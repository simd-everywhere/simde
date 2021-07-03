#include "run-tests.h"

#include "../../simde/hedley.h"

static MunitSuite suites[] = {
  #define SIMDE_TEST_DECLARE_SUITE(name) { (char*) "/", NULL, NULL, 1, MUNIT_SUITE_OPTION_NONE },
  #include "declare-suites.h"
  #undef SIMDE_TEST_DECLARE_SUITE
  { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE }
};

static MunitSuite suite = { "/wasm", NULL, suites, 1, MUNIT_SUITE_OPTION_NONE };

MunitSuite*
simde_tests_wasm_get_suite(void) {
  size_t i = 0;
  #define SIMDE_TEST_DECLARE_SUITE(name) suites[i++] = *HEDLEY_CONCAT3(simde_tests_wasm_, name, _get_suite)();
  #include "declare-suites.h"
  #undef SIMDE_TEST_DECLARE_SUITE

  return &suite;
}
