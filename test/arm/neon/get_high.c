#define SIMDE_TEST_ARM_NEON_INSN get_high

#include "test-neon.h"
#include "../../../simde/arm/neon/get_high.h"

static int
test_simde_vget_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   441.00), SIMDE_FLOAT16_VALUE(   861.50), SIMDE_FLOAT16_VALUE(    98.06), SIMDE_FLOAT16_VALUE(   896.00),
        SIMDE_FLOAT16_VALUE(  -918.50), SIMDE_FLOAT16_VALUE(  -717.00), SIMDE_FLOAT16_VALUE(  -823.00), SIMDE_FLOAT16_VALUE(  -581.00) },
      { SIMDE_FLOAT16_VALUE(  -918.50), SIMDE_FLOAT16_VALUE(  -717.00), SIMDE_FLOAT16_VALUE(  -823.00), SIMDE_FLOAT16_VALUE(  -581.00) } },
    { { SIMDE_FLOAT16_VALUE(    -6.45), SIMDE_FLOAT16_VALUE(    29.20), SIMDE_FLOAT16_VALUE(  -856.00), SIMDE_FLOAT16_VALUE(   267.25),
        SIMDE_FLOAT16_VALUE(  -302.00), SIMDE_FLOAT16_VALUE(   526.50), SIMDE_FLOAT16_VALUE(   713.00), SIMDE_FLOAT16_VALUE(   -14.83) },
      { SIMDE_FLOAT16_VALUE(  -302.00), SIMDE_FLOAT16_VALUE(   526.50), SIMDE_FLOAT16_VALUE(   713.00), SIMDE_FLOAT16_VALUE(   -14.83) } },
    { { SIMDE_FLOAT16_VALUE(   909.00), SIMDE_FLOAT16_VALUE(  -475.75), SIMDE_FLOAT16_VALUE(   269.75), SIMDE_FLOAT16_VALUE(   991.00),
        SIMDE_FLOAT16_VALUE(  -192.62), SIMDE_FLOAT16_VALUE(   446.50), SIMDE_FLOAT16_VALUE(  -590.00), SIMDE_FLOAT16_VALUE(  -508.50) },
      { SIMDE_FLOAT16_VALUE(  -192.62), SIMDE_FLOAT16_VALUE(   446.50), SIMDE_FLOAT16_VALUE(  -590.00), SIMDE_FLOAT16_VALUE(  -508.50) } },
    { { SIMDE_FLOAT16_VALUE(   121.69), SIMDE_FLOAT16_VALUE(    14.28), SIMDE_FLOAT16_VALUE(   545.00), SIMDE_FLOAT16_VALUE(   819.50),
        SIMDE_FLOAT16_VALUE(  -459.00), SIMDE_FLOAT16_VALUE(   258.50), SIMDE_FLOAT16_VALUE(  -195.12), SIMDE_FLOAT16_VALUE(  -307.00) },
      { SIMDE_FLOAT16_VALUE(  -459.00), SIMDE_FLOAT16_VALUE(   258.50), SIMDE_FLOAT16_VALUE(  -195.12), SIMDE_FLOAT16_VALUE(  -307.00) } },
    { { SIMDE_FLOAT16_VALUE(   918.00), SIMDE_FLOAT16_VALUE(   650.00), SIMDE_FLOAT16_VALUE(    80.00), SIMDE_FLOAT16_VALUE(  -275.00),
        SIMDE_FLOAT16_VALUE(    96.56), SIMDE_FLOAT16_VALUE(   489.75), SIMDE_FLOAT16_VALUE(   216.50), SIMDE_FLOAT16_VALUE(  -894.00) },
      { SIMDE_FLOAT16_VALUE(    96.56), SIMDE_FLOAT16_VALUE(   489.75), SIMDE_FLOAT16_VALUE(   216.50), SIMDE_FLOAT16_VALUE(  -894.00) } },
    { { SIMDE_FLOAT16_VALUE(  -108.69), SIMDE_FLOAT16_VALUE(  -977.50), SIMDE_FLOAT16_VALUE(   -44.56), SIMDE_FLOAT16_VALUE(   432.25),
        SIMDE_FLOAT16_VALUE(   281.00), SIMDE_FLOAT16_VALUE(   760.00), SIMDE_FLOAT16_VALUE(  -874.50), SIMDE_FLOAT16_VALUE(  -645.00) },
      { SIMDE_FLOAT16_VALUE(   281.00), SIMDE_FLOAT16_VALUE(   760.00), SIMDE_FLOAT16_VALUE(  -874.50), SIMDE_FLOAT16_VALUE(  -645.00) } },
    { { SIMDE_FLOAT16_VALUE(   392.00), SIMDE_FLOAT16_VALUE(  -758.50), SIMDE_FLOAT16_VALUE(  -870.50), SIMDE_FLOAT16_VALUE(  -511.25),
        SIMDE_FLOAT16_VALUE(   731.50), SIMDE_FLOAT16_VALUE(   345.75), SIMDE_FLOAT16_VALUE(  -405.25), SIMDE_FLOAT16_VALUE(  -353.75) },
      { SIMDE_FLOAT16_VALUE(   731.50), SIMDE_FLOAT16_VALUE(   345.75), SIMDE_FLOAT16_VALUE(  -405.25), SIMDE_FLOAT16_VALUE(  -353.75) } },
    { { SIMDE_FLOAT16_VALUE(   345.75), SIMDE_FLOAT16_VALUE(   372.75), SIMDE_FLOAT16_VALUE(   802.50), SIMDE_FLOAT16_VALUE(  -373.00),
        SIMDE_FLOAT16_VALUE(   133.12), SIMDE_FLOAT16_VALUE(   928.00), SIMDE_FLOAT16_VALUE(   -18.17), SIMDE_FLOAT16_VALUE(  -974.50) },
      { SIMDE_FLOAT16_VALUE(   133.12), SIMDE_FLOAT16_VALUE(   928.00), SIMDE_FLOAT16_VALUE(   -18.17), SIMDE_FLOAT16_VALUE(  -974.50) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a;
    simde_float16x4_t r;

    a = simde_vld1q_f16(test_vec[i].a);
    r = simde_vget_high_f16(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vget_high_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -342.02), SIMDE_FLOAT32_C(  -700.14), SIMDE_FLOAT32_C(   232.12), SIMDE_FLOAT32_C(  -101.83) },
      { SIMDE_FLOAT32_C(   232.12), SIMDE_FLOAT32_C(  -101.83) } },
    { { SIMDE_FLOAT32_C(  -988.11), SIMDE_FLOAT32_C(   147.79), SIMDE_FLOAT32_C(   871.85), SIMDE_FLOAT32_C(  -252.38) },
      { SIMDE_FLOAT32_C(   871.85), SIMDE_FLOAT32_C(  -252.38) } },
    { { SIMDE_FLOAT32_C(   182.44), SIMDE_FLOAT32_C(   926.75), SIMDE_FLOAT32_C(  -990.47), SIMDE_FLOAT32_C(  -507.70) },
      { SIMDE_FLOAT32_C(  -990.47), SIMDE_FLOAT32_C(  -507.70) } },
    { { SIMDE_FLOAT32_C(  -332.88), SIMDE_FLOAT32_C(   248.48), SIMDE_FLOAT32_C(   962.27), SIMDE_FLOAT32_C(   190.23) },
      { SIMDE_FLOAT32_C(   962.27), SIMDE_FLOAT32_C(   190.23) } },
    { { SIMDE_FLOAT32_C(   530.12), SIMDE_FLOAT32_C(  -559.75), SIMDE_FLOAT32_C(   -68.78), SIMDE_FLOAT32_C(  -625.03) },
      { SIMDE_FLOAT32_C(   -68.78), SIMDE_FLOAT32_C(  -625.03) } },
    { { SIMDE_FLOAT32_C(  -696.26), SIMDE_FLOAT32_C(   343.99), SIMDE_FLOAT32_C(   875.39), SIMDE_FLOAT32_C(   507.32) },
      { SIMDE_FLOAT32_C(   875.39), SIMDE_FLOAT32_C(   507.32) } },
    { { SIMDE_FLOAT32_C(  -239.21), SIMDE_FLOAT32_C(   714.53), SIMDE_FLOAT32_C(  -233.95), SIMDE_FLOAT32_C(    96.87) },
      { SIMDE_FLOAT32_C(  -233.95), SIMDE_FLOAT32_C(    96.87) } },
    { { SIMDE_FLOAT32_C(   751.96), SIMDE_FLOAT32_C(  -235.16), SIMDE_FLOAT32_C(  -766.29), SIMDE_FLOAT32_C(  -590.06) },
      { SIMDE_FLOAT32_C(  -766.29), SIMDE_FLOAT32_C(  -590.06) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a;
    simde_float32x2_t r;

    a = simde_vld1q_f32(test_vec[i].a);
    r = simde_vget_high_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vget_high_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[2];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -496.87), SIMDE_FLOAT64_C(  -513.71) },
      { SIMDE_FLOAT64_C(  -513.71) } },
    { { SIMDE_FLOAT64_C(   305.86), SIMDE_FLOAT64_C(   676.57) },
      { SIMDE_FLOAT64_C(   676.57) } },
    { { SIMDE_FLOAT64_C(   -67.25), SIMDE_FLOAT64_C(  -986.11) },
      { SIMDE_FLOAT64_C(  -986.11) } },
    { { SIMDE_FLOAT64_C(   582.35), SIMDE_FLOAT64_C(   984.12) },
      { SIMDE_FLOAT64_C(   984.12) } },
    { { SIMDE_FLOAT64_C(  -936.12), SIMDE_FLOAT64_C(  -999.04) },
      { SIMDE_FLOAT64_C(  -999.04) } },
    { { SIMDE_FLOAT64_C(  -427.34), SIMDE_FLOAT64_C(   114.37) },
      { SIMDE_FLOAT64_C(   114.37) } },
    { { SIMDE_FLOAT64_C(  -340.67), SIMDE_FLOAT64_C(   719.32) },
      { SIMDE_FLOAT64_C(   719.32) } },
    { { SIMDE_FLOAT64_C(  -609.36), SIMDE_FLOAT64_C(  -653.25) },
      { SIMDE_FLOAT64_C(  -653.25) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vget_high_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t r = simde_vget_high_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(   2), -INT8_C( 102), -INT8_C(  10), -INT8_C(  48), -INT8_C( 126), -INT8_C(  61),  INT8_C(  29),  INT8_C(  91),
        -INT8_C(  59), -INT8_C(   8),  INT8_C(  97),  INT8_C(  27), -INT8_C( 101),  INT8_C(  40), -INT8_C(   4),  INT8_C(  34) },
      { -INT8_C(  59), -INT8_C(   8),  INT8_C(  97),  INT8_C(  27), -INT8_C( 101),  INT8_C(  40), -INT8_C(   4),  INT8_C(  34) } },
    { { -INT8_C( 127), -INT8_C(  21), -INT8_C(  97), -INT8_C(   6),  INT8_C(  83),  INT8_C(  58), -INT8_C( 124), -INT8_C(   3),
         INT8_C( 103),  INT8_C(  78), -INT8_C(  13), -INT8_C(  42), -INT8_C(  66),  INT8_C(  46),  INT8_C(  62), -INT8_C(  64) },
      {  INT8_C( 103),  INT8_C(  78), -INT8_C(  13), -INT8_C(  42), -INT8_C(  66),  INT8_C(  46),  INT8_C(  62), -INT8_C(  64) } },
    { { -INT8_C(  56),  INT8_C(  52), -INT8_C( 112),  INT8_C(  74), -INT8_C(   9), -INT8_C(  83), -INT8_C(  90), -INT8_C(  68),
        -INT8_C(  91),  INT8_C(   7), -INT8_C(  41),  INT8_C(  64),  INT8_C(  47), -INT8_C(  44),  INT8_C(  98), -INT8_C(  79) },
      { -INT8_C(  91),  INT8_C(   7), -INT8_C(  41),  INT8_C(  64),  INT8_C(  47), -INT8_C(  44),  INT8_C(  98), -INT8_C(  79) } },
    { { -INT8_C(  65),  INT8_C(   1), -INT8_C(  85),  INT8_C(  18),  INT8_C(  60),  INT8_C(  47),  INT8_C(  15), -INT8_C(  93),
         INT8_C( 126),  INT8_C(   3),  INT8_C( 121),  INT8_C(  60),  INT8_C(  49), -INT8_C(  73), -INT8_C(   3), -INT8_C(   6) },
      {  INT8_C( 126),  INT8_C(   3),  INT8_C( 121),  INT8_C(  60),  INT8_C(  49), -INT8_C(  73), -INT8_C(   3), -INT8_C(   6) } },
    { { -INT8_C(  21), -INT8_C( 115),  INT8_C(  68), -INT8_C(  29),  INT8_C(  59), -INT8_C(  22), -INT8_C(  97), -INT8_C(  32),
        -INT8_C(  14),  INT8_C( 119),  INT8_C(  33),  INT8_C(  33),  INT8_C(  75), -INT8_C( 125), -INT8_C(  46),  INT8_C(  10) },
      { -INT8_C(  14),  INT8_C( 119),  INT8_C(  33),  INT8_C(  33),  INT8_C(  75), -INT8_C( 125), -INT8_C(  46),  INT8_C(  10) } },
    { { -INT8_C( 123),  INT8_C( 126),  INT8_C(  29), -INT8_C(  63), -INT8_C(  83),  INT8_C(  44),  INT8_C( 100),  INT8_C(  43),
         INT8_C(  47), -INT8_C(  35),  INT8_C( 104),  INT8_C(  97), -INT8_C( 108),  INT8_C( 101),  INT8_C(  91),      INT8_MAX },
      {  INT8_C(  47), -INT8_C(  35),  INT8_C( 104),  INT8_C(  97), -INT8_C( 108),  INT8_C( 101),  INT8_C(  91),      INT8_MAX } },
    { { -INT8_C(  14), -INT8_C(  97),  INT8_C(  98),  INT8_C(  45), -INT8_C( 118),  INT8_C(   2),  INT8_C(  14),  INT8_C( 124),
         INT8_C( 121),  INT8_C(  47), -INT8_C(  99), -INT8_C(  60), -INT8_C(  78),  INT8_C( 112), -INT8_C(  50),  INT8_C(  55) },
      {  INT8_C( 121),  INT8_C(  47), -INT8_C(  99), -INT8_C(  60), -INT8_C(  78),  INT8_C( 112), -INT8_C(  50),  INT8_C(  55) } },
    { { -INT8_C(  18), -INT8_C(  21), -INT8_C(   8), -INT8_C( 101),  INT8_C(  24),  INT8_C(  92), -INT8_C(  57),  INT8_C(  71),
         INT8_C(  57),  INT8_C(  47), -INT8_C(  88), -INT8_C(  51), -INT8_C( 108),  INT8_C(   3),  INT8_C(  77), -INT8_C( 122) },
      {  INT8_C(  57),  INT8_C(  47), -INT8_C(  88), -INT8_C(  51), -INT8_C( 108),  INT8_C(   3),  INT8_C(  77), -INT8_C( 122) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vget_high_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x8_t r = simde_vget_high_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(  1812), -INT16_C( 24453),  INT16_C(  7401),  INT16_C(  2904), -INT16_C( 25876),  INT16_C(  9993),  INT16_C( 30955), -INT16_C(  5514) },
      { -INT16_C( 25876),  INT16_C(  9993),  INT16_C( 30955), -INT16_C(  5514) } },
    { {  INT16_C( 16302),  INT16_C( 17547), -INT16_C( 23755),  INT16_C(  8407),  INT16_C( 14448),  INT16_C( 24177), -INT16_C( 17721), -INT16_C( 19647) },
      {  INT16_C( 14448),  INT16_C( 24177), -INT16_C( 17721), -INT16_C( 19647) } },
    { { -INT16_C( 17230), -INT16_C( 25773), -INT16_C( 21288), -INT16_C( 15193), -INT16_C( 20410),  INT16_C( 12780),  INT16_C( 25129), -INT16_C( 10468) },
      { -INT16_C( 20410),  INT16_C( 12780),  INT16_C( 25129), -INT16_C( 10468) } },
    { { -INT16_C( 22622), -INT16_C( 10469), -INT16_C(  3509), -INT16_C( 17416),  INT16_C( 26923), -INT16_C(  3559),  INT16_C( 23075), -INT16_C( 10587) },
      {  INT16_C( 26923), -INT16_C(  3559),  INT16_C( 23075), -INT16_C( 10587) } },
    { { -INT16_C(  2026), -INT16_C(  4239),  INT16_C(  6308), -INT16_C(  5453), -INT16_C( 24631), -INT16_C(  3556),  INT16_C( 14338), -INT16_C( 23351) },
      { -INT16_C( 24631), -INT16_C(  3556),  INT16_C( 14338), -INT16_C( 23351) } },
    { { -INT16_C(  6945),  INT16_C( 10875),  INT16_C( 29655),  INT16_C(   742), -INT16_C(    35),  INT16_C(   244), -INT16_C( 26278),  INT16_C( 28886) },
      { -INT16_C(    35),  INT16_C(   244), -INT16_C( 26278),  INT16_C( 28886) } },
    { {  INT16_C( 18577),  INT16_C( 13919),  INT16_C(  4960),  INT16_C( 10528),  INT16_C( 15538), -INT16_C( 19429), -INT16_C(  7052),  INT16_C( 21592) },
      {  INT16_C( 15538), -INT16_C( 19429), -INT16_C(  7052),  INT16_C( 21592) } },
    { { -INT16_C( 11063), -INT16_C( 24450),  INT16_C( 25671),  INT16_C(  9378), -INT16_C( 27036), -INT16_C( 16859), -INT16_C(  1233), -INT16_C( 16338) },
      { -INT16_C( 27036), -INT16_C( 16859), -INT16_C(  1233), -INT16_C( 16338) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vget_high_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t r = simde_vget_high_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1476397000),  INT32_C(   461227151), -INT32_C(   799969980),  INT32_C(  1647228559) },
      { -INT32_C(   799969980),  INT32_C(  1647228559) } },
    { {  INT32_C(  1924220388), -INT32_C(   255827408), -INT32_C(  2021250903), -INT32_C(  1104113530) },
      { -INT32_C(  2021250903), -INT32_C(  1104113530) } },
    { {  INT32_C(   392573064),  INT32_C(   942924788), -INT32_C(   536247216),  INT32_C(   524433211) },
      { -INT32_C(   536247216),  INT32_C(   524433211) } },
    { { -INT32_C(  1382878083), -INT32_C(     6401450),  INT32_C(     8856698),  INT32_C(  1019197364) },
      {  INT32_C(     8856698),  INT32_C(  1019197364) } },
    { { -INT32_C(   615242265),  INT32_C(  1494517512),  INT32_C(  1178148107), -INT32_C(   781812908) },
      {  INT32_C(  1178148107), -INT32_C(   781812908) } },
    { { -INT32_C(   981469073), -INT32_C(   976937654), -INT32_C(   171619263), -INT32_C(   349076477) },
      { -INT32_C(   171619263), -INT32_C(   349076477) } },
    { { -INT32_C(  1295612503),  INT32_C(   403429900),  INT32_C(  1281246455),  INT32_C(   790480063) },
      {  INT32_C(  1281246455),  INT32_C(   790480063) } },
    { {  INT32_C(   133471420), -INT32_C(    87246407),  INT32_C(   166695173), -INT32_C(  1074519786) },
      {  INT32_C(   166695173), -INT32_C(  1074519786) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x2_t r = simde_vget_high_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t r = simde_vget_high_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 8232078131339440910),  INT64_C( 6335349853300599597) },
      {  INT64_C( 6335349853300599597) } },
    { {  INT64_C( 1363296497143073401), -INT64_C(  845722348049157190) },
      { -INT64_C(  845722348049157190) } },
    { {  INT64_C( 8704551305794192305), -INT64_C( 4365535833137767693) },
      { -INT64_C( 4365535833137767693) } },
    { {  INT64_C( 5390133175935445707), -INT64_C( 3584049339885700787) },
      { -INT64_C( 3584049339885700787) } },
    { {  INT64_C(  228796346852526185),  INT64_C(  973200018634097012) },
      {  INT64_C(  973200018634097012) } },
    { {  INT64_C( 1622867932244095146),  INT64_C( 8663420517885487182) },
      {  INT64_C( 8663420517885487182) } },
    { { -INT64_C( 7709220138856396560),  INT64_C( 4929987596782868763) },
      {  INT64_C( 4929987596782868763) } },
    { {  INT64_C( 1649728995198906885), -INT64_C( 2183193650073023956) },
      { -INT64_C( 2183193650073023956) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x1_t r = simde_vget_high_s64(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x1_t r = simde_vget_high_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(178), UINT8_C(229), UINT8_C(135), UINT8_C( 25), UINT8_C(212), UINT8_C( 46), UINT8_C(139), UINT8_C( 16),
        UINT8_C(223), UINT8_C(251), UINT8_C(  3), UINT8_C( 69), UINT8_C(221), UINT8_C(253), UINT8_C(220), UINT8_C(144) },
      { UINT8_C(223), UINT8_C(251), UINT8_C(  3), UINT8_C( 69), UINT8_C(221), UINT8_C(253), UINT8_C(220), UINT8_C(144) } },
    { { UINT8_C(214), UINT8_C( 35), UINT8_C( 37), UINT8_C( 87), UINT8_C( 39), UINT8_C( 45), UINT8_C(138), UINT8_C(244),
        UINT8_C(191), UINT8_C(175), UINT8_C(236), UINT8_C(166), UINT8_C(250), UINT8_C( 50), UINT8_C(230), UINT8_C(172) },
      { UINT8_C(191), UINT8_C(175), UINT8_C(236), UINT8_C(166), UINT8_C(250), UINT8_C( 50), UINT8_C(230), UINT8_C(172) } },
    { { UINT8_C( 23), UINT8_C(110), UINT8_C(198), UINT8_C(235), UINT8_C(156), UINT8_C( 81), UINT8_C(251), UINT8_C(123),
        UINT8_C( 76), UINT8_C(254), UINT8_C(193), UINT8_C( 41), UINT8_C(251), UINT8_C(157), UINT8_C(185), UINT8_C(209) },
      { UINT8_C( 76), UINT8_C(254), UINT8_C(193), UINT8_C( 41), UINT8_C(251), UINT8_C(157), UINT8_C(185), UINT8_C(209) } },
    { { UINT8_C(192), UINT8_C(222), UINT8_C( 41), UINT8_C(232), UINT8_C( 12), UINT8_C(179), UINT8_C(220), UINT8_C(203),
        UINT8_C( 98), UINT8_C(201), UINT8_C(114), UINT8_C( 92), UINT8_C(251), UINT8_C( 88), UINT8_C(  9), UINT8_C( 18) },
      { UINT8_C( 98), UINT8_C(201), UINT8_C(114), UINT8_C( 92), UINT8_C(251), UINT8_C( 88), UINT8_C(  9), UINT8_C( 18) } },
    { { UINT8_C(198), UINT8_C(207), UINT8_C(253), UINT8_C( 99), UINT8_C( 32), UINT8_C(248), UINT8_C(222), UINT8_C(109),
        UINT8_C(246), UINT8_C(159), UINT8_C(150), UINT8_C(242), UINT8_C( 61), UINT8_C( 80), UINT8_C(195), UINT8_C(253) },
      { UINT8_C(246), UINT8_C(159), UINT8_C(150), UINT8_C(242), UINT8_C( 61), UINT8_C( 80), UINT8_C(195), UINT8_C(253) } },
    { { UINT8_C( 46), UINT8_C(236), UINT8_C(229), UINT8_C( 58), UINT8_C(159), UINT8_C(194), UINT8_C(  6), UINT8_C(  2),
        UINT8_C(139), UINT8_C(120), UINT8_C( 94), UINT8_C(134), UINT8_C(208), UINT8_C(103), UINT8_C(152), UINT8_C(151) },
      { UINT8_C(139), UINT8_C(120), UINT8_C( 94), UINT8_C(134), UINT8_C(208), UINT8_C(103), UINT8_C(152), UINT8_C(151) } },
    { { UINT8_C( 54), UINT8_C(149), UINT8_C(250), UINT8_C( 87), UINT8_C(141), UINT8_C(216), UINT8_C(196), UINT8_C(131),
        UINT8_C(120), UINT8_C( 90), UINT8_C(117), UINT8_C(181), UINT8_C(170), UINT8_C( 57), UINT8_C(178), UINT8_C(217) },
      { UINT8_C(120), UINT8_C( 90), UINT8_C(117), UINT8_C(181), UINT8_C(170), UINT8_C( 57), UINT8_C(178), UINT8_C(217) } },
    { { UINT8_C( 37), UINT8_C(152), UINT8_C( 19), UINT8_C(197), UINT8_C( 90), UINT8_C( 25), UINT8_C(199), UINT8_C(229),
        UINT8_C(145), UINT8_C( 37), UINT8_C(107), UINT8_C( 98), UINT8_C(141), UINT8_C(  3), UINT8_C(249), UINT8_C(195) },
      { UINT8_C(145), UINT8_C( 37), UINT8_C(107), UINT8_C( 98), UINT8_C(141), UINT8_C(  3), UINT8_C(249), UINT8_C(195) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x8_t r = simde_vget_high_u8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x8_t r = simde_vget_high_u8(a);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(22920), UINT16_C(63569), UINT16_C(23914), UINT16_C(54594), UINT16_C(62338), UINT16_C(64225), UINT16_C(22481), UINT16_C(21359) },
      { UINT16_C(62338), UINT16_C(64225), UINT16_C(22481), UINT16_C(21359) } },
    { { UINT16_C(33438), UINT16_C( 1944), UINT16_C(21841), UINT16_C(28692), UINT16_C(13996), UINT16_C(  156), UINT16_C(50690), UINT16_C(35674) },
      { UINT16_C(13996), UINT16_C(  156), UINT16_C(50690), UINT16_C(35674) } },
    { { UINT16_C(43808), UINT16_C(35459), UINT16_C(50697), UINT16_C(35679), UINT16_C(16569), UINT16_C(35462), UINT16_C(62871), UINT16_C(14046) },
      { UINT16_C(16569), UINT16_C(35462), UINT16_C(62871), UINT16_C(14046) } },
    { { UINT16_C(30327), UINT16_C(51261), UINT16_C(21195), UINT16_C(30521), UINT16_C(54664), UINT16_C(35447), UINT16_C(53659), UINT16_C(47893) },
      { UINT16_C(54664), UINT16_C(35447), UINT16_C(53659), UINT16_C(47893) } },
    { { UINT16_C(39293), UINT16_C(34373), UINT16_C(42079), UINT16_C( 6161), UINT16_C(38885), UINT16_C(31906), UINT16_C(32909), UINT16_C( 1202) },
      { UINT16_C(38885), UINT16_C(31906), UINT16_C(32909), UINT16_C( 1202) } },
    { { UINT16_C(61686), UINT16_C(49613), UINT16_C( 1602), UINT16_C(51768), UINT16_C(45019), UINT16_C(30292), UINT16_C(27265), UINT16_C(65074) },
      { UINT16_C(45019), UINT16_C(30292), UINT16_C(27265), UINT16_C(65074) } },
    { { UINT16_C(30467), UINT16_C(25220), UINT16_C(38172), UINT16_C(  378), UINT16_C( 7213), UINT16_C(47741), UINT16_C(12445), UINT16_C(37822) },
      { UINT16_C( 7213), UINT16_C(47741), UINT16_C(12445), UINT16_C(37822) } },
    { { UINT16_C(35616), UINT16_C(25173), UINT16_C(36241), UINT16_C(27692), UINT16_C(32829), UINT16_C(48867), UINT16_C( 5610), UINT16_C(60860) },
      { UINT16_C(32829), UINT16_C(48867), UINT16_C( 5610), UINT16_C(60860) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x4_t r = simde_vget_high_u16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x4_t r = simde_vget_high_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(1465259434), UINT32_C(1475338349), UINT32_C(3977679886), UINT32_C( 955184875) },
      { UINT32_C(3977679886), UINT32_C( 955184875) } },
    { { UINT32_C(2946554281), UINT32_C(1420591641), UINT32_C(3404329444), UINT32_C(3586975531) },
      { UINT32_C(3404329444), UINT32_C(3586975531) } },
    { { UINT32_C(1781343229), UINT32_C( 297933827), UINT32_C(2617170096), UINT32_C(2027154895) },
      { UINT32_C(2617170096), UINT32_C(2027154895) } },
    { { UINT32_C(3760747718), UINT32_C(3660895478), UINT32_C(4037287365), UINT32_C(  46559493) },
      { UINT32_C(4037287365), UINT32_C(  46559493) } },
    { { UINT32_C(2540499860), UINT32_C(3232247311), UINT32_C(3596330759), UINT32_C(1515073428) },
      { UINT32_C(3596330759), UINT32_C(1515073428) } },
    { { UINT32_C(2570745507), UINT32_C( 276000330), UINT32_C(2432702604), UINT32_C( 496223881) },
      { UINT32_C(2432702604), UINT32_C( 496223881) } },
    { { UINT32_C(3384082361), UINT32_C( 898194478), UINT32_C(2534138883), UINT32_C(3069335827) },
      { UINT32_C(2534138883), UINT32_C(3069335827) } },
    { { UINT32_C( 441396432), UINT32_C( 657114011), UINT32_C(1689791451), UINT32_C(2877377521) },
      { UINT32_C(1689791451), UINT32_C(2877377521) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x2_t r = simde_vget_high_u32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x2_t r = simde_vget_high_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(18392422304141364762), UINT64_C( 9553571390305685699) },
      { UINT64_C( 9553571390305685699) } },
    { { UINT64_C(10478824778783513736), UINT64_C( 8371460922054141089) },
      { UINT64_C( 8371460922054141089) } },
    { { UINT64_C( 4924723027677183669), UINT64_C( 8972535995333597553) },
      { UINT64_C( 8972535995333597553) } },
    { { UINT64_C( 6621385167040051125), UINT64_C( 1915813679545843143) },
      { UINT64_C( 1915813679545843143) } },
    { { UINT64_C(  763865471240075477), UINT64_C( 7715948976478543268) },
      { UINT64_C( 7715948976478543268) } },
    { { UINT64_C( 3754490732107106821), UINT64_C( 8006533284254532510) },
      { UINT64_C( 8006533284254532510) } },
    { { UINT64_C(18376479074412695395), UINT64_C(11771472225186025531) },
      { UINT64_C(11771472225186025531) } },
    { { UINT64_C( 6401441061383838005), UINT64_C( 8919791479167855808) },
      { UINT64_C( 8919791479167855808) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x1_t r = simde_vget_high_u64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x1_t r = simde_vget_high_u64(a);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[16];
    simde_poly8_t r[8];
  } test_vec[] = {
    { { SIMDE_POLY8_C(178), SIMDE_POLY8_C(229), SIMDE_POLY8_C(135), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(212), SIMDE_POLY8_C( 46), SIMDE_POLY8_C(139), SIMDE_POLY8_C( 16),
        SIMDE_POLY8_C(223), SIMDE_POLY8_C(251), SIMDE_POLY8_C(  3), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(221), SIMDE_POLY8_C(253), SIMDE_POLY8_C(220), SIMDE_POLY8_C(144) },
      { SIMDE_POLY8_C(223), SIMDE_POLY8_C(251), SIMDE_POLY8_C(  3), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(221), SIMDE_POLY8_C(253), SIMDE_POLY8_C(220), SIMDE_POLY8_C(144) } },
    { { SIMDE_POLY8_C(214), SIMDE_POLY8_C( 35), SIMDE_POLY8_C( 37), SIMDE_POLY8_C( 87), SIMDE_POLY8_C( 39), SIMDE_POLY8_C( 45), SIMDE_POLY8_C(138), SIMDE_POLY8_C(244),
        SIMDE_POLY8_C(191), SIMDE_POLY8_C(175), SIMDE_POLY8_C(236), SIMDE_POLY8_C(166), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(230), SIMDE_POLY8_C(172) },
      { SIMDE_POLY8_C(191), SIMDE_POLY8_C(175), SIMDE_POLY8_C(236), SIMDE_POLY8_C(166), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(230), SIMDE_POLY8_C(172) } },
    { { SIMDE_POLY8_C( 23), SIMDE_POLY8_C(110), SIMDE_POLY8_C(198), SIMDE_POLY8_C(235), SIMDE_POLY8_C(156), SIMDE_POLY8_C( 81), SIMDE_POLY8_C(251), SIMDE_POLY8_C(123),
        SIMDE_POLY8_C( 76), SIMDE_POLY8_C(254), SIMDE_POLY8_C(193), SIMDE_POLY8_C( 41), SIMDE_POLY8_C(251), SIMDE_POLY8_C(157), SIMDE_POLY8_C(185), SIMDE_POLY8_C(209) },
      { SIMDE_POLY8_C( 76), SIMDE_POLY8_C(254), SIMDE_POLY8_C(193), SIMDE_POLY8_C( 41), SIMDE_POLY8_C(251), SIMDE_POLY8_C(157), SIMDE_POLY8_C(185), SIMDE_POLY8_C(209) } },
    { { SIMDE_POLY8_C(192), SIMDE_POLY8_C(222), SIMDE_POLY8_C( 41), SIMDE_POLY8_C(232), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(179), SIMDE_POLY8_C(220), SIMDE_POLY8_C(203),
        SIMDE_POLY8_C( 98), SIMDE_POLY8_C(201), SIMDE_POLY8_C(114), SIMDE_POLY8_C( 92), SIMDE_POLY8_C(251), SIMDE_POLY8_C( 88), SIMDE_POLY8_C(  9), SIMDE_POLY8_C( 18) },
      { SIMDE_POLY8_C( 98), SIMDE_POLY8_C(201), SIMDE_POLY8_C(114), SIMDE_POLY8_C( 92), SIMDE_POLY8_C(251), SIMDE_POLY8_C( 88), SIMDE_POLY8_C(  9), SIMDE_POLY8_C( 18) } },
    { { SIMDE_POLY8_C(198), SIMDE_POLY8_C(207), SIMDE_POLY8_C(253), SIMDE_POLY8_C( 99), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(248), SIMDE_POLY8_C(222), SIMDE_POLY8_C(109),
        SIMDE_POLY8_C(246), SIMDE_POLY8_C(159), SIMDE_POLY8_C(150), SIMDE_POLY8_C(242), SIMDE_POLY8_C( 61), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(195), SIMDE_POLY8_C(253) },
      { SIMDE_POLY8_C(246), SIMDE_POLY8_C(159), SIMDE_POLY8_C(150), SIMDE_POLY8_C(242), SIMDE_POLY8_C( 61), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(195), SIMDE_POLY8_C(253) } },
    { { SIMDE_POLY8_C( 46), SIMDE_POLY8_C(236), SIMDE_POLY8_C(229), SIMDE_POLY8_C( 58), SIMDE_POLY8_C(159), SIMDE_POLY8_C(194), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(  2),
        SIMDE_POLY8_C(139), SIMDE_POLY8_C(120), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(134), SIMDE_POLY8_C(208), SIMDE_POLY8_C(103), SIMDE_POLY8_C(152), SIMDE_POLY8_C(151) },
      { SIMDE_POLY8_C(139), SIMDE_POLY8_C(120), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(134), SIMDE_POLY8_C(208), SIMDE_POLY8_C(103), SIMDE_POLY8_C(152), SIMDE_POLY8_C(151) } },
    { { SIMDE_POLY8_C( 54), SIMDE_POLY8_C(149), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(141), SIMDE_POLY8_C(216), SIMDE_POLY8_C(196), SIMDE_POLY8_C(131),
        SIMDE_POLY8_C(120), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(117), SIMDE_POLY8_C(181), SIMDE_POLY8_C(170), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(178), SIMDE_POLY8_C(217) },
      { SIMDE_POLY8_C(120), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(117), SIMDE_POLY8_C(181), SIMDE_POLY8_C(170), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(178), SIMDE_POLY8_C(217) } },
    { { SIMDE_POLY8_C( 37), SIMDE_POLY8_C(152), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(197), SIMDE_POLY8_C( 90), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(199), SIMDE_POLY8_C(229),
        SIMDE_POLY8_C(145), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(107), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(141), SIMDE_POLY8_C(  3), SIMDE_POLY8_C(249), SIMDE_POLY8_C(195) },
      { SIMDE_POLY8_C(145), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(107), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(141), SIMDE_POLY8_C(  3), SIMDE_POLY8_C(249), SIMDE_POLY8_C(195) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    simde_poly8x8_t r = simde_vget_high_p8(a);

    simde_test_arm_neon_assert_equal_p8x8(r, simde_vld1_p8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x16_t a = simde_test_arm_neon_random_p8x16();
    simde_poly8x8_t r = simde_vget_high_p8(a);

    simde_test_arm_neon_write_p8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[8];
    simde_poly16_t r[4];
  } test_vec[] = {
    { { SIMDE_POLY16_C(22920), SIMDE_POLY16_C(63569), SIMDE_POLY16_C(23914), SIMDE_POLY16_C(54594), SIMDE_POLY16_C(62338), SIMDE_POLY16_C(64225), SIMDE_POLY16_C(22481), SIMDE_POLY16_C(21359) },
      { SIMDE_POLY16_C(62338), SIMDE_POLY16_C(64225), SIMDE_POLY16_C(22481), SIMDE_POLY16_C(21359) } },
    { { SIMDE_POLY16_C(33438), SIMDE_POLY16_C( 1944), SIMDE_POLY16_C(21841), SIMDE_POLY16_C(28692), SIMDE_POLY16_C(13996), SIMDE_POLY16_C(  156), SIMDE_POLY16_C(50690), SIMDE_POLY16_C(35674) },
      { SIMDE_POLY16_C(13996), SIMDE_POLY16_C(  156), SIMDE_POLY16_C(50690), SIMDE_POLY16_C(35674) } },
    { { SIMDE_POLY16_C(43808), SIMDE_POLY16_C(35459), SIMDE_POLY16_C(50697), SIMDE_POLY16_C(35679), SIMDE_POLY16_C(16569), SIMDE_POLY16_C(35462), SIMDE_POLY16_C(62871), SIMDE_POLY16_C(14046) },
      { SIMDE_POLY16_C(16569), SIMDE_POLY16_C(35462), SIMDE_POLY16_C(62871), SIMDE_POLY16_C(14046) } },
    { { SIMDE_POLY16_C(30327), SIMDE_POLY16_C(51261), SIMDE_POLY16_C(21195), SIMDE_POLY16_C(30521), SIMDE_POLY16_C(54664), SIMDE_POLY16_C(35447), SIMDE_POLY16_C(53659), SIMDE_POLY16_C(47893) },
      { SIMDE_POLY16_C(54664), SIMDE_POLY16_C(35447), SIMDE_POLY16_C(53659), SIMDE_POLY16_C(47893) } },
    { { SIMDE_POLY16_C(39293), SIMDE_POLY16_C(34373), SIMDE_POLY16_C(42079), SIMDE_POLY16_C( 6161), SIMDE_POLY16_C(38885), SIMDE_POLY16_C(31906), SIMDE_POLY16_C(32909), SIMDE_POLY16_C( 1202) },
      { SIMDE_POLY16_C(38885), SIMDE_POLY16_C(31906), SIMDE_POLY16_C(32909), SIMDE_POLY16_C( 1202) } },
    { { SIMDE_POLY16_C(61686), SIMDE_POLY16_C(49613), SIMDE_POLY16_C( 1602), SIMDE_POLY16_C(51768), SIMDE_POLY16_C(45019), SIMDE_POLY16_C(30292), SIMDE_POLY16_C(27265), SIMDE_POLY16_C(65074) },
      { SIMDE_POLY16_C(45019), SIMDE_POLY16_C(30292), SIMDE_POLY16_C(27265), SIMDE_POLY16_C(65074) } },
    { { SIMDE_POLY16_C(30467), SIMDE_POLY16_C(25220), SIMDE_POLY16_C(38172), SIMDE_POLY16_C(  378), SIMDE_POLY16_C( 7213), SIMDE_POLY16_C(47741), SIMDE_POLY16_C(12445), SIMDE_POLY16_C(37822) },
      { SIMDE_POLY16_C( 7213), SIMDE_POLY16_C(47741), SIMDE_POLY16_C(12445), SIMDE_POLY16_C(37822) } },
    { { SIMDE_POLY16_C(35616), SIMDE_POLY16_C(25173), SIMDE_POLY16_C(36241), SIMDE_POLY16_C(27692), SIMDE_POLY16_C(32829), SIMDE_POLY16_C(48867), SIMDE_POLY16_C( 5610), SIMDE_POLY16_C(60860) },
      { SIMDE_POLY16_C(32829), SIMDE_POLY16_C(48867), SIMDE_POLY16_C( 5610), SIMDE_POLY16_C(60860) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    simde_poly16x4_t r = simde_vget_high_p16(a);
    simde_test_arm_neon_assert_equal_p16x4(r, simde_vld1_p16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8_t a = simde_test_arm_neon_random_p16x8();
    simde_poly16x4_t r = simde_vget_high_p16(a);

    simde_test_arm_neon_write_p16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly64_t a[2];
    simde_poly64_t r[1];
  } test_vec[] = {
    { { SIMDE_POLY64_C(18392422304141364762), SIMDE_POLY64_C( 9553571390305685699) },
      { SIMDE_POLY64_C( 9553571390305685699) } },
    { { SIMDE_POLY64_C(10478824778783513736), SIMDE_POLY64_C( 8371460922054141089) },
      { SIMDE_POLY64_C( 8371460922054141089) } },
    { { SIMDE_POLY64_C( 4924723027677183669), SIMDE_POLY64_C( 8972535995333597553) },
      { SIMDE_POLY64_C( 8972535995333597553) } },
    { { SIMDE_POLY64_C( 6621385167040051125), SIMDE_POLY64_C( 1915813679545843143) },
      { SIMDE_POLY64_C( 1915813679545843143) } },
    { { SIMDE_POLY64_C(  763865471240075477), SIMDE_POLY64_C( 7715948976478543268) },
      { SIMDE_POLY64_C( 7715948976478543268) } },
    { { SIMDE_POLY64_C( 3754490732107106821), SIMDE_POLY64_C( 8006533284254532510) },
      { SIMDE_POLY64_C( 8006533284254532510) } },
    { { SIMDE_POLY64_C(18376479074412695395), SIMDE_POLY64_C(11771472225186025531) },
      { SIMDE_POLY64_C(11771472225186025531) } },
    { { SIMDE_POLY64_C( 6401441061383838005), SIMDE_POLY64_C( 8919791479167855808) },
      { SIMDE_POLY64_C( 8919791479167855808) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2_t a = simde_vld1q_p64(test_vec[i].a);
    simde_poly64x1_t r = simde_vget_high_p64(a);
    simde_test_arm_neon_assert_equal_p64x1(r, simde_vld1_p64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x2_t a = simde_test_arm_neon_random_p64x2();
    simde_poly64x1_t r = simde_vget_high_p64(a);

    simde_test_arm_neon_write_p64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vget_high_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16 a[8];
    simde_bfloat16 r[4];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(    93.50), SIMDE_BFLOAT16_VALUE(   -34.75), SIMDE_BFLOAT16_VALUE(   -13.19), SIMDE_BFLOAT16_VALUE(    37.75),
        SIMDE_BFLOAT16_VALUE(   -19.38), SIMDE_BFLOAT16_VALUE(    80.00), SIMDE_BFLOAT16_VALUE(     3.44), SIMDE_BFLOAT16_VALUE(   -84.00) },
      { SIMDE_BFLOAT16_VALUE(   -19.38), SIMDE_BFLOAT16_VALUE(    80.00), SIMDE_BFLOAT16_VALUE(     3.44), SIMDE_BFLOAT16_VALUE(   -84.00) } },
    { { SIMDE_BFLOAT16_VALUE(    33.00), SIMDE_BFLOAT16_VALUE(   -30.38), SIMDE_BFLOAT16_VALUE(    82.50), SIMDE_BFLOAT16_VALUE(    53.50),
        SIMDE_BFLOAT16_VALUE(    70.00), SIMDE_BFLOAT16_VALUE(    55.00), SIMDE_BFLOAT16_VALUE(    46.25), SIMDE_BFLOAT16_VALUE(     2.16) },
      { SIMDE_BFLOAT16_VALUE(    70.00), SIMDE_BFLOAT16_VALUE(    55.00), SIMDE_BFLOAT16_VALUE(    46.25), SIMDE_BFLOAT16_VALUE(     2.16) } },
    { { SIMDE_BFLOAT16_VALUE(    97.00), SIMDE_BFLOAT16_VALUE(    54.00), SIMDE_BFLOAT16_VALUE(   -65.50), SIMDE_BFLOAT16_VALUE(   -11.38),
        SIMDE_BFLOAT16_VALUE(    99.00), SIMDE_BFLOAT16_VALUE(     6.31), SIMDE_BFLOAT16_VALUE(   -54.75), SIMDE_BFLOAT16_VALUE(   -75.50) },
      { SIMDE_BFLOAT16_VALUE(    99.00), SIMDE_BFLOAT16_VALUE(     6.31), SIMDE_BFLOAT16_VALUE(   -54.75), SIMDE_BFLOAT16_VALUE(   -75.50) } },
    { { SIMDE_BFLOAT16_VALUE(    19.25), SIMDE_BFLOAT16_VALUE(    24.00), SIMDE_BFLOAT16_VALUE(   -76.50), SIMDE_BFLOAT16_VALUE(     1.22),
        SIMDE_BFLOAT16_VALUE(    64.50), SIMDE_BFLOAT16_VALUE(    35.75), SIMDE_BFLOAT16_VALUE(     6.47), SIMDE_BFLOAT16_VALUE(    58.00) },
      { SIMDE_BFLOAT16_VALUE(    64.50), SIMDE_BFLOAT16_VALUE(    35.75), SIMDE_BFLOAT16_VALUE(     6.47), SIMDE_BFLOAT16_VALUE(    58.00) } },
    { { SIMDE_BFLOAT16_VALUE(   -99.00), SIMDE_BFLOAT16_VALUE(    93.50), SIMDE_BFLOAT16_VALUE(    -4.28), SIMDE_BFLOAT16_VALUE(   -18.38),
        SIMDE_BFLOAT16_VALUE(    73.50), SIMDE_BFLOAT16_VALUE(    99.00), SIMDE_BFLOAT16_VALUE(    -2.41), SIMDE_BFLOAT16_VALUE(     6.38) },
      { SIMDE_BFLOAT16_VALUE(    73.50), SIMDE_BFLOAT16_VALUE(    99.00), SIMDE_BFLOAT16_VALUE(    -2.41), SIMDE_BFLOAT16_VALUE(     6.38) } },
    { { SIMDE_BFLOAT16_VALUE(   -31.12), SIMDE_BFLOAT16_VALUE(   -19.75), SIMDE_BFLOAT16_VALUE(   -40.00), SIMDE_BFLOAT16_VALUE(   -61.25),
        SIMDE_BFLOAT16_VALUE(   -64.50), SIMDE_BFLOAT16_VALUE(   -93.50), SIMDE_BFLOAT16_VALUE(    41.00), SIMDE_BFLOAT16_VALUE(   -68.00) },
      { SIMDE_BFLOAT16_VALUE(   -64.50), SIMDE_BFLOAT16_VALUE(   -93.50), SIMDE_BFLOAT16_VALUE(    41.00), SIMDE_BFLOAT16_VALUE(   -68.00) } },
    { { SIMDE_BFLOAT16_VALUE(    60.25), SIMDE_BFLOAT16_VALUE(    75.50), SIMDE_BFLOAT16_VALUE(    20.75), SIMDE_BFLOAT16_VALUE(    59.25),
        SIMDE_BFLOAT16_VALUE(   -18.38), SIMDE_BFLOAT16_VALUE(    66.00), SIMDE_BFLOAT16_VALUE(    84.00), SIMDE_BFLOAT16_VALUE(   -99.00) },
      { SIMDE_BFLOAT16_VALUE(   -18.38), SIMDE_BFLOAT16_VALUE(    66.00), SIMDE_BFLOAT16_VALUE(    84.00), SIMDE_BFLOAT16_VALUE(   -99.00) } },
    { { SIMDE_BFLOAT16_VALUE(   -10.06), SIMDE_BFLOAT16_VALUE(   -93.00), SIMDE_BFLOAT16_VALUE(     2.06), SIMDE_BFLOAT16_VALUE(   -45.50),
        SIMDE_BFLOAT16_VALUE(    42.75), SIMDE_BFLOAT16_VALUE(   -91.50), SIMDE_BFLOAT16_VALUE(   -87.50), SIMDE_BFLOAT16_VALUE(    43.75) },
      { SIMDE_BFLOAT16_VALUE(    42.75), SIMDE_BFLOAT16_VALUE(   -91.50), SIMDE_BFLOAT16_VALUE(   -87.50), SIMDE_BFLOAT16_VALUE(    43.75) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8_t a = simde_vld1q_bf16(test_vec[i].a);
    simde_bfloat16x4_t r = simde_vget_high_bf16(a);

    simde_test_arm_neon_assert_equal_bf16x4(r, simde_vld1_bf16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_bfloat16x8_t a = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-100.0), SIMDE_BFLOAT16_VALUE(100.0));
    simde_bfloat16x4_t r = simde_vget_high_bf16(a);

    simde_test_arm_neon_write_bf16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_bf16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_high_bf16)

SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
