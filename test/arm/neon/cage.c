#define SIMDE_TEST_ARM_NEON_INSN cage

#include "test-neon.h"
#include "../../../simde/arm/neon/cage.h"

static int
test_simde_vcageh_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    simde_float32 b;
    uint16_t r;
  } test_vec[] = {
     { SIMDE_FLOAT32_C(   -68.07),
      SIMDE_FLOAT32_C(   -41.89),
           UINT16_MAX },
    { SIMDE_FLOAT32_C(    94.15),
      SIMDE_FLOAT32_C(   -23.64),
           UINT16_MAX },
    { SIMDE_FLOAT32_C(   -16.98),
      SIMDE_FLOAT32_C(    36.07),
      UINT16_C(    0) },
    { SIMDE_FLOAT32_C(     8.15),
      SIMDE_FLOAT32_C(   -14.55),
      UINT16_C(    0) },
    { SIMDE_FLOAT32_C(   -74.90),
      SIMDE_FLOAT32_C(    20.98),
           UINT16_MAX },
    { SIMDE_FLOAT32_C(   -93.79),
      SIMDE_FLOAT32_C(    28.02),
           UINT16_MAX },
    { SIMDE_FLOAT32_C(   -40.82),
      SIMDE_FLOAT32_C(    11.37),
           UINT16_MAX },
    { SIMDE_FLOAT32_C(    41.99),
      SIMDE_FLOAT32_C(    40.71),
           UINT16_MAX }    
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_vcageh_f16(simde_float16_from_float32(test_vec[i].a), simde_float16_from_float32(test_vec[i].b));

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-100.0f, 100.0f);
    simde_float32_t b = simde_test_codegen_random_f32(-100.0f, 100.0f);
    uint16_t r = simde_vcageh_f16(simde_float16_from_float32(a), simde_float16_from_float32(b));

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcages_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
    uint32_t r = simde_vcages_f32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t b = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    uint32_t r = simde_vcages_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcaged_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    uint64_t r = simde_vcaged_f64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64_t b = simde_test_codegen_random_f64(-1000.0, 1000.0);
    uint64_t r = simde_vcaged_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcage_f16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      simde_float16 a[4];
      simde_float16 b[4];
      uint16_t r[4];
    } test_vec[] = {
      { { SIMDE_FLOAT16_VALUE(   506.50), SIMDE_FLOAT16_VALUE(   580.50), SIMDE_FLOAT16_VALUE(   209.88), SIMDE_FLOAT16_VALUE(  -273.25) },
      { SIMDE_FLOAT16_VALUE(  -451.25), SIMDE_FLOAT16_VALUE(  -948.00), SIMDE_FLOAT16_VALUE(   325.00), SIMDE_FLOAT16_VALUE(   577.50) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -715.50), SIMDE_FLOAT16_VALUE(  -305.50), SIMDE_FLOAT16_VALUE(  -358.25), SIMDE_FLOAT16_VALUE(     5.56) },
      { SIMDE_FLOAT16_VALUE(   466.75), SIMDE_FLOAT16_VALUE(   482.25), SIMDE_FLOAT16_VALUE(  -649.50), SIMDE_FLOAT16_VALUE(   274.00) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   386.00), SIMDE_FLOAT16_VALUE(   -44.34), SIMDE_FLOAT16_VALUE(   -28.00), SIMDE_FLOAT16_VALUE(  -189.50) },
      { SIMDE_FLOAT16_VALUE(  -874.00), SIMDE_FLOAT16_VALUE(   179.12), SIMDE_FLOAT16_VALUE(   498.25), SIMDE_FLOAT16_VALUE(    26.06) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -109.38), SIMDE_FLOAT16_VALUE(  -715.50), SIMDE_FLOAT16_VALUE(   598.00), SIMDE_FLOAT16_VALUE(    66.88) },
      { SIMDE_FLOAT16_VALUE(   604.50), SIMDE_FLOAT16_VALUE(  -889.50), SIMDE_FLOAT16_VALUE(   -76.75), SIMDE_FLOAT16_VALUE(   111.31) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   691.00), SIMDE_FLOAT16_VALUE(  -867.00), SIMDE_FLOAT16_VALUE(   838.00), SIMDE_FLOAT16_VALUE(  -760.00) },
      { SIMDE_FLOAT16_VALUE(  -815.00), SIMDE_FLOAT16_VALUE(   163.00), SIMDE_FLOAT16_VALUE(   817.50), SIMDE_FLOAT16_VALUE(  -530.50) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(   857.50), SIMDE_FLOAT16_VALUE(  -540.50), SIMDE_FLOAT16_VALUE(   475.25), SIMDE_FLOAT16_VALUE(   324.25) },
      { SIMDE_FLOAT16_VALUE(   941.50), SIMDE_FLOAT16_VALUE(   826.00), SIMDE_FLOAT16_VALUE(  -401.75), SIMDE_FLOAT16_VALUE(   327.75) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -218.38), SIMDE_FLOAT16_VALUE(   570.00), SIMDE_FLOAT16_VALUE(  -862.00), SIMDE_FLOAT16_VALUE(   -92.25) },
      { SIMDE_FLOAT16_VALUE(  -250.75), SIMDE_FLOAT16_VALUE(   636.50), SIMDE_FLOAT16_VALUE(   934.00), SIMDE_FLOAT16_VALUE(   640.00) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   920.50), SIMDE_FLOAT16_VALUE(   532.00), SIMDE_FLOAT16_VALUE(  -293.25), SIMDE_FLOAT16_VALUE(   525.50) },
      { SIMDE_FLOAT16_VALUE(   642.50), SIMDE_FLOAT16_VALUE(   630.00), SIMDE_FLOAT16_VALUE(  -363.25), SIMDE_FLOAT16_VALUE(   333.75) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
      simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
      simde_uint16x4_t r = simde_vcage_f16(a, b);

      simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
      simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
      simde_uint16x4_t r = simde_vcage_f16(a, b);

      simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vcage_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
    simde_uint32x2_t r = simde_vcage_f32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcage_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    simde_uint64x1_t r = simde_vcage_f64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcageq_f16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      simde_float16 a[8];
      simde_float16 b[8];
      uint16_t r[8];
    } test_vec[] = {
      { { SIMDE_FLOAT16_VALUE(   476.50), SIMDE_FLOAT16_VALUE(   975.50), SIMDE_FLOAT16_VALUE(   915.00), SIMDE_FLOAT16_VALUE(  -632.50),
        SIMDE_FLOAT16_VALUE(  -472.75), SIMDE_FLOAT16_VALUE(   317.50), SIMDE_FLOAT16_VALUE(   621.50), SIMDE_FLOAT16_VALUE(   622.50) },
      { SIMDE_FLOAT16_VALUE(  -717.00), SIMDE_FLOAT16_VALUE(  -404.50), SIMDE_FLOAT16_VALUE(   444.00), SIMDE_FLOAT16_VALUE(  -493.50),
        SIMDE_FLOAT16_VALUE(  -270.75), SIMDE_FLOAT16_VALUE(   -59.31), SIMDE_FLOAT16_VALUE(  -330.25), SIMDE_FLOAT16_VALUE(   212.00) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -169.50), SIMDE_FLOAT16_VALUE(  -542.50), SIMDE_FLOAT16_VALUE(  -149.88), SIMDE_FLOAT16_VALUE(  -427.25),
        SIMDE_FLOAT16_VALUE(  -861.00), SIMDE_FLOAT16_VALUE(  -977.50), SIMDE_FLOAT16_VALUE(   717.00), SIMDE_FLOAT16_VALUE(  -377.75) },
      { SIMDE_FLOAT16_VALUE(  -880.50), SIMDE_FLOAT16_VALUE(  -855.00), SIMDE_FLOAT16_VALUE(  -173.38), SIMDE_FLOAT16_VALUE(   725.50),
        SIMDE_FLOAT16_VALUE(   -76.69), SIMDE_FLOAT16_VALUE(  -541.00), SIMDE_FLOAT16_VALUE(   -72.81), SIMDE_FLOAT16_VALUE(  -600.00) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -566.00), SIMDE_FLOAT16_VALUE(  -157.62), SIMDE_FLOAT16_VALUE(  -232.50), SIMDE_FLOAT16_VALUE(   -38.72),
        SIMDE_FLOAT16_VALUE(  -840.50), SIMDE_FLOAT16_VALUE(  -611.00), SIMDE_FLOAT16_VALUE(  -416.50), SIMDE_FLOAT16_VALUE(  -557.50) },
      { SIMDE_FLOAT16_VALUE(   -15.61), SIMDE_FLOAT16_VALUE(  -972.50), SIMDE_FLOAT16_VALUE(   -50.97), SIMDE_FLOAT16_VALUE(   713.50),
        SIMDE_FLOAT16_VALUE(   -31.72), SIMDE_FLOAT16_VALUE(   619.00), SIMDE_FLOAT16_VALUE(   -74.44), SIMDE_FLOAT16_VALUE(   799.00) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -923.50), SIMDE_FLOAT16_VALUE(   775.50), SIMDE_FLOAT16_VALUE(  -628.50), SIMDE_FLOAT16_VALUE(  -784.50),
        SIMDE_FLOAT16_VALUE(   798.00), SIMDE_FLOAT16_VALUE(  -911.50), SIMDE_FLOAT16_VALUE(  -162.25), SIMDE_FLOAT16_VALUE(   917.50) },
      { SIMDE_FLOAT16_VALUE(  -766.50), SIMDE_FLOAT16_VALUE(   664.50), SIMDE_FLOAT16_VALUE(   643.50), SIMDE_FLOAT16_VALUE(   157.00),
        SIMDE_FLOAT16_VALUE(  -877.00), SIMDE_FLOAT16_VALUE(  -429.50), SIMDE_FLOAT16_VALUE(   557.00), SIMDE_FLOAT16_VALUE(  -442.75) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(   413.00), SIMDE_FLOAT16_VALUE(  -675.50), SIMDE_FLOAT16_VALUE(   518.50), SIMDE_FLOAT16_VALUE(   572.50),
        SIMDE_FLOAT16_VALUE(  -286.75), SIMDE_FLOAT16_VALUE(  -898.00), SIMDE_FLOAT16_VALUE(  -985.00), SIMDE_FLOAT16_VALUE(   697.50) },
      { SIMDE_FLOAT16_VALUE(  -870.00), SIMDE_FLOAT16_VALUE(   -35.94), SIMDE_FLOAT16_VALUE(   411.25), SIMDE_FLOAT16_VALUE(    98.06),
        SIMDE_FLOAT16_VALUE(  -417.00), SIMDE_FLOAT16_VALUE(  -663.00), SIMDE_FLOAT16_VALUE(  -103.12), SIMDE_FLOAT16_VALUE(  -340.50) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -887.50), SIMDE_FLOAT16_VALUE(   268.50), SIMDE_FLOAT16_VALUE(  -125.00), SIMDE_FLOAT16_VALUE(   910.50),
        SIMDE_FLOAT16_VALUE(   357.00), SIMDE_FLOAT16_VALUE(   712.50), SIMDE_FLOAT16_VALUE(   828.50), SIMDE_FLOAT16_VALUE(   591.00) },
      { SIMDE_FLOAT16_VALUE(   377.00), SIMDE_FLOAT16_VALUE(   471.75), SIMDE_FLOAT16_VALUE(  -252.25), SIMDE_FLOAT16_VALUE(   500.25),
        SIMDE_FLOAT16_VALUE(  -958.00), SIMDE_FLOAT16_VALUE(  -695.50), SIMDE_FLOAT16_VALUE(  -942.50), SIMDE_FLOAT16_VALUE(   455.25) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(  -371.00), SIMDE_FLOAT16_VALUE(   576.00), SIMDE_FLOAT16_VALUE(    27.72), SIMDE_FLOAT16_VALUE(   342.25),
        SIMDE_FLOAT16_VALUE(   678.50), SIMDE_FLOAT16_VALUE(    42.72), SIMDE_FLOAT16_VALUE(    40.00), SIMDE_FLOAT16_VALUE(   808.00) },
      { SIMDE_FLOAT16_VALUE(  -993.00), SIMDE_FLOAT16_VALUE(  -548.50), SIMDE_FLOAT16_VALUE(   -93.81), SIMDE_FLOAT16_VALUE(  -410.25),
        SIMDE_FLOAT16_VALUE(  -211.88), SIMDE_FLOAT16_VALUE(   803.00), SIMDE_FLOAT16_VALUE(   249.12), SIMDE_FLOAT16_VALUE(   -99.44) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { SIMDE_FLOAT16_VALUE(    71.50), SIMDE_FLOAT16_VALUE(  -876.00), SIMDE_FLOAT16_VALUE(  -188.88), SIMDE_FLOAT16_VALUE(  -571.50),
        SIMDE_FLOAT16_VALUE(   837.00), SIMDE_FLOAT16_VALUE(  -360.50), SIMDE_FLOAT16_VALUE(  -980.50), SIMDE_FLOAT16_VALUE(   213.88) },
      { SIMDE_FLOAT16_VALUE(  -889.00), SIMDE_FLOAT16_VALUE(  -233.00), SIMDE_FLOAT16_VALUE(  -285.75), SIMDE_FLOAT16_VALUE(  -846.50),
        SIMDE_FLOAT16_VALUE(    71.56), SIMDE_FLOAT16_VALUE(  -228.25), SIMDE_FLOAT16_VALUE(   608.50), SIMDE_FLOAT16_VALUE(   700.50) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
      simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
      simde_uint16x8_t r = simde_vcageq_f16(a, b);
      simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
      simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
      simde_uint16x8_t r = simde_vcageq_f16(a, b);

      simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vcageq_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
    simde_uint32x4_t r = simde_vcageq_f32(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcageq_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    simde_uint64x2_t r = simde_vcageq_f64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcageh_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcages_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcaged_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcage_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcage_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcage_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcageq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcageq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcageq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
