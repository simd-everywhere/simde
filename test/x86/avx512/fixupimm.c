#define SIMDE_TEST_X86_AVX512_INSN fixupimm

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/fixupimm.h>
#include <simde/x86/avx512/setzero.h>

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
    { { SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      { SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00) },
      { -INT32_C(  1289243822), -INT32_C(  1566703114), -INT32_C(  1814574289), -INT32_C(   993823156) },
       INT32_C(           6),
      { SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    90.00),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      { SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00) },
      {  INT32_C(   442678001), -INT32_C(  1898682214), -INT32_C(  1314041761), -INT32_C(   110767101) },
       INT32_C(         213),
      { SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF } },
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
  r = simde_mm_fixupimm_ps(a, b, c, INT32_C(           6));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_fixupimm_ps(a, b, c, INT32_C(         213));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 2 ; i++) {
    simde__m128 a = simde_mm_set_ps(SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1.0), SIMDE_FLOAT32_C(1.0));
    simde__m128 b = simde_mm_set_ps(SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1.0), SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1.0));
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

static int
test_simde_mm_mask_fixupimm_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde__mmask8 k;
    const simde_float32 b[4];
    const int32_t c[4];
    const int imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    23.48),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   523.55) },
      UINT8_C( 56),
      { SIMDE_FLOAT32_C(   814.83),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -987.74) },
      { -INT32_C(  1062186756), -INT32_C(    13150401),  INT32_C(   518961091), -INT32_C(   970966419) },
       INT32_C(         106),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    23.48),            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   167.41), SIMDE_FLOAT32_C(  -298.70), SIMDE_FLOAT32_C(    73.34), SIMDE_FLOAT32_C(  -860.50) },
      UINT8_C(168),
      { SIMDE_FLOAT32_C(  -151.65), SIMDE_FLOAT32_C(  -558.71), SIMDE_FLOAT32_C(  -472.09), SIMDE_FLOAT32_C(  -613.35) },
      {  INT32_C(   597534342),  INT32_C(  1360845833),  INT32_C(    72177076),  INT32_C(  1564675589) },
       INT32_C(          69),
      { SIMDE_FLOAT32_C(   167.41), SIMDE_FLOAT32_C(  -298.70), SIMDE_FLOAT32_C(    73.34), SIMDE_FLOAT32_C(     1.57) } },
    { { SIMDE_FLOAT32_C(  -954.81), SIMDE_FLOAT32_C(  -400.16), SIMDE_FLOAT32_C(  -515.11), SIMDE_FLOAT32_C(   674.37) },
      UINT8_C( 48),
      { SIMDE_FLOAT32_C(  -640.90), SIMDE_FLOAT32_C(  -783.28), SIMDE_FLOAT32_C(   990.54), SIMDE_FLOAT32_C(   -77.93) },
      {  INT32_C(  1584032062), -INT32_C(  1735470033), -INT32_C(   333564346), -INT32_C(  1342881325) },
       INT32_C(          94),
      { SIMDE_FLOAT32_C(  -954.81), SIMDE_FLOAT32_C(  -400.16), SIMDE_FLOAT32_C(  -515.11), SIMDE_FLOAT32_C(   674.37) } },
    { { SIMDE_FLOAT32_C(  -839.98), SIMDE_FLOAT32_C(   384.67), SIMDE_FLOAT32_C(  -872.97), SIMDE_FLOAT32_C(   560.86) },
      UINT8_C(147),
      { SIMDE_FLOAT32_C(   200.25), SIMDE_FLOAT32_C(   749.68), SIMDE_FLOAT32_C(   -70.41), SIMDE_FLOAT32_C(  -172.70) },
      { -INT32_C(  1432242073),  INT32_C(   904783381),  INT32_C(  1265835490),  INT32_C(  1551618696) },
       INT32_C(          96),
      { SIMDE_FLOAT32_C(     1.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -872.97), SIMDE_FLOAT32_C(   560.86) } },
    { { SIMDE_FLOAT32_C(  -226.84), SIMDE_FLOAT32_C(   416.74), SIMDE_FLOAT32_C(  -649.15), SIMDE_FLOAT32_C(  -412.01) },
      UINT8_C( 49),
      { SIMDE_FLOAT32_C(   623.67), SIMDE_FLOAT32_C(   586.37), SIMDE_FLOAT32_C(  -399.76), SIMDE_FLOAT32_C(  -208.92) },
      { -INT32_C(  2089653874),  INT32_C(  2093600792),  INT32_C(  1021533571), -INT32_C(   447639810) },
       INT32_C(         123),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   416.74), SIMDE_FLOAT32_C(  -649.15), SIMDE_FLOAT32_C(  -412.01) } },
    { { SIMDE_FLOAT32_C(  -712.33), SIMDE_FLOAT32_C(   673.58), SIMDE_FLOAT32_C(   -69.41), SIMDE_FLOAT32_C(   136.02) },
      UINT8_C(250),
      { SIMDE_FLOAT32_C(  -885.13), SIMDE_FLOAT32_C(   458.50), SIMDE_FLOAT32_C(   522.67), SIMDE_FLOAT32_C(  -839.94) },
      { -INT32_C(  1899225069),  INT32_C(   530656381),  INT32_C(   732877506),  INT32_C(   356790596) },
       INT32_C(         251),
      { SIMDE_FLOAT32_C(  -712.33), SIMDE_FLOAT32_C(   458.50), SIMDE_FLOAT32_C(   -69.41),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(  -941.67), SIMDE_FLOAT32_C(  -992.44), SIMDE_FLOAT32_C(   834.43), SIMDE_FLOAT32_C(  -582.57) },
      UINT8_C(163),
      { SIMDE_FLOAT32_C(  -775.72), SIMDE_FLOAT32_C(   824.97), SIMDE_FLOAT32_C(   339.51), SIMDE_FLOAT32_C(  -615.70) },
      {  INT32_C(   640767700),  INT32_C(    61713467),  INT32_C(  1695983429), -INT32_C(  1595759500) },
       INT32_C(          69),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -992.44), SIMDE_FLOAT32_C(   834.43), SIMDE_FLOAT32_C(  -582.57) } },
    { { SIMDE_FLOAT32_C(   209.64), SIMDE_FLOAT32_C(   466.53), SIMDE_FLOAT32_C(   945.16), SIMDE_FLOAT32_C(  -590.11) },
      UINT8_C(176),
      { SIMDE_FLOAT32_C(   216.22), SIMDE_FLOAT32_C(  -125.25), SIMDE_FLOAT32_C(   237.19), SIMDE_FLOAT32_C(   989.38) },
      { -INT32_C(   756982898),  INT32_C(   160619632), -INT32_C(  1948436940),  INT32_C(   348521319) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(   209.64), SIMDE_FLOAT32_C(   466.53), SIMDE_FLOAT32_C(   945.16), SIMDE_FLOAT32_C(  -590.11) } },
  };

  simde__m128 a, b, r;
  simde__m128i c;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_mask_fixupimm_ps(a, test_vec[0].k, b, c, INT32_C(         106));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_mask_fixupimm_ps(a, test_vec[1].k, b, c, INT32_C(          69));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_mask_fixupimm_ps(a, test_vec[2].k, b, c, INT32_C(          94));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_mask_fixupimm_ps(a, test_vec[3].k, b, c, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_mask_fixupimm_ps(a, test_vec[4].k, b, c, INT32_C(         123));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_mask_fixupimm_ps(a, test_vec[5].k, b, c, INT32_C(         251));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_mask_fixupimm_ps(a, test_vec[6].k, b, c, INT32_C(          69));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_mask_fixupimm_ps(a, test_vec[7].k, b, c, INT32_C(         176));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128i c = simde_test_x86_random_i32x4();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_fixupimm_ps, r, simde_mm_setzero_ps(), imm8, a, k, b, c);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_fixupimm_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t c[4];
    const int imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(124),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   638.62),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -132.35) },
      { SIMDE_FLOAT32_C(   380.68),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -115.28) },
      {  INT32_C(    89279609),  INT32_C(  1064433692),  INT32_C(   831920124),  INT32_C(  1881735017) },
       INT32_C(         173),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(  -132.35) } },
    { UINT8_C(106),
      { SIMDE_FLOAT32_C(   -96.63), SIMDE_FLOAT32_C(  -711.38), SIMDE_FLOAT32_C(   -45.21), SIMDE_FLOAT32_C(  -751.31) },
      { SIMDE_FLOAT32_C(  -590.46), SIMDE_FLOAT32_C(  -177.78), SIMDE_FLOAT32_C(  -944.81), SIMDE_FLOAT32_C(  -564.35) },
      { -INT32_C(  1439743690),  INT32_C(  1841087159),  INT32_C(   770062561), -INT32_C(  2092307317) },
       INT32_C(          93),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF } },
    { UINT8_C( 31),
      { SIMDE_FLOAT32_C(   787.86), SIMDE_FLOAT32_C(   287.26), SIMDE_FLOAT32_C(    -7.95), SIMDE_FLOAT32_C(  -547.62) },
      { SIMDE_FLOAT32_C(   459.87), SIMDE_FLOAT32_C(  -641.82), SIMDE_FLOAT32_C(   120.92), SIMDE_FLOAT32_C(   976.19) },
      { -INT32_C(   652288335),  INT32_C(  1458752334),  INT32_C(   932011254),  INT32_C(  1324234636) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(     1.57),     -SIMDE_MATH_INFINITYF,            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF } },
    { UINT8_C( 66),
      { SIMDE_FLOAT32_C(   -62.56), SIMDE_FLOAT32_C(   669.91), SIMDE_FLOAT32_C(  -683.46), SIMDE_FLOAT32_C(   363.85) },
      { SIMDE_FLOAT32_C(  -988.00), SIMDE_FLOAT32_C(   193.28), SIMDE_FLOAT32_C(   703.87), SIMDE_FLOAT32_C(  -318.33) },
      { -INT32_C(  1490110627), -INT32_C(  1154512069), -INT32_C(   580104449),  INT32_C(   925582700) },
       INT32_C(          56),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 15),
      { SIMDE_FLOAT32_C(  -168.10), SIMDE_FLOAT32_C(   811.95), SIMDE_FLOAT32_C(   549.32), SIMDE_FLOAT32_C(  -787.42) },
      { SIMDE_FLOAT32_C(   257.19), SIMDE_FLOAT32_C(  -112.09), SIMDE_FLOAT32_C(    97.30), SIMDE_FLOAT32_C(  -839.44) },
      {  INT32_C(  1413881957), -INT32_C(  1615906193),  INT32_C(   519893351), -INT32_C(  1436966113) },
       INT32_C(         211),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    97.30), SIMDE_FLOAT32_C(     1.00) } },
    { UINT8_C(128),
      { SIMDE_FLOAT32_C(   176.53), SIMDE_FLOAT32_C(  -947.91), SIMDE_FLOAT32_C(  -590.75), SIMDE_FLOAT32_C(   586.07) },
      { SIMDE_FLOAT32_C(  -125.69), SIMDE_FLOAT32_C(  -535.56), SIMDE_FLOAT32_C(  -978.29), SIMDE_FLOAT32_C(  -337.83) },
      { -INT32_C(  1278833017), -INT32_C(   214565179), -INT32_C(  1285995374), -INT32_C(   987583094) },
       INT32_C(          92),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(189),
      { SIMDE_FLOAT32_C(   751.71), SIMDE_FLOAT32_C(    13.77), SIMDE_FLOAT32_C(   114.55), SIMDE_FLOAT32_C(   211.58) },
      { SIMDE_FLOAT32_C(   371.94), SIMDE_FLOAT32_C(  -764.53), SIMDE_FLOAT32_C(   187.77), SIMDE_FLOAT32_C(  -690.62) },
      { -INT32_C(  1537118902), -INT32_C(  1028115432), -INT32_C(   481740459), -INT32_C(    39191297) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     1.57) } },
    { UINT8_C(245),
      { SIMDE_FLOAT32_C(   905.38), SIMDE_FLOAT32_C(   504.31), SIMDE_FLOAT32_C(   673.23), SIMDE_FLOAT32_C(   917.38) },
      { SIMDE_FLOAT32_C(  -302.41), SIMDE_FLOAT32_C(   377.10), SIMDE_FLOAT32_C(  -400.95), SIMDE_FLOAT32_C(   529.50) },
      {  INT32_C(  1688338498), -INT32_C(   249167931), -INT32_C(  1170480307),  INT32_C(  2027085636) },
       INT32_C(         152),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  simde__m128 a, b, r;
  simde__m128i c;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_maskz_fixupimm_ps(test_vec[0].k, a, b, c, INT32_C(         173));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_maskz_fixupimm_ps(test_vec[1].k, a, b, c, INT32_C(          93));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_maskz_fixupimm_ps(test_vec[2].k, a, b, c, INT32_C(         244));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_maskz_fixupimm_ps(test_vec[3].k, a, b, c, INT32_C(          56));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_maskz_fixupimm_ps(test_vec[4].k, a, b, c, INT32_C(         211));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_maskz_fixupimm_ps(test_vec[5].k, a, b, c, INT32_C(          92));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_maskz_fixupimm_ps(test_vec[6].k, a, b, c, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_maskz_fixupimm_ps(test_vec[7].k, a, b, c, INT32_C(         152));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128i c = simde_test_x86_random_i32x4();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_fixupimm_ps, r, simde_mm_setzero_ps(), imm8, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_fixupimm_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const simde_float32 b[8];
    const int32_t c[8];
    const int imm8;
    const simde_float32 r[8];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -717.50),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -862.43),
        SIMDE_FLOAT32_C(  -740.31), SIMDE_FLOAT32_C(  -981.92), SIMDE_FLOAT32_C(   395.85), SIMDE_FLOAT32_C(  -866.87) },
      { SIMDE_FLOAT32_C(  -920.35),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -757.57),
        SIMDE_FLOAT32_C(   266.74), SIMDE_FLOAT32_C(  -725.14), SIMDE_FLOAT32_C(   112.06), SIMDE_FLOAT32_C(   327.58) },
      {  INT32_C(   778834093),  INT32_C(   354272015), -INT32_C(    78709799), -INT32_C(   165808334),  INT32_C(   871982277),  INT32_C(   444242987),  INT32_C(   453967824), -INT32_C(   692770008) },
       INT32_C(          59),
      { SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    -1.00),     -SIMDE_MATH_INFINITYF,
                   SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(   112.06), SIMDE_FLOAT32_C(     1.57) } },
    { { SIMDE_FLOAT32_C(  -543.90), SIMDE_FLOAT32_C(  -832.07), SIMDE_FLOAT32_C(  -172.54), SIMDE_FLOAT32_C(  -212.80),
        SIMDE_FLOAT32_C(   110.31), SIMDE_FLOAT32_C(   254.25), SIMDE_FLOAT32_C(   616.87), SIMDE_FLOAT32_C(  -886.83) },
      { SIMDE_FLOAT32_C(  -780.07), SIMDE_FLOAT32_C(   724.14), SIMDE_FLOAT32_C(  -604.09), SIMDE_FLOAT32_C(  -796.62),
        SIMDE_FLOAT32_C(  -291.37), SIMDE_FLOAT32_C(   242.20), SIMDE_FLOAT32_C(   593.52), SIMDE_FLOAT32_C(  -398.18) },
      { -INT32_C(  1100996123),  INT32_C(  1337568796),  INT32_C(  1799739046),  INT32_C(  1721712187), -INT32_C(  1417668134),  INT32_C(  1103531545), -INT32_C(   199787591), -INT32_C(  2109858659) },
       INT32_C(          61),
      { SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.50),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.50),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF } },
    { { SIMDE_FLOAT32_C(   524.71), SIMDE_FLOAT32_C(  -255.94), SIMDE_FLOAT32_C(  -260.61), SIMDE_FLOAT32_C(   784.39),
        SIMDE_FLOAT32_C(  -237.86), SIMDE_FLOAT32_C(  -864.77), SIMDE_FLOAT32_C(   917.52), SIMDE_FLOAT32_C(  -158.21) },
      { SIMDE_FLOAT32_C(  -793.92), SIMDE_FLOAT32_C(  -112.64), SIMDE_FLOAT32_C(    84.22), SIMDE_FLOAT32_C(   472.81),
        SIMDE_FLOAT32_C(   162.22), SIMDE_FLOAT32_C(  -803.72), SIMDE_FLOAT32_C(  -199.61), SIMDE_FLOAT32_C(   618.32) },
      { -INT32_C(   206964403),  INT32_C(   173993679),  INT32_C(   124845357),  INT32_C(   817033239),  INT32_C(   930183550), -INT32_C(  1859417612), -INT32_C(   502043995),  INT32_C(  1430016776) },
       INT32_C(          76),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(  -260.61),            SIMDE_MATH_NANF,
                   SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -803.72),            SIMDE_MATH_NANF,      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(  -635.79), SIMDE_FLOAT32_C(   627.86), SIMDE_FLOAT32_C(  -594.48), SIMDE_FLOAT32_C(   474.52),
        SIMDE_FLOAT32_C(  -117.90), SIMDE_FLOAT32_C(  -977.61), SIMDE_FLOAT32_C(   587.68), SIMDE_FLOAT32_C(   102.04) },
      { SIMDE_FLOAT32_C(   746.53), SIMDE_FLOAT32_C(   983.59), SIMDE_FLOAT32_C(   305.42), SIMDE_FLOAT32_C(  -544.84),
        SIMDE_FLOAT32_C(   225.79), SIMDE_FLOAT32_C(  -101.06), SIMDE_FLOAT32_C(    56.98), SIMDE_FLOAT32_C(  -249.50) },
      {  INT32_C(    19310548), -INT32_C(  1157064796),  INT32_C(   116112263),  INT32_C(   675110196), -INT32_C(  1950717466), -INT32_C(   613560877),  INT32_C(  1831971361),  INT32_C(  1669953935) },
       INT32_C(          32),
      { SIMDE_FLOAT32_C(  -635.79), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(  -594.48), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.50),      SIMDE_MATH_INFINITYF,            SIMDE_MATH_NANF } },
    { { SIMDE_FLOAT32_C(   643.00), SIMDE_FLOAT32_C(   796.36), SIMDE_FLOAT32_C(  -465.10), SIMDE_FLOAT32_C(  -594.86),
        SIMDE_FLOAT32_C(   931.60), SIMDE_FLOAT32_C(  -547.58), SIMDE_FLOAT32_C(   246.93), SIMDE_FLOAT32_C(  -862.33) },
      { SIMDE_FLOAT32_C(   339.78), SIMDE_FLOAT32_C(  -668.85), SIMDE_FLOAT32_C(   610.49), SIMDE_FLOAT32_C(  -498.00),
        SIMDE_FLOAT32_C(  -472.57), SIMDE_FLOAT32_C(  -589.12), SIMDE_FLOAT32_C(  -879.69), SIMDE_FLOAT32_C(  -108.36) },
      { -INT32_C(   830444217),  INT32_C(  1557425192), -INT32_C(  1350298935),  INT32_C(  1312439931),  INT32_C(   757704460), -INT32_C(   509978031), -INT32_C(   196860716),  INT32_C(   465152468) },
       INT32_C(          22),
      { SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),
        SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(  -589.12),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.50) } },
    { { SIMDE_FLOAT32_C(  -961.26), SIMDE_FLOAT32_C(  -474.17), SIMDE_FLOAT32_C(  -633.84), SIMDE_FLOAT32_C(   -79.16),
        SIMDE_FLOAT32_C(  -451.78), SIMDE_FLOAT32_C(   953.84), SIMDE_FLOAT32_C(  -977.12), SIMDE_FLOAT32_C(  -705.25) },
      { SIMDE_FLOAT32_C(   937.43), SIMDE_FLOAT32_C(   328.30), SIMDE_FLOAT32_C(  -250.09), SIMDE_FLOAT32_C(   163.22),
        SIMDE_FLOAT32_C(  -772.76), SIMDE_FLOAT32_C(   806.89), SIMDE_FLOAT32_C(   913.73), SIMDE_FLOAT32_C(   870.24) },
      {  INT32_C(  1872412326),  INT32_C(  1260265168),  INT32_C(  1771657309),  INT32_C(  1368834815), -INT32_C(   248369123),  INT32_C(   686126676),  INT32_C(   893624095),  INT32_C(  2138254809) },
       INT32_C(         235),
      {      SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -1.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(  -772.76),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -0.00) } },
    { { SIMDE_FLOAT32_C(   603.25), SIMDE_FLOAT32_C(  -551.38), SIMDE_FLOAT32_C(  -724.63), SIMDE_FLOAT32_C(   534.85),
        SIMDE_FLOAT32_C(   -98.96), SIMDE_FLOAT32_C(   522.30), SIMDE_FLOAT32_C(   672.52), SIMDE_FLOAT32_C(  -759.19) },
      { SIMDE_FLOAT32_C(   853.45), SIMDE_FLOAT32_C(   283.01), SIMDE_FLOAT32_C(  -257.19), SIMDE_FLOAT32_C(  -619.12),
        SIMDE_FLOAT32_C(   693.89), SIMDE_FLOAT32_C(  -136.88), SIMDE_FLOAT32_C(   272.52), SIMDE_FLOAT32_C(   732.63) },
      { -INT32_C(  1996092372),  INT32_C(  1676844900),  INT32_C(  2125760609),  INT32_C(   225437368),  INT32_C(  2083870045), -INT32_C(   843941388), -INT32_C(  1857280602),  INT32_C(  1598831155) },
       INT32_C(          70),
      { SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     1.57),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(    -1.00),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   388.95), SIMDE_FLOAT32_C(   638.68), SIMDE_FLOAT32_C(  -346.52), SIMDE_FLOAT32_C(   937.17),
        SIMDE_FLOAT32_C(   592.52), SIMDE_FLOAT32_C(  -323.64), SIMDE_FLOAT32_C(  -768.07), SIMDE_FLOAT32_C(   529.95) },
      { SIMDE_FLOAT32_C(  -995.34), SIMDE_FLOAT32_C(   -18.16), SIMDE_FLOAT32_C(  -306.83), SIMDE_FLOAT32_C(  -768.10),
        SIMDE_FLOAT32_C(  -211.27), SIMDE_FLOAT32_C(  -393.10), SIMDE_FLOAT32_C(  -897.87), SIMDE_FLOAT32_C(  -608.02) },
      {  INT32_C(  1376639729),  INT32_C(   449954402),  INT32_C(    86458536), -INT32_C(  1987945067),  INT32_C(  2086024406), -INT32_C(  1945263527),  INT32_C(   585849308), -INT32_C(  1664298069) },
       INT32_C(         173),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -1.00),
        SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(    90.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    90.00) } },
  };

  simde__m256 a, b, r;
  simde__m256i c;

  a = simde_mm256_loadu_ps(test_vec[0].a);
  b = simde_mm256_loadu_ps(test_vec[0].b);
  c = simde_x_mm256_loadu_epi32(test_vec[0].c);
  r = simde_mm256_fixupimm_ps(a, b, c, INT32_C(          59));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[0].r), 1);

  a = simde_mm256_loadu_ps(test_vec[1].a);
  b = simde_mm256_loadu_ps(test_vec[1].b);
  c = simde_x_mm256_loadu_epi32(test_vec[1].c);
  r = simde_mm256_fixupimm_ps(a, b, c, INT32_C(          61));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[1].r), 1);

  a = simde_mm256_loadu_ps(test_vec[2].a);
  b = simde_mm256_loadu_ps(test_vec[2].b);
  c = simde_x_mm256_loadu_epi32(test_vec[2].c);
  r = simde_mm256_fixupimm_ps(a, b, c, INT32_C(          76));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[2].r), 1);

  a = simde_mm256_loadu_ps(test_vec[3].a);
  b = simde_mm256_loadu_ps(test_vec[3].b);
  c = simde_x_mm256_loadu_epi32(test_vec[3].c);
  r = simde_mm256_fixupimm_ps(a, b, c, INT32_C(          32));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[3].r), 1);

  a = simde_mm256_loadu_ps(test_vec[4].a);
  b = simde_mm256_loadu_ps(test_vec[4].b);
  c = simde_x_mm256_loadu_epi32(test_vec[4].c);
  r = simde_mm256_fixupimm_ps(a, b, c, INT32_C(          22));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[4].r), 1);

  a = simde_mm256_loadu_ps(test_vec[5].a);
  b = simde_mm256_loadu_ps(test_vec[5].b);
  c = simde_x_mm256_loadu_epi32(test_vec[5].c);
  r = simde_mm256_fixupimm_ps(a, b, c, INT32_C(         235));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);

  a = simde_mm256_loadu_ps(test_vec[6].a);
  b = simde_mm256_loadu_ps(test_vec[6].b);
  c = simde_x_mm256_loadu_epi32(test_vec[6].c);
  r = simde_mm256_fixupimm_ps(a, b, c, INT32_C(          70));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  a = simde_mm256_loadu_ps(test_vec[7].a);
  b = simde_mm256_loadu_ps(test_vec[7].b);
  c = simde_x_mm256_loadu_epi32(test_vec[7].c);
  r = simde_mm256_fixupimm_ps(a, b, c, INT32_C(         173));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m256)];
  simde_test_x86_random_f32x8_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_extract_f32x8(i, 2, 0, values);
    simde__m256 b = simde_test_x86_random_extract_f32x8(i, 2, 1, values);
    simde__m256i c = simde_test_x86_random_i32x8();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256 r;
    SIMDE_CONSTIFY_256_(simde_mm256_fixupimm_ps, r, simde_mm256_setzero_ps(), imm8, a, b, c);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_fixupimm_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const simde__mmask8 k;
    const simde_float32 b[8];
    const int32_t c[8];
    const int imm8;
    const simde_float32 r[8];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -701.09),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -192.64),
        SIMDE_FLOAT32_C(  -447.73), SIMDE_FLOAT32_C(  -514.77), SIMDE_FLOAT32_C(  -642.51), SIMDE_FLOAT32_C(  -424.83) },
      UINT8_C(180),
      { SIMDE_FLOAT32_C(   471.49),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -677.28),
        SIMDE_FLOAT32_C(  -276.38), SIMDE_FLOAT32_C(  -462.43), SIMDE_FLOAT32_C(  -239.73), SIMDE_FLOAT32_C(  -354.30) },
      { -INT32_C(  1317828619), -INT32_C(  1442836490),  INT32_C(   718401157),  INT32_C(  1057338427), -INT32_C(    85827389),  INT32_C(  1211196643), -INT32_C(  1129387323), -INT32_C(  1150287674) },
       INT32_C(         135),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -701.09),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -192.64),
        SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -642.51), SIMDE_FLOAT32_C(     0.50) } },
    { { SIMDE_FLOAT32_C(  -213.42), SIMDE_FLOAT32_C(   235.52), SIMDE_FLOAT32_C(  -616.19), SIMDE_FLOAT32_C(    64.87),
        SIMDE_FLOAT32_C(  -497.47), SIMDE_FLOAT32_C(   660.86), SIMDE_FLOAT32_C(   -68.87), SIMDE_FLOAT32_C(  -443.85) },
      UINT8_C(243),
      { SIMDE_FLOAT32_C(   891.56), SIMDE_FLOAT32_C(  -909.49), SIMDE_FLOAT32_C(  -692.78), SIMDE_FLOAT32_C(   691.38),
        SIMDE_FLOAT32_C(  -378.80), SIMDE_FLOAT32_C(   606.71), SIMDE_FLOAT32_C(   445.52), SIMDE_FLOAT32_C(  -694.43) },
      {  INT32_C(  1517889644), -INT32_C(  1365924871),  INT32_C(   141677736),  INT32_C(   468413622), -INT32_C(  1998572387), -INT32_C(   498164510), -INT32_C(   244774643), -INT32_C(   488315019) },
       INT32_C(          16),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(  -616.19), SIMDE_FLOAT32_C(    64.87),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF } },
    { { SIMDE_FLOAT32_C(   905.62), SIMDE_FLOAT32_C(   -67.52), SIMDE_FLOAT32_C(   112.93), SIMDE_FLOAT32_C(  -542.11),
        SIMDE_FLOAT32_C(   417.71), SIMDE_FLOAT32_C(   470.42), SIMDE_FLOAT32_C(    33.06), SIMDE_FLOAT32_C(  -110.80) },
      UINT8_C(  0),
      { SIMDE_FLOAT32_C(  -604.83), SIMDE_FLOAT32_C(  -390.12), SIMDE_FLOAT32_C(   211.92), SIMDE_FLOAT32_C(   118.79),
        SIMDE_FLOAT32_C(   147.45), SIMDE_FLOAT32_C(   972.19), SIMDE_FLOAT32_C(   764.49), SIMDE_FLOAT32_C(   934.03) },
      { -INT32_C(  1498892334), -INT32_C(  1789022167), -INT32_C(   801998692), -INT32_C(   172836264),  INT32_C(   285381640), -INT32_C(   444075011),  INT32_C(   905275863),  INT32_C(  2000027301) },
       INT32_C(         182),
      { SIMDE_FLOAT32_C(   905.62), SIMDE_FLOAT32_C(   -67.52), SIMDE_FLOAT32_C(   112.93), SIMDE_FLOAT32_C(  -542.11),
        SIMDE_FLOAT32_C(   417.71), SIMDE_FLOAT32_C(   470.42), SIMDE_FLOAT32_C(    33.06), SIMDE_FLOAT32_C(  -110.80) } },
    { { SIMDE_FLOAT32_C(   207.71), SIMDE_FLOAT32_C(  -851.70), SIMDE_FLOAT32_C(    -1.10), SIMDE_FLOAT32_C(   710.23),
        SIMDE_FLOAT32_C(   809.17), SIMDE_FLOAT32_C(   930.03), SIMDE_FLOAT32_C(  -733.61), SIMDE_FLOAT32_C(   700.73) },
      UINT8_C(142),
      { SIMDE_FLOAT32_C(  -979.45), SIMDE_FLOAT32_C(  -426.40), SIMDE_FLOAT32_C(   392.11), SIMDE_FLOAT32_C(  -358.25),
        SIMDE_FLOAT32_C(  -819.69), SIMDE_FLOAT32_C(  -162.38), SIMDE_FLOAT32_C(   -52.68), SIMDE_FLOAT32_C(  -914.07) },
      { -INT32_C(   215321477),  INT32_C(  1632369318),  INT32_C(  1080639660),  INT32_C(   893287234),  INT32_C(  1796023042),  INT32_C(   370164248),  INT32_C(  1439467639),  INT32_C(   568634278) },
       INT32_C(          31),
      { SIMDE_FLOAT32_C(   207.71), SIMDE_FLOAT32_C(  -426.40),     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(   809.17), SIMDE_FLOAT32_C(   930.03), SIMDE_FLOAT32_C(  -733.61), SIMDE_FLOAT32_C(  -914.07) } },
    { { SIMDE_FLOAT32_C(   770.10), SIMDE_FLOAT32_C(  -939.75), SIMDE_FLOAT32_C(  -456.19), SIMDE_FLOAT32_C(   187.81),
        SIMDE_FLOAT32_C(   530.68), SIMDE_FLOAT32_C(   576.87), SIMDE_FLOAT32_C(  -922.99), SIMDE_FLOAT32_C(   925.85) },
      UINT8_C(  9),
      { SIMDE_FLOAT32_C(  -813.24), SIMDE_FLOAT32_C(   288.94), SIMDE_FLOAT32_C(    44.64), SIMDE_FLOAT32_C(   334.21),
        SIMDE_FLOAT32_C(   261.13), SIMDE_FLOAT32_C(  -190.87), SIMDE_FLOAT32_C(   268.25), SIMDE_FLOAT32_C(  -531.16) },
      { -INT32_C(  1598740641),  INT32_C(   199423632),  INT32_C(  1460475956),  INT32_C(  1735358501),  INT32_C(   299795849), -INT32_C(    38325166),  INT32_C(   639490072),  INT32_C(  1261429740) },
       INT32_C(          10),
      { SIMDE_FLOAT32_C(   770.10), SIMDE_FLOAT32_C(  -939.75), SIMDE_FLOAT32_C(  -456.19),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(   530.68), SIMDE_FLOAT32_C(   576.87), SIMDE_FLOAT32_C(  -922.99), SIMDE_FLOAT32_C(   925.85) } },
    { { SIMDE_FLOAT32_C(   -42.56), SIMDE_FLOAT32_C(  -732.85), SIMDE_FLOAT32_C(  -820.93), SIMDE_FLOAT32_C(  -233.39),
        SIMDE_FLOAT32_C(  -802.82), SIMDE_FLOAT32_C(  -554.54), SIMDE_FLOAT32_C(  -532.66), SIMDE_FLOAT32_C(  -782.27) },
      UINT8_C(219),
      { SIMDE_FLOAT32_C(    19.06), SIMDE_FLOAT32_C(   859.44), SIMDE_FLOAT32_C(  -140.53), SIMDE_FLOAT32_C(   199.37),
        SIMDE_FLOAT32_C(  -302.94), SIMDE_FLOAT32_C(   806.79), SIMDE_FLOAT32_C(   285.30), SIMDE_FLOAT32_C(  -532.83) },
      { -INT32_C(   435181874),  INT32_C(   738944691),  INT32_C(  1521840853), -INT32_C(  2069051824),  INT32_C(  1436330621), -INT32_C(  1438530617), -INT32_C(   676033294),  INT32_C(  1186090616) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -820.93), SIMDE_FLOAT32_C(     0.00),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -554.54), SIMDE_FLOAT32_C(     1.57),     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   867.05), SIMDE_FLOAT32_C(   829.11), SIMDE_FLOAT32_C(   654.98), SIMDE_FLOAT32_C(   397.72),
        SIMDE_FLOAT32_C(   405.99), SIMDE_FLOAT32_C(   731.99), SIMDE_FLOAT32_C(   323.57), SIMDE_FLOAT32_C(   592.74) },
      UINT8_C( 39),
      { SIMDE_FLOAT32_C(    20.93), SIMDE_FLOAT32_C(  -631.79), SIMDE_FLOAT32_C(   -73.04), SIMDE_FLOAT32_C(  -717.94),
        SIMDE_FLOAT32_C(   177.34), SIMDE_FLOAT32_C(  -804.80), SIMDE_FLOAT32_C(  -249.11), SIMDE_FLOAT32_C(  -865.22) },
      { -INT32_C(  1443048393),  INT32_C(  1341740937), -INT32_C(  1379107325), -INT32_C(   579591910), -INT32_C(   288350622),  INT32_C(   560375762),  INT32_C(   454405210),  INT32_C(   256097752) },
       INT32_C(         145),
      { SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(   397.72),
        SIMDE_FLOAT32_C(   405.99), SIMDE_FLOAT32_C(  -804.80), SIMDE_FLOAT32_C(   323.57), SIMDE_FLOAT32_C(   592.74) } },
    { { SIMDE_FLOAT32_C(  -537.65), SIMDE_FLOAT32_C(   -70.04), SIMDE_FLOAT32_C(   -98.61), SIMDE_FLOAT32_C(  -340.47),
        SIMDE_FLOAT32_C(   375.42), SIMDE_FLOAT32_C(   368.72), SIMDE_FLOAT32_C(  -122.75), SIMDE_FLOAT32_C(  -605.52) },
      UINT8_C(150),
      { SIMDE_FLOAT32_C(   228.17), SIMDE_FLOAT32_C(   736.72), SIMDE_FLOAT32_C(   593.85), SIMDE_FLOAT32_C(   925.23),
        SIMDE_FLOAT32_C(   543.52), SIMDE_FLOAT32_C(  -120.85), SIMDE_FLOAT32_C(  -607.60), SIMDE_FLOAT32_C(   410.57) },
      {  INT32_C(   815425970),  INT32_C(  1447708469), -INT32_C(   625465156), -INT32_C(  1616009224), -INT32_C(  1158033907), -INT32_C(  1584261661), -INT32_C(  1758289320),  INT32_C(   204361050) },
       INT32_C(         182),
      { SIMDE_FLOAT32_C(  -537.65),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(  -340.47),
        SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(   368.72), SIMDE_FLOAT32_C(  -122.75), SIMDE_FLOAT32_C(  -605.52) } },
  };

  simde__m256 a, b, r;
  simde__m256i c;

  a = simde_mm256_loadu_ps(test_vec[0].a);
  b = simde_mm256_loadu_ps(test_vec[0].b);
  c = simde_x_mm256_loadu_epi32(test_vec[0].c);
  r = simde_mm256_mask_fixupimm_ps(a, test_vec[0].k, b, c, INT32_C(         135));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[0].r), 1);

  a = simde_mm256_loadu_ps(test_vec[1].a);
  b = simde_mm256_loadu_ps(test_vec[1].b);
  c = simde_x_mm256_loadu_epi32(test_vec[1].c);
  r = simde_mm256_mask_fixupimm_ps(a, test_vec[1].k, b, c, INT32_C(          16));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[1].r), 1);

  a = simde_mm256_loadu_ps(test_vec[2].a);
  b = simde_mm256_loadu_ps(test_vec[2].b);
  c = simde_x_mm256_loadu_epi32(test_vec[2].c);
  r = simde_mm256_mask_fixupimm_ps(a, test_vec[2].k, b, c, INT32_C(         182));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[2].r), 1);

  a = simde_mm256_loadu_ps(test_vec[3].a);
  b = simde_mm256_loadu_ps(test_vec[3].b);
  c = simde_x_mm256_loadu_epi32(test_vec[3].c);
  r = simde_mm256_mask_fixupimm_ps(a, test_vec[3].k, b, c, INT32_C(          31));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[3].r), 1);

  a = simde_mm256_loadu_ps(test_vec[4].a);
  b = simde_mm256_loadu_ps(test_vec[4].b);
  c = simde_x_mm256_loadu_epi32(test_vec[4].c);
  r = simde_mm256_mask_fixupimm_ps(a, test_vec[4].k, b, c, INT32_C(          10));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[4].r), 1);

  a = simde_mm256_loadu_ps(test_vec[5].a);
  b = simde_mm256_loadu_ps(test_vec[5].b);
  c = simde_x_mm256_loadu_epi32(test_vec[5].c);
  r = simde_mm256_mask_fixupimm_ps(a, test_vec[5].k, b, c, INT32_C(         244));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);

  a = simde_mm256_loadu_ps(test_vec[6].a);
  b = simde_mm256_loadu_ps(test_vec[6].b);
  c = simde_x_mm256_loadu_epi32(test_vec[6].c);
  r = simde_mm256_mask_fixupimm_ps(a, test_vec[6].k, b, c, INT32_C(         145));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  a = simde_mm256_loadu_ps(test_vec[7].a);
  b = simde_mm256_loadu_ps(test_vec[7].b);
  c = simde_x_mm256_loadu_epi32(test_vec[7].c);
  r = simde_mm256_mask_fixupimm_ps(a, test_vec[7].k, b, c, INT32_C(         182));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m256)];
  simde_test_x86_random_f32x8_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_extract_f32x8(i, 2, 0, values);
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 b = simde_test_x86_random_extract_f32x8(i, 2, 1, values);
    simde__m256i c = simde_test_x86_random_i32x8();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256 r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_fixupimm_ps, r, simde_mm256_setzero_ps(), imm8, a, k, b, c);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_fixupimm_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const simde_float32 b[8];
    const int32_t c[8];
    const int imm8;
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C( 69),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   940.69),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -989.43),
        SIMDE_FLOAT32_C(  -775.07), SIMDE_FLOAT32_C(  -593.92), SIMDE_FLOAT32_C(  -620.41), SIMDE_FLOAT32_C(    43.35) },
      { SIMDE_FLOAT32_C(  -596.35),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   277.21),
        SIMDE_FLOAT32_C(  -589.86), SIMDE_FLOAT32_C(    41.85), SIMDE_FLOAT32_C(  -572.85), SIMDE_FLOAT32_C(   447.23) },
      { -INT32_C(   266951678),  INT32_C(  1046758520), -INT32_C(  1658184077), -INT32_C(   227928870), -INT32_C(   776419921), -INT32_C(   668170996),  INT32_C(  1544174320),  INT32_C(  2141363325) },
       INT32_C(          64),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(252),
      { SIMDE_FLOAT32_C(    50.98), SIMDE_FLOAT32_C(   -52.38), SIMDE_FLOAT32_C(  -835.14), SIMDE_FLOAT32_C(  -418.31),
        SIMDE_FLOAT32_C(   915.06), SIMDE_FLOAT32_C(   249.74), SIMDE_FLOAT32_C(   801.60), SIMDE_FLOAT32_C(  -744.22) },
      { SIMDE_FLOAT32_C(   225.98), SIMDE_FLOAT32_C(  -157.56), SIMDE_FLOAT32_C(   113.96), SIMDE_FLOAT32_C(   471.85),
        SIMDE_FLOAT32_C(   608.79), SIMDE_FLOAT32_C(   917.82), SIMDE_FLOAT32_C(  -800.62), SIMDE_FLOAT32_C(  -150.47) },
      { -INT32_C(   244320301),  INT32_C(   902499617),  INT32_C(  1038466423), -INT32_C(    79055242),  INT32_C(   501948899), -INT32_C(   929413076), -INT32_C(  1576527126),  INT32_C(  1570750601) },
       INT32_C(         183),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),
        SIMDE_FLOAT32_C(   608.79), SIMDE_FLOAT32_C(    90.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.57) } },
    { UINT8_C( 27),
      { SIMDE_FLOAT32_C(   858.50), SIMDE_FLOAT32_C(  -868.27), SIMDE_FLOAT32_C(  -139.90), SIMDE_FLOAT32_C(  -916.57),
        SIMDE_FLOAT32_C(  -462.20), SIMDE_FLOAT32_C(   239.69), SIMDE_FLOAT32_C(   126.79), SIMDE_FLOAT32_C(   -58.54) },
      { SIMDE_FLOAT32_C(   974.53), SIMDE_FLOAT32_C(    64.32), SIMDE_FLOAT32_C(  -781.34), SIMDE_FLOAT32_C(  -615.33),
        SIMDE_FLOAT32_C(  -893.82), SIMDE_FLOAT32_C(  -354.19), SIMDE_FLOAT32_C(   831.90), SIMDE_FLOAT32_C(   157.16) },
      { -INT32_C(   678228454), -INT32_C(  1454518029),  INT32_C(   999049241),  INT32_C(  2087168308),  INT32_C(  1583755076), -INT32_C(   135854025), -INT32_C(  1230027609), -INT32_C(  1378777197) },
       INT32_C(         149),
      { SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    90.00),
        SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 52),
      { SIMDE_FLOAT32_C(   593.43), SIMDE_FLOAT32_C(   996.76), SIMDE_FLOAT32_C(   738.85), SIMDE_FLOAT32_C(   508.50),
        SIMDE_FLOAT32_C(   246.50), SIMDE_FLOAT32_C(   540.45), SIMDE_FLOAT32_C(   764.28), SIMDE_FLOAT32_C(  -527.52) },
      { SIMDE_FLOAT32_C(  -617.11), SIMDE_FLOAT32_C(  -121.76), SIMDE_FLOAT32_C(   944.33), SIMDE_FLOAT32_C(   991.68),
        SIMDE_FLOAT32_C(  -203.94), SIMDE_FLOAT32_C(  -856.29), SIMDE_FLOAT32_C(  -158.79), SIMDE_FLOAT32_C(  -345.44) },
      {  INT32_C(   441332434),  INT32_C(  1749977534),  INT32_C(   531417840),  INT32_C(   961940016),  INT32_C(   920669681), -INT32_C(  2067163396), -INT32_C(   870746520), -INT32_C(   872307974) },
       INT32_C(         212),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   944.33), SIMDE_FLOAT32_C(     0.00),
            -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(216),
      { SIMDE_FLOAT32_C(  -724.56), SIMDE_FLOAT32_C(   701.31), SIMDE_FLOAT32_C(  -262.00), SIMDE_FLOAT32_C(  -186.76),
        SIMDE_FLOAT32_C(   -59.01), SIMDE_FLOAT32_C(   864.78), SIMDE_FLOAT32_C(   754.70), SIMDE_FLOAT32_C(   -84.47) },
      { SIMDE_FLOAT32_C(   -70.90), SIMDE_FLOAT32_C(   973.36), SIMDE_FLOAT32_C(   300.20), SIMDE_FLOAT32_C(    35.28),
        SIMDE_FLOAT32_C(  -380.82), SIMDE_FLOAT32_C(   132.10), SIMDE_FLOAT32_C(  -807.56), SIMDE_FLOAT32_C(  -787.39) },
      {  INT32_C(    13171253), -INT32_C(  1338972250), -INT32_C(  1969067715), -INT32_C(   527968182),  INT32_C(   390597537), -INT32_C(   971959004),  INT32_C(  1704648214), -INT32_C(    96653883) },
       INT32_C(          39),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     1.00) } },
    { UINT8_C(236),
      { SIMDE_FLOAT32_C(   128.86), SIMDE_FLOAT32_C(   931.29), SIMDE_FLOAT32_C(   721.11), SIMDE_FLOAT32_C(  -624.64),
        SIMDE_FLOAT32_C(   471.74), SIMDE_FLOAT32_C(   485.39), SIMDE_FLOAT32_C(  -152.15), SIMDE_FLOAT32_C(   854.63) },
      { SIMDE_FLOAT32_C(  -636.37), SIMDE_FLOAT32_C(  -207.82), SIMDE_FLOAT32_C(   846.32), SIMDE_FLOAT32_C(   159.69),
        SIMDE_FLOAT32_C(   -64.11), SIMDE_FLOAT32_C(  -312.47), SIMDE_FLOAT32_C(   814.25), SIMDE_FLOAT32_C(   211.33) },
      { -INT32_C(  1809220053), -INT32_C(   119622880),  INT32_C(  1167703866),  INT32_C(   476753927), -INT32_C(  1607323454), -INT32_C(   127559733), -INT32_C(   652255276), -INT32_C(  2050626214) },
       INT32_C(         108),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   159.69),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(162),
      { SIMDE_FLOAT32_C(  -611.17), SIMDE_FLOAT32_C(  -447.75), SIMDE_FLOAT32_C(  -975.43), SIMDE_FLOAT32_C(   329.83),
        SIMDE_FLOAT32_C(  -582.97), SIMDE_FLOAT32_C(   779.27), SIMDE_FLOAT32_C(  -754.65), SIMDE_FLOAT32_C(   346.13) },
      { SIMDE_FLOAT32_C(   752.63), SIMDE_FLOAT32_C(   545.55), SIMDE_FLOAT32_C(  -618.59), SIMDE_FLOAT32_C(  -628.19),
        SIMDE_FLOAT32_C(  -322.35), SIMDE_FLOAT32_C(  -426.15), SIMDE_FLOAT32_C(  -415.58), SIMDE_FLOAT32_C(   806.52) },
      { -INT32_C(  1210284552), -INT32_C(   809623010), -INT32_C(  1131291764), -INT32_C(  1517866739), -INT32_C(   176586858), -INT32_C(  1940958305),  INT32_C(   133747736), -INT32_C(   425097746) },
       INT32_C(          10),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00) } },
    { UINT8_C(167),
      { SIMDE_FLOAT32_C(  -494.85), SIMDE_FLOAT32_C(  -694.47), SIMDE_FLOAT32_C(  -818.12), SIMDE_FLOAT32_C(   976.89),
        SIMDE_FLOAT32_C(   790.92), SIMDE_FLOAT32_C(    29.73), SIMDE_FLOAT32_C(   831.52), SIMDE_FLOAT32_C(  -845.45) },
      { SIMDE_FLOAT32_C(   821.90), SIMDE_FLOAT32_C(   677.84), SIMDE_FLOAT32_C(   314.24), SIMDE_FLOAT32_C(  -242.21),
        SIMDE_FLOAT32_C(  -634.64), SIMDE_FLOAT32_C(   128.49), SIMDE_FLOAT32_C(   969.12), SIMDE_FLOAT32_C(  -245.80) },
      {  INT32_C(   909375323), -INT32_C(  1186664312), -INT32_C(   145757833), -INT32_C(  1248443038),  INT32_C(  1775116948), -INT32_C(  1604856549),  INT32_C(    61488510),  INT32_C(   900453082) },
       INT32_C(         202),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
  };

  simde__m256 a, b, r;
  simde__m256i c;

  a = simde_mm256_loadu_ps(test_vec[0].a);
  b = simde_mm256_loadu_ps(test_vec[0].b);
  c = simde_x_mm256_loadu_epi32(test_vec[0].c);
  r = simde_mm256_maskz_fixupimm_ps(test_vec[0].k, a, b, c, INT32_C(          64));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[0].r), 1);

  a = simde_mm256_loadu_ps(test_vec[1].a);
  b = simde_mm256_loadu_ps(test_vec[1].b);
  c = simde_x_mm256_loadu_epi32(test_vec[1].c);
  r = simde_mm256_maskz_fixupimm_ps(test_vec[1].k, a, b, c, INT32_C(         183));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[1].r), 1);

  a = simde_mm256_loadu_ps(test_vec[2].a);
  b = simde_mm256_loadu_ps(test_vec[2].b);
  c = simde_x_mm256_loadu_epi32(test_vec[2].c);
  r = simde_mm256_maskz_fixupimm_ps(test_vec[2].k, a, b, c, INT32_C(         149));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[2].r), 1);

  a = simde_mm256_loadu_ps(test_vec[3].a);
  b = simde_mm256_loadu_ps(test_vec[3].b);
  c = simde_x_mm256_loadu_epi32(test_vec[3].c);
  r = simde_mm256_maskz_fixupimm_ps(test_vec[3].k, a, b, c, INT32_C(         212));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[3].r), 1);

  a = simde_mm256_loadu_ps(test_vec[4].a);
  b = simde_mm256_loadu_ps(test_vec[4].b);
  c = simde_x_mm256_loadu_epi32(test_vec[4].c);
  r = simde_mm256_maskz_fixupimm_ps(test_vec[4].k, a, b, c, INT32_C(          39));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[4].r), 1);

  a = simde_mm256_loadu_ps(test_vec[5].a);
  b = simde_mm256_loadu_ps(test_vec[5].b);
  c = simde_x_mm256_loadu_epi32(test_vec[5].c);
  r = simde_mm256_maskz_fixupimm_ps(test_vec[5].k, a, b, c, INT32_C(         108));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);

  a = simde_mm256_loadu_ps(test_vec[6].a);
  b = simde_mm256_loadu_ps(test_vec[6].b);
  c = simde_x_mm256_loadu_epi32(test_vec[6].c);
  r = simde_mm256_maskz_fixupimm_ps(test_vec[6].k, a, b, c, INT32_C(          10));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  a = simde_mm256_loadu_ps(test_vec[7].a);
  b = simde_mm256_loadu_ps(test_vec[7].b);
  c = simde_x_mm256_loadu_epi32(test_vec[7].c);
  r = simde_mm256_maskz_fixupimm_ps(test_vec[7].k, a, b, c, INT32_C(         202));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m256)];
  simde_test_x86_random_f32x8_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_extract_f32x8(i, 2, 0, values);
    simde__m256 b = simde_test_x86_random_extract_f32x8(i, 2, 1, values);
    simde__m256i c = simde_test_x86_random_i32x8();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256 r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_fixupimm_ps, r, simde_mm256_setzero_ps(), imm8, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_fixupimm_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const int32_t c[16];
    const int imm8;
    const simde_float32 r[16];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -653.08),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -140.64),
        SIMDE_FLOAT32_C(  -825.82), SIMDE_FLOAT32_C(  -279.01), SIMDE_FLOAT32_C(   902.12), SIMDE_FLOAT32_C(  -376.10),
        SIMDE_FLOAT32_C(   812.35), SIMDE_FLOAT32_C(  -490.82), SIMDE_FLOAT32_C(  -666.64), SIMDE_FLOAT32_C(  -639.79),
        SIMDE_FLOAT32_C(   715.91), SIMDE_FLOAT32_C(  -962.06), SIMDE_FLOAT32_C(   524.79), SIMDE_FLOAT32_C(   -57.63) },
      { SIMDE_FLOAT32_C(  -611.63),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -962.93),
        SIMDE_FLOAT32_C(  -810.24), SIMDE_FLOAT32_C(  -361.16), SIMDE_FLOAT32_C(  -655.64), SIMDE_FLOAT32_C(  -360.58),
        SIMDE_FLOAT32_C(   652.40), SIMDE_FLOAT32_C(  -561.63), SIMDE_FLOAT32_C(  -896.90), SIMDE_FLOAT32_C(   595.45),
        SIMDE_FLOAT32_C(    59.08), SIMDE_FLOAT32_C(   135.17), SIMDE_FLOAT32_C(  -174.98), SIMDE_FLOAT32_C(   291.83) },
      {  INT32_C(    65344024), -INT32_C(  1043000603),  INT32_C(   310236860),  INT32_C(  1073926926),  INT32_C(  1299399004),  INT32_C(   912095120), -INT32_C(  1084049800),  INT32_C(   855801371),
         INT32_C(  1966532752), -INT32_C(  1237971974), -INT32_C(   271993631), -INT32_C(   483406969), -INT32_C(  1674534388), -INT32_C(  1831629286),  INT32_C(  1599157572),  INT32_C(  1150440627) },
       INT32_C(          60),
      {            SIMDE_MATH_NANF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(  -140.64),
        SIMDE_FLOAT32_C(     1.57),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),
        SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(   482.09), SIMDE_FLOAT32_C(   735.25), SIMDE_FLOAT32_C(  -848.81), SIMDE_FLOAT32_C(   656.27),
        SIMDE_FLOAT32_C(  -543.76), SIMDE_FLOAT32_C(  -946.69), SIMDE_FLOAT32_C(  -719.83), SIMDE_FLOAT32_C(  -731.41),
        SIMDE_FLOAT32_C(  -437.51), SIMDE_FLOAT32_C(  -386.47), SIMDE_FLOAT32_C(  -371.20), SIMDE_FLOAT32_C(  -721.60),
        SIMDE_FLOAT32_C(  -348.52), SIMDE_FLOAT32_C(  -846.41), SIMDE_FLOAT32_C(   220.77), SIMDE_FLOAT32_C(    39.85) },
      { SIMDE_FLOAT32_C(   463.28), SIMDE_FLOAT32_C(   704.75), SIMDE_FLOAT32_C(    76.92), SIMDE_FLOAT32_C(   653.03),
        SIMDE_FLOAT32_C(  -656.41), SIMDE_FLOAT32_C(   421.28), SIMDE_FLOAT32_C(  -707.55), SIMDE_FLOAT32_C(   995.99),
        SIMDE_FLOAT32_C(   859.65), SIMDE_FLOAT32_C(  -604.45), SIMDE_FLOAT32_C(   591.44), SIMDE_FLOAT32_C(   -81.27),
        SIMDE_FLOAT32_C(   530.72), SIMDE_FLOAT32_C(  -583.54), SIMDE_FLOAT32_C(  -789.43), SIMDE_FLOAT32_C(    12.82) },
      { -INT32_C(  1259540269),  INT32_C(   732149156), -INT32_C(  1928408191), -INT32_C(  1893056907),  INT32_C(   287505868), -INT32_C(   445615310),  INT32_C(    53019591), -INT32_C(  1623596085),
         INT32_C(  2001938131),  INT32_C(  1554184155),  INT32_C(  1072345290), -INT32_C(  1144056594),  INT32_C(  1137504529),  INT32_C(   740834404),  INT32_C(   187650623),  INT32_C(   145385781) },
       INT32_C(         143),
      { SIMDE_FLOAT32_C(     0.50),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -656.41), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -1.00),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    90.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.50),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(    39.85) } },
    { { SIMDE_FLOAT32_C(  -848.28), SIMDE_FLOAT32_C(  -638.24), SIMDE_FLOAT32_C(  -330.91), SIMDE_FLOAT32_C(  -392.04),
        SIMDE_FLOAT32_C(  -584.93), SIMDE_FLOAT32_C(   -50.74), SIMDE_FLOAT32_C(  -123.45), SIMDE_FLOAT32_C(   -22.44),
        SIMDE_FLOAT32_C(   562.79), SIMDE_FLOAT32_C(   505.35), SIMDE_FLOAT32_C(   255.96), SIMDE_FLOAT32_C(  -785.73),
        SIMDE_FLOAT32_C(   658.94), SIMDE_FLOAT32_C(  -523.27), SIMDE_FLOAT32_C(   254.12), SIMDE_FLOAT32_C(   122.21) },
      { SIMDE_FLOAT32_C(  -818.52), SIMDE_FLOAT32_C(  -668.97), SIMDE_FLOAT32_C(  -224.75), SIMDE_FLOAT32_C(  -474.93),
        SIMDE_FLOAT32_C(   752.31), SIMDE_FLOAT32_C(    67.70), SIMDE_FLOAT32_C(  -478.94), SIMDE_FLOAT32_C(   611.97),
        SIMDE_FLOAT32_C(   463.25), SIMDE_FLOAT32_C(  -887.50), SIMDE_FLOAT32_C(  -469.30), SIMDE_FLOAT32_C(    -6.03),
        SIMDE_FLOAT32_C(  -471.04), SIMDE_FLOAT32_C(  -258.73), SIMDE_FLOAT32_C(  -993.21), SIMDE_FLOAT32_C(  -319.32) },
      { -INT32_C(  1094245900), -INT32_C(  1073827375), -INT32_C(   696595003),  INT32_C(   572081854), -INT32_C(  1035058813), -INT32_C(   926056813),  INT32_C(  1993373671),  INT32_C(  1776308085),
         INT32_C(  1093183344),  INT32_C(   486614616), -INT32_C(  1309443085),  INT32_C(  1171459266), -INT32_C(   519626162), -INT32_C(  2018847328), -INT32_C(  1040352692),  INT32_C(   975953354) },
       INT32_C(         133),
      { SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),     -SIMDE_MATH_INFINITYF,            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(    90.00),     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(  -469.30),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(  -471.04), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(  -993.21), SIMDE_FLOAT32_C(     1.00) } },
    { { SIMDE_FLOAT32_C(   103.02), SIMDE_FLOAT32_C(  -324.12), SIMDE_FLOAT32_C(   288.63), SIMDE_FLOAT32_C(   518.09),
        SIMDE_FLOAT32_C(   625.14), SIMDE_FLOAT32_C(  -834.82), SIMDE_FLOAT32_C(  -504.35), SIMDE_FLOAT32_C(   187.94),
        SIMDE_FLOAT32_C(   670.53), SIMDE_FLOAT32_C(   751.61), SIMDE_FLOAT32_C(   402.21), SIMDE_FLOAT32_C(   329.47),
        SIMDE_FLOAT32_C(  -771.66), SIMDE_FLOAT32_C(  -343.67), SIMDE_FLOAT32_C(  -548.31), SIMDE_FLOAT32_C(  -590.18) },
      { SIMDE_FLOAT32_C(   -12.64), SIMDE_FLOAT32_C(   226.93), SIMDE_FLOAT32_C(   -65.11), SIMDE_FLOAT32_C(  -260.33),
        SIMDE_FLOAT32_C(  -705.37), SIMDE_FLOAT32_C(   455.95), SIMDE_FLOAT32_C(  -648.36), SIMDE_FLOAT32_C(   757.88),
        SIMDE_FLOAT32_C(   568.45), SIMDE_FLOAT32_C(  -117.66), SIMDE_FLOAT32_C(  -248.14), SIMDE_FLOAT32_C(  -902.59),
        SIMDE_FLOAT32_C(   623.60), SIMDE_FLOAT32_C(  -241.35), SIMDE_FLOAT32_C(  -221.92), SIMDE_FLOAT32_C(  -273.37) },
      {  INT32_C(  1828420985), -INT32_C(  1172443400),  INT32_C(  1241510139), -INT32_C(  1305868526),  INT32_C(   674878684),  INT32_C(   434779727), -INT32_C(  1722608364), -INT32_C(   512307352),
         INT32_C(  1162703180),  INT32_C(  1543465568),  INT32_C(  1839529818), -INT32_C(   501232122), -INT32_C(   234202717), -INT32_C(  1559497585),  INT32_C(  1899781641),  INT32_C(  2052240174) },
       INT32_C(          36),
      { SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(    -1.00),            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   455.95), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     1.57),            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -221.92), SIMDE_FLOAT32_C(     1.00) } },
    { { SIMDE_FLOAT32_C(   434.53), SIMDE_FLOAT32_C(  -933.28), SIMDE_FLOAT32_C(  -755.28), SIMDE_FLOAT32_C(    59.68),
        SIMDE_FLOAT32_C(  -768.10), SIMDE_FLOAT32_C(  -259.62), SIMDE_FLOAT32_C(  -752.38), SIMDE_FLOAT32_C(   902.43),
        SIMDE_FLOAT32_C(  -508.01), SIMDE_FLOAT32_C(   649.83), SIMDE_FLOAT32_C(   231.90), SIMDE_FLOAT32_C(  -279.67),
        SIMDE_FLOAT32_C(  -693.85), SIMDE_FLOAT32_C(   683.59), SIMDE_FLOAT32_C(   130.14), SIMDE_FLOAT32_C(   293.52) },
      { SIMDE_FLOAT32_C(   -89.48), SIMDE_FLOAT32_C(  -934.97), SIMDE_FLOAT32_C(  -966.81), SIMDE_FLOAT32_C(   205.16),
        SIMDE_FLOAT32_C(   520.98), SIMDE_FLOAT32_C(  -615.17), SIMDE_FLOAT32_C(   -36.96), SIMDE_FLOAT32_C(    89.42),
        SIMDE_FLOAT32_C(   267.17), SIMDE_FLOAT32_C(   714.90), SIMDE_FLOAT32_C(   186.83), SIMDE_FLOAT32_C(  -109.23),
        SIMDE_FLOAT32_C(  -526.45), SIMDE_FLOAT32_C(   964.91), SIMDE_FLOAT32_C(   617.40), SIMDE_FLOAT32_C(   908.08) },
      {  INT32_C(  1692385033), -INT32_C(   992902210), -INT32_C(   173608878), -INT32_C(   639127479), -INT32_C(  1367543131),  INT32_C(  2116073808), -INT32_C(  1862700436),  INT32_C(   454408210),
         INT32_C(   897578103), -INT32_C(   889630600), -INT32_C(  1967153343), -INT32_C(   178018736), -INT32_C(   391913320),  INT32_C(    90686361),  INT32_C(  1217749046), -INT32_C(  1872516584) },
       INT32_C(         159),
      {     -SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     1.57),
        SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(  -752.38), SIMDE_FLOAT32_C(    89.42),
                   SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   683.59),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -1.00) } },
    { { SIMDE_FLOAT32_C(  -968.37), SIMDE_FLOAT32_C(   862.12), SIMDE_FLOAT32_C(   -32.24), SIMDE_FLOAT32_C(  -736.47),
        SIMDE_FLOAT32_C(  -397.51), SIMDE_FLOAT32_C(   215.37), SIMDE_FLOAT32_C(  -834.04), SIMDE_FLOAT32_C(    94.48),
        SIMDE_FLOAT32_C(  -134.80), SIMDE_FLOAT32_C(   397.86), SIMDE_FLOAT32_C(   814.81), SIMDE_FLOAT32_C(   171.35),
        SIMDE_FLOAT32_C(    81.45), SIMDE_FLOAT32_C(   -55.05), SIMDE_FLOAT32_C(  -535.13), SIMDE_FLOAT32_C(   991.98) },
      { SIMDE_FLOAT32_C(     9.98), SIMDE_FLOAT32_C(  -501.94), SIMDE_FLOAT32_C(   197.13), SIMDE_FLOAT32_C(  -469.04),
        SIMDE_FLOAT32_C(  -117.11), SIMDE_FLOAT32_C(  -839.83), SIMDE_FLOAT32_C(   620.38), SIMDE_FLOAT32_C(  -849.95),
        SIMDE_FLOAT32_C(   875.07), SIMDE_FLOAT32_C(  -192.79), SIMDE_FLOAT32_C(    40.82), SIMDE_FLOAT32_C(  -651.39),
        SIMDE_FLOAT32_C(  -227.88), SIMDE_FLOAT32_C(  -341.78), SIMDE_FLOAT32_C(  -743.31), SIMDE_FLOAT32_C(  -196.25) },
      {  INT32_C(  1960951603), -INT32_C(  1358978978), -INT32_C(   559717818), -INT32_C(   607762622),  INT32_C(  1088433418), -INT32_C(  1501006195), -INT32_C(  1086919648),  INT32_C(    47643599),
         INT32_C(   427276218), -INT32_C(  1647872425),  INT32_C(   461073368), -INT32_C(  1124711758), -INT32_C(    33695889),  INT32_C(  1839433037),  INT32_C(  1076746609), -INT32_C(  1891433516) },
       INT32_C(         187),
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     0.50),
        SIMDE_FLOAT32_C(  -397.51),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.50),            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(   875.07), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(    40.82), SIMDE_FLOAT32_C(    90.00),
        SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(  -535.13), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00) } },
    { { SIMDE_FLOAT32_C(  -479.66), SIMDE_FLOAT32_C(   224.45), SIMDE_FLOAT32_C(    67.28), SIMDE_FLOAT32_C(   122.84),
        SIMDE_FLOAT32_C(  -560.17), SIMDE_FLOAT32_C(   233.24), SIMDE_FLOAT32_C(  -782.68), SIMDE_FLOAT32_C(   305.03),
        SIMDE_FLOAT32_C(  -368.90), SIMDE_FLOAT32_C(  -967.87), SIMDE_FLOAT32_C(  -523.62), SIMDE_FLOAT32_C(   712.56),
        SIMDE_FLOAT32_C(   -22.92), SIMDE_FLOAT32_C(   -58.75), SIMDE_FLOAT32_C(   704.53), SIMDE_FLOAT32_C(   987.07) },
      { SIMDE_FLOAT32_C(   439.31), SIMDE_FLOAT32_C(   -98.34), SIMDE_FLOAT32_C(  -481.97), SIMDE_FLOAT32_C(  -677.80),
        SIMDE_FLOAT32_C(    61.83), SIMDE_FLOAT32_C(  -861.59), SIMDE_FLOAT32_C(  -527.75), SIMDE_FLOAT32_C(   -63.10),
        SIMDE_FLOAT32_C(   -54.38), SIMDE_FLOAT32_C(   513.07), SIMDE_FLOAT32_C(   285.51), SIMDE_FLOAT32_C(   717.74),
        SIMDE_FLOAT32_C(  -828.70), SIMDE_FLOAT32_C(   542.20), SIMDE_FLOAT32_C(  -478.51), SIMDE_FLOAT32_C(  -308.36) },
      {  INT32_C(   145780528), -INT32_C(  1943852070), -INT32_C(   582411667),  INT32_C(  1054492401),  INT32_C(  1034649035),  INT32_C(   712890454), -INT32_C(  1749434148), -INT32_C(  1431740038),
        -INT32_C(  1414309423), -INT32_C(   231156091), -INT32_C(   506494480), -INT32_C(  1843418681),  INT32_C(  2093992742),  INT32_C(  2141670819), -INT32_C(  2011799539), -INT32_C(  1825390398) },
       INT32_C(          25),
      { SIMDE_FLOAT32_C(  -479.66), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),
                   SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     1.00),
        SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    -1.00),
        SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF } },
    { { SIMDE_FLOAT32_C(  -233.35), SIMDE_FLOAT32_C(   588.76), SIMDE_FLOAT32_C(   814.48), SIMDE_FLOAT32_C(   206.48),
        SIMDE_FLOAT32_C(  -178.00), SIMDE_FLOAT32_C(  -968.20), SIMDE_FLOAT32_C(  -488.50), SIMDE_FLOAT32_C(   453.11),
        SIMDE_FLOAT32_C(  -936.07), SIMDE_FLOAT32_C(   -12.11), SIMDE_FLOAT32_C(   165.66), SIMDE_FLOAT32_C(    41.01),
        SIMDE_FLOAT32_C(   929.14), SIMDE_FLOAT32_C(  -129.81), SIMDE_FLOAT32_C(    28.08), SIMDE_FLOAT32_C(   368.44) },
      { SIMDE_FLOAT32_C(   771.86), SIMDE_FLOAT32_C(   546.10), SIMDE_FLOAT32_C(   690.64), SIMDE_FLOAT32_C(  -166.31),
        SIMDE_FLOAT32_C(   684.51), SIMDE_FLOAT32_C(  -837.11), SIMDE_FLOAT32_C(   770.59), SIMDE_FLOAT32_C(  -369.87),
        SIMDE_FLOAT32_C(   675.97), SIMDE_FLOAT32_C(    56.10), SIMDE_FLOAT32_C(  -652.14), SIMDE_FLOAT32_C(   847.26),
        SIMDE_FLOAT32_C(  -401.70), SIMDE_FLOAT32_C(  -130.65), SIMDE_FLOAT32_C(  -461.10), SIMDE_FLOAT32_C(   364.95) },
      { -INT32_C(  1399753028), -INT32_C(  1097965321),  INT32_C(   810659082),  INT32_C(   481108088),  INT32_C(  2073777261),  INT32_C(  1979953844), -INT32_C(  1962330766), -INT32_C(   685094885),
        -INT32_C(  1232880706),  INT32_C(   628363547),  INT32_C(   928433599),  INT32_C(  1397949414),  INT32_C(   198111063),  INT32_C(   327340449),  INT32_C(   580815623), -INT32_C(  1829123885) },
       INT32_C(         131),
      { SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.50),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    90.00),
        SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.50),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.50),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -1.00) } },
  };

  simde__m512 a, b, r;
  simde__m512i c;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  b = simde_mm512_loadu_ps(test_vec[0].b);
  c = simde_mm512_loadu_epi32(test_vec[0].c);
  r = simde_mm512_fixupimm_ps(a, b, c, INT32_C(          60));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  b = simde_mm512_loadu_ps(test_vec[1].b);
  c = simde_mm512_loadu_epi32(test_vec[1].c);
  r = simde_mm512_fixupimm_ps(a, b, c, INT32_C(         143));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  b = simde_mm512_loadu_ps(test_vec[2].b);
  c = simde_mm512_loadu_epi32(test_vec[2].c);
  r = simde_mm512_fixupimm_ps(a, b, c, INT32_C(         133));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  b = simde_mm512_loadu_ps(test_vec[3].b);
  c = simde_mm512_loadu_epi32(test_vec[3].c);
  r = simde_mm512_fixupimm_ps(a, b, c, INT32_C(          36));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  b = simde_mm512_loadu_ps(test_vec[4].b);
  c = simde_mm512_loadu_epi32(test_vec[4].c);
  r = simde_mm512_fixupimm_ps(a, b, c, INT32_C(         159));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  b = simde_mm512_loadu_ps(test_vec[5].b);
  c = simde_mm512_loadu_epi32(test_vec[5].c);
  r = simde_mm512_fixupimm_ps(a, b, c, INT32_C(         187));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  b = simde_mm512_loadu_ps(test_vec[6].b);
  c = simde_mm512_loadu_epi32(test_vec[6].c);
  r = simde_mm512_fixupimm_ps(a, b, c, INT32_C(          25));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  b = simde_mm512_loadu_ps(test_vec[7].b);
  c = simde_mm512_loadu_epi32(test_vec[7].c);
  r = simde_mm512_fixupimm_ps(a, b, c, INT32_C(         131));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_f32x16_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_extract_f32x16(i, 2, 0, values);
    simde__m512 b = simde_test_x86_random_extract_f32x16(i, 2, 1, values);
    simde__m512i c = simde_test_x86_random_i32x16();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512 r;
    SIMDE_CONSTIFY_256_(simde_mm512_fixupimm_ps, r, simde_mm512_setzero_ps(), imm8, a, b, c);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  fprintf(stderr, "-------------------------\n------------------------\n----------------------\n");
  return 1;
#endif
}

static int
test_simde_mm512_mask_fixupimm_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde__mmask16 k;
    const simde_float32 b[16];
    const int32_t c[16];
    const int imm8;
    const simde_float32 r[16];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    11.52),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   929.69),
        SIMDE_FLOAT32_C(  -164.22), SIMDE_FLOAT32_C(  -671.22), SIMDE_FLOAT32_C(  -338.31), SIMDE_FLOAT32_C(  -943.38),
        SIMDE_FLOAT32_C(  -204.60), SIMDE_FLOAT32_C(  -242.41), SIMDE_FLOAT32_C(  -153.78), SIMDE_FLOAT32_C(  -370.59),
        SIMDE_FLOAT32_C(  -911.93), SIMDE_FLOAT32_C(   185.86), SIMDE_FLOAT32_C(   977.68), SIMDE_FLOAT32_C(  -572.82) },
      UINT16_C(21745),
      { SIMDE_FLOAT32_C(   601.56),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   151.49),
        SIMDE_FLOAT32_C(  -526.97), SIMDE_FLOAT32_C(   665.42), SIMDE_FLOAT32_C(  -228.74), SIMDE_FLOAT32_C(  -432.59),
        SIMDE_FLOAT32_C(  -861.10), SIMDE_FLOAT32_C(   937.48), SIMDE_FLOAT32_C(  -213.33), SIMDE_FLOAT32_C(    83.67),
        SIMDE_FLOAT32_C(   -69.75), SIMDE_FLOAT32_C(  -946.87), SIMDE_FLOAT32_C(   372.84), SIMDE_FLOAT32_C(   140.85) },
      {  INT32_C(   313384799),  INT32_C(  1572283312),  INT32_C(  1410692939), -INT32_C(   479587817), -INT32_C(   648402442), -INT32_C(   989262257),  INT32_C(  1641939429),  INT32_C(  1739968520),
         INT32_C(  1601790639), -INT32_C(   792972923), -INT32_C(  1071328600), -INT32_C(   610038044),  INT32_C(   129301943), -INT32_C(   238240500), -INT32_C(   950883649),  INT32_C(   690882426) },
       INT32_C(         105),
      { SIMDE_FLOAT32_C(   601.56), SIMDE_FLOAT32_C(    11.52),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   929.69),
        SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(  -228.74), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(  -204.60), SIMDE_FLOAT32_C(  -242.41), SIMDE_FLOAT32_C(  -153.78), SIMDE_FLOAT32_C(  -370.59),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   185.86), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(  -572.82) } },
    { { SIMDE_FLOAT32_C(    64.65), SIMDE_FLOAT32_C(   971.39), SIMDE_FLOAT32_C(    70.55), SIMDE_FLOAT32_C(   900.43),
        SIMDE_FLOAT32_C(  -699.83), SIMDE_FLOAT32_C(   732.23), SIMDE_FLOAT32_C(   957.05), SIMDE_FLOAT32_C(    95.57),
        SIMDE_FLOAT32_C(  -510.17), SIMDE_FLOAT32_C(  -196.74), SIMDE_FLOAT32_C(   724.98), SIMDE_FLOAT32_C(  -422.10),
        SIMDE_FLOAT32_C(   989.12), SIMDE_FLOAT32_C(   702.66), SIMDE_FLOAT32_C(     5.08), SIMDE_FLOAT32_C(   590.68) },
      UINT16_C(17880),
      { SIMDE_FLOAT32_C(     6.22), SIMDE_FLOAT32_C(  -183.08), SIMDE_FLOAT32_C(  -257.83), SIMDE_FLOAT32_C(   479.25),
        SIMDE_FLOAT32_C(  -517.66), SIMDE_FLOAT32_C(   513.43), SIMDE_FLOAT32_C(  -953.35), SIMDE_FLOAT32_C(  -378.76),
        SIMDE_FLOAT32_C(   450.92), SIMDE_FLOAT32_C(  -166.68), SIMDE_FLOAT32_C(   704.91), SIMDE_FLOAT32_C(  -618.84),
        SIMDE_FLOAT32_C(  -113.55), SIMDE_FLOAT32_C(    77.75), SIMDE_FLOAT32_C(   522.02), SIMDE_FLOAT32_C(   951.10) },
      { -INT32_C(   484998722), -INT32_C(   462291903), -INT32_C(  1948177961), -INT32_C(    62264016),  INT32_C(   816187614), -INT32_C(    46718513), -INT32_C(   744185782),  INT32_C(  1293516174),
         INT32_C(  1060122878),  INT32_C(    52666668), -INT32_C(    91290422), -INT32_C(   789128974), -INT32_C(  1358848544),  INT32_C(   145504446),  INT32_C(  1742491865), -INT32_C(   877333043) },
       INT32_C(          37),
      { SIMDE_FLOAT32_C(    64.65), SIMDE_FLOAT32_C(   971.39), SIMDE_FLOAT32_C(    70.55), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),
        SIMDE_FLOAT32_C(  -699.83), SIMDE_FLOAT32_C(   732.23),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.57),
                   SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -196.74), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(  -422.10),
        SIMDE_FLOAT32_C(   989.12), SIMDE_FLOAT32_C(   702.66),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   590.68) } },
    { { SIMDE_FLOAT32_C(    49.15), SIMDE_FLOAT32_C(  -407.44), SIMDE_FLOAT32_C(   851.52), SIMDE_FLOAT32_C(   349.32),
        SIMDE_FLOAT32_C(  -675.20), SIMDE_FLOAT32_C(   808.57), SIMDE_FLOAT32_C(  -555.11), SIMDE_FLOAT32_C(  -185.38),
        SIMDE_FLOAT32_C(  -388.17), SIMDE_FLOAT32_C(  -830.13), SIMDE_FLOAT32_C(   392.52), SIMDE_FLOAT32_C(  -399.05),
        SIMDE_FLOAT32_C(   872.53), SIMDE_FLOAT32_C(  -602.39), SIMDE_FLOAT32_C(  -808.37), SIMDE_FLOAT32_C(  -121.25) },
      UINT16_C(11654),
      { SIMDE_FLOAT32_C(   214.53), SIMDE_FLOAT32_C(   -66.21), SIMDE_FLOAT32_C(  -642.00), SIMDE_FLOAT32_C(   696.86),
        SIMDE_FLOAT32_C(  -552.78), SIMDE_FLOAT32_C(  -595.35), SIMDE_FLOAT32_C(  -681.90), SIMDE_FLOAT32_C(   898.14),
        SIMDE_FLOAT32_C(   237.97), SIMDE_FLOAT32_C(  -976.99), SIMDE_FLOAT32_C(  -720.70), SIMDE_FLOAT32_C(  -875.58),
        SIMDE_FLOAT32_C(   100.77), SIMDE_FLOAT32_C(   801.32), SIMDE_FLOAT32_C(  -924.49), SIMDE_FLOAT32_C(  -850.08) },
      { -INT32_C(   466464683),  INT32_C(  1102849099), -INT32_C(   169960204), -INT32_C(   147940277), -INT32_C(  2125985883),  INT32_C(   594941294), -INT32_C(   351822879),  INT32_C(  1125748205),
         INT32_C(   690441182),  INT32_C(  1667949679), -INT32_C(   866563712), -INT32_C(  1966897179), -INT32_C(    66385010),  INT32_C(    35619105),  INT32_C(   183314205), -INT32_C(  1840445772) },
       INT32_C(          81),
      { SIMDE_FLOAT32_C(    49.15), SIMDE_FLOAT32_C(   -66.21),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   349.32),
        SIMDE_FLOAT32_C(  -675.20), SIMDE_FLOAT32_C(   808.57), SIMDE_FLOAT32_C(  -555.11),     -SIMDE_MATH_INFINITYF,
                   SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -830.13), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     1.00),
        SIMDE_FLOAT32_C(   872.53), SIMDE_FLOAT32_C(  -602.39), SIMDE_FLOAT32_C(  -808.37), SIMDE_FLOAT32_C(  -121.25) } },
    { { SIMDE_FLOAT32_C(  -606.12), SIMDE_FLOAT32_C(   927.04), SIMDE_FLOAT32_C(   499.24), SIMDE_FLOAT32_C(  -281.33),
        SIMDE_FLOAT32_C(   735.61), SIMDE_FLOAT32_C(   944.13), SIMDE_FLOAT32_C(   533.30), SIMDE_FLOAT32_C(  -652.56),
        SIMDE_FLOAT32_C(  -886.00), SIMDE_FLOAT32_C(   -74.18), SIMDE_FLOAT32_C(   -51.61), SIMDE_FLOAT32_C(   986.53),
        SIMDE_FLOAT32_C(   323.43), SIMDE_FLOAT32_C(   140.01), SIMDE_FLOAT32_C(  -134.72), SIMDE_FLOAT32_C(  -462.04) },
      UINT16_C( 9817),
      { SIMDE_FLOAT32_C(  -926.19), SIMDE_FLOAT32_C(   223.28), SIMDE_FLOAT32_C(  -765.18), SIMDE_FLOAT32_C(  -478.97),
        SIMDE_FLOAT32_C(   627.93), SIMDE_FLOAT32_C(  -447.08), SIMDE_FLOAT32_C(  -580.83), SIMDE_FLOAT32_C(  -134.10),
        SIMDE_FLOAT32_C(  -424.06), SIMDE_FLOAT32_C(  -301.53), SIMDE_FLOAT32_C(    -9.68), SIMDE_FLOAT32_C(   676.71),
        SIMDE_FLOAT32_C(  -500.22), SIMDE_FLOAT32_C(    65.83), SIMDE_FLOAT32_C(   826.62), SIMDE_FLOAT32_C(  -106.34) },
      {  INT32_C(  2104482084),  INT32_C(  1761891493), -INT32_C(   361458977), -INT32_C(  1368615538), -INT32_C(  2049603177), -INT32_C(   510948973), -INT32_C(   682173156), -INT32_C(  1040339043),
         INT32_C(   775842952), -INT32_C(  1600699711),  INT32_C(  1669991380),  INT32_C(   940701345),  INT32_C(   331212415), -INT32_C(  1946924689), -INT32_C(  1016903130), -INT32_C(  2121965319) },
       INT32_C(         205),
      { SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(   927.04), SIMDE_FLOAT32_C(   499.24), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   944.13), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(  -652.56),
        SIMDE_FLOAT32_C(  -886.00), SIMDE_FLOAT32_C(   -74.18),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   986.53),
        SIMDE_FLOAT32_C(   323.43), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -134.72), SIMDE_FLOAT32_C(  -462.04) } },
    { { SIMDE_FLOAT32_C(    -7.13), SIMDE_FLOAT32_C(   325.86), SIMDE_FLOAT32_C(   612.34), SIMDE_FLOAT32_C(  -271.52),
        SIMDE_FLOAT32_C(   269.99), SIMDE_FLOAT32_C(   145.64), SIMDE_FLOAT32_C(    75.91), SIMDE_FLOAT32_C(   383.99),
        SIMDE_FLOAT32_C(  -928.54), SIMDE_FLOAT32_C(  -975.70), SIMDE_FLOAT32_C(   370.52), SIMDE_FLOAT32_C(   394.89),
        SIMDE_FLOAT32_C(   164.31), SIMDE_FLOAT32_C(  -764.19), SIMDE_FLOAT32_C(   932.84), SIMDE_FLOAT32_C(   238.12) },
      UINT16_C(17926),
      { SIMDE_FLOAT32_C(   459.08), SIMDE_FLOAT32_C(  -832.34), SIMDE_FLOAT32_C(   759.15), SIMDE_FLOAT32_C(    87.01),
        SIMDE_FLOAT32_C(  -279.41), SIMDE_FLOAT32_C(  -821.69), SIMDE_FLOAT32_C(   952.91), SIMDE_FLOAT32_C(   296.52),
        SIMDE_FLOAT32_C(  -123.22), SIMDE_FLOAT32_C(   -56.77), SIMDE_FLOAT32_C(   -26.77), SIMDE_FLOAT32_C(   376.57),
        SIMDE_FLOAT32_C(  -990.93), SIMDE_FLOAT32_C(  -200.15), SIMDE_FLOAT32_C(  -729.77), SIMDE_FLOAT32_C(     1.94) },
      { -INT32_C(  1202529746),  INT32_C(  1320153917), -INT32_C(   382456277),  INT32_C(   892511297), -INT32_C(  1837148113), -INT32_C(  1594656741), -INT32_C(  1453014790),  INT32_C(  2096130638),
        -INT32_C(  2110504380),  INT32_C(  1624302389),  INT32_C(  1397294354), -INT32_C(   662078551), -INT32_C(   278198061),  INT32_C(  2072993409),  INT32_C(  1814360862), -INT32_C(  1561848739) },
       INT32_C(          86),
      { SIMDE_FLOAT32_C(    -7.13), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(  -271.52),
        SIMDE_FLOAT32_C(   269.99), SIMDE_FLOAT32_C(   145.64), SIMDE_FLOAT32_C(    75.91), SIMDE_FLOAT32_C(   383.99),
        SIMDE_FLOAT32_C(  -928.54), SIMDE_FLOAT32_C(  -975.70),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   394.89),
        SIMDE_FLOAT32_C(   164.31), SIMDE_FLOAT32_C(  -764.19), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(   238.12) } },
    { { SIMDE_FLOAT32_C(  -874.29), SIMDE_FLOAT32_C(   882.57), SIMDE_FLOAT32_C(   730.42), SIMDE_FLOAT32_C(   395.70),
        SIMDE_FLOAT32_C(    28.20), SIMDE_FLOAT32_C(  -193.67), SIMDE_FLOAT32_C(  -220.31), SIMDE_FLOAT32_C(    99.66),
        SIMDE_FLOAT32_C(  -169.37), SIMDE_FLOAT32_C(  -849.78), SIMDE_FLOAT32_C(  -505.45), SIMDE_FLOAT32_C(   994.95),
        SIMDE_FLOAT32_C(  -613.98), SIMDE_FLOAT32_C(  -572.60), SIMDE_FLOAT32_C(   233.07), SIMDE_FLOAT32_C(   845.11) },
      UINT16_C(62464),
      { SIMDE_FLOAT32_C(  -404.94), SIMDE_FLOAT32_C(    -7.79), SIMDE_FLOAT32_C(   -67.88), SIMDE_FLOAT32_C(   315.64),
        SIMDE_FLOAT32_C(   170.53), SIMDE_FLOAT32_C(  -114.97), SIMDE_FLOAT32_C(  -387.83), SIMDE_FLOAT32_C(  -952.69),
        SIMDE_FLOAT32_C(   828.26), SIMDE_FLOAT32_C(   585.39), SIMDE_FLOAT32_C(   423.88), SIMDE_FLOAT32_C(   837.33),
        SIMDE_FLOAT32_C(  -614.76), SIMDE_FLOAT32_C(   694.11), SIMDE_FLOAT32_C(  -160.73), SIMDE_FLOAT32_C(  -489.05) },
      {  INT32_C(   905515756), -INT32_C(   290348443), -INT32_C(   419986309),  INT32_C(    54818931),  INT32_C(   402023155), -INT32_C(  1238608690),  INT32_C(   450003702), -INT32_C(    99692018),
         INT32_C(  1244596452),  INT32_C(   624484522), -INT32_C(   670355611), -INT32_C(  1696903257),  INT32_C(  2142425777),  INT32_C(   473292326),  INT32_C(  1849034848), -INT32_C(  1083685670) },
       INT32_C(          76),
      { SIMDE_FLOAT32_C(  -874.29), SIMDE_FLOAT32_C(   882.57), SIMDE_FLOAT32_C(   730.42), SIMDE_FLOAT32_C(   395.70),
        SIMDE_FLOAT32_C(    28.20), SIMDE_FLOAT32_C(  -193.67), SIMDE_FLOAT32_C(  -220.31), SIMDE_FLOAT32_C(    99.66),
        SIMDE_FLOAT32_C(  -169.37), SIMDE_FLOAT32_C(  -849.78), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(   994.95),
        SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(   694.11), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00) } },
    { { SIMDE_FLOAT32_C(   576.67), SIMDE_FLOAT32_C(  -430.32), SIMDE_FLOAT32_C(   906.65), SIMDE_FLOAT32_C(  -395.12),
        SIMDE_FLOAT32_C(   376.01), SIMDE_FLOAT32_C(  -313.66), SIMDE_FLOAT32_C(   704.54), SIMDE_FLOAT32_C(  -793.36),
        SIMDE_FLOAT32_C(  -163.44), SIMDE_FLOAT32_C(  -800.91), SIMDE_FLOAT32_C(  -798.41), SIMDE_FLOAT32_C(   222.58),
        SIMDE_FLOAT32_C(  -373.52), SIMDE_FLOAT32_C(   434.65), SIMDE_FLOAT32_C(    67.68), SIMDE_FLOAT32_C(   221.54) },
      UINT16_C(16760),
      { SIMDE_FLOAT32_C(  -573.13), SIMDE_FLOAT32_C(   999.80), SIMDE_FLOAT32_C(  -462.82), SIMDE_FLOAT32_C(   597.40),
        SIMDE_FLOAT32_C(  -115.17), SIMDE_FLOAT32_C(   149.35), SIMDE_FLOAT32_C(   644.71), SIMDE_FLOAT32_C(  -286.90),
        SIMDE_FLOAT32_C(  -265.26), SIMDE_FLOAT32_C(    68.58), SIMDE_FLOAT32_C(  -449.57), SIMDE_FLOAT32_C(   119.98),
        SIMDE_FLOAT32_C(  -237.31), SIMDE_FLOAT32_C(   389.69), SIMDE_FLOAT32_C(   630.93), SIMDE_FLOAT32_C(  -660.64) },
      {  INT32_C(   678550812), -INT32_C(  1854465866),  INT32_C(  1700997555), -INT32_C(   565999192), -INT32_C(   605641819),  INT32_C(  2048966674), -INT32_C(  2012058497), -INT32_C(  2134209693),
         INT32_C(   514341736),  INT32_C(   112205651), -INT32_C(   244640952),  INT32_C(  1120906909),  INT32_C(  1679734098), -INT32_C(   169984395),  INT32_C(   243134890), -INT32_C(   460437636) },
       INT32_C(         130),
      { SIMDE_FLOAT32_C(   576.67), SIMDE_FLOAT32_C(  -430.32), SIMDE_FLOAT32_C(   906.65), SIMDE_FLOAT32_C(     1.57),
        SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -793.36),
        SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(  -800.91), SIMDE_FLOAT32_C(  -798.41), SIMDE_FLOAT32_C(   222.58),
        SIMDE_FLOAT32_C(  -373.52), SIMDE_FLOAT32_C(   434.65), SIMDE_FLOAT32_C(    67.68), SIMDE_FLOAT32_C(   221.54) } },
    { { SIMDE_FLOAT32_C(   959.37), SIMDE_FLOAT32_C(   537.58), SIMDE_FLOAT32_C(   -55.76), SIMDE_FLOAT32_C(   335.39),
        SIMDE_FLOAT32_C(  -776.08), SIMDE_FLOAT32_C(  -351.23), SIMDE_FLOAT32_C(   542.03), SIMDE_FLOAT32_C(    60.48),
        SIMDE_FLOAT32_C(  -152.14), SIMDE_FLOAT32_C(   743.62), SIMDE_FLOAT32_C(  -716.94), SIMDE_FLOAT32_C(   474.34),
        SIMDE_FLOAT32_C(   178.27), SIMDE_FLOAT32_C(   350.74), SIMDE_FLOAT32_C(  -304.11), SIMDE_FLOAT32_C(   605.14) },
      UINT16_C(45909),
      { SIMDE_FLOAT32_C(   350.54), SIMDE_FLOAT32_C(   233.07), SIMDE_FLOAT32_C(   202.54), SIMDE_FLOAT32_C(  -764.62),
        SIMDE_FLOAT32_C(  -617.58), SIMDE_FLOAT32_C(  -152.76), SIMDE_FLOAT32_C(   -51.53), SIMDE_FLOAT32_C(   117.16),
        SIMDE_FLOAT32_C(   915.82), SIMDE_FLOAT32_C(   498.90), SIMDE_FLOAT32_C(  -762.86), SIMDE_FLOAT32_C(  -321.49),
        SIMDE_FLOAT32_C(  -111.41), SIMDE_FLOAT32_C(   868.08), SIMDE_FLOAT32_C(    17.87), SIMDE_FLOAT32_C(  -152.03) },
      {  INT32_C(  1220976348),  INT32_C(  1593205647), -INT32_C(  1005369178), -INT32_C(  1962768212), -INT32_C(    75715459),  INT32_C(  1212348602), -INT32_C(   545339940),  INT32_C(  2006111387),
         INT32_C(    29317490),  INT32_C(  1650439868), -INT32_C(  1423543554),  INT32_C(  2016815354), -INT32_C(  1888242987), -INT32_C(  2032618070),  INT32_C(   359028346), -INT32_C(  1668417494) },
       INT32_C(          81),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   537.58), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(   335.39),
        SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(  -351.23), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    60.48),
        SIMDE_FLOAT32_C(  -152.14),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -716.94), SIMDE_FLOAT32_C(   474.34),
        SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -304.11), SIMDE_FLOAT32_C(    90.00) } },
  };

  simde__m512 a, b, r;
  simde__m512i c;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  b = simde_mm512_loadu_ps(test_vec[0].b);
  c = simde_mm512_loadu_epi32(test_vec[0].c);
  r = simde_mm512_mask_fixupimm_ps(a, test_vec[0].k, b, c, INT32_C(         105));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  b = simde_mm512_loadu_ps(test_vec[1].b);
  c = simde_mm512_loadu_epi32(test_vec[1].c);
  r = simde_mm512_mask_fixupimm_ps(a, test_vec[1].k, b, c, INT32_C(          37));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  b = simde_mm512_loadu_ps(test_vec[2].b);
  c = simde_mm512_loadu_epi32(test_vec[2].c);
  r = simde_mm512_mask_fixupimm_ps(a, test_vec[2].k, b, c, INT32_C(          81));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  b = simde_mm512_loadu_ps(test_vec[3].b);
  c = simde_mm512_loadu_epi32(test_vec[3].c);
  r = simde_mm512_mask_fixupimm_ps(a, test_vec[3].k, b, c, INT32_C(         205));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  b = simde_mm512_loadu_ps(test_vec[4].b);
  c = simde_mm512_loadu_epi32(test_vec[4].c);
  r = simde_mm512_mask_fixupimm_ps(a, test_vec[4].k, b, c, INT32_C(          86));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  b = simde_mm512_loadu_ps(test_vec[5].b);
  c = simde_mm512_loadu_epi32(test_vec[5].c);
  r = simde_mm512_mask_fixupimm_ps(a, test_vec[5].k, b, c, INT32_C(          76));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  b = simde_mm512_loadu_ps(test_vec[6].b);
  c = simde_mm512_loadu_epi32(test_vec[6].c);
  r = simde_mm512_mask_fixupimm_ps(a, test_vec[6].k, b, c, INT32_C(         130));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  b = simde_mm512_loadu_ps(test_vec[7].b);
  c = simde_mm512_loadu_epi32(test_vec[7].c);
  r = simde_mm512_mask_fixupimm_ps(a, test_vec[7].k, b, c, INT32_C(          81));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_f32x16_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_extract_f32x16(i, 2, 0, values);
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 b = simde_test_x86_random_extract_f32x16(i, 2, 1, values);
    simde__m512i c = simde_test_x86_random_i32x16();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512 r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_fixupimm_ps, r, simde_mm512_setzero_ps(), imm8, a, k, b, c);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  fprintf(stderr, "-------------------------\n------------------------\n----------------------\n");
  return 1;
#endif
}

static int
test_simde_mm512_maskz_fixupimm_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 b[16];
    const int32_t c[16];
    const int imm8;
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C( 4530),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -915.59),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -611.87),
        SIMDE_FLOAT32_C(   972.93), SIMDE_FLOAT32_C(  -368.90), SIMDE_FLOAT32_C(   180.66), SIMDE_FLOAT32_C(   295.65),
        SIMDE_FLOAT32_C(  -338.99), SIMDE_FLOAT32_C(  -384.12), SIMDE_FLOAT32_C(  -256.69), SIMDE_FLOAT32_C(  -116.90),
        SIMDE_FLOAT32_C(   336.00), SIMDE_FLOAT32_C(   767.24), SIMDE_FLOAT32_C(   339.49), SIMDE_FLOAT32_C(  -776.36) },
      { SIMDE_FLOAT32_C(   426.32),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   200.37),
        SIMDE_FLOAT32_C(   186.37), SIMDE_FLOAT32_C(   203.64), SIMDE_FLOAT32_C(  -405.80), SIMDE_FLOAT32_C(   404.64),
        SIMDE_FLOAT32_C(   860.07), SIMDE_FLOAT32_C(   721.39), SIMDE_FLOAT32_C(  -837.45), SIMDE_FLOAT32_C(    -5.34),
        SIMDE_FLOAT32_C(   413.01), SIMDE_FLOAT32_C(  -154.92), SIMDE_FLOAT32_C(  -941.34), SIMDE_FLOAT32_C(  -275.03) },
      { -INT32_C(   156968499),  INT32_C(   704587896), -INT32_C(  2049974577),  INT32_C(   866252229), -INT32_C(   574602056),  INT32_C(  1633063746),  INT32_C(  2001845234),  INT32_C(  1971848104),
         INT32_C(  1416310236),  INT32_C(   612264533),  INT32_C(   246041929), -INT32_C(    79541438), -INT32_C(   774372721), -INT32_C(  2009976938), -INT32_C(  1828748310),  INT32_C(  1661438087) },
       INT32_C(         181),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     1.57),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(14045),
      { SIMDE_FLOAT32_C(   -70.51), SIMDE_FLOAT32_C(  -358.94), SIMDE_FLOAT32_C(   113.10), SIMDE_FLOAT32_C(   -97.59),
        SIMDE_FLOAT32_C(   272.16), SIMDE_FLOAT32_C(  -706.25), SIMDE_FLOAT32_C(  -801.94), SIMDE_FLOAT32_C(   933.18),
        SIMDE_FLOAT32_C(   -90.36), SIMDE_FLOAT32_C(   -58.63), SIMDE_FLOAT32_C(  -183.72), SIMDE_FLOAT32_C(  -754.36),
        SIMDE_FLOAT32_C(  -291.39), SIMDE_FLOAT32_C(  -844.23), SIMDE_FLOAT32_C(  -530.72), SIMDE_FLOAT32_C(  -865.07) },
      { SIMDE_FLOAT32_C(   -64.89), SIMDE_FLOAT32_C(  -143.98), SIMDE_FLOAT32_C(   335.30), SIMDE_FLOAT32_C(  -878.52),
        SIMDE_FLOAT32_C(  -940.34), SIMDE_FLOAT32_C(   929.50), SIMDE_FLOAT32_C(   526.12), SIMDE_FLOAT32_C(   919.74),
        SIMDE_FLOAT32_C(   650.89), SIMDE_FLOAT32_C(   688.67), SIMDE_FLOAT32_C(   -85.61), SIMDE_FLOAT32_C(    63.90),
        SIMDE_FLOAT32_C(  -466.25), SIMDE_FLOAT32_C(   -26.95), SIMDE_FLOAT32_C(   788.87), SIMDE_FLOAT32_C(   463.23) },
      { -INT32_C(   662493650),  INT32_C(  1998833205), -INT32_C(  1720077631), -INT32_C(  1245180029), -INT32_C(  1757826409),  INT32_C(  1277149252), -INT32_C(   608185309),  INT32_C(   202480862),
        -INT32_C(   119171645),  INT32_C(   477038683),  INT32_C(  1052108987), -INT32_C(  1879802120),  INT32_C(  1965436208),  INT32_C(   281101805), -INT32_C(   135495655), -INT32_C(   553321188) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -1.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(   933.18),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   688.67), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     0.00),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -844.23), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(18161),
      { SIMDE_FLOAT32_C(   614.11), SIMDE_FLOAT32_C(   -98.04), SIMDE_FLOAT32_C(  -634.35), SIMDE_FLOAT32_C(  -113.73),
        SIMDE_FLOAT32_C(   195.71), SIMDE_FLOAT32_C(  -436.29), SIMDE_FLOAT32_C(  -180.56), SIMDE_FLOAT32_C(  -894.65),
        SIMDE_FLOAT32_C(   505.08), SIMDE_FLOAT32_C(   635.72), SIMDE_FLOAT32_C(  -649.01), SIMDE_FLOAT32_C(  -786.31),
        SIMDE_FLOAT32_C(   791.49), SIMDE_FLOAT32_C(  -179.73), SIMDE_FLOAT32_C(  -651.38), SIMDE_FLOAT32_C(  -273.39) },
      { SIMDE_FLOAT32_C(   676.29), SIMDE_FLOAT32_C(   683.92), SIMDE_FLOAT32_C(  -151.91), SIMDE_FLOAT32_C(   735.95),
        SIMDE_FLOAT32_C(   613.41), SIMDE_FLOAT32_C(  -625.79), SIMDE_FLOAT32_C(   655.69), SIMDE_FLOAT32_C(   264.30),
        SIMDE_FLOAT32_C(  -937.12), SIMDE_FLOAT32_C(  -429.92), SIMDE_FLOAT32_C(  -671.80), SIMDE_FLOAT32_C(  -403.37),
        SIMDE_FLOAT32_C(   543.13), SIMDE_FLOAT32_C(  -882.94), SIMDE_FLOAT32_C(  -940.14), SIMDE_FLOAT32_C(   157.24) },
      { -INT32_C(  1087394807), -INT32_C(   549640213), -INT32_C(   586388042), -INT32_C(  1557988894), -INT32_C(   182240247),  INT32_C(   938688563), -INT32_C(   148863713),  INT32_C(  2084377203),
        -INT32_C(  1455723330),  INT32_C(  1250457747), -INT32_C(   936930074), -INT32_C(  1754510963), -INT32_C(  1181970555), -INT32_C(   269451313),  INT32_C(  2028343557), -INT32_C(   504093917) },
       INT32_C(         144),
      { SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C( 5032),
      { SIMDE_FLOAT32_C(    19.02), SIMDE_FLOAT32_C(  -574.49), SIMDE_FLOAT32_C(  -956.50), SIMDE_FLOAT32_C(  -785.26),
        SIMDE_FLOAT32_C(   -10.78), SIMDE_FLOAT32_C(  -137.05), SIMDE_FLOAT32_C(  -679.91), SIMDE_FLOAT32_C(  -505.71),
        SIMDE_FLOAT32_C(  -501.33), SIMDE_FLOAT32_C(  -328.92), SIMDE_FLOAT32_C(  -292.02), SIMDE_FLOAT32_C(  -709.84),
        SIMDE_FLOAT32_C(   491.34), SIMDE_FLOAT32_C(    56.60), SIMDE_FLOAT32_C(    16.77), SIMDE_FLOAT32_C(   167.63) },
      { SIMDE_FLOAT32_C(  -259.48), SIMDE_FLOAT32_C(   864.86), SIMDE_FLOAT32_C(   -96.41), SIMDE_FLOAT32_C(  -646.07),
        SIMDE_FLOAT32_C(  -760.93), SIMDE_FLOAT32_C(  -440.72), SIMDE_FLOAT32_C(   618.23), SIMDE_FLOAT32_C(  -698.05),
        SIMDE_FLOAT32_C(   129.36), SIMDE_FLOAT32_C(   946.42), SIMDE_FLOAT32_C(  -101.42), SIMDE_FLOAT32_C(  -327.51),
        SIMDE_FLOAT32_C(  -936.52), SIMDE_FLOAT32_C(   -41.56), SIMDE_FLOAT32_C(   829.73), SIMDE_FLOAT32_C(    82.51) },
      { -INT32_C(  1800892819), -INT32_C(  1008847529),  INT32_C(  1498571724),  INT32_C(   232268316), -INT32_C(   148972271),  INT32_C(  1243234645), -INT32_C(  1384469982),  INT32_C(  1002513102),
         INT32_C(   147876273),  INT32_C(  1808510622),  INT32_C(   784604433),  INT32_C(  1346083903), -INT32_C(   817407622), -INT32_C(  1139187046), -INT32_C(   630549748),  INT32_C(  1729506230) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.50),
        SIMDE_FLOAT32_C(  -501.33),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(14996),
      { SIMDE_FLOAT32_C(   383.95), SIMDE_FLOAT32_C(   873.23), SIMDE_FLOAT32_C(   297.25), SIMDE_FLOAT32_C(  -626.83),
        SIMDE_FLOAT32_C(  -263.82), SIMDE_FLOAT32_C(   617.33), SIMDE_FLOAT32_C(  -132.54), SIMDE_FLOAT32_C(   234.85),
        SIMDE_FLOAT32_C(  -711.59), SIMDE_FLOAT32_C(   575.45), SIMDE_FLOAT32_C(   525.01), SIMDE_FLOAT32_C(   779.75),
        SIMDE_FLOAT32_C(  -367.96), SIMDE_FLOAT32_C(  -458.22), SIMDE_FLOAT32_C(   -52.61), SIMDE_FLOAT32_C(   372.56) },
      { SIMDE_FLOAT32_C(  -593.37), SIMDE_FLOAT32_C(   850.97), SIMDE_FLOAT32_C(   726.49), SIMDE_FLOAT32_C(  -354.30),
        SIMDE_FLOAT32_C(  -589.75), SIMDE_FLOAT32_C(   344.72), SIMDE_FLOAT32_C(   -52.35), SIMDE_FLOAT32_C(   539.61),
        SIMDE_FLOAT32_C(   291.14), SIMDE_FLOAT32_C(   846.23), SIMDE_FLOAT32_C(  -787.90), SIMDE_FLOAT32_C(   354.62),
        SIMDE_FLOAT32_C(  -195.33), SIMDE_FLOAT32_C(  -958.17), SIMDE_FLOAT32_C(  -562.87), SIMDE_FLOAT32_C(  -811.37) },
      {  INT32_C(  1633133981),  INT32_C(   251566035),  INT32_C(   795310311),  INT32_C(  1636892999),  INT32_C(   687119806), -INT32_C(  1907119496), -INT32_C(  2139822319), -INT32_C(  1212544999),
        -INT32_C(  2129128787), -INT32_C(  1869670743), -INT32_C(   692062322), -INT32_C(  1237888776),  INT32_C(  1725836270), -INT32_C(   403426858),  INT32_C(   845703192),  INT32_C(   501817968) },
       INT32_C(          52),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.50),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.50),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(11800),
      { SIMDE_FLOAT32_C(   915.06), SIMDE_FLOAT32_C(   734.38), SIMDE_FLOAT32_C(  -438.20), SIMDE_FLOAT32_C(  -348.76),
        SIMDE_FLOAT32_C(   351.71), SIMDE_FLOAT32_C(   429.26), SIMDE_FLOAT32_C(   886.09), SIMDE_FLOAT32_C(   640.12),
        SIMDE_FLOAT32_C(     4.71), SIMDE_FLOAT32_C(   411.10), SIMDE_FLOAT32_C(   419.87), SIMDE_FLOAT32_C(   636.75),
        SIMDE_FLOAT32_C(   952.88), SIMDE_FLOAT32_C(  -632.74), SIMDE_FLOAT32_C(     9.31), SIMDE_FLOAT32_C(  -640.49) },
      { SIMDE_FLOAT32_C(  -781.77), SIMDE_FLOAT32_C(  -264.20), SIMDE_FLOAT32_C(     5.21), SIMDE_FLOAT32_C(  -371.51),
        SIMDE_FLOAT32_C(  -919.48), SIMDE_FLOAT32_C(   952.86), SIMDE_FLOAT32_C(  -831.90), SIMDE_FLOAT32_C(   371.66),
        SIMDE_FLOAT32_C(   799.09), SIMDE_FLOAT32_C(  -619.80), SIMDE_FLOAT32_C(  -273.72), SIMDE_FLOAT32_C(  -396.24),
        SIMDE_FLOAT32_C(  -577.97), SIMDE_FLOAT32_C(   163.41), SIMDE_FLOAT32_C(  -207.61), SIMDE_FLOAT32_C(  -662.91) },
      {  INT32_C(   757442158), -INT32_C(  1283580548), -INT32_C(  1293980460), -INT32_C(   958089774),  INT32_C(    70188188),  INT32_C(   388472366),  INT32_C(  1511611323), -INT32_C(  1484246727),
         INT32_C(  1423224279), -INT32_C(  1643687222), -INT32_C(  1873680706),  INT32_C(   945173915),  INT32_C(  1614578737), -INT32_C(   562601182), -INT32_C(   130510657), -INT32_C(  1717583679) },
       INT32_C(         109),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(   419.87), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(62662),
      { SIMDE_FLOAT32_C(  -102.21), SIMDE_FLOAT32_C(   354.19), SIMDE_FLOAT32_C(   -11.66), SIMDE_FLOAT32_C(  -750.50),
        SIMDE_FLOAT32_C(  -216.55), SIMDE_FLOAT32_C(  -125.57), SIMDE_FLOAT32_C(   889.62), SIMDE_FLOAT32_C(   788.16),
        SIMDE_FLOAT32_C(  -714.47), SIMDE_FLOAT32_C(   309.50), SIMDE_FLOAT32_C(   424.91), SIMDE_FLOAT32_C(  -761.59),
        SIMDE_FLOAT32_C(   676.76), SIMDE_FLOAT32_C(  -565.77), SIMDE_FLOAT32_C(  -402.08), SIMDE_FLOAT32_C(   894.99) },
      { SIMDE_FLOAT32_C(   170.03), SIMDE_FLOAT32_C(   603.13), SIMDE_FLOAT32_C(  -476.52), SIMDE_FLOAT32_C(   250.55),
        SIMDE_FLOAT32_C(   555.99), SIMDE_FLOAT32_C(  -308.42), SIMDE_FLOAT32_C(  -377.79), SIMDE_FLOAT32_C(   355.08),
        SIMDE_FLOAT32_C(    71.78), SIMDE_FLOAT32_C(   348.49), SIMDE_FLOAT32_C(   958.85), SIMDE_FLOAT32_C(   493.81),
        SIMDE_FLOAT32_C(  -488.10), SIMDE_FLOAT32_C(  -248.76), SIMDE_FLOAT32_C(   830.90), SIMDE_FLOAT32_C(   409.69) },
      {  INT32_C(   668697814),  INT32_C(  1801221653), -INT32_C(   336556626),  INT32_C(  1699615469),  INT32_C(   687148528), -INT32_C(  1528252667),  INT32_C(  1025004880),  INT32_C(  1664212621),
         INT32_C(  2005535842),  INT32_C(   837019267),  INT32_C(  1629279091), -INT32_C(   691639323),  INT32_C(  2130623352), -INT32_C(  1037899918), -INT32_C(   906020292),  INT32_C(  2066493720) },
       INT32_C(          61),
      { SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(    -0.00) } },
    { UINT16_C(54684),
      { SIMDE_FLOAT32_C(  -894.58), SIMDE_FLOAT32_C(  -180.76), SIMDE_FLOAT32_C(   659.19), SIMDE_FLOAT32_C(  -111.12),
        SIMDE_FLOAT32_C(   693.67), SIMDE_FLOAT32_C(   548.82), SIMDE_FLOAT32_C(  -322.96), SIMDE_FLOAT32_C(   979.20),
        SIMDE_FLOAT32_C(  -141.69), SIMDE_FLOAT32_C(  -898.05), SIMDE_FLOAT32_C(  -782.40), SIMDE_FLOAT32_C(  -464.93),
        SIMDE_FLOAT32_C(  -463.82), SIMDE_FLOAT32_C(  -184.48), SIMDE_FLOAT32_C(  -569.93), SIMDE_FLOAT32_C(   706.20) },
      { SIMDE_FLOAT32_C(  -581.35), SIMDE_FLOAT32_C(   -46.46), SIMDE_FLOAT32_C(   -43.25), SIMDE_FLOAT32_C(   974.64),
        SIMDE_FLOAT32_C(   645.12), SIMDE_FLOAT32_C(   578.96), SIMDE_FLOAT32_C(   329.73), SIMDE_FLOAT32_C(  -283.11),
        SIMDE_FLOAT32_C(   -72.55), SIMDE_FLOAT32_C(   288.57), SIMDE_FLOAT32_C(  -789.30), SIMDE_FLOAT32_C(   439.35),
        SIMDE_FLOAT32_C(  -960.19), SIMDE_FLOAT32_C(  -958.40), SIMDE_FLOAT32_C(  -150.96), SIMDE_FLOAT32_C(  -854.77) },
      {  INT32_C(   245895410),  INT32_C(   930713201),  INT32_C(  1660088932), -INT32_C(  1840683664),  INT32_C(   667780647),  INT32_C(  2086200655),  INT32_C(  1395823968),  INT32_C(  1210634070),
         INT32_C(  1347867103), -INT32_C(  1014509473),  INT32_C(   841316802),  INT32_C(   113536990),  INT32_C(  1143837173), -INT32_C(   675248777),  INT32_C(  1881862938), -INT32_C(  1581755454) },
       INT32_C(          36),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -1.00),
                   SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -141.69), SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -569.93), SIMDE_FLOAT32_C(  -854.77) } },
  };

  simde__m512 a, b, r;
  simde__m512i c;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  b = simde_mm512_loadu_ps(test_vec[0].b);
  c = simde_mm512_loadu_epi32(test_vec[0].c);
  r = simde_mm512_maskz_fixupimm_ps(test_vec[0].k, a, b, c, INT32_C(         181));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  b = simde_mm512_loadu_ps(test_vec[1].b);
  c = simde_mm512_loadu_epi32(test_vec[1].c);
  r = simde_mm512_maskz_fixupimm_ps(test_vec[1].k, a, b, c, INT32_C(         146));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  b = simde_mm512_loadu_ps(test_vec[2].b);
  c = simde_mm512_loadu_epi32(test_vec[2].c);
  r = simde_mm512_maskz_fixupimm_ps(test_vec[2].k, a, b, c, INT32_C(         144));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  b = simde_mm512_loadu_ps(test_vec[3].b);
  c = simde_mm512_loadu_epi32(test_vec[3].c);
  r = simde_mm512_maskz_fixupimm_ps(test_vec[3].k, a, b, c, INT32_C(         148));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  b = simde_mm512_loadu_ps(test_vec[4].b);
  c = simde_mm512_loadu_epi32(test_vec[4].c);
  r = simde_mm512_maskz_fixupimm_ps(test_vec[4].k, a, b, c, INT32_C(          52));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  b = simde_mm512_loadu_ps(test_vec[5].b);
  c = simde_mm512_loadu_epi32(test_vec[5].c);
  r = simde_mm512_maskz_fixupimm_ps(test_vec[5].k, a, b, c, INT32_C(         109));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  b = simde_mm512_loadu_ps(test_vec[6].b);
  c = simde_mm512_loadu_epi32(test_vec[6].c);
  r = simde_mm512_maskz_fixupimm_ps(test_vec[6].k, a, b, c, INT32_C(          61));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  b = simde_mm512_loadu_ps(test_vec[7].b);
  c = simde_mm512_loadu_epi32(test_vec[7].c);
  r = simde_mm512_maskz_fixupimm_ps(test_vec[7].k, a, b, c, INT32_C(          36));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_f32x16_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_extract_f32x16(i, 2, 0, values);
    simde__m512 b = simde_test_x86_random_extract_f32x16(i, 2, 1, values);
    simde__m512i c = simde_test_x86_random_i32x16();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512 r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_fixupimm_ps, r, simde_mm512_setzero_ps(), imm8, k, a, b, c);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  fprintf(stderr, "-------------------------\n------------------------\n----------------------\n");
  return 1;
#endif
}

static int
test_simde_mm_fixupimm_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t c[4];
    const int imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -551.70),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   860.02) },
      { SIMDE_FLOAT32_C(  -735.62),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   790.88) },
      { -INT32_C(  1265195033),  INT32_C(   140789386), -INT32_C(  1899312875), -INT32_C(  1770193656) },
       INT32_C(         221),
      {     -SIMDE_MATH_INFINITYF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   790.88) } },
    { { SIMDE_FLOAT32_C(  -566.66), SIMDE_FLOAT32_C(  -571.40), SIMDE_FLOAT32_C(  -782.02), SIMDE_FLOAT32_C(   251.94) },
      { SIMDE_FLOAT32_C(   742.03), SIMDE_FLOAT32_C(  -460.96), SIMDE_FLOAT32_C(  -135.23), SIMDE_FLOAT32_C(  -190.10) },
      { -INT32_C(  1353407648),  INT32_C(  1058776384), -INT32_C(  1024844325),  INT32_C(  1316389060) },
       INT32_C(         198),
      { SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(  -460.96), SIMDE_FLOAT32_C(  -135.23), SIMDE_FLOAT32_C(  -190.10) } },
    { { SIMDE_FLOAT32_C(   660.22), SIMDE_FLOAT32_C(  -229.57), SIMDE_FLOAT32_C(    69.62), SIMDE_FLOAT32_C(   482.86) },
      { SIMDE_FLOAT32_C(  -269.44), SIMDE_FLOAT32_C(   498.43), SIMDE_FLOAT32_C(   544.01), SIMDE_FLOAT32_C(  -439.37) },
      { -INT32_C(  1385619292), -INT32_C(    79436514), -INT32_C(   752182669),  INT32_C(  2122481213) },
       INT32_C(          36),
      { SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(   498.43), SIMDE_FLOAT32_C(   544.01), SIMDE_FLOAT32_C(  -439.37) } },
    { { SIMDE_FLOAT32_C(  -597.94), SIMDE_FLOAT32_C(  -379.85), SIMDE_FLOAT32_C(   -27.17), SIMDE_FLOAT32_C(    48.01) },
      { SIMDE_FLOAT32_C(  -137.68), SIMDE_FLOAT32_C(  -230.12), SIMDE_FLOAT32_C(   577.75), SIMDE_FLOAT32_C(  -764.05) },
      {  INT32_C(  2143398075), -INT32_C(   271763672), -INT32_C(  1211489262),  INT32_C(  1650734148) },
       INT32_C(          25),
      { SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(  -230.12), SIMDE_FLOAT32_C(   577.75), SIMDE_FLOAT32_C(  -764.05) } },
    { { SIMDE_FLOAT32_C(   218.17), SIMDE_FLOAT32_C(   867.81), SIMDE_FLOAT32_C(  -904.03), SIMDE_FLOAT32_C(   482.55) },
      { SIMDE_FLOAT32_C(   374.21), SIMDE_FLOAT32_C(  -537.12), SIMDE_FLOAT32_C(   273.43), SIMDE_FLOAT32_C(   807.55) },
      {  INT32_C(  2120255553),  INT32_C(   737993479),  INT32_C(  1009433217), -INT32_C(  1967395998) },
       INT32_C(          34),
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(  -537.12), SIMDE_FLOAT32_C(   273.43), SIMDE_FLOAT32_C(   807.55) } },
    { { SIMDE_FLOAT32_C(  -108.52), SIMDE_FLOAT32_C(   491.41), SIMDE_FLOAT32_C(    59.49), SIMDE_FLOAT32_C(  -366.49) },
      { SIMDE_FLOAT32_C(  -969.54), SIMDE_FLOAT32_C(   924.26), SIMDE_FLOAT32_C(   443.40), SIMDE_FLOAT32_C(   690.68) },
      { -INT32_C(   236174164), -INT32_C(  1856810888),  INT32_C(   941535735),  INT32_C(  1102479162) },
       INT32_C(          98),
      { SIMDE_FLOAT32_C(  -969.54), SIMDE_FLOAT32_C(   924.26), SIMDE_FLOAT32_C(   443.40), SIMDE_FLOAT32_C(   690.68) } },
    { { SIMDE_FLOAT32_C(  -305.31), SIMDE_FLOAT32_C(  -486.97), SIMDE_FLOAT32_C(   173.54), SIMDE_FLOAT32_C(   425.25) },
      { SIMDE_FLOAT32_C(  -988.54), SIMDE_FLOAT32_C(  -282.45), SIMDE_FLOAT32_C(   985.88), SIMDE_FLOAT32_C(  -586.48) },
      { -INT32_C(   820013459), -INT32_C(  1554392447),  INT32_C(   265868130), -INT32_C(  1895775209) },
       INT32_C(          20),
      { SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(  -282.45), SIMDE_FLOAT32_C(   985.88), SIMDE_FLOAT32_C(  -586.48) } },
    { { SIMDE_FLOAT32_C(   337.70), SIMDE_FLOAT32_C(   -41.29), SIMDE_FLOAT32_C(   461.53), SIMDE_FLOAT32_C(  -799.98) },
      { SIMDE_FLOAT32_C(   728.59), SIMDE_FLOAT32_C(    39.27), SIMDE_FLOAT32_C(  -564.03), SIMDE_FLOAT32_C(   -53.24) },
      {  INT32_C(  1061371653),  INT32_C(   545323710),  INT32_C(   436464813),  INT32_C(    65610370) },
       INT32_C(         252),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    39.27), SIMDE_FLOAT32_C(  -564.03), SIMDE_FLOAT32_C(   -53.24) } },
  };

  simde__m128 a, b, r;
  simde__m128i c;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_fixupimm_ss(a, b, c, INT32_C(         221));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_fixupimm_ss(a, b, c, INT32_C(         198));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_fixupimm_ss(a, b, c, INT32_C(          36));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_fixupimm_ss(a, b, c, INT32_C(          25));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_fixupimm_ss(a, b, c, INT32_C(          34));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_fixupimm_ss(a, b, c, INT32_C(          98));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_fixupimm_ss(a, b, c, INT32_C(          20));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_fixupimm_ss(a, b, c, INT32_C(         252));
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
    SIMDE_CONSTIFY_256_(simde_mm_fixupimm_ss, r, simde_mm_setzero_ps(), imm8, a, b, c);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_fixupimm_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde__mmask8 k;
    const simde_float32 b[4];
    const int32_t c[4];
    const int imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    17.73),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   583.28) },
      UINT8_C(236),
      { SIMDE_FLOAT32_C(    68.85),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   338.17) },
      {  INT32_C(   205575547), -INT32_C(  1485220724),  INT32_C(   241697071), -INT32_C(  1133261982) },
       INT32_C(         123),
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   338.17) } },
    { { SIMDE_FLOAT32_C(   817.25), SIMDE_FLOAT32_C(   -66.40), SIMDE_FLOAT32_C(   105.72), SIMDE_FLOAT32_C(   631.13) },
      UINT8_C( 17),
      { SIMDE_FLOAT32_C(   185.74), SIMDE_FLOAT32_C(   511.50), SIMDE_FLOAT32_C(  -859.94), SIMDE_FLOAT32_C(   913.76) },
      {  INT32_C(   349175174), -INT32_C(  1608832262),  INT32_C(  1981548449), -INT32_C(  1677514681) },
       INT32_C(         162),
      { SIMDE_FLOAT32_C(   185.74), SIMDE_FLOAT32_C(   511.50), SIMDE_FLOAT32_C(  -859.94), SIMDE_FLOAT32_C(   913.76) } },
    { { SIMDE_FLOAT32_C(  -266.07), SIMDE_FLOAT32_C(  -678.72), SIMDE_FLOAT32_C(   797.47), SIMDE_FLOAT32_C(  -873.06) },
      UINT8_C( 18),
      { SIMDE_FLOAT32_C(  -943.82), SIMDE_FLOAT32_C(   178.63), SIMDE_FLOAT32_C(  -914.24), SIMDE_FLOAT32_C(   532.25) },
      {  INT32_C(  1289553625), -INT32_C(   711632446), -INT32_C(   363092243), -INT32_C(  1595576203) },
       INT32_C(         139),
      { SIMDE_FLOAT32_C(  -266.07), SIMDE_FLOAT32_C(   178.63), SIMDE_FLOAT32_C(  -914.24), SIMDE_FLOAT32_C(   532.25) } },
    { { SIMDE_FLOAT32_C(  -158.88), SIMDE_FLOAT32_C(  -140.71), SIMDE_FLOAT32_C(   552.23), SIMDE_FLOAT32_C(   322.89) },
      UINT8_C(161),
      { SIMDE_FLOAT32_C(   792.00), SIMDE_FLOAT32_C(  -875.53), SIMDE_FLOAT32_C(   222.85), SIMDE_FLOAT32_C(  -731.62) },
      { -INT32_C(  1161110857),  INT32_C(  1097100406),  INT32_C(   354055951), -INT32_C(  1378326700) },
       INT32_C(         252),
      { SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(  -875.53), SIMDE_FLOAT32_C(   222.85), SIMDE_FLOAT32_C(  -731.62) } },
    { { SIMDE_FLOAT32_C(   142.21), SIMDE_FLOAT32_C(   394.02), SIMDE_FLOAT32_C(   851.66), SIMDE_FLOAT32_C(  -788.94) },
      UINT8_C(  8),
      { SIMDE_FLOAT32_C(   656.53), SIMDE_FLOAT32_C(   647.14), SIMDE_FLOAT32_C(   549.23), SIMDE_FLOAT32_C(   473.77) },
      {  INT32_C(  1786255237), -INT32_C(   118553673),  INT32_C(  1890619798), -INT32_C(   941200805) },
       INT32_C(         207),
      { SIMDE_FLOAT32_C(   142.21), SIMDE_FLOAT32_C(   647.14), SIMDE_FLOAT32_C(   549.23), SIMDE_FLOAT32_C(   473.77) } },
    { { SIMDE_FLOAT32_C(  -419.26), SIMDE_FLOAT32_C(  -345.05), SIMDE_FLOAT32_C(   104.91), SIMDE_FLOAT32_C(   766.48) },
      UINT8_C( 65),
      { SIMDE_FLOAT32_C(  -833.55), SIMDE_FLOAT32_C(   244.97), SIMDE_FLOAT32_C(   680.24), SIMDE_FLOAT32_C(   -99.63) },
      { -INT32_C(   995583252), -INT32_C(   495868856),  INT32_C(  1583839558), -INT32_C(   183119374) },
       INT32_C(         193),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   244.97), SIMDE_FLOAT32_C(   680.24), SIMDE_FLOAT32_C(   -99.63) } },
    { { SIMDE_FLOAT32_C(   566.25), SIMDE_FLOAT32_C(   477.71), SIMDE_FLOAT32_C(    27.31), SIMDE_FLOAT32_C(   622.43) },
      UINT8_C(190),
      { SIMDE_FLOAT32_C(  -343.66), SIMDE_FLOAT32_C(   113.07), SIMDE_FLOAT32_C(   154.68), SIMDE_FLOAT32_C(   497.46) },
      { -INT32_C(   517427717),  INT32_C(  1242101620), -INT32_C(   667530691), -INT32_C(  1759446286) },
       INT32_C(         107),
      { SIMDE_FLOAT32_C(   566.25), SIMDE_FLOAT32_C(   113.07), SIMDE_FLOAT32_C(   154.68), SIMDE_FLOAT32_C(   497.46) } },
    { { SIMDE_FLOAT32_C(   972.36), SIMDE_FLOAT32_C(  -293.10), SIMDE_FLOAT32_C(  -179.65), SIMDE_FLOAT32_C(   764.37) },
      UINT8_C(106),
      { SIMDE_FLOAT32_C(  -168.62), SIMDE_FLOAT32_C(  -956.80), SIMDE_FLOAT32_C(  -967.26), SIMDE_FLOAT32_C(   973.59) },
      {  INT32_C(  1362876219),  INT32_C(  1482685644), -INT32_C(    78439090),  INT32_C(  1030698309) },
       INT32_C(          61),
      { SIMDE_FLOAT32_C(   972.36), SIMDE_FLOAT32_C(  -956.80), SIMDE_FLOAT32_C(  -967.26), SIMDE_FLOAT32_C(   973.59) } },
  };

  simde__m128 a, b, r;
  simde__m128i c;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_mask_fixupimm_ss(a, test_vec[0].k, b, c, INT32_C(         123));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_mask_fixupimm_ss(a, test_vec[1].k, b, c, INT32_C(         162));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_mask_fixupimm_ss(a, test_vec[2].k, b, c, INT32_C(         139));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_mask_fixupimm_ss(a, test_vec[3].k, b, c, INT32_C(         252));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_mask_fixupimm_ss(a, test_vec[4].k, b, c, INT32_C(         207));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_mask_fixupimm_ss(a, test_vec[5].k, b, c, INT32_C(         193));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_mask_fixupimm_ss(a, test_vec[6].k, b, c, INT32_C(         107));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_mask_fixupimm_ss(a, test_vec[7].k, b, c, INT32_C(          61));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128i c = simde_test_x86_random_i32x4();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_fixupimm_ss, r, simde_mm_setzero_ps(), imm8, a, k, b, c);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_fixupimm_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t c[4];
    const int imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(234),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -233.09),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   338.03) },
      { SIMDE_FLOAT32_C(   938.21),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -268.29) },
      { -INT32_C(    33940159),  INT32_C(  1492514891), -INT32_C(  1015021536),  INT32_C(   172015337) },
       INT32_C(          98),
      { SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -268.29) } },
    { UINT8_C(100),
      { SIMDE_FLOAT32_C(   984.95), SIMDE_FLOAT32_C(   613.19), SIMDE_FLOAT32_C(   216.07), SIMDE_FLOAT32_C(   990.37) },
      { SIMDE_FLOAT32_C(   512.12), SIMDE_FLOAT32_C(   530.89), SIMDE_FLOAT32_C(  -760.11), SIMDE_FLOAT32_C(  -884.63) },
      { -INT32_C(  2020721377),  INT32_C(  2020846749),  INT32_C(   783899921),  INT32_C(  1333442135) },
       INT32_C(         172),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   530.89), SIMDE_FLOAT32_C(  -760.11), SIMDE_FLOAT32_C(  -884.63) } },
    { UINT8_C( 82),
      { SIMDE_FLOAT32_C(   252.22), SIMDE_FLOAT32_C(  -949.26), SIMDE_FLOAT32_C(   957.94), SIMDE_FLOAT32_C(  -357.53) },
      { SIMDE_FLOAT32_C(  -170.23), SIMDE_FLOAT32_C(   968.08), SIMDE_FLOAT32_C(   431.81), SIMDE_FLOAT32_C(  -235.42) },
      {  INT32_C(  1913754930),  INT32_C(  1411806111),  INT32_C(   410291163), -INT32_C(   961152231) },
       INT32_C(         110),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   968.08), SIMDE_FLOAT32_C(   431.81), SIMDE_FLOAT32_C(  -235.42) } },
    { UINT8_C(230),
      { SIMDE_FLOAT32_C(  -380.08), SIMDE_FLOAT32_C(   711.98), SIMDE_FLOAT32_C(   903.51), SIMDE_FLOAT32_C(  -241.52) },
      { SIMDE_FLOAT32_C(  -291.25), SIMDE_FLOAT32_C(   790.88), SIMDE_FLOAT32_C(   342.11), SIMDE_FLOAT32_C(   113.51) },
      {  INT32_C(  2140939013), -INT32_C(   497923982), -INT32_C(  1978358540),  INT32_C(   690587573) },
       INT32_C(         173),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   790.88), SIMDE_FLOAT32_C(   342.11), SIMDE_FLOAT32_C(   113.51) } },
    { UINT8_C(242),
      { SIMDE_FLOAT32_C(  -442.21), SIMDE_FLOAT32_C(   668.58), SIMDE_FLOAT32_C(  -548.45), SIMDE_FLOAT32_C(  -504.00) },
      { SIMDE_FLOAT32_C(   707.30), SIMDE_FLOAT32_C(  -856.65), SIMDE_FLOAT32_C(   227.71), SIMDE_FLOAT32_C(   692.25) },
      { -INT32_C(   772976100), -INT32_C(   268543208),  INT32_C(  1240785958), -INT32_C(   910396288) },
       INT32_C(         198),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -856.65), SIMDE_FLOAT32_C(   227.71), SIMDE_FLOAT32_C(   692.25) } },
    { UINT8_C(178),
      { SIMDE_FLOAT32_C(   756.54), SIMDE_FLOAT32_C(  -556.23), SIMDE_FLOAT32_C(   682.63), SIMDE_FLOAT32_C(   268.66) },
      { SIMDE_FLOAT32_C(   974.66), SIMDE_FLOAT32_C(   922.52), SIMDE_FLOAT32_C(   384.03), SIMDE_FLOAT32_C(   226.89) },
      {  INT32_C(  1899569223),  INT32_C(  1307567945),  INT32_C(  1902764319),  INT32_C(   696859342) },
       INT32_C(          56),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   922.52), SIMDE_FLOAT32_C(   384.03), SIMDE_FLOAT32_C(   226.89) } },
    { UINT8_C(109),
      { SIMDE_FLOAT32_C(   973.26), SIMDE_FLOAT32_C(   341.97), SIMDE_FLOAT32_C(   869.36), SIMDE_FLOAT32_C(  -196.97) },
      { SIMDE_FLOAT32_C(   310.05), SIMDE_FLOAT32_C(   301.17), SIMDE_FLOAT32_C(   567.61), SIMDE_FLOAT32_C(   929.98) },
      {  INT32_C(  1440849049),  INT32_C(   603170661),  INT32_C(   829072657), -INT32_C(   965026849) },
       INT32_C(         202),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   301.17), SIMDE_FLOAT32_C(   567.61), SIMDE_FLOAT32_C(   929.98) } },
    { UINT8_C( 48),
      { SIMDE_FLOAT32_C(    13.15), SIMDE_FLOAT32_C(   471.12), SIMDE_FLOAT32_C(  -311.54), SIMDE_FLOAT32_C(   721.89) },
      { SIMDE_FLOAT32_C(   262.00), SIMDE_FLOAT32_C(  -969.44), SIMDE_FLOAT32_C(  -164.59), SIMDE_FLOAT32_C(   819.79) },
      { -INT32_C(   529893033), -INT32_C(   229006686),  INT32_C(  1535887038),  INT32_C(  1321263271) },
       INT32_C(         211),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -969.44), SIMDE_FLOAT32_C(  -164.59), SIMDE_FLOAT32_C(   819.79) } },
  };

  simde__m128 a, b, r;
  simde__m128i c;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_maskz_fixupimm_ss(test_vec[0].k, a, b, c, INT32_C(          98));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_maskz_fixupimm_ss(test_vec[1].k, a, b, c, INT32_C(         172));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_maskz_fixupimm_ss(test_vec[2].k, a, b, c, INT32_C(         110));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_maskz_fixupimm_ss(test_vec[3].k, a, b, c, INT32_C(         173));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_maskz_fixupimm_ss(test_vec[4].k, a, b, c, INT32_C(         198));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_maskz_fixupimm_ss(test_vec[5].k, a, b, c, INT32_C(          56));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_maskz_fixupimm_ss(test_vec[6].k, a, b, c, INT32_C(         202));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_maskz_fixupimm_ss(test_vec[7].k, a, b, c, INT32_C(         211));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128i c = simde_test_x86_random_i32x4();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_fixupimm_ss, r, simde_mm_setzero_ps(), imm8, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
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
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_fixupimm_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_fixupimm_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_fixupimm_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_fixupimm_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_fixupimm_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_fixupimm_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_fixupimm_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_fixupimm_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fixupimm_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_fixupimm_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_fixupimm_ss)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
