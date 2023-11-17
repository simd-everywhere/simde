#define SIMDE_TEST_ARM_NEON_INSN ld4_dup

#include "test-neon.h"
#include "../../../simde/arm/neon/ld4_dup.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld4_dup_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[4];
    simde_float16_t unused[4];
    simde_float16_t r[4][4];
  } test_vec[] = {
     { {  SIMDE_FLOAT16_VALUE(48.08), SIMDE_FLOAT16_VALUE(24.50), SIMDE_FLOAT16_VALUE(47.79), SIMDE_FLOAT16_VALUE(45.49) },
       {  SIMDE_FLOAT16_VALUE(-22.72), SIMDE_FLOAT16_VALUE(6.28), SIMDE_FLOAT16_VALUE(-7.03), SIMDE_FLOAT16_VALUE(41.06)},
     { {  SIMDE_FLOAT16_VALUE(48.08), SIMDE_FLOAT16_VALUE(48.08), SIMDE_FLOAT16_VALUE(48.08), SIMDE_FLOAT16_VALUE(48.08) },
       {  SIMDE_FLOAT16_VALUE(24.50), SIMDE_FLOAT16_VALUE(24.50), SIMDE_FLOAT16_VALUE(24.50), SIMDE_FLOAT16_VALUE(24.50) },
       {  SIMDE_FLOAT16_VALUE(47.79), SIMDE_FLOAT16_VALUE(47.79), SIMDE_FLOAT16_VALUE(47.79), SIMDE_FLOAT16_VALUE(47.79) },
       {  SIMDE_FLOAT16_VALUE(45.49), SIMDE_FLOAT16_VALUE(45.49), SIMDE_FLOAT16_VALUE(45.49), SIMDE_FLOAT16_VALUE(45.49) } } },
     { {  SIMDE_FLOAT16_VALUE(41.90), SIMDE_FLOAT16_VALUE(-45.37), SIMDE_FLOAT16_VALUE(43.54), SIMDE_FLOAT16_VALUE(10.59) },
       {  SIMDE_FLOAT16_VALUE(36.07), SIMDE_FLOAT16_VALUE(28.31), SIMDE_FLOAT16_VALUE(-11.82), SIMDE_FLOAT16_VALUE(-16.27)},
     { {  SIMDE_FLOAT16_VALUE(41.90), SIMDE_FLOAT16_VALUE(41.90), SIMDE_FLOAT16_VALUE(41.90), SIMDE_FLOAT16_VALUE(41.90) },
       {  SIMDE_FLOAT16_VALUE(-45.37), SIMDE_FLOAT16_VALUE(-45.37), SIMDE_FLOAT16_VALUE(-45.37), SIMDE_FLOAT16_VALUE(-45.37) },
       {  SIMDE_FLOAT16_VALUE(43.54), SIMDE_FLOAT16_VALUE(43.54), SIMDE_FLOAT16_VALUE(43.54), SIMDE_FLOAT16_VALUE(43.54) },
       {  SIMDE_FLOAT16_VALUE(10.59), SIMDE_FLOAT16_VALUE(10.59), SIMDE_FLOAT16_VALUE(10.59), SIMDE_FLOAT16_VALUE(10.59) } } },
     { {  SIMDE_FLOAT16_VALUE(3.73), SIMDE_FLOAT16_VALUE(-41.80), SIMDE_FLOAT16_VALUE(16.45), SIMDE_FLOAT16_VALUE(28.24) },
       {  SIMDE_FLOAT16_VALUE(14.07), SIMDE_FLOAT16_VALUE(-1.72), SIMDE_FLOAT16_VALUE(-31.48), SIMDE_FLOAT16_VALUE(-4.95)},
     { {  SIMDE_FLOAT16_VALUE(3.73), SIMDE_FLOAT16_VALUE(3.73), SIMDE_FLOAT16_VALUE(3.73), SIMDE_FLOAT16_VALUE(3.73) },
       {  SIMDE_FLOAT16_VALUE(-41.80), SIMDE_FLOAT16_VALUE(-41.80), SIMDE_FLOAT16_VALUE(-41.80), SIMDE_FLOAT16_VALUE(-41.80) },
       {  SIMDE_FLOAT16_VALUE(16.45), SIMDE_FLOAT16_VALUE(16.45), SIMDE_FLOAT16_VALUE(16.45), SIMDE_FLOAT16_VALUE(16.45) },
       {  SIMDE_FLOAT16_VALUE(28.24), SIMDE_FLOAT16_VALUE(28.24), SIMDE_FLOAT16_VALUE(28.24), SIMDE_FLOAT16_VALUE(28.24) } } },
     { {  SIMDE_FLOAT16_VALUE(-14.57), SIMDE_FLOAT16_VALUE(15.78), SIMDE_FLOAT16_VALUE(3.71), SIMDE_FLOAT16_VALUE(-44.25) },
       {  SIMDE_FLOAT16_VALUE(30.42), SIMDE_FLOAT16_VALUE(7.31), SIMDE_FLOAT16_VALUE(-31.88), SIMDE_FLOAT16_VALUE(23.92)},
     { {  SIMDE_FLOAT16_VALUE(-14.57), SIMDE_FLOAT16_VALUE(-14.57), SIMDE_FLOAT16_VALUE(-14.57), SIMDE_FLOAT16_VALUE(-14.57) },
       {  SIMDE_FLOAT16_VALUE(15.78), SIMDE_FLOAT16_VALUE(15.78), SIMDE_FLOAT16_VALUE(15.78), SIMDE_FLOAT16_VALUE(15.78) },
       {  SIMDE_FLOAT16_VALUE(3.71), SIMDE_FLOAT16_VALUE(3.71), SIMDE_FLOAT16_VALUE(3.71), SIMDE_FLOAT16_VALUE(3.71) },
       {  SIMDE_FLOAT16_VALUE(-44.25), SIMDE_FLOAT16_VALUE(-44.25), SIMDE_FLOAT16_VALUE(-44.25), SIMDE_FLOAT16_VALUE(-44.25) } } },
     { {  SIMDE_FLOAT16_VALUE(-7.08), SIMDE_FLOAT16_VALUE(-13.75), SIMDE_FLOAT16_VALUE(-46.19), SIMDE_FLOAT16_VALUE(14.37) },
       {  SIMDE_FLOAT16_VALUE(-44.62), SIMDE_FLOAT16_VALUE(-35.77), SIMDE_FLOAT16_VALUE(-19.37), SIMDE_FLOAT16_VALUE(18.25)},
     { {  SIMDE_FLOAT16_VALUE(-7.08), SIMDE_FLOAT16_VALUE(-7.08), SIMDE_FLOAT16_VALUE(-7.08), SIMDE_FLOAT16_VALUE(-7.08) },
       {  SIMDE_FLOAT16_VALUE(-13.75), SIMDE_FLOAT16_VALUE(-13.75), SIMDE_FLOAT16_VALUE(-13.75), SIMDE_FLOAT16_VALUE(-13.75) },
       {  SIMDE_FLOAT16_VALUE(-46.19), SIMDE_FLOAT16_VALUE(-46.19), SIMDE_FLOAT16_VALUE(-46.19), SIMDE_FLOAT16_VALUE(-46.19) },
       {  SIMDE_FLOAT16_VALUE(14.37), SIMDE_FLOAT16_VALUE(14.37), SIMDE_FLOAT16_VALUE(14.37), SIMDE_FLOAT16_VALUE(14.37) } } },
     { {  SIMDE_FLOAT16_VALUE(-41.21), SIMDE_FLOAT16_VALUE(23.55), SIMDE_FLOAT16_VALUE(-20.74), SIMDE_FLOAT16_VALUE(31.91) },
       {  SIMDE_FLOAT16_VALUE(-5.45), SIMDE_FLOAT16_VALUE(-43.69), SIMDE_FLOAT16_VALUE(1.07), SIMDE_FLOAT16_VALUE(-15.34)},
     { {  SIMDE_FLOAT16_VALUE(-41.21), SIMDE_FLOAT16_VALUE(-41.21), SIMDE_FLOAT16_VALUE(-41.21), SIMDE_FLOAT16_VALUE(-41.21) },
       {  SIMDE_FLOAT16_VALUE(23.55), SIMDE_FLOAT16_VALUE(23.55), SIMDE_FLOAT16_VALUE(23.55), SIMDE_FLOAT16_VALUE(23.55) },
       {  SIMDE_FLOAT16_VALUE(-20.74), SIMDE_FLOAT16_VALUE(-20.74), SIMDE_FLOAT16_VALUE(-20.74), SIMDE_FLOAT16_VALUE(-20.74) },
       {  SIMDE_FLOAT16_VALUE(31.91), SIMDE_FLOAT16_VALUE(31.91), SIMDE_FLOAT16_VALUE(31.91), SIMDE_FLOAT16_VALUE(31.91) } } },
     { {  SIMDE_FLOAT16_VALUE(12.19), SIMDE_FLOAT16_VALUE(-39.62), SIMDE_FLOAT16_VALUE(26.35), SIMDE_FLOAT16_VALUE(24.05) },
       {  SIMDE_FLOAT16_VALUE(14.14), SIMDE_FLOAT16_VALUE(-6.68), SIMDE_FLOAT16_VALUE(-34.58), SIMDE_FLOAT16_VALUE(17.64)},
     { {  SIMDE_FLOAT16_VALUE(12.19), SIMDE_FLOAT16_VALUE(12.19), SIMDE_FLOAT16_VALUE(12.19), SIMDE_FLOAT16_VALUE(12.19) },
       {  SIMDE_FLOAT16_VALUE(-39.62), SIMDE_FLOAT16_VALUE(-39.62), SIMDE_FLOAT16_VALUE(-39.62), SIMDE_FLOAT16_VALUE(-39.62) },
       {  SIMDE_FLOAT16_VALUE(26.35), SIMDE_FLOAT16_VALUE(26.35), SIMDE_FLOAT16_VALUE(26.35), SIMDE_FLOAT16_VALUE(26.35) },
       {  SIMDE_FLOAT16_VALUE(24.05), SIMDE_FLOAT16_VALUE(24.05), SIMDE_FLOAT16_VALUE(24.05), SIMDE_FLOAT16_VALUE(24.05) } } },
     { {  SIMDE_FLOAT16_VALUE(32.66), SIMDE_FLOAT16_VALUE(22.65), SIMDE_FLOAT16_VALUE(-23.52), SIMDE_FLOAT16_VALUE(8.31) },
       {  SIMDE_FLOAT16_VALUE(-26.83), SIMDE_FLOAT16_VALUE(-6.25), SIMDE_FLOAT16_VALUE(38.29), SIMDE_FLOAT16_VALUE(-48.88)},
     { {  SIMDE_FLOAT16_VALUE(32.66), SIMDE_FLOAT16_VALUE(32.66), SIMDE_FLOAT16_VALUE(32.66), SIMDE_FLOAT16_VALUE(32.66) },
       {  SIMDE_FLOAT16_VALUE(22.65), SIMDE_FLOAT16_VALUE(22.65), SIMDE_FLOAT16_VALUE(22.65), SIMDE_FLOAT16_VALUE(22.65) },
       {  SIMDE_FLOAT16_VALUE(-23.52), SIMDE_FLOAT16_VALUE(-23.52), SIMDE_FLOAT16_VALUE(-23.52), SIMDE_FLOAT16_VALUE(-23.52) },
       {  SIMDE_FLOAT16_VALUE(8.31), SIMDE_FLOAT16_VALUE(8.31), SIMDE_FLOAT16_VALUE(8.31), SIMDE_FLOAT16_VALUE(8.31) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4x4_t r = simde_vld4_dup_f16(test_vec[i].a);
    simde_float16x4x4_t expected = {
        {simde_vld1_f16(test_vec[i].r[0]), simde_vld1_f16(test_vec[i].r[1]),
         simde_vld1_f16(test_vec[i].r[2]), simde_vld1_f16(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_f16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[2], expected.val[2], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[3], expected.val[3], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld4_dup_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[4];
    float unused[4];
    float r[4][2];
  } test_vec[] = {
     { {  SIMDE_FLOAT32_C(-4866.18), SIMDE_FLOAT32_C(3024.56), SIMDE_FLOAT32_C(4169.66), SIMDE_FLOAT32_C(3637.17) },
       {  SIMDE_FLOAT32_C(-555.46), SIMDE_FLOAT32_C(-1432.96), SIMDE_FLOAT32_C(3626.01), SIMDE_FLOAT32_C(2448.25)},
     { {  SIMDE_FLOAT32_C(-4866.18), SIMDE_FLOAT32_C(-4866.18) },
       {  SIMDE_FLOAT32_C(3024.56), SIMDE_FLOAT32_C(3024.56) },
       {  SIMDE_FLOAT32_C(4169.66), SIMDE_FLOAT32_C(4169.66) },
       {  SIMDE_FLOAT32_C(3637.17), SIMDE_FLOAT32_C(3637.17) } } },
     { {  SIMDE_FLOAT32_C(2885.92), SIMDE_FLOAT32_C(-4536.63), SIMDE_FLOAT32_C(-4711.82), SIMDE_FLOAT32_C(-1956.08) },
       {  SIMDE_FLOAT32_C(2407.68), SIMDE_FLOAT32_C(-2237.55), SIMDE_FLOAT32_C(-880.79), SIMDE_FLOAT32_C(3290.22)},
     { {  SIMDE_FLOAT32_C(2885.92), SIMDE_FLOAT32_C(2885.92) },
       {  SIMDE_FLOAT32_C(-4536.63), SIMDE_FLOAT32_C(-4536.63) },
       {  SIMDE_FLOAT32_C(-4711.82), SIMDE_FLOAT32_C(-4711.82) },
       {  SIMDE_FLOAT32_C(-1956.08), SIMDE_FLOAT32_C(-1956.08) } } },
     { {  SIMDE_FLOAT32_C(-3180.23), SIMDE_FLOAT32_C(4861.05), SIMDE_FLOAT32_C(-1648.83), SIMDE_FLOAT32_C(-2068.69) },
       {  SIMDE_FLOAT32_C(-110.56), SIMDE_FLOAT32_C(4643.01), SIMDE_FLOAT32_C(-3461.93), SIMDE_FLOAT32_C(-3173.78)},
     { {  SIMDE_FLOAT32_C(-3180.23), SIMDE_FLOAT32_C(-3180.23) },
       {  SIMDE_FLOAT32_C(4861.05), SIMDE_FLOAT32_C(4861.05) },
       {  SIMDE_FLOAT32_C(-1648.83), SIMDE_FLOAT32_C(-1648.83) },
       {  SIMDE_FLOAT32_C(-2068.69), SIMDE_FLOAT32_C(-2068.69) } } },
     { {  SIMDE_FLOAT32_C(-3256.85), SIMDE_FLOAT32_C(-2010.85), SIMDE_FLOAT32_C(1399.90), SIMDE_FLOAT32_C(846.03) },
       {  SIMDE_FLOAT32_C(3968.20), SIMDE_FLOAT32_C(-4075.92), SIMDE_FLOAT32_C(4628.91), SIMDE_FLOAT32_C(290.69)},
     { {  SIMDE_FLOAT32_C(-3256.85), SIMDE_FLOAT32_C(-3256.85) },
       {  SIMDE_FLOAT32_C(-2010.85), SIMDE_FLOAT32_C(-2010.85) },
       {  SIMDE_FLOAT32_C(1399.90), SIMDE_FLOAT32_C(1399.90) },
       {  SIMDE_FLOAT32_C(846.03), SIMDE_FLOAT32_C(846.03) } } },
     { {  SIMDE_FLOAT32_C(1551.81), SIMDE_FLOAT32_C(-4234.91), SIMDE_FLOAT32_C(966.88), SIMDE_FLOAT32_C(-4750.78) },
       {  SIMDE_FLOAT32_C(-4045.59), SIMDE_FLOAT32_C(-77.94), SIMDE_FLOAT32_C(-4706.59), SIMDE_FLOAT32_C(3025.78)},
     { {  SIMDE_FLOAT32_C(1551.81), SIMDE_FLOAT32_C(1551.81) },
       {  SIMDE_FLOAT32_C(-4234.91), SIMDE_FLOAT32_C(-4234.91) },
       {  SIMDE_FLOAT32_C(966.88), SIMDE_FLOAT32_C(966.88) },
       {  SIMDE_FLOAT32_C(-4750.78), SIMDE_FLOAT32_C(-4750.78) } } },
     { {  SIMDE_FLOAT32_C(3149.37), SIMDE_FLOAT32_C(-1958.05), SIMDE_FLOAT32_C(45.43), SIMDE_FLOAT32_C(4005.09) },
       {  SIMDE_FLOAT32_C(-4245.02), SIMDE_FLOAT32_C(3122.67), SIMDE_FLOAT32_C(-236.45), SIMDE_FLOAT32_C(1584.15)},
     { {  SIMDE_FLOAT32_C(3149.37), SIMDE_FLOAT32_C(3149.37) },
       {  SIMDE_FLOAT32_C(-1958.05), SIMDE_FLOAT32_C(-1958.05) },
       {  SIMDE_FLOAT32_C(45.43), SIMDE_FLOAT32_C(45.43) },
       {  SIMDE_FLOAT32_C(4005.09), SIMDE_FLOAT32_C(4005.09) } } },
     { {  SIMDE_FLOAT32_C(-1387.85), SIMDE_FLOAT32_C(-386.78), SIMDE_FLOAT32_C(-3491.79), SIMDE_FLOAT32_C(1968.50) },
       {  SIMDE_FLOAT32_C(-4637.25), SIMDE_FLOAT32_C(235.82), SIMDE_FLOAT32_C(4731.15), SIMDE_FLOAT32_C(1932.12)},
     { {  SIMDE_FLOAT32_C(-1387.85), SIMDE_FLOAT32_C(-1387.85) },
       {  SIMDE_FLOAT32_C(-386.78), SIMDE_FLOAT32_C(-386.78) },
       {  SIMDE_FLOAT32_C(-3491.79), SIMDE_FLOAT32_C(-3491.79) },
       {  SIMDE_FLOAT32_C(1968.50), SIMDE_FLOAT32_C(1968.50) } } },
     { {  SIMDE_FLOAT32_C(-2629.13), SIMDE_FLOAT32_C(-3081.26), SIMDE_FLOAT32_C(271.35), SIMDE_FLOAT32_C(1861.69) },
       {  SIMDE_FLOAT32_C(2693.30), SIMDE_FLOAT32_C(120.85), SIMDE_FLOAT32_C(-170.49), SIMDE_FLOAT32_C(980.19)},
     { {  SIMDE_FLOAT32_C(-2629.13), SIMDE_FLOAT32_C(-2629.13) },
       {  SIMDE_FLOAT32_C(-3081.26), SIMDE_FLOAT32_C(-3081.26) },
       {  SIMDE_FLOAT32_C(271.35), SIMDE_FLOAT32_C(271.35) },
       {  SIMDE_FLOAT32_C(1861.69), SIMDE_FLOAT32_C(1861.69) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x4_t r = simde_vld4_dup_f32(test_vec[i].a);
    simde_float32x2x4_t expected = {
        {simde_vld1_f32(test_vec[i].r[0]), simde_vld1_f32(test_vec[i].r[1]),
         simde_vld1_f32(test_vec[i].r[2]), simde_vld1_f32(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_f32x2(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r.val[2], expected.val[2], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r.val[3], expected.val[3], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld4_dup_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[4];
    simde_float64 unused[4];
    simde_float64 r[4][1];
  } test_vec[] = {
     { {  SIMDE_FLOAT64_C(445851.81), SIMDE_FLOAT64_C(-330960.40), SIMDE_FLOAT64_C(309250.45), SIMDE_FLOAT64_C(236747.13) },
       {  SIMDE_FLOAT64_C(-499126.60), SIMDE_FLOAT64_C(-369819.01), SIMDE_FLOAT64_C(-410746.00), SIMDE_FLOAT64_C(268713.23)},
     { {  SIMDE_FLOAT64_C(445851.81) },
       {  SIMDE_FLOAT64_C(-330960.40) },
       {  SIMDE_FLOAT64_C(309250.45) },
       {  SIMDE_FLOAT64_C(236747.13) } } },
     { {  SIMDE_FLOAT64_C(128919.66), SIMDE_FLOAT64_C(-78616.76), SIMDE_FLOAT64_C(-118926.72), SIMDE_FLOAT64_C(463558.82) },
       {  SIMDE_FLOAT64_C(269786.10), SIMDE_FLOAT64_C(344879.51), SIMDE_FLOAT64_C(-492649.86), SIMDE_FLOAT64_C(-294401.80)},
     { {  SIMDE_FLOAT64_C(128919.66) },
       {  SIMDE_FLOAT64_C(-78616.76) },
       {  SIMDE_FLOAT64_C(-118926.72) },
       {  SIMDE_FLOAT64_C(463558.82) } } },
     { {  SIMDE_FLOAT64_C(-436676.59), SIMDE_FLOAT64_C(55808.72), SIMDE_FLOAT64_C(103053.10), SIMDE_FLOAT64_C(-68771.59) },
       {  SIMDE_FLOAT64_C(-219554.42), SIMDE_FLOAT64_C(-365472.84), SIMDE_FLOAT64_C(-234535.24), SIMDE_FLOAT64_C(-485480.60)},
     { {  SIMDE_FLOAT64_C(-436676.59) },
       {  SIMDE_FLOAT64_C(55808.72) },
       {  SIMDE_FLOAT64_C(103053.10) },
       {  SIMDE_FLOAT64_C(-68771.59) } } },
     { {  SIMDE_FLOAT64_C(236460.67), SIMDE_FLOAT64_C(120005.12), SIMDE_FLOAT64_C(401078.09), SIMDE_FLOAT64_C(144330.41) },
       {  SIMDE_FLOAT64_C(-290342.75), SIMDE_FLOAT64_C(-428984.35), SIMDE_FLOAT64_C(481548.16), SIMDE_FLOAT64_C(-338674.87)},
     { {  SIMDE_FLOAT64_C(236460.67) },
       {  SIMDE_FLOAT64_C(120005.12) },
       {  SIMDE_FLOAT64_C(401078.09) },
       {  SIMDE_FLOAT64_C(144330.41) } } },
     { {  SIMDE_FLOAT64_C(-219732.53), SIMDE_FLOAT64_C(126809.41), SIMDE_FLOAT64_C(417292.34), SIMDE_FLOAT64_C(-172476.55) },
       {  SIMDE_FLOAT64_C(-365825.55), SIMDE_FLOAT64_C(430799.77), SIMDE_FLOAT64_C(220000.75), SIMDE_FLOAT64_C(-29407.47)},
     { {  SIMDE_FLOAT64_C(-219732.53) },
       {  SIMDE_FLOAT64_C(126809.41) },
       {  SIMDE_FLOAT64_C(417292.34) },
       {  SIMDE_FLOAT64_C(-172476.55) } } },
     { {  SIMDE_FLOAT64_C(196876.79), SIMDE_FLOAT64_C(-119084.66), SIMDE_FLOAT64_C(-283899.71), SIMDE_FLOAT64_C(-398048.79) },
       {  SIMDE_FLOAT64_C(-63597.93), SIMDE_FLOAT64_C(-490513.69), SIMDE_FLOAT64_C(221360.38), SIMDE_FLOAT64_C(306089.64)},
     { {  SIMDE_FLOAT64_C(196876.79) },
       {  SIMDE_FLOAT64_C(-119084.66) },
       {  SIMDE_FLOAT64_C(-283899.71) },
       {  SIMDE_FLOAT64_C(-398048.79) } } },
     { {  SIMDE_FLOAT64_C(29349.60), SIMDE_FLOAT64_C(-332457.61), SIMDE_FLOAT64_C(174407.67), SIMDE_FLOAT64_C(-266917.65) },
       {  SIMDE_FLOAT64_C(-134655.15), SIMDE_FLOAT64_C(201659.83), SIMDE_FLOAT64_C(310984.82), SIMDE_FLOAT64_C(382838.92)},
     { {  SIMDE_FLOAT64_C(29349.60) },
       {  SIMDE_FLOAT64_C(-332457.61) },
       {  SIMDE_FLOAT64_C(174407.67) },
       {  SIMDE_FLOAT64_C(-266917.65) } } },
     { {  SIMDE_FLOAT64_C(-451734.93), SIMDE_FLOAT64_C(-9569.57), SIMDE_FLOAT64_C(271001.72), SIMDE_FLOAT64_C(-452907.74) },
       {  SIMDE_FLOAT64_C(-167433.41), SIMDE_FLOAT64_C(322890.62), SIMDE_FLOAT64_C(-216738.19), SIMDE_FLOAT64_C(483419.12)},
     { {  SIMDE_FLOAT64_C(-451734.93) },
       {  SIMDE_FLOAT64_C(-9569.57) },
       {  SIMDE_FLOAT64_C(271001.72) },
       {  SIMDE_FLOAT64_C(-452907.74) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x4_t r = simde_vld4_dup_f64(test_vec[i].a);
    simde_float64x1x4_t expected = {
        {simde_vld1_f64(test_vec[i].r[0]), simde_vld1_f64(test_vec[i].r[1]),
         simde_vld1_f64(test_vec[i].r[2]), simde_vld1_f64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_f64x1(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x1(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x1(r.val[2], expected.val[2], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x1(r.val[3], expected.val[3], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld4_dup_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[4];
    int8_t unused[4];
    int8_t r[4][8];
  } test_vec[] = {
     { {  INT8_C(68), -INT8_C(10), INT8_C(21), -INT8_C(89) },
       {  INT8_C(75), -INT8_C(86), -INT8_C(69), -INT8_C(58)},
     { {  INT8_C(68), INT8_C(68), INT8_C(68), INT8_C(68),
        INT8_C(68), INT8_C(68), INT8_C(68), INT8_C(68) },
       {  -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10),
        -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10) },
       {  INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21),
        INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21) },
       {  -INT8_C(89), -INT8_C(89), -INT8_C(89), -INT8_C(89),
        -INT8_C(89), -INT8_C(89), -INT8_C(89), -INT8_C(89) } } },
     { {  INT8_C(4), -INT8_C(3), INT8_C(0), INT8_C(14) },
       {  INT8_C(91), -INT8_C(28), INT8_C(90), INT8_C(82)},
     { {  INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4),
        INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4) },
       {  -INT8_C(3), -INT8_C(3), -INT8_C(3), -INT8_C(3),
        -INT8_C(3), -INT8_C(3), -INT8_C(3), -INT8_C(3) },
       {  INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0),
        INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0) },
       {  INT8_C(14), INT8_C(14), INT8_C(14), INT8_C(14),
        INT8_C(14), INT8_C(14), INT8_C(14), INT8_C(14) } } },
     { {  -INT8_C(45), -INT8_C(54), -INT8_C(38), INT8_C(76) },
       {  INT8_C(47), INT8_C(56), -INT8_C(84), INT8_C(77)},
     { {  -INT8_C(45), -INT8_C(45), -INT8_C(45), -INT8_C(45),
        -INT8_C(45), -INT8_C(45), -INT8_C(45), -INT8_C(45) },
       {  -INT8_C(54), -INT8_C(54), -INT8_C(54), -INT8_C(54),
        -INT8_C(54), -INT8_C(54), -INT8_C(54), -INT8_C(54) },
       {  -INT8_C(38), -INT8_C(38), -INT8_C(38), -INT8_C(38),
        -INT8_C(38), -INT8_C(38), -INT8_C(38), -INT8_C(38) },
       {  INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76),
        INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76) } } },
     { {  INT8_C(58), -INT8_C(36), -INT8_C(36), -INT8_C(12) },
       {  -INT8_C(65), INT8_C(81), INT8_C(42), INT8_C(83)},
     { {  INT8_C(58), INT8_C(58), INT8_C(58), INT8_C(58),
        INT8_C(58), INT8_C(58), INT8_C(58), INT8_C(58) },
       {  -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36),
        -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36) },
       {  -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36),
        -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36) },
       {  -INT8_C(12), -INT8_C(12), -INT8_C(12), -INT8_C(12),
        -INT8_C(12), -INT8_C(12), -INT8_C(12), -INT8_C(12) } } },
     { {  INT8_C(59), INT8_C(19), INT8_C(19), -INT8_C(70) },
       {  INT8_C(39), -INT8_C(22), -INT8_C(45), INT8_C(85)},
     { {  INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59),
        INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59) },
       {  INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19),
        INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19) },
       {  INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19),
        INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19) },
       {  -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70),
        -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70) } } },
     { {  -INT8_C(61), -INT8_C(4), -INT8_C(96), -INT8_C(27) },
       {  INT8_C(5), INT8_C(13), INT8_C(35), INT8_C(16)},
     { {  -INT8_C(61), -INT8_C(61), -INT8_C(61), -INT8_C(61),
        -INT8_C(61), -INT8_C(61), -INT8_C(61), -INT8_C(61) },
       {  -INT8_C(4), -INT8_C(4), -INT8_C(4), -INT8_C(4),
        -INT8_C(4), -INT8_C(4), -INT8_C(4), -INT8_C(4) },
       {  -INT8_C(96), -INT8_C(96), -INT8_C(96), -INT8_C(96),
        -INT8_C(96), -INT8_C(96), -INT8_C(96), -INT8_C(96) },
       {  -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27),
        -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27) } } },
     { {  -INT8_C(14), INT8_C(0), INT8_C(90), -INT8_C(64) },
       {  -INT8_C(16), -INT8_C(49), INT8_C(66), -INT8_C(88)},
     { {  -INT8_C(14), -INT8_C(14), -INT8_C(14), -INT8_C(14),
        -INT8_C(14), -INT8_C(14), -INT8_C(14), -INT8_C(14) },
       {  INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0),
        INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0) },
       {  INT8_C(90), INT8_C(90), INT8_C(90), INT8_C(90),
        INT8_C(90), INT8_C(90), INT8_C(90), INT8_C(90) },
       {  -INT8_C(64), -INT8_C(64), -INT8_C(64), -INT8_C(64),
        -INT8_C(64), -INT8_C(64), -INT8_C(64), -INT8_C(64) } } },
     { {  INT8_C(12), INT8_C(19), -INT8_C(31), INT8_C(73) },
       {  INT8_C(68), -INT8_C(22), -INT8_C(73), -INT8_C(35)},
     { {  INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12),
        INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12) },
       {  INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19),
        INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19) },
       {  -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31),
        -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31) },
       {  INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73),
        INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x4_t r = simde_vld4_dup_s8(test_vec[i].a);
    simde_int8x8x4_t expected = {
        {simde_vld1_s8(test_vec[i].r[0]), simde_vld1_s8(test_vec[i].r[1]),
         simde_vld1_s8(test_vec[i].r[2]), simde_vld1_s8(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4_dup_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    int16_t unused[4];
    int16_t r[4][4];
  } test_vec[] = {
     { {  -INT16_C(1402), -INT16_C(4269), INT16_C(9722), INT16_C(6315) },
       {  -INT16_C(6328), -INT16_C(6730), -INT16_C(363), -INT16_C(2341)},
     { {  -INT16_C(1402), -INT16_C(1402), -INT16_C(1402), -INT16_C(1402) },
       {  -INT16_C(4269), -INT16_C(4269), -INT16_C(4269), -INT16_C(4269) },
       {  INT16_C(9722), INT16_C(9722), INT16_C(9722), INT16_C(9722) },
       {  INT16_C(6315), INT16_C(6315), INT16_C(6315), INT16_C(6315) } } },
     { {  -INT16_C(6055), INT16_C(9968), -INT16_C(8842), -INT16_C(8554) },
       {  -INT16_C(1679), -INT16_C(8145), -INT16_C(3034), INT16_C(7239)},
     { {  -INT16_C(6055), -INT16_C(6055), -INT16_C(6055), -INT16_C(6055) },
       {  INT16_C(9968), INT16_C(9968), INT16_C(9968), INT16_C(9968) },
       {  -INT16_C(8842), -INT16_C(8842), -INT16_C(8842), -INT16_C(8842) },
       {  -INT16_C(8554), -INT16_C(8554), -INT16_C(8554), -INT16_C(8554) } } },
     { {  INT16_C(9981), -INT16_C(5549), INT16_C(7977), INT16_C(4465) },
       {  INT16_C(2194), INT16_C(1398), INT16_C(7386), -INT16_C(5978)},
     { {  INT16_C(9981), INT16_C(9981), INT16_C(9981), INT16_C(9981) },
       {  -INT16_C(5549), -INT16_C(5549), -INT16_C(5549), -INT16_C(5549) },
       {  INT16_C(7977), INT16_C(7977), INT16_C(7977), INT16_C(7977) },
       {  INT16_C(4465), INT16_C(4465), INT16_C(4465), INT16_C(4465) } } },
     { {  INT16_C(1524), INT16_C(3583), INT16_C(3051), -INT16_C(4914) },
       {  INT16_C(7240), -INT16_C(9368), INT16_C(4797), -INT16_C(928)},
     { {  INT16_C(1524), INT16_C(1524), INT16_C(1524), INT16_C(1524) },
       {  INT16_C(3583), INT16_C(3583), INT16_C(3583), INT16_C(3583) },
       {  INT16_C(3051), INT16_C(3051), INT16_C(3051), INT16_C(3051) },
       {  -INT16_C(4914), -INT16_C(4914), -INT16_C(4914), -INT16_C(4914) } } },
     { {  INT16_C(3773), INT16_C(2624), -INT16_C(3277), INT16_C(1755) },
       {  -INT16_C(1621), INT16_C(4772), INT16_C(1264), -INT16_C(7704)},
     { {  INT16_C(3773), INT16_C(3773), INT16_C(3773), INT16_C(3773) },
       {  INT16_C(2624), INT16_C(2624), INT16_C(2624), INT16_C(2624) },
       {  -INT16_C(3277), -INT16_C(3277), -INT16_C(3277), -INT16_C(3277) },
       {  INT16_C(1755), INT16_C(1755), INT16_C(1755), INT16_C(1755) } } },
     { {  INT16_C(5286), INT16_C(2345), -INT16_C(5987), -INT16_C(2753) },
       {  INT16_C(6664), -INT16_C(2286), -INT16_C(7865), -INT16_C(1672)},
     { {  INT16_C(5286), INT16_C(5286), INT16_C(5286), INT16_C(5286) },
       {  INT16_C(2345), INT16_C(2345), INT16_C(2345), INT16_C(2345) },
       {  -INT16_C(5987), -INT16_C(5987), -INT16_C(5987), -INT16_C(5987) },
       {  -INT16_C(2753), -INT16_C(2753), -INT16_C(2753), -INT16_C(2753) } } },
     { {  INT16_C(2561), -INT16_C(9303), INT16_C(1061), -INT16_C(7213) },
       {  -INT16_C(881), -INT16_C(3042), -INT16_C(8610), INT16_C(7325)},
     { {  INT16_C(2561), INT16_C(2561), INT16_C(2561), INT16_C(2561) },
       {  -INT16_C(9303), -INT16_C(9303), -INT16_C(9303), -INT16_C(9303) },
       {  INT16_C(1061), INT16_C(1061), INT16_C(1061), INT16_C(1061) },
       {  -INT16_C(7213), -INT16_C(7213), -INT16_C(7213), -INT16_C(7213) } } },
     { {  -INT16_C(7579), -INT16_C(9735), INT16_C(7966), -INT16_C(6710) },
       {  INT16_C(4700), INT16_C(1443), -INT16_C(9728), INT16_C(4236)},
     { {  -INT16_C(7579), -INT16_C(7579), -INT16_C(7579), -INT16_C(7579) },
       {  -INT16_C(9735), -INT16_C(9735), -INT16_C(9735), -INT16_C(9735) },
       {  INT16_C(7966), INT16_C(7966), INT16_C(7966), INT16_C(7966) },
       {  -INT16_C(6710), -INT16_C(6710), -INT16_C(6710), -INT16_C(6710) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x4_t r = simde_vld4_dup_s16(test_vec[i].a);
    simde_int16x4x4_t expected = {
        {simde_vld1_s16(test_vec[i].r[0]), simde_vld1_s16(test_vec[i].r[1]),
         simde_vld1_s16(test_vec[i].r[2]), simde_vld1_s16(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_i16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4_dup_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t unused[4];
    int32_t r[4][2];
  } test_vec[] = {
     { {  -INT32_C(652086), INT32_C(830115), INT32_C(895273), INT32_C(232307) },
       {  INT32_C(514922), INT32_C(559641), INT32_C(719002), -INT32_C(522640)},
     { {  -INT32_C(652086), -INT32_C(652086) },
       {  INT32_C(830115), INT32_C(830115) },
       {  INT32_C(895273), INT32_C(895273) },
       {  INT32_C(232307), INT32_C(232307) } } },
     { {  INT32_C(82629), -INT32_C(89616), -INT32_C(760319), -INT32_C(327798) },
       {  INT32_C(554229), INT32_C(682786), -INT32_C(465184), -INT32_C(155186)},
     { {  INT32_C(82629), INT32_C(82629) },
       {  -INT32_C(89616), -INT32_C(89616) },
       {  -INT32_C(760319), -INT32_C(760319) },
       {  -INT32_C(327798), -INT32_C(327798) } } },
     { {  INT32_C(615756), INT32_C(857632), INT32_C(581076), -INT32_C(492986) },
       {  INT32_C(528868), INT32_C(762087), -INT32_C(681106), INT32_C(872087)},
     { {  INT32_C(615756), INT32_C(615756) },
       {  INT32_C(857632), INT32_C(857632) },
       {  INT32_C(581076), INT32_C(581076) },
       {  -INT32_C(492986), -INT32_C(492986) } } },
     { {  INT32_C(561833), INT32_C(921404), -INT32_C(122567), -INT32_C(732579) },
       {  INT32_C(430965), -INT32_C(874932), -INT32_C(757332), INT32_C(938068)},
     { {  INT32_C(561833), INT32_C(561833) },
       {  INT32_C(921404), INT32_C(921404) },
       {  -INT32_C(122567), -INT32_C(122567) },
       {  -INT32_C(732579), -INT32_C(732579) } } },
     { {  -INT32_C(939154), INT32_C(381182), INT32_C(713323), INT32_C(605166) },
       {  -INT32_C(796256), INT32_C(261174), -INT32_C(632162), -INT32_C(411330)},
     { {  -INT32_C(939154), -INT32_C(939154) },
       {  INT32_C(381182), INT32_C(381182) },
       {  INT32_C(713323), INT32_C(713323) },
       {  INT32_C(605166), INT32_C(605166) } } },
     { {  INT32_C(841578), -INT32_C(117022), INT32_C(195746), INT32_C(170810) },
       {  INT32_C(250486), -INT32_C(118087), INT32_C(147822), -INT32_C(446251)},
     { {  INT32_C(841578), INT32_C(841578) },
       {  -INT32_C(117022), -INT32_C(117022) },
       {  INT32_C(195746), INT32_C(195746) },
       {  INT32_C(170810), INT32_C(170810) } } },
     { {  INT32_C(625951), -INT32_C(434473), -INT32_C(487392), INT32_C(450871) },
       {  -INT32_C(21248), -INT32_C(49978), -INT32_C(870372), INT32_C(829835)},
     { {  INT32_C(625951), INT32_C(625951) },
       {  -INT32_C(434473), -INT32_C(434473) },
       {  -INT32_C(487392), -INT32_C(487392) },
       {  INT32_C(450871), INT32_C(450871) } } },
     { {  -INT32_C(233278), INT32_C(485494), INT32_C(80564), INT32_C(415117) },
       {  INT32_C(663911), INT32_C(238735), -INT32_C(926064), -INT32_C(519217)},
     { {  -INT32_C(233278), -INT32_C(233278) },
       {  INT32_C(485494), INT32_C(485494) },
       {  INT32_C(80564), INT32_C(80564) },
       {  INT32_C(415117), INT32_C(415117) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x4_t r = simde_vld4_dup_s32(test_vec[i].a);
    simde_int32x2x4_t expected = {
        {simde_vld1_s32(test_vec[i].r[0]), simde_vld1_s32(test_vec[i].r[1]),
         simde_vld1_s32(test_vec[i].r[2]), simde_vld1_s32(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_i32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4_dup_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[4];
    int64_t unused[4];
    int64_t r[4][1];
  } test_vec[] = {
     { {  -INT64_C(56733020), -INT64_C(17318014), INT64_C(12078569), INT64_C(82612068) },
       {  -INT64_C(20859555), INT64_C(24737019), -INT64_C(20445337), INT64_C(67301356)},
     { {  -INT64_C(56733020) },
       {  -INT64_C(17318014) },
       {  INT64_C(12078569) },
       {  INT64_C(82612068) } } },
     { {  INT64_C(1202527), INT64_C(4559604), INT64_C(14768409), -INT64_C(2188024) },
       {  -INT64_C(21310606), INT64_C(5729689), -INT64_C(99218139), -INT64_C(6040)},
     { {  INT64_C(1202527) },
       {  INT64_C(4559604) },
       {  INT64_C(14768409) },
       {  -INT64_C(2188024) } } },
     { {  -INT64_C(75916173), -INT64_C(36700612), -INT64_C(62050202), INT64_C(75384012) },
       {  -INT64_C(89468615), -INT64_C(42608876), INT64_C(11124466), INT64_C(56397635)},
     { {  -INT64_C(75916173) },
       {  -INT64_C(36700612) },
       {  -INT64_C(62050202) },
       {  INT64_C(75384012) } } },
     { {  INT64_C(76939592), -INT64_C(95421372), INT64_C(45337248), -INT64_C(57030409) },
       {  INT64_C(49021299), -INT64_C(76456874), -INT64_C(18305372), INT64_C(85721942)},
     { {  INT64_C(76939592) },
       {  -INT64_C(95421372) },
       {  INT64_C(45337248) },
       {  -INT64_C(57030409) } } },
     { {  -INT64_C(86501396), INT64_C(88982191), -INT64_C(84306578), INT64_C(13244094) },
       {  INT64_C(92227627), INT64_C(69395035), INT64_C(98608750), INT64_C(37417231)},
     { {  -INT64_C(86501396) },
       {  INT64_C(88982191) },
       {  -INT64_C(84306578) },
       {  INT64_C(13244094) } } },
     { {  -INT64_C(87804813), -INT64_C(41441843), -INT64_C(85279399), INT64_C(49312807) },
       {  INT64_C(20569053), INT64_C(13178173), INT64_C(24706835), INT64_C(40884278)},
     { {  -INT64_C(87804813) },
       {  -INT64_C(41441843) },
       {  -INT64_C(85279399) },
       {  INT64_C(49312807) } } },
     { {  -INT64_C(20293605), -INT64_C(9407517), INT64_C(48222736), -INT64_C(54034755) },
       {  -INT64_C(87497232), -INT64_C(49279753), INT64_C(94490130), INT64_C(30019721)},
     { {  -INT64_C(20293605) },
       {  -INT64_C(9407517) },
       {  INT64_C(48222736) },
       {  -INT64_C(54034755) } } },
     { {  -INT64_C(91077708), INT64_C(43106202), INT64_C(30721388), -INT64_C(92913395) },
       {  INT64_C(86136901), INT64_C(40220309), -INT64_C(67313051), INT64_C(57922186)},
     { {  -INT64_C(91077708) },
       {  INT64_C(43106202) },
       {  INT64_C(30721388) },
       {  -INT64_C(92913395) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x4_t r = simde_vld4_dup_s64(test_vec[i].a);
    simde_int64x1x4_t expected = {
        {simde_vld1_s64(test_vec[i].r[0]), simde_vld1_s64(test_vec[i].r[1]),
         simde_vld1_s64(test_vec[i].r[2]), simde_vld1_s64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_i64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4_dup_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a[4];
    uint8_t unused[4];
    uint8_t r[4][8];
  } test_vec[] = {
     { {  UINT8_C(113), UINT8_C(73), UINT8_C(82), UINT8_C(124) },
       {  UINT8_C(97), UINT8_C(44), UINT8_C(46), UINT8_C(6)},
     { {  UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113),
        UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113) },
       {  UINT8_C(73), UINT8_C(73), UINT8_C(73), UINT8_C(73),
        UINT8_C(73), UINT8_C(73), UINT8_C(73), UINT8_C(73) },
       {  UINT8_C(82), UINT8_C(82), UINT8_C(82), UINT8_C(82),
        UINT8_C(82), UINT8_C(82), UINT8_C(82), UINT8_C(82) },
       {  UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124),
        UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124) } } },
     { {  UINT8_C(123), UINT8_C(99), UINT8_C(73), UINT8_C(31) },
       {  UINT8_C(12), UINT8_C(196), UINT8_C(169), UINT8_C(0)},
     { {  UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123),
        UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123) },
       {  UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99),
        UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99) },
       {  UINT8_C(73), UINT8_C(73), UINT8_C(73), UINT8_C(73),
        UINT8_C(73), UINT8_C(73), UINT8_C(73), UINT8_C(73) },
       {  UINT8_C(31), UINT8_C(31), UINT8_C(31), UINT8_C(31),
        UINT8_C(31), UINT8_C(31), UINT8_C(31), UINT8_C(31) } } },
     { {  UINT8_C(49), UINT8_C(131), UINT8_C(102), UINT8_C(104) },
       {  UINT8_C(85), UINT8_C(1), UINT8_C(54), UINT8_C(25)},
     { {  UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49),
        UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49) },
       {  UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131),
        UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131) },
       {  UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102),
        UINT8_C(102), UINT8_C(102), UINT8_C(102), UINT8_C(102) },
       {  UINT8_C(104), UINT8_C(104), UINT8_C(104), UINT8_C(104),
        UINT8_C(104), UINT8_C(104), UINT8_C(104), UINT8_C(104) } } },
     { {  UINT8_C(188), UINT8_C(156), UINT8_C(48), UINT8_C(9) },
       {  UINT8_C(54), UINT8_C(21), UINT8_C(63), UINT8_C(114)},
     { {  UINT8_C(188), UINT8_C(188), UINT8_C(188), UINT8_C(188),
        UINT8_C(188), UINT8_C(188), UINT8_C(188), UINT8_C(188) },
       {  UINT8_C(156), UINT8_C(156), UINT8_C(156), UINT8_C(156),
        UINT8_C(156), UINT8_C(156), UINT8_C(156), UINT8_C(156) },
       {  UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48),
        UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48) },
       {  UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9),
        UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9) } } },
     { {  UINT8_C(110), UINT8_C(3), UINT8_C(48), UINT8_C(70) },
       {  UINT8_C(139), UINT8_C(154), UINT8_C(160), UINT8_C(139)},
     { {  UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110),
        UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110) },
       {  UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3),
        UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3) },
       {  UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48),
        UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48) },
       {  UINT8_C(70), UINT8_C(70), UINT8_C(70), UINT8_C(70),
        UINT8_C(70), UINT8_C(70), UINT8_C(70), UINT8_C(70) } } },
     { {  UINT8_C(29), UINT8_C(99), UINT8_C(185), UINT8_C(126) },
       {  UINT8_C(199), UINT8_C(190), UINT8_C(74), UINT8_C(66)},
     { {  UINT8_C(29), UINT8_C(29), UINT8_C(29), UINT8_C(29),
        UINT8_C(29), UINT8_C(29), UINT8_C(29), UINT8_C(29) },
       {  UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99),
        UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99) },
       {  UINT8_C(185), UINT8_C(185), UINT8_C(185), UINT8_C(185),
        UINT8_C(185), UINT8_C(185), UINT8_C(185), UINT8_C(185) },
       {  UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126),
        UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126) } } },
     { {  UINT8_C(78), UINT8_C(22), UINT8_C(96), UINT8_C(181) },
       {  UINT8_C(7), UINT8_C(36), UINT8_C(58), UINT8_C(159)},
     { {  UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78),
        UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78) },
       {  UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22),
        UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22) },
       {  UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96),
        UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96) },
       {  UINT8_C(181), UINT8_C(181), UINT8_C(181), UINT8_C(181),
        UINT8_C(181), UINT8_C(181), UINT8_C(181), UINT8_C(181) } } },
     { {  UINT8_C(15), UINT8_C(77), UINT8_C(33), UINT8_C(133) },
       {  UINT8_C(85), UINT8_C(81), UINT8_C(52), UINT8_C(199)},
     { {  UINT8_C(15), UINT8_C(15), UINT8_C(15), UINT8_C(15),
        UINT8_C(15), UINT8_C(15), UINT8_C(15), UINT8_C(15) },
       {  UINT8_C(77), UINT8_C(77), UINT8_C(77), UINT8_C(77),
        UINT8_C(77), UINT8_C(77), UINT8_C(77), UINT8_C(77) },
       {  UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33),
        UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33) },
       {  UINT8_C(133), UINT8_C(133), UINT8_C(133), UINT8_C(133),
        UINT8_C(133), UINT8_C(133), UINT8_C(133), UINT8_C(133) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x4_t r = simde_vld4_dup_u8(test_vec[i].a);
    simde_uint8x8x4_t expected = {
        {simde_vld1_u8(test_vec[i].r[0]), simde_vld1_u8(test_vec[i].r[1]),
         simde_vld1_u8(test_vec[i].r[2]), simde_vld1_u8(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4_dup_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[4];
    uint16_t unused[4];
    uint16_t r[4][4];
  } test_vec[] = {
     { {  UINT16_C(15647), UINT16_C(8273), UINT16_C(18121), UINT16_C(3909) },
       {  UINT16_C(3886), UINT16_C(18927), UINT16_C(6497), UINT16_C(15716)},
     { {  UINT16_C(15647), UINT16_C(15647), UINT16_C(15647), UINT16_C(15647) },
       {  UINT16_C(8273), UINT16_C(8273), UINT16_C(8273), UINT16_C(8273) },
       {  UINT16_C(18121), UINT16_C(18121), UINT16_C(18121), UINT16_C(18121) },
       {  UINT16_C(3909), UINT16_C(3909), UINT16_C(3909), UINT16_C(3909) } } },
     { {  UINT16_C(10363), UINT16_C(741), UINT16_C(19314), UINT16_C(207) },
       {  UINT16_C(18543), UINT16_C(10812), UINT16_C(4523), UINT16_C(17338)},
     { {  UINT16_C(10363), UINT16_C(10363), UINT16_C(10363), UINT16_C(10363) },
       {  UINT16_C(741), UINT16_C(741), UINT16_C(741), UINT16_C(741) },
       {  UINT16_C(19314), UINT16_C(19314), UINT16_C(19314), UINT16_C(19314) },
       {  UINT16_C(207), UINT16_C(207), UINT16_C(207), UINT16_C(207) } } },
     { {  UINT16_C(1661), UINT16_C(15340), UINT16_C(9240), UINT16_C(2126) },
       {  UINT16_C(19898), UINT16_C(6041), UINT16_C(8131), UINT16_C(5048)},
     { {  UINT16_C(1661), UINT16_C(1661), UINT16_C(1661), UINT16_C(1661) },
       {  UINT16_C(15340), UINT16_C(15340), UINT16_C(15340), UINT16_C(15340) },
       {  UINT16_C(9240), UINT16_C(9240), UINT16_C(9240), UINT16_C(9240) },
       {  UINT16_C(2126), UINT16_C(2126), UINT16_C(2126), UINT16_C(2126) } } },
     { {  UINT16_C(18793), UINT16_C(9875), UINT16_C(19455), UINT16_C(5867) },
       {  UINT16_C(6575), UINT16_C(19585), UINT16_C(56), UINT16_C(13746)},
     { {  UINT16_C(18793), UINT16_C(18793), UINT16_C(18793), UINT16_C(18793) },
       {  UINT16_C(9875), UINT16_C(9875), UINT16_C(9875), UINT16_C(9875) },
       {  UINT16_C(19455), UINT16_C(19455), UINT16_C(19455), UINT16_C(19455) },
       {  UINT16_C(5867), UINT16_C(5867), UINT16_C(5867), UINT16_C(5867) } } },
     { {  UINT16_C(7315), UINT16_C(11780), UINT16_C(12282), UINT16_C(249) },
       {  UINT16_C(2882), UINT16_C(5581), UINT16_C(2639), UINT16_C(13799)},
     { {  UINT16_C(7315), UINT16_C(7315), UINT16_C(7315), UINT16_C(7315) },
       {  UINT16_C(11780), UINT16_C(11780), UINT16_C(11780), UINT16_C(11780) },
       {  UINT16_C(12282), UINT16_C(12282), UINT16_C(12282), UINT16_C(12282) },
       {  UINT16_C(249), UINT16_C(249), UINT16_C(249), UINT16_C(249) } } },
     { {  UINT16_C(18499), UINT16_C(11815), UINT16_C(19200), UINT16_C(9265) },
       {  UINT16_C(17744), UINT16_C(12481), UINT16_C(12307), UINT16_C(15151)},
     { {  UINT16_C(18499), UINT16_C(18499), UINT16_C(18499), UINT16_C(18499) },
       {  UINT16_C(11815), UINT16_C(11815), UINT16_C(11815), UINT16_C(11815) },
       {  UINT16_C(19200), UINT16_C(19200), UINT16_C(19200), UINT16_C(19200) },
       {  UINT16_C(9265), UINT16_C(9265), UINT16_C(9265), UINT16_C(9265) } } },
     { {  UINT16_C(17166), UINT16_C(17671), UINT16_C(16947), UINT16_C(2009) },
       {  UINT16_C(5791), UINT16_C(6900), UINT16_C(7399), UINT16_C(18218)},
     { {  UINT16_C(17166), UINT16_C(17166), UINT16_C(17166), UINT16_C(17166) },
       {  UINT16_C(17671), UINT16_C(17671), UINT16_C(17671), UINT16_C(17671) },
       {  UINT16_C(16947), UINT16_C(16947), UINT16_C(16947), UINT16_C(16947) },
       {  UINT16_C(2009), UINT16_C(2009), UINT16_C(2009), UINT16_C(2009) } } },
     { {  UINT16_C(14861), UINT16_C(6270), UINT16_C(16359), UINT16_C(971) },
       {  UINT16_C(5169), UINT16_C(10261), UINT16_C(5910), UINT16_C(17221)},
     { {  UINT16_C(14861), UINT16_C(14861), UINT16_C(14861), UINT16_C(14861) },
       {  UINT16_C(6270), UINT16_C(6270), UINT16_C(6270), UINT16_C(6270) },
       {  UINT16_C(16359), UINT16_C(16359), UINT16_C(16359), UINT16_C(16359) },
       {  UINT16_C(971), UINT16_C(971), UINT16_C(971), UINT16_C(971) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x4_t r = simde_vld4_dup_u16(test_vec[i].a);
    simde_uint16x4x4_t expected = {
        {simde_vld1_u16(test_vec[i].r[0]), simde_vld1_u16(test_vec[i].r[1]),
         simde_vld1_u16(test_vec[i].r[2]), simde_vld1_u16(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_u16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4_dup_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint32_t unused[4];
    uint32_t r[4][2];
  } test_vec[] = {
     { {  UINT32_C(1580541), UINT32_C(1654270), UINT32_C(1830042), UINT32_C(684375) },
       {  UINT32_C(1813447), UINT32_C(569485), UINT32_C(617848), UINT32_C(816228)},
     { {  UINT32_C(1580541), UINT32_C(1580541) },
       {  UINT32_C(1654270), UINT32_C(1654270) },
       {  UINT32_C(1830042), UINT32_C(1830042) },
       {  UINT32_C(684375), UINT32_C(684375) } } },
     { {  UINT32_C(383439), UINT32_C(1188403), UINT32_C(1689940), UINT32_C(1017721) },
       {  UINT32_C(1908956), UINT32_C(228246), UINT32_C(863980), UINT32_C(529514)},
     { {  UINT32_C(383439), UINT32_C(383439) },
       {  UINT32_C(1188403), UINT32_C(1188403) },
       {  UINT32_C(1689940), UINT32_C(1689940) },
       {  UINT32_C(1017721), UINT32_C(1017721) } } },
     { {  UINT32_C(1641180), UINT32_C(1198501), UINT32_C(101756), UINT32_C(1521669) },
       {  UINT32_C(1648251), UINT32_C(989457), UINT32_C(437928), UINT32_C(437115)},
     { {  UINT32_C(1641180), UINT32_C(1641180) },
       {  UINT32_C(1198501), UINT32_C(1198501) },
       {  UINT32_C(101756), UINT32_C(101756) },
       {  UINT32_C(1521669), UINT32_C(1521669) } } },
     { {  UINT32_C(579695), UINT32_C(353096), UINT32_C(358282), UINT32_C(1828464) },
       {  UINT32_C(1574203), UINT32_C(1363087), UINT32_C(222357), UINT32_C(275873)},
     { {  UINT32_C(579695), UINT32_C(579695) },
       {  UINT32_C(353096), UINT32_C(353096) },
       {  UINT32_C(358282), UINT32_C(358282) },
       {  UINT32_C(1828464), UINT32_C(1828464) } } },
     { {  UINT32_C(1274076), UINT32_C(1744930), UINT32_C(420354), UINT32_C(1584284) },
       {  UINT32_C(648997), UINT32_C(1376925), UINT32_C(1522400), UINT32_C(16371)},
     { {  UINT32_C(1274076), UINT32_C(1274076) },
       {  UINT32_C(1744930), UINT32_C(1744930) },
       {  UINT32_C(420354), UINT32_C(420354) },
       {  UINT32_C(1584284), UINT32_C(1584284) } } },
     { {  UINT32_C(273508), UINT32_C(1725205), UINT32_C(284994), UINT32_C(162209) },
       {  UINT32_C(346868), UINT32_C(684962), UINT32_C(673011), UINT32_C(300146)},
     { {  UINT32_C(273508), UINT32_C(273508) },
       {  UINT32_C(1725205), UINT32_C(1725205) },
       {  UINT32_C(284994), UINT32_C(284994) },
       {  UINT32_C(162209), UINT32_C(162209) } } },
     { {  UINT32_C(1835748), UINT32_C(1712160), UINT32_C(1698734), UINT32_C(1195761) },
       {  UINT32_C(1166282), UINT32_C(653660), UINT32_C(997506), UINT32_C(1595720)},
     { {  UINT32_C(1835748), UINT32_C(1835748) },
       {  UINT32_C(1712160), UINT32_C(1712160) },
       {  UINT32_C(1698734), UINT32_C(1698734) },
       {  UINT32_C(1195761), UINT32_C(1195761) } } },
     { {  UINT32_C(651276), UINT32_C(51314), UINT32_C(370628), UINT32_C(747588) },
       {  UINT32_C(1493055), UINT32_C(1665291), UINT32_C(588273), UINT32_C(971166)},
     { {  UINT32_C(651276), UINT32_C(651276) },
       {  UINT32_C(51314), UINT32_C(51314) },
       {  UINT32_C(370628), UINT32_C(370628) },
       {  UINT32_C(747588), UINT32_C(747588) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x4_t r = simde_vld4_dup_u32(test_vec[i].a);
    simde_uint32x2x4_t expected = {
        {simde_vld1_u32(test_vec[i].r[0]), simde_vld1_u32(test_vec[i].r[1]),
         simde_vld1_u32(test_vec[i].r[2]), simde_vld1_u32(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_u32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4_dup_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[4];
    uint64_t unused[4];
    uint64_t r[4][1];
  } test_vec[] = {
     { {  UINT64_C(20635395), UINT64_C(181936279), UINT64_C(150662617), UINT64_C(10660679) },
       {  UINT64_C(136081342), UINT64_C(93194088), UINT64_C(54652239), UINT64_C(62950287)},
     { {  UINT64_C(20635395) },
       {  UINT64_C(181936279) },
       {  UINT64_C(150662617) },
       {  UINT64_C(10660679) } } },
     { {  UINT64_C(118865721), UINT64_C(67478211), UINT64_C(174461108), UINT64_C(129320325) },
       {  UINT64_C(102278144), UINT64_C(102266682), UINT64_C(49889150), UINT64_C(114118451)},
     { {  UINT64_C(118865721) },
       {  UINT64_C(67478211) },
       {  UINT64_C(174461108) },
       {  UINT64_C(129320325) } } },
     { {  UINT64_C(158221320), UINT64_C(137081001), UINT64_C(7782842), UINT64_C(7026400) },
       {  UINT64_C(177159024), UINT64_C(35276486), UINT64_C(99035872), UINT64_C(158572458)},
     { {  UINT64_C(158221320) },
       {  UINT64_C(137081001) },
       {  UINT64_C(7782842) },
       {  UINT64_C(7026400) } } },
     { {  UINT64_C(115136670), UINT64_C(35261105), UINT64_C(3380463), UINT64_C(197918324) },
       {  UINT64_C(69003240), UINT64_C(32166930), UINT64_C(11534227), UINT64_C(196165286)},
     { {  UINT64_C(115136670) },
       {  UINT64_C(35261105) },
       {  UINT64_C(3380463) },
       {  UINT64_C(197918324) } } },
     { {  UINT64_C(38362170), UINT64_C(7429842), UINT64_C(80558845), UINT64_C(1179078) },
       {  UINT64_C(101090282), UINT64_C(177527039), UINT64_C(180313574), UINT64_C(57773740)},
     { {  UINT64_C(38362170) },
       {  UINT64_C(7429842) },
       {  UINT64_C(80558845) },
       {  UINT64_C(1179078) } } },
     { {  UINT64_C(59418595), UINT64_C(76632207), UINT64_C(114062680), UINT64_C(87463453) },
       {  UINT64_C(184610108), UINT64_C(46058512), UINT64_C(140438761), UINT64_C(194086293)},
     { {  UINT64_C(59418595) },
       {  UINT64_C(76632207) },
       {  UINT64_C(114062680) },
       {  UINT64_C(87463453) } } },
     { {  UINT64_C(174190462), UINT64_C(48203683), UINT64_C(9296258), UINT64_C(59202338) },
       {  UINT64_C(8720854), UINT64_C(20468168), UINT64_C(170092521), UINT64_C(134729317)},
     { {  UINT64_C(174190462) },
       {  UINT64_C(48203683) },
       {  UINT64_C(9296258) },
       {  UINT64_C(59202338) } } },
     { {  UINT64_C(130903980), UINT64_C(23165997), UINT64_C(74136997), UINT64_C(23457473) },
       {  UINT64_C(19601344), UINT64_C(85184699), UINT64_C(189848367), UINT64_C(130732569)},
     { {  UINT64_C(130903980) },
       {  UINT64_C(23165997) },
       {  UINT64_C(74136997) },
       {  UINT64_C(23457473) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x4_t r = simde_vld4_dup_u64(test_vec[i].a);
    simde_uint64x1x4_t expected = {
        {simde_vld1_u64(test_vec[i].r[0]), simde_vld1_u64(test_vec[i].r[1]),
         simde_vld1_u64(test_vec[i].r[2]), simde_vld1_u64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_u64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4q_dup_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[4];
    simde_float16_t unused[4];
    simde_float16_t r[4][8];
  } test_vec[] = {
     { {  SIMDE_FLOAT16_VALUE(31.40), SIMDE_FLOAT16_VALUE(8.80), SIMDE_FLOAT16_VALUE(7.89), SIMDE_FLOAT16_VALUE(12.74) },
       {  SIMDE_FLOAT16_VALUE(-0.13), SIMDE_FLOAT16_VALUE(-35.35), SIMDE_FLOAT16_VALUE(41.40), SIMDE_FLOAT16_VALUE(18.27)},
     { {  SIMDE_FLOAT16_VALUE(31.40), SIMDE_FLOAT16_VALUE(31.40), SIMDE_FLOAT16_VALUE(31.40), SIMDE_FLOAT16_VALUE(31.40),
        SIMDE_FLOAT16_VALUE(31.40), SIMDE_FLOAT16_VALUE(31.40), SIMDE_FLOAT16_VALUE(31.40), SIMDE_FLOAT16_VALUE(31.40) },
       {  SIMDE_FLOAT16_VALUE(8.80), SIMDE_FLOAT16_VALUE(8.80), SIMDE_FLOAT16_VALUE(8.80), SIMDE_FLOAT16_VALUE(8.80),
        SIMDE_FLOAT16_VALUE(8.80), SIMDE_FLOAT16_VALUE(8.80), SIMDE_FLOAT16_VALUE(8.80), SIMDE_FLOAT16_VALUE(8.80) },
       {  SIMDE_FLOAT16_VALUE(7.89), SIMDE_FLOAT16_VALUE(7.89), SIMDE_FLOAT16_VALUE(7.89), SIMDE_FLOAT16_VALUE(7.89),
        SIMDE_FLOAT16_VALUE(7.89), SIMDE_FLOAT16_VALUE(7.89), SIMDE_FLOAT16_VALUE(7.89), SIMDE_FLOAT16_VALUE(7.89) },
       {  SIMDE_FLOAT16_VALUE(12.74), SIMDE_FLOAT16_VALUE(12.74), SIMDE_FLOAT16_VALUE(12.74), SIMDE_FLOAT16_VALUE(12.74),
        SIMDE_FLOAT16_VALUE(12.74), SIMDE_FLOAT16_VALUE(12.74), SIMDE_FLOAT16_VALUE(12.74), SIMDE_FLOAT16_VALUE(12.74) } } },
     { {  SIMDE_FLOAT16_VALUE(42.40), SIMDE_FLOAT16_VALUE(-29.63), SIMDE_FLOAT16_VALUE(30.06), SIMDE_FLOAT16_VALUE(1.39) },
       {  SIMDE_FLOAT16_VALUE(31.88), SIMDE_FLOAT16_VALUE(-49.31), SIMDE_FLOAT16_VALUE(23.96), SIMDE_FLOAT16_VALUE(-45.98)},
     { {  SIMDE_FLOAT16_VALUE(42.40), SIMDE_FLOAT16_VALUE(42.40), SIMDE_FLOAT16_VALUE(42.40), SIMDE_FLOAT16_VALUE(42.40),
        SIMDE_FLOAT16_VALUE(42.40), SIMDE_FLOAT16_VALUE(42.40), SIMDE_FLOAT16_VALUE(42.40), SIMDE_FLOAT16_VALUE(42.40) },
       {  SIMDE_FLOAT16_VALUE(-29.63), SIMDE_FLOAT16_VALUE(-29.63), SIMDE_FLOAT16_VALUE(-29.63), SIMDE_FLOAT16_VALUE(-29.63),
        SIMDE_FLOAT16_VALUE(-29.63), SIMDE_FLOAT16_VALUE(-29.63), SIMDE_FLOAT16_VALUE(-29.63), SIMDE_FLOAT16_VALUE(-29.63) },
       {  SIMDE_FLOAT16_VALUE(30.06), SIMDE_FLOAT16_VALUE(30.06), SIMDE_FLOAT16_VALUE(30.06), SIMDE_FLOAT16_VALUE(30.06),
        SIMDE_FLOAT16_VALUE(30.06), SIMDE_FLOAT16_VALUE(30.06), SIMDE_FLOAT16_VALUE(30.06), SIMDE_FLOAT16_VALUE(30.06) },
       {  SIMDE_FLOAT16_VALUE(1.39), SIMDE_FLOAT16_VALUE(1.39), SIMDE_FLOAT16_VALUE(1.39), SIMDE_FLOAT16_VALUE(1.39),
        SIMDE_FLOAT16_VALUE(1.39), SIMDE_FLOAT16_VALUE(1.39), SIMDE_FLOAT16_VALUE(1.39), SIMDE_FLOAT16_VALUE(1.39) } } },
     { {  SIMDE_FLOAT16_VALUE(-19.20), SIMDE_FLOAT16_VALUE(-9.05), SIMDE_FLOAT16_VALUE(0.57), SIMDE_FLOAT16_VALUE(14.82) },
       {  SIMDE_FLOAT16_VALUE(-38.07), SIMDE_FLOAT16_VALUE(-33.07), SIMDE_FLOAT16_VALUE(15.20), SIMDE_FLOAT16_VALUE(3.67)},
     { {  SIMDE_FLOAT16_VALUE(-19.20), SIMDE_FLOAT16_VALUE(-19.20), SIMDE_FLOAT16_VALUE(-19.20), SIMDE_FLOAT16_VALUE(-19.20),
        SIMDE_FLOAT16_VALUE(-19.20), SIMDE_FLOAT16_VALUE(-19.20), SIMDE_FLOAT16_VALUE(-19.20), SIMDE_FLOAT16_VALUE(-19.20) },
       {  SIMDE_FLOAT16_VALUE(-9.05), SIMDE_FLOAT16_VALUE(-9.05), SIMDE_FLOAT16_VALUE(-9.05), SIMDE_FLOAT16_VALUE(-9.05),
        SIMDE_FLOAT16_VALUE(-9.05), SIMDE_FLOAT16_VALUE(-9.05), SIMDE_FLOAT16_VALUE(-9.05), SIMDE_FLOAT16_VALUE(-9.05) },
       {  SIMDE_FLOAT16_VALUE(0.57), SIMDE_FLOAT16_VALUE(0.57), SIMDE_FLOAT16_VALUE(0.57), SIMDE_FLOAT16_VALUE(0.57),
        SIMDE_FLOAT16_VALUE(0.57), SIMDE_FLOAT16_VALUE(0.57), SIMDE_FLOAT16_VALUE(0.57), SIMDE_FLOAT16_VALUE(0.57) },
       {  SIMDE_FLOAT16_VALUE(14.82), SIMDE_FLOAT16_VALUE(14.82), SIMDE_FLOAT16_VALUE(14.82), SIMDE_FLOAT16_VALUE(14.82),
        SIMDE_FLOAT16_VALUE(14.82), SIMDE_FLOAT16_VALUE(14.82), SIMDE_FLOAT16_VALUE(14.82), SIMDE_FLOAT16_VALUE(14.82) } } },
     { {  SIMDE_FLOAT16_VALUE(-12.11), SIMDE_FLOAT16_VALUE(15.24), SIMDE_FLOAT16_VALUE(34.23), SIMDE_FLOAT16_VALUE(38.58) },
       {  SIMDE_FLOAT16_VALUE(46.28), SIMDE_FLOAT16_VALUE(-11.22), SIMDE_FLOAT16_VALUE(21.51), SIMDE_FLOAT16_VALUE(-3.08)},
     { {  SIMDE_FLOAT16_VALUE(-12.11), SIMDE_FLOAT16_VALUE(-12.11), SIMDE_FLOAT16_VALUE(-12.11), SIMDE_FLOAT16_VALUE(-12.11),
        SIMDE_FLOAT16_VALUE(-12.11), SIMDE_FLOAT16_VALUE(-12.11), SIMDE_FLOAT16_VALUE(-12.11), SIMDE_FLOAT16_VALUE(-12.11) },
       {  SIMDE_FLOAT16_VALUE(15.24), SIMDE_FLOAT16_VALUE(15.24), SIMDE_FLOAT16_VALUE(15.24), SIMDE_FLOAT16_VALUE(15.24),
        SIMDE_FLOAT16_VALUE(15.24), SIMDE_FLOAT16_VALUE(15.24), SIMDE_FLOAT16_VALUE(15.24), SIMDE_FLOAT16_VALUE(15.24) },
       {  SIMDE_FLOAT16_VALUE(34.23), SIMDE_FLOAT16_VALUE(34.23), SIMDE_FLOAT16_VALUE(34.23), SIMDE_FLOAT16_VALUE(34.23),
        SIMDE_FLOAT16_VALUE(34.23), SIMDE_FLOAT16_VALUE(34.23), SIMDE_FLOAT16_VALUE(34.23), SIMDE_FLOAT16_VALUE(34.23) },
       {  SIMDE_FLOAT16_VALUE(38.58), SIMDE_FLOAT16_VALUE(38.58), SIMDE_FLOAT16_VALUE(38.58), SIMDE_FLOAT16_VALUE(38.58),
        SIMDE_FLOAT16_VALUE(38.58), SIMDE_FLOAT16_VALUE(38.58), SIMDE_FLOAT16_VALUE(38.58), SIMDE_FLOAT16_VALUE(38.58) } } },
     { {  SIMDE_FLOAT16_VALUE(-16.90), SIMDE_FLOAT16_VALUE(45.87), SIMDE_FLOAT16_VALUE(4.55), SIMDE_FLOAT16_VALUE(-31.32) },
       {  SIMDE_FLOAT16_VALUE(-4.72), SIMDE_FLOAT16_VALUE(28.72), SIMDE_FLOAT16_VALUE(26.60), SIMDE_FLOAT16_VALUE(-42.54)},
     { {  SIMDE_FLOAT16_VALUE(-16.90), SIMDE_FLOAT16_VALUE(-16.90), SIMDE_FLOAT16_VALUE(-16.90), SIMDE_FLOAT16_VALUE(-16.90),
        SIMDE_FLOAT16_VALUE(-16.90), SIMDE_FLOAT16_VALUE(-16.90), SIMDE_FLOAT16_VALUE(-16.90), SIMDE_FLOAT16_VALUE(-16.90) },
       {  SIMDE_FLOAT16_VALUE(45.87), SIMDE_FLOAT16_VALUE(45.87), SIMDE_FLOAT16_VALUE(45.87), SIMDE_FLOAT16_VALUE(45.87),
        SIMDE_FLOAT16_VALUE(45.87), SIMDE_FLOAT16_VALUE(45.87), SIMDE_FLOAT16_VALUE(45.87), SIMDE_FLOAT16_VALUE(45.87) },
       {  SIMDE_FLOAT16_VALUE(4.55), SIMDE_FLOAT16_VALUE(4.55), SIMDE_FLOAT16_VALUE(4.55), SIMDE_FLOAT16_VALUE(4.55),
        SIMDE_FLOAT16_VALUE(4.55), SIMDE_FLOAT16_VALUE(4.55), SIMDE_FLOAT16_VALUE(4.55), SIMDE_FLOAT16_VALUE(4.55) },
       {  SIMDE_FLOAT16_VALUE(-31.32), SIMDE_FLOAT16_VALUE(-31.32), SIMDE_FLOAT16_VALUE(-31.32), SIMDE_FLOAT16_VALUE(-31.32),
        SIMDE_FLOAT16_VALUE(-31.32), SIMDE_FLOAT16_VALUE(-31.32), SIMDE_FLOAT16_VALUE(-31.32), SIMDE_FLOAT16_VALUE(-31.32) } } },
     { {  SIMDE_FLOAT16_VALUE(19.79), SIMDE_FLOAT16_VALUE(20.65), SIMDE_FLOAT16_VALUE(-41.73), SIMDE_FLOAT16_VALUE(27.61) },
       {  SIMDE_FLOAT16_VALUE(-46.55), SIMDE_FLOAT16_VALUE(-27.42), SIMDE_FLOAT16_VALUE(0.86), SIMDE_FLOAT16_VALUE(11.71)},
     { {  SIMDE_FLOAT16_VALUE(19.79), SIMDE_FLOAT16_VALUE(19.79), SIMDE_FLOAT16_VALUE(19.79), SIMDE_FLOAT16_VALUE(19.79),
        SIMDE_FLOAT16_VALUE(19.79), SIMDE_FLOAT16_VALUE(19.79), SIMDE_FLOAT16_VALUE(19.79), SIMDE_FLOAT16_VALUE(19.79) },
       {  SIMDE_FLOAT16_VALUE(20.65), SIMDE_FLOAT16_VALUE(20.65), SIMDE_FLOAT16_VALUE(20.65), SIMDE_FLOAT16_VALUE(20.65),
        SIMDE_FLOAT16_VALUE(20.65), SIMDE_FLOAT16_VALUE(20.65), SIMDE_FLOAT16_VALUE(20.65), SIMDE_FLOAT16_VALUE(20.65) },
       {  SIMDE_FLOAT16_VALUE(-41.73), SIMDE_FLOAT16_VALUE(-41.73), SIMDE_FLOAT16_VALUE(-41.73), SIMDE_FLOAT16_VALUE(-41.73),
        SIMDE_FLOAT16_VALUE(-41.73), SIMDE_FLOAT16_VALUE(-41.73), SIMDE_FLOAT16_VALUE(-41.73), SIMDE_FLOAT16_VALUE(-41.73) },
       {  SIMDE_FLOAT16_VALUE(27.61), SIMDE_FLOAT16_VALUE(27.61), SIMDE_FLOAT16_VALUE(27.61), SIMDE_FLOAT16_VALUE(27.61),
        SIMDE_FLOAT16_VALUE(27.61), SIMDE_FLOAT16_VALUE(27.61), SIMDE_FLOAT16_VALUE(27.61), SIMDE_FLOAT16_VALUE(27.61) } } },
     { {  SIMDE_FLOAT16_VALUE(33.12), SIMDE_FLOAT16_VALUE(-27.38), SIMDE_FLOAT16_VALUE(15.63), SIMDE_FLOAT16_VALUE(-26.25) },
       {  SIMDE_FLOAT16_VALUE(-46.48), SIMDE_FLOAT16_VALUE(13.65), SIMDE_FLOAT16_VALUE(3.92), SIMDE_FLOAT16_VALUE(39.42)},
     { {  SIMDE_FLOAT16_VALUE(33.12), SIMDE_FLOAT16_VALUE(33.12), SIMDE_FLOAT16_VALUE(33.12), SIMDE_FLOAT16_VALUE(33.12),
        SIMDE_FLOAT16_VALUE(33.12), SIMDE_FLOAT16_VALUE(33.12), SIMDE_FLOAT16_VALUE(33.12), SIMDE_FLOAT16_VALUE(33.12) },
       {  SIMDE_FLOAT16_VALUE(-27.38), SIMDE_FLOAT16_VALUE(-27.38), SIMDE_FLOAT16_VALUE(-27.38), SIMDE_FLOAT16_VALUE(-27.38),
        SIMDE_FLOAT16_VALUE(-27.38), SIMDE_FLOAT16_VALUE(-27.38), SIMDE_FLOAT16_VALUE(-27.38), SIMDE_FLOAT16_VALUE(-27.38) },
       {  SIMDE_FLOAT16_VALUE(15.63), SIMDE_FLOAT16_VALUE(15.63), SIMDE_FLOAT16_VALUE(15.63), SIMDE_FLOAT16_VALUE(15.63),
        SIMDE_FLOAT16_VALUE(15.63), SIMDE_FLOAT16_VALUE(15.63), SIMDE_FLOAT16_VALUE(15.63), SIMDE_FLOAT16_VALUE(15.63) },
       {  SIMDE_FLOAT16_VALUE(-26.25), SIMDE_FLOAT16_VALUE(-26.25), SIMDE_FLOAT16_VALUE(-26.25), SIMDE_FLOAT16_VALUE(-26.25),
        SIMDE_FLOAT16_VALUE(-26.25), SIMDE_FLOAT16_VALUE(-26.25), SIMDE_FLOAT16_VALUE(-26.25), SIMDE_FLOAT16_VALUE(-26.25) } } },
     { {  SIMDE_FLOAT16_VALUE(-9.54), SIMDE_FLOAT16_VALUE(-43.91), SIMDE_FLOAT16_VALUE(34.76), SIMDE_FLOAT16_VALUE(30.47) },
       {  SIMDE_FLOAT16_VALUE(44.27), SIMDE_FLOAT16_VALUE(45.27), SIMDE_FLOAT16_VALUE(47.81), SIMDE_FLOAT16_VALUE(10.39)},
     { {  SIMDE_FLOAT16_VALUE(-9.54), SIMDE_FLOAT16_VALUE(-9.54), SIMDE_FLOAT16_VALUE(-9.54), SIMDE_FLOAT16_VALUE(-9.54),
        SIMDE_FLOAT16_VALUE(-9.54), SIMDE_FLOAT16_VALUE(-9.54), SIMDE_FLOAT16_VALUE(-9.54), SIMDE_FLOAT16_VALUE(-9.54) },
       {  SIMDE_FLOAT16_VALUE(-43.91), SIMDE_FLOAT16_VALUE(-43.91), SIMDE_FLOAT16_VALUE(-43.91), SIMDE_FLOAT16_VALUE(-43.91),
        SIMDE_FLOAT16_VALUE(-43.91), SIMDE_FLOAT16_VALUE(-43.91), SIMDE_FLOAT16_VALUE(-43.91), SIMDE_FLOAT16_VALUE(-43.91) },
       {  SIMDE_FLOAT16_VALUE(34.76), SIMDE_FLOAT16_VALUE(34.76), SIMDE_FLOAT16_VALUE(34.76), SIMDE_FLOAT16_VALUE(34.76),
        SIMDE_FLOAT16_VALUE(34.76), SIMDE_FLOAT16_VALUE(34.76), SIMDE_FLOAT16_VALUE(34.76), SIMDE_FLOAT16_VALUE(34.76) },
       {  SIMDE_FLOAT16_VALUE(30.47), SIMDE_FLOAT16_VALUE(30.47), SIMDE_FLOAT16_VALUE(30.47), SIMDE_FLOAT16_VALUE(30.47),
        SIMDE_FLOAT16_VALUE(30.47), SIMDE_FLOAT16_VALUE(30.47), SIMDE_FLOAT16_VALUE(30.47), SIMDE_FLOAT16_VALUE(30.47) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8x4_t r = simde_vld4q_dup_f16(test_vec[i].a);
    simde_float16x8x4_t expected = {
        {simde_vld1q_f16(test_vec[i].r[0]), simde_vld1q_f16(test_vec[i].r[1]),
         simde_vld1q_f16(test_vec[i].r[2]), simde_vld1q_f16(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_f16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[2], expected.val[2], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[3], expected.val[3], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld4q_dup_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[4];
    float unused[4];
    float r[4][4];
  } test_vec[] = {
     { {  SIMDE_FLOAT32_C(-3861.60), SIMDE_FLOAT32_C(1139.29), SIMDE_FLOAT32_C(814.20), SIMDE_FLOAT32_C(3375.56) },
       {  SIMDE_FLOAT32_C(-150.56), SIMDE_FLOAT32_C(4160.55), SIMDE_FLOAT32_C(2937.14), SIMDE_FLOAT32_C(3001.41)},
     { {  SIMDE_FLOAT32_C(-3861.60), SIMDE_FLOAT32_C(-3861.60), SIMDE_FLOAT32_C(-3861.60), SIMDE_FLOAT32_C(-3861.60) },
       {  SIMDE_FLOAT32_C(1139.29), SIMDE_FLOAT32_C(1139.29), SIMDE_FLOAT32_C(1139.29), SIMDE_FLOAT32_C(1139.29) },
       {  SIMDE_FLOAT32_C(814.20), SIMDE_FLOAT32_C(814.20), SIMDE_FLOAT32_C(814.20), SIMDE_FLOAT32_C(814.20) },
       {  SIMDE_FLOAT32_C(3375.56), SIMDE_FLOAT32_C(3375.56), SIMDE_FLOAT32_C(3375.56), SIMDE_FLOAT32_C(3375.56) } } },
     { {  SIMDE_FLOAT32_C(805.49), SIMDE_FLOAT32_C(-4528.24), SIMDE_FLOAT32_C(3834.36), SIMDE_FLOAT32_C(57.43) },
       {  SIMDE_FLOAT32_C(-3865.32), SIMDE_FLOAT32_C(-2417.22), SIMDE_FLOAT32_C(1872.65), SIMDE_FLOAT32_C(4313.25)},
     { {  SIMDE_FLOAT32_C(805.49), SIMDE_FLOAT32_C(805.49), SIMDE_FLOAT32_C(805.49), SIMDE_FLOAT32_C(805.49) },
       {  SIMDE_FLOAT32_C(-4528.24), SIMDE_FLOAT32_C(-4528.24), SIMDE_FLOAT32_C(-4528.24), SIMDE_FLOAT32_C(-4528.24) },
       {  SIMDE_FLOAT32_C(3834.36), SIMDE_FLOAT32_C(3834.36), SIMDE_FLOAT32_C(3834.36), SIMDE_FLOAT32_C(3834.36) },
       {  SIMDE_FLOAT32_C(57.43), SIMDE_FLOAT32_C(57.43), SIMDE_FLOAT32_C(57.43), SIMDE_FLOAT32_C(57.43) } } },
     { {  SIMDE_FLOAT32_C(-2714.45), SIMDE_FLOAT32_C(496.22), SIMDE_FLOAT32_C(1544.09), SIMDE_FLOAT32_C(4179.89) },
       {  SIMDE_FLOAT32_C(3908.86), SIMDE_FLOAT32_C(-4458.82), SIMDE_FLOAT32_C(-4099.24), SIMDE_FLOAT32_C(3128.99)},
     { {  SIMDE_FLOAT32_C(-2714.45), SIMDE_FLOAT32_C(-2714.45), SIMDE_FLOAT32_C(-2714.45), SIMDE_FLOAT32_C(-2714.45) },
       {  SIMDE_FLOAT32_C(496.22), SIMDE_FLOAT32_C(496.22), SIMDE_FLOAT32_C(496.22), SIMDE_FLOAT32_C(496.22) },
       {  SIMDE_FLOAT32_C(1544.09), SIMDE_FLOAT32_C(1544.09), SIMDE_FLOAT32_C(1544.09), SIMDE_FLOAT32_C(1544.09) },
       {  SIMDE_FLOAT32_C(4179.89), SIMDE_FLOAT32_C(4179.89), SIMDE_FLOAT32_C(4179.89), SIMDE_FLOAT32_C(4179.89) } } },
     { {  SIMDE_FLOAT32_C(2851.07), SIMDE_FLOAT32_C(-1716.43), SIMDE_FLOAT32_C(-4967.83), SIMDE_FLOAT32_C(-2269.08) },
       {  SIMDE_FLOAT32_C(3455.94), SIMDE_FLOAT32_C(719.08), SIMDE_FLOAT32_C(-854.44), SIMDE_FLOAT32_C(2913.17)},
     { {  SIMDE_FLOAT32_C(2851.07), SIMDE_FLOAT32_C(2851.07), SIMDE_FLOAT32_C(2851.07), SIMDE_FLOAT32_C(2851.07) },
       {  SIMDE_FLOAT32_C(-1716.43), SIMDE_FLOAT32_C(-1716.43), SIMDE_FLOAT32_C(-1716.43), SIMDE_FLOAT32_C(-1716.43) },
       {  SIMDE_FLOAT32_C(-4967.83), SIMDE_FLOAT32_C(-4967.83), SIMDE_FLOAT32_C(-4967.83), SIMDE_FLOAT32_C(-4967.83) },
       {  SIMDE_FLOAT32_C(-2269.08), SIMDE_FLOAT32_C(-2269.08), SIMDE_FLOAT32_C(-2269.08), SIMDE_FLOAT32_C(-2269.08) } } },
     { {  SIMDE_FLOAT32_C(-3383.87), SIMDE_FLOAT32_C(-2809.13), SIMDE_FLOAT32_C(-2728.33), SIMDE_FLOAT32_C(-2481.28) },
       {  SIMDE_FLOAT32_C(2154.97), SIMDE_FLOAT32_C(2696.19), SIMDE_FLOAT32_C(-1729.45), SIMDE_FLOAT32_C(-4102.35)},
     { {  SIMDE_FLOAT32_C(-3383.87), SIMDE_FLOAT32_C(-3383.87), SIMDE_FLOAT32_C(-3383.87), SIMDE_FLOAT32_C(-3383.87) },
       {  SIMDE_FLOAT32_C(-2809.13), SIMDE_FLOAT32_C(-2809.13), SIMDE_FLOAT32_C(-2809.13), SIMDE_FLOAT32_C(-2809.13) },
       {  SIMDE_FLOAT32_C(-2728.33), SIMDE_FLOAT32_C(-2728.33), SIMDE_FLOAT32_C(-2728.33), SIMDE_FLOAT32_C(-2728.33) },
       {  SIMDE_FLOAT32_C(-2481.28), SIMDE_FLOAT32_C(-2481.28), SIMDE_FLOAT32_C(-2481.28), SIMDE_FLOAT32_C(-2481.28) } } },
     { {  SIMDE_FLOAT32_C(1690.98), SIMDE_FLOAT32_C(-2798.40), SIMDE_FLOAT32_C(2781.03), SIMDE_FLOAT32_C(-4301.72) },
       {  SIMDE_FLOAT32_C(3345.82), SIMDE_FLOAT32_C(-2334.78), SIMDE_FLOAT32_C(-2152.95), SIMDE_FLOAT32_C(4461.78)},
     { {  SIMDE_FLOAT32_C(1690.98), SIMDE_FLOAT32_C(1690.98), SIMDE_FLOAT32_C(1690.98), SIMDE_FLOAT32_C(1690.98) },
       {  SIMDE_FLOAT32_C(-2798.40), SIMDE_FLOAT32_C(-2798.40), SIMDE_FLOAT32_C(-2798.40), SIMDE_FLOAT32_C(-2798.40) },
       {  SIMDE_FLOAT32_C(2781.03), SIMDE_FLOAT32_C(2781.03), SIMDE_FLOAT32_C(2781.03), SIMDE_FLOAT32_C(2781.03) },
       {  SIMDE_FLOAT32_C(-4301.72), SIMDE_FLOAT32_C(-4301.72), SIMDE_FLOAT32_C(-4301.72), SIMDE_FLOAT32_C(-4301.72) } } },
     { {  SIMDE_FLOAT32_C(3849.23), SIMDE_FLOAT32_C(-2373.31), SIMDE_FLOAT32_C(-2655.60), SIMDE_FLOAT32_C(-4271.80) },
       {  SIMDE_FLOAT32_C(-1886.25), SIMDE_FLOAT32_C(-3798.07), SIMDE_FLOAT32_C(98.28), SIMDE_FLOAT32_C(-4138.60)},
     { {  SIMDE_FLOAT32_C(3849.23), SIMDE_FLOAT32_C(3849.23), SIMDE_FLOAT32_C(3849.23), SIMDE_FLOAT32_C(3849.23) },
       {  SIMDE_FLOAT32_C(-2373.31), SIMDE_FLOAT32_C(-2373.31), SIMDE_FLOAT32_C(-2373.31), SIMDE_FLOAT32_C(-2373.31) },
       {  SIMDE_FLOAT32_C(-2655.60), SIMDE_FLOAT32_C(-2655.60), SIMDE_FLOAT32_C(-2655.60), SIMDE_FLOAT32_C(-2655.60) },
       {  SIMDE_FLOAT32_C(-4271.80), SIMDE_FLOAT32_C(-4271.80), SIMDE_FLOAT32_C(-4271.80), SIMDE_FLOAT32_C(-4271.80) } } },
     { {  SIMDE_FLOAT32_C(3103.14), SIMDE_FLOAT32_C(188.95), SIMDE_FLOAT32_C(730.17), SIMDE_FLOAT32_C(4115.93) },
       {  SIMDE_FLOAT32_C(270.70), SIMDE_FLOAT32_C(260.43), SIMDE_FLOAT32_C(-1629.46), SIMDE_FLOAT32_C(1068.15)},
     { {  SIMDE_FLOAT32_C(3103.14), SIMDE_FLOAT32_C(3103.14), SIMDE_FLOAT32_C(3103.14), SIMDE_FLOAT32_C(3103.14) },
       {  SIMDE_FLOAT32_C(188.95), SIMDE_FLOAT32_C(188.95), SIMDE_FLOAT32_C(188.95), SIMDE_FLOAT32_C(188.95) },
       {  SIMDE_FLOAT32_C(730.17), SIMDE_FLOAT32_C(730.17), SIMDE_FLOAT32_C(730.17), SIMDE_FLOAT32_C(730.17) },
       {  SIMDE_FLOAT32_C(4115.93), SIMDE_FLOAT32_C(4115.93), SIMDE_FLOAT32_C(4115.93), SIMDE_FLOAT32_C(4115.93) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x4_t r = simde_vld4q_dup_f32(test_vec[i].a);
    simde_float32x4x4_t expected = {
        {simde_vld1q_f32(test_vec[i].r[0]), simde_vld1q_f32(test_vec[i].r[1]),
         simde_vld1q_f32(test_vec[i].r[2]), simde_vld1q_f32(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_f32x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[2], expected.val[2], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[3], expected.val[3], INT_MAX);
  }

  return 0;
}


static int
test_simde_vld4q_dup_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[4];
    simde_float64 unused[4];
    simde_float64 r[4][2];
  } test_vec[] = {
     { {  SIMDE_FLOAT64_C(301939.25), SIMDE_FLOAT64_C(31180.53), SIMDE_FLOAT64_C(328514.37), SIMDE_FLOAT64_C(-403632.52) },
       {  SIMDE_FLOAT64_C(228223.39), SIMDE_FLOAT64_C(65131.77), SIMDE_FLOAT64_C(-234702.56), SIMDE_FLOAT64_C(164177.40)},
     { {  SIMDE_FLOAT64_C(301939.25), SIMDE_FLOAT64_C(301939.25) },
       {  SIMDE_FLOAT64_C(31180.53), SIMDE_FLOAT64_C(31180.53) },
       {  SIMDE_FLOAT64_C(328514.37), SIMDE_FLOAT64_C(328514.37) },
       {  SIMDE_FLOAT64_C(-403632.52), SIMDE_FLOAT64_C(-403632.52) } } },
     { {  SIMDE_FLOAT64_C(56986.01), SIMDE_FLOAT64_C(283724.36), SIMDE_FLOAT64_C(155364.01), SIMDE_FLOAT64_C(-415889.92) },
       {  SIMDE_FLOAT64_C(-414762.25), SIMDE_FLOAT64_C(-93809.32), SIMDE_FLOAT64_C(28559.25), SIMDE_FLOAT64_C(-291618.76)},
     { {  SIMDE_FLOAT64_C(56986.01), SIMDE_FLOAT64_C(56986.01) },
       {  SIMDE_FLOAT64_C(283724.36), SIMDE_FLOAT64_C(283724.36) },
       {  SIMDE_FLOAT64_C(155364.01), SIMDE_FLOAT64_C(155364.01) },
       {  SIMDE_FLOAT64_C(-415889.92), SIMDE_FLOAT64_C(-415889.92) } } },
     { {  SIMDE_FLOAT64_C(-284581.10), SIMDE_FLOAT64_C(50140.85), SIMDE_FLOAT64_C(136310.26), SIMDE_FLOAT64_C(448266.40) },
       {  SIMDE_FLOAT64_C(266934.08), SIMDE_FLOAT64_C(207025.51), SIMDE_FLOAT64_C(-32860.95), SIMDE_FLOAT64_C(-59684.94)},
     { {  SIMDE_FLOAT64_C(-284581.10), SIMDE_FLOAT64_C(-284581.10) },
       {  SIMDE_FLOAT64_C(50140.85), SIMDE_FLOAT64_C(50140.85) },
       {  SIMDE_FLOAT64_C(136310.26), SIMDE_FLOAT64_C(136310.26) },
       {  SIMDE_FLOAT64_C(448266.40), SIMDE_FLOAT64_C(448266.40) } } },
     { {  SIMDE_FLOAT64_C(-405893.56), SIMDE_FLOAT64_C(259839.71), SIMDE_FLOAT64_C(422741.48), SIMDE_FLOAT64_C(-225178.67) },
       {  SIMDE_FLOAT64_C(-127457.76), SIMDE_FLOAT64_C(-23597.33), SIMDE_FLOAT64_C(372570.03), SIMDE_FLOAT64_C(-368106.17)},
     { {  SIMDE_FLOAT64_C(-405893.56), SIMDE_FLOAT64_C(-405893.56) },
       {  SIMDE_FLOAT64_C(259839.71), SIMDE_FLOAT64_C(259839.71) },
       {  SIMDE_FLOAT64_C(422741.48), SIMDE_FLOAT64_C(422741.48) },
       {  SIMDE_FLOAT64_C(-225178.67), SIMDE_FLOAT64_C(-225178.67) } } },
     { {  SIMDE_FLOAT64_C(29202.40), SIMDE_FLOAT64_C(-476185.70), SIMDE_FLOAT64_C(350122.87), SIMDE_FLOAT64_C(440133.57) },
       {  SIMDE_FLOAT64_C(-333398.19), SIMDE_FLOAT64_C(-420427.97), SIMDE_FLOAT64_C(124909.95), SIMDE_FLOAT64_C(364853.02)},
     { {  SIMDE_FLOAT64_C(29202.40), SIMDE_FLOAT64_C(29202.40) },
       {  SIMDE_FLOAT64_C(-476185.70), SIMDE_FLOAT64_C(-476185.70) },
       {  SIMDE_FLOAT64_C(350122.87), SIMDE_FLOAT64_C(350122.87) },
       {  SIMDE_FLOAT64_C(440133.57), SIMDE_FLOAT64_C(440133.57) } } },
     { {  SIMDE_FLOAT64_C(281268.20), SIMDE_FLOAT64_C(-21602.25), SIMDE_FLOAT64_C(64507.47), SIMDE_FLOAT64_C(365563.55) },
       {  SIMDE_FLOAT64_C(270302.58), SIMDE_FLOAT64_C(-156251.88), SIMDE_FLOAT64_C(164546.89), SIMDE_FLOAT64_C(-173037.65)},
     { {  SIMDE_FLOAT64_C(281268.20), SIMDE_FLOAT64_C(281268.20) },
       {  SIMDE_FLOAT64_C(-21602.25), SIMDE_FLOAT64_C(-21602.25) },
       {  SIMDE_FLOAT64_C(64507.47), SIMDE_FLOAT64_C(64507.47) },
       {  SIMDE_FLOAT64_C(365563.55), SIMDE_FLOAT64_C(365563.55) } } },
     { {  SIMDE_FLOAT64_C(236563.73), SIMDE_FLOAT64_C(298156.49), SIMDE_FLOAT64_C(-463451.58), SIMDE_FLOAT64_C(246608.44) },
       {  SIMDE_FLOAT64_C(-217371.80), SIMDE_FLOAT64_C(113655.63), SIMDE_FLOAT64_C(402255.30), SIMDE_FLOAT64_C(449192.11)},
     { {  SIMDE_FLOAT64_C(236563.73), SIMDE_FLOAT64_C(236563.73) },
       {  SIMDE_FLOAT64_C(298156.49), SIMDE_FLOAT64_C(298156.49) },
       {  SIMDE_FLOAT64_C(-463451.58), SIMDE_FLOAT64_C(-463451.58) },
       {  SIMDE_FLOAT64_C(246608.44), SIMDE_FLOAT64_C(246608.44) } } },
     { {  SIMDE_FLOAT64_C(-389102.28), SIMDE_FLOAT64_C(228365.87), SIMDE_FLOAT64_C(81756.79), SIMDE_FLOAT64_C(-398903.35) },
       {  SIMDE_FLOAT64_C(492074.05), SIMDE_FLOAT64_C(471641.95), SIMDE_FLOAT64_C(-224322.91), SIMDE_FLOAT64_C(498142.32)},
     { {  SIMDE_FLOAT64_C(-389102.28), SIMDE_FLOAT64_C(-389102.28) },
       {  SIMDE_FLOAT64_C(228365.87), SIMDE_FLOAT64_C(228365.87) },
       {  SIMDE_FLOAT64_C(81756.79), SIMDE_FLOAT64_C(81756.79) },
       {  SIMDE_FLOAT64_C(-398903.35), SIMDE_FLOAT64_C(-398903.35) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x4_t r = simde_vld4q_dup_f64(test_vec[i].a);
    simde_float64x2x4_t expected = {
        {simde_vld1q_f64(test_vec[i].r[0]), simde_vld1q_f64(test_vec[i].r[1]),
         simde_vld1q_f64(test_vec[i].r[2]), simde_vld1q_f64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_f64x2(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r.val[2], expected.val[2], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r.val[3], expected.val[3], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld4q_dup_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[4];
    int8_t unused[4];
    int8_t r[4][16];
  } test_vec[] = {
     { {  INT8_C(17), -INT8_C(53), INT8_C(76), INT8_C(86) },
       {  INT8_C(72), -INT8_C(98), INT8_C(32), -INT8_C(67)},
     { {  INT8_C(17), INT8_C(17), INT8_C(17), INT8_C(17), INT8_C(17), INT8_C(17), INT8_C(17), INT8_C(17),
        INT8_C(17), INT8_C(17), INT8_C(17), INT8_C(17), INT8_C(17), INT8_C(17), INT8_C(17), INT8_C(17) },
       {  -INT8_C(53), -INT8_C(53), -INT8_C(53), -INT8_C(53), -INT8_C(53), -INT8_C(53), -INT8_C(53), -INT8_C(53),
        -INT8_C(53), -INT8_C(53), -INT8_C(53), -INT8_C(53), -INT8_C(53), -INT8_C(53), -INT8_C(53), -INT8_C(53) },
       {  INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76),
        INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76), INT8_C(76) },
       {  INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86),
        INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86) } } },
     { {  -INT8_C(42), INT8_C(69), INT8_C(0), -INT8_C(20) },
       {  INT8_C(2), INT8_C(22), INT8_C(50), INT8_C(81)},
     { {  -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42),
        -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42) },
       {  INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69),
        INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69) },
       {  INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0),
        INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0) },
       {  -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20),
        -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20) } } },
     { {  INT8_C(81), -INT8_C(85), INT8_C(69), INT8_C(85) },
       {  -INT8_C(25), INT8_C(84), -INT8_C(85), -INT8_C(82)},
     { {  INT8_C(81), INT8_C(81), INT8_C(81), INT8_C(81), INT8_C(81), INT8_C(81), INT8_C(81), INT8_C(81),
        INT8_C(81), INT8_C(81), INT8_C(81), INT8_C(81), INT8_C(81), INT8_C(81), INT8_C(81), INT8_C(81) },
       {  -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85),
        -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85) },
       {  INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69),
        INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69), INT8_C(69) },
       {  INT8_C(85), INT8_C(85), INT8_C(85), INT8_C(85), INT8_C(85), INT8_C(85), INT8_C(85), INT8_C(85),
        INT8_C(85), INT8_C(85), INT8_C(85), INT8_C(85), INT8_C(85), INT8_C(85), INT8_C(85), INT8_C(85) } } },
     { {  INT8_C(96), -INT8_C(82), -INT8_C(62), -INT8_C(37) },
       {  INT8_C(42), -INT8_C(5), INT8_C(6), INT8_C(64)},
     { {  INT8_C(96), INT8_C(96), INT8_C(96), INT8_C(96), INT8_C(96), INT8_C(96), INT8_C(96), INT8_C(96),
        INT8_C(96), INT8_C(96), INT8_C(96), INT8_C(96), INT8_C(96), INT8_C(96), INT8_C(96), INT8_C(96) },
       {  -INT8_C(82), -INT8_C(82), -INT8_C(82), -INT8_C(82), -INT8_C(82), -INT8_C(82), -INT8_C(82), -INT8_C(82),
        -INT8_C(82), -INT8_C(82), -INT8_C(82), -INT8_C(82), -INT8_C(82), -INT8_C(82), -INT8_C(82), -INT8_C(82) },
       {  -INT8_C(62), -INT8_C(62), -INT8_C(62), -INT8_C(62), -INT8_C(62), -INT8_C(62), -INT8_C(62), -INT8_C(62),
        -INT8_C(62), -INT8_C(62), -INT8_C(62), -INT8_C(62), -INT8_C(62), -INT8_C(62), -INT8_C(62), -INT8_C(62) },
       {  -INT8_C(37), -INT8_C(37), -INT8_C(37), -INT8_C(37), -INT8_C(37), -INT8_C(37), -INT8_C(37), -INT8_C(37),
        -INT8_C(37), -INT8_C(37), -INT8_C(37), -INT8_C(37), -INT8_C(37), -INT8_C(37), -INT8_C(37), -INT8_C(37) } } },
     { {  INT8_C(97), INT8_C(10), INT8_C(98), -INT8_C(6) },
       {  INT8_C(48), INT8_C(21), INT8_C(54), INT8_C(91)},
     { {  INT8_C(97), INT8_C(97), INT8_C(97), INT8_C(97), INT8_C(97), INT8_C(97), INT8_C(97), INT8_C(97),
        INT8_C(97), INT8_C(97), INT8_C(97), INT8_C(97), INT8_C(97), INT8_C(97), INT8_C(97), INT8_C(97) },
       {  INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10),
        INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10) },
       {  INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98),
        INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98) },
       {  -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6),
        -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6) } } },
     { {  -INT8_C(59), -INT8_C(78), -INT8_C(32), -INT8_C(77) },
       {  -INT8_C(6), INT8_C(20), -INT8_C(70), INT8_C(62)},
     { {  -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59),
        -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59) },
       {  -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78),
        -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78) },
       {  -INT8_C(32), -INT8_C(32), -INT8_C(32), -INT8_C(32), -INT8_C(32), -INT8_C(32), -INT8_C(32), -INT8_C(32),
        -INT8_C(32), -INT8_C(32), -INT8_C(32), -INT8_C(32), -INT8_C(32), -INT8_C(32), -INT8_C(32), -INT8_C(32) },
       {  -INT8_C(77), -INT8_C(77), -INT8_C(77), -INT8_C(77), -INT8_C(77), -INT8_C(77), -INT8_C(77), -INT8_C(77),
        -INT8_C(77), -INT8_C(77), -INT8_C(77), -INT8_C(77), -INT8_C(77), -INT8_C(77), -INT8_C(77), -INT8_C(77) } } },
     { {  INT8_C(73), -INT8_C(34), INT8_C(91), INT8_C(29) },
       {  INT8_C(72), -INT8_C(56), INT8_C(92), INT8_C(43)},
     { {  INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73),
        INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73) },
       {  -INT8_C(34), -INT8_C(34), -INT8_C(34), -INT8_C(34), -INT8_C(34), -INT8_C(34), -INT8_C(34), -INT8_C(34),
        -INT8_C(34), -INT8_C(34), -INT8_C(34), -INT8_C(34), -INT8_C(34), -INT8_C(34), -INT8_C(34), -INT8_C(34) },
       {  INT8_C(91), INT8_C(91), INT8_C(91), INT8_C(91), INT8_C(91), INT8_C(91), INT8_C(91), INT8_C(91),
        INT8_C(91), INT8_C(91), INT8_C(91), INT8_C(91), INT8_C(91), INT8_C(91), INT8_C(91), INT8_C(91) },
       {  INT8_C(29), INT8_C(29), INT8_C(29), INT8_C(29), INT8_C(29), INT8_C(29), INT8_C(29), INT8_C(29),
        INT8_C(29), INT8_C(29), INT8_C(29), INT8_C(29), INT8_C(29), INT8_C(29), INT8_C(29), INT8_C(29) } } },
     { {  INT8_C(57), -INT8_C(74), INT8_C(59), INT8_C(19) },
       {  INT8_C(85), INT8_C(21), INT8_C(92), INT8_C(11)},
     { {  INT8_C(57), INT8_C(57), INT8_C(57), INT8_C(57), INT8_C(57), INT8_C(57), INT8_C(57), INT8_C(57),
        INT8_C(57), INT8_C(57), INT8_C(57), INT8_C(57), INT8_C(57), INT8_C(57), INT8_C(57), INT8_C(57) },
       {  -INT8_C(74), -INT8_C(74), -INT8_C(74), -INT8_C(74), -INT8_C(74), -INT8_C(74), -INT8_C(74), -INT8_C(74),
        -INT8_C(74), -INT8_C(74), -INT8_C(74), -INT8_C(74), -INT8_C(74), -INT8_C(74), -INT8_C(74), -INT8_C(74) },
       {  INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59),
        INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59), INT8_C(59) },
       {  INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19),
        INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x4_t r = simde_vld4q_dup_s8(test_vec[i].a);
    simde_int8x16x4_t expected = {
        {simde_vld1q_s8(test_vec[i].r[0]), simde_vld1q_s8(test_vec[i].r[1]),
         simde_vld1q_s8(test_vec[i].r[2]), simde_vld1q_s8(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_i8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4q_dup_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    int16_t unused[4];
    int16_t r[4][8];
  } test_vec[] = {
     { {  -INT16_C(1310), -INT16_C(2011), -INT16_C(5610), INT16_C(5601) },
       {  -INT16_C(8476), -INT16_C(8186), -INT16_C(3033), INT16_C(4031)},
     { {  -INT16_C(1310), -INT16_C(1310), -INT16_C(1310), -INT16_C(1310),
        -INT16_C(1310), -INT16_C(1310), -INT16_C(1310), -INT16_C(1310) },
       {  -INT16_C(2011), -INT16_C(2011), -INT16_C(2011), -INT16_C(2011),
        -INT16_C(2011), -INT16_C(2011), -INT16_C(2011), -INT16_C(2011) },
       {  -INT16_C(5610), -INT16_C(5610), -INT16_C(5610), -INT16_C(5610),
        -INT16_C(5610), -INT16_C(5610), -INT16_C(5610), -INT16_C(5610) },
       {  INT16_C(5601), INT16_C(5601), INT16_C(5601), INT16_C(5601),
        INT16_C(5601), INT16_C(5601), INT16_C(5601), INT16_C(5601) } } },
     { {  INT16_C(8148), INT16_C(2754), INT16_C(8342), -INT16_C(1139) },
       {  -INT16_C(5489), INT16_C(6809), -INT16_C(2547), -INT16_C(3550)},
     { {  INT16_C(8148), INT16_C(8148), INT16_C(8148), INT16_C(8148),
        INT16_C(8148), INT16_C(8148), INT16_C(8148), INT16_C(8148) },
       {  INT16_C(2754), INT16_C(2754), INT16_C(2754), INT16_C(2754),
        INT16_C(2754), INT16_C(2754), INT16_C(2754), INT16_C(2754) },
       {  INT16_C(8342), INT16_C(8342), INT16_C(8342), INT16_C(8342),
        INT16_C(8342), INT16_C(8342), INT16_C(8342), INT16_C(8342) },
       {  -INT16_C(1139), -INT16_C(1139), -INT16_C(1139), -INT16_C(1139),
        -INT16_C(1139), -INT16_C(1139), -INT16_C(1139), -INT16_C(1139) } } },
     { {  -INT16_C(3232), INT16_C(1913), INT16_C(1602), INT16_C(8369) },
       {  -INT16_C(6047), -INT16_C(2404), -INT16_C(7005), -INT16_C(7266)},
     { {  -INT16_C(3232), -INT16_C(3232), -INT16_C(3232), -INT16_C(3232),
        -INT16_C(3232), -INT16_C(3232), -INT16_C(3232), -INT16_C(3232) },
       {  INT16_C(1913), INT16_C(1913), INT16_C(1913), INT16_C(1913),
        INT16_C(1913), INT16_C(1913), INT16_C(1913), INT16_C(1913) },
       {  INT16_C(1602), INT16_C(1602), INT16_C(1602), INT16_C(1602),
        INT16_C(1602), INT16_C(1602), INT16_C(1602), INT16_C(1602) },
       {  INT16_C(8369), INT16_C(8369), INT16_C(8369), INT16_C(8369),
        INT16_C(8369), INT16_C(8369), INT16_C(8369), INT16_C(8369) } } },
     { {  INT16_C(6692), INT16_C(9283), -INT16_C(9852), -INT16_C(2207) },
       {  INT16_C(8934), INT16_C(8583), -INT16_C(3148), -INT16_C(2677)},
     { {  INT16_C(6692), INT16_C(6692), INT16_C(6692), INT16_C(6692),
        INT16_C(6692), INT16_C(6692), INT16_C(6692), INT16_C(6692) },
       {  INT16_C(9283), INT16_C(9283), INT16_C(9283), INT16_C(9283),
        INT16_C(9283), INT16_C(9283), INT16_C(9283), INT16_C(9283) },
       {  -INT16_C(9852), -INT16_C(9852), -INT16_C(9852), -INT16_C(9852),
        -INT16_C(9852), -INT16_C(9852), -INT16_C(9852), -INT16_C(9852) },
       {  -INT16_C(2207), -INT16_C(2207), -INT16_C(2207), -INT16_C(2207),
        -INT16_C(2207), -INT16_C(2207), -INT16_C(2207), -INT16_C(2207) } } },
     { {  INT16_C(5481), -INT16_C(8270), INT16_C(5603), INT16_C(8130) },
       {  -INT16_C(594), -INT16_C(9174), INT16_C(2942), INT16_C(9649)},
     { {  INT16_C(5481), INT16_C(5481), INT16_C(5481), INT16_C(5481),
        INT16_C(5481), INT16_C(5481), INT16_C(5481), INT16_C(5481) },
       {  -INT16_C(8270), -INT16_C(8270), -INT16_C(8270), -INT16_C(8270),
        -INT16_C(8270), -INT16_C(8270), -INT16_C(8270), -INT16_C(8270) },
       {  INT16_C(5603), INT16_C(5603), INT16_C(5603), INT16_C(5603),
        INT16_C(5603), INT16_C(5603), INT16_C(5603), INT16_C(5603) },
       {  INT16_C(8130), INT16_C(8130), INT16_C(8130), INT16_C(8130),
        INT16_C(8130), INT16_C(8130), INT16_C(8130), INT16_C(8130) } } },
     { {  INT16_C(2622), INT16_C(658), INT16_C(85), INT16_C(5386) },
       {  INT16_C(4188), -INT16_C(8037), -INT16_C(2112), INT16_C(1973)},
     { {  INT16_C(2622), INT16_C(2622), INT16_C(2622), INT16_C(2622),
        INT16_C(2622), INT16_C(2622), INT16_C(2622), INT16_C(2622) },
       {  INT16_C(658), INT16_C(658), INT16_C(658), INT16_C(658),
        INT16_C(658), INT16_C(658), INT16_C(658), INT16_C(658) },
       {  INT16_C(85), INT16_C(85), INT16_C(85), INT16_C(85),
        INT16_C(85), INT16_C(85), INT16_C(85), INT16_C(85) },
       {  INT16_C(5386), INT16_C(5386), INT16_C(5386), INT16_C(5386),
        INT16_C(5386), INT16_C(5386), INT16_C(5386), INT16_C(5386) } } },
     { {  -INT16_C(2202), -INT16_C(6550), -INT16_C(1489), INT16_C(9813) },
       {  -INT16_C(9394), -INT16_C(9999), -INT16_C(116), -INT16_C(1583)},
     { {  -INT16_C(2202), -INT16_C(2202), -INT16_C(2202), -INT16_C(2202),
        -INT16_C(2202), -INT16_C(2202), -INT16_C(2202), -INT16_C(2202) },
       {  -INT16_C(6550), -INT16_C(6550), -INT16_C(6550), -INT16_C(6550),
        -INT16_C(6550), -INT16_C(6550), -INT16_C(6550), -INT16_C(6550) },
       {  -INT16_C(1489), -INT16_C(1489), -INT16_C(1489), -INT16_C(1489),
        -INT16_C(1489), -INT16_C(1489), -INT16_C(1489), -INT16_C(1489) },
       {  INT16_C(9813), INT16_C(9813), INT16_C(9813), INT16_C(9813),
        INT16_C(9813), INT16_C(9813), INT16_C(9813), INT16_C(9813) } } },
     { {  INT16_C(1789), INT16_C(3725), -INT16_C(5614), -INT16_C(177) },
       {  INT16_C(7432), INT16_C(3078), INT16_C(1340), INT16_C(5203)},
     { {  INT16_C(1789), INT16_C(1789), INT16_C(1789), INT16_C(1789),
        INT16_C(1789), INT16_C(1789), INT16_C(1789), INT16_C(1789) },
       {  INT16_C(3725), INT16_C(3725), INT16_C(3725), INT16_C(3725),
        INT16_C(3725), INT16_C(3725), INT16_C(3725), INT16_C(3725) },
       {  -INT16_C(5614), -INT16_C(5614), -INT16_C(5614), -INT16_C(5614),
        -INT16_C(5614), -INT16_C(5614), -INT16_C(5614), -INT16_C(5614) },
       {  -INT16_C(177), -INT16_C(177), -INT16_C(177), -INT16_C(177),
        -INT16_C(177), -INT16_C(177), -INT16_C(177), -INT16_C(177) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x4_t r = simde_vld4q_dup_s16(test_vec[i].a);
    simde_int16x8x4_t expected = {
        {simde_vld1q_s16(test_vec[i].r[0]), simde_vld1q_s16(test_vec[i].r[1]),
         simde_vld1q_s16(test_vec[i].r[2]), simde_vld1q_s16(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_i16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4q_dup_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t unused[4];
    int32_t r[4][4];
  } test_vec[] = {
     { {  INT32_C(96036), INT32_C(276706), -INT32_C(576383), INT32_C(787308) },
       {  -INT32_C(917425), -INT32_C(795228), -INT32_C(300239), -INT32_C(520199)},
     { {  INT32_C(96036), INT32_C(96036), INT32_C(96036), INT32_C(96036) },
       {  INT32_C(276706), INT32_C(276706), INT32_C(276706), INT32_C(276706) },
       {  -INT32_C(576383), -INT32_C(576383), -INT32_C(576383), -INT32_C(576383) },
       {  INT32_C(787308), INT32_C(787308), INT32_C(787308), INT32_C(787308) } } },
     { {  INT32_C(197220), -INT32_C(589269), -INT32_C(684313), -INT32_C(673963) },
       {  -INT32_C(626857), -INT32_C(238551), -INT32_C(117726), -INT32_C(575676)},
     { {  INT32_C(197220), INT32_C(197220), INT32_C(197220), INT32_C(197220) },
       {  -INT32_C(589269), -INT32_C(589269), -INT32_C(589269), -INT32_C(589269) },
       {  -INT32_C(684313), -INT32_C(684313), -INT32_C(684313), -INT32_C(684313) },
       {  -INT32_C(673963), -INT32_C(673963), -INT32_C(673963), -INT32_C(673963) } } },
     { {  INT32_C(925544), INT32_C(818928), INT32_C(78068), -INT32_C(500546) },
       {  INT32_C(721350), INT32_C(786469), -INT32_C(61037), -INT32_C(414620)},
     { {  INT32_C(925544), INT32_C(925544), INT32_C(925544), INT32_C(925544) },
       {  INT32_C(818928), INT32_C(818928), INT32_C(818928), INT32_C(818928) },
       {  INT32_C(78068), INT32_C(78068), INT32_C(78068), INT32_C(78068) },
       {  -INT32_C(500546), -INT32_C(500546), -INT32_C(500546), -INT32_C(500546) } } },
     { {  -INT32_C(852696), -INT32_C(319929), -INT32_C(18615), -INT32_C(820282) },
       {  -INT32_C(669753), -INT32_C(107857), -INT32_C(923798), -INT32_C(894016)},
     { {  -INT32_C(852696), -INT32_C(852696), -INT32_C(852696), -INT32_C(852696) },
       {  -INT32_C(319929), -INT32_C(319929), -INT32_C(319929), -INT32_C(319929) },
       {  -INT32_C(18615), -INT32_C(18615), -INT32_C(18615), -INT32_C(18615) },
       {  -INT32_C(820282), -INT32_C(820282), -INT32_C(820282), -INT32_C(820282) } } },
     { {  -INT32_C(28238), -INT32_C(717470), INT32_C(330287), -INT32_C(918323) },
       {  -INT32_C(572545), INT32_C(541080), -INT32_C(285996), -INT32_C(731588)},
     { {  -INT32_C(28238), -INT32_C(28238), -INT32_C(28238), -INT32_C(28238) },
       {  -INT32_C(717470), -INT32_C(717470), -INT32_C(717470), -INT32_C(717470) },
       {  INT32_C(330287), INT32_C(330287), INT32_C(330287), INT32_C(330287) },
       {  -INT32_C(918323), -INT32_C(918323), -INT32_C(918323), -INT32_C(918323) } } },
     { {  INT32_C(304604), INT32_C(749469), -INT32_C(843860), INT32_C(236450) },
       {  -INT32_C(751345), INT32_C(386071), INT32_C(252136), INT32_C(758287)},
     { {  INT32_C(304604), INT32_C(304604), INT32_C(304604), INT32_C(304604) },
       {  INT32_C(749469), INT32_C(749469), INT32_C(749469), INT32_C(749469) },
       {  -INT32_C(843860), -INT32_C(843860), -INT32_C(843860), -INT32_C(843860) },
       {  INT32_C(236450), INT32_C(236450), INT32_C(236450), INT32_C(236450) } } },
     { {  INT32_C(641773), INT32_C(790736), -INT32_C(2616), INT32_C(175478) },
       {  INT32_C(363459), -INT32_C(479556), -INT32_C(939682), -INT32_C(215811)},
     { {  INT32_C(641773), INT32_C(641773), INT32_C(641773), INT32_C(641773) },
       {  INT32_C(790736), INT32_C(790736), INT32_C(790736), INT32_C(790736) },
       {  -INT32_C(2616), -INT32_C(2616), -INT32_C(2616), -INT32_C(2616) },
       {  INT32_C(175478), INT32_C(175478), INT32_C(175478), INT32_C(175478) } } },
     { {  INT32_C(909638), INT32_C(191353), INT32_C(158729), INT32_C(1951) },
       {  INT32_C(269992), -INT32_C(166368), INT32_C(437900), -INT32_C(328553)},
     { {  INT32_C(909638), INT32_C(909638), INT32_C(909638), INT32_C(909638) },
       {  INT32_C(191353), INT32_C(191353), INT32_C(191353), INT32_C(191353) },
       {  INT32_C(158729), INT32_C(158729), INT32_C(158729), INT32_C(158729) },
       {  INT32_C(1951), INT32_C(1951), INT32_C(1951), INT32_C(1951) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x4_t r = simde_vld4q_dup_s32(test_vec[i].a);
    simde_int32x4x4_t expected = {
        {simde_vld1q_s32(test_vec[i].r[0]), simde_vld1q_s32(test_vec[i].r[1]),
         simde_vld1q_s32(test_vec[i].r[2]), simde_vld1q_s32(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_i32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4q_dup_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[4];
    int64_t unused[4];
    int64_t r[4][2];
  } test_vec[] = {
     { {  -INT64_C(33824478), -INT64_C(5187232), INT64_C(39515006), -INT64_C(80914792) },
       {  INT64_C(93726945), -INT64_C(25808930), INT64_C(63257430), INT64_C(30498672)},
     { {  -INT64_C(33824478), -INT64_C(33824478) },
       {  -INT64_C(5187232), -INT64_C(5187232) },
       {  INT64_C(39515006), INT64_C(39515006) },
       {  -INT64_C(80914792), -INT64_C(80914792) } } },
     { {  INT64_C(79009808), INT64_C(23479431), INT64_C(7280288), -INT64_C(4073394) },
       {  INT64_C(91088968), -INT64_C(57443644), -INT64_C(67527816), -INT64_C(27085279)},
     { {  INT64_C(79009808), INT64_C(79009808) },
       {  INT64_C(23479431), INT64_C(23479431) },
       {  INT64_C(7280288), INT64_C(7280288) },
       {  -INT64_C(4073394), -INT64_C(4073394) } } },
     { {  INT64_C(47560098), -INT64_C(42568172), -INT64_C(84940253), -INT64_C(13762228) },
       {  INT64_C(51818022), INT64_C(64955838), INT64_C(72970264), INT64_C(15597298)},
     { {  INT64_C(47560098), INT64_C(47560098) },
       {  -INT64_C(42568172), -INT64_C(42568172) },
       {  -INT64_C(84940253), -INT64_C(84940253) },
       {  -INT64_C(13762228), -INT64_C(13762228) } } },
     { {  -INT64_C(94228216), INT64_C(86016311), INT64_C(44715658), INT64_C(98567682) },
       {  -INT64_C(48698288), INT64_C(40924262), -INT64_C(71124922), INT64_C(97823707)},
     { {  -INT64_C(94228216), -INT64_C(94228216) },
       {  INT64_C(86016311), INT64_C(86016311) },
       {  INT64_C(44715658), INT64_C(44715658) },
       {  INT64_C(98567682), INT64_C(98567682) } } },
     { {  -INT64_C(23294763), -INT64_C(18329751), INT64_C(202119), -INT64_C(93023835) },
       {  -INT64_C(72529621), -INT64_C(2617545), -INT64_C(51382967), -INT64_C(19480654)},
     { {  -INT64_C(23294763), -INT64_C(23294763) },
       {  -INT64_C(18329751), -INT64_C(18329751) },
       {  INT64_C(202119), INT64_C(202119) },
       {  -INT64_C(93023835), -INT64_C(93023835) } } },
     { {  -INT64_C(74212734), -INT64_C(67029147), -INT64_C(98945421), -INT64_C(45976698) },
       {  -INT64_C(24390280), INT64_C(90621403), INT64_C(71367745), INT64_C(89478676)},
     { {  -INT64_C(74212734), -INT64_C(74212734) },
       {  -INT64_C(67029147), -INT64_C(67029147) },
       {  -INT64_C(98945421), -INT64_C(98945421) },
       {  -INT64_C(45976698), -INT64_C(45976698) } } },
     { {  INT64_C(19216507), INT64_C(87031207), -INT64_C(92732196), INT64_C(17901903) },
       {  -INT64_C(63712817), -INT64_C(52596459), -INT64_C(56846456), INT64_C(83839716)},
     { {  INT64_C(19216507), INT64_C(19216507) },
       {  INT64_C(87031207), INT64_C(87031207) },
       {  -INT64_C(92732196), -INT64_C(92732196) },
       {  INT64_C(17901903), INT64_C(17901903) } } },
     { {  INT64_C(22223414), INT64_C(16045202), -INT64_C(10451385), -INT64_C(43892407) },
       {  INT64_C(9088806), INT64_C(5526600), -INT64_C(39966909), -INT64_C(16888026)},
     { {  INT64_C(22223414), INT64_C(22223414) },
       {  INT64_C(16045202), INT64_C(16045202) },
       {  -INT64_C(10451385), -INT64_C(10451385) },
       {  -INT64_C(43892407), -INT64_C(43892407) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x4_t r = simde_vld4q_dup_s64(test_vec[i].a);
    simde_int64x2x4_t expected = {
        {simde_vld1q_s64(test_vec[i].r[0]), simde_vld1q_s64(test_vec[i].r[1]),
         simde_vld1q_s64(test_vec[i].r[2]), simde_vld1q_s64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_i64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4q_dup_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a[4];
    uint8_t unused[4];
    uint8_t r[4][16];
  } test_vec[] = {
     { {  UINT8_C(116), UINT8_C(71), UINT8_C(49), UINT8_C(111) },
       {  UINT8_C(32), UINT8_C(42), UINT8_C(155), UINT8_C(143)},
     { {  UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116),
        UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116) },
       {  UINT8_C(71), UINT8_C(71), UINT8_C(71), UINT8_C(71), UINT8_C(71), UINT8_C(71), UINT8_C(71), UINT8_C(71),
        UINT8_C(71), UINT8_C(71), UINT8_C(71), UINT8_C(71), UINT8_C(71), UINT8_C(71), UINT8_C(71), UINT8_C(71) },
       {  UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49),
        UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49), UINT8_C(49) },
       {  UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111),
        UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111), UINT8_C(111) } } },
     { {  UINT8_C(78), UINT8_C(123), UINT8_C(149), UINT8_C(6) },
       {  UINT8_C(99), UINT8_C(125), UINT8_C(28), UINT8_C(85)},
     { {  UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78),
        UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78), UINT8_C(78) },
       {  UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123),
        UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123), UINT8_C(123) },
       {  UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149),
        UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149) },
       {  UINT8_C(6), UINT8_C(6), UINT8_C(6), UINT8_C(6), UINT8_C(6), UINT8_C(6), UINT8_C(6), UINT8_C(6),
        UINT8_C(6), UINT8_C(6), UINT8_C(6), UINT8_C(6), UINT8_C(6), UINT8_C(6), UINT8_C(6), UINT8_C(6) } } },
     { {  UINT8_C(65), UINT8_C(57), UINT8_C(192), UINT8_C(126) },
       {  UINT8_C(178), UINT8_C(53), UINT8_C(96), UINT8_C(39)},
     { {  UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65),
        UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65) },
       {  UINT8_C(57), UINT8_C(57), UINT8_C(57), UINT8_C(57), UINT8_C(57), UINT8_C(57), UINT8_C(57), UINT8_C(57),
        UINT8_C(57), UINT8_C(57), UINT8_C(57), UINT8_C(57), UINT8_C(57), UINT8_C(57), UINT8_C(57), UINT8_C(57) },
       {  UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192),
        UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192) },
       {  UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126),
        UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126) } } },
     { {  UINT8_C(107), UINT8_C(172), UINT8_C(112), UINT8_C(99) },
       {  UINT8_C(140), UINT8_C(193), UINT8_C(42), UINT8_C(31)},
     { {  UINT8_C(107), UINT8_C(107), UINT8_C(107), UINT8_C(107), UINT8_C(107), UINT8_C(107), UINT8_C(107), UINT8_C(107),
        UINT8_C(107), UINT8_C(107), UINT8_C(107), UINT8_C(107), UINT8_C(107), UINT8_C(107), UINT8_C(107), UINT8_C(107) },
       {  UINT8_C(172), UINT8_C(172), UINT8_C(172), UINT8_C(172), UINT8_C(172), UINT8_C(172), UINT8_C(172), UINT8_C(172),
        UINT8_C(172), UINT8_C(172), UINT8_C(172), UINT8_C(172), UINT8_C(172), UINT8_C(172), UINT8_C(172), UINT8_C(172) },
       {  UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112),
        UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112), UINT8_C(112) },
       {  UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99),
        UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99), UINT8_C(99) } } },
     { {  UINT8_C(184), UINT8_C(97), UINT8_C(109), UINT8_C(89) },
       {  UINT8_C(30), UINT8_C(38), UINT8_C(31), UINT8_C(133)},
     { {  UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184),
        UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184) },
       {  UINT8_C(97), UINT8_C(97), UINT8_C(97), UINT8_C(97), UINT8_C(97), UINT8_C(97), UINT8_C(97), UINT8_C(97),
        UINT8_C(97), UINT8_C(97), UINT8_C(97), UINT8_C(97), UINT8_C(97), UINT8_C(97), UINT8_C(97), UINT8_C(97) },
       {  UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109),
        UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109) },
       {  UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89),
        UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89) } } },
     { {  UINT8_C(80), UINT8_C(53), UINT8_C(126), UINT8_C(83) },
       {  UINT8_C(48), UINT8_C(9), UINT8_C(28), UINT8_C(3)},
     { {  UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80),
        UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80) },
       {  UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53),
        UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53) },
       {  UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126),
        UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126), UINT8_C(126) },
       {  UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83),
        UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83) } } },
     { {  UINT8_C(12), UINT8_C(5), UINT8_C(69), UINT8_C(0) },
       {  UINT8_C(124), UINT8_C(136), UINT8_C(44), UINT8_C(0)},
     { {  UINT8_C(12), UINT8_C(12), UINT8_C(12), UINT8_C(12), UINT8_C(12), UINT8_C(12), UINT8_C(12), UINT8_C(12),
        UINT8_C(12), UINT8_C(12), UINT8_C(12), UINT8_C(12), UINT8_C(12), UINT8_C(12), UINT8_C(12), UINT8_C(12) },
       {  UINT8_C(5), UINT8_C(5), UINT8_C(5), UINT8_C(5), UINT8_C(5), UINT8_C(5), UINT8_C(5), UINT8_C(5),
        UINT8_C(5), UINT8_C(5), UINT8_C(5), UINT8_C(5), UINT8_C(5), UINT8_C(5), UINT8_C(5), UINT8_C(5) },
       {  UINT8_C(69), UINT8_C(69), UINT8_C(69), UINT8_C(69), UINT8_C(69), UINT8_C(69), UINT8_C(69), UINT8_C(69),
        UINT8_C(69), UINT8_C(69), UINT8_C(69), UINT8_C(69), UINT8_C(69), UINT8_C(69), UINT8_C(69), UINT8_C(69) },
       {  UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(0),
        UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(0), UINT8_C(0) } } },
     { {  UINT8_C(2), UINT8_C(163), UINT8_C(34), UINT8_C(161) },
       {  UINT8_C(146), UINT8_C(64), UINT8_C(123), UINT8_C(49)},
     { {  UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2),
        UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2) },
       {  UINT8_C(163), UINT8_C(163), UINT8_C(163), UINT8_C(163), UINT8_C(163), UINT8_C(163), UINT8_C(163), UINT8_C(163),
        UINT8_C(163), UINT8_C(163), UINT8_C(163), UINT8_C(163), UINT8_C(163), UINT8_C(163), UINT8_C(163), UINT8_C(163) },
       {  UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34),
        UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34) },
       {  UINT8_C(161), UINT8_C(161), UINT8_C(161), UINT8_C(161), UINT8_C(161), UINT8_C(161), UINT8_C(161), UINT8_C(161),
        UINT8_C(161), UINT8_C(161), UINT8_C(161), UINT8_C(161), UINT8_C(161), UINT8_C(161), UINT8_C(161), UINT8_C(161) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x4_t r = simde_vld4q_dup_u8(test_vec[i].a);
    simde_uint8x16x4_t expected = {
        {simde_vld1q_u8(test_vec[i].r[0]), simde_vld1q_u8(test_vec[i].r[1]),
         simde_vld1q_u8(test_vec[i].r[2]), simde_vld1q_u8(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4q_dup_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[4];
    uint16_t unused[4];
    uint16_t r[4][8];
  } test_vec[] = {
     { {  UINT16_C(10133), UINT16_C(6843), UINT16_C(4919), UINT16_C(4910) },
       {  UINT16_C(5127), UINT16_C(12463), UINT16_C(6726), UINT16_C(17829)},
     { {  UINT16_C(10133), UINT16_C(10133), UINT16_C(10133), UINT16_C(10133),
        UINT16_C(10133), UINT16_C(10133), UINT16_C(10133), UINT16_C(10133) },
       {  UINT16_C(6843), UINT16_C(6843), UINT16_C(6843), UINT16_C(6843),
        UINT16_C(6843), UINT16_C(6843), UINT16_C(6843), UINT16_C(6843) },
       {  UINT16_C(4919), UINT16_C(4919), UINT16_C(4919), UINT16_C(4919),
        UINT16_C(4919), UINT16_C(4919), UINT16_C(4919), UINT16_C(4919) },
       {  UINT16_C(4910), UINT16_C(4910), UINT16_C(4910), UINT16_C(4910),
        UINT16_C(4910), UINT16_C(4910), UINT16_C(4910), UINT16_C(4910) } } },
     { {  UINT16_C(2738), UINT16_C(7856), UINT16_C(14494), UINT16_C(7102) },
       {  UINT16_C(244), UINT16_C(9302), UINT16_C(7532), UINT16_C(5861)},
     { {  UINT16_C(2738), UINT16_C(2738), UINT16_C(2738), UINT16_C(2738),
        UINT16_C(2738), UINT16_C(2738), UINT16_C(2738), UINT16_C(2738) },
       {  UINT16_C(7856), UINT16_C(7856), UINT16_C(7856), UINT16_C(7856),
        UINT16_C(7856), UINT16_C(7856), UINT16_C(7856), UINT16_C(7856) },
       {  UINT16_C(14494), UINT16_C(14494), UINT16_C(14494), UINT16_C(14494),
        UINT16_C(14494), UINT16_C(14494), UINT16_C(14494), UINT16_C(14494) },
       {  UINT16_C(7102), UINT16_C(7102), UINT16_C(7102), UINT16_C(7102),
        UINT16_C(7102), UINT16_C(7102), UINT16_C(7102), UINT16_C(7102) } } },
     { {  UINT16_C(5864), UINT16_C(933), UINT16_C(15453), UINT16_C(2108) },
       {  UINT16_C(11794), UINT16_C(15211), UINT16_C(19290), UINT16_C(8938)},
     { {  UINT16_C(5864), UINT16_C(5864), UINT16_C(5864), UINT16_C(5864),
        UINT16_C(5864), UINT16_C(5864), UINT16_C(5864), UINT16_C(5864) },
       {  UINT16_C(933), UINT16_C(933), UINT16_C(933), UINT16_C(933),
        UINT16_C(933), UINT16_C(933), UINT16_C(933), UINT16_C(933) },
       {  UINT16_C(15453), UINT16_C(15453), UINT16_C(15453), UINT16_C(15453),
        UINT16_C(15453), UINT16_C(15453), UINT16_C(15453), UINT16_C(15453) },
       {  UINT16_C(2108), UINT16_C(2108), UINT16_C(2108), UINT16_C(2108),
        UINT16_C(2108), UINT16_C(2108), UINT16_C(2108), UINT16_C(2108) } } },
     { {  UINT16_C(7054), UINT16_C(10852), UINT16_C(1425), UINT16_C(11316) },
       {  UINT16_C(4905), UINT16_C(8620), UINT16_C(9572), UINT16_C(6783)},
     { {  UINT16_C(7054), UINT16_C(7054), UINT16_C(7054), UINT16_C(7054),
        UINT16_C(7054), UINT16_C(7054), UINT16_C(7054), UINT16_C(7054) },
       {  UINT16_C(10852), UINT16_C(10852), UINT16_C(10852), UINT16_C(10852),
        UINT16_C(10852), UINT16_C(10852), UINT16_C(10852), UINT16_C(10852) },
       {  UINT16_C(1425), UINT16_C(1425), UINT16_C(1425), UINT16_C(1425),
        UINT16_C(1425), UINT16_C(1425), UINT16_C(1425), UINT16_C(1425) },
       {  UINT16_C(11316), UINT16_C(11316), UINT16_C(11316), UINT16_C(11316),
        UINT16_C(11316), UINT16_C(11316), UINT16_C(11316), UINT16_C(11316) } } },
     { {  UINT16_C(13105), UINT16_C(2420), UINT16_C(11971), UINT16_C(17278) },
       {  UINT16_C(2311), UINT16_C(9393), UINT16_C(19286), UINT16_C(16567)},
     { {  UINT16_C(13105), UINT16_C(13105), UINT16_C(13105), UINT16_C(13105),
        UINT16_C(13105), UINT16_C(13105), UINT16_C(13105), UINT16_C(13105) },
       {  UINT16_C(2420), UINT16_C(2420), UINT16_C(2420), UINT16_C(2420),
        UINT16_C(2420), UINT16_C(2420), UINT16_C(2420), UINT16_C(2420) },
       {  UINT16_C(11971), UINT16_C(11971), UINT16_C(11971), UINT16_C(11971),
        UINT16_C(11971), UINT16_C(11971), UINT16_C(11971), UINT16_C(11971) },
       {  UINT16_C(17278), UINT16_C(17278), UINT16_C(17278), UINT16_C(17278),
        UINT16_C(17278), UINT16_C(17278), UINT16_C(17278), UINT16_C(17278) } } },
     { {  UINT16_C(14853), UINT16_C(8577), UINT16_C(6845), UINT16_C(7330) },
       {  UINT16_C(3034), UINT16_C(14753), UINT16_C(15783), UINT16_C(13850)},
     { {  UINT16_C(14853), UINT16_C(14853), UINT16_C(14853), UINT16_C(14853),
        UINT16_C(14853), UINT16_C(14853), UINT16_C(14853), UINT16_C(14853) },
       {  UINT16_C(8577), UINT16_C(8577), UINT16_C(8577), UINT16_C(8577),
        UINT16_C(8577), UINT16_C(8577), UINT16_C(8577), UINT16_C(8577) },
       {  UINT16_C(6845), UINT16_C(6845), UINT16_C(6845), UINT16_C(6845),
        UINT16_C(6845), UINT16_C(6845), UINT16_C(6845), UINT16_C(6845) },
       {  UINT16_C(7330), UINT16_C(7330), UINT16_C(7330), UINT16_C(7330),
        UINT16_C(7330), UINT16_C(7330), UINT16_C(7330), UINT16_C(7330) } } },
     { {  UINT16_C(15035), UINT16_C(3809), UINT16_C(2240), UINT16_C(11888) },
       {  UINT16_C(2225), UINT16_C(9548), UINT16_C(9735), UINT16_C(9069)},
     { {  UINT16_C(15035), UINT16_C(15035), UINT16_C(15035), UINT16_C(15035),
        UINT16_C(15035), UINT16_C(15035), UINT16_C(15035), UINT16_C(15035) },
       {  UINT16_C(3809), UINT16_C(3809), UINT16_C(3809), UINT16_C(3809),
        UINT16_C(3809), UINT16_C(3809), UINT16_C(3809), UINT16_C(3809) },
       {  UINT16_C(2240), UINT16_C(2240), UINT16_C(2240), UINT16_C(2240),
        UINT16_C(2240), UINT16_C(2240), UINT16_C(2240), UINT16_C(2240) },
       {  UINT16_C(11888), UINT16_C(11888), UINT16_C(11888), UINT16_C(11888),
        UINT16_C(11888), UINT16_C(11888), UINT16_C(11888), UINT16_C(11888) } } },
     { {  UINT16_C(19246), UINT16_C(11341), UINT16_C(6716), UINT16_C(8706) },
       {  UINT16_C(10028), UINT16_C(16213), UINT16_C(13201), UINT16_C(14776)},
     { {  UINT16_C(19246), UINT16_C(19246), UINT16_C(19246), UINT16_C(19246),
        UINT16_C(19246), UINT16_C(19246), UINT16_C(19246), UINT16_C(19246) },
       {  UINT16_C(11341), UINT16_C(11341), UINT16_C(11341), UINT16_C(11341),
        UINT16_C(11341), UINT16_C(11341), UINT16_C(11341), UINT16_C(11341) },
       {  UINT16_C(6716), UINT16_C(6716), UINT16_C(6716), UINT16_C(6716),
        UINT16_C(6716), UINT16_C(6716), UINT16_C(6716), UINT16_C(6716) },
       {  UINT16_C(8706), UINT16_C(8706), UINT16_C(8706), UINT16_C(8706),
        UINT16_C(8706), UINT16_C(8706), UINT16_C(8706), UINT16_C(8706) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x4_t r = simde_vld4q_dup_u16(test_vec[i].a);
    simde_uint16x8x4_t expected = {
        {simde_vld1q_u16(test_vec[i].r[0]), simde_vld1q_u16(test_vec[i].r[1]),
         simde_vld1q_u16(test_vec[i].r[2]), simde_vld1q_u16(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_u16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4q_dup_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint32_t unused[4];
    uint32_t r[4][4];
  } test_vec[] = {
     { {  UINT32_C(1257486), UINT32_C(1370541), UINT32_C(1442704), UINT32_C(6473) },
       {  UINT32_C(473754), UINT32_C(1121548), UINT32_C(1019225), UINT32_C(1532022)},
     { {  UINT32_C(1257486), UINT32_C(1257486), UINT32_C(1257486), UINT32_C(1257486) },
       {  UINT32_C(1370541), UINT32_C(1370541), UINT32_C(1370541), UINT32_C(1370541) },
       {  UINT32_C(1442704), UINT32_C(1442704), UINT32_C(1442704), UINT32_C(1442704) },
       {  UINT32_C(6473), UINT32_C(6473), UINT32_C(6473), UINT32_C(6473) } } },
     { {  UINT32_C(1777965), UINT32_C(1389944), UINT32_C(409346), UINT32_C(538095) },
       {  UINT32_C(1323377), UINT32_C(928426), UINT32_C(983700), UINT32_C(1385753)},
     { {  UINT32_C(1777965), UINT32_C(1777965), UINT32_C(1777965), UINT32_C(1777965) },
       {  UINT32_C(1389944), UINT32_C(1389944), UINT32_C(1389944), UINT32_C(1389944) },
       {  UINT32_C(409346), UINT32_C(409346), UINT32_C(409346), UINT32_C(409346) },
       {  UINT32_C(538095), UINT32_C(538095), UINT32_C(538095), UINT32_C(538095) } } },
     { {  UINT32_C(596045), UINT32_C(764597), UINT32_C(1063129), UINT32_C(1422260) },
       {  UINT32_C(1733416), UINT32_C(1030230), UINT32_C(1044242), UINT32_C(324599)},
     { {  UINT32_C(596045), UINT32_C(596045), UINT32_C(596045), UINT32_C(596045) },
       {  UINT32_C(764597), UINT32_C(764597), UINT32_C(764597), UINT32_C(764597) },
       {  UINT32_C(1063129), UINT32_C(1063129), UINT32_C(1063129), UINT32_C(1063129) },
       {  UINT32_C(1422260), UINT32_C(1422260), UINT32_C(1422260), UINT32_C(1422260) } } },
     { {  UINT32_C(1423480), UINT32_C(1138531), UINT32_C(90322), UINT32_C(481969) },
       {  UINT32_C(1376772), UINT32_C(1695937), UINT32_C(624624), UINT32_C(1995648)},
     { {  UINT32_C(1423480), UINT32_C(1423480), UINT32_C(1423480), UINT32_C(1423480) },
       {  UINT32_C(1138531), UINT32_C(1138531), UINT32_C(1138531), UINT32_C(1138531) },
       {  UINT32_C(90322), UINT32_C(90322), UINT32_C(90322), UINT32_C(90322) },
       {  UINT32_C(481969), UINT32_C(481969), UINT32_C(481969), UINT32_C(481969) } } },
     { {  UINT32_C(717226), UINT32_C(1436576), UINT32_C(931521), UINT32_C(1409184) },
       {  UINT32_C(645928), UINT32_C(1920577), UINT32_C(329937), UINT32_C(446258)},
     { {  UINT32_C(717226), UINT32_C(717226), UINT32_C(717226), UINT32_C(717226) },
       {  UINT32_C(1436576), UINT32_C(1436576), UINT32_C(1436576), UINT32_C(1436576) },
       {  UINT32_C(931521), UINT32_C(931521), UINT32_C(931521), UINT32_C(931521) },
       {  UINT32_C(1409184), UINT32_C(1409184), UINT32_C(1409184), UINT32_C(1409184) } } },
     { {  UINT32_C(233155), UINT32_C(139215), UINT32_C(269390), UINT32_C(626804) },
       {  UINT32_C(1203036), UINT32_C(383145), UINT32_C(793331), UINT32_C(1556239)},
     { {  UINT32_C(233155), UINT32_C(233155), UINT32_C(233155), UINT32_C(233155) },
       {  UINT32_C(139215), UINT32_C(139215), UINT32_C(139215), UINT32_C(139215) },
       {  UINT32_C(269390), UINT32_C(269390), UINT32_C(269390), UINT32_C(269390) },
       {  UINT32_C(626804), UINT32_C(626804), UINT32_C(626804), UINT32_C(626804) } } },
     { {  UINT32_C(1222326), UINT32_C(1812050), UINT32_C(944922), UINT32_C(616220) },
       {  UINT32_C(460703), UINT32_C(465318), UINT32_C(530328), UINT32_C(484235)},
     { {  UINT32_C(1222326), UINT32_C(1222326), UINT32_C(1222326), UINT32_C(1222326) },
       {  UINT32_C(1812050), UINT32_C(1812050), UINT32_C(1812050), UINT32_C(1812050) },
       {  UINT32_C(944922), UINT32_C(944922), UINT32_C(944922), UINT32_C(944922) },
       {  UINT32_C(616220), UINT32_C(616220), UINT32_C(616220), UINT32_C(616220) } } },
     { {  UINT32_C(945985), UINT32_C(95899), UINT32_C(1011438), UINT32_C(1588319) },
       {  UINT32_C(437902), UINT32_C(1316605), UINT32_C(646765), UINT32_C(915755)},
     { {  UINT32_C(945985), UINT32_C(945985), UINT32_C(945985), UINT32_C(945985) },
       {  UINT32_C(95899), UINT32_C(95899), UINT32_C(95899), UINT32_C(95899) },
       {  UINT32_C(1011438), UINT32_C(1011438), UINT32_C(1011438), UINT32_C(1011438) },
       {  UINT32_C(1588319), UINT32_C(1588319), UINT32_C(1588319), UINT32_C(1588319) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x4_t r = simde_vld4q_dup_u32(test_vec[i].a);
    simde_uint32x4x4_t expected = {
        {simde_vld1q_u32(test_vec[i].r[0]), simde_vld1q_u32(test_vec[i].r[1]),
         simde_vld1q_u32(test_vec[i].r[2]), simde_vld1q_u32(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4q_dup_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[4];
    uint64_t unused[4];
    uint64_t r[4][2];
  } test_vec[] = {
     { {  UINT64_C(19415023), UINT64_C(134986722), UINT64_C(140423989), UINT64_C(194366613) },
       {  UINT64_C(29748623), UINT64_C(63792851), UINT64_C(184798224), UINT64_C(170880801)},
     { {  UINT64_C(19415023), UINT64_C(19415023) },
       {  UINT64_C(134986722), UINT64_C(134986722) },
       {  UINT64_C(140423989), UINT64_C(140423989) },
       {  UINT64_C(194366613), UINT64_C(194366613) } } },
     { {  UINT64_C(72477781), UINT64_C(119998170), UINT64_C(19598295), UINT64_C(4615743) },
       {  UINT64_C(153105690), UINT64_C(4212704), UINT64_C(31753299), UINT64_C(100870623)},
     { {  UINT64_C(72477781), UINT64_C(72477781) },
       {  UINT64_C(119998170), UINT64_C(119998170) },
       {  UINT64_C(19598295), UINT64_C(19598295) },
       {  UINT64_C(4615743), UINT64_C(4615743) } } },
     { {  UINT64_C(83267470), UINT64_C(184004374), UINT64_C(3865768), UINT64_C(20318927) },
       {  UINT64_C(101590415), UINT64_C(123726578), UINT64_C(162433497), UINT64_C(54552934)},
     { {  UINT64_C(83267470), UINT64_C(83267470) },
       {  UINT64_C(184004374), UINT64_C(184004374) },
       {  UINT64_C(3865768), UINT64_C(3865768) },
       {  UINT64_C(20318927), UINT64_C(20318927) } } },
     { {  UINT64_C(39898183), UINT64_C(62216994), UINT64_C(153003397), UINT64_C(181219988) },
       {  UINT64_C(150010328), UINT64_C(105260849), UINT64_C(187591910), UINT64_C(59479289)},
     { {  UINT64_C(39898183), UINT64_C(39898183) },
       {  UINT64_C(62216994), UINT64_C(62216994) },
       {  UINT64_C(153003397), UINT64_C(153003397) },
       {  UINT64_C(181219988), UINT64_C(181219988) } } },
     { {  UINT64_C(94456081), UINT64_C(158574380), UINT64_C(117246539), UINT64_C(195475124) },
       {  UINT64_C(45127472), UINT64_C(38196881), UINT64_C(167589198), UINT64_C(56546110)},
     { {  UINT64_C(94456081), UINT64_C(94456081) },
       {  UINT64_C(158574380), UINT64_C(158574380) },
       {  UINT64_C(117246539), UINT64_C(117246539) },
       {  UINT64_C(195475124), UINT64_C(195475124) } } },
     { {  UINT64_C(84845160), UINT64_C(183689028), UINT64_C(107358519), UINT64_C(141662487) },
       {  UINT64_C(124767939), UINT64_C(127494288), UINT64_C(109530805), UINT64_C(73133350)},
     { {  UINT64_C(84845160), UINT64_C(84845160) },
       {  UINT64_C(183689028), UINT64_C(183689028) },
       {  UINT64_C(107358519), UINT64_C(107358519) },
       {  UINT64_C(141662487), UINT64_C(141662487) } } },
     { {  UINT64_C(126339519), UINT64_C(795258), UINT64_C(46341725), UINT64_C(117764884) },
       {  UINT64_C(114711556), UINT64_C(24833869), UINT64_C(26165703), UINT64_C(104429137)},
     { {  UINT64_C(126339519), UINT64_C(126339519) },
       {  UINT64_C(795258), UINT64_C(795258) },
       {  UINT64_C(46341725), UINT64_C(46341725) },
       {  UINT64_C(117764884), UINT64_C(117764884) } } },
     { {  UINT64_C(146405593), UINT64_C(135429224), UINT64_C(127955147), UINT64_C(56324641) },
       {  UINT64_C(39205962), UINT64_C(153262080), UINT64_C(163534203), UINT64_C(21735994)},
     { {  UINT64_C(146405593), UINT64_C(146405593) },
       {  UINT64_C(135429224), UINT64_C(135429224) },
       {  UINT64_C(127955147), UINT64_C(127955147) },
       {  UINT64_C(56324641), UINT64_C(56324641) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x4_t r = simde_vld4q_dup_u64(test_vec[i].a);
    simde_uint64x2x4_t expected = {
        {simde_vld1q_u64(test_vec[i].r[0]), simde_vld1q_u64(test_vec[i].r[1]),
         simde_vld1q_u64(test_vec[i].r[2]), simde_vld1q_u64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_u64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[3], expected.val[3]);
  }

  return 0;
}

static int
test_simde_vld4_dup_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[4];
    simde_poly8_t unused[4];
    simde_poly8_t r[4][8];
  } test_vec[] = {
    { { SIMDE_POLY8_C(105), SIMDE_POLY8_C(124), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 93) },
      { SIMDE_POLY8_C(125), SIMDE_POLY8_C( 98), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 58) },
        { { SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105), SIMDE_POLY8_C(105) },
          { SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124) },
          { SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250) },
          { SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 93) } },
    },
    { { SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 92), SIMDE_POLY8_C(157), SIMDE_POLY8_C(186) },
      { SIMDE_POLY8_C(164), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(155), SIMDE_POLY8_C(106) },
        { { SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 75) },
          { SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 92) },
          { SIMDE_POLY8_C(157), SIMDE_POLY8_C(157), SIMDE_POLY8_C(157), SIMDE_POLY8_C(157), SIMDE_POLY8_C(157), SIMDE_POLY8_C(157), SIMDE_POLY8_C(157), SIMDE_POLY8_C(157) },
          { SIMDE_POLY8_C(186), SIMDE_POLY8_C(186), SIMDE_POLY8_C(186), SIMDE_POLY8_C(186), SIMDE_POLY8_C(186), SIMDE_POLY8_C(186), SIMDE_POLY8_C(186), SIMDE_POLY8_C(186) } },
    },
    { { SIMDE_POLY8_C( 91), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 86) },
      { SIMDE_POLY8_C(248), SIMDE_POLY8_C(228), SIMDE_POLY8_C( 91), SIMDE_POLY8_C(  8) },
        { { SIMDE_POLY8_C( 91), SIMDE_POLY8_C( 91), SIMDE_POLY8_C( 91), SIMDE_POLY8_C( 91), SIMDE_POLY8_C( 91), SIMDE_POLY8_C( 91), SIMDE_POLY8_C( 91), SIMDE_POLY8_C( 91) },
          { SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250), SIMDE_POLY8_C(250) },
          { SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 53), SIMDE_POLY8_C( 53) },
          { SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 86) } },
    },
    { { SIMDE_POLY8_C(248), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(189), SIMDE_POLY8_C(179) },
      { SIMDE_POLY8_C( 67), SIMDE_POLY8_C(148), SIMDE_POLY8_C(198), SIMDE_POLY8_C(173) },
        { { SIMDE_POLY8_C(248), SIMDE_POLY8_C(248), SIMDE_POLY8_C(248), SIMDE_POLY8_C(248), SIMDE_POLY8_C(248), SIMDE_POLY8_C(248), SIMDE_POLY8_C(248), SIMDE_POLY8_C(248) },
          { SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 76) },
          { SIMDE_POLY8_C(189), SIMDE_POLY8_C(189), SIMDE_POLY8_C(189), SIMDE_POLY8_C(189), SIMDE_POLY8_C(189), SIMDE_POLY8_C(189), SIMDE_POLY8_C(189), SIMDE_POLY8_C(189) },
          { SIMDE_POLY8_C(179), SIMDE_POLY8_C(179), SIMDE_POLY8_C(179), SIMDE_POLY8_C(179), SIMDE_POLY8_C(179), SIMDE_POLY8_C(179), SIMDE_POLY8_C(179), SIMDE_POLY8_C(179) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8x4_t r = simde_vld4_dup_p8(test_vec[i].a);
    simde_poly8x8x4_t expected = {
        {simde_vld1_p8(test_vec[i].r[0]), simde_vld1_p8(test_vec[i].r[1]),
         simde_vld1_p8(test_vec[i].r[2]), simde_vld1_p8(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_p8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly8_t a[4];
    simde_poly8_t unused[4];
    simde_poly8x8x4_t r;
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld4_dup_p8(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp8(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp8(2, 4, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_dup_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[4];
    simde_poly16_t unused[4];
    simde_poly16_t r[4][4];
  } test_vec[] = {
     { {  SIMDE_POLY16_C(15647), SIMDE_POLY16_C(8273), SIMDE_POLY16_C(18121), SIMDE_POLY16_C(3909) },
       {  SIMDE_POLY16_C(3886), SIMDE_POLY16_C(18927), SIMDE_POLY16_C(6497), SIMDE_POLY16_C(15716)},
     { {  SIMDE_POLY16_C(15647), SIMDE_POLY16_C(15647), SIMDE_POLY16_C(15647), SIMDE_POLY16_C(15647) },
       {  SIMDE_POLY16_C(8273), SIMDE_POLY16_C(8273), SIMDE_POLY16_C(8273), SIMDE_POLY16_C(8273) },
       {  SIMDE_POLY16_C(18121), SIMDE_POLY16_C(18121), SIMDE_POLY16_C(18121), SIMDE_POLY16_C(18121) },
       {  SIMDE_POLY16_C(3909), SIMDE_POLY16_C(3909), SIMDE_POLY16_C(3909), SIMDE_POLY16_C(3909) } } },
     { {  SIMDE_POLY16_C(10363), SIMDE_POLY16_C(741), SIMDE_POLY16_C(19314), SIMDE_POLY16_C(207) },
       {  SIMDE_POLY16_C(18543), SIMDE_POLY16_C(10812), SIMDE_POLY16_C(4523), SIMDE_POLY16_C(17338)},
     { {  SIMDE_POLY16_C(10363), SIMDE_POLY16_C(10363), SIMDE_POLY16_C(10363), SIMDE_POLY16_C(10363) },
       {  SIMDE_POLY16_C(741), SIMDE_POLY16_C(741), SIMDE_POLY16_C(741), SIMDE_POLY16_C(741) },
       {  SIMDE_POLY16_C(19314), SIMDE_POLY16_C(19314), SIMDE_POLY16_C(19314), SIMDE_POLY16_C(19314) },
       {  SIMDE_POLY16_C(207), SIMDE_POLY16_C(207), SIMDE_POLY16_C(207), SIMDE_POLY16_C(207) } } },
     { {  SIMDE_POLY16_C(1661), SIMDE_POLY16_C(15340), SIMDE_POLY16_C(9240), SIMDE_POLY16_C(2126) },
       {  SIMDE_POLY16_C(19898), SIMDE_POLY16_C(6041), SIMDE_POLY16_C(8131), SIMDE_POLY16_C(5048)},
     { {  SIMDE_POLY16_C(1661), SIMDE_POLY16_C(1661), SIMDE_POLY16_C(1661), SIMDE_POLY16_C(1661) },
       {  SIMDE_POLY16_C(15340), SIMDE_POLY16_C(15340), SIMDE_POLY16_C(15340), SIMDE_POLY16_C(15340) },
       {  SIMDE_POLY16_C(9240), SIMDE_POLY16_C(9240), SIMDE_POLY16_C(9240), SIMDE_POLY16_C(9240) },
       {  SIMDE_POLY16_C(2126), SIMDE_POLY16_C(2126), SIMDE_POLY16_C(2126), SIMDE_POLY16_C(2126) } } },
     { {  SIMDE_POLY16_C(18793), SIMDE_POLY16_C(9875), SIMDE_POLY16_C(19455), SIMDE_POLY16_C(5867) },
       {  SIMDE_POLY16_C(6575), SIMDE_POLY16_C(19585), SIMDE_POLY16_C(56), SIMDE_POLY16_C(13746)},
     { {  SIMDE_POLY16_C(18793), SIMDE_POLY16_C(18793), SIMDE_POLY16_C(18793), SIMDE_POLY16_C(18793) },
       {  SIMDE_POLY16_C(9875), SIMDE_POLY16_C(9875), SIMDE_POLY16_C(9875), SIMDE_POLY16_C(9875) },
       {  SIMDE_POLY16_C(19455), SIMDE_POLY16_C(19455), SIMDE_POLY16_C(19455), SIMDE_POLY16_C(19455) },
       {  SIMDE_POLY16_C(5867), SIMDE_POLY16_C(5867), SIMDE_POLY16_C(5867), SIMDE_POLY16_C(5867) } } },
     { {  SIMDE_POLY16_C(7315), SIMDE_POLY16_C(11780), SIMDE_POLY16_C(12282), SIMDE_POLY16_C(249) },
       {  SIMDE_POLY16_C(2882), SIMDE_POLY16_C(5581), SIMDE_POLY16_C(2639), SIMDE_POLY16_C(13799)},
     { {  SIMDE_POLY16_C(7315), SIMDE_POLY16_C(7315), SIMDE_POLY16_C(7315), SIMDE_POLY16_C(7315) },
       {  SIMDE_POLY16_C(11780), SIMDE_POLY16_C(11780), SIMDE_POLY16_C(11780), SIMDE_POLY16_C(11780) },
       {  SIMDE_POLY16_C(12282), SIMDE_POLY16_C(12282), SIMDE_POLY16_C(12282), SIMDE_POLY16_C(12282) },
       {  SIMDE_POLY16_C(249), SIMDE_POLY16_C(249), SIMDE_POLY16_C(249), SIMDE_POLY16_C(249) } } },
     { {  SIMDE_POLY16_C(18499), SIMDE_POLY16_C(11815), SIMDE_POLY16_C(19200), SIMDE_POLY16_C(9265) },
       {  SIMDE_POLY16_C(17744), SIMDE_POLY16_C(12481), SIMDE_POLY16_C(12307), SIMDE_POLY16_C(15151)},
     { {  SIMDE_POLY16_C(18499), SIMDE_POLY16_C(18499), SIMDE_POLY16_C(18499), SIMDE_POLY16_C(18499) },
       {  SIMDE_POLY16_C(11815), SIMDE_POLY16_C(11815), SIMDE_POLY16_C(11815), SIMDE_POLY16_C(11815) },
       {  SIMDE_POLY16_C(19200), SIMDE_POLY16_C(19200), SIMDE_POLY16_C(19200), SIMDE_POLY16_C(19200) },
       {  SIMDE_POLY16_C(9265), SIMDE_POLY16_C(9265), SIMDE_POLY16_C(9265), SIMDE_POLY16_C(9265) } } },
     { {  SIMDE_POLY16_C(17166), SIMDE_POLY16_C(17671), SIMDE_POLY16_C(16947), SIMDE_POLY16_C(2009) },
       {  SIMDE_POLY16_C(5791), SIMDE_POLY16_C(6900), SIMDE_POLY16_C(7399), SIMDE_POLY16_C(18218)},
     { {  SIMDE_POLY16_C(17166), SIMDE_POLY16_C(17166), SIMDE_POLY16_C(17166), SIMDE_POLY16_C(17166) },
       {  SIMDE_POLY16_C(17671), SIMDE_POLY16_C(17671), SIMDE_POLY16_C(17671), SIMDE_POLY16_C(17671) },
       {  SIMDE_POLY16_C(16947), SIMDE_POLY16_C(16947), SIMDE_POLY16_C(16947), SIMDE_POLY16_C(16947) },
       {  SIMDE_POLY16_C(2009), SIMDE_POLY16_C(2009), SIMDE_POLY16_C(2009), SIMDE_POLY16_C(2009) } } },
     { {  SIMDE_POLY16_C(14861), SIMDE_POLY16_C(6270), SIMDE_POLY16_C(16359), SIMDE_POLY16_C(971) },
       {  SIMDE_POLY16_C(5169), SIMDE_POLY16_C(10261), SIMDE_POLY16_C(5910), SIMDE_POLY16_C(17221)},
     { {  SIMDE_POLY16_C(14861), SIMDE_POLY16_C(14861), SIMDE_POLY16_C(14861), SIMDE_POLY16_C(14861) },
       {  SIMDE_POLY16_C(6270), SIMDE_POLY16_C(6270), SIMDE_POLY16_C(6270), SIMDE_POLY16_C(6270) },
       {  SIMDE_POLY16_C(16359), SIMDE_POLY16_C(16359), SIMDE_POLY16_C(16359), SIMDE_POLY16_C(16359) },
       {  SIMDE_POLY16_C(971), SIMDE_POLY16_C(971), SIMDE_POLY16_C(971), SIMDE_POLY16_C(971) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4x4_t r = simde_vld4_dup_p16(test_vec[i].a);
    simde_poly16x4x4_t expected = {
        {simde_vld1_p16(test_vec[i].r[0]), simde_vld1_p16(test_vec[i].r[1]),
         simde_vld1_p16(test_vec[i].r[2]), simde_vld1_p16(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_p16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16_t a[4];
    simde_poly16_t unused[4];
    simde_poly16x4x4_t r;
    simde_test_codegen_random_memory(8, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(8, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld4_dup_p16(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp16(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp16(2, 4, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_dup_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[4];
    simde_poly64_t unused[4];
    simde_poly64_t r[4][1];
  } test_vec[] = {
    { { SIMDE_POLY64_C( 5959551977973526970), SIMDE_POLY64_C(14029000817486517753), SIMDE_POLY64_C(17651025089120293187), SIMDE_POLY64_C(13203343532633362859) },
      { SIMDE_POLY64_C( 6892855326725558627), SIMDE_POLY64_C(16345876003958463020), SIMDE_POLY64_C( 1354033622407470345), SIMDE_POLY64_C(17240734353314142863) },
        { { SIMDE_POLY64_C( 5959551977973526970) },
          { SIMDE_POLY64_C(14029000817486517753) },
          { SIMDE_POLY64_C(17651025089120293187) },
          { SIMDE_POLY64_C(13203343532633362859) } },
    },
    { { SIMDE_POLY64_C( 7636675867502241333), SIMDE_POLY64_C(13909746472053604487), SIMDE_POLY64_C(11398434799918420405), SIMDE_POLY64_C(17416948890982832186) },
      { SIMDE_POLY64_C( 7924795918666037844), SIMDE_POLY64_C( 9764258991320627464), SIMDE_POLY64_C(12888407647516301102), SIMDE_POLY64_C(14544426080505759530) },
        { { SIMDE_POLY64_C( 7636675867502241333) },
          { SIMDE_POLY64_C(13909746472053604487) },
          { SIMDE_POLY64_C(11398434799918420405) },
          { SIMDE_POLY64_C(17416948890982832186) } },
    },
    { { SIMDE_POLY64_C(17617049215213135144), SIMDE_POLY64_C(15863425757284143309), SIMDE_POLY64_C(14301170294920497485), SIMDE_POLY64_C( 5132842570433294589) },
      { SIMDE_POLY64_C(13243912130489914858), SIMDE_POLY64_C(  174933079806607331), SIMDE_POLY64_C( 8910440573132310341), SIMDE_POLY64_C(14165274220567549231) },
        { { SIMDE_POLY64_C(17617049215213135144) },
          { SIMDE_POLY64_C(15863425757284143309) },
          { SIMDE_POLY64_C(14301170294920497485) },
          { SIMDE_POLY64_C( 5132842570433294589) } },
    },
    { { SIMDE_POLY64_C(11700182230773722302), SIMDE_POLY64_C( 8546882327743280613), SIMDE_POLY64_C(14996987453407519527), SIMDE_POLY64_C(17722707103444766037) },
      { SIMDE_POLY64_C(15564999909380558240), SIMDE_POLY64_C(18255357401336264113), SIMDE_POLY64_C(  424396851385643121), SIMDE_POLY64_C( 6195589370824884687) },
        { { SIMDE_POLY64_C(11700182230773722302) },
          { SIMDE_POLY64_C( 8546882327743280613) },
          { SIMDE_POLY64_C(14996987453407519527) },
          { SIMDE_POLY64_C(17722707103444766037) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1x4_t r = simde_vld4_dup_p64(test_vec[i].a);
    simde_poly64x1x4_t expected = {
        {simde_vld1_p64(test_vec[i].r[0]), simde_vld1_p64(test_vec[i].r[1]),
         simde_vld1_p64(test_vec[i].r[2]), simde_vld1_p64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_p64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly64_t a[4];
    simde_poly64_t unused[4];
    simde_poly64x1x4_t r;
    simde_test_codegen_random_memory(32, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(32, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld4_dup_p64(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp64(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp64(2, 4, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_dup_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[4];
    simde_poly8_t unused[4];
    simde_poly8_t r[4][16];
  } test_vec[] = {
     { {  SIMDE_POLY8_C(116), SIMDE_POLY8_C(71), SIMDE_POLY8_C(49), SIMDE_POLY8_C(111) },
       {  SIMDE_POLY8_C(32), SIMDE_POLY8_C(42), SIMDE_POLY8_C(155), SIMDE_POLY8_C(143)},
     { {  SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116),
        SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116), SIMDE_POLY8_C(116) },
       {  SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71),
        SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71), SIMDE_POLY8_C(71) },
       {  SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49),
        SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49), SIMDE_POLY8_C(49) },
       {  SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111),
        SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111), SIMDE_POLY8_C(111) } } },
     { {  SIMDE_POLY8_C(78), SIMDE_POLY8_C(123), SIMDE_POLY8_C(149), SIMDE_POLY8_C(6) },
       {  SIMDE_POLY8_C(99), SIMDE_POLY8_C(125), SIMDE_POLY8_C(28), SIMDE_POLY8_C(85)},
     { {  SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78),
        SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78), SIMDE_POLY8_C(78) },
       {  SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123),
        SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123), SIMDE_POLY8_C(123) },
       {  SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149),
        SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149) },
       {  SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6),
        SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6), SIMDE_POLY8_C(6) } } },
     { {  SIMDE_POLY8_C(65), SIMDE_POLY8_C(57), SIMDE_POLY8_C(192), SIMDE_POLY8_C(126) },
       {  SIMDE_POLY8_C(178), SIMDE_POLY8_C(53), SIMDE_POLY8_C(96), SIMDE_POLY8_C(39)},
     { {  SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65),
        SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65) },
       {  SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57),
        SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57), SIMDE_POLY8_C(57) },
       {  SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192),
        SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192), SIMDE_POLY8_C(192) },
       {  SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126),
        SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126) } } },
     { {  SIMDE_POLY8_C(107), SIMDE_POLY8_C(172), SIMDE_POLY8_C(112), SIMDE_POLY8_C(99) },
       {  SIMDE_POLY8_C(140), SIMDE_POLY8_C(193), SIMDE_POLY8_C(42), SIMDE_POLY8_C(31)},
     { {  SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107),
        SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107), SIMDE_POLY8_C(107) },
       {  SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172),
        SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172), SIMDE_POLY8_C(172) },
       {  SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112),
        SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112), SIMDE_POLY8_C(112) },
       {  SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99),
        SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99), SIMDE_POLY8_C(99) } } },
     { {  SIMDE_POLY8_C(184), SIMDE_POLY8_C(97), SIMDE_POLY8_C(109), SIMDE_POLY8_C(89) },
       {  SIMDE_POLY8_C(30), SIMDE_POLY8_C(38), SIMDE_POLY8_C(31), SIMDE_POLY8_C(133)},
     { {  SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184),
        SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184) },
       {  SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97),
        SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97), SIMDE_POLY8_C(97) },
       {  SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109),
        SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109), SIMDE_POLY8_C(109) },
       {  SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89),
        SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89) } } },
     { {  SIMDE_POLY8_C(80), SIMDE_POLY8_C(53), SIMDE_POLY8_C(126), SIMDE_POLY8_C(83) },
       {  SIMDE_POLY8_C(48), SIMDE_POLY8_C(9), SIMDE_POLY8_C(28), SIMDE_POLY8_C(3)},
     { {  SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80),
        SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80) },
       {  SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53),
        SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126),
        SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126), SIMDE_POLY8_C(126) },
       {  SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83),
        SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83) } } },
     { {  SIMDE_POLY8_C(12), SIMDE_POLY8_C(5), SIMDE_POLY8_C(69), SIMDE_POLY8_C(0) },
       {  SIMDE_POLY8_C(124), SIMDE_POLY8_C(136), SIMDE_POLY8_C(44), SIMDE_POLY8_C(0)},
     { {  SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12),
        SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12), SIMDE_POLY8_C(12) },
       {  SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5),
        SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5), SIMDE_POLY8_C(5) },
       {  SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69),
        SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69), SIMDE_POLY8_C(69) },
       {  SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0),
        SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0), SIMDE_POLY8_C(0) } } },
     { {  SIMDE_POLY8_C(2), SIMDE_POLY8_C(163), SIMDE_POLY8_C(34), SIMDE_POLY8_C(161) },
       {  SIMDE_POLY8_C(146), SIMDE_POLY8_C(64), SIMDE_POLY8_C(123), SIMDE_POLY8_C(49)},
     { {  SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2) },
       {  SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163),
        SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163), SIMDE_POLY8_C(163) },
       {  SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34),
        SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34) },
       {  SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161),
        SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161), SIMDE_POLY8_C(161) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16x4_t r = simde_vld4q_dup_p8(test_vec[i].a);
    simde_poly8x16x4_t expected = {
        {simde_vld1q_p8(test_vec[i].r[0]), simde_vld1q_p8(test_vec[i].r[1]),
         simde_vld1q_p8(test_vec[i].r[2]), simde_vld1q_p8(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_p8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly8_t a[4];
    simde_poly8_t unused[4];
    simde_poly8x16x4_t r;
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld4q_dup_p8(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp8(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp8(2, 4, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_dup_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[4];
    simde_poly16_t unused[4];
    simde_poly16_t r[4][8];
  } test_vec[] = {
     { {  SIMDE_POLY16_C(10133), SIMDE_POLY16_C(6843), SIMDE_POLY16_C(4919), SIMDE_POLY16_C(4910) },
       {  SIMDE_POLY16_C(5127), SIMDE_POLY16_C(12463), SIMDE_POLY16_C(6726), SIMDE_POLY16_C(17829)},
     { {  SIMDE_POLY16_C(10133), SIMDE_POLY16_C(10133), SIMDE_POLY16_C(10133), SIMDE_POLY16_C(10133),
        SIMDE_POLY16_C(10133), SIMDE_POLY16_C(10133), SIMDE_POLY16_C(10133), SIMDE_POLY16_C(10133) },
       {  SIMDE_POLY16_C(6843), SIMDE_POLY16_C(6843), SIMDE_POLY16_C(6843), SIMDE_POLY16_C(6843),
        SIMDE_POLY16_C(6843), SIMDE_POLY16_C(6843), SIMDE_POLY16_C(6843), SIMDE_POLY16_C(6843) },
       {  SIMDE_POLY16_C(4919), SIMDE_POLY16_C(4919), SIMDE_POLY16_C(4919), SIMDE_POLY16_C(4919),
        SIMDE_POLY16_C(4919), SIMDE_POLY16_C(4919), SIMDE_POLY16_C(4919), SIMDE_POLY16_C(4919) },
       {  SIMDE_POLY16_C(4910), SIMDE_POLY16_C(4910), SIMDE_POLY16_C(4910), SIMDE_POLY16_C(4910),
        SIMDE_POLY16_C(4910), SIMDE_POLY16_C(4910), SIMDE_POLY16_C(4910), SIMDE_POLY16_C(4910) } } },
     { {  SIMDE_POLY16_C(2738), SIMDE_POLY16_C(7856), SIMDE_POLY16_C(14494), SIMDE_POLY16_C(7102) },
       {  SIMDE_POLY16_C(244), SIMDE_POLY16_C(9302), SIMDE_POLY16_C(7532), SIMDE_POLY16_C(5861)},
     { {  SIMDE_POLY16_C(2738), SIMDE_POLY16_C(2738), SIMDE_POLY16_C(2738), SIMDE_POLY16_C(2738),
        SIMDE_POLY16_C(2738), SIMDE_POLY16_C(2738), SIMDE_POLY16_C(2738), SIMDE_POLY16_C(2738) },
       {  SIMDE_POLY16_C(7856), SIMDE_POLY16_C(7856), SIMDE_POLY16_C(7856), SIMDE_POLY16_C(7856),
        SIMDE_POLY16_C(7856), SIMDE_POLY16_C(7856), SIMDE_POLY16_C(7856), SIMDE_POLY16_C(7856) },
       {  SIMDE_POLY16_C(14494), SIMDE_POLY16_C(14494), SIMDE_POLY16_C(14494), SIMDE_POLY16_C(14494),
        SIMDE_POLY16_C(14494), SIMDE_POLY16_C(14494), SIMDE_POLY16_C(14494), SIMDE_POLY16_C(14494) },
       {  SIMDE_POLY16_C(7102), SIMDE_POLY16_C(7102), SIMDE_POLY16_C(7102), SIMDE_POLY16_C(7102),
        SIMDE_POLY16_C(7102), SIMDE_POLY16_C(7102), SIMDE_POLY16_C(7102), SIMDE_POLY16_C(7102) } } },
     { {  SIMDE_POLY16_C(5864), SIMDE_POLY16_C(933), SIMDE_POLY16_C(15453), SIMDE_POLY16_C(2108) },
       {  SIMDE_POLY16_C(11794), SIMDE_POLY16_C(15211), SIMDE_POLY16_C(19290), SIMDE_POLY16_C(8938)},
     { {  SIMDE_POLY16_C(5864), SIMDE_POLY16_C(5864), SIMDE_POLY16_C(5864), SIMDE_POLY16_C(5864),
        SIMDE_POLY16_C(5864), SIMDE_POLY16_C(5864), SIMDE_POLY16_C(5864), SIMDE_POLY16_C(5864) },
       {  SIMDE_POLY16_C(933), SIMDE_POLY16_C(933), SIMDE_POLY16_C(933), SIMDE_POLY16_C(933),
        SIMDE_POLY16_C(933), SIMDE_POLY16_C(933), SIMDE_POLY16_C(933), SIMDE_POLY16_C(933) },
       {  SIMDE_POLY16_C(15453), SIMDE_POLY16_C(15453), SIMDE_POLY16_C(15453), SIMDE_POLY16_C(15453),
        SIMDE_POLY16_C(15453), SIMDE_POLY16_C(15453), SIMDE_POLY16_C(15453), SIMDE_POLY16_C(15453) },
       {  SIMDE_POLY16_C(2108), SIMDE_POLY16_C(2108), SIMDE_POLY16_C(2108), SIMDE_POLY16_C(2108),
        SIMDE_POLY16_C(2108), SIMDE_POLY16_C(2108), SIMDE_POLY16_C(2108), SIMDE_POLY16_C(2108) } } },
     { {  SIMDE_POLY16_C(7054), SIMDE_POLY16_C(10852), SIMDE_POLY16_C(1425), SIMDE_POLY16_C(11316) },
       {  SIMDE_POLY16_C(4905), SIMDE_POLY16_C(8620), SIMDE_POLY16_C(9572), SIMDE_POLY16_C(6783)},
     { {  SIMDE_POLY16_C(7054), SIMDE_POLY16_C(7054), SIMDE_POLY16_C(7054), SIMDE_POLY16_C(7054),
        SIMDE_POLY16_C(7054), SIMDE_POLY16_C(7054), SIMDE_POLY16_C(7054), SIMDE_POLY16_C(7054) },
       {  SIMDE_POLY16_C(10852), SIMDE_POLY16_C(10852), SIMDE_POLY16_C(10852), SIMDE_POLY16_C(10852),
        SIMDE_POLY16_C(10852), SIMDE_POLY16_C(10852), SIMDE_POLY16_C(10852), SIMDE_POLY16_C(10852) },
       {  SIMDE_POLY16_C(1425), SIMDE_POLY16_C(1425), SIMDE_POLY16_C(1425), SIMDE_POLY16_C(1425),
        SIMDE_POLY16_C(1425), SIMDE_POLY16_C(1425), SIMDE_POLY16_C(1425), SIMDE_POLY16_C(1425) },
       {  SIMDE_POLY16_C(11316), SIMDE_POLY16_C(11316), SIMDE_POLY16_C(11316), SIMDE_POLY16_C(11316),
        SIMDE_POLY16_C(11316), SIMDE_POLY16_C(11316), SIMDE_POLY16_C(11316), SIMDE_POLY16_C(11316) } } },
     { {  SIMDE_POLY16_C(13105), SIMDE_POLY16_C(2420), SIMDE_POLY16_C(11971), SIMDE_POLY16_C(17278) },
       {  SIMDE_POLY16_C(2311), SIMDE_POLY16_C(9393), SIMDE_POLY16_C(19286), SIMDE_POLY16_C(16567)},
     { {  SIMDE_POLY16_C(13105), SIMDE_POLY16_C(13105), SIMDE_POLY16_C(13105), SIMDE_POLY16_C(13105),
        SIMDE_POLY16_C(13105), SIMDE_POLY16_C(13105), SIMDE_POLY16_C(13105), SIMDE_POLY16_C(13105) },
       {  SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420),
        SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420) },
       {  SIMDE_POLY16_C(11971), SIMDE_POLY16_C(11971), SIMDE_POLY16_C(11971), SIMDE_POLY16_C(11971),
        SIMDE_POLY16_C(11971), SIMDE_POLY16_C(11971), SIMDE_POLY16_C(11971), SIMDE_POLY16_C(11971) },
       {  SIMDE_POLY16_C(17278), SIMDE_POLY16_C(17278), SIMDE_POLY16_C(17278), SIMDE_POLY16_C(17278),
        SIMDE_POLY16_C(17278), SIMDE_POLY16_C(17278), SIMDE_POLY16_C(17278), SIMDE_POLY16_C(17278) } } },
     { {  SIMDE_POLY16_C(14853), SIMDE_POLY16_C(8577), SIMDE_POLY16_C(6845), SIMDE_POLY16_C(7330) },
       {  SIMDE_POLY16_C(3034), SIMDE_POLY16_C(14753), SIMDE_POLY16_C(15783), SIMDE_POLY16_C(13850)},
     { {  SIMDE_POLY16_C(14853), SIMDE_POLY16_C(14853), SIMDE_POLY16_C(14853), SIMDE_POLY16_C(14853),
        SIMDE_POLY16_C(14853), SIMDE_POLY16_C(14853), SIMDE_POLY16_C(14853), SIMDE_POLY16_C(14853) },
       {  SIMDE_POLY16_C(8577), SIMDE_POLY16_C(8577), SIMDE_POLY16_C(8577), SIMDE_POLY16_C(8577),
        SIMDE_POLY16_C(8577), SIMDE_POLY16_C(8577), SIMDE_POLY16_C(8577), SIMDE_POLY16_C(8577) },
       {  SIMDE_POLY16_C(6845), SIMDE_POLY16_C(6845), SIMDE_POLY16_C(6845), SIMDE_POLY16_C(6845),
        SIMDE_POLY16_C(6845), SIMDE_POLY16_C(6845), SIMDE_POLY16_C(6845), SIMDE_POLY16_C(6845) },
       {  SIMDE_POLY16_C(7330), SIMDE_POLY16_C(7330), SIMDE_POLY16_C(7330), SIMDE_POLY16_C(7330),
        SIMDE_POLY16_C(7330), SIMDE_POLY16_C(7330), SIMDE_POLY16_C(7330), SIMDE_POLY16_C(7330) } } },
     { {  SIMDE_POLY16_C(15035), SIMDE_POLY16_C(3809), SIMDE_POLY16_C(2240), SIMDE_POLY16_C(11888) },
       {  SIMDE_POLY16_C(2225), SIMDE_POLY16_C(9548), SIMDE_POLY16_C(9735), SIMDE_POLY16_C(9069)},
     { {  SIMDE_POLY16_C(15035), SIMDE_POLY16_C(15035), SIMDE_POLY16_C(15035), SIMDE_POLY16_C(15035),
        SIMDE_POLY16_C(15035), SIMDE_POLY16_C(15035), SIMDE_POLY16_C(15035), SIMDE_POLY16_C(15035) },
       {  SIMDE_POLY16_C(3809), SIMDE_POLY16_C(3809), SIMDE_POLY16_C(3809), SIMDE_POLY16_C(3809),
        SIMDE_POLY16_C(3809), SIMDE_POLY16_C(3809), SIMDE_POLY16_C(3809), SIMDE_POLY16_C(3809) },
       {  SIMDE_POLY16_C(2240), SIMDE_POLY16_C(2240), SIMDE_POLY16_C(2240), SIMDE_POLY16_C(2240),
        SIMDE_POLY16_C(2240), SIMDE_POLY16_C(2240), SIMDE_POLY16_C(2240), SIMDE_POLY16_C(2240) },
       {  SIMDE_POLY16_C(11888), SIMDE_POLY16_C(11888), SIMDE_POLY16_C(11888), SIMDE_POLY16_C(11888),
        SIMDE_POLY16_C(11888), SIMDE_POLY16_C(11888), SIMDE_POLY16_C(11888), SIMDE_POLY16_C(11888) } } },
     { {  SIMDE_POLY16_C(19246), SIMDE_POLY16_C(11341), SIMDE_POLY16_C(6716), SIMDE_POLY16_C(8706) },
       {  SIMDE_POLY16_C(10028), SIMDE_POLY16_C(16213), SIMDE_POLY16_C(13201), SIMDE_POLY16_C(14776)},
     { {  SIMDE_POLY16_C(19246), SIMDE_POLY16_C(19246), SIMDE_POLY16_C(19246), SIMDE_POLY16_C(19246),
        SIMDE_POLY16_C(19246), SIMDE_POLY16_C(19246), SIMDE_POLY16_C(19246), SIMDE_POLY16_C(19246) },
       {  SIMDE_POLY16_C(11341), SIMDE_POLY16_C(11341), SIMDE_POLY16_C(11341), SIMDE_POLY16_C(11341),
        SIMDE_POLY16_C(11341), SIMDE_POLY16_C(11341), SIMDE_POLY16_C(11341), SIMDE_POLY16_C(11341) },
       {  SIMDE_POLY16_C(6716), SIMDE_POLY16_C(6716), SIMDE_POLY16_C(6716), SIMDE_POLY16_C(6716),
        SIMDE_POLY16_C(6716), SIMDE_POLY16_C(6716), SIMDE_POLY16_C(6716), SIMDE_POLY16_C(6716) },
       {  SIMDE_POLY16_C(8706), SIMDE_POLY16_C(8706), SIMDE_POLY16_C(8706), SIMDE_POLY16_C(8706),
        SIMDE_POLY16_C(8706), SIMDE_POLY16_C(8706), SIMDE_POLY16_C(8706), SIMDE_POLY16_C(8706) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8x4_t r = simde_vld4q_dup_p16(test_vec[i].a);
    simde_poly16x8x4_t expected = {
        {simde_vld1q_p16(test_vec[i].r[0]), simde_vld1q_p16(test_vec[i].r[1]),
         simde_vld1q_p16(test_vec[i].r[2]), simde_vld1q_p16(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_p16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16_t a[4];
    simde_poly16_t unused[4];
    simde_poly16x8x4_t r;
    simde_test_codegen_random_memory(8, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(8, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld4q_dup_p16(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp16(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp16(2, 4, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4q_dup_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[4];
    simde_poly64_t unused[4];
    simde_poly64_t r[4][2];
  } test_vec[] = {
     { {  SIMDE_POLY64_C(19415023), SIMDE_POLY64_C(134986722), SIMDE_POLY64_C(140423989), SIMDE_POLY64_C(194366613) },
       {  SIMDE_POLY64_C(29748623), SIMDE_POLY64_C(63792851), SIMDE_POLY64_C(184798224), SIMDE_POLY64_C(170880801)},
     { {  SIMDE_POLY64_C(19415023), SIMDE_POLY64_C(19415023) },
       {  SIMDE_POLY64_C(134986722), SIMDE_POLY64_C(134986722) },
       {  SIMDE_POLY64_C(140423989), SIMDE_POLY64_C(140423989) },
       {  SIMDE_POLY64_C(194366613), SIMDE_POLY64_C(194366613) } } },
     { {  SIMDE_POLY64_C(72477781), SIMDE_POLY64_C(119998170), SIMDE_POLY64_C(19598295), SIMDE_POLY64_C(4615743) },
       {  SIMDE_POLY64_C(153105690), SIMDE_POLY64_C(4212704), SIMDE_POLY64_C(31753299), SIMDE_POLY64_C(100870623)},
     { {  SIMDE_POLY64_C(72477781), SIMDE_POLY64_C(72477781) },
       {  SIMDE_POLY64_C(119998170), SIMDE_POLY64_C(119998170) },
       {  SIMDE_POLY64_C(19598295), SIMDE_POLY64_C(19598295) },
       {  SIMDE_POLY64_C(4615743), SIMDE_POLY64_C(4615743) } } },
     { {  SIMDE_POLY64_C(83267470), SIMDE_POLY64_C(184004374), SIMDE_POLY64_C(3865768), SIMDE_POLY64_C(20318927) },
       {  SIMDE_POLY64_C(101590415), SIMDE_POLY64_C(123726578), SIMDE_POLY64_C(162433497), SIMDE_POLY64_C(54552934)},
     { {  SIMDE_POLY64_C(83267470), SIMDE_POLY64_C(83267470) },
       {  SIMDE_POLY64_C(184004374), SIMDE_POLY64_C(184004374) },
       {  SIMDE_POLY64_C(3865768), SIMDE_POLY64_C(3865768) },
       {  SIMDE_POLY64_C(20318927), SIMDE_POLY64_C(20318927) } } },
     { {  SIMDE_POLY64_C(39898183), SIMDE_POLY64_C(62216994), SIMDE_POLY64_C(153003397), SIMDE_POLY64_C(181219988) },
       {  SIMDE_POLY64_C(150010328), SIMDE_POLY64_C(105260849), SIMDE_POLY64_C(187591910), SIMDE_POLY64_C(59479289)},
     { {  SIMDE_POLY64_C(39898183), SIMDE_POLY64_C(39898183) },
       {  SIMDE_POLY64_C(62216994), SIMDE_POLY64_C(62216994) },
       {  SIMDE_POLY64_C(153003397), SIMDE_POLY64_C(153003397) },
       {  SIMDE_POLY64_C(181219988), SIMDE_POLY64_C(181219988) } } },
     { {  SIMDE_POLY64_C(94456081), SIMDE_POLY64_C(158574380), SIMDE_POLY64_C(117246539), SIMDE_POLY64_C(195475124) },
       {  SIMDE_POLY64_C(45127472), SIMDE_POLY64_C(38196881), SIMDE_POLY64_C(167589198), SIMDE_POLY64_C(56546110)},
     { {  SIMDE_POLY64_C(94456081), SIMDE_POLY64_C(94456081) },
       {  SIMDE_POLY64_C(158574380), SIMDE_POLY64_C(158574380) },
       {  SIMDE_POLY64_C(117246539), SIMDE_POLY64_C(117246539) },
       {  SIMDE_POLY64_C(195475124), SIMDE_POLY64_C(195475124) } } },
     { {  SIMDE_POLY64_C(84845160), SIMDE_POLY64_C(183689028), SIMDE_POLY64_C(107358519), SIMDE_POLY64_C(141662487) },
       {  SIMDE_POLY64_C(124767939), SIMDE_POLY64_C(127494288), SIMDE_POLY64_C(109530805), SIMDE_POLY64_C(73133350)},
     { {  SIMDE_POLY64_C(84845160), SIMDE_POLY64_C(84845160) },
       {  SIMDE_POLY64_C(183689028), SIMDE_POLY64_C(183689028) },
       {  SIMDE_POLY64_C(107358519), SIMDE_POLY64_C(107358519) },
       {  SIMDE_POLY64_C(141662487), SIMDE_POLY64_C(141662487) } } },
     { {  SIMDE_POLY64_C(126339519), SIMDE_POLY64_C(795258), SIMDE_POLY64_C(46341725), SIMDE_POLY64_C(117764884) },
       {  SIMDE_POLY64_C(114711556), SIMDE_POLY64_C(24833869), SIMDE_POLY64_C(26165703), SIMDE_POLY64_C(104429137)},
     { {  SIMDE_POLY64_C(126339519), SIMDE_POLY64_C(126339519) },
       {  SIMDE_POLY64_C(795258), SIMDE_POLY64_C(795258) },
       {  SIMDE_POLY64_C(46341725), SIMDE_POLY64_C(46341725) },
       {  SIMDE_POLY64_C(117764884), SIMDE_POLY64_C(117764884) } } },
     { {  SIMDE_POLY64_C(146405593), SIMDE_POLY64_C(135429224), SIMDE_POLY64_C(127955147), SIMDE_POLY64_C(56324641) },
       {  SIMDE_POLY64_C(39205962), SIMDE_POLY64_C(153262080), SIMDE_POLY64_C(163534203), SIMDE_POLY64_C(21735994)},
     { {  SIMDE_POLY64_C(146405593), SIMDE_POLY64_C(146405593) },
       {  SIMDE_POLY64_C(135429224), SIMDE_POLY64_C(135429224) },
       {  SIMDE_POLY64_C(127955147), SIMDE_POLY64_C(127955147) },
       {  SIMDE_POLY64_C(56324641), SIMDE_POLY64_C(56324641) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2x4_t r = simde_vld4q_dup_p64(test_vec[i].a);
    simde_poly64x2x4_t expected = {
        {simde_vld1q_p64(test_vec[i].r[0]), simde_vld1q_p64(test_vec[i].r[1]),
         simde_vld1q_p64(test_vec[i].r[2]), simde_vld1q_p64(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_p64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[2], expected.val[2]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[3], expected.val[3]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly64_t a[4];
    simde_poly64_t unused[4];
    simde_poly64x2x4_t r;
    simde_test_codegen_random_memory(32, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(32, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld4q_dup_p64(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp64(2, 4, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp64(2, 4, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld4_dup_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t a[4];
    simde_bfloat16_t unused[4];
    simde_bfloat16_t r[4][4];
  } test_vec[] = {
     { {  SIMDE_BFLOAT16_VALUE(48.08), SIMDE_BFLOAT16_VALUE(24.50), SIMDE_BFLOAT16_VALUE(47.79), SIMDE_BFLOAT16_VALUE(45.49) },
       {  SIMDE_BFLOAT16_VALUE(-22.72), SIMDE_BFLOAT16_VALUE(6.28), SIMDE_BFLOAT16_VALUE(-7.03), SIMDE_BFLOAT16_VALUE(41.06)},
     { {  SIMDE_BFLOAT16_VALUE(48.08), SIMDE_BFLOAT16_VALUE(48.08), SIMDE_BFLOAT16_VALUE(48.08), SIMDE_BFLOAT16_VALUE(48.08) },
       {  SIMDE_BFLOAT16_VALUE(24.50), SIMDE_BFLOAT16_VALUE(24.50), SIMDE_BFLOAT16_VALUE(24.50), SIMDE_BFLOAT16_VALUE(24.50) },
       {  SIMDE_BFLOAT16_VALUE(47.79), SIMDE_BFLOAT16_VALUE(47.79), SIMDE_BFLOAT16_VALUE(47.79), SIMDE_BFLOAT16_VALUE(47.79) },
       {  SIMDE_BFLOAT16_VALUE(45.49), SIMDE_BFLOAT16_VALUE(45.49), SIMDE_BFLOAT16_VALUE(45.49), SIMDE_BFLOAT16_VALUE(45.49) } } },
     { {  SIMDE_BFLOAT16_VALUE(41.90), SIMDE_BFLOAT16_VALUE(-45.37), SIMDE_BFLOAT16_VALUE(43.54), SIMDE_BFLOAT16_VALUE(10.59) },
       {  SIMDE_BFLOAT16_VALUE(36.07), SIMDE_BFLOAT16_VALUE(28.31), SIMDE_BFLOAT16_VALUE(-11.82), SIMDE_BFLOAT16_VALUE(-16.27)},
     { {  SIMDE_BFLOAT16_VALUE(41.90), SIMDE_BFLOAT16_VALUE(41.90), SIMDE_BFLOAT16_VALUE(41.90), SIMDE_BFLOAT16_VALUE(41.90) },
       {  SIMDE_BFLOAT16_VALUE(-45.37), SIMDE_BFLOAT16_VALUE(-45.37), SIMDE_BFLOAT16_VALUE(-45.37), SIMDE_BFLOAT16_VALUE(-45.37) },
       {  SIMDE_BFLOAT16_VALUE(43.54), SIMDE_BFLOAT16_VALUE(43.54), SIMDE_BFLOAT16_VALUE(43.54), SIMDE_BFLOAT16_VALUE(43.54) },
       {  SIMDE_BFLOAT16_VALUE(10.59), SIMDE_BFLOAT16_VALUE(10.59), SIMDE_BFLOAT16_VALUE(10.59), SIMDE_BFLOAT16_VALUE(10.59) } } },
     { {  SIMDE_BFLOAT16_VALUE(3.73), SIMDE_BFLOAT16_VALUE(-41.80), SIMDE_BFLOAT16_VALUE(16.45), SIMDE_BFLOAT16_VALUE(28.24) },
       {  SIMDE_BFLOAT16_VALUE(14.07), SIMDE_BFLOAT16_VALUE(-1.72), SIMDE_BFLOAT16_VALUE(-31.48), SIMDE_BFLOAT16_VALUE(-4.95)},
     { {  SIMDE_BFLOAT16_VALUE(3.73), SIMDE_BFLOAT16_VALUE(3.73), SIMDE_BFLOAT16_VALUE(3.73), SIMDE_BFLOAT16_VALUE(3.73) },
       {  SIMDE_BFLOAT16_VALUE(-41.80), SIMDE_BFLOAT16_VALUE(-41.80), SIMDE_BFLOAT16_VALUE(-41.80), SIMDE_BFLOAT16_VALUE(-41.80) },
       {  SIMDE_BFLOAT16_VALUE(16.45), SIMDE_BFLOAT16_VALUE(16.45), SIMDE_BFLOAT16_VALUE(16.45), SIMDE_BFLOAT16_VALUE(16.45) },
       {  SIMDE_BFLOAT16_VALUE(28.24), SIMDE_BFLOAT16_VALUE(28.24), SIMDE_BFLOAT16_VALUE(28.24), SIMDE_BFLOAT16_VALUE(28.24) } } },
     { {  SIMDE_BFLOAT16_VALUE(-14.57), SIMDE_BFLOAT16_VALUE(15.78), SIMDE_BFLOAT16_VALUE(3.71), SIMDE_BFLOAT16_VALUE(-44.25) },
       {  SIMDE_BFLOAT16_VALUE(30.42), SIMDE_BFLOAT16_VALUE(7.31), SIMDE_BFLOAT16_VALUE(-31.88), SIMDE_BFLOAT16_VALUE(23.92)},
     { {  SIMDE_BFLOAT16_VALUE(-14.57), SIMDE_BFLOAT16_VALUE(-14.57), SIMDE_BFLOAT16_VALUE(-14.57), SIMDE_BFLOAT16_VALUE(-14.57) },
       {  SIMDE_BFLOAT16_VALUE(15.78), SIMDE_BFLOAT16_VALUE(15.78), SIMDE_BFLOAT16_VALUE(15.78), SIMDE_BFLOAT16_VALUE(15.78) },
       {  SIMDE_BFLOAT16_VALUE(3.71), SIMDE_BFLOAT16_VALUE(3.71), SIMDE_BFLOAT16_VALUE(3.71), SIMDE_BFLOAT16_VALUE(3.71) },
       {  SIMDE_BFLOAT16_VALUE(-44.25), SIMDE_BFLOAT16_VALUE(-44.25), SIMDE_BFLOAT16_VALUE(-44.25), SIMDE_BFLOAT16_VALUE(-44.25) } } },
     { {  SIMDE_BFLOAT16_VALUE(-7.08), SIMDE_BFLOAT16_VALUE(-13.75), SIMDE_BFLOAT16_VALUE(-46.19), SIMDE_BFLOAT16_VALUE(14.37) },
       {  SIMDE_BFLOAT16_VALUE(-44.62), SIMDE_BFLOAT16_VALUE(-35.77), SIMDE_BFLOAT16_VALUE(-19.37), SIMDE_BFLOAT16_VALUE(18.25)},
     { {  SIMDE_BFLOAT16_VALUE(-7.08), SIMDE_BFLOAT16_VALUE(-7.08), SIMDE_BFLOAT16_VALUE(-7.08), SIMDE_BFLOAT16_VALUE(-7.08) },
       {  SIMDE_BFLOAT16_VALUE(-13.75), SIMDE_BFLOAT16_VALUE(-13.75), SIMDE_BFLOAT16_VALUE(-13.75), SIMDE_BFLOAT16_VALUE(-13.75) },
       {  SIMDE_BFLOAT16_VALUE(-46.19), SIMDE_BFLOAT16_VALUE(-46.19), SIMDE_BFLOAT16_VALUE(-46.19), SIMDE_BFLOAT16_VALUE(-46.19) },
       {  SIMDE_BFLOAT16_VALUE(14.37), SIMDE_BFLOAT16_VALUE(14.37), SIMDE_BFLOAT16_VALUE(14.37), SIMDE_BFLOAT16_VALUE(14.37) } } },
     { {  SIMDE_BFLOAT16_VALUE(-41.21), SIMDE_BFLOAT16_VALUE(23.55), SIMDE_BFLOAT16_VALUE(-20.74), SIMDE_BFLOAT16_VALUE(31.91) },
       {  SIMDE_BFLOAT16_VALUE(-5.45), SIMDE_BFLOAT16_VALUE(-43.69), SIMDE_BFLOAT16_VALUE(1.07), SIMDE_BFLOAT16_VALUE(-15.34)},
     { {  SIMDE_BFLOAT16_VALUE(-41.21), SIMDE_BFLOAT16_VALUE(-41.21), SIMDE_BFLOAT16_VALUE(-41.21), SIMDE_BFLOAT16_VALUE(-41.21) },
       {  SIMDE_BFLOAT16_VALUE(23.55), SIMDE_BFLOAT16_VALUE(23.55), SIMDE_BFLOAT16_VALUE(23.55), SIMDE_BFLOAT16_VALUE(23.55) },
       {  SIMDE_BFLOAT16_VALUE(-20.74), SIMDE_BFLOAT16_VALUE(-20.74), SIMDE_BFLOAT16_VALUE(-20.74), SIMDE_BFLOAT16_VALUE(-20.74) },
       {  SIMDE_BFLOAT16_VALUE(31.91), SIMDE_BFLOAT16_VALUE(31.91), SIMDE_BFLOAT16_VALUE(31.91), SIMDE_BFLOAT16_VALUE(31.91) } } },
     { {  SIMDE_BFLOAT16_VALUE(12.19), SIMDE_BFLOAT16_VALUE(-39.62), SIMDE_BFLOAT16_VALUE(26.35), SIMDE_BFLOAT16_VALUE(24.05) },
       {  SIMDE_BFLOAT16_VALUE(14.14), SIMDE_BFLOAT16_VALUE(-6.68), SIMDE_BFLOAT16_VALUE(-34.58), SIMDE_BFLOAT16_VALUE(17.64)},
     { {  SIMDE_BFLOAT16_VALUE(12.19), SIMDE_BFLOAT16_VALUE(12.19), SIMDE_BFLOAT16_VALUE(12.19), SIMDE_BFLOAT16_VALUE(12.19) },
       {  SIMDE_BFLOAT16_VALUE(-39.62), SIMDE_BFLOAT16_VALUE(-39.62), SIMDE_BFLOAT16_VALUE(-39.62), SIMDE_BFLOAT16_VALUE(-39.62) },
       {  SIMDE_BFLOAT16_VALUE(26.35), SIMDE_BFLOAT16_VALUE(26.35), SIMDE_BFLOAT16_VALUE(26.35), SIMDE_BFLOAT16_VALUE(26.35) },
       {  SIMDE_BFLOAT16_VALUE(24.05), SIMDE_BFLOAT16_VALUE(24.05), SIMDE_BFLOAT16_VALUE(24.05), SIMDE_BFLOAT16_VALUE(24.05) } } },
     { {  SIMDE_BFLOAT16_VALUE(32.66), SIMDE_BFLOAT16_VALUE(22.65), SIMDE_BFLOAT16_VALUE(-23.52), SIMDE_BFLOAT16_VALUE(8.31) },
       {  SIMDE_BFLOAT16_VALUE(-26.83), SIMDE_BFLOAT16_VALUE(-6.25), SIMDE_BFLOAT16_VALUE(38.29), SIMDE_BFLOAT16_VALUE(-48.88)},
     { {  SIMDE_BFLOAT16_VALUE(32.66), SIMDE_BFLOAT16_VALUE(32.66), SIMDE_BFLOAT16_VALUE(32.66), SIMDE_BFLOAT16_VALUE(32.66) },
       {  SIMDE_BFLOAT16_VALUE(22.65), SIMDE_BFLOAT16_VALUE(22.65), SIMDE_BFLOAT16_VALUE(22.65), SIMDE_BFLOAT16_VALUE(22.65) },
       {  SIMDE_BFLOAT16_VALUE(-23.52), SIMDE_BFLOAT16_VALUE(-23.52), SIMDE_BFLOAT16_VALUE(-23.52), SIMDE_BFLOAT16_VALUE(-23.52) },
       {  SIMDE_BFLOAT16_VALUE(8.31), SIMDE_BFLOAT16_VALUE(8.31), SIMDE_BFLOAT16_VALUE(8.31), SIMDE_BFLOAT16_VALUE(8.31) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4x4_t r = simde_vld4_dup_bf16(test_vec[i].a);
    simde_bfloat16x4x4_t expected = {
        {simde_vld1_bf16(test_vec[i].r[0]), simde_vld1_bf16(test_vec[i].r[1]),
         simde_vld1_bf16(test_vec[i].r[2]), simde_vld1_bf16(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_bf16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[2], expected.val[2], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[3], expected.val[3], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld4q_dup_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t a[4];
    simde_bfloat16_t unused[4];
    simde_bfloat16_t r[4][8];
  } test_vec[] = {
     { {  SIMDE_BFLOAT16_VALUE(31.40), SIMDE_BFLOAT16_VALUE(8.80), SIMDE_BFLOAT16_VALUE(7.89), SIMDE_BFLOAT16_VALUE(12.74) },
       {  SIMDE_BFLOAT16_VALUE(-0.13), SIMDE_BFLOAT16_VALUE(-35.35), SIMDE_BFLOAT16_VALUE(41.40), SIMDE_BFLOAT16_VALUE(18.27)},
     { {  SIMDE_BFLOAT16_VALUE(31.40), SIMDE_BFLOAT16_VALUE(31.40), SIMDE_BFLOAT16_VALUE(31.40), SIMDE_BFLOAT16_VALUE(31.40),
        SIMDE_BFLOAT16_VALUE(31.40), SIMDE_BFLOAT16_VALUE(31.40), SIMDE_BFLOAT16_VALUE(31.40), SIMDE_BFLOAT16_VALUE(31.40) },
       {  SIMDE_BFLOAT16_VALUE(8.80), SIMDE_BFLOAT16_VALUE(8.80), SIMDE_BFLOAT16_VALUE(8.80), SIMDE_BFLOAT16_VALUE(8.80),
        SIMDE_BFLOAT16_VALUE(8.80), SIMDE_BFLOAT16_VALUE(8.80), SIMDE_BFLOAT16_VALUE(8.80), SIMDE_BFLOAT16_VALUE(8.80) },
       {  SIMDE_BFLOAT16_VALUE(7.89), SIMDE_BFLOAT16_VALUE(7.89), SIMDE_BFLOAT16_VALUE(7.89), SIMDE_BFLOAT16_VALUE(7.89),
        SIMDE_BFLOAT16_VALUE(7.89), SIMDE_BFLOAT16_VALUE(7.89), SIMDE_BFLOAT16_VALUE(7.89), SIMDE_BFLOAT16_VALUE(7.89) },
       {  SIMDE_BFLOAT16_VALUE(12.74), SIMDE_BFLOAT16_VALUE(12.74), SIMDE_BFLOAT16_VALUE(12.74), SIMDE_BFLOAT16_VALUE(12.74),
        SIMDE_BFLOAT16_VALUE(12.74), SIMDE_BFLOAT16_VALUE(12.74), SIMDE_BFLOAT16_VALUE(12.74), SIMDE_BFLOAT16_VALUE(12.74) } } },
     { {  SIMDE_BFLOAT16_VALUE(42.40), SIMDE_BFLOAT16_VALUE(-29.63), SIMDE_BFLOAT16_VALUE(30.06), SIMDE_BFLOAT16_VALUE(1.39) },
       {  SIMDE_BFLOAT16_VALUE(31.88), SIMDE_BFLOAT16_VALUE(-49.31), SIMDE_BFLOAT16_VALUE(23.96), SIMDE_BFLOAT16_VALUE(-45.98)},
     { {  SIMDE_BFLOAT16_VALUE(42.40), SIMDE_BFLOAT16_VALUE(42.40), SIMDE_BFLOAT16_VALUE(42.40), SIMDE_BFLOAT16_VALUE(42.40),
        SIMDE_BFLOAT16_VALUE(42.40), SIMDE_BFLOAT16_VALUE(42.40), SIMDE_BFLOAT16_VALUE(42.40), SIMDE_BFLOAT16_VALUE(42.40) },
       {  SIMDE_BFLOAT16_VALUE(-29.63), SIMDE_BFLOAT16_VALUE(-29.63), SIMDE_BFLOAT16_VALUE(-29.63), SIMDE_BFLOAT16_VALUE(-29.63),
        SIMDE_BFLOAT16_VALUE(-29.63), SIMDE_BFLOAT16_VALUE(-29.63), SIMDE_BFLOAT16_VALUE(-29.63), SIMDE_BFLOAT16_VALUE(-29.63) },
       {  SIMDE_BFLOAT16_VALUE(30.06), SIMDE_BFLOAT16_VALUE(30.06), SIMDE_BFLOAT16_VALUE(30.06), SIMDE_BFLOAT16_VALUE(30.06),
        SIMDE_BFLOAT16_VALUE(30.06), SIMDE_BFLOAT16_VALUE(30.06), SIMDE_BFLOAT16_VALUE(30.06), SIMDE_BFLOAT16_VALUE(30.06) },
       {  SIMDE_BFLOAT16_VALUE(1.39), SIMDE_BFLOAT16_VALUE(1.39), SIMDE_BFLOAT16_VALUE(1.39), SIMDE_BFLOAT16_VALUE(1.39),
        SIMDE_BFLOAT16_VALUE(1.39), SIMDE_BFLOAT16_VALUE(1.39), SIMDE_BFLOAT16_VALUE(1.39), SIMDE_BFLOAT16_VALUE(1.39) } } },
     { {  SIMDE_BFLOAT16_VALUE(-19.20), SIMDE_BFLOAT16_VALUE(-9.05), SIMDE_BFLOAT16_VALUE(0.57), SIMDE_BFLOAT16_VALUE(14.82) },
       {  SIMDE_BFLOAT16_VALUE(-38.07), SIMDE_BFLOAT16_VALUE(-33.07), SIMDE_BFLOAT16_VALUE(15.20), SIMDE_BFLOAT16_VALUE(3.67)},
     { {  SIMDE_BFLOAT16_VALUE(-19.20), SIMDE_BFLOAT16_VALUE(-19.20), SIMDE_BFLOAT16_VALUE(-19.20), SIMDE_BFLOAT16_VALUE(-19.20),
        SIMDE_BFLOAT16_VALUE(-19.20), SIMDE_BFLOAT16_VALUE(-19.20), SIMDE_BFLOAT16_VALUE(-19.20), SIMDE_BFLOAT16_VALUE(-19.20) },
       {  SIMDE_BFLOAT16_VALUE(-9.05), SIMDE_BFLOAT16_VALUE(-9.05), SIMDE_BFLOAT16_VALUE(-9.05), SIMDE_BFLOAT16_VALUE(-9.05),
        SIMDE_BFLOAT16_VALUE(-9.05), SIMDE_BFLOAT16_VALUE(-9.05), SIMDE_BFLOAT16_VALUE(-9.05), SIMDE_BFLOAT16_VALUE(-9.05) },
       {  SIMDE_BFLOAT16_VALUE(0.57), SIMDE_BFLOAT16_VALUE(0.57), SIMDE_BFLOAT16_VALUE(0.57), SIMDE_BFLOAT16_VALUE(0.57),
        SIMDE_BFLOAT16_VALUE(0.57), SIMDE_BFLOAT16_VALUE(0.57), SIMDE_BFLOAT16_VALUE(0.57), SIMDE_BFLOAT16_VALUE(0.57) },
       {  SIMDE_BFLOAT16_VALUE(14.82), SIMDE_BFLOAT16_VALUE(14.82), SIMDE_BFLOAT16_VALUE(14.82), SIMDE_BFLOAT16_VALUE(14.82),
        SIMDE_BFLOAT16_VALUE(14.82), SIMDE_BFLOAT16_VALUE(14.82), SIMDE_BFLOAT16_VALUE(14.82), SIMDE_BFLOAT16_VALUE(14.82) } } },
     { {  SIMDE_BFLOAT16_VALUE(-12.11), SIMDE_BFLOAT16_VALUE(15.24), SIMDE_BFLOAT16_VALUE(34.23), SIMDE_BFLOAT16_VALUE(38.58) },
       {  SIMDE_BFLOAT16_VALUE(46.28), SIMDE_BFLOAT16_VALUE(-11.22), SIMDE_BFLOAT16_VALUE(21.51), SIMDE_BFLOAT16_VALUE(-3.08)},
     { {  SIMDE_BFLOAT16_VALUE(-12.11), SIMDE_BFLOAT16_VALUE(-12.11), SIMDE_BFLOAT16_VALUE(-12.11), SIMDE_BFLOAT16_VALUE(-12.11),
        SIMDE_BFLOAT16_VALUE(-12.11), SIMDE_BFLOAT16_VALUE(-12.11), SIMDE_BFLOAT16_VALUE(-12.11), SIMDE_BFLOAT16_VALUE(-12.11) },
       {  SIMDE_BFLOAT16_VALUE(15.24), SIMDE_BFLOAT16_VALUE(15.24), SIMDE_BFLOAT16_VALUE(15.24), SIMDE_BFLOAT16_VALUE(15.24),
        SIMDE_BFLOAT16_VALUE(15.24), SIMDE_BFLOAT16_VALUE(15.24), SIMDE_BFLOAT16_VALUE(15.24), SIMDE_BFLOAT16_VALUE(15.24) },
       {  SIMDE_BFLOAT16_VALUE(34.23), SIMDE_BFLOAT16_VALUE(34.23), SIMDE_BFLOAT16_VALUE(34.23), SIMDE_BFLOAT16_VALUE(34.23),
        SIMDE_BFLOAT16_VALUE(34.23), SIMDE_BFLOAT16_VALUE(34.23), SIMDE_BFLOAT16_VALUE(34.23), SIMDE_BFLOAT16_VALUE(34.23) },
       {  SIMDE_BFLOAT16_VALUE(38.58), SIMDE_BFLOAT16_VALUE(38.58), SIMDE_BFLOAT16_VALUE(38.58), SIMDE_BFLOAT16_VALUE(38.58),
        SIMDE_BFLOAT16_VALUE(38.58), SIMDE_BFLOAT16_VALUE(38.58), SIMDE_BFLOAT16_VALUE(38.58), SIMDE_BFLOAT16_VALUE(38.58) } } },
     { {  SIMDE_BFLOAT16_VALUE(-16.90), SIMDE_BFLOAT16_VALUE(45.87), SIMDE_BFLOAT16_VALUE(4.55), SIMDE_BFLOAT16_VALUE(-31.32) },
       {  SIMDE_BFLOAT16_VALUE(-4.72), SIMDE_BFLOAT16_VALUE(28.72), SIMDE_BFLOAT16_VALUE(26.60), SIMDE_BFLOAT16_VALUE(-42.54)},
     { {  SIMDE_BFLOAT16_VALUE(-16.90), SIMDE_BFLOAT16_VALUE(-16.90), SIMDE_BFLOAT16_VALUE(-16.90), SIMDE_BFLOAT16_VALUE(-16.90),
        SIMDE_BFLOAT16_VALUE(-16.90), SIMDE_BFLOAT16_VALUE(-16.90), SIMDE_BFLOAT16_VALUE(-16.90), SIMDE_BFLOAT16_VALUE(-16.90) },
       {  SIMDE_BFLOAT16_VALUE(45.87), SIMDE_BFLOAT16_VALUE(45.87), SIMDE_BFLOAT16_VALUE(45.87), SIMDE_BFLOAT16_VALUE(45.87),
        SIMDE_BFLOAT16_VALUE(45.87), SIMDE_BFLOAT16_VALUE(45.87), SIMDE_BFLOAT16_VALUE(45.87), SIMDE_BFLOAT16_VALUE(45.87) },
       {  SIMDE_BFLOAT16_VALUE(4.55), SIMDE_BFLOAT16_VALUE(4.55), SIMDE_BFLOAT16_VALUE(4.55), SIMDE_BFLOAT16_VALUE(4.55),
        SIMDE_BFLOAT16_VALUE(4.55), SIMDE_BFLOAT16_VALUE(4.55), SIMDE_BFLOAT16_VALUE(4.55), SIMDE_BFLOAT16_VALUE(4.55) },
       {  SIMDE_BFLOAT16_VALUE(-31.32), SIMDE_BFLOAT16_VALUE(-31.32), SIMDE_BFLOAT16_VALUE(-31.32), SIMDE_BFLOAT16_VALUE(-31.32),
        SIMDE_BFLOAT16_VALUE(-31.32), SIMDE_BFLOAT16_VALUE(-31.32), SIMDE_BFLOAT16_VALUE(-31.32), SIMDE_BFLOAT16_VALUE(-31.32) } } },
     { {  SIMDE_BFLOAT16_VALUE(19.79), SIMDE_BFLOAT16_VALUE(20.65), SIMDE_BFLOAT16_VALUE(-41.73), SIMDE_BFLOAT16_VALUE(27.61) },
       {  SIMDE_BFLOAT16_VALUE(-46.55), SIMDE_BFLOAT16_VALUE(-27.42), SIMDE_BFLOAT16_VALUE(0.86), SIMDE_BFLOAT16_VALUE(11.71)},
     { {  SIMDE_BFLOAT16_VALUE(19.79), SIMDE_BFLOAT16_VALUE(19.79), SIMDE_BFLOAT16_VALUE(19.79), SIMDE_BFLOAT16_VALUE(19.79),
        SIMDE_BFLOAT16_VALUE(19.79), SIMDE_BFLOAT16_VALUE(19.79), SIMDE_BFLOAT16_VALUE(19.79), SIMDE_BFLOAT16_VALUE(19.79) },
       {  SIMDE_BFLOAT16_VALUE(20.65), SIMDE_BFLOAT16_VALUE(20.65), SIMDE_BFLOAT16_VALUE(20.65), SIMDE_BFLOAT16_VALUE(20.65),
        SIMDE_BFLOAT16_VALUE(20.65), SIMDE_BFLOAT16_VALUE(20.65), SIMDE_BFLOAT16_VALUE(20.65), SIMDE_BFLOAT16_VALUE(20.65) },
       {  SIMDE_BFLOAT16_VALUE(-41.73), SIMDE_BFLOAT16_VALUE(-41.73), SIMDE_BFLOAT16_VALUE(-41.73), SIMDE_BFLOAT16_VALUE(-41.73),
        SIMDE_BFLOAT16_VALUE(-41.73), SIMDE_BFLOAT16_VALUE(-41.73), SIMDE_BFLOAT16_VALUE(-41.73), SIMDE_BFLOAT16_VALUE(-41.73) },
       {  SIMDE_BFLOAT16_VALUE(27.61), SIMDE_BFLOAT16_VALUE(27.61), SIMDE_BFLOAT16_VALUE(27.61), SIMDE_BFLOAT16_VALUE(27.61),
        SIMDE_BFLOAT16_VALUE(27.61), SIMDE_BFLOAT16_VALUE(27.61), SIMDE_BFLOAT16_VALUE(27.61), SIMDE_BFLOAT16_VALUE(27.61) } } },
     { {  SIMDE_BFLOAT16_VALUE(33.12), SIMDE_BFLOAT16_VALUE(-27.38), SIMDE_BFLOAT16_VALUE(15.63), SIMDE_BFLOAT16_VALUE(-26.25) },
       {  SIMDE_BFLOAT16_VALUE(-46.48), SIMDE_BFLOAT16_VALUE(13.65), SIMDE_BFLOAT16_VALUE(3.92), SIMDE_BFLOAT16_VALUE(39.42)},
     { {  SIMDE_BFLOAT16_VALUE(33.12), SIMDE_BFLOAT16_VALUE(33.12), SIMDE_BFLOAT16_VALUE(33.12), SIMDE_BFLOAT16_VALUE(33.12),
        SIMDE_BFLOAT16_VALUE(33.12), SIMDE_BFLOAT16_VALUE(33.12), SIMDE_BFLOAT16_VALUE(33.12), SIMDE_BFLOAT16_VALUE(33.12) },
       {  SIMDE_BFLOAT16_VALUE(-27.38), SIMDE_BFLOAT16_VALUE(-27.38), SIMDE_BFLOAT16_VALUE(-27.38), SIMDE_BFLOAT16_VALUE(-27.38),
        SIMDE_BFLOAT16_VALUE(-27.38), SIMDE_BFLOAT16_VALUE(-27.38), SIMDE_BFLOAT16_VALUE(-27.38), SIMDE_BFLOAT16_VALUE(-27.38) },
       {  SIMDE_BFLOAT16_VALUE(15.63), SIMDE_BFLOAT16_VALUE(15.63), SIMDE_BFLOAT16_VALUE(15.63), SIMDE_BFLOAT16_VALUE(15.63),
        SIMDE_BFLOAT16_VALUE(15.63), SIMDE_BFLOAT16_VALUE(15.63), SIMDE_BFLOAT16_VALUE(15.63), SIMDE_BFLOAT16_VALUE(15.63) },
       {  SIMDE_BFLOAT16_VALUE(-26.25), SIMDE_BFLOAT16_VALUE(-26.25), SIMDE_BFLOAT16_VALUE(-26.25), SIMDE_BFLOAT16_VALUE(-26.25),
        SIMDE_BFLOAT16_VALUE(-26.25), SIMDE_BFLOAT16_VALUE(-26.25), SIMDE_BFLOAT16_VALUE(-26.25), SIMDE_BFLOAT16_VALUE(-26.25) } } },
     { {  SIMDE_BFLOAT16_VALUE(-9.54), SIMDE_BFLOAT16_VALUE(-43.91), SIMDE_BFLOAT16_VALUE(34.76), SIMDE_BFLOAT16_VALUE(30.47) },
       {  SIMDE_BFLOAT16_VALUE(44.27), SIMDE_BFLOAT16_VALUE(45.27), SIMDE_BFLOAT16_VALUE(47.81), SIMDE_BFLOAT16_VALUE(10.39)},
     { {  SIMDE_BFLOAT16_VALUE(-9.54), SIMDE_BFLOAT16_VALUE(-9.54), SIMDE_BFLOAT16_VALUE(-9.54), SIMDE_BFLOAT16_VALUE(-9.54),
        SIMDE_BFLOAT16_VALUE(-9.54), SIMDE_BFLOAT16_VALUE(-9.54), SIMDE_BFLOAT16_VALUE(-9.54), SIMDE_BFLOAT16_VALUE(-9.54) },
       {  SIMDE_BFLOAT16_VALUE(-43.91), SIMDE_BFLOAT16_VALUE(-43.91), SIMDE_BFLOAT16_VALUE(-43.91), SIMDE_BFLOAT16_VALUE(-43.91),
        SIMDE_BFLOAT16_VALUE(-43.91), SIMDE_BFLOAT16_VALUE(-43.91), SIMDE_BFLOAT16_VALUE(-43.91), SIMDE_BFLOAT16_VALUE(-43.91) },
       {  SIMDE_BFLOAT16_VALUE(34.76), SIMDE_BFLOAT16_VALUE(34.76), SIMDE_BFLOAT16_VALUE(34.76), SIMDE_BFLOAT16_VALUE(34.76),
        SIMDE_BFLOAT16_VALUE(34.76), SIMDE_BFLOAT16_VALUE(34.76), SIMDE_BFLOAT16_VALUE(34.76), SIMDE_BFLOAT16_VALUE(34.76) },
       {  SIMDE_BFLOAT16_VALUE(30.47), SIMDE_BFLOAT16_VALUE(30.47), SIMDE_BFLOAT16_VALUE(30.47), SIMDE_BFLOAT16_VALUE(30.47),
        SIMDE_BFLOAT16_VALUE(30.47), SIMDE_BFLOAT16_VALUE(30.47), SIMDE_BFLOAT16_VALUE(30.47), SIMDE_BFLOAT16_VALUE(30.47) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8x4_t r = simde_vld4q_dup_bf16(test_vec[i].a);
    simde_bfloat16x8x4_t expected = {
        {simde_vld1q_bf16(test_vec[i].r[0]), simde_vld1q_bf16(test_vec[i].r[1]),
         simde_vld1q_bf16(test_vec[i].r[2]), simde_vld1q_bf16(test_vec[i].r[3])}};

    simde_test_arm_neon_assert_equal_bf16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[2], expected.val[2], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[3], expected.val[3], INT_MAX);
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4_dup_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld4q_dup_bf16)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
