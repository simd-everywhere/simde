#define SIMDE_TEST_ARM_NEON_INSN get_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/get_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vget_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[4];
    int b;
    simde_float16_t r;
  } test_vec[] = {
  { {SIMDE_FLOAT16_VALUE(-49.25), SIMDE_FLOAT16_VALUE(-109.00), SIMDE_FLOAT16_VALUE(-626.50), SIMDE_FLOAT16_VALUE(-567.00)},
       INT8_C(   0),
    SIMDE_FLOAT16_VALUE(-49.25)},
  { {SIMDE_FLOAT16_VALUE(-226.00), SIMDE_FLOAT16_VALUE(-520.50), SIMDE_FLOAT16_VALUE(-252.38), SIMDE_FLOAT16_VALUE(-407.50)},
       INT8_C(   1),
    SIMDE_FLOAT16_VALUE(-520.50)},
  { {SIMDE_FLOAT16_VALUE(-833.00), SIMDE_FLOAT16_VALUE(-714.00), SIMDE_FLOAT16_VALUE(428.50), SIMDE_FLOAT16_VALUE(871.50)},
       INT8_C(   2),
    SIMDE_FLOAT16_VALUE(428.50)},
  { {SIMDE_FLOAT16_VALUE(488.00), SIMDE_FLOAT16_VALUE(112.56), SIMDE_FLOAT16_VALUE(58.66), SIMDE_FLOAT16_VALUE(879.50)},
       INT8_C(   3),
    SIMDE_FLOAT16_VALUE(879.50)},
  { {SIMDE_FLOAT16_VALUE(32.59), SIMDE_FLOAT16_VALUE(239.50), SIMDE_FLOAT16_VALUE(-487.50), SIMDE_FLOAT16_VALUE(853.50)},
       INT8_C(   2),
    SIMDE_FLOAT16_VALUE(-487.50)},
  { {SIMDE_FLOAT16_VALUE(-31.45), SIMDE_FLOAT16_VALUE(570.00), SIMDE_FLOAT16_VALUE(616.00), SIMDE_FLOAT16_VALUE(-942.00)},
       INT8_C(   1),
    SIMDE_FLOAT16_VALUE(570.00)},
  { {SIMDE_FLOAT16_VALUE(-537.50), SIMDE_FLOAT16_VALUE(-964.50), SIMDE_FLOAT16_VALUE(-592.00), SIMDE_FLOAT16_VALUE(305.50)},
       INT8_C(   3),
    SIMDE_FLOAT16_VALUE(305.50)},
  { {SIMDE_FLOAT16_VALUE(-180.50), SIMDE_FLOAT16_VALUE(-555.50), SIMDE_FLOAT16_VALUE(375.50), SIMDE_FLOAT16_VALUE(948.50)},
       INT8_C(   0),
    SIMDE_FLOAT16_VALUE(-180.50)},
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {

    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    int b = test_vec[i].b;
    simde_float16_t r;
    SIMDE_CONSTIFY_4_(simde_vget_lane_f16, r, (HEDLEY_UNREACHABLE(), SIMDE_FLOAT16_VALUE(0.0)), b, a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_vget_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    int b;
    simde_float32 r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   410.64), SIMDE_FLOAT32_C(   344.10) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(   344.10) },
    { { SIMDE_FLOAT32_C(  -838.05), SIMDE_FLOAT32_C(  -800.70) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(  -800.70) },
    { { SIMDE_FLOAT32_C(   546.78), SIMDE_FLOAT32_C(   198.96) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(   546.78) },
    { { SIMDE_FLOAT32_C(  -101.20), SIMDE_FLOAT32_C(  -135.04) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(  -135.04) },
    { { SIMDE_FLOAT32_C(   -61.99), SIMDE_FLOAT32_C(   998.55) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(   998.55) },
    { { SIMDE_FLOAT32_C(  -663.21), SIMDE_FLOAT32_C(  -581.66) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(  -663.21) },
    { { SIMDE_FLOAT32_C(  -515.64), SIMDE_FLOAT32_C(  -101.75) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(  -101.75) },
    { { SIMDE_FLOAT32_C(   909.95), SIMDE_FLOAT32_C(  -480.35) },
       INT8_C(   0),
      SIMDE_FLOAT32_C(   909.95) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {

    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    int b = test_vec[i].b;
    simde_float32 r;
    SIMDE_CONSTIFY_2_(simde_vget_lane_f32, r, (HEDLEY_UNREACHABLE(), SIMDE_FLOAT32_C(0.0)), b, a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_vget_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    simde_float64 r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -475.46) },
      SIMDE_FLOAT64_C(  -475.46) },
    { { SIMDE_FLOAT64_C(    40.13) },
      SIMDE_FLOAT64_C(    40.13) },
    { { SIMDE_FLOAT64_C(   577.68) },
      SIMDE_FLOAT64_C(   577.68) },
    { { SIMDE_FLOAT64_C(  -438.44) },
      SIMDE_FLOAT64_C(  -438.44) },
    { { SIMDE_FLOAT64_C(   564.06) },
      SIMDE_FLOAT64_C(   564.06) },
    { { SIMDE_FLOAT64_C(  -519.34) },
      SIMDE_FLOAT64_C(  -519.34) },
    { { SIMDE_FLOAT64_C(  -449.22) },
      SIMDE_FLOAT64_C(  -449.22) },
    { { SIMDE_FLOAT64_C(  -456.94) },
      SIMDE_FLOAT64_C(  -456.94) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64 r = simde_vget_lane_f64(a, 0);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_vget_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int b;
    int8_t r;
  } test_vec[] = {
    { {  INT8_C(  79),  INT8_C(  68), -INT8_C(  36),  INT8_C(  47),  INT8_C(  87), -INT8_C(  22), -INT8_C(  44), -INT8_C( 111) },
       INT8_C(   2),
      -INT8_C(  36) },
    { { -INT8_C(  78),  INT8_C(  75), -INT8_C( 106),  INT8_C( 111), -INT8_C(  55),  INT8_C(  39), -INT8_C(  69), -INT8_C( 110) },
       INT8_C(   4),
      -INT8_C(  55) },
    { {  INT8_C(  72), -INT8_C( 120), -INT8_C( 122), -INT8_C(  86),  INT8_C(  90), -INT8_C(  24), -INT8_C(  60), -INT8_C( 104) },
       INT8_C(   1),
      -INT8_C( 120) },
    { {  INT8_C( 116),  INT8_C(  37), -INT8_C(  99), -INT8_C(  48),  INT8_C( 117), -INT8_C(  31), -INT8_C(  84), -INT8_C(  92) },
       INT8_C(   0),
       INT8_C( 116) },
    { { -INT8_C( 106),  INT8_C( 120), -INT8_C(  54), -INT8_C(  64),  INT8_C(  42),  INT8_C(  21),  INT8_C(  87), -INT8_C( 103) },
       INT8_C(   6),
       INT8_C(  87) },
    { {  INT8_C( 126),  INT8_C(  84),  INT8_C( 112),  INT8_C(  98), -INT8_C( 100), -INT8_C(   7), -INT8_C(  23),  INT8_C(  70) },
       INT8_C(   3),
       INT8_C(  98) },
    { { -INT8_C(  47),  INT8_C(  11), -INT8_C(  21),  INT8_C(  10),      INT8_MAX,  INT8_C(  17), -INT8_C(  89),  INT8_C(  79) },
       INT8_C(   6),
      -INT8_C(  89) },
    { { -INT8_C( 120), -INT8_C(   5),  INT8_C(  42), -INT8_C(  64), -INT8_C( 110), -INT8_C(  94), -INT8_C( 118),  INT8_C(  82) },
       INT8_C(   4),
      -INT8_C( 110) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    int b = test_vec[i].b;
    int8_t r;
    SIMDE_CONSTIFY_8_(simde_vget_lane_s8, r, (HEDLEY_UNREACHABLE(), 0), b, a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int b;
    int16_t r;
  } test_vec[] = {
    { {  INT16_C( 13913), -INT16_C(  7828), -INT16_C( 14489), -INT16_C( 26057) },
       INT8_C(   0),
       INT16_C( 13913) },
    { {  INT16_C( 13818),  INT16_C( 18664), -INT16_C( 10245),  INT16_C(  6383) },
       INT8_C(   0),
       INT16_C( 13818) },
    { { -INT16_C(  9771), -INT16_C( 25769),  INT16_C(  2933), -INT16_C(  2011) },
       INT8_C(   2),
       INT16_C(  2933) },
    { { -INT16_C( 14019), -INT16_C( 15785), -INT16_C( 29150),  INT16_C(   814) },
       INT8_C(   1),
      -INT16_C( 15785) },
    { {  INT16_C( 15094),  INT16_C(  3728), -INT16_C( 15051),  INT16_C( 32246) },
       INT8_C(   1),
       INT16_C(  3728) },
    { {  INT16_C( 28109),  INT16_C( 18137), -INT16_C( 19902), -INT16_C(  8803) },
       INT8_C(   0),
       INT16_C( 28109) },
    { {  INT16_C(   680),  INT16_C( 27168), -INT16_C(  5569),  INT16_C(   705) },
       INT8_C(   0),
       INT16_C(   680) },
    { {  INT16_C( 12367),  INT16_C( 17680),  INT16_C( 18982),  INT16_C( 13525) },
       INT8_C(   3),
       INT16_C( 13525) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    int b = test_vec[i].b;
    int16_t r;
    SIMDE_CONSTIFY_4_(simde_vget_lane_s16, r, (HEDLEY_UNREACHABLE(), 0), b, a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int b;
    int32_t r;
  } test_vec[] = {
    { {  INT32_C(   451851400), -INT32_C(   530446795) },
       INT8_C(   0),
       INT32_C(   451851400) },
    { { -INT32_C(   497636127), -INT32_C(   338817732) },
       INT8_C(   1),
      -INT32_C(   338817732) },
    { {  INT32_C(   212911362), -INT32_C(   643488292) },
       INT8_C(   1),
      -INT32_C(   643488292) },
    { { -INT32_C(  1592001450), -INT32_C(  1634742396) },
       INT8_C(   0),
      -INT32_C(  1592001450) },
    { { -INT32_C(   941293163), -INT32_C(  1004629534) },
       INT8_C(   1),
      -INT32_C(  1004629534) },
    { {  INT32_C(  1941475883), -INT32_C(  1608286828) },
       INT8_C(   0),
       INT32_C(  1941475883) },
    { { -INT32_C(    30194103),  INT32_C(  1025060764) },
       INT8_C(   1),
       INT32_C(  1025060764) },
    { { -INT32_C(   330117656),  INT32_C(   718361442) },
       INT8_C(   1),
       INT32_C(   718361442) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    int b = test_vec[i].b;
    int32_t r;
    SIMDE_CONSTIFY_2_(simde_vget_lane_s32, r, (HEDLEY_UNREACHABLE(), 0), b, a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    int64_t r;
  } test_vec[] = {
    { {  INT64_C( 7593315202386255056) },
       INT64_C( 7593315202386255056) },
    { { -INT64_C( 3283523923862515318) },
      -INT64_C( 3283523923862515318) },
    { {  INT64_C( 4591998433815169493) },
       INT64_C( 4591998433815169493) },
    { {  INT64_C( 3515554461116684124) },
       INT64_C( 3515554461116684124) },
    { {  INT64_C( 8463300658565386409) },
       INT64_C( 8463300658565386409) },
    { { -INT64_C( 5169869895816060153) },
      -INT64_C( 5169869895816060153) },
    { { -INT64_C( 3838821912131374513) },
      -INT64_C( 3838821912131374513) },
    { {  INT64_C(  166258511252788092) },
       INT64_C(  166258511252788092) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    int64_t r = simde_vget_lane_s64(a, 0);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    int b;
    uint8_t r;
  } test_vec[] = {
    { { UINT8_C(145), UINT8_C( 15), UINT8_C(109), UINT8_C( 38), UINT8_C(127), UINT8_C( 69), UINT8_C(163), UINT8_C(231) },
       INT8_C(   3),
      UINT8_C( 38) },
    { { UINT8_C( 26), UINT8_C( 62), UINT8_C(190), UINT8_C(237), UINT8_C(178), UINT8_C(209), UINT8_C( 61), UINT8_C(  4) },
       INT8_C(   4),
      UINT8_C(178) },
    { { UINT8_C( 55), UINT8_C(139), UINT8_C( 83), UINT8_C( 28), UINT8_C( 77), UINT8_C( 73), UINT8_C(209), UINT8_C( 70) },
       INT8_C(   0),
      UINT8_C( 55) },
    { { UINT8_C( 62), UINT8_C(144), UINT8_C( 10), UINT8_C(169), UINT8_C( 34), UINT8_C( 25), UINT8_C( 23), UINT8_C( 72) },
       INT8_C(   0),
      UINT8_C( 62) },
    { { UINT8_C( 92), UINT8_C(235), UINT8_C(127), UINT8_C(  0), UINT8_C(  6), UINT8_C(189), UINT8_C(190), UINT8_C(243) },
       INT8_C(   7),
      UINT8_C(243) },
    { { UINT8_C(143), UINT8_C( 49), UINT8_C(115), UINT8_C(147), UINT8_C(104), UINT8_C(254), UINT8_C(231), UINT8_C(132) },
       INT8_C(   4),
      UINT8_C(104) },
    { { UINT8_C( 48), UINT8_C( 86), UINT8_C(146), UINT8_C(200), UINT8_C(148), UINT8_C( 34), UINT8_C(210), UINT8_C( 61) },
       INT8_C(   4),
      UINT8_C(148) },
    { { UINT8_C(235), UINT8_C( 84), UINT8_C(141), UINT8_C(131), UINT8_C(177), UINT8_C(120), UINT8_C(  2), UINT8_C(177) },
       INT8_C(   6),
      UINT8_C(  2) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    int b = test_vec[i].b;
    uint8_t r;
    SIMDE_CONSTIFY_8_(simde_vget_lane_u8, r, (HEDLEY_UNREACHABLE(), 0), b, a);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    int b;
    uint16_t r;
  } test_vec[] = {
    { { UINT16_C(12419), UINT16_C(50038), UINT16_C(38877), UINT16_C(17206) },
       INT8_C(   2),
      UINT16_C(38877) },
    { { UINT16_C(48224), UINT16_C(21652), UINT16_C(15709), UINT16_C(31006) },
       INT8_C(   3),
      UINT16_C(31006) },
    { { UINT16_C(39237), UINT16_C(11133), UINT16_C(17423), UINT16_C(50851) },
       INT8_C(   2),
      UINT16_C(17423) },
    { { UINT16_C(48821), UINT16_C(47484), UINT16_C(44097), UINT16_C( 1071) },
       INT8_C(   2),
      UINT16_C(44097) },
    { { UINT16_C(15302), UINT16_C(28877), UINT16_C(35227), UINT16_C(61189) },
       INT8_C(   3),
      UINT16_C(61189) },
    { { UINT16_C( 3394), UINT16_C(19808), UINT16_C(63826), UINT16_C(32458) },
       INT8_C(   0),
      UINT16_C( 3394) },
    { { UINT16_C( 8462), UINT16_C(23759), UINT16_C(36311), UINT16_C(37080) },
       INT8_C(   2),
      UINT16_C(36311) },
    { { UINT16_C(49029), UINT16_C( 4051), UINT16_C( 3717), UINT16_C(63196) },
       INT8_C(   1),
      UINT16_C( 4051) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    int b = test_vec[i].b;
    uint16_t r;
    SIMDE_CONSTIFY_4_(simde_vget_lane_u16, r, (HEDLEY_UNREACHABLE(), 0), b, a);
    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    int b;
    uint32_t r;
  } test_vec[] = {
    { { UINT32_C(3007867267), UINT32_C(2989705603) },
       INT8_C(   0),
      UINT32_C(3007867267) },
    { { UINT32_C(1366545288), UINT32_C(3281825408) },
       INT8_C(   1),
      UINT32_C(3281825408) },
    { { UINT32_C( 661651758), UINT32_C(3582788621) },
       INT8_C(   1),
      UINT32_C(3582788621) },
    { { UINT32_C( 203852593), UINT32_C(3260321551) },
       INT8_C(   1),
      UINT32_C(3260321551) },
    { { UINT32_C(  96859549), UINT32_C(3464009853) },
       INT8_C(   0),
      UINT32_C(  96859549) },
    { { UINT32_C(3990579750), UINT32_C(3210599832) },
       INT8_C(   0),
      UINT32_C(3990579750) },
    { { UINT32_C( 197152098), UINT32_C(2318486398) },
       INT8_C(   0),
      UINT32_C( 197152098) },
    { { UINT32_C(3541884608), UINT32_C(2174226811) },
       INT8_C(   0),
      UINT32_C(3541884608) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    int b = test_vec[i].b;
    uint32_t r;
    SIMDE_CONSTIFY_2_(simde_vget_lane_u32, r, (HEDLEY_UNREACHABLE(), 0), b, a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t r;
  } test_vec[] = {
    { { UINT64_C( 8474713643211531917) },
      UINT64_C( 8474713643211531917) },
    { { UINT64_C( 4718805824424333625) },
      UINT64_C( 4718805824424333625) },
    { { UINT64_C( 2901443443683120557) },
      UINT64_C( 2901443443683120557) },
    { { UINT64_C(16896600451596749021) },
      UINT64_C(16896600451596749021) },
    { { UINT64_C( 2355020594457970359) },
      UINT64_C( 2355020594457970359) },
    { { UINT64_C(14871504216242625854) },
      UINT64_C(14871504216242625854) },
    { { UINT64_C(11884950968574087521) },
      UINT64_C(11884950968574087521) },
    { { UINT64_C(12253690780921831607) },
      UINT64_C(12253690780921831607) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    uint64_t r = simde_vget_lane_u64(a, 0);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16_t a[8];
    int b;
    simde_float16_t r;
  } test_vec[] = {
  { { SIMDE_FLOAT16_VALUE(   441.00), SIMDE_FLOAT16_VALUE(   861.50), SIMDE_FLOAT16_VALUE(    98.06), SIMDE_FLOAT16_VALUE(   896.00),
    SIMDE_FLOAT16_VALUE(  -918.50), SIMDE_FLOAT16_VALUE(  -717.00), SIMDE_FLOAT16_VALUE(  -823.00), SIMDE_FLOAT16_VALUE(  -581.00) },
       INT8_C(   0),
    SIMDE_FLOAT16_VALUE(441.00)},
  { { SIMDE_FLOAT16_VALUE(    -6.45), SIMDE_FLOAT16_VALUE(    29.20), SIMDE_FLOAT16_VALUE(  -856.00), SIMDE_FLOAT16_VALUE(   267.25),
    SIMDE_FLOAT16_VALUE(  -302.00), SIMDE_FLOAT16_VALUE(   526.50), SIMDE_FLOAT16_VALUE(   713.00), SIMDE_FLOAT16_VALUE(   -14.83) },
       INT8_C(   1),
    SIMDE_FLOAT16_VALUE(29.20)},
  { { SIMDE_FLOAT16_VALUE(   909.00), SIMDE_FLOAT16_VALUE(  -475.75), SIMDE_FLOAT16_VALUE(   269.8), SIMDE_FLOAT16_VALUE(   991.00),
    SIMDE_FLOAT16_VALUE(  -192.62), SIMDE_FLOAT16_VALUE(   446.50), SIMDE_FLOAT16_VALUE(  -590.00), SIMDE_FLOAT16_VALUE(  -508.50) },
       INT8_C(   2),
    SIMDE_FLOAT16_VALUE(269.8)},
  { { SIMDE_FLOAT16_VALUE(   918.00), SIMDE_FLOAT16_VALUE(   650.00), SIMDE_FLOAT16_VALUE(    80.00), SIMDE_FLOAT16_VALUE(  -275.00),
    SIMDE_FLOAT16_VALUE(    96.56), SIMDE_FLOAT16_VALUE(   489.75), SIMDE_FLOAT16_VALUE(   216.50), SIMDE_FLOAT16_VALUE(  -894.00) },
       INT8_C(   3),
    SIMDE_FLOAT16_VALUE(-275.00)},
  { { SIMDE_FLOAT16_VALUE(  -108.69), SIMDE_FLOAT16_VALUE(  -977.50), SIMDE_FLOAT16_VALUE(   -44.56), SIMDE_FLOAT16_VALUE(   432.25),
    SIMDE_FLOAT16_VALUE(   281.00), SIMDE_FLOAT16_VALUE(   760.00), SIMDE_FLOAT16_VALUE(  -874.50), SIMDE_FLOAT16_VALUE(  -645.00) },
       INT8_C(   4),
    SIMDE_FLOAT16_VALUE(281.00)},
  { { SIMDE_FLOAT16_VALUE(   392.00), SIMDE_FLOAT16_VALUE(  -758.50), SIMDE_FLOAT16_VALUE(  -870.50), SIMDE_FLOAT16_VALUE(  -511.25),
    SIMDE_FLOAT16_VALUE(   731.50), SIMDE_FLOAT16_VALUE(   345.75), SIMDE_FLOAT16_VALUE(  -405.25), SIMDE_FLOAT16_VALUE(  -353.75) },
       INT8_C(   5),
    SIMDE_FLOAT16_VALUE(345.75)},
  { { SIMDE_FLOAT16_VALUE(   345.75), SIMDE_FLOAT16_VALUE(   372.75), SIMDE_FLOAT16_VALUE(   802.50), SIMDE_FLOAT16_VALUE(  -373.00),
    SIMDE_FLOAT16_VALUE(   133.12), SIMDE_FLOAT16_VALUE(   928.00), SIMDE_FLOAT16_VALUE(   -18.17), SIMDE_FLOAT16_VALUE(  -974.50) },
       INT8_C(   6),
    SIMDE_FLOAT16_VALUE(-18.17)},
  { { SIMDE_FLOAT16_VALUE(  -634.00), SIMDE_FLOAT16_VALUE(  -283.75), SIMDE_FLOAT16_VALUE(   -99.50), SIMDE_FLOAT16_VALUE(   134.00),
    SIMDE_FLOAT16_VALUE(  -781.50), SIMDE_FLOAT16_VALUE(  1188.00), SIMDE_FLOAT16_VALUE(  -106.88), SIMDE_FLOAT16_VALUE(  -497.25) },
       INT8_C(   7),
    SIMDE_FLOAT16_VALUE(-497.25)},
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {

    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    int b = test_vec[i].b;
    simde_float16_t r;
    SIMDE_CONSTIFY_8_(simde_vgetq_lane_f16, r, (HEDLEY_UNREACHABLE(), SIMDE_FLOAT16_VALUE(0.0)), b, a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_vgetq_lane_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    int b;
    simde_float32 r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   273.12), SIMDE_FLOAT32_C(   753.68), SIMDE_FLOAT32_C(   -47.15), SIMDE_FLOAT32_C(   832.55) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(   753.68) },
    { { SIMDE_FLOAT32_C(   -32.75), SIMDE_FLOAT32_C(    69.02), SIMDE_FLOAT32_C(   834.09), SIMDE_FLOAT32_C(   613.18) },
       INT8_C(   3),
      SIMDE_FLOAT32_C(   613.18) },
    { { SIMDE_FLOAT32_C(  -409.75), SIMDE_FLOAT32_C(  -293.91), SIMDE_FLOAT32_C(  -958.18), SIMDE_FLOAT32_C(  -184.72) },
       INT8_C(   3),
      SIMDE_FLOAT32_C(  -184.72) },
    { { SIMDE_FLOAT32_C(  -957.69), SIMDE_FLOAT32_C(   993.98), SIMDE_FLOAT32_C(   264.51), SIMDE_FLOAT32_C(  -192.93) },
       INT8_C(   3),
      SIMDE_FLOAT32_C(  -192.93) },
    { { SIMDE_FLOAT32_C(   970.45), SIMDE_FLOAT32_C(   778.50), SIMDE_FLOAT32_C(   196.11), SIMDE_FLOAT32_C(   650.20) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(   778.50) },
    { { SIMDE_FLOAT32_C(  -845.53), SIMDE_FLOAT32_C(  -889.17), SIMDE_FLOAT32_C(  -363.16), SIMDE_FLOAT32_C(   770.16) },
       INT8_C(   3),
      SIMDE_FLOAT32_C(   770.16) },
    { { SIMDE_FLOAT32_C(   532.17), SIMDE_FLOAT32_C(    43.28), SIMDE_FLOAT32_C(    39.43), SIMDE_FLOAT32_C(  -514.98) },
       INT8_C(   1),
      SIMDE_FLOAT32_C(    43.28) },
    { { SIMDE_FLOAT32_C(    35.67), SIMDE_FLOAT32_C(   452.27), SIMDE_FLOAT32_C(   944.85), SIMDE_FLOAT32_C(  -130.24) },
       INT8_C(   3),
      SIMDE_FLOAT32_C(  -130.24) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    int b = test_vec[i].b;
    simde_float32 r;
    SIMDE_CONSTIFY_4_(simde_vgetq_lane_f32, r, (HEDLEY_UNREACHABLE(), SIMDE_FLOAT32_C(0.0)), b, a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_vgetq_lane_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    int b;
    simde_float64 r;
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   629.36), SIMDE_FLOAT64_C(  -547.88) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(  -547.88) },
    { { SIMDE_FLOAT64_C(  -917.95), SIMDE_FLOAT64_C(  -153.86) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(  -153.86) },
    { { SIMDE_FLOAT64_C(   233.05), SIMDE_FLOAT64_C(  -687.76) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(  -687.76) },
    { { SIMDE_FLOAT64_C(   358.76), SIMDE_FLOAT64_C(   -20.52) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(   -20.52) },
    { { SIMDE_FLOAT64_C(   501.06), SIMDE_FLOAT64_C(  -830.23) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(  -830.23) },
    { { SIMDE_FLOAT64_C(  -204.70), SIMDE_FLOAT64_C(  -481.76) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(  -481.76) },
    { { SIMDE_FLOAT64_C(  -746.83), SIMDE_FLOAT64_C(   -28.88) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(   -28.88) },
    { { SIMDE_FLOAT64_C(   935.21), SIMDE_FLOAT64_C(  -696.96) },
       INT8_C(   1),
      SIMDE_FLOAT64_C(  -696.96) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    int b = test_vec[i].b;
    simde_float64 r;
    SIMDE_CONSTIFY_2_(simde_vgetq_lane_f64, r, (HEDLEY_UNREACHABLE(), SIMDE_FLOAT64_C(0.0)), b, a);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;
}

static int
test_simde_vgetq_lane_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int b;
    int8_t r;
  } test_vec[] = {
    { {  INT8_C(  62),  INT8_C(  17),  INT8_C(  52),  INT8_C(  30), -INT8_C(  59), -INT8_C( 118), -INT8_C(  42),  INT8_C(  25),
        -INT8_C(  15), -INT8_C(  48), -INT8_C(  40), -INT8_C(  27),  INT8_C( 102),  INT8_C(  24), -INT8_C( 127), -INT8_C(  50) },
       INT8_C(   4),
      -INT8_C(  59) },
    { { -INT8_C( 121), -INT8_C(  43), -INT8_C(  86),  INT8_C(  63),  INT8_C(   7),  INT8_C(  83),  INT8_C(  53),  INT8_C(  61),
        -INT8_C(   4),  INT8_C(  81),  INT8_C(   2),  INT8_C(  47), -INT8_C(  19), -INT8_C( 112),  INT8_C( 109), -INT8_C(   2) },
       INT8_C(   4),
       INT8_C(   7) },
    { { -INT8_C( 117), -INT8_C(  61),  INT8_C(  78),  INT8_C(  97), -INT8_C(  36),  INT8_C(  63),  INT8_C(  50), -INT8_C(  76),
         INT8_C(  36), -INT8_C( 104), -INT8_C(  51), -INT8_C(  90),  INT8_C( 102),  INT8_C(  81),  INT8_C(  45),  INT8_C(  59) },
       INT8_C(  11),
      -INT8_C(  90) },
    { {  INT8_C( 108),  INT8_C(  66),  INT8_C(  78), -INT8_C(  94),      INT8_MIN,  INT8_C(  74), -INT8_C(  13), -INT8_C( 126),
         INT8_C( 121), -INT8_C(  32),  INT8_C(  18), -INT8_C(  25), -INT8_C(  34), -INT8_C(  41),  INT8_C( 114), -INT8_C(  94) },
       INT8_C(   5),
       INT8_C(  74) },
    { { -INT8_C(  44),  INT8_C( 126),  INT8_C( 101),  INT8_C(   6),  INT8_C(  51), -INT8_C( 119), -INT8_C(  98),  INT8_C(   0),
         INT8_C(  47),  INT8_C(   4),  INT8_C(  81),  INT8_C(  93),  INT8_C(  64),  INT8_C(  77), -INT8_C(  55), -INT8_C( 126) },
       INT8_C(  11),
       INT8_C(  93) },
    { {  INT8_C( 107),  INT8_C(   2), -INT8_C(  26),  INT8_C(  95), -INT8_C( 124),  INT8_C(  95),  INT8_C(  63), -INT8_C( 105),
         INT8_C(  70),  INT8_C(  30),  INT8_C( 110), -INT8_C(  71), -INT8_C(  64), -INT8_C( 109), -INT8_C( 115),  INT8_C(  62) },
       INT8_C(   8),
       INT8_C(  70) },
    { { -INT8_C( 109),  INT8_C( 113), -INT8_C( 126),  INT8_C(  49),  INT8_C( 113), -INT8_C(  79),  INT8_C(  53), -INT8_C(  61),
         INT8_C(  14),  INT8_C( 117),  INT8_C(  16), -INT8_C(  40), -INT8_C(   8), -INT8_C(  85),  INT8_C(  67), -INT8_C(   6) },
       INT8_C(   1),
       INT8_C( 113) },
    { { -INT8_C(  94),      INT8_MAX, -INT8_C(  15), -INT8_C(  30),  INT8_C(  22),  INT8_C(  55),  INT8_C(   0), -INT8_C( 124),
        -INT8_C(  16), -INT8_C(  64),  INT8_C(  23),  INT8_C( 125), -INT8_C(   2),  INT8_C(  16),  INT8_C(  16),  INT8_C( 112) },
       INT8_C(   2),
      -INT8_C(  15) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    int b = test_vec[i].b;
    int8_t r;
    SIMDE_CONSTIFY_16_(simde_vgetq_lane_s8, r, (HEDLEY_UNREACHABLE(), 0), b, a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int b;
    int16_t r;
  } test_vec[] = {
    { {  INT16_C( 16940), -INT16_C( 29603), -INT16_C( 16153), -INT16_C(  3490), -INT16_C( 19383),  INT16_C( 28817),  INT16_C(  5341),  INT16_C(  6146) },
       INT8_C(   4),
      -INT16_C( 19383) },
    { { -INT16_C( 22867),  INT16_C( 27147),  INT16_C( 18990),  INT16_C(  5131),  INT16_C( 18178), -INT16_C( 29906), -INT16_C( 10956),  INT16_C( 30392) },
       INT8_C(   2),
       INT16_C( 18990) },
    { {  INT16_C( 23876), -INT16_C( 23822),  INT16_C( 15439), -INT16_C(  8105),  INT16_C( 13484), -INT16_C( 20748), -INT16_C( 10164), -INT16_C(  3493) },
       INT8_C(   3),
      -INT16_C(  8105) },
    { {  INT16_C(  8645), -INT16_C( 12242),  INT16_C( 12341),  INT16_C( 25623),  INT16_C( 19644),  INT16_C( 29753),  INT16_C( 27586),  INT16_C(  8376) },
       INT8_C(   6),
       INT16_C( 27586) },
    { {  INT16_C( 28507), -INT16_C( 19814),  INT16_C( 18000),  INT16_C( 17638),  INT16_C( 13044),  INT16_C( 20253),  INT16_C(    37),  INT16_C( 17940) },
       INT8_C(   6),
       INT16_C(    37) },
    { {  INT16_C( 31717), -INT16_C(   929),  INT16_C(  7135),  INT16_C(  6216),  INT16_C(  2959),  INT16_C( 18308), -INT16_C(  7637), -INT16_C( 25950) },
       INT8_C(   4),
       INT16_C(  2959) },
    { { -INT16_C(  5548),  INT16_C( 15042), -INT16_C( 18897),  INT16_C( 19565), -INT16_C( 28155),  INT16_C(  6476),  INT16_C( 31704),  INT16_C( 21502) },
       INT8_C(   2),
      -INT16_C( 18897) },
    { {  INT16_C( 13307),  INT16_C( 17397), -INT16_C( 31669), -INT16_C( 12466),  INT16_C( 31179),  INT16_C( 28337),  INT16_C( 11540), -INT16_C(   318) },
       INT8_C(   7),
      -INT16_C(   318) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int b = test_vec[i].b;
    int16_t r;
    SIMDE_CONSTIFY_8_(simde_vgetq_lane_s16, r, (HEDLEY_UNREACHABLE(), 0), b, a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int b;
    int32_t r;
  } test_vec[] = {
    { { -INT32_C(   382002186),  INT32_C(  1860295962),  INT32_C(   860430686), -INT32_C(  1104420096) },
       INT8_C(   1),
       INT32_C(  1860295962) },
    { { -INT32_C(  1513067068), -INT32_C(   120501551), -INT32_C(  1300405244),  INT32_C(   262707700) },
       INT8_C(   0),
      -INT32_C(  1513067068) },
    { {  INT32_C(  1941055890), -INT32_C(   510390121),  INT32_C(  1875153987), -INT32_C(  1070336685) },
       INT8_C(   2),
       INT32_C(  1875153987) },
    { { -INT32_C(  1458531880),  INT32_C(   101520521),  INT32_C(  1872691654),  INT32_C(   956396304) },
       INT8_C(   1),
       INT32_C(   101520521) },
    { {  INT32_C(   137744756),  INT32_C(  1990031794),  INT32_C(   460058856),  INT32_C(  1106522544) },
       INT8_C(   1),
       INT32_C(  1990031794) },
    { { -INT32_C(  1420375395),  INT32_C(  1873550544), -INT32_C(  1931297397), -INT32_C(   956299018) },
       INT8_C(   1),
       INT32_C(  1873550544) },
    { { -INT32_C(  1497990903),  INT32_C(  1536597743), -INT32_C(  1366538566),  INT32_C(  1363922567) },
       INT8_C(   0),
      -INT32_C(  1497990903) },
    { { -INT32_C(  1556078090),  INT32_C(  1918946448),  INT32_C(  1501189720), -INT32_C(  1755138018) },
       INT8_C(   2),
       INT32_C(  1501189720) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int b = test_vec[i].b;
    int32_t r;
    SIMDE_CONSTIFY_4_(simde_vgetq_lane_s32, r, (HEDLEY_UNREACHABLE(), 0), b, a);
    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int b;
    int64_t r;
  } test_vec[] = {
    { {  INT64_C( 3728751874968948413),  INT64_C( 5321062654944271890) },
       INT8_C(   1),
       INT64_C( 5321062654944271890) },
    { { -INT64_C( 6526973102782903603),  INT64_C( 4086456640948673758) },
       INT8_C(   0),
      -INT64_C( 6526973102782903603) },
    { {  INT64_C(  821728255052303305), -INT64_C( 8871372210728488644) },
       INT8_C(   1),
      -INT64_C( 8871372210728488644) },
    { {  INT64_C( 9063507124988743488), -INT64_C(  755308779427368444) },
       INT8_C(   1),
      -INT64_C(  755308779427368444) },
    { { -INT64_C( 4601413837701090548), -INT64_C( 5568997109630427501) },
       INT8_C(   1),
      -INT64_C( 5568997109630427501) },
    { {  INT64_C( 7249722157166126946), -INT64_C( 5802075325525506327) },
       INT8_C(   1),
      -INT64_C( 5802075325525506327) },
    { {  INT64_C( 4192912744441392621), -INT64_C( 1385899749073431636) },
       INT8_C(   0),
       INT64_C( 4192912744441392621) },
    { {  INT64_C( 3662145803337978095), -INT64_C( 1557336465030705668) },
       INT8_C(   0),
       INT64_C( 3662145803337978095) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    int b = test_vec[i].b;
    int64_t r;
    SIMDE_CONSTIFY_2_(simde_vgetq_lane_s64, r, (HEDLEY_UNREACHABLE(), 0), b, a);
    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    int b;
    uint8_t r;
  } test_vec[] = {
    { { UINT8_C(217), UINT8_C( 95), UINT8_C(111), UINT8_C(104), UINT8_C( 19), UINT8_C(112), UINT8_C(195), UINT8_C( 29),
        UINT8_C(167), UINT8_C(167), UINT8_C( 53), UINT8_C(250), UINT8_C(196), UINT8_C(115), UINT8_C( 22), UINT8_C(127) },
       INT8_C(  14),
      UINT8_C( 22) },
    { { UINT8_C(166), UINT8_C(247), UINT8_C( 43), UINT8_C( 33), UINT8_C(246), UINT8_C(230), UINT8_C(120), UINT8_C(202),
        UINT8_C(208), UINT8_C(134), UINT8_C(111), UINT8_C(125), UINT8_C( 17), UINT8_C( 54), UINT8_C( 86), UINT8_C(112) },
       INT8_C(   6),
      UINT8_C(120) },
    { { UINT8_C(191), UINT8_C(132), UINT8_C( 22), UINT8_C(130), UINT8_C(161), UINT8_C(189), UINT8_C( 41), UINT8_C(214),
        UINT8_C(184), UINT8_C(237), UINT8_C( 73), UINT8_C(206), UINT8_C(108), UINT8_C(103), UINT8_C(117), UINT8_C( 99) },
       INT8_C(   2),
      UINT8_C( 22) },
    { { UINT8_C(150), UINT8_C( 89), UINT8_C(120), UINT8_C( 14), UINT8_C( 36), UINT8_C( 72), UINT8_C(148), UINT8_C(147),
        UINT8_C(197), UINT8_C(166), UINT8_C(201), UINT8_C( 28), UINT8_C( 22), UINT8_C(111), UINT8_C(219), UINT8_C(154) },
       INT8_C(   6),
      UINT8_C(148) },
    { { UINT8_C( 93), UINT8_C( 59), UINT8_C( 67), UINT8_C(134), UINT8_C( 17), UINT8_C(251), UINT8_C(115), UINT8_C( 91),
        UINT8_C(202), UINT8_C(223), UINT8_C(194), UINT8_C( 63), UINT8_C( 66), UINT8_C( 85), UINT8_C(213), UINT8_C(156) },
       INT8_C(  13),
      UINT8_C( 85) },
    { { UINT8_C(227), UINT8_C(192), UINT8_C( 22), UINT8_C(120), UINT8_C( 83), UINT8_C(219), UINT8_C( 30), UINT8_C( 28),
        UINT8_C(247), UINT8_C( 52), UINT8_C(140), UINT8_C(210), UINT8_C(207), UINT8_C( 18), UINT8_C( 47), UINT8_C( 10) },
       INT8_C(   5),
      UINT8_C(219) },
    { { UINT8_C(181), UINT8_C( 28), UINT8_C( 81), UINT8_C( 40), UINT8_C(119), UINT8_C( 27), UINT8_C(  7), UINT8_C( 57),
        UINT8_C( 90), UINT8_C( 74), UINT8_C(142), UINT8_C( 47), UINT8_C(230), UINT8_C( 92), UINT8_C( 18), UINT8_C(166) },
       INT8_C(   2),
      UINT8_C( 81) },
    { { UINT8_C(138), UINT8_C(249), UINT8_C( 77), UINT8_C(168), UINT8_C( 21), UINT8_C( 69), UINT8_C(221), UINT8_C(161),
        UINT8_C( 23), UINT8_C(172), UINT8_C(179), UINT8_C( 71), UINT8_C(182), UINT8_C(  9), UINT8_C(252), UINT8_C(210) },
       INT8_C(  10),
      UINT8_C(179) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    int b = test_vec[i].b;
    uint8_t r;
    SIMDE_CONSTIFY_16_(simde_vgetq_lane_u8, r, (HEDLEY_UNREACHABLE(), 0), b, a);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    int b;
    uint16_t r;
  } test_vec[] = {
    { { UINT16_C(61091), UINT16_C(53658), UINT16_C(16697), UINT16_C( 5906), UINT16_C( 8437), UINT16_C(24513), UINT16_C(37350), UINT16_C(20655) },
       INT8_C(   0),
      UINT16_C(61091) },
    { { UINT16_C(42027), UINT16_C(57525), UINT16_C(55191), UINT16_C(45942), UINT16_C( 7418), UINT16_C( 8850), UINT16_C(38827), UINT16_C(39366) },
       INT8_C(   1),
      UINT16_C(57525) },
    { { UINT16_C(53911), UINT16_C(43634), UINT16_C(26601), UINT16_C(43978), UINT16_C(45510), UINT16_C(30268), UINT16_C(29697), UINT16_C(42401) },
       INT8_C(   1),
      UINT16_C(43634) },
    { { UINT16_C(15490), UINT16_C(63489), UINT16_C(64495), UINT16_C(33044), UINT16_C(48926), UINT16_C(58393), UINT16_C(19032), UINT16_C(10875) },
       INT8_C(   5),
      UINT16_C(58393) },
    { { UINT16_C( 5157), UINT16_C(61476), UINT16_C(60351), UINT16_C(64417), UINT16_C(41569), UINT16_C(  623), UINT16_C(38983), UINT16_C(33668) },
       INT8_C(   1),
      UINT16_C(61476) },
    { { UINT16_C(29308), UINT16_C(37269), UINT16_C(46068), UINT16_C( 3408), UINT16_C(43415), UINT16_C( 4695), UINT16_C( 5331), UINT16_C(59192) },
       INT8_C(   1),
      UINT16_C(37269) },
    { { UINT16_C(42536), UINT16_C(51492), UINT16_C(34209), UINT16_C( 4203), UINT16_C(45703), UINT16_C( 3241), UINT16_C(16949), UINT16_C(42888) },
       INT8_C(   7),
      UINT16_C(42888) },
    { { UINT16_C(39705), UINT16_C(27274), UINT16_C( 8616), UINT16_C(   19), UINT16_C(58932), UINT16_C(27668), UINT16_C(19918), UINT16_C(29844) },
       INT8_C(   1),
      UINT16_C(27274) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    int b = test_vec[i].b;
    uint16_t r;
    SIMDE_CONSTIFY_8_(simde_vgetq_lane_u16, r, (HEDLEY_UNREACHABLE(), 0), b, a);
    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    int b;
    uint32_t r;
  } test_vec[] = {
    { { UINT32_C( 212833295), UINT32_C(2425004302), UINT32_C( 474038220), UINT32_C(2853920187) },
       INT8_C(   0),
      UINT32_C( 212833295) },
    { { UINT32_C(2233196758), UINT32_C(2390980779), UINT32_C(2474222548), UINT32_C(1419939520) },
       INT8_C(   1),
      UINT32_C(2390980779) },
    { { UINT32_C( 970875823), UINT32_C( 880388851), UINT32_C(3784455366), UINT32_C(3199696606) },
       INT8_C(   1),
      UINT32_C( 880388851) },
    { { UINT32_C(3222366780), UINT32_C(1919149560), UINT32_C( 452993912), UINT32_C(3670687095) },
       INT8_C(   3),
      UINT32_C(3670687095) },
    { { UINT32_C(2093338115), UINT32_C(2494598146), UINT32_C( 621973357), UINT32_C(3076631373) },
       INT8_C(   0),
      UINT32_C(2093338115) },
    { { UINT32_C(2225188897), UINT32_C( 581376546), UINT32_C(4284423989), UINT32_C(3338828537) },
       INT8_C(   3),
      UINT32_C(3338828537) },
    { { UINT32_C( 801884799), UINT32_C(1908291934), UINT32_C(3206286430), UINT32_C(1944181187) },
       INT8_C(   2),
      UINT32_C(3206286430) },
    { { UINT32_C( 227841381), UINT32_C( 372033975), UINT32_C(3415221704), UINT32_C(3075133677) },
       INT8_C(   3),
      UINT32_C(3075133677) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    int b = test_vec[i].b;
    uint32_t r;
    SIMDE_CONSTIFY_4_(simde_vgetq_lane_u32, r, (HEDLEY_UNREACHABLE(), 0), b, a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    int b;
    uint64_t r;
  } test_vec[] = {
    { { UINT64_C( 3092081787328485317), UINT64_C( 7985414882938276043) },
       INT8_C(   1),
      UINT64_C( 7985414882938276043) },
    { { UINT64_C( 7025058213030416194), UINT64_C( 6780364979241558092) },
       INT8_C(   1),
      UINT64_C( 6780364979241558092) },
    { { UINT64_C( 3391474989674094302), UINT64_C( 6056589457741813753) },
       INT8_C(   0),
      UINT64_C( 3391474989674094302) },
    { { UINT64_C( 2242727670204370304), UINT64_C(16289431355216962840) },
       INT8_C(   0),
      UINT64_C( 2242727670204370304) },
    { { UINT64_C(12501920663126502103), UINT64_C( 7356476994223244425) },
       INT8_C(   0),
      UINT64_C(12501920663126502103) },
    { { UINT64_C( 5069585831496340757), UINT64_C( 3089409691725716985) },
       INT8_C(   0),
      UINT64_C( 5069585831496340757) },
    { { UINT64_C( 8343717041656415431), UINT64_C( 6889051721661195117) },
       INT8_C(   1),
      UINT64_C( 6889051721661195117) },
    { { UINT64_C( 1010574439278891982), UINT64_C(12967946829539362128) },
       INT8_C(   1),
      UINT64_C(12967946829539362128) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    int b = test_vec[i].b;
    uint64_t r;
    SIMDE_CONSTIFY_2_(simde_vgetq_lane_u64, r, (HEDLEY_UNREACHABLE(), 0), b, a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly8_t a[16];
    int b;
    simde_poly8_t r;
  } test_vec[] = {
    { { SIMDE_POLY8_C(145), SIMDE_POLY8_C( 15), SIMDE_POLY8_C(109), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(127), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(163), SIMDE_POLY8_C(231) },
       INT8_C(   3),
      SIMDE_POLY8_C( 38) },
    { { SIMDE_POLY8_C( 26), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(190), SIMDE_POLY8_C(237), SIMDE_POLY8_C(178), SIMDE_POLY8_C(209), SIMDE_POLY8_C( 61), SIMDE_POLY8_C(  4) },
       INT8_C(   4),
      SIMDE_POLY8_C(178) },
    { { SIMDE_POLY8_C( 55), SIMDE_POLY8_C(139), SIMDE_POLY8_C( 83), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(209), SIMDE_POLY8_C( 70) },
       INT8_C(   0),
      SIMDE_POLY8_C( 55) },
    { { SIMDE_POLY8_C( 62), SIMDE_POLY8_C(144), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(169), SIMDE_POLY8_C( 34), SIMDE_POLY8_C( 25), SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 72) },
       INT8_C(   0),
      SIMDE_POLY8_C( 62) },
    { { SIMDE_POLY8_C( 92), SIMDE_POLY8_C(235), SIMDE_POLY8_C(127), SIMDE_POLY8_C(  0), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(189), SIMDE_POLY8_C(190), SIMDE_POLY8_C(243) },
       INT8_C(   7),
      SIMDE_POLY8_C(243) },
    { { SIMDE_POLY8_C(143), SIMDE_POLY8_C( 49), SIMDE_POLY8_C(115), SIMDE_POLY8_C(147), SIMDE_POLY8_C(104), SIMDE_POLY8_C(254), SIMDE_POLY8_C(231), SIMDE_POLY8_C(132) },
       INT8_C(   4),
      SIMDE_POLY8_C(104) },
    { { SIMDE_POLY8_C( 48), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(146), SIMDE_POLY8_C(200), SIMDE_POLY8_C(148), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(210), SIMDE_POLY8_C( 61) },
       INT8_C(   4),
      SIMDE_POLY8_C(148) },
    { { SIMDE_POLY8_C(235), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(141), SIMDE_POLY8_C(131), SIMDE_POLY8_C(177), SIMDE_POLY8_C(120), SIMDE_POLY8_C(  2), SIMDE_POLY8_C(177) },
       INT8_C(   6),
      SIMDE_POLY8_C(  2) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t a = simde_vld1_p8(test_vec[i].a);
    int b = test_vec[i].b;
    simde_poly8_t r;
    switch(b) {
      case 0: r = simde_vget_lane_p8(a, 0); break;
      case 1: r = simde_vget_lane_p8(a, 1); break;
      case 2: r = simde_vget_lane_p8(a, 2); break;
      case 3: r = simde_vget_lane_p8(a, 3); break;
      case 4: r = simde_vget_lane_p8(a, 4); break;
      case 5: r = simde_vget_lane_p8(a, 5); break;
      case 6: r = simde_vget_lane_p8(a, 6); break;
      case 7: r = simde_vget_lane_p8(a, 7); break;
      default: HEDLEY_UNREACHABLE(); r = 0; break;
    }

    simde_assert_equal_p8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly16_t a[4];
    int b;
    simde_poly16_t r;
  } test_vec[] = {
    { { SIMDE_POLY16_C(12419), SIMDE_POLY16_C(50038), SIMDE_POLY16_C(38877), SIMDE_POLY16_C(17206) },
       INT8_C(   2),
      SIMDE_POLY16_C(38877) },
    { { SIMDE_POLY16_C(48224), SIMDE_POLY16_C(21652), SIMDE_POLY16_C(15709), SIMDE_POLY16_C(31006) },
       INT8_C(   3),
      SIMDE_POLY16_C(31006) },
    { { SIMDE_POLY16_C(39237), SIMDE_POLY16_C(11133), SIMDE_POLY16_C(17423), SIMDE_POLY16_C(50851) },
       INT8_C(   2),
      SIMDE_POLY16_C(17423) },
    { { SIMDE_POLY16_C(48821), SIMDE_POLY16_C(47484), SIMDE_POLY16_C(44097), SIMDE_POLY16_C( 1071) },
       INT8_C(   2),
      SIMDE_POLY16_C(44097) },
    { { SIMDE_POLY16_C(15302), SIMDE_POLY16_C(28877), SIMDE_POLY16_C(35227), SIMDE_POLY16_C(61189) },
       INT8_C(   3),
      SIMDE_POLY16_C(61189) },
    { { SIMDE_POLY16_C( 3394), SIMDE_POLY16_C(19808), SIMDE_POLY16_C(63826), SIMDE_POLY16_C(32458) },
       INT8_C(   0),
      SIMDE_POLY16_C( 3394) },
    { { SIMDE_POLY16_C( 8462), SIMDE_POLY16_C(23759), SIMDE_POLY16_C(36311), SIMDE_POLY16_C(37080) },
       INT8_C(   2),
      SIMDE_POLY16_C(36311) },
    { { SIMDE_POLY16_C(49029), SIMDE_POLY16_C( 4051), SIMDE_POLY16_C( 3717), SIMDE_POLY16_C(63196) },
       INT8_C(   1),
      SIMDE_POLY16_C( 4051) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t a = simde_vld1_p16(test_vec[i].a);
    int b = test_vec[i].b;
    simde_poly16_t r;
    SIMDE_CONSTIFY_4_(simde_vget_lane_p16, r, (HEDLEY_UNREACHABLE(), 0), b, a);
    simde_assert_equal_p16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly64_t a[1];
    simde_poly64_t r;
  } test_vec[] = {
    { { SIMDE_POLY64_C( 8474713643211531917) },
      SIMDE_POLY64_C( 8474713643211531917) },
    { { SIMDE_POLY64_C( 4718805824424333625) },
      SIMDE_POLY64_C( 4718805824424333625) },
    { { SIMDE_POLY64_C( 2901443443683120557) },
      SIMDE_POLY64_C( 2901443443683120557) },
    { { SIMDE_POLY64_C(16896600451596749021) },
      SIMDE_POLY64_C(16896600451596749021) },
    { { SIMDE_POLY64_C( 2355020594457970359) },
      SIMDE_POLY64_C( 2355020594457970359) },
    { { SIMDE_POLY64_C(14871504216242625854) },
      SIMDE_POLY64_C(14871504216242625854) },
    { { SIMDE_POLY64_C(11884950968574087521) },
      SIMDE_POLY64_C(11884950968574087521) },
    { { SIMDE_POLY64_C(12253690780921831607) },
      SIMDE_POLY64_C(12253690780921831607) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1_t a = simde_vld1_p64(test_vec[i].a);
    simde_poly64_t r = simde_vget_lane_p64(a, 0);
    simde_assert_equal_p64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_p8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly8_t a[16];
    int b;
    simde_poly8_t r;
  } test_vec[] = {
    { { SIMDE_POLY8_C(217), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(111), SIMDE_POLY8_C(104), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(112), SIMDE_POLY8_C(195), SIMDE_POLY8_C( 29),
        SIMDE_POLY8_C(167), SIMDE_POLY8_C(167), SIMDE_POLY8_C( 53), SIMDE_POLY8_C(250), SIMDE_POLY8_C(196), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(127) },
       INT8_C(  14),
      SIMDE_POLY8_C( 22) },
    { { SIMDE_POLY8_C(166), SIMDE_POLY8_C(247), SIMDE_POLY8_C( 43), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(246), SIMDE_POLY8_C(230), SIMDE_POLY8_C(120), SIMDE_POLY8_C(202),
        SIMDE_POLY8_C(208), SIMDE_POLY8_C(134), SIMDE_POLY8_C(111), SIMDE_POLY8_C(125), SIMDE_POLY8_C( 17), SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(112) },
       INT8_C(   6),
      SIMDE_POLY8_C(120) },
    { { SIMDE_POLY8_C(191), SIMDE_POLY8_C(132), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(130), SIMDE_POLY8_C(161), SIMDE_POLY8_C(189), SIMDE_POLY8_C( 41), SIMDE_POLY8_C(214),
        SIMDE_POLY8_C(184), SIMDE_POLY8_C(237), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(206), SIMDE_POLY8_C(108), SIMDE_POLY8_C(103), SIMDE_POLY8_C(117), SIMDE_POLY8_C( 99) },
       INT8_C(   2),
      SIMDE_POLY8_C( 22) },
    { { SIMDE_POLY8_C(150), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(120), SIMDE_POLY8_C( 14), SIMDE_POLY8_C( 36), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(148), SIMDE_POLY8_C(147),
        SIMDE_POLY8_C(197), SIMDE_POLY8_C(166), SIMDE_POLY8_C(201), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(111), SIMDE_POLY8_C(219), SIMDE_POLY8_C(154) },
       INT8_C(   6),
      SIMDE_POLY8_C(148) },
    { { SIMDE_POLY8_C( 93), SIMDE_POLY8_C( 59), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(134), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(251), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 91),
        SIMDE_POLY8_C(202), SIMDE_POLY8_C(223), SIMDE_POLY8_C(194), SIMDE_POLY8_C( 63), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(213), SIMDE_POLY8_C(156) },
       INT8_C(  13),
      SIMDE_POLY8_C( 85) },
    { { SIMDE_POLY8_C(227), SIMDE_POLY8_C(192), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(120), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(219), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 28),
        SIMDE_POLY8_C(247), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(140), SIMDE_POLY8_C(210), SIMDE_POLY8_C(207), SIMDE_POLY8_C( 18), SIMDE_POLY8_C( 47), SIMDE_POLY8_C( 10) },
       INT8_C(   5),
      SIMDE_POLY8_C(219) },
    { { SIMDE_POLY8_C(181), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 81), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(119), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(  7), SIMDE_POLY8_C( 57),
        SIMDE_POLY8_C( 90), SIMDE_POLY8_C( 74), SIMDE_POLY8_C(142), SIMDE_POLY8_C( 47), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 18), SIMDE_POLY8_C(166) },
       INT8_C(   2),
      SIMDE_POLY8_C( 81) },
    { { SIMDE_POLY8_C(138), SIMDE_POLY8_C(249), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(168), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(221), SIMDE_POLY8_C(161),
        SIMDE_POLY8_C( 23), SIMDE_POLY8_C(172), SIMDE_POLY8_C(179), SIMDE_POLY8_C( 71), SIMDE_POLY8_C(182), SIMDE_POLY8_C(  9), SIMDE_POLY8_C(252), SIMDE_POLY8_C(210) },
       INT8_C(  10),
      SIMDE_POLY8_C(179) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    int b = test_vec[i].b;
    simde_poly8_t r;
    SIMDE_CONSTIFY_16_(simde_vgetq_lane_p8, r, (HEDLEY_UNREACHABLE(), 0), b, a);

    simde_assert_equal_p8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_p16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly16_t a[8];
    int b;
    simde_poly16_t r;
  } test_vec[] = {
    { { SIMDE_POLY16_C(61091), SIMDE_POLY16_C(53658), SIMDE_POLY16_C(16697), SIMDE_POLY16_C( 5906), SIMDE_POLY16_C( 8437), SIMDE_POLY16_C(24513), SIMDE_POLY16_C(37350), SIMDE_POLY16_C(20655) },
       INT8_C(   0),
      SIMDE_POLY16_C(61091) },
    { { SIMDE_POLY16_C(42027), SIMDE_POLY16_C(57525), SIMDE_POLY16_C(55191), SIMDE_POLY16_C(45942), SIMDE_POLY16_C( 7418), SIMDE_POLY16_C( 8850), SIMDE_POLY16_C(38827), SIMDE_POLY16_C(39366) },
       INT8_C(   1),
      SIMDE_POLY16_C(57525) },
    { { SIMDE_POLY16_C(53911), SIMDE_POLY16_C(43634), SIMDE_POLY16_C(26601), SIMDE_POLY16_C(43978), SIMDE_POLY16_C(45510), SIMDE_POLY16_C(30268), SIMDE_POLY16_C(29697), SIMDE_POLY16_C(42401) },
       INT8_C(   1),
      SIMDE_POLY16_C(43634) },
    { { SIMDE_POLY16_C(15490), SIMDE_POLY16_C(63489), SIMDE_POLY16_C(64495), SIMDE_POLY16_C(33044), SIMDE_POLY16_C(48926), SIMDE_POLY16_C(58393), SIMDE_POLY16_C(19032), SIMDE_POLY16_C(10875) },
       INT8_C(   5),
      SIMDE_POLY16_C(58393) },
    { { SIMDE_POLY16_C( 5157), SIMDE_POLY16_C(61476), SIMDE_POLY16_C(60351), SIMDE_POLY16_C(64417), SIMDE_POLY16_C(41569), SIMDE_POLY16_C(  623), SIMDE_POLY16_C(38983), SIMDE_POLY16_C(33668) },
       INT8_C(   1),
      SIMDE_POLY16_C(61476) },
    { { SIMDE_POLY16_C(29308), SIMDE_POLY16_C(37269), SIMDE_POLY16_C(46068), SIMDE_POLY16_C( 3408), SIMDE_POLY16_C(43415), SIMDE_POLY16_C( 4695), SIMDE_POLY16_C( 5331), SIMDE_POLY16_C(59192) },
       INT8_C(   1),
      SIMDE_POLY16_C(37269) },
    { { SIMDE_POLY16_C(42536), SIMDE_POLY16_C(51492), SIMDE_POLY16_C(34209), SIMDE_POLY16_C( 4203), SIMDE_POLY16_C(45703), SIMDE_POLY16_C( 3241), SIMDE_POLY16_C(16949), SIMDE_POLY16_C(42888) },
       INT8_C(   7),
      SIMDE_POLY16_C(42888) },
    { { SIMDE_POLY16_C(39705), SIMDE_POLY16_C(27274), SIMDE_POLY16_C( 8616), SIMDE_POLY16_C(   19), SIMDE_POLY16_C(58932), SIMDE_POLY16_C(27668), SIMDE_POLY16_C(19918), SIMDE_POLY16_C(29844) },
       INT8_C(   1),
      SIMDE_POLY16_C(27274) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    int b = test_vec[i].b;
    simde_poly16_t r;
    SIMDE_CONSTIFY_8_(simde_vgetq_lane_p16, r, (HEDLEY_UNREACHABLE(), 0), b, a);
    simde_assert_equal_p16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vgetq_lane_p64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_poly64_t a[2];
    int b;
    simde_poly64_t r;
  } test_vec[] = {
    { { SIMDE_POLY64_C( 3092081787328485317), SIMDE_POLY64_C( 7985414882938276043) },
       INT8_C(   1),
      SIMDE_POLY64_C( 7985414882938276043) },
    { { SIMDE_POLY64_C( 7025058213030416194), SIMDE_POLY64_C( 6780364979241558092) },
       INT8_C(   1),
      SIMDE_POLY64_C( 6780364979241558092) },
    { { SIMDE_POLY64_C( 3391474989674094302), SIMDE_POLY64_C( 6056589457741813753) },
       INT8_C(   0),
      SIMDE_POLY64_C( 3391474989674094302) },
    { { SIMDE_POLY64_C( 2242727670204370304), SIMDE_POLY64_C(16289431355216962840) },
       INT8_C(   0),
      SIMDE_POLY64_C( 2242727670204370304) },
    { { SIMDE_POLY64_C(12501920663126502103), SIMDE_POLY64_C( 7356476994223244425) },
       INT8_C(   0),
      SIMDE_POLY64_C(12501920663126502103) },
    { { SIMDE_POLY64_C( 5069585831496340757), SIMDE_POLY64_C( 3089409691725716985) },
       INT8_C(   0),
      SIMDE_POLY64_C( 5069585831496340757) },
    { { SIMDE_POLY64_C( 8343717041656415431), SIMDE_POLY64_C( 6889051721661195117) },
       INT8_C(   1),
      SIMDE_POLY64_C( 6889051721661195117) },
    { { SIMDE_POLY64_C( 1010574439278891982), SIMDE_POLY64_C(12967946829539362128) },
       INT8_C(   1),
      SIMDE_POLY64_C(12967946829539362128) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2_t a = simde_vld1q_p64(test_vec[i].a);
    int b = test_vec[i].b;
    simde_poly64_t r;
    SIMDE_CONSTIFY_2_(simde_vgetq_lane_p64, r, (HEDLEY_UNREACHABLE(), 0), b, a);
    simde_assert_equal_p64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vget_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16 a[4];
    int b;
    simde_bfloat16 r;
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(    70.00), SIMDE_BFLOAT16_VALUE(    90.50), SIMDE_BFLOAT16_VALUE(    51.50), SIMDE_BFLOAT16_VALUE(   -79.50) },
       INT32_C(           1),
      SIMDE_BFLOAT16_VALUE(    90.50) },
    { { SIMDE_BFLOAT16_VALUE(   -23.88), SIMDE_BFLOAT16_VALUE(   -43.50), SIMDE_BFLOAT16_VALUE(    61.50), SIMDE_BFLOAT16_VALUE(    35.25) },
       INT32_C(           2),
      SIMDE_BFLOAT16_VALUE(    61.50) },
    { { SIMDE_BFLOAT16_VALUE(   -91.00), SIMDE_BFLOAT16_VALUE(   -59.75), SIMDE_BFLOAT16_VALUE(    91.50), SIMDE_BFLOAT16_VALUE(    54.25) },
       INT32_C(           3),
      SIMDE_BFLOAT16_VALUE(    54.25) },
    { { SIMDE_BFLOAT16_VALUE(   -56.50), SIMDE_BFLOAT16_VALUE(    40.50), SIMDE_BFLOAT16_VALUE(   -32.50), SIMDE_BFLOAT16_VALUE(   -29.88) },
       INT32_C(           3),
      SIMDE_BFLOAT16_VALUE(   -29.88) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {

    simde_bfloat16x4_t a = simde_vld1_bf16(test_vec[i].a);
    int b = test_vec[i].b;
    simde_bfloat16 r;
    SIMDE_CONSTIFY_4_(simde_vget_lane_bf16, r, (HEDLEY_UNREACHABLE(), SIMDE_BFLOAT16_VALUE(0.0)), b, a);

    simde_assert_equal_bf16(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_bfloat16x4_t a = simde_test_arm_neon_random_bf16x4(SIMDE_BFLOAT16_VALUE(-100.0), SIMDE_BFLOAT16_VALUE(100.0));
    int lane = simde_test_codegen_random_i8() & 3;
    simde_bfloat16_t r;
    SIMDE_CONSTIFY_4_(simde_vget_lane_bf16, r, (HEDLEY_UNREACHABLE(), SIMDE_BFLOAT16_VALUE(-100.0)), lane, a);

    simde_test_arm_neon_write_bf16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_bf16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vgetq_lane_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16 a[8];
    int b;
    simde_bfloat16 r;
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(    -7.41), SIMDE_BFLOAT16_VALUE(    29.62), SIMDE_BFLOAT16_VALUE(   -78.50), SIMDE_BFLOAT16_VALUE(    93.00),
        SIMDE_BFLOAT16_VALUE(   -23.62), SIMDE_BFLOAT16_VALUE(   -42.00), SIMDE_BFLOAT16_VALUE(    16.62), SIMDE_BFLOAT16_VALUE(    54.75) },
       INT32_C(           5),
      SIMDE_BFLOAT16_VALUE(   -42.00) },
    { { SIMDE_BFLOAT16_VALUE(   -74.00), SIMDE_BFLOAT16_VALUE(    82.00), SIMDE_BFLOAT16_VALUE(    20.62), SIMDE_BFLOAT16_VALUE(   -37.25),
        SIMDE_BFLOAT16_VALUE(    84.00), SIMDE_BFLOAT16_VALUE(    38.25), SIMDE_BFLOAT16_VALUE(    74.00), SIMDE_BFLOAT16_VALUE(   -99.00) },
       INT32_C(           2),
      SIMDE_BFLOAT16_VALUE(    20.62) },
    { { SIMDE_BFLOAT16_VALUE(   -33.00), SIMDE_BFLOAT16_VALUE(    85.00), SIMDE_BFLOAT16_VALUE(   -66.00), SIMDE_BFLOAT16_VALUE(   -94.50),
        SIMDE_BFLOAT16_VALUE(   -63.00), SIMDE_BFLOAT16_VALUE(   -86.00), SIMDE_BFLOAT16_VALUE(   -22.25), SIMDE_BFLOAT16_VALUE(    19.62) },
       INT32_C(           4),
      SIMDE_BFLOAT16_VALUE(   -63.00) },
    { { SIMDE_BFLOAT16_VALUE(    46.00), SIMDE_BFLOAT16_VALUE(    82.00), SIMDE_BFLOAT16_VALUE(    51.25), SIMDE_BFLOAT16_VALUE(    47.50),
        SIMDE_BFLOAT16_VALUE(   -25.38), SIMDE_BFLOAT16_VALUE(   -19.12), SIMDE_BFLOAT16_VALUE(    68.50), SIMDE_BFLOAT16_VALUE(   -32.50) },
       INT32_C(           0),
      SIMDE_BFLOAT16_VALUE(    46.00) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {

    simde_bfloat16x8_t a = simde_vld1q_bf16(test_vec[i].a);
    int b = test_vec[i].b;
    simde_bfloat16 r;
    SIMDE_CONSTIFY_8_(simde_vgetq_lane_bf16, r, (HEDLEY_UNREACHABLE(), SIMDE_BFLOAT16_VALUE(0.0)), b, a);

    simde_assert_equal_bf16(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_bfloat16x8_t a = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-100.0), SIMDE_BFLOAT16_VALUE(100.0));
    int lane = simde_test_codegen_random_i8() & 7;
    simde_bfloat16_t r;
    SIMDE_CONSTIFY_8_(simde_vgetq_lane_bf16, r, (HEDLEY_UNREACHABLE(), SIMDE_BFLOAT16_VALUE(-100.0)), lane, a);

    simde_test_arm_neon_write_bf16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_bf16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_p64)

SIMDE_TEST_FUNC_LIST_ENTRY(vget_lane_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vgetq_lane_bf16)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
