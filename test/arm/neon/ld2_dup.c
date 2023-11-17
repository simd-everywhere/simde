#define SIMDE_TEST_ARM_NEON_INSN ld2_dup

#include "test-neon.h"
#include "../../../simde/arm/neon/ld2_dup.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld2_dup_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[2];
    simde_float16_t unused[2];
    simde_float16_t r[2][4];
  } test_vec[] = {
     { {  SIMDE_FLOAT16_VALUE(39.04), SIMDE_FLOAT16_VALUE(10.61) },
       {  SIMDE_FLOAT16_VALUE(-41.47), SIMDE_FLOAT16_VALUE(28.54)},
     { {  SIMDE_FLOAT16_VALUE(39.04), SIMDE_FLOAT16_VALUE(39.04), SIMDE_FLOAT16_VALUE(39.04), SIMDE_FLOAT16_VALUE(39.04) },
       {  SIMDE_FLOAT16_VALUE(10.61), SIMDE_FLOAT16_VALUE(10.61), SIMDE_FLOAT16_VALUE(10.61), SIMDE_FLOAT16_VALUE(10.61) } } },
     { {  SIMDE_FLOAT16_VALUE(-26.09), SIMDE_FLOAT16_VALUE(-32.09) },
       {  SIMDE_FLOAT16_VALUE(-21.60), SIMDE_FLOAT16_VALUE(-5.65)},
     { {  SIMDE_FLOAT16_VALUE(-26.09), SIMDE_FLOAT16_VALUE(-26.09), SIMDE_FLOAT16_VALUE(-26.09), SIMDE_FLOAT16_VALUE(-26.09) },
       {  SIMDE_FLOAT16_VALUE(-32.09), SIMDE_FLOAT16_VALUE(-32.09), SIMDE_FLOAT16_VALUE(-32.09), SIMDE_FLOAT16_VALUE(-32.09) } } },
     { {  SIMDE_FLOAT16_VALUE(27.51), SIMDE_FLOAT16_VALUE(-41.83) },
       {  SIMDE_FLOAT16_VALUE(21.45), SIMDE_FLOAT16_VALUE(9.79)},
     { {  SIMDE_FLOAT16_VALUE(27.51), SIMDE_FLOAT16_VALUE(27.51), SIMDE_FLOAT16_VALUE(27.51), SIMDE_FLOAT16_VALUE(27.51) },
       {  SIMDE_FLOAT16_VALUE(-41.83), SIMDE_FLOAT16_VALUE(-41.83), SIMDE_FLOAT16_VALUE(-41.83), SIMDE_FLOAT16_VALUE(-41.83) } } },
     { {  SIMDE_FLOAT16_VALUE(-19.53), SIMDE_FLOAT16_VALUE(-7.90) },
       {  SIMDE_FLOAT16_VALUE(-3.62), SIMDE_FLOAT16_VALUE(17.75)},
     { {  SIMDE_FLOAT16_VALUE(-19.53), SIMDE_FLOAT16_VALUE(-19.53), SIMDE_FLOAT16_VALUE(-19.53), SIMDE_FLOAT16_VALUE(-19.53) },
       {  SIMDE_FLOAT16_VALUE(-7.90), SIMDE_FLOAT16_VALUE(-7.90), SIMDE_FLOAT16_VALUE(-7.90), SIMDE_FLOAT16_VALUE(-7.90) } } },
     { {  SIMDE_FLOAT16_VALUE(-22.86), SIMDE_FLOAT16_VALUE(5.30) },
       {  SIMDE_FLOAT16_VALUE(-42.71), SIMDE_FLOAT16_VALUE(-2.30)},
     { {  SIMDE_FLOAT16_VALUE(-22.86), SIMDE_FLOAT16_VALUE(-22.86), SIMDE_FLOAT16_VALUE(-22.86), SIMDE_FLOAT16_VALUE(-22.86) },
       {  SIMDE_FLOAT16_VALUE(5.30), SIMDE_FLOAT16_VALUE(5.30), SIMDE_FLOAT16_VALUE(5.30), SIMDE_FLOAT16_VALUE(5.30) } } },
     { {  SIMDE_FLOAT16_VALUE(4.74), SIMDE_FLOAT16_VALUE(43.69) },
       {  SIMDE_FLOAT16_VALUE(-49.64), SIMDE_FLOAT16_VALUE(-29.99)},
     { {  SIMDE_FLOAT16_VALUE(4.74), SIMDE_FLOAT16_VALUE(4.74), SIMDE_FLOAT16_VALUE(4.74), SIMDE_FLOAT16_VALUE(4.74) },
       {  SIMDE_FLOAT16_VALUE(43.69), SIMDE_FLOAT16_VALUE(43.69), SIMDE_FLOAT16_VALUE(43.69), SIMDE_FLOAT16_VALUE(43.69) } } },
     { {  SIMDE_FLOAT16_VALUE(-1.69), SIMDE_FLOAT16_VALUE(-25.30) },
       {  SIMDE_FLOAT16_VALUE(4.77), SIMDE_FLOAT16_VALUE(22.66)},
     { {  SIMDE_FLOAT16_VALUE(-1.69), SIMDE_FLOAT16_VALUE(-1.69), SIMDE_FLOAT16_VALUE(-1.69), SIMDE_FLOAT16_VALUE(-1.69) },
       {  SIMDE_FLOAT16_VALUE(-25.30), SIMDE_FLOAT16_VALUE(-25.30), SIMDE_FLOAT16_VALUE(-25.30), SIMDE_FLOAT16_VALUE(-25.30) } } },
     { {  SIMDE_FLOAT16_VALUE(45.42), SIMDE_FLOAT16_VALUE(-42.46) },
       {  SIMDE_FLOAT16_VALUE(-4.86), SIMDE_FLOAT16_VALUE(42.78)},
     { {  SIMDE_FLOAT16_VALUE(45.42), SIMDE_FLOAT16_VALUE(45.42), SIMDE_FLOAT16_VALUE(45.42), SIMDE_FLOAT16_VALUE(45.42) },
       {  SIMDE_FLOAT16_VALUE(-42.46), SIMDE_FLOAT16_VALUE(-42.46), SIMDE_FLOAT16_VALUE(-42.46), SIMDE_FLOAT16_VALUE(-42.46) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4x2_t r = simde_vld2_dup_f16(test_vec[i].a);
    simde_float16x4x2_t expected = {
        {simde_vld1_f16(test_vec[i].r[0]), simde_vld1_f16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x4(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2_dup_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[2];
    float unused[2];
    float r[2][2];
  } test_vec[] = {
     { {  SIMDE_FLOAT32_C(2307.68), SIMDE_FLOAT32_C(-1583.29) },
       {  SIMDE_FLOAT32_C(2731.95), SIMDE_FLOAT32_C(2210.99)},
     { {  SIMDE_FLOAT32_C(2307.68), SIMDE_FLOAT32_C(2307.68) },
       {  SIMDE_FLOAT32_C(-1583.29), SIMDE_FLOAT32_C(-1583.29) } } },
     { {  SIMDE_FLOAT32_C(2852.12), SIMDE_FLOAT32_C(-4110.41) },
       {  SIMDE_FLOAT32_C(-2600.49), SIMDE_FLOAT32_C(2857.57)},
     { {  SIMDE_FLOAT32_C(2852.12), SIMDE_FLOAT32_C(2852.12) },
       {  SIMDE_FLOAT32_C(-4110.41), SIMDE_FLOAT32_C(-4110.41) } } },
     { {  SIMDE_FLOAT32_C(-3149.95), SIMDE_FLOAT32_C(-4330.61) },
       {  SIMDE_FLOAT32_C(-560.25), SIMDE_FLOAT32_C(-1571.36)},
     { {  SIMDE_FLOAT32_C(-3149.95), SIMDE_FLOAT32_C(-3149.95) },
       {  SIMDE_FLOAT32_C(-4330.61), SIMDE_FLOAT32_C(-4330.61) } } },
     { {  SIMDE_FLOAT32_C(3391.61), SIMDE_FLOAT32_C(1571.53) },
       {  SIMDE_FLOAT32_C(-2233.86), SIMDE_FLOAT32_C(-4968.04)},
     { {  SIMDE_FLOAT32_C(3391.61), SIMDE_FLOAT32_C(3391.61) },
       {  SIMDE_FLOAT32_C(1571.53), SIMDE_FLOAT32_C(1571.53) } } },
     { {  SIMDE_FLOAT32_C(4895.92), SIMDE_FLOAT32_C(507.81) },
       {  SIMDE_FLOAT32_C(-2108.13), SIMDE_FLOAT32_C(-3826.15)},
     { {  SIMDE_FLOAT32_C(4895.92), SIMDE_FLOAT32_C(4895.92) },
       {  SIMDE_FLOAT32_C(507.81), SIMDE_FLOAT32_C(507.81) } } },
     { {  SIMDE_FLOAT32_C(-4259.22), SIMDE_FLOAT32_C(-855.54) },
       {  SIMDE_FLOAT32_C(-377.33), SIMDE_FLOAT32_C(-2791.55)},
     { {  SIMDE_FLOAT32_C(-4259.22), SIMDE_FLOAT32_C(-4259.22) },
       {  SIMDE_FLOAT32_C(-855.54), SIMDE_FLOAT32_C(-855.54) } } },
     { {  SIMDE_FLOAT32_C(1929.17), SIMDE_FLOAT32_C(-2568.21) },
       {  SIMDE_FLOAT32_C(3645.74), SIMDE_FLOAT32_C(4258.92)},
     { {  SIMDE_FLOAT32_C(1929.17), SIMDE_FLOAT32_C(1929.17) },
       {  SIMDE_FLOAT32_C(-2568.21), SIMDE_FLOAT32_C(-2568.21) } } },
     { {  SIMDE_FLOAT32_C(2173.72), SIMDE_FLOAT32_C(-600.35) },
       {  SIMDE_FLOAT32_C(-4586.50), SIMDE_FLOAT32_C(2988.62)},
     { {  SIMDE_FLOAT32_C(2173.72), SIMDE_FLOAT32_C(2173.72) },
       {  SIMDE_FLOAT32_C(-600.35), SIMDE_FLOAT32_C(-600.35) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x2_t r = simde_vld2_dup_f32(test_vec[i].a);
    simde_float32x2x2_t expected = {
        {simde_vld1_f32(test_vec[i].r[0]), simde_vld1_f32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f32x2(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x2(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2_dup_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[2];
    simde_float64 unused[2];
    simde_float64 r[2][1];
  } test_vec[] = {
     { {  SIMDE_FLOAT64_C(21082.19), SIMDE_FLOAT64_C(47343.37) },
       {  SIMDE_FLOAT64_C(49432.61), SIMDE_FLOAT64_C(-21543.65)},
     { {  SIMDE_FLOAT64_C(21082.19) },
       {  SIMDE_FLOAT64_C(47343.37) } } },
     { {  SIMDE_FLOAT64_C(-41608.33), SIMDE_FLOAT64_C(-36883.25) },
       {  SIMDE_FLOAT64_C(30575.24), SIMDE_FLOAT64_C(-12584.71)},
     { {  SIMDE_FLOAT64_C(-41608.33) },
       {  SIMDE_FLOAT64_C(-36883.25) } } },
     { {  SIMDE_FLOAT64_C(49759.50), SIMDE_FLOAT64_C(-5992.61) },
       {  SIMDE_FLOAT64_C(23231.80), SIMDE_FLOAT64_C(24747.06)},
     { {  SIMDE_FLOAT64_C(49759.50) },
       {  SIMDE_FLOAT64_C(-5992.61) } } },
     { {  SIMDE_FLOAT64_C(40497.30), SIMDE_FLOAT64_C(-28566.42) },
       {  SIMDE_FLOAT64_C(43080.67), SIMDE_FLOAT64_C(-27130.92)},
     { {  SIMDE_FLOAT64_C(40497.30) },
       {  SIMDE_FLOAT64_C(-28566.42) } } },
     { {  SIMDE_FLOAT64_C(-18240.39), SIMDE_FLOAT64_C(10269.59) },
       {  SIMDE_FLOAT64_C(11473.99), SIMDE_FLOAT64_C(13282.75)},
     { {  SIMDE_FLOAT64_C(-18240.39) },
       {  SIMDE_FLOAT64_C(10269.59) } } },
     { {  SIMDE_FLOAT64_C(41195.98), SIMDE_FLOAT64_C(-22372.11) },
       {  SIMDE_FLOAT64_C(26718.51), SIMDE_FLOAT64_C(-24527.72)},
     { {  SIMDE_FLOAT64_C(41195.98) },
       {  SIMDE_FLOAT64_C(-22372.11) } } },
     { {  SIMDE_FLOAT64_C(-34223.23), SIMDE_FLOAT64_C(43205.97) },
       {  SIMDE_FLOAT64_C(-125.59), SIMDE_FLOAT64_C(1552.92)},
     { {  SIMDE_FLOAT64_C(-34223.23) },
       {  SIMDE_FLOAT64_C(43205.97) } } },
     { {  SIMDE_FLOAT64_C(-47799.32), SIMDE_FLOAT64_C(8831.04) },
       {  SIMDE_FLOAT64_C(29486.79), SIMDE_FLOAT64_C(36070.91)},
     { {  SIMDE_FLOAT64_C(-47799.32) },
       {  SIMDE_FLOAT64_C(8831.04) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x2_t r = simde_vld2_dup_f64(test_vec[i].a);
    simde_float64x1x2_t expected = {
        {simde_vld1_f64(test_vec[i].r[0]), simde_vld1_f64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f64x1(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x1(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2_dup_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[2];
    int8_t unused[2];
    int8_t r[2][8];
  } test_vec[] = {
     { {  -INT8_C(44), -INT8_C(10) },
       {  INT8_C(11), -INT8_C(46)},
     { {  -INT8_C(44), -INT8_C(44), -INT8_C(44), -INT8_C(44),
        -INT8_C(44), -INT8_C(44), -INT8_C(44), -INT8_C(44) },
       {  -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10),
        -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10) } } },
     { {  -INT8_C(36), INT8_C(0) },
       {  INT8_C(3), INT8_C(7)},
     { {  -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36),
        -INT8_C(36), -INT8_C(36), -INT8_C(36), -INT8_C(36) },
       {  INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0),
        INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0) } } },
     { {  INT8_C(41), -INT8_C(47) },
       {  INT8_C(1), -INT8_C(40)},
     { {  INT8_C(41), INT8_C(41), INT8_C(41), INT8_C(41),
        INT8_C(41), INT8_C(41), INT8_C(41), INT8_C(41) },
       {  -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47),
        -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47) } } },
     { {  INT8_C(40), -INT8_C(26) },
       {  -INT8_C(40), INT8_C(1)},
     { {  INT8_C(40), INT8_C(40), INT8_C(40), INT8_C(40),
        INT8_C(40), INT8_C(40), INT8_C(40), INT8_C(40) },
       {  -INT8_C(26), -INT8_C(26), -INT8_C(26), -INT8_C(26),
        -INT8_C(26), -INT8_C(26), -INT8_C(26), -INT8_C(26) } } },
     { {  INT8_C(27), -INT8_C(41) },
       {  -INT8_C(12), -INT8_C(34)},
     { {  INT8_C(27), INT8_C(27), INT8_C(27), INT8_C(27),
        INT8_C(27), INT8_C(27), INT8_C(27), INT8_C(27) },
       {  -INT8_C(41), -INT8_C(41), -INT8_C(41), -INT8_C(41),
        -INT8_C(41), -INT8_C(41), -INT8_C(41), -INT8_C(41) } } },
     { {  INT8_C(0), INT8_C(10) },
       {  -INT8_C(17), INT8_C(42)},
     { {  INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0),
        INT8_C(0), INT8_C(0), INT8_C(0), INT8_C(0) },
       {  INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10),
        INT8_C(10), INT8_C(10), INT8_C(10), INT8_C(10) } } },
     { {  -INT8_C(31), -INT8_C(20) },
       {  -INT8_C(18), -INT8_C(32)},
     { {  -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31),
        -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31) },
       {  -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20),
        -INT8_C(20), -INT8_C(20), -INT8_C(20), -INT8_C(20) } } },
     { {  INT8_C(14), -INT8_C(5) },
       {  -INT8_C(17), INT8_C(17)},
     { {  INT8_C(14), INT8_C(14), INT8_C(14), INT8_C(14),
        INT8_C(14), INT8_C(14), INT8_C(14), INT8_C(14) },
       {  -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5),
        -INT8_C(5), -INT8_C(5), -INT8_C(5), -INT8_C(5) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x2_t r = simde_vld2_dup_s8(test_vec[i].a);
    simde_int8x8x2_t expected = {
        {simde_vld1_s8(test_vec[i].r[0]), simde_vld1_s8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_dup_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[2];
    int16_t unused[2];
    int16_t r[2][4];
  } test_vec[] = {
     { {  -INT16_C(4410), INT16_C(4292) },
       {  INT16_C(4011), -INT16_C(684)},
     { {  -INT16_C(4410), -INT16_C(4410), -INT16_C(4410), -INT16_C(4410) },
       {  INT16_C(4292), INT16_C(4292), INT16_C(4292), INT16_C(4292) } } },
     { {  -INT16_C(385), INT16_C(937) },
       {  -INT16_C(2080), -INT16_C(604)},
     { {  -INT16_C(385), -INT16_C(385), -INT16_C(385), -INT16_C(385) },
       {  INT16_C(937), INT16_C(937), INT16_C(937), INT16_C(937) } } },
     { {  INT16_C(1583), -INT16_C(4297) },
       {  -INT16_C(444), INT16_C(2137)},
     { {  INT16_C(1583), INT16_C(1583), INT16_C(1583), INT16_C(1583) },
       {  -INT16_C(4297), -INT16_C(4297), -INT16_C(4297), -INT16_C(4297) } } },
     { {  INT16_C(851), INT16_C(2552) },
       {  INT16_C(729), -INT16_C(3035)},
     { {  INT16_C(851), INT16_C(851), INT16_C(851), INT16_C(851) },
       {  INT16_C(2552), INT16_C(2552), INT16_C(2552), INT16_C(2552) } } },
     { {  INT16_C(4380), -INT16_C(3253) },
       {  -INT16_C(1679), INT16_C(1203)},
     { {  INT16_C(4380), INT16_C(4380), INT16_C(4380), INT16_C(4380) },
       {  -INT16_C(3253), -INT16_C(3253), -INT16_C(3253), -INT16_C(3253) } } },
     { {  -INT16_C(524), -INT16_C(21) },
       {  INT16_C(797), INT16_C(255)},
     { {  -INT16_C(524), -INT16_C(524), -INT16_C(524), -INT16_C(524) },
       {  -INT16_C(21), -INT16_C(21), -INT16_C(21), -INT16_C(21) } } },
     { {  -INT16_C(186), -INT16_C(581) },
       {  -INT16_C(3301), -INT16_C(4925)},
     { {  -INT16_C(186), -INT16_C(186), -INT16_C(186), -INT16_C(186) },
       {  -INT16_C(581), -INT16_C(581), -INT16_C(581), -INT16_C(581) } } },
     { {  -INT16_C(1648), INT16_C(2898) },
       {  -INT16_C(2578), INT16_C(2614)},
     { {  -INT16_C(1648), -INT16_C(1648), -INT16_C(1648), -INT16_C(1648) },
       {  INT16_C(2898), INT16_C(2898), INT16_C(2898), INT16_C(2898) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x2_t r = simde_vld2_dup_s16(test_vec[i].a);
    simde_int16x4x2_t expected = {
        {simde_vld1_s16(test_vec[i].r[0]), simde_vld1_s16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_dup_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t unused[2];
    int32_t r[2][2];
  } test_vec[] = {
     { {  -INT32_C(423975), INT32_C(232951) },
       {  INT32_C(10395), INT32_C(421653)},
     { {  -INT32_C(423975), -INT32_C(423975) },
       {  INT32_C(232951), INT32_C(232951) } } },
     { {  -INT32_C(145011), -INT32_C(212273) },
       {  INT32_C(183013), INT32_C(475303)},
     { {  -INT32_C(145011), -INT32_C(145011) },
       {  -INT32_C(212273), -INT32_C(212273) } } },
     { {  INT32_C(58903), -INT32_C(376587) },
       {  INT32_C(139539), INT32_C(95681)},
     { {  INT32_C(58903), INT32_C(58903) },
       {  -INT32_C(376587), -INT32_C(376587) } } },
     { {  -INT32_C(192673), INT32_C(65349) },
       {  INT32_C(165140), INT32_C(318086)},
     { {  -INT32_C(192673), -INT32_C(192673) },
       {  INT32_C(65349), INT32_C(65349) } } },
     { {  INT32_C(233617), INT32_C(369077) },
       {  INT32_C(447975), INT32_C(362104)},
     { {  INT32_C(233617), INT32_C(233617) },
       {  INT32_C(369077), INT32_C(369077) } } },
     { {  -INT32_C(293844), INT32_C(124382) },
       {  -INT32_C(131540), -INT32_C(38739)},
     { {  -INT32_C(293844), -INT32_C(293844) },
       {  INT32_C(124382), INT32_C(124382) } } },
     { {  -INT32_C(198129), -INT32_C(404701) },
       {  INT32_C(277076), -INT32_C(95884)},
     { {  -INT32_C(198129), -INT32_C(198129) },
       {  -INT32_C(404701), -INT32_C(404701) } } },
     { {  -INT32_C(79259), -INT32_C(145497) },
       {  -INT32_C(286896), INT32_C(459476)},
     { {  -INT32_C(79259), -INT32_C(79259) },
       {  -INT32_C(145497), -INT32_C(145497) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x2_t r = simde_vld2_dup_s32(test_vec[i].a);
    simde_int32x2x2_t expected = {
        {simde_vld1_s32(test_vec[i].r[0]), simde_vld1_s32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_dup_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int64_t unused[2];
    int64_t r[2][1];
  } test_vec[] = {
     { {  -INT64_C(16075735), -INT64_C(41986772) },
       {  INT64_C(1992980), -INT64_C(18040045)},
     { {  -INT64_C(16075735) },
       {  -INT64_C(41986772) } } },
     { {  INT64_C(45666736), INT64_C(14603987) },
       {  INT64_C(5576751), -INT64_C(32015067)},
     { {  INT64_C(45666736) },
       {  INT64_C(14603987) } } },
     { {  INT64_C(22903463), -INT64_C(26683670) },
       {  INT64_C(31335237), -INT64_C(35045895)},
     { {  INT64_C(22903463) },
       {  -INT64_C(26683670) } } },
     { {  -INT64_C(2725423), INT64_C(14936754) },
       {  -INT64_C(15271657), -INT64_C(33623481)},
     { {  -INT64_C(2725423) },
       {  INT64_C(14936754) } } },
     { {  -INT64_C(41889667), -INT64_C(48507508) },
       {  -INT64_C(40708285), INT64_C(19288415)},
     { {  -INT64_C(41889667) },
       {  -INT64_C(48507508) } } },
     { {  -INT64_C(45608478), INT64_C(30343871) },
       {  INT64_C(46346252), -INT64_C(2149923)},
     { {  -INT64_C(45608478) },
       {  INT64_C(30343871) } } },
     { {  INT64_C(17093091), -INT64_C(49483236) },
       {  -INT64_C(13243908), -INT64_C(37644879)},
     { {  INT64_C(17093091) },
       {  -INT64_C(49483236) } } },
     { {  -INT64_C(9604042), INT64_C(42837322) },
       {  -INT64_C(47932845), INT64_C(29714084)},
     { {  -INT64_C(9604042) },
       {  INT64_C(42837322) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x2_t r = simde_vld2_dup_s64(test_vec[i].a);
    simde_int64x1x2_t expected = {
        {simde_vld1_s64(test_vec[i].r[0]), simde_vld1_s64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_dup_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a[2];
    uint8_t unused[2];
    uint8_t r[2][8];
  } test_vec[] = {
     { {  UINT8_C(94), UINT8_C(65) },
       {  UINT8_C(68), UINT8_C(15)},
     { {  UINT8_C(94), UINT8_C(94), UINT8_C(94), UINT8_C(94),
        UINT8_C(94), UINT8_C(94), UINT8_C(94), UINT8_C(94) },
       {  UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65),
        UINT8_C(65), UINT8_C(65), UINT8_C(65), UINT8_C(65) } } },
     { {  UINT8_C(89), UINT8_C(88) },
       {  UINT8_C(87), UINT8_C(56)},
     { {  UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89),
        UINT8_C(89), UINT8_C(89), UINT8_C(89), UINT8_C(89) },
       {  UINT8_C(88), UINT8_C(88), UINT8_C(88), UINT8_C(88),
        UINT8_C(88), UINT8_C(88), UINT8_C(88), UINT8_C(88) } } },
     { {  UINT8_C(28), UINT8_C(34) },
       {  UINT8_C(99), UINT8_C(65)},
     { {  UINT8_C(28), UINT8_C(28), UINT8_C(28), UINT8_C(28),
        UINT8_C(28), UINT8_C(28), UINT8_C(28), UINT8_C(28) },
       {  UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34),
        UINT8_C(34), UINT8_C(34), UINT8_C(34), UINT8_C(34) } } },
     { {  UINT8_C(44), UINT8_C(68) },
       {  UINT8_C(10), UINT8_C(26)},
     { {  UINT8_C(44), UINT8_C(44), UINT8_C(44), UINT8_C(44),
        UINT8_C(44), UINT8_C(44), UINT8_C(44), UINT8_C(44) },
       {  UINT8_C(68), UINT8_C(68), UINT8_C(68), UINT8_C(68),
        UINT8_C(68), UINT8_C(68), UINT8_C(68), UINT8_C(68) } } },
     { {  UINT8_C(47), UINT8_C(62) },
       {  UINT8_C(86), UINT8_C(81)},
     { {  UINT8_C(47), UINT8_C(47), UINT8_C(47), UINT8_C(47),
        UINT8_C(47), UINT8_C(47), UINT8_C(47), UINT8_C(47) },
       {  UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62),
        UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62) } } },
     { {  UINT8_C(53), UINT8_C(60) },
       {  UINT8_C(43), UINT8_C(84)},
     { {  UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53),
        UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53) },
       {  UINT8_C(60), UINT8_C(60), UINT8_C(60), UINT8_C(60),
        UINT8_C(60), UINT8_C(60), UINT8_C(60), UINT8_C(60) } } },
     { {  UINT8_C(15), UINT8_C(10) },
       {  UINT8_C(26), UINT8_C(7)},
     { {  UINT8_C(15), UINT8_C(15), UINT8_C(15), UINT8_C(15),
        UINT8_C(15), UINT8_C(15), UINT8_C(15), UINT8_C(15) },
       {  UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10),
        UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10) } } },
     { {  UINT8_C(64), UINT8_C(33) },
       {  UINT8_C(81), UINT8_C(53)},
     { {  UINT8_C(64), UINT8_C(64), UINT8_C(64), UINT8_C(64),
        UINT8_C(64), UINT8_C(64), UINT8_C(64), UINT8_C(64) },
       {  UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33),
        UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x2_t r = simde_vld2_dup_u8(test_vec[i].a);
    simde_uint8x8x2_t expected = {
        {simde_vld1_u8(test_vec[i].r[0]), simde_vld1_u8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_dup_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[2];
    uint16_t unused[2];
    uint16_t r[2][4];
  } test_vec[] = {
     { {  UINT16_C(7277), UINT16_C(6201) },
       {  UINT16_C(9680), UINT16_C(3544)},
     { {  UINT16_C(7277), UINT16_C(7277), UINT16_C(7277), UINT16_C(7277) },
       {  UINT16_C(6201), UINT16_C(6201), UINT16_C(6201), UINT16_C(6201) } } },
     { {  UINT16_C(2944), UINT16_C(5592) },
       {  UINT16_C(9662), UINT16_C(4267)},
     { {  UINT16_C(2944), UINT16_C(2944), UINT16_C(2944), UINT16_C(2944) },
       {  UINT16_C(5592), UINT16_C(5592), UINT16_C(5592), UINT16_C(5592) } } },
     { {  UINT16_C(8742), UINT16_C(6060) },
       {  UINT16_C(3824), UINT16_C(2303)},
     { {  UINT16_C(8742), UINT16_C(8742), UINT16_C(8742), UINT16_C(8742) },
       {  UINT16_C(6060), UINT16_C(6060), UINT16_C(6060), UINT16_C(6060) } } },
     { {  UINT16_C(9964), UINT16_C(5944) },
       {  UINT16_C(4767), UINT16_C(7055)},
     { {  UINT16_C(9964), UINT16_C(9964), UINT16_C(9964), UINT16_C(9964) },
       {  UINT16_C(5944), UINT16_C(5944), UINT16_C(5944), UINT16_C(5944) } } },
     { {  UINT16_C(6764), UINT16_C(915) },
       {  UINT16_C(2455), UINT16_C(4422)},
     { {  UINT16_C(6764), UINT16_C(6764), UINT16_C(6764), UINT16_C(6764) },
       {  UINT16_C(915), UINT16_C(915), UINT16_C(915), UINT16_C(915) } } },
     { {  UINT16_C(3051), UINT16_C(2687) },
       {  UINT16_C(3858), UINT16_C(7628)},
     { {  UINT16_C(3051), UINT16_C(3051), UINT16_C(3051), UINT16_C(3051) },
       {  UINT16_C(2687), UINT16_C(2687), UINT16_C(2687), UINT16_C(2687) } } },
     { {  UINT16_C(2343), UINT16_C(2688) },
       {  UINT16_C(3196), UINT16_C(4003)},
     { {  UINT16_C(2343), UINT16_C(2343), UINT16_C(2343), UINT16_C(2343) },
       {  UINT16_C(2688), UINT16_C(2688), UINT16_C(2688), UINT16_C(2688) } } },
     { {  UINT16_C(6885), UINT16_C(4075) },
       {  UINT16_C(1096), UINT16_C(2437)},
     { {  UINT16_C(6885), UINT16_C(6885), UINT16_C(6885), UINT16_C(6885) },
       {  UINT16_C(4075), UINT16_C(4075), UINT16_C(4075), UINT16_C(4075) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x2_t r = simde_vld2_dup_u16(test_vec[i].a);
    simde_uint16x4x2_t expected = {
        {simde_vld1_u16(test_vec[i].r[0]), simde_vld1_u16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_dup_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[2];
    uint32_t unused[2];
    uint32_t r[2][2];
  } test_vec[] = {
     { {  UINT32_C(8806364), UINT32_C(5747175) },
       {  UINT32_C(62640), UINT32_C(51477)},
     { {  UINT32_C(8806364), UINT32_C(8806364) },
       {  UINT32_C(5747175), UINT32_C(5747175) } } },
     { {  UINT32_C(6190067), UINT32_C(9926025) },
       {  UINT32_C(5527107), UINT32_C(2621754)},
     { {  UINT32_C(6190067), UINT32_C(6190067) },
       {  UINT32_C(9926025), UINT32_C(9926025) } } },
     { {  UINT32_C(7713063), UINT32_C(1058099) },
       {  UINT32_C(5449836), UINT32_C(7469060)},
     { {  UINT32_C(7713063), UINT32_C(7713063) },
       {  UINT32_C(1058099), UINT32_C(1058099) } } },
     { {  UINT32_C(9037710), UINT32_C(8162655) },
       {  UINT32_C(6515501), UINT32_C(8695502)},
     { {  UINT32_C(9037710), UINT32_C(9037710) },
       {  UINT32_C(8162655), UINT32_C(8162655) } } },
     { {  UINT32_C(3473717), UINT32_C(4274463) },
       {  UINT32_C(2777529), UINT32_C(4443635)},
     { {  UINT32_C(3473717), UINT32_C(3473717) },
       {  UINT32_C(4274463), UINT32_C(4274463) } } },
     { {  UINT32_C(2223044), UINT32_C(6511474) },
       {  UINT32_C(2931518), UINT32_C(3607081)},
     { {  UINT32_C(2223044), UINT32_C(2223044) },
       {  UINT32_C(6511474), UINT32_C(6511474) } } },
     { {  UINT32_C(2577872), UINT32_C(6180197) },
       {  UINT32_C(9858974), UINT32_C(1298189)},
     { {  UINT32_C(2577872), UINT32_C(2577872) },
       {  UINT32_C(6180197), UINT32_C(6180197) } } },
     { {  UINT32_C(3511221), UINT32_C(9972720) },
       {  UINT32_C(4216133), UINT32_C(7465157)},
     { {  UINT32_C(3511221), UINT32_C(3511221) },
       {  UINT32_C(9972720), UINT32_C(9972720) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x2_t r = simde_vld2_dup_u32(test_vec[i].a);
    simde_uint32x2x2_t expected = {
        {simde_vld1_u32(test_vec[i].r[0]), simde_vld1_u32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_dup_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[2];
    uint64_t unused[2];
    uint64_t r[2][1];
  } test_vec[] = {
     { {  UINT64_C(406306774), UINT64_C(832079054) },
       {  UINT64_C(942691710), UINT64_C(590244517)},
     { {  UINT64_C(406306774) },
       {  UINT64_C(832079054) } } },
     { {  UINT64_C(209815625), UINT64_C(142491912) },
       {  UINT64_C(346572474), UINT64_C(762924904)},
     { {  UINT64_C(209815625) },
       {  UINT64_C(142491912) } } },
     { {  UINT64_C(329793009), UINT64_C(224060866) },
       {  UINT64_C(648830943), UINT64_C(251128938)},
     { {  UINT64_C(329793009) },
       {  UINT64_C(224060866) } } },
     { {  UINT64_C(353732428), UINT64_C(38041495) },
       {  UINT64_C(142075049), UINT64_C(500056775)},
     { {  UINT64_C(353732428) },
       {  UINT64_C(38041495) } } },
     { {  UINT64_C(396112989), UINT64_C(999174752) },
       {  UINT64_C(69563384), UINT64_C(343798648)},
     { {  UINT64_C(396112989) },
       {  UINT64_C(999174752) } } },
     { {  UINT64_C(321475295), UINT64_C(362221548) },
       {  UINT64_C(851265818), UINT64_C(259349005)},
     { {  UINT64_C(321475295) },
       {  UINT64_C(362221548) } } },
     { {  UINT64_C(424982958), UINT64_C(188017536) },
       {  UINT64_C(162916083), UINT64_C(282151345)},
     { {  UINT64_C(424982958) },
       {  UINT64_C(188017536) } } },
     { {  UINT64_C(49743777), UINT64_C(694072886) },
       {  UINT64_C(998695309), UINT64_C(891182183)},
     { {  UINT64_C(49743777) },
       {  UINT64_C(694072886) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x2_t r = simde_vld2_dup_u64(test_vec[i].a);
    simde_uint64x1x2_t expected = {
        {simde_vld1_u64(test_vec[i].r[0]), simde_vld1_u64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_dup_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[2];
    simde_float16_t unused[2];
    simde_float16_t r[2][8];
  } test_vec[] = {
     { {  SIMDE_FLOAT16_VALUE(44.20), SIMDE_FLOAT16_VALUE(24.16) },
       {  SIMDE_FLOAT16_VALUE(-44.99), SIMDE_FLOAT16_VALUE(0.06)},
     { {  SIMDE_FLOAT16_VALUE(44.20), SIMDE_FLOAT16_VALUE(44.20), SIMDE_FLOAT16_VALUE(44.20), SIMDE_FLOAT16_VALUE(44.20),
        SIMDE_FLOAT16_VALUE(44.20), SIMDE_FLOAT16_VALUE(44.20), SIMDE_FLOAT16_VALUE(44.20), SIMDE_FLOAT16_VALUE(44.20) },
       {  SIMDE_FLOAT16_VALUE(24.16), SIMDE_FLOAT16_VALUE(24.16), SIMDE_FLOAT16_VALUE(24.16), SIMDE_FLOAT16_VALUE(24.16),
        SIMDE_FLOAT16_VALUE(24.16), SIMDE_FLOAT16_VALUE(24.16), SIMDE_FLOAT16_VALUE(24.16), SIMDE_FLOAT16_VALUE(24.16) } } },
     { {  SIMDE_FLOAT16_VALUE(49.42), SIMDE_FLOAT16_VALUE(2.99) },
       {  SIMDE_FLOAT16_VALUE(-44.29), SIMDE_FLOAT16_VALUE(-47.80)},
     { {  SIMDE_FLOAT16_VALUE(49.42), SIMDE_FLOAT16_VALUE(49.42), SIMDE_FLOAT16_VALUE(49.42), SIMDE_FLOAT16_VALUE(49.42),
        SIMDE_FLOAT16_VALUE(49.42), SIMDE_FLOAT16_VALUE(49.42), SIMDE_FLOAT16_VALUE(49.42), SIMDE_FLOAT16_VALUE(49.42) },
       {  SIMDE_FLOAT16_VALUE(2.99), SIMDE_FLOAT16_VALUE(2.99), SIMDE_FLOAT16_VALUE(2.99), SIMDE_FLOAT16_VALUE(2.99),
        SIMDE_FLOAT16_VALUE(2.99), SIMDE_FLOAT16_VALUE(2.99), SIMDE_FLOAT16_VALUE(2.99), SIMDE_FLOAT16_VALUE(2.99) } } },
     { {  SIMDE_FLOAT16_VALUE(-4.29), SIMDE_FLOAT16_VALUE(-21.75) },
       {  SIMDE_FLOAT16_VALUE(18.84), SIMDE_FLOAT16_VALUE(47.44)},
     { {  SIMDE_FLOAT16_VALUE(-4.29), SIMDE_FLOAT16_VALUE(-4.29), SIMDE_FLOAT16_VALUE(-4.29), SIMDE_FLOAT16_VALUE(-4.29),
        SIMDE_FLOAT16_VALUE(-4.29), SIMDE_FLOAT16_VALUE(-4.29), SIMDE_FLOAT16_VALUE(-4.29), SIMDE_FLOAT16_VALUE(-4.29) },
       {  SIMDE_FLOAT16_VALUE(-21.75), SIMDE_FLOAT16_VALUE(-21.75), SIMDE_FLOAT16_VALUE(-21.75), SIMDE_FLOAT16_VALUE(-21.75),
        SIMDE_FLOAT16_VALUE(-21.75), SIMDE_FLOAT16_VALUE(-21.75), SIMDE_FLOAT16_VALUE(-21.75), SIMDE_FLOAT16_VALUE(-21.75) } } },
     { {  SIMDE_FLOAT16_VALUE(14.92), SIMDE_FLOAT16_VALUE(32.44) },
       {  SIMDE_FLOAT16_VALUE(32.42), SIMDE_FLOAT16_VALUE(-11.78)},
     { {  SIMDE_FLOAT16_VALUE(14.92), SIMDE_FLOAT16_VALUE(14.92), SIMDE_FLOAT16_VALUE(14.92), SIMDE_FLOAT16_VALUE(14.92),
        SIMDE_FLOAT16_VALUE(14.92), SIMDE_FLOAT16_VALUE(14.92), SIMDE_FLOAT16_VALUE(14.92), SIMDE_FLOAT16_VALUE(14.92) },
       {  SIMDE_FLOAT16_VALUE(32.44), SIMDE_FLOAT16_VALUE(32.44), SIMDE_FLOAT16_VALUE(32.44), SIMDE_FLOAT16_VALUE(32.44),
        SIMDE_FLOAT16_VALUE(32.44), SIMDE_FLOAT16_VALUE(32.44), SIMDE_FLOAT16_VALUE(32.44), SIMDE_FLOAT16_VALUE(32.44) } } },
     { {  SIMDE_FLOAT16_VALUE(-15.04), SIMDE_FLOAT16_VALUE(-22.71) },
       {  SIMDE_FLOAT16_VALUE(21.86), SIMDE_FLOAT16_VALUE(-1.79)},
     { {  SIMDE_FLOAT16_VALUE(-15.04), SIMDE_FLOAT16_VALUE(-15.04), SIMDE_FLOAT16_VALUE(-15.04), SIMDE_FLOAT16_VALUE(-15.04),
        SIMDE_FLOAT16_VALUE(-15.04), SIMDE_FLOAT16_VALUE(-15.04), SIMDE_FLOAT16_VALUE(-15.04), SIMDE_FLOAT16_VALUE(-15.04) },
       {  SIMDE_FLOAT16_VALUE(-22.71), SIMDE_FLOAT16_VALUE(-22.71), SIMDE_FLOAT16_VALUE(-22.71), SIMDE_FLOAT16_VALUE(-22.71),
        SIMDE_FLOAT16_VALUE(-22.71), SIMDE_FLOAT16_VALUE(-22.71), SIMDE_FLOAT16_VALUE(-22.71), SIMDE_FLOAT16_VALUE(-22.71) } } },
     { {  SIMDE_FLOAT16_VALUE(2.97), SIMDE_FLOAT16_VALUE(23.53) },
       {  SIMDE_FLOAT16_VALUE(-46.16), SIMDE_FLOAT16_VALUE(23.15)},
     { {  SIMDE_FLOAT16_VALUE(2.97), SIMDE_FLOAT16_VALUE(2.97), SIMDE_FLOAT16_VALUE(2.97), SIMDE_FLOAT16_VALUE(2.97),
        SIMDE_FLOAT16_VALUE(2.97), SIMDE_FLOAT16_VALUE(2.97), SIMDE_FLOAT16_VALUE(2.97), SIMDE_FLOAT16_VALUE(2.97) },
       {  SIMDE_FLOAT16_VALUE(23.53), SIMDE_FLOAT16_VALUE(23.53), SIMDE_FLOAT16_VALUE(23.53), SIMDE_FLOAT16_VALUE(23.53),
        SIMDE_FLOAT16_VALUE(23.53), SIMDE_FLOAT16_VALUE(23.53), SIMDE_FLOAT16_VALUE(23.53), SIMDE_FLOAT16_VALUE(23.53) } } },
     { {  SIMDE_FLOAT16_VALUE(9.52), SIMDE_FLOAT16_VALUE(-32.92) },
       {  SIMDE_FLOAT16_VALUE(24.32), SIMDE_FLOAT16_VALUE(39.39)},
     { {  SIMDE_FLOAT16_VALUE(9.52), SIMDE_FLOAT16_VALUE(9.52), SIMDE_FLOAT16_VALUE(9.52), SIMDE_FLOAT16_VALUE(9.52),
        SIMDE_FLOAT16_VALUE(9.52), SIMDE_FLOAT16_VALUE(9.52), SIMDE_FLOAT16_VALUE(9.52), SIMDE_FLOAT16_VALUE(9.52) },
       {  SIMDE_FLOAT16_VALUE(-32.92), SIMDE_FLOAT16_VALUE(-32.92), SIMDE_FLOAT16_VALUE(-32.92), SIMDE_FLOAT16_VALUE(-32.92),
        SIMDE_FLOAT16_VALUE(-32.92), SIMDE_FLOAT16_VALUE(-32.92), SIMDE_FLOAT16_VALUE(-32.92), SIMDE_FLOAT16_VALUE(-32.92) } } },
     { {  SIMDE_FLOAT16_VALUE(-26.46), SIMDE_FLOAT16_VALUE(24.31) },
       {  SIMDE_FLOAT16_VALUE(14.82), SIMDE_FLOAT16_VALUE(-40.92)},
     { {  SIMDE_FLOAT16_VALUE(-26.46), SIMDE_FLOAT16_VALUE(-26.46), SIMDE_FLOAT16_VALUE(-26.46), SIMDE_FLOAT16_VALUE(-26.46),
        SIMDE_FLOAT16_VALUE(-26.46), SIMDE_FLOAT16_VALUE(-26.46), SIMDE_FLOAT16_VALUE(-26.46), SIMDE_FLOAT16_VALUE(-26.46) },
       {  SIMDE_FLOAT16_VALUE(24.31), SIMDE_FLOAT16_VALUE(24.31), SIMDE_FLOAT16_VALUE(24.31), SIMDE_FLOAT16_VALUE(24.31),
        SIMDE_FLOAT16_VALUE(24.31), SIMDE_FLOAT16_VALUE(24.31), SIMDE_FLOAT16_VALUE(24.31), SIMDE_FLOAT16_VALUE(24.31) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8x2_t r = simde_vld2q_dup_f16(test_vec[i].a);
    simde_float16x8x2_t expected = {
        {simde_vld1q_f16(test_vec[i].r[0]), simde_vld1q_f16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f16x8(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2q_dup_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    float a[2];
    float unused[2];
    float r[2][4];
  } test_vec[] = {
     { {  SIMDE_FLOAT32_C(-36.86), SIMDE_FLOAT32_C(-3235.75) },
       {  SIMDE_FLOAT32_C(-1620.77), SIMDE_FLOAT32_C(-2598.23)},
     { {  SIMDE_FLOAT32_C(-36.86), SIMDE_FLOAT32_C(-36.86), SIMDE_FLOAT32_C(-36.86), SIMDE_FLOAT32_C(-36.86) },
       {  SIMDE_FLOAT32_C(-3235.75), SIMDE_FLOAT32_C(-3235.75), SIMDE_FLOAT32_C(-3235.75), SIMDE_FLOAT32_C(-3235.75) } } },
     { {  SIMDE_FLOAT32_C(-22.58), SIMDE_FLOAT32_C(-1940.17) },
       {  SIMDE_FLOAT32_C(404.34), SIMDE_FLOAT32_C(2212.34)},
     { {  SIMDE_FLOAT32_C(-22.58), SIMDE_FLOAT32_C(-22.58), SIMDE_FLOAT32_C(-22.58), SIMDE_FLOAT32_C(-22.58) },
       {  SIMDE_FLOAT32_C(-1940.17), SIMDE_FLOAT32_C(-1940.17), SIMDE_FLOAT32_C(-1940.17), SIMDE_FLOAT32_C(-1940.17) } } },
     { {  SIMDE_FLOAT32_C(1792.73), SIMDE_FLOAT32_C(3138.56) },
       {  SIMDE_FLOAT32_C(-468.64), SIMDE_FLOAT32_C(-4526.15)},
     { {  SIMDE_FLOAT32_C(1792.73), SIMDE_FLOAT32_C(1792.73), SIMDE_FLOAT32_C(1792.73), SIMDE_FLOAT32_C(1792.73) },
       {  SIMDE_FLOAT32_C(3138.56), SIMDE_FLOAT32_C(3138.56), SIMDE_FLOAT32_C(3138.56), SIMDE_FLOAT32_C(3138.56) } } },
     { {  SIMDE_FLOAT32_C(1849.53), SIMDE_FLOAT32_C(-3910.03) },
       {  SIMDE_FLOAT32_C(-4396.76), SIMDE_FLOAT32_C(-3095.12)},
     { {  SIMDE_FLOAT32_C(1849.53), SIMDE_FLOAT32_C(1849.53), SIMDE_FLOAT32_C(1849.53), SIMDE_FLOAT32_C(1849.53) },
       {  SIMDE_FLOAT32_C(-3910.03), SIMDE_FLOAT32_C(-3910.03), SIMDE_FLOAT32_C(-3910.03), SIMDE_FLOAT32_C(-3910.03) } } },
     { {  SIMDE_FLOAT32_C(1942.57), SIMDE_FLOAT32_C(-2284.97) },
       {  SIMDE_FLOAT32_C(2327.82), SIMDE_FLOAT32_C(700.88)},
     { {  SIMDE_FLOAT32_C(1942.57), SIMDE_FLOAT32_C(1942.57), SIMDE_FLOAT32_C(1942.57), SIMDE_FLOAT32_C(1942.57) },
       {  SIMDE_FLOAT32_C(-2284.97), SIMDE_FLOAT32_C(-2284.97), SIMDE_FLOAT32_C(-2284.97), SIMDE_FLOAT32_C(-2284.97) } } },
     { {  SIMDE_FLOAT32_C(2044.12), SIMDE_FLOAT32_C(636.75) },
       {  SIMDE_FLOAT32_C(1647.09), SIMDE_FLOAT32_C(105.34)},
     { {  SIMDE_FLOAT32_C(2044.12), SIMDE_FLOAT32_C(2044.12), SIMDE_FLOAT32_C(2044.12), SIMDE_FLOAT32_C(2044.12) },
       {  SIMDE_FLOAT32_C(636.75), SIMDE_FLOAT32_C(636.75), SIMDE_FLOAT32_C(636.75), SIMDE_FLOAT32_C(636.75) } } },
     { {  SIMDE_FLOAT32_C(4347.49), SIMDE_FLOAT32_C(1671.95) },
       {  SIMDE_FLOAT32_C(-2453.27), SIMDE_FLOAT32_C(-3619.39)},
     { {  SIMDE_FLOAT32_C(4347.49), SIMDE_FLOAT32_C(4347.49), SIMDE_FLOAT32_C(4347.49), SIMDE_FLOAT32_C(4347.49) },
       {  SIMDE_FLOAT32_C(1671.95), SIMDE_FLOAT32_C(1671.95), SIMDE_FLOAT32_C(1671.95), SIMDE_FLOAT32_C(1671.95) } } },
     { {  SIMDE_FLOAT32_C(-4696.01), SIMDE_FLOAT32_C(2725.12) },
       {  SIMDE_FLOAT32_C(4041.30), SIMDE_FLOAT32_C(3596.24)},
     { {  SIMDE_FLOAT32_C(-4696.01), SIMDE_FLOAT32_C(-4696.01), SIMDE_FLOAT32_C(-4696.01), SIMDE_FLOAT32_C(-4696.01) },
       {  SIMDE_FLOAT32_C(2725.12), SIMDE_FLOAT32_C(2725.12), SIMDE_FLOAT32_C(2725.12), SIMDE_FLOAT32_C(2725.12) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x2_t r = simde_vld2q_dup_f32(test_vec[i].a);
    simde_float32x4x2_t expected = {
        {simde_vld1q_f32(test_vec[i].r[0]), simde_vld1q_f32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f32x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2q_dup_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[2];
    simde_float64 unused[2];
    simde_float64 r[2][2];
  } test_vec[] = {
     { {  SIMDE_FLOAT64_C(-6318.09), SIMDE_FLOAT64_C(38696.63) },
       {  SIMDE_FLOAT64_C(-27977.77), SIMDE_FLOAT64_C(-12787.81)},
     { {  SIMDE_FLOAT64_C(-6318.09), SIMDE_FLOAT64_C(-6318.09) },
       {  SIMDE_FLOAT64_C(38696.63), SIMDE_FLOAT64_C(38696.63) } } },
     { {  SIMDE_FLOAT64_C(-21625.08), SIMDE_FLOAT64_C(26911.10) },
       {  SIMDE_FLOAT64_C(33404.93), SIMDE_FLOAT64_C(33236.51)},
     { {  SIMDE_FLOAT64_C(-21625.08), SIMDE_FLOAT64_C(-21625.08) },
       {  SIMDE_FLOAT64_C(26911.10), SIMDE_FLOAT64_C(26911.10) } } },
     { {  SIMDE_FLOAT64_C(-35341.89), SIMDE_FLOAT64_C(-4671.89) },
       {  SIMDE_FLOAT64_C(-24439.53), SIMDE_FLOAT64_C(-25942.73)},
     { {  SIMDE_FLOAT64_C(-35341.89), SIMDE_FLOAT64_C(-35341.89) },
       {  SIMDE_FLOAT64_C(-4671.89), SIMDE_FLOAT64_C(-4671.89) } } },
     { {  SIMDE_FLOAT64_C(23971.09), SIMDE_FLOAT64_C(43928.74) },
       {  SIMDE_FLOAT64_C(-4938.80), SIMDE_FLOAT64_C(39585.23)},
     { {  SIMDE_FLOAT64_C(23971.09), SIMDE_FLOAT64_C(23971.09) },
       {  SIMDE_FLOAT64_C(43928.74), SIMDE_FLOAT64_C(43928.74) } } },
     { {  SIMDE_FLOAT64_C(29978.96), SIMDE_FLOAT64_C(34924.24) },
       {  SIMDE_FLOAT64_C(-11437.93), SIMDE_FLOAT64_C(-33530.62)},
     { {  SIMDE_FLOAT64_C(29978.96), SIMDE_FLOAT64_C(29978.96) },
       {  SIMDE_FLOAT64_C(34924.24), SIMDE_FLOAT64_C(34924.24) } } },
     { {  SIMDE_FLOAT64_C(44018.29), SIMDE_FLOAT64_C(33685.76) },
       {  SIMDE_FLOAT64_C(-13974.59), SIMDE_FLOAT64_C(-14748.18)},
     { {  SIMDE_FLOAT64_C(44018.29), SIMDE_FLOAT64_C(44018.29) },
       {  SIMDE_FLOAT64_C(33685.76), SIMDE_FLOAT64_C(33685.76) } } },
     { {  SIMDE_FLOAT64_C(-14298.09), SIMDE_FLOAT64_C(-13821.65) },
       {  SIMDE_FLOAT64_C(-5506.59), SIMDE_FLOAT64_C(7420.16)},
     { {  SIMDE_FLOAT64_C(-14298.09), SIMDE_FLOAT64_C(-14298.09) },
       {  SIMDE_FLOAT64_C(-13821.65), SIMDE_FLOAT64_C(-13821.65) } } },
     { {  SIMDE_FLOAT64_C(-9654.44), SIMDE_FLOAT64_C(40543.01) },
       {  SIMDE_FLOAT64_C(29651.86), SIMDE_FLOAT64_C(16915.17)},
     { {  SIMDE_FLOAT64_C(-9654.44), SIMDE_FLOAT64_C(-9654.44) },
       {  SIMDE_FLOAT64_C(40543.01), SIMDE_FLOAT64_C(40543.01) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x2_t r = simde_vld2q_dup_f64(test_vec[i].a);
    simde_float64x2x2_t expected = {
        {simde_vld1q_f64(test_vec[i].r[0]), simde_vld1q_f64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f64x2(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f64x2(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2q_dup_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[2];
    int8_t unused[2];
    int8_t r[2][16];
  } test_vec[] = {
     { {  INT8_C(21), -INT8_C(48) },
       {  INT8_C(32), -INT8_C(39)},
     { {  INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21),
        INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21), INT8_C(21) },
       {  -INT8_C(48), -INT8_C(48), -INT8_C(48), -INT8_C(48), -INT8_C(48), -INT8_C(48), -INT8_C(48), -INT8_C(48),
        -INT8_C(48), -INT8_C(48), -INT8_C(48), -INT8_C(48), -INT8_C(48), -INT8_C(48), -INT8_C(48), -INT8_C(48) } } },
     { {  INT8_C(3), INT8_C(43) },
       {  INT8_C(49), -INT8_C(35)},
     { {  INT8_C(3), INT8_C(3), INT8_C(3), INT8_C(3), INT8_C(3), INT8_C(3), INT8_C(3), INT8_C(3),
        INT8_C(3), INT8_C(3), INT8_C(3), INT8_C(3), INT8_C(3), INT8_C(3), INT8_C(3), INT8_C(3) },
       {  INT8_C(43), INT8_C(43), INT8_C(43), INT8_C(43), INT8_C(43), INT8_C(43), INT8_C(43), INT8_C(43),
        INT8_C(43), INT8_C(43), INT8_C(43), INT8_C(43), INT8_C(43), INT8_C(43), INT8_C(43), INT8_C(43) } } },
     { {  INT8_C(12), -INT8_C(47) },
       {  -INT8_C(17), INT8_C(2)},
     { {  INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12),
        INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12), INT8_C(12) },
       {  -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47),
        -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47), -INT8_C(47) } } },
     { {  -INT8_C(31), -INT8_C(27) },
       {  INT8_C(34), -INT8_C(28)},
     { {  -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31),
        -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31) },
       {  -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27),
        -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27), -INT8_C(27) } } },
     { {  -INT8_C(21), -INT8_C(17) },
       {  INT8_C(30), -INT8_C(40)},
     { {  -INT8_C(21), -INT8_C(21), -INT8_C(21), -INT8_C(21), -INT8_C(21), -INT8_C(21), -INT8_C(21), -INT8_C(21),
        -INT8_C(21), -INT8_C(21), -INT8_C(21), -INT8_C(21), -INT8_C(21), -INT8_C(21), -INT8_C(21), -INT8_C(21) },
       {  -INT8_C(17), -INT8_C(17), -INT8_C(17), -INT8_C(17), -INT8_C(17), -INT8_C(17), -INT8_C(17), -INT8_C(17),
        -INT8_C(17), -INT8_C(17), -INT8_C(17), -INT8_C(17), -INT8_C(17), -INT8_C(17), -INT8_C(17), -INT8_C(17) } } },
     { {  INT8_C(26), -INT8_C(31) },
       {  INT8_C(18), INT8_C(14)},
     { {  INT8_C(26), INT8_C(26), INT8_C(26), INT8_C(26), INT8_C(26), INT8_C(26), INT8_C(26), INT8_C(26),
        INT8_C(26), INT8_C(26), INT8_C(26), INT8_C(26), INT8_C(26), INT8_C(26), INT8_C(26), INT8_C(26) },
       {  -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31),
        -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31) } } },
     { {  INT8_C(47), -INT8_C(31) },
       {  -INT8_C(7), INT8_C(20)},
     { {  INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47),
        INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47), INT8_C(47) },
       {  -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31),
        -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31), -INT8_C(31) } } },
     { {  INT8_C(42), -INT8_C(10) },
       {  -INT8_C(38), INT8_C(37)},
     { {  INT8_C(42), INT8_C(42), INT8_C(42), INT8_C(42), INT8_C(42), INT8_C(42), INT8_C(42), INT8_C(42),
        INT8_C(42), INT8_C(42), INT8_C(42), INT8_C(42), INT8_C(42), INT8_C(42), INT8_C(42), INT8_C(42) },
       {  -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10),
        -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10), -INT8_C(10) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x2_t r = simde_vld2q_dup_s8(test_vec[i].a);
    simde_int8x16x2_t expected = {
        {simde_vld1q_s8(test_vec[i].r[0]), simde_vld1q_s8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_dup_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[2];
    int16_t unused[2];
    int16_t r[2][8];
  } test_vec[] = {
     { {  INT16_C(2407), -INT16_C(2601) },
       {  -INT16_C(3548), INT16_C(1088)},
     { {  INT16_C(2407), INT16_C(2407), INT16_C(2407), INT16_C(2407),
        INT16_C(2407), INT16_C(2407), INT16_C(2407), INT16_C(2407) },
       {  -INT16_C(2601), -INT16_C(2601), -INT16_C(2601), -INT16_C(2601),
        -INT16_C(2601), -INT16_C(2601), -INT16_C(2601), -INT16_C(2601) } } },
     { {  -INT16_C(4900), INT16_C(3927) },
       {  -INT16_C(2400), -INT16_C(4330)},
     { {  -INT16_C(4900), -INT16_C(4900), -INT16_C(4900), -INT16_C(4900),
        -INT16_C(4900), -INT16_C(4900), -INT16_C(4900), -INT16_C(4900) },
       {  INT16_C(3927), INT16_C(3927), INT16_C(3927), INT16_C(3927),
        INT16_C(3927), INT16_C(3927), INT16_C(3927), INT16_C(3927) } } },
     { {  -INT16_C(564), -INT16_C(1118) },
       {  INT16_C(1031), -INT16_C(151)},
     { {  -INT16_C(564), -INT16_C(564), -INT16_C(564), -INT16_C(564),
        -INT16_C(564), -INT16_C(564), -INT16_C(564), -INT16_C(564) },
       {  -INT16_C(1118), -INT16_C(1118), -INT16_C(1118), -INT16_C(1118),
        -INT16_C(1118), -INT16_C(1118), -INT16_C(1118), -INT16_C(1118) } } },
     { {  INT16_C(1703), INT16_C(2374) },
       {  -INT16_C(4899), -INT16_C(3132)},
     { {  INT16_C(1703), INT16_C(1703), INT16_C(1703), INT16_C(1703),
        INT16_C(1703), INT16_C(1703), INT16_C(1703), INT16_C(1703) },
       {  INT16_C(2374), INT16_C(2374), INT16_C(2374), INT16_C(2374),
        INT16_C(2374), INT16_C(2374), INT16_C(2374), INT16_C(2374) } } },
     { {  INT16_C(4278), INT16_C(4104) },
       {  -INT16_C(2252), INT16_C(2469)},
     { {  INT16_C(4278), INT16_C(4278), INT16_C(4278), INT16_C(4278),
        INT16_C(4278), INT16_C(4278), INT16_C(4278), INT16_C(4278) },
       {  INT16_C(4104), INT16_C(4104), INT16_C(4104), INT16_C(4104),
        INT16_C(4104), INT16_C(4104), INT16_C(4104), INT16_C(4104) } } },
     { {  -INT16_C(1164), -INT16_C(4939) },
       {  -INT16_C(3858), INT16_C(4548)},
     { {  -INT16_C(1164), -INT16_C(1164), -INT16_C(1164), -INT16_C(1164),
        -INT16_C(1164), -INT16_C(1164), -INT16_C(1164), -INT16_C(1164) },
       {  -INT16_C(4939), -INT16_C(4939), -INT16_C(4939), -INT16_C(4939),
        -INT16_C(4939), -INT16_C(4939), -INT16_C(4939), -INT16_C(4939) } } },
     { {  -INT16_C(3397), INT16_C(3662) },
       {  INT16_C(4517), -INT16_C(1655)},
     { {  -INT16_C(3397), -INT16_C(3397), -INT16_C(3397), -INT16_C(3397),
        -INT16_C(3397), -INT16_C(3397), -INT16_C(3397), -INT16_C(3397) },
       {  INT16_C(3662), INT16_C(3662), INT16_C(3662), INT16_C(3662),
        INT16_C(3662), INT16_C(3662), INT16_C(3662), INT16_C(3662) } } },
     { {  -INT16_C(3636), INT16_C(1082) },
       {  -INT16_C(3186), INT16_C(4513)},
     { {  -INT16_C(3636), -INT16_C(3636), -INT16_C(3636), -INT16_C(3636),
        -INT16_C(3636), -INT16_C(3636), -INT16_C(3636), -INT16_C(3636) },
       {  INT16_C(1082), INT16_C(1082), INT16_C(1082), INT16_C(1082),
        INT16_C(1082), INT16_C(1082), INT16_C(1082), INT16_C(1082) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x2_t r = simde_vld2q_dup_s16(test_vec[i].a);
    simde_int16x8x2_t expected = {
        {simde_vld1q_s16(test_vec[i].r[0]), simde_vld1q_s16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_dup_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t unused[2];
    int32_t r[2][4];
  } test_vec[] = {
     { {  -INT32_C(320215), -INT32_C(128824) },
       {  -INT32_C(84416), INT32_C(173924)},
     { {  -INT32_C(320215), -INT32_C(320215), -INT32_C(320215), -INT32_C(320215) },
       {  -INT32_C(128824), -INT32_C(128824), -INT32_C(128824), -INT32_C(128824) } } },
     { {  -INT32_C(352719), -INT32_C(124530) },
       {  INT32_C(469272), -INT32_C(259438)},
     { {  -INT32_C(352719), -INT32_C(352719), -INT32_C(352719), -INT32_C(352719) },
       {  -INT32_C(124530), -INT32_C(124530), -INT32_C(124530), -INT32_C(124530) } } },
     { {  INT32_C(26840), -INT32_C(67706) },
       {  INT32_C(306244), -INT32_C(394994)},
     { {  INT32_C(26840), INT32_C(26840), INT32_C(26840), INT32_C(26840) },
       {  -INT32_C(67706), -INT32_C(67706), -INT32_C(67706), -INT32_C(67706) } } },
     { {  INT32_C(386819), -INT32_C(52375) },
       {  -INT32_C(221686), INT32_C(458634)},
     { {  INT32_C(386819), INT32_C(386819), INT32_C(386819), INT32_C(386819) },
       {  -INT32_C(52375), -INT32_C(52375), -INT32_C(52375), -INT32_C(52375) } } },
     { {  INT32_C(71692), -INT32_C(6908) },
       {  -INT32_C(241460), INT32_C(376961)},
     { {  INT32_C(71692), INT32_C(71692), INT32_C(71692), INT32_C(71692) },
       {  -INT32_C(6908), -INT32_C(6908), -INT32_C(6908), -INT32_C(6908) } } },
     { {  -INT32_C(153484), INT32_C(220056) },
       {  INT32_C(497409), -INT32_C(429618)},
     { {  -INT32_C(153484), -INT32_C(153484), -INT32_C(153484), -INT32_C(153484) },
       {  INT32_C(220056), INT32_C(220056), INT32_C(220056), INT32_C(220056) } } },
     { {  INT32_C(445458), -INT32_C(422069) },
       {  -INT32_C(473699), -INT32_C(169167)},
     { {  INT32_C(445458), INT32_C(445458), INT32_C(445458), INT32_C(445458) },
       {  -INT32_C(422069), -INT32_C(422069), -INT32_C(422069), -INT32_C(422069) } } },
     { {  INT32_C(142131), -INT32_C(97847) },
       {  -INT32_C(394989), -INT32_C(267336)},
     { {  INT32_C(142131), INT32_C(142131), INT32_C(142131), INT32_C(142131) },
       {  -INT32_C(97847), -INT32_C(97847), -INT32_C(97847), -INT32_C(97847) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x2_t r = simde_vld2q_dup_s32(test_vec[i].a);
    simde_int32x4x2_t expected = {
        {simde_vld1q_s32(test_vec[i].r[0]), simde_vld1q_s32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_dup_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int64_t unused[2];
    int64_t r[2][2];
  } test_vec[] = {
     { {  -INT64_C(15235051), -INT64_C(30008301) },
       {  INT64_C(31964111), -INT64_C(24641971)},
     { {  -INT64_C(15235051), -INT64_C(15235051) },
       {  -INT64_C(30008301), -INT64_C(30008301) } } },
     { {  -INT64_C(16181149), INT64_C(3841670) },
       {  -INT64_C(27973863), INT64_C(39259391)},
     { {  -INT64_C(16181149), -INT64_C(16181149) },
       {  INT64_C(3841670), INT64_C(3841670) } } },
     { {  INT64_C(48064682), INT64_C(41855966) },
       {  -INT64_C(10570224), INT64_C(38329774)},
     { {  INT64_C(48064682), INT64_C(48064682) },
       {  INT64_C(41855966), INT64_C(41855966) } } },
     { {  -INT64_C(90740), INT64_C(37361034) },
       {  INT64_C(44464818), INT64_C(15207495)},
     { {  -INT64_C(90740), -INT64_C(90740) },
       {  INT64_C(37361034), INT64_C(37361034) } } },
     { {  INT64_C(21453155), INT64_C(22061973) },
       {  -INT64_C(31158130), INT64_C(38690033)},
     { {  INT64_C(21453155), INT64_C(21453155) },
       {  INT64_C(22061973), INT64_C(22061973) } } },
     { {  -INT64_C(21071153), -INT64_C(25469385) },
       {  INT64_C(14847780), INT64_C(9714022)},
     { {  -INT64_C(21071153), -INT64_C(21071153) },
       {  -INT64_C(25469385), -INT64_C(25469385) } } },
     { {  -INT64_C(21428279), -INT64_C(33446233) },
       {  INT64_C(33284182), -INT64_C(519364)},
     { {  -INT64_C(21428279), -INT64_C(21428279) },
       {  -INT64_C(33446233), -INT64_C(33446233) } } },
     { {  INT64_C(40007009), INT64_C(23627817) },
       {  INT64_C(29955083), INT64_C(41266286)},
     { {  INT64_C(40007009), INT64_C(40007009) },
       {  INT64_C(23627817), INT64_C(23627817) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x2_t r = simde_vld2q_dup_s64(test_vec[i].a);
    simde_int64x2x2_t expected = {
        {simde_vld1q_s64(test_vec[i].r[0]), simde_vld1q_s64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_dup_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a[2];
    uint8_t unused[2];
    uint8_t r[2][16];
  } test_vec[] = {
     { {  UINT8_C(96), UINT8_C(23) },
       {  UINT8_C(44), UINT8_C(91)},
     { {  UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96),
        UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96), UINT8_C(96) },
       {  UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23),
        UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23), UINT8_C(23) } } },
     { {  UINT8_C(53), UINT8_C(10) },
       {  UINT8_C(65), UINT8_C(22)},
     { {  UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53),
        UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53) },
       {  UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10),
        UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10) } } },
     { {  UINT8_C(83), UINT8_C(3) },
       {  UINT8_C(50), UINT8_C(69)},
     { {  UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83),
        UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83), UINT8_C(83) },
       {  UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3),
        UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3), UINT8_C(3) } } },
     { {  UINT8_C(48), UINT8_C(62) },
       {  UINT8_C(64), UINT8_C(80)},
     { {  UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48),
        UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48), UINT8_C(48) },
       {  UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62),
        UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62), UINT8_C(62) } } },
     { {  UINT8_C(33), UINT8_C(39) },
       {  UINT8_C(0), UINT8_C(10)},
     { {  UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33),
        UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33), UINT8_C(33) },
       {  UINT8_C(39), UINT8_C(39), UINT8_C(39), UINT8_C(39), UINT8_C(39), UINT8_C(39), UINT8_C(39), UINT8_C(39),
        UINT8_C(39), UINT8_C(39), UINT8_C(39), UINT8_C(39), UINT8_C(39), UINT8_C(39), UINT8_C(39), UINT8_C(39) } } },
     { {  UINT8_C(53), UINT8_C(22) },
       {  UINT8_C(79), UINT8_C(9)},
     { {  UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53),
        UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53), UINT8_C(53) },
       {  UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22),
        UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22), UINT8_C(22) } } },
     { {  UINT8_C(54), UINT8_C(10) },
       {  UINT8_C(3), UINT8_C(83)},
     { {  UINT8_C(54), UINT8_C(54), UINT8_C(54), UINT8_C(54), UINT8_C(54), UINT8_C(54), UINT8_C(54), UINT8_C(54),
        UINT8_C(54), UINT8_C(54), UINT8_C(54), UINT8_C(54), UINT8_C(54), UINT8_C(54), UINT8_C(54), UINT8_C(54) },
       {  UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10),
        UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10), UINT8_C(10) } } },
     { {  UINT8_C(9), UINT8_C(80) },
       {  UINT8_C(74), UINT8_C(55)},
     { {  UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9),
        UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9), UINT8_C(9) },
       {  UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80),
        UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80), UINT8_C(80) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x2_t r = simde_vld2q_dup_u8(test_vec[i].a);
    simde_uint8x16x2_t expected = {
        {simde_vld1q_u8(test_vec[i].r[0]), simde_vld1q_u8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_dup_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[2];
    uint16_t unused[2];
    uint16_t r[2][8];
  } test_vec[] = {
     { {  UINT16_C(6058), UINT16_C(6273) },
       {  UINT16_C(6301), UINT16_C(7423)},
     { {  UINT16_C(6058), UINT16_C(6058), UINT16_C(6058), UINT16_C(6058),
        UINT16_C(6058), UINT16_C(6058), UINT16_C(6058), UINT16_C(6058) },
       {  UINT16_C(6273), UINT16_C(6273), UINT16_C(6273), UINT16_C(6273),
        UINT16_C(6273), UINT16_C(6273), UINT16_C(6273), UINT16_C(6273) } } },
     { {  UINT16_C(7176), UINT16_C(4578) },
       {  UINT16_C(9644), UINT16_C(9994)},
     { {  UINT16_C(7176), UINT16_C(7176), UINT16_C(7176), UINT16_C(7176),
        UINT16_C(7176), UINT16_C(7176), UINT16_C(7176), UINT16_C(7176) },
       {  UINT16_C(4578), UINT16_C(4578), UINT16_C(4578), UINT16_C(4578),
        UINT16_C(4578), UINT16_C(4578), UINT16_C(4578), UINT16_C(4578) } } },
     { {  UINT16_C(7902), UINT16_C(1902) },
       {  UINT16_C(7534), UINT16_C(3814)},
     { {  UINT16_C(7902), UINT16_C(7902), UINT16_C(7902), UINT16_C(7902),
        UINT16_C(7902), UINT16_C(7902), UINT16_C(7902), UINT16_C(7902) },
       {  UINT16_C(1902), UINT16_C(1902), UINT16_C(1902), UINT16_C(1902),
        UINT16_C(1902), UINT16_C(1902), UINT16_C(1902), UINT16_C(1902) } } },
     { {  UINT16_C(8498), UINT16_C(3391) },
       {  UINT16_C(2384), UINT16_C(829)},
     { {  UINT16_C(8498), UINT16_C(8498), UINT16_C(8498), UINT16_C(8498),
        UINT16_C(8498), UINT16_C(8498), UINT16_C(8498), UINT16_C(8498) },
       {  UINT16_C(3391), UINT16_C(3391), UINT16_C(3391), UINT16_C(3391),
        UINT16_C(3391), UINT16_C(3391), UINT16_C(3391), UINT16_C(3391) } } },
     { {  UINT16_C(5757), UINT16_C(7453) },
       {  UINT16_C(3497), UINT16_C(4212)},
     { {  UINT16_C(5757), UINT16_C(5757), UINT16_C(5757), UINT16_C(5757),
        UINT16_C(5757), UINT16_C(5757), UINT16_C(5757), UINT16_C(5757) },
       {  UINT16_C(7453), UINT16_C(7453), UINT16_C(7453), UINT16_C(7453),
        UINT16_C(7453), UINT16_C(7453), UINT16_C(7453), UINT16_C(7453) } } },
     { {  UINT16_C(2420), UINT16_C(5818) },
       {  UINT16_C(6753), UINT16_C(5749)},
     { {  UINT16_C(2420), UINT16_C(2420), UINT16_C(2420), UINT16_C(2420),
        UINT16_C(2420), UINT16_C(2420), UINT16_C(2420), UINT16_C(2420) },
       {  UINT16_C(5818), UINT16_C(5818), UINT16_C(5818), UINT16_C(5818),
        UINT16_C(5818), UINT16_C(5818), UINT16_C(5818), UINT16_C(5818) } } },
     { {  UINT16_C(3143), UINT16_C(6838) },
       {  UINT16_C(8323), UINT16_C(2227)},
     { {  UINT16_C(3143), UINT16_C(3143), UINT16_C(3143), UINT16_C(3143),
        UINT16_C(3143), UINT16_C(3143), UINT16_C(3143), UINT16_C(3143) },
       {  UINT16_C(6838), UINT16_C(6838), UINT16_C(6838), UINT16_C(6838),
        UINT16_C(6838), UINT16_C(6838), UINT16_C(6838), UINT16_C(6838) } } },
     { {  UINT16_C(6156), UINT16_C(8714) },
       {  UINT16_C(9846), UINT16_C(2394)},
     { {  UINT16_C(6156), UINT16_C(6156), UINT16_C(6156), UINT16_C(6156),
        UINT16_C(6156), UINT16_C(6156), UINT16_C(6156), UINT16_C(6156) },
       {  UINT16_C(8714), UINT16_C(8714), UINT16_C(8714), UINT16_C(8714),
        UINT16_C(8714), UINT16_C(8714), UINT16_C(8714), UINT16_C(8714) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x2_t r = simde_vld2q_dup_u16(test_vec[i].a);
    simde_uint16x8x2_t expected = {
        {simde_vld1q_u16(test_vec[i].r[0]), simde_vld1q_u16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_dup_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[2];
    uint32_t unused[2];
    uint32_t r[2][4];
  } test_vec[] = {
     { {  UINT32_C(536106), UINT32_C(877508) },
       {  UINT32_C(4679840), UINT32_C(2116123)},
     { {  UINT32_C(536106), UINT32_C(536106), UINT32_C(536106), UINT32_C(536106) },
       {  UINT32_C(877508), UINT32_C(877508), UINT32_C(877508), UINT32_C(877508) } } },
     { {  UINT32_C(2745092), UINT32_C(2480848) },
       {  UINT32_C(6021702), UINT32_C(5477534)},
     { {  UINT32_C(2745092), UINT32_C(2745092), UINT32_C(2745092), UINT32_C(2745092) },
       {  UINT32_C(2480848), UINT32_C(2480848), UINT32_C(2480848), UINT32_C(2480848) } } },
     { {  UINT32_C(4890262), UINT32_C(9837780) },
       {  UINT32_C(2908038), UINT32_C(8114742)},
     { {  UINT32_C(4890262), UINT32_C(4890262), UINT32_C(4890262), UINT32_C(4890262) },
       {  UINT32_C(9837780), UINT32_C(9837780), UINT32_C(9837780), UINT32_C(9837780) } } },
     { {  UINT32_C(6798984), UINT32_C(3169873) },
       {  UINT32_C(5423024), UINT32_C(204472)},
     { {  UINT32_C(6798984), UINT32_C(6798984), UINT32_C(6798984), UINT32_C(6798984) },
       {  UINT32_C(3169873), UINT32_C(3169873), UINT32_C(3169873), UINT32_C(3169873) } } },
     { {  UINT32_C(5642096), UINT32_C(2938870) },
       {  UINT32_C(6387732), UINT32_C(8027323)},
     { {  UINT32_C(5642096), UINT32_C(5642096), UINT32_C(5642096), UINT32_C(5642096) },
       {  UINT32_C(2938870), UINT32_C(2938870), UINT32_C(2938870), UINT32_C(2938870) } } },
     { {  UINT32_C(992304), UINT32_C(4886731) },
       {  UINT32_C(6516958), UINT32_C(303121)},
     { {  UINT32_C(992304), UINT32_C(992304), UINT32_C(992304), UINT32_C(992304) },
       {  UINT32_C(4886731), UINT32_C(4886731), UINT32_C(4886731), UINT32_C(4886731) } } },
     { {  UINT32_C(5616151), UINT32_C(6074604) },
       {  UINT32_C(2135742), UINT32_C(2607255)},
     { {  UINT32_C(5616151), UINT32_C(5616151), UINT32_C(5616151), UINT32_C(5616151) },
       {  UINT32_C(6074604), UINT32_C(6074604), UINT32_C(6074604), UINT32_C(6074604) } } },
     { {  UINT32_C(5796703), UINT32_C(4718965) },
       {  UINT32_C(8894279), UINT32_C(5823775)},
     { {  UINT32_C(5796703), UINT32_C(5796703), UINT32_C(5796703), UINT32_C(5796703) },
       {  UINT32_C(4718965), UINT32_C(4718965), UINT32_C(4718965), UINT32_C(4718965) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x2_t r = simde_vld2q_dup_u32(test_vec[i].a);
    simde_uint32x4x2_t expected = {
        {simde_vld1q_u32(test_vec[i].r[0]), simde_vld1q_u32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2q_dup_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[2];
    uint64_t unused[2];
    uint64_t r[2][2];
  } test_vec[] = {
     { {  UINT64_C(706048852), UINT64_C(383443850) },
       {  UINT64_C(285705054), UINT64_C(822983505)},
     { {  UINT64_C(706048852), UINT64_C(706048852) },
       {  UINT64_C(383443850), UINT64_C(383443850) } } },
     { {  UINT64_C(421014862), UINT64_C(906802850) },
       {  UINT64_C(817754491), UINT64_C(29691523)},
     { {  UINT64_C(421014862), UINT64_C(421014862) },
       {  UINT64_C(906802850), UINT64_C(906802850) } } },
     { {  UINT64_C(221353308), UINT64_C(322577141) },
       {  UINT64_C(995600522), UINT64_C(297974478)},
     { {  UINT64_C(221353308), UINT64_C(221353308) },
       {  UINT64_C(322577141), UINT64_C(322577141) } } },
     { {  UINT64_C(663578487), UINT64_C(286997839) },
       {  UINT64_C(243168275), UINT64_C(577857697)},
     { {  UINT64_C(663578487), UINT64_C(663578487) },
       {  UINT64_C(286997839), UINT64_C(286997839) } } },
     { {  UINT64_C(593025173), UINT64_C(964665381) },
       {  UINT64_C(503395467), UINT64_C(204960526)},
     { {  UINT64_C(593025173), UINT64_C(593025173) },
       {  UINT64_C(964665381), UINT64_C(964665381) } } },
     { {  UINT64_C(962157997), UINT64_C(598569861) },
       {  UINT64_C(705698189), UINT64_C(932957687)},
     { {  UINT64_C(962157997), UINT64_C(962157997) },
       {  UINT64_C(598569861), UINT64_C(598569861) } } },
     { {  UINT64_C(486609766), UINT64_C(401817412) },
       {  UINT64_C(317463497), UINT64_C(368423896)},
     { {  UINT64_C(486609766), UINT64_C(486609766) },
       {  UINT64_C(401817412), UINT64_C(401817412) } } },
     { {  UINT64_C(603061297), UINT64_C(721346221) },
       {  UINT64_C(633243906), UINT64_C(434342421)},
     { {  UINT64_C(603061297), UINT64_C(603061297) },
       {  UINT64_C(721346221), UINT64_C(721346221) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x2_t r = simde_vld2q_dup_u64(test_vec[i].a);
    simde_uint64x2x2_t expected = {
        {simde_vld1q_u64(test_vec[i].r[0]), simde_vld1q_u64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[1], expected.val[1]);
  }

  return 0;
}

static int
test_simde_vld2_dup_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly8_t a[2];
    simde_poly8_t unused[2];
    simde_poly8_t r[2][8];
  } test_vec[] = {
     { {  SIMDE_POLY8_C(94), SIMDE_POLY8_C(65) },
       {  SIMDE_POLY8_C(68), SIMDE_POLY8_C(15)},
     { {  SIMDE_POLY8_C(94), SIMDE_POLY8_C(94), SIMDE_POLY8_C(94), SIMDE_POLY8_C(94),
        SIMDE_POLY8_C(94), SIMDE_POLY8_C(94), SIMDE_POLY8_C(94), SIMDE_POLY8_C(94) },
       {  SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65),
        SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65), SIMDE_POLY8_C(65) } } },
     { {  SIMDE_POLY8_C(89), SIMDE_POLY8_C(88) },
       {  SIMDE_POLY8_C(87), SIMDE_POLY8_C(56)},
     { {  SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89),
        SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89), SIMDE_POLY8_C(89) },
       {  SIMDE_POLY8_C(88), SIMDE_POLY8_C(88), SIMDE_POLY8_C(88), SIMDE_POLY8_C(88),
        SIMDE_POLY8_C(88), SIMDE_POLY8_C(88), SIMDE_POLY8_C(88), SIMDE_POLY8_C(88) } } },
     { {  SIMDE_POLY8_C(28), SIMDE_POLY8_C(34) },
       {  SIMDE_POLY8_C(99), SIMDE_POLY8_C(65)},
     { {  SIMDE_POLY8_C(28), SIMDE_POLY8_C(28), SIMDE_POLY8_C(28), SIMDE_POLY8_C(28),
        SIMDE_POLY8_C(28), SIMDE_POLY8_C(28), SIMDE_POLY8_C(28), SIMDE_POLY8_C(28) },
       {  SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34),
        SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34), SIMDE_POLY8_C(34) } } },
     { {  SIMDE_POLY8_C(44), SIMDE_POLY8_C(68) },
       {  SIMDE_POLY8_C(10), SIMDE_POLY8_C(26)},
     { {  SIMDE_POLY8_C(44), SIMDE_POLY8_C(44), SIMDE_POLY8_C(44), SIMDE_POLY8_C(44),
        SIMDE_POLY8_C(44), SIMDE_POLY8_C(44), SIMDE_POLY8_C(44), SIMDE_POLY8_C(44) },
       {  SIMDE_POLY8_C(68), SIMDE_POLY8_C(68), SIMDE_POLY8_C(68), SIMDE_POLY8_C(68),
        SIMDE_POLY8_C(68), SIMDE_POLY8_C(68), SIMDE_POLY8_C(68), SIMDE_POLY8_C(68) } } },
     { {  SIMDE_POLY8_C(47), SIMDE_POLY8_C(62) },
       {  SIMDE_POLY8_C(86), SIMDE_POLY8_C(81)},
     { {  SIMDE_POLY8_C(47), SIMDE_POLY8_C(47), SIMDE_POLY8_C(47), SIMDE_POLY8_C(47),
        SIMDE_POLY8_C(47), SIMDE_POLY8_C(47), SIMDE_POLY8_C(47), SIMDE_POLY8_C(47) },
       {  SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62),
        SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62) } } },
     { {  SIMDE_POLY8_C(53), SIMDE_POLY8_C(60) },
       {  SIMDE_POLY8_C(43), SIMDE_POLY8_C(84)},
     { {  SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53),
        SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(60), SIMDE_POLY8_C(60), SIMDE_POLY8_C(60), SIMDE_POLY8_C(60),
        SIMDE_POLY8_C(60), SIMDE_POLY8_C(60), SIMDE_POLY8_C(60), SIMDE_POLY8_C(60) } } },
     { {  SIMDE_POLY8_C(15), SIMDE_POLY8_C(10) },
       {  SIMDE_POLY8_C(26), SIMDE_POLY8_C(7)},
     { {  SIMDE_POLY8_C(15), SIMDE_POLY8_C(15), SIMDE_POLY8_C(15), SIMDE_POLY8_C(15),
        SIMDE_POLY8_C(15), SIMDE_POLY8_C(15), SIMDE_POLY8_C(15), SIMDE_POLY8_C(15) },
       {  SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10),
        SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10) } } },
     { {  SIMDE_POLY8_C(64), SIMDE_POLY8_C(33) },
       {  SIMDE_POLY8_C(81), SIMDE_POLY8_C(53)},
     { {  SIMDE_POLY8_C(64), SIMDE_POLY8_C(64), SIMDE_POLY8_C(64), SIMDE_POLY8_C(64),
        SIMDE_POLY8_C(64), SIMDE_POLY8_C(64), SIMDE_POLY8_C(64), SIMDE_POLY8_C(64) },
       {  SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33),
        SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8x2_t r = simde_vld2_dup_p8(test_vec[i].a);
    simde_poly8x8x2_t expected = {
        {simde_vld1_p8(test_vec[i].r[0]), simde_vld1_p8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_p8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly8_t a[2];
    simde_poly8_t unused[2];
    simde_poly8x8x2_t r;
    simde_test_codegen_random_memory(2, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(2, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld2_dup_p8(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp8(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp8(2, 2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_dup_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly16_t a[2];
    simde_poly16_t unused[2];
    simde_poly16_t r[2][4];
  } test_vec[] = {
     { {  SIMDE_POLY16_C(7277), SIMDE_POLY16_C(6201) },
       {  SIMDE_POLY16_C(9680), SIMDE_POLY16_C(3544)},
     { {  SIMDE_POLY16_C(7277), SIMDE_POLY16_C(7277), SIMDE_POLY16_C(7277), SIMDE_POLY16_C(7277) },
       {  SIMDE_POLY16_C(6201), SIMDE_POLY16_C(6201), SIMDE_POLY16_C(6201), SIMDE_POLY16_C(6201) } } },
     { {  SIMDE_POLY16_C(2944), SIMDE_POLY16_C(5592) },
       {  SIMDE_POLY16_C(9662), SIMDE_POLY16_C(4267)},
     { {  SIMDE_POLY16_C(2944), SIMDE_POLY16_C(2944), SIMDE_POLY16_C(2944), SIMDE_POLY16_C(2944) },
       {  SIMDE_POLY16_C(5592), SIMDE_POLY16_C(5592), SIMDE_POLY16_C(5592), SIMDE_POLY16_C(5592) } } },
     { {  SIMDE_POLY16_C(8742), SIMDE_POLY16_C(6060) },
       {  SIMDE_POLY16_C(3824), SIMDE_POLY16_C(2303)},
     { {  SIMDE_POLY16_C(8742), SIMDE_POLY16_C(8742), SIMDE_POLY16_C(8742), SIMDE_POLY16_C(8742) },
       {  SIMDE_POLY16_C(6060), SIMDE_POLY16_C(6060), SIMDE_POLY16_C(6060), SIMDE_POLY16_C(6060) } } },
     { {  SIMDE_POLY16_C(9964), SIMDE_POLY16_C(5944) },
       {  SIMDE_POLY16_C(4767), SIMDE_POLY16_C(7055)},
     { {  SIMDE_POLY16_C(9964), SIMDE_POLY16_C(9964), SIMDE_POLY16_C(9964), SIMDE_POLY16_C(9964) },
       {  SIMDE_POLY16_C(5944), SIMDE_POLY16_C(5944), SIMDE_POLY16_C(5944), SIMDE_POLY16_C(5944) } } },
     { {  SIMDE_POLY16_C(6764), SIMDE_POLY16_C(915) },
       {  SIMDE_POLY16_C(2455), SIMDE_POLY16_C(4422)},
     { {  SIMDE_POLY16_C(6764), SIMDE_POLY16_C(6764), SIMDE_POLY16_C(6764), SIMDE_POLY16_C(6764) },
       {  SIMDE_POLY16_C(915), SIMDE_POLY16_C(915), SIMDE_POLY16_C(915), SIMDE_POLY16_C(915) } } },
     { {  SIMDE_POLY16_C(3051), SIMDE_POLY16_C(2687) },
       {  SIMDE_POLY16_C(3858), SIMDE_POLY16_C(7628)},
     { {  SIMDE_POLY16_C(3051), SIMDE_POLY16_C(3051), SIMDE_POLY16_C(3051), SIMDE_POLY16_C(3051) },
       {  SIMDE_POLY16_C(2687), SIMDE_POLY16_C(2687), SIMDE_POLY16_C(2687), SIMDE_POLY16_C(2687) } } },
     { {  SIMDE_POLY16_C(2343), SIMDE_POLY16_C(2688) },
       {  SIMDE_POLY16_C(3196), SIMDE_POLY16_C(4003)},
     { {  SIMDE_POLY16_C(2343), SIMDE_POLY16_C(2343), SIMDE_POLY16_C(2343), SIMDE_POLY16_C(2343) },
       {  SIMDE_POLY16_C(2688), SIMDE_POLY16_C(2688), SIMDE_POLY16_C(2688), SIMDE_POLY16_C(2688) } } },
     { {  SIMDE_POLY16_C(6885), SIMDE_POLY16_C(4075) },
       {  SIMDE_POLY16_C(1096), SIMDE_POLY16_C(2437)},
     { {  SIMDE_POLY16_C(6885), SIMDE_POLY16_C(6885), SIMDE_POLY16_C(6885), SIMDE_POLY16_C(6885) },
       {  SIMDE_POLY16_C(4075), SIMDE_POLY16_C(4075), SIMDE_POLY16_C(4075), SIMDE_POLY16_C(4075) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4x2_t r = simde_vld2_dup_p16(test_vec[i].a);
    simde_poly16x4x2_t expected = {
        {simde_vld1_p16(test_vec[i].r[0]), simde_vld1_p16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_p16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x4(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16_t a[2];
    simde_poly16_t unused[2];
    simde_poly16x4x2_t r;
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld2_dup_p16(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp16(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp16(2, 2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_dup_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[2];
    simde_poly64_t unused[2];
    simde_poly64_t r[2][1];
  } test_vec[] = {
    { { SIMDE_POLY64_C(12740477471170781294), SIMDE_POLY64_C( 1202653309370274056) },
      { SIMDE_POLY64_C( 3578144166166679559), SIMDE_POLY64_C( 3824348584412100321) },
        { { SIMDE_POLY64_C(12740477471170781294) },
          { SIMDE_POLY64_C( 1202653309370274056) } },
    },
    { { SIMDE_POLY64_C( 6891094942518022704), SIMDE_POLY64_C( 5658821612954949799) },
      { SIMDE_POLY64_C(  708826733701826684), SIMDE_POLY64_C(18227356099470753016) },
        { { SIMDE_POLY64_C( 6891094942518022704) },
          { SIMDE_POLY64_C( 5658821612954949799) } },
    },
    { { SIMDE_POLY64_C(17968113820134947749), SIMDE_POLY64_C( 9132446833727034920) },
      { SIMDE_POLY64_C(10390641722217682433), SIMDE_POLY64_C(16986807340681376757) },
        { { SIMDE_POLY64_C(17968113820134947749) },
          { SIMDE_POLY64_C( 9132446833727034920) } },
    },
    { { SIMDE_POLY64_C( 7190351104749054846), SIMDE_POLY64_C( 3718440788214036761) },
      { SIMDE_POLY64_C(12397722267937455588), SIMDE_POLY64_C( 2194145411926481985) },
        { { SIMDE_POLY64_C( 7190351104749054846) },
          { SIMDE_POLY64_C( 3718440788214036761) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1x2_t r = simde_vld2_dup_p64(test_vec[i].a);
    simde_poly64x1x2_t expected = {
        {simde_vld1_p64(test_vec[i].r[0]), simde_vld1_p64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_p64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x1(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly64_t a[2];
    simde_poly64_t unused[2];
    simde_poly64x1x2_t r;
    simde_test_codegen_random_memory(16, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(16, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld2_dup_p64(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp64(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp64(2, 2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_dup_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_TO_16 simde_poly8_t a[2];
    SIMDE_ALIGN_TO_16 simde_poly8_t unused[2];
    SIMDE_ALIGN_TO_16 simde_poly8_t r[2][16];
  } test_vec[] = {
     { {  SIMDE_POLY8_C(96), SIMDE_POLY8_C(23) },
       {  SIMDE_POLY8_C(44), SIMDE_POLY8_C(91)},
     { {  SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96),
        SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96), SIMDE_POLY8_C(96) },
       {  SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23),
        SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23), SIMDE_POLY8_C(23) } } },
     { {  SIMDE_POLY8_C(53), SIMDE_POLY8_C(10) },
       {  SIMDE_POLY8_C(65), SIMDE_POLY8_C(22)},
     { {  SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53),
        SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10),
        SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10) } } },
     { {  SIMDE_POLY8_C(83), SIMDE_POLY8_C(3) },
       {  SIMDE_POLY8_C(50), SIMDE_POLY8_C(69)},
     { {  SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83),
        SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83), SIMDE_POLY8_C(83) },
       {  SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3),
        SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3), SIMDE_POLY8_C(3) } } },
     { {  SIMDE_POLY8_C(48), SIMDE_POLY8_C(62) },
       {  SIMDE_POLY8_C(64), SIMDE_POLY8_C(80)},
     { {  SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48),
        SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48), SIMDE_POLY8_C(48) },
       {  SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62),
        SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62), SIMDE_POLY8_C(62) } } },
     { {  SIMDE_POLY8_C(33), SIMDE_POLY8_C(39) },
       {  SIMDE_POLY8_C(0), SIMDE_POLY8_C(10)},
     { {  SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33),
        SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33), SIMDE_POLY8_C(33) },
       {  SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39),
        SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39), SIMDE_POLY8_C(39) } } },
     { {  SIMDE_POLY8_C(53), SIMDE_POLY8_C(22) },
       {  SIMDE_POLY8_C(79), SIMDE_POLY8_C(9)},
     { {  SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53),
        SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53), SIMDE_POLY8_C(53) },
       {  SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22),
        SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22), SIMDE_POLY8_C(22) } } },
     { {  SIMDE_POLY8_C(54), SIMDE_POLY8_C(10) },
       {  SIMDE_POLY8_C(3), SIMDE_POLY8_C(83)},
     { {  SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54),
        SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54), SIMDE_POLY8_C(54) },
       {  SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10),
        SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10), SIMDE_POLY8_C(10) } } },
     { {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(80) },
       {  SIMDE_POLY8_C(74), SIMDE_POLY8_C(55)},
     { {  SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9),
        SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9), SIMDE_POLY8_C(9) },
       {  SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80),
        SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80), SIMDE_POLY8_C(80) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    SIMDE_ALIGN_TO_16 simde_poly8x16x2_t r = simde_vld2q_dup_p8(test_vec[i].a);
    SIMDE_ALIGN_TO_16 simde_poly8x16x2_t expected = {
        {simde_vld1q_p8(test_vec[i].r[0]), simde_vld1q_p8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_p8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p8x16(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly8_t a[2];
    simde_poly8_t unused[2];
    simde_poly8x16x2_t r;
    simde_test_codegen_random_memory(2, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(2, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld2q_dup_p8(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp8(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp8(2, 2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_dup_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 simde_poly16_t a[2];
    SIMDE_ALIGN_TO_16 simde_poly16_t unused[2];
    SIMDE_ALIGN_TO_16 simde_poly16_t r[2][8];
  } test_vec[] = {
     { {  SIMDE_POLY16_C(6058), SIMDE_POLY16_C(6273) },
       {  SIMDE_POLY16_C(6301), SIMDE_POLY16_C(7423)},
     { {  SIMDE_POLY16_C(6058), SIMDE_POLY16_C(6058), SIMDE_POLY16_C(6058), SIMDE_POLY16_C(6058),
        SIMDE_POLY16_C(6058), SIMDE_POLY16_C(6058), SIMDE_POLY16_C(6058), SIMDE_POLY16_C(6058) },
       {  SIMDE_POLY16_C(6273), SIMDE_POLY16_C(6273), SIMDE_POLY16_C(6273), SIMDE_POLY16_C(6273),
        SIMDE_POLY16_C(6273), SIMDE_POLY16_C(6273), SIMDE_POLY16_C(6273), SIMDE_POLY16_C(6273) } } },
     { {  SIMDE_POLY16_C(7176), SIMDE_POLY16_C(4578) },
       {  SIMDE_POLY16_C(9644), SIMDE_POLY16_C(9994)},
     { {  SIMDE_POLY16_C(7176), SIMDE_POLY16_C(7176), SIMDE_POLY16_C(7176), SIMDE_POLY16_C(7176),
        SIMDE_POLY16_C(7176), SIMDE_POLY16_C(7176), SIMDE_POLY16_C(7176), SIMDE_POLY16_C(7176) },
       {  SIMDE_POLY16_C(4578), SIMDE_POLY16_C(4578), SIMDE_POLY16_C(4578), SIMDE_POLY16_C(4578),
        SIMDE_POLY16_C(4578), SIMDE_POLY16_C(4578), SIMDE_POLY16_C(4578), SIMDE_POLY16_C(4578) } } },
     { {  SIMDE_POLY16_C(7902), SIMDE_POLY16_C(1902) },
       {  SIMDE_POLY16_C(7534), SIMDE_POLY16_C(3814)},
     { {  SIMDE_POLY16_C(7902), SIMDE_POLY16_C(7902), SIMDE_POLY16_C(7902), SIMDE_POLY16_C(7902),
        SIMDE_POLY16_C(7902), SIMDE_POLY16_C(7902), SIMDE_POLY16_C(7902), SIMDE_POLY16_C(7902) },
       {  SIMDE_POLY16_C(1902), SIMDE_POLY16_C(1902), SIMDE_POLY16_C(1902), SIMDE_POLY16_C(1902),
        SIMDE_POLY16_C(1902), SIMDE_POLY16_C(1902), SIMDE_POLY16_C(1902), SIMDE_POLY16_C(1902) } } },
     { {  SIMDE_POLY16_C(8498), SIMDE_POLY16_C(3391) },
       {  SIMDE_POLY16_C(2384), SIMDE_POLY16_C(829)},
     { {  SIMDE_POLY16_C(8498), SIMDE_POLY16_C(8498), SIMDE_POLY16_C(8498), SIMDE_POLY16_C(8498),
        SIMDE_POLY16_C(8498), SIMDE_POLY16_C(8498), SIMDE_POLY16_C(8498), SIMDE_POLY16_C(8498) },
       {  SIMDE_POLY16_C(3391), SIMDE_POLY16_C(3391), SIMDE_POLY16_C(3391), SIMDE_POLY16_C(3391),
        SIMDE_POLY16_C(3391), SIMDE_POLY16_C(3391), SIMDE_POLY16_C(3391), SIMDE_POLY16_C(3391) } } },
     { {  SIMDE_POLY16_C(5757), SIMDE_POLY16_C(7453) },
       {  SIMDE_POLY16_C(3497), SIMDE_POLY16_C(4212)},
     { {  SIMDE_POLY16_C(5757), SIMDE_POLY16_C(5757), SIMDE_POLY16_C(5757), SIMDE_POLY16_C(5757),
        SIMDE_POLY16_C(5757), SIMDE_POLY16_C(5757), SIMDE_POLY16_C(5757), SIMDE_POLY16_C(5757) },
       {  SIMDE_POLY16_C(7453), SIMDE_POLY16_C(7453), SIMDE_POLY16_C(7453), SIMDE_POLY16_C(7453),
        SIMDE_POLY16_C(7453), SIMDE_POLY16_C(7453), SIMDE_POLY16_C(7453), SIMDE_POLY16_C(7453) } } },
     { {  SIMDE_POLY16_C(2420), SIMDE_POLY16_C(5818) },
       {  SIMDE_POLY16_C(6753), SIMDE_POLY16_C(5749)},
     { {  SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420),
        SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420), SIMDE_POLY16_C(2420) },
       {  SIMDE_POLY16_C(5818), SIMDE_POLY16_C(5818), SIMDE_POLY16_C(5818), SIMDE_POLY16_C(5818),
        SIMDE_POLY16_C(5818), SIMDE_POLY16_C(5818), SIMDE_POLY16_C(5818), SIMDE_POLY16_C(5818) } } },
     { {  SIMDE_POLY16_C(3143), SIMDE_POLY16_C(6838) },
       {  SIMDE_POLY16_C(8323), SIMDE_POLY16_C(2227)},
     { {  SIMDE_POLY16_C(3143), SIMDE_POLY16_C(3143), SIMDE_POLY16_C(3143), SIMDE_POLY16_C(3143),
        SIMDE_POLY16_C(3143), SIMDE_POLY16_C(3143), SIMDE_POLY16_C(3143), SIMDE_POLY16_C(3143) },
       {  SIMDE_POLY16_C(6838), SIMDE_POLY16_C(6838), SIMDE_POLY16_C(6838), SIMDE_POLY16_C(6838),
        SIMDE_POLY16_C(6838), SIMDE_POLY16_C(6838), SIMDE_POLY16_C(6838), SIMDE_POLY16_C(6838) } } },
     { {  SIMDE_POLY16_C(6156), SIMDE_POLY16_C(8714) },
       {  SIMDE_POLY16_C(9846), SIMDE_POLY16_C(2394)},
     { {  SIMDE_POLY16_C(6156), SIMDE_POLY16_C(6156), SIMDE_POLY16_C(6156), SIMDE_POLY16_C(6156),
        SIMDE_POLY16_C(6156), SIMDE_POLY16_C(6156), SIMDE_POLY16_C(6156), SIMDE_POLY16_C(6156) },
       {  SIMDE_POLY16_C(8714), SIMDE_POLY16_C(8714), SIMDE_POLY16_C(8714), SIMDE_POLY16_C(8714),
        SIMDE_POLY16_C(8714), SIMDE_POLY16_C(8714), SIMDE_POLY16_C(8714), SIMDE_POLY16_C(8714) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    SIMDE_ALIGN_TO_16 simde_poly16_t* a = HEDLEY_STATIC_CAST(simde_poly16_t*, test_vec[i].a);
    SIMDE_ALIGN_TO_16 simde_poly16x8x2_t r;
    SIMDE_ALIGN_TO_16 simde_poly16x8x2_t expected = {
        {simde_vld1q_p16(test_vec[i].r[0]), simde_vld1q_p16(test_vec[i].r[1])}};
    r = simde_vld2q_dup_p16(a);

    simde_test_arm_neon_write_p16x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
    simde_test_arm_neon_assert_equal_p16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p16x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly16_t a[2];
    simde_poly16_t unused[2];
    simde_poly16x8x2_t r;
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(4, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld2q_dup_p16(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp16(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp16(2, 2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_dup_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t a[2];
    simde_poly64_t unused[2];
    simde_poly64_t r[2][2];
  } test_vec[] = {
     { {  SIMDE_POLY64_C(706048852), SIMDE_POLY64_C(383443850) },
       {  SIMDE_POLY64_C(285705054), SIMDE_POLY64_C(822983505)},
     { {  SIMDE_POLY64_C(706048852), SIMDE_POLY64_C(706048852) },
       {  SIMDE_POLY64_C(383443850), SIMDE_POLY64_C(383443850) } } },
     { {  SIMDE_POLY64_C(421014862), SIMDE_POLY64_C(906802850) },
       {  SIMDE_POLY64_C(817754491), SIMDE_POLY64_C(29691523)},
     { {  SIMDE_POLY64_C(421014862), SIMDE_POLY64_C(421014862) },
       {  SIMDE_POLY64_C(906802850), SIMDE_POLY64_C(906802850) } } },
     { {  SIMDE_POLY64_C(221353308), SIMDE_POLY64_C(322577141) },
       {  SIMDE_POLY64_C(995600522), SIMDE_POLY64_C(297974478)},
     { {  SIMDE_POLY64_C(221353308), SIMDE_POLY64_C(221353308) },
       {  SIMDE_POLY64_C(322577141), SIMDE_POLY64_C(322577141) } } },
     { {  SIMDE_POLY64_C(663578487), SIMDE_POLY64_C(286997839) },
       {  SIMDE_POLY64_C(243168275), SIMDE_POLY64_C(577857697)},
     { {  SIMDE_POLY64_C(663578487), SIMDE_POLY64_C(663578487) },
       {  SIMDE_POLY64_C(286997839), SIMDE_POLY64_C(286997839) } } },
     { {  SIMDE_POLY64_C(593025173), SIMDE_POLY64_C(964665381) },
       {  SIMDE_POLY64_C(503395467), SIMDE_POLY64_C(204960526)},
     { {  SIMDE_POLY64_C(593025173), SIMDE_POLY64_C(593025173) },
       {  SIMDE_POLY64_C(964665381), SIMDE_POLY64_C(964665381) } } },
     { {  SIMDE_POLY64_C(962157997), SIMDE_POLY64_C(598569861) },
       {  SIMDE_POLY64_C(705698189), SIMDE_POLY64_C(932957687)},
     { {  SIMDE_POLY64_C(962157997), SIMDE_POLY64_C(962157997) },
       {  SIMDE_POLY64_C(598569861), SIMDE_POLY64_C(598569861) } } },
     { {  SIMDE_POLY64_C(486609766), SIMDE_POLY64_C(401817412) },
       {  SIMDE_POLY64_C(317463497), SIMDE_POLY64_C(368423896)},
     { {  SIMDE_POLY64_C(486609766), SIMDE_POLY64_C(486609766) },
       {  SIMDE_POLY64_C(401817412), SIMDE_POLY64_C(401817412) } } },
     { {  SIMDE_POLY64_C(603061297), SIMDE_POLY64_C(721346221) },
       {  SIMDE_POLY64_C(633243906), SIMDE_POLY64_C(434342421)},
     { {  SIMDE_POLY64_C(603061297), SIMDE_POLY64_C(603061297) },
       {  SIMDE_POLY64_C(721346221), SIMDE_POLY64_C(721346221) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2x2_t r = simde_vld2q_dup_p64(test_vec[i].a);
    simde_poly64x2x2_t expected = {
        {simde_vld1q_p64(test_vec[i].r[0]), simde_vld1q_p64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_p64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_p64x2(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_poly64_t a[2];
    simde_poly64_t unused[2];
    simde_poly64x2x2_t r;
    simde_test_codegen_random_memory(16, HEDLEY_REINTERPRET_CAST(uint8_t*, a));
    simde_test_codegen_random_memory(16, HEDLEY_REINTERPRET_CAST(uint8_t*, unused));
    r = simde_vld2q_dup_p64(a);
    // Random buffer between pointer to load and expected results to check for
    // loading out of bounds.

    simde_test_codegen_write_vp64(2, 2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_vp64(2, 2, unused, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_dup_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t a[2];
    simde_bfloat16_t unused[2];
    simde_bfloat16_t r[2][4];
  } test_vec[] = {
     { {  SIMDE_BFLOAT16_VALUE(39.04), SIMDE_BFLOAT16_VALUE(10.61) },
       {  SIMDE_BFLOAT16_VALUE(-41.47), SIMDE_BFLOAT16_VALUE(28.54)},
     { {  SIMDE_BFLOAT16_VALUE(39.04), SIMDE_BFLOAT16_VALUE(39.04), SIMDE_BFLOAT16_VALUE(39.04), SIMDE_BFLOAT16_VALUE(39.04) },
       {  SIMDE_BFLOAT16_VALUE(10.61), SIMDE_BFLOAT16_VALUE(10.61), SIMDE_BFLOAT16_VALUE(10.61), SIMDE_BFLOAT16_VALUE(10.61) } } },
     { {  SIMDE_BFLOAT16_VALUE(-26.09), SIMDE_BFLOAT16_VALUE(-32.09) },
       {  SIMDE_BFLOAT16_VALUE(-21.60), SIMDE_BFLOAT16_VALUE(-5.65)},
     { {  SIMDE_BFLOAT16_VALUE(-26.09), SIMDE_BFLOAT16_VALUE(-26.09), SIMDE_BFLOAT16_VALUE(-26.09), SIMDE_BFLOAT16_VALUE(-26.09) },
       {  SIMDE_BFLOAT16_VALUE(-32.09), SIMDE_BFLOAT16_VALUE(-32.09), SIMDE_BFLOAT16_VALUE(-32.09), SIMDE_BFLOAT16_VALUE(-32.09) } } },
     { {  SIMDE_BFLOAT16_VALUE(27.51), SIMDE_BFLOAT16_VALUE(-41.83) },
       {  SIMDE_BFLOAT16_VALUE(21.45), SIMDE_BFLOAT16_VALUE(9.79)},
     { {  SIMDE_BFLOAT16_VALUE(27.51), SIMDE_BFLOAT16_VALUE(27.51), SIMDE_BFLOAT16_VALUE(27.51), SIMDE_BFLOAT16_VALUE(27.51) },
       {  SIMDE_BFLOAT16_VALUE(-41.83), SIMDE_BFLOAT16_VALUE(-41.83), SIMDE_BFLOAT16_VALUE(-41.83), SIMDE_BFLOAT16_VALUE(-41.83) } } },
     { {  SIMDE_BFLOAT16_VALUE(-19.53), SIMDE_BFLOAT16_VALUE(-7.90) },
       {  SIMDE_BFLOAT16_VALUE(-3.62), SIMDE_BFLOAT16_VALUE(17.75)},
     { {  SIMDE_BFLOAT16_VALUE(-19.53), SIMDE_BFLOAT16_VALUE(-19.53), SIMDE_BFLOAT16_VALUE(-19.53), SIMDE_BFLOAT16_VALUE(-19.53) },
       {  SIMDE_BFLOAT16_VALUE(-7.90), SIMDE_BFLOAT16_VALUE(-7.90), SIMDE_BFLOAT16_VALUE(-7.90), SIMDE_BFLOAT16_VALUE(-7.90) } } },
     { {  SIMDE_BFLOAT16_VALUE(-22.86), SIMDE_BFLOAT16_VALUE(5.30) },
       {  SIMDE_BFLOAT16_VALUE(-42.71), SIMDE_BFLOAT16_VALUE(-2.30)},
     { {  SIMDE_BFLOAT16_VALUE(-22.86), SIMDE_BFLOAT16_VALUE(-22.86), SIMDE_BFLOAT16_VALUE(-22.86), SIMDE_BFLOAT16_VALUE(-22.86) },
       {  SIMDE_BFLOAT16_VALUE(5.30), SIMDE_BFLOAT16_VALUE(5.30), SIMDE_BFLOAT16_VALUE(5.30), SIMDE_BFLOAT16_VALUE(5.30) } } },
     { {  SIMDE_BFLOAT16_VALUE(4.74), SIMDE_BFLOAT16_VALUE(43.69) },
       {  SIMDE_BFLOAT16_VALUE(-49.64), SIMDE_BFLOAT16_VALUE(-29.99)},
     { {  SIMDE_BFLOAT16_VALUE(4.74), SIMDE_BFLOAT16_VALUE(4.74), SIMDE_BFLOAT16_VALUE(4.74), SIMDE_BFLOAT16_VALUE(4.74) },
       {  SIMDE_BFLOAT16_VALUE(43.69), SIMDE_BFLOAT16_VALUE(43.69), SIMDE_BFLOAT16_VALUE(43.69), SIMDE_BFLOAT16_VALUE(43.69) } } },
     { {  SIMDE_BFLOAT16_VALUE(-1.69), SIMDE_BFLOAT16_VALUE(-25.30) },
       {  SIMDE_BFLOAT16_VALUE(4.77), SIMDE_BFLOAT16_VALUE(22.66)},
     { {  SIMDE_BFLOAT16_VALUE(-1.69), SIMDE_BFLOAT16_VALUE(-1.69), SIMDE_BFLOAT16_VALUE(-1.69), SIMDE_BFLOAT16_VALUE(-1.69) },
       {  SIMDE_BFLOAT16_VALUE(-25.30), SIMDE_BFLOAT16_VALUE(-25.30), SIMDE_BFLOAT16_VALUE(-25.30), SIMDE_BFLOAT16_VALUE(-25.30) } } },
     { {  SIMDE_BFLOAT16_VALUE(45.42), SIMDE_BFLOAT16_VALUE(-42.46) },
       {  SIMDE_BFLOAT16_VALUE(-4.86), SIMDE_BFLOAT16_VALUE(42.78)},
     { {  SIMDE_BFLOAT16_VALUE(45.42), SIMDE_BFLOAT16_VALUE(45.42), SIMDE_BFLOAT16_VALUE(45.42), SIMDE_BFLOAT16_VALUE(45.42) },
       {  SIMDE_BFLOAT16_VALUE(-42.46), SIMDE_BFLOAT16_VALUE(-42.46), SIMDE_BFLOAT16_VALUE(-42.46), SIMDE_BFLOAT16_VALUE(-42.46) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4x2_t r = simde_vld2_dup_bf16(test_vec[i].a);
    simde_bfloat16x4x2_t expected = {
        {simde_vld1_bf16(test_vec[i].r[0]), simde_vld1_bf16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_bf16x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x4(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

static int
test_simde_vld2q_dup_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_bfloat16_t a[2];
    simde_bfloat16_t unused[2];
    simde_bfloat16_t r[2][8];
  } test_vec[] = {
     { {  SIMDE_BFLOAT16_VALUE(44.20), SIMDE_BFLOAT16_VALUE(24.16) },
       {  SIMDE_BFLOAT16_VALUE(-44.99), SIMDE_BFLOAT16_VALUE(0.06)},
     { {  SIMDE_BFLOAT16_VALUE(44.20), SIMDE_BFLOAT16_VALUE(44.20), SIMDE_BFLOAT16_VALUE(44.20), SIMDE_BFLOAT16_VALUE(44.20),
        SIMDE_BFLOAT16_VALUE(44.20), SIMDE_BFLOAT16_VALUE(44.20), SIMDE_BFLOAT16_VALUE(44.20), SIMDE_BFLOAT16_VALUE(44.20) },
       {  SIMDE_BFLOAT16_VALUE(24.16), SIMDE_BFLOAT16_VALUE(24.16), SIMDE_BFLOAT16_VALUE(24.16), SIMDE_BFLOAT16_VALUE(24.16),
        SIMDE_BFLOAT16_VALUE(24.16), SIMDE_BFLOAT16_VALUE(24.16), SIMDE_BFLOAT16_VALUE(24.16), SIMDE_BFLOAT16_VALUE(24.16) } } },
     { {  SIMDE_BFLOAT16_VALUE(49.42), SIMDE_BFLOAT16_VALUE(2.99) },
       {  SIMDE_BFLOAT16_VALUE(-44.29), SIMDE_BFLOAT16_VALUE(-47.80)},
     { {  SIMDE_BFLOAT16_VALUE(49.42), SIMDE_BFLOAT16_VALUE(49.42), SIMDE_BFLOAT16_VALUE(49.42), SIMDE_BFLOAT16_VALUE(49.42),
        SIMDE_BFLOAT16_VALUE(49.42), SIMDE_BFLOAT16_VALUE(49.42), SIMDE_BFLOAT16_VALUE(49.42), SIMDE_BFLOAT16_VALUE(49.42) },
       {  SIMDE_BFLOAT16_VALUE(2.99), SIMDE_BFLOAT16_VALUE(2.99), SIMDE_BFLOAT16_VALUE(2.99), SIMDE_BFLOAT16_VALUE(2.99),
        SIMDE_BFLOAT16_VALUE(2.99), SIMDE_BFLOAT16_VALUE(2.99), SIMDE_BFLOAT16_VALUE(2.99), SIMDE_BFLOAT16_VALUE(2.99) } } },
     { {  SIMDE_BFLOAT16_VALUE(-4.29), SIMDE_BFLOAT16_VALUE(-21.75) },
       {  SIMDE_BFLOAT16_VALUE(18.84), SIMDE_BFLOAT16_VALUE(47.44)},
     { {  SIMDE_BFLOAT16_VALUE(-4.29), SIMDE_BFLOAT16_VALUE(-4.29), SIMDE_BFLOAT16_VALUE(-4.29), SIMDE_BFLOAT16_VALUE(-4.29),
        SIMDE_BFLOAT16_VALUE(-4.29), SIMDE_BFLOAT16_VALUE(-4.29), SIMDE_BFLOAT16_VALUE(-4.29), SIMDE_BFLOAT16_VALUE(-4.29) },
       {  SIMDE_BFLOAT16_VALUE(-21.75), SIMDE_BFLOAT16_VALUE(-21.75), SIMDE_BFLOAT16_VALUE(-21.75), SIMDE_BFLOAT16_VALUE(-21.75),
        SIMDE_BFLOAT16_VALUE(-21.75), SIMDE_BFLOAT16_VALUE(-21.75), SIMDE_BFLOAT16_VALUE(-21.75), SIMDE_BFLOAT16_VALUE(-21.75) } } },
     { {  SIMDE_BFLOAT16_VALUE(14.92), SIMDE_BFLOAT16_VALUE(32.44) },
       {  SIMDE_BFLOAT16_VALUE(32.42), SIMDE_BFLOAT16_VALUE(-11.78)},
     { {  SIMDE_BFLOAT16_VALUE(14.92), SIMDE_BFLOAT16_VALUE(14.92), SIMDE_BFLOAT16_VALUE(14.92), SIMDE_BFLOAT16_VALUE(14.92),
        SIMDE_BFLOAT16_VALUE(14.92), SIMDE_BFLOAT16_VALUE(14.92), SIMDE_BFLOAT16_VALUE(14.92), SIMDE_BFLOAT16_VALUE(14.92) },
       {  SIMDE_BFLOAT16_VALUE(32.44), SIMDE_BFLOAT16_VALUE(32.44), SIMDE_BFLOAT16_VALUE(32.44), SIMDE_BFLOAT16_VALUE(32.44),
        SIMDE_BFLOAT16_VALUE(32.44), SIMDE_BFLOAT16_VALUE(32.44), SIMDE_BFLOAT16_VALUE(32.44), SIMDE_BFLOAT16_VALUE(32.44) } } },
     { {  SIMDE_BFLOAT16_VALUE(-15.04), SIMDE_BFLOAT16_VALUE(-22.71) },
       {  SIMDE_BFLOAT16_VALUE(21.86), SIMDE_BFLOAT16_VALUE(-1.79)},
     { {  SIMDE_BFLOAT16_VALUE(-15.04), SIMDE_BFLOAT16_VALUE(-15.04), SIMDE_BFLOAT16_VALUE(-15.04), SIMDE_BFLOAT16_VALUE(-15.04),
        SIMDE_BFLOAT16_VALUE(-15.04), SIMDE_BFLOAT16_VALUE(-15.04), SIMDE_BFLOAT16_VALUE(-15.04), SIMDE_BFLOAT16_VALUE(-15.04) },
       {  SIMDE_BFLOAT16_VALUE(-22.71), SIMDE_BFLOAT16_VALUE(-22.71), SIMDE_BFLOAT16_VALUE(-22.71), SIMDE_BFLOAT16_VALUE(-22.71),
        SIMDE_BFLOAT16_VALUE(-22.71), SIMDE_BFLOAT16_VALUE(-22.71), SIMDE_BFLOAT16_VALUE(-22.71), SIMDE_BFLOAT16_VALUE(-22.71) } } },
     { {  SIMDE_BFLOAT16_VALUE(2.97), SIMDE_BFLOAT16_VALUE(23.53) },
       {  SIMDE_BFLOAT16_VALUE(-46.16), SIMDE_BFLOAT16_VALUE(23.15)},
     { {  SIMDE_BFLOAT16_VALUE(2.97), SIMDE_BFLOAT16_VALUE(2.97), SIMDE_BFLOAT16_VALUE(2.97), SIMDE_BFLOAT16_VALUE(2.97),
        SIMDE_BFLOAT16_VALUE(2.97), SIMDE_BFLOAT16_VALUE(2.97), SIMDE_BFLOAT16_VALUE(2.97), SIMDE_BFLOAT16_VALUE(2.97) },
       {  SIMDE_BFLOAT16_VALUE(23.53), SIMDE_BFLOAT16_VALUE(23.53), SIMDE_BFLOAT16_VALUE(23.53), SIMDE_BFLOAT16_VALUE(23.53),
        SIMDE_BFLOAT16_VALUE(23.53), SIMDE_BFLOAT16_VALUE(23.53), SIMDE_BFLOAT16_VALUE(23.53), SIMDE_BFLOAT16_VALUE(23.53) } } },
     { {  SIMDE_BFLOAT16_VALUE(9.52), SIMDE_BFLOAT16_VALUE(-32.92) },
       {  SIMDE_BFLOAT16_VALUE(24.32), SIMDE_BFLOAT16_VALUE(39.39)},
     { {  SIMDE_BFLOAT16_VALUE(9.52), SIMDE_BFLOAT16_VALUE(9.52), SIMDE_BFLOAT16_VALUE(9.52), SIMDE_BFLOAT16_VALUE(9.52),
        SIMDE_BFLOAT16_VALUE(9.52), SIMDE_BFLOAT16_VALUE(9.52), SIMDE_BFLOAT16_VALUE(9.52), SIMDE_BFLOAT16_VALUE(9.52) },
       {  SIMDE_BFLOAT16_VALUE(-32.92), SIMDE_BFLOAT16_VALUE(-32.92), SIMDE_BFLOAT16_VALUE(-32.92), SIMDE_BFLOAT16_VALUE(-32.92),
        SIMDE_BFLOAT16_VALUE(-32.92), SIMDE_BFLOAT16_VALUE(-32.92), SIMDE_BFLOAT16_VALUE(-32.92), SIMDE_BFLOAT16_VALUE(-32.92) } } },
     { {  SIMDE_BFLOAT16_VALUE(-26.46), SIMDE_BFLOAT16_VALUE(24.31) },
       {  SIMDE_BFLOAT16_VALUE(14.82), SIMDE_BFLOAT16_VALUE(-40.92)},
     { {  SIMDE_BFLOAT16_VALUE(-26.46), SIMDE_BFLOAT16_VALUE(-26.46), SIMDE_BFLOAT16_VALUE(-26.46), SIMDE_BFLOAT16_VALUE(-26.46),
        SIMDE_BFLOAT16_VALUE(-26.46), SIMDE_BFLOAT16_VALUE(-26.46), SIMDE_BFLOAT16_VALUE(-26.46), SIMDE_BFLOAT16_VALUE(-26.46) },
       {  SIMDE_BFLOAT16_VALUE(24.31), SIMDE_BFLOAT16_VALUE(24.31), SIMDE_BFLOAT16_VALUE(24.31), SIMDE_BFLOAT16_VALUE(24.31),
        SIMDE_BFLOAT16_VALUE(24.31), SIMDE_BFLOAT16_VALUE(24.31), SIMDE_BFLOAT16_VALUE(24.31), SIMDE_BFLOAT16_VALUE(24.31) } } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8x2_t r = simde_vld2q_dup_bf16(test_vec[i].a);
    simde_bfloat16x8x2_t expected = {
        {simde_vld1q_bf16(test_vec[i].r[0]), simde_vld1q_bf16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_bf16x8(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_bf16x8(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_dup_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_dup_bf16)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
