#define SIMDE_TEST_ARM_NEON_INSN fma_n

#include "test-neon.h"
#include "../../../simde/arm/neon/fma_n.h"

static int
test_simde_vfma_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 c;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -884.17), SIMDE_FLOAT32_C(   455.82) },
      { SIMDE_FLOAT32_C(   414.73), SIMDE_FLOAT32_C(  -958.00) },
      SIMDE_FLOAT32_C(  -376.95),
      { SIMDE_FLOAT32_C(-157216.66), SIMDE_FLOAT32_C(361573.94) } },
    { { SIMDE_FLOAT32_C(  -430.93), SIMDE_FLOAT32_C(  -278.22) },
      { SIMDE_FLOAT32_C(   598.34), SIMDE_FLOAT32_C(   118.00) },
      SIMDE_FLOAT32_C(  -694.94),
      { SIMDE_FLOAT32_C(-416241.34), SIMDE_FLOAT32_C(-82281.14) } },
    { { SIMDE_FLOAT32_C(   878.52), SIMDE_FLOAT32_C(   396.17) },
      { SIMDE_FLOAT32_C(  -308.14), SIMDE_FLOAT32_C(  -455.30) },
      SIMDE_FLOAT32_C(  -963.24),
      { SIMDE_FLOAT32_C(297691.31), SIMDE_FLOAT32_C(438959.31) } },
    { { SIMDE_FLOAT32_C(   425.11), SIMDE_FLOAT32_C(  -476.90) },
      { SIMDE_FLOAT32_C(   396.10), SIMDE_FLOAT32_C(   714.01) },
      SIMDE_FLOAT32_C(   153.93),
      { SIMDE_FLOAT32_C( 61396.78), SIMDE_FLOAT32_C(109430.66) } },
    { { SIMDE_FLOAT32_C(  -383.41), SIMDE_FLOAT32_C(   189.47) },
      { SIMDE_FLOAT32_C(   456.48), SIMDE_FLOAT32_C(   334.18) },
      SIMDE_FLOAT32_C(   996.82),
      { SIMDE_FLOAT32_C(454645.00), SIMDE_FLOAT32_C(333306.78) } },
    { { SIMDE_FLOAT32_C(  -160.70), SIMDE_FLOAT32_C(  -844.72) },
      { SIMDE_FLOAT32_C(  -119.46), SIMDE_FLOAT32_C(   646.91) },
      SIMDE_FLOAT32_C(   516.76),
      { SIMDE_FLOAT32_C(-61892.85), SIMDE_FLOAT32_C(333452.47) } },
    { { SIMDE_FLOAT32_C(   291.12), SIMDE_FLOAT32_C(   762.74) },
      { SIMDE_FLOAT32_C(   -27.42), SIMDE_FLOAT32_C(  -294.15) },
      SIMDE_FLOAT32_C(   804.73),
      { SIMDE_FLOAT32_C(-21774.58), SIMDE_FLOAT32_C(-235948.58) } },
    { { SIMDE_FLOAT32_C(   595.63), SIMDE_FLOAT32_C(   274.91) },
      { SIMDE_FLOAT32_C(  -473.49), SIMDE_FLOAT32_C(   193.97) },
      SIMDE_FLOAT32_C(  -607.09),
      { SIMDE_FLOAT32_C(288046.69), SIMDE_FLOAT32_C(-117482.34) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32 c = test_vec[i].c;
    simde_float32x2_t r = simde_vfma_n_f32(a, b, c);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float32 c = simde_test_codegen_random_f32(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float32x2_t r = simde_vfma_n_f32(a, b, c);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfma_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 c;
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -168.43) },
      { SIMDE_FLOAT64_C(    72.48) },
      SIMDE_FLOAT64_C(   789.08),
      { SIMDE_FLOAT64_C( 57024.09) } },
    { { SIMDE_FLOAT64_C(   523.43) },
      { SIMDE_FLOAT64_C(   617.18) },
      SIMDE_FLOAT64_C(   825.85),
      { SIMDE_FLOAT64_C(510221.53) } },
    { { SIMDE_FLOAT64_C(   -51.46) },
      { SIMDE_FLOAT64_C(  -859.72) },
      SIMDE_FLOAT64_C(   221.95),
      { SIMDE_FLOAT64_C(-190866.31) } },
    { { SIMDE_FLOAT64_C(  -337.45) },
      { SIMDE_FLOAT64_C(   294.21) },
      SIMDE_FLOAT64_C(   838.54),
      { SIMDE_FLOAT64_C(246369.40) } },
    { { SIMDE_FLOAT64_C(   852.02) },
      { SIMDE_FLOAT64_C(  -249.31) },
      SIMDE_FLOAT64_C(   172.71),
      { SIMDE_FLOAT64_C(-42206.31) } },
    { { SIMDE_FLOAT64_C(   848.85) },
      { SIMDE_FLOAT64_C(   589.99) },
      SIMDE_FLOAT64_C(   327.99),
      { SIMDE_FLOAT64_C(194359.67) } },
    { { SIMDE_FLOAT64_C(  -270.61) },
      { SIMDE_FLOAT64_C(   236.90) },
      SIMDE_FLOAT64_C(  -155.25),
      { SIMDE_FLOAT64_C(-37049.33) } },
    { { SIMDE_FLOAT64_C(  -979.50) },
      { SIMDE_FLOAT64_C(    -0.36) },
      SIMDE_FLOAT64_C(   817.33),
      { SIMDE_FLOAT64_C( -1273.74) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64 c = test_vec[i].c;
    simde_float64x1_t r = simde_vfma_n_f64(a, b, c);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64 c = simde_test_codegen_random_f64(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t r = simde_vfma_n_f64(a, b, c);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfmaq_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 c;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -273.65), SIMDE_FLOAT32_C(  -195.63), SIMDE_FLOAT32_C(   412.96), SIMDE_FLOAT32_C(  -998.74) },
      { SIMDE_FLOAT32_C(   330.89), SIMDE_FLOAT32_C(  -393.07), SIMDE_FLOAT32_C(  -605.83), SIMDE_FLOAT32_C(  -837.54) },
      SIMDE_FLOAT32_C(   679.41),
      { SIMDE_FLOAT32_C(224536.33), SIMDE_FLOAT32_C(-267251.31), SIMDE_FLOAT32_C(-411194.00), SIMDE_FLOAT32_C(-570031.75) } },
    { { SIMDE_FLOAT32_C(  -816.75), SIMDE_FLOAT32_C(   685.89), SIMDE_FLOAT32_C(   296.59), SIMDE_FLOAT32_C(  -990.90) },
      { SIMDE_FLOAT32_C(  -365.58), SIMDE_FLOAT32_C(   436.87), SIMDE_FLOAT32_C(   231.05), SIMDE_FLOAT32_C(   296.97) },
      SIMDE_FLOAT32_C(  -268.92),
      { SIMDE_FLOAT32_C( 97495.02), SIMDE_FLOAT32_C(-116797.20), SIMDE_FLOAT32_C(-61837.38), SIMDE_FLOAT32_C(-80852.08) } },
    { { SIMDE_FLOAT32_C(    69.59), SIMDE_FLOAT32_C(   149.00), SIMDE_FLOAT32_C(   481.77), SIMDE_FLOAT32_C(  -757.70) },
      { SIMDE_FLOAT32_C(    -2.16), SIMDE_FLOAT32_C(    71.76), SIMDE_FLOAT32_C(   570.29), SIMDE_FLOAT32_C(   727.23) },
      SIMDE_FLOAT32_C(  -691.34),
      { SIMDE_FLOAT32_C(  1562.88), SIMDE_FLOAT32_C(-49461.56), SIMDE_FLOAT32_C(-393782.53), SIMDE_FLOAT32_C(-503520.91) } },
    { { SIMDE_FLOAT32_C(  -584.96), SIMDE_FLOAT32_C(   747.74), SIMDE_FLOAT32_C(   308.30), SIMDE_FLOAT32_C(  -767.63) },
      { SIMDE_FLOAT32_C(  -525.91), SIMDE_FLOAT32_C(  -887.33), SIMDE_FLOAT32_C(   645.32), SIMDE_FLOAT32_C(  -524.65) },
      SIMDE_FLOAT32_C(   443.56),
      { SIMDE_FLOAT32_C(-233857.59), SIMDE_FLOAT32_C(-392836.38), SIMDE_FLOAT32_C(286546.44), SIMDE_FLOAT32_C(-233481.39) } },
    { { SIMDE_FLOAT32_C(  -747.75), SIMDE_FLOAT32_C(  -130.48), SIMDE_FLOAT32_C(   606.01), SIMDE_FLOAT32_C(   931.66) },
      { SIMDE_FLOAT32_C(    52.77), SIMDE_FLOAT32_C(   291.90), SIMDE_FLOAT32_C(   228.25), SIMDE_FLOAT32_C(    61.88) },
      SIMDE_FLOAT32_C(   926.32),
      { SIMDE_FLOAT32_C( 48134.16), SIMDE_FLOAT32_C(270262.31), SIMDE_FLOAT32_C(212038.55), SIMDE_FLOAT32_C( 58252.34) } },
    { { SIMDE_FLOAT32_C(  -334.88), SIMDE_FLOAT32_C(  -707.07), SIMDE_FLOAT32_C(   223.29), SIMDE_FLOAT32_C(   396.20) },
      { SIMDE_FLOAT32_C(   362.51), SIMDE_FLOAT32_C(  -627.71), SIMDE_FLOAT32_C(  -122.03), SIMDE_FLOAT32_C(   604.81) },
      SIMDE_FLOAT32_C(   370.13),
      { SIMDE_FLOAT32_C(133840.95), SIMDE_FLOAT32_C(-233041.39), SIMDE_FLOAT32_C(-44943.68), SIMDE_FLOAT32_C(224254.53) } },
    { { SIMDE_FLOAT32_C(   949.73), SIMDE_FLOAT32_C(   175.10), SIMDE_FLOAT32_C(    97.36), SIMDE_FLOAT32_C(  -741.61) },
      { SIMDE_FLOAT32_C(   590.13), SIMDE_FLOAT32_C(  -154.90), SIMDE_FLOAT32_C(   566.69), SIMDE_FLOAT32_C(   822.50) },
      SIMDE_FLOAT32_C(   319.19),
      { SIMDE_FLOAT32_C(189313.33), SIMDE_FLOAT32_C(-49267.43), SIMDE_FLOAT32_C(180979.14), SIMDE_FLOAT32_C(261792.17) } },
    { { SIMDE_FLOAT32_C(   679.36), SIMDE_FLOAT32_C(   467.82), SIMDE_FLOAT32_C(   794.53), SIMDE_FLOAT32_C(   122.92) },
      { SIMDE_FLOAT32_C(   720.07), SIMDE_FLOAT32_C(  -335.95), SIMDE_FLOAT32_C(  -271.07), SIMDE_FLOAT32_C(   651.74) },
      SIMDE_FLOAT32_C(   716.83),
      { SIMDE_FLOAT32_C(516847.16), SIMDE_FLOAT32_C(-240351.23), SIMDE_FLOAT32_C(-193516.59), SIMDE_FLOAT32_C(467309.72) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32 c = test_vec[i].c;
    simde_float32x4_t r = simde_vfmaq_n_f32(a, b, c);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float32 c = simde_test_codegen_random_f32(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float32x4_t r = simde_vfmaq_n_f32(a, b, c);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfmaq_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 c;
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -979.17), SIMDE_FLOAT64_C(  -120.01) },
      { SIMDE_FLOAT64_C(  -221.30), SIMDE_FLOAT64_C(   947.15) },
      SIMDE_FLOAT64_C(   545.11),
      { SIMDE_FLOAT64_C(-121612.01), SIMDE_FLOAT64_C(516180.93) } },
    { { SIMDE_FLOAT64_C(    71.63), SIMDE_FLOAT64_C(   170.44) },
      { SIMDE_FLOAT64_C(   -58.69), SIMDE_FLOAT64_C(  -565.86) },
      SIMDE_FLOAT64_C(   542.73),
      { SIMDE_FLOAT64_C(-31781.19), SIMDE_FLOAT64_C(-306938.76) } },
    { { SIMDE_FLOAT64_C(   819.28), SIMDE_FLOAT64_C(  -961.05) },
      { SIMDE_FLOAT64_C(   -87.14), SIMDE_FLOAT64_C(   769.01) },
      SIMDE_FLOAT64_C(   214.05),
      { SIMDE_FLOAT64_C(-17833.04), SIMDE_FLOAT64_C(163645.54) } },
    { { SIMDE_FLOAT64_C(  -989.77), SIMDE_FLOAT64_C(  -972.59) },
      { SIMDE_FLOAT64_C(  -195.82), SIMDE_FLOAT64_C(  -144.67) },
      SIMDE_FLOAT64_C(   594.10),
      { SIMDE_FLOAT64_C(-117326.43), SIMDE_FLOAT64_C(-86921.04) } },
    { { SIMDE_FLOAT64_C(  -373.32), SIMDE_FLOAT64_C(  -825.48) },
      { SIMDE_FLOAT64_C(   273.46), SIMDE_FLOAT64_C(  -905.50) },
      SIMDE_FLOAT64_C(   969.05),
      { SIMDE_FLOAT64_C(264623.09), SIMDE_FLOAT64_C(-878300.26) } },
    { { SIMDE_FLOAT64_C(  -603.63), SIMDE_FLOAT64_C(   814.58) },
      { SIMDE_FLOAT64_C(  -366.90), SIMDE_FLOAT64_C(   125.30) },
      SIMDE_FLOAT64_C(   466.31),
      { SIMDE_FLOAT64_C(-171692.77), SIMDE_FLOAT64_C( 59243.22) } },
    { { SIMDE_FLOAT64_C(  -650.07), SIMDE_FLOAT64_C(   146.13) },
      { SIMDE_FLOAT64_C(  -653.70), SIMDE_FLOAT64_C(   128.64) },
      SIMDE_FLOAT64_C(    93.28),
      { SIMDE_FLOAT64_C(-61627.21), SIMDE_FLOAT64_C( 12145.67) } },
    { { SIMDE_FLOAT64_C(   891.42), SIMDE_FLOAT64_C(  -799.73) },
      { SIMDE_FLOAT64_C(  -736.28), SIMDE_FLOAT64_C(  -167.27) },
      SIMDE_FLOAT64_C(  -365.59),
      { SIMDE_FLOAT64_C(270068.03), SIMDE_FLOAT64_C( 60352.51) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64 c = test_vec[i].c;
    simde_float64x2_t r = simde_vfmaq_n_f64(a, b, c);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64 c = simde_test_codegen_random_f64(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r = simde_vfmaq_n_f64(a, b, c);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vfma_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfma_n_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmaq_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmaq_n_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
