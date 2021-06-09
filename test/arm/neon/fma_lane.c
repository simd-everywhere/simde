#define SIMDE_TEST_ARM_NEON_INSN fma_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/fma_lane.h"

static int
test_simde_vfmad_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b;
    simde_float64_t v[1];
    simde_float64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -551.91),
      SIMDE_FLOAT64_C(   -88.98),
      { SIMDE_FLOAT64_C(  -739.25) },
      SIMDE_FLOAT64_C( 65226.56) },
    { SIMDE_FLOAT64_C(   976.90),
      SIMDE_FLOAT64_C(  -627.36),
      { SIMDE_FLOAT64_C(   686.54) },
      SIMDE_FLOAT64_C(-429730.83) },
    { SIMDE_FLOAT64_C(   187.07),
      SIMDE_FLOAT64_C(   241.14),
      { SIMDE_FLOAT64_C(   939.17) },
      SIMDE_FLOAT64_C(226658.52) },
    { SIMDE_FLOAT64_C(   252.34),
      SIMDE_FLOAT64_C(   299.82),
      { SIMDE_FLOAT64_C(  -987.26) },
      SIMDE_FLOAT64_C(-295747.95) },
    { SIMDE_FLOAT64_C(   407.64),
      SIMDE_FLOAT64_C(   173.41),
      { SIMDE_FLOAT64_C(  -310.88) },
      SIMDE_FLOAT64_C(-53502.06) },
    { SIMDE_FLOAT64_C(  -130.57),
      SIMDE_FLOAT64_C(   -33.95),
      { SIMDE_FLOAT64_C(   448.04) },
      SIMDE_FLOAT64_C(-15341.53) },
    { SIMDE_FLOAT64_C(  -511.27),
      SIMDE_FLOAT64_C(  -230.11),
      { SIMDE_FLOAT64_C(  -658.57) },
      SIMDE_FLOAT64_C(151032.27) },
    { SIMDE_FLOAT64_C(   647.26),
      SIMDE_FLOAT64_C(  -290.71),
      { SIMDE_FLOAT64_C(   731.29) },
      SIMDE_FLOAT64_C(-211946.06) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t r = simde_vfmad_lane_f64(test_vec[i].a, test_vec[i].b, simde_vld1_f64(test_vec[i].v), 0);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64_t b = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64x1_t v = simde_test_arm_neon_random_f64x1(-1000.0f, 1000.0f);
    simde_float64_t r = simde_vfmad_lane_f64(a, b, v, 0);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfmad_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    simde_float64_t b;
    simde_float64_t v[2];
    const int lane;
    simde_float64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(   663.90),
      SIMDE_FLOAT64_C(  -379.85),
      { SIMDE_FLOAT64_C(  -328.93), SIMDE_FLOAT64_C(   830.60) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(125607.96) },
    { SIMDE_FLOAT64_C(   719.94),
      SIMDE_FLOAT64_C(   289.28),
      { SIMDE_FLOAT64_C(  -394.82), SIMDE_FLOAT64_C(   161.00) },
       INT8_C(   1),
      SIMDE_FLOAT64_C( 47294.02) },
    { SIMDE_FLOAT64_C(   826.70),
      SIMDE_FLOAT64_C(   689.13),
      { SIMDE_FLOAT64_C(   640.02), SIMDE_FLOAT64_C(   835.07) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(441883.68) },
    { SIMDE_FLOAT64_C(  -899.27),
      SIMDE_FLOAT64_C(   -93.77),
      { SIMDE_FLOAT64_C(  -620.12), SIMDE_FLOAT64_C(  -907.53) },
       INT8_C(   1),
      SIMDE_FLOAT64_C( 84199.82) },
    { SIMDE_FLOAT64_C(  -144.47),
      SIMDE_FLOAT64_C(   376.21),
      { SIMDE_FLOAT64_C(   549.29), SIMDE_FLOAT64_C(  -109.58) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(206503.92) },
    { SIMDE_FLOAT64_C(  -607.55),
      SIMDE_FLOAT64_C(  -454.89),
      { SIMDE_FLOAT64_C(   956.37), SIMDE_FLOAT64_C(   212.37) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(-97212.54) },
    { SIMDE_FLOAT64_C(   157.08),
      SIMDE_FLOAT64_C(  -880.72),
      { SIMDE_FLOAT64_C(   474.67), SIMDE_FLOAT64_C(   653.18) },
       INT8_C(   0),
      SIMDE_FLOAT64_C(-417894.28) },
    { SIMDE_FLOAT64_C(   760.96),
      SIMDE_FLOAT64_C(   -18.45),
      { SIMDE_FLOAT64_C(   725.55), SIMDE_FLOAT64_C(   424.86) },
       INT8_C(   1),
      SIMDE_FLOAT64_C( -7077.71) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t r;
    simde_float64x2_t v = simde_vld1q_f64(test_vec[i].v);
    SIMDE_CONSTIFY_2_(simde_vfmad_laneq_f64, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, test_vec[i].b, v);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64_t b = simde_test_codegen_random_f64(-1000, 1000);
    simde_float64x2_t v = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64_t r;
    SIMDE_CONSTIFY_2_(simde_vfmad_laneq_f64, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b, v);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfmas_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b;
    simde_float32_t v[2];
    int lane;
    simde_float32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   601.71),
     SIMDE_FLOAT32_C(  -603.38),
     { SIMDE_FLOAT32_C(   255.46), SIMDE_FLOAT32_C(   321.65) },
      INT8_C(   0),
     SIMDE_FLOAT32_C(-153537.75) },
   { SIMDE_FLOAT32_C(   685.90),
     SIMDE_FLOAT32_C(   860.64),
     { SIMDE_FLOAT32_C(  -517.35), SIMDE_FLOAT32_C(   512.61) },
      INT8_C(   1),
     SIMDE_FLOAT32_C(441858.56) },
   { SIMDE_FLOAT32_C(   549.77),
     SIMDE_FLOAT32_C(  -877.34),
     { SIMDE_FLOAT32_C(   347.67), SIMDE_FLOAT32_C(   650.51) },
      INT8_C(   0),
     SIMDE_FLOAT32_C(-304475.06) },
   { SIMDE_FLOAT32_C(    28.89),
     SIMDE_FLOAT32_C(   727.56),
     { SIMDE_FLOAT32_C(   742.98), SIMDE_FLOAT32_C(   884.41) },
      INT8_C(   1),
     SIMDE_FLOAT32_C(643490.19) },
   { SIMDE_FLOAT32_C(   103.77),
     SIMDE_FLOAT32_C(   292.27),
     { SIMDE_FLOAT32_C(  -225.17), SIMDE_FLOAT32_C(   496.22) },
      INT8_C(   0),
     SIMDE_FLOAT32_C(-65706.66) },
   { SIMDE_FLOAT32_C(   837.39),
     SIMDE_FLOAT32_C(  -268.80),
     { SIMDE_FLOAT32_C(  -291.41), SIMDE_FLOAT32_C(    -5.53) },
      INT8_C(   1),
     SIMDE_FLOAT32_C(  2323.85) },
   { SIMDE_FLOAT32_C(  -149.51),
     SIMDE_FLOAT32_C(  -816.74),
     { SIMDE_FLOAT32_C(  -352.35), SIMDE_FLOAT32_C(  -388.55) },
      INT8_C(   0),
     SIMDE_FLOAT32_C(287628.84) },
   { SIMDE_FLOAT32_C(   164.81),
     SIMDE_FLOAT32_C(  -626.79),
     { SIMDE_FLOAT32_C(  -963.69), SIMDE_FLOAT32_C(  -233.48) },
      INT8_C(   1),
     SIMDE_FLOAT32_C(146507.73) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t v = simde_vld1_f32(test_vec[i].v);
    simde_float32_t r;
    SIMDE_CONSTIFY_2_(simde_vfmas_lane_f32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, test_vec[i].b, v);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32_t b = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32x2_t v = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32_t r;
    SIMDE_CONSTIFY_2_(simde_vfmas_lane_f32, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b, v);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfmas_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    simde_float32_t b;
    simde_float32_t v[4];
    int lane;
    simde_float32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(  -230.17),
      SIMDE_FLOAT32_C(   291.77),
      { SIMDE_FLOAT32_C(  -911.83), SIMDE_FLOAT32_C(  -544.27), SIMDE_FLOAT32_C(   152.41), SIMDE_FLOAT32_C(  -429.18) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(-266274.81) },
    { SIMDE_FLOAT32_C(   968.33),
      SIMDE_FLOAT32_C(  -297.82),
      { SIMDE_FLOAT32_C(  -306.52), SIMDE_FLOAT32_C(   316.00), SIMDE_FLOAT32_C(  -647.31), SIMDE_FLOAT32_C(   722.37) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(-93142.79) },
    { SIMDE_FLOAT32_C(    43.56),
      SIMDE_FLOAT32_C(  -904.33),
      { SIMDE_FLOAT32_C(   606.78), SIMDE_FLOAT32_C(  -852.67), SIMDE_FLOAT32_C(   387.94), SIMDE_FLOAT32_C(  -618.39) },
       INT8_C(   2),
      SIMDE_FLOAT32_C(-350782.22) },
    { SIMDE_FLOAT32_C(   643.55),
      SIMDE_FLOAT32_C(   225.33),
      { SIMDE_FLOAT32_C(   112.82), SIMDE_FLOAT32_C(  -647.86), SIMDE_FLOAT32_C(  -780.20), SIMDE_FLOAT32_C(   963.30) },
       INT8_C(   3),
      SIMDE_FLOAT32_C(217703.94) },
    { SIMDE_FLOAT32_C(  -464.60),
      SIMDE_FLOAT32_C(  -132.54),
      { SIMDE_FLOAT32_C(  -425.25), SIMDE_FLOAT32_C(   700.21), SIMDE_FLOAT32_C(   240.67), SIMDE_FLOAT32_C(  -388.94) },
       INT8_C(   0),
      SIMDE_FLOAT32_C( 55898.03) },
    { SIMDE_FLOAT32_C(  -533.27),
      SIMDE_FLOAT32_C(  -989.51),
      { SIMDE_FLOAT32_C(   902.82), SIMDE_FLOAT32_C(  -445.09), SIMDE_FLOAT32_C(  -533.78), SIMDE_FLOAT32_C(    55.23) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(439887.75) },
    { SIMDE_FLOAT32_C(   125.72),
      SIMDE_FLOAT32_C(  -565.45),
      { SIMDE_FLOAT32_C(   757.41), SIMDE_FLOAT32_C(   819.20), SIMDE_FLOAT32_C(   750.55), SIMDE_FLOAT32_C(  -889.90) },
       INT8_C(   2),
      SIMDE_FLOAT32_C(-424272.78) },
    { SIMDE_FLOAT32_C(   541.56),
      SIMDE_FLOAT32_C(  -205.89),
      { SIMDE_FLOAT32_C(  -794.23), SIMDE_FLOAT32_C(   148.34), SIMDE_FLOAT32_C(   -58.56), SIMDE_FLOAT32_C(   593.72) },
       INT8_C(   3),
      SIMDE_FLOAT32_C(-121699.45) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t v = simde_vld1q_f32(test_vec[i].v);
    simde_float32_t r;
    SIMDE_CONSTIFY_4_(simde_vfmas_laneq_f32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, test_vec[i].a, test_vec[i].b, v);
    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32_t b = simde_test_codegen_random_f32(-1000, 1000);
    simde_float32x4_t v = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_float32_t r;
    SIMDE_CONSTIFY_4_(simde_vfmas_laneq_f32, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b, v);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfma_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t b[2];
    simde_float32_t v[2];
    int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -176.16), SIMDE_FLOAT32_C(  -794.24) },
      { SIMDE_FLOAT32_C(  -281.91), SIMDE_FLOAT32_C(   129.44) },
      { SIMDE_FLOAT32_C(  -309.78), SIMDE_FLOAT32_C(   -74.83) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C( 87153.92), SIMDE_FLOAT32_C(-40892.16) } },
    { { SIMDE_FLOAT32_C(  -517.84), SIMDE_FLOAT32_C(  -770.38) },
      { SIMDE_FLOAT32_C(  -499.84), SIMDE_FLOAT32_C(   172.34) },
      { SIMDE_FLOAT32_C(  -588.69), SIMDE_FLOAT32_C(  -794.23) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(396470.06), SIMDE_FLOAT32_C(-137647.97) } },
    { { SIMDE_FLOAT32_C(  -726.64), SIMDE_FLOAT32_C(   811.77) },
      { SIMDE_FLOAT32_C(   870.49), SIMDE_FLOAT32_C(  -589.92) },
      { SIMDE_FLOAT32_C(   319.07), SIMDE_FLOAT32_C(   914.05) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(277020.59), SIMDE_FLOAT32_C(-187414.00) } },
    { { SIMDE_FLOAT32_C(   930.28), SIMDE_FLOAT32_C(   690.95) },
      { SIMDE_FLOAT32_C(  -793.18), SIMDE_FLOAT32_C(  -510.55) },
      { SIMDE_FLOAT32_C(    60.30), SIMDE_FLOAT32_C(   256.87) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-202813.86), SIMDE_FLOAT32_C(-130454.02) } },
    { { SIMDE_FLOAT32_C(   611.42), SIMDE_FLOAT32_C(  -737.34) },
      { SIMDE_FLOAT32_C(     3.67), SIMDE_FLOAT32_C(   675.59) },
      { SIMDE_FLOAT32_C(    33.21), SIMDE_FLOAT32_C(  -771.30) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(   733.30), SIMDE_FLOAT32_C( 21699.00) } },
    { { SIMDE_FLOAT32_C(  -481.45), SIMDE_FLOAT32_C(   857.05) },
      { SIMDE_FLOAT32_C(  -565.54), SIMDE_FLOAT32_C(   236.64) },
      { SIMDE_FLOAT32_C(   -13.51), SIMDE_FLOAT32_C(   124.68) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-70992.98), SIMDE_FLOAT32_C( 30361.32) } },
    { { SIMDE_FLOAT32_C(  -838.19), SIMDE_FLOAT32_C(   468.65) },
      { SIMDE_FLOAT32_C(   354.30), SIMDE_FLOAT32_C(  -338.03) },
      { SIMDE_FLOAT32_C(  -359.01), SIMDE_FLOAT32_C(   765.62) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-128035.43), SIMDE_FLOAT32_C(121824.80) } },
    { { SIMDE_FLOAT32_C(  -132.27), SIMDE_FLOAT32_C(   -85.66) },
      { SIMDE_FLOAT32_C(   577.38), SIMDE_FLOAT32_C(  -261.77) },
      { SIMDE_FLOAT32_C(   324.42), SIMDE_FLOAT32_C(  -103.55) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-59919.97), SIMDE_FLOAT32_C( 27020.62) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t v = simde_vld1_f32(test_vec[i].v);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vfma_lane_f32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000, 1000);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000, 1000);
    simde_float32x2_t v = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r;
    SIMDE_CONSTIFY_2_(simde_vfma_lane_f32, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b, v);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfma_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[1];
    simde_float64_t b[1];
    simde_float64_t v[1];
    simde_float64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -347.72) },
      { SIMDE_FLOAT64_C(   254.71) },
      { SIMDE_FLOAT64_C(  -412.60) },
      { SIMDE_FLOAT64_C(-105441.07) } },
    { { SIMDE_FLOAT64_C(  -140.90) },
      { SIMDE_FLOAT64_C(   744.16) },
      { SIMDE_FLOAT64_C(   647.70) },
      { SIMDE_FLOAT64_C(481851.53) } },
    { { SIMDE_FLOAT64_C(  -884.03) },
      { SIMDE_FLOAT64_C(   355.58) },
      { SIMDE_FLOAT64_C(   910.36) },
      { SIMDE_FLOAT64_C(322821.78) } },
    { { SIMDE_FLOAT64_C(   119.64) },
      { SIMDE_FLOAT64_C(    31.17) },
      { SIMDE_FLOAT64_C(   -56.43) },
      { SIMDE_FLOAT64_C( -1639.28) } },
    { { SIMDE_FLOAT64_C(   348.34) },
      { SIMDE_FLOAT64_C(   549.72) },
      { SIMDE_FLOAT64_C(  -199.38) },
      { SIMDE_FLOAT64_C(-109254.83) } },
    { { SIMDE_FLOAT64_C(   782.79) },
      { SIMDE_FLOAT64_C(  -213.64) },
      { SIMDE_FLOAT64_C(   787.12) },
      { SIMDE_FLOAT64_C(-167377.53) } },
    { { SIMDE_FLOAT64_C(   -92.53) },
      { SIMDE_FLOAT64_C(   -51.83) },
      { SIMDE_FLOAT64_C(   255.77) },
      { SIMDE_FLOAT64_C(-13349.09) } },
    { { SIMDE_FLOAT64_C(  -738.23) },
      { SIMDE_FLOAT64_C(   610.13) },
      { SIMDE_FLOAT64_C(   896.76) },
      { SIMDE_FLOAT64_C(546401.95) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t v = simde_vld1_f64(test_vec[i].v);
    simde_float64x1_t r = simde_vfma_lane_f64(simde_vld1_f64(test_vec[i].a), simde_vld1_f64(test_vec[i].b), v, 0);
    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000, 1000);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000, 1000);
    simde_float64x1_t v = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t r = simde_vfma_lane_f64(a, b, v, 0);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfma_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t b[2];
    simde_float32_t v[4];
    int lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   409.25), SIMDE_FLOAT32_C(  -302.87) },
      { SIMDE_FLOAT32_C(  -620.78), SIMDE_FLOAT32_C(  -471.96) },
      { SIMDE_FLOAT32_C(  -544.24), SIMDE_FLOAT32_C(   -56.37), SIMDE_FLOAT32_C(    65.67), SIMDE_FLOAT32_C(  -383.60) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(338262.56), SIMDE_FLOAT32_C(256556.62) } },
    { { SIMDE_FLOAT32_C(  -613.23), SIMDE_FLOAT32_C(   -92.94) },
      { SIMDE_FLOAT32_C(   824.73), SIMDE_FLOAT32_C(   251.66) },
      { SIMDE_FLOAT32_C(   269.58), SIMDE_FLOAT32_C(   726.84), SIMDE_FLOAT32_C(  -213.77), SIMDE_FLOAT32_C(   954.55) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(598833.50), SIMDE_FLOAT32_C(182823.62) } },
    { { SIMDE_FLOAT32_C(   478.28), SIMDE_FLOAT32_C(  -716.40) },
      { SIMDE_FLOAT32_C(  -263.63), SIMDE_FLOAT32_C(  -170.86) },
      { SIMDE_FLOAT32_C(   678.51), SIMDE_FLOAT32_C(   762.10), SIMDE_FLOAT32_C(   302.80), SIMDE_FLOAT32_C(   -57.32) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-79348.88), SIMDE_FLOAT32_C(-52452.80) } },
    { { SIMDE_FLOAT32_C(   143.08), SIMDE_FLOAT32_C(   789.85) },
      { SIMDE_FLOAT32_C(  -226.91), SIMDE_FLOAT32_C(   882.09) },
      { SIMDE_FLOAT32_C(   -74.30), SIMDE_FLOAT32_C(  -127.05), SIMDE_FLOAT32_C(  -334.68), SIMDE_FLOAT32_C(  -665.05) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(151049.58), SIMDE_FLOAT32_C(-585844.12) } },
    { { SIMDE_FLOAT32_C(   570.08), SIMDE_FLOAT32_C(    44.54) },
      { SIMDE_FLOAT32_C(  -137.01), SIMDE_FLOAT32_C(  -974.16) },
      { SIMDE_FLOAT32_C(   988.17), SIMDE_FLOAT32_C(   928.66), SIMDE_FLOAT32_C(  -357.76), SIMDE_FLOAT32_C(  -625.06) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-134819.08), SIMDE_FLOAT32_C(-962591.12) } },
    { { SIMDE_FLOAT32_C(  -164.29), SIMDE_FLOAT32_C(  -533.03) },
      { SIMDE_FLOAT32_C(   626.60), SIMDE_FLOAT32_C(  -894.71) },
      { SIMDE_FLOAT32_C(  -806.19), SIMDE_FLOAT32_C(  -587.17), SIMDE_FLOAT32_C(  -940.16), SIMDE_FLOAT32_C(   672.09) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-368085.00), SIMDE_FLOAT32_C(524813.81) } },
    { { SIMDE_FLOAT32_C(  -303.57), SIMDE_FLOAT32_C(  -203.78) },
      { SIMDE_FLOAT32_C(  -498.77), SIMDE_FLOAT32_C(  -625.06) },
      { SIMDE_FLOAT32_C(  -441.68), SIMDE_FLOAT32_C(   804.03), SIMDE_FLOAT32_C(   317.62), SIMDE_FLOAT32_C(   701.40) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-158722.89), SIMDE_FLOAT32_C(-198735.33) } },
    { { SIMDE_FLOAT32_C(   593.88), SIMDE_FLOAT32_C(  -909.29) },
      { SIMDE_FLOAT32_C(   583.49), SIMDE_FLOAT32_C(  -480.42) },
      { SIMDE_FLOAT32_C(   -36.33), SIMDE_FLOAT32_C(  -751.19), SIMDE_FLOAT32_C(  -145.48), SIMDE_FLOAT32_C(  -466.25) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(-271458.31), SIMDE_FLOAT32_C(223086.55) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t v = simde_vld1q_f32(test_vec[i].v);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vfma_laneq_f32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000, 1000);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000, 1000);
    simde_float32x4_t v = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x2_t r;
    SIMDE_CONSTIFY_4_(simde_vfma_laneq_f32, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b, v);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfma_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[1];
    simde_float64_t b[1];
    simde_float64_t v[2];
    int lane;
    simde_float64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   293.34) },
      { SIMDE_FLOAT64_C(   717.51) },
      { SIMDE_FLOAT64_C(  -440.41), SIMDE_FLOAT64_C(   281.51) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-315705.24) } },
    { { SIMDE_FLOAT64_C(   646.17) },
      { SIMDE_FLOAT64_C(   201.83) },
      { SIMDE_FLOAT64_C(   656.45), SIMDE_FLOAT64_C(  -518.12) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-103925.99) } },
    { { SIMDE_FLOAT64_C(   668.80) },
      { SIMDE_FLOAT64_C(   283.06) },
      { SIMDE_FLOAT64_C(  -412.83), SIMDE_FLOAT64_C(   862.61) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-116186.86) } },
    { { SIMDE_FLOAT64_C(   695.89) },
      { SIMDE_FLOAT64_C(  -352.99) },
      { SIMDE_FLOAT64_C(   534.70), SIMDE_FLOAT64_C(  -607.68) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(215200.85) } },
    { { SIMDE_FLOAT64_C(   443.23) },
      { SIMDE_FLOAT64_C(  -964.07) },
      { SIMDE_FLOAT64_C(  -232.74), SIMDE_FLOAT64_C(  -998.45) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(224820.88) } },
    { { SIMDE_FLOAT64_C(   839.96) },
      { SIMDE_FLOAT64_C(  -915.12) },
      { SIMDE_FLOAT64_C(   702.94), SIMDE_FLOAT64_C(   433.84) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-396175.70) } },
    { { SIMDE_FLOAT64_C(  -824.41) },
      { SIMDE_FLOAT64_C(   286.43) },
      { SIMDE_FLOAT64_C(   953.42), SIMDE_FLOAT64_C(   139.26) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(272263.68) } },
    { { SIMDE_FLOAT64_C(   535.24) },
      { SIMDE_FLOAT64_C(  -192.06) },
      { SIMDE_FLOAT64_C(   673.00), SIMDE_FLOAT64_C(  -171.42) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C( 33458.17) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t v = simde_vld1q_f64(test_vec[i].v);
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r;
    SIMDE_CONSTIFY_2_(simde_vfma_laneq_f64, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);
    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000, 1000);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000, 1000);
    simde_float64x2_t v = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x1_t r;
    SIMDE_CONSTIFY_2_(simde_vfma_laneq_f64, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b, v);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfmaq_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t b[4];
    simde_float32_t v[4];
    int lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -474.55), SIMDE_FLOAT32_C(  -767.41), SIMDE_FLOAT32_C(  -889.91), SIMDE_FLOAT32_C(  -828.38) },
      { SIMDE_FLOAT32_C(   434.42), SIMDE_FLOAT32_C(   766.55), SIMDE_FLOAT32_C(  -346.50), SIMDE_FLOAT32_C(   103.22) },
      { SIMDE_FLOAT32_C(    49.60), SIMDE_FLOAT32_C(   240.67), SIMDE_FLOAT32_C(   -34.17), SIMDE_FLOAT32_C(  -254.51) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C( 21072.68), SIMDE_FLOAT32_C( 37253.47), SIMDE_FLOAT32_C(-18076.31), SIMDE_FLOAT32_C(  4291.33) } },
    { { SIMDE_FLOAT32_C(   887.69), SIMDE_FLOAT32_C(  -499.48), SIMDE_FLOAT32_C(   137.81), SIMDE_FLOAT32_C(   330.92) },
      { SIMDE_FLOAT32_C(  -463.55), SIMDE_FLOAT32_C(   905.07), SIMDE_FLOAT32_C(   332.46), SIMDE_FLOAT32_C(  -623.59) },
      { SIMDE_FLOAT32_C(   989.95), SIMDE_FLOAT32_C(    35.41), SIMDE_FLOAT32_C(   810.24), SIMDE_FLOAT32_C(  -834.46) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-15526.62), SIMDE_FLOAT32_C( 31549.05), SIMDE_FLOAT32_C( 11910.22), SIMDE_FLOAT32_C(-21750.40) } },
    { { SIMDE_FLOAT32_C(  -678.16), SIMDE_FLOAT32_C(   763.66), SIMDE_FLOAT32_C(   304.80), SIMDE_FLOAT32_C(   857.07) },
      { SIMDE_FLOAT32_C(  -428.40), SIMDE_FLOAT32_C(   -22.20), SIMDE_FLOAT32_C(  -314.35), SIMDE_FLOAT32_C(    97.05) },
      { SIMDE_FLOAT32_C(   210.40), SIMDE_FLOAT32_C(  -204.25), SIMDE_FLOAT32_C(   268.67), SIMDE_FLOAT32_C(  -355.18) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-115776.39), SIMDE_FLOAT32_C( -5200.81), SIMDE_FLOAT32_C(-84151.62), SIMDE_FLOAT32_C( 26931.50) } },
    { { SIMDE_FLOAT32_C(  -437.70), SIMDE_FLOAT32_C(   922.17), SIMDE_FLOAT32_C(   748.03), SIMDE_FLOAT32_C(   611.90) },
      { SIMDE_FLOAT32_C(   162.84), SIMDE_FLOAT32_C(  -286.14), SIMDE_FLOAT32_C(  -642.61), SIMDE_FLOAT32_C(    50.53) },
      { SIMDE_FLOAT32_C(   214.38), SIMDE_FLOAT32_C(   495.20), SIMDE_FLOAT32_C(  -618.55), SIMDE_FLOAT32_C(   750.83) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(121827.46), SIMDE_FLOAT32_C(-213920.34), SIMDE_FLOAT32_C(-481742.84), SIMDE_FLOAT32_C( 38551.34) } },
    { { SIMDE_FLOAT32_C(   400.27), SIMDE_FLOAT32_C(   713.91), SIMDE_FLOAT32_C(  -872.77), SIMDE_FLOAT32_C(   390.22) },
      { SIMDE_FLOAT32_C(  -250.69), SIMDE_FLOAT32_C(   937.48), SIMDE_FLOAT32_C(   555.76), SIMDE_FLOAT32_C(    71.15) },
      { SIMDE_FLOAT32_C(   701.14), SIMDE_FLOAT32_C(  -139.44), SIMDE_FLOAT32_C(   -71.78), SIMDE_FLOAT32_C(  -727.26) },
       INT8_C(   0),
      { SIMDE_FLOAT32_C(-175368.52), SIMDE_FLOAT32_C(658018.62), SIMDE_FLOAT32_C(388792.81), SIMDE_FLOAT32_C( 50276.33) } },
    { { SIMDE_FLOAT32_C(   838.36), SIMDE_FLOAT32_C(   613.88), SIMDE_FLOAT32_C(   369.79), SIMDE_FLOAT32_C(    48.76) },
      { SIMDE_FLOAT32_C(  -590.37), SIMDE_FLOAT32_C(  -361.54), SIMDE_FLOAT32_C(   693.57), SIMDE_FLOAT32_C(   -28.08) },
      { SIMDE_FLOAT32_C(  -439.38), SIMDE_FLOAT32_C(   441.61), SIMDE_FLOAT32_C(  -416.18), SIMDE_FLOAT32_C(   723.47) },
       INT8_C(   1),
      { SIMDE_FLOAT32_C(-259874.92), SIMDE_FLOAT32_C(-159045.80), SIMDE_FLOAT32_C(306657.22), SIMDE_FLOAT32_C(-12351.65) } },
    { { SIMDE_FLOAT32_C(  -844.54), SIMDE_FLOAT32_C(   -58.79), SIMDE_FLOAT32_C(  -226.00), SIMDE_FLOAT32_C(   369.84) },
      { SIMDE_FLOAT32_C(  -563.59), SIMDE_FLOAT32_C(   155.44), SIMDE_FLOAT32_C(   120.67), SIMDE_FLOAT32_C(   836.67) },
      { SIMDE_FLOAT32_C(  -130.65), SIMDE_FLOAT32_C(   247.91), SIMDE_FLOAT32_C(   226.89), SIMDE_FLOAT32_C(   618.66) },
       INT8_C(   2),
      { SIMDE_FLOAT32_C(-128717.48), SIMDE_FLOAT32_C( 35208.99), SIMDE_FLOAT32_C( 27152.82), SIMDE_FLOAT32_C(190201.89) } },
    { { SIMDE_FLOAT32_C(   185.39), SIMDE_FLOAT32_C(  -217.35), SIMDE_FLOAT32_C(  -310.19), SIMDE_FLOAT32_C(  -113.48) },
      { SIMDE_FLOAT32_C(   643.20), SIMDE_FLOAT32_C(   618.04), SIMDE_FLOAT32_C(   159.26), SIMDE_FLOAT32_C(   481.56) },
      { SIMDE_FLOAT32_C(   231.92), SIMDE_FLOAT32_C(  -470.95), SIMDE_FLOAT32_C(  -469.68), SIMDE_FLOAT32_C(   641.54) },
       INT8_C(   3),
      { SIMDE_FLOAT32_C(412823.91), SIMDE_FLOAT32_C(396280.00), SIMDE_FLOAT32_C(101861.46), SIMDE_FLOAT32_C(308826.50) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t v = simde_vld1q_f32(test_vec[i].v);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vfmaq_laneq_f32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000, 1000);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000, 1000);
    simde_float32x4_t v = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vfmaq_laneq_f32, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b, v);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vfmaq_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t b[2];
    simde_float64_t v[2];
    int lane;
    simde_float64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   167.50), SIMDE_FLOAT64_C(  -776.11) },
      { SIMDE_FLOAT64_C(  -386.54), SIMDE_FLOAT64_C(   728.13) },
      { SIMDE_FLOAT64_C(   665.50), SIMDE_FLOAT64_C(   197.29) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-257074.87), SIMDE_FLOAT64_C(483794.40) } },
    { { SIMDE_FLOAT64_C(   451.59), SIMDE_FLOAT64_C(   820.97) },
      { SIMDE_FLOAT64_C(  -861.50), SIMDE_FLOAT64_C(  -774.41) },
      { SIMDE_FLOAT64_C(   190.81), SIMDE_FLOAT64_C(  -425.09) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(366666.62), SIMDE_FLOAT64_C(330014.92) } },
    { { SIMDE_FLOAT64_C(   381.03), SIMDE_FLOAT64_C(  -688.52) },
      { SIMDE_FLOAT64_C(  -588.42), SIMDE_FLOAT64_C(  -749.62) },
      { SIMDE_FLOAT64_C(   559.39), SIMDE_FLOAT64_C(   638.47) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(-328775.23), SIMDE_FLOAT64_C(-420018.45) } },
    { { SIMDE_FLOAT64_C(   869.04), SIMDE_FLOAT64_C(  -255.22) },
      { SIMDE_FLOAT64_C(  -578.88), SIMDE_FLOAT64_C(  -441.14) },
      { SIMDE_FLOAT64_C(   631.30), SIMDE_FLOAT64_C(  -935.68) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(542515.48), SIMDE_FLOAT64_C(412510.66) } },
    { { SIMDE_FLOAT64_C(  -823.10), SIMDE_FLOAT64_C(  -209.44) },
      { SIMDE_FLOAT64_C(   545.89), SIMDE_FLOAT64_C(   408.81) },
      { SIMDE_FLOAT64_C(   319.61), SIMDE_FLOAT64_C(  -923.79) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(173648.80), SIMDE_FLOAT64_C(130450.32) } },
    { { SIMDE_FLOAT64_C(    50.36), SIMDE_FLOAT64_C(  -512.88) },
      { SIMDE_FLOAT64_C(  -699.90), SIMDE_FLOAT64_C(   663.82) },
      { SIMDE_FLOAT64_C(  -784.76), SIMDE_FLOAT64_C(   965.60) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-675773.08), SIMDE_FLOAT64_C(640471.71) } },
    { { SIMDE_FLOAT64_C(  -138.89), SIMDE_FLOAT64_C(   666.84) },
      { SIMDE_FLOAT64_C(   786.57), SIMDE_FLOAT64_C(    -0.40) },
      { SIMDE_FLOAT64_C(   892.43), SIMDE_FLOAT64_C(   -22.62) },
       INT8_C(   0),
      { SIMDE_FLOAT64_C(701819.78), SIMDE_FLOAT64_C(   309.87) } },
    { { SIMDE_FLOAT64_C(   574.51), SIMDE_FLOAT64_C(   273.46) },
      { SIMDE_FLOAT64_C(   288.87), SIMDE_FLOAT64_C(   986.09) },
      { SIMDE_FLOAT64_C(   523.84), SIMDE_FLOAT64_C(  -151.74) },
       INT8_C(   1),
      { SIMDE_FLOAT64_C(-43258.62), SIMDE_FLOAT64_C(-149355.84) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t v = simde_vld1q_f64(test_vec[i].v);
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vfmaq_laneq_f64, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);
    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000, 1000);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000, 1000);
    simde_float64x2_t v = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vfmaq_laneq_f64, r, (HEDLEY_UNREACHABLE(), r), lanes[i], a, b, v);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lanes[i]), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vfmad_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmad_laneq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmas_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmas_laneq_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vfma_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfma_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vfma_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfma_laneq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmaq_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmaq_laneq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
