#define SIMDE_TEST_ARM_NEON_INSN hsub

#include "test-neon.h"
#include "../../../simde/arm/neon/hsub.h"

static int
test_simde_vhsub_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  82),  INT8_C( 111),  INT8_C(  70), -INT8_C(  31), -INT8_C(  51), -INT8_C(  22),  INT8_C( 109),  INT8_C(  85) },
      {  INT8_C( 126),  INT8_C(  89),  INT8_C(  38),  INT8_C(  58), -INT8_C(  56),  INT8_C(  28),  INT8_C(  49), -INT8_C(  21) },
      { -INT8_C(  22),  INT8_C(  11),  INT8_C(  16), -INT8_C(  45),  INT8_C(   2), -INT8_C(  25),  INT8_C(  30),  INT8_C(  53) } },
    { { -INT8_C(  63), -INT8_C( 107), -INT8_C( 109), -INT8_C(  28),  INT8_C(  68),  INT8_C(  51),  INT8_C(  14), -INT8_C( 100) },
      {  INT8_C(  29),  INT8_C(  41), -INT8_C(  53), -INT8_C( 109), -INT8_C( 102),  INT8_C(  28),  INT8_C(  36), -INT8_C(  19) },
      { -INT8_C(  46), -INT8_C(  74), -INT8_C(  28),  INT8_C(  40),  INT8_C(  85),  INT8_C(  11), -INT8_C(  11), -INT8_C(  41) } },
    { { -INT8_C( 117),  INT8_C( 106), -INT8_C(  50),  INT8_C(  89),  INT8_C(  84),  INT8_C(  59), -INT8_C(  82), -INT8_C(  46) },
      { -INT8_C( 107), -INT8_C(  44),  INT8_C(  13),  INT8_C(  93), -INT8_C(  16),  INT8_C(  62),  INT8_C(  72), -INT8_C(  78) },
      { -INT8_C(   5),  INT8_C(  75), -INT8_C(  32), -INT8_C(   2),  INT8_C(  50), -INT8_C(   2), -INT8_C(  77),  INT8_C(  16) } },
    { { -INT8_C(  45), -INT8_C(  37), -INT8_C( 106),  INT8_C(  23),  INT8_C(  15), -INT8_C(  91), -INT8_C(  77),  INT8_C(  44) },
      { -INT8_C(  50),  INT8_C( 126), -INT8_C(  64),  INT8_C( 105), -INT8_C( 101), -INT8_C(  28),  INT8_C(  86),  INT8_C(  38) },
      {  INT8_C(   2), -INT8_C(  82), -INT8_C(  21), -INT8_C(  41),  INT8_C(  58), -INT8_C(  32), -INT8_C(  82),  INT8_C(   3) } },
    { {  INT8_C(  79),  INT8_C(  36),      INT8_MAX, -INT8_C(  93),  INT8_C(  95),  INT8_C(  46),  INT8_C( 118), -INT8_C(  12) },
      {  INT8_C(   2), -INT8_C( 125),  INT8_C(  81), -INT8_C(  13), -INT8_C(  63), -INT8_C( 102), -INT8_C(  91), -INT8_C( 107) },
      {  INT8_C(  38),  INT8_C(  80),  INT8_C(  23), -INT8_C(  40),  INT8_C(  79),  INT8_C(  74),  INT8_C( 104),  INT8_C(  47) } },
    { {  INT8_C( 117),  INT8_C(  59), -INT8_C(  84), -INT8_C( 124), -INT8_C(  32),  INT8_C(  96), -INT8_C(  79), -INT8_C(  81) },
      { -INT8_C(  34),  INT8_C( 113),  INT8_C(  24),  INT8_C( 121),  INT8_C(  85),  INT8_C( 110), -INT8_C(  96), -INT8_C(  92) },
      {  INT8_C(  75), -INT8_C(  27), -INT8_C(  54), -INT8_C( 123), -INT8_C(  59), -INT8_C(   7),  INT8_C(   8),  INT8_C(   5) } },
    { { -INT8_C( 110),  INT8_C(  31),  INT8_C(  72), -INT8_C(  15),  INT8_C(  77), -INT8_C(  66), -INT8_C(  26),  INT8_C(  80) },
      {  INT8_C(  65),  INT8_C(  55),  INT8_C(  67),  INT8_C(   2), -INT8_C(  47), -INT8_C(  24), -INT8_C( 105),  INT8_C(  71) },
      { -INT8_C(  88), -INT8_C(  12),  INT8_C(   2), -INT8_C(   9),  INT8_C(  62), -INT8_C(  21),  INT8_C(  39),  INT8_C(   4) } },
    { {  INT8_C(  35),  INT8_C(  68), -INT8_C(  53),  INT8_C(   4), -INT8_C(  92),  INT8_C( 124), -INT8_C(  77), -INT8_C( 126) },
      { -INT8_C(  19), -INT8_C(  53), -INT8_C(   4),  INT8_C(  67),  INT8_C(  57), -INT8_C( 100), -INT8_C(  25), -INT8_C(  53) },
      {  INT8_C(  27),  INT8_C(  60), -INT8_C(  25), -INT8_C(  32), -INT8_C(  75),  INT8_C( 112), -INT8_C(  26), -INT8_C(  37) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vhsub_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vhsub_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhsub_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 12219),  INT16_C(  2492), -INT16_C( 23827),  INT16_C( 11865) },
      { -INT16_C( 25382), -INT16_C( 21711), -INT16_C( 14204), -INT16_C( 22542) },
      {  INT16_C( 18800),  INT16_C( 12101), -INT16_C(  4812),  INT16_C( 17203) } },
    { { -INT16_C( 16884), -INT16_C( 20309),  INT16_C( 24122),  INT16_C( 10291) },
      {  INT16_C( 12073),  INT16_C( 25195),  INT16_C( 21195), -INT16_C( 31187) },
      { -INT16_C( 14479), -INT16_C( 22752),  INT16_C(  1463),  INT16_C( 20739) } },
    { { -INT16_C(  5502),  INT16_C( 28559), -INT16_C(  6004),  INT16_C( 26270) },
      { -INT16_C( 12412),  INT16_C(  2066),  INT16_C(  1175), -INT16_C( 23376) },
      {  INT16_C(  3455),  INT16_C( 13246), -INT16_C(  3590),  INT16_C( 24823) } },
    { {  INT16_C( 23490), -INT16_C(   684), -INT16_C( 30790), -INT16_C(  7387) },
      { -INT16_C( 28490), -INT16_C( 32442),  INT16_C( 29666),  INT16_C( 25608) },
      {  INT16_C( 25990),  INT16_C( 15879), -INT16_C( 30228), -INT16_C( 16498) } },
    { { -INT16_C( 26787), -INT16_C(  5420),  INT16_C( 29312),  INT16_C(  1104) },
      {  INT16_C( 25153), -INT16_C( 10227), -INT16_C( 17049),  INT16_C( 10620) },
      { -INT16_C( 25970),  INT16_C(  2403),  INT16_C( 23180), -INT16_C(  4758) } },
    { { -INT16_C( 12008), -INT16_C( 11738),  INT16_C( 19288),  INT16_C(  4022) },
      { -INT16_C(   805), -INT16_C( 16752), -INT16_C( 26513), -INT16_C( 13022) },
      { -INT16_C(  5602),  INT16_C(  2507),  INT16_C( 22900),  INT16_C(  8522) } },
    { { -INT16_C(  2512), -INT16_C( 20297),  INT16_C(  1896), -INT16_C( 22092) },
      { -INT16_C( 16022), -INT16_C( 11902), -INT16_C(   386), -INT16_C( 26630) },
      {  INT16_C(  6755), -INT16_C(  4198),  INT16_C(  1141),  INT16_C(  2269) } },
    { {  INT16_C(  8655),  INT16_C( 10345),  INT16_C(  8044),  INT16_C( 18487) },
      { -INT16_C( 14565), -INT16_C( 29946),  INT16_C( 10336), -INT16_C( 28584) },
      {  INT16_C( 11610),  INT16_C( 20145), -INT16_C(  1146),  INT16_C( 23535) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vhsub_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vhsub_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(TEST_SIMDE_VABD_NO_TEST_32)
static int
test_simde_vhsub_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  2025844961), -INT32_C(  2144209898) },
      {  INT32_C(   877769654), -INT32_C(  2117382991) },
      { -INT32_C(  1451807308), -INT32_C(    13413454) } },
    { { -INT32_C(   643222163),  INT32_C(  1881268308) },
      {  INT32_C(   133900199),  INT32_C(  1872188240) },
      { -INT32_C(   388561181),  INT32_C(     4540034) } },
    { {  INT32_C(  2029442914), -INT32_C(  2097600564) },
      { -INT32_C(  1934210342),  INT32_C(    51217046) },
      {  INT32_C(  1981826628), -INT32_C(  1074408805) } },
    { {  INT32_C(   199079607),  INT32_C(  1031536278) },
      {  INT32_C(  1984263718),  INT32_C(   736484553) },
      { -INT32_C(   892592056),  INT32_C(   147525862) } },
    { { -INT32_C(  2136679500), -INT32_C(   587031293) },
      {  INT32_C(  2120857831), -INT32_C(   243173830) },
      { -INT32_C(  2128768666), -INT32_C(   171928732) } },
    { { -INT32_C(  1023582676), -INT32_C(  2097121187) },
      { -INT32_C(  1191623185), -INT32_C(   706421215) },
      {  INT32_C(    84020254), -INT32_C(   695349986) } },
    { { -INT32_C(  1135245127),  INT32_C(   211441445) },
      {  INT32_C(  1250558736), -INT32_C(  1506014086) },
      { -INT32_C(  1192901932),  INT32_C(   858727765) } },
    { { -INT32_C(   949405334), -INT32_C(  1605736015) },
      { -INT32_C(   816233554), -INT32_C(   609927903) },
      { -INT32_C(    66585890), -INT32_C(   497904056) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vhsub_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vhsub_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

static int
test_simde_vhsub_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(197), UINT8_C(250), UINT8_C(151), UINT8_C(234), UINT8_C( 82), UINT8_C( 49), UINT8_C(246), UINT8_C( 98) },
      { UINT8_C( 53), UINT8_C(129), UINT8_C(172), UINT8_C(175), UINT8_C(141), UINT8_C(232), UINT8_C( 85), UINT8_C(247) },
      { UINT8_C( 72), UINT8_C( 60), UINT8_C(245), UINT8_C( 29), UINT8_C(226), UINT8_C(164), UINT8_C( 80), UINT8_C(181) } },
    { { UINT8_C( 33), UINT8_C(190), UINT8_C(191), UINT8_C(211), UINT8_C( 39), UINT8_C(  9), UINT8_C(115), UINT8_C(213) },
      { UINT8_C( 77), UINT8_C(204), UINT8_C(165), UINT8_C(110), UINT8_C(  9), UINT8_C( 74), UINT8_C( 73), UINT8_C(206) },
      { UINT8_C(234), UINT8_C(249), UINT8_C( 13), UINT8_C( 50), UINT8_C( 15), UINT8_C(223), UINT8_C( 21), UINT8_C(  3) } },
    { { UINT8_C( 68), UINT8_C(225), UINT8_C(184), UINT8_C(150), UINT8_C( 18), UINT8_C(175), UINT8_C(248), UINT8_C( 71) },
      { UINT8_C( 48), UINT8_C(165), UINT8_C(246), UINT8_C(189), UINT8_C(141), UINT8_C( 76), UINT8_C(180), UINT8_C(175) },
      { UINT8_C( 10), UINT8_C( 30), UINT8_C(225), UINT8_C(236), UINT8_C(194), UINT8_C( 49), UINT8_C( 34), UINT8_C(204) } },
    { { UINT8_C( 10), UINT8_C(115), UINT8_C(130), UINT8_C( 50), UINT8_C(125), UINT8_C(245), UINT8_C(  7), UINT8_C(202) },
      { UINT8_C(194), UINT8_C(172), UINT8_C( 56), UINT8_C(203), UINT8_C(246), UINT8_C(130), UINT8_C(154), UINT8_C( 59) },
      { UINT8_C(164), UINT8_C(227), UINT8_C( 37), UINT8_C(179), UINT8_C(195), UINT8_C( 57), UINT8_C(182), UINT8_C( 71) } },
    { { UINT8_C( 99), UINT8_C( 82), UINT8_C(209), UINT8_C(117), UINT8_C(  1), UINT8_C(202), UINT8_C(189), UINT8_C( 49) },
      { UINT8_C(111), UINT8_C(179), UINT8_C(238), UINT8_C(252),    UINT8_MAX, UINT8_C(163), UINT8_C(171), UINT8_C( 10) },
      { UINT8_C(250), UINT8_C(207), UINT8_C(241), UINT8_C(188), UINT8_C(129), UINT8_C( 19), UINT8_C(  9), UINT8_C( 19) } },
    { { UINT8_C( 22), UINT8_C( 45), UINT8_C( 60), UINT8_C(147), UINT8_C( 35), UINT8_C( 67), UINT8_C( 93), UINT8_C(229) },
      { UINT8_C(240), UINT8_C(150), UINT8_C(176), UINT8_C(230), UINT8_C( 24), UINT8_C( 74), UINT8_C( 33), UINT8_C(123) },
      { UINT8_C(147), UINT8_C(203), UINT8_C(198), UINT8_C(214), UINT8_C(  5), UINT8_C(252), UINT8_C( 30), UINT8_C( 53) } },
    { { UINT8_C(157), UINT8_C(243), UINT8_C(240), UINT8_C(158), UINT8_C(189), UINT8_C(173), UINT8_C(208), UINT8_C( 44) },
      { UINT8_C( 97), UINT8_C(190), UINT8_C( 40), UINT8_C( 96), UINT8_C( 97), UINT8_C(212), UINT8_C(106), UINT8_C(120) },
      { UINT8_C( 30), UINT8_C( 26), UINT8_C(100), UINT8_C( 31), UINT8_C( 46), UINT8_C(236), UINT8_C( 51), UINT8_C(218) } },
    { { UINT8_C(  1), UINT8_C(166), UINT8_C( 11), UINT8_C( 36), UINT8_C(234), UINT8_C(105), UINT8_C(  9), UINT8_C(218) },
      {    UINT8_MAX, UINT8_C(186), UINT8_C(192), UINT8_C( 23), UINT8_C(  4), UINT8_C(226), UINT8_C(146), UINT8_C(161) },
      { UINT8_C(129), UINT8_C(246), UINT8_C(165), UINT8_C(  6), UINT8_C(115), UINT8_C(195), UINT8_C(187), UINT8_C( 28) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vhsub_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vhsub_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhsub_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(33493), UINT16_C(37440), UINT16_C( 4144), UINT16_C(37310) },
      { UINT16_C(59086), UINT16_C(12529), UINT16_C(23738), UINT16_C(48296) },
      { UINT16_C(52739), UINT16_C(12455), UINT16_C(55739), UINT16_C(60043) } },
    { { UINT16_C(45826), UINT16_C(60640), UINT16_C(59932), UINT16_C( 7110) },
      { UINT16_C(34724), UINT16_C(43058), UINT16_C(50281), UINT16_C(15946) },
      { UINT16_C( 5551), UINT16_C( 8791), UINT16_C( 4825), UINT16_C(61118) } },
    { { UINT16_C(35399), UINT16_C(30672), UINT16_C(36506), UINT16_C(26632) },
      { UINT16_C(63860), UINT16_C(12184), UINT16_C(16469), UINT16_C(22763) },
      { UINT16_C(51305), UINT16_C( 9244), UINT16_C(10018), UINT16_C( 1934) } },
    { { UINT16_C(52212), UINT16_C( 4164), UINT16_C( 2997), UINT16_C(22828) },
      { UINT16_C(24210), UINT16_C(64258), UINT16_C(19491), UINT16_C(27193) },
      { UINT16_C(14001), UINT16_C(35489), UINT16_C(57289), UINT16_C(63353) } },
    { { UINT16_C( 2518), UINT16_C(28897), UINT16_C(59799), UINT16_C( 3032) },
      { UINT16_C(29154), UINT16_C(14394), UINT16_C( 9649), UINT16_C(42384) },
      { UINT16_C(52218), UINT16_C( 7251), UINT16_C(25075), UINT16_C(45860) } },
    { { UINT16_C(54513), UINT16_C(42678), UINT16_C(58079), UINT16_C(28928) },
      { UINT16_C(  576), UINT16_C(25452), UINT16_C(42318), UINT16_C( 9421) },
      { UINT16_C(26968), UINT16_C( 8613), UINT16_C( 7880), UINT16_C( 9753) } },
    { { UINT16_C(44718), UINT16_C(17812), UINT16_C(27799), UINT16_C(31313) },
      { UINT16_C(35805), UINT16_C(36786), UINT16_C(17073), UINT16_C(41524) },
      { UINT16_C( 4456), UINT16_C(56049), UINT16_C( 5363), UINT16_C(60430) } },
    { { UINT16_C(59926), UINT16_C(63048), UINT16_C(18636), UINT16_C( 3431) },
      { UINT16_C(54346), UINT16_C(39024), UINT16_C(15993), UINT16_C(10428) },
      { UINT16_C( 2790), UINT16_C(12012), UINT16_C( 1321), UINT16_C(62037) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vhsub_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vhsub_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhsub_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2221756652), UINT32_C(2600386237) },
      { UINT32_C(4213813322), UINT32_C( 144531186) },
      { UINT32_C(3298938961), UINT32_C(1227927525) } },
    { { UINT32_C( 369026376), UINT32_C(2015520302) },
      { UINT32_C(3004273210), UINT32_C(3185298896) },
      { UINT32_C(2977343879), UINT32_C(3710077999) } },
    { { UINT32_C(3678488862), UINT32_C(1366638343) },
      { UINT32_C(3779895279), UINT32_C(1172957693) },
      { UINT32_C(4244264087), UINT32_C(  96840325) } },
    { { UINT32_C(4250593487), UINT32_C(2289400910) },
      { UINT32_C(3745220111), UINT32_C(1922832212) },
      { UINT32_C( 252686688), UINT32_C( 183284349) } },
    { { UINT32_C(1733156192), UINT32_C( 196723228) },
      { UINT32_C(1592526177), UINT32_C(3198473967) },
      { UINT32_C(  70315007), UINT32_C(2794091926) } },
    { { UINT32_C( 213647038), UINT32_C(2324967547) },
      { UINT32_C( 191483831), UINT32_C(1182598886) },
      { UINT32_C(  11081603), UINT32_C( 571184330) } },
    { { UINT32_C(  11455203), UINT32_C(3993724812) },
      { UINT32_C(1531770988), UINT32_C(2350510286) },
      { UINT32_C(3534809403), UINT32_C( 821607263) } },
    { { UINT32_C(1788400879), UINT32_C(3170118661) },
      { UINT32_C(3804716539), UINT32_C(1193821283) },
      { UINT32_C(3286809466), UINT32_C( 988148689) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vhsub_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vhsub_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhsubq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  14), -INT8_C(  42),  INT8_C(  71), -INT8_C( 102),  INT8_C(  61),  INT8_C(  82), -INT8_C( 120), -INT8_C(  86),
         INT8_C(  74), -INT8_C(  43),  INT8_C(   5),  INT8_C(  24), -INT8_C(  59),  INT8_C(  31), -INT8_C(  92), -INT8_C(  76) },
      { -INT8_C(  13),  INT8_C(  60),  INT8_C(  30), -INT8_C(   8),  INT8_C( 104),  INT8_C(  18), -INT8_C(  76),  INT8_C( 100),
         INT8_C( 112),  INT8_C( 123),  INT8_C(  70), -INT8_C(  45), -INT8_C(  65),  INT8_C( 110),  INT8_C(  26), -INT8_C(  51) },
      {  INT8_C(  13), -INT8_C(  51),  INT8_C(  20), -INT8_C(  47), -INT8_C(  22),  INT8_C(  32), -INT8_C(  22), -INT8_C(  93),
        -INT8_C(  19), -INT8_C(  83), -INT8_C(  33),  INT8_C(  34),  INT8_C(   3), -INT8_C(  40), -INT8_C(  59), -INT8_C(  13) } },
    { {  INT8_C(  69),  INT8_C(  97),  INT8_C( 104), -INT8_C( 126), -INT8_C(  76), -INT8_C(  16),  INT8_C(  44), -INT8_C(   2),
        -INT8_C(  59),  INT8_C(  50),  INT8_C(  23), -INT8_C( 117),  INT8_C(  81), -INT8_C(  69),  INT8_C(  63),  INT8_C(  68) },
      { -INT8_C(   8),  INT8_C(  94),  INT8_C(  61),  INT8_C(  96),  INT8_C( 112), -INT8_C(  15), -INT8_C(  60), -INT8_C(  32),
         INT8_C( 109),  INT8_C(  10), -INT8_C(  76),  INT8_C(  44),  INT8_C( 121), -INT8_C(  50), -INT8_C(   6), -INT8_C(  66) },
      {  INT8_C(  38),  INT8_C(   1),  INT8_C(  21), -INT8_C( 111), -INT8_C(  94), -INT8_C(   1),  INT8_C(  52),  INT8_C(  15),
        -INT8_C(  84),  INT8_C(  20),  INT8_C(  49), -INT8_C(  81), -INT8_C(  20), -INT8_C(  10),  INT8_C(  34),  INT8_C(  67) } },
    { {  INT8_C(  48),  INT8_C(  98),  INT8_C(  64), -INT8_C(  28),  INT8_C(  82),  INT8_C( 109), -INT8_C(  30),  INT8_C(  24),
        -INT8_C(  97), -INT8_C(   7), -INT8_C(  93), -INT8_C(  16), -INT8_C(  75), -INT8_C(  30),  INT8_C(  52), -INT8_C(  83) },
      {  INT8_C(  64),  INT8_C( 113),  INT8_C(  13), -INT8_C(  79),  INT8_C(  99), -INT8_C(  46), -INT8_C( 111), -INT8_C(  48),
        -INT8_C(  36),  INT8_C(  69), -INT8_C(   4),  INT8_C(  85),  INT8_C(  20), -INT8_C(  10),  INT8_C(  19),  INT8_C(  68) },
      { -INT8_C(   8), -INT8_C(   8),  INT8_C(  25),  INT8_C(  25), -INT8_C(   9),  INT8_C(  77),  INT8_C(  40),  INT8_C(  36),
        -INT8_C(  31), -INT8_C(  38), -INT8_C(  45), -INT8_C(  51), -INT8_C(  48), -INT8_C(  10),  INT8_C(  16), -INT8_C(  76) } },
    { {  INT8_C(  88),  INT8_C(  84),  INT8_C(  40), -INT8_C(  85), -INT8_C(  63),  INT8_C(  10), -INT8_C(  61),  INT8_C(  96),
         INT8_C(   4),  INT8_C( 102),  INT8_C(  80), -INT8_C(  71),  INT8_C(  72), -INT8_C( 124),  INT8_C( 102), -INT8_C( 119) },
      { -INT8_C(  10),  INT8_C( 115),  INT8_C(  58),  INT8_C(  89),  INT8_C(  69), -INT8_C(  53),  INT8_C(  41),  INT8_C(  34),
         INT8_C(  17),  INT8_C(  37),  INT8_C( 119),  INT8_C(  37),  INT8_C(  28), -INT8_C( 117),  INT8_C( 105),  INT8_C( 116) },
      {  INT8_C(  49), -INT8_C(  16), -INT8_C(   9), -INT8_C(  87), -INT8_C(  66),  INT8_C(  31), -INT8_C(  51),  INT8_C(  31),
        -INT8_C(   7),  INT8_C(  32), -INT8_C(  20), -INT8_C(  54),  INT8_C(  22), -INT8_C(   4), -INT8_C(   2), -INT8_C( 118) } },
    { { -INT8_C(  33), -INT8_C( 111),  INT8_C(  31), -INT8_C(  96), -INT8_C( 101), -INT8_C(  30),  INT8_C(   0), -INT8_C(  97),
         INT8_C(  72),  INT8_C(  80),  INT8_C(  88), -INT8_C( 111), -INT8_C(  44), -INT8_C(  66),  INT8_C(  26), -INT8_C(  54) },
      {  INT8_C(  50),  INT8_C(  84),  INT8_C(  35),  INT8_C( 119),  INT8_C(  31),  INT8_C(  76), -INT8_C( 103),  INT8_C(  48),
         INT8_C( 114),  INT8_C(  17),  INT8_C(  85), -INT8_C( 114), -INT8_C( 100), -INT8_C(  66),  INT8_C(   2),  INT8_C( 123) },
      { -INT8_C(  42), -INT8_C(  98), -INT8_C(   2), -INT8_C( 108), -INT8_C(  66), -INT8_C(  53),  INT8_C(  51), -INT8_C(  73),
        -INT8_C(  21),  INT8_C(  31),  INT8_C(   1),  INT8_C(   1),  INT8_C(  28),  INT8_C(   0),  INT8_C(  12), -INT8_C(  89) } },
    { {  INT8_C(  79),  INT8_C(  34),  INT8_C(  27), -INT8_C(  21),  INT8_C(   4),  INT8_C(  27), -INT8_C( 118),  INT8_C(  77),
         INT8_C( 107), -INT8_C(  29), -INT8_C(  34),  INT8_C(  63), -INT8_C(  95), -INT8_C(   8),  INT8_C(  10), -INT8_C(  45) },
      {  INT8_C(  76),  INT8_C(  45),  INT8_C(  75),  INT8_C( 107),  INT8_C( 122), -INT8_C(  28), -INT8_C( 100), -INT8_C(  20),
        -INT8_C(  11), -INT8_C(  15),  INT8_C( 122), -INT8_C( 111), -INT8_C(  80),  INT8_C( 124),  INT8_C(  12), -INT8_C(   1) },
      {  INT8_C(   1), -INT8_C(   6), -INT8_C(  24), -INT8_C(  64), -INT8_C(  59),  INT8_C(  27), -INT8_C(   9),  INT8_C(  48),
         INT8_C(  59), -INT8_C(   7), -INT8_C(  78),  INT8_C(  87), -INT8_C(   8), -INT8_C(  66), -INT8_C(   1), -INT8_C(  22) } },
    { { -INT8_C(  98),  INT8_C(  39), -INT8_C(  22), -INT8_C(  93),  INT8_C(  66),  INT8_C( 117), -INT8_C(  16), -INT8_C(  83),
         INT8_C(  88), -INT8_C(  50), -INT8_C(  19), -INT8_C(   7), -INT8_C(  58), -INT8_C(   9), -INT8_C(  51),  INT8_C(  18) },
      {  INT8_C(  36),  INT8_C(  24),  INT8_C( 125), -INT8_C(  98), -INT8_C(   4),  INT8_C(  25), -INT8_C( 118), -INT8_C(  14),
         INT8_C(  11),  INT8_C(   4), -INT8_C( 125), -INT8_C(  69), -INT8_C( 127), -INT8_C( 112), -INT8_C(  70),  INT8_C(  31) },
      { -INT8_C(  67),  INT8_C(   7), -INT8_C(  74),  INT8_C(   2),  INT8_C(  35),  INT8_C(  46),  INT8_C(  51), -INT8_C(  35),
         INT8_C(  38), -INT8_C(  27),  INT8_C(  53),  INT8_C(  31),  INT8_C(  34),  INT8_C(  51),  INT8_C(   9), -INT8_C(   7) } },
    { { -INT8_C(  73), -INT8_C(  91), -INT8_C(  62), -INT8_C(   6),  INT8_C(  26), -INT8_C(  78), -INT8_C(  89),  INT8_C( 114),
             INT8_MIN, -INT8_C( 108),  INT8_C( 107),  INT8_C(  70), -INT8_C( 117),  INT8_C(  56),  INT8_C(  88), -INT8_C(  80) },
      {  INT8_C(  80), -INT8_C(  42),  INT8_C(  78),  INT8_C(  77), -INT8_C(  17), -INT8_C(  39),  INT8_C(  63), -INT8_C(   6),
        -INT8_C(  35), -INT8_C(  62), -INT8_C(  75),  INT8_C(  94),  INT8_C(  82),  INT8_C( 112),  INT8_C( 126),  INT8_C(  10) },
      { -INT8_C(  77), -INT8_C(  25), -INT8_C(  70), -INT8_C(  42),  INT8_C(  21), -INT8_C(  20), -INT8_C(  76),  INT8_C(  60),
        -INT8_C(  47), -INT8_C(  23),  INT8_C(  91), -INT8_C(  12), -INT8_C( 100), -INT8_C(  28), -INT8_C(  19), -INT8_C(  45) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vhsubq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vhsubq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhsubq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 16405),  INT16_C( 12036), -INT16_C( 21517),  INT16_C( 29601),  INT16_C(  3136), -INT16_C( 13382),  INT16_C(  4677), -INT16_C( 27269) },
      { -INT16_C( 13592), -INT16_C( 10014),  INT16_C(  8611), -INT16_C( 32558), -INT16_C( 30492),  INT16_C( 14047),  INT16_C( 24056),  INT16_C(  3392) },
      {  INT16_C( 14998),  INT16_C( 11025), -INT16_C( 15064),  INT16_C( 31079),  INT16_C( 16814), -INT16_C( 13715), -INT16_C(  9690), -INT16_C( 15331) } },
    { {  INT16_C( 17565), -INT16_C( 28612), -INT16_C(  8720),  INT16_C( 12292), -INT16_C( 16663),  INT16_C( 12027),  INT16_C( 30672), -INT16_C( 17980) },
      { -INT16_C( 22975), -INT16_C(  7023),  INT16_C( 25544), -INT16_C( 21404),  INT16_C( 17387), -INT16_C(  7198),  INT16_C(  9120),  INT16_C( 16112) },
      {  INT16_C( 20270), -INT16_C( 10795), -INT16_C( 17132),  INT16_C( 16848), -INT16_C( 17025),  INT16_C(  9612),  INT16_C( 10776), -INT16_C( 17046) } },
    { {  INT16_C( 11367),  INT16_C( 22478), -INT16_C( 11767), -INT16_C(  3193), -INT16_C( 31856),  INT16_C( 24865), -INT16_C(  6662),  INT16_C( 15130) },
      { -INT16_C( 21620),  INT16_C( 21535), -INT16_C( 31986), -INT16_C(  1536), -INT16_C(  7481),  INT16_C( 26589), -INT16_C( 12795),  INT16_C( 28069) },
      {  INT16_C( 16493),  INT16_C(   471),  INT16_C( 10109), -INT16_C(   829), -INT16_C( 12188), -INT16_C(   862),  INT16_C(  3066), -INT16_C(  6470) } },
    { {  INT16_C( 29946),  INT16_C(  1220),  INT16_C( 19526), -INT16_C( 10249),  INT16_C(  6351), -INT16_C( 14024),  INT16_C( 21246), -INT16_C( 30204) },
      {  INT16_C(  9213),  INT16_C(  3038), -INT16_C(  8538),  INT16_C( 27909), -INT16_C(  7232), -INT16_C( 14635),  INT16_C( 31409), -INT16_C( 21709) },
      {  INT16_C( 10366), -INT16_C(   909),  INT16_C( 14032), -INT16_C( 19079),  INT16_C(  6791),  INT16_C(   305), -INT16_C(  5082), -INT16_C(  4248) } },
    { { -INT16_C(  2066),  INT16_C( 13743), -INT16_C( 22973),  INT16_C(  4620),  INT16_C( 17599), -INT16_C( 16933), -INT16_C(  8298), -INT16_C( 27833) },
      {  INT16_C(  9474), -INT16_C( 22114), -INT16_C( 23549), -INT16_C( 15594), -INT16_C(  5241),  INT16_C( 14473), -INT16_C( 17306),  INT16_C( 21731) },
      { -INT16_C(  5770),  INT16_C( 17928),  INT16_C(   288),  INT16_C( 10107),  INT16_C( 11420), -INT16_C( 15703),  INT16_C(  4504), -INT16_C( 24782) } },
    { { -INT16_C( 27724), -INT16_C(  2167), -INT16_C( 27335), -INT16_C(  2038), -INT16_C(  6695),  INT16_C( 28597), -INT16_C(   827), -INT16_C( 14590) },
      { -INT16_C( 24287),  INT16_C(  9328), -INT16_C( 30907), -INT16_C( 13080),  INT16_C( 29042), -INT16_C( 10236), -INT16_C(  6354), -INT16_C(  7635) },
      { -INT16_C(  1719), -INT16_C(  5748),  INT16_C(  1786),  INT16_C(  5521), -INT16_C( 17869),  INT16_C( 19416),  INT16_C(  2763), -INT16_C(  3478) } },
    { { -INT16_C( 18822), -INT16_C( 19239), -INT16_C(  7348),  INT16_C(  9644),  INT16_C( 25289), -INT16_C( 29035), -INT16_C( 26786), -INT16_C( 32683) },
      { -INT16_C( 14792),  INT16_C( 32164), -INT16_C( 29619), -INT16_C( 16567),  INT16_C( 19966),  INT16_C( 11416), -INT16_C( 15051), -INT16_C( 20722) },
      { -INT16_C(  2015), -INT16_C( 25702),  INT16_C( 11135),  INT16_C( 13105),  INT16_C(  2661), -INT16_C( 20226), -INT16_C(  5868), -INT16_C(  5981) } },
    { { -INT16_C(  6277), -INT16_C( 14493),  INT16_C(  4299), -INT16_C( 27411), -INT16_C( 32142), -INT16_C( 12254),  INT16_C( 30489),  INT16_C( 21072) },
      { -INT16_C(  2755), -INT16_C( 30001),  INT16_C(  6529),  INT16_C( 32586), -INT16_C(  7578), -INT16_C( 25685), -INT16_C( 18009),  INT16_C(  8779) },
      { -INT16_C(  1761),  INT16_C(  7754), -INT16_C(  1115), -INT16_C( 29999), -INT16_C( 12282),  INT16_C(  6715),  INT16_C( 24249),  INT16_C(  6146) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vhsubq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vhsubq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhsubq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1827319457),  INT32_C(   805361598),  INT32_C(  1912676953), -INT32_C(   674999911) },
      { -INT32_C(   933129146),  INT32_C(   323464109),  INT32_C(   883946381),  INT32_C(  1297611436) },
      {  INT32_C(  1380224301),  INT32_C(   240948744),  INT32_C(   514365286), -INT32_C(   986305674) } },
    { {  INT32_C(  1740194216),  INT32_C(  1905768728),  INT32_C(  1977850075),  INT32_C(   810330346) },
      { -INT32_C(   369578692), -INT32_C(   419676071), -INT32_C(   551834829),  INT32_C(  1311601317) },
      {  INT32_C(  1054886454),  INT32_C(  1162722399),  INT32_C(  1264842452), -INT32_C(   250635486) } },
    { { -INT32_C(   877271373),  INT32_C(  2067549344), -INT32_C(   806346779),  INT32_C(    67058887) },
      {  INT32_C(  1139603690),  INT32_C(  1797908792),  INT32_C(   977945748),  INT32_C(  1770551222) },
      { -INT32_C(  1008437532),  INT32_C(   134820276), -INT32_C(   892146264), -INT32_C(   851746168) } },
    { { -INT32_C(    30130850),  INT32_C(  1853452425),  INT32_C(  1463642768), -INT32_C(  1873068634) },
      {  INT32_C(  1842562869), -INT32_C(   975635152), -INT32_C(   117497279), -INT32_C(   127826022) },
      { -INT32_C(   936346860),  INT32_C(  1414543788),  INT32_C(   790570023), -INT32_C(   872621306) } },
    { {  INT32_C(  1308006084), -INT32_C(  1766035706), -INT32_C(  2131822119),  INT32_C(  1796229430) },
      { -INT32_C(  1042750320),  INT32_C(   579252449),  INT32_C(  1830454739), -INT32_C(   798655476) },
      {  INT32_C(  1175378202), -INT32_C(  1172644078), -INT32_C(  1981138429),  INT32_C(  1297442453) } },
    { {  INT32_C(   404577042), -INT32_C(  1531979318),  INT32_C(   153394643),  INT32_C(  1987392742) },
      { -INT32_C(   113816296), -INT32_C(   786645506),  INT32_C(  1312699970), -INT32_C(  1004624974) },
      {  INT32_C(   259196669), -INT32_C(   372666906), -INT32_C(   579652664),  INT32_C(  1496008858) } },
    { { -INT32_C(   925025026), -INT32_C(   395539435),  INT32_C(   267554857), -INT32_C(   578459707) },
      { -INT32_C(  1294484044), -INT32_C(  1115425926), -INT32_C(   603209431),  INT32_C(  1654663780) },
      {  INT32_C(   184729509),  INT32_C(   359943245),  INT32_C(   435382144), -INT32_C(  1116561744) } },
    { {  INT32_C(  2066447718),  INT32_C(   845453065), -INT32_C(   314485208),  INT32_C(  1909114813) },
      { -INT32_C(    31153788), -INT32_C(  1094998124), -INT32_C(   845494423),  INT32_C(  1462778609) },
      {  INT32_C(  1048800753),  INT32_C(   970225594),  INT32_C(   265504607),  INT32_C(   223168102) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vhsubq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vhsubq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhsubq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(184), UINT8_C( 91), UINT8_C(210), UINT8_C(193), UINT8_C(242), UINT8_C( 54), UINT8_C(244), UINT8_C( 26),
        UINT8_C(140), UINT8_C( 53), UINT8_C(  7), UINT8_C( 73), UINT8_C(252), UINT8_C(210), UINT8_C(187), UINT8_C(128) },
      { UINT8_C(115), UINT8_C(223), UINT8_C(127), UINT8_C(  8), UINT8_C(134), UINT8_C( 58), UINT8_C(198), UINT8_C(239),
        UINT8_C(  1), UINT8_C( 96), UINT8_C(189), UINT8_C(242), UINT8_C(154), UINT8_C(237), UINT8_C( 73), UINT8_C( 82) },
      { UINT8_C( 34), UINT8_C(190), UINT8_C( 41), UINT8_C( 92), UINT8_C( 54), UINT8_C(254), UINT8_C( 23), UINT8_C(149),
        UINT8_C( 69), UINT8_C(234), UINT8_C(165), UINT8_C(171), UINT8_C( 49), UINT8_C(242), UINT8_C( 57), UINT8_C( 23) } },
    { { UINT8_C( 72), UINT8_C( 28), UINT8_C( 20), UINT8_C( 58), UINT8_C( 82), UINT8_C(  8), UINT8_C( 85), UINT8_C(223),
        UINT8_C( 61), UINT8_C( 92), UINT8_C( 40), UINT8_C( 58), UINT8_C( 46), UINT8_C(227), UINT8_C(186), UINT8_C(162) },
      { UINT8_C(194), UINT8_C( 57), UINT8_C(170), UINT8_C( 73), UINT8_C(116), UINT8_C(112), UINT8_C( 56), UINT8_C(117),
        UINT8_C(208), UINT8_C(245), UINT8_C(104), UINT8_C(106), UINT8_C(226), UINT8_C(177), UINT8_C(189), UINT8_C( 42) },
      { UINT8_C(195), UINT8_C(241), UINT8_C(181), UINT8_C(248), UINT8_C(239), UINT8_C(204), UINT8_C( 14), UINT8_C( 53),
        UINT8_C(182), UINT8_C(179), UINT8_C(224), UINT8_C(232), UINT8_C(166), UINT8_C( 25), UINT8_C(254), UINT8_C( 60) } },
    { { UINT8_C(205), UINT8_C(209), UINT8_C(101), UINT8_C( 32), UINT8_C(217), UINT8_C(186),    UINT8_MAX, UINT8_C( 22),
        UINT8_C( 22), UINT8_C( 39), UINT8_C( 80), UINT8_C( 69), UINT8_C( 11), UINT8_C( 11), UINT8_C(231), UINT8_C(205) },
      { UINT8_C( 68), UINT8_C(145), UINT8_C( 22), UINT8_C(184), UINT8_C(  1), UINT8_C( 79), UINT8_C( 46), UINT8_C(209),
        UINT8_C( 68), UINT8_C(150), UINT8_C( 59), UINT8_C( 39), UINT8_C( 71), UINT8_C(248), UINT8_C( 81), UINT8_C( 21) },
      { UINT8_C( 68), UINT8_C( 32), UINT8_C( 39), UINT8_C(180), UINT8_C(108), UINT8_C( 53), UINT8_C(104), UINT8_C(162),
        UINT8_C(233), UINT8_C(200), UINT8_C( 10), UINT8_C( 15), UINT8_C(226), UINT8_C(137), UINT8_C( 75), UINT8_C( 92) } },
    { { UINT8_C(201), UINT8_C(182), UINT8_C( 53), UINT8_C(162), UINT8_C(112), UINT8_C( 52), UINT8_C(185), UINT8_C(135),
        UINT8_C( 91), UINT8_C(  9), UINT8_C(204), UINT8_C(102), UINT8_C( 20), UINT8_C(179), UINT8_C( 52), UINT8_C( 89) },
      { UINT8_C( 68), UINT8_C( 74), UINT8_C( 17), UINT8_C( 69), UINT8_C(153), UINT8_C( 63), UINT8_C( 22), UINT8_C(222),
        UINT8_C(213), UINT8_C( 81), UINT8_C(  5), UINT8_C( 29), UINT8_C( 74), UINT8_C( 86), UINT8_C( 50), UINT8_C( 19) },
      { UINT8_C( 66), UINT8_C( 54), UINT8_C( 18), UINT8_C( 46), UINT8_C(235), UINT8_C(250), UINT8_C( 81), UINT8_C(212),
        UINT8_C(195), UINT8_C(220), UINT8_C( 99), UINT8_C( 36), UINT8_C(229), UINT8_C( 46), UINT8_C(  1), UINT8_C( 35) } },
    { { UINT8_C( 13), UINT8_C(103), UINT8_C(182), UINT8_C(125), UINT8_C(155), UINT8_C(111), UINT8_C(  4), UINT8_C(246),
        UINT8_C(120), UINT8_C(208), UINT8_C( 93), UINT8_C(141), UINT8_C(131), UINT8_C(145), UINT8_C(230), UINT8_C(199) },
      { UINT8_C(219), UINT8_C(247), UINT8_C( 12), UINT8_C(117), UINT8_C( 55), UINT8_C( 34), UINT8_C( 83), UINT8_C( 12),
        UINT8_C(116), UINT8_C( 88), UINT8_C( 41), UINT8_C(190), UINT8_C(174), UINT8_C( 91), UINT8_C(209), UINT8_C(187) },
      { UINT8_C(153), UINT8_C(184), UINT8_C( 85), UINT8_C(  4), UINT8_C( 50), UINT8_C( 38), UINT8_C(216), UINT8_C(117),
        UINT8_C(  2), UINT8_C( 60), UINT8_C( 26), UINT8_C(231), UINT8_C(234), UINT8_C( 27), UINT8_C( 10), UINT8_C(  6) } },
    { { UINT8_C(194), UINT8_C(135), UINT8_C( 57), UINT8_C( 93), UINT8_C(246), UINT8_C( 61), UINT8_C( 84), UINT8_C(111),
        UINT8_C( 14), UINT8_C(177), UINT8_C(252), UINT8_C(145), UINT8_C( 66), UINT8_C(226), UINT8_C( 89), UINT8_C( 29) },
      { UINT8_C(217), UINT8_C(101), UINT8_C(146), UINT8_C( 16), UINT8_C(136), UINT8_C(229), UINT8_C( 29), UINT8_C(252),
        UINT8_C( 61), UINT8_C( 70), UINT8_C(186), UINT8_C(236), UINT8_C(162), UINT8_C(139), UINT8_C(167), UINT8_C(100) },
      { UINT8_C(244), UINT8_C( 17), UINT8_C(211), UINT8_C( 38), UINT8_C( 55), UINT8_C(172), UINT8_C( 27), UINT8_C(185),
        UINT8_C(232), UINT8_C( 53), UINT8_C( 33), UINT8_C(210), UINT8_C(208), UINT8_C( 43), UINT8_C(217), UINT8_C(220) } },
    { { UINT8_C( 19), UINT8_C(224), UINT8_C(194), UINT8_C(  9), UINT8_C( 30), UINT8_C( 22), UINT8_C(120), UINT8_C( 44),
        UINT8_C(199), UINT8_C(116), UINT8_C(189), UINT8_C(  9), UINT8_C( 86), UINT8_C( 22), UINT8_C( 38), UINT8_C( 48) },
      { UINT8_C(124), UINT8_C(185), UINT8_C( 64), UINT8_C(  4), UINT8_C(158), UINT8_C( 93), UINT8_C(  0), UINT8_C(220),
        UINT8_C(164), UINT8_C(186), UINT8_C(200), UINT8_C( 70), UINT8_C( 69), UINT8_C(111), UINT8_C(170), UINT8_C( 88) },
      { UINT8_C(203), UINT8_C( 19), UINT8_C( 65), UINT8_C(  2), UINT8_C(192), UINT8_C(220), UINT8_C( 60), UINT8_C(168),
        UINT8_C( 17), UINT8_C(221), UINT8_C(250), UINT8_C(225), UINT8_C(  8), UINT8_C(211), UINT8_C(190), UINT8_C(236) } },
    { { UINT8_C( 80), UINT8_C(108), UINT8_C( 98), UINT8_C(110), UINT8_C(130), UINT8_C(218), UINT8_C(154), UINT8_C( 73),
        UINT8_C( 79), UINT8_C( 87), UINT8_C( 82), UINT8_C(165), UINT8_C(110), UINT8_C(121), UINT8_C(213), UINT8_C(234) },
      { UINT8_C( 50), UINT8_C( 22), UINT8_C(238), UINT8_C(208), UINT8_C(115), UINT8_C(238), UINT8_C(172), UINT8_C( 23),
        UINT8_C(168), UINT8_C(116), UINT8_C( 93), UINT8_C(237), UINT8_C(228), UINT8_C(  8), UINT8_C( 70), UINT8_C( 52) },
      { UINT8_C( 15), UINT8_C( 43), UINT8_C(186), UINT8_C(207), UINT8_C(  7), UINT8_C(246), UINT8_C(247), UINT8_C( 25),
        UINT8_C(211), UINT8_C(241), UINT8_C(250), UINT8_C(220), UINT8_C(197), UINT8_C( 56), UINT8_C( 71), UINT8_C( 91) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vhsubq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vhsubq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhsubq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(43124), UINT16_C(63394), UINT16_C(15490), UINT16_C(53568), UINT16_C(37779), UINT16_C(  375), UINT16_C(19468), UINT16_C(16107) },
      { UINT16_C(55650), UINT16_C(54798), UINT16_C(48071), UINT16_C(28653), UINT16_C(19247), UINT16_C( 4957), UINT16_C(41811), UINT16_C(51015) },
      { UINT16_C(59273), UINT16_C( 4298), UINT16_C(49245), UINT16_C(12457), UINT16_C( 9266), UINT16_C(63245), UINT16_C(54364), UINT16_C(48082) } },
    { { UINT16_C(59723), UINT16_C(52670), UINT16_C(65317), UINT16_C(47519), UINT16_C( 5778), UINT16_C(40634), UINT16_C(42594), UINT16_C(50652) },
      { UINT16_C(60031), UINT16_C(18331), UINT16_C(34981), UINT16_C(54710), UINT16_C( 5075), UINT16_C( 9960), UINT16_C(12470), UINT16_C(  494) },
      { UINT16_C(65382), UINT16_C(17169), UINT16_C(15168), UINT16_C(61940), UINT16_C(  351), UINT16_C(15337), UINT16_C(15062), UINT16_C(25079) } },
    { { UINT16_C(44057), UINT16_C(16335), UINT16_C(28331), UINT16_C(15864), UINT16_C(45700), UINT16_C(59099), UINT16_C(46936), UINT16_C(55467) },
      { UINT16_C(18082), UINT16_C(18207), UINT16_C(54735), UINT16_C(41500), UINT16_C( 1513), UINT16_C(40905), UINT16_C(46901), UINT16_C(20129) },
      { UINT16_C(12987), UINT16_C(64600), UINT16_C(52334), UINT16_C(52718), UINT16_C(22093), UINT16_C( 9097), UINT16_C(   17), UINT16_C(17669) } },
    { { UINT16_C(28771), UINT16_C( 3981), UINT16_C(34270), UINT16_C(25164), UINT16_C(10296), UINT16_C(36936), UINT16_C(62687), UINT16_C(33128) },
      { UINT16_C(34618), UINT16_C( 2505), UINT16_C(58717), UINT16_C(18092), UINT16_C(30186), UINT16_C( 8165), UINT16_C(34348), UINT16_C(36718) },
      { UINT16_C(62612), UINT16_C(  738), UINT16_C(53312), UINT16_C( 3536), UINT16_C(55591), UINT16_C(14385), UINT16_C(14169), UINT16_C(63741) } },
    { { UINT16_C(64502), UINT16_C(54430), UINT16_C(60289), UINT16_C(47414), UINT16_C(32531), UINT16_C(62025), UINT16_C(45683), UINT16_C(44404) },
      { UINT16_C(15673), UINT16_C(38583), UINT16_C(25378), UINT16_C( 3548), UINT16_C(49880), UINT16_C( 1068), UINT16_C(39496), UINT16_C(16275) },
      { UINT16_C(24414), UINT16_C( 7923), UINT16_C(17455), UINT16_C(21933), UINT16_C(56861), UINT16_C(30478), UINT16_C( 3093), UINT16_C(14064) } },
    { { UINT16_C(12950), UINT16_C( 5907), UINT16_C(18973), UINT16_C(12496), UINT16_C( 6601), UINT16_C(15394), UINT16_C(38603), UINT16_C( 1513) },
      { UINT16_C(41171), UINT16_C(63131), UINT16_C(30723), UINT16_C(56067), UINT16_C(12090), UINT16_C(33503), UINT16_C(29642), UINT16_C(24769) },
      { UINT16_C(51425), UINT16_C(36924), UINT16_C(59661), UINT16_C(43750), UINT16_C(62791), UINT16_C(56481), UINT16_C( 4480), UINT16_C(53908) } },
    { { UINT16_C(54693), UINT16_C(49783), UINT16_C(18207), UINT16_C(59634), UINT16_C( 5216), UINT16_C(11300), UINT16_C( 3499), UINT16_C(32305) },
      { UINT16_C(52398), UINT16_C(45428), UINT16_C(30532), UINT16_C(32397), UINT16_C(27815), UINT16_C(28929), UINT16_C(49887), UINT16_C(34001) },
      { UINT16_C( 1147), UINT16_C( 2177), UINT16_C(59373), UINT16_C(13618), UINT16_C(54236), UINT16_C(56721), UINT16_C(42342), UINT16_C(64688) } },
    { { UINT16_C(18583), UINT16_C(46662), UINT16_C(14479), UINT16_C(61342), UINT16_C(49741), UINT16_C(63515), UINT16_C(19664), UINT16_C(32374) },
      { UINT16_C(60185), UINT16_C(23855), UINT16_C(48226), UINT16_C( 2524), UINT16_C(56617), UINT16_C( 2170), UINT16_C(19359), UINT16_C(14221) },
      { UINT16_C(44735), UINT16_C(11403), UINT16_C(48662), UINT16_C(29409), UINT16_C(62098), UINT16_C(30672), UINT16_C(  152), UINT16_C( 9076) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vhsubq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vhsubq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vhsubq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 586011539), UINT32_C(1494387724), UINT32_C( 508636494), UINT32_C(2476525434) },
      { UINT32_C( 368102578), UINT32_C(2971585672), UINT32_C(1236965801), UINT32_C(2021672932) },
      { UINT32_C( 108954480), UINT32_C(3556368322), UINT32_C(3930802642), UINT32_C( 227426251) } },
    { { UINT32_C( 647654682), UINT32_C(1216326905), UINT32_C(1416024282), UINT32_C(1256653720) },
      { UINT32_C(1465898959), UINT32_C(1292467876), UINT32_C(4220961559), UINT32_C( 611522058) },
      { UINT32_C(3885845157), UINT32_C(4256896810), UINT32_C(2892498657), UINT32_C( 322565831) } },
    { { UINT32_C(2102070916), UINT32_C(2495990458), UINT32_C( 870853787), UINT32_C(4269657903) },
      { UINT32_C(1263918503), UINT32_C(1922588251), UINT32_C( 728575777), UINT32_C(3377520965) },
      { UINT32_C( 419076206), UINT32_C( 286701103), UINT32_C(  71139005), UINT32_C( 446068469) } },
    { { UINT32_C(2840042479), UINT32_C(   4066405), UINT32_C(1731405368), UINT32_C(2640687606) },
      { UINT32_C(3924343694), UINT32_C( 995852313), UINT32_C(4117153967), UINT32_C(2562635433) },
      { UINT32_C(3752816688), UINT32_C(3799074342), UINT32_C(3102092996), UINT32_C(  39026086) } },
    { { UINT32_C(3074557265), UINT32_C(1253539858), UINT32_C(2628971430), UINT32_C( 708384668) },
      { UINT32_C(3960676818), UINT32_C(1361538722), UINT32_C(3762720054), UINT32_C(2507670852) },
      { UINT32_C(3851907519), UINT32_C(4240967864), UINT32_C(3728092984), UINT32_C(3395324204) } },
    { { UINT32_C( 474790410), UINT32_C(3781624890), UINT32_C(2340231663), UINT32_C(  62240560) },
      { UINT32_C(2062534872), UINT32_C(1825314358), UINT32_C(3880522403), UINT32_C( 578667799) },
      { UINT32_C(3501095065), UINT32_C( 978155266), UINT32_C(3524821926), UINT32_C(4036753676) } },
    { { UINT32_C(3124676991), UINT32_C(3164317133), UINT32_C(4014414014), UINT32_C(2834496719) },
      { UINT32_C(4196590020), UINT32_C(2590502647), UINT32_C( 411218689), UINT32_C(4164616056) },
      { UINT32_C(3759010781), UINT32_C( 286907243), UINT32_C(1801597662), UINT32_C(3629907627) } },
    { { UINT32_C(2528278984), UINT32_C(3713158430), UINT32_C( 902601317), UINT32_C(1541258902) },
      { UINT32_C(2522218399), UINT32_C(4012948718), UINT32_C(3892818544), UINT32_C(2061517489) },
      { UINT32_C(   3030292), UINT32_C(4145072152), UINT32_C(2799858682), UINT32_C(4034838002) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vhsubq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vhsubq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vhsub_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsub_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsub_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsub_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsub_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsub_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsubq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsubq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsubq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsubq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsubq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vhsubq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
