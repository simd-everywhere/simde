#!/bin/bash

set -euxo pipefail

# Define variables
JOBS="$(nproc)"

# Functions
function _time {
  /bin/time -f '=> [%E]' ${@}
}

function _setup {
  if ! meson setup "${BUILD_DIR}"; then
    cat "${BUILD_DIR}/meson-logs/meson-log.txt"
    return 1
  fi
}

function _build {
  rm -f build.log
  if ! _time ninja -C "${BUILD_DIR}" -v -j "${JOBS}" >& build.log; then
    cat build.log
    return 1
  fi
  head -4 build.log
  tail -3 build.log
}

function _test {
  if ! _time meson test -C "${BUILD_DIR}" \
    -q --no-rebuild --print-errorlogs; then
    return 1
  fi
}

function _run_test {
  if ! _setup; then
    return 1
  fi

  if ! _build; then
    return 2
  fi

  if ! _test; then
    return 3
  fi
}

# Print system info.
cat /proc/cpuinfo
cat /proc/meminfo

# Install additional packages.
pip3 install meson==0.55.0

# Run test.

# Customized constants.
#
# If the value is true, the CI returns the exit status zero even if the tests
# fail as a compromised way.
IGNORE_EXIT_STATUS=
# Set true if you want to skip specific tests to save total running time.
SKIP_GCC=
SKIP_GCC_O2=
SKIP_GCC_RPM=true
SKIP_CLANG=true
SKIP_CLANG_O2=true
SKIP_CLANG_RPM=true

exit_status=0
result_gcc="skipped"
result_gcc_O2="skipped"
result_gcc_rpm="skipped"
result_clang="skipped"
result_clang_O2="skipped"
result_clang_rpm="skipped"

# Print compiler versions.
gcc --version
g++ --version
clang --version
clang++ --version

echo "== Tests on gcc without flags =="
if [ ! "${SKIP_GCC}" = true ]; then
  result_gcc="ok"
  if ! BUILD_DIR="build/gcc" CC="gcc" CXX="g++" \
    _run_test; then
    exit_status=1
    result_gcc="not ok"
  fi
fi

echo "== Tests on clang without flags =="
if [ ! "${SKIP_CLANG}" = true ]; then
  result_clang="ok"
  if ! BUILD_DIR="build/clang" CC="clang" CXX="clang++" \
    _run_test; then
    exit_status=1
    result_clang="not ok"
  fi
fi

echo "== Tests on gcc with O2 flag =="
if [ ! "${SKIP_GCC_O2}" = true ]; then
  result_gcc_O2="ok"
  if ! BUILD_DIR="build/gcc-O2" CC="gcc" CXX="g++" \
    CFLAGS="-O2" CXXFLAGS="-O2" \
    _run_test; then
    exit_status=1
    result_gcc_O2="not ok"
  fi
fi

echo "== Tests on clang with O2 flag =="
if [ ! "${SKIP_CLANG_O2}" = true ]; then
  result_clang_O2="ok"
  if ! BUILD_DIR="build/clang-O2" CC="clang" CXX="clang++" \
    CFLAGS="-O2" CXXFLAGS="-O2" \
    _run_test; then
    exit_status=1
    result_clang_O2="not ok"
  fi
fi

# This is an advanced test.
echo "== Tests on gcc with flags used in RPM package build =="
if [ ! "${SKIP_GCC_RPM}" = true ]; then
  result_gcc_rpm="ok"
  if ! BUILD_DIR="build/gcc-rpm" CC="gcc" CXX="g++" \
    CFLAGS="${CI_GCC_RPM_CFLAGS}" CXXFLAGS="${CI_GCC_RPM_CXXFLAGS}" \
    LDFLAGS="${CI_GCC_RPM_LDFLAGS}" \
    _run_test; then
    exit_status=1
    result_gcc_rpm="not ok"
  fi
fi

# This is an advanced test.
echo "== Tests on clang with flags used in RPM package build =="
if [ ! "${SKIP_CLANG_RPM}" = true ]; then
  result_clang_rpm="ok"
  if ! BUILD_DIR="build/clang-rpm" CC="clang" CXX="clang++" \
    CFLAGS="${CI_CLANG_RPM_CFLAGS}" CXXFLAGS="${CI_CLANG_RPM_CXXFLAGS}" \
    LDFLAGS="${CI_CLANG_RPM_LDFLAGS}" \
    _run_test; then
    exit_status=1
    result_clang_rpm="not ok"
  fi
fi

# Print results.
cat <<EOF
== Results ==
Exit status: ${exit_status}
${result_gcc} gcc without flags
${result_gcc_O2} gcc with -O2 flag
${result_gcc_rpm} gcc with RPM build flags
${result_clang} clang without flags
${result_clang_O2} clang with -O2 flag
${result_clang_rpm} clang with RPM build flags
EOF

if [ "${IGNORE_EXIT_STATUS}" = true ]; then
  echo "warning: Exiting always with exit status zero is not ideal."
  exit 0
else
  exit ${exit_status}
fi
