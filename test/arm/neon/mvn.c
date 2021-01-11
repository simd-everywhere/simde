#define SIMDE_TEST_ARM_NEON_INSN mvn

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/mvn.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vmvn_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  27),  INT8_C(   6),  INT8_C(  75),  INT8_C( 101),  INT8_C(   8), -INT8_C(  12), -INT8_C(   2),  INT8_C(  29) },
      { -INT8_C(  28), -INT8_C(   7), -INT8_C(  76), -INT8_C( 102), -INT8_C(   9),  INT8_C(  11),  INT8_C(   1), -INT8_C(  30) } },
    { {  INT8_C(  81), -INT8_C(  96), -INT8_C(  60),  INT8_C(  86), -INT8_C(  57),  INT8_C(  42), -INT8_C(  34), -INT8_C(  29) },
      { -INT8_C(  82),  INT8_C(  95),  INT8_C(  59), -INT8_C(  87),  INT8_C(  56), -INT8_C(  43),  INT8_C(  33),  INT8_C(  28) } },
    { {  INT8_C( 120),  INT8_C(  82), -INT8_C(  78),  INT8_C(  74), -INT8_C( 126),  INT8_C( 123),  INT8_C(  26),  INT8_C(  61) },
      { -INT8_C( 121), -INT8_C(  83),  INT8_C(  77), -INT8_C(  75),  INT8_C( 125), -INT8_C( 124), -INT8_C(  27), -INT8_C(  62) } },
    { { -INT8_C( 113),  INT8_C( 122), -INT8_C(  79), -INT8_C(  94), -INT8_C(  16),  INT8_C(  93), -INT8_C(  97),  INT8_C(  11) },
      {  INT8_C( 112), -INT8_C( 123),  INT8_C(  78),  INT8_C(  93),  INT8_C(  15), -INT8_C(  94),  INT8_C(  96), -INT8_C(  12) } },
    { {  INT8_C(  99), -INT8_C(  21),  INT8_C( 112),  INT8_C( 107), -INT8_C(  33),  INT8_C( 111), -INT8_C( 120),  INT8_C(  48) },
      { -INT8_C( 100),  INT8_C(  20), -INT8_C( 113), -INT8_C( 108),  INT8_C(  32), -INT8_C( 112),  INT8_C( 119), -INT8_C(  49) } },
    { {  INT8_C(  15),  INT8_C(  76), -INT8_C( 122), -INT8_C(  42),  INT8_C( 118),  INT8_C( 100), -INT8_C(  71), -INT8_C(  17) },
      { -INT8_C(  16), -INT8_C(  77),  INT8_C( 121),  INT8_C(  41), -INT8_C( 119), -INT8_C( 101),  INT8_C(  70),  INT8_C(  16) } },
    { { -INT8_C(  74),  INT8_C( 107),  INT8_C(  57),  INT8_C(  57), -INT8_C(  26),  INT8_C(  83),  INT8_C( 118),  INT8_C( 117) },
      {  INT8_C(  73), -INT8_C( 108), -INT8_C(  58), -INT8_C(  58),  INT8_C(  25), -INT8_C(  84), -INT8_C( 119), -INT8_C( 118) } },
    { { -INT8_C(  51),  INT8_C(  39),  INT8_C(  23), -INT8_C(  67), -INT8_C( 124), -INT8_C(  73), -INT8_C(  55), -INT8_C(  25) },
      {  INT8_C(  50), -INT8_C(  40), -INT8_C(  24),  INT8_C(  66),  INT8_C( 123),  INT8_C(  72),  INT8_C(  54),  INT8_C(  24) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vmvn_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vmvn_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvn_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(  3761),  INT16_C(  8161), -INT16_C( 11229),  INT16_C( 25212) },
      { -INT16_C(  3762), -INT16_C(  8162),  INT16_C( 11228), -INT16_C( 25213) } },
    { {  INT16_C( 17586),  INT16_C( 20930), -INT16_C( 21449),  INT16_C(  5279) },
      { -INT16_C( 17587), -INT16_C( 20931),  INT16_C( 21448), -INT16_C(  5280) } },
    { { -INT16_C(  1840), -INT16_C(  4596), -INT16_C( 25181),  INT16_C(  2074) },
      {  INT16_C(  1839),  INT16_C(  4595),  INT16_C( 25180), -INT16_C(  2075) } },
    { { -INT16_C( 28742), -INT16_C(  7187), -INT16_C( 21198), -INT16_C(  7217) },
      {  INT16_C( 28741),  INT16_C(  7186),  INT16_C( 21197),  INT16_C(  7216) } },
    { { -INT16_C( 20293), -INT16_C(  8702),  INT16_C( 32388),  INT16_C( 13889) },
      {  INT16_C( 20292),  INT16_C(  8701), -INT16_C( 32389), -INT16_C( 13890) } },
    { {  INT16_C(   962), -INT16_C(  1656),  INT16_C( 10159),  INT16_C( 32526) },
      { -INT16_C(   963),  INT16_C(  1655), -INT16_C( 10160), -INT16_C( 32527) } },
    { {  INT16_C(  6687), -INT16_C( 15763), -INT16_C( 30792),  INT16_C( 29386) },
      { -INT16_C(  6688),  INT16_C( 15762),  INT16_C( 30791), -INT16_C( 29387) } },
    { { -INT16_C( 18665),  INT16_C( 18773),  INT16_C(  9316),  INT16_C(  7980) },
      {  INT16_C( 18664), -INT16_C( 18774), -INT16_C(  9317), -INT16_C(  7981) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vmvn_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vmvn_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvn_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   793763496),  INT32_C(  1077145611) },
      { -INT32_C(   793763497), -INT32_C(  1077145612) } },
    { { -INT32_C(   223545418), -INT32_C(  1691633505) },
      {  INT32_C(   223545417),  INT32_C(  1691633504) } },
    { { -INT32_C(   705535259),  INT32_C(   702757249) },
      {  INT32_C(   705535258), -INT32_C(   702757250) } },
    { {  INT32_C(   332262688),  INT32_C(   461678451) },
      { -INT32_C(   332262689), -INT32_C(   461678452) } },
    { { -INT32_C(  1857367162),  INT32_C(  2060549571) },
      {  INT32_C(  1857367161), -INT32_C(  2060549572) } },
    { {  INT32_C(   325877108),  INT32_C(   464426805) },
      { -INT32_C(   325877109), -INT32_C(   464426806) } },
    { {  INT32_C(  2079367417), -INT32_C(   106638119) },
      { -INT32_C(  2079367418),  INT32_C(   106638118) } },
    { {  INT32_C(   873296577), -INT32_C(  1622175463) },
      { -INT32_C(   873296578),  INT32_C(  1622175462) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t r = simde_vmvn_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vmvn_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvn_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(245), UINT8_C(228), UINT8_C( 41), UINT8_C( 86), UINT8_C(199), UINT8_C(240), UINT8_C( 66), UINT8_C( 39) },
      { UINT8_C( 10), UINT8_C( 27), UINT8_C(214), UINT8_C(169), UINT8_C( 56), UINT8_C( 15), UINT8_C(189), UINT8_C(216) } },
    { { UINT8_C(222), UINT8_C(231), UINT8_C(111), UINT8_C( 66), UINT8_C(118), UINT8_C(193), UINT8_C( 32), UINT8_C( 66) },
      { UINT8_C( 33), UINT8_C( 24), UINT8_C(144), UINT8_C(189), UINT8_C(137), UINT8_C( 62), UINT8_C(223), UINT8_C(189) } },
    { { UINT8_C(126), UINT8_C( 35), UINT8_C(233), UINT8_C(186), UINT8_C( 84), UINT8_C( 74), UINT8_C( 40), UINT8_C(224) },
      { UINT8_C(129), UINT8_C(220), UINT8_C( 22), UINT8_C( 69), UINT8_C(171), UINT8_C(181), UINT8_C(215), UINT8_C( 31) } },
    { { UINT8_C(236), UINT8_C( 39), UINT8_C( 71), UINT8_C(236), UINT8_C( 45), UINT8_C(106), UINT8_C( 15), UINT8_C( 35) },
      { UINT8_C( 19), UINT8_C(216), UINT8_C(184), UINT8_C( 19), UINT8_C(210), UINT8_C(149), UINT8_C(240), UINT8_C(220) } },
    { { UINT8_C( 79), UINT8_C( 57), UINT8_C(121), UINT8_C( 22), UINT8_C( 41), UINT8_C(187), UINT8_C( 61), UINT8_C(  7) },
      { UINT8_C(176), UINT8_C(198), UINT8_C(134), UINT8_C(233), UINT8_C(214), UINT8_C( 68), UINT8_C(194), UINT8_C(248) } },
    { { UINT8_C(162), UINT8_C(173), UINT8_C( 73), UINT8_C( 24), UINT8_C(110), UINT8_C(106), UINT8_C( 91), UINT8_C(236) },
      { UINT8_C( 93), UINT8_C( 82), UINT8_C(182), UINT8_C(231), UINT8_C(145), UINT8_C(149), UINT8_C(164), UINT8_C( 19) } },
    { { UINT8_C(141), UINT8_C( 68), UINT8_C(167), UINT8_C(225), UINT8_C(143), UINT8_C(207), UINT8_C(193), UINT8_C(123) },
      { UINT8_C(114), UINT8_C(187), UINT8_C( 88), UINT8_C( 30), UINT8_C(112), UINT8_C( 48), UINT8_C( 62), UINT8_C(132) } },
    { { UINT8_C(246), UINT8_C(  9), UINT8_C(103), UINT8_C( 36), UINT8_C(115), UINT8_C(118), UINT8_C( 71), UINT8_C(194) },
      { UINT8_C(  9), UINT8_C(246), UINT8_C(152), UINT8_C(219), UINT8_C(140), UINT8_C(137), UINT8_C(184), UINT8_C( 61) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t r = simde_vmvn_u8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vmvn_u8(a);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvn_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(48717), UINT16_C(17400), UINT16_C(59057), UINT16_C(50869) },
      { UINT16_C(16818), UINT16_C(48135), UINT16_C( 6478), UINT16_C(14666) } },
    { { UINT16_C(33816), UINT16_C(61995), UINT16_C(11273), UINT16_C(45334) },
      { UINT16_C(31719), UINT16_C( 3540), UINT16_C(54262), UINT16_C(20201) } },
    { { UINT16_C(57276), UINT16_C(34241), UINT16_C(52335), UINT16_C(56050) },
      { UINT16_C( 8259), UINT16_C(31294), UINT16_C(13200), UINT16_C( 9485) } },
    { { UINT16_C(52494), UINT16_C( 1151), UINT16_C(50587), UINT16_C(59614) },
      { UINT16_C(13041), UINT16_C(64384), UINT16_C(14948), UINT16_C( 5921) } },
    { { UINT16_C(55171), UINT16_C(13611), UINT16_C(57533), UINT16_C(54779) },
      { UINT16_C(10364), UINT16_C(51924), UINT16_C( 8002), UINT16_C(10756) } },
    { { UINT16_C( 9828), UINT16_C(28103), UINT16_C(56914), UINT16_C( 3870) },
      { UINT16_C(55707), UINT16_C(37432), UINT16_C( 8621), UINT16_C(61665) } },
    { { UINT16_C(57277), UINT16_C(11412), UINT16_C(34475), UINT16_C(47366) },
      { UINT16_C( 8258), UINT16_C(54123), UINT16_C(31060), UINT16_C(18169) } },
    { { UINT16_C(34388), UINT16_C(61373), UINT16_C(40011), UINT16_C(53207) },
      { UINT16_C(31147), UINT16_C( 4162), UINT16_C(25524), UINT16_C(12328) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t r = simde_vmvn_u16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vmvn_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvn_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(  87345636), UINT32_C(2841930894) },
      { UINT32_C(4207621659), UINT32_C(1453036401) } },
    { { UINT32_C(2317135787), UINT32_C( 870366211) },
      { UINT32_C(1977831508), UINT32_C(3424601084) } },
    { { UINT32_C(3381487743), UINT32_C(3683874477) },
      { UINT32_C( 913479552), UINT32_C( 611092818) } },
    { { UINT32_C( 142579175), UINT32_C(3930029830) },
      { UINT32_C(4152388120), UINT32_C( 364937465) } },
    { { UINT32_C(3622859592), UINT32_C(2323666143) },
      { UINT32_C( 672107703), UINT32_C(1971301152) } },
    { { UINT32_C( 102014211), UINT32_C(3627677017) },
      { UINT32_C(4192953084), UINT32_C( 667290278) } },
    { { UINT32_C( 178374237), UINT32_C( 619000893) },
      { UINT32_C(4116593058), UINT32_C(3675966402) } },
    { { UINT32_C(3475793097), UINT32_C( 750414819) },
      { UINT32_C( 819174198), UINT32_C(3544552476) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t r = simde_vmvn_u32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vmvn_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvnq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  69),  INT8_C(  44), -INT8_C( 110), -INT8_C(  82), -INT8_C(   7),  INT8_C(  68), -INT8_C( 120), -INT8_C(  25),
         INT8_C(  15),  INT8_C(  54),  INT8_C(  36),  INT8_C( 121),  INT8_C(  81),  INT8_C(   4),  INT8_C(  96), -INT8_C( 117) },
      { -INT8_C(  70), -INT8_C(  45),  INT8_C( 109),  INT8_C(  81),  INT8_C(   6), -INT8_C(  69),  INT8_C( 119),  INT8_C(  24),
        -INT8_C(  16), -INT8_C(  55), -INT8_C(  37), -INT8_C( 122), -INT8_C(  82), -INT8_C(   5), -INT8_C(  97),  INT8_C( 116) } },
    { { -INT8_C(  16),  INT8_C(  35), -INT8_C( 107),  INT8_C(  20),  INT8_C(  50), -INT8_C(  76), -INT8_C(  12), -INT8_C(  40),
        -INT8_C(  51),  INT8_C(  18), -INT8_C(  26),  INT8_C(  18),  INT8_C(  55),  INT8_C(  80), -INT8_C(  35),  INT8_C( 124) },
      {  INT8_C(  15), -INT8_C(  36),  INT8_C( 106), -INT8_C(  21), -INT8_C(  51),  INT8_C(  75),  INT8_C(  11),  INT8_C(  39),
         INT8_C(  50), -INT8_C(  19),  INT8_C(  25), -INT8_C(  19), -INT8_C(  56), -INT8_C(  81),  INT8_C(  34), -INT8_C( 125) } },
    { {  INT8_C( 124),  INT8_C( 111),  INT8_C(  43),  INT8_C( 117), -INT8_C(  76), -INT8_C(  77),  INT8_C(  93), -INT8_C(  61),
        -INT8_C(  23), -INT8_C( 127),  INT8_C(  60),  INT8_C(  58), -INT8_C( 123), -INT8_C( 100), -INT8_C(  59),  INT8_C( 117) },
      { -INT8_C( 125), -INT8_C( 112), -INT8_C(  44), -INT8_C( 118),  INT8_C(  75),  INT8_C(  76), -INT8_C(  94),  INT8_C(  60),
         INT8_C(  22),  INT8_C( 126), -INT8_C(  61), -INT8_C(  59),  INT8_C( 122),  INT8_C(  99),  INT8_C(  58), -INT8_C( 118) } },
    { { -INT8_C(  64),  INT8_C(  91), -INT8_C( 118), -INT8_C(  14),  INT8_C(  15),  INT8_C( 126), -INT8_C(  54), -INT8_C(  36),
        -INT8_C( 111), -INT8_C(  79), -INT8_C(  18), -INT8_C(  56),  INT8_C(   1), -INT8_C(  53),  INT8_C(  68),  INT8_C( 125) },
      {  INT8_C(  63), -INT8_C(  92),  INT8_C( 117),  INT8_C(  13), -INT8_C(  16), -INT8_C( 127),  INT8_C(  53),  INT8_C(  35),
         INT8_C( 110),  INT8_C(  78),  INT8_C(  17),  INT8_C(  55), -INT8_C(   2),  INT8_C(  52), -INT8_C(  69), -INT8_C( 126) } },
    { {  INT8_C(  59),  INT8_C( 111), -INT8_C(  14), -INT8_C(  17),  INT8_C(  34),  INT8_C(  79), -INT8_C(  78),  INT8_C(  11),
        -INT8_C(  48), -INT8_C(  17),  INT8_C(  70),  INT8_C(  86), -INT8_C( 117),  INT8_C(  11), -INT8_C(  53),  INT8_C(  75) },
      { -INT8_C(  60), -INT8_C( 112),  INT8_C(  13),  INT8_C(  16), -INT8_C(  35), -INT8_C(  80),  INT8_C(  77), -INT8_C(  12),
         INT8_C(  47),  INT8_C(  16), -INT8_C(  71), -INT8_C(  87),  INT8_C( 116), -INT8_C(  12),  INT8_C(  52), -INT8_C(  76) } },
    { {  INT8_C( 102),  INT8_C(  85),  INT8_C(  61),  INT8_C( 117), -INT8_C(  44),  INT8_C(   8),  INT8_C(  82),  INT8_C( 101),
        -INT8_C(  71),  INT8_C(  64),  INT8_C(  45), -INT8_C(  70),  INT8_C(  12),  INT8_C( 113),  INT8_C(  55),  INT8_C(  71) },
      { -INT8_C( 103), -INT8_C(  86), -INT8_C(  62), -INT8_C( 118),  INT8_C(  43), -INT8_C(   9), -INT8_C(  83), -INT8_C( 102),
         INT8_C(  70), -INT8_C(  65), -INT8_C(  46),  INT8_C(  69), -INT8_C(  13), -INT8_C( 114), -INT8_C(  56), -INT8_C(  72) } },
    { { -INT8_C(  31),  INT8_C(  41),  INT8_C(  54),  INT8_C(   3),  INT8_C( 121), -INT8_C(  24),  INT8_C(  15),  INT8_C(  73),
        -INT8_C(  41),  INT8_C(  85), -INT8_C(  97),  INT8_C(  99),  INT8_C(  96),  INT8_C( 107), -INT8_C(  82), -INT8_C(  57) },
      {  INT8_C(  30), -INT8_C(  42), -INT8_C(  55), -INT8_C(   4), -INT8_C( 122),  INT8_C(  23), -INT8_C(  16), -INT8_C(  74),
         INT8_C(  40), -INT8_C(  86),  INT8_C(  96), -INT8_C( 100), -INT8_C(  97), -INT8_C( 108),  INT8_C(  81),  INT8_C(  56) } },
    { { -INT8_C(  64), -INT8_C(  20),  INT8_C(  60), -INT8_C( 108), -INT8_C(  12), -INT8_C( 114), -INT8_C(   7), -INT8_C(  83),
        -INT8_C(  49),  INT8_C(  38),  INT8_C( 103), -INT8_C(  37), -INT8_C( 104), -INT8_C(  98),  INT8_C(  34),  INT8_C( 121) },
      {  INT8_C(  63),  INT8_C(  19), -INT8_C(  61),  INT8_C( 107),  INT8_C(  11),  INT8_C( 113),  INT8_C(   6),  INT8_C(  82),
         INT8_C(  48), -INT8_C(  39), -INT8_C( 104),  INT8_C(  36),  INT8_C( 103),  INT8_C(  97), -INT8_C(  35), -INT8_C( 122) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t r = simde_vmvnq_s8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vmvnq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvnq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 16310),  INT16_C( 26887),  INT16_C( 16229), -INT16_C( 12679), -INT16_C( 20729), -INT16_C( 12653), -INT16_C(  3818),  INT16_C( 21089) },
      {  INT16_C( 16309), -INT16_C( 26888), -INT16_C( 16230),  INT16_C( 12678),  INT16_C( 20728),  INT16_C( 12652),  INT16_C(  3817), -INT16_C( 21090) } },
    { {  INT16_C( 28555), -INT16_C( 26112),  INT16_C( 22553), -INT16_C( 32323), -INT16_C(  6022), -INT16_C( 18686),  INT16_C( 12944), -INT16_C(  9680) },
      { -INT16_C( 28556),  INT16_C( 26111), -INT16_C( 22554),  INT16_C( 32322),  INT16_C(  6021),  INT16_C( 18685), -INT16_C( 12945),  INT16_C(  9679) } },
    { {  INT16_C( 14322),  INT16_C( 22596), -INT16_C( 17034),  INT16_C( 32038), -INT16_C( 18067), -INT16_C( 31924), -INT16_C( 21078),  INT16_C( 13781) },
      { -INT16_C( 14323), -INT16_C( 22597),  INT16_C( 17033), -INT16_C( 32039),  INT16_C( 18066),  INT16_C( 31923),  INT16_C( 21077), -INT16_C( 13782) } },
    { { -INT16_C( 10980),  INT16_C( 13776), -INT16_C( 29395), -INT16_C( 22346), -INT16_C( 18315),  INT16_C(  1631), -INT16_C( 28438), -INT16_C(  8736) },
      {  INT16_C( 10979), -INT16_C( 13777),  INT16_C( 29394),  INT16_C( 22345),  INT16_C( 18314), -INT16_C(  1632),  INT16_C( 28437),  INT16_C(  8735) } },
    { {  INT16_C(  9415),  INT16_C( 15925),  INT16_C( 23522),  INT16_C( 20411),  INT16_C(  1812), -INT16_C( 16430), -INT16_C( 22604), -INT16_C( 11788) },
      { -INT16_C(  9416), -INT16_C( 15926), -INT16_C( 23523), -INT16_C( 20412), -INT16_C(  1813),  INT16_C( 16429),  INT16_C( 22603),  INT16_C( 11787) } },
    { { -INT16_C( 15236), -INT16_C( 22266), -INT16_C( 17070), -INT16_C( 14511), -INT16_C( 20107),  INT16_C( 24781), -INT16_C( 20927),  INT16_C(  2109) },
      {  INT16_C( 15235),  INT16_C( 22265),  INT16_C( 17069),  INT16_C( 14510),  INT16_C( 20106), -INT16_C( 24782),  INT16_C( 20926), -INT16_C(  2110) } },
    { {  INT16_C( 29394), -INT16_C( 19386),  INT16_C(   717), -INT16_C(  7933), -INT16_C( 10999), -INT16_C( 16736), -INT16_C( 27268), -INT16_C(  1905) },
      { -INT16_C( 29395),  INT16_C( 19385), -INT16_C(   718),  INT16_C(  7932),  INT16_C( 10998),  INT16_C( 16735),  INT16_C( 27267),  INT16_C(  1904) } },
    { { -INT16_C( 27303), -INT16_C( 21598), -INT16_C(  3246), -INT16_C( 14221),  INT16_C( 16548), -INT16_C(  6872),  INT16_C( 26094), -INT16_C( 15890) },
      {  INT16_C( 27302),  INT16_C( 21597),  INT16_C(  3245),  INT16_C( 14220), -INT16_C( 16549),  INT16_C(  6871), -INT16_C( 26095),  INT16_C( 15889) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t r = simde_vmvnq_s16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vmvnq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvnq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1864677264), -INT32_C(   683572489), -INT32_C(  1030215016),  INT32_C(  1509418569) },
      { -INT32_C(  1864677265),  INT32_C(   683572488),  INT32_C(  1030215015), -INT32_C(  1509418570) } },
    { {  INT32_C(   202844593),  INT32_C(  1440732261),  INT32_C(  1701141465),  INT32_C(  2111764460) },
      { -INT32_C(   202844594), -INT32_C(  1440732262), -INT32_C(  1701141466), -INT32_C(  2111764461) } },
    { { -INT32_C(  1511259474),  INT32_C(   477900164), -INT32_C(  1579281321), -INT32_C(  1392847109) },
      {  INT32_C(  1511259473), -INT32_C(   477900165),  INT32_C(  1579281320),  INT32_C(  1392847108) } },
    { {  INT32_C(  1689784831), -INT32_C(  1078355995), -INT32_C(   551280909), -INT32_C(  1017380331) },
      { -INT32_C(  1689784832),  INT32_C(  1078355994),  INT32_C(   551280908),  INT32_C(  1017380330) } },
    { { -INT32_C(  2006431740), -INT32_C(   844766090), -INT32_C(   210861064),  INT32_C(  1486907481) },
      {  INT32_C(  2006431739),  INT32_C(   844766089),  INT32_C(   210861063), -INT32_C(  1486907482) } },
    { {  INT32_C(  1606178937), -INT32_C(   484542992), -INT32_C(  1463663981),  INT32_C(  1231757125) },
      { -INT32_C(  1606178938),  INT32_C(   484542991),  INT32_C(  1463663980), -INT32_C(  1231757126) } },
    { { -INT32_C(   573385881), -INT32_C(  1330939977),  INT32_C(  1419975162), -INT32_C(    72596606) },
      {  INT32_C(   573385880),  INT32_C(  1330939976), -INT32_C(  1419975163),  INT32_C(    72596605) } },
    { { -INT32_C(  1940231780),  INT32_C(  1919908062),  INT32_C(     1716667), -INT32_C(  1203141040) },
      {  INT32_C(  1940231779), -INT32_C(  1919908063), -INT32_C(     1716668),  INT32_C(  1203141039) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t r = simde_vmvnq_s32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vmvnq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvnq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 18), UINT8_C(204), UINT8_C( 53), UINT8_C( 76), UINT8_C(185), UINT8_C( 18), UINT8_C( 45), UINT8_C(197),
        UINT8_C(231), UINT8_C(109), UINT8_C(114), UINT8_C(202), UINT8_C(183), UINT8_C( 33), UINT8_C(169), UINT8_C( 35) },
      { UINT8_C(237), UINT8_C( 51), UINT8_C(202), UINT8_C(179), UINT8_C( 70), UINT8_C(237), UINT8_C(210), UINT8_C( 58),
        UINT8_C( 24), UINT8_C(146), UINT8_C(141), UINT8_C( 53), UINT8_C( 72), UINT8_C(222), UINT8_C( 86), UINT8_C(220) } },
    { { UINT8_C(  8), UINT8_C(155), UINT8_C( 61), UINT8_C(185), UINT8_C( 53), UINT8_C( 38), UINT8_C(194), UINT8_C( 57),
        UINT8_C(191), UINT8_C( 15), UINT8_C( 48), UINT8_C(119), UINT8_C( 78), UINT8_C(235), UINT8_C( 20), UINT8_C( 96) },
      { UINT8_C(247), UINT8_C(100), UINT8_C(194), UINT8_C( 70), UINT8_C(202), UINT8_C(217), UINT8_C( 61), UINT8_C(198),
        UINT8_C( 64), UINT8_C(240), UINT8_C(207), UINT8_C(136), UINT8_C(177), UINT8_C( 20), UINT8_C(235), UINT8_C(159) } },
    { { UINT8_C(183), UINT8_C( 74), UINT8_C(172), UINT8_C(112), UINT8_C( 92), UINT8_C(218), UINT8_C( 53), UINT8_C( 68),
        UINT8_C( 71), UINT8_C(167), UINT8_C( 14), UINT8_C(254), UINT8_C(201), UINT8_C(183), UINT8_C( 33), UINT8_C(209) },
      { UINT8_C( 72), UINT8_C(181), UINT8_C( 83), UINT8_C(143), UINT8_C(163), UINT8_C( 37), UINT8_C(202), UINT8_C(187),
        UINT8_C(184), UINT8_C( 88), UINT8_C(241), UINT8_C(  1), UINT8_C( 54), UINT8_C( 72), UINT8_C(222), UINT8_C( 46) } },
    { { UINT8_C( 82), UINT8_C( 94), UINT8_C(138), UINT8_C(135), UINT8_C(132), UINT8_C( 77), UINT8_C(192), UINT8_C( 67),
        UINT8_C( 92), UINT8_C(240), UINT8_C(187), UINT8_C(170), UINT8_C(219), UINT8_C(207), UINT8_C( 10), UINT8_C(146) },
      { UINT8_C(173), UINT8_C(161), UINT8_C(117), UINT8_C(120), UINT8_C(123), UINT8_C(178), UINT8_C( 63), UINT8_C(188),
        UINT8_C(163), UINT8_C( 15), UINT8_C( 68), UINT8_C( 85), UINT8_C( 36), UINT8_C( 48), UINT8_C(245), UINT8_C(109) } },
    { { UINT8_C( 25), UINT8_C(183), UINT8_C(  2), UINT8_C(118), UINT8_C(145), UINT8_C( 55), UINT8_C(186), UINT8_C(216),
        UINT8_C(223), UINT8_C(200), UINT8_C(214), UINT8_C(168), UINT8_C(127), UINT8_C(247), UINT8_C(121), UINT8_C(209) },
      { UINT8_C(230), UINT8_C( 72), UINT8_C(253), UINT8_C(137), UINT8_C(110), UINT8_C(200), UINT8_C( 69), UINT8_C( 39),
        UINT8_C( 32), UINT8_C( 55), UINT8_C( 41), UINT8_C( 87), UINT8_C(128), UINT8_C(  8), UINT8_C(134), UINT8_C( 46) } },
    { { UINT8_C( 85), UINT8_C(  4), UINT8_C( 88), UINT8_C(217), UINT8_C( 81), UINT8_C( 24), UINT8_C( 28), UINT8_C(173),
        UINT8_C(  8), UINT8_C(215), UINT8_C( 88), UINT8_C(228), UINT8_C(167), UINT8_C( 98), UINT8_C(118), UINT8_C(192) },
      { UINT8_C(170), UINT8_C(251), UINT8_C(167), UINT8_C( 38), UINT8_C(174), UINT8_C(231), UINT8_C(227), UINT8_C( 82),
        UINT8_C(247), UINT8_C( 40), UINT8_C(167), UINT8_C( 27), UINT8_C( 88), UINT8_C(157), UINT8_C(137), UINT8_C( 63) } },
    { { UINT8_C( 25), UINT8_C(121), UINT8_C( 54), UINT8_C(170), UINT8_C(176), UINT8_C(240), UINT8_C(130), UINT8_C(143),
        UINT8_C(184), UINT8_C( 88), UINT8_C( 55), UINT8_C( 55), UINT8_C( 79), UINT8_C(177), UINT8_C(  8), UINT8_C(164) },
      { UINT8_C(230), UINT8_C(134), UINT8_C(201), UINT8_C( 85), UINT8_C( 79), UINT8_C( 15), UINT8_C(125), UINT8_C(112),
        UINT8_C( 71), UINT8_C(167), UINT8_C(200), UINT8_C(200), UINT8_C(176), UINT8_C( 78), UINT8_C(247), UINT8_C( 91) } },
    { { UINT8_C(181), UINT8_C( 96), UINT8_C(125), UINT8_C(  6), UINT8_C(120), UINT8_C(154), UINT8_C(179), UINT8_C(129),
        UINT8_C(113), UINT8_C( 11), UINT8_C(101), UINT8_C( 24), UINT8_C(110), UINT8_C(219), UINT8_C(217), UINT8_C(135) },
      { UINT8_C( 74), UINT8_C(159), UINT8_C(130), UINT8_C(249), UINT8_C(135), UINT8_C(101), UINT8_C( 76), UINT8_C(126),
        UINT8_C(142), UINT8_C(244), UINT8_C(154), UINT8_C(231), UINT8_C(145), UINT8_C( 36), UINT8_C( 38), UINT8_C(120) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t r = simde_vmvnq_u8(a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vmvnq_u8(a);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvnq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(47575), UINT16_C(62789), UINT16_C(44550), UINT16_C(31586), UINT16_C( 2213), UINT16_C(35014), UINT16_C(61130), UINT16_C( 2225) },
      { UINT16_C(17960), UINT16_C( 2746), UINT16_C(20985), UINT16_C(33949), UINT16_C(63322), UINT16_C(30521), UINT16_C( 4405), UINT16_C(63310) } },
    { { UINT16_C(54992), UINT16_C(34469), UINT16_C(53736), UINT16_C(23984), UINT16_C(14961), UINT16_C(52228), UINT16_C(42793), UINT16_C(  164) },
      { UINT16_C(10543), UINT16_C(31066), UINT16_C(11799), UINT16_C(41551), UINT16_C(50574), UINT16_C(13307), UINT16_C(22742), UINT16_C(65371) } },
    { { UINT16_C(60000), UINT16_C(26614), UINT16_C(22680), UINT16_C(16098), UINT16_C(43104), UINT16_C(10950), UINT16_C(30615), UINT16_C(26418) },
      { UINT16_C( 5535), UINT16_C(38921), UINT16_C(42855), UINT16_C(49437), UINT16_C(22431), UINT16_C(54585), UINT16_C(34920), UINT16_C(39117) } },
    { { UINT16_C(55374), UINT16_C(14061), UINT16_C(40361), UINT16_C( 7060), UINT16_C(39127), UINT16_C(  487), UINT16_C(35903), UINT16_C(40705) },
      { UINT16_C(10161), UINT16_C(51474), UINT16_C(25174), UINT16_C(58475), UINT16_C(26408), UINT16_C(65048), UINT16_C(29632), UINT16_C(24830) } },
    { { UINT16_C(63350), UINT16_C( 3590), UINT16_C(59471), UINT16_C(44876), UINT16_C( 5009), UINT16_C(10458), UINT16_C( 3210), UINT16_C(55439) },
      { UINT16_C( 2185), UINT16_C(61945), UINT16_C( 6064), UINT16_C(20659), UINT16_C(60526), UINT16_C(55077), UINT16_C(62325), UINT16_C(10096) } },
    { { UINT16_C(31972), UINT16_C(36367), UINT16_C(41753), UINT16_C(61865), UINT16_C(36923), UINT16_C(31474), UINT16_C(62236), UINT16_C(37401) },
      { UINT16_C(33563), UINT16_C(29168), UINT16_C(23782), UINT16_C( 3670), UINT16_C(28612), UINT16_C(34061), UINT16_C( 3299), UINT16_C(28134) } },
    { { UINT16_C( 8427), UINT16_C(15009), UINT16_C(60680), UINT16_C(39402), UINT16_C(50176), UINT16_C(35777), UINT16_C(20688), UINT16_C(46435) },
      { UINT16_C(57108), UINT16_C(50526), UINT16_C( 4855), UINT16_C(26133), UINT16_C(15359), UINT16_C(29758), UINT16_C(44847), UINT16_C(19100) } },
    { { UINT16_C(29388), UINT16_C(58947), UINT16_C(60437), UINT16_C(20695), UINT16_C(51580), UINT16_C(39370), UINT16_C(58556), UINT16_C(42795) },
      { UINT16_C(36147), UINT16_C( 6588), UINT16_C( 5098), UINT16_C(44840), UINT16_C(13955), UINT16_C(26165), UINT16_C( 6979), UINT16_C(22740) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t r = simde_vmvnq_u16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vmvnq_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmvnq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1700826709), UINT32_C(4200405802), UINT32_C(4150461492), UINT32_C(3304330719) },
      { UINT32_C(2594140586), UINT32_C(  94561493), UINT32_C( 144505803), UINT32_C( 990636576) } },
    { { UINT32_C( 799921039), UINT32_C(2967516902), UINT32_C(2873095487), UINT32_C( 346815679) },
      { UINT32_C(3495046256), UINT32_C(1327450393), UINT32_C(1421871808), UINT32_C(3948151616) } },
    { { UINT32_C(3044608907), UINT32_C(1538315815), UINT32_C(3126006747), UINT32_C(3095283497) },
      { UINT32_C(1250358388), UINT32_C(2756651480), UINT32_C(1168960548), UINT32_C(1199683798) } },
    { { UINT32_C(  15150106), UINT32_C( 565233634), UINT32_C(2093805500), UINT32_C(2005956588) },
      { UINT32_C(4279817189), UINT32_C(3729733661), UINT32_C(2201161795), UINT32_C(2289010707) } },
    { { UINT32_C(2855012995), UINT32_C(3137723616), UINT32_C( 427120880), UINT32_C(3134321824) },
      { UINT32_C(1439954300), UINT32_C(1157243679), UINT32_C(3867846415), UINT32_C(1160645471) } },
    { { UINT32_C(  45857056), UINT32_C(1025731456), UINT32_C(1203367771), UINT32_C(3921561958) },
      { UINT32_C(4249110239), UINT32_C(3269235839), UINT32_C(3091599524), UINT32_C( 373405337) } },
    { { UINT32_C( 882109011), UINT32_C(3085932999), UINT32_C(2446353905), UINT32_C(2035065177) },
      { UINT32_C(3412858284), UINT32_C(1209034296), UINT32_C(1848613390), UINT32_C(2259902118) } },
    { { UINT32_C(3682273114), UINT32_C(3440942706), UINT32_C(4078227853), UINT32_C(1860031002) },
      { UINT32_C( 612694181), UINT32_C( 854024589), UINT32_C( 216739442), UINT32_C(2434936293) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t r = simde_vmvnq_u32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vmvnq_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmvn_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmvn_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmvn_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmvn_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmvn_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmvn_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmvnq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmvnq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmvnq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmvnq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmvnq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmvnq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
