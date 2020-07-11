#define SIMDE_TEST_ARM_NEON_INSN get_low

#include "test-neon.h"
#include "../../../simde/arm/neon/get_low.h"

static int
test_simde_vget_low_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -618.44), SIMDE_FLOAT32_C(  -264.56), SIMDE_FLOAT32_C(   635.79), SIMDE_FLOAT32_C(   558.25) },
      { SIMDE_FLOAT32_C(  -618.44), SIMDE_FLOAT32_C(  -264.56) } },
    { { SIMDE_FLOAT32_C(  -758.55), SIMDE_FLOAT32_C(   584.32), SIMDE_FLOAT32_C(   478.21), SIMDE_FLOAT32_C(  -463.12) },
      { SIMDE_FLOAT32_C(  -758.55), SIMDE_FLOAT32_C(   584.32) } },
    { { SIMDE_FLOAT32_C(  -948.98), SIMDE_FLOAT32_C(  -867.33), SIMDE_FLOAT32_C(   729.13), SIMDE_FLOAT32_C(   324.50) },
      { SIMDE_FLOAT32_C(  -948.98), SIMDE_FLOAT32_C(  -867.33) } },
    { { SIMDE_FLOAT32_C(  -385.61), SIMDE_FLOAT32_C(  -150.04), SIMDE_FLOAT32_C(  -341.48), SIMDE_FLOAT32_C(  -404.96) },
      { SIMDE_FLOAT32_C(  -385.61), SIMDE_FLOAT32_C(  -150.04) } },
    { { SIMDE_FLOAT32_C(   568.77), SIMDE_FLOAT32_C(   261.80), SIMDE_FLOAT32_C(   803.98), SIMDE_FLOAT32_C(  -772.87) },
      { SIMDE_FLOAT32_C(   568.77), SIMDE_FLOAT32_C(   261.80) } },
    { { SIMDE_FLOAT32_C(   656.21), SIMDE_FLOAT32_C(   633.91), SIMDE_FLOAT32_C(  -959.69), SIMDE_FLOAT32_C(   161.89) },
      { SIMDE_FLOAT32_C(   656.21), SIMDE_FLOAT32_C(   633.91) } },
    { { SIMDE_FLOAT32_C(   160.28), SIMDE_FLOAT32_C(  -927.68), SIMDE_FLOAT32_C(   797.28), SIMDE_FLOAT32_C(   950.20) },
      { SIMDE_FLOAT32_C(   160.28), SIMDE_FLOAT32_C(  -927.68) } },
    { { SIMDE_FLOAT32_C(    50.38), SIMDE_FLOAT32_C(   496.87), SIMDE_FLOAT32_C(   994.83), SIMDE_FLOAT32_C(   431.94) },
      { SIMDE_FLOAT32_C(    50.38), SIMDE_FLOAT32_C(   496.87) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a;
    simde_float32x2_t r;

    a = simde_vld1q_f32(test_vec[i].a);
    r = simde_vget_low_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vget_low_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   587.42), SIMDE_FLOAT64_C(  -708.35) },
      { SIMDE_FLOAT64_C(   587.42) } },
    { { SIMDE_FLOAT64_C(   444.89), SIMDE_FLOAT64_C(  -898.30) },
      { SIMDE_FLOAT64_C(   444.89) } },
    { { SIMDE_FLOAT64_C(   950.88), SIMDE_FLOAT64_C(   657.56) },
      { SIMDE_FLOAT64_C(   950.88) } },
    { { SIMDE_FLOAT64_C(   -17.67), SIMDE_FLOAT64_C(  -677.48) },
      { SIMDE_FLOAT64_C(   -17.67) } },
    { { SIMDE_FLOAT64_C(  -738.88), SIMDE_FLOAT64_C(   843.84) },
      { SIMDE_FLOAT64_C(  -738.88) } },
    { { SIMDE_FLOAT64_C(   933.98), SIMDE_FLOAT64_C(   432.45) },
      { SIMDE_FLOAT64_C(   933.98) } },
    { { SIMDE_FLOAT64_C(   713.24), SIMDE_FLOAT64_C(  -937.79) },
      { SIMDE_FLOAT64_C(   713.24) } },
    { { SIMDE_FLOAT64_C(  -634.19), SIMDE_FLOAT64_C(  -779.71) },
      { SIMDE_FLOAT64_C(  -634.19) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x1_t r = simde_vget_low_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vget_low_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  50),  INT8_C(  25), -INT8_C(   2), -INT8_C( 103),  INT8_C( 121), -INT8_C(  72),  INT8_C(  60),  INT8_C(  40),
        -INT8_C( 124), -INT8_C(  21), -INT8_C(  26),  INT8_C(  20),  INT8_C(   1), -INT8_C( 116), -INT8_C(  14),  INT8_C( 113) },
      { -INT8_C(  50),  INT8_C(  25), -INT8_C(   2), -INT8_C( 103),  INT8_C( 121), -INT8_C(  72),  INT8_C(  60),  INT8_C(  40) } },
    { { -INT8_C(  31),  INT8_C(  36), -INT8_C(  55),  INT8_C( 120), -INT8_C(  82),  INT8_C( 112),      INT8_MIN, -INT8_C(  68),
         INT8_C( 110),  INT8_C( 121), -INT8_C( 124), -INT8_C(  81),  INT8_C(  39), -INT8_C(  40),  INT8_C(  49), -INT8_C(  11) },
      { -INT8_C(  31),  INT8_C(  36), -INT8_C(  55),  INT8_C( 120), -INT8_C(  82),  INT8_C( 112),      INT8_MIN, -INT8_C(  68) } },
    { { -INT8_C(  14),  INT8_C(  47), -INT8_C( 114),  INT8_C( 107), -INT8_C(  25), -INT8_C(  54), -INT8_C( 109),  INT8_C( 107),
        -INT8_C(  74),  INT8_C( 122),      INT8_MAX, -INT8_C(  73),  INT8_C(   6),  INT8_C( 113),  INT8_C(  41), -INT8_C(  25) },
      { -INT8_C(  14),  INT8_C(  47), -INT8_C( 114),  INT8_C( 107), -INT8_C(  25), -INT8_C(  54), -INT8_C( 109),  INT8_C( 107) } },
    { { -INT8_C( 107), -INT8_C(  14),  INT8_C(  95),  INT8_C(  67),  INT8_C(  98), -INT8_C(  33), -INT8_C(   1), -INT8_C(  47),
         INT8_C(  89), -INT8_C( 125),      INT8_MIN,      INT8_MIN,  INT8_C(  92), -INT8_C(  78),  INT8_C( 117),  INT8_C(  78) },
      { -INT8_C( 107), -INT8_C(  14),  INT8_C(  95),  INT8_C(  67),  INT8_C(  98), -INT8_C(  33), -INT8_C(   1), -INT8_C(  47) } },
    { { -INT8_C(  31),  INT8_C(   3), -INT8_C(  71), -INT8_C(  55), -INT8_C(  50),  INT8_C(  76),  INT8_C(  52), -INT8_C( 124),
        -INT8_C(  58), -INT8_C(  76),  INT8_C(  59), -INT8_C(  52),  INT8_C(  37),  INT8_C( 100), -INT8_C(  76), -INT8_C(  69) },
      { -INT8_C(  31),  INT8_C(   3), -INT8_C(  71), -INT8_C(  55), -INT8_C(  50),  INT8_C(  76),  INT8_C(  52), -INT8_C( 124) } },
    { {  INT8_C(  87),  INT8_C(  19), -INT8_C(   2), -INT8_C(  71), -INT8_C(  13), -INT8_C(   2), -INT8_C( 118),  INT8_C(  76),
        -INT8_C( 127),  INT8_C(  11), -INT8_C(  52), -INT8_C(  35), -INT8_C(  67),  INT8_C(  65),  INT8_C(  43), -INT8_C(  98) },
      {  INT8_C(  87),  INT8_C(  19), -INT8_C(   2), -INT8_C(  71), -INT8_C(  13), -INT8_C(   2), -INT8_C( 118),  INT8_C(  76) } },
    { {  INT8_C(  68), -INT8_C(  28),  INT8_C( 103),  INT8_C(  18),  INT8_C(  49), -INT8_C( 100), -INT8_C( 106), -INT8_C(   9),
         INT8_C(  80), -INT8_C(  46), -INT8_C(  60),  INT8_C( 117),  INT8_C(  54),  INT8_C( 120),  INT8_C(  48), -INT8_C( 115) },
      {  INT8_C(  68), -INT8_C(  28),  INT8_C( 103),  INT8_C(  18),  INT8_C(  49), -INT8_C( 100), -INT8_C( 106), -INT8_C(   9) } },
    { { -INT8_C( 117),  INT8_C(  47),  INT8_C(  71),  INT8_C( 126),  INT8_C(  45), -INT8_C(  47), -INT8_C(  54), -INT8_C(  82),
        -INT8_C(  36), -INT8_C( 106), -INT8_C( 116), -INT8_C( 103), -INT8_C(  41), -INT8_C(  73),  INT8_C(  56),  INT8_C(  28) },
      { -INT8_C( 117),  INT8_C(  47),  INT8_C(  71),  INT8_C( 126),  INT8_C(  45), -INT8_C(  47), -INT8_C(  54), -INT8_C(  82) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vget_low_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vget_low_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(  8842), -INT16_C( 21774),  INT16_C( 23919),  INT16_C(  1631), -INT16_C( 24130), -INT16_C(  3644), -INT16_C(  1346), -INT16_C( 21416) },
      { -INT16_C(  8842), -INT16_C( 21774),  INT16_C( 23919),  INT16_C(  1631) } },
    { {  INT16_C( 16724),  INT16_C( 30279), -INT16_C(  6849),  INT16_C( 31437), -INT16_C( 14479), -INT16_C( 16413), -INT16_C( 19162), -INT16_C( 25537) },
      {  INT16_C( 16724),  INT16_C( 30279), -INT16_C(  6849),  INT16_C( 31437) } },
    { {  INT16_C( 12690),  INT16_C(   582), -INT16_C( 23153),  INT16_C( 19720), -INT16_C( 12986),  INT16_C(  1342), -INT16_C( 26937),  INT16_C(  7089) },
      {  INT16_C( 12690),  INT16_C(   582), -INT16_C( 23153),  INT16_C( 19720) } },
    { { -INT16_C(  1576),  INT16_C(  6034),  INT16_C( 24542),  INT16_C( 20370),  INT16_C( 29990),  INT16_C( 19470),  INT16_C( 19754), -INT16_C( 16920) },
      { -INT16_C(  1576),  INT16_C(  6034),  INT16_C( 24542),  INT16_C( 20370) } },
    { {  INT16_C( 11903),  INT16_C(  3775), -INT16_C( 14381),  INT16_C(  6747), -INT16_C( 26220),  INT16_C( 23327), -INT16_C( 12240),  INT16_C(  2167) },
      {  INT16_C( 11903),  INT16_C(  3775), -INT16_C( 14381),  INT16_C(  6747) } },
    { {  INT16_C(  2505), -INT16_C( 22753), -INT16_C( 20120), -INT16_C( 28682),  INT16_C(  1062),  INT16_C( 20955), -INT16_C( 15278), -INT16_C( 12018) },
      {  INT16_C(  2505), -INT16_C( 22753), -INT16_C( 20120), -INT16_C( 28682) } },
    { { -INT16_C( 12814), -INT16_C( 14625),  INT16_C( 14996),  INT16_C( 10720), -INT16_C(    45),  INT16_C(   900), -INT16_C(  1073), -INT16_C( 26357) },
      { -INT16_C( 12814), -INT16_C( 14625),  INT16_C( 14996),  INT16_C( 10720) } },
    { {  INT16_C( 11012),  INT16_C( 27968),  INT16_C( 14300),  INT16_C(  1020), -INT16_C( 10437), -INT16_C( 29356),  INT16_C( 25243), -INT16_C( 29090) },
      {  INT16_C( 11012),  INT16_C( 27968),  INT16_C( 14300),  INT16_C(  1020) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vget_low_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vget_low_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  2072489384),  INT32_C(  1176990042),  INT32_C(   492144110), -INT32_C(  1353512510) },
      { -INT32_C(  2072489384),  INT32_C(  1176990042) } },
    { {  INT32_C(   476637811), -INT32_C(   628344084),  INT32_C(  1839877601), -INT32_C(  1813123782) },
      {  INT32_C(   476637811), -INT32_C(   628344084) } },
    { { -INT32_C(  1709742785), -INT32_C(   975159337), -INT32_C(  2031995452), -INT32_C(  1321913026) },
      { -INT32_C(  1709742785), -INT32_C(   975159337) } },
    { {  INT32_C(   198024479), -INT32_C(  1192863273), -INT32_C(   517631834), -INT32_C(  1116466307) },
      {  INT32_C(   198024479), -INT32_C(  1192863273) } },
    { {  INT32_C(  1331137400), -INT32_C(  1911277622), -INT32_C(  1424623764),  INT32_C(  1281116716) },
      {  INT32_C(  1331137400), -INT32_C(  1911277622) } },
    { { -INT32_C(  1084806424),  INT32_C(   712523139),  INT32_C(  1259052494),  INT32_C(   688422832) },
      { -INT32_C(  1084806424),  INT32_C(   712523139) } },
    { { -INT32_C(   713531638),  INT32_C(    56855958), -INT32_C(  1330743164), -INT32_C(  1409545533) },
      { -INT32_C(   713531638),  INT32_C(    56855958) } },
    { { -INT32_C(  1200991180),  INT32_C(  1608704657),  INT32_C(   816573824),  INT32_C(  1985590124) },
      { -INT32_C(  1200991180),  INT32_C(  1608704657) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x2_t r = simde_vget_low_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vget_low_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 5552791125174468305),  INT64_C( 7690059133849055532) },
      { -INT64_C( 5552791125174468305) } },
    { { -INT64_C( 3464544314608880100), -INT64_C( 8271590384803619907) },
      { -INT64_C( 3464544314608880100) } },
    { { -INT64_C( 1170727257668501975),  INT64_C( 4855309375206429422) },
      { -INT64_C( 1170727257668501975) } },
    { { -INT64_C( 5109208448872577540), -INT64_C( 1605646795316963380) },
      { -INT64_C( 5109208448872577540) } },
    { {  INT64_C( 3425469384464172246), -INT64_C( 2832050735323589047) },
      {  INT64_C( 3425469384464172246) } },
    { {  INT64_C( 8557466743929387021), -INT64_C( 7766078508003940975) },
      {  INT64_C( 8557466743929387021) } },
    { {  INT64_C( 3408864166942748893),  INT64_C(  847329830903969037) },
      {  INT64_C( 3408864166942748893) } },
    { { -INT64_C( 5788577846308576118), -INT64_C( 9129014539981992964) },
      { -INT64_C( 5788577846308576118) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x1_t r = simde_vget_low_s64(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vget_low_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 49), UINT8_C( 19), UINT8_C( 24), UINT8_C(135), UINT8_C(231), UINT8_C( 68), UINT8_C(165), UINT8_C( 18),
        UINT8_C( 76), UINT8_C(174), UINT8_C(105), UINT8_C(  5), UINT8_C( 66), UINT8_C( 84), UINT8_C(216), UINT8_C( 35) },
      { UINT8_C( 49), UINT8_C( 19), UINT8_C( 24), UINT8_C(135), UINT8_C(231), UINT8_C( 68), UINT8_C(165), UINT8_C( 18) } },
    { { UINT8_C(191), UINT8_C(201), UINT8_C(125), UINT8_C(100), UINT8_C(129), UINT8_C(173), UINT8_C( 89), UINT8_C( 59),
        UINT8_C(167), UINT8_C( 49), UINT8_C(196), UINT8_C(147), UINT8_C(153), UINT8_C( 43), UINT8_C(139), UINT8_C(202) },
      { UINT8_C(191), UINT8_C(201), UINT8_C(125), UINT8_C(100), UINT8_C(129), UINT8_C(173), UINT8_C( 89), UINT8_C( 59) } },
    { { UINT8_C( 62), UINT8_C(163), UINT8_C( 81), UINT8_C( 37), UINT8_C(231), UINT8_C(247), UINT8_C( 55), UINT8_C( 52),
        UINT8_C(165), UINT8_C(160), UINT8_C( 57), UINT8_C(232), UINT8_C(244), UINT8_C( 17), UINT8_C( 11), UINT8_C(179) },
      { UINT8_C( 62), UINT8_C(163), UINT8_C( 81), UINT8_C( 37), UINT8_C(231), UINT8_C(247), UINT8_C( 55), UINT8_C( 52) } },
    { { UINT8_C(218), UINT8_C(136), UINT8_C( 24), UINT8_C( 92), UINT8_C( 54), UINT8_C(113), UINT8_C(151), UINT8_C(221),
        UINT8_C(163), UINT8_C( 91), UINT8_C(113), UINT8_C( 60), UINT8_C(134), UINT8_C(252), UINT8_C(  6), UINT8_C(196) },
      { UINT8_C(218), UINT8_C(136), UINT8_C( 24), UINT8_C( 92), UINT8_C( 54), UINT8_C(113), UINT8_C(151), UINT8_C(221) } },
    { { UINT8_C(159), UINT8_C( 88), UINT8_C(233), UINT8_C(135), UINT8_C( 79), UINT8_C( 32), UINT8_C(187), UINT8_C(244),
        UINT8_C(193), UINT8_C(244), UINT8_C(220), UINT8_C(181), UINT8_C(  5), UINT8_C(232), UINT8_C(105), UINT8_C(224) },
      { UINT8_C(159), UINT8_C( 88), UINT8_C(233), UINT8_C(135), UINT8_C( 79), UINT8_C( 32), UINT8_C(187), UINT8_C(244) } },
    { { UINT8_C(112), UINT8_C(129), UINT8_C( 60), UINT8_C(166), UINT8_C(242), UINT8_C(211), UINT8_C(132), UINT8_C(149),
        UINT8_C( 46), UINT8_C(245), UINT8_C(209), UINT8_C(180), UINT8_C(241), UINT8_C(216), UINT8_C(120), UINT8_C(144) },
      { UINT8_C(112), UINT8_C(129), UINT8_C( 60), UINT8_C(166), UINT8_C(242), UINT8_C(211), UINT8_C(132), UINT8_C(149) } },
    { { UINT8_C( 48), UINT8_C( 97), UINT8_C( 23), UINT8_C(127), UINT8_C(129), UINT8_C(210), UINT8_C(115), UINT8_C( 66),
        UINT8_C(198), UINT8_C( 80), UINT8_C(248), UINT8_C(204), UINT8_C( 56), UINT8_C( 97), UINT8_C(172), UINT8_C(168) },
      { UINT8_C( 48), UINT8_C( 97), UINT8_C( 23), UINT8_C(127), UINT8_C(129), UINT8_C(210), UINT8_C(115), UINT8_C( 66) } },
    { { UINT8_C(226), UINT8_C(232), UINT8_C( 79), UINT8_C(212), UINT8_C(187), UINT8_C(211), UINT8_C(106), UINT8_C(233),
        UINT8_C(200), UINT8_C( 59), UINT8_C(157), UINT8_C(185), UINT8_C( 19), UINT8_C( 21), UINT8_C( 73), UINT8_C( 67) },
      { UINT8_C(226), UINT8_C(232), UINT8_C( 79), UINT8_C(212), UINT8_C(187), UINT8_C(211), UINT8_C(106), UINT8_C(233) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x8_t r = simde_vget_low_u8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vget_low_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(63133), UINT16_C( 3112), UINT16_C(63250), UINT16_C(53711), UINT16_C( 3909), UINT16_C(60069), UINT16_C(17310), UINT16_C(25373) },
      { UINT16_C(63133), UINT16_C( 3112), UINT16_C(63250), UINT16_C(53711) } },
    { { UINT16_C( 1988), UINT16_C(43042), UINT16_C(34217), UINT16_C( 3759), UINT16_C(49039), UINT16_C(16267), UINT16_C( 8488), UINT16_C(50799) },
      { UINT16_C( 1988), UINT16_C(43042), UINT16_C(34217), UINT16_C( 3759) } },
    { { UINT16_C(38679), UINT16_C(10706), UINT16_C(41614), UINT16_C(54266), UINT16_C(41137), UINT16_C(20670), UINT16_C(56291), UINT16_C(42931) },
      { UINT16_C(38679), UINT16_C(10706), UINT16_C(41614), UINT16_C(54266) } },
    { { UINT16_C(55010), UINT16_C(35663), UINT16_C(65115), UINT16_C(60058), UINT16_C( 9662), UINT16_C(58921), UINT16_C(38983), UINT16_C(24236) },
      { UINT16_C(55010), UINT16_C(35663), UINT16_C(65115), UINT16_C(60058) } },
    { { UINT16_C(32560), UINT16_C(48776), UINT16_C(33313), UINT16_C(53906), UINT16_C(20514), UINT16_C( 1314), UINT16_C(54827), UINT16_C( 3500) },
      { UINT16_C(32560), UINT16_C(48776), UINT16_C(33313), UINT16_C(53906) } },
    { { UINT16_C(64428), UINT16_C( 1944), UINT16_C(13050), UINT16_C(47345), UINT16_C( 6744), UINT16_C(40862), UINT16_C(19378), UINT16_C(58109) },
      { UINT16_C(64428), UINT16_C( 1944), UINT16_C(13050), UINT16_C(47345) } },
    { { UINT16_C(34250), UINT16_C(60321), UINT16_C(13064), UINT16_C(10941), UINT16_C(57475), UINT16_C(44592), UINT16_C(56502), UINT16_C(25275) },
      { UINT16_C(34250), UINT16_C(60321), UINT16_C(13064), UINT16_C(10941) } },
    { { UINT16_C(21464), UINT16_C(53865), UINT16_C(23174), UINT16_C(56970), UINT16_C(10356), UINT16_C( 9853), UINT16_C(31347), UINT16_C(15625) },
      { UINT16_C(21464), UINT16_C(53865), UINT16_C(23174), UINT16_C(56970) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x4_t r = simde_vget_low_u16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vget_low_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 664864438), UINT32_C(1031793488), UINT32_C(3797458318), UINT32_C(2293678734) },
      { UINT32_C( 664864438), UINT32_C(1031793488) } },
    { { UINT32_C(2911591410), UINT32_C(2619020298), UINT32_C(3774382299), UINT32_C(3514230811) },
      { UINT32_C(2911591410), UINT32_C(2619020298) } },
    { { UINT32_C(1056446702), UINT32_C(2440787715), UINT32_C(2725565204), UINT32_C(2284464790) },
      { UINT32_C(1056446702), UINT32_C(2440787715) } },
    { { UINT32_C(2402727301), UINT32_C(2771145162), UINT32_C(3984925905), UINT32_C(4206820364) },
      { UINT32_C(2402727301), UINT32_C(2771145162) } },
    { { UINT32_C( 389658388), UINT32_C(1135129646), UINT32_C( 518331528), UINT32_C(3433435206) },
      { UINT32_C( 389658388), UINT32_C(1135129646) } },
    { { UINT32_C(2405162181), UINT32_C(4281698093), UINT32_C(3102522028), UINT32_C(3400772278) },
      { UINT32_C(2405162181), UINT32_C(4281698093) } },
    { { UINT32_C(2430725217), UINT32_C( 684952224), UINT32_C(3980834982), UINT32_C(2394549704) },
      { UINT32_C(2430725217), UINT32_C( 684952224) } },
    { { UINT32_C(4145878217), UINT32_C(1224102556), UINT32_C(3271614989), UINT32_C(4002329484) },
      { UINT32_C(4145878217), UINT32_C(1224102556) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x2_t r = simde_vget_low_u32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vget_low_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(10622998194429045261), UINT64_C( 7741122720249478585) },
      { UINT64_C(10622998194429045261) } },
    { { UINT64_C(17660482733443859451), UINT64_C( 7088876185833046643) },
      { UINT64_C(17660482733443859451) } },
    { { UINT64_C( 2310614234654306281), UINT64_C( 3924073685936192752) },
      { UINT64_C( 2310614234654306281) } },
    { { UINT64_C( 7192069315162950751), UINT64_C(14345906403414384222) },
      { UINT64_C( 7192069315162950751) } },
    { { UINT64_C( 9321418311508205012), UINT64_C( 9800114439348489361) },
      { UINT64_C( 9321418311508205012) } },
    { { UINT64_C(  260981884868249677), UINT64_C(15993633616004850767) },
      { UINT64_C(  260981884868249677) } },
    { { UINT64_C( 2124984947085752427), UINT64_C( 6211284163340339586) },
      { UINT64_C( 2124984947085752427) } },
    { { UINT64_C( 1574626849321096242), UINT64_C(14500806154155888982) },
      { UINT64_C( 1574626849321096242) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x1_t r = simde_vget_low_u64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vget_low_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_low_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_low_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_low_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_low_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_low_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_low_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_low_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_low_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vget_low_u64)

SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
