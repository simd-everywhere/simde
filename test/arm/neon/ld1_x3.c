#define SIMDE_TEST_ARM_NEON_INSN ld1_x3
#include "test/test.h"
#include "test-neon.h"
#include "../../../simde/arm/neon/ld1_x3.h"
#include "../../../simde/arm/neon/ld1_lane.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld1_f32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 buf[6];
    simde_float32 expected[3][2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -888.98), SIMDE_FLOAT32_C(  -694.40), SIMDE_FLOAT32_C(    20.16), SIMDE_FLOAT32_C(  -917.81),
        SIMDE_FLOAT32_C(   420.99), SIMDE_FLOAT32_C(   574.51) },
        { { SIMDE_FLOAT32_C(  -888.98), SIMDE_FLOAT32_C(  -694.40) },
          { SIMDE_FLOAT32_C(    20.16), SIMDE_FLOAT32_C(  -917.81) },
          { SIMDE_FLOAT32_C(   420.99), SIMDE_FLOAT32_C(   574.51) } },
    },
    { { SIMDE_FLOAT32_C(   346.79), SIMDE_FLOAT32_C(   618.26), SIMDE_FLOAT32_C(  -931.06), SIMDE_FLOAT32_C(   657.47),
        SIMDE_FLOAT32_C(   404.28), SIMDE_FLOAT32_C(   373.34) },
        { { SIMDE_FLOAT32_C(   346.79), SIMDE_FLOAT32_C(   618.26) },
          { SIMDE_FLOAT32_C(  -931.06), SIMDE_FLOAT32_C(   657.47) },
          { SIMDE_FLOAT32_C(   404.28), SIMDE_FLOAT32_C(   373.34) } },
    },
    { { SIMDE_FLOAT32_C(   444.60), SIMDE_FLOAT32_C(  -509.24), SIMDE_FLOAT32_C(   602.28), SIMDE_FLOAT32_C(    77.95),
        SIMDE_FLOAT32_C(   861.00), SIMDE_FLOAT32_C(   523.46) },
        { { SIMDE_FLOAT32_C(   444.60), SIMDE_FLOAT32_C(  -509.24) },
          { SIMDE_FLOAT32_C(   602.28), SIMDE_FLOAT32_C(    77.95) },
          { SIMDE_FLOAT32_C(   861.00), SIMDE_FLOAT32_C(   523.46) } },
    },
    { { SIMDE_FLOAT32_C(  -666.26), SIMDE_FLOAT32_C(   585.18), SIMDE_FLOAT32_C(   589.29), SIMDE_FLOAT32_C(   163.58),
        SIMDE_FLOAT32_C(  -888.98), SIMDE_FLOAT32_C(  -328.02) },
        { { SIMDE_FLOAT32_C(  -666.26), SIMDE_FLOAT32_C(   585.18) },
          { SIMDE_FLOAT32_C(   589.29), SIMDE_FLOAT32_C(   163.58) },
          { SIMDE_FLOAT32_C(  -888.98), SIMDE_FLOAT32_C(  -328.02) } },
    },
    { { SIMDE_FLOAT32_C(   903.32), SIMDE_FLOAT32_C(   619.16), SIMDE_FLOAT32_C(  -497.00), SIMDE_FLOAT32_C(   850.93),
        SIMDE_FLOAT32_C(   857.80), SIMDE_FLOAT32_C(    37.13) },
        { { SIMDE_FLOAT32_C(   903.32), SIMDE_FLOAT32_C(   619.16) },
          { SIMDE_FLOAT32_C(  -497.00), SIMDE_FLOAT32_C(   850.93) },
          { SIMDE_FLOAT32_C(   857.80), SIMDE_FLOAT32_C(    37.13) } },
    },
    { { SIMDE_FLOAT32_C(   302.11), SIMDE_FLOAT32_C(   968.83), SIMDE_FLOAT32_C(   342.73), SIMDE_FLOAT32_C(  -677.74),
        SIMDE_FLOAT32_C(  -948.98), SIMDE_FLOAT32_C(  -236.28) },
        { { SIMDE_FLOAT32_C(   302.11), SIMDE_FLOAT32_C(   968.83) },
          { SIMDE_FLOAT32_C(   342.73), SIMDE_FLOAT32_C(  -677.74) },
          { SIMDE_FLOAT32_C(  -948.98), SIMDE_FLOAT32_C(  -236.28) } },
    },
    { { SIMDE_FLOAT32_C(   896.77), SIMDE_FLOAT32_C(   397.81), SIMDE_FLOAT32_C(  -618.02), SIMDE_FLOAT32_C(   965.72),
        SIMDE_FLOAT32_C(    55.28), SIMDE_FLOAT32_C(   786.26) },
        { { SIMDE_FLOAT32_C(   896.77), SIMDE_FLOAT32_C(   397.81) },
          { SIMDE_FLOAT32_C(  -618.02), SIMDE_FLOAT32_C(   965.72) },
          { SIMDE_FLOAT32_C(    55.28), SIMDE_FLOAT32_C(   786.26) } },
    },
    { { SIMDE_FLOAT32_C(   339.06), SIMDE_FLOAT32_C(  -500.12), SIMDE_FLOAT32_C(  -722.98), SIMDE_FLOAT32_C(   -58.66),
        SIMDE_FLOAT32_C(   577.82), SIMDE_FLOAT32_C(  -861.98) },
        { { SIMDE_FLOAT32_C(   339.06), SIMDE_FLOAT32_C(  -500.12) },
          { SIMDE_FLOAT32_C(  -722.98), SIMDE_FLOAT32_C(   -58.66) },
          { SIMDE_FLOAT32_C(   577.82), SIMDE_FLOAT32_C(  -861.98) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2x3_t r = simde_vld1_f32_x3(test_vec[i].buf);
    simde_float32x2x3_t expected = {{
        simde_vld1_f32(test_vec[i].expected[0]),
        simde_vld1_f32(test_vec[i].expected[1]),
        simde_vld1_f32(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_f32x2x3(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 buf[6];
    for (int j = 0 ; j < 6 ; j++) {
      buf[j] = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    }
    simde_test_codegen_write_vf32(2, 6, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32x2x3_t val = simde_vld1_f32_x3(buf);
    simde_test_arm_neon_write_f32x2x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_f64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 buf[3];
    simde_float64 expected[3][1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   569.90), SIMDE_FLOAT64_C(   741.85), SIMDE_FLOAT64_C(   966.09) },
        { { SIMDE_FLOAT64_C(   569.90) },
          { SIMDE_FLOAT64_C(   741.85) },
          { SIMDE_FLOAT64_C(   966.09) } },
    },
    { { SIMDE_FLOAT64_C(  -897.50), SIMDE_FLOAT64_C(   973.15), SIMDE_FLOAT64_C(   -68.38) },
        { { SIMDE_FLOAT64_C(  -897.50) },
          { SIMDE_FLOAT64_C(   973.15) },
          { SIMDE_FLOAT64_C(   -68.38) } },
    },
    { { SIMDE_FLOAT64_C(   262.37), SIMDE_FLOAT64_C(   619.82), SIMDE_FLOAT64_C(  -410.17) },
        { { SIMDE_FLOAT64_C(   262.37) },
          { SIMDE_FLOAT64_C(   619.82) },
          { SIMDE_FLOAT64_C(  -410.17) } },
    },
    { { SIMDE_FLOAT64_C(   584.45), SIMDE_FLOAT64_C(  -682.10), SIMDE_FLOAT64_C(   -60.19) },
        { { SIMDE_FLOAT64_C(   584.45) },
          { SIMDE_FLOAT64_C(  -682.10) },
          { SIMDE_FLOAT64_C(   -60.19) } },
    },
    { { SIMDE_FLOAT64_C(  -712.90), SIMDE_FLOAT64_C(    33.31), SIMDE_FLOAT64_C(   411.66) },
        { { SIMDE_FLOAT64_C(  -712.90) },
          { SIMDE_FLOAT64_C(    33.31) },
          { SIMDE_FLOAT64_C(   411.66) } },
    },
    { { SIMDE_FLOAT64_C(  -744.44), SIMDE_FLOAT64_C(   809.96), SIMDE_FLOAT64_C(  -111.78) },
        { { SIMDE_FLOAT64_C(  -744.44) },
          { SIMDE_FLOAT64_C(   809.96) },
          { SIMDE_FLOAT64_C(  -111.78) } },
    },
    { { SIMDE_FLOAT64_C(  -857.02), SIMDE_FLOAT64_C(   251.71), SIMDE_FLOAT64_C(  -229.61) },
        { { SIMDE_FLOAT64_C(  -857.02) },
          { SIMDE_FLOAT64_C(   251.71) },
          { SIMDE_FLOAT64_C(  -229.61) } },
    },
    { { SIMDE_FLOAT64_C(   478.06), SIMDE_FLOAT64_C(  -343.50), SIMDE_FLOAT64_C(   723.80) },
        { { SIMDE_FLOAT64_C(   478.06) },
          { SIMDE_FLOAT64_C(  -343.50) },
          { SIMDE_FLOAT64_C(   723.80) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1x3_t r = simde_vld1_f64_x3(test_vec[i].buf);
    simde_float64x1x3_t expected = {{
        simde_vld1_f64(test_vec[i].expected[0]),
        simde_vld1_f64(test_vec[i].expected[1]),
        simde_vld1_f64(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_f64x1x3(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 buf[3];
    for (int j = 0 ; j < 3 ; j++) {
      buf[j] = simde_test_codegen_random_f64(-1000.0, 1000.0);
    }
    simde_test_codegen_write_vf64(2, 3, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64x1x3_t val = simde_vld1_f64_x3(buf);
    simde_test_arm_neon_write_f64x1x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s8_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t buf[24];
    int8_t expected[3][8];
  } test_vec[] = {
    { { -INT8_C(  11), -INT8_C( 121),  INT8_C( 101), -INT8_C(  21), -INT8_C(  80), -INT8_C(  10),  INT8_C( 117), -INT8_C( 117),
        -INT8_C(  40), -INT8_C(  37), -INT8_C(  59),  INT8_C(  16), -INT8_C(  11),  INT8_C(  41), -INT8_C( 109),  INT8_C(  76),
         INT8_C(  10), -INT8_C(  40), -INT8_C(  85),  INT8_C(   5), -INT8_C( 106),  INT8_C( 100),  INT8_C(  96),  INT8_C(  54) },
        { { -INT8_C(  11), -INT8_C( 121),  INT8_C( 101), -INT8_C(  21), -INT8_C(  80), -INT8_C(  10),  INT8_C( 117), -INT8_C( 117) },
          { -INT8_C(  40), -INT8_C(  37), -INT8_C(  59),  INT8_C(  16), -INT8_C(  11),  INT8_C(  41), -INT8_C( 109),  INT8_C(  76) },
          {  INT8_C(  10), -INT8_C(  40), -INT8_C(  85),  INT8_C(   5), -INT8_C( 106),  INT8_C( 100),  INT8_C(  96),  INT8_C(  54) } },
    },
    { { -INT8_C(  97), -INT8_C(  65),  INT8_C(  42), -INT8_C(  27),  INT8_C(  31),  INT8_C( 108),  INT8_C(  50),  INT8_C(  21),
        -INT8_C(  13), -INT8_C( 105),  INT8_C(   0), -INT8_C(  92), -INT8_C( 114),  INT8_C( 117),  INT8_C(  47),  INT8_C( 102),
         INT8_C(  80), -INT8_C(  12),  INT8_C( 118),  INT8_C(  69),  INT8_C(  29),  INT8_C(   9), -INT8_C( 110),  INT8_C(  39) },
        { { -INT8_C(  97), -INT8_C(  65),  INT8_C(  42), -INT8_C(  27),  INT8_C(  31),  INT8_C( 108),  INT8_C(  50),  INT8_C(  21) },
          { -INT8_C(  13), -INT8_C( 105),  INT8_C(   0), -INT8_C(  92), -INT8_C( 114),  INT8_C( 117),  INT8_C(  47),  INT8_C( 102) },
          {  INT8_C(  80), -INT8_C(  12),  INT8_C( 118),  INT8_C(  69),  INT8_C(  29),  INT8_C(   9), -INT8_C( 110),  INT8_C(  39) } },
    },
    { { -INT8_C(  31),  INT8_C(  61),  INT8_C(  44),  INT8_C( 119), -INT8_C(  95), -INT8_C( 116), -INT8_C(  83),  INT8_C(  64),
         INT8_C(  75), -INT8_C(  40),  INT8_C(  38),  INT8_C( 107),  INT8_C(  68),  INT8_C(  88),      INT8_MIN,  INT8_C(  56),
        -INT8_C(  17),      INT8_MIN, -INT8_C(  36),  INT8_C( 125), -INT8_C(  11),  INT8_C(  11), -INT8_C(  29),  INT8_C(  69) },
        { { -INT8_C(  31),  INT8_C(  61),  INT8_C(  44),  INT8_C( 119), -INT8_C(  95), -INT8_C( 116), -INT8_C(  83),  INT8_C(  64) },
          {  INT8_C(  75), -INT8_C(  40),  INT8_C(  38),  INT8_C( 107),  INT8_C(  68),  INT8_C(  88),      INT8_MIN,  INT8_C(  56) },
          { -INT8_C(  17),      INT8_MIN, -INT8_C(  36),  INT8_C( 125), -INT8_C(  11),  INT8_C(  11), -INT8_C(  29),  INT8_C(  69) } },
    },
    { { -INT8_C(   1),  INT8_C(  90), -INT8_C( 117),  INT8_C(  29),  INT8_C(  99),  INT8_C(  29),  INT8_C(  68),  INT8_C(  69),
         INT8_C(  90),  INT8_C( 113), -INT8_C(  68), -INT8_C(   5), -INT8_C(   3),  INT8_C( 106),  INT8_C(  59),  INT8_C(  73),
         INT8_C(  66),  INT8_C(  97), -INT8_C(  76), -INT8_C( 122), -INT8_C(  71),  INT8_C(  52), -INT8_C(  66), -INT8_C(  87) },
        { { -INT8_C(   1),  INT8_C(  90), -INT8_C( 117),  INT8_C(  29),  INT8_C(  99),  INT8_C(  29),  INT8_C(  68),  INT8_C(  69) },
          {  INT8_C(  90),  INT8_C( 113), -INT8_C(  68), -INT8_C(   5), -INT8_C(   3),  INT8_C( 106),  INT8_C(  59),  INT8_C(  73) },
          {  INT8_C(  66),  INT8_C(  97), -INT8_C(  76), -INT8_C( 122), -INT8_C(  71),  INT8_C(  52), -INT8_C(  66), -INT8_C(  87) } },
    },
    { { -INT8_C(  76), -INT8_C( 102),  INT8_C(  38), -INT8_C(  87), -INT8_C(  91),  INT8_C(  10), -INT8_C(  18), -INT8_C(  91),
         INT8_C( 100),  INT8_C( 121), -INT8_C(  62), -INT8_C(  57), -INT8_C( 106),  INT8_C(   6),  INT8_C(  12), -INT8_C(  16),
         INT8_C( 119), -INT8_C(  55), -INT8_C(  21),  INT8_C( 117),  INT8_C(  51),  INT8_C(  39), -INT8_C(  66),  INT8_C( 117) },
        { { -INT8_C(  76), -INT8_C( 102),  INT8_C(  38), -INT8_C(  87), -INT8_C(  91),  INT8_C(  10), -INT8_C(  18), -INT8_C(  91) },
          {  INT8_C( 100),  INT8_C( 121), -INT8_C(  62), -INT8_C(  57), -INT8_C( 106),  INT8_C(   6),  INT8_C(  12), -INT8_C(  16) },
          {  INT8_C( 119), -INT8_C(  55), -INT8_C(  21),  INT8_C( 117),  INT8_C(  51),  INT8_C(  39), -INT8_C(  66),  INT8_C( 117) } },
    },
    { { -INT8_C( 120),  INT8_C( 114), -INT8_C(   5),  INT8_C(  66), -INT8_C(  90), -INT8_C(  70), -INT8_C(  21),  INT8_C(  90),
         INT8_C(  84),  INT8_C(  17),  INT8_C(   3), -INT8_C(   6),  INT8_C(  27), -INT8_C(  15), -INT8_C(  97),      INT8_MAX,
         INT8_C( 107),  INT8_C(  97),  INT8_C(  71),  INT8_C(   1),  INT8_C( 103),  INT8_C(  83), -INT8_C(  14), -INT8_C(  33) },
        { { -INT8_C( 120),  INT8_C( 114), -INT8_C(   5),  INT8_C(  66), -INT8_C(  90), -INT8_C(  70), -INT8_C(  21),  INT8_C(  90) },
          {  INT8_C(  84),  INT8_C(  17),  INT8_C(   3), -INT8_C(   6),  INT8_C(  27), -INT8_C(  15), -INT8_C(  97),      INT8_MAX },
          {  INT8_C( 107),  INT8_C(  97),  INT8_C(  71),  INT8_C(   1),  INT8_C( 103),  INT8_C(  83), -INT8_C(  14), -INT8_C(  33) } },
    },
    { {  INT8_C(  28), -INT8_C(  35),  INT8_C(  84),  INT8_C(  79),  INT8_C(   4),  INT8_C(  18), -INT8_C(  60), -INT8_C( 115),
        -INT8_C( 124), -INT8_C(  64), -INT8_C(  49),  INT8_C(  42),  INT8_C( 122), -INT8_C(  70), -INT8_C( 124), -INT8_C(  50),
        -INT8_C(  53), -INT8_C( 121), -INT8_C(  56), -INT8_C(  25),  INT8_C( 120),  INT8_C( 103),  INT8_C( 102), -INT8_C(  29) },
        { {  INT8_C(  28), -INT8_C(  35),  INT8_C(  84),  INT8_C(  79),  INT8_C(   4),  INT8_C(  18), -INT8_C(  60), -INT8_C( 115) },
          { -INT8_C( 124), -INT8_C(  64), -INT8_C(  49),  INT8_C(  42),  INT8_C( 122), -INT8_C(  70), -INT8_C( 124), -INT8_C(  50) },
          { -INT8_C(  53), -INT8_C( 121), -INT8_C(  56), -INT8_C(  25),  INT8_C( 120),  INT8_C( 103),  INT8_C( 102), -INT8_C(  29) } },
    },
    { { -INT8_C(  56), -INT8_C(  83), -INT8_C(  27),  INT8_C(  48),  INT8_C(   1), -INT8_C(  41),  INT8_C(  15),  INT8_C(  29),
        -INT8_C(  76),  INT8_C(  99),  INT8_C( 109), -INT8_C(  71),  INT8_C( 117),  INT8_C(  49),  INT8_C(  70), -INT8_C(   7),
        -INT8_C(  15),  INT8_C(  21),  INT8_C(  35),  INT8_C( 107), -INT8_C(  49), -INT8_C(  89),  INT8_C(  58), -INT8_C( 102) },
        { { -INT8_C(  56), -INT8_C(  83), -INT8_C(  27),  INT8_C(  48),  INT8_C(   1), -INT8_C(  41),  INT8_C(  15),  INT8_C(  29) },
          { -INT8_C(  76),  INT8_C(  99),  INT8_C( 109), -INT8_C(  71),  INT8_C( 117),  INT8_C(  49),  INT8_C(  70), -INT8_C(   7) },
          { -INT8_C(  15),  INT8_C(  21),  INT8_C(  35),  INT8_C( 107), -INT8_C(  49), -INT8_C(  89),  INT8_C(  58), -INT8_C( 102) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8x3_t r = simde_vld1_s8_x3(test_vec[i].buf);
    simde_int8x8x3_t expected = {{
        simde_vld1_s8(test_vec[i].expected[0]),
        simde_vld1_s8(test_vec[i].expected[1]),
        simde_vld1_s8(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_i8x8x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int8_t buf[24];
    simde_test_codegen_random_memory(24, (uint8_t*)buf);
    simde_test_codegen_write_vi8(2, 24, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int8x8x3_t val = simde_vld1_s8_x3(buf);
    simde_test_arm_neon_write_i8x8x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t buf[12];
    int16_t expected[3][4];
  } test_vec[] = {
    { {  INT16_C( 25595), -INT16_C( 21319),  INT16_C( 30814), -INT16_C(   703),  INT16_C(  5368),  INT16_C( 18560), -INT16_C( 14528), -INT16_C(  9009),
         INT16_C( 19110),  INT16_C(  1126),  INT16_C(  2820), -INT16_C( 24628) },
        { {  INT16_C( 25595), -INT16_C( 21319),  INT16_C( 30814), -INT16_C(   703) },
          {  INT16_C(  5368),  INT16_C( 18560), -INT16_C( 14528), -INT16_C(  9009) },
          {  INT16_C( 19110),  INT16_C(  1126),  INT16_C(  2820), -INT16_C( 24628) } },
    },
    { { -INT16_C( 25991), -INT16_C( 15949), -INT16_C( 31863), -INT16_C( 31250), -INT16_C( 22553),  INT16_C( 17713),  INT16_C( 29472),  INT16_C(  6210),
        -INT16_C( 15481), -INT16_C( 14495),  INT16_C( 12426),  INT16_C( 12707) },
        { { -INT16_C( 25991), -INT16_C( 15949), -INT16_C( 31863), -INT16_C( 31250) },
          { -INT16_C( 22553),  INT16_C( 17713),  INT16_C( 29472),  INT16_C(  6210) },
          { -INT16_C( 15481), -INT16_C( 14495),  INT16_C( 12426),  INT16_C( 12707) } },
    },
    { {  INT16_C(  2682),  INT16_C( 32309),  INT16_C(   533), -INT16_C( 28898), -INT16_C( 11876),  INT16_C(  9808),  INT16_C( 15956),  INT16_C( 15275),
        -INT16_C(  8987),  INT16_C(  1409), -INT16_C( 15537), -INT16_C( 10466) },
        { {  INT16_C(  2682),  INT16_C( 32309),  INT16_C(   533), -INT16_C( 28898) },
          { -INT16_C( 11876),  INT16_C(  9808),  INT16_C( 15956),  INT16_C( 15275) },
          { -INT16_C(  8987),  INT16_C(  1409), -INT16_C( 15537), -INT16_C( 10466) } },
    },
    { {  INT16_C( 32646),  INT16_C(  4510),  INT16_C( 17071),  INT16_C( 10562),  INT16_C( 30540),  INT16_C( 25000), -INT16_C( 14727),  INT16_C(  5872),
         INT16_C( 16535), -INT16_C(  5316), -INT16_C(  6274),  INT16_C( 25639) },
        { {  INT16_C( 32646),  INT16_C(  4510),  INT16_C( 17071),  INT16_C( 10562) },
          {  INT16_C( 30540),  INT16_C( 25000), -INT16_C( 14727),  INT16_C(  5872) },
          {  INT16_C( 16535), -INT16_C(  5316), -INT16_C(  6274),  INT16_C( 25639) } },
    },
    { { -INT16_C( 22333),  INT16_C(  4969), -INT16_C( 30869), -INT16_C(  3350), -INT16_C( 30714), -INT16_C( 19197),  INT16_C( 17866),  INT16_C(  5855),
        -INT16_C( 30788),  INT16_C( 13944),  INT16_C( 26701), -INT16_C(  7092) },
        { { -INT16_C( 22333),  INT16_C(  4969), -INT16_C( 30869), -INT16_C(  3350) },
          { -INT16_C( 30714), -INT16_C( 19197),  INT16_C( 17866),  INT16_C(  5855) },
          { -INT16_C( 30788),  INT16_C( 13944),  INT16_C( 26701), -INT16_C(  7092) } },
    },
    { { -INT16_C( 30551),  INT16_C( 10191), -INT16_C(  2449),  INT16_C( 12939), -INT16_C(  2658),  INT16_C(  2629),  INT16_C( 12156), -INT16_C( 31748),
        -INT16_C(    72), -INT16_C( 32200),  INT16_C(  5956),  INT16_C(   153) },
        { { -INT16_C( 30551),  INT16_C( 10191), -INT16_C(  2449),  INT16_C( 12939) },
          { -INT16_C(  2658),  INT16_C(  2629),  INT16_C( 12156), -INT16_C( 31748) },
          { -INT16_C(    72), -INT16_C( 32200),  INT16_C(  5956),  INT16_C(   153) } },
    },
    { {  INT16_C(  4510), -INT16_C(  5322), -INT16_C( 32135),  INT16_C(  8911), -INT16_C( 24822),  INT16_C( 31050), -INT16_C( 10859),  INT16_C( 13484),
        -INT16_C(  3638),  INT16_C( 18238),  INT16_C( 14881), -INT16_C(  9782) },
        { {  INT16_C(  4510), -INT16_C(  5322), -INT16_C( 32135),  INT16_C(  8911) },
          { -INT16_C( 24822),  INT16_C( 31050), -INT16_C( 10859),  INT16_C( 13484) },
          { -INT16_C(  3638),  INT16_C( 18238),  INT16_C( 14881), -INT16_C(  9782) } },
    },
    { {  INT16_C(   569),  INT16_C( 32091), -INT16_C(  3046), -INT16_C( 18307), -INT16_C( 19451),  INT16_C( 32676),  INT16_C( 29494),  INT16_C( 16801),
        -INT16_C(  5358), -INT16_C( 22342),  INT16_C( 26305), -INT16_C( 29732) },
        { {  INT16_C(   569),  INT16_C( 32091), -INT16_C(  3046), -INT16_C( 18307) },
          { -INT16_C( 19451),  INT16_C( 32676),  INT16_C( 29494),  INT16_C( 16801) },
          { -INT16_C(  5358), -INT16_C( 22342),  INT16_C( 26305), -INT16_C( 29732) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4x3_t r = simde_vld1_s16_x3(test_vec[i].buf);
    simde_int16x4x3_t expected = {{
        simde_vld1_s16(test_vec[i].expected[0]),
        simde_vld1_s16(test_vec[i].expected[1]),
        simde_vld1_s16(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_i16x4x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int16_t buf[12];
    simde_test_codegen_random_memory(24, (uint8_t*)buf);
    simde_test_codegen_write_vi16(2, 12, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int16x4x3_t val = simde_vld1_s16_x3(buf);
    simde_test_arm_neon_write_i16x4x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t buf[6];
    int32_t expected[3][2];
  } test_vec[] = {
    { {  INT32_C(  2043812440), -INT32_C(  1923965868), -INT32_C(  1190482529), -INT32_C(  1485731934),  INT32_C(  1915098427), -INT32_C(  1682716535) },
        { {  INT32_C(  2043812440), -INT32_C(  1923965868) },
          { -INT32_C(  1190482529), -INT32_C(  1485731934) },
          {  INT32_C(  1915098427), -INT32_C(  1682716535) } },
    },
    { {  INT32_C(  1950576051),  INT32_C(   738205652), -INT32_C(  1918512583),  INT32_C(   236648303),  INT32_C(  1187456164), -INT32_C(   403818324) },
        { {  INT32_C(  1950576051),  INT32_C(   738205652) },
          { -INT32_C(  1918512583),  INT32_C(   236648303) },
          {  INT32_C(  1187456164), -INT32_C(   403818324) } },
    },
    { { -INT32_C(   682027954), -INT32_C(  1871573796),  INT32_C(  1308931706),  INT32_C(   259654869),  INT32_C(  1184636887), -INT32_C(  1168853226) },
        { { -INT32_C(   682027954), -INT32_C(  1871573796) },
          {  INT32_C(  1308931706),  INT32_C(   259654869) },
          {  INT32_C(  1184636887), -INT32_C(  1168853226) } },
    },
    { { -INT32_C(  2029970469), -INT32_C(  1586499757), -INT32_C(   528955389),  INT32_C(  1332800469),  INT32_C(  1990030497),  INT32_C(  1350899577) },
        { { -INT32_C(  2029970469), -INT32_C(  1586499757) },
          { -INT32_C(   528955389),  INT32_C(  1332800469) },
          {  INT32_C(  1990030497),  INT32_C(  1350899577) } },
    },
    { {  INT32_C(  1284907574), -INT32_C(  1274615079),  INT32_C(  1480328965), -INT32_C(    84235274),  INT32_C(  1222275699), -INT32_C(    23639459) },
        { {  INT32_C(  1284907574), -INT32_C(  1274615079) },
          {  INT32_C(  1480328965), -INT32_C(    84235274) },
          {  INT32_C(  1222275699), -INT32_C(    23639459) } },
    },
    { {  INT32_C(   930428094), -INT32_C(  2121794997), -INT32_C(   171107044),  INT32_C(   212521991), -INT32_C(   765073701),  INT32_C(    80502673) },
        { {  INT32_C(   930428094), -INT32_C(  2121794997) },
          { -INT32_C(   171107044),  INT32_C(   212521991) },
          { -INT32_C(   765073701),  INT32_C(    80502673) } },
    },
    { {  INT32_C(   793618129), -INT32_C(  1372723984),  INT32_C(  1692836377), -INT32_C(  1176080995), -INT32_C(  1833978997),  INT32_C(  1671387527) },
        { {  INT32_C(   793618129), -INT32_C(  1372723984) },
          {  INT32_C(  1692836377), -INT32_C(  1176080995) },
          { -INT32_C(  1833978997),  INT32_C(  1671387527) } },
    },
    { { -INT32_C(   801831873),  INT32_C(   886309219), -INT32_C(  1755111001),  INT32_C(   524652806), -INT32_C(   796710093),  INT32_C(   613050777) },
        { { -INT32_C(   801831873),  INT32_C(   886309219) },
          { -INT32_C(  1755111001),  INT32_C(   524652806) },
          { -INT32_C(   796710093),  INT32_C(   613050777) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2x3_t r = simde_vld1_s32_x3(test_vec[i].buf);
    simde_int32x2x3_t expected = {{
        simde_vld1_s32(test_vec[i].expected[0]),
        simde_vld1_s32(test_vec[i].expected[1]),
        simde_vld1_s32(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_i32x2x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int32_t buf[6];
    simde_test_codegen_random_memory(24, (uint8_t*)buf);
    simde_test_codegen_write_vi32(2, 6, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int32x2x3_t val = simde_vld1_s32_x3(buf);
    simde_test_arm_neon_write_i32x2x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t buf[3];
    int64_t expected[3][1];
  } test_vec[] = {
    { {  INT64_C(  417499293700581051), -INT64_C( 1219175381170673886), -INT64_C( 3786260281518077139) },
        { {  INT64_C(  417499293700581051) },
          { -INT64_C( 1219175381170673886) },
          { -INT64_C( 3786260281518077139) } },
    },
    { { -INT64_C( 3561255404491550293), -INT64_C(  706254993944636729),  INT64_C( 7704058335413968519) },
        { { -INT64_C( 3561255404491550293) },
          { -INT64_C(  706254993944636729) },
          {  INT64_C( 7704058335413968519) } },
    },
    { {  INT64_C(  521426194319989788), -INT64_C( 4850782561955540020),  INT64_C( 3164373178695402272) },
        { {  INT64_C(  521426194319989788) },
          { -INT64_C( 4850782561955540020) },
          {  INT64_C( 3164373178695402272) } },
    },
    { { -INT64_C( 7899295643285969222), -INT64_C( 5958190970674387220), -INT64_C(  358815886111650733) },
        { { -INT64_C( 7899295643285969222) },
          { -INT64_C( 5958190970674387220) },
          { -INT64_C(  358815886111650733) } },
    },
    { { -INT64_C( 4265796107336945923), -INT64_C( 1222697601451953409), -INT64_C( 6984933164683097214) },
        { { -INT64_C( 4265796107336945923) },
          { -INT64_C( 1222697601451953409) },
          { -INT64_C( 6984933164683097214) } },
    },
    { { -INT64_C( 3122422980514702124),  INT64_C( 8190430834058435035),  INT64_C(  154791996658443571) },
        { { -INT64_C( 3122422980514702124) },
          {  INT64_C( 8190430834058435035) },
          {  INT64_C(  154791996658443571) } },
    },
    { { -INT64_C( 4979725660392694278), -INT64_C( 7801057294624895982), -INT64_C( 6300778372033596500) },
        { { -INT64_C( 4979725660392694278) },
          { -INT64_C( 7801057294624895982) },
          { -INT64_C( 6300778372033596500) } },
    },
    { {  INT64_C( 6776513792489452936), -INT64_C(  504534110650011552),  INT64_C( 2855456415087159380) },
        { {  INT64_C( 6776513792489452936) },
          { -INT64_C(  504534110650011552) },
          {  INT64_C( 2855456415087159380) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1x3_t r = simde_vld1_s64_x3(test_vec[i].buf);
    simde_int64x1x3_t expected = {{
        simde_vld1_s64(test_vec[i].expected[0]),
        simde_vld1_s64(test_vec[i].expected[1]),
        simde_vld1_s64(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_i64x1x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int64_t buf[3];
    simde_test_codegen_random_memory(24, (uint8_t*)buf);
    simde_test_codegen_write_vi64(2, 3, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int64x1x3_t val = simde_vld1_s64_x3(buf);
    simde_test_arm_neon_write_i64x1x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u8_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t buf[24];
    uint8_t expected[3][8];
  } test_vec[] = {
    { { UINT8_C( 46), UINT8_C(  2), UINT8_C(129), UINT8_C(166), UINT8_C(106), UINT8_C(232), UINT8_C(138), UINT8_C( 50),
        UINT8_C(149), UINT8_C(111), UINT8_C( 98), UINT8_C(150), UINT8_C( 70), UINT8_C(113), UINT8_C(180), UINT8_C(250),
        UINT8_C(212), UINT8_C( 33), UINT8_C(179), UINT8_C( 73), UINT8_C( 82), UINT8_C(249), UINT8_C( 66), UINT8_C( 68) },
        { { UINT8_C( 46), UINT8_C(  2), UINT8_C(129), UINT8_C(166), UINT8_C(106), UINT8_C(232), UINT8_C(138), UINT8_C( 50) },
          { UINT8_C(149), UINT8_C(111), UINT8_C( 98), UINT8_C(150), UINT8_C( 70), UINT8_C(113), UINT8_C(180), UINT8_C(250) },
          { UINT8_C(212), UINT8_C( 33), UINT8_C(179), UINT8_C( 73), UINT8_C( 82), UINT8_C(249), UINT8_C( 66), UINT8_C( 68) } },
    },
    { { UINT8_C( 14), UINT8_C(101), UINT8_C(175), UINT8_C(221), UINT8_C( 12), UINT8_C(233), UINT8_C(120), UINT8_C( 58),
        UINT8_C(236), UINT8_C(249), UINT8_C(225), UINT8_C( 86), UINT8_C(225), UINT8_C(107), UINT8_C(136), UINT8_C(119),
        UINT8_C(218), UINT8_C(235), UINT8_C( 13), UINT8_C( 32), UINT8_C( 92), UINT8_C(193), UINT8_C( 26), UINT8_C( 49) },
        { { UINT8_C( 14), UINT8_C(101), UINT8_C(175), UINT8_C(221), UINT8_C( 12), UINT8_C(233), UINT8_C(120), UINT8_C( 58) },
          { UINT8_C(236), UINT8_C(249), UINT8_C(225), UINT8_C( 86), UINT8_C(225), UINT8_C(107), UINT8_C(136), UINT8_C(119) },
          { UINT8_C(218), UINT8_C(235), UINT8_C( 13), UINT8_C( 32), UINT8_C( 92), UINT8_C(193), UINT8_C( 26), UINT8_C( 49) } },
    },
    { { UINT8_C(226), UINT8_C(206), UINT8_C(122), UINT8_C( 53), UINT8_C(199), UINT8_C(189), UINT8_C(121), UINT8_C(214),
        UINT8_C( 34), UINT8_C( 40), UINT8_C(179), UINT8_C( 47), UINT8_C( 18), UINT8_C( 43), UINT8_C(105), UINT8_C(254),
        UINT8_C( 37), UINT8_C( 74), UINT8_C( 84), UINT8_C(  6), UINT8_C(181), UINT8_C(220), UINT8_C(125), UINT8_C(143) },
        { { UINT8_C(226), UINT8_C(206), UINT8_C(122), UINT8_C( 53), UINT8_C(199), UINT8_C(189), UINT8_C(121), UINT8_C(214) },
          { UINT8_C( 34), UINT8_C( 40), UINT8_C(179), UINT8_C( 47), UINT8_C( 18), UINT8_C( 43), UINT8_C(105), UINT8_C(254) },
          { UINT8_C( 37), UINT8_C( 74), UINT8_C( 84), UINT8_C(  6), UINT8_C(181), UINT8_C(220), UINT8_C(125), UINT8_C(143) } },
    },
    { { UINT8_C(199), UINT8_C(139), UINT8_C(175), UINT8_C( 36), UINT8_C( 76), UINT8_C(202), UINT8_C( 85), UINT8_C( 47),
        UINT8_C(152), UINT8_C(207), UINT8_C(100), UINT8_C( 95), UINT8_C(140), UINT8_C(221), UINT8_C( 53), UINT8_C(175),
        UINT8_C(  5), UINT8_C(233), UINT8_C(222), UINT8_C( 23), UINT8_C( 20), UINT8_C( 71), UINT8_C( 21), UINT8_C( 57) },
        { { UINT8_C(199), UINT8_C(139), UINT8_C(175), UINT8_C( 36), UINT8_C( 76), UINT8_C(202), UINT8_C( 85), UINT8_C( 47) },
          { UINT8_C(152), UINT8_C(207), UINT8_C(100), UINT8_C( 95), UINT8_C(140), UINT8_C(221), UINT8_C( 53), UINT8_C(175) },
          { UINT8_C(  5), UINT8_C(233), UINT8_C(222), UINT8_C( 23), UINT8_C( 20), UINT8_C( 71), UINT8_C( 21), UINT8_C( 57) } },
    },
    { { UINT8_C(146), UINT8_C(105), UINT8_C( 64), UINT8_C( 71), UINT8_C( 70), UINT8_C(189), UINT8_C(215), UINT8_C( 13),
        UINT8_C( 72), UINT8_C(134), UINT8_C( 49), UINT8_C(149), UINT8_C( 80), UINT8_C(134), UINT8_C(196), UINT8_C(232),
        UINT8_C( 86), UINT8_C( 40), UINT8_C( 72), UINT8_C(226), UINT8_C(  5), UINT8_C(125), UINT8_C(145), UINT8_C( 10) },
        { { UINT8_C(146), UINT8_C(105), UINT8_C( 64), UINT8_C( 71), UINT8_C( 70), UINT8_C(189), UINT8_C(215), UINT8_C( 13) },
          { UINT8_C( 72), UINT8_C(134), UINT8_C( 49), UINT8_C(149), UINT8_C( 80), UINT8_C(134), UINT8_C(196), UINT8_C(232) },
          { UINT8_C( 86), UINT8_C( 40), UINT8_C( 72), UINT8_C(226), UINT8_C(  5), UINT8_C(125), UINT8_C(145), UINT8_C( 10) } },
    },
    { { UINT8_C(102), UINT8_C(111), UINT8_C( 34), UINT8_C(123), UINT8_C(183), UINT8_C( 55), UINT8_C(180), UINT8_C( 73),
        UINT8_C(161), UINT8_C(244), UINT8_C(144), UINT8_C(231), UINT8_C(178), UINT8_C(103), UINT8_C(244), UINT8_C(250),
        UINT8_C(238), UINT8_C( 38), UINT8_C(143), UINT8_C( 62), UINT8_C(172), UINT8_C( 83), UINT8_C( 39), UINT8_C(  2) },
        { { UINT8_C(102), UINT8_C(111), UINT8_C( 34), UINT8_C(123), UINT8_C(183), UINT8_C( 55), UINT8_C(180), UINT8_C( 73) },
          { UINT8_C(161), UINT8_C(244), UINT8_C(144), UINT8_C(231), UINT8_C(178), UINT8_C(103), UINT8_C(244), UINT8_C(250) },
          { UINT8_C(238), UINT8_C( 38), UINT8_C(143), UINT8_C( 62), UINT8_C(172), UINT8_C( 83), UINT8_C( 39), UINT8_C(  2) } },
    },
    { { UINT8_C(123), UINT8_C(111), UINT8_C(229), UINT8_C(128), UINT8_C(236), UINT8_C(118), UINT8_C(139), UINT8_C( 83),
        UINT8_C(230), UINT8_C(173), UINT8_C(206), UINT8_C(157), UINT8_C(228), UINT8_C(130), UINT8_C(230), UINT8_C(133),
        UINT8_C(119), UINT8_C(118), UINT8_C(108), UINT8_C( 41), UINT8_C(222), UINT8_C( 97), UINT8_C( 35), UINT8_C(204) },
        { { UINT8_C(123), UINT8_C(111), UINT8_C(229), UINT8_C(128), UINT8_C(236), UINT8_C(118), UINT8_C(139), UINT8_C( 83) },
          { UINT8_C(230), UINT8_C(173), UINT8_C(206), UINT8_C(157), UINT8_C(228), UINT8_C(130), UINT8_C(230), UINT8_C(133) },
          { UINT8_C(119), UINT8_C(118), UINT8_C(108), UINT8_C( 41), UINT8_C(222), UINT8_C( 97), UINT8_C( 35), UINT8_C(204) } },
    },
    { { UINT8_C(135), UINT8_C(179), UINT8_C( 10), UINT8_C( 51), UINT8_C(  6), UINT8_C( 49), UINT8_C( 54), UINT8_C(130),
        UINT8_C(160), UINT8_C( 27), UINT8_C(  2), UINT8_C(141), UINT8_C(145), UINT8_C(141), UINT8_C(224), UINT8_C(119),
        UINT8_C( 58), UINT8_C(174), UINT8_C( 20), UINT8_C( 31), UINT8_C( 48), UINT8_C(250), UINT8_C(164), UINT8_C(167) },
        { { UINT8_C(135), UINT8_C(179), UINT8_C( 10), UINT8_C( 51), UINT8_C(  6), UINT8_C( 49), UINT8_C( 54), UINT8_C(130) },
          { UINT8_C(160), UINT8_C( 27), UINT8_C(  2), UINT8_C(141), UINT8_C(145), UINT8_C(141), UINT8_C(224), UINT8_C(119) },
          { UINT8_C( 58), UINT8_C(174), UINT8_C( 20), UINT8_C( 31), UINT8_C( 48), UINT8_C(250), UINT8_C(164), UINT8_C(167) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8x3_t r = simde_vld1_u8_x3(test_vec[i].buf);
    simde_uint8x8x3_t expected = {{
        simde_vld1_u8(test_vec[i].expected[0]),
        simde_vld1_u8(test_vec[i].expected[1]),
        simde_vld1_u8(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_u8x8x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t buf[24];
    simde_test_codegen_random_memory(24, buf);
    simde_test_codegen_write_vu8(2, 24, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint8x8x3_t val = simde_vld1_u8_x3(buf);
    simde_test_arm_neon_write_u8x8x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t buf[12];
    uint16_t expected[3][4];
  } test_vec[] = {
    { { UINT16_C( 6609), UINT16_C(17989), UINT16_C(54332), UINT16_C(50414), UINT16_C(52298), UINT16_C(44748), UINT16_C(55247), UINT16_C(12044),
        UINT16_C(44872), UINT16_C(11892), UINT16_C(29751), UINT16_C(35622) },
        { { UINT16_C( 6609), UINT16_C(17989), UINT16_C(54332), UINT16_C(50414) },
          { UINT16_C(52298), UINT16_C(44748), UINT16_C(55247), UINT16_C(12044) },
          { UINT16_C(44872), UINT16_C(11892), UINT16_C(29751), UINT16_C(35622) } },
    },
    { { UINT16_C( 2012), UINT16_C(22680), UINT16_C(14501), UINT16_C(30591), UINT16_C(50513), UINT16_C(36285), UINT16_C(43929), UINT16_C(58193),
        UINT16_C( 7543), UINT16_C(18065), UINT16_C(40437), UINT16_C(15733) },
        { { UINT16_C( 2012), UINT16_C(22680), UINT16_C(14501), UINT16_C(30591) },
          { UINT16_C(50513), UINT16_C(36285), UINT16_C(43929), UINT16_C(58193) },
          { UINT16_C( 7543), UINT16_C(18065), UINT16_C(40437), UINT16_C(15733) } },
    },
    { { UINT16_C(59725), UINT16_C(33899), UINT16_C(37213), UINT16_C(14864), UINT16_C(43160), UINT16_C(15762), UINT16_C( 4576), UINT16_C(12724),
        UINT16_C(29142), UINT16_C(28862), UINT16_C( 3868), UINT16_C(37715) },
        { { UINT16_C(59725), UINT16_C(33899), UINT16_C(37213), UINT16_C(14864) },
          { UINT16_C(43160), UINT16_C(15762), UINT16_C( 4576), UINT16_C(12724) },
          { UINT16_C(29142), UINT16_C(28862), UINT16_C( 3868), UINT16_C(37715) } },
    },
    { { UINT16_C(58668), UINT16_C( 8665), UINT16_C(20098), UINT16_C(53086), UINT16_C(51512), UINT16_C(38228), UINT16_C(25690), UINT16_C(62159),
        UINT16_C(24844), UINT16_C(60464), UINT16_C(58483), UINT16_C(18717) },
        { { UINT16_C(58668), UINT16_C( 8665), UINT16_C(20098), UINT16_C(53086) },
          { UINT16_C(51512), UINT16_C(38228), UINT16_C(25690), UINT16_C(62159) },
          { UINT16_C(24844), UINT16_C(60464), UINT16_C(58483), UINT16_C(18717) } },
    },
    { { UINT16_C(56150), UINT16_C(29369), UINT16_C( 3562), UINT16_C( 5638), UINT16_C(57330), UINT16_C(29752), UINT16_C(38446), UINT16_C(26180),
        UINT16_C(39008), UINT16_C(47867), UINT16_C(52220), UINT16_C( 2221) },
        { { UINT16_C(56150), UINT16_C(29369), UINT16_C( 3562), UINT16_C( 5638) },
          { UINT16_C(57330), UINT16_C(29752), UINT16_C(38446), UINT16_C(26180) },
          { UINT16_C(39008), UINT16_C(47867), UINT16_C(52220), UINT16_C( 2221) } },
    },
    { { UINT16_C(56620), UINT16_C(40948), UINT16_C( 4545), UINT16_C( 6121), UINT16_C(41708), UINT16_C(54922), UINT16_C(37039), UINT16_C(41452),
        UINT16_C( 9327), UINT16_C(40214), UINT16_C(23227), UINT16_C( 6915) },
        { { UINT16_C(56620), UINT16_C(40948), UINT16_C( 4545), UINT16_C( 6121) },
          { UINT16_C(41708), UINT16_C(54922), UINT16_C(37039), UINT16_C(41452) },
          { UINT16_C( 9327), UINT16_C(40214), UINT16_C(23227), UINT16_C( 6915) } },
    },
    { { UINT16_C(65522), UINT16_C(61141), UINT16_C(33482), UINT16_C(63222), UINT16_C(59999), UINT16_C( 8598), UINT16_C(32763), UINT16_C(59192),
        UINT16_C(49697), UINT16_C(53693), UINT16_C(43346), UINT16_C(49778) },
        { { UINT16_C(65522), UINT16_C(61141), UINT16_C(33482), UINT16_C(63222) },
          { UINT16_C(59999), UINT16_C( 8598), UINT16_C(32763), UINT16_C(59192) },
          { UINT16_C(49697), UINT16_C(53693), UINT16_C(43346), UINT16_C(49778) } },
    },
    { { UINT16_C(35022), UINT16_C(35167), UINT16_C(25570), UINT16_C(54436), UINT16_C(31074), UINT16_C(11458), UINT16_C(47356), UINT16_C(23330),
        UINT16_C(47266), UINT16_C(40316), UINT16_C(46391), UINT16_C(22916) },
        { { UINT16_C(35022), UINT16_C(35167), UINT16_C(25570), UINT16_C(54436) },
          { UINT16_C(31074), UINT16_C(11458), UINT16_C(47356), UINT16_C(23330) },
          { UINT16_C(47266), UINT16_C(40316), UINT16_C(46391), UINT16_C(22916) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4x3_t r = simde_vld1_u16_x3(test_vec[i].buf);
    simde_uint16x4x3_t expected = {{
        simde_vld1_u16(test_vec[i].expected[0]),
        simde_vld1_u16(test_vec[i].expected[1]),
        simde_vld1_u16(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_u16x4x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t buf[12];
    simde_test_codegen_random_memory(24, (uint8_t*)buf);
    simde_test_codegen_write_vu16(2, 12, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint16x4x3_t val = simde_vld1_u16_x3(buf);
    simde_test_arm_neon_write_u16x4x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t buf[6];
    uint32_t expected[3][2];
  } test_vec[] = {
    { { UINT32_C(3391766903), UINT32_C(3113000171), UINT32_C( 121826085), UINT32_C(2967266894), UINT32_C(1541185119), UINT32_C(4189585239) },
        { { UINT32_C(3391766903), UINT32_C(3113000171) },
          { UINT32_C( 121826085), UINT32_C(2967266894) },
          { UINT32_C(1541185119), UINT32_C(4189585239) } },
    },
    { { UINT32_C(4019663799), UINT32_C(1615338472), UINT32_C(1210741341), UINT32_C( 855750158), UINT32_C(4030415777), UINT32_C(2292193065) },
        { { UINT32_C(4019663799), UINT32_C(1615338472) },
          { UINT32_C(1210741341), UINT32_C( 855750158) },
          { UINT32_C(4030415777), UINT32_C(2292193065) } },
    },
    { { UINT32_C( 216300981), UINT32_C( 856071036), UINT32_C(3072499150), UINT32_C( 353856184), UINT32_C(3948757468), UINT32_C(2552127223) },
        { { UINT32_C( 216300981), UINT32_C( 856071036) },
          { UINT32_C(3072499150), UINT32_C( 353856184) },
          { UINT32_C(3948757468), UINT32_C(2552127223) } },
    },
    { { UINT32_C(3397933473), UINT32_C( 642984304), UINT32_C( 573716390), UINT32_C(2689939666), UINT32_C(2388097237), UINT32_C(3215159010) },
        { { UINT32_C(3397933473), UINT32_C( 642984304) },
          { UINT32_C( 573716390), UINT32_C(2689939666) },
          { UINT32_C(2388097237), UINT32_C(3215159010) } },
    },
    { { UINT32_C(2796159407), UINT32_C(  20957279), UINT32_C(2462828322), UINT32_C(2528648944), UINT32_C( 666430293), UINT32_C(4190637603) },
        { { UINT32_C(2796159407), UINT32_C(  20957279) },
          { UINT32_C(2462828322), UINT32_C(2528648944) },
          { UINT32_C( 666430293), UINT32_C(4190637603) } },
    },
    { { UINT32_C(1753685894), UINT32_C(1025976974), UINT32_C(2347028779), UINT32_C(3163300762), UINT32_C(3679344618), UINT32_C(3413182326) },
        { { UINT32_C(1753685894), UINT32_C(1025976974) },
          { UINT32_C(2347028779), UINT32_C(3163300762) },
          { UINT32_C(3679344618), UINT32_C(3413182326) } },
    },
    { { UINT32_C( 368257778), UINT32_C(3188636472), UINT32_C(1747359194), UINT32_C(3953544896), UINT32_C(3111553567), UINT32_C(2541028013) },
        { { UINT32_C( 368257778), UINT32_C(3188636472) },
          { UINT32_C(1747359194), UINT32_C(3953544896) },
          { UINT32_C(3111553567), UINT32_C(2541028013) } },
    },
    { { UINT32_C(3497182298), UINT32_C(3181110475), UINT32_C(1188204046), UINT32_C( 604299593), UINT32_C( 915155574), UINT32_C(2552377976) },
        { { UINT32_C(3497182298), UINT32_C(3181110475) },
          { UINT32_C(1188204046), UINT32_C( 604299593) },
          { UINT32_C( 915155574), UINT32_C(2552377976) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2x3_t r = simde_vld1_u32_x3(test_vec[i].buf);
    simde_uint32x2x3_t expected = {{
        simde_vld1_u32(test_vec[i].expected[0]),
        simde_vld1_u32(test_vec[i].expected[1]),
        simde_vld1_u32(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_u32x2x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t buf[6];
    simde_test_codegen_random_memory(24, (uint8_t*)buf);
    simde_test_codegen_write_vu32(2, 6, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint32x2x3_t val = simde_vld1_u32_x3(buf);
    simde_test_arm_neon_write_u32x2x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t buf[3];
    uint64_t expected[3][1];
  } test_vec[] = {
    { { UINT64_C(17654611484569868476), UINT64_C( 7283270950622425995), UINT64_C( 4421602200060159471) },
        { { UINT64_C(17654611484569868476) },
          { UINT64_C( 7283270950622425995) },
          { UINT64_C( 4421602200060159471) } },
    },
    { { UINT64_C(15630469401322711514), UINT64_C(10285731182989622318), UINT64_C(15164736924849308598) },
        { { UINT64_C(15630469401322711514) },
          { UINT64_C(10285731182989622318) },
          { UINT64_C(15164736924849308598) } },
    },
    { { UINT64_C(12168840330351419100), UINT64_C( 1676717752007152464), UINT64_C( 9129533977082758433) },
        { { UINT64_C(12168840330351419100) },
          { UINT64_C( 1676717752007152464) },
          { UINT64_C( 9129533977082758433) } },
    },
    { { UINT64_C( 7626844375595324961), UINT64_C(11138506105637626397), UINT64_C(10610562576259910976) },
        { { UINT64_C( 7626844375595324961) },
          { UINT64_C(11138506105637626397) },
          { UINT64_C(10610562576259910976) } },
    },
    { { UINT64_C(16074870712278917327), UINT64_C(13616275717827568127), UINT64_C( 3422800518842876572) },
        { { UINT64_C(16074870712278917327) },
          { UINT64_C(13616275717827568127) },
          { UINT64_C( 3422800518842876572) } },
    },
    { { UINT64_C(11515309317332436680), UINT64_C(17173717345411499448), UINT64_C(10324908911588227309) },
        { { UINT64_C(11515309317332436680) },
          { UINT64_C(17173717345411499448) },
          { UINT64_C(10324908911588227309) } },
    },
    { { UINT64_C(17551078789523829107), UINT64_C( 4173707111931242875), UINT64_C( 6656043646660321921) },
        { { UINT64_C(17551078789523829107) },
          { UINT64_C( 4173707111931242875) },
          { UINT64_C( 6656043646660321921) } },
    },
    { { UINT64_C(13744759886282611261), UINT64_C(11980333853544887587), UINT64_C(17174438060917616796) },
        { { UINT64_C(13744759886282611261) },
          { UINT64_C(11980333853544887587) },
          { UINT64_C(17174438060917616796) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1x3_t r = simde_vld1_u64_x3(test_vec[i].buf);
    simde_uint64x1x3_t expected = {{
        simde_vld1_u64(test_vec[i].expected[0]),
        simde_vld1_u64(test_vec[i].expected[1]),
        simde_vld1_u64(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_u64x1x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t buf[3];
    simde_test_codegen_random_memory(24, (uint8_t*)buf);
    simde_test_codegen_write_vu64(2, 3, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint64x1x3_t val = simde_vld1_u64_x3(buf);
    simde_test_arm_neon_write_u64x1x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_f32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_f64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u64_x3)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
