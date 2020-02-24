#include "munit/munit.h"
#include "x86/test-x86.h"
#include "arm/test-arm.h"
#include "../simde/simde-common.h"
#include "run-tests.h"

#include <math.h>

int main(int argc, char* argv[HEDLEY_ARRAY_PARAM(argc + 1)]) {
  static MunitSuite suite = { "", NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE };
  MunitSuite suites[] = {
    *simde_tests_x86_get_suite(),
    *simde_tests_arm_get_suite(),
    { NULL, NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE }
  };

  suite.suites = suites;

  return munit_suite_main(&suite, NULL, argc, argv);
}
