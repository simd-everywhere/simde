#include "test-arm.h"
#include "test-arm-internal.h"
#include "neon/test-neon.h"

#include <stdio.h>

MunitSuite*
simde_tests_arm_get_suite(void) {
  static MunitSuite children[] = {
    { NULL, NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE },
    { NULL, NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE }
  };
  static MunitSuite suite = { HEDLEY_STATIC_CAST(char*, "/arm"), NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  children[0] = *simde_tests_arm_neon_get_suite();

  suite.suites = children;

  return &suite;
}
