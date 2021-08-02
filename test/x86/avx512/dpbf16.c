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

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dpbf16_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
