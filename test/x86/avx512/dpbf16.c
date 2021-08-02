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
    { { SIMDE_FLOAT32_C(     0.93), SIMDE_FLOAT32_C(   -30.68), SIMDE_FLOAT32_C(     7.59), SIMDE_FLOAT32_C(     4.46) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -27.99),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    45.72) },
      { SIMDE_FLOAT32_C(    -2.47),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.29) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF } },
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
    simde__m128 tmp;

    simde__m128 src = simde_mm_loadu_ps(test_vec[i].src);

    tmp = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128bh a;
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128bh b;
    simde_memcpy(&b, &tmp, sizeof(tmp));

    simde__m128 r = simde_mm_dpbf16_ps(src, a, b);
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
    { { SIMDE_FLOAT32_C(    35.52), SIMDE_FLOAT32_C(   -15.16), SIMDE_FLOAT32_C(    12.96), SIMDE_FLOAT32_C(   -37.51) },
      UINT8_C( 28),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    37.95),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -46.79) },
      { SIMDE_FLOAT32_C(    12.78),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -34.41) },
      { SIMDE_FLOAT32_C(    35.52), SIMDE_FLOAT32_C(   -15.16),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  1563.68) } },
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
    simde__m128 tmp;

    simde__m128 src = simde_mm_loadu_ps(test_vec[i].src);

    tmp = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128bh a;
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128bh b;
    simde_memcpy(&b, &tmp, sizeof(tmp));

    simde__m128 r = simde_mm_mask_dpbf16_ps(src, test_vec[i].k, a, b);
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
    { UINT8_C(199),
      { SIMDE_FLOAT32_C(   -22.83), SIMDE_FLOAT32_C(    28.42), SIMDE_FLOAT32_C(    20.82), SIMDE_FLOAT32_C(   -21.24) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    29.78),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    44.29) },
      { SIMDE_FLOAT32_C(   -22.83),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    29.04) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00) } },
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
    simde__m128 tmp;

    simde__m128 src = simde_mm_loadu_ps(test_vec[i].src);

    tmp = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128bh a;
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm_loadu_ps(test_vec[i].b);
    simde__m128bh b;
    simde_memcpy(&b, &tmp, sizeof(tmp));

    simde__m128 r = simde_mm_maskz_dpbf16_ps(test_vec[i].k, src, a, b);
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
    { { SIMDE_FLOAT32_C(   -43.55), SIMDE_FLOAT32_C(   -40.45), SIMDE_FLOAT32_C(    32.76), SIMDE_FLOAT32_C(   -28.04),
        SIMDE_FLOAT32_C(   -49.60), SIMDE_FLOAT32_C(    -3.34), SIMDE_FLOAT32_C(   -24.54), SIMDE_FLOAT32_C(    -4.35) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    21.20),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -15.30),
        SIMDE_FLOAT32_C(   -19.91), SIMDE_FLOAT32_C(   -23.31), SIMDE_FLOAT32_C(     4.99), SIMDE_FLOAT32_C(   -16.82) },
      { SIMDE_FLOAT32_C(   -40.48),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -43.54),
        SIMDE_FLOAT32_C(    42.85), SIMDE_FLOAT32_C(   -44.25), SIMDE_FLOAT32_C(   -25.14), SIMDE_FLOAT32_C(    17.55) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   635.34),
        SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(  1025.47), SIMDE_FLOAT32_C(  -149.38), SIMDE_FLOAT32_C(  -297.48) } },
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
    simde__m256 tmp;

    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);

    tmp = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256bh a;
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256bh b;
    simde_memcpy(&b, &tmp, sizeof(tmp));

    simde__m256 r = simde_mm256_dpbf16_ps(src, a, b);
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
    simde__m256 tmp;

    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);

    tmp = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256bh a;
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256bh b;
    simde_memcpy(&b, &tmp, sizeof(tmp));

    simde__m256 r = simde_mm256_mask_dpbf16_ps(src, test_vec[i].k, a, b);
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
    { UINT8_C(205),
      { SIMDE_FLOAT32_C(   -36.42), SIMDE_FLOAT32_C(   -49.03), SIMDE_FLOAT32_C(   -38.95), SIMDE_FLOAT32_C(    12.54),
        SIMDE_FLOAT32_C(   -41.04), SIMDE_FLOAT32_C(    38.86), SIMDE_FLOAT32_C(    -1.22), SIMDE_FLOAT32_C(   -10.59) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -49.55),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    27.62),
        SIMDE_FLOAT32_C(   -28.81), SIMDE_FLOAT32_C(    21.94), SIMDE_FLOAT32_C(    12.16), SIMDE_FLOAT32_C(    -8.39) },
      { SIMDE_FLOAT32_C(    34.31),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -33.23),
        SIMDE_FLOAT32_C(   -18.34), SIMDE_FLOAT32_C(   -38.83), SIMDE_FLOAT32_C(   -36.16), SIMDE_FLOAT32_C(    49.05) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF,      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -437.72), SIMDE_FLOAT32_C(  -420.96) } },
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
    simde__m256 tmp;

    simde__m256 src = simde_mm256_loadu_ps(test_vec[i].src);

    tmp = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m256bh a;
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm256_loadu_ps(test_vec[i].b);
    simde__m256bh b;
    simde_memcpy(&b, &tmp, sizeof(tmp));

    simde__m256 r = simde_mm256_maskz_dpbf16_ps(test_vec[i].k, src, a, b);
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
    { { SIMDE_FLOAT32_C(    10.45), SIMDE_FLOAT32_C(    -1.65), SIMDE_FLOAT32_C(    39.63), SIMDE_FLOAT32_C(    10.98),
        SIMDE_FLOAT32_C(    48.46), SIMDE_FLOAT32_C(   -40.71), SIMDE_FLOAT32_C(    35.28), SIMDE_FLOAT32_C(   -23.94),
        SIMDE_FLOAT32_C(   -42.14), SIMDE_FLOAT32_C(    35.09), SIMDE_FLOAT32_C(    44.26), SIMDE_FLOAT32_C(    23.02),
        SIMDE_FLOAT32_C(    -9.31), SIMDE_FLOAT32_C(    -2.26), SIMDE_FLOAT32_C(    40.69), SIMDE_FLOAT32_C(     7.30) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    20.23),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     5.98),
        SIMDE_FLOAT32_C(   -16.13), SIMDE_FLOAT32_C(    31.47), SIMDE_FLOAT32_C(    47.72), SIMDE_FLOAT32_C(   -31.89),
        SIMDE_FLOAT32_C(     0.65), SIMDE_FLOAT32_C(    37.32), SIMDE_FLOAT32_C(    34.37), SIMDE_FLOAT32_C(    47.67),
        SIMDE_FLOAT32_C(   -23.25), SIMDE_FLOAT32_C(   -42.88), SIMDE_FLOAT32_C(    21.15), SIMDE_FLOAT32_C(    26.22) },
      { SIMDE_FLOAT32_C(    29.33),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.31),
        SIMDE_FLOAT32_C(   -13.39), SIMDE_FLOAT32_C(    29.00), SIMDE_FLOAT32_C(     8.81), SIMDE_FLOAT32_C(    16.08),
        SIMDE_FLOAT32_C(   -26.02), SIMDE_FLOAT32_C(    49.37), SIMDE_FLOAT32_C(    -4.57), SIMDE_FLOAT32_C(    10.15),
        SIMDE_FLOAT32_C(    -6.00), SIMDE_FLOAT32_C(     0.82), SIMDE_FLOAT32_C(   -15.51), SIMDE_FLOAT32_C(    -7.31) },
      { SIMDE_FLOAT32_C(    10.45), SIMDE_FLOAT32_C(    -1.65), SIMDE_FLOAT32_C(    39.63), SIMDE_FLOAT32_C(-9526774333440.00),
        SIMDE_FLOAT32_C(    48.46), SIMDE_FLOAT32_C(   -40.71),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -23.94),
                   SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    24.86),
        SIMDE_FLOAT32_C(   206.36), SIMDE_FLOAT32_C(   907.61), SIMDE_FLOAT32_C(   456.32), SIMDE_FLOAT32_C(  -502.70) } },
    { { SIMDE_FLOAT32_C(     7.02), SIMDE_FLOAT32_C(   -30.08), SIMDE_FLOAT32_C(    36.21), SIMDE_FLOAT32_C(     8.40),
        SIMDE_FLOAT32_C(    31.05), SIMDE_FLOAT32_C(    23.14), SIMDE_FLOAT32_C(    45.88), SIMDE_FLOAT32_C(    46.21),
        SIMDE_FLOAT32_C(     7.68), SIMDE_FLOAT32_C(    36.16), SIMDE_FLOAT32_C(   -30.16), SIMDE_FLOAT32_C(   -47.47),
        SIMDE_FLOAT32_C(   -27.11), SIMDE_FLOAT32_C(    43.35), SIMDE_FLOAT32_C(   -45.88), SIMDE_FLOAT32_C(    33.33) },
      { SIMDE_FLOAT32_C(   -28.95), SIMDE_FLOAT32_C(   -35.73), SIMDE_FLOAT32_C(    48.67), SIMDE_FLOAT32_C(     4.92),
        SIMDE_FLOAT32_C(    45.74), SIMDE_FLOAT32_C(    46.39), SIMDE_FLOAT32_C(    23.04), SIMDE_FLOAT32_C(    -3.61),
        SIMDE_FLOAT32_C(    33.71), SIMDE_FLOAT32_C(     7.41), SIMDE_FLOAT32_C(    -5.94), SIMDE_FLOAT32_C(   -39.54),
        SIMDE_FLOAT32_C(    14.52), SIMDE_FLOAT32_C(   -34.79), SIMDE_FLOAT32_C(    36.68), SIMDE_FLOAT32_C(    -6.15) },
      { SIMDE_FLOAT32_C(   -46.24), SIMDE_FLOAT32_C(   -41.12), SIMDE_FLOAT32_C(    44.16), SIMDE_FLOAT32_C(    -9.64),
        SIMDE_FLOAT32_C(    37.89), SIMDE_FLOAT32_C(     2.97), SIMDE_FLOAT32_C(   -43.55), SIMDE_FLOAT32_C(   -38.13),
        SIMDE_FLOAT32_C(     2.34), SIMDE_FLOAT32_C(     1.88), SIMDE_FLOAT32_C(    22.02), SIMDE_FLOAT32_C(    46.35),
        SIMDE_FLOAT32_C(   -47.30), SIMDE_FLOAT32_C(   -43.49), SIMDE_FLOAT32_C(   -10.97), SIMDE_FLOAT32_C(   -26.25) },
      { SIMDE_FLOAT32_C(15744368640.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(7872184320.00), SIMDE_FLOAT32_C(23890792047224301750543450112.00),
        SIMDE_FLOAT32_C(7872189440.00), SIMDE_FLOAT32_C(7872184320.00), SIMDE_FLOAT32_C(7872189440.00), SIMDE_FLOAT32_C(7872184320.00),
        SIMDE_FLOAT32_C(7872185856.00), SIMDE_FLOAT32_C(7872185856.00), SIMDE_FLOAT32_C(7872186368.00), SIMDE_FLOAT32_C(7872184320.00),
        SIMDE_FLOAT32_C(7872185856.00), SIMDE_FLOAT32_C(7872184320.00), SIMDE_FLOAT32_C(7872183296.00), SIMDE_FLOAT32_C(7872184320.00) } },
    { { SIMDE_FLOAT32_C(    44.53), SIMDE_FLOAT32_C(    48.88), SIMDE_FLOAT32_C(   -26.35), SIMDE_FLOAT32_C(    25.58),
        SIMDE_FLOAT32_C(    22.02), SIMDE_FLOAT32_C(   -30.47), SIMDE_FLOAT32_C(    21.79), SIMDE_FLOAT32_C(   -20.30),
        SIMDE_FLOAT32_C(   -44.31), SIMDE_FLOAT32_C(    41.63), SIMDE_FLOAT32_C(   -17.76), SIMDE_FLOAT32_C(   -21.42),
        SIMDE_FLOAT32_C(    34.98), SIMDE_FLOAT32_C(   -13.65), SIMDE_FLOAT32_C(   -38.09), SIMDE_FLOAT32_C(   -23.31) },
      { SIMDE_FLOAT32_C(    40.03), SIMDE_FLOAT32_C(   -20.27), SIMDE_FLOAT32_C(   -10.59), SIMDE_FLOAT32_C(   -25.88),
        SIMDE_FLOAT32_C(    31.44), SIMDE_FLOAT32_C(   -47.68), SIMDE_FLOAT32_C(    -8.07), SIMDE_FLOAT32_C(    40.55),
        SIMDE_FLOAT32_C(   -40.71), SIMDE_FLOAT32_C(    20.19), SIMDE_FLOAT32_C(    14.19), SIMDE_FLOAT32_C(   -18.53),
        SIMDE_FLOAT32_C(    35.14), SIMDE_FLOAT32_C(    31.67), SIMDE_FLOAT32_C(     7.41), SIMDE_FLOAT32_C(   -41.03) },
      { SIMDE_FLOAT32_C(    43.31), SIMDE_FLOAT32_C(   -26.29), SIMDE_FLOAT32_C(   -29.31), SIMDE_FLOAT32_C(     7.91),
        SIMDE_FLOAT32_C(    46.45), SIMDE_FLOAT32_C(    -5.72), SIMDE_FLOAT32_C(    24.87), SIMDE_FLOAT32_C(   -28.92),
        SIMDE_FLOAT32_C(   -10.11), SIMDE_FLOAT32_C(    38.16), SIMDE_FLOAT32_C(    -1.61), SIMDE_FLOAT32_C(    -7.99),
        SIMDE_FLOAT32_C(    -9.50), SIMDE_FLOAT32_C(    49.46), SIMDE_FLOAT32_C(    14.90), SIMDE_FLOAT32_C(   -19.47) },
      { SIMDE_FLOAT32_C(    44.53), SIMDE_FLOAT32_C(    48.88),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    25.58),
        SIMDE_FLOAT32_C(    22.02), SIMDE_FLOAT32_C(   -30.47), SIMDE_FLOAT32_C(-9631464161280.00), SIMDE_FLOAT32_C(7930118144.00),
        SIMDE_FLOAT32_C(  1685.69), SIMDE_FLOAT32_C(   573.19), SIMDE_FLOAT32_C(   291.19), SIMDE_FLOAT32_C(  -225.99),
        SIMDE_FLOAT32_C(  1486.07), SIMDE_FLOAT32_C(   257.99), SIMDE_FLOAT32_C(  -237.64), SIMDE_FLOAT32_C( -1192.75) } },
    { { SIMDE_FLOAT32_C(   -19.89), SIMDE_FLOAT32_C(     6.23), SIMDE_FLOAT32_C(    16.85), SIMDE_FLOAT32_C(   -16.85),
        SIMDE_FLOAT32_C(    35.82), SIMDE_FLOAT32_C(   -16.92), SIMDE_FLOAT32_C(    -5.95), SIMDE_FLOAT32_C(   -49.49),
        SIMDE_FLOAT32_C(    43.57), SIMDE_FLOAT32_C(   -22.02), SIMDE_FLOAT32_C(     5.88), SIMDE_FLOAT32_C(   -48.20),
        SIMDE_FLOAT32_C(   -47.41), SIMDE_FLOAT32_C(    18.55), SIMDE_FLOAT32_C(    17.06), SIMDE_FLOAT32_C(    47.12) },
      { SIMDE_FLOAT32_C(   -20.81), SIMDE_FLOAT32_C(   -45.68), SIMDE_FLOAT32_C(     4.65), SIMDE_FLOAT32_C(   -39.37),
        SIMDE_FLOAT32_C(   -43.36), SIMDE_FLOAT32_C(    46.58), SIMDE_FLOAT32_C(   -48.81), SIMDE_FLOAT32_C(   -34.07),
        SIMDE_FLOAT32_C(    16.77), SIMDE_FLOAT32_C(    15.37), SIMDE_FLOAT32_C(    -2.60), SIMDE_FLOAT32_C(     1.91),
        SIMDE_FLOAT32_C(    -2.96), SIMDE_FLOAT32_C(   -45.19), SIMDE_FLOAT32_C(    10.88), SIMDE_FLOAT32_C(    -9.65) },
      { SIMDE_FLOAT32_C(   -21.49), SIMDE_FLOAT32_C(    31.57), SIMDE_FLOAT32_C(    48.26), SIMDE_FLOAT32_C(   -25.03),
        SIMDE_FLOAT32_C(   -24.15), SIMDE_FLOAT32_C(    23.13), SIMDE_FLOAT32_C(    -3.96), SIMDE_FLOAT32_C(    15.74),
        SIMDE_FLOAT32_C(    11.29), SIMDE_FLOAT32_C(    44.44), SIMDE_FLOAT32_C(   -42.25), SIMDE_FLOAT32_C(   -48.21),
        SIMDE_FLOAT32_C(    43.89), SIMDE_FLOAT32_C(    22.65), SIMDE_FLOAT32_C(   -17.68), SIMDE_FLOAT32_C(   -26.91) },
      {     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(    17.43), SIMDE_FLOAT32_C(    40.71), SIMDE_FLOAT32_C(    22.70), SIMDE_FLOAT32_C(   -10.55),
        SIMDE_FLOAT32_C(   -39.76), SIMDE_FLOAT32_C(    -5.51), SIMDE_FLOAT32_C(    19.16), SIMDE_FLOAT32_C(   -34.07),
        SIMDE_FLOAT32_C(   -13.88), SIMDE_FLOAT32_C(   -48.61), SIMDE_FLOAT32_C(    -5.50), SIMDE_FLOAT32_C(   -28.90),
        SIMDE_FLOAT32_C(   -12.25), SIMDE_FLOAT32_C(     6.42), SIMDE_FLOAT32_C(    -2.22), SIMDE_FLOAT32_C(    17.85) },
      { SIMDE_FLOAT32_C(    26.97), SIMDE_FLOAT32_C(    36.97), SIMDE_FLOAT32_C(   -16.28), SIMDE_FLOAT32_C(    33.61),
        SIMDE_FLOAT32_C(    33.55), SIMDE_FLOAT32_C(   -15.09), SIMDE_FLOAT32_C(    49.55), SIMDE_FLOAT32_C(     0.31),
        SIMDE_FLOAT32_C(   -49.72), SIMDE_FLOAT32_C(    -3.05), SIMDE_FLOAT32_C(   -47.78), SIMDE_FLOAT32_C(    -2.68),
        SIMDE_FLOAT32_C(     1.75), SIMDE_FLOAT32_C(    13.10), SIMDE_FLOAT32_C(    37.66), SIMDE_FLOAT32_C(    30.27) },
      { SIMDE_FLOAT32_C(    -5.32), SIMDE_FLOAT32_C(    35.92), SIMDE_FLOAT32_C(   -44.76), SIMDE_FLOAT32_C(    20.53),
        SIMDE_FLOAT32_C(     9.05), SIMDE_FLOAT32_C(     1.28), SIMDE_FLOAT32_C(   -13.72), SIMDE_FLOAT32_C(   -29.66),
        SIMDE_FLOAT32_C(    -4.29), SIMDE_FLOAT32_C(    -5.97), SIMDE_FLOAT32_C(   -27.87), SIMDE_FLOAT32_C(   -10.39),
        SIMDE_FLOAT32_C(   -33.32), SIMDE_FLOAT32_C(     4.44), SIMDE_FLOAT32_C(    12.69), SIMDE_FLOAT32_C(    43.66) },
      { SIMDE_FLOAT32_C(     9.02), SIMDE_FLOAT32_C(7759462400.00), SIMDE_FLOAT32_C(    18.49), SIMDE_FLOAT32_C(23890792047224301750543450112.00),
        SIMDE_FLOAT32_C(   -48.45),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    14.95), SIMDE_FLOAT32_C(   -42.74),
        SIMDE_FLOAT32_C(  -160.86), SIMDE_FLOAT32_C(  1261.00), SIMDE_FLOAT32_C(   717.48), SIMDE_FLOAT32_C(   653.64),
        SIMDE_FLOAT32_C(   285.04), SIMDE_FLOAT32_C(   -16.97), SIMDE_FLOAT32_C(  -683.96), SIMDE_FLOAT32_C(     4.50) } },
    { { SIMDE_FLOAT32_C(   -49.14), SIMDE_FLOAT32_C(    -4.56), SIMDE_FLOAT32_C(   -19.71), SIMDE_FLOAT32_C(   -38.90),
        SIMDE_FLOAT32_C(    39.93), SIMDE_FLOAT32_C(    49.45), SIMDE_FLOAT32_C(   -22.97), SIMDE_FLOAT32_C(   -23.96),
        SIMDE_FLOAT32_C(   -49.16), SIMDE_FLOAT32_C(    21.53), SIMDE_FLOAT32_C(    -2.86), SIMDE_FLOAT32_C(   -11.41),
        SIMDE_FLOAT32_C(   -22.05), SIMDE_FLOAT32_C(    44.92), SIMDE_FLOAT32_C(   -43.56), SIMDE_FLOAT32_C(    -9.41) },
      { SIMDE_FLOAT32_C(     6.73), SIMDE_FLOAT32_C(   -26.28), SIMDE_FLOAT32_C(    24.84), SIMDE_FLOAT32_C(    38.05),
        SIMDE_FLOAT32_C(   -49.47), SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(   -30.35), SIMDE_FLOAT32_C(   -25.70),
        SIMDE_FLOAT32_C(   -22.40), SIMDE_FLOAT32_C(    48.57), SIMDE_FLOAT32_C(    49.81), SIMDE_FLOAT32_C(    18.20),
        SIMDE_FLOAT32_C(    15.16), SIMDE_FLOAT32_C(     5.60), SIMDE_FLOAT32_C(     3.48), SIMDE_FLOAT32_C(   -32.33) },
      { SIMDE_FLOAT32_C(   -33.38), SIMDE_FLOAT32_C(   -40.71), SIMDE_FLOAT32_C(   -20.77), SIMDE_FLOAT32_C(   -21.09),
        SIMDE_FLOAT32_C(   -48.63), SIMDE_FLOAT32_C(    11.13), SIMDE_FLOAT32_C(    36.92), SIMDE_FLOAT32_C(   -12.52),
        SIMDE_FLOAT32_C(   -34.84), SIMDE_FLOAT32_C(    34.54), SIMDE_FLOAT32_C(    40.28), SIMDE_FLOAT32_C(   -26.37),
        SIMDE_FLOAT32_C(    -5.15), SIMDE_FLOAT32_C(   -13.27), SIMDE_FLOAT32_C(    23.51), SIMDE_FLOAT32_C(   -48.42) },
      { SIMDE_FLOAT32_C(   -49.14), SIMDE_FLOAT32_C(-8927626395648.00), SIMDE_FLOAT32_C(   -19.71), SIMDE_FLOAT32_C(   -38.90),
        SIMDE_FLOAT32_C(    39.93), SIMDE_FLOAT32_C(    49.45), SIMDE_FLOAT32_C(   -22.97), SIMDE_FLOAT32_C(   -23.96),
        SIMDE_FLOAT32_C(  -272.56), SIMDE_FLOAT32_C(  1084.66), SIMDE_FLOAT32_C(  -516.42), SIMDE_FLOAT32_C(  -809.41),
        SIMDE_FLOAT32_C(  2366.57), SIMDE_FLOAT32_C(    46.14), SIMDE_FLOAT32_C( -1155.25), SIMDE_FLOAT32_C(   310.90) } },
    { { SIMDE_FLOAT32_C(     9.38), SIMDE_FLOAT32_C(     9.41), SIMDE_FLOAT32_C(    -4.64), SIMDE_FLOAT32_C(   -45.17),
        SIMDE_FLOAT32_C(     2.48), SIMDE_FLOAT32_C(   -18.77), SIMDE_FLOAT32_C(    -0.95), SIMDE_FLOAT32_C(   -48.42),
        SIMDE_FLOAT32_C(    34.95), SIMDE_FLOAT32_C(     8.78), SIMDE_FLOAT32_C(    21.33), SIMDE_FLOAT32_C(   -49.81),
        SIMDE_FLOAT32_C(   -45.01), SIMDE_FLOAT32_C(   -21.44), SIMDE_FLOAT32_C(    42.63), SIMDE_FLOAT32_C(   -13.19) },
      { SIMDE_FLOAT32_C(   -15.96), SIMDE_FLOAT32_C(    16.09), SIMDE_FLOAT32_C(    25.68), SIMDE_FLOAT32_C(     8.09),
        SIMDE_FLOAT32_C(    48.52), SIMDE_FLOAT32_C(   -25.43), SIMDE_FLOAT32_C(   -32.53), SIMDE_FLOAT32_C(    27.66),
        SIMDE_FLOAT32_C(    14.18), SIMDE_FLOAT32_C(   -20.11), SIMDE_FLOAT32_C(    28.69), SIMDE_FLOAT32_C(   -23.73),
        SIMDE_FLOAT32_C(    -3.59), SIMDE_FLOAT32_C(   -26.75), SIMDE_FLOAT32_C(     2.26), SIMDE_FLOAT32_C(     4.12) },
      { SIMDE_FLOAT32_C(    21.03), SIMDE_FLOAT32_C(   -20.15), SIMDE_FLOAT32_C(    28.07), SIMDE_FLOAT32_C(   -19.04),
        SIMDE_FLOAT32_C(    23.89), SIMDE_FLOAT32_C(   -47.61), SIMDE_FLOAT32_C(    47.01), SIMDE_FLOAT32_C(    30.02),
        SIMDE_FLOAT32_C(   -46.57), SIMDE_FLOAT32_C(     5.58), SIMDE_FLOAT32_C(     1.34), SIMDE_FLOAT32_C(    46.11),
        SIMDE_FLOAT32_C(    34.13), SIMDE_FLOAT32_C(    25.83), SIMDE_FLOAT32_C(   -18.56), SIMDE_FLOAT32_C(   -31.84) },
      { SIMDE_FLOAT32_C(22391004543844352.00), SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(11195502271922176.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(11195502271922176.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(11195502271922176.00),
        SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(11195502271922176.00),
        SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(11195502271922176.00) } },
    { { SIMDE_FLOAT32_C(    -5.29), SIMDE_FLOAT32_C(    47.00), SIMDE_FLOAT32_C(    11.48), SIMDE_FLOAT32_C(    49.21),
        SIMDE_FLOAT32_C(   -27.37), SIMDE_FLOAT32_C(    45.74), SIMDE_FLOAT32_C(    25.63), SIMDE_FLOAT32_C(   -12.37),
        SIMDE_FLOAT32_C(    -8.34), SIMDE_FLOAT32_C(    43.11), SIMDE_FLOAT32_C(    36.98), SIMDE_FLOAT32_C(   -21.48),
        SIMDE_FLOAT32_C(   -36.56), SIMDE_FLOAT32_C(    18.84), SIMDE_FLOAT32_C(     3.28), SIMDE_FLOAT32_C(    22.82) },
      { SIMDE_FLOAT32_C(    -8.09), SIMDE_FLOAT32_C(   -42.89), SIMDE_FLOAT32_C(    26.25), SIMDE_FLOAT32_C(    -9.57),
        SIMDE_FLOAT32_C(   -18.31), SIMDE_FLOAT32_C(    43.72), SIMDE_FLOAT32_C(   -31.90), SIMDE_FLOAT32_C(    45.86),
        SIMDE_FLOAT32_C(   -26.39), SIMDE_FLOAT32_C(    46.79), SIMDE_FLOAT32_C(   -27.87), SIMDE_FLOAT32_C(    20.01),
        SIMDE_FLOAT32_C(   -29.96), SIMDE_FLOAT32_C(    24.39), SIMDE_FLOAT32_C(   -25.87), SIMDE_FLOAT32_C(    41.07) },
      { SIMDE_FLOAT32_C(   -45.76), SIMDE_FLOAT32_C(   -47.80), SIMDE_FLOAT32_C(   -27.97), SIMDE_FLOAT32_C(    28.13),
        SIMDE_FLOAT32_C(   -45.41), SIMDE_FLOAT32_C(   -30.97), SIMDE_FLOAT32_C(     8.15), SIMDE_FLOAT32_C(   -41.98),
        SIMDE_FLOAT32_C(    24.62), SIMDE_FLOAT32_C(   -40.51), SIMDE_FLOAT32_C(   -45.87), SIMDE_FLOAT32_C(     8.74),
        SIMDE_FLOAT32_C(    35.32), SIMDE_FLOAT32_C(   -14.43), SIMDE_FLOAT32_C(    26.91), SIMDE_FLOAT32_C(   -22.77) },
      { SIMDE_FLOAT32_C(    -5.28), SIMDE_FLOAT32_C(    47.00), SIMDE_FLOAT32_C(    11.48), SIMDE_FLOAT32_C(    49.21),
        SIMDE_FLOAT32_C(-13616351998377984000.00), SIMDE_FLOAT32_C(16486777515877911756800.00), SIMDE_FLOAT32_C(11316723428884480.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(   360.52), SIMDE_FLOAT32_C(  2084.43), SIMDE_FLOAT32_C(  -694.74), SIMDE_FLOAT32_C(  -290.42),
        SIMDE_FLOAT32_C(   789.26), SIMDE_FLOAT32_C( -1324.22), SIMDE_FLOAT32_C(  -255.70), SIMDE_FLOAT32_C( -1887.24) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 tmp;

    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);

    tmp = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512bh a;
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512bh b;
    simde_memcpy(&b, &tmp, sizeof(tmp));

    simde__m512 r = simde_mm512_dpbf16_ps(src, a, b);
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
    { { SIMDE_FLOAT32_C(     2.34), SIMDE_FLOAT32_C(   -12.07), SIMDE_FLOAT32_C(   -38.46), SIMDE_FLOAT32_C(    29.60),
        SIMDE_FLOAT32_C(     4.01), SIMDE_FLOAT32_C(   -14.67), SIMDE_FLOAT32_C(   -28.19), SIMDE_FLOAT32_C(    35.79),
        SIMDE_FLOAT32_C(    45.16), SIMDE_FLOAT32_C(    -0.56), SIMDE_FLOAT32_C(    43.97), SIMDE_FLOAT32_C(   -48.45),
        SIMDE_FLOAT32_C(   -21.48), SIMDE_FLOAT32_C(    25.53), SIMDE_FLOAT32_C(    24.81), SIMDE_FLOAT32_C(   -14.29) },
      UINT16_C(36601),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -42.56),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     7.28),
        SIMDE_FLOAT32_C(     2.49), SIMDE_FLOAT32_C(   -11.97), SIMDE_FLOAT32_C(    48.58), SIMDE_FLOAT32_C(   -24.48),
        SIMDE_FLOAT32_C(    42.89), SIMDE_FLOAT32_C(    -8.32), SIMDE_FLOAT32_C(   -48.86), SIMDE_FLOAT32_C(   -33.71),
        SIMDE_FLOAT32_C(     1.83), SIMDE_FLOAT32_C(    23.88), SIMDE_FLOAT32_C(   -42.87), SIMDE_FLOAT32_C(     2.69) },
      { SIMDE_FLOAT32_C(   -30.68),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -40.75),
        SIMDE_FLOAT32_C(   -13.14), SIMDE_FLOAT32_C(    40.82), SIMDE_FLOAT32_C(   -14.71), SIMDE_FLOAT32_C(   -12.30),
        SIMDE_FLOAT32_C(    12.35), SIMDE_FLOAT32_C(    32.43), SIMDE_FLOAT32_C(    26.29), SIMDE_FLOAT32_C(    40.29),
        SIMDE_FLOAT32_C(    27.36), SIMDE_FLOAT32_C(    32.73), SIMDE_FLOAT32_C(   -19.12), SIMDE_FLOAT32_C(    36.92) },
      { SIMDE_FLOAT32_C(     2.34), SIMDE_FLOAT32_C(   -12.07), SIMDE_FLOAT32_C(   -38.46), SIMDE_FLOAT32_C(    29.60),
        SIMDE_FLOAT32_C(11195502271922176.00), SIMDE_FLOAT32_C(   -14.67), SIMDE_FLOAT32_C(24108398694754935001990561792.00), SIMDE_FLOAT32_C(16308074682663850475520.00),
        SIMDE_FLOAT32_C(    45.16),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -343.89),
        SIMDE_FLOAT32_C(   -21.48), SIMDE_FLOAT32_C(    25.53), SIMDE_FLOAT32_C(    24.81), SIMDE_FLOAT32_C(   284.30) } },
    { { SIMDE_FLOAT32_C(   -20.35), SIMDE_FLOAT32_C(   -39.50), SIMDE_FLOAT32_C(   -47.09), SIMDE_FLOAT32_C(    24.12),
        SIMDE_FLOAT32_C(    11.21), SIMDE_FLOAT32_C(    49.99), SIMDE_FLOAT32_C(    48.27), SIMDE_FLOAT32_C(    30.91),
        SIMDE_FLOAT32_C(   -28.26), SIMDE_FLOAT32_C(   -27.73), SIMDE_FLOAT32_C(    24.96), SIMDE_FLOAT32_C(    -1.19),
        SIMDE_FLOAT32_C(    -5.51), SIMDE_FLOAT32_C(   -22.70), SIMDE_FLOAT32_C(    36.74), SIMDE_FLOAT32_C(     6.03) },
      UINT16_C( 1457),
      { SIMDE_FLOAT32_C(    40.18), SIMDE_FLOAT32_C(    19.94), SIMDE_FLOAT32_C(    -5.80), SIMDE_FLOAT32_C(    -7.33),
        SIMDE_FLOAT32_C(   -42.02), SIMDE_FLOAT32_C(    -7.23), SIMDE_FLOAT32_C(    18.19), SIMDE_FLOAT32_C(   -49.13),
        SIMDE_FLOAT32_C(    34.45), SIMDE_FLOAT32_C(    19.33), SIMDE_FLOAT32_C(   -32.84), SIMDE_FLOAT32_C(   -13.72),
        SIMDE_FLOAT32_C(    -6.79), SIMDE_FLOAT32_C(   -25.72), SIMDE_FLOAT32_C(    38.98), SIMDE_FLOAT32_C(    12.53) },
      { SIMDE_FLOAT32_C(    11.70), SIMDE_FLOAT32_C(     2.77), SIMDE_FLOAT32_C(    21.77), SIMDE_FLOAT32_C(    48.56),
        SIMDE_FLOAT32_C(    -6.41), SIMDE_FLOAT32_C(   -42.94), SIMDE_FLOAT32_C(   -13.74), SIMDE_FLOAT32_C(   -44.06),
        SIMDE_FLOAT32_C(    39.49), SIMDE_FLOAT32_C(   -37.45), SIMDE_FLOAT32_C(    46.23), SIMDE_FLOAT32_C(    16.85),
        SIMDE_FLOAT32_C(    45.29), SIMDE_FLOAT32_C(   -22.88), SIMDE_FLOAT32_C(     3.76), SIMDE_FLOAT32_C(    35.46) },
      { SIMDE_FLOAT32_C(   -20.35), SIMDE_FLOAT32_C(   -39.50), SIMDE_FLOAT32_C(   -47.09), SIMDE_FLOAT32_C(    24.12),
        SIMDE_FLOAT32_C(    11.21), SIMDE_FLOAT32_C(-13604811524332847104.00), SIMDE_FLOAT32_C(    48.27), SIMDE_FLOAT32_C(    30.91),
        SIMDE_FLOAT32_C(   439.24), SIMDE_FLOAT32_C(   -27.73), SIMDE_FLOAT32_C(  -100.78), SIMDE_FLOAT32_C(    -1.19),
        SIMDE_FLOAT32_C(    -5.51), SIMDE_FLOAT32_C(   -22.70), SIMDE_FLOAT32_C(    36.74), SIMDE_FLOAT32_C(     6.03) } },
    { { SIMDE_FLOAT32_C(    41.35), SIMDE_FLOAT32_C(   -21.28), SIMDE_FLOAT32_C(   -23.46), SIMDE_FLOAT32_C(    36.52),
        SIMDE_FLOAT32_C(    28.15), SIMDE_FLOAT32_C(   -29.49), SIMDE_FLOAT32_C(    38.07), SIMDE_FLOAT32_C(   -43.33),
        SIMDE_FLOAT32_C(    46.04), SIMDE_FLOAT32_C(    12.87), SIMDE_FLOAT32_C(    -7.62), SIMDE_FLOAT32_C(    48.68),
        SIMDE_FLOAT32_C(    -1.37), SIMDE_FLOAT32_C(    22.03), SIMDE_FLOAT32_C(   -40.82), SIMDE_FLOAT32_C(     1.55) },
      UINT16_C(62824),
      { SIMDE_FLOAT32_C(    47.06), SIMDE_FLOAT32_C(    47.96), SIMDE_FLOAT32_C(   -21.87), SIMDE_FLOAT32_C(   -44.96),
        SIMDE_FLOAT32_C(    -9.26), SIMDE_FLOAT32_C(    46.33), SIMDE_FLOAT32_C(   -44.10), SIMDE_FLOAT32_C(   -24.81),
        SIMDE_FLOAT32_C(    15.66), SIMDE_FLOAT32_C(   -26.94), SIMDE_FLOAT32_C(    11.47), SIMDE_FLOAT32_C(   -41.13),
        SIMDE_FLOAT32_C(    -2.66), SIMDE_FLOAT32_C(     0.44), SIMDE_FLOAT32_C(    21.39), SIMDE_FLOAT32_C(   -40.96) },
      { SIMDE_FLOAT32_C(   -46.79), SIMDE_FLOAT32_C(    -6.84), SIMDE_FLOAT32_C(   -42.40), SIMDE_FLOAT32_C(    -3.20),
        SIMDE_FLOAT32_C(     0.22), SIMDE_FLOAT32_C(    -6.13), SIMDE_FLOAT32_C(     2.74), SIMDE_FLOAT32_C(   -10.29),
        SIMDE_FLOAT32_C(     6.42), SIMDE_FLOAT32_C(    -1.03), SIMDE_FLOAT32_C(   -43.44), SIMDE_FLOAT32_C(     1.71),
        SIMDE_FLOAT32_C(    26.08), SIMDE_FLOAT32_C(    10.32), SIMDE_FLOAT32_C(   -12.83), SIMDE_FLOAT32_C(    23.14) },
      { SIMDE_FLOAT32_C(    41.35), SIMDE_FLOAT32_C(   -21.28), SIMDE_FLOAT32_C(   -23.46), SIMDE_FLOAT32_C(16308074682663850475520.00),
        SIMDE_FLOAT32_C(    28.15), SIMDE_FLOAT32_C(   -29.49),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -43.33),
        SIMDE_FLOAT32_C( -2151.21), SIMDE_FLOAT32_C(    12.87), SIMDE_FLOAT32_C(   911.32), SIMDE_FLOAT32_C(    48.68),
        SIMDE_FLOAT32_C(    -3.40), SIMDE_FLOAT32_C(  -261.25), SIMDE_FLOAT32_C(  -161.13), SIMDE_FLOAT32_C(   255.24) } },
    { { SIMDE_FLOAT32_C(     1.54), SIMDE_FLOAT32_C(    -5.58), SIMDE_FLOAT32_C(     1.30), SIMDE_FLOAT32_C(    23.28),
        SIMDE_FLOAT32_C(    16.69), SIMDE_FLOAT32_C(   -23.74), SIMDE_FLOAT32_C(   -27.92), SIMDE_FLOAT32_C(   -38.82),
        SIMDE_FLOAT32_C(     3.56), SIMDE_FLOAT32_C(   -41.18), SIMDE_FLOAT32_C(    17.20), SIMDE_FLOAT32_C(    10.46),
        SIMDE_FLOAT32_C(    -0.44), SIMDE_FLOAT32_C(     8.56), SIMDE_FLOAT32_C(    39.18), SIMDE_FLOAT32_C(    26.10) },
      UINT16_C(37331),
      { SIMDE_FLOAT32_C(     8.29), SIMDE_FLOAT32_C(    15.30), SIMDE_FLOAT32_C(    28.18), SIMDE_FLOAT32_C(    49.02),
        SIMDE_FLOAT32_C(    11.63), SIMDE_FLOAT32_C(    34.08), SIMDE_FLOAT32_C(   -25.79), SIMDE_FLOAT32_C(   -22.71),
        SIMDE_FLOAT32_C(   -42.86), SIMDE_FLOAT32_C(    35.68), SIMDE_FLOAT32_C(   -13.85), SIMDE_FLOAT32_C(     4.48),
        SIMDE_FLOAT32_C(   -13.88), SIMDE_FLOAT32_C(   -42.46), SIMDE_FLOAT32_C(    13.52), SIMDE_FLOAT32_C(   -10.67) },
      { SIMDE_FLOAT32_C(     0.71), SIMDE_FLOAT32_C(    21.13), SIMDE_FLOAT32_C(    36.13), SIMDE_FLOAT32_C(   -49.07),
        SIMDE_FLOAT32_C(   -35.01), SIMDE_FLOAT32_C(   -11.13), SIMDE_FLOAT32_C(    -9.36), SIMDE_FLOAT32_C(    21.41),
        SIMDE_FLOAT32_C(    37.84), SIMDE_FLOAT32_C(    -2.80), SIMDE_FLOAT32_C(   -26.88), SIMDE_FLOAT32_C(    13.92),
        SIMDE_FLOAT32_C(   -42.47), SIMDE_FLOAT32_C(    10.29), SIMDE_FLOAT32_C(   -12.94), SIMDE_FLOAT32_C(    15.82) },
      { SIMDE_FLOAT32_C(     1.54), SIMDE_FLOAT32_C(    -5.58), SIMDE_FLOAT32_C(     1.30), SIMDE_FLOAT32_C(    23.28),
        SIMDE_FLOAT32_C(    16.69), SIMDE_FLOAT32_C(   -23.74), SIMDE_FLOAT32_C(-9059159769088.00), SIMDE_FLOAT32_C(   -38.82),
        SIMDE_FLOAT32_C(     9.39), SIMDE_FLOAT32_C(   -41.18), SIMDE_FLOAT32_C(    17.20), SIMDE_FLOAT32_C(    10.46),
        SIMDE_FLOAT32_C(  -407.32), SIMDE_FLOAT32_C(     8.56), SIMDE_FLOAT32_C(    39.18), SIMDE_FLOAT32_C(  -457.51) } },
    { { SIMDE_FLOAT32_C(    46.61), SIMDE_FLOAT32_C(   -16.86), SIMDE_FLOAT32_C(    24.00), SIMDE_FLOAT32_C(    42.65),
        SIMDE_FLOAT32_C(    46.02), SIMDE_FLOAT32_C(   -33.62), SIMDE_FLOAT32_C(    41.33), SIMDE_FLOAT32_C(    -5.35),
        SIMDE_FLOAT32_C(    38.41), SIMDE_FLOAT32_C(   -49.49), SIMDE_FLOAT32_C(    46.20), SIMDE_FLOAT32_C(   -15.44),
        SIMDE_FLOAT32_C(    20.90), SIMDE_FLOAT32_C(    -2.26), SIMDE_FLOAT32_C(    28.98), SIMDE_FLOAT32_C(   -27.80) },
      UINT16_C(48865),
      { SIMDE_FLOAT32_C(   -24.41), SIMDE_FLOAT32_C(   -34.76), SIMDE_FLOAT32_C(    14.84), SIMDE_FLOAT32_C(    37.22),
        SIMDE_FLOAT32_C(    49.32), SIMDE_FLOAT32_C(    39.05), SIMDE_FLOAT32_C(   -35.49), SIMDE_FLOAT32_C(   -43.53),
        SIMDE_FLOAT32_C(    24.73), SIMDE_FLOAT32_C(     0.66), SIMDE_FLOAT32_C(    10.95), SIMDE_FLOAT32_C(   -39.15),
        SIMDE_FLOAT32_C(     8.20), SIMDE_FLOAT32_C(   -25.53), SIMDE_FLOAT32_C(     0.18), SIMDE_FLOAT32_C(   -41.09) },
      { SIMDE_FLOAT32_C(    45.60), SIMDE_FLOAT32_C(   -13.69), SIMDE_FLOAT32_C(   -40.16), SIMDE_FLOAT32_C(   -39.41),
        SIMDE_FLOAT32_C(    25.18), SIMDE_FLOAT32_C(     0.48), SIMDE_FLOAT32_C(    32.00), SIMDE_FLOAT32_C(    13.02),
        SIMDE_FLOAT32_C(    47.69), SIMDE_FLOAT32_C(   -44.88), SIMDE_FLOAT32_C(   -23.06), SIMDE_FLOAT32_C(   -44.78),
        SIMDE_FLOAT32_C(    15.40), SIMDE_FLOAT32_C(    14.00), SIMDE_FLOAT32_C(    21.03), SIMDE_FLOAT32_C(    40.99) },
      { SIMDE_FLOAT32_C(48381211300977459571741163520.00), SIMDE_FLOAT32_C(   -16.86), SIMDE_FLOAT32_C(    24.00), SIMDE_FLOAT32_C(    42.65),
        SIMDE_FLOAT32_C(    46.02), SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(24190605650488729785870581760.00),
        SIMDE_FLOAT32_C(    38.41), SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(24190605650488729785870581760.00),
        SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(24190605650488729785870581760.00), SIMDE_FLOAT32_C(    28.98), SIMDE_FLOAT32_C(24190605650488729785870581760.00) } },
    { { SIMDE_FLOAT32_C(    -1.55), SIMDE_FLOAT32_C(    -6.90), SIMDE_FLOAT32_C(     6.84), SIMDE_FLOAT32_C(   -47.99),
        SIMDE_FLOAT32_C(     1.92), SIMDE_FLOAT32_C(   -25.96), SIMDE_FLOAT32_C(    12.48), SIMDE_FLOAT32_C(   -48.51),
        SIMDE_FLOAT32_C(    32.60), SIMDE_FLOAT32_C(     1.65), SIMDE_FLOAT32_C(    27.58), SIMDE_FLOAT32_C(   -22.32),
        SIMDE_FLOAT32_C(   -31.02), SIMDE_FLOAT32_C(    24.19), SIMDE_FLOAT32_C(    10.83), SIMDE_FLOAT32_C(    42.98) },
      UINT16_C(61208),
      { SIMDE_FLOAT32_C(    29.24), SIMDE_FLOAT32_C(   -14.13), SIMDE_FLOAT32_C(    28.21), SIMDE_FLOAT32_C(    28.57),
        SIMDE_FLOAT32_C(   -25.08), SIMDE_FLOAT32_C(    42.72), SIMDE_FLOAT32_C(    35.03), SIMDE_FLOAT32_C(    49.65),
        SIMDE_FLOAT32_C(    -6.62), SIMDE_FLOAT32_C(    -4.02), SIMDE_FLOAT32_C(   -39.50), SIMDE_FLOAT32_C(   -48.42),
        SIMDE_FLOAT32_C(    20.46), SIMDE_FLOAT32_C(    10.68), SIMDE_FLOAT32_C(   -39.51), SIMDE_FLOAT32_C(    16.05) },
      { SIMDE_FLOAT32_C(    46.99), SIMDE_FLOAT32_C(   -29.67), SIMDE_FLOAT32_C(    26.64), SIMDE_FLOAT32_C(    22.17),
        SIMDE_FLOAT32_C(    20.82), SIMDE_FLOAT32_C(     8.65), SIMDE_FLOAT32_C(   -14.81), SIMDE_FLOAT32_C(    18.50),
        SIMDE_FLOAT32_C(    13.76), SIMDE_FLOAT32_C(    12.12), SIMDE_FLOAT32_C(    23.72), SIMDE_FLOAT32_C(   -20.83),
        SIMDE_FLOAT32_C(   -23.88), SIMDE_FLOAT32_C(    -5.24), SIMDE_FLOAT32_C(   -29.84), SIMDE_FLOAT32_C(   -44.63) },
      { SIMDE_FLOAT32_C(    -1.55), SIMDE_FLOAT32_C(    -6.90), SIMDE_FLOAT32_C(     6.84),      SIMDE_MATH_INFINITYF,
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -25.96), SIMDE_FLOAT32_C(    12.48), SIMDE_FLOAT32_C(   -48.51),
             SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(   -31.02),      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   -40.64), SIMDE_FLOAT32_C(     8.17), SIMDE_FLOAT32_C(   -48.51), SIMDE_FLOAT32_C(    47.77),
        SIMDE_FLOAT32_C(     8.68), SIMDE_FLOAT32_C(    47.69), SIMDE_FLOAT32_C(   -17.67), SIMDE_FLOAT32_C(   -20.43),
        SIMDE_FLOAT32_C(    -4.57), SIMDE_FLOAT32_C(   -38.69), SIMDE_FLOAT32_C(     1.77), SIMDE_FLOAT32_C(    16.45),
        SIMDE_FLOAT32_C(     6.97), SIMDE_FLOAT32_C(   -49.77), SIMDE_FLOAT32_C(   -40.45), SIMDE_FLOAT32_C(   -36.19) },
      UINT16_C( 7969),
      { SIMDE_FLOAT32_C(    30.63), SIMDE_FLOAT32_C(    48.37), SIMDE_FLOAT32_C(    33.94), SIMDE_FLOAT32_C(   -44.44),
        SIMDE_FLOAT32_C(    41.09), SIMDE_FLOAT32_C(    18.97), SIMDE_FLOAT32_C(   -44.79), SIMDE_FLOAT32_C(   -15.53),
        SIMDE_FLOAT32_C(   -35.05), SIMDE_FLOAT32_C(   -34.29), SIMDE_FLOAT32_C(   -13.95), SIMDE_FLOAT32_C(    35.41),
        SIMDE_FLOAT32_C(    26.39), SIMDE_FLOAT32_C(    -3.46), SIMDE_FLOAT32_C(     1.46), SIMDE_FLOAT32_C(    23.38) },
      { SIMDE_FLOAT32_C(    16.88), SIMDE_FLOAT32_C(   -21.89), SIMDE_FLOAT32_C(    -4.45), SIMDE_FLOAT32_C(   -12.31),
        SIMDE_FLOAT32_C(    36.75), SIMDE_FLOAT32_C(    30.74), SIMDE_FLOAT32_C(   -43.80), SIMDE_FLOAT32_C(     0.52),
        SIMDE_FLOAT32_C(    -7.14), SIMDE_FLOAT32_C(    29.92), SIMDE_FLOAT32_C(    29.69), SIMDE_FLOAT32_C(    18.99),
        SIMDE_FLOAT32_C(   -25.32), SIMDE_FLOAT32_C(    49.85), SIMDE_FLOAT32_C(    24.35), SIMDE_FLOAT32_C(   -44.69) },
      { SIMDE_FLOAT32_C(   -40.64), SIMDE_FLOAT32_C(     8.17), SIMDE_FLOAT32_C(   -48.51), SIMDE_FLOAT32_C(    47.77),
        SIMDE_FLOAT32_C(     8.68), SIMDE_FLOAT32_C(22992560163250632273736761344.00), SIMDE_FLOAT32_C(   -17.67), SIMDE_FLOAT32_C(   -20.43),
        SIMDE_FLOAT32_C(   512.23), SIMDE_FLOAT32_C( -1094.16), SIMDE_FLOAT32_C(  -148.00), SIMDE_FLOAT32_C(   558.51),
        SIMDE_FLOAT32_C(  1513.72), SIMDE_FLOAT32_C(   -49.77), SIMDE_FLOAT32_C(   -40.45), SIMDE_FLOAT32_C(   -36.19) } },
    { { SIMDE_FLOAT32_C(   -12.15), SIMDE_FLOAT32_C(    14.72), SIMDE_FLOAT32_C(    12.96), SIMDE_FLOAT32_C(   -29.54),
        SIMDE_FLOAT32_C(   -33.63), SIMDE_FLOAT32_C(    -9.46), SIMDE_FLOAT32_C(    -1.86), SIMDE_FLOAT32_C(   -14.65),
        SIMDE_FLOAT32_C(   -35.27), SIMDE_FLOAT32_C(   -41.03), SIMDE_FLOAT32_C(   -21.67), SIMDE_FLOAT32_C(    31.57),
        SIMDE_FLOAT32_C(    15.81), SIMDE_FLOAT32_C(   -12.32), SIMDE_FLOAT32_C(   -10.26), SIMDE_FLOAT32_C(    17.30) },
      UINT16_C(64035),
      { SIMDE_FLOAT32_C(    48.22), SIMDE_FLOAT32_C(     8.29), SIMDE_FLOAT32_C(   -39.13), SIMDE_FLOAT32_C(    39.32),
        SIMDE_FLOAT32_C(   -22.74), SIMDE_FLOAT32_C(   -33.92), SIMDE_FLOAT32_C(   -26.21), SIMDE_FLOAT32_C(    -7.79),
        SIMDE_FLOAT32_C(   -18.21), SIMDE_FLOAT32_C(     9.84), SIMDE_FLOAT32_C(   -22.38), SIMDE_FLOAT32_C(   -41.82),
        SIMDE_FLOAT32_C(   -43.62), SIMDE_FLOAT32_C(    29.08), SIMDE_FLOAT32_C(    31.56), SIMDE_FLOAT32_C(    23.26) },
      { SIMDE_FLOAT32_C(   -42.81), SIMDE_FLOAT32_C(   -22.89), SIMDE_FLOAT32_C(   -39.05), SIMDE_FLOAT32_C(    43.94),
        SIMDE_FLOAT32_C(   -42.15), SIMDE_FLOAT32_C(   -32.85), SIMDE_FLOAT32_C(    -5.54), SIMDE_FLOAT32_C(     0.71),
        SIMDE_FLOAT32_C(    47.07), SIMDE_FLOAT32_C(   -25.85), SIMDE_FLOAT32_C(   -30.30), SIMDE_FLOAT32_C(   -28.25),
        SIMDE_FLOAT32_C(   -26.00), SIMDE_FLOAT32_C(    44.05), SIMDE_FLOAT32_C(   -22.94), SIMDE_FLOAT32_C(   -27.78) },
      { SIMDE_FLOAT32_C(-27134187754907238400.00), SIMDE_FLOAT32_C(-13567093877453619200.00), SIMDE_FLOAT32_C(    12.96), SIMDE_FLOAT32_C(   -29.54),
        SIMDE_FLOAT32_C(   -33.63), SIMDE_FLOAT32_C(-13567102673546641408.00), SIMDE_FLOAT32_C(    -1.86), SIMDE_FLOAT32_C(   -14.65),
        SIMDE_FLOAT32_C(   -35.27), SIMDE_FLOAT32_C(-13567093877453619200.00), SIMDE_FLOAT32_C(   -21.67), SIMDE_FLOAT32_C(-13567093877453619200.00),
        SIMDE_FLOAT32_C(-13567093877453619200.00), SIMDE_FLOAT32_C(-13567093877453619200.00), SIMDE_FLOAT32_C(-13567093877453619200.00), SIMDE_FLOAT32_C(-13567093877453619200.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 tmp;

    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);

    tmp = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512bh a;
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512bh b;
    simde_memcpy(&b, &tmp, sizeof(tmp));

    simde__m512 r = simde_mm512_mask_dpbf16_ps(src, test_vec[i].k, a, b);
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
    { UINT16_C(55967),
      { SIMDE_FLOAT32_C(    -6.44), SIMDE_FLOAT32_C(   -26.61), SIMDE_FLOAT32_C(   -34.79), SIMDE_FLOAT32_C(    37.18),
        SIMDE_FLOAT32_C(    25.00), SIMDE_FLOAT32_C(    17.20), SIMDE_FLOAT32_C(   -28.44), SIMDE_FLOAT32_C(    26.72),
        SIMDE_FLOAT32_C(   -40.03), SIMDE_FLOAT32_C(    11.32), SIMDE_FLOAT32_C(    23.09), SIMDE_FLOAT32_C(    49.89),
        SIMDE_FLOAT32_C(   -28.05), SIMDE_FLOAT32_C(   -35.60), SIMDE_FLOAT32_C(    36.55), SIMDE_FLOAT32_C(    -5.49) },
      { SIMDE_FLOAT32_C(    17.89), SIMDE_FLOAT32_C(   -36.17), SIMDE_FLOAT32_C(    23.81), SIMDE_FLOAT32_C(    -3.03),
        SIMDE_FLOAT32_C(    43.59), SIMDE_FLOAT32_C(     0.69), SIMDE_FLOAT32_C(    33.02), SIMDE_FLOAT32_C(    23.58),
        SIMDE_FLOAT32_C(   -12.89), SIMDE_FLOAT32_C(   -17.13), SIMDE_FLOAT32_C(     5.81), SIMDE_FLOAT32_C(    35.00),
        SIMDE_FLOAT32_C(   -29.41), SIMDE_FLOAT32_C(   -47.25), SIMDE_FLOAT32_C(    45.84), SIMDE_FLOAT32_C(   -21.24) },
      { SIMDE_FLOAT32_C(    16.06), SIMDE_FLOAT32_C(    -2.77), SIMDE_FLOAT32_C(    35.07), SIMDE_FLOAT32_C(    14.72),
        SIMDE_FLOAT32_C(   -36.65), SIMDE_FLOAT32_C(     0.35), SIMDE_FLOAT32_C(    41.71), SIMDE_FLOAT32_C(    11.04),
        SIMDE_FLOAT32_C(    31.44), SIMDE_FLOAT32_C(     6.38), SIMDE_FLOAT32_C(    -1.53), SIMDE_FLOAT32_C(    29.84),
        SIMDE_FLOAT32_C(     6.49), SIMDE_FLOAT32_C(   -15.68), SIMDE_FLOAT32_C(    -6.77), SIMDE_FLOAT32_C(   -25.62) },
      { SIMDE_FLOAT32_C(22759890694963200.00), SIMDE_FLOAT32_C(11379945347481600.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(11379945347481600.00),
        SIMDE_FLOAT32_C(11379945347481600.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(11379945347481600.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(11379945347481600.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(11379945347481600.00),
        SIMDE_FLOAT32_C(11379945347481600.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(11379945347481600.00), SIMDE_FLOAT32_C(11379945347481600.00) } },
    { UINT16_C(31550),
      { SIMDE_FLOAT32_C(    12.11), SIMDE_FLOAT32_C(   -44.26), SIMDE_FLOAT32_C(    10.04), SIMDE_FLOAT32_C(    -9.22),
        SIMDE_FLOAT32_C(    -8.89), SIMDE_FLOAT32_C(    16.03), SIMDE_FLOAT32_C(    -8.82), SIMDE_FLOAT32_C(    18.28),
        SIMDE_FLOAT32_C(   -42.81), SIMDE_FLOAT32_C(   -41.65), SIMDE_FLOAT32_C(    26.31), SIMDE_FLOAT32_C(   -47.45),
        SIMDE_FLOAT32_C(    -4.72), SIMDE_FLOAT32_C(   -30.14), SIMDE_FLOAT32_C(   -24.06), SIMDE_FLOAT32_C(    10.49) },
      { SIMDE_FLOAT32_C(    -1.85), SIMDE_FLOAT32_C(   -32.96), SIMDE_FLOAT32_C(    21.35), SIMDE_FLOAT32_C(    -8.26),
        SIMDE_FLOAT32_C(    17.73), SIMDE_FLOAT32_C(     4.36), SIMDE_FLOAT32_C(   -34.68), SIMDE_FLOAT32_C(   -45.17),
        SIMDE_FLOAT32_C(    37.24), SIMDE_FLOAT32_C(    21.13), SIMDE_FLOAT32_C(    39.83), SIMDE_FLOAT32_C(   -42.17),
        SIMDE_FLOAT32_C(    23.88), SIMDE_FLOAT32_C(    35.67), SIMDE_FLOAT32_C(   -13.42), SIMDE_FLOAT32_C(   -10.06) },
      { SIMDE_FLOAT32_C(   -17.10), SIMDE_FLOAT32_C(   -28.34), SIMDE_FLOAT32_C(   -45.34), SIMDE_FLOAT32_C(    -3.74),
        SIMDE_FLOAT32_C(    22.01), SIMDE_FLOAT32_C(    46.37), SIMDE_FLOAT32_C(   -42.70), SIMDE_FLOAT32_C(     3.45),
        SIMDE_FLOAT32_C(     2.75), SIMDE_FLOAT32_C(     5.77), SIMDE_FLOAT32_C(   -16.71), SIMDE_FLOAT32_C(   -40.76),
        SIMDE_FLOAT32_C(    40.09), SIMDE_FLOAT32_C(    26.52), SIMDE_FLOAT32_C(   -16.38), SIMDE_FLOAT32_C(   -11.76) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(11551751555514368.00), SIMDE_FLOAT32_C(-20450798349877357303562240.00), SIMDE_FLOAT32_C(11551744039321600.00),
        SIMDE_FLOAT32_C(11551744039321600.00), SIMDE_FLOAT32_C(11551744039321600.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(11551744039321600.00), SIMDE_FLOAT32_C(11551744039321600.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(11551744039321600.00),
        SIMDE_FLOAT32_C(11551744039321600.00), SIMDE_FLOAT32_C(11551744039321600.00), SIMDE_FLOAT32_C(11551744039321600.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(59118),
      { SIMDE_FLOAT32_C(     7.15), SIMDE_FLOAT32_C(   -49.55), SIMDE_FLOAT32_C(    29.13), SIMDE_FLOAT32_C(    14.34),
        SIMDE_FLOAT32_C(   -41.20), SIMDE_FLOAT32_C(     5.44), SIMDE_FLOAT32_C(    16.89), SIMDE_FLOAT32_C(     4.08),
        SIMDE_FLOAT32_C(    25.30), SIMDE_FLOAT32_C(    42.83), SIMDE_FLOAT32_C(   -35.44), SIMDE_FLOAT32_C(    32.35),
        SIMDE_FLOAT32_C(    43.77), SIMDE_FLOAT32_C(    -7.75), SIMDE_FLOAT32_C(   -39.05), SIMDE_FLOAT32_C(    21.42) },
      { SIMDE_FLOAT32_C(    31.87), SIMDE_FLOAT32_C(    42.15), SIMDE_FLOAT32_C(   -47.26), SIMDE_FLOAT32_C(    -8.80),
        SIMDE_FLOAT32_C(    37.46), SIMDE_FLOAT32_C(    18.85), SIMDE_FLOAT32_C(    37.76), SIMDE_FLOAT32_C(     3.90),
        SIMDE_FLOAT32_C(   -25.21), SIMDE_FLOAT32_C(    -7.84), SIMDE_FLOAT32_C(    44.22), SIMDE_FLOAT32_C(    16.40),
        SIMDE_FLOAT32_C(   -16.87), SIMDE_FLOAT32_C(    24.48), SIMDE_FLOAT32_C(    -9.08), SIMDE_FLOAT32_C(    -4.23) },
      { SIMDE_FLOAT32_C(     9.41), SIMDE_FLOAT32_C(    11.69), SIMDE_FLOAT32_C(   -19.59), SIMDE_FLOAT32_C(    -9.29),
        SIMDE_FLOAT32_C(    39.76), SIMDE_FLOAT32_C(    18.51), SIMDE_FLOAT32_C(    24.75), SIMDE_FLOAT32_C(    23.60),
        SIMDE_FLOAT32_C(   -10.11), SIMDE_FLOAT32_C(   -31.97), SIMDE_FLOAT32_C(    -2.47), SIMDE_FLOAT32_C(    37.79),
        SIMDE_FLOAT32_C(    44.93), SIMDE_FLOAT32_C(     9.70), SIMDE_FLOAT32_C(   -20.76), SIMDE_FLOAT32_C(    26.80) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  5312.95), SIMDE_FLOAT32_C(  5391.63), SIMDE_FLOAT32_C(  5376.84),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  5367.94), SIMDE_FLOAT32_C(  5379.39), SIMDE_FLOAT32_C(  5366.58),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  5896.21), SIMDE_FLOAT32_C(  6248.44), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  5701.62), SIMDE_FLOAT32_C(  6257.76), SIMDE_FLOAT32_C(  5475.35) } },
    { UINT16_C(24133),
      { SIMDE_FLOAT32_C(   -27.84), SIMDE_FLOAT32_C(   -32.53), SIMDE_FLOAT32_C(   -37.25), SIMDE_FLOAT32_C(    37.30),
        SIMDE_FLOAT32_C(    -8.42), SIMDE_FLOAT32_C(    19.13), SIMDE_FLOAT32_C(     1.30), SIMDE_FLOAT32_C(    22.65),
        SIMDE_FLOAT32_C(    37.62), SIMDE_FLOAT32_C(   -28.97), SIMDE_FLOAT32_C(    13.77), SIMDE_FLOAT32_C(    -3.11),
        SIMDE_FLOAT32_C(   -18.12), SIMDE_FLOAT32_C(   -29.09), SIMDE_FLOAT32_C(    -2.65), SIMDE_FLOAT32_C(   -38.99) },
      { SIMDE_FLOAT32_C(     1.85), SIMDE_FLOAT32_C(   -18.02), SIMDE_FLOAT32_C(   -32.00), SIMDE_FLOAT32_C(   -10.69),
        SIMDE_FLOAT32_C(   -49.17), SIMDE_FLOAT32_C(   -44.24), SIMDE_FLOAT32_C(    43.21), SIMDE_FLOAT32_C(   -24.38),
        SIMDE_FLOAT32_C(    -2.08), SIMDE_FLOAT32_C(    37.43), SIMDE_FLOAT32_C(    42.02), SIMDE_FLOAT32_C(    31.05),
        SIMDE_FLOAT32_C(    11.91), SIMDE_FLOAT32_C(   -17.07), SIMDE_FLOAT32_C(   -23.18), SIMDE_FLOAT32_C(   -28.68) },
      { SIMDE_FLOAT32_C(    44.62), SIMDE_FLOAT32_C(     7.23), SIMDE_FLOAT32_C(    12.02), SIMDE_FLOAT32_C(    34.38),
        SIMDE_FLOAT32_C(   -24.26), SIMDE_FLOAT32_C(   -13.23), SIMDE_FLOAT32_C(     7.97), SIMDE_FLOAT32_C(    15.63),
        SIMDE_FLOAT32_C(     4.81), SIMDE_FLOAT32_C(   -44.50), SIMDE_FLOAT32_C(     3.42), SIMDE_FLOAT32_C(    -0.26),
        SIMDE_FLOAT32_C(    15.21), SIMDE_FLOAT32_C(    32.66), SIMDE_FLOAT32_C(   -23.46), SIMDE_FLOAT32_C(   -32.94) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C( 2118),
      { SIMDE_FLOAT32_C(    16.45), SIMDE_FLOAT32_C(     2.15), SIMDE_FLOAT32_C(   -39.77), SIMDE_FLOAT32_C(    -8.24),
        SIMDE_FLOAT32_C(    -5.02), SIMDE_FLOAT32_C(   -25.21), SIMDE_FLOAT32_C(   -25.90), SIMDE_FLOAT32_C(   -11.25),
        SIMDE_FLOAT32_C(    17.04), SIMDE_FLOAT32_C(   -14.95), SIMDE_FLOAT32_C(   -39.83), SIMDE_FLOAT32_C(    -3.05),
        SIMDE_FLOAT32_C(   -14.07), SIMDE_FLOAT32_C(   -17.67), SIMDE_FLOAT32_C(    14.42), SIMDE_FLOAT32_C(    -1.32) },
      { SIMDE_FLOAT32_C(   -35.36), SIMDE_FLOAT32_C(    -5.46), SIMDE_FLOAT32_C(     6.37), SIMDE_FLOAT32_C(   -34.53),
        SIMDE_FLOAT32_C(     0.29), SIMDE_FLOAT32_C(    -0.41), SIMDE_FLOAT32_C(    -8.92), SIMDE_FLOAT32_C(    48.21),
        SIMDE_FLOAT32_C(   -12.99), SIMDE_FLOAT32_C(   -16.90), SIMDE_FLOAT32_C(    29.26), SIMDE_FLOAT32_C(    48.92),
        SIMDE_FLOAT32_C(    16.04), SIMDE_FLOAT32_C(   -43.92), SIMDE_FLOAT32_C(   -29.76), SIMDE_FLOAT32_C(    10.66) },
      { SIMDE_FLOAT32_C(    13.31), SIMDE_FLOAT32_C(    32.26), SIMDE_FLOAT32_C(    -4.97), SIMDE_FLOAT32_C(    39.05),
        SIMDE_FLOAT32_C(   -30.97), SIMDE_FLOAT32_C(   -46.99), SIMDE_FLOAT32_C(     4.68), SIMDE_FLOAT32_C(    23.83),
        SIMDE_FLOAT32_C(   -41.49), SIMDE_FLOAT32_C(   -41.91), SIMDE_FLOAT32_C(   -26.43), SIMDE_FLOAT32_C(    23.72),
        SIMDE_FLOAT32_C(    40.75), SIMDE_FLOAT32_C(     0.11), SIMDE_FLOAT32_C(    40.78), SIMDE_FLOAT32_C(   -44.61) },
      { SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(33879),
      { SIMDE_FLOAT32_C(   -32.18), SIMDE_FLOAT32_C(    20.92), SIMDE_FLOAT32_C(    28.65), SIMDE_FLOAT32_C(   -44.56),
        SIMDE_FLOAT32_C(    41.96), SIMDE_FLOAT32_C(    -7.58), SIMDE_FLOAT32_C(     2.34), SIMDE_FLOAT32_C(   -26.16),
        SIMDE_FLOAT32_C(    13.33), SIMDE_FLOAT32_C(    49.69), SIMDE_FLOAT32_C(   -15.14), SIMDE_FLOAT32_C(    -1.41),
        SIMDE_FLOAT32_C(     5.83), SIMDE_FLOAT32_C(   -48.69), SIMDE_FLOAT32_C(   -49.26), SIMDE_FLOAT32_C(    16.06) },
      { SIMDE_FLOAT32_C(    44.65), SIMDE_FLOAT32_C(    -2.85), SIMDE_FLOAT32_C(   -29.14), SIMDE_FLOAT32_C(    -5.06),
        SIMDE_FLOAT32_C(    46.74), SIMDE_FLOAT32_C(    11.94), SIMDE_FLOAT32_C(    -6.85), SIMDE_FLOAT32_C(   -16.25),
        SIMDE_FLOAT32_C(    45.04), SIMDE_FLOAT32_C(   -27.59), SIMDE_FLOAT32_C(   -17.33), SIMDE_FLOAT32_C(    11.07),
        SIMDE_FLOAT32_C(   -21.51), SIMDE_FLOAT32_C(     2.91), SIMDE_FLOAT32_C(   -28.27), SIMDE_FLOAT32_C(    41.80) },
      { SIMDE_FLOAT32_C(   -14.83), SIMDE_FLOAT32_C(    16.76), SIMDE_FLOAT32_C(    30.85), SIMDE_FLOAT32_C(     4.20),
        SIMDE_FLOAT32_C(    19.77), SIMDE_FLOAT32_C(   -14.47), SIMDE_FLOAT32_C(   -21.97), SIMDE_FLOAT32_C(    28.28),
        SIMDE_FLOAT32_C(    -6.38), SIMDE_FLOAT32_C(     1.61), SIMDE_FLOAT32_C(     1.99), SIMDE_FLOAT32_C(   -15.62),
        SIMDE_FLOAT32_C(   -48.28), SIMDE_FLOAT32_C(    -7.23), SIMDE_FLOAT32_C(   -10.23), SIMDE_FLOAT32_C(    46.37) },
      { SIMDE_FLOAT32_C(   -32.18), SIMDE_FLOAT32_C(    20.92), SIMDE_FLOAT32_C(    28.65), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(-13502354632810168320.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     2.34), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -910.73), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -443.00) } },
    { UINT16_C(27341),
      { SIMDE_FLOAT32_C(   -19.53), SIMDE_FLOAT32_C(   -45.16), SIMDE_FLOAT32_C(    18.62), SIMDE_FLOAT32_C(   -31.45),
        SIMDE_FLOAT32_C(   -38.00), SIMDE_FLOAT32_C(   -33.25), SIMDE_FLOAT32_C(    16.80), SIMDE_FLOAT32_C(   -14.60),
        SIMDE_FLOAT32_C(   -49.21), SIMDE_FLOAT32_C(    17.91), SIMDE_FLOAT32_C(    -3.23), SIMDE_FLOAT32_C(    15.19),
        SIMDE_FLOAT32_C(   -10.55), SIMDE_FLOAT32_C(   -45.58), SIMDE_FLOAT32_C(   -17.22), SIMDE_FLOAT32_C(     3.58) },
      { SIMDE_FLOAT32_C(   -40.20), SIMDE_FLOAT32_C(    17.87), SIMDE_FLOAT32_C(    -3.35), SIMDE_FLOAT32_C(    15.37),
        SIMDE_FLOAT32_C(   -41.67), SIMDE_FLOAT32_C(    41.52), SIMDE_FLOAT32_C(   -49.67), SIMDE_FLOAT32_C(    47.84),
        SIMDE_FLOAT32_C(    39.94), SIMDE_FLOAT32_C(    23.52), SIMDE_FLOAT32_C(    47.67), SIMDE_FLOAT32_C(    32.33),
        SIMDE_FLOAT32_C(    24.20), SIMDE_FLOAT32_C(    47.02), SIMDE_FLOAT32_C(    14.36), SIMDE_FLOAT32_C(    41.71) },
      { SIMDE_FLOAT32_C(    47.34), SIMDE_FLOAT32_C(    -6.76), SIMDE_FLOAT32_C(   -45.48), SIMDE_FLOAT32_C(    14.65),
        SIMDE_FLOAT32_C(    30.98), SIMDE_FLOAT32_C(   -44.60), SIMDE_FLOAT32_C(    24.12), SIMDE_FLOAT32_C(   -35.15),
        SIMDE_FLOAT32_C(   -13.06), SIMDE_FLOAT32_C(     1.72), SIMDE_FLOAT32_C(   -18.92), SIMDE_FLOAT32_C(    16.19),
        SIMDE_FLOAT32_C(     4.49), SIMDE_FLOAT32_C(    -0.42), SIMDE_FLOAT32_C(    24.62), SIMDE_FLOAT32_C(    14.29) },
      { SIMDE_FLOAT32_C(-40901596699754714607124480.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-20434161692565880501698560.00), SIMDE_FLOAT32_C(-20450798349877357303562240.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-20450798349877357303562240.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-20450798349877357303562240.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-20450798349877357303562240.00), SIMDE_FLOAT32_C(-20450798349877357303562240.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(33090),
      { SIMDE_FLOAT32_C(    17.06), SIMDE_FLOAT32_C(    27.25), SIMDE_FLOAT32_C(   -22.69), SIMDE_FLOAT32_C(   -25.30),
        SIMDE_FLOAT32_C(    13.00), SIMDE_FLOAT32_C(    -1.13), SIMDE_FLOAT32_C(   -12.84), SIMDE_FLOAT32_C(    25.79),
        SIMDE_FLOAT32_C(    47.29), SIMDE_FLOAT32_C(     0.36), SIMDE_FLOAT32_C(    -3.68), SIMDE_FLOAT32_C(   -41.39),
        SIMDE_FLOAT32_C(   -30.58), SIMDE_FLOAT32_C(    26.79), SIMDE_FLOAT32_C(   -36.55), SIMDE_FLOAT32_C(    38.04) },
      { SIMDE_FLOAT32_C(   -32.55), SIMDE_FLOAT32_C(   -28.73), SIMDE_FLOAT32_C(   -20.34), SIMDE_FLOAT32_C(   -24.22),
        SIMDE_FLOAT32_C(   -37.22), SIMDE_FLOAT32_C(   -20.00), SIMDE_FLOAT32_C(   -26.38), SIMDE_FLOAT32_C(   -47.28),
        SIMDE_FLOAT32_C(   -46.48), SIMDE_FLOAT32_C(   -28.71), SIMDE_FLOAT32_C(    35.04), SIMDE_FLOAT32_C(    27.73),
        SIMDE_FLOAT32_C(   -31.70), SIMDE_FLOAT32_C(    -0.60), SIMDE_FLOAT32_C(    19.44), SIMDE_FLOAT32_C(   -34.35) },
      { SIMDE_FLOAT32_C(    42.64), SIMDE_FLOAT32_C(    23.96), SIMDE_FLOAT32_C(    30.29), SIMDE_FLOAT32_C(    23.62),
        SIMDE_FLOAT32_C(    29.36), SIMDE_FLOAT32_C(     4.41), SIMDE_FLOAT32_C(    38.47), SIMDE_FLOAT32_C(   -33.71),
        SIMDE_FLOAT32_C(   -43.87), SIMDE_FLOAT32_C(   -30.45), SIMDE_FLOAT32_C(    32.48), SIMDE_FLOAT32_C(    10.62),
        SIMDE_FLOAT32_C(    19.13), SIMDE_FLOAT32_C(     7.11), SIMDE_FLOAT32_C(   -25.09), SIMDE_FLOAT32_C(    36.59) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  5133.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -12.84), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C( -1333.96), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  1620.92) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 tmp;

    simde__m512 src = simde_mm512_loadu_ps(test_vec[i].src);

    tmp = simde_mm512_loadu_ps(test_vec[i].a);
    simde__m512bh a;
    simde_memcpy(&a, &tmp, sizeof(tmp));

    tmp = simde_mm512_loadu_ps(test_vec[i].b);
    simde__m512bh b;
    simde_memcpy(&b, &tmp, sizeof(tmp));

    simde__m512 r = simde_mm512_maskz_dpbf16_ps(test_vec[i].k, src, a, b);
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
