#!/bin/bash

set -euxo pipefail

# Define variables
HOST_CPU="$(uname -m)"
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

function _run_test_and_get_result {
  local exit_status=0
  local result="skipped"

  if [ "${#}" -lt 1 ]; then
    echo "Argument error" 2>&1
    exit 1
  fi
  local cond="${1}"

  if [ "${cond}" = "include" ] || [ "${cond}" = "pend" ]; then
    if _run_test; then
      if [ "${cond}" = "include" ]; then
        result="ok"
      else
        exit_status=1
        result="pending - passed unexpectedly"
      fi
    else
      if [ "${cond}" = "include" ]; then
        exit_status=1
        result="not ok"
      else
        result="pending - failed expectedly"
      fi
    fi
  fi

  # Use global variables to pass the return values as a limitation of Bash.
  result_buf="${result}"
  return "${exit_status}"
}

# Print system info.
cat /proc/cpuinfo
cat /proc/meminfo

# Set PATH for commands installed by `pip install`.
PATH="${PATH}:${HOME}/.local/bin"

# Install additional packages.
pip3 install meson==0.55.0

# Run test.

# Configuration
#
# If the value is true, the CI returns the exit status zero even if the tests
# fail as a compromised way.
IGNORE_EXIT_STATUS=

# Define the testing matrix.
# "include": Include the test in the matrix. Run the test.
# "exclude": Exclude the test. The test is not executed.
#            It can be used to save the total running time in CI.
# "pend"   : Run the test, but if the test fails, it passes as exit status zero.
#            If the test passes unexpectedly, it fails as exit status non-zero.
#
# Set the default behavior for each test.
MATRIX_DEFAULT_GCC_DEFAULT="include"
MATRIX_DEFAULT_GCC_O2="include"
MATRIX_DEFAULT_GCC_RPM="exclude"
MATRIX_DEFAULT_CLANG_DEFAULT="exclude"
MATRIX_DEFAULT_CLANG_O2="exclude"
MATRIX_DEFAULT_CLANG_RPM="exclude"
# Set the CPU specific behavior for each test optionally.
# This configuration is prioritized than the default behavior.

# End of configuration

# Generate the current CPU specific test conditions.
# If there is no CPU specific variable, set the default value.
TEST_COND_GCC_DEFAULT=$(eval echo \
  "\${MATRIX_${HOST_CPU}_GCC_DEFAULT:-${MATRIX_DEFAULT_GCC_DEFAULT}}")
TEST_COND_GCC_O2=$(eval echo \
  "\${MATRIX_${HOST_CPU}_GCC_O2:-${MATRIX_DEFAULT_GCC_O2}}")
TEST_COND_GCC_RPM=$(eval echo \
  "\${MATRIX_${HOST_CPU}_GCC_RPM:-${MATRIX_DEFAULT_GCC_RPM}}")
TEST_COND_CLANG_DEFAULT=$(eval echo \
  "\${MATRIX_${HOST_CPU}_CLANG_DEFAULT:-${MATRIX_DEFAULT_CLANG_DEFAULT}}")
TEST_COND_CLANG_O2=$(eval echo \
  "\${MATRIX_${HOST_CPU}_CLANG_O2:-${MATRIX_DEFAULT_CLANG_O2}}")
TEST_COND_CLANG_RPM=$(eval echo \
  "\${MATRIX_${HOST_CPU}_CLANG_RPM:-${MATRIX_DEFAULT_CLANG_RPM}}")

exit_status=0
# A temporary buffer to store the return value from a function.
result_buf=

# Print compiler versions.
gcc --version
g++ --version
clang --version
clang++ --version

echo "== Tests on gcc in a default status =="
if ! BUILD_DIR="build/gcc" CC="gcc" CXX="g++" \
  _run_test_and_get_result "${TEST_COND_GCC_DEFAULT}"; then
  exit_status=1
fi
result_gcc="${result_buf}"

echo "== Tests on clang in a default status =="
if ! BUILD_DIR="build/clang" CC="clang" CXX="clang++" \
  _run_test_and_get_result "${TEST_COND_CLANG_DEFAULT}"; then
  exit_status=1
fi
result_clang="${result_buf}"

echo "== Tests on gcc with O2 flag =="
if ! BUILD_DIR="build/gcc-O2" CC="gcc" CXX="g++" \
  CFLAGS="-O2" CXXFLAGS="-O2" \
  _run_test_and_get_result "${TEST_COND_GCC_O2}"; then
  exit_status=1
fi
result_gcc_O2="${result_buf}"

echo "== Tests on clang with O2 flag =="
if ! BUILD_DIR="build/clang-O2" CC="clang" CXX="clang++" \
  CFLAGS="-O2" CXXFLAGS="-O2" \
  _run_test_and_get_result "${TEST_COND_CLANG_O2}"; then
  exit_status=1
fi
result_clang_O2="${result_buf}"

# This is an advanced test.
echo "== Tests on gcc with flags used in RPM package build =="
if ! BUILD_DIR="build/gcc-rpm" CC="gcc" CXX="g++" \
  CFLAGS="${CI_GCC_RPM_CFLAGS-}" CXXFLAGS="${CI_GCC_RPM_CXXFLAGS-}" \
  LDFLAGS="${CI_GCC_RPM_LDFLAGS-}" \
  _run_test_and_get_result "${TEST_COND_GCC_RPM}"; then
  exit_status=1
fi
result_gcc_rpm="${result_buf}"

# This is an advanced test.
echo "== Tests on clang with flags used in RPM package build =="
if ! BUILD_DIR="build/clang-rpm" CC="clang" CXX="clang++" \
  CFLAGS="${CI_CLANG_RPM_CFLAGS-}" CXXFLAGS="${CI_CLANG_RPM_CXXFLAGS-}" \
  LDFLAGS="${CI_CLANG_RPM_LDFLAGS-}" \
  _run_test_and_get_result "${TEST_COND_CLANG_RPM}"; then
  exit_status=1
fi
result_clang_rpm="${result_buf}"

# Print results.
cat <<EOF
== Results ==
Exit status: ${exit_status}
${result_gcc}: gcc without flags
${result_gcc_O2}: gcc with -O2 flag
${result_gcc_rpm}: gcc with RPM build flags
${result_clang}: clang without flags
${result_clang_O2}: clang with -O2 flag
${result_clang_rpm}: clang with RPM build flags
EOF

if [ "${IGNORE_EXIT_STATUS}" = true ]; then
  echo "warning: Exiting always with exit status zero is not ideal."
  exit 0
else
  exit ${exit_status}
fi
