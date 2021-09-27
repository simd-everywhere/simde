#define SIMDE_TEST_ARM_NEON_INSN ld1q_x3
#include "test/test.h"
#include "test-neon.h"
#include "../../../simde/arm/neon/ld1q_x3.h"
#include "../../../simde/arm/neon/ld1_lane.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld1q_f32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 buf[12];
    simde_float32 expected[3][4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -189.04), SIMDE_FLOAT32_C(  -501.20), SIMDE_FLOAT32_C(  -610.52), SIMDE_FLOAT32_C(   268.30),
        SIMDE_FLOAT32_C(    97.68), SIMDE_FLOAT32_C(  -198.37), SIMDE_FLOAT32_C(   613.42), SIMDE_FLOAT32_C(   214.67),
        SIMDE_FLOAT32_C(   975.70), SIMDE_FLOAT32_C(  -301.04), SIMDE_FLOAT32_C(   751.55), SIMDE_FLOAT32_C(   570.88) },
        { { SIMDE_FLOAT32_C(  -189.04), SIMDE_FLOAT32_C(  -501.20), SIMDE_FLOAT32_C(  -610.52), SIMDE_FLOAT32_C(   268.30) },
          { SIMDE_FLOAT32_C(    97.68), SIMDE_FLOAT32_C(  -198.37), SIMDE_FLOAT32_C(   613.42), SIMDE_FLOAT32_C(   214.67) },
          { SIMDE_FLOAT32_C(   975.70), SIMDE_FLOAT32_C(  -301.04), SIMDE_FLOAT32_C(   751.55), SIMDE_FLOAT32_C(   570.88) } },
    },
    { { SIMDE_FLOAT32_C(  -976.75), SIMDE_FLOAT32_C(  -977.85), SIMDE_FLOAT32_C(   521.96), SIMDE_FLOAT32_C(  -701.67),
        SIMDE_FLOAT32_C(  -747.39), SIMDE_FLOAT32_C(    44.88), SIMDE_FLOAT32_C(    40.91), SIMDE_FLOAT32_C(   203.72),
        SIMDE_FLOAT32_C(   824.73), SIMDE_FLOAT32_C(   304.74), SIMDE_FLOAT32_C(   -49.61), SIMDE_FLOAT32_C(   807.59) },
        { { SIMDE_FLOAT32_C(  -976.75), SIMDE_FLOAT32_C(  -977.85), SIMDE_FLOAT32_C(   521.96), SIMDE_FLOAT32_C(  -701.67) },
          { SIMDE_FLOAT32_C(  -747.39), SIMDE_FLOAT32_C(    44.88), SIMDE_FLOAT32_C(    40.91), SIMDE_FLOAT32_C(   203.72) },
          { SIMDE_FLOAT32_C(   824.73), SIMDE_FLOAT32_C(   304.74), SIMDE_FLOAT32_C(   -49.61), SIMDE_FLOAT32_C(   807.59) } },
    },
    { { SIMDE_FLOAT32_C(  -462.00), SIMDE_FLOAT32_C(   612.39), SIMDE_FLOAT32_C(  -430.76), SIMDE_FLOAT32_C(   235.76),
        SIMDE_FLOAT32_C(   302.72), SIMDE_FLOAT32_C(  -623.60), SIMDE_FLOAT32_C(   852.23), SIMDE_FLOAT32_C(  -886.32),
        SIMDE_FLOAT32_C(  -124.81), SIMDE_FLOAT32_C(  -758.28), SIMDE_FLOAT32_C(   381.98), SIMDE_FLOAT32_C(   972.87) },
        { { SIMDE_FLOAT32_C(  -462.00), SIMDE_FLOAT32_C(   612.39), SIMDE_FLOAT32_C(  -430.76), SIMDE_FLOAT32_C(   235.76) },
          { SIMDE_FLOAT32_C(   302.72), SIMDE_FLOAT32_C(  -623.60), SIMDE_FLOAT32_C(   852.23), SIMDE_FLOAT32_C(  -886.32) },
          { SIMDE_FLOAT32_C(  -124.81), SIMDE_FLOAT32_C(  -758.28), SIMDE_FLOAT32_C(   381.98), SIMDE_FLOAT32_C(   972.87) } },
    },
    { { SIMDE_FLOAT32_C(    43.35), SIMDE_FLOAT32_C(    -4.60), SIMDE_FLOAT32_C(   187.55), SIMDE_FLOAT32_C(    19.05),
        SIMDE_FLOAT32_C(   694.36), SIMDE_FLOAT32_C(   -60.90), SIMDE_FLOAT32_C(  -410.07), SIMDE_FLOAT32_C(   717.61),
        SIMDE_FLOAT32_C(   -38.75), SIMDE_FLOAT32_C(  -888.11), SIMDE_FLOAT32_C(  -984.06), SIMDE_FLOAT32_C(   213.86) },
        { { SIMDE_FLOAT32_C(    43.35), SIMDE_FLOAT32_C(    -4.60), SIMDE_FLOAT32_C(   187.55), SIMDE_FLOAT32_C(    19.05) },
          { SIMDE_FLOAT32_C(   694.36), SIMDE_FLOAT32_C(   -60.90), SIMDE_FLOAT32_C(  -410.07), SIMDE_FLOAT32_C(   717.61) },
          { SIMDE_FLOAT32_C(   -38.75), SIMDE_FLOAT32_C(  -888.11), SIMDE_FLOAT32_C(  -984.06), SIMDE_FLOAT32_C(   213.86) } },
    },
    { { SIMDE_FLOAT32_C(   156.77), SIMDE_FLOAT32_C(    56.84), SIMDE_FLOAT32_C(  -582.42), SIMDE_FLOAT32_C(   -18.50),
        SIMDE_FLOAT32_C(  -638.42), SIMDE_FLOAT32_C(   367.97), SIMDE_FLOAT32_C(  -210.91), SIMDE_FLOAT32_C(  -100.41),
        SIMDE_FLOAT32_C(   -19.64), SIMDE_FLOAT32_C(   358.32), SIMDE_FLOAT32_C(  -864.65), SIMDE_FLOAT32_C(  -716.92) },
        { { SIMDE_FLOAT32_C(   156.77), SIMDE_FLOAT32_C(    56.84), SIMDE_FLOAT32_C(  -582.42), SIMDE_FLOAT32_C(   -18.50) },
          { SIMDE_FLOAT32_C(  -638.42), SIMDE_FLOAT32_C(   367.97), SIMDE_FLOAT32_C(  -210.91), SIMDE_FLOAT32_C(  -100.41) },
          { SIMDE_FLOAT32_C(   -19.64), SIMDE_FLOAT32_C(   358.32), SIMDE_FLOAT32_C(  -864.65), SIMDE_FLOAT32_C(  -716.92) } },
    },
    { { SIMDE_FLOAT32_C(   734.72), SIMDE_FLOAT32_C(   987.58), SIMDE_FLOAT32_C(  -603.24), SIMDE_FLOAT32_C(  -390.08),
        SIMDE_FLOAT32_C(  -770.70), SIMDE_FLOAT32_C(   778.73), SIMDE_FLOAT32_C(  -417.21), SIMDE_FLOAT32_C(   272.65),
        SIMDE_FLOAT32_C(  -225.87), SIMDE_FLOAT32_C(   770.34), SIMDE_FLOAT32_C(  -708.30), SIMDE_FLOAT32_C(  -531.50) },
        { { SIMDE_FLOAT32_C(   734.72), SIMDE_FLOAT32_C(   987.58), SIMDE_FLOAT32_C(  -603.24), SIMDE_FLOAT32_C(  -390.08) },
          { SIMDE_FLOAT32_C(  -770.70), SIMDE_FLOAT32_C(   778.73), SIMDE_FLOAT32_C(  -417.21), SIMDE_FLOAT32_C(   272.65) },
          { SIMDE_FLOAT32_C(  -225.87), SIMDE_FLOAT32_C(   770.34), SIMDE_FLOAT32_C(  -708.30), SIMDE_FLOAT32_C(  -531.50) } },
    },
    { { SIMDE_FLOAT32_C(  -290.56), SIMDE_FLOAT32_C(  -118.38), SIMDE_FLOAT32_C(  -813.89), SIMDE_FLOAT32_C(   670.68),
        SIMDE_FLOAT32_C(    -6.49), SIMDE_FLOAT32_C(  -797.96), SIMDE_FLOAT32_C(  -115.46), SIMDE_FLOAT32_C(  -849.72),
        SIMDE_FLOAT32_C(   258.89), SIMDE_FLOAT32_C(   302.13), SIMDE_FLOAT32_C(   131.78), SIMDE_FLOAT32_C(   620.47) },
        { { SIMDE_FLOAT32_C(  -290.56), SIMDE_FLOAT32_C(  -118.38), SIMDE_FLOAT32_C(  -813.89), SIMDE_FLOAT32_C(   670.68) },
          { SIMDE_FLOAT32_C(    -6.49), SIMDE_FLOAT32_C(  -797.96), SIMDE_FLOAT32_C(  -115.46), SIMDE_FLOAT32_C(  -849.72) },
          { SIMDE_FLOAT32_C(   258.89), SIMDE_FLOAT32_C(   302.13), SIMDE_FLOAT32_C(   131.78), SIMDE_FLOAT32_C(   620.47) } },
    },
    { { SIMDE_FLOAT32_C(  -329.90), SIMDE_FLOAT32_C(   920.86), SIMDE_FLOAT32_C(  -479.94), SIMDE_FLOAT32_C(   650.46),
        SIMDE_FLOAT32_C(   279.19), SIMDE_FLOAT32_C(  -344.59), SIMDE_FLOAT32_C(   933.54), SIMDE_FLOAT32_C(    13.91),
        SIMDE_FLOAT32_C(  -357.01), SIMDE_FLOAT32_C(  -669.71), SIMDE_FLOAT32_C(   623.83), SIMDE_FLOAT32_C(  -127.71) },
        { { SIMDE_FLOAT32_C(  -329.90), SIMDE_FLOAT32_C(   920.86), SIMDE_FLOAT32_C(  -479.94), SIMDE_FLOAT32_C(   650.46) },
          { SIMDE_FLOAT32_C(   279.19), SIMDE_FLOAT32_C(  -344.59), SIMDE_FLOAT32_C(   933.54), SIMDE_FLOAT32_C(    13.91) },
          { SIMDE_FLOAT32_C(  -357.01), SIMDE_FLOAT32_C(  -669.71), SIMDE_FLOAT32_C(   623.83), SIMDE_FLOAT32_C(  -127.71) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4x3_t r = simde_vld1q_f32_x3(test_vec[i].buf);
    simde_float32x4x3_t expected = {{
        simde_vld1q_f32(test_vec[i].expected[0]),
        simde_vld1q_f32(test_vec[i].expected[1]),
        simde_vld1q_f32(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_f32x4x3(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 buf[12];
    for (int j = 0 ; j < 12 ; j++) {
      buf[j] = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    }
    simde_test_codegen_write_vf32(2, 12, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32x4x3_t val = simde_vld1q_f32_x3(buf);
    simde_test_arm_neon_write_f32x4x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_f64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 buf[6];
    simde_float64 expected[3][2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -839.03), SIMDE_FLOAT64_C(  -242.94), SIMDE_FLOAT64_C(  -380.01), SIMDE_FLOAT64_C(    58.51),
        SIMDE_FLOAT64_C(  -674.80), SIMDE_FLOAT64_C(   471.34) },
        { { SIMDE_FLOAT64_C(  -839.03), SIMDE_FLOAT64_C(  -242.94) },
          { SIMDE_FLOAT64_C(  -380.01), SIMDE_FLOAT64_C(    58.51) },
          { SIMDE_FLOAT64_C(  -674.80), SIMDE_FLOAT64_C(   471.34) } },
    },
    { { SIMDE_FLOAT64_C(  -680.21), SIMDE_FLOAT64_C(   514.67), SIMDE_FLOAT64_C(  -105.76), SIMDE_FLOAT64_C(  -655.79),
        SIMDE_FLOAT64_C(   391.12), SIMDE_FLOAT64_C(  -903.23) },
        { { SIMDE_FLOAT64_C(  -680.21), SIMDE_FLOAT64_C(   514.67) },
          { SIMDE_FLOAT64_C(  -105.76), SIMDE_FLOAT64_C(  -655.79) },
          { SIMDE_FLOAT64_C(   391.12), SIMDE_FLOAT64_C(  -903.23) } },
    },
    { { SIMDE_FLOAT64_C(   467.18), SIMDE_FLOAT64_C(   181.64), SIMDE_FLOAT64_C(   788.89), SIMDE_FLOAT64_C(   161.74),
        SIMDE_FLOAT64_C(  -995.50), SIMDE_FLOAT64_C(  -878.21) },
        { { SIMDE_FLOAT64_C(   467.18), SIMDE_FLOAT64_C(   181.64) },
          { SIMDE_FLOAT64_C(   788.89), SIMDE_FLOAT64_C(   161.74) },
          { SIMDE_FLOAT64_C(  -995.50), SIMDE_FLOAT64_C(  -878.21) } },
    },
    { { SIMDE_FLOAT64_C(   447.09), SIMDE_FLOAT64_C(   368.01), SIMDE_FLOAT64_C(   153.35), SIMDE_FLOAT64_C(  -543.97),
        SIMDE_FLOAT64_C(   406.74), SIMDE_FLOAT64_C(  -589.94) },
        { { SIMDE_FLOAT64_C(   447.09), SIMDE_FLOAT64_C(   368.01) },
          { SIMDE_FLOAT64_C(   153.35), SIMDE_FLOAT64_C(  -543.97) },
          { SIMDE_FLOAT64_C(   406.74), SIMDE_FLOAT64_C(  -589.94) } },
    },
    { { SIMDE_FLOAT64_C(   873.06), SIMDE_FLOAT64_C(  -591.22), SIMDE_FLOAT64_C(   665.45), SIMDE_FLOAT64_C(  -720.55),
        SIMDE_FLOAT64_C(    15.92), SIMDE_FLOAT64_C(   746.00) },
        { { SIMDE_FLOAT64_C(   873.06), SIMDE_FLOAT64_C(  -591.22) },
          { SIMDE_FLOAT64_C(   665.45), SIMDE_FLOAT64_C(  -720.55) },
          { SIMDE_FLOAT64_C(    15.92), SIMDE_FLOAT64_C(   746.00) } },
    },
    { { SIMDE_FLOAT64_C(   448.25), SIMDE_FLOAT64_C(   176.90), SIMDE_FLOAT64_C(  -496.94), SIMDE_FLOAT64_C(  -931.76),
        SIMDE_FLOAT64_C(  -764.59), SIMDE_FLOAT64_C(  -171.74) },
        { { SIMDE_FLOAT64_C(   448.25), SIMDE_FLOAT64_C(   176.90) },
          { SIMDE_FLOAT64_C(  -496.94), SIMDE_FLOAT64_C(  -931.76) },
          { SIMDE_FLOAT64_C(  -764.59), SIMDE_FLOAT64_C(  -171.74) } },
    },
    { { SIMDE_FLOAT64_C(   539.58), SIMDE_FLOAT64_C(  -444.81), SIMDE_FLOAT64_C(  -657.06), SIMDE_FLOAT64_C(  -566.17),
        SIMDE_FLOAT64_C(  -100.59), SIMDE_FLOAT64_C(   734.06) },
        { { SIMDE_FLOAT64_C(   539.58), SIMDE_FLOAT64_C(  -444.81) },
          { SIMDE_FLOAT64_C(  -657.06), SIMDE_FLOAT64_C(  -566.17) },
          { SIMDE_FLOAT64_C(  -100.59), SIMDE_FLOAT64_C(   734.06) } },
    },
    { { SIMDE_FLOAT64_C(  -469.40), SIMDE_FLOAT64_C(  -633.41), SIMDE_FLOAT64_C(   -84.30), SIMDE_FLOAT64_C(  -680.51),
        SIMDE_FLOAT64_C(   528.32), SIMDE_FLOAT64_C(   -79.80) },
        { { SIMDE_FLOAT64_C(  -469.40), SIMDE_FLOAT64_C(  -633.41) },
          { SIMDE_FLOAT64_C(   -84.30), SIMDE_FLOAT64_C(  -680.51) },
          { SIMDE_FLOAT64_C(   528.32), SIMDE_FLOAT64_C(   -79.80) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2x3_t r = simde_vld1q_f64_x3(test_vec[i].buf);
    simde_float64x2x3_t expected = {{
        simde_vld1q_f64(test_vec[i].expected[0]),
        simde_vld1q_f64(test_vec[i].expected[1]),
        simde_vld1q_f64(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_f64x2x3(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 buf[6];
    for (int j = 0 ; j < 6 ; j++) {
      buf[j] = simde_test_codegen_random_f64(-1000.0, 1000.0);
    }
    simde_test_codegen_write_vf64(2, 6, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64x2x3_t val = simde_vld1q_f64_x3(buf);
    simde_test_arm_neon_write_f64x2x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s8_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t buf[48];
    int8_t expected[3][16];
  } test_vec[] = {
    { {  INT8_C(  91), -INT8_C( 113),  INT8_C( 126), -INT8_C(  17), -INT8_C(  20), -INT8_C(  74), -INT8_C(  87), -INT8_C(  25),
        -INT8_C(  24),  INT8_C(   4), -INT8_C(  16),  INT8_C(  20),  INT8_C(  68), -INT8_C( 100), -INT8_C( 101), -INT8_C(  30),
        -INT8_C(  87), -INT8_C(  70), -INT8_C(  62), -INT8_C(  37),  INT8_C(  59),  INT8_C(  27),  INT8_C(  69),  INT8_C(  45),
         INT8_C(  55),  INT8_C(  39), -INT8_C( 105),  INT8_C(  96),  INT8_C(  74),  INT8_C(  77), -INT8_C(  88), -INT8_C(  90),
        -INT8_C(  36),  INT8_C(  38), -INT8_C( 107), -INT8_C(  55), -INT8_C(  36),  INT8_C(  63), -INT8_C(  80), -INT8_C(  60),
         INT8_C(  67), -INT8_C(  96), -INT8_C(  40), -INT8_C( 120),  INT8_C(  60),  INT8_C( 115),  INT8_C( 106), -INT8_C(  26) },
        { {  INT8_C(  91), -INT8_C( 113),  INT8_C( 126), -INT8_C(  17), -INT8_C(  20), -INT8_C(  74), -INT8_C(  87), -INT8_C(  25),
            -INT8_C(  24),  INT8_C(   4), -INT8_C(  16),  INT8_C(  20),  INT8_C(  68), -INT8_C( 100), -INT8_C( 101), -INT8_C(  30) },
          { -INT8_C(  87), -INT8_C(  70), -INT8_C(  62), -INT8_C(  37),  INT8_C(  59),  INT8_C(  27),  INT8_C(  69),  INT8_C(  45),
             INT8_C(  55),  INT8_C(  39), -INT8_C( 105),  INT8_C(  96),  INT8_C(  74),  INT8_C(  77), -INT8_C(  88), -INT8_C(  90) },
          { -INT8_C(  36),  INT8_C(  38), -INT8_C( 107), -INT8_C(  55), -INT8_C(  36),  INT8_C(  63), -INT8_C(  80), -INT8_C(  60),
             INT8_C(  67), -INT8_C(  96), -INT8_C(  40), -INT8_C( 120),  INT8_C(  60),  INT8_C( 115),  INT8_C( 106), -INT8_C(  26) } },
    },
    { {  INT8_C(  45),  INT8_C(  44), -INT8_C(  63),  INT8_C( 105),  INT8_C(  71),  INT8_C(   7), -INT8_C( 106),      INT8_MAX,
         INT8_C(  46),  INT8_C(  45), -INT8_C(  33),  INT8_C( 121),  INT8_C( 122), -INT8_C( 121),  INT8_C(  31),  INT8_C(  86),
        -INT8_C(  83), -INT8_C(  76),  INT8_C(  31), -INT8_C( 118), -INT8_C(  13), -INT8_C(  49),  INT8_C(  78),  INT8_C(  55),
         INT8_C( 112),  INT8_C(  39), -INT8_C(  65), -INT8_C(  84), -INT8_C( 102),  INT8_C(  41), -INT8_C( 110), -INT8_C(  56),
         INT8_C(  85),  INT8_C(  84),  INT8_C(  49), -INT8_C(  99),  INT8_C(  91), -INT8_C(  57),  INT8_C(  28), -INT8_C( 119),
        -INT8_C(  12), -INT8_C(   5),  INT8_C(   2),  INT8_C( 110), -INT8_C( 125),  INT8_C(  33), -INT8_C(  60),  INT8_C(  48) },
        { {  INT8_C(  45),  INT8_C(  44), -INT8_C(  63),  INT8_C( 105),  INT8_C(  71),  INT8_C(   7), -INT8_C( 106),      INT8_MAX,
             INT8_C(  46),  INT8_C(  45), -INT8_C(  33),  INT8_C( 121),  INT8_C( 122), -INT8_C( 121),  INT8_C(  31),  INT8_C(  86) },
          { -INT8_C(  83), -INT8_C(  76),  INT8_C(  31), -INT8_C( 118), -INT8_C(  13), -INT8_C(  49),  INT8_C(  78),  INT8_C(  55),
             INT8_C( 112),  INT8_C(  39), -INT8_C(  65), -INT8_C(  84), -INT8_C( 102),  INT8_C(  41), -INT8_C( 110), -INT8_C(  56) },
          {  INT8_C(  85),  INT8_C(  84),  INT8_C(  49), -INT8_C(  99),  INT8_C(  91), -INT8_C(  57),  INT8_C(  28), -INT8_C( 119),
            -INT8_C(  12), -INT8_C(   5),  INT8_C(   2),  INT8_C( 110), -INT8_C( 125),  INT8_C(  33), -INT8_C(  60),  INT8_C(  48) } },
    },
    { { -INT8_C(  42), -INT8_C(  28), -INT8_C(  70), -INT8_C(  55), -INT8_C(  77),  INT8_C(   9),  INT8_C(   0),  INT8_C(  35),
         INT8_C(  48), -INT8_C(  65), -INT8_C(  48), -INT8_C(  54), -INT8_C(  24),  INT8_C(  98), -INT8_C( 110),  INT8_C(  62),
        -INT8_C(  74), -INT8_C(  61), -INT8_C(  37),  INT8_C(  17), -INT8_C( 118), -INT8_C(   9), -INT8_C( 101),  INT8_C( 126),
        -INT8_C(  14), -INT8_C(  99), -INT8_C(  20),  INT8_C( 117), -INT8_C(  65), -INT8_C(  79), -INT8_C(  90), -INT8_C( 107),
        -INT8_C( 107),  INT8_C(  96),  INT8_C(  94),  INT8_C(  72),  INT8_C( 105),  INT8_C(  95),  INT8_C( 108), -INT8_C( 103),
         INT8_C(  30),  INT8_C(  60),  INT8_C( 100),  INT8_C(   7), -INT8_C(  98), -INT8_C(  10),  INT8_C(  69),  INT8_C(  85) },
        { { -INT8_C(  42), -INT8_C(  28), -INT8_C(  70), -INT8_C(  55), -INT8_C(  77),  INT8_C(   9),  INT8_C(   0),  INT8_C(  35),
             INT8_C(  48), -INT8_C(  65), -INT8_C(  48), -INT8_C(  54), -INT8_C(  24),  INT8_C(  98), -INT8_C( 110),  INT8_C(  62) },
          { -INT8_C(  74), -INT8_C(  61), -INT8_C(  37),  INT8_C(  17), -INT8_C( 118), -INT8_C(   9), -INT8_C( 101),  INT8_C( 126),
            -INT8_C(  14), -INT8_C(  99), -INT8_C(  20),  INT8_C( 117), -INT8_C(  65), -INT8_C(  79), -INT8_C(  90), -INT8_C( 107) },
          { -INT8_C( 107),  INT8_C(  96),  INT8_C(  94),  INT8_C(  72),  INT8_C( 105),  INT8_C(  95),  INT8_C( 108), -INT8_C( 103),
             INT8_C(  30),  INT8_C(  60),  INT8_C( 100),  INT8_C(   7), -INT8_C(  98), -INT8_C(  10),  INT8_C(  69),  INT8_C(  85) } },
    },
    { { -INT8_C(  70),  INT8_C(  32),  INT8_C( 102),  INT8_C(  68),  INT8_C(  23),  INT8_C(   1), -INT8_C(  61),  INT8_C(   9),
        -INT8_C(  97), -INT8_C(  81),      INT8_MAX,  INT8_C(  94),  INT8_C(  96),  INT8_C(  37), -INT8_C(  13), -INT8_C(  11),
        -INT8_C( 123),  INT8_C(  81),  INT8_C(  62), -INT8_C(  17), -INT8_C(  80), -INT8_C(  86), -INT8_C( 120), -INT8_C(  49),
        -INT8_C(  26), -INT8_C(  20), -INT8_C(  42), -INT8_C( 124), -INT8_C(  29),  INT8_C(  27), -INT8_C(  39), -INT8_C(  99),
         INT8_C(  59),  INT8_C(  64), -INT8_C(  31),  INT8_C(  82),  INT8_C(  65), -INT8_C(  92),  INT8_C(  91), -INT8_C(  32),
         INT8_C(  84), -INT8_C(  38),  INT8_C(  62), -INT8_C(  76), -INT8_C(   1),  INT8_C(  49), -INT8_C(  86), -INT8_C( 123) },
        { { -INT8_C(  70),  INT8_C(  32),  INT8_C( 102),  INT8_C(  68),  INT8_C(  23),  INT8_C(   1), -INT8_C(  61),  INT8_C(   9),
            -INT8_C(  97), -INT8_C(  81),      INT8_MAX,  INT8_C(  94),  INT8_C(  96),  INT8_C(  37), -INT8_C(  13), -INT8_C(  11) },
          { -INT8_C( 123),  INT8_C(  81),  INT8_C(  62), -INT8_C(  17), -INT8_C(  80), -INT8_C(  86), -INT8_C( 120), -INT8_C(  49),
            -INT8_C(  26), -INT8_C(  20), -INT8_C(  42), -INT8_C( 124), -INT8_C(  29),  INT8_C(  27), -INT8_C(  39), -INT8_C(  99) },
          {  INT8_C(  59),  INT8_C(  64), -INT8_C(  31),  INT8_C(  82),  INT8_C(  65), -INT8_C(  92),  INT8_C(  91), -INT8_C(  32),
             INT8_C(  84), -INT8_C(  38),  INT8_C(  62), -INT8_C(  76), -INT8_C(   1),  INT8_C(  49), -INT8_C(  86), -INT8_C( 123) } },
    },
    { { -INT8_C( 125), -INT8_C(  24),  INT8_C( 116),  INT8_C(  51), -INT8_C( 110), -INT8_C(   4),  INT8_C(   2),  INT8_C( 120),
        -INT8_C(  23), -INT8_C(  40), -INT8_C(   4), -INT8_C(  52), -INT8_C(  13), -INT8_C(  42),  INT8_C( 105),  INT8_C(  46),
         INT8_C(  22),  INT8_C(  74),      INT8_MIN,  INT8_C(  87), -INT8_C(  17), -INT8_C(  36),  INT8_C(  56),  INT8_C(  67),
        -INT8_C(  74),  INT8_C( 118), -INT8_C(   9), -INT8_C(  74), -INT8_C(  88), -INT8_C(  95),  INT8_C(  59),  INT8_C(  43),
        -INT8_C( 119), -INT8_C(  81),  INT8_C(  94),  INT8_C(  27), -INT8_C(  85),  INT8_C(  97), -INT8_C( 109), -INT8_C( 108),
         INT8_C(  57), -INT8_C( 112),  INT8_C(  96),  INT8_C(  45),  INT8_C( 102), -INT8_C(  55),  INT8_C(  91),  INT8_C( 124) },
        { { -INT8_C( 125), -INT8_C(  24),  INT8_C( 116),  INT8_C(  51), -INT8_C( 110), -INT8_C(   4),  INT8_C(   2),  INT8_C( 120),
            -INT8_C(  23), -INT8_C(  40), -INT8_C(   4), -INT8_C(  52), -INT8_C(  13), -INT8_C(  42),  INT8_C( 105),  INT8_C(  46) },
          {  INT8_C(  22),  INT8_C(  74),      INT8_MIN,  INT8_C(  87), -INT8_C(  17), -INT8_C(  36),  INT8_C(  56),  INT8_C(  67),
            -INT8_C(  74),  INT8_C( 118), -INT8_C(   9), -INT8_C(  74), -INT8_C(  88), -INT8_C(  95),  INT8_C(  59),  INT8_C(  43) },
          { -INT8_C( 119), -INT8_C(  81),  INT8_C(  94),  INT8_C(  27), -INT8_C(  85),  INT8_C(  97), -INT8_C( 109), -INT8_C( 108),
             INT8_C(  57), -INT8_C( 112),  INT8_C(  96),  INT8_C(  45),  INT8_C( 102), -INT8_C(  55),  INT8_C(  91),  INT8_C( 124) } },
    },
    { {  INT8_C(  20), -INT8_C(  36), -INT8_C(  45),  INT8_C(   3), -INT8_C(  72),  INT8_C(  11),  INT8_C(  70),  INT8_C( 110),
        -INT8_C( 126),  INT8_C(  61),  INT8_C(  36),  INT8_C(  42), -INT8_C(  33),  INT8_C(  95),  INT8_C(  85),  INT8_C( 104),
         INT8_C(  14), -INT8_C(  77), -INT8_C( 124), -INT8_C(  70),  INT8_C(  20),  INT8_C(  23),  INT8_C(  78),  INT8_C(  78),
        -INT8_C(  89), -INT8_C(  81),  INT8_C( 123),  INT8_C(  13),  INT8_C( 120), -INT8_C(  42), -INT8_C( 119), -INT8_C( 116),
        -INT8_C(  78),  INT8_C(  93), -INT8_C( 113),  INT8_C( 106),  INT8_C( 104), -INT8_C(  43), -INT8_C(  39), -INT8_C(  22),
         INT8_C(  19), -INT8_C(   3),  INT8_C(  20), -INT8_C(  14),  INT8_C(  93),  INT8_C( 105),  INT8_C(  90),  INT8_C( 107) },
        { {  INT8_C(  20), -INT8_C(  36), -INT8_C(  45),  INT8_C(   3), -INT8_C(  72),  INT8_C(  11),  INT8_C(  70),  INT8_C( 110),
            -INT8_C( 126),  INT8_C(  61),  INT8_C(  36),  INT8_C(  42), -INT8_C(  33),  INT8_C(  95),  INT8_C(  85),  INT8_C( 104) },
          {  INT8_C(  14), -INT8_C(  77), -INT8_C( 124), -INT8_C(  70),  INT8_C(  20),  INT8_C(  23),  INT8_C(  78),  INT8_C(  78),
            -INT8_C(  89), -INT8_C(  81),  INT8_C( 123),  INT8_C(  13),  INT8_C( 120), -INT8_C(  42), -INT8_C( 119), -INT8_C( 116) },
          { -INT8_C(  78),  INT8_C(  93), -INT8_C( 113),  INT8_C( 106),  INT8_C( 104), -INT8_C(  43), -INT8_C(  39), -INT8_C(  22),
             INT8_C(  19), -INT8_C(   3),  INT8_C(  20), -INT8_C(  14),  INT8_C(  93),  INT8_C( 105),  INT8_C(  90),  INT8_C( 107) } },
    },
    { {  INT8_C(  29), -INT8_C(  34),  INT8_C(  37),  INT8_C(  49), -INT8_C(  10),  INT8_C( 116),      INT8_MAX, -INT8_C(  99),
         INT8_C(  35), -INT8_C(   6), -INT8_C(  85), -INT8_C( 101), -INT8_C(  47),  INT8_C(  52),  INT8_C(  40), -INT8_C( 125),
        -INT8_C( 111), -INT8_C(  73), -INT8_C(  18), -INT8_C(   6), -INT8_C( 115), -INT8_C(  57), -INT8_C(  28), -INT8_C(  96),
        -INT8_C(  60), -INT8_C(   7), -INT8_C( 110),  INT8_C(  33),  INT8_C(  98), -INT8_C(  20), -INT8_C( 115),      INT8_MAX,
        -INT8_C(  53), -INT8_C(  78), -INT8_C(  79), -INT8_C(  63),  INT8_C(  38),  INT8_C(  48),  INT8_C(  94),  INT8_C(  73),
         INT8_C(  43),  INT8_C(   9), -INT8_C(  27), -INT8_C(   4),  INT8_C(  62),  INT8_C(  13),      INT8_MAX, -INT8_C(  49) },
        { {  INT8_C(  29), -INT8_C(  34),  INT8_C(  37),  INT8_C(  49), -INT8_C(  10),  INT8_C( 116),      INT8_MAX, -INT8_C(  99),
             INT8_C(  35), -INT8_C(   6), -INT8_C(  85), -INT8_C( 101), -INT8_C(  47),  INT8_C(  52),  INT8_C(  40), -INT8_C( 125) },
          { -INT8_C( 111), -INT8_C(  73), -INT8_C(  18), -INT8_C(   6), -INT8_C( 115), -INT8_C(  57), -INT8_C(  28), -INT8_C(  96),
            -INT8_C(  60), -INT8_C(   7), -INT8_C( 110),  INT8_C(  33),  INT8_C(  98), -INT8_C(  20), -INT8_C( 115),      INT8_MAX },
          { -INT8_C(  53), -INT8_C(  78), -INT8_C(  79), -INT8_C(  63),  INT8_C(  38),  INT8_C(  48),  INT8_C(  94),  INT8_C(  73),
             INT8_C(  43),  INT8_C(   9), -INT8_C(  27), -INT8_C(   4),  INT8_C(  62),  INT8_C(  13),      INT8_MAX, -INT8_C(  49) } },
    },
    { { -INT8_C(  60),  INT8_C( 109), -INT8_C(  55),  INT8_C(  81),  INT8_C(  52), -INT8_C(  82), -INT8_C(  15), -INT8_C(   7),
        -INT8_C(  89), -INT8_C( 125),  INT8_C(  26),  INT8_C(   9),  INT8_C( 112), -INT8_C(  89), -INT8_C( 119),  INT8_C(  59),
         INT8_C(  90),  INT8_C(  58), -INT8_C(   4),      INT8_MIN,  INT8_C( 106),  INT8_C(  90), -INT8_C(  54), -INT8_C( 107),
         INT8_C( 100), -INT8_C(  81), -INT8_C( 111), -INT8_C(  94), -INT8_C(  68),  INT8_C(  17),  INT8_C( 113),      INT8_MIN,
         INT8_C( 126),  INT8_C(  59), -INT8_C(  46), -INT8_C(  77), -INT8_C(  23), -INT8_C(  61), -INT8_C(  84), -INT8_C( 112),
         INT8_C(  71), -INT8_C(  58), -INT8_C( 103), -INT8_C(  73),  INT8_C( 110),  INT8_C(  34), -INT8_C(  14), -INT8_C(  56) },
        { { -INT8_C(  60),  INT8_C( 109), -INT8_C(  55),  INT8_C(  81),  INT8_C(  52), -INT8_C(  82), -INT8_C(  15), -INT8_C(   7),
            -INT8_C(  89), -INT8_C( 125),  INT8_C(  26),  INT8_C(   9),  INT8_C( 112), -INT8_C(  89), -INT8_C( 119),  INT8_C(  59) },
          {  INT8_C(  90),  INT8_C(  58), -INT8_C(   4),      INT8_MIN,  INT8_C( 106),  INT8_C(  90), -INT8_C(  54), -INT8_C( 107),
             INT8_C( 100), -INT8_C(  81), -INT8_C( 111), -INT8_C(  94), -INT8_C(  68),  INT8_C(  17),  INT8_C( 113),      INT8_MIN },
          {  INT8_C( 126),  INT8_C(  59), -INT8_C(  46), -INT8_C(  77), -INT8_C(  23), -INT8_C(  61), -INT8_C(  84), -INT8_C( 112),
             INT8_C(  71), -INT8_C(  58), -INT8_C( 103), -INT8_C(  73),  INT8_C( 110),  INT8_C(  34), -INT8_C(  14), -INT8_C(  56) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16x3_t r = simde_vld1q_s8_x3(test_vec[i].buf);
    simde_int8x16x3_t expected = {{
        simde_vld1q_s8(test_vec[i].expected[0]),
        simde_vld1q_s8(test_vec[i].expected[1]),
        simde_vld1q_s8(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_i8x16x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int8_t buf[48];
    simde_test_codegen_random_memory(48, (uint8_t*)buf);
    simde_test_codegen_write_vi8(2, 48, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int8x16x3_t val = simde_vld1q_s8_x3(buf);
    simde_test_arm_neon_write_i8x16x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t buf[24];
    int16_t expected[3][8];
  } test_vec[] = {
    { {  INT16_C( 19282),  INT16_C( 16982), -INT16_C( 22135),  INT16_C( 17215), -INT16_C(   599), -INT16_C( 14865), -INT16_C( 20968), -INT16_C( 16165),
         INT16_C( 31741),  INT16_C(  6953),  INT16_C(  4426), -INT16_C( 26976),  INT16_C( 25311), -INT16_C( 14877),  INT16_C( 11458),  INT16_C(  5142),
         INT16_C( 27767),  INT16_C(    86), -INT16_C( 27370), -INT16_C( 16572),  INT16_C( 13203), -INT16_C( 21628),  INT16_C( 24545), -INT16_C(  8341) },
        { {  INT16_C( 19282),  INT16_C( 16982), -INT16_C( 22135),  INT16_C( 17215), -INT16_C(   599), -INT16_C( 14865), -INT16_C( 20968), -INT16_C( 16165) },
          {  INT16_C( 31741),  INT16_C(  6953),  INT16_C(  4426), -INT16_C( 26976),  INT16_C( 25311), -INT16_C( 14877),  INT16_C( 11458),  INT16_C(  5142) },
          {  INT16_C( 27767),  INT16_C(    86), -INT16_C( 27370), -INT16_C( 16572),  INT16_C( 13203), -INT16_C( 21628),  INT16_C( 24545), -INT16_C(  8341) } },
    },
    { { -INT16_C( 27174),  INT16_C(  9722), -INT16_C( 25946), -INT16_C( 31045), -INT16_C( 24835), -INT16_C( 16565),  INT16_C( 25034),  INT16_C( 17107),
         INT16_C( 10957), -INT16_C(  7358), -INT16_C( 31041),  INT16_C( 21154),  INT16_C( 10169), -INT16_C( 25603),  INT16_C( 27014),  INT16_C( 24954),
         INT16_C( 29950), -INT16_C( 23418),  INT16_C( 16654),  INT16_C(  2858),  INT16_C( 30176), -INT16_C( 21814), -INT16_C( 24874), -INT16_C( 23316) },
        { { -INT16_C( 27174),  INT16_C(  9722), -INT16_C( 25946), -INT16_C( 31045), -INT16_C( 24835), -INT16_C( 16565),  INT16_C( 25034),  INT16_C( 17107) },
          {  INT16_C( 10957), -INT16_C(  7358), -INT16_C( 31041),  INT16_C( 21154),  INT16_C( 10169), -INT16_C( 25603),  INT16_C( 27014),  INT16_C( 24954) },
          {  INT16_C( 29950), -INT16_C( 23418),  INT16_C( 16654),  INT16_C(  2858),  INT16_C( 30176), -INT16_C( 21814), -INT16_C( 24874), -INT16_C( 23316) } },
    },
    { {  INT16_C( 12232), -INT16_C( 30841),  INT16_C( 10933),  INT16_C( 28634), -INT16_C( 10415), -INT16_C( 10486), -INT16_C( 31680),  INT16_C( 15928),
        -INT16_C( 16648),  INT16_C(  1763),  INT16_C(  3328), -INT16_C(  8174), -INT16_C(  9085),  INT16_C( 22922),  INT16_C( 30586),  INT16_C( 17149),
        -INT16_C( 31322),  INT16_C( 23498), -INT16_C( 23377),  INT16_C(   202), -INT16_C( 11141), -INT16_C( 17193),  INT16_C(  4184),  INT16_C( 20730) },
        { {  INT16_C( 12232), -INT16_C( 30841),  INT16_C( 10933),  INT16_C( 28634), -INT16_C( 10415), -INT16_C( 10486), -INT16_C( 31680),  INT16_C( 15928) },
          { -INT16_C( 16648),  INT16_C(  1763),  INT16_C(  3328), -INT16_C(  8174), -INT16_C(  9085),  INT16_C( 22922),  INT16_C( 30586),  INT16_C( 17149) },
          { -INT16_C( 31322),  INT16_C( 23498), -INT16_C( 23377),  INT16_C(   202), -INT16_C( 11141), -INT16_C( 17193),  INT16_C(  4184),  INT16_C( 20730) } },
    },
    { { -INT16_C(  8754), -INT16_C( 12713),  INT16_C( 27115),  INT16_C( 28334),  INT16_C( 14661), -INT16_C( 16185), -INT16_C( 14928),  INT16_C( 22018),
        -INT16_C( 13238), -INT16_C(  1615),  INT16_C( 31856), -INT16_C(  4871), -INT16_C( 12208), -INT16_C( 22104), -INT16_C( 23840), -INT16_C( 20487),
         INT16_C( 20608),  INT16_C( 27517),  INT16_C( 11449), -INT16_C(    39), -INT16_C( 24475),  INT16_C(  5567), -INT16_C( 16027), -INT16_C( 20629) },
        { { -INT16_C(  8754), -INT16_C( 12713),  INT16_C( 27115),  INT16_C( 28334),  INT16_C( 14661), -INT16_C( 16185), -INT16_C( 14928),  INT16_C( 22018) },
          { -INT16_C( 13238), -INT16_C(  1615),  INT16_C( 31856), -INT16_C(  4871), -INT16_C( 12208), -INT16_C( 22104), -INT16_C( 23840), -INT16_C( 20487) },
          {  INT16_C( 20608),  INT16_C( 27517),  INT16_C( 11449), -INT16_C(    39), -INT16_C( 24475),  INT16_C(  5567), -INT16_C( 16027), -INT16_C( 20629) } },
    },
    { {  INT16_C(  7310), -INT16_C(   344), -INT16_C( 24168), -INT16_C(  5654), -INT16_C( 28046),  INT16_C( 21138), -INT16_C( 29899), -INT16_C( 19199),
         INT16_C( 32732), -INT16_C( 27360), -INT16_C(  1621),  INT16_C(  4244),  INT16_C( 21401), -INT16_C(   219), -INT16_C( 28651), -INT16_C( 23634),
         INT16_C( 22444),  INT16_C( 17825), -INT16_C( 29448),  INT16_C( 27182), -INT16_C( 16354),  INT16_C( 21437), -INT16_C( 16821),  INT16_C(  9992) },
        { {  INT16_C(  7310), -INT16_C(   344), -INT16_C( 24168), -INT16_C(  5654), -INT16_C( 28046),  INT16_C( 21138), -INT16_C( 29899), -INT16_C( 19199) },
          {  INT16_C( 32732), -INT16_C( 27360), -INT16_C(  1621),  INT16_C(  4244),  INT16_C( 21401), -INT16_C(   219), -INT16_C( 28651), -INT16_C( 23634) },
          {  INT16_C( 22444),  INT16_C( 17825), -INT16_C( 29448),  INT16_C( 27182), -INT16_C( 16354),  INT16_C( 21437), -INT16_C( 16821),  INT16_C(  9992) } },
    },
    { {  INT16_C( 10301), -INT16_C(  5955),  INT16_C( 20769), -INT16_C( 17416),  INT16_C(  7589), -INT16_C( 17734),  INT16_C( 26797),  INT16_C( 23133),
        -INT16_C(   321), -INT16_C( 18273), -INT16_C( 12918), -INT16_C( 22238), -INT16_C(  8307), -INT16_C(  9988),  INT16_C(  1438), -INT16_C(  9472),
        -INT16_C( 17107),  INT16_C( 20420), -INT16_C( 17394), -INT16_C( 19702), -INT16_C( 15142), -INT16_C( 30867), -INT16_C( 13780), -INT16_C(  4895) },
        { {  INT16_C( 10301), -INT16_C(  5955),  INT16_C( 20769), -INT16_C( 17416),  INT16_C(  7589), -INT16_C( 17734),  INT16_C( 26797),  INT16_C( 23133) },
          { -INT16_C(   321), -INT16_C( 18273), -INT16_C( 12918), -INT16_C( 22238), -INT16_C(  8307), -INT16_C(  9988),  INT16_C(  1438), -INT16_C(  9472) },
          { -INT16_C( 17107),  INT16_C( 20420), -INT16_C( 17394), -INT16_C( 19702), -INT16_C( 15142), -INT16_C( 30867), -INT16_C( 13780), -INT16_C(  4895) } },
    },
    { { -INT16_C( 32567),  INT16_C( 21412), -INT16_C( 14771), -INT16_C(  9476), -INT16_C(  1626),  INT16_C( 17587), -INT16_C( 19458),  INT16_C( 11039),
        -INT16_C(  7312),  INT16_C( 32378), -INT16_C( 31584),  INT16_C( 31282), -INT16_C( 24760),  INT16_C( 29953), -INT16_C(  7318),  INT16_C( 13153),
         INT16_C(  1379), -INT16_C( 20090), -INT16_C( 31797),  INT16_C( 29067),  INT16_C( 15996),  INT16_C( 31413), -INT16_C( 10767),  INT16_C( 24997) },
        { { -INT16_C( 32567),  INT16_C( 21412), -INT16_C( 14771), -INT16_C(  9476), -INT16_C(  1626),  INT16_C( 17587), -INT16_C( 19458),  INT16_C( 11039) },
          { -INT16_C(  7312),  INT16_C( 32378), -INT16_C( 31584),  INT16_C( 31282), -INT16_C( 24760),  INT16_C( 29953), -INT16_C(  7318),  INT16_C( 13153) },
          {  INT16_C(  1379), -INT16_C( 20090), -INT16_C( 31797),  INT16_C( 29067),  INT16_C( 15996),  INT16_C( 31413), -INT16_C( 10767),  INT16_C( 24997) } },
    },
    { {  INT16_C(  8376),  INT16_C( 22752),  INT16_C(  4772), -INT16_C(  4654), -INT16_C( 11087),  INT16_C(  7010), -INT16_C( 15433),  INT16_C(  6734),
        -INT16_C( 10808), -INT16_C( 27701),  INT16_C( 22360), -INT16_C( 11259), -INT16_C( 17771), -INT16_C( 30898), -INT16_C(  3185),  INT16_C( 18664),
        -INT16_C( 14317), -INT16_C( 18272),  INT16_C( 29658), -INT16_C( 29531),  INT16_C(  1863), -INT16_C(   345), -INT16_C(  2358), -INT16_C( 28136) },
        { {  INT16_C(  8376),  INT16_C( 22752),  INT16_C(  4772), -INT16_C(  4654), -INT16_C( 11087),  INT16_C(  7010), -INT16_C( 15433),  INT16_C(  6734) },
          { -INT16_C( 10808), -INT16_C( 27701),  INT16_C( 22360), -INT16_C( 11259), -INT16_C( 17771), -INT16_C( 30898), -INT16_C(  3185),  INT16_C( 18664) },
          { -INT16_C( 14317), -INT16_C( 18272),  INT16_C( 29658), -INT16_C( 29531),  INT16_C(  1863), -INT16_C(   345), -INT16_C(  2358), -INT16_C( 28136) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8x3_t r = simde_vld1q_s16_x3(test_vec[i].buf);
    simde_int16x8x3_t expected = {{
        simde_vld1q_s16(test_vec[i].expected[0]),
        simde_vld1q_s16(test_vec[i].expected[1]),
        simde_vld1q_s16(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_i16x8x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int16_t buf[24];
    simde_test_codegen_random_memory(48, (uint8_t*)buf);
    simde_test_codegen_write_vi16(2, 24, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int16x8x3_t val = simde_vld1q_s16_x3(buf);
    simde_test_arm_neon_write_i16x8x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t buf[12];
    int32_t expected[3][4];
  } test_vec[] = {
    { {  INT32_C(   589685963), -INT32_C(   789108165),  INT32_C(  1951876581),  INT32_C(  1287405624), -INT32_C(   486253304),  INT32_C(   393193936),  INT32_C(  2048202416), -INT32_C(   687067892),
         INT32_C(  1291464977),  INT32_C(  1092481372),  INT32_C(  1874162742), -INT32_C(  1111788876) },
        { {  INT32_C(   589685963), -INT32_C(   789108165),  INT32_C(  1951876581),  INT32_C(  1287405624) },
          { -INT32_C(   486253304),  INT32_C(   393193936),  INT32_C(  2048202416), -INT32_C(   687067892) },
          {  INT32_C(  1291464977),  INT32_C(  1092481372),  INT32_C(  1874162742), -INT32_C(  1111788876) } },
    },
    { { -INT32_C(  1616855089),  INT32_C(   414584680),  INT32_C(   848481061),  INT32_C(   168402680),  INT32_C(   727057615),  INT32_C(   745305077), -INT32_C(  1667554584),  INT32_C(  1666799252),
         INT32_C(  2097346837),  INT32_C(   781563912),  INT32_C(  2069899139), -INT32_C(  1803195963) },
        { { -INT32_C(  1616855089),  INT32_C(   414584680),  INT32_C(   848481061),  INT32_C(   168402680) },
          {  INT32_C(   727057615),  INT32_C(   745305077), -INT32_C(  1667554584),  INT32_C(  1666799252) },
          {  INT32_C(  2097346837),  INT32_C(   781563912),  INT32_C(  2069899139), -INT32_C(  1803195963) } },
    },
    { {  INT32_C(  1673583725),  INT32_C(   932129871), -INT32_C(   489412018), -INT32_C(  1790628480),  INT32_C(   789727015), -INT32_C(  2107791361), -INT32_C(  1812021810), -INT32_C(  1809349849),
        -INT32_C(  1342707873),  INT32_C(  1659274772),  INT32_C(   809876144),  INT32_C(   264604392) },
        { {  INT32_C(  1673583725),  INT32_C(   932129871), -INT32_C(   489412018), -INT32_C(  1790628480) },
          {  INT32_C(   789727015), -INT32_C(  2107791361), -INT32_C(  1812021810), -INT32_C(  1809349849) },
          { -INT32_C(  1342707873),  INT32_C(  1659274772),  INT32_C(   809876144),  INT32_C(   264604392) } },
    },
    { { -INT32_C(   784410670),  INT32_C(  1280613502), -INT32_C(  2132848039),  INT32_C(   890570709),  INT32_C(    48499950),  INT32_C(  1130744467),  INT32_C(  1836362373),  INT32_C(   108804404),
        -INT32_C(  1881621999), -INT32_C(  1327748010),  INT32_C(  1395702654), -INT32_C(  1316469310) },
        { { -INT32_C(   784410670),  INT32_C(  1280613502), -INT32_C(  2132848039),  INT32_C(   890570709) },
          {  INT32_C(    48499950),  INT32_C(  1130744467),  INT32_C(  1836362373),  INT32_C(   108804404) },
          { -INT32_C(  1881621999), -INT32_C(  1327748010),  INT32_C(  1395702654), -INT32_C(  1316469310) } },
    },
    { { -INT32_C(   441226158), -INT32_C(  1138223049), -INT32_C(   148267838), -INT32_C(   402807338), -INT32_C(  1233726113),  INT32_C(  2137412097), -INT32_C(   791439858),  INT32_C(   780229596),
        -INT32_C(    15518264),  INT32_C(   280705869), -INT32_C(  1375214376), -INT32_C(   392887159) },
        { { -INT32_C(   441226158), -INT32_C(  1138223049), -INT32_C(   148267838), -INT32_C(   402807338) },
          { -INT32_C(  1233726113),  INT32_C(  2137412097), -INT32_C(   791439858),  INT32_C(   780229596) },
          { -INT32_C(    15518264),  INT32_C(   280705869), -INT32_C(  1375214376), -INT32_C(   392887159) } },
    },
    { { -INT32_C(   610399270),  INT32_C(  1817904222),  INT32_C(  2000432795),  INT32_C(  1369816713),  INT32_C(  1079032051), -INT32_C(   883946509),  INT32_C(  2021218287),  INT32_C(   912330332),
         INT32_C(  2014445338), -INT32_C(  1612420092),  INT32_C(   605429914), -INT32_C(   780813346) },
        { { -INT32_C(   610399270),  INT32_C(  1817904222),  INT32_C(  2000432795),  INT32_C(  1369816713) },
          {  INT32_C(  1079032051), -INT32_C(   883946509),  INT32_C(  2021218287),  INT32_C(   912330332) },
          {  INT32_C(  2014445338), -INT32_C(  1612420092),  INT32_C(   605429914), -INT32_C(   780813346) } },
    },
    { {  INT32_C(  1712506483), -INT32_C(  1053662511),  INT32_C(   372878266), -INT32_C(   733177158), -INT32_C(  1639162470),  INT32_C(  1681731786),  INT32_C(   797463376), -INT32_C(  2130641394),
        -INT32_C(  1780018492),  INT32_C(   794171765),  INT32_C(  2135265477), -INT32_C(  1001156310) },
        { {  INT32_C(  1712506483), -INT32_C(  1053662511),  INT32_C(   372878266), -INT32_C(   733177158) },
          { -INT32_C(  1639162470),  INT32_C(  1681731786),  INT32_C(   797463376), -INT32_C(  2130641394) },
          { -INT32_C(  1780018492),  INT32_C(   794171765),  INT32_C(  2135265477), -INT32_C(  1001156310) } },
    },
    { { -INT32_C(  1201496082),  INT32_C(   522035151),  INT32_C(     5154290),  INT32_C(  1736527779), -INT32_C(   688035487),  INT32_C(  1191531394),  INT32_C(   247876323), -INT32_C(   892200485),
        -INT32_C(  2021509704), -INT32_C(   945315884), -INT32_C(   389548731), -INT32_C(  1504687804) },
        { { -INT32_C(  1201496082),  INT32_C(   522035151),  INT32_C(     5154290),  INT32_C(  1736527779) },
          { -INT32_C(   688035487),  INT32_C(  1191531394),  INT32_C(   247876323), -INT32_C(   892200485) },
          { -INT32_C(  2021509704), -INT32_C(   945315884), -INT32_C(   389548731), -INT32_C(  1504687804) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4x3_t r = simde_vld1q_s32_x3(test_vec[i].buf);
    simde_int32x4x3_t expected = {{
        simde_vld1q_s32(test_vec[i].expected[0]),
        simde_vld1q_s32(test_vec[i].expected[1]),
        simde_vld1q_s32(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_i32x4x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int32_t buf[12];
    simde_test_codegen_random_memory(48, (uint8_t*)buf);
    simde_test_codegen_write_vi32(2, 12, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int32x4x3_t val = simde_vld1q_s32_x3(buf);
    simde_test_arm_neon_write_i32x4x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t buf[6];
    int64_t expected[3][2];
  } test_vec[] = {
    { { -INT64_C( 8900095139004002894),  INT64_C( 1473350377231499980), -INT64_C( 2795253688923523943), -INT64_C(  638647731996197832),
        -INT64_C( 1259978606765105314),  INT64_C( 1394717826569606634) },
        { { -INT64_C( 8900095139004002894),  INT64_C( 1473350377231499980) },
          { -INT64_C( 2795253688923523943), -INT64_C(  638647731996197832) },
          { -INT64_C( 1259978606765105314),  INT64_C( 1394717826569606634) } },
    },
    { {  INT64_C( 8244320955527198716), -INT64_C( 7210524425313113166), -INT64_C( 5854365313699013710),  INT64_C( 6682866169389799218),
        -INT64_C( 6272574243567026362), -INT64_C( 6388197785813851519) },
        { {  INT64_C( 8244320955527198716), -INT64_C( 7210524425313113166) },
          { -INT64_C( 5854365313699013710),  INT64_C( 6682866169389799218) },
          { -INT64_C( 6272574243567026362), -INT64_C( 6388197785813851519) } },
    },
    { {  INT64_C( 4691690948788941483), -INT64_C( 6390700913317834349),  INT64_C( 1335346503348599787),  INT64_C( 7176812256004417789),
        -INT64_C( 2059008905826987237), -INT64_C( 1223249548066530817) },
        { {  INT64_C( 4691690948788941483), -INT64_C( 6390700913317834349) },
          {  INT64_C( 1335346503348599787),  INT64_C( 7176812256004417789) },
          { -INT64_C( 2059008905826987237), -INT64_C( 1223249548066530817) } },
    },
    { {  INT64_C( 4973196958858489440),  INT64_C( 1773522139282396289),  INT64_C( 6491567619626397156),  INT64_C( 8285427118938713095),
        -INT64_C( 6522223655581856786),  INT64_C( 7517205436376724541) },
        { {  INT64_C( 4973196958858489440),  INT64_C( 1773522139282396289) },
          {  INT64_C( 6491567619626397156),  INT64_C( 8285427118938713095) },
          { -INT64_C( 6522223655581856786),  INT64_C( 7517205436376724541) } },
    },
    { {  INT64_C( 5376649532117128423),  INT64_C(  442005979426871199),  INT64_C( 3235478919066781213),  INT64_C( 2764005376816235630),
         INT64_C( 5249515640979060556), -INT64_C( 6882595883373219746) },
        { {  INT64_C( 5376649532117128423),  INT64_C(  442005979426871199) },
          {  INT64_C( 3235478919066781213),  INT64_C( 2764005376816235630) },
          {  INT64_C( 5249515640979060556), -INT64_C( 6882595883373219746) } },
    },
    { { -INT64_C( 2108308647550272862),  INT64_C( 2878134257930478476), -INT64_C( 4748885962057623002), -INT64_C( 3466451005192531519),
         INT64_C( 1927854610666538347), -INT64_C( 1494395984268651200) },
        { { -INT64_C( 2108308647550272862),  INT64_C( 2878134257930478476) },
          { -INT64_C( 4748885962057623002), -INT64_C( 3466451005192531519) },
          {  INT64_C( 1927854610666538347), -INT64_C( 1494395984268651200) } },
    },
    { {  INT64_C( 5498847361641478448), -INT64_C( 6926126984920529947), -INT64_C( 6998242669650624199), -INT64_C( 3709280968528771371),
        -INT64_C(  374736560142401035),  INT64_C(  649625350053911599) },
        { {  INT64_C( 5498847361641478448), -INT64_C( 6926126984920529947) },
          { -INT64_C( 6998242669650624199), -INT64_C( 3709280968528771371) },
          { -INT64_C(  374736560142401035),  INT64_C(  649625350053911599) } },
    },
    { { -INT64_C( 7625243149185547984), -INT64_C( 2819334859121432969),  INT64_C( 1586996493441055990),  INT64_C( 3556010825384334208),
         INT64_C( 6004967206239087358),  INT64_C( 3570868776828569043) },
        { { -INT64_C( 7625243149185547984), -INT64_C( 2819334859121432969) },
          {  INT64_C( 1586996493441055990),  INT64_C( 3556010825384334208) },
          {  INT64_C( 6004967206239087358),  INT64_C( 3570868776828569043) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x2x3_t r = simde_vld1q_s64_x3(test_vec[i].buf);
    simde_int64x2x3_t expected = {{
        simde_vld1q_s64(test_vec[i].expected[0]),
        simde_vld1q_s64(test_vec[i].expected[1]),
        simde_vld1q_s64(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_i64x2x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int64_t buf[6];
    simde_test_codegen_random_memory(48, (uint8_t*)buf);
    simde_test_codegen_write_vi64(2, 6, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int64x2x3_t val = simde_vld1q_s64_x3(buf);
    simde_test_arm_neon_write_i64x2x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u8_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t buf[48];
    uint8_t expected[3][16];
  } test_vec[] = {
    { { UINT8_C( 79), UINT8_C(180), UINT8_C(175), UINT8_C(252), UINT8_C(223), UINT8_C(175), UINT8_C(182), UINT8_C(217),
        UINT8_C( 39), UINT8_C( 94), UINT8_C(109), UINT8_C( 25), UINT8_C(252), UINT8_C( 59), UINT8_C(174), UINT8_C( 34),
        UINT8_C(250), UINT8_C(199), UINT8_C(  7), UINT8_C( 31), UINT8_C( 36), UINT8_C(124), UINT8_C(166), UINT8_C( 79),
        UINT8_C(247), UINT8_C( 57), UINT8_C(140), UINT8_C(237), UINT8_C(181), UINT8_C( 36), UINT8_C(243), UINT8_C(  4),
        UINT8_C(216), UINT8_C(163), UINT8_C(  1), UINT8_C(183), UINT8_C( 82), UINT8_C(183), UINT8_C(144), UINT8_C(121),
        UINT8_C( 22), UINT8_C(253), UINT8_C(146), UINT8_C( 18), UINT8_C( 57), UINT8_C( 64), UINT8_C( 53), UINT8_C( 51) },
        { { UINT8_C( 79), UINT8_C(180), UINT8_C(175), UINT8_C(252), UINT8_C(223), UINT8_C(175), UINT8_C(182), UINT8_C(217),
            UINT8_C( 39), UINT8_C( 94), UINT8_C(109), UINT8_C( 25), UINT8_C(252), UINT8_C( 59), UINT8_C(174), UINT8_C( 34) },
          { UINT8_C(250), UINT8_C(199), UINT8_C(  7), UINT8_C( 31), UINT8_C( 36), UINT8_C(124), UINT8_C(166), UINT8_C( 79),
            UINT8_C(247), UINT8_C( 57), UINT8_C(140), UINT8_C(237), UINT8_C(181), UINT8_C( 36), UINT8_C(243), UINT8_C(  4) },
          { UINT8_C(216), UINT8_C(163), UINT8_C(  1), UINT8_C(183), UINT8_C( 82), UINT8_C(183), UINT8_C(144), UINT8_C(121),
            UINT8_C( 22), UINT8_C(253), UINT8_C(146), UINT8_C( 18), UINT8_C( 57), UINT8_C( 64), UINT8_C( 53), UINT8_C( 51) } },
    },
    { { UINT8_C(  8), UINT8_C( 60), UINT8_C( 82), UINT8_C( 44), UINT8_C(184), UINT8_C(248), UINT8_C(123), UINT8_C(175),
        UINT8_C( 49), UINT8_C(  7), UINT8_C(156), UINT8_C(231), UINT8_C( 44), UINT8_C(144), UINT8_C(235), UINT8_C(  4),
        UINT8_C( 51), UINT8_C(236), UINT8_C(188), UINT8_C(133), UINT8_C(164), UINT8_C( 76), UINT8_C(254), UINT8_C(186),
        UINT8_C( 74), UINT8_C(145), UINT8_C(204), UINT8_C(131), UINT8_C(209), UINT8_C(  1), UINT8_C(182), UINT8_C(217),
        UINT8_C( 61), UINT8_C(  8), UINT8_C(  5), UINT8_C(246), UINT8_C(  0), UINT8_C(129), UINT8_C(165), UINT8_C( 50),
        UINT8_C(136), UINT8_C( 66), UINT8_C( 25), UINT8_C(180), UINT8_C(210), UINT8_C(  4), UINT8_C(185), UINT8_C(  5) },
        { { UINT8_C(  8), UINT8_C( 60), UINT8_C( 82), UINT8_C( 44), UINT8_C(184), UINT8_C(248), UINT8_C(123), UINT8_C(175),
            UINT8_C( 49), UINT8_C(  7), UINT8_C(156), UINT8_C(231), UINT8_C( 44), UINT8_C(144), UINT8_C(235), UINT8_C(  4) },
          { UINT8_C( 51), UINT8_C(236), UINT8_C(188), UINT8_C(133), UINT8_C(164), UINT8_C( 76), UINT8_C(254), UINT8_C(186),
            UINT8_C( 74), UINT8_C(145), UINT8_C(204), UINT8_C(131), UINT8_C(209), UINT8_C(  1), UINT8_C(182), UINT8_C(217) },
          { UINT8_C( 61), UINT8_C(  8), UINT8_C(  5), UINT8_C(246), UINT8_C(  0), UINT8_C(129), UINT8_C(165), UINT8_C( 50),
            UINT8_C(136), UINT8_C( 66), UINT8_C( 25), UINT8_C(180), UINT8_C(210), UINT8_C(  4), UINT8_C(185), UINT8_C(  5) } },
    },
    { { UINT8_C(241), UINT8_C(117), UINT8_C(138), UINT8_C(149), UINT8_C(193), UINT8_C(136), UINT8_C( 79), UINT8_C( 11),
        UINT8_C( 25), UINT8_C( 27), UINT8_C(142), UINT8_C(235), UINT8_C( 29), UINT8_C( 68), UINT8_C(196), UINT8_C( 90),
        UINT8_C( 76), UINT8_C(202), UINT8_C( 80), UINT8_C( 77), UINT8_C( 75), UINT8_C(246), UINT8_C(127), UINT8_C(211),
        UINT8_C( 56), UINT8_C(152), UINT8_C(136), UINT8_C( 10), UINT8_C(156), UINT8_C( 65), UINT8_C( 15), UINT8_C(141),
        UINT8_C(182), UINT8_C(153), UINT8_C( 34), UINT8_C(119), UINT8_C( 33), UINT8_C(113), UINT8_C(131), UINT8_C( 59),
        UINT8_C(141), UINT8_C( 17), UINT8_C( 38), UINT8_C(170), UINT8_C( 86), UINT8_C(234), UINT8_C(  4), UINT8_C(162) },
        { { UINT8_C(241), UINT8_C(117), UINT8_C(138), UINT8_C(149), UINT8_C(193), UINT8_C(136), UINT8_C( 79), UINT8_C( 11),
            UINT8_C( 25), UINT8_C( 27), UINT8_C(142), UINT8_C(235), UINT8_C( 29), UINT8_C( 68), UINT8_C(196), UINT8_C( 90) },
          { UINT8_C( 76), UINT8_C(202), UINT8_C( 80), UINT8_C( 77), UINT8_C( 75), UINT8_C(246), UINT8_C(127), UINT8_C(211),
            UINT8_C( 56), UINT8_C(152), UINT8_C(136), UINT8_C( 10), UINT8_C(156), UINT8_C( 65), UINT8_C( 15), UINT8_C(141) },
          { UINT8_C(182), UINT8_C(153), UINT8_C( 34), UINT8_C(119), UINT8_C( 33), UINT8_C(113), UINT8_C(131), UINT8_C( 59),
            UINT8_C(141), UINT8_C( 17), UINT8_C( 38), UINT8_C(170), UINT8_C( 86), UINT8_C(234), UINT8_C(  4), UINT8_C(162) } },
    },
    { { UINT8_C(180), UINT8_C( 85), UINT8_C(239),    UINT8_MAX, UINT8_C( 75), UINT8_C(110), UINT8_C(211), UINT8_C(131),
        UINT8_C(  6), UINT8_C( 91), UINT8_C(141), UINT8_C(163), UINT8_C(156), UINT8_C(156), UINT8_C( 48), UINT8_C( 82),
        UINT8_C( 53), UINT8_C( 83), UINT8_C(201), UINT8_C( 86), UINT8_C(196), UINT8_C( 76), UINT8_C(145), UINT8_C( 81),
        UINT8_C( 94), UINT8_C(183), UINT8_C(251), UINT8_C(180), UINT8_C(162), UINT8_C(  0), UINT8_C( 86), UINT8_C( 86),
        UINT8_C( 85), UINT8_C( 70), UINT8_C( 86), UINT8_C(160), UINT8_C(180), UINT8_C( 41), UINT8_C( 35), UINT8_C(187),
        UINT8_C(132), UINT8_C(176), UINT8_C( 94), UINT8_C( 32), UINT8_C( 76), UINT8_C(142), UINT8_C(114), UINT8_C(129) },
        { { UINT8_C(180), UINT8_C( 85), UINT8_C(239),    UINT8_MAX, UINT8_C( 75), UINT8_C(110), UINT8_C(211), UINT8_C(131),
            UINT8_C(  6), UINT8_C( 91), UINT8_C(141), UINT8_C(163), UINT8_C(156), UINT8_C(156), UINT8_C( 48), UINT8_C( 82) },
          { UINT8_C( 53), UINT8_C( 83), UINT8_C(201), UINT8_C( 86), UINT8_C(196), UINT8_C( 76), UINT8_C(145), UINT8_C( 81),
            UINT8_C( 94), UINT8_C(183), UINT8_C(251), UINT8_C(180), UINT8_C(162), UINT8_C(  0), UINT8_C( 86), UINT8_C( 86) },
          { UINT8_C( 85), UINT8_C( 70), UINT8_C( 86), UINT8_C(160), UINT8_C(180), UINT8_C( 41), UINT8_C( 35), UINT8_C(187),
            UINT8_C(132), UINT8_C(176), UINT8_C( 94), UINT8_C( 32), UINT8_C( 76), UINT8_C(142), UINT8_C(114), UINT8_C(129) } },
    },
    { { UINT8_C(225), UINT8_C( 59), UINT8_C(215), UINT8_C(166), UINT8_C(136), UINT8_C(105), UINT8_C(247), UINT8_C(230),
        UINT8_C( 32), UINT8_C(243), UINT8_C(154), UINT8_C(194), UINT8_C(243), UINT8_C(240), UINT8_C( 25), UINT8_C( 72),
        UINT8_C( 54), UINT8_C(111), UINT8_C(232), UINT8_C(235), UINT8_C(152), UINT8_C( 11), UINT8_C(166), UINT8_C( 28),
        UINT8_C(187), UINT8_C(  4), UINT8_C( 60), UINT8_C(  7), UINT8_C(146), UINT8_C(174), UINT8_C(136), UINT8_C(116),
        UINT8_C(233), UINT8_C( 95), UINT8_C( 26), UINT8_C(113), UINT8_C(200), UINT8_C( 17), UINT8_C( 87), UINT8_C(233),
        UINT8_C(  4), UINT8_C(241), UINT8_C(171), UINT8_C(247), UINT8_C(226), UINT8_C(196), UINT8_C( 63), UINT8_C( 24) },
        { { UINT8_C(225), UINT8_C( 59), UINT8_C(215), UINT8_C(166), UINT8_C(136), UINT8_C(105), UINT8_C(247), UINT8_C(230),
            UINT8_C( 32), UINT8_C(243), UINT8_C(154), UINT8_C(194), UINT8_C(243), UINT8_C(240), UINT8_C( 25), UINT8_C( 72) },
          { UINT8_C( 54), UINT8_C(111), UINT8_C(232), UINT8_C(235), UINT8_C(152), UINT8_C( 11), UINT8_C(166), UINT8_C( 28),
            UINT8_C(187), UINT8_C(  4), UINT8_C( 60), UINT8_C(  7), UINT8_C(146), UINT8_C(174), UINT8_C(136), UINT8_C(116) },
          { UINT8_C(233), UINT8_C( 95), UINT8_C( 26), UINT8_C(113), UINT8_C(200), UINT8_C( 17), UINT8_C( 87), UINT8_C(233),
            UINT8_C(  4), UINT8_C(241), UINT8_C(171), UINT8_C(247), UINT8_C(226), UINT8_C(196), UINT8_C( 63), UINT8_C( 24) } },
    },
    { { UINT8_C( 51), UINT8_C( 39), UINT8_C(  3), UINT8_C(203), UINT8_C( 50), UINT8_C(169), UINT8_C(231), UINT8_C(237),
        UINT8_C(173), UINT8_C( 35), UINT8_C(244), UINT8_C( 64), UINT8_C(209), UINT8_C(124), UINT8_C(180), UINT8_C(187),
        UINT8_C(220), UINT8_C(206), UINT8_C( 44), UINT8_C(164), UINT8_C(223), UINT8_C(132), UINT8_C(141), UINT8_C(228),
        UINT8_C(117), UINT8_C( 57), UINT8_C(219), UINT8_C( 87), UINT8_C(253), UINT8_C( 27), UINT8_C(112), UINT8_C( 49),
        UINT8_C( 66), UINT8_C(115), UINT8_C(252), UINT8_C(117), UINT8_C( 29), UINT8_C(228), UINT8_C( 98), UINT8_C(202),
        UINT8_C(  7), UINT8_C( 87), UINT8_C( 10), UINT8_C(217), UINT8_C(211), UINT8_C(190), UINT8_C(148), UINT8_C(175) },
        { { UINT8_C( 51), UINT8_C( 39), UINT8_C(  3), UINT8_C(203), UINT8_C( 50), UINT8_C(169), UINT8_C(231), UINT8_C(237),
            UINT8_C(173), UINT8_C( 35), UINT8_C(244), UINT8_C( 64), UINT8_C(209), UINT8_C(124), UINT8_C(180), UINT8_C(187) },
          { UINT8_C(220), UINT8_C(206), UINT8_C( 44), UINT8_C(164), UINT8_C(223), UINT8_C(132), UINT8_C(141), UINT8_C(228),
            UINT8_C(117), UINT8_C( 57), UINT8_C(219), UINT8_C( 87), UINT8_C(253), UINT8_C( 27), UINT8_C(112), UINT8_C( 49) },
          { UINT8_C( 66), UINT8_C(115), UINT8_C(252), UINT8_C(117), UINT8_C( 29), UINT8_C(228), UINT8_C( 98), UINT8_C(202),
            UINT8_C(  7), UINT8_C( 87), UINT8_C( 10), UINT8_C(217), UINT8_C(211), UINT8_C(190), UINT8_C(148), UINT8_C(175) } },
    },
    { { UINT8_C(140), UINT8_C(192), UINT8_C( 84), UINT8_C(108), UINT8_C( 68), UINT8_C(225), UINT8_C( 80), UINT8_C(186),
        UINT8_C( 26), UINT8_C( 43), UINT8_C( 17), UINT8_C( 24), UINT8_C( 70), UINT8_C(129), UINT8_C( 73), UINT8_C(137),
        UINT8_C(245), UINT8_C( 69), UINT8_C(254), UINT8_C( 18), UINT8_C( 41), UINT8_C( 96), UINT8_C(220), UINT8_C( 49),
        UINT8_C(183), UINT8_C(231), UINT8_C( 10), UINT8_C(139), UINT8_C(165), UINT8_C(158), UINT8_C( 58), UINT8_C( 50),
        UINT8_C( 94), UINT8_C(142), UINT8_C(158), UINT8_C(163), UINT8_C(112), UINT8_C(238), UINT8_C( 93), UINT8_C(138),
        UINT8_C( 25), UINT8_C(110), UINT8_C(162), UINT8_C( 96), UINT8_C(240), UINT8_C(235), UINT8_C(233), UINT8_C(229) },
        { { UINT8_C(140), UINT8_C(192), UINT8_C( 84), UINT8_C(108), UINT8_C( 68), UINT8_C(225), UINT8_C( 80), UINT8_C(186),
            UINT8_C( 26), UINT8_C( 43), UINT8_C( 17), UINT8_C( 24), UINT8_C( 70), UINT8_C(129), UINT8_C( 73), UINT8_C(137) },
          { UINT8_C(245), UINT8_C( 69), UINT8_C(254), UINT8_C( 18), UINT8_C( 41), UINT8_C( 96), UINT8_C(220), UINT8_C( 49),
            UINT8_C(183), UINT8_C(231), UINT8_C( 10), UINT8_C(139), UINT8_C(165), UINT8_C(158), UINT8_C( 58), UINT8_C( 50) },
          { UINT8_C( 94), UINT8_C(142), UINT8_C(158), UINT8_C(163), UINT8_C(112), UINT8_C(238), UINT8_C( 93), UINT8_C(138),
            UINT8_C( 25), UINT8_C(110), UINT8_C(162), UINT8_C( 96), UINT8_C(240), UINT8_C(235), UINT8_C(233), UINT8_C(229) } },
    },
    { { UINT8_C( 49), UINT8_C(231), UINT8_C(247), UINT8_C( 90), UINT8_C( 71), UINT8_C(211), UINT8_C(139),    UINT8_MAX,
        UINT8_C(186), UINT8_C(149), UINT8_C(138), UINT8_C( 96), UINT8_C( 51), UINT8_C(196), UINT8_C(146), UINT8_C(146),
        UINT8_C( 83), UINT8_C( 48), UINT8_C( 53), UINT8_C(195), UINT8_C( 30), UINT8_C(146), UINT8_C( 77), UINT8_C( 55),
        UINT8_C(  0), UINT8_C(240), UINT8_C(151), UINT8_C(240), UINT8_C(219), UINT8_C(128), UINT8_C(213), UINT8_C( 12),
        UINT8_C(103), UINT8_C(204), UINT8_C(103), UINT8_C(175), UINT8_C(160), UINT8_C(242), UINT8_C(174), UINT8_C( 90),
        UINT8_C(136), UINT8_C( 56), UINT8_C(186), UINT8_C(187), UINT8_C(252), UINT8_C( 76), UINT8_C( 77), UINT8_C( 79) },
        { { UINT8_C( 49), UINT8_C(231), UINT8_C(247), UINT8_C( 90), UINT8_C( 71), UINT8_C(211), UINT8_C(139),    UINT8_MAX,
            UINT8_C(186), UINT8_C(149), UINT8_C(138), UINT8_C( 96), UINT8_C( 51), UINT8_C(196), UINT8_C(146), UINT8_C(146) },
          { UINT8_C( 83), UINT8_C( 48), UINT8_C( 53), UINT8_C(195), UINT8_C( 30), UINT8_C(146), UINT8_C( 77), UINT8_C( 55),
            UINT8_C(  0), UINT8_C(240), UINT8_C(151), UINT8_C(240), UINT8_C(219), UINT8_C(128), UINT8_C(213), UINT8_C( 12) },
          { UINT8_C(103), UINT8_C(204), UINT8_C(103), UINT8_C(175), UINT8_C(160), UINT8_C(242), UINT8_C(174), UINT8_C( 90),
            UINT8_C(136), UINT8_C( 56), UINT8_C(186), UINT8_C(187), UINT8_C(252), UINT8_C( 76), UINT8_C( 77), UINT8_C( 79) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16x3_t r = simde_vld1q_u8_x3(test_vec[i].buf);
    simde_uint8x16x3_t expected = {{
        simde_vld1q_u8(test_vec[i].expected[0]),
        simde_vld1q_u8(test_vec[i].expected[1]),
        simde_vld1q_u8(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_u8x16x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t buf[48];
    simde_test_codegen_random_memory(48, buf);
    simde_test_codegen_write_vu8(2, 48, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint8x16x3_t val = simde_vld1q_u8_x3(buf);
    simde_test_arm_neon_write_u8x16x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t buf[24];
    uint16_t expected[3][8];
  } test_vec[] = {
    { { UINT16_C(29307), UINT16_C(64420), UINT16_C( 1960), UINT16_C(55981), UINT16_C(65410), UINT16_C(54332), UINT16_C( 1633), UINT16_C(35676),
        UINT16_C(25076), UINT16_C(27483), UINT16_C(13741), UINT16_C(55237), UINT16_C(39999), UINT16_C(44673), UINT16_C(43420), UINT16_C( 6117),
        UINT16_C(35100), UINT16_C(50194), UINT16_C(49041), UINT16_C( 5022), UINT16_C(56255), UINT16_C( 8423), UINT16_C(17377), UINT16_C(54699) },
        { { UINT16_C(29307), UINT16_C(64420), UINT16_C( 1960), UINT16_C(55981), UINT16_C(65410), UINT16_C(54332), UINT16_C( 1633), UINT16_C(35676) },
          { UINT16_C(25076), UINT16_C(27483), UINT16_C(13741), UINT16_C(55237), UINT16_C(39999), UINT16_C(44673), UINT16_C(43420), UINT16_C( 6117) },
          { UINT16_C(35100), UINT16_C(50194), UINT16_C(49041), UINT16_C( 5022), UINT16_C(56255), UINT16_C( 8423), UINT16_C(17377), UINT16_C(54699) } },
    },
    { { UINT16_C( 1700), UINT16_C(21057), UINT16_C( 1596), UINT16_C(31529), UINT16_C(43682), UINT16_C(16170), UINT16_C( 3923), UINT16_C(28502),
        UINT16_C(27033), UINT16_C(10804), UINT16_C(53800), UINT16_C(59197), UINT16_C( 9645), UINT16_C(36615), UINT16_C(45928), UINT16_C( 3428),
        UINT16_C(42425), UINT16_C(62815), UINT16_C(34987), UINT16_C(20081), UINT16_C(39730), UINT16_C(34189), UINT16_C(58282), UINT16_C(17397) },
        { { UINT16_C( 1700), UINT16_C(21057), UINT16_C( 1596), UINT16_C(31529), UINT16_C(43682), UINT16_C(16170), UINT16_C( 3923), UINT16_C(28502) },
          { UINT16_C(27033), UINT16_C(10804), UINT16_C(53800), UINT16_C(59197), UINT16_C( 9645), UINT16_C(36615), UINT16_C(45928), UINT16_C( 3428) },
          { UINT16_C(42425), UINT16_C(62815), UINT16_C(34987), UINT16_C(20081), UINT16_C(39730), UINT16_C(34189), UINT16_C(58282), UINT16_C(17397) } },
    },
    { { UINT16_C(10572), UINT16_C(30061), UINT16_C(44027), UINT16_C(43356), UINT16_C(25808), UINT16_C(14392), UINT16_C(39959), UINT16_C(53317),
        UINT16_C(42050), UINT16_C(60870), UINT16_C(14124), UINT16_C(24123), UINT16_C(51410), UINT16_C(31972), UINT16_C(55724), UINT16_C(63680),
        UINT16_C(11522), UINT16_C(64877), UINT16_C(51928), UINT16_C(43174), UINT16_C(56878), UINT16_C(17889), UINT16_C( 9851), UINT16_C(48405) },
        { { UINT16_C(10572), UINT16_C(30061), UINT16_C(44027), UINT16_C(43356), UINT16_C(25808), UINT16_C(14392), UINT16_C(39959), UINT16_C(53317) },
          { UINT16_C(42050), UINT16_C(60870), UINT16_C(14124), UINT16_C(24123), UINT16_C(51410), UINT16_C(31972), UINT16_C(55724), UINT16_C(63680) },
          { UINT16_C(11522), UINT16_C(64877), UINT16_C(51928), UINT16_C(43174), UINT16_C(56878), UINT16_C(17889), UINT16_C( 9851), UINT16_C(48405) } },
    },
    { { UINT16_C(56267), UINT16_C(63402), UINT16_C(58898), UINT16_C(58454), UINT16_C(15022), UINT16_C(23137), UINT16_C( 8467), UINT16_C( 5459),
        UINT16_C(49230), UINT16_C(10002), UINT16_C(47498), UINT16_C(47311), UINT16_C(45207), UINT16_C( 4861), UINT16_C( 5079), UINT16_C(41679),
        UINT16_C(31470), UINT16_C(  409), UINT16_C(61280), UINT16_C( 3813), UINT16_C(17961), UINT16_C(15465), UINT16_C(48231), UINT16_C(46673) },
        { { UINT16_C(56267), UINT16_C(63402), UINT16_C(58898), UINT16_C(58454), UINT16_C(15022), UINT16_C(23137), UINT16_C( 8467), UINT16_C( 5459) },
          { UINT16_C(49230), UINT16_C(10002), UINT16_C(47498), UINT16_C(47311), UINT16_C(45207), UINT16_C( 4861), UINT16_C( 5079), UINT16_C(41679) },
          { UINT16_C(31470), UINT16_C(  409), UINT16_C(61280), UINT16_C( 3813), UINT16_C(17961), UINT16_C(15465), UINT16_C(48231), UINT16_C(46673) } },
    },
    { { UINT16_C(25724), UINT16_C( 2013), UINT16_C(44061), UINT16_C(46271), UINT16_C(48477), UINT16_C(13511), UINT16_C(38608), UINT16_C(48854),
        UINT16_C(28432), UINT16_C(28863), UINT16_C(42335), UINT16_C(34943), UINT16_C(59627), UINT16_C(21445), UINT16_C( 5796), UINT16_C( 8201),
        UINT16_C(59002), UINT16_C(38695), UINT16_C(59282), UINT16_C(61260), UINT16_C( 5028), UINT16_C(29731), UINT16_C(63913), UINT16_C(47666) },
        { { UINT16_C(25724), UINT16_C( 2013), UINT16_C(44061), UINT16_C(46271), UINT16_C(48477), UINT16_C(13511), UINT16_C(38608), UINT16_C(48854) },
          { UINT16_C(28432), UINT16_C(28863), UINT16_C(42335), UINT16_C(34943), UINT16_C(59627), UINT16_C(21445), UINT16_C( 5796), UINT16_C( 8201) },
          { UINT16_C(59002), UINT16_C(38695), UINT16_C(59282), UINT16_C(61260), UINT16_C( 5028), UINT16_C(29731), UINT16_C(63913), UINT16_C(47666) } },
    },
    { { UINT16_C(62057), UINT16_C(51242), UINT16_C(43415), UINT16_C(33360), UINT16_C( 5521), UINT16_C(13781), UINT16_C(56876), UINT16_C(42582),
        UINT16_C(32196), UINT16_C(22334), UINT16_C(35428), UINT16_C( 2118), UINT16_C(27293), UINT16_C(18044), UINT16_C(44899), UINT16_C(52224),
        UINT16_C(11169), UINT16_C(14484), UINT16_C(58836), UINT16_C(26298), UINT16_C(37114), UINT16_C( 9883), UINT16_C(61806), UINT16_C(13261) },
        { { UINT16_C(62057), UINT16_C(51242), UINT16_C(43415), UINT16_C(33360), UINT16_C( 5521), UINT16_C(13781), UINT16_C(56876), UINT16_C(42582) },
          { UINT16_C(32196), UINT16_C(22334), UINT16_C(35428), UINT16_C( 2118), UINT16_C(27293), UINT16_C(18044), UINT16_C(44899), UINT16_C(52224) },
          { UINT16_C(11169), UINT16_C(14484), UINT16_C(58836), UINT16_C(26298), UINT16_C(37114), UINT16_C( 9883), UINT16_C(61806), UINT16_C(13261) } },
    },
    { { UINT16_C( 2927), UINT16_C(54154), UINT16_C(53397), UINT16_C(13020), UINT16_C(22586), UINT16_C(40568), UINT16_C(30983), UINT16_C(43114),
        UINT16_C(65444), UINT16_C(30944), UINT16_C(39908), UINT16_C(57054), UINT16_C(31275), UINT16_C(39173), UINT16_C(53867), UINT16_C(56012),
        UINT16_C(22237), UINT16_C(29358), UINT16_C(35367), UINT16_C(24996), UINT16_C( 7394), UINT16_C(60159), UINT16_C(27285), UINT16_C(14738) },
        { { UINT16_C( 2927), UINT16_C(54154), UINT16_C(53397), UINT16_C(13020), UINT16_C(22586), UINT16_C(40568), UINT16_C(30983), UINT16_C(43114) },
          { UINT16_C(65444), UINT16_C(30944), UINT16_C(39908), UINT16_C(57054), UINT16_C(31275), UINT16_C(39173), UINT16_C(53867), UINT16_C(56012) },
          { UINT16_C(22237), UINT16_C(29358), UINT16_C(35367), UINT16_C(24996), UINT16_C( 7394), UINT16_C(60159), UINT16_C(27285), UINT16_C(14738) } },
    },
    { { UINT16_C(29545), UINT16_C(19890), UINT16_C(36878), UINT16_C(14635), UINT16_C(12298), UINT16_C(30418), UINT16_C(40706), UINT16_C(57168),
        UINT16_C(65269), UINT16_C( 7249), UINT16_C(62856), UINT16_C(27518), UINT16_C(32018), UINT16_C(42837), UINT16_C(59367), UINT16_C(20705),
        UINT16_C(37722), UINT16_C(26781), UINT16_C(51491), UINT16_C(11937), UINT16_C(29945), UINT16_C(64676), UINT16_C(62483), UINT16_C( 2267) },
        { { UINT16_C(29545), UINT16_C(19890), UINT16_C(36878), UINT16_C(14635), UINT16_C(12298), UINT16_C(30418), UINT16_C(40706), UINT16_C(57168) },
          { UINT16_C(65269), UINT16_C( 7249), UINT16_C(62856), UINT16_C(27518), UINT16_C(32018), UINT16_C(42837), UINT16_C(59367), UINT16_C(20705) },
          { UINT16_C(37722), UINT16_C(26781), UINT16_C(51491), UINT16_C(11937), UINT16_C(29945), UINT16_C(64676), UINT16_C(62483), UINT16_C( 2267) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8x3_t r = simde_vld1q_u16_x3(test_vec[i].buf);
    simde_uint16x8x3_t expected = {{
        simde_vld1q_u16(test_vec[i].expected[0]),
        simde_vld1q_u16(test_vec[i].expected[1]),
        simde_vld1q_u16(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_u16x8x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t buf[24];
    simde_test_codegen_random_memory(48, (uint8_t*)buf);
    simde_test_codegen_write_vu16(2, 24, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint16x8x3_t val = simde_vld1q_u16_x3(buf);
    simde_test_arm_neon_write_u16x8x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t buf[12];
    uint32_t expected[3][4];
  } test_vec[] = {
    { { UINT32_C(2066034163), UINT32_C( 887530274), UINT32_C( 148650784), UINT32_C(2102967587), UINT32_C(1944516176), UINT32_C(3097593791), UINT32_C( 246695419), UINT32_C( 756518970),
        UINT32_C(3752344765), UINT32_C(4279537631), UINT32_C(3976720586), UINT32_C(4251672749) },
        { { UINT32_C(2066034163), UINT32_C( 887530274), UINT32_C( 148650784), UINT32_C(2102967587) },
          { UINT32_C(1944516176), UINT32_C(3097593791), UINT32_C( 246695419), UINT32_C( 756518970) },
          { UINT32_C(3752344765), UINT32_C(4279537631), UINT32_C(3976720586), UINT32_C(4251672749) } },
    },
    { { UINT32_C( 359682390), UINT32_C(3570209496), UINT32_C(2447540823), UINT32_C(3485399314), UINT32_C( 346974005), UINT32_C(3222586102), UINT32_C(1605245874), UINT32_C(3512473979),
        UINT32_C(1122422122), UINT32_C( 907457759), UINT32_C(1221130550), UINT32_C( 672630514) },
        { { UINT32_C( 359682390), UINT32_C(3570209496), UINT32_C(2447540823), UINT32_C(3485399314) },
          { UINT32_C( 346974005), UINT32_C(3222586102), UINT32_C(1605245874), UINT32_C(3512473979) },
          { UINT32_C(1122422122), UINT32_C( 907457759), UINT32_C(1221130550), UINT32_C( 672630514) } },
    },
    { { UINT32_C(3812410861), UINT32_C( 983847048), UINT32_C(3885650540), UINT32_C(3585734251), UINT32_C(2719457219), UINT32_C(2312711763), UINT32_C( 433168679), UINT32_C( 356640807),
        UINT32_C( 922255022), UINT32_C( 980458702), UINT32_C(1495403246), UINT32_C(3291405057) },
        { { UINT32_C(3812410861), UINT32_C( 983847048), UINT32_C(3885650540), UINT32_C(3585734251) },
          { UINT32_C(2719457219), UINT32_C(2312711763), UINT32_C( 433168679), UINT32_C( 356640807) },
          { UINT32_C( 922255022), UINT32_C( 980458702), UINT32_C(1495403246), UINT32_C(3291405057) } },
    },
    { { UINT32_C(3462874746), UINT32_C(2606186612), UINT32_C( 146024929), UINT32_C(3206411793), UINT32_C(1123358324), UINT32_C(2709350066), UINT32_C(1912250224), UINT32_C(4097190266),
        UINT32_C(3821182319), UINT32_C(3195935453), UINT32_C(1422275139), UINT32_C(2618614824) },
        { { UINT32_C(3462874746), UINT32_C(2606186612), UINT32_C( 146024929), UINT32_C(3206411793) },
          { UINT32_C(1123358324), UINT32_C(2709350066), UINT32_C(1912250224), UINT32_C(4097190266) },
          { UINT32_C(3821182319), UINT32_C(3195935453), UINT32_C(1422275139), UINT32_C(2618614824) } },
    },
    { { UINT32_C(2900298234), UINT32_C(3763166319), UINT32_C(1968261371), UINT32_C(3765012337), UINT32_C(  29568036), UINT32_C(2311012678), UINT32_C(2631763571), UINT32_C(1681453418),
        UINT32_C(1779439611), UINT32_C(1850367603), UINT32_C( 400792742), UINT32_C(1224166691) },
        { { UINT32_C(2900298234), UINT32_C(3763166319), UINT32_C(1968261371), UINT32_C(3765012337) },
          { UINT32_C(  29568036), UINT32_C(2311012678), UINT32_C(2631763571), UINT32_C(1681453418) },
          { UINT32_C(1779439611), UINT32_C(1850367603), UINT32_C( 400792742), UINT32_C(1224166691) } },
    },
    { { UINT32_C(3209280121), UINT32_C(1850214907), UINT32_C(4178191759), UINT32_C( 308101911), UINT32_C(3464260954), UINT32_C(1899808715), UINT32_C(2257068131), UINT32_C(3872292717),
        UINT32_C( 883234873), UINT32_C(2963533089), UINT32_C( 698985746), UINT32_C(1262159600) },
        { { UINT32_C(3209280121), UINT32_C(1850214907), UINT32_C(4178191759), UINT32_C( 308101911) },
          { UINT32_C(3464260954), UINT32_C(1899808715), UINT32_C(2257068131), UINT32_C(3872292717) },
          { UINT32_C( 883234873), UINT32_C(2963533089), UINT32_C( 698985746), UINT32_C(1262159600) } },
    },
    { { UINT32_C(1058650227), UINT32_C(3803207039), UINT32_C(3798481269), UINT32_C(4073207736), UINT32_C(1881566543), UINT32_C(1830865242), UINT32_C(1737935223), UINT32_C(1119015631),
        UINT32_C( 159501194), UINT32_C(2531996193), UINT32_C( 595153771), UINT32_C(3642048906) },
        { { UINT32_C(1058650227), UINT32_C(3803207039), UINT32_C(3798481269), UINT32_C(4073207736) },
          { UINT32_C(1881566543), UINT32_C(1830865242), UINT32_C(1737935223), UINT32_C(1119015631) },
          { UINT32_C( 159501194), UINT32_C(2531996193), UINT32_C( 595153771), UINT32_C(3642048906) } },
    },
    { { UINT32_C( 155794607), UINT32_C(2088134917), UINT32_C(  31722802), UINT32_C(1766102751), UINT32_C(2205336930), UINT32_C(1645829623), UINT32_C( 998675120), UINT32_C(2199165908),
        UINT32_C(3716964055), UINT32_C(4200137671), UINT32_C(4026219792), UINT32_C( 911753172) },
        { { UINT32_C( 155794607), UINT32_C(2088134917), UINT32_C(  31722802), UINT32_C(1766102751) },
          { UINT32_C(2205336930), UINT32_C(1645829623), UINT32_C( 998675120), UINT32_C(2199165908) },
          { UINT32_C(3716964055), UINT32_C(4200137671), UINT32_C(4026219792), UINT32_C( 911753172) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4x3_t r = simde_vld1q_u32_x3(test_vec[i].buf);
    simde_uint32x4x3_t expected = {{
        simde_vld1q_u32(test_vec[i].expected[0]),
        simde_vld1q_u32(test_vec[i].expected[1]),
        simde_vld1q_u32(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_u32x4x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t buf[12];
    simde_test_codegen_random_memory(48, (uint8_t*)buf);
    simde_test_codegen_write_vu32(2, 12, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint32x4x3_t val = simde_vld1q_u32_x3(buf);
    simde_test_arm_neon_write_u32x4x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t buf[6];
    uint64_t expected[3][2];
  } test_vec[] = {
    { { UINT64_C(15519353910127610373), UINT64_C( 6394029002626098533), UINT64_C( 6577100759873439877), UINT64_C( 9716131923722126028),
        UINT64_C(14297770350732349292), UINT64_C( 2999322191108996551) },
        { { UINT64_C(15519353910127610373), UINT64_C( 6394029002626098533) },
          { UINT64_C( 6577100759873439877), UINT64_C( 9716131923722126028) },
          { UINT64_C(14297770350732349292), UINT64_C( 2999322191108996551) } },
    },
    { { UINT64_C( 3435046275521106948), UINT64_C(  290101300426700286), UINT64_C( 3628779160359962932), UINT64_C( 1967537674411203456),
        UINT64_C( 9187366884996728046), UINT64_C( 2929317730421001995) },
        { { UINT64_C( 3435046275521106948), UINT64_C(  290101300426700286) },
          { UINT64_C( 3628779160359962932), UINT64_C( 1967537674411203456) },
          { UINT64_C( 9187366884996728046), UINT64_C( 2929317730421001995) } },
    },
    { { UINT64_C(14063924986829946767), UINT64_C(12657145482668713845), UINT64_C( 3673670828123230715), UINT64_C(10442576508011019215),
        UINT64_C( 4017696589736552636), UINT64_C(15839277400333724000) },
        { { UINT64_C(14063924986829946767), UINT64_C(12657145482668713845) },
          { UINT64_C( 3673670828123230715), UINT64_C(10442576508011019215) },
          { UINT64_C( 4017696589736552636), UINT64_C(15839277400333724000) } },
    },
    { { UINT64_C( 2293548616512950395), UINT64_C(16348010736794118477), UINT64_C( 9543024407583156854), UINT64_C( 1659143925851828811),
        UINT64_C(18281956626468068678), UINT64_C(15870732805522364728) },
        { { UINT64_C( 2293548616512950395), UINT64_C(16348010736794118477) },
          { UINT64_C( 9543024407583156854), UINT64_C( 1659143925851828811) },
          { UINT64_C(18281956626468068678), UINT64_C(15870732805522364728) } },
    },
    { { UINT64_C( 1026121162462339221), UINT64_C(11486783072649208501), UINT64_C(16810790280339268509), UINT64_C( 6325454947899381637),
        UINT64_C( 1619129142531382696), UINT64_C(10315443211604570672) },
        { { UINT64_C( 1026121162462339221), UINT64_C(11486783072649208501) },
          { UINT64_C(16810790280339268509), UINT64_C( 6325454947899381637) },
          { UINT64_C( 1619129142531382696), UINT64_C(10315443211604570672) } },
    },
    { { UINT64_C(14955935713619434995), UINT64_C(  421232102302537407), UINT64_C( 7410647033732720993), UINT64_C(  224078337506492314),
        UINT64_C(16180648554772625780), UINT64_C( 3345956602575407372) },
        { { UINT64_C(14955935713619434995), UINT64_C(  421232102302537407) },
          { UINT64_C( 7410647033732720993), UINT64_C(  224078337506492314) },
          { UINT64_C(16180648554772625780), UINT64_C( 3345956602575407372) } },
    },
    { { UINT64_C( 7115625599584952098), UINT64_C( 4114051200707440134), UINT64_C(  217726354026119172), UINT64_C(14035711916260550349),
        UINT64_C( 9648920967876688060), UINT64_C(16539385936809219721) },
        { { UINT64_C( 7115625599584952098), UINT64_C( 4114051200707440134) },
          { UINT64_C(  217726354026119172), UINT64_C(14035711916260550349) },
          { UINT64_C( 9648920967876688060), UINT64_C(16539385936809219721) } },
    },
    { { UINT64_C(15018958310370606707), UINT64_C( 8491031013163195253), UINT64_C( 6192415181230436843), UINT64_C(12717085887517919670),
        UINT64_C(  755066063923349160), UINT64_C(  257256137636701540) },
        { { UINT64_C(15018958310370606707), UINT64_C( 8491031013163195253) },
          { UINT64_C( 6192415181230436843), UINT64_C(12717085887517919670) },
          { UINT64_C(  755066063923349160), UINT64_C(  257256137636701540) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x2x3_t r = simde_vld1q_u64_x3(test_vec[i].buf);
    simde_uint64x2x3_t expected = {{
        simde_vld1q_u64(test_vec[i].expected[0]),
        simde_vld1q_u64(test_vec[i].expected[1]),
        simde_vld1q_u64(test_vec[i].expected[2]),
    }};
    simde_test_arm_neon_assert_equal_u64x2x3(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t buf[6];
    simde_test_codegen_random_memory(48, (uint8_t*)buf);
    simde_test_codegen_write_vu64(2, 6, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint64x2x3_t val = simde_vld1q_u64_x3(buf);
    simde_test_arm_neon_write_u64x2x3(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_f32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_f64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u64_x3)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
