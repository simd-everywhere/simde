#define SIMDE_TEST_ARM_NEON_INSN ld1q_x2
#include "test/test.h"
#include "test-neon.h"
#include "../../../simde/arm/neon/ld1q_x2.h"
#include "../../../simde/arm/neon/ld1_lane.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld1q_f32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 buf[8];
    simde_float32 expected[2][4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -519.75), SIMDE_FLOAT32_C(   458.27), SIMDE_FLOAT32_C(  -666.84), SIMDE_FLOAT32_C(    30.63),
        SIMDE_FLOAT32_C(   204.13), SIMDE_FLOAT32_C(   924.39), SIMDE_FLOAT32_C(   273.99), SIMDE_FLOAT32_C(   -46.96) },
        { { SIMDE_FLOAT32_C(  -519.75), SIMDE_FLOAT32_C(   458.27), SIMDE_FLOAT32_C(  -666.84), SIMDE_FLOAT32_C(    30.63) },
          { SIMDE_FLOAT32_C(   204.13), SIMDE_FLOAT32_C(   924.39), SIMDE_FLOAT32_C(   273.99), SIMDE_FLOAT32_C(   -46.96) } },
    },
    { { SIMDE_FLOAT32_C(  -699.34), SIMDE_FLOAT32_C(   -33.06), SIMDE_FLOAT32_C(  -647.44), SIMDE_FLOAT32_C(   127.96),
        SIMDE_FLOAT32_C(   609.99), SIMDE_FLOAT32_C(   520.83), SIMDE_FLOAT32_C(  -592.58), SIMDE_FLOAT32_C(   923.15) },
        { { SIMDE_FLOAT32_C(  -699.34), SIMDE_FLOAT32_C(   -33.06), SIMDE_FLOAT32_C(  -647.44), SIMDE_FLOAT32_C(   127.96) },
          { SIMDE_FLOAT32_C(   609.99), SIMDE_FLOAT32_C(   520.83), SIMDE_FLOAT32_C(  -592.58), SIMDE_FLOAT32_C(   923.15) } },
    },
    { { SIMDE_FLOAT32_C(  -372.27), SIMDE_FLOAT32_C(   210.58), SIMDE_FLOAT32_C(  -652.94), SIMDE_FLOAT32_C(  -104.58),
        SIMDE_FLOAT32_C(  -217.08), SIMDE_FLOAT32_C(   293.97), SIMDE_FLOAT32_C(  -646.43), SIMDE_FLOAT32_C(  -437.15) },
        { { SIMDE_FLOAT32_C(  -372.27), SIMDE_FLOAT32_C(   210.58), SIMDE_FLOAT32_C(  -652.94), SIMDE_FLOAT32_C(  -104.58) },
          { SIMDE_FLOAT32_C(  -217.08), SIMDE_FLOAT32_C(   293.97), SIMDE_FLOAT32_C(  -646.43), SIMDE_FLOAT32_C(  -437.15) } },
    },
    { { SIMDE_FLOAT32_C(   -88.48), SIMDE_FLOAT32_C(   163.64), SIMDE_FLOAT32_C(  -966.50), SIMDE_FLOAT32_C(   798.22),
        SIMDE_FLOAT32_C(   997.21), SIMDE_FLOAT32_C(    40.31), SIMDE_FLOAT32_C(   338.70), SIMDE_FLOAT32_C(  -522.54) },
        { { SIMDE_FLOAT32_C(   -88.48), SIMDE_FLOAT32_C(   163.64), SIMDE_FLOAT32_C(  -966.50), SIMDE_FLOAT32_C(   798.22) },
          { SIMDE_FLOAT32_C(   997.21), SIMDE_FLOAT32_C(    40.31), SIMDE_FLOAT32_C(   338.70), SIMDE_FLOAT32_C(  -522.54) } },
    },
    { { SIMDE_FLOAT32_C(  -501.41), SIMDE_FLOAT32_C(   671.87), SIMDE_FLOAT32_C(   508.09), SIMDE_FLOAT32_C(   702.72),
        SIMDE_FLOAT32_C(   596.26), SIMDE_FLOAT32_C(  -217.91), SIMDE_FLOAT32_C(  -344.24), SIMDE_FLOAT32_C(   896.92) },
        { { SIMDE_FLOAT32_C(  -501.41), SIMDE_FLOAT32_C(   671.87), SIMDE_FLOAT32_C(   508.09), SIMDE_FLOAT32_C(   702.72) },
          { SIMDE_FLOAT32_C(   596.26), SIMDE_FLOAT32_C(  -217.91), SIMDE_FLOAT32_C(  -344.24), SIMDE_FLOAT32_C(   896.92) } },
    },
    { { SIMDE_FLOAT32_C(   749.03), SIMDE_FLOAT32_C(     8.31), SIMDE_FLOAT32_C(    24.89), SIMDE_FLOAT32_C(   359.02),
        SIMDE_FLOAT32_C(  -470.86), SIMDE_FLOAT32_C(   432.30), SIMDE_FLOAT32_C(   282.17), SIMDE_FLOAT32_C(   156.87) },
        { { SIMDE_FLOAT32_C(   749.03), SIMDE_FLOAT32_C(     8.31), SIMDE_FLOAT32_C(    24.89), SIMDE_FLOAT32_C(   359.02) },
          { SIMDE_FLOAT32_C(  -470.86), SIMDE_FLOAT32_C(   432.30), SIMDE_FLOAT32_C(   282.17), SIMDE_FLOAT32_C(   156.87) } },
    },
    { { SIMDE_FLOAT32_C(  -357.11), SIMDE_FLOAT32_C(   629.23), SIMDE_FLOAT32_C(  -947.72), SIMDE_FLOAT32_C(   425.80),
        SIMDE_FLOAT32_C(   -76.80), SIMDE_FLOAT32_C(  -594.15), SIMDE_FLOAT32_C(   988.65), SIMDE_FLOAT32_C(   834.72) },
        { { SIMDE_FLOAT32_C(  -357.11), SIMDE_FLOAT32_C(   629.23), SIMDE_FLOAT32_C(  -947.72), SIMDE_FLOAT32_C(   425.80) },
          { SIMDE_FLOAT32_C(   -76.80), SIMDE_FLOAT32_C(  -594.15), SIMDE_FLOAT32_C(   988.65), SIMDE_FLOAT32_C(   834.72) } },
    },
    { { SIMDE_FLOAT32_C(   569.49), SIMDE_FLOAT32_C(  -977.85), SIMDE_FLOAT32_C(   632.94), SIMDE_FLOAT32_C(   566.70),
        SIMDE_FLOAT32_C(    62.47), SIMDE_FLOAT32_C(   -28.35), SIMDE_FLOAT32_C(  -955.84), SIMDE_FLOAT32_C(   561.05) },
        { { SIMDE_FLOAT32_C(   569.49), SIMDE_FLOAT32_C(  -977.85), SIMDE_FLOAT32_C(   632.94), SIMDE_FLOAT32_C(   566.70) },
          { SIMDE_FLOAT32_C(    62.47), SIMDE_FLOAT32_C(   -28.35), SIMDE_FLOAT32_C(  -955.84), SIMDE_FLOAT32_C(   561.05) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4x2_t r = simde_vld1q_f32_x2(test_vec[i].buf);
    simde_float32x4x2_t expected = {{
        simde_vld1q_f32(test_vec[i].expected[0]),
        simde_vld1q_f32(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_f32x4x2(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 buf[8];
    for (int j = 0 ; j < 8 ; j++) {
      buf[j] = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    }
    simde_test_codegen_write_vf32(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32x4x2_t val = simde_vld1q_f32_x2(buf);
    simde_test_arm_neon_write_f32x4x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_f64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 buf[4];
    simde_float64 expected[2][2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -356.49), SIMDE_FLOAT64_C(   552.25), SIMDE_FLOAT64_C(   263.77), SIMDE_FLOAT64_C(  -760.23) },
        { { SIMDE_FLOAT64_C(  -356.49), SIMDE_FLOAT64_C(   552.25) },
          { SIMDE_FLOAT64_C(   263.77), SIMDE_FLOAT64_C(  -760.23) } },
    },
    { { SIMDE_FLOAT64_C(  -665.66), SIMDE_FLOAT64_C(   919.53), SIMDE_FLOAT64_C(  -863.30), SIMDE_FLOAT64_C(  -916.63) },
        { { SIMDE_FLOAT64_C(  -665.66), SIMDE_FLOAT64_C(   919.53) },
          { SIMDE_FLOAT64_C(  -863.30), SIMDE_FLOAT64_C(  -916.63) } },
    },
    { { SIMDE_FLOAT64_C(   -72.16), SIMDE_FLOAT64_C(   161.58), SIMDE_FLOAT64_C(   442.39), SIMDE_FLOAT64_C(   456.98) },
        { { SIMDE_FLOAT64_C(   -72.16), SIMDE_FLOAT64_C(   161.58) },
          { SIMDE_FLOAT64_C(   442.39), SIMDE_FLOAT64_C(   456.98) } },
    },
    { { SIMDE_FLOAT64_C(  -406.11), SIMDE_FLOAT64_C(  -275.44), SIMDE_FLOAT64_C(  -386.15), SIMDE_FLOAT64_C(   236.77) },
        { { SIMDE_FLOAT64_C(  -406.11), SIMDE_FLOAT64_C(  -275.44) },
          { SIMDE_FLOAT64_C(  -386.15), SIMDE_FLOAT64_C(   236.77) } },
    },
    { { SIMDE_FLOAT64_C(  -646.21), SIMDE_FLOAT64_C(  -333.87), SIMDE_FLOAT64_C(  -337.42), SIMDE_FLOAT64_C(   276.99) },
        { { SIMDE_FLOAT64_C(  -646.21), SIMDE_FLOAT64_C(  -333.87) },
          { SIMDE_FLOAT64_C(  -337.42), SIMDE_FLOAT64_C(   276.99) } },
    },
    { { SIMDE_FLOAT64_C(    71.98), SIMDE_FLOAT64_C(  -348.77), SIMDE_FLOAT64_C(   111.71), SIMDE_FLOAT64_C(  -358.53) },
        { { SIMDE_FLOAT64_C(    71.98), SIMDE_FLOAT64_C(  -348.77) },
          { SIMDE_FLOAT64_C(   111.71), SIMDE_FLOAT64_C(  -358.53) } },
    },
    { { SIMDE_FLOAT64_C(  -326.61), SIMDE_FLOAT64_C(  -255.35), SIMDE_FLOAT64_C(  -791.83), SIMDE_FLOAT64_C(   735.85) },
        { { SIMDE_FLOAT64_C(  -326.61), SIMDE_FLOAT64_C(  -255.35) },
          { SIMDE_FLOAT64_C(  -791.83), SIMDE_FLOAT64_C(   735.85) } },
    },
    { { SIMDE_FLOAT64_C(   716.30), SIMDE_FLOAT64_C(  -747.68), SIMDE_FLOAT64_C(   296.91), SIMDE_FLOAT64_C(  -640.19) },
        { { SIMDE_FLOAT64_C(   716.30), SIMDE_FLOAT64_C(  -747.68) },
          { SIMDE_FLOAT64_C(   296.91), SIMDE_FLOAT64_C(  -640.19) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2x2_t r = simde_vld1q_f64_x2(test_vec[i].buf);
    simde_float64x2x2_t expected = {{
        simde_vld1q_f64(test_vec[i].expected[0]),
        simde_vld1q_f64(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_f64x2x2(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 buf[4];
    for (int j = 0 ; j < 4 ; j++) {
      buf[j] = simde_test_codegen_random_f64(-1000.0, 1000.0);
    }
    simde_test_codegen_write_vf64(2, 4, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64x2x2_t val = simde_vld1q_f64_x2(buf);
    simde_test_arm_neon_write_f64x2x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s8_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t buf[32];
    int8_t expected[2][16];
  } test_vec[] = {
    { {  INT8_C(  87),  INT8_C(  13),  INT8_C( 111), -INT8_C(  93), -INT8_C(  38),  INT8_C( 103),  INT8_C(  59), -INT8_C(  94),
        -INT8_C(  85),  INT8_C(  66),  INT8_C(  92),  INT8_C(  66),  INT8_C(  13),  INT8_C(  68), -INT8_C(  61), -INT8_C(   3),
         INT8_C( 106), -INT8_C(  58), -INT8_C(  56),  INT8_C(  19),  INT8_C(  12),  INT8_C(  53),  INT8_C(  65), -INT8_C(  50),
        -INT8_C(  34),  INT8_C(  14), -INT8_C(  90),  INT8_C(  86),  INT8_C(  59),  INT8_C(  47), -INT8_C( 124), -INT8_C( 109) },
        { {  INT8_C(  87),  INT8_C(  13),  INT8_C( 111), -INT8_C(  93), -INT8_C(  38),  INT8_C( 103),  INT8_C(  59), -INT8_C(  94),
            -INT8_C(  85),  INT8_C(  66),  INT8_C(  92),  INT8_C(  66),  INT8_C(  13),  INT8_C(  68), -INT8_C(  61), -INT8_C(   3) },
          {  INT8_C( 106), -INT8_C(  58), -INT8_C(  56),  INT8_C(  19),  INT8_C(  12),  INT8_C(  53),  INT8_C(  65), -INT8_C(  50),
            -INT8_C(  34),  INT8_C(  14), -INT8_C(  90),  INT8_C(  86),  INT8_C(  59),  INT8_C(  47), -INT8_C( 124), -INT8_C( 109) } },
    },
    { {  INT8_C(  61), -INT8_C(  13),  INT8_C(  54),  INT8_C(  23),  INT8_C(  90),  INT8_C( 113), -INT8_C(  71),  INT8_C(   5),
        -INT8_C(  77),  INT8_C(  22),  INT8_C(  71), -INT8_C(  63),  INT8_C(  90),  INT8_C(  10), -INT8_C(  66), -INT8_C(  59),
        -INT8_C(  48), -INT8_C( 122), -INT8_C(  40), -INT8_C(  35), -INT8_C(  69),  INT8_C(  25), -INT8_C(  85), -INT8_C( 103),
         INT8_C(  40),  INT8_C(  82), -INT8_C(  16),  INT8_C(  99), -INT8_C( 127),  INT8_C( 116), -INT8_C(  10), -INT8_C(  66) },
        { {  INT8_C(  61), -INT8_C(  13),  INT8_C(  54),  INT8_C(  23),  INT8_C(  90),  INT8_C( 113), -INT8_C(  71),  INT8_C(   5),
            -INT8_C(  77),  INT8_C(  22),  INT8_C(  71), -INT8_C(  63),  INT8_C(  90),  INT8_C(  10), -INT8_C(  66), -INT8_C(  59) },
          { -INT8_C(  48), -INT8_C( 122), -INT8_C(  40), -INT8_C(  35), -INT8_C(  69),  INT8_C(  25), -INT8_C(  85), -INT8_C( 103),
             INT8_C(  40),  INT8_C(  82), -INT8_C(  16),  INT8_C(  99), -INT8_C( 127),  INT8_C( 116), -INT8_C(  10), -INT8_C(  66) } },
    },
    { {  INT8_C( 103),  INT8_C(  44), -INT8_C(  42), -INT8_C(  62), -INT8_C(  98), -INT8_C( 113), -INT8_C(  57),  INT8_C(  81),
        -INT8_C(  91),  INT8_C(  15),  INT8_C(  18),  INT8_C(   0),  INT8_C(  25), -INT8_C(  48), -INT8_C(  59), -INT8_C(  22),
         INT8_C(  86), -INT8_C(  99), -INT8_C(  57),  INT8_C(  17), -INT8_C(  73),  INT8_C( 114), -INT8_C(  85), -INT8_C(  33),
        -INT8_C(  60), -INT8_C( 101),  INT8_C(  66),  INT8_C(  70),  INT8_C(  15),  INT8_C(  57),  INT8_C(   4),  INT8_C( 118) },
        { {  INT8_C( 103),  INT8_C(  44), -INT8_C(  42), -INT8_C(  62), -INT8_C(  98), -INT8_C( 113), -INT8_C(  57),  INT8_C(  81),
            -INT8_C(  91),  INT8_C(  15),  INT8_C(  18),  INT8_C(   0),  INT8_C(  25), -INT8_C(  48), -INT8_C(  59), -INT8_C(  22) },
          {  INT8_C(  86), -INT8_C(  99), -INT8_C(  57),  INT8_C(  17), -INT8_C(  73),  INT8_C( 114), -INT8_C(  85), -INT8_C(  33),
            -INT8_C(  60), -INT8_C( 101),  INT8_C(  66),  INT8_C(  70),  INT8_C(  15),  INT8_C(  57),  INT8_C(   4),  INT8_C( 118) } },
    },
    { {  INT8_C( 101), -INT8_C(  38),  INT8_C(  56),  INT8_C(   3),  INT8_C( 106),  INT8_C(   0),  INT8_C(  85),  INT8_C(  15),
         INT8_C(  15),  INT8_C( 103),  INT8_C(  15),  INT8_C(  40),  INT8_C(  56), -INT8_C(  44),  INT8_C(  18), -INT8_C( 114),
         INT8_C( 114), -INT8_C(  39), -INT8_C(  96),  INT8_C(  41),  INT8_C(  76),  INT8_C(  75),  INT8_C(   8),  INT8_C(  16),
        -INT8_C(  26),  INT8_C(  74),  INT8_C(  86), -INT8_C(  11), -INT8_C( 125),  INT8_C(  91),  INT8_C( 107), -INT8_C(  23) },
        { {  INT8_C( 101), -INT8_C(  38),  INT8_C(  56),  INT8_C(   3),  INT8_C( 106),  INT8_C(   0),  INT8_C(  85),  INT8_C(  15),
             INT8_C(  15),  INT8_C( 103),  INT8_C(  15),  INT8_C(  40),  INT8_C(  56), -INT8_C(  44),  INT8_C(  18), -INT8_C( 114) },
          {  INT8_C( 114), -INT8_C(  39), -INT8_C(  96),  INT8_C(  41),  INT8_C(  76),  INT8_C(  75),  INT8_C(   8),  INT8_C(  16),
            -INT8_C(  26),  INT8_C(  74),  INT8_C(  86), -INT8_C(  11), -INT8_C( 125),  INT8_C(  91),  INT8_C( 107), -INT8_C(  23) } },
    },
    { {  INT8_C(  53), -INT8_C(  92), -INT8_C(  20), -INT8_C(  97), -INT8_C(  92),  INT8_C(  65), -INT8_C(  81), -INT8_C(  77),
        -INT8_C(  87), -INT8_C(  66), -INT8_C(  37), -INT8_C(  31), -INT8_C( 109), -INT8_C(  18),  INT8_C( 111),  INT8_C(   5),
        -INT8_C(  57),  INT8_C(  15),  INT8_C(  46),  INT8_C(  19),  INT8_C(  90),  INT8_C(  54),  INT8_C(  36),  INT8_C(  64),
             INT8_MIN,  INT8_C( 122),  INT8_C(  53),  INT8_C(   4), -INT8_C(  43), -INT8_C(  95), -INT8_C(  19),  INT8_C(  11) },
        { {  INT8_C(  53), -INT8_C(  92), -INT8_C(  20), -INT8_C(  97), -INT8_C(  92),  INT8_C(  65), -INT8_C(  81), -INT8_C(  77),
            -INT8_C(  87), -INT8_C(  66), -INT8_C(  37), -INT8_C(  31), -INT8_C( 109), -INT8_C(  18),  INT8_C( 111),  INT8_C(   5) },
          { -INT8_C(  57),  INT8_C(  15),  INT8_C(  46),  INT8_C(  19),  INT8_C(  90),  INT8_C(  54),  INT8_C(  36),  INT8_C(  64),
                 INT8_MIN,  INT8_C( 122),  INT8_C(  53),  INT8_C(   4), -INT8_C(  43), -INT8_C(  95), -INT8_C(  19),  INT8_C(  11) } },
    },
    { {  INT8_C(  69), -INT8_C(  39), -INT8_C(  86), -INT8_C(  23),  INT8_C(  27),  INT8_C(  89), -INT8_C( 100), -INT8_C(  60),
         INT8_C(  24),  INT8_C( 119), -INT8_C(  91), -INT8_C(  85),  INT8_C( 101),  INT8_C(  20), -INT8_C(  80),  INT8_C(  45),
         INT8_C(  36), -INT8_C(  34),  INT8_C(  64),  INT8_C( 126),  INT8_C(  20),  INT8_C( 100), -INT8_C(  65), -INT8_C( 108),
        -INT8_C(  33), -INT8_C(  12), -INT8_C( 104), -INT8_C(  76), -INT8_C( 107), -INT8_C( 123), -INT8_C(  65), -INT8_C(  38) },
        { {  INT8_C(  69), -INT8_C(  39), -INT8_C(  86), -INT8_C(  23),  INT8_C(  27),  INT8_C(  89), -INT8_C( 100), -INT8_C(  60),
             INT8_C(  24),  INT8_C( 119), -INT8_C(  91), -INT8_C(  85),  INT8_C( 101),  INT8_C(  20), -INT8_C(  80),  INT8_C(  45) },
          {  INT8_C(  36), -INT8_C(  34),  INT8_C(  64),  INT8_C( 126),  INT8_C(  20),  INT8_C( 100), -INT8_C(  65), -INT8_C( 108),
            -INT8_C(  33), -INT8_C(  12), -INT8_C( 104), -INT8_C(  76), -INT8_C( 107), -INT8_C( 123), -INT8_C(  65), -INT8_C(  38) } },
    },
    { {  INT8_C(  95),  INT8_C( 106), -INT8_C(  61),  INT8_C( 122), -INT8_C(  61),  INT8_C(  95),  INT8_C(  62), -INT8_C(  37),
        -INT8_C(  41), -INT8_C(  29), -INT8_C( 122),  INT8_C(  60), -INT8_C(   9),  INT8_C(  54),  INT8_C( 105),  INT8_C(  27),
         INT8_C(  20), -INT8_C(  86), -INT8_C( 102),  INT8_C(  40),  INT8_C(  14),  INT8_C(  89), -INT8_C(  67), -INT8_C(  19),
         INT8_C(  77),  INT8_C(  85), -INT8_C(  94), -INT8_C(  29), -INT8_C(  37),  INT8_C(  97), -INT8_C(  67),  INT8_C(  58) },
        { {  INT8_C(  95),  INT8_C( 106), -INT8_C(  61),  INT8_C( 122), -INT8_C(  61),  INT8_C(  95),  INT8_C(  62), -INT8_C(  37),
            -INT8_C(  41), -INT8_C(  29), -INT8_C( 122),  INT8_C(  60), -INT8_C(   9),  INT8_C(  54),  INT8_C( 105),  INT8_C(  27) },
          {  INT8_C(  20), -INT8_C(  86), -INT8_C( 102),  INT8_C(  40),  INT8_C(  14),  INT8_C(  89), -INT8_C(  67), -INT8_C(  19),
             INT8_C(  77),  INT8_C(  85), -INT8_C(  94), -INT8_C(  29), -INT8_C(  37),  INT8_C(  97), -INT8_C(  67),  INT8_C(  58) } },
    },
    { { -INT8_C(  53), -INT8_C( 127), -INT8_C(  76), -INT8_C( 113), -INT8_C(  32), -INT8_C(  14),  INT8_C( 106), -INT8_C(  73),
        -INT8_C(  43), -INT8_C(  15), -INT8_C(  12), -INT8_C(  52),  INT8_C(  39),  INT8_C(  93), -INT8_C(  24),  INT8_C(  60),
         INT8_C(   7), -INT8_C( 126),  INT8_C( 100),  INT8_C(  22), -INT8_C(  37),  INT8_C(  33),  INT8_C(   3),  INT8_C(  40),
         INT8_C( 119), -INT8_C(  91),  INT8_C(  11),  INT8_C(  82),  INT8_C(   7), -INT8_C(  55), -INT8_C( 116), -INT8_C(  46) },
        { { -INT8_C(  53), -INT8_C( 127), -INT8_C(  76), -INT8_C( 113), -INT8_C(  32), -INT8_C(  14),  INT8_C( 106), -INT8_C(  73),
            -INT8_C(  43), -INT8_C(  15), -INT8_C(  12), -INT8_C(  52),  INT8_C(  39),  INT8_C(  93), -INT8_C(  24),  INT8_C(  60) },
          {  INT8_C(   7), -INT8_C( 126),  INT8_C( 100),  INT8_C(  22), -INT8_C(  37),  INT8_C(  33),  INT8_C(   3),  INT8_C(  40),
             INT8_C( 119), -INT8_C(  91),  INT8_C(  11),  INT8_C(  82),  INT8_C(   7), -INT8_C(  55), -INT8_C( 116), -INT8_C(  46) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16x2_t r = simde_vld1q_s8_x2(test_vec[i].buf);
    simde_int8x16x2_t expected = {{
        simde_vld1q_s8(test_vec[i].expected[0]),
        simde_vld1q_s8(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_i8x16x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int8_t buf[32];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vi8(2, 32, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int8x16x2_t val = simde_vld1q_s8_x2(buf);
    simde_test_arm_neon_write_i8x16x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t buf[16];
    int16_t expected[2][8];
  } test_vec[] = {
    { { -INT16_C( 32100), -INT16_C( 19381),  INT16_C(  2960), -INT16_C( 11469),  INT16_C( 18628), -INT16_C( 20611),  INT16_C( 28063), -INT16_C( 14327),
         INT16_C( 20098),  INT16_C( 29533),  INT16_C( 27675), -INT16_C(  5529),  INT16_C(  3588),  INT16_C(  3984), -INT16_C( 30383), -INT16_C(  4699) },
        { { -INT16_C( 32100), -INT16_C( 19381),  INT16_C(  2960), -INT16_C( 11469),  INT16_C( 18628), -INT16_C( 20611),  INT16_C( 28063), -INT16_C( 14327) },
          {  INT16_C( 20098),  INT16_C( 29533),  INT16_C( 27675), -INT16_C(  5529),  INT16_C(  3588),  INT16_C(  3984), -INT16_C( 30383), -INT16_C(  4699) } },
    },
    { { -INT16_C(  4085), -INT16_C( 25439), -INT16_C( 11012), -INT16_C( 16273), -INT16_C(  5092), -INT16_C( 17296),  INT16_C( 31065), -INT16_C(  9340),
        -INT16_C(  7737), -INT16_C(  7345), -INT16_C( 18867),  INT16_C( 21197),  INT16_C( 24260),  INT16_C(  5473),  INT16_C(  1767), -INT16_C(  3326) },
        { { -INT16_C(  4085), -INT16_C( 25439), -INT16_C( 11012), -INT16_C( 16273), -INT16_C(  5092), -INT16_C( 17296),  INT16_C( 31065), -INT16_C(  9340) },
          { -INT16_C(  7737), -INT16_C(  7345), -INT16_C( 18867),  INT16_C( 21197),  INT16_C( 24260),  INT16_C(  5473),  INT16_C(  1767), -INT16_C(  3326) } },
    },
    { { -INT16_C( 23561), -INT16_C(  3185), -INT16_C(   392), -INT16_C( 27469),  INT16_C(  9194),  INT16_C( 17488), -INT16_C( 11108),  INT16_C( 25631),
         INT16_C( 28341),  INT16_C(   839),  INT16_C(  5157), -INT16_C(  5803), -INT16_C( 18830),  INT16_C( 23295),  INT16_C(   445), -INT16_C( 19379) },
        { { -INT16_C( 23561), -INT16_C(  3185), -INT16_C(   392), -INT16_C( 27469),  INT16_C(  9194),  INT16_C( 17488), -INT16_C( 11108),  INT16_C( 25631) },
          {  INT16_C( 28341),  INT16_C(   839),  INT16_C(  5157), -INT16_C(  5803), -INT16_C( 18830),  INT16_C( 23295),  INT16_C(   445), -INT16_C( 19379) } },
    },
    { { -INT16_C(  9051),  INT16_C(  7591),  INT16_C( 23258), -INT16_C( 15183),  INT16_C(   638),  INT16_C(  6664),  INT16_C( 10454), -INT16_C( 29570),
        -INT16_C( 14954), -INT16_C( 17521), -INT16_C(  6950),  INT16_C( 19621), -INT16_C( 23398),  INT16_C( 22438), -INT16_C(  3163),  INT16_C( 18955) },
        { { -INT16_C(  9051),  INT16_C(  7591),  INT16_C( 23258), -INT16_C( 15183),  INT16_C(   638),  INT16_C(  6664),  INT16_C( 10454), -INT16_C( 29570) },
          { -INT16_C( 14954), -INT16_C( 17521), -INT16_C(  6950),  INT16_C( 19621), -INT16_C( 23398),  INT16_C( 22438), -INT16_C(  3163),  INT16_C( 18955) } },
    },
    { { -INT16_C( 19761), -INT16_C( 22169),  INT16_C(  6413), -INT16_C( 29842),  INT16_C( 30235), -INT16_C(  3675),  INT16_C(  9374),  INT16_C( 13693),
         INT16_C(  3305), -INT16_C( 15376), -INT16_C( 27152), -INT16_C( 29936), -INT16_C( 18887), -INT16_C(  8222), -INT16_C(  4438),  INT16_C( 31017) },
        { { -INT16_C( 19761), -INT16_C( 22169),  INT16_C(  6413), -INT16_C( 29842),  INT16_C( 30235), -INT16_C(  3675),  INT16_C(  9374),  INT16_C( 13693) },
          {  INT16_C(  3305), -INT16_C( 15376), -INT16_C( 27152), -INT16_C( 29936), -INT16_C( 18887), -INT16_C(  8222), -INT16_C(  4438),  INT16_C( 31017) } },
    },
    { { -INT16_C( 28256), -INT16_C( 21213), -INT16_C( 28246), -INT16_C( 15048), -INT16_C(  8697), -INT16_C( 22858),  INT16_C( 13314), -INT16_C(  5157),
        -INT16_C( 13504),  INT16_C( 12719), -INT16_C( 16543), -INT16_C( 25924), -INT16_C( 24971),  INT16_C(  8057), -INT16_C( 23668),  INT16_C( 11673) },
        { { -INT16_C( 28256), -INT16_C( 21213), -INT16_C( 28246), -INT16_C( 15048), -INT16_C(  8697), -INT16_C( 22858),  INT16_C( 13314), -INT16_C(  5157) },
          { -INT16_C( 13504),  INT16_C( 12719), -INT16_C( 16543), -INT16_C( 25924), -INT16_C( 24971),  INT16_C(  8057), -INT16_C( 23668),  INT16_C( 11673) } },
    },
    { { -INT16_C( 17356), -INT16_C(  8486),  INT16_C(  4941),  INT16_C( 21667),  INT16_C( 23025), -INT16_C(  3078), -INT16_C( 10867), -INT16_C( 12578),
        -INT16_C( 29279),  INT16_C(   767), -INT16_C( 17588), -INT16_C( 15716),  INT16_C(  5721), -INT16_C(  6431),  INT16_C( 31417), -INT16_C(  4845) },
        { { -INT16_C( 17356), -INT16_C(  8486),  INT16_C(  4941),  INT16_C( 21667),  INT16_C( 23025), -INT16_C(  3078), -INT16_C( 10867), -INT16_C( 12578) },
          { -INT16_C( 29279),  INT16_C(   767), -INT16_C( 17588), -INT16_C( 15716),  INT16_C(  5721), -INT16_C(  6431),  INT16_C( 31417), -INT16_C(  4845) } },
    },
    { { -INT16_C(  4810), -INT16_C( 31797),  INT16_C( 28160), -INT16_C(  3624), -INT16_C( 11577),  INT16_C( 21988), -INT16_C( 15448),  INT16_C( 18723),
         INT16_C(  8784), -INT16_C( 25269), -INT16_C(  6179),  INT16_C( 13919),  INT16_C( 16637), -INT16_C( 18916),  INT16_C( 12219), -INT16_C(  3677) },
        { { -INT16_C(  4810), -INT16_C( 31797),  INT16_C( 28160), -INT16_C(  3624), -INT16_C( 11577),  INT16_C( 21988), -INT16_C( 15448),  INT16_C( 18723) },
          {  INT16_C(  8784), -INT16_C( 25269), -INT16_C(  6179),  INT16_C( 13919),  INT16_C( 16637), -INT16_C( 18916),  INT16_C( 12219), -INT16_C(  3677) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8x2_t r = simde_vld1q_s16_x2(test_vec[i].buf);
    simde_int16x8x2_t expected = {{
        simde_vld1q_s16(test_vec[i].expected[0]),
        simde_vld1q_s16(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_i16x8x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int16_t buf[16];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vi16(2, 16, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int16x8x2_t val = simde_vld1q_s16_x2(buf);
    simde_test_arm_neon_write_i16x8x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t buf[8];
    int32_t expected[2][4];
  } test_vec[] = {
    { { -INT32_C(   762919624),  INT32_C(   149692731), -INT32_C(   296545614),  INT32_C(  1267844380), -INT32_C(  1550454676), -INT32_C(  1798459241), -INT32_C(  2008421263), -INT32_C(  1030084726) },
        { { -INT32_C(   762919624),  INT32_C(   149692731), -INT32_C(   296545614),  INT32_C(  1267844380) },
          { -INT32_C(  1550454676), -INT32_C(  1798459241), -INT32_C(  2008421263), -INT32_C(  1030084726) } },
    },
    { {  INT32_C(   680796397), -INT32_C(   198148030), -INT32_C(  1344109421), -INT32_C(  1241877431), -INT32_C(    61239196), -INT32_C(  1299175872), -INT32_C(  1673864942), -INT32_C(   295775231) },
        { {  INT32_C(   680796397), -INT32_C(   198148030), -INT32_C(  1344109421), -INT32_C(  1241877431) },
          { -INT32_C(    61239196), -INT32_C(  1299175872), -INT32_C(  1673864942), -INT32_C(   295775231) } },
    },
    { {  INT32_C(   924250869),  INT32_C(   103499635),  INT32_C(   347410123), -INT32_C(   422989694), -INT32_C(  2132663744),  INT32_C(  1530032969),  INT32_C(  1308126284),  INT32_C(   909858369) },
        { {  INT32_C(   924250869),  INT32_C(   103499635),  INT32_C(   347410123), -INT32_C(   422989694) },
          { -INT32_C(  2132663744),  INT32_C(  1530032969),  INT32_C(  1308126284),  INT32_C(   909858369) } },
    },
    { { -INT32_C(  1133686199),  INT32_C(  1690474649),  INT32_C(   678983590),  INT32_C(  1729052967), -INT32_C(  1377242780), -INT32_C(  1324869020), -INT32_C(   922877817), -INT32_C(  1593951657) },
        { { -INT32_C(  1133686199),  INT32_C(  1690474649),  INT32_C(   678983590),  INT32_C(  1729052967) },
          { -INT32_C(  1377242780), -INT32_C(  1324869020), -INT32_C(   922877817), -INT32_C(  1593951657) } },
    },
    { {  INT32_C(   626813836), -INT32_C(  1433854461), -INT32_C(  1110310507), -INT32_C(  1507532478),  INT32_C(   928189651), -INT32_C(  1360503769), -INT32_C(  1284053156), -INT32_C(  1387039711) },
        { {  INT32_C(   626813836), -INT32_C(  1433854461), -INT32_C(  1110310507), -INT32_C(  1507532478) },
          {  INT32_C(   928189651), -INT32_C(  1360503769), -INT32_C(  1284053156), -INT32_C(  1387039711) } },
    },
    { { -INT32_C(   489508897),  INT32_C(  1670142925), -INT32_C(  1642045604),  INT32_C(   323306560),  INT32_C(  2018220113),  INT32_C(  1361458164),  INT32_C(   990157850), -INT32_C(   269985776) },
        { { -INT32_C(   489508897),  INT32_C(  1670142925), -INT32_C(  1642045604),  INT32_C(   323306560) },
          {  INT32_C(  2018220113),  INT32_C(  1361458164),  INT32_C(   990157850), -INT32_C(   269985776) } },
    },
    { { -INT32_C(   707675641),  INT32_C(  1899519509), -INT32_C(    49260355), -INT32_C(   317631076), -INT32_C(   496673555), -INT32_C(  1439462513),  INT32_C(   937768743), -INT32_C(  1759064433) },
        { { -INT32_C(   707675641),  INT32_C(  1899519509), -INT32_C(    49260355), -INT32_C(   317631076) },
          { -INT32_C(   496673555), -INT32_C(  1439462513),  INT32_C(   937768743), -INT32_C(  1759064433) } },
    },
    { { -INT32_C(  1637025656),  INT32_C(   319792214), -INT32_C(  1743773700),  INT32_C(  1652957556),  INT32_C(   222620541), -INT32_C(  1632143497),  INT32_C(  1054252206), -INT32_C(   204080022) },
        { { -INT32_C(  1637025656),  INT32_C(   319792214), -INT32_C(  1743773700),  INT32_C(  1652957556) },
          {  INT32_C(   222620541), -INT32_C(  1632143497),  INT32_C(  1054252206), -INT32_C(   204080022) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4x2_t r = simde_vld1q_s32_x2(test_vec[i].buf);
    simde_int32x4x2_t expected = {{
        simde_vld1q_s32(test_vec[i].expected[0]),
        simde_vld1q_s32(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_i32x4x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int32_t buf[8];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vi32(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int32x4x2_t val = simde_vld1q_s32_x2(buf);
    simde_test_arm_neon_write_i32x4x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_s64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t buf[4];
    int64_t expected[2][2];
  } test_vec[] = {
    { { -INT64_C( 2207431335682686476),  INT64_C(  979250959525441216),  INT64_C(     230147468483307), -INT64_C( 4050121639302605203) },
        { { -INT64_C( 2207431335682686476),  INT64_C(  979250959525441216) },
          {  INT64_C(     230147468483307), -INT64_C( 4050121639302605203) } },
    },
    { { -INT64_C( 4892474916104676268),  INT64_C( 9113745863212110813), -INT64_C( 3264018577499319198),  INT64_C( 6363996410817999287) },
        { { -INT64_C( 4892474916104676268),  INT64_C( 9113745863212110813) },
          { -INT64_C( 3264018577499319198),  INT64_C( 6363996410817999287) } },
    },
    { { -INT64_C( 5725575050056080431),  INT64_C( 7300501038633417535), -INT64_C( 4079192465958490069),  INT64_C( 6060336034876558781) },
        { { -INT64_C( 5725575050056080431),  INT64_C( 7300501038633417535) },
          { -INT64_C( 4079192465958490069),  INT64_C( 6060336034876558781) } },
    },
    { { -INT64_C( 7599070828417602554),  INT64_C( 7678839946117424936),  INT64_C( 3657026758223047144), -INT64_C( 4953097891104943509) },
        { { -INT64_C( 7599070828417602554),  INT64_C( 7678839946117424936) },
          {  INT64_C( 3657026758223047144), -INT64_C( 4953097891104943509) } },
    },
    { {  INT64_C( 4299001481783502267), -INT64_C( 5588694690520755770),  INT64_C( 3767099224226491296),  INT64_C(  499449081851231358) },
        { {  INT64_C( 4299001481783502267), -INT64_C( 5588694690520755770) },
          {  INT64_C( 3767099224226491296),  INT64_C(  499449081851231358) } },
    },
    { {  INT64_C( 7573297153655210955),  INT64_C( 1607748193023328211), -INT64_C( 1925443429153899703), -INT64_C( 7277809503211853137) },
        { {  INT64_C( 7573297153655210955),  INT64_C( 1607748193023328211) },
          { -INT64_C( 1925443429153899703), -INT64_C( 7277809503211853137) } },
    },
    { { -INT64_C( 5938679067871471478),  INT64_C( 3215457857194034194), -INT64_C( 1377954984720676204), -INT64_C( 8548985481522120465) },
        { { -INT64_C( 5938679067871471478),  INT64_C( 3215457857194034194) },
          { -INT64_C( 1377954984720676204), -INT64_C( 8548985481522120465) } },
    },
    { {  INT64_C( 8756769434874795263), -INT64_C(  117761641587552177),  INT64_C( 1267158708278369387),  INT64_C( 7014967073009859538) },
        { {  INT64_C( 8756769434874795263), -INT64_C(  117761641587552177) },
          {  INT64_C( 1267158708278369387),  INT64_C( 7014967073009859538) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x2x2_t r = simde_vld1q_s64_x2(test_vec[i].buf);
    simde_int64x2x2_t expected = {{
        simde_vld1q_s64(test_vec[i].expected[0]),
        simde_vld1q_s64(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_i64x2x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int64_t buf[4];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vi64(2, 4, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int64x2x2_t val = simde_vld1q_s64_x2(buf);
    simde_test_arm_neon_write_i64x2x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u8_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t buf[32];
    uint8_t expected[2][16];
  } test_vec[] = {
    { { UINT8_C(  1), UINT8_C(207), UINT8_C( 90), UINT8_C( 91), UINT8_C(  1), UINT8_C(120), UINT8_C(244), UINT8_C( 26),
        UINT8_C( 39), UINT8_C( 61), UINT8_C( 30), UINT8_C(124), UINT8_C(117), UINT8_C(182), UINT8_C(248), UINT8_C(134),
        UINT8_C(103), UINT8_C(254), UINT8_C(116), UINT8_C(200), UINT8_C(  4), UINT8_C(177), UINT8_C(119), UINT8_C(104),
        UINT8_C(147), UINT8_C( 37), UINT8_C(120), UINT8_C( 21), UINT8_C(213), UINT8_C( 20), UINT8_C(135), UINT8_C(214) },
        { { UINT8_C(  1), UINT8_C(207), UINT8_C( 90), UINT8_C( 91), UINT8_C(  1), UINT8_C(120), UINT8_C(244), UINT8_C( 26),
            UINT8_C( 39), UINT8_C( 61), UINT8_C( 30), UINT8_C(124), UINT8_C(117), UINT8_C(182), UINT8_C(248), UINT8_C(134) },
          { UINT8_C(103), UINT8_C(254), UINT8_C(116), UINT8_C(200), UINT8_C(  4), UINT8_C(177), UINT8_C(119), UINT8_C(104),
            UINT8_C(147), UINT8_C( 37), UINT8_C(120), UINT8_C( 21), UINT8_C(213), UINT8_C( 20), UINT8_C(135), UINT8_C(214) } },
    },
    { { UINT8_C(227), UINT8_C(225), UINT8_C( 50), UINT8_C(229), UINT8_C( 89), UINT8_C( 38),    UINT8_MAX, UINT8_C(128),
        UINT8_C(100), UINT8_C( 29), UINT8_C(252), UINT8_C(217), UINT8_C(211), UINT8_C(244), UINT8_C( 95), UINT8_C( 59),
        UINT8_C(242), UINT8_C(212), UINT8_C(  3), UINT8_C(246), UINT8_C(133), UINT8_C(122), UINT8_C( 94), UINT8_C( 25),
        UINT8_C(159), UINT8_C(215), UINT8_C( 46), UINT8_C(117), UINT8_C(235), UINT8_C(181), UINT8_C( 75), UINT8_C(206) },
        { { UINT8_C(227), UINT8_C(225), UINT8_C( 50), UINT8_C(229), UINT8_C( 89), UINT8_C( 38),    UINT8_MAX, UINT8_C(128),
            UINT8_C(100), UINT8_C( 29), UINT8_C(252), UINT8_C(217), UINT8_C(211), UINT8_C(244), UINT8_C( 95), UINT8_C( 59) },
          { UINT8_C(242), UINT8_C(212), UINT8_C(  3), UINT8_C(246), UINT8_C(133), UINT8_C(122), UINT8_C( 94), UINT8_C( 25),
            UINT8_C(159), UINT8_C(215), UINT8_C( 46), UINT8_C(117), UINT8_C(235), UINT8_C(181), UINT8_C( 75), UINT8_C(206) } },
    },
    { { UINT8_C(150), UINT8_C(125), UINT8_C(179), UINT8_C(239), UINT8_C(164), UINT8_C(178), UINT8_C(111), UINT8_C(  8),
        UINT8_C(208), UINT8_C(107), UINT8_C(225), UINT8_C(163), UINT8_C( 95), UINT8_C( 64), UINT8_C(222), UINT8_C( 81),
        UINT8_C( 20), UINT8_C(226), UINT8_C( 71), UINT8_C(154), UINT8_C( 92), UINT8_C(166), UINT8_C(179), UINT8_C(252),
        UINT8_C(125), UINT8_C(225), UINT8_C(113), UINT8_C(104), UINT8_C(150), UINT8_C(188), UINT8_C( 54), UINT8_C( 44) },
        { { UINT8_C(150), UINT8_C(125), UINT8_C(179), UINT8_C(239), UINT8_C(164), UINT8_C(178), UINT8_C(111), UINT8_C(  8),
            UINT8_C(208), UINT8_C(107), UINT8_C(225), UINT8_C(163), UINT8_C( 95), UINT8_C( 64), UINT8_C(222), UINT8_C( 81) },
          { UINT8_C( 20), UINT8_C(226), UINT8_C( 71), UINT8_C(154), UINT8_C( 92), UINT8_C(166), UINT8_C(179), UINT8_C(252),
            UINT8_C(125), UINT8_C(225), UINT8_C(113), UINT8_C(104), UINT8_C(150), UINT8_C(188), UINT8_C( 54), UINT8_C( 44) } },
    },
    { { UINT8_C( 58), UINT8_C(234), UINT8_C( 27), UINT8_C(222), UINT8_C(156), UINT8_C(138), UINT8_C(230), UINT8_C(108),
        UINT8_C(245), UINT8_C(199), UINT8_C( 16), UINT8_C( 84), UINT8_C(  7), UINT8_C(238), UINT8_C(165), UINT8_C( 28),
        UINT8_C(208), UINT8_C(236), UINT8_C(182), UINT8_C( 45), UINT8_C(146), UINT8_C(105), UINT8_C( 41), UINT8_C( 15),
        UINT8_C( 74), UINT8_C(154), UINT8_C(119), UINT8_C(224), UINT8_C( 86), UINT8_C(174), UINT8_C( 12), UINT8_C(144) },
        { { UINT8_C( 58), UINT8_C(234), UINT8_C( 27), UINT8_C(222), UINT8_C(156), UINT8_C(138), UINT8_C(230), UINT8_C(108),
            UINT8_C(245), UINT8_C(199), UINT8_C( 16), UINT8_C( 84), UINT8_C(  7), UINT8_C(238), UINT8_C(165), UINT8_C( 28) },
          { UINT8_C(208), UINT8_C(236), UINT8_C(182), UINT8_C( 45), UINT8_C(146), UINT8_C(105), UINT8_C( 41), UINT8_C( 15),
            UINT8_C( 74), UINT8_C(154), UINT8_C(119), UINT8_C(224), UINT8_C( 86), UINT8_C(174), UINT8_C( 12), UINT8_C(144) } },
    },
    { { UINT8_C(152), UINT8_C( 39), UINT8_C(110), UINT8_C( 52), UINT8_C(177), UINT8_C( 84), UINT8_C(161), UINT8_C(166),
        UINT8_C( 27), UINT8_C(177), UINT8_C(250), UINT8_C( 35), UINT8_C(159), UINT8_C(159), UINT8_C( 63), UINT8_C(112),
        UINT8_C(139), UINT8_C(245), UINT8_C(157), UINT8_C( 30), UINT8_C( 94), UINT8_C(198), UINT8_C( 45), UINT8_C(168),
        UINT8_C( 96), UINT8_C(165), UINT8_C(136), UINT8_C(182), UINT8_C( 83), UINT8_C(148), UINT8_C( 71), UINT8_C(235) },
        { { UINT8_C(152), UINT8_C( 39), UINT8_C(110), UINT8_C( 52), UINT8_C(177), UINT8_C( 84), UINT8_C(161), UINT8_C(166),
            UINT8_C( 27), UINT8_C(177), UINT8_C(250), UINT8_C( 35), UINT8_C(159), UINT8_C(159), UINT8_C( 63), UINT8_C(112) },
          { UINT8_C(139), UINT8_C(245), UINT8_C(157), UINT8_C( 30), UINT8_C( 94), UINT8_C(198), UINT8_C( 45), UINT8_C(168),
            UINT8_C( 96), UINT8_C(165), UINT8_C(136), UINT8_C(182), UINT8_C( 83), UINT8_C(148), UINT8_C( 71), UINT8_C(235) } },
    },
    { { UINT8_C(187), UINT8_C(181), UINT8_C( 31), UINT8_C(108), UINT8_C( 10), UINT8_C(192), UINT8_C( 18), UINT8_C( 37),
        UINT8_C(113), UINT8_C( 12), UINT8_C( 72), UINT8_C( 17), UINT8_C(171), UINT8_C(135), UINT8_C(129), UINT8_C( 54),
        UINT8_C(124), UINT8_C( 30), UINT8_C( 84), UINT8_C(218), UINT8_C(228), UINT8_C(130), UINT8_C(130), UINT8_C( 68),
        UINT8_C( 39), UINT8_C( 10), UINT8_C(250), UINT8_C(122), UINT8_C(158), UINT8_C( 65), UINT8_C(101), UINT8_C( 89) },
        { { UINT8_C(187), UINT8_C(181), UINT8_C( 31), UINT8_C(108), UINT8_C( 10), UINT8_C(192), UINT8_C( 18), UINT8_C( 37),
            UINT8_C(113), UINT8_C( 12), UINT8_C( 72), UINT8_C( 17), UINT8_C(171), UINT8_C(135), UINT8_C(129), UINT8_C( 54) },
          { UINT8_C(124), UINT8_C( 30), UINT8_C( 84), UINT8_C(218), UINT8_C(228), UINT8_C(130), UINT8_C(130), UINT8_C( 68),
            UINT8_C( 39), UINT8_C( 10), UINT8_C(250), UINT8_C(122), UINT8_C(158), UINT8_C( 65), UINT8_C(101), UINT8_C( 89) } },
    },
    { { UINT8_C(247), UINT8_C(132), UINT8_C(197), UINT8_C(  1), UINT8_C( 69), UINT8_C(215), UINT8_C( 38), UINT8_C(182),
        UINT8_C(227), UINT8_C(111), UINT8_C(199), UINT8_C(142), UINT8_C(246), UINT8_C( 72), UINT8_C(197), UINT8_C(115),
        UINT8_C(102), UINT8_C( 25), UINT8_C( 77), UINT8_C( 74), UINT8_C(155), UINT8_C(208), UINT8_C(142), UINT8_C(194),
        UINT8_C(218), UINT8_C(137), UINT8_C( 60), UINT8_C(121), UINT8_C(202), UINT8_C(161), UINT8_C(210), UINT8_C(193) },
        { { UINT8_C(247), UINT8_C(132), UINT8_C(197), UINT8_C(  1), UINT8_C( 69), UINT8_C(215), UINT8_C( 38), UINT8_C(182),
            UINT8_C(227), UINT8_C(111), UINT8_C(199), UINT8_C(142), UINT8_C(246), UINT8_C( 72), UINT8_C(197), UINT8_C(115) },
          { UINT8_C(102), UINT8_C( 25), UINT8_C( 77), UINT8_C( 74), UINT8_C(155), UINT8_C(208), UINT8_C(142), UINT8_C(194),
            UINT8_C(218), UINT8_C(137), UINT8_C( 60), UINT8_C(121), UINT8_C(202), UINT8_C(161), UINT8_C(210), UINT8_C(193) } },
    },
    { { UINT8_C( 38), UINT8_C(152), UINT8_C(194), UINT8_C(107), UINT8_C(111), UINT8_C(233), UINT8_C( 33), UINT8_C( 83),
        UINT8_C( 88), UINT8_C(233), UINT8_C(225), UINT8_C( 78), UINT8_C( 49), UINT8_C(166), UINT8_C(193), UINT8_C(152),
        UINT8_C(192), UINT8_C( 15), UINT8_C(226), UINT8_C( 91), UINT8_C(223), UINT8_C(113), UINT8_C( 30), UINT8_C(185),
        UINT8_C(250), UINT8_C( 90), UINT8_C( 50), UINT8_C(196), UINT8_C(252), UINT8_C(  5), UINT8_C(134), UINT8_C( 34) },
        { { UINT8_C( 38), UINT8_C(152), UINT8_C(194), UINT8_C(107), UINT8_C(111), UINT8_C(233), UINT8_C( 33), UINT8_C( 83),
            UINT8_C( 88), UINT8_C(233), UINT8_C(225), UINT8_C( 78), UINT8_C( 49), UINT8_C(166), UINT8_C(193), UINT8_C(152) },
          { UINT8_C(192), UINT8_C( 15), UINT8_C(226), UINT8_C( 91), UINT8_C(223), UINT8_C(113), UINT8_C( 30), UINT8_C(185),
            UINT8_C(250), UINT8_C( 90), UINT8_C( 50), UINT8_C(196), UINT8_C(252), UINT8_C(  5), UINT8_C(134), UINT8_C( 34) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16x2_t r = simde_vld1q_u8_x2(test_vec[i].buf);
    simde_uint8x16x2_t expected = {{
        simde_vld1q_u8(test_vec[i].expected[0]),
        simde_vld1q_u8(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_u8x16x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t buf[32];
    simde_test_codegen_random_memory(32, buf);
    simde_test_codegen_write_vu8(2, 32, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint8x16x2_t val = simde_vld1q_u8_x2(buf);
    simde_test_arm_neon_write_u8x16x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t buf[16];
    uint16_t expected[2][8];
  } test_vec[] = {
    { { UINT16_C(  825), UINT16_C(10210), UINT16_C( 3731), UINT16_C( 5598), UINT16_C(24657), UINT16_C(20451), UINT16_C(21382), UINT16_C(34867),
        UINT16_C(63322), UINT16_C(32517), UINT16_C(49700), UINT16_C(46516), UINT16_C(37728), UINT16_C(62645), UINT16_C(14775), UINT16_C(61520) },
        { { UINT16_C(  825), UINT16_C(10210), UINT16_C( 3731), UINT16_C( 5598), UINT16_C(24657), UINT16_C(20451), UINT16_C(21382), UINT16_C(34867) },
          { UINT16_C(63322), UINT16_C(32517), UINT16_C(49700), UINT16_C(46516), UINT16_C(37728), UINT16_C(62645), UINT16_C(14775), UINT16_C(61520) } },
    },
    { { UINT16_C(12860), UINT16_C(53016), UINT16_C(63040), UINT16_C(37348), UINT16_C(51030), UINT16_C(56544), UINT16_C( 4890), UINT16_C(29796),
        UINT16_C(26890), UINT16_C(12276), UINT16_C(43052), UINT16_C(36068), UINT16_C(39228), UINT16_C(62336), UINT16_C(53458), UINT16_C( 3811) },
        { { UINT16_C(12860), UINT16_C(53016), UINT16_C(63040), UINT16_C(37348), UINT16_C(51030), UINT16_C(56544), UINT16_C( 4890), UINT16_C(29796) },
          { UINT16_C(26890), UINT16_C(12276), UINT16_C(43052), UINT16_C(36068), UINT16_C(39228), UINT16_C(62336), UINT16_C(53458), UINT16_C( 3811) } },
    },
    { { UINT16_C(64258), UINT16_C(17118), UINT16_C(49905), UINT16_C(18643), UINT16_C(46218), UINT16_C(42020), UINT16_C(35271), UINT16_C(53785),
        UINT16_C( 3570), UINT16_C( 7681), UINT16_C(58805), UINT16_C(61867), UINT16_C(11134), UINT16_C(20964), UINT16_C(51452), UINT16_C(65119) },
        { { UINT16_C(64258), UINT16_C(17118), UINT16_C(49905), UINT16_C(18643), UINT16_C(46218), UINT16_C(42020), UINT16_C(35271), UINT16_C(53785) },
          { UINT16_C( 3570), UINT16_C( 7681), UINT16_C(58805), UINT16_C(61867), UINT16_C(11134), UINT16_C(20964), UINT16_C(51452), UINT16_C(65119) } },
    },
    { { UINT16_C(15811), UINT16_C(46401), UINT16_C( 5120), UINT16_C(35581), UINT16_C( 8648), UINT16_C(36910), UINT16_C(18346), UINT16_C(40290),
        UINT16_C(25428), UINT16_C( 2747), UINT16_C(26184), UINT16_C(50939), UINT16_C(57490), UINT16_C(36375), UINT16_C(30632), UINT16_C(27532) },
        { { UINT16_C(15811), UINT16_C(46401), UINT16_C( 5120), UINT16_C(35581), UINT16_C( 8648), UINT16_C(36910), UINT16_C(18346), UINT16_C(40290) },
          { UINT16_C(25428), UINT16_C( 2747), UINT16_C(26184), UINT16_C(50939), UINT16_C(57490), UINT16_C(36375), UINT16_C(30632), UINT16_C(27532) } },
    },
    { { UINT16_C(52660), UINT16_C(46112), UINT16_C( 7650), UINT16_C(43582), UINT16_C(27967), UINT16_C(59706), UINT16_C(40116), UINT16_C( 2438),
        UINT16_C(17151), UINT16_C(18195), UINT16_C( 3752), UINT16_C(14862), UINT16_C( 9710), UINT16_C(38600), UINT16_C(21916), UINT16_C(20738) },
        { { UINT16_C(52660), UINT16_C(46112), UINT16_C( 7650), UINT16_C(43582), UINT16_C(27967), UINT16_C(59706), UINT16_C(40116), UINT16_C( 2438) },
          { UINT16_C(17151), UINT16_C(18195), UINT16_C( 3752), UINT16_C(14862), UINT16_C( 9710), UINT16_C(38600), UINT16_C(21916), UINT16_C(20738) } },
    },
    { { UINT16_C( 8738), UINT16_C( 1029), UINT16_C(17472), UINT16_C(32687), UINT16_C(59825), UINT16_C(25960), UINT16_C(61318), UINT16_C(34158),
        UINT16_C(33073), UINT16_C(55757), UINT16_C(56208), UINT16_C(32276), UINT16_C(56320), UINT16_C(40213), UINT16_C( 5937), UINT16_C(21742) },
        { { UINT16_C( 8738), UINT16_C( 1029), UINT16_C(17472), UINT16_C(32687), UINT16_C(59825), UINT16_C(25960), UINT16_C(61318), UINT16_C(34158) },
          { UINT16_C(33073), UINT16_C(55757), UINT16_C(56208), UINT16_C(32276), UINT16_C(56320), UINT16_C(40213), UINT16_C( 5937), UINT16_C(21742) } },
    },
    { { UINT16_C(62265), UINT16_C(31064), UINT16_C( 1847), UINT16_C(59640), UINT16_C(25073), UINT16_C(30542), UINT16_C(48208), UINT16_C(33276),
        UINT16_C(51518), UINT16_C(52826), UINT16_C(28324), UINT16_C(42316), UINT16_C(24907), UINT16_C(31810), UINT16_C(12408), UINT16_C(45776) },
        { { UINT16_C(62265), UINT16_C(31064), UINT16_C( 1847), UINT16_C(59640), UINT16_C(25073), UINT16_C(30542), UINT16_C(48208), UINT16_C(33276) },
          { UINT16_C(51518), UINT16_C(52826), UINT16_C(28324), UINT16_C(42316), UINT16_C(24907), UINT16_C(31810), UINT16_C(12408), UINT16_C(45776) } },
    },
    { { UINT16_C(10531), UINT16_C(23339), UINT16_C( 9264), UINT16_C( 8515), UINT16_C(37253), UINT16_C(54680), UINT16_C(38222), UINT16_C(35926),
        UINT16_C(45150), UINT16_C(  858), UINT16_C(42527), UINT16_C(27304), UINT16_C(59912), UINT16_C(32998), UINT16_C(46874), UINT16_C(15666) },
        { { UINT16_C(10531), UINT16_C(23339), UINT16_C( 9264), UINT16_C( 8515), UINT16_C(37253), UINT16_C(54680), UINT16_C(38222), UINT16_C(35926) },
          { UINT16_C(45150), UINT16_C(  858), UINT16_C(42527), UINT16_C(27304), UINT16_C(59912), UINT16_C(32998), UINT16_C(46874), UINT16_C(15666) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8x2_t r = simde_vld1q_u16_x2(test_vec[i].buf);
    simde_uint16x8x2_t expected = {{
        simde_vld1q_u16(test_vec[i].expected[0]),
        simde_vld1q_u16(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_u16x8x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t buf[16];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vu16(2, 16, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint16x8x2_t val = simde_vld1q_u16_x2(buf);
    simde_test_arm_neon_write_u16x8x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t buf[8];
    uint32_t expected[2][4];
  } test_vec[] = {
    { { UINT32_C(1731858432), UINT32_C(2866856027), UINT32_C(4191936912), UINT32_C(3992402306), UINT32_C(4137021909), UINT32_C(2634492619), UINT32_C( 141547686), UINT32_C(  57264387) },
        { { UINT32_C(1731858432), UINT32_C(2866856027), UINT32_C(4191936912), UINT32_C(3992402306) },
          { UINT32_C(4137021909), UINT32_C(2634492619), UINT32_C( 141547686), UINT32_C(  57264387) } },
    },
    { { UINT32_C( 879403993), UINT32_C(4091431523), UINT32_C(2934749740), UINT32_C(3365659891), UINT32_C(2696818901), UINT32_C(  20825691), UINT32_C(2701765790), UINT32_C(1336242806) },
        { { UINT32_C( 879403993), UINT32_C(4091431523), UINT32_C(2934749740), UINT32_C(3365659891) },
          { UINT32_C(2696818901), UINT32_C(  20825691), UINT32_C(2701765790), UINT32_C(1336242806) } },
    },
    { { UINT32_C(2021920533), UINT32_C(2255184474), UINT32_C( 255088412), UINT32_C( 282578747), UINT32_C(1521522431), UINT32_C(4200328796), UINT32_C( 278619290), UINT32_C(3948953814) },
        { { UINT32_C(2021920533), UINT32_C(2255184474), UINT32_C( 255088412), UINT32_C( 282578747) },
          { UINT32_C(1521522431), UINT32_C(4200328796), UINT32_C( 278619290), UINT32_C(3948953814) } },
    },
    { { UINT32_C(2858673232), UINT32_C(1664142918), UINT32_C(1634886694), UINT32_C( 846350899), UINT32_C(1015882464), UINT32_C(2872502288), UINT32_C( 599511373), UINT32_C(1645157138) },
        { { UINT32_C(2858673232), UINT32_C(1664142918), UINT32_C(1634886694), UINT32_C( 846350899) },
          { UINT32_C(1015882464), UINT32_C(2872502288), UINT32_C( 599511373), UINT32_C(1645157138) } },
    },
    { { UINT32_C(1175220991), UINT32_C(1739144257), UINT32_C(3553106848), UINT32_C(1157970533), UINT32_C(1837208157), UINT32_C(3357063035), UINT32_C(2615923849), UINT32_C(4026399471) },
        { { UINT32_C(1175220991), UINT32_C(1739144257), UINT32_C(3553106848), UINT32_C(1157970533) },
          { UINT32_C(1837208157), UINT32_C(3357063035), UINT32_C(2615923849), UINT32_C(4026399471) } },
    },
    { { UINT32_C(2922711405), UINT32_C(3843415621), UINT32_C(1605950969), UINT32_C(1973730584), UINT32_C(3420595792), UINT32_C(1720974301), UINT32_C(3187769039), UINT32_C(3870162553) },
        { { UINT32_C(2922711405), UINT32_C(3843415621), UINT32_C(1605950969), UINT32_C(1973730584) },
          { UINT32_C(3420595792), UINT32_C(1720974301), UINT32_C(3187769039), UINT32_C(3870162553) } },
    },
    { { UINT32_C(1284825607), UINT32_C(3123816896), UINT32_C(2652498310), UINT32_C(4145266087), UINT32_C(3250779875), UINT32_C(3223803377), UINT32_C(1283336659), UINT32_C( 791817255) },
        { { UINT32_C(1284825607), UINT32_C(3123816896), UINT32_C(2652498310), UINT32_C(4145266087) },
          { UINT32_C(3250779875), UINT32_C(3223803377), UINT32_C(1283336659), UINT32_C( 791817255) } },
    },
    { { UINT32_C(3480995342), UINT32_C(4136217967), UINT32_C(1033151126), UINT32_C(1127524447), UINT32_C(2399467166), UINT32_C( 525282123), UINT32_C(2087439700), UINT32_C( 145465081) },
        { { UINT32_C(3480995342), UINT32_C(4136217967), UINT32_C(1033151126), UINT32_C(1127524447) },
          { UINT32_C(2399467166), UINT32_C( 525282123), UINT32_C(2087439700), UINT32_C( 145465081) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4x2_t r = simde_vld1q_u32_x2(test_vec[i].buf);
    simde_uint32x4x2_t expected = {{
        simde_vld1q_u32(test_vec[i].expected[0]),
        simde_vld1q_u32(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_u32x4x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t buf[8];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vu32(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint32x4x2_t val = simde_vld1q_u32_x2(buf);
    simde_test_arm_neon_write_u32x4x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1q_u64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t buf[4];
    uint64_t expected[2][2];
  } test_vec[] = {
    { { UINT64_C( 7695069376241149540), UINT64_C(11863849238367002114), UINT64_C( 2899617582647847122), UINT64_C(12344735216901072976) },
        { { UINT64_C( 7695069376241149540), UINT64_C(11863849238367002114) },
          { UINT64_C( 2899617582647847122), UINT64_C(12344735216901072976) } },
    },
    { { UINT64_C( 9994412847762712694), UINT64_C(  671757863263951783), UINT64_C( 6356096434846533177), UINT64_C(11528919454937438733) },
        { { UINT64_C( 9994412847762712694), UINT64_C(  671757863263951783) },
          { UINT64_C( 6356096434846533177), UINT64_C(11528919454937438733) } },
    },
    { { UINT64_C( 7939737045061696796), UINT64_C(16445015720835423223), UINT64_C(15084006253974872052), UINT64_C(  561300596492400385) },
        { { UINT64_C( 7939737045061696796), UINT64_C(16445015720835423223) },
          { UINT64_C(15084006253974872052), UINT64_C(  561300596492400385) } },
    },
    { { UINT64_C( 5176283381308830624), UINT64_C( 6090464697330823669), UINT64_C(11502939599304488717), UINT64_C( 9984643005128754846) },
        { { UINT64_C( 5176283381308830624), UINT64_C( 6090464697330823669) },
          { UINT64_C(11502939599304488717), UINT64_C( 9984643005128754846) } },
    },
    { { UINT64_C(  855057304594234182), UINT64_C(  966640045986173623), UINT64_C(   64880404244380585), UINT64_C( 9924272505232142150) },
        { { UINT64_C(  855057304594234182), UINT64_C(  966640045986173623) },
          { UINT64_C(   64880404244380585), UINT64_C( 9924272505232142150) } },
    },
    { { UINT64_C( 2915795372810939220), UINT64_C(18256653169024967247), UINT64_C(   55779027067353700), UINT64_C(13665867852189552602) },
        { { UINT64_C( 2915795372810939220), UINT64_C(18256653169024967247) },
          { UINT64_C(   55779027067353700), UINT64_C(13665867852189552602) } },
    },
    { { UINT64_C( 1238100404225951381), UINT64_C( 8796299825225166272), UINT64_C( 6607070381918476022), UINT64_C( 7024523383525663063) },
        { { UINT64_C( 1238100404225951381), UINT64_C( 8796299825225166272) },
          { UINT64_C( 6607070381918476022), UINT64_C( 7024523383525663063) } },
    },
    { { UINT64_C(  124014198478382308), UINT64_C(14741452376004499715), UINT64_C( 3700320471040710014), UINT64_C(15365279113249280527) },
        { { UINT64_C(  124014198478382308), UINT64_C(14741452376004499715) },
          { UINT64_C( 3700320471040710014), UINT64_C(15365279113249280527) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x2x2_t r = simde_vld1q_u64_x2(test_vec[i].buf);
    simde_uint64x2x2_t expected = {{
        simde_vld1q_u64(test_vec[i].expected[0]),
        simde_vld1q_u64(test_vec[i].expected[1]),
    }};
    simde_test_arm_neon_assert_equal_u64x2x2(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t buf[4];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vu64(2, 4, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint64x2x2_t val = simde_vld1q_u64_x2(buf);
    simde_test_arm_neon_write_u64x2x2(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_f32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_f64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_s64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1q_u64_x2)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
