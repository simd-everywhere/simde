#!/usr/bin/env python3
"""
SIMDe Packaging Script

Packages SIMDe headers into a zip archive (or other formats) matching the
example structure with amalgamation. This script handles:
- Finding the revision via git (or fallback).
- Copying and amalgamating headers (recursively processing #include).
- Creating the output archive with a consistent directory structure.

Examples:
    # Basic usage (defaults to zip format, simde/ source, and auto-detected git hash)
    python3 package_simde.py --output simde-v0.8.0.zip

    # Specify source directory and output format
    python3 package_simde.py --output simde-snapshot.tar.gz --source ./simde

    # Override git hash (useful for reproducible builds without .git)
    python3 package_simde.py --output simde.zip --git-hash v0.8.0
"""

import os
import shutil
import argparse
import re
import subprocess
import glob

# Pattern to find includes that should be amalgamated: #include "..."
amalgamate_include = re.compile(r"^\s*#\s*include\s+\"([^)]+)\"\s$")


def get_git_id(srcdir):
    """
    Try to retrieve the current git hash of the source directory.
    Returns 'unknown' if git is not available or the command fails.
    """
    if not shutil.which("git"):
        return "unknown"

    try:
        return (
            subprocess.check_output(
                ["git", "rev-parse", "HEAD"], cwd=srcdir, stderr=subprocess.DEVNULL
            )
            .decode()
            .strip()
        )
    except (subprocess.CalledProcessError, OSError):
        return "unknown"


def amalgamate(filename, stream, already_included, src_root, git_id):
    """
    Recursively writes the content of filename to stream.

    - Checks for #include directives and recursively amalgamates them.
    - Guards against cyclic includes using already_included list.
    - Adds markers for start/end of included files.
    """
    full_path = os.path.realpath(filename)
    srcdir = os.path.dirname(full_path)

    stream.write("/* AUTOMATICALLY GENERATED FILE, DO NOT MODIFY */\n")
    stream.write(f"/* {git_id} */\n")

    if full_path not in already_included:
        already_included.append(full_path)
        try:
            with open(filename, "r", encoding="utf-8") as input_file:
                # Use forward slashes for cross-platform consistency in comments
                rel_path_str = os.path.relpath(full_path, start=src_root).replace(
                    "\\", "/"
                )
                stream.write("/* :: Begin " + rel_path_str + " :: */\n")
                for source_line in input_file:
                    a9e_inc_m = amalgamate_include.match(source_line)
                    if a9e_inc_m:
                        inc_path = os.path.join(srcdir, a9e_inc_m.group(1))
                        if os.path.exists(inc_path):
                            amalgamate(
                                inc_path, stream, already_included, src_root, git_id
                            )
                        else:
                            stream.write(source_line)
                    else:
                        stream.write(source_line)
                stream.write("/* :: End " + rel_path_str + " :: */\n")
        except FileNotFoundError:
            print(f"Warning: Could not find file to amalgamate: {filename}")
            stream.write(f"/* ERROR: Could not find file {filename} */\n")


def main():
    parser = argparse.ArgumentParser(
        description="Package SIMDe headers with amalgamation.",
        epilog="""Examples:
  python3 package_simde.py --output simde-v0.8.0.zip
  python3 package_simde.py --output simde.tar.gz --source ../simde
""",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument(
        "--output",
        "-o",
        required=True,
        help="Output archive path (e.g., simde-v0.8.0.zip).",
    )
    parser.add_argument(
        "--source",
        "-s",
        default="simde",
        help="Source directory containing SIMDe headers.",
    )
    parser.add_argument(
        "--git-hash", help="Override the git hash embedded in the files."
    )
    parser.add_argument("--format", "-f", help="Archive format (default: auto-detect).")
    parser.add_argument(
        "--quiet", "-q", action="store_true", help="Suppress all output."
    )
    parser.add_argument(
        "--overwrite",
        action="store_true",
        help="Overwrite existing output file and temporary directory.",
    )
    args = parser.parse_args()

    is_verbose = not args.quiet

    source_dir = os.path.abspath(args.source)
    output_arg = args.output

    repo_root = os.path.dirname(os.path.abspath(__file__))

    if is_verbose:
        print(f"Source directory: {source_dir}")

    format_map = {
        "zip": ".zip",
        "gztar": ".tar.gz",
        "bztar": ".tar.bz2",
        "xztar": ".tar.xz",
        "tar": ".tar",
    }

    archive_format = args.format
    if not archive_format:
        lower_output = output_arg.lower()
        if lower_output.endswith(".zip"):
            archive_format = "zip"
        elif lower_output.endswith(".tar.gz") or lower_output.endswith(".tgz"):
            archive_format = "gztar"
        elif lower_output.endswith(".tar.bz2") or lower_output.endswith(".tbz2"):
            archive_format = "bztar"
        elif lower_output.endswith(".tar.xz") or lower_output.endswith(".txz"):
            archive_format = "xztar"
        elif lower_output.endswith(".tar"):
            archive_format = "tar"
        else:
            if is_verbose:
                print(
                    f"Warning: Could not detect format from '{output_arg}', defaulting to zip."
                )
            archive_format = "zip"

    if is_verbose:
        print(f"Archive format: {archive_format}")

    # Determine final output filename and base name
    extension = format_map.get(archive_format, "")

    if output_arg.lower().endswith(extension):
        final_output_filename = output_arg
        base_name_str = output_arg[: -len(extension)]
    else:
        final_output_filename = output_arg + extension
        base_name_str = output_arg

    final_output_path = os.path.abspath(final_output_filename)
    if is_verbose:
        print(f"Final output path: {final_output_path}")

    if os.path.exists(final_output_path):
        if args.overwrite:
            if is_verbose:
                print(f"Removing existing output file: {final_output_path}")
            os.remove(final_output_path)
        else:
            print(
                f"Error: Output file '{final_output_path}' already exists. Use --overwrite."
            )
            exit(1)

    # Determine base directory name
    stem = os.path.basename(base_name_str)
    
    # Temp dir is now based on the output path (minus extension)
    temp_build_dir = os.path.abspath(base_name_str)

    if is_verbose:
        print(f"Temporary build directory: {temp_build_dir}")

    # Safety checks
    if os.path.abspath(temp_build_dir) == os.path.abspath(source_dir):
        print(
            f"Error: Temporary directory '{temp_build_dir}' is the same as the source directory."
        )
        print("Please provide a different output name.")
        exit(1)

    if os.path.abspath(temp_build_dir) == os.path.abspath(repo_root):
        print(
            f"Error: Temporary directory '{temp_build_dir}' is the same as the repository root."
        )
        print("Please provide a different output name.")
        exit(1)

    if os.path.exists(temp_build_dir):
        if args.overwrite:
            if is_verbose:
                print(f"Removing existing temporary directory: {temp_build_dir}")
            shutil.rmtree(temp_build_dir)
        else:
            print(
                f"Error: Temporary directory '{temp_build_dir}' already exists. Use --overwrite."
            )
            exit(1)

    output_simde_dir = os.path.join(temp_build_dir, "simde")

    if is_verbose:
        print(f"Creating directory structure: {output_simde_dir}")
    os.makedirs(output_simde_dir)

    git_id = args.git_hash if args.git_hash else get_git_id(source_dir)
    if is_verbose:
        print(f"Git Hash: {git_id}")

    search_pattern = os.path.join(source_dir, "*", "*.h")
    found_files = glob.glob(search_pattern)
    found_files.sort()

    if is_verbose:
        print(f"Amalgamating {len(found_files)} headers from '{source_dir}'...")

    for source_path in found_files:
        rel_path = os.path.relpath(source_path, start=source_dir)
        if is_verbose:
            print(f"Processing: {rel_path}")

        dest_path = os.path.join(output_simde_dir, rel_path)
        dest_dir = os.path.dirname(dest_path)

        if not os.path.exists(dest_dir):
            os.makedirs(dest_dir)

        with open(dest_path, "w", encoding="utf-8", newline="\n") as outfile:
            amalgamate(source_path, outfile, [], repo_root, git_id)

    if os.path.exists(os.path.join(repo_root, "COPYING")):
        if is_verbose:
            print("Copying COPYING file")
        shutil.copy(os.path.join(repo_root, "COPYING"), os.path.join(temp_build_dir, "COPYING"))

    if os.path.exists(os.path.join(repo_root, "CMakeLists.txt")):
        if is_verbose:
            print("Copying CMakeLists.txt file")
        shutil.copy(os.path.join(repo_root, "CMakeLists.txt"), os.path.join(temp_build_dir, "CMakeLists.txt"))

    if is_verbose:
        print(f"Creating archive {final_output_path}...")

    # We archive the temp directory content directly (flattening structure)
    # We need absolute path for base_name passed to make_archive
    final_base_name = os.path.join(os.path.dirname(final_output_path), stem)

    final_archive_actual_path = shutil.make_archive(
        base_name=final_base_name,
        format=archive_format,
        root_dir=temp_build_dir,
        base_dir=".",
    )

    print(f"Successfully created {final_archive_actual_path}")

if __name__ == "__main__":
    main()
