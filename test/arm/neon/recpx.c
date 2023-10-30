#define SIMDE_TEST_ARM_NEON_INSN recpx

#include "test-neon.h"
#include "../../../simde/arm/neon/recpx.h"

static int
test_simde_vrecpxh_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a;
    simde_float16 r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {            SIMDE_NANHF,
                 SIMDE_NANHF },
    #endif
    {    SIMDE_FLOAT16_VALUE(  -0.0003834),
         SIMDE_FLOAT16_VALUE(   -8192.000) },
    {    SIMDE_FLOAT16_VALUE(      -178.5),
         SIMDE_FLOAT16_VALUE(     -0.0156) },
    {    SIMDE_FLOAT16_VALUE(   0.0003405),
         SIMDE_FLOAT16_VALUE(    8192.000) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    simde_float16_t r = simde_vrecpxh_f16(a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t r = simde_vrecpxh_f16(a);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecpxs_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {            SIMDE_MATH_NANF,
                 SIMDE_MATH_NANF },
    #endif
    {    SIMDE_FLOAT32_C(   360.397),
         SIMDE_FLOAT32_C(     0.008) },
    {   -SIMDE_FLOAT32_C(   358.546),
        -SIMDE_FLOAT32_C(     0.008) },
    {    SIMDE_FLOAT32_C(    11.519),
         SIMDE_FLOAT32_C(     0.250) },
    {   -SIMDE_FLOAT32_C(   930.861),
        -SIMDE_FLOAT32_C(     0.004) },
    {    SIMDE_FLOAT32_C(   908.780),
         SIMDE_FLOAT32_C(     0.004) },
    {    SIMDE_FLOAT32_C(   643.252),
         SIMDE_FLOAT32_C(     0.004) },
    {   -SIMDE_FLOAT32_C(   604.199),
        -SIMDE_FLOAT32_C(     0.004) },
    {    SIMDE_FLOAT32_C(   199.733),
         SIMDE_FLOAT32_C(     0.016) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32_t a = test_vec[i].a;
    simde_float32_t r = simde_vrecpxs_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vrecpxs_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrecpxd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {            SIMDE_MATH_NAN,
                 SIMDE_MATH_NAN },
    #endif
    {    SIMDE_FLOAT64_C(0.6406250298023224),
         SIMDE_FLOAT64_C(4.00000) },
    {    SIMDE_FLOAT64_C(82091.0000000000),
         SIMDE_FLOAT64_C(0.0000305176) },
    {    SIMDE_FLOAT64_C(33113.0781250000),
         SIMDE_FLOAT64_C(0.0000610352) },
    {    SIMDE_FLOAT64_C(3877.2734375000),
         SIMDE_FLOAT64_C(0.0009765625) },
    {   -SIMDE_FLOAT64_C(58554.0039062500),
        -SIMDE_FLOAT64_C(0.0000610352) },
    {   -SIMDE_FLOAT64_C(79657.2890625000),
        -SIMDE_FLOAT64_C(0.0000305176) },
    {    SIMDE_FLOAT64_C(79821.5625000000),
         SIMDE_FLOAT64_C(0.0000305176) },
    {   -SIMDE_FLOAT64_C(52040.1406250000),
        -SIMDE_FLOAT64_C(0.0000610352) },
    {    SIMDE_FLOAT64_C(30870.6484375000),
         SIMDE_FLOAT64_C(0.0001220703) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t a = test_vec[i].a;
    simde_float64_t r = simde_vrecpxd_f64(a);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64_t r = simde_vrecpxd_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpxh_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpxs_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrecpxd_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
