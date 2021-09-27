#define SIMDE_TEST_ARM_NEON_INSN ld1q_x4
#include "test/test.h"
#include "test-neon.h"
#include "../../../simde/arm/neon/ld1q_x4.h"
#include "../../../simde/arm/neon/ld1_lane.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld1q_f32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 buf[16];
    simde_float32 expected[4][4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -756.25), SIMDE_FLOAT32_C(  -472.56), SIMDE_FLOAT32_C(  -485.21), SIMDE_FLOAT32_C(  -951.63),
        SIMDE_FLOAT32_C(  -740.33), SIMDE_FLOAT32_C(   -53.06), SIMDE_FLOAT32_C(   631.32), SIMDE_FLOAT32_C(  -592.71),
        SIMDE_FLOAT32_C(  -259.33), SIMDE_FLOAT32_C(   413.25), SIMDE_FLOAT32_C(   857.59), SIMDE_FLOAT32_C(   233.16),
        SIMDE_FLOAT32_C(  -253.96), SIMDE_FLOAT32_C(  -530.78), SIMDE_FLOAT32_C(  -279.00), SIMDE_FLOAT32_C(   879.54) },
        { { SIMDE_FLOAT32_C(  -756.25), SIMDE_FLOAT32_C(  -472.56), SIMDE_FLOAT32_C(  -485.21), SIMDE_FLOAT32_C(  -951.63) },
          { SIMDE_FLOAT32_C(  -740.33), SIMDE_FLOAT32_C(   -53.06), SIMDE_FLOAT32_C(   631.32), SIMDE_FLOAT32_C(  -592.71) },
          { SIMDE_FLOAT32_C(  -259.33), SIMDE_FLOAT32_C(   413.25), SIMDE_FLOAT32_C(   857.59), SIMDE_FLOAT32_C(   233.16) },
          { SIMDE_FLOAT32_C(  -253.96), SIMDE_FLOAT32_C(  -530.78), SIMDE_FLOAT32_C(  -279.00), SIMDE_FLOAT32_C(   879.54) } },
    },
    { { SIMDE_FLOAT32_C(   234.46), SIMDE_FLOAT32_C(  -638.91), SIMDE_FLOAT32_C(  -980.23), SIMDE_FLOAT32_C(  -592.36),
        SIMDE_FLOAT32_C(  -675.80), SIMDE_FLOAT32_C(  -681.20), SIMDE_FLOAT32_C(   412.15), SIMDE_FLOAT32_C(   974.72),
        SIMDE_FLOAT32_C(  -672.11), SIMDE_FLOAT32_C(  -298.37), SIMDE_FLOAT32_C(   118.31), SIMDE_FLOAT32_C(  -312.90),
        SIMDE_FLOAT32_C(   964.41), SIMDE_FLOAT32_C(  -132.57), SIMDE_FLOAT32_C(   913.72), SIMDE_FLOAT32_C(  -791.84) },
        { { SIMDE_FLOAT32_C(   234.46), SIMDE_FLOAT32_C(  -638.91), SIMDE_FLOAT32_C(  -980.23), SIMDE_FLOAT32_C(  -592.36) },
          { SIMDE_FLOAT32_C(  -675.80), SIMDE_FLOAT32_C(  -681.20), SIMDE_FLOAT32_C(   412.15), SIMDE_FLOAT32_C(   974.72) },
          { SIMDE_FLOAT32_C(  -672.11), SIMDE_FLOAT32_C(  -298.37), SIMDE_FLOAT32_C(   118.31), SIMDE_FLOAT32_C(  -312.90) },
          { SIMDE_FLOAT32_C(   964.41), SIMDE_FLOAT32_C(  -132.57), SIMDE_FLOAT32_C(   913.72), SIMDE_FLOAT32_C(  -791.84) } },
    },
    { { SIMDE_FLOAT32_C(   394.88), SIMDE_FLOAT32_C(  -571.48), SIMDE_FLOAT32_C(  -743.47), SIMDE_FLOAT32_C(   654.55),
        SIMDE_FLOAT32_C(   375.46), SIMDE_FLOAT32_C(   887.86), SIMDE_FLOAT32_C(  -938.16), SIMDE_FLOAT32_C(  -883.87),
        SIMDE_FLOAT32_C(   301.10), SIMDE_FLOAT32_C(   919.43), SIMDE_FLOAT32_C(   349.29), SIMDE_FLOAT32_C(  -952.86),
        SIMDE_FLOAT32_C(  -611.35), SIMDE_FLOAT32_C(  -929.71), SIMDE_FLOAT32_C(   926.68), SIMDE_FLOAT32_C(   623.11) },
        { { SIMDE_FLOAT32_C(   394.88), SIMDE_FLOAT32_C(  -571.48), SIMDE_FLOAT32_C(  -743.47), SIMDE_FLOAT32_C(   654.55) },
          { SIMDE_FLOAT32_C(   375.46), SIMDE_FLOAT32_C(   887.86), SIMDE_FLOAT32_C(  -938.16), SIMDE_FLOAT32_C(  -883.87) },
          { SIMDE_FLOAT32_C(   301.10), SIMDE_FLOAT32_C(   919.43), SIMDE_FLOAT32_C(   349.29), SIMDE_FLOAT32_C(  -952.86) },
          { SIMDE_FLOAT32_C(  -611.35), SIMDE_FLOAT32_C(  -929.71), SIMDE_FLOAT32_C(   926.68), SIMDE_FLOAT32_C(   623.11) } },
    },
    { { SIMDE_FLOAT32_C(  -568.62), SIMDE_FLOAT32_C(   946.46), SIMDE_FLOAT32_C(  -969.25), SIMDE_FLOAT32_C(  -244.42),
        SIMDE_FLOAT32_C(  -734.74), SIMDE_FLOAT32_C(   442.91), SIMDE_FLOAT32_C(  -269.70), SIMDE_FLOAT32_C(  -406.85),
        SIMDE_FLOAT32_C(  -855.46), SIMDE_FLOAT32_C(   848.61), SIMDE_FLOAT32_C(   280.25), SIMDE_FLOAT32_C(  -891.06),
        SIMDE_FLOAT32_C(  -283.96), SIMDE_FLOAT32_C(   193.98), SIMDE_FLOAT32_C(  -682.89), SIMDE_FLOAT32_C(  -889.08) },
        { { SIMDE_FLOAT32_C(  -568.62), SIMDE_FLOAT32_C(   946.46), SIMDE_FLOAT32_C(  -969.25), SIMDE_FLOAT32_C(  -244.42) },
          { SIMDE_FLOAT32_C(  -734.74), SIMDE_FLOAT32_C(   442.91), SIMDE_FLOAT32_C(  -269.70), SIMDE_FLOAT32_C(  -406.85) },
          { SIMDE_FLOAT32_C(  -855.46), SIMDE_FLOAT32_C(   848.61), SIMDE_FLOAT32_C(   280.25), SIMDE_FLOAT32_C(  -891.06) },
          { SIMDE_FLOAT32_C(  -283.96), SIMDE_FLOAT32_C(   193.98), SIMDE_FLOAT32_C(  -682.89), SIMDE_FLOAT32_C(  -889.08) } },
    },
    { { SIMDE_FLOAT32_C(   622.50), SIMDE_FLOAT32_C(  -426.36), SIMDE_FLOAT32_C(   765.46), SIMDE_FLOAT32_C(    -2.04),
        SIMDE_FLOAT32_C(  -538.51), SIMDE_FLOAT32_C(   827.30), SIMDE_FLOAT32_C(   114.09), SIMDE_FLOAT32_C(   762.60),
        SIMDE_FLOAT32_C(   746.73), SIMDE_FLOAT32_C(  -536.62), SIMDE_FLOAT32_C(   809.74), SIMDE_FLOAT32_C(  -864.62),
        SIMDE_FLOAT32_C(  -466.32), SIMDE_FLOAT32_C(   736.42), SIMDE_FLOAT32_C(   758.48), SIMDE_FLOAT32_C(   -34.95) },
        { { SIMDE_FLOAT32_C(   622.50), SIMDE_FLOAT32_C(  -426.36), SIMDE_FLOAT32_C(   765.46), SIMDE_FLOAT32_C(    -2.04) },
          { SIMDE_FLOAT32_C(  -538.51), SIMDE_FLOAT32_C(   827.30), SIMDE_FLOAT32_C(   114.09), SIMDE_FLOAT32_C(   762.60) },
          { SIMDE_FLOAT32_C(   746.73), SIMDE_FLOAT32_C(  -536.62), SIMDE_FLOAT32_C(   809.74), SIMDE_FLOAT32_C(  -864.62) },
          { SIMDE_FLOAT32_C(  -466.32), SIMDE_FLOAT32_C(   736.42), SIMDE_FLOAT32_C(   758.48), SIMDE_FLOAT32_C(   -34.95) } },
    },
    { { SIMDE_FLOAT32_C(   682.88), SIMDE_FLOAT32_C(   789.23), SIMDE_FLOAT32_C(   720.63), SIMDE_FLOAT32_C(   948.14),
        SIMDE_FLOAT32_C(   232.14), SIMDE_FLOAT32_C(  -549.07), SIMDE_FLOAT32_C(  -458.71), SIMDE_FLOAT32_C(   376.67),
        SIMDE_FLOAT32_C(  -700.46), SIMDE_FLOAT32_C(   821.55), SIMDE_FLOAT32_C(   485.62), SIMDE_FLOAT32_C(    15.58),
        SIMDE_FLOAT32_C(    15.53), SIMDE_FLOAT32_C(   802.73), SIMDE_FLOAT32_C(   126.49), SIMDE_FLOAT32_C(  -361.98) },
        { { SIMDE_FLOAT32_C(   682.88), SIMDE_FLOAT32_C(   789.23), SIMDE_FLOAT32_C(   720.63), SIMDE_FLOAT32_C(   948.14) },
          { SIMDE_FLOAT32_C(   232.14), SIMDE_FLOAT32_C(  -549.07), SIMDE_FLOAT32_C(  -458.71), SIMDE_FLOAT32_C(   376.67) },
          { SIMDE_FLOAT32_C(  -700.46), SIMDE_FLOAT32_C(   821.55), SIMDE_FLOAT32_C(   485.62), SIMDE_FLOAT32_C(    15.58) },
          { SIMDE_FLOAT32_C(    15.53), SIMDE_FLOAT32_C(   802.73), SIMDE_FLOAT32_C(   126.49), SIMDE_FLOAT32_C(  -361.98) } },
    },
    { { SIMDE_FLOAT32_C(  -623.64), SIMDE_FLOAT32_C(  -108.04), SIMDE_FLOAT32_C(   635.98), SIMDE_FLOAT32_C(  -162.14),
        SIMDE_FLOAT32_C(  -280.74), SIMDE_FLOAT32_C(  -249.93), SIMDE_FLOAT32_C(  -399.54), SIMDE_FLOAT32_C(  -534.01),
        SIMDE_FLOAT32_C(   213.46), SIMDE_FLOAT32_C(  -589.80), SIMDE_FLOAT32_C(  -398.64), SIMDE_FLOAT32_C(   747.13),
        SIMDE_FLOAT32_C(  -853.38), SIMDE_FLOAT32_C(  -640.15), SIMDE_FLOAT32_C(  -287.82), SIMDE_FLOAT32_C(   829.50) },
        { { SIMDE_FLOAT32_C(  -623.64), SIMDE_FLOAT32_C(  -108.04), SIMDE_FLOAT32_C(   635.98), SIMDE_FLOAT32_C(  -162.14) },
          { SIMDE_FLOAT32_C(  -280.74), SIMDE_FLOAT32_C(  -249.93), SIMDE_FLOAT32_C(  -399.54), SIMDE_FLOAT32_C(  -534.01) },
          { SIMDE_FLOAT32_C(   213.46), SIMDE_FLOAT32_C(  -589.80), SIMDE_FLOAT32_C(  -398.64), SIMDE_FLOAT32_C(   747.13) },
          { SIMDE_FLOAT32_C(  -853.38), SIMDE_FLOAT32_C(  -640.15), SIMDE_FLOAT32_C(  -287.82), SIMDE_FLOAT32_C(   829.50) } },
    },
    { { SIMDE_FLOAT32_C(  -850.92), SIMDE_FLOAT32_C(  -567.18), SIMDE_FLOAT32_C(   777.64), SIMDE_FLOAT32_C(   381.22),
        SIMDE_FLOAT32_C(  -116.25), SIMDE_FLOAT32_C(  -681.06), SIMDE_FLOAT32_C(  -242.11), SIMDE_FLOAT32_C(   183.28),
        SIMDE_FLOAT32_C(  -859.51), SIMDE_FLOAT32_C(  -756.49), SIMDE_FLOAT32_C(  -801.14), SIMDE_FLOAT32_C(   156.01),
        SIMDE_FLOAT32_C(  -953.76), SIMDE_FLOAT32_C(   325.35), SIMDE_FLOAT32_C(   794.04), SIMDE_FLOAT32_C(  -577.40) },
        { { SIMDE_FLOAT32_C(  -850.92), SIMDE_FLOAT32_C(  -567.18), SIMDE_FLOAT32_C(   777.64), SIMDE_FLOAT32_C(   381.22) },
          { SIMDE_FLOAT32_C(  -116.25), SIMDE_FLOAT32_C(  -681.06), SIMDE_FLOAT32_C(  -242.11), SIMDE_FLOAT32_C(   183.28) },
          { SIMDE_FLOAT32_C(  -859.51), SIMDE_FLOAT32_C(  -756.49), SIMDE_FLOAT32_C(  -801.14), SIMDE_FLOAT32_C(   156.01) },
          { SIMDE_FLOAT32_C(  -953.76), SIMDE_FLOAT32_C(   325.35), SIMDE_FLOAT32_C(   794.04), SIMDE_FLOAT32_C(  -577.40) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4x4_t r = simde_vld1q_f32_x4(test_vec[i].buf);
    simde_float32x4x4_t expected = {{
        simde_vld1q_f32(test_vec[i].expected[0]),
        simde_vld1q_f32(test_vec[i].expected[1]),
        simde_vld1q_f32(test_vec[i].expected[2]),
        simde_vld1q_f32(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_f32x4x4(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 buf[16];
    for (int j = 0 ; j < 16 ; j++) {
      buf[j] = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    }
    simde_test_codegen_write_vf32(2, 16, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32x4x4_t val = simde_vld1q_f32_x4(buf);
    simde_test_arm_neon_write_f32x4x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_f64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 buf[8];
    simde_float64 expected[4][2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -782.69), SIMDE_FLOAT64_C(   430.02), SIMDE_FLOAT64_C(   260.46), SIMDE_FLOAT64_C(   -63.43),
        SIMDE_FLOAT64_C(  -819.91), SIMDE_FLOAT64_C(   860.92), SIMDE_FLOAT64_C(   402.56), SIMDE_FLOAT64_C(   393.55) },
        { { SIMDE_FLOAT64_C(  -782.69), SIMDE_FLOAT64_C(   430.02) },
          { SIMDE_FLOAT64_C(   260.46), SIMDE_FLOAT64_C(   -63.43) },
          { SIMDE_FLOAT64_C(  -819.91), SIMDE_FLOAT64_C(   860.92) },
          { SIMDE_FLOAT64_C(   402.56), SIMDE_FLOAT64_C(   393.55) } },
    },
    { { SIMDE_FLOAT64_C(  -728.88), SIMDE_FLOAT64_C(  -996.08), SIMDE_FLOAT64_C(   140.68), SIMDE_FLOAT64_C(  -582.26),
        SIMDE_FLOAT64_C(  -636.23), SIMDE_FLOAT64_C(   852.86), SIMDE_FLOAT64_C(  -752.75), SIMDE_FLOAT64_C(  -487.15) },
        { { SIMDE_FLOAT64_C(  -728.88), SIMDE_FLOAT64_C(  -996.08) },
          { SIMDE_FLOAT64_C(   140.68), SIMDE_FLOAT64_C(  -582.26) },
          { SIMDE_FLOAT64_C(  -636.23), SIMDE_FLOAT64_C(   852.86) },
          { SIMDE_FLOAT64_C(  -752.75), SIMDE_FLOAT64_C(  -487.15) } },
    },
    { { SIMDE_FLOAT64_C(  -714.32), SIMDE_FLOAT64_C(  -975.11), SIMDE_FLOAT64_C(   894.07), SIMDE_FLOAT64_C(   169.43),
        SIMDE_FLOAT64_C(  -656.17), SIMDE_FLOAT64_C(  -348.04), SIMDE_FLOAT64_C(  -647.29), SIMDE_FLOAT64_C(  -515.68) },
        { { SIMDE_FLOAT64_C(  -714.32), SIMDE_FLOAT64_C(  -975.11) },
          { SIMDE_FLOAT64_C(   894.07), SIMDE_FLOAT64_C(   169.43) },
          { SIMDE_FLOAT64_C(  -656.17), SIMDE_FLOAT64_C(  -348.04) },
          { SIMDE_FLOAT64_C(  -647.29), SIMDE_FLOAT64_C(  -515.68) } },
    },
    { { SIMDE_FLOAT64_C(  -104.52), SIMDE_FLOAT64_C(  -448.43), SIMDE_FLOAT64_C(   640.33), SIMDE_FLOAT64_C(   -58.29),
        SIMDE_FLOAT64_C(   876.93), SIMDE_FLOAT64_C(   434.37), SIMDE_FLOAT64_C(   364.32), SIMDE_FLOAT64_C(  -905.76) },
        { { SIMDE_FLOAT64_C(  -104.52), SIMDE_FLOAT64_C(  -448.43) },
          { SIMDE_FLOAT64_C(   640.33), SIMDE_FLOAT64_C(   -58.29) },
          { SIMDE_FLOAT64_C(   876.93), SIMDE_FLOAT64_C(   434.37) },
          { SIMDE_FLOAT64_C(   364.32), SIMDE_FLOAT64_C(  -905.76) } },
    },
    { { SIMDE_FLOAT64_C(  -135.61), SIMDE_FLOAT64_C(  -375.22), SIMDE_FLOAT64_C(    30.81), SIMDE_FLOAT64_C(    44.48),
        SIMDE_FLOAT64_C(  -514.30), SIMDE_FLOAT64_C(  -566.63), SIMDE_FLOAT64_C(  -561.97), SIMDE_FLOAT64_C(  -243.18) },
        { { SIMDE_FLOAT64_C(  -135.61), SIMDE_FLOAT64_C(  -375.22) },
          { SIMDE_FLOAT64_C(    30.81), SIMDE_FLOAT64_C(    44.48) },
          { SIMDE_FLOAT64_C(  -514.30), SIMDE_FLOAT64_C(  -566.63) },
          { SIMDE_FLOAT64_C(  -561.97), SIMDE_FLOAT64_C(  -243.18) } },
    },
    { { SIMDE_FLOAT64_C(  -562.70), SIMDE_FLOAT64_C(   578.71), SIMDE_FLOAT64_C(   174.56), SIMDE_FLOAT64_C(  -198.93),
        SIMDE_FLOAT64_C(   431.58), SIMDE_FLOAT64_C(   421.80), SIMDE_FLOAT64_C(   313.92), SIMDE_FLOAT64_C(   717.26) },
        { { SIMDE_FLOAT64_C(  -562.70), SIMDE_FLOAT64_C(   578.71) },
          { SIMDE_FLOAT64_C(   174.56), SIMDE_FLOAT64_C(  -198.93) },
          { SIMDE_FLOAT64_C(   431.58), SIMDE_FLOAT64_C(   421.80) },
          { SIMDE_FLOAT64_C(   313.92), SIMDE_FLOAT64_C(   717.26) } },
    },
    { { SIMDE_FLOAT64_C(   446.69), SIMDE_FLOAT64_C(   207.99), SIMDE_FLOAT64_C(  -113.31), SIMDE_FLOAT64_C(   790.52),
        SIMDE_FLOAT64_C(   859.95), SIMDE_FLOAT64_C(   239.40), SIMDE_FLOAT64_C(  -725.16), SIMDE_FLOAT64_C(  -244.57) },
        { { SIMDE_FLOAT64_C(   446.69), SIMDE_FLOAT64_C(   207.99) },
          { SIMDE_FLOAT64_C(  -113.31), SIMDE_FLOAT64_C(   790.52) },
          { SIMDE_FLOAT64_C(   859.95), SIMDE_FLOAT64_C(   239.40) },
          { SIMDE_FLOAT64_C(  -725.16), SIMDE_FLOAT64_C(  -244.57) } },
    },
    { { SIMDE_FLOAT64_C(   790.98), SIMDE_FLOAT64_C(   915.17), SIMDE_FLOAT64_C(   697.14), SIMDE_FLOAT64_C(   667.91),
        SIMDE_FLOAT64_C(   349.54), SIMDE_FLOAT64_C(    61.46), SIMDE_FLOAT64_C(   762.15), SIMDE_FLOAT64_C(  -786.07) },
        { { SIMDE_FLOAT64_C(   790.98), SIMDE_FLOAT64_C(   915.17) },
          { SIMDE_FLOAT64_C(   697.14), SIMDE_FLOAT64_C(   667.91) },
          { SIMDE_FLOAT64_C(   349.54), SIMDE_FLOAT64_C(    61.46) },
          { SIMDE_FLOAT64_C(   762.15), SIMDE_FLOAT64_C(  -786.07) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2x4_t r = simde_vld1q_f64_x4(test_vec[i].buf);
    simde_float64x2x4_t expected = {{
        simde_vld1q_f64(test_vec[i].expected[0]),
        simde_vld1q_f64(test_vec[i].expected[1]),
        simde_vld1q_f64(test_vec[i].expected[2]),
        simde_vld1q_f64(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_f64x2x4(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 buf[8];
    for (int j = 0 ; j < 8 ; j++) {
      buf[j] = simde_test_codegen_random_f64(-1000.0, 1000.0);
    }
    simde_test_codegen_write_vf64(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64x2x4_t val = simde_vld1q_f64_x4(buf);
    simde_test_arm_neon_write_f64x2x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s8_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t buf[64];
    int8_t expected[4][16];
  } test_vec[] = {
    { { -INT8_C(  58), -INT8_C( 113),  INT8_C(  28),  INT8_C(  37),  INT8_C(  62), -INT8_C(  22), -INT8_C(  31), -INT8_C(   2),
        -INT8_C(  83),  INT8_C(  58),  INT8_C(  20), -INT8_C( 113),  INT8_C(  14), -INT8_C(   9), -INT8_C( 126),  INT8_C(  38),
        -INT8_C( 125), -INT8_C(   6), -INT8_C(  70),  INT8_C( 106),  INT8_C(  86), -INT8_C(  42), -INT8_C(  44), -INT8_C(  83),
         INT8_C(  99), -INT8_C(  55), -INT8_C( 100), -INT8_C(  24),  INT8_C( 125), -INT8_C(  35),  INT8_C(   3),  INT8_C(  67),
         INT8_C( 108),  INT8_C(  31),  INT8_C( 105), -INT8_C(  86),  INT8_C(  10),  INT8_C(  74), -INT8_C(  87), -INT8_C(  73),
        -INT8_C( 124), -INT8_C(  67),  INT8_C(  70), -INT8_C( 110), -INT8_C(  76), -INT8_C(  56), -INT8_C(  71),  INT8_C(  55),
        -INT8_C(  62),  INT8_C( 115), -INT8_C(  94),  INT8_C(  24),  INT8_C(  73),  INT8_C( 118), -INT8_C(  59), -INT8_C(  84),
         INT8_C(  63),  INT8_C(  98), -INT8_C( 108), -INT8_C(  67),  INT8_C(  63), -INT8_C( 105),  INT8_C(   0), -INT8_C(  85) },
        { { -INT8_C(  58), -INT8_C( 113),  INT8_C(  28),  INT8_C(  37),  INT8_C(  62), -INT8_C(  22), -INT8_C(  31), -INT8_C(   2),
            -INT8_C(  83),  INT8_C(  58),  INT8_C(  20), -INT8_C( 113),  INT8_C(  14), -INT8_C(   9), -INT8_C( 126),  INT8_C(  38) },
          { -INT8_C( 125), -INT8_C(   6), -INT8_C(  70),  INT8_C( 106),  INT8_C(  86), -INT8_C(  42), -INT8_C(  44), -INT8_C(  83),
             INT8_C(  99), -INT8_C(  55), -INT8_C( 100), -INT8_C(  24),  INT8_C( 125), -INT8_C(  35),  INT8_C(   3),  INT8_C(  67) },
          {  INT8_C( 108),  INT8_C(  31),  INT8_C( 105), -INT8_C(  86),  INT8_C(  10),  INT8_C(  74), -INT8_C(  87), -INT8_C(  73),
            -INT8_C( 124), -INT8_C(  67),  INT8_C(  70), -INT8_C( 110), -INT8_C(  76), -INT8_C(  56), -INT8_C(  71),  INT8_C(  55) },
          { -INT8_C(  62),  INT8_C( 115), -INT8_C(  94),  INT8_C(  24),  INT8_C(  73),  INT8_C( 118), -INT8_C(  59), -INT8_C(  84),
             INT8_C(  63),  INT8_C(  98), -INT8_C( 108), -INT8_C(  67),  INT8_C(  63), -INT8_C( 105),  INT8_C(   0), -INT8_C(  85) } },
    },
    { { -INT8_C(  73),  INT8_C( 105),  INT8_C(  85), -INT8_C(  63), -INT8_C(  77), -INT8_C(   2),  INT8_C( 120),  INT8_C(  55),
        -INT8_C(  69), -INT8_C(  66), -INT8_C(  54),  INT8_C( 112), -INT8_C( 121), -INT8_C( 125), -INT8_C(  89),  INT8_C(  73),
        -INT8_C(  10),  INT8_C(  73),  INT8_C(  98),  INT8_C(  63), -INT8_C(  65),  INT8_C(  39), -INT8_C(  21), -INT8_C(   1),
        -INT8_C( 119),      INT8_MAX, -INT8_C(  68), -INT8_C(  56),  INT8_C(  23), -INT8_C(  68),  INT8_C( 115), -INT8_C(  50),
         INT8_C(  38), -INT8_C(  55), -INT8_C( 113), -INT8_C(  39), -INT8_C(  57),  INT8_C(   7),  INT8_C(  17), -INT8_C( 125),
        -INT8_C(  59), -INT8_C(  37), -INT8_C(  13),  INT8_C(  76),  INT8_C(  94), -INT8_C( 102), -INT8_C( 106),  INT8_C(  84),
        -INT8_C(  28), -INT8_C(   8), -INT8_C( 109), -INT8_C(  93),  INT8_C(  31),  INT8_C( 126), -INT8_C(  94), -INT8_C(  87),
        -INT8_C(   3),  INT8_C(  94),  INT8_C( 113),  INT8_C(  20),  INT8_C(  27), -INT8_C(  27), -INT8_C(  30),  INT8_C(  65) },
        { { -INT8_C(  73),  INT8_C( 105),  INT8_C(  85), -INT8_C(  63), -INT8_C(  77), -INT8_C(   2),  INT8_C( 120),  INT8_C(  55),
            -INT8_C(  69), -INT8_C(  66), -INT8_C(  54),  INT8_C( 112), -INT8_C( 121), -INT8_C( 125), -INT8_C(  89),  INT8_C(  73) },
          { -INT8_C(  10),  INT8_C(  73),  INT8_C(  98),  INT8_C(  63), -INT8_C(  65),  INT8_C(  39), -INT8_C(  21), -INT8_C(   1),
            -INT8_C( 119),      INT8_MAX, -INT8_C(  68), -INT8_C(  56),  INT8_C(  23), -INT8_C(  68),  INT8_C( 115), -INT8_C(  50) },
          {  INT8_C(  38), -INT8_C(  55), -INT8_C( 113), -INT8_C(  39), -INT8_C(  57),  INT8_C(   7),  INT8_C(  17), -INT8_C( 125),
            -INT8_C(  59), -INT8_C(  37), -INT8_C(  13),  INT8_C(  76),  INT8_C(  94), -INT8_C( 102), -INT8_C( 106),  INT8_C(  84) },
          { -INT8_C(  28), -INT8_C(   8), -INT8_C( 109), -INT8_C(  93),  INT8_C(  31),  INT8_C( 126), -INT8_C(  94), -INT8_C(  87),
            -INT8_C(   3),  INT8_C(  94),  INT8_C( 113),  INT8_C(  20),  INT8_C(  27), -INT8_C(  27), -INT8_C(  30),  INT8_C(  65) } },
    },
    { { -INT8_C(  82),  INT8_C( 113),  INT8_C(  26),  INT8_C( 117),  INT8_C( 120),  INT8_C(  43), -INT8_C(   8),  INT8_C(  62),
         INT8_C(   6), -INT8_C(  21), -INT8_C( 118),  INT8_C( 100), -INT8_C( 122),  INT8_C(  32), -INT8_C(  72),  INT8_C( 106),
         INT8_C(  24),  INT8_C(  75),  INT8_C(  13),  INT8_C(  56), -INT8_C(  55), -INT8_C(  80), -INT8_C(  31), -INT8_C(  57),
         INT8_C(  14),  INT8_C(  82), -INT8_C(  37),  INT8_C(  41),  INT8_C(  55), -INT8_C(  66),  INT8_C( 106), -INT8_C(  27),
         INT8_C(  47), -INT8_C( 123),  INT8_C(  91), -INT8_C(  88), -INT8_C(  80),  INT8_C(  83), -INT8_C(  26), -INT8_C(  73),
         INT8_C(  63),  INT8_C( 112),  INT8_C(  27), -INT8_C(  59), -INT8_C( 111), -INT8_C(  44),  INT8_C(  47), -INT8_C(  87),
         INT8_C(  31),  INT8_C(  60), -INT8_C(  31), -INT8_C(  23), -INT8_C(  20), -INT8_C(  62), -INT8_C(  80), -INT8_C(   5),
         INT8_C(  21), -INT8_C( 117),  INT8_C(  36),  INT8_C(  76),  INT8_C(  73), -INT8_C( 113),  INT8_C(  50),  INT8_C( 121) },
        { { -INT8_C(  82),  INT8_C( 113),  INT8_C(  26),  INT8_C( 117),  INT8_C( 120),  INT8_C(  43), -INT8_C(   8),  INT8_C(  62),
             INT8_C(   6), -INT8_C(  21), -INT8_C( 118),  INT8_C( 100), -INT8_C( 122),  INT8_C(  32), -INT8_C(  72),  INT8_C( 106) },
          {  INT8_C(  24),  INT8_C(  75),  INT8_C(  13),  INT8_C(  56), -INT8_C(  55), -INT8_C(  80), -INT8_C(  31), -INT8_C(  57),
             INT8_C(  14),  INT8_C(  82), -INT8_C(  37),  INT8_C(  41),  INT8_C(  55), -INT8_C(  66),  INT8_C( 106), -INT8_C(  27) },
          {  INT8_C(  47), -INT8_C( 123),  INT8_C(  91), -INT8_C(  88), -INT8_C(  80),  INT8_C(  83), -INT8_C(  26), -INT8_C(  73),
             INT8_C(  63),  INT8_C( 112),  INT8_C(  27), -INT8_C(  59), -INT8_C( 111), -INT8_C(  44),  INT8_C(  47), -INT8_C(  87) },
          {  INT8_C(  31),  INT8_C(  60), -INT8_C(  31), -INT8_C(  23), -INT8_C(  20), -INT8_C(  62), -INT8_C(  80), -INT8_C(   5),
             INT8_C(  21), -INT8_C( 117),  INT8_C(  36),  INT8_C(  76),  INT8_C(  73), -INT8_C( 113),  INT8_C(  50),  INT8_C( 121) } },
    },
    { {  INT8_C(  20), -INT8_C( 115),  INT8_C(  33), -INT8_C(  60), -INT8_C(  32),  INT8_C(   7),  INT8_C( 123),  INT8_C(  31),
         INT8_C( 119), -INT8_C( 105), -INT8_C(  28),  INT8_C(   8),  INT8_C( 107),  INT8_C(  19), -INT8_C(  78), -INT8_C( 118),
         INT8_C(  80), -INT8_C( 109),  INT8_C( 115),  INT8_C(  60),  INT8_C(  86),  INT8_C(  35),  INT8_C(  55),  INT8_C( 107),
        -INT8_C(  81),  INT8_C(  92), -INT8_C(  73), -INT8_C(   8), -INT8_C(  21), -INT8_C(  23),  INT8_C( 113), -INT8_C(   1),
         INT8_C( 118), -INT8_C( 110), -INT8_C(  61),  INT8_C(  87), -INT8_C( 103),  INT8_C(  63),  INT8_C( 118),  INT8_C(  17),
        -INT8_C(  42),  INT8_C(  91),  INT8_C(  25),  INT8_C(  65),  INT8_C( 110), -INT8_C(  53), -INT8_C(  53), -INT8_C(  66),
         INT8_C(  95),  INT8_C(  63), -INT8_C(   5), -INT8_C(  75),  INT8_C(  98),  INT8_C(  50),  INT8_C(  32),  INT8_C(  17),
        -INT8_C( 114), -INT8_C(  41),  INT8_C(  10),  INT8_C( 121), -INT8_C(  63),  INT8_C( 123),  INT8_C( 120),  INT8_C(  55) },
        { {  INT8_C(  20), -INT8_C( 115),  INT8_C(  33), -INT8_C(  60), -INT8_C(  32),  INT8_C(   7),  INT8_C( 123),  INT8_C(  31),
             INT8_C( 119), -INT8_C( 105), -INT8_C(  28),  INT8_C(   8),  INT8_C( 107),  INT8_C(  19), -INT8_C(  78), -INT8_C( 118) },
          {  INT8_C(  80), -INT8_C( 109),  INT8_C( 115),  INT8_C(  60),  INT8_C(  86),  INT8_C(  35),  INT8_C(  55),  INT8_C( 107),
            -INT8_C(  81),  INT8_C(  92), -INT8_C(  73), -INT8_C(   8), -INT8_C(  21), -INT8_C(  23),  INT8_C( 113), -INT8_C(   1) },
          {  INT8_C( 118), -INT8_C( 110), -INT8_C(  61),  INT8_C(  87), -INT8_C( 103),  INT8_C(  63),  INT8_C( 118),  INT8_C(  17),
            -INT8_C(  42),  INT8_C(  91),  INT8_C(  25),  INT8_C(  65),  INT8_C( 110), -INT8_C(  53), -INT8_C(  53), -INT8_C(  66) },
          {  INT8_C(  95),  INT8_C(  63), -INT8_C(   5), -INT8_C(  75),  INT8_C(  98),  INT8_C(  50),  INT8_C(  32),  INT8_C(  17),
            -INT8_C( 114), -INT8_C(  41),  INT8_C(  10),  INT8_C( 121), -INT8_C(  63),  INT8_C( 123),  INT8_C( 120),  INT8_C(  55) } },
    },
    { {  INT8_C(  14),  INT8_C(  60), -INT8_C( 114), -INT8_C(  89),  INT8_C( 123),  INT8_C(   5), -INT8_C(  72),  INT8_C(  81),
         INT8_C(  96), -INT8_C(  46), -INT8_C( 110), -INT8_C(  50), -INT8_C(  99),  INT8_C(  93), -INT8_C( 115), -INT8_C(   4),
        -INT8_C( 100), -INT8_C( 120), -INT8_C(  79), -INT8_C(   1), -INT8_C(  70), -INT8_C(  47),  INT8_C(  16),  INT8_C(  73),
        -INT8_C(  87),  INT8_C(  26), -INT8_C(  62),  INT8_C( 106), -INT8_C( 106),  INT8_C(  59), -INT8_C(  95), -INT8_C(  92),
         INT8_C( 119),  INT8_C(  48),  INT8_C(  75), -INT8_C(  14),  INT8_C(  53),  INT8_C(   4),  INT8_C(  67), -INT8_C( 107),
        -INT8_C(  42), -INT8_C(  43),  INT8_C(  99),  INT8_C( 115),  INT8_C(  50), -INT8_C(  16),  INT8_C( 112), -INT8_C(  49),
         INT8_C( 120),  INT8_C(  33), -INT8_C(  50),  INT8_C(  51), -INT8_C(  13), -INT8_C(  34),  INT8_C( 124), -INT8_C( 100),
        -INT8_C(   7),  INT8_C(  62),  INT8_C(   6), -INT8_C( 113),  INT8_C( 121), -INT8_C(  89),  INT8_C(  51), -INT8_C(  16) },
        { {  INT8_C(  14),  INT8_C(  60), -INT8_C( 114), -INT8_C(  89),  INT8_C( 123),  INT8_C(   5), -INT8_C(  72),  INT8_C(  81),
             INT8_C(  96), -INT8_C(  46), -INT8_C( 110), -INT8_C(  50), -INT8_C(  99),  INT8_C(  93), -INT8_C( 115), -INT8_C(   4) },
          { -INT8_C( 100), -INT8_C( 120), -INT8_C(  79), -INT8_C(   1), -INT8_C(  70), -INT8_C(  47),  INT8_C(  16),  INT8_C(  73),
            -INT8_C(  87),  INT8_C(  26), -INT8_C(  62),  INT8_C( 106), -INT8_C( 106),  INT8_C(  59), -INT8_C(  95), -INT8_C(  92) },
          {  INT8_C( 119),  INT8_C(  48),  INT8_C(  75), -INT8_C(  14),  INT8_C(  53),  INT8_C(   4),  INT8_C(  67), -INT8_C( 107),
            -INT8_C(  42), -INT8_C(  43),  INT8_C(  99),  INT8_C( 115),  INT8_C(  50), -INT8_C(  16),  INT8_C( 112), -INT8_C(  49) },
          {  INT8_C( 120),  INT8_C(  33), -INT8_C(  50),  INT8_C(  51), -INT8_C(  13), -INT8_C(  34),  INT8_C( 124), -INT8_C( 100),
            -INT8_C(   7),  INT8_C(  62),  INT8_C(   6), -INT8_C( 113),  INT8_C( 121), -INT8_C(  89),  INT8_C(  51), -INT8_C(  16) } },
    },
    { { -INT8_C(  41),  INT8_C( 126), -INT8_C(  30),  INT8_C(  12), -INT8_C( 126),  INT8_C(  37), -INT8_C(  95),  INT8_C(  88),
        -INT8_C(   6),  INT8_C(   5), -INT8_C(  52),  INT8_C(  45), -INT8_C(  11),  INT8_C(  60), -INT8_C(   4),  INT8_C( 110),
         INT8_C(  93), -INT8_C(  54), -INT8_C(  95),  INT8_C(  80), -INT8_C(  88),  INT8_C(  29), -INT8_C(  20), -INT8_C(  95),
         INT8_C(  91), -INT8_C(  14),  INT8_C(  48), -INT8_C(  43), -INT8_C( 102),  INT8_C(  99), -INT8_C(  59),  INT8_C( 113),
        -INT8_C(  30), -INT8_C(  88),  INT8_C( 126),  INT8_C( 100), -INT8_C(  51),  INT8_C(  31), -INT8_C(  67), -INT8_C(  56),
         INT8_C(  36), -INT8_C( 119), -INT8_C(  11),  INT8_C(  26), -INT8_C(  59), -INT8_C(  15), -INT8_C( 120),  INT8_C(  34),
        -INT8_C(  69),  INT8_C(  41),  INT8_C( 115),  INT8_C(  99),  INT8_C(  70),  INT8_C(  95),  INT8_C(   5), -INT8_C(  95),
         INT8_C(  82),  INT8_C(  53),  INT8_C( 118), -INT8_C(  20), -INT8_C( 103),  INT8_C(  60),  INT8_C(  93),  INT8_C( 123) },
        { { -INT8_C(  41),  INT8_C( 126), -INT8_C(  30),  INT8_C(  12), -INT8_C( 126),  INT8_C(  37), -INT8_C(  95),  INT8_C(  88),
            -INT8_C(   6),  INT8_C(   5), -INT8_C(  52),  INT8_C(  45), -INT8_C(  11),  INT8_C(  60), -INT8_C(   4),  INT8_C( 110) },
          {  INT8_C(  93), -INT8_C(  54), -INT8_C(  95),  INT8_C(  80), -INT8_C(  88),  INT8_C(  29), -INT8_C(  20), -INT8_C(  95),
             INT8_C(  91), -INT8_C(  14),  INT8_C(  48), -INT8_C(  43), -INT8_C( 102),  INT8_C(  99), -INT8_C(  59),  INT8_C( 113) },
          { -INT8_C(  30), -INT8_C(  88),  INT8_C( 126),  INT8_C( 100), -INT8_C(  51),  INT8_C(  31), -INT8_C(  67), -INT8_C(  56),
             INT8_C(  36), -INT8_C( 119), -INT8_C(  11),  INT8_C(  26), -INT8_C(  59), -INT8_C(  15), -INT8_C( 120),  INT8_C(  34) },
          { -INT8_C(  69),  INT8_C(  41),  INT8_C( 115),  INT8_C(  99),  INT8_C(  70),  INT8_C(  95),  INT8_C(   5), -INT8_C(  95),
             INT8_C(  82),  INT8_C(  53),  INT8_C( 118), -INT8_C(  20), -INT8_C( 103),  INT8_C(  60),  INT8_C(  93),  INT8_C( 123) } },
    },
    { { -INT8_C(  28), -INT8_C(  37), -INT8_C(  33), -INT8_C(  79), -INT8_C(   5), -INT8_C( 100),  INT8_C( 121),  INT8_C(  31),
         INT8_C(  37),  INT8_C( 110),  INT8_C(  57), -INT8_C(  22),  INT8_C(  95), -INT8_C(  63),  INT8_C(  13),  INT8_C(  26),
        -INT8_C(  22),      INT8_MIN,  INT8_C( 126),  INT8_C(  48), -INT8_C(  33), -INT8_C( 125), -INT8_C(  46),  INT8_C(  49),
        -INT8_C(  72),  INT8_C(  72),  INT8_C(  29),  INT8_C(  81), -INT8_C( 124),  INT8_C( 123), -INT8_C(  52),  INT8_C( 104),
         INT8_C(  86), -INT8_C(  84),  INT8_C(  26),  INT8_C(  81),  INT8_C(  72), -INT8_C( 109),  INT8_C( 113),  INT8_C( 110),
         INT8_C(   2), -INT8_C(  86),  INT8_C(  88),  INT8_C(  97),  INT8_C( 108),  INT8_C( 101),  INT8_C( 124),  INT8_C(  86),
        -INT8_C(  27), -INT8_C(   6), -INT8_C( 121), -INT8_C(  59),  INT8_C( 125),  INT8_C(  89), -INT8_C(  10),  INT8_C(  53),
        -INT8_C(  95),  INT8_C(  20), -INT8_C( 121),  INT8_C(  38), -INT8_C( 113),  INT8_C(  83), -INT8_C( 114), -INT8_C(  27) },
        { { -INT8_C(  28), -INT8_C(  37), -INT8_C(  33), -INT8_C(  79), -INT8_C(   5), -INT8_C( 100),  INT8_C( 121),  INT8_C(  31),
             INT8_C(  37),  INT8_C( 110),  INT8_C(  57), -INT8_C(  22),  INT8_C(  95), -INT8_C(  63),  INT8_C(  13),  INT8_C(  26) },
          { -INT8_C(  22),      INT8_MIN,  INT8_C( 126),  INT8_C(  48), -INT8_C(  33), -INT8_C( 125), -INT8_C(  46),  INT8_C(  49),
            -INT8_C(  72),  INT8_C(  72),  INT8_C(  29),  INT8_C(  81), -INT8_C( 124),  INT8_C( 123), -INT8_C(  52),  INT8_C( 104) },
          {  INT8_C(  86), -INT8_C(  84),  INT8_C(  26),  INT8_C(  81),  INT8_C(  72), -INT8_C( 109),  INT8_C( 113),  INT8_C( 110),
             INT8_C(   2), -INT8_C(  86),  INT8_C(  88),  INT8_C(  97),  INT8_C( 108),  INT8_C( 101),  INT8_C( 124),  INT8_C(  86) },
          { -INT8_C(  27), -INT8_C(   6), -INT8_C( 121), -INT8_C(  59),  INT8_C( 125),  INT8_C(  89), -INT8_C(  10),  INT8_C(  53),
            -INT8_C(  95),  INT8_C(  20), -INT8_C( 121),  INT8_C(  38), -INT8_C( 113),  INT8_C(  83), -INT8_C( 114), -INT8_C(  27) } },
    },
    { { -INT8_C(   1), -INT8_C(  88),  INT8_C(  55),  INT8_C(  72),  INT8_C(  60), -INT8_C(  88), -INT8_C(  74),  INT8_C(  62),
         INT8_C(  82),  INT8_C(  14), -INT8_C(  97), -INT8_C(  66),  INT8_C( 116),  INT8_C(  27),  INT8_C(  21),  INT8_C(  89),
         INT8_C(  21), -INT8_C( 100),  INT8_C(  30), -INT8_C( 110), -INT8_C(  11),  INT8_C(  21), -INT8_C(  56), -INT8_C( 106),
         INT8_C(  41),  INT8_C(  79), -INT8_C(  68), -INT8_C(  72), -INT8_C(  94),  INT8_C(  75), -INT8_C(  99), -INT8_C(  94),
        -INT8_C(  13), -INT8_C(  44), -INT8_C(  22),  INT8_C(  47),  INT8_C( 124), -INT8_C(  96),  INT8_C( 109), -INT8_C(  49),
        -INT8_C(  82),  INT8_C(  13), -INT8_C( 115),  INT8_C(  34),  INT8_C(  40), -INT8_C(  94),  INT8_C( 124),  INT8_C(  62),
         INT8_C(  62), -INT8_C( 102), -INT8_C(  48),  INT8_C(  51), -INT8_C(  81), -INT8_C( 104), -INT8_C(  54), -INT8_C(  40),
        -INT8_C(  25), -INT8_C( 122), -INT8_C( 112), -INT8_C( 118), -INT8_C(  47),  INT8_C(  46),  INT8_C(  44), -INT8_C(  59) },
        { { -INT8_C(   1), -INT8_C(  88),  INT8_C(  55),  INT8_C(  72),  INT8_C(  60), -INT8_C(  88), -INT8_C(  74),  INT8_C(  62),
             INT8_C(  82),  INT8_C(  14), -INT8_C(  97), -INT8_C(  66),  INT8_C( 116),  INT8_C(  27),  INT8_C(  21),  INT8_C(  89) },
          {  INT8_C(  21), -INT8_C( 100),  INT8_C(  30), -INT8_C( 110), -INT8_C(  11),  INT8_C(  21), -INT8_C(  56), -INT8_C( 106),
             INT8_C(  41),  INT8_C(  79), -INT8_C(  68), -INT8_C(  72), -INT8_C(  94),  INT8_C(  75), -INT8_C(  99), -INT8_C(  94) },
          { -INT8_C(  13), -INT8_C(  44), -INT8_C(  22),  INT8_C(  47),  INT8_C( 124), -INT8_C(  96),  INT8_C( 109), -INT8_C(  49),
            -INT8_C(  82),  INT8_C(  13), -INT8_C( 115),  INT8_C(  34),  INT8_C(  40), -INT8_C(  94),  INT8_C( 124),  INT8_C(  62) },
          {  INT8_C(  62), -INT8_C( 102), -INT8_C(  48),  INT8_C(  51), -INT8_C(  81), -INT8_C( 104), -INT8_C(  54), -INT8_C(  40),
            -INT8_C(  25), -INT8_C( 122), -INT8_C( 112), -INT8_C( 118), -INT8_C(  47),  INT8_C(  46),  INT8_C(  44), -INT8_C(  59) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16x4_t r = simde_vld1q_s8_x4(test_vec[i].buf);
    simde_int8x16x4_t expected = {{
        simde_vld1q_s8(test_vec[i].expected[0]),
        simde_vld1q_s8(test_vec[i].expected[1]),
        simde_vld1q_s8(test_vec[i].expected[2]),
        simde_vld1q_s8(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_i8x16x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int8_t buf[64];
    simde_test_codegen_random_memory(64, (uint8_t*)buf);
    simde_test_codegen_write_vi8(2, 64, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int8x16x4_t val = simde_vld1q_s8_x4(buf);
    simde_test_arm_neon_write_i8x16x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s16_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t buf[32];
    int16_t expected[4][8];
  } test_vec[] = {
    { { -INT16_C(  3028), -INT16_C(  9957), -INT16_C( 13972),  INT16_C(  8275), -INT16_C( 11262), -INT16_C( 26807), -INT16_C( 24460),  INT16_C( 20280),
         INT16_C(   736),  INT16_C(   321), -INT16_C( 23819), -INT16_C( 29317),  INT16_C( 15380),  INT16_C( 18873), -INT16_C( 26631),  INT16_C(  9642),
        -INT16_C( 14709), -INT16_C(  2050),  INT16_C( 20879), -INT16_C( 28392),  INT16_C( 24869), -INT16_C( 26328),  INT16_C( 24833), -INT16_C(  7447),
         INT16_C( 10851),  INT16_C( 23011),  INT16_C( 24268), -INT16_C(  7706), -INT16_C( 24678), -INT16_C( 27606), -INT16_C( 11210), -INT16_C( 15943) },
        { { -INT16_C(  3028), -INT16_C(  9957), -INT16_C( 13972),  INT16_C(  8275), -INT16_C( 11262), -INT16_C( 26807), -INT16_C( 24460),  INT16_C( 20280) },
          {  INT16_C(   736),  INT16_C(   321), -INT16_C( 23819), -INT16_C( 29317),  INT16_C( 15380),  INT16_C( 18873), -INT16_C( 26631),  INT16_C(  9642) },
          { -INT16_C( 14709), -INT16_C(  2050),  INT16_C( 20879), -INT16_C( 28392),  INT16_C( 24869), -INT16_C( 26328),  INT16_C( 24833), -INT16_C(  7447) },
          {  INT16_C( 10851),  INT16_C( 23011),  INT16_C( 24268), -INT16_C(  7706), -INT16_C( 24678), -INT16_C( 27606), -INT16_C( 11210), -INT16_C( 15943) } },
    },
    { { -INT16_C( 18278),  INT16_C( 10937), -INT16_C( 12023),  INT16_C( 12219), -INT16_C(  7118),  INT16_C( 13512), -INT16_C( 20155), -INT16_C( 22506),
        -INT16_C(  1572), -INT16_C( 22527), -INT16_C(  6057), -INT16_C(  3447), -INT16_C( 19577), -INT16_C( 16762),  INT16_C( 16264),  INT16_C(  8831),
         INT16_C( 14583),  INT16_C(   332),  INT16_C(  2057),  INT16_C( 15408), -INT16_C(  1812),  INT16_C( 12656), -INT16_C( 31062), -INT16_C( 31015),
        -INT16_C(  9345), -INT16_C( 10706), -INT16_C( 18237),  INT16_C( 19144),  INT16_C( 20075), -INT16_C(  3320), -INT16_C( 30578), -INT16_C( 31466) },
        { { -INT16_C( 18278),  INT16_C( 10937), -INT16_C( 12023),  INT16_C( 12219), -INT16_C(  7118),  INT16_C( 13512), -INT16_C( 20155), -INT16_C( 22506) },
          { -INT16_C(  1572), -INT16_C( 22527), -INT16_C(  6057), -INT16_C(  3447), -INT16_C( 19577), -INT16_C( 16762),  INT16_C( 16264),  INT16_C(  8831) },
          {  INT16_C( 14583),  INT16_C(   332),  INT16_C(  2057),  INT16_C( 15408), -INT16_C(  1812),  INT16_C( 12656), -INT16_C( 31062), -INT16_C( 31015) },
          { -INT16_C(  9345), -INT16_C( 10706), -INT16_C( 18237),  INT16_C( 19144),  INT16_C( 20075), -INT16_C(  3320), -INT16_C( 30578), -INT16_C( 31466) } },
    },
    { {  INT16_C( 25280), -INT16_C( 13690), -INT16_C( 18838),  INT16_C( 22022),  INT16_C( 30383),  INT16_C( 22919),  INT16_C( 25084),  INT16_C( 31711),
         INT16_C(  3388), -INT16_C(   175),  INT16_C(  6853),  INT16_C( 12617),  INT16_C( 21096), -INT16_C(  2524),  INT16_C( 15066), -INT16_C( 25988),
         INT16_C(   669),  INT16_C(  1892),  INT16_C( 27321),  INT16_C( 26718), -INT16_C(  6688), -INT16_C(  9023), -INT16_C( 24506), -INT16_C( 32169),
        -INT16_C( 22099),  INT16_C( 29569), -INT16_C( 13373),  INT16_C( 11172), -INT16_C( 14307), -INT16_C(  2270), -INT16_C( 25085), -INT16_C( 24431) },
        { {  INT16_C( 25280), -INT16_C( 13690), -INT16_C( 18838),  INT16_C( 22022),  INT16_C( 30383),  INT16_C( 22919),  INT16_C( 25084),  INT16_C( 31711) },
          {  INT16_C(  3388), -INT16_C(   175),  INT16_C(  6853),  INT16_C( 12617),  INT16_C( 21096), -INT16_C(  2524),  INT16_C( 15066), -INT16_C( 25988) },
          {  INT16_C(   669),  INT16_C(  1892),  INT16_C( 27321),  INT16_C( 26718), -INT16_C(  6688), -INT16_C(  9023), -INT16_C( 24506), -INT16_C( 32169) },
          { -INT16_C( 22099),  INT16_C( 29569), -INT16_C( 13373),  INT16_C( 11172), -INT16_C( 14307), -INT16_C(  2270), -INT16_C( 25085), -INT16_C( 24431) } },
    },
    { { -INT16_C(  2400),  INT16_C( 22951),  INT16_C(  1376),  INT16_C( 16833), -INT16_C( 32021),  INT16_C( 12573),  INT16_C( 29986), -INT16_C( 12108),
         INT16_C( 13598), -INT16_C(  7869), -INT16_C(  6400),  INT16_C(  7436),  INT16_C( 11951), -INT16_C( 19948), -INT16_C( 22836),  INT16_C( 27986),
        -INT16_C(  1380), -INT16_C(   826), -INT16_C( 30465), -INT16_C(  5571),  INT16_C( 23306),  INT16_C( 11548), -INT16_C( 12080), -INT16_C(  4355),
         INT16_C( 16389),  INT16_C(  1743), -INT16_C(  9433), -INT16_C( 10717),  INT16_C( 14346), -INT16_C( 10615), -INT16_C(  9250),  INT16_C( 31299) },
        { { -INT16_C(  2400),  INT16_C( 22951),  INT16_C(  1376),  INT16_C( 16833), -INT16_C( 32021),  INT16_C( 12573),  INT16_C( 29986), -INT16_C( 12108) },
          {  INT16_C( 13598), -INT16_C(  7869), -INT16_C(  6400),  INT16_C(  7436),  INT16_C( 11951), -INT16_C( 19948), -INT16_C( 22836),  INT16_C( 27986) },
          { -INT16_C(  1380), -INT16_C(   826), -INT16_C( 30465), -INT16_C(  5571),  INT16_C( 23306),  INT16_C( 11548), -INT16_C( 12080), -INT16_C(  4355) },
          {  INT16_C( 16389),  INT16_C(  1743), -INT16_C(  9433), -INT16_C( 10717),  INT16_C( 14346), -INT16_C( 10615), -INT16_C(  9250),  INT16_C( 31299) } },
    },
    { {  INT16_C(  2773), -INT16_C( 10890), -INT16_C( 19310), -INT16_C( 25409), -INT16_C(  9457), -INT16_C(  8247), -INT16_C( 14677), -INT16_C( 20019),
        -INT16_C( 25594),  INT16_C( 11703), -INT16_C(  9609), -INT16_C( 32508), -INT16_C( 29422), -INT16_C(  4008), -INT16_C( 25752),  INT16_C( 15978),
        -INT16_C(  7771),  INT16_C( 14099), -INT16_C( 11627), -INT16_C( 23340), -INT16_C( 25170),  INT16_C( 22915),  INT16_C( 20580),  INT16_C( 27146),
        -INT16_C( 15892),  INT16_C( 25496), -INT16_C( 25444), -INT16_C( 20763),  INT16_C( 15657), -INT16_C( 28257),  INT16_C(  2520),  INT16_C( 32463) },
        { {  INT16_C(  2773), -INT16_C( 10890), -INT16_C( 19310), -INT16_C( 25409), -INT16_C(  9457), -INT16_C(  8247), -INT16_C( 14677), -INT16_C( 20019) },
          { -INT16_C( 25594),  INT16_C( 11703), -INT16_C(  9609), -INT16_C( 32508), -INT16_C( 29422), -INT16_C(  4008), -INT16_C( 25752),  INT16_C( 15978) },
          { -INT16_C(  7771),  INT16_C( 14099), -INT16_C( 11627), -INT16_C( 23340), -INT16_C( 25170),  INT16_C( 22915),  INT16_C( 20580),  INT16_C( 27146) },
          { -INT16_C( 15892),  INT16_C( 25496), -INT16_C( 25444), -INT16_C( 20763),  INT16_C( 15657), -INT16_C( 28257),  INT16_C(  2520),  INT16_C( 32463) } },
    },
    { { -INT16_C(  7446),  INT16_C( 32693), -INT16_C( 30283),  INT16_C( 25379), -INT16_C( 23001), -INT16_C( 29764), -INT16_C( 14346), -INT16_C(  7435),
        -INT16_C( 29304),  INT16_C(  9286),  INT16_C( 11049),  INT16_C( 21203),  INT16_C( 29288),  INT16_C( 16612), -INT16_C( 19589),  INT16_C( 26302),
         INT16_C( 29846),  INT16_C( 19429),  INT16_C(  2557),  INT16_C(  9390),  INT16_C( 27311), -INT16_C( 22865), -INT16_C( 23247), -INT16_C( 17784),
        -INT16_C( 12750),  INT16_C( 23774), -INT16_C( 19975),  INT16_C( 25006), -INT16_C( 28125), -INT16_C( 24670),  INT16_C( 24646), -INT16_C(  9211) },
        { { -INT16_C(  7446),  INT16_C( 32693), -INT16_C( 30283),  INT16_C( 25379), -INT16_C( 23001), -INT16_C( 29764), -INT16_C( 14346), -INT16_C(  7435) },
          { -INT16_C( 29304),  INT16_C(  9286),  INT16_C( 11049),  INT16_C( 21203),  INT16_C( 29288),  INT16_C( 16612), -INT16_C( 19589),  INT16_C( 26302) },
          {  INT16_C( 29846),  INT16_C( 19429),  INT16_C(  2557),  INT16_C(  9390),  INT16_C( 27311), -INT16_C( 22865), -INT16_C( 23247), -INT16_C( 17784) },
          { -INT16_C( 12750),  INT16_C( 23774), -INT16_C( 19975),  INT16_C( 25006), -INT16_C( 28125), -INT16_C( 24670),  INT16_C( 24646), -INT16_C(  9211) } },
    },
    { { -INT16_C(  5420), -INT16_C( 11737), -INT16_C( 10765), -INT16_C( 23562), -INT16_C( 22977),  INT16_C( 29001), -INT16_C( 11957),  INT16_C( 32043),
         INT16_C(  2464), -INT16_C( 26151), -INT16_C( 30533), -INT16_C(  8453), -INT16_C( 25318),  INT16_C( 24701), -INT16_C( 32003), -INT16_C( 11716),
         INT16_C( 25453),  INT16_C( 24740), -INT16_C( 26056),  INT16_C( 30723),  INT16_C( 19520), -INT16_C( 29719),  INT16_C(  5150), -INT16_C( 16887),
        -INT16_C(  7651), -INT16_C( 10153),  INT16_C( 21098), -INT16_C( 31305),  INT16_C( 13551), -INT16_C(  4635),  INT16_C(  8887),  INT16_C(  9407) },
        { { -INT16_C(  5420), -INT16_C( 11737), -INT16_C( 10765), -INT16_C( 23562), -INT16_C( 22977),  INT16_C( 29001), -INT16_C( 11957),  INT16_C( 32043) },
          {  INT16_C(  2464), -INT16_C( 26151), -INT16_C( 30533), -INT16_C(  8453), -INT16_C( 25318),  INT16_C( 24701), -INT16_C( 32003), -INT16_C( 11716) },
          {  INT16_C( 25453),  INT16_C( 24740), -INT16_C( 26056),  INT16_C( 30723),  INT16_C( 19520), -INT16_C( 29719),  INT16_C(  5150), -INT16_C( 16887) },
          { -INT16_C(  7651), -INT16_C( 10153),  INT16_C( 21098), -INT16_C( 31305),  INT16_C( 13551), -INT16_C(  4635),  INT16_C(  8887),  INT16_C(  9407) } },
    },
    { {  INT16_C( 25477), -INT16_C( 16764), -INT16_C( 30467),  INT16_C( 15926),  INT16_C(  8148), -INT16_C(  3383), -INT16_C( 11725),  INT16_C( 20656),
         INT16_C(  2229),  INT16_C(  7977), -INT16_C(  8102),  INT16_C( 19108), -INT16_C( 30188), -INT16_C( 13513), -INT16_C(  2388),  INT16_C( 12783),
         INT16_C( 29785),  INT16_C( 22255),  INT16_C(  9724), -INT16_C( 12140),  INT16_C( 24132),  INT16_C( 30659),  INT16_C( 29488), -INT16_C(  6712),
        -INT16_C(  3717), -INT16_C( 10747), -INT16_C( 22063), -INT16_C(  6880),  INT16_C( 22323), -INT16_C(  8271), -INT16_C( 24499), -INT16_C( 23023) },
        { {  INT16_C( 25477), -INT16_C( 16764), -INT16_C( 30467),  INT16_C( 15926),  INT16_C(  8148), -INT16_C(  3383), -INT16_C( 11725),  INT16_C( 20656) },
          {  INT16_C(  2229),  INT16_C(  7977), -INT16_C(  8102),  INT16_C( 19108), -INT16_C( 30188), -INT16_C( 13513), -INT16_C(  2388),  INT16_C( 12783) },
          {  INT16_C( 29785),  INT16_C( 22255),  INT16_C(  9724), -INT16_C( 12140),  INT16_C( 24132),  INT16_C( 30659),  INT16_C( 29488), -INT16_C(  6712) },
          { -INT16_C(  3717), -INT16_C( 10747), -INT16_C( 22063), -INT16_C(  6880),  INT16_C( 22323), -INT16_C(  8271), -INT16_C( 24499), -INT16_C( 23023) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8x4_t r = simde_vld1q_s16_x4(test_vec[i].buf);
    simde_int16x8x4_t expected = {{
        simde_vld1q_s16(test_vec[i].expected[0]),
        simde_vld1q_s16(test_vec[i].expected[1]),
        simde_vld1q_s16(test_vec[i].expected[2]),
        simde_vld1q_s16(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_i16x8x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int16_t buf[32];
    simde_test_codegen_random_memory(64, (uint8_t*)buf);
    simde_test_codegen_write_vi16(2, 32, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int16x8x4_t val = simde_vld1q_s16_x4(buf);
    simde_test_arm_neon_write_i16x8x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t buf[16];
    int32_t expected[4][4];
  } test_vec[] = {
    { {  INT32_C(   284950548),  INT32_C(  1793167654),  INT32_C(   534947055), -INT32_C(  1828345321),  INT32_C(  1818823323), -INT32_C(   414086733),  INT32_C(   767951584), -INT32_C(  1210853469),
        -INT32_C(    20394024),  INT32_C(  1332259168),  INT32_C(  1685015117), -INT32_C(  1879608076),  INT32_C(   838557822), -INT32_C(   921154071), -INT32_C(   218702001), -INT32_C(  1901409866) },
        { {  INT32_C(   284950548),  INT32_C(  1793167654),  INT32_C(   534947055), -INT32_C(  1828345321) },
          {  INT32_C(  1818823323), -INT32_C(   414086733),  INT32_C(   767951584), -INT32_C(  1210853469) },
          { -INT32_C(    20394024),  INT32_C(  1332259168),  INT32_C(  1685015117), -INT32_C(  1879608076) },
          {  INT32_C(   838557822), -INT32_C(   921154071), -INT32_C(   218702001), -INT32_C(  1901409866) } },
    },
    { { -INT32_C(   108236135),  INT32_C(  1749677339),  INT32_C(   885831743), -INT32_C(  1430010836),  INT32_C(   249282340),  INT32_C(  1540879372), -INT32_C(  1991323949),  INT32_C(   806942871),
        -INT32_C(  2060802966), -INT32_C(   638749799),  INT32_C(  1460517163), -INT32_C(  1576939395), -INT32_C(  1682908017), -INT32_C(  1544058928), -INT32_C(   315800235), -INT32_C(  1491253955) },
        { { -INT32_C(   108236135),  INT32_C(  1749677339),  INT32_C(   885831743), -INT32_C(  1430010836) },
          {  INT32_C(   249282340),  INT32_C(  1540879372), -INT32_C(  1991323949),  INT32_C(   806942871) },
          { -INT32_C(  2060802966), -INT32_C(   638749799),  INT32_C(  1460517163), -INT32_C(  1576939395) },
          { -INT32_C(  1682908017), -INT32_C(  1544058928), -INT32_C(   315800235), -INT32_C(  1491253955) } },
    },
    { { -INT32_C(  2094250007), -INT32_C(   446948934),  INT32_C(  1346136530), -INT32_C(   906871495), -INT32_C(   362503654),  INT32_C(  2140035881), -INT32_C(   580076640), -INT32_C(   377190144),
        -INT32_C(  1955811119), -INT32_C(  1670264631),  INT32_C(  1810672945),  INT32_C(    87351019), -INT32_C(  1443915648), -INT32_C(  1809285644),  INT32_C(   947033144), -INT32_C(   282921442) },
        { { -INT32_C(  2094250007), -INT32_C(   446948934),  INT32_C(  1346136530), -INT32_C(   906871495) },
          { -INT32_C(   362503654),  INT32_C(  2140035881), -INT32_C(   580076640), -INT32_C(   377190144) },
          { -INT32_C(  1955811119), -INT32_C(  1670264631),  INT32_C(  1810672945),  INT32_C(    87351019) },
          { -INT32_C(  1443915648), -INT32_C(  1809285644),  INT32_C(   947033144), -INT32_C(   282921442) } },
    },
    { {  INT32_C(  1887080103), -INT32_C(  2012419241), -INT32_C(  2064385895),  INT32_C(  1451829206), -INT32_C(  1275037504),  INT32_C(   776481014), -INT32_C(   613958979),  INT32_C(  1489668529),
         INT32_C(  1858618391), -INT32_C(   906504912), -INT32_C(  1538397491), -INT32_C(   755313134),  INT32_C(  1149696590), -INT32_C(   529281501),  INT32_C(   985389705),  INT32_C(  2056422755) },
        { {  INT32_C(  1887080103), -INT32_C(  2012419241), -INT32_C(  2064385895),  INT32_C(  1451829206) },
          { -INT32_C(  1275037504),  INT32_C(   776481014), -INT32_C(   613958979),  INT32_C(  1489668529) },
          {  INT32_C(  1858618391), -INT32_C(   906504912), -INT32_C(  1538397491), -INT32_C(   755313134) },
          {  INT32_C(  1149696590), -INT32_C(   529281501),  INT32_C(   985389705),  INT32_C(  2056422755) } },
    },
    { { -INT32_C(   102147383), -INT32_C(    37560273), -INT32_C(   593424438),  INT32_C(   883858405), -INT32_C(  1183304554), -INT32_C(  1936069885),  INT32_C(   684086469), -INT32_C(  1566353191),
        -INT32_C(   493056846),  INT32_C(   920608364),  INT32_C(  1393786990), -INT32_C(  1316503269), -INT32_C(   110493450), -INT32_C(  1316682773),  INT32_C(   819546967),  INT32_C(  1439923363) },
        { { -INT32_C(   102147383), -INT32_C(    37560273), -INT32_C(   593424438),  INT32_C(   883858405) },
          { -INT32_C(  1183304554), -INT32_C(  1936069885),  INT32_C(   684086469), -INT32_C(  1566353191) },
          { -INT32_C(   493056846),  INT32_C(   920608364),  INT32_C(  1393786990), -INT32_C(  1316503269) },
          { -INT32_C(   110493450), -INT32_C(  1316682773),  INT32_C(   819546967),  INT32_C(  1439923363) } },
    },
    { {  INT32_C(  1949789960),  INT32_C(  1001068237), -INT32_C(  1299202410),  INT32_C(  1969428095),  INT32_C(    40816150),  INT32_C(   699659217), -INT32_C(   514225090),  INT32_C(   288828425),
         INT32_C(  1770417819),  INT32_C(   463745413),  INT32_C(  1858941935),  INT32_C(  1625567562), -INT32_C(   798862593), -INT32_C(  2064050874), -INT32_C(  1419357278),  INT32_C(   465345919) },
        { {  INT32_C(  1949789960),  INT32_C(  1001068237), -INT32_C(  1299202410),  INT32_C(  1969428095) },
          {  INT32_C(    40816150),  INT32_C(   699659217), -INT32_C(   514225090),  INT32_C(   288828425) },
          {  INT32_C(  1770417819),  INT32_C(   463745413),  INT32_C(  1858941935),  INT32_C(  1625567562) },
          { -INT32_C(   798862593), -INT32_C(  2064050874), -INT32_C(  1419357278),  INT32_C(   465345919) } },
    },
    { { -INT32_C(  1870380533),  INT32_C(  1655449715), -INT32_C(  1496221348), -INT32_C(  1459178070),  INT32_C(  1299867911),  INT32_C(   550663038),  INT32_C(  1187723462), -INT32_C(   530478891),
         INT32_C(  1047651786),  INT32_C(  1772100877),  INT32_C(  1091531158),  INT32_C(   787093030), -INT32_C(    42244993), -INT32_C(  1642181160),  INT32_C(  1524951429),  INT32_C(  1010517361) },
        { { -INT32_C(  1870380533),  INT32_C(  1655449715), -INT32_C(  1496221348), -INT32_C(  1459178070) },
          {  INT32_C(  1299867911),  INT32_C(   550663038),  INT32_C(  1187723462), -INT32_C(   530478891) },
          {  INT32_C(  1047651786),  INT32_C(  1772100877),  INT32_C(  1091531158),  INT32_C(   787093030) },
          { -INT32_C(    42244993), -INT32_C(  1642181160),  INT32_C(  1524951429),  INT32_C(  1010517361) } },
    },
    { {  INT32_C(   947563562),  INT32_C(  1604393673), -INT32_C(  1298091636),  INT32_C(  1189120967), -INT32_C(   951886609),  INT32_C(   795238825), -INT32_C(  1131853237), -INT32_C(  1158101872),
         INT32_C(   972190320),  INT32_C(   429495437),  INT32_C(   214645061), -INT32_C(  1269650236), -INT32_C(  1317300984),  INT32_C(  1122034167), -INT32_C(  1124177364), -INT32_C(  1619593426) },
        { {  INT32_C(   947563562),  INT32_C(  1604393673), -INT32_C(  1298091636),  INT32_C(  1189120967) },
          { -INT32_C(   951886609),  INT32_C(   795238825), -INT32_C(  1131853237), -INT32_C(  1158101872) },
          {  INT32_C(   972190320),  INT32_C(   429495437),  INT32_C(   214645061), -INT32_C(  1269650236) },
          { -INT32_C(  1317300984),  INT32_C(  1122034167), -INT32_C(  1124177364), -INT32_C(  1619593426) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4x4_t r = simde_vld1q_s32_x4(test_vec[i].buf);
    simde_int32x4x4_t expected = {{
        simde_vld1q_s32(test_vec[i].expected[0]),
        simde_vld1q_s32(test_vec[i].expected[1]),
        simde_vld1q_s32(test_vec[i].expected[2]),
        simde_vld1q_s32(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_i32x4x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int32_t buf[16];
    simde_test_codegen_random_memory(64, (uint8_t*)buf);
    simde_test_codegen_write_vi32(2, 16, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int32x4x4_t val = simde_vld1q_s32_x4(buf);
    simde_test_arm_neon_write_i32x4x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t buf[8];
    int64_t expected[4][2];
  } test_vec[] = {
    { {  INT64_C( 4760148666735946089), -INT64_C( 8132479998552515669), -INT64_C( 6021838817365811403), -INT64_C( 3649921874283434613),
         INT64_C( 5586666556685037896), -INT64_C( 6141537197809085010), -INT64_C( 5644060203476908673),  INT64_C( 4387847390081193394) },
        { {  INT64_C( 4760148666735946089), -INT64_C( 8132479998552515669) },
          { -INT64_C( 6021838817365811403), -INT64_C( 3649921874283434613) },
          { -INT64_C( 6021838817365811403), -INT64_C( 3649921874283434613) },
          { -INT64_C( 6021838817365811403), -INT64_C( 3649921874283434613) } },
    },
    { {  INT64_C( 3090604571182082292),  INT64_C(  143029426020393437), -INT64_C( 3818862159798873303),  INT64_C( 2446235447259720386),
         INT64_C( 6346588355911250798), -INT64_C( 4557740027694910659),  INT64_C( 3485521604196155514),  INT64_C( 8487272124684648825) },
        { {  INT64_C( 3090604571182082292),  INT64_C(  143029426020393437) },
          { -INT64_C( 3818862159798873303),  INT64_C( 2446235447259720386) },
          { -INT64_C( 3818862159798873303),  INT64_C( 2446235447259720386) },
          { -INT64_C( 3818862159798873303),  INT64_C( 2446235447259720386) } },
    },
    { {  INT64_C( 6422540011553325133), -INT64_C( 1351968901409747995), -INT64_C( 3227146505215259752),  INT64_C( 4943901219744259360),
         INT64_C( 5924816734716230595), -INT64_C( 4514847453420301831), -INT64_C( 2773375450841884331),  INT64_C(  240552528616422683) },
        { {  INT64_C( 6422540011553325133), -INT64_C( 1351968901409747995) },
          { -INT64_C( 3227146505215259752),  INT64_C( 4943901219744259360) },
          { -INT64_C( 3227146505215259752),  INT64_C( 4943901219744259360) },
          { -INT64_C( 3227146505215259752),  INT64_C( 4943901219744259360) } },
    },
    { { -INT64_C( 8550332863128313192), -INT64_C( 8910286995944364690),  INT64_C( 4086934326748585766), -INT64_C( 1299675151452161870),
         INT64_C( 7285498145578080514), -INT64_C( 8997816719938678674), -INT64_C( 4843312395375782796), -INT64_C( 5326732844894121007) },
        { { -INT64_C( 8550332863128313192), -INT64_C( 8910286995944364690) },
          {  INT64_C( 4086934326748585766), -INT64_C( 1299675151452161870) },
          {  INT64_C( 4086934326748585766), -INT64_C( 1299675151452161870) },
          {  INT64_C( 4086934326748585766), -INT64_C( 1299675151452161870) } },
    },
    { { -INT64_C( 4838726036511783554), -INT64_C( 6965808395020806540), -INT64_C( 6947934033821977138),  INT64_C( 7239493411626369550),
        -INT64_C( 7428773191900086051), -INT64_C( 8623340251912781688), -INT64_C( 8295362790028180366),  INT64_C( 6665544593939801653) },
        { { -INT64_C( 4838726036511783554), -INT64_C( 6965808395020806540) },
          { -INT64_C( 6947934033821977138),  INT64_C( 7239493411626369550) },
          { -INT64_C( 6947934033821977138),  INT64_C( 7239493411626369550) },
          { -INT64_C( 6947934033821977138),  INT64_C( 7239493411626369550) } },
    },
    { { -INT64_C( 7763802182435513979), -INT64_C( 2669900760610198865),  INT64_C( 8875182296389079583), -INT64_C( 4360583688382613343),
         INT64_C( 2455216553624077169),  INT64_C( 1484638621134510680),  INT64_C( 5950059607068095953), -INT64_C( 5524528873201325485) },
        { { -INT64_C( 7763802182435513979), -INT64_C( 2669900760610198865) },
          {  INT64_C( 8875182296389079583), -INT64_C( 4360583688382613343) },
          {  INT64_C( 8875182296389079583), -INT64_C( 4360583688382613343) },
          {  INT64_C( 8875182296389079583), -INT64_C( 4360583688382613343) } },
    },
    { { -INT64_C( 4069491071876218639),  INT64_C( 7036348372630311581), -INT64_C( 8730215561730435114),  INT64_C( 3038358788875176501),
         INT64_C( 4278723792409090860), -INT64_C( 2371018718251718618), -INT64_C( 3421540977185746741),  INT64_C( 3741209293094362249) },
        { { -INT64_C( 4069491071876218639),  INT64_C( 7036348372630311581) },
          { -INT64_C( 8730215561730435114),  INT64_C( 3038358788875176501) },
          { -INT64_C( 8730215561730435114),  INT64_C( 3038358788875176501) },
          { -INT64_C( 8730215561730435114),  INT64_C( 3038358788875176501) } },
    },
    { { -INT64_C( 5501376135347406387), -INT64_C( 5548009332439091944),  INT64_C( 3350175258038593298),  INT64_C(  364188182107965138),
         INT64_C( 2492206978335628117), -INT64_C( 7770321780442136434), -INT64_C( 2053429149959005268), -INT64_C( 6862137505517571961) },
        { { -INT64_C( 5501376135347406387), -INT64_C( 5548009332439091944) },
          {  INT64_C( 3350175258038593298),  INT64_C(  364188182107965138) },
          {  INT64_C( 3350175258038593298),  INT64_C(  364188182107965138) },
          {  INT64_C( 3350175258038593298),  INT64_C(  364188182107965138) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x2x4_t r = simde_vld1q_s64_x4(test_vec[i].buf);
    simde_int64x2x4_t expected = {{
        simde_vld1q_s64(test_vec[i].expected[0]),
        simde_vld1q_s64(test_vec[i].expected[1]),
        simde_vld1q_s64(test_vec[i].expected[2]),
        simde_vld1q_s64(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_i64x2x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int64_t buf[8];
    simde_test_codegen_random_memory(64, (uint8_t*)buf);
    simde_test_codegen_write_vi64(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int64x2x4_t val = simde_vld1q_s64_x4(buf);
    simde_test_arm_neon_write_i64x2x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u8_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t buf[64];
    uint8_t expected[4][16];
  } test_vec[] = {
    { { UINT8_C(171), UINT8_C(209), UINT8_C(190), UINT8_C( 65), UINT8_C(254), UINT8_C(218), UINT8_C( 87), UINT8_C( 32),
        UINT8_C(205), UINT8_C( 84), UINT8_C(251), UINT8_C(248), UINT8_C(172), UINT8_C(241), UINT8_C(178), UINT8_C( 28),
        UINT8_C(150), UINT8_C( 98), UINT8_C(162), UINT8_C(108), UINT8_C( 28), UINT8_C(224), UINT8_C( 62), UINT8_C( 82),
        UINT8_C( 92), UINT8_C(  1), UINT8_C(171), UINT8_C(142), UINT8_C( 99), UINT8_C(117), UINT8_C( 52), UINT8_C( 15),
        UINT8_C( 70), UINT8_C(242), UINT8_C( 80), UINT8_C( 68), UINT8_C(204), UINT8_C(167), UINT8_C(100), UINT8_C(154),
        UINT8_C(251), UINT8_C( 95), UINT8_C(146), UINT8_C(167), UINT8_C( 81), UINT8_C( 69), UINT8_C(196), UINT8_C(231),
        UINT8_C(167), UINT8_C(102), UINT8_C( 83), UINT8_C(196), UINT8_C( 70), UINT8_C(145), UINT8_C( 22), UINT8_C(163),
        UINT8_C(146), UINT8_C(193), UINT8_C( 49), UINT8_C(246), UINT8_C( 54), UINT8_C(101), UINT8_C(  5), UINT8_C(125) },
        { { UINT8_C(171), UINT8_C(209), UINT8_C(190), UINT8_C( 65), UINT8_C(254), UINT8_C(218), UINT8_C( 87), UINT8_C( 32),
            UINT8_C(205), UINT8_C( 84), UINT8_C(251), UINT8_C(248), UINT8_C(172), UINT8_C(241), UINT8_C(178), UINT8_C( 28) },
          { UINT8_C(150), UINT8_C( 98), UINT8_C(162), UINT8_C(108), UINT8_C( 28), UINT8_C(224), UINT8_C( 62), UINT8_C( 82),
            UINT8_C( 92), UINT8_C(  1), UINT8_C(171), UINT8_C(142), UINT8_C( 99), UINT8_C(117), UINT8_C( 52), UINT8_C( 15) },
          { UINT8_C( 70), UINT8_C(242), UINT8_C( 80), UINT8_C( 68), UINT8_C(204), UINT8_C(167), UINT8_C(100), UINT8_C(154),
            UINT8_C(251), UINT8_C( 95), UINT8_C(146), UINT8_C(167), UINT8_C( 81), UINT8_C( 69), UINT8_C(196), UINT8_C(231) },
          { UINT8_C(167), UINT8_C(102), UINT8_C( 83), UINT8_C(196), UINT8_C( 70), UINT8_C(145), UINT8_C( 22), UINT8_C(163),
            UINT8_C(146), UINT8_C(193), UINT8_C( 49), UINT8_C(246), UINT8_C( 54), UINT8_C(101), UINT8_C(  5), UINT8_C(125) } },
    },
    { { UINT8_C( 87), UINT8_C( 85), UINT8_C(193), UINT8_C( 36), UINT8_C(252), UINT8_C( 38), UINT8_C(190), UINT8_C(247),
        UINT8_C(133), UINT8_C( 80), UINT8_C(158), UINT8_C(214), UINT8_C(149), UINT8_C( 98), UINT8_C(189), UINT8_C( 61),
        UINT8_C(200), UINT8_C( 17), UINT8_C(  1), UINT8_C( 15), UINT8_C(162), UINT8_C( 23), UINT8_C(178), UINT8_C( 53),
        UINT8_C(216), UINT8_C(227), UINT8_C( 43), UINT8_C( 14), UINT8_C( 72), UINT8_C( 48), UINT8_C(139), UINT8_C(159),
        UINT8_C(133), UINT8_C( 77), UINT8_C(195), UINT8_C(129), UINT8_C(115), UINT8_C(129), UINT8_C(120), UINT8_C(248),
        UINT8_C(210), UINT8_C( 22), UINT8_C(207), UINT8_C(103), UINT8_C(121), UINT8_C(140), UINT8_C(164), UINT8_C( 65),
        UINT8_C(157), UINT8_C(165), UINT8_C( 80), UINT8_C( 64), UINT8_C(188), UINT8_C(  2), UINT8_C(117), UINT8_C(148),
        UINT8_C(229), UINT8_C(160), UINT8_C(163), UINT8_C( 45), UINT8_C(208), UINT8_C( 46), UINT8_C(205), UINT8_C( 85) },
        { { UINT8_C( 87), UINT8_C( 85), UINT8_C(193), UINT8_C( 36), UINT8_C(252), UINT8_C( 38), UINT8_C(190), UINT8_C(247),
            UINT8_C(133), UINT8_C( 80), UINT8_C(158), UINT8_C(214), UINT8_C(149), UINT8_C( 98), UINT8_C(189), UINT8_C( 61) },
          { UINT8_C(200), UINT8_C( 17), UINT8_C(  1), UINT8_C( 15), UINT8_C(162), UINT8_C( 23), UINT8_C(178), UINT8_C( 53),
            UINT8_C(216), UINT8_C(227), UINT8_C( 43), UINT8_C( 14), UINT8_C( 72), UINT8_C( 48), UINT8_C(139), UINT8_C(159) },
          { UINT8_C(133), UINT8_C( 77), UINT8_C(195), UINT8_C(129), UINT8_C(115), UINT8_C(129), UINT8_C(120), UINT8_C(248),
            UINT8_C(210), UINT8_C( 22), UINT8_C(207), UINT8_C(103), UINT8_C(121), UINT8_C(140), UINT8_C(164), UINT8_C( 65) },
          { UINT8_C(157), UINT8_C(165), UINT8_C( 80), UINT8_C( 64), UINT8_C(188), UINT8_C(  2), UINT8_C(117), UINT8_C(148),
            UINT8_C(229), UINT8_C(160), UINT8_C(163), UINT8_C( 45), UINT8_C(208), UINT8_C( 46), UINT8_C(205), UINT8_C( 85) } },
    },
    { { UINT8_C(123), UINT8_C(144), UINT8_C(214), UINT8_C(238), UINT8_C( 18), UINT8_C( 78), UINT8_C(231), UINT8_C(228),
        UINT8_C(100), UINT8_C(182), UINT8_C( 75), UINT8_C(221), UINT8_C( 66), UINT8_C(240), UINT8_C( 31), UINT8_C(224),
        UINT8_C(149), UINT8_C(111), UINT8_C( 32), UINT8_C( 82), UINT8_C(114), UINT8_C(149), UINT8_C(230), UINT8_C( 87),
        UINT8_C( 53), UINT8_C(137), UINT8_C(133), UINT8_C(  5), UINT8_C(184), UINT8_C( 82), UINT8_C( 90), UINT8_C( 51),
        UINT8_C(226), UINT8_C( 48), UINT8_C( 34), UINT8_C(244), UINT8_C(126), UINT8_C(  9), UINT8_C(216), UINT8_C(226),
        UINT8_C(191), UINT8_C( 36), UINT8_C(192), UINT8_C(  1), UINT8_C( 20), UINT8_C(223), UINT8_C(225), UINT8_C(169),
        UINT8_C( 78), UINT8_C(  1), UINT8_C(251), UINT8_C(192), UINT8_C(150), UINT8_C(226), UINT8_C( 24), UINT8_C(203),
        UINT8_C(107), UINT8_C(157), UINT8_C(208), UINT8_C( 35), UINT8_C(239), UINT8_C( 42), UINT8_C( 87), UINT8_C(209) },
        { { UINT8_C(123), UINT8_C(144), UINT8_C(214), UINT8_C(238), UINT8_C( 18), UINT8_C( 78), UINT8_C(231), UINT8_C(228),
            UINT8_C(100), UINT8_C(182), UINT8_C( 75), UINT8_C(221), UINT8_C( 66), UINT8_C(240), UINT8_C( 31), UINT8_C(224) },
          { UINT8_C(149), UINT8_C(111), UINT8_C( 32), UINT8_C( 82), UINT8_C(114), UINT8_C(149), UINT8_C(230), UINT8_C( 87),
            UINT8_C( 53), UINT8_C(137), UINT8_C(133), UINT8_C(  5), UINT8_C(184), UINT8_C( 82), UINT8_C( 90), UINT8_C( 51) },
          { UINT8_C(226), UINT8_C( 48), UINT8_C( 34), UINT8_C(244), UINT8_C(126), UINT8_C(  9), UINT8_C(216), UINT8_C(226),
            UINT8_C(191), UINT8_C( 36), UINT8_C(192), UINT8_C(  1), UINT8_C( 20), UINT8_C(223), UINT8_C(225), UINT8_C(169) },
          { UINT8_C( 78), UINT8_C(  1), UINT8_C(251), UINT8_C(192), UINT8_C(150), UINT8_C(226), UINT8_C( 24), UINT8_C(203),
            UINT8_C(107), UINT8_C(157), UINT8_C(208), UINT8_C( 35), UINT8_C(239), UINT8_C( 42), UINT8_C( 87), UINT8_C(209) } },
    },
    { { UINT8_C( 90), UINT8_C(121), UINT8_C(198), UINT8_C(216), UINT8_C(130), UINT8_C(158), UINT8_C(187), UINT8_C( 65),
        UINT8_C(194), UINT8_C(123), UINT8_C( 66), UINT8_C(214), UINT8_C( 90), UINT8_C( 36), UINT8_C(128), UINT8_C(168),
        UINT8_C( 37), UINT8_C(123), UINT8_C(105), UINT8_C(188), UINT8_C( 93), UINT8_C(129), UINT8_C(135), UINT8_C(201),
        UINT8_C( 30), UINT8_C( 88), UINT8_C(236), UINT8_C( 13), UINT8_C(130), UINT8_C( 67), UINT8_C(222), UINT8_C(221),
        UINT8_C(188), UINT8_C(164), UINT8_C(181), UINT8_C( 62), UINT8_C( 67), UINT8_C(112), UINT8_C(127), UINT8_C(  5),
        UINT8_C(235), UINT8_C(194), UINT8_C(220), UINT8_C( 69), UINT8_C(230), UINT8_C( 92), UINT8_C(238), UINT8_C( 11),
        UINT8_C(215), UINT8_C( 87), UINT8_C(199), UINT8_C( 53), UINT8_C(216), UINT8_C( 79), UINT8_C(254), UINT8_C(246),
        UINT8_C(167), UINT8_C(234), UINT8_C(  3), UINT8_C( 41), UINT8_C( 46), UINT8_C(225), UINT8_C(  6), UINT8_C(234) },
        { { UINT8_C( 90), UINT8_C(121), UINT8_C(198), UINT8_C(216), UINT8_C(130), UINT8_C(158), UINT8_C(187), UINT8_C( 65),
            UINT8_C(194), UINT8_C(123), UINT8_C( 66), UINT8_C(214), UINT8_C( 90), UINT8_C( 36), UINT8_C(128), UINT8_C(168) },
          { UINT8_C( 37), UINT8_C(123), UINT8_C(105), UINT8_C(188), UINT8_C( 93), UINT8_C(129), UINT8_C(135), UINT8_C(201),
            UINT8_C( 30), UINT8_C( 88), UINT8_C(236), UINT8_C( 13), UINT8_C(130), UINT8_C( 67), UINT8_C(222), UINT8_C(221) },
          { UINT8_C(188), UINT8_C(164), UINT8_C(181), UINT8_C( 62), UINT8_C( 67), UINT8_C(112), UINT8_C(127), UINT8_C(  5),
            UINT8_C(235), UINT8_C(194), UINT8_C(220), UINT8_C( 69), UINT8_C(230), UINT8_C( 92), UINT8_C(238), UINT8_C( 11) },
          { UINT8_C(215), UINT8_C( 87), UINT8_C(199), UINT8_C( 53), UINT8_C(216), UINT8_C( 79), UINT8_C(254), UINT8_C(246),
            UINT8_C(167), UINT8_C(234), UINT8_C(  3), UINT8_C( 41), UINT8_C( 46), UINT8_C(225), UINT8_C(  6), UINT8_C(234) } },
    },
    { { UINT8_C(134), UINT8_C(188), UINT8_C( 41), UINT8_C(201), UINT8_C( 44), UINT8_C(168), UINT8_C(206), UINT8_C( 24),
        UINT8_C(106), UINT8_C(170), UINT8_C( 93), UINT8_C( 80), UINT8_C(  6), UINT8_C( 75), UINT8_C( 92), UINT8_C(222),
        UINT8_C(162), UINT8_C( 35), UINT8_C( 19), UINT8_C(122), UINT8_C(114), UINT8_C( 17), UINT8_C(112), UINT8_C( 25),
        UINT8_C(251), UINT8_C(115), UINT8_C( 67), UINT8_C( 41), UINT8_C( 85), UINT8_C( 73), UINT8_C( 20), UINT8_C(219),
        UINT8_C(  5), UINT8_C( 61), UINT8_C(164), UINT8_C( 50), UINT8_C(229), UINT8_C(114), UINT8_C( 74), UINT8_C( 80),
        UINT8_C( 29), UINT8_C(167), UINT8_C(160), UINT8_C( 35), UINT8_C(243), UINT8_C(252), UINT8_C(  1), UINT8_C(149),
        UINT8_C( 32), UINT8_C( 20), UINT8_C( 16), UINT8_C(146), UINT8_C( 37), UINT8_C(128), UINT8_C(172), UINT8_C( 33),
        UINT8_C(244), UINT8_C(239), UINT8_C( 74), UINT8_C( 73), UINT8_C( 56), UINT8_C( 94), UINT8_C( 36), UINT8_C( 62) },
        { { UINT8_C(134), UINT8_C(188), UINT8_C( 41), UINT8_C(201), UINT8_C( 44), UINT8_C(168), UINT8_C(206), UINT8_C( 24),
            UINT8_C(106), UINT8_C(170), UINT8_C( 93), UINT8_C( 80), UINT8_C(  6), UINT8_C( 75), UINT8_C( 92), UINT8_C(222) },
          { UINT8_C(162), UINT8_C( 35), UINT8_C( 19), UINT8_C(122), UINT8_C(114), UINT8_C( 17), UINT8_C(112), UINT8_C( 25),
            UINT8_C(251), UINT8_C(115), UINT8_C( 67), UINT8_C( 41), UINT8_C( 85), UINT8_C( 73), UINT8_C( 20), UINT8_C(219) },
          { UINT8_C(  5), UINT8_C( 61), UINT8_C(164), UINT8_C( 50), UINT8_C(229), UINT8_C(114), UINT8_C( 74), UINT8_C( 80),
            UINT8_C( 29), UINT8_C(167), UINT8_C(160), UINT8_C( 35), UINT8_C(243), UINT8_C(252), UINT8_C(  1), UINT8_C(149) },
          { UINT8_C( 32), UINT8_C( 20), UINT8_C( 16), UINT8_C(146), UINT8_C( 37), UINT8_C(128), UINT8_C(172), UINT8_C( 33),
            UINT8_C(244), UINT8_C(239), UINT8_C( 74), UINT8_C( 73), UINT8_C( 56), UINT8_C( 94), UINT8_C( 36), UINT8_C( 62) } },
    },
    { { UINT8_C(155), UINT8_C(200), UINT8_C(112), UINT8_C(129), UINT8_C( 58), UINT8_C(186), UINT8_C(209), UINT8_C( 87),
        UINT8_C( 97), UINT8_C(113), UINT8_C(123), UINT8_C( 84), UINT8_C(110), UINT8_C(124), UINT8_C(234), UINT8_C(142),
        UINT8_C(145), UINT8_C(250), UINT8_C( 32), UINT8_C(182), UINT8_C(122), UINT8_C(204), UINT8_C(215), UINT8_C(110),
        UINT8_C(187), UINT8_C( 34), UINT8_C(183), UINT8_C(244), UINT8_C(128), UINT8_C(219), UINT8_C( 50), UINT8_C( 28),
        UINT8_C(163), UINT8_C(162), UINT8_C(157), UINT8_C(222), UINT8_C( 92), UINT8_C(110), UINT8_C( 53), UINT8_C(189),
        UINT8_C(223), UINT8_C(176), UINT8_C( 18), UINT8_C( 77), UINT8_C( 45), UINT8_C(252), UINT8_C(219), UINT8_C(190),
        UINT8_C(246), UINT8_C(252), UINT8_C(116), UINT8_C(112), UINT8_C(200), UINT8_C( 76), UINT8_C(223), UINT8_C(132),
        UINT8_C(110), UINT8_C(150), UINT8_C(120), UINT8_C(238), UINT8_C(114), UINT8_C(170), UINT8_C( 10), UINT8_C( 21) },
        { { UINT8_C(155), UINT8_C(200), UINT8_C(112), UINT8_C(129), UINT8_C( 58), UINT8_C(186), UINT8_C(209), UINT8_C( 87),
            UINT8_C( 97), UINT8_C(113), UINT8_C(123), UINT8_C( 84), UINT8_C(110), UINT8_C(124), UINT8_C(234), UINT8_C(142) },
          { UINT8_C(145), UINT8_C(250), UINT8_C( 32), UINT8_C(182), UINT8_C(122), UINT8_C(204), UINT8_C(215), UINT8_C(110),
            UINT8_C(187), UINT8_C( 34), UINT8_C(183), UINT8_C(244), UINT8_C(128), UINT8_C(219), UINT8_C( 50), UINT8_C( 28) },
          { UINT8_C(163), UINT8_C(162), UINT8_C(157), UINT8_C(222), UINT8_C( 92), UINT8_C(110), UINT8_C( 53), UINT8_C(189),
            UINT8_C(223), UINT8_C(176), UINT8_C( 18), UINT8_C( 77), UINT8_C( 45), UINT8_C(252), UINT8_C(219), UINT8_C(190) },
          { UINT8_C(246), UINT8_C(252), UINT8_C(116), UINT8_C(112), UINT8_C(200), UINT8_C( 76), UINT8_C(223), UINT8_C(132),
            UINT8_C(110), UINT8_C(150), UINT8_C(120), UINT8_C(238), UINT8_C(114), UINT8_C(170), UINT8_C( 10), UINT8_C( 21) } },
    },
    { { UINT8_C( 76), UINT8_C(167), UINT8_C(243), UINT8_C(168), UINT8_C( 21), UINT8_C( 41), UINT8_C(101), UINT8_C(245),
        UINT8_C(217), UINT8_C(119), UINT8_C( 66), UINT8_C(  6), UINT8_C(115), UINT8_C( 30), UINT8_C(196), UINT8_C(105),
        UINT8_C( 26), UINT8_C( 57), UINT8_C(218), UINT8_C(226), UINT8_C(133), UINT8_C(185), UINT8_C(102), UINT8_C(243),
        UINT8_C( 79), UINT8_C(222), UINT8_C(225), UINT8_C(193), UINT8_C(136), UINT8_C(236), UINT8_C(215), UINT8_C(212),
        UINT8_C(147), UINT8_C(202), UINT8_C(124), UINT8_C(169), UINT8_C(243), UINT8_C(226), UINT8_C(158), UINT8_C(205),
        UINT8_C( 89), UINT8_C(224), UINT8_C(211), UINT8_C(205), UINT8_C(254), UINT8_C(152), UINT8_C( 54), UINT8_C( 24),
        UINT8_C(209), UINT8_C( 16), UINT8_C(251), UINT8_C( 86), UINT8_C(201), UINT8_C( 97), UINT8_C( 73), UINT8_C( 25),
        UINT8_C( 64), UINT8_C( 42), UINT8_C(218), UINT8_C(200), UINT8_C( 22), UINT8_C(177), UINT8_C(157), UINT8_C(170) },
        { { UINT8_C( 76), UINT8_C(167), UINT8_C(243), UINT8_C(168), UINT8_C( 21), UINT8_C( 41), UINT8_C(101), UINT8_C(245),
            UINT8_C(217), UINT8_C(119), UINT8_C( 66), UINT8_C(  6), UINT8_C(115), UINT8_C( 30), UINT8_C(196), UINT8_C(105) },
          { UINT8_C( 26), UINT8_C( 57), UINT8_C(218), UINT8_C(226), UINT8_C(133), UINT8_C(185), UINT8_C(102), UINT8_C(243),
            UINT8_C( 79), UINT8_C(222), UINT8_C(225), UINT8_C(193), UINT8_C(136), UINT8_C(236), UINT8_C(215), UINT8_C(212) },
          { UINT8_C(147), UINT8_C(202), UINT8_C(124), UINT8_C(169), UINT8_C(243), UINT8_C(226), UINT8_C(158), UINT8_C(205),
            UINT8_C( 89), UINT8_C(224), UINT8_C(211), UINT8_C(205), UINT8_C(254), UINT8_C(152), UINT8_C( 54), UINT8_C( 24) },
          { UINT8_C(209), UINT8_C( 16), UINT8_C(251), UINT8_C( 86), UINT8_C(201), UINT8_C( 97), UINT8_C( 73), UINT8_C( 25),
            UINT8_C( 64), UINT8_C( 42), UINT8_C(218), UINT8_C(200), UINT8_C( 22), UINT8_C(177), UINT8_C(157), UINT8_C(170) } },
    },
    { { UINT8_C(124), UINT8_C( 25), UINT8_C( 83), UINT8_C(111), UINT8_C(251), UINT8_C(241), UINT8_C( 60), UINT8_C( 85),
        UINT8_C(209), UINT8_C( 16), UINT8_C( 34), UINT8_C(208), UINT8_C(168), UINT8_C( 88), UINT8_C(232), UINT8_C(121),
        UINT8_C(105), UINT8_C(227), UINT8_C(207), UINT8_C( 50), UINT8_C( 69), UINT8_C( 24), UINT8_C( 75), UINT8_C(133),
        UINT8_C( 66), UINT8_C( 38), UINT8_C( 77), UINT8_C( 89), UINT8_C(215), UINT8_C(234), UINT8_C(  3), UINT8_C( 83),
        UINT8_C(  4), UINT8_C( 86), UINT8_C(195),    UINT8_MAX, UINT8_C( 71),    UINT8_MAX, UINT8_C( 84), UINT8_C( 24),
        UINT8_C( 15), UINT8_C(118), UINT8_C(232), UINT8_C(183), UINT8_C(207), UINT8_C(209), UINT8_C( 48), UINT8_C( 56),
        UINT8_C(180),    UINT8_MAX, UINT8_C(106), UINT8_C(249), UINT8_C( 23), UINT8_C(182), UINT8_C(126), UINT8_C( 90),
        UINT8_C(220), UINT8_C(204), UINT8_C(179), UINT8_C(179), UINT8_C(182), UINT8_C(182), UINT8_C(  7), UINT8_C(186) },
        { { UINT8_C(124), UINT8_C( 25), UINT8_C( 83), UINT8_C(111), UINT8_C(251), UINT8_C(241), UINT8_C( 60), UINT8_C( 85),
            UINT8_C(209), UINT8_C( 16), UINT8_C( 34), UINT8_C(208), UINT8_C(168), UINT8_C( 88), UINT8_C(232), UINT8_C(121) },
          { UINT8_C(105), UINT8_C(227), UINT8_C(207), UINT8_C( 50), UINT8_C( 69), UINT8_C( 24), UINT8_C( 75), UINT8_C(133),
            UINT8_C( 66), UINT8_C( 38), UINT8_C( 77), UINT8_C( 89), UINT8_C(215), UINT8_C(234), UINT8_C(  3), UINT8_C( 83) },
          { UINT8_C(  4), UINT8_C( 86), UINT8_C(195),    UINT8_MAX, UINT8_C( 71),    UINT8_MAX, UINT8_C( 84), UINT8_C( 24),
            UINT8_C( 15), UINT8_C(118), UINT8_C(232), UINT8_C(183), UINT8_C(207), UINT8_C(209), UINT8_C( 48), UINT8_C( 56) },
          { UINT8_C(180),    UINT8_MAX, UINT8_C(106), UINT8_C(249), UINT8_C( 23), UINT8_C(182), UINT8_C(126), UINT8_C( 90),
            UINT8_C(220), UINT8_C(204), UINT8_C(179), UINT8_C(179), UINT8_C(182), UINT8_C(182), UINT8_C(  7), UINT8_C(186) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16x4_t r = simde_vld1q_u8_x4(test_vec[i].buf);
    simde_uint8x16x4_t expected = {{
        simde_vld1q_u8(test_vec[i].expected[0]),
        simde_vld1q_u8(test_vec[i].expected[1]),
        simde_vld1q_u8(test_vec[i].expected[2]),
        simde_vld1q_u8(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_u8x16x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t buf[64];
    simde_test_codegen_random_memory(64, buf);
    simde_test_codegen_write_vu8(2, 64, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint8x16x4_t val = simde_vld1q_u8_x4(buf);
    simde_test_arm_neon_write_u8x16x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u16_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t buf[32];
    uint16_t expected[4][8];
  } test_vec[] = {
    { { UINT16_C(51820), UINT16_C(23341), UINT16_C(11327), UINT16_C(36350), UINT16_C(24752), UINT16_C(52077), UINT16_C(30465), UINT16_C(28627),
        UINT16_C(34772), UINT16_C(60098), UINT16_C( 5519), UINT16_C(45826), UINT16_C(57681), UINT16_C(58786), UINT16_C(41520), UINT16_C(39937),
        UINT16_C(11885), UINT16_C(44279), UINT16_C(63066), UINT16_C( 2873), UINT16_C(42582), UINT16_C(22486), UINT16_C(43549), UINT16_C(61894),
        UINT16_C(35121), UINT16_C(49627), UINT16_C(56734), UINT16_C(61300), UINT16_C( 6078), UINT16_C(61397), UINT16_C(54969), UINT16_C( 9867) },
        { { UINT16_C(51820), UINT16_C(23341), UINT16_C(11327), UINT16_C(36350), UINT16_C(24752), UINT16_C(52077), UINT16_C(30465), UINT16_C(28627) },
          { UINT16_C(34772), UINT16_C(60098), UINT16_C( 5519), UINT16_C(45826), UINT16_C(57681), UINT16_C(58786), UINT16_C(41520), UINT16_C(39937) },
          { UINT16_C(11885), UINT16_C(44279), UINT16_C(63066), UINT16_C( 2873), UINT16_C(42582), UINT16_C(22486), UINT16_C(43549), UINT16_C(61894) },
          { UINT16_C(35121), UINT16_C(49627), UINT16_C(56734), UINT16_C(61300), UINT16_C( 6078), UINT16_C(61397), UINT16_C(54969), UINT16_C( 9867) } },
    },
    { { UINT16_C(33540), UINT16_C(24274), UINT16_C( 2937), UINT16_C(53097), UINT16_C(16561), UINT16_C(52774), UINT16_C(60906), UINT16_C( 7103),
        UINT16_C(39542), UINT16_C( 5340), UINT16_C(20856), UINT16_C(13828), UINT16_C(55656), UINT16_C( 8485), UINT16_C(45487), UINT16_C(45896),
        UINT16_C( 6708), UINT16_C(44305), UINT16_C(31526), UINT16_C(55164), UINT16_C(41659), UINT16_C(42406), UINT16_C(25999), UINT16_C( 1472),
        UINT16_C(40192), UINT16_C(30746), UINT16_C( 7918), UINT16_C(22190), UINT16_C(54519), UINT16_C(42615), UINT16_C(49029), UINT16_C(47449) },
        { { UINT16_C(33540), UINT16_C(24274), UINT16_C( 2937), UINT16_C(53097), UINT16_C(16561), UINT16_C(52774), UINT16_C(60906), UINT16_C( 7103) },
          { UINT16_C(39542), UINT16_C( 5340), UINT16_C(20856), UINT16_C(13828), UINT16_C(55656), UINT16_C( 8485), UINT16_C(45487), UINT16_C(45896) },
          { UINT16_C( 6708), UINT16_C(44305), UINT16_C(31526), UINT16_C(55164), UINT16_C(41659), UINT16_C(42406), UINT16_C(25999), UINT16_C( 1472) },
          { UINT16_C(40192), UINT16_C(30746), UINT16_C( 7918), UINT16_C(22190), UINT16_C(54519), UINT16_C(42615), UINT16_C(49029), UINT16_C(47449) } },
    },
    { { UINT16_C(27354), UINT16_C(  102), UINT16_C(58085), UINT16_C(41175), UINT16_C(32132), UINT16_C( 5189), UINT16_C( 1763), UINT16_C(58137),
        UINT16_C(13219), UINT16_C(37211), UINT16_C( 2385), UINT16_C(18663), UINT16_C(24285), UINT16_C(25326), UINT16_C(18206), UINT16_C(63515),
        UINT16_C(33202), UINT16_C(38904), UINT16_C(53091), UINT16_C(59448), UINT16_C(32077), UINT16_C(12540), UINT16_C( 5507), UINT16_C( 9747),
        UINT16_C(28233), UINT16_C(39607), UINT16_C(40567), UINT16_C(21987), UINT16_C(53757), UINT16_C( 7095), UINT16_C(54041), UINT16_C(51987) },
        { { UINT16_C(27354), UINT16_C(  102), UINT16_C(58085), UINT16_C(41175), UINT16_C(32132), UINT16_C( 5189), UINT16_C( 1763), UINT16_C(58137) },
          { UINT16_C(13219), UINT16_C(37211), UINT16_C( 2385), UINT16_C(18663), UINT16_C(24285), UINT16_C(25326), UINT16_C(18206), UINT16_C(63515) },
          { UINT16_C(33202), UINT16_C(38904), UINT16_C(53091), UINT16_C(59448), UINT16_C(32077), UINT16_C(12540), UINT16_C( 5507), UINT16_C( 9747) },
          { UINT16_C(28233), UINT16_C(39607), UINT16_C(40567), UINT16_C(21987), UINT16_C(53757), UINT16_C( 7095), UINT16_C(54041), UINT16_C(51987) } },
    },
    { { UINT16_C( 2900), UINT16_C(47202), UINT16_C(39642), UINT16_C(10144), UINT16_C(39960), UINT16_C(39767), UINT16_C(27313), UINT16_C(64194),
        UINT16_C(31192), UINT16_C(20629), UINT16_C(30744), UINT16_C( 5541), UINT16_C(23625), UINT16_C(25136), UINT16_C(17199), UINT16_C(33837),
        UINT16_C(36942), UINT16_C(10300), UINT16_C(56362), UINT16_C(16976), UINT16_C(42872), UINT16_C(10718), UINT16_C(40978), UINT16_C(59940),
        UINT16_C(47385), UINT16_C(12602), UINT16_C(57137), UINT16_C(31302), UINT16_C(30268), UINT16_C(27613), UINT16_C( 2745), UINT16_C( 2031) },
        { { UINT16_C( 2900), UINT16_C(47202), UINT16_C(39642), UINT16_C(10144), UINT16_C(39960), UINT16_C(39767), UINT16_C(27313), UINT16_C(64194) },
          { UINT16_C(31192), UINT16_C(20629), UINT16_C(30744), UINT16_C( 5541), UINT16_C(23625), UINT16_C(25136), UINT16_C(17199), UINT16_C(33837) },
          { UINT16_C(36942), UINT16_C(10300), UINT16_C(56362), UINT16_C(16976), UINT16_C(42872), UINT16_C(10718), UINT16_C(40978), UINT16_C(59940) },
          { UINT16_C(47385), UINT16_C(12602), UINT16_C(57137), UINT16_C(31302), UINT16_C(30268), UINT16_C(27613), UINT16_C( 2745), UINT16_C( 2031) } },
    },
    { { UINT16_C(11162), UINT16_C(50480), UINT16_C(32775), UINT16_C(32519), UINT16_C(58663), UINT16_C(14761), UINT16_C(52613), UINT16_C(40740),
        UINT16_C(24198), UINT16_C(47056), UINT16_C( 5950), UINT16_C(31281), UINT16_C( 3725), UINT16_C(18405), UINT16_C(54553), UINT16_C(45902),
        UINT16_C(32256), UINT16_C( 2168), UINT16_C(33022), UINT16_C( 9863), UINT16_C(12389), UINT16_C(60255), UINT16_C(33789), UINT16_C(33674),
        UINT16_C(23266), UINT16_C( 8250), UINT16_C(27761), UINT16_C(65434), UINT16_C(32634), UINT16_C(37702), UINT16_C(37972), UINT16_C(21831) },
        { { UINT16_C(11162), UINT16_C(50480), UINT16_C(32775), UINT16_C(32519), UINT16_C(58663), UINT16_C(14761), UINT16_C(52613), UINT16_C(40740) },
          { UINT16_C(24198), UINT16_C(47056), UINT16_C( 5950), UINT16_C(31281), UINT16_C( 3725), UINT16_C(18405), UINT16_C(54553), UINT16_C(45902) },
          { UINT16_C(32256), UINT16_C( 2168), UINT16_C(33022), UINT16_C( 9863), UINT16_C(12389), UINT16_C(60255), UINT16_C(33789), UINT16_C(33674) },
          { UINT16_C(23266), UINT16_C( 8250), UINT16_C(27761), UINT16_C(65434), UINT16_C(32634), UINT16_C(37702), UINT16_C(37972), UINT16_C(21831) } },
    },
    { { UINT16_C(48915), UINT16_C( 4445), UINT16_C(58431), UINT16_C(42295), UINT16_C(38677), UINT16_C( 4752), UINT16_C( 6682), UINT16_C(64662),
        UINT16_C(53364), UINT16_C(58908), UINT16_C(46652), UINT16_C(47077), UINT16_C(11062), UINT16_C(35402), UINT16_C(37311), UINT16_C(53983),
        UINT16_C(15441), UINT16_C(37092), UINT16_C( 6945), UINT16_C(13877), UINT16_C(50610), UINT16_C(52552), UINT16_C(57055), UINT16_C(21705),
        UINT16_C(59055), UINT16_C(60218), UINT16_C( 8092), UINT16_C(53922), UINT16_C(60746), UINT16_C( 2397), UINT16_C(15486), UINT16_C(53212) },
        { { UINT16_C(48915), UINT16_C( 4445), UINT16_C(58431), UINT16_C(42295), UINT16_C(38677), UINT16_C( 4752), UINT16_C( 6682), UINT16_C(64662) },
          { UINT16_C(53364), UINT16_C(58908), UINT16_C(46652), UINT16_C(47077), UINT16_C(11062), UINT16_C(35402), UINT16_C(37311), UINT16_C(53983) },
          { UINT16_C(15441), UINT16_C(37092), UINT16_C( 6945), UINT16_C(13877), UINT16_C(50610), UINT16_C(52552), UINT16_C(57055), UINT16_C(21705) },
          { UINT16_C(59055), UINT16_C(60218), UINT16_C( 8092), UINT16_C(53922), UINT16_C(60746), UINT16_C( 2397), UINT16_C(15486), UINT16_C(53212) } },
    },
    { { UINT16_C(49273), UINT16_C(39520), UINT16_C(38363), UINT16_C(36560), UINT16_C( 6235), UINT16_C(14939), UINT16_C( 9463), UINT16_C(42638),
        UINT16_C(51210), UINT16_C(42897), UINT16_C(13543), UINT16_C(12665), UINT16_C(54817), UINT16_C(40763), UINT16_C( 5907), UINT16_C(35951),
        UINT16_C(53207), UINT16_C(45606), UINT16_C(63076), UINT16_C(48960), UINT16_C(39694), UINT16_C( 1530), UINT16_C(35008), UINT16_C(51883),
        UINT16_C(15697), UINT16_C(14449), UINT16_C(60273), UINT16_C(37482), UINT16_C(42433), UINT16_C(54321), UINT16_C(41148), UINT16_C(37728) },
        { { UINT16_C(49273), UINT16_C(39520), UINT16_C(38363), UINT16_C(36560), UINT16_C( 6235), UINT16_C(14939), UINT16_C( 9463), UINT16_C(42638) },
          { UINT16_C(51210), UINT16_C(42897), UINT16_C(13543), UINT16_C(12665), UINT16_C(54817), UINT16_C(40763), UINT16_C( 5907), UINT16_C(35951) },
          { UINT16_C(53207), UINT16_C(45606), UINT16_C(63076), UINT16_C(48960), UINT16_C(39694), UINT16_C( 1530), UINT16_C(35008), UINT16_C(51883) },
          { UINT16_C(15697), UINT16_C(14449), UINT16_C(60273), UINT16_C(37482), UINT16_C(42433), UINT16_C(54321), UINT16_C(41148), UINT16_C(37728) } },
    },
    { { UINT16_C(34415), UINT16_C(54341), UINT16_C(34428), UINT16_C(35731), UINT16_C(36129), UINT16_C(57744), UINT16_C(15382), UINT16_C(26540),
        UINT16_C( 7545), UINT16_C(60063), UINT16_C( 2312), UINT16_C(51836), UINT16_C(44462), UINT16_C(27294), UINT16_C(65358), UINT16_C(48637),
        UINT16_C(17285), UINT16_C(  657), UINT16_C( 9673), UINT16_C(60045), UINT16_C( 7602), UINT16_C(51404), UINT16_C(30809), UINT16_C(53807),
        UINT16_C(53141), UINT16_C(40636), UINT16_C(14552), UINT16_C(34664), UINT16_C( 1766), UINT16_C(13553), UINT16_C(61189), UINT16_C(35825) },
        { { UINT16_C(34415), UINT16_C(54341), UINT16_C(34428), UINT16_C(35731), UINT16_C(36129), UINT16_C(57744), UINT16_C(15382), UINT16_C(26540) },
          { UINT16_C( 7545), UINT16_C(60063), UINT16_C( 2312), UINT16_C(51836), UINT16_C(44462), UINT16_C(27294), UINT16_C(65358), UINT16_C(48637) },
          { UINT16_C(17285), UINT16_C(  657), UINT16_C( 9673), UINT16_C(60045), UINT16_C( 7602), UINT16_C(51404), UINT16_C(30809), UINT16_C(53807) },
          { UINT16_C(53141), UINT16_C(40636), UINT16_C(14552), UINT16_C(34664), UINT16_C( 1766), UINT16_C(13553), UINT16_C(61189), UINT16_C(35825) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8x4_t r = simde_vld1q_u16_x4(test_vec[i].buf);
    simde_uint16x8x4_t expected = {{
        simde_vld1q_u16(test_vec[i].expected[0]),
        simde_vld1q_u16(test_vec[i].expected[1]),
        simde_vld1q_u16(test_vec[i].expected[2]),
        simde_vld1q_u16(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_u16x8x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t buf[32];
    simde_test_codegen_random_memory(64, (uint8_t*)buf);
    simde_test_codegen_write_vu16(2, 32, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint16x8x4_t val = simde_vld1q_u16_x4(buf);
    simde_test_arm_neon_write_u16x8x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t buf[16];
    uint32_t expected[4][4];
  } test_vec[] = {
    { { UINT32_C(4220355378), UINT32_C(1524964008), UINT32_C(2435035447), UINT32_C(3210957353), UINT32_C(4200407073), UINT32_C(1048692056), UINT32_C(3513938635), UINT32_C(2472305761),
        UINT32_C(2408507879), UINT32_C( 988378115), UINT32_C(1338706981), UINT32_C(2148413279), UINT32_C(2809817935), UINT32_C(4226218800), UINT32_C(3486275694), UINT32_C(2741184700) },
        { { UINT32_C(4220355378), UINT32_C(1524964008), UINT32_C(2435035447), UINT32_C(3210957353) },
          { UINT32_C(4200407073), UINT32_C(1048692056), UINT32_C(3513938635), UINT32_C(2472305761) },
          { UINT32_C(2408507879), UINT32_C( 988378115), UINT32_C(1338706981), UINT32_C(2148413279) },
          { UINT32_C(2809817935), UINT32_C(4226218800), UINT32_C(3486275694), UINT32_C(2741184700) } },
    },
    { { UINT32_C( 338882833), UINT32_C(2337217637), UINT32_C(2279217704), UINT32_C(2550720585), UINT32_C(2202042963), UINT32_C(3967690366), UINT32_C(1002130302), UINT32_C(2245926515),
        UINT32_C(1972965648), UINT32_C(1426122797), UINT32_C(1289607683), UINT32_C( 367388098), UINT32_C(3851953511), UINT32_C(3385923403), UINT32_C(3573845346), UINT32_C(3143295915) },
        { { UINT32_C( 338882833), UINT32_C(2337217637), UINT32_C(2279217704), UINT32_C(2550720585) },
          { UINT32_C(2202042963), UINT32_C(3967690366), UINT32_C(1002130302), UINT32_C(2245926515) },
          { UINT32_C(1972965648), UINT32_C(1426122797), UINT32_C(1289607683), UINT32_C( 367388098) },
          { UINT32_C(3851953511), UINT32_C(3385923403), UINT32_C(3573845346), UINT32_C(3143295915) } },
    },
    { { UINT32_C( 556922100), UINT32_C(3749065180), UINT32_C(3459011340), UINT32_C(2699301176), UINT32_C(2173008950), UINT32_C(4115290003), UINT32_C(2412466148), UINT32_C( 642458930),
        UINT32_C(4131879961), UINT32_C(3117792685), UINT32_C(1233649937), UINT32_C(1223257106), UINT32_C(2093576168), UINT32_C(2859537606), UINT32_C(2503556195), UINT32_C(2075886690) },
        { { UINT32_C( 556922100), UINT32_C(3749065180), UINT32_C(3459011340), UINT32_C(2699301176) },
          { UINT32_C(2173008950), UINT32_C(4115290003), UINT32_C(2412466148), UINT32_C( 642458930) },
          { UINT32_C(4131879961), UINT32_C(3117792685), UINT32_C(1233649937), UINT32_C(1223257106) },
          { UINT32_C(2093576168), UINT32_C(2859537606), UINT32_C(2503556195), UINT32_C(2075886690) } },
    },
    { { UINT32_C(2926641664), UINT32_C(3496429503), UINT32_C(1528491848), UINT32_C(1151533915), UINT32_C( 952135026), UINT32_C(3840029057), UINT32_C(3497598062), UINT32_C(2706060448),
        UINT32_C(4115643702), UINT32_C(1288091140), UINT32_C(  27779238), UINT32_C(1447381987), UINT32_C( 965608888), UINT32_C(2770170167), UINT32_C( 762680973), UINT32_C(  13549770) },
        { { UINT32_C(2926641664), UINT32_C(3496429503), UINT32_C(1528491848), UINT32_C(1151533915) },
          { UINT32_C( 952135026), UINT32_C(3840029057), UINT32_C(3497598062), UINT32_C(2706060448) },
          { UINT32_C(4115643702), UINT32_C(1288091140), UINT32_C(  27779238), UINT32_C(1447381987) },
          { UINT32_C( 965608888), UINT32_C(2770170167), UINT32_C( 762680973), UINT32_C(  13549770) } },
    },
    { { UINT32_C(2180324733), UINT32_C(2060368852), UINT32_C(2138797467), UINT32_C(2027274688), UINT32_C(4256261062), UINT32_C(1638059732), UINT32_C( 781129572), UINT32_C(1429102040),
        UINT32_C(1339499643), UINT32_C(2076812767), UINT32_C(3690611738), UINT32_C(3428044549), UINT32_C( 130614578), UINT32_C( 946367699), UINT32_C(1533474691), UINT32_C(3501299029) },
        { { UINT32_C(2180324733), UINT32_C(2060368852), UINT32_C(2138797467), UINT32_C(2027274688) },
          { UINT32_C(4256261062), UINT32_C(1638059732), UINT32_C( 781129572), UINT32_C(1429102040) },
          { UINT32_C(1339499643), UINT32_C(2076812767), UINT32_C(3690611738), UINT32_C(3428044549) },
          { UINT32_C( 130614578), UINT32_C( 946367699), UINT32_C(1533474691), UINT32_C(3501299029) } },
    },
    { { UINT32_C(2552203449), UINT32_C(1192486957), UINT32_C( 841092396), UINT32_C( 268334812), UINT32_C(1310115707), UINT32_C(3079044659), UINT32_C(3407015286), UINT32_C(1000063874),
        UINT32_C(2027141707), UINT32_C(3468748706), UINT32_C(3506496244), UINT32_C(3554737752), UINT32_C(4179818182), UINT32_C(3937446004), UINT32_C( 397788053), UINT32_C(3528609926) },
        { { UINT32_C(2552203449), UINT32_C(1192486957), UINT32_C( 841092396), UINT32_C( 268334812) },
          { UINT32_C(1310115707), UINT32_C(3079044659), UINT32_C(3407015286), UINT32_C(1000063874) },
          { UINT32_C(2027141707), UINT32_C(3468748706), UINT32_C(3506496244), UINT32_C(3554737752) },
          { UINT32_C(4179818182), UINT32_C(3937446004), UINT32_C( 397788053), UINT32_C(3528609926) } },
    },
    { { UINT32_C(2890540554), UINT32_C(  24840717), UINT32_C(1171422189), UINT32_C(1075425914), UINT32_C( 490290088), UINT32_C(2030562019), UINT32_C( 865123757), UINT32_C( 403038989),
        UINT32_C( 381964297), UINT32_C(1192705882), UINT32_C( 898493115), UINT32_C(1165338268), UINT32_C(3294801633), UINT32_C(1161652632), UINT32_C( 880397862), UINT32_C(3125575345) },
        { { UINT32_C(2890540554), UINT32_C(  24840717), UINT32_C(1171422189), UINT32_C(1075425914) },
          { UINT32_C( 490290088), UINT32_C(2030562019), UINT32_C( 865123757), UINT32_C( 403038989) },
          { UINT32_C( 381964297), UINT32_C(1192705882), UINT32_C( 898493115), UINT32_C(1165338268) },
          { UINT32_C(3294801633), UINT32_C(1161652632), UINT32_C( 880397862), UINT32_C(3125575345) } },
    },
    { { UINT32_C( 701501646), UINT32_C( 191948624), UINT32_C(1849753041), UINT32_C(2226369955), UINT32_C(4232648035), UINT32_C(2772534910), UINT32_C(  98155092), UINT32_C( 129967417),
        UINT32_C(2234552117), UINT32_C(1217438071), UINT32_C(1119277214), UINT32_C(3922094469), UINT32_C(4259647358), UINT32_C(3936495254), UINT32_C( 451967969), UINT32_C(3575754656) },
        { { UINT32_C( 701501646), UINT32_C( 191948624), UINT32_C(1849753041), UINT32_C(2226369955) },
          { UINT32_C(4232648035), UINT32_C(2772534910), UINT32_C(  98155092), UINT32_C( 129967417) },
          { UINT32_C(2234552117), UINT32_C(1217438071), UINT32_C(1119277214), UINT32_C(3922094469) },
          { UINT32_C(4259647358), UINT32_C(3936495254), UINT32_C( 451967969), UINT32_C(3575754656) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4x4_t r = simde_vld1q_u32_x4(test_vec[i].buf);
    simde_uint32x4x4_t expected = {{
        simde_vld1q_u32(test_vec[i].expected[0]),
        simde_vld1q_u32(test_vec[i].expected[1]),
        simde_vld1q_u32(test_vec[i].expected[2]),
        simde_vld1q_u32(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_u32x4x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t buf[16];
    simde_test_codegen_random_memory(64, (uint8_t*)buf);
    simde_test_codegen_write_vu32(2, 16, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint32x4x4_t val = simde_vld1q_u32_x4(buf);
    simde_test_arm_neon_write_u32x4x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t buf[8];
    uint64_t expected[4][2];
  } test_vec[] = {
    { { UINT64_C(10520105211553075775), UINT64_C(11325033667720623548), UINT64_C( 1669212815587151785), UINT64_C(  588936675983432375),
        UINT64_C( 3398455697992484772), UINT64_C( 4624523463350090866), UINT64_C(13472422644418594730), UINT64_C( 2275793887074265283) },
        { { UINT64_C(10520105211553075775), UINT64_C(11325033667720623548) },
          { UINT64_C( 1669212815587151785), UINT64_C(  588936675983432375) },
          { UINT64_C( 3398455697992484772), UINT64_C( 4624523463350090866) },
          { UINT64_C(13472422644418594730), UINT64_C( 2275793887074265283) } },
    },
    { { UINT64_C( 9468783106140361925), UINT64_C( 2140126212038842588), UINT64_C(11513159822878847496), UINT64_C(15832617892335900702),
        UINT64_C( 3218520463597924118), UINT64_C(  568670707163053395), UINT64_C(17654350058345456260), UINT64_C(  334189888231320753) },
        { { UINT64_C( 9468783106140361925), UINT64_C( 2140126212038842588) },
          { UINT64_C(11513159822878847496), UINT64_C(15832617892335900702) },
          { UINT64_C( 3218520463597924118), UINT64_C(  568670707163053395) },
          { UINT64_C(17654350058345456260), UINT64_C(  334189888231320753) } },
    },
    { { UINT64_C( 9670025760746485686), UINT64_C(12076455330113704339), UINT64_C( 3953888369104694034), UINT64_C( 7721317885515034164),
        UINT64_C(13479453079236596568), UINT64_C(11547200365892820340), UINT64_C( 9461052705600063377), UINT64_C( 4897892105837759191) },
        { { UINT64_C( 9670025760746485686), UINT64_C(12076455330113704339) },
          { UINT64_C( 3953888369104694034), UINT64_C( 7721317885515034164) },
          { UINT64_C(13479453079236596568), UINT64_C(11547200365892820340) },
          { UINT64_C( 9461052705600063377), UINT64_C( 4897892105837759191) } },
    },
    { { UINT64_C( 9297081154430462241), UINT64_C(14441170676760531515), UINT64_C( 3778849240485131167), UINT64_C(  550768354068011125),
        UINT64_C(10137696568385499682), UINT64_C(13882273429082982823), UINT64_C( 2756801866731783857), UINT64_C(15935192038703039032) },
        { { UINT64_C( 9297081154430462241), UINT64_C(14441170676760531515) },
          { UINT64_C( 3778849240485131167), UINT64_C(  550768354068011125) },
          { UINT64_C(10137696568385499682), UINT64_C(13882273429082982823) },
          { UINT64_C( 2756801866731783857), UINT64_C(15935192038703039032) } },
    },
    { { UINT64_C( 8249676201510860190), UINT64_C( 4713291409720988038), UINT64_C( 7950701854093940351), UINT64_C(12118255355189583508),
        UINT64_C( 8819197012572911655), UINT64_C( 3366311732671854309), UINT64_C( 3190154479603156640), UINT64_C(12269396943548699282) },
        { { UINT64_C( 8249676201510860190), UINT64_C( 4713291409720988038) },
          { UINT64_C( 7950701854093940351), UINT64_C(12118255355189583508) },
          { UINT64_C( 8819197012572911655), UINT64_C( 3366311732671854309) },
          { UINT64_C( 3190154479603156640), UINT64_C(12269396943548699282) } },
    },
    { { UINT64_C(15442282310449028575), UINT64_C(11138532152387072183), UINT64_C( 4165187156688630281), UINT64_C(14895403906566015113),
        UINT64_C(  846659502439814135), UINT64_C( 1726010116394781536), UINT64_C(12022225192063952631), UINT64_C(13730747145541299407) },
        { { UINT64_C(15442282310449028575), UINT64_C(11138532152387072183) },
          { UINT64_C( 4165187156688630281), UINT64_C(14895403906566015113) },
          { UINT64_C(  846659502439814135), UINT64_C( 1726010116394781536) },
          { UINT64_C(12022225192063952631), UINT64_C(13730747145541299407) } },
    },
    { { UINT64_C( 9159589500767645629), UINT64_C(10058452855462399601), UINT64_C(11958746780996816691), UINT64_C(14930259676739381677),
        UINT64_C(12735614868865014047), UINT64_C(10929328529060370060), UINT64_C( 9480322230277166357), UINT64_C(  317831310535554183) },
        { { UINT64_C( 9159589500767645629), UINT64_C(10058452855462399601) },
          { UINT64_C(11958746780996816691), UINT64_C(14930259676739381677) },
          { UINT64_C(12735614868865014047), UINT64_C(10929328529060370060) },
          { UINT64_C( 9480322230277166357), UINT64_C(  317831310535554183) } },
    },
    { { UINT64_C(15416666259768625667), UINT64_C(18343902254248305302), UINT64_C(16199582379334531703), UINT64_C(17534452820529039214),
        UINT64_C( 3407863282125936942), UINT64_C( 6427407297934934347), UINT64_C(  247265414267411254), UINT64_C(18023877176664188989) },
        { { UINT64_C(15416666259768625667), UINT64_C(18343902254248305302) },
          { UINT64_C(16199582379334531703), UINT64_C(17534452820529039214) },
          { UINT64_C( 3407863282125936942), UINT64_C( 6427407297934934347) },
          { UINT64_C(  247265414267411254), UINT64_C(18023877176664188989) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x2x4_t r = simde_vld1q_u64_x4(test_vec[i].buf);
    simde_uint64x2x4_t expected = {{
        simde_vld1q_u64(test_vec[i].expected[0]),
        simde_vld1q_u64(test_vec[i].expected[1]),
        simde_vld1q_u64(test_vec[i].expected[2]),
        simde_vld1q_u64(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_u64x2x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t buf[8];
    simde_test_codegen_random_memory(64, (uint8_t*)buf);
    simde_test_codegen_write_vu64(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint64x2x4_t val = simde_vld1q_u64_x4(buf);
    simde_test_arm_neon_write_u64x2x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_f32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_f64_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s8_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s16_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s64_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u8_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u16_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u64_x4)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
