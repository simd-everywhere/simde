#define SIMDE_TEST_ARM_NEON_INSN mls

#include "test-neon.h"
#include "../../../simde/arm/neon/mls.h"

static int
test_simde_vmls_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 c[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -365.18), SIMDE_FLOAT32_C(   555.85) },
      { SIMDE_FLOAT32_C(   342.95), SIMDE_FLOAT32_C(   560.35) },
      { SIMDE_FLOAT32_C(   990.43), SIMDE_FLOAT32_C(   963.21) },
      { SIMDE_FLOAT32_C(-340033.16), SIMDE_FLOAT32_C(-539178.81) } },
    { { SIMDE_FLOAT32_C(  -502.01), SIMDE_FLOAT32_C(   894.84) },
      { SIMDE_FLOAT32_C(   131.14), SIMDE_FLOAT32_C(   977.90) },
      { SIMDE_FLOAT32_C(   151.65), SIMDE_FLOAT32_C(   607.45) },
      { SIMDE_FLOAT32_C(-20389.39), SIMDE_FLOAT32_C(-593130.56) } },
    { { SIMDE_FLOAT32_C(  -426.49), SIMDE_FLOAT32_C(   736.48) },
      { SIMDE_FLOAT32_C(  -938.18), SIMDE_FLOAT32_C(  -397.50) },
      { SIMDE_FLOAT32_C(    44.80), SIMDE_FLOAT32_C(   850.55) },
      { SIMDE_FLOAT32_C( 41603.98), SIMDE_FLOAT32_C(338830.09) } },
    { { SIMDE_FLOAT32_C(  -738.35), SIMDE_FLOAT32_C(   630.15) },
      { SIMDE_FLOAT32_C(   820.68), SIMDE_FLOAT32_C(  -844.89) },
      { SIMDE_FLOAT32_C(   328.00), SIMDE_FLOAT32_C(   133.56) },
      { SIMDE_FLOAT32_C(-269921.38), SIMDE_FLOAT32_C(113473.66) } },
    { { SIMDE_FLOAT32_C(   660.82), SIMDE_FLOAT32_C(  -833.42) },
      { SIMDE_FLOAT32_C(   240.76), SIMDE_FLOAT32_C(  -548.85) },
      { SIMDE_FLOAT32_C(  -272.61), SIMDE_FLOAT32_C(   897.78) },
      { SIMDE_FLOAT32_C( 66294.40), SIMDE_FLOAT32_C(491913.16) } },
    { { SIMDE_FLOAT32_C(  -760.18), SIMDE_FLOAT32_C(   362.21) },
      { SIMDE_FLOAT32_C(   453.62), SIMDE_FLOAT32_C(   582.76) },
      { SIMDE_FLOAT32_C(   -77.44), SIMDE_FLOAT32_C(   444.05) },
      { SIMDE_FLOAT32_C( 34368.15), SIMDE_FLOAT32_C(-258412.38) } },
    { { SIMDE_FLOAT32_C(   545.98), SIMDE_FLOAT32_C(   420.55) },
      { SIMDE_FLOAT32_C(   338.90), SIMDE_FLOAT32_C(  -322.88) },
      { SIMDE_FLOAT32_C(   398.44), SIMDE_FLOAT32_C(  -509.46) },
      { SIMDE_FLOAT32_C(-134485.33), SIMDE_FLOAT32_C(-164073.89) } },
    { { SIMDE_FLOAT32_C(  -715.43), SIMDE_FLOAT32_C(   971.95) },
      { SIMDE_FLOAT32_C(  -772.98), SIMDE_FLOAT32_C(  -653.61) },
      { SIMDE_FLOAT32_C(  -425.55), SIMDE_FLOAT32_C(   271.82) },
      { SIMDE_FLOAT32_C(-329657.06), SIMDE_FLOAT32_C(178636.22) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t c = simde_vld1_f32(test_vec[i].c);
    simde_float32x2_t r = simde_vmls_f32(a, b, c);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_float32x2_t c = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_float32x2_t r = simde_vmls_f32(a, b, c);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 c[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   662.20) },
      { SIMDE_FLOAT64_C(   614.22) },
      { SIMDE_FLOAT64_C(  -568.69) },
      { SIMDE_FLOAT64_C(349962.97) } },
    { { SIMDE_FLOAT64_C(   237.85) },
      { SIMDE_FLOAT64_C(    33.93) },
      { SIMDE_FLOAT64_C(    22.08) },
      { SIMDE_FLOAT64_C(  -511.32) } },
    { { SIMDE_FLOAT64_C(   254.37) },
      { SIMDE_FLOAT64_C(  -543.96) },
      { SIMDE_FLOAT64_C(    92.53) },
      { SIMDE_FLOAT64_C( 50586.99) } },
    { { SIMDE_FLOAT64_C(   461.60) },
      { SIMDE_FLOAT64_C(  -604.69) },
      { SIMDE_FLOAT64_C(  -522.66) },
      { SIMDE_FLOAT64_C(-315585.68) } },
    { { SIMDE_FLOAT64_C(  -338.41) },
      { SIMDE_FLOAT64_C(   863.96) },
      { SIMDE_FLOAT64_C(   948.15) },
      { SIMDE_FLOAT64_C(-819502.08) } },
    { { SIMDE_FLOAT64_C(   524.72) },
      { SIMDE_FLOAT64_C(  -156.65) },
      { SIMDE_FLOAT64_C(   673.47) },
      { SIMDE_FLOAT64_C(106023.80) } },
    { { SIMDE_FLOAT64_C(  -712.19) },
      { SIMDE_FLOAT64_C(   -87.29) },
      { SIMDE_FLOAT64_C(   443.43) },
      { SIMDE_FLOAT64_C( 37994.81) } },
    { { SIMDE_FLOAT64_C(   673.85) },
      { SIMDE_FLOAT64_C(   112.89) },
      { SIMDE_FLOAT64_C(  -243.00) },
      { SIMDE_FLOAT64_C( 28106.12) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t c = simde_vld1_f64(test_vec[i].c);
    simde_float64x1_t r = simde_vmls_f64(a, b, c);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t c = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vmls_f64(a, b, c);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t c[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C( 109),  INT8_C(  57), -INT8_C(  86),  INT8_C(  50), -INT8_C(  11),  INT8_C(  88), -INT8_C( 121), -INT8_C(  63) },
      {  INT8_C(  31), -INT8_C( 117),  INT8_C(  39),  INT8_C(  85), -INT8_C( 105), -INT8_C(   3),  INT8_C(  78), -INT8_C(  42) },
      {  INT8_C(  53),  INT8_C(  25),  INT8_C(  95), -INT8_C(  29),  INT8_C(  65),  INT8_C( 107), -INT8_C(  31),  INT8_C(  54) },
      {  INT8_C(  40), -INT8_C(  90),  INT8_C(  49), -INT8_C(  45), -INT8_C(  98), -INT8_C( 103), -INT8_C(   7), -INT8_C(  99) } },
    { { -INT8_C(  93), -INT8_C(  72), -INT8_C( 124),  INT8_C(  46),  INT8_C( 126),  INT8_C(  99),  INT8_C(  61),  INT8_C(  18) },
      { -INT8_C( 100), -INT8_C(  24),  INT8_C(  68), -INT8_C( 111),  INT8_C(  64), -INT8_C(  53),  INT8_C(  83),  INT8_C(  95) },
      {  INT8_C(  86),  INT8_C( 122), -INT8_C(  76), -INT8_C(  19),  INT8_C( 119),  INT8_C(   2), -INT8_C(  61), -INT8_C(  84) },
      {  INT8_C(  59),  INT8_C(  40), -INT8_C(  76), -INT8_C(  15), -INT8_C(  66), -INT8_C(  51),  INT8_C(   4),  INT8_C(  62) } },
    { {  INT8_C(  28),  INT8_C(  34), -INT8_C( 113),  INT8_C(  93), -INT8_C( 115),  INT8_C( 112), -INT8_C( 108),  INT8_C(  49) },
      {  INT8_C(  40),  INT8_C(  24),  INT8_C(  95), -INT8_C(  90),  INT8_C( 123), -INT8_C(  99), -INT8_C(  72),  INT8_C(  24) },
      { -INT8_C( 123), -INT8_C(   4), -INT8_C(  87), -INT8_C(  59), -INT8_C(  57), -INT8_C(   4),  INT8_C(  36),  INT8_C(  29) },
      {  INT8_C(  84), -INT8_C( 126), -INT8_C(  40), -INT8_C(  97), -INT8_C(  16), -INT8_C(  28), -INT8_C(  76),  INT8_C( 121) } },
    { {  INT8_C( 118), -INT8_C(  40),  INT8_C(  11), -INT8_C(  19), -INT8_C(  37), -INT8_C(  50), -INT8_C( 103), -INT8_C(   9) },
      { -INT8_C(  15),  INT8_C(  40),  INT8_C(  84),  INT8_C( 126), -INT8_C( 104), -INT8_C(  24), -INT8_C(  81), -INT8_C(  64) },
      {  INT8_C(   1),  INT8_C(  15),  INT8_C( 103),  INT8_C( 124), -INT8_C(  84),  INT8_C(  31), -INT8_C( 108),  INT8_C(  49) },
      { -INT8_C( 123),      INT8_MIN,  INT8_C(  63), -INT8_C(  27), -INT8_C(  69), -INT8_C(  74),  INT8_C( 109),  INT8_C(  55) } },
    { {  INT8_C(  28),  INT8_C(  62), -INT8_C(  10), -INT8_C(  29),  INT8_C(  58),  INT8_C(  26),  INT8_C(   1), -INT8_C(  79) },
      { -INT8_C(  14),  INT8_C(  12), -INT8_C(  98), -INT8_C(  51), -INT8_C(  38),  INT8_C(  56), -INT8_C(  60), -INT8_C(  53) },
      {  INT8_C(  96),  INT8_C(  25),  INT8_C(  74), -INT8_C(   7),  INT8_C(   1), -INT8_C(   7), -INT8_C(  71),  INT8_C(   2) },
      {  INT8_C(  92),  INT8_C(  18),  INT8_C(  74),  INT8_C( 126),  INT8_C(  96), -INT8_C(  94),  INT8_C(  93),  INT8_C(  27) } },
    { {  INT8_C(   8),  INT8_C(  32),      INT8_MAX, -INT8_C(  76),  INT8_C(  64),  INT8_C(  19), -INT8_C(  27),  INT8_C(  92) },
      {  INT8_C(  81), -INT8_C(  37),  INT8_C(  63), -INT8_C( 116), -INT8_C(  11),  INT8_C(  64),  INT8_C(  61), -INT8_C(  24) },
      {  INT8_C(  76), -INT8_C(  37), -INT8_C(  75),  INT8_C(  39),  INT8_C(  19),  INT8_C( 122), -INT8_C(  14),  INT8_C( 116) },
      { -INT8_C(   4), -INT8_C(  57), -INT8_C(  12),  INT8_C(  96),  INT8_C(  17), -INT8_C( 109),  INT8_C(  59),  INT8_C(  60) } },
    { { -INT8_C( 109),  INT8_C(  60),  INT8_C( 109), -INT8_C( 108),  INT8_C(  54),  INT8_C(  38), -INT8_C( 105),  INT8_C(  62) },
      {  INT8_C(  71),  INT8_C(  22), -INT8_C(  13), -INT8_C( 121),  INT8_C(  41), -INT8_C(  40), -INT8_C(  29),  INT8_C( 123) },
      { -INT8_C(  76),  INT8_C(  34),  INT8_C(   7), -INT8_C(  87),  INT8_C(  99),  INT8_C(  68), -INT8_C( 111), -INT8_C(  81) },
      { -INT8_C(  89),  INT8_C(  80), -INT8_C(  56),  INT8_C( 117),  INT8_C(  91), -INT8_C(  58),  INT8_C(   4),  INT8_C(  41) } },
    { {  INT8_C(  31),  INT8_C(  71), -INT8_C(  42),  INT8_C(  51), -INT8_C(  63), -INT8_C(  55), -INT8_C(  89),  INT8_C(  84) },
      {  INT8_C(   5),  INT8_C(  20), -INT8_C(  24),  INT8_C(  59),  INT8_C(  58),      INT8_MAX,  INT8_C( 122), -INT8_C( 127) },
      { -INT8_C( 107),  INT8_C( 109),  INT8_C(   8), -INT8_C(  65),  INT8_C(  69), -INT8_C(  21),  INT8_C(  58), -INT8_C(   7) },
      {  INT8_C(  54), -INT8_C(  61), -INT8_C( 106),  INT8_C(  46),  INT8_C(  31),  INT8_C(  52),  INT8_C(   3), -INT8_C(  37) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t c = simde_vld1_s8(test_vec[i].c);
    simde_int8x8_t r = simde_vmls_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t c = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vmls_s8(a, b, c);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t c[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 16654),  INT16_C( 29091),  INT16_C( 13445), -INT16_C( 23520) },
      { -INT16_C(  2181),  INT16_C( 15575),  INT16_C( 32448), -INT16_C( 14960) },
      {  INT16_C( 31122), -INT16_C( 13055),  INT16_C( 31736), -INT16_C( 29106) },
      { -INT16_C(  1560),  INT16_C(  2508),  INT16_C( 10885), -INT16_C( 28096) } },
    { {  INT16_C( 22504),  INT16_C( 11597), -INT16_C( 30910),  INT16_C( 20519) },
      { -INT16_C( 13624),  INT16_C( 19905), -INT16_C(  7426),  INT16_C( 31473) },
      { -INT16_C( 13863), -INT16_C( 26186),  INT16_C( 18247), -INT16_C(  9634) },
      {  INT16_C( 27744), -INT16_C( 29417),  INT16_C(  8400), -INT16_C(  3671) } },
    { {  INT16_C( 24512), -INT16_C( 18265), -INT16_C(  2598), -INT16_C( 15802) },
      { -INT16_C( 27828), -INT16_C( 28688),  INT16_C(  5914), -INT16_C(  7457) },
      { -INT16_C( 24095), -INT16_C(  8401),  INT16_C(  8579),  INT16_C( 23641) },
      {  INT16_C(  7668),  INT16_C( 15255), -INT16_C( 13940), -INT16_C( 16705) } },
    { {  INT16_C(  4330),  INT16_C( 12789),  INT16_C( 21335),  INT16_C(  5899) },
      { -INT16_C( 19789), -INT16_C( 29233),  INT16_C(  5800), -INT16_C(  2992) },
      {  INT16_C( 16553), -INT16_C( 15229),  INT16_C( 25431),  INT16_C( 14502) },
      {  INT16_C( 22719),  INT16_C(  9480), -INT16_C( 22465),  INT16_C( 11051) } },
    { { -INT16_C( 10748), -INT16_C( 30953),  INT16_C( 29175), -INT16_C(  7709) },
      { -INT16_C( 10111), -INT16_C( 10222),  INT16_C(  7723), -INT16_C(  8465) },
      { -INT16_C( 16688),  INT16_C( 30828), -INT16_C( 17196),  INT16_C( 32365) },
      {  INT16_C( 12084), -INT16_C(  4225), -INT16_C(  7589),  INT16_C( 21536) } },
    { { -INT16_C(  3844),  INT16_C( 21314), -INT16_C(  6061),  INT16_C( 22411) },
      { -INT16_C( 23874), -INT16_C( 18978), -INT16_C( 16109), -INT16_C( 27498) },
      { -INT16_C( 22119), -INT16_C( 14996),  INT16_C( 23495), -INT16_C( 26717) },
      {  INT16_C( 16238), -INT16_C( 15462),  INT16_C(  4494),  INT16_C( 16905) } },
    { {  INT16_C(  3866), -INT16_C(  4592),  INT16_C( 32203), -INT16_C( 14484) },
      { -INT16_C( 20883), -INT16_C( 16102), -INT16_C( 23145),  INT16_C( 21784) },
      { -INT16_C(  2232),  INT16_C( 23307), -INT16_C( 24136),  INT16_C( 21232) },
      { -INT16_C( 10894),  INT16_C( 25586), -INT16_C( 32189),  INT16_C( 20716) } },
    { {  INT16_C( 23626),  INT16_C(  4375), -INT16_C( 17736), -INT16_C( 11607) },
      { -INT16_C( 17974), -INT16_C( 27200),  INT16_C( 11574), -INT16_C( 23715) },
      {  INT16_C( 30683),  INT16_C( 29284),  INT16_C( 32029),  INT16_C( 26056) },
      { -INT16_C( 31108),  INT16_C(  4631),  INT16_C( 15770), -INT16_C( 32511) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int16x4_t r = simde_vmls_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t c = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vmls_s16(a, b, c);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t c[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   750834548), -INT32_C(  1082216332) },
      { -INT32_C(   976186099),  INT32_C(   446134608) },
      {  INT32_C(  1756321586),  INT32_C(  1611402372) },
      {  INT32_C(  2071546858),  INT32_C(  1072980788) } },
    { { -INT32_C(  1580044156),  INT32_C(  1627822829) },
      { -INT32_C(   493959571), -INT32_C(  2069820297) },
      { -INT32_C(   230067806),  INT32_C(   487383275) },
      { -INT32_C(  1630682486), -INT32_C(  1514927696) } },
    { { -INT32_C(  1132020937),  INT32_C(  1276941000) },
      { -INT32_C(   252842494), -INT32_C(   162401399) },
      {  INT32_C(   819519417), -INT32_C(  1900774932) },
      {  INT32_C(   747765189),  INT32_C(  1109413756) } },
    { { -INT32_C(   696189461),  INT32_C(   368282845) },
      {  INT32_C(   265386311),  INT32_C(   240905483) },
      {  INT32_C(  1694386395), -INT32_C(   178565317) },
      {  INT32_C(  1405109806), -INT32_C(  1632336300) } },
    { {  INT32_C(   455422767), -INT32_C(  1733698899) },
      { -INT32_C(  1251071529), -INT32_C(    53845579) },
      { -INT32_C(   435381285),  INT32_C(  1676961672) },
      {  INT32_C(   310262594), -INT32_C(  1068359803) } },
    { { -INT32_C(   339152208),  INT32_C(  1910514498) },
      {  INT32_C(    59508310), -INT32_C(  1214564896) },
      {  INT32_C(   325847390),  INT32_C(  1175402091) },
      { -INT32_C(  1545758436), -INT32_C(  1903993182) } },
    { {  INT32_C(  1496062929),  INT32_C(   868032899) },
      {  INT32_C(  1428063507), -INT32_C(    20512856) },
      { -INT32_C(   452832763), -INT32_C(   442720889) },
      { -INT32_C(   540185486), -INT32_C(  1146992661) } },
    { {  INT32_C(   318245287),  INT32_C(   290981951) },
      { -INT32_C(  1502968797), -INT32_C(  1176950875) },
      {  INT32_C(  1410267308), -INT32_C(    61614601) },
      {  INT32_C(  1568365091), -INT32_C(   866681076) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int32x2_t r = simde_vmls_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t c = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vmls_s32(a, b, c);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t c[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 39), UINT8_C( 85), UINT8_C(225), UINT8_C(175), UINT8_C(242), UINT8_C(125), UINT8_C(148), UINT8_C(153) },
      { UINT8_C(134), UINT8_C(141), UINT8_C(171), UINT8_C(198), UINT8_C(149), UINT8_C(  3), UINT8_C(215), UINT8_C(184) },
      { UINT8_C(136), UINT8_C( 65), UINT8_C( 95), UINT8_C( 45), UINT8_C(105), UINT8_C( 56), UINT8_C(230), UINT8_C( 21) },
      { UINT8_C(247), UINT8_C(136), UINT8_C(108), UINT8_C(225), UINT8_C(213), UINT8_C(213), UINT8_C(106), UINT8_C(129) } },
    { { UINT8_C( 48), UINT8_C(245), UINT8_C(106), UINT8_C( 39), UINT8_C(202), UINT8_C(189), UINT8_C( 35), UINT8_C(241) },
      { UINT8_C( 18), UINT8_C(  4), UINT8_C(160), UINT8_C(  4), UINT8_C(130), UINT8_C( 53), UINT8_C(158), UINT8_C(  8) },
      { UINT8_C(194), UINT8_C( 73), UINT8_C(206), UINT8_C( 87), UINT8_C( 77), UINT8_C(165), UINT8_C( 15), UINT8_C(213) },
      { UINT8_C(140), UINT8_C(209), UINT8_C(170), UINT8_C(203), UINT8_C(176), UINT8_C(148), UINT8_C(225), UINT8_C( 73) } },
    { { UINT8_C(231), UINT8_C(110), UINT8_C(  2), UINT8_C( 80), UINT8_C(167), UINT8_C(233), UINT8_C(101), UINT8_C(215) },
      { UINT8_C(222), UINT8_C(207),    UINT8_MAX, UINT8_C(168), UINT8_C(140), UINT8_C( 34), UINT8_C(153), UINT8_C(158) },
      { UINT8_C( 39), UINT8_C( 58), UINT8_C(163), UINT8_C(169), UINT8_C(111), UINT8_C( 65), UINT8_C(177), UINT8_C( 49) },
      { UINT8_C( 21), UINT8_C(136), UINT8_C(165), UINT8_C(104), UINT8_C(243), UINT8_C( 71), UINT8_C(156), UINT8_C(153) } },
    { { UINT8_C(138), UINT8_C(128), UINT8_C(136), UINT8_C(215), UINT8_C( 37), UINT8_C(151), UINT8_C(172), UINT8_C( 12) },
      { UINT8_C(  6), UINT8_C(175), UINT8_C( 92), UINT8_C(173), UINT8_C(152), UINT8_C(194), UINT8_C(132), UINT8_C(118) },
      { UINT8_C(145), UINT8_C(131), UINT8_C( 30), UINT8_C( 30), UINT8_C(166), UINT8_C(183), UINT8_C(188), UINT8_C(205) },
      { UINT8_C( 36), UINT8_C(243), UINT8_C(192), UINT8_C(145), UINT8_C(149), UINT8_C(233), UINT8_C(188), UINT8_C(142) } },
    { { UINT8_C(241), UINT8_C( 95), UINT8_C(118), UINT8_C( 96), UINT8_C(160), UINT8_C( 39), UINT8_C(145), UINT8_C( 43) },
      { UINT8_C(167), UINT8_C( 25), UINT8_C(  2), UINT8_C(205), UINT8_C(177), UINT8_C(175), UINT8_C(217), UINT8_C(183) },
      { UINT8_C( 94), UINT8_C( 54), UINT8_C(100), UINT8_C(246), UINT8_C(248), UINT8_C(232), UINT8_C(108), UINT8_C(137) },
      { UINT8_C(159), UINT8_C( 25), UINT8_C(174), UINT8_C( 98), UINT8_C( 40), UINT8_C(143), UINT8_C(  5), UINT8_C( 60) } },
    { { UINT8_C(108), UINT8_C(138), UINT8_C(167), UINT8_C( 18), UINT8_C( 65), UINT8_C(100), UINT8_C(223), UINT8_C( 51) },
      { UINT8_C(195), UINT8_C( 85), UINT8_C(147), UINT8_C(100), UINT8_C(124), UINT8_C( 37), UINT8_C(143), UINT8_C( 36) },
      { UINT8_C( 62), UINT8_C(145), UINT8_C(241), UINT8_C(239), UINT8_C( 64), UINT8_C(202), UINT8_C(166), UINT8_C(158) },
      { UINT8_C( 50), UINT8_C(101), UINT8_C( 68), UINT8_C(182), UINT8_C( 65), UINT8_C( 50), UINT8_C( 37), UINT8_C(251) } },
    { { UINT8_C(  0), UINT8_C( 10), UINT8_C(148), UINT8_C(248), UINT8_C(243), UINT8_C(  0), UINT8_C(130), UINT8_C( 95) },
      { UINT8_C(138), UINT8_C( 41), UINT8_C(113), UINT8_C(204), UINT8_C(141), UINT8_C( 80),    UINT8_MAX, UINT8_C( 81) },
      { UINT8_C(165), UINT8_C(146), UINT8_C(181), UINT8_C( 33), UINT8_C(183), UINT8_C( 68), UINT8_C( 69), UINT8_C(246) },
      { UINT8_C( 14), UINT8_C(168), UINT8_C(175), UINT8_C(172), UINT8_C( 40), UINT8_C(192), UINT8_C(199), UINT8_C(137) } },
    { { UINT8_C(213), UINT8_C( 54), UINT8_C(229), UINT8_C( 22), UINT8_C(  1), UINT8_C(140), UINT8_C(180), UINT8_C(  1) },
      { UINT8_C(150), UINT8_C( 73), UINT8_C(250), UINT8_C(137), UINT8_C( 73), UINT8_C(124), UINT8_C(232), UINT8_C(212) },
      { UINT8_C(165), UINT8_C( 89), UINT8_C(160), UINT8_C( 51), UINT8_C(169), UINT8_C(159), UINT8_C(132), UINT8_C( 78) },
      { UINT8_C( 39), UINT8_C(213), UINT8_C(165), UINT8_C(203), UINT8_C(208), UINT8_C(136), UINT8_C( 20), UINT8_C(105) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t c = simde_vld1_u8(test_vec[i].c);
    simde_uint8x8_t r = simde_vmls_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t c = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vmls_u8(a, b, c);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t c[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(14641), UINT16_C(59760), UINT16_C(46461), UINT16_C(21215) },
      { UINT16_C(50412), UINT16_C(60776), UINT16_C( 7504), UINT16_C(59374) },
      { UINT16_C(59494), UINT16_C(44912), UINT16_C(22884), UINT16_C( 2691) },
      { UINT16_C(58153), UINT16_C(62448), UINT16_C(29245), UINT16_C(22549) } },
    { { UINT16_C( 9138), UINT16_C(23613), UINT16_C(49602), UINT16_C(62634) },
      { UINT16_C( 6906), UINT16_C(30685), UINT16_C(48336), UINT16_C(48329) },
      { UINT16_C(12928), UINT16_C(53673), UINT16_C(38735), UINT16_C(46520) },
      { UINT16_C(53938), UINT16_C(52824), UINT16_C(52626), UINT16_C(10034) } },
    { { UINT16_C(10368), UINT16_C(58468), UINT16_C(59521), UINT16_C(13550) },
      { UINT16_C(11019), UINT16_C(52880), UINT16_C(15084), UINT16_C(59074) },
      { UINT16_C(40789), UINT16_C( 9565), UINT16_C(10075), UINT16_C(56289) },
      { UINT16_C( 2265), UINT16_C( 2580), UINT16_C(  669), UINT16_C(28268) } },
    { { UINT16_C(35417), UINT16_C(43180), UINT16_C(25633), UINT16_C(41309) },
      { UINT16_C(49549), UINT16_C( 3718), UINT16_C(29865), UINT16_C(46402) },
      { UINT16_C(53920), UINT16_C(35971), UINT16_C(17677), UINT16_C(25203) },
      { UINT16_C(59449), UINT16_C(61978), UINT16_C(60044), UINT16_C(61623) } },
    { { UINT16_C(53476), UINT16_C(16263), UINT16_C(26871), UINT16_C(20506) },
      { UINT16_C(51186), UINT16_C( 5112), UINT16_C(21803), UINT16_C(47285) },
      { UINT16_C(15127), UINT16_C(49351), UINT16_C( 2479), UINT16_C(20341) },
      { UINT16_C( 5158), UINT16_C(47551), UINT16_C(44434), UINT16_C( 2657) } },
    { { UINT16_C(63708), UINT16_C(59868), UINT16_C(20285), UINT16_C( 8523) },
      { UINT16_C(53791), UINT16_C( 5984), UINT16_C(31546), UINT16_C(11367) },
      { UINT16_C(24642), UINT16_C(27967), UINT16_C(62645), UINT16_C(52262) },
      { UINT16_C(11486), UINT16_C(18748), UINT16_C(59195), UINT16_C(30209) } },
    { { UINT16_C(60719), UINT16_C(57229), UINT16_C(  758), UINT16_C(53806) },
      { UINT16_C( 2811), UINT16_C(14523), UINT16_C( 1625), UINT16_C(31066) },
      { UINT16_C(47832), UINT16_C( 4752), UINT16_C(63285), UINT16_C(30526) },
      { UINT16_C(19303), UINT16_C(53341), UINT16_C(54153), UINT16_C(39010) } },
    { { UINT16_C(32343), UINT16_C( 3557), UINT16_C( 2930), UINT16_C(41689) },
      { UINT16_C(26360), UINT16_C(61057), UINT16_C(44905), UINT16_C(25793) },
      { UINT16_C(31930), UINT16_C( 5020), UINT16_C(63107), UINT16_C(23436) },
      { UINT16_C(36391), UINT16_C( 9289), UINT16_C(25271), UINT16_C(61005) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t c = simde_vld1_u16(test_vec[i].c);
    simde_uint16x4_t r = simde_vmls_u16(a, b, c);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t c = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vmls_u16(a, b, c);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t c[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3865975985), UINT32_C(1801366548) },
      { UINT32_C(2641904426), UINT32_C(1178554958) },
      { UINT32_C( 557105336), UINT32_C( 696644975) },
      { UINT32_C(1997952641), UINT32_C( 463427138) } },
    { { UINT32_C(4114424434), UINT32_C(3377514776) },
      { UINT32_C(4205887206), UINT32_C(2506428011) },
      { UINT32_C(2670911057), UINT32_C(3907350832) },
      { UINT32_C( 987318188), UINT32_C(1296685576) } },
    { { UINT32_C(2701793585), UINT32_C(2177535759) },
      { UINT32_C(3396732849), UINT32_C(3079915217) },
      { UINT32_C(4038148997), UINT32_C(2726630993) },
      { UINT32_C(1280558908), UINT32_C( 744337646) } },
    { { UINT32_C( 608286964), UINT32_C(1527588393) },
      { UINT32_C(1341921088), UINT32_C(1490077350) },
      { UINT32_C(2669823694), UINT32_C(2438378764) },
      { UINT32_C(  42697588), UINT32_C(3540809825) } },
    { { UINT32_C(1249970169), UINT32_C( 317523741) },
      { UINT32_C(3895865023), UINT32_C(2504213333) },
      { UINT32_C(  31735642), UINT32_C(3562648582) },
      { UINT32_C(4040660947), UINT32_C(2071244575) } },
    { { UINT32_C( 108231674), UINT32_C( 697878832) },
      { UINT32_C(3983808976), UINT32_C(3758055712) },
      { UINT32_C(3838326415), UINT32_C(3564702585) },
      { UINT32_C(2057777354), UINT32_C(3902243088) } },
    { { UINT32_C(1372937547), UINT32_C( 186986001) },
      { UINT32_C(3641874601), UINT32_C( 822323809) },
      { UINT32_C(3827201987), UINT32_C(1740840664) },
      { UINT32_C(3957753232), UINT32_C(1932725817) } },
    { { UINT32_C(3444345684), UINT32_C(3802252695) },
      { UINT32_C( 875787811), UINT32_C(1296062628) },
      { UINT32_C(1361531632), UINT32_C(3212978940) },
      { UINT32_C(1323406468), UINT32_C(3916930087) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t c = simde_vld1_u32(test_vec[i].c);
    simde_uint32x2_t r = simde_vmls_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t c = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vmls_u32(a, b, c);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 c[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   596.92), SIMDE_FLOAT32_C(  -413.27), SIMDE_FLOAT32_C(   717.20), SIMDE_FLOAT32_C(  -915.06) },
      { SIMDE_FLOAT32_C(  -486.72), SIMDE_FLOAT32_C(   408.94), SIMDE_FLOAT32_C(  -871.24), SIMDE_FLOAT32_C(   518.77) },
      { SIMDE_FLOAT32_C(   984.39), SIMDE_FLOAT32_C(  -416.38), SIMDE_FLOAT32_C(   953.84), SIMDE_FLOAT32_C(  -338.43) },
      { SIMDE_FLOAT32_C(479719.22), SIMDE_FLOAT32_C(169861.17), SIMDE_FLOAT32_C(831740.75), SIMDE_FLOAT32_C(174652.27) } },
    { { SIMDE_FLOAT32_C(  -409.52), SIMDE_FLOAT32_C(  -800.89), SIMDE_FLOAT32_C(   109.19), SIMDE_FLOAT32_C(    12.08) },
      { SIMDE_FLOAT32_C(   528.53), SIMDE_FLOAT32_C(  -884.21), SIMDE_FLOAT32_C(  -913.46), SIMDE_FLOAT32_C(   551.48) },
      { SIMDE_FLOAT32_C(  -761.40), SIMDE_FLOAT32_C(  -258.52), SIMDE_FLOAT32_C(   301.97), SIMDE_FLOAT32_C(  -198.07) },
      { SIMDE_FLOAT32_C(402013.25), SIMDE_FLOAT32_C(-229386.86), SIMDE_FLOAT32_C(275946.72), SIMDE_FLOAT32_C(109243.72) } },
    { { SIMDE_FLOAT32_C(  -503.83), SIMDE_FLOAT32_C(    16.75), SIMDE_FLOAT32_C(  -286.53), SIMDE_FLOAT32_C(    -6.86) },
      { SIMDE_FLOAT32_C(   487.42), SIMDE_FLOAT32_C(  -978.12), SIMDE_FLOAT32_C(   184.61), SIMDE_FLOAT32_C(    84.33) },
      { SIMDE_FLOAT32_C(  -391.38), SIMDE_FLOAT32_C(   -98.19), SIMDE_FLOAT32_C(   169.27), SIMDE_FLOAT32_C(   121.90) },
      { SIMDE_FLOAT32_C(190262.62), SIMDE_FLOAT32_C(-96024.85), SIMDE_FLOAT32_C(-31535.46), SIMDE_FLOAT32_C(-10286.69) } },
    { { SIMDE_FLOAT32_C(  -689.25), SIMDE_FLOAT32_C(   298.04), SIMDE_FLOAT32_C(  -359.33), SIMDE_FLOAT32_C(  -704.86) },
      { SIMDE_FLOAT32_C(   881.65), SIMDE_FLOAT32_C(  -405.49), SIMDE_FLOAT32_C(   -43.29), SIMDE_FLOAT32_C(  -527.87) },
      { SIMDE_FLOAT32_C(  -206.39), SIMDE_FLOAT32_C(  -934.10), SIMDE_FLOAT32_C(   484.22), SIMDE_FLOAT32_C(  -677.86) },
      { SIMDE_FLOAT32_C(181274.50), SIMDE_FLOAT32_C(-378470.16), SIMDE_FLOAT32_C( 20602.55), SIMDE_FLOAT32_C(-358526.81) } },
    { { SIMDE_FLOAT32_C(  -818.31), SIMDE_FLOAT32_C(   570.75), SIMDE_FLOAT32_C(   873.62), SIMDE_FLOAT32_C(  -579.71) },
      { SIMDE_FLOAT32_C(  -687.77), SIMDE_FLOAT32_C(   175.59), SIMDE_FLOAT32_C(   222.23), SIMDE_FLOAT32_C(  -191.61) },
      { SIMDE_FLOAT32_C(  -807.66), SIMDE_FLOAT32_C(   935.69), SIMDE_FLOAT32_C(   801.53), SIMDE_FLOAT32_C(   679.76) },
      { SIMDE_FLOAT32_C(-556302.62), SIMDE_FLOAT32_C(-163727.05), SIMDE_FLOAT32_C(-177250.39), SIMDE_FLOAT32_C(129669.10) } },
    { { SIMDE_FLOAT32_C(   957.58), SIMDE_FLOAT32_C(   -13.85), SIMDE_FLOAT32_C(  -235.91), SIMDE_FLOAT32_C(  -433.81) },
      { SIMDE_FLOAT32_C(   887.96), SIMDE_FLOAT32_C(   933.36), SIMDE_FLOAT32_C(   688.09), SIMDE_FLOAT32_C(  -801.30) },
      { SIMDE_FLOAT32_C(   231.40), SIMDE_FLOAT32_C(  -671.24), SIMDE_FLOAT32_C(  -506.16), SIMDE_FLOAT32_C(   113.05) },
      { SIMDE_FLOAT32_C(-204516.36), SIMDE_FLOAT32_C(626494.69), SIMDE_FLOAT32_C(348047.75), SIMDE_FLOAT32_C( 90153.16) } },
    { { SIMDE_FLOAT32_C(   -76.73), SIMDE_FLOAT32_C(   450.55), SIMDE_FLOAT32_C(   585.19), SIMDE_FLOAT32_C(   716.88) },
      { SIMDE_FLOAT32_C(   516.45), SIMDE_FLOAT32_C(    69.40), SIMDE_FLOAT32_C(  -960.98), SIMDE_FLOAT32_C(   698.14) },
      { SIMDE_FLOAT32_C(  -359.85), SIMDE_FLOAT32_C(   912.64), SIMDE_FLOAT32_C(  -881.57), SIMDE_FLOAT32_C(   -47.62) },
      { SIMDE_FLOAT32_C(185767.81), SIMDE_FLOAT32_C(-62886.67), SIMDE_FLOAT32_C(-846585.94), SIMDE_FLOAT32_C( 33962.30) } },
    { { SIMDE_FLOAT32_C(    88.23), SIMDE_FLOAT32_C(   340.65), SIMDE_FLOAT32_C(   760.78), SIMDE_FLOAT32_C(   280.57) },
      { SIMDE_FLOAT32_C(   276.34), SIMDE_FLOAT32_C(   562.31), SIMDE_FLOAT32_C(   -39.67), SIMDE_FLOAT32_C(   233.92) },
      { SIMDE_FLOAT32_C(  -451.55), SIMDE_FLOAT32_C(   724.42), SIMDE_FLOAT32_C(   800.11), SIMDE_FLOAT32_C(  -563.59) },
      { SIMDE_FLOAT32_C(124869.55), SIMDE_FLOAT32_C(-407007.94), SIMDE_FLOAT32_C( 32501.14), SIMDE_FLOAT32_C(132115.55) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t c = simde_vld1q_f32(test_vec[i].c);
    simde_float32x4_t r = simde_vmlsq_f32(a, b, c);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_float32x4_t c = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_float32x4_t r = simde_vmlsq_f32(a, b, c);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 c[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   657.78), SIMDE_FLOAT64_C(   488.21) },
      { SIMDE_FLOAT64_C(  -364.89), SIMDE_FLOAT64_C(  -110.82) },
      { SIMDE_FLOAT64_C(   816.97), SIMDE_FLOAT64_C(   128.95) },
      { SIMDE_FLOAT64_C(298761.96), SIMDE_FLOAT64_C( 14778.45) } },
    { { SIMDE_FLOAT64_C(  -997.76), SIMDE_FLOAT64_C(  -259.76) },
      { SIMDE_FLOAT64_C(  -420.50), SIMDE_FLOAT64_C(   587.42) },
      { SIMDE_FLOAT64_C(  -542.88), SIMDE_FLOAT64_C(  -904.05) },
      { SIMDE_FLOAT64_C(-229278.80), SIMDE_FLOAT64_C(530797.29) } },
    { { SIMDE_FLOAT64_C(  -343.18), SIMDE_FLOAT64_C(  -503.86) },
      { SIMDE_FLOAT64_C(   794.08), SIMDE_FLOAT64_C(   296.98) },
      { SIMDE_FLOAT64_C(  -591.22), SIMDE_FLOAT64_C(   912.51) },
      { SIMDE_FLOAT64_C(469132.80), SIMDE_FLOAT64_C(-271501.08) } },
    { { SIMDE_FLOAT64_C(  -750.64), SIMDE_FLOAT64_C(   497.01) },
      { SIMDE_FLOAT64_C(   253.16), SIMDE_FLOAT64_C(  -989.86) },
      { SIMDE_FLOAT64_C(  -222.42), SIMDE_FLOAT64_C(  -470.49) },
      { SIMDE_FLOAT64_C( 55557.21), SIMDE_FLOAT64_C(-465222.22) } },
    { { SIMDE_FLOAT64_C(   572.44), SIMDE_FLOAT64_C(   737.91) },
      { SIMDE_FLOAT64_C(   763.43), SIMDE_FLOAT64_C(  -879.10) },
      { SIMDE_FLOAT64_C(   462.33), SIMDE_FLOAT64_C(   563.54) },
      { SIMDE_FLOAT64_C(-352384.15), SIMDE_FLOAT64_C(496145.92) } },
    { { SIMDE_FLOAT64_C(  -442.69), SIMDE_FLOAT64_C(   120.11) },
      { SIMDE_FLOAT64_C(    51.75), SIMDE_FLOAT64_C(   192.42) },
      { SIMDE_FLOAT64_C(  -990.71), SIMDE_FLOAT64_C(  -131.28) },
      { SIMDE_FLOAT64_C( 50826.55), SIMDE_FLOAT64_C( 25381.01) } },
    { { SIMDE_FLOAT64_C(  -678.63), SIMDE_FLOAT64_C(  -988.47) },
      { SIMDE_FLOAT64_C(   608.96), SIMDE_FLOAT64_C(   -99.13) },
      { SIMDE_FLOAT64_C(   598.95), SIMDE_FLOAT64_C(  -933.92) },
      { SIMDE_FLOAT64_C(-365415.22), SIMDE_FLOAT64_C(-93567.96) } },
    { { SIMDE_FLOAT64_C(    -3.18), SIMDE_FLOAT64_C(  -744.22) },
      { SIMDE_FLOAT64_C(  -437.78), SIMDE_FLOAT64_C(  -209.09) },
      { SIMDE_FLOAT64_C(   552.75), SIMDE_FLOAT64_C(   -29.00) },
      { SIMDE_FLOAT64_C(241979.71), SIMDE_FLOAT64_C( -6807.83) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t c = simde_vld1q_f64(test_vec[i].c);
    simde_float64x2_t r = simde_vmlsq_f64(a, b, c);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t c = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vmlsq_f64(a, b, c);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t c[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  21), -INT8_C(  27), -INT8_C(  75), -INT8_C( 105),  INT8_C(  87),  INT8_C(  49),  INT8_C( 102), -INT8_C( 101),
        -INT8_C(   5),  INT8_C(  77),  INT8_C(  55),  INT8_C(  70), -INT8_C( 100), -INT8_C(  22), -INT8_C( 102), -INT8_C(  70) },
      {  INT8_C(  24), -INT8_C(  76),  INT8_C(  58), -INT8_C(  75), -INT8_C(  75), -INT8_C(  69), -INT8_C(  42),  INT8_C(  15),
         INT8_C( 103),  INT8_C(  23), -INT8_C(  97), -INT8_C(  19),  INT8_C(  60), -INT8_C(  12),  INT8_C(  29),  INT8_C(  39) },
      { -INT8_C(  39), -INT8_C(  46), -INT8_C(  65),  INT8_C(  48),  INT8_C(   3),  INT8_C(  37), -INT8_C(  52), -INT8_C(   2),
         INT8_C( 115),  INT8_C(   3),  INT8_C(  68),  INT8_C(  15), -INT8_C(  19), -INT8_C(  34), -INT8_C(  55),  INT8_C(   5) },
      { -INT8_C( 109),  INT8_C(  61),  INT8_C( 111), -INT8_C(  89),  INT8_C(  56),  INT8_C(  42), -INT8_C(  34), -INT8_C(  71),
        -INT8_C(  74),  INT8_C(   8), -INT8_C(   5),  INT8_C(  99),  INT8_C(  16),  INT8_C(  82), -INT8_C(  43), -INT8_C(   9) } },
    { { -INT8_C( 109),  INT8_C(   3), -INT8_C(  69),  INT8_C(  72), -INT8_C(  65), -INT8_C( 111),  INT8_C(  87),  INT8_C(  38),
        -INT8_C(  87), -INT8_C(  10),  INT8_C(  20), -INT8_C(  27), -INT8_C(  22),  INT8_C(  49),  INT8_C(  13), -INT8_C(  61) },
      {  INT8_C(   4), -INT8_C(  52), -INT8_C(  13),  INT8_C(   7), -INT8_C(  15), -INT8_C(  65),  INT8_C(   6),  INT8_C( 100),
        -INT8_C(  62),  INT8_C(  74),  INT8_C( 115), -INT8_C(  80),  INT8_C(  41),  INT8_C(  60), -INT8_C(  75), -INT8_C(  68) },
      {  INT8_C(  64),  INT8_C( 112),  INT8_C(   4), -INT8_C(   1),  INT8_C(   2),  INT8_C(  91),  INT8_C(  37), -INT8_C(  85),
         INT8_C(  81),  INT8_C(  57), -INT8_C( 112),  INT8_C(  59),  INT8_C( 107), -INT8_C(  99), -INT8_C(   2),  INT8_C( 111) },
      { -INT8_C( 109), -INT8_C(  61), -INT8_C(  17),  INT8_C(  79), -INT8_C(  35), -INT8_C(  84),  INT8_C( 121),  INT8_C(  90),
         INT8_C(  71),  INT8_C( 124),  INT8_C( 100),  INT8_C(  85), -INT8_C(  57),  INT8_C( 101),  INT8_C( 119),  INT8_C(  63) } },
    { {  INT8_C( 105), -INT8_C(  15),  INT8_C( 118),  INT8_C(  91), -INT8_C(  79),  INT8_C( 124), -INT8_C(  65),  INT8_C( 115),
        -INT8_C(  57),  INT8_C(  51),  INT8_C(  35), -INT8_C(  16),  INT8_C( 111), -INT8_C(  39), -INT8_C(  84), -INT8_C(  81) },
      {  INT8_C(  73), -INT8_C(  80), -INT8_C(  82),  INT8_C(  75),  INT8_C(  11), -INT8_C(  44), -INT8_C(  10),  INT8_C(  92),
         INT8_C(  13), -INT8_C( 121), -INT8_C( 105),  INT8_C( 120),  INT8_C(  36), -INT8_C( 107), -INT8_C(  25), -INT8_C( 114) },
      { -INT8_C( 122),  INT8_C(  94), -INT8_C(  23),  INT8_C(  55), -INT8_C(  38), -INT8_C(  88), -INT8_C(  85), -INT8_C(  95),
        -INT8_C(  37), -INT8_C(  50), -INT8_C( 111),  INT8_C(  75), -INT8_C(  89),  INT8_C(  61), -INT8_C(   6), -INT8_C(  15) },
      {  INT8_C(  51),  INT8_C(  81),  INT8_C(  24),  INT8_C(  62),  INT8_C(  83),  INT8_C(  92),  INT8_C( 109), -INT8_C( 105),
        -INT8_C(  88), -INT8_C( 111), -INT8_C( 100), -INT8_C(  56), -INT8_C(  13),  INT8_C(  88),  INT8_C(  22),  INT8_C(   1) } },
    { { -INT8_C(  19), -INT8_C(  87),  INT8_C(  60), -INT8_C(   8),  INT8_C( 125),  INT8_C(  51),  INT8_C(  84), -INT8_C( 118),
        -INT8_C(  70), -INT8_C(  21),  INT8_C(   3), -INT8_C(  34),      INT8_MIN, -INT8_C(  22),  INT8_C( 108),  INT8_C(   7) },
      {  INT8_C(  72),  INT8_C(  85),  INT8_C(  62),  INT8_C(  35), -INT8_C(   2), -INT8_C(  23), -INT8_C(  60), -INT8_C(  39),
        -INT8_C(  72),  INT8_C(  86),  INT8_C(  36),  INT8_C(  95), -INT8_C( 109),  INT8_C(  31),  INT8_C(  80), -INT8_C( 127) },
      { -INT8_C(  56), -INT8_C( 115),  INT8_C( 121),  INT8_C(  69), -INT8_C(  64), -INT8_C(  50), -INT8_C(  49),  INT8_C( 122),
        -INT8_C(  71), -INT8_C(  46),  INT8_C(  88),  INT8_C(  58), -INT8_C(  67), -INT8_C(  59),  INT8_C(  65),  INT8_C(   5) },
      { -INT8_C(  83), -INT8_C(  40), -INT8_C(  18), -INT8_C( 119), -INT8_C(   3), -INT8_C(  75), -INT8_C(  40),  INT8_C(  32),
        -INT8_C(  62),  INT8_C(  95), -INT8_C(  93),  INT8_C(  88), -INT8_C(   7),  INT8_C(  15),  INT8_C(  28), -INT8_C( 126) } },
    { {  INT8_C(  26),      INT8_MAX,  INT8_C(  40),  INT8_C(  24),  INT8_C( 105), -INT8_C(  19), -INT8_C(  14),  INT8_C(  33),
         INT8_C(  67),  INT8_C(  22),      INT8_MIN, -INT8_C(  42),  INT8_C(  53), -INT8_C(  47),  INT8_C(  87), -INT8_C(   3) },
      {  INT8_C(  94), -INT8_C(  47),  INT8_C(  66),  INT8_C(  30), -INT8_C(  97),  INT8_C(  18), -INT8_C( 104),  INT8_C(  88),
        -INT8_C(  28), -INT8_C(  16), -INT8_C( 110), -INT8_C(  95), -INT8_C(  75), -INT8_C(  45), -INT8_C(  89), -INT8_C(  48) },
      {  INT8_C(  83), -INT8_C(  49), -INT8_C(  24), -INT8_C(  68), -INT8_C(  68), -INT8_C(  38), -INT8_C(  35), -INT8_C(   1),
        -INT8_C(  15),  INT8_C(  93), -INT8_C(  42),  INT8_C(  38),  INT8_C(  46),  INT8_C(  45),  INT8_C(  36), -INT8_C( 116) },
      { -INT8_C(  96),      INT8_MIN,  INT8_C(  88),  INT8_C(  16), -INT8_C(  91), -INT8_C( 103), -INT8_C(  70),  INT8_C( 121),
        -INT8_C(  97), -INT8_C(  26),  INT8_C( 116), -INT8_C(  16), -INT8_C(  81), -INT8_C(  70), -INT8_C(  37),  INT8_C(  61) } },
    { { -INT8_C(   2),  INT8_C( 102), -INT8_C(  86), -INT8_C(  99),  INT8_C( 120),  INT8_C(  66), -INT8_C(  10),  INT8_C(  93),
         INT8_C(  51), -INT8_C( 120), -INT8_C(   2), -INT8_C(  24),  INT8_C(  92), -INT8_C(  91), -INT8_C(  72), -INT8_C(  81) },
      {  INT8_C( 117), -INT8_C(  95),  INT8_C( 107),  INT8_C(  49),  INT8_C( 123),  INT8_C(  72),  INT8_C(  49),  INT8_C( 108),
        -INT8_C(  91),  INT8_C(   7), -INT8_C( 109), -INT8_C(  44),  INT8_C(  52), -INT8_C(  73),  INT8_C(  96),  INT8_C(  51) },
      {  INT8_C(  29),  INT8_C(  11), -INT8_C(  48), -INT8_C( 106),  INT8_C(  77), -INT8_C(  58), -INT8_C(  13),      INT8_MIN,
         INT8_C(  79), -INT8_C(  15),  INT8_C( 105), -INT8_C(  85), -INT8_C( 105),  INT8_C(  33),  INT8_C(  90),  INT8_C(  12) },
      { -INT8_C(  67),  INT8_C( 123), -INT8_C(  70), -INT8_C(  25),  INT8_C( 121), -INT8_C( 110),  INT8_C( 115),  INT8_C(  93),
         INT8_C(  72), -INT8_C(  15), -INT8_C(  77),  INT8_C(  76), -INT8_C(  80),  INT8_C(  14), -INT8_C(   8),  INT8_C(  75) } },
    { { -INT8_C(  62), -INT8_C(  59),  INT8_C(  61),  INT8_C(  62),  INT8_C(  13),  INT8_C( 110), -INT8_C(  86), -INT8_C(  78),
         INT8_C( 117),  INT8_C(  61), -INT8_C( 122), -INT8_C(  86), -INT8_C(  12), -INT8_C(  25), -INT8_C(  35),  INT8_C(  18) },
      { -INT8_C(  14), -INT8_C(  83), -INT8_C(  88),  INT8_C(  63),  INT8_C( 116), -INT8_C( 101), -INT8_C(  64), -INT8_C(  61),
        -INT8_C( 116),  INT8_C(  41),  INT8_C( 110),  INT8_C(  35),  INT8_C(  74), -INT8_C(  56),  INT8_C(  47),  INT8_C(  13) },
      { -INT8_C( 115),  INT8_C( 109),  INT8_C(  75), -INT8_C( 102), -INT8_C(  37), -INT8_C(  11),  INT8_C(  76),  INT8_C(  81),
         INT8_C(  51), -INT8_C(  45), -INT8_C(   5),  INT8_C(  39), -INT8_C(  70), -INT8_C(  40),  INT8_C(  57), -INT8_C(  84) },
      {  INT8_C( 120),  INT8_C(  28),  INT8_C(   5),  INT8_C(  88), -INT8_C(  47),  INT8_C(  23), -INT8_C(  86), -INT8_C(   1),
        -INT8_C( 111),  INT8_C( 114), -INT8_C(  84),  INT8_C(  85),  INT8_C(  48),  INT8_C(  39),  INT8_C( 102),  INT8_C(  86) } },
    { { -INT8_C( 123), -INT8_C(  31), -INT8_C(  21), -INT8_C(   7),  INT8_C( 124), -INT8_C(  85), -INT8_C(  68),  INT8_C(   9),
        -INT8_C(  44),  INT8_C(  42),  INT8_C(  44),  INT8_C(  31), -INT8_C(  14),  INT8_C(  92),  INT8_C(  44),      INT8_MAX },
      { -INT8_C(  55),  INT8_C( 119),  INT8_C(  25), -INT8_C(  92),  INT8_C( 108),  INT8_C( 102), -INT8_C(  11), -INT8_C(  97),
         INT8_C(  57), -INT8_C(  16), -INT8_C(  57), -INT8_C(  13), -INT8_C(  56),  INT8_C(   0), -INT8_C(  97),  INT8_C(  78) },
      { -INT8_C(  30), -INT8_C( 118),  INT8_C(  71),  INT8_C(  94),  INT8_C(  54),  INT8_C(   4),  INT8_C( 103),  INT8_C(  10),
         INT8_C(  46), -INT8_C( 108),  INT8_C(  41),  INT8_C(  33), -INT8_C(  16),  INT8_C(  85), -INT8_C(  96), -INT8_C(  71) },
      {  INT8_C(  19), -INT8_C(  69), -INT8_C(   4), -INT8_C(  63), -INT8_C(  76),  INT8_C(  19),  INT8_C(  41), -INT8_C(  45),
        -INT8_C( 106),  INT8_C( 106),  INT8_C(  77), -INT8_C(  52),  INT8_C( 114),  INT8_C(  92), -INT8_C(  52),  INT8_C(  33) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t c = simde_vld1q_s8(test_vec[i].c);
    simde_int8x16_t r = simde_vmlsq_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t c = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vmlsq_s8(a, b, c);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 17716),  INT16_C( 14685),  INT16_C( 21280),  INT16_C( 23000), -INT16_C( 24765),  INT16_C(  3148), -INT16_C(  5216), -INT16_C( 32166) },
      { -INT16_C( 24203), -INT16_C( 21536),  INT16_C( 18597), -INT16_C( 11082), -INT16_C(  8228), -INT16_C( 13067), -INT16_C( 27339),  INT16_C(   389) },
      { -INT16_C(  7601),  INT16_C( 28474),  INT16_C(  4917),  INT16_C( 31176),  INT16_C(  5298),  INT16_C( 21125), -INT16_C(  8193),  INT16_C( 30164) },
      { -INT16_C( 25167),  INT16_C( 10397),  INT16_C(  2551),  INT16_C(  9640), -INT16_C( 14261),  INT16_C(  5891),  INT16_C(  8405),  INT16_C( 30518) } },
    { { -INT16_C( 19072),  INT16_C(  9760), -INT16_C( 10499), -INT16_C(  9734), -INT16_C(  4170), -INT16_C(  5211),  INT16_C( 10884), -INT16_C( 11028) },
      {  INT16_C(  9996),  INT16_C( 16963),  INT16_C(  3130), -INT16_C(  4933),  INT16_C( 16416),  INT16_C(  8255),  INT16_C(  4895), -INT16_C( 24683) },
      { -INT16_C( 19000), -INT16_C( 14907), -INT16_C( 16500),  INT16_C( 17054),  INT16_C( 17326),  INT16_C( 13101),  INT16_C(  6509),  INT16_C( 31239) },
      { -INT16_C( 18400), -INT16_C( 26223), -INT16_C(  7867), -INT16_C( 30576), -INT16_C(  1546), -INT16_C( 19566), -INT16_C(   175),  INT16_C( 30169) } },
    { {  INT16_C( 19008),  INT16_C( 31420),  INT16_C( 30550),  INT16_C( 30567), -INT16_C( 22857), -INT16_C( 10601),  INT16_C( 11449), -INT16_C( 32139) },
      {  INT16_C( 15329),  INT16_C( 27975), -INT16_C(  6406), -INT16_C( 22097), -INT16_C(  9175), -INT16_C( 26660), -INT16_C(  7178),  INT16_C( 13841) },
      { -INT16_C( 13011), -INT16_C( 31567),  INT16_C(  6212), -INT16_C(  1029), -INT16_C( 27970),  INT16_C( 30673),  INT16_C( 18110), -INT16_C( 24583) },
      { -INT16_C( 26957),  INT16_C( 20645), -INT16_C( 21266), -INT16_C( 31790), -INT16_C(  8631), -INT16_C( 26629), -INT16_C( 18395),  INT16_C( 23788) } },
    { {  INT16_C( 16769),  INT16_C( 31757), -INT16_C( 17369),  INT16_C( 20517),  INT16_C(   409), -INT16_C( 28697), -INT16_C(  1820),  INT16_C(  4549) },
      {  INT16_C( 30405),  INT16_C(  2453), -INT16_C( 28530),  INT16_C( 19460), -INT16_C( 10974), -INT16_C(  7996), -INT16_C( 17124), -INT16_C( 25216) },
      { -INT16_C( 29186),  INT16_C(  9497),  INT16_C( 15945), -INT16_C(  7562),  INT16_C( 23871),  INT16_C(  9073),  INT16_C( 14166),  INT16_C(  6965) },
      { -INT16_C(  5877),  INT16_C(   896),  INT16_C(  8105), -INT16_C( 16819),  INT16_C( 13371), -INT16_C( 29341),  INT16_C( 28028), -INT16_C(  2491) } },
    { { -INT16_C( 13651),  INT16_C( 15397),  INT16_C( 10587),  INT16_C( 32136),  INT16_C( 19711),  INT16_C(  7006), -INT16_C(  8694),  INT16_C(  2232) },
      { -INT16_C( 11669), -INT16_C( 19410), -INT16_C( 23536),  INT16_C( 20631),  INT16_C(  2049),  INT16_C( 22387), -INT16_C( 22465), -INT16_C(  4749) },
      { -INT16_C( 26509), -INT16_C( 12759), -INT16_C( 20031), -INT16_C( 16309), -INT16_C( 22018),  INT16_C(  2267), -INT16_C( 27513), -INT16_C(  3568) },
      { -INT16_C( 17252),  INT16_C( 23751),  INT16_C( 26955), -INT16_C( 24245), -INT16_C( 19711), -INT16_C( 19459), -INT16_C( 18223),  INT16_C( 31624) } },
    { {  INT16_C( 15974),  INT16_C( 30375),  INT16_C( 16098), -INT16_C(  6970),  INT16_C( 14918), -INT16_C( 31173), -INT16_C( 20766),  INT16_C( 21875) },
      { -INT16_C( 25530),  INT16_C(  2083),  INT16_C( 28493),  INT16_C( 19400), -INT16_C( 23528), -INT16_C( 24493),  INT16_C( 25656), -INT16_C( 24942) },
      {  INT16_C( 14754), -INT16_C( 31468), -INT16_C(  9353), -INT16_C( 16791), -INT16_C( 23531), -INT16_C(  2236), -INT16_C( 18605), -INT16_C( 26291) },
      { -INT16_C( 15334), -INT16_C( 23317), -INT16_C( 23785),  INT16_C( 24510),  INT16_C( 25678), -INT16_C(  9425),  INT16_C( 10426),  INT16_C( 24969) } },
    { {  INT16_C( 28755), -INT16_C( 24415),  INT16_C( 27359), -INT16_C(  1812),  INT16_C( 16142),  INT16_C( 18072),  INT16_C( 10915),  INT16_C( 18148) },
      { -INT16_C(  1948), -INT16_C(  9269),  INT16_C( 13523), -INT16_C(  5991), -INT16_C(  8744),  INT16_C( 11232),  INT16_C( 11668), -INT16_C(  6203) },
      {  INT16_C( 26269),  INT16_C( 32136),  INT16_C( 29904), -INT16_C(  8587),  INT16_C(  3507),  INT16_C( 22308),  INT16_C(  2103), -INT16_C( 25699) },
      {  INT16_C( 17151), -INT16_C( 16951), -INT16_C(  7313), -INT16_C(   769),  INT16_C( 10502), -INT16_C(  1256), -INT16_C( 16425), -INT16_C(  9197) } },
    { {  INT16_C( 26625), -INT16_C( 11145),  INT16_C(  4252),  INT16_C( 29885), -INT16_C( 25106), -INT16_C( 32096),  INT16_C( 26058),  INT16_C( 26474) },
      { -INT16_C(  3381), -INT16_C( 25372),  INT16_C( 22886),  INT16_C(  6522), -INT16_C( 24730), -INT16_C( 24976),  INT16_C(  3495), -INT16_C( 22471) },
      { -INT16_C( 20363),  INT16_C(  4477),  INT16_C( 15041), -INT16_C( 20602),  INT16_C(  9943), -INT16_C( 24271), -INT16_C( 25717),  INT16_C( 22024) },
      { -INT16_C(  7878),  INT16_C(  5411), -INT16_C( 29002), -INT16_C( 18207), -INT16_C( 25788), -INT16_C( 16592), -INT16_C(  8419), -INT16_C(    94) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int16x8_t r = simde_vmlsq_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t c = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vmlsq_s16(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t c[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   202183283), -INT32_C(  1391628986), -INT32_C(  1286898420),  INT32_C(     6063243) },
      { -INT32_C(   166536907), -INT32_C(   358246381),  INT32_C(  1233901246), -INT32_C(     6319246) },
      { -INT32_C(   940338560),  INT32_C(   192151807),  INT32_C(   146718589),  INT32_C(  2013862467) },
      { -INT32_C(   900261619),  INT32_C(   947843673),  INT32_C(   600301638),  INT32_C(  1167940021) } },
    { {  INT32_C(   107879411),  INT32_C(  1911559091),  INT32_C(  1555725290), -INT32_C(  1889838833) },
      { -INT32_C(   363442453), -INT32_C(   856307122), -INT32_C(   841698167), -INT32_C(  1035608626) },
      { -INT32_C(  1412909832), -INT32_C(  1323517497),  INT32_C(  1124980276),  INT32_C(   466839856) },
      { -INT32_C(  1296274357),  INT32_C(  1898279697), -INT32_C(  1197061610), -INT32_C(   276937617) } },
    { {  INT32_C(   101067191),  INT32_C(  2110979060),  INT32_C(  2118821551),  INT32_C(  2084606084) },
      {  INT32_C(   187172932), -INT32_C(   155368255),  INT32_C(  1262078491), -INT32_C(   345633741) },
      {  INT32_C(   720464950),  INT32_C(   396870504), -INT32_C(   308940183), -INT32_C(   966077054) },
      { -INT32_C(   669795489), -INT32_C(   458683764),  INT32_C(  1641167772), -INT32_C(  1960185954) } },
    { { -INT32_C(  1613655330), -INT32_C(   241856810), -INT32_C(  1942171815),  INT32_C(   293053403) },
      {  INT32_C(  2000381967), -INT32_C(  1785732309),  INT32_C(  1468146901), -INT32_C(   669127430) },
      {  INT32_C(  1433923198), -INT32_C(   700052099), -INT32_C(  1218280484),  INT32_C(   902421030) },
      {  INT32_C(  1541237116), -INT32_C(  1945603113),  INT32_C(  1661086029), -INT32_C(  1360031041) } },
    { {  INT32_C(  1856832578), -INT32_C(  1140638489),  INT32_C(  1511228768), -INT32_C(   265146254) },
      { -INT32_C(  1673156065), -INT32_C(  1821209417),  INT32_C(   894096399), -INT32_C(   244706386) },
      { -INT32_C(    10545384), -INT32_C(  1262722477),  INT32_C(  1494142951),  INT32_C(   524960000) },
      { -INT32_C(  2091169702),  INT32_C(   295538578), -INT32_C(   230421801),  INT32_C(  1055326834) } },
    { { -INT32_C(  1564766229),  INT32_C(   708128027), -INT32_C(  1335918847), -INT32_C(  1415460205) },
      {  INT32_C(   900333793),  INT32_C(  1240032866),  INT32_C(   916715318),  INT32_C(   592833848) },
      { -INT32_C(  1731915652),  INT32_C(  1052965437),  INT32_C(   233710202), -INT32_C(   843542548) },
      { -INT32_C(  1087368465),  INT32_C(  1297617857),  INT32_C(  1295156037), -INT32_C(  1062677773) } },
    { { -INT32_C(   251501937), -INT32_C(    12850231),  INT32_C(   456515299),  INT32_C(  1195346635) },
      { -INT32_C(   673250150),  INT32_C(  2031461119), -INT32_C(  1333394236),  INT32_C(   595410579) },
      {  INT32_C(  1762951328),  INT32_C(  1315458923), -INT32_C(   127230675), -INT32_C(  1052727001) },
      { -INT32_C(    45448625), -INT32_C(   867427788),  INT32_C(   160617583), -INT32_C(  1189349530) } },
    { { -INT32_C(  1399316563), -INT32_C(  2061127999),  INT32_C(  1161145266), -INT32_C(  1972849687) },
      { -INT32_C(  1628209869), -INT32_C(    85107508),  INT32_C(   569530361), -INT32_C(  1377684992) },
      {  INT32_C(   324696914), -INT32_C(   610697431),  INT32_C(   337694251), -INT32_C(  1264678527) },
      { -INT32_C(   125533097), -INT32_C(  1708351979),  INT32_C(   462849759),  INT32_C(    44794345) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int32x4_t r = simde_vmlsq_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t c = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vmlsq_s32(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t c[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(  6), UINT8_C(146), UINT8_C( 83), UINT8_C(210), UINT8_C(238), UINT8_C( 64), UINT8_C(204), UINT8_C(231),
        UINT8_C(151), UINT8_C(191), UINT8_C(  8), UINT8_C(151), UINT8_C(241), UINT8_C(235), UINT8_C( 68), UINT8_C( 67) },
      { UINT8_C(102), UINT8_C(158), UINT8_C( 87), UINT8_C(143), UINT8_C( 30), UINT8_C(240), UINT8_C(106), UINT8_C( 73),
        UINT8_C(190), UINT8_C(138), UINT8_C( 93), UINT8_C( 64), UINT8_C( 19), UINT8_C(252), UINT8_C(244), UINT8_C( 25) },
      { UINT8_C(142), UINT8_C( 71), UINT8_C(236), UINT8_C(124), UINT8_C(135), UINT8_C(184), UINT8_C( 99), UINT8_C( 30),
        UINT8_C(119), UINT8_C(108), UINT8_C(181), UINT8_C(105), UINT8_C( 87), UINT8_C(250), UINT8_C(172), UINT8_C(189) },
      { UINT8_C(114), UINT8_C(192), UINT8_C( 31), UINT8_C(142), UINT8_C( 28), UINT8_C(192), UINT8_C(206), UINT8_C( 89),
        UINT8_C( 69), UINT8_C(135), UINT8_C( 71), UINT8_C( 87), UINT8_C(124), UINT8_C(211), UINT8_C( 84), UINT8_C(206) } },
    { { UINT8_C(152), UINT8_C(  3), UINT8_C( 76), UINT8_C(182), UINT8_C(243), UINT8_C(182),    UINT8_MAX, UINT8_C(178),
        UINT8_C( 64), UINT8_C( 93), UINT8_C(242), UINT8_C( 84), UINT8_C( 89), UINT8_C(230), UINT8_C(109), UINT8_C(231) },
      { UINT8_C( 46), UINT8_C( 89), UINT8_C( 99), UINT8_C(181), UINT8_C( 18), UINT8_C(198), UINT8_C(212), UINT8_C(137),
        UINT8_C( 50), UINT8_C(137), UINT8_C(242), UINT8_C(137), UINT8_C(131), UINT8_C(159), UINT8_C( 70), UINT8_C( 28) },
      { UINT8_C(162), UINT8_C(146), UINT8_C(210), UINT8_C(150), UINT8_C( 72), UINT8_C(210), UINT8_C( 72), UINT8_C(137),
        UINT8_C( 47), UINT8_C( 58), UINT8_C(221), UINT8_C(136), UINT8_C( 32), UINT8_C( 74), UINT8_C(111), UINT8_C( 78) },
      { UINT8_C(124), UINT8_C( 65), UINT8_C( 22), UINT8_C(168), UINT8_C(227), UINT8_C( 74), UINT8_C( 95), UINT8_C( 97),
        UINT8_C( 18), UINT8_C( 83), UINT8_C(  8), UINT8_C(140), UINT8_C(249), UINT8_C(240), UINT8_C( 19), UINT8_C( 95) } },
    { { UINT8_C(164), UINT8_C(210), UINT8_C(  4), UINT8_C(182), UINT8_C(152), UINT8_C(216), UINT8_C( 63), UINT8_C(203),
        UINT8_C( 97), UINT8_C( 50), UINT8_C( 84), UINT8_C(229), UINT8_C(209), UINT8_C(155), UINT8_C(  1), UINT8_C(115) },
      { UINT8_C( 45), UINT8_C(211), UINT8_C(  9), UINT8_C(118), UINT8_C(165), UINT8_C( 81),    UINT8_MAX, UINT8_C(212),
        UINT8_C(139), UINT8_C(220), UINT8_C( 92), UINT8_C(172), UINT8_C( 38), UINT8_C(203), UINT8_C(250), UINT8_C(202) },
      { UINT8_C(157), UINT8_C(254), UINT8_C(128), UINT8_C( 54), UINT8_C(214), UINT8_C(192), UINT8_C(  1), UINT8_C( 56),
        UINT8_C(242), UINT8_C( 85), UINT8_C( 29), UINT8_C(195), UINT8_C(240), UINT8_C( 30), UINT8_C( 54), UINT8_C( 30) },
      { UINT8_C( 11), UINT8_C(120), UINT8_C(132), UINT8_C(210), UINT8_C(170), UINT8_C( 24), UINT8_C( 64), UINT8_C(107),
        UINT8_C(251), UINT8_C( 38), UINT8_C(232), UINT8_C(225), UINT8_C( 49), UINT8_C(209), UINT8_C( 69), UINT8_C(199) } },
    { { UINT8_C(241), UINT8_C( 64), UINT8_C(148), UINT8_C(151), UINT8_C(145), UINT8_C(147), UINT8_C(107), UINT8_C( 29),
        UINT8_C(111), UINT8_C(200), UINT8_C(201), UINT8_C(149), UINT8_C(147), UINT8_C(195), UINT8_C( 96), UINT8_C( 49) },
      { UINT8_C(194), UINT8_C(224), UINT8_C(103), UINT8_C(152), UINT8_C(160), UINT8_C(104), UINT8_C(208), UINT8_C(146),
        UINT8_C(189), UINT8_C(237), UINT8_C( 85), UINT8_C(174), UINT8_C( 11), UINT8_C(140), UINT8_C(204), UINT8_C(253) },
      { UINT8_C(204), UINT8_C( 96), UINT8_C(148), UINT8_C( 93), UINT8_C(243),    UINT8_MAX, UINT8_C(122), UINT8_C( 98),
        UINT8_C(199), UINT8_C( 67), UINT8_C(247), UINT8_C( 91), UINT8_C(  7), UINT8_C( 87), UINT8_C(140), UINT8_C(201) },
      { UINT8_C( 89), UINT8_C( 64), UINT8_C(  8), UINT8_C( 95), UINT8_C(177), UINT8_C(251), UINT8_C( 75), UINT8_C( 57),
        UINT8_C(132), UINT8_C(193), UINT8_C(198), UINT8_C(187), UINT8_C( 70), UINT8_C( 47), UINT8_C(208), UINT8_C(140) } },
    { { UINT8_C( 56), UINT8_C(243), UINT8_C( 97), UINT8_C(216), UINT8_C( 91), UINT8_C( 50), UINT8_C(107), UINT8_C( 24),
        UINT8_C( 31), UINT8_C(192), UINT8_C(198), UINT8_C( 43), UINT8_C( 76), UINT8_C(146), UINT8_C( 40), UINT8_C( 24) },
      { UINT8_C(242), UINT8_C(188), UINT8_C(118), UINT8_C(229), UINT8_C(187), UINT8_C(240), UINT8_C( 71), UINT8_C(131),
        UINT8_C( 52), UINT8_C( 63), UINT8_C(222), UINT8_C( 59), UINT8_C(150), UINT8_C(106), UINT8_C(  4), UINT8_C(206) },
      { UINT8_C( 93), UINT8_C(101), UINT8_C(167), UINT8_C(184), UINT8_C(151), UINT8_C( 18), UINT8_C(208), UINT8_C(183),
        UINT8_C(210), UINT8_C(151), UINT8_C(226), UINT8_C( 31), UINT8_C( 41), UINT8_C( 10), UINT8_C( 55), UINT8_C( 28) },
      { UINT8_C( 78), UINT8_C(199), UINT8_C(103), UINT8_C( 64), UINT8_C( 14), UINT8_C( 82), UINT8_C(187), UINT8_C(115),
        UINT8_C(119), UINT8_C(151), UINT8_C(202), UINT8_C(  6), UINT8_C( 70), UINT8_C(110), UINT8_C( 76), UINT8_C(144) } },
    { { UINT8_C(198), UINT8_C(173), UINT8_C(  1), UINT8_C(129), UINT8_C(158), UINT8_C( 73), UINT8_C(  4), UINT8_C(210),
        UINT8_C(136), UINT8_C(226), UINT8_C( 13), UINT8_C( 30), UINT8_C( 76), UINT8_C( 17), UINT8_C(237), UINT8_C(169) },
      { UINT8_C(118), UINT8_C(148), UINT8_C( 97), UINT8_C( 14), UINT8_C(166), UINT8_C( 50), UINT8_C(197), UINT8_C(120),
        UINT8_C(201), UINT8_C(167), UINT8_C(151), UINT8_C(242), UINT8_C(177), UINT8_C(207), UINT8_C( 14), UINT8_C(119) },
      { UINT8_C(124), UINT8_C( 16), UINT8_C(248), UINT8_C( 26), UINT8_C( 89), UINT8_C(253), UINT8_C(236), UINT8_C(225),
        UINT8_C(223), UINT8_C(249),    UINT8_MAX, UINT8_C( 44), UINT8_C( 10), UINT8_C(236), UINT8_C(213), UINT8_C(129) },
      { UINT8_C(158), UINT8_C(109), UINT8_C(  9), UINT8_C( 21), UINT8_C(232), UINT8_C(223), UINT8_C(104), UINT8_C( 90),
        UINT8_C(113), UINT8_C(115), UINT8_C(164), UINT8_C(134), UINT8_C( 98), UINT8_C( 61), UINT8_C( 71), UINT8_C(178) } },
    { { UINT8_C(128), UINT8_C( 55), UINT8_C(143), UINT8_C( 38), UINT8_C(105), UINT8_C( 84), UINT8_C(159), UINT8_C( 50),
        UINT8_C(251), UINT8_C( 54), UINT8_C( 36), UINT8_C(172), UINT8_C(  5), UINT8_C( 51), UINT8_C( 35), UINT8_C(130) },
      { UINT8_C( 67), UINT8_C( 27), UINT8_C(156), UINT8_C(156), UINT8_C( 24), UINT8_C(137), UINT8_C(125), UINT8_C(248),
        UINT8_C(130), UINT8_C(124), UINT8_C( 36), UINT8_C(141), UINT8_C(105), UINT8_C(249), UINT8_C( 14), UINT8_C(233) },
      { UINT8_C( 48), UINT8_C(157), UINT8_C( 16), UINT8_C(153), UINT8_C(241), UINT8_C(175), UINT8_C(203), UINT8_C(236),
        UINT8_C(229), UINT8_C(240), UINT8_C(152), UINT8_C(235), UINT8_C( 35), UINT8_C(187), UINT8_C(109), UINT8_C(102) },
      { UINT8_C(240), UINT8_C(168), UINT8_C(207), UINT8_C(234), UINT8_C(209), UINT8_C(173), UINT8_C(128), UINT8_C(146),
        UINT8_C(177), UINT8_C(246), UINT8_C(196), UINT8_C( 61), UINT8_C(170), UINT8_C( 80), UINT8_C( 45), UINT8_C(172) } },
    { { UINT8_C(214), UINT8_C(  9), UINT8_C(  2), UINT8_C(239), UINT8_C(146), UINT8_C(127), UINT8_C(231), UINT8_C( 21),
        UINT8_C(251), UINT8_C( 11), UINT8_C(162), UINT8_C(100), UINT8_C(  4), UINT8_C(176), UINT8_C( 78), UINT8_C( 53) },
      { UINT8_C( 77), UINT8_C( 94), UINT8_C(206), UINT8_C( 62), UINT8_C( 13), UINT8_C(154), UINT8_C( 42), UINT8_C(242),
        UINT8_C(138), UINT8_C(194), UINT8_C(221), UINT8_C(173), UINT8_C(125), UINT8_C( 74), UINT8_C( 19), UINT8_C( 83) },
      { UINT8_C( 84), UINT8_C( 21), UINT8_C( 66), UINT8_C(230), UINT8_C(148), UINT8_C( 41), UINT8_C(251), UINT8_C(143),
        UINT8_C( 52), UINT8_C(157), UINT8_C(244), UINT8_C( 57), UINT8_C( 77), UINT8_C( 66), UINT8_C(110), UINT8_C(154) },
      { UINT8_C(146), UINT8_C( 83), UINT8_C(230), UINT8_C( 59), UINT8_C( 14), UINT8_C(213), UINT8_C(185), UINT8_C(231),
        UINT8_C(243), UINT8_C( 17), UINT8_C(254), UINT8_C(223), UINT8_C(107), UINT8_C(156), UINT8_C( 36), UINT8_C( 71) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t c = simde_vld1q_u8(test_vec[i].c);
    simde_uint8x16_t r = simde_vmlsq_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t c = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vmlsq_u8(a, b, c);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t c[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(15520), UINT16_C(44504), UINT16_C(  726), UINT16_C(24735), UINT16_C(32196), UINT16_C(16653), UINT16_C( 8391), UINT16_C( 7061) },
      { UINT16_C(55093), UINT16_C(51458), UINT16_C(64769), UINT16_C(13657), UINT16_C(19867), UINT16_C(59502), UINT16_C(56463), UINT16_C(12163) },
      { UINT16_C(23321), UINT16_C(61404), UINT16_C(31582), UINT16_C( 8784), UINT16_C(24056), UINT16_C(49252), UINT16_C(63870), UINT16_C(46043) },
      { UINT16_C(24947), UINT16_C( 4640), UINT16_C(41336), UINT16_C(58063), UINT16_C(  156), UINT16_C(62997), UINT16_C(31589), UINT16_C(56708) } },
    { { UINT16_C(56784), UINT16_C(53629), UINT16_C(55003), UINT16_C(30215), UINT16_C(29987), UINT16_C(45662), UINT16_C(57682), UINT16_C(27617) },
      { UINT16_C(48445), UINT16_C(39770), UINT16_C(43576), UINT16_C(12733), UINT16_C( 8456), UINT16_C(34545), UINT16_C(52250), UINT16_C(60217) },
      { UINT16_C(46762), UINT16_C(34236), UINT16_C(50060), UINT16_C(45051), UINT16_C(22841), UINT16_C(35681), UINT16_C(16955), UINT16_C(30966) },
      { UINT16_C(54606), UINT16_C(63845), UINT16_C( 6203), UINT16_C(32440), UINT16_C(21083), UINT16_C(46605), UINT16_C( 9044), UINT16_C(43803) } },
    { { UINT16_C(20735), UINT16_C(14355), UINT16_C(53499), UINT16_C(  873), UINT16_C(23282), UINT16_C( 3209), UINT16_C(49702), UINT16_C(53495) },
      { UINT16_C(46201), UINT16_C( 1365), UINT16_C(20599), UINT16_C(45237), UINT16_C( 5802), UINT16_C(58683), UINT16_C(12633), UINT16_C(22621) },
      { UINT16_C(28802), UINT16_C(32144), UINT16_C(63808), UINT16_C(12928), UINT16_C( 2387), UINT16_C(31295), UINT16_C(14027), UINT16_C(17482) },
      { UINT16_C(48013), UINT16_C(46915), UINT16_C(62523), UINT16_C(20201), UINT16_C( 2004), UINT16_C(34052), UINT16_C(55955), UINT16_C(37397) } },
    { { UINT16_C(41194), UINT16_C(25162), UINT16_C(65520), UINT16_C(39442), UINT16_C(19989), UINT16_C(28287), UINT16_C(56447), UINT16_C(  455) },
      { UINT16_C(22348), UINT16_C(36222), UINT16_C(65105), UINT16_C(42175), UINT16_C(65031), UINT16_C(54046), UINT16_C(26933), UINT16_C( 7959) },
      { UINT16_C(24841), UINT16_C(63873), UINT16_C(37984), UINT16_C(30356), UINT16_C( 5090), UINT16_C(25060), UINT16_C(44016), UINT16_C(15459) },
      { UINT16_C(49982), UINT16_C(34764), UINT16_C(52624), UINT16_C(20902), UINT16_C(34535), UINT16_C( 2503), UINT16_C(54223), UINT16_C(38882) } },
    { { UINT16_C(57603), UINT16_C(21705), UINT16_C(35296), UINT16_C(59384), UINT16_C( 6023), UINT16_C(48314), UINT16_C(53888), UINT16_C(35292) },
      { UINT16_C(23859), UINT16_C(38018), UINT16_C( 5873), UINT16_C(54026), UINT16_C(60970), UINT16_C( 6709), UINT16_C(39066), UINT16_C(40278) },
      { UINT16_C( 8313), UINT16_C(23025), UINT16_C(59817), UINT16_C(12353), UINT16_C(64256), UINT16_C(33005), UINT16_C(51661), UINT16_C(  265) },
      { UINT16_C(29672), UINT16_C(21607), UINT16_C( 3015), UINT16_C(29294), UINT16_C(59783), UINT16_C(63913), UINT16_C(46382), UINT16_C(43990) } },
    { { UINT16_C(35878), UINT16_C( 6293), UINT16_C(40866), UINT16_C(52459), UINT16_C( 8333), UINT16_C(10214), UINT16_C(15800), UINT16_C(12996) },
      { UINT16_C(46429), UINT16_C( 1675), UINT16_C(52383), UINT16_C(40758), UINT16_C( 9160), UINT16_C(38176), UINT16_C(10732), UINT16_C( 5014) },
      { UINT16_C(11189), UINT16_C(22571), UINT16_C( 5834), UINT16_C(22564), UINT16_C( 2871), UINT16_C(61311), UINT16_C(17480), UINT16_C(42273) },
      { UINT16_C(45669), UINT16_C(14140), UINT16_C(32812), UINT16_C(55635), UINT16_C(55445), UINT16_C(19718), UINT16_C(50008), UINT16_C(65134) } },
    { { UINT16_C(44537), UINT16_C(39083), UINT16_C(57721), UINT16_C(16696), UINT16_C(22533), UINT16_C(61911), UINT16_C(28033), UINT16_C(14084) },
      { UINT16_C(12185), UINT16_C(25487), UINT16_C(45894), UINT16_C(32187), UINT16_C(15294), UINT16_C( 1644), UINT16_C(36479), UINT16_C(30891) },
      { UINT16_C(22075), UINT16_C(46097), UINT16_C(18744), UINT16_C(15862), UINT16_C(52641), UINT16_C( 8750), UINT16_C(13114), UINT16_C(54105) },
      { UINT16_C(20406), UINT16_C(28716), UINT16_C(46121), UINT16_C(57478), UINT16_C(40839), UINT16_C(29295), UINT16_C(55227), UINT16_C(21137) } },
    { { UINT16_C(59490), UINT16_C(43063), UINT16_C(62108), UINT16_C(23077), UINT16_C(37421), UINT16_C(44129), UINT16_C( 3104), UINT16_C(23333) },
      { UINT16_C(13923), UINT16_C(39695), UINT16_C( 1407), UINT16_C( 8408), UINT16_C( 1746), UINT16_C( 3394), UINT16_C(39993), UINT16_C(40160) },
      { UINT16_C( 6020), UINT16_C( 8260), UINT16_C(27146), UINT16_C(14203), UINT16_C(56572), UINT16_C( 7396), UINT16_C( 2536), UINT16_C(19319) },
      { UINT16_C(63574), UINT16_C(38971), UINT16_C( 9638), UINT16_C(10845), UINT16_C(25461), UINT16_C(42393), UINT16_C(30584), UINT16_C(52997) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t c = simde_vld1q_u16(test_vec[i].c);
    simde_uint16x8_t r = simde_vmlsq_u16(a, b, c);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t c = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vmlsq_u16(a, b, c);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3202778687), UINT32_C(1591656076), UINT32_C(4268433605), UINT32_C(1100631228) },
      { UINT32_C(1835130723), UINT32_C(1168497737), UINT32_C(2707524024), UINT32_C(3521960082) },
      { UINT32_C(3935294302), UINT32_C(1447652753), UINT32_C(1247130765), UINT32_C(1686892288) },
      { UINT32_C(2743789285), UINT32_C(4132496435), UINT32_C(2630149741), UINT32_C(2216951484) } },
    { { UINT32_C( 399633614), UINT32_C(2170320585), UINT32_C(2434973183), UINT32_C(4100067221) },
      { UINT32_C(1943990754), UINT32_C(3972671326), UINT32_C(3694534620), UINT32_C(3712008462) },
      { UINT32_C(1995707053), UINT32_C(2297975176), UINT32_C(2753108494), UINT32_C( 194542633) },
      { UINT32_C(1706988308), UINT32_C(2893205209), UINT32_C(4201949175), UINT32_C(3979369559) } },
    { { UINT32_C(3430905453), UINT32_C(2058897822), UINT32_C(1985408616), UINT32_C(1548982191) },
      { UINT32_C( 835930281), UINT32_C(2813971353), UINT32_C( 256627685), UINT32_C(3155878735) },
      { UINT32_C(4169701722), UINT32_C(1249001698), UINT32_C(3720464430), UINT32_C( 138024031) },
      { UINT32_C(2952980995), UINT32_C( 296373388), UINT32_C( 143061826), UINT32_C(2091979102) } },
    { { UINT32_C(4114222428), UINT32_C(3181245400), UINT32_C( 365750470), UINT32_C( 651356108) },
      { UINT32_C(1662933632), UINT32_C(3383595163), UINT32_C(3097980504), UINT32_C(3753959811) },
      { UINT32_C(3335912174), UINT32_C(3028513518), UINT32_C( 650793050), UINT32_C(3075251255) },
      { UINT32_C(3726699100), UINT32_C(4169891262), UINT32_C(3070533078), UINT32_C(4078084263) } },
    { { UINT32_C(2434427638), UINT32_C(1398524154), UINT32_C(3104506422), UINT32_C(3516517347) },
      { UINT32_C(3029823174), UINT32_C( 979901152), UINT32_C(2707501674), UINT32_C(3310988750) },
      { UINT32_C( 307655448), UINT32_C(1919267131), UINT32_C(2519429299), UINT32_C(  40354876) },
      { UINT32_C(2040600166), UINT32_C(2288564058), UINT32_C(3359138328), UINT32_C(1570854811) } },
    { { UINT32_C( 313982514), UINT32_C(2202869273), UINT32_C( 522563153), UINT32_C(1944354395) },
      { UINT32_C( 763771889), UINT32_C(2694835180), UINT32_C(2553727580), UINT32_C(3248135823) },
      { UINT32_C(3050590364), UINT32_C(3208192366), UINT32_C( 719281871), UINT32_C(3449734108) },
      { UINT32_C(1503340374), UINT32_C(1168134833), UINT32_C(2389067245), UINT32_C(3975892599) } },
    { { UINT32_C(3959039230), UINT32_C(1804310799), UINT32_C(4077109604), UINT32_C(4239695199) },
      { UINT32_C(1555138797), UINT32_C(2015095465), UINT32_C( 614726216), UINT32_C(3169993150) },
      { UINT32_C(1957162085), UINT32_C(3940561542), UINT32_C(1407050740), UINT32_C(1850708353) },
      { UINT32_C(4179207037), UINT32_C(1262076569), UINT32_C( 933452996), UINT32_C(2713902753) } },
    { { UINT32_C(3284795674), UINT32_C( 876406507), UINT32_C(2656624608), UINT32_C(2237352480) },
      { UINT32_C(3187212855), UINT32_C( 698865973), UINT32_C(1048347837), UINT32_C( 799853589) },
      { UINT32_C(3102963661), UINT32_C(1038888797), UINT32_C( 786187534), UINT32_C(3333633935) },
      { UINT32_C(1093052943), UINT32_C(1669743530), UINT32_C(2606148746), UINT32_C(3545089893) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vmlsq_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vmlsq_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
