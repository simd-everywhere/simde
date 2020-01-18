#include "munit/munit.h"
#include "x86/test-x86.h"
#include "arm/test-arm.h"
#include "../simde/simde-common.h"

#include <math.h>

void random_f32v(size_t nmemb, simde_float32 v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  for (size_t i = 0 ; i < nmemb ; i++) {
    do {
      munit_rand_memory(sizeof(v[i]), (uint8_t*) &(v[i]));
    } while (!isnormal(v[i]));
  }
}

simde_float64 random_f64_range(simde_float64 min, simde_float64 max) {
  const simde_float64 range = max - min;
  simde_float64 x = (simde_float64) munit_rand_uint32();
  x /= ((simde_float32) UINT32_MAX) / range;
  x += min;
  return x;
}

simde_float32 random_f32_range(simde_float32 min, simde_float32 max) {
  return (simde_float32) random_f64_range(min, max);
}

void random_f64v(size_t nmemb, simde_float64 v[HEDLEY_ARRAY_PARAM(nmemb)]) {
  for (size_t i = 0 ; i < nmemb ; i++) {
    do {
      munit_rand_memory(sizeof(v[i]), (uint8_t*) &(v[i]));
    } while (!isnormal(v[i]));
  }
}

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
