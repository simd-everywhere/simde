#define SIMDE_TEST_ARM_NEON_INSN dot

#include "test-neon.h"
#include "../../../simde/arm/neon/dot.h"


static int
test_simde_vdot_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int8_t b[8];
    int8_t c[8];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1524632456), -INT32_C(  1298408979) },
      { -INT8_C(  30), -INT8_C(   3), -INT8_C(  60), -INT8_C(  69), -INT8_C(  89), -INT8_C(  80),  INT8_C( 120),  INT8_C( 114) },
      {  INT8_C(  37), -INT8_C(  73), -INT8_C(  19), -INT8_C(  21), -INT8_C(  48), -INT8_C(  53),  INT8_C(  61),  INT8_C(  79) },
      {  INT32_C(  1524634154), -INT32_C(  1298384141) } },
    { { -INT32_C(  1634669294),  INT32_C(  1359806665) },
      {  INT8_C(  12), -INT8_C(  19), -INT8_C(  85), -INT8_C(   7), -INT8_C(  57),  INT8_C(  70), -INT8_C(  84), -INT8_C(  87) },
      {  INT8_C(  68),  INT8_C( 112),  INT8_C( 100), -INT8_C(  21),  INT8_C(  32), -INT8_C(  35),  INT8_C(  94),  INT8_C(  69) },
      { -INT32_C(  1634678959),  INT32_C(  1359788492) } },
    { {  INT32_C(  1680952212),  INT32_C(   699624983) },
      {  INT8_C(  91),  INT8_C(  68), -INT8_C(  57),  INT8_C(  36),  INT8_C(  68), -INT8_C(  44),  INT8_C( 117),  INT8_C(  80) },
      { -INT8_C(  62),  INT8_C(  32),  INT8_C(  74), -INT8_C( 119),  INT8_C( 103), -INT8_C(  10),  INT8_C(  50), -INT8_C(  85) },
      {  INT32_C(  1680940244),  INT32_C(   699631477) } },
    { { -INT32_C(  2036951450),  INT32_C(   147649651) },
      {  INT8_C(  64), -INT8_C(   3),  INT8_C( 108),  INT8_C(  87),  INT8_C( 107),  INT8_C(  32),      INT8_MIN, -INT8_C(  58) },
      {  INT8_C( 100),  INT8_C(  71), -INT8_C(  22), -INT8_C(  88),  INT8_C(  28),  INT8_C(  95), -INT8_C(   7), -INT8_C(  34) },
      { -INT32_C(  2036955295),  INT32_C(   147658555) } },
    { { -INT32_C(   429440129), -INT32_C(  1617848007) },
      {  INT8_C(  47),  INT8_C(  40),  INT8_C(  37), -INT8_C(  93),  INT8_C(  28), -INT8_C(  15), -INT8_C(  85),  INT8_C(  92) },
      { -INT8_C(  18),  INT8_C(  23), -INT8_C(  77),  INT8_C(  89),  INT8_C(  55),  INT8_C(  51),  INT8_C(  31), -INT8_C( 101) },
      { -INT32_C(   429451181), -INT32_C(  1617859159) } },
    { { -INT32_C(  1757148805), -INT32_C(   394969752) },
      {      INT8_MIN, -INT8_C(  36), -INT8_C(  50), -INT8_C(  71),  INT8_C( 117),  INT8_C(  96),  INT8_C(  88), -INT8_C(  92) },
      { -INT8_C( 120),  INT8_C( 125),  INT8_C(  71), -INT8_C(  92),  INT8_C( 111), -INT8_C(  14),  INT8_C(   1),  INT8_C(  93) },
      { -INT32_C(  1757134963), -INT32_C(   394966577) } },
    { {  INT32_C(  1102558218),  INT32_C(  1675482856) },
      { -INT8_C(  32),  INT8_C(  33), -INT8_C(   6),  INT8_C(  72),  INT8_C(  94),  INT8_C( 111),  INT8_C(  48), -INT8_C(  34) },
      {  INT8_C(  75), -INT8_C(   1), -INT8_C( 105), -INT8_C(  64),  INT8_C(  95), -INT8_C(  17),  INT8_C( 100), -INT8_C(  25) },
      {  INT32_C(  1102551807),  INT32_C(  1675495549) } },
    { { -INT32_C(   611603348), -INT32_C(  1472623458) },
      {  INT8_C(  65), -INT8_C(  16), -INT8_C(  22),  INT8_C(  41), -INT8_C(  58), -INT8_C(  57), -INT8_C( 116), -INT8_C(  90) },
      { -INT8_C(  24), -INT8_C( 122), -INT8_C(  17),  INT8_C(  70), -INT8_C(  11),  INT8_C(  31),  INT8_C(  36),  INT8_C(  64) },
      { -INT32_C(   611599712), -INT32_C(  1472634523) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t c = simde_vld1_s8(test_vec[i].c);
    simde_int32x2_t r = simde_vdot_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t c = simde_test_arm_neon_random_i8x8();
    simde_int32x2_t r = simde_vdot_s32(a, b, c);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdot_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint8_t b[8];
    uint8_t c[8];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 655185567), UINT32_C(3897459723) },
      { UINT8_C( 18), UINT8_C(121), UINT8_C( 22), UINT8_C(155), UINT8_C(163), UINT8_C( 40), UINT8_C(139), UINT8_C(130) },
      { UINT8_C(158), UINT8_C(120), UINT8_C( 42), UINT8_C(195), UINT8_C( 75), UINT8_C( 33), UINT8_C(233), UINT8_C(110) },
      { UINT32_C( 655234080), UINT32_C(3897519955) } },
    { { UINT32_C(  62151472), UINT32_C(2215003365) },
      { UINT8_C(155), UINT8_C( 19), UINT8_C(171), UINT8_C(166), UINT8_C(152), UINT8_C(250), UINT8_C(142), UINT8_C(170) },
      { UINT8_C(115), UINT8_C(165), UINT8_C( 70), UINT8_C( 22), UINT8_C(205), UINT8_C(209), UINT8_C(152), UINT8_C(107) },
      { UINT32_C(  62188054), UINT32_C(2215126549) } },
    { { UINT32_C(2486092361), UINT32_C( 335747299) },
      { UINT8_C(115), UINT8_C(183), UINT8_C( 23), UINT8_C( 88), UINT8_C(251), UINT8_C( 29), UINT8_C(221), UINT8_C(150) },
      { UINT8_C( 49), UINT8_C(136), UINT8_C( 60), UINT8_C(201), UINT8_C(130), UINT8_C(203), UINT8_C(115), UINT8_C(246) },
      { UINT32_C(2486141952), UINT32_C( 335848131) } },
    { { UINT32_C(1024244080), UINT32_C(3567887755) },
      { UINT8_C(103), UINT8_C(215), UINT8_C(105), UINT8_C( 75), UINT8_C(239), UINT8_C(108), UINT8_C( 95), UINT8_C( 99) },
      { UINT8_C( 35), UINT8_C(118), UINT8_C(187), UINT8_C( 30), UINT8_C(148), UINT8_C(152), UINT8_C(181), UINT8_C(197) },
      { UINT32_C(1024294940), UINT32_C(3567976241) } },
    { { UINT32_C(2744054049), UINT32_C( 748224956) },
      { UINT8_C(187), UINT8_C(166), UINT8_C(106), UINT8_C( 70), UINT8_C( 75), UINT8_C( 19), UINT8_C( 26), UINT8_C(178) },
      { UINT8_C(234), UINT8_C(131), UINT8_C(253), UINT8_C(218), UINT8_C(239), UINT8_C( 92), UINT8_C( 61), UINT8_C( 18) },
      { UINT32_C(2744161631), UINT32_C( 748249419) } },
    { { UINT32_C(1731328211), UINT32_C(2989287057) },
      { UINT8_C(215), UINT8_C(186), UINT8_C( 85), UINT8_C(148), UINT8_C(187), UINT8_C(239), UINT8_C(192), UINT8_C(118) },
      { UINT8_C(149), UINT8_C( 42), UINT8_C(188), UINT8_C(224), UINT8_C( 61), UINT8_C(215), UINT8_C(146), UINT8_C( 40) },
      { UINT32_C(1731417190), UINT32_C(2989382601) } },
    { { UINT32_C(1241682010), UINT32_C(3210493932) },
      { UINT8_C( 55), UINT8_C(141), UINT8_C( 38), UINT8_C(200), UINT8_C(115), UINT8_C( 82), UINT8_C(122), UINT8_C( 75) },
      { UINT8_C( 12), UINT8_C(208), UINT8_C(223), UINT8_C(200), UINT8_C(191), UINT8_C(159), UINT8_C( 62), UINT8_C( 84) },
      { UINT32_C(1241760472), UINT32_C(3210542799) } },
    { { UINT32_C( 120912842), UINT32_C( 741328594) },
      { UINT8_C( 86), UINT8_C( 49), UINT8_C(118), UINT8_C( 67), UINT8_C(112), UINT8_C(211), UINT8_C(  2), UINT8_C(168) },
      { UINT8_C( 96), UINT8_C( 41), UINT8_C(112), UINT8_C(212), UINT8_C(123), UINT8_C(235), UINT8_C( 31), UINT8_C(136) },
      { UINT32_C( 120950527), UINT32_C( 741414865) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t c = simde_vld1_u8(test_vec[i].c);
    simde_uint32x2_t r = simde_vdot_u32(a, b, c);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t c = simde_test_arm_neon_random_u8x8();
    simde_uint32x2_t r = simde_vdot_u32(a, b, c);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdotq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int8_t b[16];
    int8_t c[16];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1315274814),  INT32_C(  1813013239), -INT32_C(   878005830),  INT32_C(   996395424) },
      { -INT8_C(  46), -INT8_C(  66),  INT8_C(  35), -INT8_C( 112), -INT8_C(  26), -INT8_C(  23), -INT8_C(  99), -INT8_C(  11),
        -INT8_C(  89),  INT8_C(  77), -INT8_C(  31), -INT8_C(  32), -INT8_C(  24),  INT8_C(  93), -INT8_C( 104), -INT8_C(  86) },
      { -INT8_C(  36),  INT8_C(  50),  INT8_C(  91), -INT8_C(  45), -INT8_C( 107),  INT8_C( 107),  INT8_C(  63),  INT8_C(  79),
         INT8_C(  28), -INT8_C(  22),  INT8_C(  26), -INT8_C(  68), -INT8_C(  77),  INT8_C( 125), -INT8_C(   8), -INT8_C( 123) },
      { -INT32_C(  1315268233),  INT32_C(  1813006454), -INT32_C(   878008646),  INT32_C(   996420307) } },
    { {  INT32_C(   555031355), -INT32_C(  1424575996), -INT32_C(   410257409),  INT32_C(   831595604) },
      {  INT8_C(  86), -INT8_C(  19),  INT8_C(   4), -INT8_C(  21),  INT8_C(  88),  INT8_C(  68),  INT8_C(  58),  INT8_C( 117),
         INT8_C(  46),  INT8_C(  84),  INT8_C(  49), -INT8_C(  31), -INT8_C(  47),  INT8_C(  41),  INT8_C( 102),  INT8_C(  13) },
      {  INT8_C(  68),  INT8_C( 123),  INT8_C(  46),  INT8_C(  72),  INT8_C(  45),  INT8_C(  69), -INT8_C(  13),  INT8_C(  45),
         INT8_C(  60),      INT8_MAX,  INT8_C(  20), -INT8_C( 111), -INT8_C(  93), -INT8_C(  90), -INT8_C(  62), -INT8_C(   7) },
      {  INT32_C(   555033538), -INT32_C(  1424562833), -INT32_C(   410239560),  INT32_C(   831589870) } },
    { { -INT32_C(   337262957),  INT32_C(   945823498),  INT32_C(  1159303796),  INT32_C(     5406651) },
      { -INT8_C(   6), -INT8_C( 127),  INT8_C(  72),  INT8_C(  40), -INT8_C(  58),  INT8_C(  60),  INT8_C(  85),  INT8_C(   2),
        -INT8_C(  69),  INT8_C( 105), -INT8_C( 109),  INT8_C(  94),  INT8_C(  15),  INT8_C(  85),  INT8_C(  87), -INT8_C(  94) },
      {  INT8_C(  28),  INT8_C(  60), -INT8_C( 114),  INT8_C(  38),  INT8_C(  92), -INT8_C(  18),  INT8_C(  95), -INT8_C(  48),
             INT8_MIN,  INT8_C( 120),  INT8_C(  21),  INT8_C(  60), -INT8_C(   8),  INT8_C( 104),  INT8_C(  60), -INT8_C(  14) },
      { -INT32_C(   337277433),  INT32_C(   945825061),  INT32_C(  1159328579),  INT32_C(     5421907) } },
    { { -INT32_C(  1357216535),  INT32_C(  2075226048), -INT32_C(   388413991), -INT32_C(  1232391782) },
      {  INT8_C( 109),  INT8_C(  25), -INT8_C(  35), -INT8_C(  55),  INT8_C(   7),  INT8_C(  60), -INT8_C( 103), -INT8_C( 120),
        -INT8_C(  76), -INT8_C(  81), -INT8_C(  60), -INT8_C(  84),  INT8_C(  23),  INT8_C(   0), -INT8_C(  97),  INT8_C(   0) },
      { -INT8_C( 124), -INT8_C(  71), -INT8_C(  81),  INT8_C(  69),  INT8_C(  41),  INT8_C(  96), -INT8_C(  64),  INT8_C(   2),
        -INT8_C(  91), -INT8_C( 102), -INT8_C(  22),  INT8_C(  64), -INT8_C(  53),  INT8_C( 117), -INT8_C(  10),  INT8_C(  56) },
      { -INT32_C(  1357232786),  INT32_C(  2075238447), -INT32_C(   388402869), -INT32_C(  1232392031) } },
    { { -INT32_C(  1778199666), -INT32_C(  1004627185),  INT32_C(  1634787914),  INT32_C(  1717637090) },
      { -INT8_C(  55),  INT8_C(  16), -INT8_C(  85), -INT8_C(  14),  INT8_C( 113),  INT8_C( 108), -INT8_C(  12),  INT8_C(  22),
         INT8_C(   6), -INT8_C(  34),  INT8_C(  86), -INT8_C(  47),  INT8_C(  84),  INT8_C(  77),  INT8_C(   9), -INT8_C(  30) },
      {  INT8_C(  32),  INT8_C(  11),  INT8_C( 120),  INT8_C(  48), -INT8_C(  89), -INT8_C( 106), -INT8_C(  12), -INT8_C(  15),
         INT8_C( 120),  INT8_C( 100),  INT8_C(  83),  INT8_C(  90),  INT8_C( 116), -INT8_C(  76), -INT8_C(  63),  INT8_C(  61) },
      { -INT32_C(  1778212122), -INT32_C(  1004648876),  INT32_C(  1634788142),  INT32_C(  1717638585) } },
    { {  INT32_C(   909077701), -INT32_C(   565435432),  INT32_C(  1437573889),  INT32_C(   272153072) },
      { -INT8_C(  60), -INT8_C(  80),  INT8_C(  64),  INT8_C( 107),  INT8_C(  71),  INT8_C(  52),  INT8_C(  93), -INT8_C(  65),
        -INT8_C( 103), -INT8_C(  80),  INT8_C(  26),  INT8_C(  13),  INT8_C( 100), -INT8_C(  37),  INT8_C(  74),  INT8_C(  41) },
      {  INT8_C(  71),  INT8_C( 121),  INT8_C(  95),  INT8_C(  32), -INT8_C( 100), -INT8_C(  84), -INT8_C(   2), -INT8_C(  99),
         INT8_C(  79), -INT8_C(  82), -INT8_C(  13),  INT8_C(  63),  INT8_C( 103),  INT8_C(  43),  INT8_C(  79),  INT8_C(  43) },
      {  INT32_C(   909073265), -INT32_C(   565440651),  INT32_C(  1437572793),  INT32_C(   272169390) } },
    { {  INT32_C(   580358363),  INT32_C(  1575154884),  INT32_C(   141229220),  INT32_C(   506639575) },
      {  INT8_C(  45), -INT8_C( 111),  INT8_C(  62), -INT8_C(  55),  INT8_C(  61),  INT8_C(  61),  INT8_C( 103), -INT8_C( 116),
        -INT8_C(  21),  INT8_C(  90), -INT8_C(  53),  INT8_C(  82), -INT8_C( 123),  INT8_C(  27),  INT8_C( 125),  INT8_C(  96) },
      { -INT8_C(  85),  INT8_C(  20), -INT8_C( 125),  INT8_C( 111),  INT8_C(   8),  INT8_C( 101), -INT8_C(  51), -INT8_C(  84),
         INT8_C(  97),  INT8_C(  55), -INT8_C(  75),  INT8_C(  56), -INT8_C(  20), -INT8_C(  25),  INT8_C(  86),  INT8_C(  25) },
      {  INT32_C(   580338463),  INT32_C(  1575166024),  INT32_C(   141240700),  INT32_C(   506654510) } },
    { { -INT32_C(  1226599048), -INT32_C(  1119728942),  INT32_C(   688852644), -INT32_C(   729183191) },
      { -INT8_C(  95),  INT8_C(  12),  INT8_C(  67), -INT8_C(  87),  INT8_C( 113),  INT8_C(  16),  INT8_C(  86), -INT8_C(  46),
         INT8_C(  72),  INT8_C(  11),  INT8_C(  10),  INT8_C(  52), -INT8_C(  14),  INT8_C(  97),  INT8_C(  77),  INT8_C( 106) },
      { -INT8_C(  10),  INT8_C(  48),  INT8_C(  32), -INT8_C(  56),  INT8_C( 122),  INT8_C(  99), -INT8_C( 123),  INT8_C(  30),
         INT8_C( 113), -INT8_C( 108),  INT8_C(  71), -INT8_C( 102),  INT8_C(  32), -INT8_C(  47),  INT8_C( 110), -INT8_C(  63) },
      { -INT32_C(  1226590506), -INT32_C(  1119725530),  INT32_C(   688854998), -INT32_C(   729186406) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t c = simde_vld1q_s8(test_vec[i].c);
    simde_int32x4_t r = simde_vdotq_s32(a, b, c);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t c = simde_test_arm_neon_random_i8x16();
    simde_int32x4_t r = simde_vdotq_s32(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdotq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint8_t b[16];
    uint8_t c[16];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3976885184), UINT32_C(3561508868), UINT32_C(3970367447), UINT32_C(3484184309) },
      { UINT8_C(194),    UINT8_MAX, UINT8_C(199), UINT8_C(164), UINT8_C(174), UINT8_C( 27), UINT8_C(152), UINT8_C(196),
        UINT8_C(143), UINT8_C(127), UINT8_C(127), UINT8_C(229), UINT8_C( 80), UINT8_C(  0), UINT8_C(146), UINT8_C( 16) },
      { UINT8_C(116), UINT8_C(157), UINT8_C(254), UINT8_C(120), UINT8_C(237), UINT8_C( 70), UINT8_C( 76), UINT8_C(196),
        UINT8_C( 69), UINT8_C(243), UINT8_C(176), UINT8_C( 58), UINT8_C( 97), UINT8_C( 92), UINT8_C( 10), UINT8_C( 36) },
      { UINT32_C(3977017949), UINT32_C(3561601964), UINT32_C(3970443809), UINT32_C(3484194105) } },
    { { UINT32_C( 180932956), UINT32_C(2093965549), UINT32_C( 811749087), UINT32_C(3259036750) },
      { UINT8_C(145), UINT8_C( 62), UINT8_C( 58), UINT8_C(126), UINT8_C(133), UINT8_C(135), UINT8_C( 67), UINT8_C(202),
        UINT8_C(122), UINT8_C(243), UINT8_C(  5), UINT8_C(219), UINT8_C( 80), UINT8_C( 15),    UINT8_MAX, UINT8_C(172) },
      { UINT8_C(224), UINT8_C(200), UINT8_C(182), UINT8_C(205), UINT8_C( 40), UINT8_C(133), UINT8_C( 74), UINT8_C(  8),
        UINT8_C(211), UINT8_C(172), UINT8_C( 56), UINT8_C( 34), UINT8_C(160), UINT8_C(120), UINT8_C(228), UINT8_C( 50) },
      { UINT32_C( 181014222), UINT32_C(2093995398), UINT32_C( 811824351), UINT32_C(3259118090) } },
    { { UINT32_C(1018175415), UINT32_C( 537326502), UINT32_C( 939199463), UINT32_C(4226022170) },
      { UINT8_C(195), UINT8_C(153), UINT8_C(200), UINT8_C(235), UINT8_C( 31), UINT8_C( 18), UINT8_C(243), UINT8_C(242),
        UINT8_C(190), UINT8_C( 43), UINT8_C( 20), UINT8_C( 95), UINT8_C(164), UINT8_C(249), UINT8_C(145), UINT8_C( 91) },
      { UINT8_C( 24), UINT8_C( 65), UINT8_C(151), UINT8_C(190), UINT8_C( 53), UINT8_C(157), UINT8_C(222), UINT8_C( 28),
        UINT8_C(169), UINT8_C(217), UINT8_C( 83), UINT8_C(195), UINT8_C(212), UINT8_C( 54), UINT8_C(190), UINT8_C(151) },
      { UINT32_C(1018264890), UINT32_C( 537391693), UINT32_C( 939261089), UINT32_C(4226111675) } },
    { { UINT32_C(4001597391), UINT32_C(1491170969), UINT32_C(1186461090), UINT32_C( 111233262) },
      { UINT8_C(137), UINT8_C( 56), UINT8_C(196), UINT8_C(190), UINT8_C(213), UINT8_C(162), UINT8_C(218), UINT8_C(126),
        UINT8_C(124), UINT8_C( 45), UINT8_C( 66), UINT8_C( 80), UINT8_C( 99), UINT8_C(  0), UINT8_C(232), UINT8_C( 51) },
      { UINT8_C(135), UINT8_C(107), UINT8_C( 33), UINT8_C( 33), UINT8_C(225), UINT8_C(  2), UINT8_C(121), UINT8_C(131),
        UINT8_C(248), UINT8_C( 48), UINT8_C(201), UINT8_C(230), UINT8_C(120), UINT8_C(106), UINT8_C(237), UINT8_C(  1) },
      { UINT32_C(4001634616), UINT32_C(1491262102), UINT32_C(1186525668), UINT32_C( 111300177) } },
    { { UINT32_C(2025894306), UINT32_C(3505822292), UINT32_C( 723531976), UINT32_C(3227387961) },
      { UINT8_C(115), UINT8_C(128), UINT8_C(225), UINT8_C( 85), UINT8_C(130), UINT8_C( 90), UINT8_C(216), UINT8_C(122),
        UINT8_C(138), UINT8_C(162), UINT8_C( 97), UINT8_C(  2), UINT8_C( 12), UINT8_C( 78), UINT8_C(  4), UINT8_C(175) },
      {    UINT8_MAX, UINT8_C(196), UINT8_C( 39), UINT8_C( 83), UINT8_C( 94), UINT8_C( 29), UINT8_C( 35), UINT8_C( 38),
        UINT8_C( 86), UINT8_C( 68), UINT8_C( 82), UINT8_C(143), UINT8_C( 76), UINT8_C(176), UINT8_C( 79), UINT8_C(192) },
      { UINT32_C(2025964549), UINT32_C(3505849318), UINT32_C( 723563100), UINT32_C(3227436517) } },
    { { UINT32_C(3004510512), UINT32_C( 372108683), UINT32_C(2618855055), UINT32_C(3695910108) },
      { UINT8_C(224), UINT8_C(114), UINT8_C( 47), UINT8_C( 63), UINT8_C(143), UINT8_C( 83), UINT8_C(101), UINT8_C(229),
        UINT8_C(151), UINT8_C(183), UINT8_C(116), UINT8_C(227), UINT8_C(104), UINT8_C(196), UINT8_C(163), UINT8_C(152) },
      { UINT8_C(245), UINT8_C(184), UINT8_C( 75), UINT8_C(128), UINT8_C(166), UINT8_C(121), UINT8_C(150), UINT8_C( 53),
        UINT8_C(  7), UINT8_C(175), UINT8_C(209), UINT8_C(228), UINT8_C(203), UINT8_C( 28), UINT8_C(192), UINT8_C(172) },
      { UINT32_C(3004597957), UINT32_C( 372169751), UINT32_C(2618964137), UINT32_C(3695994148) } },
    { { UINT32_C( 518778766), UINT32_C(3640873026), UINT32_C(1891465224), UINT32_C( 822632508) },
      { UINT8_C( 25), UINT8_C( 84), UINT8_C(177), UINT8_C(191), UINT8_C(205), UINT8_C( 72), UINT8_C(244), UINT8_C(212),
        UINT8_C(247), UINT8_C(198), UINT8_C(184), UINT8_C(194), UINT8_C(226), UINT8_C(120), UINT8_C(110), UINT8_C(113) },
      { UINT8_C(104), UINT8_C( 89), UINT8_C(143), UINT8_C(170), UINT8_C(170), UINT8_C(146), UINT8_C(132), UINT8_C(178),
        UINT8_C( 10), UINT8_C( 65), UINT8_C( 34), UINT8_C( 70), UINT8_C(161), UINT8_C( 42), UINT8_C(119), UINT8_C(186) },
      { UINT32_C( 518846623), UINT32_C(3640988332), UINT32_C(1891500400), UINT32_C( 822708042) } },
    { { UINT32_C(1266231678), UINT32_C(1746955889), UINT32_C( 371906612), UINT32_C(3112671569) },
      { UINT8_C(242), UINT8_C( 22), UINT8_C( 99), UINT8_C(156), UINT8_C(169), UINT8_C(231), UINT8_C( 78), UINT8_C(179),
        UINT8_C( 40), UINT8_C(112), UINT8_C(250), UINT8_C(202), UINT8_C(155), UINT8_C(113), UINT8_C(132), UINT8_C( 25) },
      { UINT8_C(154), UINT8_C(254), UINT8_C(101), UINT8_C( 11), UINT8_C(108), UINT8_C(133), UINT8_C(115), UINT8_C(160),
        UINT8_C( 93), UINT8_C(158), UINT8_C(182), UINT8_C(174), UINT8_C( 55), UINT8_C( 62), UINT8_C(103), UINT8_C( 41) },
      { UINT32_C(1266286249), UINT32_C(1747042474), UINT32_C( 372008676), UINT32_C(3112701721) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t c = simde_vld1q_u8(test_vec[i].c);
    simde_uint32x4_t r = simde_vdotq_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t c = simde_test_arm_neon_random_u8x16();
    simde_uint32x4_t r = simde_vdotq_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vdot_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdot_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vdotq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdotq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
