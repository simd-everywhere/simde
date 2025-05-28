#define SIMDE_TEST_X86_AVX512_INSN dpbf16

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/dpbf16.h>

static int
test_simde_mm_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(     0.93), SIMDE_FLOAT32_C(   -30.68), SIMDE_FLOAT32_C(     7.59), SIMDE_FLOAT32_C(     4.46) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -27.99),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    45.72) },
      { SIMDE_FLOAT32_C(    -2.47),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.29) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF } },
    #endif
    { { SIMDE_FLOAT32_C(    44.06), SIMDE_FLOAT32_C(    39.39), SIMDE_FLOAT32_C(   -16.35), SIMDE_FLOAT32_C(   -41.96) },
      { SIMDE_FLOAT32_C(    25.67), SIMDE_FLOAT32_C(   -10.76), SIMDE_FLOAT32_C(   -35.31), SIMDE_FLOAT32_C(   -34.29) },
      { SIMDE_FLOAT32_C(    24.99), SIMDE_FLOAT32_C(   -33.35), SIMDE_FLOAT32_C(   -42.40), SIMDE_FLOAT32_C(    38.29) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(7416054272.00), SIMDE_FLOAT32_C(  1472.96), SIMDE_FLOAT32_C( -1352.02) } },
    { { SIMDE_FLOAT32_C(   -14.13), SIMDE_FLOAT32_C(   -21.45), SIMDE_FLOAT32_C(    47.00), SIMDE_FLOAT32_C(    49.00) },
      { SIMDE_FLOAT32_C(    49.48), SIMDE_FLOAT32_C(   -43.57), SIMDE_FLOAT32_C(    -3.78), SIMDE_FLOAT32_C(    46.59) },
      { SIMDE_FLOAT32_C(     5.84), SIMDE_FLOAT32_C(   -44.27), SIMDE_FLOAT32_C(    -9.99), SIMDE_FLOAT32_C(    26.51) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  1903.43),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  1281.25) } },
    { { SIMDE_FLOAT32_C(   -18.95), SIMDE_FLOAT32_C(    24.25), SIMDE_FLOAT32_C(    11.61), SIMDE_FLOAT32_C(   -10.02) },
      { SIMDE_FLOAT32_C(    36.90), SIMDE_FLOAT32_C(   -27.07), SIMDE_FLOAT32_C(    38.86), SIMDE_FLOAT32_C(   -40.80) },
      { SIMDE_FLOAT32_C(    18.20), SIMDE_FLOAT32_C(   -38.04), SIMDE_FLOAT32_C(   -18.22), SIMDE_FLOAT32_C(   -33.36) },
      { SIMDE_FLOAT32_C(   647.14), SIMDE_FLOAT32_C(  1050.25), SIMDE_FLOAT32_C(-29032169801320738206934261301248.00), SIMDE_FLOAT32_C(16922581844619299913728.00) } },
    { { SIMDE_FLOAT32_C(    47.73), SIMDE_FLOAT32_C(   -29.20), SIMDE_FLOAT32_C(   -45.25), SIMDE_FLOAT32_C(   -23.06) },
      { SIMDE_FLOAT32_C(   -16.02), SIMDE_FLOAT32_C(    43.85), SIMDE_FLOAT32_C(   -37.64), SIMDE_FLOAT32_C(    31.51) },
      { SIMDE_FLOAT32_C(   -46.48), SIMDE_FLOAT32_C(    24.74), SIMDE_FLOAT32_C(   -18.20), SIMDE_FLOAT32_C(    29.19) },
      { SIMDE_FLOAT32_C(-8782671249408.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   634.44), SIMDE_FLOAT32_C(   894.38) } },
    { { SIMDE_FLOAT32_C(   -30.00), SIMDE_FLOAT32_C(    -3.97), SIMDE_FLOAT32_C(    -6.96), SIMDE_FLOAT32_C(    -7.87) },
      { SIMDE_FLOAT32_C(   -36.02), SIMDE_FLOAT32_C(    -3.52), SIMDE_FLOAT32_C(    44.90), SIMDE_FLOAT32_C(    38.96) },
      { SIMDE_FLOAT32_C(    13.13), SIMDE_FLOAT32_C(   -47.50), SIMDE_FLOAT32_C(    27.25), SIMDE_FLOAT32_C(    12.61) },
      { SIMDE_FLOAT32_C(  -502.50), SIMDE_FLOAT32_C(   163.02), SIMDE_FLOAT32_C(  1212.48), SIMDE_FLOAT32_C(10848881231265792.00) } },
    { { SIMDE_FLOAT32_C(    26.18), SIMDE_FLOAT32_C(    18.34), SIMDE_FLOAT32_C(   -17.54), SIMDE_FLOAT32_C(   -31.71) },
      { SIMDE_FLOAT32_C(   -41.07), SIMDE_FLOAT32_C(   -26.52), SIMDE_FLOAT32_C(     9.19), SIMDE_FLOAT32_C(    14.77) },
      { SIMDE_FLOAT32_C(   -20.79), SIMDE_FLOAT32_C(    49.20), SIMDE_FLOAT32_C(    -8.72), SIMDE_FLOAT32_C(   -33.90) },
      { SIMDE_FLOAT32_C(11287586370748416.00), SIMDE_FLOAT32_C( -1280.16), SIMDE_FLOAT32_C(   -97.36), SIMDE_FLOAT32_C(  -529.52) } },
    { { SIMDE_FLOAT32_C(   -24.57), SIMDE_FLOAT32_C(   -10.57), SIMDE_FLOAT32_C(    44.37), SIMDE_FLOAT32_C(    26.36) },
      { SIMDE_FLOAT32_C(   -27.87), SIMDE_FLOAT32_C(   -19.86), SIMDE_FLOAT32_C(   -24.70), SIMDE_FLOAT32_C(    40.33) },
      { SIMDE_FLOAT32_C(    -7.89), SIMDE_FLOAT32_C(     7.09), SIMDE_FLOAT32_C(   -43.03), SIMDE_FLOAT32_C(    26.08) },
      {     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  1103.24), SIMDE_FLOAT32_C(  1072.86) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 tmp, src, r;
    simde__m128bh a;
    simde__m128bh b;

    src = simde_mm_loadu_ps(test_vec[i].src);

    tmp = simde_mm_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm_dpbf16_ps(src, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m128bh a = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 0, values));
    simde__m128bh b = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 1, values));
    simde__m128 r = simde_mm_dpbf16_ps(src, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(    35.52), SIMDE_FLOAT32_C(   -15.16), SIMDE_FLOAT32_C(    12.96), SIMDE_FLOAT32_C(   -37.51) },
      UINT8_C( 28),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    37.95),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -46.79) },
      { SIMDE_FLOAT32_C(    12.78),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -34.41) },
      { SIMDE_FLOAT32_C(    35.52), SIMDE_FLOAT32_C(   -15.16),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  1563.68) } },
    #endif
    { { SIMDE_FLOAT32_C(    19.58), SIMDE_FLOAT32_C(    34.74), SIMDE_FLOAT32_C(    11.92), SIMDE_FLOAT32_C(   -27.97) },
      UINT8_C( 43),
      { SIMDE_FLOAT32_C(    -4.73), SIMDE_FLOAT32_C(   -44.27), SIMDE_FLOAT32_C(    -4.16), SIMDE_FLOAT32_C(     5.47) },
      { SIMDE_FLOAT32_C(    12.69), SIMDE_FLOAT32_C(    46.62), SIMDE_FLOAT32_C(    24.70), SIMDE_FLOAT32_C(   -22.72) },
      { SIMDE_FLOAT32_C(   -40.29), SIMDE_FLOAT32_C(7402289152.00), SIMDE_FLOAT32_C(    11.92), SIMDE_FLOAT32_C(  -151.70) } },
    { { SIMDE_FLOAT32_C(    -8.98), SIMDE_FLOAT32_C(    21.11), SIMDE_FLOAT32_C(   -35.13), SIMDE_FLOAT32_C(    -2.61) },
      UINT8_C( 44),
      { SIMDE_FLOAT32_C(   -47.49), SIMDE_FLOAT32_C(   -43.31), SIMDE_FLOAT32_C(    48.10), SIMDE_FLOAT32_C(    48.31) },
      { SIMDE_FLOAT32_C(   -33.22), SIMDE_FLOAT32_C(   -45.96), SIMDE_FLOAT32_C(    12.04), SIMDE_FLOAT32_C(    -9.66) },
      { SIMDE_FLOAT32_C(    -8.98), SIMDE_FLOAT32_C(    21.11), SIMDE_FLOAT32_C(-6329059.00), SIMDE_FLOAT32_C(  -467.02) } },
    { { SIMDE_FLOAT32_C(    14.51), SIMDE_FLOAT32_C(   -11.26), SIMDE_FLOAT32_C(    13.15), SIMDE_FLOAT32_C(    34.22) },
      UINT8_C( 70),
      { SIMDE_FLOAT32_C(   -33.59), SIMDE_FLOAT32_C(     2.45), SIMDE_FLOAT32_C(   -22.28), SIMDE_FLOAT32_C(    29.10) },
      { SIMDE_FLOAT32_C(    -0.93), SIMDE_FLOAT32_C(   -47.58), SIMDE_FLOAT32_C(   -43.63), SIMDE_FLOAT32_C(     1.58) },
      { SIMDE_FLOAT32_C(    14.51), SIMDE_FLOAT32_C(-13617759373261537280.00), SIMDE_FLOAT32_C(   981.03), SIMDE_FLOAT32_C(    34.22) } },
    { { SIMDE_FLOAT32_C(   -14.91), SIMDE_FLOAT32_C(    19.73), SIMDE_FLOAT32_C(   -18.66), SIMDE_FLOAT32_C(    48.05) },
      UINT8_C(227),
      { SIMDE_FLOAT32_C(   -40.90), SIMDE_FLOAT32_C(   -45.52), SIMDE_FLOAT32_C(    -0.11), SIMDE_FLOAT32_C(   -24.11) },
      { SIMDE_FLOAT32_C(   -41.49), SIMDE_FLOAT32_C(   -38.07), SIMDE_FLOAT32_C(    16.22), SIMDE_FLOAT32_C(    -7.83) },
      { SIMDE_FLOAT32_C(7872185856.00), SIMDE_FLOAT32_C(  1748.73), SIMDE_FLOAT32_C(   -18.66), SIMDE_FLOAT32_C(    48.05) } },
    { { SIMDE_FLOAT32_C(    26.85), SIMDE_FLOAT32_C(    17.63), SIMDE_FLOAT32_C(    16.96), SIMDE_FLOAT32_C(   -11.23) },
      UINT8_C( 73),
      { SIMDE_FLOAT32_C(    20.34), SIMDE_FLOAT32_C(   -46.62), SIMDE_FLOAT32_C(    11.95), SIMDE_FLOAT32_C(    33.90) },
      { SIMDE_FLOAT32_C(    -6.32), SIMDE_FLOAT32_C(   -30.29), SIMDE_FLOAT32_C(     7.76), SIMDE_FLOAT32_C(    21.94) },
      { SIMDE_FLOAT32_C(  -100.98), SIMDE_FLOAT32_C(    17.63), SIMDE_FLOAT32_C(    16.96), SIMDE_FLOAT32_C(   727.05) } },
    { { SIMDE_FLOAT32_C(   -36.14), SIMDE_FLOAT32_C(    33.15), SIMDE_FLOAT32_C(   -46.67), SIMDE_FLOAT32_C(    30.56) },
      UINT8_C( 43),
      { SIMDE_FLOAT32_C(    16.14), SIMDE_FLOAT32_C(     2.20), SIMDE_FLOAT32_C(    42.34), SIMDE_FLOAT32_C(    45.79) },
      { SIMDE_FLOAT32_C(    17.91), SIMDE_FLOAT32_C(    39.28), SIMDE_FLOAT32_C(   -38.32), SIMDE_FLOAT32_C(    -5.20) },
      { SIMDE_FLOAT32_C(   252.09), SIMDE_FLOAT32_C(   119.01), SIMDE_FLOAT32_C(   -46.67), SIMDE_FLOAT32_C(7416053760.00) } },
    { { SIMDE_FLOAT32_C(    42.26), SIMDE_FLOAT32_C(    -4.90), SIMDE_FLOAT32_C(   -10.91), SIMDE_FLOAT32_C(   -34.04) },
      UINT8_C(193),
      { SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(    29.82), SIMDE_FLOAT32_C(   -42.37), SIMDE_FLOAT32_C(    31.08) },
      { SIMDE_FLOAT32_C(   -47.45), SIMDE_FLOAT32_C(   -18.97), SIMDE_FLOAT32_C(   -46.05), SIMDE_FLOAT32_C(     7.17) },
      { SIMDE_FLOAT32_C(7684751360.00), SIMDE_FLOAT32_C(    -4.90), SIMDE_FLOAT32_C(   -10.91), SIMDE_FLOAT32_C(   -34.04) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 tmp, src, r;
    simde__m128bh a, b;

    src = simde_mm_loadu_ps(test_vec[i].src);

    tmp = simde_mm_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm_mask_dpbf16_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128bh a = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 0, values));
    simde__m128bh b = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 1, values));
    simde__m128 r = simde_mm_mask_dpbf16_ps(src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 src[4];
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT8_C(199),
      { SIMDE_FLOAT32_C(   -22.83), SIMDE_FLOAT32_C(    28.42), SIMDE_FLOAT32_C(    20.82), SIMDE_FLOAT32_C(   -21.24) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    29.78),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    44.29) },
      { SIMDE_FLOAT32_C(   -22.83),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    29.04) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00) } },
    #endif
    { UINT8_C(235),
      { SIMDE_FLOAT32_C(   -21.64), SIMDE_FLOAT32_C(    48.49), SIMDE_FLOAT32_C(    -5.03), SIMDE_FLOAT32_C(   -23.56) },
      { SIMDE_FLOAT32_C(     6.04), SIMDE_FLOAT32_C(    18.13), SIMDE_FLOAT32_C(   -10.58), SIMDE_FLOAT32_C(    -9.46) },
      { SIMDE_FLOAT32_C(    34.22), SIMDE_FLOAT32_C(    -8.03), SIMDE_FLOAT32_C(    45.38), SIMDE_FLOAT32_C(   -46.31) },
      { SIMDE_FLOAT32_C(-20542294200482956679577600.00), SIMDE_FLOAT32_C(  5219.12), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(11195502271922176.00) } },
    { UINT8_C(228),
      { SIMDE_FLOAT32_C(    39.92), SIMDE_FLOAT32_C(   -30.09), SIMDE_FLOAT32_C(   -39.94), SIMDE_FLOAT32_C(    -8.65) },
      { SIMDE_FLOAT32_C(   -43.52), SIMDE_FLOAT32_C(   -15.88), SIMDE_FLOAT32_C(    16.84), SIMDE_FLOAT32_C(    40.69) },
      { SIMDE_FLOAT32_C(   -19.38), SIMDE_FLOAT32_C(   -48.07), SIMDE_FLOAT32_C(    10.42), SIMDE_FLOAT32_C(    11.96) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   133.84), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(254),
      { SIMDE_FLOAT32_C(   -15.47), SIMDE_FLOAT32_C(    33.47), SIMDE_FLOAT32_C(   -44.29), SIMDE_FLOAT32_C(    10.93) },
      { SIMDE_FLOAT32_C(    49.98), SIMDE_FLOAT32_C(    -7.35), SIMDE_FLOAT32_C(   -11.19), SIMDE_FLOAT32_C(    17.61) },
      { SIMDE_FLOAT32_C(   -40.39), SIMDE_FLOAT32_C(    27.57), SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(    39.03) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -168.48), SIMDE_FLOAT32_C(  -125.40), SIMDE_FLOAT32_C(   688.94) } },
    { UINT8_C( 48),
      { SIMDE_FLOAT32_C(    36.02), SIMDE_FLOAT32_C(   -28.60), SIMDE_FLOAT32_C(   -17.43), SIMDE_FLOAT32_C(   -20.14) },
      { SIMDE_FLOAT32_C(    19.73), SIMDE_FLOAT32_C(   -47.02), SIMDE_FLOAT32_C(    48.09), SIMDE_FLOAT32_C(     3.94) },
      { SIMDE_FLOAT32_C(    -5.05), SIMDE_FLOAT32_C(    43.47), SIMDE_FLOAT32_C(     7.63), SIMDE_FLOAT32_C(     1.43) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(  9),
      { SIMDE_FLOAT32_C(   -48.11), SIMDE_FLOAT32_C(     7.03), SIMDE_FLOAT32_C(    43.72), SIMDE_FLOAT32_C(    22.70) },
      { SIMDE_FLOAT32_C(   -22.41), SIMDE_FLOAT32_C(   -25.53), SIMDE_FLOAT32_C(    -7.88), SIMDE_FLOAT32_C(     8.21) },
      { SIMDE_FLOAT32_C(   -23.60), SIMDE_FLOAT32_C(   -47.46), SIMDE_FLOAT32_C(   -29.83), SIMDE_FLOAT32_C(   -23.62) },
      { SIMDE_FLOAT32_C(-9575092715520.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF } },
    { UINT8_C(102),
      { SIMDE_FLOAT32_C(   -14.30), SIMDE_FLOAT32_C(   -48.94), SIMDE_FLOAT32_C(    34.28), SIMDE_FLOAT32_C(    30.67) },
      { SIMDE_FLOAT32_C(    -4.80), SIMDE_FLOAT32_C(     8.97), SIMDE_FLOAT32_C(    43.99), SIMDE_FLOAT32_C(     4.81) },
      { SIMDE_FLOAT32_C(   -13.46), SIMDE_FLOAT32_C(     1.27), SIMDE_FLOAT32_C(    -6.16), SIMDE_FLOAT32_C(    43.90) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -37.63), SIMDE_FLOAT32_C(-9631464161280.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 73),
      { SIMDE_FLOAT32_C(   -30.20), SIMDE_FLOAT32_C(   -38.70), SIMDE_FLOAT32_C(    -2.33), SIMDE_FLOAT32_C(   -12.17) },
      { SIMDE_FLOAT32_C(    -8.28), SIMDE_FLOAT32_C(   -37.76), SIMDE_FLOAT32_C(     7.19), SIMDE_FLOAT32_C(     5.90) },
      { SIMDE_FLOAT32_C(    37.14), SIMDE_FLOAT32_C(   -26.21), SIMDE_FLOAT32_C(   -32.69), SIMDE_FLOAT32_C(   -28.12) },
      { SIMDE_FLOAT32_C(-6336335.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 tmp, src, r;
    simde__m128bh a, b;

    src = simde_mm_loadu_ps(test_vec[i].src);

    tmp = simde_mm_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm_maskz_dpbf16_ps(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m128bh a = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 0, values));
    simde__m128bh b = HEDLEY_REINTERPRET_CAST(simde__m128bh, simde_test_x86_random_extract_f32x4(i, 2, 1, values));
    simde__m128 r = simde_mm_maskz_dpbf16_ps(k, src, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, HEDLEY_REINTERPRET_CAST(simde__m128, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(   -43.55), SIMDE_FLOAT32_C(   -40.45), SIMDE_FLOAT32_C(    32.76), SIMDE_FLOAT32_C(   -28.04),
        SIMDE_FLOAT32_C(   -49.60), SIMDE_FLOAT32_C(    -3.34), SIMDE_FLOAT32_C(   -24.54), SIMDE_FLOAT32_C(    -4.35) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    21.20),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -15.30),
        SIMDE_FLOAT32_C(   -19.91), SIMDE_FLOAT32_C(   -23.31), SIMDE_FLOAT32_C(     4.99), SIMDE_FLOAT32_C(   -16.82) },
      { SIMDE_FLOAT32_C(   -40.48),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -43.54),
        SIMDE_FLOAT32_C(    42.85), SIMDE_FLOAT32_C(   -44.25), SIMDE_FLOAT32_C(   -25.14), SIMDE_FLOAT32_C(    17.55) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   635.34),
        SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(  1025.47), SIMDE_FLOAT32_C(  -149.38), SIMDE_FLOAT32_C(  -297.48) } },
    #endif
    { { SIMDE_FLOAT32_C(    44.44), SIMDE_FLOAT32_C(    41.32), SIMDE_FLOAT32_C(    38.89), SIMDE_FLOAT32_C(   -14.30),
        SIMDE_FLOAT32_C(     3.18), SIMDE_FLOAT32_C(    24.09), SIMDE_FLOAT32_C(    48.74), SIMDE_FLOAT32_C(     0.39) },
      { SIMDE_FLOAT32_C(     9.27), SIMDE_FLOAT32_C(   -49.63), SIMDE_FLOAT32_C(   -31.31), SIMDE_FLOAT32_C(   -44.30),
        SIMDE_FLOAT32_C(    32.50), SIMDE_FLOAT32_C(   -18.32), SIMDE_FLOAT32_C(    39.56), SIMDE_FLOAT32_C(   -42.25) },
      { SIMDE_FLOAT32_C(     8.28), SIMDE_FLOAT32_C(    23.80), SIMDE_FLOAT32_C(    48.27), SIMDE_FLOAT32_C(    -1.67),
        SIMDE_FLOAT32_C(   -22.88), SIMDE_FLOAT32_C(    19.98), SIMDE_FLOAT32_C(    27.98), SIMDE_FLOAT32_C(    29.46) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C( -1134.31), SIMDE_FLOAT32_C(7402289664.00), SIMDE_FLOAT32_C(    59.33),
        SIMDE_FLOAT32_C(  -740.26), SIMDE_FLOAT32_C(  -338.63), SIMDE_FLOAT32_C(-8927626395648.00), SIMDE_FLOAT32_C( -1240.70) } },
    { { SIMDE_FLOAT32_C(   -22.28), SIMDE_FLOAT32_C(    -6.46), SIMDE_FLOAT32_C(   -38.16), SIMDE_FLOAT32_C(    34.00),
        SIMDE_FLOAT32_C(    38.34), SIMDE_FLOAT32_C(    -9.77), SIMDE_FLOAT32_C(    25.42), SIMDE_FLOAT32_C(    49.76) },
      { SIMDE_FLOAT32_C(    -8.82), SIMDE_FLOAT32_C(    26.07), SIMDE_FLOAT32_C(   -35.84), SIMDE_FLOAT32_C(    21.26),
        SIMDE_FLOAT32_C(   -47.24), SIMDE_FLOAT32_C(    19.15), SIMDE_FLOAT32_C(   -45.56), SIMDE_FLOAT32_C(   -37.72) },
      { SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(    18.63), SIMDE_FLOAT32_C(   -31.27), SIMDE_FLOAT32_C(    -7.94),
        SIMDE_FLOAT32_C(    24.38), SIMDE_FLOAT32_C(    -6.40), SIMDE_FLOAT32_C(   -40.39), SIMDE_FLOAT32_C(   -16.36) },
      { SIMDE_FLOAT32_C(   -15.33), SIMDE_FLOAT32_C(   477.79), SIMDE_FLOAT32_C(  6275.78), SIMDE_FLOAT32_C(  -134.67),
        SIMDE_FLOAT32_C( -1111.78), SIMDE_FLOAT32_C(  -136.17), SIMDE_FLOAT32_C(  1856.80),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(    15.37), SIMDE_FLOAT32_C(   -45.56), SIMDE_FLOAT32_C(   -27.67), SIMDE_FLOAT32_C(    46.56),
        SIMDE_FLOAT32_C(   -35.28), SIMDE_FLOAT32_C(    26.70), SIMDE_FLOAT32_C(     7.23), SIMDE_FLOAT32_C(   -28.83) },
      { SIMDE_FLOAT32_C(    -6.04), SIMDE_FLOAT32_C(   -21.70), SIMDE_FLOAT32_C(   -10.66), SIMDE_FLOAT32_C(   -23.53),
        SIMDE_FLOAT32_C(     9.98), SIMDE_FLOAT32_C(   -21.10), SIMDE_FLOAT32_C(   -15.78), SIMDE_FLOAT32_C(   -31.74) },
      { SIMDE_FLOAT32_C(   -47.30), SIMDE_FLOAT32_C(   -17.51), SIMDE_FLOAT32_C(    16.59), SIMDE_FLOAT32_C(   -20.18),
        SIMDE_FLOAT32_C(   -47.53), SIMDE_FLOAT32_C(    -5.44), SIMDE_FLOAT32_C(   -40.72), SIMDE_FLOAT32_C(    -6.35) },
      { SIMDE_FLOAT32_C(   300.35), SIMDE_FLOAT32_C(   332.88), SIMDE_FLOAT32_C(  -202.98), SIMDE_FLOAT32_C(23890792047224301750543450112.00),
        SIMDE_FLOAT32_C(  -507.31), SIMDE_FLOAT32_C(   140.89),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-13402149541101174784.00) } },
    { { SIMDE_FLOAT32_C(    36.26), SIMDE_FLOAT32_C(   -10.01), SIMDE_FLOAT32_C(    -6.87), SIMDE_FLOAT32_C(    36.66),
        SIMDE_FLOAT32_C(    36.66), SIMDE_FLOAT32_C(    18.59), SIMDE_FLOAT32_C(   -17.70), SIMDE_FLOAT32_C(    31.10) },
      { SIMDE_FLOAT32_C(   -29.37), SIMDE_FLOAT32_C(   -26.55), SIMDE_FLOAT32_C(   -35.09), SIMDE_FLOAT32_C(   -26.61),
        SIMDE_FLOAT32_C(    42.60), SIMDE_FLOAT32_C(   -30.65), SIMDE_FLOAT32_C(   -14.33), SIMDE_FLOAT32_C(    -8.19) },
      { SIMDE_FLOAT32_C(    37.98), SIMDE_FLOAT32_C(     4.40), SIMDE_FLOAT32_C(    33.88), SIMDE_FLOAT32_C(    12.36),
        SIMDE_FLOAT32_C(    48.00), SIMDE_FLOAT32_C(    43.48), SIMDE_FLOAT32_C(    46.00), SIMDE_FLOAT32_C(    -8.04) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-29184436426152839980746853580800.00), SIMDE_FLOAT32_C( -1188.12), SIMDE_FLOAT32_C(16486777515877911756800.00),
        SIMDE_FLOAT32_C(  2076.66), SIMDE_FLOAT32_C(-13402149541101174784.00), SIMDE_FLOAT32_C(  -676.08), SIMDE_FLOAT32_C(    96.60) } },
    { { SIMDE_FLOAT32_C(     9.08), SIMDE_FLOAT32_C(    25.33), SIMDE_FLOAT32_C(   -42.99), SIMDE_FLOAT32_C(    -2.58),
        SIMDE_FLOAT32_C(   -34.44), SIMDE_FLOAT32_C(    32.43), SIMDE_FLOAT32_C(    -2.82), SIMDE_FLOAT32_C(    30.93) },
      { SIMDE_FLOAT32_C(   -20.51), SIMDE_FLOAT32_C(    46.17), SIMDE_FLOAT32_C(     5.18), SIMDE_FLOAT32_C(   -27.91),
        SIMDE_FLOAT32_C(   -34.48), SIMDE_FLOAT32_C(    40.85), SIMDE_FLOAT32_C(    13.90), SIMDE_FLOAT32_C(   -46.50) },
      { SIMDE_FLOAT32_C(    -4.75), SIMDE_FLOAT32_C(    -2.22), SIMDE_FLOAT32_C(    15.86), SIMDE_FLOAT32_C(    -6.76),
        SIMDE_FLOAT32_C(    -8.74), SIMDE_FLOAT32_C(    11.86), SIMDE_FLOAT32_C(    35.20), SIMDE_FLOAT32_C(    13.04) },
      { SIMDE_FLOAT32_C(   106.46), SIMDE_FLOAT32_C(   -76.73), SIMDE_FLOAT32_C(  5150.79), SIMDE_FLOAT32_C(11287586370748416.00),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-19414829202697828884807680.00), SIMDE_FLOAT32_C(-29184436426152839980746853580800.00), SIMDE_FLOAT32_C(  -573.57) } },
    { { SIMDE_FLOAT32_C(   -22.82), SIMDE_FLOAT32_C(   -13.42), SIMDE_FLOAT32_C(   -38.50), SIMDE_FLOAT32_C(    -3.20),
        SIMDE_FLOAT32_C(    -8.82), SIMDE_FLOAT32_C(    17.53), SIMDE_FLOAT32_C(    49.52), SIMDE_FLOAT32_C(     1.94) },
      { SIMDE_FLOAT32_C(   -41.60), SIMDE_FLOAT32_C(     7.42), SIMDE_FLOAT32_C(    27.15), SIMDE_FLOAT32_C(    16.02),
        SIMDE_FLOAT32_C(    22.15), SIMDE_FLOAT32_C(    38.29), SIMDE_FLOAT32_C(   -13.83), SIMDE_FLOAT32_C(    45.19) },
      { SIMDE_FLOAT32_C(    47.35), SIMDE_FLOAT32_C(   -42.76), SIMDE_FLOAT32_C(    48.65), SIMDE_FLOAT32_C(    -6.98),
        SIMDE_FLOAT32_C(   -44.00), SIMDE_FLOAT32_C(    41.52), SIMDE_FLOAT32_C(   -16.70), SIMDE_FLOAT32_C(   -45.18) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -330.03), SIMDE_FLOAT32_C(  1277.06), SIMDE_FLOAT32_C(  5082.05),
        SIMDE_FLOAT32_C(  -982.32), SIMDE_FLOAT32_C(  1604.91), SIMDE_FLOAT32_C(   279.15), SIMDE_FLOAT32_C( -2023.06) } },
    { { SIMDE_FLOAT32_C(    45.15), SIMDE_FLOAT32_C(     7.49), SIMDE_FLOAT32_C(     7.14), SIMDE_FLOAT32_C(   -19.46),
        SIMDE_FLOAT32_C(   -34.09), SIMDE_FLOAT32_C(     4.14), SIMDE_FLOAT32_C(    30.94), SIMDE_FLOAT32_C(    23.42) },
      { SIMDE_FLOAT32_C(     5.07), SIMDE_FLOAT32_C(    37.87), SIMDE_FLOAT32_C(   -32.67), SIMDE_FLOAT32_C(   -13.70),
        SIMDE_FLOAT32_C(   -39.25), SIMDE_FLOAT32_C(    41.58), SIMDE_FLOAT32_C(     0.04), SIMDE_FLOAT32_C(    43.83) },
      { SIMDE_FLOAT32_C(     1.07), SIMDE_FLOAT32_C(   -28.76), SIMDE_FLOAT32_C(    33.36), SIMDE_FLOAT32_C(    39.77),
        SIMDE_FLOAT32_C(    47.18), SIMDE_FLOAT32_C(    25.69), SIMDE_FLOAT32_C(   -20.99), SIMDE_FLOAT32_C(   -44.42) },
      { SIMDE_FLOAT32_C(-29088496073108223009442171453440.00), SIMDE_FLOAT32_C(7402290176.00), SIMDE_FLOAT32_C(-13663921269442084864.00), SIMDE_FLOAT32_C(  -563.54),
        SIMDE_FLOAT32_C( -1878.84), SIMDE_FLOAT32_C(  1067.58),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C( -1916.78) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 tmp, src, r;
    simde__m256bh a, b;

    src = simde_mm256_loadu_ps(test_vec[i].src);

    tmp = simde_mm256_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm256_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm256_dpbf16_ps(src, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m256)];
  simde_test_x86_random_f32x8_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m256bh a = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 0, values));
    simde__m256bh b = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 1, values));
    simde__m256 r = simde_mm256_dpbf16_ps(src, a, b);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    18.56), SIMDE_FLOAT32_C(    -7.58), SIMDE_FLOAT32_C(   -43.70), SIMDE_FLOAT32_C(   -16.96),
        SIMDE_FLOAT32_C(   -40.14), SIMDE_FLOAT32_C(     4.59), SIMDE_FLOAT32_C(     1.18), SIMDE_FLOAT32_C(     0.97) },
      UINT8_C(211),
      { SIMDE_FLOAT32_C(   -47.64), SIMDE_FLOAT32_C(    17.81), SIMDE_FLOAT32_C(    46.74), SIMDE_FLOAT32_C(    24.20),
        SIMDE_FLOAT32_C(     9.47), SIMDE_FLOAT32_C(   -29.52), SIMDE_FLOAT32_C(   -32.75), SIMDE_FLOAT32_C(   -45.08) },
      { SIMDE_FLOAT32_C(   -42.94), SIMDE_FLOAT32_C(    34.02), SIMDE_FLOAT32_C(   -28.54), SIMDE_FLOAT32_C(     7.11),
        SIMDE_FLOAT32_C(    31.91), SIMDE_FLOAT32_C(   -43.84), SIMDE_FLOAT32_C(   -31.77), SIMDE_FLOAT32_C(    27.44) },
      { SIMDE_FLOAT32_C(  2049.19), SIMDE_FLOAT32_C(7402291712.00), SIMDE_FLOAT32_C(   -43.70), SIMDE_FLOAT32_C(   -16.96),
        SIMDE_FLOAT32_C(   260.68), SIMDE_FLOAT32_C(     4.59), SIMDE_FLOAT32_C(  1040.99), SIMDE_FLOAT32_C( -1230.91) } },
    { { SIMDE_FLOAT32_C(    44.89), SIMDE_FLOAT32_C(   -35.37), SIMDE_FLOAT32_C(   -40.40), SIMDE_FLOAT32_C(   -29.91),
        SIMDE_FLOAT32_C(    21.16), SIMDE_FLOAT32_C(   -40.49), SIMDE_FLOAT32_C(    14.61), SIMDE_FLOAT32_C(    47.05) },
      UINT8_C(101),
      { SIMDE_FLOAT32_C(    36.93), SIMDE_FLOAT32_C(    13.07), SIMDE_FLOAT32_C(   -44.42), SIMDE_FLOAT32_C(    44.87),
        SIMDE_FLOAT32_C(   -20.91), SIMDE_FLOAT32_C(   -49.83), SIMDE_FLOAT32_C(     7.11), SIMDE_FLOAT32_C(     2.98) },
      { SIMDE_FLOAT32_C(    18.08), SIMDE_FLOAT32_C(   -24.95), SIMDE_FLOAT32_C(    -9.92), SIMDE_FLOAT32_C(    12.44),
        SIMDE_FLOAT32_C(    28.10), SIMDE_FLOAT32_C(   -33.34), SIMDE_FLOAT32_C(    -6.24), SIMDE_FLOAT32_C(    30.46) },
      { SIMDE_FLOAT32_C(   706.39), SIMDE_FLOAT32_C(   -35.37), SIMDE_FLOAT32_C(   396.57), SIMDE_FLOAT32_C(   -29.91),
        SIMDE_FLOAT32_C(    21.16), SIMDE_FLOAT32_C(24108398694754935001990561792.00), SIMDE_FLOAT32_C(   -29.50), SIMDE_FLOAT32_C(    47.05) } },
    { { SIMDE_FLOAT32_C(    -6.28), SIMDE_FLOAT32_C(     5.72), SIMDE_FLOAT32_C(   -34.13), SIMDE_FLOAT32_C(    28.30),
        SIMDE_FLOAT32_C(   -44.56), SIMDE_FLOAT32_C(    14.29), SIMDE_FLOAT32_C(    39.35), SIMDE_FLOAT32_C(    11.62) },
      UINT8_C(117),
      { SIMDE_FLOAT32_C(    34.48), SIMDE_FLOAT32_C(    -9.50), SIMDE_FLOAT32_C(     4.65), SIMDE_FLOAT32_C(    -6.05),
        SIMDE_FLOAT32_C(    10.98), SIMDE_FLOAT32_C(    21.90), SIMDE_FLOAT32_C(    -1.13), SIMDE_FLOAT32_C(    18.04) },
      { SIMDE_FLOAT32_C(     5.92), SIMDE_FLOAT32_C(    20.32), SIMDE_FLOAT32_C(   -24.85), SIMDE_FLOAT32_C(   -12.17),
        SIMDE_FLOAT32_C(    26.48), SIMDE_FLOAT32_C(    -6.62), SIMDE_FLOAT32_C(   -34.72), SIMDE_FLOAT32_C(    13.42) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     5.72), SIMDE_FLOAT32_C(11551744039321600.00), SIMDE_FLOAT32_C(    28.30),
        SIMDE_FLOAT32_C(  5349.92), SIMDE_FLOAT32_C(-6323841.50), SIMDE_FLOAT32_C(  5453.16), SIMDE_FLOAT32_C(    11.62) } },
    { { SIMDE_FLOAT32_C(    16.02), SIMDE_FLOAT32_C(    14.71), SIMDE_FLOAT32_C(    31.29), SIMDE_FLOAT32_C(     9.84),
        SIMDE_FLOAT32_C(   -16.73), SIMDE_FLOAT32_C(   -26.29), SIMDE_FLOAT32_C(    16.15), SIMDE_FLOAT32_C(    16.31) },
      UINT8_C(236),
      { SIMDE_FLOAT32_C(   -43.56), SIMDE_FLOAT32_C(   -29.14), SIMDE_FLOAT32_C(     8.29), SIMDE_FLOAT32_C(   -14.47),
        SIMDE_FLOAT32_C(   -28.97), SIMDE_FLOAT32_C(   -34.60), SIMDE_FLOAT32_C(    38.51), SIMDE_FLOAT32_C(    39.12) },
      { SIMDE_FLOAT32_C(    -9.55), SIMDE_FLOAT32_C(   -21.41), SIMDE_FLOAT32_C(     1.56), SIMDE_FLOAT32_C(   -31.45),
        SIMDE_FLOAT32_C(    -4.75), SIMDE_FLOAT32_C(    45.32), SIMDE_FLOAT32_C(    49.01), SIMDE_FLOAT32_C(   -20.27) },
      { SIMDE_FLOAT32_C(    16.02), SIMDE_FLOAT32_C(    14.71), SIMDE_FLOAT32_C(    44.12), SIMDE_FLOAT32_C(   462.82),
        SIMDE_FLOAT32_C(   -16.73), SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(  1902.65), SIMDE_FLOAT32_C(15953551319997245030400.00) } },
    { { SIMDE_FLOAT32_C(   -29.26), SIMDE_FLOAT32_C(   -32.51), SIMDE_FLOAT32_C(    34.54), SIMDE_FLOAT32_C(   -29.58),
        SIMDE_FLOAT32_C(   -37.63), SIMDE_FLOAT32_C(    49.17), SIMDE_FLOAT32_C(   -19.98), SIMDE_FLOAT32_C(   -17.54) },
      UINT8_C(127),
      { SIMDE_FLOAT32_C(   -14.19), SIMDE_FLOAT32_C(     3.66), SIMDE_FLOAT32_C(    23.68), SIMDE_FLOAT32_C(    46.80),
        SIMDE_FLOAT32_C(   -24.43), SIMDE_FLOAT32_C(   -27.45), SIMDE_FLOAT32_C(    14.84), SIMDE_FLOAT32_C(    31.49) },
      { SIMDE_FLOAT32_C(    42.87), SIMDE_FLOAT32_C(    39.99), SIMDE_FLOAT32_C(   -30.68), SIMDE_FLOAT32_C(    19.36),
        SIMDE_FLOAT32_C(   -16.64), SIMDE_FLOAT32_C(   -15.40), SIMDE_FLOAT32_C(   -17.23), SIMDE_FLOAT32_C(   -10.19) },
      { SIMDE_FLOAT32_C(  4679.85), SIMDE_FLOAT32_C(-29088496073108223009442171453440.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-9609989324800.00),
        SIMDE_FLOAT32_C(7910457856.00), SIMDE_FLOAT32_C(   465.74),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -17.54) } },
    { { SIMDE_FLOAT32_C(    12.48), SIMDE_FLOAT32_C(   -41.56), SIMDE_FLOAT32_C(    40.16), SIMDE_FLOAT32_C(   -10.95),
        SIMDE_FLOAT32_C(    24.46), SIMDE_FLOAT32_C(     4.87), SIMDE_FLOAT32_C(   -29.66), SIMDE_FLOAT32_C(   -15.69) },
      UINT8_C(174),
      { SIMDE_FLOAT32_C(   -31.86), SIMDE_FLOAT32_C(    -8.89), SIMDE_FLOAT32_C(    -4.91), SIMDE_FLOAT32_C(    -6.29),
        SIMDE_FLOAT32_C(    13.66), SIMDE_FLOAT32_C(   -40.08), SIMDE_FLOAT32_C(   -24.80), SIMDE_FLOAT32_C(     6.53) },
      { SIMDE_FLOAT32_C(    49.91), SIMDE_FLOAT32_C(    -5.48), SIMDE_FLOAT32_C(   -24.11), SIMDE_FLOAT32_C(   -16.73),
        SIMDE_FLOAT32_C(    29.12), SIMDE_FLOAT32_C(     8.66), SIMDE_FLOAT32_C(    23.08), SIMDE_FLOAT32_C(   -15.43) },
      { SIMDE_FLOAT32_C(    12.48), SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(   153.42), SIMDE_FLOAT32_C(-13517554281552543744.00),
        SIMDE_FLOAT32_C(    24.46), SIMDE_FLOAT32_C(  -340.13), SIMDE_FLOAT32_C(   -29.66),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   -40.43), SIMDE_FLOAT32_C(    13.45), SIMDE_FLOAT32_C(   -42.45), SIMDE_FLOAT32_C(    -7.68),
        SIMDE_FLOAT32_C(    33.78), SIMDE_FLOAT32_C(     9.61), SIMDE_FLOAT32_C(   -47.80), SIMDE_FLOAT32_C(   -14.17) },
      UINT8_C(221),
      { SIMDE_FLOAT32_C(   -45.55), SIMDE_FLOAT32_C(    47.06), SIMDE_FLOAT32_C(    12.77), SIMDE_FLOAT32_C(   -28.83),
        SIMDE_FLOAT32_C(    37.41), SIMDE_FLOAT32_C(    -3.34), SIMDE_FLOAT32_C(   -32.47), SIMDE_FLOAT32_C(    49.71) },
      { SIMDE_FLOAT32_C(   -45.42), SIMDE_FLOAT32_C(    34.06), SIMDE_FLOAT32_C(   -16.73), SIMDE_FLOAT32_C(     2.63),
        SIMDE_FLOAT32_C(    -3.83), SIMDE_FLOAT32_C(   -12.76), SIMDE_FLOAT32_C(    -9.10), SIMDE_FLOAT32_C(   -30.91) },
      { SIMDE_FLOAT32_C(  2018.44), SIMDE_FLOAT32_C(    13.45), SIMDE_FLOAT32_C(-19224753951762325664956416.00), SIMDE_FLOAT32_C(   -83.15),
        SIMDE_FLOAT32_C(  -108.82), SIMDE_FLOAT32_C(     9.61), SIMDE_FLOAT32_C(   244.47), SIMDE_FLOAT32_C(-13517554281552543744.00) } },
    { { SIMDE_FLOAT32_C(    23.26), SIMDE_FLOAT32_C(     2.87), SIMDE_FLOAT32_C(   -48.26), SIMDE_FLOAT32_C(   -48.30),
        SIMDE_FLOAT32_C(    22.16), SIMDE_FLOAT32_C(    35.34), SIMDE_FLOAT32_C(   -43.42), SIMDE_FLOAT32_C(    32.62) },
      UINT8_C(169),
      { SIMDE_FLOAT32_C(    38.93), SIMDE_FLOAT32_C(    24.44), SIMDE_FLOAT32_C(    42.37), SIMDE_FLOAT32_C(     0.39),
        SIMDE_FLOAT32_C(   -32.05), SIMDE_FLOAT32_C(   -40.71), SIMDE_FLOAT32_C(   -42.65), SIMDE_FLOAT32_C(   -23.47) },
      { SIMDE_FLOAT32_C(    11.99), SIMDE_FLOAT32_C(   -48.15), SIMDE_FLOAT32_C(   -28.11), SIMDE_FLOAT32_C(    46.40),
        SIMDE_FLOAT32_C(    33.97), SIMDE_FLOAT32_C(    -2.45), SIMDE_FLOAT32_C(    -2.21), SIMDE_FLOAT32_C(    38.42) },
      { SIMDE_FLOAT32_C(7596933632.00), SIMDE_FLOAT32_C(     2.87), SIMDE_FLOAT32_C(   -48.26), SIMDE_FLOAT32_C(   -30.32),
        SIMDE_FLOAT32_C(    22.16), SIMDE_FLOAT32_C(16308074682663850475520.00), SIMDE_FLOAT32_C(   -43.42), SIMDE_FLOAT32_C(  -861.47) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 tmp, src, r;
    simde__m256bh a, b;

    src = simde_mm256_loadu_ps(test_vec[i].src);

    tmp = simde_mm256_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm256_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm256_mask_dpbf16_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m256)];
  simde_test_x86_random_f32x8_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256bh a = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 0, values));
    simde__m256bh b = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 1, values));
    simde__m256 r = simde_mm256_mask_dpbf16_ps(src, k, a, b);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 src[8];
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT8_C(205),
      { SIMDE_FLOAT32_C(   -36.42), SIMDE_FLOAT32_C(   -49.03), SIMDE_FLOAT32_C(   -38.95), SIMDE_FLOAT32_C(    12.54),
        SIMDE_FLOAT32_C(   -41.04), SIMDE_FLOAT32_C(    38.86), SIMDE_FLOAT32_C(    -1.22), SIMDE_FLOAT32_C(   -10.59) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -49.55),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    27.62),
        SIMDE_FLOAT32_C(   -28.81), SIMDE_FLOAT32_C(    21.94), SIMDE_FLOAT32_C(    12.16), SIMDE_FLOAT32_C(    -8.39) },
      { SIMDE_FLOAT32_C(    34.31),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -33.23),
        SIMDE_FLOAT32_C(   -18.34), SIMDE_FLOAT32_C(   -38.83), SIMDE_FLOAT32_C(   -36.16), SIMDE_FLOAT32_C(    49.05) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF,      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -437.72), SIMDE_FLOAT32_C(  -420.96) } },
    #endif
    { UINT8_C(205),
      { SIMDE_FLOAT32_C(    47.49), SIMDE_FLOAT32_C(    31.73), SIMDE_FLOAT32_C(    37.79), SIMDE_FLOAT32_C(    38.51),
        SIMDE_FLOAT32_C(    -2.46), SIMDE_FLOAT32_C(    11.57), SIMDE_FLOAT32_C(    25.38), SIMDE_FLOAT32_C(    49.11) },
      { SIMDE_FLOAT32_C(    43.49), SIMDE_FLOAT32_C(     4.63), SIMDE_FLOAT32_C(   -27.84), SIMDE_FLOAT32_C(    41.68),
        SIMDE_FLOAT32_C(    23.72), SIMDE_FLOAT32_C(     0.70), SIMDE_FLOAT32_C(     4.16), SIMDE_FLOAT32_C(    32.17) },
      { SIMDE_FLOAT32_C(    -9.14), SIMDE_FLOAT32_C(    43.22), SIMDE_FLOAT32_C(     6.63), SIMDE_FLOAT32_C(    45.73),
        SIMDE_FLOAT32_C(   -36.44), SIMDE_FLOAT32_C(    40.93), SIMDE_FLOAT32_C(    33.88), SIMDE_FLOAT32_C(     7.61) },
      { SIMDE_FLOAT32_C(-29088496073108223009442171453440.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -146.05), SIMDE_FLOAT32_C(16100548811834618019840.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   165.65), SIMDE_FLOAT32_C(   292.11) } },
    { UINT8_C(227),
      { SIMDE_FLOAT32_C(    43.82), SIMDE_FLOAT32_C(   -10.38), SIMDE_FLOAT32_C(    28.47), SIMDE_FLOAT32_C(   -13.83),
        SIMDE_FLOAT32_C(    17.93), SIMDE_FLOAT32_C(    24.26), SIMDE_FLOAT32_C(    35.71), SIMDE_FLOAT32_C(    16.82) },
      { SIMDE_FLOAT32_C(    41.39), SIMDE_FLOAT32_C(   -11.67), SIMDE_FLOAT32_C(   -14.77), SIMDE_FLOAT32_C(   -37.42),
        SIMDE_FLOAT32_C(   -39.73), SIMDE_FLOAT32_C(    47.39), SIMDE_FLOAT32_C(     4.19), SIMDE_FLOAT32_C(    44.58) },
      { SIMDE_FLOAT32_C(     8.72), SIMDE_FLOAT32_C(   -24.17), SIMDE_FLOAT32_C(   -38.65), SIMDE_FLOAT32_C(    40.38),
        SIMDE_FLOAT32_C(   -13.00), SIMDE_FLOAT32_C(   -24.81), SIMDE_FLOAT32_C(    39.44), SIMDE_FLOAT32_C(   -19.51) },
      { SIMDE_FLOAT32_C(   402.18), SIMDE_FLOAT32_C(-9526774333440.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-6337145.00), SIMDE_FLOAT32_C(   200.07), SIMDE_FLOAT32_C(  -850.93) } },
    { UINT8_C( 43),
      { SIMDE_FLOAT32_C(   -32.90), SIMDE_FLOAT32_C(     7.38), SIMDE_FLOAT32_C(   -28.27), SIMDE_FLOAT32_C(   -32.39),
        SIMDE_FLOAT32_C(    20.96), SIMDE_FLOAT32_C(   -27.31), SIMDE_FLOAT32_C(   -21.35), SIMDE_FLOAT32_C(   -16.50) },
      { SIMDE_FLOAT32_C(    29.83), SIMDE_FLOAT32_C(   -38.41), SIMDE_FLOAT32_C(   -27.83), SIMDE_FLOAT32_C(     3.55),
        SIMDE_FLOAT32_C(    12.29), SIMDE_FLOAT32_C(    26.34), SIMDE_FLOAT32_C(   -14.28), SIMDE_FLOAT32_C(   -46.85) },
      { SIMDE_FLOAT32_C(    19.55), SIMDE_FLOAT32_C(    42.34), SIMDE_FLOAT32_C(    48.89), SIMDE_FLOAT32_C(    33.11),
        SIMDE_FLOAT32_C(    33.28), SIMDE_FLOAT32_C(    32.76), SIMDE_FLOAT32_C(    -9.28), SIMDE_FLOAT32_C(    24.67) },
      { SIMDE_FLOAT32_C(-6329053.00), SIMDE_FLOAT32_C( -1613.12), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(16922581844619299913728.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   832.38), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(241),
      { SIMDE_FLOAT32_C(   -32.49), SIMDE_FLOAT32_C(    32.27), SIMDE_FLOAT32_C(    21.07), SIMDE_FLOAT32_C(    38.46),
        SIMDE_FLOAT32_C(    29.77), SIMDE_FLOAT32_C(     2.80), SIMDE_FLOAT32_C(    26.25), SIMDE_FLOAT32_C(    18.28) },
      { SIMDE_FLOAT32_C(   -28.91), SIMDE_FLOAT32_C(    25.95), SIMDE_FLOAT32_C(    37.25), SIMDE_FLOAT32_C(   -18.64),
        SIMDE_FLOAT32_C(    23.34), SIMDE_FLOAT32_C(    -8.56), SIMDE_FLOAT32_C(   -24.07), SIMDE_FLOAT32_C(   -17.94) },
      { SIMDE_FLOAT32_C(    17.27), SIMDE_FLOAT32_C(   -12.72), SIMDE_FLOAT32_C(   -27.55), SIMDE_FLOAT32_C(   -45.73),
        SIMDE_FLOAT32_C(    12.48), SIMDE_FLOAT32_C(   -38.12), SIMDE_FLOAT32_C(   -15.24), SIMDE_FLOAT32_C(    -7.70) },
      { SIMDE_FLOAT32_C(  -530.58), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   318.94),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   390.75), SIMDE_FLOAT32_C(   155.69) } },
    { UINT8_C( 27),
      { SIMDE_FLOAT32_C(   -12.18), SIMDE_FLOAT32_C(    -6.34), SIMDE_FLOAT32_C(    49.45), SIMDE_FLOAT32_C(   -43.57),
        SIMDE_FLOAT32_C(   -12.52), SIMDE_FLOAT32_C(   -10.93), SIMDE_FLOAT32_C(    34.90), SIMDE_FLOAT32_C(    23.65) },
      { SIMDE_FLOAT32_C(   -26.52), SIMDE_FLOAT32_C(     6.93), SIMDE_FLOAT32_C(    45.85), SIMDE_FLOAT32_C(    35.77),
        SIMDE_FLOAT32_C(   -16.73), SIMDE_FLOAT32_C(   -18.43), SIMDE_FLOAT32_C(    38.93), SIMDE_FLOAT32_C(   -47.18) },
      { SIMDE_FLOAT32_C(   -26.09), SIMDE_FLOAT32_C(    37.81), SIMDE_FLOAT32_C(    35.93), SIMDE_FLOAT32_C(   -42.81),
        SIMDE_FLOAT32_C(    20.58), SIMDE_FLOAT32_C(   -23.35), SIMDE_FLOAT32_C(    31.86), SIMDE_FLOAT32_C(    41.67) },
      { SIMDE_FLOAT32_C(   676.82), SIMDE_FLOAT32_C(   250.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1571.88),
        SIMDE_FLOAT32_C(  -353.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(141),
      { SIMDE_FLOAT32_C(     9.16), SIMDE_FLOAT32_C(     9.35), SIMDE_FLOAT32_C(    23.82), SIMDE_FLOAT32_C(     5.86),
        SIMDE_FLOAT32_C(    26.46), SIMDE_FLOAT32_C(   -18.80), SIMDE_FLOAT32_C(    27.59), SIMDE_FLOAT32_C(    44.06) },
      { SIMDE_FLOAT32_C(   -47.40), SIMDE_FLOAT32_C(    19.10), SIMDE_FLOAT32_C(   -26.98), SIMDE_FLOAT32_C(    25.94),
        SIMDE_FLOAT32_C(   -39.45), SIMDE_FLOAT32_C(    -1.04), SIMDE_FLOAT32_C(   -42.00), SIMDE_FLOAT32_C(    27.82) },
      { SIMDE_FLOAT32_C(    36.24), SIMDE_FLOAT32_C(   -19.56), SIMDE_FLOAT32_C(    32.09), SIMDE_FLOAT32_C(    -1.28),
        SIMDE_FLOAT32_C(    -7.67), SIMDE_FLOAT32_C(   -33.16), SIMDE_FLOAT32_C(    41.02), SIMDE_FLOAT32_C(    15.80) },
      { SIMDE_FLOAT32_C(7872182784.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-28871237596213638771197375152128.00), SIMDE_FLOAT32_C(   -27.09),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   481.12) } },
    { UINT8_C(160),
      { SIMDE_FLOAT32_C(   -49.72), SIMDE_FLOAT32_C(   -27.29), SIMDE_FLOAT32_C(   -14.35), SIMDE_FLOAT32_C(   -18.06),
        SIMDE_FLOAT32_C(    -9.77), SIMDE_FLOAT32_C(   -32.07), SIMDE_FLOAT32_C(   -47.00), SIMDE_FLOAT32_C(   -21.31) },
      { SIMDE_FLOAT32_C(    23.78), SIMDE_FLOAT32_C(    36.87), SIMDE_FLOAT32_C(     1.58), SIMDE_FLOAT32_C(   -42.96),
        SIMDE_FLOAT32_C(   -31.56), SIMDE_FLOAT32_C(    -9.50), SIMDE_FLOAT32_C(   -40.14), SIMDE_FLOAT32_C(    -7.65) },
      { SIMDE_FLOAT32_C(   -21.68), SIMDE_FLOAT32_C(    45.79), SIMDE_FLOAT32_C(    -0.46), SIMDE_FLOAT32_C(    48.89),
        SIMDE_FLOAT32_C(   -27.56), SIMDE_FLOAT32_C(   -18.60), SIMDE_FLOAT32_C(    40.56), SIMDE_FLOAT32_C(   -24.97) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   143.68), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(7684751360.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 tmp, src, r;
    simde__m256bh a, b;

    src = simde_mm256_loadu_ps(test_vec[i].src);

    tmp = simde_mm256_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm256_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm256_maskz_dpbf16_ps(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m256)];
  simde_test_x86_random_f32x8_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m256bh a = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 0, values));
    simde__m256bh b = HEDLEY_REINTERPRET_CAST(simde__m256bh, simde_test_x86_random_extract_f32x8(i, 2, 1, values));
    simde__m256 r = simde_mm256_maskz_dpbf16_ps(k, src, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, HEDLEY_REINTERPRET_CAST(simde__m256, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    -4.44), SIMDE_FLOAT32_C(    40.05), SIMDE_FLOAT32_C(    12.00), SIMDE_FLOAT32_C(    39.47),
        SIMDE_FLOAT32_C(    11.52), SIMDE_FLOAT32_C(   -31.72), SIMDE_FLOAT32_C(    49.75), SIMDE_FLOAT32_C(   -30.71),
        SIMDE_FLOAT32_C(     3.12), SIMDE_FLOAT32_C(   -12.10), SIMDE_FLOAT32_C(    39.10), SIMDE_FLOAT32_C(     8.78),
        SIMDE_FLOAT32_C(   -20.18), SIMDE_FLOAT32_C(   -32.50), SIMDE_FLOAT32_C(     2.81), SIMDE_FLOAT32_C(    -9.14) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -43.59),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -16.76),
        SIMDE_FLOAT32_C(   -26.37), SIMDE_FLOAT32_C(    48.72), SIMDE_FLOAT32_C(   -46.46), SIMDE_FLOAT32_C(    22.60),
        SIMDE_FLOAT32_C(   -14.26), SIMDE_FLOAT32_C(   -33.63), SIMDE_FLOAT32_C(     8.09), SIMDE_FLOAT32_C(    25.18),
        SIMDE_FLOAT32_C(   -22.07), SIMDE_FLOAT32_C(    42.28), SIMDE_FLOAT32_C(    -2.69), SIMDE_FLOAT32_C(    16.71) },
      { SIMDE_FLOAT32_C(    48.18),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    44.57),
        SIMDE_FLOAT32_C(    31.61), SIMDE_FLOAT32_C(   -25.05), SIMDE_FLOAT32_C(    49.98), SIMDE_FLOAT32_C(    18.38),
        SIMDE_FLOAT32_C(     7.25), SIMDE_FLOAT32_C(    30.69), SIMDE_FLOAT32_C(   -33.02), SIMDE_FLOAT32_C(    22.01),
        SIMDE_FLOAT32_C(    37.39), SIMDE_FLOAT32_C(   -47.43), SIMDE_FLOAT32_C(   -36.63), SIMDE_FLOAT32_C(   -22.09) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -705.91),
             SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   382.73),
        SIMDE_FLOAT32_C(  -100.19), SIMDE_FLOAT32_C( -1038.04), SIMDE_FLOAT32_C(  4918.54), SIMDE_FLOAT32_C(  5707.03),
        SIMDE_FLOAT32_C(  -839.68), SIMDE_FLOAT32_C( -2028.81), SIMDE_FLOAT32_C(   100.90), SIMDE_FLOAT32_C(  -374.89) } },
    { { SIMDE_FLOAT32_C(     5.69), SIMDE_FLOAT32_C(    47.63), SIMDE_FLOAT32_C(   -46.05), SIMDE_FLOAT32_C(    37.97),
        SIMDE_FLOAT32_C(    25.96), SIMDE_FLOAT32_C(    45.47), SIMDE_FLOAT32_C(     9.16), SIMDE_FLOAT32_C(    16.69),
        SIMDE_FLOAT32_C(    12.15), SIMDE_FLOAT32_C(    45.50), SIMDE_FLOAT32_C(   -23.77), SIMDE_FLOAT32_C(   -14.89),
        SIMDE_FLOAT32_C(     2.59), SIMDE_FLOAT32_C(    -4.17), SIMDE_FLOAT32_C(    22.38), SIMDE_FLOAT32_C(    48.14) },
      { SIMDE_FLOAT32_C(   -41.02), SIMDE_FLOAT32_C(    -9.86), SIMDE_FLOAT32_C(    11.15), SIMDE_FLOAT32_C(   -17.39),
        SIMDE_FLOAT32_C(   -11.14), SIMDE_FLOAT32_C(    14.70), SIMDE_FLOAT32_C(   -44.78), SIMDE_FLOAT32_C(    24.60),
        SIMDE_FLOAT32_C(    31.06), SIMDE_FLOAT32_C(    13.31), SIMDE_FLOAT32_C(    -0.22), SIMDE_FLOAT32_C(   -41.01),
        SIMDE_FLOAT32_C(     5.59), SIMDE_FLOAT32_C(    47.09), SIMDE_FLOAT32_C(    25.70), SIMDE_FLOAT32_C(     3.76) },
      { SIMDE_FLOAT32_C(   -25.07), SIMDE_FLOAT32_C(    36.83), SIMDE_FLOAT32_C(    -1.67), SIMDE_FLOAT32_C(   -43.46),
        SIMDE_FLOAT32_C(   -38.22), SIMDE_FLOAT32_C(    -1.70), SIMDE_FLOAT32_C(    24.92), SIMDE_FLOAT32_C(    19.03),
        SIMDE_FLOAT32_C(   -21.01), SIMDE_FLOAT32_C(    41.90), SIMDE_FLOAT32_C(    -8.96), SIMDE_FLOAT32_C(   -33.62),
        SIMDE_FLOAT32_C(    44.47), SIMDE_FLOAT32_C(     4.41), SIMDE_FLOAT32_C(    -5.71), SIMDE_FLOAT32_C(   -46.55) },
      { SIMDE_FLOAT32_C(  1030.69), SIMDE_FLOAT32_C(-9059159769088.00), SIMDE_FLOAT32_C(-19414829202697828884807680.00), SIMDE_FLOAT32_C(   789.44),
        SIMDE_FLOAT32_C(-13567093877453619200.00), SIMDE_FLOAT32_C(    20.57), SIMDE_FLOAT32_C( -1103.99), SIMDE_FLOAT32_C(-6323358.00),
        SIMDE_FLOAT32_C(7402290688.00), SIMDE_FLOAT32_C(7872184832.00), SIMDE_FLOAT32_C(16951404882234471088128.00), SIMDE_FLOAT32_C(  6674.23),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   202.93), SIMDE_FLOAT32_C(  -123.36), SIMDE_FLOAT32_C(  -126.24) } },
    { { SIMDE_FLOAT32_C(   -14.11), SIMDE_FLOAT32_C(   -15.62), SIMDE_FLOAT32_C(    37.62), SIMDE_FLOAT32_C(    47.41),
        SIMDE_FLOAT32_C(     2.66), SIMDE_FLOAT32_C(    37.37), SIMDE_FLOAT32_C(   -33.31), SIMDE_FLOAT32_C(   -44.22),
        SIMDE_FLOAT32_C(   -24.74), SIMDE_FLOAT32_C(   -44.20), SIMDE_FLOAT32_C(    14.56), SIMDE_FLOAT32_C(     5.08),
        SIMDE_FLOAT32_C(   -26.71), SIMDE_FLOAT32_C(   -32.63), SIMDE_FLOAT32_C(    45.94), SIMDE_FLOAT32_C(    28.98) },
      { SIMDE_FLOAT32_C(    44.55), SIMDE_FLOAT32_C(   -44.56), SIMDE_FLOAT32_C(   -13.93), SIMDE_FLOAT32_C(   -16.59),
        SIMDE_FLOAT32_C(    20.14), SIMDE_FLOAT32_C(    -8.72), SIMDE_FLOAT32_C(   -41.99), SIMDE_FLOAT32_C(     1.20),
        SIMDE_FLOAT32_C(   -45.41), SIMDE_FLOAT32_C(     7.79), SIMDE_FLOAT32_C(    10.19), SIMDE_FLOAT32_C(    10.18),
        SIMDE_FLOAT32_C(     4.88), SIMDE_FLOAT32_C(   -14.11), SIMDE_FLOAT32_C(   -36.06), SIMDE_FLOAT32_C(    29.81) },
      { SIMDE_FLOAT32_C(   -27.28), SIMDE_FLOAT32_C(    12.27), SIMDE_FLOAT32_C(    36.34), SIMDE_FLOAT32_C(   -15.50),
        SIMDE_FLOAT32_C(   -39.42), SIMDE_FLOAT32_C(    11.26), SIMDE_FLOAT32_C(   -46.47), SIMDE_FLOAT32_C(   -10.43),
        SIMDE_FLOAT32_C(     3.16), SIMDE_FLOAT32_C(    -5.43), SIMDE_FLOAT32_C(     5.95), SIMDE_FLOAT32_C(    -2.37),
        SIMDE_FLOAT32_C(    48.98), SIMDE_FLOAT32_C(   -49.76), SIMDE_FLOAT32_C(     1.08), SIMDE_FLOAT32_C(    43.53) },
      { SIMDE_FLOAT32_C( -1226.73), SIMDE_FLOAT32_C(7454850560.00), SIMDE_FLOAT32_C(-43874908454619293461082693981909811200.00), SIMDE_FLOAT32_C(   303.16),
        SIMDE_FLOAT32_C(  -787.25), SIMDE_FLOAT32_C(   -60.36),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -56.62),
        SIMDE_FLOAT32_C(  -167.56), SIMDE_FLOAT32_C(-6369878.50), SIMDE_FLOAT32_C(    75.05), SIMDE_FLOAT32_C(7759462400.00),
        SIMDE_FLOAT32_C(-8782671249408.00), SIMDE_FLOAT32_C(   666.98), SIMDE_FLOAT32_C(     7.13), SIMDE_FLOAT32_C(11379945347481600.00) } },
    { { SIMDE_FLOAT32_C(   -35.00), SIMDE_FLOAT32_C(    49.89), SIMDE_FLOAT32_C(    16.95), SIMDE_FLOAT32_C(    40.96),
        SIMDE_FLOAT32_C(    45.35), SIMDE_FLOAT32_C(   -23.89), SIMDE_FLOAT32_C(     7.65), SIMDE_FLOAT32_C(     7.50),
        SIMDE_FLOAT32_C(   -28.39), SIMDE_FLOAT32_C(    33.87), SIMDE_FLOAT32_C(    42.61), SIMDE_FLOAT32_C(    24.20),
        SIMDE_FLOAT32_C(   -20.29), SIMDE_FLOAT32_C(    15.00), SIMDE_FLOAT32_C(    22.34), SIMDE_FLOAT32_C(    15.59) },
      { SIMDE_FLOAT32_C(   -44.31), SIMDE_FLOAT32_C(    37.15), SIMDE_FLOAT32_C(   -23.06), SIMDE_FLOAT32_C(    25.83),
        SIMDE_FLOAT32_C(   -21.57), SIMDE_FLOAT32_C(   -15.05), SIMDE_FLOAT32_C(   -22.97), SIMDE_FLOAT32_C(   -16.98),
        SIMDE_FLOAT32_C(    42.74), SIMDE_FLOAT32_C(    37.22), SIMDE_FLOAT32_C(    43.20), SIMDE_FLOAT32_C(    -2.38),
        SIMDE_FLOAT32_C(   -26.89), SIMDE_FLOAT32_C(   -42.85), SIMDE_FLOAT32_C(   -22.57), SIMDE_FLOAT32_C(    -4.17) },
      { SIMDE_FLOAT32_C(    19.42), SIMDE_FLOAT32_C(   -36.23), SIMDE_FLOAT32_C(    30.33), SIMDE_FLOAT32_C(    29.99),
        SIMDE_FLOAT32_C(    25.03), SIMDE_FLOAT32_C(    33.86), SIMDE_FLOAT32_C(   -30.44), SIMDE_FLOAT32_C(   -21.81),
        SIMDE_FLOAT32_C(   -21.57), SIMDE_FLOAT32_C(    25.52), SIMDE_FLOAT32_C(    25.82), SIMDE_FLOAT32_C(   -22.59),
        SIMDE_FLOAT32_C(    25.76), SIMDE_FLOAT32_C(   -23.09), SIMDE_FLOAT32_C(   -29.06), SIMDE_FLOAT32_C(    31.44) },
      { SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(  3838.39), SIMDE_FLOAT32_C(-13616351998377984000.00), SIMDE_FLOAT32_C(7496008704.00),
        SIMDE_FLOAT32_C(  -492.15), SIMDE_FLOAT32_C(-43641255095985226217798821647094906880.00), SIMDE_FLOAT32_C(   702.48),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(  4420.36), SIMDE_FLOAT32_C(-6296622.50), SIMDE_FLOAT32_C(  1149.86), SIMDE_FLOAT32_C(-6343602.50),
        SIMDE_FLOAT32_C(  -712.32), SIMDE_FLOAT32_C(-13595241375124684800.00), SIMDE_FLOAT32_C(-6335325.00), SIMDE_FLOAT32_C(  -114.81) } },
    { { SIMDE_FLOAT32_C(    49.37), SIMDE_FLOAT32_C(     9.96), SIMDE_FLOAT32_C(    13.00), SIMDE_FLOAT32_C(     2.04),
        SIMDE_FLOAT32_C(    -2.68), SIMDE_FLOAT32_C(    29.69), SIMDE_FLOAT32_C(     7.82), SIMDE_FLOAT32_C(    22.58),
        SIMDE_FLOAT32_C(    35.49), SIMDE_FLOAT32_C(   -27.63), SIMDE_FLOAT32_C(   -22.33), SIMDE_FLOAT32_C(   -41.22),
        SIMDE_FLOAT32_C(   -10.25), SIMDE_FLOAT32_C(   -26.39), SIMDE_FLOAT32_C(    37.76), SIMDE_FLOAT32_C(     4.74) },
      { SIMDE_FLOAT32_C(   -35.94), SIMDE_FLOAT32_C(    -2.12), SIMDE_FLOAT32_C(     7.27), SIMDE_FLOAT32_C(    -7.51),
        SIMDE_FLOAT32_C(    32.83), SIMDE_FLOAT32_C(    34.30), SIMDE_FLOAT32_C(    25.52), SIMDE_FLOAT32_C(    25.57),
        SIMDE_FLOAT32_C(    21.52), SIMDE_FLOAT32_C(    18.72), SIMDE_FLOAT32_C(   -26.81), SIMDE_FLOAT32_C(    44.63),
        SIMDE_FLOAT32_C(    25.87), SIMDE_FLOAT32_C(     0.61), SIMDE_FLOAT32_C(    -9.53), SIMDE_FLOAT32_C(    -4.72) },
      { SIMDE_FLOAT32_C(    14.39), SIMDE_FLOAT32_C(   -29.20), SIMDE_FLOAT32_C(   -24.72), SIMDE_FLOAT32_C(   -10.58),
        SIMDE_FLOAT32_C(   -45.34), SIMDE_FLOAT32_C(    -5.16), SIMDE_FLOAT32_C(    17.61), SIMDE_FLOAT32_C(   -16.90),
        SIMDE_FLOAT32_C(   -29.64), SIMDE_FLOAT32_C(    -6.56), SIMDE_FLOAT32_C(    10.51), SIMDE_FLOAT32_C(    46.11),
        SIMDE_FLOAT32_C(    20.34), SIMDE_FLOAT32_C(    31.45), SIMDE_FLOAT32_C(    27.56), SIMDE_FLOAT32_C(    34.40) },
      { SIMDE_FLOAT32_C(  -468.74), SIMDE_FLOAT32_C(    71.40), SIMDE_FLOAT32_C(  -165.53), SIMDE_FLOAT32_C(11287586370748416.00),
        SIMDE_FLOAT32_C(24108398694754935001990561792.00), SIMDE_FLOAT32_C(  -146.91), SIMDE_FLOAT32_C(-6297146.00), SIMDE_FLOAT32_C(  -407.73),
        SIMDE_FLOAT32_C(  -601.45), SIMDE_FLOAT32_C(22992560163250632273736761344.00), SIMDE_FLOAT32_C(15953551319997245030400.00), SIMDE_FLOAT32_C(  2005.78),
        SIMDE_FLOAT32_C(24752756156609532352108953600.00), SIMDE_FLOAT32_C(    -7.27),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -156.88) } },
    { { SIMDE_FLOAT32_C(   -26.51), SIMDE_FLOAT32_C(     4.71), SIMDE_FLOAT32_C(    -4.30), SIMDE_FLOAT32_C(   -31.16),
        SIMDE_FLOAT32_C(    30.82), SIMDE_FLOAT32_C(   -46.65), SIMDE_FLOAT32_C(    26.34), SIMDE_FLOAT32_C(   -47.57),
        SIMDE_FLOAT32_C(    37.22), SIMDE_FLOAT32_C(    18.96), SIMDE_FLOAT32_C(    26.63), SIMDE_FLOAT32_C(   -33.07),
        SIMDE_FLOAT32_C(   -16.05), SIMDE_FLOAT32_C(    -1.04), SIMDE_FLOAT32_C(    32.52), SIMDE_FLOAT32_C(   -16.67) },
      { SIMDE_FLOAT32_C(   -20.68), SIMDE_FLOAT32_C(   -15.17), SIMDE_FLOAT32_C(   -23.11), SIMDE_FLOAT32_C(   -37.85),
        SIMDE_FLOAT32_C(   -30.87), SIMDE_FLOAT32_C(   -47.59), SIMDE_FLOAT32_C(    37.72), SIMDE_FLOAT32_C(    40.65),
        SIMDE_FLOAT32_C(    21.13), SIMDE_FLOAT32_C(   -39.10), SIMDE_FLOAT32_C(    35.28), SIMDE_FLOAT32_C(    -3.01),
        SIMDE_FLOAT32_C(    11.52), SIMDE_FLOAT32_C(   -24.26), SIMDE_FLOAT32_C(    42.28), SIMDE_FLOAT32_C(   -24.09) },
      { SIMDE_FLOAT32_C(    -3.46), SIMDE_FLOAT32_C(   -32.45), SIMDE_FLOAT32_C(    15.33), SIMDE_FLOAT32_C(     1.21),
        SIMDE_FLOAT32_C(    12.39), SIMDE_FLOAT32_C(   -17.06), SIMDE_FLOAT32_C(    34.30), SIMDE_FLOAT32_C(    32.75),
        SIMDE_FLOAT32_C(    26.38), SIMDE_FLOAT32_C(    -5.19), SIMDE_FLOAT32_C(    28.87), SIMDE_FLOAT32_C(    -3.28),
        SIMDE_FLOAT32_C(   -23.74), SIMDE_FLOAT32_C(     6.42), SIMDE_FLOAT32_C(   -18.87), SIMDE_FLOAT32_C(     5.58) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  5873.74), SIMDE_FLOAT32_C(-20542294200482956679577600.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(-29088496073108223009442171453440.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-9609989324800.00), SIMDE_FLOAT32_C(  1278.81),
        SIMDE_FLOAT32_C(   594.39), SIMDE_FLOAT32_C(   221.28), SIMDE_FLOAT32_C(-9631464161280.00), SIMDE_FLOAT32_C(7496007680.00),
        SIMDE_FLOAT32_C(-40743953448922792401078804695390093312.00), SIMDE_FLOAT32_C(  4989.11), SIMDE_FLOAT32_C(-9631464161280.00), SIMDE_FLOAT32_C(  -150.17) } },
    { { SIMDE_FLOAT32_C(   -41.08), SIMDE_FLOAT32_C(    -4.48), SIMDE_FLOAT32_C(    35.36), SIMDE_FLOAT32_C(     6.24),
        SIMDE_FLOAT32_C(   -24.78), SIMDE_FLOAT32_C(    -6.82), SIMDE_FLOAT32_C(   -21.18), SIMDE_FLOAT32_C(   -39.29),
        SIMDE_FLOAT32_C(    15.56), SIMDE_FLOAT32_C(     6.49), SIMDE_FLOAT32_C(   -30.51), SIMDE_FLOAT32_C(   -44.70),
        SIMDE_FLOAT32_C(    30.10), SIMDE_FLOAT32_C(   -42.75), SIMDE_FLOAT32_C(    10.04), SIMDE_FLOAT32_C(   -46.41) },
      { SIMDE_FLOAT32_C(    41.25), SIMDE_FLOAT32_C(     8.02), SIMDE_FLOAT32_C(    17.73), SIMDE_FLOAT32_C(   -39.62),
        SIMDE_FLOAT32_C(    10.43), SIMDE_FLOAT32_C(     5.45), SIMDE_FLOAT32_C(   -48.98), SIMDE_FLOAT32_C(   -18.44),
        SIMDE_FLOAT32_C(    16.35), SIMDE_FLOAT32_C(    36.30), SIMDE_FLOAT32_C(    28.55), SIMDE_FLOAT32_C(   -22.13),
        SIMDE_FLOAT32_C(   -37.96), SIMDE_FLOAT32_C(    20.83), SIMDE_FLOAT32_C(     3.78), SIMDE_FLOAT32_C(     8.58) },
      { SIMDE_FLOAT32_C(    38.38), SIMDE_FLOAT32_C(   -30.89), SIMDE_FLOAT32_C(   -40.21), SIMDE_FLOAT32_C(     0.77),
        SIMDE_FLOAT32_C(     2.05), SIMDE_FLOAT32_C(    44.09), SIMDE_FLOAT32_C(   -16.48), SIMDE_FLOAT32_C(   -21.57),
        SIMDE_FLOAT32_C(   -11.10), SIMDE_FLOAT32_C(   -37.61), SIMDE_FLOAT32_C(    25.16), SIMDE_FLOAT32_C(    15.16),
        SIMDE_FLOAT32_C(    18.81), SIMDE_FLOAT32_C(   -43.72), SIMDE_FLOAT32_C(   -29.26), SIMDE_FLOAT32_C(    10.07) },
      { SIMDE_FLOAT32_C(  1536.73), SIMDE_FLOAT32_C(  -251.48), SIMDE_FLOAT32_C(23022783308740998003104415744.00), SIMDE_FLOAT32_C(11379945347481600.00),
        SIMDE_FLOAT32_C(-9609989324800.00),      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   355.77),
        SIMDE_FLOAT32_C(  -164.21), SIMDE_FLOAT32_C(16922581844619299913728.00), SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(  -379.34),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  4429.62), SIMDE_FLOAT32_C(  -104.18), SIMDE_FLOAT32_C(    39.75) } },
    { { SIMDE_FLOAT32_C(    11.97), SIMDE_FLOAT32_C(   -44.25), SIMDE_FLOAT32_C(   -27.57), SIMDE_FLOAT32_C(    -7.21),
        SIMDE_FLOAT32_C(   -40.91), SIMDE_FLOAT32_C(    48.77), SIMDE_FLOAT32_C(    -4.79), SIMDE_FLOAT32_C(    46.32),
        SIMDE_FLOAT32_C(    17.73), SIMDE_FLOAT32_C(   -28.16), SIMDE_FLOAT32_C(   -36.75), SIMDE_FLOAT32_C(   -48.31),
        SIMDE_FLOAT32_C(    20.80), SIMDE_FLOAT32_C(    45.77), SIMDE_FLOAT32_C(   -14.99), SIMDE_FLOAT32_C(    29.72) },
      { SIMDE_FLOAT32_C(    14.30), SIMDE_FLOAT32_C(    38.47), SIMDE_FLOAT32_C(    20.44), SIMDE_FLOAT32_C(   -25.27),
        SIMDE_FLOAT32_C(    -6.08), SIMDE_FLOAT32_C(    21.47), SIMDE_FLOAT32_C(     6.29), SIMDE_FLOAT32_C(   -39.73),
        SIMDE_FLOAT32_C(     7.77), SIMDE_FLOAT32_C(   -15.17), SIMDE_FLOAT32_C(   -11.85), SIMDE_FLOAT32_C(    19.81),
        SIMDE_FLOAT32_C(   -44.34), SIMDE_FLOAT32_C(    41.93), SIMDE_FLOAT32_C(   -21.60), SIMDE_FLOAT32_C(    44.04) },
      { SIMDE_FLOAT32_C(   -38.96), SIMDE_FLOAT32_C(   -11.81), SIMDE_FLOAT32_C(    -5.19), SIMDE_FLOAT32_C(    13.09),
        SIMDE_FLOAT32_C(   -17.72), SIMDE_FLOAT32_C(    28.34), SIMDE_FLOAT32_C(    41.52), SIMDE_FLOAT32_C(    21.19),
        SIMDE_FLOAT32_C(    40.73), SIMDE_FLOAT32_C(    16.68), SIMDE_FLOAT32_C(   -13.65), SIMDE_FLOAT32_C(     9.54),
        SIMDE_FLOAT32_C(    22.97), SIMDE_FLOAT32_C(     7.08), SIMDE_FLOAT32_C(   -30.39), SIMDE_FLOAT32_C(   -12.73) },
      { SIMDE_FLOAT32_C(16308074682663850475520.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -133.27), SIMDE_FLOAT32_C(11089674277748736.00),
        SIMDE_FLOAT32_C(    65.94), SIMDE_FLOAT32_C(   652.62), SIMDE_FLOAT32_C(   255.88), SIMDE_FLOAT32_C(  -788.12),
        SIMDE_FLOAT32_C(7496008192.00), SIMDE_FLOAT32_C(-20329787708753822644961280.00), SIMDE_FLOAT32_C(   119.87), SIMDE_FLOAT32_C(-13616351998377984000.00),
        SIMDE_FLOAT32_C(-13604811524332847104.00), SIMDE_FLOAT32_C(   340.63), SIMDE_FLOAT32_C(   638.07), SIMDE_FLOAT32_C(  -528.53) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 tmp, src, r;
    simde__m512bh a, b;

    src = simde_mm512_loadu_ps(test_vec[i].src);

    tmp = simde_mm512_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm512_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm512_dpbf16_ps(src, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_f32x16_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m512bh a = HEDLEY_REINTERPRET_CAST(simde__m512bh, simde_test_x86_random_extract_f32x16(i, 2, 0, values));
    simde__m512bh b = HEDLEY_REINTERPRET_CAST(simde__m512bh, simde_test_x86_random_extract_f32x16(i, 2, 1, values));
    simde__m512 r = simde_mm512_dpbf16_ps(src, a, b);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, HEDLEY_REINTERPRET_CAST(simde__m512, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, HEDLEY_REINTERPRET_CAST(simde__m512, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    20.94), SIMDE_FLOAT32_C(     8.14), SIMDE_FLOAT32_C(    -3.05), SIMDE_FLOAT32_C(    42.30),
        SIMDE_FLOAT32_C(    12.00), SIMDE_FLOAT32_C(    22.72), SIMDE_FLOAT32_C(    19.08), SIMDE_FLOAT32_C(   -18.36),
        SIMDE_FLOAT32_C(   -34.01), SIMDE_FLOAT32_C(    21.71), SIMDE_FLOAT32_C(   -16.85), SIMDE_FLOAT32_C(     1.39),
        SIMDE_FLOAT32_C(    30.00), SIMDE_FLOAT32_C(    10.35), SIMDE_FLOAT32_C(    29.10), SIMDE_FLOAT32_C(   -14.63) },
      UINT16_C(33291),
      { -INT32_C(  1140163072), -INT32_C(   774537728),  INT32_C(  1240748366), -INT32_C(   796143464), -INT32_C(   794246065),  INT32_C(  1368608967),  INT32_C(  1327649281),  INT32_C(  1321780503),
         INT32_C(  1361138239), -INT32_C(   790673148), -INT32_C(   792639037),  INT32_C(  1341968817), -INT32_C(   804729686), -INT32_C(  1000255374), -INT32_C(   878096122),  INT32_C(  1259163922) },
      {  INT32_C(  2113949750),  INT32_C(  1317502464),  INT32_C(  1336660243),  INT32_C(  1159352569),  INT32_C(  1325420909),  INT32_C(  1362015478),  INT32_C(  1368606344),  INT32_C(  1182616741),
        -INT32_C(   849784716), -INT32_C(  1045541790),  INT32_C(  1300285622),  INT32_C(  1300024634), -INT32_C(   798273288),  INT32_C(  1333579790), -INT32_C(   784549581), -INT32_C(   868235789) },
      {      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -3.05), SIMDE_FLOAT32_C(-681809025155618308096.00),
        SIMDE_FLOAT32_C(    12.00), SIMDE_FLOAT32_C(    22.72), SIMDE_FLOAT32_C(    19.08), SIMDE_FLOAT32_C(   -18.36),
        SIMDE_FLOAT32_C(   -34.01), SIMDE_FLOAT32_C(    21.71), SIMDE_FLOAT32_C(   -16.85), SIMDE_FLOAT32_C(     1.39),
        SIMDE_FLOAT32_C(    30.00), SIMDE_FLOAT32_C(    10.35), SIMDE_FLOAT32_C(    29.10), SIMDE_FLOAT32_C(   -14.63) } },
    { { SIMDE_FLOAT32_C(    42.34), SIMDE_FLOAT32_C(   -18.34), SIMDE_FLOAT32_C(    30.85), SIMDE_FLOAT32_C(    -1.85),
        SIMDE_FLOAT32_C(    41.88), SIMDE_FLOAT32_C(   -38.97), SIMDE_FLOAT32_C(    17.64), SIMDE_FLOAT32_C(   -37.29),
        SIMDE_FLOAT32_C(    26.58), SIMDE_FLOAT32_C(    46.53), SIMDE_FLOAT32_C(     4.26), SIMDE_FLOAT32_C(    31.66),
        SIMDE_FLOAT32_C(   -24.68), SIMDE_FLOAT32_C(   -24.79), SIMDE_FLOAT32_C(   -10.21), SIMDE_FLOAT32_C(    22.28) },
      UINT16_C(29878),
      { -INT32_C(   791591526),  INT32_C(  1266733340),  INT32_C(  1377653060),  INT32_C(  1349701498),  INT32_C(  1291013818), -INT32_C(   870035775), -INT32_C(   999732430),  INT32_C(   665735421),
         INT32_C(  1198738957), -INT32_C(   798535194), -INT32_C(   840053469), -INT32_C(   810332009), -INT32_C(   776484730),  INT32_C(  1359630884), -INT32_C(   959459148),  INT32_C(  1283378860) },
      { -INT32_C(   865909591), -INT32_C(  1033778110),  INT32_C(  1109380265), -INT32_C(   784872344), -INT32_C(   787165494),  INT32_C(  1353238566), -INT32_C(   862436101), -INT32_C(   852112803),
        -INT32_C(   876261150), -INT32_C(   807418355), -INT32_C(   858437280), -INT32_C(   771044827), -INT32_C(   896283767), -INT32_C(  1050259136), -INT32_C(   799649917), -INT32_C(   878260137) },
      { SIMDE_FLOAT32_C(    42.34), SIMDE_FLOAT32_C(2129639673792823296.00), SIMDE_FLOAT32_C(-4661781967212118016.00), SIMDE_FLOAT32_C(    -1.85),
        SIMDE_FLOAT32_C(-7705377487454208000.00), SIMDE_FLOAT32_C(-969675041295826944.00), SIMDE_FLOAT32_C(    17.64), SIMDE_FLOAT32_C(-122953987287678976.00),
        SIMDE_FLOAT32_C(    26.58), SIMDE_FLOAT32_C(    46.53), SIMDE_FLOAT32_C(     4.26), SIMDE_FLOAT32_C(    31.66),
        SIMDE_FLOAT32_C(   -24.68), SIMDE_FLOAT32_C(   -24.79), SIMDE_FLOAT32_C(   -10.21), SIMDE_FLOAT32_C(    22.28) } },
    { { SIMDE_FLOAT32_C(    -5.00), SIMDE_FLOAT32_C(    36.59), SIMDE_FLOAT32_C(   -16.57), SIMDE_FLOAT32_C(    10.99),
        SIMDE_FLOAT32_C(     8.30), SIMDE_FLOAT32_C(    16.58), SIMDE_FLOAT32_C(   -37.62), SIMDE_FLOAT32_C(   -11.70),
        SIMDE_FLOAT32_C(   -23.07), SIMDE_FLOAT32_C(    41.48), SIMDE_FLOAT32_C(    23.67), SIMDE_FLOAT32_C(    19.84),
        SIMDE_FLOAT32_C(   -13.97), SIMDE_FLOAT32_C(    16.01), SIMDE_FLOAT32_C(   -48.50), SIMDE_FLOAT32_C(   -33.12) },
      UINT16_C(11115),
      { -INT32_C(  1089159050),  INT32_C(  1330139105), -INT32_C(   796601834), -INT32_C(   831106899), -INT32_C(   851784017),  INT32_C(  1326502100), -INT32_C(  1118680740), -INT32_C(  1291136685),
         INT32_C(  1031491620), -INT32_C(   971027309), -INT32_C(   780120063), -INT32_C(   803093394), -INT32_C(   902314204), -INT32_C(   825799901),  INT32_C(  1331904963), -INT32_C(   768915561) },
      { -INT32_C(   915157618), -INT32_C(   851685517),  INT32_C(  1280066038),  INT32_C(  1318077041),  INT32_C(  1263423945),  INT32_C(  1191199872),  INT32_C(  1240912023),  INT32_C(  1372442983),
         INT32_C(  1313198231),  INT32_C(  1370212572),  INT32_C(  1350258630), -INT32_C(   830222154),  INT32_C(  1319489189),  INT32_C(  1318306386), -INT32_C(   776845793),  INT32_C(  1346129597) },
      { SIMDE_FLOAT32_C(1145227136.00), SIMDE_FLOAT32_C(30117822508040192000.00), SIMDE_FLOAT32_C(   -16.57), SIMDE_FLOAT32_C(-1246369822485250048.00),
        SIMDE_FLOAT32_C(     8.30), SIMDE_FLOAT32_C(50027779063808.00), SIMDE_FLOAT32_C(-18262888137359360.00), SIMDE_FLOAT32_C(   -11.70),
        SIMDE_FLOAT32_C(   -23.07), SIMDE_FLOAT32_C(    41.48), SIMDE_FLOAT32_C(    23.67), SIMDE_FLOAT32_C(    19.84),
        SIMDE_FLOAT32_C(   -13.97), SIMDE_FLOAT32_C(    16.01), SIMDE_FLOAT32_C(   -48.50), SIMDE_FLOAT32_C(   -33.12) } },
    { { SIMDE_FLOAT32_C(   -22.09), SIMDE_FLOAT32_C(    31.80), SIMDE_FLOAT32_C(   -43.92), SIMDE_FLOAT32_C(   -45.51),
        SIMDE_FLOAT32_C(    28.33), SIMDE_FLOAT32_C(    10.35), SIMDE_FLOAT32_C(    36.14), SIMDE_FLOAT32_C(   -46.35),
        SIMDE_FLOAT32_C(    35.55), SIMDE_FLOAT32_C(   -24.06), SIMDE_FLOAT32_C(    25.93), SIMDE_FLOAT32_C(   -46.94),
        SIMDE_FLOAT32_C(   -22.27), SIMDE_FLOAT32_C(   -29.07), SIMDE_FLOAT32_C(    39.65), SIMDE_FLOAT32_C(    11.17) },
      UINT16_C(42646),
      {  INT32_C(  1187038840),  INT32_C(  1372639393),  INT32_C(  1275907716), -INT32_C(   814527055), -INT32_C(   844116787), -INT32_C(   974041395),  INT32_C(  1346392294), -INT32_C(   772683579),
         INT32_C(  1336887433), -INT32_C(   924036614), -INT32_C(   788771802),  INT32_C(  1358973709), -INT32_C(   790474602), -INT32_C(   953070572), -INT32_C(   960769964),  INT32_C(  1215548883) },
      { -INT32_C(   919940545), -INT32_C(   830257815), -INT32_C(   847916667), -INT32_C(   894515753), -INT32_C(   819444370), -INT32_C(   983281747), -INT32_C(   818556524),  INT32_C(  1261945298),
        -INT32_C(   988098045),  INT32_C(  1285673389),  INT32_C(  1286358275), -INT32_C(   937015231), -INT32_C(   833925272),  INT32_C(  1369460816), -INT32_C(   791065466),  INT32_C(  1283933133) },
      { SIMDE_FLOAT32_C(   -22.09), SIMDE_FLOAT32_C(-122714161811428474880.00), SIMDE_FLOAT32_C(79055765646396620800.00), SIMDE_FLOAT32_C(   -45.51),
        SIMDE_FLOAT32_C(1034420127094800384.00), SIMDE_FLOAT32_C(    10.35), SIMDE_FLOAT32_C(    36.14), SIMDE_FLOAT32_C(-1551736362233757696.00),
        SIMDE_FLOAT32_C(    35.55), SIMDE_FLOAT32_C(   -24.06), SIMDE_FLOAT32_C(    25.93), SIMDE_FLOAT32_C(   -46.94),
        SIMDE_FLOAT32_C(   -22.27), SIMDE_FLOAT32_C(   -29.07), SIMDE_FLOAT32_C(    39.65), SIMDE_FLOAT32_C(    11.17) } },
    { { SIMDE_FLOAT32_C(   -22.25), SIMDE_FLOAT32_C(    44.30), SIMDE_FLOAT32_C(    36.25), SIMDE_FLOAT32_C(     4.68),
        SIMDE_FLOAT32_C(    35.78), SIMDE_FLOAT32_C(     9.92), SIMDE_FLOAT32_C(   -25.48), SIMDE_FLOAT32_C(   -28.19),
        SIMDE_FLOAT32_C(   -24.07), SIMDE_FLOAT32_C(   -23.98), SIMDE_FLOAT32_C(   -11.31), SIMDE_FLOAT32_C(    -9.90),
        SIMDE_FLOAT32_C(   -30.60), SIMDE_FLOAT32_C(    16.60), SIMDE_FLOAT32_C(   -28.10), SIMDE_FLOAT32_C(   -24.52) },
      UINT16_C(50702),
      { -INT32_C(   787072225),  INT32_C(  1186812226), -INT32_C(   890910143),  INT32_C(  1365070188),  INT32_C(  1309034388),  INT32_C(  1249430075),  INT32_C(  1347703209),  INT32_C(  1374080424),
        -INT32_C(   863777505),  INT32_C(  1347505112), -INT32_C(   831270356),  INT32_C(  1334955505), -INT32_C(   790053949), -INT32_C(   803451311), -INT32_C(   852111613),  INT32_C(  1303793768) },
      {  INT32_C(  1322502593),  INT32_C(  1316998426), -INT32_C(   826158960),  INT32_C(  1296452794), -INT32_C(   781037085),  INT32_C(  1363921916),  INT32_C(  1236554018), -INT32_C(   816164623),
         INT32_C(  1161318764),  INT32_C(  1367396764), -INT32_C(   861253796), -INT32_C(   849129967), -INT32_C(  1218656282),  INT32_C(  1258931308), -INT32_C(   859025618), -INT32_C(   803616118) },
      { SIMDE_FLOAT32_C(   -22.25), SIMDE_FLOAT32_C(-8409320565684305920.00), SIMDE_FLOAT32_C(73264033171505152.00), SIMDE_FLOAT32_C(18494594819750363136.00),
        SIMDE_FLOAT32_C(    35.78), SIMDE_FLOAT32_C(     9.92), SIMDE_FLOAT32_C(   -25.48), SIMDE_FLOAT32_C(   -28.19),
        SIMDE_FLOAT32_C(   -24.07), SIMDE_FLOAT32_C(   -23.98), SIMDE_FLOAT32_C(   -11.31), SIMDE_FLOAT32_C(    -9.90),
        SIMDE_FLOAT32_C(   -30.60), SIMDE_FLOAT32_C(    16.60), SIMDE_FLOAT32_C(   -28.10), SIMDE_FLOAT32_C(   -24.52) } },
    { { SIMDE_FLOAT32_C(    35.83), SIMDE_FLOAT32_C(     7.22), SIMDE_FLOAT32_C(   -46.12), SIMDE_FLOAT32_C(    21.38),
        SIMDE_FLOAT32_C(    33.16), SIMDE_FLOAT32_C(    29.81), SIMDE_FLOAT32_C(    24.45), SIMDE_FLOAT32_C(   -39.11),
        SIMDE_FLOAT32_C(   -49.26), SIMDE_FLOAT32_C(    14.10), SIMDE_FLOAT32_C(    22.06), SIMDE_FLOAT32_C(    32.66),
        SIMDE_FLOAT32_C(   -37.95), SIMDE_FLOAT32_C(    49.81), SIMDE_FLOAT32_C(    26.96), SIMDE_FLOAT32_C(    48.30) },
      UINT16_C(63693),
      {  INT32_C(  1277284668), -INT32_C(   820489882),  INT32_C(  1242321136),  INT32_C(  1351831895), -INT32_C(   841986909),  INT32_C(  1221414716),  INT32_C(  1285443781),  INT32_C(  1340166028),
         INT32_C(  1349176980), -INT32_C(   774091167), -INT32_C(  1301884885),  INT32_C(  1214499995),  INT32_C(  1321882155),  INT32_C(  1325715146),  INT32_C(  1222758720), -INT32_C(   801287767) },
      {  INT32_C(  1355795951), -INT32_C(   800601565), -INT32_C(   857524122), -INT32_C(   809774604),  INT32_C(  1339246387), -INT32_C(   995733716),  INT32_C(  1215411118),  INT32_C(  1306381768),
        -INT32_C(   772553267),  INT32_C(  1232031396), -INT32_C(   784646047),  INT32_C(  1042927511), -INT32_C(   947367830),  INT32_C(  1365888282), -INT32_C(   834088455), -INT32_C(   849293037) },
      { SIMDE_FLOAT32_C(26467056875730894848.00), SIMDE_FLOAT32_C(     7.22), SIMDE_FLOAT32_C(-272988121333760.00), SIMDE_FLOAT32_C(-7684082216616186609664.00),
        SIMDE_FLOAT32_C(    33.16), SIMDE_FLOAT32_C(    29.81), SIMDE_FLOAT32_C(20442970587136.00), SIMDE_FLOAT32_C(1528760967259750400.00),
        SIMDE_FLOAT32_C(   -49.26), SIMDE_FLOAT32_C(    14.10), SIMDE_FLOAT32_C(    22.06), SIMDE_FLOAT32_C(    32.66),
        SIMDE_FLOAT32_C(   -37.95), SIMDE_FLOAT32_C(    49.81), SIMDE_FLOAT32_C(    26.96), SIMDE_FLOAT32_C(    48.30) } },
    { { SIMDE_FLOAT32_C(     8.22), SIMDE_FLOAT32_C(    29.01), SIMDE_FLOAT32_C(    34.56), SIMDE_FLOAT32_C(    34.16),
        SIMDE_FLOAT32_C(   -44.97), SIMDE_FLOAT32_C(   -26.76), SIMDE_FLOAT32_C(   -25.75), SIMDE_FLOAT32_C(   -25.57),
        SIMDE_FLOAT32_C(    39.84), SIMDE_FLOAT32_C(    -3.85), SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(    10.92),
        SIMDE_FLOAT32_C(    -3.62), SIMDE_FLOAT32_C(   -14.25), SIMDE_FLOAT32_C(   -31.86), SIMDE_FLOAT32_C(     0.27) },
      UINT16_C(51548),
      { -INT32_C(  1044131690),  INT32_C(  1257227704), -INT32_C(  1028108572), -INT32_C(   878882786),  INT32_C(  1238551940),  INT32_C(  1324109704), -INT32_C(   782184609),  INT32_C(  1264336015),
        -INT32_C(   845950700),  INT32_C(  1238027803), -INT32_C(   993473773), -INT32_C(   818491236), -INT32_C(   951562058),  INT32_C(  1358876785), -INT32_C(   829797275),  INT32_C(  1337642980) },
      {  INT32_C(  1247497535), -INT32_C(  1110588104), -INT32_C(   846081771), -INT32_C(   899919830),  INT32_C(  1253593324), -INT32_C(   788213663),  INT32_C(  1275546908),  INT32_C(  1333022247),
        -INT32_C(   767929990), -INT32_C(   854210484),  INT32_C(  1149813908), -INT32_C(   868664668),  INT32_C(  1269125608),  INT32_C(  1265290941), -INT32_C(   935046940),  INT32_C(  1225704517) },
      { SIMDE_FLOAT32_C(     8.22), SIMDE_FLOAT32_C(    29.01), SIMDE_FLOAT32_C(-76498143270515245056.00), SIMDE_FLOAT32_C(120966756359915700224.00),
        SIMDE_FLOAT32_C(-8768498029129891840.00), SIMDE_FLOAT32_C(   -26.76), SIMDE_FLOAT32_C(-2739947792045703168.00), SIMDE_FLOAT32_C(   -25.57),
        SIMDE_FLOAT32_C(    39.84), SIMDE_FLOAT32_C(    -3.85), SIMDE_FLOAT32_C(    -0.09), SIMDE_FLOAT32_C(    10.92),
        SIMDE_FLOAT32_C(    -3.62), SIMDE_FLOAT32_C(   -14.25), SIMDE_FLOAT32_C(   -31.86), SIMDE_FLOAT32_C(     0.27) } },
    { { SIMDE_FLOAT32_C(   -19.92), SIMDE_FLOAT32_C(    31.58), SIMDE_FLOAT32_C(   -37.82), SIMDE_FLOAT32_C(   -19.18),
        SIMDE_FLOAT32_C(    -4.32), SIMDE_FLOAT32_C(    34.24), SIMDE_FLOAT32_C(   -36.51), SIMDE_FLOAT32_C(     7.73),
        SIMDE_FLOAT32_C(    34.04), SIMDE_FLOAT32_C(    40.45), SIMDE_FLOAT32_C(     6.03), SIMDE_FLOAT32_C(   -11.47),
        SIMDE_FLOAT32_C(     3.20), SIMDE_FLOAT32_C(   -35.74), SIMDE_FLOAT32_C(   -32.46), SIMDE_FLOAT32_C(   -12.25) },
      UINT16_C(60967),
      {  INT32_C(  1360056762), -INT32_C(   795881173),  INT32_C(  1363136497), -INT32_C(   783533466),  INT32_C(  1273185644), -INT32_C(   838152176),  INT32_C(  1363463304), -INT32_C(   837496437),
        -INT32_C(  1042525878), -INT32_C(   903789220), -INT32_C(   780479987),  INT32_C(  1377520950),  INT32_C(  1367100766),  INT32_C(  1229867734), -INT32_C(   787231918), -INT32_C(   918761646) },
      { -INT32_C(   853061059), -INT32_C(   805944801), -INT32_C(   775631063),  INT32_C(  1320341007), -INT32_C(   960803608), -INT32_C(   770649620), -INT32_C(   784872626), -INT32_C(   845951565),
         INT32_C(  1343374687),  INT32_C(  1190677434), -INT32_C(   891662120),  INT32_C(  1226589647), -INT32_C(   811479820),  INT32_C(  1271254859), -INT32_C(   935801529), -INT32_C(   850538083) },
      { SIMDE_FLOAT32_C(-20271670196714487152640.00), SIMDE_FLOAT32_C(158427627691639308288.00), SIMDE_FLOAT32_C(-5372167792154843807744.00), SIMDE_FLOAT32_C(   -19.18),
        SIMDE_FLOAT32_C(    -4.32), SIMDE_FLOAT32_C(1313898169687577985024.00), SIMDE_FLOAT32_C(   -36.51), SIMDE_FLOAT32_C(     7.73),
        SIMDE_FLOAT32_C(    34.04), SIMDE_FLOAT32_C(    40.45), SIMDE_FLOAT32_C(     6.03), SIMDE_FLOAT32_C(   -11.47),
        SIMDE_FLOAT32_C(     3.20), SIMDE_FLOAT32_C(   -35.74), SIMDE_FLOAT32_C(   -32.46), SIMDE_FLOAT32_C(   -12.25) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src, r;
    simde__m512bh a, b;

    src = simde_mm512_loadu_ps(test_vec[i].src);

    a = HEDLEY_REINTERPRET_CAST(simde__m512bh, simde_mm512_loadu_epi32(test_vec[i].a));
    b = HEDLEY_REINTERPRET_CAST(simde__m512bh, simde_mm512_loadu_epi32(test_vec[i].b));

    r = simde_mm512_mask_dpbf16_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_bfloat16 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_bf16x32_full(8, 2, values, simde_bfloat16_from_float32(-50.0f), simde_bfloat16_from_float32(50.0f), SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512bh a = simde_test_x86_random_extract_bf16x32(i, 2, 0, values);
    simde__m512bh b = simde_test_x86_random_extract_bf16x32(i, 2, 1, values);
    simde__m512 r = simde_mm512_mask_dpbf16_ps(src, k, a, b);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, HEDLEY_REINTERPRET_CAST(simde__m512i, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, HEDLEY_REINTERPRET_CAST(simde__m512i, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_dpbf16_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const simde_float32 src[16];
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { UINT16_C( 6181),
      { SIMDE_FLOAT32_C(   -19.40), SIMDE_FLOAT32_C(   -36.46), SIMDE_FLOAT32_C(   -22.81), SIMDE_FLOAT32_C(     8.92),
        SIMDE_FLOAT32_C(    -3.42), SIMDE_FLOAT32_C(    47.63), SIMDE_FLOAT32_C(   -39.78), SIMDE_FLOAT32_C(    21.68),
        SIMDE_FLOAT32_C(   -39.56), SIMDE_FLOAT32_C(     4.65), SIMDE_FLOAT32_C(   -10.05), SIMDE_FLOAT32_C(     5.68),
        SIMDE_FLOAT32_C(    49.93), SIMDE_FLOAT32_C(   -44.75), SIMDE_FLOAT32_C(   -29.07), SIMDE_FLOAT32_C(    45.52) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    16.37),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    43.77),
        SIMDE_FLOAT32_C(    22.67), SIMDE_FLOAT32_C(   -24.10), SIMDE_FLOAT32_C(    43.99), SIMDE_FLOAT32_C(    -7.41),
        SIMDE_FLOAT32_C(    27.28), SIMDE_FLOAT32_C(   -49.29), SIMDE_FLOAT32_C(   -40.00), SIMDE_FLOAT32_C(   -31.24),
        SIMDE_FLOAT32_C(    47.51), SIMDE_FLOAT32_C(    17.77), SIMDE_FLOAT32_C(    33.75), SIMDE_FLOAT32_C(     5.22) },
      { SIMDE_FLOAT32_C(    32.17),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -2.63),
        SIMDE_FLOAT32_C(   -19.15), SIMDE_FLOAT32_C(    34.34), SIMDE_FLOAT32_C(    11.89), SIMDE_FLOAT32_C(    35.00),
        SIMDE_FLOAT32_C(   -49.64), SIMDE_FLOAT32_C(    49.36), SIMDE_FLOAT32_C(   -40.76), SIMDE_FLOAT32_C(   -28.90),
        SIMDE_FLOAT32_C(    -0.98), SIMDE_FLOAT32_C(    40.24), SIMDE_FLOAT32_C(   -17.94), SIMDE_FLOAT32_C(     2.94) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-20450798349877357303562240.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    #endif
    { UINT16_C(32950),
      { SIMDE_FLOAT32_C(    -3.11), SIMDE_FLOAT32_C(   -24.96), SIMDE_FLOAT32_C(    35.92), SIMDE_FLOAT32_C(    32.16),
        SIMDE_FLOAT32_C(   -15.85), SIMDE_FLOAT32_C(    33.16), SIMDE_FLOAT32_C(    10.33), SIMDE_FLOAT32_C(    12.58),
        SIMDE_FLOAT32_C(    26.51), SIMDE_FLOAT32_C(     0.71), SIMDE_FLOAT32_C(    21.60), SIMDE_FLOAT32_C(    45.15),
        SIMDE_FLOAT32_C(     5.07), SIMDE_FLOAT32_C(   -47.80), SIMDE_FLOAT32_C(   -41.30), SIMDE_FLOAT32_C(    32.25) },
      { SIMDE_FLOAT32_C(     6.60), SIMDE_FLOAT32_C(    13.76), SIMDE_FLOAT32_C(    -3.29), SIMDE_FLOAT32_C(   -20.73),
        SIMDE_FLOAT32_C(    39.67), SIMDE_FLOAT32_C(    -9.30), SIMDE_FLOAT32_C(    21.87), SIMDE_FLOAT32_C(    16.95),
        SIMDE_FLOAT32_C(    -8.59), SIMDE_FLOAT32_C(    31.87), SIMDE_FLOAT32_C(    35.70), SIMDE_FLOAT32_C(   -11.08),
        SIMDE_FLOAT32_C(    -0.36), SIMDE_FLOAT32_C(    19.46), SIMDE_FLOAT32_C(    44.14), SIMDE_FLOAT32_C(   -18.19) },
      { SIMDE_FLOAT32_C(   -26.50), SIMDE_FLOAT32_C(    13.18), SIMDE_FLOAT32_C(    29.18), SIMDE_FLOAT32_C(     4.36),
        SIMDE_FLOAT32_C(    -2.49), SIMDE_FLOAT32_C(    -8.93), SIMDE_FLOAT32_C(   -10.64), SIMDE_FLOAT32_C(    -2.12),
        SIMDE_FLOAT32_C(    -9.57), SIMDE_FLOAT32_C(    -1.40), SIMDE_FLOAT32_C(    18.98), SIMDE_FLOAT32_C(    39.45),
        SIMDE_FLOAT32_C(   -11.17), SIMDE_FLOAT32_C(   -48.96), SIMDE_FLOAT32_C(    -7.61), SIMDE_FLOAT32_C(    45.44) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-6297444.50), SIMDE_FLOAT32_C(   -64.05), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(-6403186.00), SIMDE_FLOAT32_C(24782979302099898081476608000.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -23.02),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(46585),
      { SIMDE_FLOAT32_C(    29.89), SIMDE_FLOAT32_C(    21.34), SIMDE_FLOAT32_C(   -23.05), SIMDE_FLOAT32_C(    40.32),
        SIMDE_FLOAT32_C(   -24.01), SIMDE_FLOAT32_C(    16.90), SIMDE_FLOAT32_C(    -4.00), SIMDE_FLOAT32_C(   -24.09),
        SIMDE_FLOAT32_C(    22.16), SIMDE_FLOAT32_C(    16.93), SIMDE_FLOAT32_C(   -28.57), SIMDE_FLOAT32_C(    -5.70),
        SIMDE_FLOAT32_C(    42.16), SIMDE_FLOAT32_C(    18.32), SIMDE_FLOAT32_C(    19.34), SIMDE_FLOAT32_C(    28.09) },
      { SIMDE_FLOAT32_C(    14.80), SIMDE_FLOAT32_C(    39.10), SIMDE_FLOAT32_C(   -25.29), SIMDE_FLOAT32_C(     4.47),
        SIMDE_FLOAT32_C(   -20.20), SIMDE_FLOAT32_C(    46.58), SIMDE_FLOAT32_C(   -28.58), SIMDE_FLOAT32_C(    21.21),
        SIMDE_FLOAT32_C(    28.45), SIMDE_FLOAT32_C(   -42.88), SIMDE_FLOAT32_C(   -39.87), SIMDE_FLOAT32_C(   -21.91),
        SIMDE_FLOAT32_C(    26.58), SIMDE_FLOAT32_C(   -45.74), SIMDE_FLOAT32_C(     9.90), SIMDE_FLOAT32_C(   -49.92) },
      { SIMDE_FLOAT32_C(    17.44), SIMDE_FLOAT32_C(   -10.92), SIMDE_FLOAT32_C(     4.44), SIMDE_FLOAT32_C(   -35.04),
        SIMDE_FLOAT32_C(    30.15), SIMDE_FLOAT32_C(    43.80), SIMDE_FLOAT32_C(    12.84), SIMDE_FLOAT32_C(   -29.42),
        SIMDE_FLOAT32_C(    -7.61), SIMDE_FLOAT32_C(   -18.18), SIMDE_FLOAT32_C(   -39.97), SIMDE_FLOAT32_C(    31.23),
        SIMDE_FLOAT32_C(   -17.14), SIMDE_FLOAT32_C(     2.42), SIMDE_FLOAT32_C(    26.66), SIMDE_FLOAT32_C(    47.66) },
      { SIMDE_FLOAT32_C(   286.17), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -116.09),
        SIMDE_FLOAT32_C(  -630.28), SIMDE_FLOAT32_C(  7331.77), SIMDE_FLOAT32_C(-9465034178560.00), SIMDE_FLOAT32_C(-6403716.50),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(47628),
      { SIMDE_FLOAT32_C(    11.24), SIMDE_FLOAT32_C(   -39.19), SIMDE_FLOAT32_C(    16.06), SIMDE_FLOAT32_C(   -12.24),
        SIMDE_FLOAT32_C(    11.52), SIMDE_FLOAT32_C(   -12.34), SIMDE_FLOAT32_C(   -17.09), SIMDE_FLOAT32_C(   -33.41),
        SIMDE_FLOAT32_C(   -10.13), SIMDE_FLOAT32_C(    -8.39), SIMDE_FLOAT32_C(    48.84), SIMDE_FLOAT32_C(   -49.01),
        SIMDE_FLOAT32_C(    46.89), SIMDE_FLOAT32_C(    28.73), SIMDE_FLOAT32_C(    22.33), SIMDE_FLOAT32_C(   -26.16) },
      { SIMDE_FLOAT32_C(    -8.47), SIMDE_FLOAT32_C(   -48.63), SIMDE_FLOAT32_C(     2.13), SIMDE_FLOAT32_C(    21.33),
        SIMDE_FLOAT32_C(    47.95), SIMDE_FLOAT32_C(    23.55), SIMDE_FLOAT32_C(    -7.47), SIMDE_FLOAT32_C(    26.40),
        SIMDE_FLOAT32_C(    30.67), SIMDE_FLOAT32_C(     2.66), SIMDE_FLOAT32_C(   -45.51), SIMDE_FLOAT32_C(     7.24),
        SIMDE_FLOAT32_C(     6.93), SIMDE_FLOAT32_C(    14.39), SIMDE_FLOAT32_C(     7.33), SIMDE_FLOAT32_C(   -25.63) },
      { SIMDE_FLOAT32_C(   -46.53), SIMDE_FLOAT32_C(   -38.23), SIMDE_FLOAT32_C(   -10.67), SIMDE_FLOAT32_C(    33.62),
        SIMDE_FLOAT32_C(   -44.44), SIMDE_FLOAT32_C(   -47.84), SIMDE_FLOAT32_C(   -45.79), SIMDE_FLOAT32_C(    -2.04),
        SIMDE_FLOAT32_C(   -16.02), SIMDE_FLOAT32_C(   -35.76), SIMDE_FLOAT32_C(   -20.81), SIMDE_FLOAT32_C(    16.84),
        SIMDE_FLOAT32_C(    16.66), SIMDE_FLOAT32_C(   -44.15), SIMDE_FLOAT32_C(    14.50), SIMDE_FLOAT32_C(   -41.81) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-6343686.50), SIMDE_FLOAT32_C(-13616351998377984000.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(26372),
      { SIMDE_FLOAT32_C(    40.75), SIMDE_FLOAT32_C(   -34.95), SIMDE_FLOAT32_C(   -25.77), SIMDE_FLOAT32_C(    12.90),
        SIMDE_FLOAT32_C(    31.99), SIMDE_FLOAT32_C(    -4.34), SIMDE_FLOAT32_C(   -42.80), SIMDE_FLOAT32_C(    24.15),
        SIMDE_FLOAT32_C(   -36.03), SIMDE_FLOAT32_C(    26.54), SIMDE_FLOAT32_C(     2.23), SIMDE_FLOAT32_C(    14.45),
        SIMDE_FLOAT32_C(    30.03), SIMDE_FLOAT32_C(   -36.52), SIMDE_FLOAT32_C(    25.26), SIMDE_FLOAT32_C(    -3.91) },
      { SIMDE_FLOAT32_C(   -42.78), SIMDE_FLOAT32_C(   -33.37), SIMDE_FLOAT32_C(    29.51), SIMDE_FLOAT32_C(   -44.83),
        SIMDE_FLOAT32_C(    40.17), SIMDE_FLOAT32_C(   -27.95), SIMDE_FLOAT32_C(    31.57), SIMDE_FLOAT32_C(    20.84),
        SIMDE_FLOAT32_C(    24.71), SIMDE_FLOAT32_C(    36.07), SIMDE_FLOAT32_C(   -21.92), SIMDE_FLOAT32_C(   -18.37),
        SIMDE_FLOAT32_C(     0.46), SIMDE_FLOAT32_C(    35.41), SIMDE_FLOAT32_C(     6.00), SIMDE_FLOAT32_C(     3.93) },
      { SIMDE_FLOAT32_C(    47.18), SIMDE_FLOAT32_C(    45.33), SIMDE_FLOAT32_C(   -12.45), SIMDE_FLOAT32_C(   -47.26),
        SIMDE_FLOAT32_C(    47.49), SIMDE_FLOAT32_C(    -8.24), SIMDE_FLOAT32_C(     0.70), SIMDE_FLOAT32_C(   -18.53),
        SIMDE_FLOAT32_C(     6.00), SIMDE_FLOAT32_C(    29.89), SIMDE_FLOAT32_C(    48.31), SIMDE_FLOAT32_C(   -27.34),
        SIMDE_FLOAT32_C(    35.74), SIMDE_FLOAT32_C(    12.80), SIMDE_FLOAT32_C(   -19.15), SIMDE_FLOAT32_C(    42.96) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -392.68), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(27969),
      { SIMDE_FLOAT32_C(    33.75), SIMDE_FLOAT32_C(    34.15), SIMDE_FLOAT32_C(     3.37), SIMDE_FLOAT32_C(   -26.38),
        SIMDE_FLOAT32_C(   -24.24), SIMDE_FLOAT32_C(     2.21), SIMDE_FLOAT32_C(   -25.40), SIMDE_FLOAT32_C(   -27.35),
        SIMDE_FLOAT32_C(   -19.06), SIMDE_FLOAT32_C(    46.93), SIMDE_FLOAT32_C(    -3.51), SIMDE_FLOAT32_C(    49.99),
        SIMDE_FLOAT32_C(    45.24), SIMDE_FLOAT32_C(   -12.77), SIMDE_FLOAT32_C(   -34.96), SIMDE_FLOAT32_C(   -30.53) },
      { SIMDE_FLOAT32_C(    29.43), SIMDE_FLOAT32_C(   -39.64), SIMDE_FLOAT32_C(    48.13), SIMDE_FLOAT32_C(    19.60),
        SIMDE_FLOAT32_C(   -17.59), SIMDE_FLOAT32_C(    29.71), SIMDE_FLOAT32_C(    -9.56), SIMDE_FLOAT32_C(   -42.88),
        SIMDE_FLOAT32_C(    15.77), SIMDE_FLOAT32_C(    18.52), SIMDE_FLOAT32_C(   -11.25), SIMDE_FLOAT32_C(   -33.77),
        SIMDE_FLOAT32_C(     3.93), SIMDE_FLOAT32_C(    44.75), SIMDE_FLOAT32_C(    20.16), SIMDE_FLOAT32_C(     1.11) },
      { SIMDE_FLOAT32_C(    40.08), SIMDE_FLOAT32_C(   -42.29), SIMDE_FLOAT32_C(     3.85), SIMDE_FLOAT32_C(    37.57),
        SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(   -45.45), SIMDE_FLOAT32_C(   -30.96), SIMDE_FLOAT32_C(   -44.53),
        SIMDE_FLOAT32_C(    34.44), SIMDE_FLOAT32_C(   -32.65), SIMDE_FLOAT32_C(   -21.87), SIMDE_FLOAT32_C(    20.17),
        SIMDE_FLOAT32_C(    30.15), SIMDE_FLOAT32_C(     8.98), SIMDE_FLOAT32_C(    13.13), SIMDE_FLOAT32_C(     9.57) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(16636657311476801863680.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(20143),
      { SIMDE_FLOAT32_C(    15.12), SIMDE_FLOAT32_C(   -42.66), SIMDE_FLOAT32_C(    21.18), SIMDE_FLOAT32_C(    29.09),
        SIMDE_FLOAT32_C(    33.88), SIMDE_FLOAT32_C(   -26.59), SIMDE_FLOAT32_C(    -6.46), SIMDE_FLOAT32_C(    13.90),
        SIMDE_FLOAT32_C(   -13.11), SIMDE_FLOAT32_C(   -31.20), SIMDE_FLOAT32_C(   -40.01), SIMDE_FLOAT32_C(    38.12),
        SIMDE_FLOAT32_C(     5.58), SIMDE_FLOAT32_C(    43.74), SIMDE_FLOAT32_C(    22.27), SIMDE_FLOAT32_C(   -41.05) },
      { SIMDE_FLOAT32_C(    19.34), SIMDE_FLOAT32_C(    11.27), SIMDE_FLOAT32_C(   -20.83), SIMDE_FLOAT32_C(   -48.25),
        SIMDE_FLOAT32_C(    -9.02), SIMDE_FLOAT32_C(    19.61), SIMDE_FLOAT32_C(   -41.14), SIMDE_FLOAT32_C(   -43.25),
        SIMDE_FLOAT32_C(   -11.87), SIMDE_FLOAT32_C(    -2.39), SIMDE_FLOAT32_C(   -27.02), SIMDE_FLOAT32_C(    42.06),
        SIMDE_FLOAT32_C(    -7.64), SIMDE_FLOAT32_C(    43.13), SIMDE_FLOAT32_C(    -6.82), SIMDE_FLOAT32_C(   -17.56) },
      { SIMDE_FLOAT32_C(   -49.16), SIMDE_FLOAT32_C(    47.03), SIMDE_FLOAT32_C(   -29.99), SIMDE_FLOAT32_C(     0.31),
        SIMDE_FLOAT32_C(   -48.42), SIMDE_FLOAT32_C(   -10.95), SIMDE_FLOAT32_C(     5.78), SIMDE_FLOAT32_C(    36.02),
        SIMDE_FLOAT32_C(     6.39), SIMDE_FLOAT32_C(    33.91), SIMDE_FLOAT32_C(     6.20), SIMDE_FLOAT32_C(   -13.46),
        SIMDE_FLOAT32_C(    -7.12), SIMDE_FLOAT32_C(   -30.67), SIMDE_FLOAT32_C(    46.12), SIMDE_FLOAT32_C(   -37.78) },
      { SIMDE_FLOAT32_C(  -928.13), SIMDE_FLOAT32_C(   486.09), SIMDE_FLOAT32_C(7496008192.00), SIMDE_FLOAT32_C(    14.20),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-9609989324800.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1543.10),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C( 3953),
      { SIMDE_FLOAT32_C(    11.16), SIMDE_FLOAT32_C(    -8.04), SIMDE_FLOAT32_C(   -29.33), SIMDE_FLOAT32_C(    42.09),
        SIMDE_FLOAT32_C(   -11.11), SIMDE_FLOAT32_C(    17.16), SIMDE_FLOAT32_C(    42.08), SIMDE_FLOAT32_C(   -15.87),
        SIMDE_FLOAT32_C(   -45.61), SIMDE_FLOAT32_C(   -42.88), SIMDE_FLOAT32_C(     3.60), SIMDE_FLOAT32_C(   -45.47),
        SIMDE_FLOAT32_C(   -45.85), SIMDE_FLOAT32_C(   -31.28), SIMDE_FLOAT32_C(   -38.13), SIMDE_FLOAT32_C(    25.33) },
      { SIMDE_FLOAT32_C(    30.60), SIMDE_FLOAT32_C(   -24.71), SIMDE_FLOAT32_C(   -36.03), SIMDE_FLOAT32_C(   -28.43),
        SIMDE_FLOAT32_C(    44.90), SIMDE_FLOAT32_C(   -27.17), SIMDE_FLOAT32_C(   -21.68), SIMDE_FLOAT32_C(   -16.97),
        SIMDE_FLOAT32_C(    20.44), SIMDE_FLOAT32_C(     1.30), SIMDE_FLOAT32_C(   -24.90), SIMDE_FLOAT32_C(   -37.20),
        SIMDE_FLOAT32_C(    -5.57), SIMDE_FLOAT32_C(    18.27), SIMDE_FLOAT32_C(    -4.76), SIMDE_FLOAT32_C(    -4.72) },
      { SIMDE_FLOAT32_C(    15.30), SIMDE_FLOAT32_C(    15.25), SIMDE_FLOAT32_C(    45.59), SIMDE_FLOAT32_C(    16.88),
        SIMDE_FLOAT32_C(   -45.70), SIMDE_FLOAT32_C(     1.37), SIMDE_FLOAT32_C(     2.91), SIMDE_FLOAT32_C(    10.69),
        SIMDE_FLOAT32_C(   -14.72), SIMDE_FLOAT32_C(   -40.90), SIMDE_FLOAT32_C(    47.24), SIMDE_FLOAT32_C(    28.16),
        SIMDE_FLOAT32_C(   -21.57), SIMDE_FLOAT32_C(    43.35), SIMDE_FLOAT32_C(    40.39), SIMDE_FLOAT32_C(   -40.97) },
      { SIMDE_FLOAT32_C(11551744039321600.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C( -2047.23), SIMDE_FLOAT32_C(36205368793118459936147340248743936.00), SIMDE_FLOAT32_C(23890792047224301750543450112.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 tmp, src, r;
    simde__m512bh a, b;

    src = simde_mm512_loadu_ps(test_vec[i].src);

    tmp = simde_mm512_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm512_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm512_maskz_dpbf16_ps(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_f32x16_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__m512bh a = HEDLEY_REINTERPRET_CAST(simde__m512bh, simde_test_x86_random_extract_f32x16(i, 2, 0, values));
    simde__m512bh b = HEDLEY_REINTERPRET_CAST(simde__m512bh, simde_test_x86_random_extract_f32x16(i, 2, 1, values));
    simde__m512 r = simde_mm512_maskz_dpbf16_ps(k, src, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, HEDLEY_REINTERPRET_CAST(simde__m512, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, HEDLEY_REINTERPRET_CAST(simde__m512, b), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_dpbf16_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_dpbf16_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
