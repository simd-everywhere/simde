#define SIMDE_TEST_ARM_NEON_INSN ld2

#include "test-neon.h"
#include "../../../simde/arm/neon/ld2.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vld2_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r[2][8];
  } test_vec[] = {
    { { -INT8_C(  68),  INT8_C(  76),  INT8_C( 126), -INT8_C(  73), -INT8_C(  89),  INT8_C(  54),  INT8_C(  92), -INT8_C(  47),
        -INT8_C(  92),  INT8_C( 107), -INT8_C(  48),  INT8_C(  54),  INT8_C(  35), -INT8_C(  53), -INT8_C(  80),  INT8_C(  34) },
        { { -INT8_C(  68),  INT8_C( 126), -INT8_C(  89),  INT8_C(  92), -INT8_C(  92), -INT8_C(  48),  INT8_C(  35), -INT8_C(  80) },
          {  INT8_C(  76), -INT8_C(  73),  INT8_C(  54), -INT8_C(  47),  INT8_C( 107),  INT8_C(  54), -INT8_C(  53),  INT8_C(  34) } },
    },
    { { -INT8_C(  90), -INT8_C(  85),  INT8_C(  93), -INT8_C(  59), -INT8_C( 121), -INT8_C(  55),  INT8_C(   2), -INT8_C( 111),
         INT8_C(  49),  INT8_C(  61),  INT8_C(   4), -INT8_C(  65),  INT8_C(  56),  INT8_C(  54), -INT8_C( 101), -INT8_C(  12) },
        { { -INT8_C(  90),  INT8_C(  93), -INT8_C( 121),  INT8_C(   2),  INT8_C(  49),  INT8_C(   4),  INT8_C(  56), -INT8_C( 101) },
          { -INT8_C(  85), -INT8_C(  59), -INT8_C(  55), -INT8_C( 111),  INT8_C(  61), -INT8_C(  65),  INT8_C(  54), -INT8_C(  12) } },
    },
    { { -INT8_C( 126),  INT8_C(  25), -INT8_C(  85),  INT8_C(  41),  INT8_C(  80),  INT8_C(   8), -INT8_C(   5), -INT8_C(  12),
         INT8_C( 115), -INT8_C(  53),  INT8_C(  42), -INT8_C( 105), -INT8_C( 106), -INT8_C(  38), -INT8_C(  71),  INT8_C(  61) },
        { { -INT8_C( 126), -INT8_C(  85),  INT8_C(  80), -INT8_C(   5),  INT8_C( 115),  INT8_C(  42), -INT8_C( 106), -INT8_C(  71) },
          {  INT8_C(  25),  INT8_C(  41),  INT8_C(   8), -INT8_C(  12), -INT8_C(  53), -INT8_C( 105), -INT8_C(  38),  INT8_C(  61) } },
    },
    { { -INT8_C( 123),  INT8_C(  22),  INT8_C(   2),  INT8_C(  12), -INT8_C(  33),  INT8_C(   4), -INT8_C(  99),  INT8_C(  16),
         INT8_C(  65), -INT8_C(  94), -INT8_C(  49),  INT8_C( 122), -INT8_C(  40),  INT8_C( 107),  INT8_C( 110),  INT8_C(  90) },
        { { -INT8_C( 123),  INT8_C(   2), -INT8_C(  33), -INT8_C(  99),  INT8_C(  65), -INT8_C(  49), -INT8_C(  40),  INT8_C( 110) },
          {  INT8_C(  22),  INT8_C(  12),  INT8_C(   4),  INT8_C(  16), -INT8_C(  94),  INT8_C( 122),  INT8_C( 107),  INT8_C(  90) } },
    },
    { { -INT8_C( 124),  INT8_C(  26), -INT8_C( 125), -INT8_C(  44),  INT8_C(  34),  INT8_C( 126), -INT8_C(  56), -INT8_C( 107),
         INT8_C(  74), -INT8_C(  14),  INT8_C(  44), -INT8_C(  32), -INT8_C(  52), -INT8_C(  27),  INT8_C(  29),  INT8_C(  82) },
        { { -INT8_C( 124), -INT8_C( 125),  INT8_C(  34), -INT8_C(  56),  INT8_C(  74),  INT8_C(  44), -INT8_C(  52),  INT8_C(  29) },
          {  INT8_C(  26), -INT8_C(  44),  INT8_C( 126), -INT8_C( 107), -INT8_C(  14), -INT8_C(  32), -INT8_C(  27),  INT8_C(  82) } },
    },
    { { -INT8_C(   4),  INT8_C(  31),  INT8_C(  94), -INT8_C(  37),  INT8_C(  35), -INT8_C(   4), -INT8_C(  20),  INT8_C( 101),
        -INT8_C(  98), -INT8_C(  69), -INT8_C(  33),  INT8_C( 118),  INT8_C(  38),  INT8_C(  77), -INT8_C(  48), -INT8_C(  85) },
        { { -INT8_C(   4),  INT8_C(  94),  INT8_C(  35), -INT8_C(  20), -INT8_C(  98), -INT8_C(  33),  INT8_C(  38), -INT8_C(  48) },
          {  INT8_C(  31), -INT8_C(  37), -INT8_C(   4),  INT8_C( 101), -INT8_C(  69),  INT8_C( 118),  INT8_C(  77), -INT8_C(  85) } },
    },
    { {  INT8_C( 103),  INT8_C(  83),      INT8_MAX, -INT8_C( 119), -INT8_C(  46),  INT8_C(  72),  INT8_C(  31),  INT8_C(  28),
         INT8_C(  58),  INT8_C(  75), -INT8_C(   4),  INT8_C(   7),  INT8_C(  49),  INT8_C(  26),  INT8_C(  89),  INT8_C(  45) },
        { {  INT8_C( 103),      INT8_MAX, -INT8_C(  46),  INT8_C(  31),  INT8_C(  58), -INT8_C(   4),  INT8_C(  49),  INT8_C(  89) },
          {  INT8_C(  83), -INT8_C( 119),  INT8_C(  72),  INT8_C(  28),  INT8_C(  75),  INT8_C(   7),  INT8_C(  26),  INT8_C(  45) } },
    },
    { {  INT8_C(  57), -INT8_C(  73),  INT8_C(   8),  INT8_C(  93), -INT8_C(  77), -INT8_C(  12), -INT8_C(  62),  INT8_C(  81),
        -INT8_C(  80), -INT8_C(  95), -INT8_C(  57), -INT8_C(  42), -INT8_C(  18), -INT8_C( 105), -INT8_C( 127),  INT8_C(  86) },
        { {  INT8_C(  57),  INT8_C(   8), -INT8_C(  77), -INT8_C(  62), -INT8_C(  80), -INT8_C(  57), -INT8_C(  18), -INT8_C( 127) },
          { -INT8_C(  73),  INT8_C(  93), -INT8_C(  12),  INT8_C(  81), -INT8_C(  95), -INT8_C(  42), -INT8_C( 105),  INT8_C(  86) } }
    },


  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x2_t r = simde_vld2_s8(test_vec[i].a);

    simde_int8x8x2_t expected = {
        {simde_vld1_s8(test_vec[i].r[0]), simde_vld1_s8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int8_t buf[16];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_int8x8x2_t r = simde_vld2_s8(buf);

    simde_test_arm_neon_write_i8x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r[2][4];
  } test_vec[] = {
    { {  INT16_C( 26434), -INT16_C(  7742), -INT16_C( 24667),  INT16_C(  2612),
        -INT16_C( 16418), -INT16_C( 32141), -INT16_C( 30519),  INT16_C( 21039) },
        { {  INT16_C( 26434), -INT16_C( 24667), -INT16_C( 16418), -INT16_C( 30519) },
          { -INT16_C(  7742),  INT16_C(  2612), -INT16_C( 32141),  INT16_C( 21039) } },
    },
    { {  INT16_C( 12584),  INT16_C( 13680),  INT16_C(  9409),  INT16_C( 17421),
         INT16_C( 27590), -INT16_C( 17399), -INT16_C( 23807),  INT16_C( 17632) },
        { {  INT16_C( 12584),  INT16_C(  9409),  INT16_C( 27590), -INT16_C( 23807) },
          {  INT16_C( 13680),  INT16_C( 17421), -INT16_C( 17399),  INT16_C( 17632) } },
    },
    { { -INT16_C( 24054), -INT16_C( 20443),  INT16_C( 22849),  INT16_C(  8122),
         INT16_C( 11544), -INT16_C(  7519), -INT16_C( 11851), -INT16_C(  8652) },
        { { -INT16_C( 24054),  INT16_C( 22849),  INT16_C( 11544), -INT16_C( 11851) },
          { -INT16_C( 20443),  INT16_C(  8122), -INT16_C(  7519), -INT16_C(  8652) } },
    },
    { { -INT16_C( 23294), -INT16_C( 15597),  INT16_C(  8649), -INT16_C( 28921),
         INT16_C(  4236), -INT16_C( 29365),  INT16_C( 11188), -INT16_C( 16687) },
        { { -INT16_C( 23294),  INT16_C(  8649),  INT16_C(  4236),  INT16_C( 11188) },
          { -INT16_C( 15597), -INT16_C( 28921), -INT16_C( 29365), -INT16_C( 16687) } }
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x2_t r = simde_vld2_s16(test_vec[i].a);

    simde_int16x4x2_t expected = {
        {simde_vld1_s16(test_vec[i].r[0]), simde_vld1_s16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x4(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int16_t buf[8];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_int16x4x2_t r = simde_vld2_s16(buf);

    simde_test_arm_neon_write_i16x4x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r[2][2];
  } test_vec[] = {
    { {  INT32_C(   886724837),  INT32_C(   903508407),
        -INT32_C(   977712366),  INT32_C(  1183767792) },
        { {  INT32_C(   886724837), -INT32_C(   977712366) },
          {  INT32_C(   903508407),  INT32_C(  1183767792) } },
    },
    { {  INT32_C(  1474850969),  INT32_C(   975881925),
         INT32_C(  1191817794), -INT32_C(  1270968626) },
        { {  INT32_C(  1474850969),  INT32_C(  1191817794) },
          {  INT32_C(   975881925), -INT32_C(  1270968626) } },
    },
    { { -INT32_C(  1628956186), -INT32_C(  1663843702),
        -INT32_C(    43938803),  INT32_C(    21229672) },
        { { -INT32_C(  1628956186), -INT32_C(    43938803) },
          { -INT32_C(  1663843702),  INT32_C(    21229672) } },
    },
    { {  INT32_C(   643312736),  INT32_C(   878740466),
         INT32_C(    58419765), -INT32_C(   558384392) },
        { {  INT32_C(   643312736),  INT32_C(    58419765) },
          {  INT32_C(   878740466), -INT32_C(   558384392) } },
    },
    { {  INT32_C(  1568448467),  INT32_C(  1861832801),
         INT32_C(  1164729308), -INT32_C(  1421430965) },
        { {  INT32_C(  1568448467),  INT32_C(  1164729308) },
          {  INT32_C(  1861832801), -INT32_C(  1421430965) } },
    },
    { { -INT32_C(   841900069),  INT32_C(  1459761698),
        -INT32_C(  1806008932),  INT32_C(   175247927) },
        { { -INT32_C(   841900069), -INT32_C(  1806008932) },
          {  INT32_C(  1459761698),  INT32_C(   175247927) } },
    },
    { {  INT32_C(   325578673),  INT32_C(   461463871),
         INT32_C(   123792828),  INT32_C(  2024974237) },
        { {  INT32_C(   325578673),  INT32_C(   123792828) },
          {  INT32_C(   461463871),  INT32_C(  2024974237) } },
    },
    { {  INT32_C(  1749451846),  INT32_C(  1388267702),
        -INT32_C(    35251771), -INT32_C(   586721237) },
        { {  INT32_C(  1749451846), -INT32_C(    35251771) },
          {  INT32_C(  1388267702), -INT32_C(   586721237) } }}
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x2_t r = simde_vld2_s32(test_vec[i].a);

    simde_int32x2x2_t expected = {
        {simde_vld1_s32(test_vec[i].r[0]), simde_vld1_s32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x2(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int32_t buf[4];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_int32x2x2_t r = simde_vld2_s32(buf);

    simde_test_arm_neon_write_i32x2x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t r[2][1];
  } test_vec[] = {
    { {  INT64_C( 2491657136620446655),
        -INT64_C( 8008712209217472471) },
        { {  INT64_C( 2491657136620446655) },
          { -INT64_C( 8008712209217472471) } }
    },
    { {  INT64_C( 5905840427281538397),
        -INT64_C(  256047405469913514) },
        { {  INT64_C( 5905840427281538397) },
          { -INT64_C(  256047405469913514) } },
    },
    { {  INT64_C( 1410598559050352250),
        -INT64_C( 8581208681535646293) },
        { {  INT64_C( 1410598559050352250) },
          { -INT64_C( 8581208681535646293) } },
    },
    { {  INT64_C( 4768888611226069577),
         INT64_C( 5613591610635419053) },
        { {  INT64_C( 4768888611226069577) },
          {  INT64_C( 5613591610635419053) } },
    },
    { { -INT64_C( 1999508928546814398),
        -INT64_C( 8729622882906418906) },
        { { -INT64_C( 1999508928546814398) },
          { -INT64_C( 8729622882906418906) } },
    },
    { { -INT64_C( 8178376526721227951),
         INT64_C( 5129424078989003022) },
        { { -INT64_C( 8178376526721227951) },
          {  INT64_C( 5129424078989003022) } },
    },
    { {  INT64_C( 7224815307703184678),
        -INT64_C(  556316978773065340) },
        { {  INT64_C( 7224815307703184678) },
          { -INT64_C(  556316978773065340) } },
    },
    { {  INT64_C( 5360328353875667699),
         INT64_C( 7100870651391302719) },
        { {  INT64_C( 5360328353875667699) },
          {  INT64_C( 7100870651391302719) } }}
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x2_t r = simde_vld2_s64(test_vec[i].a);

    simde_int64x1x2_t expected = {
        {simde_vld1_s64(test_vec[i].r[0]), simde_vld1_s64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x1(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1x2_t c = {{a, b}};

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int64_t buf[4];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_int64x1x2_t r = simde_vld2_s64(buf);

    simde_test_arm_neon_write_i64x1x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t r[2][8];
  } test_vec[] = {

    { { UINT8_C(144), UINT8_C(234), UINT8_C(130), UINT8_C(145), UINT8_C( 26), UINT8_C(241), UINT8_C( 35), UINT8_C( 43),
        UINT8_C( 76), UINT8_C(223), UINT8_C(152), UINT8_C(128), UINT8_C(203), UINT8_C( 66), UINT8_C( 17), UINT8_C(218) },
        { { UINT8_C(144), UINT8_C(130), UINT8_C( 26), UINT8_C( 35), UINT8_C( 76), UINT8_C(152), UINT8_C(203), UINT8_C( 17) },
          { UINT8_C(234), UINT8_C(145), UINT8_C(241), UINT8_C( 43), UINT8_C(223), UINT8_C(128), UINT8_C( 66), UINT8_C(218) } },
    },
    { { UINT8_C(196), UINT8_C( 14), UINT8_C( 36), UINT8_C( 59), UINT8_C(230), UINT8_C(253), UINT8_C(216), UINT8_C( 14),
        UINT8_C( 31), UINT8_C( 73), UINT8_C( 48), UINT8_C( 55), UINT8_C(200), UINT8_C( 71), UINT8_C(176), UINT8_C( 88) },
        { { UINT8_C(196), UINT8_C( 36), UINT8_C(230), UINT8_C(216), UINT8_C( 31), UINT8_C( 48), UINT8_C(200), UINT8_C(176) },
          { UINT8_C( 14), UINT8_C( 59), UINT8_C(253), UINT8_C( 14), UINT8_C( 73), UINT8_C( 55), UINT8_C( 71), UINT8_C( 88) } },
    },
    { { UINT8_C( 49), UINT8_C( 50), UINT8_C(233), UINT8_C( 76), UINT8_C( 35), UINT8_C( 13), UINT8_C(119), UINT8_C(111),
        UINT8_C(236), UINT8_C( 15), UINT8_C(240), UINT8_C(184), UINT8_C( 81), UINT8_C(  1), UINT8_C(146), UINT8_C( 22) },
        { { UINT8_C( 49), UINT8_C(233), UINT8_C( 35), UINT8_C(119), UINT8_C(236), UINT8_C(240), UINT8_C( 81), UINT8_C(146) },
          { UINT8_C( 50), UINT8_C( 76), UINT8_C( 13), UINT8_C(111), UINT8_C( 15), UINT8_C(184), UINT8_C(  1), UINT8_C( 22) } },
    },
    { { UINT8_C( 15), UINT8_C(182), UINT8_C( 81), UINT8_C(245), UINT8_C(179), UINT8_C( 41), UINT8_C(  4), UINT8_C(211),
        UINT8_C(115), UINT8_C( 52), UINT8_C( 10), UINT8_C( 59), UINT8_C(123), UINT8_C(187), UINT8_C(147), UINT8_C(173) },
        { { UINT8_C( 15), UINT8_C( 81), UINT8_C(179), UINT8_C(  4), UINT8_C(115), UINT8_C( 10), UINT8_C(123), UINT8_C(147) },
          { UINT8_C(182), UINT8_C(245), UINT8_C( 41), UINT8_C(211), UINT8_C( 52), UINT8_C( 59), UINT8_C(187), UINT8_C(173) } },
    },
    { { UINT8_C(237), UINT8_C(125), UINT8_C(249), UINT8_C( 17), UINT8_C(138), UINT8_C(112), UINT8_C(128), UINT8_C(118),
        UINT8_C(127), UINT8_C(112), UINT8_C( 46), UINT8_C(208), UINT8_C(113), UINT8_C(193), UINT8_C(230), UINT8_C(129) },
        { { UINT8_C(237), UINT8_C(249), UINT8_C(138), UINT8_C(128), UINT8_C(127), UINT8_C( 46), UINT8_C(113), UINT8_C(230) },
          { UINT8_C(125), UINT8_C( 17), UINT8_C(112), UINT8_C(118), UINT8_C(112), UINT8_C(208), UINT8_C(193), UINT8_C(129) } },
    },
    { { UINT8_C(119), UINT8_C( 56), UINT8_C(118), UINT8_C( 43), UINT8_C( 97), UINT8_C(122), UINT8_C(254), UINT8_C(212),
        UINT8_C(175), UINT8_C(  8), UINT8_C( 15), UINT8_C( 42), UINT8_C(195), UINT8_C(163), UINT8_C(215), UINT8_C(177) },
        { { UINT8_C(119), UINT8_C(118), UINT8_C( 97), UINT8_C(254), UINT8_C(175), UINT8_C( 15), UINT8_C(195), UINT8_C(215) },
          { UINT8_C( 56), UINT8_C( 43), UINT8_C(122), UINT8_C(212), UINT8_C(  8), UINT8_C( 42), UINT8_C(163), UINT8_C(177) } },
    },
    { { UINT8_C( 32), UINT8_C(208), UINT8_C(194), UINT8_C(170), UINT8_C( 64), UINT8_C( 66), UINT8_C( 32), UINT8_C(191),
        UINT8_C(179), UINT8_C( 79), UINT8_C(144), UINT8_C( 36), UINT8_C( 16), UINT8_C(118), UINT8_C(165), UINT8_C(135) },
        { { UINT8_C( 32), UINT8_C(194), UINT8_C( 64), UINT8_C( 32), UINT8_C(179), UINT8_C(144), UINT8_C( 16), UINT8_C(165) },
          { UINT8_C(208), UINT8_C(170), UINT8_C( 66), UINT8_C(191), UINT8_C( 79), UINT8_C( 36), UINT8_C(118), UINT8_C(135) } },
    },
    { { UINT8_C(174), UINT8_C( 28), UINT8_C(178), UINT8_C( 16), UINT8_C(150), UINT8_C(176), UINT8_C(228), UINT8_C( 69),
        UINT8_C(185), UINT8_C(244), UINT8_C(112), UINT8_C(124), UINT8_C(151), UINT8_C( 71), UINT8_C( 45), UINT8_C(183) },
        { { UINT8_C(174), UINT8_C(178), UINT8_C(150), UINT8_C(228), UINT8_C(185), UINT8_C(112), UINT8_C(151), UINT8_C( 45) },
          { UINT8_C( 28), UINT8_C( 16), UINT8_C(176), UINT8_C( 69), UINT8_C(244), UINT8_C(124), UINT8_C( 71), UINT8_C(183) } },
    },


  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x2_t r = simde_vld2_u8(test_vec[i].a);

    simde_uint8x8x2_t expected = {
        {simde_vld1_u8(test_vec[i].r[0]), simde_vld1_u8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u8x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint8_t buf[16];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint8x8x2_t r = simde_vld2_u8(buf);

    simde_test_arm_neon_write_u8x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t r[2][4];
  } test_vec[] = {
    { { UINT16_C(42664), UINT16_C(53887), UINT16_C(10958), UINT16_C(61123),
        UINT16_C( 7800), UINT16_C(15834), UINT16_C(36089), UINT16_C(22799) },
        { { UINT16_C(42664), UINT16_C(10958), UINT16_C( 7800), UINT16_C(36089) },
          { UINT16_C(53887), UINT16_C(61123), UINT16_C(15834), UINT16_C(22799) } },
    },
    { { UINT16_C(62795), UINT16_C(22857), UINT16_C(11632), UINT16_C(39934),
        UINT16_C(56742), UINT16_C(64150), UINT16_C( 8095), UINT16_C(18414) },
        { { UINT16_C(62795), UINT16_C(11632), UINT16_C(56742), UINT16_C( 8095) },
          { UINT16_C(22857), UINT16_C(39934), UINT16_C(64150), UINT16_C(18414) } },
    },
    { { UINT16_C(28101), UINT16_C(37914), UINT16_C(56727), UINT16_C( 3970),
        UINT16_C(23803), UINT16_C(62797), UINT16_C(23784), UINT16_C(13390) },
        { { UINT16_C(28101), UINT16_C(56727), UINT16_C(23803), UINT16_C(23784) },
          { UINT16_C(37914), UINT16_C( 3970), UINT16_C(62797), UINT16_C(13390) } },
    },
    { { UINT16_C(38737), UINT16_C(49549), UINT16_C(36037), UINT16_C(27485),
        UINT16_C(62313), UINT16_C( 2149), UINT16_C(21522), UINT16_C(55375) },
        { { UINT16_C(38737), UINT16_C(36037), UINT16_C(62313), UINT16_C(21522) },
          { UINT16_C(49549), UINT16_C(27485), UINT16_C( 2149), UINT16_C(55375) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x2_t r = simde_vld2_u16(test_vec[i].a);

    simde_uint16x4x2_t expected = {
        {simde_vld1_u16(test_vec[i].r[0]), simde_vld1_u16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u16x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x4(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 4 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint16_t buf[8];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint16x4x2_t r = simde_vld2_u16(buf);

    simde_test_arm_neon_write_u16x4x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t r[2][2];
  } test_vec[] = {
    { { UINT32_C(1500277185), UINT32_C(1114172999),
        UINT32_C( 859288906), UINT32_C(1650951697) },
        { { UINT32_C(1500277185), UINT32_C( 859288906) },
          { UINT32_C(1114172999), UINT32_C(1650951697) } },
    },
    { { UINT32_C(3794072605), UINT32_C(3914236288),
        UINT32_C(2280764276), UINT32_C(3378462983) },
        { { UINT32_C(3794072605), UINT32_C(2280764276) },
          { UINT32_C(3914236288), UINT32_C(3378462983) } },
    },
    { { UINT32_C(4045589418), UINT32_C(  53775033),
        UINT32_C(1362520896), UINT32_C( 263495153) },
        { { UINT32_C(4045589418), UINT32_C(1362520896) },
          { UINT32_C(  53775033), UINT32_C( 263495153) } },
    },
    { { UINT32_C( 317839506), UINT32_C(3455860569),
        UINT32_C(4199869939), UINT32_C(3653481262) },
        { { UINT32_C( 317839506), UINT32_C(4199869939) },
          { UINT32_C(3455860569), UINT32_C(3653481262) } },
    },
    { { UINT32_C( 936043902), UINT32_C(2956721776),
        UINT32_C(1526821226), UINT32_C(2708124943) },
        { { UINT32_C( 936043902), UINT32_C(1526821226) },
          { UINT32_C(2956721776), UINT32_C(2708124943) } },
    },
    { { UINT32_C(3870514317), UINT32_C(2394206107),
        UINT32_C(3414755485), UINT32_C( 983846076) },
        { { UINT32_C(3870514317), UINT32_C(3414755485) },
          { UINT32_C(2394206107), UINT32_C( 983846076) } },
    },
    { { UINT32_C(2725408562), UINT32_C(3612519789),
        UINT32_C( 758338334), UINT32_C(2530123017) },
        { { UINT32_C(2725408562), UINT32_C( 758338334) },
          { UINT32_C(3612519789), UINT32_C(2530123017) } },
    },
    { { UINT32_C(2508030713), UINT32_C(3458412849),
        UINT32_C(4120554553), UINT32_C( 724582137) },
        { { UINT32_C(2508030713), UINT32_C(4120554553) },
          { UINT32_C(3458412849), UINT32_C( 724582137) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x2_t r = simde_vld2_u32(test_vec[i].a);

    simde_uint32x2x2_t expected = {
        {simde_vld1_u32(test_vec[i].r[0]), simde_vld1_u32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u32x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x2(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint32_t buf[4];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint32x2x2_t r = simde_vld2_u32(buf);

    simde_test_arm_neon_write_u32x2x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t r[2][1];
  } test_vec[] = {
    { { UINT64_C( 9544671133075875798),
        UINT64_C(10026771010818587806) },
        { { UINT64_C( 9544671133075875798) },
          { UINT64_C(10026771010818587806) } },
    },
    { { UINT64_C(11716502022888129015),
        UINT64_C( 9207447440231071203) },
        { { UINT64_C(11716502022888129015) },
          { UINT64_C( 9207447440231071203) } },
    },
    { { UINT64_C(14585844370014973971),
        UINT64_C(12085455436694909200) },
        { { UINT64_C(14585844370014973971) },
          { UINT64_C(12085455436694909200) } },
    },
    { { UINT64_C( 6976248983748549802),
        UINT64_C( 6648178682459053338) },
        { { UINT64_C( 6976248983748549802) },
          { UINT64_C( 6648178682459053338) } },
    },
    { { UINT64_C( 9780321370926949059),
        UINT64_C(10409627327296486687) },
        { { UINT64_C( 9780321370926949059) },
          { UINT64_C(10409627327296486687) } },
    },
    { { UINT64_C( 3559687685519800969),
        UINT64_C( 9804398810564506218) },
        { { UINT64_C( 3559687685519800969) },
          { UINT64_C( 9804398810564506218) } },
    },
    { { UINT64_C( 2403006863864517466),
        UINT64_C(  244715532034575855) },
        { { UINT64_C( 2403006863864517466) },
          { UINT64_C(  244715532034575855) } },
    },
    { { UINT64_C( 1885442199874249441),
        UINT64_C(12785682336243916577) },
        { { UINT64_C( 1885442199874249441) },
          { UINT64_C(12785682336243916577) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x2_t r = simde_vld2_u64(test_vec[i].a);

    simde_uint64x1x2_t expected = {
        {simde_vld1_u64(test_vec[i].r[0]), simde_vld1_u64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u64x1(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x1(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1x2_t c = {{a, b}};

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint64_t buf[4];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint64x1x2_t r = simde_vld2_u64(buf);

    simde_test_arm_neon_write_u64x1x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t r[2][2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -22.58), SIMDE_FLOAT32_C(   -87.59),
        SIMDE_FLOAT32_C(     1.12), SIMDE_FLOAT32_C(   -68.18) },
        { { SIMDE_FLOAT32_C(   -22.58), SIMDE_FLOAT32_C(     1.12) },
          { SIMDE_FLOAT32_C(   -87.59), SIMDE_FLOAT32_C(   -68.18) } },
    },
    { { SIMDE_FLOAT32_C(   -19.64), SIMDE_FLOAT32_C(   -79.11),
        SIMDE_FLOAT32_C(   -13.56), SIMDE_FLOAT32_C(    59.24) },
        { { SIMDE_FLOAT32_C(   -19.64), SIMDE_FLOAT32_C(   -13.56) },
          { SIMDE_FLOAT32_C(   -79.11), SIMDE_FLOAT32_C(    59.24) } },
    },
    { { SIMDE_FLOAT32_C(    84.01), SIMDE_FLOAT32_C(   -49.79),
        SIMDE_FLOAT32_C(    69.20), SIMDE_FLOAT32_C(    82.05) },
        { { SIMDE_FLOAT32_C(    84.01), SIMDE_FLOAT32_C(    69.20) },
          { SIMDE_FLOAT32_C(   -49.79), SIMDE_FLOAT32_C(    82.05) } },
    },
    { { SIMDE_FLOAT32_C(   -12.11), SIMDE_FLOAT32_C(    93.29),
        SIMDE_FLOAT32_C(    70.29), SIMDE_FLOAT32_C(    70.67) },
        { { SIMDE_FLOAT32_C(   -12.11), SIMDE_FLOAT32_C(    70.29) },
          { SIMDE_FLOAT32_C(    93.29), SIMDE_FLOAT32_C(    70.67) } },
    },
    { { SIMDE_FLOAT32_C(    14.62), SIMDE_FLOAT32_C(    51.53),
        SIMDE_FLOAT32_C(    11.77), SIMDE_FLOAT32_C(    81.69) },
        { { SIMDE_FLOAT32_C(    14.62), SIMDE_FLOAT32_C(    11.77) },
          { SIMDE_FLOAT32_C(    51.53), SIMDE_FLOAT32_C(    81.69) } },
    },
    { { SIMDE_FLOAT32_C(   -19.28), SIMDE_FLOAT32_C(    59.50),
        SIMDE_FLOAT32_C(   -77.17), SIMDE_FLOAT32_C(   -41.73) },
        { { SIMDE_FLOAT32_C(   -19.28), SIMDE_FLOAT32_C(   -77.17) },
          { SIMDE_FLOAT32_C(    59.50), SIMDE_FLOAT32_C(   -41.73) } },
    },
    { { SIMDE_FLOAT32_C(   -85.96), SIMDE_FLOAT32_C(    68.07),
        SIMDE_FLOAT32_C(   -11.65), SIMDE_FLOAT32_C(    31.99) },
        { { SIMDE_FLOAT32_C(   -85.96), SIMDE_FLOAT32_C(   -11.65) },
          { SIMDE_FLOAT32_C(    68.07), SIMDE_FLOAT32_C(    31.99) } },
    },
    { { SIMDE_FLOAT32_C(   -11.72), SIMDE_FLOAT32_C(   -86.96),
        SIMDE_FLOAT32_C(    52.84), SIMDE_FLOAT32_C(    65.70) },
        { { SIMDE_FLOAT32_C(   -11.72), SIMDE_FLOAT32_C(    52.84) },
          { SIMDE_FLOAT32_C(   -86.96), SIMDE_FLOAT32_C(    65.70) } }
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x2_t r = simde_vld2_f32(test_vec[i].a);

    simde_float32x2x2_t expected = {
        {simde_vld1_f32(test_vec[i].r[0]), simde_vld1_f32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f32x2(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_f32x2(r.val[1], expected.val[1], 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-100.0f, 100.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-100.0f, 100.0f);
    simde_float32x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    simde_float32_t buf[4];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_float32x2x2_t r = simde_vld2_f32(buf);

    simde_test_arm_neon_write_f32x2x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t r[2][1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -60.52),
        SIMDE_FLOAT64_C(   -27.97) },
        { { SIMDE_FLOAT64_C(   -60.52) },
          { SIMDE_FLOAT64_C(   -27.97) } },
    },
    { { SIMDE_FLOAT64_C(    41.23),
        SIMDE_FLOAT64_C(   -82.15) },
        { { SIMDE_FLOAT64_C(    41.23) },
          { SIMDE_FLOAT64_C(   -82.15) } },
    },
    { { SIMDE_FLOAT64_C(   -45.22),
        SIMDE_FLOAT64_C(   -82.20) },
        { { SIMDE_FLOAT64_C(   -45.22) },
          { SIMDE_FLOAT64_C(   -82.20) } },
    },
    { { SIMDE_FLOAT64_C(    20.47),
        SIMDE_FLOAT64_C(   -91.57) },
        { { SIMDE_FLOAT64_C(    20.47) },
          { SIMDE_FLOAT64_C(   -91.57) } },
    },
    { { SIMDE_FLOAT64_C(    87.79),
        SIMDE_FLOAT64_C(    27.03) },
        { { SIMDE_FLOAT64_C(    87.79) },
          { SIMDE_FLOAT64_C(    27.03) } },
    },
    { { SIMDE_FLOAT64_C(   -13.17),
        SIMDE_FLOAT64_C(    89.71) },
        { { SIMDE_FLOAT64_C(   -13.17) },
          { SIMDE_FLOAT64_C(    89.71) } },
    },
    { { SIMDE_FLOAT64_C(   -91.04),
        SIMDE_FLOAT64_C(    54.16) },
        { { SIMDE_FLOAT64_C(   -91.04) },
          { SIMDE_FLOAT64_C(    54.16) } },
    },
    { { SIMDE_FLOAT64_C(    49.63),
        SIMDE_FLOAT64_C(    71.75) },
        { { SIMDE_FLOAT64_C(    49.63) },
          { SIMDE_FLOAT64_C(    71.75) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x2_t r = simde_vld2_f64(test_vec[i].a);

    simde_float64x1x2_t expected = {
        {simde_vld1_f64(test_vec[i].r[0]), simde_vld1_f64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f64x1(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_f64x1(r.val[1], expected.val[1], 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-100.0, 100.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-100.0, 100.0);
    simde_float64x1x2_t c = {{a, b}};

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    simde_float64_t buf[4];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_float64x1x2_t r = simde_vld2_f64(buf);

    simde_test_arm_neon_write_f64x1x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[32];
    int8_t r[2][16];
  } test_vec[] = {
    { { -INT8_C(  25),  INT8_C(  77),  INT8_C(  76),  INT8_C(  77),  INT8_C(  68),  INT8_C(  84),  INT8_C(  81),  INT8_C(  59),
         INT8_C(  69),  INT8_C(   8), -INT8_C( 108), -INT8_C(  45), -INT8_C(  85),  INT8_C(  73), -INT8_C( 110),  INT8_C(  69),
        -INT8_C(  13),  INT8_C(  23), -INT8_C(  80), -INT8_C(  93), -INT8_C( 102),  INT8_C(  80), -INT8_C(  63),  INT8_C(  67),
         INT8_C(  11), -INT8_C(  75),  INT8_C(   9),  INT8_C(  98),  INT8_C(  19),  INT8_C(  38),  INT8_C(  41), -INT8_C(   6) },
        { { -INT8_C(  25),  INT8_C(  76),  INT8_C(  68),  INT8_C(  81),  INT8_C(  69), -INT8_C( 108), -INT8_C(  85), -INT8_C( 110),
            -INT8_C(  13), -INT8_C(  80), -INT8_C( 102), -INT8_C(  63),  INT8_C(  11),  INT8_C(   9),  INT8_C(  19),  INT8_C(  41) },
          {  INT8_C(  77),  INT8_C(  77),  INT8_C(  84),  INT8_C(  59),  INT8_C(   8), -INT8_C(  45),  INT8_C(  73),  INT8_C(  69),
             INT8_C(  23), -INT8_C(  93),  INT8_C(  80),  INT8_C(  67), -INT8_C(  75),  INT8_C(  98),  INT8_C(  38), -INT8_C(   6) } },
    },
    { {  INT8_C( 116),  INT8_C( 117),  INT8_C(  71), -INT8_C(  72), -INT8_C(  55), -INT8_C( 104), -INT8_C(  13),  INT8_C(  15),
        -INT8_C(  96), -INT8_C( 121), -INT8_C(  30),  INT8_C(  76), -INT8_C(  48),  INT8_C( 116), -INT8_C( 111), -INT8_C(  60),
        -INT8_C( 117),  INT8_C(  65),  INT8_C( 103),  INT8_C(  38), -INT8_C( 111),  INT8_C(  40),  INT8_C( 105), -INT8_C( 100),
        -INT8_C(  35),  INT8_C( 115), -INT8_C(   2), -INT8_C(  15), -INT8_C( 103),  INT8_C(  39), -INT8_C(  21),  INT8_C(  13) },
        { {  INT8_C( 116),  INT8_C(  71), -INT8_C(  55), -INT8_C(  13), -INT8_C(  96), -INT8_C(  30), -INT8_C(  48), -INT8_C( 111),
            -INT8_C( 117),  INT8_C( 103), -INT8_C( 111),  INT8_C( 105), -INT8_C(  35), -INT8_C(   2), -INT8_C( 103), -INT8_C(  21) },
          {  INT8_C( 117), -INT8_C(  72), -INT8_C( 104),  INT8_C(  15), -INT8_C( 121),  INT8_C(  76),  INT8_C( 116), -INT8_C(  60),
             INT8_C(  65),  INT8_C(  38),  INT8_C(  40), -INT8_C( 100),  INT8_C( 115), -INT8_C(  15),  INT8_C(  39),  INT8_C(  13) } },
    },
    { { -INT8_C( 100),  INT8_C(  51), -INT8_C(  59),  INT8_C( 102), -INT8_C(  53), -INT8_C(  71),  INT8_C( 117),  INT8_C( 108),
         INT8_C(  64),  INT8_C(  87), -INT8_C(  72),  INT8_C(  17), -INT8_C(  52),  INT8_C(  73), -INT8_C(  43),  INT8_C(  87),
        -INT8_C( 117),  INT8_C(  60),  INT8_C( 125),  INT8_C(  28),  INT8_C( 101), -INT8_C(  25), -INT8_C(  71),  INT8_C(  66),
         INT8_C(  90), -INT8_C(  73),  INT8_C(  51), -INT8_C(  13), -INT8_C(  33),  INT8_C(  31),  INT8_C(   1),  INT8_C( 123) },
        { { -INT8_C( 100), -INT8_C(  59), -INT8_C(  53),  INT8_C( 117),  INT8_C(  64), -INT8_C(  72), -INT8_C(  52), -INT8_C(  43),
            -INT8_C( 117),  INT8_C( 125),  INT8_C( 101), -INT8_C(  71),  INT8_C(  90),  INT8_C(  51), -INT8_C(  33),  INT8_C(   1) },
          {  INT8_C(  51),  INT8_C( 102), -INT8_C(  71),  INT8_C( 108),  INT8_C(  87),  INT8_C(  17),  INT8_C(  73),  INT8_C(  87),
             INT8_C(  60),  INT8_C(  28), -INT8_C(  25),  INT8_C(  66), -INT8_C(  73), -INT8_C(  13),  INT8_C(  31),  INT8_C( 123) } },
    },
    { {  INT8_C(  82), -INT8_C(  58), -INT8_C(  31),  INT8_C(  29),      INT8_MAX,  INT8_C(  86), -INT8_C( 119), -INT8_C(  64),
        -INT8_C(  82),  INT8_C(  65), -INT8_C(  47),  INT8_C( 122), -INT8_C( 117), -INT8_C(  90), -INT8_C(  47),  INT8_C(  22),
        -INT8_C(  30),  INT8_C(  79),  INT8_C(  50),  INT8_C(  71),  INT8_C(  54), -INT8_C(  21), -INT8_C( 118), -INT8_C( 112),
        -INT8_C(  93), -INT8_C(  67), -INT8_C( 125), -INT8_C( 126), -INT8_C(  36), -INT8_C( 124), -INT8_C(   3),  INT8_C(  46) },
        { {  INT8_C(  82), -INT8_C(  31),      INT8_MAX, -INT8_C( 119), -INT8_C(  82), -INT8_C(  47), -INT8_C( 117), -INT8_C(  47),
            -INT8_C(  30),  INT8_C(  50),  INT8_C(  54), -INT8_C( 118), -INT8_C(  93), -INT8_C( 125), -INT8_C(  36), -INT8_C(   3) },
          { -INT8_C(  58),  INT8_C(  29),  INT8_C(  86), -INT8_C(  64),  INT8_C(  65),  INT8_C( 122), -INT8_C(  90),  INT8_C(  22),
             INT8_C(  79),  INT8_C(  71), -INT8_C(  21), -INT8_C( 112), -INT8_C(  67), -INT8_C( 126), -INT8_C( 124),  INT8_C(  46) } },
    },
    { {  INT8_C(  75), -INT8_C(  33),  INT8_C(  76), -INT8_C(  54),  INT8_C(  53), -INT8_C(  43), -INT8_C( 118), -INT8_C(  29),
         INT8_C(  23),  INT8_C(  91),  INT8_C(  93), -INT8_C(  94),  INT8_C(   1),  INT8_C(  47), -INT8_C(  72), -INT8_C(  28),
         INT8_C( 126), -INT8_C(  22),  INT8_C(  43), -INT8_C(  76), -INT8_C(  42), -INT8_C(  75),  INT8_C(  68),  INT8_C( 121),
         INT8_C( 115), -INT8_C(  57), -INT8_C(   5),  INT8_C(  79),  INT8_C(  76), -INT8_C(   8),  INT8_C( 126), -INT8_C( 105) },
        { {  INT8_C(  75),  INT8_C(  76),  INT8_C(  53), -INT8_C( 118),  INT8_C(  23),  INT8_C(  93),  INT8_C(   1), -INT8_C(  72),
             INT8_C( 126),  INT8_C(  43), -INT8_C(  42),  INT8_C(  68),  INT8_C( 115), -INT8_C(   5),  INT8_C(  76),  INT8_C( 126) },
          { -INT8_C(  33), -INT8_C(  54), -INT8_C(  43), -INT8_C(  29),  INT8_C(  91), -INT8_C(  94),  INT8_C(  47), -INT8_C(  28),
            -INT8_C(  22), -INT8_C(  76), -INT8_C(  75),  INT8_C( 121), -INT8_C(  57),  INT8_C(  79), -INT8_C(   8), -INT8_C( 105) } },
    },
    { { -INT8_C(  41), -INT8_C(  54),  INT8_C(  97),  INT8_C(  13), -INT8_C(  97), -INT8_C(  20), -INT8_C(  16), -INT8_C(  74),
         INT8_C(  71),  INT8_C(  78),  INT8_C(  88),  INT8_C(  73),  INT8_C( 125),  INT8_C(  16),  INT8_C(  45), -INT8_C(   5),
        -INT8_C(   5),  INT8_C(  88), -INT8_C(  81), -INT8_C(  47),  INT8_C(  14), -INT8_C(  13),  INT8_C(  74), -INT8_C( 127),
        -INT8_C(  70),  INT8_C(  69), -INT8_C(  48),  INT8_C(   6),  INT8_C(  61),  INT8_C(  78), -INT8_C(  99),  INT8_C(  21) },
        { { -INT8_C(  41),  INT8_C(  97), -INT8_C(  97), -INT8_C(  16),  INT8_C(  71),  INT8_C(  88),  INT8_C( 125),  INT8_C(  45),
            -INT8_C(   5), -INT8_C(  81),  INT8_C(  14),  INT8_C(  74), -INT8_C(  70), -INT8_C(  48),  INT8_C(  61), -INT8_C(  99) },
          { -INT8_C(  54),  INT8_C(  13), -INT8_C(  20), -INT8_C(  74),  INT8_C(  78),  INT8_C(  73),  INT8_C(  16), -INT8_C(   5),
             INT8_C(  88), -INT8_C(  47), -INT8_C(  13), -INT8_C( 127),  INT8_C(  69),  INT8_C(   6),  INT8_C(  78),  INT8_C(  21) } },
    },
    { {  INT8_C(  24), -INT8_C(   1),  INT8_C(  34), -INT8_C(  72), -INT8_C(  21),  INT8_C(  18),  INT8_C( 110),  INT8_C(  50),
         INT8_C(  96), -INT8_C(  57),  INT8_C( 123), -INT8_C(  35), -INT8_C(  41), -INT8_C(  88), -INT8_C(  40), -INT8_C(  46),
         INT8_C(   1), -INT8_C( 121), -INT8_C(  93),  INT8_C(  15),  INT8_C( 122), -INT8_C(  19), -INT8_C( 112),  INT8_C(  53),
         INT8_C(  50),  INT8_C(  96),  INT8_C(  59),  INT8_C( 112), -INT8_C(  81), -INT8_C(  39), -INT8_C( 123), -INT8_C(  57) },
        { {  INT8_C(  24),  INT8_C(  34), -INT8_C(  21),  INT8_C( 110),  INT8_C(  96),  INT8_C( 123), -INT8_C(  41), -INT8_C(  40),
             INT8_C(   1), -INT8_C(  93),  INT8_C( 122), -INT8_C( 112),  INT8_C(  50),  INT8_C(  59), -INT8_C(  81), -INT8_C( 123) },
          { -INT8_C(   1), -INT8_C(  72),  INT8_C(  18),  INT8_C(  50), -INT8_C(  57), -INT8_C(  35), -INT8_C(  88), -INT8_C(  46),
            -INT8_C( 121),  INT8_C(  15), -INT8_C(  19),  INT8_C(  53),  INT8_C(  96),  INT8_C( 112), -INT8_C(  39), -INT8_C(  57) } },
    },
    { { -INT8_C(  40), -INT8_C(  89),      INT8_MAX, -INT8_C(  61), -INT8_C(  71), -INT8_C(  18), -INT8_C(  11),  INT8_C(  26),
        -INT8_C(  75),  INT8_C( 113), -INT8_C(   9), -INT8_C( 116),  INT8_C(  25), -INT8_C(  48),  INT8_C(  95),  INT8_C(  26),
         INT8_C(  87),  INT8_C(   2),  INT8_C(  41), -INT8_C(  46), -INT8_C(  16), -INT8_C(  71),  INT8_C(   7),  INT8_C(  34),
         INT8_C(  26),  INT8_C(  66), -INT8_C( 110), -INT8_C(  55),  INT8_C(  27),  INT8_C(  23), -INT8_C( 112), -INT8_C(  13) },
        { { -INT8_C(  40),      INT8_MAX, -INT8_C(  71), -INT8_C(  11), -INT8_C(  75), -INT8_C(   9),  INT8_C(  25),  INT8_C(  95),
             INT8_C(  87),  INT8_C(  41), -INT8_C(  16),  INT8_C(   7),  INT8_C(  26), -INT8_C( 110),  INT8_C(  27), -INT8_C( 112) },
          { -INT8_C(  89), -INT8_C(  61), -INT8_C(  18),  INT8_C(  26),  INT8_C( 113), -INT8_C( 116), -INT8_C(  48),  INT8_C(  26),
             INT8_C(   2), -INT8_C(  46), -INT8_C(  71),  INT8_C(  34),  INT8_C(  66), -INT8_C(  55),  INT8_C(  23), -INT8_C(  13) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x2_t r = simde_vld2q_s8(test_vec[i].a);

    simde_int8x16x2_t expected = {
        {simde_vld1q_s8(test_vec[i].r[0]), simde_vld1q_s8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i8x16(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16x2_t c = {{a, b}};

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int8_t buf[32];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_int8x16x2_t r = simde_vld2q_s8(buf);

    simde_test_arm_neon_write_i8x16x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[16];
    int16_t r[2][8];
  } test_vec[] = {
    { {  INT16_C( 11850),  INT16_C( 12679),  INT16_C(  1668), -INT16_C(  2829),  INT16_C(  2417),  INT16_C(  6613), -INT16_C( 26382), -INT16_C(  6963),
         INT16_C( 11746), -INT16_C( 19992),  INT16_C(   261), -INT16_C( 26272), -INT16_C( 27245),  INT16_C( 20274), -INT16_C( 24440), -INT16_C( 11702) },
        { {  INT16_C( 11850),  INT16_C(  1668),  INT16_C(  2417), -INT16_C( 26382),  INT16_C( 11746),  INT16_C(   261), -INT16_C( 27245), -INT16_C( 24440) },
          {  INT16_C( 12679), -INT16_C(  2829),  INT16_C(  6613), -INT16_C(  6963), -INT16_C( 19992), -INT16_C( 26272),  INT16_C( 20274), -INT16_C( 11702) } },
    },
    { { -INT16_C( 11826),  INT16_C( 21252), -INT16_C(  2089),  INT16_C( 18503),  INT16_C(  7168), -INT16_C(  3231),  INT16_C( 11956), -INT16_C( 26921),
        -INT16_C( 16548),  INT16_C( 24903), -INT16_C( 22335),  INT16_C( 21754),  INT16_C( 11325), -INT16_C( 14941), -INT16_C(  4659), -INT16_C( 25704) },
        { { -INT16_C( 11826), -INT16_C(  2089),  INT16_C(  7168),  INT16_C( 11956), -INT16_C( 16548), -INT16_C( 22335),  INT16_C( 11325), -INT16_C(  4659) },
          {  INT16_C( 21252),  INT16_C( 18503), -INT16_C(  3231), -INT16_C( 26921),  INT16_C( 24903),  INT16_C( 21754), -INT16_C( 14941), -INT16_C( 25704) } },
    },
    { { -INT16_C( 25410), -INT16_C( 27154),  INT16_C( 13715), -INT16_C( 27427),  INT16_C( 15953),  INT16_C(  1415),  INT16_C( 24172), -INT16_C( 14181),
        -INT16_C(  7395), -INT16_C(  8663),  INT16_C(  9355), -INT16_C( 14286), -INT16_C( 10928),  INT16_C(  7566),  INT16_C(  9922), -INT16_C( 32583) },
        { { -INT16_C( 25410),  INT16_C( 13715),  INT16_C( 15953),  INT16_C( 24172), -INT16_C(  7395),  INT16_C(  9355), -INT16_C( 10928),  INT16_C(  9922) },
          { -INT16_C( 27154), -INT16_C( 27427),  INT16_C(  1415), -INT16_C( 14181), -INT16_C(  8663), -INT16_C( 14286),  INT16_C(  7566), -INT16_C( 32583) } },
    },
    { { -INT16_C( 22590),  INT16_C( 21781), -INT16_C(  3363),  INT16_C( 12009),  INT16_C( 28720), -INT16_C( 25292), -INT16_C( 12338), -INT16_C(  5019),
        -INT16_C( 28750),  INT16_C( 15818), -INT16_C(   589),  INT16_C(   774), -INT16_C( 27438), -INT16_C( 27359), -INT16_C(  9542),  INT16_C( 31765) },
        { { -INT16_C( 22590), -INT16_C(  3363),  INT16_C( 28720), -INT16_C( 12338), -INT16_C( 28750), -INT16_C(   589), -INT16_C( 27438), -INT16_C(  9542) },
          {  INT16_C( 21781),  INT16_C( 12009), -INT16_C( 25292), -INT16_C(  5019),  INT16_C( 15818),  INT16_C(   774), -INT16_C( 27359),  INT16_C( 31765) } },
    },
    { {  INT16_C( 11137),  INT16_C( 24273), -INT16_C( 17635),  INT16_C( 20109), -INT16_C( 16085), -INT16_C(  1301),  INT16_C( 20624),  INT16_C( 17382),
        -INT16_C( 20257), -INT16_C( 28032), -INT16_C( 31059), -INT16_C( 32618), -INT16_C( 18662), -INT16_C( 11243),  INT16_C( 10897),  INT16_C(  4688) },
        { {  INT16_C( 11137), -INT16_C( 17635), -INT16_C( 16085),  INT16_C( 20624), -INT16_C( 20257), -INT16_C( 31059), -INT16_C( 18662),  INT16_C( 10897) },
          {  INT16_C( 24273),  INT16_C( 20109), -INT16_C(  1301),  INT16_C( 17382), -INT16_C( 28032), -INT16_C( 32618), -INT16_C( 11243),  INT16_C(  4688) } },
    },
    { {  INT16_C(  8789),  INT16_C( 29553), -INT16_C(   291),  INT16_C(  2241), -INT16_C( 21313),  INT16_C( 20226), -INT16_C(  5892), -INT16_C(  9070),
         INT16_C(  5017),  INT16_C( 18030),  INT16_C(  1177), -INT16_C( 19258), -INT16_C(  9285),  INT16_C( 19592), -INT16_C(  9978),  INT16_C( 23391) },
        { {  INT16_C(  8789), -INT16_C(   291), -INT16_C( 21313), -INT16_C(  5892),  INT16_C(  5017),  INT16_C(  1177), -INT16_C(  9285), -INT16_C(  9978) },
          {  INT16_C( 29553),  INT16_C(  2241),  INT16_C( 20226), -INT16_C(  9070),  INT16_C( 18030), -INT16_C( 19258),  INT16_C( 19592),  INT16_C( 23391) } },
    },
    { { -INT16_C( 12037), -INT16_C( 10034), -INT16_C( 28722), -INT16_C( 29216), -INT16_C(  7365),  INT16_C( 14556),  INT16_C( 28619),  INT16_C( 25620),
        -INT16_C( 32126),  INT16_C(  7083),  INT16_C( 29063),  INT16_C( 17103),  INT16_C( 22605),  INT16_C( 21391), -INT16_C(  4559),  INT16_C( 11438) },
        { { -INT16_C( 12037), -INT16_C( 28722), -INT16_C(  7365),  INT16_C( 28619), -INT16_C( 32126),  INT16_C( 29063),  INT16_C( 22605), -INT16_C(  4559) },
          { -INT16_C( 10034), -INT16_C( 29216),  INT16_C( 14556),  INT16_C( 25620),  INT16_C(  7083),  INT16_C( 17103),  INT16_C( 21391),  INT16_C( 11438) } },
    },
    { {  INT16_C( 32190), -INT16_C( 29692), -INT16_C(  7156),  INT16_C( 18457), -INT16_C(  2617), -INT16_C( 27776), -INT16_C( 27548), -INT16_C(  6409),
        -INT16_C( 24042), -INT16_C( 25342), -INT16_C( 12012),  INT16_C( 25056),  INT16_C( 28457),  INT16_C( 23220),  INT16_C( 25181),  INT16_C(  7046) },
        { {  INT16_C( 32190), -INT16_C(  7156), -INT16_C(  2617), -INT16_C( 27548), -INT16_C( 24042), -INT16_C( 12012),  INT16_C( 28457),  INT16_C( 25181) },
          { -INT16_C( 29692),  INT16_C( 18457), -INT16_C( 27776), -INT16_C(  6409), -INT16_C( 25342),  INT16_C( 25056),  INT16_C( 23220),  INT16_C(  7046) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x2_t r = simde_vld2q_s16(test_vec[i].a);

    simde_int16x8x2_t expected = {
        {simde_vld1q_s16(test_vec[i].r[0]), simde_vld1q_s16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i16x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int16_t buf[16];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_int16x8x2_t r = simde_vld2q_s16(buf);

    simde_test_arm_neon_write_i16x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[8];
    int32_t r[2][4];
  } test_vec[] = {
    { { -INT32_C(  1652910308),  INT32_C(  1276922200), -INT32_C(  1246624074),  INT32_C(   345995066),
        -INT32_C(  1909421954),  INT32_C(  1484737180), -INT32_C(  1927907536),  INT32_C(  1716163914) },
        { { -INT32_C(  1652910308), -INT32_C(  1246624074), -INT32_C(  1909421954), -INT32_C(  1927907536) },
          {  INT32_C(  1276922200),  INT32_C(   345995066),  INT32_C(  1484737180),  INT32_C(  1716163914) } },
    },
    { { -INT32_C(  2063350484), -INT32_C(   992927986),  INT32_C(  1601798949),  INT32_C(  2037651963),
         INT32_C(  1023976609),  INT32_C(   513116142),  INT32_C(  1236052991),  INT32_C(  1840248385) },
        { { -INT32_C(  2063350484),  INT32_C(  1601798949),  INT32_C(  1023976609),  INT32_C(  1236052991) },
          { -INT32_C(   992927986),  INT32_C(  2037651963),  INT32_C(   513116142),  INT32_C(  1840248385) } },
    },
    { { -INT32_C(   890064197), -INT32_C(   141638702),  INT32_C(  1113000007), -INT32_C(  1027880159),
         INT32_C(  1593820015),  INT32_C(  1249678667), -INT32_C(  2121062336), -INT32_C(   621854177) },
        { { -INT32_C(   890064197),  INT32_C(  1113000007),  INT32_C(  1593820015), -INT32_C(  2121062336) },
          { -INT32_C(   141638702), -INT32_C(  1027880159),  INT32_C(  1249678667), -INT32_C(   621854177) } },
    },
    { { -INT32_C(   962272780), -INT32_C(   323079259),  INT32_C(  1546523963),  INT32_C(  1327426016),
        -INT32_C(   122872403), -INT32_C(   213767502),  INT32_C(  1903482194),  INT32_C(   189555479) },
        { { -INT32_C(   962272780),  INT32_C(  1546523963), -INT32_C(   122872403),  INT32_C(  1903482194) },
          { -INT32_C(   323079259),  INT32_C(  1327426016), -INT32_C(   213767502),  INT32_C(   189555479) } },
    },
    { { -INT32_C(   355274683),  INT32_C(  1591119907), -INT32_C(  2051406683), -INT32_C(  1697326867),
        -INT32_C(  1466793226), -INT32_C(    23341908), -INT32_C(  1066397527), -INT32_C(  1194541965) },
        { { -INT32_C(   355274683), -INT32_C(  2051406683), -INT32_C(  1466793226), -INT32_C(  1066397527) },
          {  INT32_C(  1591119907), -INT32_C(  1697326867), -INT32_C(    23341908), -INT32_C(  1194541965) } },
    },
    { { -INT32_C(   794648916), -INT32_C(   751929298),  INT32_C(  1784211836), -INT32_C(  1224463167),
         INT32_C(  1516279726),  INT32_C(   358218603),  INT32_C(  2144717067),  INT32_C(   825729413) },
        { { -INT32_C(   794648916),  INT32_C(  1784211836),  INT32_C(  1516279726),  INT32_C(  2144717067) },
          { -INT32_C(   751929298), -INT32_C(  1224463167),  INT32_C(   358218603),  INT32_C(   825729413) } },
    },
    { {  INT32_C(  1828837951), -INT32_C(   817876910), -INT32_C(   633759719),  INT32_C(  1938963909),
         INT32_C(  1087304404), -INT32_C(   111859731),  INT32_C(  1970809584),  INT32_C(   195473356) },
        { {  INT32_C(  1828837951), -INT32_C(   633759719),  INT32_C(  1087304404),  INT32_C(  1970809584) },
          { -INT32_C(   817876910),  INT32_C(  1938963909), -INT32_C(   111859731),  INT32_C(   195473356) } },
    },
    { { -INT32_C(   596006775), -INT32_C(   240404008),  INT32_C(   399238226), -INT32_C(   158704351),
         INT32_C(  1026971727),  INT32_C(  1865845631), -INT32_C(  2115719499), -INT32_C(   410154147) },
        { { -INT32_C(   596006775),  INT32_C(   399238226),  INT32_C(  1026971727), -INT32_C(  2115719499) },
          { -INT32_C(   240404008), -INT32_C(   158704351),  INT32_C(  1865845631), -INT32_C(   410154147) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x2_t r = simde_vld2q_s32(test_vec[i].a);

    simde_int32x4x2_t expected = {
        {simde_vld1q_s32(test_vec[i].r[0]), simde_vld1q_s32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i32x4(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int32_t buf[8];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_int32x4x2_t r = simde_vld2q_s32(buf);

    simde_test_arm_neon_write_i32x4x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[4];
    int64_t r[2][2];
  } test_vec[] = {
    { {  INT64_C(  761675503690497765), -INT64_C( 3317868187565492127),
         INT64_C( 6422292174704708047), -INT64_C( 4276746329755678056) },
        { {  INT64_C(  761675503690497765),  INT64_C( 6422292174704708047) },
          { -INT64_C( 3317868187565492127), -INT64_C( 4276746329755678056) } },
    },
    { { -INT64_C( 6949583921125508177), -INT64_C( 8908427146440727274),
        -INT64_C( 7890751878801495695), -INT64_C( 7775319739955481739) },
        { { -INT64_C( 6949583921125508177), -INT64_C( 7890751878801495695) },
          { -INT64_C( 8908427146440727274), -INT64_C( 7775319739955481739) } },
    },
    { { -INT64_C( 2838209209255287618), -INT64_C( 1655702365654380340),
         INT64_C( 3438371571634163500), -INT64_C( 2812327433930041729) },
        { { -INT64_C( 2838209209255287618),  INT64_C( 3438371571634163500) },
          { -INT64_C( 1655702365654380340), -INT64_C( 2812327433930041729) } },
    },
    { { -INT64_C( 8945432303512580032),  INT64_C( 3414021002538270720),
         INT64_C( 8881675687628664665), -INT64_C( 6803857797262883422) },
        { { -INT64_C( 8945432303512580032),  INT64_C( 8881675687628664665) },
          {  INT64_C( 3414021002538270720), -INT64_C( 6803857797262883422) } },
    },
    { { -INT64_C( 2800536549414704921), -INT64_C( 8435045075786848322),
        -INT64_C(  893436412045671134),  INT64_C( 3938470781334223014) },
        { { -INT64_C( 2800536549414704921), -INT64_C(  893436412045671134) },
          { -INT64_C( 8435045075786848322),  INT64_C( 3938470781334223014) } },
    },
    { { -INT64_C( 8621023513008583766), -INT64_C( 9017831118517654241),
        -INT64_C(   17106915664299905),  INT64_C( 6789087051402080945) },
        { { -INT64_C( 8621023513008583766), -INT64_C(   17106915664299905) },
          { -INT64_C( 9017831118517654241),  INT64_C( 6789087051402080945) } },
    },
    { {  INT64_C( 2543473880721263865),  INT64_C( 5821833599798974185),
         INT64_C( 6277706328444005574), -INT64_C( 3717564459626585002) },
        { {  INT64_C( 2543473880721263865),  INT64_C( 6277706328444005574) },
          {  INT64_C( 5821833599798974185), -INT64_C( 3717564459626585002) } },
    },
    { {  INT64_C( 7909406733251856539),  INT64_C( 5445558404010882673),
        -INT64_C( 1375135456396922130),  INT64_C( 7731658909898130093) },
        { {  INT64_C( 7909406733251856539), -INT64_C( 1375135456396922130) },
          {  INT64_C( 5445558404010882673),  INT64_C( 7731658909898130093) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x2_t r = simde_vld2q_s64(test_vec[i].a);

    simde_int64x2x2_t expected = {
        {simde_vld1q_s64(test_vec[i].r[0]), simde_vld1q_s64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_i64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_i64x2(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int64_t buf[4];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_int64x2x2_t r = simde_vld2q_s64(buf);

    simde_test_arm_neon_write_i64x2x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[32];
    uint8_t r[2][16];
  } test_vec[] = {
    { { UINT8_C( 56), UINT8_C(119), UINT8_C(167), UINT8_C( 99), UINT8_C(221), UINT8_C(126), UINT8_C(139), UINT8_C( 94),
        UINT8_C(  0), UINT8_C(203), UINT8_C(216), UINT8_C( 77), UINT8_C( 79), UINT8_C(152), UINT8_C(  2), UINT8_C(187),
        UINT8_C(173), UINT8_C(251), UINT8_C( 63), UINT8_C( 57), UINT8_C(133), UINT8_C( 35), UINT8_C(243), UINT8_C(166),
        UINT8_C( 51), UINT8_C(149), UINT8_C(128), UINT8_C( 99), UINT8_C(176), UINT8_C(195), UINT8_C( 30), UINT8_C(232) },
        { { UINT8_C( 56), UINT8_C(167), UINT8_C(221), UINT8_C(139), UINT8_C(  0), UINT8_C(216), UINT8_C( 79), UINT8_C(  2),
            UINT8_C(173), UINT8_C( 63), UINT8_C(133), UINT8_C(243), UINT8_C( 51), UINT8_C(128), UINT8_C(176), UINT8_C( 30) },
          { UINT8_C(119), UINT8_C( 99), UINT8_C(126), UINT8_C( 94), UINT8_C(203), UINT8_C( 77), UINT8_C(152), UINT8_C(187),
            UINT8_C(251), UINT8_C( 57), UINT8_C( 35), UINT8_C(166), UINT8_C(149), UINT8_C( 99), UINT8_C(195), UINT8_C(232) } },
    },
    { { UINT8_C( 58), UINT8_C(198), UINT8_C( 75), UINT8_C( 24), UINT8_C( 68), UINT8_C(214), UINT8_C(118), UINT8_C( 68),
        UINT8_C(161), UINT8_C( 78), UINT8_C(145), UINT8_C(240), UINT8_C(231), UINT8_C(148), UINT8_C(172), UINT8_C(148),
        UINT8_C(143), UINT8_C(235), UINT8_C(205), UINT8_C( 20), UINT8_C( 14), UINT8_C(192), UINT8_C(186), UINT8_C( 65),
        UINT8_C( 85), UINT8_C( 58), UINT8_C(164), UINT8_C(  5), UINT8_C(254), UINT8_C(195), UINT8_C(237), UINT8_C( 56) },
        { { UINT8_C( 58), UINT8_C( 75), UINT8_C( 68), UINT8_C(118), UINT8_C(161), UINT8_C(145), UINT8_C(231), UINT8_C(172),
            UINT8_C(143), UINT8_C(205), UINT8_C( 14), UINT8_C(186), UINT8_C( 85), UINT8_C(164), UINT8_C(254), UINT8_C(237) },
          { UINT8_C(198), UINT8_C( 24), UINT8_C(214), UINT8_C( 68), UINT8_C( 78), UINT8_C(240), UINT8_C(148), UINT8_C(148),
            UINT8_C(235), UINT8_C( 20), UINT8_C(192), UINT8_C( 65), UINT8_C( 58), UINT8_C(  5), UINT8_C(195), UINT8_C( 56) } },
    },
    { { UINT8_C(137), UINT8_C( 56), UINT8_C( 80), UINT8_C(205), UINT8_C( 15), UINT8_C(199), UINT8_C( 18), UINT8_C(176),
        UINT8_C( 21), UINT8_C(163), UINT8_C(161), UINT8_C(252), UINT8_C( 55), UINT8_C( 77), UINT8_C(144), UINT8_C(198),
        UINT8_C( 56), UINT8_C( 93), UINT8_C(219), UINT8_C( 70), UINT8_C( 29), UINT8_C(149), UINT8_C(135), UINT8_C(115),
        UINT8_C(208), UINT8_C( 43), UINT8_C(120), UINT8_C(206), UINT8_C(238), UINT8_C(102), UINT8_C(  6), UINT8_C(119) },
        { { UINT8_C(137), UINT8_C( 80), UINT8_C( 15), UINT8_C( 18), UINT8_C( 21), UINT8_C(161), UINT8_C( 55), UINT8_C(144),
            UINT8_C( 56), UINT8_C(219), UINT8_C( 29), UINT8_C(135), UINT8_C(208), UINT8_C(120), UINT8_C(238), UINT8_C(  6) },
          { UINT8_C( 56), UINT8_C(205), UINT8_C(199), UINT8_C(176), UINT8_C(163), UINT8_C(252), UINT8_C( 77), UINT8_C(198),
            UINT8_C( 93), UINT8_C( 70), UINT8_C(149), UINT8_C(115), UINT8_C( 43), UINT8_C(206), UINT8_C(102), UINT8_C(119) } },
    },
    { { UINT8_C(158), UINT8_C( 87), UINT8_C( 69), UINT8_C(173), UINT8_C( 30), UINT8_C( 87), UINT8_C( 94), UINT8_C( 51),
        UINT8_C(250),    UINT8_MAX, UINT8_C( 48), UINT8_C( 50), UINT8_C( 76), UINT8_C(192), UINT8_C(248), UINT8_C(132),
        UINT8_C( 30), UINT8_C(211), UINT8_C(202), UINT8_C( 59), UINT8_C(105), UINT8_C( 81), UINT8_C(174), UINT8_C( 57),
        UINT8_C(124), UINT8_C( 39), UINT8_C(  7), UINT8_C(107), UINT8_C(141), UINT8_C( 13), UINT8_C(226), UINT8_C( 43) },
        { { UINT8_C(158), UINT8_C( 69), UINT8_C( 30), UINT8_C( 94), UINT8_C(250), UINT8_C( 48), UINT8_C( 76), UINT8_C(248),
            UINT8_C( 30), UINT8_C(202), UINT8_C(105), UINT8_C(174), UINT8_C(124), UINT8_C(  7), UINT8_C(141), UINT8_C(226) },
          { UINT8_C( 87), UINT8_C(173), UINT8_C( 87), UINT8_C( 51),    UINT8_MAX, UINT8_C( 50), UINT8_C(192), UINT8_C(132),
            UINT8_C(211), UINT8_C( 59), UINT8_C( 81), UINT8_C( 57), UINT8_C( 39), UINT8_C(107), UINT8_C( 13), UINT8_C( 43) } },
    },
    { { UINT8_C(100), UINT8_C( 39), UINT8_C(217), UINT8_C(130), UINT8_C(126), UINT8_C( 55), UINT8_C(182), UINT8_C(121),
        UINT8_C( 54), UINT8_C(230), UINT8_C(171), UINT8_C(130), UINT8_C(166), UINT8_C(163), UINT8_C(  6), UINT8_C(196),
        UINT8_C(119), UINT8_C(208), UINT8_C(  0), UINT8_C(224), UINT8_C( 33), UINT8_C(174), UINT8_C( 25), UINT8_C(157),
        UINT8_C(213), UINT8_C( 32), UINT8_C(  8), UINT8_C( 98), UINT8_C( 45), UINT8_C(235), UINT8_C(142), UINT8_C(146) },
        { { UINT8_C(100), UINT8_C(217), UINT8_C(126), UINT8_C(182), UINT8_C( 54), UINT8_C(171), UINT8_C(166), UINT8_C(  6),
            UINT8_C(119), UINT8_C(  0), UINT8_C( 33), UINT8_C( 25), UINT8_C(213), UINT8_C(  8), UINT8_C( 45), UINT8_C(142) },
          { UINT8_C( 39), UINT8_C(130), UINT8_C( 55), UINT8_C(121), UINT8_C(230), UINT8_C(130), UINT8_C(163), UINT8_C(196),
            UINT8_C(208), UINT8_C(224), UINT8_C(174), UINT8_C(157), UINT8_C( 32), UINT8_C( 98), UINT8_C(235), UINT8_C(146) } },
    },
    { { UINT8_C( 18), UINT8_C(103), UINT8_C( 20), UINT8_C(145), UINT8_C(158), UINT8_C(202), UINT8_C( 10), UINT8_C(212),
        UINT8_C(176), UINT8_C(181), UINT8_C( 86), UINT8_C( 87), UINT8_C( 88), UINT8_C( 92), UINT8_C( 27), UINT8_C(207),
        UINT8_C( 44), UINT8_C( 27), UINT8_C(175), UINT8_C( 77), UINT8_C(202), UINT8_C(200), UINT8_C(234), UINT8_C(159),
        UINT8_C(232), UINT8_C(243), UINT8_C(  2), UINT8_C( 22), UINT8_C(222), UINT8_C(144), UINT8_C(168), UINT8_C(240) },
        { { UINT8_C( 18), UINT8_C( 20), UINT8_C(158), UINT8_C( 10), UINT8_C(176), UINT8_C( 86), UINT8_C( 88), UINT8_C( 27),
            UINT8_C( 44), UINT8_C(175), UINT8_C(202), UINT8_C(234), UINT8_C(232), UINT8_C(  2), UINT8_C(222), UINT8_C(168) },
          { UINT8_C(103), UINT8_C(145), UINT8_C(202), UINT8_C(212), UINT8_C(181), UINT8_C( 87), UINT8_C( 92), UINT8_C(207),
            UINT8_C( 27), UINT8_C( 77), UINT8_C(200), UINT8_C(159), UINT8_C(243), UINT8_C( 22), UINT8_C(144), UINT8_C(240) } },
    },
    { { UINT8_C(247), UINT8_C(188), UINT8_C(129), UINT8_C(149), UINT8_C(135), UINT8_C(139), UINT8_C(105), UINT8_C( 55),
        UINT8_C( 64), UINT8_C(191), UINT8_C(142), UINT8_C(153), UINT8_C( 27), UINT8_C(170), UINT8_C(104), UINT8_C( 71),
        UINT8_C(197), UINT8_C( 24), UINT8_C(148), UINT8_C(143), UINT8_C(224), UINT8_C(126), UINT8_C( 47), UINT8_C(201),
        UINT8_C(113), UINT8_C( 49), UINT8_C(223), UINT8_C( 79), UINT8_C(193), UINT8_C(135), UINT8_C( 64), UINT8_C(184) },
        { { UINT8_C(247), UINT8_C(129), UINT8_C(135), UINT8_C(105), UINT8_C( 64), UINT8_C(142), UINT8_C( 27), UINT8_C(104),
            UINT8_C(197), UINT8_C(148), UINT8_C(224), UINT8_C( 47), UINT8_C(113), UINT8_C(223), UINT8_C(193), UINT8_C( 64) },
          { UINT8_C(188), UINT8_C(149), UINT8_C(139), UINT8_C( 55), UINT8_C(191), UINT8_C(153), UINT8_C(170), UINT8_C( 71),
            UINT8_C( 24), UINT8_C(143), UINT8_C(126), UINT8_C(201), UINT8_C( 49), UINT8_C( 79), UINT8_C(135), UINT8_C(184) } },
    },
    { { UINT8_C( 67), UINT8_C(193), UINT8_C( 77), UINT8_C(202), UINT8_C( 77), UINT8_C(182), UINT8_C(  2), UINT8_C(141),
        UINT8_C(117), UINT8_C(144), UINT8_C( 38), UINT8_C(144), UINT8_C( 58), UINT8_C(143), UINT8_C(215), UINT8_C(  0),
        UINT8_C(167), UINT8_C(107), UINT8_C(143), UINT8_C(135), UINT8_C(233), UINT8_C(190), UINT8_C( 80), UINT8_C( 91),
        UINT8_C(239), UINT8_C( 47), UINT8_C(170), UINT8_C(176), UINT8_C(182), UINT8_C(234), UINT8_C(104), UINT8_C(250) },
        { { UINT8_C( 67), UINT8_C( 77), UINT8_C( 77), UINT8_C(  2), UINT8_C(117), UINT8_C( 38), UINT8_C( 58), UINT8_C(215),
            UINT8_C(167), UINT8_C(143), UINT8_C(233), UINT8_C( 80), UINT8_C(239), UINT8_C(170), UINT8_C(182), UINT8_C(104) },
          { UINT8_C(193), UINT8_C(202), UINT8_C(182), UINT8_C(141), UINT8_C(144), UINT8_C(144), UINT8_C(143), UINT8_C(  0),
            UINT8_C(107), UINT8_C(135), UINT8_C(190), UINT8_C( 91), UINT8_C( 47), UINT8_C(176), UINT8_C(234), UINT8_C(250) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x2_t r = simde_vld2q_u8(test_vec[i].a);

    simde_uint8x16x2_t expected = {
        {simde_vld1q_u8(test_vec[i].r[0]), simde_vld1q_u8(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u8x16(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u8x16(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16x2_t c = {{a, b}};

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint8_t buf[32];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint8x16x2_t r = simde_vld2q_u8(buf);

    simde_test_arm_neon_write_u8x16x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[16];
    uint16_t r[2][8];
  } test_vec[] = {
    { { UINT16_C( 5263), UINT16_C(46704), UINT16_C(17324), UINT16_C(  435), UINT16_C(22826), UINT16_C(35226), UINT16_C( 4289), UINT16_C(14289),
        UINT16_C(15842), UINT16_C(32624), UINT16_C( 9166), UINT16_C(50530), UINT16_C(15251), UINT16_C(37458), UINT16_C(64003), UINT16_C(37377) },
        { { UINT16_C( 5263), UINT16_C(17324), UINT16_C(22826), UINT16_C( 4289), UINT16_C(15842), UINT16_C( 9166), UINT16_C(15251), UINT16_C(64003) },
          { UINT16_C(46704), UINT16_C(  435), UINT16_C(35226), UINT16_C(14289), UINT16_C(32624), UINT16_C(50530), UINT16_C(37458), UINT16_C(37377) } },
    },
    { { UINT16_C(28943), UINT16_C(47944), UINT16_C(64436), UINT16_C(57020), UINT16_C(22100), UINT16_C( 5480), UINT16_C(14695), UINT16_C(18765),
        UINT16_C(48502), UINT16_C(17865), UINT16_C(11232), UINT16_C(29450), UINT16_C(23654), UINT16_C(26886), UINT16_C( 1879), UINT16_C(26363) },
        { { UINT16_C(28943), UINT16_C(64436), UINT16_C(22100), UINT16_C(14695), UINT16_C(48502), UINT16_C(11232), UINT16_C(23654), UINT16_C( 1879) },
          { UINT16_C(47944), UINT16_C(57020), UINT16_C( 5480), UINT16_C(18765), UINT16_C(17865), UINT16_C(29450), UINT16_C(26886), UINT16_C(26363) } },
    },
    { { UINT16_C(17528), UINT16_C(11297), UINT16_C(56639), UINT16_C(37899), UINT16_C(29491), UINT16_C(39593), UINT16_C(63148), UINT16_C( 8932),
        UINT16_C(44468), UINT16_C(37991), UINT16_C(29144), UINT16_C(16136), UINT16_C( 3790), UINT16_C( 9640), UINT16_C(42005), UINT16_C(36235) },
        { { UINT16_C(17528), UINT16_C(56639), UINT16_C(29491), UINT16_C(63148), UINT16_C(44468), UINT16_C(29144), UINT16_C( 3790), UINT16_C(42005) },
          { UINT16_C(11297), UINT16_C(37899), UINT16_C(39593), UINT16_C( 8932), UINT16_C(37991), UINT16_C(16136), UINT16_C( 9640), UINT16_C(36235) } },
    },
    { { UINT16_C(44264), UINT16_C(10169), UINT16_C(50313), UINT16_C(48315), UINT16_C(25911), UINT16_C(58199), UINT16_C(15195), UINT16_C( 3846),
        UINT16_C(28136), UINT16_C(49316), UINT16_C(44255), UINT16_C(44543), UINT16_C(43194), UINT16_C(53202), UINT16_C(23884), UINT16_C(13404) },
        { { UINT16_C(44264), UINT16_C(50313), UINT16_C(25911), UINT16_C(15195), UINT16_C(28136), UINT16_C(44255), UINT16_C(43194), UINT16_C(23884) },
          { UINT16_C(10169), UINT16_C(48315), UINT16_C(58199), UINT16_C( 3846), UINT16_C(49316), UINT16_C(44543), UINT16_C(53202), UINT16_C(13404) } },
    },
    { { UINT16_C( 5385), UINT16_C(37467), UINT16_C( 6106), UINT16_C( 4430), UINT16_C(42364), UINT16_C(55285), UINT16_C(64480), UINT16_C(51431),
        UINT16_C(35688), UINT16_C(18313), UINT16_C(34871), UINT16_C(61940), UINT16_C(50736), UINT16_C(31936), UINT16_C( 7203), UINT16_C(11440) },
        { { UINT16_C( 5385), UINT16_C( 6106), UINT16_C(42364), UINT16_C(64480), UINT16_C(35688), UINT16_C(34871), UINT16_C(50736), UINT16_C( 7203) },
          { UINT16_C(37467), UINT16_C( 4430), UINT16_C(55285), UINT16_C(51431), UINT16_C(18313), UINT16_C(61940), UINT16_C(31936), UINT16_C(11440) } },
    },
    { { UINT16_C( 3121), UINT16_C( 3006), UINT16_C( 3363), UINT16_C(40733), UINT16_C( 4786), UINT16_C(37750), UINT16_C(23821), UINT16_C(30043),
        UINT16_C(58600), UINT16_C( 8125), UINT16_C(45421), UINT16_C(40208), UINT16_C(53368), UINT16_C(39706), UINT16_C(51948), UINT16_C( 7880) },
        { { UINT16_C( 3121), UINT16_C( 3363), UINT16_C( 4786), UINT16_C(23821), UINT16_C(58600), UINT16_C(45421), UINT16_C(53368), UINT16_C(51948) },
          { UINT16_C( 3006), UINT16_C(40733), UINT16_C(37750), UINT16_C(30043), UINT16_C( 8125), UINT16_C(40208), UINT16_C(39706), UINT16_C( 7880) } },
    },
    { { UINT16_C(34518), UINT16_C(63785), UINT16_C(18067), UINT16_C(18072), UINT16_C( 3928), UINT16_C(26073), UINT16_C(13420), UINT16_C(21979),
        UINT16_C(38937), UINT16_C(34420), UINT16_C(34121), UINT16_C(49443), UINT16_C(15701), UINT16_C(16989), UINT16_C( 9480), UINT16_C(56928) },
        { { UINT16_C(34518), UINT16_C(18067), UINT16_C( 3928), UINT16_C(13420), UINT16_C(38937), UINT16_C(34121), UINT16_C(15701), UINT16_C( 9480) },
          { UINT16_C(63785), UINT16_C(18072), UINT16_C(26073), UINT16_C(21979), UINT16_C(34420), UINT16_C(49443), UINT16_C(16989), UINT16_C(56928) } },
    },
    { { UINT16_C(35243), UINT16_C(16344), UINT16_C(28880), UINT16_C(10373), UINT16_C(24191), UINT16_C(60558), UINT16_C(27026), UINT16_C(43841),
        UINT16_C(46337), UINT16_C(18993), UINT16_C(21818), UINT16_C(36876), UINT16_C(27026), UINT16_C(39634), UINT16_C(12942), UINT16_C(14713) },
        { { UINT16_C(35243), UINT16_C(28880), UINT16_C(24191), UINT16_C(27026), UINT16_C(46337), UINT16_C(21818), UINT16_C(27026), UINT16_C(12942) },
          { UINT16_C(16344), UINT16_C(10373), UINT16_C(60558), UINT16_C(43841), UINT16_C(18993), UINT16_C(36876), UINT16_C(39634), UINT16_C(14713) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x2_t r = simde_vld2q_u16(test_vec[i].a);

    simde_uint16x8x2_t expected = {
        {simde_vld1q_u16(test_vec[i].r[0]), simde_vld1q_u16(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u16x8(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u16x8(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint16_t buf[16];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint16x8x2_t r = simde_vld2q_u16(buf);

    simde_test_arm_neon_write_u16x8x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[8];
    uint32_t r[2][4];
  } test_vec[] = {
    { { UINT32_C(2339918267), UINT32_C(1102380481), UINT32_C(3995943515), UINT32_C(2895736491),
        UINT32_C(1593232163), UINT32_C(3001942560), UINT32_C(4182622315), UINT32_C(2905851634) },
        { { UINT32_C(2339918267), UINT32_C(3995943515), UINT32_C(1593232163), UINT32_C(4182622315) },
          { UINT32_C(1102380481), UINT32_C(2895736491), UINT32_C(3001942560), UINT32_C(2905851634) } },
    },
    { { UINT32_C(3627658007), UINT32_C(  68808105), UINT32_C(3673310767), UINT32_C(3632696500),
        UINT32_C(2000059479), UINT32_C(3928564863), UINT32_C(3605296868), UINT32_C(1401100092) },
        { { UINT32_C(3627658007), UINT32_C(3673310767), UINT32_C(2000059479), UINT32_C(3605296868) },
          { UINT32_C(  68808105), UINT32_C(3632696500), UINT32_C(3928564863), UINT32_C(1401100092) } },
    },
    { { UINT32_C(1798094018), UINT32_C(3631236521), UINT32_C(1085432460), UINT32_C(1159215342),
        UINT32_C( 884756149), UINT32_C(1444865650), UINT32_C(2569798236), UINT32_C(3706499097) },
        { { UINT32_C(1798094018), UINT32_C(1085432460), UINT32_C( 884756149), UINT32_C(2569798236) },
          { UINT32_C(3631236521), UINT32_C(1159215342), UINT32_C(1444865650), UINT32_C(3706499097) } },
    },
    { { UINT32_C( 373758060), UINT32_C(3941513054), UINT32_C( 137011482), UINT32_C(2387493849),
        UINT32_C(  79825553), UINT32_C(1297801712), UINT32_C(4259743715), UINT32_C(2748961335) },
        { { UINT32_C( 373758060), UINT32_C( 137011482), UINT32_C(  79825553), UINT32_C(4259743715) },
          { UINT32_C(3941513054), UINT32_C(2387493849), UINT32_C(1297801712), UINT32_C(2748961335) } },
    },
    { { UINT32_C(1236869355), UINT32_C(4063471832), UINT32_C( 586833225), UINT32_C( 850479264),
        UINT32_C(1127641939), UINT32_C( 948998228), UINT32_C(1312126487), UINT32_C( 888278601) },
        { { UINT32_C(1236869355), UINT32_C( 586833225), UINT32_C(1127641939), UINT32_C(1312126487) },
          { UINT32_C(4063471832), UINT32_C( 850479264), UINT32_C( 948998228), UINT32_C( 888278601) } },
    },
    { { UINT32_C( 108899118), UINT32_C(2633543763), UINT32_C(2931815181), UINT32_C(2397073467),
        UINT32_C( 953292515), UINT32_C(3195036326), UINT32_C( 571254233), UINT32_C(3780574899) },
        { { UINT32_C( 108899118), UINT32_C(2931815181), UINT32_C( 953292515), UINT32_C( 571254233) },
          { UINT32_C(2633543763), UINT32_C(2397073467), UINT32_C(3195036326), UINT32_C(3780574899) } },
    },
    { { UINT32_C(4259894186), UINT32_C(2426069123), UINT32_C( 255744467), UINT32_C(2895978185),
        UINT32_C(3689180980), UINT32_C(2878952658), UINT32_C(2899158521), UINT32_C(1317938084) },
        { { UINT32_C(4259894186), UINT32_C( 255744467), UINT32_C(3689180980), UINT32_C(2899158521) },
          { UINT32_C(2426069123), UINT32_C(2895978185), UINT32_C(2878952658), UINT32_C(1317938084) } },
    },
    { { UINT32_C(2034988790), UINT32_C( 705291606), UINT32_C( 121194558), UINT32_C(2612319846),
        UINT32_C( 410425414), UINT32_C(3871543277), UINT32_C(1486065844), UINT32_C(2846237107) },
        { { UINT32_C(2034988790), UINT32_C( 121194558), UINT32_C( 410425414), UINT32_C(1486065844) },
          { UINT32_C( 705291606), UINT32_C(2612319846), UINT32_C(3871543277), UINT32_C(2846237107) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x2_t r = simde_vld2q_u32(test_vec[i].a);

    simde_uint32x4x2_t expected = {
        {simde_vld1q_u32(test_vec[i].r[0]), simde_vld1q_u32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u32x4(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u32x4(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint32_t buf[8];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint32x4x2_t r = simde_vld2q_u32(buf);

    simde_test_arm_neon_write_u32x4x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[4];
    uint64_t r[2][2];
  } test_vec[] = {
    { { UINT64_C( 3020762151839533812), UINT64_C(17954495856467081562),
        UINT64_C(14288482954718013222), UINT64_C( 3819020876812341264) },
        { { UINT64_C( 3020762151839533812), UINT64_C(14288482954718013222) },
          { UINT64_C(17954495856467081562), UINT64_C( 3819020876812341264) } },
    },
    { { UINT64_C(10899347977887241965), UINT64_C( 9840223772233446588),
        UINT64_C(12950102532167286886), UINT64_C(13530663546384542545) },
        { { UINT64_C(10899347977887241965), UINT64_C(12950102532167286886) },
          { UINT64_C( 9840223772233446588), UINT64_C(13530663546384542545) } },
    },
    { { UINT64_C( 2070555630402543080), UINT64_C(17741159496252854347),
        UINT64_C( 4492799045846756354), UINT64_C( 7500346603649101196) },
        { { UINT64_C( 2070555630402543080), UINT64_C( 4492799045846756354) },
          { UINT64_C(17741159496252854347), UINT64_C( 7500346603649101196) } },
    },
    { { UINT64_C( 5489969314248125107), UINT64_C( 2945686371667927898),
        UINT64_C(17745633243074316570), UINT64_C( 6772400822477133076) },
        { { UINT64_C( 5489969314248125107), UINT64_C(17745633243074316570) },
          { UINT64_C( 2945686371667927898), UINT64_C( 6772400822477133076) } },
    },
    { { UINT64_C( 3359581776035023185), UINT64_C(16272061564597082244),
        UINT64_C(15790516151494746051), UINT64_C( 3119705754931524419) },
        { { UINT64_C( 3359581776035023185), UINT64_C(15790516151494746051) },
          { UINT64_C(16272061564597082244), UINT64_C( 3119705754931524419) } },
    },
    { { UINT64_C(16282232691925826805), UINT64_C(14653969954052444085),
        UINT64_C(13303100541911975676), UINT64_C( 7968260244002705039) },
        { { UINT64_C(16282232691925826805), UINT64_C(13303100541911975676) },
          { UINT64_C(14653969954052444085), UINT64_C( 7968260244002705039) } },
    },
    { { UINT64_C(16423833091886748078), UINT64_C(15064748377732249660),
        UINT64_C(12911875263894391043), UINT64_C( 8586307070039217984) },
        { { UINT64_C(16423833091886748078), UINT64_C(12911875263894391043) },
          { UINT64_C(15064748377732249660), UINT64_C( 8586307070039217984) } },
    },
    { { UINT64_C(14543092476148932546), UINT64_C(17406166195061535465),
        UINT64_C(10808808801129014056), UINT64_C(10354190940655066225) },
        { { UINT64_C(14543092476148932546), UINT64_C(10808808801129014056) },
          { UINT64_C(17406166195061535465), UINT64_C(10354190940655066225) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x2_t r = simde_vld2q_u64(test_vec[i].a);

    simde_uint64x2x2_t expected = {
        {simde_vld1q_u64(test_vec[i].r[0]), simde_vld1q_u64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_u64x2(r.val[0], expected.val[0]);
    simde_test_arm_neon_assert_equal_u64x2(r.val[1], expected.val[1]);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint64_t buf[4];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_uint64x2x2_t r = simde_vld2q_u64(buf);

    simde_test_arm_neon_write_u64x2x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[8];
    simde_float32_t r[2][4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   793.71), SIMDE_FLOAT32_C(   221.62), SIMDE_FLOAT32_C(   781.57), SIMDE_FLOAT32_C(  -525.52),
        SIMDE_FLOAT32_C(   800.99), SIMDE_FLOAT32_C(  -411.87), SIMDE_FLOAT32_C(   483.99), SIMDE_FLOAT32_C(   852.73) },
        { { SIMDE_FLOAT32_C(   793.71), SIMDE_FLOAT32_C(   781.57), SIMDE_FLOAT32_C(   800.99), SIMDE_FLOAT32_C(   483.99) },
          { SIMDE_FLOAT32_C(   221.62), SIMDE_FLOAT32_C(  -525.52), SIMDE_FLOAT32_C(  -411.87), SIMDE_FLOAT32_C(   852.73) } },
    },
    { { SIMDE_FLOAT32_C(  -433.25), SIMDE_FLOAT32_C(  -811.76), SIMDE_FLOAT32_C(  -463.04), SIMDE_FLOAT32_C(   671.94),
        SIMDE_FLOAT32_C(   -60.94), SIMDE_FLOAT32_C(  -434.20), SIMDE_FLOAT32_C(  -263.89), SIMDE_FLOAT32_C(   754.63) },
        { { SIMDE_FLOAT32_C(  -433.25), SIMDE_FLOAT32_C(  -463.04), SIMDE_FLOAT32_C(   -60.94), SIMDE_FLOAT32_C(  -263.89) },
          { SIMDE_FLOAT32_C(  -811.76), SIMDE_FLOAT32_C(   671.94), SIMDE_FLOAT32_C(  -434.20), SIMDE_FLOAT32_C(   754.63) } },
    },
    { { SIMDE_FLOAT32_C(  -877.85), SIMDE_FLOAT32_C(  -225.98), SIMDE_FLOAT32_C(  -292.03), SIMDE_FLOAT32_C(   932.32),
        SIMDE_FLOAT32_C(  -463.10), SIMDE_FLOAT32_C(   171.18), SIMDE_FLOAT32_C(  -115.23), SIMDE_FLOAT32_C(  -867.52) },
        { { SIMDE_FLOAT32_C(  -877.85), SIMDE_FLOAT32_C(  -292.03), SIMDE_FLOAT32_C(  -463.10), SIMDE_FLOAT32_C(  -115.23) },
          { SIMDE_FLOAT32_C(  -225.98), SIMDE_FLOAT32_C(   932.32), SIMDE_FLOAT32_C(   171.18), SIMDE_FLOAT32_C(  -867.52) } },
    },
    { { SIMDE_FLOAT32_C(  -182.14), SIMDE_FLOAT32_C(   874.57), SIMDE_FLOAT32_C(  -306.44), SIMDE_FLOAT32_C(   180.87),
        SIMDE_FLOAT32_C(  -827.59), SIMDE_FLOAT32_C(  -449.53), SIMDE_FLOAT32_C(  -593.39), SIMDE_FLOAT32_C(   966.11) },
        { { SIMDE_FLOAT32_C(  -182.14), SIMDE_FLOAT32_C(  -306.44), SIMDE_FLOAT32_C(  -827.59), SIMDE_FLOAT32_C(  -593.39) },
          { SIMDE_FLOAT32_C(   874.57), SIMDE_FLOAT32_C(   180.87), SIMDE_FLOAT32_C(  -449.53), SIMDE_FLOAT32_C(   966.11) } },
    },
    { { SIMDE_FLOAT32_C(   772.09), SIMDE_FLOAT32_C(  -811.82), SIMDE_FLOAT32_C(  -559.40), SIMDE_FLOAT32_C(   573.08),
        SIMDE_FLOAT32_C(  -223.69), SIMDE_FLOAT32_C(   924.59), SIMDE_FLOAT32_C(   425.81), SIMDE_FLOAT32_C(   343.06) },
        { { SIMDE_FLOAT32_C(   772.09), SIMDE_FLOAT32_C(  -559.40), SIMDE_FLOAT32_C(  -223.69), SIMDE_FLOAT32_C(   425.81) },
          { SIMDE_FLOAT32_C(  -811.82), SIMDE_FLOAT32_C(   573.08), SIMDE_FLOAT32_C(   924.59), SIMDE_FLOAT32_C(   343.06) } },
    },
    { { SIMDE_FLOAT32_C(  -887.17), SIMDE_FLOAT32_C(   962.76), SIMDE_FLOAT32_C(    15.01), SIMDE_FLOAT32_C(    51.89),
        SIMDE_FLOAT32_C(  -471.44), SIMDE_FLOAT32_C(   751.11), SIMDE_FLOAT32_C(  -193.48), SIMDE_FLOAT32_C(  -349.29) },
        { { SIMDE_FLOAT32_C(  -887.17), SIMDE_FLOAT32_C(    15.01), SIMDE_FLOAT32_C(  -471.44), SIMDE_FLOAT32_C(  -193.48) },
          { SIMDE_FLOAT32_C(   962.76), SIMDE_FLOAT32_C(    51.89), SIMDE_FLOAT32_C(   751.11), SIMDE_FLOAT32_C(  -349.29) } },
    },
    { { SIMDE_FLOAT32_C(  -474.87), SIMDE_FLOAT32_C(   514.49), SIMDE_FLOAT32_C(  -416.97), SIMDE_FLOAT32_C(    62.03),
        SIMDE_FLOAT32_C(  -314.33), SIMDE_FLOAT32_C(   467.80), SIMDE_FLOAT32_C(   194.51), SIMDE_FLOAT32_C(   503.53) },
        { { SIMDE_FLOAT32_C(  -474.87), SIMDE_FLOAT32_C(  -416.97), SIMDE_FLOAT32_C(  -314.33), SIMDE_FLOAT32_C(   194.51) },
          { SIMDE_FLOAT32_C(   514.49), SIMDE_FLOAT32_C(    62.03), SIMDE_FLOAT32_C(   467.80), SIMDE_FLOAT32_C(   503.53) } },
    },
    { { SIMDE_FLOAT32_C(   342.37), SIMDE_FLOAT32_C(   888.07), SIMDE_FLOAT32_C(  -315.60), SIMDE_FLOAT32_C(   514.77),
        SIMDE_FLOAT32_C(  -561.46), SIMDE_FLOAT32_C(    91.01), SIMDE_FLOAT32_C(   480.89), SIMDE_FLOAT32_C(  -789.37) },
        { { SIMDE_FLOAT32_C(   342.37), SIMDE_FLOAT32_C(  -315.60), SIMDE_FLOAT32_C(  -561.46), SIMDE_FLOAT32_C(   480.89) },
          { SIMDE_FLOAT32_C(   888.07), SIMDE_FLOAT32_C(   514.77), SIMDE_FLOAT32_C(    91.01), SIMDE_FLOAT32_C(  -789.37) } },
    },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x2_t r = simde_vld2q_f32(test_vec[i].a);

    simde_float32x4x2_t expected = {
        {simde_vld1q_f32(test_vec[i].r[0]), simde_vld1q_f32(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f32x4(r.val[0], expected.val[0], INT_MAX);
    simde_test_arm_neon_assert_equal_f32x4(r.val[1], expected.val[1], INT_MAX);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    simde_float32_t buf[8];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_float32x4x2_t r = simde_vld2q_f32(buf);

    simde_test_arm_neon_write_f32x4x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vld2q_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[4];
    simde_float64_t r[2][2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -81.12), SIMDE_FLOAT64_C(   -90.46),
        SIMDE_FLOAT64_C(   -83.90), SIMDE_FLOAT64_C(    20.75) },
        { { SIMDE_FLOAT64_C(   -81.12), SIMDE_FLOAT64_C(   -83.90) },
          { SIMDE_FLOAT64_C(   -90.46), SIMDE_FLOAT64_C(    20.75) } },
    },
    { { SIMDE_FLOAT64_C(   -91.92), SIMDE_FLOAT64_C(     5.15),
        SIMDE_FLOAT64_C(   -58.53), SIMDE_FLOAT64_C(   -40.61) },
        { { SIMDE_FLOAT64_C(   -91.92), SIMDE_FLOAT64_C(   -58.53) },
          { SIMDE_FLOAT64_C(     5.15), SIMDE_FLOAT64_C(   -40.61) } },
    },
    { { SIMDE_FLOAT64_C(    92.56), SIMDE_FLOAT64_C(    91.44),
        SIMDE_FLOAT64_C(    67.84), SIMDE_FLOAT64_C(   -58.14) },
        { { SIMDE_FLOAT64_C(    92.56), SIMDE_FLOAT64_C(    67.84) },
          { SIMDE_FLOAT64_C(    91.44), SIMDE_FLOAT64_C(   -58.14) } },
    },
    { { SIMDE_FLOAT64_C(    63.47), SIMDE_FLOAT64_C(    42.43),
        SIMDE_FLOAT64_C(    29.58), SIMDE_FLOAT64_C(     4.03) },
        { { SIMDE_FLOAT64_C(    63.47), SIMDE_FLOAT64_C(    29.58) },
          { SIMDE_FLOAT64_C(    42.43), SIMDE_FLOAT64_C(     4.03) } },
    },
    { { SIMDE_FLOAT64_C(     0.29), SIMDE_FLOAT64_C(   -69.19),
        SIMDE_FLOAT64_C(   -73.56), SIMDE_FLOAT64_C(   -97.91) },
        { { SIMDE_FLOAT64_C(     0.29), SIMDE_FLOAT64_C(   -73.56) },
          { SIMDE_FLOAT64_C(   -69.19), SIMDE_FLOAT64_C(   -97.91) } },
    },
    { { SIMDE_FLOAT64_C(   -62.67), SIMDE_FLOAT64_C(   -66.03),
        SIMDE_FLOAT64_C(   -17.85), SIMDE_FLOAT64_C(   -62.88) },
        { { SIMDE_FLOAT64_C(   -62.67), SIMDE_FLOAT64_C(   -17.85) },
          { SIMDE_FLOAT64_C(   -66.03), SIMDE_FLOAT64_C(   -62.88) } },
    },
    { { SIMDE_FLOAT64_C(   -24.49), SIMDE_FLOAT64_C(   -93.09),
        SIMDE_FLOAT64_C(    12.23), SIMDE_FLOAT64_C(    80.71) },
        { { SIMDE_FLOAT64_C(   -24.49), SIMDE_FLOAT64_C(    12.23) },
          { SIMDE_FLOAT64_C(   -93.09), SIMDE_FLOAT64_C(    80.71) } },
    },
    { { SIMDE_FLOAT64_C(   -90.54), SIMDE_FLOAT64_C(    20.34),
        SIMDE_FLOAT64_C(   -11.66), SIMDE_FLOAT64_C(   -71.66) },
        { { SIMDE_FLOAT64_C(   -90.54), SIMDE_FLOAT64_C(   -11.66) },
          { SIMDE_FLOAT64_C(    20.34), SIMDE_FLOAT64_C(   -71.66) } },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x2_t r = simde_vld2q_f64(test_vec[i].a);

    simde_float64x2x2_t expected = {
        {simde_vld1q_f64(test_vec[i].r[0]), simde_vld1q_f64(test_vec[i].r[1])}};

    simde_test_arm_neon_assert_equal_f64x2(r.val[0], expected.val[0], 1);
    simde_test_arm_neon_assert_equal_f64x2(r.val[1], expected.val[1], 1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-100.0, 100.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-100.0, 100.0);
    simde_float64x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    simde_float64_t buf[4];
    simde_memcpy(buf, c.val, sizeof(buf));
    simde_float64x2x2_t r = simde_vld2q_f64(buf);

    simde_test_arm_neon_write_f64x2x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vld2q_f64)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
