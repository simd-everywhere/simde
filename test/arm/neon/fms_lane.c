#define SIMDE_TEST_ARM_NEON_INSN fms_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/fms_lane.h"

static int
test_simde_vfmsd_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64_t a;
    simde_float64_t b;
    simde_float64_t v[1];
    simde_float64_t r;
  } test_vec[] = {
   {    SIMDE_FLOAT64_C(5083.45820),
        SIMDE_FLOAT64_C(-3347.28901),
     {  SIMDE_FLOAT64_C(-9966.81290) },
        SIMDE_FLOAT64_C(-33356719.80975) },
   {    SIMDE_FLOAT64_C(3981.27307),
        SIMDE_FLOAT64_C(2968.35655),
     {  SIMDE_FLOAT64_C(-2931.01175) },
        SIMDE_FLOAT64_C(8704269.19618) },
   {    SIMDE_FLOAT64_C(-4088.29943),
        SIMDE_FLOAT64_C(-3956.96859),
     {  SIMDE_FLOAT64_C(-2729.82603) },
        SIMDE_FLOAT64_C(-10805924.15163) },
   {    SIMDE_FLOAT64_C(-2775.38215),
        SIMDE_FLOAT64_C(6069.57489),
     {  SIMDE_FLOAT64_C(9040.55990) },
        SIMDE_FLOAT64_C(-54875130.73359) },
   {    SIMDE_FLOAT64_C(9278.86644),
        SIMDE_FLOAT64_C(-2329.30846),
     {  SIMDE_FLOAT64_C(6279.55264) },
        SIMDE_FLOAT64_C(14636293.96772) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t r = simde_vfmsd_lane_f64(test_vec[i].a, test_vec[i].b, simde_vld1_f64(test_vec[i].v), 0);
    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_vfmsd_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64_t a;
    simde_float64_t b;
    simde_float64_t v[2];
    simde_float64_t r0;
    simde_float64_t r1;
  } test_vec[] = {
   {    SIMDE_FLOAT64_C(-3108.00660),
        SIMDE_FLOAT64_C(-5521.68941),
     {  SIMDE_FLOAT64_C(1818.16262), SIMDE_FLOAT64_C(-9300.44809) },
        SIMDE_FLOAT64_C(10036221.29886),
        SIMDE_FLOAT64_C(-51357293.73881) },
   {    SIMDE_FLOAT64_C(8415.12967),
        SIMDE_FLOAT64_C(1111.46983),
     {  SIMDE_FLOAT64_C(-1295.73632), SIMDE_FLOAT64_C(-4438.18975) },
        SIMDE_FLOAT64_C(1448586.96000),
        SIMDE_FLOAT64_C(4941329.15670) },
   {    SIMDE_FLOAT64_C(5884.59336),
        SIMDE_FLOAT64_C(-1992.49187),
     {  SIMDE_FLOAT64_C(2407.80020), SIMDE_FLOAT64_C(2554.90830) },
        SIMDE_FLOAT64_C(4803406.90538),
        SIMDE_FLOAT64_C(5096518.59537) },
   {    SIMDE_FLOAT64_C(-2673.73366),
        SIMDE_FLOAT64_C(-5819.36367),
     {  SIMDE_FLOAT64_C(5499.70467), SIMDE_FLOAT64_C(2027.19160) },
        SIMDE_FLOAT64_C(32002107.81655),
        SIMDE_FLOAT64_C(11794291.42416) },
   {    SIMDE_FLOAT64_C(-2883.16010),
        SIMDE_FLOAT64_C(7115.86616),
     {  SIMDE_FLOAT64_C(5926.97189), SIMDE_FLOAT64_C(-6790.25503) },
        SIMDE_FLOAT64_C(-42178421.85403),
        SIMDE_FLOAT64_C(48315662.79867) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t v = simde_vld1q_f64(test_vec[i].v);
    simde_float64_t r0 = simde_vfmsd_laneq_f64(test_vec[i].a, test_vec[i].b, v, 0);
    simde_float64_t r1 = simde_vfmsd_laneq_f64(test_vec[i].a, test_vec[i].b, v, 1);
    simde_assert_equal_f64(r0, test_vec[i].r0, 1);
    simde_assert_equal_f64(r1, test_vec[i].r1, 1);
  }

  return 0;
}

static int
test_simde_vfmsh_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a;
    simde_float16_t b;
    simde_float16_t v[4];
    simde_float16_t r0;
    simde_float16_t r1;
    simde_float16_t r2;
    simde_float16_t r3;
  } test_vec[] = {
   {    SIMDE_FLOAT16_VALUE(-5.6),
        SIMDE_FLOAT16_VALUE(9.8),
     {  SIMDE_FLOAT16_VALUE(1.0), SIMDE_FLOAT16_VALUE(8.9), SIMDE_FLOAT16_VALUE(-9.0), SIMDE_FLOAT16_VALUE(4.0) },
        SIMDE_FLOAT16_VALUE(-15.40),
        SIMDE_FLOAT16_VALUE(-92.82),
        SIMDE_FLOAT16_VALUE(82.60),
        SIMDE_FLOAT16_VALUE(-44.80) },
   {    SIMDE_FLOAT16_VALUE(6.4),
        SIMDE_FLOAT16_VALUE(0.3),
     {  SIMDE_FLOAT16_VALUE(5.7), SIMDE_FLOAT16_VALUE(8.5), SIMDE_FLOAT16_VALUE(-6.9), SIMDE_FLOAT16_VALUE(6.2) },
        SIMDE_FLOAT16_VALUE(4.69),
        SIMDE_FLOAT16_VALUE(3.85),
        SIMDE_FLOAT16_VALUE(8.47),
        SIMDE_FLOAT16_VALUE(4.54) },
   {    SIMDE_FLOAT16_VALUE(4.6),
        SIMDE_FLOAT16_VALUE(7.9),
     {  SIMDE_FLOAT16_VALUE(2.9), SIMDE_FLOAT16_VALUE(-5.8), SIMDE_FLOAT16_VALUE(-8.9), SIMDE_FLOAT16_VALUE(-1.4) },
        SIMDE_FLOAT16_VALUE(-18.31),
        SIMDE_FLOAT16_VALUE(50.42),
        SIMDE_FLOAT16_VALUE(74.91),
        SIMDE_FLOAT16_VALUE(15.66) },
   {    SIMDE_FLOAT16_VALUE(3.5),
        SIMDE_FLOAT16_VALUE(9.7),
     {  SIMDE_FLOAT16_VALUE(-8.3), SIMDE_FLOAT16_VALUE(2.6), SIMDE_FLOAT16_VALUE(0.1), SIMDE_FLOAT16_VALUE(3.3) },
        SIMDE_FLOAT16_VALUE(84.01),
        SIMDE_FLOAT16_VALUE(-21.72),
        SIMDE_FLOAT16_VALUE(2.53),
        SIMDE_FLOAT16_VALUE(-28.51) },
   {    SIMDE_FLOAT16_VALUE(-4.7),
        SIMDE_FLOAT16_VALUE(-9.2),
     {  SIMDE_FLOAT16_VALUE(-0.4), SIMDE_FLOAT16_VALUE(-1.1), SIMDE_FLOAT16_VALUE(5.1), SIMDE_FLOAT16_VALUE(0.3) },
        SIMDE_FLOAT16_VALUE(-8.38),
        SIMDE_FLOAT16_VALUE(-14.82),
        SIMDE_FLOAT16_VALUE(42.22),
        SIMDE_FLOAT16_VALUE(-1.94) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t v = simde_vld1_f16(test_vec[i].v);
    simde_float16_t r0 = simde_vfmsh_lane_f16(test_vec[i].a, test_vec[i].b, v, 0);
    simde_float16_t r1 = simde_vfmsh_lane_f16(test_vec[i].a, test_vec[i].b, v, 1);
    simde_float16_t r2 = simde_vfmsh_lane_f16(test_vec[i].a, test_vec[i].b, v, 2);
    simde_float16_t r3 = simde_vfmsh_lane_f16(test_vec[i].a, test_vec[i].b, v, 3);
    simde_assert_equal_f16(r0, test_vec[i].r0, 1);
    simde_assert_equal_f16(r1, test_vec[i].r1, 1);
    simde_assert_equal_f16(r2, test_vec[i].r2, 1);
    simde_assert_equal_f16(r3, test_vec[i].r3, 1);
  }

  return 0;
}

static int
test_simde_vfmsh_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a;
    simde_float16_t b;
    simde_float16_t v[8];
    simde_float16_t r0;
    simde_float16_t r1;
    simde_float16_t r2;
    simde_float16_t r3;
    simde_float16_t r4;
    simde_float16_t r5;
    simde_float16_t r6;
    simde_float16_t r7;
  } test_vec[] = {
   {    SIMDE_FLOAT16_VALUE(-6.7),
        SIMDE_FLOAT16_VALUE(-9.3),
     {  SIMDE_FLOAT16_VALUE(-1.6), SIMDE_FLOAT16_VALUE(-9.4), SIMDE_FLOAT16_VALUE(0.4), SIMDE_FLOAT16_VALUE(-1.0),
        SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(3.1), SIMDE_FLOAT16_VALUE(0.7), SIMDE_FLOAT16_VALUE(9.4) },
        SIMDE_FLOAT16_VALUE(-21.58),
        SIMDE_FLOAT16_VALUE(-94.12),
        SIMDE_FLOAT16_VALUE(-2.98),
        SIMDE_FLOAT16_VALUE(-16.00),
        SIMDE_FLOAT16_VALUE(6.32),
        SIMDE_FLOAT16_VALUE(22.13),
        SIMDE_FLOAT16_VALUE(-0.19),
        SIMDE_FLOAT16_VALUE(80.72) },
   {    SIMDE_FLOAT16_VALUE(5.4),
        SIMDE_FLOAT16_VALUE(3.0),
     {  SIMDE_FLOAT16_VALUE(3.8), SIMDE_FLOAT16_VALUE(5.2), SIMDE_FLOAT16_VALUE(-7.0), SIMDE_FLOAT16_VALUE(6.8),
        SIMDE_FLOAT16_VALUE(-5.5), SIMDE_FLOAT16_VALUE(-6.3), SIMDE_FLOAT16_VALUE(7.4), SIMDE_FLOAT16_VALUE(6.8) },
        SIMDE_FLOAT16_VALUE(-6.00),
        SIMDE_FLOAT16_VALUE(-10.20),
        SIMDE_FLOAT16_VALUE(26.40),
        SIMDE_FLOAT16_VALUE(-15.00),
        SIMDE_FLOAT16_VALUE(21.90),
        SIMDE_FLOAT16_VALUE(24.30),
        SIMDE_FLOAT16_VALUE(-16.80),
        SIMDE_FLOAT16_VALUE(-15.00) },
   {    SIMDE_FLOAT16_VALUE(7.8),
        SIMDE_FLOAT16_VALUE(0.3),
     {  SIMDE_FLOAT16_VALUE(-1.5), SIMDE_FLOAT16_VALUE(-0.5), SIMDE_FLOAT16_VALUE(2.5), SIMDE_FLOAT16_VALUE(9.2),
        SIMDE_FLOAT16_VALUE(1.9), SIMDE_FLOAT16_VALUE(-8.0), SIMDE_FLOAT16_VALUE(5.9), SIMDE_FLOAT16_VALUE(2.0) },
        SIMDE_FLOAT16_VALUE(8.25),
        SIMDE_FLOAT16_VALUE(7.95),
        SIMDE_FLOAT16_VALUE(7.05),
        SIMDE_FLOAT16_VALUE(5.04),
        SIMDE_FLOAT16_VALUE(7.23),
        SIMDE_FLOAT16_VALUE(10.20),
        SIMDE_FLOAT16_VALUE(6.03),
        SIMDE_FLOAT16_VALUE(7.20) },
   {    SIMDE_FLOAT16_VALUE(7.9),
        SIMDE_FLOAT16_VALUE(3.0),
     {  SIMDE_FLOAT16_VALUE(-6.6), SIMDE_FLOAT16_VALUE(8.5), SIMDE_FLOAT16_VALUE(-2.1), SIMDE_FLOAT16_VALUE(9.6),
        SIMDE_FLOAT16_VALUE(8.0), SIMDE_FLOAT16_VALUE(-5.2), SIMDE_FLOAT16_VALUE(-8.5), SIMDE_FLOAT16_VALUE(-9.3) },
        SIMDE_FLOAT16_VALUE(27.70),
        SIMDE_FLOAT16_VALUE(-17.60),
        SIMDE_FLOAT16_VALUE(14.20),
        SIMDE_FLOAT16_VALUE(-20.90),
        SIMDE_FLOAT16_VALUE(-16.10),
        SIMDE_FLOAT16_VALUE(23.50),
        SIMDE_FLOAT16_VALUE(33.40),
        SIMDE_FLOAT16_VALUE(35.80) },
   {    SIMDE_FLOAT16_VALUE(8.3),
        SIMDE_FLOAT16_VALUE(-0.2),
     {  SIMDE_FLOAT16_VALUE(1.6), SIMDE_FLOAT16_VALUE(9.0), SIMDE_FLOAT16_VALUE(8.7), SIMDE_FLOAT16_VALUE(1.4),
        SIMDE_FLOAT16_VALUE(-7.1), SIMDE_FLOAT16_VALUE(-4.6), SIMDE_FLOAT16_VALUE(-9.6), SIMDE_FLOAT16_VALUE(-9.4) },
        SIMDE_FLOAT16_VALUE(8.62),
        SIMDE_FLOAT16_VALUE(10.10),
        SIMDE_FLOAT16_VALUE(10.04),
        SIMDE_FLOAT16_VALUE(8.58),
        SIMDE_FLOAT16_VALUE(6.88),
        SIMDE_FLOAT16_VALUE(7.38),
        SIMDE_FLOAT16_VALUE(6.38),
        SIMDE_FLOAT16_VALUE(6.42) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t v = simde_vld1q_f16(test_vec[i].v);
    simde_float16_t r0 = simde_vfmsh_laneq_f16(test_vec[i].a, test_vec[i].b, v, 0);
    simde_float16_t r1 = simde_vfmsh_laneq_f16(test_vec[i].a, test_vec[i].b, v, 1);
    simde_float16_t r2 = simde_vfmsh_laneq_f16(test_vec[i].a, test_vec[i].b, v, 2);
    simde_float16_t r3 = simde_vfmsh_laneq_f16(test_vec[i].a, test_vec[i].b, v, 3);
    simde_float16_t r4 = simde_vfmsh_laneq_f16(test_vec[i].a, test_vec[i].b, v, 4);
    simde_float16_t r5 = simde_vfmsh_laneq_f16(test_vec[i].a, test_vec[i].b, v, 5);
    simde_float16_t r6 = simde_vfmsh_laneq_f16(test_vec[i].a, test_vec[i].b, v, 6);
    simde_float16_t r7 = simde_vfmsh_laneq_f16(test_vec[i].a, test_vec[i].b, v, 7);

    simde_assert_equal_f16(r0, test_vec[i].r0, 1);
    simde_assert_equal_f16(r1, test_vec[i].r1, 1);
    simde_assert_equal_f16(r2, test_vec[i].r2, 1);
    simde_assert_equal_f16(r3, test_vec[i].r3, 1);
    simde_assert_equal_f16(r4, test_vec[i].r4, 1);
    simde_assert_equal_f16(r5, test_vec[i].r5, 1);
    simde_assert_equal_f16(r6, test_vec[i].r6, 1);
    simde_assert_equal_f16(r7, test_vec[i].r7, 1);
  }

  return 0;
}

static int
test_simde_vfmss_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t a;
    simde_float32_t b;
    simde_float32_t v[2];
    simde_float32_t r0;
    simde_float32_t r1;
  } test_vec[] = {
   {    SIMDE_FLOAT32_C(-245.78053),
        SIMDE_FLOAT32_C(-510.31364),
     {  SIMDE_FLOAT32_C(-692.23531), SIMDE_FLOAT32_C(-878.41332) },
        SIMDE_FLOAT32_C(-353502.90372),
        SIMDE_FLOAT32_C(-448512.08281) },
   {    SIMDE_FLOAT32_C(-564.58993),
        SIMDE_FLOAT32_C(-741.36855),
     {  SIMDE_FLOAT32_C(-36.47120), SIMDE_FLOAT32_C(56.49479) },
        SIMDE_FLOAT32_C(-27603.18998),
        SIMDE_FLOAT32_C(41318.86775) },
   {    SIMDE_FLOAT32_C(984.27762),
        SIMDE_FLOAT32_C(-912.50208),
     {  SIMDE_FLOAT32_C(-876.43217), SIMDE_FLOAT32_C(694.61740) },
        SIMDE_FLOAT32_C(-798761.90387),
        SIMDE_FLOAT32_C(634824.10714) },
   {    SIMDE_FLOAT32_C(-431.23028),
        SIMDE_FLOAT32_C(-695.27617),
     {  SIMDE_FLOAT32_C(966.19776), SIMDE_FLOAT32_C(503.58925) },
        SIMDE_FLOAT32_C(671343.04625),
        SIMDE_FLOAT32_C(349702.37079) },
   {    SIMDE_FLOAT32_C(-292.62265),
        SIMDE_FLOAT32_C(957.48912),
     {  SIMDE_FLOAT32_C(229.60490), SIMDE_FLOAT32_C(-673.93248) },
        SIMDE_FLOAT32_C(-220136.81448),
        SIMDE_FLOAT32_C(644990.39976) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t v = simde_vld1_f32(test_vec[i].v);
    simde_float32_t r0 = simde_vfmss_lane_f32(test_vec[i].a, test_vec[i].b, v, 0);
    simde_float32_t r1 = simde_vfmss_lane_f32(test_vec[i].a, test_vec[i].b, v, 1);
    simde_assert_equal_f32(r0, test_vec[i].r0, 1);
    simde_assert_equal_f32(r1, test_vec[i].r1, 1);
  }

  return 0;
}

static int
test_simde_vfmss_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t a;
    simde_float32_t b;
    simde_float32_t v[4];
    simde_float32_t r0;
    simde_float32_t r1;
    simde_float32_t r2;
    simde_float32_t r3;
  } test_vec[] = {
   {    SIMDE_FLOAT32_C(-543.69870),
        SIMDE_FLOAT32_C(-921.77581),
     {  SIMDE_FLOAT32_C(-179.29631), SIMDE_FLOAT32_C(131.66650), SIMDE_FLOAT32_C(-896.40104), SIMDE_FLOAT32_C(-50.53601) },
        SIMDE_FLOAT32_C(-165814.70087),
        SIMDE_FLOAT32_C(120823.29126),
        SIMDE_FLOAT32_C(-826824.49470),
        SIMDE_FLOAT32_C(-47126.56953) },
   {    SIMDE_FLOAT32_C(630.92630),
        SIMDE_FLOAT32_C(-294.49788),
     {  SIMDE_FLOAT32_C(542.77533), SIMDE_FLOAT32_C(-98.29697), SIMDE_FLOAT32_C(192.56576), SIMDE_FLOAT32_C(-510.86249) },
        SIMDE_FLOAT32_C(160477.11170),
        SIMDE_FLOAT32_C(-28317.32299),
        SIMDE_FLOAT32_C(57341.13617),
        SIMDE_FLOAT32_C(-149816.99612) },
   {    SIMDE_FLOAT32_C(335.92091),
        SIMDE_FLOAT32_C(-781.41195),
     {  SIMDE_FLOAT32_C(-271.13463), SIMDE_FLOAT32_C(907.74971), SIMDE_FLOAT32_C(-327.73176), SIMDE_FLOAT32_C(-364.37127) },
        SIMDE_FLOAT32_C(-211531.91898),
        SIMDE_FLOAT32_C(709662.39198),
        SIMDE_FLOAT32_C(-255757.59162),
        SIMDE_FLOAT32_C(-284388.14421) },
   {    SIMDE_FLOAT32_C(-520.15321),
        SIMDE_FLOAT32_C(-320.28896),
     {  SIMDE_FLOAT32_C(658.32259), SIMDE_FLOAT32_C(52.40700), SIMDE_FLOAT32_C(-107.97869), SIMDE_FLOAT32_C(153.98573) },
        SIMDE_FLOAT32_C(210333.30406),
        SIMDE_FLOAT32_C(16265.22944),
        SIMDE_FLOAT32_C(-35104.53670),
        SIMDE_FLOAT32_C(48799.77512) },
   {    SIMDE_FLOAT32_C(-504.12254),
        SIMDE_FLOAT32_C(-451.10630),
     {  SIMDE_FLOAT32_C(428.44660), SIMDE_FLOAT32_C(598.14857), SIMDE_FLOAT32_C(475.06262), SIMDE_FLOAT32_C(-754.04418) },
        SIMDE_FLOAT32_C(192770.83751),
        SIMDE_FLOAT32_C(269324.46435),
        SIMDE_FLOAT32_C(213799.61931),
        SIMDE_FLOAT32_C(-340658.20187) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t v = simde_vld1q_f32(test_vec[i].v);
    simde_float32_t r0 = simde_vfmss_laneq_f32(test_vec[i].a, test_vec[i].b, v, 0);
    simde_float32_t r1 = simde_vfmss_laneq_f32(test_vec[i].a, test_vec[i].b, v, 1);
    simde_float32_t r2 = simde_vfmss_laneq_f32(test_vec[i].a, test_vec[i].b, v, 2);
    simde_float32_t r3 = simde_vfmss_laneq_f32(test_vec[i].a, test_vec[i].b, v, 3);

    simde_assert_equal_f32(r0, test_vec[i].r0, 1);
    simde_assert_equal_f32(r1, test_vec[i].r1, 1);
    simde_assert_equal_f32(r2, test_vec[i].r2, 1);
    simde_assert_equal_f32(r3, test_vec[i].r3, 1);
  }

  return 0;
}

static int
test_simde_vfms_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[4];
    simde_float16_t b[4];
    simde_float16_t v[4];
    simde_float16_t r0[4];
    simde_float16_t r1[4];
    simde_float16_t r2[4];
    simde_float16_t r3[4];
  } test_vec[] = {
   { {  SIMDE_FLOAT16_VALUE(7.4), SIMDE_FLOAT16_VALUE(-9.5), SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(-5.8) },
     {  SIMDE_FLOAT16_VALUE(-4.5), SIMDE_FLOAT16_VALUE(1.5), SIMDE_FLOAT16_VALUE(-9.3), SIMDE_FLOAT16_VALUE(7.4) },
     {  SIMDE_FLOAT16_VALUE(-2.3), SIMDE_FLOAT16_VALUE(-4.2), SIMDE_FLOAT16_VALUE(-9.9), SIMDE_FLOAT16_VALUE(4.1) },
     {  SIMDE_FLOAT16_VALUE(-2.95), SIMDE_FLOAT16_VALUE(-6.05), SIMDE_FLOAT16_VALUE(-20.29), SIMDE_FLOAT16_VALUE(11.22) },
     {  SIMDE_FLOAT16_VALUE(-11.50), SIMDE_FLOAT16_VALUE(-3.20), SIMDE_FLOAT16_VALUE(-37.96), SIMDE_FLOAT16_VALUE(25.28) },
     {  SIMDE_FLOAT16_VALUE(-37.15), SIMDE_FLOAT16_VALUE(5.35), SIMDE_FLOAT16_VALUE(-90.87), SIMDE_FLOAT16_VALUE(67.46) },
     {  SIMDE_FLOAT16_VALUE(25.85), SIMDE_FLOAT16_VALUE(-15.65), SIMDE_FLOAT16_VALUE(39.23), SIMDE_FLOAT16_VALUE(-36.14) } },
   { {  SIMDE_FLOAT16_VALUE(-3.2), SIMDE_FLOAT16_VALUE(-0.5), SIMDE_FLOAT16_VALUE(0.3), SIMDE_FLOAT16_VALUE(-4.7) },
     {  SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(-6.9), SIMDE_FLOAT16_VALUE(-8.4), SIMDE_FLOAT16_VALUE(6.1) },
     {  SIMDE_FLOAT16_VALUE(7.1), SIMDE_FLOAT16_VALUE(-3.9), SIMDE_FLOAT16_VALUE(2.5), SIMDE_FLOAT16_VALUE(-3.6) },
     {  SIMDE_FLOAT16_VALUE(-11.01), SIMDE_FLOAT16_VALUE(48.49), SIMDE_FLOAT16_VALUE(59.94), SIMDE_FLOAT16_VALUE(-48.01) },
     {  SIMDE_FLOAT16_VALUE(1.09), SIMDE_FLOAT16_VALUE(-27.41), SIMDE_FLOAT16_VALUE(-32.46), SIMDE_FLOAT16_VALUE(19.09) },
     {  SIMDE_FLOAT16_VALUE(-5.95), SIMDE_FLOAT16_VALUE(16.75), SIMDE_FLOAT16_VALUE(21.30), SIMDE_FLOAT16_VALUE(-19.95) },
     {  SIMDE_FLOAT16_VALUE(0.76), SIMDE_FLOAT16_VALUE(-25.34), SIMDE_FLOAT16_VALUE(-29.94), SIMDE_FLOAT16_VALUE(17.26) } },
   { {  SIMDE_FLOAT16_VALUE(8.2), SIMDE_FLOAT16_VALUE(-5.4), SIMDE_FLOAT16_VALUE(4.3), SIMDE_FLOAT16_VALUE(3.9) },
     {  SIMDE_FLOAT16_VALUE(-1.7), SIMDE_FLOAT16_VALUE(-5.8), SIMDE_FLOAT16_VALUE(-5.7), SIMDE_FLOAT16_VALUE(5.5) },
     {  SIMDE_FLOAT16_VALUE(-2.7), SIMDE_FLOAT16_VALUE(-6.5), SIMDE_FLOAT16_VALUE(-1.9), SIMDE_FLOAT16_VALUE(-3.6) },
     {  SIMDE_FLOAT16_VALUE(3.61), SIMDE_FLOAT16_VALUE(-21.06), SIMDE_FLOAT16_VALUE(-11.09), SIMDE_FLOAT16_VALUE(18.75) },
     {  SIMDE_FLOAT16_VALUE(-2.85), SIMDE_FLOAT16_VALUE(-43.10), SIMDE_FLOAT16_VALUE(-32.75), SIMDE_FLOAT16_VALUE(39.65) },
     {  SIMDE_FLOAT16_VALUE(4.97), SIMDE_FLOAT16_VALUE(-16.42), SIMDE_FLOAT16_VALUE(-6.53), SIMDE_FLOAT16_VALUE(14.35) },
     {  SIMDE_FLOAT16_VALUE(2.08), SIMDE_FLOAT16_VALUE(-26.28), SIMDE_FLOAT16_VALUE(-16.22), SIMDE_FLOAT16_VALUE(23.70) } },
   { {  SIMDE_FLOAT16_VALUE(9.1), SIMDE_FLOAT16_VALUE(-9.8), SIMDE_FLOAT16_VALUE(3.0), SIMDE_FLOAT16_VALUE(9.4) },
     {  SIMDE_FLOAT16_VALUE(-2.4), SIMDE_FLOAT16_VALUE(4.3), SIMDE_FLOAT16_VALUE(9.0), SIMDE_FLOAT16_VALUE(0.8) },
     {  SIMDE_FLOAT16_VALUE(-1.4), SIMDE_FLOAT16_VALUE(-6.9), SIMDE_FLOAT16_VALUE(-4.8), SIMDE_FLOAT16_VALUE(5.7) },
     {  SIMDE_FLOAT16_VALUE(5.74), SIMDE_FLOAT16_VALUE(-3.78), SIMDE_FLOAT16_VALUE(15.60), SIMDE_FLOAT16_VALUE(10.52) },
     {  SIMDE_FLOAT16_VALUE(-7.46), SIMDE_FLOAT16_VALUE(19.87), SIMDE_FLOAT16_VALUE(65.10), SIMDE_FLOAT16_VALUE(14.92) },
     {  SIMDE_FLOAT16_VALUE(-2.42), SIMDE_FLOAT16_VALUE(10.84), SIMDE_FLOAT16_VALUE(46.20), SIMDE_FLOAT16_VALUE(13.24) },
     {  SIMDE_FLOAT16_VALUE(22.78), SIMDE_FLOAT16_VALUE(-34.31), SIMDE_FLOAT16_VALUE(-48.30), SIMDE_FLOAT16_VALUE(4.84) } },
   { {  SIMDE_FLOAT16_VALUE(4.9), SIMDE_FLOAT16_VALUE(9.4), SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(-8.5) },
     {  SIMDE_FLOAT16_VALUE(6.1), SIMDE_FLOAT16_VALUE(5.0), SIMDE_FLOAT16_VALUE(6.3), SIMDE_FLOAT16_VALUE(-5.8) },
     {  SIMDE_FLOAT16_VALUE(6.9), SIMDE_FLOAT16_VALUE(-0.0), SIMDE_FLOAT16_VALUE(6.5), SIMDE_FLOAT16_VALUE(-9.2) },
     {  SIMDE_FLOAT16_VALUE(-37.19), SIMDE_FLOAT16_VALUE(-25.10), SIMDE_FLOAT16_VALUE(-40.17), SIMDE_FLOAT16_VALUE(31.52) },
     {  SIMDE_FLOAT16_VALUE(4.90), SIMDE_FLOAT16_VALUE(9.40), SIMDE_FLOAT16_VALUE(3.30), SIMDE_FLOAT16_VALUE(-8.50) },
     {  SIMDE_FLOAT16_VALUE(-34.75), SIMDE_FLOAT16_VALUE(-23.10), SIMDE_FLOAT16_VALUE(-37.65), SIMDE_FLOAT16_VALUE(29.20) },
     {  SIMDE_FLOAT16_VALUE(61.02), SIMDE_FLOAT16_VALUE(55.40), SIMDE_FLOAT16_VALUE(61.26), SIMDE_FLOAT16_VALUE(-61.86) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t v = simde_vld1_f16(test_vec[i].v);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r0 = simde_vfms_lane_f16(a, b, v, 0);
    simde_float16x4_t r1 = simde_vfms_lane_f16(a, b, v, 1);
    simde_float16x4_t r2 = simde_vfms_lane_f16(a, b, v, 2);
    simde_float16x4_t r3 = simde_vfms_lane_f16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_f16x4(r0, simde_vld1_f16(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f16x4(r1, simde_vld1_f16(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f16x4(r2, simde_vld1_f16(test_vec[i].r2), 1);
    simde_test_arm_neon_assert_equal_f16x4(r3, simde_vld1_f16(test_vec[i].r3), 1);
  }

  return 0;
}

static int
test_simde_vfms_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t a[2];
    simde_float32_t b[2];
    simde_float32_t v[2];
    simde_float32_t r0[2];
    simde_float32_t r1[2];
  } test_vec[] = {
   { {  SIMDE_FLOAT32_C(-122.86190), SIMDE_FLOAT32_C(876.09460) },
     {  SIMDE_FLOAT32_C(-659.82491), SIMDE_FLOAT32_C(-582.51925) },
     {  SIMDE_FLOAT32_C(192.61616), SIMDE_FLOAT32_C(-268.86836) },
     {  SIMDE_FLOAT32_C(126970.07668), SIMDE_FLOAT32_C(113078.71313) },
     {  SIMDE_FLOAT32_C(-177528.90336), SIMDE_FLOAT32_C(-155744.89961) } },
   { {  SIMDE_FLOAT32_C(94.67060), SIMDE_FLOAT32_C(-520.91137) },
     {  SIMDE_FLOAT32_C(-947.08934), SIMDE_FLOAT32_C(-694.08895) },
     {  SIMDE_FLOAT32_C(178.67959), SIMDE_FLOAT32_C(-186.53816) },
     {  SIMDE_FLOAT32_C(169320.20891), SIMDE_FLOAT32_C(123498.61992) },
     {  SIMDE_FLOAT32_C(-176573.63370), SIMDE_FLOAT32_C(-129994.98787) } },
   { {  SIMDE_FLOAT32_C(155.07091), SIMDE_FLOAT32_C(-342.36202) },
     {  SIMDE_FLOAT32_C(-783.56502), SIMDE_FLOAT32_C(-177.49802) },
     {  SIMDE_FLOAT32_C(-750.10136), SIMDE_FLOAT32_C(-316.79896) },
     {  SIMDE_FLOAT32_C(-587598.11686), SIMDE_FLOAT32_C(-133483.87184) },
     {  SIMDE_FLOAT32_C(-248077.51452), SIMDE_FLOAT32_C(-56573.55208) } },
   { {  SIMDE_FLOAT32_C(57.11387), SIMDE_FLOAT32_C(575.00959) },
     {  SIMDE_FLOAT32_C(-166.49087), SIMDE_FLOAT32_C(-456.70562) },
     {  SIMDE_FLOAT32_C(334.78387), SIMDE_FLOAT32_C(-93.37312) },
     {  SIMDE_FLOAT32_C(55795.57118), SIMDE_FLOAT32_C(153472.68523) },
     {  SIMDE_FLOAT32_C(-15488.65812), SIMDE_FLOAT32_C(-42069.01964) } },
   { {  SIMDE_FLOAT32_C(-884.10215), SIMDE_FLOAT32_C(465.54633) },
     {  SIMDE_FLOAT32_C(-317.69692), SIMDE_FLOAT32_C(801.18637) },
     {  SIMDE_FLOAT32_C(-930.09100), SIMDE_FLOAT32_C(-642.43853) },
     {  SIMDE_FLOAT32_C(-296371.15224), SIMDE_FLOAT32_C(745641.77909) },
     {  SIMDE_FLOAT32_C(-204984.84670), SIMDE_FLOAT32_C(515178.53928) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t v = simde_vld1_f32(test_vec[i].v);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r0 = simde_vfms_lane_f32(a, b, v, 0);
    simde_float32x2_t r1 = simde_vfms_lane_f32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_f32x2(r0, simde_vld1_f32(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f32x2(r1, simde_vld1_f32(test_vec[i].r1), 1);
  }

  return 0;
}

static int
test_simde_vfms_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64_t a[1];
    simde_float64_t b[1];
    simde_float64_t v[1];
    simde_float64_t r[1];
  } test_vec[] = {
   { {  SIMDE_FLOAT64_C(3636.83577) },
     {  SIMDE_FLOAT64_C(6175.08860) },
     {  SIMDE_FLOAT64_C(7239.25714) },
     {  SIMDE_FLOAT64_C(-44699417.39457) } },
   { {  SIMDE_FLOAT64_C(-895.90190) },
     {  SIMDE_FLOAT64_C(-6127.51825) },
     {  SIMDE_FLOAT64_C(-6063.19315) },
     {  SIMDE_FLOAT64_C(-37153222.57897) } },
   { {  SIMDE_FLOAT64_C(7511.87882) },
     {  SIMDE_FLOAT64_C(-3060.31431) },
     {  SIMDE_FLOAT64_C(-8366.52902) },
     {  SIMDE_FLOAT64_C(-25596696.63421) } },
   { {  SIMDE_FLOAT64_C(-9672.14195) },
     {  SIMDE_FLOAT64_C(-4610.28204) },
     {  SIMDE_FLOAT64_C(-9678.81520) },
     {  SIMDE_FLOAT64_C(-44631740.08271) } },
   { {  SIMDE_FLOAT64_C(6971.33141) },
     {  SIMDE_FLOAT64_C(7885.70448) },
     {  SIMDE_FLOAT64_C(-4134.40167) },
     {  SIMDE_FLOAT64_C(32609641.06601) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t v = simde_vld1_f64(test_vec[i].v);
    simde_float64x1_t r = simde_vfms_lane_f64(simde_vld1_f64(test_vec[i].a), simde_vld1_f64(test_vec[i].b), v, 0);
    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfms_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[4];
    simde_float16_t b[4];
    simde_float16_t v[8];
    simde_float16_t r0[4];
    simde_float16_t r1[4];
    simde_float16_t r2[4];
    simde_float16_t r3[4];
    simde_float16_t r4[4];
    simde_float16_t r5[4];
    simde_float16_t r6[4];
    simde_float16_t r7[4];
  } test_vec[] = {
   { {  SIMDE_FLOAT16_VALUE(-4.5), SIMDE_FLOAT16_VALUE(9.8), SIMDE_FLOAT16_VALUE(9.0), SIMDE_FLOAT16_VALUE(-9.5) },
     {  SIMDE_FLOAT16_VALUE(4.1), SIMDE_FLOAT16_VALUE(1.0), SIMDE_FLOAT16_VALUE(9.2), SIMDE_FLOAT16_VALUE(8.3) },
     {  SIMDE_FLOAT16_VALUE(9.1), SIMDE_FLOAT16_VALUE(-3.1), SIMDE_FLOAT16_VALUE(-2.0), SIMDE_FLOAT16_VALUE(-5.8),
        SIMDE_FLOAT16_VALUE(-8.6), SIMDE_FLOAT16_VALUE(2.4), SIMDE_FLOAT16_VALUE(-1.5), SIMDE_FLOAT16_VALUE(-4.4) },
     {  SIMDE_FLOAT16_VALUE(-41.81), SIMDE_FLOAT16_VALUE(0.70), SIMDE_FLOAT16_VALUE(-74.72), SIMDE_FLOAT16_VALUE(-85.03) },
     {  SIMDE_FLOAT16_VALUE(8.21), SIMDE_FLOAT16_VALUE(12.90), SIMDE_FLOAT16_VALUE(37.52), SIMDE_FLOAT16_VALUE(16.23) },
     {  SIMDE_FLOAT16_VALUE(3.70), SIMDE_FLOAT16_VALUE(11.80), SIMDE_FLOAT16_VALUE(27.40), SIMDE_FLOAT16_VALUE(7.10) },
     {  SIMDE_FLOAT16_VALUE(19.28), SIMDE_FLOAT16_VALUE(15.60), SIMDE_FLOAT16_VALUE(62.36), SIMDE_FLOAT16_VALUE(38.64) },
     {  SIMDE_FLOAT16_VALUE(30.76), SIMDE_FLOAT16_VALUE(18.40), SIMDE_FLOAT16_VALUE(88.12), SIMDE_FLOAT16_VALUE(61.88) },
     {  SIMDE_FLOAT16_VALUE(-14.34), SIMDE_FLOAT16_VALUE(7.40), SIMDE_FLOAT16_VALUE(-13.08), SIMDE_FLOAT16_VALUE(-29.42) },
     {  SIMDE_FLOAT16_VALUE(1.65), SIMDE_FLOAT16_VALUE(11.30), SIMDE_FLOAT16_VALUE(22.80), SIMDE_FLOAT16_VALUE(2.95) },
     {  SIMDE_FLOAT16_VALUE(13.54), SIMDE_FLOAT16_VALUE(14.20), SIMDE_FLOAT16_VALUE(49.48), SIMDE_FLOAT16_VALUE(27.02) } },
   { {  SIMDE_FLOAT16_VALUE(-2.4), SIMDE_FLOAT16_VALUE(0.5), SIMDE_FLOAT16_VALUE(1.7), SIMDE_FLOAT16_VALUE(-6.9) },
     {  SIMDE_FLOAT16_VALUE(-8.6), SIMDE_FLOAT16_VALUE(8.4), SIMDE_FLOAT16_VALUE(6.0), SIMDE_FLOAT16_VALUE(3.7) },
     {  SIMDE_FLOAT16_VALUE(4.3), SIMDE_FLOAT16_VALUE(-5.1), SIMDE_FLOAT16_VALUE(-4.0), SIMDE_FLOAT16_VALUE(5.4),
        SIMDE_FLOAT16_VALUE(-7.1), SIMDE_FLOAT16_VALUE(8.3), SIMDE_FLOAT16_VALUE(7.7), SIMDE_FLOAT16_VALUE(0.2) },
     {  SIMDE_FLOAT16_VALUE(34.58), SIMDE_FLOAT16_VALUE(-35.62), SIMDE_FLOAT16_VALUE(-24.10), SIMDE_FLOAT16_VALUE(-22.81) },
     {  SIMDE_FLOAT16_VALUE(-46.26), SIMDE_FLOAT16_VALUE(43.34), SIMDE_FLOAT16_VALUE(32.30), SIMDE_FLOAT16_VALUE(11.97) },
     {  SIMDE_FLOAT16_VALUE(-36.80), SIMDE_FLOAT16_VALUE(34.10), SIMDE_FLOAT16_VALUE(25.70), SIMDE_FLOAT16_VALUE(7.90) },
     {  SIMDE_FLOAT16_VALUE(44.04), SIMDE_FLOAT16_VALUE(-44.86), SIMDE_FLOAT16_VALUE(-30.70), SIMDE_FLOAT16_VALUE(-26.88) },
     {  SIMDE_FLOAT16_VALUE(-63.46), SIMDE_FLOAT16_VALUE(60.14), SIMDE_FLOAT16_VALUE(44.30), SIMDE_FLOAT16_VALUE(19.37) },
     {  SIMDE_FLOAT16_VALUE(68.98), SIMDE_FLOAT16_VALUE(-69.22), SIMDE_FLOAT16_VALUE(-48.10), SIMDE_FLOAT16_VALUE(-37.61) },
     {  SIMDE_FLOAT16_VALUE(63.82), SIMDE_FLOAT16_VALUE(-64.18), SIMDE_FLOAT16_VALUE(-44.50), SIMDE_FLOAT16_VALUE(-35.39) },
     {  SIMDE_FLOAT16_VALUE(-0.68), SIMDE_FLOAT16_VALUE(-1.18), SIMDE_FLOAT16_VALUE(0.50), SIMDE_FLOAT16_VALUE(-7.64) } },
   { {  SIMDE_FLOAT16_VALUE(-9.9), SIMDE_FLOAT16_VALUE(-2.3), SIMDE_FLOAT16_VALUE(1.3), SIMDE_FLOAT16_VALUE(-7.5) },
     {  SIMDE_FLOAT16_VALUE(9.9), SIMDE_FLOAT16_VALUE(-7.5), SIMDE_FLOAT16_VALUE(-7.2), SIMDE_FLOAT16_VALUE(9.0) },
     {  SIMDE_FLOAT16_VALUE(4.1), SIMDE_FLOAT16_VALUE(9.0), SIMDE_FLOAT16_VALUE(5.4), SIMDE_FLOAT16_VALUE(8.4),
        SIMDE_FLOAT16_VALUE(8.3), SIMDE_FLOAT16_VALUE(-6.0), SIMDE_FLOAT16_VALUE(-0.7), SIMDE_FLOAT16_VALUE(4.8) },
     {  SIMDE_FLOAT16_VALUE(-50.49), SIMDE_FLOAT16_VALUE(28.45), SIMDE_FLOAT16_VALUE(30.82), SIMDE_FLOAT16_VALUE(-44.40) },
     {  SIMDE_FLOAT16_VALUE(-99.00), SIMDE_FLOAT16_VALUE(65.20), SIMDE_FLOAT16_VALUE(66.10), SIMDE_FLOAT16_VALUE(-88.50) },
     {  SIMDE_FLOAT16_VALUE(-63.36), SIMDE_FLOAT16_VALUE(38.20), SIMDE_FLOAT16_VALUE(40.18), SIMDE_FLOAT16_VALUE(-56.10) },
     {  SIMDE_FLOAT16_VALUE(-93.06), SIMDE_FLOAT16_VALUE(60.70), SIMDE_FLOAT16_VALUE(61.78), SIMDE_FLOAT16_VALUE(-83.10) },
     {  SIMDE_FLOAT16_VALUE(-92.07), SIMDE_FLOAT16_VALUE(59.95), SIMDE_FLOAT16_VALUE(61.06), SIMDE_FLOAT16_VALUE(-82.20) },
     {  SIMDE_FLOAT16_VALUE(49.50), SIMDE_FLOAT16_VALUE(-47.30), SIMDE_FLOAT16_VALUE(-41.90), SIMDE_FLOAT16_VALUE(46.50) },
     {  SIMDE_FLOAT16_VALUE(-2.97), SIMDE_FLOAT16_VALUE(-7.55), SIMDE_FLOAT16_VALUE(-3.74), SIMDE_FLOAT16_VALUE(-1.20) },
     {  SIMDE_FLOAT16_VALUE(-57.42), SIMDE_FLOAT16_VALUE(33.70), SIMDE_FLOAT16_VALUE(35.86), SIMDE_FLOAT16_VALUE(-50.70) } },
   { {  SIMDE_FLOAT16_VALUE(9.1), SIMDE_FLOAT16_VALUE(6.6), SIMDE_FLOAT16_VALUE(-8.9), SIMDE_FLOAT16_VALUE(0.9) },
     {  SIMDE_FLOAT16_VALUE(4.2), SIMDE_FLOAT16_VALUE(1.3), SIMDE_FLOAT16_VALUE(-4.6), SIMDE_FLOAT16_VALUE(-7.6) },
     {  SIMDE_FLOAT16_VALUE(-3.3), SIMDE_FLOAT16_VALUE(-1.0), SIMDE_FLOAT16_VALUE(2.8), SIMDE_FLOAT16_VALUE(7.2),
        SIMDE_FLOAT16_VALUE(6.0), SIMDE_FLOAT16_VALUE(-3.4), SIMDE_FLOAT16_VALUE(9.4), SIMDE_FLOAT16_VALUE(0.6) },
     {  SIMDE_FLOAT16_VALUE(22.96), SIMDE_FLOAT16_VALUE(10.89), SIMDE_FLOAT16_VALUE(-24.08), SIMDE_FLOAT16_VALUE(-24.18) },
     {  SIMDE_FLOAT16_VALUE(13.30), SIMDE_FLOAT16_VALUE(7.90), SIMDE_FLOAT16_VALUE(-13.50), SIMDE_FLOAT16_VALUE(-6.70) },
     {  SIMDE_FLOAT16_VALUE(-2.66), SIMDE_FLOAT16_VALUE(2.96), SIMDE_FLOAT16_VALUE(3.98), SIMDE_FLOAT16_VALUE(22.18) },
     {  SIMDE_FLOAT16_VALUE(-21.14), SIMDE_FLOAT16_VALUE(-2.76), SIMDE_FLOAT16_VALUE(24.22), SIMDE_FLOAT16_VALUE(55.62) },
     {  SIMDE_FLOAT16_VALUE(-16.10), SIMDE_FLOAT16_VALUE(-1.20), SIMDE_FLOAT16_VALUE(18.70), SIMDE_FLOAT16_VALUE(46.50) },
     {  SIMDE_FLOAT16_VALUE(23.38), SIMDE_FLOAT16_VALUE(11.02), SIMDE_FLOAT16_VALUE(-24.54), SIMDE_FLOAT16_VALUE(-24.94) },
     {  SIMDE_FLOAT16_VALUE(-30.38), SIMDE_FLOAT16_VALUE(-5.62), SIMDE_FLOAT16_VALUE(34.34), SIMDE_FLOAT16_VALUE(72.34) },
     {  SIMDE_FLOAT16_VALUE(6.58), SIMDE_FLOAT16_VALUE(5.82), SIMDE_FLOAT16_VALUE(-6.14), SIMDE_FLOAT16_VALUE(5.46) } },
   { {  SIMDE_FLOAT16_VALUE(-9.4), SIMDE_FLOAT16_VALUE(6.2), SIMDE_FLOAT16_VALUE(7.8), SIMDE_FLOAT16_VALUE(-4.3) },
     {  SIMDE_FLOAT16_VALUE(7.7), SIMDE_FLOAT16_VALUE(2.5), SIMDE_FLOAT16_VALUE(-6.0), SIMDE_FLOAT16_VALUE(-2.5) },
     {  SIMDE_FLOAT16_VALUE(5.5), SIMDE_FLOAT16_VALUE(-0.5), SIMDE_FLOAT16_VALUE(2.1), SIMDE_FLOAT16_VALUE(-8.7),
        SIMDE_FLOAT16_VALUE(-1.4), SIMDE_FLOAT16_VALUE(3.1), SIMDE_FLOAT16_VALUE(2.1), SIMDE_FLOAT16_VALUE(1.4) },
     {  SIMDE_FLOAT16_VALUE(-51.75), SIMDE_FLOAT16_VALUE(-7.55), SIMDE_FLOAT16_VALUE(40.80), SIMDE_FLOAT16_VALUE(9.45) },
     {  SIMDE_FLOAT16_VALUE(-5.55), SIMDE_FLOAT16_VALUE(7.45), SIMDE_FLOAT16_VALUE(4.80), SIMDE_FLOAT16_VALUE(-5.55) },
     {  SIMDE_FLOAT16_VALUE(-25.57), SIMDE_FLOAT16_VALUE(0.95), SIMDE_FLOAT16_VALUE(20.40), SIMDE_FLOAT16_VALUE(0.95) },
     {  SIMDE_FLOAT16_VALUE(57.59), SIMDE_FLOAT16_VALUE(27.95), SIMDE_FLOAT16_VALUE(-44.40), SIMDE_FLOAT16_VALUE(-26.05) },
     {  SIMDE_FLOAT16_VALUE(1.38), SIMDE_FLOAT16_VALUE(9.70), SIMDE_FLOAT16_VALUE(-0.60), SIMDE_FLOAT16_VALUE(-7.80) },
     {  SIMDE_FLOAT16_VALUE(-33.27), SIMDE_FLOAT16_VALUE(-1.55), SIMDE_FLOAT16_VALUE(26.40), SIMDE_FLOAT16_VALUE(3.45) },
     {  SIMDE_FLOAT16_VALUE(-25.57), SIMDE_FLOAT16_VALUE(0.95), SIMDE_FLOAT16_VALUE(20.40), SIMDE_FLOAT16_VALUE(0.95) },
     {  SIMDE_FLOAT16_VALUE(-20.18), SIMDE_FLOAT16_VALUE(2.70), SIMDE_FLOAT16_VALUE(16.20), SIMDE_FLOAT16_VALUE(-0.80) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t v = simde_vld1q_f16(test_vec[i].v);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r0 = simde_vfms_laneq_f16(a, b, v, 0);
    simde_float16x4_t r1 = simde_vfms_laneq_f16(a, b, v, 1);
    simde_float16x4_t r2 = simde_vfms_laneq_f16(a, b, v, 2);
    simde_float16x4_t r3 = simde_vfms_laneq_f16(a, b, v, 3);
    simde_float16x4_t r4 = simde_vfms_laneq_f16(a, b, v, 4);
    simde_float16x4_t r5 = simde_vfms_laneq_f16(a, b, v, 5);
    simde_float16x4_t r6 = simde_vfms_laneq_f16(a, b, v, 6);
    simde_float16x4_t r7 = simde_vfms_laneq_f16(a, b, v, 7);
    simde_test_arm_neon_assert_equal_f16x4(r0, simde_vld1_f16(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f16x4(r1, simde_vld1_f16(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f16x4(r2, simde_vld1_f16(test_vec[i].r2), 1);
    simde_test_arm_neon_assert_equal_f16x4(r3, simde_vld1_f16(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f16x4(r4, simde_vld1_f16(test_vec[i].r4), 1);
    simde_test_arm_neon_assert_equal_f16x4(r5, simde_vld1_f16(test_vec[i].r5), 1);
    simde_test_arm_neon_assert_equal_f16x4(r6, simde_vld1_f16(test_vec[i].r6), 1);
    simde_test_arm_neon_assert_equal_f16x4(r7, simde_vld1_f16(test_vec[i].r7), 1);
  }

  return 0;
}

static int
test_simde_vfms_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t a[2];
    simde_float32_t b[2];
    simde_float32_t v[4];
    simde_float32_t r0[2];
    simde_float32_t r1[2];
    simde_float32_t r2[2];
    simde_float32_t r3[2];
  } test_vec[] = {
   { {  SIMDE_FLOAT32_C(-153.43837), SIMDE_FLOAT32_C(503.74412) },
     {  SIMDE_FLOAT32_C(-559.77714), SIMDE_FLOAT32_C(-959.16982) },
     {  SIMDE_FLOAT32_C(-830.50913), SIMDE_FLOAT32_C(-66.51184), SIMDE_FLOAT32_C(453.22695), SIMDE_FLOAT32_C(-501.35099) },
     {  SIMDE_FLOAT32_C(-465053.45990), SIMDE_FLOAT32_C(-796095.54394) },
     {  SIMDE_FLOAT32_C(-37385.24475), SIMDE_FLOAT32_C(-63292.40360) },
     {  SIMDE_FLOAT32_C(253552.64714), SIMDE_FLOAT32_C(435225.35681) },
     {  SIMDE_FLOAT32_C(-280798.25826), SIMDE_FLOAT32_C(-480376.99017) } },
   { {  SIMDE_FLOAT32_C(199.60276), SIMDE_FLOAT32_C(-541.95639) },
     {  SIMDE_FLOAT32_C(218.73526), SIMDE_FLOAT32_C(109.17016) },
     {  SIMDE_FLOAT32_C(-726.91525), SIMDE_FLOAT32_C(-486.28244), SIMDE_FLOAT32_C(284.07620), SIMDE_FLOAT32_C(379.83470) },
     {  SIMDE_FLOAT32_C(159201.59736), SIMDE_FLOAT32_C(78815.49873) },
     {  SIMDE_FLOAT32_C(106566.71823), SIMDE_FLOAT32_C(52545.57634) },
     {  SIMDE_FLOAT32_C(-61937.87821), SIMDE_FLOAT32_C(-31554.60104) },
     {  SIMDE_FLOAT32_C(-82883.63698), SIMDE_FLOAT32_C(-42008.57124) } },
   { {  SIMDE_FLOAT32_C(-184.18353), SIMDE_FLOAT32_C(-43.69214) },
     {  SIMDE_FLOAT32_C(-418.67591), SIMDE_FLOAT32_C(856.13203) },
     {  SIMDE_FLOAT32_C(-754.73863), SIMDE_FLOAT32_C(638.29933), SIMDE_FLOAT32_C(927.38787), SIMDE_FLOAT32_C(669.07491) },
     {  SIMDE_FLOAT32_C(-316175.06656), SIMDE_FLOAT32_C(646112.22444) },
     {  SIMDE_FLOAT32_C(267056.36877), SIMDE_FLOAT32_C(-546512.19264) },
     {  SIMDE_FLOAT32_C(388090.77539), SIMDE_FLOAT32_C(-794010.14955) },
     {  SIMDE_FLOAT32_C(279941.36267), SIMDE_FLOAT32_C(-572860.15232) } },
   { {  SIMDE_FLOAT32_C(389.52113), SIMDE_FLOAT32_C(707.84734) },
     {  SIMDE_FLOAT32_C(958.05355), SIMDE_FLOAT32_C(150.29900) },
     {  SIMDE_FLOAT32_C(120.28485), SIMDE_FLOAT32_C(11.61154), SIMDE_FLOAT32_C(-460.14664), SIMDE_FLOAT32_C(-838.47235) },
     {  SIMDE_FLOAT32_C(-114849.80274), SIMDE_FLOAT32_C(-17370.84519) },
     {  SIMDE_FLOAT32_C(-10734.95656), SIMDE_FLOAT32_C(-1037.35565) },
     {  SIMDE_FLOAT32_C(441234.63871), SIMDE_FLOAT32_C(69867.42814) },
     {  SIMDE_FLOAT32_C(803690.93246), SIMDE_FLOAT32_C(126729.40605) } },
   { {  SIMDE_FLOAT32_C(-826.73092), SIMDE_FLOAT32_C(254.89718) },
     {  SIMDE_FLOAT32_C(390.80161), SIMDE_FLOAT32_C(-199.96408) },
     {  SIMDE_FLOAT32_C(-699.09639), SIMDE_FLOAT32_C(-542.77986), SIMDE_FLOAT32_C(-881.29501), SIMDE_FLOAT32_C(-872.41284) },
     {  SIMDE_FLOAT32_C(272381.26620), SIMDE_FLOAT32_C(-139539.26674) },
     {  SIMDE_FLOAT32_C(211292.51312), SIMDE_FLOAT32_C(-108281.57571) },
     {  SIMDE_FLOAT32_C(343584.78183), SIMDE_FLOAT32_C(-175972.44601) },
     {  SIMDE_FLOAT32_C(340113.61461), SIMDE_FLOAT32_C(-174196.33065) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t v = simde_vld1q_f32(test_vec[i].v);
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r0 = simde_vfms_laneq_f32(a, b, v, 0);
    simde_float32x2_t r1 = simde_vfms_laneq_f32(a, b, v, 1);
    simde_float32x2_t r2 = simde_vfms_laneq_f32(a, b, v, 2);
    simde_float32x2_t r3 = simde_vfms_laneq_f32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_f32x2(r0, simde_vld1_f32(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f32x2(r1, simde_vld1_f32(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f32x2(r2, simde_vld1_f32(test_vec[i].r2), 1);
    simde_test_arm_neon_assert_equal_f32x2(r3, simde_vld1_f32(test_vec[i].r3), 1);
  }

  return 0;
}

static int
test_simde_vfms_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64_t a[1];
    simde_float64_t b[1];
    simde_float64_t v[2];
    simde_float64_t r0[1];
    simde_float64_t r1[1];
  } test_vec[] = {
   { {  SIMDE_FLOAT64_C(-3942.86616) },
     {  SIMDE_FLOAT64_C(-9855.76058) },
     {  SIMDE_FLOAT64_C(-1324.65337), SIMDE_FLOAT64_C(822.32748) },
     {  SIMDE_FLOAT64_C(-13059409.32468) },
     {  SIMDE_FLOAT64_C(8100719.88905) } },
   { {  SIMDE_FLOAT64_C(-6732.42544) },
     {  SIMDE_FLOAT64_C(2071.21955) },
     {  SIMDE_FLOAT64_C(4414.34149), SIMDE_FLOAT64_C(-8374.81694) },
     {  SIMDE_FLOAT64_C(-9149802.79669) },
     {  SIMDE_FLOAT64_C(17339352.10646) } },
   { {  SIMDE_FLOAT64_C(-1559.08339) },
     {  SIMDE_FLOAT64_C(1412.37257) },
     {  SIMDE_FLOAT64_C(-4430.92431), SIMDE_FLOAT64_C(3299.93935) },
     {  SIMDE_FLOAT64_C(6256556.86291) },
     {  SIMDE_FLOAT64_C(-4662302.89156) } },
   { {  SIMDE_FLOAT64_C(2969.86908) },
     {  SIMDE_FLOAT64_C(-5042.58214) },
     {  SIMDE_FLOAT64_C(120.53521), SIMDE_FLOAT64_C(-1587.80482) },
     {  SIMDE_FLOAT64_C(610778.54441) },
     {  SIMDE_FLOAT64_C(-8003666.36062) } },
   { {  SIMDE_FLOAT64_C(8478.26755) },
     {  SIMDE_FLOAT64_C(1529.21578) },
     {  SIMDE_FLOAT64_C(5553.07356), SIMDE_FLOAT64_C(5831.98402) },
     {  SIMDE_FLOAT64_C(-8483369.43716) },
     {  SIMDE_FLOAT64_C(-8909883.70655) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t v = simde_vld1q_f64(test_vec[i].v);
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r0 = simde_vfms_laneq_f64(a, b, v, 0);
    simde_float64x1_t r1 = simde_vfms_laneq_f64(a, b, v, 1);
    simde_test_arm_neon_assert_equal_f64x1(r0, simde_vld1_f64(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f64x1(r1, simde_vld1_f64(test_vec[i].r1), 1);
  }

  return 0;
}

static int
test_simde_vfmsq_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[8];
    simde_float16_t b[8];
    simde_float16_t v[4];
    simde_float16_t r0[8];
    simde_float16_t r1[8];
    simde_float16_t r2[8];
    simde_float16_t r3[8];
  } test_vec[] = {
   { {  SIMDE_FLOAT16_VALUE(7.2), SIMDE_FLOAT16_VALUE(5.1), SIMDE_FLOAT16_VALUE(-6.9), SIMDE_FLOAT16_VALUE(-1.9),
        SIMDE_FLOAT16_VALUE(5.5), SIMDE_FLOAT16_VALUE(9.4), SIMDE_FLOAT16_VALUE(-7.9), SIMDE_FLOAT16_VALUE(9.0) },
     {  SIMDE_FLOAT16_VALUE(8.0), SIMDE_FLOAT16_VALUE(0.3), SIMDE_FLOAT16_VALUE(-9.0), SIMDE_FLOAT16_VALUE(-2.9),
        SIMDE_FLOAT16_VALUE(-2.3), SIMDE_FLOAT16_VALUE(6.4), SIMDE_FLOAT16_VALUE(-3.6), SIMDE_FLOAT16_VALUE(-6.1) },
     {  SIMDE_FLOAT16_VALUE(6.4), SIMDE_FLOAT16_VALUE(8.6), SIMDE_FLOAT16_VALUE(8.9), SIMDE_FLOAT16_VALUE(-8.5) },
     {  SIMDE_FLOAT16_VALUE(-44.00), SIMDE_FLOAT16_VALUE(3.18), SIMDE_FLOAT16_VALUE(50.70), SIMDE_FLOAT16_VALUE(16.66),
        SIMDE_FLOAT16_VALUE(20.22), SIMDE_FLOAT16_VALUE(-31.56), SIMDE_FLOAT16_VALUE(15.14), SIMDE_FLOAT16_VALUE(48.04) },
     {  SIMDE_FLOAT16_VALUE(-61.60), SIMDE_FLOAT16_VALUE(2.52), SIMDE_FLOAT16_VALUE(70.50), SIMDE_FLOAT16_VALUE(23.04),
        SIMDE_FLOAT16_VALUE(25.28), SIMDE_FLOAT16_VALUE(-45.64), SIMDE_FLOAT16_VALUE(23.06), SIMDE_FLOAT16_VALUE(61.46) },
     {  SIMDE_FLOAT16_VALUE(-64.00), SIMDE_FLOAT16_VALUE(2.43), SIMDE_FLOAT16_VALUE(73.20), SIMDE_FLOAT16_VALUE(23.91),
        SIMDE_FLOAT16_VALUE(25.97), SIMDE_FLOAT16_VALUE(-47.56), SIMDE_FLOAT16_VALUE(24.14), SIMDE_FLOAT16_VALUE(63.29) },
     {  SIMDE_FLOAT16_VALUE(75.20), SIMDE_FLOAT16_VALUE(7.65), SIMDE_FLOAT16_VALUE(-83.40), SIMDE_FLOAT16_VALUE(-26.55),
        SIMDE_FLOAT16_VALUE(-14.05), SIMDE_FLOAT16_VALUE(63.80), SIMDE_FLOAT16_VALUE(-38.50), SIMDE_FLOAT16_VALUE(-42.85) } },
   { {  SIMDE_FLOAT16_VALUE(-3.6), SIMDE_FLOAT16_VALUE(-1.5), SIMDE_FLOAT16_VALUE(-5.1), SIMDE_FLOAT16_VALUE(-4.9),
        SIMDE_FLOAT16_VALUE(-9.6), SIMDE_FLOAT16_VALUE(-9.3), SIMDE_FLOAT16_VALUE(-2.3), SIMDE_FLOAT16_VALUE(-1.1) },
     {  SIMDE_FLOAT16_VALUE(6.7), SIMDE_FLOAT16_VALUE(-8.0), SIMDE_FLOAT16_VALUE(-9.4), SIMDE_FLOAT16_VALUE(8.3),
        SIMDE_FLOAT16_VALUE(-9.0), SIMDE_FLOAT16_VALUE(-7.0), SIMDE_FLOAT16_VALUE(0.4), SIMDE_FLOAT16_VALUE(-0.1) },
     {  SIMDE_FLOAT16_VALUE(-2.5), SIMDE_FLOAT16_VALUE(-7.0), SIMDE_FLOAT16_VALUE(2.4), SIMDE_FLOAT16_VALUE(7.7) },
     {  SIMDE_FLOAT16_VALUE(13.15), SIMDE_FLOAT16_VALUE(-21.50), SIMDE_FLOAT16_VALUE(-28.60), SIMDE_FLOAT16_VALUE(15.85),
        SIMDE_FLOAT16_VALUE(-32.10), SIMDE_FLOAT16_VALUE(-26.80), SIMDE_FLOAT16_VALUE(-1.30), SIMDE_FLOAT16_VALUE(-1.35) },
     {  SIMDE_FLOAT16_VALUE(43.30), SIMDE_FLOAT16_VALUE(-57.50), SIMDE_FLOAT16_VALUE(-70.90), SIMDE_FLOAT16_VALUE(53.20),
        SIMDE_FLOAT16_VALUE(-72.60), SIMDE_FLOAT16_VALUE(-58.30), SIMDE_FLOAT16_VALUE(0.50), SIMDE_FLOAT16_VALUE(-1.80) },
     {  SIMDE_FLOAT16_VALUE(-19.68), SIMDE_FLOAT16_VALUE(17.70), SIMDE_FLOAT16_VALUE(17.46), SIMDE_FLOAT16_VALUE(-24.82),
        SIMDE_FLOAT16_VALUE(12.00), SIMDE_FLOAT16_VALUE(7.50), SIMDE_FLOAT16_VALUE(-3.26), SIMDE_FLOAT16_VALUE(-0.86) },
     {  SIMDE_FLOAT16_VALUE(-55.19), SIMDE_FLOAT16_VALUE(60.10), SIMDE_FLOAT16_VALUE(67.28), SIMDE_FLOAT16_VALUE(-68.81),
        SIMDE_FLOAT16_VALUE(59.70), SIMDE_FLOAT16_VALUE(44.60), SIMDE_FLOAT16_VALUE(-5.38), SIMDE_FLOAT16_VALUE(-0.33) } },
   { {  SIMDE_FLOAT16_VALUE(-8.6), SIMDE_FLOAT16_VALUE(-2.7), SIMDE_FLOAT16_VALUE(-6.8), SIMDE_FLOAT16_VALUE(-0.6),
        SIMDE_FLOAT16_VALUE(-2.6), SIMDE_FLOAT16_VALUE(-7.1), SIMDE_FLOAT16_VALUE(-8.5), SIMDE_FLOAT16_VALUE(2.5) },
     {  SIMDE_FLOAT16_VALUE(4.9), SIMDE_FLOAT16_VALUE(-0.6), SIMDE_FLOAT16_VALUE(2.5), SIMDE_FLOAT16_VALUE(6.4),
        SIMDE_FLOAT16_VALUE(6.9), SIMDE_FLOAT16_VALUE(-8.7), SIMDE_FLOAT16_VALUE(-4.6), SIMDE_FLOAT16_VALUE(3.9) },
     {  SIMDE_FLOAT16_VALUE(7.8), SIMDE_FLOAT16_VALUE(0.1), SIMDE_FLOAT16_VALUE(9.2), SIMDE_FLOAT16_VALUE(-7.4) },
     {  SIMDE_FLOAT16_VALUE(-46.82), SIMDE_FLOAT16_VALUE(1.98), SIMDE_FLOAT16_VALUE(-26.30), SIMDE_FLOAT16_VALUE(-50.52),
        SIMDE_FLOAT16_VALUE(-56.42), SIMDE_FLOAT16_VALUE(60.76), SIMDE_FLOAT16_VALUE(27.38), SIMDE_FLOAT16_VALUE(-27.92) },
     {  SIMDE_FLOAT16_VALUE(-9.09), SIMDE_FLOAT16_VALUE(-2.64), SIMDE_FLOAT16_VALUE(-7.05), SIMDE_FLOAT16_VALUE(-1.24),
        SIMDE_FLOAT16_VALUE(-3.29), SIMDE_FLOAT16_VALUE(-6.23), SIMDE_FLOAT16_VALUE(-8.04), SIMDE_FLOAT16_VALUE(2.11) },
     {  SIMDE_FLOAT16_VALUE(-53.68), SIMDE_FLOAT16_VALUE(2.82), SIMDE_FLOAT16_VALUE(-29.80), SIMDE_FLOAT16_VALUE(-59.48),
        SIMDE_FLOAT16_VALUE(-66.08), SIMDE_FLOAT16_VALUE(72.94), SIMDE_FLOAT16_VALUE(33.82), SIMDE_FLOAT16_VALUE(-33.38) },
     {  SIMDE_FLOAT16_VALUE(27.66), SIMDE_FLOAT16_VALUE(-7.14), SIMDE_FLOAT16_VALUE(11.70), SIMDE_FLOAT16_VALUE(46.76),
        SIMDE_FLOAT16_VALUE(48.46), SIMDE_FLOAT16_VALUE(-71.48), SIMDE_FLOAT16_VALUE(-42.54), SIMDE_FLOAT16_VALUE(31.36) } },
   { {  SIMDE_FLOAT16_VALUE(9.1), SIMDE_FLOAT16_VALUE(0.5), SIMDE_FLOAT16_VALUE(-8.6), SIMDE_FLOAT16_VALUE(3.7),
        SIMDE_FLOAT16_VALUE(2.3), SIMDE_FLOAT16_VALUE(7.2), SIMDE_FLOAT16_VALUE(5.3), SIMDE_FLOAT16_VALUE(-7.9) },
     {  SIMDE_FLOAT16_VALUE(-0.1), SIMDE_FLOAT16_VALUE(-2.9), SIMDE_FLOAT16_VALUE(-3.2), SIMDE_FLOAT16_VALUE(-5.0),
        SIMDE_FLOAT16_VALUE(0.7), SIMDE_FLOAT16_VALUE(1.1), SIMDE_FLOAT16_VALUE(1.0), SIMDE_FLOAT16_VALUE(7.2) },
     {  SIMDE_FLOAT16_VALUE(-1.1), SIMDE_FLOAT16_VALUE(0.8), SIMDE_FLOAT16_VALUE(-3.6), SIMDE_FLOAT16_VALUE(-4.3) },
     {  SIMDE_FLOAT16_VALUE(8.99), SIMDE_FLOAT16_VALUE(-2.69), SIMDE_FLOAT16_VALUE(-12.12), SIMDE_FLOAT16_VALUE(-1.80),
        SIMDE_FLOAT16_VALUE(3.07), SIMDE_FLOAT16_VALUE(8.41), SIMDE_FLOAT16_VALUE(6.40), SIMDE_FLOAT16_VALUE(0.02) },
     {  SIMDE_FLOAT16_VALUE(9.18), SIMDE_FLOAT16_VALUE(2.82), SIMDE_FLOAT16_VALUE(-6.04), SIMDE_FLOAT16_VALUE(7.70),
        SIMDE_FLOAT16_VALUE(1.74), SIMDE_FLOAT16_VALUE(6.32), SIMDE_FLOAT16_VALUE(4.50), SIMDE_FLOAT16_VALUE(-13.66) },
     {  SIMDE_FLOAT16_VALUE(8.74), SIMDE_FLOAT16_VALUE(-9.94), SIMDE_FLOAT16_VALUE(-20.12), SIMDE_FLOAT16_VALUE(-14.30),
        SIMDE_FLOAT16_VALUE(4.82), SIMDE_FLOAT16_VALUE(11.16), SIMDE_FLOAT16_VALUE(8.90), SIMDE_FLOAT16_VALUE(18.02) },
     {  SIMDE_FLOAT16_VALUE(8.67), SIMDE_FLOAT16_VALUE(-11.97), SIMDE_FLOAT16_VALUE(-22.36), SIMDE_FLOAT16_VALUE(-17.80),
        SIMDE_FLOAT16_VALUE(5.31), SIMDE_FLOAT16_VALUE(11.93), SIMDE_FLOAT16_VALUE(9.60), SIMDE_FLOAT16_VALUE(23.06) } },
   { {  SIMDE_FLOAT16_VALUE(2.6), SIMDE_FLOAT16_VALUE(7.6), SIMDE_FLOAT16_VALUE(0.9), SIMDE_FLOAT16_VALUE(4.6),
        SIMDE_FLOAT16_VALUE(-9.5), SIMDE_FLOAT16_VALUE(-4.1), SIMDE_FLOAT16_VALUE(-1.3), SIMDE_FLOAT16_VALUE(3.7) },
     {  SIMDE_FLOAT16_VALUE(10.0), SIMDE_FLOAT16_VALUE(4.4), SIMDE_FLOAT16_VALUE(2.9), SIMDE_FLOAT16_VALUE(-0.2),
        SIMDE_FLOAT16_VALUE(-4.8), SIMDE_FLOAT16_VALUE(4.2), SIMDE_FLOAT16_VALUE(-5.3), SIMDE_FLOAT16_VALUE(8.1) },
     {  SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(4.5), SIMDE_FLOAT16_VALUE(-2.7), SIMDE_FLOAT16_VALUE(-7.2) },
     {  SIMDE_FLOAT16_VALUE(-30.40), SIMDE_FLOAT16_VALUE(-6.92), SIMDE_FLOAT16_VALUE(-8.67), SIMDE_FLOAT16_VALUE(5.26),
        SIMDE_FLOAT16_VALUE(6.34), SIMDE_FLOAT16_VALUE(-17.96), SIMDE_FLOAT16_VALUE(16.19), SIMDE_FLOAT16_VALUE(-23.03) },
     {  SIMDE_FLOAT16_VALUE(-42.40), SIMDE_FLOAT16_VALUE(-12.20), SIMDE_FLOAT16_VALUE(-12.15), SIMDE_FLOAT16_VALUE(5.50),
        SIMDE_FLOAT16_VALUE(12.10), SIMDE_FLOAT16_VALUE(-23.00), SIMDE_FLOAT16_VALUE(22.55), SIMDE_FLOAT16_VALUE(-32.75) },
     {  SIMDE_FLOAT16_VALUE(29.60), SIMDE_FLOAT16_VALUE(19.48), SIMDE_FLOAT16_VALUE(8.73), SIMDE_FLOAT16_VALUE(4.06),
        SIMDE_FLOAT16_VALUE(-22.46), SIMDE_FLOAT16_VALUE(7.24), SIMDE_FLOAT16_VALUE(-15.61), SIMDE_FLOAT16_VALUE(25.57) },
     {  SIMDE_FLOAT16_VALUE(74.60), SIMDE_FLOAT16_VALUE(39.28), SIMDE_FLOAT16_VALUE(21.78), SIMDE_FLOAT16_VALUE(3.16),
        SIMDE_FLOAT16_VALUE(-44.06), SIMDE_FLOAT16_VALUE(26.14), SIMDE_FLOAT16_VALUE(-39.46), SIMDE_FLOAT16_VALUE(62.02) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t v = simde_vld1_f16(test_vec[i].v);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r0 = simde_vfmsq_lane_f16(a, b, v, 0);
    simde_float16x8_t r1 = simde_vfmsq_lane_f16(a, b, v, 1);
    simde_float16x8_t r2 = simde_vfmsq_lane_f16(a, b, v, 2);
    simde_float16x8_t r3 = simde_vfmsq_lane_f16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_f16x8(r0, simde_vld1q_f16(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f16x8(r1, simde_vld1q_f16(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f16x8(r2, simde_vld1q_f16(test_vec[i].r2), 1);
    simde_test_arm_neon_assert_equal_f16x8(r3, simde_vld1q_f16(test_vec[i].r3), 1);
  }

  return 0;
}

static int
test_simde_vfmsq_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t a[4];
    simde_float32_t b[4];
    simde_float32_t v[2];
    simde_float32_t r0[4];
    simde_float32_t r1[4];
  } test_vec[] = {
   { {  SIMDE_FLOAT32_C(259.18173), SIMDE_FLOAT32_C(-982.71656), SIMDE_FLOAT32_C(201.04464), SIMDE_FLOAT32_C(-839.59556) },
     {  SIMDE_FLOAT32_C(-687.10042), SIMDE_FLOAT32_C(-248.92711), SIMDE_FLOAT32_C(499.97356), SIMDE_FLOAT32_C(96.80549) },
     {  SIMDE_FLOAT32_C(-737.85009), SIMDE_FLOAT32_C(806.59386) },
     {  SIMDE_FLOAT32_C(-506717.92770), SIMDE_FLOAT32_C(-184653.60658), SIMDE_FLOAT32_C(369106.58433), SIMDE_FLOAT32_C(70588.34750) },
     {  SIMDE_FLOAT32_C(554470.16094), SIMDE_FLOAT32_C(199800.36006), SIMDE_FLOAT32_C(-403074.56009), SIMDE_FLOAT32_C(-78922.31276) } },
   { {  SIMDE_FLOAT32_C(-776.04346), SIMDE_FLOAT32_C(312.16529), SIMDE_FLOAT32_C(-469.69252), SIMDE_FLOAT32_C(-755.31740) },
     {  SIMDE_FLOAT32_C(-350.36425), SIMDE_FLOAT32_C(20.89342), SIMDE_FLOAT32_C(289.86478), SIMDE_FLOAT32_C(421.10273) },
     {  SIMDE_FLOAT32_C(718.18823), SIMDE_FLOAT32_C(-40.43155) },
     {  SIMDE_FLOAT32_C(250851.43555), SIMDE_FLOAT32_C(-14693.24359), SIMDE_FLOAT32_C(-208647.17036), SIMDE_FLOAT32_C(-303186.34346) },
     {  SIMDE_FLOAT32_C(-14941.81202), SIMDE_FLOAT32_C(1156.91861), SIMDE_FLOAT32_C(11249.98922), SIMDE_FLOAT32_C(16270.51753) } },
   { {  SIMDE_FLOAT32_C(-17.44808), SIMDE_FLOAT32_C(993.72564), SIMDE_FLOAT32_C(-520.55389), SIMDE_FLOAT32_C(-398.75283) },
     {  SIMDE_FLOAT32_C(822.00589), SIMDE_FLOAT32_C(-197.83084), SIMDE_FLOAT32_C(498.70719), SIMDE_FLOAT32_C(280.02367) },
     {  SIMDE_FLOAT32_C(476.70933), SIMDE_FLOAT32_C(-342.78566) },
     {  SIMDE_FLOAT32_C(-391875.32565), SIMDE_FLOAT32_C(95301.53498), SIMDE_FLOAT32_C(-238258.92417), SIMDE_FLOAT32_C(-133888.64830) },
     {  SIMDE_FLOAT32_C(281754.38103), SIMDE_FLOAT32_C(-66819.85030), SIMDE_FLOAT32_C(170429.11759), SIMDE_FLOAT32_C(95589.34431) } },
   { {  SIMDE_FLOAT32_C(-984.28741), SIMDE_FLOAT32_C(709.24134), SIMDE_FLOAT32_C(-294.78043), SIMDE_FLOAT32_C(863.91755) },
     {  SIMDE_FLOAT32_C(341.83247), SIMDE_FLOAT32_C(-465.47732), SIMDE_FLOAT32_C(-676.53834), SIMDE_FLOAT32_C(565.41989) },
     {  SIMDE_FLOAT32_C(-776.90809), SIMDE_FLOAT32_C(925.68351) },
     {  SIMDE_FLOAT32_C(264588.12256), SIMDE_FLOAT32_C(-360923.85159), SIMDE_FLOAT32_C(-525902.89051), SIMDE_FLOAT32_C(440143.20642) },
     {  SIMDE_FLOAT32_C(-317412.96628), SIMDE_FLOAT32_C(431593.91738), SIMDE_FLOAT32_C(625965.60519), SIMDE_FLOAT32_C(-522535.95314) } },
   { {  SIMDE_FLOAT32_C(-234.32520), SIMDE_FLOAT32_C(-246.62651), SIMDE_FLOAT32_C(673.43551), SIMDE_FLOAT32_C(11.13586) },
     {  SIMDE_FLOAT32_C(732.20479), SIMDE_FLOAT32_C(99.78277), SIMDE_FLOAT32_C(-699.98007), SIMDE_FLOAT32_C(903.21751) },
     {  SIMDE_FLOAT32_C(-579.16182), SIMDE_FLOAT32_C(-231.83252) },
     {  SIMDE_FLOAT32_C(423830.73321), SIMDE_FLOAT32_C(57543.74672), SIMDE_FLOAT32_C(-404728.29923), SIMDE_FLOAT32_C(523120.23775) },
     {  SIMDE_FLOAT32_C(169514.55746), SIMDE_FLOAT32_C(22886.26570), SIMDE_FLOAT32_C(-161604.71058), SIMDE_FLOAT32_C(209406.33076) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t v = simde_vld1_f32(test_vec[i].v);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r0 = simde_vfmsq_lane_f32(a, b, v, 0);
    simde_float32x4_t r1 = simde_vfmsq_lane_f32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_f32x4(r0, simde_vld1q_f32(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f32x4(r1, simde_vld1q_f32(test_vec[i].r1), 1);
  }

  return 0;
}

static int
test_simde_vfmsq_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64_t a[2];
    simde_float64_t b[2];
    simde_float64_t v[1];
    simde_float64_t r0[2];
  } test_vec[] = {
   { {  SIMDE_FLOAT64_C(821.28925), SIMDE_FLOAT64_C(-6342.69479) },
     {  SIMDE_FLOAT64_C(9166.38887), SIMDE_FLOAT64_C(-5790.51734) },
     {  SIMDE_FLOAT64_C(-8262.79545) },
     {  SIMDE_FLOAT64_C(75740817.56570), SIMDE_FLOAT64_C(-47852203.03573) } },
   { {  SIMDE_FLOAT64_C(-5785.12562), SIMDE_FLOAT64_C(4386.72108) },
     {  SIMDE_FLOAT64_C(-687.24970), SIMDE_FLOAT64_C(5209.94217) },
     {  SIMDE_FLOAT64_C(3279.55066) },
     {  SIMDE_FLOAT64_C(2248085.06744), SIMDE_FLOAT64_C(-17081882.53329) } },
   { {  SIMDE_FLOAT64_C(8966.81503), SIMDE_FLOAT64_C(-850.87370) },
     {  SIMDE_FLOAT64_C(-6534.17860), SIMDE_FLOAT64_C(8038.77118) },
     {  SIMDE_FLOAT64_C(9244.64824) },
     {  SIMDE_FLOAT64_C(60415149.50670), SIMDE_FLOAT64_C(-74316462.72382) } },
   { {  SIMDE_FLOAT64_C(-5290.76223), SIMDE_FLOAT64_C(4570.18419) },
     {  SIMDE_FLOAT64_C(-7944.64530), SIMDE_FLOAT64_C(-541.83675) },
     {  SIMDE_FLOAT64_C(1903.77031) },
     {  SIMDE_FLOAT64_C(15119489.05151), SIMDE_FLOAT64_C(1036102.89044) } },
   { {  SIMDE_FLOAT64_C(1856.12192), SIMDE_FLOAT64_C(1962.01446) },
     {  SIMDE_FLOAT64_C(-7579.59161), SIMDE_FLOAT64_C(-5421.01685) },
     {  SIMDE_FLOAT64_C(-209.85312) },
     {  SIMDE_FLOAT64_C(-1588744.85381), SIMDE_FLOAT64_C(-1135655.30540) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t v = simde_vld1_f64(test_vec[i].v);
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r0 = simde_vfmsq_lane_f64(a, b, v, 0);
    simde_test_arm_neon_assert_equal_f64x2(r0, simde_vld1q_f64(test_vec[i].r0), 1);
  }

  return 0;
}

static int
test_simde_vfmsq_laneq_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[8];
    simde_float16_t b[8];
    simde_float16_t v[8];
    simde_float16_t r0[8];
    simde_float16_t r1[8];
    simde_float16_t r2[8];
    simde_float16_t r3[8];
    simde_float16_t r4[8];
    simde_float16_t r5[8];
    simde_float16_t r6[8];
    simde_float16_t r7[8];
  } test_vec[] = {
   { {  SIMDE_FLOAT16_VALUE(-3.3), SIMDE_FLOAT16_VALUE(2.3), SIMDE_FLOAT16_VALUE(2.6), SIMDE_FLOAT16_VALUE(7.1),
        SIMDE_FLOAT16_VALUE(4.9), SIMDE_FLOAT16_VALUE(-0.6), SIMDE_FLOAT16_VALUE(7.4), SIMDE_FLOAT16_VALUE(9.3) },
     {  SIMDE_FLOAT16_VALUE(-9.7), SIMDE_FLOAT16_VALUE(9.6), SIMDE_FLOAT16_VALUE(-9.9), SIMDE_FLOAT16_VALUE(0.0),
        SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(-4.9), SIMDE_FLOAT16_VALUE(-4.6), SIMDE_FLOAT16_VALUE(7.7) },
     {  SIMDE_FLOAT16_VALUE(-1.3), SIMDE_FLOAT16_VALUE(0.7), SIMDE_FLOAT16_VALUE(-9.7), SIMDE_FLOAT16_VALUE(9.8),
        SIMDE_FLOAT16_VALUE(7.7), SIMDE_FLOAT16_VALUE(7.1), SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(-9.2) },
     {  SIMDE_FLOAT16_VALUE(-15.91), SIMDE_FLOAT16_VALUE(14.78), SIMDE_FLOAT16_VALUE(-10.27), SIMDE_FLOAT16_VALUE(7.10),
        SIMDE_FLOAT16_VALUE(9.19), SIMDE_FLOAT16_VALUE(-6.97), SIMDE_FLOAT16_VALUE(1.42), SIMDE_FLOAT16_VALUE(19.31) },
     {  SIMDE_FLOAT16_VALUE(3.49), SIMDE_FLOAT16_VALUE(-4.42), SIMDE_FLOAT16_VALUE(9.53), SIMDE_FLOAT16_VALUE(7.10),
        SIMDE_FLOAT16_VALUE(2.59), SIMDE_FLOAT16_VALUE(2.83), SIMDE_FLOAT16_VALUE(10.62), SIMDE_FLOAT16_VALUE(3.91) },
     {  SIMDE_FLOAT16_VALUE(-97.39), SIMDE_FLOAT16_VALUE(95.42), SIMDE_FLOAT16_VALUE(-93.43), SIMDE_FLOAT16_VALUE(7.10),
        SIMDE_FLOAT16_VALUE(36.91), SIMDE_FLOAT16_VALUE(-48.13), SIMDE_FLOAT16_VALUE(-37.22), SIMDE_FLOAT16_VALUE(83.99) },
     {  SIMDE_FLOAT16_VALUE(91.76), SIMDE_FLOAT16_VALUE(-91.78), SIMDE_FLOAT16_VALUE(99.62), SIMDE_FLOAT16_VALUE(7.10),
        SIMDE_FLOAT16_VALUE(-27.44), SIMDE_FLOAT16_VALUE(47.42), SIMDE_FLOAT16_VALUE(52.48), SIMDE_FLOAT16_VALUE(-66.16) },
     {  SIMDE_FLOAT16_VALUE(71.39), SIMDE_FLOAT16_VALUE(-71.62), SIMDE_FLOAT16_VALUE(78.83), SIMDE_FLOAT16_VALUE(7.10),
        SIMDE_FLOAT16_VALUE(-20.51), SIMDE_FLOAT16_VALUE(37.13), SIMDE_FLOAT16_VALUE(42.82), SIMDE_FLOAT16_VALUE(-49.99) },
     {  SIMDE_FLOAT16_VALUE(65.57), SIMDE_FLOAT16_VALUE(-65.86), SIMDE_FLOAT16_VALUE(72.89), SIMDE_FLOAT16_VALUE(7.10),
        SIMDE_FLOAT16_VALUE(-18.53), SIMDE_FLOAT16_VALUE(34.19), SIMDE_FLOAT16_VALUE(40.06), SIMDE_FLOAT16_VALUE(-45.37) },
     {  SIMDE_FLOAT16_VALUE(10.28), SIMDE_FLOAT16_VALUE(-11.14), SIMDE_FLOAT16_VALUE(16.46), SIMDE_FLOAT16_VALUE(7.10),
        SIMDE_FLOAT16_VALUE(0.28), SIMDE_FLOAT16_VALUE(6.26), SIMDE_FLOAT16_VALUE(13.84), SIMDE_FLOAT16_VALUE(-1.48) },
     {  SIMDE_FLOAT16_VALUE(-92.54), SIMDE_FLOAT16_VALUE(90.62), SIMDE_FLOAT16_VALUE(-88.48), SIMDE_FLOAT16_VALUE(7.10),
        SIMDE_FLOAT16_VALUE(35.26), SIMDE_FLOAT16_VALUE(-45.68), SIMDE_FLOAT16_VALUE(-34.92), SIMDE_FLOAT16_VALUE(80.14) } },
   { {  SIMDE_FLOAT16_VALUE(-2.0), SIMDE_FLOAT16_VALUE(-7.1), SIMDE_FLOAT16_VALUE(-7.2), SIMDE_FLOAT16_VALUE(-7.1),
        SIMDE_FLOAT16_VALUE(-8.4), SIMDE_FLOAT16_VALUE(-0.1), SIMDE_FLOAT16_VALUE(-2.9), SIMDE_FLOAT16_VALUE(-1.5) },
     {  SIMDE_FLOAT16_VALUE(0.4), SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(-0.3), SIMDE_FLOAT16_VALUE(-3.0),
        SIMDE_FLOAT16_VALUE(-1.0), SIMDE_FLOAT16_VALUE(0.8), SIMDE_FLOAT16_VALUE(-2.7), SIMDE_FLOAT16_VALUE(-8.8) },
     {  SIMDE_FLOAT16_VALUE(2.7), SIMDE_FLOAT16_VALUE(-7.8), SIMDE_FLOAT16_VALUE(2.6), SIMDE_FLOAT16_VALUE(-0.8),
        SIMDE_FLOAT16_VALUE(1.3), SIMDE_FLOAT16_VALUE(6.0), SIMDE_FLOAT16_VALUE(-8.7), SIMDE_FLOAT16_VALUE(4.7) },
     {  SIMDE_FLOAT16_VALUE(-3.08), SIMDE_FLOAT16_VALUE(-16.01), SIMDE_FLOAT16_VALUE(-6.39), SIMDE_FLOAT16_VALUE(1.00),
        SIMDE_FLOAT16_VALUE(-5.70), SIMDE_FLOAT16_VALUE(-2.26), SIMDE_FLOAT16_VALUE(4.39), SIMDE_FLOAT16_VALUE(22.26) },
     {  SIMDE_FLOAT16_VALUE(1.12), SIMDE_FLOAT16_VALUE(18.64), SIMDE_FLOAT16_VALUE(-9.54), SIMDE_FLOAT16_VALUE(-30.50),
        SIMDE_FLOAT16_VALUE(-16.20), SIMDE_FLOAT16_VALUE(6.14), SIMDE_FLOAT16_VALUE(-23.96), SIMDE_FLOAT16_VALUE(-70.14) },
     {  SIMDE_FLOAT16_VALUE(-3.04), SIMDE_FLOAT16_VALUE(-15.68), SIMDE_FLOAT16_VALUE(-6.42), SIMDE_FLOAT16_VALUE(0.70),
        SIMDE_FLOAT16_VALUE(-5.80), SIMDE_FLOAT16_VALUE(-2.18), SIMDE_FLOAT16_VALUE(4.12), SIMDE_FLOAT16_VALUE(21.38) },
     {  SIMDE_FLOAT16_VALUE(-1.68), SIMDE_FLOAT16_VALUE(-4.46), SIMDE_FLOAT16_VALUE(-7.44), SIMDE_FLOAT16_VALUE(-9.50),
        SIMDE_FLOAT16_VALUE(-9.20), SIMDE_FLOAT16_VALUE(0.54), SIMDE_FLOAT16_VALUE(-5.06), SIMDE_FLOAT16_VALUE(-8.54) },
     {  SIMDE_FLOAT16_VALUE(-2.52), SIMDE_FLOAT16_VALUE(-11.39), SIMDE_FLOAT16_VALUE(-6.81), SIMDE_FLOAT16_VALUE(-3.20),
        SIMDE_FLOAT16_VALUE(-7.10), SIMDE_FLOAT16_VALUE(-1.14), SIMDE_FLOAT16_VALUE(0.61), SIMDE_FLOAT16_VALUE(9.94) },
     {  SIMDE_FLOAT16_VALUE(-4.40), SIMDE_FLOAT16_VALUE(-26.90), SIMDE_FLOAT16_VALUE(-5.40), SIMDE_FLOAT16_VALUE(10.90),
        SIMDE_FLOAT16_VALUE(-2.40), SIMDE_FLOAT16_VALUE(-4.90), SIMDE_FLOAT16_VALUE(13.30), SIMDE_FLOAT16_VALUE(51.30) },
     {  SIMDE_FLOAT16_VALUE(1.48), SIMDE_FLOAT16_VALUE(21.61), SIMDE_FLOAT16_VALUE(-9.81), SIMDE_FLOAT16_VALUE(-33.20),
        SIMDE_FLOAT16_VALUE(-17.10), SIMDE_FLOAT16_VALUE(6.86), SIMDE_FLOAT16_VALUE(-26.39), SIMDE_FLOAT16_VALUE(-78.06) },
     {  SIMDE_FLOAT16_VALUE(-3.88), SIMDE_FLOAT16_VALUE(-22.61), SIMDE_FLOAT16_VALUE(-5.79), SIMDE_FLOAT16_VALUE(7.00),
        SIMDE_FLOAT16_VALUE(-3.70), SIMDE_FLOAT16_VALUE(-3.86), SIMDE_FLOAT16_VALUE(9.79), SIMDE_FLOAT16_VALUE(39.86) } },
   { {  SIMDE_FLOAT16_VALUE(-5.1), SIMDE_FLOAT16_VALUE(-4.8), SIMDE_FLOAT16_VALUE(2.8), SIMDE_FLOAT16_VALUE(6.7),
        SIMDE_FLOAT16_VALUE(4.0), SIMDE_FLOAT16_VALUE(-3.1), SIMDE_FLOAT16_VALUE(-2.8), SIMDE_FLOAT16_VALUE(5.0) },
     {  SIMDE_FLOAT16_VALUE(1.3), SIMDE_FLOAT16_VALUE(-7.7), SIMDE_FLOAT16_VALUE(4.8), SIMDE_FLOAT16_VALUE(2.2),
        SIMDE_FLOAT16_VALUE(-4.5), SIMDE_FLOAT16_VALUE(3.7), SIMDE_FLOAT16_VALUE(2.8), SIMDE_FLOAT16_VALUE(-4.0) },
     {  SIMDE_FLOAT16_VALUE(-2.4), SIMDE_FLOAT16_VALUE(-1.9), SIMDE_FLOAT16_VALUE(3.6), SIMDE_FLOAT16_VALUE(0.7),
        SIMDE_FLOAT16_VALUE(7.3), SIMDE_FLOAT16_VALUE(6.4), SIMDE_FLOAT16_VALUE(4.1), SIMDE_FLOAT16_VALUE(1.7) },
     {  SIMDE_FLOAT16_VALUE(-1.98), SIMDE_FLOAT16_VALUE(-23.28), SIMDE_FLOAT16_VALUE(14.32), SIMDE_FLOAT16_VALUE(11.98),
        SIMDE_FLOAT16_VALUE(-6.80), SIMDE_FLOAT16_VALUE(5.78), SIMDE_FLOAT16_VALUE(3.92), SIMDE_FLOAT16_VALUE(-4.60) },
     {  SIMDE_FLOAT16_VALUE(-2.63), SIMDE_FLOAT16_VALUE(-19.43), SIMDE_FLOAT16_VALUE(11.92), SIMDE_FLOAT16_VALUE(10.88),
        SIMDE_FLOAT16_VALUE(-4.55), SIMDE_FLOAT16_VALUE(3.93), SIMDE_FLOAT16_VALUE(2.52), SIMDE_FLOAT16_VALUE(-2.60) },
     {  SIMDE_FLOAT16_VALUE(-9.78), SIMDE_FLOAT16_VALUE(22.92), SIMDE_FLOAT16_VALUE(-14.48), SIMDE_FLOAT16_VALUE(-1.22),
        SIMDE_FLOAT16_VALUE(20.20), SIMDE_FLOAT16_VALUE(-16.42), SIMDE_FLOAT16_VALUE(-12.88), SIMDE_FLOAT16_VALUE(19.40) },
     {  SIMDE_FLOAT16_VALUE(-6.01), SIMDE_FLOAT16_VALUE(0.59), SIMDE_FLOAT16_VALUE(-0.56), SIMDE_FLOAT16_VALUE(5.16),
        SIMDE_FLOAT16_VALUE(7.15), SIMDE_FLOAT16_VALUE(-5.69), SIMDE_FLOAT16_VALUE(-4.76), SIMDE_FLOAT16_VALUE(7.80) },
     {  SIMDE_FLOAT16_VALUE(-14.59), SIMDE_FLOAT16_VALUE(51.41), SIMDE_FLOAT16_VALUE(-32.24), SIMDE_FLOAT16_VALUE(-9.36),
        SIMDE_FLOAT16_VALUE(36.85), SIMDE_FLOAT16_VALUE(-30.11), SIMDE_FLOAT16_VALUE(-23.24), SIMDE_FLOAT16_VALUE(34.20) },
     {  SIMDE_FLOAT16_VALUE(-13.42), SIMDE_FLOAT16_VALUE(44.48), SIMDE_FLOAT16_VALUE(-27.92), SIMDE_FLOAT16_VALUE(-7.38),
        SIMDE_FLOAT16_VALUE(32.80), SIMDE_FLOAT16_VALUE(-26.78), SIMDE_FLOAT16_VALUE(-20.72), SIMDE_FLOAT16_VALUE(30.60) },
     {  SIMDE_FLOAT16_VALUE(-10.43), SIMDE_FLOAT16_VALUE(26.77), SIMDE_FLOAT16_VALUE(-16.88), SIMDE_FLOAT16_VALUE(-2.32),
        SIMDE_FLOAT16_VALUE(22.45), SIMDE_FLOAT16_VALUE(-18.27), SIMDE_FLOAT16_VALUE(-14.28), SIMDE_FLOAT16_VALUE(21.40) },
     {  SIMDE_FLOAT16_VALUE(-7.31), SIMDE_FLOAT16_VALUE(8.29), SIMDE_FLOAT16_VALUE(-5.36), SIMDE_FLOAT16_VALUE(2.96),
        SIMDE_FLOAT16_VALUE(11.65), SIMDE_FLOAT16_VALUE(-9.39), SIMDE_FLOAT16_VALUE(-7.56), SIMDE_FLOAT16_VALUE(11.80) } },
   { {  SIMDE_FLOAT16_VALUE(-2.4), SIMDE_FLOAT16_VALUE(4.8), SIMDE_FLOAT16_VALUE(3.5), SIMDE_FLOAT16_VALUE(-2.1),
        SIMDE_FLOAT16_VALUE(5.3), SIMDE_FLOAT16_VALUE(5.1), SIMDE_FLOAT16_VALUE(5.0), SIMDE_FLOAT16_VALUE(3.5) },
     {  SIMDE_FLOAT16_VALUE(5.5), SIMDE_FLOAT16_VALUE(-8.7), SIMDE_FLOAT16_VALUE(3.2), SIMDE_FLOAT16_VALUE(1.4),
        SIMDE_FLOAT16_VALUE(-7.7), SIMDE_FLOAT16_VALUE(4.1), SIMDE_FLOAT16_VALUE(9.4), SIMDE_FLOAT16_VALUE(-8.2) },
     {  SIMDE_FLOAT16_VALUE(4.9), SIMDE_FLOAT16_VALUE(-7.7), SIMDE_FLOAT16_VALUE(-1.5), SIMDE_FLOAT16_VALUE(-1.4),
        SIMDE_FLOAT16_VALUE(0.0), SIMDE_FLOAT16_VALUE(6.1), SIMDE_FLOAT16_VALUE(3.4), SIMDE_FLOAT16_VALUE(0.1) },
     {  SIMDE_FLOAT16_VALUE(-29.35), SIMDE_FLOAT16_VALUE(47.43), SIMDE_FLOAT16_VALUE(-12.18), SIMDE_FLOAT16_VALUE(-8.96),
        SIMDE_FLOAT16_VALUE(43.03), SIMDE_FLOAT16_VALUE(-14.99), SIMDE_FLOAT16_VALUE(-41.06), SIMDE_FLOAT16_VALUE(43.68) },
     {  SIMDE_FLOAT16_VALUE(39.95), SIMDE_FLOAT16_VALUE(-62.19), SIMDE_FLOAT16_VALUE(28.14), SIMDE_FLOAT16_VALUE(8.68),
        SIMDE_FLOAT16_VALUE(-53.99), SIMDE_FLOAT16_VALUE(36.67), SIMDE_FLOAT16_VALUE(77.38), SIMDE_FLOAT16_VALUE(-59.64) },
     {  SIMDE_FLOAT16_VALUE(5.85), SIMDE_FLOAT16_VALUE(-8.25), SIMDE_FLOAT16_VALUE(8.30), SIMDE_FLOAT16_VALUE(-0.00),
        SIMDE_FLOAT16_VALUE(-6.25), SIMDE_FLOAT16_VALUE(11.25), SIMDE_FLOAT16_VALUE(19.10), SIMDE_FLOAT16_VALUE(-8.80) },
     {  SIMDE_FLOAT16_VALUE(5.30), SIMDE_FLOAT16_VALUE(-7.38), SIMDE_FLOAT16_VALUE(7.98), SIMDE_FLOAT16_VALUE(-0.14),
        SIMDE_FLOAT16_VALUE(-5.48), SIMDE_FLOAT16_VALUE(10.84), SIMDE_FLOAT16_VALUE(18.16), SIMDE_FLOAT16_VALUE(-7.98) },
     {  SIMDE_FLOAT16_VALUE(-2.40), SIMDE_FLOAT16_VALUE(4.80), SIMDE_FLOAT16_VALUE(3.50), SIMDE_FLOAT16_VALUE(-2.10),
        SIMDE_FLOAT16_VALUE(5.30), SIMDE_FLOAT16_VALUE(5.10), SIMDE_FLOAT16_VALUE(5.00), SIMDE_FLOAT16_VALUE(3.50) },
     {  SIMDE_FLOAT16_VALUE(-35.95), SIMDE_FLOAT16_VALUE(57.87), SIMDE_FLOAT16_VALUE(-16.02), SIMDE_FLOAT16_VALUE(-10.64),
        SIMDE_FLOAT16_VALUE(52.27), SIMDE_FLOAT16_VALUE(-19.91), SIMDE_FLOAT16_VALUE(-52.34), SIMDE_FLOAT16_VALUE(53.52) },
     {  SIMDE_FLOAT16_VALUE(-21.10), SIMDE_FLOAT16_VALUE(34.38), SIMDE_FLOAT16_VALUE(-7.38), SIMDE_FLOAT16_VALUE(-6.86),
        SIMDE_FLOAT16_VALUE(31.48), SIMDE_FLOAT16_VALUE(-8.84), SIMDE_FLOAT16_VALUE(-26.96), SIMDE_FLOAT16_VALUE(31.38) },
     {  SIMDE_FLOAT16_VALUE(-2.95), SIMDE_FLOAT16_VALUE(5.67), SIMDE_FLOAT16_VALUE(3.18), SIMDE_FLOAT16_VALUE(-2.24),
        SIMDE_FLOAT16_VALUE(6.07), SIMDE_FLOAT16_VALUE(4.69), SIMDE_FLOAT16_VALUE(4.06), SIMDE_FLOAT16_VALUE(4.32) } },
   { {  SIMDE_FLOAT16_VALUE(-6.3), SIMDE_FLOAT16_VALUE(7.2), SIMDE_FLOAT16_VALUE(6.8), SIMDE_FLOAT16_VALUE(3.2),
        SIMDE_FLOAT16_VALUE(-7.6), SIMDE_FLOAT16_VALUE(5.6), SIMDE_FLOAT16_VALUE(5.7), SIMDE_FLOAT16_VALUE(3.3) },
     {  SIMDE_FLOAT16_VALUE(8.6), SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(-6.4), SIMDE_FLOAT16_VALUE(-1.8),
        SIMDE_FLOAT16_VALUE(7.2), SIMDE_FLOAT16_VALUE(3.7), SIMDE_FLOAT16_VALUE(0.2), SIMDE_FLOAT16_VALUE(2.6) },
     {  SIMDE_FLOAT16_VALUE(-3.5), SIMDE_FLOAT16_VALUE(6.8), SIMDE_FLOAT16_VALUE(-4.2), SIMDE_FLOAT16_VALUE(-5.3),
        SIMDE_FLOAT16_VALUE(-0.7), SIMDE_FLOAT16_VALUE(-4.7), SIMDE_FLOAT16_VALUE(8.2), SIMDE_FLOAT16_VALUE(6.6) },
     {  SIMDE_FLOAT16_VALUE(23.80), SIMDE_FLOAT16_VALUE(18.75), SIMDE_FLOAT16_VALUE(-15.60), SIMDE_FLOAT16_VALUE(-3.10),
        SIMDE_FLOAT16_VALUE(17.60), SIMDE_FLOAT16_VALUE(18.55), SIMDE_FLOAT16_VALUE(6.40), SIMDE_FLOAT16_VALUE(12.40) },
     {  SIMDE_FLOAT16_VALUE(-64.78), SIMDE_FLOAT16_VALUE(-15.24), SIMDE_FLOAT16_VALUE(50.32), SIMDE_FLOAT16_VALUE(15.44),
        SIMDE_FLOAT16_VALUE(-56.56), SIMDE_FLOAT16_VALUE(-19.56), SIMDE_FLOAT16_VALUE(4.34), SIMDE_FLOAT16_VALUE(-14.38) },
     {  SIMDE_FLOAT16_VALUE(29.82), SIMDE_FLOAT16_VALUE(21.06), SIMDE_FLOAT16_VALUE(-20.08), SIMDE_FLOAT16_VALUE(-4.36),
        SIMDE_FLOAT16_VALUE(22.64), SIMDE_FLOAT16_VALUE(21.14), SIMDE_FLOAT16_VALUE(6.54), SIMDE_FLOAT16_VALUE(14.22) },
     {  SIMDE_FLOAT16_VALUE(39.28), SIMDE_FLOAT16_VALUE(24.69), SIMDE_FLOAT16_VALUE(-27.12), SIMDE_FLOAT16_VALUE(-6.34),
        SIMDE_FLOAT16_VALUE(30.56), SIMDE_FLOAT16_VALUE(25.21), SIMDE_FLOAT16_VALUE(6.76), SIMDE_FLOAT16_VALUE(17.08) },
     {  SIMDE_FLOAT16_VALUE(-0.28), SIMDE_FLOAT16_VALUE(9.51), SIMDE_FLOAT16_VALUE(2.32), SIMDE_FLOAT16_VALUE(1.94),
        SIMDE_FLOAT16_VALUE(-2.56), SIMDE_FLOAT16_VALUE(8.19), SIMDE_FLOAT16_VALUE(5.84), SIMDE_FLOAT16_VALUE(5.12) },
     {  SIMDE_FLOAT16_VALUE(34.12), SIMDE_FLOAT16_VALUE(22.71), SIMDE_FLOAT16_VALUE(-23.28), SIMDE_FLOAT16_VALUE(-5.26),
        SIMDE_FLOAT16_VALUE(26.24), SIMDE_FLOAT16_VALUE(22.99), SIMDE_FLOAT16_VALUE(6.64), SIMDE_FLOAT16_VALUE(15.52) },
     {  SIMDE_FLOAT16_VALUE(-76.82), SIMDE_FLOAT16_VALUE(-19.86), SIMDE_FLOAT16_VALUE(59.28), SIMDE_FLOAT16_VALUE(17.96),
        SIMDE_FLOAT16_VALUE(-66.64), SIMDE_FLOAT16_VALUE(-24.74), SIMDE_FLOAT16_VALUE(4.06), SIMDE_FLOAT16_VALUE(-18.02) },
     {  SIMDE_FLOAT16_VALUE(-63.06), SIMDE_FLOAT16_VALUE(-14.58), SIMDE_FLOAT16_VALUE(49.04), SIMDE_FLOAT16_VALUE(15.08),
        SIMDE_FLOAT16_VALUE(-55.12), SIMDE_FLOAT16_VALUE(-18.82), SIMDE_FLOAT16_VALUE(4.38), SIMDE_FLOAT16_VALUE(-13.86) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t v = simde_vld1q_f16(test_vec[i].v);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r0 = simde_vfmsq_laneq_f16(a, b, v, 0);
    simde_float16x8_t r1 = simde_vfmsq_laneq_f16(a, b, v, 1);
    simde_float16x8_t r2 = simde_vfmsq_laneq_f16(a, b, v, 2);
    simde_float16x8_t r3 = simde_vfmsq_laneq_f16(a, b, v, 3);
    simde_float16x8_t r4 = simde_vfmsq_laneq_f16(a, b, v, 4);
    simde_float16x8_t r5 = simde_vfmsq_laneq_f16(a, b, v, 5);
    simde_float16x8_t r6 = simde_vfmsq_laneq_f16(a, b, v, 6);
    simde_float16x8_t r7 = simde_vfmsq_laneq_f16(a, b, v, 7);
    simde_test_arm_neon_assert_equal_f16x8(r0, simde_vld1q_f16(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f16x8(r1, simde_vld1q_f16(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f16x8(r2, simde_vld1q_f16(test_vec[i].r2), 1);
    simde_test_arm_neon_assert_equal_f16x8(r3, simde_vld1q_f16(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f16x8(r4, simde_vld1q_f16(test_vec[i].r4), 1);
    simde_test_arm_neon_assert_equal_f16x8(r5, simde_vld1q_f16(test_vec[i].r5), 1);
    simde_test_arm_neon_assert_equal_f16x8(r6, simde_vld1q_f16(test_vec[i].r6), 1);
    simde_test_arm_neon_assert_equal_f16x8(r7, simde_vld1q_f16(test_vec[i].r7), 1);
  }

  return 0;
}

static int
test_simde_vfmsq_laneq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t a[4];
    simde_float32_t b[4];
    simde_float32_t v[4];
    simde_float32_t r0[4];
    simde_float32_t r1[4];
    simde_float32_t r2[4];
    simde_float32_t r3[4];
  } test_vec[] = {
   { {  SIMDE_FLOAT32_C(102.82656), SIMDE_FLOAT32_C(951.11129), SIMDE_FLOAT32_C(2.40355), SIMDE_FLOAT32_C(-369.45028) },
     {  SIMDE_FLOAT32_C(888.92002), SIMDE_FLOAT32_C(-752.99577), SIMDE_FLOAT32_C(-939.64723), SIMDE_FLOAT32_C(960.22599) },
     {  SIMDE_FLOAT32_C(-371.75725), SIMDE_FLOAT32_C(966.75005), SIMDE_FLOAT32_C(-45.49931), SIMDE_FLOAT32_C(-821.43020) },
     {  SIMDE_FLOAT32_C(330565.28534), SIMDE_FLOAT32_C(-278980.52517), SIMDE_FLOAT32_C(-349318.26573), SIMDE_FLOAT32_C(356601.51932) },
     {  SIMDE_FLOAT32_C(-859260.64451), SIMDE_FLOAT32_C(728909.81394), SIMDE_FLOAT32_C(908406.41405), SIMDE_FLOAT32_C(-928667.97061) },
     {  SIMDE_FLOAT32_C(40548.07757), SIMDE_FLOAT32_C(-33309.67992), SIMDE_FLOAT32_C(-42750.90103), SIMDE_FLOAT32_C(43320.17341) },
     {  SIMDE_FLOAT32_C(730288.57064), SIMDE_FLOAT32_C(-617582.35546), SIMDE_FLOAT32_C(-771852.20821), SIMDE_FLOAT32_C(788389.17004) } },
   { {  SIMDE_FLOAT32_C(-291.65071), SIMDE_FLOAT32_C(-154.24511), SIMDE_FLOAT32_C(527.37848), SIMDE_FLOAT32_C(-472.25705) },
     {  SIMDE_FLOAT32_C(-390.25343), SIMDE_FLOAT32_C(-977.99004), SIMDE_FLOAT32_C(-648.10719), SIMDE_FLOAT32_C(-638.11574) },
     {  SIMDE_FLOAT32_C(241.11814), SIMDE_FLOAT32_C(-231.93603), SIMDE_FLOAT32_C(5.65139), SIMDE_FLOAT32_C(808.77716) },
     {  SIMDE_FLOAT32_C(93805.53156), SIMDE_FLOAT32_C(235656.89555), SIMDE_FLOAT32_C(156797.78003), SIMDE_FLOAT32_C(153389.02404) },
     {  SIMDE_FLOAT32_C(-90805.48206), SIMDE_FLOAT32_C(-226985.37115), SIMDE_FLOAT32_C(-149792.02989), SIMDE_FLOAT32_C(-148474.28760) },
     {  SIMDE_FLOAT32_C(1913.82518), SIMDE_FLOAT32_C(5372.76190), SIMDE_FLOAT32_C(4190.08756), SIMDE_FLOAT32_C(3133.98639) },
     {  SIMDE_FLOAT32_C(315336.41460), SIMDE_FLOAT32_C(790821.76825), SIMDE_FLOAT32_C(524701.67695), SIMDE_FLOAT32_C(515621.18274) } },
   { {  SIMDE_FLOAT32_C(-479.10655), SIMDE_FLOAT32_C(450.71118), SIMDE_FLOAT32_C(-184.72924), SIMDE_FLOAT32_C(-676.51379) },
     {  SIMDE_FLOAT32_C(-275.05178), SIMDE_FLOAT32_C(688.51605), SIMDE_FLOAT32_C(-579.44131), SIMDE_FLOAT32_C(565.66724) },
     {  SIMDE_FLOAT32_C(244.78459), SIMDE_FLOAT32_C(355.79255), SIMDE_FLOAT32_C(-611.21600), SIMDE_FLOAT32_C(-983.17422) },
     {  SIMDE_FLOAT32_C(66849.33234), SIMDE_FLOAT32_C(-168087.41123), SIMDE_FLOAT32_C(141653.57685), SIMDE_FLOAT32_C(-139143.14072) },
     {  SIMDE_FLOAT32_C(97382.26797), SIMDE_FLOAT32_C(-244518.16959), SIMDE_FLOAT32_C(205976.17132), SIMDE_FLOAT32_C(-201936.70429) },
     {  SIMDE_FLOAT32_C(-168595.15677), SIMDE_FLOAT32_C(421282.73879), SIMDE_FLOAT32_C(-354348.52963), SIMDE_FLOAT32_C(345068.35705) },
     {  SIMDE_FLOAT32_C(-270902.92683), SIMDE_FLOAT32_C(677381.94084), SIMDE_FLOAT32_C(-569876.48550), SIMDE_FLOAT32_C(555472.93590) } },
   { {  SIMDE_FLOAT32_C(598.94398), SIMDE_FLOAT32_C(-678.76233), SIMDE_FLOAT32_C(525.14756), SIMDE_FLOAT32_C(-393.56775) },
     {  SIMDE_FLOAT32_C(270.63878), SIMDE_FLOAT32_C(62.33552), SIMDE_FLOAT32_C(532.73637), SIMDE_FLOAT32_C(-53.87204) },
     {  SIMDE_FLOAT32_C(-402.56303), SIMDE_FLOAT32_C(-875.39401), SIMDE_FLOAT32_C(-525.16995), SIMDE_FLOAT32_C(0.83003) },
     {  SIMDE_FLOAT32_C(109548.11225), SIMDE_FLOAT32_C(24415.21183), SIMDE_FLOAT32_C(214985.11298), SIMDE_FLOAT32_C(-22080.45814) },
     {  SIMDE_FLOAT32_C(237514.51413), SIMDE_FLOAT32_C(53889.37518), SIMDE_FLOAT32_C(466879.37302), SIMDE_FLOAT32_C(-47552.82637) },
     {  SIMDE_FLOAT32_C(142730.30110), SIMDE_FLOAT32_C(32057.97775), SIMDE_FLOAT32_C(280302.28049), SIMDE_FLOAT32_C(-28685.54292) },
     {  SIMDE_FLOAT32_C(374.30701), SIMDE_FLOAT32_C(-730.50237), SIMDE_FLOAT32_C(82.96301), SIMDE_FLOAT32_C(-348.85261) } },
   { {  SIMDE_FLOAT32_C(-230.44369), SIMDE_FLOAT32_C(-546.43451), SIMDE_FLOAT32_C(-247.60873), SIMDE_FLOAT32_C(644.18364) },
     {  SIMDE_FLOAT32_C(-992.70944), SIMDE_FLOAT32_C(100.10228), SIMDE_FLOAT32_C(892.71396), SIMDE_FLOAT32_C(179.76280) },
     {  SIMDE_FLOAT32_C(-390.46056), SIMDE_FLOAT32_C(-238.49889), SIMDE_FLOAT32_C(-25.44016), SIMDE_FLOAT32_C(716.38644) },
     {  SIMDE_FLOAT32_C(-387844.33013), SIMDE_FLOAT32_C(38539.55701), SIMDE_FLOAT32_C(348321.98658), SIMDE_FLOAT32_C(70834.46651) },
     {  SIMDE_FLOAT32_C(-236990.53963), SIMDE_FLOAT32_C(23327.84715), SIMDE_FLOAT32_C(212663.67675), SIMDE_FLOAT32_C(43517.41055) },
     {  SIMDE_FLOAT32_C(-25485.13297), SIMDE_FLOAT32_C(2000.18367), SIMDE_FLOAT32_C(22463.17933), SIMDE_FLOAT32_C(5217.37838) },
     {  SIMDE_FLOAT32_C(710933.13081), SIMDE_FLOAT32_C(-72258.34787), SIMDE_FLOAT32_C(-639775.77848), SIMDE_FLOAT32_C(-128135.44528) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t v = simde_vld1q_f32(test_vec[i].v);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r0 = simde_vfmsq_laneq_f32(a, b, v, 0);
    simde_float32x4_t r1 = simde_vfmsq_laneq_f32(a, b, v, 1);
    simde_float32x4_t r2 = simde_vfmsq_laneq_f32(a, b, v, 2);
    simde_float32x4_t r3 = simde_vfmsq_laneq_f32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_f32x4(r0, simde_vld1q_f32(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f32x4(r1, simde_vld1q_f32(test_vec[i].r1), 1);
    simde_test_arm_neon_assert_equal_f32x4(r2, simde_vld1q_f32(test_vec[i].r2), 1);
    simde_test_arm_neon_assert_equal_f32x4(r3, simde_vld1q_f32(test_vec[i].r3), 1);
  }

  return 0;
}

static int
test_simde_vfmsq_laneq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64_t a[2];
    simde_float64_t b[2];
    simde_float64_t v[2];
    simde_float64_t r0[2];
    simde_float64_t r1[2];
  } test_vec[] = {
   { {  SIMDE_FLOAT64_C(2111.40644), SIMDE_FLOAT64_C(147.93113) },
     {  SIMDE_FLOAT64_C(3281.30423), SIMDE_FLOAT64_C(-5219.67760) },
     {  SIMDE_FLOAT64_C(3585.45315), SIMDE_FLOAT64_C(4506.84828) },
     {  SIMDE_FLOAT64_C(-11762851.19121), SIMDE_FLOAT64_C(18715057.43867) },
     {  SIMDE_FLOAT64_C(-14786228.90247), SIMDE_FLOAT64_C(23524442.91725) } },
   { {  SIMDE_FLOAT64_C(-4250.80606), SIMDE_FLOAT64_C(9340.30783) },
     {  SIMDE_FLOAT64_C(-7342.00142), SIMDE_FLOAT64_C(-727.71775) },
     {  SIMDE_FLOAT64_C(4396.54168), SIMDE_FLOAT64_C(-6058.97674) },
     {  SIMDE_FLOAT64_C(32275164.39840), SIMDE_FLOAT64_C(3208781.71167) },
     {  SIMDE_FLOAT64_C(-44489266.61039), SIMDE_FLOAT64_C(-4399884.59644) } },
   { {  SIMDE_FLOAT64_C(959.96052), SIMDE_FLOAT64_C(-3408.84969) },
     {  SIMDE_FLOAT64_C(-93.01932), SIMDE_FLOAT64_C(-346.20674) },
     {  SIMDE_FLOAT64_C(3686.43292), SIMDE_FLOAT64_C(-4978.44355) },
     {  SIMDE_FLOAT64_C(343869.43298), SIMDE_FLOAT64_C(1272859.08246) },
     {  SIMDE_FLOAT64_C(-462131.45820), SIMDE_FLOAT64_C(-1726979.57269) } },
   { {  SIMDE_FLOAT64_C(-4180.69522), SIMDE_FLOAT64_C(3331.97653) },
     {  SIMDE_FLOAT64_C(215.33179), SIMDE_FLOAT64_C(4094.47228) },
     {  SIMDE_FLOAT64_C(-7142.91683), SIMDE_FLOAT64_C(-4136.77211) },
     {  SIMDE_FLOAT64_C(1533916.38871), SIMDE_FLOAT64_C(29249806.96093) },
     {  SIMDE_FLOAT64_C(886597.85719), SIMDE_FLOAT64_C(16941230.70986) } },
   { {  SIMDE_FLOAT64_C(-2499.69552), SIMDE_FLOAT64_C(4103.78549) },
     {  SIMDE_FLOAT64_C(-6459.94724), SIMDE_FLOAT64_C(5532.81151) },
     {  SIMDE_FLOAT64_C(4249.54527), SIMDE_FLOAT64_C(1730.69927) },
     {  SIMDE_FLOAT64_C(27449338.55907), SIMDE_FLOAT64_C(-23507829.21384) },
     {  SIMDE_FLOAT64_C(11177726.29310), SIMDE_FLOAT64_C(-9571529.07100) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t v = simde_vld1q_f64(test_vec[i].v);
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r0 = simde_vfmsq_laneq_f64(a, b, v, 0);
    simde_float64x2_t r1 = simde_vfmsq_laneq_f64(a, b, v, 1);
    simde_test_arm_neon_assert_equal_f64x2(r0, simde_vld1q_f64(test_vec[i].r0), 1);
    simde_test_arm_neon_assert_equal_f64x2(r1, simde_vld1q_f64(test_vec[i].r1), 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vfmsd_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmsd_laneq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmss_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmss_laneq_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmsh_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmsh_laneq_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfms_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfms_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfms_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vfms_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfms_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfms_laneq_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmsq_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmsq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmsq_lane_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmsq_laneq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmsq_laneq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmsq_laneq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
