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
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -574.44),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   524.22) },
      { SIMDE_FLOAT32_C(   500.85),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   876.76) },
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,      SIMDE_MATH_INFINITYF } },
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

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_scalef_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
