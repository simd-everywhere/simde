#if defined(SIMDE_TESTS_ARM_NEON_RUN_TESTS_H)
  #error File already included.
#endif
#define SIMDE_TESTS_ARM_NEON_RUN_TESTS_H

#include "../../munit/munit.h"

MunitSuite* simde_tests_arm_neon_get_suite(void);
