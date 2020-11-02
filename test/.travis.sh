#!/bin/sh

# Helper script for running tests on Travis CI.

if [ "${RUN_TESTS}" = "true" ]; then
  if [ "windows" != "${TRAVIS_OS_NAME}" ]; then
    if command -v parallel; then
      ${TEST_WRAPPER} ./run-tests${EXECUTABLE_EXTENSION} --list | grep -oP '^/(x86|arm/neon)/([^\/]+)' | sort -u | xargs parallel ${TEST_WRAPPER} ./run-tests${EXECUTABLE_EXTENSION} ${TEST_ARG_SEPARATOR} {} ::: || exit 1
    else
      ${TEST_WRAPPER} ./run-tests${EXECUTABLE_EXTENSION} || exit 1
    fi
  else
    ctest --output-on-failure --interactive-debug-mode 0 -C Debug -V || exit 1
  fi
fi

echo "Tests completed successfully."
