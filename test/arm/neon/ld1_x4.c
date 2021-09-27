#define SIMDE_TEST_ARM_NEON_INSN ld1_x4
#include "test/test.h"
#include "test-neon.h"
#include "../../../simde/arm/neon/ld1_x4.h"
#include "../../../simde/arm/neon/ld1_lane.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld1_f32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 buf[8];
    simde_float32 expected[4][2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   137.86), SIMDE_FLOAT32_C(   778.17), SIMDE_FLOAT32_C(  -861.60), SIMDE_FLOAT32_C(  -441.21),
        SIMDE_FLOAT32_C(   356.14), SIMDE_FLOAT32_C(  -759.49), SIMDE_FLOAT32_C(   328.87), SIMDE_FLOAT32_C(   539.40) },
        { { SIMDE_FLOAT32_C(   137.86), SIMDE_FLOAT32_C(   778.17) },
          { SIMDE_FLOAT32_C(  -861.60), SIMDE_FLOAT32_C(  -441.21) },
          { SIMDE_FLOAT32_C(   356.14), SIMDE_FLOAT32_C(  -759.49) },
          { SIMDE_FLOAT32_C(   328.87), SIMDE_FLOAT32_C(   539.40) } },
    },
    { { SIMDE_FLOAT32_C(  -563.53), SIMDE_FLOAT32_C(   522.62), SIMDE_FLOAT32_C(  -958.77), SIMDE_FLOAT32_C(   366.07),
        SIMDE_FLOAT32_C(  -175.50), SIMDE_FLOAT32_C(  -243.76), SIMDE_FLOAT32_C(  -993.67), SIMDE_FLOAT32_C(  -884.19) },
        { { SIMDE_FLOAT32_C(  -563.53), SIMDE_FLOAT32_C(   522.62) },
          { SIMDE_FLOAT32_C(  -958.77), SIMDE_FLOAT32_C(   366.07) },
          { SIMDE_FLOAT32_C(  -175.50), SIMDE_FLOAT32_C(  -243.76) },
          { SIMDE_FLOAT32_C(  -993.67), SIMDE_FLOAT32_C(  -884.19) } },
    },
    { { SIMDE_FLOAT32_C(   700.43), SIMDE_FLOAT32_C(  -888.11), SIMDE_FLOAT32_C(  -358.64), SIMDE_FLOAT32_C(  -439.99),
        SIMDE_FLOAT32_C(   469.00), SIMDE_FLOAT32_C(   631.22), SIMDE_FLOAT32_C(   238.79), SIMDE_FLOAT32_C(   484.56) },
        { { SIMDE_FLOAT32_C(   700.43), SIMDE_FLOAT32_C(  -888.11) },
          { SIMDE_FLOAT32_C(  -358.64), SIMDE_FLOAT32_C(  -439.99) },
          { SIMDE_FLOAT32_C(   469.00), SIMDE_FLOAT32_C(   631.22) },
          { SIMDE_FLOAT32_C(   238.79), SIMDE_FLOAT32_C(   484.56) } },
    },
    { { SIMDE_FLOAT32_C(    66.66), SIMDE_FLOAT32_C(  -894.77), SIMDE_FLOAT32_C(  -261.86), SIMDE_FLOAT32_C(   -68.48),
        SIMDE_FLOAT32_C(   412.11), SIMDE_FLOAT32_C(  -232.31), SIMDE_FLOAT32_C(   243.52), SIMDE_FLOAT32_C(  -450.03) },
        { { SIMDE_FLOAT32_C(    66.66), SIMDE_FLOAT32_C(  -894.77) },
          { SIMDE_FLOAT32_C(  -261.86), SIMDE_FLOAT32_C(   -68.48) },
          { SIMDE_FLOAT32_C(   412.11), SIMDE_FLOAT32_C(  -232.31) },
          { SIMDE_FLOAT32_C(   243.52), SIMDE_FLOAT32_C(  -450.03) } },
    },
    { { SIMDE_FLOAT32_C(  -454.14), SIMDE_FLOAT32_C(   381.92), SIMDE_FLOAT32_C(   108.76), SIMDE_FLOAT32_C(   902.00),
        SIMDE_FLOAT32_C(   622.43), SIMDE_FLOAT32_C(  -562.37), SIMDE_FLOAT32_C(   441.40), SIMDE_FLOAT32_C(  -941.11) },
        { { SIMDE_FLOAT32_C(  -454.14), SIMDE_FLOAT32_C(   381.92) },
          { SIMDE_FLOAT32_C(   108.76), SIMDE_FLOAT32_C(   902.00) },
          { SIMDE_FLOAT32_C(   622.43), SIMDE_FLOAT32_C(  -562.37) },
          { SIMDE_FLOAT32_C(   441.40), SIMDE_FLOAT32_C(  -941.11) } },
    },
    { { SIMDE_FLOAT32_C(   960.24), SIMDE_FLOAT32_C(   482.63), SIMDE_FLOAT32_C(   424.96), SIMDE_FLOAT32_C(  -215.26),
        SIMDE_FLOAT32_C(  -761.13), SIMDE_FLOAT32_C(   431.30), SIMDE_FLOAT32_C(   -99.45), SIMDE_FLOAT32_C(   939.30) },
        { { SIMDE_FLOAT32_C(   960.24), SIMDE_FLOAT32_C(   482.63) },
          { SIMDE_FLOAT32_C(   424.96), SIMDE_FLOAT32_C(  -215.26) },
          { SIMDE_FLOAT32_C(  -761.13), SIMDE_FLOAT32_C(   431.30) },
          { SIMDE_FLOAT32_C(   -99.45), SIMDE_FLOAT32_C(   939.30) } },
    },
    { { SIMDE_FLOAT32_C(   543.19), SIMDE_FLOAT32_C(   541.90), SIMDE_FLOAT32_C(  -500.69), SIMDE_FLOAT32_C(    12.19),
        SIMDE_FLOAT32_C(   173.12), SIMDE_FLOAT32_C(   738.10), SIMDE_FLOAT32_C(  -503.25), SIMDE_FLOAT32_C(  -760.22) },
        { { SIMDE_FLOAT32_C(   543.19), SIMDE_FLOAT32_C(   541.90) },
          { SIMDE_FLOAT32_C(  -500.69), SIMDE_FLOAT32_C(    12.19) },
          { SIMDE_FLOAT32_C(   173.12), SIMDE_FLOAT32_C(   738.10) },
          { SIMDE_FLOAT32_C(  -503.25), SIMDE_FLOAT32_C(  -760.22) } },
    },
    { { SIMDE_FLOAT32_C(   843.33), SIMDE_FLOAT32_C(   234.89), SIMDE_FLOAT32_C(   171.30), SIMDE_FLOAT32_C(   255.44),
        SIMDE_FLOAT32_C(  -997.42), SIMDE_FLOAT32_C(  -585.18), SIMDE_FLOAT32_C(   805.40), SIMDE_FLOAT32_C(  -451.56) },
        { { SIMDE_FLOAT32_C(   843.33), SIMDE_FLOAT32_C(   234.89) },
          { SIMDE_FLOAT32_C(   171.30), SIMDE_FLOAT32_C(   255.44) },
          { SIMDE_FLOAT32_C(  -997.42), SIMDE_FLOAT32_C(  -585.18) },
          { SIMDE_FLOAT32_C(   805.40), SIMDE_FLOAT32_C(  -451.56) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2x4_t r = simde_vld1_f32_x4(test_vec[i].buf);
    simde_float32x2x4_t expected = {{
        simde_vld1_f32(test_vec[i].expected[0]),
        simde_vld1_f32(test_vec[i].expected[1]),
        simde_vld1_f32(test_vec[i].expected[2]),
        simde_vld1_f32(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_f32x2x4(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 buf[8];
    for (int j = 0 ; j < 8 ; j++) {
      buf[j] = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    }
    simde_test_codegen_write_vf32(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32x2x4_t val = simde_vld1_f32_x4(buf);
    simde_test_arm_neon_write_f32x2x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_f64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 buf[4];
    simde_float64 expected[4][1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   796.74), SIMDE_FLOAT64_C(   -85.84), SIMDE_FLOAT64_C(  -549.56), SIMDE_FLOAT64_C(   419.17) },
        { { SIMDE_FLOAT64_C(   796.74) },
          { SIMDE_FLOAT64_C(   -85.84) },
          { SIMDE_FLOAT64_C(  -549.56) },
          { SIMDE_FLOAT64_C(   419.17) } },
    },
    { { SIMDE_FLOAT64_C(   351.79), SIMDE_FLOAT64_C(   891.84), SIMDE_FLOAT64_C(   478.06), SIMDE_FLOAT64_C(   312.03) },
        { { SIMDE_FLOAT64_C(   351.79) },
          { SIMDE_FLOAT64_C(   891.84) },
          { SIMDE_FLOAT64_C(   478.06) },
          { SIMDE_FLOAT64_C(   312.03) } },
    },
    { { SIMDE_FLOAT64_C(   374.47), SIMDE_FLOAT64_C(   -96.98), SIMDE_FLOAT64_C(  -903.23), SIMDE_FLOAT64_C(   613.34) },
        { { SIMDE_FLOAT64_C(   374.47) },
          { SIMDE_FLOAT64_C(   -96.98) },
          { SIMDE_FLOAT64_C(  -903.23) },
          { SIMDE_FLOAT64_C(   613.34) } },
    },
    { { SIMDE_FLOAT64_C(  -665.68), SIMDE_FLOAT64_C(    -2.68), SIMDE_FLOAT64_C(   552.64), SIMDE_FLOAT64_C(   877.51) },
        { { SIMDE_FLOAT64_C(  -665.68) },
          { SIMDE_FLOAT64_C(    -2.68) },
          { SIMDE_FLOAT64_C(   552.64) },
          { SIMDE_FLOAT64_C(   877.51) } },
    },
    { { SIMDE_FLOAT64_C(  -460.78), SIMDE_FLOAT64_C(  -948.05), SIMDE_FLOAT64_C(  -110.30), SIMDE_FLOAT64_C(   712.34) },
        { { SIMDE_FLOAT64_C(  -460.78) },
          { SIMDE_FLOAT64_C(  -948.05) },
          { SIMDE_FLOAT64_C(  -110.30) },
          { SIMDE_FLOAT64_C(   712.34) } },
    },
    { { SIMDE_FLOAT64_C(   790.04), SIMDE_FLOAT64_C(   386.45), SIMDE_FLOAT64_C(   952.13), SIMDE_FLOAT64_C(   633.37) },
        { { SIMDE_FLOAT64_C(   790.04) },
          { SIMDE_FLOAT64_C(   386.45) },
          { SIMDE_FLOAT64_C(   952.13) },
          { SIMDE_FLOAT64_C(   633.37) } },
    },
    { { SIMDE_FLOAT64_C(  -378.66), SIMDE_FLOAT64_C(   123.43), SIMDE_FLOAT64_C(  -111.19), SIMDE_FLOAT64_C(  -376.08) },
        { { SIMDE_FLOAT64_C(  -378.66) },
          { SIMDE_FLOAT64_C(   123.43) },
          { SIMDE_FLOAT64_C(  -111.19) },
          { SIMDE_FLOAT64_C(  -376.08) } },
    },
    { { SIMDE_FLOAT64_C(   538.25), SIMDE_FLOAT64_C(  -305.79), SIMDE_FLOAT64_C(   172.36), SIMDE_FLOAT64_C(   334.99) },
        { { SIMDE_FLOAT64_C(   538.25) },
          { SIMDE_FLOAT64_C(  -305.79) },
          { SIMDE_FLOAT64_C(   172.36) },
          { SIMDE_FLOAT64_C(   334.99) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1x4_t r = simde_vld1_f64_x4(test_vec[i].buf);
    simde_float64x1x4_t expected = {{
        simde_vld1_f64(test_vec[i].expected[0]),
        simde_vld1_f64(test_vec[i].expected[1]),
        simde_vld1_f64(test_vec[i].expected[2]),
        simde_vld1_f64(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_f64x1x4(r, expected, 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 buf[4];
    for (int j = 0 ; j < 4 ; j++) {
      buf[j] = simde_test_codegen_random_f64(-1000.0, 1000.0);
    }
    simde_test_codegen_write_vf64(2, 4, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64x1x4_t val = simde_vld1_f64_x4(buf);
    simde_test_arm_neon_write_f64x1x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s8_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t buf[32];
    int8_t expected[4][8];
  } test_vec[] = {
    { { -INT8_C( 111),  INT8_C( 104),  INT8_C(  10), -INT8_C(  74),  INT8_C( 103), -INT8_C( 104), -INT8_C(  44), -INT8_C(  55),
        -INT8_C(  46), -INT8_C(  62),  INT8_C(  63), -INT8_C( 105), -INT8_C( 109),  INT8_C(   7),  INT8_C( 110),  INT8_C(   3),
         INT8_C(  11), -INT8_C(  79), -INT8_C(  93),  INT8_C(   5), -INT8_C( 106), -INT8_C( 107), -INT8_C(  33),  INT8_C(  80),
         INT8_C(  44),  INT8_C(  43), -INT8_C(  64),  INT8_C(  95), -INT8_C(   2), -INT8_C(  66),  INT8_C(  48), -INT8_C( 113) },
        { { -INT8_C( 111),  INT8_C( 104),  INT8_C(  10), -INT8_C(  74),  INT8_C( 103), -INT8_C( 104), -INT8_C(  44), -INT8_C(  55) },
          { -INT8_C(  46), -INT8_C(  62),  INT8_C(  63), -INT8_C( 105), -INT8_C( 109),  INT8_C(   7),  INT8_C( 110),  INT8_C(   3) },
          {  INT8_C(  11), -INT8_C(  79), -INT8_C(  93),  INT8_C(   5), -INT8_C( 106), -INT8_C( 107), -INT8_C(  33),  INT8_C(  80) },
          {  INT8_C(  44),  INT8_C(  43), -INT8_C(  64),  INT8_C(  95), -INT8_C(   2), -INT8_C(  66),  INT8_C(  48), -INT8_C( 113) } },
    },
    { {  INT8_C(  38),  INT8_C(  58),  INT8_C(  69), -INT8_C( 115), -INT8_C(  45),  INT8_C(  25),  INT8_C(  87), -INT8_C(  91),
        -INT8_C(  37), -INT8_C( 106),  INT8_C(  60),  INT8_C( 110), -INT8_C(  99), -INT8_C(  85),  INT8_C( 114), -INT8_C(  88),
         INT8_C(  92),  INT8_C(  21), -INT8_C(  83), -INT8_C(  14), -INT8_C(  85), -INT8_C( 116),  INT8_C(  67), -INT8_C(  41),
        -INT8_C(  73),  INT8_C(   3),  INT8_C(  55), -INT8_C(  75), -INT8_C(  63),  INT8_C( 103),  INT8_C(  69), -INT8_C(  25) },
        { {  INT8_C(  38),  INT8_C(  58),  INT8_C(  69), -INT8_C( 115), -INT8_C(  45),  INT8_C(  25),  INT8_C(  87), -INT8_C(  91) },
          { -INT8_C(  37), -INT8_C( 106),  INT8_C(  60),  INT8_C( 110), -INT8_C(  99), -INT8_C(  85),  INT8_C( 114), -INT8_C(  88) },
          {  INT8_C(  92),  INT8_C(  21), -INT8_C(  83), -INT8_C(  14), -INT8_C(  85), -INT8_C( 116),  INT8_C(  67), -INT8_C(  41) },
          { -INT8_C(  73),  INT8_C(   3),  INT8_C(  55), -INT8_C(  75), -INT8_C(  63),  INT8_C( 103),  INT8_C(  69), -INT8_C(  25) } },
    },
    { { -INT8_C(  94), -INT8_C( 118),  INT8_C( 117),  INT8_C( 117), -INT8_C(  92), -INT8_C(  52),  INT8_C(  26),      INT8_MAX,
         INT8_C(  98),  INT8_C(  87), -INT8_C(  18), -INT8_C(   1),  INT8_C(   2),  INT8_C(  96), -INT8_C(  89),  INT8_C(  94),
         INT8_C( 117),  INT8_C(  85),  INT8_C(  80),  INT8_C(  32), -INT8_C(  31), -INT8_C( 109), -INT8_C(   8), -INT8_C( 103),
        -INT8_C( 106),  INT8_C(  47),  INT8_C(  78),  INT8_C(  87), -INT8_C( 106), -INT8_C( 109),  INT8_C(  63),  INT8_C(  56) },
        { { -INT8_C(  94), -INT8_C( 118),  INT8_C( 117),  INT8_C( 117), -INT8_C(  92), -INT8_C(  52),  INT8_C(  26),      INT8_MAX },
          {  INT8_C(  98),  INT8_C(  87), -INT8_C(  18), -INT8_C(   1),  INT8_C(   2),  INT8_C(  96), -INT8_C(  89),  INT8_C(  94) },
          {  INT8_C( 117),  INT8_C(  85),  INT8_C(  80),  INT8_C(  32), -INT8_C(  31), -INT8_C( 109), -INT8_C(   8), -INT8_C( 103) },
          { -INT8_C( 106),  INT8_C(  47),  INT8_C(  78),  INT8_C(  87), -INT8_C( 106), -INT8_C( 109),  INT8_C(  63),  INT8_C(  56) } },
    },
    { {  INT8_C(  30), -INT8_C(  76), -INT8_C(  83), -INT8_C(  62),      INT8_MIN, -INT8_C(  56),  INT8_C(  65), -INT8_C(  30),
         INT8_C(  31),  INT8_C(  47), -INT8_C(  31),  INT8_C(  33), -INT8_C( 113), -INT8_C( 120),      INT8_MAX,  INT8_C(   5),
        -INT8_C(  35), -INT8_C(  49),  INT8_C(  37), -INT8_C(  65),  INT8_C(  99),  INT8_C(  29),  INT8_C(  88), -INT8_C(   7),
         INT8_C(  76), -INT8_C(  90),  INT8_C(  81), -INT8_C(  29),  INT8_C(  58), -INT8_C( 112),  INT8_C(  27),  INT8_C(  88) },
        { {  INT8_C(  30), -INT8_C(  76), -INT8_C(  83), -INT8_C(  62),      INT8_MIN, -INT8_C(  56),  INT8_C(  65), -INT8_C(  30) },
          {  INT8_C(  31),  INT8_C(  47), -INT8_C(  31),  INT8_C(  33), -INT8_C( 113), -INT8_C( 120),      INT8_MAX,  INT8_C(   5) },
          { -INT8_C(  35), -INT8_C(  49),  INT8_C(  37), -INT8_C(  65),  INT8_C(  99),  INT8_C(  29),  INT8_C(  88), -INT8_C(   7) },
          {  INT8_C(  76), -INT8_C(  90),  INT8_C(  81), -INT8_C(  29),  INT8_C(  58), -INT8_C( 112),  INT8_C(  27),  INT8_C(  88) } },
    },
    { {  INT8_C(  68), -INT8_C(  55),  INT8_C(  26), -INT8_C(  60), -INT8_C( 111),  INT8_C(  91), -INT8_C(  90), -INT8_C(  80),
        -INT8_C( 117), -INT8_C( 121), -INT8_C(  47),  INT8_C(  26),  INT8_C(  15),  INT8_C(  80),  INT8_C(  31), -INT8_C(  19),
         INT8_C(  31),  INT8_C(  69), -INT8_C(  84), -INT8_C( 126),  INT8_C(  98),  INT8_C(   4),  INT8_C( 124), -INT8_C(  81),
        -INT8_C(  86), -INT8_C(  51), -INT8_C( 110), -INT8_C(  28),  INT8_C(  93), -INT8_C(  83),  INT8_C(  60), -INT8_C(  95) },
        { {  INT8_C(  68), -INT8_C(  55),  INT8_C(  26), -INT8_C(  60), -INT8_C( 111),  INT8_C(  91), -INT8_C(  90), -INT8_C(  80) },
          { -INT8_C( 117), -INT8_C( 121), -INT8_C(  47),  INT8_C(  26),  INT8_C(  15),  INT8_C(  80),  INT8_C(  31), -INT8_C(  19) },
          {  INT8_C(  31),  INT8_C(  69), -INT8_C(  84), -INT8_C( 126),  INT8_C(  98),  INT8_C(   4),  INT8_C( 124), -INT8_C(  81) },
          { -INT8_C(  86), -INT8_C(  51), -INT8_C( 110), -INT8_C(  28),  INT8_C(  93), -INT8_C(  83),  INT8_C(  60), -INT8_C(  95) } },
    },
    { {  INT8_C( 118),  INT8_C(  86),  INT8_C( 101),  INT8_C(   7), -INT8_C(  78),  INT8_C(  11), -INT8_C(  73),  INT8_C(  61),
        -INT8_C( 110), -INT8_C( 120),  INT8_C(  87), -INT8_C(  95), -INT8_C(  40),  INT8_C( 119), -INT8_C( 114), -INT8_C(   8),
        -INT8_C(  68),  INT8_C(  58),  INT8_C( 122),  INT8_C(  30),  INT8_C(  62), -INT8_C(  10), -INT8_C(  51), -INT8_C(  23),
        -INT8_C(  61),  INT8_C(  95), -INT8_C(  51),  INT8_C(  32),  INT8_C(  13),  INT8_C(  10), -INT8_C(  63), -INT8_C( 125) },
        { {  INT8_C( 118),  INT8_C(  86),  INT8_C( 101),  INT8_C(   7), -INT8_C(  78),  INT8_C(  11), -INT8_C(  73),  INT8_C(  61) },
          { -INT8_C( 110), -INT8_C( 120),  INT8_C(  87), -INT8_C(  95), -INT8_C(  40),  INT8_C( 119), -INT8_C( 114), -INT8_C(   8) },
          { -INT8_C(  68),  INT8_C(  58),  INT8_C( 122),  INT8_C(  30),  INT8_C(  62), -INT8_C(  10), -INT8_C(  51), -INT8_C(  23) },
          { -INT8_C(  61),  INT8_C(  95), -INT8_C(  51),  INT8_C(  32),  INT8_C(  13),  INT8_C(  10), -INT8_C(  63), -INT8_C( 125) } },
    },
    { {  INT8_C(  96),  INT8_C(  38), -INT8_C( 117),  INT8_C(  18),  INT8_C(  49),  INT8_C(  66),  INT8_C(  79), -INT8_C(  61),
        -INT8_C(  53), -INT8_C(  89),  INT8_C( 101), -INT8_C(  93),  INT8_C(  30), -INT8_C(  13), -INT8_C( 101), -INT8_C(  38),
         INT8_C(  46),  INT8_C(  22), -INT8_C(   8),  INT8_C( 108),  INT8_C(  12), -INT8_C(  58),  INT8_C(  85), -INT8_C(  48),
         INT8_C(  37),  INT8_C(  35), -INT8_C(  16),  INT8_C(  50),  INT8_C(  45), -INT8_C(  78), -INT8_C(  74), -INT8_C( 115) },
        { {  INT8_C(  96),  INT8_C(  38), -INT8_C( 117),  INT8_C(  18),  INT8_C(  49),  INT8_C(  66),  INT8_C(  79), -INT8_C(  61) },
          { -INT8_C(  53), -INT8_C(  89),  INT8_C( 101), -INT8_C(  93),  INT8_C(  30), -INT8_C(  13), -INT8_C( 101), -INT8_C(  38) },
          {  INT8_C(  46),  INT8_C(  22), -INT8_C(   8),  INT8_C( 108),  INT8_C(  12), -INT8_C(  58),  INT8_C(  85), -INT8_C(  48) },
          {  INT8_C(  37),  INT8_C(  35), -INT8_C(  16),  INT8_C(  50),  INT8_C(  45), -INT8_C(  78), -INT8_C(  74), -INT8_C( 115) } },
    },
    { { -INT8_C(  40),  INT8_C(  65), -INT8_C(  96),  INT8_C(  10), -INT8_C( 125), -INT8_C(  17), -INT8_C(  51),  INT8_C(  78),
        -INT8_C( 106),  INT8_C(  50), -INT8_C(  14), -INT8_C(  76),  INT8_C(  38), -INT8_C( 115), -INT8_C( 114),  INT8_C(  84),
        -INT8_C(  93), -INT8_C( 121), -INT8_C(  64), -INT8_C(  80),  INT8_C(  77),  INT8_C(  22),      INT8_MIN,  INT8_C( 114),
         INT8_C(  57),  INT8_C( 112), -INT8_C(  91),  INT8_C( 102),  INT8_C(  34),  INT8_C(  91), -INT8_C(  13), -INT8_C(   5) },
        { { -INT8_C(  40),  INT8_C(  65), -INT8_C(  96),  INT8_C(  10), -INT8_C( 125), -INT8_C(  17), -INT8_C(  51),  INT8_C(  78) },
          { -INT8_C( 106),  INT8_C(  50), -INT8_C(  14), -INT8_C(  76),  INT8_C(  38), -INT8_C( 115), -INT8_C( 114),  INT8_C(  84) },
          { -INT8_C(  93), -INT8_C( 121), -INT8_C(  64), -INT8_C(  80),  INT8_C(  77),  INT8_C(  22),      INT8_MIN,  INT8_C( 114) },
          {  INT8_C(  57),  INT8_C( 112), -INT8_C(  91),  INT8_C( 102),  INT8_C(  34),  INT8_C(  91), -INT8_C(  13), -INT8_C(   5) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8x4_t r = simde_vld1_s8_x4(test_vec[i].buf);
    simde_int8x8x4_t expected = {{
        simde_vld1_s8(test_vec[i].expected[0]),
        simde_vld1_s8(test_vec[i].expected[1]),
        simde_vld1_s8(test_vec[i].expected[2]),
        simde_vld1_s8(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_i8x8x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int8_t buf[32];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vi8(2, 32, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int8x8x4_t val = simde_vld1_s8_x4(buf);
    simde_test_arm_neon_write_i8x8x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s16_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t buf[16];
    int16_t expected[4][4];
  } test_vec[] = {
    { { -INT16_C( 20908),  INT16_C(  1439),  INT16_C(  1963), -INT16_C(  9647), -INT16_C( 16336),  INT16_C(  8544), -INT16_C( 10833),  INT16_C(   374),
         INT16_C( 13836), -INT16_C( 20082), -INT16_C( 31603), -INT16_C(  6873), -INT16_C( 17432),  INT16_C( 22309), -INT16_C( 28696),  INT16_C( 15584) },
        { { -INT16_C( 20908),  INT16_C(  1439),  INT16_C(  1963), -INT16_C(  9647) },
          { -INT16_C( 16336),  INT16_C(  8544), -INT16_C( 10833),  INT16_C(   374) },
          {  INT16_C( 13836), -INT16_C( 20082), -INT16_C( 31603), -INT16_C(  6873) },
          { -INT16_C( 17432),  INT16_C( 22309), -INT16_C( 28696),  INT16_C( 15584) } },
    },
    { { -INT16_C( 32707), -INT16_C(  6078), -INT16_C( 27769), -INT16_C( 18494),  INT16_C(  9043),  INT16_C(   984),  INT16_C( 20216),  INT16_C(  1028),
        -INT16_C( 28028),  INT16_C(  4533), -INT16_C(  8938), -INT16_C(     9),  INT16_C(  7320), -INT16_C( 32426),  INT16_C( 13996), -INT16_C(  5699) },
        { { -INT16_C( 32707), -INT16_C(  6078), -INT16_C( 27769), -INT16_C( 18494) },
          {  INT16_C(  9043),  INT16_C(   984),  INT16_C( 20216),  INT16_C(  1028) },
          { -INT16_C( 28028),  INT16_C(  4533), -INT16_C(  8938), -INT16_C(     9) },
          {  INT16_C(  7320), -INT16_C( 32426),  INT16_C( 13996), -INT16_C(  5699) } },
    },
    { { -INT16_C(    74),  INT16_C( 15826), -INT16_C( 27502), -INT16_C(  6412), -INT16_C( 12873), -INT16_C( 20503), -INT16_C(  4837), -INT16_C( 24396),
         INT16_C( 27007), -INT16_C( 26959), -INT16_C( 22458), -INT16_C(  8299), -INT16_C(  5179),  INT16_C( 29024),  INT16_C(  7457), -INT16_C( 10150) },
        { { -INT16_C(    74),  INT16_C( 15826), -INT16_C( 27502), -INT16_C(  6412) },
          { -INT16_C( 12873), -INT16_C( 20503), -INT16_C(  4837), -INT16_C( 24396) },
          {  INT16_C( 27007), -INT16_C( 26959), -INT16_C( 22458), -INT16_C(  8299) },
          { -INT16_C(  5179),  INT16_C( 29024),  INT16_C(  7457), -INT16_C( 10150) } },
    },
    { {  INT16_C( 11293), -INT16_C( 20715),  INT16_C(  2753),  INT16_C( 30869),  INT16_C( 32471), -INT16_C(  3544), -INT16_C(  9109), -INT16_C(  5230),
         INT16_C( 17477), -INT16_C( 29567),  INT16_C(  5868), -INT16_C( 20117), -INT16_C( 13567),  INT16_C(  8738),  INT16_C( 32232),  INT16_C(  1530) },
        { {  INT16_C( 11293), -INT16_C( 20715),  INT16_C(  2753),  INT16_C( 30869) },
          {  INT16_C( 32471), -INT16_C(  3544), -INT16_C(  9109), -INT16_C(  5230) },
          {  INT16_C( 17477), -INT16_C( 29567),  INT16_C(  5868), -INT16_C( 20117) },
          { -INT16_C( 13567),  INT16_C(  8738),  INT16_C( 32232),  INT16_C(  1530) } },
    },
    { {  INT16_C(  4265),  INT16_C( 27317),  INT16_C( 18970), -INT16_C(  3613),  INT16_C(  3017),  INT16_C( 13539),  INT16_C( 30439),  INT16_C( 11295),
        -INT16_C( 24390), -INT16_C( 22856),  INT16_C(  9142), -INT16_C( 18600),  INT16_C( 31470), -INT16_C( 10278), -INT16_C( 11017), -INT16_C( 24100) },
        { {  INT16_C(  4265),  INT16_C( 27317),  INT16_C( 18970), -INT16_C(  3613) },
          {  INT16_C(  3017),  INT16_C( 13539),  INT16_C( 30439),  INT16_C( 11295) },
          { -INT16_C( 24390), -INT16_C( 22856),  INT16_C(  9142), -INT16_C( 18600) },
          {  INT16_C( 31470), -INT16_C( 10278), -INT16_C( 11017), -INT16_C( 24100) } },
    },
    { { -INT16_C( 28188), -INT16_C(   501), -INT16_C(  4388), -INT16_C( 23057), -INT16_C( 11271), -INT16_C(  7975), -INT16_C(  1719),  INT16_C(   781),
        -INT16_C( 14951),  INT16_C( 20649),  INT16_C(   489), -INT16_C( 10489), -INT16_C(  7812),  INT16_C( 29614), -INT16_C( 29770), -INT16_C( 26092) },
        { { -INT16_C( 28188), -INT16_C(   501), -INT16_C(  4388), -INT16_C( 23057) },
          { -INT16_C( 11271), -INT16_C(  7975), -INT16_C(  1719),  INT16_C(   781) },
          { -INT16_C( 14951),  INT16_C( 20649),  INT16_C(   489), -INT16_C( 10489) },
          { -INT16_C(  7812),  INT16_C( 29614), -INT16_C( 29770), -INT16_C( 26092) } },
    },
    { {  INT16_C(  8220), -INT16_C(  1895), -INT16_C( 30706),  INT16_C(  2205),  INT16_C( 30555), -INT16_C( 23320), -INT16_C(  2704),  INT16_C(  2471),
         INT16_C( 20923), -INT16_C( 23463),  INT16_C( 24914), -INT16_C( 12677),  INT16_C( 10818), -INT16_C(  1982),  INT16_C( 22197), -INT16_C( 11885) },
        { {  INT16_C(  8220), -INT16_C(  1895), -INT16_C( 30706),  INT16_C(  2205) },
          {  INT16_C( 30555), -INT16_C( 23320), -INT16_C(  2704),  INT16_C(  2471) },
          {  INT16_C( 20923), -INT16_C( 23463),  INT16_C( 24914), -INT16_C( 12677) },
          {  INT16_C( 10818), -INT16_C(  1982),  INT16_C( 22197), -INT16_C( 11885) } },
    },
    { {  INT16_C( 11382), -INT16_C( 31286),  INT16_C( 26548),  INT16_C(  4237),  INT16_C( 30174),  INT16_C( 20148),  INT16_C( 23659),  INT16_C(  9816),
        -INT16_C( 20051), -INT16_C(    54),  INT16_C( 17682),  INT16_C( 21966),  INT16_C(  4207),  INT16_C(  9293), -INT16_C(  8090), -INT16_C(  8714) },
        { {  INT16_C( 11382), -INT16_C( 31286),  INT16_C( 26548),  INT16_C(  4237) },
          {  INT16_C( 30174),  INT16_C( 20148),  INT16_C( 23659),  INT16_C(  9816) },
          { -INT16_C( 20051), -INT16_C(    54),  INT16_C( 17682),  INT16_C( 21966) },
          {  INT16_C(  4207),  INT16_C(  9293), -INT16_C(  8090), -INT16_C(  8714) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4x4_t r = simde_vld1_s16_x4(test_vec[i].buf);
    simde_int16x4x4_t expected = {{
        simde_vld1_s16(test_vec[i].expected[0]),
        simde_vld1_s16(test_vec[i].expected[1]),
        simde_vld1_s16(test_vec[i].expected[2]),
        simde_vld1_s16(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_i16x4x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int16_t buf[16];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vi16(2, 16, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int16x4x4_t val = simde_vld1_s16_x4(buf);
    simde_test_arm_neon_write_i16x4x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t buf[8];
    int32_t expected[4][2];
  } test_vec[] = {
    { { -INT32_C(   552944985),  INT32_C(  1471088520), -INT32_C(  1300159989),  INT32_C(   297639629),  INT32_C(   890410926),  INT32_C(   397817857), -INT32_C(  1742767204),  INT32_C(  1022786453) },
        { { -INT32_C(   552944985),  INT32_C(  1471088520) },
          { -INT32_C(  1300159989),  INT32_C(   297639629) },
          {  INT32_C(   890410926),  INT32_C(   397817857) },
          { -INT32_C(  1742767204),  INT32_C(  1022786453) } },
    },
    { { -INT32_C(  1105526475),  INT32_C(   320195080), -INT32_C(  1178232852), -INT32_C(   473201867),  INT32_C(   454614298), -INT32_C(  1305293291), -INT32_C(   548777654),  INT32_C(    18563532) },
        { { -INT32_C(  1105526475),  INT32_C(   320195080) },
          { -INT32_C(  1178232852), -INT32_C(   473201867) },
          {  INT32_C(   454614298), -INT32_C(  1305293291) },
          { -INT32_C(   548777654),  INT32_C(    18563532) } },
    },
    { {  INT32_C(  1254045250), -INT32_C(   312552192), -INT32_C(  1582947476), -INT32_C(  1065061978),  INT32_C(  1692114254), -INT32_C(  1256845973),  INT32_C(   714367070), -INT32_C(   483610719) },
        { {  INT32_C(  1254045250), -INT32_C(   312552192) },
          { -INT32_C(  1582947476), -INT32_C(  1065061978) },
          {  INT32_C(  1692114254), -INT32_C(  1256845973) },
          {  INT32_C(   714367070), -INT32_C(   483610719) } },
    },
    { { -INT32_C(   433132571),  INT32_C(   752061632),  INT32_C(  1456306607),  INT32_C(   957764331),  INT32_C(  1520300783),  INT32_C(  1578152959), -INT32_C(  1249336300),  INT32_C(   966374484) },
        { { -INT32_C(   433132571),  INT32_C(   752061632) },
          {  INT32_C(  1456306607),  INT32_C(   957764331) },
          {  INT32_C(  1520300783),  INT32_C(  1578152959) },
          { -INT32_C(  1249336300),  INT32_C(   966374484) } },
    },
    { {  INT32_C(  1612695456),  INT32_C(    42857043),  INT32_C(  1465408108), -INT32_C(  1685033044),  INT32_C(  1626746465), -INT32_C(   172095775), -INT32_C(    22329430), -INT32_C(  1690811141) },
        { {  INT32_C(  1612695456),  INT32_C(    42857043) },
          {  INT32_C(  1465408108), -INT32_C(  1685033044) },
          {  INT32_C(  1626746465), -INT32_C(   172095775) },
          { -INT32_C(    22329430), -INT32_C(  1690811141) } },
    },
    { {  INT32_C(  1593595659), -INT32_C(  1235187382), -INT32_C(  1878148637), -INT32_C(  1993630424), -INT32_C(  1377230389), -INT32_C(   761092057), -INT32_C(   355447313), -INT32_C(  1668937583) },
        { {  INT32_C(  1593595659), -INT32_C(  1235187382) },
          { -INT32_C(  1878148637), -INT32_C(  1993630424) },
          { -INT32_C(  1377230389), -INT32_C(   761092057) },
          { -INT32_C(   355447313), -INT32_C(  1668937583) } },
    },
    { { -INT32_C(  1426423200), -INT32_C(   295675125),  INT32_C(  1014918420), -INT32_C(   691688950), -INT32_C(   209473845),  INT32_C(  1170548054),  INT32_C(    70292851), -INT32_C(    22956386) },
        { { -INT32_C(  1426423200), -INT32_C(   295675125) },
          {  INT32_C(  1014918420), -INT32_C(   691688950) },
          { -INT32_C(   209473845),  INT32_C(  1170548054) },
          {  INT32_C(    70292851), -INT32_C(    22956386) } },
    },
    { {  INT32_C(  1135123256),  INT32_C(   170985718),  INT32_C(  2135339125),  INT32_C(   626330458),  INT32_C(   270063802),  INT32_C(  1901518334),  INT32_C(   292914803),  INT32_C(  1947145788) },
        { {  INT32_C(  1135123256),  INT32_C(   170985718) },
          {  INT32_C(  2135339125),  INT32_C(   626330458) },
          {  INT32_C(   270063802),  INT32_C(  1901518334) },
          {  INT32_C(   292914803),  INT32_C(  1947145788) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2x4_t r = simde_vld1_s32_x4(test_vec[i].buf);
    simde_int32x2x4_t expected = {{
        simde_vld1_s32(test_vec[i].expected[0]),
        simde_vld1_s32(test_vec[i].expected[1]),
        simde_vld1_s32(test_vec[i].expected[2]),
        simde_vld1_s32(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_i32x2x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int32_t buf[8];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vi32(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int32x2x4_t val = simde_vld1_s32_x4(buf);
    simde_test_arm_neon_write_i32x2x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_s64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t buf[4];
    int64_t expected[4][1];
  } test_vec[] = {
    { {  INT64_C( 3797634820670470066), -INT64_C( 4676978291872892520), -INT64_C( 9128755698865327903), -INT64_C( 8188773527293081941) },
        { {  INT64_C( 3797634820670470066) },
          { -INT64_C( 4676978291872892520) },
          { -INT64_C( 9128755698865327903) },
          { -INT64_C( 8188773527293081941) } },
    },
    { { -INT64_C( 7832908762733669800), -INT64_C( 1610144584958542109),  INT64_C( 5214352105074620366), -INT64_C( 1708399654901649441) },
        { { -INT64_C( 7832908762733669800) },
          { -INT64_C( 1610144584958542109) },
          {  INT64_C( 5214352105074620366) },
          { -INT64_C( 1708399654901649441) } },
    },
    { {  INT64_C( 5632959059922485661),  INT64_C( 2178016331334922825), -INT64_C(  415923138514451883), -INT64_C( 7871729246594045624) },
        { {  INT64_C( 5632959059922485661) },
          {  INT64_C( 2178016331334922825) },
          { -INT64_C(  415923138514451883) },
          { -INT64_C( 7871729246594045624) } },
    },
    { {  INT64_C( 6069258057025241216), -INT64_C( 6523501102851919608),  INT64_C( 1366228731711419104),  INT64_C( 3080933467046521402) },
        { {  INT64_C( 6069258057025241216) },
          { -INT64_C( 6523501102851919608) },
          {  INT64_C( 1366228731711419104) },
          {  INT64_C( 3080933467046521402) } },
    },
    { {  INT64_C( 5389489625474984812),  INT64_C( 3365625219118231745),  INT64_C( 6370656259240709260),  INT64_C( 7826490894198461640) },
        { {  INT64_C( 5389489625474984812) },
          {  INT64_C( 3365625219118231745) },
          {  INT64_C( 6370656259240709260) },
          {  INT64_C( 7826490894198461640) } },
    },
    { { -INT64_C( 4269220017349545165),  INT64_C(  692299239049683743), -INT64_C( 6103282517905783594),  INT64_C( 5659259032366338844) },
        { { -INT64_C( 4269220017349545165) },
          {  INT64_C(  692299239049683743) },
          { -INT64_C( 6103282517905783594) },
          {  INT64_C( 5659259032366338844) } },
    },
    { {  INT64_C( 4338237598750502253),  INT64_C( 7596804645795203559), -INT64_C( 5649860746132206583), -INT64_C( 2529238003922062212) },
        { {  INT64_C( 4338237598750502253) },
          {  INT64_C( 7596804645795203559) },
          { -INT64_C( 5649860746132206583) },
          { -INT64_C( 2529238003922062212) } },
    },
    { {  INT64_C( 1521232812476050116),  INT64_C( 1479403938028045962),  INT64_C(  790829846912623794), -INT64_C( 2119075434076125364) },
        { {  INT64_C( 1521232812476050116) },
          {  INT64_C( 1479403938028045962) },
          {  INT64_C(  790829846912623794) },
          { -INT64_C( 2119075434076125364) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1x4_t r = simde_vld1_s64_x4(test_vec[i].buf);
    simde_int64x1x4_t expected = {{
        simde_vld1_s64(test_vec[i].expected[0]),
        simde_vld1_s64(test_vec[i].expected[1]),
        simde_vld1_s64(test_vec[i].expected[2]),
        simde_vld1_s64(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_i64x1x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int64_t buf[4];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vi64(2, 4, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_int64x1x4_t val = simde_vld1_s64_x4(buf);
    simde_test_arm_neon_write_i64x1x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u8_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t buf[32];
    uint8_t expected[4][8];
  } test_vec[] = {
    { { UINT8_C(115), UINT8_C(157), UINT8_C(202), UINT8_C(158), UINT8_C(229), UINT8_C( 49), UINT8_C( 33), UINT8_C(150),
        UINT8_C(241), UINT8_C(209), UINT8_C(252), UINT8_C(130), UINT8_C( 25), UINT8_C(177), UINT8_C( 29), UINT8_C(  7),
        UINT8_C( 29), UINT8_C( 90), UINT8_C(165),    UINT8_MAX, UINT8_C( 67), UINT8_C(227), UINT8_C(235), UINT8_C( 48),
        UINT8_C( 96), UINT8_C( 16), UINT8_C( 58), UINT8_C( 52), UINT8_C(159), UINT8_C(228), UINT8_C(158), UINT8_C( 18) },
        { { UINT8_C(115), UINT8_C(157), UINT8_C(202), UINT8_C(158), UINT8_C(229), UINT8_C( 49), UINT8_C( 33), UINT8_C(150) },
          { UINT8_C(241), UINT8_C(209), UINT8_C(252), UINT8_C(130), UINT8_C( 25), UINT8_C(177), UINT8_C( 29), UINT8_C(  7) },
          { UINT8_C( 29), UINT8_C( 90), UINT8_C(165),    UINT8_MAX, UINT8_C( 67), UINT8_C(227), UINT8_C(235), UINT8_C( 48) },
          { UINT8_C( 96), UINT8_C( 16), UINT8_C( 58), UINT8_C( 52), UINT8_C(159), UINT8_C(228), UINT8_C(158), UINT8_C( 18) } },
    },
    { { UINT8_C(129), UINT8_C(104), UINT8_C(177), UINT8_C(103), UINT8_C(153), UINT8_C(210), UINT8_C(253), UINT8_C(138),
        UINT8_C(163), UINT8_C(250), UINT8_C( 13), UINT8_C(189), UINT8_C(171), UINT8_C( 42), UINT8_C(196), UINT8_C(201),
        UINT8_C(132), UINT8_C(105), UINT8_C(200), UINT8_C(199), UINT8_C( 76), UINT8_C(179), UINT8_C(247), UINT8_C(172),
        UINT8_C(195), UINT8_C( 49), UINT8_C(224), UINT8_C( 98), UINT8_C( 21), UINT8_C(126), UINT8_C(117), UINT8_C(150) },
        { { UINT8_C(129), UINT8_C(104), UINT8_C(177), UINT8_C(103), UINT8_C(153), UINT8_C(210), UINT8_C(253), UINT8_C(138) },
          { UINT8_C(163), UINT8_C(250), UINT8_C( 13), UINT8_C(189), UINT8_C(171), UINT8_C( 42), UINT8_C(196), UINT8_C(201) },
          { UINT8_C(132), UINT8_C(105), UINT8_C(200), UINT8_C(199), UINT8_C( 76), UINT8_C(179), UINT8_C(247), UINT8_C(172) },
          { UINT8_C(195), UINT8_C( 49), UINT8_C(224), UINT8_C( 98), UINT8_C( 21), UINT8_C(126), UINT8_C(117), UINT8_C(150) } },
    },
    { { UINT8_C(231), UINT8_C( 38), UINT8_C(253), UINT8_C(128), UINT8_C(248), UINT8_C(251), UINT8_C( 11), UINT8_C(156),
        UINT8_C(245), UINT8_C( 24), UINT8_C( 89), UINT8_C(160), UINT8_C( 66), UINT8_C( 29), UINT8_C(105), UINT8_C(198),
        UINT8_C(134), UINT8_C( 49), UINT8_C(141), UINT8_C(211), UINT8_C(229), UINT8_C(132), UINT8_C(127), UINT8_C(168),
        UINT8_C(181), UINT8_C( 96), UINT8_C( 11), UINT8_C(202), UINT8_C(222), UINT8_C(128), UINT8_C( 96), UINT8_C(197) },
        { { UINT8_C(231), UINT8_C( 38), UINT8_C(253), UINT8_C(128), UINT8_C(248), UINT8_C(251), UINT8_C( 11), UINT8_C(156) },
          { UINT8_C(245), UINT8_C( 24), UINT8_C( 89), UINT8_C(160), UINT8_C( 66), UINT8_C( 29), UINT8_C(105), UINT8_C(198) },
          { UINT8_C(134), UINT8_C( 49), UINT8_C(141), UINT8_C(211), UINT8_C(229), UINT8_C(132), UINT8_C(127), UINT8_C(168) },
          { UINT8_C(181), UINT8_C( 96), UINT8_C( 11), UINT8_C(202), UINT8_C(222), UINT8_C(128), UINT8_C( 96), UINT8_C(197) } },
    },
    { { UINT8_C(166), UINT8_C( 94), UINT8_C( 70), UINT8_C(158), UINT8_C( 89), UINT8_C( 81), UINT8_C( 58), UINT8_C( 78),
        UINT8_C(105), UINT8_C(147), UINT8_C(238), UINT8_C(171), UINT8_C(176), UINT8_C( 88), UINT8_C(113), UINT8_C( 55),
        UINT8_C(137), UINT8_C(254), UINT8_C( 10), UINT8_C(110), UINT8_C(130), UINT8_C(137), UINT8_C( 23), UINT8_C( 55),
        UINT8_C(233), UINT8_C( 34), UINT8_C(  1), UINT8_C(200), UINT8_C(162), UINT8_C( 97), UINT8_C(141), UINT8_C( 72) },
        { { UINT8_C(166), UINT8_C( 94), UINT8_C( 70), UINT8_C(158), UINT8_C( 89), UINT8_C( 81), UINT8_C( 58), UINT8_C( 78) },
          { UINT8_C(105), UINT8_C(147), UINT8_C(238), UINT8_C(171), UINT8_C(176), UINT8_C( 88), UINT8_C(113), UINT8_C( 55) },
          { UINT8_C(137), UINT8_C(254), UINT8_C( 10), UINT8_C(110), UINT8_C(130), UINT8_C(137), UINT8_C( 23), UINT8_C( 55) },
          { UINT8_C(233), UINT8_C( 34), UINT8_C(  1), UINT8_C(200), UINT8_C(162), UINT8_C( 97), UINT8_C(141), UINT8_C( 72) } },
    },
    { { UINT8_C(191), UINT8_C(211), UINT8_C(230), UINT8_C( 24), UINT8_C( 36), UINT8_C( 33), UINT8_C(102), UINT8_C(141),
        UINT8_C(180), UINT8_C( 85), UINT8_C( 56), UINT8_C(101), UINT8_C(173), UINT8_C(169), UINT8_C(156), UINT8_C( 54),
        UINT8_C(167), UINT8_C(166), UINT8_C(165), UINT8_C( 41), UINT8_C( 47), UINT8_C(188), UINT8_C( 96), UINT8_C( 25),
        UINT8_C(222), UINT8_C( 97), UINT8_C(225), UINT8_C(128), UINT8_C(195), UINT8_C(110), UINT8_C(200), UINT8_C(130) },
        { { UINT8_C(191), UINT8_C(211), UINT8_C(230), UINT8_C( 24), UINT8_C( 36), UINT8_C( 33), UINT8_C(102), UINT8_C(141) },
          { UINT8_C(180), UINT8_C( 85), UINT8_C( 56), UINT8_C(101), UINT8_C(173), UINT8_C(169), UINT8_C(156), UINT8_C( 54) },
          { UINT8_C(167), UINT8_C(166), UINT8_C(165), UINT8_C( 41), UINT8_C( 47), UINT8_C(188), UINT8_C( 96), UINT8_C( 25) },
          { UINT8_C(222), UINT8_C( 97), UINT8_C(225), UINT8_C(128), UINT8_C(195), UINT8_C(110), UINT8_C(200), UINT8_C(130) } },
    },
    { { UINT8_C( 66), UINT8_C(174), UINT8_C(155), UINT8_C(102), UINT8_C(207), UINT8_C(  1), UINT8_C(244), UINT8_C(132),
        UINT8_C( 86), UINT8_C( 44), UINT8_C(233), UINT8_C(  3), UINT8_C(214), UINT8_C(133), UINT8_C( 58), UINT8_C(125),
        UINT8_C( 43), UINT8_C(223), UINT8_C(167), UINT8_C( 90), UINT8_C(155), UINT8_C(  7), UINT8_C(115), UINT8_C(121),
        UINT8_C(105), UINT8_C( 84), UINT8_C(249), UINT8_C( 44), UINT8_C(195), UINT8_C(193), UINT8_C(174), UINT8_C(  5) },
        { { UINT8_C( 66), UINT8_C(174), UINT8_C(155), UINT8_C(102), UINT8_C(207), UINT8_C(  1), UINT8_C(244), UINT8_C(132) },
          { UINT8_C( 86), UINT8_C( 44), UINT8_C(233), UINT8_C(  3), UINT8_C(214), UINT8_C(133), UINT8_C( 58), UINT8_C(125) },
          { UINT8_C( 43), UINT8_C(223), UINT8_C(167), UINT8_C( 90), UINT8_C(155), UINT8_C(  7), UINT8_C(115), UINT8_C(121) },
          { UINT8_C(105), UINT8_C( 84), UINT8_C(249), UINT8_C( 44), UINT8_C(195), UINT8_C(193), UINT8_C(174), UINT8_C(  5) } },
    },
    { { UINT8_C(111), UINT8_C( 73), UINT8_C(107), UINT8_C( 63), UINT8_C( 75), UINT8_C( 95), UINT8_C(195), UINT8_C(161),
        UINT8_C(140), UINT8_C(172), UINT8_C(165), UINT8_C( 98), UINT8_C( 49), UINT8_C(223), UINT8_C(223), UINT8_C( 92),
        UINT8_C(190), UINT8_C(134), UINT8_C(182), UINT8_C( 89), UINT8_C(142), UINT8_C( 42), UINT8_C(210), UINT8_C(247),
        UINT8_C(126), UINT8_C(203), UINT8_C( 35), UINT8_C( 65), UINT8_C(140), UINT8_C(209), UINT8_C( 70), UINT8_C(251) },
        { { UINT8_C(111), UINT8_C( 73), UINT8_C(107), UINT8_C( 63), UINT8_C( 75), UINT8_C( 95), UINT8_C(195), UINT8_C(161) },
          { UINT8_C(140), UINT8_C(172), UINT8_C(165), UINT8_C( 98), UINT8_C( 49), UINT8_C(223), UINT8_C(223), UINT8_C( 92) },
          { UINT8_C(190), UINT8_C(134), UINT8_C(182), UINT8_C( 89), UINT8_C(142), UINT8_C( 42), UINT8_C(210), UINT8_C(247) },
          { UINT8_C(126), UINT8_C(203), UINT8_C( 35), UINT8_C( 65), UINT8_C(140), UINT8_C(209), UINT8_C( 70), UINT8_C(251) } },
    },
    { { UINT8_C( 27), UINT8_C(178), UINT8_C( 58), UINT8_C(102), UINT8_C( 17), UINT8_C(253), UINT8_C(  7), UINT8_C(157),
        UINT8_C(169), UINT8_C(172),    UINT8_MAX, UINT8_C(218), UINT8_C(139), UINT8_C(223), UINT8_C( 54), UINT8_C( 73),
        UINT8_C(101), UINT8_C(237), UINT8_C(162), UINT8_C(243), UINT8_C( 23), UINT8_C(116), UINT8_C(234), UINT8_C(149),
        UINT8_C( 63), UINT8_C( 13), UINT8_C(215), UINT8_C(203), UINT8_C(223), UINT8_C( 29), UINT8_C(199), UINT8_C(250) },
        { { UINT8_C( 27), UINT8_C(178), UINT8_C( 58), UINT8_C(102), UINT8_C( 17), UINT8_C(253), UINT8_C(  7), UINT8_C(157) },
          { UINT8_C(169), UINT8_C(172),    UINT8_MAX, UINT8_C(218), UINT8_C(139), UINT8_C(223), UINT8_C( 54), UINT8_C( 73) },
          { UINT8_C(101), UINT8_C(237), UINT8_C(162), UINT8_C(243), UINT8_C( 23), UINT8_C(116), UINT8_C(234), UINT8_C(149) },
          { UINT8_C( 63), UINT8_C( 13), UINT8_C(215), UINT8_C(203), UINT8_C(223), UINT8_C( 29), UINT8_C(199), UINT8_C(250) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8x4_t r = simde_vld1_u8_x4(test_vec[i].buf);
    simde_uint8x8x4_t expected = {{
        simde_vld1_u8(test_vec[i].expected[0]),
        simde_vld1_u8(test_vec[i].expected[1]),
        simde_vld1_u8(test_vec[i].expected[2]),
        simde_vld1_u8(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_u8x8x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t buf[32];
    simde_test_codegen_random_memory(32, buf);
    simde_test_codegen_write_vu8(2, 32, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint8x8x4_t val = simde_vld1_u8_x4(buf);
    simde_test_arm_neon_write_u8x8x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u16_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t buf[16];
    uint16_t expected[4][4];
  } test_vec[] = {
    { { UINT16_C(11057), UINT16_C(26146), UINT16_C(26897), UINT16_C(39509), UINT16_C(63640), UINT16_C(43715), UINT16_C(30007), UINT16_C(28763),
        UINT16_C(19543), UINT16_C(17162), UINT16_C(56535), UINT16_C(17014), UINT16_C(52473), UINT16_C(24636), UINT16_C(37539), UINT16_C(54708) },
        { { UINT16_C(11057), UINT16_C(26146), UINT16_C(26897), UINT16_C(39509) },
          { UINT16_C(63640), UINT16_C(43715), UINT16_C(30007), UINT16_C(28763) },
          { UINT16_C(19543), UINT16_C(17162), UINT16_C(56535), UINT16_C(17014) },
          { UINT16_C(52473), UINT16_C(24636), UINT16_C(37539), UINT16_C(54708) } },
    },
    { { UINT16_C(55229), UINT16_C(53051), UINT16_C(36928), UINT16_C(55401), UINT16_C(11401), UINT16_C(49282), UINT16_C(56994), UINT16_C(63793),
        UINT16_C(15146), UINT16_C(  317), UINT16_C(45847), UINT16_C( 4419), UINT16_C(32639), UINT16_C( 9073), UINT16_C( 9490), UINT16_C(53240) },
        { { UINT16_C(55229), UINT16_C(53051), UINT16_C(36928), UINT16_C(55401) },
          { UINT16_C(11401), UINT16_C(49282), UINT16_C(56994), UINT16_C(63793) },
          { UINT16_C(15146), UINT16_C(  317), UINT16_C(45847), UINT16_C( 4419) },
          { UINT16_C(32639), UINT16_C( 9073), UINT16_C( 9490), UINT16_C(53240) } },
    },
    { { UINT16_C(13308), UINT16_C(15518), UINT16_C( 2244), UINT16_C(19732), UINT16_C(38708), UINT16_C(54797), UINT16_C(15989), UINT16_C(40912),
        UINT16_C( 3450), UINT16_C(37280), UINT16_C(58304), UINT16_C(16290), UINT16_C( 4963), UINT16_C(30050), UINT16_C(23097), UINT16_C(13636) },
        { { UINT16_C(13308), UINT16_C(15518), UINT16_C( 2244), UINT16_C(19732) },
          { UINT16_C(38708), UINT16_C(54797), UINT16_C(15989), UINT16_C(40912) },
          { UINT16_C( 3450), UINT16_C(37280), UINT16_C(58304), UINT16_C(16290) },
          { UINT16_C( 4963), UINT16_C(30050), UINT16_C(23097), UINT16_C(13636) } },
    },
    { { UINT16_C(58254), UINT16_C(21106), UINT16_C(34539), UINT16_C( 8095), UINT16_C(44061), UINT16_C(37622), UINT16_C(50923), UINT16_C(25905),
        UINT16_C(53715), UINT16_C(37878), UINT16_C(39349), UINT16_C( 6354), UINT16_C(13740), UINT16_C(58765), UINT16_C(53647), UINT16_C( 7451) },
        { { UINT16_C(58254), UINT16_C(21106), UINT16_C(34539), UINT16_C( 8095) },
          { UINT16_C(44061), UINT16_C(37622), UINT16_C(50923), UINT16_C(25905) },
          { UINT16_C(53715), UINT16_C(37878), UINT16_C(39349), UINT16_C( 6354) },
          { UINT16_C(13740), UINT16_C(58765), UINT16_C(53647), UINT16_C( 7451) } },
    },
    { { UINT16_C(36276), UINT16_C(40815), UINT16_C( 3603), UINT16_C(12735), UINT16_C(46523), UINT16_C(42691), UINT16_C(62843), UINT16_C(19979),
        UINT16_C(  454), UINT16_C(31713), UINT16_C(45978), UINT16_C(18323), UINT16_C( 8424), UINT16_C(30764), UINT16_C(18418), UINT16_C(42645) },
        { { UINT16_C(36276), UINT16_C(40815), UINT16_C( 3603), UINT16_C(12735) },
          { UINT16_C(46523), UINT16_C(42691), UINT16_C(62843), UINT16_C(19979) },
          { UINT16_C(  454), UINT16_C(31713), UINT16_C(45978), UINT16_C(18323) },
          { UINT16_C( 8424), UINT16_C(30764), UINT16_C(18418), UINT16_C(42645) } },
    },
    { { UINT16_C( 1492), UINT16_C(59462), UINT16_C( 1299), UINT16_C(52761), UINT16_C(56506), UINT16_C(13684), UINT16_C(32721), UINT16_C(39043),
        UINT16_C(25729), UINT16_C( 6931), UINT16_C(42775), UINT16_C(   98), UINT16_C(36807), UINT16_C(47480), UINT16_C( 3542), UINT16_C(43872) },
        { { UINT16_C( 1492), UINT16_C(59462), UINT16_C( 1299), UINT16_C(52761) },
          { UINT16_C(56506), UINT16_C(13684), UINT16_C(32721), UINT16_C(39043) },
          { UINT16_C(25729), UINT16_C( 6931), UINT16_C(42775), UINT16_C(   98) },
          { UINT16_C(36807), UINT16_C(47480), UINT16_C( 3542), UINT16_C(43872) } },
    },
    { { UINT16_C(42514), UINT16_C( 9875), UINT16_C(44203), UINT16_C(26100), UINT16_C(27016), UINT16_C(23194), UINT16_C( 7656), UINT16_C(27122),
        UINT16_C( 1409), UINT16_C(39045), UINT16_C(59308), UINT16_C(29848), UINT16_C( 4214), UINT16_C(19757), UINT16_C(36126), UINT16_C(12536) },
        { { UINT16_C(42514), UINT16_C( 9875), UINT16_C(44203), UINT16_C(26100) },
          { UINT16_C(27016), UINT16_C(23194), UINT16_C( 7656), UINT16_C(27122) },
          { UINT16_C( 1409), UINT16_C(39045), UINT16_C(59308), UINT16_C(29848) },
          { UINT16_C( 4214), UINT16_C(19757), UINT16_C(36126), UINT16_C(12536) } },
    },
    { { UINT16_C(35635), UINT16_C(56918), UINT16_C(19255), UINT16_C(48963), UINT16_C(56756), UINT16_C(39961), UINT16_C( 3066), UINT16_C(31494),
        UINT16_C(35601), UINT16_C(48404), UINT16_C(44146), UINT16_C(59697), UINT16_C(24509), UINT16_C(56118), UINT16_C(12012), UINT16_C( 8203) },
        { { UINT16_C(35635), UINT16_C(56918), UINT16_C(19255), UINT16_C(48963) },
          { UINT16_C(56756), UINT16_C(39961), UINT16_C( 3066), UINT16_C(31494) },
          { UINT16_C(35601), UINT16_C(48404), UINT16_C(44146), UINT16_C(59697) },
          { UINT16_C(24509), UINT16_C(56118), UINT16_C(12012), UINT16_C( 8203) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4x4_t r = simde_vld1_u16_x4(test_vec[i].buf);
    simde_uint16x4x4_t expected = {{
        simde_vld1_u16(test_vec[i].expected[0]),
        simde_vld1_u16(test_vec[i].expected[1]),
        simde_vld1_u16(test_vec[i].expected[2]),
        simde_vld1_u16(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_u16x4x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t buf[16];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vu16(2, 16, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint16x4x4_t val = simde_vld1_u16_x4(buf);
    simde_test_arm_neon_write_u16x4x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t buf[8];
    uint32_t expected[4][2];
  } test_vec[] = {
    { { UINT32_C(4043203257), UINT32_C(1638875821), UINT32_C( 452839711), UINT32_C(3851748308), UINT32_C(  27502990), UINT32_C( 334156886), UINT32_C( 552476723), UINT32_C( 121698638) },
        { { UINT32_C(4043203257), UINT32_C(1638875821) },
          { UINT32_C( 452839711), UINT32_C(3851748308) },
          { UINT32_C(  27502990), UINT32_C( 334156886) },
          { UINT32_C( 552476723), UINT32_C( 121698638) } },
    },
    { { UINT32_C( 150421083), UINT32_C(2691278464), UINT32_C(1153066863), UINT32_C(4180234090), UINT32_C(1341836537), UINT32_C(3563250849), UINT32_C(1391742980), UINT32_C(2774086729) },
        { { UINT32_C( 150421083), UINT32_C(2691278464) },
          { UINT32_C(1153066863), UINT32_C(4180234090) },
          { UINT32_C(1341836537), UINT32_C(3563250849) },
          { UINT32_C(1391742980), UINT32_C(2774086729) } },
    },
    { { UINT32_C(4088221811), UINT32_C(1720915958), UINT32_C(3903475070), UINT32_C(2531382173), UINT32_C(1105583008), UINT32_C(3272951743), UINT32_C(3759475351), UINT32_C(2978311742) },
        { { UINT32_C(4088221811), UINT32_C(1720915958) },
          { UINT32_C(3903475070), UINT32_C(2531382173) },
          { UINT32_C(1105583008), UINT32_C(3272951743) },
          { UINT32_C(3759475351), UINT32_C(2978311742) } },
    },
    { { UINT32_C(3047502782), UINT32_C(3357227082), UINT32_C( 598787462), UINT32_C( 951685784), UINT32_C( 762945133), UINT32_C(2096140261), UINT32_C(3613132441), UINT32_C( 864674420) },
        { { UINT32_C(3047502782), UINT32_C(3357227082) },
          { UINT32_C( 598787462), UINT32_C( 951685784) },
          { UINT32_C( 762945133), UINT32_C(2096140261) },
          { UINT32_C(3613132441), UINT32_C( 864674420) } },
    },
    { { UINT32_C(1609051669), UINT32_C(3961979750), UINT32_C(1611651016), UINT32_C(3617179753), UINT32_C(1258558054), UINT32_C( 986182817), UINT32_C(1863460090), UINT32_C( 463641350) },
        { { UINT32_C(1609051669), UINT32_C(3961979750) },
          { UINT32_C(1611651016), UINT32_C(3617179753) },
          { UINT32_C(1258558054), UINT32_C( 986182817) },
          { UINT32_C(1863460090), UINT32_C( 463641350) } },
    },
    { { UINT32_C( 796560073), UINT32_C(1427939725), UINT32_C(3803523960), UINT32_C(1522093812), UINT32_C(  44481889), UINT32_C(2889706929), UINT32_C(2535149457), UINT32_C(3014835690) },
        { { UINT32_C( 796560073), UINT32_C(1427939725) },
          { UINT32_C(3803523960), UINT32_C(1522093812) },
          { UINT32_C(  44481889), UINT32_C(2889706929) },
          { UINT32_C(2535149457), UINT32_C(3014835690) } },
    },
    { { UINT32_C(3571592263), UINT32_C(1177157325), UINT32_C( 505994794), UINT32_C(2390286637), UINT32_C(1334845086), UINT32_C( 503041420), UINT32_C( 112530972), UINT32_C( 448358355) },
        { { UINT32_C(3571592263), UINT32_C(1177157325) },
          { UINT32_C( 505994794), UINT32_C(2390286637) },
          { UINT32_C(1334845086), UINT32_C( 503041420) },
          { UINT32_C( 112530972), UINT32_C( 448358355) } },
    },
    { { UINT32_C(1643027604), UINT32_C(3299284890), UINT32_C( 602066934), UINT32_C(1320246192), UINT32_C(  94257529), UINT32_C( 723753231), UINT32_C(2201147568), UINT32_C(3550407487) },
        { { UINT32_C(1643027604), UINT32_C(3299284890) },
          { UINT32_C( 602066934), UINT32_C(1320246192) },
          { UINT32_C(  94257529), UINT32_C( 723753231) },
          { UINT32_C(2201147568), UINT32_C(3550407487) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2x4_t r = simde_vld1_u32_x4(test_vec[i].buf);
    simde_uint32x2x4_t expected = {{
        simde_vld1_u32(test_vec[i].expected[0]),
        simde_vld1_u32(test_vec[i].expected[1]),
        simde_vld1_u32(test_vec[i].expected[2]),
        simde_vld1_u32(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_u32x2x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t buf[8];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vu32(2, 8, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint32x2x4_t val = simde_vld1_u32_x4(buf);
    simde_test_arm_neon_write_u32x2x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld1_u64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t buf[4];
    uint64_t expected[4][1];
  } test_vec[] = {
    { { UINT64_C(11161851323991035015), UINT64_C(11361295587426027948), UINT64_C(10586492551251052975), UINT64_C(10354254964168465566) },
        { { UINT64_C(11161851323991035015) },
          { UINT64_C(11361295587426027948) },
          { UINT64_C(10586492551251052975) },
          { UINT64_C(10354254964168465566) } },
    },
    { { UINT64_C( 7961968054553929280), UINT64_C( 6422826489033210720), UINT64_C( 2968999753558771135), UINT64_C( 4518438628330195485) },
        { { UINT64_C( 7961968054553929280) },
          { UINT64_C( 6422826489033210720) },
          { UINT64_C( 2968999753558771135) },
          { UINT64_C( 4518438628330195485) } },
    },
    { { UINT64_C( 6759518196046456221), UINT64_C(14906636656841955805), UINT64_C( 1620351352405293000), UINT64_C(15576525297564746734) },
        { { UINT64_C( 6759518196046456221) },
          { UINT64_C(14906636656841955805) },
          { UINT64_C( 1620351352405293000) },
          { UINT64_C(15576525297564746734) } },
    },
    { { UINT64_C(14748451979621059924), UINT64_C( 6592762510105022368), UINT64_C( 9238901067204193833), UINT64_C(13096633063648817838) },
        { { UINT64_C(14748451979621059924) },
          { UINT64_C( 6592762510105022368) },
          { UINT64_C( 9238901067204193833) },
          { UINT64_C(13096633063648817838) } },
    },
    { { UINT64_C(11502109884666018020), UINT64_C( 5490112400039276866), UINT64_C(13244142063545409210), UINT64_C(12911645100909541400) },
        { { UINT64_C(11502109884666018020) },
          { UINT64_C( 5490112400039276866) },
          { UINT64_C(13244142063545409210) },
          { UINT64_C(12911645100909541400) } },
    },
    { { UINT64_C( 3168042542726264153), UINT64_C(14737519685457167638), UINT64_C(12884769508922356750), UINT64_C( 2999497205207494430) },
        { { UINT64_C( 3168042542726264153) },
          { UINT64_C(14737519685457167638) },
          { UINT64_C(12884769508922356750) },
          { UINT64_C( 2999497205207494430) } },
    },
    { { UINT64_C( 7035599308422456975), UINT64_C(16256907048017175485), UINT64_C(13286403516927685910), UINT64_C( 8660780421289971256) },
        { { UINT64_C( 7035599308422456975) },
          { UINT64_C(16256907048017175485) },
          { UINT64_C(13286403516927685910) },
          { UINT64_C( 8660780421289971256) } },
    },
    { { UINT64_C(16724279027907474027), UINT64_C(17071549511957459766), UINT64_C(16527084378805560328), UINT64_C(12892995695718302093) },
        { { UINT64_C(16724279027907474027) },
          { UINT64_C(17071549511957459766) },
          { UINT64_C(16527084378805560328) },
          { UINT64_C(12892995695718302093) } },
    },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1x4_t r = simde_vld1_u64_x4(test_vec[i].buf);
    simde_uint64x1x4_t expected = {{
        simde_vld1_u64(test_vec[i].expected[0]),
        simde_vld1_u64(test_vec[i].expected[1]),
        simde_vld1_u64(test_vec[i].expected[2]),
        simde_vld1_u64(test_vec[i].expected[3]),
    }};
    simde_test_arm_neon_assert_equal_u64x1x4(r, expected);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t buf[4];
    simde_test_codegen_random_memory(32, (uint8_t*)buf);
    simde_test_codegen_write_vu64(2, 4, buf, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint64x1x4_t val = simde_vld1_u64_x4(buf);
    simde_test_arm_neon_write_u64x1x4(2, val, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_f32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_f64_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s8_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s16_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_s64_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u8_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u16_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vld1_u64_x4)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
