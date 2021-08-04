#define SIMDE_TEST_X86_AVX512_INSN fixupimm

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/fixupimm.h>

static int
test_simde_mm_fixupimm_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t c[4];
    const int imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   201.54),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   881.13) },
      { SIMDE_FLOAT32_C(   -46.40),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   174.98) },
      { -INT32_C(   408511845),  INT32_C(  1587971559), -INT32_C(   627447801),  INT32_C(  2001924042) },
       INT32_C(           9),
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00) } },
    { { SIMDE_FLOAT32_C(   664.12), SIMDE_FLOAT32_C(  -562.89), SIMDE_FLOAT32_C(   663.33), SIMDE_FLOAT32_C(   970.48) },
      { SIMDE_FLOAT32_C(   603.80), SIMDE_FLOAT32_C(  -265.96), SIMDE_FLOAT32_C(  -984.77), SIMDE_FLOAT32_C(   917.02) },
      { -INT32_C(   718677047),  INT32_C(   781642408),  INT32_C(    34931302), -INT32_C(  2081834084) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00) } },
    { { SIMDE_FLOAT32_C(   517.09), SIMDE_FLOAT32_C(  -513.21), SIMDE_FLOAT32_C(  -326.22), SIMDE_FLOAT32_C(  -832.74) },
      { SIMDE_FLOAT32_C(  -388.67), SIMDE_FLOAT32_C(   -81.18), SIMDE_FLOAT32_C(   227.41), SIMDE_FLOAT32_C(  -456.50) },
      {  INT32_C(  1126398840),  INT32_C(  1941599594),  INT32_C(  1252359041), -INT32_C(    14627242) },
       INT32_C(         184),
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF,  SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00) } },
    { { SIMDE_FLOAT32_C(  -446.07), SIMDE_FLOAT32_C(  -715.24), SIMDE_FLOAT32_C(  -742.45), SIMDE_FLOAT32_C(  -938.47) },
      { SIMDE_FLOAT32_C(   179.77), SIMDE_FLOAT32_C(   -73.95), SIMDE_FLOAT32_C(    38.40), SIMDE_FLOAT32_C(   117.23) },
      {  INT32_C(  1428177592),  INT32_C(  1071123198),  INT32_C(   310885018), -INT32_C(  1621775819) },
       INT32_C(          32),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    38.40), SIMDE_FLOAT32_C(    -1.00) } },
    { { SIMDE_FLOAT32_C(  -872.41), SIMDE_FLOAT32_C(   469.38), SIMDE_FLOAT32_C(    -1.64), SIMDE_FLOAT32_C(    81.20) },
      { SIMDE_FLOAT32_C(   969.80), SIMDE_FLOAT32_C(   475.02), SIMDE_FLOAT32_C(  -743.82), SIMDE_FLOAT32_C(   633.92) },
      { -INT32_C(   504580214),  INT32_C(  1038093445),  INT32_C(  2069564866),  INT32_C(  1322286160) },
       INT32_C(         134),
      { SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.50),     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   912.13), SIMDE_FLOAT32_C(   919.50), SIMDE_FLOAT32_C(   604.40), SIMDE_FLOAT32_C(   515.94) },
      { SIMDE_FLOAT32_C(  -346.46), SIMDE_FLOAT32_C(   619.63), SIMDE_FLOAT32_C(   432.96), SIMDE_FLOAT32_C(  -829.36) },
      { -INT32_C(  1758325662), -INT32_C(   550074177),  INT32_C(   578832535), -INT32_C(  2080150273) },
       INT32_C(         120),
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     1.57),            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(  -893.58), SIMDE_FLOAT32_C(  -893.27), SIMDE_FLOAT32_C(  -662.11), SIMDE_FLOAT32_C(  -282.25) },
      { SIMDE_FLOAT32_C(    25.55), SIMDE_FLOAT32_C(   565.30), SIMDE_FLOAT32_C(   261.25), SIMDE_FLOAT32_C(   579.48) },
      {  INT32_C(  1085677040),  INT32_C(   529434265), -INT32_C(  1858135250), -INT32_C(   282562256) },
       INT32_C(         249),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   565.30), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00) } },
    { { SIMDE_FLOAT32_C(   850.06), SIMDE_FLOAT32_C(   518.80), SIMDE_FLOAT32_C(   641.02), SIMDE_FLOAT32_C(    29.83) },
      { SIMDE_FLOAT32_C(  -555.15), SIMDE_FLOAT32_C(  -320.59), SIMDE_FLOAT32_C(  -852.94), SIMDE_FLOAT32_C(  -427.56) },
      { -INT32_C(  1481421145),  INT32_C(   858502843), -INT32_C(  1989218919), -INT32_C(  1547033590) },
       INT32_C(         170),
      { SIMDE_FLOAT32_C(    -0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -1.00),            SIMDE_MATH_NANF } },
  };

  simde__m128 a, b, r;
  simde__m128i c;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_fixupimm_ps(a, b, c, INT32_C(           9));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_fixupimm_ps(a, b, c, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_fixupimm_ps(a, b, c, INT32_C(         184));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_fixupimm_ps(a, b, c, INT32_C(          32));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_fixupimm_ps(a, b, c, INT32_C(         134));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_fixupimm_ps(a, b, c, INT32_C(         120));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_fixupimm_ps(a, b, c, INT32_C(         249));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_fixupimm_ps(a, b, c, INT32_C(         170));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128i c = simde_test_x86_random_i32x4();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_fixupimm_ps, r, simde_mm_setzero_ps(), imm8, a, b, c);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fixupimm_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
