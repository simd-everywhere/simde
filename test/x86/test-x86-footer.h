#if defined(SIMDE_TEST_BARE)
  int main(void) {
    for (size_t i = 0 ; i < (sizeof(test_suite_tests) / sizeof(test_suite_tests[0])) ; i++) {
      int res = test_suite_tests[i]();
      if (res != 0) {
        return res;
      }
    }

    return 0;
  }
#else
  #if defined(__cplusplus)
    static MunitSuite suite = { const_cast<char*>("/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_ISAX)), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };
  #else
    static MunitSuite suite = { (char*) "/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_ISAX), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };
  #endif

  HEDLEY_C_DECL MunitSuite*
  SIMDE_TEST_GENERATE_VARIANT_SYMBOL_CURRENT(HEDLEY_CONCAT(simde_test_x86_get_suite_,SIMDE_TESTS_CURRENT_ISAX)) (void) {
    return &suite;
  }
#endif
