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
    { { SIMDE_FLOAT32_C(    41.97), SIMDE_FLOAT32_C(   -38.86), SIMDE_FLOAT32_C(   -41.42), SIMDE_FLOAT32_C(   -36.59),
        SIMDE_FLOAT32_C(    47.47), SIMDE_FLOAT32_C(    -3.68), SIMDE_FLOAT32_C(    -9.99), SIMDE_FLOAT32_C(   -18.40),
        SIMDE_FLOAT32_C(   -21.35), SIMDE_FLOAT32_C(    30.30), SIMDE_FLOAT32_C(   -49.63), SIMDE_FLOAT32_C(   -44.49),
        SIMDE_FLOAT32_C(   -34.55), SIMDE_FLOAT32_C(    -9.63), SIMDE_FLOAT32_C(   -35.72), SIMDE_FLOAT32_C(    22.88) },
      { SIMDE_FLOAT32_C(     8.67), SIMDE_FLOAT32_C(   -39.77), SIMDE_FLOAT32_C(   -35.49), SIMDE_FLOAT32_C(    29.91),
        SIMDE_FLOAT32_C(    12.76), SIMDE_FLOAT32_C(   -46.50), SIMDE_FLOAT32_C(    17.78), SIMDE_FLOAT32_C(    -8.78),
        SIMDE_FLOAT32_C(    44.43), SIMDE_FLOAT32_C(     0.75), SIMDE_FLOAT32_C(    43.12), SIMDE_FLOAT32_C(   -47.50),
        SIMDE_FLOAT32_C(   -40.81), SIMDE_FLOAT32_C(   -14.02), SIMDE_FLOAT32_C(    25.88), SIMDE_FLOAT32_C(   -39.29) },
      { SIMDE_FLOAT32_C(   -14.95), SIMDE_FLOAT32_C(    15.90), SIMDE_FLOAT32_C(     7.59), SIMDE_FLOAT32_C(    49.63),
        SIMDE_FLOAT32_C(    44.94), SIMDE_FLOAT32_C(   -38.85), SIMDE_FLOAT32_C(    15.18), SIMDE_FLOAT32_C(   -31.16),
        SIMDE_FLOAT32_C(    20.37), SIMDE_FLOAT32_C(   -36.88), SIMDE_FLOAT32_C(   -42.11), SIMDE_FLOAT32_C(    -2.01),
        SIMDE_FLOAT32_C(    13.69), SIMDE_FLOAT32_C(   -29.98), SIMDE_FLOAT32_C(    16.64), SIMDE_FLOAT32_C(   -27.64) },
      { SIMDE_FLOAT32_C(   -86.87), SIMDE_FLOAT32_C(  -669.89),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  1442.22),
        SIMDE_FLOAT32_C(   618.03), SIMDE_FLOAT32_C(  1798.19), SIMDE_FLOAT32_C(-13567093877453619200.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(24752756156609532352108953600.00), SIMDE_FLOAT32_C(     2.74),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    50.51),
        SIMDE_FLOAT32_C(  -592.32), SIMDE_FLOAT32_C(-19224753951762325664956416.00), SIMDE_FLOAT32_C(   394.45), SIMDE_FLOAT32_C(  1107.16) } },
    { { SIMDE_FLOAT32_C(    -1.09), SIMDE_FLOAT32_C(    36.02), SIMDE_FLOAT32_C(    -0.23), SIMDE_FLOAT32_C(   -34.19),
        SIMDE_FLOAT32_C(   -12.87), SIMDE_FLOAT32_C(    -0.27), SIMDE_FLOAT32_C(   -16.32), SIMDE_FLOAT32_C(    37.17),
        SIMDE_FLOAT32_C(   -18.77), SIMDE_FLOAT32_C(   -40.08), SIMDE_FLOAT32_C(   -48.98), SIMDE_FLOAT32_C(    15.57),
        SIMDE_FLOAT32_C(    48.78), SIMDE_FLOAT32_C(    14.92), SIMDE_FLOAT32_C(    17.72), SIMDE_FLOAT32_C(    40.75) },
      { SIMDE_FLOAT32_C(   -19.75), SIMDE_FLOAT32_C(    31.16), SIMDE_FLOAT32_C(   -47.73), SIMDE_FLOAT32_C(    43.01),
        SIMDE_FLOAT32_C(    34.66), SIMDE_FLOAT32_C(    20.05), SIMDE_FLOAT32_C(   -15.77), SIMDE_FLOAT32_C(    29.09),
        SIMDE_FLOAT32_C(   -29.21), SIMDE_FLOAT32_C(   -22.64), SIMDE_FLOAT32_C(    31.59), SIMDE_FLOAT32_C(   -20.02),
        SIMDE_FLOAT32_C(    13.33), SIMDE_FLOAT32_C(     7.48), SIMDE_FLOAT32_C(    -9.32), SIMDE_FLOAT32_C(    48.38) },
      { SIMDE_FLOAT32_C(   -26.62), SIMDE_FLOAT32_C(    48.27), SIMDE_FLOAT32_C(    48.01), SIMDE_FLOAT32_C(   -31.68),
        SIMDE_FLOAT32_C(   -40.58), SIMDE_FLOAT32_C(    13.19), SIMDE_FLOAT32_C(   -12.84), SIMDE_FLOAT32_C(    29.79),
        SIMDE_FLOAT32_C(    26.31), SIMDE_FLOAT32_C(    -4.95), SIMDE_FLOAT32_C(   -22.22), SIMDE_FLOAT32_C(   -10.01),
        SIMDE_FLOAT32_C(    15.07), SIMDE_FLOAT32_C(    44.42), SIMDE_FLOAT32_C(    12.35), SIMDE_FLOAT32_C(    45.32) },
      { SIMDE_FLOAT32_C(   522.28), SIMDE_FLOAT32_C(  1537.80), SIMDE_FLOAT32_C( -2280.23), SIMDE_FLOAT32_C( -1394.06),
        SIMDE_FLOAT32_C( -1410.12), SIMDE_FLOAT32_C(   263.48),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-6342780.00),
        SIMDE_FLOAT32_C(-19656850484944898202009600.00), SIMDE_FLOAT32_C(  5361.63), SIMDE_FLOAT32_C(  -745.91), SIMDE_FLOAT32_C(   215.57),
        SIMDE_FLOAT32_C(   249.30), SIMDE_FLOAT32_C(-6402726.50), SIMDE_FLOAT32_C(   -96.94), SIMDE_FLOAT32_C(  2224.06) } },
    { { SIMDE_FLOAT32_C(     7.08), SIMDE_FLOAT32_C(    12.56), SIMDE_FLOAT32_C(   -39.41), SIMDE_FLOAT32_C(    44.22),
        SIMDE_FLOAT32_C(   -37.70), SIMDE_FLOAT32_C(    -5.72), SIMDE_FLOAT32_C(    31.38), SIMDE_FLOAT32_C(    -6.47),
        SIMDE_FLOAT32_C(     4.20), SIMDE_FLOAT32_C(    32.40), SIMDE_FLOAT32_C(   -40.91), SIMDE_FLOAT32_C(     2.97),
        SIMDE_FLOAT32_C(    -2.68), SIMDE_FLOAT32_C(    26.81), SIMDE_FLOAT32_C(    -6.28), SIMDE_FLOAT32_C(   -26.62) },
      { SIMDE_FLOAT32_C(   -33.90), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(    21.61), SIMDE_FLOAT32_C(     0.77),
        SIMDE_FLOAT32_C(    23.57), SIMDE_FLOAT32_C(   -39.07), SIMDE_FLOAT32_C(   -43.76), SIMDE_FLOAT32_C(   -26.51),
        SIMDE_FLOAT32_C(   -18.15), SIMDE_FLOAT32_C(    41.68), SIMDE_FLOAT32_C(   -13.26), SIMDE_FLOAT32_C(   -39.76),
        SIMDE_FLOAT32_C(   -32.20), SIMDE_FLOAT32_C(    -1.63), SIMDE_FLOAT32_C(   -37.99), SIMDE_FLOAT32_C(    -7.81) },
      { SIMDE_FLOAT32_C(     8.01), SIMDE_FLOAT32_C(   -17.91), SIMDE_FLOAT32_C(    26.00), SIMDE_FLOAT32_C(   -19.17),
        SIMDE_FLOAT32_C(    39.34), SIMDE_FLOAT32_C(    39.60), SIMDE_FLOAT32_C(    29.96), SIMDE_FLOAT32_C(    41.63),
        SIMDE_FLOAT32_C(   -19.02), SIMDE_FLOAT32_C(    19.08), SIMDE_FLOAT32_C(     8.99), SIMDE_FLOAT32_C(    16.77),
        SIMDE_FLOAT32_C(   -29.44), SIMDE_FLOAT32_C(   -28.33), SIMDE_FLOAT32_C(    28.15), SIMDE_FLOAT32_C(   -13.33) },
      { SIMDE_FLOAT32_C(  -262.92), SIMDE_FLOAT32_C(    -5.31), SIMDE_FLOAT32_C(   519.59), SIMDE_FLOAT32_C(    29.51),
        SIMDE_FLOAT32_C(   884.67), SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C( -1275.65), SIMDE_FLOAT32_C( -1106.22),
        SIMDE_FLOAT32_C(   348.58), SIMDE_FLOAT32_C(   820.90), SIMDE_FLOAT32_C(  -163.48), SIMDE_FLOAT32_C(  -662.84),
        SIMDE_FLOAT32_C(   937.32), SIMDE_FLOAT32_C(    72.72), SIMDE_FLOAT32_C(-20604275260570620773007360.00), SIMDE_FLOAT32_C(-28648408389142270321715532791808.00) } },
    { { SIMDE_FLOAT32_C(    33.44), SIMDE_FLOAT32_C(   -10.21), SIMDE_FLOAT32_C(   -15.86), SIMDE_FLOAT32_C(   -37.42),
        SIMDE_FLOAT32_C(    28.00), SIMDE_FLOAT32_C(     8.77), SIMDE_FLOAT32_C(    37.55), SIMDE_FLOAT32_C(    33.34),
        SIMDE_FLOAT32_C(    34.72), SIMDE_FLOAT32_C(   -23.27), SIMDE_FLOAT32_C(   -19.02), SIMDE_FLOAT32_C(     8.46),
        SIMDE_FLOAT32_C(   -25.71), SIMDE_FLOAT32_C(   -26.35), SIMDE_FLOAT32_C(    19.60), SIMDE_FLOAT32_C(   -30.08) },
      { SIMDE_FLOAT32_C(    39.20), SIMDE_FLOAT32_C(    19.88), SIMDE_FLOAT32_C(   -22.23), SIMDE_FLOAT32_C(    47.46),
        SIMDE_FLOAT32_C(    11.67), SIMDE_FLOAT32_C(     2.95), SIMDE_FLOAT32_C(    40.85), SIMDE_FLOAT32_C(    11.67),
        SIMDE_FLOAT32_C(     0.70), SIMDE_FLOAT32_C(    22.19), SIMDE_FLOAT32_C(   -12.27), SIMDE_FLOAT32_C(    11.51),
        SIMDE_FLOAT32_C(     8.97), SIMDE_FLOAT32_C(    23.23), SIMDE_FLOAT32_C(    -7.88), SIMDE_FLOAT32_C(   -34.64) },
      { SIMDE_FLOAT32_C(    10.67), SIMDE_FLOAT32_C(   -29.05), SIMDE_FLOAT32_C(    27.29), SIMDE_FLOAT32_C(   -46.63),
        SIMDE_FLOAT32_C(    42.01), SIMDE_FLOAT32_C(    34.91), SIMDE_FLOAT32_C(    -1.83), SIMDE_FLOAT32_C(   -25.06),
        SIMDE_FLOAT32_C(   -29.09), SIMDE_FLOAT32_C(     4.55), SIMDE_FLOAT32_C(    11.42), SIMDE_FLOAT32_C(    -4.96),
        SIMDE_FLOAT32_C(    33.46), SIMDE_FLOAT32_C(   -49.89), SIMDE_FLOAT32_C(   -20.56), SIMDE_FLOAT32_C(    22.66) },
      { SIMDE_FLOAT32_C(  5829.06), SIMDE_FLOAT32_C(  -586.59), SIMDE_FLOAT32_C(-19224753951762325664956416.00), SIMDE_FLOAT32_C( -2234.54),
        SIMDE_FLOAT32_C(   516.25), SIMDE_FLOAT32_C(   110.85), SIMDE_FLOAT32_C(15976609750089381969920.00), SIMDE_FLOAT32_C(-29246333428117108994491809792000.00),
        SIMDE_FLOAT32_C(    14.44), SIMDE_FLOAT32_C(    76.98), SIMDE_FLOAT32_C(-6343838.50), SIMDE_FLOAT32_C(   -48.32),
        SIMDE_FLOAT32_C(   271.46), SIMDE_FLOAT32_C( -1176.82), SIMDE_FLOAT32_C(15953551319997245030400.00), SIMDE_FLOAT32_C(  -810.64) } },
    #if !defined(SIMDE_FAST_MATH)
    { { SIMDE_FLOAT32_C(    47.78), SIMDE_FLOAT32_C(   -14.98), SIMDE_FLOAT32_C(    24.74), SIMDE_FLOAT32_C(   -20.51),
        SIMDE_FLOAT32_C(   -30.09), SIMDE_FLOAT32_C(   -31.49), SIMDE_FLOAT32_C(     1.18), SIMDE_FLOAT32_C(   -29.49),
        SIMDE_FLOAT32_C(    -4.16), SIMDE_FLOAT32_C(    17.13), SIMDE_FLOAT32_C(   -48.68), SIMDE_FLOAT32_C(    14.20),
        SIMDE_FLOAT32_C(    -7.69), SIMDE_FLOAT32_C(    -2.21), SIMDE_FLOAT32_C(     8.38), SIMDE_FLOAT32_C(    -4.96) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    38.87),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -14.71),
        SIMDE_FLOAT32_C(    25.30), SIMDE_FLOAT32_C(    23.30), SIMDE_FLOAT32_C(    48.57), SIMDE_FLOAT32_C(   -16.56),
        SIMDE_FLOAT32_C(   -48.68), SIMDE_FLOAT32_C(    37.76), SIMDE_FLOAT32_C(   -23.07), SIMDE_FLOAT32_C(   -34.00),
        SIMDE_FLOAT32_C(    42.06), SIMDE_FLOAT32_C(    15.66), SIMDE_FLOAT32_C(   -29.79), SIMDE_FLOAT32_C(    -0.28) },
      { SIMDE_FLOAT32_C(   -35.32),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -3.33),
        SIMDE_FLOAT32_C(   -40.88), SIMDE_FLOAT32_C(    21.71), SIMDE_FLOAT32_C(    21.76), SIMDE_FLOAT32_C(   -39.21),
        SIMDE_FLOAT32_C(    15.54), SIMDE_FLOAT32_C(   -45.76), SIMDE_FLOAT32_C(    -6.44), SIMDE_FLOAT32_C(    25.68),
        SIMDE_FLOAT32_C(    -7.50), SIMDE_FLOAT32_C(   -37.38), SIMDE_FLOAT32_C(    22.01), SIMDE_FLOAT32_C(    27.09) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    28.38),
        SIMDE_FLOAT32_C( -1059.03), SIMDE_FLOAT32_C(-9137542922240.00), SIMDE_FLOAT32_C(  1056.06),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(  -755.91), SIMDE_FLOAT32_C( -1709.93), SIMDE_FLOAT32_C(    99.38), SIMDE_FLOAT32_C(  -857.05),
        SIMDE_FLOAT32_C(  -322.69), SIMDE_FLOAT32_C(  -584.24), SIMDE_FLOAT32_C(  -646.12), SIMDE_FLOAT32_C(-9526774333440.00) } },
    #endif
    { { SIMDE_FLOAT32_C(   -12.61), SIMDE_FLOAT32_C(    48.07), SIMDE_FLOAT32_C(    41.82), SIMDE_FLOAT32_C(    22.53),
        SIMDE_FLOAT32_C(    23.86), SIMDE_FLOAT32_C(     3.71), SIMDE_FLOAT32_C(   -32.99), SIMDE_FLOAT32_C(   -28.61),
        SIMDE_FLOAT32_C(    35.21), SIMDE_FLOAT32_C(   -15.22), SIMDE_FLOAT32_C(   -44.26), SIMDE_FLOAT32_C(   -36.49),
        SIMDE_FLOAT32_C(     9.76), SIMDE_FLOAT32_C(    -0.81), SIMDE_FLOAT32_C(   -14.11), SIMDE_FLOAT32_C(     7.54) },
      { SIMDE_FLOAT32_C(   -48.52), SIMDE_FLOAT32_C(     7.00), SIMDE_FLOAT32_C(   -37.62), SIMDE_FLOAT32_C(    26.79),
        SIMDE_FLOAT32_C(   -19.70), SIMDE_FLOAT32_C(   -39.05), SIMDE_FLOAT32_C(   -39.77), SIMDE_FLOAT32_C(   -18.37),
        SIMDE_FLOAT32_C(    48.71), SIMDE_FLOAT32_C(   -12.84), SIMDE_FLOAT32_C(    -2.38), SIMDE_FLOAT32_C(    40.77),
        SIMDE_FLOAT32_C(   -47.18), SIMDE_FLOAT32_C(    17.83), SIMDE_FLOAT32_C(    -9.51), SIMDE_FLOAT32_C(   -32.51) },
      { SIMDE_FLOAT32_C(    33.39), SIMDE_FLOAT32_C(     6.73), SIMDE_FLOAT32_C(    14.17), SIMDE_FLOAT32_C(    42.51),
        SIMDE_FLOAT32_C(   -21.56), SIMDE_FLOAT32_C(   -14.07), SIMDE_FLOAT32_C(   -46.70), SIMDE_FLOAT32_C(    43.98),
        SIMDE_FLOAT32_C(    -9.83), SIMDE_FLOAT32_C(    -3.14), SIMDE_FLOAT32_C(    19.66), SIMDE_FLOAT32_C(    32.67),
        SIMDE_FLOAT32_C(     9.47), SIMDE_FLOAT32_C(    -8.33), SIMDE_FLOAT32_C(     9.76), SIMDE_FLOAT32_C(    10.96) },
      { SIMDE_FLOAT32_C( -1625.23), SIMDE_FLOAT32_C(    95.10), SIMDE_FLOAT32_C(-29246333428117108994491809792000.00), SIMDE_FLOAT32_C(  1159.41),
        SIMDE_FLOAT32_C(-9301288550400.00), SIMDE_FLOAT32_C(   552.15), SIMDE_FLOAT32_C(  1815.39),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(-13517554281552543744.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(11287586370748416.00), SIMDE_FLOAT32_C(  1287.89),
        SIMDE_FLOAT32_C(  -433.80), SIMDE_FLOAT32_C(  -148.36), SIMDE_FLOAT32_C(  -106.74), SIMDE_FLOAT32_C(  -347.93) } },
    { { SIMDE_FLOAT32_C(    34.21), SIMDE_FLOAT32_C(   -39.37), SIMDE_FLOAT32_C(    37.03), SIMDE_FLOAT32_C(   -45.88),
        SIMDE_FLOAT32_C(   -20.86), SIMDE_FLOAT32_C(   -11.79), SIMDE_FLOAT32_C(   -25.37), SIMDE_FLOAT32_C(    24.97),
        SIMDE_FLOAT32_C(   -44.66), SIMDE_FLOAT32_C(   -24.05), SIMDE_FLOAT32_C(   -10.82), SIMDE_FLOAT32_C(    -2.36),
        SIMDE_FLOAT32_C(    23.74), SIMDE_FLOAT32_C(    47.56), SIMDE_FLOAT32_C(    42.68), SIMDE_FLOAT32_C(   -38.86) },
      { SIMDE_FLOAT32_C(    48.67), SIMDE_FLOAT32_C(    22.14), SIMDE_FLOAT32_C(   -12.26), SIMDE_FLOAT32_C(   -21.03),
        SIMDE_FLOAT32_C(    33.10), SIMDE_FLOAT32_C(    -2.02), SIMDE_FLOAT32_C(    10.60), SIMDE_FLOAT32_C(    31.81),
        SIMDE_FLOAT32_C(    35.13), SIMDE_FLOAT32_C(   -41.78), SIMDE_FLOAT32_C(    22.57), SIMDE_FLOAT32_C(    37.95),
        SIMDE_FLOAT32_C(    26.05), SIMDE_FLOAT32_C(   -36.94), SIMDE_FLOAT32_C(   -44.56), SIMDE_FLOAT32_C(     9.44) },
      { SIMDE_FLOAT32_C(    19.79), SIMDE_FLOAT32_C(    19.61), SIMDE_FLOAT32_C(     1.95), SIMDE_FLOAT32_C(    48.23),
        SIMDE_FLOAT32_C(   -44.47), SIMDE_FLOAT32_C(     5.25), SIMDE_FLOAT32_C(    42.22), SIMDE_FLOAT32_C(    -4.30),
        SIMDE_FLOAT32_C(   -47.90), SIMDE_FLOAT32_C(    11.88), SIMDE_FLOAT32_C(   -21.63), SIMDE_FLOAT32_C(    11.58),
        SIMDE_FLOAT32_C(   -46.45), SIMDE_FLOAT32_C(    38.13), SIMDE_FLOAT32_C(   -27.46), SIMDE_FLOAT32_C(   -47.78) },
      { SIMDE_FLOAT32_C(   987.82), SIMDE_FLOAT32_C(   387.58), SIMDE_FLOAT32_C(    13.20), SIMDE_FLOAT32_C(-18920751609427592254324736.00),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -22.37), SIMDE_FLOAT32_C(   418.26), SIMDE_FLOAT32_C(-9301288550400.00),
        SIMDE_FLOAT32_C( -1715.91), SIMDE_FLOAT32_C(  -519.83), SIMDE_FLOAT32_C(  -497.38), SIMDE_FLOAT32_C(-9575092715520.00),
        SIMDE_FLOAT32_C(-29184436426152839980746853580800.00), SIMDE_FLOAT32_C( -1348.94), SIMDE_FLOAT32_C(  1260.87), SIMDE_FLOAT32_C(  -489.50) } },
    { { SIMDE_FLOAT32_C(    -4.61), SIMDE_FLOAT32_C(   -16.28), SIMDE_FLOAT32_C(    26.39), SIMDE_FLOAT32_C(    31.57),
        SIMDE_FLOAT32_C(   -49.66), SIMDE_FLOAT32_C(    35.65), SIMDE_FLOAT32_C(    -5.68), SIMDE_FLOAT32_C(    36.04),
        SIMDE_FLOAT32_C(    38.28), SIMDE_FLOAT32_C(    33.58), SIMDE_FLOAT32_C(   -47.25), SIMDE_FLOAT32_C(   -41.42),
        SIMDE_FLOAT32_C(    31.48), SIMDE_FLOAT32_C(    14.13), SIMDE_FLOAT32_C(   -30.37), SIMDE_FLOAT32_C(   -16.33) },
      { SIMDE_FLOAT32_C(    36.78), SIMDE_FLOAT32_C(     0.05), SIMDE_FLOAT32_C(    34.84), SIMDE_FLOAT32_C(     0.85),
        SIMDE_FLOAT32_C(    31.25), SIMDE_FLOAT32_C(    40.74), SIMDE_FLOAT32_C(   -43.51), SIMDE_FLOAT32_C(    30.98),
        SIMDE_FLOAT32_C(    32.98), SIMDE_FLOAT32_C(    12.30), SIMDE_FLOAT32_C(    -8.80), SIMDE_FLOAT32_C(    41.55),
        SIMDE_FLOAT32_C(    36.55), SIMDE_FLOAT32_C(    44.43), SIMDE_FLOAT32_C(    28.62), SIMDE_FLOAT32_C(    -4.36) },
      { SIMDE_FLOAT32_C(   -10.90), SIMDE_FLOAT32_C(     4.49), SIMDE_FLOAT32_C(   -47.86), SIMDE_FLOAT32_C(    -4.83),
        SIMDE_FLOAT32_C(   -35.34), SIMDE_FLOAT32_C(    22.79), SIMDE_FLOAT32_C(    48.03), SIMDE_FLOAT32_C(   -14.61),
        SIMDE_FLOAT32_C(   -27.07), SIMDE_FLOAT32_C(   -47.18), SIMDE_FLOAT32_C(   -32.37), SIMDE_FLOAT32_C(    -2.50),
        SIMDE_FLOAT32_C(   -38.85), SIMDE_FLOAT32_C(    32.18), SIMDE_FLOAT32_C(   -33.16), SIMDE_FLOAT32_C(    47.93) },
      { SIMDE_FLOAT32_C(  4885.73), SIMDE_FLOAT32_C(   -16.05),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    27.49),
        SIMDE_FLOAT32_C( -1151.22),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C( -2093.68), SIMDE_FLOAT32_C(10848881231265792.00),
        SIMDE_FLOAT32_C(  -845.97), SIMDE_FLOAT32_C(  4839.08),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -145.17),
        SIMDE_FLOAT32_C(11316723428884480.00), SIMDE_FLOAT32_C(  1430.13), SIMDE_FLOAT32_C(11524256248627200.00), SIMDE_FLOAT32_C(  -223.74) } },
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
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    40.11), SIMDE_FLOAT32_C(   -19.39), SIMDE_FLOAT32_C(   -41.56), SIMDE_FLOAT32_C(    18.94),
        SIMDE_FLOAT32_C(    20.21), SIMDE_FLOAT32_C(    -9.24), SIMDE_FLOAT32_C(     9.43), SIMDE_FLOAT32_C(    17.33),
        SIMDE_FLOAT32_C(   -18.76), SIMDE_FLOAT32_C(   -10.09), SIMDE_FLOAT32_C(    -2.32), SIMDE_FLOAT32_C(   -49.26),
        SIMDE_FLOAT32_C(    -0.93), SIMDE_FLOAT32_C(   -20.05), SIMDE_FLOAT32_C(     5.19), SIMDE_FLOAT32_C(   -13.89) },
      UINT16_C( 7338),
      { SIMDE_FLOAT32_C(    -5.06), SIMDE_FLOAT32_C(    20.43), SIMDE_FLOAT32_C(    19.29), SIMDE_FLOAT32_C(    14.81),
        SIMDE_FLOAT32_C(   -19.15), SIMDE_FLOAT32_C(    10.65), SIMDE_FLOAT32_C(    30.77), SIMDE_FLOAT32_C(    19.33),
        SIMDE_FLOAT32_C(   -37.44), SIMDE_FLOAT32_C(    16.33), SIMDE_FLOAT32_C(   -10.19), SIMDE_FLOAT32_C(    15.64),
        SIMDE_FLOAT32_C(    -1.91), SIMDE_FLOAT32_C(    -5.87), SIMDE_FLOAT32_C(     7.39), SIMDE_FLOAT32_C(   -21.61) },
      { SIMDE_FLOAT32_C(    26.17), SIMDE_FLOAT32_C(   -22.61), SIMDE_FLOAT32_C(   -13.44), SIMDE_FLOAT32_C(    -3.70),
        SIMDE_FLOAT32_C(   -27.26), SIMDE_FLOAT32_C(    35.68), SIMDE_FLOAT32_C(   -28.70), SIMDE_FLOAT32_C(    -6.05),
        SIMDE_FLOAT32_C(    -6.33), SIMDE_FLOAT32_C(   -12.83), SIMDE_FLOAT32_C(   -10.27), SIMDE_FLOAT32_C(    40.33),
        SIMDE_FLOAT32_C(    11.67), SIMDE_FLOAT32_C(   -32.45), SIMDE_FLOAT32_C(   -38.41), SIMDE_FLOAT32_C(   -43.39) },
      { SIMDE_FLOAT32_C(    40.11),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -41.56),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(    20.21), SIMDE_FLOAT32_C(-13595241375124684800.00), SIMDE_FLOAT32_C(     9.43), SIMDE_FLOAT32_C(   -98.77),
        SIMDE_FLOAT32_C(   -18.76), SIMDE_FLOAT32_C(   -10.09), SIMDE_FLOAT32_C(   102.10), SIMDE_FLOAT32_C(7454851584.00),
        SIMDE_FLOAT32_C(-29246333428117108994491809792000.00), SIMDE_FLOAT32_C(   -20.05), SIMDE_FLOAT32_C(     5.19), SIMDE_FLOAT32_C(   -13.89) } },
    { { SIMDE_FLOAT32_C(   -10.57), SIMDE_FLOAT32_C(   -31.39), SIMDE_FLOAT32_C(    40.10), SIMDE_FLOAT32_C(    31.66),
        SIMDE_FLOAT32_C(    46.17), SIMDE_FLOAT32_C(   -12.96), SIMDE_FLOAT32_C(   -49.84), SIMDE_FLOAT32_C(    38.30),
        SIMDE_FLOAT32_C(    25.29), SIMDE_FLOAT32_C(   -49.07), SIMDE_FLOAT32_C(     4.13), SIMDE_FLOAT32_C(     6.28),
        SIMDE_FLOAT32_C(    14.00), SIMDE_FLOAT32_C(    -5.76), SIMDE_FLOAT32_C(    36.89), SIMDE_FLOAT32_C(    22.45) },
      UINT16_C( 9033),
      { SIMDE_FLOAT32_C(    37.99), SIMDE_FLOAT32_C(    30.89), SIMDE_FLOAT32_C(    21.42), SIMDE_FLOAT32_C(   -31.16),
        SIMDE_FLOAT32_C(    -8.46), SIMDE_FLOAT32_C(     2.19), SIMDE_FLOAT32_C(    38.17), SIMDE_FLOAT32_C(     4.10),
        SIMDE_FLOAT32_C(   -31.49), SIMDE_FLOAT32_C(   -22.02), SIMDE_FLOAT32_C(   -30.26), SIMDE_FLOAT32_C(    16.60),
        SIMDE_FLOAT32_C(    22.11), SIMDE_FLOAT32_C(    27.13), SIMDE_FLOAT32_C(    44.99), SIMDE_FLOAT32_C(    -1.71) },
      { SIMDE_FLOAT32_C(   -45.48), SIMDE_FLOAT32_C(   -18.45), SIMDE_FLOAT32_C(    44.59), SIMDE_FLOAT32_C(   -22.74),
        SIMDE_FLOAT32_C(   -32.76), SIMDE_FLOAT32_C(   -34.11), SIMDE_FLOAT32_C(    21.21), SIMDE_FLOAT32_C(    10.91),
        SIMDE_FLOAT32_C(     3.06), SIMDE_FLOAT32_C(   -39.06), SIMDE_FLOAT32_C(     1.24), SIMDE_FLOAT32_C(   -35.27),
        SIMDE_FLOAT32_C(   -21.51), SIMDE_FLOAT32_C(    12.83), SIMDE_FLOAT32_C(   -28.66), SIMDE_FLOAT32_C(   -33.52) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -31.39), SIMDE_FLOAT32_C(    40.10), SIMDE_FLOAT32_C(-28648408389142270321715532791808.00),
        SIMDE_FLOAT32_C(    46.17), SIMDE_FLOAT32_C(   -12.96), SIMDE_FLOAT32_C(   752.91), SIMDE_FLOAT32_C(    38.30),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   808.93), SIMDE_FLOAT32_C(     4.13), SIMDE_FLOAT32_C(     6.28),
        SIMDE_FLOAT32_C(    14.00), SIMDE_FLOAT32_C(   341.78), SIMDE_FLOAT32_C(    36.89), SIMDE_FLOAT32_C(    22.45) } },
    { { SIMDE_FLOAT32_C(   -36.79), SIMDE_FLOAT32_C(    22.61), SIMDE_FLOAT32_C(   -25.57), SIMDE_FLOAT32_C(    -5.55),
        SIMDE_FLOAT32_C(   -37.48), SIMDE_FLOAT32_C(    22.10), SIMDE_FLOAT32_C(    -4.80), SIMDE_FLOAT32_C(    11.58),
        SIMDE_FLOAT32_C(   -47.95), SIMDE_FLOAT32_C(   -49.61), SIMDE_FLOAT32_C(    47.70), SIMDE_FLOAT32_C(   -36.16),
        SIMDE_FLOAT32_C(   -13.89), SIMDE_FLOAT32_C(   -12.88), SIMDE_FLOAT32_C(   -17.54), SIMDE_FLOAT32_C(   -23.79) },
      UINT16_C(11160),
      { SIMDE_FLOAT32_C(    -6.28), SIMDE_FLOAT32_C(    42.76), SIMDE_FLOAT32_C(   -14.68), SIMDE_FLOAT32_C(    35.25),
        SIMDE_FLOAT32_C(    -5.05), SIMDE_FLOAT32_C(   -26.51), SIMDE_FLOAT32_C(   -10.65), SIMDE_FLOAT32_C(    13.46),
        SIMDE_FLOAT32_C(     1.47), SIMDE_FLOAT32_C(     9.09), SIMDE_FLOAT32_C(   -19.94), SIMDE_FLOAT32_C(   -26.41),
        SIMDE_FLOAT32_C(   -13.78), SIMDE_FLOAT32_C(   -24.94), SIMDE_FLOAT32_C(    21.87), SIMDE_FLOAT32_C(    -9.27) },
      { SIMDE_FLOAT32_C(     6.61), SIMDE_FLOAT32_C(    16.46), SIMDE_FLOAT32_C(    17.99), SIMDE_FLOAT32_C(    23.85),
        SIMDE_FLOAT32_C(    32.34), SIMDE_FLOAT32_C(   -10.80), SIMDE_FLOAT32_C(   -15.25), SIMDE_FLOAT32_C(   -14.60),
        SIMDE_FLOAT32_C(     0.14), SIMDE_FLOAT32_C(    35.99), SIMDE_FLOAT32_C(     0.13), SIMDE_FLOAT32_C(    28.63),
        SIMDE_FLOAT32_C(    -1.18), SIMDE_FLOAT32_C(    21.47), SIMDE_FLOAT32_C(    45.11), SIMDE_FLOAT32_C(    42.54) },
      { SIMDE_FLOAT32_C(   -36.79), SIMDE_FLOAT32_C(    22.61), SIMDE_FLOAT32_C(   -25.57), SIMDE_FLOAT32_C(   831.64),
        SIMDE_FLOAT32_C(  -199.74), SIMDE_FLOAT32_C(    22.10), SIMDE_FLOAT32_C(    -4.80), SIMDE_FLOAT32_C(  -184.10),
        SIMDE_FLOAT32_C(  5149.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    47.70), SIMDE_FLOAT32_C(  -791.14),
        SIMDE_FLOAT32_C(   -13.89), SIMDE_FLOAT32_C(  -544.58), SIMDE_FLOAT32_C(   -17.54), SIMDE_FLOAT32_C(   -23.79) } },
    { { SIMDE_FLOAT32_C(    13.26), SIMDE_FLOAT32_C(   -31.06), SIMDE_FLOAT32_C(   -33.07), SIMDE_FLOAT32_C(   -11.46),
        SIMDE_FLOAT32_C(   -30.13), SIMDE_FLOAT32_C(    21.06), SIMDE_FLOAT32_C(    44.83), SIMDE_FLOAT32_C(    33.87),
        SIMDE_FLOAT32_C(   -34.71), SIMDE_FLOAT32_C(    31.72), SIMDE_FLOAT32_C(     6.32), SIMDE_FLOAT32_C(   -21.53),
        SIMDE_FLOAT32_C(   -11.18), SIMDE_FLOAT32_C(    19.53), SIMDE_FLOAT32_C(   -48.93), SIMDE_FLOAT32_C(    13.24) },
      UINT16_C(26206),
      { SIMDE_FLOAT32_C(    14.23), SIMDE_FLOAT32_C(   -19.56), SIMDE_FLOAT32_C(    27.79), SIMDE_FLOAT32_C(   -40.83),
        SIMDE_FLOAT32_C(     3.93), SIMDE_FLOAT32_C(   -32.85), SIMDE_FLOAT32_C(    22.63), SIMDE_FLOAT32_C(   -44.60),
        SIMDE_FLOAT32_C(    26.24), SIMDE_FLOAT32_C(   -47.30), SIMDE_FLOAT32_C(   -21.01), SIMDE_FLOAT32_C(   -37.55),
        SIMDE_FLOAT32_C(   -22.25), SIMDE_FLOAT32_C(   -49.14), SIMDE_FLOAT32_C(     3.19), SIMDE_FLOAT32_C(    34.36) },
      { SIMDE_FLOAT32_C(    17.32), SIMDE_FLOAT32_C(   -28.82), SIMDE_FLOAT32_C(     8.21), SIMDE_FLOAT32_C(    -0.34),
        SIMDE_FLOAT32_C(    10.38), SIMDE_FLOAT32_C(    42.96), SIMDE_FLOAT32_C(    35.06), SIMDE_FLOAT32_C(   -39.48),
        SIMDE_FLOAT32_C(    28.96), SIMDE_FLOAT32_C(   -14.80), SIMDE_FLOAT32_C(    39.16), SIMDE_FLOAT32_C(   -22.22),
        SIMDE_FLOAT32_C(   -43.33), SIMDE_FLOAT32_C(    34.27), SIMDE_FLOAT32_C(   -29.68), SIMDE_FLOAT32_C(    20.89) },
      { SIMDE_FLOAT32_C(    13.26), SIMDE_FLOAT32_C(-6335470.50), SIMDE_FLOAT32_C(24108398694754935001990561792.00), SIMDE_FLOAT32_C(     2.39),
        SIMDE_FLOAT32_C(    10.56), SIMDE_FLOAT32_C(    21.06), SIMDE_FLOAT32_C(   836.71), SIMDE_FLOAT32_C(    33.87),
        SIMDE_FLOAT32_C(   -34.71), SIMDE_FLOAT32_C(   724.18), SIMDE_FLOAT32_C(  -812.68), SIMDE_FLOAT32_C(   -21.53),
        SIMDE_FLOAT32_C(   -11.18), SIMDE_FLOAT32_C( -1658.72), SIMDE_FLOAT32_C(11089674277748736.00), SIMDE_FLOAT32_C(    13.24) } },
    { { SIMDE_FLOAT32_C(   -21.50), SIMDE_FLOAT32_C(    26.01), SIMDE_FLOAT32_C(     2.52), SIMDE_FLOAT32_C(    14.53),
        SIMDE_FLOAT32_C(     5.83), SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C(    -0.31), SIMDE_FLOAT32_C(   -33.80),
        SIMDE_FLOAT32_C(    49.44), SIMDE_FLOAT32_C(   -46.69), SIMDE_FLOAT32_C(    26.48), SIMDE_FLOAT32_C(    41.39),
        SIMDE_FLOAT32_C(   -27.71), SIMDE_FLOAT32_C(    40.91), SIMDE_FLOAT32_C(    22.97), SIMDE_FLOAT32_C(   -19.66) },
      UINT16_C(60104),
      { SIMDE_FLOAT32_C(    -8.80), SIMDE_FLOAT32_C(    34.46), SIMDE_FLOAT32_C(   -32.34), SIMDE_FLOAT32_C(    -1.16),
        SIMDE_FLOAT32_C(   -16.24), SIMDE_FLOAT32_C(    -0.79), SIMDE_FLOAT32_C(   -44.42), SIMDE_FLOAT32_C(    16.14),
        SIMDE_FLOAT32_C(     8.49), SIMDE_FLOAT32_C(    27.24), SIMDE_FLOAT32_C(    -1.50), SIMDE_FLOAT32_C(     8.20),
        SIMDE_FLOAT32_C(    46.23), SIMDE_FLOAT32_C(   -42.70), SIMDE_FLOAT32_C(   -45.39), SIMDE_FLOAT32_C(    15.20) },
      { SIMDE_FLOAT32_C(    -4.01), SIMDE_FLOAT32_C(     2.49), SIMDE_FLOAT32_C(   -12.27), SIMDE_FLOAT32_C(    19.13),
        SIMDE_FLOAT32_C(    44.86), SIMDE_FLOAT32_C(   -28.34), SIMDE_FLOAT32_C(    36.06), SIMDE_FLOAT32_C(    -9.95),
        SIMDE_FLOAT32_C(   -14.84), SIMDE_FLOAT32_C(    27.43), SIMDE_FLOAT32_C(    15.88), SIMDE_FLOAT32_C(    -0.30),
        SIMDE_FLOAT32_C(   -12.65), SIMDE_FLOAT32_C(   -20.84), SIMDE_FLOAT32_C(    28.69), SIMDE_FLOAT32_C(    28.55) },
      { SIMDE_FLOAT32_C(   -21.50), SIMDE_FLOAT32_C(    26.01), SIMDE_FLOAT32_C(     2.52), SIMDE_FLOAT32_C(  5308.04),
        SIMDE_FLOAT32_C(     5.83), SIMDE_FLOAT32_C(    -0.53), SIMDE_FLOAT32_C( -1593.31), SIMDE_FLOAT32_C(  -194.04),
        SIMDE_FLOAT32_C(    49.44),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    26.48), SIMDE_FLOAT32_C(    38.94),
        SIMDE_FLOAT32_C(   -27.71), SIMDE_FLOAT32_C(  6304.04), SIMDE_FLOAT32_C( -1272.31), SIMDE_FLOAT32_C(11316723428884480.00) } },
    { { SIMDE_FLOAT32_C(    -9.07), SIMDE_FLOAT32_C(   -12.26), SIMDE_FLOAT32_C(    49.25), SIMDE_FLOAT32_C(    17.59),
        SIMDE_FLOAT32_C(   -14.60), SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(    -2.31), SIMDE_FLOAT32_C(    44.74),
        SIMDE_FLOAT32_C(     9.36), SIMDE_FLOAT32_C(   -21.73), SIMDE_FLOAT32_C(    24.43), SIMDE_FLOAT32_C(   -14.16),
        SIMDE_FLOAT32_C(   -28.77), SIMDE_FLOAT32_C(   -47.07), SIMDE_FLOAT32_C(   -38.14), SIMDE_FLOAT32_C(    23.76) },
      UINT16_C(  444),
      { SIMDE_FLOAT32_C(   -36.38), SIMDE_FLOAT32_C(    46.34), SIMDE_FLOAT32_C(   -22.61), SIMDE_FLOAT32_C(    -2.62),
        SIMDE_FLOAT32_C(    -4.44), SIMDE_FLOAT32_C(   -17.04), SIMDE_FLOAT32_C(   -36.48), SIMDE_FLOAT32_C(   -45.96),
        SIMDE_FLOAT32_C(   -39.80), SIMDE_FLOAT32_C(    12.02), SIMDE_FLOAT32_C(    12.25), SIMDE_FLOAT32_C(   -43.57),
        SIMDE_FLOAT32_C(    19.32), SIMDE_FLOAT32_C(    16.85), SIMDE_FLOAT32_C(    21.63), SIMDE_FLOAT32_C(   -34.69) },
      { SIMDE_FLOAT32_C(   -30.66), SIMDE_FLOAT32_C(   -40.63), SIMDE_FLOAT32_C(    34.45), SIMDE_FLOAT32_C(   -35.80),
        SIMDE_FLOAT32_C(   -18.97), SIMDE_FLOAT32_C(    20.51), SIMDE_FLOAT32_C(     4.25), SIMDE_FLOAT32_C(    16.18),
        SIMDE_FLOAT32_C(    -2.06), SIMDE_FLOAT32_C(   -29.87), SIMDE_FLOAT32_C(   -34.11), SIMDE_FLOAT32_C(    35.29),
        SIMDE_FLOAT32_C(    -0.71), SIMDE_FLOAT32_C(    44.57), SIMDE_FLOAT32_C(    13.84), SIMDE_FLOAT32_C(    12.91) },
      { SIMDE_FLOAT32_C(    -9.07), SIMDE_FLOAT32_C(   -12.26), SIMDE_FLOAT32_C(24782979302099898081476608000.00), SIMDE_FLOAT32_C(   110.88),
        SIMDE_FLOAT32_C(    69.16), SIMDE_FLOAT32_C(  -348.92), SIMDE_FLOAT32_C(    -2.31),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(-6323621.00), SIMDE_FLOAT32_C(   -21.73), SIMDE_FLOAT32_C(    24.43), SIMDE_FLOAT32_C(   -14.16),
        SIMDE_FLOAT32_C(   -28.77), SIMDE_FLOAT32_C(   -47.07), SIMDE_FLOAT32_C(   -38.14), SIMDE_FLOAT32_C(    23.76) } },
    { { SIMDE_FLOAT32_C(   -26.77), SIMDE_FLOAT32_C(   -32.86), SIMDE_FLOAT32_C(    33.88), SIMDE_FLOAT32_C(   -27.33),
        SIMDE_FLOAT32_C(   -29.55), SIMDE_FLOAT32_C(    10.36), SIMDE_FLOAT32_C(   -35.94), SIMDE_FLOAT32_C(    -7.26),
        SIMDE_FLOAT32_C(     1.27), SIMDE_FLOAT32_C(    37.03), SIMDE_FLOAT32_C(    23.08), SIMDE_FLOAT32_C(    44.54),
        SIMDE_FLOAT32_C(   -48.66), SIMDE_FLOAT32_C(   -35.98), SIMDE_FLOAT32_C(   -17.71), SIMDE_FLOAT32_C(   -49.41) },
      UINT16_C(17433),
      { SIMDE_FLOAT32_C(    40.92), SIMDE_FLOAT32_C(    41.23), SIMDE_FLOAT32_C(   -39.71), SIMDE_FLOAT32_C(   -13.53),
        SIMDE_FLOAT32_C(   -25.81), SIMDE_FLOAT32_C(   -26.19), SIMDE_FLOAT32_C(    -9.48), SIMDE_FLOAT32_C(   -15.60),
        SIMDE_FLOAT32_C(    35.83), SIMDE_FLOAT32_C(   -47.23), SIMDE_FLOAT32_C(    -9.17), SIMDE_FLOAT32_C(     5.15),
        SIMDE_FLOAT32_C(    19.62), SIMDE_FLOAT32_C(   -37.54), SIMDE_FLOAT32_C(    20.46), SIMDE_FLOAT32_C(    38.96) },
      { SIMDE_FLOAT32_C(   -28.17), SIMDE_FLOAT32_C(     4.91), SIMDE_FLOAT32_C(   -46.84), SIMDE_FLOAT32_C(     2.86),
        SIMDE_FLOAT32_C(   -24.58), SIMDE_FLOAT32_C(     7.42), SIMDE_FLOAT32_C(   -30.96), SIMDE_FLOAT32_C(    23.36),
        SIMDE_FLOAT32_C(    27.55), SIMDE_FLOAT32_C(   -15.07), SIMDE_FLOAT32_C(     8.65), SIMDE_FLOAT32_C(   -23.16),
        SIMDE_FLOAT32_C(   -20.50), SIMDE_FLOAT32_C(   -27.51), SIMDE_FLOAT32_C(    39.75), SIMDE_FLOAT32_C(   -29.58) },
      { SIMDE_FLOAT32_C(-6404245.00), SIMDE_FLOAT32_C(   -32.86), SIMDE_FLOAT32_C(    33.88), SIMDE_FLOAT32_C(  5249.69),
        SIMDE_FLOAT32_C(-13616351998377984000.00), SIMDE_FLOAT32_C(    10.36), SIMDE_FLOAT32_C(   -35.94), SIMDE_FLOAT32_C(    -7.26),
        SIMDE_FLOAT32_C(     1.27), SIMDE_FLOAT32_C(    37.03), SIMDE_FLOAT32_C(-13595241375124684800.00), SIMDE_FLOAT32_C(    44.54),
        SIMDE_FLOAT32_C(   -48.66), SIMDE_FLOAT32_C(   -35.98), SIMDE_FLOAT32_C(   792.20), SIMDE_FLOAT32_C(   -49.41) } },
    { { SIMDE_FLOAT32_C(     0.17), SIMDE_FLOAT32_C(   -20.71), SIMDE_FLOAT32_C(    12.43), SIMDE_FLOAT32_C(   -40.47),
        SIMDE_FLOAT32_C(     7.56), SIMDE_FLOAT32_C(   -13.14), SIMDE_FLOAT32_C(    -4.63), SIMDE_FLOAT32_C(    28.80),
        SIMDE_FLOAT32_C(   -10.21), SIMDE_FLOAT32_C(     7.23), SIMDE_FLOAT32_C(     2.56), SIMDE_FLOAT32_C(   -42.75),
        SIMDE_FLOAT32_C(   -25.09), SIMDE_FLOAT32_C(    25.79), SIMDE_FLOAT32_C(   -25.61), SIMDE_FLOAT32_C(   -41.21) },
      UINT16_C(18347),
      { SIMDE_FLOAT32_C(   -36.28), SIMDE_FLOAT32_C(   -49.96), SIMDE_FLOAT32_C(     6.89), SIMDE_FLOAT32_C(   -12.08),
        SIMDE_FLOAT32_C(   -26.15), SIMDE_FLOAT32_C(    47.41), SIMDE_FLOAT32_C(    22.32), SIMDE_FLOAT32_C(   -40.32),
        SIMDE_FLOAT32_C(   -49.82), SIMDE_FLOAT32_C(   -36.85), SIMDE_FLOAT32_C(    14.83), SIMDE_FLOAT32_C(    19.80),
        SIMDE_FLOAT32_C(   -24.39), SIMDE_FLOAT32_C(   -14.70), SIMDE_FLOAT32_C(     8.75), SIMDE_FLOAT32_C(    -2.56) },
      { SIMDE_FLOAT32_C(    40.20), SIMDE_FLOAT32_C(    11.92), SIMDE_FLOAT32_C(   -49.71), SIMDE_FLOAT32_C(   -34.38),
        SIMDE_FLOAT32_C(   -30.67), SIMDE_FLOAT32_C(   -30.67), SIMDE_FLOAT32_C(    38.98), SIMDE_FLOAT32_C(    46.88),
        SIMDE_FLOAT32_C(     4.26), SIMDE_FLOAT32_C(    -2.37), SIMDE_FLOAT32_C(   -26.28), SIMDE_FLOAT32_C(    33.77),
        SIMDE_FLOAT32_C(    20.13), SIMDE_FLOAT32_C(   -36.53), SIMDE_FLOAT32_C(   -45.81), SIMDE_FLOAT32_C(    33.85) },
      { SIMDE_FLOAT32_C( -1449.83), SIMDE_FLOAT32_C(7596932608.00), SIMDE_FLOAT32_C(    12.43), SIMDE_FLOAT32_C(   372.67),
        SIMDE_FLOAT32_C(     7.56), SIMDE_FLOAT32_C( -1464.61), SIMDE_FLOAT32_C(    -4.63), SIMDE_FLOAT32_C( -1852.89),
        SIMDE_FLOAT32_C(11287586370748416.00), SIMDE_FLOAT32_C(-9137542922240.00), SIMDE_FLOAT32_C(  4855.48), SIMDE_FLOAT32_C(   -42.75),
        SIMDE_FLOAT32_C(   -25.09), SIMDE_FLOAT32_C(    25.79), SIMDE_FLOAT32_C(  -425.92), SIMDE_FLOAT32_C(   -41.21) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 tmp, src, r;
    simde__m512bh a, b;

    src = simde_mm512_loadu_ps(test_vec[i].src);

    tmp = simde_mm512_loadu_ps(test_vec[i].a);
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm512_loadu_ps(test_vec[i].b);
    simde_memcpy(&b, &tmp, sizeof(tmp));

    r = simde_mm512_mask_dpbf16_ps(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_f32x16_full(8, 2, values, -50.0f, 50.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-50.0), SIMDE_FLOAT32_C(50.0));
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512bh a = HEDLEY_REINTERPRET_CAST(simde__m512bh, simde_test_x86_random_extract_f32x16(i, 2, 0, values));
    simde__m512bh b = HEDLEY_REINTERPRET_CAST(simde__m512bh, simde_test_x86_random_extract_f32x16(i, 2, 1, values));
    simde__m512 r = simde_mm512_mask_dpbf16_ps(src, k, a, b);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, HEDLEY_REINTERPRET_CAST(simde__m512, a), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, HEDLEY_REINTERPRET_CAST(simde__m512, b), SIMDE_TEST_VEC_POS_MIDDLE);
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
    { UINT16_C(25102),
      { SIMDE_FLOAT32_C(     1.43), SIMDE_FLOAT32_C(   -30.81), SIMDE_FLOAT32_C(    21.01), SIMDE_FLOAT32_C(   -45.33),
        SIMDE_FLOAT32_C(     6.52), SIMDE_FLOAT32_C(   -38.24), SIMDE_FLOAT32_C(     4.09), SIMDE_FLOAT32_C(     7.77),
        SIMDE_FLOAT32_C(   -44.96), SIMDE_FLOAT32_C(   -14.41), SIMDE_FLOAT32_C(    35.98), SIMDE_FLOAT32_C(   -36.04),
        SIMDE_FLOAT32_C(    23.66), SIMDE_FLOAT32_C(    23.77), SIMDE_FLOAT32_C(   -21.27), SIMDE_FLOAT32_C(   -28.54) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -23.70),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -33.23),
        SIMDE_FLOAT32_C(   -40.00), SIMDE_FLOAT32_C(   -22.41), SIMDE_FLOAT32_C(    -4.46), SIMDE_FLOAT32_C(   -27.67),
        SIMDE_FLOAT32_C(   -37.26), SIMDE_FLOAT32_C(    43.25), SIMDE_FLOAT32_C(     1.58), SIMDE_FLOAT32_C(   -13.57),
        SIMDE_FLOAT32_C(    10.83), SIMDE_FLOAT32_C(     1.90), SIMDE_FLOAT32_C(     4.95), SIMDE_FLOAT32_C(   -37.73) },
      { SIMDE_FLOAT32_C(    17.51),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -38.41),
        SIMDE_FLOAT32_C(    44.24), SIMDE_FLOAT32_C(    47.32), SIMDE_FLOAT32_C(     6.73), SIMDE_FLOAT32_C(    46.54),
        SIMDE_FLOAT32_C(    38.59), SIMDE_FLOAT32_C(   -34.53), SIMDE_FLOAT32_C(   -15.81), SIMDE_FLOAT32_C(   -10.96),
        SIMDE_FLOAT32_C(    -0.62), SIMDE_FLOAT32_C(   -40.76), SIMDE_FLOAT32_C(    -0.94), SIMDE_FLOAT32_C(     6.16) },
      { SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(7496008704.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C( -1506.54), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -53.59), SIMDE_FLOAT32_C(-6329626.00), SIMDE_FLOAT32_C(     0.00) } },
    #endif
    { UINT16_C(44252),
      { SIMDE_FLOAT32_C(   -42.44), SIMDE_FLOAT32_C(    34.94), SIMDE_FLOAT32_C(    47.47), SIMDE_FLOAT32_C(   -32.52),
        SIMDE_FLOAT32_C(    35.59), SIMDE_FLOAT32_C(   -27.88), SIMDE_FLOAT32_C(   -38.76), SIMDE_FLOAT32_C(    47.61),
        SIMDE_FLOAT32_C(   -19.62), SIMDE_FLOAT32_C(    46.39), SIMDE_FLOAT32_C(   -10.80), SIMDE_FLOAT32_C(   -11.07),
        SIMDE_FLOAT32_C(    37.92), SIMDE_FLOAT32_C(    40.62), SIMDE_FLOAT32_C(     8.12), SIMDE_FLOAT32_C(     8.93) },
      { SIMDE_FLOAT32_C(   -14.47), SIMDE_FLOAT32_C(     4.76), SIMDE_FLOAT32_C(    22.93), SIMDE_FLOAT32_C(    -4.47),
        SIMDE_FLOAT32_C(    32.35), SIMDE_FLOAT32_C(   -31.52), SIMDE_FLOAT32_C(    17.86), SIMDE_FLOAT32_C(    45.08),
        SIMDE_FLOAT32_C(   -38.27), SIMDE_FLOAT32_C(   -30.56), SIMDE_FLOAT32_C(   -18.49), SIMDE_FLOAT32_C(    22.55),
        SIMDE_FLOAT32_C(    21.34), SIMDE_FLOAT32_C(    36.46), SIMDE_FLOAT32_C(    34.83), SIMDE_FLOAT32_C(   -11.15) },
      { SIMDE_FLOAT32_C(    -8.35), SIMDE_FLOAT32_C(   -45.14), SIMDE_FLOAT32_C(     0.43), SIMDE_FLOAT32_C(   -14.11),
        SIMDE_FLOAT32_C(   -47.81), SIMDE_FLOAT32_C(   -42.83), SIMDE_FLOAT32_C(   -17.58), SIMDE_FLOAT32_C(    40.78),
        SIMDE_FLOAT32_C(   -27.36), SIMDE_FLOAT32_C(    16.61), SIMDE_FLOAT32_C(   -20.18), SIMDE_FLOAT32_C(    22.02),
        SIMDE_FLOAT32_C(    25.85), SIMDE_FLOAT32_C(    28.88), SIMDE_FLOAT32_C(   -21.82), SIMDE_FLOAT32_C(   -38.62) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(11089674277748736.00), SIMDE_FLOAT32_C(    30.32),
        SIMDE_FLOAT32_C(15976609750089381969920.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  5025.62), SIMDE_FLOAT32_C(  1881.36),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(7416054272.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1087.34), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    { UINT16_C(34951),
      { SIMDE_FLOAT32_C(    20.69), SIMDE_FLOAT32_C(    -0.61), SIMDE_FLOAT32_C(    22.41), SIMDE_FLOAT32_C(    25.74),
        SIMDE_FLOAT32_C(    34.98), SIMDE_FLOAT32_C(     8.39), SIMDE_FLOAT32_C(    39.69), SIMDE_FLOAT32_C(     8.64),
        SIMDE_FLOAT32_C(   -17.84), SIMDE_FLOAT32_C(   -31.58), SIMDE_FLOAT32_C(    30.10), SIMDE_FLOAT32_C(   -45.00),
        SIMDE_FLOAT32_C(     6.77), SIMDE_FLOAT32_C(    37.66), SIMDE_FLOAT32_C(    39.95), SIMDE_FLOAT32_C(     4.24) },
      { SIMDE_FLOAT32_C(   -16.36), SIMDE_FLOAT32_C(   -48.88), SIMDE_FLOAT32_C(     6.91), SIMDE_FLOAT32_C(   -34.01),
        SIMDE_FLOAT32_C(   -30.41), SIMDE_FLOAT32_C(   -25.24), SIMDE_FLOAT32_C(   -38.93), SIMDE_FLOAT32_C(   -18.68),
        SIMDE_FLOAT32_C(    -5.80), SIMDE_FLOAT32_C(    -7.41), SIMDE_FLOAT32_C(   -46.13), SIMDE_FLOAT32_C(   -34.46),
        SIMDE_FLOAT32_C(   -20.95), SIMDE_FLOAT32_C(    38.70), SIMDE_FLOAT32_C(     4.39), SIMDE_FLOAT32_C(    20.69) },
      { SIMDE_FLOAT32_C(    43.56), SIMDE_FLOAT32_C(   -45.18), SIMDE_FLOAT32_C(   -43.42), SIMDE_FLOAT32_C(    45.75),
        SIMDE_FLOAT32_C(   -38.01), SIMDE_FLOAT32_C(   -10.99), SIMDE_FLOAT32_C(    36.53), SIMDE_FLOAT32_C(   -15.37),
        SIMDE_FLOAT32_C(   -44.38), SIMDE_FLOAT32_C(   -33.64), SIMDE_FLOAT32_C(   -43.35), SIMDE_FLOAT32_C(    31.46),
        SIMDE_FLOAT32_C(    45.24), SIMDE_FLOAT32_C(   -15.17), SIMDE_FLOAT32_C(    42.84), SIMDE_FLOAT32_C(   -21.12) },
      { SIMDE_FLOAT32_C(-13567093877453619200.00), SIMDE_FLOAT32_C(  2193.14), SIMDE_FLOAT32_C(  -276.29), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  3986.41),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -428.88) } },
    { UINT16_C(61694),
      { SIMDE_FLOAT32_C(    26.35), SIMDE_FLOAT32_C(   -33.63), SIMDE_FLOAT32_C(    23.15), SIMDE_FLOAT32_C(   -43.27),
        SIMDE_FLOAT32_C(   -37.24), SIMDE_FLOAT32_C(   -37.65), SIMDE_FLOAT32_C(    -4.34), SIMDE_FLOAT32_C(   -49.32),
        SIMDE_FLOAT32_C(   -47.03), SIMDE_FLOAT32_C(   -46.22), SIMDE_FLOAT32_C(     9.61), SIMDE_FLOAT32_C(    48.27),
        SIMDE_FLOAT32_C(   -31.58), SIMDE_FLOAT32_C(   -19.69), SIMDE_FLOAT32_C(    -2.34), SIMDE_FLOAT32_C(    40.84) },
      { SIMDE_FLOAT32_C(   -14.05), SIMDE_FLOAT32_C(    -0.25), SIMDE_FLOAT32_C(    -5.13), SIMDE_FLOAT32_C(     5.54),
        SIMDE_FLOAT32_C(    24.51), SIMDE_FLOAT32_C(     5.94), SIMDE_FLOAT32_C(    36.86), SIMDE_FLOAT32_C(   -31.28),
        SIMDE_FLOAT32_C(    48.52), SIMDE_FLOAT32_C(    40.73), SIMDE_FLOAT32_C(   -15.74), SIMDE_FLOAT32_C(   -22.43),
        SIMDE_FLOAT32_C(    29.44), SIMDE_FLOAT32_C(    38.65), SIMDE_FLOAT32_C(    48.26), SIMDE_FLOAT32_C(    23.00) },
      { SIMDE_FLOAT32_C(    43.47), SIMDE_FLOAT32_C(   -45.15), SIMDE_FLOAT32_C(    18.75), SIMDE_FLOAT32_C(   -44.54),
        SIMDE_FLOAT32_C(    -6.15), SIMDE_FLOAT32_C(     5.29), SIMDE_FLOAT32_C(    -9.91), SIMDE_FLOAT32_C(    -0.53),
        SIMDE_FLOAT32_C(    21.64), SIMDE_FLOAT32_C(    -3.27), SIMDE_FLOAT32_C(   -19.07), SIMDE_FLOAT32_C(    16.88),
        SIMDE_FLOAT32_C(    31.57), SIMDE_FLOAT32_C(   -26.23), SIMDE_FLOAT32_C(    45.76), SIMDE_FLOAT32_C(   -32.49) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -22.38), SIMDE_FLOAT32_C(   -72.94), SIMDE_FLOAT32_C(  -289.41),
        SIMDE_FLOAT32_C(  -187.30), SIMDE_FLOAT32_C(    -6.29), SIMDE_FLOAT32_C(  -371.65), SIMDE_FLOAT32_C(   -32.84),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   893.73), SIMDE_FLOAT32_C( -1025.50), SIMDE_FLOAT32_C(  2205.10), SIMDE_FLOAT32_C(  -700.91) } },
    { UINT16_C( 6707),
      { SIMDE_FLOAT32_C(    -0.77), SIMDE_FLOAT32_C(    45.73), SIMDE_FLOAT32_C(    41.28), SIMDE_FLOAT32_C(    31.39),
        SIMDE_FLOAT32_C(   -35.85), SIMDE_FLOAT32_C(    21.38), SIMDE_FLOAT32_C(    36.39), SIMDE_FLOAT32_C(    20.92),
        SIMDE_FLOAT32_C(     9.04), SIMDE_FLOAT32_C(    26.34), SIMDE_FLOAT32_C(   -24.84), SIMDE_FLOAT32_C(    14.18),
        SIMDE_FLOAT32_C(     1.88), SIMDE_FLOAT32_C(   -48.49), SIMDE_FLOAT32_C(    30.55), SIMDE_FLOAT32_C(   -24.97) },
      { SIMDE_FLOAT32_C(    23.52), SIMDE_FLOAT32_C(    -9.37), SIMDE_FLOAT32_C(    23.05), SIMDE_FLOAT32_C(    -1.96),
        SIMDE_FLOAT32_C(    46.56), SIMDE_FLOAT32_C(     9.91), SIMDE_FLOAT32_C(    16.75), SIMDE_FLOAT32_C(    45.08),
        SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(   -48.99), SIMDE_FLOAT32_C(   -27.35), SIMDE_FLOAT32_C(   -19.92),
        SIMDE_FLOAT32_C(    39.66), SIMDE_FLOAT32_C(   -29.08), SIMDE_FLOAT32_C(   -46.92), SIMDE_FLOAT32_C(    33.13) },
      { SIMDE_FLOAT32_C(   -24.24), SIMDE_FLOAT32_C(    21.84), SIMDE_FLOAT32_C(    38.59), SIMDE_FLOAT32_C(    19.62),
        SIMDE_FLOAT32_C(   -22.88), SIMDE_FLOAT32_C(   -21.33), SIMDE_FLOAT32_C(   -30.91), SIMDE_FLOAT32_C(    48.77),
        SIMDE_FLOAT32_C(    25.40), SIMDE_FLOAT32_C(     0.02), SIMDE_FLOAT32_C(    15.65), SIMDE_FLOAT32_C(     6.97),
        SIMDE_FLOAT32_C(    23.79), SIMDE_FLOAT32_C(    11.41), SIMDE_FLOAT32_C(    24.48), SIMDE_FLOAT32_C(    -2.69) },
      { SIMDE_FLOAT32_C(-8782671249408.00), SIMDE_FLOAT32_C(16100548811834618019840.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C( -1099.54), SIMDE_FLOAT32_C(  -188.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -124.32),
        SIMDE_FLOAT32_C(   940.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(38880),
      { SIMDE_FLOAT32_C(   -12.62), SIMDE_FLOAT32_C(     3.90), SIMDE_FLOAT32_C(    43.99), SIMDE_FLOAT32_C(    -9.65),
        SIMDE_FLOAT32_C(     7.69), SIMDE_FLOAT32_C(     3.60), SIMDE_FLOAT32_C(   -11.38), SIMDE_FLOAT32_C(    26.11),
        SIMDE_FLOAT32_C(    33.91), SIMDE_FLOAT32_C(    36.28), SIMDE_FLOAT32_C(    16.95), SIMDE_FLOAT32_C(    39.95),
        SIMDE_FLOAT32_C(   -31.09), SIMDE_FLOAT32_C(   -33.82), SIMDE_FLOAT32_C(    35.68), SIMDE_FLOAT32_C(   -39.81) },
      { SIMDE_FLOAT32_C(   -47.97), SIMDE_FLOAT32_C(    -2.47), SIMDE_FLOAT32_C(    45.35), SIMDE_FLOAT32_C(    48.59),
        SIMDE_FLOAT32_C(   -42.55), SIMDE_FLOAT32_C(    12.10), SIMDE_FLOAT32_C(    43.68), SIMDE_FLOAT32_C(     8.09),
        SIMDE_FLOAT32_C(    13.12), SIMDE_FLOAT32_C(   -33.67), SIMDE_FLOAT32_C(    38.18), SIMDE_FLOAT32_C(     2.78),
        SIMDE_FLOAT32_C(   -12.75), SIMDE_FLOAT32_C(    41.26), SIMDE_FLOAT32_C(   -14.10), SIMDE_FLOAT32_C(    13.01) },
      { SIMDE_FLOAT32_C(    13.10), SIMDE_FLOAT32_C(   -25.51), SIMDE_FLOAT32_C(   -17.37), SIMDE_FLOAT32_C(    40.23),
        SIMDE_FLOAT32_C(     3.16), SIMDE_FLOAT32_C(     1.71), SIMDE_FLOAT32_C(    38.99), SIMDE_FLOAT32_C(   -21.44),
        SIMDE_FLOAT32_C(   -48.27), SIMDE_FLOAT32_C(     4.64), SIMDE_FLOAT32_C(    35.53), SIMDE_FLOAT32_C(    25.52),
        SIMDE_FLOAT32_C(   -33.95), SIMDE_FLOAT32_C(    10.01), SIMDE_FLOAT32_C(   -27.17), SIMDE_FLOAT32_C(   -31.92) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    24.15), SIMDE_FLOAT32_C(24752756156609532352108953600.00), SIMDE_FLOAT32_C(  -146.23),
        SIMDE_FLOAT32_C(  -600.43), SIMDE_FLOAT32_C(-19656850484944898202009600.00), SIMDE_FLOAT32_C(  1365.95), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   399.22), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  4742.56) } },
    { UINT16_C(   71),
      { SIMDE_FLOAT32_C(    31.57), SIMDE_FLOAT32_C(    33.96), SIMDE_FLOAT32_C(    20.76), SIMDE_FLOAT32_C(    -9.39),
        SIMDE_FLOAT32_C(    10.30), SIMDE_FLOAT32_C(    45.92), SIMDE_FLOAT32_C(   -45.22), SIMDE_FLOAT32_C(   -37.82),
        SIMDE_FLOAT32_C(    47.43), SIMDE_FLOAT32_C(    35.33), SIMDE_FLOAT32_C(   -12.79), SIMDE_FLOAT32_C(   -44.33),
        SIMDE_FLOAT32_C(    28.64), SIMDE_FLOAT32_C(    24.59), SIMDE_FLOAT32_C(     9.58), SIMDE_FLOAT32_C(    22.63) },
      { SIMDE_FLOAT32_C(   -42.45), SIMDE_FLOAT32_C(   -31.82), SIMDE_FLOAT32_C(   -33.33), SIMDE_FLOAT32_C(   -35.00),
        SIMDE_FLOAT32_C(    30.28), SIMDE_FLOAT32_C(   -39.65), SIMDE_FLOAT32_C(    23.09), SIMDE_FLOAT32_C(    -6.60),
        SIMDE_FLOAT32_C(   -23.32), SIMDE_FLOAT32_C(    11.27), SIMDE_FLOAT32_C(    46.18), SIMDE_FLOAT32_C(    13.93),
        SIMDE_FLOAT32_C(     2.53), SIMDE_FLOAT32_C(   -17.92), SIMDE_FLOAT32_C(   -23.05), SIMDE_FLOAT32_C(   -34.37) },
      { SIMDE_FLOAT32_C(     6.57), SIMDE_FLOAT32_C(     9.58), SIMDE_FLOAT32_C(   -44.14), SIMDE_FLOAT32_C(   -40.27),
        SIMDE_FLOAT32_C(   -38.71), SIMDE_FLOAT32_C(    44.85), SIMDE_FLOAT32_C(   -11.71), SIMDE_FLOAT32_C(   -36.98),
        SIMDE_FLOAT32_C(    -0.51), SIMDE_FLOAT32_C(   -26.17), SIMDE_FLOAT32_C(    38.55), SIMDE_FLOAT32_C(    15.54),
        SIMDE_FLOAT32_C(    33.84), SIMDE_FLOAT32_C(   -38.62), SIMDE_FLOAT32_C(    33.61), SIMDE_FLOAT32_C(    41.39) },
      { SIMDE_FLOAT32_C(-6324086.00), SIMDE_FLOAT32_C(  -269.65), SIMDE_FLOAT32_C(  1483.76), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-9526774333440.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(59587),
      { SIMDE_FLOAT32_C(   -45.42), SIMDE_FLOAT32_C(    42.16), SIMDE_FLOAT32_C(     5.68), SIMDE_FLOAT32_C(    -0.26),
        SIMDE_FLOAT32_C(   -46.36), SIMDE_FLOAT32_C(   -11.42), SIMDE_FLOAT32_C(   -15.73), SIMDE_FLOAT32_C(    11.63),
        SIMDE_FLOAT32_C(    -5.26), SIMDE_FLOAT32_C(    -0.56), SIMDE_FLOAT32_C(   -49.45), SIMDE_FLOAT32_C(    24.59),
        SIMDE_FLOAT32_C(   -19.00), SIMDE_FLOAT32_C(   -26.80), SIMDE_FLOAT32_C(    24.80), SIMDE_FLOAT32_C(    -0.28) },
      { SIMDE_FLOAT32_C(    -6.13), SIMDE_FLOAT32_C(   -49.62), SIMDE_FLOAT32_C(   -41.61), SIMDE_FLOAT32_C(   -31.99),
        SIMDE_FLOAT32_C(   -37.47), SIMDE_FLOAT32_C(   -37.25), SIMDE_FLOAT32_C(   -45.75), SIMDE_FLOAT32_C(    31.81),
        SIMDE_FLOAT32_C(   -17.76), SIMDE_FLOAT32_C(   -41.55), SIMDE_FLOAT32_C(   -13.04), SIMDE_FLOAT32_C(   -42.15),
        SIMDE_FLOAT32_C(   -45.33), SIMDE_FLOAT32_C(    21.28), SIMDE_FLOAT32_C(   -37.89), SIMDE_FLOAT32_C(   -14.13) },
      { SIMDE_FLOAT32_C(   -30.66), SIMDE_FLOAT32_C(   -21.01), SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(   -30.95),
        SIMDE_FLOAT32_C(    40.55), SIMDE_FLOAT32_C(    15.98), SIMDE_FLOAT32_C(   -42.19), SIMDE_FLOAT32_C(   -49.08),
        SIMDE_FLOAT32_C(    -4.67), SIMDE_FLOAT32_C(   -36.17), SIMDE_FLOAT32_C(    15.56), SIMDE_FLOAT32_C(    -8.78),
        SIMDE_FLOAT32_C(   -46.32), SIMDE_FLOAT32_C(   -45.14), SIMDE_FLOAT32_C(    -7.85), SIMDE_FLOAT32_C(    -2.45) },
      { SIMDE_FLOAT32_C(   142.16), SIMDE_FLOAT32_C(7402292224.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1905.77),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-9301288550400.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -983.05), SIMDE_FLOAT32_C(   320.90), SIMDE_FLOAT32_C(    34.15) } },
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
