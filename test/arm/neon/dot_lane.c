#define SIMDE_TEST_ARM_NEON_INSN dot_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/dot_lane.h"

static int
test_simde_vdot_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[2];
    int8_t a[8];
    int8_t b[8];
    const int lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1695142189),  INT32_C(   606253494) },
      { -INT8_C(   8),  INT8_C( 126), -INT8_C(  89), -INT8_C(   2),  INT8_C(  86),  INT8_C(  74),  INT8_C( 126),  INT8_C(  50) },
      { -INT8_C(  85), -INT8_C(  18), -INT8_C( 109),  INT8_C(  56),      INT8_MIN, -INT8_C( 104), -INT8_C(  65), -INT8_C(  22) },
       INT32_C(           0),
      { -INT32_C(  1695134188),  INT32_C(   606233918) } },
    { { -INT32_C(   475476306), -INT32_C(  1248166687) },
      { -INT8_C(  86), -INT8_C( 112),  INT8_C(  79),  INT8_C(  96),  INT8_C(  66),  INT8_C( 113), -INT8_C( 123),  INT8_C(  58) },
      { -INT8_C(  17),  INT8_C(  44),  INT8_C(  56),  INT8_C(  69),  INT8_C( 119), -INT8_C(  74),  INT8_C( 119),  INT8_C(  34) },
       INT32_C(           1),
      { -INT32_C(   475465587), -INT32_C(  1248179860) } },
    { {  INT32_C(   609880740),  INT32_C(  1359944354) },
      { -INT8_C(  24), -INT8_C(  73),  INT8_C(  52), -INT8_C(  54),  INT8_C(  51), -INT8_C(  50),      INT8_MAX, -INT8_C(  34) },
      {  INT8_C(  95), -INT8_C(  50),  INT8_C(  62), -INT8_C(  95),  INT8_C(  63), -INT8_C(  61), -INT8_C(  37),  INT8_C(  46) },
       INT32_C(           0),
      {  INT32_C(   609890464),  INT32_C(  1359962803) } },
    { {  INT32_C(  1735660528),  INT32_C(  1837755337) },
      { -INT8_C(  10), -INT8_C(  28), -INT8_C( 110), -INT8_C( 104), -INT8_C(   2), -INT8_C(  95), -INT8_C(  23), -INT8_C(  26) },
      {  INT8_C(  88),  INT8_C(  29), -INT8_C(  80), -INT8_C( 117), -INT8_C(  20),  INT8_C(  47),  INT8_C( 105),  INT8_C(  75) },
       INT32_C(           1),
      {  INT32_C(  1735640062),  INT32_C(  1837746547) } },
    { {  INT32_C(  1022142717),  INT32_C(  1533790059) },
      { -INT8_C(  38), -INT8_C(  33), -INT8_C(  62), -INT8_C(  93), -INT8_C(  54),  INT8_C(  76),  INT8_C(  16), -INT8_C(  64) },
      {  INT8_C(  48), -INT8_C(  94),  INT8_C(  89),  INT8_C(  46),  INT8_C(  67),  INT8_C(  66),  INT8_C(  20), -INT8_C( 101) },
       INT32_C(           0),
      {  INT32_C(  1022134199),  INT32_C(  1533778803) } },
    { {  INT32_C(  1277674848), -INT32_C(   224947980) },
      {  INT8_C(  56), -INT8_C( 125),  INT8_C(  46), -INT8_C(  92),  INT8_C(  74), -INT8_C( 103), -INT8_C(   1),  INT8_C(  36) },
      {  INT8_C( 120), -INT8_C(  62), -INT8_C(  57),  INT8_C(  67),  INT8_C(  14), -INT8_C(  41),  INT8_C(   3),  INT8_C(  62) },
       INT32_C(           1),
      {  INT32_C(  1277675191), -INT32_C(   224940492) } },
    { { -INT32_C(  1116971910), -INT32_C(    10911585) },
      {  INT8_C(  69),      INT8_MIN,  INT8_C(  75),  INT8_C(  58),  INT8_C(  16), -INT8_C(  30),  INT8_C(  44),  INT8_C(  73) },
      {  INT8_C( 101),  INT8_C(  90), -INT8_C(  19), -INT8_C(  81), -INT8_C(  12), -INT8_C(  20), -INT8_C(  45),  INT8_C( 108) },
       INT32_C(           0),
      { -INT32_C(  1116982584), -INT32_C(    10919418) } },
    { { -INT32_C(  1129342290), -INT32_C(   335891599) },
      {  INT8_C(  15),  INT8_C( 102), -INT8_C(  87), -INT8_C(  82), -INT8_C(  25),  INT8_C(   2), -INT8_C(  83),  INT8_C(  44) },
      { -INT8_C( 126), -INT8_C(   8),  INT8_C( 102), -INT8_C( 110), -INT8_C(  38), -INT8_C( 110), -INT8_C(  37),  INT8_C(  63) },
       INT32_C(           1),
      { -INT32_C(  1129356027), -INT32_C(   335885026) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r_ = simde_vld1_s32(test_vec[i].r_);
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int32x2_t r = simde_vdot_lane_s32(r_, a, b, test_vec[i].lane);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r_ = simde_test_arm_neon_random_i32x2();
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int32x2_t r = simde_vdot_lane_s32(r_, a, b, lanes[i]);

    simde_test_arm_neon_write_i32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdot_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r_[2];
    uint8_t a[8];
    uint8_t b[8];
    const int lane;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2004636215), UINT32_C(1447988795) },
      { UINT8_C(252), UINT8_C( 39), UINT8_C( 82), UINT8_C( 17), UINT8_C(244), UINT8_C(247), UINT8_C( 33), UINT8_C( 22) },
      { UINT8_C(166), UINT8_C(124), UINT8_C(170), UINT8_C(109), UINT8_C(174), UINT8_C( 87), UINT8_C(102), UINT8_C( 37) },
       INT32_C(           0),
      { UINT32_C(2004698676), UINT32_C(1448067935) } },
    { { UINT32_C(1203385153), UINT32_C( 129883856) },
      { UINT8_C( 48), UINT8_C( 58), UINT8_C(127), UINT8_C(107), UINT8_C(200), UINT8_C(205), UINT8_C(193), UINT8_C(196) },
      { UINT8_C(244), UINT8_C( 19), UINT8_C(213), UINT8_C(232), UINT8_C( 10), UINT8_C(247), UINT8_C(254), UINT8_C(177) },
       INT32_C(           1),
      { UINT32_C(1203451156), UINT32_C( 130020205) } },
    { { UINT32_C( 555657587), UINT32_C(1095205888) },
      { UINT8_C(183), UINT8_C(  1), UINT8_C(136), UINT8_C(136), UINT8_C(223), UINT8_C( 70), UINT8_C(143), UINT8_C( 15) },
      { UINT8_C(128), UINT8_C( 14), UINT8_C(123), UINT8_C( 72), UINT8_C(219), UINT8_C( 60), UINT8_C( 12), UINT8_C(207) },
       INT32_C(           0),
      { UINT32_C( 555707545), UINT32_C(1095254081) } },
    { { UINT32_C(1522000208), UINT32_C(1259058904) },
      { UINT8_C( 95), UINT8_C( 41), UINT8_C(109), UINT8_C( 95), UINT8_C(173), UINT8_C(180), UINT8_C(160), UINT8_C(101) },
      { UINT8_C(181), UINT8_C( 40), UINT8_C(237), UINT8_C(149), UINT8_C(110), UINT8_C(124), UINT8_C(164), UINT8_C(238) },
       INT32_C(           1),
      { UINT32_C(1522056228), UINT32_C(1259150532) } },
    { { UINT32_C(1714823051), UINT32_C(2889237084) },
      { UINT8_C( 36), UINT8_C(237), UINT8_C(  6), UINT8_C(252), UINT8_C(163), UINT8_C( 18), UINT8_C( 72), UINT8_C(  2) },
      { UINT8_C( 59), UINT8_C(181), UINT8_C( 97), UINT8_C(233), UINT8_C(105), UINT8_C(  1), UINT8_C( 78), UINT8_C( 30) },
       INT32_C(           0),
      { UINT32_C(1714927370), UINT32_C(2889257409) } },
    { { UINT32_C(2561882922), UINT32_C(1116166327) },
      { UINT8_C(119), UINT8_C(189), UINT8_C(169), UINT8_C(211), UINT8_C(  0), UINT8_C(223), UINT8_C(127), UINT8_C( 36) },
      { UINT8_C(204), UINT8_C(134), UINT8_C( 32), UINT8_C(112), UINT8_C(152), UINT8_C(104), UINT8_C(114), UINT8_C(211) },
       INT32_C(           1),
      { UINT32_C(2561984453), UINT32_C(1116211593) } },
    { { UINT32_C(2260522013), UINT32_C(4289006293) },
      { UINT8_C( 69), UINT8_C( 88), UINT8_C(152), UINT8_C(253), UINT8_C(176), UINT8_C( 31), UINT8_C( 63), UINT8_C( 40) },
      { UINT8_C(220), UINT8_C(232), UINT8_C(251), UINT8_C(220), UINT8_C(199), UINT8_C(123), UINT8_C(  0), UINT8_C(148) },
       INT32_C(           0),
      { UINT32_C(2260651421), UINT32_C(4289076818) } },
    { { UINT32_C(2567184641), UINT32_C(2808903305) },
      { UINT8_C( 74), UINT8_C( 41), UINT8_C( 45), UINT8_C( 32), UINT8_C( 51), UINT8_C(210), UINT8_C( 31), UINT8_C(121) },
      { UINT8_C( 43), UINT8_C(183), UINT8_C(118), UINT8_C(219), UINT8_C(214), UINT8_C(181), UINT8_C(  3), UINT8_C(179) },
       INT32_C(           1),
      { UINT32_C(2567213761), UINT32_C(2808973981) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r_ = simde_vld1_u32(test_vec[i].r_);
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint32x2_t r = simde_vdot_lane_u32(r_, a, b, test_vec[i].lane);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 0, 1, 0, 1, 0, 1 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t r_ = simde_test_arm_neon_random_u32x2();
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint32x2_t r = simde_vdot_lane_u32(r_, a, b, lanes[i]);

    simde_test_arm_neon_write_u32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdot_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[2];
    int8_t a[8];
    int8_t b[16];
    const int lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1265596150),  INT32_C(  1757209770) },
      {  INT8_C(   2), -INT8_C(  13),  INT8_C( 103), -INT8_C(  48),  INT8_C(  83), -INT8_C(  69),  INT8_C(  75), -INT8_C( 110) },
      {  INT8_C(  77), -INT8_C( 127),  INT8_C(  43), -INT8_C( 101),  INT8_C(  73),  INT8_C(  30), -INT8_C( 106),  INT8_C(  50),
        -INT8_C(   7), -INT8_C(  72), -INT8_C( 114),  INT8_C( 102),  INT8_C(  94),  INT8_C( 122),  INT8_C(  21),  INT8_C( 104) },
       INT32_C(           0),
      { -INT32_C(  1265585068),  INT32_C(  1757239259) } },
    { { -INT32_C(  1390566141), -INT32_C(  1944659575) },
      { -INT8_C(  52),  INT8_C( 125),  INT8_C(  92),  INT8_C(  32),  INT8_C(  56), -INT8_C(  89), -INT8_C(  78), -INT8_C( 123) },
      {  INT8_C(  40), -INT8_C(  35),  INT8_C(  32),  INT8_C( 114), -INT8_C(   5), -INT8_C(  74), -INT8_C(  92), -INT8_C(  11),
         INT8_C( 111),  INT8_C(  50),  INT8_C(  91), -INT8_C(  51), -INT8_C(  84),  INT8_C( 112),  INT8_C(  54), -INT8_C(  80) },
       INT32_C(           1),
      { -INT32_C(  1390583947), -INT32_C(  1944644740) } },
    { { -INT32_C(  1621273834), -INT32_C(   131370196) },
      { -INT8_C(  15), -INT8_C( 120),  INT8_C(  24),  INT8_C(  41),  INT8_C(  47), -INT8_C(  53), -INT8_C(  81),  INT8_C(  88) },
      { -INT8_C(  88), -INT8_C(  49), -INT8_C(  54), -INT8_C(  92), -INT8_C( 122),  INT8_C( 110), -INT8_C( 103), -INT8_C(  11),
        -INT8_C(  96), -INT8_C(  12), -INT8_C(  62),  INT8_C(  77),  INT8_C( 100), -INT8_C(   8), -INT8_C(   3),  INT8_C( 122) },
       INT32_C(           2),
      { -INT32_C(  1621269285), -INT32_C(   131362274) } },
    { {  INT32_C(  1998215755), -INT32_C(  1083161138) },
      { -INT8_C(  51), -INT8_C( 120), -INT8_C(  24), -INT8_C(   3),  INT8_C(  83), -INT8_C( 105),  INT8_C(  85), -INT8_C(   4) },
      {  INT8_C( 103),  INT8_C(  31), -INT8_C(  96), -INT8_C(  19), -INT8_C( 115),  INT8_C(  57), -INT8_C(  30),  INT8_C(  45),
         INT8_C(  45), -INT8_C(  92),  INT8_C( 122), -INT8_C( 111), -INT8_C(  99),  INT8_C( 119),  INT8_C(  12), -INT8_C(  24) },
       INT32_C(           3),
      {  INT32_C(  1998206308), -INT32_C(  1083180734) } },
    { { -INT32_C(  1604311342),  INT32_C(   962580587) },
      {  INT8_C(  88),  INT8_C(  71),  INT8_C(  54), -INT8_C(  84), -INT8_C(  33), -INT8_C( 117), -INT8_C(  88),  INT8_C(  70) },
      { -INT8_C(  86),  INT8_C(  72),  INT8_C(  51),  INT8_C(  55), -INT8_C( 127),  INT8_C(  21),  INT8_C( 100), -INT8_C(  82),
        -INT8_C(  71), -INT8_C(  33),  INT8_C(  63),  INT8_C(  86),  INT8_C(  86),  INT8_C(  75),  INT8_C(  63),  INT8_C(  40) },
       INT32_C(           0),
      { -INT32_C(  1604315664),  INT32_C(   962574363) } },
    { { -INT32_C(   574054543), -INT32_C(   954849425) },
      {  INT8_C( 111),  INT8_C(  76),  INT8_C( 115),  INT8_C(  78), -INT8_C(  41),  INT8_C(  27), -INT8_C( 108), -INT8_C( 127) },
      {  INT8_C(  99), -INT8_C(  57), -INT8_C(  72), -INT8_C(  28), -INT8_C(  36),  INT8_C(  28), -INT8_C( 110), -INT8_C( 107),
        -INT8_C(   5), -INT8_C(  46), -INT8_C(  20),  INT8_C(  82),  INT8_C(  29),  INT8_C(  43),  INT8_C( 122), -INT8_C( 113) },
       INT32_C(           1),
      { -INT32_C(   574077407), -INT32_C(   954821724) } },
    { {  INT32_C(   963396554), -INT32_C(   654278038) },
      { -INT8_C(  50),  INT8_C( 116),  INT8_C(  39), -INT8_C(  91), -INT8_C( 113), -INT8_C(  69),  INT8_C(  38), -INT8_C(  13) },
      { -INT8_C( 126), -INT8_C(  34), -INT8_C(  41),  INT8_C(  94), -INT8_C(   6),  INT8_C( 106), -INT8_C(  12), -INT8_C(  10),
         INT8_C(  60), -INT8_C(  32),  INT8_C(  72),  INT8_C(  89),  INT8_C(  11), -INT8_C(  62), -INT8_C(  24), -INT8_C(  43) },
       INT32_C(           2),
      {  INT32_C(   963384551), -INT32_C(   654281031) } },
    { {  INT32_C(  1879987205), -INT32_C(  1538715946) },
      { -INT8_C( 126),  INT8_C( 113),  INT8_C(  73),  INT8_C(  18),  INT8_C(  44),  INT8_C( 111),  INT8_C(   5), -INT8_C(  81) },
      {  INT8_C(  77), -INT8_C(  36),  INT8_C(  13),  INT8_C(  72),  INT8_C(  70),  INT8_C(   1),  INT8_C(  62), -INT8_C( 126),
        -INT8_C(  31), -INT8_C( 122), -INT8_C(  36), -INT8_C(  20),  INT8_C(  72), -INT8_C(  60), -INT8_C(  63),  INT8_C(  78) },
       INT32_C(           3),
      {  INT32_C(  1879968158), -INT32_C(  1538726071) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r_ = simde_vld1_s32(test_vec[i].r_);
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int32x2_t r = simde_vdot_laneq_s32(r_, a, b, test_vec[i].lane);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r_ = simde_test_arm_neon_random_i32x2();
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int32x2_t r = simde_vdot_laneq_s32(r_, a, b, lanes[i]);

    simde_test_arm_neon_write_i32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdot_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r_[4];
    uint8_t a[16];
    uint8_t b[16];
    const int lane;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(4212112153), UINT32_C(2140133093) },
      { UINT8_C(219), UINT8_C( 10), UINT8_C(230), UINT8_C( 71), UINT8_C( 87), UINT8_C( 27), UINT8_C(218), UINT8_C(104) },
      { UINT8_C(119), UINT8_C(112), UINT8_C(148), UINT8_C( 58), UINT8_C(217), UINT8_C(247), UINT8_C(231), UINT8_C( 79),
        UINT8_C(162), UINT8_C(164), UINT8_C( 33), UINT8_C(182), UINT8_C(172), UINT8_C(196), UINT8_C( 77), UINT8_C(197) },
       INT32_C(           0),
      { UINT32_C(4212177492), UINT32_C(2140184766) } },
    { { UINT32_C(1707105408), UINT32_C( 249843507) },
      { UINT8_C( 89), UINT8_C(202), UINT8_C( 85), UINT8_C(177), UINT8_C(229), UINT8_C( 48), UINT8_C( 25), UINT8_C( 92) },
      { UINT8_C(160), UINT8_C(174), UINT8_C(150), UINT8_C(121), UINT8_C(165), UINT8_C(125), UINT8_C(201), UINT8_C( 71),
        UINT8_C( 33), UINT8_C(234), UINT8_C(253), UINT8_C(205), UINT8_C(175), UINT8_C( 75), UINT8_C(146), UINT8_C( 47) },
       INT32_C(           1),
      { UINT32_C(1707174995), UINT32_C( 249898849) } },
    { { UINT32_C(3667153575), UINT32_C(4226381985) },
      { UINT8_C( 66), UINT8_C( 62), UINT8_C(172), UINT8_C( 39), UINT8_C(110), UINT8_C(197), UINT8_C(132), UINT8_C( 14) },
      { UINT8_C(115), UINT8_C( 26), UINT8_C(136), UINT8_C( 25), UINT8_C(152), UINT8_C( 81), UINT8_C( 96), UINT8_C(185),
        UINT8_C( 59), UINT8_C( 94), UINT8_C(135), UINT8_C(234), UINT8_C(169), UINT8_C( 25), UINT8_C( 25), UINT8_C( 80) },
       INT32_C(           2),
      { UINT32_C(3667195643), UINT32_C(4226428089) } },
    { { UINT32_C( 220966252), UINT32_C(1728582693) },
      { UINT8_C( 82), UINT8_C(180), UINT8_C(143), UINT8_C(193), UINT8_C(122), UINT8_C( 19), UINT8_C(207), UINT8_C(237) },
      { UINT8_C( 45), UINT8_C( 87), UINT8_C(  6), UINT8_C(197), UINT8_C(168), UINT8_C(103), UINT8_C(127), UINT8_C(228),
        UINT8_C(197), UINT8_C(  6), UINT8_C(206), UINT8_C(110), UINT8_C( 31), UINT8_C(232), UINT8_C(190), UINT8_C(139) },
       INT32_C(           3),
      { UINT32_C( 221064551), UINT32_C(1728663156) } },
    { { UINT32_C(3147426197), UINT32_C(1344446973) },
      { UINT8_C( 86), UINT8_C(177), UINT8_C( 17), UINT8_C(208), UINT8_C(196), UINT8_C(224), UINT8_C(189), UINT8_C(242) },
      { UINT8_C( 56), UINT8_C(196), UINT8_C(183), UINT8_C(224), UINT8_C( 43), UINT8_C( 54), UINT8_C(196), UINT8_C(240),
        UINT8_C( 60), UINT8_C(147), UINT8_C( 94), UINT8_C( 92), UINT8_C(123), UINT8_C( 28), UINT8_C(231), UINT8_C( 16) },
       INT32_C(           0),
      { UINT32_C(3147515408), UINT32_C(1344590648) } },
    { { UINT32_C(  63668230), UINT32_C(2018766370) },
      { UINT8_C(159), UINT8_C(100), UINT8_C( 72), UINT8_C(100), UINT8_C( 69), UINT8_C(  5), UINT8_C( 86), UINT8_C(125) },
      { UINT8_C(201), UINT8_C( 13), UINT8_C( 93), UINT8_C(244), UINT8_C( 68), UINT8_C( 34), UINT8_C(228), UINT8_C(128),
        UINT8_C(181), UINT8_C( 66), UINT8_C(220), UINT8_C( 48), UINT8_C( 95), UINT8_C(196), UINT8_C( 64), UINT8_C(101) },
       INT32_C(           1),
      { UINT32_C(  63711658), UINT32_C(2018806840) } },
    { { UINT32_C(1718094916), UINT32_C(2581511418) },
      { UINT8_C( 32), UINT8_C( 38), UINT8_C(253), UINT8_C(101), UINT8_C( 44), UINT8_C( 83), UINT8_C(226), UINT8_C(245) },
      { UINT8_C( 97), UINT8_C( 64), UINT8_C(234), UINT8_C(165), UINT8_C( 98), UINT8_C(206), UINT8_C( 37), UINT8_C( 23),
        UINT8_C( 17), UINT8_C(  2), UINT8_C( 71), UINT8_C(112), UINT8_C(198), UINT8_C(135), UINT8_C(213), UINT8_C( 10) },
       INT32_C(           2),
      { UINT32_C(1718124811), UINT32_C(2581555818) } },
    { { UINT32_C(2373008787), UINT32_C( 438783993) },
      { UINT8_C(118), UINT8_C( 36), UINT8_C(127), UINT8_C(162), UINT8_C(120), UINT8_C( 98), UINT8_C(151), UINT8_C(217) },
      { UINT8_C(162), UINT8_C(129), UINT8_C(126), UINT8_C(  4), UINT8_C( 80), UINT8_C(163), UINT8_C( 27), UINT8_C( 97),
        UINT8_C(165), UINT8_C( 98), UINT8_C(209), UINT8_C(107), UINT8_C(233), UINT8_C(166), UINT8_C(118), UINT8_C(125) },
       INT32_C(           3),
      { UINT32_C(2373077493), UINT32_C( 438873164) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r_ = simde_vld1_u32(test_vec[i].r_);
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint32x2_t r = simde_vdot_laneq_u32(r_, a, b, test_vec[i].lane);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int lanes[] = { 0, 1, 2, 3, 0, 1, 2, 3 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t r_ = simde_test_arm_neon_random_u32x2();
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint32x2_t r = simde_vdot_laneq_u32(r_, a, b, lanes[i]);

    simde_test_arm_neon_write_u32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lanes[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vdot_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdot_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vdot_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdot_laneq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
