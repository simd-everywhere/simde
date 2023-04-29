#define SIMDE_TEST_X86_AVX512_INSN roundscale_round

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/roundscale_round.h>
#include <simde/x86/avx512/setzero.h>

static int
test_simde_mm512_roundscale_round_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   420.36), SIMDE_FLOAT32_C(  -392.69), SIMDE_FLOAT32_C(    92.54), SIMDE_FLOAT32_C(  -516.66),
        SIMDE_FLOAT32_C(  -461.28), SIMDE_FLOAT32_C(   334.68), SIMDE_FLOAT32_C(  -795.62), SIMDE_FLOAT32_C(   457.56),
        SIMDE_FLOAT32_C(   838.71), SIMDE_FLOAT32_C(  -818.44), SIMDE_FLOAT32_C(  -257.99), SIMDE_FLOAT32_C(   715.11),
        SIMDE_FLOAT32_C(   338.10), SIMDE_FLOAT32_C(   349.70), SIMDE_FLOAT32_C(  -986.91), SIMDE_FLOAT32_C(   385.06) },
       INT32_C(         128),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   420.36), SIMDE_FLOAT32_C(  -392.69), SIMDE_FLOAT32_C(    92.54), SIMDE_FLOAT32_C(  -516.66),
        SIMDE_FLOAT32_C(  -461.28), SIMDE_FLOAT32_C(   334.68), SIMDE_FLOAT32_C(  -795.62), SIMDE_FLOAT32_C(   457.56),
        SIMDE_FLOAT32_C(   838.71), SIMDE_FLOAT32_C(  -818.44), SIMDE_FLOAT32_C(  -257.99), SIMDE_FLOAT32_C(   715.11),
        SIMDE_FLOAT32_C(   338.10), SIMDE_FLOAT32_C(   349.70), SIMDE_FLOAT32_C(  -986.91), SIMDE_FLOAT32_C(   385.06) } },
    { { SIMDE_FLOAT32_C(  -102.50),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   610.23), SIMDE_FLOAT32_C(   712.54),
        SIMDE_FLOAT32_C(  -668.49), SIMDE_FLOAT32_C(   752.35), SIMDE_FLOAT32_C(  -528.74), SIMDE_FLOAT32_C(   -20.66),
        SIMDE_FLOAT32_C(  -980.81), SIMDE_FLOAT32_C(  -208.53), SIMDE_FLOAT32_C(  -940.25), SIMDE_FLOAT32_C(   895.60),
        SIMDE_FLOAT32_C(  -788.17), SIMDE_FLOAT32_C(  -332.94), SIMDE_FLOAT32_C(   -11.86), SIMDE_FLOAT32_C(  -304.83) },
       INT32_C(          65),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -102.50),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   610.19), SIMDE_FLOAT32_C(   712.50),
        SIMDE_FLOAT32_C(  -668.50), SIMDE_FLOAT32_C(   752.31), SIMDE_FLOAT32_C(  -528.75), SIMDE_FLOAT32_C(   -20.69),
        SIMDE_FLOAT32_C(  -980.81), SIMDE_FLOAT32_C(  -208.56), SIMDE_FLOAT32_C(  -940.25), SIMDE_FLOAT32_C(   895.56),
        SIMDE_FLOAT32_C(  -788.19), SIMDE_FLOAT32_C(  -333.00), SIMDE_FLOAT32_C(   -11.88), SIMDE_FLOAT32_C(  -304.88) } },
    { { SIMDE_FLOAT32_C(    81.11),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   876.65), SIMDE_FLOAT32_C(  -580.79),
        SIMDE_FLOAT32_C(  -244.95), SIMDE_FLOAT32_C(   889.73), SIMDE_FLOAT32_C(   804.27), SIMDE_FLOAT32_C(  -859.60),
        SIMDE_FLOAT32_C(   948.64), SIMDE_FLOAT32_C(  -574.10), SIMDE_FLOAT32_C(    37.90), SIMDE_FLOAT32_C(  -975.20),
        SIMDE_FLOAT32_C(  -963.86), SIMDE_FLOAT32_C(  -249.56), SIMDE_FLOAT32_C(  -643.68), SIMDE_FLOAT32_C(   788.49) },
       INT32_C(         226),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(    81.11),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   876.65), SIMDE_FLOAT32_C(  -580.79),
        SIMDE_FLOAT32_C(  -244.95), SIMDE_FLOAT32_C(   889.73), SIMDE_FLOAT32_C(   804.27), SIMDE_FLOAT32_C(  -859.60),
        SIMDE_FLOAT32_C(   948.64), SIMDE_FLOAT32_C(  -574.10), SIMDE_FLOAT32_C(    37.90), SIMDE_FLOAT32_C(  -975.20),
        SIMDE_FLOAT32_C(  -963.86), SIMDE_FLOAT32_C(  -249.56), SIMDE_FLOAT32_C(  -643.68), SIMDE_FLOAT32_C(   788.49) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -775.00), SIMDE_FLOAT32_C(  -937.53), SIMDE_FLOAT32_C(  -308.58),
        SIMDE_FLOAT32_C(   -79.83), SIMDE_FLOAT32_C(   268.25), SIMDE_FLOAT32_C(    14.24), SIMDE_FLOAT32_C(   819.73),
        SIMDE_FLOAT32_C(   931.60), SIMDE_FLOAT32_C(   175.77), SIMDE_FLOAT32_C(   -99.16), SIMDE_FLOAT32_C(   336.95),
        SIMDE_FLOAT32_C(    52.42), SIMDE_FLOAT32_C(   320.05), SIMDE_FLOAT32_C(  -908.00), SIMDE_FLOAT32_C(   -57.85) },
       INT32_C(         243),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -775.00), SIMDE_FLOAT32_C(  -937.53), SIMDE_FLOAT32_C(  -308.58),
        SIMDE_FLOAT32_C(   -79.83), SIMDE_FLOAT32_C(   268.25), SIMDE_FLOAT32_C(    14.24), SIMDE_FLOAT32_C(   819.73),
        SIMDE_FLOAT32_C(   931.60), SIMDE_FLOAT32_C(   175.77), SIMDE_FLOAT32_C(   -99.16), SIMDE_FLOAT32_C(   336.95),
        SIMDE_FLOAT32_C(    52.42), SIMDE_FLOAT32_C(   320.05), SIMDE_FLOAT32_C(  -908.00), SIMDE_FLOAT32_C(   -57.85) } },
    { { SIMDE_FLOAT32_C(   270.29), SIMDE_FLOAT32_C(   -84.41), SIMDE_FLOAT32_C(   586.36), SIMDE_FLOAT32_C(  -979.27),
        SIMDE_FLOAT32_C(   271.91), SIMDE_FLOAT32_C(   374.85), SIMDE_FLOAT32_C(   242.43), SIMDE_FLOAT32_C(  -392.43),
        SIMDE_FLOAT32_C(   182.52), SIMDE_FLOAT32_C(   255.60), SIMDE_FLOAT32_C(  -997.03), SIMDE_FLOAT32_C(  -114.21),
        SIMDE_FLOAT32_C(   480.61), SIMDE_FLOAT32_C(  -934.56), SIMDE_FLOAT32_C(   577.21), SIMDE_FLOAT32_C(  -599.22) },
       INT32_C(          68),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   270.31), SIMDE_FLOAT32_C(   -84.44), SIMDE_FLOAT32_C(   586.38), SIMDE_FLOAT32_C(  -979.25),
        SIMDE_FLOAT32_C(   271.94), SIMDE_FLOAT32_C(   374.88), SIMDE_FLOAT32_C(   242.44), SIMDE_FLOAT32_C(  -392.44),
        SIMDE_FLOAT32_C(   182.50), SIMDE_FLOAT32_C(   255.62), SIMDE_FLOAT32_C(  -997.00), SIMDE_FLOAT32_C(  -114.19),
        SIMDE_FLOAT32_C(   480.62), SIMDE_FLOAT32_C(  -934.56), SIMDE_FLOAT32_C(   577.19), SIMDE_FLOAT32_C(  -599.25) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   767.22), SIMDE_FLOAT32_C(   121.34), SIMDE_FLOAT32_C(  -397.76),
        SIMDE_FLOAT32_C(  -180.36), SIMDE_FLOAT32_C(  -558.61), SIMDE_FLOAT32_C(  -305.76), SIMDE_FLOAT32_C(   761.79),
        SIMDE_FLOAT32_C(   565.70), SIMDE_FLOAT32_C(   -73.36), SIMDE_FLOAT32_C(  -347.42), SIMDE_FLOAT32_C(   115.93),
        SIMDE_FLOAT32_C(  -803.07), SIMDE_FLOAT32_C(   568.17), SIMDE_FLOAT32_C(  -297.71), SIMDE_FLOAT32_C(  -782.34) },
       INT32_C(          16),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   767.00), SIMDE_FLOAT32_C(   121.50), SIMDE_FLOAT32_C(  -398.00),
        SIMDE_FLOAT32_C(  -180.50), SIMDE_FLOAT32_C(  -558.50), SIMDE_FLOAT32_C(  -306.00), SIMDE_FLOAT32_C(   762.00),
        SIMDE_FLOAT32_C(   565.50), SIMDE_FLOAT32_C(   -73.50), SIMDE_FLOAT32_C(  -347.50), SIMDE_FLOAT32_C(   116.00),
        SIMDE_FLOAT32_C(  -803.00), SIMDE_FLOAT32_C(   568.00), SIMDE_FLOAT32_C(  -297.50), SIMDE_FLOAT32_C(  -782.50) } },
    { { SIMDE_FLOAT32_C(   259.65),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   450.62), SIMDE_FLOAT32_C(  -854.55),
        SIMDE_FLOAT32_C(  -803.69), SIMDE_FLOAT32_C(   516.07), SIMDE_FLOAT32_C(   722.66), SIMDE_FLOAT32_C(  -402.91),
        SIMDE_FLOAT32_C(  -150.24), SIMDE_FLOAT32_C(  -685.89), SIMDE_FLOAT32_C(  -182.41), SIMDE_FLOAT32_C(  -884.95),
        SIMDE_FLOAT32_C(  -918.68), SIMDE_FLOAT32_C(   938.93), SIMDE_FLOAT32_C(  -282.71), SIMDE_FLOAT32_C(   -99.04) },
       INT32_C(         209),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   259.65),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   450.62), SIMDE_FLOAT32_C(  -854.55),
        SIMDE_FLOAT32_C(  -803.69), SIMDE_FLOAT32_C(   516.07), SIMDE_FLOAT32_C(   722.66), SIMDE_FLOAT32_C(  -402.91),
        SIMDE_FLOAT32_C(  -150.24), SIMDE_FLOAT32_C(  -685.89), SIMDE_FLOAT32_C(  -182.41), SIMDE_FLOAT32_C(  -884.95),
        SIMDE_FLOAT32_C(  -918.68), SIMDE_FLOAT32_C(   938.93), SIMDE_FLOAT32_C(  -282.71), SIMDE_FLOAT32_C(   -99.04) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    61.95), SIMDE_FLOAT32_C(  -464.91), SIMDE_FLOAT32_C(  -116.51),
        SIMDE_FLOAT32_C(   764.24), SIMDE_FLOAT32_C(  -247.25), SIMDE_FLOAT32_C(   723.58), SIMDE_FLOAT32_C(   841.37),
        SIMDE_FLOAT32_C(  -787.15), SIMDE_FLOAT32_C(   171.22), SIMDE_FLOAT32_C(   101.02), SIMDE_FLOAT32_C(   -71.45),
        SIMDE_FLOAT32_C(  -378.15), SIMDE_FLOAT32_C(   246.47), SIMDE_FLOAT32_C(   124.86), SIMDE_FLOAT32_C(  -862.09) },
       INT32_C(         146),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    61.95), SIMDE_FLOAT32_C(  -464.91), SIMDE_FLOAT32_C(  -116.51),
        SIMDE_FLOAT32_C(   764.24), SIMDE_FLOAT32_C(  -247.25), SIMDE_FLOAT32_C(   723.58), SIMDE_FLOAT32_C(   841.37),
        SIMDE_FLOAT32_C(  -787.15), SIMDE_FLOAT32_C(   171.22), SIMDE_FLOAT32_C(   101.02), SIMDE_FLOAT32_C(   -71.45),
        SIMDE_FLOAT32_C(  -378.15), SIMDE_FLOAT32_C(   246.47), SIMDE_FLOAT32_C(   124.86), SIMDE_FLOAT32_C(  -862.09) } },
  };

  simde__m512 a, r;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(         128), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(          65), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(         226), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(         243), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);
  #endif

  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(          68), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(          16), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);
  #endif

  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(         209), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_roundscale_round_ps(a, INT32_C(         146), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);
  #endif

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_ps(a, 1, simde_mm512_set1_ps(SIMDE_MATH_NANF));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION: SIMDE_MM_FROUND_NO_EXC;
    simde__m512 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_roundscale_round_ps, r, simde_mm512_setzero_ps(), imm8, sae, a);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_roundscale_round_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde__mmask8 k;
    const simde_float32 a[16];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -683.72), SIMDE_FLOAT32_C(   458.47), SIMDE_FLOAT32_C(  -593.60), SIMDE_FLOAT32_C(   433.99),
        SIMDE_FLOAT32_C(   507.21), SIMDE_FLOAT32_C(  -748.26), SIMDE_FLOAT32_C(   930.02), SIMDE_FLOAT32_C(   211.45),
        SIMDE_FLOAT32_C(   545.03), SIMDE_FLOAT32_C(   396.72), SIMDE_FLOAT32_C(   252.12), SIMDE_FLOAT32_C(  -162.44),
        SIMDE_FLOAT32_C(  -909.04), SIMDE_FLOAT32_C(  -524.81), SIMDE_FLOAT32_C(  -182.17), SIMDE_FLOAT32_C(   649.98) },
      UINT8_C(106),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   420.31), SIMDE_FLOAT32_C(   726.25), SIMDE_FLOAT32_C(  -425.66),
        SIMDE_FLOAT32_C(   519.34), SIMDE_FLOAT32_C(   413.17), SIMDE_FLOAT32_C(   674.22), SIMDE_FLOAT32_C(  -345.82),
        SIMDE_FLOAT32_C(  -228.35), SIMDE_FLOAT32_C(   -30.31), SIMDE_FLOAT32_C(  -791.64), SIMDE_FLOAT32_C(   638.20),
        SIMDE_FLOAT32_C(  -289.44), SIMDE_FLOAT32_C(   644.82), SIMDE_FLOAT32_C(   954.47), SIMDE_FLOAT32_C(  -830.97) },
       INT32_C(          64),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -683.72), SIMDE_FLOAT32_C(   420.31), SIMDE_FLOAT32_C(  -593.60), SIMDE_FLOAT32_C(  -425.69),
        SIMDE_FLOAT32_C(   507.21), SIMDE_FLOAT32_C(   413.19), SIMDE_FLOAT32_C(   674.25), SIMDE_FLOAT32_C(   211.45),
        SIMDE_FLOAT32_C(   545.03), SIMDE_FLOAT32_C(   396.72), SIMDE_FLOAT32_C(   252.12), SIMDE_FLOAT32_C(  -162.44),
        SIMDE_FLOAT32_C(  -909.04), SIMDE_FLOAT32_C(  -524.81), SIMDE_FLOAT32_C(  -182.17), SIMDE_FLOAT32_C(   649.98) } },
    { { SIMDE_FLOAT32_C(   318.48), SIMDE_FLOAT32_C(  -112.31), SIMDE_FLOAT32_C(   847.99), SIMDE_FLOAT32_C(  -284.80),
        SIMDE_FLOAT32_C(  -860.19), SIMDE_FLOAT32_C(  -314.45), SIMDE_FLOAT32_C(  -193.84), SIMDE_FLOAT32_C(  -385.00),
        SIMDE_FLOAT32_C(   503.38), SIMDE_FLOAT32_C(  -543.86), SIMDE_FLOAT32_C(   367.57), SIMDE_FLOAT32_C(  -848.04),
        SIMDE_FLOAT32_C(   876.46), SIMDE_FLOAT32_C(    93.82), SIMDE_FLOAT32_C(  -273.70), SIMDE_FLOAT32_C(   395.80) },
      UINT8_C( 50),
      { SIMDE_FLOAT32_C(  -599.48),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   278.64), SIMDE_FLOAT32_C(   370.22),
        SIMDE_FLOAT32_C(  -741.66), SIMDE_FLOAT32_C(   -83.17), SIMDE_FLOAT32_C(  -919.22), SIMDE_FLOAT32_C(   903.16),
        SIMDE_FLOAT32_C(  -128.69), SIMDE_FLOAT32_C(  -750.19), SIMDE_FLOAT32_C(   954.39), SIMDE_FLOAT32_C(  -740.23),
        SIMDE_FLOAT32_C(   926.06), SIMDE_FLOAT32_C(  -742.65), SIMDE_FLOAT32_C(   578.25), SIMDE_FLOAT32_C(  -186.24) },
       INT32_C(         177),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   318.48),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   847.99), SIMDE_FLOAT32_C(  -284.80),
        SIMDE_FLOAT32_C(  -741.66), SIMDE_FLOAT32_C(   -83.17), SIMDE_FLOAT32_C(  -193.84), SIMDE_FLOAT32_C(  -385.00),
        SIMDE_FLOAT32_C(   503.38), SIMDE_FLOAT32_C(  -543.86), SIMDE_FLOAT32_C(   367.57), SIMDE_FLOAT32_C(  -848.04),
        SIMDE_FLOAT32_C(   876.46), SIMDE_FLOAT32_C(    93.82), SIMDE_FLOAT32_C(  -273.70), SIMDE_FLOAT32_C(   395.80) } },
    { { SIMDE_FLOAT32_C(   568.56), SIMDE_FLOAT32_C(  -705.73), SIMDE_FLOAT32_C(   555.76), SIMDE_FLOAT32_C(   -63.87),
        SIMDE_FLOAT32_C(  -553.77), SIMDE_FLOAT32_C(   432.21), SIMDE_FLOAT32_C(  -970.05), SIMDE_FLOAT32_C(   172.53),
        SIMDE_FLOAT32_C(  -171.99), SIMDE_FLOAT32_C(  -463.06), SIMDE_FLOAT32_C(   573.05), SIMDE_FLOAT32_C(  -122.01),
        SIMDE_FLOAT32_C(   815.58), SIMDE_FLOAT32_C(   -56.73), SIMDE_FLOAT32_C(   136.33), SIMDE_FLOAT32_C(  -267.59) },
      UINT8_C( 31),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   603.72), SIMDE_FLOAT32_C(   273.86), SIMDE_FLOAT32_C(    -6.12),
        SIMDE_FLOAT32_C(   863.49), SIMDE_FLOAT32_C(   199.92), SIMDE_FLOAT32_C(   251.23), SIMDE_FLOAT32_C(   441.74),
        SIMDE_FLOAT32_C(  -986.32), SIMDE_FLOAT32_C(   356.57), SIMDE_FLOAT32_C(   735.19), SIMDE_FLOAT32_C(   -32.75),
        SIMDE_FLOAT32_C(  -852.54), SIMDE_FLOAT32_C(  -165.20), SIMDE_FLOAT32_C(  -464.19), SIMDE_FLOAT32_C(  -558.27) },
       INT32_C(         242),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   603.72), SIMDE_FLOAT32_C(   273.86), SIMDE_FLOAT32_C(    -6.12),
        SIMDE_FLOAT32_C(   863.49), SIMDE_FLOAT32_C(   432.21), SIMDE_FLOAT32_C(  -970.05), SIMDE_FLOAT32_C(   172.53),
        SIMDE_FLOAT32_C(  -171.99), SIMDE_FLOAT32_C(  -463.06), SIMDE_FLOAT32_C(   573.05), SIMDE_FLOAT32_C(  -122.01),
        SIMDE_FLOAT32_C(   815.58), SIMDE_FLOAT32_C(   -56.73), SIMDE_FLOAT32_C(   136.33), SIMDE_FLOAT32_C(  -267.59) } },
    { { SIMDE_FLOAT32_C(   501.88), SIMDE_FLOAT32_C(  -939.52), SIMDE_FLOAT32_C(  -349.21), SIMDE_FLOAT32_C(  -961.18),
        SIMDE_FLOAT32_C(   633.53), SIMDE_FLOAT32_C(   528.78), SIMDE_FLOAT32_C(   854.40), SIMDE_FLOAT32_C(  -423.20),
        SIMDE_FLOAT32_C(  -334.89), SIMDE_FLOAT32_C(  -413.19), SIMDE_FLOAT32_C(   600.85), SIMDE_FLOAT32_C(   704.60),
        SIMDE_FLOAT32_C(  -809.47), SIMDE_FLOAT32_C(  -125.29), SIMDE_FLOAT32_C(  -301.53), SIMDE_FLOAT32_C(  -945.98) },
      UINT8_C(138),
      { SIMDE_FLOAT32_C(   949.70), SIMDE_FLOAT32_C(   495.77), SIMDE_FLOAT32_C(  -911.69), SIMDE_FLOAT32_C(   306.27),
        SIMDE_FLOAT32_C(   230.96), SIMDE_FLOAT32_C(    55.56), SIMDE_FLOAT32_C(   453.73), SIMDE_FLOAT32_C(  -934.24),
        SIMDE_FLOAT32_C(   591.37), SIMDE_FLOAT32_C(   895.45), SIMDE_FLOAT32_C(  -543.68), SIMDE_FLOAT32_C(    63.30),
        SIMDE_FLOAT32_C(  -216.59), SIMDE_FLOAT32_C(  -720.90), SIMDE_FLOAT32_C(  -434.81), SIMDE_FLOAT32_C(  -156.11) },
       INT32_C(          83),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   501.88), SIMDE_FLOAT32_C(   495.75), SIMDE_FLOAT32_C(  -349.21), SIMDE_FLOAT32_C(   306.25),
        SIMDE_FLOAT32_C(   633.53), SIMDE_FLOAT32_C(   528.78), SIMDE_FLOAT32_C(   854.40), SIMDE_FLOAT32_C(  -934.22),
        SIMDE_FLOAT32_C(  -334.89), SIMDE_FLOAT32_C(  -413.19), SIMDE_FLOAT32_C(   600.85), SIMDE_FLOAT32_C(   704.60),
        SIMDE_FLOAT32_C(  -809.47), SIMDE_FLOAT32_C(  -125.29), SIMDE_FLOAT32_C(  -301.53), SIMDE_FLOAT32_C(  -945.98) } },
    { { SIMDE_FLOAT32_C(  -541.34), SIMDE_FLOAT32_C(  -541.59), SIMDE_FLOAT32_C(    54.22), SIMDE_FLOAT32_C(   123.77),
        SIMDE_FLOAT32_C(    45.22), SIMDE_FLOAT32_C(  -344.93), SIMDE_FLOAT32_C(  -171.63), SIMDE_FLOAT32_C(   235.75),
        SIMDE_FLOAT32_C(   529.78), SIMDE_FLOAT32_C(   526.84), SIMDE_FLOAT32_C(   289.78), SIMDE_FLOAT32_C(   604.42),
        SIMDE_FLOAT32_C(   476.54), SIMDE_FLOAT32_C(  -214.46), SIMDE_FLOAT32_C(   692.73), SIMDE_FLOAT32_C(  -217.19) },
      UINT8_C(173),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -763.46), SIMDE_FLOAT32_C(  -917.74), SIMDE_FLOAT32_C(  -660.34),
        SIMDE_FLOAT32_C(  -868.01), SIMDE_FLOAT32_C(  -461.42), SIMDE_FLOAT32_C(   402.96), SIMDE_FLOAT32_C(   -84.60),
        SIMDE_FLOAT32_C(  -182.32), SIMDE_FLOAT32_C(   968.15), SIMDE_FLOAT32_C(   759.29), SIMDE_FLOAT32_C(   747.56),
        SIMDE_FLOAT32_C(  -427.84), SIMDE_FLOAT32_C(  -763.29), SIMDE_FLOAT32_C(  -793.77), SIMDE_FLOAT32_C(    30.57) },
       INT32_C(         100),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -541.59), SIMDE_FLOAT32_C(  -917.73), SIMDE_FLOAT32_C(  -660.34),
        SIMDE_FLOAT32_C(    45.22), SIMDE_FLOAT32_C(  -461.42), SIMDE_FLOAT32_C(  -171.63), SIMDE_FLOAT32_C(   -84.59),
        SIMDE_FLOAT32_C(   529.78), SIMDE_FLOAT32_C(   526.84), SIMDE_FLOAT32_C(   289.78), SIMDE_FLOAT32_C(   604.42),
        SIMDE_FLOAT32_C(   476.54), SIMDE_FLOAT32_C(  -214.46), SIMDE_FLOAT32_C(   692.73), SIMDE_FLOAT32_C(  -217.19) } },
    { { SIMDE_FLOAT32_C(  -841.63), SIMDE_FLOAT32_C(   311.54), SIMDE_FLOAT32_C(   475.79), SIMDE_FLOAT32_C(   685.21),
        SIMDE_FLOAT32_C(  -398.68), SIMDE_FLOAT32_C(    80.21), SIMDE_FLOAT32_C(   161.75), SIMDE_FLOAT32_C(   386.86),
        SIMDE_FLOAT32_C(  -227.06), SIMDE_FLOAT32_C(   944.56), SIMDE_FLOAT32_C(   403.36), SIMDE_FLOAT32_C(   521.23),
        SIMDE_FLOAT32_C(  -818.90), SIMDE_FLOAT32_C(   485.62), SIMDE_FLOAT32_C(   860.89), SIMDE_FLOAT32_C(  -686.90) },
      UINT8_C( 71),
      { SIMDE_FLOAT32_C(   263.85),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -158.11), SIMDE_FLOAT32_C(   231.99),
        SIMDE_FLOAT32_C(   -12.21), SIMDE_FLOAT32_C(  -410.55), SIMDE_FLOAT32_C(   804.15), SIMDE_FLOAT32_C(   224.51),
        SIMDE_FLOAT32_C(  -204.32), SIMDE_FLOAT32_C(  -165.28), SIMDE_FLOAT32_C(  -484.56), SIMDE_FLOAT32_C(  -874.32),
        SIMDE_FLOAT32_C(   -89.50), SIMDE_FLOAT32_C(  -538.55), SIMDE_FLOAT32_C(  -715.95), SIMDE_FLOAT32_C(  -777.95) },
       INT32_C(         240),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   263.85),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -158.11), SIMDE_FLOAT32_C(   685.21),
        SIMDE_FLOAT32_C(  -398.68), SIMDE_FLOAT32_C(    80.21), SIMDE_FLOAT32_C(   804.15), SIMDE_FLOAT32_C(   386.86),
        SIMDE_FLOAT32_C(  -227.06), SIMDE_FLOAT32_C(   944.56), SIMDE_FLOAT32_C(   403.36), SIMDE_FLOAT32_C(   521.23),
        SIMDE_FLOAT32_C(  -818.90), SIMDE_FLOAT32_C(   485.62), SIMDE_FLOAT32_C(   860.89), SIMDE_FLOAT32_C(  -686.90) } },
    { { SIMDE_FLOAT32_C(  -789.77), SIMDE_FLOAT32_C(   790.38), SIMDE_FLOAT32_C(    75.57), SIMDE_FLOAT32_C(   613.60),
        SIMDE_FLOAT32_C(   311.61), SIMDE_FLOAT32_C(   256.68), SIMDE_FLOAT32_C(    99.22), SIMDE_FLOAT32_C(   172.50),
        SIMDE_FLOAT32_C(   569.77), SIMDE_FLOAT32_C(   123.43), SIMDE_FLOAT32_C(  -563.65), SIMDE_FLOAT32_C(  -201.73),
        SIMDE_FLOAT32_C(   965.31), SIMDE_FLOAT32_C(   668.34), SIMDE_FLOAT32_C(   786.06), SIMDE_FLOAT32_C(  -445.24) },
      UINT8_C( 96),
      { SIMDE_FLOAT32_C(    10.57), SIMDE_FLOAT32_C(   350.44), SIMDE_FLOAT32_C(  -692.79), SIMDE_FLOAT32_C(   526.01),
        SIMDE_FLOAT32_C(   476.12), SIMDE_FLOAT32_C(   217.72), SIMDE_FLOAT32_C(   987.46), SIMDE_FLOAT32_C(   760.17),
        SIMDE_FLOAT32_C(   439.76), SIMDE_FLOAT32_C(   924.70), SIMDE_FLOAT32_C(   729.42), SIMDE_FLOAT32_C(  -736.87),
        SIMDE_FLOAT32_C(   -57.85), SIMDE_FLOAT32_C(  -139.57), SIMDE_FLOAT32_C(  -526.64), SIMDE_FLOAT32_C(  -267.47) },
       INT32_C(          33),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -789.77), SIMDE_FLOAT32_C(   790.38), SIMDE_FLOAT32_C(    75.57), SIMDE_FLOAT32_C(   613.60),
        SIMDE_FLOAT32_C(   311.61), SIMDE_FLOAT32_C(   217.50), SIMDE_FLOAT32_C(   987.25), SIMDE_FLOAT32_C(   172.50),
        SIMDE_FLOAT32_C(   569.77), SIMDE_FLOAT32_C(   123.43), SIMDE_FLOAT32_C(  -563.65), SIMDE_FLOAT32_C(  -201.73),
        SIMDE_FLOAT32_C(   965.31), SIMDE_FLOAT32_C(   668.34), SIMDE_FLOAT32_C(   786.06), SIMDE_FLOAT32_C(  -445.24) } },
    { { SIMDE_FLOAT32_C(   192.68), SIMDE_FLOAT32_C(   186.18), SIMDE_FLOAT32_C(   216.65), SIMDE_FLOAT32_C(  -237.55),
        SIMDE_FLOAT32_C(  -690.39), SIMDE_FLOAT32_C(   653.00), SIMDE_FLOAT32_C(   560.73), SIMDE_FLOAT32_C(  -725.08),
        SIMDE_FLOAT32_C(   321.34), SIMDE_FLOAT32_C(   346.79), SIMDE_FLOAT32_C(  -170.31), SIMDE_FLOAT32_C(  -206.17),
        SIMDE_FLOAT32_C(  -642.64), SIMDE_FLOAT32_C(  -819.87), SIMDE_FLOAT32_C(   101.05), SIMDE_FLOAT32_C(   883.37) },
      UINT8_C(188),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   870.84), SIMDE_FLOAT32_C(   416.42), SIMDE_FLOAT32_C(   758.53),
        SIMDE_FLOAT32_C(   795.54), SIMDE_FLOAT32_C(   145.85), SIMDE_FLOAT32_C(  -978.34), SIMDE_FLOAT32_C(  -262.31),
        SIMDE_FLOAT32_C(  -993.72), SIMDE_FLOAT32_C(  -504.98), SIMDE_FLOAT32_C(   470.22), SIMDE_FLOAT32_C(   942.28),
        SIMDE_FLOAT32_C(  -418.02), SIMDE_FLOAT32_C(   514.37), SIMDE_FLOAT32_C(   134.96), SIMDE_FLOAT32_C(   768.16) },
       INT32_C(          66),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   192.68), SIMDE_FLOAT32_C(   186.18), SIMDE_FLOAT32_C(   416.44), SIMDE_FLOAT32_C(   758.56),
        SIMDE_FLOAT32_C(   795.56), SIMDE_FLOAT32_C(   145.88), SIMDE_FLOAT32_C(   560.73), SIMDE_FLOAT32_C(  -262.25),
        SIMDE_FLOAT32_C(   321.34), SIMDE_FLOAT32_C(   346.79), SIMDE_FLOAT32_C(  -170.31), SIMDE_FLOAT32_C(  -206.17),
        SIMDE_FLOAT32_C(  -642.64), SIMDE_FLOAT32_C(  -819.87), SIMDE_FLOAT32_C(   101.05), SIMDE_FLOAT32_C(   883.37) } },
  };

  simde__m512 src, a, r;

  src = simde_mm512_loadu_ps(test_vec[0].src);
  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[0].k, a, INT32_C(          64), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  src = simde_mm512_loadu_ps(test_vec[1].src);
  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[1].k, a, INT32_C(         177), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  src = simde_mm512_loadu_ps(test_vec[2].src);
  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[2].k, a, INT32_C(         242), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);
  #endif

  src = simde_mm512_loadu_ps(test_vec[3].src);
  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[3].k, a, INT32_C(          83), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  src = simde_mm512_loadu_ps(test_vec[4].src);
  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[4].k, a, INT32_C(         100), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);
  #endif

  src = simde_mm512_loadu_ps(test_vec[5].src);
  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[5].k, a, INT32_C(         240), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  src = simde_mm512_loadu_ps(test_vec[6].src);
  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[6].k, a, INT32_C(          33), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  src = simde_mm512_loadu_ps(test_vec[7].src);
  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_mask_roundscale_round_ps(src, test_vec[7].k, a, INT32_C(          66), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_ps(a, 1, simde_mm512_set1_ps(SIMDE_MATH_NANF));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION: SIMDE_MM_FROUND_NO_EXC;
    simde__m512 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_mask_roundscale_round_ps, r, simde_mm512_setzero_ps(), imm8, sae, src, k, a);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_roundscale_round_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[16];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT8_C(117),
      { SIMDE_FLOAT32_C(  -647.31),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -195.07), SIMDE_FLOAT32_C(   182.38),
        SIMDE_FLOAT32_C(  -500.81), SIMDE_FLOAT32_C(   162.29), SIMDE_FLOAT32_C(   362.51), SIMDE_FLOAT32_C(   600.24),
        SIMDE_FLOAT32_C(    45.66), SIMDE_FLOAT32_C(    18.76), SIMDE_FLOAT32_C(   919.00), SIMDE_FLOAT32_C(   -83.51),
        SIMDE_FLOAT32_C(  -564.82), SIMDE_FLOAT32_C(   677.53), SIMDE_FLOAT32_C(  -287.97), SIMDE_FLOAT32_C(   581.03) },
       INT32_C(         192),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -647.31), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -195.07), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -500.81), SIMDE_FLOAT32_C(   162.29), SIMDE_FLOAT32_C(   362.51), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 15),
      { SIMDE_FLOAT32_C(  -223.80), SIMDE_FLOAT32_C(  -565.68), SIMDE_FLOAT32_C(  -335.46), SIMDE_FLOAT32_C(  -455.64),
        SIMDE_FLOAT32_C(   165.34), SIMDE_FLOAT32_C(  -438.04), SIMDE_FLOAT32_C(  -377.87), SIMDE_FLOAT32_C(   549.36),
        SIMDE_FLOAT32_C(  -979.91), SIMDE_FLOAT32_C(   -25.17), SIMDE_FLOAT32_C(   254.71), SIMDE_FLOAT32_C(  -174.98),
        SIMDE_FLOAT32_C(  -842.79), SIMDE_FLOAT32_C(   753.91), SIMDE_FLOAT32_C(   987.31), SIMDE_FLOAT32_C(   519.72) },
       INT32_C(          65),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -223.81), SIMDE_FLOAT32_C(  -565.69), SIMDE_FLOAT32_C(  -335.50), SIMDE_FLOAT32_C(  -455.69),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 49),
      { SIMDE_FLOAT32_C(   949.46), SIMDE_FLOAT32_C(   -26.34), SIMDE_FLOAT32_C(   -49.32), SIMDE_FLOAT32_C(  -338.51),
        SIMDE_FLOAT32_C(  -445.32), SIMDE_FLOAT32_C(  -350.13), SIMDE_FLOAT32_C(  -888.78), SIMDE_FLOAT32_C(  -858.02),
        SIMDE_FLOAT32_C(  -155.91), SIMDE_FLOAT32_C(    31.16), SIMDE_FLOAT32_C(   671.57), SIMDE_FLOAT32_C(   620.29),
        SIMDE_FLOAT32_C(   465.48), SIMDE_FLOAT32_C(  -663.89), SIMDE_FLOAT32_C(  -835.35), SIMDE_FLOAT32_C(  -369.18) },
       INT32_C(         226),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   949.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -445.32), SIMDE_FLOAT32_C(  -350.13), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(121),
      { SIMDE_FLOAT32_C(   761.61), SIMDE_FLOAT32_C(   434.89), SIMDE_FLOAT32_C(   743.18), SIMDE_FLOAT32_C(   918.82),
        SIMDE_FLOAT32_C(   188.79), SIMDE_FLOAT32_C(   730.49), SIMDE_FLOAT32_C(   438.54), SIMDE_FLOAT32_C(  -457.06),
        SIMDE_FLOAT32_C(  -236.54), SIMDE_FLOAT32_C(   977.01), SIMDE_FLOAT32_C(   816.09), SIMDE_FLOAT32_C(  -287.08),
        SIMDE_FLOAT32_C(   -49.33), SIMDE_FLOAT32_C(  -233.23), SIMDE_FLOAT32_C(   374.41), SIMDE_FLOAT32_C(   505.35) },
       INT32_C(         147),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   761.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   918.82),
        SIMDE_FLOAT32_C(   188.79), SIMDE_FLOAT32_C(   730.49), SIMDE_FLOAT32_C(   438.54), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 82),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   318.90), SIMDE_FLOAT32_C(   881.02), SIMDE_FLOAT32_C(   982.27),
        SIMDE_FLOAT32_C(   655.01), SIMDE_FLOAT32_C(  -954.33), SIMDE_FLOAT32_C(  -386.91), SIMDE_FLOAT32_C(  -446.92),
        SIMDE_FLOAT32_C(  -167.55), SIMDE_FLOAT32_C(  -206.74), SIMDE_FLOAT32_C(   471.24), SIMDE_FLOAT32_C(  -405.94),
        SIMDE_FLOAT32_C(  -771.85), SIMDE_FLOAT32_C(   214.42), SIMDE_FLOAT32_C(  -487.12), SIMDE_FLOAT32_C(   416.95) },
       INT32_C(         180),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   318.90), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   655.01), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -386.91), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(134),
      { SIMDE_FLOAT32_C(   775.97), SIMDE_FLOAT32_C(  -578.72), SIMDE_FLOAT32_C(  -120.90), SIMDE_FLOAT32_C(  -457.26),
        SIMDE_FLOAT32_C(   795.69), SIMDE_FLOAT32_C(  -615.55), SIMDE_FLOAT32_C(   959.38), SIMDE_FLOAT32_C(   281.32),
        SIMDE_FLOAT32_C(  -968.22), SIMDE_FLOAT32_C(  -779.89), SIMDE_FLOAT32_C(   798.10), SIMDE_FLOAT32_C(   350.68),
        SIMDE_FLOAT32_C(  -898.87), SIMDE_FLOAT32_C(   780.37), SIMDE_FLOAT32_C(     5.70), SIMDE_FLOAT32_C(  -853.21) },
       INT32_C(         128),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -578.72), SIMDE_FLOAT32_C(  -120.90), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   281.32),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(160),
      { SIMDE_FLOAT32_C(    30.02), SIMDE_FLOAT32_C(   573.31), SIMDE_FLOAT32_C(   414.88), SIMDE_FLOAT32_C(  -755.56),
        SIMDE_FLOAT32_C(  -913.81), SIMDE_FLOAT32_C(  -168.18), SIMDE_FLOAT32_C(   189.35), SIMDE_FLOAT32_C(  -962.39),
        SIMDE_FLOAT32_C(  -208.29), SIMDE_FLOAT32_C(  -102.29), SIMDE_FLOAT32_C(   966.04), SIMDE_FLOAT32_C(  -432.32),
        SIMDE_FLOAT32_C(   318.99), SIMDE_FLOAT32_C(  -154.87), SIMDE_FLOAT32_C(   110.42), SIMDE_FLOAT32_C(   114.68) },
       INT32_C(          65),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -168.19), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -962.44),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(113),
      { SIMDE_FLOAT32_C(   289.91),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -387.95), SIMDE_FLOAT32_C(   391.04),
        SIMDE_FLOAT32_C(   974.47), SIMDE_FLOAT32_C(   617.75), SIMDE_FLOAT32_C(   537.83), SIMDE_FLOAT32_C(  -632.07),
        SIMDE_FLOAT32_C(   176.52), SIMDE_FLOAT32_C(  -482.92), SIMDE_FLOAT32_C(   554.66), SIMDE_FLOAT32_C(  -793.46),
        SIMDE_FLOAT32_C(  -909.62), SIMDE_FLOAT32_C(   -30.47), SIMDE_FLOAT32_C(  -549.02), SIMDE_FLOAT32_C(  -823.43) },
       INT32_C(         130),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   289.91), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   974.47), SIMDE_FLOAT32_C(   617.75), SIMDE_FLOAT32_C(   537.83), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  simde__m512 a, r;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[0].k, a, INT32_C(         192), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[1].k, a, INT32_C(          65), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[2].k, a, INT32_C(         226), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[3].k, a, INT32_C(         147), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[4].k, a, INT32_C(         180), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[5].k, a, INT32_C(         128), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[6].k, a, INT32_C(          65), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_maskz_roundscale_round_ps(test_vec[7].k, a, INT32_C(         130), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_ps(a, 1, simde_mm512_set1_ps(SIMDE_MATH_NANF));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION: SIMDE_MM_FROUND_NO_EXC;
    simde__m512 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_maskz_roundscale_round_ps, r, simde_mm512_setzero_ps(), imm8, sae, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_roundscale_round_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -764.76), SIMDE_FLOAT64_C(   372.30), SIMDE_FLOAT64_C(  -204.93), SIMDE_FLOAT64_C(   187.19),
        SIMDE_FLOAT64_C(   319.82), SIMDE_FLOAT64_C(  -587.65), SIMDE_FLOAT64_C(  -285.97), SIMDE_FLOAT64_C(  -184.26) },
       INT32_C(         224),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -764.76), SIMDE_FLOAT64_C(   372.30), SIMDE_FLOAT64_C(  -204.93), SIMDE_FLOAT64_C(   187.19),
        SIMDE_FLOAT64_C(   319.82), SIMDE_FLOAT64_C(  -587.65), SIMDE_FLOAT64_C(  -285.97), SIMDE_FLOAT64_C(  -184.26) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -737.42), SIMDE_FLOAT64_C(   189.61), SIMDE_FLOAT64_C(   596.45),
        SIMDE_FLOAT64_C(  -867.46), SIMDE_FLOAT64_C(  -762.70), SIMDE_FLOAT64_C(    52.01), SIMDE_FLOAT64_C(   506.49) },
       INT32_C(         225),
       INT32_C(           8),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -737.42), SIMDE_FLOAT64_C(   189.61), SIMDE_FLOAT64_C(   596.45),
        SIMDE_FLOAT64_C(  -867.46), SIMDE_FLOAT64_C(  -762.70), SIMDE_FLOAT64_C(    52.01), SIMDE_FLOAT64_C(   506.49) } },
    { { SIMDE_FLOAT64_C(  -225.83), SIMDE_FLOAT64_C(   341.08), SIMDE_FLOAT64_C(  -924.52), SIMDE_FLOAT64_C(   659.69),
        SIMDE_FLOAT64_C(   637.52), SIMDE_FLOAT64_C(   570.34), SIMDE_FLOAT64_C(  -794.05), SIMDE_FLOAT64_C(   295.70) },
       INT32_C(         114),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -225.83), SIMDE_FLOAT64_C(   341.09), SIMDE_FLOAT64_C(  -924.52), SIMDE_FLOAT64_C(   659.70),
        SIMDE_FLOAT64_C(   637.52), SIMDE_FLOAT64_C(   570.34), SIMDE_FLOAT64_C(  -794.05), SIMDE_FLOAT64_C(   295.70) } },
    { { SIMDE_FLOAT64_C(    -7.23), SIMDE_FLOAT64_C(  -101.93), SIMDE_FLOAT64_C(  -496.88), SIMDE_FLOAT64_C(   706.80),
        SIMDE_FLOAT64_C(   713.81), SIMDE_FLOAT64_C(    25.71), SIMDE_FLOAT64_C(  -458.99), SIMDE_FLOAT64_C(  -420.32) },
       INT32_C(          35),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(    -7.00), SIMDE_FLOAT64_C(  -101.75), SIMDE_FLOAT64_C(  -496.75), SIMDE_FLOAT64_C(   706.75),
        SIMDE_FLOAT64_C(   713.75), SIMDE_FLOAT64_C(    25.50), SIMDE_FLOAT64_C(  -458.75), SIMDE_FLOAT64_C(  -420.25) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -63.86), SIMDE_FLOAT64_C(  -993.41), SIMDE_FLOAT64_C(   848.39),
        SIMDE_FLOAT64_C(  -557.37), SIMDE_FLOAT64_C(  -180.81), SIMDE_FLOAT64_C(  -935.49), SIMDE_FLOAT64_C(   801.51) },
       INT32_C(         100),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -63.86), SIMDE_FLOAT64_C(  -993.41), SIMDE_FLOAT64_C(   848.39),
        SIMDE_FLOAT64_C(  -557.38), SIMDE_FLOAT64_C(  -180.81), SIMDE_FLOAT64_C(  -935.48), SIMDE_FLOAT64_C(   801.52) } },
    { { SIMDE_FLOAT64_C(  -501.64), SIMDE_FLOAT64_C(  -219.90), SIMDE_FLOAT64_C(  -472.78), SIMDE_FLOAT64_C(  -295.68),
        SIMDE_FLOAT64_C(  -924.20), SIMDE_FLOAT64_C(  -667.20), SIMDE_FLOAT64_C(  -717.43), SIMDE_FLOAT64_C(  -833.43) },
       INT32_C(          48),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -501.62), SIMDE_FLOAT64_C(  -219.88), SIMDE_FLOAT64_C(  -472.75), SIMDE_FLOAT64_C(  -295.62),
        SIMDE_FLOAT64_C(  -924.25), SIMDE_FLOAT64_C(  -667.25), SIMDE_FLOAT64_C(  -717.38), SIMDE_FLOAT64_C(  -833.38) } },
    { { SIMDE_FLOAT64_C(    32.37),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   695.40), SIMDE_FLOAT64_C(   573.38),
        SIMDE_FLOAT64_C(   474.12), SIMDE_FLOAT64_C(  -104.66), SIMDE_FLOAT64_C(  -623.03), SIMDE_FLOAT64_C(   243.41) },
       INT32_C(          33),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(    32.25),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   695.25), SIMDE_FLOAT64_C(   573.25),
        SIMDE_FLOAT64_C(   474.00), SIMDE_FLOAT64_C(  -104.75), SIMDE_FLOAT64_C(  -623.25), SIMDE_FLOAT64_C(   243.25) } },
    { { SIMDE_FLOAT64_C(  -930.80),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   557.24), SIMDE_FLOAT64_C(   -49.40),
        SIMDE_FLOAT64_C(  -556.69), SIMDE_FLOAT64_C(  -300.17), SIMDE_FLOAT64_C(   907.48), SIMDE_FLOAT64_C(   -58.33) },
       INT32_C(         210),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -930.80),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   557.24), SIMDE_FLOAT64_C(   -49.40),
        SIMDE_FLOAT64_C(  -556.69), SIMDE_FLOAT64_C(  -300.17), SIMDE_FLOAT64_C(   907.48), SIMDE_FLOAT64_C(   -58.33) } },
  };

  simde__m512d a, r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(         224), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(         225), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(         114), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(          35), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(         100), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(          48), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(          33), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_roundscale_round_pd(a, INT32_C(         210), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_pd(a, 1, simde_mm512_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m512d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_roundscale_round_pd, r, simde_mm512_setzero_pd(), imm8, sae, a);

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_roundscale_round_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const simde_float64 a[8];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   586.90), SIMDE_FLOAT64_C(  -112.94), SIMDE_FLOAT64_C(  -235.54), SIMDE_FLOAT64_C(   172.88),
        SIMDE_FLOAT64_C(  -277.74), SIMDE_FLOAT64_C(   581.03), SIMDE_FLOAT64_C(   348.44), SIMDE_FLOAT64_C(   605.57) },
      UINT8_C( 95),
      { SIMDE_FLOAT64_C(   311.24),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   137.73), SIMDE_FLOAT64_C(   690.30),
        SIMDE_FLOAT64_C(  -788.97), SIMDE_FLOAT64_C(   105.19), SIMDE_FLOAT64_C(   565.43), SIMDE_FLOAT64_C(   516.54) },
       INT32_C(          16),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   311.00),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   137.50), SIMDE_FLOAT64_C(   690.50),
        SIMDE_FLOAT64_C(  -789.00), SIMDE_FLOAT64_C(   581.03), SIMDE_FLOAT64_C(   565.50), SIMDE_FLOAT64_C(   605.57) } },
    { { SIMDE_FLOAT64_C(  -756.52), SIMDE_FLOAT64_C(   407.18), SIMDE_FLOAT64_C(  -238.43), SIMDE_FLOAT64_C(   978.50),
        SIMDE_FLOAT64_C(   941.71), SIMDE_FLOAT64_C(   783.86), SIMDE_FLOAT64_C(  -197.05), SIMDE_FLOAT64_C(  -143.50) },
      UINT8_C(229),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   743.56), SIMDE_FLOAT64_C(   166.90), SIMDE_FLOAT64_C(   562.73),
        SIMDE_FLOAT64_C(  -534.18), SIMDE_FLOAT64_C(  -252.07), SIMDE_FLOAT64_C(   -88.83), SIMDE_FLOAT64_C(  -928.61) },
       INT32_C(         241),
       INT32_C(           8),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   407.18), SIMDE_FLOAT64_C(   166.90), SIMDE_FLOAT64_C(   978.50),
        SIMDE_FLOAT64_C(   941.71), SIMDE_FLOAT64_C(  -252.07), SIMDE_FLOAT64_C(   -88.83), SIMDE_FLOAT64_C(  -928.61) } },
    { { SIMDE_FLOAT64_C(   912.72), SIMDE_FLOAT64_C(  -558.33), SIMDE_FLOAT64_C(  -448.66), SIMDE_FLOAT64_C(   478.15),
        SIMDE_FLOAT64_C(   958.21), SIMDE_FLOAT64_C(  -141.38), SIMDE_FLOAT64_C(  -216.49), SIMDE_FLOAT64_C(  -842.28) },
      UINT8_C( 29),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -598.80), SIMDE_FLOAT64_C(  -646.62), SIMDE_FLOAT64_C(  -242.27),
        SIMDE_FLOAT64_C(  -620.30), SIMDE_FLOAT64_C(  -704.91), SIMDE_FLOAT64_C(  -458.40), SIMDE_FLOAT64_C(   182.65) },
       INT32_C(           2),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -558.33), SIMDE_FLOAT64_C(  -646.00), SIMDE_FLOAT64_C(  -242.00),
        SIMDE_FLOAT64_C(  -620.00), SIMDE_FLOAT64_C(  -141.38), SIMDE_FLOAT64_C(  -216.49), SIMDE_FLOAT64_C(  -842.28) } },
    { { SIMDE_FLOAT64_C(  -889.06), SIMDE_FLOAT64_C(   135.23), SIMDE_FLOAT64_C(   360.97), SIMDE_FLOAT64_C(  -141.13),
        SIMDE_FLOAT64_C(  -953.60), SIMDE_FLOAT64_C(   432.35), SIMDE_FLOAT64_C(   167.30), SIMDE_FLOAT64_C(  -731.19) },
      UINT8_C(219),
      { SIMDE_FLOAT64_C(  -386.55), SIMDE_FLOAT64_C(  -818.48), SIMDE_FLOAT64_C(  -895.33), SIMDE_FLOAT64_C(   164.80),
        SIMDE_FLOAT64_C(   659.67), SIMDE_FLOAT64_C(  -937.13), SIMDE_FLOAT64_C(  -976.58), SIMDE_FLOAT64_C(  -556.82) },
       INT32_C(         163),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -386.55), SIMDE_FLOAT64_C(  -818.48), SIMDE_FLOAT64_C(   360.97), SIMDE_FLOAT64_C(   164.80),
        SIMDE_FLOAT64_C(   659.67), SIMDE_FLOAT64_C(   432.35), SIMDE_FLOAT64_C(  -976.58), SIMDE_FLOAT64_C(  -556.82) } },
    { { SIMDE_FLOAT64_C(  -378.20), SIMDE_FLOAT64_C(   322.99), SIMDE_FLOAT64_C(   197.08), SIMDE_FLOAT64_C(     1.49),
        SIMDE_FLOAT64_C(   618.08), SIMDE_FLOAT64_C(   738.68), SIMDE_FLOAT64_C(  -815.86), SIMDE_FLOAT64_C(  -230.34) },
      UINT8_C(148),
      { SIMDE_FLOAT64_C(   756.64), SIMDE_FLOAT64_C(   664.81), SIMDE_FLOAT64_C(  -206.35), SIMDE_FLOAT64_C(  -108.13),
        SIMDE_FLOAT64_C(    25.78), SIMDE_FLOAT64_C(   652.52), SIMDE_FLOAT64_C(   -61.74), SIMDE_FLOAT64_C(  -541.86) },
       INT32_C(         132),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -378.20), SIMDE_FLOAT64_C(   322.99), SIMDE_FLOAT64_C(  -206.35), SIMDE_FLOAT64_C(     1.49),
        SIMDE_FLOAT64_C(    25.78), SIMDE_FLOAT64_C(   738.68), SIMDE_FLOAT64_C(  -815.86), SIMDE_FLOAT64_C(  -541.86) } },
    { { SIMDE_FLOAT64_C(   433.27), SIMDE_FLOAT64_C(   388.59), SIMDE_FLOAT64_C(  -774.20), SIMDE_FLOAT64_C(  -401.93),
        SIMDE_FLOAT64_C(    48.26), SIMDE_FLOAT64_C(  -711.33), SIMDE_FLOAT64_C(  -378.51), SIMDE_FLOAT64_C(   491.44) },
      UINT8_C(198),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   930.79), SIMDE_FLOAT64_C(   131.07), SIMDE_FLOAT64_C(   -85.91),
        SIMDE_FLOAT64_C(   127.87), SIMDE_FLOAT64_C(  -867.44), SIMDE_FLOAT64_C(  -467.84), SIMDE_FLOAT64_C(  -133.46) },
       INT32_C(         160),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   433.27), SIMDE_FLOAT64_C(   930.79), SIMDE_FLOAT64_C(   131.07), SIMDE_FLOAT64_C(  -401.93),
        SIMDE_FLOAT64_C(    48.26), SIMDE_FLOAT64_C(  -711.33), SIMDE_FLOAT64_C(  -467.84), SIMDE_FLOAT64_C(  -133.46) } },
    { { SIMDE_FLOAT64_C(   -33.36), SIMDE_FLOAT64_C(  -657.09), SIMDE_FLOAT64_C(   -34.78), SIMDE_FLOAT64_C(   992.42),
        SIMDE_FLOAT64_C(   995.43), SIMDE_FLOAT64_C(   903.48), SIMDE_FLOAT64_C(  -549.44), SIMDE_FLOAT64_C(  -184.75) },
      UINT8_C( 83),
      { SIMDE_FLOAT64_C(  -428.31), SIMDE_FLOAT64_C(  -751.48), SIMDE_FLOAT64_C(  -500.86), SIMDE_FLOAT64_C(  -202.51),
        SIMDE_FLOAT64_C(  -153.40), SIMDE_FLOAT64_C(   547.40), SIMDE_FLOAT64_C(    86.17), SIMDE_FLOAT64_C(   468.08) },
       INT32_C(          81),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -428.31), SIMDE_FLOAT64_C(  -751.50), SIMDE_FLOAT64_C(   -34.78), SIMDE_FLOAT64_C(   992.42),
        SIMDE_FLOAT64_C(  -153.41), SIMDE_FLOAT64_C(   903.48), SIMDE_FLOAT64_C(    86.16), SIMDE_FLOAT64_C(  -184.75) } },
    { { SIMDE_FLOAT64_C(   -30.38), SIMDE_FLOAT64_C(  -273.50), SIMDE_FLOAT64_C(   973.26), SIMDE_FLOAT64_C(  -902.51),
        SIMDE_FLOAT64_C(  -140.94), SIMDE_FLOAT64_C(  -494.57), SIMDE_FLOAT64_C(   -35.97), SIMDE_FLOAT64_C(   175.77) },
      UINT8_C(161),
      { SIMDE_FLOAT64_C(  -486.71), SIMDE_FLOAT64_C(   249.12), SIMDE_FLOAT64_C(  -226.11), SIMDE_FLOAT64_C(  -143.80),
        SIMDE_FLOAT64_C(  -785.67), SIMDE_FLOAT64_C(  -233.68), SIMDE_FLOAT64_C(  -148.38), SIMDE_FLOAT64_C(  -882.19) },
       INT32_C(         210),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -486.71), SIMDE_FLOAT64_C(  -273.50), SIMDE_FLOAT64_C(   973.26), SIMDE_FLOAT64_C(  -902.51),
        SIMDE_FLOAT64_C(  -140.94), SIMDE_FLOAT64_C(  -233.68), SIMDE_FLOAT64_C(   -35.97), SIMDE_FLOAT64_C(  -882.19) } },
  };

  simde__m512d src, a, r;

  src = simde_mm512_loadu_pd(test_vec[0].src);
  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[0].k, a, INT32_C(          16), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  src = simde_mm512_loadu_pd(test_vec[1].src);
  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[1].k, a, INT32_C(         241), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  src = simde_mm512_loadu_pd(test_vec[2].src);
  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[2].k, a, INT32_C(           2), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);
  #endif

  src = simde_mm512_loadu_pd(test_vec[3].src);
  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[3].k, a, INT32_C(         163), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  src = simde_mm512_loadu_pd(test_vec[4].src);
  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[4].k, a, INT32_C(         132), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  src = simde_mm512_loadu_pd(test_vec[5].src);
  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[5].k, a, INT32_C(         160), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  src = simde_mm512_loadu_pd(test_vec[6].src);
  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[6].k, a, INT32_C(          81), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  src = simde_mm512_loadu_pd(test_vec[7].src);
  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_mask_roundscale_round_pd(src, test_vec[7].k, a, INT32_C(         210), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d src = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_pd(a, 1, simde_mm512_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m512d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_mask_roundscale_round_pd, r, simde_mm512_setzero_pd(), imm8, sae, src, k, a);

    simde_test_x86_write_f64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_roundscale_round_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(190),
      { SIMDE_FLOAT64_C(   515.32), SIMDE_FLOAT64_C(    92.71), SIMDE_FLOAT64_C(   -98.65), SIMDE_FLOAT64_C(  -709.07),
        SIMDE_FLOAT64_C(   445.35), SIMDE_FLOAT64_C(  -129.46), SIMDE_FLOAT64_C(   180.22), SIMDE_FLOAT64_C(   747.49) },
       INT32_C(         176),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    92.71), SIMDE_FLOAT64_C(   -98.65), SIMDE_FLOAT64_C(  -709.07),
        SIMDE_FLOAT64_C(   445.35), SIMDE_FLOAT64_C(  -129.46), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   747.49) } },
    { UINT8_C(118),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -392.58), SIMDE_FLOAT64_C(  -387.10), SIMDE_FLOAT64_C(    99.02),
        SIMDE_FLOAT64_C(   596.83), SIMDE_FLOAT64_C(  -871.46), SIMDE_FLOAT64_C(  -220.73), SIMDE_FLOAT64_C(   401.93) },
       INT32_C(         193),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -392.58), SIMDE_FLOAT64_C(  -387.10), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   596.83), SIMDE_FLOAT64_C(  -871.46), SIMDE_FLOAT64_C(  -220.73), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(143),
      { SIMDE_FLOAT64_C(  -975.69), SIMDE_FLOAT64_C(  -293.66), SIMDE_FLOAT64_C(  -314.85), SIMDE_FLOAT64_C(  -720.20),
        SIMDE_FLOAT64_C(   714.21), SIMDE_FLOAT64_C(  -592.83), SIMDE_FLOAT64_C(   795.13), SIMDE_FLOAT64_C(  -193.07) },
       INT32_C(         146),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -975.69), SIMDE_FLOAT64_C(  -293.66), SIMDE_FLOAT64_C(  -314.85), SIMDE_FLOAT64_C(  -720.20),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -193.07) } },
    { UINT8_C( 78),
      { SIMDE_FLOAT64_C(   266.27), SIMDE_FLOAT64_C(   999.77), SIMDE_FLOAT64_C(  -432.85), SIMDE_FLOAT64_C(  -229.42),
        SIMDE_FLOAT64_C(   135.60), SIMDE_FLOAT64_C(  -650.90), SIMDE_FLOAT64_C(   385.97), SIMDE_FLOAT64_C(   743.01) },
       INT32_C(         243),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   999.77), SIMDE_FLOAT64_C(  -432.85), SIMDE_FLOAT64_C(  -229.42),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   385.97), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(153),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -258.22), SIMDE_FLOAT64_C(   643.08), SIMDE_FLOAT64_C(  -777.45),
        SIMDE_FLOAT64_C(   864.04), SIMDE_FLOAT64_C(  -328.14), SIMDE_FLOAT64_C(  -310.52), SIMDE_FLOAT64_C(   888.34) },
       INT32_C(         148),
       INT32_C(           8),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -777.45),
        SIMDE_FLOAT64_C(   864.04), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   888.34) } },
    { UINT8_C(203),
      { SIMDE_FLOAT64_C(   963.27), SIMDE_FLOAT64_C(   899.35), SIMDE_FLOAT64_C(    90.33), SIMDE_FLOAT64_C(  -950.68),
        SIMDE_FLOAT64_C(  -848.37), SIMDE_FLOAT64_C(   269.40), SIMDE_FLOAT64_C(   315.60), SIMDE_FLOAT64_C(  -848.60) },
       INT32_C(           0),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   963.00), SIMDE_FLOAT64_C(   899.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -951.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   316.00), SIMDE_FLOAT64_C(  -849.00) } },
    { UINT8_C(164),
      { SIMDE_FLOAT64_C(   472.15),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   147.65), SIMDE_FLOAT64_C(   957.14),
        SIMDE_FLOAT64_C(  -630.15), SIMDE_FLOAT64_C(  -761.81), SIMDE_FLOAT64_C(   221.41), SIMDE_FLOAT64_C(   111.62) },
       INT32_C(          17),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   147.50), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -762.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   111.50) } },
    { UINT8_C(143),
      { SIMDE_FLOAT64_C(   931.35),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    32.15), SIMDE_FLOAT64_C(    23.77),
        SIMDE_FLOAT64_C(   289.88), SIMDE_FLOAT64_C(    -4.58), SIMDE_FLOAT64_C(   -76.88), SIMDE_FLOAT64_C(  -619.79) },
       INT32_C(          18),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   931.50),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    32.50), SIMDE_FLOAT64_C(    24.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -619.50) } },
  };

  simde__m512d a, r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[0].k, a, INT32_C(         176), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[1].k, a, INT32_C(         193), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[2].k, a, INT32_C(         146), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[3].k, a, INT32_C(         243), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[4].k, a, INT32_C(         148), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[5].k, a, INT32_C(           0), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[6].k, a, INT32_C(          17), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_maskz_roundscale_round_pd(test_vec[7].k, a, INT32_C(          18), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        a = simde_mm512_mask_mov_pd(a, 1, simde_mm512_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(SIMDE_MATH_INFINITY));
        else
          a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m512d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_maskz_roundscale_round_pd, r, simde_mm512_setzero_pd(), imm8, sae, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX_NATIVE))
static int
test_simde_mm_roundscale_round_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   800.62), SIMDE_FLOAT32_C(     5.17), SIMDE_FLOAT32_C(   547.21), SIMDE_FLOAT32_C(   203.23) },
      { SIMDE_FLOAT32_C(  -972.56), SIMDE_FLOAT32_C(  -577.41), SIMDE_FLOAT32_C(   863.22), SIMDE_FLOAT32_C(  -460.21) },
       INT32_C(          48),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -972.50), SIMDE_FLOAT32_C(     5.17), SIMDE_FLOAT32_C(   547.21), SIMDE_FLOAT32_C(   203.23) } },
    { { SIMDE_FLOAT32_C(   180.26), SIMDE_FLOAT32_C(   -68.69), SIMDE_FLOAT32_C(  -107.59), SIMDE_FLOAT32_C(   332.04) },
      { SIMDE_FLOAT32_C(  -720.34), SIMDE_FLOAT32_C(  -229.64), SIMDE_FLOAT32_C(   714.58), SIMDE_FLOAT32_C(  -728.77) },
       INT32_C(          33),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -720.50), SIMDE_FLOAT32_C(   -68.69), SIMDE_FLOAT32_C(  -107.59), SIMDE_FLOAT32_C(   332.04) } },
    { { SIMDE_FLOAT32_C(   440.49), SIMDE_FLOAT32_C(  -146.35), SIMDE_FLOAT32_C(   642.47), SIMDE_FLOAT32_C(   445.00) },
      { SIMDE_FLOAT32_C(   258.97), SIMDE_FLOAT32_C(  -557.60), SIMDE_FLOAT32_C(    27.31), SIMDE_FLOAT32_C(   -55.97) },
       INT32_C(          98),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   258.98), SIMDE_FLOAT32_C(  -146.35), SIMDE_FLOAT32_C(   642.47), SIMDE_FLOAT32_C(   445.00) } },
    { { SIMDE_FLOAT32_C(  -315.92), SIMDE_FLOAT32_C(  -968.83), SIMDE_FLOAT32_C(   976.63), SIMDE_FLOAT32_C(   106.67) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -483.58), SIMDE_FLOAT32_C(    91.58), SIMDE_FLOAT32_C(  -501.75) },
       INT32_C(         131),
       INT32_C(           4),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -968.83), SIMDE_FLOAT32_C(   976.63), SIMDE_FLOAT32_C(   106.67) } },
    { { SIMDE_FLOAT32_C(   709.22), SIMDE_FLOAT32_C(  -852.46), SIMDE_FLOAT32_C(   318.46), SIMDE_FLOAT32_C(   980.46) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -335.06), SIMDE_FLOAT32_C(  -155.61), SIMDE_FLOAT32_C(  -166.44) },
       INT32_C(         132),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -852.46), SIMDE_FLOAT32_C(   318.46), SIMDE_FLOAT32_C(   980.46) } },
    { { SIMDE_FLOAT32_C(   -70.75), SIMDE_FLOAT32_C(   305.87), SIMDE_FLOAT32_C(   721.59), SIMDE_FLOAT32_C(  -933.87) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   670.79), SIMDE_FLOAT32_C(  -249.78), SIMDE_FLOAT32_C(  -835.03) },
       INT32_C(         160),
       INT32_C(           8),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   305.87), SIMDE_FLOAT32_C(   721.59), SIMDE_FLOAT32_C(  -933.87) } },
    { { SIMDE_FLOAT32_C(  -442.39), SIMDE_FLOAT32_C(  -351.39), SIMDE_FLOAT32_C(   220.31), SIMDE_FLOAT32_C(   987.17) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -175.80), SIMDE_FLOAT32_C(   696.40), SIMDE_FLOAT32_C(  -826.66) },
       INT32_C(          65),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -351.39), SIMDE_FLOAT32_C(   220.31), SIMDE_FLOAT32_C(   987.17) } },
    { { SIMDE_FLOAT32_C(  -478.76), SIMDE_FLOAT32_C(  -600.03), SIMDE_FLOAT32_C(  -673.80), SIMDE_FLOAT32_C(     8.09) },
      { SIMDE_FLOAT32_C(  -321.46), SIMDE_FLOAT32_C(   103.77), SIMDE_FLOAT32_C(   937.35), SIMDE_FLOAT32_C(   984.41) },
       INT32_C(         146),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -321.46), SIMDE_FLOAT32_C(  -600.03), SIMDE_FLOAT32_C(  -673.80), SIMDE_FLOAT32_C(     8.09) } },
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(          48), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(          33), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(          98), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(         131), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(         132), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(         160), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(          65), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_roundscale_round_ss(a, b, INT32_C(         146), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m128 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_roundscale_round_ss, r, simde_mm_setzero_ps(), imm8, sae, a, b);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_roundscale_round_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -901.37), SIMDE_FLOAT32_C(   991.78), SIMDE_FLOAT32_C(  -993.88), SIMDE_FLOAT32_C(   421.48) },
      UINT8_C(125),
      { SIMDE_FLOAT32_C(   705.11), SIMDE_FLOAT32_C(  -569.84), SIMDE_FLOAT32_C(  -299.64), SIMDE_FLOAT32_C(  -705.39) },
      { SIMDE_FLOAT32_C(   431.44), SIMDE_FLOAT32_C(   682.16), SIMDE_FLOAT32_C(   342.34), SIMDE_FLOAT32_C(  -645.40) },
       INT32_C(         160),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   431.44), SIMDE_FLOAT32_C(  -569.84), SIMDE_FLOAT32_C(  -299.64), SIMDE_FLOAT32_C(  -705.39) } },
    { { SIMDE_FLOAT32_C(   935.70), SIMDE_FLOAT32_C(   772.61), SIMDE_FLOAT32_C(  -364.40), SIMDE_FLOAT32_C(   382.32) },
      UINT8_C(218),
      { SIMDE_FLOAT32_C(   -42.14), SIMDE_FLOAT32_C(   962.15), SIMDE_FLOAT32_C(   558.00), SIMDE_FLOAT32_C(   190.11) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   104.40), SIMDE_FLOAT32_C(   182.55), SIMDE_FLOAT32_C(   334.92) },
       INT32_C(          33),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   935.70), SIMDE_FLOAT32_C(   962.15), SIMDE_FLOAT32_C(   558.00), SIMDE_FLOAT32_C(   190.11) } },
    { { SIMDE_FLOAT32_C(    53.35), SIMDE_FLOAT32_C(  -144.97), SIMDE_FLOAT32_C(   718.45), SIMDE_FLOAT32_C(  -241.54) },
      UINT8_C(243),
      { SIMDE_FLOAT32_C(  -581.19), SIMDE_FLOAT32_C(    53.08), SIMDE_FLOAT32_C(  -283.38), SIMDE_FLOAT32_C(  -899.03) },
      { SIMDE_FLOAT32_C(  -604.58), SIMDE_FLOAT32_C(    71.23), SIMDE_FLOAT32_C(   989.92), SIMDE_FLOAT32_C(  -662.30) },
       INT32_C(          66),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -604.56), SIMDE_FLOAT32_C(    53.08), SIMDE_FLOAT32_C(  -283.38), SIMDE_FLOAT32_C(  -899.03) } },
    { { SIMDE_FLOAT32_C(  -529.80), SIMDE_FLOAT32_C(   307.93), SIMDE_FLOAT32_C(  -992.43), SIMDE_FLOAT32_C(   428.06) },
      UINT8_C( 78),
      { SIMDE_FLOAT32_C(   565.57), SIMDE_FLOAT32_C(  -381.83), SIMDE_FLOAT32_C(     4.93), SIMDE_FLOAT32_C(  -330.03) },
      { SIMDE_FLOAT32_C(   800.71), SIMDE_FLOAT32_C(  -660.15), SIMDE_FLOAT32_C(  -384.42), SIMDE_FLOAT32_C(  -152.05) },
       INT32_C(         211),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -529.80), SIMDE_FLOAT32_C(  -381.83), SIMDE_FLOAT32_C(     4.93), SIMDE_FLOAT32_C(  -330.03) } },
    { { SIMDE_FLOAT32_C(  -371.56), SIMDE_FLOAT32_C(  -728.57), SIMDE_FLOAT32_C(  -340.23), SIMDE_FLOAT32_C(   913.62) },
      UINT8_C( 96),
      { SIMDE_FLOAT32_C(   712.85), SIMDE_FLOAT32_C(  -369.75), SIMDE_FLOAT32_C(  -208.79), SIMDE_FLOAT32_C(  -891.73) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -218.88), SIMDE_FLOAT32_C(  -554.03), SIMDE_FLOAT32_C(   536.07) },
       INT32_C(         116),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -371.56), SIMDE_FLOAT32_C(  -369.75), SIMDE_FLOAT32_C(  -208.79), SIMDE_FLOAT32_C(  -891.73) } },
    { { SIMDE_FLOAT32_C(  -436.15), SIMDE_FLOAT32_C(   434.32), SIMDE_FLOAT32_C(   284.76), SIMDE_FLOAT32_C(  -870.58) },
      UINT8_C( 55),
      { SIMDE_FLOAT32_C(  -710.31), SIMDE_FLOAT32_C(  -200.61), SIMDE_FLOAT32_C(   853.20), SIMDE_FLOAT32_C(  -370.45) },
      { SIMDE_FLOAT32_C(   414.97), SIMDE_FLOAT32_C(  -298.84), SIMDE_FLOAT32_C(  -597.05), SIMDE_FLOAT32_C(   967.94) },
       INT32_C(           0),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   415.00), SIMDE_FLOAT32_C(  -200.61), SIMDE_FLOAT32_C(   853.20), SIMDE_FLOAT32_C(  -370.45) } },
    { { SIMDE_FLOAT32_C(   262.23), SIMDE_FLOAT32_C(   -54.99), SIMDE_FLOAT32_C(   -70.40), SIMDE_FLOAT32_C(   -24.92) },
      UINT8_C(133),
      { SIMDE_FLOAT32_C(   720.81), SIMDE_FLOAT32_C(    83.35), SIMDE_FLOAT32_C(   276.74), SIMDE_FLOAT32_C(  -498.07) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -187.19), SIMDE_FLOAT32_C(   208.67), SIMDE_FLOAT32_C(  -914.41) },
       INT32_C(         113),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    83.35), SIMDE_FLOAT32_C(   276.74), SIMDE_FLOAT32_C(  -498.07) } },
    { { SIMDE_FLOAT32_C(  -491.89), SIMDE_FLOAT32_C(  -221.14), SIMDE_FLOAT32_C(  -694.11), SIMDE_FLOAT32_C(  -202.20) },
      UINT8_C( 29),
      { SIMDE_FLOAT32_C(  -840.90), SIMDE_FLOAT32_C(   427.35), SIMDE_FLOAT32_C(    -6.78), SIMDE_FLOAT32_C(  -139.75) },
      { SIMDE_FLOAT32_C(   830.30), SIMDE_FLOAT32_C(   -38.84), SIMDE_FLOAT32_C(   462.72), SIMDE_FLOAT32_C(  -138.30) },
       INT32_C(         114),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   830.30), SIMDE_FLOAT32_C(   427.35), SIMDE_FLOAT32_C(    -6.78), SIMDE_FLOAT32_C(  -139.75) } },
  };

  simde__m128 src, a, b, r;

  src = simde_mm_loadu_ps(test_vec[0].src);
  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[0].k, a, b, INT32_C(         160), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  src = simde_mm_loadu_ps(test_vec[1].src);
  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[1].k, a, b, INT32_C(          33), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  src = simde_mm_loadu_ps(test_vec[2].src);
  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[2].k, a, b, INT32_C(          66), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  src = simde_mm_loadu_ps(test_vec[3].src);
  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[3].k, a, b, INT32_C(         211), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  src = simde_mm_loadu_ps(test_vec[4].src);
  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[4].k, a, b, INT32_C(         116), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  src = simde_mm_loadu_ps(test_vec[5].src);
  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[5].k, a, b, INT32_C(           0), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  src = simde_mm_loadu_ps(test_vec[6].src);
  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[6].k, a, b, INT32_C(         113), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);
  #endif

  src = simde_mm_loadu_ps(test_vec[7].src);
  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_mask_roundscale_round_ss(src, test_vec[7].k, a, b, INT32_C(         114), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m128 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_mask_roundscale_round_ss, r, simde_mm_setzero_ps(), imm8, sae, src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_round_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const int32_t sae;
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(128),
      { SIMDE_FLOAT32_C(   700.03), SIMDE_FLOAT32_C(   381.97), SIMDE_FLOAT32_C(   850.94), SIMDE_FLOAT32_C(  -216.62) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -647.13), SIMDE_FLOAT32_C(  -687.31), SIMDE_FLOAT32_C(   471.52) },
       INT32_C(           0),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   381.97), SIMDE_FLOAT32_C(   850.94), SIMDE_FLOAT32_C(  -216.62) } },
    { UINT8_C( 36),
      { SIMDE_FLOAT32_C(  -456.00), SIMDE_FLOAT32_C(   293.00), SIMDE_FLOAT32_C(   826.59), SIMDE_FLOAT32_C(  -150.11) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   404.84), SIMDE_FLOAT32_C(     8.98), SIMDE_FLOAT32_C(   518.15) },
       INT32_C(          97),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   293.00), SIMDE_FLOAT32_C(   826.59), SIMDE_FLOAT32_C(  -150.11) } },
    { UINT8_C( 80),
      { SIMDE_FLOAT32_C(  -789.85), SIMDE_FLOAT32_C(  -440.26), SIMDE_FLOAT32_C(  -943.10), SIMDE_FLOAT32_C(  -983.14) },
      { SIMDE_FLOAT32_C(  -310.13), SIMDE_FLOAT32_C(   756.93), SIMDE_FLOAT32_C(   398.83), SIMDE_FLOAT32_C(  -459.18) },
       INT32_C(           2),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -440.26), SIMDE_FLOAT32_C(  -943.10), SIMDE_FLOAT32_C(  -983.14) } },
    { UINT8_C(  2),
      { SIMDE_FLOAT32_C(   529.06), SIMDE_FLOAT32_C(  -544.76), SIMDE_FLOAT32_C(   251.28), SIMDE_FLOAT32_C(   819.65) },
      { SIMDE_FLOAT32_C(   240.13), SIMDE_FLOAT32_C(  -700.99), SIMDE_FLOAT32_C(  -636.35), SIMDE_FLOAT32_C(  -466.87) },
       INT32_C(          83),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -544.76), SIMDE_FLOAT32_C(   251.28), SIMDE_FLOAT32_C(   819.65) } },
    { UINT8_C(253),
      { SIMDE_FLOAT32_C(  -777.48), SIMDE_FLOAT32_C(  -857.91), SIMDE_FLOAT32_C(   928.50), SIMDE_FLOAT32_C(  -908.25) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   287.72), SIMDE_FLOAT32_C(   423.71), SIMDE_FLOAT32_C(   700.70) },
       INT32_C(         180),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -857.91), SIMDE_FLOAT32_C(   928.50), SIMDE_FLOAT32_C(  -908.25) } },
    { UINT8_C(193),
      { SIMDE_FLOAT32_C(   116.39), SIMDE_FLOAT32_C(    78.15), SIMDE_FLOAT32_C(   777.83), SIMDE_FLOAT32_C(   173.93) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -369.17), SIMDE_FLOAT32_C(  -297.02), SIMDE_FLOAT32_C(  -572.92) },
       INT32_C(         128),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    78.15), SIMDE_FLOAT32_C(   777.83), SIMDE_FLOAT32_C(   173.93) } },
    { UINT8_C(155),
      { SIMDE_FLOAT32_C(  -799.66), SIMDE_FLOAT32_C(  -693.28), SIMDE_FLOAT32_C(  -900.19), SIMDE_FLOAT32_C(  -175.72) },
      { SIMDE_FLOAT32_C(   837.16), SIMDE_FLOAT32_C(  -677.67), SIMDE_FLOAT32_C(   -33.63), SIMDE_FLOAT32_C(   765.66) },
       INT32_C(         241),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   837.16), SIMDE_FLOAT32_C(  -693.28), SIMDE_FLOAT32_C(  -900.19), SIMDE_FLOAT32_C(  -175.72) } },
    { UINT8_C( 22),
      { SIMDE_FLOAT32_C(  -842.39), SIMDE_FLOAT32_C(   -99.15), SIMDE_FLOAT32_C(   318.40), SIMDE_FLOAT32_C(   875.17) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -444.07), SIMDE_FLOAT32_C(    -8.44), SIMDE_FLOAT32_C(  -483.66) },
       INT32_C(          50),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -99.15), SIMDE_FLOAT32_C(   318.40), SIMDE_FLOAT32_C(   875.17) } },
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[0].k, a, b, INT32_C(           0), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[1].k, a, b, INT32_C(          97), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[2].k, a, b, INT32_C(           2), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[3].k, a, b, INT32_C(          83), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[4].k, a, b, INT32_C(         180), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[5].k, a, b, INT32_C(         128), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[6].k, a, b, INT32_C(         241), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_maskz_roundscale_round_ss(test_vec[7].k, a, b, INT32_C(          50), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_CUR_DIRECTION : SIMDE_MM_FROUND_NO_EXC;
    simde__m128 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_maskz_roundscale_round_ss, r, simde_mm_setzero_ps(), imm8, sae, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_roundscale_round_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -922.84), SIMDE_FLOAT64_C(   174.41) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -819.78) },
       INT32_C(          64),
       INT32_C(           8),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   174.41) } },
    { { SIMDE_FLOAT64_C(  -239.65), SIMDE_FLOAT64_C(  -886.64) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -376.97) },
       INT32_C(          97),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -886.64) } },
    { { SIMDE_FLOAT64_C(   481.56), SIMDE_FLOAT64_C(  -294.29) },
      { SIMDE_FLOAT64_C(   -38.63), SIMDE_FLOAT64_C(   396.57) },
       INT32_C(         210),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   -38.63), SIMDE_FLOAT64_C(  -294.29) } },
    { { SIMDE_FLOAT64_C(   243.93), SIMDE_FLOAT64_C(   311.65) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   681.34) },
       INT32_C(          19),
       INT32_C(           8),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   311.65) } },
    { { SIMDE_FLOAT64_C(  -476.93), SIMDE_FLOAT64_C(   188.19) },
      { SIMDE_FLOAT64_C(   352.72), SIMDE_FLOAT64_C(  -296.71) },
       INT32_C(          84),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   352.72), SIMDE_FLOAT64_C(   188.19) } },
    { { SIMDE_FLOAT64_C(  -150.31), SIMDE_FLOAT64_C(   102.87) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   796.03) },
       INT32_C(         240),
       INT32_C(           4),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   102.87) } },
    { { SIMDE_FLOAT64_C(   614.65), SIMDE_FLOAT64_C(  -800.95) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    11.22) },
       INT32_C(          33),
       INT32_C(           8),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -800.95) } },
    { { SIMDE_FLOAT64_C(  -451.36), SIMDE_FLOAT64_C(  -912.02) },
      { SIMDE_FLOAT64_C(  -391.41), SIMDE_FLOAT64_C(    -5.45) },
       INT32_C(         162),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -391.41), SIMDE_FLOAT64_C(  -912.02) } },
  };

  simde__m128d a, b, r;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(          64), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(          97), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(         210), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(          19), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(          84), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(         240), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(          33), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_roundscale_round_sd(a, b, INT32_C(         162), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_roundscale_round_sd, r, simde_mm_setzero_pd(), imm8, sae, a, b);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_roundscale_round_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   874.86), SIMDE_FLOAT64_C(   394.65) },
      UINT8_C( 58),
      { SIMDE_FLOAT64_C(   201.75), SIMDE_FLOAT64_C(   815.04) },
      { SIMDE_FLOAT64_C(  -159.78), SIMDE_FLOAT64_C(   969.89) },
       INT32_C(         128),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   874.86), SIMDE_FLOAT64_C(   815.04) } },
    { { SIMDE_FLOAT64_C(  -740.35), SIMDE_FLOAT64_C(  -485.55) },
      UINT8_C( 56),
      { SIMDE_FLOAT64_C(   387.51), SIMDE_FLOAT64_C(  -803.37) },
      { SIMDE_FLOAT64_C(  -180.68), SIMDE_FLOAT64_C(  -444.72) },
       INT32_C(          17),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -740.35), SIMDE_FLOAT64_C(  -803.37) } },
    { { SIMDE_FLOAT64_C(  -952.30), SIMDE_FLOAT64_C(   509.81) },
      UINT8_C(124),
      { SIMDE_FLOAT64_C(  -488.08), SIMDE_FLOAT64_C(  -565.90) },
      { SIMDE_FLOAT64_C(   427.29), SIMDE_FLOAT64_C(   560.52) },
       INT32_C(         194),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -952.30), SIMDE_FLOAT64_C(  -565.90) } },
    { { SIMDE_FLOAT64_C(  -643.85), SIMDE_FLOAT64_C(   123.00) },
      UINT8_C(217),
      { SIMDE_FLOAT64_C(   346.67), SIMDE_FLOAT64_C(  -675.25) },
      { SIMDE_FLOAT64_C(   842.99), SIMDE_FLOAT64_C(  -813.12) },
       INT32_C(          67),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   842.94), SIMDE_FLOAT64_C(  -675.25) } },
    { { SIMDE_FLOAT64_C(  -850.89), SIMDE_FLOAT64_C(   -19.24) },
      UINT8_C(208),
      { SIMDE_FLOAT64_C(  -410.70), SIMDE_FLOAT64_C(  -631.73) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   408.62) },
       INT32_C(          20),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -850.89), SIMDE_FLOAT64_C(  -631.73) } },
    { { SIMDE_FLOAT64_C(  -431.37), SIMDE_FLOAT64_C(   805.13) },
      UINT8_C(  6),
      { SIMDE_FLOAT64_C(    80.55), SIMDE_FLOAT64_C(  -760.78) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -358.93) },
       INT32_C(         160),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -431.37), SIMDE_FLOAT64_C(  -760.78) } },
    { { SIMDE_FLOAT64_C(   302.34), SIMDE_FLOAT64_C(  -502.96) },
      UINT8_C(109),
      { SIMDE_FLOAT64_C(   145.33), SIMDE_FLOAT64_C(  -316.07) },
      { SIMDE_FLOAT64_C(   771.91), SIMDE_FLOAT64_C(   866.44) },
       INT32_C(         113),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   771.91), SIMDE_FLOAT64_C(  -316.07) } },
    { { SIMDE_FLOAT64_C(  -661.10), SIMDE_FLOAT64_C(  -489.68) },
      UINT8_C( 18),
      { SIMDE_FLOAT64_C(  -379.76), SIMDE_FLOAT64_C(   918.95) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   141.17) },
       INT32_C(         242),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -661.10), SIMDE_FLOAT64_C(   918.95) } },
  };

  simde__m128d src, a, b, r;

  src = simde_mm_loadu_pd(test_vec[0].src);
  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[0].k, a, b, INT32_C(         128), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  src = simde_mm_loadu_pd(test_vec[1].src);
  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[1].k, a, b, INT32_C(          17), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  src = simde_mm_loadu_pd(test_vec[2].src);
  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[2].k, a, b, INT32_C(         194), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  src = simde_mm_loadu_pd(test_vec[3].src);
  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[3].k, a, b, INT32_C(          67), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  src = simde_mm_loadu_pd(test_vec[4].src);
  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[4].k, a, b, INT32_C(          20), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  src = simde_mm_loadu_pd(test_vec[5].src);
  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[5].k, a, b, INT32_C(         160), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  src = simde_mm_loadu_pd(test_vec[6].src);
  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[6].k, a, b, INT32_C(         113), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  src = simde_mm_loadu_pd(test_vec[7].src);
  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_mask_roundscale_round_sd(src, test_vec[7].k, a, b, INT32_C(         242), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_mask_roundscale_round_sd, r, simde_mm_setzero_pd(), imm8, sae, src, k, a, b);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_round_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const int32_t sae;
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C( 24),
      { SIMDE_FLOAT64_C(   182.09), SIMDE_FLOAT64_C(  -254.56) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -862.84) },
       INT32_C(         208),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -254.56) } },
    { UINT8_C(155),
      { SIMDE_FLOAT64_C(  -276.68), SIMDE_FLOAT64_C(  -318.19) },
      { SIMDE_FLOAT64_C(   579.53), SIMDE_FLOAT64_C(   929.18) },
       INT32_C(          97),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   579.52), SIMDE_FLOAT64_C(  -318.19) } },
    { UINT8_C( 46),
      { SIMDE_FLOAT64_C(   499.87), SIMDE_FLOAT64_C(  -856.43) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   509.56) },
       INT32_C(         210),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -856.43) } },
    { UINT8_C(127),
      { SIMDE_FLOAT64_C(   171.29), SIMDE_FLOAT64_C(  -814.14) },
      { SIMDE_FLOAT64_C(  -592.15), SIMDE_FLOAT64_C(  -646.63) },
       INT32_C(           3),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -592.00), SIMDE_FLOAT64_C(  -814.14) } },
    { UINT8_C(  4),
      { SIMDE_FLOAT64_C(   426.00), SIMDE_FLOAT64_C(   297.22) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   827.55) },
       INT32_C(         100),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   297.22) } },
    { UINT8_C( 33),
      { SIMDE_FLOAT64_C(   318.40), SIMDE_FLOAT64_C(     7.60) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -181.73) },
       INT32_C(          64),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     7.60) } },
    { UINT8_C(188),
      { SIMDE_FLOAT64_C(  -686.65), SIMDE_FLOAT64_C(   152.96) },
      { SIMDE_FLOAT64_C(   752.21), SIMDE_FLOAT64_C(  -604.31) },
       INT32_C(         161),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   152.96) } },
    { UINT8_C(182),
      { SIMDE_FLOAT64_C(  -130.62), SIMDE_FLOAT64_C(   -92.45) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -441.39) },
       INT32_C(          66),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -92.45) } },
  };

  simde__m128d a, b, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[0].k, a, b, INT32_C(         208), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[1].k, a, b, INT32_C(          97), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[2].k, a, b, INT32_C(         210), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[3].k, a, b, INT32_C(           3), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[4].k, a, b, INT32_C(         100), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[5].k, a, b, INT32_C(          64), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[6].k, a, b, INT32_C(         161), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_maskz_roundscale_round_sd(test_vec[7].k, a, b, INT32_C(          66), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    int sae = (simde_test_codegen_rand() & 1) ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_maskz_roundscale_round_sd, r, simde_mm_setzero_pd(), imm8, sae, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_roundscale_round_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_roundscale_round_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_roundscale_round_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_roundscale_round_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_roundscale_round_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_roundscale_round_pd)
  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX_NATIVE))
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_round_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_round_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_round_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_round_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_round_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_round_sd)
  #endif
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
