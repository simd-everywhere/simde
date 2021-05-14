#if defined(SIMDE_TESTS_ARM_RUN_TESTS_H)
  #error File already included.
#endif
#define SIMDE_TESTS_ARM_RUN_TESTS_H

#include "../test.h"
#include "neon/run-tests.h"
#include "sve/run-tests.h"

MunitSuite* simde_tests_arm_get_suite(void);
