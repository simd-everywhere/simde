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

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fixupimm_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_fixupimm_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_fixupimm_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
