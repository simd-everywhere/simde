#!/usr/bin/env python3
"""
Check that LoongArch SIMD intrinsic usage matches the preprocessor guard.
  - If a guarded block contains ONLY __lsx_* intrinsics, it MUST be guarded
    by SIMDE_LOONGARCH_LSX_NATIVE.
  - If a guarded block contains __lasx_* intrinsics, with or without __lsx_*,
    it MUST be guarded by SIMDE_LOONGARCH_LASX_NATIVE.
"""

import re
import sys
from pathlib import Path

TARGET_MACRO = r'SIMDE_LOONGARCH_(?:LSX|LASX)_NATIVE'

# All conditional inclusion directives, including C++23 #elifdef / #elifndef.
DIRECTIVE_RE = re.compile(
    r'^\s*#\s*(if|ifdef|ifndef|elifdef|elifndef|elif|else|endif)\b'
)

# Positive guards from #if / #elif:
#   #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
#   #elif defined(SIMDE_LOONGARCH_LASX_NATIVE)
# Also tolerates:
#   #if defined SIMDE_LOONGARCH_LSX_NATIVE
IF_GUARD_RE = re.compile(
    r'^\s*#\s*(?:if|elif)\s+defined\s*(?:\(\s*)?(' + TARGET_MACRO + r')\b\s*\)?'
)

# Positive guards from #ifdef / #elifdef:
#   #ifdef SIMDE_LOONGARCH_LSX_NATIVE
#   #elifdef SIMDE_LOONGARCH_LASX_NATIVE
DEF_GUARD_RE = re.compile(
    r'^\s*#\s*(?:ifdef|elifdef)\s+(' + TARGET_MACRO + r')\b'
)

LSX_RE = re.compile(r'\b__lsx_\w+')
LASX_RE = re.compile(r'\b__lasx_\w+')


def positive_guard(line):
    """
    Return the target macro name if this line starts a positive target guard.

    Positive guards are:
      #if defined(SIMDE_LOONGARCH_LSX_NATIVE)
      #elif defined(SIMDE_LOONGARCH_LASX_NATIVE)
      #ifdef SIMDE_LOONGARCH_LSX_NATIVE
      #elifdef SIMDE_LOONGARCH_LASX_NATIVE

    Negative guards such as #ifndef / #elifndef return None.
    """
    m = IF_GUARD_RE.match(line)
    if m:
        return m.group(1)

    m = DEF_GUARD_RE.match(line)
    if m:
        return m.group(1)

    return None


def guarded_blocks(lines):
    """
    Yield (guard_macro, guard_line, block_start, block_end) tuples.

    block_end is exclusive, matching Python slice semantics.
    """
    i = 0
    while i < len(lines):
        guard = positive_guard(lines[i])
        if not guard:
            i += 1
            continue

        guard_line = i
        start = i + 1
        depth = 1
        j = start

        while j < len(lines) and depth:
            dm = DIRECTIVE_RE.match(lines[j])
            if dm:
                kind = dm.group(1)

                if kind in {'if', 'ifdef', 'ifndef'}:
                    depth += 1
                elif kind == 'endif':
                    depth -= 1
                elif depth == 1:
                    # Same-level branch boundary:
                    #   #elif
                    #   #elifdef
                    #   #elifndef
                    #   #else
                    if guard and start < j:
                        yield guard, guard_line, start, j

                    guard = positive_guard(lines[j])
                    guard_line = j
                    start = j + 1

            j += 1

        # If depth == 0, j points just after the matching #endif.
        # The #endif line itself should not be part of the block.
        #
        # If depth != 0, the file ended before #endif; treat EOF as the end.
        end = j - 1 if depth == 0 else j

        if guard and start < end:
            yield guard, guard_line, start, end

        i = j


def snippet(lines, start, end, context=2):
    """Return a small line-numbered snippet around [start, end)."""
    first = max(0, start - context)
    last = min(len(lines), end + context)

    return '\n'.join(
        f"{'>>>' if start <= i < end else '   '} {i + 1:5d} | {lines[i]}"
        for i in range(first, last)
    )


def check_file(path):
    """Yield errors found in one file."""
    try:
        lines = path.read_text(encoding='utf-8', errors='replace').splitlines()
    except OSError:
        return

    for guard, guard_line, start, end in guarded_blocks(lines):
        if any(LASX_RE.search(lines[i]) for i in range(start, end)):
            expected = 'SIMDE_LOONGARCH_LASX_NATIVE'
        elif any(LSX_RE.search(lines[i]) for i in range(start, end)):
            expected = 'SIMDE_LOONGARCH_LSX_NATIVE'
        else:
            continue

        if guard != expected:
            yield (
                path,
                guard_line + 1,
                guard,
                expected,
                snippet(lines, guard_line, end),
            )


def main():
    root = Path(sys.argv[1]) if len(sys.argv) > 1 else Path('simde')

    if not root.is_dir():
        print(f"ERROR: directory '{root}' not found", file=sys.stderr)
        return 1

    files = sorted(root.rglob('*.h'))
    print(f"Checking {len(files)} header files in '{root}/' ...")

    error_count = 0

    for path in files:
        for file_path, line, guard, expected, snip in check_file(path):
            error_count += 1

            reason = (
                'LASX (or mixed LSX+LASX)'
                if expected == 'SIMDE_LOONGARCH_LASX_NATIVE'
                else 'LSX-only'
            )

            print(f"\n{'=' * 72}")
            print(f'[{error_count}] {file_path}:{line}')
            print(f'    Guard:    {guard}')
            print(f'    Expected: {expected}')
            print(f'    Reason:   Block contains {reason} intrinsics')
            print(f"    Code:\n{'-' * 72}")
            print(snip)
            print('=' * 72)

    if error_count == 0:
        print('PASSED: All LoongArch intrinsic guards are consistent.')
        return 0

    print(f'\nFAILED: {error_count} error(s) found')
    return 1


if __name__ == '__main__':
    sys.exit(main())
