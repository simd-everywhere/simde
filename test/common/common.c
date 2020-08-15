#include "../test.h"

/* These tests are basically to verify assumptions we make about the
 * target platform. */

#if defined(SIMDE_IEEE754_STORAGE)

static int
test_simde_ieee754_storage_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const simde_float32 pif_as_f32 = SIMDE_MATH_PIF;

  uint32_t pif_as_u32;

  simde_memcpy(&pif_as_u32, &pif_as_f32, sizeof(simde_float32));

  simde_assert_equal_u32(pif_as_u32, UINT32_C(0x40490fdb));

  return 0;
}

static int
test_simde_ieee754_storage_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const simde_float64 pid_as_f64 = SIMDE_MATH_PI;

  uint64_t pid_as_u64;

  simde_memcpy(&pid_as_u64, &pid_as_f64, sizeof(simde_float64));

  simde_assert_equal_u64(pid_as_u64, UINT64_C(0x400921fb54442d18));

  return 0;
}

#endif

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(ieee754_storage_f32)
  SIMDE_TEST_FUNC_LIST_ENTRY(ieee754_storage_f64)
SIMDE_TEST_FUNC_LIST_END

int main(void) {
  int retval = EXIT_SUCCESS;

  fprintf(stdout, "1..%zu\n", (sizeof(test_suite_tests) / sizeof(test_suite_tests[0])));
  for (size_t i = 0 ; i < (sizeof(test_suite_tests) / sizeof(test_suite_tests[0])) ; i++) {
    int res = test_suite_tests[i].func();
    if (res != 0) {
      retval = EXIT_FAILURE;
      fprintf(stdout, "not ok %zu %s\n", i + 1, test_suite_tests[i].name);
    } else {
      fprintf(stdout, "ok %zu %s\n", i + 1, test_suite_tests[i].name);
    }
  }

  return retval;
}
