#define SIMDE_TEST_ARM_NEON_INSN rev64

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/rev64.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

/* N.B. CM: vrev64_f16 and vrev64q_f16 are omitted as
 * SIMDe has no 16-bit floating point support. */

static int
test_simde_vrev64_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  46), -INT8_C(  72),  INT8_C(  77), -INT8_C(   5), -INT8_C(  73), -INT8_C(  68),  INT8_C(  74), -INT8_C(   6) },
      { -INT8_C(   6),  INT8_C(  74), -INT8_C(  68), -INT8_C(  73), -INT8_C(   5),  INT8_C(  77), -INT8_C(  72),  INT8_C(  46) } },
    { {  INT8_C(   2),  INT8_C(  96), -INT8_C(  44), -INT8_C( 111), -INT8_C( 115), -INT8_C(  69),  INT8_C(  42),  INT8_C(  51) },
      {  INT8_C(  51),  INT8_C(  42), -INT8_C(  69), -INT8_C( 115), -INT8_C( 111), -INT8_C(  44),  INT8_C(  96),  INT8_C(   2) } },
    { { -INT8_C(  53), -INT8_C( 119),  INT8_C(  78),  INT8_C(  93), -INT8_C(   2),  INT8_C(  73), -INT8_C(  56), -INT8_C( 100) },
      { -INT8_C( 100), -INT8_C(  56),  INT8_C(  73), -INT8_C(   2),  INT8_C(  93),  INT8_C(  78), -INT8_C( 119), -INT8_C(  53) } },
    { { -INT8_C(  71), -INT8_C(  26),  INT8_C(  64), -INT8_C(  41),  INT8_C(  59), -INT8_C(  30),  INT8_C(  14),  INT8_C( 106) },
      {  INT8_C( 106),  INT8_C(  14), -INT8_C(  30),  INT8_C(  59), -INT8_C(  41),  INT8_C(  64), -INT8_C(  26), -INT8_C(  71) } },
    { { -INT8_C( 102),  INT8_C(  91),  INT8_C( 101),  INT8_C(  81),  INT8_C(  23), -INT8_C(  81),  INT8_C(  76),  INT8_C(  25) },
      {  INT8_C(  25),  INT8_C(  76), -INT8_C(  81),  INT8_C(  23),  INT8_C(  81),  INT8_C( 101),  INT8_C(  91), -INT8_C( 102) } },
    { {  INT8_C(  15),  INT8_C(  32), -INT8_C(  86), -INT8_C( 100), -INT8_C(  37), -INT8_C(  43), -INT8_C(  49), -INT8_C(  90) },
      { -INT8_C(  90), -INT8_C(  49), -INT8_C(  43), -INT8_C(  37), -INT8_C( 100), -INT8_C(  86),  INT8_C(  32),  INT8_C(  15) } },
    { {  INT8_C(  94),  INT8_C(  30),  INT8_C(   3),  INT8_C(  92),  INT8_C( 103), -INT8_C(  53), -INT8_C(   8),  INT8_C(  32) },
      {  INT8_C(  32), -INT8_C(   8), -INT8_C(  53),  INT8_C( 103),  INT8_C(  92),  INT8_C(   3),  INT8_C(  30),  INT8_C(  94) } },
    { { -INT8_C(  79),  INT8_C(  56), -INT8_C(   8), -INT8_C(  19),  INT8_C(  26),  INT8_C(   6),  INT8_C(  87), -INT8_C(  76) },
      { -INT8_C(  76),  INT8_C(  87),  INT8_C(   6),  INT8_C(  26), -INT8_C(  19), -INT8_C(   8),  INT8_C(  56), -INT8_C(  79) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vrev64_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vrev64_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 11185), -INT16_C(  7304), -INT16_C(  8734), -INT16_C( 11770) },
      { -INT16_C( 11770), -INT16_C(  8734), -INT16_C(  7304),  INT16_C( 11185) } },
    { { -INT16_C( 21481), -INT16_C( 25761), -INT16_C(  1527), -INT16_C( 18865) },
      { -INT16_C( 18865), -INT16_C(  1527), -INT16_C( 25761), -INT16_C( 21481) } },
    { {  INT16_C(   888), -INT16_C(  6773), -INT16_C(  5383), -INT16_C(  7968) },
      { -INT16_C(  7968), -INT16_C(  5383), -INT16_C(  6773),  INT16_C(   888) } },
    { {  INT16_C(  2067), -INT16_C( 23157),  INT16_C( 20660),  INT16_C( 26010) },
      {  INT16_C( 26010),  INT16_C( 20660), -INT16_C( 23157),  INT16_C(  2067) } },
    { {  INT16_C(  4731),  INT16_C( 24136),  INT16_C( 20207),  INT16_C(  1584) },
      {  INT16_C(  1584),  INT16_C( 20207),  INT16_C( 24136),  INT16_C(  4731) } },
    { { -INT16_C( 28678),  INT16_C(  1185), -INT16_C(  3959),  INT16_C(   442) },
      {  INT16_C(   442), -INT16_C(  3959),  INT16_C(  1185), -INT16_C( 28678) } },
    { {  INT16_C( 18163), -INT16_C(  4890), -INT16_C( 14800),  INT16_C( 17356) },
      {  INT16_C( 17356), -INT16_C( 14800), -INT16_C(  4890),  INT16_C( 18163) } },
    { {  INT16_C( 22478), -INT16_C( 32023), -INT16_C( 31832),  INT16_C(  9191) },
      {  INT16_C(  9191), -INT16_C( 31832), -INT16_C( 32023),  INT16_C( 22478) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vrev64_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vrev64_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1284480829),  INT32_C(  1659778769) },
      {  INT32_C(  1659778769), -INT32_C(  1284480829) } },
    { { -INT32_C(  1499471149), -INT32_C(   866681537) },
      { -INT32_C(   866681537), -INT32_C(  1499471149) } },
    { { -INT32_C(  1697484102),  INT32_C(   526077331) },
      {  INT32_C(   526077331), -INT32_C(  1697484102) } },
    { {  INT32_C(   184553202),  INT32_C(  1331616140) },
      {  INT32_C(  1331616140),  INT32_C(   184553202) } },
    { {  INT32_C(   184798777), -INT32_C(   663883516) },
      { -INT32_C(   663883516),  INT32_C(   184798777) } },
    { {  INT32_C(   310250707),  INT32_C(  1138742665) },
      {  INT32_C(  1138742665),  INT32_C(   310250707) } },
    { { -INT32_C(   623005369), -INT32_C(   235324929) },
      { -INT32_C(   235324929), -INT32_C(   623005369) } },
    { { -INT32_C(   738395833),  INT32_C(   203643602) },
      {  INT32_C(   203643602), -INT32_C(   738395833) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t r = simde_vrev64_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vrev64_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(179), UINT8_C(177), UINT8_C(132), UINT8_C(204), UINT8_C( 13), UINT8_C( 33), UINT8_C(173), UINT8_C(243) },
      { UINT8_C(243), UINT8_C(173), UINT8_C( 33), UINT8_C( 13), UINT8_C(204), UINT8_C(132), UINT8_C(177), UINT8_C(179) } },
    { { UINT8_C(192), UINT8_C(222), UINT8_C( 23), UINT8_C( 78), UINT8_C( 87), UINT8_C( 89), UINT8_C(198), UINT8_C(132) },
      { UINT8_C(132), UINT8_C(198), UINT8_C( 89), UINT8_C( 87), UINT8_C( 78), UINT8_C( 23), UINT8_C(222), UINT8_C(192) } },
    { { UINT8_C(236), UINT8_C(188), UINT8_C( 92), UINT8_C(104), UINT8_C(146), UINT8_C(132), UINT8_C(149), UINT8_C( 72) },
      { UINT8_C( 72), UINT8_C(149), UINT8_C(132), UINT8_C(146), UINT8_C(104), UINT8_C( 92), UINT8_C(188), UINT8_C(236) } },
    { { UINT8_C( 23), UINT8_C( 76), UINT8_C(240), UINT8_C( 20), UINT8_C(135), UINT8_C(245), UINT8_C(178), UINT8_C( 58) },
      { UINT8_C( 58), UINT8_C(178), UINT8_C(245), UINT8_C(135), UINT8_C( 20), UINT8_C(240), UINT8_C( 76), UINT8_C( 23) } },
    { { UINT8_C(166), UINT8_C( 55), UINT8_C(  6), UINT8_C(179), UINT8_C( 88), UINT8_C(180), UINT8_C(166), UINT8_C( 24) },
      { UINT8_C( 24), UINT8_C(166), UINT8_C(180), UINT8_C( 88), UINT8_C(179), UINT8_C(  6), UINT8_C( 55), UINT8_C(166) } },
    { { UINT8_C(146), UINT8_C(189), UINT8_C(102), UINT8_C(233), UINT8_C( 23), UINT8_C( 45), UINT8_C(109), UINT8_C(  3) },
      { UINT8_C(  3), UINT8_C(109), UINT8_C( 45), UINT8_C( 23), UINT8_C(233), UINT8_C(102), UINT8_C(189), UINT8_C(146) } },
    { { UINT8_C(233), UINT8_C(202), UINT8_C(107), UINT8_C(124), UINT8_C( 78), UINT8_C(  1), UINT8_C(196), UINT8_C(101) },
      { UINT8_C(101), UINT8_C(196), UINT8_C(  1), UINT8_C( 78), UINT8_C(124), UINT8_C(107), UINT8_C(202), UINT8_C(233) } },
    { { UINT8_C( 77), UINT8_C(180), UINT8_C(121), UINT8_C(212), UINT8_C(170), UINT8_C( 44), UINT8_C( 15), UINT8_C( 80) },
      { UINT8_C( 80), UINT8_C( 15), UINT8_C( 44), UINT8_C(170), UINT8_C(212), UINT8_C(121), UINT8_C(180), UINT8_C( 77) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t r = simde_vrev64_u8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vrev64_u8(a);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(59270), UINT16_C(33972), UINT16_C(12613), UINT16_C(  118) },
      { UINT16_C(  118), UINT16_C(12613), UINT16_C(33972), UINT16_C(59270) } },
    { { UINT16_C(52123), UINT16_C( 9798), UINT16_C(57227), UINT16_C(52269) },
      { UINT16_C(52269), UINT16_C(57227), UINT16_C( 9798), UINT16_C(52123) } },
    { { UINT16_C(32029), UINT16_C( 8590), UINT16_C(40992), UINT16_C(60985) },
      { UINT16_C(60985), UINT16_C(40992), UINT16_C( 8590), UINT16_C(32029) } },
    { { UINT16_C(60666), UINT16_C(13202), UINT16_C(21293), UINT16_C(46056) },
      { UINT16_C(46056), UINT16_C(21293), UINT16_C(13202), UINT16_C(60666) } },
    { { UINT16_C(39995), UINT16_C(32824), UINT16_C(44750), UINT16_C(27008) },
      { UINT16_C(27008), UINT16_C(44750), UINT16_C(32824), UINT16_C(39995) } },
    { { UINT16_C(51065), UINT16_C( 1167), UINT16_C(48294), UINT16_C(50129) },
      { UINT16_C(50129), UINT16_C(48294), UINT16_C( 1167), UINT16_C(51065) } },
    { { UINT16_C(24377), UINT16_C(23012), UINT16_C( 7679), UINT16_C(63815) },
      { UINT16_C(63815), UINT16_C( 7679), UINT16_C(23012), UINT16_C(24377) } },
    { { UINT16_C(55562), UINT16_C(14124), UINT16_C( 5165), UINT16_C(26858) },
      { UINT16_C(26858), UINT16_C( 5165), UINT16_C(14124), UINT16_C(55562) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t r = simde_vrev64_u16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vrev64_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2730879067), UINT32_C(2920167489) },
      { UINT32_C(2920167489), UINT32_C(2730879067) } },
    { { UINT32_C(1333580779), UINT32_C(3300500620) },
      { UINT32_C(3300500620), UINT32_C(1333580779) } },
    { { UINT32_C(1377871977), UINT32_C( 894461476) },
      { UINT32_C( 894461476), UINT32_C(1377871977) } },
    { { UINT32_C( 948007493), UINT32_C( 539389893) },
      { UINT32_C( 539389893), UINT32_C( 948007493) } },
    { { UINT32_C(2579688280), UINT32_C( 239587619) },
      { UINT32_C( 239587619), UINT32_C(2579688280) } },
    { { UINT32_C( 811516836), UINT32_C(3522434920) },
      { UINT32_C(3522434920), UINT32_C( 811516836) } },
    { { UINT32_C(3827504319), UINT32_C(3222893434) },
      { UINT32_C(3222893434), UINT32_C(3827504319) } },
    { { UINT32_C(2868419301), UINT32_C(1657413130) },
      { UINT32_C(1657413130), UINT32_C(2868419301) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t r = simde_vrev64_u32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vrev64_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   197.38), SIMDE_FLOAT32_C(  -984.96) },
      { SIMDE_FLOAT32_C(  -984.96), SIMDE_FLOAT32_C(   197.38) } },
    { { SIMDE_FLOAT32_C(   987.38), SIMDE_FLOAT32_C(   664.23) },
      { SIMDE_FLOAT32_C(   664.23), SIMDE_FLOAT32_C(   987.38) } },
    { { SIMDE_FLOAT32_C(   830.72), SIMDE_FLOAT32_C(  -164.98) },
      { SIMDE_FLOAT32_C(  -164.98), SIMDE_FLOAT32_C(   830.72) } },
    { { SIMDE_FLOAT32_C(   120.71), SIMDE_FLOAT32_C(  -223.00) },
      { SIMDE_FLOAT32_C(  -223.00), SIMDE_FLOAT32_C(   120.71) } },
    { { SIMDE_FLOAT32_C(   907.59), SIMDE_FLOAT32_C(     9.60) },
      { SIMDE_FLOAT32_C(     9.60), SIMDE_FLOAT32_C(   907.59) } },
    { { SIMDE_FLOAT32_C(   135.79), SIMDE_FLOAT32_C(   135.93) },
      { SIMDE_FLOAT32_C(   135.93), SIMDE_FLOAT32_C(   135.79) } },
    { { SIMDE_FLOAT32_C(  -918.57), SIMDE_FLOAT32_C(  -483.52) },
      { SIMDE_FLOAT32_C(  -483.52), SIMDE_FLOAT32_C(  -918.57) } },
    { { SIMDE_FLOAT32_C(  -308.42), SIMDE_FLOAT32_C(   475.73) },
      { SIMDE_FLOAT32_C(   475.73), SIMDE_FLOAT32_C(  -308.42) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t r = simde_vrev64_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vrev64_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  49), -INT8_C( 126), -INT8_C(  30),  INT8_C( 122), -INT8_C( 110), -INT8_C( 111), -INT8_C(  19), -INT8_C(   6),
         INT8_C(  95), -INT8_C(  73),  INT8_C(   6),  INT8_C(  16), -INT8_C(  77), -INT8_C(  18),  INT8_C(  99),  INT8_C(  24) },
      { -INT8_C(   6), -INT8_C(  19), -INT8_C( 111), -INT8_C( 110),  INT8_C( 122), -INT8_C(  30), -INT8_C( 126), -INT8_C(  49),
         INT8_C(  24),  INT8_C(  99), -INT8_C(  18), -INT8_C(  77),  INT8_C(  16),  INT8_C(   6), -INT8_C(  73),  INT8_C(  95) } },
    { { -INT8_C(  97),  INT8_C(  39), -INT8_C(  14), -INT8_C(   4), -INT8_C(  33),  INT8_C(  56), -INT8_C(  96),  INT8_C( 103),
        -INT8_C( 120), -INT8_C( 111),  INT8_C(  13), -INT8_C(  29), -INT8_C(  62), -INT8_C( 117),  INT8_C(  80), -INT8_C( 110) },
      {  INT8_C( 103), -INT8_C(  96),  INT8_C(  56), -INT8_C(  33), -INT8_C(   4), -INT8_C(  14),  INT8_C(  39), -INT8_C(  97),
        -INT8_C( 110),  INT8_C(  80), -INT8_C( 117), -INT8_C(  62), -INT8_C(  29),  INT8_C(  13), -INT8_C( 111), -INT8_C( 120) } },
    { {  INT8_C(  14),  INT8_C(  51),  INT8_C(  12), -INT8_C(  96), -INT8_C(  60), -INT8_C(   6), -INT8_C( 101),  INT8_C(  35),
        -INT8_C(  79), -INT8_C(  95),  INT8_C(  52),  INT8_C( 101), -INT8_C( 112), -INT8_C( 105),  INT8_C( 125),  INT8_C(  47) },
      {  INT8_C(  35), -INT8_C( 101), -INT8_C(   6), -INT8_C(  60), -INT8_C(  96),  INT8_C(  12),  INT8_C(  51),  INT8_C(  14),
         INT8_C(  47),  INT8_C( 125), -INT8_C( 105), -INT8_C( 112),  INT8_C( 101),  INT8_C(  52), -INT8_C(  95), -INT8_C(  79) } },
    { { -INT8_C(  65),  INT8_C( 111),  INT8_C(  43), -INT8_C(  98), -INT8_C(  89), -INT8_C(  53),  INT8_C(   5),  INT8_C(  47),
         INT8_C(  92),  INT8_C(  19),  INT8_C(  19),  INT8_C(  31), -INT8_C(  98),  INT8_C(  99), -INT8_C(  79), -INT8_C(  84) },
      {  INT8_C(  47),  INT8_C(   5), -INT8_C(  53), -INT8_C(  89), -INT8_C(  98),  INT8_C(  43),  INT8_C( 111), -INT8_C(  65),
        -INT8_C(  84), -INT8_C(  79),  INT8_C(  99), -INT8_C(  98),  INT8_C(  31),  INT8_C(  19),  INT8_C(  19),  INT8_C(  92) } },
    { { -INT8_C( 106), -INT8_C(  67),  INT8_C(  77),  INT8_C(  90), -INT8_C(  73), -INT8_C(  24),  INT8_C( 126),  INT8_C( 105),
        -INT8_C( 119), -INT8_C(  78), -INT8_C(  50),  INT8_C(  25),  INT8_C(  73),  INT8_C(  75),  INT8_C(  73),  INT8_C(   8) },
      {  INT8_C( 105),  INT8_C( 126), -INT8_C(  24), -INT8_C(  73),  INT8_C(  90),  INT8_C(  77), -INT8_C(  67), -INT8_C( 106),
         INT8_C(   8),  INT8_C(  73),  INT8_C(  75),  INT8_C(  73),  INT8_C(  25), -INT8_C(  50), -INT8_C(  78), -INT8_C( 119) } },
    { { -INT8_C(  70),  INT8_C( 116), -INT8_C(  89),  INT8_C(  98),  INT8_C(  64), -INT8_C(  84), -INT8_C( 111), -INT8_C( 100),
        -INT8_C(  65), -INT8_C(  92), -INT8_C(  69),  INT8_C(  94),  INT8_C(   8),  INT8_C( 108),  INT8_C(  10), -INT8_C(  98) },
      { -INT8_C( 100), -INT8_C( 111), -INT8_C(  84),  INT8_C(  64),  INT8_C(  98), -INT8_C(  89),  INT8_C( 116), -INT8_C(  70),
        -INT8_C(  98),  INT8_C(  10),  INT8_C( 108),  INT8_C(   8),  INT8_C(  94), -INT8_C(  69), -INT8_C(  92), -INT8_C(  65) } },
    { {  INT8_C(  42),  INT8_C(  87), -INT8_C(   7), -INT8_C(  31),  INT8_C(  63),  INT8_C( 119),  INT8_C(  74), -INT8_C(  55),
         INT8_C(  41),  INT8_C(  24), -INT8_C(  30),  INT8_C( 114),  INT8_C(  99),  INT8_C(  43),  INT8_C( 123),  INT8_C(  30) },
      { -INT8_C(  55),  INT8_C(  74),  INT8_C( 119),  INT8_C(  63), -INT8_C(  31), -INT8_C(   7),  INT8_C(  87),  INT8_C(  42),
         INT8_C(  30),  INT8_C( 123),  INT8_C(  43),  INT8_C(  99),  INT8_C( 114), -INT8_C(  30),  INT8_C(  24),  INT8_C(  41) } },
    { { -INT8_C(  96),  INT8_C(  34),      INT8_MIN, -INT8_C(  32), -INT8_C(  50),  INT8_C(  17),  INT8_C( 124), -INT8_C( 114),
        -INT8_C(  74),  INT8_C(  56), -INT8_C(  20), -INT8_C(  66), -INT8_C(  92), -INT8_C(  10),  INT8_C(  92), -INT8_C(  50) },
      { -INT8_C( 114),  INT8_C( 124),  INT8_C(  17), -INT8_C(  50), -INT8_C(  32),      INT8_MIN,  INT8_C(  34), -INT8_C(  96),
        -INT8_C(  50),  INT8_C(  92), -INT8_C(  10), -INT8_C(  92), -INT8_C(  66), -INT8_C(  20),  INT8_C(  56), -INT8_C(  74) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t r = simde_vrev64q_s8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vrev64q_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 16499),  INT16_C( 32260), -INT16_C( 29870), -INT16_C( 22736), -INT16_C(   710),  INT16_C( 16837), -INT16_C(  2834),  INT16_C( 26044) },
      { -INT16_C( 22736), -INT16_C( 29870),  INT16_C( 32260),  INT16_C( 16499),  INT16_C( 26044), -INT16_C(  2834),  INT16_C( 16837), -INT16_C(   710) } },
    { { -INT16_C(   174), -INT16_C( 25727), -INT16_C( 30182), -INT16_C( 26510), -INT16_C(  1989), -INT16_C(  2810),  INT16_C(  5206), -INT16_C( 13657) },
      { -INT16_C( 26510), -INT16_C( 30182), -INT16_C( 25727), -INT16_C(   174), -INT16_C( 13657),  INT16_C(  5206), -INT16_C(  2810), -INT16_C(  1989) } },
    { { -INT16_C( 21676), -INT16_C( 22712),  INT16_C( 30775),  INT16_C( 29006),  INT16_C(  5237),  INT16_C( 25779),  INT16_C( 28424),  INT16_C( 23241) },
      {  INT16_C( 29006),  INT16_C( 30775), -INT16_C( 22712), -INT16_C( 21676),  INT16_C( 23241),  INT16_C( 28424),  INT16_C( 25779),  INT16_C(  5237) } },
    { {  INT16_C( 19311), -INT16_C( 30219),  INT16_C( 26581),  INT16_C(  4385),  INT16_C( 10336), -INT16_C( 18938), -INT16_C( 21188), -INT16_C( 28288) },
      {  INT16_C(  4385),  INT16_C( 26581), -INT16_C( 30219),  INT16_C( 19311), -INT16_C( 28288), -INT16_C( 21188), -INT16_C( 18938),  INT16_C( 10336) } },
    { { -INT16_C( 14247), -INT16_C( 28616), -INT16_C( 31168), -INT16_C( 18943), -INT16_C( 19302), -INT16_C( 23782), -INT16_C(  7388), -INT16_C( 27651) },
      { -INT16_C( 18943), -INT16_C( 31168), -INT16_C( 28616), -INT16_C( 14247), -INT16_C( 27651), -INT16_C(  7388), -INT16_C( 23782), -INT16_C( 19302) } },
    { { -INT16_C(  3282),  INT16_C(  1052),  INT16_C( 15706), -INT16_C( 17899),  INT16_C(  7013), -INT16_C( 23951), -INT16_C(  3639),  INT16_C(  8755) },
      { -INT16_C( 17899),  INT16_C( 15706),  INT16_C(  1052), -INT16_C(  3282),  INT16_C(  8755), -INT16_C(  3639), -INT16_C( 23951),  INT16_C(  7013) } },
    { {  INT16_C( 27578), -INT16_C(  1358), -INT16_C( 19471), -INT16_C( 29520), -INT16_C( 13720), -INT16_C( 29649),  INT16_C( 11438), -INT16_C(  9185) },
      { -INT16_C( 29520), -INT16_C( 19471), -INT16_C(  1358),  INT16_C( 27578), -INT16_C(  9185),  INT16_C( 11438), -INT16_C( 29649), -INT16_C( 13720) } },
    { {  INT16_C( 15135),  INT16_C( 31456), -INT16_C(  2696), -INT16_C(  8652), -INT16_C( 23279), -INT16_C(  9600), -INT16_C( 19561),  INT16_C( 20988) },
      { -INT16_C(  8652), -INT16_C(  2696),  INT16_C( 31456),  INT16_C( 15135),  INT16_C( 20988), -INT16_C( 19561), -INT16_C(  9600), -INT16_C( 23279) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t r = simde_vrev64q_s16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vrev64q_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64q_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   853077418), -INT32_C(  1621561868), -INT32_C(   976200669),  INT32_C(  1316530513) },
      { -INT32_C(  1621561868),  INT32_C(   853077418),  INT32_C(  1316530513), -INT32_C(   976200669) } },
    { {  INT32_C(  1223214716),  INT32_C(  1719530838), -INT32_C(  1485267583),  INT32_C(  1261568161) },
      {  INT32_C(  1719530838),  INT32_C(  1223214716),  INT32_C(  1261568161), -INT32_C(  1485267583) } },
    { { -INT32_C(   495055891),  INT32_C(   461494008), -INT32_C(  2082451150),  INT32_C(  1993431546) },
      {  INT32_C(   461494008), -INT32_C(   495055891),  INT32_C(  1993431546), -INT32_C(  2082451150) } },
    { {  INT32_C(  1992276255),  INT32_C(   819739823),  INT32_C(  2077709529),  INT32_C(  1103497556) },
      {  INT32_C(   819739823),  INT32_C(  1992276255),  INT32_C(  1103497556),  INT32_C(  2077709529) } },
    { {  INT32_C(   203637780),  INT32_C(  1277666330), -INT32_C(   254867210), -INT32_C(  2140692383) },
      {  INT32_C(  1277666330),  INT32_C(   203637780), -INT32_C(  2140692383), -INT32_C(   254867210) } },
    { {  INT32_C(   167126618),  INT32_C(  1010422370),  INT32_C(  2058817574),  INT32_C(   784104729) },
      {  INT32_C(  1010422370),  INT32_C(   167126618),  INT32_C(   784104729),  INT32_C(  2058817574) } },
    { { -INT32_C(   600121406),  INT32_C(  2049532548), -INT32_C(   882182038), -INT32_C(   213134951) },
      {  INT32_C(  2049532548), -INT32_C(   600121406), -INT32_C(   213134951), -INT32_C(   882182038) } },
    { {  INT32_C(  1526481655),  INT32_C(   999699732),  INT32_C(  1588940101), -INT32_C(  1936952886) },
      {  INT32_C(   999699732),  INT32_C(  1526481655), -INT32_C(  1936952886),  INT32_C(  1588940101) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t r = simde_vrev64q_s32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vrev64q_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(105), UINT8_C( 82), UINT8_C(  6), UINT8_C(116), UINT8_C( 54), UINT8_C(104), UINT8_C(  1), UINT8_C( 54),
        UINT8_C(215), UINT8_C(206), UINT8_C( 89), UINT8_C(218), UINT8_C( 41), UINT8_C(170), UINT8_C( 21), UINT8_C(195) },
      { UINT8_C( 54), UINT8_C(  1), UINT8_C(104), UINT8_C( 54), UINT8_C(116), UINT8_C(  6), UINT8_C( 82), UINT8_C(105),
        UINT8_C(195), UINT8_C( 21), UINT8_C(170), UINT8_C( 41), UINT8_C(218), UINT8_C( 89), UINT8_C(206), UINT8_C(215) } },
    { { UINT8_C( 19), UINT8_C(118), UINT8_C(243), UINT8_C( 49), UINT8_C(101), UINT8_C( 80), UINT8_C( 91), UINT8_C(134),
        UINT8_C( 54), UINT8_C(199), UINT8_C(158), UINT8_C( 68), UINT8_C(237), UINT8_C(174), UINT8_C(137), UINT8_C( 87) },
      { UINT8_C(134), UINT8_C( 91), UINT8_C( 80), UINT8_C(101), UINT8_C( 49), UINT8_C(243), UINT8_C(118), UINT8_C( 19),
        UINT8_C( 87), UINT8_C(137), UINT8_C(174), UINT8_C(237), UINT8_C( 68), UINT8_C(158), UINT8_C(199), UINT8_C( 54) } },
    { { UINT8_C(  1), UINT8_C(143), UINT8_C(203), UINT8_C( 55), UINT8_C(248), UINT8_C(204), UINT8_C(109), UINT8_C(207),
        UINT8_C(155), UINT8_C(198), UINT8_C(169), UINT8_C(196), UINT8_C(112), UINT8_C(191), UINT8_C(136), UINT8_C(131) },
      { UINT8_C(207), UINT8_C(109), UINT8_C(204), UINT8_C(248), UINT8_C( 55), UINT8_C(203), UINT8_C(143), UINT8_C(  1),
        UINT8_C(131), UINT8_C(136), UINT8_C(191), UINT8_C(112), UINT8_C(196), UINT8_C(169), UINT8_C(198), UINT8_C(155) } },
    { { UINT8_C( 53), UINT8_C(123), UINT8_C(181), UINT8_C(154), UINT8_C(203), UINT8_C( 16), UINT8_C( 32), UINT8_C(  1),
        UINT8_C(215), UINT8_C(190), UINT8_C( 69), UINT8_C(197), UINT8_C(109), UINT8_C(206), UINT8_C( 28), UINT8_C(110) },
      { UINT8_C(  1), UINT8_C( 32), UINT8_C( 16), UINT8_C(203), UINT8_C(154), UINT8_C(181), UINT8_C(123), UINT8_C( 53),
        UINT8_C(110), UINT8_C( 28), UINT8_C(206), UINT8_C(109), UINT8_C(197), UINT8_C( 69), UINT8_C(190), UINT8_C(215) } },
    { { UINT8_C( 94), UINT8_C(231), UINT8_C(165), UINT8_C( 86), UINT8_C(180), UINT8_C( 19), UINT8_C( 37), UINT8_C( 79),
        UINT8_C(217), UINT8_C(207), UINT8_C( 19), UINT8_C( 74), UINT8_C(142), UINT8_C(155), UINT8_C(205), UINT8_C(195) },
      { UINT8_C( 79), UINT8_C( 37), UINT8_C( 19), UINT8_C(180), UINT8_C( 86), UINT8_C(165), UINT8_C(231), UINT8_C( 94),
        UINT8_C(195), UINT8_C(205), UINT8_C(155), UINT8_C(142), UINT8_C( 74), UINT8_C( 19), UINT8_C(207), UINT8_C(217) } },
    { { UINT8_C( 22), UINT8_C(130), UINT8_C( 93), UINT8_C(225), UINT8_C(146), UINT8_C(125), UINT8_C(226), UINT8_C(106),
        UINT8_C( 60), UINT8_C( 40), UINT8_C( 47), UINT8_C(169), UINT8_C(246), UINT8_C( 75), UINT8_C( 23), UINT8_C( 84) },
      { UINT8_C(106), UINT8_C(226), UINT8_C(125), UINT8_C(146), UINT8_C(225), UINT8_C( 93), UINT8_C(130), UINT8_C( 22),
        UINT8_C( 84), UINT8_C( 23), UINT8_C( 75), UINT8_C(246), UINT8_C(169), UINT8_C( 47), UINT8_C( 40), UINT8_C( 60) } },
    { { UINT8_C( 50), UINT8_C(188), UINT8_C(170), UINT8_C(230), UINT8_C(207), UINT8_C(208), UINT8_C( 53), UINT8_C(169),
        UINT8_C(159), UINT8_C( 73), UINT8_C(243), UINT8_C( 45), UINT8_C(228), UINT8_C(192), UINT8_C(240), UINT8_C(251) },
      { UINT8_C(169), UINT8_C( 53), UINT8_C(208), UINT8_C(207), UINT8_C(230), UINT8_C(170), UINT8_C(188), UINT8_C( 50),
        UINT8_C(251), UINT8_C(240), UINT8_C(192), UINT8_C(228), UINT8_C( 45), UINT8_C(243), UINT8_C( 73), UINT8_C(159) } },
    { { UINT8_C( 67), UINT8_C( 77), UINT8_C(220), UINT8_C(213), UINT8_C(202), UINT8_C(191), UINT8_C( 63), UINT8_C(  6),
        UINT8_C(231), UINT8_C(110), UINT8_C(175), UINT8_C(221), UINT8_C(185), UINT8_C(198), UINT8_C( 50), UINT8_C(236) },
      { UINT8_C(  6), UINT8_C( 63), UINT8_C(191), UINT8_C(202), UINT8_C(213), UINT8_C(220), UINT8_C( 77), UINT8_C( 67),
        UINT8_C(236), UINT8_C( 50), UINT8_C(198), UINT8_C(185), UINT8_C(221), UINT8_C(175), UINT8_C(110), UINT8_C(231) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t r = simde_vrev64q_u8(a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vrev64q_u8(a);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(23729), UINT16_C(35203), UINT16_C(54806), UINT16_C(21539), UINT16_C(50954), UINT16_C(24064), UINT16_C(21898), UINT16_C(26296) },
      { UINT16_C(21539), UINT16_C(54806), UINT16_C(35203), UINT16_C(23729), UINT16_C(26296), UINT16_C(21898), UINT16_C(24064), UINT16_C(50954) } },
    { { UINT16_C(49935), UINT16_C(59261), UINT16_C(59617), UINT16_C(46782), UINT16_C(57390), UINT16_C(44550), UINT16_C(19947), UINT16_C(40107) },
      { UINT16_C(46782), UINT16_C(59617), UINT16_C(59261), UINT16_C(49935), UINT16_C(40107), UINT16_C(19947), UINT16_C(44550), UINT16_C(57390) } },
    { { UINT16_C(11946), UINT16_C(49189), UINT16_C(18436), UINT16_C( 3860), UINT16_C( 5136), UINT16_C(39533), UINT16_C( 9577), UINT16_C(30977) },
      { UINT16_C( 3860), UINT16_C(18436), UINT16_C(49189), UINT16_C(11946), UINT16_C(30977), UINT16_C( 9577), UINT16_C(39533), UINT16_C( 5136) } },
    { { UINT16_C(32488), UINT16_C(51552), UINT16_C( 7783), UINT16_C(38271), UINT16_C(34558), UINT16_C(59716), UINT16_C(61395), UINT16_C(32133) },
      { UINT16_C(38271), UINT16_C( 7783), UINT16_C(51552), UINT16_C(32488), UINT16_C(32133), UINT16_C(61395), UINT16_C(59716), UINT16_C(34558) } },
    { { UINT16_C(43805), UINT16_C( 8509), UINT16_C(21235), UINT16_C(  816), UINT16_C(40294), UINT16_C(53406), UINT16_C(40898), UINT16_C(43593) },
      { UINT16_C(  816), UINT16_C(21235), UINT16_C( 8509), UINT16_C(43805), UINT16_C(43593), UINT16_C(40898), UINT16_C(53406), UINT16_C(40294) } },
    { { UINT16_C(43293), UINT16_C(33907), UINT16_C(62407), UINT16_C(50714), UINT16_C(24185), UINT16_C(19631), UINT16_C(13645), UINT16_C(27338) },
      { UINT16_C(50714), UINT16_C(62407), UINT16_C(33907), UINT16_C(43293), UINT16_C(27338), UINT16_C(13645), UINT16_C(19631), UINT16_C(24185) } },
    { { UINT16_C( 2016), UINT16_C(54155), UINT16_C(48217), UINT16_C(49367), UINT16_C(30041), UINT16_C( 7312), UINT16_C(55572), UINT16_C(12742) },
      { UINT16_C(49367), UINT16_C(48217), UINT16_C(54155), UINT16_C( 2016), UINT16_C(12742), UINT16_C(55572), UINT16_C( 7312), UINT16_C(30041) } },
    { { UINT16_C(14978), UINT16_C(18870), UINT16_C(53293), UINT16_C(42511), UINT16_C(48942), UINT16_C(31730), UINT16_C(48372), UINT16_C(54501) },
      { UINT16_C(42511), UINT16_C(53293), UINT16_C(18870), UINT16_C(14978), UINT16_C(54501), UINT16_C(48372), UINT16_C(31730), UINT16_C(48942) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t r = simde_vrev64q_u16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vrev64q_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1434993302), UINT32_C( 552597513), UINT32_C(1341026527), UINT32_C(1033003339) },
      { UINT32_C( 552597513), UINT32_C(1434993302), UINT32_C(1033003339), UINT32_C(1341026527) } },
    { { UINT32_C( 233765670), UINT32_C( 773899934), UINT32_C(1736511025), UINT32_C(3921435987) },
      { UINT32_C( 773899934), UINT32_C( 233765670), UINT32_C(3921435987), UINT32_C(1736511025) } },
    { { UINT32_C(2839495839), UINT32_C( 482946621), UINT32_C(3932993695), UINT32_C(1059651097) },
      { UINT32_C( 482946621), UINT32_C(2839495839), UINT32_C(1059651097), UINT32_C(3932993695) } },
    { { UINT32_C(2555123449), UINT32_C( 247885277), UINT32_C(3463792507), UINT32_C(1136144804) },
      { UINT32_C( 247885277), UINT32_C(2555123449), UINT32_C(1136144804), UINT32_C(3463792507) } },
    { { UINT32_C(3018651510), UINT32_C(3301946917), UINT32_C(2276408174), UINT32_C( 868669241) },
      { UINT32_C(3301946917), UINT32_C(3018651510), UINT32_C( 868669241), UINT32_C(2276408174) } },
    { { UINT32_C(3402306285), UINT32_C(4225274239), UINT32_C(2093567448), UINT32_C(4122968447) },
      { UINT32_C(4225274239), UINT32_C(3402306285), UINT32_C(4122968447), UINT32_C(2093567448) } },
    { { UINT32_C(2661854328), UINT32_C(3496114018), UINT32_C(3965129139), UINT32_C(3592363496) },
      { UINT32_C(3496114018), UINT32_C(2661854328), UINT32_C(3592363496), UINT32_C(3965129139) } },
    { { UINT32_C(2946558511), UINT32_C(1403681147), UINT32_C(1171223494), UINT32_C(1832554485) },
      { UINT32_C(1403681147), UINT32_C(2946558511), UINT32_C(1832554485), UINT32_C(1171223494) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t r = simde_vrev64q_u32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vrev64q_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrev64q_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -324.81), SIMDE_FLOAT32_C(  -870.47), SIMDE_FLOAT32_C(   342.98), SIMDE_FLOAT32_C(  -492.44) },
      { SIMDE_FLOAT32_C(  -870.47), SIMDE_FLOAT32_C(  -324.81), SIMDE_FLOAT32_C(  -492.44), SIMDE_FLOAT32_C(   342.98) } },
    { { SIMDE_FLOAT32_C(  -289.18), SIMDE_FLOAT32_C(  -318.73), SIMDE_FLOAT32_C(  -927.82), SIMDE_FLOAT32_C(   328.84) },
      { SIMDE_FLOAT32_C(  -318.73), SIMDE_FLOAT32_C(  -289.18), SIMDE_FLOAT32_C(   328.84), SIMDE_FLOAT32_C(  -927.82) } },
    { { SIMDE_FLOAT32_C(  -870.55), SIMDE_FLOAT32_C(  -305.56), SIMDE_FLOAT32_C(   -62.60), SIMDE_FLOAT32_C(  -509.92) },
      { SIMDE_FLOAT32_C(  -305.56), SIMDE_FLOAT32_C(  -870.55), SIMDE_FLOAT32_C(  -509.92), SIMDE_FLOAT32_C(   -62.60) } },
    { { SIMDE_FLOAT32_C(    55.68), SIMDE_FLOAT32_C(   856.66), SIMDE_FLOAT32_C(  -934.25), SIMDE_FLOAT32_C(   336.42) },
      { SIMDE_FLOAT32_C(   856.66), SIMDE_FLOAT32_C(    55.68), SIMDE_FLOAT32_C(   336.42), SIMDE_FLOAT32_C(  -934.25) } },
    { { SIMDE_FLOAT32_C(   501.43), SIMDE_FLOAT32_C(  -571.21), SIMDE_FLOAT32_C(  -251.52), SIMDE_FLOAT32_C(   672.13) },
      { SIMDE_FLOAT32_C(  -571.21), SIMDE_FLOAT32_C(   501.43), SIMDE_FLOAT32_C(   672.13), SIMDE_FLOAT32_C(  -251.52) } },
    { { SIMDE_FLOAT32_C(   844.20), SIMDE_FLOAT32_C(    87.76), SIMDE_FLOAT32_C(   609.29), SIMDE_FLOAT32_C(   856.58) },
      { SIMDE_FLOAT32_C(    87.76), SIMDE_FLOAT32_C(   844.20), SIMDE_FLOAT32_C(   856.58), SIMDE_FLOAT32_C(   609.29) } },
    { { SIMDE_FLOAT32_C(  -229.44), SIMDE_FLOAT32_C(  -640.32), SIMDE_FLOAT32_C(  -844.07), SIMDE_FLOAT32_C(   466.08) },
      { SIMDE_FLOAT32_C(  -640.32), SIMDE_FLOAT32_C(  -229.44), SIMDE_FLOAT32_C(   466.08), SIMDE_FLOAT32_C(  -844.07) } },
    { { SIMDE_FLOAT32_C(   517.84), SIMDE_FLOAT32_C(   101.16), SIMDE_FLOAT32_C(   322.38), SIMDE_FLOAT32_C(  -806.97) },
      { SIMDE_FLOAT32_C(   101.16), SIMDE_FLOAT32_C(   517.84), SIMDE_FLOAT32_C(  -806.97), SIMDE_FLOAT32_C(   322.38) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t r = simde_vrev64q_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vrev64q_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64_u32)
//SIMDE_TEST_FUNC_LIST_ENTRY(vrev64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vrev64q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64q_u32)
//SIMDE_TEST_FUNC_LIST_ENTRY(vrev64q_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrev64q_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
