#include "test.h"

#include "../sse.h"
#include <fenv.h>

#include <math.h>

void debug_array_u32(const char* prefix, size_t nmemb, uint32_t v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " 0x%08x", v[i]);
  }
  fprintf(stderr, "\n");
}

void debug_array_f32(const char* prefix, size_t nmemb, float v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  fprintf(stderr, "%s:", prefix);
  for(size_t i = 0 ; i < nmemb ; i++) {
    fprintf(stderr, " %2.6f", v[i]);
  }
  fprintf(stderr, "\n");
}

void random_floatv(size_t nmemb, float v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  for (size_t i = 0 ; i < nmemb ; i++) {
    do {
      munit_rand_memory(sizeof(v[i]), (uint8_t*) &(v[i]));
    } while (!isnormal(v[i]));
  }
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

  /* Set the SSE rounding mode to match the CPU rounding mode. */
#if defined(SIMDE__SSE_NATIVE)
  switch (fegetround()) {
#if defined(FE_TONEAREST)
    case FE_TONEAREST:
      simde_MM_SET_ROUNDING_MODE(_MM_ROUND_NEAREST);
      break;
#endif
#if defined(FE_DOWNWARD)
    case FE_DOWNWARD:
      simde_MM_SET_ROUNDING_MODE(_MM_ROUND_DOWN);
      break;
#endif
#if defined(FE_UPWARD)
    case FE_UPWARD:
      simde_MM_SET_ROUNDING_MODE(_MM_ROUND_UP);
      break;
#endif
#if defined(FE_TOWARDZERO)
    case FE_TOWARDZERO:
      simde_MM_SET_ROUNDING_MODE(_MM_ROUND_TOWARD_ZERO);
      break;
#endif
  }
#endif

  return munit_suite_main(&test_suite, NULL, argc, argv);
}
