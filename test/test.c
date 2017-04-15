#include "test.h"

void debug_array_u32(const char* prefix, size_t nmemb, uint32_t* v) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " 0x%08x", v[i]);
  }
  fprintf(stderr, "\n");
}

static MunitTest test_suite_tests[] = {
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  MunitSuite test_suites[] = {
    simde_mmx_test_suite,
    simde_sse_test_suite,
    simde_sse2_test_suite,
    { 0, },
  };

  MunitSuite test_suite = {
#if defined(TEST_NATIVE)
    (char*) "/native",
#else
    (char*) "/emul",
#endif
    test_suite_tests,
    test_suites,
    1,
    MUNIT_SUITE_OPTION_NONE
  };

  return munit_suite_main(&test_suite, NULL, argc, argv);
}
