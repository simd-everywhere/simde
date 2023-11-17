#define SIMDE_TEST_ARM_NEON_INSN ld3_dup

#include "test-neon.h"
#include "../../../simde/arm/neon/ld3_dup.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld3_dup_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[3];
    simde_float16_t unused[3];
    simde_float16_t r[3][4];
  } test_vec[] = {
     { {  SIMDE_FLOAT16_VALUE(-6.58), SIMDE_FLOAT16_VALUE(2.17), SIMDE_FLOAT16_VALUE(3.51) },
       {  SIMDE_FLOAT16_VALUE(-28.23), SIMDE_FLOAT16_VALUE(27.18), SIMDE_FLOAT16_VALUE(21.06)},
     { {  SIMDE_FLOAT16_VALUE(-6.58), SIMDE_FLOAT16_VALUE(-6.58), SIMDE_FLOAT16_VALUE(-6.58), SIMDE_FLOAT16_VALUE(-6.58) },
       {  SIMDE_FLOAT16_VALUE(2.17), SIMDE_FLOAT16_VALUE(2.17), SIMDE_FLOAT16_VALUE(2.17), SIMDE_FLOAT16_VALUE(2.17) },
       {  SIMDE_FLOAT16_VALUE(3.51), SIMDE_FLOAT16_VALUE(3.51), SIMDE_FLOAT16_VALUE(3.51), SIMDE_FLOAT16_VALUE(3.51) } } },
     { {  SIMDE_FLOAT16_VALUE(-46.99), SIMDE_FLOAT16_VALUE(-6.72), SIMDE_FLOAT16_VALUE(41.08) },
       {  SIMDE_FLOAT16_VALUE(-2.06), SIMDE_FLOAT16_VALUE(-6.78), SIMDE_FLOAT16_VALUE(36.58)},
     { {  SIMDE_FLOAT16_VALUE(-46.99), SIMDE_FLOAT16_VALUE(-46.99), SIMDE_FLOAT16_VALUE(-46.99), SIMDE_FLOAT16_VALUE(-46.99) },
       {  SIMDE_FLOAT16_VALUE(-6.72), SIMDE_FLOAT16_VALUE(-6.72), SIMDE_FLOAT16_VALUE(-6.72), SIMDE_FLOAT16_VALUE(-6.72) },
       {  SIMDE_FLOAT16_VALUE(41.08), SIMDE_FLOAT16_VALUE(41.08), SIMDE_FLOAT16_VALUE(41.08), SIMDE_FLOAT16_VALUE(41.08) } } },
     { {  SIMDE_FLOAT16_VALUE(39.86), SIMDE_FLOAT16_VALUE(40.77), SIMDE_FLOAT16_VALUE(-32.22) },
       {  SIMDE_FLOAT16_VALUE(-24.94), SIMDE_FLOAT16_VALUE(-38.80), SIMDE_FLOAT16_VALUE(7.87)},
     { {  SIMDE_FLOAT16_VALUE(39.86), SIMDE_FLOAT16_VALUE(39.86), SIMDE_FLOAT16_VALUE(39.86), SIMDE_FLOAT16_VALUE(39.86) },
       {  SIMDE_FLOAT16_VALUE(40.77), SIMDE_FLOAT16_VALUE(40.77), SIMDE_FLOAT16_VALUE(40.77), SIMDE_FLOAT16_VALUE(40.77) },
       {  SIMDE_FLOAT16_VALUE(-32.22), SIMDE_FLOAT16_VALUE(-32.22), SIMDE_FLOAT16_VALUE(-32.22), SIMDE_FLOAT16_VALUE(-32.22) } } },
     { {  SIMDE_FLOAT16_VALUE(3.72), SIMDE_FLOAT16_VALUE(45.41), SIMDE_FLOAT16_VALUE(4.48) },
       {  SIMDE_FLOAT16_VALUE(47.09), SIMDE_FLOAT16_VALUE(-24.14), SIMDE_FLOAT16_VALUE(-0.13)},
     { {  SIMDE_FLOAT16_VALUE(3.72), SIMDE_FLOAT16_VALUE(3.72), SIMDE_FLOAT16_VALUE(3.72), SIMDE_FLOAT16_VALUE(3.72) },
       {  SIMDE_FLOAT16_VALUE(45.41), SIMDE_FLOAT16_VALUE(45.41), SIMDE_FLOAT16_VALUE(45.41), SIMDE_FLOAT16_VALUE(45.41) },
       {  SIMDE_FLOAT16_VALUE(4.48), SIMDE_FLOAT16_VALUE(4.48), SIMDE_FLOAT16_VALUE(4.48), SIMDE_FLOAT16_VALUE(4.48) } } },
     { {  SIMDE_FLOAT16_VALUE(-31.75), SIMDE_FLOAT16_VALUE(20.34), SIMDE_FLOAT16_VALUE(-29.59) },
       {  SIMDE_FLOAT16_VALUE(-11.56), SIMDE_FLOAT16_VALUE(-7.53), SIMDE_FLOAT16_VALUE(28.61)},
     { {  SIMDE_FLOAT16_VALUE(-31.75), SIMDE_FLOAT16_VALUE(-31.75), SIMDE_FLOAT16_VALUE(-31.75), SIMDE_FLOAT16_VALUE(-31.75) },
       {  SIMDE_FLOAT16_VALUE(20.34), SIMDE_FLOAT16_VALUE(20.34), SIMDE_FLOAT16_VALUE(20.34), SIMDE_FLOAT16_VALUE(20.34) },
       {  SIMDE_FLOAT16_VALUE(-29.59), SIMDE_FLOAT16_VALUE(-29.59), SIMDE_FLOAT16_VALUE(-29.59), SIMDE_FLOAT16_VALUE(-29.59) } } },
     { {  SIMDE_FLOAT16_VALUE(37.05), SIMDE_FLOAT16_VALUE(17.72), SIMDE_FLOAT16_VALUE(-49.37) },
       {  SIMDE_FLOAT16_VALUE(-27.61), SIMDE_FLOAT16_VALUE(-29.16), SIMDE_FLOAT16_VALUE(2.30)},
     { {  SIMDE_FLOAT16_VALUE(37.05), SIMDE_FLOAT16_VALUE(37.05), SIMDE_FLOAT16_VALUE(37.05), SIMDE_FLOAT16_VALUE(37.05) },
       {  SIMDE_FLOAT16_VALUE(17.72), SIMDE_FLOAT16_VALUE(17.72), SIMDE_FLOAT16_VALUE(17.72), SIMDE_FLOAT16_VALUE(17.72) },
       {  SIMDE_FLOAT16_VALUE(-49.37), SIMDE_FLOAT16_VALUE(-49.37), SIMDE_FLOAT16_VALUE(-49.37), SIMDE_FLOAT16_VALUE(-49.37) } } },
     { {  SIMDE_FLOAT16_VALUE(-49.24), SIMDE_FLOAT16_VALUE(-2.48), SIMDE_FLOAT16_VALUE(-45.21) },
       {  SIMDE_FLOAT16_VALUE(19.81), SIMDE_FLOAT16_VALUE(5.79), SIMDE_FLOAT16_VALUE(42.08)},
     { {  SIMDE_FLOAT16_VALUE(-49.24), SIMDE_FLOAT16_VALUE(-49.24), SIMDE_FLOAT16_VALUE(-49.24), SIMDE_FLOAT16_VALUE(-49.24) },
       {  SIMDE_FLOAT16_VALUE(-2.48), SIMDE_FLOAT16_VALUE(-2.48), SIMDE_FLOAT16_VALUE(-2.48), SIMDE_FLOAT16_VALUE(-2.48) },
       {  SIMDE_FLOAT16_VALUE(-45.21), SIMDE_FLOAT16_VALUE(-45.21), SIMDE_FLOAT16_VALUE(-45.21), SIMDE_FLOAT16_VALUE(-45.21) } } },
     { {  SIMDE_FLOAT16_VALUE(26.41), SIMDE_FLOAT16_VALUE(49.96), SIMDE_FLOAT16_VALUE(20.11) },
       {  SIMDE_FLOAT16_VALUE(34.64), SIMDE_FLOAT16_VALUE(-7.87), SIMDE_FLOAT16_VALUE(-43.78)},
     { {  SIMDE_FLOAT16_VALUE(26.41), SIMDE_FLOAT16_VALUE(26.41), SIMDE_FLOAT16_VALUE(26.41), SIMDE_FLOAT16_VALUE(26.41) },
       {  SIMDE_FLOAT16_VALUE(49.96), SIMDE_FLOAT16_VALUE(49.96), SIMDE_FLOAT16_VALUE(49.96), SIMDE_FLOAT16_VALUE(49.96) },
       {  SIMDE_FLOAT16_VALUE(20.11), SIMDE_FLOAT16_VALUE(20.11), SIMDE_FLOAT16_VALUE(20.11), SIMDE_FLOAT16_VALUE(20.11) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4x3_t r = simde_vld3_dup_f16(test_vec[i].a);
    simde_float16x4x3_t expected = {
        {simde_vld1_f16(test_vec[i].r[0]), simde_vld1_f16(test_vec[i].r[1]), simde_vld1_f16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_f16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3_dup_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[3];
    float unused[3];
    float r[3][2];
  } test_vec[] = {
     { {  SIMDE_FLOAT32_C(-2382.50), SIMDE_FLOAT32_C(1337.52), SIMDE_FLOAT32_C(-2555.52) },
       {  SIMDE_FLOAT32_C(2329.55), SIMDE_FLOAT32_C(-2887.02), SIMDE_FLOAT32_C(-1085.66)},
     { {  SIMDE_FLOAT32_C(-2382.50), SIMDE_FLOAT32_C(-2382.50) },
       {  SIMDE_FLOAT32_C(1337.52), SIMDE_FLOAT32_C(1337.52) },
       {  SIMDE_FLOAT32_C(-2555.52), SIMDE_FLOAT32_C(-2555.52) } } },
     { {  SIMDE_FLOAT32_C(-4735.63), SIMDE_FLOAT32_C(-1105.19), SIMDE_FLOAT32_C(2348.59) },
       {  SIMDE_FLOAT32_C(1863.06), SIMDE_FLOAT32_C(-2989.05), SIMDE_FLOAT32_C(3957.38)},
     { {  SIMDE_FLOAT32_C(-4735.63), SIMDE_FLOAT32_C(-4735.63) },
       {  SIMDE_FLOAT32_C(-1105.19), SIMDE_FLOAT32_C(-1105.19) },
       {  SIMDE_FLOAT32_C(2348.59), SIMDE_FLOAT32_C(2348.59) } } },
     { {  SIMDE_FLOAT32_C(-2290.48), SIMDE_FLOAT32_C(1772.72), SIMDE_FLOAT32_C(4473.71) },
       {  SIMDE_FLOAT32_C(-2560.60), SIMDE_FLOAT32_C(-3282.98), SIMDE_FLOAT32_C(-4654.17)},
     { {  SIMDE_FLOAT32_C(-2290.48), SIMDE_FLOAT32_C(-2290.48) },
       {  SIMDE_FLOAT32_C(1772.72), SIMDE_FLOAT32_C(1772.72) },
       {  SIMDE_FLOAT32_C(4473.71), SIMDE_FLOAT32_C(4473.71) } } },
     { {  SIMDE_FLOAT32_C(2639.57), SIMDE_FLOAT32_C(-2227.82), SIMDE_FLOAT32_C(4717.55) },
       {  SIMDE_FLOAT32_C(4303.36), SIMDE_FLOAT32_C(-1218.20), SIMDE_FLOAT32_C(3830.48)},
     { {  SIMDE_FLOAT32_C(2639.57), SIMDE_FLOAT32_C(2639.57) },
       {  SIMDE_FLOAT32_C(-2227.82), SIMDE_FLOAT32_C(-2227.82) },
       {  SIMDE_FLOAT32_C(4717.55), SIMDE_FLOAT32_C(4717.55) } } },
     { {  SIMDE_FLOAT32_C(2452.62), SIMDE_FLOAT32_C(1625.56), SIMDE_FLOAT32_C(-228.25) },
       {  SIMDE_FLOAT32_C(-1171.56), SIMDE_FLOAT32_C(1910.83), SIMDE_FLOAT32_C(3954.71)},
     { {  SIMDE_FLOAT32_C(2452.62), SIMDE_FLOAT32_C(2452.62) },
       {  SIMDE_FLOAT32_C(1625.56), SIMDE_FLOAT32_C(1625.56) },
       {  SIMDE_FLOAT32_C(-228.25), SIMDE_FLOAT32_C(-228.25) } } },
     { {  SIMDE_FLOAT32_C(-2742.46), SIMDE_FLOAT32_C(3293.38), SIMDE_FLOAT32_C(346.01) },
       {  SIMDE_FLOAT32_C(4929.24), SIMDE_FLOAT32_C(2432.88), SIMDE_FLOAT32_C(1629.40)},
     { {  SIMDE_FLOAT32_C(-2742.46), SIMDE_FLOAT32_C(-2742.46) },
       {  SIMDE_FLOAT32_C(3293.38), SIMDE_FLOAT32_C(3293.38) },
       {  SIMDE_FLOAT32_C(346.01), SIMDE_FLOAT32_C(346.01) } } },
     { {  SIMDE_FLOAT32_C(4711.75), SIMDE_FLOAT32_C(4806.28), SIMDE_FLOAT32_C(941.70) },
       {  SIMDE_FLOAT32_C(572.76), SIMDE_FLOAT32_C(2872.54), SIMDE_FLOAT32_C(2021.90)},
     { {  SIMDE_FLOAT32_C(4711.75), SIMDE_FLOAT32_C(4711.75) },
       {  SIMDE_FLOAT32_C(4806.28), SIMDE_FLOAT32_C(4806.28) },
       {  SIMDE_FLOAT32_C(941.70), SIMDE_FLOAT32_C(941.70) } } },
     { {  SIMDE_FLOAT32_C(4312.83), SIMDE_FLOAT32_C(-1093.57), SIMDE_FLOAT32_C(-4143.46) },
       {  SIMDE_FLOAT32_C(-73.76), SIMDE_FLOAT32_C(4246.17), SIMDE_FLOAT32_C(-233.49)},
     { {  SIMDE_FLOAT32_C(4312.83), SIMDE_FLOAT32_C(4312.83) },
       {  SIMDE_FLOAT32_C(-1093.57), SIMDE_FLOAT32_C(-1093.57) },
       {  SIMDE_FLOAT32_C(-4143.46), SIMDE_FLOAT32_C(-4143.46) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x3_t r = simde_vld3_dup_f32(test_vec[i].a);
    simde_float32x2x3_t expected = {
        {simde_vld1_f32(test_vec[i].r[0]), simde_vld1_f32(test_vec[i].r[1]), simde_vld1_f32(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_f32x2(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3_dup_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[3];
    simde_float64 unused[3];
    simde_float64 r[3][1];
  } test_vec[] = {
     { {  SIMDE_FLOAT64_C(236226.67), SIMDE_FLOAT64_C(192939.74), SIMDE_FLOAT64_C(384504.37) },
       {  SIMDE_FLOAT64_C(-378339.05), SIMDE_FLOAT64_C(76696.47), SIMDE_FLOAT64_C(438417.90)},
     { {  SIMDE_FLOAT64_C(236226.67) },
       {  SIMDE_FLOAT64_C(192939.74) },
       {  SIMDE_FLOAT64_C(384504.37) } } },
     { {  SIMDE_FLOAT64_C(144897.63), SIMDE_FLOAT64_C(483753.45), SIMDE_FLOAT64_C(-377140.44) },
       {  SIMDE_FLOAT64_C(-21825.93), SIMDE_FLOAT64_C(429765.52), SIMDE_FLOAT64_C(43437.54)},
     { {  SIMDE_FLOAT64_C(144897.63) },
       {  SIMDE_FLOAT64_C(483753.45) },
       {  SIMDE_FLOAT64_C(-377140.44) } } },
     { {  SIMDE_FLOAT64_C(394483.35), SIMDE_FLOAT64_C(-488967.56), SIMDE_FLOAT64_C(-59025.38) },
       {  SIMDE_FLOAT64_C(-493532.19), SIMDE_FLOAT64_C(-466855.88), SIMDE_FLOAT64_C(-38442.08)},
     { {  SIMDE_FLOAT64_C(394483.35) },
       {  SIMDE_FLOAT64_C(-488967.56) },
       {  SIMDE_FLOAT64_C(-59025.38) } } },
     { {  SIMDE_FLOAT64_C(354858.43), SIMDE_FLOAT64_C(-400360.87), SIMDE_FLOAT64_C(375674.67) },
       {  SIMDE_FLOAT64_C(-20167.12), SIMDE_FLOAT64_C(-172548.28), SIMDE_FLOAT64_C(-108982.35)},
     { {  SIMDE_FLOAT64_C(354858.43) },
       {  SIMDE_FLOAT64_C(-400360.87) },
       {  SIMDE_FLOAT64_C(375674.67) } } },
     { {  SIMDE_FLOAT64_C(379531.80), SIMDE_FLOAT64_C(-427312.47), SIMDE_FLOAT64_C(-243573.72) },
       {  SIMDE_FLOAT64_C(-414651.89), SIMDE_FLOAT64_C(174702.00), SIMDE_FLOAT64_C(56533.13)},
     { {  SIMDE_FLOAT64_C(379531.80) },
       {  SIMDE_FLOAT64_C(-427312.47) },
       {  SIMDE_FLOAT64_C(-243573.72) } } },
     { {  SIMDE_FLOAT64_C(8488.31), SIMDE_FLOAT64_C(-324836.80), SIMDE_FLOAT64_C(-438953.32) },
       {  SIMDE_FLOAT64_C(-109126.89), SIMDE_FLOAT64_C(-388098.72), SIMDE_FLOAT64_C(-93955.75)},
     { {  SIMDE_FLOAT64_C(8488.31) },
       {  SIMDE_FLOAT64_C(-324836.80) },
       {  SIMDE_FLOAT64_C(-438953.32) } } },
     { {  SIMDE_FLOAT64_C(-446810.13), SIMDE_FLOAT64_C(-275424.67), SIMDE_FLOAT64_C(453798.55) },
       {  SIMDE_FLOAT64_C(493858.73), SIMDE_FLOAT64_C(73175.04), SIMDE_FLOAT64_C(-101153.68)},
     { {  SIMDE_FLOAT64_C(-446810.13) },
       {  SIMDE_FLOAT64_C(-275424.67) },
       {  SIMDE_FLOAT64_C(453798.55) } } },
     { {  SIMDE_FLOAT64_C(183424.28), SIMDE_FLOAT64_C(115671.75), SIMDE_FLOAT64_C(165990.60) },
       {  SIMDE_FLOAT64_C(-460186.50), SIMDE_FLOAT64_C(408473.34), SIMDE_FLOAT64_C(85833.78)},
     { {  SIMDE_FLOAT64_C(183424.28) },
       {  SIMDE_FLOAT64_C(115671.75) },
       {  SIMDE_FLOAT64_C(165990.60) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x3_t r = simde_vld3_dup_f64(test_vec[i].a);
    simde_float64x1x3_t expected = {
        {simde_vld1_f64(test_vec[i].r[0]), simde_vld1_f64(test_vec[i].r[1]), simde_vld1_f64(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_f64x1(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x1(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x1(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3_dup_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[3];
    int8_t unused[3];
    int8_t r[3][8];
  } test_vec[] = {
     { {  INT8_C(55), -INT8_C(67), INT8_C(34) },
       {  -INT8_C(4), INT8_C(29), INT8_C(62)},
     { {  INT8_C(55), INT8_C(55), INT8_C(55), INT8_C(55),
        INT8_C(55), INT8_C(55), INT8_C(55), INT8_C(55) },
       {  -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67),
        -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67) },
       {  INT8_C(34), INT8_C(34), INT8_C(34), INT8_C(34),
        INT8_C(34), INT8_C(34), INT8_C(34), INT8_C(34) } } },
     { {  INT8_C(58), INT8_C(53), INT8_C(86) },
       {  INT8_C(5), INT8_C(6), -INT8_C(5)},
     { {  INT8_C(58), INT8_C(58), INT8_C(58), INT8_C(58),
        INT8_C(58), INT8_C(58), INT8_C(58), INT8_C(58) },
       {  INT8_C(53), INT8_C(53), INT8_C(53), INT8_C(53),
        INT8_C(53), INT8_C(53), INT8_C(53), INT8_C(53) },
       {  INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86),
        INT8_C(86), INT8_C(86), INT8_C(86), INT8_C(86) } } },
     { {  INT8_C(92), -INT8_C(1), -INT8_C(94) },
       {  -INT8_C(6), INT8_C(61), -INT8_C(61)},
     { {  INT8_C(92), INT8_C(92), INT8_C(92), INT8_C(92),
        INT8_C(92), INT8_C(92), INT8_C(92), INT8_C(92) },
       {  -INT8_C(1), -INT8_C(1), -INT8_C(1), -INT8_C(1),
        -INT8_C(1), -INT8_C(1), -INT8_C(1), -INT8_C(1) },
       {  -INT8_C(94), -INT8_C(94), -INT8_C(94), -INT8_C(94),
        -INT8_C(94), -INT8_C(94), -INT8_C(94), -INT8_C(94) } } },
     { {  INT8_C(99), INT8_C(89), -INT8_C(30) },
       {  -INT8_C(83), INT8_C(36), INT8_C(27)},
     { {  INT8_C(99), INT8_C(99), INT8_C(99), INT8_C(99),
        INT8_C(99), INT8_C(99), INT8_C(99), INT8_C(99) },
       {  INT8_C(89), INT8_C(89), INT8_C(89), INT8_C(89),
        INT8_C(89), INT8_C(89), INT8_C(89), INT8_C(89) },
       {  -INT8_C(30), -INT8_C(30), -INT8_C(30), -INT8_C(30),
        -INT8_C(30), -INT8_C(30), -INT8_C(30), -INT8_C(30) } } },
     { {  -INT8_C(92), INT8_C(73), INT8_C(70) },
       {  -INT8_C(33), -INT8_C(90), -INT8_C(72)},
     { {  -INT8_C(92), -INT8_C(92), -INT8_C(92), -INT8_C(92),
        -INT8_C(92), -INT8_C(92), -INT8_C(92), -INT8_C(92) },
       {  INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73),
        INT8_C(73), INT8_C(73), INT8_C(73), INT8_C(73) },
       {  INT8_C(70), INT8_C(70), INT8_C(70), INT8_C(70),
        INT8_C(70), INT8_C(70), INT8_C(70), INT8_C(70) } } },
     { {  -INT8_C(93), -INT8_C(78), INT8_C(35) },
       {  -INT8_C(20), -INT8_C(43), INT8_C(12)},
     { {  -INT8_C(93), -INT8_C(93), -INT8_C(93), -INT8_C(93),
        -INT8_C(93), -INT8_C(93), -INT8_C(93), -INT8_C(93) },
       {  -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78),
        -INT8_C(78), -INT8_C(78), -INT8_C(78), -INT8_C(78) },
       {  INT8_C(35), INT8_C(35), INT8_C(35), INT8_C(35),
        INT8_C(35), INT8_C(35), INT8_C(35), INT8_C(35) } } },
     { {  -INT8_C(97), INT8_C(19), -INT8_C(95) },
       {  INT8_C(10), INT8_C(91), -INT8_C(14)},
     { {  -INT8_C(97), -INT8_C(97), -INT8_C(97), -INT8_C(97),
        -INT8_C(97), -INT8_C(97), -INT8_C(97), -INT8_C(97) },
       {  INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19),
        INT8_C(19), INT8_C(19), INT8_C(19), INT8_C(19) },
       {  -INT8_C(95), -INT8_C(95), -INT8_C(95), -INT8_C(95),
        -INT8_C(95), -INT8_C(95), -INT8_C(95), -INT8_C(95) } } },
     { {  INT8_C(36), -INT8_C(24), -INT8_C(59) },
       {  -INT8_C(78), INT8_C(76), INT8_C(53)},
     { {  INT8_C(36), INT8_C(36), INT8_C(36), INT8_C(36),
        INT8_C(36), INT8_C(36), INT8_C(36), INT8_C(36) },
       {  -INT8_C(24), -INT8_C(24), -INT8_C(24), -INT8_C(24),
        -INT8_C(24), -INT8_C(24), -INT8_C(24), -INT8_C(24) },
       {  -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59),
        -INT8_C(59), -INT8_C(59), -INT8_C(59), -INT8_C(59) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x3_t r = simde_vld3_dup_s8(test_vec[i].a);
    simde_int8x8x3_t expected = {
        {simde_vld1_s8(test_vec[i].r[0]), simde_vld1_s8(test_vec[i].r[1]), simde_vld1_s8(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_dup_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[3];
    int16_t unused[3];
    int16_t r[3][4];
  } test_vec[] = {
     { {  -INT16_C(2921), INT16_C(8854), -INT16_C(1686) },
       {  -INT16_C(4075), -INT16_C(1501), INT16_C(1121)},
     { {  -INT16_C(2921), -INT16_C(2921), -INT16_C(2921), -INT16_C(2921) },
       {  INT16_C(8854), INT16_C(8854), INT16_C(8854), INT16_C(8854) },
       {  -INT16_C(1686), -INT16_C(1686), -INT16_C(1686), -INT16_C(1686) } } },
     { {  -INT16_C(6896), INT16_C(2743), -INT16_C(1644) },
       {  -INT16_C(2845), -INT16_C(6251), INT16_C(9882)},
     { {  -INT16_C(6896), -INT16_C(6896), -INT16_C(6896), -INT16_C(6896) },
       {  INT16_C(2743), INT16_C(2743), INT16_C(2743), INT16_C(2743) },
       {  -INT16_C(1644), -INT16_C(1644), -INT16_C(1644), -INT16_C(1644) } } },
     { {  INT16_C(7425), INT16_C(1407), -INT16_C(9810) },
       {  INT16_C(5827), INT16_C(7010), INT16_C(2508)},
     { {  INT16_C(7425), INT16_C(7425), INT16_C(7425), INT16_C(7425) },
       {  INT16_C(1407), INT16_C(1407), INT16_C(1407), INT16_C(1407) },
       {  -INT16_C(9810), -INT16_C(9810), -INT16_C(9810), -INT16_C(9810) } } },
     { {  -INT16_C(5814), INT16_C(168), -INT16_C(2609) },
       {  INT16_C(7740), INT16_C(5018), -INT16_C(7738)},
     { {  -INT16_C(5814), -INT16_C(5814), -INT16_C(5814), -INT16_C(5814) },
       {  INT16_C(168), INT16_C(168), INT16_C(168), INT16_C(168) },
       {  -INT16_C(2609), -INT16_C(2609), -INT16_C(2609), -INT16_C(2609) } } },
     { {  INT16_C(4688), -INT16_C(4953), -INT16_C(1696) },
       {  INT16_C(7371), -INT16_C(9194), INT16_C(8018)},
     { {  INT16_C(4688), INT16_C(4688), INT16_C(4688), INT16_C(4688) },
       {  -INT16_C(4953), -INT16_C(4953), -INT16_C(4953), -INT16_C(4953) },
       {  -INT16_C(1696), -INT16_C(1696), -INT16_C(1696), -INT16_C(1696) } } },
     { {  INT16_C(5322), -INT16_C(3475), -INT16_C(1646) },
       {  INT16_C(3260), INT16_C(9616), -INT16_C(7563)},
     { {  INT16_C(5322), INT16_C(5322), INT16_C(5322), INT16_C(5322) },
       {  -INT16_C(3475), -INT16_C(3475), -INT16_C(3475), -INT16_C(3475) },
       {  -INT16_C(1646), -INT16_C(1646), -INT16_C(1646), -INT16_C(1646) } } },
     { {  INT16_C(1866), INT16_C(5035), INT16_C(6718) },
       {  -INT16_C(3904), INT16_C(8154), INT16_C(3705)},
     { {  INT16_C(1866), INT16_C(1866), INT16_C(1866), INT16_C(1866) },
       {  INT16_C(5035), INT16_C(5035), INT16_C(5035), INT16_C(5035) },
       {  INT16_C(6718), INT16_C(6718), INT16_C(6718), INT16_C(6718) } } },
     { {  INT16_C(2449), INT16_C(2426), -INT16_C(4109) },
       {  -INT16_C(3807), INT16_C(2524), -INT16_C(585)},
     { {  INT16_C(2449), INT16_C(2449), INT16_C(2449), INT16_C(2449) },
       {  INT16_C(2426), INT16_C(2426), INT16_C(2426), INT16_C(2426) },
       {  -INT16_C(4109), -INT16_C(4109), -INT16_C(4109), -INT16_C(4109) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x3_t r = simde_vld3_dup_s16(test_vec[i].a);
    simde_int16x4x3_t expected = {
        {simde_vld1_s16(test_vec[i].r[0]), simde_vld1_s16(test_vec[i].r[1]), simde_vld1_s16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_i16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_dup_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[3];
    int32_t unused[3];
    int32_t r[3][2];
  } test_vec[] = {
     { {  INT32_C(9359), -INT32_C(791754), INT32_C(780198) },
       {  -INT32_C(692894), -INT32_C(601710), INT32_C(160090)},
     { {  INT32_C(9359), INT32_C(9359) },
       {  -INT32_C(791754), -INT32_C(791754) },
       {  INT32_C(780198), INT32_C(780198) } } },
     { {  -INT32_C(445729), INT32_C(492254), INT32_C(729801) },
       {  INT32_C(172233), -INT32_C(996411), INT32_C(527512)},
     { {  -INT32_C(445729), -INT32_C(445729) },
       {  INT32_C(492254), INT32_C(492254) },
       {  INT32_C(729801), INT32_C(729801) } } },
     { {  -INT32_C(80447), -INT32_C(632170), INT32_C(712178) },
       {  INT32_C(644121), INT32_C(399198), INT32_C(706984)},
     { {  -INT32_C(80447), -INT32_C(80447) },
       {  -INT32_C(632170), -INT32_C(632170) },
       {  INT32_C(712178), INT32_C(712178) } } },
     { {  -INT32_C(181596), INT32_C(493128), -INT32_C(330413) },
       {  -INT32_C(510772), -INT32_C(439183), INT32_C(228483)},
     { {  -INT32_C(181596), -INT32_C(181596) },
       {  INT32_C(493128), INT32_C(493128) },
       {  -INT32_C(330413), -INT32_C(330413) } } },
     { {  INT32_C(415181), -INT32_C(745887), -INT32_C(767306) },
       {  INT32_C(843741), INT32_C(249059), -INT32_C(35530)},
     { {  INT32_C(415181), INT32_C(415181) },
       {  -INT32_C(745887), -INT32_C(745887) },
       {  -INT32_C(767306), -INT32_C(767306) } } },
     { {  INT32_C(264934), -INT32_C(922140), -INT32_C(924397) },
       {  -INT32_C(823933), INT32_C(333243), -INT32_C(862050)},
     { {  INT32_C(264934), INT32_C(264934) },
       {  -INT32_C(922140), -INT32_C(922140) },
       {  -INT32_C(924397), -INT32_C(924397) } } },
     { {  -INT32_C(211892), -INT32_C(108610), INT32_C(775205) },
       {  -INT32_C(732876), INT32_C(220414), -INT32_C(39935)},
     { {  -INT32_C(211892), -INT32_C(211892) },
       {  -INT32_C(108610), -INT32_C(108610) },
       {  INT32_C(775205), INT32_C(775205) } } },
     { {  INT32_C(52472), INT32_C(404931), -INT32_C(266802) },
       {  INT32_C(192308), INT32_C(487453), INT32_C(771119)},
     { {  INT32_C(52472), INT32_C(52472) },
       {  INT32_C(404931), INT32_C(404931) },
       {  -INT32_C(266802), -INT32_C(266802) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x3_t r = simde_vld3_dup_s32(test_vec[i].a);
    simde_int32x2x3_t expected = {
        {simde_vld1_s32(test_vec[i].r[0]), simde_vld1_s32(test_vec[i].r[1]), simde_vld1_s32(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_i32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_dup_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[3];
    int64_t unused[3];
    int64_t r[3][1];
  } test_vec[] = {
     { {  INT64_C(51518731), -INT64_C(53716248), -INT64_C(89452262) },
       {  INT64_C(84707352), -INT64_C(86842244), -INT64_C(80580693)},
     { {  INT64_C(51518731) },
       {  -INT64_C(53716248) },
       {  -INT64_C(89452262) } } },
     { {  -INT64_C(44610849), -INT64_C(52160709), -INT64_C(95346428) },
       {  INT64_C(72202015), INT64_C(35144772), -INT64_C(29764090)},
     { {  -INT64_C(44610849) },
       {  -INT64_C(52160709) },
       {  -INT64_C(95346428) } } },
     { {  -INT64_C(13186336), INT64_C(44857075), -INT64_C(85282798) },
       {  INT64_C(56936164), INT64_C(65920241), INT64_C(30317650)},
     { {  -INT64_C(13186336) },
       {  INT64_C(44857075) },
       {  -INT64_C(85282798) } } },
     { {  -INT64_C(52586359), -INT64_C(72094720), INT64_C(86111358) },
       {  INT64_C(38491545), -INT64_C(41719422), INT64_C(26443629)},
     { {  -INT64_C(52586359) },
       {  -INT64_C(72094720) },
       {  INT64_C(86111358) } } },
     { {  -INT64_C(7491042), INT64_C(65098523), INT64_C(45614065) },
       {  -INT64_C(34048766), INT64_C(32766230), -INT64_C(19050598)},
     { {  -INT64_C(7491042) },
       {  INT64_C(65098523) },
       {  INT64_C(45614065) } } },
     { {  -INT64_C(15626393), -INT64_C(90534831), INT64_C(77179247) },
       {  INT64_C(66256354), INT64_C(28944347), -INT64_C(58272864)},
     { {  -INT64_C(15626393) },
       {  -INT64_C(90534831) },
       {  INT64_C(77179247) } } },
     { {  -INT64_C(591805), -INT64_C(23226575), -INT64_C(94673457) },
       {  INT64_C(92387981), -INT64_C(78597599), INT64_C(71171711)},
     { {  -INT64_C(591805) },
       {  -INT64_C(23226575) },
       {  -INT64_C(94673457) } } },
     { {  -INT64_C(22331289), INT64_C(63626465), -INT64_C(59469151) },
       {  -INT64_C(50710329), INT64_C(52199199), INT64_C(34000198)},
     { {  -INT64_C(22331289) },
       {  INT64_C(63626465) },
       {  -INT64_C(59469151) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x3_t r = simde_vld3_dup_s64(test_vec[i].a);
    simde_int64x1x3_t expected = {
        {simde_vld1_s64(test_vec[i].r[0]), simde_vld1_s64(test_vec[i].r[1]), simde_vld1_s64(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_i64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_dup_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a[3];
    uint8_t unused[3];
    uint8_t r[3][8];
  } test_vec[] = {
     { {  UINT8_C(135), UINT8_C(154), UINT8_C(34) },
       {  UINT8_C(4), UINT8_C(55), UINT8_C(125)},
     { {  UINT8_C(135), UINT8_C(135), UINT8_C(135), UINT8_C(135),
        UINT8_C(135), UINT8_C(135), UINT8_C(135), UINT8_C(135) },
       {  UINT8_C(154), UINT8_C(154), UINT8_C(154), UINT8_C(154),
        UINT8_C(154), UINT8_C(154), UINT8_C(154), UINT8_C(154) },
       {  UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34),
        UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34) } } },
     { {  UINT8_C(182), UINT8_C(2), UINT8_C(184) },
       {  UINT8_C(165), UINT8_C(123), UINT8_C(191)},
     { {  UINT8_C(182), UINT8_C(182), UINT8_C(182), UINT8_C(182),
        UINT8_C(182), UINT8_C(182), UINT8_C(182), UINT8_C(182) },
       {  UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2),
        UINT8_C(2), UINT8_C(2), UINT8_C(2), UINT8_C(2) },
       {  UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184),
        UINT8_C(184), UINT8_C(184), UINT8_C(184), UINT8_C(184) } } },
     { {  UINT8_C(127), UINT8_C(64), UINT8_C(31) },
       {  UINT8_C(41), UINT8_C(77), UINT8_C(44)},
     { {  UINT8_C(127), UINT8_C(127), UINT8_C(127), UINT8_C(127),
        UINT8_C(127), UINT8_C(127), UINT8_C(127), UINT8_C(127) },
       {  UINT8_C(64), UINT8_C(64), UINT8_C(64), UINT8_C(64),
        UINT8_C(64), UINT8_C(64), UINT8_C(64), UINT8_C(64) },
       {  UINT8_C(31), UINT8_C(31), UINT8_C(31), UINT8_C(31),
        UINT8_C(31), UINT8_C(31), UINT8_C(31), UINT8_C(31) } } },
     { {  UINT8_C(95), UINT8_C(134), UINT8_C(151) },
       {  UINT8_C(30), UINT8_C(126), UINT8_C(11)},
     { {  UINT8_C(95), UINT8_C(95), UINT8_C(95), UINT8_C(95),
        UINT8_C(95), UINT8_C(95), UINT8_C(95), UINT8_C(95) },
       {  UINT8_C(134), UINT8_C(134), UINT8_C(134), UINT8_C(134),
        UINT8_C(134), UINT8_C(134), UINT8_C(134), UINT8_C(134) },
       {  UINT8_C(151), UINT8_C(151), UINT8_C(151), UINT8_C(151),
        UINT8_C(151), UINT8_C(151), UINT8_C(151), UINT8_C(151) } } },
     { {  UINT8_C(198), UINT8_C(171), UINT8_C(185) },
       {  UINT8_C(44), UINT8_C(68), UINT8_C(53)},
     { {  UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198),
        UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198) },
       {  UINT8_C(171), UINT8_C(171), UINT8_C(171), UINT8_C(171),
        UINT8_C(171), UINT8_C(171), UINT8_C(171), UINT8_C(171) },
       {  UINT8_C(185), UINT8_C(185), UINT8_C(185), UINT8_C(185),
        UINT8_C(185), UINT8_C(185), UINT8_C(185), UINT8_C(185) } } },
     { {  UINT8_C(149), UINT8_C(156), UINT8_C(25) },
       {  UINT8_C(131), UINT8_C(33), UINT8_C(82)},
     { {  UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149),
        UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149) },
       {  UINT8_C(156), UINT8_C(156), UINT8_C(156), UINT8_C(156),
        UINT8_C(156), UINT8_C(156), UINT8_C(156), UINT8_C(156) },
       {  UINT8_C(25), UINT8_C(25), UINT8_C(25), UINT8_C(25),
        UINT8_C(25), UINT8_C(25), UINT8_C(25), UINT8_C(25) } } },
     { {  UINT8_C(168), UINT8_C(104), UINT8_C(156) },
       {  UINT8_C(82), UINT8_C(180), UINT8_C(74)},
     { {  UINT8_C(168), UINT8_C(168), UINT8_C(168), UINT8_C(168),
        UINT8_C(168), UINT8_C(168), UINT8_C(168), UINT8_C(168) },
       {  UINT8_C(104), UINT8_C(104), UINT8_C(104), UINT8_C(104),
        UINT8_C(104), UINT8_C(104), UINT8_C(104), UINT8_C(104) },
       {  UINT8_C(156), UINT8_C(156), UINT8_C(156), UINT8_C(156),
        UINT8_C(156), UINT8_C(156), UINT8_C(156), UINT8_C(156) } } },
     { {  UINT8_C(20), UINT8_C(9), UINT8_C(108) },
       {  UINT8_C(197), UINT8_C(40), UINT8_C(191)},
     { {  UINT8_C(20), UINT8_C(20), UINT8_C(20), UINT8_C(20),
        UINT8_C(20), UINT8_C(20), UINT8_C(20), UINT8_C(20) },
       {  UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9),
        UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9) },
       {  UINT8_C(108), UINT8_C(108), UINT8_C(108), UINT8_C(108),
        UINT8_C(108), UINT8_C(108), UINT8_C(108), UINT8_C(108) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x3_t r = simde_vld3_dup_u8(test_vec[i].a);
    simde_uint8x8x3_t expected = {
        {simde_vld1_u8(test_vec[i].r[0]), simde_vld1_u8(test_vec[i].r[1]), simde_vld1_u8(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_dup_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[3];
    uint16_t unused[3];
    uint16_t r[3][4];
  } test_vec[] = {
     { {  UINT16_C(13377), UINT16_C(10805), UINT16_C(14630) },
       {  UINT16_C(10222), UINT16_C(12690), UINT16_C(19072)},
     { {  UINT16_C(13377), UINT16_C(13377), UINT16_C(13377), UINT16_C(13377) },
       {  UINT16_C(10805), UINT16_C(10805), UINT16_C(10805), UINT16_C(10805) },
       {  UINT16_C(14630), UINT16_C(14630), UINT16_C(14630), UINT16_C(14630) } } },
     { {  UINT16_C(8093), UINT16_C(11570), UINT16_C(183) },
       {  UINT16_C(14974), UINT16_C(2867), UINT16_C(19983)},
     { {  UINT16_C(8093), UINT16_C(8093), UINT16_C(8093), UINT16_C(8093) },
       {  UINT16_C(11570), UINT16_C(11570), UINT16_C(11570), UINT16_C(11570) },
       {  UINT16_C(183), UINT16_C(183), UINT16_C(183), UINT16_C(183) } } },
     { {  UINT16_C(51), UINT16_C(11622), UINT16_C(2412) },
       {  UINT16_C(186), UINT16_C(13191), UINT16_C(7620)},
     { {  UINT16_C(51), UINT16_C(51), UINT16_C(51), UINT16_C(51) },
       {  UINT16_C(11622), UINT16_C(11622), UINT16_C(11622), UINT16_C(11622) },
       {  UINT16_C(2412), UINT16_C(2412), UINT16_C(2412), UINT16_C(2412) } } },
     { {  UINT16_C(1319), UINT16_C(3015), UINT16_C(17065) },
       {  UINT16_C(2405), UINT16_C(6666), UINT16_C(16892)},
     { {  UINT16_C(1319), UINT16_C(1319), UINT16_C(1319), UINT16_C(1319) },
       {  UINT16_C(3015), UINT16_C(3015), UINT16_C(3015), UINT16_C(3015) },
       {  UINT16_C(17065), UINT16_C(17065), UINT16_C(17065), UINT16_C(17065) } } },
     { {  UINT16_C(5845), UINT16_C(17414), UINT16_C(9474) },
       {  UINT16_C(17463), UINT16_C(1796), UINT16_C(5656)},
     { {  UINT16_C(5845), UINT16_C(5845), UINT16_C(5845), UINT16_C(5845) },
       {  UINT16_C(17414), UINT16_C(17414), UINT16_C(17414), UINT16_C(17414) },
       {  UINT16_C(9474), UINT16_C(9474), UINT16_C(9474), UINT16_C(9474) } } },
     { {  UINT16_C(4232), UINT16_C(1927), UINT16_C(15662) },
       {  UINT16_C(4302), UINT16_C(2477), UINT16_C(16338)},
     { {  UINT16_C(4232), UINT16_C(4232), UINT16_C(4232), UINT16_C(4232) },
       {  UINT16_C(1927), UINT16_C(1927), UINT16_C(1927), UINT16_C(1927) },
       {  UINT16_C(15662), UINT16_C(15662), UINT16_C(15662), UINT16_C(15662) } } },
     { {  UINT16_C(2091), UINT16_C(9041), UINT16_C(5199) },
       {  UINT16_C(2392), UINT16_C(11870), UINT16_C(18327)},
     { {  UINT16_C(2091), UINT16_C(2091), UINT16_C(2091), UINT16_C(2091) },
       {  UINT16_C(9041), UINT16_C(9041), UINT16_C(9041), UINT16_C(9041) },
       {  UINT16_C(5199), UINT16_C(5199), UINT16_C(5199), UINT16_C(5199) } } },
     { {  UINT16_C(9669), UINT16_C(11054), UINT16_C(16736) },
       {  UINT16_C(8412), UINT16_C(8721), UINT16_C(13754)},
     { {  UINT16_C(9669), UINT16_C(9669), UINT16_C(9669), UINT16_C(9669) },
       {  UINT16_C(11054), UINT16_C(11054), UINT16_C(11054), UINT16_C(11054) },
       {  UINT16_C(16736), UINT16_C(16736), UINT16_C(16736), UINT16_C(16736) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x3_t r = simde_vld3_dup_u16(test_vec[i].a);
    simde_uint16x4x3_t expected = {
        {simde_vld1_u16(test_vec[i].r[0]), simde_vld1_u16(test_vec[i].r[1]), simde_vld1_u16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_u16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_dup_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[3];
    uint32_t unused[3];
    uint32_t r[3][2];
  } test_vec[] = {
     { {  UINT32_C(395765), UINT32_C(1580157), UINT32_C(1297063) },
       {  UINT32_C(437858), UINT32_C(950362), UINT32_C(611421)},
     { {  UINT32_C(395765), UINT32_C(395765) },
       {  UINT32_C(1580157), UINT32_C(1580157) },
       {  UINT32_C(1297063), UINT32_C(1297063) } } },
     { {  UINT32_C(795810), UINT32_C(971010), UINT32_C(508108) },
       {  UINT32_C(99068), UINT32_C(1593779), UINT32_C(1092559)},
     { {  UINT32_C(795810), UINT32_C(795810) },
       {  UINT32_C(971010), UINT32_C(971010) },
       {  UINT32_C(508108), UINT32_C(508108) } } },
     { {  UINT32_C(851511), UINT32_C(1871084), UINT32_C(1077984) },
       {  UINT32_C(441102), UINT32_C(921978), UINT32_C(185864)},
     { {  UINT32_C(851511), UINT32_C(851511) },
       {  UINT32_C(1871084), UINT32_C(1871084) },
       {  UINT32_C(1077984), UINT32_C(1077984) } } },
     { {  UINT32_C(44627), UINT32_C(755307), UINT32_C(1310678) },
       {  UINT32_C(1692632), UINT32_C(1730487), UINT32_C(33593)},
     { {  UINT32_C(44627), UINT32_C(44627) },
       {  UINT32_C(755307), UINT32_C(755307) },
       {  UINT32_C(1310678), UINT32_C(1310678) } } },
     { {  UINT32_C(1123068), UINT32_C(1764923), UINT32_C(135672) },
       {  UINT32_C(748360), UINT32_C(1811211), UINT32_C(237332)},
     { {  UINT32_C(1123068), UINT32_C(1123068) },
       {  UINT32_C(1764923), UINT32_C(1764923) },
       {  UINT32_C(135672), UINT32_C(135672) } } },
     { {  UINT32_C(1762919), UINT32_C(212442), UINT32_C(403640) },
       {  UINT32_C(95742), UINT32_C(870777), UINT32_C(1775043)},
     { {  UINT32_C(1762919), UINT32_C(1762919) },
       {  UINT32_C(212442), UINT32_C(212442) },
       {  UINT32_C(403640), UINT32_C(403640) } } },
     { {  UINT32_C(838356), UINT32_C(1713991), UINT32_C(1501513) },
       {  UINT32_C(1515420), UINT32_C(835038), UINT32_C(322935)},
     { {  UINT32_C(838356), UINT32_C(838356) },
       {  UINT32_C(1713991), UINT32_C(1713991) },
       {  UINT32_C(1501513), UINT32_C(1501513) } } },
     { {  UINT32_C(295067), UINT32_C(128462), UINT32_C(205058) },
       {  UINT32_C(758571), UINT32_C(757108), UINT32_C(669760)},
     { {  UINT32_C(295067), UINT32_C(295067) },
       {  UINT32_C(128462), UINT32_C(128462) },
       {  UINT32_C(205058), UINT32_C(205058) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x3_t r = simde_vld3_dup_u32(test_vec[i].a);
    simde_uint32x2x3_t expected = {
        {simde_vld1_u32(test_vec[i].r[0]), simde_vld1_u32(test_vec[i].r[1]), simde_vld1_u32(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_u32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_dup_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[3];
    uint64_t unused[3];
    uint64_t r[3][1];
  } test_vec[] = {
     { {  UINT64_C(160975844), UINT64_C(153508503), UINT64_C(173493973) },
       {  UINT64_C(166251921), UINT64_C(65830676), UINT64_C(97239677)},
     { {  UINT64_C(160975844) },
       {  UINT64_C(153508503) },
       {  UINT64_C(173493973) } } },
     { {  UINT64_C(187315367), UINT64_C(5800842), UINT64_C(115739498) },
       {  UINT64_C(84653812), UINT64_C(120517420), UINT64_C(175798293)},
     { {  UINT64_C(187315367) },
       {  UINT64_C(5800842) },
       {  UINT64_C(115739498) } } },
     { {  UINT64_C(76024341), UINT64_C(155566333), UINT64_C(101038279) },
       {  UINT64_C(46074453), UINT64_C(151593559), UINT64_C(39262253)},
     { {  UINT64_C(76024341) },
       {  UINT64_C(155566333) },
       {  UINT64_C(101038279) } } },
     { {  UINT64_C(46906477), UINT64_C(997782), UINT64_C(69721610) },
       {  UINT64_C(31134385), UINT64_C(173251253), UINT64_C(151509065)},
     { {  UINT64_C(46906477) },
       {  UINT64_C(997782) },
       {  UINT64_C(69721610) } } },
     { {  UINT64_C(59105148), UINT64_C(194933961), UINT64_C(18072130) },
       {  UINT64_C(67463877), UINT64_C(80370119), UINT64_C(107818223)},
     { {  UINT64_C(59105148) },
       {  UINT64_C(194933961) },
       {  UINT64_C(18072130) } } },
     { {  UINT64_C(187736185), UINT64_C(161160447), UINT64_C(24909245) },
       {  UINT64_C(110288501), UINT64_C(110076399), UINT64_C(184478722)},
     { {  UINT64_C(187736185) },
       {  UINT64_C(161160447) },
       {  UINT64_C(24909245) } } },
     { {  UINT64_C(113683975), UINT64_C(71734803), UINT64_C(50110366) },
       {  UINT64_C(20964634), UINT64_C(167646318), UINT64_C(171677397)},
     { {  UINT64_C(113683975) },
       {  UINT64_C(71734803) },
       {  UINT64_C(50110366) } } },
     { {  UINT64_C(5715707), UINT64_C(147794026), UINT64_C(162515415) },
       {  UINT64_C(142055920), UINT64_C(10766156), UINT64_C(64823110)},
     { {  UINT64_C(5715707) },
       {  UINT64_C(147794026) },
       {  UINT64_C(162515415) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x3_t r = simde_vld3_dup_u64(test_vec[i].a);
    simde_uint64x1x3_t expected = {
        {simde_vld1_u64(test_vec[i].r[0]), simde_vld1_u64(test_vec[i].r[1]), simde_vld1_u64(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_u64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_dup_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[3];
    simde_float16_t unused[3];
    simde_float16_t r[3][8];
  } test_vec[] = {
     { {  SIMDE_FLOAT16_VALUE(20.19), SIMDE_FLOAT16_VALUE(16.39), SIMDE_FLOAT16_VALUE(46.17) },
       {  SIMDE_FLOAT16_VALUE(29.32), SIMDE_FLOAT16_VALUE(-18.79), SIMDE_FLOAT16_VALUE(30.83)},
     { {  SIMDE_FLOAT16_VALUE(20.19), SIMDE_FLOAT16_VALUE(20.19), SIMDE_FLOAT16_VALUE(20.19), SIMDE_FLOAT16_VALUE(20.19),
        SIMDE_FLOAT16_VALUE(20.19), SIMDE_FLOAT16_VALUE(20.19), SIMDE_FLOAT16_VALUE(20.19), SIMDE_FLOAT16_VALUE(20.19) },
       {  SIMDE_FLOAT16_VALUE(16.39), SIMDE_FLOAT16_VALUE(16.39), SIMDE_FLOAT16_VALUE(16.39), SIMDE_FLOAT16_VALUE(16.39),
        SIMDE_FLOAT16_VALUE(16.39), SIMDE_FLOAT16_VALUE(16.39), SIMDE_FLOAT16_VALUE(16.39), SIMDE_FLOAT16_VALUE(16.39) },
       {  SIMDE_FLOAT16_VALUE(46.17), SIMDE_FLOAT16_VALUE(46.17), SIMDE_FLOAT16_VALUE(46.17), SIMDE_FLOAT16_VALUE(46.17),
        SIMDE_FLOAT16_VALUE(46.17), SIMDE_FLOAT16_VALUE(46.17), SIMDE_FLOAT16_VALUE(46.17), SIMDE_FLOAT16_VALUE(46.17) } } },
     { {  SIMDE_FLOAT16_VALUE(-48.67), SIMDE_FLOAT16_VALUE(-21.20), SIMDE_FLOAT16_VALUE(-45.20) },
       {  SIMDE_FLOAT16_VALUE(6.72), SIMDE_FLOAT16_VALUE(10.70), SIMDE_FLOAT16_VALUE(32.09)},
     { {  SIMDE_FLOAT16_VALUE(-48.67), SIMDE_FLOAT16_VALUE(-48.67), SIMDE_FLOAT16_VALUE(-48.67), SIMDE_FLOAT16_VALUE(-48.67),
        SIMDE_FLOAT16_VALUE(-48.67), SIMDE_FLOAT16_VALUE(-48.67), SIMDE_FLOAT16_VALUE(-48.67), SIMDE_FLOAT16_VALUE(-48.67) },
       {  SIMDE_FLOAT16_VALUE(-21.20), SIMDE_FLOAT16_VALUE(-21.20), SIMDE_FLOAT16_VALUE(-21.20), SIMDE_FLOAT16_VALUE(-21.20),
        SIMDE_FLOAT16_VALUE(-21.20), SIMDE_FLOAT16_VALUE(-21.20), SIMDE_FLOAT16_VALUE(-21.20), SIMDE_FLOAT16_VALUE(-21.20) },
       {  SIMDE_FLOAT16_VALUE(-45.20), SIMDE_FLOAT16_VALUE(-45.20), SIMDE_FLOAT16_VALUE(-45.20), SIMDE_FLOAT16_VALUE(-45.20),
        SIMDE_FLOAT16_VALUE(-45.20), SIMDE_FLOAT16_VALUE(-45.20), SIMDE_FLOAT16_VALUE(-45.20), SIMDE_FLOAT16_VALUE(-45.20) } } },
     { {  SIMDE_FLOAT16_VALUE(-29.85), SIMDE_FLOAT16_VALUE(24.77), SIMDE_FLOAT16_VALUE(7.75) },
       {  SIMDE_FLOAT16_VALUE(-19.50), SIMDE_FLOAT16_VALUE(-45.53), SIMDE_FLOAT16_VALUE(21.67)},
     { {  SIMDE_FLOAT16_VALUE(-29.85), SIMDE_FLOAT16_VALUE(-29.85), SIMDE_FLOAT16_VALUE(-29.85), SIMDE_FLOAT16_VALUE(-29.85),
        SIMDE_FLOAT16_VALUE(-29.85), SIMDE_FLOAT16_VALUE(-29.85), SIMDE_FLOAT16_VALUE(-29.85), SIMDE_FLOAT16_VALUE(-29.85) },
       {  SIMDE_FLOAT16_VALUE(24.77), SIMDE_FLOAT16_VALUE(24.77), SIMDE_FLOAT16_VALUE(24.77), SIMDE_FLOAT16_VALUE(24.77),
        SIMDE_FLOAT16_VALUE(24.77), SIMDE_FLOAT16_VALUE(24.77), SIMDE_FLOAT16_VALUE(24.77), SIMDE_FLOAT16_VALUE(24.77) },
       {  SIMDE_FLOAT16_VALUE(7.75), SIMDE_FLOAT16_VALUE(7.75), SIMDE_FLOAT16_VALUE(7.75), SIMDE_FLOAT16_VALUE(7.75),
        SIMDE_FLOAT16_VALUE(7.75), SIMDE_FLOAT16_VALUE(7.75), SIMDE_FLOAT16_VALUE(7.75), SIMDE_FLOAT16_VALUE(7.75) } } },
     { {  SIMDE_FLOAT16_VALUE(-4.91), SIMDE_FLOAT16_VALUE(-25.17), SIMDE_FLOAT16_VALUE(45.00) },
       {  SIMDE_FLOAT16_VALUE(2.89), SIMDE_FLOAT16_VALUE(7.87), SIMDE_FLOAT16_VALUE(24.69)},
     { {  SIMDE_FLOAT16_VALUE(-4.91), SIMDE_FLOAT16_VALUE(-4.91), SIMDE_FLOAT16_VALUE(-4.91), SIMDE_FLOAT16_VALUE(-4.91),
        SIMDE_FLOAT16_VALUE(-4.91), SIMDE_FLOAT16_VALUE(-4.91), SIMDE_FLOAT16_VALUE(-4.91), SIMDE_FLOAT16_VALUE(-4.91) },
       {  SIMDE_FLOAT16_VALUE(-25.17), SIMDE_FLOAT16_VALUE(-25.17), SIMDE_FLOAT16_VALUE(-25.17), SIMDE_FLOAT16_VALUE(-25.17),
        SIMDE_FLOAT16_VALUE(-25.17), SIMDE_FLOAT16_VALUE(-25.17), SIMDE_FLOAT16_VALUE(-25.17), SIMDE_FLOAT16_VALUE(-25.17) },
       {  SIMDE_FLOAT16_VALUE(45.00), SIMDE_FLOAT16_VALUE(45.00), SIMDE_FLOAT16_VALUE(45.00), SIMDE_FLOAT16_VALUE(45.00),
        SIMDE_FLOAT16_VALUE(45.00), SIMDE_FLOAT16_VALUE(45.00), SIMDE_FLOAT16_VALUE(45.00), SIMDE_FLOAT16_VALUE(45.00) } } },
     { {  SIMDE_FLOAT16_VALUE(-47.11), SIMDE_FLOAT16_VALUE(-3.75), SIMDE_FLOAT16_VALUE(44.40) },
       {  SIMDE_FLOAT16_VALUE(-8.68), SIMDE_FLOAT16_VALUE(49.28), SIMDE_FLOAT16_VALUE(49.67)},
     { {  SIMDE_FLOAT16_VALUE(-47.11), SIMDE_FLOAT16_VALUE(-47.11), SIMDE_FLOAT16_VALUE(-47.11), SIMDE_FLOAT16_VALUE(-47.11),
        SIMDE_FLOAT16_VALUE(-47.11), SIMDE_FLOAT16_VALUE(-47.11), SIMDE_FLOAT16_VALUE(-47.11), SIMDE_FLOAT16_VALUE(-47.11) },
       {  SIMDE_FLOAT16_VALUE(-3.75), SIMDE_FLOAT16_VALUE(-3.75), SIMDE_FLOAT16_VALUE(-3.75), SIMDE_FLOAT16_VALUE(-3.75),
        SIMDE_FLOAT16_VALUE(-3.75), SIMDE_FLOAT16_VALUE(-3.75), SIMDE_FLOAT16_VALUE(-3.75), SIMDE_FLOAT16_VALUE(-3.75) },
       {  SIMDE_FLOAT16_VALUE(44.40), SIMDE_FLOAT16_VALUE(44.40), SIMDE_FLOAT16_VALUE(44.40), SIMDE_FLOAT16_VALUE(44.40),
        SIMDE_FLOAT16_VALUE(44.40), SIMDE_FLOAT16_VALUE(44.40), SIMDE_FLOAT16_VALUE(44.40), SIMDE_FLOAT16_VALUE(44.40) } } },
     { {  SIMDE_FLOAT16_VALUE(-32.16), SIMDE_FLOAT16_VALUE(30.51), SIMDE_FLOAT16_VALUE(15.52) },
       {  SIMDE_FLOAT16_VALUE(24.82), SIMDE_FLOAT16_VALUE(34.29), SIMDE_FLOAT16_VALUE(-0.76)},
     { {  SIMDE_FLOAT16_VALUE(-32.16), SIMDE_FLOAT16_VALUE(-32.16), SIMDE_FLOAT16_VALUE(-32.16), SIMDE_FLOAT16_VALUE(-32.16),
        SIMDE_FLOAT16_VALUE(-32.16), SIMDE_FLOAT16_VALUE(-32.16), SIMDE_FLOAT16_VALUE(-32.16), SIMDE_FLOAT16_VALUE(-32.16) },
       {  SIMDE_FLOAT16_VALUE(30.51), SIMDE_FLOAT16_VALUE(30.51), SIMDE_FLOAT16_VALUE(30.51), SIMDE_FLOAT16_VALUE(30.51),
        SIMDE_FLOAT16_VALUE(30.51), SIMDE_FLOAT16_VALUE(30.51), SIMDE_FLOAT16_VALUE(30.51), SIMDE_FLOAT16_VALUE(30.51) },
       {  SIMDE_FLOAT16_VALUE(15.52), SIMDE_FLOAT16_VALUE(15.52), SIMDE_FLOAT16_VALUE(15.52), SIMDE_FLOAT16_VALUE(15.52),
        SIMDE_FLOAT16_VALUE(15.52), SIMDE_FLOAT16_VALUE(15.52), SIMDE_FLOAT16_VALUE(15.52), SIMDE_FLOAT16_VALUE(15.52) } } },
     { {  SIMDE_FLOAT16_VALUE(-15.98), SIMDE_FLOAT16_VALUE(9.92), SIMDE_FLOAT16_VALUE(-43.38) },
       {  SIMDE_FLOAT16_VALUE(3.24), SIMDE_FLOAT16_VALUE(-29.83), SIMDE_FLOAT16_VALUE(34.76)},
     { {  SIMDE_FLOAT16_VALUE(-15.98), SIMDE_FLOAT16_VALUE(-15.98), SIMDE_FLOAT16_VALUE(-15.98), SIMDE_FLOAT16_VALUE(-15.98),
        SIMDE_FLOAT16_VALUE(-15.98), SIMDE_FLOAT16_VALUE(-15.98), SIMDE_FLOAT16_VALUE(-15.98), SIMDE_FLOAT16_VALUE(-15.98) },
       {  SIMDE_FLOAT16_VALUE(9.92), SIMDE_FLOAT16_VALUE(9.92), SIMDE_FLOAT16_VALUE(9.92), SIMDE_FLOAT16_VALUE(9.92),
        SIMDE_FLOAT16_VALUE(9.92), SIMDE_FLOAT16_VALUE(9.92), SIMDE_FLOAT16_VALUE(9.92), SIMDE_FLOAT16_VALUE(9.92) },
       {  SIMDE_FLOAT16_VALUE(-43.38), SIMDE_FLOAT16_VALUE(-43.38), SIMDE_FLOAT16_VALUE(-43.38), SIMDE_FLOAT16_VALUE(-43.38),
        SIMDE_FLOAT16_VALUE(-43.38), SIMDE_FLOAT16_VALUE(-43.38), SIMDE_FLOAT16_VALUE(-43.38), SIMDE_FLOAT16_VALUE(-43.38) } } },
     { {  SIMDE_FLOAT16_VALUE(34.74), SIMDE_FLOAT16_VALUE(3.30), SIMDE_FLOAT16_VALUE(-43.69) },
       {  SIMDE_FLOAT16_VALUE(-47.12), SIMDE_FLOAT16_VALUE(-48.25), SIMDE_FLOAT16_VALUE(-34.42)},
     { {  SIMDE_FLOAT16_VALUE(34.74), SIMDE_FLOAT16_VALUE(34.74), SIMDE_FLOAT16_VALUE(34.74), SIMDE_FLOAT16_VALUE(34.74),
        SIMDE_FLOAT16_VALUE(34.74), SIMDE_FLOAT16_VALUE(34.74), SIMDE_FLOAT16_VALUE(34.74), SIMDE_FLOAT16_VALUE(34.74) },
       {  SIMDE_FLOAT16_VALUE(3.30), SIMDE_FLOAT16_VALUE(3.30), SIMDE_FLOAT16_VALUE(3.30), SIMDE_FLOAT16_VALUE(3.30),
        SIMDE_FLOAT16_VALUE(3.30), SIMDE_FLOAT16_VALUE(3.30), SIMDE_FLOAT16_VALUE(3.30), SIMDE_FLOAT16_VALUE(3.30) },
       {  SIMDE_FLOAT16_VALUE(-43.69), SIMDE_FLOAT16_VALUE(-43.69), SIMDE_FLOAT16_VALUE(-43.69), SIMDE_FLOAT16_VALUE(-43.69),
        SIMDE_FLOAT16_VALUE(-43.69), SIMDE_FLOAT16_VALUE(-43.69), SIMDE_FLOAT16_VALUE(-43.69), SIMDE_FLOAT16_VALUE(-43.69) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8x3_t r = simde_vld3q_dup_f16(test_vec[i].a);
    simde_float16x8x3_t expected = {
        {simde_vld1q_f16(test_vec[i].r[0]), simde_vld1q_f16(test_vec[i].r[1]), simde_vld1q_f16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_f16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3q_dup_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[3];
    float unused[3];
    float r[3][4];
  } test_vec[] = {
     { {  SIMDE_FLOAT32_C(3697.78), SIMDE_FLOAT32_C(2264.54), SIMDE_FLOAT32_C(1602.33) },
       {  SIMDE_FLOAT32_C(2604.95), SIMDE_FLOAT32_C(3726.11), SIMDE_FLOAT32_C(-1452.17)},
     { {  SIMDE_FLOAT32_C(3697.78), SIMDE_FLOAT32_C(3697.78), SIMDE_FLOAT32_C(3697.78), SIMDE_FLOAT32_C(3697.78) },
       {  SIMDE_FLOAT32_C(2264.54), SIMDE_FLOAT32_C(2264.54), SIMDE_FLOAT32_C(2264.54), SIMDE_FLOAT32_C(2264.54) },
       {  SIMDE_FLOAT32_C(1602.33), SIMDE_FLOAT32_C(1602.33), SIMDE_FLOAT32_C(1602.33), SIMDE_FLOAT32_C(1602.33) } } },
     { {  SIMDE_FLOAT32_C(2171.36), SIMDE_FLOAT32_C(-1728.35), SIMDE_FLOAT32_C(-1392.20) },
       {  SIMDE_FLOAT32_C(-373.74), SIMDE_FLOAT32_C(-2139.62), SIMDE_FLOAT32_C(2081.32)},
     { {  SIMDE_FLOAT32_C(2171.36), SIMDE_FLOAT32_C(2171.36), SIMDE_FLOAT32_C(2171.36), SIMDE_FLOAT32_C(2171.36) },
       {  SIMDE_FLOAT32_C(-1728.35), SIMDE_FLOAT32_C(-1728.35), SIMDE_FLOAT32_C(-1728.35), SIMDE_FLOAT32_C(-1728.35) },
       {  SIMDE_FLOAT32_C(-1392.20), SIMDE_FLOAT32_C(-1392.20), SIMDE_FLOAT32_C(-1392.20), SIMDE_FLOAT32_C(-1392.20) } } },
     { {  SIMDE_FLOAT32_C(2884.54), SIMDE_FLOAT32_C(1531.32), SIMDE_FLOAT32_C(-2902.25) },
       {  SIMDE_FLOAT32_C(-4095.36), SIMDE_FLOAT32_C(4395.19), SIMDE_FLOAT32_C(-4907.26)},
     { {  SIMDE_FLOAT32_C(2884.54), SIMDE_FLOAT32_C(2884.54), SIMDE_FLOAT32_C(2884.54), SIMDE_FLOAT32_C(2884.54) },
       {  SIMDE_FLOAT32_C(1531.32), SIMDE_FLOAT32_C(1531.32), SIMDE_FLOAT32_C(1531.32), SIMDE_FLOAT32_C(1531.32) },
       {  SIMDE_FLOAT32_C(-2902.25), SIMDE_FLOAT32_C(-2902.25), SIMDE_FLOAT32_C(-2902.25), SIMDE_FLOAT32_C(-2902.25) } } },
     { {  SIMDE_FLOAT32_C(174.64), SIMDE_FLOAT32_C(-2150.06), SIMDE_FLOAT32_C(2897.93) },
       {  SIMDE_FLOAT32_C(-2988.20), SIMDE_FLOAT32_C(-575.59), SIMDE_FLOAT32_C(3191.50)},
     { {  SIMDE_FLOAT32_C(174.64), SIMDE_FLOAT32_C(174.64), SIMDE_FLOAT32_C(174.64), SIMDE_FLOAT32_C(174.64) },
       {  SIMDE_FLOAT32_C(-2150.06), SIMDE_FLOAT32_C(-2150.06), SIMDE_FLOAT32_C(-2150.06), SIMDE_FLOAT32_C(-2150.06) },
       {  SIMDE_FLOAT32_C(2897.93), SIMDE_FLOAT32_C(2897.93), SIMDE_FLOAT32_C(2897.93), SIMDE_FLOAT32_C(2897.93) } } },
     { {  SIMDE_FLOAT32_C(-3237.71), SIMDE_FLOAT32_C(3879.02), SIMDE_FLOAT32_C(4954.54) },
       {  SIMDE_FLOAT32_C(3405.09), SIMDE_FLOAT32_C(224.82), SIMDE_FLOAT32_C(-180.79)},
     { {  SIMDE_FLOAT32_C(-3237.71), SIMDE_FLOAT32_C(-3237.71), SIMDE_FLOAT32_C(-3237.71), SIMDE_FLOAT32_C(-3237.71) },
       {  SIMDE_FLOAT32_C(3879.02), SIMDE_FLOAT32_C(3879.02), SIMDE_FLOAT32_C(3879.02), SIMDE_FLOAT32_C(3879.02) },
       {  SIMDE_FLOAT32_C(4954.54), SIMDE_FLOAT32_C(4954.54), SIMDE_FLOAT32_C(4954.54), SIMDE_FLOAT32_C(4954.54) } } },
     { {  SIMDE_FLOAT32_C(-1667.55), SIMDE_FLOAT32_C(-1961.29), SIMDE_FLOAT32_C(-4785.81) },
       {  SIMDE_FLOAT32_C(-988.22), SIMDE_FLOAT32_C(645.67), SIMDE_FLOAT32_C(-4900.78)},
     { {  SIMDE_FLOAT32_C(-1667.55), SIMDE_FLOAT32_C(-1667.55), SIMDE_FLOAT32_C(-1667.55), SIMDE_FLOAT32_C(-1667.55) },
       {  SIMDE_FLOAT32_C(-1961.29), SIMDE_FLOAT32_C(-1961.29), SIMDE_FLOAT32_C(-1961.29), SIMDE_FLOAT32_C(-1961.29) },
       {  SIMDE_FLOAT32_C(-4785.81), SIMDE_FLOAT32_C(-4785.81), SIMDE_FLOAT32_C(-4785.81), SIMDE_FLOAT32_C(-4785.81) } } },
     { {  SIMDE_FLOAT32_C(-1617.37), SIMDE_FLOAT32_C(-3727.98), SIMDE_FLOAT32_C(1464.46) },
       {  SIMDE_FLOAT32_C(-3143.52), SIMDE_FLOAT32_C(-3238.88), SIMDE_FLOAT32_C(2569.95)},
     { {  SIMDE_FLOAT32_C(-1617.37), SIMDE_FLOAT32_C(-1617.37), SIMDE_FLOAT32_C(-1617.37), SIMDE_FLOAT32_C(-1617.37) },
       {  SIMDE_FLOAT32_C(-3727.98), SIMDE_FLOAT32_C(-3727.98), SIMDE_FLOAT32_C(-3727.98), SIMDE_FLOAT32_C(-3727.98) },
       {  SIMDE_FLOAT32_C(1464.46), SIMDE_FLOAT32_C(1464.46), SIMDE_FLOAT32_C(1464.46), SIMDE_FLOAT32_C(1464.46) } } },
     { {  SIMDE_FLOAT32_C(896.32), SIMDE_FLOAT32_C(3033.53), SIMDE_FLOAT32_C(2717.79) },
       {  SIMDE_FLOAT32_C(-2243.74), SIMDE_FLOAT32_C(2624.94), SIMDE_FLOAT32_C(4491.28)},
     { {  SIMDE_FLOAT32_C(896.32), SIMDE_FLOAT32_C(896.32), SIMDE_FLOAT32_C(896.32), SIMDE_FLOAT32_C(896.32) },
       {  SIMDE_FLOAT32_C(3033.53), SIMDE_FLOAT32_C(3033.53), SIMDE_FLOAT32_C(3033.53), SIMDE_FLOAT32_C(3033.53) },
       {  SIMDE_FLOAT32_C(2717.79), SIMDE_FLOAT32_C(2717.79), SIMDE_FLOAT32_C(2717.79), SIMDE_FLOAT32_C(2717.79) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x3_t r = simde_vld3q_dup_f32(test_vec[i].a);
    simde_float32x4x3_t expected = {
        {simde_vld1q_f32(test_vec[i].r[0]), simde_vld1q_f32(test_vec[i].r[1]), simde_vld1q_f32(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_f32x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3q_dup_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[3];
    simde_float64 unused[3];
    simde_float64 r[3][2];
  } test_vec[] = {
     { {  SIMDE_FLOAT64_C(-76188.51), SIMDE_FLOAT64_C(-158100.44), SIMDE_FLOAT64_C(450863.97) },
       {  SIMDE_FLOAT64_C(-419497.68), SIMDE_FLOAT64_C(486477.94), SIMDE_FLOAT64_C(-161711.22)},
     { {  SIMDE_FLOAT64_C(-76188.51), SIMDE_FLOAT64_C(-76188.51) },
       {  SIMDE_FLOAT64_C(-158100.44), SIMDE_FLOAT64_C(-158100.44) },
       {  SIMDE_FLOAT64_C(450863.97), SIMDE_FLOAT64_C(450863.97) } } },
     { {  SIMDE_FLOAT64_C(-311999.81), SIMDE_FLOAT64_C(-133166.59), SIMDE_FLOAT64_C(19751.09) },
       {  SIMDE_FLOAT64_C(381296.77), SIMDE_FLOAT64_C(4280.17), SIMDE_FLOAT64_C(200621.38)},
     { {  SIMDE_FLOAT64_C(-311999.81), SIMDE_FLOAT64_C(-311999.81) },
       {  SIMDE_FLOAT64_C(-133166.59), SIMDE_FLOAT64_C(-133166.59) },
       {  SIMDE_FLOAT64_C(19751.09), SIMDE_FLOAT64_C(19751.09) } } },
     { {  SIMDE_FLOAT64_C(431577.95), SIMDE_FLOAT64_C(77634.91), SIMDE_FLOAT64_C(266670.63) },
       {  SIMDE_FLOAT64_C(53.33), SIMDE_FLOAT64_C(-384944.02), SIMDE_FLOAT64_C(283777.76)},
     { {  SIMDE_FLOAT64_C(431577.95), SIMDE_FLOAT64_C(431577.95) },
       {  SIMDE_FLOAT64_C(77634.91), SIMDE_FLOAT64_C(77634.91) },
       {  SIMDE_FLOAT64_C(266670.63), SIMDE_FLOAT64_C(266670.63) } } },
     { {  SIMDE_FLOAT64_C(-158517.04), SIMDE_FLOAT64_C(-133983.50), SIMDE_FLOAT64_C(338367.02) },
       {  SIMDE_FLOAT64_C(-188683.95), SIMDE_FLOAT64_C(-130665.38), SIMDE_FLOAT64_C(393704.35)},
     { {  SIMDE_FLOAT64_C(-158517.04), SIMDE_FLOAT64_C(-158517.04) },
       {  SIMDE_FLOAT64_C(-133983.50), SIMDE_FLOAT64_C(-133983.50) },
       {  SIMDE_FLOAT64_C(338367.02), SIMDE_FLOAT64_C(338367.02) } } },
     { {  SIMDE_FLOAT64_C(-304331.98), SIMDE_FLOAT64_C(378917.44), SIMDE_FLOAT64_C(214241.91) },
       {  SIMDE_FLOAT64_C(294684.17), SIMDE_FLOAT64_C(75983.67), SIMDE_FLOAT64_C(143540.59)},
     { {  SIMDE_FLOAT64_C(-304331.98), SIMDE_FLOAT64_C(-304331.98) },
       {  SIMDE_FLOAT64_C(378917.44), SIMDE_FLOAT64_C(378917.44) },
       {  SIMDE_FLOAT64_C(214241.91), SIMDE_FLOAT64_C(214241.91) } } },
     { {  SIMDE_FLOAT64_C(177828.72), SIMDE_FLOAT64_C(182291.88), SIMDE_FLOAT64_C(133239.91) },
       {  SIMDE_FLOAT64_C(-367510.55), SIMDE_FLOAT64_C(11412.91), SIMDE_FLOAT64_C(-249368.85)},
     { {  SIMDE_FLOAT64_C(177828.72), SIMDE_FLOAT64_C(177828.72) },
       {  SIMDE_FLOAT64_C(182291.88), SIMDE_FLOAT64_C(182291.88) },
       {  SIMDE_FLOAT64_C(133239.91), SIMDE_FLOAT64_C(133239.91) } } },
     { {  SIMDE_FLOAT64_C(480108.45), SIMDE_FLOAT64_C(-112601.79), SIMDE_FLOAT64_C(-401218.95) },
       {  SIMDE_FLOAT64_C(-132521.78), SIMDE_FLOAT64_C(-454060.72), SIMDE_FLOAT64_C(92070.34)},
     { {  SIMDE_FLOAT64_C(480108.45), SIMDE_FLOAT64_C(480108.45) },
       {  SIMDE_FLOAT64_C(-112601.79), SIMDE_FLOAT64_C(-112601.79) },
       {  SIMDE_FLOAT64_C(-401218.95), SIMDE_FLOAT64_C(-401218.95) } } },
     { {  SIMDE_FLOAT64_C(-209344.40), SIMDE_FLOAT64_C(-38397.36), SIMDE_FLOAT64_C(171975.62) },
       {  SIMDE_FLOAT64_C(-306358.76), SIMDE_FLOAT64_C(-389466.37), SIMDE_FLOAT64_C(459048.36)},
     { {  SIMDE_FLOAT64_C(-209344.40), SIMDE_FLOAT64_C(-209344.40) },
       {  SIMDE_FLOAT64_C(-38397.36), SIMDE_FLOAT64_C(-38397.36) },
       {  SIMDE_FLOAT64_C(171975.62), SIMDE_FLOAT64_C(171975.62) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x3_t r = simde_vld3q_dup_f64(test_vec[i].a);
    simde_float64x2x3_t expected = {
        {simde_vld1q_f64(test_vec[i].r[0]), simde_vld1q_f64(test_vec[i].r[1]), simde_vld1q_f64(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_f64x2(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3q_dup_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[3];
    int8_t unused[3];
    int8_t r[3][16];
  } test_vec[] = {
     { {  INT8_C(4), INT8_C(83), -INT8_C(85) },
       {  -INT8_C(88), -INT8_C(66), INT8_C(59)},
     { {  INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4),
        INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4), INT8_C(4) },
       {  INT8_C(83), INT8_C(83), INT8_C(83), INT8_C(83), INT8_C(83), INT8_C(83), INT8_C(83), INT8_C(83),
        INT8_C(83), INT8_C(83), INT8_C(83), INT8_C(83), INT8_C(83), INT8_C(83), INT8_C(83), INT8_C(83) },
       {  -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85),
        -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85), -INT8_C(85) } } },
     { {  -INT8_C(22), INT8_C(10), -INT8_C(86) },
       {  -INT8_C(79), -INT8_C(34), -INT8_C(27)},
     { {  -INT8_C(22), -INT8_C(22), -INT8_C(22), -INT8_C(22), -INT8_C(22), -INT8_C(22), -INT8_C(22), -INT8_C(22),
        -INT8_C(22), -INT8_C(22), -INT8_C(22), -INT8_C(22), -INT8_C(22), -INT8_C(22), -INT8_C(22), -INT8_C(22) },
       {  INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10),
        INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10) },
       {  -INT8_C(86), -INT8_C(86), -INT8_C(86), -INT8_C(86), -INT8_C(86), -INT8_C(86), -INT8_C(86), -INT8_C(86),
        -INT8_C(86), -INT8_C(86), -INT8_C(86), -INT8_C(86), -INT8_C(86), -INT8_C(86), -INT8_C(86), -INT8_C(86) } } },
     { {  -INT8_C(6), -INT8_C(70), -INT8_C(75) },
       {  INT8_C(64), -INT8_C(62), INT8_C(94)},
     { {  -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6),
        -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6), -INT8_C(6) },
       {  -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70),
        -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70), -INT8_C(70) },
       {  -INT8_C(75), -INT8_C(75), -INT8_C(75), -INT8_C(75), -INT8_C(75), -INT8_C(75), -INT8_C(75), -INT8_C(75),
        -INT8_C(75), -INT8_C(75), -INT8_C(75), -INT8_C(75), -INT8_C(75), -INT8_C(75), -INT8_C(75), -INT8_C(75) } } },
     { {  -INT8_C(42), INT8_C(47), -INT8_C(43) },
       {  INT8_C(90), INT8_C(56), INT8_C(31)},
     { {  -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42),
        -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42), -INT8_C(42) },
       {  INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47),
        INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47) },
       {  -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43),
        -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43) } } },
     { {  INT8_C(88), -INT8_C(67), -INT8_C(36) },
       {  INT8_C(56), -INT8_C(54), INT8_C(66)},
     { {  INT8_C(88), INT8_C(88), INT8_C(88), INT8_C(88), INT8_C(88), INT8_C(88), INT8_C(88), INT8_C(88),
        INT8_C(88), INT8_C(88), INT8_C(88), INT8_C(88), INT8_C(88), INT8_C(88), INT8_C(88), INT8_C(88) },
       {  -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67),
        -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67), -INT8_C(67) },
       {  -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36),
        -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36) } } },
     { {  -INT8_C(58), -INT8_C(5), INT8_C(64) },
       {  -INT8_C(87), -INT8_C(97), -INT8_C(71)},
     { {  -INT8_C(58), -INT8_C(58), -INT8_C(58), -INT8_C(58), -INT8_C(58), -INT8_C(58), -INT8_C(58), -INT8_C(58),
        -INT8_C(58), -INT8_C(58), -INT8_C(58), -INT8_C(58), -INT8_C(58), -INT8_C(58), -INT8_C(58), -INT8_C(58) },
       {  -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5),
        -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5) },
       {  INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64),
        INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64) } } },
     { {  -INT8_C(68), INT8_C(98), INT8_C(64) },
       {  -INT8_C(65), INT8_C(25), INT8_C(97)},
     { {  -INT8_C(68), -INT8_C(68), -INT8_C(68), -INT8_C(68), -INT8_C(68), -INT8_C(68), -INT8_C(68), -INT8_C(68),
        -INT8_C(68), -INT8_C(68), -INT8_C(68), -INT8_C(68), -INT8_C(68), -INT8_C(68), -INT8_C(68), -INT8_C(68) },
       {  INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98),
        INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98), INT8_C(98) },
       {  INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64),
        INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64), INT8_C(64) } } },
     { {  -INT8_C(27), -INT8_C(43), -INT8_C(10) },
       {  INT8_C(0), INT8_C(27), -INT8_C(24)},
     { {  -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27),
        -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27) },
       {  -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43),
        -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43), -INT8_C(43) },
       {  -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10),
        -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x3_t r = simde_vld3q_dup_s8(test_vec[i].a);
    simde_int8x16x3_t expected = {
        {simde_vld1q_s8(test_vec[i].r[0]), simde_vld1q_s8(test_vec[i].r[1]), simde_vld1q_s8(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_i8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_dup_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[3];
    int16_t unused[3];
    int16_t r[3][8];
  } test_vec[] = {
     { {  INT16_C(3070), INT16_C(3325), -INT16_C(8375) },
       {  -INT16_C(8688), -INT16_C(7594), INT16_C(4565)},
     { {  INT16_C(3070), INT16_C(3070), INT16_C(3070), INT16_C(3070),
        INT16_C(3070), INT16_C(3070), INT16_C(3070), INT16_C(3070) },
       {  INT16_C(3325), INT16_C(3325), INT16_C(3325), INT16_C(3325),
        INT16_C(3325), INT16_C(3325), INT16_C(3325), INT16_C(3325) },
       {  -INT16_C(8375), -INT16_C(8375), -INT16_C(8375), -INT16_C(8375),
        -INT16_C(8375), -INT16_C(8375), -INT16_C(8375), -INT16_C(8375) } } },
     { {  -INT16_C(4204), INT16_C(8721), INT16_C(5623) },
       {  -INT16_C(472), INT16_C(2671), INT16_C(1200)},
     { {  -INT16_C(4204), -INT16_C(4204), -INT16_C(4204), -INT16_C(4204),
        -INT16_C(4204), -INT16_C(4204), -INT16_C(4204), -INT16_C(4204) },
       {  INT16_C(8721), INT16_C(8721), INT16_C(8721), INT16_C(8721),
        INT16_C(8721), INT16_C(8721), INT16_C(8721), INT16_C(8721) },
       {  INT16_C(5623), INT16_C(5623), INT16_C(5623), INT16_C(5623),
        INT16_C(5623), INT16_C(5623), INT16_C(5623), INT16_C(5623) } } },
     { {  INT16_C(6944), INT16_C(2570), INT16_C(7777) },
       {  -INT16_C(6788), -INT16_C(5739), INT16_C(634)},
     { {  INT16_C(6944), INT16_C(6944), INT16_C(6944), INT16_C(6944),
        INT16_C(6944), INT16_C(6944), INT16_C(6944), INT16_C(6944) },
       {  INT16_C(2570), INT16_C(2570), INT16_C(2570), INT16_C(2570),
        INT16_C(2570), INT16_C(2570), INT16_C(2570), INT16_C(2570) },
       {  INT16_C(7777), INT16_C(7777), INT16_C(7777), INT16_C(7777),
        INT16_C(7777), INT16_C(7777), INT16_C(7777), INT16_C(7777) } } },
     { {  -INT16_C(2506), INT16_C(2490), -INT16_C(5108) },
       {  -INT16_C(4656), -INT16_C(804), INT16_C(9299)},
     { {  -INT16_C(2506), -INT16_C(2506), -INT16_C(2506), -INT16_C(2506),
        -INT16_C(2506), -INT16_C(2506), -INT16_C(2506), -INT16_C(2506) },
       {  INT16_C(2490), INT16_C(2490), INT16_C(2490), INT16_C(2490),
        INT16_C(2490), INT16_C(2490), INT16_C(2490), INT16_C(2490) },
       {  -INT16_C(5108), -INT16_C(5108), -INT16_C(5108), -INT16_C(5108),
        -INT16_C(5108), -INT16_C(5108), -INT16_C(5108), -INT16_C(5108) } } },
     { {  INT16_C(7062), -INT16_C(9613), INT16_C(5275) },
       {  INT16_C(9211), -INT16_C(3971), INT16_C(2988)},
     { {  INT16_C(7062), INT16_C(7062), INT16_C(7062), INT16_C(7062),
        INT16_C(7062), INT16_C(7062), INT16_C(7062), INT16_C(7062) },
       {  -INT16_C(9613), -INT16_C(9613), -INT16_C(9613), -INT16_C(9613),
        -INT16_C(9613), -INT16_C(9613), -INT16_C(9613), -INT16_C(9613) },
       {  INT16_C(5275), INT16_C(5275), INT16_C(5275), INT16_C(5275),
        INT16_C(5275), INT16_C(5275), INT16_C(5275), INT16_C(5275) } } },
     { {  -INT16_C(2278), INT16_C(2234), INT16_C(8224) },
       {  INT16_C(377), INT16_C(8197), INT16_C(9563)},
     { {  -INT16_C(2278), -INT16_C(2278), -INT16_C(2278), -INT16_C(2278),
        -INT16_C(2278), -INT16_C(2278), -INT16_C(2278), -INT16_C(2278) },
       {  INT16_C(2234), INT16_C(2234), INT16_C(2234), INT16_C(2234),
        INT16_C(2234), INT16_C(2234), INT16_C(2234), INT16_C(2234) },
       {  INT16_C(8224), INT16_C(8224), INT16_C(8224), INT16_C(8224),
        INT16_C(8224), INT16_C(8224), INT16_C(8224), INT16_C(8224) } } },
     { {  INT16_C(8937), -INT16_C(9972), INT16_C(4720) },
       {  -INT16_C(5849), INT16_C(8449), INT16_C(7259)},
     { {  INT16_C(8937), INT16_C(8937), INT16_C(8937), INT16_C(8937),
        INT16_C(8937), INT16_C(8937), INT16_C(8937), INT16_C(8937) },
       {  -INT16_C(9972), -INT16_C(9972), -INT16_C(9972), -INT16_C(9972),
        -INT16_C(9972), -INT16_C(9972), -INT16_C(9972), -INT16_C(9972) },
       {  INT16_C(4720), INT16_C(4720), INT16_C(4720), INT16_C(4720),
        INT16_C(4720), INT16_C(4720), INT16_C(4720), INT16_C(4720) } } },
     { {  -INT16_C(8860), -INT16_C(995), -INT16_C(3832) },
       {  INT16_C(4136), -INT16_C(9880), -INT16_C(6950)},
     { {  -INT16_C(8860), -INT16_C(8860), -INT16_C(8860), -INT16_C(8860),
        -INT16_C(8860), -INT16_C(8860), -INT16_C(8860), -INT16_C(8860) },
       {  -INT16_C(995), -INT16_C(995), -INT16_C(995), -INT16_C(995),
        -INT16_C(995), -INT16_C(995), -INT16_C(995), -INT16_C(995) },
       {  -INT16_C(3832), -INT16_C(3832), -INT16_C(3832), -INT16_C(3832),
        -INT16_C(3832), -INT16_C(3832), -INT16_C(3832), -INT16_C(3832) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x3_t r = simde_vld3q_dup_s16(test_vec[i].a);
    simde_int16x8x3_t expected = {
        {simde_vld1q_s16(test_vec[i].r[0]), simde_vld1q_s16(test_vec[i].r[1]), simde_vld1q_s16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_i16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_dup_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[3];
    int32_t unused[3];
    int32_t r[3][4];
  } test_vec[] = {
     { {  -INT32_C(220041), -INT32_C(136466), -INT32_C(639215) },
       {  -INT32_C(317815), -INT32_C(462436), -INT32_C(731661)},
     { {  -INT32_C(220041), -INT32_C(220041), -INT32_C(220041), -INT32_C(220041) },
       {  -INT32_C(136466), -INT32_C(136466), -INT32_C(136466), -INT32_C(136466) },
       {  -INT32_C(639215), -INT32_C(639215), -INT32_C(639215), -INT32_C(639215) } } },
     { {  INT32_C(126360), INT32_C(731272), -INT32_C(643018) },
       {  INT32_C(135164), INT32_C(44493), INT32_C(256793)},
     { {  INT32_C(126360), INT32_C(126360), INT32_C(126360), INT32_C(126360) },
       {  INT32_C(731272), INT32_C(731272), INT32_C(731272), INT32_C(731272) },
       {  -INT32_C(643018), -INT32_C(643018), -INT32_C(643018), -INT32_C(643018) } } },
     { {  -INT32_C(506698), INT32_C(847224), -INT32_C(263807) },
       {  -INT32_C(322179), INT32_C(943052), INT32_C(403393)},
     { {  -INT32_C(506698), -INT32_C(506698), -INT32_C(506698), -INT32_C(506698) },
       {  INT32_C(847224), INT32_C(847224), INT32_C(847224), INT32_C(847224) },
       {  -INT32_C(263807), -INT32_C(263807), -INT32_C(263807), -INT32_C(263807) } } },
     { {  -INT32_C(269498), INT32_C(592114), -INT32_C(342573) },
       {  -INT32_C(120068), -INT32_C(608432), -INT32_C(729451)},
     { {  -INT32_C(269498), -INT32_C(269498), -INT32_C(269498), -INT32_C(269498) },
       {  INT32_C(592114), INT32_C(592114), INT32_C(592114), INT32_C(592114) },
       {  -INT32_C(342573), -INT32_C(342573), -INT32_C(342573), -INT32_C(342573) } } },
     { {  -INT32_C(930622), -INT32_C(46600), -INT32_C(350088) },
       {  -INT32_C(464765), -INT32_C(884750), INT32_C(205861)},
     { {  -INT32_C(930622), -INT32_C(930622), -INT32_C(930622), -INT32_C(930622) },
       {  -INT32_C(46600), -INT32_C(46600), -INT32_C(46600), -INT32_C(46600) },
       {  -INT32_C(350088), -INT32_C(350088), -INT32_C(350088), -INT32_C(350088) } } },
     { {  -INT32_C(243432), -INT32_C(205395), -INT32_C(893190) },
       {  INT32_C(811036), INT32_C(262547), INT32_C(351628)},
     { {  -INT32_C(243432), -INT32_C(243432), -INT32_C(243432), -INT32_C(243432) },
       {  -INT32_C(205395), -INT32_C(205395), -INT32_C(205395), -INT32_C(205395) },
       {  -INT32_C(893190), -INT32_C(893190), -INT32_C(893190), -INT32_C(893190) } } },
     { {  INT32_C(347685), INT32_C(358948), INT32_C(914938) },
       {  INT32_C(27640), INT32_C(919511), INT32_C(219147)},
     { {  INT32_C(347685), INT32_C(347685), INT32_C(347685), INT32_C(347685) },
       {  INT32_C(358948), INT32_C(358948), INT32_C(358948), INT32_C(358948) },
       {  INT32_C(914938), INT32_C(914938), INT32_C(914938), INT32_C(914938) } } },
     { {  INT32_C(561560), -INT32_C(274267), INT32_C(204485) },
       {  INT32_C(765969), INT32_C(388245), INT32_C(257065)},
     { {  INT32_C(561560), INT32_C(561560), INT32_C(561560), INT32_C(561560) },
       {  -INT32_C(274267), -INT32_C(274267), -INT32_C(274267), -INT32_C(274267) },
       {  INT32_C(204485), INT32_C(204485), INT32_C(204485), INT32_C(204485) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x3_t r = simde_vld3q_dup_s32(test_vec[i].a);
    simde_int32x4x3_t expected = {
        {simde_vld1q_s32(test_vec[i].r[0]), simde_vld1q_s32(test_vec[i].r[1]), simde_vld1q_s32(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_i32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_dup_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[3];
    int64_t unused[3];
    int64_t r[3][2];
  } test_vec[] = {
     { {  -INT64_C(79406386), INT64_C(41175464), INT64_C(7159478) },
       {  INT64_C(30451828), INT64_C(73611566), INT64_C(82111454)},
     { {  -INT64_C(79406386), -INT64_C(79406386) },
       {  INT64_C(41175464), INT64_C(41175464) },
       {  INT64_C(7159478), INT64_C(7159478) } } },
     { {  -INT64_C(75960984), INT64_C(72605055), INT64_C(28446824) },
       {  INT64_C(33111103), -INT64_C(83285820), INT64_C(74966460)},
     { {  -INT64_C(75960984), -INT64_C(75960984) },
       {  INT64_C(72605055), INT64_C(72605055) },
       {  INT64_C(28446824), INT64_C(28446824) } } },
     { {  INT64_C(12246277), INT64_C(13799747), INT64_C(5941147) },
       {  -INT64_C(75658711), INT64_C(2033325), -INT64_C(46607368)},
     { {  INT64_C(12246277), INT64_C(12246277) },
       {  INT64_C(13799747), INT64_C(13799747) },
       {  INT64_C(5941147), INT64_C(5941147) } } },
     { {  -INT64_C(34340194), -INT64_C(85099997), INT64_C(58086303) },
       {  -INT64_C(70737572), -INT64_C(35354753), -INT64_C(67958448)},
     { {  -INT64_C(34340194), -INT64_C(34340194) },
       {  -INT64_C(85099997), -INT64_C(85099997) },
       {  INT64_C(58086303), INT64_C(58086303) } } },
     { {  -INT64_C(55249984), -INT64_C(44930870), INT64_C(34202412) },
       {  INT64_C(19535608), INT64_C(32670990), INT64_C(11914506)},
     { {  -INT64_C(55249984), -INT64_C(55249984) },
       {  -INT64_C(44930870), -INT64_C(44930870) },
       {  INT64_C(34202412), INT64_C(34202412) } } },
     { {  -INT64_C(70171393), -INT64_C(52064191), INT64_C(19678826) },
       {  INT64_C(65818655), INT64_C(42062976), INT64_C(71093868)},
     { {  -INT64_C(70171393), -INT64_C(70171393) },
       {  -INT64_C(52064191), -INT64_C(52064191) },
       {  INT64_C(19678826), INT64_C(19678826) } } },
     { {  INT64_C(61111924), INT64_C(5653009), INT64_C(11261082) },
       {  -INT64_C(29267150), INT64_C(49729783), INT64_C(59210528)},
     { {  INT64_C(61111924), INT64_C(61111924) },
       {  INT64_C(5653009), INT64_C(5653009) },
       {  INT64_C(11261082), INT64_C(11261082) } } },
     { {  -INT64_C(40289471), INT64_C(71520226), -INT64_C(74282823) },
       {  INT64_C(65251834), INT64_C(91366098), INT64_C(57294064)},
     { {  -INT64_C(40289471), -INT64_C(40289471) },
       {  INT64_C(71520226), INT64_C(71520226) },
       {  -INT64_C(74282823), -INT64_C(74282823) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x3_t r = simde_vld3q_dup_s64(test_vec[i].a);
    simde_int64x2x3_t expected = {
        {simde_vld1q_s64(test_vec[i].r[0]), simde_vld1q_s64(test_vec[i].r[1]), simde_vld1q_s64(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_i64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_dup_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a[3];
    uint8_t unused[3];
    uint8_t r[3][16];
  } test_vec[] = {
     { {  UINT8_C(131), UINT8_C(170), UINT8_C(140) },
       {  UINT8_C(114), UINT8_C(199), UINT8_C(32)},
     { {  UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131),
        UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131) },
       {  UINT8_C(170), UINT8_C(170), UINT8_C(170), UINT8_C(170), UINT8_C(170), UINT8_C(170), UINT8_C(170), UINT8_C(170),
        UINT8_C(170), UINT8_C(170), UINT8_C(170), UINT8_C(170), UINT8_C(170), UINT8_C(170), UINT8_C(170), UINT8_C(170) },
       {  UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140),
        UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140) } } },
     { {  UINT8_C(122), UINT8_C(34), UINT8_C(152) },
       {  UINT8_C(111), UINT8_C(186), UINT8_C(172)},
     { {  UINT8_C(122), UINT8_C(122), UINT8_C(122), UINT8_C(122), UINT8_C(122), UINT8_C(122), UINT8_C(122), UINT8_C(122),
        UINT8_C(122), UINT8_C(122), UINT8_C(122), UINT8_C(122), UINT8_C(122), UINT8_C(122), UINT8_C(122), UINT8_C(122) },
       {  UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34),
        UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34) },
       {  UINT8_C(152), UINT8_C(152), UINT8_C(152), UINT8_C(152), UINT8_C(152), UINT8_C(152), UINT8_C(152), UINT8_C(152),
        UINT8_C(152), UINT8_C(152), UINT8_C(152), UINT8_C(152), UINT8_C(152), UINT8_C(152), UINT8_C(152), UINT8_C(152) } } },
     { {  UINT8_C(198), UINT8_C(18), UINT8_C(101) },
       {  UINT8_C(91), UINT8_C(119), UINT8_C(69)},
     { {  UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198),
        UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198), UINT8_C(198) },
       {  UINT8_C(18), UINT8_C(18), UINT8_C(18), UINT8_C(18), UINT8_C(18), UINT8_C(18), UINT8_C(18), UINT8_C(18),
        UINT8_C(18), UINT8_C(18), UINT8_C(18), UINT8_C(18), UINT8_C(18), UINT8_C(18), UINT8_C(18), UINT8_C(18) },
       {  UINT8_C(101), UINT8_C(101), UINT8_C(101), UINT8_C(101), UINT8_C(101), UINT8_C(101), UINT8_C(101), UINT8_C(101),
        UINT8_C(101), UINT8_C(101), UINT8_C(101), UINT8_C(101), UINT8_C(101), UINT8_C(101), UINT8_C(101), UINT8_C(101) } } },
     { {  UINT8_C(148), UINT8_C(113), UINT8_C(110) },
       {  UINT8_C(57), UINT8_C(103), UINT8_C(149)},
     { {  UINT8_C(148), UINT8_C(148), UINT8_C(148), UINT8_C(148), UINT8_C(148), UINT8_C(148), UINT8_C(148), UINT8_C(148),
        UINT8_C(148), UINT8_C(148), UINT8_C(148), UINT8_C(148), UINT8_C(148), UINT8_C(148), UINT8_C(148), UINT8_C(148) },
       {  UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113),
        UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113), UINT8_C(113) },
       {  UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110),
        UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110), UINT8_C(110) } } },
     { {  UINT8_C(13), UINT8_C(140), UINT8_C(72) },
       {  UINT8_C(114), UINT8_C(161), UINT8_C(131)},
     { {  UINT8_C(13), UINT8_C(13), UINT8_C(13), UINT8_C(13), UINT8_C(13), UINT8_C(13), UINT8_C(13), UINT8_C(13),
        UINT8_C(13), UINT8_C(13), UINT8_C(13), UINT8_C(13), UINT8_C(13), UINT8_C(13), UINT8_C(13), UINT8_C(13) },
       {  UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140),
        UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140), UINT8_C(140) },
       {  UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72),
        UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72) } } },
     { {  UINT8_C(66), UINT8_C(23), UINT8_C(149) },
       {  UINT8_C(20), UINT8_C(31), UINT8_C(114)},
     { {  UINT8_C(66), UINT8_C(66), UINT8_C(66), UINT8_C(66), UINT8_C(66), UINT8_C(66), UINT8_C(66), UINT8_C(66),
        UINT8_C(66), UINT8_C(66), UINT8_C(66), UINT8_C(66), UINT8_C(66), UINT8_C(66), UINT8_C(66), UINT8_C(66) },
       {  UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23),
        UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23) },
       {  UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149),
        UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149), UINT8_C(149) } } },
     { {  UINT8_C(65), UINT8_C(19), UINT8_C(124) },
       {  UINT8_C(31), UINT8_C(9), UINT8_C(194)},
     { {  UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65),
        UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65) },
       {  UINT8_C(19), UINT8_C(19), UINT8_C(19), UINT8_C(19), UINT8_C(19), UINT8_C(19), UINT8_C(19), UINT8_C(19),
        UINT8_C(19), UINT8_C(19), UINT8_C(19), UINT8_C(19), UINT8_C(19), UINT8_C(19), UINT8_C(19), UINT8_C(19) },
       {  UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124),
        UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124), UINT8_C(124) } } },
     { {  UINT8_C(72), UINT8_C(144), UINT8_C(159) },
       {  UINT8_C(87), UINT8_C(134), UINT8_C(28)},
     { {  UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72),
        UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72), UINT8_C(72) },
       {  UINT8_C(144), UINT8_C(144), UINT8_C(144), UINT8_C(144), UINT8_C(144), UINT8_C(144), UINT8_C(144), UINT8_C(144),
        UINT8_C(144), UINT8_C(144), UINT8_C(144), UINT8_C(144), UINT8_C(144), UINT8_C(144), UINT8_C(144), UINT8_C(144) },
       {  UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159),
        UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159), UINT8_C(159) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x3_t r = simde_vld3q_dup_u8(test_vec[i].a);
    simde_uint8x16x3_t expected = {
        {simde_vld1q_u8(test_vec[i].r[0]), simde_vld1q_u8(test_vec[i].r[1]), simde_vld1q_u8(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_dup_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[3];
    uint16_t unused[3];
    uint16_t r[3][8];
  } test_vec[] = {
     { {  UINT16_C(13221), UINT16_C(12229), UINT16_C(11071) },
       {  UINT16_C(17602), UINT16_C(4227), UINT16_C(7666)},
     { {  UINT16_C(13221), UINT16_C(13221), UINT16_C(13221), UINT16_C(13221),
        UINT16_C(13221), UINT16_C(13221), UINT16_C(13221), UINT16_C(13221) },
       {  UINT16_C(12229), UINT16_C(12229), UINT16_C(12229), UINT16_C(12229),
        UINT16_C(12229), UINT16_C(12229), UINT16_C(12229), UINT16_C(12229) },
       {  UINT16_C(11071), UINT16_C(11071), UINT16_C(11071), UINT16_C(11071),
        UINT16_C(11071), UINT16_C(11071), UINT16_C(11071), UINT16_C(11071) } } },
     { {  UINT16_C(12420), UINT16_C(14500), UINT16_C(12248) },
       {  UINT16_C(17926), UINT16_C(17458), UINT16_C(3685)},
     { {  UINT16_C(12420), UINT16_C(12420), UINT16_C(12420), UINT16_C(12420),
        UINT16_C(12420), UINT16_C(12420), UINT16_C(12420), UINT16_C(12420) },
       {  UINT16_C(14500), UINT16_C(14500), UINT16_C(14500), UINT16_C(14500),
        UINT16_C(14500), UINT16_C(14500), UINT16_C(14500), UINT16_C(14500) },
       {  UINT16_C(12248), UINT16_C(12248), UINT16_C(12248), UINT16_C(12248),
        UINT16_C(12248), UINT16_C(12248), UINT16_C(12248), UINT16_C(12248) } } },
     { {  UINT16_C(8504), UINT16_C(3056), UINT16_C(15978) },
       {  UINT16_C(11648), UINT16_C(2353), UINT16_C(16355)},
     { {  UINT16_C(8504), UINT16_C(8504), UINT16_C(8504), UINT16_C(8504),
        UINT16_C(8504), UINT16_C(8504), UINT16_C(8504), UINT16_C(8504) },
       {  UINT16_C(3056), UINT16_C(3056), UINT16_C(3056), UINT16_C(3056),
        UINT16_C(3056), UINT16_C(3056), UINT16_C(3056), UINT16_C(3056) },
       {  UINT16_C(15978), UINT16_C(15978), UINT16_C(15978), UINT16_C(15978),
        UINT16_C(15978), UINT16_C(15978), UINT16_C(15978), UINT16_C(15978) } } },
     { {  UINT16_C(15523), UINT16_C(1359), UINT16_C(16502) },
       {  UINT16_C(13928), UINT16_C(5794), UINT16_C(818)},
     { {  UINT16_C(15523), UINT16_C(15523), UINT16_C(15523), UINT16_C(15523),
        UINT16_C(15523), UINT16_C(15523), UINT16_C(15523), UINT16_C(15523) },
       {  UINT16_C(1359), UINT16_C(1359), UINT16_C(1359), UINT16_C(1359),
        UINT16_C(1359), UINT16_C(1359), UINT16_C(1359), UINT16_C(1359) },
       {  UINT16_C(16502), UINT16_C(16502), UINT16_C(16502), UINT16_C(16502),
        UINT16_C(16502), UINT16_C(16502), UINT16_C(16502), UINT16_C(16502) } } },
     { {  UINT16_C(19929), UINT16_C(2856), UINT16_C(3524) },
       {  UINT16_C(4725), UINT16_C(16666), UINT16_C(9010)},
     { {  UINT16_C(19929), UINT16_C(19929), UINT16_C(19929), UINT16_C(19929),
        UINT16_C(19929), UINT16_C(19929), UINT16_C(19929), UINT16_C(19929) },
       {  UINT16_C(2856), UINT16_C(2856), UINT16_C(2856), UINT16_C(2856),
        UINT16_C(2856), UINT16_C(2856), UINT16_C(2856), UINT16_C(2856) },
       {  UINT16_C(3524), UINT16_C(3524), UINT16_C(3524), UINT16_C(3524),
        UINT16_C(3524), UINT16_C(3524), UINT16_C(3524), UINT16_C(3524) } } },
     { {  UINT16_C(1112), UINT16_C(8015), UINT16_C(4791) },
       {  UINT16_C(18035), UINT16_C(7170), UINT16_C(3494)},
     { {  UINT16_C(1112), UINT16_C(1112), UINT16_C(1112), UINT16_C(1112),
        UINT16_C(1112), UINT16_C(1112), UINT16_C(1112), UINT16_C(1112) },
       {  UINT16_C(8015), UINT16_C(8015), UINT16_C(8015), UINT16_C(8015),
        UINT16_C(8015), UINT16_C(8015), UINT16_C(8015), UINT16_C(8015) },
       {  UINT16_C(4791), UINT16_C(4791), UINT16_C(4791), UINT16_C(4791),
        UINT16_C(4791), UINT16_C(4791), UINT16_C(4791), UINT16_C(4791) } } },
     { {  UINT16_C(19750), UINT16_C(19409), UINT16_C(17275) },
       {  UINT16_C(5089), UINT16_C(5163), UINT16_C(18594)},
     { {  UINT16_C(19750), UINT16_C(19750), UINT16_C(19750), UINT16_C(19750),
        UINT16_C(19750), UINT16_C(19750), UINT16_C(19750), UINT16_C(19750) },
       {  UINT16_C(19409), UINT16_C(19409), UINT16_C(19409), UINT16_C(19409),
        UINT16_C(19409), UINT16_C(19409), UINT16_C(19409), UINT16_C(19409) },
       {  UINT16_C(17275), UINT16_C(17275), UINT16_C(17275), UINT16_C(17275),
        UINT16_C(17275), UINT16_C(17275), UINT16_C(17275), UINT16_C(17275) } } },
     { {  UINT16_C(7578), UINT16_C(8951), UINT16_C(11969) },
       {  UINT16_C(15208), UINT16_C(9477), UINT16_C(18579)},
     { {  UINT16_C(7578), UINT16_C(7578), UINT16_C(7578), UINT16_C(7578),
        UINT16_C(7578), UINT16_C(7578), UINT16_C(7578), UINT16_C(7578) },
       {  UINT16_C(8951), UINT16_C(8951), UINT16_C(8951), UINT16_C(8951),
        UINT16_C(8951), UINT16_C(8951), UINT16_C(8951), UINT16_C(8951) },
       {  UINT16_C(11969), UINT16_C(11969), UINT16_C(11969), UINT16_C(11969),
        UINT16_C(11969), UINT16_C(11969), UINT16_C(11969), UINT16_C(11969) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x3_t r = simde_vld3q_dup_u16(test_vec[i].a);
    simde_uint16x8x3_t expected = {
        {simde_vld1q_u16(test_vec[i].r[0]), simde_vld1q_u16(test_vec[i].r[1]), simde_vld1q_u16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_u16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_dup_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[3];
    uint32_t unused[3];
    uint32_t r[3][4];
  } test_vec[] = {
     { {  UINT32_C(1876681), UINT32_C(383882), UINT32_C(1503446) },
       {  UINT32_C(1131353), UINT32_C(685373), UINT32_C(644898)},
     { {  UINT32_C(1876681), UINT32_C(1876681), UINT32_C(1876681), UINT32_C(1876681) },
       {  UINT32_C(383882), UINT32_C(383882), UINT32_C(383882), UINT32_C(383882) },
       {  UINT32_C(1503446), UINT32_C(1503446), UINT32_C(1503446), UINT32_C(1503446) } } },
     { {  UINT32_C(1252582), UINT32_C(197720), UINT32_C(1532363) },
       {  UINT32_C(149827), UINT32_C(586569), UINT32_C(781195)},
     { {  UINT32_C(1252582), UINT32_C(1252582), UINT32_C(1252582), UINT32_C(1252582) },
       {  UINT32_C(197720), UINT32_C(197720), UINT32_C(197720), UINT32_C(197720) },
       {  UINT32_C(1532363), UINT32_C(1532363), UINT32_C(1532363), UINT32_C(1532363) } } },
     { {  UINT32_C(1255475), UINT32_C(1250931), UINT32_C(344434) },
       {  UINT32_C(20022), UINT32_C(598221), UINT32_C(1823423)},
     { {  UINT32_C(1255475), UINT32_C(1255475), UINT32_C(1255475), UINT32_C(1255475) },
       {  UINT32_C(1250931), UINT32_C(1250931), UINT32_C(1250931), UINT32_C(1250931) },
       {  UINT32_C(344434), UINT32_C(344434), UINT32_C(344434), UINT32_C(344434) } } },
     { {  UINT32_C(468848), UINT32_C(1580004), UINT32_C(349385) },
       {  UINT32_C(398943), UINT32_C(1301831), UINT32_C(129635)},
     { {  UINT32_C(468848), UINT32_C(468848), UINT32_C(468848), UINT32_C(468848) },
       {  UINT32_C(1580004), UINT32_C(1580004), UINT32_C(1580004), UINT32_C(1580004) },
       {  UINT32_C(349385), UINT32_C(349385), UINT32_C(349385), UINT32_C(349385) } } },
     { {  UINT32_C(1151250), UINT32_C(233582), UINT32_C(1925943) },
       {  UINT32_C(77066), UINT32_C(1269609), UINT32_C(294824)},
     { {  UINT32_C(1151250), UINT32_C(1151250), UINT32_C(1151250), UINT32_C(1151250) },
       {  UINT32_C(233582), UINT32_C(233582), UINT32_C(233582), UINT32_C(233582) },
       {  UINT32_C(1925943), UINT32_C(1925943), UINT32_C(1925943), UINT32_C(1925943) } } },
     { {  UINT32_C(498645), UINT32_C(274619), UINT32_C(816883) },
       {  UINT32_C(647287), UINT32_C(31939), UINT32_C(1314337)},
     { {  UINT32_C(498645), UINT32_C(498645), UINT32_C(498645), UINT32_C(498645) },
       {  UINT32_C(274619), UINT32_C(274619), UINT32_C(274619), UINT32_C(274619) },
       {  UINT32_C(816883), UINT32_C(816883), UINT32_C(816883), UINT32_C(816883) } } },
     { {  UINT32_C(976290), UINT32_C(913370), UINT32_C(617200) },
       {  UINT32_C(772841), UINT32_C(145369), UINT32_C(351685)},
     { {  UINT32_C(976290), UINT32_C(976290), UINT32_C(976290), UINT32_C(976290) },
       {  UINT32_C(913370), UINT32_C(913370), UINT32_C(913370), UINT32_C(913370) },
       {  UINT32_C(617200), UINT32_C(617200), UINT32_C(617200), UINT32_C(617200) } } },
     { {  UINT32_C(350154), UINT32_C(575781), UINT32_C(1368405) },
       {  UINT32_C(172538), UINT32_C(1978412), UINT32_C(1670805)},
     { {  UINT32_C(350154), UINT32_C(350154), UINT32_C(350154), UINT32_C(350154) },
       {  UINT32_C(575781), UINT32_C(575781), UINT32_C(575781), UINT32_C(575781) },
       {  UINT32_C(1368405), UINT32_C(1368405), UINT32_C(1368405), UINT32_C(1368405) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x3_t r = simde_vld3q_dup_u32(test_vec[i].a);
    simde_uint32x4x3_t expected = {
        {simde_vld1q_u32(test_vec[i].r[0]), simde_vld1q_u32(test_vec[i].r[1]), simde_vld1q_u32(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3q_dup_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[3];
    uint64_t unused[3];
    uint64_t r[3][2];
  } test_vec[] = {
     { {  UINT64_C(155091681), UINT64_C(112589773), UINT64_C(63143791) },
       {  UINT64_C(23716520), UINT64_C(176818970), UINT64_C(116173662)},
     { {  UINT64_C(155091681), UINT64_C(155091681) },
       {  UINT64_C(112589773), UINT64_C(112589773) },
       {  UINT64_C(63143791), UINT64_C(63143791) } } },
     { {  UINT64_C(130942524), UINT64_C(57780860), UINT64_C(31934739) },
       {  UINT64_C(176079421), UINT64_C(5675018), UINT64_C(63494312)},
     { {  UINT64_C(130942524), UINT64_C(130942524) },
       {  UINT64_C(57780860), UINT64_C(57780860) },
       {  UINT64_C(31934739), UINT64_C(31934739) } } },
     { {  UINT64_C(194457642), UINT64_C(39554875), UINT64_C(15224283) },
       {  UINT64_C(71051928), UINT64_C(81814738), UINT64_C(2283266)},
     { {  UINT64_C(194457642), UINT64_C(194457642) },
       {  UINT64_C(39554875), UINT64_C(39554875) },
       {  UINT64_C(15224283), UINT64_C(15224283) } } },
     { {  UINT64_C(23817396), UINT64_C(113541293), UINT64_C(123440835) },
       {  UINT64_C(102375805), UINT64_C(133049515), UINT64_C(41509326)},
     { {  UINT64_C(23817396), UINT64_C(23817396) },
       {  UINT64_C(113541293), UINT64_C(113541293) },
       {  UINT64_C(123440835), UINT64_C(123440835) } } },
     { {  UINT64_C(2000000), UINT64_C(51642274), UINT64_C(110635130) },
       {  UINT64_C(133946772), UINT64_C(153402717), UINT64_C(120380529)},
     { {  UINT64_C(2000000), UINT64_C(2000000) },
       {  UINT64_C(51642274), UINT64_C(51642274) },
       {  UINT64_C(110635130), UINT64_C(110635130) } } },
     { {  UINT64_C(174832616), UINT64_C(187609954), UINT64_C(22590510) },
       {  UINT64_C(93628333), UINT64_C(86283110), UINT64_C(199160701)},
     { {  UINT64_C(174832616), UINT64_C(174832616) },
       {  UINT64_C(187609954), UINT64_C(187609954) },
       {  UINT64_C(22590510), UINT64_C(22590510) } } },
     { {  UINT64_C(137018276), UINT64_C(195056582), UINT64_C(193644384) },
       {  UINT64_C(108521062), UINT64_C(28373149), UINT64_C(12285757)},
     { {  UINT64_C(137018276), UINT64_C(137018276) },
       {  UINT64_C(195056582), UINT64_C(195056582) },
       {  UINT64_C(193644384), UINT64_C(193644384) } } },
     { {  UINT64_C(56333011), UINT64_C(89077389), UINT64_C(76364445) },
       {  UINT64_C(662711), UINT64_C(94837583), UINT64_C(180422589)},
     { {  UINT64_C(56333011), UINT64_C(56333011) },
       {  UINT64_C(89077389), UINT64_C(89077389) },
       {  UINT64_C(76364445), UINT64_C(76364445) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x3_t r = simde_vld3q_dup_u64(test_vec[i].a);
    simde_uint64x2x3_t expected = {
        {simde_vld1q_u64(test_vec[i].r[0]), simde_vld1q_u64(test_vec[i].r[1]), simde_vld1q_u64(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_u64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[2], expected.val[2]);
  }

  return 0;
}

static int
test_simde_vld3_dup_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[3];
    simde_poly8_t unused[3];
    simde_poly8_t r[3][8];
  } test_vec[] = {
     { {  SIMDE_POLY8_C(135), SIMDE_POLY8_C(154), SIMDE_POLY8_C(34) },
       {  SIMDE_POLY8_C(4), SIMDE_POLY8_C(55), SIMDE_POLY8_C(125)},
     { {  SIMDE_POLY8_C(135), SIMDE_POLY8_C(135), SIMDE_POLY8_C(135), SIMDE_POLY8_C(135),
        SIMDE_POLY8_C(135), SIMDE_POLY8_C(135), SIMDE_POLY8_C(135), SIMDE_POLY8_C(135) },
       {  SIMDE_POLY8_C(154), SIMDE_POLY8_C(154), SIMDE_POLY8_C(154), SIMDE_POLY8_C(154),
        SIMDE_POLY8_C(154), SIMDE_POLY8_C(154), SIMDE_POLY8_C(154), SIMDE_POLY8_C(154) },
       {  SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34),
        SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34) } } },
     { {  SIMDE_POLY8_C(182), SIMDE_POLY8_C(2), SIMDE_POLY8_C(184) },
       {  SIMDE_POLY8_C(165), SIMDE_POLY8_C(123), SIMDE_POLY8_C(191)},
     { {  SIMDE_POLY8_C(182), SIMDE_POLY8_C(182), SIMDE_POLY8_C(182), SIMDE_POLY8_C(182),
        SIMDE_POLY8_C(182), SIMDE_POLY8_C(182), SIMDE_POLY8_C(182), SIMDE_POLY8_C(182) },
       {  SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2),
        SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2), SIMDE_POLY8_C(2) },
       {  SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184),
        SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184), SIMDE_POLY8_C(184) } } },
     { {  SIMDE_POLY8_C(127), SIMDE_POLY8_C(64), SIMDE_POLY8_C(31) },
       {  SIMDE_POLY8_C(41), SIMDE_POLY8_C(77), SIMDE_POLY8_C(44)},
     { {  SIMDE_POLY8_C(127), SIMDE_POLY8_C(127), SIMDE_POLY8_C(127), SIMDE_POLY8_C(127),
        SIMDE_POLY8_C(127), SIMDE_POLY8_C(127), SIMDE_POLY8_C(127), SIMDE_POLY8_C(127) },
       {  SIMDE_POLY8_C(64), SIMDE_POLY8_C(64), SIMDE_POLY8_C(64), SIMDE_POLY8_C(64),
        SIMDE_POLY8_C(64), SIMDE_POLY8_C(64), SIMDE_POLY8_C(64), SIMDE_POLY8_C(64) },
       {  SIMDE_POLY8_C(31), SIMDE_POLY8_C(31), SIMDE_POLY8_C(31), SIMDE_POLY8_C(31),
        SIMDE_POLY8_C(31), SIMDE_POLY8_C(31), SIMDE_POLY8_C(31), SIMDE_POLY8_C(31) } } },
     { {  SIMDE_POLY8_C(95), SIMDE_POLY8_C(134), SIMDE_POLY8_C(151) },
       {  SIMDE_POLY8_C(30), SIMDE_POLY8_C(126), SIMDE_POLY8_C(11)},
     { {  SIMDE_POLY8_C(95), SIMDE_POLY8_C(95), SIMDE_POLY8_C(95), SIMDE_POLY8_C(95),
        SIMDE_POLY8_C(95), SIMDE_POLY8_C(95), SIMDE_POLY8_C(95), SIMDE_POLY8_C(95) },
       {  SIMDE_POLY8_C(134), SIMDE_POLY8_C(134), SIMDE_POLY8_C(134), SIMDE_POLY8_C(134),
        SIMDE_POLY8_C(134), SIMDE_POLY8_C(134), SIMDE_POLY8_C(134), SIMDE_POLY8_C(134) },
       {  SIMDE_POLY8_C(151), SIMDE_POLY8_C(151), SIMDE_POLY8_C(151), SIMDE_POLY8_C(151),
        SIMDE_POLY8_C(151), SIMDE_POLY8_C(151), SIMDE_POLY8_C(151), SIMDE_POLY8_C(151) } } },
     { {  SIMDE_POLY8_C(198), SIMDE_POLY8_C(171), SIMDE_POLY8_C(185) },
       {  SIMDE_POLY8_C(44), SIMDE_POLY8_C(68), SIMDE_POLY8_C(53)},
     { {  SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198),
        SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198) },
       {  SIMDE_POLY8_C(171), SIMDE_POLY8_C(171), SIMDE_POLY8_C(171), SIMDE_POLY8_C(171),
        SIMDE_POLY8_C(171), SIMDE_POLY8_C(171), SIMDE_POLY8_C(171), SIMDE_POLY8_C(171) },
       {  SIMDE_POLY8_C(185), SIMDE_POLY8_C(185), SIMDE_POLY8_C(185), SIMDE_POLY8_C(185),
        SIMDE_POLY8_C(185), SIMDE_POLY8_C(185), SIMDE_POLY8_C(185), SIMDE_POLY8_C(185) } } },
     { {  SIMDE_POLY8_C(149), SIMDE_POLY8_C(156), SIMDE_POLY8_C(25) },
       {  SIMDE_POLY8_C(131), SIMDE_POLY8_C(33), SIMDE_POLY8_C(82)},
     { {  SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149),
        SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149) },
       {  SIMDE_POLY8_C(156), SIMDE_POLY8_C(156), SIMDE_POLY8_C(156), SIMDE_POLY8_C(156),
        SIMDE_POLY8_C(156), SIMDE_POLY8_C(156), SIMDE_POLY8_C(156), SIMDE_POLY8_C(156) },
       {  SIMDE_POLY8_C(25), SIMDE_POLY8_C(25), SIMDE_POLY8_C(25), SIMDE_POLY8_C(25),
        SIMDE_POLY8_C(25), SIMDE_POLY8_C(25), SIMDE_POLY8_C(25), SIMDE_POLY8_C(25) } } },
     { {  SIMDE_POLY8_C(168), SIMDE_POLY8_C(104), SIMDE_POLY8_C(156) },
       {  SIMDE_POLY8_C(82), SIMDE_POLY8_C(180), SIMDE_POLY8_C(74)},
     { {  SIMDE_POLY8_C(168), SIMDE_POLY8_C(168), SIMDE_POLY8_C(168), SIMDE_POLY8_C(168),
        SIMDE_POLY8_C(168), SIMDE_POLY8_C(168), SIMDE_POLY8_C(168), SIMDE_POLY8_C(168) },
       {  SIMDE_POLY8_C(104), SIMDE_POLY8_C(104), SIMDE_POLY8_C(104), SIMDE_POLY8_C(104),
        SIMDE_POLY8_C(104), SIMDE_POLY8_C(104), SIMDE_POLY8_C(104), SIMDE_POLY8_C(104) },
       {  SIMDE_POLY8_C(156), SIMDE_POLY8_C(156), SIMDE_POLY8_C(156), SIMDE_POLY8_C(156),
        SIMDE_POLY8_C(156), SIMDE_POLY8_C(156), SIMDE_POLY8_C(156), SIMDE_POLY8_C(156) } } },
     { {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(9), SIMDE_POLY8_C(108) },
       {  SIMDE_POLY8_C(197), SIMDE_POLY8_C(40), SIMDE_POLY8_C(191)},
     { {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(20), SIMDE_POLY8_C(20), SIMDE_POLY8_C(20),
        SIMDE_POLY8_C(20), SIMDE_POLY8_C(20), SIMDE_POLY8_C(20), SIMDE_POLY8_C(20) },
       {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9),
        SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9) },
       {  SIMDE_POLY8_C(108), SIMDE_POLY8_C(108), SIMDE_POLY8_C(108), SIMDE_POLY8_C(108),
        SIMDE_POLY8_C(108), SIMDE_POLY8_C(108), SIMDE_POLY8_C(108), SIMDE_POLY8_C(108) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8x3_t r = simde_vld3_dup_p8(test_vec[i].a);
    simde_poly8x8x3_t expected = {
        {simde_vld1_p8(test_vec[i].r[0]), simde_vld1_p8(test_vec[i].r[1]), simde_vld1_p8(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_p8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly8_t a[3];
    simde_poly8_t unused[3];
    simde_poly8x8x3_t r;
    simde_test_codegen_random_memory(3, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(3, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld3_dup_p8(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp8(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp8(2, 3, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3_dup_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[3];
    simde_poly16_t unused[3];
    simde_poly16_t r[3][4];
  } test_vec[] = {
     { {  SIMDE_POLY16_C(13377), SIMDE_POLY16_C(10805), SIMDE_POLY16_C(14630) },
       {  SIMDE_POLY16_C(10222), SIMDE_POLY16_C(12690), SIMDE_POLY16_C(19072)},
     { {  SIMDE_POLY16_C(13377), SIMDE_POLY16_C(13377), SIMDE_POLY16_C(13377), SIMDE_POLY16_C(13377) },
       {  SIMDE_POLY16_C(10805), SIMDE_POLY16_C(10805), SIMDE_POLY16_C(10805), SIMDE_POLY16_C(10805) },
       {  SIMDE_POLY16_C(14630), SIMDE_POLY16_C(14630), SIMDE_POLY16_C(14630), SIMDE_POLY16_C(14630) } } },
     { {  SIMDE_POLY16_C(8093), SIMDE_POLY16_C(11570), SIMDE_POLY16_C(183) },
       {  SIMDE_POLY16_C(14974), SIMDE_POLY16_C(2867), SIMDE_POLY16_C(19983)},
     { {  SIMDE_POLY16_C(8093), SIMDE_POLY16_C(8093), SIMDE_POLY16_C(8093), SIMDE_POLY16_C(8093) },
       {  SIMDE_POLY16_C(11570), SIMDE_POLY16_C(11570), SIMDE_POLY16_C(11570), SIMDE_POLY16_C(11570) },
       {  SIMDE_POLY16_C(183), SIMDE_POLY16_C(183), SIMDE_POLY16_C(183), SIMDE_POLY16_C(183) } } },
     { {  SIMDE_POLY16_C(51), SIMDE_POLY16_C(11622), SIMDE_POLY16_C(2412) },
       {  SIMDE_POLY16_C(186), SIMDE_POLY16_C(13191), SIMDE_POLY16_C(7620)},
     { {  SIMDE_POLY16_C(51), SIMDE_POLY16_C(51), SIMDE_POLY16_C(51), SIMDE_POLY16_C(51) },
       {  SIMDE_POLY16_C(11622), SIMDE_POLY16_C(11622), SIMDE_POLY16_C(11622), SIMDE_POLY16_C(11622) },
       {  SIMDE_POLY16_C(2412), SIMDE_POLY16_C(2412), SIMDE_POLY16_C(2412), SIMDE_POLY16_C(2412) } } },
     { {  SIMDE_POLY16_C(1319), SIMDE_POLY16_C(3015), SIMDE_POLY16_C(17065) },
       {  SIMDE_POLY16_C(2405), SIMDE_POLY16_C(6666), SIMDE_POLY16_C(16892)},
     { {  SIMDE_POLY16_C(1319), SIMDE_POLY16_C(1319), SIMDE_POLY16_C(1319), SIMDE_POLY16_C(1319) },
       {  SIMDE_POLY16_C(3015), SIMDE_POLY16_C(3015), SIMDE_POLY16_C(3015), SIMDE_POLY16_C(3015) },
       {  SIMDE_POLY16_C(17065), SIMDE_POLY16_C(17065), SIMDE_POLY16_C(17065), SIMDE_POLY16_C(17065) } } },
     { {  SIMDE_POLY16_C(5845), SIMDE_POLY16_C(17414), SIMDE_POLY16_C(9474) },
       {  SIMDE_POLY16_C(17463), SIMDE_POLY16_C(1796), SIMDE_POLY16_C(5656)},
     { {  SIMDE_POLY16_C(5845), SIMDE_POLY16_C(5845), SIMDE_POLY16_C(5845), SIMDE_POLY16_C(5845) },
       {  SIMDE_POLY16_C(17414), SIMDE_POLY16_C(17414), SIMDE_POLY16_C(17414), SIMDE_POLY16_C(17414) },
       {  SIMDE_POLY16_C(9474), SIMDE_POLY16_C(9474), SIMDE_POLY16_C(9474), SIMDE_POLY16_C(9474) } } },
     { {  SIMDE_POLY16_C(4232), SIMDE_POLY16_C(1927), SIMDE_POLY16_C(15662) },
       {  SIMDE_POLY16_C(4302), SIMDE_POLY16_C(2477), SIMDE_POLY16_C(16338)},
     { {  SIMDE_POLY16_C(4232), SIMDE_POLY16_C(4232), SIMDE_POLY16_C(4232), SIMDE_POLY16_C(4232) },
       {  SIMDE_POLY16_C(1927), SIMDE_POLY16_C(1927), SIMDE_POLY16_C(1927), SIMDE_POLY16_C(1927) },
       {  SIMDE_POLY16_C(15662), SIMDE_POLY16_C(15662), SIMDE_POLY16_C(15662), SIMDE_POLY16_C(15662) } } },
     { {  SIMDE_POLY16_C(2091), SIMDE_POLY16_C(9041), SIMDE_POLY16_C(5199) },
       {  SIMDE_POLY16_C(2392), SIMDE_POLY16_C(11870), SIMDE_POLY16_C(18327)},
     { {  SIMDE_POLY16_C(2091), SIMDE_POLY16_C(2091), SIMDE_POLY16_C(2091), SIMDE_POLY16_C(2091) },
       {  SIMDE_POLY16_C(9041), SIMDE_POLY16_C(9041), SIMDE_POLY16_C(9041), SIMDE_POLY16_C(9041) },
       {  SIMDE_POLY16_C(5199), SIMDE_POLY16_C(5199), SIMDE_POLY16_C(5199), SIMDE_POLY16_C(5199) } } },
     { {  SIMDE_POLY16_C(9669), SIMDE_POLY16_C(11054), SIMDE_POLY16_C(16736) },
       {  SIMDE_POLY16_C(8412), SIMDE_POLY16_C(8721), SIMDE_POLY16_C(13754)},
     { {  SIMDE_POLY16_C(9669), SIMDE_POLY16_C(9669), SIMDE_POLY16_C(9669), SIMDE_POLY16_C(9669) },
       {  SIMDE_POLY16_C(11054), SIMDE_POLY16_C(11054), SIMDE_POLY16_C(11054), SIMDE_POLY16_C(11054) },
       {  SIMDE_POLY16_C(16736), SIMDE_POLY16_C(16736), SIMDE_POLY16_C(16736), SIMDE_POLY16_C(16736) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4x3_t r = simde_vld3_dup_p16(test_vec[i].a);
    simde_poly16x4x3_t expected = {
        {simde_vld1_p16(test_vec[i].r[0]), simde_vld1_p16(test_vec[i].r[1]), simde_vld1_p16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_p16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16_t a[3];
    simde_poly16_t unused[3];
    simde_poly16x4x3_t r;
    simde_test_codegen_random_memory(6, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(6, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld3_dup_p16(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp16(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp16(2, 3, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3_dup_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[3];
    simde_poly64_t unused[3];
    simde_poly64_t r[3][1];
  } test_vec[] = {
     { {  SIMDE_POLY64_C(160975844), SIMDE_POLY64_C(153508503), SIMDE_POLY64_C(173493973) },
       {  SIMDE_POLY64_C(166251921), SIMDE_POLY64_C(65830676), SIMDE_POLY64_C(97239677)},
     { {  SIMDE_POLY64_C(160975844) },
       {  SIMDE_POLY64_C(153508503) },
       {  SIMDE_POLY64_C(173493973) } } },
     { {  SIMDE_POLY64_C(187315367), SIMDE_POLY64_C(5800842), SIMDE_POLY64_C(115739498) },
       {  SIMDE_POLY64_C(84653812), SIMDE_POLY64_C(120517420), SIMDE_POLY64_C(175798293)},
     { {  SIMDE_POLY64_C(187315367) },
       {  SIMDE_POLY64_C(5800842) },
       {  SIMDE_POLY64_C(115739498) } } },
     { {  SIMDE_POLY64_C(76024341), SIMDE_POLY64_C(155566333), SIMDE_POLY64_C(101038279) },
       {  SIMDE_POLY64_C(46074453), SIMDE_POLY64_C(151593559), SIMDE_POLY64_C(39262253)},
     { {  SIMDE_POLY64_C(76024341) },
       {  SIMDE_POLY64_C(155566333) },
       {  SIMDE_POLY64_C(101038279) } } },
     { {  SIMDE_POLY64_C(46906477), SIMDE_POLY64_C(997782), SIMDE_POLY64_C(69721610) },
       {  SIMDE_POLY64_C(31134385), SIMDE_POLY64_C(173251253), SIMDE_POLY64_C(151509065)},
     { {  SIMDE_POLY64_C(46906477) },
       {  SIMDE_POLY64_C(997782) },
       {  SIMDE_POLY64_C(69721610) } } },
     { {  SIMDE_POLY64_C(59105148), SIMDE_POLY64_C(194933961), SIMDE_POLY64_C(18072130) },
       {  SIMDE_POLY64_C(67463877), SIMDE_POLY64_C(80370119), SIMDE_POLY64_C(107818223)},
     { {  SIMDE_POLY64_C(59105148) },
       {  SIMDE_POLY64_C(194933961) },
       {  SIMDE_POLY64_C(18072130) } } },
     { {  SIMDE_POLY64_C(187736185), SIMDE_POLY64_C(161160447), SIMDE_POLY64_C(24909245) },
       {  SIMDE_POLY64_C(110288501), SIMDE_POLY64_C(110076399), SIMDE_POLY64_C(184478722)},
     { {  SIMDE_POLY64_C(187736185) },
       {  SIMDE_POLY64_C(161160447) },
       {  SIMDE_POLY64_C(24909245) } } },
     { {  SIMDE_POLY64_C(113683975), SIMDE_POLY64_C(71734803), SIMDE_POLY64_C(50110366) },
       {  SIMDE_POLY64_C(20964634), SIMDE_POLY64_C(167646318), SIMDE_POLY64_C(171677397)},
     { {  SIMDE_POLY64_C(113683975) },
       {  SIMDE_POLY64_C(71734803) },
       {  SIMDE_POLY64_C(50110366) } } },
     { {  SIMDE_POLY64_C(5715707), SIMDE_POLY64_C(147794026), SIMDE_POLY64_C(162515415) },
       {  SIMDE_POLY64_C(142055920), SIMDE_POLY64_C(10766156), SIMDE_POLY64_C(64823110)},
     { {  SIMDE_POLY64_C(5715707) },
       {  SIMDE_POLY64_C(147794026) },
       {  SIMDE_POLY64_C(162515415) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1x3_t r = simde_vld3_dup_p64(test_vec[i].a);
    simde_poly64x1x3_t expected = {
        {simde_vld1_p64(test_vec[i].r[0]), simde_vld1_p64(test_vec[i].r[1]), simde_vld1_p64(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_p64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly64_t a[3];
    simde_poly64_t unused[3];
    simde_poly64x1x3_t r;
    simde_test_codegen_random_memory(24, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(24, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld3_dup_p64(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp64(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp64(2, 3, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3q_dup_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[3];
    simde_poly8_t unused[3];
    simde_poly8_t r[3][16];
  } test_vec[] = {
     { {  SIMDE_POLY8_C(131), SIMDE_POLY8_C(170), SIMDE_POLY8_C(140) },
       {  SIMDE_POLY8_C(114), SIMDE_POLY8_C(199), SIMDE_POLY8_C(32)},
     { {  SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131),
        SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131), SIMDE_POLY8_C(131) },
       {  SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170),
        SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170), SIMDE_POLY8_C(170) },
       {  SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140),
        SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140) } } },
     { {  SIMDE_POLY8_C(122), SIMDE_POLY8_C(34), SIMDE_POLY8_C(152) },
       {  SIMDE_POLY8_C(111), SIMDE_POLY8_C(186), SIMDE_POLY8_C(172)},
     { {  SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122),
        SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122), SIMDE_POLY8_C(122) },
       {  SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34),
        SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34) },
       {  SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152),
        SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152), SIMDE_POLY8_C(152) } } },
     { {  SIMDE_POLY8_C(198), SIMDE_POLY8_C(18), SIMDE_POLY8_C(101) },
       {  SIMDE_POLY8_C(91), SIMDE_POLY8_C(119), SIMDE_POLY8_C(69)},
     { {  SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198),
        SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198), SIMDE_POLY8_C(198) },
       {  SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18),
        SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18), SIMDE_POLY8_C(18) },
       {  SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101),
        SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101), SIMDE_POLY8_C(101) } } },
     { {  SIMDE_POLY8_C(148), SIMDE_POLY8_C(113), SIMDE_POLY8_C(110) },
       {  SIMDE_POLY8_C(57), SIMDE_POLY8_C(103), SIMDE_POLY8_C(149)},
     { {  SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148),
        SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148), SIMDE_POLY8_C(148) },
       {  SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113),
        SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113), SIMDE_POLY8_C(113) },
       {  SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110),
        SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110), SIMDE_POLY8_C(110) } } },
     { {  SIMDE_POLY8_C(13), SIMDE_POLY8_C(140), SIMDE_POLY8_C(72) },
       {  SIMDE_POLY8_C(114), SIMDE_POLY8_C(161), SIMDE_POLY8_C(131)},
     { {  SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13),
        SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13), SIMDE_POLY8_C(13) },
       {  SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140),
        SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140), SIMDE_POLY8_C(140) },
       {  SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72),
        SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72) } } },
     { {  SIMDE_POLY8_C(66), SIMDE_POLY8_C(23), SIMDE_POLY8_C(149) },
       {  SIMDE_POLY8_C(20), SIMDE_POLY8_C(31), SIMDE_POLY8_C(114)},
     { {  SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66),
        SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66), SIMDE_POLY8_C(66) },
       {  SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23),
        SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23) },
       {  SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149),
        SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149), SIMDE_POLY8_C(149) } } },
     { {  SIMDE_POLY8_C(65), SIMDE_POLY8_C(19), SIMDE_POLY8_C(124) },
       {  SIMDE_POLY8_C(31), SIMDE_POLY8_C(9), SIMDE_POLY8_C(194)},
     { {  SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65),
        SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65) },
       {  SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19),
        SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19), SIMDE_POLY8_C(19) },
       {  SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124),
        SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124), SIMDE_POLY8_C(124) } } },
     { {  SIMDE_POLY8_C(72), SIMDE_POLY8_C(144), SIMDE_POLY8_C(159) },
       {  SIMDE_POLY8_C(87), SIMDE_POLY8_C(134), SIMDE_POLY8_C(28)},
     { {  SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72),
        SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72), SIMDE_POLY8_C(72) },
       {  SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144),
        SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144), SIMDE_POLY8_C(144) },
       {  SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159),
        SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159), SIMDE_POLY8_C(159) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16x3_t r = simde_vld3q_dup_p8(test_vec[i].a);
    simde_poly8x16x3_t expected = {
        {simde_vld1q_p8(test_vec[i].r[0]), simde_vld1q_p8(test_vec[i].r[1]), simde_vld1q_p8(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_p8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly8_t a[3];
    simde_poly8_t unused[3];
    simde_poly8x16x3_t r;
    simde_test_codegen_random_memory(3, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(3, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld3q_dup_p8(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp8(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp8(2, 3, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3q_dup_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[3];
    simde_poly16_t unused[3];
    simde_poly16_t r[3][8];
  } test_vec[] = {
     { {  SIMDE_POLY16_C(13221), SIMDE_POLY16_C(12229), SIMDE_POLY16_C(11071) },
       {  SIMDE_POLY16_C(17602), SIMDE_POLY16_C(4227), SIMDE_POLY16_C(7666)},
     { {  SIMDE_POLY16_C(13221), SIMDE_POLY16_C(13221), SIMDE_POLY16_C(13221), SIMDE_POLY16_C(13221),
        SIMDE_POLY16_C(13221), SIMDE_POLY16_C(13221), SIMDE_POLY16_C(13221), SIMDE_POLY16_C(13221) },
       {  SIMDE_POLY16_C(12229), SIMDE_POLY16_C(12229), SIMDE_POLY16_C(12229), SIMDE_POLY16_C(12229),
        SIMDE_POLY16_C(12229), SIMDE_POLY16_C(12229), SIMDE_POLY16_C(12229), SIMDE_POLY16_C(12229) },
       {  SIMDE_POLY16_C(11071), SIMDE_POLY16_C(11071), SIMDE_POLY16_C(11071), SIMDE_POLY16_C(11071),
        SIMDE_POLY16_C(11071), SIMDE_POLY16_C(11071), SIMDE_POLY16_C(11071), SIMDE_POLY16_C(11071) } } },
     { {  SIMDE_POLY16_C(12420), SIMDE_POLY16_C(14500), SIMDE_POLY16_C(12248) },
       {  SIMDE_POLY16_C(17926), SIMDE_POLY16_C(17458), SIMDE_POLY16_C(3685)},
     { {  SIMDE_POLY16_C(12420), SIMDE_POLY16_C(12420), SIMDE_POLY16_C(12420), SIMDE_POLY16_C(12420),
        SIMDE_POLY16_C(12420), SIMDE_POLY16_C(12420), SIMDE_POLY16_C(12420), SIMDE_POLY16_C(12420) },
       {  SIMDE_POLY16_C(14500), SIMDE_POLY16_C(14500), SIMDE_POLY16_C(14500), SIMDE_POLY16_C(14500),
        SIMDE_POLY16_C(14500), SIMDE_POLY16_C(14500), SIMDE_POLY16_C(14500), SIMDE_POLY16_C(14500) },
       {  SIMDE_POLY16_C(12248), SIMDE_POLY16_C(12248), SIMDE_POLY16_C(12248), SIMDE_POLY16_C(12248),
        SIMDE_POLY16_C(12248), SIMDE_POLY16_C(12248), SIMDE_POLY16_C(12248), SIMDE_POLY16_C(12248) } } },
     { {  SIMDE_POLY16_C(8504), SIMDE_POLY16_C(3056), SIMDE_POLY16_C(15978) },
       {  SIMDE_POLY16_C(11648), SIMDE_POLY16_C(2353), SIMDE_POLY16_C(16355)},
     { {  SIMDE_POLY16_C(8504), SIMDE_POLY16_C(8504), SIMDE_POLY16_C(8504), SIMDE_POLY16_C(8504),
        SIMDE_POLY16_C(8504), SIMDE_POLY16_C(8504), SIMDE_POLY16_C(8504), SIMDE_POLY16_C(8504) },
       {  SIMDE_POLY16_C(3056), SIMDE_POLY16_C(3056), SIMDE_POLY16_C(3056), SIMDE_POLY16_C(3056),
        SIMDE_POLY16_C(3056), SIMDE_POLY16_C(3056), SIMDE_POLY16_C(3056), SIMDE_POLY16_C(3056) },
       {  SIMDE_POLY16_C(15978), SIMDE_POLY16_C(15978), SIMDE_POLY16_C(15978), SIMDE_POLY16_C(15978),
        SIMDE_POLY16_C(15978), SIMDE_POLY16_C(15978), SIMDE_POLY16_C(15978), SIMDE_POLY16_C(15978) } } },
     { {  SIMDE_POLY16_C(15523), SIMDE_POLY16_C(1359), SIMDE_POLY16_C(16502) },
       {  SIMDE_POLY16_C(13928), SIMDE_POLY16_C(5794), SIMDE_POLY16_C(818)},
     { {  SIMDE_POLY16_C(15523), SIMDE_POLY16_C(15523), SIMDE_POLY16_C(15523), SIMDE_POLY16_C(15523),
        SIMDE_POLY16_C(15523), SIMDE_POLY16_C(15523), SIMDE_POLY16_C(15523), SIMDE_POLY16_C(15523) },
       {  SIMDE_POLY16_C(1359), SIMDE_POLY16_C(1359), SIMDE_POLY16_C(1359), SIMDE_POLY16_C(1359),
        SIMDE_POLY16_C(1359), SIMDE_POLY16_C(1359), SIMDE_POLY16_C(1359), SIMDE_POLY16_C(1359) },
       {  SIMDE_POLY16_C(16502), SIMDE_POLY16_C(16502), SIMDE_POLY16_C(16502), SIMDE_POLY16_C(16502),
        SIMDE_POLY16_C(16502), SIMDE_POLY16_C(16502), SIMDE_POLY16_C(16502), SIMDE_POLY16_C(16502) } } },
     { {  SIMDE_POLY16_C(19929), SIMDE_POLY16_C(2856), SIMDE_POLY16_C(3524) },
       {  SIMDE_POLY16_C(4725), SIMDE_POLY16_C(16666), SIMDE_POLY16_C(9010)},
     { {  SIMDE_POLY16_C(19929), SIMDE_POLY16_C(19929), SIMDE_POLY16_C(19929), SIMDE_POLY16_C(19929),
        SIMDE_POLY16_C(19929), SIMDE_POLY16_C(19929), SIMDE_POLY16_C(19929), SIMDE_POLY16_C(19929) },
       {  SIMDE_POLY16_C(2856), SIMDE_POLY16_C(2856), SIMDE_POLY16_C(2856), SIMDE_POLY16_C(2856),
        SIMDE_POLY16_C(2856), SIMDE_POLY16_C(2856), SIMDE_POLY16_C(2856), SIMDE_POLY16_C(2856) },
       {  SIMDE_POLY16_C(3524), SIMDE_POLY16_C(3524), SIMDE_POLY16_C(3524), SIMDE_POLY16_C(3524),
        SIMDE_POLY16_C(3524), SIMDE_POLY16_C(3524), SIMDE_POLY16_C(3524), SIMDE_POLY16_C(3524) } } },
     { {  SIMDE_POLY16_C(1112), SIMDE_POLY16_C(8015), SIMDE_POLY16_C(4791) },
       {  SIMDE_POLY16_C(18035), SIMDE_POLY16_C(7170), SIMDE_POLY16_C(3494)},
     { {  SIMDE_POLY16_C(1112), SIMDE_POLY16_C(1112), SIMDE_POLY16_C(1112), SIMDE_POLY16_C(1112),
        SIMDE_POLY16_C(1112), SIMDE_POLY16_C(1112), SIMDE_POLY16_C(1112), SIMDE_POLY16_C(1112) },
       {  SIMDE_POLY16_C(8015), SIMDE_POLY16_C(8015), SIMDE_POLY16_C(8015), SIMDE_POLY16_C(8015),
        SIMDE_POLY16_C(8015), SIMDE_POLY16_C(8015), SIMDE_POLY16_C(8015), SIMDE_POLY16_C(8015) },
       {  SIMDE_POLY16_C(4791), SIMDE_POLY16_C(4791), SIMDE_POLY16_C(4791), SIMDE_POLY16_C(4791),
        SIMDE_POLY16_C(4791), SIMDE_POLY16_C(4791), SIMDE_POLY16_C(4791), SIMDE_POLY16_C(4791) } } },
     { {  SIMDE_POLY16_C(19750), SIMDE_POLY16_C(19409), SIMDE_POLY16_C(17275) },
       {  SIMDE_POLY16_C(5089), SIMDE_POLY16_C(5163), SIMDE_POLY16_C(18594)},
     { {  SIMDE_POLY16_C(19750), SIMDE_POLY16_C(19750), SIMDE_POLY16_C(19750), SIMDE_POLY16_C(19750),
        SIMDE_POLY16_C(19750), SIMDE_POLY16_C(19750), SIMDE_POLY16_C(19750), SIMDE_POLY16_C(19750) },
       {  SIMDE_POLY16_C(19409), SIMDE_POLY16_C(19409), SIMDE_POLY16_C(19409), SIMDE_POLY16_C(19409),
        SIMDE_POLY16_C(19409), SIMDE_POLY16_C(19409), SIMDE_POLY16_C(19409), SIMDE_POLY16_C(19409) },
       {  SIMDE_POLY16_C(17275), SIMDE_POLY16_C(17275), SIMDE_POLY16_C(17275), SIMDE_POLY16_C(17275),
        SIMDE_POLY16_C(17275), SIMDE_POLY16_C(17275), SIMDE_POLY16_C(17275), SIMDE_POLY16_C(17275) } } },
     { {  SIMDE_POLY16_C(7578), SIMDE_POLY16_C(8951), SIMDE_POLY16_C(11969) },
       {  SIMDE_POLY16_C(15208), SIMDE_POLY16_C(9477), SIMDE_POLY16_C(18579)},
     { {  SIMDE_POLY16_C(7578), SIMDE_POLY16_C(7578), SIMDE_POLY16_C(7578), SIMDE_POLY16_C(7578),
        SIMDE_POLY16_C(7578), SIMDE_POLY16_C(7578), SIMDE_POLY16_C(7578), SIMDE_POLY16_C(7578) },
       {  SIMDE_POLY16_C(8951), SIMDE_POLY16_C(8951), SIMDE_POLY16_C(8951), SIMDE_POLY16_C(8951),
        SIMDE_POLY16_C(8951), SIMDE_POLY16_C(8951), SIMDE_POLY16_C(8951), SIMDE_POLY16_C(8951) },
       {  SIMDE_POLY16_C(11969), SIMDE_POLY16_C(11969), SIMDE_POLY16_C(11969), SIMDE_POLY16_C(11969),
        SIMDE_POLY16_C(11969), SIMDE_POLY16_C(11969), SIMDE_POLY16_C(11969), SIMDE_POLY16_C(11969) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8x3_t r = simde_vld3q_dup_p16(test_vec[i].a);
    simde_poly16x8x3_t expected = {
        {simde_vld1q_p16(test_vec[i].r[0]), simde_vld1q_p16(test_vec[i].r[1]), simde_vld1q_p16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_p16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16_t a[3];
    simde_poly16_t unused[3];
    simde_poly16x8x3_t r;
    simde_test_codegen_random_memory(6, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(6, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld3q_dup_p16(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp16(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp16(2, 3, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3q_dup_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[3];
    simde_poly64_t unused[3];
    simde_poly64_t r[3][2];
  } test_vec[] = {
     { {  SIMDE_POLY64_C(155091681), SIMDE_POLY64_C(112589773), SIMDE_POLY64_C(63143791) },
       {  SIMDE_POLY64_C(23716520), SIMDE_POLY64_C(176818970), SIMDE_POLY64_C(116173662)},
     { {  SIMDE_POLY64_C(155091681), SIMDE_POLY64_C(155091681) },
       {  SIMDE_POLY64_C(112589773), SIMDE_POLY64_C(112589773) },
       {  SIMDE_POLY64_C(63143791), SIMDE_POLY64_C(63143791) } } },
     { {  SIMDE_POLY64_C(130942524), SIMDE_POLY64_C(57780860), SIMDE_POLY64_C(31934739) },
       {  SIMDE_POLY64_C(176079421), SIMDE_POLY64_C(5675018), SIMDE_POLY64_C(63494312)},
     { {  SIMDE_POLY64_C(130942524), SIMDE_POLY64_C(130942524) },
       {  SIMDE_POLY64_C(57780860), SIMDE_POLY64_C(57780860) },
       {  SIMDE_POLY64_C(31934739), SIMDE_POLY64_C(31934739) } } },
     { {  SIMDE_POLY64_C(194457642), SIMDE_POLY64_C(39554875), SIMDE_POLY64_C(15224283) },
       {  SIMDE_POLY64_C(71051928), SIMDE_POLY64_C(81814738), SIMDE_POLY64_C(2283266)},
     { {  SIMDE_POLY64_C(194457642), SIMDE_POLY64_C(194457642) },
       {  SIMDE_POLY64_C(39554875), SIMDE_POLY64_C(39554875) },
       {  SIMDE_POLY64_C(15224283), SIMDE_POLY64_C(15224283) } } },
     { {  SIMDE_POLY64_C(23817396), SIMDE_POLY64_C(113541293), SIMDE_POLY64_C(123440835) },
       {  SIMDE_POLY64_C(102375805), SIMDE_POLY64_C(133049515), SIMDE_POLY64_C(41509326)},
     { {  SIMDE_POLY64_C(23817396), SIMDE_POLY64_C(23817396) },
       {  SIMDE_POLY64_C(113541293), SIMDE_POLY64_C(113541293) },
       {  SIMDE_POLY64_C(123440835), SIMDE_POLY64_C(123440835) } } },
     { {  SIMDE_POLY64_C(2000000), SIMDE_POLY64_C(51642274), SIMDE_POLY64_C(110635130) },
       {  SIMDE_POLY64_C(133946772), SIMDE_POLY64_C(153402717), SIMDE_POLY64_C(120380529)},
     { {  SIMDE_POLY64_C(2000000), SIMDE_POLY64_C(2000000) },
       {  SIMDE_POLY64_C(51642274), SIMDE_POLY64_C(51642274) },
       {  SIMDE_POLY64_C(110635130), SIMDE_POLY64_C(110635130) } } },
     { {  SIMDE_POLY64_C(174832616), SIMDE_POLY64_C(187609954), SIMDE_POLY64_C(22590510) },
       {  SIMDE_POLY64_C(93628333), SIMDE_POLY64_C(86283110), SIMDE_POLY64_C(199160701)},
     { {  SIMDE_POLY64_C(174832616), SIMDE_POLY64_C(174832616) },
       {  SIMDE_POLY64_C(187609954), SIMDE_POLY64_C(187609954) },
       {  SIMDE_POLY64_C(22590510), SIMDE_POLY64_C(22590510) } } },
     { {  SIMDE_POLY64_C(137018276), SIMDE_POLY64_C(195056582), SIMDE_POLY64_C(193644384) },
       {  SIMDE_POLY64_C(108521062), SIMDE_POLY64_C(28373149), SIMDE_POLY64_C(12285757)},
     { {  SIMDE_POLY64_C(137018276), SIMDE_POLY64_C(137018276) },
       {  SIMDE_POLY64_C(195056582), SIMDE_POLY64_C(195056582) },
       {  SIMDE_POLY64_C(193644384), SIMDE_POLY64_C(193644384) } } },
     { {  SIMDE_POLY64_C(56333011), SIMDE_POLY64_C(89077389), SIMDE_POLY64_C(76364445) },
       {  SIMDE_POLY64_C(662711), SIMDE_POLY64_C(94837583), SIMDE_POLY64_C(180422589)},
     { {  SIMDE_POLY64_C(56333011), SIMDE_POLY64_C(56333011) },
       {  SIMDE_POLY64_C(89077389), SIMDE_POLY64_C(89077389) },
       {  SIMDE_POLY64_C(76364445), SIMDE_POLY64_C(76364445) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2x3_t r = simde_vld3q_dup_p64(test_vec[i].a);
    simde_poly64x2x3_t expected = {
        {simde_vld1q_p64(test_vec[i].r[0]), simde_vld1q_p64(test_vec[i].r[1]), simde_vld1q_p64(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_p64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[1], expected.val[1]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[2], expected.val[2]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly64_t a[3];
    simde_poly64_t unused[3];
    simde_poly64x2x3_t r;
    simde_test_codegen_random_memory(24, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(24, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld3q_dup_p64(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp64(2, 3, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp64(2, 3, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2x3(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld3_dup_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t a[3];
    simde_bfloat16_t unused[3];
    simde_bfloat16_t r[3][4];
  } test_vec[] = {
     { {  SIMDE_BFLOAT16_VALUE(-6.58), SIMDE_BFLOAT16_VALUE(2.17), SIMDE_BFLOAT16_VALUE(3.51) },
       {  SIMDE_BFLOAT16_VALUE(-28.23), SIMDE_BFLOAT16_VALUE(27.18), SIMDE_BFLOAT16_VALUE(21.06)},
     { {  SIMDE_BFLOAT16_VALUE(-6.58), SIMDE_BFLOAT16_VALUE(-6.58), SIMDE_BFLOAT16_VALUE(-6.58), SIMDE_BFLOAT16_VALUE(-6.58) },
       {  SIMDE_BFLOAT16_VALUE(2.17), SIMDE_BFLOAT16_VALUE(2.17), SIMDE_BFLOAT16_VALUE(2.17), SIMDE_BFLOAT16_VALUE(2.17) },
       {  SIMDE_BFLOAT16_VALUE(3.51), SIMDE_BFLOAT16_VALUE(3.51), SIMDE_BFLOAT16_VALUE(3.51), SIMDE_BFLOAT16_VALUE(3.51) } } },
     { {  SIMDE_BFLOAT16_VALUE(-46.99), SIMDE_BFLOAT16_VALUE(-6.72), SIMDE_BFLOAT16_VALUE(41.08) },
       {  SIMDE_BFLOAT16_VALUE(-2.06), SIMDE_BFLOAT16_VALUE(-6.78), SIMDE_BFLOAT16_VALUE(36.58)},
     { {  SIMDE_BFLOAT16_VALUE(-46.99), SIMDE_BFLOAT16_VALUE(-46.99), SIMDE_BFLOAT16_VALUE(-46.99), SIMDE_BFLOAT16_VALUE(-46.99) },
       {  SIMDE_BFLOAT16_VALUE(-6.72), SIMDE_BFLOAT16_VALUE(-6.72), SIMDE_BFLOAT16_VALUE(-6.72), SIMDE_BFLOAT16_VALUE(-6.72) },
       {  SIMDE_BFLOAT16_VALUE(41.08), SIMDE_BFLOAT16_VALUE(41.08), SIMDE_BFLOAT16_VALUE(41.08), SIMDE_BFLOAT16_VALUE(41.08) } } },
     { {  SIMDE_BFLOAT16_VALUE(39.86), SIMDE_BFLOAT16_VALUE(40.77), SIMDE_BFLOAT16_VALUE(-32.22) },
       {  SIMDE_BFLOAT16_VALUE(-24.94), SIMDE_BFLOAT16_VALUE(-38.80), SIMDE_BFLOAT16_VALUE(7.87)},
     { {  SIMDE_BFLOAT16_VALUE(39.86), SIMDE_BFLOAT16_VALUE(39.86), SIMDE_BFLOAT16_VALUE(39.86), SIMDE_BFLOAT16_VALUE(39.86) },
       {  SIMDE_BFLOAT16_VALUE(40.77), SIMDE_BFLOAT16_VALUE(40.77), SIMDE_BFLOAT16_VALUE(40.77), SIMDE_BFLOAT16_VALUE(40.77) },
       {  SIMDE_BFLOAT16_VALUE(-32.22), SIMDE_BFLOAT16_VALUE(-32.22), SIMDE_BFLOAT16_VALUE(-32.22), SIMDE_BFLOAT16_VALUE(-32.22) } } },
     { {  SIMDE_BFLOAT16_VALUE(3.72), SIMDE_BFLOAT16_VALUE(45.41), SIMDE_BFLOAT16_VALUE(4.48) },
       {  SIMDE_BFLOAT16_VALUE(47.09), SIMDE_BFLOAT16_VALUE(-24.14), SIMDE_BFLOAT16_VALUE(-0.13)},
     { {  SIMDE_BFLOAT16_VALUE(3.72), SIMDE_BFLOAT16_VALUE(3.72), SIMDE_BFLOAT16_VALUE(3.72), SIMDE_BFLOAT16_VALUE(3.72) },
       {  SIMDE_BFLOAT16_VALUE(45.41), SIMDE_BFLOAT16_VALUE(45.41), SIMDE_BFLOAT16_VALUE(45.41), SIMDE_BFLOAT16_VALUE(45.41) },
       {  SIMDE_BFLOAT16_VALUE(4.48), SIMDE_BFLOAT16_VALUE(4.48), SIMDE_BFLOAT16_VALUE(4.48), SIMDE_BFLOAT16_VALUE(4.48) } } },
     { {  SIMDE_BFLOAT16_VALUE(-31.75), SIMDE_BFLOAT16_VALUE(20.34), SIMDE_BFLOAT16_VALUE(-29.59) },
       {  SIMDE_BFLOAT16_VALUE(-11.56), SIMDE_BFLOAT16_VALUE(-7.53), SIMDE_BFLOAT16_VALUE(28.61)},
     { {  SIMDE_BFLOAT16_VALUE(-31.75), SIMDE_BFLOAT16_VALUE(-31.75), SIMDE_BFLOAT16_VALUE(-31.75), SIMDE_BFLOAT16_VALUE(-31.75) },
       {  SIMDE_BFLOAT16_VALUE(20.34), SIMDE_BFLOAT16_VALUE(20.34), SIMDE_BFLOAT16_VALUE(20.34), SIMDE_BFLOAT16_VALUE(20.34) },
       {  SIMDE_BFLOAT16_VALUE(-29.59), SIMDE_BFLOAT16_VALUE(-29.59), SIMDE_BFLOAT16_VALUE(-29.59), SIMDE_BFLOAT16_VALUE(-29.59) } } },
     { {  SIMDE_BFLOAT16_VALUE(37.05), SIMDE_BFLOAT16_VALUE(17.72), SIMDE_BFLOAT16_VALUE(-49.37) },
       {  SIMDE_BFLOAT16_VALUE(-27.61), SIMDE_BFLOAT16_VALUE(-29.16), SIMDE_BFLOAT16_VALUE(2.30)},
     { {  SIMDE_BFLOAT16_VALUE(37.05), SIMDE_BFLOAT16_VALUE(37.05), SIMDE_BFLOAT16_VALUE(37.05), SIMDE_BFLOAT16_VALUE(37.05) },
       {  SIMDE_BFLOAT16_VALUE(17.72), SIMDE_BFLOAT16_VALUE(17.72), SIMDE_BFLOAT16_VALUE(17.72), SIMDE_BFLOAT16_VALUE(17.72) },
       {  SIMDE_BFLOAT16_VALUE(-49.37), SIMDE_BFLOAT16_VALUE(-49.37), SIMDE_BFLOAT16_VALUE(-49.37), SIMDE_BFLOAT16_VALUE(-49.37) } } },
     { {  SIMDE_BFLOAT16_VALUE(-49.24), SIMDE_BFLOAT16_VALUE(-2.48), SIMDE_BFLOAT16_VALUE(-45.21) },
       {  SIMDE_BFLOAT16_VALUE(19.81), SIMDE_BFLOAT16_VALUE(5.79), SIMDE_BFLOAT16_VALUE(42.08)},
     { {  SIMDE_BFLOAT16_VALUE(-49.24), SIMDE_BFLOAT16_VALUE(-49.24), SIMDE_BFLOAT16_VALUE(-49.24), SIMDE_BFLOAT16_VALUE(-49.24) },
       {  SIMDE_BFLOAT16_VALUE(-2.48), SIMDE_BFLOAT16_VALUE(-2.48), SIMDE_BFLOAT16_VALUE(-2.48), SIMDE_BFLOAT16_VALUE(-2.48) },
       {  SIMDE_BFLOAT16_VALUE(-45.21), SIMDE_BFLOAT16_VALUE(-45.21), SIMDE_BFLOAT16_VALUE(-45.21), SIMDE_BFLOAT16_VALUE(-45.21) } } },
     { {  SIMDE_BFLOAT16_VALUE(26.41), SIMDE_BFLOAT16_VALUE(49.96), SIMDE_BFLOAT16_VALUE(20.11) },
       {  SIMDE_BFLOAT16_VALUE(34.64), SIMDE_BFLOAT16_VALUE(-7.87), SIMDE_BFLOAT16_VALUE(-43.78)},
     { {  SIMDE_BFLOAT16_VALUE(26.41), SIMDE_BFLOAT16_VALUE(26.41), SIMDE_BFLOAT16_VALUE(26.41), SIMDE_BFLOAT16_VALUE(26.41) },
       {  SIMDE_BFLOAT16_VALUE(49.96), SIMDE_BFLOAT16_VALUE(49.96), SIMDE_BFLOAT16_VALUE(49.96), SIMDE_BFLOAT16_VALUE(49.96) },
       {  SIMDE_BFLOAT16_VALUE(20.11), SIMDE_BFLOAT16_VALUE(20.11), SIMDE_BFLOAT16_VALUE(20.11), SIMDE_BFLOAT16_VALUE(20.11) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4x3_t r = simde_vld3_dup_bf16(test_vec[i].a);
    simde_bfloat16x4x3_t expected = {
        {simde_vld1_bf16(test_vec[i].r[0]), simde_vld1_bf16(test_vec[i].r[1]), simde_vld1_bf16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_bf16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld3q_dup_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t a[3];
    simde_bfloat16_t unused[3];
    simde_bfloat16_t r[3][8];
  } test_vec[] = {
     { {  SIMDE_BFLOAT16_VALUE(20.19), SIMDE_BFLOAT16_VALUE(16.39), SIMDE_BFLOAT16_VALUE(46.17) },
       {  SIMDE_BFLOAT16_VALUE(29.32), SIMDE_BFLOAT16_VALUE(-18.79), SIMDE_BFLOAT16_VALUE(30.83)},
     { {  SIMDE_BFLOAT16_VALUE(20.19), SIMDE_BFLOAT16_VALUE(20.19), SIMDE_BFLOAT16_VALUE(20.19), SIMDE_BFLOAT16_VALUE(20.19),
        SIMDE_BFLOAT16_VALUE(20.19), SIMDE_BFLOAT16_VALUE(20.19), SIMDE_BFLOAT16_VALUE(20.19), SIMDE_BFLOAT16_VALUE(20.19) },
       {  SIMDE_BFLOAT16_VALUE(16.39), SIMDE_BFLOAT16_VALUE(16.39), SIMDE_BFLOAT16_VALUE(16.39), SIMDE_BFLOAT16_VALUE(16.39),
        SIMDE_BFLOAT16_VALUE(16.39), SIMDE_BFLOAT16_VALUE(16.39), SIMDE_BFLOAT16_VALUE(16.39), SIMDE_BFLOAT16_VALUE(16.39) },
       {  SIMDE_BFLOAT16_VALUE(46.17), SIMDE_BFLOAT16_VALUE(46.17), SIMDE_BFLOAT16_VALUE(46.17), SIMDE_BFLOAT16_VALUE(46.17),
        SIMDE_BFLOAT16_VALUE(46.17), SIMDE_BFLOAT16_VALUE(46.17), SIMDE_BFLOAT16_VALUE(46.17), SIMDE_BFLOAT16_VALUE(46.17) } } },
     { {  SIMDE_BFLOAT16_VALUE(-48.67), SIMDE_BFLOAT16_VALUE(-21.20), SIMDE_BFLOAT16_VALUE(-45.20) },
       {  SIMDE_BFLOAT16_VALUE(6.72), SIMDE_BFLOAT16_VALUE(10.70), SIMDE_BFLOAT16_VALUE(32.09)},
     { {  SIMDE_BFLOAT16_VALUE(-48.67), SIMDE_BFLOAT16_VALUE(-48.67), SIMDE_BFLOAT16_VALUE(-48.67), SIMDE_BFLOAT16_VALUE(-48.67),
        SIMDE_BFLOAT16_VALUE(-48.67), SIMDE_BFLOAT16_VALUE(-48.67), SIMDE_BFLOAT16_VALUE(-48.67), SIMDE_BFLOAT16_VALUE(-48.67) },
       {  SIMDE_BFLOAT16_VALUE(-21.20), SIMDE_BFLOAT16_VALUE(-21.20), SIMDE_BFLOAT16_VALUE(-21.20), SIMDE_BFLOAT16_VALUE(-21.20),
        SIMDE_BFLOAT16_VALUE(-21.20), SIMDE_BFLOAT16_VALUE(-21.20), SIMDE_BFLOAT16_VALUE(-21.20), SIMDE_BFLOAT16_VALUE(-21.20) },
       {  SIMDE_BFLOAT16_VALUE(-45.20), SIMDE_BFLOAT16_VALUE(-45.20), SIMDE_BFLOAT16_VALUE(-45.20), SIMDE_BFLOAT16_VALUE(-45.20),
        SIMDE_BFLOAT16_VALUE(-45.20), SIMDE_BFLOAT16_VALUE(-45.20), SIMDE_BFLOAT16_VALUE(-45.20), SIMDE_BFLOAT16_VALUE(-45.20) } } },
     { {  SIMDE_BFLOAT16_VALUE(-29.85), SIMDE_BFLOAT16_VALUE(24.77), SIMDE_BFLOAT16_VALUE(7.75) },
       {  SIMDE_BFLOAT16_VALUE(-19.50), SIMDE_BFLOAT16_VALUE(-45.53), SIMDE_BFLOAT16_VALUE(21.67)},
     { {  SIMDE_BFLOAT16_VALUE(-29.85), SIMDE_BFLOAT16_VALUE(-29.85), SIMDE_BFLOAT16_VALUE(-29.85), SIMDE_BFLOAT16_VALUE(-29.85),
        SIMDE_BFLOAT16_VALUE(-29.85), SIMDE_BFLOAT16_VALUE(-29.85), SIMDE_BFLOAT16_VALUE(-29.85), SIMDE_BFLOAT16_VALUE(-29.85) },
       {  SIMDE_BFLOAT16_VALUE(24.77), SIMDE_BFLOAT16_VALUE(24.77), SIMDE_BFLOAT16_VALUE(24.77), SIMDE_BFLOAT16_VALUE(24.77),
        SIMDE_BFLOAT16_VALUE(24.77), SIMDE_BFLOAT16_VALUE(24.77), SIMDE_BFLOAT16_VALUE(24.77), SIMDE_BFLOAT16_VALUE(24.77) },
       {  SIMDE_BFLOAT16_VALUE(7.75), SIMDE_BFLOAT16_VALUE(7.75), SIMDE_BFLOAT16_VALUE(7.75), SIMDE_BFLOAT16_VALUE(7.75),
        SIMDE_BFLOAT16_VALUE(7.75), SIMDE_BFLOAT16_VALUE(7.75), SIMDE_BFLOAT16_VALUE(7.75), SIMDE_BFLOAT16_VALUE(7.75) } } },
     { {  SIMDE_BFLOAT16_VALUE(-4.91), SIMDE_BFLOAT16_VALUE(-25.17), SIMDE_BFLOAT16_VALUE(45.00) },
       {  SIMDE_BFLOAT16_VALUE(2.89), SIMDE_BFLOAT16_VALUE(7.87), SIMDE_BFLOAT16_VALUE(24.69)},
     { {  SIMDE_BFLOAT16_VALUE(-4.91), SIMDE_BFLOAT16_VALUE(-4.91), SIMDE_BFLOAT16_VALUE(-4.91), SIMDE_BFLOAT16_VALUE(-4.91),
        SIMDE_BFLOAT16_VALUE(-4.91), SIMDE_BFLOAT16_VALUE(-4.91), SIMDE_BFLOAT16_VALUE(-4.91), SIMDE_BFLOAT16_VALUE(-4.91) },
       {  SIMDE_BFLOAT16_VALUE(-25.17), SIMDE_BFLOAT16_VALUE(-25.17), SIMDE_BFLOAT16_VALUE(-25.17), SIMDE_BFLOAT16_VALUE(-25.17),
        SIMDE_BFLOAT16_VALUE(-25.17), SIMDE_BFLOAT16_VALUE(-25.17), SIMDE_BFLOAT16_VALUE(-25.17), SIMDE_BFLOAT16_VALUE(-25.17) },
       {  SIMDE_BFLOAT16_VALUE(45.00), SIMDE_BFLOAT16_VALUE(45.00), SIMDE_BFLOAT16_VALUE(45.00), SIMDE_BFLOAT16_VALUE(45.00),
        SIMDE_BFLOAT16_VALUE(45.00), SIMDE_BFLOAT16_VALUE(45.00), SIMDE_BFLOAT16_VALUE(45.00), SIMDE_BFLOAT16_VALUE(45.00) } } },
     { {  SIMDE_BFLOAT16_VALUE(-47.11), SIMDE_BFLOAT16_VALUE(-3.75), SIMDE_BFLOAT16_VALUE(44.40) },
       {  SIMDE_BFLOAT16_VALUE(-8.68), SIMDE_BFLOAT16_VALUE(49.28), SIMDE_BFLOAT16_VALUE(49.67)},
     { {  SIMDE_BFLOAT16_VALUE(-47.11), SIMDE_BFLOAT16_VALUE(-47.11), SIMDE_BFLOAT16_VALUE(-47.11), SIMDE_BFLOAT16_VALUE(-47.11),
        SIMDE_BFLOAT16_VALUE(-47.11), SIMDE_BFLOAT16_VALUE(-47.11), SIMDE_BFLOAT16_VALUE(-47.11), SIMDE_BFLOAT16_VALUE(-47.11) },
       {  SIMDE_BFLOAT16_VALUE(-3.75), SIMDE_BFLOAT16_VALUE(-3.75), SIMDE_BFLOAT16_VALUE(-3.75), SIMDE_BFLOAT16_VALUE(-3.75),
        SIMDE_BFLOAT16_VALUE(-3.75), SIMDE_BFLOAT16_VALUE(-3.75), SIMDE_BFLOAT16_VALUE(-3.75), SIMDE_BFLOAT16_VALUE(-3.75) },
       {  SIMDE_BFLOAT16_VALUE(44.40), SIMDE_BFLOAT16_VALUE(44.40), SIMDE_BFLOAT16_VALUE(44.40), SIMDE_BFLOAT16_VALUE(44.40),
        SIMDE_BFLOAT16_VALUE(44.40), SIMDE_BFLOAT16_VALUE(44.40), SIMDE_BFLOAT16_VALUE(44.40), SIMDE_BFLOAT16_VALUE(44.40) } } },
     { {  SIMDE_BFLOAT16_VALUE(-32.16), SIMDE_BFLOAT16_VALUE(30.51), SIMDE_BFLOAT16_VALUE(15.52) },
       {  SIMDE_BFLOAT16_VALUE(24.82), SIMDE_BFLOAT16_VALUE(34.29), SIMDE_BFLOAT16_VALUE(-0.76)},
     { {  SIMDE_BFLOAT16_VALUE(-32.16), SIMDE_BFLOAT16_VALUE(-32.16), SIMDE_BFLOAT16_VALUE(-32.16), SIMDE_BFLOAT16_VALUE(-32.16),
        SIMDE_BFLOAT16_VALUE(-32.16), SIMDE_BFLOAT16_VALUE(-32.16), SIMDE_BFLOAT16_VALUE(-32.16), SIMDE_BFLOAT16_VALUE(-32.16) },
       {  SIMDE_BFLOAT16_VALUE(30.51), SIMDE_BFLOAT16_VALUE(30.51), SIMDE_BFLOAT16_VALUE(30.51), SIMDE_BFLOAT16_VALUE(30.51),
        SIMDE_BFLOAT16_VALUE(30.51), SIMDE_BFLOAT16_VALUE(30.51), SIMDE_BFLOAT16_VALUE(30.51), SIMDE_BFLOAT16_VALUE(30.51) },
       {  SIMDE_BFLOAT16_VALUE(15.52), SIMDE_BFLOAT16_VALUE(15.52), SIMDE_BFLOAT16_VALUE(15.52), SIMDE_BFLOAT16_VALUE(15.52),
        SIMDE_BFLOAT16_VALUE(15.52), SIMDE_BFLOAT16_VALUE(15.52), SIMDE_BFLOAT16_VALUE(15.52), SIMDE_BFLOAT16_VALUE(15.52) } } },
     { {  SIMDE_BFLOAT16_VALUE(-15.98), SIMDE_BFLOAT16_VALUE(9.92), SIMDE_BFLOAT16_VALUE(-43.38) },
       {  SIMDE_BFLOAT16_VALUE(3.24), SIMDE_BFLOAT16_VALUE(-29.83), SIMDE_BFLOAT16_VALUE(34.76)},
     { {  SIMDE_BFLOAT16_VALUE(-15.98), SIMDE_BFLOAT16_VALUE(-15.98), SIMDE_BFLOAT16_VALUE(-15.98), SIMDE_BFLOAT16_VALUE(-15.98),
        SIMDE_BFLOAT16_VALUE(-15.98), SIMDE_BFLOAT16_VALUE(-15.98), SIMDE_BFLOAT16_VALUE(-15.98), SIMDE_BFLOAT16_VALUE(-15.98) },
       {  SIMDE_BFLOAT16_VALUE(9.92), SIMDE_BFLOAT16_VALUE(9.92), SIMDE_BFLOAT16_VALUE(9.92), SIMDE_BFLOAT16_VALUE(9.92),
        SIMDE_BFLOAT16_VALUE(9.92), SIMDE_BFLOAT16_VALUE(9.92), SIMDE_BFLOAT16_VALUE(9.92), SIMDE_BFLOAT16_VALUE(9.92) },
       {  SIMDE_BFLOAT16_VALUE(-43.38), SIMDE_BFLOAT16_VALUE(-43.38), SIMDE_BFLOAT16_VALUE(-43.38), SIMDE_BFLOAT16_VALUE(-43.38),
        SIMDE_BFLOAT16_VALUE(-43.38), SIMDE_BFLOAT16_VALUE(-43.38), SIMDE_BFLOAT16_VALUE(-43.38), SIMDE_BFLOAT16_VALUE(-43.38) } } },
     { {  SIMDE_BFLOAT16_VALUE(34.74), SIMDE_BFLOAT16_VALUE(3.30), SIMDE_BFLOAT16_VALUE(-43.69) },
       {  SIMDE_BFLOAT16_VALUE(-47.12), SIMDE_BFLOAT16_VALUE(-48.25), SIMDE_BFLOAT16_VALUE(-34.42)},
     { {  SIMDE_BFLOAT16_VALUE(34.74), SIMDE_BFLOAT16_VALUE(34.74), SIMDE_BFLOAT16_VALUE(34.74), SIMDE_BFLOAT16_VALUE(34.74),
        SIMDE_BFLOAT16_VALUE(34.74), SIMDE_BFLOAT16_VALUE(34.74), SIMDE_BFLOAT16_VALUE(34.74), SIMDE_BFLOAT16_VALUE(34.74) },
       {  SIMDE_BFLOAT16_VALUE(3.30), SIMDE_BFLOAT16_VALUE(3.30), SIMDE_BFLOAT16_VALUE(3.30), SIMDE_BFLOAT16_VALUE(3.30),
        SIMDE_BFLOAT16_VALUE(3.30), SIMDE_BFLOAT16_VALUE(3.30), SIMDE_BFLOAT16_VALUE(3.30), SIMDE_BFLOAT16_VALUE(3.30) },
       {  SIMDE_BFLOAT16_VALUE(-43.69), SIMDE_BFLOAT16_VALUE(-43.69), SIMDE_BFLOAT16_VALUE(-43.69), SIMDE_BFLOAT16_VALUE(-43.69),
        SIMDE_BFLOAT16_VALUE(-43.69), SIMDE_BFLOAT16_VALUE(-43.69), SIMDE_BFLOAT16_VALUE(-43.69), SIMDE_BFLOAT16_VALUE(-43.69) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8x3_t r = simde_vld3q_dup_bf16(test_vec[i].a);
    simde_bfloat16x8x3_t expected = {
        {simde_vld1q_bf16(test_vec[i].r[0]), simde_vld1q_bf16(test_vec[i].r[1]), simde_vld1q_bf16(test_vec[i].r[2])}};

    simde_test_arm_neon_assert_equal_bf16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[1], expected.val[1], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[2], expected.val[2], INT_MAX);
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3_dup_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld3q_dup_bf16)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
