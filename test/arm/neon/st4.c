#define SIMDE_TEST_ARM_NEON_INSN st4

#include "test-neon.h"
#include "../../../simde/arm/neon/st4.h"
#include "../../../simde/arm/neon/ld4.h"
#include "../../../simde/arm/neon/get_lane.h"

/* Implementor notes (seanptmaher):
 *
 * the way that I'm opting to test this is that I'll have a r[4][x]
 * array of vectors, as well as a flat buffer of results. The flat
 * buffer contains the expected result of a st4, done on arm hardware,
 * which will be compared against a st4 done at test time.
 *
 * To test the ld4, the stored st4 will be ld4'd, and then
 * individually compared against the r[4][x] vector.
 */

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst4_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r0[2];
    simde_float32 r1[2];
    simde_float32 r2[2];
    simde_float32 r3[2];
    simde_float32 a[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    77.38), SIMDE_FLOAT32_C(   677.34) },
      { SIMDE_FLOAT32_C(  -113.63), SIMDE_FLOAT32_C(  -677.73) },
      { SIMDE_FLOAT32_C(  -489.72), SIMDE_FLOAT32_C(   841.42) },
      { SIMDE_FLOAT32_C(   -32.02), SIMDE_FLOAT32_C(   794.35) },
      {
      SIMDE_FLOAT32_C(    77.38),
      SIMDE_FLOAT32_C(  -113.63),
      SIMDE_FLOAT32_C(  -489.72),
      SIMDE_FLOAT32_C(   -32.02),
      SIMDE_FLOAT32_C(   677.34),
      SIMDE_FLOAT32_C(  -677.73),
      SIMDE_FLOAT32_C(   841.42),
      SIMDE_FLOAT32_C(   794.35),
      }
    },
    { { SIMDE_FLOAT32_C(  -290.22), SIMDE_FLOAT32_C(  -690.11) },
      { SIMDE_FLOAT32_C(  -998.58), SIMDE_FLOAT32_C(  -130.70) },
      { SIMDE_FLOAT32_C(  -215.14), SIMDE_FLOAT32_C(   735.01) },
      { SIMDE_FLOAT32_C(   247.54), SIMDE_FLOAT32_C(    37.32) },
      {
      SIMDE_FLOAT32_C(  -290.22),
      SIMDE_FLOAT32_C(  -998.58),
      SIMDE_FLOAT32_C(  -215.14),
      SIMDE_FLOAT32_C(   247.54),
      SIMDE_FLOAT32_C(  -690.11),
      SIMDE_FLOAT32_C(  -130.70),
      SIMDE_FLOAT32_C(   735.01),
      SIMDE_FLOAT32_C(    37.32),
      }
    },
    { { SIMDE_FLOAT32_C(   469.24), SIMDE_FLOAT32_C(   265.50) },
      { SIMDE_FLOAT32_C(   319.83), SIMDE_FLOAT32_C(  -183.68) },
      { SIMDE_FLOAT32_C(  -305.25), SIMDE_FLOAT32_C(  -951.48) },
      { SIMDE_FLOAT32_C(   557.71), SIMDE_FLOAT32_C(  -797.73) },
      {
      SIMDE_FLOAT32_C(   469.24),
      SIMDE_FLOAT32_C(   319.83),
      SIMDE_FLOAT32_C(  -305.25),
      SIMDE_FLOAT32_C(   557.71),
      SIMDE_FLOAT32_C(   265.50),
      SIMDE_FLOAT32_C(  -183.68),
      SIMDE_FLOAT32_C(  -951.48),
      SIMDE_FLOAT32_C(  -797.73),
      }
    },
    { { SIMDE_FLOAT32_C(   453.48), SIMDE_FLOAT32_C(  -751.30) },
      { SIMDE_FLOAT32_C(  -461.55), SIMDE_FLOAT32_C(  -927.67) },
      { SIMDE_FLOAT32_C(  -520.41), SIMDE_FLOAT32_C(   745.85) },
      { SIMDE_FLOAT32_C(  -100.92), SIMDE_FLOAT32_C(   556.97) },
      {
      SIMDE_FLOAT32_C(   453.48),
      SIMDE_FLOAT32_C(  -461.55),
      SIMDE_FLOAT32_C(  -520.41),
      SIMDE_FLOAT32_C(  -100.92),
      SIMDE_FLOAT32_C(  -751.30),
      SIMDE_FLOAT32_C(  -927.67),
      SIMDE_FLOAT32_C(   745.85),
      SIMDE_FLOAT32_C(   556.97),
      }
    },
    { { SIMDE_FLOAT32_C(   423.19), SIMDE_FLOAT32_C(   785.44) },
      { SIMDE_FLOAT32_C(   879.23), SIMDE_FLOAT32_C(   933.48) },
      { SIMDE_FLOAT32_C(   626.86), SIMDE_FLOAT32_C(  -152.79) },
      { SIMDE_FLOAT32_C(   727.83), SIMDE_FLOAT32_C(  -663.36) },
      {
      SIMDE_FLOAT32_C(   423.19),
      SIMDE_FLOAT32_C(   879.23),
      SIMDE_FLOAT32_C(   626.86),
      SIMDE_FLOAT32_C(   727.83),
      SIMDE_FLOAT32_C(   785.44),
      SIMDE_FLOAT32_C(   933.48),
      SIMDE_FLOAT32_C(  -152.79),
      SIMDE_FLOAT32_C(  -663.36),
      }
    },
    { { SIMDE_FLOAT32_C(   157.09), SIMDE_FLOAT32_C(   729.25) },
      { SIMDE_FLOAT32_C(   205.94), SIMDE_FLOAT32_C(   941.95) },
      { SIMDE_FLOAT32_C(   464.26), SIMDE_FLOAT32_C(  -546.52) },
      { SIMDE_FLOAT32_C(   -20.73), SIMDE_FLOAT32_C(   -66.51) },
      {
      SIMDE_FLOAT32_C(   157.09),
      SIMDE_FLOAT32_C(   205.94),
      SIMDE_FLOAT32_C(   464.26),
      SIMDE_FLOAT32_C(   -20.73),
      SIMDE_FLOAT32_C(   729.25),
      SIMDE_FLOAT32_C(   941.95),
      SIMDE_FLOAT32_C(  -546.52),
      SIMDE_FLOAT32_C(   -66.51),
      }
    },
    { { SIMDE_FLOAT32_C(   718.98), SIMDE_FLOAT32_C(  -700.91) },
      { SIMDE_FLOAT32_C(   749.81), SIMDE_FLOAT32_C(  -586.28) },
      { SIMDE_FLOAT32_C(  -652.38), SIMDE_FLOAT32_C(   307.52) },
      { SIMDE_FLOAT32_C(  -384.00), SIMDE_FLOAT32_C(   801.10) },
      {
      SIMDE_FLOAT32_C(   718.98),
      SIMDE_FLOAT32_C(   749.81),
      SIMDE_FLOAT32_C(  -652.38),
      SIMDE_FLOAT32_C(  -384.00),
      SIMDE_FLOAT32_C(  -700.91),
      SIMDE_FLOAT32_C(  -586.28),
      SIMDE_FLOAT32_C(   307.52),
      SIMDE_FLOAT32_C(   801.10),
      }
    },
    { { SIMDE_FLOAT32_C(   556.22), SIMDE_FLOAT32_C(   154.44) },
      { SIMDE_FLOAT32_C(   873.42), SIMDE_FLOAT32_C(  -964.19) },
      { SIMDE_FLOAT32_C(   -99.70), SIMDE_FLOAT32_C(  -227.50) },
      { SIMDE_FLOAT32_C(   592.78), SIMDE_FLOAT32_C(  -676.51) },
      {
      SIMDE_FLOAT32_C(   556.22),
      SIMDE_FLOAT32_C(   873.42),
      SIMDE_FLOAT32_C(   -99.70),
      SIMDE_FLOAT32_C(   592.78),
      SIMDE_FLOAT32_C(   154.44),
      SIMDE_FLOAT32_C(  -964.19),
      SIMDE_FLOAT32_C(  -227.50),
      SIMDE_FLOAT32_C(  -676.51),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x4_t r_ = { { simde_vld1_f32(test_vec[i].r0),
                                 simde_vld1_f32(test_vec[i].r1),
                                 simde_vld1_f32(test_vec[i].r2),
                                 simde_vld1_f32(test_vec[i].r3), } };

    simde_float32 a_[8];
    simde_vst4_f32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4_f32(a_);
    simde_test_arm_neon_assert_equal_f32x2(r_.val[0], simde_vld1_f32(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f32x2(r_.val[1], simde_vld1_f32(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f32x2(r_.val[2], simde_vld1_f32(test_vec[i].r2), 1);
    simde_test_arm_neon_assert_equal_f32x2(r_.val[3], simde_vld1_f32(test_vec[i].r3), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a0 = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t a1 = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t a2 = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t a3 = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_f32x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float32_t buf[8];
    simde_vst4_f32(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_f32(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r0[1];
    simde_float64 r1[1];
    simde_float64 r2[1];
    simde_float64 r3[1];
    simde_float64 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   624.60) },
      { SIMDE_FLOAT64_C(   658.33) },
      { SIMDE_FLOAT64_C(   990.90) },
      { SIMDE_FLOAT64_C(  -345.25) },
      {
      SIMDE_FLOAT64_C(   624.60),
      SIMDE_FLOAT64_C(   658.33),
      SIMDE_FLOAT64_C(   990.90),
      SIMDE_FLOAT64_C(  -345.25),
      }
    },
    { { SIMDE_FLOAT64_C(   563.48) },
      { SIMDE_FLOAT64_C(   508.25) },
      { SIMDE_FLOAT64_C(   888.63) },
      { SIMDE_FLOAT64_C(  -575.04) },
      {
      SIMDE_FLOAT64_C(   563.48),
      SIMDE_FLOAT64_C(   508.25),
      SIMDE_FLOAT64_C(   888.63),
      SIMDE_FLOAT64_C(  -575.04),
      }
    },
    { { SIMDE_FLOAT64_C(  -646.15) },
      { SIMDE_FLOAT64_C(   389.76) },
      { SIMDE_FLOAT64_C(   742.88) },
      { SIMDE_FLOAT64_C(  -788.98) },
      {
      SIMDE_FLOAT64_C(  -646.15),
      SIMDE_FLOAT64_C(   389.76),
      SIMDE_FLOAT64_C(   742.88),
      SIMDE_FLOAT64_C(  -788.98),
      }
    },
    { { SIMDE_FLOAT64_C(   856.06) },
      { SIMDE_FLOAT64_C(   722.96) },
      { SIMDE_FLOAT64_C(  -525.80) },
      { SIMDE_FLOAT64_C(  -581.83) },
      {
      SIMDE_FLOAT64_C(   856.06),
      SIMDE_FLOAT64_C(   722.96),
      SIMDE_FLOAT64_C(  -525.80),
      SIMDE_FLOAT64_C(  -581.83),
      }
    },
    { { SIMDE_FLOAT64_C(   936.61) },
      { SIMDE_FLOAT64_C(  -287.02) },
      { SIMDE_FLOAT64_C(   260.93) },
      { SIMDE_FLOAT64_C(   698.72) },
      {
      SIMDE_FLOAT64_C(   936.61),
      SIMDE_FLOAT64_C(  -287.02),
      SIMDE_FLOAT64_C(   260.93),
      SIMDE_FLOAT64_C(   698.72),
      }
    },
    { { SIMDE_FLOAT64_C(  -737.87) },
      { SIMDE_FLOAT64_C(   387.05) },
      { SIMDE_FLOAT64_C(   511.74) },
      { SIMDE_FLOAT64_C(  -545.62) },
      {
      SIMDE_FLOAT64_C(  -737.87),
      SIMDE_FLOAT64_C(   387.05),
      SIMDE_FLOAT64_C(   511.74),
      SIMDE_FLOAT64_C(  -545.62),
      }
    },
    { { SIMDE_FLOAT64_C(  -116.76) },
      { SIMDE_FLOAT64_C(   449.01) },
      { SIMDE_FLOAT64_C(   535.14) },
      { SIMDE_FLOAT64_C(   592.89) },
      {
      SIMDE_FLOAT64_C(  -116.76),
      SIMDE_FLOAT64_C(   449.01),
      SIMDE_FLOAT64_C(   535.14),
      SIMDE_FLOAT64_C(   592.89),
      }
    },
    { { SIMDE_FLOAT64_C(  -783.83) },
      { SIMDE_FLOAT64_C(   958.98) },
      { SIMDE_FLOAT64_C(  -896.71) },
      { SIMDE_FLOAT64_C(   840.77) },
      {
      SIMDE_FLOAT64_C(  -783.83),
      SIMDE_FLOAT64_C(   958.98),
      SIMDE_FLOAT64_C(  -896.71),
      SIMDE_FLOAT64_C(   840.77),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x4_t r_ = { { simde_vld1_f64(test_vec[i].r0),
                                 simde_vld1_f64(test_vec[i].r1),
                                 simde_vld1_f64(test_vec[i].r2),
                                 simde_vld1_f64(test_vec[i].r3), } };

    simde_float64_t a_[4];
    simde_vst4_f64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4_f64(a_);
    simde_test_arm_neon_assert_equal_f64x1(r_.val[0], simde_vld1_f64(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f64x1(r_.val[1], simde_vld1_f64(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f64x1(r_.val[2], simde_vld1_f64(test_vec[i].r2), 1);
    simde_test_arm_neon_assert_equal_f64x1(r_.val[3], simde_vld1_f64(test_vec[i].r3), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a0 = simde_test_arm_neon_random_f64x1(-1000.0f, 1000.0f);
    simde_float64x1_t a1 = simde_test_arm_neon_random_f64x1(-1000.0f, 1000.0f);
    simde_float64x1_t a2 = simde_test_arm_neon_random_f64x1(-1000.0f, 1000.0f);
    simde_float64x1_t a3 = simde_test_arm_neon_random_f64x1(-1000.0f, 1000.0f);
    simde_float64x1x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_f64x1(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float64_t buf[4];
    simde_vst4_f64(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_f64(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r0[8];
    int8_t r1[8];
    int8_t r2[8];
    int8_t r3[8];
    int8_t a[32];
  } test_vec[] = {
    { { -INT8_C(  32), -INT8_C(  94), -INT8_C( 106),  INT8_C( 115), -INT8_C(  56),  INT8_C( 118), -INT8_C(  83),  INT8_C(  12) },
      { -INT8_C(  18), -INT8_C(   2), -INT8_C(   8),  INT8_C(  95), -INT8_C( 117),  INT8_C(  56),  INT8_C(  92), -INT8_C(  94) },
      { -INT8_C(  45), -INT8_C(  37), -INT8_C( 110), -INT8_C(  10),      INT8_MAX,  INT8_C( 100), -INT8_C(  25),  INT8_C( 115) },
      { -INT8_C(   6),  INT8_C(  60), -INT8_C(  25),  INT8_C(  92), -INT8_C(  89), -INT8_C( 118), -INT8_C(  50), -INT8_C( 120) },
      {
      -INT8_C(  32),
      -INT8_C(  18),
      -INT8_C(  45),
      -INT8_C(   6),
      -INT8_C(  94),
      -INT8_C(   2),
      -INT8_C(  37),
       INT8_C(  60),
      -INT8_C( 106),
      -INT8_C(   8),
      -INT8_C( 110),
      -INT8_C(  25),
       INT8_C( 115),
       INT8_C(  95),
      -INT8_C(  10),
       INT8_C(  92),
      -INT8_C(  56),
      -INT8_C( 117),
           INT8_MAX,
      -INT8_C(  89),
       INT8_C( 118),
       INT8_C(  56),
       INT8_C( 100),
      -INT8_C( 118),
      -INT8_C(  83),
       INT8_C(  92),
      -INT8_C(  25),
      -INT8_C(  50),
       INT8_C(  12),
      -INT8_C(  94),
       INT8_C( 115),
      -INT8_C( 120),
      }
    },
    { {  INT8_C(  44),  INT8_C( 100), -INT8_C(   5), -INT8_C(  11), -INT8_C(  38), -INT8_C(  87),  INT8_C(   1), -INT8_C(  55) },
      { -INT8_C(  89), -INT8_C(   7),  INT8_C(  40),  INT8_C(  50),  INT8_C(  49), -INT8_C( 123), -INT8_C(  44),  INT8_C(   5) },
      {  INT8_C(  96),  INT8_C( 102), -INT8_C(   5), -INT8_C(  33), -INT8_C(  53), -INT8_C(  30),  INT8_C(  82), -INT8_C(  59) },
      {  INT8_C(  30),  INT8_C(  57),  INT8_C(  34), -INT8_C(  58), -INT8_C(  61), -INT8_C(  16),  INT8_C(  78), -INT8_C(  16) },
      {
       INT8_C(  44),
      -INT8_C(  89),
       INT8_C(  96),
       INT8_C(  30),
       INT8_C( 100),
      -INT8_C(   7),
       INT8_C( 102),
       INT8_C(  57),
      -INT8_C(   5),
       INT8_C(  40),
      -INT8_C(   5),
       INT8_C(  34),
      -INT8_C(  11),
       INT8_C(  50),
      -INT8_C(  33),
      -INT8_C(  58),
      -INT8_C(  38),
       INT8_C(  49),
      -INT8_C(  53),
      -INT8_C(  61),
      -INT8_C(  87),
      -INT8_C( 123),
      -INT8_C(  30),
      -INT8_C(  16),
       INT8_C(   1),
      -INT8_C(  44),
       INT8_C(  82),
       INT8_C(  78),
      -INT8_C(  55),
       INT8_C(   5),
      -INT8_C(  59),
      -INT8_C(  16),
      }
    },
    { {  INT8_C(  84),  INT8_C(  73), -INT8_C(  27),  INT8_C(  46), -INT8_C(  14), -INT8_C(  26), -INT8_C(   9), -INT8_C( 103) },
      { -INT8_C(  33),  INT8_C(  32), -INT8_C(  52),  INT8_C(  17), -INT8_C(  91), -INT8_C(  96),  INT8_C(  22),  INT8_C(   5) },
      {  INT8_C(   7),  INT8_C(  17), -INT8_C(  28), -INT8_C(  46), -INT8_C(  13),  INT8_C(  55), -INT8_C( 105),  INT8_C(  17) },
      {  INT8_C( 112), -INT8_C(  71), -INT8_C(  41),  INT8_C(  52), -INT8_C(  87),  INT8_C(  37),  INT8_C(  36), -INT8_C(   3) },
      {
       INT8_C(  84),
      -INT8_C(  33),
       INT8_C(   7),
       INT8_C( 112),
       INT8_C(  73),
       INT8_C(  32),
       INT8_C(  17),
      -INT8_C(  71),
      -INT8_C(  27),
      -INT8_C(  52),
      -INT8_C(  28),
      -INT8_C(  41),
       INT8_C(  46),
       INT8_C(  17),
      -INT8_C(  46),
       INT8_C(  52),
      -INT8_C(  14),
      -INT8_C(  91),
      -INT8_C(  13),
      -INT8_C(  87),
      -INT8_C(  26),
      -INT8_C(  96),
       INT8_C(  55),
       INT8_C(  37),
      -INT8_C(   9),
       INT8_C(  22),
      -INT8_C( 105),
       INT8_C(  36),
      -INT8_C( 103),
       INT8_C(   5),
       INT8_C(  17),
      -INT8_C(   3),
      }
    },
    { {  INT8_C( 111),  INT8_C(   9),  INT8_C(  44),  INT8_C(  97), -INT8_C(  17),  INT8_C(  35), -INT8_C(   5), -INT8_C(  50) },
      {  INT8_C(  67), -INT8_C(  57), -INT8_C(  33), -INT8_C(  24),  INT8_C( 103), -INT8_C(  11), -INT8_C(  19),  INT8_C( 110) },
      {  INT8_C(   6), -INT8_C(  46),  INT8_C(  64), -INT8_C(   7),  INT8_C(   9), -INT8_C(  40),  INT8_C(  11),  INT8_C( 121) },
      { -INT8_C( 111), -INT8_C(  30), -INT8_C(  83),  INT8_C(  59),  INT8_C(   8), -INT8_C(  47),  INT8_C(  56),  INT8_C( 119) },
      {
       INT8_C( 111),
       INT8_C(  67),
       INT8_C(   6),
      -INT8_C( 111),
       INT8_C(   9),
      -INT8_C(  57),
      -INT8_C(  46),
      -INT8_C(  30),
       INT8_C(  44),
      -INT8_C(  33),
       INT8_C(  64),
      -INT8_C(  83),
       INT8_C(  97),
      -INT8_C(  24),
      -INT8_C(   7),
       INT8_C(  59),
      -INT8_C(  17),
       INT8_C( 103),
       INT8_C(   9),
       INT8_C(   8),
       INT8_C(  35),
      -INT8_C(  11),
      -INT8_C(  40),
      -INT8_C(  47),
      -INT8_C(   5),
      -INT8_C(  19),
       INT8_C(  11),
       INT8_C(  56),
      -INT8_C(  50),
       INT8_C( 110),
       INT8_C( 121),
       INT8_C( 119),
      }
    },
    { { -INT8_C(  38),  INT8_C( 100), -INT8_C(  40), -INT8_C(  55), -INT8_C( 120), -INT8_C(  45), -INT8_C( 104), -INT8_C(  53) },
      { -INT8_C( 102),  INT8_C( 119), -INT8_C(  76),  INT8_C(   2),  INT8_C( 109), -INT8_C(  95),  INT8_C( 112),  INT8_C( 115) },
      {  INT8_C( 115), -INT8_C(  79),  INT8_C( 109),  INT8_C( 124), -INT8_C( 119),  INT8_C( 120), -INT8_C(  10),  INT8_C(  26) },
      {  INT8_C(  90), -INT8_C(  93),  INT8_C(  85),  INT8_C(  98),  INT8_C( 117), -INT8_C( 114), -INT8_C(  39),  INT8_C(  79) },
      {
      -INT8_C(  38),
      -INT8_C( 102),
       INT8_C( 115),
       INT8_C(  90),
       INT8_C( 100),
       INT8_C( 119),
      -INT8_C(  79),
      -INT8_C(  93),
      -INT8_C(  40),
      -INT8_C(  76),
       INT8_C( 109),
       INT8_C(  85),
      -INT8_C(  55),
       INT8_C(   2),
       INT8_C( 124),
       INT8_C(  98),
      -INT8_C( 120),
       INT8_C( 109),
      -INT8_C( 119),
       INT8_C( 117),
      -INT8_C(  45),
      -INT8_C(  95),
       INT8_C( 120),
      -INT8_C( 114),
      -INT8_C( 104),
       INT8_C( 112),
      -INT8_C(  10),
      -INT8_C(  39),
      -INT8_C(  53),
       INT8_C( 115),
       INT8_C(  26),
       INT8_C(  79),
      }
    },
    { { -INT8_C(  14), -INT8_C(  78),  INT8_C(  25),  INT8_C( 122), -INT8_C( 123), -INT8_C(  79),  INT8_C(  70),  INT8_C(  32) },
      {  INT8_C(  40), -INT8_C(   6),  INT8_C(  34), -INT8_C( 107), -INT8_C( 101), -INT8_C( 110),  INT8_C(   9),  INT8_C(  15) },
      {  INT8_C(  67),  INT8_C( 118), -INT8_C( 117), -INT8_C(  52), -INT8_C(  18), -INT8_C( 127), -INT8_C(  25),  INT8_C(  72) },
      {  INT8_C(  37),  INT8_C(  60), -INT8_C(  85), -INT8_C( 102), -INT8_C(  54), -INT8_C( 124), -INT8_C(  23), -INT8_C(  67) },
      {
      -INT8_C(  14),
       INT8_C(  40),
       INT8_C(  67),
       INT8_C(  37),
      -INT8_C(  78),
      -INT8_C(   6),
       INT8_C( 118),
       INT8_C(  60),
       INT8_C(  25),
       INT8_C(  34),
      -INT8_C( 117),
      -INT8_C(  85),
       INT8_C( 122),
      -INT8_C( 107),
      -INT8_C(  52),
      -INT8_C( 102),
      -INT8_C( 123),
      -INT8_C( 101),
      -INT8_C(  18),
      -INT8_C(  54),
      -INT8_C(  79),
      -INT8_C( 110),
      -INT8_C( 127),
      -INT8_C( 124),
       INT8_C(  70),
       INT8_C(   9),
      -INT8_C(  25),
      -INT8_C(  23),
       INT8_C(  32),
       INT8_C(  15),
       INT8_C(  72),
      -INT8_C(  67),
      }
    },
    { {  INT8_C(  54),  INT8_C(   2),  INT8_C(  55), -INT8_C(  68), -INT8_C(  77),  INT8_C( 125), -INT8_C(  36), -INT8_C(  36) },
      {  INT8_C( 119), -INT8_C(   2),  INT8_C( 113),  INT8_C(  19), -INT8_C( 112),  INT8_C( 122),  INT8_C(  34), -INT8_C(  44) },
      { -INT8_C(  16), -INT8_C(  83), -INT8_C(  96), -INT8_C(  34),  INT8_C(  47), -INT8_C( 121),  INT8_C(  39),  INT8_C(  84) },
      { -INT8_C(  60), -INT8_C(  46), -INT8_C(  18), -INT8_C( 114),  INT8_C(  86), -INT8_C(  41),  INT8_C(  75), -INT8_C( 115) },
      {
       INT8_C(  54),
       INT8_C( 119),
      -INT8_C(  16),
      -INT8_C(  60),
       INT8_C(   2),
      -INT8_C(   2),
      -INT8_C(  83),
      -INT8_C(  46),
       INT8_C(  55),
       INT8_C( 113),
      -INT8_C(  96),
      -INT8_C(  18),
      -INT8_C(  68),
       INT8_C(  19),
      -INT8_C(  34),
      -INT8_C( 114),
      -INT8_C(  77),
      -INT8_C( 112),
       INT8_C(  47),
       INT8_C(  86),
       INT8_C( 125),
       INT8_C( 122),
      -INT8_C( 121),
      -INT8_C(  41),
      -INT8_C(  36),
       INT8_C(  34),
       INT8_C(  39),
       INT8_C(  75),
      -INT8_C(  36),
      -INT8_C(  44),
       INT8_C(  84),
      -INT8_C( 115),
      }
    },
    { { -INT8_C(  38), -INT8_C( 125),  INT8_C(  73), -INT8_C( 115),  INT8_C(   0),  INT8_C(  37),  INT8_C( 105),  INT8_C( 120) },
      {  INT8_C(  35), -INT8_C(  37), -INT8_C( 117), -INT8_C(  77),  INT8_C(  85), -INT8_C(  83), -INT8_C( 121),  INT8_C(  70) },
      {  INT8_C(  90),  INT8_C(  40),  INT8_C(  36), -INT8_C( 119), -INT8_C(  81),  INT8_C(  75), -INT8_C(  35),  INT8_C( 115) },
      {  INT8_C(  29), -INT8_C(  53),  INT8_C(   2),  INT8_C( 116), -INT8_C(  93),  INT8_C(  77),  INT8_C(   1),  INT8_C( 125) },
      {
      -INT8_C(  38),
       INT8_C(  35),
       INT8_C(  90),
       INT8_C(  29),
      -INT8_C( 125),
      -INT8_C(  37),
       INT8_C(  40),
      -INT8_C(  53),
       INT8_C(  73),
      -INT8_C( 117),
       INT8_C(  36),
       INT8_C(   2),
      -INT8_C( 115),
      -INT8_C(  77),
      -INT8_C( 119),
       INT8_C( 116),
       INT8_C(   0),
       INT8_C(  85),
      -INT8_C(  81),
      -INT8_C(  93),
       INT8_C(  37),
      -INT8_C(  83),
       INT8_C(  75),
       INT8_C(  77),
       INT8_C( 105),
      -INT8_C( 121),
      -INT8_C(  35),
       INT8_C(   1),
       INT8_C( 120),
       INT8_C(  70),
       INT8_C( 115),
       INT8_C( 125),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x4_t r_ = { { simde_vld1_s8(test_vec[i].r0),
                              simde_vld1_s8(test_vec[i].r1),
                              simde_vld1_s8(test_vec[i].r2),
                              simde_vld1_s8(test_vec[i].r3), } };
    int8_t a_[32];
    simde_vst4_s8(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(a_)));

    r_ = simde_vld4_s8(a_);
    simde_test_arm_neon_assert_equal_i8x8(r_.val[0], simde_vld1_s8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i8x8(r_.val[1], simde_vld1_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x8(r_.val[2], simde_vld1_s8(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a0 = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t a1 = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t a2 = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t a3 = simde_test_arm_neon_random_i8x8();
    simde_int8x8x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_i8x8(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    int8_t buf[32];
    simde_vst4_s8(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_i8(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r0[4];
    int16_t r1[4];
    int16_t r2[4];
    int16_t r3[4];
    int16_t a[16];
  } test_vec[] = {
    { {  INT16_C(  5398), -INT16_C( 25729),  INT16_C( 15178),  INT16_C(   458) },
      {  INT16_C( 10086),  INT16_C( 28789), -INT16_C( 32315), -INT16_C(  3249) },
      {  INT16_C( 31188),  INT16_C( 24333),  INT16_C( 18929), -INT16_C( 14162) },
      { -INT16_C(  4559),  INT16_C( 31053),  INT16_C( 11632), -INT16_C( 30981) },
      {
       INT16_C(  5398),
       INT16_C( 10086),
       INT16_C( 31188),
      -INT16_C(  4559),
      -INT16_C( 25729),
       INT16_C( 28789),
       INT16_C( 24333),
       INT16_C( 31053),
       INT16_C( 15178),
      -INT16_C( 32315),
       INT16_C( 18929),
       INT16_C( 11632),
       INT16_C(   458),
      -INT16_C(  3249),
      -INT16_C( 14162),
      -INT16_C( 30981),
      }
    },
    { {  INT16_C( 31298), -INT16_C( 29663), -INT16_C(  5194),  INT16_C(  7309) },
      {  INT16_C(   786), -INT16_C( 10356), -INT16_C(  9340),  INT16_C( 22730) },
      { -INT16_C( 10156),  INT16_C( 17848),  INT16_C( 26145),  INT16_C( 21005) },
      {  INT16_C( 23381), -INT16_C( 14900), -INT16_C( 14456), -INT16_C( 13493) },
      {
       INT16_C( 31298),
       INT16_C(   786),
      -INT16_C( 10156),
       INT16_C( 23381),
      -INT16_C( 29663),
      -INT16_C( 10356),
       INT16_C( 17848),
      -INT16_C( 14900),
      -INT16_C(  5194),
      -INT16_C(  9340),
       INT16_C( 26145),
      -INT16_C( 14456),
       INT16_C(  7309),
       INT16_C( 22730),
       INT16_C( 21005),
      -INT16_C( 13493),
      }
    },
    { {  INT16_C( 27713), -INT16_C(  2217), -INT16_C(  6824),  INT16_C( 27155) },
      { -INT16_C( 24600),  INT16_C( 27714),  INT16_C(  3195), -INT16_C( 12347) },
      {  INT16_C( 32228),  INT16_C(  1301),  INT16_C(  8931),  INT16_C( 14424) },
      {  INT16_C(  9341),  INT16_C(  1789),  INT16_C( 18667),  INT16_C( 11473) },
      {
       INT16_C( 27713),
      -INT16_C( 24600),
       INT16_C( 32228),
       INT16_C(  9341),
      -INT16_C(  2217),
       INT16_C( 27714),
       INT16_C(  1301),
       INT16_C(  1789),
      -INT16_C(  6824),
       INT16_C(  3195),
       INT16_C(  8931),
       INT16_C( 18667),
       INT16_C( 27155),
      -INT16_C( 12347),
       INT16_C( 14424),
       INT16_C( 11473),
      }
    },
    { {  INT16_C( 10421),  INT16_C(  3364),  INT16_C( 14093), -INT16_C(  2697) },
      { -INT16_C( 17961),  INT16_C( 21090),  INT16_C( 10182), -INT16_C( 21983) },
      {  INT16_C( 13988), -INT16_C( 30800),  INT16_C(  2137), -INT16_C( 10560) },
      { -INT16_C( 17108),  INT16_C(  6108), -INT16_C( 21242), -INT16_C( 17597) },
      {
       INT16_C( 10421),
      -INT16_C( 17961),
       INT16_C( 13988),
      -INT16_C( 17108),
       INT16_C(  3364),
       INT16_C( 21090),
      -INT16_C( 30800),
       INT16_C(  6108),
       INT16_C( 14093),
       INT16_C( 10182),
       INT16_C(  2137),
      -INT16_C( 21242),
      -INT16_C(  2697),
      -INT16_C( 21983),
      -INT16_C( 10560),
      -INT16_C( 17597),
      }
    },
    { {  INT16_C( 26582), -INT16_C(  7224),  INT16_C( 16287),  INT16_C( 30425) },
      {  INT16_C( 15353), -INT16_C( 16440), -INT16_C(  5790),  INT16_C(  1641) },
      {  INT16_C(  6432),  INT16_C( 31117),  INT16_C( 19745),  INT16_C( 19791) },
      {  INT16_C( 11275),  INT16_C(  4452), -INT16_C( 22311), -INT16_C( 20532) },
      {
       INT16_C( 26582),
       INT16_C( 15353),
       INT16_C(  6432),
       INT16_C( 11275),
      -INT16_C(  7224),
      -INT16_C( 16440),
       INT16_C( 31117),
       INT16_C(  4452),
       INT16_C( 16287),
      -INT16_C(  5790),
       INT16_C( 19745),
      -INT16_C( 22311),
       INT16_C( 30425),
       INT16_C(  1641),
       INT16_C( 19791),
      -INT16_C( 20532),
      }
    },
    { { -INT16_C( 27633), -INT16_C( 20845),  INT16_C( 27859), -INT16_C( 13276) },
      { -INT16_C(  4953),  INT16_C(  2443), -INT16_C(  2602), -INT16_C(  2545) },
      { -INT16_C( 25586),  INT16_C( 12399), -INT16_C( 16662), -INT16_C(  2691) },
      { -INT16_C(  7446), -INT16_C( 15354), -INT16_C( 11638), -INT16_C( 26253) },
      {
      -INT16_C( 27633),
      -INT16_C(  4953),
      -INT16_C( 25586),
      -INT16_C(  7446),
      -INT16_C( 20845),
       INT16_C(  2443),
       INT16_C( 12399),
      -INT16_C( 15354),
       INT16_C( 27859),
      -INT16_C(  2602),
      -INT16_C( 16662),
      -INT16_C( 11638),
      -INT16_C( 13276),
      -INT16_C(  2545),
      -INT16_C(  2691),
      -INT16_C( 26253),
      }
    },
    { {  INT16_C(  1638),  INT16_C( 14664),  INT16_C( 27762),  INT16_C(  6406) },
      { -INT16_C( 28327),  INT16_C( 12066),  INT16_C( 12678), -INT16_C( 27355) },
      { -INT16_C( 27442), -INT16_C( 18235),  INT16_C( 16978),  INT16_C( 15789) },
      { -INT16_C( 19676), -INT16_C( 20991),  INT16_C( 29829), -INT16_C(  5304) },
      {
       INT16_C(  1638),
      -INT16_C( 28327),
      -INT16_C( 27442),
      -INT16_C( 19676),
       INT16_C( 14664),
       INT16_C( 12066),
      -INT16_C( 18235),
      -INT16_C( 20991),
       INT16_C( 27762),
       INT16_C( 12678),
       INT16_C( 16978),
       INT16_C( 29829),
       INT16_C(  6406),
      -INT16_C( 27355),
       INT16_C( 15789),
      -INT16_C(  5304),
      }
    },
    { { -INT16_C( 28549), -INT16_C(  4828),  INT16_C( 11004),  INT16_C( 21767) },
      {  INT16_C( 10684),  INT16_C( 17028), -INT16_C( 22181),  INT16_C( 10711) },
      { -INT16_C( 25539), -INT16_C( 28447), -INT16_C( 28961),  INT16_C(   973) },
      { -INT16_C( 12735), -INT16_C( 14670), -INT16_C(  1470), -INT16_C( 16975) },
      {
      -INT16_C( 28549),
       INT16_C( 10684),
      -INT16_C( 25539),
      -INT16_C( 12735),
      -INT16_C(  4828),
       INT16_C( 17028),
      -INT16_C( 28447),
      -INT16_C( 14670),
       INT16_C( 11004),
      -INT16_C( 22181),
      -INT16_C( 28961),
      -INT16_C(  1470),
       INT16_C( 21767),
       INT16_C( 10711),
       INT16_C(   973),
      -INT16_C( 16975),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x4_t r_ = { { simde_vld1_s16(test_vec[i].r0),
                               simde_vld1_s16(test_vec[i].r1),
                               simde_vld1_s16(test_vec[i].r2),
                               simde_vld1_s16(test_vec[i].r3), } };

    int16_t a_[16];
    simde_vst4_s16(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4_s16(a_);
    simde_test_arm_neon_assert_equal_i16x4(r_.val[0], simde_vld1_s16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i16x4(r_.val[1], simde_vld1_s16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i16x4(r_.val[2], simde_vld1_s16(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a0 = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t a1 = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t a2 = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t a3 = simde_test_arm_neon_random_i16x4();
    simde_int16x4x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_i16x4(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    int16_t buf[16];
    simde_vst4_s16(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_i16(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r0[2];
    int32_t r1[2];
    int32_t r2[2];
    int32_t r3[2];
    int32_t a[8];
  } test_vec[] = {
    { { -INT32_C(  1421389733),  INT32_C(  1091510019) },
      { -INT32_C(   855567543),  INT32_C(  1758550749) },
      { -INT32_C(   548252799),  INT32_C(  1558828652) },
      { -INT32_C(  1985916028), -INT32_C(   288439918) },
      {
      -INT32_C(  1421389733),
      -INT32_C(   855567543),
      -INT32_C(   548252799),
      -INT32_C(  1985916028),
       INT32_C(  1091510019),
       INT32_C(  1758550749),
       INT32_C(  1558828652),
      -INT32_C(   288439918),
      }
    },
    { {  INT32_C(   362354193),  INT32_C(  2119608373) },
      { -INT32_C(  1723049796),  INT32_C(   872488370) },
      { -INT32_C(   585936016), -INT32_C(  1371931606) },
      { -INT32_C(   499655856), -INT32_C(  1378876004) },
      {
       INT32_C(   362354193),
      -INT32_C(  1723049796),
      -INT32_C(   585936016),
      -INT32_C(   499655856),
       INT32_C(  2119608373),
       INT32_C(   872488370),
      -INT32_C(  1371931606),
      -INT32_C(  1378876004),
      }
    },
    { {  INT32_C(  1371695387), -INT32_C(   825288430) },
      {  INT32_C(   593959793), -INT32_C(  1453889479) },
      { -INT32_C(   427398468), -INT32_C(  1214988185) },
      {  INT32_C(   932826011), -INT32_C(   320574768) },
      {
       INT32_C(  1371695387),
       INT32_C(   593959793),
      -INT32_C(   427398468),
       INT32_C(   932826011),
      -INT32_C(   825288430),
      -INT32_C(  1453889479),
      -INT32_C(  1214988185),
      -INT32_C(   320574768),
      }
    },
    { { -INT32_C(   448944173),  INT32_C(   833817792) },
      {  INT32_C(  1632901672),  INT32_C(  1057664131) },
      {  INT32_C(  2099613974), -INT32_C(   332089007) },
      {  INT32_C(  1411632772),  INT32_C(   188745528) },
      {
      -INT32_C(   448944173),
       INT32_C(  1632901672),
       INT32_C(  2099613974),
       INT32_C(  1411632772),
       INT32_C(   833817792),
       INT32_C(  1057664131),
      -INT32_C(   332089007),
       INT32_C(   188745528),
      }
    },
    { {  INT32_C(  1861320110), -INT32_C(  1298160502) },
      {  INT32_C(  1108604095), -INT32_C(  1233052256) },
      { -INT32_C(    13326674), -INT32_C(   471111585) },
      {  INT32_C(  1849101878), -INT32_C(   998606826) },
      {
       INT32_C(  1861320110),
       INT32_C(  1108604095),
      -INT32_C(    13326674),
       INT32_C(  1849101878),
      -INT32_C(  1298160502),
      -INT32_C(  1233052256),
      -INT32_C(   471111585),
      -INT32_C(   998606826),
      }
    },
    { {  INT32_C(  2134076405), -INT32_C(   835595761) },
      {  INT32_C(  1712342214),  INT32_C(   270373218) },
      { -INT32_C(  1777315529), -INT32_C(   260441159) },
      {  INT32_C(   543076618),  INT32_C(   518314025) },
      {
       INT32_C(  2134076405),
       INT32_C(  1712342214),
      -INT32_C(  1777315529),
       INT32_C(   543076618),
      -INT32_C(   835595761),
       INT32_C(   270373218),
      -INT32_C(   260441159),
       INT32_C(   518314025),
      }
    },
    { {  INT32_C(  1402869571), -INT32_C(  1339961366) },
      {  INT32_C(  1981231636), -INT32_C(    75090749) },
      {  INT32_C(  1049728645), -INT32_C(  1674703982) },
      { -INT32_C(   440627780), -INT32_C(  1459380123) },
      {
       INT32_C(  1402869571),
       INT32_C(  1981231636),
       INT32_C(  1049728645),
      -INT32_C(   440627780),
      -INT32_C(  1339961366),
      -INT32_C(    75090749),
      -INT32_C(  1674703982),
      -INT32_C(  1459380123),
      }
    },
    { { -INT32_C(  1560501832), -INT32_C(  2058216079) },
      {  INT32_C(   335243599),  INT32_C(   571376029) },
      { -INT32_C(  1436442856),  INT32_C(  1715900330) },
      { -INT32_C(  2109013476),  INT32_C(  1512787874) },
      {
      -INT32_C(  1560501832),
       INT32_C(   335243599),
      -INT32_C(  1436442856),
      -INT32_C(  2109013476),
      -INT32_C(  2058216079),
       INT32_C(   571376029),
       INT32_C(  1715900330),
       INT32_C(  1512787874),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x4_t r_ = { { simde_vld1_s32(test_vec[i].r0),
                               simde_vld1_s32(test_vec[i].r1),
                               simde_vld1_s32(test_vec[i].r2),
                               simde_vld1_s32(test_vec[i].r3), } };

    int32_t a_[8];
    simde_vst4_s32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4_s32(a_);
    simde_test_arm_neon_assert_equal_i32x2(r_.val[0], simde_vld1_s32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i32x2(r_.val[1], simde_vld1_s32(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i32x2(r_.val[2], simde_vld1_s32(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a0 = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t a1 = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t a2 = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t a3 = simde_test_arm_neon_random_i32x2();
    simde_int32x2x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_i32x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    int32_t buf[8];
    simde_vst4_s32(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_i32(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r0[1];
    int64_t r1[1];
    int64_t r2[1];
    int64_t r3[1];
    int64_t a[4];
  } test_vec[] = {
    { { -INT64_C( 1447547888260701651) },
      { -INT64_C( 3827526438922877263) },
      {  INT64_C(  524167343945907796) },
      { -INT64_C( 7563624692450300060) },
      {
      -INT64_C( 1447547888260701651),
      -INT64_C( 3827526438922877263),
       INT64_C(  524167343945907796),
      -INT64_C( 7563624692450300060),
      }
    },
    { { -INT64_C( 2808569240011087299) },
      { -INT64_C( 3116109957209416452) },
      {  INT64_C( 2183170197427815128) },
      {  INT64_C( 5016629588355083676) },
      {
      -INT64_C( 2808569240011087299),
      -INT64_C( 3116109957209416452),
       INT64_C( 2183170197427815128),
       INT64_C( 5016629588355083676),
      }
    },
    { { -INT64_C( 7166522641185002871) },
      {  INT64_C( 3915129315457696769) },
      {  INT64_C(  481824040889826519) },
      {  INT64_C( 9043980067198029365) },
      {
      -INT64_C( 7166522641185002871),
       INT64_C( 3915129315457696769),
       INT64_C(  481824040889826519),
       INT64_C( 9043980067198029365),
      }
    },
    { {  INT64_C( 5157389337233449302) },
      {  INT64_C( 5931837169018086846) },
      { -INT64_C( 3762032262956986790) },
      { -INT64_C( 2858789043925624863) },
      {
       INT64_C( 5157389337233449302),
       INT64_C( 5931837169018086846),
      -INT64_C( 3762032262956986790),
      -INT64_C( 2858789043925624863),
      }
    },
    { { -INT64_C(  362152481212431765) },
      {  INT64_C( 4202536713573548678) },
      { -INT64_C( 6154229596725299658) },
      { -INT64_C( 7639562743766343777) },
      {
      -INT64_C(  362152481212431765),
       INT64_C( 4202536713573548678),
      -INT64_C( 6154229596725299658),
      -INT64_C( 7639562743766343777),
      }
    },
    { { -INT64_C( 5797751023027631788) },
      {  INT64_C( 4547793440195256322) },
      { -INT64_C( 8958886834058028232) },
      {  INT64_C( 5909181196396735299) },
      {
      -INT64_C( 5797751023027631788),
       INT64_C( 4547793440195256322),
      -INT64_C( 8958886834058028232),
       INT64_C( 5909181196396735299),
      }
    },
    { { -INT64_C( 8412040716332414871) },
      {  INT64_C( 3266952460168524301) },
      {  INT64_C( 5192327137732747942) },
      { -INT64_C( 4876072028891401467) },
      {
      -INT64_C( 8412040716332414871),
       INT64_C( 3266952460168524301),
       INT64_C( 5192327137732747942),
      -INT64_C( 4876072028891401467),
      }
    },
    { { -INT64_C( 5687041768591247361) },
      { -INT64_C( 5502239805841833597) },
      { -INT64_C( 5562425281119136896) },
      {  INT64_C( 4039457532579972095) },
      {
      -INT64_C( 5687041768591247361),
      -INT64_C( 5502239805841833597),
      -INT64_C( 5562425281119136896),
       INT64_C( 4039457532579972095),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x4_t r_ = { { simde_vld1_s64(test_vec[i].r0),
                               simde_vld1_s64(test_vec[i].r1),
                               simde_vld1_s64(test_vec[i].r2),
                               simde_vld1_s64(test_vec[i].r3), } };

    int64_t a_[4];
    simde_vst4_s64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4_s64(a_);
    simde_test_arm_neon_assert_equal_i64x1(r_.val[0], simde_vld1_s64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i64x1(r_.val[1], simde_vld1_s64(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i64x1(r_.val[2], simde_vld1_s64(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a0 = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t a1 = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t a2 = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t a3 = simde_test_arm_neon_random_i64x1();
    simde_int64x1x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_i64x1(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    int64_t buf[4];
    simde_vst4_s64(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_i64(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r0[8];
    uint8_t r1[8];
    uint8_t r2[8];
    uint8_t r3[8];
    uint8_t a[32];
  } test_vec[] = {
    { { UINT8_C(195), UINT8_C(195), UINT8_C( 72), UINT8_C(180), UINT8_C(152), UINT8_C(218), UINT8_C( 85), UINT8_C(252) },
      { UINT8_C(167), UINT8_C( 84), UINT8_C(101), UINT8_C(151), UINT8_C( 48), UINT8_C(151), UINT8_C( 79), UINT8_C( 76) },
      { UINT8_C(221), UINT8_C( 97), UINT8_C( 95), UINT8_C(196), UINT8_C( 26), UINT8_C( 93), UINT8_C(153), UINT8_C(174) },
      { UINT8_C(240), UINT8_C( 96), UINT8_C( 57), UINT8_C( 51), UINT8_C(183), UINT8_C( 88), UINT8_C(175), UINT8_C(122) },
      {
      UINT8_C(195),
      UINT8_C(167),
      UINT8_C(221),
      UINT8_C(240),
      UINT8_C(195),
      UINT8_C( 84),
      UINT8_C( 97),
      UINT8_C( 96),
      UINT8_C( 72),
      UINT8_C(101),
      UINT8_C( 95),
      UINT8_C( 57),
      UINT8_C(180),
      UINT8_C(151),
      UINT8_C(196),
      UINT8_C( 51),
      UINT8_C(152),
      UINT8_C( 48),
      UINT8_C( 26),
      UINT8_C(183),
      UINT8_C(218),
      UINT8_C(151),
      UINT8_C( 93),
      UINT8_C( 88),
      UINT8_C( 85),
      UINT8_C( 79),
      UINT8_C(153),
      UINT8_C(175),
      UINT8_C(252),
      UINT8_C( 76),
      UINT8_C(174),
      UINT8_C(122),
      }
    },
    { { UINT8_C( 27), UINT8_C(247), UINT8_C( 47), UINT8_C(180), UINT8_C(209), UINT8_C(132), UINT8_C(176), UINT8_C(120) },
      { UINT8_C(216), UINT8_C( 22), UINT8_C( 15), UINT8_C(  9), UINT8_C(173), UINT8_C( 95), UINT8_C( 85), UINT8_C(138) },
      { UINT8_C(192), UINT8_C(180), UINT8_C( 79), UINT8_C(219), UINT8_C( 17), UINT8_C(232), UINT8_C(137), UINT8_C(  2) },
      { UINT8_C( 73), UINT8_C(195), UINT8_C( 53), UINT8_C(  0), UINT8_C( 27), UINT8_C(228), UINT8_C(123), UINT8_C( 54) },
      {
      UINT8_C( 27),
      UINT8_C(216),
      UINT8_C(192),
      UINT8_C( 73),
      UINT8_C(247),
      UINT8_C( 22),
      UINT8_C(180),
      UINT8_C(195),
      UINT8_C( 47),
      UINT8_C( 15),
      UINT8_C( 79),
      UINT8_C( 53),
      UINT8_C(180),
      UINT8_C(  9),
      UINT8_C(219),
      UINT8_C(  0),
      UINT8_C(209),
      UINT8_C(173),
      UINT8_C( 17),
      UINT8_C( 27),
      UINT8_C(132),
      UINT8_C( 95),
      UINT8_C(232),
      UINT8_C(228),
      UINT8_C(176),
      UINT8_C( 85),
      UINT8_C(137),
      UINT8_C(123),
      UINT8_C(120),
      UINT8_C(138),
      UINT8_C(  2),
      UINT8_C( 54),
      }
    },
    { { UINT8_C(219), UINT8_C(170), UINT8_C(234), UINT8_C(172), UINT8_C( 46), UINT8_C(155), UINT8_C( 36), UINT8_C(  6) },
      { UINT8_C(177), UINT8_C( 52), UINT8_C( 15), UINT8_C( 94), UINT8_C(147), UINT8_C(101), UINT8_C(233), UINT8_C( 83) },
      { UINT8_C( 25), UINT8_C( 56), UINT8_C( 46), UINT8_C( 43), UINT8_C( 32), UINT8_C(184), UINT8_C( 45), UINT8_C(105) },
      { UINT8_C(123), UINT8_C( 98), UINT8_C(106), UINT8_C(150), UINT8_C( 71), UINT8_C(229), UINT8_C(204), UINT8_C( 34) },
      {
      UINT8_C(219),
      UINT8_C(177),
      UINT8_C( 25),
      UINT8_C(123),
      UINT8_C(170),
      UINT8_C( 52),
      UINT8_C( 56),
      UINT8_C( 98),
      UINT8_C(234),
      UINT8_C( 15),
      UINT8_C( 46),
      UINT8_C(106),
      UINT8_C(172),
      UINT8_C( 94),
      UINT8_C( 43),
      UINT8_C(150),
      UINT8_C( 46),
      UINT8_C(147),
      UINT8_C( 32),
      UINT8_C( 71),
      UINT8_C(155),
      UINT8_C(101),
      UINT8_C(184),
      UINT8_C(229),
      UINT8_C( 36),
      UINT8_C(233),
      UINT8_C( 45),
      UINT8_C(204),
      UINT8_C(  6),
      UINT8_C( 83),
      UINT8_C(105),
      UINT8_C( 34),
      }
    },
    { { UINT8_C(143), UINT8_C(183), UINT8_C(207), UINT8_C(189), UINT8_C( 82), UINT8_C(243), UINT8_C(195), UINT8_C(  3) },
      { UINT8_C( 39), UINT8_C(211), UINT8_C( 97), UINT8_C(186), UINT8_C( 56), UINT8_C( 74), UINT8_C( 14), UINT8_C( 81) },
      { UINT8_C(130), UINT8_C( 60), UINT8_C(124), UINT8_C(163), UINT8_C(244), UINT8_C(169), UINT8_C( 12), UINT8_C(111) },
      { UINT8_C( 12), UINT8_C(118), UINT8_C(  5), UINT8_C( 83), UINT8_C( 91), UINT8_C(210), UINT8_C(117), UINT8_C(234) },
      {
      UINT8_C(143),
      UINT8_C( 39),
      UINT8_C(130),
      UINT8_C( 12),
      UINT8_C(183),
      UINT8_C(211),
      UINT8_C( 60),
      UINT8_C(118),
      UINT8_C(207),
      UINT8_C( 97),
      UINT8_C(124),
      UINT8_C(  5),
      UINT8_C(189),
      UINT8_C(186),
      UINT8_C(163),
      UINT8_C( 83),
      UINT8_C( 82),
      UINT8_C( 56),
      UINT8_C(244),
      UINT8_C( 91),
      UINT8_C(243),
      UINT8_C( 74),
      UINT8_C(169),
      UINT8_C(210),
      UINT8_C(195),
      UINT8_C( 14),
      UINT8_C( 12),
      UINT8_C(117),
      UINT8_C(  3),
      UINT8_C( 81),
      UINT8_C(111),
      UINT8_C(234),
      }
    },
    { { UINT8_C(137), UINT8_C( 68), UINT8_C(167), UINT8_C(219), UINT8_C( 56), UINT8_C(107), UINT8_C(222), UINT8_C( 95) },
      { UINT8_C( 62), UINT8_C( 63), UINT8_C( 26), UINT8_C(118), UINT8_C(138), UINT8_C( 40), UINT8_C(199), UINT8_C( 12) },
      { UINT8_C(100), UINT8_C( 68), UINT8_C(175), UINT8_C( 89), UINT8_C(237), UINT8_C(188), UINT8_C(200), UINT8_C(249) },
      { UINT8_C( 50), UINT8_C(206), UINT8_C( 76), UINT8_C(142), UINT8_C(160), UINT8_C(194), UINT8_C(120), UINT8_C( 41) },
      {
      UINT8_C(137),
      UINT8_C( 62),
      UINT8_C(100),
      UINT8_C( 50),
      UINT8_C( 68),
      UINT8_C( 63),
      UINT8_C( 68),
      UINT8_C(206),
      UINT8_C(167),
      UINT8_C( 26),
      UINT8_C(175),
      UINT8_C( 76),
      UINT8_C(219),
      UINT8_C(118),
      UINT8_C( 89),
      UINT8_C(142),
      UINT8_C( 56),
      UINT8_C(138),
      UINT8_C(237),
      UINT8_C(160),
      UINT8_C(107),
      UINT8_C( 40),
      UINT8_C(188),
      UINT8_C(194),
      UINT8_C(222),
      UINT8_C(199),
      UINT8_C(200),
      UINT8_C(120),
      UINT8_C( 95),
      UINT8_C( 12),
      UINT8_C(249),
      UINT8_C( 41),
      }
    },
    { { UINT8_C(  6), UINT8_C( 32), UINT8_C(  4), UINT8_C( 62), UINT8_C(139), UINT8_C(226), UINT8_C(158), UINT8_C(201) },
      { UINT8_C( 33), UINT8_C(184), UINT8_C( 63), UINT8_C(171), UINT8_C(224), UINT8_C(  6), UINT8_C(184), UINT8_C( 68) },
      { UINT8_C( 74), UINT8_C(103), UINT8_C(157), UINT8_C( 56), UINT8_C( 35), UINT8_C(102), UINT8_C( 49), UINT8_C( 86) },
      { UINT8_C( 52), UINT8_C(126), UINT8_C(228), UINT8_C(212), UINT8_C( 64), UINT8_C( 92), UINT8_C(253), UINT8_C( 70) },
      {
      UINT8_C(  6),
      UINT8_C( 33),
      UINT8_C( 74),
      UINT8_C( 52),
      UINT8_C( 32),
      UINT8_C(184),
      UINT8_C(103),
      UINT8_C(126),
      UINT8_C(  4),
      UINT8_C( 63),
      UINT8_C(157),
      UINT8_C(228),
      UINT8_C( 62),
      UINT8_C(171),
      UINT8_C( 56),
      UINT8_C(212),
      UINT8_C(139),
      UINT8_C(224),
      UINT8_C( 35),
      UINT8_C( 64),
      UINT8_C(226),
      UINT8_C(  6),
      UINT8_C(102),
      UINT8_C( 92),
      UINT8_C(158),
      UINT8_C(184),
      UINT8_C( 49),
      UINT8_C(253),
      UINT8_C(201),
      UINT8_C( 68),
      UINT8_C( 86),
      UINT8_C( 70),
      }
    },
    { { UINT8_C(124), UINT8_C(  1), UINT8_C(133), UINT8_C(  7), UINT8_C(227), UINT8_C( 35), UINT8_C(208), UINT8_C(  4) },
      { UINT8_C(219), UINT8_C( 15), UINT8_C(176), UINT8_C(187), UINT8_C( 22), UINT8_C(104),    UINT8_MAX, UINT8_C( 96) },
      { UINT8_C(207), UINT8_C(157), UINT8_C(152), UINT8_C(243), UINT8_C(  3), UINT8_C(202), UINT8_C( 73), UINT8_C( 55) },
      { UINT8_C( 72), UINT8_C( 45), UINT8_C( 11), UINT8_C(136), UINT8_C(137), UINT8_C(  8), UINT8_C(206), UINT8_C(  6) },
      {
      UINT8_C(124),
      UINT8_C(219),
      UINT8_C(207),
      UINT8_C( 72),
      UINT8_C(  1),
      UINT8_C( 15),
      UINT8_C(157),
      UINT8_C( 45),
      UINT8_C(133),
      UINT8_C(176),
      UINT8_C(152),
      UINT8_C( 11),
      UINT8_C(  7),
      UINT8_C(187),
      UINT8_C(243),
      UINT8_C(136),
      UINT8_C(227),
      UINT8_C( 22),
      UINT8_C(  3),
      UINT8_C(137),
      UINT8_C( 35),
      UINT8_C(104),
      UINT8_C(202),
      UINT8_C(  8),
      UINT8_C(208),
         UINT8_MAX,
      UINT8_C( 73),
      UINT8_C(206),
      UINT8_C(  4),
      UINT8_C( 96),
      UINT8_C( 55),
      UINT8_C(  6),
      }
    },
    { { UINT8_C(  9), UINT8_C( 83), UINT8_C( 13), UINT8_C(236), UINT8_C(118), UINT8_C(222), UINT8_C(240), UINT8_C( 81) },
      { UINT8_C(237), UINT8_C(160), UINT8_C( 12), UINT8_C(  3), UINT8_C(  8), UINT8_C( 12), UINT8_C(100), UINT8_C(216) },
      { UINT8_C(169), UINT8_C(252), UINT8_C(203), UINT8_C(172), UINT8_C(198), UINT8_C( 20), UINT8_C(227), UINT8_C( 14) },
      { UINT8_C( 65), UINT8_C(238), UINT8_C(150), UINT8_C(202), UINT8_C(246), UINT8_C(101), UINT8_C(208),    UINT8_MAX },
      {
      UINT8_C(  9),
      UINT8_C(237),
      UINT8_C(169),
      UINT8_C( 65),
      UINT8_C( 83),
      UINT8_C(160),
      UINT8_C(252),
      UINT8_C(238),
      UINT8_C( 13),
      UINT8_C( 12),
      UINT8_C(203),
      UINT8_C(150),
      UINT8_C(236),
      UINT8_C(  3),
      UINT8_C(172),
      UINT8_C(202),
      UINT8_C(118),
      UINT8_C(  8),
      UINT8_C(198),
      UINT8_C(246),
      UINT8_C(222),
      UINT8_C( 12),
      UINT8_C( 20),
      UINT8_C(101),
      UINT8_C(240),
      UINT8_C(100),
      UINT8_C(227),
      UINT8_C(208),
      UINT8_C( 81),
      UINT8_C(216),
      UINT8_C( 14),
         UINT8_MAX,
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x4_t r_ = { { simde_vld1_u8(test_vec[i].r0),
                               simde_vld1_u8(test_vec[i].r1),
                               simde_vld1_u8(test_vec[i].r2),
                               simde_vld1_u8(test_vec[i].r3), } };

    uint8_t a_[32];
    simde_vst4_u8(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4_u8(a_);
    simde_test_arm_neon_assert_equal_u8x8(r_.val[0], simde_vld1_u8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u8x8(r_.val[1], simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r_.val[2], simde_vld1_u8(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (size_t i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a0 = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t a1 = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t a2 = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t a3 = simde_test_arm_neon_random_u8x8();
    simde_uint8x8x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_u8x8(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    uint8_t buf[32];
    simde_vst4_u8(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_u8(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r0[4];
    uint16_t r1[4];
    uint16_t r2[4];
    uint16_t r3[4];
    uint16_t a[16];
  } test_vec[] = {
    { { UINT16_C( 7053), UINT16_C(18194), UINT16_C(41501), UINT16_C( 5028) },
      { UINT16_C(23380), UINT16_C(23265), UINT16_C(39297), UINT16_C(36422) },
      { UINT16_C(64123), UINT16_C(47306), UINT16_C(63985), UINT16_C(40762) },
      { UINT16_C(48714), UINT16_C(44810), UINT16_C(41814), UINT16_C(58351) },
      {
      UINT16_C( 7053),
      UINT16_C(23380),
      UINT16_C(64123),
      UINT16_C(48714),
      UINT16_C(18194),
      UINT16_C(23265),
      UINT16_C(47306),
      UINT16_C(44810),
      UINT16_C(41501),
      UINT16_C(39297),
      UINT16_C(63985),
      UINT16_C(41814),
      UINT16_C( 5028),
      UINT16_C(36422),
      UINT16_C(40762),
      UINT16_C(58351),
      }
    },
    { { UINT16_C(  446), UINT16_C(56106), UINT16_C(53155), UINT16_C(63470) },
      { UINT16_C(53034), UINT16_C(44114), UINT16_C(39016), UINT16_C(58170) },
      { UINT16_C( 1171), UINT16_C(33948), UINT16_C(55037), UINT16_C(18211) },
      { UINT16_C(11669), UINT16_C(60407), UINT16_C(59088), UINT16_C(36558) },
      {
      UINT16_C(  446),
      UINT16_C(53034),
      UINT16_C( 1171),
      UINT16_C(11669),
      UINT16_C(56106),
      UINT16_C(44114),
      UINT16_C(33948),
      UINT16_C(60407),
      UINT16_C(53155),
      UINT16_C(39016),
      UINT16_C(55037),
      UINT16_C(59088),
      UINT16_C(63470),
      UINT16_C(58170),
      UINT16_C(18211),
      UINT16_C(36558),
      }
    },
    { { UINT16_C(63719), UINT16_C(35434), UINT16_C(22727), UINT16_C(62081) },
      { UINT16_C(54056), UINT16_C(37022), UINT16_C(55404), UINT16_C(65396) },
      { UINT16_C( 4316), UINT16_C(55939), UINT16_C(42726), UINT16_C(31521) },
      { UINT16_C( 6355), UINT16_C(42086), UINT16_C(13566), UINT16_C(58674) },
      {
      UINT16_C(63719),
      UINT16_C(54056),
      UINT16_C( 4316),
      UINT16_C( 6355),
      UINT16_C(35434),
      UINT16_C(37022),
      UINT16_C(55939),
      UINT16_C(42086),
      UINT16_C(22727),
      UINT16_C(55404),
      UINT16_C(42726),
      UINT16_C(13566),
      UINT16_C(62081),
      UINT16_C(65396),
      UINT16_C(31521),
      UINT16_C(58674),
      }
    },
    { { UINT16_C(39981), UINT16_C(62575), UINT16_C(61941), UINT16_C( 7654) },
      { UINT16_C(33988), UINT16_C(12461), UINT16_C( 8540), UINT16_C(14639) },
      { UINT16_C(45617), UINT16_C( 6163), UINT16_C(13400), UINT16_C(11411) },
      { UINT16_C(64077), UINT16_C(19408), UINT16_C(  558), UINT16_C(23345) },
      {
      UINT16_C(39981),
      UINT16_C(33988),
      UINT16_C(45617),
      UINT16_C(64077),
      UINT16_C(62575),
      UINT16_C(12461),
      UINT16_C( 6163),
      UINT16_C(19408),
      UINT16_C(61941),
      UINT16_C( 8540),
      UINT16_C(13400),
      UINT16_C(  558),
      UINT16_C( 7654),
      UINT16_C(14639),
      UINT16_C(11411),
      UINT16_C(23345),
      }
    },
    { { UINT16_C(41119), UINT16_C(37968), UINT16_C(13969), UINT16_C(22193) },
      { UINT16_C(24251), UINT16_C( 6022), UINT16_C(46720), UINT16_C(45392) },
      { UINT16_C(25448), UINT16_C(49609), UINT16_C(23960), UINT16_C(58861) },
      { UINT16_C(48471), UINT16_C(34096), UINT16_C(25023), UINT16_C(24289) },
      {
      UINT16_C(41119),
      UINT16_C(24251),
      UINT16_C(25448),
      UINT16_C(48471),
      UINT16_C(37968),
      UINT16_C( 6022),
      UINT16_C(49609),
      UINT16_C(34096),
      UINT16_C(13969),
      UINT16_C(46720),
      UINT16_C(23960),
      UINT16_C(25023),
      UINT16_C(22193),
      UINT16_C(45392),
      UINT16_C(58861),
      UINT16_C(24289),
      }
    },
    { { UINT16_C(12546), UINT16_C(37874), UINT16_C(41831), UINT16_C( 8937) },
      { UINT16_C(28674), UINT16_C(33338), UINT16_C(35366), UINT16_C(36403) },
      { UINT16_C(65006), UINT16_C(34383), UINT16_C(15450), UINT16_C(45419) },
      { UINT16_C(39929), UINT16_C(47414), UINT16_C( 6141), UINT16_C(65303) },
      {
      UINT16_C(12546),
      UINT16_C(28674),
      UINT16_C(65006),
      UINT16_C(39929),
      UINT16_C(37874),
      UINT16_C(33338),
      UINT16_C(34383),
      UINT16_C(47414),
      UINT16_C(41831),
      UINT16_C(35366),
      UINT16_C(15450),
      UINT16_C( 6141),
      UINT16_C( 8937),
      UINT16_C(36403),
      UINT16_C(45419),
      UINT16_C(65303),
      }
    },
    { { UINT16_C( 2632), UINT16_C(45202), UINT16_C(31917), UINT16_C(45010) },
      { UINT16_C( 3308), UINT16_C( 4657), UINT16_C(26007), UINT16_C(34208) },
      { UINT16_C(61538), UINT16_C(48139), UINT16_C(30252), UINT16_C( 9837) },
      { UINT16_C(41745), UINT16_C( 3807), UINT16_C(63163), UINT16_C(  781) },
      {
      UINT16_C( 2632),
      UINT16_C( 3308),
      UINT16_C(61538),
      UINT16_C(41745),
      UINT16_C(45202),
      UINT16_C( 4657),
      UINT16_C(48139),
      UINT16_C( 3807),
      UINT16_C(31917),
      UINT16_C(26007),
      UINT16_C(30252),
      UINT16_C(63163),
      UINT16_C(45010),
      UINT16_C(34208),
      UINT16_C( 9837),
      UINT16_C(  781),
      }
    },
    { { UINT16_C(40960), UINT16_C(44723), UINT16_C(34332), UINT16_C( 2141) },
      { UINT16_C(36754), UINT16_C(10522), UINT16_C(47860), UINT16_C(22190) },
      { UINT16_C(47530), UINT16_C(55058), UINT16_C(32559), UINT16_C(16893) },
      { UINT16_C(56354), UINT16_C(56655), UINT16_C(24018), UINT16_C(54241) },
      {
      UINT16_C(40960),
      UINT16_C(36754),
      UINT16_C(47530),
      UINT16_C(56354),
      UINT16_C(44723),
      UINT16_C(10522),
      UINT16_C(55058),
      UINT16_C(56655),
      UINT16_C(34332),
      UINT16_C(47860),
      UINT16_C(32559),
      UINT16_C(24018),
      UINT16_C( 2141),
      UINT16_C(22190),
      UINT16_C(16893),
      UINT16_C(54241),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x4_t r_ = { { simde_vld1_u16(test_vec[i].r0),
                                simde_vld1_u16(test_vec[i].r1),
                                simde_vld1_u16(test_vec[i].r2),
                                simde_vld1_u16(test_vec[i].r3), } };

    uint16_t a_[16];
    simde_vst4_u16(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4_u16(a_);
    simde_test_arm_neon_assert_equal_u16x4(r_.val[0], simde_vld1_u16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u16x4(r_.val[1], simde_vld1_u16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u16x4(r_.val[2], simde_vld1_u16(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (size_t i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a0 = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t a1 = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t a2 = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t a3 = simde_test_arm_neon_random_u16x4();
    simde_uint16x4x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_u16x4(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    uint16_t buf[16];
    simde_vst4_u16(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_u16(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r0[2];
    uint32_t r1[2];
    uint32_t r2[2];
    uint32_t r3[2];
    uint32_t a[8];
  } test_vec[] = {
    { { UINT32_C( 160598487), UINT32_C(3431268484) },
      { UINT32_C( 277942869), UINT32_C(3957648286) },
      { UINT32_C(3792231046), UINT32_C(2849176706) },
      { UINT32_C(4241723360), UINT32_C(2166330026) },
      {
      UINT32_C( 160598487),
      UINT32_C( 277942869),
      UINT32_C(3792231046),
      UINT32_C(4241723360),
      UINT32_C(3431268484),
      UINT32_C(3957648286),
      UINT32_C(2849176706),
      UINT32_C(2166330026),
      }
    },
    { { UINT32_C(2676666651), UINT32_C( 124456881) },
      { UINT32_C(3222797601), UINT32_C(1856765160) },
      { UINT32_C(1481683926), UINT32_C(2399216303) },
      { UINT32_C(1535956145), UINT32_C(2178788198) },
      {
      UINT32_C(2676666651),
      UINT32_C(3222797601),
      UINT32_C(1481683926),
      UINT32_C(1535956145),
      UINT32_C( 124456881),
      UINT32_C(1856765160),
      UINT32_C(2399216303),
      UINT32_C(2178788198),
      }
    },
    { { UINT32_C( 237004636), UINT32_C(2551548791) },
      { UINT32_C(1884826760), UINT32_C(4275962920) },
      { UINT32_C(1733701303), UINT32_C(  49698640) },
      { UINT32_C(2438824491), UINT32_C(2316450349) },
      {
      UINT32_C( 237004636),
      UINT32_C(1884826760),
      UINT32_C(1733701303),
      UINT32_C(2438824491),
      UINT32_C(2551548791),
      UINT32_C(4275962920),
      UINT32_C(  49698640),
      UINT32_C(2316450349),
      }
    },
    { { UINT32_C( 429404834), UINT32_C(1186049470) },
      { UINT32_C(  45550297), UINT32_C(3305149710) },
      { UINT32_C( 338450372), UINT32_C(3658884014) },
      { UINT32_C(3547034789), UINT32_C(1348304558) },
      {
      UINT32_C( 429404834),
      UINT32_C(  45550297),
      UINT32_C( 338450372),
      UINT32_C(3547034789),
      UINT32_C(1186049470),
      UINT32_C(3305149710),
      UINT32_C(3658884014),
      UINT32_C(1348304558),
      }
    },
    { { UINT32_C(1852437936), UINT32_C(2075466658) },
      { UINT32_C( 863857701), UINT32_C(3321396737) },
      { UINT32_C(2212111829), UINT32_C(3982356552) },
      { UINT32_C( 331401572), UINT32_C(4150467911) },
      {
      UINT32_C(1852437936),
      UINT32_C( 863857701),
      UINT32_C(2212111829),
      UINT32_C( 331401572),
      UINT32_C(2075466658),
      UINT32_C(3321396737),
      UINT32_C(3982356552),
      UINT32_C(4150467911),
      }
    },
    { { UINT32_C(3026636050), UINT32_C( 221256680) },
      { UINT32_C(2285940103), UINT32_C(   5126187) },
      { UINT32_C(2776901725), UINT32_C(2106843416) },
      { UINT32_C(4052767658), UINT32_C(2213147505) },
      {
      UINT32_C(3026636050),
      UINT32_C(2285940103),
      UINT32_C(2776901725),
      UINT32_C(4052767658),
      UINT32_C( 221256680),
      UINT32_C(   5126187),
      UINT32_C(2106843416),
      UINT32_C(2213147505),
      }
    },
    { { UINT32_C(2822262720), UINT32_C(4055197802) },
      { UINT32_C(1098511637), UINT32_C(2336343854) },
      { UINT32_C( 137479663), UINT32_C(1367721127) },
      { UINT32_C(2286097687), UINT32_C(3373018120) },
      {
      UINT32_C(2822262720),
      UINT32_C(1098511637),
      UINT32_C( 137479663),
      UINT32_C(2286097687),
      UINT32_C(4055197802),
      UINT32_C(2336343854),
      UINT32_C(1367721127),
      UINT32_C(3373018120),
      }
    },
    { { UINT32_C(3849405563), UINT32_C(3252037548) },
      { UINT32_C(1241665308), UINT32_C( 114705431) },
      { UINT32_C(2953709321), UINT32_C(3791819723) },
      { UINT32_C(2976597416), UINT32_C(3967448945) },
      {
      UINT32_C(3849405563),
      UINT32_C(1241665308),
      UINT32_C(2953709321),
      UINT32_C(2976597416),
      UINT32_C(3252037548),
      UINT32_C( 114705431),
      UINT32_C(3791819723),
      UINT32_C(3967448945),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x4_t r_ = { { simde_vld1_u32(test_vec[i].r0),
                                simde_vld1_u32(test_vec[i].r1),
                                simde_vld1_u32(test_vec[i].r2),
                                simde_vld1_u32(test_vec[i].r3), } };

    uint32_t a_[8];
    simde_vst4_u32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4_u32(a_);
    simde_test_arm_neon_assert_equal_u32x2(r_.val[0], simde_vld1_u32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u32x2(r_.val[1], simde_vld1_u32(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u32x2(r_.val[2], simde_vld1_u32(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (size_t i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a0 = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t a1 = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t a2 = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t a3 = simde_test_arm_neon_random_u32x2();
    simde_uint32x2x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_u32x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    uint32_t buf[8];
    simde_vst4_u32(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_u32(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r0[1];
    uint64_t r1[1];
    uint64_t r2[1];
    uint64_t r3[1];
    uint64_t a[4];
  } test_vec[] = {
    { { UINT64_C( 5721188545113066611) },
      { UINT64_C(14561941195432479727) },
      { UINT64_C(18383632674776778752) },
      { UINT64_C(15980372823853894486) },
      {
      UINT64_C( 5721188545113066611),
      UINT64_C(14561941195432479727),
      UINT64_C(18383632674776778752),
      UINT64_C(15980372823853894486),
      }
    },
    { { UINT64_C(17453329832926135356) },
      { UINT64_C( 9305115780059437306) },
      { UINT64_C(10769792532928690161) },
      { UINT64_C( 9174047135429923592) },
      {
      UINT64_C(17453329832926135356),
      UINT64_C( 9305115780059437306),
      UINT64_C(10769792532928690161),
      UINT64_C( 9174047135429923592),
      }
    },
    { { UINT64_C( 4971021025742920199) },
      { UINT64_C(12229453011547344821) },
      { UINT64_C(11171622612186862901) },
      { UINT64_C(15125726142156113446) },
      {
      UINT64_C( 4971021025742920199),
      UINT64_C(12229453011547344821),
      UINT64_C(11171622612186862901),
      UINT64_C(15125726142156113446),
      }
    },
    { { UINT64_C(11783624364083859705) },
      { UINT64_C( 1623425490471166758) },
      { UINT64_C( 6869277207765361957) },
      { UINT64_C(13489603327554052761) },
      {
      UINT64_C(11783624364083859705),
      UINT64_C( 1623425490471166758),
      UINT64_C( 6869277207765361957),
      UINT64_C(13489603327554052761),
      }
    },
    { { UINT64_C(  905933701970267906) },
      { UINT64_C( 2422780449713187752) },
      { UINT64_C( 6174203900964972822) },
      { UINT64_C( 3174171503893182608) },
      {
      UINT64_C(  905933701970267906),
      UINT64_C( 2422780449713187752),
      UINT64_C( 6174203900964972822),
      UINT64_C( 3174171503893182608),
      }
    },
    { { UINT64_C( 4030069174546664187) },
      { UINT64_C( 6860775845552772889) },
      { UINT64_C(14815256441915314056) },
      { UINT64_C( 4191491432061489877) },
      {
      UINT64_C( 4030069174546664187),
      UINT64_C( 6860775845552772889),
      UINT64_C(14815256441915314056),
      UINT64_C( 4191491432061489877),
      }
    },
    { { UINT64_C( 1079748961840678709) },
      { UINT64_C(11927881590574923233) },
      { UINT64_C( 7670619264820787049) },
      { UINT64_C(17460338915384332758) },
      {
      UINT64_C( 1079748961840678709),
      UINT64_C(11927881590574923233),
      UINT64_C( 7670619264820787049),
      UINT64_C(17460338915384332758),
      }
    },
    { { UINT64_C( 6259919325679283164) },
      { UINT64_C(14209428967911261040) },
      { UINT64_C( 8448153254045096767) },
      { UINT64_C( 1738065358680139632) },
      {
      UINT64_C( 6259919325679283164),
      UINT64_C(14209428967911261040),
      UINT64_C( 8448153254045096767),
      UINT64_C( 1738065358680139632),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x4_t r_ = { { simde_vld1_u64(test_vec[i].r0),
                                simde_vld1_u64(test_vec[i].r1),
                                simde_vld1_u64(test_vec[i].r2),
                                simde_vld1_u64(test_vec[i].r3), } };

    uint64_t a_[4];
    simde_vst4_u64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4_u64(a_);
    simde_test_arm_neon_assert_equal_u64x1(r_.val[0], simde_vld1_u64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u64x1(r_.val[1], simde_vld1_u64(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u64x1(r_.val[2], simde_vld1_u64(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (size_t i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a0 = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t a1 = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t a2 = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t a3 = simde_test_arm_neon_random_u64x1();
    simde_uint64x1x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_u64x1(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    uint64_t buf[4];
    simde_vst4_u64(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_u64(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4q_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r0[4];
    simde_float32 r1[4];
    simde_float32 r2[4];
    simde_float32 r3[4];
    simde_float32 a[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -988.70), SIMDE_FLOAT32_C(   709.53), SIMDE_FLOAT32_C(  -895.28), SIMDE_FLOAT32_C(  -307.54) },
      { SIMDE_FLOAT32_C(  -137.31), SIMDE_FLOAT32_C(   947.38), SIMDE_FLOAT32_C(   965.29), SIMDE_FLOAT32_C(  -533.59) },
      { SIMDE_FLOAT32_C(  -896.71), SIMDE_FLOAT32_C(   365.46), SIMDE_FLOAT32_C(  -161.98), SIMDE_FLOAT32_C(   -31.53) },
      { SIMDE_FLOAT32_C(  -334.29), SIMDE_FLOAT32_C(  -613.71), SIMDE_FLOAT32_C(   414.87), SIMDE_FLOAT32_C(  -872.42) },
      {
      SIMDE_FLOAT32_C(  -988.70),
      SIMDE_FLOAT32_C(  -137.31),
      SIMDE_FLOAT32_C(  -896.71),
      SIMDE_FLOAT32_C(  -334.29),
      SIMDE_FLOAT32_C(   709.53),
      SIMDE_FLOAT32_C(   947.38),
      SIMDE_FLOAT32_C(   365.46),
      SIMDE_FLOAT32_C(  -613.71),
      SIMDE_FLOAT32_C(  -895.28),
      SIMDE_FLOAT32_C(   965.29),
      SIMDE_FLOAT32_C(  -161.98),
      SIMDE_FLOAT32_C(   414.87),
      SIMDE_FLOAT32_C(  -307.54),
      SIMDE_FLOAT32_C(  -533.59),
      SIMDE_FLOAT32_C(   -31.53),
      SIMDE_FLOAT32_C(  -872.42),
      }
    },
    { { SIMDE_FLOAT32_C(  -175.89), SIMDE_FLOAT32_C(   -87.40), SIMDE_FLOAT32_C(  -428.46), SIMDE_FLOAT32_C(  -598.83) },
      { SIMDE_FLOAT32_C(  -917.69), SIMDE_FLOAT32_C(  -293.34), SIMDE_FLOAT32_C(   593.88), SIMDE_FLOAT32_C(  -196.10) },
      { SIMDE_FLOAT32_C(   921.26), SIMDE_FLOAT32_C(   218.55), SIMDE_FLOAT32_C(  -799.38), SIMDE_FLOAT32_C(  -616.04) },
      { SIMDE_FLOAT32_C(   227.38), SIMDE_FLOAT32_C(   356.05), SIMDE_FLOAT32_C(   155.96), SIMDE_FLOAT32_C(   238.69) },
      {
      SIMDE_FLOAT32_C(  -175.89),
      SIMDE_FLOAT32_C(  -917.69),
      SIMDE_FLOAT32_C(   921.26),
      SIMDE_FLOAT32_C(   227.38),
      SIMDE_FLOAT32_C(   -87.40),
      SIMDE_FLOAT32_C(  -293.34),
      SIMDE_FLOAT32_C(   218.55),
      SIMDE_FLOAT32_C(   356.05),
      SIMDE_FLOAT32_C(  -428.46),
      SIMDE_FLOAT32_C(   593.88),
      SIMDE_FLOAT32_C(  -799.38),
      SIMDE_FLOAT32_C(   155.96),
      SIMDE_FLOAT32_C(  -598.83),
      SIMDE_FLOAT32_C(  -196.10),
      SIMDE_FLOAT32_C(  -616.04),
      SIMDE_FLOAT32_C(   238.69),
      }
    },
    { { SIMDE_FLOAT32_C(    65.58), SIMDE_FLOAT32_C(   260.68), SIMDE_FLOAT32_C(   931.15), SIMDE_FLOAT32_C(   928.27) },
      { SIMDE_FLOAT32_C(   208.06), SIMDE_FLOAT32_C(   896.44), SIMDE_FLOAT32_C(  -605.32), SIMDE_FLOAT32_C(   311.35) },
      { SIMDE_FLOAT32_C(   261.91), SIMDE_FLOAT32_C(   232.70), SIMDE_FLOAT32_C(  -720.18), SIMDE_FLOAT32_C(   927.62) },
      { SIMDE_FLOAT32_C(   618.99), SIMDE_FLOAT32_C(   694.69), SIMDE_FLOAT32_C(  -944.80), SIMDE_FLOAT32_C(  -556.90) },
      {
      SIMDE_FLOAT32_C(    65.58),
      SIMDE_FLOAT32_C(   208.06),
      SIMDE_FLOAT32_C(   261.91),
      SIMDE_FLOAT32_C(   618.99),
      SIMDE_FLOAT32_C(   260.68),
      SIMDE_FLOAT32_C(   896.44),
      SIMDE_FLOAT32_C(   232.70),
      SIMDE_FLOAT32_C(   694.69),
      SIMDE_FLOAT32_C(   931.15),
      SIMDE_FLOAT32_C(  -605.32),
      SIMDE_FLOAT32_C(  -720.18),
      SIMDE_FLOAT32_C(  -944.80),
      SIMDE_FLOAT32_C(   928.27),
      SIMDE_FLOAT32_C(   311.35),
      SIMDE_FLOAT32_C(   927.62),
      SIMDE_FLOAT32_C(  -556.90),
      }
    },
    { { SIMDE_FLOAT32_C(  -392.71), SIMDE_FLOAT32_C(  -373.26), SIMDE_FLOAT32_C(  -155.73), SIMDE_FLOAT32_C(  -310.40) },
      { SIMDE_FLOAT32_C(   333.40), SIMDE_FLOAT32_C(  -561.84), SIMDE_FLOAT32_C(   493.50), SIMDE_FLOAT32_C(   254.66) },
      { SIMDE_FLOAT32_C(   656.70), SIMDE_FLOAT32_C(   694.12), SIMDE_FLOAT32_C(   638.62), SIMDE_FLOAT32_C(  -115.91) },
      { SIMDE_FLOAT32_C(    50.17), SIMDE_FLOAT32_C(  -205.42), SIMDE_FLOAT32_C(  -877.23), SIMDE_FLOAT32_C(  -884.25) },
      {
      SIMDE_FLOAT32_C(  -392.71),
      SIMDE_FLOAT32_C(   333.40),
      SIMDE_FLOAT32_C(   656.70),
      SIMDE_FLOAT32_C(    50.17),
      SIMDE_FLOAT32_C(  -373.26),
      SIMDE_FLOAT32_C(  -561.84),
      SIMDE_FLOAT32_C(   694.12),
      SIMDE_FLOAT32_C(  -205.42),
      SIMDE_FLOAT32_C(  -155.73),
      SIMDE_FLOAT32_C(   493.50),
      SIMDE_FLOAT32_C(   638.62),
      SIMDE_FLOAT32_C(  -877.23),
      SIMDE_FLOAT32_C(  -310.40),
      SIMDE_FLOAT32_C(   254.66),
      SIMDE_FLOAT32_C(  -115.91),
      SIMDE_FLOAT32_C(  -884.25),
      }
    },
    { { SIMDE_FLOAT32_C(  -944.74), SIMDE_FLOAT32_C(  -946.08), SIMDE_FLOAT32_C(  -955.97), SIMDE_FLOAT32_C(   263.32) },
      { SIMDE_FLOAT32_C(   950.37), SIMDE_FLOAT32_C(  -561.29), SIMDE_FLOAT32_C(  -425.33), SIMDE_FLOAT32_C(   212.28) },
      { SIMDE_FLOAT32_C(   671.41), SIMDE_FLOAT32_C(  -145.51), SIMDE_FLOAT32_C(   139.89), SIMDE_FLOAT32_C(   290.40) },
      { SIMDE_FLOAT32_C(  -450.81), SIMDE_FLOAT32_C(   195.09), SIMDE_FLOAT32_C(   733.51), SIMDE_FLOAT32_C(   156.48) },
      {
      SIMDE_FLOAT32_C(  -944.74),
      SIMDE_FLOAT32_C(   950.37),
      SIMDE_FLOAT32_C(   671.41),
      SIMDE_FLOAT32_C(  -450.81),
      SIMDE_FLOAT32_C(  -946.08),
      SIMDE_FLOAT32_C(  -561.29),
      SIMDE_FLOAT32_C(  -145.51),
      SIMDE_FLOAT32_C(   195.09),
      SIMDE_FLOAT32_C(  -955.97),
      SIMDE_FLOAT32_C(  -425.33),
      SIMDE_FLOAT32_C(   139.89),
      SIMDE_FLOAT32_C(   733.51),
      SIMDE_FLOAT32_C(   263.32),
      SIMDE_FLOAT32_C(   212.28),
      SIMDE_FLOAT32_C(   290.40),
      SIMDE_FLOAT32_C(   156.48),
      }
    },
    { { SIMDE_FLOAT32_C(   821.83), SIMDE_FLOAT32_C(  -422.22), SIMDE_FLOAT32_C(   846.08), SIMDE_FLOAT32_C(   155.24) },
      { SIMDE_FLOAT32_C(    15.94), SIMDE_FLOAT32_C(   339.58), SIMDE_FLOAT32_C(  -590.10), SIMDE_FLOAT32_C(  -327.36) },
      { SIMDE_FLOAT32_C(    33.70), SIMDE_FLOAT32_C(  -951.48), SIMDE_FLOAT32_C(   556.72), SIMDE_FLOAT32_C(  -916.13) },
      { SIMDE_FLOAT32_C(  -156.90), SIMDE_FLOAT32_C(   679.50), SIMDE_FLOAT32_C(  -800.38), SIMDE_FLOAT32_C(  -101.64) },
      {
      SIMDE_FLOAT32_C(   821.83),
      SIMDE_FLOAT32_C(    15.94),
      SIMDE_FLOAT32_C(    33.70),
      SIMDE_FLOAT32_C(  -156.90),
      SIMDE_FLOAT32_C(  -422.22),
      SIMDE_FLOAT32_C(   339.58),
      SIMDE_FLOAT32_C(  -951.48),
      SIMDE_FLOAT32_C(   679.50),
      SIMDE_FLOAT32_C(   846.08),
      SIMDE_FLOAT32_C(  -590.10),
      SIMDE_FLOAT32_C(   556.72),
      SIMDE_FLOAT32_C(  -800.38),
      SIMDE_FLOAT32_C(   155.24),
      SIMDE_FLOAT32_C(  -327.36),
      SIMDE_FLOAT32_C(  -916.13),
      SIMDE_FLOAT32_C(  -101.64),
      }
    },
    { { SIMDE_FLOAT32_C(   733.42), SIMDE_FLOAT32_C(  -756.36), SIMDE_FLOAT32_C(  -838.32), SIMDE_FLOAT32_C(   683.79) },
      { SIMDE_FLOAT32_C(  -317.65), SIMDE_FLOAT32_C(  -263.65), SIMDE_FLOAT32_C(  -103.93), SIMDE_FLOAT32_C(  -646.24) },
      { SIMDE_FLOAT32_C(   590.85), SIMDE_FLOAT32_C(  -964.04), SIMDE_FLOAT32_C(   644.16), SIMDE_FLOAT32_C(  -859.96) },
      { SIMDE_FLOAT32_C(   231.05), SIMDE_FLOAT32_C(   377.67), SIMDE_FLOAT32_C(   296.52), SIMDE_FLOAT32_C(    52.89) },
      {
      SIMDE_FLOAT32_C(   733.42),
      SIMDE_FLOAT32_C(  -317.65),
      SIMDE_FLOAT32_C(   590.85),
      SIMDE_FLOAT32_C(   231.05),
      SIMDE_FLOAT32_C(  -756.36),
      SIMDE_FLOAT32_C(  -263.65),
      SIMDE_FLOAT32_C(  -964.04),
      SIMDE_FLOAT32_C(   377.67),
      SIMDE_FLOAT32_C(  -838.32),
      SIMDE_FLOAT32_C(  -103.93),
      SIMDE_FLOAT32_C(   644.16),
      SIMDE_FLOAT32_C(   296.52),
      SIMDE_FLOAT32_C(   683.79),
      SIMDE_FLOAT32_C(  -646.24),
      SIMDE_FLOAT32_C(  -859.96),
      SIMDE_FLOAT32_C(    52.89),
      }
    },
    { { SIMDE_FLOAT32_C(   955.45), SIMDE_FLOAT32_C(   142.60), SIMDE_FLOAT32_C(  -791.88), SIMDE_FLOAT32_C(   -28.62) },
      { SIMDE_FLOAT32_C(  -517.82), SIMDE_FLOAT32_C(  -381.98), SIMDE_FLOAT32_C(   644.02), SIMDE_FLOAT32_C(   515.88) },
      { SIMDE_FLOAT32_C(  -333.46), SIMDE_FLOAT32_C(   200.74), SIMDE_FLOAT32_C(   599.74), SIMDE_FLOAT32_C(   509.64) },
      { SIMDE_FLOAT32_C(  -119.76), SIMDE_FLOAT32_C(   799.36), SIMDE_FLOAT32_C(  -592.00), SIMDE_FLOAT32_C(  -386.34) },
      {
      SIMDE_FLOAT32_C(   955.45),
      SIMDE_FLOAT32_C(  -517.82),
      SIMDE_FLOAT32_C(  -333.46),
      SIMDE_FLOAT32_C(  -119.76),
      SIMDE_FLOAT32_C(   142.60),
      SIMDE_FLOAT32_C(  -381.98),
      SIMDE_FLOAT32_C(   200.74),
      SIMDE_FLOAT32_C(   799.36),
      SIMDE_FLOAT32_C(  -791.88),
      SIMDE_FLOAT32_C(   644.02),
      SIMDE_FLOAT32_C(   599.74),
      SIMDE_FLOAT32_C(  -592.00),
      SIMDE_FLOAT32_C(   -28.62),
      SIMDE_FLOAT32_C(   515.88),
      SIMDE_FLOAT32_C(   509.64),
      SIMDE_FLOAT32_C(  -386.34),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x4_t r_ = { { simde_vld1q_f32(test_vec[i].r0),
                                 simde_vld1q_f32(test_vec[i].r1),
                                 simde_vld1q_f32(test_vec[i].r2),
                                 simde_vld1q_f32(test_vec[i].r3), } };

    simde_float32 a_[16];
    simde_vst4q_f32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4q_f32(a_);
    simde_test_arm_neon_assert_equal_f32x4(r_.val[0], simde_vld1q_f32(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f32x4(r_.val[1], simde_vld1q_f32(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f32x4(r_.val[2], simde_vld1q_f32(test_vec[i].r2), 1);
    simde_test_arm_neon_assert_equal_f32x4(r_.val[3], simde_vld1q_f32(test_vec[i].r3), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a0 = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t a1 = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t a2 = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t a3 = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_f32x4(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float32_t buf[16];
    simde_vst4q_f32(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_f32(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4q_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r0[2];
    simde_float64 r1[2];
    simde_float64 r2[2];
    simde_float64 r3[2];
    simde_float64 a[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -818.28), SIMDE_FLOAT64_C(   -30.31) },
      { SIMDE_FLOAT64_C(   709.73), SIMDE_FLOAT64_C(  -485.43) },
      { SIMDE_FLOAT64_C(   859.77), SIMDE_FLOAT64_C(  -908.87) },
      { SIMDE_FLOAT64_C(   467.51), SIMDE_FLOAT64_C(   159.39) },
      {
      SIMDE_FLOAT64_C(  -818.28),
      SIMDE_FLOAT64_C(   709.73),
      SIMDE_FLOAT64_C(   859.77),
      SIMDE_FLOAT64_C(   467.51),
      SIMDE_FLOAT64_C(   -30.31),
      SIMDE_FLOAT64_C(  -485.43),
      SIMDE_FLOAT64_C(  -908.87),
      SIMDE_FLOAT64_C(   159.39),
      }
    },
    { { SIMDE_FLOAT64_C(  -267.86), SIMDE_FLOAT64_C(  -945.08) },
      { SIMDE_FLOAT64_C(   703.56), SIMDE_FLOAT64_C(  -499.98) },
      { SIMDE_FLOAT64_C(   229.30), SIMDE_FLOAT64_C(  -572.30) },
      { SIMDE_FLOAT64_C(   838.48), SIMDE_FLOAT64_C(  -276.60) },
      {
      SIMDE_FLOAT64_C(  -267.86),
      SIMDE_FLOAT64_C(   703.56),
      SIMDE_FLOAT64_C(   229.30),
      SIMDE_FLOAT64_C(   838.48),
      SIMDE_FLOAT64_C(  -945.08),
      SIMDE_FLOAT64_C(  -499.98),
      SIMDE_FLOAT64_C(  -572.30),
      SIMDE_FLOAT64_C(  -276.60),
      }
    },
    { { SIMDE_FLOAT64_C(   417.49), SIMDE_FLOAT64_C(   -54.87) },
      { SIMDE_FLOAT64_C(    57.43), SIMDE_FLOAT64_C(   286.91) },
      { SIMDE_FLOAT64_C(  -186.44), SIMDE_FLOAT64_C(   308.53) },
      { SIMDE_FLOAT64_C(   898.55), SIMDE_FLOAT64_C(  -632.39) },
      {
      SIMDE_FLOAT64_C(   417.49),
      SIMDE_FLOAT64_C(    57.43),
      SIMDE_FLOAT64_C(  -186.44),
      SIMDE_FLOAT64_C(   898.55),
      SIMDE_FLOAT64_C(   -54.87),
      SIMDE_FLOAT64_C(   286.91),
      SIMDE_FLOAT64_C(   308.53),
      SIMDE_FLOAT64_C(  -632.39),
      }
    },
    { { SIMDE_FLOAT64_C(   104.89), SIMDE_FLOAT64_C(  -475.34) },
      { SIMDE_FLOAT64_C(   -11.27), SIMDE_FLOAT64_C(   402.75) },
      { SIMDE_FLOAT64_C(  -840.97), SIMDE_FLOAT64_C(  -286.94) },
      { SIMDE_FLOAT64_C(  -305.37), SIMDE_FLOAT64_C(  -659.25) },
      {
      SIMDE_FLOAT64_C(   104.89),
      SIMDE_FLOAT64_C(   -11.27),
      SIMDE_FLOAT64_C(  -840.97),
      SIMDE_FLOAT64_C(  -305.37),
      SIMDE_FLOAT64_C(  -475.34),
      SIMDE_FLOAT64_C(   402.75),
      SIMDE_FLOAT64_C(  -286.94),
      SIMDE_FLOAT64_C(  -659.25),
      }
    },
    { { SIMDE_FLOAT64_C(   682.75), SIMDE_FLOAT64_C(  -595.64) },
      { SIMDE_FLOAT64_C(  -144.67), SIMDE_FLOAT64_C(   542.52) },
      { SIMDE_FLOAT64_C(  -504.51), SIMDE_FLOAT64_C(  -677.16) },
      { SIMDE_FLOAT64_C(  -298.09), SIMDE_FLOAT64_C(   227.63) },
      {
      SIMDE_FLOAT64_C(   682.75),
      SIMDE_FLOAT64_C(  -144.67),
      SIMDE_FLOAT64_C(  -504.51),
      SIMDE_FLOAT64_C(  -298.09),
      SIMDE_FLOAT64_C(  -595.64),
      SIMDE_FLOAT64_C(   542.52),
      SIMDE_FLOAT64_C(  -677.16),
      SIMDE_FLOAT64_C(   227.63),
      }
    },
    { { SIMDE_FLOAT64_C(  -622.24), SIMDE_FLOAT64_C(  -594.53) },
      { SIMDE_FLOAT64_C(   727.66), SIMDE_FLOAT64_C(   607.06) },
      { SIMDE_FLOAT64_C(  -166.83), SIMDE_FLOAT64_C(   566.14) },
      { SIMDE_FLOAT64_C(  -669.54), SIMDE_FLOAT64_C(  -749.34) },
      {
      SIMDE_FLOAT64_C(  -622.24),
      SIMDE_FLOAT64_C(   727.66),
      SIMDE_FLOAT64_C(  -166.83),
      SIMDE_FLOAT64_C(  -669.54),
      SIMDE_FLOAT64_C(  -594.53),
      SIMDE_FLOAT64_C(   607.06),
      SIMDE_FLOAT64_C(   566.14),
      SIMDE_FLOAT64_C(  -749.34),
      }
    },
    { { SIMDE_FLOAT64_C(  -488.73), SIMDE_FLOAT64_C(   387.89) },
      { SIMDE_FLOAT64_C(   537.58), SIMDE_FLOAT64_C(   324.83) },
      { SIMDE_FLOAT64_C(  -303.58), SIMDE_FLOAT64_C(   436.13) },
      { SIMDE_FLOAT64_C(   692.45), SIMDE_FLOAT64_C(   801.32) },
      {
      SIMDE_FLOAT64_C(  -488.73),
      SIMDE_FLOAT64_C(   537.58),
      SIMDE_FLOAT64_C(  -303.58),
      SIMDE_FLOAT64_C(   692.45),
      SIMDE_FLOAT64_C(   387.89),
      SIMDE_FLOAT64_C(   324.83),
      SIMDE_FLOAT64_C(   436.13),
      SIMDE_FLOAT64_C(   801.32),
      }
    },
    { { SIMDE_FLOAT64_C(   960.79), SIMDE_FLOAT64_C(  -318.82) },
      { SIMDE_FLOAT64_C(   204.07), SIMDE_FLOAT64_C(  -880.18) },
      { SIMDE_FLOAT64_C(   394.24), SIMDE_FLOAT64_C(   898.70) },
      { SIMDE_FLOAT64_C(  -539.42), SIMDE_FLOAT64_C(    76.99) },
      {
      SIMDE_FLOAT64_C(   960.79),
      SIMDE_FLOAT64_C(   204.07),
      SIMDE_FLOAT64_C(   394.24),
      SIMDE_FLOAT64_C(  -539.42),
      SIMDE_FLOAT64_C(  -318.82),
      SIMDE_FLOAT64_C(  -880.18),
      SIMDE_FLOAT64_C(   898.70),
      SIMDE_FLOAT64_C(    76.99),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x4_t r_ = { { simde_vld1q_f64(test_vec[i].r0),
                                 simde_vld1q_f64(test_vec[i].r1),
                                 simde_vld1q_f64(test_vec[i].r2),
                                 simde_vld1q_f64(test_vec[i].r3), } };

    simde_float64_t a_[8];
    simde_vst4q_f64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4q_f64(a_);
    simde_test_arm_neon_assert_equal_f64x2(r_.val[0], simde_vld1q_f64(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f64x2(r_.val[1], simde_vld1q_f64(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f64x2(r_.val[2], simde_vld1q_f64(test_vec[i].r2), 1);
    simde_test_arm_neon_assert_equal_f64x2(r_.val[3], simde_vld1q_f64(test_vec[i].r3), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a0 = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t a1 = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t a2 = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t a3 = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_f64x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float64_t buf[8];
    simde_vst4q_f64(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_f64(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r0[16];
    int8_t r1[16];
    int8_t r2[16];
    int8_t r3[16];
    int8_t a[64];
  } test_vec[] = {
    { { -INT8_C( 104),  INT8_C(  69), -INT8_C(  31),  INT8_C(  55), -INT8_C( 109),  INT8_C(  42), -INT8_C(  54), -INT8_C(  38),
         INT8_C(   7), -INT8_C(  16),  INT8_C(   6), -INT8_C(  40), -INT8_C(  55),  INT8_C( 115),  INT8_C(   4), -INT8_C( 113) },
      { -INT8_C(  64),  INT8_C( 107), -INT8_C(  83),  INT8_C(  34),  INT8_C(  99),  INT8_C(   1), -INT8_C(  67),  INT8_C(  53),
        -INT8_C(  37), -INT8_C(  78), -INT8_C(  45), -INT8_C(  28),  INT8_C( 122),      INT8_MIN, -INT8_C(  26),  INT8_C(  19) },
      { -INT8_C(  59), -INT8_C(  57),  INT8_C(  74),  INT8_C(  89), -INT8_C(  15),  INT8_C(  20),  INT8_C(  51), -INT8_C(   8),
         INT8_C(   5),  INT8_C(  57), -INT8_C(  47), -INT8_C(  50), -INT8_C(  84), -INT8_C(  43),  INT8_C(  93),  INT8_C( 108) },
      {  INT8_C(  64),  INT8_C(  10), -INT8_C( 113), -INT8_C(  93),  INT8_C(  11),  INT8_C(  76), -INT8_C(  39), -INT8_C(  25),
        -INT8_C(   2), -INT8_C(  84), -INT8_C(  53),  INT8_C( 121),  INT8_C(  45), -INT8_C(  79), -INT8_C( 116), -INT8_C(  14) },
      {
      -INT8_C( 104),
      -INT8_C(  64),
      -INT8_C(  59),
       INT8_C(  64),
       INT8_C(  69),
       INT8_C( 107),
      -INT8_C(  57),
       INT8_C(  10),
      -INT8_C(  31),
      -INT8_C(  83),
       INT8_C(  74),
      -INT8_C( 113),
       INT8_C(  55),
       INT8_C(  34),
       INT8_C(  89),
      -INT8_C(  93),
      -INT8_C( 109),
       INT8_C(  99),
      -INT8_C(  15),
       INT8_C(  11),
       INT8_C(  42),
       INT8_C(   1),
       INT8_C(  20),
       INT8_C(  76),
      -INT8_C(  54),
      -INT8_C(  67),
       INT8_C(  51),
      -INT8_C(  39),
      -INT8_C(  38),
       INT8_C(  53),
      -INT8_C(   8),
      -INT8_C(  25),
       INT8_C(   7),
      -INT8_C(  37),
       INT8_C(   5),
      -INT8_C(   2),
      -INT8_C(  16),
      -INT8_C(  78),
       INT8_C(  57),
      -INT8_C(  84),
       INT8_C(   6),
      -INT8_C(  45),
      -INT8_C(  47),
      -INT8_C(  53),
      -INT8_C(  40),
      -INT8_C(  28),
      -INT8_C(  50),
       INT8_C( 121),
      -INT8_C(  55),
       INT8_C( 122),
      -INT8_C(  84),
       INT8_C(  45),
       INT8_C( 115),
           INT8_MIN,
      -INT8_C(  43),
      -INT8_C(  79),
       INT8_C(   4),
      -INT8_C(  26),
       INT8_C(  93),
      -INT8_C( 116),
      -INT8_C( 113),
       INT8_C(  19),
       INT8_C( 108),
      -INT8_C(  14),
      }
    },
    { {  INT8_C( 120), -INT8_C(  42),  INT8_C(  75),  INT8_C( 106), -INT8_C(  21),      INT8_MAX,  INT8_C(  98), -INT8_C(  16),
        -INT8_C(  72),  INT8_C(  51), -INT8_C(  66),  INT8_C( 101),  INT8_C(   8),  INT8_C(  27), -INT8_C(  47),  INT8_C(  72) },
      {  INT8_C(  37),  INT8_C(  96), -INT8_C(  20),  INT8_C(  48), -INT8_C(  83), -INT8_C(  59),  INT8_C(  23), -INT8_C(  85),
         INT8_C( 113), -INT8_C(  30),  INT8_C(  36), -INT8_C(  98), -INT8_C( 109), -INT8_C(  80), -INT8_C( 111),  INT8_C(  12) },
      { -INT8_C( 121), -INT8_C(  36),  INT8_C( 118),  INT8_C( 114),  INT8_C(  91), -INT8_C(  40),  INT8_C(  98),  INT8_C(  20),
         INT8_C(  12),  INT8_C(  32),  INT8_C( 121),  INT8_C(  20),  INT8_C(  59),  INT8_C(  74),  INT8_C(  93),  INT8_C(  96) },
      { -INT8_C(  85),  INT8_C(  73), -INT8_C( 112),  INT8_C(  88),  INT8_C(  14), -INT8_C(  88),  INT8_C(   3),      INT8_MAX,
        -INT8_C( 118),  INT8_C(  40),  INT8_C(  30),  INT8_C(  30), -INT8_C(  40), -INT8_C(  81),  INT8_C(  42),  INT8_C(  95) },
      {
       INT8_C( 120),
       INT8_C(  37),
      -INT8_C( 121),
      -INT8_C(  85),
      -INT8_C(  42),
       INT8_C(  96),
      -INT8_C(  36),
       INT8_C(  73),
       INT8_C(  75),
      -INT8_C(  20),
       INT8_C( 118),
      -INT8_C( 112),
       INT8_C( 106),
       INT8_C(  48),
       INT8_C( 114),
       INT8_C(  88),
      -INT8_C(  21),
      -INT8_C(  83),
       INT8_C(  91),
       INT8_C(  14),
           INT8_MAX,
      -INT8_C(  59),
      -INT8_C(  40),
      -INT8_C(  88),
       INT8_C(  98),
       INT8_C(  23),
       INT8_C(  98),
       INT8_C(   3),
      -INT8_C(  16),
      -INT8_C(  85),
       INT8_C(  20),
           INT8_MAX,
      -INT8_C(  72),
       INT8_C( 113),
       INT8_C(  12),
      -INT8_C( 118),
       INT8_C(  51),
      -INT8_C(  30),
       INT8_C(  32),
       INT8_C(  40),
      -INT8_C(  66),
       INT8_C(  36),
       INT8_C( 121),
       INT8_C(  30),
       INT8_C( 101),
      -INT8_C(  98),
       INT8_C(  20),
       INT8_C(  30),
       INT8_C(   8),
      -INT8_C( 109),
       INT8_C(  59),
      -INT8_C(  40),
       INT8_C(  27),
      -INT8_C(  80),
       INT8_C(  74),
      -INT8_C(  81),
      -INT8_C(  47),
      -INT8_C( 111),
       INT8_C(  93),
       INT8_C(  42),
       INT8_C(  72),
       INT8_C(  12),
       INT8_C(  96),
       INT8_C(  95),
      }
    },
    { { -INT8_C( 117), -INT8_C(  96), -INT8_C(  47), -INT8_C(  25),  INT8_C( 120),  INT8_C(  51), -INT8_C(   5), -INT8_C( 124),
         INT8_C(  83),  INT8_C( 116), -INT8_C( 103), -INT8_C( 114), -INT8_C(  66), -INT8_C(  10), -INT8_C(  18),  INT8_C( 105) },
      {  INT8_C(  63),      INT8_MAX, -INT8_C(  63),  INT8_C(  77),  INT8_C(  39), -INT8_C(  59), -INT8_C(  52), -INT8_C(  79),
        -INT8_C(  19), -INT8_C(  22), -INT8_C(  49), -INT8_C(  59), -INT8_C( 103), -INT8_C(   7),  INT8_C(  37),  INT8_C(  37) },
      { -INT8_C( 103), -INT8_C(  10),  INT8_C(  12),  INT8_C(  18),  INT8_C(  42),  INT8_C(   7), -INT8_C( 106),  INT8_C( 125),
         INT8_C( 123),  INT8_C(  47),  INT8_C(  12),  INT8_C(  57),  INT8_C(  37), -INT8_C(   6), -INT8_C(  93),  INT8_C( 100) },
      {  INT8_C( 121),  INT8_C( 100), -INT8_C(  79), -INT8_C(  96),  INT8_C(  41),  INT8_C( 126),  INT8_C(  82),  INT8_C(  22),
         INT8_C( 104),  INT8_C(  33), -INT8_C(  36),  INT8_C(   2),  INT8_C(  27),  INT8_C(   1),  INT8_C(  39), -INT8_C(  76) },
      {
      -INT8_C( 117),
       INT8_C(  63),
      -INT8_C( 103),
       INT8_C( 121),
      -INT8_C(  96),
           INT8_MAX,
      -INT8_C(  10),
       INT8_C( 100),
      -INT8_C(  47),
      -INT8_C(  63),
       INT8_C(  12),
      -INT8_C(  79),
      -INT8_C(  25),
       INT8_C(  77),
       INT8_C(  18),
      -INT8_C(  96),
       INT8_C( 120),
       INT8_C(  39),
       INT8_C(  42),
       INT8_C(  41),
       INT8_C(  51),
      -INT8_C(  59),
       INT8_C(   7),
       INT8_C( 126),
      -INT8_C(   5),
      -INT8_C(  52),
      -INT8_C( 106),
       INT8_C(  82),
      -INT8_C( 124),
      -INT8_C(  79),
       INT8_C( 125),
       INT8_C(  22),
       INT8_C(  83),
      -INT8_C(  19),
       INT8_C( 123),
       INT8_C( 104),
       INT8_C( 116),
      -INT8_C(  22),
       INT8_C(  47),
       INT8_C(  33),
      -INT8_C( 103),
      -INT8_C(  49),
       INT8_C(  12),
      -INT8_C(  36),
      -INT8_C( 114),
      -INT8_C(  59),
       INT8_C(  57),
       INT8_C(   2),
      -INT8_C(  66),
      -INT8_C( 103),
       INT8_C(  37),
       INT8_C(  27),
      -INT8_C(  10),
      -INT8_C(   7),
      -INT8_C(   6),
       INT8_C(   1),
      -INT8_C(  18),
       INT8_C(  37),
      -INT8_C(  93),
       INT8_C(  39),
       INT8_C( 105),
       INT8_C(  37),
       INT8_C( 100),
      -INT8_C(  76),
      }
    },
    { { -INT8_C(   9),  INT8_C(  51), -INT8_C(  58),  INT8_C(  33),  INT8_C(  58),  INT8_C(  93), -INT8_C(  97), -INT8_C(  75),
        -INT8_C( 116), -INT8_C(  85), -INT8_C(  18), -INT8_C(  78), -INT8_C(  91), -INT8_C( 111),  INT8_C(  22),  INT8_C(  31) },
      { -INT8_C(  10), -INT8_C(  56), -INT8_C(  65),  INT8_C(  31),  INT8_C(  70),  INT8_C(  17),  INT8_C(  54), -INT8_C(  82),
         INT8_C(  51),  INT8_C(  18), -INT8_C(  80),  INT8_C(  78),  INT8_C(  19), -INT8_C(  41),  INT8_C(   2),  INT8_C(  10) },
      {  INT8_C(  10), -INT8_C(  55),  INT8_C(  44),  INT8_C(  68),  INT8_C(  38), -INT8_C(  53), -INT8_C(   7), -INT8_C(  78),
         INT8_C( 118), -INT8_C(  24),  INT8_C( 100),  INT8_C(  27),  INT8_C( 121),  INT8_C( 123),  INT8_C(  58),  INT8_C( 111) },
      {  INT8_C(  67), -INT8_C(   6), -INT8_C( 113), -INT8_C( 119),  INT8_C(  11), -INT8_C(  59),  INT8_C(  55),  INT8_C(  62),
        -INT8_C(  41), -INT8_C(  24), -INT8_C( 116), -INT8_C(  22), -INT8_C(  65), -INT8_C( 113), -INT8_C(  12), -INT8_C(  54) },
      {
      -INT8_C(   9),
      -INT8_C(  10),
       INT8_C(  10),
       INT8_C(  67),
       INT8_C(  51),
      -INT8_C(  56),
      -INT8_C(  55),
      -INT8_C(   6),
      -INT8_C(  58),
      -INT8_C(  65),
       INT8_C(  44),
      -INT8_C( 113),
       INT8_C(  33),
       INT8_C(  31),
       INT8_C(  68),
      -INT8_C( 119),
       INT8_C(  58),
       INT8_C(  70),
       INT8_C(  38),
       INT8_C(  11),
       INT8_C(  93),
       INT8_C(  17),
      -INT8_C(  53),
      -INT8_C(  59),
      -INT8_C(  97),
       INT8_C(  54),
      -INT8_C(   7),
       INT8_C(  55),
      -INT8_C(  75),
      -INT8_C(  82),
      -INT8_C(  78),
       INT8_C(  62),
      -INT8_C( 116),
       INT8_C(  51),
       INT8_C( 118),
      -INT8_C(  41),
      -INT8_C(  85),
       INT8_C(  18),
      -INT8_C(  24),
      -INT8_C(  24),
      -INT8_C(  18),
      -INT8_C(  80),
       INT8_C( 100),
      -INT8_C( 116),
      -INT8_C(  78),
       INT8_C(  78),
       INT8_C(  27),
      -INT8_C(  22),
      -INT8_C(  91),
       INT8_C(  19),
       INT8_C( 121),
      -INT8_C(  65),
      -INT8_C( 111),
      -INT8_C(  41),
       INT8_C( 123),
      -INT8_C( 113),
       INT8_C(  22),
       INT8_C(   2),
       INT8_C(  58),
      -INT8_C(  12),
       INT8_C(  31),
       INT8_C(  10),
       INT8_C( 111),
      -INT8_C(  54),
      }
    },
    { {  INT8_C(  88),  INT8_C(  32),  INT8_C(  14),  INT8_C( 126), -INT8_C(  21),  INT8_C(   8),  INT8_C(  48),  INT8_C(  97),
        -INT8_C(  16), -INT8_C( 107),  INT8_C( 125),  INT8_C( 105),  INT8_C(  16), -INT8_C(  73), -INT8_C(  39),  INT8_C(  83) },
      { -INT8_C(  79),  INT8_C( 104), -INT8_C(  36), -INT8_C(  67),  INT8_C(  45),  INT8_C(  19), -INT8_C(   5),  INT8_C(   4),
        -INT8_C(   5), -INT8_C( 120), -INT8_C(  18), -INT8_C(  69),  INT8_C(  23), -INT8_C(  30), -INT8_C( 123),  INT8_C( 111) },
      {  INT8_C(   3), -INT8_C( 109), -INT8_C(  19), -INT8_C(  18), -INT8_C( 101),  INT8_C(  29),  INT8_C(  80), -INT8_C( 117),
        -INT8_C(  78), -INT8_C(  51), -INT8_C(  11), -INT8_C(  62), -INT8_C( 124), -INT8_C(  50),  INT8_C(  21),  INT8_C(  54) },
      {  INT8_C(  54), -INT8_C(  15), -INT8_C(  13),  INT8_C(  99),  INT8_C(   5), -INT8_C(  18),  INT8_C( 103),  INT8_C(   0),
         INT8_C( 118),  INT8_C(  85), -INT8_C(  69), -INT8_C( 115),  INT8_C(  55),  INT8_C(  64), -INT8_C(   4),  INT8_C(  58) },
      {
       INT8_C(  88),
      -INT8_C(  79),
       INT8_C(   3),
       INT8_C(  54),
       INT8_C(  32),
       INT8_C( 104),
      -INT8_C( 109),
      -INT8_C(  15),
       INT8_C(  14),
      -INT8_C(  36),
      -INT8_C(  19),
      -INT8_C(  13),
       INT8_C( 126),
      -INT8_C(  67),
      -INT8_C(  18),
       INT8_C(  99),
      -INT8_C(  21),
       INT8_C(  45),
      -INT8_C( 101),
       INT8_C(   5),
       INT8_C(   8),
       INT8_C(  19),
       INT8_C(  29),
      -INT8_C(  18),
       INT8_C(  48),
      -INT8_C(   5),
       INT8_C(  80),
       INT8_C( 103),
       INT8_C(  97),
       INT8_C(   4),
      -INT8_C( 117),
       INT8_C(   0),
      -INT8_C(  16),
      -INT8_C(   5),
      -INT8_C(  78),
       INT8_C( 118),
      -INT8_C( 107),
      -INT8_C( 120),
      -INT8_C(  51),
       INT8_C(  85),
       INT8_C( 125),
      -INT8_C(  18),
      -INT8_C(  11),
      -INT8_C(  69),
       INT8_C( 105),
      -INT8_C(  69),
      -INT8_C(  62),
      -INT8_C( 115),
       INT8_C(  16),
       INT8_C(  23),
      -INT8_C( 124),
       INT8_C(  55),
      -INT8_C(  73),
      -INT8_C(  30),
      -INT8_C(  50),
       INT8_C(  64),
      -INT8_C(  39),
      -INT8_C( 123),
       INT8_C(  21),
      -INT8_C(   4),
       INT8_C(  83),
       INT8_C( 111),
       INT8_C(  54),
       INT8_C(  58),
      }
    },
    { { -INT8_C(  44), -INT8_C(  23),  INT8_C(  41),  INT8_C( 111),  INT8_C(   7),  INT8_C( 121), -INT8_C(   5), -INT8_C(  71),
         INT8_C(  70), -INT8_C(  16),  INT8_C( 124), -INT8_C(  54), -INT8_C(  66), -INT8_C( 111),  INT8_C(   0), -INT8_C(  12) },
      { -INT8_C( 125), -INT8_C(  13),  INT8_C(  87), -INT8_C( 120), -INT8_C(  30), -INT8_C(  66), -INT8_C( 120),  INT8_C(  88),
         INT8_C(  19),  INT8_C(  68), -INT8_C(  26),  INT8_C(  74), -INT8_C( 124), -INT8_C(  30), -INT8_C( 123),  INT8_C(  88) },
      { -INT8_C(  52), -INT8_C(  82), -INT8_C(  56), -INT8_C(  45),  INT8_C(  39), -INT8_C(  61), -INT8_C( 116),  INT8_C( 109),
        -INT8_C(  77),  INT8_C(   8),  INT8_C(  55),  INT8_C( 113), -INT8_C( 102),  INT8_C(  56),  INT8_C( 101),  INT8_C(  29) },
      {  INT8_C(  43), -INT8_C(  68), -INT8_C(  91),  INT8_C(  13),  INT8_C( 122),  INT8_C(  45),  INT8_C( 102), -INT8_C( 115),
         INT8_C( 113),  INT8_C(  76), -INT8_C(  41), -INT8_C(  10),  INT8_C(  46),  INT8_C(  92),  INT8_C(  78), -INT8_C(   6) },
      {
      -INT8_C(  44),
      -INT8_C( 125),
      -INT8_C(  52),
       INT8_C(  43),
      -INT8_C(  23),
      -INT8_C(  13),
      -INT8_C(  82),
      -INT8_C(  68),
       INT8_C(  41),
       INT8_C(  87),
      -INT8_C(  56),
      -INT8_C(  91),
       INT8_C( 111),
      -INT8_C( 120),
      -INT8_C(  45),
       INT8_C(  13),
       INT8_C(   7),
      -INT8_C(  30),
       INT8_C(  39),
       INT8_C( 122),
       INT8_C( 121),
      -INT8_C(  66),
      -INT8_C(  61),
       INT8_C(  45),
      -INT8_C(   5),
      -INT8_C( 120),
      -INT8_C( 116),
       INT8_C( 102),
      -INT8_C(  71),
       INT8_C(  88),
       INT8_C( 109),
      -INT8_C( 115),
       INT8_C(  70),
       INT8_C(  19),
      -INT8_C(  77),
       INT8_C( 113),
      -INT8_C(  16),
       INT8_C(  68),
       INT8_C(   8),
       INT8_C(  76),
       INT8_C( 124),
      -INT8_C(  26),
       INT8_C(  55),
      -INT8_C(  41),
      -INT8_C(  54),
       INT8_C(  74),
       INT8_C( 113),
      -INT8_C(  10),
      -INT8_C(  66),
      -INT8_C( 124),
      -INT8_C( 102),
       INT8_C(  46),
      -INT8_C( 111),
      -INT8_C(  30),
       INT8_C(  56),
       INT8_C(  92),
       INT8_C(   0),
      -INT8_C( 123),
       INT8_C( 101),
       INT8_C(  78),
      -INT8_C(  12),
       INT8_C(  88),
       INT8_C(  29),
      -INT8_C(   6),
      }
    },
    { {  INT8_C(  10),  INT8_C(  22), -INT8_C(  51),  INT8_C(  49), -INT8_C(  39),  INT8_C(  90), -INT8_C(  98), -INT8_C( 116),
         INT8_C(  98), -INT8_C(  42), -INT8_C(   3), -INT8_C(   4),  INT8_C(  14),  INT8_C(  98),  INT8_C(  25),  INT8_C(  57) },
      {  INT8_C(  30), -INT8_C(  66),  INT8_C(  71), -INT8_C( 104), -INT8_C(  20), -INT8_C(  83),  INT8_C(  37),  INT8_C(  93),
        -INT8_C(   7), -INT8_C(   3),  INT8_C(  83),  INT8_C(  39),  INT8_C(  89), -INT8_C(  94),  INT8_C(  34),  INT8_C( 100) },
      { -INT8_C(  72), -INT8_C(  17), -INT8_C( 107), -INT8_C( 110),  INT8_C(  73),  INT8_C(  52),  INT8_C(  30), -INT8_C(  84),
         INT8_C(  10),  INT8_C(  28), -INT8_C(  88),  INT8_C(  24),  INT8_C( 126), -INT8_C(  62),  INT8_C(  81), -INT8_C(  99) },
      {      INT8_MIN, -INT8_C( 104),  INT8_C(  53),  INT8_C( 108),  INT8_C(  69),  INT8_C(  91), -INT8_C(  54),  INT8_C(  62),
         INT8_C(  88),  INT8_C(  29),  INT8_C( 102), -INT8_C(  79), -INT8_C(  65), -INT8_C( 120),  INT8_C(  21),  INT8_C( 120) },
      {
       INT8_C(  10),
       INT8_C(  30),
      -INT8_C(  72),
           INT8_MIN,
       INT8_C(  22),
      -INT8_C(  66),
      -INT8_C(  17),
      -INT8_C( 104),
      -INT8_C(  51),
       INT8_C(  71),
      -INT8_C( 107),
       INT8_C(  53),
       INT8_C(  49),
      -INT8_C( 104),
      -INT8_C( 110),
       INT8_C( 108),
      -INT8_C(  39),
      -INT8_C(  20),
       INT8_C(  73),
       INT8_C(  69),
       INT8_C(  90),
      -INT8_C(  83),
       INT8_C(  52),
       INT8_C(  91),
      -INT8_C(  98),
       INT8_C(  37),
       INT8_C(  30),
      -INT8_C(  54),
      -INT8_C( 116),
       INT8_C(  93),
      -INT8_C(  84),
       INT8_C(  62),
       INT8_C(  98),
      -INT8_C(   7),
       INT8_C(  10),
       INT8_C(  88),
      -INT8_C(  42),
      -INT8_C(   3),
       INT8_C(  28),
       INT8_C(  29),
      -INT8_C(   3),
       INT8_C(  83),
      -INT8_C(  88),
       INT8_C( 102),
      -INT8_C(   4),
       INT8_C(  39),
       INT8_C(  24),
      -INT8_C(  79),
       INT8_C(  14),
       INT8_C(  89),
       INT8_C( 126),
      -INT8_C(  65),
       INT8_C(  98),
      -INT8_C(  94),
      -INT8_C(  62),
      -INT8_C( 120),
       INT8_C(  25),
       INT8_C(  34),
       INT8_C(  81),
       INT8_C(  21),
       INT8_C(  57),
       INT8_C( 100),
      -INT8_C(  99),
       INT8_C( 120),
      }
    },
    { {  INT8_C( 119), -INT8_C(  85),  INT8_C(  10), -INT8_C(  63), -INT8_C(  33),  INT8_C(  40),  INT8_C( 109), -INT8_C(  23),
         INT8_C(  68),  INT8_C(  21),  INT8_C(   1), -INT8_C(  61), -INT8_C(  41),  INT8_C(  82),  INT8_C(  96),  INT8_C(  88) },
      { -INT8_C(  21), -INT8_C( 107), -INT8_C(  60),  INT8_C(  48), -INT8_C(  16), -INT8_C( 114),  INT8_C( 111),  INT8_C(  72),
        -INT8_C(  84), -INT8_C(  43), -INT8_C(   6),  INT8_C( 107),  INT8_C(  93),  INT8_C(  15), -INT8_C(  29), -INT8_C(  44) },
      { -INT8_C(  70), -INT8_C(  19), -INT8_C( 107), -INT8_C( 103),  INT8_C(  22),  INT8_C(   2), -INT8_C( 126),  INT8_C(  90),
         INT8_C(  24), -INT8_C( 125),  INT8_C(  29), -INT8_C(  17), -INT8_C(  42),  INT8_C( 125),  INT8_C(  71), -INT8_C(  63) },
      {  INT8_C(  19),  INT8_C(  12), -INT8_C(  15),  INT8_C(   3), -INT8_C( 102),  INT8_C(  96),  INT8_C(  76),  INT8_C(  70),
         INT8_C(  53),  INT8_C(  70), -INT8_C(  78), -INT8_C( 110),  INT8_C(  85), -INT8_C( 107),  INT8_C( 103),  INT8_C(  16) },
      {
       INT8_C( 119),
      -INT8_C(  21),
      -INT8_C(  70),
       INT8_C(  19),
      -INT8_C(  85),
      -INT8_C( 107),
      -INT8_C(  19),
       INT8_C(  12),
       INT8_C(  10),
      -INT8_C(  60),
      -INT8_C( 107),
      -INT8_C(  15),
      -INT8_C(  63),
       INT8_C(  48),
      -INT8_C( 103),
       INT8_C(   3),
      -INT8_C(  33),
      -INT8_C(  16),
       INT8_C(  22),
      -INT8_C( 102),
       INT8_C(  40),
      -INT8_C( 114),
       INT8_C(   2),
       INT8_C(  96),
       INT8_C( 109),
       INT8_C( 111),
      -INT8_C( 126),
       INT8_C(  76),
      -INT8_C(  23),
       INT8_C(  72),
       INT8_C(  90),
       INT8_C(  70),
       INT8_C(  68),
      -INT8_C(  84),
       INT8_C(  24),
       INT8_C(  53),
       INT8_C(  21),
      -INT8_C(  43),
      -INT8_C( 125),
       INT8_C(  70),
       INT8_C(   1),
      -INT8_C(   6),
       INT8_C(  29),
      -INT8_C(  78),
      -INT8_C(  61),
       INT8_C( 107),
      -INT8_C(  17),
      -INT8_C( 110),
      -INT8_C(  41),
       INT8_C(  93),
      -INT8_C(  42),
       INT8_C(  85),
       INT8_C(  82),
       INT8_C(  15),
       INT8_C( 125),
      -INT8_C( 107),
       INT8_C(  96),
      -INT8_C(  29),
       INT8_C(  71),
       INT8_C( 103),
       INT8_C(  88),
      -INT8_C(  44),
      -INT8_C(  63),
       INT8_C(  16),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x4_t r_ = { { simde_vld1q_s8(test_vec[i].r0),
                               simde_vld1q_s8(test_vec[i].r1),
                               simde_vld1q_s8(test_vec[i].r2),
                               simde_vld1q_s8(test_vec[i].r3), } };

    int8_t a_[64];
    simde_vst4q_s8(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4q_s8(a_);
    simde_test_arm_neon_assert_equal_i8x16(r_.val[0], simde_vld1q_s8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i8x16(r_.val[1], simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r_.val[2], simde_vld1q_s8(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a0 = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t a1 = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t a2 = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t a3 = simde_test_arm_neon_random_i8x16();
    simde_int8x16x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_i8x16(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    int8_t buf[64];
    simde_vst4q_s8(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_i8(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r0[8];
    int16_t r1[8];
    int16_t r2[8];
    int16_t r3[8];
    int16_t a[32];
  } test_vec[] = {
    { { -INT16_C(  5888),  INT16_C(   846),  INT16_C( 30499), -INT16_C( 13089),  INT16_C( 15915),  INT16_C( 21143),  INT16_C( 25352), -INT16_C( 16725) },
      { -INT16_C( 30030), -INT16_C( 28847), -INT16_C( 11856), -INT16_C( 11620),  INT16_C( 12783),  INT16_C( 25877),  INT16_C(  2830),  INT16_C(  3662) },
      { -INT16_C( 25356),  INT16_C(  6161), -INT16_C(  4077),  INT16_C( 16100),  INT16_C( 31791),  INT16_C( 14225),  INT16_C( 15583), -INT16_C( 28171) },
      {  INT16_C( 18119),  INT16_C( 30496), -INT16_C( 17385),  INT16_C(  1609),  INT16_C( 24301), -INT16_C(  1172), -INT16_C( 17814),  INT16_C( 24074) },
      {
      -INT16_C(  5888),
      -INT16_C( 30030),
      -INT16_C( 25356),
       INT16_C( 18119),
       INT16_C(   846),
      -INT16_C( 28847),
       INT16_C(  6161),
       INT16_C( 30496),
       INT16_C( 30499),
      -INT16_C( 11856),
      -INT16_C(  4077),
      -INT16_C( 17385),
      -INT16_C( 13089),
      -INT16_C( 11620),
       INT16_C( 16100),
       INT16_C(  1609),
       INT16_C( 15915),
       INT16_C( 12783),
       INT16_C( 31791),
       INT16_C( 24301),
       INT16_C( 21143),
       INT16_C( 25877),
       INT16_C( 14225),
      -INT16_C(  1172),
       INT16_C( 25352),
       INT16_C(  2830),
       INT16_C( 15583),
      -INT16_C( 17814),
      -INT16_C( 16725),
       INT16_C(  3662),
      -INT16_C( 28171),
       INT16_C( 24074),
      }
    },
    { {  INT16_C(  6999),  INT16_C( 27254),  INT16_C( 23308),  INT16_C( 15273),  INT16_C( 15063), -INT16_C( 18830),  INT16_C( 26486),  INT16_C( 15687) },
      {  INT16_C( 26542), -INT16_C( 14924), -INT16_C(   733),  INT16_C(  4300),  INT16_C( 14428), -INT16_C( 14836),  INT16_C(  5874),  INT16_C( 18724) },
      { -INT16_C( 25807),  INT16_C( 15796),  INT16_C( 24054), -INT16_C( 12936), -INT16_C(  5481),  INT16_C(  3459), -INT16_C( 13742),  INT16_C(    75) },
      { -INT16_C(   207),  INT16_C( 21701), -INT16_C( 28163),  INT16_C( 22884),  INT16_C( 28873), -INT16_C( 17377),  INT16_C( 17286), -INT16_C( 18427) },
      {
       INT16_C(  6999),
       INT16_C( 26542),
      -INT16_C( 25807),
      -INT16_C(   207),
       INT16_C( 27254),
      -INT16_C( 14924),
       INT16_C( 15796),
       INT16_C( 21701),
       INT16_C( 23308),
      -INT16_C(   733),
       INT16_C( 24054),
      -INT16_C( 28163),
       INT16_C( 15273),
       INT16_C(  4300),
      -INT16_C( 12936),
       INT16_C( 22884),
       INT16_C( 15063),
       INT16_C( 14428),
      -INT16_C(  5481),
       INT16_C( 28873),
      -INT16_C( 18830),
      -INT16_C( 14836),
       INT16_C(  3459),
      -INT16_C( 17377),
       INT16_C( 26486),
       INT16_C(  5874),
      -INT16_C( 13742),
       INT16_C( 17286),
       INT16_C( 15687),
       INT16_C( 18724),
       INT16_C(    75),
      -INT16_C( 18427),
      }
    },
    { { -INT16_C( 17954), -INT16_C( 11019),  INT16_C( 28182), -INT16_C( 21087),  INT16_C(  9304), -INT16_C( 21829),  INT16_C(  1774),  INT16_C(  8106) },
      {  INT16_C( 28677),  INT16_C(   627), -INT16_C( 10239), -INT16_C( 13477),  INT16_C( 31304), -INT16_C( 12409), -INT16_C( 29506), -INT16_C( 25465) },
      {  INT16_C( 31814),  INT16_C( 23665),  INT16_C(  4842),  INT16_C( 17162), -INT16_C( 15049),  INT16_C(  9709), -INT16_C( 26421), -INT16_C( 12219) },
      { -INT16_C( 18424),  INT16_C(  2515),  INT16_C( 11920), -INT16_C(  9772),  INT16_C( 23465),  INT16_C( 26536),  INT16_C( 12264),  INT16_C( 11779) },
      {
      -INT16_C( 17954),
       INT16_C( 28677),
       INT16_C( 31814),
      -INT16_C( 18424),
      -INT16_C( 11019),
       INT16_C(   627),
       INT16_C( 23665),
       INT16_C(  2515),
       INT16_C( 28182),
      -INT16_C( 10239),
       INT16_C(  4842),
       INT16_C( 11920),
      -INT16_C( 21087),
      -INT16_C( 13477),
       INT16_C( 17162),
      -INT16_C(  9772),
       INT16_C(  9304),
       INT16_C( 31304),
      -INT16_C( 15049),
       INT16_C( 23465),
      -INT16_C( 21829),
      -INT16_C( 12409),
       INT16_C(  9709),
       INT16_C( 26536),
       INT16_C(  1774),
      -INT16_C( 29506),
      -INT16_C( 26421),
       INT16_C( 12264),
       INT16_C(  8106),
      -INT16_C( 25465),
      -INT16_C( 12219),
       INT16_C( 11779),
      }
    },
    { {  INT16_C( 29867), -INT16_C( 26998), -INT16_C( 27513), -INT16_C( 16679), -INT16_C( 14759),  INT16_C(  9443),  INT16_C( 10334),  INT16_C( 26357) },
      { -INT16_C( 14111),  INT16_C( 29040),  INT16_C( 17654), -INT16_C( 24758), -INT16_C(  3424), -INT16_C( 30714),  INT16_C(  2593), -INT16_C( 12874) },
      {  INT16_C( 16510),  INT16_C(  1379),  INT16_C( 15573),  INT16_C( 11971), -INT16_C( 22782),  INT16_C( 24915),  INT16_C( 18639), -INT16_C( 20281) },
      {  INT16_C( 14096),  INT16_C(  1570),  INT16_C( 27772),  INT16_C(  7334), -INT16_C( 21409), -INT16_C( 32604),  INT16_C( 23222),  INT16_C( 13645) },
      {
       INT16_C( 29867),
      -INT16_C( 14111),
       INT16_C( 16510),
       INT16_C( 14096),
      -INT16_C( 26998),
       INT16_C( 29040),
       INT16_C(  1379),
       INT16_C(  1570),
      -INT16_C( 27513),
       INT16_C( 17654),
       INT16_C( 15573),
       INT16_C( 27772),
      -INT16_C( 16679),
      -INT16_C( 24758),
       INT16_C( 11971),
       INT16_C(  7334),
      -INT16_C( 14759),
      -INT16_C(  3424),
      -INT16_C( 22782),
      -INT16_C( 21409),
       INT16_C(  9443),
      -INT16_C( 30714),
       INT16_C( 24915),
      -INT16_C( 32604),
       INT16_C( 10334),
       INT16_C(  2593),
       INT16_C( 18639),
       INT16_C( 23222),
       INT16_C( 26357),
      -INT16_C( 12874),
      -INT16_C( 20281),
       INT16_C( 13645),
      }
    },
    { { -INT16_C( 20326),  INT16_C( 28474), -INT16_C(   276), -INT16_C(  4194), -INT16_C(  3675),  INT16_C( 29776),  INT16_C(  5945),  INT16_C( 18725) },
      {  INT16_C( 18255), -INT16_C( 13489), -INT16_C(  2637),  INT16_C(  4839), -INT16_C( 29790),  INT16_C( 22675), -INT16_C(  7963),  INT16_C( 32653) },
      { -INT16_C( 14191),  INT16_C( 32239), -INT16_C( 29242),  INT16_C( 27500), -INT16_C( 17282), -INT16_C( 18465),  INT16_C(  1236),  INT16_C(  8960) },
      {  INT16_C( 20299), -INT16_C(    18), -INT16_C( 10939), -INT16_C(  6383), -INT16_C( 23456),  INT16_C( 17727), -INT16_C( 12923),  INT16_C(  5828) },
      {
      -INT16_C( 20326),
       INT16_C( 18255),
      -INT16_C( 14191),
       INT16_C( 20299),
       INT16_C( 28474),
      -INT16_C( 13489),
       INT16_C( 32239),
      -INT16_C(    18),
      -INT16_C(   276),
      -INT16_C(  2637),
      -INT16_C( 29242),
      -INT16_C( 10939),
      -INT16_C(  4194),
       INT16_C(  4839),
       INT16_C( 27500),
      -INT16_C(  6383),
      -INT16_C(  3675),
      -INT16_C( 29790),
      -INT16_C( 17282),
      -INT16_C( 23456),
       INT16_C( 29776),
       INT16_C( 22675),
      -INT16_C( 18465),
       INT16_C( 17727),
       INT16_C(  5945),
      -INT16_C(  7963),
       INT16_C(  1236),
      -INT16_C( 12923),
       INT16_C( 18725),
       INT16_C( 32653),
       INT16_C(  8960),
       INT16_C(  5828),
      }
    },
    { { -INT16_C( 19563),  INT16_C( 23443),  INT16_C(    64), -INT16_C( 16698), -INT16_C( 23108), -INT16_C( 28555),  INT16_C( 30122), -INT16_C(  2637) },
      { -INT16_C( 24123),  INT16_C(  2804),  INT16_C(  1654), -INT16_C( 10511),  INT16_C( 12458),  INT16_C( 12059), -INT16_C(  7939), -INT16_C( 28091) },
      { -INT16_C(  9837), -INT16_C( 11027), -INT16_C( 19495), -INT16_C( 27246),  INT16_C(  2137),  INT16_C(   806), -INT16_C(  9859),  INT16_C( 17144) },
      { -INT16_C(  4741), -INT16_C(  3764),  INT16_C( 15859), -INT16_C( 25144), -INT16_C(  7314),  INT16_C( 27597),  INT16_C(  4803),  INT16_C( 22526) },
      {
      -INT16_C( 19563),
      -INT16_C( 24123),
      -INT16_C(  9837),
      -INT16_C(  4741),
       INT16_C( 23443),
       INT16_C(  2804),
      -INT16_C( 11027),
      -INT16_C(  3764),
       INT16_C(    64),
       INT16_C(  1654),
      -INT16_C( 19495),
       INT16_C( 15859),
      -INT16_C( 16698),
      -INT16_C( 10511),
      -INT16_C( 27246),
      -INT16_C( 25144),
      -INT16_C( 23108),
       INT16_C( 12458),
       INT16_C(  2137),
      -INT16_C(  7314),
      -INT16_C( 28555),
       INT16_C( 12059),
       INT16_C(   806),
       INT16_C( 27597),
       INT16_C( 30122),
      -INT16_C(  7939),
      -INT16_C(  9859),
       INT16_C(  4803),
      -INT16_C(  2637),
      -INT16_C( 28091),
       INT16_C( 17144),
       INT16_C( 22526),
      }
    },
    { { -INT16_C(  5141), -INT16_C( 15317), -INT16_C( 16993), -INT16_C(  1958), -INT16_C( 32571),  INT16_C( 17403), -INT16_C(  3239), -INT16_C( 11131) },
      { -INT16_C( 11552), -INT16_C( 11322), -INT16_C( 29169),  INT16_C( 32113),  INT16_C( 15985),  INT16_C( 13801), -INT16_C(  6320),  INT16_C( 15500) },
      { -INT16_C( 18478),  INT16_C( 28928),  INT16_C( 23156),  INT16_C( 14953),  INT16_C( 25818),  INT16_C( 13437),  INT16_C(   600),  INT16_C( 14344) },
      { -INT16_C( 12588), -INT16_C(  7156),  INT16_C( 32092), -INT16_C( 12703),  INT16_C( 19131),  INT16_C(  2819), -INT16_C( 28879),  INT16_C(  1095) },
      {
      -INT16_C(  5141),
      -INT16_C( 11552),
      -INT16_C( 18478),
      -INT16_C( 12588),
      -INT16_C( 15317),
      -INT16_C( 11322),
       INT16_C( 28928),
      -INT16_C(  7156),
      -INT16_C( 16993),
      -INT16_C( 29169),
       INT16_C( 23156),
       INT16_C( 32092),
      -INT16_C(  1958),
       INT16_C( 32113),
       INT16_C( 14953),
      -INT16_C( 12703),
      -INT16_C( 32571),
       INT16_C( 15985),
       INT16_C( 25818),
       INT16_C( 19131),
       INT16_C( 17403),
       INT16_C( 13801),
       INT16_C( 13437),
       INT16_C(  2819),
      -INT16_C(  3239),
      -INT16_C(  6320),
       INT16_C(   600),
      -INT16_C( 28879),
      -INT16_C( 11131),
       INT16_C( 15500),
       INT16_C( 14344),
       INT16_C(  1095),
      }
    },
    { {  INT16_C( 18502), -INT16_C( 17803), -INT16_C(  8286),  INT16_C( 32244),  INT16_C( 28995), -INT16_C( 25679), -INT16_C( 18060),  INT16_C( 18644) },
      { -INT16_C(  8056), -INT16_C(  7124), -INT16_C( 29091),  INT16_C(  6322), -INT16_C( 18984),  INT16_C(  2595),  INT16_C( 27460), -INT16_C( 30194) },
      { -INT16_C( 31821),  INT16_C( 21829),  INT16_C( 14690), -INT16_C( 22830), -INT16_C( 31829),  INT16_C(  8001),  INT16_C(  5437), -INT16_C( 15001) },
      { -INT16_C( 27403),  INT16_C( 21161),  INT16_C( 23586), -INT16_C(  1430), -INT16_C( 29167),  INT16_C( 22020),  INT16_C(  4857), -INT16_C( 21280) },
      {
       INT16_C( 18502),
      -INT16_C(  8056),
      -INT16_C( 31821),
      -INT16_C( 27403),
      -INT16_C( 17803),
      -INT16_C(  7124),
       INT16_C( 21829),
       INT16_C( 21161),
      -INT16_C(  8286),
      -INT16_C( 29091),
       INT16_C( 14690),
       INT16_C( 23586),
       INT16_C( 32244),
       INT16_C(  6322),
      -INT16_C( 22830),
      -INT16_C(  1430),
       INT16_C( 28995),
      -INT16_C( 18984),
      -INT16_C( 31829),
      -INT16_C( 29167),
      -INT16_C( 25679),
       INT16_C(  2595),
       INT16_C(  8001),
       INT16_C( 22020),
      -INT16_C( 18060),
       INT16_C( 27460),
       INT16_C(  5437),
       INT16_C(  4857),
       INT16_C( 18644),
      -INT16_C( 30194),
      -INT16_C( 15001),
      -INT16_C( 21280),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x4_t r_ = { { simde_vld1q_s16(test_vec[i].r0),
                               simde_vld1q_s16(test_vec[i].r1),
                               simde_vld1q_s16(test_vec[i].r2),
                               simde_vld1q_s16(test_vec[i].r3), } };

    int16_t a_[32];
    simde_vst4q_s16(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4q_s16(a_);
    simde_test_arm_neon_assert_equal_i16x8(r_.val[0], simde_vld1q_s16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i16x8(r_.val[1], simde_vld1q_s16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i16x8(r_.val[2], simde_vld1q_s16(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a0 = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t a1 = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t a2 = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t a3 = simde_test_arm_neon_random_i16x8();
    simde_int16x8x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_i16x8(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    int16_t buf[32];
    simde_vst4q_s16(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_i16(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4q_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r0[4];
    int32_t r1[4];
    int32_t r2[4];
    int32_t r3[4];
    int32_t a[16];
  } test_vec[] = {
    { {  INT32_C(   828023628), -INT32_C(   521468002),  INT32_C(   799178535),  INT32_C(   116664159) },
      { -INT32_C(  1033881595),  INT32_C(   549532486), -INT32_C(  1241418747), -INT32_C(  1122383247) },
      {  INT32_C(   200242029), -INT32_C(  1561535877), -INT32_C(  1177448871), -INT32_C(  1161837131) },
      {  INT32_C(  1132273661),  INT32_C(  1482899027),  INT32_C(   588145842), -INT32_C(  1662965969) },
      {
       INT32_C(   828023628),
      -INT32_C(  1033881595),
       INT32_C(   200242029),
       INT32_C(  1132273661),
      -INT32_C(   521468002),
       INT32_C(   549532486),
      -INT32_C(  1561535877),
       INT32_C(  1482899027),
       INT32_C(   799178535),
      -INT32_C(  1241418747),
      -INT32_C(  1177448871),
       INT32_C(   588145842),
       INT32_C(   116664159),
      -INT32_C(  1122383247),
      -INT32_C(  1161837131),
      -INT32_C(  1662965969),
      }
    },
    { {  INT32_C(   380162203),  INT32_C(    62428330), -INT32_C(   675509982),  INT32_C(  1284602702) },
      { -INT32_C(   292614501), -INT32_C(    12127411), -INT32_C(  2044504745),  INT32_C(   388170876) },
      {  INT32_C(  2116930516), -INT32_C(  2122193569), -INT32_C(  1118290322),  INT32_C(  1409935801) },
      {  INT32_C(  1161992440), -INT32_C(   482047605),  INT32_C(  1516857310),  INT32_C(  1064471659) },
      {
       INT32_C(   380162203),
      -INT32_C(   292614501),
       INT32_C(  2116930516),
       INT32_C(  1161992440),
       INT32_C(    62428330),
      -INT32_C(    12127411),
      -INT32_C(  2122193569),
      -INT32_C(   482047605),
      -INT32_C(   675509982),
      -INT32_C(  2044504745),
      -INT32_C(  1118290322),
       INT32_C(  1516857310),
       INT32_C(  1284602702),
       INT32_C(   388170876),
       INT32_C(  1409935801),
       INT32_C(  1064471659),
      }
    },
    { { -INT32_C(  1229086889), -INT32_C(   214483067),  INT32_C(   917540733),  INT32_C(  1904982393) },
      { -INT32_C(   575222446),  INT32_C(   885062230), -INT32_C(   846255518),  INT32_C(   235733430) },
      {  INT32_C(   633653920), -INT32_C(  2045117431),  INT32_C(    79546763), -INT32_C(   713734013) },
      {  INT32_C(  1823615765), -INT32_C(  2002750682),  INT32_C(  1398091677), -INT32_C(   782147024) },
      {
      -INT32_C(  1229086889),
      -INT32_C(   575222446),
       INT32_C(   633653920),
       INT32_C(  1823615765),
      -INT32_C(   214483067),
       INT32_C(   885062230),
      -INT32_C(  2045117431),
      -INT32_C(  2002750682),
       INT32_C(   917540733),
      -INT32_C(   846255518),
       INT32_C(    79546763),
       INT32_C(  1398091677),
       INT32_C(  1904982393),
       INT32_C(   235733430),
      -INT32_C(   713734013),
      -INT32_C(   782147024),
      }
    },
    { {  INT32_C(   922101293), -INT32_C(  1380118750),  INT32_C(  1555200729), -INT32_C(   684644414) },
      {  INT32_C(  2034492243), -INT32_C(   217979818),  INT32_C(  1145525779), -INT32_C(   434788167) },
      { -INT32_C(   266597426), -INT32_C(   190916325),  INT32_C(   357584979), -INT32_C(   890404489) },
      { -INT32_C(  1153224604),  INT32_C(   682509332),  INT32_C(  1416426907),  INT32_C(  1815773598) },
      {
       INT32_C(   922101293),
       INT32_C(  2034492243),
      -INT32_C(   266597426),
      -INT32_C(  1153224604),
      -INT32_C(  1380118750),
      -INT32_C(   217979818),
      -INT32_C(   190916325),
       INT32_C(   682509332),
       INT32_C(  1555200729),
       INT32_C(  1145525779),
       INT32_C(   357584979),
       INT32_C(  1416426907),
      -INT32_C(   684644414),
      -INT32_C(   434788167),
      -INT32_C(   890404489),
       INT32_C(  1815773598),
      }
    },
    { { -INT32_C(  1487055220), -INT32_C(  2086929616), -INT32_C(  1030100149), -INT32_C(   779254164) },
      { -INT32_C(   879963978), -INT32_C(  1326237163), -INT32_C(   838574288),  INT32_C(  1815756512) },
      { -INT32_C(  1005283436), -INT32_C(   582439022),  INT32_C(   127984027),  INT32_C(   500706663) },
      {  INT32_C(   317220093), -INT32_C(   809313377),  INT32_C(   446547514), -INT32_C(  1719150844) },
      {
      -INT32_C(  1487055220),
      -INT32_C(   879963978),
      -INT32_C(  1005283436),
       INT32_C(   317220093),
      -INT32_C(  2086929616),
      -INT32_C(  1326237163),
      -INT32_C(   582439022),
      -INT32_C(   809313377),
      -INT32_C(  1030100149),
      -INT32_C(   838574288),
       INT32_C(   127984027),
       INT32_C(   446547514),
      -INT32_C(   779254164),
       INT32_C(  1815756512),
       INT32_C(   500706663),
      -INT32_C(  1719150844),
      }
    },
    { {  INT32_C(    22911855), -INT32_C(   438327990), -INT32_C(   303202426), -INT32_C(  1458846292) },
      { -INT32_C(   910363862),  INT32_C(   160988879),  INT32_C(  1227109701),  INT32_C(  2078452492) },
      { -INT32_C(  1870839738),  INT32_C(  1819696357), -INT32_C(  2024184869),  INT32_C(  1378903080) },
      {  INT32_C(   656141400), -INT32_C(  1338985621), -INT32_C(   168209176),  INT32_C(  1165024511) },
      {
       INT32_C(    22911855),
      -INT32_C(   910363862),
      -INT32_C(  1870839738),
       INT32_C(   656141400),
      -INT32_C(   438327990),
       INT32_C(   160988879),
       INT32_C(  1819696357),
      -INT32_C(  1338985621),
      -INT32_C(   303202426),
       INT32_C(  1227109701),
      -INT32_C(  2024184869),
      -INT32_C(   168209176),
      -INT32_C(  1458846292),
       INT32_C(  2078452492),
       INT32_C(  1378903080),
       INT32_C(  1165024511),
      }
    },
    { {  INT32_C(    30862620),  INT32_C(   611142729), -INT32_C(   676608081), -INT32_C(  2094343125) },
      {  INT32_C(   866797000), -INT32_C(   505160711),  INT32_C(   802610479), -INT32_C(   713799751) },
      {  INT32_C(  2127972916),  INT32_C(  1168262294),  INT32_C(   907890187), -INT32_C(   222673110) },
      { -INT32_C(  2061081460),  INT32_C(  1869023551), -INT32_C(  1617019418), -INT32_C(  1183575420) },
      {
       INT32_C(    30862620),
       INT32_C(   866797000),
       INT32_C(  2127972916),
      -INT32_C(  2061081460),
       INT32_C(   611142729),
      -INT32_C(   505160711),
       INT32_C(  1168262294),
       INT32_C(  1869023551),
      -INT32_C(   676608081),
       INT32_C(   802610479),
       INT32_C(   907890187),
      -INT32_C(  1617019418),
      -INT32_C(  2094343125),
      -INT32_C(   713799751),
      -INT32_C(   222673110),
      -INT32_C(  1183575420),
      }
    },
    { { -INT32_C(   214480035), -INT32_C(  1707484785),  INT32_C(  1372608039),  INT32_C(   692357789) },
      {  INT32_C(   783248111),  INT32_C(  1520244339), -INT32_C(   654754989), -INT32_C(  1416532402) },
      {  INT32_C(  1218365625), -INT32_C(   907880543), -INT32_C(   904220115),  INT32_C(   754212413) },
      {  INT32_C(  1012573128),  INT32_C(   211220665), -INT32_C(  2115727565), -INT32_C(  1238600195) },
      {
      -INT32_C(   214480035),
       INT32_C(   783248111),
       INT32_C(  1218365625),
       INT32_C(  1012573128),
      -INT32_C(  1707484785),
       INT32_C(  1520244339),
      -INT32_C(   907880543),
       INT32_C(   211220665),
       INT32_C(  1372608039),
      -INT32_C(   654754989),
      -INT32_C(   904220115),
      -INT32_C(  2115727565),
       INT32_C(   692357789),
      -INT32_C(  1416532402),
       INT32_C(   754212413),
      -INT32_C(  1238600195),
      }
    },

  };


  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x4_t r_ = { { simde_vld1q_s32(test_vec[i].r0),
                               simde_vld1q_s32(test_vec[i].r1),
                               simde_vld1q_s32(test_vec[i].r2),
                               simde_vld1q_s32(test_vec[i].r3), } };

    int32_t a_[16];
    simde_vst4q_s32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4q_s32(a_);
    simde_test_arm_neon_assert_equal_i32x4(r_.val[0], simde_vld1q_s32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i32x4(r_.val[1], simde_vld1q_s32(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i32x4(r_.val[2], simde_vld1q_s32(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a0 = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t a1 = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t a2 = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t a3 = simde_test_arm_neon_random_i32x4();
    simde_int32x4x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_i32x4(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    int32_t buf[16];
    simde_vst4q_s32(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_i32(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4q_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r0[2];
    int64_t r1[2];
    int64_t r2[2];
    int64_t r3[2];
    int64_t a[8];
  } test_vec[] = {
    { { -INT64_C( 8541829943489260097),  INT64_C( 3564085409604377743) },
      {  INT64_C( 3948167333166941086), -INT64_C( 5324707249671790809) },
      { -INT64_C( 8979769786078813461), -INT64_C( 3779948158193827698) },
      { -INT64_C( 6995210109496671887),  INT64_C(  815857554770381220) },
      {
      -INT64_C( 8541829943489260097),
       INT64_C( 3948167333166941086),
      -INT64_C( 8979769786078813461),
      -INT64_C( 6995210109496671887),
       INT64_C( 3564085409604377743),
      -INT64_C( 5324707249671790809),
      -INT64_C( 3779948158193827698),
       INT64_C(  815857554770381220),
      }
    },
    { {  INT64_C( 5664476923655507492),  INT64_C( 8231509200709555012) },
      {  INT64_C( 2308117329321948915),  INT64_C( 1695339124149153885) },
      { -INT64_C( 1050521044186535332),  INT64_C( 4058480232873726687) },
      { -INT64_C( 1463481250095138283), -INT64_C( 3087517191304090597) },
      {
       INT64_C( 5664476923655507492),
       INT64_C( 2308117329321948915),
      -INT64_C( 1050521044186535332),
      -INT64_C( 1463481250095138283),
       INT64_C( 8231509200709555012),
       INT64_C( 1695339124149153885),
       INT64_C( 4058480232873726687),
      -INT64_C( 3087517191304090597),
      }
    },
    { {  INT64_C(  141965789005764185),  INT64_C( 1075292658120940399) },
      {  INT64_C( 6136523074534608559), -INT64_C( 2735222639929617989) },
      { -INT64_C( 3962084270849000225), -INT64_C( 4018221210646223564) },
      { -INT64_C( 1835727935554266121),  INT64_C( 5916083336943233472) },
      {
       INT64_C(  141965789005764185),
       INT64_C( 6136523074534608559),
      -INT64_C( 3962084270849000225),
      -INT64_C( 1835727935554266121),
       INT64_C( 1075292658120940399),
      -INT64_C( 2735222639929617989),
      -INT64_C( 4018221210646223564),
       INT64_C( 5916083336943233472),
      }
    },
    { {  INT64_C(  668036694159981346),  INT64_C( 2458530176053002812) },
      {  INT64_C( 1396636312019346511), -INT64_C( 4212995808429900605) },
      {  INT64_C( 8018806691179125865),  INT64_C( 4870049206829940552) },
      { -INT64_C( 8832369474108790521), -INT64_C( 7493351864596184933) },
      {
       INT64_C(  668036694159981346),
       INT64_C( 1396636312019346511),
       INT64_C( 8018806691179125865),
      -INT64_C( 8832369474108790521),
       INT64_C( 2458530176053002812),
      -INT64_C( 4212995808429900605),
       INT64_C( 4870049206829940552),
      -INT64_C( 7493351864596184933),
      }
    },
    { {  INT64_C( 1279900569163940640),  INT64_C( 8274267464691648670) },
      {  INT64_C( 5425493607493440003),  INT64_C( 7764358908210644730) },
      {  INT64_C( 6028774767652214735),  INT64_C( 5470106943301692939) },
      { -INT64_C( 1637237753729927861),  INT64_C( 3105463238554407010) },
      {
       INT64_C( 1279900569163940640),
       INT64_C( 5425493607493440003),
       INT64_C( 6028774767652214735),
      -INT64_C( 1637237753729927861),
       INT64_C( 8274267464691648670),
       INT64_C( 7764358908210644730),
       INT64_C( 5470106943301692939),
       INT64_C( 3105463238554407010),
      }
    },
    { {  INT64_C( 7237967780673476457),  INT64_C( 6643025027209582492) },
      { -INT64_C(   49082622515068551), -INT64_C( 6991904161123245200) },
      { -INT64_C( 4298353615892071781),  INT64_C( 8282921226878858373) },
      {  INT64_C( 6464403697443686937), -INT64_C( 4439955325513801073) },
      {
       INT64_C( 7237967780673476457),
      -INT64_C(   49082622515068551),
      -INT64_C( 4298353615892071781),
       INT64_C( 6464403697443686937),
       INT64_C( 6643025027209582492),
      -INT64_C( 6991904161123245200),
       INT64_C( 8282921226878858373),
      -INT64_C( 4439955325513801073),
      }
    },
    { { -INT64_C( 3259742678585762089),  INT64_C( 6750995090579680069) },
      {  INT64_C( 5037217593653758628),  INT64_C(    6310274718567724) },
      {  INT64_C( 2641856918791900554),  INT64_C( 1283264675808678446) },
      { -INT64_C( 2695256297990790244), -INT64_C( 7512774877096598893) },
      {
      -INT64_C( 3259742678585762089),
       INT64_C( 5037217593653758628),
       INT64_C( 2641856918791900554),
      -INT64_C( 2695256297990790244),
       INT64_C( 6750995090579680069),
       INT64_C(    6310274718567724),
       INT64_C( 1283264675808678446),
      -INT64_C( 7512774877096598893),
      }
    },
    { { -INT64_C( 5975405342833591023),  INT64_C( 2641343072094352682) },
      {  INT64_C( 6942879150843053778), -INT64_C( 2569624869237061711) },
      {  INT64_C(  560099869357491608), -INT64_C( 6485106687171763116) },
      {  INT64_C( 4087439451308324747),  INT64_C( 5309266436860401159) },
      {
      -INT64_C( 5975405342833591023),
       INT64_C( 6942879150843053778),
       INT64_C(  560099869357491608),
       INT64_C( 4087439451308324747),
       INT64_C( 2641343072094352682),
      -INT64_C( 2569624869237061711),
      -INT64_C( 6485106687171763116),
       INT64_C( 5309266436860401159),
      }
    },

  };


  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x4_t r_ = { { simde_vld1q_s64(test_vec[i].r0),
                               simde_vld1q_s64(test_vec[i].r1),
                               simde_vld1q_s64(test_vec[i].r2),
                               simde_vld1q_s64(test_vec[i].r3), } };

    int64_t a_[8];
    simde_vst4q_s64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4q_s64(a_);
    simde_test_arm_neon_assert_equal_i64x2(r_.val[0], simde_vld1q_s64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i64x2(r_.val[1], simde_vld1q_s64(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i64x2(r_.val[2], simde_vld1q_s64(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a0 = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t a1 = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t a2 = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t a3 = simde_test_arm_neon_random_i64x2();
    simde_int64x2x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_i64x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    int64_t buf[8];
    simde_vst4q_s64(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_i64(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r0[16];
    uint8_t r1[16];
    uint8_t r2[16];
    uint8_t r3[16];
    uint8_t a[64];
  } test_vec[] = {
    { { UINT8_C( 22), UINT8_C(175), UINT8_C(135), UINT8_C( 79), UINT8_C(237), UINT8_C(179), UINT8_C( 98), UINT8_C(110),
        UINT8_C( 15), UINT8_C( 62), UINT8_C(209), UINT8_C(178), UINT8_C(179), UINT8_C(169), UINT8_C( 95), UINT8_C( 83) },
      { UINT8_C( 45), UINT8_C(101), UINT8_C(113), UINT8_C(245), UINT8_C( 76), UINT8_C(222), UINT8_C(163), UINT8_C(217),
        UINT8_C(132), UINT8_C(175), UINT8_C(183), UINT8_C(169), UINT8_C(170), UINT8_C(171), UINT8_C(187), UINT8_C(192) },
      { UINT8_C( 90), UINT8_C( 66), UINT8_C( 16), UINT8_C( 71), UINT8_C(246), UINT8_C(114), UINT8_C(182), UINT8_C(  5),
        UINT8_C(176), UINT8_C(135), UINT8_C(183), UINT8_C( 99), UINT8_C( 48), UINT8_C( 22), UINT8_C(183), UINT8_C( 94) },
      { UINT8_C(124), UINT8_C( 40), UINT8_C( 83), UINT8_C(200), UINT8_C(  6), UINT8_C(246), UINT8_C(162), UINT8_C(139),
        UINT8_C(165), UINT8_C( 89), UINT8_C( 52), UINT8_C( 80), UINT8_C(  4), UINT8_C(240), UINT8_C( 16), UINT8_C( 95) },
      {
      UINT8_C( 22),
      UINT8_C( 45),
      UINT8_C( 90),
      UINT8_C(124),
      UINT8_C(175),
      UINT8_C(101),
      UINT8_C( 66),
      UINT8_C( 40),
      UINT8_C(135),
      UINT8_C(113),
      UINT8_C( 16),
      UINT8_C( 83),
      UINT8_C( 79),
      UINT8_C(245),
      UINT8_C( 71),
      UINT8_C(200),
      UINT8_C(237),
      UINT8_C( 76),
      UINT8_C(246),
      UINT8_C(  6),
      UINT8_C(179),
      UINT8_C(222),
      UINT8_C(114),
      UINT8_C(246),
      UINT8_C( 98),
      UINT8_C(163),
      UINT8_C(182),
      UINT8_C(162),
      UINT8_C(110),
      UINT8_C(217),
      UINT8_C(  5),
      UINT8_C(139),
      UINT8_C( 15),
      UINT8_C(132),
      UINT8_C(176),
      UINT8_C(165),
      UINT8_C( 62),
      UINT8_C(175),
      UINT8_C(135),
      UINT8_C( 89),
      UINT8_C(209),
      UINT8_C(183),
      UINT8_C(183),
      UINT8_C( 52),
      UINT8_C(178),
      UINT8_C(169),
      UINT8_C( 99),
      UINT8_C( 80),
      UINT8_C(179),
      UINT8_C(170),
      UINT8_C( 48),
      UINT8_C(  4),
      UINT8_C(169),
      UINT8_C(171),
      UINT8_C( 22),
      UINT8_C(240),
      UINT8_C( 95),
      UINT8_C(187),
      UINT8_C(183),
      UINT8_C( 16),
      UINT8_C( 83),
      UINT8_C(192),
      UINT8_C( 94),
      UINT8_C( 95),
      }
    },
    { { UINT8_C( 50), UINT8_C( 32), UINT8_C(166), UINT8_C( 40), UINT8_C(147), UINT8_C( 92), UINT8_C( 45), UINT8_C( 67),
        UINT8_C(227), UINT8_C(229), UINT8_C(167), UINT8_C( 20), UINT8_C(251), UINT8_C( 94), UINT8_C(114), UINT8_C(119) },
      { UINT8_C(134), UINT8_C(197), UINT8_C( 64), UINT8_C(141), UINT8_C(188), UINT8_C(226), UINT8_C( 24), UINT8_C( 97),
        UINT8_C( 59), UINT8_C( 76), UINT8_C(177), UINT8_C( 64), UINT8_C( 60), UINT8_C(194), UINT8_C(159), UINT8_C(111) },
      { UINT8_C(226), UINT8_C( 69), UINT8_C(151), UINT8_C(117), UINT8_C(162), UINT8_C(197), UINT8_C(185), UINT8_C(133),
        UINT8_C(170), UINT8_C( 96), UINT8_C(153), UINT8_C(165), UINT8_C(190), UINT8_C( 11), UINT8_C( 29), UINT8_C( 68) },
      { UINT8_C(209), UINT8_C( 93), UINT8_C(209), UINT8_C(141), UINT8_C( 63), UINT8_C(233), UINT8_C(238), UINT8_C(122),
        UINT8_C( 54), UINT8_C(160), UINT8_C(186), UINT8_C(114), UINT8_C( 98), UINT8_C( 89), UINT8_C(225), UINT8_C( 68) },
      {
      UINT8_C( 50),
      UINT8_C(134),
      UINT8_C(226),
      UINT8_C(209),
      UINT8_C( 32),
      UINT8_C(197),
      UINT8_C( 69),
      UINT8_C( 93),
      UINT8_C(166),
      UINT8_C( 64),
      UINT8_C(151),
      UINT8_C(209),
      UINT8_C( 40),
      UINT8_C(141),
      UINT8_C(117),
      UINT8_C(141),
      UINT8_C(147),
      UINT8_C(188),
      UINT8_C(162),
      UINT8_C( 63),
      UINT8_C( 92),
      UINT8_C(226),
      UINT8_C(197),
      UINT8_C(233),
      UINT8_C( 45),
      UINT8_C( 24),
      UINT8_C(185),
      UINT8_C(238),
      UINT8_C( 67),
      UINT8_C( 97),
      UINT8_C(133),
      UINT8_C(122),
      UINT8_C(227),
      UINT8_C( 59),
      UINT8_C(170),
      UINT8_C( 54),
      UINT8_C(229),
      UINT8_C( 76),
      UINT8_C( 96),
      UINT8_C(160),
      UINT8_C(167),
      UINT8_C(177),
      UINT8_C(153),
      UINT8_C(186),
      UINT8_C( 20),
      UINT8_C( 64),
      UINT8_C(165),
      UINT8_C(114),
      UINT8_C(251),
      UINT8_C( 60),
      UINT8_C(190),
      UINT8_C( 98),
      UINT8_C( 94),
      UINT8_C(194),
      UINT8_C( 11),
      UINT8_C( 89),
      UINT8_C(114),
      UINT8_C(159),
      UINT8_C( 29),
      UINT8_C(225),
      UINT8_C(119),
      UINT8_C(111),
      UINT8_C( 68),
      UINT8_C( 68),
      }
    },
    { { UINT8_C(159), UINT8_C(121), UINT8_C(186), UINT8_C( 65), UINT8_C( 62), UINT8_C(115), UINT8_C(198), UINT8_C(232),
        UINT8_C(211), UINT8_C( 96), UINT8_C(141), UINT8_C(145), UINT8_C(107), UINT8_C(170), UINT8_C(213), UINT8_C( 60) },
      { UINT8_C(  7), UINT8_C(167), UINT8_C(201), UINT8_C( 70), UINT8_C(144), UINT8_C(184), UINT8_C(193), UINT8_C(198),
        UINT8_C( 88), UINT8_C(123), UINT8_C( 57), UINT8_C(186), UINT8_C(213), UINT8_C( 26), UINT8_C(254), UINT8_C(116) },
      { UINT8_C(147), UINT8_C(184), UINT8_C(181), UINT8_C(209), UINT8_C( 43), UINT8_C(123), UINT8_C(185), UINT8_C(254),
        UINT8_C(219), UINT8_C( 71), UINT8_C(143), UINT8_C( 71), UINT8_C(241), UINT8_C(101), UINT8_C(131), UINT8_C(249) },
      { UINT8_C( 12), UINT8_C( 77), UINT8_C( 63), UINT8_C(156), UINT8_C(  5), UINT8_C(  0), UINT8_C( 99), UINT8_C( 93),
        UINT8_C(124), UINT8_C(156), UINT8_C( 23), UINT8_C( 81), UINT8_C(182), UINT8_C( 21), UINT8_C(197), UINT8_C( 74) },
      {
      UINT8_C(159),
      UINT8_C(  7),
      UINT8_C(147),
      UINT8_C( 12),
      UINT8_C(121),
      UINT8_C(167),
      UINT8_C(184),
      UINT8_C( 77),
      UINT8_C(186),
      UINT8_C(201),
      UINT8_C(181),
      UINT8_C( 63),
      UINT8_C( 65),
      UINT8_C( 70),
      UINT8_C(209),
      UINT8_C(156),
      UINT8_C( 62),
      UINT8_C(144),
      UINT8_C( 43),
      UINT8_C(  5),
      UINT8_C(115),
      UINT8_C(184),
      UINT8_C(123),
      UINT8_C(  0),
      UINT8_C(198),
      UINT8_C(193),
      UINT8_C(185),
      UINT8_C( 99),
      UINT8_C(232),
      UINT8_C(198),
      UINT8_C(254),
      UINT8_C( 93),
      UINT8_C(211),
      UINT8_C( 88),
      UINT8_C(219),
      UINT8_C(124),
      UINT8_C( 96),
      UINT8_C(123),
      UINT8_C( 71),
      UINT8_C(156),
      UINT8_C(141),
      UINT8_C( 57),
      UINT8_C(143),
      UINT8_C( 23),
      UINT8_C(145),
      UINT8_C(186),
      UINT8_C( 71),
      UINT8_C( 81),
      UINT8_C(107),
      UINT8_C(213),
      UINT8_C(241),
      UINT8_C(182),
      UINT8_C(170),
      UINT8_C( 26),
      UINT8_C(101),
      UINT8_C( 21),
      UINT8_C(213),
      UINT8_C(254),
      UINT8_C(131),
      UINT8_C(197),
      UINT8_C( 60),
      UINT8_C(116),
      UINT8_C(249),
      UINT8_C( 74),
      }
    },
    { { UINT8_C(206), UINT8_C(122), UINT8_C( 27), UINT8_C(249), UINT8_C(245), UINT8_C(213), UINT8_C(248), UINT8_C(209),
        UINT8_C( 28), UINT8_C(135), UINT8_C( 24), UINT8_C( 13), UINT8_C(236), UINT8_C(155), UINT8_C(  6), UINT8_C(248) },
      { UINT8_C(232), UINT8_C( 70), UINT8_C(149), UINT8_C(237), UINT8_C( 70), UINT8_C(248), UINT8_C( 74), UINT8_C(194),
        UINT8_C(148), UINT8_C( 97), UINT8_C( 19), UINT8_C( 74), UINT8_C(119), UINT8_C(216), UINT8_C(148), UINT8_C( 69) },
      { UINT8_C( 82), UINT8_C(176), UINT8_C( 62), UINT8_C( 72), UINT8_C(133), UINT8_C( 54), UINT8_C( 25), UINT8_C(161),
        UINT8_C(190), UINT8_C( 49), UINT8_C(174), UINT8_C(170), UINT8_C(204), UINT8_C(181), UINT8_C(163), UINT8_C(181) },
      { UINT8_C(251), UINT8_C( 56), UINT8_C(162), UINT8_C( 65), UINT8_C( 48), UINT8_C(237), UINT8_C(  4), UINT8_C(196),
        UINT8_C( 78), UINT8_C( 23), UINT8_C( 14), UINT8_C(197), UINT8_C(240), UINT8_C(163), UINT8_C( 10), UINT8_C( 66) },
      {
      UINT8_C(206),
      UINT8_C(232),
      UINT8_C( 82),
      UINT8_C(251),
      UINT8_C(122),
      UINT8_C( 70),
      UINT8_C(176),
      UINT8_C( 56),
      UINT8_C( 27),
      UINT8_C(149),
      UINT8_C( 62),
      UINT8_C(162),
      UINT8_C(249),
      UINT8_C(237),
      UINT8_C( 72),
      UINT8_C( 65),
      UINT8_C(245),
      UINT8_C( 70),
      UINT8_C(133),
      UINT8_C( 48),
      UINT8_C(213),
      UINT8_C(248),
      UINT8_C( 54),
      UINT8_C(237),
      UINT8_C(248),
      UINT8_C( 74),
      UINT8_C( 25),
      UINT8_C(  4),
      UINT8_C(209),
      UINT8_C(194),
      UINT8_C(161),
      UINT8_C(196),
      UINT8_C( 28),
      UINT8_C(148),
      UINT8_C(190),
      UINT8_C( 78),
      UINT8_C(135),
      UINT8_C( 97),
      UINT8_C( 49),
      UINT8_C( 23),
      UINT8_C( 24),
      UINT8_C( 19),
      UINT8_C(174),
      UINT8_C( 14),
      UINT8_C( 13),
      UINT8_C( 74),
      UINT8_C(170),
      UINT8_C(197),
      UINT8_C(236),
      UINT8_C(119),
      UINT8_C(204),
      UINT8_C(240),
      UINT8_C(155),
      UINT8_C(216),
      UINT8_C(181),
      UINT8_C(163),
      UINT8_C(  6),
      UINT8_C(148),
      UINT8_C(163),
      UINT8_C( 10),
      UINT8_C(248),
      UINT8_C( 69),
      UINT8_C(181),
      UINT8_C( 66),
      }
    },
    { { UINT8_C( 83), UINT8_C( 73), UINT8_C(138), UINT8_C(216), UINT8_C(127), UINT8_C(163), UINT8_C(121), UINT8_C( 61),
        UINT8_C(212), UINT8_C( 39), UINT8_C(232), UINT8_C(161), UINT8_C(220), UINT8_C(139), UINT8_C( 86), UINT8_C(215) },
      { UINT8_C(195), UINT8_C(248), UINT8_C( 25), UINT8_C(243), UINT8_C(229), UINT8_C( 29), UINT8_C(183), UINT8_C( 52),
        UINT8_C( 52), UINT8_C(197), UINT8_C(249), UINT8_C( 36), UINT8_C(104), UINT8_C(  4), UINT8_C(103), UINT8_C(187) },
      { UINT8_C( 77), UINT8_C(241), UINT8_C(147), UINT8_C(204), UINT8_C(149), UINT8_C( 12), UINT8_C( 10), UINT8_C(105),
        UINT8_C( 52), UINT8_C(242), UINT8_C( 10), UINT8_C( 16), UINT8_C(125), UINT8_C( 96), UINT8_C(232), UINT8_C( 64) },
      { UINT8_C( 89), UINT8_C(  1), UINT8_C( 51), UINT8_C( 62), UINT8_C( 30), UINT8_C(234), UINT8_C(114), UINT8_C( 82),
        UINT8_C(175), UINT8_C(108), UINT8_C(119), UINT8_C( 24), UINT8_C(112), UINT8_C(222), UINT8_C(211), UINT8_C(189) },
      {
      UINT8_C( 83),
      UINT8_C(195),
      UINT8_C( 77),
      UINT8_C( 89),
      UINT8_C( 73),
      UINT8_C(248),
      UINT8_C(241),
      UINT8_C(  1),
      UINT8_C(138),
      UINT8_C( 25),
      UINT8_C(147),
      UINT8_C( 51),
      UINT8_C(216),
      UINT8_C(243),
      UINT8_C(204),
      UINT8_C( 62),
      UINT8_C(127),
      UINT8_C(229),
      UINT8_C(149),
      UINT8_C( 30),
      UINT8_C(163),
      UINT8_C( 29),
      UINT8_C( 12),
      UINT8_C(234),
      UINT8_C(121),
      UINT8_C(183),
      UINT8_C( 10),
      UINT8_C(114),
      UINT8_C( 61),
      UINT8_C( 52),
      UINT8_C(105),
      UINT8_C( 82),
      UINT8_C(212),
      UINT8_C( 52),
      UINT8_C( 52),
      UINT8_C(175),
      UINT8_C( 39),
      UINT8_C(197),
      UINT8_C(242),
      UINT8_C(108),
      UINT8_C(232),
      UINT8_C(249),
      UINT8_C( 10),
      UINT8_C(119),
      UINT8_C(161),
      UINT8_C( 36),
      UINT8_C( 16),
      UINT8_C( 24),
      UINT8_C(220),
      UINT8_C(104),
      UINT8_C(125),
      UINT8_C(112),
      UINT8_C(139),
      UINT8_C(  4),
      UINT8_C( 96),
      UINT8_C(222),
      UINT8_C( 86),
      UINT8_C(103),
      UINT8_C(232),
      UINT8_C(211),
      UINT8_C(215),
      UINT8_C(187),
      UINT8_C( 64),
      UINT8_C(189),
      }
    },
    { { UINT8_C(207), UINT8_C(103), UINT8_C(137), UINT8_C(100), UINT8_C(115), UINT8_C(147), UINT8_C(206), UINT8_C(167),
        UINT8_C(133), UINT8_C(216), UINT8_C(184), UINT8_C(  2), UINT8_C( 57), UINT8_C(160), UINT8_C( 66), UINT8_C(146) },
      { UINT8_C(161), UINT8_C(117), UINT8_C(208), UINT8_C(191), UINT8_C( 95), UINT8_C( 67), UINT8_C( 17), UINT8_C( 15),
        UINT8_C(175), UINT8_C(136), UINT8_C( 39), UINT8_C( 31), UINT8_C(102), UINT8_C(250), UINT8_C(220), UINT8_C( 54) },
      { UINT8_C( 97), UINT8_C(101), UINT8_C(154), UINT8_C(213), UINT8_C(249), UINT8_C(104), UINT8_C(124), UINT8_C(126),
        UINT8_C( 65), UINT8_C( 52), UINT8_C(129), UINT8_C(122), UINT8_C(212), UINT8_C(195), UINT8_C( 12), UINT8_C(117) },
      { UINT8_C( 57), UINT8_C(220), UINT8_C( 52), UINT8_C(152), UINT8_C( 31), UINT8_C( 70), UINT8_C(167), UINT8_C(206),
        UINT8_C(206), UINT8_C(206), UINT8_C(237), UINT8_C( 53), UINT8_C(201), UINT8_C(201), UINT8_C(107), UINT8_C( 42) },
      {
      UINT8_C(207),
      UINT8_C(161),
      UINT8_C( 97),
      UINT8_C( 57),
      UINT8_C(103),
      UINT8_C(117),
      UINT8_C(101),
      UINT8_C(220),
      UINT8_C(137),
      UINT8_C(208),
      UINT8_C(154),
      UINT8_C( 52),
      UINT8_C(100),
      UINT8_C(191),
      UINT8_C(213),
      UINT8_C(152),
      UINT8_C(115),
      UINT8_C( 95),
      UINT8_C(249),
      UINT8_C( 31),
      UINT8_C(147),
      UINT8_C( 67),
      UINT8_C(104),
      UINT8_C( 70),
      UINT8_C(206),
      UINT8_C( 17),
      UINT8_C(124),
      UINT8_C(167),
      UINT8_C(167),
      UINT8_C( 15),
      UINT8_C(126),
      UINT8_C(206),
      UINT8_C(133),
      UINT8_C(175),
      UINT8_C( 65),
      UINT8_C(206),
      UINT8_C(216),
      UINT8_C(136),
      UINT8_C( 52),
      UINT8_C(206),
      UINT8_C(184),
      UINT8_C( 39),
      UINT8_C(129),
      UINT8_C(237),
      UINT8_C(  2),
      UINT8_C( 31),
      UINT8_C(122),
      UINT8_C( 53),
      UINT8_C( 57),
      UINT8_C(102),
      UINT8_C(212),
      UINT8_C(201),
      UINT8_C(160),
      UINT8_C(250),
      UINT8_C(195),
      UINT8_C(201),
      UINT8_C( 66),
      UINT8_C(220),
      UINT8_C( 12),
      UINT8_C(107),
      UINT8_C(146),
      UINT8_C( 54),
      UINT8_C(117),
      UINT8_C( 42),
      }
    },
    { { UINT8_C( 47), UINT8_C(  5),    UINT8_MAX, UINT8_C( 40), UINT8_C(110), UINT8_C(124), UINT8_C(166), UINT8_C(175),
        UINT8_C(176), UINT8_C( 39), UINT8_C( 41), UINT8_C(133), UINT8_C(235), UINT8_C( 53), UINT8_C(250), UINT8_C( 36) },
      { UINT8_C( 17), UINT8_C( 47), UINT8_C(188), UINT8_C( 49), UINT8_C(117), UINT8_C(100),    UINT8_MAX, UINT8_C( 67),
        UINT8_C( 50), UINT8_C(237), UINT8_C(120), UINT8_C(251), UINT8_C(182), UINT8_C(227), UINT8_C( 38), UINT8_C(229) },
      { UINT8_C(233), UINT8_C( 37), UINT8_C( 13), UINT8_C( 87), UINT8_C(161), UINT8_C(180), UINT8_C(  6), UINT8_C( 82),
        UINT8_C(219), UINT8_C( 47), UINT8_C(215), UINT8_C(198), UINT8_C(100), UINT8_C(209), UINT8_C(234), UINT8_C(117) },
      { UINT8_C(  0), UINT8_C(167), UINT8_C(166), UINT8_C(117), UINT8_C( 11), UINT8_C(166), UINT8_C(185), UINT8_C( 61),
        UINT8_C(147), UINT8_C( 49), UINT8_C( 57), UINT8_C( 73), UINT8_C( 21), UINT8_C( 95), UINT8_C( 47), UINT8_C(254) },
      {
      UINT8_C( 47),
      UINT8_C( 17),
      UINT8_C(233),
      UINT8_C(  0),
      UINT8_C(  5),
      UINT8_C( 47),
      UINT8_C( 37),
      UINT8_C(167),
         UINT8_MAX,
      UINT8_C(188),
      UINT8_C( 13),
      UINT8_C(166),
      UINT8_C( 40),
      UINT8_C( 49),
      UINT8_C( 87),
      UINT8_C(117),
      UINT8_C(110),
      UINT8_C(117),
      UINT8_C(161),
      UINT8_C( 11),
      UINT8_C(124),
      UINT8_C(100),
      UINT8_C(180),
      UINT8_C(166),
      UINT8_C(166),
         UINT8_MAX,
      UINT8_C(  6),
      UINT8_C(185),
      UINT8_C(175),
      UINT8_C( 67),
      UINT8_C( 82),
      UINT8_C( 61),
      UINT8_C(176),
      UINT8_C( 50),
      UINT8_C(219),
      UINT8_C(147),
      UINT8_C( 39),
      UINT8_C(237),
      UINT8_C( 47),
      UINT8_C( 49),
      UINT8_C( 41),
      UINT8_C(120),
      UINT8_C(215),
      UINT8_C( 57),
      UINT8_C(133),
      UINT8_C(251),
      UINT8_C(198),
      UINT8_C( 73),
      UINT8_C(235),
      UINT8_C(182),
      UINT8_C(100),
      UINT8_C( 21),
      UINT8_C( 53),
      UINT8_C(227),
      UINT8_C(209),
      UINT8_C( 95),
      UINT8_C(250),
      UINT8_C( 38),
      UINT8_C(234),
      UINT8_C( 47),
      UINT8_C( 36),
      UINT8_C(229),
      UINT8_C(117),
      UINT8_C(254),
      }
    },
    { { UINT8_C(132), UINT8_C( 60), UINT8_C( 85), UINT8_C( 38), UINT8_C(240), UINT8_C( 91), UINT8_C(120), UINT8_C(204),
        UINT8_C(138), UINT8_C( 79), UINT8_C(146), UINT8_C(238), UINT8_C( 32), UINT8_C(125), UINT8_C( 99), UINT8_C( 33) },
      { UINT8_C( 36), UINT8_C( 10), UINT8_C(150), UINT8_C( 47), UINT8_C(176), UINT8_C( 79), UINT8_C(108), UINT8_C( 67),
        UINT8_C(129), UINT8_C(165), UINT8_C(140), UINT8_C(150), UINT8_C(  4), UINT8_C(187), UINT8_C(148), UINT8_C(137) },
      { UINT8_C(248), UINT8_C(233), UINT8_C(175), UINT8_C(232), UINT8_C( 68), UINT8_C( 39), UINT8_C(180), UINT8_C(206),
        UINT8_C(118), UINT8_C( 71), UINT8_C(188), UINT8_C(150), UINT8_C(196), UINT8_C( 31), UINT8_C(183), UINT8_C(232) },
      { UINT8_C( 41), UINT8_C( 78), UINT8_C( 23), UINT8_C(217), UINT8_C(157), UINT8_C(131), UINT8_C( 28), UINT8_C( 30),
        UINT8_C( 41), UINT8_C(169), UINT8_C(180), UINT8_C( 45), UINT8_C(100), UINT8_C( 72), UINT8_C(182), UINT8_C( 92) },
      {
      UINT8_C(132),
      UINT8_C( 36),
      UINT8_C(248),
      UINT8_C( 41),
      UINT8_C( 60),
      UINT8_C( 10),
      UINT8_C(233),
      UINT8_C( 78),
      UINT8_C( 85),
      UINT8_C(150),
      UINT8_C(175),
      UINT8_C( 23),
      UINT8_C( 38),
      UINT8_C( 47),
      UINT8_C(232),
      UINT8_C(217),
      UINT8_C(240),
      UINT8_C(176),
      UINT8_C( 68),
      UINT8_C(157),
      UINT8_C( 91),
      UINT8_C( 79),
      UINT8_C( 39),
      UINT8_C(131),
      UINT8_C(120),
      UINT8_C(108),
      UINT8_C(180),
      UINT8_C( 28),
      UINT8_C(204),
      UINT8_C( 67),
      UINT8_C(206),
      UINT8_C( 30),
      UINT8_C(138),
      UINT8_C(129),
      UINT8_C(118),
      UINT8_C( 41),
      UINT8_C( 79),
      UINT8_C(165),
      UINT8_C( 71),
      UINT8_C(169),
      UINT8_C(146),
      UINT8_C(140),
      UINT8_C(188),
      UINT8_C(180),
      UINT8_C(238),
      UINT8_C(150),
      UINT8_C(150),
      UINT8_C( 45),
      UINT8_C( 32),
      UINT8_C(  4),
      UINT8_C(196),
      UINT8_C(100),
      UINT8_C(125),
      UINT8_C(187),
      UINT8_C( 31),
      UINT8_C( 72),
      UINT8_C( 99),
      UINT8_C(148),
      UINT8_C(183),
      UINT8_C(182),
      UINT8_C( 33),
      UINT8_C(137),
      UINT8_C(232),
      UINT8_C( 92),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x4_t r_ = { { simde_vld1q_u8(test_vec[i].r0),
                                simde_vld1q_u8(test_vec[i].r1),
                                simde_vld1q_u8(test_vec[i].r2),
                                simde_vld1q_u8(test_vec[i].r3), } };

    uint8_t a_[64];
    simde_vst4q_u8(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4q_u8(a_);
    simde_test_arm_neon_assert_equal_u8x16(r_.val[0], simde_vld1q_u8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u8x16(r_.val[1], simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r_.val[2], simde_vld1q_u8(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (size_t i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a0 = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t a1 = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t a2 = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t a3 = simde_test_arm_neon_random_u8x16();
    simde_uint8x16x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_u8x16(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    uint8_t buf[64];
    simde_vst4q_u8(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_u8(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r0[8];
    uint16_t r1[8];
    uint16_t r2[8];
    uint16_t r3[8];
    uint16_t a[32];
  } test_vec[] = {
    { { UINT16_C(15069), UINT16_C(48098), UINT16_C(50460), UINT16_C(57042), UINT16_C(60925), UINT16_C(31976), UINT16_C(20855), UINT16_C(12914) },
      { UINT16_C(15353), UINT16_C(16232), UINT16_C(47274), UINT16_C(46855), UINT16_C(31075), UINT16_C(46180), UINT16_C(53651), UINT16_C(28697) },
      { UINT16_C(64523), UINT16_C(10027), UINT16_C(64961), UINT16_C(48645), UINT16_C(60906), UINT16_C(24890), UINT16_C(44095), UINT16_C(14483) },
      { UINT16_C(64487), UINT16_C(37239), UINT16_C(32435), UINT16_C( 5705), UINT16_C(44535), UINT16_C(35531), UINT16_C(58494), UINT16_C(35322) },
      {
      UINT16_C(15069),
      UINT16_C(15353),
      UINT16_C(64523),
      UINT16_C(64487),
      UINT16_C(48098),
      UINT16_C(16232),
      UINT16_C(10027),
      UINT16_C(37239),
      UINT16_C(50460),
      UINT16_C(47274),
      UINT16_C(64961),
      UINT16_C(32435),
      UINT16_C(57042),
      UINT16_C(46855),
      UINT16_C(48645),
      UINT16_C( 5705),
      UINT16_C(60925),
      UINT16_C(31075),
      UINT16_C(60906),
      UINT16_C(44535),
      UINT16_C(31976),
      UINT16_C(46180),
      UINT16_C(24890),
      UINT16_C(35531),
      UINT16_C(20855),
      UINT16_C(53651),
      UINT16_C(44095),
      UINT16_C(58494),
      UINT16_C(12914),
      UINT16_C(28697),
      UINT16_C(14483),
      UINT16_C(35322),
      }
    },
    { { UINT16_C( 9696), UINT16_C(41393), UINT16_C(46626), UINT16_C( 3424), UINT16_C(39588), UINT16_C(58222), UINT16_C(  583), UINT16_C(11803) },
      { UINT16_C(37629), UINT16_C(45504), UINT16_C( 2321), UINT16_C( 2247), UINT16_C(37558), UINT16_C(13459), UINT16_C(36215), UINT16_C(22461) },
      { UINT16_C(28339), UINT16_C(54777), UINT16_C(22821), UINT16_C(51682), UINT16_C(20979), UINT16_C(15020), UINT16_C(51027), UINT16_C(20585) },
      { UINT16_C(10585), UINT16_C(27137), UINT16_C(51506), UINT16_C(59507), UINT16_C( 1627), UINT16_C(53788), UINT16_C(55699), UINT16_C(17962) },
      {
      UINT16_C( 9696),
      UINT16_C(37629),
      UINT16_C(28339),
      UINT16_C(10585),
      UINT16_C(41393),
      UINT16_C(45504),
      UINT16_C(54777),
      UINT16_C(27137),
      UINT16_C(46626),
      UINT16_C( 2321),
      UINT16_C(22821),
      UINT16_C(51506),
      UINT16_C( 3424),
      UINT16_C( 2247),
      UINT16_C(51682),
      UINT16_C(59507),
      UINT16_C(39588),
      UINT16_C(37558),
      UINT16_C(20979),
      UINT16_C( 1627),
      UINT16_C(58222),
      UINT16_C(13459),
      UINT16_C(15020),
      UINT16_C(53788),
      UINT16_C(  583),
      UINT16_C(36215),
      UINT16_C(51027),
      UINT16_C(55699),
      UINT16_C(11803),
      UINT16_C(22461),
      UINT16_C(20585),
      UINT16_C(17962),
      }
    },
    { { UINT16_C( 9032), UINT16_C(27932), UINT16_C(65148), UINT16_C(28470), UINT16_C(57935), UINT16_C(41642), UINT16_C( 5033), UINT16_C(  755) },
      { UINT16_C(62524), UINT16_C(28269), UINT16_C(57533), UINT16_C( 6486), UINT16_C(29414), UINT16_C(31211), UINT16_C( 5451), UINT16_C(37824) },
      { UINT16_C(56376), UINT16_C(46080), UINT16_C(14042), UINT16_C(10788), UINT16_C(52760), UINT16_C(49612), UINT16_C(49121), UINT16_C( 7620) },
      { UINT16_C(12724), UINT16_C(29067), UINT16_C(57617), UINT16_C(63370), UINT16_C(30291), UINT16_C(40560), UINT16_C(12427), UINT16_C(50226) },
      {
      UINT16_C( 9032),
      UINT16_C(62524),
      UINT16_C(56376),
      UINT16_C(12724),
      UINT16_C(27932),
      UINT16_C(28269),
      UINT16_C(46080),
      UINT16_C(29067),
      UINT16_C(65148),
      UINT16_C(57533),
      UINT16_C(14042),
      UINT16_C(57617),
      UINT16_C(28470),
      UINT16_C( 6486),
      UINT16_C(10788),
      UINT16_C(63370),
      UINT16_C(57935),
      UINT16_C(29414),
      UINT16_C(52760),
      UINT16_C(30291),
      UINT16_C(41642),
      UINT16_C(31211),
      UINT16_C(49612),
      UINT16_C(40560),
      UINT16_C( 5033),
      UINT16_C( 5451),
      UINT16_C(49121),
      UINT16_C(12427),
      UINT16_C(  755),
      UINT16_C(37824),
      UINT16_C( 7620),
      UINT16_C(50226),
      }
    },
    { { UINT16_C(12812), UINT16_C(59256), UINT16_C(40041), UINT16_C(33041), UINT16_C(56682), UINT16_C(19267), UINT16_C( 1949), UINT16_C(20840) },
      { UINT16_C(62264), UINT16_C(18882), UINT16_C(19924), UINT16_C(10048), UINT16_C(45251), UINT16_C(20166), UINT16_C(63713), UINT16_C(60690) },
      { UINT16_C(35626), UINT16_C(37844), UINT16_C(58663), UINT16_C(37397), UINT16_C(22723), UINT16_C(24797), UINT16_C(18015), UINT16_C(38833) },
      { UINT16_C(29497), UINT16_C( 3808), UINT16_C( 8384), UINT16_C(33589), UINT16_C(64464), UINT16_C(45522), UINT16_C(58611), UINT16_C( 7839) },
      {
      UINT16_C(12812),
      UINT16_C(62264),
      UINT16_C(35626),
      UINT16_C(29497),
      UINT16_C(59256),
      UINT16_C(18882),
      UINT16_C(37844),
      UINT16_C( 3808),
      UINT16_C(40041),
      UINT16_C(19924),
      UINT16_C(58663),
      UINT16_C( 8384),
      UINT16_C(33041),
      UINT16_C(10048),
      UINT16_C(37397),
      UINT16_C(33589),
      UINT16_C(56682),
      UINT16_C(45251),
      UINT16_C(22723),
      UINT16_C(64464),
      UINT16_C(19267),
      UINT16_C(20166),
      UINT16_C(24797),
      UINT16_C(45522),
      UINT16_C( 1949),
      UINT16_C(63713),
      UINT16_C(18015),
      UINT16_C(58611),
      UINT16_C(20840),
      UINT16_C(60690),
      UINT16_C(38833),
      UINT16_C( 7839),
      }
    },
    { { UINT16_C(29551), UINT16_C(38833), UINT16_C(50777), UINT16_C( 7209), UINT16_C( 1566), UINT16_C(32124), UINT16_C(11596), UINT16_C(34324) },
      { UINT16_C(62624), UINT16_C(24980), UINT16_C(51476), UINT16_C(58852), UINT16_C(46789), UINT16_C(47254), UINT16_C(13723), UINT16_C( 2774) },
      { UINT16_C(34985), UINT16_C(  673), UINT16_C(51790), UINT16_C(27934), UINT16_C(39633), UINT16_C( 7658), UINT16_C(65479), UINT16_C(26531) },
      { UINT16_C(14323), UINT16_C( 2248), UINT16_C(44289), UINT16_C(50925), UINT16_C(33635), UINT16_C(65150), UINT16_C(21945), UINT16_C(25097) },
      {
      UINT16_C(29551),
      UINT16_C(62624),
      UINT16_C(34985),
      UINT16_C(14323),
      UINT16_C(38833),
      UINT16_C(24980),
      UINT16_C(  673),
      UINT16_C( 2248),
      UINT16_C(50777),
      UINT16_C(51476),
      UINT16_C(51790),
      UINT16_C(44289),
      UINT16_C( 7209),
      UINT16_C(58852),
      UINT16_C(27934),
      UINT16_C(50925),
      UINT16_C( 1566),
      UINT16_C(46789),
      UINT16_C(39633),
      UINT16_C(33635),
      UINT16_C(32124),
      UINT16_C(47254),
      UINT16_C( 7658),
      UINT16_C(65150),
      UINT16_C(11596),
      UINT16_C(13723),
      UINT16_C(65479),
      UINT16_C(21945),
      UINT16_C(34324),
      UINT16_C( 2774),
      UINT16_C(26531),
      UINT16_C(25097),
      }
    },
    { { UINT16_C(43741), UINT16_C(11108), UINT16_C(33397), UINT16_C(18072), UINT16_C(33564), UINT16_C(58211), UINT16_C( 1922), UINT16_C(30026) },
      { UINT16_C( 4926), UINT16_C(16253), UINT16_C(27328), UINT16_C( 8965), UINT16_C(34030), UINT16_C(42786), UINT16_C(11225), UINT16_C(46601) },
      { UINT16_C(28117), UINT16_C(19169), UINT16_C(31471), UINT16_C( 2960), UINT16_C(62717), UINT16_C(32750), UINT16_C(14587), UINT16_C(14836) },
      { UINT16_C(29259), UINT16_C( 2937), UINT16_C(32476), UINT16_C(51759), UINT16_C(20738), UINT16_C(56177), UINT16_C(31356), UINT16_C(20881) },
      {
      UINT16_C(43741),
      UINT16_C( 4926),
      UINT16_C(28117),
      UINT16_C(29259),
      UINT16_C(11108),
      UINT16_C(16253),
      UINT16_C(19169),
      UINT16_C( 2937),
      UINT16_C(33397),
      UINT16_C(27328),
      UINT16_C(31471),
      UINT16_C(32476),
      UINT16_C(18072),
      UINT16_C( 8965),
      UINT16_C( 2960),
      UINT16_C(51759),
      UINT16_C(33564),
      UINT16_C(34030),
      UINT16_C(62717),
      UINT16_C(20738),
      UINT16_C(58211),
      UINT16_C(42786),
      UINT16_C(32750),
      UINT16_C(56177),
      UINT16_C( 1922),
      UINT16_C(11225),
      UINT16_C(14587),
      UINT16_C(31356),
      UINT16_C(30026),
      UINT16_C(46601),
      UINT16_C(14836),
      UINT16_C(20881),
      }
    },
    { { UINT16_C(29671), UINT16_C(54940), UINT16_C(11501), UINT16_C(60129), UINT16_C(53024), UINT16_C( 7017), UINT16_C(23816), UINT16_C(21333) },
      { UINT16_C(52943), UINT16_C(44127), UINT16_C(36428), UINT16_C(20342), UINT16_C(59615), UINT16_C(23338), UINT16_C(48226), UINT16_C(19116) },
      { UINT16_C(18479), UINT16_C( 7200), UINT16_C(  629), UINT16_C(38150), UINT16_C(28625), UINT16_C(55729), UINT16_C( 1740), UINT16_C(39981) },
      { UINT16_C(36052), UINT16_C( 8264), UINT16_C(48666), UINT16_C(63855), UINT16_C(39590), UINT16_C( 2388), UINT16_C(   86), UINT16_C(34131) },
      {
      UINT16_C(29671),
      UINT16_C(52943),
      UINT16_C(18479),
      UINT16_C(36052),
      UINT16_C(54940),
      UINT16_C(44127),
      UINT16_C( 7200),
      UINT16_C( 8264),
      UINT16_C(11501),
      UINT16_C(36428),
      UINT16_C(  629),
      UINT16_C(48666),
      UINT16_C(60129),
      UINT16_C(20342),
      UINT16_C(38150),
      UINT16_C(63855),
      UINT16_C(53024),
      UINT16_C(59615),
      UINT16_C(28625),
      UINT16_C(39590),
      UINT16_C( 7017),
      UINT16_C(23338),
      UINT16_C(55729),
      UINT16_C( 2388),
      UINT16_C(23816),
      UINT16_C(48226),
      UINT16_C( 1740),
      UINT16_C(   86),
      UINT16_C(21333),
      UINT16_C(19116),
      UINT16_C(39981),
      UINT16_C(34131),
      }
    },
    { { UINT16_C(29513), UINT16_C(48801), UINT16_C(42869), UINT16_C(18259), UINT16_C( 1046), UINT16_C(57888), UINT16_C(19722), UINT16_C(56958) },
      { UINT16_C(50905), UINT16_C(62463), UINT16_C(28293), UINT16_C(11244), UINT16_C(16392), UINT16_C(24116), UINT16_C(34625), UINT16_C(35555) },
      { UINT16_C(34043), UINT16_C(28744), UINT16_C(39723), UINT16_C(16823), UINT16_C(55456), UINT16_C(43556), UINT16_C(41509), UINT16_C(65417) },
      { UINT16_C(34921), UINT16_C(61170), UINT16_C(57334), UINT16_C(65305), UINT16_C(19999), UINT16_C(24669), UINT16_C(16853), UINT16_C(53482) },
      {
      UINT16_C(29513),
      UINT16_C(50905),
      UINT16_C(34043),
      UINT16_C(34921),
      UINT16_C(48801),
      UINT16_C(62463),
      UINT16_C(28744),
      UINT16_C(61170),
      UINT16_C(42869),
      UINT16_C(28293),
      UINT16_C(39723),
      UINT16_C(57334),
      UINT16_C(18259),
      UINT16_C(11244),
      UINT16_C(16823),
      UINT16_C(65305),
      UINT16_C( 1046),
      UINT16_C(16392),
      UINT16_C(55456),
      UINT16_C(19999),
      UINT16_C(57888),
      UINT16_C(24116),
      UINT16_C(43556),
      UINT16_C(24669),
      UINT16_C(19722),
      UINT16_C(34625),
      UINT16_C(41509),
      UINT16_C(16853),
      UINT16_C(56958),
      UINT16_C(35555),
      UINT16_C(65417),
      UINT16_C(53482),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x4_t r_ = { { simde_vld1q_u16(test_vec[i].r0),
                                simde_vld1q_u16(test_vec[i].r1),
                                simde_vld1q_u16(test_vec[i].r2),
                                simde_vld1q_u16(test_vec[i].r3), } };

    uint16_t a_[32];
    simde_vst4q_u16(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4q_u16(a_);
    simde_test_arm_neon_assert_equal_u16x8(r_.val[0], simde_vld1q_u16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u16x8(r_.val[1], simde_vld1q_u16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u16x8(r_.val[2], simde_vld1q_u16(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (size_t i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a0 = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t a1 = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t a2 = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t a3 = simde_test_arm_neon_random_u16x8();
    simde_uint16x8x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_u16x8(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    uint16_t buf[32];
    simde_vst4q_u16(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])) ; j++) {
      simde_test_codegen_write_u16(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}


static int
test_simde_vst4q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r0[4];
    uint32_t r1[4];
    uint32_t r2[4];
    uint32_t r3[4];
    uint32_t a[16];
  } test_vec[] = {
    { { UINT32_C( 816928038), UINT32_C(4024508959), UINT32_C(2589801649), UINT32_C(2940729031) },
      { UINT32_C(3956440918), UINT32_C( 899659297), UINT32_C(1093083275), UINT32_C( 598365436) },
      { UINT32_C(3377683625), UINT32_C( 800601470), UINT32_C( 969545329), UINT32_C(1659375884) },
      { UINT32_C(2991438481), UINT32_C(4243057777), UINT32_C( 154996236), UINT32_C( 204269667) },
      {
      UINT32_C( 816928038),
      UINT32_C(3956440918),
      UINT32_C(3377683625),
      UINT32_C(2991438481),
      UINT32_C(4024508959),
      UINT32_C( 899659297),
      UINT32_C( 800601470),
      UINT32_C(4243057777),
      UINT32_C(2589801649),
      UINT32_C(1093083275),
      UINT32_C( 969545329),
      UINT32_C( 154996236),
      UINT32_C(2940729031),
      UINT32_C( 598365436),
      UINT32_C(1659375884),
      UINT32_C( 204269667),
      }
    },
    { { UINT32_C(3268771652), UINT32_C( 653364916), UINT32_C(2959063972), UINT32_C(1578321869) },
      { UINT32_C(1930452994), UINT32_C(1500510029), UINT32_C(1751297285), UINT32_C(3648360085) },
      { UINT32_C(3264956942), UINT32_C(2095615192), UINT32_C( 355288904), UINT32_C(2440249487) },
      { UINT32_C(3976496032), UINT32_C(2135389050), UINT32_C(3051923744), UINT32_C(1183735096) },
      {
      UINT32_C(3268771652),
      UINT32_C(1930452994),
      UINT32_C(3264956942),
      UINT32_C(3976496032),
      UINT32_C( 653364916),
      UINT32_C(1500510029),
      UINT32_C(2095615192),
      UINT32_C(2135389050),
      UINT32_C(2959063972),
      UINT32_C(1751297285),
      UINT32_C( 355288904),
      UINT32_C(3051923744),
      UINT32_C(1578321869),
      UINT32_C(3648360085),
      UINT32_C(2440249487),
      UINT32_C(1183735096),
      }
    },
    { { UINT32_C(2148018599), UINT32_C(4277989814), UINT32_C(3339921720), UINT32_C( 173573737) },
      { UINT32_C(2214026249), UINT32_C(4026678992), UINT32_C( 547810024), UINT32_C(4016452679) },
      { UINT32_C( 342847070), UINT32_C(2551343967), UINT32_C(4267648405), UINT32_C(3020470443) },
      { UINT32_C(3828809748), UINT32_C( 651508030), UINT32_C(1799781156), UINT32_C( 224046255) },
      {
      UINT32_C(2148018599),
      UINT32_C(2214026249),
      UINT32_C( 342847070),
      UINT32_C(3828809748),
      UINT32_C(4277989814),
      UINT32_C(4026678992),
      UINT32_C(2551343967),
      UINT32_C( 651508030),
      UINT32_C(3339921720),
      UINT32_C( 547810024),
      UINT32_C(4267648405),
      UINT32_C(1799781156),
      UINT32_C( 173573737),
      UINT32_C(4016452679),
      UINT32_C(3020470443),
      UINT32_C( 224046255),
      }
    },
    { { UINT32_C(2049034523), UINT32_C(3390190389), UINT32_C(  63468120), UINT32_C(1052234026) },
      { UINT32_C( 254013137), UINT32_C(1278670888), UINT32_C( 582450291), UINT32_C(1144001065) },
      { UINT32_C( 280908251), UINT32_C(3722105221), UINT32_C(1843503939), UINT32_C(1168873588) },
      { UINT32_C(2941570695), UINT32_C( 972786374), UINT32_C( 811381255), UINT32_C(2691992772) },
      {
      UINT32_C(2049034523),
      UINT32_C( 254013137),
      UINT32_C( 280908251),
      UINT32_C(2941570695),
      UINT32_C(3390190389),
      UINT32_C(1278670888),
      UINT32_C(3722105221),
      UINT32_C( 972786374),
      UINT32_C(  63468120),
      UINT32_C( 582450291),
      UINT32_C(1843503939),
      UINT32_C( 811381255),
      UINT32_C(1052234026),
      UINT32_C(1144001065),
      UINT32_C(1168873588),
      UINT32_C(2691992772),
      }
    },
    { { UINT32_C(1655714525), UINT32_C(1178635011), UINT32_C(2729648430), UINT32_C(1088905145) },
      { UINT32_C(4109318957), UINT32_C(3442338502), UINT32_C(1644005789), UINT32_C(4076957973) },
      { UINT32_C(2807411363), UINT32_C(1810732349), UINT32_C(1879941558), UINT32_C( 766571520) },
      { UINT32_C(4112621615), UINT32_C( 667045770), UINT32_C(4002004952), UINT32_C(3571550768) },
      {
      UINT32_C(1655714525),
      UINT32_C(4109318957),
      UINT32_C(2807411363),
      UINT32_C(4112621615),
      UINT32_C(1178635011),
      UINT32_C(3442338502),
      UINT32_C(1810732349),
      UINT32_C( 667045770),
      UINT32_C(2729648430),
      UINT32_C(1644005789),
      UINT32_C(1879941558),
      UINT32_C(4002004952),
      UINT32_C(1088905145),
      UINT32_C(4076957973),
      UINT32_C( 766571520),
      UINT32_C(3571550768),
      }
    },
    { { UINT32_C(2038117948), UINT32_C(2196007116), UINT32_C( 166916361), UINT32_C( 355967973) },
      { UINT32_C(3440007235), UINT32_C(2163592615), UINT32_C(3178135180), UINT32_C(1167150856) },
      { UINT32_C(1371409541), UINT32_C(2127864692), UINT32_C(2055718548), UINT32_C(2895101545) },
      { UINT32_C(3195705623), UINT32_C(4080955238), UINT32_C(4121996525), UINT32_C(2168078843) },
      {
      UINT32_C(2038117948),
      UINT32_C(3440007235),
      UINT32_C(1371409541),
      UINT32_C(3195705623),
      UINT32_C(2196007116),
      UINT32_C(2163592615),
      UINT32_C(2127864692),
      UINT32_C(4080955238),
      UINT32_C( 166916361),
      UINT32_C(3178135180),
      UINT32_C(2055718548),
      UINT32_C(4121996525),
      UINT32_C( 355967973),
      UINT32_C(1167150856),
      UINT32_C(2895101545),
      UINT32_C(2168078843),
      }
    },
    { { UINT32_C(3251829069), UINT32_C( 809477788), UINT32_C(3601516397), UINT32_C(2625845637) },
      { UINT32_C( 962330067), UINT32_C(1496095084), UINT32_C(1095687238), UINT32_C(1791133981) },
      { UINT32_C( 506238338), UINT32_C(2823711547), UINT32_C(3095394610), UINT32_C(  89391666) },
      { UINT32_C(1799335935), UINT32_C(2412014409), UINT32_C(1708134984), UINT32_C( 500208539) },
      {
      UINT32_C(3251829069),
      UINT32_C( 962330067),
      UINT32_C( 506238338),
      UINT32_C(1799335935),
      UINT32_C( 809477788),
      UINT32_C(1496095084),
      UINT32_C(2823711547),
      UINT32_C(2412014409),
      UINT32_C(3601516397),
      UINT32_C(1095687238),
      UINT32_C(3095394610),
      UINT32_C(1708134984),
      UINT32_C(2625845637),
      UINT32_C(1791133981),
      UINT32_C(  89391666),
      UINT32_C( 500208539),
      }
    },
    { { UINT32_C(1664875560), UINT32_C(2584513127), UINT32_C(3042085763), UINT32_C(2361108109) },
      { UINT32_C(2683828822), UINT32_C(2905520997), UINT32_C(1762918093), UINT32_C(3112625041) },
      { UINT32_C(1176355551), UINT32_C(3487574348), UINT32_C(1099182772), UINT32_C( 801980377) },
      { UINT32_C(2681127993), UINT32_C(1280113791), UINT32_C(2360696826), UINT32_C( 558185538) },
      {
      UINT32_C(1664875560),
      UINT32_C(2683828822),
      UINT32_C(1176355551),
      UINT32_C(2681127993),
      UINT32_C(2584513127),
      UINT32_C(2905520997),
      UINT32_C(3487574348),
      UINT32_C(1280113791),
      UINT32_C(3042085763),
      UINT32_C(1762918093),
      UINT32_C(1099182772),
      UINT32_C(2360696826),
      UINT32_C(2361108109),
      UINT32_C(3112625041),
      UINT32_C( 801980377),
      UINT32_C( 558185538),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x4_t r_ = { { simde_vld1q_u32(test_vec[i].r0),
                                simde_vld1q_u32(test_vec[i].r1),
                                simde_vld1q_u32(test_vec[i].r2),
                                simde_vld1q_u32(test_vec[i].r3), } };

    uint32_t a_[16];
    simde_vst4q_u32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4q_u32(a_);
    simde_test_arm_neon_assert_equal_u32x4(r_.val[0], simde_vld1q_u32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u32x4(r_.val[1], simde_vld1q_u32(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u32x4(r_.val[2], simde_vld1q_u32(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (size_t i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a0 = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t a1 = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t a2 = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t a3 = simde_test_arm_neon_random_u32x4();
    simde_uint32x4x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_u32x4(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    uint32_t buf[16];
    simde_vst4q_u32(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])); j++) {
      simde_test_codegen_write_u32(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

static int
test_simde_vst4q_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r0[2];
    uint64_t r1[2];
    uint64_t r2[2];
    uint64_t r3[2];
    uint64_t a[8];
  } test_vec[] = {
    { { UINT64_C(10037403692393182480), UINT64_C( 8361711425298189690) },
      { UINT64_C(12218369200614863841), UINT64_C( 2381342151739302120) },
      { UINT64_C(15453747378136373104), UINT64_C( 6105776580658310922) },
      { UINT64_C( 4376731735500977414), UINT64_C( 8959977481816756774) },
      {
      UINT64_C(10037403692393182480),
      UINT64_C(12218369200614863841),
      UINT64_C(15453747378136373104),
      UINT64_C( 4376731735500977414),
      UINT64_C( 8361711425298189690),
      UINT64_C( 2381342151739302120),
      UINT64_C( 6105776580658310922),
      UINT64_C( 8959977481816756774),
      }
    },
    { { UINT64_C(10431987683485534611), UINT64_C(16741170512735555212) },
      { UINT64_C( 8510035628354374282), UINT64_C( 1734736352801278346) },
      { UINT64_C(16421474816743668430), UINT64_C(15880597538443869594) },
      { UINT64_C(11675532657163853633), UINT64_C( 9779932425969316892) },
      {
      UINT64_C(10431987683485534611),
      UINT64_C( 8510035628354374282),
      UINT64_C(16421474816743668430),
      UINT64_C(11675532657163853633),
      UINT64_C(16741170512735555212),
      UINT64_C( 1734736352801278346),
      UINT64_C(15880597538443869594),
      UINT64_C( 9779932425969316892),
      }
    },
    { { UINT64_C( 2738962131928727751), UINT64_C( 6749212612852049276) },
      { UINT64_C( 5989212698123854948), UINT64_C( 7703879554845398697) },
      { UINT64_C(    8878023709869165), UINT64_C( 3019797439513018479) },
      { UINT64_C( 8387887008481400541), UINT64_C( 8441644595801381657) },
      {
      UINT64_C( 2738962131928727751),
      UINT64_C( 5989212698123854948),
      UINT64_C(    8878023709869165),
      UINT64_C( 8387887008481400541),
      UINT64_C( 6749212612852049276),
      UINT64_C( 7703879554845398697),
      UINT64_C( 3019797439513018479),
      UINT64_C( 8441644595801381657),
      }
    },
    { { UINT64_C(12107801399286214275), UINT64_C( 3115396163888797005) },
      { UINT64_C(13633423723477328371), UINT64_C( 5512018679744235777) },
      { UINT64_C(14352790015444249677), UINT64_C( 8262441203209495344) },
      { UINT64_C(10473512980685384184), UINT64_C(13727844063193584237) },
      {
      UINT64_C(12107801399286214275),
      UINT64_C(13633423723477328371),
      UINT64_C(14352790015444249677),
      UINT64_C(10473512980685384184),
      UINT64_C( 3115396163888797005),
      UINT64_C( 5512018679744235777),
      UINT64_C( 8262441203209495344),
      UINT64_C(13727844063193584237),
      }
    },
    { { UINT64_C( 7009417625986258438), UINT64_C( 3443434260875124951) },
      { UINT64_C(14669389872461773427), UINT64_C( 5703111053441904630) },
      { UINT64_C(13109158135934642779), UINT64_C(14527439590170348853) },
      { UINT64_C( 9293285077180769999), UINT64_C(15791886936142510736) },
      {
      UINT64_C( 7009417625986258438),
      UINT64_C(14669389872461773427),
      UINT64_C(13109158135934642779),
      UINT64_C( 9293285077180769999),
      UINT64_C( 3443434260875124951),
      UINT64_C( 5703111053441904630),
      UINT64_C(14527439590170348853),
      UINT64_C(15791886936142510736),
      }
    },
    { { UINT64_C( 4686933348686755703), UINT64_C(13493428713541211938) },
      { UINT64_C(   52883688490798768), UINT64_C( 2825448768405086939) },
      { UINT64_C( 1461005702183886329), UINT64_C(17170201446903051424) },
      { UINT64_C(17099573023644070109), UINT64_C( 2403935012266714758) },
      {
      UINT64_C( 4686933348686755703),
      UINT64_C(   52883688490798768),
      UINT64_C( 1461005702183886329),
      UINT64_C(17099573023644070109),
      UINT64_C(13493428713541211938),
      UINT64_C( 2825448768405086939),
      UINT64_C(17170201446903051424),
      UINT64_C( 2403935012266714758),
      }
    },
    { { UINT64_C(  153805605195667739), UINT64_C( 6669222462536724321) },
      { UINT64_C( 2235463927463523847), UINT64_C(16674210156985535772) },
      { UINT64_C( 6624539943386844555), UINT64_C( 6602708424234597831) },
      { UINT64_C( 6771013884191132222), UINT64_C( 9905958744852942022) },
      {
      UINT64_C(  153805605195667739),
      UINT64_C( 2235463927463523847),
      UINT64_C( 6624539943386844555),
      UINT64_C( 6771013884191132222),
      UINT64_C( 6669222462536724321),
      UINT64_C(16674210156985535772),
      UINT64_C( 6602708424234597831),
      UINT64_C( 9905958744852942022),
      }
    },
    { { UINT64_C( 5542635390721486485), UINT64_C(12506834188639594210) },
      { UINT64_C( 4907653102754399614), UINT64_C( 6579846770763152841) },
      { UINT64_C(  977235125474150077), UINT64_C(15264904023753630140) },
      { UINT64_C(11717712954493328602), UINT64_C( 9262982781576246122) },
      {
      UINT64_C( 5542635390721486485),
      UINT64_C( 4907653102754399614),
      UINT64_C(  977235125474150077),
      UINT64_C(11717712954493328602),
      UINT64_C(12506834188639594210),
      UINT64_C( 6579846770763152841),
      UINT64_C(15264904023753630140),
      UINT64_C( 9262982781576246122),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x4_t r_ = { { simde_vld1q_u64(test_vec[i].r0),
                                simde_vld1q_u64(test_vec[i].r1),
                                simde_vld1q_u64(test_vec[i].r2),
                                simde_vld1q_u64(test_vec[i].r3), } };

    uint64_t a_[8];
    simde_vst4q_u64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld4q_u64(a_);
    simde_test_arm_neon_assert_equal_u64x2(r_.val[0], simde_vld1q_u64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u64x2(r_.val[1], simde_vld1q_u64(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u64x2(r_.val[2], simde_vld1q_u64(test_vec[i].r2));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (size_t i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a0 = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t a1 = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t a2 = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t a3 = simde_test_arm_neon_random_u64x2();
    simde_uint64x2x4_t a = { { a0, a1, a2, a3 } };
    simde_test_arm_neon_write_u64x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, a3, SIMDE_TEST_VEC_POS_MIDDLE);
    uint64_t buf[8];
    simde_vst4q_u64(buf, a);

    printf("      {\n");
    for (size_t j = 0; j < (sizeof(buf) / sizeof(buf[0])); j++) {
      simde_test_codegen_write_u64(2, buf[j], SIMDE_TEST_VEC_POS_MIDDLE);
    }
    printf("      }\n    },\n");
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst4q_u64)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
