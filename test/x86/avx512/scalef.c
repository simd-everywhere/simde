#define SIMDE_TEST_X86_AVX512_INSN scalef

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/scalef.h>

static int
test_simde_mm_scalef_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -574.44),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   524.22) },
      { SIMDE_FLOAT32_C(   500.85),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   876.76) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,      SIMDE_MATH_INFINITYF } },
    #endif
    { { SIMDE_FLOAT32_C(   919.28), SIMDE_FLOAT32_C(  -131.68), SIMDE_FLOAT32_C(  -977.50), SIMDE_FLOAT32_C(  -661.80) },
      { SIMDE_FLOAT32_C(   737.41), SIMDE_FLOAT32_C(  -540.20), SIMDE_FLOAT32_C(   308.25), SIMDE_FLOAT32_C(   444.32) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(     0.37), SIMDE_FLOAT32_C(   498.31), SIMDE_FLOAT32_C(    33.05), SIMDE_FLOAT32_C(  -256.10) },
      { SIMDE_FLOAT32_C(  -472.78), SIMDE_FLOAT32_C(  -591.57), SIMDE_FLOAT32_C(    -2.46), SIMDE_FLOAT32_C(  -254.61) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     4.13), SIMDE_FLOAT32_C(    -0.00) } },
    { { SIMDE_FLOAT32_C(   931.71), SIMDE_FLOAT32_C(  -418.21), SIMDE_FLOAT32_C(   348.08), SIMDE_FLOAT32_C(   395.26) },
      { SIMDE_FLOAT32_C(  -506.53), SIMDE_FLOAT32_C(    75.82), SIMDE_FLOAT32_C(   809.38), SIMDE_FLOAT32_C(   887.05) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-15799526771589293308641280.00),      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   501.38), SIMDE_FLOAT32_C(   -77.34), SIMDE_FLOAT32_C(   411.27), SIMDE_FLOAT32_C(     2.23) },
      { SIMDE_FLOAT32_C(   996.51), SIMDE_FLOAT32_C(   522.28), SIMDE_FLOAT32_C(  -121.01), SIMDE_FLOAT32_C(   915.79) },
      {      SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(  -609.41), SIMDE_FLOAT32_C(   -98.51), SIMDE_FLOAT32_C(  -746.01), SIMDE_FLOAT32_C(  -872.00) },
      { SIMDE_FLOAT32_C(   361.29), SIMDE_FLOAT32_C(   562.24), SIMDE_FLOAT32_C(   572.32), SIMDE_FLOAT32_C(  -638.34) },
      {     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00) } },
    { { SIMDE_FLOAT32_C(    60.55), SIMDE_FLOAT32_C(  -394.64), SIMDE_FLOAT32_C(   105.57), SIMDE_FLOAT32_C(   587.77) },
      { SIMDE_FLOAT32_C(    13.80), SIMDE_FLOAT32_C(  -896.90), SIMDE_FLOAT32_C(  -666.83), SIMDE_FLOAT32_C(   -54.49) },
      { SIMDE_FLOAT32_C(496025.59), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(  -315.11), SIMDE_FLOAT32_C(   681.24), SIMDE_FLOAT32_C(  -659.23), SIMDE_FLOAT32_C(   178.37) },
      { SIMDE_FLOAT32_C(  -242.94), SIMDE_FLOAT32_C(  -849.85), SIMDE_FLOAT32_C(    65.41), SIMDE_FLOAT32_C(  -741.55) },
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-24321293470847155044352.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_scalef_ps(a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128 r = simde_mm_scalef_ps(a, b);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_scalef_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(   510.80), SIMDE_FLOAT32_C(    70.72), SIMDE_FLOAT32_C(  -240.36), SIMDE_FLOAT32_C(   667.59) },
      UINT8_C(167),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   120.08),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   803.63) },
      { SIMDE_FLOAT32_C(  -971.21),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -397.24) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   667.59) } },
    #endif
    { { SIMDE_FLOAT32_C(  -527.36), SIMDE_FLOAT32_C(   207.05), SIMDE_FLOAT32_C(   888.57), SIMDE_FLOAT32_C(   676.31) },
      UINT8_C(209),
      { SIMDE_FLOAT32_C(   382.67), SIMDE_FLOAT32_C(  -251.21), SIMDE_FLOAT32_C(   490.66), SIMDE_FLOAT32_C(   276.18) },
      { SIMDE_FLOAT32_C(  -493.35), SIMDE_FLOAT32_C(   664.91), SIMDE_FLOAT32_C(  -894.03), SIMDE_FLOAT32_C(  -245.08) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   207.05), SIMDE_FLOAT32_C(   888.57), SIMDE_FLOAT32_C(   676.31) } },
    { { SIMDE_FLOAT32_C(   178.54), SIMDE_FLOAT32_C(  -455.11), SIMDE_FLOAT32_C(   -55.71), SIMDE_FLOAT32_C(   223.43) },
      UINT8_C(149),
      { SIMDE_FLOAT32_C(   651.73), SIMDE_FLOAT32_C(   452.73), SIMDE_FLOAT32_C(   119.59), SIMDE_FLOAT32_C(  -408.37) },
      { SIMDE_FLOAT32_C(   720.80), SIMDE_FLOAT32_C(   390.12), SIMDE_FLOAT32_C(   263.08), SIMDE_FLOAT32_C(   973.63) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -455.11),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   223.43) } },
    { { SIMDE_FLOAT32_C(   318.63), SIMDE_FLOAT32_C(  -612.09), SIMDE_FLOAT32_C(  -822.85), SIMDE_FLOAT32_C(   413.77) },
      UINT8_C( 59),
      { SIMDE_FLOAT32_C(  -230.03), SIMDE_FLOAT32_C(  -651.76), SIMDE_FLOAT32_C(  -462.21), SIMDE_FLOAT32_C(   420.82) },
      { SIMDE_FLOAT32_C(   320.60), SIMDE_FLOAT32_C(   961.38), SIMDE_FLOAT32_C(  -871.21), SIMDE_FLOAT32_C(   611.61) },
      {     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -822.85),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(  -447.83), SIMDE_FLOAT32_C(   482.54), SIMDE_FLOAT32_C(  -732.93), SIMDE_FLOAT32_C(   275.44) },
      UINT8_C(204),
      { SIMDE_FLOAT32_C(    81.46), SIMDE_FLOAT32_C(  -363.38), SIMDE_FLOAT32_C(   415.25), SIMDE_FLOAT32_C(   110.24) },
      { SIMDE_FLOAT32_C(  -843.21), SIMDE_FLOAT32_C(  -965.47), SIMDE_FLOAT32_C(   713.00), SIMDE_FLOAT32_C(   539.46) },
      { SIMDE_FLOAT32_C(  -447.83), SIMDE_FLOAT32_C(   482.54),      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(    12.45), SIMDE_FLOAT32_C(   319.29), SIMDE_FLOAT32_C(  -342.96), SIMDE_FLOAT32_C(   886.63) },
      UINT8_C( 98),
      { SIMDE_FLOAT32_C(  -216.68), SIMDE_FLOAT32_C(   203.67), SIMDE_FLOAT32_C(  -184.36), SIMDE_FLOAT32_C(   289.97) },
      { SIMDE_FLOAT32_C(  -131.42), SIMDE_FLOAT32_C(   -78.39), SIMDE_FLOAT32_C(  -955.11), SIMDE_FLOAT32_C(  -479.68) },
      { SIMDE_FLOAT32_C(    12.45), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -342.96), SIMDE_FLOAT32_C(   886.63) } },
    { { SIMDE_FLOAT32_C(  -693.57), SIMDE_FLOAT32_C(   397.43), SIMDE_FLOAT32_C(  -954.51), SIMDE_FLOAT32_C(    66.07) },
      UINT8_C(115),
      { SIMDE_FLOAT32_C(  -625.66), SIMDE_FLOAT32_C(   164.48), SIMDE_FLOAT32_C(   111.94), SIMDE_FLOAT32_C(  -904.86) },
      { SIMDE_FLOAT32_C(  -445.41), SIMDE_FLOAT32_C(  -624.98), SIMDE_FLOAT32_C(  -931.23), SIMDE_FLOAT32_C(   324.57) },
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -954.51), SIMDE_FLOAT32_C(    66.07) } },
    { { SIMDE_FLOAT32_C(   150.74), SIMDE_FLOAT32_C(   538.71), SIMDE_FLOAT32_C(  -727.93), SIMDE_FLOAT32_C(    39.30) },
      UINT8_C(225),
      { SIMDE_FLOAT32_C(  -276.74), SIMDE_FLOAT32_C(  -393.44), SIMDE_FLOAT32_C(  -254.61), SIMDE_FLOAT32_C(  -956.14) },
      { SIMDE_FLOAT32_C(  -432.06), SIMDE_FLOAT32_C(  -125.82), SIMDE_FLOAT32_C(   655.47), SIMDE_FLOAT32_C(   649.39) },
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   538.71), SIMDE_FLOAT32_C(  -727.93), SIMDE_FLOAT32_C(    39.30) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 src = simde_mm_loadu_ps(test_vec[i].src);
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_mask_scalef_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128 r = simde_mm_mask_scalef_ps(src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_scalef_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(  8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -782.16),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   239.05) },
      { SIMDE_FLOAT32_C(   441.27),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   829.17) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    { UINT8_C(212),
      { SIMDE_FLOAT32_C(     2.27), SIMDE_FLOAT32_C(   971.45), SIMDE_FLOAT32_C(  -228.33), SIMDE_FLOAT32_C(   554.45) },
      { SIMDE_FLOAT32_C(   453.99), SIMDE_FLOAT32_C(    38.74), SIMDE_FLOAT32_C(  -170.12), SIMDE_FLOAT32_C(   543.09) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(142),
      { SIMDE_FLOAT32_C(  -948.81), SIMDE_FLOAT32_C(  -850.82), SIMDE_FLOAT32_C(  -799.87), SIMDE_FLOAT32_C(   937.82) },
      { SIMDE_FLOAT32_C(   123.94), SIMDE_FLOAT32_C(  -493.44), SIMDE_FLOAT32_C(   335.26), SIMDE_FLOAT32_C(   169.43) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF } },
    { UINT8_C( 34),
      { SIMDE_FLOAT32_C(   572.63), SIMDE_FLOAT32_C(  -599.72), SIMDE_FLOAT32_C(  -679.83), SIMDE_FLOAT32_C(   111.33) },
      { SIMDE_FLOAT32_C(  -327.65), SIMDE_FLOAT32_C(   359.47), SIMDE_FLOAT32_C(  -673.65), SIMDE_FLOAT32_C(   -32.89) },
      { SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(185),
      { SIMDE_FLOAT32_C(   577.31), SIMDE_FLOAT32_C(  -913.73), SIMDE_FLOAT32_C(  -793.84), SIMDE_FLOAT32_C(    18.58) },
      { SIMDE_FLOAT32_C(   -88.61), SIMDE_FLOAT32_C(  -236.15), SIMDE_FLOAT32_C(  -152.25), SIMDE_FLOAT32_C(   913.66) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    { UINT8_C(110),
      { SIMDE_FLOAT32_C(  -264.70), SIMDE_FLOAT32_C(   619.42), SIMDE_FLOAT32_C(   468.11), SIMDE_FLOAT32_C(  -810.71) },
      { SIMDE_FLOAT32_C(  -341.84), SIMDE_FLOAT32_C(  -702.01), SIMDE_FLOAT32_C(   732.39), SIMDE_FLOAT32_C(  -290.65) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00) } },
    { UINT8_C( 76),
      { SIMDE_FLOAT32_C(  -552.83), SIMDE_FLOAT32_C(   932.51), SIMDE_FLOAT32_C(  -352.83), SIMDE_FLOAT32_C(   571.11) },
      { SIMDE_FLOAT32_C(  -560.93), SIMDE_FLOAT32_C(   982.43), SIMDE_FLOAT32_C(  -259.45), SIMDE_FLOAT32_C(  -988.30) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(172),
      { SIMDE_FLOAT32_C(  -617.29), SIMDE_FLOAT32_C(    60.71), SIMDE_FLOAT32_C(   123.03), SIMDE_FLOAT32_C(    55.06) },
      { SIMDE_FLOAT32_C(  -579.82), SIMDE_FLOAT32_C(   449.39), SIMDE_FLOAT32_C(  -977.83), SIMDE_FLOAT32_C(   997.49) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_maskz_scalef_ps(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128 r = simde_mm_maskz_scalef_ps(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_scalef_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    39.06),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   879.22),
        SIMDE_FLOAT32_C(   799.85), SIMDE_FLOAT32_C(    98.16), SIMDE_FLOAT32_C(   360.53), SIMDE_FLOAT32_C(   817.25) },
      { SIMDE_FLOAT32_C(   981.76),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -177.33),
        SIMDE_FLOAT32_C(  -885.94), SIMDE_FLOAT32_C(   138.17), SIMDE_FLOAT32_C(   764.91), SIMDE_FLOAT32_C(  -195.41) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00) } },
    #endif
    { { SIMDE_FLOAT32_C(   860.80), SIMDE_FLOAT32_C(  -750.11), SIMDE_FLOAT32_C(  -210.97), SIMDE_FLOAT32_C(   614.29),
        SIMDE_FLOAT32_C(   913.44), SIMDE_FLOAT32_C(   400.13), SIMDE_FLOAT32_C(   801.72), SIMDE_FLOAT32_C(   828.58) },
      { SIMDE_FLOAT32_C(  -995.54), SIMDE_FLOAT32_C(   953.74), SIMDE_FLOAT32_C(   674.22), SIMDE_FLOAT32_C(   219.06),
        SIMDE_FLOAT32_C(   633.43), SIMDE_FLOAT32_C(  -596.99), SIMDE_FLOAT32_C(  -149.83), SIMDE_FLOAT32_C(  -755.25) },
      { SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(   442.07), SIMDE_FLOAT32_C(   493.98), SIMDE_FLOAT32_C(  -876.03), SIMDE_FLOAT32_C(   241.92),
        SIMDE_FLOAT32_C(  -407.86), SIMDE_FLOAT32_C(   484.50), SIMDE_FLOAT32_C(    59.17), SIMDE_FLOAT32_C(  -426.10) },
      { SIMDE_FLOAT32_C(  -934.67), SIMDE_FLOAT32_C(   908.49), SIMDE_FLOAT32_C(   396.57), SIMDE_FLOAT32_C(  -820.61),
        SIMDE_FLOAT32_C(    46.66), SIMDE_FLOAT32_C(   161.48), SIMDE_FLOAT32_C(   -16.02), SIMDE_FLOAT32_C(   -92.54) },
      { SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(-28700594969509888.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00) } },
    { { SIMDE_FLOAT32_C(   411.36), SIMDE_FLOAT32_C(   773.01), SIMDE_FLOAT32_C(  -478.24), SIMDE_FLOAT32_C(   324.81),
        SIMDE_FLOAT32_C(   173.14), SIMDE_FLOAT32_C(  -676.52), SIMDE_FLOAT32_C(   153.39), SIMDE_FLOAT32_C(   177.60) },
      { SIMDE_FLOAT32_C(  -722.78), SIMDE_FLOAT32_C(  -172.39), SIMDE_FLOAT32_C(  -603.34), SIMDE_FLOAT32_C(   910.65),
        SIMDE_FLOAT32_C(   230.62), SIMDE_FLOAT32_C(   246.83), SIMDE_FLOAT32_C(  -844.60), SIMDE_FLOAT32_C(  -327.31) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF,
             SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(  -259.19), SIMDE_FLOAT32_C(  -720.63), SIMDE_FLOAT32_C(   914.61), SIMDE_FLOAT32_C(   332.96),
        SIMDE_FLOAT32_C(   763.88), SIMDE_FLOAT32_C(   -26.22), SIMDE_FLOAT32_C(   906.86), SIMDE_FLOAT32_C(   829.21) },
      { SIMDE_FLOAT32_C(  -117.73), SIMDE_FLOAT32_C(   303.42), SIMDE_FLOAT32_C(  -991.40), SIMDE_FLOAT32_C(   928.93),
        SIMDE_FLOAT32_C(  -535.10), SIMDE_FLOAT32_C(    -7.42), SIMDE_FLOAT32_C(  -163.61), SIMDE_FLOAT32_C(   876.26) },
      { SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.10), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(  -234.41), SIMDE_FLOAT32_C(   358.15), SIMDE_FLOAT32_C(   201.07), SIMDE_FLOAT32_C(   938.74),
        SIMDE_FLOAT32_C(   681.63), SIMDE_FLOAT32_C(  -645.54), SIMDE_FLOAT32_C(   116.33), SIMDE_FLOAT32_C(   958.85) },
      { SIMDE_FLOAT32_C(   182.07), SIMDE_FLOAT32_C(   513.00), SIMDE_FLOAT32_C(   869.50), SIMDE_FLOAT32_C(  -587.31),
        SIMDE_FLOAT32_C(  -240.17), SIMDE_FLOAT32_C(  -975.09), SIMDE_FLOAT32_C(    85.37), SIMDE_FLOAT32_C(   500.64) },
      {     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(4500298969900131223638900736.00),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(  -695.72), SIMDE_FLOAT32_C(    -0.02), SIMDE_FLOAT32_C(  -166.40), SIMDE_FLOAT32_C(  -931.84),
        SIMDE_FLOAT32_C(   973.75), SIMDE_FLOAT32_C(  -259.54), SIMDE_FLOAT32_C(   897.36), SIMDE_FLOAT32_C(  -143.98) },
      { SIMDE_FLOAT32_C(  -956.12), SIMDE_FLOAT32_C(   905.96), SIMDE_FLOAT32_C(  -215.05), SIMDE_FLOAT32_C(  -491.22),
        SIMDE_FLOAT32_C(  -101.46), SIMDE_FLOAT32_C(   621.35), SIMDE_FLOAT32_C(  -614.96), SIMDE_FLOAT32_C(   664.13) },
      { SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   -20.50), SIMDE_FLOAT32_C(   586.11), SIMDE_FLOAT32_C(   602.87), SIMDE_FLOAT32_C(  -338.88),
        SIMDE_FLOAT32_C(   940.58), SIMDE_FLOAT32_C(  -280.80), SIMDE_FLOAT32_C(  -380.03), SIMDE_FLOAT32_C(   122.65) },
      { SIMDE_FLOAT32_C(  -767.80), SIMDE_FLOAT32_C(  -510.52), SIMDE_FLOAT32_C(   535.33), SIMDE_FLOAT32_C(    -7.97),
        SIMDE_FLOAT32_C(  -485.61), SIMDE_FLOAT32_C(  -379.29), SIMDE_FLOAT32_C(  -507.33), SIMDE_FLOAT32_C(  -181.33) },
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -1.32),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_scalef_ps(a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x8_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_extract_f32x8(i, 2, 0, values);
    simde__m256 b = simde_test_x86_random_extract_f32x8(i, 2, 1, values);
    simde__m256 r = simde_mm256_scalef_ps(a, b);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_scalef_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(   867.27), SIMDE_FLOAT32_C(  -634.46), SIMDE_FLOAT32_C(  -222.00), SIMDE_FLOAT32_C(  -962.68),
        SIMDE_FLOAT32_C(   917.78), SIMDE_FLOAT32_C(  -612.70), SIMDE_FLOAT32_C(  -579.88), SIMDE_FLOAT32_C(  -888.92) },
      UINT8_C(242),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -925.31),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -690.77),
        SIMDE_FLOAT32_C(   675.94), SIMDE_FLOAT32_C(  -374.50), SIMDE_FLOAT32_C(  -487.76), SIMDE_FLOAT32_C(  -756.43) },
      { SIMDE_FLOAT32_C(  -175.93),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -48.52),
        SIMDE_FLOAT32_C(    96.45), SIMDE_FLOAT32_C(   957.68), SIMDE_FLOAT32_C(   588.59), SIMDE_FLOAT32_C(  -197.83) },
      { SIMDE_FLOAT32_C(   867.27),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -222.00), SIMDE_FLOAT32_C(  -962.68),
        SIMDE_FLOAT32_C(53553484363319967491320765743104.00),     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00) } },
    #endif
    { { SIMDE_FLOAT32_C(   383.03), SIMDE_FLOAT32_C(  -868.75), SIMDE_FLOAT32_C(  -330.42), SIMDE_FLOAT32_C(   976.95),
        SIMDE_FLOAT32_C(   757.69), SIMDE_FLOAT32_C(  -838.96), SIMDE_FLOAT32_C(  -959.76), SIMDE_FLOAT32_C(  -432.14) },
      UINT8_C( 26),
      { SIMDE_FLOAT32_C(  -316.46), SIMDE_FLOAT32_C(  -406.44), SIMDE_FLOAT32_C(  -251.32), SIMDE_FLOAT32_C(  -212.53),
        SIMDE_FLOAT32_C(   798.11), SIMDE_FLOAT32_C(  -886.02), SIMDE_FLOAT32_C(  -585.83), SIMDE_FLOAT32_C(  -936.92) },
      { SIMDE_FLOAT32_C(   885.55), SIMDE_FLOAT32_C(   273.13), SIMDE_FLOAT32_C(   426.36), SIMDE_FLOAT32_C(   195.17),
        SIMDE_FLOAT32_C(  -463.04), SIMDE_FLOAT32_C(   229.16), SIMDE_FLOAT32_C(  -598.06), SIMDE_FLOAT32_C(  -962.03) },
      { SIMDE_FLOAT32_C(   383.03),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -330.42),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -838.96), SIMDE_FLOAT32_C(  -959.76), SIMDE_FLOAT32_C(  -432.14) } },
    { { SIMDE_FLOAT32_C(   825.42), SIMDE_FLOAT32_C(  -797.66), SIMDE_FLOAT32_C(   103.98), SIMDE_FLOAT32_C(  -141.83),
        SIMDE_FLOAT32_C(   728.06), SIMDE_FLOAT32_C(   316.86), SIMDE_FLOAT32_C(   201.08), SIMDE_FLOAT32_C(   441.10) },
      UINT8_C(185),
      { SIMDE_FLOAT32_C(   303.85), SIMDE_FLOAT32_C(   196.18), SIMDE_FLOAT32_C(  -652.80), SIMDE_FLOAT32_C(   -20.21),
        SIMDE_FLOAT32_C(   821.68), SIMDE_FLOAT32_C(  -140.56), SIMDE_FLOAT32_C(   223.36), SIMDE_FLOAT32_C(  -354.25) },
      { SIMDE_FLOAT32_C(   136.29), SIMDE_FLOAT32_C(  -590.33), SIMDE_FLOAT32_C(   597.23), SIMDE_FLOAT32_C(  -767.26),
        SIMDE_FLOAT32_C(  -632.64), SIMDE_FLOAT32_C(   185.82), SIMDE_FLOAT32_C(    34.90), SIMDE_FLOAT32_C(    50.90) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -797.66), SIMDE_FLOAT32_C(   103.98), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   201.08), SIMDE_FLOAT32_C(-398850041998999552.00) } },
    { { SIMDE_FLOAT32_C(   -45.25), SIMDE_FLOAT32_C(   -58.61), SIMDE_FLOAT32_C(   -79.21), SIMDE_FLOAT32_C(  -433.04),
        SIMDE_FLOAT32_C(  -191.34), SIMDE_FLOAT32_C(   286.33), SIMDE_FLOAT32_C(   344.96), SIMDE_FLOAT32_C(  -154.03) },
      UINT8_C( 54),
      { SIMDE_FLOAT32_C(   779.38), SIMDE_FLOAT32_C(   783.58), SIMDE_FLOAT32_C(   838.36), SIMDE_FLOAT32_C(   577.49),
        SIMDE_FLOAT32_C(   897.56), SIMDE_FLOAT32_C(  -747.47), SIMDE_FLOAT32_C(   640.57), SIMDE_FLOAT32_C(   783.11) },
      { SIMDE_FLOAT32_C(   525.66), SIMDE_FLOAT32_C(    66.92), SIMDE_FLOAT32_C(   -21.72), SIMDE_FLOAT32_C(  -937.39),
        SIMDE_FLOAT32_C(  -703.91), SIMDE_FLOAT32_C(   380.22), SIMDE_FLOAT32_C(  -899.41), SIMDE_FLOAT32_C(   599.93) },
      { SIMDE_FLOAT32_C(   -45.25), SIMDE_FLOAT32_C(57818000146117217484800.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -433.04),
        SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   344.96), SIMDE_FLOAT32_C(  -154.03) } },
    { { SIMDE_FLOAT32_C(   732.26), SIMDE_FLOAT32_C(   266.10), SIMDE_FLOAT32_C(   315.19), SIMDE_FLOAT32_C(  -594.88),
        SIMDE_FLOAT32_C(  -350.87), SIMDE_FLOAT32_C(   446.44), SIMDE_FLOAT32_C(    74.70), SIMDE_FLOAT32_C(  -373.92) },
      UINT8_C(178),
      { SIMDE_FLOAT32_C(  -423.60), SIMDE_FLOAT32_C(  -552.21), SIMDE_FLOAT32_C(  -420.28), SIMDE_FLOAT32_C(  -601.92),
        SIMDE_FLOAT32_C(   307.23), SIMDE_FLOAT32_C(   803.08), SIMDE_FLOAT32_C(    43.83), SIMDE_FLOAT32_C(  -556.48) },
      { SIMDE_FLOAT32_C(  -787.25), SIMDE_FLOAT32_C(  -358.94), SIMDE_FLOAT32_C(  -323.74), SIMDE_FLOAT32_C(  -419.89),
        SIMDE_FLOAT32_C(   826.88), SIMDE_FLOAT32_C(   711.16), SIMDE_FLOAT32_C(   631.01), SIMDE_FLOAT32_C(   606.26) },
      { SIMDE_FLOAT32_C(   732.26), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   315.19), SIMDE_FLOAT32_C(  -594.88),
             SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    74.70),     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   235.74), SIMDE_FLOAT32_C(  -333.68), SIMDE_FLOAT32_C(   771.99), SIMDE_FLOAT32_C(  -719.46),
        SIMDE_FLOAT32_C(  -508.26), SIMDE_FLOAT32_C(   974.33), SIMDE_FLOAT32_C(   384.53), SIMDE_FLOAT32_C(   349.91) },
      UINT8_C( 46),
      { SIMDE_FLOAT32_C(   494.74), SIMDE_FLOAT32_C(   469.37), SIMDE_FLOAT32_C(   183.74), SIMDE_FLOAT32_C(   392.30),
        SIMDE_FLOAT32_C(   721.90), SIMDE_FLOAT32_C(  -175.69), SIMDE_FLOAT32_C(   175.42), SIMDE_FLOAT32_C(   247.56) },
      { SIMDE_FLOAT32_C(   891.23), SIMDE_FLOAT32_C(  -846.30), SIMDE_FLOAT32_C(   310.17), SIMDE_FLOAT32_C(  -812.68),
        SIMDE_FLOAT32_C(   533.92), SIMDE_FLOAT32_C(   410.76), SIMDE_FLOAT32_C(   787.25), SIMDE_FLOAT32_C(  -889.67) },
      { SIMDE_FLOAT32_C(   235.74), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -508.26),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   384.53), SIMDE_FLOAT32_C(   349.91) } },
    { { SIMDE_FLOAT32_C(  -298.61), SIMDE_FLOAT32_C(  -449.02), SIMDE_FLOAT32_C(   143.49), SIMDE_FLOAT32_C(   765.05),
        SIMDE_FLOAT32_C(   505.73), SIMDE_FLOAT32_C(  -915.12), SIMDE_FLOAT32_C(  -314.15), SIMDE_FLOAT32_C(  -927.30) },
      UINT8_C( 96),
      { SIMDE_FLOAT32_C(   858.55), SIMDE_FLOAT32_C(  -633.02), SIMDE_FLOAT32_C(  -491.59), SIMDE_FLOAT32_C(   165.78),
        SIMDE_FLOAT32_C(  -829.95), SIMDE_FLOAT32_C(   552.24), SIMDE_FLOAT32_C(   609.30), SIMDE_FLOAT32_C(  -617.20) },
      { SIMDE_FLOAT32_C(  -806.70), SIMDE_FLOAT32_C(  -714.44), SIMDE_FLOAT32_C(   -37.09), SIMDE_FLOAT32_C(  -979.82),
        SIMDE_FLOAT32_C(   996.72), SIMDE_FLOAT32_C(  -406.08), SIMDE_FLOAT32_C(   626.43), SIMDE_FLOAT32_C(   491.46) },
      { SIMDE_FLOAT32_C(  -298.61), SIMDE_FLOAT32_C(  -449.02), SIMDE_FLOAT32_C(   143.49), SIMDE_FLOAT32_C(   765.05),
        SIMDE_FLOAT32_C(   505.73), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -927.30) } },
    { { SIMDE_FLOAT32_C(   972.18), SIMDE_FLOAT32_C(   417.66), SIMDE_FLOAT32_C(   739.51), SIMDE_FLOAT32_C(   176.29),
        SIMDE_FLOAT32_C(   149.93), SIMDE_FLOAT32_C(     5.61), SIMDE_FLOAT32_C(  -508.52), SIMDE_FLOAT32_C(   555.05) },
      UINT8_C(250),
      { SIMDE_FLOAT32_C(  -936.71), SIMDE_FLOAT32_C(  -189.83), SIMDE_FLOAT32_C(  -116.24), SIMDE_FLOAT32_C(   785.19),
        SIMDE_FLOAT32_C(   634.48), SIMDE_FLOAT32_C(  -940.82), SIMDE_FLOAT32_C(    32.74), SIMDE_FLOAT32_C(   525.72) },
      { SIMDE_FLOAT32_C(  -787.12), SIMDE_FLOAT32_C(  -657.09), SIMDE_FLOAT32_C(   713.04), SIMDE_FLOAT32_C(   746.80),
        SIMDE_FLOAT32_C(   753.67), SIMDE_FLOAT32_C(   500.29), SIMDE_FLOAT32_C(   857.13), SIMDE_FLOAT32_C(   612.22) },
      { SIMDE_FLOAT32_C(   972.18), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   739.51),      SIMDE_MATH_INFINITYF,
             SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_mask_scalef_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x8_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_extract_f32x8(i, 2, 0, values);
    simde__m256 b = simde_test_x86_random_extract_f32x8(i, 2, 1, values);
    simde__m256 r = simde_mm256_mask_scalef_ps(src, k, a, b);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_scalef_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT8_C(186),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -178.84),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    73.91),
        SIMDE_FLOAT32_C(   775.85), SIMDE_FLOAT32_C(  -179.10), SIMDE_FLOAT32_C(  -902.23), SIMDE_FLOAT32_C(   808.26) },
      { SIMDE_FLOAT32_C(   157.12),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -829.15),
        SIMDE_FLOAT32_C(   857.21), SIMDE_FLOAT32_C(   874.94), SIMDE_FLOAT32_C(  -731.65), SIMDE_FLOAT32_C(   885.12) },
      { SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
             SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    #endif
    { UINT8_C(254),
      { SIMDE_FLOAT32_C(  -373.68), SIMDE_FLOAT32_C(  -338.69), SIMDE_FLOAT32_C(   -17.30), SIMDE_FLOAT32_C(  -429.35),
        SIMDE_FLOAT32_C(   603.79), SIMDE_FLOAT32_C(  -761.55), SIMDE_FLOAT32_C(   662.37), SIMDE_FLOAT32_C(   998.63) },
      { SIMDE_FLOAT32_C(   271.41), SIMDE_FLOAT32_C(   639.65), SIMDE_FLOAT32_C(   500.97), SIMDE_FLOAT32_C(   133.67),
        SIMDE_FLOAT32_C(  -849.31), SIMDE_FLOAT32_C(  -311.72), SIMDE_FLOAT32_C(  -251.83), SIMDE_FLOAT32_C(   361.48) },
      { SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    { UINT8_C( 91),
      { SIMDE_FLOAT32_C(   509.45), SIMDE_FLOAT32_C(  -862.03), SIMDE_FLOAT32_C(  -564.61), SIMDE_FLOAT32_C(   285.30),
        SIMDE_FLOAT32_C(   -41.13), SIMDE_FLOAT32_C(  -466.84), SIMDE_FLOAT32_C(    93.56), SIMDE_FLOAT32_C(  -884.01) },
      { SIMDE_FLOAT32_C(  -518.82), SIMDE_FLOAT32_C(   198.48), SIMDE_FLOAT32_C(  -713.16), SIMDE_FLOAT32_C(  -661.61),
        SIMDE_FLOAT32_C(    73.43), SIMDE_FLOAT32_C(  -444.81), SIMDE_FLOAT32_C(  -776.49), SIMDE_FLOAT32_C(   699.75) },
      { SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(-388461876968920180588544.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(167),
      { SIMDE_FLOAT32_C(   216.50), SIMDE_FLOAT32_C(   206.21), SIMDE_FLOAT32_C(  -729.60), SIMDE_FLOAT32_C(  -179.71),
        SIMDE_FLOAT32_C(   444.66), SIMDE_FLOAT32_C(   932.77), SIMDE_FLOAT32_C(  -181.08), SIMDE_FLOAT32_C(  -283.93) },
      { SIMDE_FLOAT32_C(   572.42), SIMDE_FLOAT32_C(  -680.11), SIMDE_FLOAT32_C(   849.74), SIMDE_FLOAT32_C(   723.11),
        SIMDE_FLOAT32_C(     8.17), SIMDE_FLOAT32_C(  -402.09), SIMDE_FLOAT32_C(    84.60), SIMDE_FLOAT32_C(  -482.38) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00) } },
    { UINT8_C( 15),
      { SIMDE_FLOAT32_C(  -264.12), SIMDE_FLOAT32_C(   519.99), SIMDE_FLOAT32_C(   802.92), SIMDE_FLOAT32_C(   694.75),
        SIMDE_FLOAT32_C(  -946.85), SIMDE_FLOAT32_C(  -103.53), SIMDE_FLOAT32_C(   810.74), SIMDE_FLOAT32_C(  -465.67) },
      { SIMDE_FLOAT32_C(  -905.04), SIMDE_FLOAT32_C(  -902.42), SIMDE_FLOAT32_C(  -127.28), SIMDE_FLOAT32_C(   168.39),
        SIMDE_FLOAT32_C(  -347.23), SIMDE_FLOAT32_C(    96.24), SIMDE_FLOAT32_C(  -131.87), SIMDE_FLOAT32_C(   869.27) },
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 37),
      { SIMDE_FLOAT32_C(  -697.56), SIMDE_FLOAT32_C(   138.53), SIMDE_FLOAT32_C(  -310.44), SIMDE_FLOAT32_C(   747.10),
        SIMDE_FLOAT32_C(    71.30), SIMDE_FLOAT32_C(   508.48), SIMDE_FLOAT32_C(  -536.83), SIMDE_FLOAT32_C(  -356.28) },
      { SIMDE_FLOAT32_C(   828.37), SIMDE_FLOAT32_C(  -687.09), SIMDE_FLOAT32_C(  -633.17), SIMDE_FLOAT32_C(  -163.46),
        SIMDE_FLOAT32_C(   -89.17), SIMDE_FLOAT32_C(   451.43), SIMDE_FLOAT32_C(   354.16), SIMDE_FLOAT32_C(   646.71) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(173),
      { SIMDE_FLOAT32_C(   -28.58), SIMDE_FLOAT32_C(   157.08), SIMDE_FLOAT32_C(   341.46), SIMDE_FLOAT32_C(    24.57),
        SIMDE_FLOAT32_C(  -946.45), SIMDE_FLOAT32_C(   152.20), SIMDE_FLOAT32_C(   558.90), SIMDE_FLOAT32_C(  -851.49) },
      { SIMDE_FLOAT32_C(   249.78), SIMDE_FLOAT32_C(  -568.37), SIMDE_FLOAT32_C(   316.90), SIMDE_FLOAT32_C(   902.55),
        SIMDE_FLOAT32_C(   527.86), SIMDE_FLOAT32_C(  -814.97), SIMDE_FLOAT32_C(   771.83), SIMDE_FLOAT32_C(   830.31) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF } },
    { UINT8_C(195),
      { SIMDE_FLOAT32_C(   323.56), SIMDE_FLOAT32_C(  -538.61), SIMDE_FLOAT32_C(   577.41), SIMDE_FLOAT32_C(  -605.14),
        SIMDE_FLOAT32_C(   969.87), SIMDE_FLOAT32_C(  -959.42), SIMDE_FLOAT32_C(    38.58), SIMDE_FLOAT32_C(   798.24) },
      { SIMDE_FLOAT32_C(  -646.50), SIMDE_FLOAT32_C(   405.42), SIMDE_FLOAT32_C(  -365.22), SIMDE_FLOAT32_C(   264.32),
        SIMDE_FLOAT32_C(  -143.15), SIMDE_FLOAT32_C(   988.94), SIMDE_FLOAT32_C(   -88.97), SIMDE_FLOAT32_C(   828.26) },
      { SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256 b = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256 r = simde_mm256_maskz_scalef_ps(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x8_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_extract_f32x8(i, 2, 0, values);
    simde__m256 b = simde_test_x86_random_extract_f32x8(i, 2, 1, values);
    simde__m256 r = simde_mm256_maskz_scalef_ps(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_scalef_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -941.86),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -47.07),
        SIMDE_FLOAT32_C(  -156.60), SIMDE_FLOAT32_C(   419.86), SIMDE_FLOAT32_C(  -712.98), SIMDE_FLOAT32_C(  -783.29),
        SIMDE_FLOAT32_C(    69.87), SIMDE_FLOAT32_C(   -21.10), SIMDE_FLOAT32_C(  -277.06), SIMDE_FLOAT32_C(   523.29),
        SIMDE_FLOAT32_C(  -586.99), SIMDE_FLOAT32_C(   332.51), SIMDE_FLOAT32_C(   560.50), SIMDE_FLOAT32_C(  -464.61) },
      { SIMDE_FLOAT32_C(   654.36),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   462.88),
        SIMDE_FLOAT32_C(  -277.88), SIMDE_FLOAT32_C(  -634.57), SIMDE_FLOAT32_C(   -80.52), SIMDE_FLOAT32_C(   989.53),
        SIMDE_FLOAT32_C(   286.30), SIMDE_FLOAT32_C(  -241.62), SIMDE_FLOAT32_C(  -571.25), SIMDE_FLOAT32_C(   770.87),
        SIMDE_FLOAT32_C(   519.90), SIMDE_FLOAT32_C(   854.89), SIMDE_FLOAT32_C(   -33.16), SIMDE_FLOAT32_C(   127.70) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF,
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF } },
    #endif
    { { SIMDE_FLOAT32_C(   913.03), SIMDE_FLOAT32_C(   -34.30), SIMDE_FLOAT32_C(  -919.38), SIMDE_FLOAT32_C(  -243.57),
        SIMDE_FLOAT32_C(  -614.45), SIMDE_FLOAT32_C(  -632.36), SIMDE_FLOAT32_C(   -26.86), SIMDE_FLOAT32_C(   455.43),
        SIMDE_FLOAT32_C(   346.55), SIMDE_FLOAT32_C(   696.08), SIMDE_FLOAT32_C(   -21.28), SIMDE_FLOAT32_C(   759.56),
        SIMDE_FLOAT32_C(    28.59), SIMDE_FLOAT32_C(  -460.78), SIMDE_FLOAT32_C(  -705.05), SIMDE_FLOAT32_C(  -317.05) },
      { SIMDE_FLOAT32_C(   662.85), SIMDE_FLOAT32_C(    11.06), SIMDE_FLOAT32_C(  -854.18), SIMDE_FLOAT32_C(  -615.03),
        SIMDE_FLOAT32_C(   376.49), SIMDE_FLOAT32_C(    65.30), SIMDE_FLOAT32_C(  -625.50), SIMDE_FLOAT32_C(  -337.21),
        SIMDE_FLOAT32_C(   823.68), SIMDE_FLOAT32_C(  -196.74), SIMDE_FLOAT32_C(  -566.34), SIMDE_FLOAT32_C(   343.57),
        SIMDE_FLOAT32_C(  -341.85), SIMDE_FLOAT32_C(   400.50), SIMDE_FLOAT32_C(  -528.73), SIMDE_FLOAT32_C(  -428.82) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-70246.40), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-23329965624469988835328.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00) } },
    { { SIMDE_FLOAT32_C(  -633.80), SIMDE_FLOAT32_C(  -448.10), SIMDE_FLOAT32_C(   327.62), SIMDE_FLOAT32_C(  -248.25),
        SIMDE_FLOAT32_C(   -80.46), SIMDE_FLOAT32_C(  -699.24), SIMDE_FLOAT32_C(  -792.82), SIMDE_FLOAT32_C(  -733.92),
        SIMDE_FLOAT32_C(   996.84), SIMDE_FLOAT32_C(   185.90), SIMDE_FLOAT32_C(  -974.36), SIMDE_FLOAT32_C(    25.42),
        SIMDE_FLOAT32_C(   725.12), SIMDE_FLOAT32_C(  -679.41), SIMDE_FLOAT32_C(   708.37), SIMDE_FLOAT32_C(   387.97) },
      { SIMDE_FLOAT32_C(   331.65), SIMDE_FLOAT32_C(   854.19), SIMDE_FLOAT32_C(   772.94), SIMDE_FLOAT32_C(  -291.85),
        SIMDE_FLOAT32_C(   -80.51), SIMDE_FLOAT32_C(  -852.55), SIMDE_FLOAT32_C(   370.94), SIMDE_FLOAT32_C(  -256.84),
        SIMDE_FLOAT32_C(   -49.30), SIMDE_FLOAT32_C(   804.60), SIMDE_FLOAT32_C(  -913.26), SIMDE_FLOAT32_C(   608.85),
        SIMDE_FLOAT32_C(   205.10), SIMDE_FLOAT32_C(  -441.99), SIMDE_FLOAT32_C(  -819.97), SIMDE_FLOAT32_C(   571.30) },
      {     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF,
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   109.91), SIMDE_FLOAT32_C(   507.65), SIMDE_FLOAT32_C(  -676.94), SIMDE_FLOAT32_C(  -970.55),
        SIMDE_FLOAT32_C(   808.40), SIMDE_FLOAT32_C(  -469.76), SIMDE_FLOAT32_C(  -704.47), SIMDE_FLOAT32_C(   805.24),
        SIMDE_FLOAT32_C(   716.14), SIMDE_FLOAT32_C(  -678.83), SIMDE_FLOAT32_C(  -169.34), SIMDE_FLOAT32_C(   441.26),
        SIMDE_FLOAT32_C(  -358.23), SIMDE_FLOAT32_C(  -460.97), SIMDE_FLOAT32_C(  -170.77), SIMDE_FLOAT32_C(   973.42) },
      { SIMDE_FLOAT32_C(  -606.78), SIMDE_FLOAT32_C(  -397.82), SIMDE_FLOAT32_C(  -318.44), SIMDE_FLOAT32_C(   312.71),
        SIMDE_FLOAT32_C(  -250.38), SIMDE_FLOAT32_C(  -947.50), SIMDE_FLOAT32_C(  -944.13), SIMDE_FLOAT32_C(   700.32),
        SIMDE_FLOAT32_C(   857.10), SIMDE_FLOAT32_C(  -857.39), SIMDE_FLOAT32_C(   309.17), SIMDE_FLOAT32_C(    62.21),
        SIMDE_FLOAT32_C(  -299.38), SIMDE_FLOAT32_C(   489.21), SIMDE_FLOAT32_C(  -366.49), SIMDE_FLOAT32_C(   810.53) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF,
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(2034952617527265460224.00),
        SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(    -3.14), SIMDE_FLOAT32_C(   -43.43), SIMDE_FLOAT32_C(   839.97), SIMDE_FLOAT32_C(  -194.74),
        SIMDE_FLOAT32_C(   486.80), SIMDE_FLOAT32_C(  -864.50), SIMDE_FLOAT32_C(  -389.50), SIMDE_FLOAT32_C(   202.94),
        SIMDE_FLOAT32_C(  -543.32), SIMDE_FLOAT32_C(   441.16), SIMDE_FLOAT32_C(  -355.80), SIMDE_FLOAT32_C(    98.44),
        SIMDE_FLOAT32_C(   980.20), SIMDE_FLOAT32_C(   473.43), SIMDE_FLOAT32_C(    71.86), SIMDE_FLOAT32_C(  -626.58) },
      { SIMDE_FLOAT32_C(  -924.39), SIMDE_FLOAT32_C(   753.42), SIMDE_FLOAT32_C(   686.13), SIMDE_FLOAT32_C(  -174.77),
        SIMDE_FLOAT32_C(   805.92), SIMDE_FLOAT32_C(   742.00), SIMDE_FLOAT32_C(  -474.45), SIMDE_FLOAT32_C(   663.03),
        SIMDE_FLOAT32_C(   884.61), SIMDE_FLOAT32_C(   834.73), SIMDE_FLOAT32_C(  -274.77), SIMDE_FLOAT32_C(  -414.76),
        SIMDE_FLOAT32_C(   323.93), SIMDE_FLOAT32_C(   358.74), SIMDE_FLOAT32_C(  -604.24), SIMDE_FLOAT32_C(  -679.21) },
      { SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),
             SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),
             SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00) } },
    { { SIMDE_FLOAT32_C(  -684.70), SIMDE_FLOAT32_C(  -764.26), SIMDE_FLOAT32_C(   126.05), SIMDE_FLOAT32_C(   802.11),
        SIMDE_FLOAT32_C(  -628.76), SIMDE_FLOAT32_C(   736.55), SIMDE_FLOAT32_C(     5.05), SIMDE_FLOAT32_C(  -172.08),
        SIMDE_FLOAT32_C(   177.71), SIMDE_FLOAT32_C(   649.25), SIMDE_FLOAT32_C(   926.36), SIMDE_FLOAT32_C(   157.91),
        SIMDE_FLOAT32_C(   122.68), SIMDE_FLOAT32_C(    -1.78), SIMDE_FLOAT32_C(   531.33), SIMDE_FLOAT32_C(   198.28) },
      { SIMDE_FLOAT32_C(  -248.36), SIMDE_FLOAT32_C(   217.45), SIMDE_FLOAT32_C(  -976.49), SIMDE_FLOAT32_C(  -442.43),
        SIMDE_FLOAT32_C(   -40.54), SIMDE_FLOAT32_C(  -450.94), SIMDE_FLOAT32_C(  -779.41), SIMDE_FLOAT32_C(  -155.93),
        SIMDE_FLOAT32_C(  -616.21), SIMDE_FLOAT32_C(   -54.18), SIMDE_FLOAT32_C(   429.31), SIMDE_FLOAT32_C(   707.72),
        SIMDE_FLOAT32_C(  -695.44), SIMDE_FLOAT32_C(   825.07), SIMDE_FLOAT32_C(  -971.49), SIMDE_FLOAT32_C(  -380.13) },
      { SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(  -939.19), SIMDE_FLOAT32_C(   154.56), SIMDE_FLOAT32_C(  -578.03), SIMDE_FLOAT32_C(  -567.95),
        SIMDE_FLOAT32_C(  -108.89), SIMDE_FLOAT32_C(   427.02), SIMDE_FLOAT32_C(   259.97), SIMDE_FLOAT32_C(  -931.18),
        SIMDE_FLOAT32_C(    76.27), SIMDE_FLOAT32_C(   186.33), SIMDE_FLOAT32_C(   226.73), SIMDE_FLOAT32_C(  -801.06),
        SIMDE_FLOAT32_C(  -815.45), SIMDE_FLOAT32_C(  -241.94), SIMDE_FLOAT32_C(   397.23), SIMDE_FLOAT32_C(   -63.80) },
      { SIMDE_FLOAT32_C(   975.51), SIMDE_FLOAT32_C(   420.74), SIMDE_FLOAT32_C(   493.76), SIMDE_FLOAT32_C(   -65.03),
        SIMDE_FLOAT32_C(   969.81), SIMDE_FLOAT32_C(   714.36), SIMDE_FLOAT32_C(   779.04), SIMDE_FLOAT32_C(  -646.40),
        SIMDE_FLOAT32_C(  -339.82), SIMDE_FLOAT32_C(   208.34), SIMDE_FLOAT32_C(  -938.68), SIMDE_FLOAT32_C(   -35.26),
        SIMDE_FLOAT32_C(    33.41), SIMDE_FLOAT32_C(  -910.17), SIMDE_FLOAT32_C(   584.61), SIMDE_FLOAT32_C(    94.22) },
      {     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),
            -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(-7004662267904.00), SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-1263689176990943439434161324032.00) } },
    { { SIMDE_FLOAT32_C(   244.39), SIMDE_FLOAT32_C(  -993.42), SIMDE_FLOAT32_C(   526.27), SIMDE_FLOAT32_C(  -864.50),
        SIMDE_FLOAT32_C(   433.60), SIMDE_FLOAT32_C(  -213.76), SIMDE_FLOAT32_C(  -795.68), SIMDE_FLOAT32_C(  -490.13),
        SIMDE_FLOAT32_C(   972.57), SIMDE_FLOAT32_C(   431.05), SIMDE_FLOAT32_C(  -291.19), SIMDE_FLOAT32_C(  -842.88),
        SIMDE_FLOAT32_C(  -810.89), SIMDE_FLOAT32_C(  -893.96), SIMDE_FLOAT32_C(    93.32), SIMDE_FLOAT32_C(  -835.37) },
      { SIMDE_FLOAT32_C(   526.79), SIMDE_FLOAT32_C(  -412.92), SIMDE_FLOAT32_C(    99.60), SIMDE_FLOAT32_C(   496.59),
        SIMDE_FLOAT32_C(  -698.56), SIMDE_FLOAT32_C(  -121.37), SIMDE_FLOAT32_C(   850.19), SIMDE_FLOAT32_C(   -38.38),
        SIMDE_FLOAT32_C(  -913.02), SIMDE_FLOAT32_C(   911.51), SIMDE_FLOAT32_C(   926.36), SIMDE_FLOAT32_C(   120.39),
        SIMDE_FLOAT32_C(  -998.66), SIMDE_FLOAT32_C(   510.97), SIMDE_FLOAT32_C(  -785.39), SIMDE_FLOAT32_C(   245.73) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(333563253070455536416637746937856.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_scalef_ps(a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x16_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_extract_f32x16(i, 2, 0, values);
    simde__m512 b = simde_test_x86_random_extract_f32x16(i, 2, 1, values);
    simde__m512 r = simde_mm512_scalef_ps(a, b);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_scalef_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(  -384.09), SIMDE_FLOAT32_C(  -958.76), SIMDE_FLOAT32_C(   466.64), SIMDE_FLOAT32_C(   966.42),
        SIMDE_FLOAT32_C(  -935.87), SIMDE_FLOAT32_C(   220.72), SIMDE_FLOAT32_C(   714.63), SIMDE_FLOAT32_C(   933.35),
        SIMDE_FLOAT32_C(   753.44), SIMDE_FLOAT32_C(  -693.92), SIMDE_FLOAT32_C(  -785.64), SIMDE_FLOAT32_C(   651.72),
        SIMDE_FLOAT32_C(   585.75), SIMDE_FLOAT32_C(   125.22), SIMDE_FLOAT32_C(   285.70), SIMDE_FLOAT32_C(  -119.05) },
      UINT16_C( 6353),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   740.89),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -48.84),
        SIMDE_FLOAT32_C(  -472.87), SIMDE_FLOAT32_C(   585.55), SIMDE_FLOAT32_C(   461.03), SIMDE_FLOAT32_C(  -500.30),
        SIMDE_FLOAT32_C(    16.61), SIMDE_FLOAT32_C(  -830.16), SIMDE_FLOAT32_C(  -343.18), SIMDE_FLOAT32_C(   205.72),
        SIMDE_FLOAT32_C(  -724.11), SIMDE_FLOAT32_C(   750.14), SIMDE_FLOAT32_C(   370.35), SIMDE_FLOAT32_C(   802.67) },
      { SIMDE_FLOAT32_C(  -662.78),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -361.34),
        SIMDE_FLOAT32_C(   348.58), SIMDE_FLOAT32_C(   149.45), SIMDE_FLOAT32_C(   600.28), SIMDE_FLOAT32_C(   435.55),
        SIMDE_FLOAT32_C(    60.96), SIMDE_FLOAT32_C(   526.64), SIMDE_FLOAT32_C(  -444.05), SIMDE_FLOAT32_C(    62.30),
        SIMDE_FLOAT32_C(    37.62), SIMDE_FLOAT32_C(  -229.44), SIMDE_FLOAT32_C(  -691.97), SIMDE_FLOAT32_C(  -444.83) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -958.76), SIMDE_FLOAT32_C(   466.64), SIMDE_FLOAT32_C(   966.42),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   220.72),      SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(   753.44), SIMDE_FLOAT32_C(  -693.92), SIMDE_FLOAT32_C(  -785.64), SIMDE_FLOAT32_C(948716053340381773824.00),
        SIMDE_FLOAT32_C(-99520918585344.00), SIMDE_FLOAT32_C(   125.22), SIMDE_FLOAT32_C(   285.70), SIMDE_FLOAT32_C(  -119.05) } },
    #endif
    { { SIMDE_FLOAT32_C(   622.41), SIMDE_FLOAT32_C(   402.50), SIMDE_FLOAT32_C(   168.18), SIMDE_FLOAT32_C(   951.95),
        SIMDE_FLOAT32_C(   716.56), SIMDE_FLOAT32_C(   604.02), SIMDE_FLOAT32_C(   275.93), SIMDE_FLOAT32_C(  -553.03),
        SIMDE_FLOAT32_C(    55.37), SIMDE_FLOAT32_C(   762.73), SIMDE_FLOAT32_C(  -158.00), SIMDE_FLOAT32_C(   316.47),
        SIMDE_FLOAT32_C(   320.59), SIMDE_FLOAT32_C(   457.91), SIMDE_FLOAT32_C(   357.71), SIMDE_FLOAT32_C(  -212.77) },
      UINT16_C(57868),
      { SIMDE_FLOAT32_C(  -488.55), SIMDE_FLOAT32_C(   689.26), SIMDE_FLOAT32_C(   506.33), SIMDE_FLOAT32_C(    38.58),
        SIMDE_FLOAT32_C(   274.81), SIMDE_FLOAT32_C(   -32.64), SIMDE_FLOAT32_C(   538.27), SIMDE_FLOAT32_C(  -708.59),
        SIMDE_FLOAT32_C(   137.20), SIMDE_FLOAT32_C(  -804.91), SIMDE_FLOAT32_C(   497.13), SIMDE_FLOAT32_C(   413.09),
        SIMDE_FLOAT32_C(   945.23), SIMDE_FLOAT32_C(  -132.52), SIMDE_FLOAT32_C(   215.76), SIMDE_FLOAT32_C(  -717.54) },
      { SIMDE_FLOAT32_C(   337.42), SIMDE_FLOAT32_C(  -484.97), SIMDE_FLOAT32_C(   -78.88), SIMDE_FLOAT32_C(  -314.00),
        SIMDE_FLOAT32_C(   664.48), SIMDE_FLOAT32_C(  -478.60), SIMDE_FLOAT32_C(  -878.45), SIMDE_FLOAT32_C(  -274.56),
        SIMDE_FLOAT32_C(  -951.95), SIMDE_FLOAT32_C(  -322.50), SIMDE_FLOAT32_C(   787.74), SIMDE_FLOAT32_C(    85.66),
        SIMDE_FLOAT32_C(   448.06), SIMDE_FLOAT32_C(  -904.23), SIMDE_FLOAT32_C(   640.83), SIMDE_FLOAT32_C(   959.51) },
      { SIMDE_FLOAT32_C(   622.41), SIMDE_FLOAT32_C(   402.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   716.56), SIMDE_FLOAT32_C(   604.02), SIMDE_FLOAT32_C(   275.93), SIMDE_FLOAT32_C(  -553.03),
        SIMDE_FLOAT32_C(    55.37), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(  -158.00), SIMDE_FLOAT32_C(   316.47),
        SIMDE_FLOAT32_C(   320.59), SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(  -992.05), SIMDE_FLOAT32_C(   138.95), SIMDE_FLOAT32_C(   355.18), SIMDE_FLOAT32_C(   761.39),
        SIMDE_FLOAT32_C(   445.03), SIMDE_FLOAT32_C(   569.54), SIMDE_FLOAT32_C(   413.11), SIMDE_FLOAT32_C(    30.79),
        SIMDE_FLOAT32_C(  -305.24), SIMDE_FLOAT32_C(  -301.19), SIMDE_FLOAT32_C(   911.73), SIMDE_FLOAT32_C(  -292.42),
        SIMDE_FLOAT32_C(  -913.23), SIMDE_FLOAT32_C(   534.14), SIMDE_FLOAT32_C(  -889.91), SIMDE_FLOAT32_C(   254.96) },
      UINT16_C(49817),
      { SIMDE_FLOAT32_C(   785.03), SIMDE_FLOAT32_C(   147.16), SIMDE_FLOAT32_C(    -1.92), SIMDE_FLOAT32_C(    59.84),
        SIMDE_FLOAT32_C(  -885.48), SIMDE_FLOAT32_C(  -463.64), SIMDE_FLOAT32_C(   351.25), SIMDE_FLOAT32_C(   251.72),
        SIMDE_FLOAT32_C(  -268.55), SIMDE_FLOAT32_C(  -151.61), SIMDE_FLOAT32_C(  -335.18), SIMDE_FLOAT32_C(  -323.32),
        SIMDE_FLOAT32_C(   715.87), SIMDE_FLOAT32_C(   880.58), SIMDE_FLOAT32_C(   -40.86), SIMDE_FLOAT32_C(    53.29) },
      { SIMDE_FLOAT32_C(  -604.39), SIMDE_FLOAT32_C(   880.26), SIMDE_FLOAT32_C(   739.29), SIMDE_FLOAT32_C(  -939.91),
        SIMDE_FLOAT32_C(  -598.33), SIMDE_FLOAT32_C(   860.84), SIMDE_FLOAT32_C(  -214.46), SIMDE_FLOAT32_C(  -550.28),
        SIMDE_FLOAT32_C(  -461.66), SIMDE_FLOAT32_C(  -426.72), SIMDE_FLOAT32_C(   535.38), SIMDE_FLOAT32_C(   986.40),
        SIMDE_FLOAT32_C(  -330.95), SIMDE_FLOAT32_C(   176.21), SIMDE_FLOAT32_C(   945.91), SIMDE_FLOAT32_C(  -545.92) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   138.95), SIMDE_FLOAT32_C(   355.18), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   569.54), SIMDE_FLOAT32_C(   413.11), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -305.24), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   911.73), SIMDE_FLOAT32_C(  -292.42),
        SIMDE_FLOAT32_C(  -913.23), SIMDE_FLOAT32_C(   534.14),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(  -141.02), SIMDE_FLOAT32_C(  -237.99), SIMDE_FLOAT32_C(  -726.39), SIMDE_FLOAT32_C(   914.35),
        SIMDE_FLOAT32_C(  -475.26), SIMDE_FLOAT32_C(   115.61), SIMDE_FLOAT32_C(   230.82), SIMDE_FLOAT32_C(   845.33),
        SIMDE_FLOAT32_C(  -426.47), SIMDE_FLOAT32_C(  -411.48), SIMDE_FLOAT32_C(  -367.44), SIMDE_FLOAT32_C(   997.86),
        SIMDE_FLOAT32_C(  -989.64), SIMDE_FLOAT32_C(  -359.48), SIMDE_FLOAT32_C(   136.81), SIMDE_FLOAT32_C(   365.54) },
      UINT16_C(52705),
      { SIMDE_FLOAT32_C(  -676.62), SIMDE_FLOAT32_C(   -56.01), SIMDE_FLOAT32_C(   513.92), SIMDE_FLOAT32_C(  -562.10),
        SIMDE_FLOAT32_C(   480.35), SIMDE_FLOAT32_C(  -134.83), SIMDE_FLOAT32_C(   689.63), SIMDE_FLOAT32_C(  -788.20),
        SIMDE_FLOAT32_C(   713.56), SIMDE_FLOAT32_C(  -645.56), SIMDE_FLOAT32_C(  -111.52), SIMDE_FLOAT32_C(   429.42),
        SIMDE_FLOAT32_C(  -764.98), SIMDE_FLOAT32_C(   847.63), SIMDE_FLOAT32_C(  -517.29), SIMDE_FLOAT32_C(  -369.37) },
      { SIMDE_FLOAT32_C(   727.89), SIMDE_FLOAT32_C(  -778.00), SIMDE_FLOAT32_C(  -309.27), SIMDE_FLOAT32_C(  -870.44),
        SIMDE_FLOAT32_C(  -917.16), SIMDE_FLOAT32_C(   476.26), SIMDE_FLOAT32_C(  -420.73), SIMDE_FLOAT32_C(  -378.82),
        SIMDE_FLOAT32_C(  -950.46), SIMDE_FLOAT32_C(  -885.35), SIMDE_FLOAT32_C(  -392.42), SIMDE_FLOAT32_C(  -281.40),
        SIMDE_FLOAT32_C(   290.87), SIMDE_FLOAT32_C(  -446.51), SIMDE_FLOAT32_C(   172.67), SIMDE_FLOAT32_C(   614.25) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -237.99), SIMDE_FLOAT32_C(  -726.39), SIMDE_FLOAT32_C(   914.35),
        SIMDE_FLOAT32_C(  -475.26),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -411.48), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -989.64), SIMDE_FLOAT32_C(  -359.48),     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   -64.92), SIMDE_FLOAT32_C(   815.02), SIMDE_FLOAT32_C(   612.63), SIMDE_FLOAT32_C(   629.84),
        SIMDE_FLOAT32_C(  -486.17), SIMDE_FLOAT32_C(   524.36), SIMDE_FLOAT32_C(  -662.57), SIMDE_FLOAT32_C(  -399.40),
        SIMDE_FLOAT32_C(    58.50), SIMDE_FLOAT32_C(  -552.49), SIMDE_FLOAT32_C(   855.56), SIMDE_FLOAT32_C(  -455.41),
        SIMDE_FLOAT32_C(  -725.84), SIMDE_FLOAT32_C(  -285.46), SIMDE_FLOAT32_C(   306.60), SIMDE_FLOAT32_C(  -452.23) },
      UINT16_C(57400),
      { SIMDE_FLOAT32_C(   497.48), SIMDE_FLOAT32_C(  -313.41), SIMDE_FLOAT32_C(  -947.85), SIMDE_FLOAT32_C(   -22.17),
        SIMDE_FLOAT32_C(   551.76), SIMDE_FLOAT32_C(   741.77), SIMDE_FLOAT32_C(   189.63), SIMDE_FLOAT32_C(   265.32),
        SIMDE_FLOAT32_C(  -903.79), SIMDE_FLOAT32_C(  -921.89), SIMDE_FLOAT32_C(  -305.26), SIMDE_FLOAT32_C(  -668.76),
        SIMDE_FLOAT32_C(   925.73), SIMDE_FLOAT32_C(   177.45), SIMDE_FLOAT32_C(   -38.13), SIMDE_FLOAT32_C(   653.62) },
      { SIMDE_FLOAT32_C(   399.45), SIMDE_FLOAT32_C(   652.59), SIMDE_FLOAT32_C(   783.18), SIMDE_FLOAT32_C(   482.29),
        SIMDE_FLOAT32_C(   128.86), SIMDE_FLOAT32_C(  -637.55), SIMDE_FLOAT32_C(  -896.53), SIMDE_FLOAT32_C(   178.40),
        SIMDE_FLOAT32_C(  -522.89), SIMDE_FLOAT32_C(  -288.94), SIMDE_FLOAT32_C(   897.00), SIMDE_FLOAT32_C(   767.97),
        SIMDE_FLOAT32_C(   264.55), SIMDE_FLOAT32_C(    69.67), SIMDE_FLOAT32_C(   382.22), SIMDE_FLOAT32_C(  -237.97) },
      { SIMDE_FLOAT32_C(   -64.92), SIMDE_FLOAT32_C(   815.02), SIMDE_FLOAT32_C(   612.63),     -SIMDE_MATH_INFINITYF,
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -662.57), SIMDE_FLOAT32_C(  -399.40),
        SIMDE_FLOAT32_C(    58.50), SIMDE_FLOAT32_C(  -552.49), SIMDE_FLOAT32_C(   855.56), SIMDE_FLOAT32_C(  -455.41),
        SIMDE_FLOAT32_C(  -725.84), SIMDE_FLOAT32_C(104747989746712466948096.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(   663.39), SIMDE_FLOAT32_C(   859.70), SIMDE_FLOAT32_C(   676.68), SIMDE_FLOAT32_C(  -763.09),
        SIMDE_FLOAT32_C(  -551.77), SIMDE_FLOAT32_C(  -690.76), SIMDE_FLOAT32_C(  -765.23), SIMDE_FLOAT32_C(  -541.42),
        SIMDE_FLOAT32_C(   -50.24), SIMDE_FLOAT32_C(   371.58), SIMDE_FLOAT32_C(   824.12), SIMDE_FLOAT32_C(   351.66),
        SIMDE_FLOAT32_C(   953.42), SIMDE_FLOAT32_C(  -240.79), SIMDE_FLOAT32_C(   166.68), SIMDE_FLOAT32_C(   566.05) },
      UINT16_C(32446),
      { SIMDE_FLOAT32_C(   756.26), SIMDE_FLOAT32_C(   434.37), SIMDE_FLOAT32_C(   739.85), SIMDE_FLOAT32_C(   308.03),
        SIMDE_FLOAT32_C(   176.14), SIMDE_FLOAT32_C(   -70.52), SIMDE_FLOAT32_C(  -426.66), SIMDE_FLOAT32_C(   272.35),
        SIMDE_FLOAT32_C(     7.59), SIMDE_FLOAT32_C(   268.08), SIMDE_FLOAT32_C(   603.59), SIMDE_FLOAT32_C(   -66.68),
        SIMDE_FLOAT32_C(  -554.46), SIMDE_FLOAT32_C(  -434.54), SIMDE_FLOAT32_C(  -413.06), SIMDE_FLOAT32_C(   844.99) },
      { SIMDE_FLOAT32_C(  -781.95), SIMDE_FLOAT32_C(  -629.87), SIMDE_FLOAT32_C(   327.28), SIMDE_FLOAT32_C(   346.91),
        SIMDE_FLOAT32_C(  -267.42), SIMDE_FLOAT32_C(   430.76), SIMDE_FLOAT32_C(  -474.69), SIMDE_FLOAT32_C(   209.69),
        SIMDE_FLOAT32_C(  -858.19), SIMDE_FLOAT32_C(  -577.69), SIMDE_FLOAT32_C(   -22.34), SIMDE_FLOAT32_C(   406.36),
        SIMDE_FLOAT32_C(   491.98), SIMDE_FLOAT32_C(  -640.12), SIMDE_FLOAT32_C(  -831.62), SIMDE_FLOAT32_C(   248.25) },
      { SIMDE_FLOAT32_C(   663.39), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -765.23),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(   -50.24), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   566.05) } },
    { { SIMDE_FLOAT32_C(    90.40), SIMDE_FLOAT32_C(  -273.52), SIMDE_FLOAT32_C(  -718.89), SIMDE_FLOAT32_C(  -851.10),
        SIMDE_FLOAT32_C(   173.99), SIMDE_FLOAT32_C(  -863.33), SIMDE_FLOAT32_C(  -306.51), SIMDE_FLOAT32_C(   448.15),
        SIMDE_FLOAT32_C(  -148.79), SIMDE_FLOAT32_C(  -999.91), SIMDE_FLOAT32_C(   995.92), SIMDE_FLOAT32_C(   480.10),
        SIMDE_FLOAT32_C(   831.43), SIMDE_FLOAT32_C(   659.31), SIMDE_FLOAT32_C(   339.80), SIMDE_FLOAT32_C(   508.11) },
      UINT16_C( 2559),
      { SIMDE_FLOAT32_C(   794.25), SIMDE_FLOAT32_C(   908.24), SIMDE_FLOAT32_C(  -443.72), SIMDE_FLOAT32_C(   -29.61),
        SIMDE_FLOAT32_C(  -162.28), SIMDE_FLOAT32_C(   129.62), SIMDE_FLOAT32_C(  -757.26), SIMDE_FLOAT32_C(   845.31),
        SIMDE_FLOAT32_C(  -602.30), SIMDE_FLOAT32_C(   846.33), SIMDE_FLOAT32_C(  -221.37), SIMDE_FLOAT32_C(  -156.76),
        SIMDE_FLOAT32_C(  -588.21), SIMDE_FLOAT32_C(   365.57), SIMDE_FLOAT32_C(  -311.77), SIMDE_FLOAT32_C(  -370.16) },
      { SIMDE_FLOAT32_C(   735.70), SIMDE_FLOAT32_C(  -984.49), SIMDE_FLOAT32_C(   976.75), SIMDE_FLOAT32_C(  -531.72),
        SIMDE_FLOAT32_C(   446.27), SIMDE_FLOAT32_C(  -497.93), SIMDE_FLOAT32_C(   677.96), SIMDE_FLOAT32_C(   588.08),
        SIMDE_FLOAT32_C(   -75.62), SIMDE_FLOAT32_C(  -344.38), SIMDE_FLOAT32_C(    -5.56), SIMDE_FLOAT32_C(  -583.64),
        SIMDE_FLOAT32_C(    15.50), SIMDE_FLOAT32_C(   162.82), SIMDE_FLOAT32_C(   664.61), SIMDE_FLOAT32_C(  -190.25) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(  -999.91), SIMDE_FLOAT32_C(   995.92), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(   831.43), SIMDE_FLOAT32_C(   659.31), SIMDE_FLOAT32_C(   339.80), SIMDE_FLOAT32_C(   508.11) } },
    { { SIMDE_FLOAT32_C(   817.35), SIMDE_FLOAT32_C(  -869.01), SIMDE_FLOAT32_C(  -753.39), SIMDE_FLOAT32_C(  -232.89),
        SIMDE_FLOAT32_C(   502.57), SIMDE_FLOAT32_C(  -929.27), SIMDE_FLOAT32_C(  -881.23), SIMDE_FLOAT32_C(   455.99),
        SIMDE_FLOAT32_C(  -170.06), SIMDE_FLOAT32_C(   285.45), SIMDE_FLOAT32_C(    22.03), SIMDE_FLOAT32_C(   218.99),
        SIMDE_FLOAT32_C(   -34.04), SIMDE_FLOAT32_C(  -887.56), SIMDE_FLOAT32_C(   945.47), SIMDE_FLOAT32_C(   247.07) },
      UINT16_C(32166),
      { SIMDE_FLOAT32_C(    71.06), SIMDE_FLOAT32_C(  -779.11), SIMDE_FLOAT32_C(   780.14), SIMDE_FLOAT32_C(   908.78),
        SIMDE_FLOAT32_C(   350.50), SIMDE_FLOAT32_C(  -977.11), SIMDE_FLOAT32_C(   754.08), SIMDE_FLOAT32_C(   748.21),
        SIMDE_FLOAT32_C(   869.22), SIMDE_FLOAT32_C(  -467.29), SIMDE_FLOAT32_C(  -408.55), SIMDE_FLOAT32_C(  -718.99),
        SIMDE_FLOAT32_C(   898.28), SIMDE_FLOAT32_C(   279.68), SIMDE_FLOAT32_C(   -89.14), SIMDE_FLOAT32_C(   633.98) },
      { SIMDE_FLOAT32_C(   295.19), SIMDE_FLOAT32_C(  -112.39), SIMDE_FLOAT32_C(  -897.74), SIMDE_FLOAT32_C(  -258.54),
        SIMDE_FLOAT32_C(   389.68), SIMDE_FLOAT32_C(   780.22), SIMDE_FLOAT32_C(  -670.46), SIMDE_FLOAT32_C(  -685.95),
        SIMDE_FLOAT32_C(  -564.16), SIMDE_FLOAT32_C(   323.98), SIMDE_FLOAT32_C(  -269.58), SIMDE_FLOAT32_C(   451.34),
        SIMDE_FLOAT32_C(  -513.20), SIMDE_FLOAT32_C(  -604.97), SIMDE_FLOAT32_C(  -738.90), SIMDE_FLOAT32_C(   557.86) },
      { SIMDE_FLOAT32_C(   817.35), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -232.89),
        SIMDE_FLOAT32_C(   502.57),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -881.23), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   285.45), SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   247.07) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_mask_scalef_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x16_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_extract_f32x16(i, 2, 0, values);
    simde__m512 b = simde_test_x86_random_extract_f32x16(i, 2, 1, values);
    simde__m512 r = simde_mm512_mask_scalef_ps(src, k, a, b);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_scalef_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT16_C(60257),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   254.81),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -407.97),
        SIMDE_FLOAT32_C(   760.87), SIMDE_FLOAT32_C(  -325.12), SIMDE_FLOAT32_C(    16.51), SIMDE_FLOAT32_C(    38.28),
        SIMDE_FLOAT32_C(   599.38), SIMDE_FLOAT32_C(   485.34), SIMDE_FLOAT32_C(   133.72), SIMDE_FLOAT32_C(   580.55),
        SIMDE_FLOAT32_C(  -139.95), SIMDE_FLOAT32_C(  -474.22), SIMDE_FLOAT32_C(  -119.72), SIMDE_FLOAT32_C(   230.75) },
      { SIMDE_FLOAT32_C(   613.23),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   488.81),
        SIMDE_FLOAT32_C(   971.27), SIMDE_FLOAT32_C(   124.58), SIMDE_FLOAT32_C(  -409.85), SIMDE_FLOAT32_C(  -229.54),
        SIMDE_FLOAT32_C(  -583.28), SIMDE_FLOAT32_C(   611.22), SIMDE_FLOAT32_C(   -28.00), SIMDE_FLOAT32_C(   -40.38),
        SIMDE_FLOAT32_C(   556.64), SIMDE_FLOAT32_C(   264.91), SIMDE_FLOAT32_C(   835.06), SIMDE_FLOAT32_C(   -53.83) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00) } },
    #endif
    { UINT16_C(18948),
      { SIMDE_FLOAT32_C(  -480.28), SIMDE_FLOAT32_C(   460.06), SIMDE_FLOAT32_C(   538.20), SIMDE_FLOAT32_C(  -719.40),
        SIMDE_FLOAT32_C(  -865.06), SIMDE_FLOAT32_C(  -445.29), SIMDE_FLOAT32_C(   318.88), SIMDE_FLOAT32_C(   734.32),
        SIMDE_FLOAT32_C(  -959.95), SIMDE_FLOAT32_C(  -547.40), SIMDE_FLOAT32_C(   314.88), SIMDE_FLOAT32_C(   -99.90),
        SIMDE_FLOAT32_C(   -21.62), SIMDE_FLOAT32_C(  -804.84), SIMDE_FLOAT32_C(  -869.16), SIMDE_FLOAT32_C(  -408.39) },
      { SIMDE_FLOAT32_C(   239.48), SIMDE_FLOAT32_C(  -209.55), SIMDE_FLOAT32_C(  -919.58), SIMDE_FLOAT32_C(   210.74),
        SIMDE_FLOAT32_C(   915.03), SIMDE_FLOAT32_C(  -329.43), SIMDE_FLOAT32_C(   981.21), SIMDE_FLOAT32_C(  -668.25),
        SIMDE_FLOAT32_C(  -718.22), SIMDE_FLOAT32_C(   -46.79), SIMDE_FLOAT32_C(   291.36), SIMDE_FLOAT32_C(   838.42),
        SIMDE_FLOAT32_C(  -781.88), SIMDE_FLOAT32_C(   126.42), SIMDE_FLOAT32_C(  -215.40), SIMDE_FLOAT32_C(  -262.16) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(38861),
      { SIMDE_FLOAT32_C(  -413.52), SIMDE_FLOAT32_C(  -677.20), SIMDE_FLOAT32_C(    18.44), SIMDE_FLOAT32_C(  -278.58),
        SIMDE_FLOAT32_C(  -122.49), SIMDE_FLOAT32_C(  -662.68), SIMDE_FLOAT32_C(  -544.26), SIMDE_FLOAT32_C(   -82.44),
        SIMDE_FLOAT32_C(  -210.08), SIMDE_FLOAT32_C(   770.62), SIMDE_FLOAT32_C(   817.65), SIMDE_FLOAT32_C(   768.30),
        SIMDE_FLOAT32_C(   965.78), SIMDE_FLOAT32_C(   948.50), SIMDE_FLOAT32_C(  -640.09), SIMDE_FLOAT32_C(   205.26) },
      { SIMDE_FLOAT32_C(  -261.05), SIMDE_FLOAT32_C(  -559.68), SIMDE_FLOAT32_C(  -584.00), SIMDE_FLOAT32_C(  -346.02),
        SIMDE_FLOAT32_C(   110.89), SIMDE_FLOAT32_C(  -602.79), SIMDE_FLOAT32_C(   -14.27), SIMDE_FLOAT32_C(   392.68),
        SIMDE_FLOAT32_C(   350.41), SIMDE_FLOAT32_C(  -722.91), SIMDE_FLOAT32_C(   231.10), SIMDE_FLOAT32_C(   568.53),
        SIMDE_FLOAT32_C(   403.51), SIMDE_FLOAT32_C(  -984.30), SIMDE_FLOAT32_C(  -693.63), SIMDE_FLOAT32_C(   989.99) },
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.02),     -SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    { UINT16_C( 9085),
      { SIMDE_FLOAT32_C(  -661.50), SIMDE_FLOAT32_C(   324.81), SIMDE_FLOAT32_C(  -288.59), SIMDE_FLOAT32_C(   216.01),
        SIMDE_FLOAT32_C(   662.13), SIMDE_FLOAT32_C(   167.15), SIMDE_FLOAT32_C(  -866.44), SIMDE_FLOAT32_C(  -547.95),
        SIMDE_FLOAT32_C(   -62.23), SIMDE_FLOAT32_C(   951.22), SIMDE_FLOAT32_C(  -779.65), SIMDE_FLOAT32_C(   -96.45),
        SIMDE_FLOAT32_C(   899.71), SIMDE_FLOAT32_C(  -419.75), SIMDE_FLOAT32_C(  -891.19), SIMDE_FLOAT32_C(  -361.34) },
      { SIMDE_FLOAT32_C(    20.58), SIMDE_FLOAT32_C(  -475.19), SIMDE_FLOAT32_C(   292.64), SIMDE_FLOAT32_C(  -868.53),
        SIMDE_FLOAT32_C(   -77.98), SIMDE_FLOAT32_C(  -721.63), SIMDE_FLOAT32_C(   524.15), SIMDE_FLOAT32_C(  -727.57),
        SIMDE_FLOAT32_C(  -444.54), SIMDE_FLOAT32_C(  -244.75), SIMDE_FLOAT32_C(   840.96), SIMDE_FLOAT32_C(   958.97),
        SIMDE_FLOAT32_C(  -229.06), SIMDE_FLOAT32_C(  -852.67), SIMDE_FLOAT32_C(   948.96), SIMDE_FLOAT32_C(   109.44) },
      { SIMDE_FLOAT32_C(-693633024.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(43730),
      { SIMDE_FLOAT32_C(   472.13), SIMDE_FLOAT32_C(  -339.63), SIMDE_FLOAT32_C(  -674.55), SIMDE_FLOAT32_C(   134.26),
        SIMDE_FLOAT32_C(   827.52), SIMDE_FLOAT32_C(  -540.99), SIMDE_FLOAT32_C(   586.31), SIMDE_FLOAT32_C(  -234.71),
        SIMDE_FLOAT32_C(  -589.77), SIMDE_FLOAT32_C(   806.65), SIMDE_FLOAT32_C(   668.84), SIMDE_FLOAT32_C(  -690.06),
        SIMDE_FLOAT32_C(  -613.09), SIMDE_FLOAT32_C(   777.65), SIMDE_FLOAT32_C(   -51.40), SIMDE_FLOAT32_C(   407.49) },
      { SIMDE_FLOAT32_C(  -697.54), SIMDE_FLOAT32_C(  -758.76), SIMDE_FLOAT32_C(   538.96), SIMDE_FLOAT32_C(   224.47),
        SIMDE_FLOAT32_C(  -480.40), SIMDE_FLOAT32_C(    63.11), SIMDE_FLOAT32_C(   496.90), SIMDE_FLOAT32_C(    75.06),
        SIMDE_FLOAT32_C(   818.35), SIMDE_FLOAT32_C(   337.86), SIMDE_FLOAT32_C(    34.03), SIMDE_FLOAT32_C(  -410.70),
        SIMDE_FLOAT32_C(   485.18), SIMDE_FLOAT32_C(   -17.01), SIMDE_FLOAT32_C(   698.74), SIMDE_FLOAT32_C(   -42.68) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-8867093351197406438359040.00),
        SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(37360),
      { SIMDE_FLOAT32_C(   643.36), SIMDE_FLOAT32_C(  -975.82), SIMDE_FLOAT32_C(  -908.42), SIMDE_FLOAT32_C(   470.88),
        SIMDE_FLOAT32_C(  -516.81), SIMDE_FLOAT32_C(   677.89), SIMDE_FLOAT32_C(  -763.83), SIMDE_FLOAT32_C(  -106.58),
        SIMDE_FLOAT32_C(   484.54), SIMDE_FLOAT32_C(   905.01), SIMDE_FLOAT32_C(   203.36), SIMDE_FLOAT32_C(   871.45),
        SIMDE_FLOAT32_C(   682.65), SIMDE_FLOAT32_C(  -848.04), SIMDE_FLOAT32_C(   278.94), SIMDE_FLOAT32_C(   985.11) },
      { SIMDE_FLOAT32_C(  -606.80), SIMDE_FLOAT32_C(  -182.10), SIMDE_FLOAT32_C(   209.58), SIMDE_FLOAT32_C(   -87.20),
        SIMDE_FLOAT32_C(   881.00), SIMDE_FLOAT32_C(  -293.52), SIMDE_FLOAT32_C(   987.86), SIMDE_FLOAT32_C(   699.35),
        SIMDE_FLOAT32_C(  -955.66), SIMDE_FLOAT32_C(    21.89), SIMDE_FLOAT32_C(  -711.35), SIMDE_FLOAT32_C(   529.52),
        SIMDE_FLOAT32_C(  -995.12), SIMDE_FLOAT32_C(   987.39), SIMDE_FLOAT32_C(  -513.16), SIMDE_FLOAT32_C(   648.24) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    { UINT16_C(23765),
      { SIMDE_FLOAT32_C(  -988.43), SIMDE_FLOAT32_C(  -421.58), SIMDE_FLOAT32_C(   119.12), SIMDE_FLOAT32_C(  -505.24),
        SIMDE_FLOAT32_C(  -743.69), SIMDE_FLOAT32_C(   355.29), SIMDE_FLOAT32_C(   388.18), SIMDE_FLOAT32_C(   740.85),
        SIMDE_FLOAT32_C(   260.29), SIMDE_FLOAT32_C(  -408.46), SIMDE_FLOAT32_C(   612.30), SIMDE_FLOAT32_C(   -57.05),
        SIMDE_FLOAT32_C(  -256.50), SIMDE_FLOAT32_C(  -108.76), SIMDE_FLOAT32_C(   -71.94), SIMDE_FLOAT32_C(   136.70) },
      { SIMDE_FLOAT32_C(   709.14), SIMDE_FLOAT32_C(  -862.36), SIMDE_FLOAT32_C(  -950.50), SIMDE_FLOAT32_C(   590.14),
        SIMDE_FLOAT32_C(  -155.88), SIMDE_FLOAT32_C(  -962.63), SIMDE_FLOAT32_C(   289.49), SIMDE_FLOAT32_C(  -111.55),
        SIMDE_FLOAT32_C(    59.26), SIMDE_FLOAT32_C(   578.14), SIMDE_FLOAT32_C(  -582.02), SIMDE_FLOAT32_C(    64.14),
        SIMDE_FLOAT32_C(   565.53), SIMDE_FLOAT32_C(   -95.18), SIMDE_FLOAT32_C(  -287.62), SIMDE_FLOAT32_C(   577.10) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-1052386735331381084160.00),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(13355),
      { SIMDE_FLOAT32_C(   483.24), SIMDE_FLOAT32_C(   831.50), SIMDE_FLOAT32_C(  -928.13), SIMDE_FLOAT32_C(   739.55),
        SIMDE_FLOAT32_C(   186.79), SIMDE_FLOAT32_C(   460.05), SIMDE_FLOAT32_C(   480.40), SIMDE_FLOAT32_C(  -552.91),
        SIMDE_FLOAT32_C(  -948.41), SIMDE_FLOAT32_C(    92.70), SIMDE_FLOAT32_C(   390.03), SIMDE_FLOAT32_C(  -204.90),
        SIMDE_FLOAT32_C(   983.95), SIMDE_FLOAT32_C(  -681.91), SIMDE_FLOAT32_C(   931.80), SIMDE_FLOAT32_C(   693.08) },
      { SIMDE_FLOAT32_C(  -544.27), SIMDE_FLOAT32_C(   981.30), SIMDE_FLOAT32_C(   283.22), SIMDE_FLOAT32_C(   299.84),
        SIMDE_FLOAT32_C(  -981.34), SIMDE_FLOAT32_C(  -427.29), SIMDE_FLOAT32_C(  -811.70), SIMDE_FLOAT32_C(    77.92),
        SIMDE_FLOAT32_C(  -849.14), SIMDE_FLOAT32_C(  -393.73), SIMDE_FLOAT32_C(  -857.94), SIMDE_FLOAT32_C(   716.39),
        SIMDE_FLOAT32_C(   511.09), SIMDE_FLOAT32_C(  -145.55), SIMDE_FLOAT32_C(   293.49), SIMDE_FLOAT32_C(    -5.67) },
      { SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 a = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512 b = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512 r = simde_mm512_maskz_scalef_ps(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x16_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_extract_f32x16(i, 2, 0, values);
    simde__m512 b = simde_test_x86_random_extract_f32x16(i, 2, 1, values);
    simde__m512 r = simde_mm512_maskz_scalef_ps(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_scalef_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    14.65) },
      { SIMDE_FLOAT64_C(    73.76),             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -30.10) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -60.62) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -0.00) } },
    #endif
    { { SIMDE_FLOAT64_C(    18.39), SIMDE_FLOAT64_C(   -19.05) },
      { SIMDE_FLOAT64_C(     8.69), SIMDE_FLOAT64_C(     2.38) },
      { SIMDE_FLOAT64_C(  4707.84), SIMDE_FLOAT64_C(   -76.20) } },
    { { SIMDE_FLOAT64_C(   -25.14), SIMDE_FLOAT64_C(    99.57) },
      { SIMDE_FLOAT64_C(    63.92), SIMDE_FLOAT64_C(    15.05) },
      { SIMDE_FLOAT64_C(-231875573006529069056.00), SIMDE_FLOAT64_C(3262709.76) } },
    { { SIMDE_FLOAT64_C(   -26.71), SIMDE_FLOAT64_C(   -61.81) },
      { SIMDE_FLOAT64_C(    53.58), SIMDE_FLOAT64_C(   -85.95) },
      { SIMDE_FLOAT64_C(-240582292094131904.00), SIMDE_FLOAT64_C(    -0.00) } },
    { { SIMDE_FLOAT64_C(    30.91), SIMDE_FLOAT64_C(    80.20) },
      { SIMDE_FLOAT64_C(   -51.60), SIMDE_FLOAT64_C(   -87.81) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(    50.75), SIMDE_FLOAT64_C(   -84.71) },
      { SIMDE_FLOAT64_C(   -31.49), SIMDE_FLOAT64_C(    85.93) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-3277059397745767354566967296.00) } },
    { { SIMDE_FLOAT64_C(   -22.94), SIMDE_FLOAT64_C(     9.42) },
      { SIMDE_FLOAT64_C(    83.85), SIMDE_FLOAT64_C(     4.58) },
      { SIMDE_FLOAT64_C(-221862066415676758511583232.00), SIMDE_FLOAT64_C(   150.72) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_scalef_pd(a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x2_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_extract_f64x2(i, 2, 0, values);
    simde__m128d b = simde_test_x86_random_extract_f64x2(i, 2, 1, values);
    simde__m128d r = simde_mm_scalef_pd(a, b);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_scalef_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT64_C(  -683.93), SIMDE_FLOAT64_C(  -643.14) },
      UINT8_C( 97),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    57.61) },
      { SIMDE_FLOAT64_C(    53.43),             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -643.14) } },
    #endif
    { { SIMDE_FLOAT64_C(  -408.83), SIMDE_FLOAT64_C(   845.11) },
      UINT8_C( 22),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    48.83) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    45.90) },
      { SIMDE_FLOAT64_C(  -408.83), SIMDE_FLOAT64_C(1718052889097666.50) } },
    { { SIMDE_FLOAT64_C(  -949.80), SIMDE_FLOAT64_C(  -857.08) },
      UINT8_C(201),
      { SIMDE_FLOAT64_C(   -70.22), SIMDE_FLOAT64_C(    50.02) },
      { SIMDE_FLOAT64_C(   -51.72), SIMDE_FLOAT64_C(     4.64) },
      { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(  -857.08) } },
    { { SIMDE_FLOAT64_C(  -466.99), SIMDE_FLOAT64_C(   189.32) },
      UINT8_C(190),
      { SIMDE_FLOAT64_C(    49.59), SIMDE_FLOAT64_C(   -87.80) },
      { SIMDE_FLOAT64_C(   -80.31), SIMDE_FLOAT64_C(   -77.12) },
      { SIMDE_FLOAT64_C(  -466.99), SIMDE_FLOAT64_C(    -0.00) } },
    { { SIMDE_FLOAT64_C(  -344.95), SIMDE_FLOAT64_C(   386.18) },
      UINT8_C(156),
      { SIMDE_FLOAT64_C(   -49.61), SIMDE_FLOAT64_C(    73.26) },
      { SIMDE_FLOAT64_C(   -63.07), SIMDE_FLOAT64_C(    81.30) },
      { SIMDE_FLOAT64_C(  -344.95), SIMDE_FLOAT64_C(   386.18) } },
    { { SIMDE_FLOAT64_C(   158.99), SIMDE_FLOAT64_C(   118.79) },
      UINT8_C( 37),
      { SIMDE_FLOAT64_C(    53.46), SIMDE_FLOAT64_C(   -14.67) },
      { SIMDE_FLOAT64_C(    93.50), SIMDE_FLOAT64_C(     4.21) },
      { SIMDE_FLOAT64_C(529442196001571444413106749440.00), SIMDE_FLOAT64_C(   118.79) } },
    { { SIMDE_FLOAT64_C(   -27.96), SIMDE_FLOAT64_C(  -346.62) },
      UINT8_C(189),
      { SIMDE_FLOAT64_C(     0.62), SIMDE_FLOAT64_C(   -37.99) },
      { SIMDE_FLOAT64_C(    -9.86), SIMDE_FLOAT64_C(    77.68) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -346.62) } },
    { { SIMDE_FLOAT64_C(   -93.00), SIMDE_FLOAT64_C(   695.44) },
      UINT8_C(140),
      { SIMDE_FLOAT64_C(    71.43), SIMDE_FLOAT64_C(   -26.01) },
      { SIMDE_FLOAT64_C(   -17.74), SIMDE_FLOAT64_C(    95.49) },
      { SIMDE_FLOAT64_C(   -93.00), SIMDE_FLOAT64_C(   695.44) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d src = simde_mm_loadu_pd(test_vec[i].src);
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_mask_scalef_pd(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x2_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_extract_f64x2(i, 2, 0, values);
    simde__m128d b = simde_test_x86_random_extract_f64x2(i, 2, 1, values);
    simde__m128d r = simde_mm_mask_scalef_pd(src, k, a, b);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_scalef_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT8_C(123),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -40.32) },
      { SIMDE_FLOAT64_C(    61.82),             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
    #endif
    { UINT8_C( 40),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -55.92) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    65.28) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(206),
      { SIMDE_FLOAT64_C(   -20.24), SIMDE_FLOAT64_C(    17.07) },
      { SIMDE_FLOAT64_C(   -75.60), SIMDE_FLOAT64_C(   -35.73) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(202),
      { SIMDE_FLOAT64_C(    55.84), SIMDE_FLOAT64_C(   -70.58) },
      { SIMDE_FLOAT64_C(   -21.43), SIMDE_FLOAT64_C(    44.63) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-1241656491014881.25) } },
    { UINT8_C( 11),
      { SIMDE_FLOAT64_C(   -17.28), SIMDE_FLOAT64_C(    97.50) },
      { SIMDE_FLOAT64_C(   -16.98), SIMDE_FLOAT64_C(    48.23) },
      { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(27443810229288960.00) } },
    { UINT8_C(223),
      { SIMDE_FLOAT64_C(    36.11), SIMDE_FLOAT64_C(   -55.71) },
      { SIMDE_FLOAT64_C(   -35.87), SIMDE_FLOAT64_C(   -52.01) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00) } },
    { UINT8_C(137),
      { SIMDE_FLOAT64_C(   -57.52), SIMDE_FLOAT64_C(    61.33) },
      { SIMDE_FLOAT64_C(    13.33), SIMDE_FLOAT64_C(    26.00) },
      { SIMDE_FLOAT64_C(-471203.84), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(221),
      { SIMDE_FLOAT64_C(   -47.97), SIMDE_FLOAT64_C(   -17.12) },
      { SIMDE_FLOAT64_C(    10.14), SIMDE_FLOAT64_C(   -95.26) },
      { SIMDE_FLOAT64_C(-49121.28), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_maskz_scalef_pd(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x2_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_extract_f64x2(i, 2, 0, values);
    simde__m128d b = simde_test_x86_random_extract_f64x2(i, 2, 1, values);
    simde__m128d r = simde_mm_maskz_scalef_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_scalef_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -98.02),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    14.34) },
      { SIMDE_FLOAT64_C(    22.61),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -40.04) },
      {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     0.00) } },
    #endif
    { { SIMDE_FLOAT64_C(    -4.76), SIMDE_FLOAT64_C(     2.92), SIMDE_FLOAT64_C(    74.43), SIMDE_FLOAT64_C(    19.75) },
      { SIMDE_FLOAT64_C(     1.84), SIMDE_FLOAT64_C(   -74.38), SIMDE_FLOAT64_C(   -33.99), SIMDE_FLOAT64_C(   -68.40) },
      { SIMDE_FLOAT64_C(    -9.52), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(    68.17), SIMDE_FLOAT64_C(   -15.58), SIMDE_FLOAT64_C(    50.42), SIMDE_FLOAT64_C(   -37.05) },
      { SIMDE_FLOAT64_C(   -69.82), SIMDE_FLOAT64_C(   -94.10), SIMDE_FLOAT64_C(    71.05), SIMDE_FLOAT64_C(   -56.51) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(119050859033143759863808.00), SIMDE_FLOAT64_C(    -0.00) } },
    { { SIMDE_FLOAT64_C(   -36.90), SIMDE_FLOAT64_C(    88.15), SIMDE_FLOAT64_C(    42.92), SIMDE_FLOAT64_C(   -12.71) },
      { SIMDE_FLOAT64_C(    79.73), SIMDE_FLOAT64_C(   -61.58), SIMDE_FLOAT64_C(   -58.02), SIMDE_FLOAT64_C(     6.34) },
      { SIMDE_FLOAT64_C(-22304681371889907414335488.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -813.44) } },
    { { SIMDE_FLOAT64_C(   -59.60), SIMDE_FLOAT64_C(   -82.73), SIMDE_FLOAT64_C(   -79.32), SIMDE_FLOAT64_C(    63.02) },
      { SIMDE_FLOAT64_C(    65.75), SIMDE_FLOAT64_C(    91.64), SIMDE_FLOAT64_C(   -77.02), SIMDE_FLOAT64_C(   -39.01) },
      { SIMDE_FLOAT64_C(-2198851893586178605056.00), SIMDE_FLOAT64_C(-204829558900159030136433278976.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(    -5.44), SIMDE_FLOAT64_C(    97.41), SIMDE_FLOAT64_C(    80.74), SIMDE_FLOAT64_C(    96.39) },
      { SIMDE_FLOAT64_C(   -76.97), SIMDE_FLOAT64_C(   -53.25), SIMDE_FLOAT64_C(   -72.00), SIMDE_FLOAT64_C(    91.20) },
      { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(238650080773435610802428051456.00) } },
    { { SIMDE_FLOAT64_C(    31.18), SIMDE_FLOAT64_C(    78.42), SIMDE_FLOAT64_C(   -45.85), SIMDE_FLOAT64_C(    61.36) },
      { SIMDE_FLOAT64_C(    84.31), SIMDE_FLOAT64_C(   -74.80), SIMDE_FLOAT64_C(   -95.16), SIMDE_FLOAT64_C(   -52.59) },
      { SIMDE_FLOAT64_C(603108912889346197179858944.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(   -86.66), SIMDE_FLOAT64_C(    47.76), SIMDE_FLOAT64_C(    34.70), SIMDE_FLOAT64_C(    93.08) },
      { SIMDE_FLOAT64_C(    86.19), SIMDE_FLOAT64_C(    76.68), SIMDE_FLOAT64_C(    -0.58), SIMDE_FLOAT64_C(   -73.41) },
      { SIMDE_FLOAT64_C(-6704992737779440650039590912.00), SIMDE_FLOAT64_C(3608643571549667936174080.00), SIMDE_FLOAT64_C(    17.35), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_scalef_pd(a, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x4_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256d a = simde_test_x86_random_extract_f64x4(i, 2, 0, values);
    simde__m256d b = simde_test_x86_random_extract_f64x4(i, 2, 1, values);
    simde__m256d r = simde_mm256_scalef_pd(a, b);

    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_scalef_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[4];
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT64_C(  -835.99), SIMDE_FLOAT64_C(    39.26), SIMDE_FLOAT64_C(   644.55), SIMDE_FLOAT64_C(   246.88) },
      UINT8_C( 98),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    20.10),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    59.70) },
      { SIMDE_FLOAT64_C(    11.73),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -93.71) },
      { SIMDE_FLOAT64_C(  -835.99),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   644.55), SIMDE_FLOAT64_C(   246.88) } },
    #endif
    { { SIMDE_FLOAT64_C(  -880.30), SIMDE_FLOAT64_C(  -570.31), SIMDE_FLOAT64_C(   584.35), SIMDE_FLOAT64_C(  -378.30) },
      UINT8_C(  6),
      { SIMDE_FLOAT64_C(   -90.01), SIMDE_FLOAT64_C(   -98.57), SIMDE_FLOAT64_C(   -97.32), SIMDE_FLOAT64_C(   -66.98) },
      { SIMDE_FLOAT64_C(   -51.82), SIMDE_FLOAT64_C(   -69.32), SIMDE_FLOAT64_C(   -75.78), SIMDE_FLOAT64_C(    79.36) },
      { SIMDE_FLOAT64_C(  -880.30), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(  -378.30) } },
    { { SIMDE_FLOAT64_C(   345.86), SIMDE_FLOAT64_C(   430.52), SIMDE_FLOAT64_C(   697.90), SIMDE_FLOAT64_C(   -99.07) },
      UINT8_C( 91),
      { SIMDE_FLOAT64_C(   -90.90), SIMDE_FLOAT64_C(   -21.63), SIMDE_FLOAT64_C(    40.71), SIMDE_FLOAT64_C(    93.41) },
      { SIMDE_FLOAT64_C(     3.56), SIMDE_FLOAT64_C(    45.56), SIMDE_FLOAT64_C(   -59.18), SIMDE_FLOAT64_C(    16.91) },
      { SIMDE_FLOAT64_C(  -727.20), SIMDE_FLOAT64_C(-761037968281436.12), SIMDE_FLOAT64_C(   697.90), SIMDE_FLOAT64_C(6121717.76) } },
    { { SIMDE_FLOAT64_C(  -763.22), SIMDE_FLOAT64_C(   863.15), SIMDE_FLOAT64_C(   164.23), SIMDE_FLOAT64_C(   811.29) },
      UINT8_C(249),
      { SIMDE_FLOAT64_C(    -6.68), SIMDE_FLOAT64_C(    75.52), SIMDE_FLOAT64_C(     9.98), SIMDE_FLOAT64_C(   -20.49) },
      { SIMDE_FLOAT64_C(    52.20), SIMDE_FLOAT64_C(   -90.60), SIMDE_FLOAT64_C(     6.09), SIMDE_FLOAT64_C(    46.15) },
      { SIMDE_FLOAT64_C(-30084045510834912.00), SIMDE_FLOAT64_C(   863.15), SIMDE_FLOAT64_C(   164.23), SIMDE_FLOAT64_C(-1441855568200335.25) } },
    { { SIMDE_FLOAT64_C(  -593.66), SIMDE_FLOAT64_C(  -445.14), SIMDE_FLOAT64_C(   631.97), SIMDE_FLOAT64_C(   403.63) },
      UINT8_C( 71),
      { SIMDE_FLOAT64_C(    29.49), SIMDE_FLOAT64_C(    -4.30), SIMDE_FLOAT64_C(     5.85), SIMDE_FLOAT64_C(   -58.77) },
      { SIMDE_FLOAT64_C(     8.29), SIMDE_FLOAT64_C(    26.54), SIMDE_FLOAT64_C(   -52.48), SIMDE_FLOAT64_C(    18.28) },
      { SIMDE_FLOAT64_C(  7549.44), SIMDE_FLOAT64_C(-288568115.20), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   403.63) } },
    { { SIMDE_FLOAT64_C(   778.03), SIMDE_FLOAT64_C(   922.89), SIMDE_FLOAT64_C(  -664.40), SIMDE_FLOAT64_C(   -14.97) },
      UINT8_C(118),
      { SIMDE_FLOAT64_C(    27.97), SIMDE_FLOAT64_C(   -49.80), SIMDE_FLOAT64_C(    51.30), SIMDE_FLOAT64_C(    76.15) },
      { SIMDE_FLOAT64_C(   -19.12), SIMDE_FLOAT64_C(    75.52), SIMDE_FLOAT64_C(    55.51), SIMDE_FLOAT64_C(   -10.02) },
      { SIMDE_FLOAT64_C(   778.03), SIMDE_FLOAT64_C(-1881390806775266545762304.00), SIMDE_FLOAT64_C(1848277287072851456.00), SIMDE_FLOAT64_C(   -14.97) } },
    { { SIMDE_FLOAT64_C(   567.88), SIMDE_FLOAT64_C(   149.04), SIMDE_FLOAT64_C(   -57.09), SIMDE_FLOAT64_C(   212.43) },
      UINT8_C(210),
      { SIMDE_FLOAT64_C(   -46.11), SIMDE_FLOAT64_C(    -3.78), SIMDE_FLOAT64_C(   -16.61), SIMDE_FLOAT64_C(    57.45) },
      { SIMDE_FLOAT64_C(   -58.22), SIMDE_FLOAT64_C(    24.21), SIMDE_FLOAT64_C(   -25.64), SIMDE_FLOAT64_C(    35.10) },
      { SIMDE_FLOAT64_C(   567.88), SIMDE_FLOAT64_C(-63417876.48), SIMDE_FLOAT64_C(   -57.09), SIMDE_FLOAT64_C(   212.43) } },
    { { SIMDE_FLOAT64_C(   247.57), SIMDE_FLOAT64_C(   332.13), SIMDE_FLOAT64_C(  -174.39), SIMDE_FLOAT64_C(  -168.09) },
      UINT8_C( 28),
      { SIMDE_FLOAT64_C(    -0.27), SIMDE_FLOAT64_C(    84.34), SIMDE_FLOAT64_C(   -85.39), SIMDE_FLOAT64_C(   -48.07) },
      { SIMDE_FLOAT64_C(    93.74), SIMDE_FLOAT64_C(    20.70), SIMDE_FLOAT64_C(    98.08), SIMDE_FLOAT64_C(    23.23) },
      { SIMDE_FLOAT64_C(   247.57), SIMDE_FLOAT64_C(   332.13), SIMDE_FLOAT64_C(-27061171188372127328594856771584.00), SIMDE_FLOAT64_C(-403240386.56) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d src = simde_mm256_loadu_pd(test_vec[i].src);
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_mask_scalef_pd(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x4_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256d src = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_extract_f64x4(i, 2, 0, values);
    simde__m256d b = simde_test_x86_random_extract_f64x4(i, 2, 1, values);
    simde__m256d r = simde_mm256_mask_scalef_pd(src, k, a, b);

    simde_test_x86_write_f64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_scalef_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT8_C( 69),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -82.22),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -53.38) },
      { SIMDE_FLOAT64_C(     7.87),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -5.81) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     0.00),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     0.00) } },
    #endif
    { UINT8_C(236),
      { SIMDE_FLOAT64_C(   -12.11), SIMDE_FLOAT64_C(   -48.57), SIMDE_FLOAT64_C(    22.28), SIMDE_FLOAT64_C(    28.52) },
      { SIMDE_FLOAT64_C(     6.91), SIMDE_FLOAT64_C(   -14.52), SIMDE_FLOAT64_C(   -31.11), SIMDE_FLOAT64_C(    46.74) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(2006916583946977.25) } },
    { UINT8_C( 31),
      { SIMDE_FLOAT64_C(   -36.72), SIMDE_FLOAT64_C(   -38.82), SIMDE_FLOAT64_C(    80.30), SIMDE_FLOAT64_C(    61.79) },
      { SIMDE_FLOAT64_C(   -48.46), SIMDE_FLOAT64_C(    37.08), SIMDE_FLOAT64_C(   -23.31), SIMDE_FLOAT64_C(    45.83) },
      { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(-5335380173783.04), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(2174042351368929.25) } },
    { UINT8_C(147),
      { SIMDE_FLOAT64_C(   -41.67), SIMDE_FLOAT64_C(    16.28), SIMDE_FLOAT64_C(   -29.41), SIMDE_FLOAT64_C(    91.54) },
      { SIMDE_FLOAT64_C(    98.84), SIMDE_FLOAT64_C(    53.78), SIMDE_FLOAT64_C(    86.92), SIMDE_FLOAT64_C(   -24.33) },
      { SIMDE_FLOAT64_C(-13205750127877580330523860926464.00), SIMDE_FLOAT64_C(146637203867183360.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 72),
      { SIMDE_FLOAT64_C(    71.56), SIMDE_FLOAT64_C(    25.36), SIMDE_FLOAT64_C(    22.29), SIMDE_FLOAT64_C(   -20.57) },
      { SIMDE_FLOAT64_C(    -3.18), SIMDE_FLOAT64_C(    92.59), SIMDE_FLOAT64_C(    73.62), SIMDE_FLOAT64_C(    84.72) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-397881665751566759476854784.00) } },
    { UINT8_C(232),
      { SIMDE_FLOAT64_C(   -55.98), SIMDE_FLOAT64_C(    -4.10), SIMDE_FLOAT64_C(    13.24), SIMDE_FLOAT64_C(    50.93) },
      { SIMDE_FLOAT64_C(    81.38), SIMDE_FLOAT64_C(    82.13), SIMDE_FLOAT64_C(    -2.33), SIMDE_FLOAT64_C(   -55.34) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(160),
      { SIMDE_FLOAT64_C(   -56.69), SIMDE_FLOAT64_C(   -22.04), SIMDE_FLOAT64_C(   -93.56), SIMDE_FLOAT64_C(    -5.15) },
      { SIMDE_FLOAT64_C(   -84.95), SIMDE_FLOAT64_C(   -16.87), SIMDE_FLOAT64_C(   -59.32), SIMDE_FLOAT64_C(   -26.63) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 29),
      { SIMDE_FLOAT64_C(    99.42), SIMDE_FLOAT64_C(    11.27), SIMDE_FLOAT64_C(   -35.09), SIMDE_FLOAT64_C(    98.26) },
      { SIMDE_FLOAT64_C(   -34.94), SIMDE_FLOAT64_C(   -48.16), SIMDE_FLOAT64_C(   -26.07), SIMDE_FLOAT64_C(   -63.38) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256d a = simde_mm256_loadu_pd(test_vec[i].a);
    simde__m256d b = simde_mm256_loadu_pd(test_vec[i].b);
    simde__m256d r = simde_mm256_maskz_scalef_pd(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x4_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_extract_f64x4(i, 2, 0, values);
    simde__m256d b = simde_test_x86_random_extract_f64x4(i, 2, 1, values);
    simde__m256d r = simde_mm256_maskz_scalef_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_scalef_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     3.52),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    82.72),
        SIMDE_FLOAT64_C(   -70.09), SIMDE_FLOAT64_C(    38.95), SIMDE_FLOAT64_C(   -64.55), SIMDE_FLOAT64_C(    80.50) },
      { SIMDE_FLOAT64_C(    55.63),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    88.21),
        SIMDE_FLOAT64_C(   -89.05), SIMDE_FLOAT64_C(    49.51), SIMDE_FLOAT64_C(    20.06), SIMDE_FLOAT64_C(    16.65) },
      {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(25600600012421663733070168064.00),
        SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(21926900685760104.00), SIMDE_FLOAT64_C(-67685580.80), SIMDE_FLOAT64_C(5275648.00) } },
    #endif
    { { SIMDE_FLOAT64_C(    72.14), SIMDE_FLOAT64_C(   -64.35), SIMDE_FLOAT64_C(   -86.99), SIMDE_FLOAT64_C(    12.78),
        SIMDE_FLOAT64_C(    48.87), SIMDE_FLOAT64_C(    35.58), SIMDE_FLOAT64_C(   -50.15), SIMDE_FLOAT64_C(   -28.04) },
      { SIMDE_FLOAT64_C(   -50.35), SIMDE_FLOAT64_C(    12.93), SIMDE_FLOAT64_C(   -43.72), SIMDE_FLOAT64_C(    45.63),
        SIMDE_FLOAT64_C(    18.72), SIMDE_FLOAT64_C(    92.32), SIMDE_FLOAT64_C(   -91.81), SIMDE_FLOAT64_C(    52.08) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-263577.60), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(449656275295272.94),
        SIMDE_FLOAT64_C(12810977.28), SIMDE_FLOAT64_C(176183626391095312279394058240.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(-126280933551468704.00) } },
    { { SIMDE_FLOAT64_C(    -4.16), SIMDE_FLOAT64_C(   -75.71), SIMDE_FLOAT64_C(    34.79), SIMDE_FLOAT64_C(    25.75),
        SIMDE_FLOAT64_C(    63.24), SIMDE_FLOAT64_C(    70.24), SIMDE_FLOAT64_C(     6.25), SIMDE_FLOAT64_C(    18.87) },
      { SIMDE_FLOAT64_C(    52.58), SIMDE_FLOAT64_C(   -80.99), SIMDE_FLOAT64_C(     7.07), SIMDE_FLOAT64_C(    63.54),
        SIMDE_FLOAT64_C(    68.52), SIMDE_FLOAT64_C(   -72.86), SIMDE_FLOAT64_C(   -19.81), SIMDE_FLOAT64_C(    40.66) },
      { SIMDE_FLOAT64_C(-18734974449861264.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(  4453.12), SIMDE_FLOAT64_C(237501829949010477056.00),
        SIMDE_FLOAT64_C(18665153523542273294336.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(20747784416133.12) } },
    { { SIMDE_FLOAT64_C(   -37.21), SIMDE_FLOAT64_C(    -6.81), SIMDE_FLOAT64_C(   -46.56), SIMDE_FLOAT64_C(   -88.34),
        SIMDE_FLOAT64_C(   -71.23), SIMDE_FLOAT64_C(     3.29), SIMDE_FLOAT64_C(   -16.38), SIMDE_FLOAT64_C(   -21.58) },
      { SIMDE_FLOAT64_C(   -83.78), SIMDE_FLOAT64_C(    39.89), SIMDE_FLOAT64_C(   -75.94), SIMDE_FLOAT64_C(    34.93),
        SIMDE_FLOAT64_C(    32.21), SIMDE_FLOAT64_C(   -67.75), SIMDE_FLOAT64_C(   -12.99), SIMDE_FLOAT64_C(   -71.95) },
      { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(-3743837092577.28), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(-1517669643714.56),
        SIMDE_FLOAT64_C(-305930520494.08), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(    -0.00) } },
    { { SIMDE_FLOAT64_C(   -43.46), SIMDE_FLOAT64_C(   -78.20), SIMDE_FLOAT64_C(    53.80), SIMDE_FLOAT64_C(   -80.23),
        SIMDE_FLOAT64_C(    92.04), SIMDE_FLOAT64_C(   -39.95), SIMDE_FLOAT64_C(    38.64), SIMDE_FLOAT64_C(    44.63) },
      { SIMDE_FLOAT64_C(   -20.94), SIMDE_FLOAT64_C(   -54.29), SIMDE_FLOAT64_C(     8.17), SIMDE_FLOAT64_C(   -52.42),
        SIMDE_FLOAT64_C(   -27.15), SIMDE_FLOAT64_C(    88.35), SIMDE_FLOAT64_C(    88.24), SIMDE_FLOAT64_C(    35.64) },
      { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C( 13772.80), SIMDE_FLOAT64_C(    -0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-12363926142362736375164305408.00), SIMDE_FLOAT64_C(11958500779496773631447400448.00), SIMDE_FLOAT64_C(1533475123363.84) } },
    { { SIMDE_FLOAT64_C(   -18.45), SIMDE_FLOAT64_C(   -58.32), SIMDE_FLOAT64_C(    47.30), SIMDE_FLOAT64_C(    10.32),
        SIMDE_FLOAT64_C(    44.97), SIMDE_FLOAT64_C(   -69.08), SIMDE_FLOAT64_C(    88.74), SIMDE_FLOAT64_C(    61.18) },
      { SIMDE_FLOAT64_C(    70.81), SIMDE_FLOAT64_C(   -87.20), SIMDE_FLOAT64_C(    -3.89), SIMDE_FLOAT64_C(     3.02),
        SIMDE_FLOAT64_C(   -54.95), SIMDE_FLOAT64_C(    83.12), SIMDE_FLOAT64_C(    31.07), SIMDE_FLOAT64_C(     1.58) },
      { SIMDE_FLOAT64_C(-21781915402236237709312.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     2.96), SIMDE_FLOAT64_C(    82.56),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-668100764951828650616946688.00), SIMDE_FLOAT64_C(190567698923.52), SIMDE_FLOAT64_C(   122.36) } },
    { { SIMDE_FLOAT64_C(   -95.08), SIMDE_FLOAT64_C(   -15.13), SIMDE_FLOAT64_C(    21.36), SIMDE_FLOAT64_C(    96.97),
        SIMDE_FLOAT64_C(    44.91), SIMDE_FLOAT64_C(   -40.00), SIMDE_FLOAT64_C(    41.60), SIMDE_FLOAT64_C(   -76.03) },
      { SIMDE_FLOAT64_C(     5.71), SIMDE_FLOAT64_C(   -50.24), SIMDE_FLOAT64_C(   -28.45), SIMDE_FLOAT64_C(    78.56),
        SIMDE_FLOAT64_C(   -61.89), SIMDE_FLOAT64_C(   -40.21), SIMDE_FLOAT64_C(    14.19), SIMDE_FLOAT64_C(    19.66) },
      { SIMDE_FLOAT64_C( -3042.56), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(29307384182007647424217088.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(681574.40), SIMDE_FLOAT64_C(-39861616.64) } },
    { { SIMDE_FLOAT64_C(     1.47), SIMDE_FLOAT64_C(   -38.51), SIMDE_FLOAT64_C(   -70.02), SIMDE_FLOAT64_C(   -53.56),
        SIMDE_FLOAT64_C(    -7.59), SIMDE_FLOAT64_C(   -81.28), SIMDE_FLOAT64_C(   -92.38), SIMDE_FLOAT64_C(   -36.78) },
      { SIMDE_FLOAT64_C(   -68.49), SIMDE_FLOAT64_C(     3.73), SIMDE_FLOAT64_C(    66.24), SIMDE_FLOAT64_C(   -23.44),
        SIMDE_FLOAT64_C(   -13.15), SIMDE_FLOAT64_C(    -2.69), SIMDE_FLOAT64_C(    78.14), SIMDE_FLOAT64_C(    -8.22) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -308.08), SIMDE_FLOAT64_C(-5166564080164570923008.00), SIMDE_FLOAT64_C(    -0.00),
        SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(   -10.16), SIMDE_FLOAT64_C(-27920141803999859415449600.00), SIMDE_FLOAT64_C(    -0.07) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_scalef_pd(a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x8_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_extract_f64x8(i, 2, 0, values);
    simde__m512d b = simde_test_x86_random_extract_f64x8(i, 2, 1, values);
    simde__m512d r = simde_mm512_scalef_pd(a, b);

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_scalef_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT64_C(  -161.86), SIMDE_FLOAT64_C(  -689.84), SIMDE_FLOAT64_C(  -760.83), SIMDE_FLOAT64_C(  -853.23),
        SIMDE_FLOAT64_C(    59.60), SIMDE_FLOAT64_C(  -500.46), SIMDE_FLOAT64_C(  -972.68), SIMDE_FLOAT64_C(   329.52) },
      UINT8_C( 53),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -0.50),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    27.08),
        SIMDE_FLOAT64_C(    59.49), SIMDE_FLOAT64_C(   -69.66), SIMDE_FLOAT64_C(    51.05), SIMDE_FLOAT64_C(   -34.80) },
      { SIMDE_FLOAT64_C(   -19.90),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    18.21),
        SIMDE_FLOAT64_C(   -17.60), SIMDE_FLOAT64_C(    57.95), SIMDE_FLOAT64_C(   -62.13), SIMDE_FLOAT64_C(    83.87) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -689.84),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -853.23),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-10039064001364119552.00), SIMDE_FLOAT64_C(  -972.68), SIMDE_FLOAT64_C(   329.52) } },
    #endif
    { { SIMDE_FLOAT64_C(   466.56), SIMDE_FLOAT64_C(   875.54), SIMDE_FLOAT64_C(  -763.98), SIMDE_FLOAT64_C(   645.69),
        SIMDE_FLOAT64_C(  -868.26), SIMDE_FLOAT64_C(   770.97), SIMDE_FLOAT64_C(  -135.66), SIMDE_FLOAT64_C(  -602.20) },
      UINT8_C(134),
      { SIMDE_FLOAT64_C(   -80.56), SIMDE_FLOAT64_C(   -32.15), SIMDE_FLOAT64_C(   -69.69), SIMDE_FLOAT64_C(    11.85),
        SIMDE_FLOAT64_C(   -13.44), SIMDE_FLOAT64_C(   -62.07), SIMDE_FLOAT64_C(    75.06), SIMDE_FLOAT64_C(    18.08) },
      { SIMDE_FLOAT64_C(    41.66), SIMDE_FLOAT64_C(    41.30), SIMDE_FLOAT64_C(    94.63), SIMDE_FLOAT64_C(   -71.49),
        SIMDE_FLOAT64_C(   -61.39), SIMDE_FLOAT64_C(    72.78), SIMDE_FLOAT64_C(    20.29), SIMDE_FLOAT64_C(   -79.22) },
      { SIMDE_FLOAT64_C(   466.56), SIMDE_FLOAT64_C(-70698597665996.80), SIMDE_FLOAT64_C(-1380352661404770376687523201024.00), SIMDE_FLOAT64_C(   645.69),
        SIMDE_FLOAT64_C(  -868.26), SIMDE_FLOAT64_C(   770.97), SIMDE_FLOAT64_C(  -135.66), SIMDE_FLOAT64_C(     0.00) } },
    { { SIMDE_FLOAT64_C(   172.80), SIMDE_FLOAT64_C(  -845.80), SIMDE_FLOAT64_C(  -987.32), SIMDE_FLOAT64_C(  -965.66),
        SIMDE_FLOAT64_C(  -172.29), SIMDE_FLOAT64_C(   -41.83), SIMDE_FLOAT64_C(   298.33), SIMDE_FLOAT64_C(   572.92) },
      UINT8_C(149),
      { SIMDE_FLOAT64_C(   -27.73), SIMDE_FLOAT64_C(   -90.97), SIMDE_FLOAT64_C(    47.86), SIMDE_FLOAT64_C(   -68.23),
        SIMDE_FLOAT64_C(   -60.63), SIMDE_FLOAT64_C(    -1.09), SIMDE_FLOAT64_C(    -3.03), SIMDE_FLOAT64_C(    19.47) },
      { SIMDE_FLOAT64_C(    21.52), SIMDE_FLOAT64_C(    40.73), SIMDE_FLOAT64_C(   -62.31), SIMDE_FLOAT64_C(   -96.08),
        SIMDE_FLOAT64_C(    -1.32), SIMDE_FLOAT64_C(   -24.44), SIMDE_FLOAT64_C(    87.79), SIMDE_FLOAT64_C(    18.12) },
      { SIMDE_FLOAT64_C(-58154024.96), SIMDE_FLOAT64_C(  -845.80), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -965.66),
        SIMDE_FLOAT64_C(   -15.16), SIMDE_FLOAT64_C(   -41.83), SIMDE_FLOAT64_C(   298.33), SIMDE_FLOAT64_C(5103943.68) } },
    { { SIMDE_FLOAT64_C(    21.90), SIMDE_FLOAT64_C(  -732.90), SIMDE_FLOAT64_C(  -290.17), SIMDE_FLOAT64_C(  -259.18),
        SIMDE_FLOAT64_C(   105.25), SIMDE_FLOAT64_C(    19.99), SIMDE_FLOAT64_C(   -20.01), SIMDE_FLOAT64_C(   252.01) },
      UINT8_C( 47),
      { SIMDE_FLOAT64_C(    43.41), SIMDE_FLOAT64_C(   -81.90), SIMDE_FLOAT64_C(   -70.04), SIMDE_FLOAT64_C(   -70.03),
        SIMDE_FLOAT64_C(   -43.98), SIMDE_FLOAT64_C(   -94.97), SIMDE_FLOAT64_C(    48.05), SIMDE_FLOAT64_C(    97.68) },
      { SIMDE_FLOAT64_C(    46.33), SIMDE_FLOAT64_C(    42.68), SIMDE_FLOAT64_C(   -73.81), SIMDE_FLOAT64_C(    84.94),
        SIMDE_FLOAT64_C(    15.46), SIMDE_FLOAT64_C(    46.48), SIMDE_FLOAT64_C(   -94.29), SIMDE_FLOAT64_C(    87.73) },
      { SIMDE_FLOAT64_C(3054707184752394.00), SIMDE_FLOAT64_C(-360200009259417.62), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(-1354577202361799719665008640.00),
        SIMDE_FLOAT64_C(   105.25), SIMDE_FLOAT64_C(-6682919634552750.00), SIMDE_FLOAT64_C(   -20.01), SIMDE_FLOAT64_C(   252.01) } },
    { { SIMDE_FLOAT64_C(   479.53), SIMDE_FLOAT64_C(   279.33), SIMDE_FLOAT64_C(   409.11), SIMDE_FLOAT64_C(  -981.28),
        SIMDE_FLOAT64_C(  -254.11), SIMDE_FLOAT64_C(   284.65), SIMDE_FLOAT64_C(  -745.27), SIMDE_FLOAT64_C(  -608.42) },
      UINT8_C(  4),
      { SIMDE_FLOAT64_C(    55.51), SIMDE_FLOAT64_C(    53.58), SIMDE_FLOAT64_C(   -80.50), SIMDE_FLOAT64_C(    94.89),
        SIMDE_FLOAT64_C(   -47.51), SIMDE_FLOAT64_C(    16.47), SIMDE_FLOAT64_C(    14.36), SIMDE_FLOAT64_C(    74.01) },
      { SIMDE_FLOAT64_C(   -42.81), SIMDE_FLOAT64_C(    52.05), SIMDE_FLOAT64_C(    77.93), SIMDE_FLOAT64_C(    55.87),
        SIMDE_FLOAT64_C(   -72.39), SIMDE_FLOAT64_C(    65.72), SIMDE_FLOAT64_C(   -26.01), SIMDE_FLOAT64_C(    71.02) },
      { SIMDE_FLOAT64_C(   479.53), SIMDE_FLOAT64_C(   279.33), SIMDE_FLOAT64_C(-12164816059872206070480896.00), SIMDE_FLOAT64_C(  -981.28),
        SIMDE_FLOAT64_C(  -254.11), SIMDE_FLOAT64_C(   284.65), SIMDE_FLOAT64_C(  -745.27), SIMDE_FLOAT64_C(  -608.42) } },
    { { SIMDE_FLOAT64_C(  -974.30), SIMDE_FLOAT64_C(   255.92), SIMDE_FLOAT64_C(   814.19), SIMDE_FLOAT64_C(   729.95),
        SIMDE_FLOAT64_C(  -571.28), SIMDE_FLOAT64_C(   968.38), SIMDE_FLOAT64_C(   742.63), SIMDE_FLOAT64_C(  -536.94) },
      UINT8_C( 19),
      { SIMDE_FLOAT64_C(    83.81), SIMDE_FLOAT64_C(     3.95), SIMDE_FLOAT64_C(   -99.01), SIMDE_FLOAT64_C(   -60.17),
        SIMDE_FLOAT64_C(     8.98), SIMDE_FLOAT64_C(    49.03), SIMDE_FLOAT64_C(   -62.49), SIMDE_FLOAT64_C(   -44.69) },
      { SIMDE_FLOAT64_C(    -8.29), SIMDE_FLOAT64_C(   -36.29), SIMDE_FLOAT64_C(   -59.76), SIMDE_FLOAT64_C(   -92.83),
        SIMDE_FLOAT64_C(   -89.81), SIMDE_FLOAT64_C(   -54.04), SIMDE_FLOAT64_C(    94.90), SIMDE_FLOAT64_C(    65.70) },
      { SIMDE_FLOAT64_C(     0.16), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   814.19), SIMDE_FLOAT64_C(   729.95),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   968.38), SIMDE_FLOAT64_C(   742.63), SIMDE_FLOAT64_C(  -536.94) } },
    { { SIMDE_FLOAT64_C(  -299.20), SIMDE_FLOAT64_C(   761.39), SIMDE_FLOAT64_C(  -630.98), SIMDE_FLOAT64_C(  -293.69),
        SIMDE_FLOAT64_C(  -216.71), SIMDE_FLOAT64_C(  -363.88), SIMDE_FLOAT64_C(   416.14), SIMDE_FLOAT64_C(   524.11) },
      UINT8_C(105),
      { SIMDE_FLOAT64_C(    99.53), SIMDE_FLOAT64_C(   -85.60), SIMDE_FLOAT64_C(    60.58), SIMDE_FLOAT64_C(   -47.97),
        SIMDE_FLOAT64_C(    30.86), SIMDE_FLOAT64_C(   -25.06), SIMDE_FLOAT64_C(   -73.96), SIMDE_FLOAT64_C(    88.06) },
      { SIMDE_FLOAT64_C(   -73.01), SIMDE_FLOAT64_C(   -96.03), SIMDE_FLOAT64_C(    43.92), SIMDE_FLOAT64_C(   -45.40),
        SIMDE_FLOAT64_C(    69.68), SIMDE_FLOAT64_C(   -82.09), SIMDE_FLOAT64_C(   -74.38), SIMDE_FLOAT64_C(    53.49) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   761.39), SIMDE_FLOAT64_C(  -630.98), SIMDE_FLOAT64_C(    -0.00),
        SIMDE_FLOAT64_C(  -216.71), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(   524.11) } },
    { { SIMDE_FLOAT64_C(  -563.87), SIMDE_FLOAT64_C(  -495.90), SIMDE_FLOAT64_C(    -6.62), SIMDE_FLOAT64_C(  -484.29),
        SIMDE_FLOAT64_C(   983.63), SIMDE_FLOAT64_C(  -727.29), SIMDE_FLOAT64_C(   924.82), SIMDE_FLOAT64_C(  -997.65) },
      UINT8_C(190),
      { SIMDE_FLOAT64_C(    21.87), SIMDE_FLOAT64_C(   -73.39), SIMDE_FLOAT64_C(    93.33), SIMDE_FLOAT64_C(   -69.15),
        SIMDE_FLOAT64_C(    75.64), SIMDE_FLOAT64_C(   -69.16), SIMDE_FLOAT64_C(   -13.85), SIMDE_FLOAT64_C(   -32.65) },
      { SIMDE_FLOAT64_C(    -5.45), SIMDE_FLOAT64_C(    26.40), SIMDE_FLOAT64_C(   -25.48), SIMDE_FLOAT64_C(     4.73),
        SIMDE_FLOAT64_C(    72.36), SIMDE_FLOAT64_C(   -30.58), SIMDE_FLOAT64_C(   -29.57), SIMDE_FLOAT64_C(    71.89) },
      { SIMDE_FLOAT64_C(  -563.87), SIMDE_FLOAT64_C(-4925119528.96), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C( -1106.40),
        SIMDE_FLOAT64_C(357199800764259966648320.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(   924.82), SIMDE_FLOAT64_C(-77092632832846954758144.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d src = simde_mm512_loadu_pd(test_vec[i].src);
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_mask_scalef_pd(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x8_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512d src = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_extract_f64x8(i, 2, 0, values);
    simde__m512d b = simde_test_x86_random_extract_f64x8(i, 2, 1, values);
    simde__m512d r = simde_mm512_mask_scalef_pd(src, k, a, b);

    simde_test_x86_write_f64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_scalef_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT8_C( 75),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -74.29),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -37.41),
        SIMDE_FLOAT64_C(   -71.72), SIMDE_FLOAT64_C(   -33.39), SIMDE_FLOAT64_C(   -55.99), SIMDE_FLOAT64_C(   -98.73) },
      { SIMDE_FLOAT64_C(     9.48),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    55.79),
        SIMDE_FLOAT64_C(    20.45), SIMDE_FLOAT64_C(   -54.38), SIMDE_FLOAT64_C(    31.93), SIMDE_FLOAT64_C(    57.36) },
      {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-1347837296479441920.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-120237609451.52), SIMDE_FLOAT64_C(     0.00) } },
    #endif
    { UINT8_C(115),
      { SIMDE_FLOAT64_C(    16.25), SIMDE_FLOAT64_C(   -89.74), SIMDE_FLOAT64_C(   -79.03), SIMDE_FLOAT64_C(   -42.14),
        SIMDE_FLOAT64_C(    62.67), SIMDE_FLOAT64_C(    95.10), SIMDE_FLOAT64_C(     1.47), SIMDE_FLOAT64_C(   -86.92) },
      { SIMDE_FLOAT64_C(    -5.56), SIMDE_FLOAT64_C(    53.05), SIMDE_FLOAT64_C(   -88.56), SIMDE_FLOAT64_C(    21.71),
        SIMDE_FLOAT64_C(    45.53), SIMDE_FLOAT64_C(   -88.32), SIMDE_FLOAT64_C(   -76.43), SIMDE_FLOAT64_C(   -33.52) },
      { SIMDE_FLOAT64_C(     0.25), SIMDE_FLOAT64_C(-808306061120456576.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(2205004598807101.50), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(182),
      { SIMDE_FLOAT64_C(   -62.62), SIMDE_FLOAT64_C(    64.59), SIMDE_FLOAT64_C(    29.06), SIMDE_FLOAT64_C(   -34.34),
        SIMDE_FLOAT64_C(   -68.80), SIMDE_FLOAT64_C(    73.07), SIMDE_FLOAT64_C(   -33.07), SIMDE_FLOAT64_C(    40.68) },
      { SIMDE_FLOAT64_C(   -86.09), SIMDE_FLOAT64_C(   -57.53), SIMDE_FLOAT64_C(    -3.53), SIMDE_FLOAT64_C(    34.36),
        SIMDE_FLOAT64_C(   -11.91), SIMDE_FLOAT64_C(   -71.60), SIMDE_FLOAT64_C(    -8.28), SIMDE_FLOAT64_C(   -95.66) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     1.82), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(    -0.02), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 11),
      { SIMDE_FLOAT64_C(   -61.35), SIMDE_FLOAT64_C(    12.69), SIMDE_FLOAT64_C(   -37.80), SIMDE_FLOAT64_C(   -98.68),
        SIMDE_FLOAT64_C(     7.79), SIMDE_FLOAT64_C(    63.67), SIMDE_FLOAT64_C(   -85.60), SIMDE_FLOAT64_C(   -97.77) },
      { SIMDE_FLOAT64_C(    16.72), SIMDE_FLOAT64_C(   -74.16), SIMDE_FLOAT64_C(    23.94), SIMDE_FLOAT64_C(   -37.75),
        SIMDE_FLOAT64_C(   -62.49), SIMDE_FLOAT64_C(    47.52), SIMDE_FLOAT64_C(    28.72), SIMDE_FLOAT64_C(   -25.10) },
      { SIMDE_FLOAT64_C(-4020633.60), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 86),
      { SIMDE_FLOAT64_C(    12.11), SIMDE_FLOAT64_C(   -42.22), SIMDE_FLOAT64_C(    40.56), SIMDE_FLOAT64_C(    43.31),
        SIMDE_FLOAT64_C(   -69.15), SIMDE_FLOAT64_C(   -92.51), SIMDE_FLOAT64_C(   -16.01), SIMDE_FLOAT64_C(   -55.24) },
      { SIMDE_FLOAT64_C(   -50.04), SIMDE_FLOAT64_C(    80.46), SIMDE_FLOAT64_C(    79.12), SIMDE_FLOAT64_C(    38.05),
        SIMDE_FLOAT64_C(   -91.14), SIMDE_FLOAT64_C(   -29.16), SIMDE_FLOAT64_C(    42.39), SIMDE_FLOAT64_C(   -52.49) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-51040848104129642381705216.00), SIMDE_FLOAT64_C(24517015621784681037430784.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-70412724642775.05), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(100),
      { SIMDE_FLOAT64_C(    83.52), SIMDE_FLOAT64_C(   -95.42), SIMDE_FLOAT64_C(   -51.17), SIMDE_FLOAT64_C(    -8.69),
        SIMDE_FLOAT64_C(    68.26), SIMDE_FLOAT64_C(   -36.77), SIMDE_FLOAT64_C(    -6.45), SIMDE_FLOAT64_C(   -15.03) },
      { SIMDE_FLOAT64_C(   -10.93), SIMDE_FLOAT64_C(   -82.51), SIMDE_FLOAT64_C(    47.22), SIMDE_FLOAT64_C(    26.58),
        SIMDE_FLOAT64_C(    65.01), SIMDE_FLOAT64_C(   -24.06), SIMDE_FLOAT64_C(   -98.52), SIMDE_FLOAT64_C(   -22.88) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-7201537279142134.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(135),
      { SIMDE_FLOAT64_C(    33.72), SIMDE_FLOAT64_C(    42.04), SIMDE_FLOAT64_C(   -79.57), SIMDE_FLOAT64_C(    64.57),
        SIMDE_FLOAT64_C(    49.53), SIMDE_FLOAT64_C(     4.42), SIMDE_FLOAT64_C(   -90.67), SIMDE_FLOAT64_C(    99.49) },
      { SIMDE_FLOAT64_C(   -15.11), SIMDE_FLOAT64_C(    88.45), SIMDE_FLOAT64_C(    37.55), SIMDE_FLOAT64_C(    -6.25),
        SIMDE_FLOAT64_C(   -40.71), SIMDE_FLOAT64_C(   -20.07), SIMDE_FLOAT64_C(    41.26), SIMDE_FLOAT64_C(   -57.19) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(13010749812889346425307004928.00), SIMDE_FLOAT64_C(-10936017527767.04), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(  5),
      { SIMDE_FLOAT64_C(   -15.48), SIMDE_FLOAT64_C(    90.09), SIMDE_FLOAT64_C(    34.13), SIMDE_FLOAT64_C(   -47.23),
        SIMDE_FLOAT64_C(   -46.68), SIMDE_FLOAT64_C(   -72.33), SIMDE_FLOAT64_C(    37.75), SIMDE_FLOAT64_C(    42.39) },
      { SIMDE_FLOAT64_C(   -54.84), SIMDE_FLOAT64_C(   -15.03), SIMDE_FLOAT64_C(   -31.03), SIMDE_FLOAT64_C(   -89.83),
        SIMDE_FLOAT64_C(    60.91), SIMDE_FLOAT64_C(   -29.55), SIMDE_FLOAT64_C(   -12.71), SIMDE_FLOAT64_C(    -5.37) },
      { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d a = simde_mm512_loadu_pd(test_vec[i].a);
    simde__m512d b = simde_mm512_loadu_pd(test_vec[i].b);
    simde__m512d r = simde_mm512_maskz_scalef_pd(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x8_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_extract_f64x8(i, 2, 0, values);
    simde__m512d b = simde_test_x86_random_extract_f64x8(i, 2, 1, values);
    simde__m512d r = simde_mm512_maskz_scalef_pd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_scalef_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     8.46),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -43.86) },
      { SIMDE_FLOAT32_C(     2.77),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    94.26) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     8.46),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -43.86) } },
    #endif
    { { SIMDE_FLOAT32_C(    22.22), SIMDE_FLOAT32_C(    99.63), SIMDE_FLOAT32_C(    63.82), SIMDE_FLOAT32_C(   -81.67) },
      { SIMDE_FLOAT32_C(    56.56), SIMDE_FLOAT32_C(    -8.28), SIMDE_FLOAT32_C(   -19.28), SIMDE_FLOAT32_C(   -43.97) },
      { SIMDE_FLOAT32_C(1601119690044735488.00), SIMDE_FLOAT32_C(    99.63), SIMDE_FLOAT32_C(    63.82), SIMDE_FLOAT32_C(   -81.67) } },
    { { SIMDE_FLOAT32_C(   -70.33), SIMDE_FLOAT32_C(    37.05), SIMDE_FLOAT32_C(   -71.07), SIMDE_FLOAT32_C(    34.14) },
      { SIMDE_FLOAT32_C(   -79.13), SIMDE_FLOAT32_C(    49.31), SIMDE_FLOAT32_C(    -6.87), SIMDE_FLOAT32_C(    71.23) },
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    37.05), SIMDE_FLOAT32_C(   -71.07), SIMDE_FLOAT32_C(    34.14) } },
    { { SIMDE_FLOAT32_C(    29.98), SIMDE_FLOAT32_C(    69.93), SIMDE_FLOAT32_C(   -39.05), SIMDE_FLOAT32_C(   -77.82) },
      { SIMDE_FLOAT32_C(   -34.23), SIMDE_FLOAT32_C(   -95.61), SIMDE_FLOAT32_C(   -20.06), SIMDE_FLOAT32_C(    75.82) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    69.93), SIMDE_FLOAT32_C(   -39.05), SIMDE_FLOAT32_C(   -77.82) } },
    { { SIMDE_FLOAT32_C(    12.85), SIMDE_FLOAT32_C(    72.11), SIMDE_FLOAT32_C(   -68.04), SIMDE_FLOAT32_C(   -84.38) },
      { SIMDE_FLOAT32_C(    93.74), SIMDE_FLOAT32_C(   -93.74), SIMDE_FLOAT32_C(   -90.12), SIMDE_FLOAT32_C(    15.95) },
      { SIMDE_FLOAT32_C(127260239816430278555346141184.00), SIMDE_FLOAT32_C(    72.11), SIMDE_FLOAT32_C(   -68.04), SIMDE_FLOAT32_C(   -84.38) } },
    { { SIMDE_FLOAT32_C(   -94.12), SIMDE_FLOAT32_C(    73.70), SIMDE_FLOAT32_C(    34.29), SIMDE_FLOAT32_C(    62.45) },
      { SIMDE_FLOAT32_C(   -34.57), SIMDE_FLOAT32_C(   -85.00), SIMDE_FLOAT32_C(   -81.52), SIMDE_FLOAT32_C(    -4.90) },
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    73.70), SIMDE_FLOAT32_C(    34.29), SIMDE_FLOAT32_C(    62.45) } },
    { { SIMDE_FLOAT32_C(    52.06), SIMDE_FLOAT32_C(   -52.60), SIMDE_FLOAT32_C(   -70.76), SIMDE_FLOAT32_C(    72.93) },
      { SIMDE_FLOAT32_C(    96.71), SIMDE_FLOAT32_C(    22.38), SIMDE_FLOAT32_C(    44.16), SIMDE_FLOAT32_C(    26.69) },
      { SIMDE_FLOAT32_C(4124618249295925180436523778048.00), SIMDE_FLOAT32_C(   -52.60), SIMDE_FLOAT32_C(   -70.76), SIMDE_FLOAT32_C(    72.93) } },
    { { SIMDE_FLOAT32_C(    -7.69), SIMDE_FLOAT32_C(   -94.90), SIMDE_FLOAT32_C(    48.88), SIMDE_FLOAT32_C(    58.08) },
      { SIMDE_FLOAT32_C(   -90.51), SIMDE_FLOAT32_C(   -71.19), SIMDE_FLOAT32_C(    33.90), SIMDE_FLOAT32_C(    22.34) },
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   -94.90), SIMDE_FLOAT32_C(    48.88), SIMDE_FLOAT32_C(    58.08) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_scalef_ss(a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128 r = simde_mm_scalef_ss(a, b);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_scalef_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(   321.56), SIMDE_FLOAT32_C(   103.07), SIMDE_FLOAT32_C(   870.41), SIMDE_FLOAT32_C(   353.61) },
      UINT8_C( 68),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    14.74),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -72.92) },
      { SIMDE_FLOAT32_C(    42.33),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -50.64) },
      { SIMDE_FLOAT32_C(   321.56), SIMDE_FLOAT32_C(    14.74),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -72.92) } },
    #endif
    { { SIMDE_FLOAT32_C(   573.63), SIMDE_FLOAT32_C(  -621.46), SIMDE_FLOAT32_C(  -603.81), SIMDE_FLOAT32_C(  -953.39) },
      UINT8_C(119),
      { SIMDE_FLOAT32_C(    -0.71), SIMDE_FLOAT32_C(    -1.98), SIMDE_FLOAT32_C(   -23.02), SIMDE_FLOAT32_C(    52.28) },
      { SIMDE_FLOAT32_C(    95.17), SIMDE_FLOAT32_C(   -63.55), SIMDE_FLOAT32_C(    71.25), SIMDE_FLOAT32_C(    69.36) },
      { SIMDE_FLOAT32_C(-28125996842537872929171963904.00), SIMDE_FLOAT32_C(    -1.98), SIMDE_FLOAT32_C(   -23.02), SIMDE_FLOAT32_C(    52.28) } },
    { { SIMDE_FLOAT32_C(   484.51), SIMDE_FLOAT32_C(  -115.93), SIMDE_FLOAT32_C(   186.45), SIMDE_FLOAT32_C(  -733.62) },
      UINT8_C( 47),
      { SIMDE_FLOAT32_C(    64.20), SIMDE_FLOAT32_C(   -96.12), SIMDE_FLOAT32_C(   -96.39), SIMDE_FLOAT32_C(   -17.49) },
      { SIMDE_FLOAT32_C(   -36.36), SIMDE_FLOAT32_C(   -78.88), SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(    32.66) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -96.12), SIMDE_FLOAT32_C(   -96.39), SIMDE_FLOAT32_C(   -17.49) } },
    { { SIMDE_FLOAT32_C(   485.42), SIMDE_FLOAT32_C(    84.35), SIMDE_FLOAT32_C(  -331.91), SIMDE_FLOAT32_C(  -579.17) },
      UINT8_C(110),
      { SIMDE_FLOAT32_C(    35.09), SIMDE_FLOAT32_C(   -20.10), SIMDE_FLOAT32_C(    97.37), SIMDE_FLOAT32_C(   -96.10) },
      { SIMDE_FLOAT32_C(   -27.26), SIMDE_FLOAT32_C(   -36.11), SIMDE_FLOAT32_C(    -8.13), SIMDE_FLOAT32_C(   -49.72) },
      { SIMDE_FLOAT32_C(   485.42), SIMDE_FLOAT32_C(   -20.10), SIMDE_FLOAT32_C(    97.37), SIMDE_FLOAT32_C(   -96.10) } },
    { { SIMDE_FLOAT32_C(   -31.73), SIMDE_FLOAT32_C(  -317.18), SIMDE_FLOAT32_C(  -506.44), SIMDE_FLOAT32_C(  -932.52) },
      UINT8_C( 58),
      { SIMDE_FLOAT32_C(    78.63), SIMDE_FLOAT32_C(    98.37), SIMDE_FLOAT32_C(   -22.64), SIMDE_FLOAT32_C(    20.96) },
      { SIMDE_FLOAT32_C(   -96.80), SIMDE_FLOAT32_C(   -84.35), SIMDE_FLOAT32_C(    70.32), SIMDE_FLOAT32_C(     2.49) },
      { SIMDE_FLOAT32_C(   -31.73), SIMDE_FLOAT32_C(    98.37), SIMDE_FLOAT32_C(   -22.64), SIMDE_FLOAT32_C(    20.96) } },
    { { SIMDE_FLOAT32_C(   -87.31), SIMDE_FLOAT32_C(   894.08), SIMDE_FLOAT32_C(   793.10), SIMDE_FLOAT32_C(  -749.47) },
      UINT8_C( 58),
      { SIMDE_FLOAT32_C(    13.66), SIMDE_FLOAT32_C(   -52.70), SIMDE_FLOAT32_C(   -45.23), SIMDE_FLOAT32_C(     8.83) },
      { SIMDE_FLOAT32_C(   -16.25), SIMDE_FLOAT32_C(   -73.98), SIMDE_FLOAT32_C(   -21.81), SIMDE_FLOAT32_C(   -52.06) },
      { SIMDE_FLOAT32_C(   -87.31), SIMDE_FLOAT32_C(   -52.70), SIMDE_FLOAT32_C(   -45.23), SIMDE_FLOAT32_C(     8.83) } },
    { { SIMDE_FLOAT32_C(  -546.05), SIMDE_FLOAT32_C(   572.09), SIMDE_FLOAT32_C(   326.61), SIMDE_FLOAT32_C(  -675.63) },
      UINT8_C( 85),
      { SIMDE_FLOAT32_C(   -70.10), SIMDE_FLOAT32_C(   -18.20), SIMDE_FLOAT32_C(    30.46), SIMDE_FLOAT32_C(    -6.46) },
      { SIMDE_FLOAT32_C(     2.91), SIMDE_FLOAT32_C(   -69.98), SIMDE_FLOAT32_C(   -73.80), SIMDE_FLOAT32_C(   -61.99) },
      { SIMDE_FLOAT32_C(  -280.40), SIMDE_FLOAT32_C(   -18.20), SIMDE_FLOAT32_C(    30.46), SIMDE_FLOAT32_C(    -6.46) } },
    { { SIMDE_FLOAT32_C(  -413.85), SIMDE_FLOAT32_C(   897.99), SIMDE_FLOAT32_C(   304.24), SIMDE_FLOAT32_C(   -17.66) },
      UINT8_C( 74),
      { SIMDE_FLOAT32_C(     9.92), SIMDE_FLOAT32_C(   -76.43), SIMDE_FLOAT32_C(   -58.09), SIMDE_FLOAT32_C(    82.66) },
      { SIMDE_FLOAT32_C(   -12.54), SIMDE_FLOAT32_C(    33.78), SIMDE_FLOAT32_C(   -67.05), SIMDE_FLOAT32_C(   -33.92) },
      { SIMDE_FLOAT32_C(  -413.85), SIMDE_FLOAT32_C(   -76.43), SIMDE_FLOAT32_C(   -58.09), SIMDE_FLOAT32_C(    82.66) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 src = simde_mm_loadu_ps(test_vec[i].src);
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_mask_scalef_ss(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128 r = simde_mm_mask_scalef_ss(src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_scalef_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT8_C( 91),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -13.69),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    92.32) },
      { SIMDE_FLOAT32_C(    -7.87),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    40.59) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -13.69),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    92.32) } },
  #endif
    { UINT8_C(186),
      { SIMDE_FLOAT32_C(    67.39), SIMDE_FLOAT32_C(   -52.02), SIMDE_FLOAT32_C(    54.28), SIMDE_FLOAT32_C(    29.68) },
      { SIMDE_FLOAT32_C(   -66.62), SIMDE_FLOAT32_C(    66.41), SIMDE_FLOAT32_C(    55.44), SIMDE_FLOAT32_C(   -26.62) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -52.02), SIMDE_FLOAT32_C(    54.28), SIMDE_FLOAT32_C(    29.68) } },
    { UINT8_C(219),
      { SIMDE_FLOAT32_C(   -81.80), SIMDE_FLOAT32_C(    26.08), SIMDE_FLOAT32_C(    64.57), SIMDE_FLOAT32_C(   -95.69) },
      { SIMDE_FLOAT32_C(    75.38), SIMDE_FLOAT32_C(   -99.29), SIMDE_FLOAT32_C(    88.91), SIMDE_FLOAT32_C(   -94.01) },
      { SIMDE_FLOAT32_C(-3090316741682046288527360.00), SIMDE_FLOAT32_C(    26.08), SIMDE_FLOAT32_C(    64.57), SIMDE_FLOAT32_C(   -95.69) } },
    { UINT8_C(121),
      { SIMDE_FLOAT32_C(   -17.89), SIMDE_FLOAT32_C(   -96.36), SIMDE_FLOAT32_C(    42.61), SIMDE_FLOAT32_C(   -46.05) },
      { SIMDE_FLOAT32_C(   -69.23), SIMDE_FLOAT32_C(    42.52), SIMDE_FLOAT32_C(   -33.23), SIMDE_FLOAT32_C(    79.27) },
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   -96.36), SIMDE_FLOAT32_C(    42.61), SIMDE_FLOAT32_C(   -46.05) } },
    { UINT8_C(188),
      { SIMDE_FLOAT32_C(   -71.17), SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(    71.59), SIMDE_FLOAT32_C(    20.96) },
      { SIMDE_FLOAT32_C(    50.12), SIMDE_FLOAT32_C(    64.72), SIMDE_FLOAT32_C(   -38.45), SIMDE_FLOAT32_C(    17.51) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(    71.59), SIMDE_FLOAT32_C(    20.96) } },
    { UINT8_C( 40),
      { SIMDE_FLOAT32_C(   -87.30), SIMDE_FLOAT32_C(   -84.17), SIMDE_FLOAT32_C(   -52.81), SIMDE_FLOAT32_C(   -53.92) },
      { SIMDE_FLOAT32_C(    82.24), SIMDE_FLOAT32_C(   -97.37), SIMDE_FLOAT32_C(    19.46), SIMDE_FLOAT32_C(   -99.56) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -84.17), SIMDE_FLOAT32_C(   -52.81), SIMDE_FLOAT32_C(   -53.92) } },
    { UINT8_C(121),
      { SIMDE_FLOAT32_C(    28.72), SIMDE_FLOAT32_C(   -15.97), SIMDE_FLOAT32_C(   -95.25), SIMDE_FLOAT32_C(     4.09) },
      { SIMDE_FLOAT32_C(   -15.26), SIMDE_FLOAT32_C(    93.67), SIMDE_FLOAT32_C(    10.09), SIMDE_FLOAT32_C(    66.85) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -15.97), SIMDE_FLOAT32_C(   -95.25), SIMDE_FLOAT32_C(     4.09) } },
    { UINT8_C(159),
      { SIMDE_FLOAT32_C(    97.31), SIMDE_FLOAT32_C(   -47.31), SIMDE_FLOAT32_C(   -79.20), SIMDE_FLOAT32_C(   -71.92) },
      { SIMDE_FLOAT32_C(    95.22), SIMDE_FLOAT32_C(   -12.43), SIMDE_FLOAT32_C(   -92.66), SIMDE_FLOAT32_C(   -75.95) },
      { SIMDE_FLOAT32_C(3854846150417465776443546927104.00), SIMDE_FLOAT32_C(   -47.31), SIMDE_FLOAT32_C(   -79.20), SIMDE_FLOAT32_C(   -71.92) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 b = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128 r = simde_mm_maskz_scalef_ss(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -100.0f, 100.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128 r = simde_mm_maskz_scalef_ss(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_scalef_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -7.28) },
      { SIMDE_FLOAT64_C(    15.70),             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -7.28) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -32.67) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -36.49) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -32.67) } },
  #endif
    { { SIMDE_FLOAT64_C(    74.68), SIMDE_FLOAT64_C(    88.10) },
      { SIMDE_FLOAT64_C(    15.04), SIMDE_FLOAT64_C(    11.85) },
      { SIMDE_FLOAT64_C(2447114.24), SIMDE_FLOAT64_C(    88.10) } },
    { { SIMDE_FLOAT64_C(   -68.62), SIMDE_FLOAT64_C(    24.41) },
      { SIMDE_FLOAT64_C(    76.59), SIMDE_FLOAT64_C(    61.07) },
      { SIMDE_FLOAT64_C(-5184780608872241216618496.00), SIMDE_FLOAT64_C(    24.41) } },
    { { SIMDE_FLOAT64_C(   -35.11), SIMDE_FLOAT64_C(    50.04) },
      { SIMDE_FLOAT64_C(    67.17), SIMDE_FLOAT64_C(   -63.07) },
      { SIMDE_FLOAT64_C(-5181321475423538774016.00), SIMDE_FLOAT64_C(    50.04) } },
    { { SIMDE_FLOAT64_C(    39.02), SIMDE_FLOAT64_C(   -47.15) },
      { SIMDE_FLOAT64_C(    76.34), SIMDE_FLOAT64_C(     7.26) },
      { SIMDE_FLOAT64_C(2948267842585177136037888.00), SIMDE_FLOAT64_C(   -47.15) } },
    { { SIMDE_FLOAT64_C(    27.11), SIMDE_FLOAT64_C(    65.60) },
      { SIMDE_FLOAT64_C(    84.64), SIMDE_FLOAT64_C(    93.98) },
      { SIMDE_FLOAT64_C(524383663516041539825434624.00), SIMDE_FLOAT64_C(    65.60) } },
    { { SIMDE_FLOAT64_C(    79.86), SIMDE_FLOAT64_C(    22.49) },
      { SIMDE_FLOAT64_C(   -72.03), SIMDE_FLOAT64_C(   -51.51) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    22.49) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_scalef_sd(a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x2_full(8, 2, values, -100.0, 100.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_extract_f64x2(i, 2, 0, values);
    simde__m128d b = simde_test_x86_random_extract_f64x2(i, 2, 1, values);
    simde__m128d r = simde_mm_scalef_sd(a, b);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_scalef_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT64_C(  -756.00), SIMDE_FLOAT64_C(   511.84) },
      UINT8_C( 43),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    43.68) },
      { SIMDE_FLOAT64_C(    61.65),             SIMDE_MATH_NAN },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    43.68) } },
  #endif
    { { SIMDE_FLOAT64_C(  -645.93), SIMDE_FLOAT64_C(  -177.17) },
      UINT8_C( 56),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    31.10) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    85.68) },
      { SIMDE_FLOAT64_C(  -645.93), SIMDE_FLOAT64_C(    31.10) } },
    { { SIMDE_FLOAT64_C(  -789.10), SIMDE_FLOAT64_C(  -985.21) },
      UINT8_C(154),
      { SIMDE_FLOAT64_C(    19.20), SIMDE_FLOAT64_C(    93.02) },
      { SIMDE_FLOAT64_C(    -2.47), SIMDE_FLOAT64_C(    50.57) },
      { SIMDE_FLOAT64_C(  -789.10), SIMDE_FLOAT64_C(    93.02) } },
    { { SIMDE_FLOAT64_C(   186.22), SIMDE_FLOAT64_C(   520.54) },
      UINT8_C(150),
      { SIMDE_FLOAT64_C(    17.42), SIMDE_FLOAT64_C(   -25.88) },
      { SIMDE_FLOAT64_C(    11.64), SIMDE_FLOAT64_C(    82.31) },
      { SIMDE_FLOAT64_C(   186.22), SIMDE_FLOAT64_C(   -25.88) } },
    { { SIMDE_FLOAT64_C(   927.41), SIMDE_FLOAT64_C(  -363.02) },
      UINT8_C(111),
      { SIMDE_FLOAT64_C(   -75.84), SIMDE_FLOAT64_C(   -21.19) },
      { SIMDE_FLOAT64_C(   -80.76), SIMDE_FLOAT64_C(    63.18) },
      { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(   -21.19) } },
    { { SIMDE_FLOAT64_C(  -830.99), SIMDE_FLOAT64_C(   425.11) },
      UINT8_C(181),
      { SIMDE_FLOAT64_C(    31.66), SIMDE_FLOAT64_C(    95.59) },
      { SIMDE_FLOAT64_C(   -29.56), SIMDE_FLOAT64_C(   -41.23) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    95.59) } },
    { { SIMDE_FLOAT64_C(   800.81), SIMDE_FLOAT64_C(  -258.28) },
      UINT8_C(152),
      { SIMDE_FLOAT64_C(    61.19), SIMDE_FLOAT64_C(   -44.92) },
      { SIMDE_FLOAT64_C(   -47.25), SIMDE_FLOAT64_C(    41.05) },
      { SIMDE_FLOAT64_C(   800.81), SIMDE_FLOAT64_C(   -44.92) } },
    { { SIMDE_FLOAT64_C(  -494.75), SIMDE_FLOAT64_C(   329.42) },
      UINT8_C( 55),
      { SIMDE_FLOAT64_C(    77.57), SIMDE_FLOAT64_C(   -19.28) },
      { SIMDE_FLOAT64_C(    89.53), SIMDE_FLOAT64_C(    92.79) },
      { SIMDE_FLOAT64_C(48013504423683469739837882368.00), SIMDE_FLOAT64_C(   -19.28) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d src = simde_mm_loadu_pd(test_vec[i].src);
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_mask_scalef_sd(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x2_full(8, 2, values, -100.0, 100.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_extract_f64x2(i, 2, 0, values);
    simde__m128d b = simde_test_x86_random_extract_f64x2(i, 2, 1, values);
    simde__m128d r = simde_mm_mask_scalef_sd(src, k, a, b);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_scalef_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C( 22),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    85.69) },
      { SIMDE_FLOAT64_C(    -4.94),             SIMDE_MATH_NAN },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    85.69) } },
    { UINT8_C(108),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -15.41) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -9.18) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -15.41) } },
    { UINT8_C( 87),
      { SIMDE_FLOAT64_C(   -64.22), SIMDE_FLOAT64_C(   -16.77) },
      { SIMDE_FLOAT64_C(    26.22), SIMDE_FLOAT64_C(    18.06) },
      { SIMDE_FLOAT64_C(-4309731246.08), SIMDE_FLOAT64_C(   -16.77) } },
    { UINT8_C( 35),
      { SIMDE_FLOAT64_C(    68.46), SIMDE_FLOAT64_C(    47.31) },
      { SIMDE_FLOAT64_C(    19.54), SIMDE_FLOAT64_C(   -53.28) },
      { SIMDE_FLOAT64_C(35892756.48), SIMDE_FLOAT64_C(    47.31) } },
    { UINT8_C(199),
      { SIMDE_FLOAT64_C(   -34.06), SIMDE_FLOAT64_C(   -28.41) },
      { SIMDE_FLOAT64_C(   -57.61), SIMDE_FLOAT64_C(   -41.32) },
      { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(   -28.41) } },
    { UINT8_C(204),
      { SIMDE_FLOAT64_C(    35.29), SIMDE_FLOAT64_C(   -79.62) },
      { SIMDE_FLOAT64_C(   -24.42), SIMDE_FLOAT64_C(   -22.20) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -79.62) } },
    { UINT8_C(246),
      { SIMDE_FLOAT64_C(   -82.38), SIMDE_FLOAT64_C(   -44.34) },
      { SIMDE_FLOAT64_C(    51.97), SIMDE_FLOAT64_C(   -89.56) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -44.34) } },
    { UINT8_C( 76),
      { SIMDE_FLOAT64_C(     6.18), SIMDE_FLOAT64_C(   -15.08) },
      { SIMDE_FLOAT64_C(    64.45), SIMDE_FLOAT64_C(   -88.21) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -15.08) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128d a = simde_mm_loadu_pd(test_vec[i].a);
    simde__m128d b = simde_mm_loadu_pd(test_vec[i].b);
    simde__m128d r = simde_mm_maskz_scalef_sd(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x2_full(8, 2, values, -100.0, 100.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_extract_f64x2(i, 2, 0, values);
    simde__m128d b = simde_test_x86_random_extract_f64x2(i, 2, 1, values);
    simde__m128d r = simde_mm_maskz_scalef_sd(k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_scalef_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_scalef_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_scalef_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_scalef_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_scalef_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_scalef_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_scalef_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_scalef_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_scalef_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_scalef_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_scalef_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_scalef_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_scalef_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_scalef_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_scalef_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_scalef_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_scalef_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_scalef_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_scalef_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_scalef_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_scalef_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_scalef_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_scalef_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_scalef_sd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
