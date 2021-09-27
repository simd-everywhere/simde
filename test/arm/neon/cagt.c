#define SIMDE_TEST_ARM_NEON_INSN cagt

#include "test-neon.h"
#include "../../../simde/arm/neon/cagt.h"

static int
test_simde_vcagth_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a;
    simde_float16 b;
    uint16_t r;
  } test_vec[] = {
    { SIMDE_FLOAT16_VALUE(  -774.00),
      SIMDE_FLOAT16_VALUE(   279.00),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(  -933.00),
      SIMDE_FLOAT16_VALUE(   505.00),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(   510.00),
      SIMDE_FLOAT16_VALUE(    91.44),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(  -980.50),
      SIMDE_FLOAT16_VALUE(   217.50),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(   716.50),
      SIMDE_FLOAT16_VALUE(   903.00),
      UINT16_C(    0) },
    { SIMDE_FLOAT16_VALUE(   875.00),
      SIMDE_FLOAT16_VALUE(  -717.50),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(    -9.65),
      SIMDE_FLOAT16_VALUE(    45.19),
      UINT16_C(    0) },
    { SIMDE_FLOAT16_VALUE(  -580.00),
      SIMDE_FLOAT16_VALUE(   148.88),
           UINT16_MAX }   
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_vcagth_f16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
    simde_float16_t b = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
    uint16_t r = simde_vcagth_f16(a, b);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcagts_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 b;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {            SIMDE_MATH_NANF,
      SIMDE_FLOAT32_C(     0.52),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   705.02),
                 SIMDE_MATH_NANF,
      UINT32_C(         0) },
    {            SIMDE_MATH_NANF,
                 SIMDE_MATH_NANF,
      UINT32_C(         0) },
    #endif

    { SIMDE_FLOAT32_C(     8.79),
      SIMDE_FLOAT32_C(   792.83),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -399.97),
      SIMDE_FLOAT32_C(  -256.84),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   231.75),
      SIMDE_FLOAT32_C(  -411.54),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   864.59),
      SIMDE_FLOAT32_C(  -881.95),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -814.20),
      SIMDE_FLOAT32_C(   479.81),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   263.32),
      SIMDE_FLOAT32_C(  -797.51),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   321.47),
      SIMDE_FLOAT32_C(   -74.97),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   -57.92),
      SIMDE_FLOAT32_C(   535.57),
      UINT32_C(         0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vcagts_f32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t b = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    uint32_t r = simde_vcagts_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcagtd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float64 b;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    {              SIMDE_MATH_NAN,
      SIMDE_FLOAT64_C(     0.52),
      UINT64_C(         0) },
    { SIMDE_FLOAT64_C(   705.02),
                  SIMDE_MATH_NAN,
      UINT64_C(         0) },
    {             SIMDE_MATH_NAN,
                  SIMDE_MATH_NAN,
      UINT64_C(         0) },
    #endif

    { SIMDE_FLOAT64_C(  -111.66),
      SIMDE_FLOAT64_C(  -149.68),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -365.17),
      SIMDE_FLOAT64_C(  -219.70),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(   -45.32),
      SIMDE_FLOAT64_C(   606.55),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -324.50),
      SIMDE_FLOAT64_C(  -332.43),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   611.77),
      SIMDE_FLOAT64_C(   425.54),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(   910.11),
      SIMDE_FLOAT64_C(   648.44),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(   572.56),
      SIMDE_FLOAT64_C(  -409.05),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(   265.81),
      SIMDE_FLOAT64_C(  -418.65),
      UINT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcagtd_f64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64_t b = simde_test_codegen_random_f64(-1000.0, 1000.0);
    uint64_t r = simde_vcagtd_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcagt_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   930.50), SIMDE_FLOAT16_VALUE(  -703.50), SIMDE_FLOAT16_VALUE(  -125.12), SIMDE_FLOAT16_VALUE(   783.00) },
      { SIMDE_FLOAT16_VALUE(   402.50), SIMDE_FLOAT16_VALUE(  -327.25), SIMDE_FLOAT16_VALUE(   405.25), SIMDE_FLOAT16_VALUE(  -207.75) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(   -29.70), SIMDE_FLOAT16_VALUE(   210.88), SIMDE_FLOAT16_VALUE(  -861.00), SIMDE_FLOAT16_VALUE(  -614.50) },
      { SIMDE_FLOAT16_VALUE(  -248.62), SIMDE_FLOAT16_VALUE(   342.00), SIMDE_FLOAT16_VALUE(  -816.50), SIMDE_FLOAT16_VALUE(   -39.50) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(   419.75), SIMDE_FLOAT16_VALUE(  -664.50), SIMDE_FLOAT16_VALUE(  -289.75), SIMDE_FLOAT16_VALUE(   396.25) },
      { SIMDE_FLOAT16_VALUE(  -934.50), SIMDE_FLOAT16_VALUE(   -18.20), SIMDE_FLOAT16_VALUE(   855.00), SIMDE_FLOAT16_VALUE(   748.50) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   145.12), SIMDE_FLOAT16_VALUE(  -781.50), SIMDE_FLOAT16_VALUE(  -379.50), SIMDE_FLOAT16_VALUE(    23.91) },
      { SIMDE_FLOAT16_VALUE(   854.00), SIMDE_FLOAT16_VALUE(   763.50), SIMDE_FLOAT16_VALUE(   -35.88), SIMDE_FLOAT16_VALUE(   784.50) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -940.00), SIMDE_FLOAT16_VALUE(   839.00), SIMDE_FLOAT16_VALUE(   568.00), SIMDE_FLOAT16_VALUE(   462.25) },
      { SIMDE_FLOAT16_VALUE(  -488.25), SIMDE_FLOAT16_VALUE(   -26.98), SIMDE_FLOAT16_VALUE(  -745.50), SIMDE_FLOAT16_VALUE(   482.00) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -816.00), SIMDE_FLOAT16_VALUE(  -606.50), SIMDE_FLOAT16_VALUE(   867.50), SIMDE_FLOAT16_VALUE(   -64.75) },
      { SIMDE_FLOAT16_VALUE(   735.50), SIMDE_FLOAT16_VALUE(  -949.00), SIMDE_FLOAT16_VALUE(   895.50), SIMDE_FLOAT16_VALUE(   155.25) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -613.50), SIMDE_FLOAT16_VALUE(  -394.00), SIMDE_FLOAT16_VALUE(  -448.50), SIMDE_FLOAT16_VALUE(  -548.00) },
      { SIMDE_FLOAT16_VALUE(   587.50), SIMDE_FLOAT16_VALUE(  -593.50), SIMDE_FLOAT16_VALUE(  -799.00), SIMDE_FLOAT16_VALUE(  -267.00) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -375.00), SIMDE_FLOAT16_VALUE(  -178.62), SIMDE_FLOAT16_VALUE(   757.00), SIMDE_FLOAT16_VALUE(  -521.00) },
      { SIMDE_FLOAT16_VALUE(  -415.25), SIMDE_FLOAT16_VALUE(  -279.00), SIMDE_FLOAT16_VALUE(  -736.00), SIMDE_FLOAT16_VALUE(  -355.25) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_uint16x4_t r = simde_vld1_u16(test_vec[i].r);
    simde_uint16x4_t r_ = simde_vcagt_f16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r_, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_uint16x4_t r = simde_vcagt_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcagt_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   311.69), SIMDE_FLOAT32_C(  -932.68) },
      { SIMDE_FLOAT32_C(    98.33), SIMDE_FLOAT32_C(  -552.98) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   959.61), SIMDE_FLOAT32_C(   617.75) },
      { SIMDE_FLOAT32_C(  -197.11), SIMDE_FLOAT32_C(   562.98) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   468.98), SIMDE_FLOAT32_C(  -916.49) },
      { SIMDE_FLOAT32_C(   965.35), SIMDE_FLOAT32_C(   700.25) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -647.13), SIMDE_FLOAT32_C(  -147.35) },
      { SIMDE_FLOAT32_C(  -117.68), SIMDE_FLOAT32_C(  -241.37) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -664.10), SIMDE_FLOAT32_C(  -976.12) },
      { SIMDE_FLOAT32_C(   874.22), SIMDE_FLOAT32_C(   -12.94) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(    25.04), SIMDE_FLOAT32_C(  -125.75) },
      { SIMDE_FLOAT32_C(   212.15), SIMDE_FLOAT32_C(   782.89) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   561.17), SIMDE_FLOAT32_C(   217.87) },
      { SIMDE_FLOAT32_C(  -238.74), SIMDE_FLOAT32_C(   679.32) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -965.46), SIMDE_FLOAT32_C(  -738.96) },
      { SIMDE_FLOAT32_C(  -711.74), SIMDE_FLOAT32_C(   346.23) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_uint32x2_t r = simde_vcagt_f32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcagt_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    simde_float64 b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    85.26) },
      { SIMDE_FLOAT64_C(   122.65) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -500.89) },
      { SIMDE_FLOAT64_C(   936.69) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   594.89) },
      { SIMDE_FLOAT64_C(   788.77) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   543.70) },
      { SIMDE_FLOAT64_C(  -150.09) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -875.02) },
      { SIMDE_FLOAT64_C(   442.69) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   673.76) },
      { SIMDE_FLOAT64_C(   217.24) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   789.39) },
      { SIMDE_FLOAT64_C(   718.78) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -511.44) },
      { SIMDE_FLOAT64_C(   752.01) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_uint64x1_t r = simde_vcagt_f64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcagtq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   131.50), SIMDE_FLOAT16_VALUE(  -289.00), SIMDE_FLOAT16_VALUE(  -100.88), SIMDE_FLOAT16_VALUE(  -881.00),
        SIMDE_FLOAT16_VALUE(  -149.50), SIMDE_FLOAT16_VALUE(   558.00), SIMDE_FLOAT16_VALUE(   800.50), SIMDE_FLOAT16_VALUE(  -454.00) },
      { SIMDE_FLOAT16_VALUE(   227.38), SIMDE_FLOAT16_VALUE(   969.00), SIMDE_FLOAT16_VALUE(   828.50), SIMDE_FLOAT16_VALUE(  -672.50),
        SIMDE_FLOAT16_VALUE(  -452.25), SIMDE_FLOAT16_VALUE(  -720.50), SIMDE_FLOAT16_VALUE(   609.00), SIMDE_FLOAT16_VALUE(   -97.19) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(   400.00), SIMDE_FLOAT16_VALUE(  -230.38), SIMDE_FLOAT16_VALUE(  -477.50), SIMDE_FLOAT16_VALUE(   924.00),
        SIMDE_FLOAT16_VALUE(   -85.00), SIMDE_FLOAT16_VALUE(   -74.06), SIMDE_FLOAT16_VALUE(  -465.50), SIMDE_FLOAT16_VALUE(  -573.50) },
      { SIMDE_FLOAT16_VALUE(  -854.00), SIMDE_FLOAT16_VALUE(   866.00), SIMDE_FLOAT16_VALUE(  -726.00), SIMDE_FLOAT16_VALUE(  -426.00),
        SIMDE_FLOAT16_VALUE(   380.00), SIMDE_FLOAT16_VALUE(  -691.00), SIMDE_FLOAT16_VALUE(   747.50), SIMDE_FLOAT16_VALUE(  -488.50) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(    19.80), SIMDE_FLOAT16_VALUE(  -353.25), SIMDE_FLOAT16_VALUE(  -369.25), SIMDE_FLOAT16_VALUE(   870.50),
        SIMDE_FLOAT16_VALUE(  -795.50), SIMDE_FLOAT16_VALUE(  -569.00), SIMDE_FLOAT16_VALUE(  -584.00), SIMDE_FLOAT16_VALUE(   432.00) },
      { SIMDE_FLOAT16_VALUE(  -600.00), SIMDE_FLOAT16_VALUE(  -755.00), SIMDE_FLOAT16_VALUE(   759.50), SIMDE_FLOAT16_VALUE(   -52.28),
        SIMDE_FLOAT16_VALUE(  -475.25), SIMDE_FLOAT16_VALUE(   368.25), SIMDE_FLOAT16_VALUE(   850.50), SIMDE_FLOAT16_VALUE(   924.50) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -862.00), SIMDE_FLOAT16_VALUE(  -627.00), SIMDE_FLOAT16_VALUE(   848.50), SIMDE_FLOAT16_VALUE(    52.91),
        SIMDE_FLOAT16_VALUE(   299.00), SIMDE_FLOAT16_VALUE(  -617.00), SIMDE_FLOAT16_VALUE(   479.50), SIMDE_FLOAT16_VALUE(   445.25) },
      { SIMDE_FLOAT16_VALUE(  -751.00), SIMDE_FLOAT16_VALUE(   753.50), SIMDE_FLOAT16_VALUE(  -981.00), SIMDE_FLOAT16_VALUE(   629.00),
        SIMDE_FLOAT16_VALUE(  -937.50), SIMDE_FLOAT16_VALUE(   766.50), SIMDE_FLOAT16_VALUE(  -859.50), SIMDE_FLOAT16_VALUE(    82.19) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -586.50), SIMDE_FLOAT16_VALUE(  -229.00), SIMDE_FLOAT16_VALUE(   -47.53), SIMDE_FLOAT16_VALUE(  -382.00),
        SIMDE_FLOAT16_VALUE(   202.12), SIMDE_FLOAT16_VALUE(   368.75), SIMDE_FLOAT16_VALUE(  -950.00), SIMDE_FLOAT16_VALUE(   602.00) },
      { SIMDE_FLOAT16_VALUE(   613.50), SIMDE_FLOAT16_VALUE(   809.50), SIMDE_FLOAT16_VALUE(  -450.00), SIMDE_FLOAT16_VALUE(  -861.50),
        SIMDE_FLOAT16_VALUE(   177.62), SIMDE_FLOAT16_VALUE(  -599.50), SIMDE_FLOAT16_VALUE(  -937.00), SIMDE_FLOAT16_VALUE(   315.50) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -226.62), SIMDE_FLOAT16_VALUE(   911.50), SIMDE_FLOAT16_VALUE(  -631.50), SIMDE_FLOAT16_VALUE(  -927.50),
        SIMDE_FLOAT16_VALUE(  -705.50), SIMDE_FLOAT16_VALUE(   848.00), SIMDE_FLOAT16_VALUE(   517.50), SIMDE_FLOAT16_VALUE(  -456.50) },
      { SIMDE_FLOAT16_VALUE(   601.50), SIMDE_FLOAT16_VALUE(   536.50), SIMDE_FLOAT16_VALUE(  -827.50), SIMDE_FLOAT16_VALUE(   664.00),
        SIMDE_FLOAT16_VALUE(   303.25), SIMDE_FLOAT16_VALUE(  -687.50), SIMDE_FLOAT16_VALUE(  -253.88), SIMDE_FLOAT16_VALUE(   717.00) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(    83.62), SIMDE_FLOAT16_VALUE(   698.50), SIMDE_FLOAT16_VALUE(  -665.00), SIMDE_FLOAT16_VALUE(  -714.50),
        SIMDE_FLOAT16_VALUE(    67.25), SIMDE_FLOAT16_VALUE(  -615.00), SIMDE_FLOAT16_VALUE(   888.00), SIMDE_FLOAT16_VALUE(  -319.25) },
      { SIMDE_FLOAT16_VALUE(  -806.00), SIMDE_FLOAT16_VALUE(  -562.00), SIMDE_FLOAT16_VALUE(  -180.88), SIMDE_FLOAT16_VALUE(   371.75),
        SIMDE_FLOAT16_VALUE(  -161.75), SIMDE_FLOAT16_VALUE(  -117.88), SIMDE_FLOAT16_VALUE(  -312.50), SIMDE_FLOAT16_VALUE(   611.50) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -206.38), SIMDE_FLOAT16_VALUE(    55.94), SIMDE_FLOAT16_VALUE(   684.00), SIMDE_FLOAT16_VALUE(    88.25),
        SIMDE_FLOAT16_VALUE(   -96.19), SIMDE_FLOAT16_VALUE(   201.50), SIMDE_FLOAT16_VALUE(   631.50), SIMDE_FLOAT16_VALUE(  -494.75) },
      { SIMDE_FLOAT16_VALUE(  -261.75), SIMDE_FLOAT16_VALUE(   804.00), SIMDE_FLOAT16_VALUE(  -830.50), SIMDE_FLOAT16_VALUE(  -958.50),
        SIMDE_FLOAT16_VALUE(  -883.50), SIMDE_FLOAT16_VALUE(   -84.69), SIMDE_FLOAT16_VALUE(   758.50), SIMDE_FLOAT16_VALUE(   200.25) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_uint16x8_t r = simde_vld1q_u16(test_vec[i].r);
    simde_uint16x8_t r_ = simde_vcagtq_f16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r_, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_uint16x8_t r = simde_vcagtq_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcagtq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   880.25), SIMDE_FLOAT32_C(   497.37), SIMDE_FLOAT32_C(   188.18), SIMDE_FLOAT32_C(  -214.92) },
      { SIMDE_FLOAT32_C(  -292.63), SIMDE_FLOAT32_C(   165.21), SIMDE_FLOAT32_C(  -507.32), SIMDE_FLOAT32_C(  -554.07) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(    21.58), SIMDE_FLOAT32_C(  -187.66), SIMDE_FLOAT32_C(    52.34), SIMDE_FLOAT32_C(   522.72) },
      { SIMDE_FLOAT32_C(   805.10), SIMDE_FLOAT32_C(  -357.26), SIMDE_FLOAT32_C(   451.59), SIMDE_FLOAT32_C(   744.08) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   113.67), SIMDE_FLOAT32_C(   334.71), SIMDE_FLOAT32_C(   489.01), SIMDE_FLOAT32_C(   347.72) },
      { SIMDE_FLOAT32_C(  -991.50), SIMDE_FLOAT32_C(  -625.74), SIMDE_FLOAT32_C(  -356.50), SIMDE_FLOAT32_C(   848.94) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(    90.46), SIMDE_FLOAT32_C(   858.14), SIMDE_FLOAT32_C(  -123.29), SIMDE_FLOAT32_C(  -917.86) },
      { SIMDE_FLOAT32_C(  -788.14), SIMDE_FLOAT32_C(   739.22), SIMDE_FLOAT32_C(   572.18), SIMDE_FLOAT32_C(  -907.90) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   236.59), SIMDE_FLOAT32_C(  -239.64), SIMDE_FLOAT32_C(  -122.81), SIMDE_FLOAT32_C(   943.97) },
      { SIMDE_FLOAT32_C(   925.57), SIMDE_FLOAT32_C(   369.86), SIMDE_FLOAT32_C(  -610.11), SIMDE_FLOAT32_C(   -52.85) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -817.80), SIMDE_FLOAT32_C(   442.23), SIMDE_FLOAT32_C(  -530.12), SIMDE_FLOAT32_C(   987.30) },
      { SIMDE_FLOAT32_C(  -915.03), SIMDE_FLOAT32_C(   921.46), SIMDE_FLOAT32_C(   731.38), SIMDE_FLOAT32_C(   198.64) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   256.18), SIMDE_FLOAT32_C(   220.39), SIMDE_FLOAT32_C(  -453.64), SIMDE_FLOAT32_C(   264.67) },
      { SIMDE_FLOAT32_C(   594.64), SIMDE_FLOAT32_C(   189.87), SIMDE_FLOAT32_C(   113.62), SIMDE_FLOAT32_C(  -314.89) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(    48.01), SIMDE_FLOAT32_C(   990.32), SIMDE_FLOAT32_C(  -232.76), SIMDE_FLOAT32_C(   259.86) },
      { SIMDE_FLOAT32_C(   729.55), SIMDE_FLOAT32_C(  -660.58), SIMDE_FLOAT32_C(   351.97), SIMDE_FLOAT32_C(   -33.86) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcagtq_f32(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcagtq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   230.31), SIMDE_FLOAT64_C(  -618.28) },
      { SIMDE_FLOAT64_C(   180.85), SIMDE_FLOAT64_C(   444.53) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   217.53), SIMDE_FLOAT64_C(  -615.67) },
      { SIMDE_FLOAT64_C(   629.35), SIMDE_FLOAT64_C(  -484.75) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   170.44), SIMDE_FLOAT64_C(  -454.09) },
      { SIMDE_FLOAT64_C(   330.58), SIMDE_FLOAT64_C(   520.13) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -764.76), SIMDE_FLOAT64_C(  -650.22) },
      { SIMDE_FLOAT64_C(   -78.50), SIMDE_FLOAT64_C(   683.38) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -812.10), SIMDE_FLOAT64_C(   401.95) },
      { SIMDE_FLOAT64_C(  -416.07), SIMDE_FLOAT64_C(   983.29) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -496.16), SIMDE_FLOAT64_C(   249.85) },
      { SIMDE_FLOAT64_C(    57.13), SIMDE_FLOAT64_C(  -909.73) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -537.53), SIMDE_FLOAT64_C(   707.06) },
      { SIMDE_FLOAT64_C(   -45.84), SIMDE_FLOAT64_C(  -807.07) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   -27.41), SIMDE_FLOAT64_C(   231.88) },
      { SIMDE_FLOAT64_C(  -442.67), SIMDE_FLOAT64_C(  -797.10) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcagtq_f64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcagth_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcagts_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcagtd_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcagt_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcagt_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcagt_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcagtq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcagtq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcagtq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
