#define SIMDE_TEST_ARM_NEON_INSN st3

#include "test-neon.h"
#include "../../../simde/arm/neon/st3.h"
#include "../../../simde/arm/neon/ld3.h"
#include "../../../simde/arm/neon/get_lane.h"

/* Implementor notes (seanptmaher):
 *
 * the way that I'm opting to test this is that I'll have a r[3][x]
 * array of vectors, as well as a flat buffer of results. The flat
 * buffer contains the expected result of a st3, done on arm hardware,
 * which will be compared against a st3 done at test time.
 *
 * To test the ld3, the stored st3 will be ld3'd, and then
 * individually compared against the r[3][x] vector.
 */

#if !defined(SIMDE_BUG_INTEL_857088)
static int
test_simde_vst3_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r0[2];
    simde_float32 r1[2];
    simde_float32 r2[2];
    simde_float32 a[6];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   966.95), SIMDE_FLOAT32_C(  -826.32) },
      { SIMDE_FLOAT32_C(  -900.75), SIMDE_FLOAT32_C(   795.70) },
      { SIMDE_FLOAT32_C(  -772.41), SIMDE_FLOAT32_C(   343.84) },
      {
      SIMDE_FLOAT32_C(   966.95),
      SIMDE_FLOAT32_C(  -900.75),
      SIMDE_FLOAT32_C(  -772.41),
      SIMDE_FLOAT32_C(  -826.32),
      SIMDE_FLOAT32_C(   795.70),
      SIMDE_FLOAT32_C(   343.84),
      }
    },
    { { SIMDE_FLOAT32_C(  -783.51), SIMDE_FLOAT32_C(   493.54) },
      { SIMDE_FLOAT32_C(  -971.39), SIMDE_FLOAT32_C(   895.53) },
      { SIMDE_FLOAT32_C(   208.75), SIMDE_FLOAT32_C(   253.35) },
      {
      SIMDE_FLOAT32_C(  -783.51),
      SIMDE_FLOAT32_C(  -971.39),
      SIMDE_FLOAT32_C(   208.75),
      SIMDE_FLOAT32_C(   493.54),
      SIMDE_FLOAT32_C(   895.53),
      SIMDE_FLOAT32_C(   253.35),
      }
    },
    { { SIMDE_FLOAT32_C(   867.44), SIMDE_FLOAT32_C(   363.06) },
      { SIMDE_FLOAT32_C(   749.57), SIMDE_FLOAT32_C(  -109.51) },
      { SIMDE_FLOAT32_C(   -81.12), SIMDE_FLOAT32_C(  -786.46) },
      {
      SIMDE_FLOAT32_C(   867.44),
      SIMDE_FLOAT32_C(   749.57),
      SIMDE_FLOAT32_C(   -81.12),
      SIMDE_FLOAT32_C(   363.06),
      SIMDE_FLOAT32_C(  -109.51),
      SIMDE_FLOAT32_C(  -786.46),
      }
    },
    { { SIMDE_FLOAT32_C(   687.74), SIMDE_FLOAT32_C(  -617.77) },
      { SIMDE_FLOAT32_C(   482.69), SIMDE_FLOAT32_C(   219.53) },
      { SIMDE_FLOAT32_C(   980.32), SIMDE_FLOAT32_C(  -243.91) },
      {
      SIMDE_FLOAT32_C(   687.74),
      SIMDE_FLOAT32_C(   482.69),
      SIMDE_FLOAT32_C(   980.32),
      SIMDE_FLOAT32_C(  -617.77),
      SIMDE_FLOAT32_C(   219.53),
      SIMDE_FLOAT32_C(  -243.91),
      }
    },
    { { SIMDE_FLOAT32_C(  -516.59), SIMDE_FLOAT32_C(  -483.00) },
      { SIMDE_FLOAT32_C(   444.86), SIMDE_FLOAT32_C(   663.90) },
      { SIMDE_FLOAT32_C(   259.84), SIMDE_FLOAT32_C(  -602.70) },
      {
      SIMDE_FLOAT32_C(  -516.59),
      SIMDE_FLOAT32_C(   444.86),
      SIMDE_FLOAT32_C(   259.84),
      SIMDE_FLOAT32_C(  -483.00),
      SIMDE_FLOAT32_C(   663.90),
      SIMDE_FLOAT32_C(  -602.70),
      }
    },
    { { SIMDE_FLOAT32_C(   -83.32), SIMDE_FLOAT32_C(   226.79) },
      { SIMDE_FLOAT32_C(  -429.02), SIMDE_FLOAT32_C(    15.93) },
      { SIMDE_FLOAT32_C(    22.49), SIMDE_FLOAT32_C(  -201.43) },
      {
      SIMDE_FLOAT32_C(   -83.32),
      SIMDE_FLOAT32_C(  -429.02),
      SIMDE_FLOAT32_C(    22.49),
      SIMDE_FLOAT32_C(   226.79),
      SIMDE_FLOAT32_C(    15.93),
      SIMDE_FLOAT32_C(  -201.43),
      }
    },
    { { SIMDE_FLOAT32_C(  -640.23), SIMDE_FLOAT32_C(   238.98) },
      { SIMDE_FLOAT32_C(  -707.89), SIMDE_FLOAT32_C(  -611.62) },
      { SIMDE_FLOAT32_C(   134.51), SIMDE_FLOAT32_C(   500.86) },
      {
      SIMDE_FLOAT32_C(  -640.23),
      SIMDE_FLOAT32_C(  -707.89),
      SIMDE_FLOAT32_C(   134.51),
      SIMDE_FLOAT32_C(   238.98),
      SIMDE_FLOAT32_C(  -611.62),
      SIMDE_FLOAT32_C(   500.86),
      }
    },
    { { SIMDE_FLOAT32_C(   641.73), SIMDE_FLOAT32_C(     1.95) },
      { SIMDE_FLOAT32_C(  -136.08), SIMDE_FLOAT32_C(   391.30) },
      { SIMDE_FLOAT32_C(   892.44), SIMDE_FLOAT32_C(   782.80) },
      {
      SIMDE_FLOAT32_C(   641.73),
      SIMDE_FLOAT32_C(  -136.08),
      SIMDE_FLOAT32_C(   892.44),
      SIMDE_FLOAT32_C(     1.95),
      SIMDE_FLOAT32_C(   391.30),
      SIMDE_FLOAT32_C(   782.80),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x3_t r_ = { { simde_vld1_f32(test_vec[i].r0),
                                 simde_vld1_f32(test_vec[i].r1),
                                 simde_vld1_f32(test_vec[i].r2), } };

    simde_float32 a_[6];
    simde_vst3_f32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3_f32(a_);
    simde_test_arm_neon_assert_equal_f32x2(r_.val[0], simde_vld1_f32(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f32x2(r_.val[1], simde_vld1_f32(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f32x2(r_.val[2], simde_vld1_f32(test_vec[i].r2), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a0 = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t a1 = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t a2 = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_f32x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float32_t buf[6];
    simde_vst3_f32(buf, a);

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
test_simde_vst3_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r0[1];
    simde_float64 r1[1];
    simde_float64 r2[1];
    simde_float64 a[3];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -319.19) },
      { SIMDE_FLOAT64_C(   569.35) },
      { SIMDE_FLOAT64_C(  -226.94) },
      {
      SIMDE_FLOAT64_C(  -319.19),
      SIMDE_FLOAT64_C(   569.35),
      SIMDE_FLOAT64_C(  -226.94),
      }
    },
    { { SIMDE_FLOAT64_C(   -79.23) },
      { SIMDE_FLOAT64_C(  -856.19) },
      { SIMDE_FLOAT64_C(   982.37) },
      {
      SIMDE_FLOAT64_C(   -79.23),
      SIMDE_FLOAT64_C(  -856.19),
      SIMDE_FLOAT64_C(   982.37),
      }
    },
    { { SIMDE_FLOAT64_C(  -330.57) },
      { SIMDE_FLOAT64_C(   730.79) },
      { SIMDE_FLOAT64_C(  -392.36) },
      {
      SIMDE_FLOAT64_C(  -330.57),
      SIMDE_FLOAT64_C(   730.79),
      SIMDE_FLOAT64_C(  -392.36),
      }
    },
    { { SIMDE_FLOAT64_C(  -114.08) },
      { SIMDE_FLOAT64_C(  -298.63) },
      { SIMDE_FLOAT64_C(   209.96) },
      {
      SIMDE_FLOAT64_C(  -114.08),
      SIMDE_FLOAT64_C(  -298.63),
      SIMDE_FLOAT64_C(   209.96),
      }
    },
    { { SIMDE_FLOAT64_C(  -867.54) },
      { SIMDE_FLOAT64_C(  -281.79) },
      { SIMDE_FLOAT64_C(   780.67) },
      {
      SIMDE_FLOAT64_C(  -867.54),
      SIMDE_FLOAT64_C(  -281.79),
      SIMDE_FLOAT64_C(   780.67),
      }
    },
    { { SIMDE_FLOAT64_C(   665.37) },
      { SIMDE_FLOAT64_C(   109.67) },
      { SIMDE_FLOAT64_C(   882.86) },
      {
      SIMDE_FLOAT64_C(   665.37),
      SIMDE_FLOAT64_C(   109.67),
      SIMDE_FLOAT64_C(   882.86),
      }
    },
    { { SIMDE_FLOAT64_C(    -7.69) },
      { SIMDE_FLOAT64_C(  -441.62) },
      { SIMDE_FLOAT64_C(   205.44) },
      {
      SIMDE_FLOAT64_C(    -7.69),
      SIMDE_FLOAT64_C(  -441.62),
      SIMDE_FLOAT64_C(   205.44),
      }
    },
    { { SIMDE_FLOAT64_C(   761.86) },
      { SIMDE_FLOAT64_C(   259.74) },
      { SIMDE_FLOAT64_C(   953.99) },
      {
      SIMDE_FLOAT64_C(   761.86),
      SIMDE_FLOAT64_C(   259.74),
      SIMDE_FLOAT64_C(   953.99),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x3_t r_ = { { simde_vld1_f64(test_vec[i].r0),
                                 simde_vld1_f64(test_vec[i].r1),
                                 simde_vld1_f64(test_vec[i].r2), } };

    simde_float64_t a_[3];
    simde_vst3_f64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3_f64(a_);
    simde_test_arm_neon_assert_equal_f64x1(r_.val[0], simde_vld1_f64(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f64x1(r_.val[1], simde_vld1_f64(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f64x1(r_.val[2], simde_vld1_f64(test_vec[i].r2), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a0 = simde_test_arm_neon_random_f64x1(-1000.0f, 1000.0f);
    simde_float64x1_t a1 = simde_test_arm_neon_random_f64x1(-1000.0f, 1000.0f);
    simde_float64x1_t a2 = simde_test_arm_neon_random_f64x1(-1000.0f, 1000.0f);
    simde_float64x1x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_f64x1(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float64_t buf[3];
    simde_vst3_f64(buf, a);

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
test_simde_vst3_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r0[8];
    int8_t r1[8];
    int8_t r2[8];
    int8_t a[24];
  } test_vec[] = {
    { { -INT8_C( 125), -INT8_C(  82), -INT8_C(  51), -INT8_C( 114),  INT8_C( 105),  INT8_C(   0), -INT8_C(  73),  INT8_C( 100) },
      {  INT8_C(  63), -INT8_C(  12),  INT8_C(  81),  INT8_C(  72), -INT8_C(  10),  INT8_C(  76),  INT8_C(  20), -INT8_C(  89) },
      { -INT8_C(  63), -INT8_C( 118),  INT8_C(  94),  INT8_C(  42), -INT8_C(  88), -INT8_C(  57), -INT8_C(   6),  INT8_C(  16) },
      {
      -INT8_C( 125),
       INT8_C(  63),
      -INT8_C(  63),
      -INT8_C(  82),
      -INT8_C(  12),
      -INT8_C( 118),
      -INT8_C(  51),
       INT8_C(  81),
       INT8_C(  94),
      -INT8_C( 114),
       INT8_C(  72),
       INT8_C(  42),
       INT8_C( 105),
      -INT8_C(  10),
      -INT8_C(  88),
       INT8_C(   0),
       INT8_C(  76),
      -INT8_C(  57),
      -INT8_C(  73),
       INT8_C(  20),
      -INT8_C(   6),
       INT8_C( 100),
      -INT8_C(  89),
       INT8_C(  16),
      }
    },
    { {  INT8_C(  37),  INT8_C(  25), -INT8_C(  10),  INT8_C(  35),  INT8_C(  77),  INT8_C(  32), -INT8_C(  94), -INT8_C(  48) },
      { -INT8_C(  49),  INT8_C( 111),  INT8_C(  94),  INT8_C(  56),  INT8_C( 112),  INT8_C(  21), -INT8_C( 100), -INT8_C(  81) },
      {  INT8_C(   9), -INT8_C(  18), -INT8_C(   9), -INT8_C(   1),  INT8_C(  58),  INT8_C(  12), -INT8_C(  90), -INT8_C(   4) },
      {
       INT8_C(  37),
      -INT8_C(  49),
       INT8_C(   9),
       INT8_C(  25),
       INT8_C( 111),
      -INT8_C(  18),
      -INT8_C(  10),
       INT8_C(  94),
      -INT8_C(   9),
       INT8_C(  35),
       INT8_C(  56),
      -INT8_C(   1),
       INT8_C(  77),
       INT8_C( 112),
       INT8_C(  58),
       INT8_C(  32),
       INT8_C(  21),
       INT8_C(  12),
      -INT8_C(  94),
      -INT8_C( 100),
      -INT8_C(  90),
      -INT8_C(  48),
      -INT8_C(  81),
      -INT8_C(   4),
      }
    },
    { { -INT8_C( 106),  INT8_C(   5),  INT8_C(  38),  INT8_C(  63), -INT8_C(  52),  INT8_C(  32),  INT8_C(  79), -INT8_C(  14) },
      {  INT8_C(  57),  INT8_C(  69),  INT8_C(  21), -INT8_C( 122),  INT8_C( 102), -INT8_C(  73),  INT8_C(  86),  INT8_C(  53) },
      {  INT8_C(  39), -INT8_C(  76),  INT8_C( 109), -INT8_C( 105), -INT8_C(  54),  INT8_C(  10),  INT8_C(  70), -INT8_C(  45) },
      {
      -INT8_C( 106),
       INT8_C(  57),
       INT8_C(  39),
       INT8_C(   5),
       INT8_C(  69),
      -INT8_C(  76),
       INT8_C(  38),
       INT8_C(  21),
       INT8_C( 109),
       INT8_C(  63),
      -INT8_C( 122),
      -INT8_C( 105),
      -INT8_C(  52),
       INT8_C( 102),
      -INT8_C(  54),
       INT8_C(  32),
      -INT8_C(  73),
       INT8_C(  10),
       INT8_C(  79),
       INT8_C(  86),
       INT8_C(  70),
      -INT8_C(  14),
       INT8_C(  53),
      -INT8_C(  45),
      }
    },
    { { -INT8_C(   8),  INT8_C(  62), -INT8_C(  45),  INT8_C(  50),  INT8_C(  74),  INT8_C( 121),  INT8_C(  46), -INT8_C(  32) },
      {  INT8_C( 126),  INT8_C(  84),  INT8_C(  31),  INT8_C(  75),  INT8_C( 116),  INT8_C( 111),  INT8_C(  61), -INT8_C(  83) },
      { -INT8_C(  76),  INT8_C(  82),  INT8_C(  51),  INT8_C(  26),  INT8_C(  10), -INT8_C( 119),  INT8_C(  79),  INT8_C(  49) },
      {
      -INT8_C(   8),
       INT8_C( 126),
      -INT8_C(  76),
       INT8_C(  62),
       INT8_C(  84),
       INT8_C(  82),
      -INT8_C(  45),
       INT8_C(  31),
       INT8_C(  51),
       INT8_C(  50),
       INT8_C(  75),
       INT8_C(  26),
       INT8_C(  74),
       INT8_C( 116),
       INT8_C(  10),
       INT8_C( 121),
       INT8_C( 111),
      -INT8_C( 119),
       INT8_C(  46),
       INT8_C(  61),
       INT8_C(  79),
      -INT8_C(  32),
      -INT8_C(  83),
       INT8_C(  49),
      }
    },
    { {  INT8_C(  62), -INT8_C(  67), -INT8_C(  56),  INT8_C(   8), -INT8_C(  57),  INT8_C(  14), -INT8_C(  37), -INT8_C(  65) },
      {  INT8_C(  76), -INT8_C(  82), -INT8_C(  15), -INT8_C( 106),  INT8_C(  40),  INT8_C(  32),  INT8_C( 119), -INT8_C(  90) },
      {  INT8_C( 116), -INT8_C( 106), -INT8_C(  15), -INT8_C(  23),  INT8_C(   5),  INT8_C(  46), -INT8_C( 106), -INT8_C(  70) },
      {
       INT8_C(  62),
       INT8_C(  76),
       INT8_C( 116),
      -INT8_C(  67),
      -INT8_C(  82),
      -INT8_C( 106),
      -INT8_C(  56),
      -INT8_C(  15),
      -INT8_C(  15),
       INT8_C(   8),
      -INT8_C( 106),
      -INT8_C(  23),
      -INT8_C(  57),
       INT8_C(  40),
       INT8_C(   5),
       INT8_C(  14),
       INT8_C(  32),
       INT8_C(  46),
      -INT8_C(  37),
       INT8_C( 119),
      -INT8_C( 106),
      -INT8_C(  65),
      -INT8_C(  90),
      -INT8_C(  70),
      }
    },
    { { -INT8_C( 127), -INT8_C(  54), -INT8_C(  44), -INT8_C( 117),  INT8_C(  83),  INT8_C(  36), -INT8_C(  68), -INT8_C( 111) },
      { -INT8_C(  31), -INT8_C( 124), -INT8_C( 103), -INT8_C(  88), -INT8_C( 110),  INT8_C( 117),  INT8_C( 103), -INT8_C(  33) },
      {  INT8_C(  35),  INT8_C(  88),  INT8_C( 117),  INT8_C(  75),  INT8_C( 120), -INT8_C(  20), -INT8_C(  14), -INT8_C(  19) },
      {
      -INT8_C( 127),
      -INT8_C(  31),
       INT8_C(  35),
      -INT8_C(  54),
      -INT8_C( 124),
       INT8_C(  88),
      -INT8_C(  44),
      -INT8_C( 103),
       INT8_C( 117),
      -INT8_C( 117),
      -INT8_C(  88),
       INT8_C(  75),
       INT8_C(  83),
      -INT8_C( 110),
       INT8_C( 120),
       INT8_C(  36),
       INT8_C( 117),
      -INT8_C(  20),
      -INT8_C(  68),
       INT8_C( 103),
      -INT8_C(  14),
      -INT8_C( 111),
      -INT8_C(  33),
      -INT8_C(  19),
      }
    },
    { { -INT8_C( 125), -INT8_C(  29), -INT8_C(  42), -INT8_C( 120),  INT8_C(  18),  INT8_C( 108),  INT8_C(  66), -INT8_C( 109) },
      {  INT8_C(  54),  INT8_C(  23),  INT8_C(  30), -INT8_C( 118),  INT8_C(  59), -INT8_C(  38),  INT8_C(  27),  INT8_C(  28) },
      {  INT8_C(  94), -INT8_C(  75), -INT8_C(  60), -INT8_C(  16),  INT8_C(  42),  INT8_C(  43), -INT8_C(  49),  INT8_C(  77) },
      {
      -INT8_C( 125),
       INT8_C(  54),
       INT8_C(  94),
      -INT8_C(  29),
       INT8_C(  23),
      -INT8_C(  75),
      -INT8_C(  42),
       INT8_C(  30),
      -INT8_C(  60),
      -INT8_C( 120),
      -INT8_C( 118),
      -INT8_C(  16),
       INT8_C(  18),
       INT8_C(  59),
       INT8_C(  42),
       INT8_C( 108),
      -INT8_C(  38),
       INT8_C(  43),
       INT8_C(  66),
       INT8_C(  27),
      -INT8_C(  49),
      -INT8_C( 109),
       INT8_C(  28),
       INT8_C(  77),
      }
    },
    { { -INT8_C( 125),  INT8_C(  69), -INT8_C( 103), -INT8_C(   4),  INT8_C(  49), -INT8_C( 117), -INT8_C(  23), -INT8_C(  76) },
      {  INT8_C( 110), -INT8_C(  65),  INT8_C(  61),      INT8_MIN,  INT8_C(  43),      INT8_MAX,  INT8_C(  19),  INT8_C(  98) },
      { -INT8_C( 106),  INT8_C(  49), -INT8_C(  20), -INT8_C(  47),  INT8_C(  11),  INT8_C(   7), -INT8_C(  19),  INT8_C( 105) },
      {
      -INT8_C( 125),
       INT8_C( 110),
      -INT8_C( 106),
       INT8_C(  69),
      -INT8_C(  65),
       INT8_C(  49),
      -INT8_C( 103),
       INT8_C(  61),
      -INT8_C(  20),
      -INT8_C(   4),
           INT8_MIN,
      -INT8_C(  47),
       INT8_C(  49),
       INT8_C(  43),
       INT8_C(  11),
      -INT8_C( 117),
           INT8_MAX,
       INT8_C(   7),
      -INT8_C(  23),
       INT8_C(  19),
      -INT8_C(  19),
      -INT8_C(  76),
       INT8_C(  98),
       INT8_C( 105),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x3_t r_ = { { simde_vld1_s8(test_vec[i].r0),
                              simde_vld1_s8(test_vec[i].r1),
                              simde_vld1_s8(test_vec[i].r2), } };
    int8_t a_[24];
    simde_vst3_s8(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(a_)));

    r_ = simde_vld3_s8(a_);
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
    simde_int8x8x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_i8x8(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    int8_t buf[24];
    simde_vst3_s8(buf, a);

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
test_simde_vst3_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r0[4];
    int16_t r1[4];
    int16_t r2[4];
    int16_t a[12];
  } test_vec[] = {
    { { -INT16_C( 12961), -INT16_C(  6596),  INT16_C( 18449),  INT16_C(  9642) },
      { -INT16_C( 26186),  INT16_C(  4954), -INT16_C( 25970),  INT16_C( 13983) },
      {  INT16_C( 14092), -INT16_C( 14144),  INT16_C(   792),  INT16_C(  6146) },
      {
      -INT16_C( 12961),
      -INT16_C( 26186),
       INT16_C( 14092),
      -INT16_C(  6596),
       INT16_C(  4954),
      -INT16_C( 14144),
       INT16_C( 18449),
      -INT16_C( 25970),
       INT16_C(   792),
       INT16_C(  9642),
       INT16_C( 13983),
       INT16_C(  6146),
      }
    },
    { { -INT16_C( 19593), -INT16_C(  4112), -INT16_C(  6692),  INT16_C( 15284) },
      { -INT16_C(  3918), -INT16_C( 15327), -INT16_C( 13512), -INT16_C(  4375) },
      {  INT16_C( 17252), -INT16_C(  3583), -INT16_C( 24355), -INT16_C(  5592) },
      {
      -INT16_C( 19593),
      -INT16_C(  3918),
       INT16_C( 17252),
      -INT16_C(  4112),
      -INT16_C( 15327),
      -INT16_C(  3583),
      -INT16_C(  6692),
      -INT16_C( 13512),
      -INT16_C( 24355),
       INT16_C( 15284),
      -INT16_C(  4375),
      -INT16_C(  5592),
      }
    },
    { { -INT16_C(  5673), -INT16_C(  3918), -INT16_C( 19220),  INT16_C( 25352) },
      { -INT16_C(  1945),  INT16_C( 17234),  INT16_C(  1757), -INT16_C( 28545) },
      { -INT16_C( 24330),  INT16_C( 11860),  INT16_C( 15724), -INT16_C( 12260) },
      {
      -INT16_C(  5673),
      -INT16_C(  1945),
      -INT16_C( 24330),
      -INT16_C(  3918),
       INT16_C( 17234),
       INT16_C( 11860),
      -INT16_C( 19220),
       INT16_C(  1757),
       INT16_C( 15724),
       INT16_C( 25352),
      -INT16_C( 28545),
      -INT16_C( 12260),
      }
    },
    { {  INT16_C(  7552),  INT16_C( 24003), -INT16_C(  5186), -INT16_C( 27321) },
      { -INT16_C(  1580), -INT16_C( 15995), -INT16_C( 29267),  INT16_C(  5156) },
      {  INT16_C( 30598),  INT16_C( 25432), -INT16_C( 10371),  INT16_C( 29939) },
      {
       INT16_C(  7552),
      -INT16_C(  1580),
       INT16_C( 30598),
       INT16_C( 24003),
      -INT16_C( 15995),
       INT16_C( 25432),
      -INT16_C(  5186),
      -INT16_C( 29267),
      -INT16_C( 10371),
      -INT16_C( 27321),
       INT16_C(  5156),
       INT16_C( 29939),
      }
    },
    { {  INT16_C( 18295), -INT16_C(  7262), -INT16_C( 16508),  INT16_C(  1204) },
      {  INT16_C( 30684), -INT16_C( 26014), -INT16_C( 22174),  INT16_C( 14128) },
      { -INT16_C( 19037),  INT16_C( 20728),  INT16_C(  7235), -INT16_C( 13979) },
      {
       INT16_C( 18295),
       INT16_C( 30684),
      -INT16_C( 19037),
      -INT16_C(  7262),
      -INT16_C( 26014),
       INT16_C( 20728),
      -INT16_C( 16508),
      -INT16_C( 22174),
       INT16_C(  7235),
       INT16_C(  1204),
       INT16_C( 14128),
      -INT16_C( 13979),
      }
    },
    { { -INT16_C( 17005),  INT16_C(  4396),  INT16_C(  8340),  INT16_C(  2949) },
      {  INT16_C( 10087), -INT16_C(  4881), -INT16_C( 23578), -INT16_C( 15376) },
      {  INT16_C( 21018),  INT16_C( 31837), -INT16_C( 29188), -INT16_C( 24653) },
      {
      -INT16_C( 17005),
       INT16_C( 10087),
       INT16_C( 21018),
       INT16_C(  4396),
      -INT16_C(  4881),
       INT16_C( 31837),
       INT16_C(  8340),
      -INT16_C( 23578),
      -INT16_C( 29188),
       INT16_C(  2949),
      -INT16_C( 15376),
      -INT16_C( 24653),
      }
    },
    { { -INT16_C( 21693), -INT16_C( 30993),  INT16_C( 21704),  INT16_C( 23375) },
      {  INT16_C( 31505), -INT16_C( 23188), -INT16_C(  3685),  INT16_C(   945) },
      { -INT16_C( 24551), -INT16_C(    17), -INT16_C(  8381),  INT16_C( 24002) },
      {
      -INT16_C( 21693),
       INT16_C( 31505),
      -INT16_C( 24551),
      -INT16_C( 30993),
      -INT16_C( 23188),
      -INT16_C(    17),
       INT16_C( 21704),
      -INT16_C(  3685),
      -INT16_C(  8381),
       INT16_C( 23375),
       INT16_C(   945),
       INT16_C( 24002),
      }
    },
    { {  INT16_C(  8242),  INT16_C( 11993), -INT16_C( 29267), -INT16_C(  3891) },
      { -INT16_C( 17352),  INT16_C(   118), -INT16_C( 15087),  INT16_C(  8796) },
      { -INT16_C( 14271), -INT16_C(  9016),  INT16_C( 31162), -INT16_C( 11297) },
      {
       INT16_C(  8242),
      -INT16_C( 17352),
      -INT16_C( 14271),
       INT16_C( 11993),
       INT16_C(   118),
      -INT16_C(  9016),
      -INT16_C( 29267),
      -INT16_C( 15087),
       INT16_C( 31162),
      -INT16_C(  3891),
       INT16_C(  8796),
      -INT16_C( 11297),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x3_t r_ = { { simde_vld1_s16(test_vec[i].r0),
                               simde_vld1_s16(test_vec[i].r1),
                               simde_vld1_s16(test_vec[i].r2), } };

    int16_t a_[12];
    simde_vst3_s16(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3_s16(a_);
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
    simde_int16x4x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_i16x4(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    int16_t buf[12];
    simde_vst3_s16(buf, a);

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
test_simde_vst3_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r0[2];
    int32_t r1[2];
    int32_t r2[2];
    int32_t a[6];
  } test_vec[] = {
    { {  INT32_C(  1914427947),  INT32_C(  1925674776) },
      {  INT32_C(  1209568771),  INT32_C(  1487047557) },
      {  INT32_C(  1914078099), -INT32_C(   432278526) },
      {
       INT32_C(  1914427947),
       INT32_C(  1209568771),
       INT32_C(  1914078099),
       INT32_C(  1925674776),
       INT32_C(  1487047557),
      -INT32_C(   432278526),
      }
    },
    { {  INT32_C(  1941302689), -INT32_C(  1422572160) },
      {  INT32_C(   924733471), -INT32_C(   894769721) },
      { -INT32_C(   116145548), -INT32_C(   531516083) },
      {
       INT32_C(  1941302689),
       INT32_C(   924733471),
      -INT32_C(   116145548),
      -INT32_C(  1422572160),
      -INT32_C(   894769721),
      -INT32_C(   531516083),
      }
    },
    { {  INT32_C(   995256376), -INT32_C(    48132772) },
      { -INT32_C(    76491141),  INT32_C(   983999771) },
      { -INT32_C(  1116551947),  INT32_C(   512171178) },
      {
       INT32_C(   995256376),
      -INT32_C(    76491141),
      -INT32_C(  1116551947),
      -INT32_C(    48132772),
       INT32_C(   983999771),
       INT32_C(   512171178),
      }
    },
    { {  INT32_C(   722967262), -INT32_C(  2012452784) },
      {  INT32_C(   751001296),  INT32_C(  1730799084) },
      { -INT32_C(   681403717),  INT32_C(   890308671) },
      {
       INT32_C(   722967262),
       INT32_C(   751001296),
      -INT32_C(   681403717),
      -INT32_C(  2012452784),
       INT32_C(  1730799084),
       INT32_C(   890308671),
      }
    },
    { {  INT32_C(  2012382157),  INT32_C(  2106947999) },
      {  INT32_C(  1688841236), -INT32_C(   437471980) },
      { -INT32_C(    15618029),  INT32_C(  1348877205) },
      {
       INT32_C(  2012382157),
       INT32_C(  1688841236),
      -INT32_C(    15618029),
       INT32_C(  2106947999),
      -INT32_C(   437471980),
       INT32_C(  1348877205),
      }
    },
    { {  INT32_C(   338151637), -INT32_C(  1639368239) },
      {  INT32_C(  1544895420), -INT32_C(   908481867) },
      {  INT32_C(  1781367382),  INT32_C(  1263474999) },
      {
       INT32_C(   338151637),
       INT32_C(  1544895420),
       INT32_C(  1781367382),
      -INT32_C(  1639368239),
      -INT32_C(   908481867),
       INT32_C(  1263474999),
      }
    },
    { {  INT32_C(  1581933001),  INT32_C(  1907339676) },
      {  INT32_C(  1250285177), -INT32_C(   857157873) },
      { -INT32_C(  1087832822), -INT32_C(    41418329) },
      {
       INT32_C(  1581933001),
       INT32_C(  1250285177),
      -INT32_C(  1087832822),
       INT32_C(  1907339676),
      -INT32_C(   857157873),
      -INT32_C(    41418329),
      }
    },
    { { -INT32_C(  1150765692), -INT32_C(  1744390193) },
      { -INT32_C(  1258860264),  INT32_C(  2066064898) },
      { -INT32_C(  1933137028), -INT32_C(  2074562950) },
      {
      -INT32_C(  1150765692),
      -INT32_C(  1258860264),
      -INT32_C(  1933137028),
      -INT32_C(  1744390193),
       INT32_C(  2066064898),
      -INT32_C(  2074562950),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x3_t r_ = { { simde_vld1_s32(test_vec[i].r0),
                               simde_vld1_s32(test_vec[i].r1),
                               simde_vld1_s32(test_vec[i].r2), } };

    int32_t a_[6];
    simde_vst3_s32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3_s32(a_);
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
    simde_int32x2x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_i32x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    int32_t buf[6];
    simde_vst3_s32(buf, a);

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
test_simde_vst3_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r0[1];
    int64_t r1[1];
    int64_t r2[1];
    int64_t a[3];
  } test_vec[] = {
    { {  INT64_C( 3572290692995033026) },
      {  INT64_C( 3052598082801596878) },
      {  INT64_C( 2809764841870853617) },
      {
       INT64_C( 3572290692995033026),
       INT64_C( 3052598082801596878),
       INT64_C( 2809764841870853617),
      }
    },
    { { -INT64_C( 8572706592134440696) },
      { -INT64_C( 7967295716091007032) },
      { -INT64_C( 3537755775352906508) },
      {
      -INT64_C( 8572706592134440696),
      -INT64_C( 7967295716091007032),
      -INT64_C( 3537755775352906508),
      }
    },
    { {  INT64_C( 5892241348017586019) },
      {  INT64_C( 6492965336728335051) },
      {  INT64_C( 8099449588095058452) },
      {
       INT64_C( 5892241348017586019),
       INT64_C( 6492965336728335051),
       INT64_C( 8099449588095058452),
      }
    },
    { {  INT64_C( 2922014572781856738) },
      {  INT64_C( 4516420428428149011) },
      {  INT64_C(  246550016633621118) },
      {
       INT64_C( 2922014572781856738),
       INT64_C( 4516420428428149011),
       INT64_C(  246550016633621118),
      }
    },
    { { -INT64_C( 1523834019503275283) },
      {  INT64_C( 3356930063699871657) },
      {  INT64_C( 7487577332208262455) },
      {
      -INT64_C( 1523834019503275283),
       INT64_C( 3356930063699871657),
       INT64_C( 7487577332208262455),
      }
    },
    { { -INT64_C( 7893153571695773310) },
      {  INT64_C( 4168318472599392229) },
      { -INT64_C( 1213652234887790114) },
      {
      -INT64_C( 7893153571695773310),
       INT64_C( 4168318472599392229),
      -INT64_C( 1213652234887790114),
      }
    },
    { {  INT64_C( 7848230343900050330) },
      {  INT64_C( 2987104008165810748) },
      {  INT64_C( 2768850959988125858) },
      {
       INT64_C( 7848230343900050330),
       INT64_C( 2987104008165810748),
       INT64_C( 2768850959988125858),
      }
    },
    { { -INT64_C( 1506374561952689296) },
      {  INT64_C( 8165687162410349307) },
      {  INT64_C( 2677890818908565691) },
      {
      -INT64_C( 1506374561952689296),
       INT64_C( 8165687162410349307),
       INT64_C( 2677890818908565691),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x3_t r_ = { { simde_vld1_s64(test_vec[i].r0),
                               simde_vld1_s64(test_vec[i].r1),
                               simde_vld1_s64(test_vec[i].r2), } };

    int64_t a_[3];
    simde_vst3_s64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3_s64(a_);
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
    simde_int64x1x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_i64x1(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    int64_t buf[3];
    simde_vst3_s64(buf, a);

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
test_simde_vst3_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r0[8];
    uint8_t r1[8];
    uint8_t r2[8];
    uint8_t a[24];
  } test_vec[] = {
    { { UINT8_C( 12), UINT8_C( 67), UINT8_C(124), UINT8_C(237), UINT8_C(151), UINT8_C(131), UINT8_C(124), UINT8_C(175) },
      { UINT8_C(205), UINT8_C(128), UINT8_C(134), UINT8_C(187), UINT8_C(236), UINT8_C(  2), UINT8_C( 61), UINT8_C( 50) },
      { UINT8_C( 18), UINT8_C(148), UINT8_C(148), UINT8_C( 14), UINT8_C(133), UINT8_C( 73), UINT8_C( 44), UINT8_C(182) },
      {
      UINT8_C( 12),
      UINT8_C(205),
      UINT8_C( 18),
      UINT8_C( 67),
      UINT8_C(128),
      UINT8_C(148),
      UINT8_C(124),
      UINT8_C(134),
      UINT8_C(148),
      UINT8_C(237),
      UINT8_C(187),
      UINT8_C( 14),
      UINT8_C(151),
      UINT8_C(236),
      UINT8_C(133),
      UINT8_C(131),
      UINT8_C(  2),
      UINT8_C( 73),
      UINT8_C(124),
      UINT8_C( 61),
      UINT8_C( 44),
      UINT8_C(175),
      UINT8_C( 50),
      UINT8_C(182),
      }
    },
    { { UINT8_C( 10), UINT8_C(157), UINT8_C(245), UINT8_C( 84), UINT8_C(206), UINT8_C( 89), UINT8_C(211), UINT8_C(218) },
      { UINT8_C(156), UINT8_C( 79), UINT8_C(199), UINT8_C( 51), UINT8_C(210), UINT8_C( 67), UINT8_C(226), UINT8_C(159) },
      { UINT8_C(196), UINT8_C(104), UINT8_C( 90), UINT8_C(176), UINT8_C(106), UINT8_C(152), UINT8_C(226), UINT8_C(125) },
      {
      UINT8_C( 10),
      UINT8_C(156),
      UINT8_C(196),
      UINT8_C(157),
      UINT8_C( 79),
      UINT8_C(104),
      UINT8_C(245),
      UINT8_C(199),
      UINT8_C( 90),
      UINT8_C( 84),
      UINT8_C( 51),
      UINT8_C(176),
      UINT8_C(206),
      UINT8_C(210),
      UINT8_C(106),
      UINT8_C( 89),
      UINT8_C( 67),
      UINT8_C(152),
      UINT8_C(211),
      UINT8_C(226),
      UINT8_C(226),
      UINT8_C(218),
      UINT8_C(159),
      UINT8_C(125),
      }
    },
    { { UINT8_C( 44), UINT8_C(119), UINT8_C(139), UINT8_C(177), UINT8_C(192), UINT8_C(183), UINT8_C(103), UINT8_C(202) },
      { UINT8_C( 85), UINT8_C( 92), UINT8_C( 30), UINT8_C( 35), UINT8_C(181), UINT8_C(241), UINT8_C(253), UINT8_C( 81) },
      { UINT8_C( 64), UINT8_C(196), UINT8_C(132), UINT8_C( 19), UINT8_C(  8), UINT8_C(103), UINT8_C(178), UINT8_C(204) },
      {
      UINT8_C( 44),
      UINT8_C( 85),
      UINT8_C( 64),
      UINT8_C(119),
      UINT8_C( 92),
      UINT8_C(196),
      UINT8_C(139),
      UINT8_C( 30),
      UINT8_C(132),
      UINT8_C(177),
      UINT8_C( 35),
      UINT8_C( 19),
      UINT8_C(192),
      UINT8_C(181),
      UINT8_C(  8),
      UINT8_C(183),
      UINT8_C(241),
      UINT8_C(103),
      UINT8_C(103),
      UINT8_C(253),
      UINT8_C(178),
      UINT8_C(202),
      UINT8_C( 81),
      UINT8_C(204),
      }
    },
    { { UINT8_C(207), UINT8_C( 13), UINT8_C(124), UINT8_C( 58), UINT8_C(165), UINT8_C( 94), UINT8_C(183), UINT8_C(209) },
      { UINT8_C(213), UINT8_C( 66), UINT8_C(130), UINT8_C(150), UINT8_C(250), UINT8_C(233), UINT8_C( 96), UINT8_C( 79) },
      { UINT8_C( 69), UINT8_C(127), UINT8_C(114), UINT8_C(250), UINT8_C(112), UINT8_C(111), UINT8_C( 75), UINT8_C(177) },
      {
      UINT8_C(207),
      UINT8_C(213),
      UINT8_C( 69),
      UINT8_C( 13),
      UINT8_C( 66),
      UINT8_C(127),
      UINT8_C(124),
      UINT8_C(130),
      UINT8_C(114),
      UINT8_C( 58),
      UINT8_C(150),
      UINT8_C(250),
      UINT8_C(165),
      UINT8_C(250),
      UINT8_C(112),
      UINT8_C( 94),
      UINT8_C(233),
      UINT8_C(111),
      UINT8_C(183),
      UINT8_C( 96),
      UINT8_C( 75),
      UINT8_C(209),
      UINT8_C( 79),
      UINT8_C(177),
      }
    },
    { { UINT8_C( 51), UINT8_C(207), UINT8_C(196), UINT8_C( 59), UINT8_C( 54), UINT8_C(118), UINT8_C(  7), UINT8_C(  6) },
      { UINT8_C(131), UINT8_C(131), UINT8_C( 64), UINT8_C( 40), UINT8_C(226), UINT8_C(247), UINT8_C(249), UINT8_C(183) },
      { UINT8_C( 57), UINT8_C(123), UINT8_C( 77), UINT8_C( 51), UINT8_C(100), UINT8_C(174), UINT8_C(130), UINT8_C(169) },
      {
      UINT8_C( 51),
      UINT8_C(131),
      UINT8_C( 57),
      UINT8_C(207),
      UINT8_C(131),
      UINT8_C(123),
      UINT8_C(196),
      UINT8_C( 64),
      UINT8_C( 77),
      UINT8_C( 59),
      UINT8_C( 40),
      UINT8_C( 51),
      UINT8_C( 54),
      UINT8_C(226),
      UINT8_C(100),
      UINT8_C(118),
      UINT8_C(247),
      UINT8_C(174),
      UINT8_C(  7),
      UINT8_C(249),
      UINT8_C(130),
      UINT8_C(  6),
      UINT8_C(183),
      UINT8_C(169),
      }
    },
    { { UINT8_C( 45), UINT8_C(244), UINT8_C(163), UINT8_C(157), UINT8_C( 99), UINT8_C(238), UINT8_C( 78), UINT8_C(151) },
      { UINT8_C(190), UINT8_C( 18), UINT8_C(210), UINT8_C(244), UINT8_C(137), UINT8_C(218), UINT8_C(250), UINT8_C( 12) },
      { UINT8_C( 93), UINT8_C( 58), UINT8_C( 53), UINT8_C( 63), UINT8_C( 49), UINT8_C( 46), UINT8_C(247), UINT8_C(107) },
      {
      UINT8_C( 45),
      UINT8_C(190),
      UINT8_C( 93),
      UINT8_C(244),
      UINT8_C( 18),
      UINT8_C( 58),
      UINT8_C(163),
      UINT8_C(210),
      UINT8_C( 53),
      UINT8_C(157),
      UINT8_C(244),
      UINT8_C( 63),
      UINT8_C( 99),
      UINT8_C(137),
      UINT8_C( 49),
      UINT8_C(238),
      UINT8_C(218),
      UINT8_C( 46),
      UINT8_C( 78),
      UINT8_C(250),
      UINT8_C(247),
      UINT8_C(151),
      UINT8_C( 12),
      UINT8_C(107),
      }
    },
    { { UINT8_C(170), UINT8_C( 68), UINT8_C(158), UINT8_C( 14), UINT8_C(242), UINT8_C( 33), UINT8_C(184), UINT8_C( 31) },
      { UINT8_C( 21), UINT8_C( 91), UINT8_C(189), UINT8_C(121), UINT8_C( 74), UINT8_C( 11), UINT8_C( 16), UINT8_C(  8) },
      { UINT8_C( 30), UINT8_C(226), UINT8_C(252), UINT8_C(167), UINT8_C(188), UINT8_C(247), UINT8_C(179), UINT8_C( 26) },
      {
      UINT8_C(170),
      UINT8_C( 21),
      UINT8_C( 30),
      UINT8_C( 68),
      UINT8_C( 91),
      UINT8_C(226),
      UINT8_C(158),
      UINT8_C(189),
      UINT8_C(252),
      UINT8_C( 14),
      UINT8_C(121),
      UINT8_C(167),
      UINT8_C(242),
      UINT8_C( 74),
      UINT8_C(188),
      UINT8_C( 33),
      UINT8_C( 11),
      UINT8_C(247),
      UINT8_C(184),
      UINT8_C( 16),
      UINT8_C(179),
      UINT8_C( 31),
      UINT8_C(  8),
      UINT8_C( 26),
      }
    },
    { { UINT8_C( 49), UINT8_C(232), UINT8_C( 89), UINT8_C( 99), UINT8_C( 23), UINT8_C( 80), UINT8_C(206), UINT8_C(193) },
      { UINT8_C(149), UINT8_C(108), UINT8_C(207), UINT8_C(135), UINT8_C(141), UINT8_C(135), UINT8_C(167), UINT8_C(163) },
      { UINT8_C(227), UINT8_C(100), UINT8_C( 28), UINT8_C( 45), UINT8_C(111), UINT8_C( 44), UINT8_C( 53), UINT8_C(141) },
      {
      UINT8_C( 49),
      UINT8_C(149),
      UINT8_C(227),
      UINT8_C(232),
      UINT8_C(108),
      UINT8_C(100),
      UINT8_C( 89),
      UINT8_C(207),
      UINT8_C( 28),
      UINT8_C( 99),
      UINT8_C(135),
      UINT8_C( 45),
      UINT8_C( 23),
      UINT8_C(141),
      UINT8_C(111),
      UINT8_C( 80),
      UINT8_C(135),
      UINT8_C( 44),
      UINT8_C(206),
      UINT8_C(167),
      UINT8_C( 53),
      UINT8_C(193),
      UINT8_C(163),
      UINT8_C(141),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x3_t r_ = { { simde_vld1_u8(test_vec[i].r0),
                               simde_vld1_u8(test_vec[i].r1),
                               simde_vld1_u8(test_vec[i].r2), } };

    uint8_t a_[24];
    simde_vst3_u8(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3_u8(a_);
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
    simde_uint8x8x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_u8x8(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    uint8_t buf[24];
    simde_vst3_u8(buf, a);

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
test_simde_vst3_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r0[4];
    uint16_t r1[4];
    uint16_t r2[4];
    uint16_t a[12];
  } test_vec[] = {
    { { UINT16_C( 9344), UINT16_C(14996), UINT16_C( 7435), UINT16_C(59276) },
      { UINT16_C(26277), UINT16_C(23774), UINT16_C(21915), UINT16_C(  425) },
      { UINT16_C(18737), UINT16_C(57584), UINT16_C(38525), UINT16_C(39425) },
      {
      UINT16_C( 9344),
      UINT16_C(26277),
      UINT16_C(18737),
      UINT16_C(14996),
      UINT16_C(23774),
      UINT16_C(57584),
      UINT16_C( 7435),
      UINT16_C(21915),
      UINT16_C(38525),
      UINT16_C(59276),
      UINT16_C(  425),
      UINT16_C(39425),
      }
    },
    { { UINT16_C(31766), UINT16_C(36501), UINT16_C(13366), UINT16_C(47054) },
      { UINT16_C(25177), UINT16_C(25841), UINT16_C(32127), UINT16_C( 9547) },
      { UINT16_C(10724), UINT16_C(32641), UINT16_C(10878), UINT16_C(45184) },
      {
      UINT16_C(31766),
      UINT16_C(25177),
      UINT16_C(10724),
      UINT16_C(36501),
      UINT16_C(25841),
      UINT16_C(32641),
      UINT16_C(13366),
      UINT16_C(32127),
      UINT16_C(10878),
      UINT16_C(47054),
      UINT16_C( 9547),
      UINT16_C(45184),
      }
    },
    { { UINT16_C(29044), UINT16_C(61840), UINT16_C(37127), UINT16_C( 7563) },
      { UINT16_C( 8206), UINT16_C(17579), UINT16_C(31317), UINT16_C(44795) },
      { UINT16_C(60892), UINT16_C(23570), UINT16_C(23914), UINT16_C(20097) },
      {
      UINT16_C(29044),
      UINT16_C( 8206),
      UINT16_C(60892),
      UINT16_C(61840),
      UINT16_C(17579),
      UINT16_C(23570),
      UINT16_C(37127),
      UINT16_C(31317),
      UINT16_C(23914),
      UINT16_C( 7563),
      UINT16_C(44795),
      UINT16_C(20097),
      }
    },
    { { UINT16_C(  646), UINT16_C( 1230), UINT16_C(20013), UINT16_C(41396) },
      { UINT16_C(17599), UINT16_C(51090), UINT16_C( 7638), UINT16_C(58596) },
      { UINT16_C(36926), UINT16_C(37672), UINT16_C( 9226), UINT16_C(58945) },
      {
      UINT16_C(  646),
      UINT16_C(17599),
      UINT16_C(36926),
      UINT16_C( 1230),
      UINT16_C(51090),
      UINT16_C(37672),
      UINT16_C(20013),
      UINT16_C( 7638),
      UINT16_C( 9226),
      UINT16_C(41396),
      UINT16_C(58596),
      UINT16_C(58945),
      }
    },
    { { UINT16_C(21265), UINT16_C(31554), UINT16_C(50096), UINT16_C(14026) },
      { UINT16_C(39110), UINT16_C(62266), UINT16_C(61414), UINT16_C(42644) },
      { UINT16_C( 9779), UINT16_C( 2413), UINT16_C(20803), UINT16_C(33261) },
      {
      UINT16_C(21265),
      UINT16_C(39110),
      UINT16_C( 9779),
      UINT16_C(31554),
      UINT16_C(62266),
      UINT16_C( 2413),
      UINT16_C(50096),
      UINT16_C(61414),
      UINT16_C(20803),
      UINT16_C(14026),
      UINT16_C(42644),
      UINT16_C(33261),
      }
    },
    { { UINT16_C( 5857), UINT16_C(60180), UINT16_C(21818), UINT16_C(19410) },
      { UINT16_C( 5288), UINT16_C(22726), UINT16_C(37080), UINT16_C(40590) },
      { UINT16_C(51496), UINT16_C( 3985), UINT16_C( 9656), UINT16_C(60341) },
      {
      UINT16_C( 5857),
      UINT16_C( 5288),
      UINT16_C(51496),
      UINT16_C(60180),
      UINT16_C(22726),
      UINT16_C( 3985),
      UINT16_C(21818),
      UINT16_C(37080),
      UINT16_C( 9656),
      UINT16_C(19410),
      UINT16_C(40590),
      UINT16_C(60341),
      }
    },
    { { UINT16_C( 8779), UINT16_C(36597), UINT16_C(57971), UINT16_C(21776) },
      { UINT16_C( 9464), UINT16_C(12864), UINT16_C( 4730), UINT16_C( 8829) },
      { UINT16_C(17447), UINT16_C(65403), UINT16_C( 2516), UINT16_C(64925) },
      {
      UINT16_C( 8779),
      UINT16_C( 9464),
      UINT16_C(17447),
      UINT16_C(36597),
      UINT16_C(12864),
      UINT16_C(65403),
      UINT16_C(57971),
      UINT16_C( 4730),
      UINT16_C( 2516),
      UINT16_C(21776),
      UINT16_C( 8829),
      UINT16_C(64925),
      }
    },
    { { UINT16_C(11986), UINT16_C(35340), UINT16_C(49491), UINT16_C(40566) },
      { UINT16_C(27619), UINT16_C(22060), UINT16_C(15437), UINT16_C(18091) },
      { UINT16_C(60513), UINT16_C(56184), UINT16_C(63230), UINT16_C( 9725) },
      {
      UINT16_C(11986),
      UINT16_C(27619),
      UINT16_C(60513),
      UINT16_C(35340),
      UINT16_C(22060),
      UINT16_C(56184),
      UINT16_C(49491),
      UINT16_C(15437),
      UINT16_C(63230),
      UINT16_C(40566),
      UINT16_C(18091),
      UINT16_C( 9725),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x3_t r_ = { { simde_vld1_u16(test_vec[i].r0),
                                simde_vld1_u16(test_vec[i].r1),
                                simde_vld1_u16(test_vec[i].r2), } };

    uint16_t a_[12];
    simde_vst3_u16(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3_u16(a_);
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
    simde_uint16x4x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_u16x4(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    uint16_t buf[12];
    simde_vst3_u16(buf, a);

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
test_simde_vst3_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r0[2];
    uint32_t r1[2];
    uint32_t r2[2];
    uint32_t a[6];
  } test_vec[] = {
    { { UINT32_C(1250214441), UINT32_C(1747430402) },
      { UINT32_C( 407036501), UINT32_C( 975185396) },
      { UINT32_C(3833042844), UINT32_C( 714403033) },
      {
      UINT32_C(1250214441),
      UINT32_C( 407036501),
      UINT32_C(3833042844),
      UINT32_C(1747430402),
      UINT32_C( 975185396),
      UINT32_C( 714403033),
      }
    },
    { { UINT32_C( 284881893), UINT32_C(1679415099) },
      { UINT32_C(2628689306), UINT32_C(2667894090) },
      { UINT32_C(2897692599), UINT32_C( 149346156) },
      {
      UINT32_C( 284881893),
      UINT32_C(2628689306),
      UINT32_C(2897692599),
      UINT32_C(1679415099),
      UINT32_C(2667894090),
      UINT32_C( 149346156),
      }
    },
    { { UINT32_C(1206738286), UINT32_C( 779190601) },
      { UINT32_C(2956880757), UINT32_C(3709098051) },
      { UINT32_C(1064944373), UINT32_C(1323203991) },
      {
      UINT32_C(1206738286),
      UINT32_C(2956880757),
      UINT32_C(1064944373),
      UINT32_C( 779190601),
      UINT32_C(3709098051),
      UINT32_C(1323203991),
      }
    },
    { { UINT32_C( 838505924), UINT32_C(3661226348) },
      { UINT32_C(2283939390), UINT32_C( 498504616) },
      { UINT32_C(1120794111), UINT32_C(1109385549) },
      {
      UINT32_C( 838505924),
      UINT32_C(2283939390),
      UINT32_C(1120794111),
      UINT32_C(3661226348),
      UINT32_C( 498504616),
      UINT32_C(1109385549),
      }
    },
    { { UINT32_C( 981637283), UINT32_C(3666370581) },
      { UINT32_C(1644921846), UINT32_C(2721924196) },
      { UINT32_C( 321544043), UINT32_C(4046512626) },
      {
      UINT32_C( 981637283),
      UINT32_C(1644921846),
      UINT32_C( 321544043),
      UINT32_C(3666370581),
      UINT32_C(2721924196),
      UINT32_C(4046512626),
      }
    },
    { { UINT32_C( 590609878), UINT32_C(2170901214) },
      { UINT32_C(  12314602), UINT32_C(1054491464) },
      { UINT32_C( 715187654), UINT32_C(2496519465) },
      {
      UINT32_C( 590609878),
      UINT32_C(  12314602),
      UINT32_C( 715187654),
      UINT32_C(2170901214),
      UINT32_C(1054491464),
      UINT32_C(2496519465),
      }
    },
    { { UINT32_C( 799536956), UINT32_C(2921387992) },
      { UINT32_C(3000063188), UINT32_C(2436052902) },
      { UINT32_C(1720839710), UINT32_C(4171524914) },
      {
      UINT32_C( 799536956),
      UINT32_C(3000063188),
      UINT32_C(1720839710),
      UINT32_C(2921387992),
      UINT32_C(2436052902),
      UINT32_C(4171524914),
      }
    },
    { { UINT32_C(2032354640), UINT32_C(1594814498) },
      { UINT32_C(3230578151), UINT32_C(1634643597) },
      { UINT32_C(2836676610), UINT32_C(2503624567) },
      {
      UINT32_C(2032354640),
      UINT32_C(3230578151),
      UINT32_C(2836676610),
      UINT32_C(1594814498),
      UINT32_C(1634643597),
      UINT32_C(2503624567),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x3_t r_ = { { simde_vld1_u32(test_vec[i].r0),
                                simde_vld1_u32(test_vec[i].r1),
                                simde_vld1_u32(test_vec[i].r2), } };

    uint32_t a_[6];
    simde_vst3_u32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3_u32(a_);
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
    simde_uint32x2x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_u32x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    uint32_t buf[6];
    simde_vst3_u32(buf, a);

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
test_simde_vst3_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r0[1];
    uint64_t r1[1];
    uint64_t r2[1];
    uint64_t a[3];
  } test_vec[] = {
    { { UINT64_C(12422824856183467782) },
      { UINT64_C( 7004324963154263795) },
      { UINT64_C( 9338655374062009309) },
      {
      UINT64_C(12422824856183467782),
      UINT64_C( 7004324963154263795),
      UINT64_C( 9338655374062009309),
      }
    },
    { { UINT64_C( 6390283869042032365) },
      { UINT64_C( 1465642543073747784) },
      { UINT64_C(14254966942331603968) },
      {
      UINT64_C( 6390283869042032365),
      UINT64_C( 1465642543073747784),
      UINT64_C(14254966942331603968),
      }
    },
    { { UINT64_C( 1378937280728634636) },
      { UINT64_C( 7737497671101794998) },
      { UINT64_C(18425754395142978945) },
      {
      UINT64_C( 1378937280728634636),
      UINT64_C( 7737497671101794998),
      UINT64_C(18425754395142978945),
      }
    },
    { { UINT64_C( 3361450187992158969) },
      { UINT64_C(13048320093653501658) },
      { UINT64_C( 2506568346036438075) },
      {
      UINT64_C( 3361450187992158969),
      UINT64_C(13048320093653501658),
      UINT64_C( 2506568346036438075),
      }
    },
    { { UINT64_C( 4979425705785089819) },
      { UINT64_C(12329956177065970635) },
      { UINT64_C( 1839369556765502675) },
      {
      UINT64_C( 4979425705785089819),
      UINT64_C(12329956177065970635),
      UINT64_C( 1839369556765502675),
      }
    },
    { { UINT64_C( 9081580541621781572) },
      { UINT64_C( 1275277660055456800) },
      { UINT64_C( 8771073248822548798) },
      {
      UINT64_C( 9081580541621781572),
      UINT64_C( 1275277660055456800),
      UINT64_C( 8771073248822548798),
      }
    },
    { { UINT64_C( 7709829577090688264) },
      { UINT64_C(15561442731964266005) },
      { UINT64_C( 9114713076917374501) },
      {
      UINT64_C( 7709829577090688264),
      UINT64_C(15561442731964266005),
      UINT64_C( 9114713076917374501),
      }
    },
    { { UINT64_C(11596565186140273872) },
      { UINT64_C( 2250819095794956716) },
      { UINT64_C(  831350528676433402) },
      {
      UINT64_C(11596565186140273872),
      UINT64_C( 2250819095794956716),
      UINT64_C(  831350528676433402),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x3_t r_ = { { simde_vld1_u64(test_vec[i].r0),
                                simde_vld1_u64(test_vec[i].r1),
                                simde_vld1_u64(test_vec[i].r2), } };

    uint64_t a_[3];
    simde_vst3_u64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3_u64(a_);
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
    simde_uint64x1x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_u64x1(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    uint64_t buf[3];
    simde_vst3_u64(buf, a);

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
test_simde_vst3q_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r0[4];
    simde_float32 r1[4];
    simde_float32 r2[4];
    simde_float32 a[12];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -985.78), SIMDE_FLOAT32_C(  -181.56), SIMDE_FLOAT32_C(  -910.82), SIMDE_FLOAT32_C(  -732.91) },
      { SIMDE_FLOAT32_C(  -353.18), SIMDE_FLOAT32_C(  -450.78), SIMDE_FLOAT32_C(   -83.42), SIMDE_FLOAT32_C(  -225.91) },
      { SIMDE_FLOAT32_C(  -974.60), SIMDE_FLOAT32_C(  -205.59), SIMDE_FLOAT32_C(  -350.99), SIMDE_FLOAT32_C(  -219.80) },
      {
      SIMDE_FLOAT32_C(  -985.78),
      SIMDE_FLOAT32_C(  -353.18),
      SIMDE_FLOAT32_C(  -974.60),
      SIMDE_FLOAT32_C(  -181.56),
      SIMDE_FLOAT32_C(  -450.78),
      SIMDE_FLOAT32_C(  -205.59),
      SIMDE_FLOAT32_C(  -910.82),
      SIMDE_FLOAT32_C(   -83.42),
      SIMDE_FLOAT32_C(  -350.99),
      SIMDE_FLOAT32_C(  -732.91),
      SIMDE_FLOAT32_C(  -225.91),
      SIMDE_FLOAT32_C(  -219.80),
      }
    },
    { { SIMDE_FLOAT32_C(   583.13), SIMDE_FLOAT32_C(   717.32), SIMDE_FLOAT32_C(  -138.31), SIMDE_FLOAT32_C(   428.23) },
      { SIMDE_FLOAT32_C(   -15.12), SIMDE_FLOAT32_C(  -349.44), SIMDE_FLOAT32_C(   838.60), SIMDE_FLOAT32_C(   645.26) },
      { SIMDE_FLOAT32_C(   917.57), SIMDE_FLOAT32_C(  -862.79), SIMDE_FLOAT32_C(   403.85), SIMDE_FLOAT32_C(   196.39) },
      {
      SIMDE_FLOAT32_C(   583.13),
      SIMDE_FLOAT32_C(   -15.12),
      SIMDE_FLOAT32_C(   917.57),
      SIMDE_FLOAT32_C(   717.32),
      SIMDE_FLOAT32_C(  -349.44),
      SIMDE_FLOAT32_C(  -862.79),
      SIMDE_FLOAT32_C(  -138.31),
      SIMDE_FLOAT32_C(   838.60),
      SIMDE_FLOAT32_C(   403.85),
      SIMDE_FLOAT32_C(   428.23),
      SIMDE_FLOAT32_C(   645.26),
      SIMDE_FLOAT32_C(   196.39),
      }
    },
    { { SIMDE_FLOAT32_C(  -768.47), SIMDE_FLOAT32_C(  -949.16), SIMDE_FLOAT32_C(    42.85), SIMDE_FLOAT32_C(  -252.64) },
      { SIMDE_FLOAT32_C(  -690.55), SIMDE_FLOAT32_C(  -771.86), SIMDE_FLOAT32_C(  -903.80), SIMDE_FLOAT32_C(  -676.33) },
      { SIMDE_FLOAT32_C(    46.58), SIMDE_FLOAT32_C(  -814.62), SIMDE_FLOAT32_C(  -409.24), SIMDE_FLOAT32_C(   693.40) },
      {
      SIMDE_FLOAT32_C(  -768.47),
      SIMDE_FLOAT32_C(  -690.55),
      SIMDE_FLOAT32_C(    46.58),
      SIMDE_FLOAT32_C(  -949.16),
      SIMDE_FLOAT32_C(  -771.86),
      SIMDE_FLOAT32_C(  -814.62),
      SIMDE_FLOAT32_C(    42.85),
      SIMDE_FLOAT32_C(  -903.80),
      SIMDE_FLOAT32_C(  -409.24),
      SIMDE_FLOAT32_C(  -252.64),
      SIMDE_FLOAT32_C(  -676.33),
      SIMDE_FLOAT32_C(   693.40),
      }
    },
    { { SIMDE_FLOAT32_C(  -265.40), SIMDE_FLOAT32_C(   507.34), SIMDE_FLOAT32_C(  -532.51), SIMDE_FLOAT32_C(  -240.00) },
      { SIMDE_FLOAT32_C(  -698.24), SIMDE_FLOAT32_C(   116.50), SIMDE_FLOAT32_C(   540.20), SIMDE_FLOAT32_C(   884.89) },
      { SIMDE_FLOAT32_C(  -166.18), SIMDE_FLOAT32_C(  -598.11), SIMDE_FLOAT32_C(   313.12), SIMDE_FLOAT32_C(   818.70) },
      {
      SIMDE_FLOAT32_C(  -265.40),
      SIMDE_FLOAT32_C(  -698.24),
      SIMDE_FLOAT32_C(  -166.18),
      SIMDE_FLOAT32_C(   507.34),
      SIMDE_FLOAT32_C(   116.50),
      SIMDE_FLOAT32_C(  -598.11),
      SIMDE_FLOAT32_C(  -532.51),
      SIMDE_FLOAT32_C(   540.20),
      SIMDE_FLOAT32_C(   313.12),
      SIMDE_FLOAT32_C(  -240.00),
      SIMDE_FLOAT32_C(   884.89),
      SIMDE_FLOAT32_C(   818.70),
      }
    },
    { { SIMDE_FLOAT32_C(    52.45), SIMDE_FLOAT32_C(   151.71), SIMDE_FLOAT32_C(   463.96), SIMDE_FLOAT32_C(   -29.98) },
      { SIMDE_FLOAT32_C(   288.92), SIMDE_FLOAT32_C(  -132.19), SIMDE_FLOAT32_C(  -833.58), SIMDE_FLOAT32_C(   520.45) },
      { SIMDE_FLOAT32_C(   -81.36), SIMDE_FLOAT32_C(   209.27), SIMDE_FLOAT32_C(  -732.19), SIMDE_FLOAT32_C(   228.09) },
      {
      SIMDE_FLOAT32_C(    52.45),
      SIMDE_FLOAT32_C(   288.92),
      SIMDE_FLOAT32_C(   -81.36),
      SIMDE_FLOAT32_C(   151.71),
      SIMDE_FLOAT32_C(  -132.19),
      SIMDE_FLOAT32_C(   209.27),
      SIMDE_FLOAT32_C(   463.96),
      SIMDE_FLOAT32_C(  -833.58),
      SIMDE_FLOAT32_C(  -732.19),
      SIMDE_FLOAT32_C(   -29.98),
      SIMDE_FLOAT32_C(   520.45),
      SIMDE_FLOAT32_C(   228.09),
      }
    },
    { { SIMDE_FLOAT32_C(   437.41), SIMDE_FLOAT32_C(  -635.99), SIMDE_FLOAT32_C(   551.76), SIMDE_FLOAT32_C(  -516.01) },
      { SIMDE_FLOAT32_C(  -450.62), SIMDE_FLOAT32_C(  -857.48), SIMDE_FLOAT32_C(  -822.60), SIMDE_FLOAT32_C(   283.98) },
      { SIMDE_FLOAT32_C(   649.87), SIMDE_FLOAT32_C(  -355.11), SIMDE_FLOAT32_C(  -956.02), SIMDE_FLOAT32_C(   951.62) },
      {
      SIMDE_FLOAT32_C(   437.41),
      SIMDE_FLOAT32_C(  -450.62),
      SIMDE_FLOAT32_C(   649.87),
      SIMDE_FLOAT32_C(  -635.99),
      SIMDE_FLOAT32_C(  -857.48),
      SIMDE_FLOAT32_C(  -355.11),
      SIMDE_FLOAT32_C(   551.76),
      SIMDE_FLOAT32_C(  -822.60),
      SIMDE_FLOAT32_C(  -956.02),
      SIMDE_FLOAT32_C(  -516.01),
      SIMDE_FLOAT32_C(   283.98),
      SIMDE_FLOAT32_C(   951.62),
      }
    },
    { { SIMDE_FLOAT32_C(   761.38), SIMDE_FLOAT32_C(   584.18), SIMDE_FLOAT32_C(   836.51), SIMDE_FLOAT32_C(  -404.80) },
      { SIMDE_FLOAT32_C(   986.07), SIMDE_FLOAT32_C(   149.63), SIMDE_FLOAT32_C(  -586.10), SIMDE_FLOAT32_C(    38.52) },
      { SIMDE_FLOAT32_C(  -698.66), SIMDE_FLOAT32_C(   877.86), SIMDE_FLOAT32_C(  -991.46), SIMDE_FLOAT32_C(   590.26) },
      {
      SIMDE_FLOAT32_C(   761.38),
      SIMDE_FLOAT32_C(   986.07),
      SIMDE_FLOAT32_C(  -698.66),
      SIMDE_FLOAT32_C(   584.18),
      SIMDE_FLOAT32_C(   149.63),
      SIMDE_FLOAT32_C(   877.86),
      SIMDE_FLOAT32_C(   836.51),
      SIMDE_FLOAT32_C(  -586.10),
      SIMDE_FLOAT32_C(  -991.46),
      SIMDE_FLOAT32_C(  -404.80),
      SIMDE_FLOAT32_C(    38.52),
      SIMDE_FLOAT32_C(   590.26),
      }
    },
    { { SIMDE_FLOAT32_C(  -254.33), SIMDE_FLOAT32_C(  -825.04), SIMDE_FLOAT32_C(   110.71), SIMDE_FLOAT32_C(   664.31) },
      { SIMDE_FLOAT32_C(   384.23), SIMDE_FLOAT32_C(   378.52), SIMDE_FLOAT32_C(  -107.59), SIMDE_FLOAT32_C(  -178.36) },
      { SIMDE_FLOAT32_C(   742.53), SIMDE_FLOAT32_C(  -555.83), SIMDE_FLOAT32_C(   305.63), SIMDE_FLOAT32_C(  -708.09) },
      {
      SIMDE_FLOAT32_C(  -254.33),
      SIMDE_FLOAT32_C(   384.23),
      SIMDE_FLOAT32_C(   742.53),
      SIMDE_FLOAT32_C(  -825.04),
      SIMDE_FLOAT32_C(   378.52),
      SIMDE_FLOAT32_C(  -555.83),
      SIMDE_FLOAT32_C(   110.71),
      SIMDE_FLOAT32_C(  -107.59),
      SIMDE_FLOAT32_C(   305.63),
      SIMDE_FLOAT32_C(   664.31),
      SIMDE_FLOAT32_C(  -178.36),
      SIMDE_FLOAT32_C(  -708.09),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x3_t r_ = { { simde_vld1q_f32(test_vec[i].r0),
                                 simde_vld1q_f32(test_vec[i].r1),
                                 simde_vld1q_f32(test_vec[i].r2), } };

    simde_float32 a_[12];
    simde_vst3q_f32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3q_f32(a_);
    simde_test_arm_neon_assert_equal_f32x4(r_.val[0], simde_vld1q_f32(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f32x4(r_.val[1], simde_vld1q_f32(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f32x4(r_.val[2], simde_vld1q_f32(test_vec[i].r2), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a0 = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t a1 = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t a2 = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_f32x4(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float32_t buf[12];
    simde_vst3q_f32(buf, a);

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
test_simde_vst3q_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r0[2];
    simde_float64 r1[2];
    simde_float64 r2[2];
    simde_float64 a[6];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   758.07), SIMDE_FLOAT64_C(    84.29) },
      { SIMDE_FLOAT64_C(  -600.63), SIMDE_FLOAT64_C(  -472.51) },
      { SIMDE_FLOAT64_C(   725.40), SIMDE_FLOAT64_C(   903.42) },
      {
      SIMDE_FLOAT64_C(   758.07),
      SIMDE_FLOAT64_C(  -600.63),
      SIMDE_FLOAT64_C(   725.40),
      SIMDE_FLOAT64_C(    84.29),
      SIMDE_FLOAT64_C(  -472.51),
      SIMDE_FLOAT64_C(   903.42),
      }
    },
    { { SIMDE_FLOAT64_C(  -564.41), SIMDE_FLOAT64_C(  -453.39) },
      { SIMDE_FLOAT64_C(  -311.50), SIMDE_FLOAT64_C(  -928.88) },
      { SIMDE_FLOAT64_C(   670.94), SIMDE_FLOAT64_C(  -991.23) },
      {
      SIMDE_FLOAT64_C(  -564.41),
      SIMDE_FLOAT64_C(  -311.50),
      SIMDE_FLOAT64_C(   670.94),
      SIMDE_FLOAT64_C(  -453.39),
      SIMDE_FLOAT64_C(  -928.88),
      SIMDE_FLOAT64_C(  -991.23),
      }
    },
    { { SIMDE_FLOAT64_C(   354.81), SIMDE_FLOAT64_C(   507.91) },
      { SIMDE_FLOAT64_C(    71.00), SIMDE_FLOAT64_C(   659.02) },
      { SIMDE_FLOAT64_C(   105.92), SIMDE_FLOAT64_C(   373.60) },
      {
      SIMDE_FLOAT64_C(   354.81),
      SIMDE_FLOAT64_C(    71.00),
      SIMDE_FLOAT64_C(   105.92),
      SIMDE_FLOAT64_C(   507.91),
      SIMDE_FLOAT64_C(   659.02),
      SIMDE_FLOAT64_C(   373.60),
      }
    },
    { { SIMDE_FLOAT64_C(  -261.08), SIMDE_FLOAT64_C(  -713.36) },
      { SIMDE_FLOAT64_C(   -70.21), SIMDE_FLOAT64_C(   417.30) },
      { SIMDE_FLOAT64_C(  -815.10), SIMDE_FLOAT64_C(   451.49) },
      {
      SIMDE_FLOAT64_C(  -261.08),
      SIMDE_FLOAT64_C(   -70.21),
      SIMDE_FLOAT64_C(  -815.10),
      SIMDE_FLOAT64_C(  -713.36),
      SIMDE_FLOAT64_C(   417.30),
      SIMDE_FLOAT64_C(   451.49),
      }
    },
    { { SIMDE_FLOAT64_C(   701.42), SIMDE_FLOAT64_C(  -485.46) },
      { SIMDE_FLOAT64_C(  -486.64), SIMDE_FLOAT64_C(   421.84) },
      { SIMDE_FLOAT64_C(  -955.83), SIMDE_FLOAT64_C(  -150.69) },
      {
      SIMDE_FLOAT64_C(   701.42),
      SIMDE_FLOAT64_C(  -486.64),
      SIMDE_FLOAT64_C(  -955.83),
      SIMDE_FLOAT64_C(  -485.46),
      SIMDE_FLOAT64_C(   421.84),
      SIMDE_FLOAT64_C(  -150.69),
      }
    },
    { { SIMDE_FLOAT64_C(   498.32), SIMDE_FLOAT64_C(   802.24) },
      { SIMDE_FLOAT64_C(   933.60), SIMDE_FLOAT64_C(   897.69) },
      { SIMDE_FLOAT64_C(  -670.27), SIMDE_FLOAT64_C(   659.00) },
      {
      SIMDE_FLOAT64_C(   498.32),
      SIMDE_FLOAT64_C(   933.60),
      SIMDE_FLOAT64_C(  -670.27),
      SIMDE_FLOAT64_C(   802.24),
      SIMDE_FLOAT64_C(   897.69),
      SIMDE_FLOAT64_C(   659.00),
      }
    },
    { { SIMDE_FLOAT64_C(   801.12), SIMDE_FLOAT64_C(  -234.68) },
      { SIMDE_FLOAT64_C(  -794.39), SIMDE_FLOAT64_C(  -510.38) },
      { SIMDE_FLOAT64_C(  -163.56), SIMDE_FLOAT64_C(   876.55) },
      {
      SIMDE_FLOAT64_C(   801.12),
      SIMDE_FLOAT64_C(  -794.39),
      SIMDE_FLOAT64_C(  -163.56),
      SIMDE_FLOAT64_C(  -234.68),
      SIMDE_FLOAT64_C(  -510.38),
      SIMDE_FLOAT64_C(   876.55),
      }
    },
    { { SIMDE_FLOAT64_C(  -501.62), SIMDE_FLOAT64_C(  -808.75) },
      { SIMDE_FLOAT64_C(   384.46), SIMDE_FLOAT64_C(   569.38) },
      { SIMDE_FLOAT64_C(   850.27), SIMDE_FLOAT64_C(  -509.62) },
      {
      SIMDE_FLOAT64_C(  -501.62),
      SIMDE_FLOAT64_C(   384.46),
      SIMDE_FLOAT64_C(   850.27),
      SIMDE_FLOAT64_C(  -808.75),
      SIMDE_FLOAT64_C(   569.38),
      SIMDE_FLOAT64_C(  -509.62),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x3_t r_ = { { simde_vld1q_f64(test_vec[i].r0),
                                 simde_vld1q_f64(test_vec[i].r1),
                                 simde_vld1q_f64(test_vec[i].r2), } };

    simde_float64_t a_[6];
    simde_vst3q_f64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3q_f64(a_);
    simde_test_arm_neon_assert_equal_f64x2(r_.val[0], simde_vld1q_f64(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f64x2(r_.val[1], simde_vld1q_f64(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f64x2(r_.val[2], simde_vld1q_f64(test_vec[i].r2), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a0 = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t a1 = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2_t a2 = simde_test_arm_neon_random_f64x2(-1000.0f, 1000.0f);
    simde_float64x2x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_f64x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_float64_t buf[6];
    simde_vst3q_f64(buf, a);

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
test_simde_vst3q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r0[16];
    int8_t r1[16];
    int8_t r2[16];
    int8_t a[48];
  } test_vec[] = {
    { {  INT8_C(  38), -INT8_C(  65),  INT8_C(  42),  INT8_C(  56),  INT8_C(  36), -INT8_C(  28), -INT8_C(  63), -INT8_C(  86),
         INT8_C(  15),  INT8_C( 115),  INT8_C(  26),  INT8_C(  40), -INT8_C(  25),  INT8_C(  24), -INT8_C( 121),  INT8_C(  86) },
      {  INT8_C(  63), -INT8_C(  66), -INT8_C(  76), -INT8_C( 106),  INT8_C(  57), -INT8_C(  69), -INT8_C(  57), -INT8_C(  91),
        -INT8_C(  60), -INT8_C(  43), -INT8_C( 102), -INT8_C(  91), -INT8_C(  16), -INT8_C(  95),      INT8_MIN,  INT8_C(  22) },
      {  INT8_C(  97), -INT8_C(  86),  INT8_C(  79), -INT8_C( 123), -INT8_C( 114),  INT8_C(  16),  INT8_C(  47), -INT8_C(  99),
        -INT8_C( 124),  INT8_C(  73), -INT8_C(  58),  INT8_C( 107),  INT8_C(  97),  INT8_C(  77), -INT8_C(  63), -INT8_C(  96) },
      {
       INT8_C(  38),
       INT8_C(  63),
       INT8_C(  97),
      -INT8_C(  65),
      -INT8_C(  66),
      -INT8_C(  86),
       INT8_C(  42),
      -INT8_C(  76),
       INT8_C(  79),
       INT8_C(  56),
      -INT8_C( 106),
      -INT8_C( 123),
       INT8_C(  36),
       INT8_C(  57),
      -INT8_C( 114),
      -INT8_C(  28),
      -INT8_C(  69),
       INT8_C(  16),
      -INT8_C(  63),
      -INT8_C(  57),
       INT8_C(  47),
      -INT8_C(  86),
      -INT8_C(  91),
      -INT8_C(  99),
       INT8_C(  15),
      -INT8_C(  60),
      -INT8_C( 124),
       INT8_C( 115),
      -INT8_C(  43),
       INT8_C(  73),
       INT8_C(  26),
      -INT8_C( 102),
      -INT8_C(  58),
       INT8_C(  40),
      -INT8_C(  91),
       INT8_C( 107),
      -INT8_C(  25),
      -INT8_C(  16),
       INT8_C(  97),
       INT8_C(  24),
      -INT8_C(  95),
       INT8_C(  77),
      -INT8_C( 121),
           INT8_MIN,
      -INT8_C(  63),
       INT8_C(  86),
       INT8_C(  22),
      -INT8_C(  96),
      }
    },
    { {  INT8_C(  11),  INT8_C( 117),  INT8_C(  54),  INT8_C(  69),  INT8_C(  48), -INT8_C(   2), -INT8_C(  22), -INT8_C(  11),
        -INT8_C(  45), -INT8_C( 124), -INT8_C( 102), -INT8_C(  60),  INT8_C(  38),  INT8_C(  26), -INT8_C(  38), -INT8_C( 121) },
      { -INT8_C(  60),  INT8_C(  41),  INT8_C(  12),  INT8_C(  83),  INT8_C(  58),  INT8_C(  59), -INT8_C(  16), -INT8_C(  66),
        -INT8_C( 123), -INT8_C(  74),  INT8_C(  41), -INT8_C(  26),  INT8_C(   4), -INT8_C(  21), -INT8_C( 121),  INT8_C(  15) },
      {  INT8_C(  96), -INT8_C(  67),  INT8_C(  84), -INT8_C( 111), -INT8_C(  69),  INT8_C(  62), -INT8_C( 122), -INT8_C( 113),
        -INT8_C(  61),  INT8_C(  32),  INT8_C(  83), -INT8_C(  23),  INT8_C(  58),  INT8_C(  45),  INT8_C( 112), -INT8_C(   2) },
      {
       INT8_C(  11),
      -INT8_C(  60),
       INT8_C(  96),
       INT8_C( 117),
       INT8_C(  41),
      -INT8_C(  67),
       INT8_C(  54),
       INT8_C(  12),
       INT8_C(  84),
       INT8_C(  69),
       INT8_C(  83),
      -INT8_C( 111),
       INT8_C(  48),
       INT8_C(  58),
      -INT8_C(  69),
      -INT8_C(   2),
       INT8_C(  59),
       INT8_C(  62),
      -INT8_C(  22),
      -INT8_C(  16),
      -INT8_C( 122),
      -INT8_C(  11),
      -INT8_C(  66),
      -INT8_C( 113),
      -INT8_C(  45),
      -INT8_C( 123),
      -INT8_C(  61),
      -INT8_C( 124),
      -INT8_C(  74),
       INT8_C(  32),
      -INT8_C( 102),
       INT8_C(  41),
       INT8_C(  83),
      -INT8_C(  60),
      -INT8_C(  26),
      -INT8_C(  23),
       INT8_C(  38),
       INT8_C(   4),
       INT8_C(  58),
       INT8_C(  26),
      -INT8_C(  21),
       INT8_C(  45),
      -INT8_C(  38),
      -INT8_C( 121),
       INT8_C( 112),
      -INT8_C( 121),
       INT8_C(  15),
      -INT8_C(   2),
      }
    },
    { {  INT8_C(  87),  INT8_C( 124),  INT8_C(  81), -INT8_C( 111), -INT8_C(  73),  INT8_C(  66),  INT8_C(  79),  INT8_C(  60),
        -INT8_C(   8),  INT8_C( 120),  INT8_C(  35), -INT8_C(   4),  INT8_C(  99), -INT8_C(  86),  INT8_C(  12), -INT8_C(  60) },
      {  INT8_C( 103),  INT8_C(  96),  INT8_C(  85),  INT8_C(  35), -INT8_C(  97), -INT8_C(  37), -INT8_C(  78),  INT8_C(  98),
        -INT8_C(   5),  INT8_C(   5),  INT8_C(  75),  INT8_C(  53),  INT8_C(  50), -INT8_C(  69),  INT8_C(  51), -INT8_C( 119) },
      {  INT8_C(  55), -INT8_C( 123),  INT8_C(  26), -INT8_C(  18), -INT8_C(  57),  INT8_C( 105),  INT8_C(  43), -INT8_C(  65),
        -INT8_C(  30),  INT8_C(  78), -INT8_C(  68),  INT8_C(  69), -INT8_C(   8), -INT8_C(  56),  INT8_C(   9),  INT8_C(  95) },
      {
       INT8_C(  87),
       INT8_C( 103),
       INT8_C(  55),
       INT8_C( 124),
       INT8_C(  96),
      -INT8_C( 123),
       INT8_C(  81),
       INT8_C(  85),
       INT8_C(  26),
      -INT8_C( 111),
       INT8_C(  35),
      -INT8_C(  18),
      -INT8_C(  73),
      -INT8_C(  97),
      -INT8_C(  57),
       INT8_C(  66),
      -INT8_C(  37),
       INT8_C( 105),
       INT8_C(  79),
      -INT8_C(  78),
       INT8_C(  43),
       INT8_C(  60),
       INT8_C(  98),
      -INT8_C(  65),
      -INT8_C(   8),
      -INT8_C(   5),
      -INT8_C(  30),
       INT8_C( 120),
       INT8_C(   5),
       INT8_C(  78),
       INT8_C(  35),
       INT8_C(  75),
      -INT8_C(  68),
      -INT8_C(   4),
       INT8_C(  53),
       INT8_C(  69),
       INT8_C(  99),
       INT8_C(  50),
      -INT8_C(   8),
      -INT8_C(  86),
      -INT8_C(  69),
      -INT8_C(  56),
       INT8_C(  12),
       INT8_C(  51),
       INT8_C(   9),
      -INT8_C(  60),
      -INT8_C( 119),
       INT8_C(  95),
      }
    },
    { {  INT8_C(  40),  INT8_C(  94), -INT8_C( 126), -INT8_C(  57),  INT8_C(  57),  INT8_C(  52),  INT8_C(  41),  INT8_C(  52),
         INT8_C(  57),  INT8_C( 116),  INT8_C( 105),  INT8_C( 108),  INT8_C(  47), -INT8_C(  99), -INT8_C(  11),  INT8_C( 102) },
      {  INT8_C(  34),  INT8_C(  16),  INT8_C(  85), -INT8_C(  23),  INT8_C( 121),      INT8_MIN, -INT8_C(  88),  INT8_C(  91),
        -INT8_C(  50),  INT8_C( 100), -INT8_C(  95), -INT8_C(  58),  INT8_C(  44), -INT8_C(  86),  INT8_C(  37),  INT8_C(  85) },
      {  INT8_C(   9), -INT8_C(  88),  INT8_C(  28),  INT8_C(  66), -INT8_C(  36),  INT8_C(  70),  INT8_C( 119),  INT8_C(  22),
        -INT8_C(  70), -INT8_C(  32), -INT8_C( 126), -INT8_C(  22),  INT8_C( 125),  INT8_C( 119),  INT8_C(  80), -INT8_C(  97) },
      {
       INT8_C(  40),
       INT8_C(  34),
       INT8_C(   9),
       INT8_C(  94),
       INT8_C(  16),
      -INT8_C(  88),
      -INT8_C( 126),
       INT8_C(  85),
       INT8_C(  28),
      -INT8_C(  57),
      -INT8_C(  23),
       INT8_C(  66),
       INT8_C(  57),
       INT8_C( 121),
      -INT8_C(  36),
       INT8_C(  52),
           INT8_MIN,
       INT8_C(  70),
       INT8_C(  41),
      -INT8_C(  88),
       INT8_C( 119),
       INT8_C(  52),
       INT8_C(  91),
       INT8_C(  22),
       INT8_C(  57),
      -INT8_C(  50),
      -INT8_C(  70),
       INT8_C( 116),
       INT8_C( 100),
      -INT8_C(  32),
       INT8_C( 105),
      -INT8_C(  95),
      -INT8_C( 126),
       INT8_C( 108),
      -INT8_C(  58),
      -INT8_C(  22),
       INT8_C(  47),
       INT8_C(  44),
       INT8_C( 125),
      -INT8_C(  99),
      -INT8_C(  86),
       INT8_C( 119),
      -INT8_C(  11),
       INT8_C(  37),
       INT8_C(  80),
       INT8_C( 102),
       INT8_C(  85),
      -INT8_C(  97),
      }
    },
    { { -INT8_C( 121), -INT8_C(  91), -INT8_C( 120),  INT8_C(   1),  INT8_C(  37),  INT8_C(  49),  INT8_C(  92), -INT8_C(  13),
        -INT8_C( 107), -INT8_C(   3), -INT8_C(  71), -INT8_C(  62), -INT8_C(  88), -INT8_C(  33),  INT8_C(  23), -INT8_C(  79) },
      { -INT8_C( 121),  INT8_C(  51), -INT8_C(  13),  INT8_C(  99),  INT8_C( 121),  INT8_C( 106),  INT8_C( 121),  INT8_C(  52),
         INT8_C(  75), -INT8_C(   5),  INT8_C(  30), -INT8_C(  56),  INT8_C( 115),  INT8_C( 110),  INT8_C( 104), -INT8_C(   6) },
      {  INT8_C(  20), -INT8_C(  16), -INT8_C(   5),  INT8_C(  57),  INT8_C(  33),  INT8_C(  88),  INT8_C(  45), -INT8_C(  73),
         INT8_C(  85), -INT8_C(  26),  INT8_C( 121), -INT8_C(   3), -INT8_C(  59), -INT8_C( 112), -INT8_C(  82),  INT8_C(  76) },
      {
      -INT8_C( 121),
      -INT8_C( 121),
       INT8_C(  20),
      -INT8_C(  91),
       INT8_C(  51),
      -INT8_C(  16),
      -INT8_C( 120),
      -INT8_C(  13),
      -INT8_C(   5),
       INT8_C(   1),
       INT8_C(  99),
       INT8_C(  57),
       INT8_C(  37),
       INT8_C( 121),
       INT8_C(  33),
       INT8_C(  49),
       INT8_C( 106),
       INT8_C(  88),
       INT8_C(  92),
       INT8_C( 121),
       INT8_C(  45),
      -INT8_C(  13),
       INT8_C(  52),
      -INT8_C(  73),
      -INT8_C( 107),
       INT8_C(  75),
       INT8_C(  85),
      -INT8_C(   3),
      -INT8_C(   5),
      -INT8_C(  26),
      -INT8_C(  71),
       INT8_C(  30),
       INT8_C( 121),
      -INT8_C(  62),
      -INT8_C(  56),
      -INT8_C(   3),
      -INT8_C(  88),
       INT8_C( 115),
      -INT8_C(  59),
      -INT8_C(  33),
       INT8_C( 110),
      -INT8_C( 112),
       INT8_C(  23),
       INT8_C( 104),
      -INT8_C(  82),
      -INT8_C(  79),
      -INT8_C(   6),
       INT8_C(  76),
      }
    },
    { { -INT8_C(  61), -INT8_C(  94), -INT8_C(  80),  INT8_C(  61),  INT8_C(  12),  INT8_C(  41),  INT8_C( 113),  INT8_C(  87),
         INT8_C(  37), -INT8_C( 113),  INT8_C(  32), -INT8_C( 104), -INT8_C(   3), -INT8_C( 120), -INT8_C( 110),  INT8_C(  17) },
      {  INT8_C( 120), -INT8_C( 114),  INT8_C(  75), -INT8_C( 102), -INT8_C(  26),  INT8_C( 120),  INT8_C(  81),  INT8_C(  59),
         INT8_C(  94), -INT8_C(  54),  INT8_C(  57),  INT8_C(  36),  INT8_C(  90), -INT8_C(  25),  INT8_C( 112),  INT8_C(  29) },
      { -INT8_C( 119),  INT8_C(  32),  INT8_C(  90), -INT8_C( 106),  INT8_C(  74), -INT8_C(  53), -INT8_C(  19),  INT8_C( 111),
         INT8_C(  90),  INT8_C(  13),  INT8_C(   7),  INT8_C(  88), -INT8_C( 107), -INT8_C( 103),  INT8_C( 105),  INT8_C(  14) },
      {
      -INT8_C(  61),
       INT8_C( 120),
      -INT8_C( 119),
      -INT8_C(  94),
      -INT8_C( 114),
       INT8_C(  32),
      -INT8_C(  80),
       INT8_C(  75),
       INT8_C(  90),
       INT8_C(  61),
      -INT8_C( 102),
      -INT8_C( 106),
       INT8_C(  12),
      -INT8_C(  26),
       INT8_C(  74),
       INT8_C(  41),
       INT8_C( 120),
      -INT8_C(  53),
       INT8_C( 113),
       INT8_C(  81),
      -INT8_C(  19),
       INT8_C(  87),
       INT8_C(  59),
       INT8_C( 111),
       INT8_C(  37),
       INT8_C(  94),
       INT8_C(  90),
      -INT8_C( 113),
      -INT8_C(  54),
       INT8_C(  13),
       INT8_C(  32),
       INT8_C(  57),
       INT8_C(   7),
      -INT8_C( 104),
       INT8_C(  36),
       INT8_C(  88),
      -INT8_C(   3),
       INT8_C(  90),
      -INT8_C( 107),
      -INT8_C( 120),
      -INT8_C(  25),
      -INT8_C( 103),
      -INT8_C( 110),
       INT8_C( 112),
       INT8_C( 105),
       INT8_C(  17),
       INT8_C(  29),
       INT8_C(  14),
      }
    },
    { {  INT8_C(  39), -INT8_C(  76), -INT8_C(  88),  INT8_C(  13),  INT8_C(  44), -INT8_C(   7),  INT8_C(  73), -INT8_C( 117),
        -INT8_C(  61), -INT8_C( 126), -INT8_C(  81),  INT8_C(  29),  INT8_C( 105),  INT8_C(  31),  INT8_C(  58), -INT8_C(  13) },
      {  INT8_C(  64), -INT8_C( 107), -INT8_C( 119), -INT8_C( 118),  INT8_C(  96),  INT8_C( 118), -INT8_C(   7), -INT8_C(  69),
        -INT8_C( 124),  INT8_C(   0),  INT8_C(  19),  INT8_C(  25), -INT8_C( 103),  INT8_C( 124),  INT8_C(  39), -INT8_C(  63) },
      {  INT8_C(  49), -INT8_C(  49), -INT8_C(  50),  INT8_C(  93), -INT8_C(  56),  INT8_C(  23), -INT8_C(  24), -INT8_C( 117),
        -INT8_C( 103), -INT8_C( 105), -INT8_C(  88),  INT8_C(   3), -INT8_C(  73), -INT8_C(  29), -INT8_C(  10), -INT8_C(   9) },
      {
       INT8_C(  39),
       INT8_C(  64),
       INT8_C(  49),
      -INT8_C(  76),
      -INT8_C( 107),
      -INT8_C(  49),
      -INT8_C(  88),
      -INT8_C( 119),
      -INT8_C(  50),
       INT8_C(  13),
      -INT8_C( 118),
       INT8_C(  93),
       INT8_C(  44),
       INT8_C(  96),
      -INT8_C(  56),
      -INT8_C(   7),
       INT8_C( 118),
       INT8_C(  23),
       INT8_C(  73),
      -INT8_C(   7),
      -INT8_C(  24),
      -INT8_C( 117),
      -INT8_C(  69),
      -INT8_C( 117),
      -INT8_C(  61),
      -INT8_C( 124),
      -INT8_C( 103),
      -INT8_C( 126),
       INT8_C(   0),
      -INT8_C( 105),
      -INT8_C(  81),
       INT8_C(  19),
      -INT8_C(  88),
       INT8_C(  29),
       INT8_C(  25),
       INT8_C(   3),
       INT8_C( 105),
      -INT8_C( 103),
      -INT8_C(  73),
       INT8_C(  31),
       INT8_C( 124),
      -INT8_C(  29),
       INT8_C(  58),
       INT8_C(  39),
      -INT8_C(  10),
      -INT8_C(  13),
      -INT8_C(  63),
      -INT8_C(   9),
      }
    },
    { {  INT8_C( 120),      INT8_MAX, -INT8_C( 127), -INT8_C(  40), -INT8_C(  11),  INT8_C( 122), -INT8_C( 109),  INT8_C( 121),
         INT8_C( 122), -INT8_C(  90), -INT8_C( 109),  INT8_C(  19),  INT8_C(  35), -INT8_C(  70), -INT8_C(  44),  INT8_C(  84) },
      { -INT8_C( 118), -INT8_C(  93), -INT8_C(  79),  INT8_C(  82), -INT8_C(  70), -INT8_C( 102), -INT8_C(  34),  INT8_C(  84),
         INT8_C(  49), -INT8_C( 122),  INT8_C(  87), -INT8_C(  24),  INT8_C( 105),  INT8_C(  77), -INT8_C(  33), -INT8_C(  31) },
      { -INT8_C(  52),  INT8_C(  96), -INT8_C(  70), -INT8_C(  63), -INT8_C(  38),  INT8_C(  77),  INT8_C(  59),  INT8_C(  84),
        -INT8_C(  12), -INT8_C(  50),  INT8_C( 104),  INT8_C(  23), -INT8_C( 120),  INT8_C(  60),  INT8_C( 107),  INT8_C(  18) },
      {
       INT8_C( 120),
      -INT8_C( 118),
      -INT8_C(  52),
           INT8_MAX,
      -INT8_C(  93),
       INT8_C(  96),
      -INT8_C( 127),
      -INT8_C(  79),
      -INT8_C(  70),
      -INT8_C(  40),
       INT8_C(  82),
      -INT8_C(  63),
      -INT8_C(  11),
      -INT8_C(  70),
      -INT8_C(  38),
       INT8_C( 122),
      -INT8_C( 102),
       INT8_C(  77),
      -INT8_C( 109),
      -INT8_C(  34),
       INT8_C(  59),
       INT8_C( 121),
       INT8_C(  84),
       INT8_C(  84),
       INT8_C( 122),
       INT8_C(  49),
      -INT8_C(  12),
      -INT8_C(  90),
      -INT8_C( 122),
      -INT8_C(  50),
      -INT8_C( 109),
       INT8_C(  87),
       INT8_C( 104),
       INT8_C(  19),
      -INT8_C(  24),
       INT8_C(  23),
       INT8_C(  35),
       INT8_C( 105),
      -INT8_C( 120),
      -INT8_C(  70),
       INT8_C(  77),
       INT8_C(  60),
      -INT8_C(  44),
      -INT8_C(  33),
       INT8_C( 107),
       INT8_C(  84),
      -INT8_C(  31),
       INT8_C(  18),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x3_t r_ = { { simde_vld1q_s8(test_vec[i].r0),
                               simde_vld1q_s8(test_vec[i].r1),
                               simde_vld1q_s8(test_vec[i].r2), } };

    int8_t a_[48];
    simde_vst3q_s8(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3q_s8(a_);
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
    simde_int8x16x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_i8x16(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    int8_t buf[48];
    simde_vst3q_s8(buf, a);

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
test_simde_vst3q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r0[8];
    int16_t r1[8];
    int16_t r2[8];
    int16_t a[24];
  } test_vec[] = {
    { { -INT16_C(  7093),  INT16_C(  1303), -INT16_C( 17439), -INT16_C( 22859),  INT16_C( 31645),  INT16_C(  1370),  INT16_C( 32280), -INT16_C( 15440) },
      {  INT16_C( 13391),  INT16_C(  3162),  INT16_C(  2283),  INT16_C( 24508), -INT16_C(  9937),  INT16_C( 27470),  INT16_C( 29591), -INT16_C(  7429) },
      {  INT16_C(  4695),  INT16_C( 14823), -INT16_C( 25139),  INT16_C( 27359),  INT16_C( 14616),  INT16_C( 12399),  INT16_C(  8375),  INT16_C(  1779) },
      {
      -INT16_C(  7093),
       INT16_C( 13391),
       INT16_C(  4695),
       INT16_C(  1303),
       INT16_C(  3162),
       INT16_C( 14823),
      -INT16_C( 17439),
       INT16_C(  2283),
      -INT16_C( 25139),
      -INT16_C( 22859),
       INT16_C( 24508),
       INT16_C( 27359),
       INT16_C( 31645),
      -INT16_C(  9937),
       INT16_C( 14616),
       INT16_C(  1370),
       INT16_C( 27470),
       INT16_C( 12399),
       INT16_C( 32280),
       INT16_C( 29591),
       INT16_C(  8375),
      -INT16_C( 15440),
      -INT16_C(  7429),
       INT16_C(  1779),
      }
    },
    { {  INT16_C( 19796),  INT16_C( 16147), -INT16_C( 12459), -INT16_C( 31586), -INT16_C(  4952),  INT16_C( 16368), -INT16_C(  5280), -INT16_C( 18655) },
      {  INT16_C(  2557), -INT16_C( 13328), -INT16_C( 12378), -INT16_C( 16843), -INT16_C( 23288), -INT16_C( 16402), -INT16_C(  7483),  INT16_C(  6598) },
      { -INT16_C(  9937), -INT16_C( 31400), -INT16_C(  2392),  INT16_C( 20489), -INT16_C(  1566),  INT16_C( 17040), -INT16_C( 19996), -INT16_C(  7430) },
      {
       INT16_C( 19796),
       INT16_C(  2557),
      -INT16_C(  9937),
       INT16_C( 16147),
      -INT16_C( 13328),
      -INT16_C( 31400),
      -INT16_C( 12459),
      -INT16_C( 12378),
      -INT16_C(  2392),
      -INT16_C( 31586),
      -INT16_C( 16843),
       INT16_C( 20489),
      -INT16_C(  4952),
      -INT16_C( 23288),
      -INT16_C(  1566),
       INT16_C( 16368),
      -INT16_C( 16402),
       INT16_C( 17040),
      -INT16_C(  5280),
      -INT16_C(  7483),
      -INT16_C( 19996),
      -INT16_C( 18655),
       INT16_C(  6598),
      -INT16_C(  7430),
      }
    },
    { { -INT16_C(  5446),  INT16_C( 24749), -INT16_C(  7494), -INT16_C( 15842),  INT16_C(  3463),  INT16_C( 19586),  INT16_C( 18671),  INT16_C(  7781) },
      { -INT16_C( 17119), -INT16_C( 13917), -INT16_C( 21069), -INT16_C( 27111), -INT16_C( 22106), -INT16_C( 29736), -INT16_C( 11685),  INT16_C(  5485) },
      {  INT16_C(  6845),  INT16_C( 30582), -INT16_C( 27396), -INT16_C( 31687), -INT16_C( 17503), -INT16_C( 28464),  INT16_C( 13827),  INT16_C(  9391) },
      {
      -INT16_C(  5446),
      -INT16_C( 17119),
       INT16_C(  6845),
       INT16_C( 24749),
      -INT16_C( 13917),
       INT16_C( 30582),
      -INT16_C(  7494),
      -INT16_C( 21069),
      -INT16_C( 27396),
      -INT16_C( 15842),
      -INT16_C( 27111),
      -INT16_C( 31687),
       INT16_C(  3463),
      -INT16_C( 22106),
      -INT16_C( 17503),
       INT16_C( 19586),
      -INT16_C( 29736),
      -INT16_C( 28464),
       INT16_C( 18671),
      -INT16_C( 11685),
       INT16_C( 13827),
       INT16_C(  7781),
       INT16_C(  5485),
       INT16_C(  9391),
      }
    },
    { {  INT16_C( 21235), -INT16_C( 22547),  INT16_C(  2047), -INT16_C( 22979),  INT16_C(  5552),  INT16_C(  2865), -INT16_C( 24856), -INT16_C( 23263) },
      { -INT16_C( 26696), -INT16_C( 19428),  INT16_C( 21803), -INT16_C( 13000),  INT16_C(  2321),  INT16_C(  5213),  INT16_C(  3135),  INT16_C( 12857) },
      {  INT16_C(  9823),  INT16_C( 24281),  INT16_C(  5677), -INT16_C(  8700),  INT16_C( 13612),  INT16_C(  5353),  INT16_C(  2771), -INT16_C( 29767) },
      {
       INT16_C( 21235),
      -INT16_C( 26696),
       INT16_C(  9823),
      -INT16_C( 22547),
      -INT16_C( 19428),
       INT16_C( 24281),
       INT16_C(  2047),
       INT16_C( 21803),
       INT16_C(  5677),
      -INT16_C( 22979),
      -INT16_C( 13000),
      -INT16_C(  8700),
       INT16_C(  5552),
       INT16_C(  2321),
       INT16_C( 13612),
       INT16_C(  2865),
       INT16_C(  5213),
       INT16_C(  5353),
      -INT16_C( 24856),
       INT16_C(  3135),
       INT16_C(  2771),
      -INT16_C( 23263),
       INT16_C( 12857),
      -INT16_C( 29767),
      }
    },
    { { -INT16_C( 10847), -INT16_C( 12992),  INT16_C( 30762),  INT16_C( 15258), -INT16_C(  2175), -INT16_C( 16304), -INT16_C( 30460),  INT16_C( 25587) },
      { -INT16_C( 13137), -INT16_C(  8767), -INT16_C( 14621),  INT16_C(  4027), -INT16_C( 23301), -INT16_C( 12509), -INT16_C(  9041),  INT16_C( 20570) },
      { -INT16_C( 25935), -INT16_C(  9443), -INT16_C( 18669), -INT16_C( 27625),  INT16_C( 26543), -INT16_C( 19627),  INT16_C( 18672), -INT16_C( 24810) },
      {
      -INT16_C( 10847),
      -INT16_C( 13137),
      -INT16_C( 25935),
      -INT16_C( 12992),
      -INT16_C(  8767),
      -INT16_C(  9443),
       INT16_C( 30762),
      -INT16_C( 14621),
      -INT16_C( 18669),
       INT16_C( 15258),
       INT16_C(  4027),
      -INT16_C( 27625),
      -INT16_C(  2175),
      -INT16_C( 23301),
       INT16_C( 26543),
      -INT16_C( 16304),
      -INT16_C( 12509),
      -INT16_C( 19627),
      -INT16_C( 30460),
      -INT16_C(  9041),
       INT16_C( 18672),
       INT16_C( 25587),
       INT16_C( 20570),
      -INT16_C( 24810),
      }
    },
    { { -INT16_C( 10476), -INT16_C(  2180),  INT16_C( 14237), -INT16_C( 26362),  INT16_C( 10716), -INT16_C( 29848), -INT16_C( 15867), -INT16_C( 18725) },
      { -INT16_C(  1699),  INT16_C( 28818), -INT16_C( 22096),  INT16_C( 24324),  INT16_C( 22800),  INT16_C(    18),  INT16_C( 10401), -INT16_C( 18785) },
      {  INT16_C(  7168), -INT16_C( 25171), -INT16_C( 19373),  INT16_C( 12086), -INT16_C( 24867), -INT16_C(  7238), -INT16_C( 27039), -INT16_C( 16743) },
      {
      -INT16_C( 10476),
      -INT16_C(  1699),
       INT16_C(  7168),
      -INT16_C(  2180),
       INT16_C( 28818),
      -INT16_C( 25171),
       INT16_C( 14237),
      -INT16_C( 22096),
      -INT16_C( 19373),
      -INT16_C( 26362),
       INT16_C( 24324),
       INT16_C( 12086),
       INT16_C( 10716),
       INT16_C( 22800),
      -INT16_C( 24867),
      -INT16_C( 29848),
       INT16_C(    18),
      -INT16_C(  7238),
      -INT16_C( 15867),
       INT16_C( 10401),
      -INT16_C( 27039),
      -INT16_C( 18725),
      -INT16_C( 18785),
      -INT16_C( 16743),
      }
    },
    { {  INT16_C( 11151),  INT16_C( 16174),  INT16_C( 13012), -INT16_C(  7009), -INT16_C( 20084),  INT16_C( 11748), -INT16_C( 31526), -INT16_C(  9501) },
      { -INT16_C( 28256), -INT16_C(  3209), -INT16_C( 20923),  INT16_C(  8739), -INT16_C(  8884), -INT16_C( 21243), -INT16_C( 24717),  INT16_C(   619) },
      { -INT16_C( 26166), -INT16_C( 24766), -INT16_C(  7732),  INT16_C( 22659),  INT16_C( 26770),  INT16_C( 27781),  INT16_C( 27116), -INT16_C( 29626) },
      {
       INT16_C( 11151),
      -INT16_C( 28256),
      -INT16_C( 26166),
       INT16_C( 16174),
      -INT16_C(  3209),
      -INT16_C( 24766),
       INT16_C( 13012),
      -INT16_C( 20923),
      -INT16_C(  7732),
      -INT16_C(  7009),
       INT16_C(  8739),
       INT16_C( 22659),
      -INT16_C( 20084),
      -INT16_C(  8884),
       INT16_C( 26770),
       INT16_C( 11748),
      -INT16_C( 21243),
       INT16_C( 27781),
      -INT16_C( 31526),
      -INT16_C( 24717),
       INT16_C( 27116),
      -INT16_C(  9501),
       INT16_C(   619),
      -INT16_C( 29626),
      }
    },
    { { -INT16_C( 16646),  INT16_C( 16255), -INT16_C( 23956), -INT16_C( 18335),  INT16_C( 26496), -INT16_C(  3226), -INT16_C( 12026), -INT16_C( 12042) },
      {  INT16_C( 14443),  INT16_C( 14191), -INT16_C(  3303), -INT16_C( 21617),  INT16_C(  5211),  INT16_C( 18200),  INT16_C( 24189),  INT16_C( 30675) },
      {  INT16_C( 21020), -INT16_C( 30538),  INT16_C(  6389),  INT16_C( 30017), -INT16_C( 22657), -INT16_C( 31384),  INT16_C( 24184), -INT16_C(  7339) },
      {
      -INT16_C( 16646),
       INT16_C( 14443),
       INT16_C( 21020),
       INT16_C( 16255),
       INT16_C( 14191),
      -INT16_C( 30538),
      -INT16_C( 23956),
      -INT16_C(  3303),
       INT16_C(  6389),
      -INT16_C( 18335),
      -INT16_C( 21617),
       INT16_C( 30017),
       INT16_C( 26496),
       INT16_C(  5211),
      -INT16_C( 22657),
      -INT16_C(  3226),
       INT16_C( 18200),
      -INT16_C( 31384),
      -INT16_C( 12026),
       INT16_C( 24189),
       INT16_C( 24184),
      -INT16_C( 12042),
       INT16_C( 30675),
      -INT16_C(  7339),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x3_t r_ = { { simde_vld1q_s16(test_vec[i].r0),
                               simde_vld1q_s16(test_vec[i].r1),
                               simde_vld1q_s16(test_vec[i].r2), } };

    int16_t a_[24];
    simde_vst3q_s16(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3q_s16(a_);
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
    simde_int16x8x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_i16x8(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    int16_t buf[24];
    simde_vst3q_s16(buf, a);

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
test_simde_vst3q_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r0[4];
    int32_t r1[4];
    int32_t r2[4];
    int32_t a[12];
  } test_vec[] = {
    { { -INT32_C(  1750261198),  INT32_C(   365683672),  INT32_C(   720805854),  INT32_C(    97011150) },
      {  INT32_C(   497640506),  INT32_C(  1227936960),  INT32_C(  1527923171), -INT32_C(  1488084108) },
      { -INT32_C(  1640039482), -INT32_C(  1112340002),  INT32_C(  1994893736),  INT32_C(   696037359) },
      {
      -INT32_C(  1750261198),
       INT32_C(   497640506),
      -INT32_C(  1640039482),
       INT32_C(   365683672),
       INT32_C(  1227936960),
      -INT32_C(  1112340002),
       INT32_C(   720805854),
       INT32_C(  1527923171),
       INT32_C(  1994893736),
       INT32_C(    97011150),
      -INT32_C(  1488084108),
       INT32_C(   696037359),
      }
    },
    { { -INT32_C(   733600492), -INT32_C(   602048519),  INT32_C(   741814200), -INT32_C(  1714190893) },
      {  INT32_C(  1580667264), -INT32_C(  1021580774), -INT32_C(  2110192749), -INT32_C(   961825358) },
      { -INT32_C(   744820006),  INT32_C(   565164137), -INT32_C(  1169299481), -INT32_C(   330096276) },
      {
      -INT32_C(   733600492),
       INT32_C(  1580667264),
      -INT32_C(   744820006),
      -INT32_C(   602048519),
      -INT32_C(  1021580774),
       INT32_C(   565164137),
       INT32_C(   741814200),
      -INT32_C(  2110192749),
      -INT32_C(  1169299481),
      -INT32_C(  1714190893),
      -INT32_C(   961825358),
      -INT32_C(   330096276),
      }
    },
    { {  INT32_C(  1296730674),  INT32_C(   135292532),  INT32_C(   462047593), -INT32_C(   639486209) },
      { -INT32_C(  1850901464),  INT32_C(   481451060), -INT32_C(  1344864445),  INT32_C(  1402677792) },
      {  INT32_C(   698410676), -INT32_C(  1255034804), -INT32_C(   120538119),  INT32_C(   433238769) },
      {
       INT32_C(  1296730674),
      -INT32_C(  1850901464),
       INT32_C(   698410676),
       INT32_C(   135292532),
       INT32_C(   481451060),
      -INT32_C(  1255034804),
       INT32_C(   462047593),
      -INT32_C(  1344864445),
      -INT32_C(   120538119),
      -INT32_C(   639486209),
       INT32_C(  1402677792),
       INT32_C(   433238769),
      }
    },
    { {  INT32_C(  1672118063),  INT32_C(   528440539),  INT32_C(  2093897308),  INT32_C(   886008448) },
      { -INT32_C(  1671598256),  INT32_C(   424775199),  INT32_C(   990978378),  INT32_C(    55960532) },
      {  INT32_C(  1046937442), -INT32_C(  1201805732), -INT32_C(  1137431748), -INT32_C(   437255019) },
      {
       INT32_C(  1672118063),
      -INT32_C(  1671598256),
       INT32_C(  1046937442),
       INT32_C(   528440539),
       INT32_C(   424775199),
      -INT32_C(  1201805732),
       INT32_C(  2093897308),
       INT32_C(   990978378),
      -INT32_C(  1137431748),
       INT32_C(   886008448),
       INT32_C(    55960532),
      -INT32_C(   437255019),
      }
    },
    { { -INT32_C(  1820242317),  INT32_C(   648860380), -INT32_C(   933052940),  INT32_C(    63682465) },
      {  INT32_C(   306262454),  INT32_C(  1405787671),  INT32_C(  1594884042),  INT32_C(  1984233475) },
      {  INT32_C(   705283662), -INT32_C(  1924024935),  INT32_C(   341160819),  INT32_C(   538386538) },
      {
      -INT32_C(  1820242317),
       INT32_C(   306262454),
       INT32_C(   705283662),
       INT32_C(   648860380),
       INT32_C(  1405787671),
      -INT32_C(  1924024935),
      -INT32_C(   933052940),
       INT32_C(  1594884042),
       INT32_C(   341160819),
       INT32_C(    63682465),
       INT32_C(  1984233475),
       INT32_C(   538386538),
      }
    },
    { {  INT32_C(  1764972881), -INT32_C(  1044578825), -INT32_C(    14562052),  INT32_C(   443967180) },
      { -INT32_C(   985366740), -INT32_C(  1470982859), -INT32_C(  1296259256),  INT32_C(   433312711) },
      {  INT32_C(   612501036),  INT32_C(    15023619), -INT32_C(   687929846), -INT32_C(  1712294548) },
      {
       INT32_C(  1764972881),
      -INT32_C(   985366740),
       INT32_C(   612501036),
      -INT32_C(  1044578825),
      -INT32_C(  1470982859),
       INT32_C(    15023619),
      -INT32_C(    14562052),
      -INT32_C(  1296259256),
      -INT32_C(   687929846),
       INT32_C(   443967180),
       INT32_C(   433312711),
      -INT32_C(  1712294548),
      }
    },
    { {  INT32_C(   710817269),  INT32_C(   332575178),  INT32_C(   549817944), -INT32_C(  1908828063) },
      { -INT32_C(  1565344866),  INT32_C(    77764601),  INT32_C(   182100382),  INT32_C(   212060951) },
      { -INT32_C(   902430208),  INT32_C(   199035059), -INT32_C(   148135018), -INT32_C(   628792261) },
      {
       INT32_C(   710817269),
      -INT32_C(  1565344866),
      -INT32_C(   902430208),
       INT32_C(   332575178),
       INT32_C(    77764601),
       INT32_C(   199035059),
       INT32_C(   549817944),
       INT32_C(   182100382),
      -INT32_C(   148135018),
      -INT32_C(  1908828063),
       INT32_C(   212060951),
      -INT32_C(   628792261),
      }
    },
    { {  INT32_C(   427570975),  INT32_C(  1830624975), -INT32_C(   696780865), -INT32_C(  1025369150) },
      { -INT32_C(   796059619), -INT32_C(  1227134432),  INT32_C(  1236141837), -INT32_C(  1960627349) },
      {  INT32_C(   983867243),  INT32_C(  2091368893),  INT32_C(  2069044920),  INT32_C(  1446851897) },
      {
       INT32_C(   427570975),
      -INT32_C(   796059619),
       INT32_C(   983867243),
       INT32_C(  1830624975),
      -INT32_C(  1227134432),
       INT32_C(  2091368893),
      -INT32_C(   696780865),
       INT32_C(  1236141837),
       INT32_C(  2069044920),
      -INT32_C(  1025369150),
      -INT32_C(  1960627349),
       INT32_C(  1446851897),
      }
    },

  };


  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x3_t r_ = { { simde_vld1q_s32(test_vec[i].r0),
                               simde_vld1q_s32(test_vec[i].r1),
                               simde_vld1q_s32(test_vec[i].r2), } };

    int32_t a_[12];
    simde_vst3q_s32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3q_s32(a_);
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
    simde_int32x4x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_i32x4(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    int32_t buf[12];
    simde_vst3q_s32(buf, a);

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
test_simde_vst3q_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r0[2];
    int64_t r1[2];
    int64_t r2[2];
    int64_t a[6];
  } test_vec[] = {
    { { -INT64_C(  635012862125708663), -INT64_C( 4551834836964699426) },
      { -INT64_C( 6853432729242667566), -INT64_C(  286868685105955221) },
      {  INT64_C( 1108378301783684416),  INT64_C( 5650045543870290514) },
      {
      -INT64_C(  635012862125708663),
      -INT64_C( 6853432729242667566),
       INT64_C( 1108378301783684416),
      -INT64_C( 4551834836964699426),
      -INT64_C(  286868685105955221),
       INT64_C( 5650045543870290514),
      }
    },
    { { -INT64_C(   49088157496910733),  INT64_C( 8829424968667718680) },
      {  INT64_C( 3306001507121699489),  INT64_C( 9073411890563255072) },
      {  INT64_C( 6245507785642976025),  INT64_C( 2349307249855435749) },
      {
      -INT64_C(   49088157496910733),
       INT64_C( 3306001507121699489),
       INT64_C( 6245507785642976025),
       INT64_C( 8829424968667718680),
       INT64_C( 9073411890563255072),
       INT64_C( 2349307249855435749),
      }
    },
    { { -INT64_C( 1833858103574888572), -INT64_C( 5303429886675558177) },
      { -INT64_C(  313828010536757999),  INT64_C( 8557601191857129251) },
      {  INT64_C( 7412750748315137075), -INT64_C( 2155897315551911231) },
      {
      -INT64_C( 1833858103574888572),
      -INT64_C(  313828010536757999),
       INT64_C( 7412750748315137075),
      -INT64_C( 5303429886675558177),
       INT64_C( 8557601191857129251),
      -INT64_C( 2155897315551911231),
      }
    },
    { { -INT64_C( 6170821512464861365),  INT64_C( 6900656108198459229) },
      { -INT64_C( 4850315250566129214),  INT64_C(   93220673490190233) },
      { -INT64_C( 5775937637409719130), -INT64_C(  882492009611386058) },
      {
      -INT64_C( 6170821512464861365),
      -INT64_C( 4850315250566129214),
      -INT64_C( 5775937637409719130),
       INT64_C( 6900656108198459229),
       INT64_C(   93220673490190233),
      -INT64_C(  882492009611386058),
      }
    },
    { { -INT64_C( 1724054782324434852),  INT64_C(  190168630465539564) },
      { -INT64_C(  424455724669598438),  INT64_C( 4057774997028739627) },
      {  INT64_C( 7380732911912193333),  INT64_C( 8515650882758033358) },
      {
      -INT64_C( 1724054782324434852),
      -INT64_C(  424455724669598438),
       INT64_C( 7380732911912193333),
       INT64_C(  190168630465539564),
       INT64_C( 4057774997028739627),
       INT64_C( 8515650882758033358),
      }
    },
    { { -INT64_C( 8110702121954615887),  INT64_C( 2102685047284616217) },
      {  INT64_C( 3290177900306939337),  INT64_C( 1054269323458622158) },
      { -INT64_C( 7145536389092440863), -INT64_C( 4123397312635354688) },
      {
      -INT64_C( 8110702121954615887),
       INT64_C( 3290177900306939337),
      -INT64_C( 7145536389092440863),
       INT64_C( 2102685047284616217),
       INT64_C( 1054269323458622158),
      -INT64_C( 4123397312635354688),
      }
    },
    { {  INT64_C( 4974423115788019836), -INT64_C( 4192551203404554395) },
      {  INT64_C(  699150071208039828), -INT64_C( 9122473133432814174) },
      { -INT64_C( 8603172560225668897), -INT64_C( 5733896944988058685) },
      {
       INT64_C( 4974423115788019836),
       INT64_C(  699150071208039828),
      -INT64_C( 8603172560225668897),
      -INT64_C( 4192551203404554395),
      -INT64_C( 9122473133432814174),
      -INT64_C( 5733896944988058685),
      }
    },
    { { -INT64_C(  233488605370681232), -INT64_C( 3799627498977987392) },
      { -INT64_C( 3954797066086932110), -INT64_C(  823070748352419640) },
      { -INT64_C( 7589848679630152874), -INT64_C( 4856393004998834204) },
      {
      -INT64_C(  233488605370681232),
      -INT64_C( 3954797066086932110),
      -INT64_C( 7589848679630152874),
      -INT64_C( 3799627498977987392),
      -INT64_C(  823070748352419640),
      -INT64_C( 4856393004998834204),
      }
    },

  };


  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x3_t r_ = { { simde_vld1q_s64(test_vec[i].r0),
                               simde_vld1q_s64(test_vec[i].r1),
                               simde_vld1q_s64(test_vec[i].r2), } };

    int64_t a_[6];
    simde_vst3q_s64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3q_s64(a_);
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
    simde_int64x2x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_i64x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    int64_t buf[6];
    simde_vst3q_s64(buf, a);

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
test_simde_vst3q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r0[16];
    uint8_t r1[16];
    uint8_t r2[16];
    uint8_t a[48];
  } test_vec[] = {
    { { UINT8_C(195), UINT8_C( 18), UINT8_C( 66), UINT8_C( 58), UINT8_C(252), UINT8_C(168), UINT8_C( 43), UINT8_C(  6),
        UINT8_C(179), UINT8_C( 14), UINT8_C(200), UINT8_C( 15), UINT8_C( 92), UINT8_C(143), UINT8_C( 19), UINT8_C(  5) },
      { UINT8_C(122), UINT8_C(198), UINT8_C(166), UINT8_C(235), UINT8_C(197), UINT8_C(222), UINT8_C(151), UINT8_C(111),
        UINT8_C( 19), UINT8_C(223), UINT8_C(248), UINT8_C(105), UINT8_C( 28), UINT8_C(  2), UINT8_C(173), UINT8_C(223) },
      { UINT8_C( 20), UINT8_C(240), UINT8_C( 26), UINT8_C( 16), UINT8_C(152), UINT8_C( 69), UINT8_C( 23), UINT8_C( 76),
        UINT8_C( 84), UINT8_C(223), UINT8_C( 91), UINT8_C(176), UINT8_C(111), UINT8_C(110), UINT8_C(181), UINT8_C(233) },
      {
      UINT8_C(195),
      UINT8_C(122),
      UINT8_C( 20),
      UINT8_C( 18),
      UINT8_C(198),
      UINT8_C(240),
      UINT8_C( 66),
      UINT8_C(166),
      UINT8_C( 26),
      UINT8_C( 58),
      UINT8_C(235),
      UINT8_C( 16),
      UINT8_C(252),
      UINT8_C(197),
      UINT8_C(152),
      UINT8_C(168),
      UINT8_C(222),
      UINT8_C( 69),
      UINT8_C( 43),
      UINT8_C(151),
      UINT8_C( 23),
      UINT8_C(  6),
      UINT8_C(111),
      UINT8_C( 76),
      UINT8_C(179),
      UINT8_C( 19),
      UINT8_C( 84),
      UINT8_C( 14),
      UINT8_C(223),
      UINT8_C(223),
      UINT8_C(200),
      UINT8_C(248),
      UINT8_C( 91),
      UINT8_C( 15),
      UINT8_C(105),
      UINT8_C(176),
      UINT8_C( 92),
      UINT8_C( 28),
      UINT8_C(111),
      UINT8_C(143),
      UINT8_C(  2),
      UINT8_C(110),
      UINT8_C( 19),
      UINT8_C(173),
      UINT8_C(181),
      UINT8_C(  5),
      UINT8_C(223),
      UINT8_C(233),
      }
    },
    { { UINT8_C( 53), UINT8_C( 92), UINT8_C(212), UINT8_C(250), UINT8_C( 58), UINT8_C(108), UINT8_C(105), UINT8_C( 78),
        UINT8_C( 75), UINT8_C( 97), UINT8_C(183), UINT8_C(103), UINT8_C( 99), UINT8_C(100), UINT8_C( 71), UINT8_C(119) },
      { UINT8_C( 84), UINT8_C( 97), UINT8_C(136), UINT8_C(237), UINT8_C(166), UINT8_C(159), UINT8_C( 57), UINT8_C(250),
        UINT8_C(126), UINT8_C(148), UINT8_C(171), UINT8_C(237), UINT8_C(  2), UINT8_C( 96), UINT8_C(215), UINT8_C( 55) },
      { UINT8_C(188), UINT8_C(171), UINT8_C( 49), UINT8_C(247), UINT8_C( 23), UINT8_C(154), UINT8_C( 69), UINT8_C( 98),
        UINT8_C(252), UINT8_C(252), UINT8_C(202), UINT8_C( 95), UINT8_C( 96), UINT8_C( 17), UINT8_C(215), UINT8_C(181) },
      {
      UINT8_C( 53),
      UINT8_C( 84),
      UINT8_C(188),
      UINT8_C( 92),
      UINT8_C( 97),
      UINT8_C(171),
      UINT8_C(212),
      UINT8_C(136),
      UINT8_C( 49),
      UINT8_C(250),
      UINT8_C(237),
      UINT8_C(247),
      UINT8_C( 58),
      UINT8_C(166),
      UINT8_C( 23),
      UINT8_C(108),
      UINT8_C(159),
      UINT8_C(154),
      UINT8_C(105),
      UINT8_C( 57),
      UINT8_C( 69),
      UINT8_C( 78),
      UINT8_C(250),
      UINT8_C( 98),
      UINT8_C( 75),
      UINT8_C(126),
      UINT8_C(252),
      UINT8_C( 97),
      UINT8_C(148),
      UINT8_C(252),
      UINT8_C(183),
      UINT8_C(171),
      UINT8_C(202),
      UINT8_C(103),
      UINT8_C(237),
      UINT8_C( 95),
      UINT8_C( 99),
      UINT8_C(  2),
      UINT8_C( 96),
      UINT8_C(100),
      UINT8_C( 96),
      UINT8_C( 17),
      UINT8_C( 71),
      UINT8_C(215),
      UINT8_C(215),
      UINT8_C(119),
      UINT8_C( 55),
      UINT8_C(181),
      }
    },
    { { UINT8_C(114), UINT8_C( 95), UINT8_C(162), UINT8_C( 24), UINT8_C(254), UINT8_C(219), UINT8_C( 19), UINT8_C(124),
        UINT8_C(111), UINT8_C(190), UINT8_C(106), UINT8_C(113), UINT8_C( 30), UINT8_C( 65), UINT8_C(169), UINT8_C(219) },
      { UINT8_C(236), UINT8_C(218), UINT8_C(210), UINT8_C(  4), UINT8_C(117), UINT8_C( 23), UINT8_C(102), UINT8_C(113),
        UINT8_C( 19), UINT8_C( 48), UINT8_C(208), UINT8_C(115), UINT8_C( 65), UINT8_C(167), UINT8_C( 40), UINT8_C(179) },
      { UINT8_C(  6), UINT8_C(202), UINT8_C(204), UINT8_C(  4), UINT8_C(165), UINT8_C(223), UINT8_C(129), UINT8_C( 20),
        UINT8_C(157), UINT8_C(235), UINT8_C(134), UINT8_C(187), UINT8_C( 44), UINT8_C( 47), UINT8_C(150), UINT8_C( 24) },
      {
      UINT8_C(114),
      UINT8_C(236),
      UINT8_C(  6),
      UINT8_C( 95),
      UINT8_C(218),
      UINT8_C(202),
      UINT8_C(162),
      UINT8_C(210),
      UINT8_C(204),
      UINT8_C( 24),
      UINT8_C(  4),
      UINT8_C(  4),
      UINT8_C(254),
      UINT8_C(117),
      UINT8_C(165),
      UINT8_C(219),
      UINT8_C( 23),
      UINT8_C(223),
      UINT8_C( 19),
      UINT8_C(102),
      UINT8_C(129),
      UINT8_C(124),
      UINT8_C(113),
      UINT8_C( 20),
      UINT8_C(111),
      UINT8_C( 19),
      UINT8_C(157),
      UINT8_C(190),
      UINT8_C( 48),
      UINT8_C(235),
      UINT8_C(106),
      UINT8_C(208),
      UINT8_C(134),
      UINT8_C(113),
      UINT8_C(115),
      UINT8_C(187),
      UINT8_C( 30),
      UINT8_C( 65),
      UINT8_C( 44),
      UINT8_C( 65),
      UINT8_C(167),
      UINT8_C( 47),
      UINT8_C(169),
      UINT8_C( 40),
      UINT8_C(150),
      UINT8_C(219),
      UINT8_C(179),
      UINT8_C( 24),
      }
    },
    { { UINT8_C(  9), UINT8_C(104), UINT8_C( 28), UINT8_C(126), UINT8_C(127), UINT8_C(131), UINT8_C(239), UINT8_C(146),
        UINT8_C(179), UINT8_C(192), UINT8_C(  6), UINT8_C(245), UINT8_C(103), UINT8_C( 46), UINT8_C(168), UINT8_C(110) },
      { UINT8_C(249), UINT8_C(116), UINT8_C(114), UINT8_C(158), UINT8_C( 83), UINT8_C(243), UINT8_C(179), UINT8_C(240),
        UINT8_C(222), UINT8_C( 57), UINT8_C(172), UINT8_C( 10), UINT8_C(104), UINT8_C( 66), UINT8_C( 35), UINT8_C(113) },
      { UINT8_C(171), UINT8_C( 63), UINT8_C(240), UINT8_C( 42), UINT8_C(194), UINT8_C(223), UINT8_C(189), UINT8_C(118),
        UINT8_C(159), UINT8_C(195), UINT8_C(107), UINT8_C(  7), UINT8_C(241), UINT8_C( 19), UINT8_C(117), UINT8_C(234) },
      {
      UINT8_C(  9),
      UINT8_C(249),
      UINT8_C(171),
      UINT8_C(104),
      UINT8_C(116),
      UINT8_C( 63),
      UINT8_C( 28),
      UINT8_C(114),
      UINT8_C(240),
      UINT8_C(126),
      UINT8_C(158),
      UINT8_C( 42),
      UINT8_C(127),
      UINT8_C( 83),
      UINT8_C(194),
      UINT8_C(131),
      UINT8_C(243),
      UINT8_C(223),
      UINT8_C(239),
      UINT8_C(179),
      UINT8_C(189),
      UINT8_C(146),
      UINT8_C(240),
      UINT8_C(118),
      UINT8_C(179),
      UINT8_C(222),
      UINT8_C(159),
      UINT8_C(192),
      UINT8_C( 57),
      UINT8_C(195),
      UINT8_C(  6),
      UINT8_C(172),
      UINT8_C(107),
      UINT8_C(245),
      UINT8_C( 10),
      UINT8_C(  7),
      UINT8_C(103),
      UINT8_C(104),
      UINT8_C(241),
      UINT8_C( 46),
      UINT8_C( 66),
      UINT8_C( 19),
      UINT8_C(168),
      UINT8_C( 35),
      UINT8_C(117),
      UINT8_C(110),
      UINT8_C(113),
      UINT8_C(234),
      }
    },
    { { UINT8_C(136), UINT8_C(231), UINT8_C(137), UINT8_C(219), UINT8_C(219), UINT8_C( 60), UINT8_C(204), UINT8_C(185),
        UINT8_C(117), UINT8_C(120), UINT8_C(196), UINT8_C(221), UINT8_C(186), UINT8_C(231), UINT8_C( 78), UINT8_C(101) },
      { UINT8_C( 38), UINT8_C( 62), UINT8_C(144), UINT8_C(233), UINT8_C( 30), UINT8_C( 77), UINT8_C( 95), UINT8_C(189),
        UINT8_C( 16), UINT8_C(202), UINT8_C(196), UINT8_C(  1), UINT8_C(221), UINT8_C( 57), UINT8_C(236), UINT8_C(101) },
      { UINT8_C( 33), UINT8_C(117), UINT8_C( 65), UINT8_C(252), UINT8_C(177), UINT8_C( 13), UINT8_C(181), UINT8_C( 38),
        UINT8_C(133), UINT8_C(121), UINT8_C(  3), UINT8_C( 63), UINT8_C( 96), UINT8_C( 81), UINT8_C(165), UINT8_C(135) },
      {
      UINT8_C(136),
      UINT8_C( 38),
      UINT8_C( 33),
      UINT8_C(231),
      UINT8_C( 62),
      UINT8_C(117),
      UINT8_C(137),
      UINT8_C(144),
      UINT8_C( 65),
      UINT8_C(219),
      UINT8_C(233),
      UINT8_C(252),
      UINT8_C(219),
      UINT8_C( 30),
      UINT8_C(177),
      UINT8_C( 60),
      UINT8_C( 77),
      UINT8_C( 13),
      UINT8_C(204),
      UINT8_C( 95),
      UINT8_C(181),
      UINT8_C(185),
      UINT8_C(189),
      UINT8_C( 38),
      UINT8_C(117),
      UINT8_C( 16),
      UINT8_C(133),
      UINT8_C(120),
      UINT8_C(202),
      UINT8_C(121),
      UINT8_C(196),
      UINT8_C(196),
      UINT8_C(  3),
      UINT8_C(221),
      UINT8_C(  1),
      UINT8_C( 63),
      UINT8_C(186),
      UINT8_C(221),
      UINT8_C( 96),
      UINT8_C(231),
      UINT8_C( 57),
      UINT8_C( 81),
      UINT8_C( 78),
      UINT8_C(236),
      UINT8_C(165),
      UINT8_C(101),
      UINT8_C(101),
      UINT8_C(135),
      }
    },
    { { UINT8_C(144), UINT8_C( 53), UINT8_C(112), UINT8_C(174), UINT8_C(130), UINT8_C(207), UINT8_C(107), UINT8_C(146),
        UINT8_C(153), UINT8_C( 48), UINT8_C(147), UINT8_C(118), UINT8_C(105), UINT8_C(127), UINT8_C(220), UINT8_C(138) },
      { UINT8_C(244), UINT8_C( 29), UINT8_C(134), UINT8_C(165), UINT8_C( 42), UINT8_C( 60), UINT8_C(203), UINT8_C(175),
        UINT8_C(181), UINT8_C(206), UINT8_C(238), UINT8_C( 22), UINT8_C( 32), UINT8_C(147), UINT8_C(157), UINT8_C(176) },
      { UINT8_C(200), UINT8_C( 13), UINT8_C( 94), UINT8_C( 74), UINT8_C(220), UINT8_C(201), UINT8_C(220), UINT8_C(117),
        UINT8_C(249), UINT8_C(112), UINT8_C(235), UINT8_C( 99), UINT8_C(239), UINT8_C(199), UINT8_C(237), UINT8_C(228) },
      {
      UINT8_C(144),
      UINT8_C(244),
      UINT8_C(200),
      UINT8_C( 53),
      UINT8_C( 29),
      UINT8_C( 13),
      UINT8_C(112),
      UINT8_C(134),
      UINT8_C( 94),
      UINT8_C(174),
      UINT8_C(165),
      UINT8_C( 74),
      UINT8_C(130),
      UINT8_C( 42),
      UINT8_C(220),
      UINT8_C(207),
      UINT8_C( 60),
      UINT8_C(201),
      UINT8_C(107),
      UINT8_C(203),
      UINT8_C(220),
      UINT8_C(146),
      UINT8_C(175),
      UINT8_C(117),
      UINT8_C(153),
      UINT8_C(181),
      UINT8_C(249),
      UINT8_C( 48),
      UINT8_C(206),
      UINT8_C(112),
      UINT8_C(147),
      UINT8_C(238),
      UINT8_C(235),
      UINT8_C(118),
      UINT8_C( 22),
      UINT8_C( 99),
      UINT8_C(105),
      UINT8_C( 32),
      UINT8_C(239),
      UINT8_C(127),
      UINT8_C(147),
      UINT8_C(199),
      UINT8_C(220),
      UINT8_C(157),
      UINT8_C(237),
      UINT8_C(138),
      UINT8_C(176),
      UINT8_C(228),
      }
    },
    { { UINT8_C(228), UINT8_C(116), UINT8_C(137), UINT8_C( 14), UINT8_C(176), UINT8_C( 85), UINT8_C(189), UINT8_C(101),
        UINT8_C( 35), UINT8_C(172), UINT8_C(123), UINT8_C( 67), UINT8_C( 63), UINT8_C( 24), UINT8_C(243), UINT8_C(  8) },
      { UINT8_C( 37), UINT8_C( 81), UINT8_C( 82), UINT8_C(  1), UINT8_C( 27), UINT8_C( 47), UINT8_C(118), UINT8_C( 20),
        UINT8_C(159), UINT8_C( 98), UINT8_C(119), UINT8_C(142), UINT8_C( 41), UINT8_C(101), UINT8_C(114), UINT8_C( 14) },
      { UINT8_C(217), UINT8_C(252), UINT8_C( 28), UINT8_C(137), UINT8_C( 81), UINT8_C(218), UINT8_C(238), UINT8_C(116),
        UINT8_C(134), UINT8_C(106), UINT8_C(184), UINT8_C(197), UINT8_C(130), UINT8_C(171), UINT8_C(205), UINT8_C(168) },
      {
      UINT8_C(228),
      UINT8_C( 37),
      UINT8_C(217),
      UINT8_C(116),
      UINT8_C( 81),
      UINT8_C(252),
      UINT8_C(137),
      UINT8_C( 82),
      UINT8_C( 28),
      UINT8_C( 14),
      UINT8_C(  1),
      UINT8_C(137),
      UINT8_C(176),
      UINT8_C( 27),
      UINT8_C( 81),
      UINT8_C( 85),
      UINT8_C( 47),
      UINT8_C(218),
      UINT8_C(189),
      UINT8_C(118),
      UINT8_C(238),
      UINT8_C(101),
      UINT8_C( 20),
      UINT8_C(116),
      UINT8_C( 35),
      UINT8_C(159),
      UINT8_C(134),
      UINT8_C(172),
      UINT8_C( 98),
      UINT8_C(106),
      UINT8_C(123),
      UINT8_C(119),
      UINT8_C(184),
      UINT8_C( 67),
      UINT8_C(142),
      UINT8_C(197),
      UINT8_C( 63),
      UINT8_C( 41),
      UINT8_C(130),
      UINT8_C( 24),
      UINT8_C(101),
      UINT8_C(171),
      UINT8_C(243),
      UINT8_C(114),
      UINT8_C(205),
      UINT8_C(  8),
      UINT8_C( 14),
      UINT8_C(168),
      }
    },
    { { UINT8_C(253), UINT8_C( 32), UINT8_C(169), UINT8_C( 24), UINT8_C( 79), UINT8_C( 32), UINT8_C( 44), UINT8_C(238),
        UINT8_C(130), UINT8_C(164), UINT8_C(124), UINT8_C(171), UINT8_C(  9), UINT8_C(239), UINT8_C(185), UINT8_C(226) },
      { UINT8_C(235), UINT8_C(214), UINT8_C(107), UINT8_C( 60), UINT8_C(176), UINT8_C( 89), UINT8_C(176), UINT8_C( 54),
        UINT8_C(195), UINT8_C(104), UINT8_C(251), UINT8_C( 70), UINT8_C( 20), UINT8_C(201), UINT8_C(238), UINT8_C( 17) },
      { UINT8_C(233), UINT8_C(151), UINT8_C( 41), UINT8_C( 56), UINT8_C(183), UINT8_C( 85), UINT8_C( 38), UINT8_C( 57),
        UINT8_C(249), UINT8_C(162), UINT8_C(229), UINT8_C(  2), UINT8_C(145), UINT8_C(158), UINT8_C(228), UINT8_C(124) },
      {
      UINT8_C(253),
      UINT8_C(235),
      UINT8_C(233),
      UINT8_C( 32),
      UINT8_C(214),
      UINT8_C(151),
      UINT8_C(169),
      UINT8_C(107),
      UINT8_C( 41),
      UINT8_C( 24),
      UINT8_C( 60),
      UINT8_C( 56),
      UINT8_C( 79),
      UINT8_C(176),
      UINT8_C(183),
      UINT8_C( 32),
      UINT8_C( 89),
      UINT8_C( 85),
      UINT8_C( 44),
      UINT8_C(176),
      UINT8_C( 38),
      UINT8_C(238),
      UINT8_C( 54),
      UINT8_C( 57),
      UINT8_C(130),
      UINT8_C(195),
      UINT8_C(249),
      UINT8_C(164),
      UINT8_C(104),
      UINT8_C(162),
      UINT8_C(124),
      UINT8_C(251),
      UINT8_C(229),
      UINT8_C(171),
      UINT8_C( 70),
      UINT8_C(  2),
      UINT8_C(  9),
      UINT8_C( 20),
      UINT8_C(145),
      UINT8_C(239),
      UINT8_C(201),
      UINT8_C(158),
      UINT8_C(185),
      UINT8_C(238),
      UINT8_C(228),
      UINT8_C(226),
      UINT8_C( 17),
      UINT8_C(124),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x3_t r_ = { { simde_vld1q_u8(test_vec[i].r0),
                                simde_vld1q_u8(test_vec[i].r1),
                                simde_vld1q_u8(test_vec[i].r2), } };

    uint8_t a_[48];
    simde_vst3q_u8(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3q_u8(a_);
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
    simde_uint8x16x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_u8x16(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    uint8_t buf[48];
    simde_vst3q_u8(buf, a);

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
test_simde_vst3q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r0[8];
    uint16_t r1[8];
    uint16_t r2[8];
    uint16_t a[24];
  } test_vec[] = {
    { { UINT16_C(28854), UINT16_C(51168), UINT16_C(18132), UINT16_C(49742), UINT16_C(35222), UINT16_C(24102), UINT16_C(16864), UINT16_C( 8805) },
      { UINT16_C(42923), UINT16_C(13774), UINT16_C(28620), UINT16_C(22537), UINT16_C(57874), UINT16_C(53954), UINT16_C(25731), UINT16_C(14804) },
      { UINT16_C(46548), UINT16_C(43008), UINT16_C(20475), UINT16_C(37226), UINT16_C(37080), UINT16_C(47343), UINT16_C(21714), UINT16_C(32218) },
      {
      UINT16_C(28854),
      UINT16_C(42923),
      UINT16_C(46548),
      UINT16_C(51168),
      UINT16_C(13774),
      UINT16_C(43008),
      UINT16_C(18132),
      UINT16_C(28620),
      UINT16_C(20475),
      UINT16_C(49742),
      UINT16_C(22537),
      UINT16_C(37226),
      UINT16_C(35222),
      UINT16_C(57874),
      UINT16_C(37080),
      UINT16_C(24102),
      UINT16_C(53954),
      UINT16_C(47343),
      UINT16_C(16864),
      UINT16_C(25731),
      UINT16_C(21714),
      UINT16_C( 8805),
      UINT16_C(14804),
      UINT16_C(32218),
      }
    },
    { { UINT16_C(43516), UINT16_C(51378), UINT16_C(48152), UINT16_C(11041), UINT16_C(58270), UINT16_C( 8701), UINT16_C(53831), UINT16_C( 7259) },
      { UINT16_C(23431), UINT16_C(33476), UINT16_C(12202), UINT16_C(33299), UINT16_C(  959), UINT16_C(37178), UINT16_C( 5463), UINT16_C(21262) },
      { UINT16_C(49598), UINT16_C(54812), UINT16_C(15741), UINT16_C( 6913), UINT16_C(65312), UINT16_C(26684), UINT16_C(38865), UINT16_C(22660) },
      {
      UINT16_C(43516),
      UINT16_C(23431),
      UINT16_C(49598),
      UINT16_C(51378),
      UINT16_C(33476),
      UINT16_C(54812),
      UINT16_C(48152),
      UINT16_C(12202),
      UINT16_C(15741),
      UINT16_C(11041),
      UINT16_C(33299),
      UINT16_C( 6913),
      UINT16_C(58270),
      UINT16_C(  959),
      UINT16_C(65312),
      UINT16_C( 8701),
      UINT16_C(37178),
      UINT16_C(26684),
      UINT16_C(53831),
      UINT16_C( 5463),
      UINT16_C(38865),
      UINT16_C( 7259),
      UINT16_C(21262),
      UINT16_C(22660),
      }
    },
    { { UINT16_C(18675), UINT16_C(40410), UINT16_C(60791), UINT16_C(14112), UINT16_C(23280), UINT16_C(18632), UINT16_C(55151), UINT16_C(11675) },
      { UINT16_C(47000), UINT16_C( 5380), UINT16_C( 1524), UINT16_C( 5424), UINT16_C(27652), UINT16_C(54653), UINT16_C(  260), UINT16_C(63277) },
      { UINT16_C( 1865), UINT16_C(49556), UINT16_C(46325), UINT16_C(58872), UINT16_C(49167), UINT16_C(32301), UINT16_C(51607), UINT16_C(12204) },
      {
      UINT16_C(18675),
      UINT16_C(47000),
      UINT16_C( 1865),
      UINT16_C(40410),
      UINT16_C( 5380),
      UINT16_C(49556),
      UINT16_C(60791),
      UINT16_C( 1524),
      UINT16_C(46325),
      UINT16_C(14112),
      UINT16_C( 5424),
      UINT16_C(58872),
      UINT16_C(23280),
      UINT16_C(27652),
      UINT16_C(49167),
      UINT16_C(18632),
      UINT16_C(54653),
      UINT16_C(32301),
      UINT16_C(55151),
      UINT16_C(  260),
      UINT16_C(51607),
      UINT16_C(11675),
      UINT16_C(63277),
      UINT16_C(12204),
      }
    },
    { { UINT16_C(45184), UINT16_C(30020), UINT16_C(29877), UINT16_C(47754), UINT16_C( 2017), UINT16_C(58767), UINT16_C(48392), UINT16_C(20956) },
      { UINT16_C(28868), UINT16_C(47378), UINT16_C( 2597), UINT16_C(13471), UINT16_C(52427), UINT16_C(25266), UINT16_C(24213), UINT16_C( 5778) },
      { UINT16_C(54798), UINT16_C(50315), UINT16_C( 5451), UINT16_C(11390), UINT16_C( 3356), UINT16_C( 9233), UINT16_C(60874), UINT16_C(36725) },
      {
      UINT16_C(45184),
      UINT16_C(28868),
      UINT16_C(54798),
      UINT16_C(30020),
      UINT16_C(47378),
      UINT16_C(50315),
      UINT16_C(29877),
      UINT16_C( 2597),
      UINT16_C( 5451),
      UINT16_C(47754),
      UINT16_C(13471),
      UINT16_C(11390),
      UINT16_C( 2017),
      UINT16_C(52427),
      UINT16_C( 3356),
      UINT16_C(58767),
      UINT16_C(25266),
      UINT16_C( 9233),
      UINT16_C(48392),
      UINT16_C(24213),
      UINT16_C(60874),
      UINT16_C(20956),
      UINT16_C( 5778),
      UINT16_C(36725),
      }
    },
    { { UINT16_C(34909), UINT16_C(33352), UINT16_C(59282), UINT16_C(23990), UINT16_C(27060), UINT16_C(18880), UINT16_C(21191), UINT16_C(54879) },
      { UINT16_C(59944), UINT16_C(29594), UINT16_C( 6399), UINT16_C( 7071), UINT16_C(45093), UINT16_C(61503), UINT16_C(46493), UINT16_C(64383) },
      { UINT16_C(51005), UINT16_C(53117), UINT16_C(13487), UINT16_C(25389), UINT16_C(60829), UINT16_C(25772), UINT16_C( 3135), UINT16_C(26426) },
      {
      UINT16_C(34909),
      UINT16_C(59944),
      UINT16_C(51005),
      UINT16_C(33352),
      UINT16_C(29594),
      UINT16_C(53117),
      UINT16_C(59282),
      UINT16_C( 6399),
      UINT16_C(13487),
      UINT16_C(23990),
      UINT16_C( 7071),
      UINT16_C(25389),
      UINT16_C(27060),
      UINT16_C(45093),
      UINT16_C(60829),
      UINT16_C(18880),
      UINT16_C(61503),
      UINT16_C(25772),
      UINT16_C(21191),
      UINT16_C(46493),
      UINT16_C( 3135),
      UINT16_C(54879),
      UINT16_C(64383),
      UINT16_C(26426),
      }
    },
    { { UINT16_C(54518), UINT16_C(63195), UINT16_C(31468), UINT16_C( 4625), UINT16_C(20779), UINT16_C(51202), UINT16_C(33030), UINT16_C(17347) },
      { UINT16_C(16712), UINT16_C(63250), UINT16_C(16245), UINT16_C( 4698), UINT16_C( 1836), UINT16_C(27510), UINT16_C(45331), UINT16_C( 2515) },
      { UINT16_C(44677), UINT16_C(29439), UINT16_C( 4392), UINT16_C(21380), UINT16_C(34402), UINT16_C(26652), UINT16_C(57095), UINT16_C(20395) },
      {
      UINT16_C(54518),
      UINT16_C(16712),
      UINT16_C(44677),
      UINT16_C(63195),
      UINT16_C(63250),
      UINT16_C(29439),
      UINT16_C(31468),
      UINT16_C(16245),
      UINT16_C( 4392),
      UINT16_C( 4625),
      UINT16_C( 4698),
      UINT16_C(21380),
      UINT16_C(20779),
      UINT16_C( 1836),
      UINT16_C(34402),
      UINT16_C(51202),
      UINT16_C(27510),
      UINT16_C(26652),
      UINT16_C(33030),
      UINT16_C(45331),
      UINT16_C(57095),
      UINT16_C(17347),
      UINT16_C( 2515),
      UINT16_C(20395),
      }
    },
    { { UINT16_C(48416), UINT16_C(38215), UINT16_C(41469), UINT16_C(10663), UINT16_C( 7848), UINT16_C(48021), UINT16_C(26831), UINT16_C(21701) },
      { UINT16_C(50198), UINT16_C(16070), UINT16_C(19157), UINT16_C(14226), UINT16_C(44752), UINT16_C(55199), UINT16_C(19085), UINT16_C(44583) },
      { UINT16_C(28168), UINT16_C( 1347), UINT16_C(60175), UINT16_C(47150), UINT16_C(49929), UINT16_C(55411), UINT16_C(14379), UINT16_C(16684) },
      {
      UINT16_C(48416),
      UINT16_C(50198),
      UINT16_C(28168),
      UINT16_C(38215),
      UINT16_C(16070),
      UINT16_C( 1347),
      UINT16_C(41469),
      UINT16_C(19157),
      UINT16_C(60175),
      UINT16_C(10663),
      UINT16_C(14226),
      UINT16_C(47150),
      UINT16_C( 7848),
      UINT16_C(44752),
      UINT16_C(49929),
      UINT16_C(48021),
      UINT16_C(55199),
      UINT16_C(55411),
      UINT16_C(26831),
      UINT16_C(19085),
      UINT16_C(14379),
      UINT16_C(21701),
      UINT16_C(44583),
      UINT16_C(16684),
      }
    },
    { { UINT16_C(62461), UINT16_C(53888), UINT16_C( 4669), UINT16_C( 3594), UINT16_C(43456), UINT16_C(19941), UINT16_C( 3316), UINT16_C(64763) },
      { UINT16_C(16250), UINT16_C(35329), UINT16_C(12074), UINT16_C(13122), UINT16_C(46579), UINT16_C( 7691), UINT16_C(14318), UINT16_C(60256) },
      { UINT16_C(57386), UINT16_C(26813), UINT16_C(51186), UINT16_C(45686), UINT16_C(23409), UINT16_C(26111), UINT16_C(64360), UINT16_C(57953) },
      {
      UINT16_C(62461),
      UINT16_C(16250),
      UINT16_C(57386),
      UINT16_C(53888),
      UINT16_C(35329),
      UINT16_C(26813),
      UINT16_C( 4669),
      UINT16_C(12074),
      UINT16_C(51186),
      UINT16_C( 3594),
      UINT16_C(13122),
      UINT16_C(45686),
      UINT16_C(43456),
      UINT16_C(46579),
      UINT16_C(23409),
      UINT16_C(19941),
      UINT16_C( 7691),
      UINT16_C(26111),
      UINT16_C( 3316),
      UINT16_C(14318),
      UINT16_C(64360),
      UINT16_C(64763),
      UINT16_C(60256),
      UINT16_C(57953),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x3_t r_ = { { simde_vld1q_u16(test_vec[i].r0),
                                simde_vld1q_u16(test_vec[i].r1),
                                simde_vld1q_u16(test_vec[i].r2), } };

    uint16_t a_[24];
    simde_vst3q_u16(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3q_u16(a_);
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
    simde_uint16x8x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_u16x8(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    uint16_t buf[24];
    simde_vst3q_u16(buf, a);

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
test_simde_vst3q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r0[4];
    uint32_t r1[4];
    uint32_t r2[4];
    uint32_t a[12];
  } test_vec[] = {
    { { UINT32_C(2644289703), UINT32_C(4217165007), UINT32_C(4135406643), UINT32_C(1998399494) },
      { UINT32_C( 139488877), UINT32_C(1168216955), UINT32_C(3519844586), UINT32_C(1657552315) },
      { UINT32_C(3036637413), UINT32_C(1890540348), UINT32_C(2925931687), UINT32_C(3240461140) },
      {
      UINT32_C(2644289703),
      UINT32_C( 139488877),
      UINT32_C(3036637413),
      UINT32_C(4217165007),
      UINT32_C(1168216955),
      UINT32_C(1890540348),
      UINT32_C(4135406643),
      UINT32_C(3519844586),
      UINT32_C(2925931687),
      UINT32_C(1998399494),
      UINT32_C(1657552315),
      UINT32_C(3240461140),
      }
    },
    { { UINT32_C(1841985266), UINT32_C(4088621833), UINT32_C(3066396667), UINT32_C(2702741948) },
      { UINT32_C( 894769145), UINT32_C( 447022195), UINT32_C(2227702832), UINT32_C(2168909455) },
      { UINT32_C(1844383844), UINT32_C(1986110075), UINT32_C(3727500833), UINT32_C(2961130935) },
      {
      UINT32_C(1841985266),
      UINT32_C( 894769145),
      UINT32_C(1844383844),
      UINT32_C(4088621833),
      UINT32_C( 447022195),
      UINT32_C(1986110075),
      UINT32_C(3066396667),
      UINT32_C(2227702832),
      UINT32_C(3727500833),
      UINT32_C(2702741948),
      UINT32_C(2168909455),
      UINT32_C(2961130935),
      }
    },
    { { UINT32_C(3504723293), UINT32_C( 183143385), UINT32_C( 646886295), UINT32_C(  94950561) },
      { UINT32_C(1601345508), UINT32_C(1524028217), UINT32_C(2956461049), UINT32_C(2774579272) },
      { UINT32_C(1718961805), UINT32_C(1752195281), UINT32_C(3029270291), UINT32_C(3099145939) },
      {
      UINT32_C(3504723293),
      UINT32_C(1601345508),
      UINT32_C(1718961805),
      UINT32_C( 183143385),
      UINT32_C(1524028217),
      UINT32_C(1752195281),
      UINT32_C( 646886295),
      UINT32_C(2956461049),
      UINT32_C(3029270291),
      UINT32_C(  94950561),
      UINT32_C(2774579272),
      UINT32_C(3099145939),
      }
    },
    { { UINT32_C( 102181837), UINT32_C(4167167487), UINT32_C( 967416304), UINT32_C(3739093329) },
      { UINT32_C( 541414479), UINT32_C(3347625396), UINT32_C(2289768372), UINT32_C( 457192525) },
      { UINT32_C(1579243359), UINT32_C( 894927429), UINT32_C(1835925532), UINT32_C(1498172681) },
      {
      UINT32_C( 102181837),
      UINT32_C( 541414479),
      UINT32_C(1579243359),
      UINT32_C(4167167487),
      UINT32_C(3347625396),
      UINT32_C( 894927429),
      UINT32_C( 967416304),
      UINT32_C(2289768372),
      UINT32_C(1835925532),
      UINT32_C(3739093329),
      UINT32_C( 457192525),
      UINT32_C(1498172681),
      }
    },
    { { UINT32_C(1434030497), UINT32_C(4212916806), UINT32_C(1719899929), UINT32_C( 713147339) },
      { UINT32_C(1602855706), UINT32_C(1100341285), UINT32_C(3920561120), UINT32_C(4047698768) },
      { UINT32_C(3527851148), UINT32_C(3620561598), UINT32_C(3292352761), UINT32_C( 787463955) },
      {
      UINT32_C(1434030497),
      UINT32_C(1602855706),
      UINT32_C(3527851148),
      UINT32_C(4212916806),
      UINT32_C(1100341285),
      UINT32_C(3620561598),
      UINT32_C(1719899929),
      UINT32_C(3920561120),
      UINT32_C(3292352761),
      UINT32_C( 713147339),
      UINT32_C(4047698768),
      UINT32_C( 787463955),
      }
    },
    { { UINT32_C(2274195554), UINT32_C( 952705624), UINT32_C(1981904934), UINT32_C(4285031539) },
      { UINT32_C(3738283552), UINT32_C( 179674897), UINT32_C(  63959791), UINT32_C( 322027185) },
      { UINT32_C(2392571446), UINT32_C( 130442465), UINT32_C(1333651420), UINT32_C(1800332619) },
      {
      UINT32_C(2274195554),
      UINT32_C(3738283552),
      UINT32_C(2392571446),
      UINT32_C( 952705624),
      UINT32_C( 179674897),
      UINT32_C( 130442465),
      UINT32_C(1981904934),
      UINT32_C(  63959791),
      UINT32_C(1333651420),
      UINT32_C(4285031539),
      UINT32_C( 322027185),
      UINT32_C(1800332619),
      }
    },
    { { UINT32_C(2773032852), UINT32_C(2930769598), UINT32_C(2729541361), UINT32_C(1924588092) },
      { UINT32_C(2164281760), UINT32_C(2441660085), UINT32_C(4192208558), UINT32_C(2137337579) },
      { UINT32_C( 203730509), UINT32_C(2663044269), UINT32_C(2403363666), UINT32_C(3976328781) },
      {
      UINT32_C(2773032852),
      UINT32_C(2164281760),
      UINT32_C( 203730509),
      UINT32_C(2930769598),
      UINT32_C(2441660085),
      UINT32_C(2663044269),
      UINT32_C(2729541361),
      UINT32_C(4192208558),
      UINT32_C(2403363666),
      UINT32_C(1924588092),
      UINT32_C(2137337579),
      UINT32_C(3976328781),
      }
    },
    { { UINT32_C(4235133511), UINT32_C(1989015496), UINT32_C(3916459517), UINT32_C(3915961755) },
      { UINT32_C( 821398915), UINT32_C(3016666977), UINT32_C(1732382490), UINT32_C(1297368069) },
      { UINT32_C( 239715142), UINT32_C(3095779259), UINT32_C(3768710468), UINT32_C(1305021130) },
      {
      UINT32_C(4235133511),
      UINT32_C( 821398915),
      UINT32_C( 239715142),
      UINT32_C(1989015496),
      UINT32_C(3016666977),
      UINT32_C(3095779259),
      UINT32_C(3916459517),
      UINT32_C(1732382490),
      UINT32_C(3768710468),
      UINT32_C(3915961755),
      UINT32_C(1297368069),
      UINT32_C(1305021130),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x3_t r_ = { { simde_vld1q_u32(test_vec[i].r0),
                                simde_vld1q_u32(test_vec[i].r1),
                                simde_vld1q_u32(test_vec[i].r2), } };

    uint32_t a_[12];
    simde_vst3q_u32(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3q_u32(a_);
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
    simde_uint32x4x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_u32x4(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    uint32_t buf[12];
    simde_vst3q_u32(buf, a);

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
test_simde_vst3q_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r0[2];
    uint64_t r1[2];
    uint64_t r2[2];
    uint64_t a[6];
  } test_vec[] = {
    { { UINT64_C(18060883008768479347), UINT64_C( 5018011187030834501) },
      { UINT64_C(11625139375786132363), UINT64_C( 5059326699072687921) },
      { UINT64_C( 2974855029542469350), UINT64_C( 5361348160817082507) },
      {
      UINT64_C(18060883008768479347),
      UINT64_C(11625139375786132363),
      UINT64_C( 2974855029542469350),
      UINT64_C( 5018011187030834501),
      UINT64_C( 5059326699072687921),
      UINT64_C( 5361348160817082507),
      }
    },
    { { UINT64_C( 9666145736659077849), UINT64_C( 4878956801423443611) },
      { UINT64_C( 4131166095989137223), UINT64_C( 3824614212338648586) },
      { UINT64_C( 8298128430671186765), UINT64_C( 5441640290016459493) },
      {
      UINT64_C( 9666145736659077849),
      UINT64_C( 4131166095989137223),
      UINT64_C( 8298128430671186765),
      UINT64_C( 4878956801423443611),
      UINT64_C( 3824614212338648586),
      UINT64_C( 5441640290016459493),
      }
    },
    { { UINT64_C(17968741216735860086), UINT64_C(14366999007002278096) },
      { UINT64_C(16134869119939451808), UINT64_C(15734070097341369356) },
      { UINT64_C( 7755862228120555706), UINT64_C(15660697304851506195) },
      {
      UINT64_C(17968741216735860086),
      UINT64_C(16134869119939451808),
      UINT64_C( 7755862228120555706),
      UINT64_C(14366999007002278096),
      UINT64_C(15734070097341369356),
      UINT64_C(15660697304851506195),
      }
    },
    { { UINT64_C( 6696073435993456404), UINT64_C( 7874199468129389832) },
      { UINT64_C(13014481120863339927), UINT64_C( 4697420632340706333) },
      { UINT64_C(14196257235655426390), UINT64_C(14801492728372883273) },
      {
      UINT64_C( 6696073435993456404),
      UINT64_C(13014481120863339927),
      UINT64_C(14196257235655426390),
      UINT64_C( 7874199468129389832),
      UINT64_C( 4697420632340706333),
      UINT64_C(14801492728372883273),
      }
    },
    { { UINT64_C( 6201908828263317436), UINT64_C( 4701157587375969231) },
      { UINT64_C( 1288570213115661407), UINT64_C( 5070620563681907291) },
      { UINT64_C(14304757290167917814), UINT64_C( 7940689536953233671) },
      {
      UINT64_C( 6201908828263317436),
      UINT64_C( 1288570213115661407),
      UINT64_C(14304757290167917814),
      UINT64_C( 4701157587375969231),
      UINT64_C( 5070620563681907291),
      UINT64_C( 7940689536953233671),
      }
    },
    { { UINT64_C( 7018133269242321547), UINT64_C(16090324530462093949) },
      { UINT64_C(12279788565508779948), UINT64_C(13276838393395555779) },
      { UINT64_C(12848893113834130153), UINT64_C( 4515709179427111651) },
      {
      UINT64_C( 7018133269242321547),
      UINT64_C(12279788565508779948),
      UINT64_C(12848893113834130153),
      UINT64_C(16090324530462093949),
      UINT64_C(13276838393395555779),
      UINT64_C( 4515709179427111651),
      }
    },
    { { UINT64_C( 1027750122758519029), UINT64_C(10835134783212806010) },
      { UINT64_C(13678511626096306923), UINT64_C( 9793135194231376919) },
      { UINT64_C(10467880760741186285), UINT64_C( 3640481109499192897) },
      {
      UINT64_C( 1027750122758519029),
      UINT64_C(13678511626096306923),
      UINT64_C(10467880760741186285),
      UINT64_C(10835134783212806010),
      UINT64_C( 9793135194231376919),
      UINT64_C( 3640481109499192897),
      }
    },
    { { UINT64_C(17913111364571958016), UINT64_C( 4885430699418526387) },
      { UINT64_C(10447718153612684372), UINT64_C(14726776052189705702) },
      { UINT64_C(10297550757555581711), UINT64_C( 7492758411626645857) },
      {
      UINT64_C(17913111364571958016),
      UINT64_C(10447718153612684372),
      UINT64_C(10297550757555581711),
      UINT64_C( 4885430699418526387),
      UINT64_C(14726776052189705702),
      UINT64_C( 7492758411626645857),
      }
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x3_t r_ = { { simde_vld1q_u64(test_vec[i].r0),
                                simde_vld1q_u64(test_vec[i].r1),
                                simde_vld1q_u64(test_vec[i].r2), } };

    uint64_t a_[6];
    simde_vst3q_u64(a_, r_);
    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));

    r_ = simde_vld3q_u64(a_);
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
    simde_uint64x2x3_t a = { { a0, a1, a2 } };
    simde_test_arm_neon_write_u64x2(2, a0, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, a1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, a2, SIMDE_TEST_VEC_POS_MIDDLE);
    uint64_t buf[6];
    simde_vst3q_u64(buf, a);

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
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_u64)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
