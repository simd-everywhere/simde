#if defined(SIMDE_TESTS_X86_RUN_TESTS_H)
  #error File already included.
#endif
#define SIMDE_TESTS_X86_RUN_TESTS_H

#include "../munit/munit.h"
#include "avx512/run-tests.h"

MunitSuite* simde_tests_x86_get_suite(void);
