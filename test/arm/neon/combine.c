#define SIMDE_TEST_ARM_NEON_INSN combine

#include "test-neon.h"
#include "../../../simde/arm/neon/combine.h"

static int
test_simde_vcombine_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -53.98), SIMDE_FLOAT32_C(  -106.66) },
      { SIMDE_FLOAT32_C(   -75.22), SIMDE_FLOAT32_C(   554.40) },
      { SIMDE_FLOAT32_C(   -53.98), SIMDE_FLOAT32_C(  -106.66), SIMDE_FLOAT32_C(   -75.22), SIMDE_FLOAT32_C(   554.40) } },
    { { SIMDE_FLOAT32_C(   653.50), SIMDE_FLOAT32_C(   983.28) },
      { SIMDE_FLOAT32_C(    26.88), SIMDE_FLOAT32_C(   397.84) },
      { SIMDE_FLOAT32_C(   653.50), SIMDE_FLOAT32_C(   983.28), SIMDE_FLOAT32_C(    26.88), SIMDE_FLOAT32_C(   397.84) } },
    { { SIMDE_FLOAT32_C(  -890.56), SIMDE_FLOAT32_C(   449.15) },
      { SIMDE_FLOAT32_C(  -645.05), SIMDE_FLOAT32_C(   760.45) },
      { SIMDE_FLOAT32_C(  -890.56), SIMDE_FLOAT32_C(   449.15), SIMDE_FLOAT32_C(  -645.05), SIMDE_FLOAT32_C(   760.45) } },
    { { SIMDE_FLOAT32_C(  -595.29), SIMDE_FLOAT32_C(  -601.12) },
      { SIMDE_FLOAT32_C(   312.34), SIMDE_FLOAT32_C(  -100.77) },
      { SIMDE_FLOAT32_C(  -595.29), SIMDE_FLOAT32_C(  -601.12), SIMDE_FLOAT32_C(   312.34), SIMDE_FLOAT32_C(  -100.77) } },
    { { SIMDE_FLOAT32_C(  -983.11), SIMDE_FLOAT32_C(   886.29) },
      { SIMDE_FLOAT32_C(  -371.66), SIMDE_FLOAT32_C(   376.19) },
      { SIMDE_FLOAT32_C(  -983.11), SIMDE_FLOAT32_C(   886.29), SIMDE_FLOAT32_C(  -371.66), SIMDE_FLOAT32_C(   376.19) } },
    { { SIMDE_FLOAT32_C(   421.16), SIMDE_FLOAT32_C(  -941.17) },
      { SIMDE_FLOAT32_C(  -980.32), SIMDE_FLOAT32_C(    53.73) },
      { SIMDE_FLOAT32_C(   421.16), SIMDE_FLOAT32_C(  -941.17), SIMDE_FLOAT32_C(  -980.32), SIMDE_FLOAT32_C(    53.73) } },
    { { SIMDE_FLOAT32_C(  -450.56), SIMDE_FLOAT32_C(  -313.93) },
      { SIMDE_FLOAT32_C(  -837.06), SIMDE_FLOAT32_C(  -183.56) },
      { SIMDE_FLOAT32_C(  -450.56), SIMDE_FLOAT32_C(  -313.93), SIMDE_FLOAT32_C(  -837.06), SIMDE_FLOAT32_C(  -183.56) } },
    { { SIMDE_FLOAT32_C(   591.39), SIMDE_FLOAT32_C(   270.71) },
      { SIMDE_FLOAT32_C(  -178.56), SIMDE_FLOAT32_C(  -462.59) },
      { SIMDE_FLOAT32_C(   591.39), SIMDE_FLOAT32_C(   270.71), SIMDE_FLOAT32_C(  -178.56), SIMDE_FLOAT32_C(  -462.59) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vcombine_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vcombine_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcombine_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   425.89) },
      { SIMDE_FLOAT64_C(   679.01) },
      { SIMDE_FLOAT64_C(   425.89), SIMDE_FLOAT64_C(   679.01) } },
    { { SIMDE_FLOAT64_C(    46.20) },
      { SIMDE_FLOAT64_C(  -599.79) },
      { SIMDE_FLOAT64_C(    46.20), SIMDE_FLOAT64_C(  -599.79) } },
    { { SIMDE_FLOAT64_C(   -92.67) },
      { SIMDE_FLOAT64_C(   654.91) },
      { SIMDE_FLOAT64_C(   -92.67), SIMDE_FLOAT64_C(   654.91) } },
    { { SIMDE_FLOAT64_C(   643.92) },
      { SIMDE_FLOAT64_C(   238.58) },
      { SIMDE_FLOAT64_C(   643.92), SIMDE_FLOAT64_C(   238.58) } },
    { { SIMDE_FLOAT64_C(   715.59) },
      { SIMDE_FLOAT64_C(  -916.05) },
      { SIMDE_FLOAT64_C(   715.59), SIMDE_FLOAT64_C(  -916.05) } },
    { { SIMDE_FLOAT64_C(  -885.97) },
      { SIMDE_FLOAT64_C(   112.56) },
      { SIMDE_FLOAT64_C(  -885.97), SIMDE_FLOAT64_C(   112.56) } },
    { { SIMDE_FLOAT64_C(   319.99) },
      { SIMDE_FLOAT64_C(  -850.11) },
      { SIMDE_FLOAT64_C(   319.99), SIMDE_FLOAT64_C(  -850.11) } },
    { { SIMDE_FLOAT64_C(  -588.46) },
      { SIMDE_FLOAT64_C(   182.96) },
      { SIMDE_FLOAT64_C(  -588.46), SIMDE_FLOAT64_C(   182.96) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vcombine_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vcombine_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcombine_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  68), -INT8_C(  50), -INT8_C(  26),  INT8_C( 105),  INT8_C(  81),  INT8_C(  69),  INT8_C(   3),  INT8_C(  21) },
      {  INT8_C( 119),  INT8_C(  72),  INT8_C( 123), -INT8_C(  44),  INT8_C(  61),  INT8_C(  43),  INT8_C( 109), -INT8_C(  34) },
      {  INT8_C(  68), -INT8_C(  50), -INT8_C(  26),  INT8_C( 105),  INT8_C(  81),  INT8_C(  69),  INT8_C(   3),  INT8_C(  21),
         INT8_C( 119),  INT8_C(  72),  INT8_C( 123), -INT8_C(  44),  INT8_C(  61),  INT8_C(  43),  INT8_C( 109), -INT8_C(  34) } },
    { {  INT8_C(  36), -INT8_C( 100),  INT8_C( 109), -INT8_C(  72), -INT8_C(  41), -INT8_C(  75),  INT8_C(  14),  INT8_C( 114) },
      {  INT8_C( 110),  INT8_C( 126), -INT8_C(  79), -INT8_C(  75),  INT8_C(  23), -INT8_C(   2), -INT8_C(   9),  INT8_C(  91) },
      {  INT8_C(  36), -INT8_C( 100),  INT8_C( 109), -INT8_C(  72), -INT8_C(  41), -INT8_C(  75),  INT8_C(  14),  INT8_C( 114),
         INT8_C( 110),  INT8_C( 126), -INT8_C(  79), -INT8_C(  75),  INT8_C(  23), -INT8_C(   2), -INT8_C(   9),  INT8_C(  91) } },
    { { -INT8_C(  51), -INT8_C(  34), -INT8_C(  59),  INT8_C(  30),  INT8_C(  35), -INT8_C(  56),  INT8_C(  51), -INT8_C( 102) },
      {  INT8_C(  16), -INT8_C(  82),  INT8_C( 110),  INT8_C(  77), -INT8_C(  38), -INT8_C(  37),  INT8_C(  43), -INT8_C(   2) },
      { -INT8_C(  51), -INT8_C(  34), -INT8_C(  59),  INT8_C(  30),  INT8_C(  35), -INT8_C(  56),  INT8_C(  51), -INT8_C( 102),
         INT8_C(  16), -INT8_C(  82),  INT8_C( 110),  INT8_C(  77), -INT8_C(  38), -INT8_C(  37),  INT8_C(  43), -INT8_C(   2) } },
    { {  INT8_C( 119), -INT8_C( 104), -INT8_C(  74),  INT8_C(  79),  INT8_C(  78), -INT8_C(  60), -INT8_C(  63), -INT8_C(  68) },
      {  INT8_C(  66),  INT8_C( 114),  INT8_C( 113),  INT8_C(  90),  INT8_C( 112),  INT8_C( 105), -INT8_C(  75),  INT8_C(  61) },
      {  INT8_C( 119), -INT8_C( 104), -INT8_C(  74),  INT8_C(  79),  INT8_C(  78), -INT8_C(  60), -INT8_C(  63), -INT8_C(  68),
         INT8_C(  66),  INT8_C( 114),  INT8_C( 113),  INT8_C(  90),  INT8_C( 112),  INT8_C( 105), -INT8_C(  75),  INT8_C(  61) } },
    { {  INT8_C(  71),  INT8_C( 122),  INT8_C(  91),  INT8_C( 106),  INT8_C(  67), -INT8_C( 113),  INT8_C(   4),  INT8_C(  83) },
      {  INT8_C(  61),  INT8_C( 114), -INT8_C(  95),  INT8_C(  23),  INT8_C(  77), -INT8_C(  52),  INT8_C(  22), -INT8_C(  60) },
      {  INT8_C(  71),  INT8_C( 122),  INT8_C(  91),  INT8_C( 106),  INT8_C(  67), -INT8_C( 113),  INT8_C(   4),  INT8_C(  83),
         INT8_C(  61),  INT8_C( 114), -INT8_C(  95),  INT8_C(  23),  INT8_C(  77), -INT8_C(  52),  INT8_C(  22), -INT8_C(  60) } },
    { {  INT8_C( 101), -INT8_C(  52),  INT8_C(  19), -INT8_C(  77), -INT8_C( 111), -INT8_C(  44),  INT8_C( 111), -INT8_C(  45) },
      {  INT8_C(  70), -INT8_C(  31),  INT8_C(  45), -INT8_C(  73),  INT8_C(  74), -INT8_C(  29), -INT8_C(  12), -INT8_C( 111) },
      {  INT8_C( 101), -INT8_C(  52),  INT8_C(  19), -INT8_C(  77), -INT8_C( 111), -INT8_C(  44),  INT8_C( 111), -INT8_C(  45),
         INT8_C(  70), -INT8_C(  31),  INT8_C(  45), -INT8_C(  73),  INT8_C(  74), -INT8_C(  29), -INT8_C(  12), -INT8_C( 111) } },
    { {  INT8_C(  93),  INT8_C(  80), -INT8_C(   5), -INT8_C(  96), -INT8_C(  33), -INT8_C(   1), -INT8_C(  12),  INT8_C(  28) },
      {  INT8_C( 113), -INT8_C( 107),  INT8_C(  52), -INT8_C(  66),  INT8_C(  97),  INT8_C(  74), -INT8_C( 126), -INT8_C(  58) },
      {  INT8_C(  93),  INT8_C(  80), -INT8_C(   5), -INT8_C(  96), -INT8_C(  33), -INT8_C(   1), -INT8_C(  12),  INT8_C(  28),
         INT8_C( 113), -INT8_C( 107),  INT8_C(  52), -INT8_C(  66),  INT8_C(  97),  INT8_C(  74), -INT8_C( 126), -INT8_C(  58) } },
    { {  INT8_C(  22), -INT8_C( 106),  INT8_C( 121), -INT8_C(  89),  INT8_C( 106), -INT8_C(  23),  INT8_C( 123), -INT8_C(  79) },
      { -INT8_C(  54), -INT8_C(  88),  INT8_C( 104),  INT8_C(  20), -INT8_C( 117),  INT8_C(  92), -INT8_C(  91), -INT8_C(  23) },
      {  INT8_C(  22), -INT8_C( 106),  INT8_C( 121), -INT8_C(  89),  INT8_C( 106), -INT8_C(  23),  INT8_C( 123), -INT8_C(  79),
        -INT8_C(  54), -INT8_C(  88),  INT8_C( 104),  INT8_C(  20), -INT8_C( 117),  INT8_C(  92), -INT8_C(  91), -INT8_C(  23) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vcombine_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x16_t r = simde_vcombine_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcombine_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 30456),  INT16_C( 24748),  INT16_C( 23695), -INT16_C( 11654) },
      {  INT16_C( 15149), -INT16_C( 12216), -INT16_C( 26484), -INT16_C( 18819) },
      { -INT16_C( 30456),  INT16_C( 24748),  INT16_C( 23695), -INT16_C( 11654),  INT16_C( 15149), -INT16_C( 12216), -INT16_C( 26484), -INT16_C( 18819) } },
    { { -INT16_C(  7855),  INT16_C( 16407), -INT16_C( 20008),  INT16_C(  7685) },
      { -INT16_C(  2640),  INT16_C( 15239),  INT16_C( 11611),  INT16_C( 25435) },
      { -INT16_C(  7855),  INT16_C( 16407), -INT16_C( 20008),  INT16_C(  7685), -INT16_C(  2640),  INT16_C( 15239),  INT16_C( 11611),  INT16_C( 25435) } },
    { {  INT16_C(  1974),  INT16_C( 18115),  INT16_C( 15715), -INT16_C( 28648) },
      {  INT16_C( 24696),  INT16_C(  1120), -INT16_C(  8712),  INT16_C( 18875) },
      {  INT16_C(  1974),  INT16_C( 18115),  INT16_C( 15715), -INT16_C( 28648),  INT16_C( 24696),  INT16_C(  1120), -INT16_C(  8712),  INT16_C( 18875) } },
    { { -INT16_C( 11585), -INT16_C( 26743), -INT16_C( 29053),  INT16_C( 13493) },
      {  INT16_C( 15747), -INT16_C(  8593), -INT16_C( 13718),  INT16_C(  8513) },
      { -INT16_C( 11585), -INT16_C( 26743), -INT16_C( 29053),  INT16_C( 13493),  INT16_C( 15747), -INT16_C(  8593), -INT16_C( 13718),  INT16_C(  8513) } },
    { {  INT16_C(  1233),  INT16_C( 13671),  INT16_C( 32577), -INT16_C( 17979) },
      {  INT16_C(  9951), -INT16_C( 10307),  INT16_C( 30723), -INT16_C( 15840) },
      {  INT16_C(  1233),  INT16_C( 13671),  INT16_C( 32577), -INT16_C( 17979),  INT16_C(  9951), -INT16_C( 10307),  INT16_C( 30723), -INT16_C( 15840) } },
    { { -INT16_C( 22197), -INT16_C( 12710),  INT16_C(  3895), -INT16_C( 17918) },
      {  INT16_C( 29004), -INT16_C( 18536), -INT16_C(  9925),  INT16_C(  3544) },
      { -INT16_C( 22197), -INT16_C( 12710),  INT16_C(  3895), -INT16_C( 17918),  INT16_C( 29004), -INT16_C( 18536), -INT16_C(  9925),  INT16_C(  3544) } },
    { {  INT16_C( 16349),  INT16_C(  7746),  INT16_C(  1982), -INT16_C( 25129) },
      { -INT16_C( 27603),  INT16_C( 12660), -INT16_C( 27635),  INT16_C( 22771) },
      {  INT16_C( 16349),  INT16_C(  7746),  INT16_C(  1982), -INT16_C( 25129), -INT16_C( 27603),  INT16_C( 12660), -INT16_C( 27635),  INT16_C( 22771) } },
    { {  INT16_C( 19773),  INT16_C( 29734),  INT16_C( 10589), -INT16_C( 22226) },
      { -INT16_C( 14694), -INT16_C( 10656),  INT16_C( 14495),  INT16_C( 31971) },
      {  INT16_C( 19773),  INT16_C( 29734),  INT16_C( 10589), -INT16_C( 22226), -INT16_C( 14694), -INT16_C( 10656),  INT16_C( 14495),  INT16_C( 31971) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vcombine_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t r = simde_vcombine_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcombine_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   479230270), -INT32_C(   919434613) },
      { -INT32_C(  1167602195),  INT32_C(   292509305) },
      {  INT32_C(   479230270), -INT32_C(   919434613), -INT32_C(  1167602195),  INT32_C(   292509305) } },
    { {  INT32_C(   396420651), -INT32_C(   521622852) },
      {  INT32_C(   567435341),  INT32_C(  1151863558) },
      {  INT32_C(   396420651), -INT32_C(   521622852),  INT32_C(   567435341),  INT32_C(  1151863558) } },
    { {  INT32_C(   274741637), -INT32_C(  1311075389) },
      { -INT32_C(   630505120), -INT32_C(  1024730473) },
      {  INT32_C(   274741637), -INT32_C(  1311075389), -INT32_C(   630505120), -INT32_C(  1024730473) } },
    { {  INT32_C(  2111409089), -INT32_C(  2091007435) },
      {  INT32_C(   681848610), -INT32_C(  1083421382) },
      {  INT32_C(  2111409089), -INT32_C(  2091007435),  INT32_C(   681848610), -INT32_C(  1083421382) } },
    { {  INT32_C(  1238420870), -INT32_C(  1057314208) },
      { -INT32_C(  2103810581),  INT32_C(    21267776) },
      {  INT32_C(  1238420870), -INT32_C(  1057314208), -INT32_C(  2103810581),  INT32_C(    21267776) } },
    { {  INT32_C(  1182670352),  INT32_C(    46783456) },
      {  INT32_C(  1143631114),  INT32_C(  1074042554) },
      {  INT32_C(  1182670352),  INT32_C(    46783456),  INT32_C(  1143631114),  INT32_C(  1074042554) } },
    { { -INT32_C(  1014311837),  INT32_C(  1770292350) },
      {  INT32_C(   720051946), -INT32_C(  1272238172) },
      { -INT32_C(  1014311837),  INT32_C(  1770292350),  INT32_C(   720051946), -INT32_C(  1272238172) } },
    { {  INT32_C(   771402061), -INT32_C(  1909472380) },
      { -INT32_C(   338536143),  INT32_C(  1395447536) },
      {  INT32_C(   771402061), -INT32_C(  1909472380), -INT32_C(   338536143),  INT32_C(  1395447536) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vcombine_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t r = simde_vcombine_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcombine_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 7042412965683835049) },
      {  INT64_C( 1117862416211221349) },
      {  INT64_C( 7042412965683835049),  INT64_C( 1117862416211221349) } },
    { { -INT64_C( 3901535941454286721) },
      { -INT64_C( 1354626619370034422) },
      { -INT64_C( 3901535941454286721), -INT64_C( 1354626619370034422) } },
    { {  INT64_C( 8556652449628906263) },
      { -INT64_C( 5191846387337607439) },
      {  INT64_C( 8556652449628906263), -INT64_C( 5191846387337607439) } },
    { {  INT64_C( 2526541489756578955) },
      { -INT64_C( 5228216683076765376) },
      {  INT64_C( 2526541489756578955), -INT64_C( 5228216683076765376) } },
    { {  INT64_C( 6093322338631486471) },
      {  INT64_C( 5659099228278286235) },
      {  INT64_C( 6093322338631486471),  INT64_C( 5659099228278286235) } },
    { {  INT64_C( 1768126677572240204) },
      { -INT64_C( 6542026434312078625) },
      {  INT64_C( 1768126677572240204), -INT64_C( 6542026434312078625) } },
    { { -INT64_C( 4985399989866968294) },
      {  INT64_C( 8954869304345298740) },
      { -INT64_C( 4985399989866968294),  INT64_C( 8954869304345298740) } },
    { {  INT64_C( 6974505177732799450) },
      { -INT64_C( 8239030459567217051) },
      {  INT64_C( 6974505177732799450), -INT64_C( 8239030459567217051) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vcombine_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x2_t r = simde_vcombine_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcombine_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(242), UINT8_C(197), UINT8_C(237), UINT8_C(208), UINT8_C( 62), UINT8_C(206), UINT8_C(169), UINT8_C(170) },
      { UINT8_C( 26), UINT8_C( 39), UINT8_C(185), UINT8_C(112), UINT8_C(211), UINT8_C(125), UINT8_C(174), UINT8_C( 83) },
      { UINT8_C(242), UINT8_C(197), UINT8_C(237), UINT8_C(208), UINT8_C( 62), UINT8_C(206), UINT8_C(169), UINT8_C(170),
        UINT8_C( 26), UINT8_C( 39), UINT8_C(185), UINT8_C(112), UINT8_C(211), UINT8_C(125), UINT8_C(174), UINT8_C( 83) } },
    { { UINT8_C( 67), UINT8_C(254), UINT8_C( 36), UINT8_C(110), UINT8_C(206), UINT8_C( 98), UINT8_C(151), UINT8_C( 23) },
      { UINT8_C(198), UINT8_C(171), UINT8_C( 20), UINT8_C(176), UINT8_C( 57), UINT8_C(103), UINT8_C(214), UINT8_C( 43) },
      { UINT8_C( 67), UINT8_C(254), UINT8_C( 36), UINT8_C(110), UINT8_C(206), UINT8_C( 98), UINT8_C(151), UINT8_C( 23),
        UINT8_C(198), UINT8_C(171), UINT8_C( 20), UINT8_C(176), UINT8_C( 57), UINT8_C(103), UINT8_C(214), UINT8_C( 43) } },
    { { UINT8_C( 44), UINT8_C(195), UINT8_C(252), UINT8_C(106), UINT8_C(145), UINT8_C(165), UINT8_C( 20), UINT8_C(171) },
      { UINT8_C(205), UINT8_C(206), UINT8_C( 28), UINT8_C(160), UINT8_C( 75), UINT8_C(202), UINT8_C(243), UINT8_C(142) },
      { UINT8_C( 44), UINT8_C(195), UINT8_C(252), UINT8_C(106), UINT8_C(145), UINT8_C(165), UINT8_C( 20), UINT8_C(171),
        UINT8_C(205), UINT8_C(206), UINT8_C( 28), UINT8_C(160), UINT8_C( 75), UINT8_C(202), UINT8_C(243), UINT8_C(142) } },
    { { UINT8_C(200), UINT8_C( 24), UINT8_C(253), UINT8_C(151), UINT8_C(122), UINT8_C(148), UINT8_C(174), UINT8_C( 64) },
      { UINT8_C( 64), UINT8_C(194), UINT8_C(241), UINT8_C(121), UINT8_C( 41), UINT8_C(199), UINT8_C(164), UINT8_C( 85) },
      { UINT8_C(200), UINT8_C( 24), UINT8_C(253), UINT8_C(151), UINT8_C(122), UINT8_C(148), UINT8_C(174), UINT8_C( 64),
        UINT8_C( 64), UINT8_C(194), UINT8_C(241), UINT8_C(121), UINT8_C( 41), UINT8_C(199), UINT8_C(164), UINT8_C( 85) } },
    { { UINT8_C(138), UINT8_C(160), UINT8_C(192), UINT8_C( 27), UINT8_C( 70), UINT8_C(212), UINT8_C(199), UINT8_C( 19) },
      { UINT8_C(162), UINT8_C(227), UINT8_C(179), UINT8_C(238), UINT8_C(173), UINT8_C(167), UINT8_C(124), UINT8_C(118) },
      { UINT8_C(138), UINT8_C(160), UINT8_C(192), UINT8_C( 27), UINT8_C( 70), UINT8_C(212), UINT8_C(199), UINT8_C( 19),
        UINT8_C(162), UINT8_C(227), UINT8_C(179), UINT8_C(238), UINT8_C(173), UINT8_C(167), UINT8_C(124), UINT8_C(118) } },
    { { UINT8_C(191), UINT8_C(121), UINT8_C( 13), UINT8_C( 57), UINT8_C( 14), UINT8_C(187), UINT8_C(122), UINT8_C( 78) },
      { UINT8_C(125), UINT8_C(107), UINT8_C(199), UINT8_C(166), UINT8_C( 50), UINT8_C(107), UINT8_C(251), UINT8_C(188) },
      { UINT8_C(191), UINT8_C(121), UINT8_C( 13), UINT8_C( 57), UINT8_C( 14), UINT8_C(187), UINT8_C(122), UINT8_C( 78),
        UINT8_C(125), UINT8_C(107), UINT8_C(199), UINT8_C(166), UINT8_C( 50), UINT8_C(107), UINT8_C(251), UINT8_C(188) } },
    { { UINT8_C( 12), UINT8_C(187), UINT8_C(215), UINT8_C( 82), UINT8_C(144), UINT8_C(158), UINT8_C(101), UINT8_C( 50) },
      { UINT8_C(129), UINT8_C( 24), UINT8_C( 32), UINT8_C( 47), UINT8_C(191), UINT8_C(157), UINT8_C(165), UINT8_C(126) },
      { UINT8_C( 12), UINT8_C(187), UINT8_C(215), UINT8_C( 82), UINT8_C(144), UINT8_C(158), UINT8_C(101), UINT8_C( 50),
        UINT8_C(129), UINT8_C( 24), UINT8_C( 32), UINT8_C( 47), UINT8_C(191), UINT8_C(157), UINT8_C(165), UINT8_C(126) } },
    { { UINT8_C( 22), UINT8_C(178), UINT8_C(184), UINT8_C( 36), UINT8_C(109), UINT8_C( 50), UINT8_C(114), UINT8_C(234) },
      { UINT8_C(157), UINT8_C( 57), UINT8_C(144), UINT8_C(207), UINT8_C(165), UINT8_C(139), UINT8_C(139), UINT8_C(177) },
      { UINT8_C( 22), UINT8_C(178), UINT8_C(184), UINT8_C( 36), UINT8_C(109), UINT8_C( 50), UINT8_C(114), UINT8_C(234),
        UINT8_C(157), UINT8_C( 57), UINT8_C(144), UINT8_C(207), UINT8_C(165), UINT8_C(139), UINT8_C(139), UINT8_C(177) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vcombine_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x16_t r = simde_vcombine_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcombine_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 2850), UINT16_C(54644), UINT16_C(22390), UINT16_C(12151) },
      { UINT16_C(36777), UINT16_C(47906), UINT16_C( 9646), UINT16_C(44426) },
      { UINT16_C( 2850), UINT16_C(54644), UINT16_C(22390), UINT16_C(12151), UINT16_C(36777), UINT16_C(47906), UINT16_C( 9646), UINT16_C(44426) } },
    { { UINT16_C(44944), UINT16_C(58267), UINT16_C(30973), UINT16_C(16694) },
      { UINT16_C(54474), UINT16_C(20044), UINT16_C(55264), UINT16_C(  593) },
      { UINT16_C(44944), UINT16_C(58267), UINT16_C(30973), UINT16_C(16694), UINT16_C(54474), UINT16_C(20044), UINT16_C(55264), UINT16_C(  593) } },
    { { UINT16_C(50658), UINT16_C(22744), UINT16_C(20252), UINT16_C(50568) },
      { UINT16_C(43743), UINT16_C(36225), UINT16_C( 3023), UINT16_C(24378) },
      { UINT16_C(50658), UINT16_C(22744), UINT16_C(20252), UINT16_C(50568), UINT16_C(43743), UINT16_C(36225), UINT16_C( 3023), UINT16_C(24378) } },
    { { UINT16_C(54714), UINT16_C(46914), UINT16_C(30797), UINT16_C( 6136) },
      { UINT16_C(17741), UINT16_C(11622), UINT16_C(46876), UINT16_C(65328) },
      { UINT16_C(54714), UINT16_C(46914), UINT16_C(30797), UINT16_C( 6136), UINT16_C(17741), UINT16_C(11622), UINT16_C(46876), UINT16_C(65328) } },
    { { UINT16_C( 2172), UINT16_C(38999), UINT16_C(57175), UINT16_C(13918) },
      { UINT16_C(57225), UINT16_C(22723), UINT16_C(65002), UINT16_C(42167) },
      { UINT16_C( 2172), UINT16_C(38999), UINT16_C(57175), UINT16_C(13918), UINT16_C(57225), UINT16_C(22723), UINT16_C(65002), UINT16_C(42167) } },
    { { UINT16_C(64210), UINT16_C( 8284), UINT16_C(21618), UINT16_C(48951) },
      { UINT16_C(40345), UINT16_C(46829), UINT16_C( 7508), UINT16_C(53429) },
      { UINT16_C(64210), UINT16_C( 8284), UINT16_C(21618), UINT16_C(48951), UINT16_C(40345), UINT16_C(46829), UINT16_C( 7508), UINT16_C(53429) } },
    { { UINT16_C( 3109), UINT16_C(31849), UINT16_C(51180), UINT16_C(30131) },
      { UINT16_C(30374), UINT16_C(37070), UINT16_C(34164), UINT16_C(17972) },
      { UINT16_C( 3109), UINT16_C(31849), UINT16_C(51180), UINT16_C(30131), UINT16_C(30374), UINT16_C(37070), UINT16_C(34164), UINT16_C(17972) } },
    { { UINT16_C(36991), UINT16_C(62054), UINT16_C(40677), UINT16_C(32433) },
      { UINT16_C(40507), UINT16_C(36916), UINT16_C(59835), UINT16_C(57440) },
      { UINT16_C(36991), UINT16_C(62054), UINT16_C(40677), UINT16_C(32433), UINT16_C(40507), UINT16_C(36916), UINT16_C(59835), UINT16_C(57440) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vcombine_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x8_t r = simde_vcombine_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcombine_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1573219985), UINT32_C(4091762574) },
      { UINT32_C(2146127911), UINT32_C( 652211733) },
      { UINT32_C(1573219985), UINT32_C(4091762574), UINT32_C(2146127911), UINT32_C( 652211733) } },
    { { UINT32_C(1454558493), UINT32_C(1586285622) },
      { UINT32_C(1784348730), UINT32_C(2848915480) },
      { UINT32_C(1454558493), UINT32_C(1586285622), UINT32_C(1784348730), UINT32_C(2848915480) } },
    { { UINT32_C(4228355182), UINT32_C( 317778667) },
      { UINT32_C(1351801659), UINT32_C(4000805329) },
      { UINT32_C(4228355182), UINT32_C( 317778667), UINT32_C(1351801659), UINT32_C(4000805329) } },
    { { UINT32_C(1967401279), UINT32_C( 819187957) },
      { UINT32_C(3919196113), UINT32_C(2643683631) },
      { UINT32_C(1967401279), UINT32_C( 819187957), UINT32_C(3919196113), UINT32_C(2643683631) } },
    { { UINT32_C(3902446333), UINT32_C(3220933252) },
      { UINT32_C( 907054437), UINT32_C(1025869822) },
      { UINT32_C(3902446333), UINT32_C(3220933252), UINT32_C( 907054437), UINT32_C(1025869822) } },
    { { UINT32_C(2796775856), UINT32_C( 198608442) },
      { UINT32_C(3841224885), UINT32_C(3598878681) },
      { UINT32_C(2796775856), UINT32_C( 198608442), UINT32_C(3841224885), UINT32_C(3598878681) } },
    { { UINT32_C(2797476897), UINT32_C( 191216038) },
      { UINT32_C(1161917766), UINT32_C(2911004412) },
      { UINT32_C(2797476897), UINT32_C( 191216038), UINT32_C(1161917766), UINT32_C(2911004412) } },
    { { UINT32_C( 173225424), UINT32_C(1897212348) },
      { UINT32_C(1918241177), UINT32_C(2991118481) },
      { UINT32_C( 173225424), UINT32_C(1897212348), UINT32_C(1918241177), UINT32_C(2991118481) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vcombine_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x4_t r = simde_vcombine_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcombine_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(18153453259173778237) },
      { UINT64_C(11400740053166720884) },
      { UINT64_C(18153453259173778237), UINT64_C(11400740053166720884) } },
    { { UINT64_C( 7651395941339862214) },
      { UINT64_C( 3776799313776537214) },
      { UINT64_C( 7651395941339862214), UINT64_C( 3776799313776537214) } },
    { { UINT64_C(10898431973749169846) },
      { UINT64_C( 2905810644555846153) },
      { UINT64_C(10898431973749169846), UINT64_C( 2905810644555846153) } },
    { { UINT64_C( 8616290951558053911) },
      { UINT64_C(14001987062142871845) },
      { UINT64_C( 8616290951558053911), UINT64_C(14001987062142871845) } },
    { { UINT64_C( 8134984611907659051) },
      { UINT64_C(14745199371509641495) },
      { UINT64_C( 8134984611907659051), UINT64_C(14745199371509641495) } },
    { { UINT64_C(  335668664436369464) },
      { UINT64_C( 9619813438614162610) },
      { UINT64_C(  335668664436369464), UINT64_C( 9619813438614162610) } },
    { { UINT64_C(16405973300147422934) },
      { UINT64_C( 9469942237931295467) },
      { UINT64_C(16405973300147422934), UINT64_C( 9469942237931295467) } },
    { { UINT64_C(11207591305728516262) },
      { UINT64_C(17476457064037984936) },
      { UINT64_C(11207591305728516262), UINT64_C(17476457064037984936) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vcombine_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x2_t r = simde_vcombine_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcombine_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcombine_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcombine_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcombine_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcombine_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcombine_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcombine_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcombine_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcombine_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcombine_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
