#define SIMDE_TEST_ARM_NEON_INSN cvt_n

#include "test-neon.h"
#include "../../../simde/arm/neon/cvt_n.h"

static int
test_simde_vcvt_n_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[4];
    int32_t n;
    int16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_C(0.0), SIMDE_FLOAT16_C(9.7), SIMDE_FLOAT16_C(4.3), SIMDE_FLOAT16_C(-2.6) },
        INT16_C(11),
      { INT16_C(0), INT16_C(87), INT16_C(38), -INT16_C(23) } },
    { { SIMDE_FLOAT16_C(-2.1), SIMDE_FLOAT16_C(-6.7), SIMDE_FLOAT16_C(3.7), SIMDE_FLOAT16_C(2.4) },
        INT16_C(10),
      { -INT16_C(16), -INT16_C(53), INT16_C(29), INT16_C(19) } },
    { { SIMDE_FLOAT16_C(-3.8), SIMDE_FLOAT16_C(-3.7), SIMDE_FLOAT16_C(-9.4), SIMDE_FLOAT16_C(-8.7) },
        INT16_C(9),
      { -INT16_C(41), -INT16_C(40), -INT16_C(103), -INT16_C(95) } },
    { { SIMDE_FLOAT16_C(-6.6), SIMDE_FLOAT16_C(-1.8), SIMDE_FLOAT16_C(-1.9), SIMDE_FLOAT16_C(-1.4) },
        INT16_C(7),
      { -INT16_C(33), -INT16_C(9), -INT16_C(9), -INT16_C(7) } },
    { { SIMDE_FLOAT16_C(-2.6), SIMDE_FLOAT16_C(2.9), SIMDE_FLOAT16_C(8.5), SIMDE_FLOAT16_C(-6.6) },
        INT16_C(13),
      { -INT16_C(39), INT16_C(43), INT16_C(127), -INT16_C(99) } },
    { { SIMDE_FLOAT16_C(4.7), SIMDE_FLOAT16_C(-0.7), SIMDE_FLOAT16_C(-7.9), SIMDE_FLOAT16_C(-4.7) },
        INT16_C(15),
      { INT16_C(61), -INT16_C(9), -INT16_C(102), -INT16_C(61) } },
    { { SIMDE_FLOAT16_C(9.9), SIMDE_FLOAT16_C(-9.7), SIMDE_FLOAT16_C(-7.7), SIMDE_FLOAT16_C(9.9) },
        INT16_C(16),
      { INT16_C(178), -INT16_C(174), -INT16_C(138), INT16_C(178) } },
    { { SIMDE_FLOAT16_C(-5.1), SIMDE_FLOAT16_C(-2.3), SIMDE_FLOAT16_C(9.4), SIMDE_FLOAT16_C(-3.8) },
        INT16_C(8),
      { -INT16_C(51), -INT16_C(23), INT16_C(94), -INT16_C(38) } },
    { { SIMDE_FLOAT16_C(-4.8), SIMDE_FLOAT16_C(4.0), SIMDE_FLOAT16_C(9.2), SIMDE_FLOAT16_C(-0.5) },
        INT16_C(2),
      { INT16_C(0), INT16_C(0), INT16_C(0), INT16_C(0) } },
    { { SIMDE_FLOAT16_C(-6.5), SIMDE_FLOAT16_C(3.7), SIMDE_FLOAT16_C(-8.5), SIMDE_FLOAT16_C(6.4) },
        INT16_C(1),
      { -INT16_C(19), INT16_C(11), -INT16_C(25), INT16_C(19) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_int16x4_t r = simde_vcvt_n_s16_f16(a, test_vec[i].n);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvt_n_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[2];
    int32_t n;
    int32_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(1000.0),
          HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) - SIMDE_FLOAT32_C(1000.0) },
        1,
        {              INT32_MAX,              INT32_MIN } },
      { {        SIMDE_MATH_NANF,   SIMDE_MATH_INFINITYF },
        1,
        {  INT32_C(           0),              INT32_MAX } },
    #endif
    { { SIMDE_FLOAT32_C(-742.644201021157), SIMDE_FLOAT32_C(362.2242136738157) },
        INT32_C(1),
      { -INT32_C(2227), INT32_C(1086) } },
    { { SIMDE_FLOAT32_C(210.13494831935031), SIMDE_FLOAT32_C(-160.0159651287372) },
        INT32_C(10),
      { INT32_C(1681), -INT32_C(1280) } },
    { { SIMDE_FLOAT32_C(609.5223236525342), SIMDE_FLOAT32_C(169.65110860918162) },
        INT32_C(13),
      { INT32_C(9142), INT32_C(2544) } },
    { { SIMDE_FLOAT32_C(145.65077413025347), SIMDE_FLOAT32_C(-236.2218958550153) },
        INT32_C(24),
      { INT32_C(3786), -INT32_C(6141) } },
    { { SIMDE_FLOAT32_C(-18.631628667305563), SIMDE_FLOAT32_C(-432.625264605253) },
        INT32_C(29),
      { -INT32_C(577), -INT32_C(13411) } },
    { { SIMDE_FLOAT32_C(-560.0382012578748), SIMDE_FLOAT32_C(-819.9654179215612) },
        INT32_C(3),
      { -INT32_C(560), -INT32_C(819) } },
    { { SIMDE_FLOAT32_C(-447.99045767836463), SIMDE_FLOAT32_C(102.47425021777917) },
        INT32_C(14),
      { -INT32_C(5375), INT32_C(1229) } },
    { { SIMDE_FLOAT32_C(-755.3698865720435), SIMDE_FLOAT32_C(869.9981047441252) },
        INT32_C(7),
      { -INT32_C(3776), INT32_C(4349) } },
    { { SIMDE_FLOAT32_C(-125.6842530507032), SIMDE_FLOAT32_C(-509.20033358174936) },
        INT32_C(19),
      { -INT32_C(2136), -INT32_C(8656) } },
    { { SIMDE_FLOAT32_C(-450.56595469104013), SIMDE_FLOAT32_C(732.4348761156855) },
        INT32_C(16),
      { -INT32_C(8110), INT32_C(13183) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_int32x2_t r = simde_vcvt_n_s32_f32(a, test_vec[i].n);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvt_n_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[1];
    int32_t n;
    int64_t r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0) },
        3,
        { INT64_MAX } },
      { { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) - SIMDE_FLOAT64_C(10000.0) },
        6,
        { INT64_MIN } },
      { { SIMDE_MATH_NAN },
        9,
        {  INT64_C(0) } },
    #endif
    { { SIMDE_FLOAT64_C(354.574) },
        INT64_C(32),
      { INT64_C(12055) } },
    { { SIMDE_FLOAT64_C(-172.008) },
        INT64_C(41),
      { -INT64_C(7396) } },
    { { SIMDE_FLOAT64_C(-654.989) },
        INT64_C(42),
      { -INT64_C(26199) } },
    { { SIMDE_FLOAT64_C(-596.727) },
        INT64_C(23),
      { -INT64_C(12531) } },
    { { SIMDE_FLOAT64_C(390.197) },
        INT64_C(3),
      { INT64_C(390) } },
    { { SIMDE_FLOAT64_C(339.776) },
        INT64_C(46),
      { INT64_C(14950) } },
    { { SIMDE_FLOAT64_C(-375.425) },
        INT64_C(23),
      { -INT64_C(7883) } },
    { { SIMDE_FLOAT64_C(584.183) },
        INT64_C(34),
      { INT64_C(18693) } },
    { { SIMDE_FLOAT64_C(499.646) },
        INT64_C(6),
      { INT64_C(1998) } },
    { { SIMDE_FLOAT64_C(-505.025) },
        INT64_C(8),
      { -INT64_C(5050) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_int64x1_t r = simde_vcvt_n_s64_f64(a, test_vec[i].n);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvt_n_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[4];
    int32_t n;
    uint16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_C(5.6), SIMDE_FLOAT16_C(7.4), SIMDE_FLOAT16_C(9.1), SIMDE_FLOAT16_C(7.9) },
        UINT16_C(4),
      { UINT16_C(33), UINT16_C(44), UINT16_C(54), UINT16_C(47) } },
    { { SIMDE_FLOAT16_C(10.0), SIMDE_FLOAT16_C(7.9), SIMDE_FLOAT16_C(4.2), SIMDE_FLOAT16_C(6.5) },
        UINT16_C(15),
      { UINT16_C(130), UINT16_C(102), UINT16_C(54), UINT16_C(84) } },
    { { SIMDE_FLOAT16_C(0.9), SIMDE_FLOAT16_C(8.6), SIMDE_FLOAT16_C(9.1), SIMDE_FLOAT16_C(9.8) },
        UINT16_C(1),
      { UINT16_C(2), UINT16_C(25), UINT16_C(27), UINT16_C(29) } },
    { { SIMDE_FLOAT16_C(7.9), SIMDE_FLOAT16_C(2.4), SIMDE_FLOAT16_C(3.1), SIMDE_FLOAT16_C(3.7) },
        UINT16_C(16),
      { UINT16_C(142), UINT16_C(43), UINT16_C(55), UINT16_C(66) } },
    { { SIMDE_FLOAT16_C(10.0), SIMDE_FLOAT16_C(9.9), SIMDE_FLOAT16_C(2.3), SIMDE_FLOAT16_C(5.1) },
        UINT16_C(4),
      { UINT16_C(60), UINT16_C(59), UINT16_C(13), UINT16_C(30) } },
    { { SIMDE_FLOAT16_C(1.5), SIMDE_FLOAT16_C(8.2), SIMDE_FLOAT16_C(4.5), SIMDE_FLOAT16_C(7.8) },
        UINT16_C(13),
      { UINT16_C(22), UINT16_C(123), UINT16_C(67), UINT16_C(117) } },
    { { SIMDE_FLOAT16_C(3.9), SIMDE_FLOAT16_C(5.4), SIMDE_FLOAT16_C(3.6), SIMDE_FLOAT16_C(1.5) },
        UINT16_C(14),
      { UINT16_C(46), UINT16_C(64), UINT16_C(43), UINT16_C(18) } },
    { { SIMDE_FLOAT16_C(1.0), SIMDE_FLOAT16_C(10.0), SIMDE_FLOAT16_C(9.7), SIMDE_FLOAT16_C(7.8) },
        UINT16_C(4),
      { UINT16_C(6), UINT16_C(60), UINT16_C(58), UINT16_C(46) } },
    { { SIMDE_FLOAT16_C(5.0), SIMDE_FLOAT16_C(0.2), SIMDE_FLOAT16_C(7.0), SIMDE_FLOAT16_C(8.1) },
        UINT16_C(4),
      { UINT16_C(30), UINT16_C(1), UINT16_C(42), UINT16_C(48) } },
    { { SIMDE_FLOAT16_C(8.4), SIMDE_FLOAT16_C(4.0), SIMDE_FLOAT16_C(5.4), SIMDE_FLOAT16_C(3.6) },
        UINT16_C(7),
      { UINT16_C(42), UINT16_C(20), UINT16_C(27), UINT16_C(18) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcvt_n_u16_f16(a, test_vec[i].n);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvt_n_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[2];
    int32_t n;
    uint32_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(1000.0) },
        3,
        { UINT32_MAX } },
      { { -SIMDE_FLOAT32_C(1000.0) },
        6,
        { INT32_C(0) } },
      { { SIMDE_MATH_NAN },
        9,
        { INT32_C(0) } },
    #endif
    { { SIMDE_FLOAT32_C(-599.745), SIMDE_FLOAT32_C(-150.48) },
        INT32_C(14),
      { INT32_C(0), INT32_C(0) } },
    { { SIMDE_FLOAT32_C(-270.483), SIMDE_FLOAT32_C(-471.806) },
        INT32_C(32),
      { INT32_C(0), INT32_C(0) } },
    { { SIMDE_FLOAT32_C(633.891), SIMDE_FLOAT32_C(452.152) },
        INT32_C(25),
      { UINT32_C(17115), UINT32_C(12208) } },
    { { SIMDE_FLOAT32_C(157.297), SIMDE_FLOAT32_C(402.484) },
        INT32_C(25),
      { UINT32_C(4247), UINT32_C(10867) } },
    { { SIMDE_FLOAT32_C(633.453), SIMDE_FLOAT32_C(528.98) },
        INT32_C(21),
      { UINT32_C(14569), UINT32_C(12166) } },
    { { SIMDE_FLOAT32_C(-77.493), SIMDE_FLOAT32_C(272.346) },
        INT32_C(28),
      { INT32_C(0), UINT32_C(8170) } },
    { { SIMDE_FLOAT32_C(648.015), SIMDE_FLOAT32_C(210.352) },
        INT32_C(8),
      { UINT32_C(6480), UINT32_C(2103) } },
    { { SIMDE_FLOAT32_C(-295.362), SIMDE_FLOAT32_C(187.507) },
        INT32_C(27),
      { INT32_C(0), UINT32_C(4687) } },
    { { SIMDE_FLOAT32_C(-452.522), SIMDE_FLOAT32_C(-544.087) },
        INT32_C(3),
      { INT32_C(0), INT32_C(0) } },
    { { SIMDE_FLOAT32_C(64.965), SIMDE_FLOAT32_C(-317.315) },
        INT32_C(2),
      { UINT32_C(0), UINT32_C(0) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcvt_n_u32_f32(a, test_vec[i].n);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvt_n_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[1];
    int32_t n;
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(944.4656) },
        INT32_C(13),
      { UINT64_C(14166) } },
    { { SIMDE_FLOAT64_C(337.1491) },
        INT32_C(30),
      { UINT64_C(9440) } },
    { { SIMDE_FLOAT64_C(249.7855) },
        INT32_C(12),
      { UINT64_C(3496) } },
    { { SIMDE_FLOAT64_C(416.7374) },
        INT32_C(60),
      { UINT64_C(25837) } },
    { { SIMDE_FLOAT64_C(50.4166) },
        INT32_C(18),
      { UINT64_C(806) } },
    { { SIMDE_FLOAT64_C(136.0392) },
        INT32_C(2),
      { UINT64_C(0) } },
    { { SIMDE_FLOAT64_C(64.8793) },
        INT32_C(6),
      { UINT64_C(259) } },
    { { SIMDE_FLOAT64_C(797.5769) },
        INT32_C(63),
      { UINT64_C(48652) } },
    { { SIMDE_FLOAT64_C(65.6367) },
        INT32_C(26),
      { UINT64_C(1575) } },
    { { SIMDE_FLOAT64_C(41.6920) },
        INT32_C(30),
      { UINT64_C(1167) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcvt_n_u64_f64(a, test_vec[i].n);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtq_n_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[8];
    int32_t n;
    int16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_C(7.7), SIMDE_FLOAT16_C(4.8), SIMDE_FLOAT16_C(4.8), SIMDE_FLOAT16_C(4.9),
        SIMDE_FLOAT16_C(9.7), SIMDE_FLOAT16_C(8.5), SIMDE_FLOAT16_C(5.1), SIMDE_FLOAT16_C(2.7) },
        INT32_C(14),
      { INT16_C(92), INT16_C(57), INT16_C(57), INT16_C(58),
        INT16_C(116), INT16_C(102), INT16_C(61), INT16_C(32) } },
    { { SIMDE_FLOAT16_C(4.4), SIMDE_FLOAT16_C(1.1), SIMDE_FLOAT16_C(3.4), SIMDE_FLOAT16_C(6.4),
        SIMDE_FLOAT16_C(8.6), SIMDE_FLOAT16_C(7.4), SIMDE_FLOAT16_C(1.4), SIMDE_FLOAT16_C(1.9) },
        INT32_C(6),
      { INT16_C(17), INT16_C(4), INT16_C(13), INT16_C(25),
        INT16_C(34), INT16_C(29), INT16_C(5), INT16_C(7) } },
    { { SIMDE_FLOAT16_C(6.5), SIMDE_FLOAT16_C(2.6), SIMDE_FLOAT16_C(3.2), SIMDE_FLOAT16_C(5.9),
        SIMDE_FLOAT16_C(8.3), SIMDE_FLOAT16_C(4.7), SIMDE_FLOAT16_C(7.0), SIMDE_FLOAT16_C(8.0) },
        INT32_C(6),
      { INT16_C(26), INT16_C(10), INT16_C(12), INT16_C(23),
        INT16_C(33), INT16_C(18), INT16_C(28), INT16_C(32) } },
    { { SIMDE_FLOAT16_C(4.0), SIMDE_FLOAT16_C(5.8), SIMDE_FLOAT16_C(7.3), SIMDE_FLOAT16_C(1.6),
        SIMDE_FLOAT16_C(3.2), SIMDE_FLOAT16_C(4.0), SIMDE_FLOAT16_C(7.2), SIMDE_FLOAT16_C(0.4) },
        INT32_C(4),
      { INT16_C(24), INT16_C(34), INT16_C(43), INT16_C(9),
        INT16_C(19), INT16_C(24), INT16_C(43), INT16_C(2) } },
    { { SIMDE_FLOAT16_C(9.4), SIMDE_FLOAT16_C(1.8), SIMDE_FLOAT16_C(1.2), SIMDE_FLOAT16_C(4.8),
        SIMDE_FLOAT16_C(3.9), SIMDE_FLOAT16_C(5.0), SIMDE_FLOAT16_C(9.3), SIMDE_FLOAT16_C(4.9) },
        INT32_C(15),
      { INT16_C(122), INT16_C(23), INT16_C(15), INT16_C(62),
        INT16_C(50), INT16_C(65), INT16_C(120), INT16_C(63) } },
    { { SIMDE_FLOAT16_C(4.4), SIMDE_FLOAT16_C(9.5), SIMDE_FLOAT16_C(9.1), SIMDE_FLOAT16_C(6.9),
        SIMDE_FLOAT16_C(2.7), SIMDE_FLOAT16_C(8.7), SIMDE_FLOAT16_C(7.3), SIMDE_FLOAT16_C(5.1) },
        INT32_C(4),
      { INT16_C(26), INT16_C(57), INT16_C(54), INT16_C(41),
        INT16_C(16), INT16_C(52), INT16_C(43), INT16_C(30) } },
    { { SIMDE_FLOAT16_C(4.5), SIMDE_FLOAT16_C(5.9), SIMDE_FLOAT16_C(5.3), SIMDE_FLOAT16_C(3.5),
        SIMDE_FLOAT16_C(4.0), SIMDE_FLOAT16_C(6.8), SIMDE_FLOAT16_C(3.4), SIMDE_FLOAT16_C(0.5) },
        INT32_C(1),
      { INT16_C(13), INT16_C(17), INT16_C(15), INT16_C(10),
        INT16_C(12), INT16_C(20), INT16_C(10), INT16_C(1) } },
    { { SIMDE_FLOAT16_C(7.6), SIMDE_FLOAT16_C(9.7), SIMDE_FLOAT16_C(6.6), SIMDE_FLOAT16_C(0.0),
        SIMDE_FLOAT16_C(4.4), SIMDE_FLOAT16_C(6.8), SIMDE_FLOAT16_C(7.3), SIMDE_FLOAT16_C(0.1) },
        INT32_C(7),
      { INT16_C(38), INT16_C(48), INT16_C(33), INT16_C(0),
        INT16_C(22), INT16_C(34), INT16_C(36), INT16_C(0) } },
    { { SIMDE_FLOAT16_C(0.2), SIMDE_FLOAT16_C(4.0), SIMDE_FLOAT16_C(2.5), SIMDE_FLOAT16_C(4.8),
        SIMDE_FLOAT16_C(4.2), SIMDE_FLOAT16_C(7.9), SIMDE_FLOAT16_C(1.2), SIMDE_FLOAT16_C(4.0) },
        INT32_C(13),
      { INT16_C(3), INT16_C(60), INT16_C(37), INT16_C(72),
        INT16_C(63), INT16_C(118), INT16_C(18), INT16_C(60) } },
    { { SIMDE_FLOAT16_C(7.7), SIMDE_FLOAT16_C(4.8), SIMDE_FLOAT16_C(5.4), SIMDE_FLOAT16_C(7.4),
        SIMDE_FLOAT16_C(6.2), SIMDE_FLOAT16_C(1.7), SIMDE_FLOAT16_C(9.6), SIMDE_FLOAT16_C(4.9) },
        INT32_C(2),
      { INT16_C(0), INT16_C(0), INT16_C(0), INT16_C(0),
        INT16_C(0), INT16_C(0), INT16_C(0), INT16_C(0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_int16x8_t r = simde_vcvtq_n_s16_f16(a, test_vec[i].n);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtq_n_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[4];
    int32_t n;
    int32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(905.4), SIMDE_FLOAT32_C(440.7), SIMDE_FLOAT32_C(232.8), SIMDE_FLOAT32_C(179.5) },
        INT32_C(9),
      { INT32_C(9959), INT32_C(4847), INT32_C(2560), INT32_C(1974) } },
    { { SIMDE_FLOAT32_C(386.9), SIMDE_FLOAT32_C(880.3), SIMDE_FLOAT32_C(184.4), SIMDE_FLOAT32_C(747.7) },
        INT32_C(12),
      { INT32_C(5416), INT32_C(12324), INT32_C(2581), INT32_C(10467) } },
    { { SIMDE_FLOAT32_C(912.2), SIMDE_FLOAT32_C(448.2), SIMDE_FLOAT32_C(300.6), SIMDE_FLOAT32_C(529.0) },
        INT32_C(10),
      { INT32_C(7297), INT32_C(3585), INT32_C(2404), INT32_C(4232) } },
    { { SIMDE_FLOAT32_C(865.6), SIMDE_FLOAT32_C(186.1), SIMDE_FLOAT32_C(29.5), SIMDE_FLOAT32_C(497.0) },
        INT32_C(4),
      { INT32_C(5193), INT32_C(1116), INT32_C(177), INT32_C(2982) } },
    { { SIMDE_FLOAT32_C(249.0), SIMDE_FLOAT32_C(337.0), SIMDE_FLOAT32_C(782.7), SIMDE_FLOAT32_C(173.3) },
        INT32_C(1),
      { INT32_C(747), INT32_C(1011), INT32_C(2348), INT32_C(519) } },
    { { SIMDE_FLOAT32_C(464.0), SIMDE_FLOAT32_C(567.7), SIMDE_FLOAT32_C(547.5), SIMDE_FLOAT32_C(181.4) },
        INT32_C(29),
      { INT32_C(14384), INT32_C(17598), INT32_C(16972), INT32_C(5623) } },
    { { SIMDE_FLOAT32_C(510.2), SIMDE_FLOAT32_C(536.9), SIMDE_FLOAT32_C(67.8), SIMDE_FLOAT32_C(83.8) },
        INT32_C(7),
      { INT32_C(2551), INT32_C(2684), INT32_C(339), INT32_C(419) } },
    { { SIMDE_FLOAT32_C(63.0), SIMDE_FLOAT32_C(408.8), SIMDE_FLOAT32_C(793.2), SIMDE_FLOAT32_C(54.4) },
        INT32_C(5),
      { INT32_C(441), INT32_C(2861), INT32_C(5552), INT32_C(380) } },
    { { SIMDE_FLOAT32_C(272.4), SIMDE_FLOAT32_C(136.1), SIMDE_FLOAT32_C(929.9), SIMDE_FLOAT32_C(856.5) },
        INT32_C(7),
      { INT32_C(1362), INT32_C(680), INT32_C(4649), INT32_C(4282) } },
    { { SIMDE_FLOAT32_C(284.5), SIMDE_FLOAT32_C(508.8), SIMDE_FLOAT32_C(154.3), SIMDE_FLOAT32_C(186.6) },
        INT32_C(21),
      { INT32_C(6543), INT32_C(11702), INT32_C(3548), INT32_C(4291) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_int32x4_t r = simde_vcvtq_n_s32_f32(a, test_vec[i].n);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtq_n_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[2];
    int32_t n;
    int64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(377.2054), SIMDE_FLOAT64_C(820.1639) },
        INT32_C(13),
      { INT64_C(5658), INT64_C(12302) } },
    { { SIMDE_FLOAT64_C(111.2393), SIMDE_FLOAT64_C(231.2226) },
        INT32_C(59),
      { INT64_C(6340), INT64_C(13179) } },
    { { SIMDE_FLOAT64_C(538.5625), SIMDE_FLOAT64_C(342.8885) },
        INT32_C(17),
      { INT64_C(10232), INT64_C(6514) } },
    { { SIMDE_FLOAT64_C(592.5572), SIMDE_FLOAT64_C(348.9751) },
        INT32_C(2),
      { INT64_C(0), INT64_C(0) } },
    { { SIMDE_FLOAT64_C(13.4362), SIMDE_FLOAT64_C(992.6178) },
        INT32_C(8),
      { INT64_C(134), INT64_C(9926) } },
    { { SIMDE_FLOAT64_C(605.6133), SIMDE_FLOAT64_C(896.8283) },
        INT32_C(5),
      { INT64_C(4239), INT64_C(6277) } },
    { { SIMDE_FLOAT64_C(957.8787), SIMDE_FLOAT64_C(776.8960) },
        INT32_C(41),
      { INT64_C(41188), INT64_C(33406) } },
    { { SIMDE_FLOAT64_C(936.3104), SIMDE_FLOAT64_C(810.4760) },
        INT32_C(10),
      { INT64_C(7490), INT64_C(6483) } },
    { { SIMDE_FLOAT64_C(854.5740), SIMDE_FLOAT64_C(672.1653) },
        INT32_C(52),
      { INT64_C(46146), INT64_C(36296) } },
    { { SIMDE_FLOAT64_C(706.5375), SIMDE_FLOAT64_C(286.5603) },
        INT32_C(60),
      { INT64_C(43805), INT64_C(17766) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_int64x2_t r = simde_vcvtq_n_s64_f64(a, test_vec[i].n);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtq_n_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[8];
    int32_t n;
    uint16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_C(1.8), SIMDE_FLOAT16_C(6.0), SIMDE_FLOAT16_C(6.6), SIMDE_FLOAT16_C(8.9),
        SIMDE_FLOAT16_C(2.6), SIMDE_FLOAT16_C(8.4), SIMDE_FLOAT16_C(3.0), SIMDE_FLOAT16_C(1.8) },
        UINT16_C(11),
      { UINT16_C(16), UINT16_C(54), UINT16_C(59), UINT16_C(80),
        UINT16_C(23), UINT16_C(75), UINT16_C(27), UINT16_C(16) } },
    { { SIMDE_FLOAT16_C(4.7), SIMDE_FLOAT16_C(7.7), SIMDE_FLOAT16_C(1.9), SIMDE_FLOAT16_C(0.8),
        SIMDE_FLOAT16_C(4.8), SIMDE_FLOAT16_C(6.8), SIMDE_FLOAT16_C(9.2), SIMDE_FLOAT16_C(6.4) },
        UINT16_C(4),
      { UINT16_C(28), UINT16_C(46), UINT16_C(11), UINT16_C(4),
        UINT16_C(28), UINT16_C(40), UINT16_C(55), UINT16_C(38) } },
    { { SIMDE_FLOAT16_C(6.5), SIMDE_FLOAT16_C(6.7), SIMDE_FLOAT16_C(4.7), SIMDE_FLOAT16_C(6.5),
        SIMDE_FLOAT16_C(0.7), SIMDE_FLOAT16_C(5.4), SIMDE_FLOAT16_C(8.3), SIMDE_FLOAT16_C(2.7) },
        UINT16_C(14),
      { UINT16_C(78), UINT16_C(80), UINT16_C(56), UINT16_C(78),
        UINT16_C(8), UINT16_C(64), UINT16_C(99), UINT16_C(32) } },
    { { SIMDE_FLOAT16_C(4.1), SIMDE_FLOAT16_C(9.7), SIMDE_FLOAT16_C(0.3), SIMDE_FLOAT16_C(2.8),
        SIMDE_FLOAT16_C(2.5), SIMDE_FLOAT16_C(9.5), SIMDE_FLOAT16_C(0.5), SIMDE_FLOAT16_C(1.1) },
        UINT16_C(13),
      { UINT16_C(61), UINT16_C(145), UINT16_C(4), UINT16_C(42),
        UINT16_C(37), UINT16_C(142), UINT16_C(7), UINT16_C(16) } },
    { { SIMDE_FLOAT16_C(5.2), SIMDE_FLOAT16_C(9.9), SIMDE_FLOAT16_C(6.9), SIMDE_FLOAT16_C(0.6),
        SIMDE_FLOAT16_C(3.6), SIMDE_FLOAT16_C(8.2), SIMDE_FLOAT16_C(0.2), SIMDE_FLOAT16_C(0.1) },
        UINT16_C(12),
      { UINT16_C(72), UINT16_C(138), UINT16_C(96), UINT16_C(8),
        UINT16_C(50), UINT16_C(114), UINT16_C(2), UINT16_C(1) } },
    { { SIMDE_FLOAT16_C(1.1), SIMDE_FLOAT16_C(8.9), SIMDE_FLOAT16_C(9.2), SIMDE_FLOAT16_C(1.4),
        SIMDE_FLOAT16_C(9.0), SIMDE_FLOAT16_C(0.3), SIMDE_FLOAT16_C(3.0), SIMDE_FLOAT16_C(3.8) },
        UINT16_C(7),
      { UINT16_C(5), UINT16_C(44), UINT16_C(46), UINT16_C(7),
        UINT16_C(45), UINT16_C(1), UINT16_C(15), UINT16_C(19) } },
    { { SIMDE_FLOAT16_C(4.3), SIMDE_FLOAT16_C(4.2), SIMDE_FLOAT16_C(1.2), SIMDE_FLOAT16_C(1.0),
        SIMDE_FLOAT16_C(7.2), SIMDE_FLOAT16_C(0.2), SIMDE_FLOAT16_C(5.2), SIMDE_FLOAT16_C(1.6) },
        UINT16_C(5),
      { UINT16_C(30), UINT16_C(29), UINT16_C(8), UINT16_C(7),
        UINT16_C(50), UINT16_C(1), UINT16_C(36), UINT16_C(11) } },
    { { SIMDE_FLOAT16_C(2.5), SIMDE_FLOAT16_C(0.9), SIMDE_FLOAT16_C(5.1), SIMDE_FLOAT16_C(8.9),
        SIMDE_FLOAT16_C(2.7), SIMDE_FLOAT16_C(9.7), SIMDE_FLOAT16_C(2.5), SIMDE_FLOAT16_C(3.3) },
        UINT16_C(13),
      { UINT16_C(37), UINT16_C(13), UINT16_C(76), UINT16_C(133),
        UINT16_C(40), UINT16_C(145), UINT16_C(37), UINT16_C(49) } },
    { { SIMDE_FLOAT16_C(4.4), SIMDE_FLOAT16_C(7.0), SIMDE_FLOAT16_C(0.9), SIMDE_FLOAT16_C(8.4),
        SIMDE_FLOAT16_C(9.2), SIMDE_FLOAT16_C(1.8), SIMDE_FLOAT16_C(3.1), SIMDE_FLOAT16_C(2.8) },
        UINT16_C(2),
      { UINT16_C(0), UINT16_C(0), UINT16_C(0), UINT16_C(0),
        UINT16_C(0), UINT16_C(0), UINT16_C(0), UINT16_C(0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcvtq_n_u16_f16(a, test_vec[i].n);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtq_n_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[4];
    int32_t n;
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(661.7), SIMDE_FLOAT32_C(867.1), SIMDE_FLOAT32_C(218.0), SIMDE_FLOAT32_C(845.7) },
        UINT32_C(4),
      { UINT32_C(3970), UINT32_C(5202), UINT32_C(1308), UINT32_C(5074) } },
    { { SIMDE_FLOAT32_C(773.4), SIMDE_FLOAT32_C(576.6), SIMDE_FLOAT32_C(840.2), SIMDE_FLOAT32_C(92.4) },
        UINT32_C(5),
      { UINT32_C(5413), UINT32_C(4036), UINT32_C(5881), UINT32_C(646) } },
    { { SIMDE_FLOAT32_C(710.4), SIMDE_FLOAT32_C(311.1), SIMDE_FLOAT32_C(91.4), SIMDE_FLOAT32_C(471.7) },
        UINT32_C(6),
      { UINT32_C(2841), UINT32_C(1244), UINT32_C(365), UINT32_C(1886) } },
    { { SIMDE_FLOAT32_C(618.6), SIMDE_FLOAT32_C(853.1), SIMDE_FLOAT32_C(703.5), SIMDE_FLOAT32_C(107.9) },
        UINT32_C(13),
      { UINT32_C(9279), UINT32_C(12796), UINT32_C(10552), UINT32_C(1618) } },
    { { SIMDE_FLOAT32_C(522.0), SIMDE_FLOAT32_C(785.1), SIMDE_FLOAT32_C(153.3), SIMDE_FLOAT32_C(172.0) },
        UINT32_C(6),
      { UINT32_C(2088), UINT32_C(3140), UINT32_C(613), UINT32_C(688) } },
    { { SIMDE_FLOAT32_C(176.6), SIMDE_FLOAT32_C(53.8), SIMDE_FLOAT32_C(252.0), SIMDE_FLOAT32_C(975.5) },
        UINT32_C(5),
      { UINT32_C(1236), UINT32_C(376), UINT32_C(1764), UINT32_C(6828) } },
    { { SIMDE_FLOAT32_C(628.1), SIMDE_FLOAT32_C(792.7), SIMDE_FLOAT32_C(597.1), SIMDE_FLOAT32_C(699.4) },
        UINT32_C(4),
      { UINT32_C(3768), UINT32_C(4756), UINT32_C(3582), UINT32_C(4196) } },
    { { SIMDE_FLOAT32_C(558.4), SIMDE_FLOAT32_C(54.4), SIMDE_FLOAT32_C(311.3), SIMDE_FLOAT32_C(106.9) },
        UINT32_C(32),
      { UINT32_C(18985), UINT32_C(1849), UINT32_C(10584), UINT32_C(3634) } },
    { { SIMDE_FLOAT32_C(41.0), SIMDE_FLOAT32_C(910.5), SIMDE_FLOAT32_C(891.0), SIMDE_FLOAT32_C(162.6) },
        UINT32_C(25),
      { UINT32_C(1107), UINT32_C(24583), UINT32_C(24057), UINT32_C(4390) } },
    { { SIMDE_FLOAT32_C(832.0), SIMDE_FLOAT32_C(512.7), SIMDE_FLOAT32_C(534.8), SIMDE_FLOAT32_C(977.7) },
        UINT32_C(2),
      { UINT32_C(0), UINT32_C(0), UINT32_C(0), UINT32_C(0) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcvtq_n_u32_f32(a, test_vec[i].n);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcvtq_n_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[2];
    int32_t n;
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(783.0312), SIMDE_FLOAT64_C(378.2593) },
        INT32_C(19),
      { UINT64_C(13311), UINT64_C(6430) } },
    { { SIMDE_FLOAT64_C(293.4481), SIMDE_FLOAT64_C(444.8110) },
        INT32_C(2),
      { UINT64_C(0), UINT64_C(0) } },
    { { SIMDE_FLOAT64_C(55.6421), SIMDE_FLOAT64_C(433.0257) },
        INT32_C(59),
      { UINT64_C(3171), UINT64_C(24682) } },
    { { SIMDE_FLOAT64_C(592.6953), SIMDE_FLOAT64_C(904.6588) },
        INT32_C(61),
      { UINT64_C(37339), UINT64_C(56993) } },
    { { SIMDE_FLOAT64_C(859.7336), SIMDE_FLOAT64_C(768.8291) },
        INT32_C(17),
      { UINT64_C(16334), UINT64_C(14607) } },
    { { SIMDE_FLOAT64_C(842.2237), SIMDE_FLOAT64_C(390.3714) },
        INT32_C(43),
      { UINT64_C(34531), UINT64_C(16005) } },
    { { SIMDE_FLOAT64_C(27.8951), SIMDE_FLOAT64_C(219.0477) },
        INT32_C(38),
      { UINT64_C(1004), UINT64_C(7885) } },
    { { SIMDE_FLOAT64_C(813.1943), SIMDE_FLOAT64_C(113.7207) },
        INT32_C(55),
      { UINT64_C(43099), UINT64_C(6027) } },
    { { SIMDE_FLOAT64_C(745.5396), SIMDE_FLOAT64_C(806.7791) },
        INT32_C(42),
      { UINT64_C(29821), UINT64_C(32271) } },
    { { SIMDE_FLOAT64_C(784.0902), SIMDE_FLOAT64_C(898.5282) },
        INT32_C(21),
      { UINT64_C(18034), UINT64_C(20666) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcvtq_n_u64_f64(a, test_vec[i].n);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

/*
static int
test_simde_vcvt_n_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int32_t n;
    simde_float16 r[4];
  } test_vec[] = {
    { { INT16_C(1), INT16_C(5), INT16_C(5), INT16_C(8) },
        INT32_C(9),
      { SIMDE_FLOAT16_C(0.1), SIMDE_FLOAT16_C(0.5), SIMDE_FLOAT16_C(0.5), SIMDE_FLOAT16_C(0.7) } },
    { { INT16_C(2), INT16_C(6), INT16_C(7), INT16_C(1) },
        INT32_C(13),
      { SIMDE_FLOAT16_C(0.1), SIMDE_FLOAT16_C(0.4), SIMDE_FLOAT16_C(0.5), SIMDE_FLOAT16_C(0.1) } },
    { { INT16_C(1), INT16_C(9), INT16_C(8), INT16_C(9) },
        INT32_C(12),
      { SIMDE_FLOAT16_C(0.1), SIMDE_FLOAT16_C(0.6), SIMDE_FLOAT16_C(0.6), SIMDE_FLOAT16_C(0.6) } },
    { { INT16_C(5), INT16_C(6), INT16_C(1), INT16_C(6) },
        INT32_C(3),
      { SIMDE_FLOAT16_C(5.0), SIMDE_FLOAT16_C(6.0), SIMDE_FLOAT16_C(1.0), SIMDE_FLOAT16_C(6.0) } },
    { { INT16_C(1), INT16_C(0), INT16_C(3), INT16_C(8) },
        INT32_C(5),
      { SIMDE_FLOAT16_C(0.1), SIMDE_FLOAT16_C(0.0), SIMDE_FLOAT16_C(0.4), SIMDE_FLOAT16_C(1.1) } },
    { { INT16_C(5), INT16_C(9), INT16_C(0), INT16_C(0) },
        INT32_C(4),
      { SIMDE_FLOAT16_C(0.8), SIMDE_FLOAT16_C(1.5), SIMDE_FLOAT16_C(0.0), SIMDE_FLOAT16_C(0.0) } },
    { { INT16_C(2), INT16_C(3), INT16_C(6), INT16_C(2) },
        INT32_C(3),
      { SIMDE_FLOAT16_C(2.0), SIMDE_FLOAT16_C(3.0), SIMDE_FLOAT16_C(6.0), SIMDE_FLOAT16_C(2.0) } },
    { { INT16_C(1), INT16_C(8), INT16_C(7), INT16_C(5) },
        INT32_C(11),
      { SIMDE_FLOAT16_C(0.1), SIMDE_FLOAT16_C(0.9), SIMDE_FLOAT16_C(0.8), SIMDE_FLOAT16_C(0.6) } },
    { { INT16_C(7), INT16_C(7), INT16_C(1), INT16_C(3) },
        INT32_C(6),
      { SIMDE_FLOAT16_C(1.8), SIMDE_FLOAT16_C(1.8), SIMDE_FLOAT16_C(0.2), SIMDE_FLOAT16_C(0.8) } },
    { { INT16_C(3), INT16_C(4), INT16_C(3), INT16_C(5) },
        INT32_C(8),
      { SIMDE_FLOAT16_C(0.3), SIMDE_FLOAT16_C(0.4), SIMDE_FLOAT16_C(0.3), SIMDE_FLOAT16_C(0.5) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_float16x4_t r = simde_vcvt_n_f16_s16(a, test_vec[i].n);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
}
*/

static int
test_simde_vcvtq_n_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t n;
    simde_float32 r[4];
  } test_vec[] = {
    { { INT32_C(291), INT32_C(714), INT32_C(173), INT32_C(281) },
        INT32_C(15),
      { SIMDE_FLOAT32_C(22.0), SIMDE_FLOAT32_C(54.0), SIMDE_FLOAT32_C(13.0), SIMDE_FLOAT32_C(21.0) } },
    { { INT32_C(569), INT32_C(38), INT32_C(166), INT32_C(687) },
        INT32_C(23),
      { SIMDE_FLOAT32_C(27.0), SIMDE_FLOAT32_C(1.0), SIMDE_FLOAT32_C(7.0), SIMDE_FLOAT32_C(32.0) } },
    { { INT32_C(144), INT32_C(778), INT32_C(87), INT32_C(83) },
        INT32_C(18),
      { SIMDE_FLOAT32_C(9.0), SIMDE_FLOAT32_C(48.0), SIMDE_FLOAT32_C(5.0), SIMDE_FLOAT32_C(5.0) } },
    { { INT32_C(497), INT32_C(473), INT32_C(542), INT32_C(97) },
        INT32_C(1),
      { SIMDE_FLOAT32_C(165.0), SIMDE_FLOAT32_C(157.0), SIMDE_FLOAT32_C(180.0), SIMDE_FLOAT32_C(32.0) } },
    { { INT32_C(995), INT32_C(158), INT32_C(484), INT32_C(245) },
        INT32_C(12),
      { SIMDE_FLOAT32_C(71.0), SIMDE_FLOAT32_C(11.0), SIMDE_FLOAT32_C(34.0), SIMDE_FLOAT32_C(17.0) } },
    { { INT32_C(696), INT32_C(610), INT32_C(1001), INT32_C(487) },
        INT32_C(17),
      { SIMDE_FLOAT32_C(36.0), SIMDE_FLOAT32_C(32.0), SIMDE_FLOAT32_C(52.0), SIMDE_FLOAT32_C(25.0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_float32x4_t r = simde_vcvtq_n_f32_s32(a, test_vec[i].n);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vcvt_n_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t n;
    simde_float32 r[2];
  } test_vec[] = {
    { { -INT32_C(147), -INT32_C(423) },
        INT32_C(22),
      { SIMDE_FLOAT32_C(-7.0), SIMDE_FLOAT32_C(-21.0) } },
    { { INT32_C(813), -INT32_C(208) },
        INT32_C(6),
      { SIMDE_FLOAT32_C(203.0), SIMDE_FLOAT32_C(-52.0) } },
    { { -INT32_C(696), -INT32_C(320) },
        INT32_C(32),
      { SIMDE_FLOAT32_C(-20.0), SIMDE_FLOAT32_C(-9.0) } },
    { { INT32_C(240), INT32_C(486) },
        INT32_C(10),
      { SIMDE_FLOAT32_C(30.0), SIMDE_FLOAT32_C(60.0) } },
    { { -INT32_C(466), INT32_C(723) },
        INT32_C(26),
      { SIMDE_FLOAT32_C(-19.0), SIMDE_FLOAT32_C(30.0) } },
    { { -INT32_C(960), INT32_C(724) },
        INT32_C(18),
      { SIMDE_FLOAT32_C(-60.0), SIMDE_FLOAT32_C(45.0) } },
    { { INT32_C(967), -INT32_C(190) },
        INT32_C(17),
      { SIMDE_FLOAT32_C(50.0), SIMDE_FLOAT32_C(-10.0) } },
    { { INT32_C(869), INT32_C(722) },
        INT32_C(15),
      { SIMDE_FLOAT32_C(66.0), SIMDE_FLOAT32_C(55.0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_float32x2_t r = simde_vcvt_n_f32_s32(a, test_vec[i].n);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vcvtq_n_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    int32_t n;
    simde_float32 r[4];
  } test_vec[] = {
    { { UINT32_C(291), UINT32_C(714), UINT32_C(173), UINT32_C(281) },
        INT32_C(15),
      { SIMDE_FLOAT32_C(22.0), SIMDE_FLOAT32_C(54.0), SIMDE_FLOAT32_C(13.0), SIMDE_FLOAT32_C(21.0) } },
    { { UINT32_C(569), UINT32_C(38), UINT32_C(166), UINT32_C(687) },
        INT32_C(23),
      { SIMDE_FLOAT32_C(27.0), SIMDE_FLOAT32_C(1.0), SIMDE_FLOAT32_C(7.0), SIMDE_FLOAT32_C(32.0) } },
    { { UINT32_C(144), UINT32_C(778), UINT32_C(87), UINT32_C(83) },
        INT32_C(18),
      { SIMDE_FLOAT32_C(9.0), SIMDE_FLOAT32_C(48.0), SIMDE_FLOAT32_C(5.0), SIMDE_FLOAT32_C(5.0) } },
    { { UINT32_C(497), UINT32_C(473), UINT32_C(542), UINT32_C(97) },
        INT32_C(1),
      { SIMDE_FLOAT32_C(165.0), SIMDE_FLOAT32_C(157.0), SIMDE_FLOAT32_C(180.0), SIMDE_FLOAT32_C(32.0) } },
    { { UINT32_C(995), UINT32_C(158), UINT32_C(484), UINT32_C(245) },
        INT32_C(12),
      { SIMDE_FLOAT32_C(71.0), SIMDE_FLOAT32_C(11.0), SIMDE_FLOAT32_C(34.0), SIMDE_FLOAT32_C(17.0) } },
    { { UINT32_C(696), UINT32_C(610), UINT32_C(1001), UINT32_C(487) },
        INT32_C(17),
      { SIMDE_FLOAT32_C(36.0), SIMDE_FLOAT32_C(32.0), SIMDE_FLOAT32_C(52.0), SIMDE_FLOAT32_C(25.0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_float32x4_t r = simde_vcvtq_n_f32_u32(a, test_vec[i].n);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vcvt_n_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[2];
    int32_t n;
    simde_float32 r[2];
  } test_vec[] = {
    { { UINT32_C(387), UINT32_C(878) },
        INT32_C(8),
      { SIMDE_FLOAT32_C(38.0), SIMDE_FLOAT32_C(87.0) } },
    { { UINT32_C(382), UINT32_C(803) },
        INT32_C(3),
      { SIMDE_FLOAT32_C(382.0), SIMDE_FLOAT32_C(803.0) } },
    { { UINT32_C(22), UINT32_C(675) },
        INT32_C(4),
      { SIMDE_FLOAT32_C(3.0), SIMDE_FLOAT32_C(112.0) } },
    { { UINT32_C(145), UINT32_C(784) },
        INT32_C(4),
      { SIMDE_FLOAT32_C(24.0), SIMDE_FLOAT32_C(130.0) } },
    { { UINT32_C(424), UINT32_C(787) },
        INT32_C(24),
      { SIMDE_FLOAT32_C(16.0), SIMDE_FLOAT32_C(30.0) } },
    { { UINT32_C(934), UINT32_C(272) },
        INT32_C(10),
      { SIMDE_FLOAT32_C(116.0), SIMDE_FLOAT32_C(34.0) } },
    { { UINT32_C(412), UINT32_C(148) },
        INT32_C(13),
      { SIMDE_FLOAT32_C(27.0), SIMDE_FLOAT32_C(9.0) } },
    { { UINT32_C(984), UINT32_C(904) },
        INT32_C(31),
      { SIMDE_FLOAT32_C(33.0), SIMDE_FLOAT32_C(31.0) } },
    { { UINT32_C(791), UINT32_C(612) },
        INT32_C(7),
      { SIMDE_FLOAT32_C(158.0), SIMDE_FLOAT32_C(122.0) } },
    { { UINT32_C(54), UINT32_C(303) },
        INT32_C(28),
      { SIMDE_FLOAT32_C(1.0), SIMDE_FLOAT32_C(10.0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_float32x2_t r = simde_vcvt_n_f32_u32(a, test_vec[i].n);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_s64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_f16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_f32_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_s64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
