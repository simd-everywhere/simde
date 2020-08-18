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

/* These next two make sure that all we need to do is flip a single
 * bit in order to flip the sign of a value without altering the
 * absolute value. i.e., we want to make sure the parts of the float
 * aren't stored as two's complement or something. */

static int
test_simde_single_bit_sign_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const simde_float32 ppif_as_f32 =  SIMDE_MATH_PIF;
  static const simde_float32 npif_as_f32 = -SIMDE_MATH_PIF;
  uint32_t ppif_as_u32, npif_as_u32, v;

  simde_memcpy(&ppif_as_u32, &ppif_as_f32, sizeof(uint32_t));
  simde_memcpy(&npif_as_u32, &npif_as_f32, sizeof(uint32_t));

  /* is_power_of_two(pi ^ -pi) */
  v = ppif_as_u32 ^ npif_as_u32;
  v = (v & (v - 1)) == 0;

  simde_assert_equal_u32(v, UINT32_C(1));

  return 0;
}

static int
test_simde_single_bit_sign_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const simde_float64 ppif_as_f64 =  SIMDE_MATH_PI;
  static const simde_float64 npif_as_f64 = -SIMDE_MATH_PI;
  uint64_t ppif_as_u64, npif_as_u64, v;

  simde_memcpy(&ppif_as_u64, &ppif_as_f64, sizeof(uint64_t));
  simde_memcpy(&npif_as_u64, &npif_as_f64, sizeof(uint64_t));

  /* is_power_of_two(pi ^ -pi) */
  v = ppif_as_u64 ^ npif_as_u64;
  v = (v & (v - 1)) == 0;

  simde_assert_equal_u64(v, UINT64_C(1));

  return 0;
}

/* We can handle little and big endian, but not PDP endian (or any
 * other endianness). */

static int
test_simde_endian (SIMDE_MUNIT_TEST_ARGS) {
  uint8_t a[] = { 1, 2, 3, 4 };
  uint32_t v;

  simde_memcpy(&v, a, sizeof(v));

  switch(v) {
    case UINT32_C(0x01020304): /* Big endian */
    case UINT32_C(0x04030201): /* Little endian */
      return 0;
    default:
      return 1;
  }
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(ieee754_storage_f32)
  SIMDE_TEST_FUNC_LIST_ENTRY(ieee754_storage_f64)
  SIMDE_TEST_FUNC_LIST_ENTRY(single_bit_sign_f32)
  SIMDE_TEST_FUNC_LIST_ENTRY(single_bit_sign_f64)
  SIMDE_TEST_FUNC_LIST_ENTRY(endian)
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
