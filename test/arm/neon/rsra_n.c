#define SIMDE_TEST_ARM_NEON_INSN rsra_n

#include <test/arm/neon/test-neon.h>

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/rsra_n.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vrsra_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec[] = {
    { {  INT8_C(  53), -INT8_C(  70),  INT8_C( 119),  INT8_C(   8),  INT8_C(  71), -INT8_C(  53), -INT8_C( 109),  INT8_C(  51) },
      {  INT8_C(  60), -INT8_C(  71), -INT8_C(  27), -INT8_C( 112), -INT8_C(  21),  INT8_C(  75),  INT8_C( 108), -INT8_C(  57) },
      {  INT8_C(  83), -INT8_C( 105),  INT8_C( 106), -INT8_C(  48),  INT8_C(  61), -INT8_C(  15), -INT8_C(  55),  INT8_C(  23) },
      {  INT8_C(  61), -INT8_C(  79),  INT8_C( 116), -INT8_C(   6),  INT8_C(  68), -INT8_C(  44), -INT8_C(  95),  INT8_C(  44) },
      {  INT8_C(  55), -INT8_C(  72),  INT8_C( 118),  INT8_C(   5),  INT8_C(  70), -INT8_C(  51), -INT8_C( 106),  INT8_C(  49) },
      {  INT8_C(  54), -INT8_C(  71),  INT8_C( 119),  INT8_C(   6),  INT8_C(  71), -INT8_C(  52), -INT8_C( 107),  INT8_C(  50) },
      {  INT8_C(  53), -INT8_C(  70),  INT8_C( 119),  INT8_C(   8),  INT8_C(  71), -INT8_C(  53), -INT8_C( 109),  INT8_C(  51) } },
    { { -INT8_C(  24),  INT8_C(  15),  INT8_C( 107),  INT8_C(  16),  INT8_C(   7), -INT8_C(  81), -INT8_C( 124), -INT8_C(  98) },
      {  INT8_C(  26), -INT8_C( 104), -INT8_C( 113), -INT8_C( 127),  INT8_C(  68),  INT8_C(  60),  INT8_C( 111),  INT8_C( 121) },
      { -INT8_C(  11), -INT8_C(  37),  INT8_C(  51), -INT8_C(  47),  INT8_C(  41), -INT8_C(  51), -INT8_C(  68), -INT8_C(  37) },
      { -INT8_C(  21),  INT8_C(   2),  INT8_C(  93),  INT8_C(   0),  INT8_C(  16), -INT8_C(  73), -INT8_C( 110), -INT8_C(  83) },
      { -INT8_C(  23),  INT8_C(  12),  INT8_C( 103),  INT8_C(  12),  INT8_C(   9), -INT8_C(  79), -INT8_C( 121), -INT8_C(  94) },
      { -INT8_C(  24),  INT8_C(  13),  INT8_C( 105),  INT8_C(  14),  INT8_C(   8), -INT8_C(  80), -INT8_C( 122), -INT8_C(  96) },
      { -INT8_C(  24),  INT8_C(  15),  INT8_C( 107),  INT8_C(  16),  INT8_C(   7), -INT8_C(  81), -INT8_C( 124), -INT8_C(  98) } },
    { { -INT8_C(  10), -INT8_C(  26), -INT8_C( 127),  INT8_C(  61), -INT8_C(  79),  INT8_C(  20),  INT8_C( 113), -INT8_C(  18) },
      { -INT8_C(  50),  INT8_C(  86),  INT8_C( 126), -INT8_C(  71), -INT8_C(  95), -INT8_C(  21),      INT8_MIN, -INT8_C( 119) },
      { -INT8_C(  35),  INT8_C(  17), -INT8_C(  64),  INT8_C(  26), -INT8_C( 126),  INT8_C(  10),  INT8_C(  49), -INT8_C(  77) },
      { -INT8_C(  16), -INT8_C(  15), -INT8_C( 111),  INT8_C(  52), -INT8_C(  91),  INT8_C(  17),  INT8_C(  97), -INT8_C(  33) },
      { -INT8_C(  12), -INT8_C(  23), -INT8_C( 123),  INT8_C(  59), -INT8_C(  82),  INT8_C(  19),  INT8_C( 109), -INT8_C(  22) },
      { -INT8_C(  11), -INT8_C(  25), -INT8_C( 125),  INT8_C(  60), -INT8_C(  80),  INT8_C(  20),  INT8_C( 111), -INT8_C(  20) },
      { -INT8_C(  10), -INT8_C(  26), -INT8_C( 127),  INT8_C(  61), -INT8_C(  79),  INT8_C(  20),  INT8_C( 113), -INT8_C(  18) } },
    { { -INT8_C(   6), -INT8_C(  21), -INT8_C( 102),  INT8_C(   2), -INT8_C( 101),  INT8_C(  30), -INT8_C(  96), -INT8_C(  75) },
      { -INT8_C(  73),  INT8_C(  47),  INT8_C(  55), -INT8_C(   5),  INT8_C( 107), -INT8_C(  90),  INT8_C( 116),  INT8_C(  98) },
      { -INT8_C(  42),  INT8_C(   3), -INT8_C(  74),  INT8_C(   0), -INT8_C(  47), -INT8_C(  15), -INT8_C(  38), -INT8_C(  26) },
      { -INT8_C(  15), -INT8_C(  15), -INT8_C(  95),  INT8_C(   1), -INT8_C(  88),  INT8_C(  19), -INT8_C(  81), -INT8_C(  63) },
      { -INT8_C(   8), -INT8_C(  20), -INT8_C( 100),  INT8_C(   2), -INT8_C(  98),  INT8_C(  27), -INT8_C(  92), -INT8_C(  72) },
      { -INT8_C(   7), -INT8_C(  20), -INT8_C( 101),  INT8_C(   2), -INT8_C(  99),  INT8_C(  29), -INT8_C(  94), -INT8_C(  73) },
      { -INT8_C(   6), -INT8_C(  21), -INT8_C( 102),  INT8_C(   2), -INT8_C( 101),  INT8_C(  30), -INT8_C(  96), -INT8_C(  75) } },
    { { -INT8_C( 116), -INT8_C(  11), -INT8_C(  97),  INT8_C(  61),  INT8_C(  10),  INT8_C(  16),  INT8_C(  43), -INT8_C(  40) },
      {  INT8_C( 102), -INT8_C(  86), -INT8_C( 111),  INT8_C(   8), -INT8_C( 107),  INT8_C(  17), -INT8_C( 111), -INT8_C( 113) },
      { -INT8_C(  65), -INT8_C(  54),  INT8_C( 104),  INT8_C(  65), -INT8_C(  43),  INT8_C(  25), -INT8_C(  12), -INT8_C(  96) },
      { -INT8_C( 103), -INT8_C(  22), -INT8_C( 111),  INT8_C(  62), -INT8_C(   3),  INT8_C(  18),  INT8_C(  29), -INT8_C(  54) },
      { -INT8_C( 113), -INT8_C(  14), -INT8_C( 100),  INT8_C(  61),  INT8_C(   7),  INT8_C(  17),  INT8_C(  40), -INT8_C(  44) },
      { -INT8_C( 114), -INT8_C(  12), -INT8_C(  99),  INT8_C(  61),  INT8_C(   8),  INT8_C(  16),  INT8_C(  41), -INT8_C(  42) },
      { -INT8_C( 116), -INT8_C(  11), -INT8_C(  97),  INT8_C(  61),  INT8_C(  10),  INT8_C(  16),  INT8_C(  43), -INT8_C(  40) } },
    { { -INT8_C(   3),  INT8_C(  43), -INT8_C( 111), -INT8_C( 104),  INT8_C(  74),  INT8_C(  49),  INT8_C(  77),  INT8_C(   1) },
      {  INT8_C(  97), -INT8_C( 124), -INT8_C(   4), -INT8_C(  52),  INT8_C(  42),  INT8_C( 112),  INT8_C(  46), -INT8_C(  74) },
      {  INT8_C(  46), -INT8_C(  19), -INT8_C( 113),  INT8_C( 126),  INT8_C(  95),  INT8_C( 105),  INT8_C( 100), -INT8_C(  36) },
      {  INT8_C(   9),  INT8_C(  28), -INT8_C( 111), -INT8_C( 110),  INT8_C(  79),  INT8_C(  63),  INT8_C(  83), -INT8_C(   8) },
      {  INT8_C(   0),  INT8_C(  39), -INT8_C( 111), -INT8_C( 106),  INT8_C(  75),  INT8_C(  53),  INT8_C(  78), -INT8_C(   1) },
      { -INT8_C(   1),  INT8_C(  41), -INT8_C( 111), -INT8_C( 105),  INT8_C(  75),  INT8_C(  51),  INT8_C(  78),  INT8_C(   0) },
      { -INT8_C(   3),  INT8_C(  43), -INT8_C( 111), -INT8_C( 104),  INT8_C(  74),  INT8_C(  49),  INT8_C(  77),  INT8_C(   1) } },
    { {  INT8_C( 101), -INT8_C(  50), -INT8_C(  12),  INT8_C( 111), -INT8_C(  34),  INT8_C(  31),  INT8_C(  71),  INT8_C(  69) },
      { -INT8_C(  55), -INT8_C(  40),  INT8_C(  77),  INT8_C(  94), -INT8_C(  22), -INT8_C(  34), -INT8_C(  18), -INT8_C(  25) },
      {  INT8_C(  74), -INT8_C(  70),  INT8_C(  27), -INT8_C(  98), -INT8_C(  45),  INT8_C(  14),  INT8_C(  62),  INT8_C(  57) },
      {  INT8_C(  94), -INT8_C(  55), -INT8_C(   2),  INT8_C( 123), -INT8_C(  37),  INT8_C(  27),  INT8_C(  69),  INT8_C(  66) },
      {  INT8_C(  99), -INT8_C(  51), -INT8_C(  10),  INT8_C( 114), -INT8_C(  35),  INT8_C(  30),  INT8_C(  70),  INT8_C(  68) },
      {  INT8_C( 100), -INT8_C(  51), -INT8_C(  11),  INT8_C( 112), -INT8_C(  34),  INT8_C(  30),  INT8_C(  71),  INT8_C(  69) },
      {  INT8_C( 101), -INT8_C(  50), -INT8_C(  12),  INT8_C( 111), -INT8_C(  34),  INT8_C(  31),  INT8_C(  71),  INT8_C(  69) } },
    { {  INT8_C(  10),      INT8_MAX,      INT8_MAX,  INT8_C(  84), -INT8_C(  79), -INT8_C(  52),  INT8_C(  85),  INT8_C(  18) },
      {  INT8_C(  81),  INT8_C(  81), -INT8_C(  34),  INT8_C( 123), -INT8_C(  63),  INT8_C(  13),  INT8_C(  50),  INT8_C(  38) },
      {  INT8_C(  51), -INT8_C(  88),  INT8_C( 110), -INT8_C( 110), -INT8_C( 110), -INT8_C(  45),  INT8_C( 110),  INT8_C(  37) },
      {  INT8_C(  20), -INT8_C( 119),  INT8_C( 123),  INT8_C(  99), -INT8_C(  87), -INT8_C(  50),  INT8_C(  91),  INT8_C(  23) },
      {  INT8_C(  13), -INT8_C( 126),  INT8_C( 126),  INT8_C(  88), -INT8_C(  81), -INT8_C(  52),  INT8_C(  87),  INT8_C(  19) },
      {  INT8_C(  11),      INT8_MIN,  INT8_C( 126),  INT8_C(  86), -INT8_C(  80), -INT8_C(  52),  INT8_C(  86),  INT8_C(  19) },
      {  INT8_C(  10),      INT8_MAX,      INT8_MAX,  INT8_C(  84), -INT8_C(  79), -INT8_C(  52),  INT8_C(  85),  INT8_C(  18) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);

    simde_int8x8_t r1 = simde_vrsra_n_s8(a, b, 1);
    simde_int8x8_t r3 = simde_vrsra_n_s8(a, b, 3);
    simde_int8x8_t r5 = simde_vrsra_n_s8(a, b, 5);
    simde_int8x8_t r6 = simde_vrsra_n_s8(a, b, 6);
    simde_int8x8_t r8 = simde_vrsra_n_s8(a, b, 8);

    simde_test_arm_neon_assert_equal_i8x8(r1, simde_vld1_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r6, simde_vld1_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x8(r8, simde_vld1_s8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vrsra_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { { -INT16_C(  9517), -INT16_C( 14208), -INT16_C( 10515),  INT16_C(  3914) },
      {  INT16_C(  9067),  INT16_C( 28811),  INT16_C( 28074), -INT16_C( 27330) },
      { -INT16_C(  8384), -INT16_C( 10607), -INT16_C(  7006),  INT16_C(   498) },
      { -INT16_C(  9375), -INT16_C( 13758), -INT16_C( 10076),  INT16_C(  3487) },
      { -INT16_C(  9508), -INT16_C( 14180), -INT16_C( 10488),  INT16_C(  3887) },
      { -INT16_C(  9516), -INT16_C( 14204), -INT16_C( 10512),  INT16_C(  3911) },
      { -INT16_C(  9517), -INT16_C( 14208), -INT16_C( 10515),  INT16_C(  3914) } },
    { { -INT16_C( 12201),  INT16_C( 22657),  INT16_C( 17622),  INT16_C(  1012) },
      {  INT16_C( 17717), -INT16_C( 17474),  INT16_C(  4757),  INT16_C( 26980) },
      { -INT16_C(  9986),  INT16_C( 20473),  INT16_C( 18217),  INT16_C(  4385) },
      { -INT16_C( 11924),  INT16_C( 22384),  INT16_C( 17696),  INT16_C(  1434) },
      { -INT16_C( 12184),  INT16_C( 22640),  INT16_C( 17627),  INT16_C(  1038) },
      { -INT16_C( 12199),  INT16_C( 22655),  INT16_C( 17623),  INT16_C(  1015) },
      { -INT16_C( 12201),  INT16_C( 22657),  INT16_C( 17622),  INT16_C(  1012) } },
    { { -INT16_C(  6932), -INT16_C(  9935),  INT16_C( 31674),  INT16_C(  9960) },
      {  INT16_C( 29855),  INT16_C( 18838), -INT16_C( 10783),  INT16_C( 14558) },
      { -INT16_C(  3200), -INT16_C(  7580),  INT16_C( 30326),  INT16_C( 11780) },
      { -INT16_C(  6466), -INT16_C(  9641),  INT16_C( 31506),  INT16_C( 10187) },
      { -INT16_C(  6903), -INT16_C(  9917),  INT16_C( 31663),  INT16_C(  9974) },
      { -INT16_C(  6928), -INT16_C(  9933),  INT16_C( 31673),  INT16_C(  9962) },
      { -INT16_C(  6932), -INT16_C(  9935),  INT16_C( 31674),  INT16_C(  9960) } },
    { {  INT16_C( 24485),  INT16_C( 31632), -INT16_C( 31580), -INT16_C(  9858) },
      {  INT16_C( 15817),  INT16_C( 24468), -INT16_C(  1713),  INT16_C( 15304) },
      {  INT16_C( 26462), -INT16_C( 30845), -INT16_C( 31794), -INT16_C(  7945) },
      {  INT16_C( 24732),  INT16_C( 32014), -INT16_C( 31607), -INT16_C(  9619) },
      {  INT16_C( 24500),  INT16_C( 31656), -INT16_C( 31582), -INT16_C(  9843) },
      {  INT16_C( 24487),  INT16_C( 31635), -INT16_C( 31580), -INT16_C(  9856) },
      {  INT16_C( 24485),  INT16_C( 31632), -INT16_C( 31580), -INT16_C(  9858) } },
    { { -INT16_C(  1571), -INT16_C( 26604), -INT16_C(   908),  INT16_C(  5054) },
      {  INT16_C( 21616),  INT16_C( 20828),  INT16_C( 15145), -INT16_C( 12663) },
      {  INT16_C(  1131), -INT16_C( 24000),  INT16_C(   985),  INT16_C(  3471) },
      { -INT16_C(  1233), -INT16_C( 26279), -INT16_C(   671),  INT16_C(  4856) },
      { -INT16_C(  1550), -INT16_C( 26584), -INT16_C(   893),  INT16_C(  5042) },
      { -INT16_C(  1568), -INT16_C( 26601), -INT16_C(   906),  INT16_C(  5052) },
      { -INT16_C(  1571), -INT16_C( 26604), -INT16_C(   908),  INT16_C(  5054) } },
    { {  INT16_C(  6554),  INT16_C( 15945), -INT16_C( 14178),  INT16_C( 26392) },
      { -INT16_C( 21499),  INT16_C( 21702), -INT16_C( 29019), -INT16_C( 31857) },
      {  INT16_C(  3867),  INT16_C( 18658), -INT16_C( 17805),  INT16_C( 22410) },
      {  INT16_C(  6218),  INT16_C( 16284), -INT16_C( 14631),  INT16_C( 25894) },
      {  INT16_C(  6533),  INT16_C( 15966), -INT16_C( 14206),  INT16_C( 26361) },
      {  INT16_C(  6551),  INT16_C( 15948), -INT16_C( 14182),  INT16_C( 26388) },
      {  INT16_C(  6554),  INT16_C( 15945), -INT16_C( 14178),  INT16_C( 26392) } },
    { { -INT16_C( 23673), -INT16_C(   997), -INT16_C(  9825),  INT16_C(  4111) },
      {  INT16_C( 27693),  INT16_C( 22369), -INT16_C(  5209),  INT16_C( 16677) },
      { -INT16_C( 20211),  INT16_C(  1799), -INT16_C( 10476),  INT16_C(  6196) },
      { -INT16_C( 23240), -INT16_C(   647), -INT16_C(  9906),  INT16_C(  4372) },
      { -INT16_C( 23646), -INT16_C(   975), -INT16_C(  9830),  INT16_C(  4127) },
      { -INT16_C( 23670), -INT16_C(   994), -INT16_C(  9826),  INT16_C(  4113) },
      { -INT16_C( 23673), -INT16_C(   997), -INT16_C(  9825),  INT16_C(  4111) } },
    { {  INT16_C( 28420), -INT16_C( 23936), -INT16_C( 26569),  INT16_C( 15370) },
      { -INT16_C( 12220), -INT16_C(  5488),  INT16_C(  8031), -INT16_C(  6547) },
      {  INT16_C( 26893), -INT16_C( 24622), -INT16_C( 25565),  INT16_C( 14552) },
      {  INT16_C( 28229), -INT16_C( 24022), -INT16_C( 26444),  INT16_C( 15268) },
      {  INT16_C( 28408), -INT16_C( 23941), -INT16_C( 26561),  INT16_C( 15364) },
      {  INT16_C( 28419), -INT16_C( 23937), -INT16_C( 26568),  INT16_C( 15369) },
      {  INT16_C( 28420), -INT16_C( 23936), -INT16_C( 26569),  INT16_C( 15370) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);

    simde_int16x4_t r3 = simde_vrsra_n_s16(a, b, 3);
    simde_int16x4_t r6 = simde_vrsra_n_s16(a, b, 6);
    simde_int16x4_t r10 = simde_vrsra_n_s16(a, b, 10);
    simde_int16x4_t r13 = simde_vrsra_n_s16(a, b, 13);
    simde_int16x4_t r16 = simde_vrsra_n_s16(a, b, 16);

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r16, simde_vld1_s16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vrsra_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec[] = {
    { {  INT32_C(  1934731521),  INT32_C(    76811743) },
      {  INT32_C(   328250290), -INT32_C(  1106175686) },
      {  INT32_C(  1939860432),  INT32_C(    59527748) },
      {  INT32_C(  1934771591),  INT32_C(    76676712) },
      {  INT32_C(  1934732147),  INT32_C(    76809633) },
      {  INT32_C(  1934731526),  INT32_C(    76811727) },
      {  INT32_C(  1934731521),  INT32_C(    76811743) } },
    { { -INT32_C(   790704782),  INT32_C(   798683025) },
      {  INT32_C(   833800098),  INT32_C(  1575841628) },
      { -INT32_C(   777676655),  INT32_C(   823305550) },
      { -INT32_C(   790603000),  INT32_C(   798875388) },
      { -INT32_C(   790703192),  INT32_C(   798686031) },
      { -INT32_C(   790704770),  INT32_C(   798683048) },
      { -INT32_C(   790704782),  INT32_C(   798683025) } },
    { { -INT32_C(   137347560), -INT32_C(    33790645) },
      {  INT32_C(  1376816152),  INT32_C(   386933413) },
      { -INT32_C(   115834808), -INT32_C(    27744810) },
      { -INT32_C(   137179492), -INT32_C(    33743412) },
      { -INT32_C(   137344934), -INT32_C(    33789907) },
      { -INT32_C(   137347539), -INT32_C(    33790639) },
      { -INT32_C(   137347560), -INT32_C(    33790645) } },
    { { -INT32_C(  2132283409), -INT32_C(  2119138594) },
      { -INT32_C(  1498258871), -INT32_C(   385638447) },
      {  INT32_C(  2139273592), -INT32_C(  2125164195) },
      { -INT32_C(  2132466302), -INT32_C(  2119185669) },
      { -INT32_C(  2132286267), -INT32_C(  2119139330) },
      { -INT32_C(  2132283431), -INT32_C(  2119138600) },
      { -INT32_C(  2132283409), -INT32_C(  2119138594) } },
    { {  INT32_C(   685823197),  INT32_C(  1361501241) },
      {  INT32_C(   245642857),  INT32_C(  1210496088) },
      {  INT32_C(   689661367),  INT32_C(  1380415242) },
      {  INT32_C(   685853183),  INT32_C(  1361649007) },
      {  INT32_C(   685823666),  INT32_C(  1361503550) },
      {  INT32_C(   685823201),  INT32_C(  1361501259) },
      {  INT32_C(   685823197),  INT32_C(  1361501241) } },
    { { -INT32_C(  2100818525), -INT32_C(   654083953) },
      { -INT32_C(  1417693734),  INT32_C(   831816276) },
      { -INT32_C(  2122969990), -INT32_C(   641086824) },
      { -INT32_C(  2100991583), -INT32_C(   653982413) },
      { -INT32_C(  2100821229), -INT32_C(   654082366) },
      { -INT32_C(  2100818546), -INT32_C(   654083941) },
      { -INT32_C(  2100818525), -INT32_C(   654083953) } },
    { { -INT32_C(  1889962666), -INT32_C(  1159626927) },
      {  INT32_C(   248087990), -INT32_C(   581505223) },
      { -INT32_C(  1886086291), -INT32_C(  1168712946) },
      { -INT32_C(  1889932382), -INT32_C(  1159697912) },
      { -INT32_C(  1889962193), -INT32_C(  1159628036) },
      { -INT32_C(  1889962662), -INT32_C(  1159626936) },
      { -INT32_C(  1889962666), -INT32_C(  1159626927) } },
    { { -INT32_C(  1939922948),  INT32_C(  1919246999) },
      {  INT32_C(  1797121047), -INT32_C(  1113804186) },
      { -INT32_C(  1911842932),  INT32_C(  1901843809) },
      { -INT32_C(  1939703573),  INT32_C(  1919111037) },
      { -INT32_C(  1939919520),  INT32_C(  1919244875) },
      { -INT32_C(  1939922921),  INT32_C(  1919246982) },
      { -INT32_C(  1939922948),  INT32_C(  1919246999) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);

    simde_int32x2_t r6 = simde_vrsra_n_s32(a, b, 6);
    simde_int32x2_t r13 = simde_vrsra_n_s32(a, b, 13);
    simde_int32x2_t r19 = simde_vrsra_n_s32(a, b, 19);
    simde_int32x2_t r26 = simde_vrsra_n_s32(a, b, 26);
    simde_int32x2_t r32 = simde_vrsra_n_s32(a, b, 32);

    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r32, simde_vld1_s32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vrsra_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r13[1];
    int64_t r26[1];
    int64_t r39[1];
    int64_t r52[1];
    int64_t r64[1];
  } test_vec[] = {
    { {  INT64_C( 1447598319563480591) },
      { -INT64_C( 2394531401172035068) },
      {  INT64_C( 1447306018367048458) },
      {  INT64_C( 1447598283882182198) },
      {  INT64_C( 1447598319559124964) },
      {  INT64_C( 1447598319563480059) },
      {  INT64_C( 1447598319563480591) } },
    { {  INT64_C( 8563258826769889006) },
      {  INT64_C( 6079905976082192743) },
      {  INT64_C( 8564001002792359977) },
      {  INT64_C( 8563258917367547999) },
      {  INT64_C( 8563258826780948291) },
      {  INT64_C( 8563258826769890356) },
      {  INT64_C( 8563258826769889006) } },
    { {  INT64_C( 6043243903393687752) },
      {  INT64_C( 6089910573593558084) },
      {  INT64_C( 6043987300680503372) },
      {  INT64_C( 6043243994140426865) },
      {  INT64_C( 6043243903404765235) },
      {  INT64_C( 6043243903393689104) },
      {  INT64_C( 6043243903393687752) } },
    { {  INT64_C( 1200934605591272363) },
      { -INT64_C( 4285678638112321044) },
      {  INT64_C( 1200411451460643418) },
      {  INT64_C( 1200934541729684151) },
      {  INT64_C( 1200934605583476759) },
      {  INT64_C( 1200934605591271411) },
      {  INT64_C( 1200934605591272363) } },
    { { -INT64_C( 8701119115092469347) },
      { -INT64_C( 8025221136613887770) },
      { -INT64_C( 8702098756344497409) },
      { -INT64_C( 8701119234677583120) },
      { -INT64_C( 8701119115107067139) },
      { -INT64_C( 8701119115092471129) },
      { -INT64_C( 8701119115092469347) } },
    { { -INT64_C( 2575091484474450550) },
      { -INT64_C( 1584822534416754624) },
      { -INT64_C( 2575284944256483845) },
      { -INT64_C( 2575091508090146599) },
      { -INT64_C( 2575091484477333325) },
      { -INT64_C( 2575091484474450902) },
      { -INT64_C( 2575091484474450550) } },
    { { -INT64_C( 2398141546330943763) },
      {  INT64_C( 2142528781178037318) },
      { -INT64_C( 2397880007173085116) },
      { -INT64_C( 2398141514404777032) },
      { -INT64_C( 2398141546327046526) },
      { -INT64_C( 2398141546330943287) },
      { -INT64_C( 2398141546330943763) } },
    { {  INT64_C( 3455269093732548647) },
      { -INT64_C( 8942902469132025428) },
      {  INT64_C( 3454177430833484679) },
      {  INT64_C( 3455268960472917414) },
      {  INT64_C( 3455269093716281602) },
      {  INT64_C( 3455269093732546661) },
      {  INT64_C( 3455269093732548647) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);

    simde_int64x1_t r13 = simde_vrsra_n_s64(a, b, 13);
    simde_int64x1_t r26 = simde_vrsra_n_s64(a, b, 26);
    simde_int64x1_t r39 = simde_vrsra_n_s64(a, b, 39);
    simde_int64x1_t r52 = simde_vrsra_n_s64(a, b, 52);
    simde_int64x1_t r64 = simde_vrsra_n_s64(a, b, 64);

    simde_test_arm_neon_assert_equal_i64x1(r13, simde_vld1_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x1(r26, simde_vld1_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x1(r39, simde_vld1_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x1(r52, simde_vld1_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x1(r64, simde_vld1_s64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vrsra_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec[] = {
    { { UINT8_C(  5), UINT8_C( 68), UINT8_C( 51), UINT8_C(236), UINT8_C(172), UINT8_C(201), UINT8_C( 57), UINT8_C( 63) },
      { UINT8_C(176), UINT8_C(  4), UINT8_C(154), UINT8_C( 70), UINT8_C( 36), UINT8_C(134), UINT8_C(245), UINT8_C(171) },
      { UINT8_C( 93), UINT8_C( 70), UINT8_C(128), UINT8_C( 15), UINT8_C(190), UINT8_C( 12), UINT8_C(180), UINT8_C(149) },
      { UINT8_C( 27), UINT8_C( 69), UINT8_C( 70), UINT8_C(245), UINT8_C(177), UINT8_C(218), UINT8_C( 88), UINT8_C( 84) },
      { UINT8_C( 11), UINT8_C( 68), UINT8_C( 56), UINT8_C(238), UINT8_C(173), UINT8_C(205), UINT8_C( 65), UINT8_C( 68) },
      { UINT8_C(  8), UINT8_C( 68), UINT8_C( 53), UINT8_C(237), UINT8_C(173), UINT8_C(203), UINT8_C( 61), UINT8_C( 66) },
      { UINT8_C(  6), UINT8_C( 68), UINT8_C( 52), UINT8_C(236), UINT8_C(172), UINT8_C(202), UINT8_C( 58), UINT8_C( 64) } },
    { { UINT8_C(209), UINT8_C(154), UINT8_C(217), UINT8_C(111), UINT8_C(135), UINT8_C(222), UINT8_C( 31), UINT8_C( 95) },
      { UINT8_C( 21), UINT8_C(220), UINT8_C(219), UINT8_C( 41), UINT8_C( 25), UINT8_C(155), UINT8_C(210), UINT8_C( 30) },
      { UINT8_C(220), UINT8_C(  8), UINT8_C( 71), UINT8_C(132), UINT8_C(148), UINT8_C( 44), UINT8_C(136), UINT8_C(110) },
      { UINT8_C(212), UINT8_C(182), UINT8_C(244), UINT8_C(116), UINT8_C(138), UINT8_C(241), UINT8_C( 57), UINT8_C( 99) },
      { UINT8_C(210), UINT8_C(161), UINT8_C(224), UINT8_C(112), UINT8_C(136), UINT8_C(227), UINT8_C( 38), UINT8_C( 96) },
      { UINT8_C(209), UINT8_C(157), UINT8_C(220), UINT8_C(112), UINT8_C(135), UINT8_C(224), UINT8_C( 34), UINT8_C( 95) },
      { UINT8_C(209), UINT8_C(155), UINT8_C(218), UINT8_C(111), UINT8_C(135), UINT8_C(223), UINT8_C( 32), UINT8_C( 95) } },
    { { UINT8_C(223), UINT8_C(  6), UINT8_C( 10), UINT8_C(139), UINT8_C(207), UINT8_C( 68), UINT8_C(202), UINT8_C(127) },
      { UINT8_C( 72), UINT8_C(101), UINT8_C(198), UINT8_C(108), UINT8_C(235), UINT8_C(187), UINT8_C( 23), UINT8_C(188) },
      { UINT8_C(  3), UINT8_C( 57), UINT8_C(109), UINT8_C(193), UINT8_C( 69), UINT8_C(162), UINT8_C(214), UINT8_C(221) },
      { UINT8_C(232), UINT8_C( 19), UINT8_C( 35), UINT8_C(153), UINT8_C(236), UINT8_C( 91), UINT8_C(205), UINT8_C(151) },
      { UINT8_C(225), UINT8_C(  9), UINT8_C( 16), UINT8_C(142), UINT8_C(214), UINT8_C( 74), UINT8_C(203), UINT8_C(133) },
      { UINT8_C(224), UINT8_C(  8), UINT8_C( 13), UINT8_C(141), UINT8_C(211), UINT8_C( 71), UINT8_C(202), UINT8_C(130) },
      { UINT8_C(223), UINT8_C(  6), UINT8_C( 11), UINT8_C(139), UINT8_C(208), UINT8_C( 69), UINT8_C(202), UINT8_C(128) } },
    { { UINT8_C( 86), UINT8_C(240), UINT8_C( 44), UINT8_C(221), UINT8_C(206), UINT8_C( 75), UINT8_C( 61), UINT8_C(227) },
      { UINT8_C( 39), UINT8_C( 24), UINT8_C( 12), UINT8_C( 64), UINT8_C(179), UINT8_C(223), UINT8_C( 95), UINT8_C(147) },
      { UINT8_C(106), UINT8_C(252), UINT8_C( 50), UINT8_C(253), UINT8_C( 40), UINT8_C(187), UINT8_C(109), UINT8_C( 45) },
      { UINT8_C( 91), UINT8_C(243), UINT8_C( 46), UINT8_C(229), UINT8_C(228), UINT8_C(103), UINT8_C( 73), UINT8_C(245) },
      { UINT8_C( 87), UINT8_C(241), UINT8_C( 44), UINT8_C(223), UINT8_C(212), UINT8_C( 82), UINT8_C( 64), UINT8_C(232) },
      { UINT8_C( 87), UINT8_C(240), UINT8_C( 44), UINT8_C(222), UINT8_C(209), UINT8_C( 78), UINT8_C( 62), UINT8_C(229) },
      { UINT8_C( 86), UINT8_C(240), UINT8_C( 44), UINT8_C(221), UINT8_C(207), UINT8_C( 76), UINT8_C( 61), UINT8_C(228) } },
    { { UINT8_C(229), UINT8_C(105), UINT8_C( 30), UINT8_C(180), UINT8_C(173), UINT8_C(233), UINT8_C( 52), UINT8_C(245) },
      { UINT8_C( 78), UINT8_C(250), UINT8_C( 97), UINT8_C( 57), UINT8_C(181), UINT8_C(120), UINT8_C(246), UINT8_C( 11) },
      { UINT8_C( 12), UINT8_C(230), UINT8_C( 79), UINT8_C(209), UINT8_C(  8), UINT8_C( 37), UINT8_C(175), UINT8_C(251) },
      { UINT8_C(239), UINT8_C(136), UINT8_C( 42), UINT8_C(187), UINT8_C(196), UINT8_C(248), UINT8_C( 83), UINT8_C(246) },
      { UINT8_C(231), UINT8_C(113), UINT8_C( 33), UINT8_C(182), UINT8_C(179), UINT8_C(237), UINT8_C( 60), UINT8_C(245) },
      { UINT8_C(230), UINT8_C(109), UINT8_C( 32), UINT8_C(181), UINT8_C(176), UINT8_C(235), UINT8_C( 56), UINT8_C(245) },
      { UINT8_C(229), UINT8_C(106), UINT8_C( 30), UINT8_C(180), UINT8_C(174), UINT8_C(233), UINT8_C( 53), UINT8_C(245) } },
    { { UINT8_C(104), UINT8_C( 34), UINT8_C(233), UINT8_C( 54), UINT8_C(109), UINT8_C( 38), UINT8_C( 26), UINT8_C(148) },
      { UINT8_C( 62), UINT8_C( 38), UINT8_C(212), UINT8_C(241), UINT8_C(  5), UINT8_C( 51), UINT8_C(132), UINT8_C(234) },
      { UINT8_C(135), UINT8_C( 53), UINT8_C( 83), UINT8_C(175), UINT8_C(112), UINT8_C( 64), UINT8_C( 92), UINT8_C(  9) },
      { UINT8_C(112), UINT8_C( 39), UINT8_C(  4), UINT8_C( 84), UINT8_C(110), UINT8_C( 44), UINT8_C( 43), UINT8_C(177) },
      { UINT8_C(106), UINT8_C( 35), UINT8_C(240), UINT8_C( 62), UINT8_C(109), UINT8_C( 40), UINT8_C( 30), UINT8_C(155) },
      { UINT8_C(105), UINT8_C( 35), UINT8_C(236), UINT8_C( 58), UINT8_C(109), UINT8_C( 39), UINT8_C( 28), UINT8_C(152) },
      { UINT8_C(104), UINT8_C( 34), UINT8_C(234), UINT8_C( 55), UINT8_C(109), UINT8_C( 38), UINT8_C( 27), UINT8_C(149) } },
    { { UINT8_C(157), UINT8_C(163), UINT8_C(159), UINT8_C( 74), UINT8_C(140), UINT8_C(211), UINT8_C( 64), UINT8_C(218) },
      { UINT8_C(205), UINT8_C(161), UINT8_C( 19), UINT8_C(130), UINT8_C( 26), UINT8_C(  9), UINT8_C(142), UINT8_C(130) },
      { UINT8_C(  4), UINT8_C(244), UINT8_C(169), UINT8_C(139), UINT8_C(153), UINT8_C(216), UINT8_C(135), UINT8_C( 27) },
      { UINT8_C(183), UINT8_C(183), UINT8_C(161), UINT8_C( 90), UINT8_C(143), UINT8_C(212), UINT8_C( 82), UINT8_C(234) },
      { UINT8_C(163), UINT8_C(168), UINT8_C(160), UINT8_C( 78), UINT8_C(141), UINT8_C(211), UINT8_C( 68), UINT8_C(222) },
      { UINT8_C(160), UINT8_C(166), UINT8_C(159), UINT8_C( 76), UINT8_C(140), UINT8_C(211), UINT8_C( 66), UINT8_C(220) },
      { UINT8_C(158), UINT8_C(164), UINT8_C(159), UINT8_C( 75), UINT8_C(140), UINT8_C(211), UINT8_C( 65), UINT8_C(219) } },
    { { UINT8_C( 43), UINT8_C(119), UINT8_C(185), UINT8_C(152), UINT8_C(157), UINT8_C(211), UINT8_C( 44), UINT8_C(219) },
      { UINT8_C(249), UINT8_C(  1), UINT8_C(204),    UINT8_MAX, UINT8_C( 52), UINT8_C( 81), UINT8_C(233), UINT8_C(209) },
      { UINT8_C(168), UINT8_C(120), UINT8_C( 31), UINT8_C( 24), UINT8_C(183), UINT8_C(252), UINT8_C(161), UINT8_C( 68) },
      { UINT8_C( 74), UINT8_C(119), UINT8_C(211), UINT8_C(184), UINT8_C(164), UINT8_C(221), UINT8_C( 73), UINT8_C(245) },
      { UINT8_C( 51), UINT8_C(119), UINT8_C(191), UINT8_C(160), UINT8_C(159), UINT8_C(214), UINT8_C( 51), UINT8_C(226) },
      { UINT8_C( 47), UINT8_C(119), UINT8_C(188), UINT8_C(156), UINT8_C(158), UINT8_C(212), UINT8_C( 48), UINT8_C(222) },
      { UINT8_C( 44), UINT8_C(119), UINT8_C(186), UINT8_C(153), UINT8_C(157), UINT8_C(211), UINT8_C( 45), UINT8_C(220) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);

    simde_uint8x8_t r1 = simde_vrsra_n_u8(a, b, 1);
    simde_uint8x8_t r3 = simde_vrsra_n_u8(a, b, 3);
    simde_uint8x8_t r5 = simde_vrsra_n_u8(a, b, 5);
    simde_uint8x8_t r6 = simde_vrsra_n_u8(a, b, 6);
    simde_uint8x8_t r8 = simde_vrsra_n_u8(a, b, 8);

    simde_test_arm_neon_assert_equal_u8x8(r1, simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r6, simde_vld1_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x8(r8, simde_vld1_u8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vrsra_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { UINT16_C( 9797), UINT16_C( 3708), UINT16_C( 3895), UINT16_C(56667) },
      { UINT16_C(40416), UINT16_C(18906), UINT16_C(39683), UINT16_C(49020) },
      { UINT16_C(14849), UINT16_C( 6071), UINT16_C( 8855), UINT16_C(62795) },
      { UINT16_C(10429), UINT16_C( 4003), UINT16_C( 4515), UINT16_C(57433) },
      { UINT16_C( 9836), UINT16_C( 3726), UINT16_C( 3934), UINT16_C(56715) },
      { UINT16_C( 9802), UINT16_C( 3710), UINT16_C( 3900), UINT16_C(56673) },
      { UINT16_C( 9798), UINT16_C( 3708), UINT16_C( 3896), UINT16_C(56668) } },
    { { UINT16_C(27645), UINT16_C( 2893), UINT16_C(44795), UINT16_C(45319) },
      { UINT16_C(59352), UINT16_C(25814), UINT16_C(46436), UINT16_C(43587) },
      { UINT16_C(35064), UINT16_C( 6120), UINT16_C(50600), UINT16_C(50767) },
      { UINT16_C(28572), UINT16_C( 3296), UINT16_C(45521), UINT16_C(46000) },
      { UINT16_C(27703), UINT16_C( 2918), UINT16_C(44840), UINT16_C(45362) },
      { UINT16_C(27652), UINT16_C( 2896), UINT16_C(44801), UINT16_C(45324) },
      { UINT16_C(27646), UINT16_C( 2893), UINT16_C(44796), UINT16_C(45320) } },
    { { UINT16_C(49115), UINT16_C( 5048), UINT16_C( 5326), UINT16_C(44784) },
      { UINT16_C(51889), UINT16_C(46327), UINT16_C(29797), UINT16_C(25459) },
      { UINT16_C(55601), UINT16_C(10839), UINT16_C( 9051), UINT16_C(47966) },
      { UINT16_C(49926), UINT16_C( 5772), UINT16_C( 5792), UINT16_C(45182) },
      { UINT16_C(49166), UINT16_C( 5093), UINT16_C( 5355), UINT16_C(44809) },
      { UINT16_C(49121), UINT16_C( 5054), UINT16_C( 5330), UINT16_C(44787) },
      { UINT16_C(49116), UINT16_C( 5049), UINT16_C( 5326), UINT16_C(44784) } },
    { { UINT16_C(49631), UINT16_C(55918), UINT16_C(30319), UINT16_C(18315) },
      { UINT16_C(24925), UINT16_C(49579), UINT16_C(60951), UINT16_C(62059) },
      { UINT16_C(52747), UINT16_C(62115), UINT16_C(37938), UINT16_C(26072) },
      { UINT16_C(50020), UINT16_C(56693), UINT16_C(31271), UINT16_C(19285) },
      { UINT16_C(49655), UINT16_C(55966), UINT16_C(30379), UINT16_C(18376) },
      { UINT16_C(49634), UINT16_C(55924), UINT16_C(30326), UINT16_C(18323) },
      { UINT16_C(49631), UINT16_C(55919), UINT16_C(30320), UINT16_C(18316) } },
    { { UINT16_C( 9389), UINT16_C(31749), UINT16_C(62776), UINT16_C(59690) },
      { UINT16_C( 8895), UINT16_C( 9630), UINT16_C( 4502), UINT16_C(30088) },
      { UINT16_C(10501), UINT16_C(32953), UINT16_C(63339), UINT16_C(63451) },
      { UINT16_C( 9528), UINT16_C(31899), UINT16_C(62846), UINT16_C(60160) },
      { UINT16_C( 9398), UINT16_C(31758), UINT16_C(62780), UINT16_C(59719) },
      { UINT16_C( 9390), UINT16_C(31750), UINT16_C(62777), UINT16_C(59694) },
      { UINT16_C( 9389), UINT16_C(31749), UINT16_C(62776), UINT16_C(59690) } },
    { { UINT16_C(63186), UINT16_C(16719), UINT16_C(55916), UINT16_C(51593) },
      { UINT16_C(13371), UINT16_C(21131), UINT16_C(63011), UINT16_C(53317) },
      { UINT16_C(64857), UINT16_C(19360), UINT16_C(63792), UINT16_C(58258) },
      { UINT16_C(63395), UINT16_C(17049), UINT16_C(56901), UINT16_C(52426) },
      { UINT16_C(63199), UINT16_C(16740), UINT16_C(55978), UINT16_C(51645) },
      { UINT16_C(63188), UINT16_C(16722), UINT16_C(55924), UINT16_C(51600) },
      { UINT16_C(63186), UINT16_C(16719), UINT16_C(55917), UINT16_C(51594) } },
    { { UINT16_C(18970), UINT16_C(21068), UINT16_C(30528), UINT16_C(65340) },
      { UINT16_C(55961), UINT16_C(12068), UINT16_C(44267), UINT16_C(48804) },
      { UINT16_C(25965), UINT16_C(22577), UINT16_C(36061), UINT16_C( 5905) },
      { UINT16_C(19844), UINT16_C(21257), UINT16_C(31220), UINT16_C(  567) },
      { UINT16_C(19025), UINT16_C(21080), UINT16_C(30571), UINT16_C(65388) },
      { UINT16_C(18977), UINT16_C(21069), UINT16_C(30533), UINT16_C(65346) },
      { UINT16_C(18971), UINT16_C(21068), UINT16_C(30529), UINT16_C(65341) } },
    { { UINT16_C(62371), UINT16_C( 4095), UINT16_C(35021), UINT16_C( 2265) },
      { UINT16_C(25789), UINT16_C(57435), UINT16_C(41050), UINT16_C(30128) },
      { UINT16_C(   59), UINT16_C(11274), UINT16_C(40152), UINT16_C( 6031) },
      { UINT16_C(62774), UINT16_C( 4992), UINT16_C(35662), UINT16_C( 2736) },
      { UINT16_C(62396), UINT16_C( 4151), UINT16_C(35061), UINT16_C( 2294) },
      { UINT16_C(62374), UINT16_C( 4102), UINT16_C(35026), UINT16_C( 2269) },
      { UINT16_C(62371), UINT16_C( 4096), UINT16_C(35022), UINT16_C( 2265) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);

    simde_uint16x4_t r3 = simde_vrsra_n_u16(a, b, 3);
    simde_uint16x4_t r6 = simde_vrsra_n_u16(a, b, 6);
    simde_uint16x4_t r10 = simde_vrsra_n_u16(a, b, 10);
    simde_uint16x4_t r13 = simde_vrsra_n_u16(a, b, 13);
    simde_uint16x4_t r16 = simde_vrsra_n_u16(a, b, 16);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r16, simde_vld1_u16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vrsra_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { UINT32_C(2856545990), UINT32_C(3559013179) },
      { UINT32_C(1802418243), UINT32_C(1802606704) },
      { UINT32_C(2884708775), UINT32_C(3587178909) },
      { UINT32_C(2856766012), UINT32_C(3559233224) },
      { UINT32_C(2856549428), UINT32_C(3559016617) },
      { UINT32_C(2856546017), UINT32_C(3559013206) },
      { UINT32_C(2856545990), UINT32_C(3559013179) } },
    { { UINT32_C( 120642863), UINT32_C(3323490355) },
      { UINT32_C(1871857396), UINT32_C( 336916046) },
      { UINT32_C( 149890635), UINT32_C(3328754668) },
      { UINT32_C( 120871361), UINT32_C(3323531482) },
      { UINT32_C( 120646433), UINT32_C(3323490998) },
      { UINT32_C( 120642891), UINT32_C(3323490360) },
      { UINT32_C( 120642863), UINT32_C(3323490355) } },
    { { UINT32_C(2545899356), UINT32_C(3597394322) },
      { UINT32_C( 155310745), UINT32_C(2708779890) },
      { UINT32_C(2548326086), UINT32_C(3639719008) },
      { UINT32_C(2545918315), UINT32_C(3597724984) },
      { UINT32_C(2545899652), UINT32_C(3597399489) },
      { UINT32_C(2545899358), UINT32_C(3597394362) },
      { UINT32_C(2545899356), UINT32_C(3597394323) } },
    { { UINT32_C(3282609296), UINT32_C( 160022804) },
      { UINT32_C(1450711815), UINT32_C(1701481481) },
      { UINT32_C(3305276668), UINT32_C( 186608452) },
      { UINT32_C(3282786385), UINT32_C( 160230504) },
      { UINT32_C(3282612063), UINT32_C( 160026049) },
      { UINT32_C(3282609318), UINT32_C( 160022829) },
      { UINT32_C(3282609296), UINT32_C( 160022804) } },
    { { UINT32_C(1996302820), UINT32_C(2739693578) },
      { UINT32_C(3048050242), UINT32_C(3512082753) },
      { UINT32_C(2043928605), UINT32_C(2794569871) },
      { UINT32_C(1996674896), UINT32_C(2740122299) },
      { UINT32_C(1996308634), UINT32_C(2739700277) },
      { UINT32_C(1996302865), UINT32_C(2739693630) },
      { UINT32_C(1996302821), UINT32_C(2739693579) } },
    { { UINT32_C(3667197894), UINT32_C(3353550272) },
      { UINT32_C(1109220408), UINT32_C(3433531624) },
      { UINT32_C(3684529463), UINT32_C(3407199204) },
      { UINT32_C(3667333297), UINT32_C(3353969404) },
      { UINT32_C(3667200010), UINT32_C(3353556821) },
      { UINT32_C(3667197911), UINT32_C(3353550323) },
      { UINT32_C(3667197894), UINT32_C(3353550273) } },
    { { UINT32_C(3158549681), UINT32_C(1331662605) },
      { UINT32_C(1577323549), UINT32_C(4096744238) },
      { UINT32_C(3183195361), UINT32_C(1395674234) },
      { UINT32_C(3158742225), UINT32_C(1332162696) },
      { UINT32_C(3158552690), UINT32_C(1331670419) },
      { UINT32_C(3158549705), UINT32_C(1331662666) },
      { UINT32_C(3158549681), UINT32_C(1331662606) } },
    { { UINT32_C( 449758042), UINT32_C( 434221792) },
      { UINT32_C(4133224206), UINT32_C( 952304263) },
      { UINT32_C( 514339670), UINT32_C( 449101546) },
      { UINT32_C( 450262586), UINT32_C( 434338040) },
      { UINT32_C( 449765925), UINT32_C( 434223608) },
      { UINT32_C( 449758104), UINT32_C( 434221806) },
      { UINT32_C( 449758043), UINT32_C( 434221792) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);

    simde_uint32x2_t r6 = simde_vrsra_n_u32(a, b, 6);
    simde_uint32x2_t r13 = simde_vrsra_n_u32(a, b, 13);
    simde_uint32x2_t r19 = simde_vrsra_n_u32(a, b, 19);
    simde_uint32x2_t r26 = simde_vrsra_n_u32(a, b, 26);
    simde_uint32x2_t r32 = simde_vrsra_n_u32(a, b, 32);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r32, simde_vld1_u32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vrsra_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r13[1];
    uint64_t r26[1];
    uint64_t r39[1];
    uint64_t r52[1];
    uint64_t r64[1];
  } test_vec[] = {
    { { UINT64_C(10648944995671283270) },
      { UINT64_C(11505581380092416709) },
      { UINT64_C(10650349485585845333) },
      { UINT64_C(10648945167117806044) },
      { UINT64_C(10648944995692211801) },
      { UINT64_C(10648944995671285825) },
      { UINT64_C(10648944995671283271) } },
    { { UINT64_C( 1360706969982614345) },
      { UINT64_C( 8710257663316107129) },
      { UINT64_C( 1361770233857530862) },
      { UINT64_C( 1360707099775567826) },
      { UINT64_C( 1360706969998458211) },
      { UINT64_C( 1360706969982616279) },
      { UINT64_C( 1360706969982614345) } },
    { { UINT64_C(17781570536506952227) },
      { UINT64_C(15606091530443261350) },
      { UINT64_C(17783475576976977039) },
      { UINT64_C(17781570769055837728) },
      { UINT64_C(17781570536535339542) },
      { UINT64_C(17781570536506955692) },
      { UINT64_C(17781570536506952228) } },
    { { UINT64_C( 8578899884654840372) },
      { UINT64_C( 6028486122644644862) },
      { UINT64_C( 8579635783839733517) },
      { UINT64_C( 8578899974486283840) },
      { UINT64_C( 8578899884665806124) },
      { UINT64_C( 8578899884654841711) },
      { UINT64_C( 8578899884654840372) } },
    { { UINT64_C( 3399734522907243782) },
      { UINT64_C(12192853280877214670) },
      { UINT64_C( 3401222908317507114) },
      { UINT64_C( 3399734704594915933) },
      { UINT64_C( 3399734522929422453) },
      { UINT64_C( 3399734522907246489) },
      { UINT64_C( 3399734522907243783) } },
    { { UINT64_C( 1222362336126677633) },
      { UINT64_C( 1394684376301801943) },
      { UINT64_C( 1222532585684331662) },
      { UINT64_C( 1222362356909094339) },
      { UINT64_C( 1222362336129214549) },
      { UINT64_C( 1222362336126677943) },
      { UINT64_C( 1222362336126677633) } },
    { { UINT64_C(17679296120834744224) },
      { UINT64_C(13120260273628937717) },
      { UINT64_C(17680897715106427444) },
      { UINT64_C(17679296316341857467) },
      { UINT64_C(17679296120858609838) },
      { UINT64_C(17679296120834747137) },
      { UINT64_C(17679296120834744225) } },
    { { UINT64_C( 4925578365873011001) },
      { UINT64_C( 2800296166150610108) },
      { UINT64_C( 4925920198901105558) },
      { UINT64_C( 4925578407600675563) },
      { UINT64_C( 4925578365878104710) },
      { UINT64_C( 4925578365873011623) },
      { UINT64_C( 4925578365873011001) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);

    simde_uint64x1_t r13 = simde_vrsra_n_u64(a, b, 13);
    simde_uint64x1_t r26 = simde_vrsra_n_u64(a, b, 26);
    simde_uint64x1_t r39 = simde_vrsra_n_u64(a, b, 39);
    simde_uint64x1_t r52 = simde_vrsra_n_u64(a, b, 52);
    simde_uint64x1_t r64 = simde_vrsra_n_u64(a, b, 64);

    simde_test_arm_neon_assert_equal_u64x1(r13, simde_vld1_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x1(r26, simde_vld1_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x1(r39, simde_vld1_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x1(r52, simde_vld1_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x1(r64, simde_vld1_u64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vrsraq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r8[16];
  } test_vec[] = {
    { {  INT8_C( 105), -INT8_C(  86),  INT8_C(  14), -INT8_C( 118), -INT8_C(   4),  INT8_C(  43),  INT8_C(  78), -INT8_C(   2),
        -INT8_C(  92), -INT8_C(  12), -INT8_C(  99),  INT8_C(  44),  INT8_C(  42),  INT8_C(   9),  INT8_C(   5), -INT8_C(  70) },
      { -INT8_C(  84),  INT8_C(  58),  INT8_C(  42), -INT8_C(  63),  INT8_C(  24), -INT8_C(  44), -INT8_C( 126), -INT8_C(  42),
         INT8_C(  85),  INT8_C( 117), -INT8_C(  70),  INT8_C( 115),  INT8_C(  19),  INT8_C( 117),  INT8_C(  39),  INT8_C( 124) },
      {  INT8_C(  63), -INT8_C(  57),  INT8_C(  35),  INT8_C( 107),  INT8_C(   8),  INT8_C(  21),  INT8_C(  15), -INT8_C(  23),
        -INT8_C(  49),  INT8_C(  47),  INT8_C( 122),  INT8_C( 102),  INT8_C(  52),  INT8_C(  68),  INT8_C(  25), -INT8_C(   8) },
      {  INT8_C(  95), -INT8_C(  79),  INT8_C(  19), -INT8_C( 126), -INT8_C(   1),  INT8_C(  38),  INT8_C(  62), -INT8_C(   7),
        -INT8_C(  81),  INT8_C(   3), -INT8_C( 108),  INT8_C(  58),  INT8_C(  44),  INT8_C(  24),  INT8_C(  10), -INT8_C(  54) },
      {  INT8_C( 102), -INT8_C(  84),  INT8_C(  15), -INT8_C( 120), -INT8_C(   3),  INT8_C(  42),  INT8_C(  74), -INT8_C(   3),
        -INT8_C(  89), -INT8_C(   8), -INT8_C( 101),  INT8_C(  48),  INT8_C(  43),  INT8_C(  13),  INT8_C(   6), -INT8_C(  66) },
      {  INT8_C( 104), -INT8_C(  85),  INT8_C(  15), -INT8_C( 119), -INT8_C(   4),  INT8_C(  42),  INT8_C(  76), -INT8_C(   3),
        -INT8_C(  91), -INT8_C(  10), -INT8_C( 100),  INT8_C(  46),  INT8_C(  42),  INT8_C(  11),  INT8_C(   6), -INT8_C(  68) },
      {  INT8_C( 105), -INT8_C(  86),  INT8_C(  14), -INT8_C( 118), -INT8_C(   4),  INT8_C(  43),  INT8_C(  78), -INT8_C(   2),
        -INT8_C(  92), -INT8_C(  12), -INT8_C(  99),  INT8_C(  44),  INT8_C(  42),  INT8_C(   9),  INT8_C(   5), -INT8_C(  70) } },
    { {  INT8_C(  32),  INT8_C(  53),  INT8_C(   7),  INT8_C(  28),  INT8_C(  97),  INT8_C(  85),  INT8_C(  26),  INT8_C(   5),
         INT8_C(  73), -INT8_C(  73),  INT8_C(  49),  INT8_C( 115), -INT8_C(  63),  INT8_C(  54),  INT8_C(  45),  INT8_C( 109) },
      {  INT8_C( 112),  INT8_C(  87),  INT8_C(  46), -INT8_C( 120),  INT8_C(  43), -INT8_C(  80),  INT8_C(  95), -INT8_C( 127),
         INT8_C(  37),  INT8_C(  25), -INT8_C(  12),  INT8_C(  57), -INT8_C( 114),  INT8_C(  27), -INT8_C(  75), -INT8_C(  82) },
      {  INT8_C(  88),  INT8_C(  97),  INT8_C(  30), -INT8_C(  32),  INT8_C( 119),  INT8_C(  45),  INT8_C(  74), -INT8_C(  58),
         INT8_C(  92), -INT8_C(  60),  INT8_C(  43), -INT8_C( 112), -INT8_C( 120),  INT8_C(  68),  INT8_C(   8),  INT8_C(  68) },
      {  INT8_C(  46),  INT8_C(  64),  INT8_C(  13),  INT8_C(  13),  INT8_C( 102),  INT8_C(  75),  INT8_C(  38), -INT8_C(  11),
         INT8_C(  78), -INT8_C(  70),  INT8_C(  48),  INT8_C( 122), -INT8_C(  77),  INT8_C(  57),  INT8_C(  36),  INT8_C(  99) },
      {  INT8_C(  36),  INT8_C(  56),  INT8_C(   8),  INT8_C(  24),  INT8_C(  98),  INT8_C(  83),  INT8_C(  29),  INT8_C(   1),
         INT8_C(  74), -INT8_C(  72),  INT8_C(  49),  INT8_C( 117), -INT8_C(  67),  INT8_C(  55),  INT8_C(  43),  INT8_C( 106) },
      {  INT8_C(  34),  INT8_C(  54),  INT8_C(   8),  INT8_C(  26),  INT8_C(  98),  INT8_C(  84),  INT8_C(  27),  INT8_C(   3),
         INT8_C(  74), -INT8_C(  73),  INT8_C(  49),  INT8_C( 116), -INT8_C(  65),  INT8_C(  54),  INT8_C(  44),  INT8_C( 108) },
      {  INT8_C(  32),  INT8_C(  53),  INT8_C(   7),  INT8_C(  28),  INT8_C(  97),  INT8_C(  85),  INT8_C(  26),  INT8_C(   5),
         INT8_C(  73), -INT8_C(  73),  INT8_C(  49),  INT8_C( 115), -INT8_C(  63),  INT8_C(  54),  INT8_C(  45),  INT8_C( 109) } },
    { {  INT8_C(  80), -INT8_C(  68), -INT8_C(  54), -INT8_C(  79),  INT8_C(  17), -INT8_C(  27), -INT8_C(  74),  INT8_C(  90),
        -INT8_C( 100), -INT8_C(  25), -INT8_C(  51),  INT8_C(  93),  INT8_C(  29), -INT8_C(   5), -INT8_C(  54), -INT8_C( 115) },
      {  INT8_C(  82), -INT8_C(   8),  INT8_C(  22),  INT8_C( 126), -INT8_C(  87),  INT8_C( 117), -INT8_C(   1), -INT8_C(  50),
        -INT8_C( 114), -INT8_C(  13),  INT8_C(   7),  INT8_C(  28),  INT8_C(  14), -INT8_C(  67), -INT8_C(  53),  INT8_C(  94) },
      {  INT8_C( 121), -INT8_C(  72), -INT8_C(  43), -INT8_C(  16), -INT8_C(  26),  INT8_C(  32), -INT8_C(  74),  INT8_C(  65),
         INT8_C(  99), -INT8_C(  31), -INT8_C(  47),  INT8_C( 107),  INT8_C(  36), -INT8_C(  38), -INT8_C(  80), -INT8_C(  68) },
      {  INT8_C(  90), -INT8_C(  69), -INT8_C(  51), -INT8_C(  63),  INT8_C(   6), -INT8_C(  12), -INT8_C(  74),  INT8_C(  84),
        -INT8_C( 114), -INT8_C(  27), -INT8_C(  50),  INT8_C(  97),  INT8_C(  31), -INT8_C(  13), -INT8_C(  61), -INT8_C( 103) },
      {  INT8_C(  83), -INT8_C(  68), -INT8_C(  53), -INT8_C(  75),  INT8_C(  14), -INT8_C(  23), -INT8_C(  74),  INT8_C(  88),
        -INT8_C( 104), -INT8_C(  25), -INT8_C(  51),  INT8_C(  94),  INT8_C(  29), -INT8_C(   7), -INT8_C(  56), -INT8_C( 112) },
      {  INT8_C(  81), -INT8_C(  68), -INT8_C(  54), -INT8_C(  77),  INT8_C(  16), -INT8_C(  25), -INT8_C(  74),  INT8_C(  89),
        -INT8_C( 102), -INT8_C(  25), -INT8_C(  51),  INT8_C(  93),  INT8_C(  29), -INT8_C(   6), -INT8_C(  55), -INT8_C( 114) },
      {  INT8_C(  80), -INT8_C(  68), -INT8_C(  54), -INT8_C(  79),  INT8_C(  17), -INT8_C(  27), -INT8_C(  74),  INT8_C(  90),
        -INT8_C( 100), -INT8_C(  25), -INT8_C(  51),  INT8_C(  93),  INT8_C(  29), -INT8_C(   5), -INT8_C(  54), -INT8_C( 115) } },
    { {  INT8_C( 121), -INT8_C( 107),  INT8_C(  16), -INT8_C( 117),  INT8_C( 122), -INT8_C(  58), -INT8_C(  27),  INT8_C(  23),
        -INT8_C(  82), -INT8_C(  77),  INT8_C( 116), -INT8_C(  53), -INT8_C(  82),  INT8_C(  63),  INT8_C(  89),  INT8_C(   0) },
      {  INT8_C(  55),  INT8_C( 111),  INT8_C( 126), -INT8_C(  32), -INT8_C(  28),  INT8_C( 125), -INT8_C(  81),  INT8_C( 114),
         INT8_C( 112), -INT8_C(  74), -INT8_C( 114),  INT8_C( 126),  INT8_C( 115),  INT8_C(  89), -INT8_C(  35), -INT8_C(  19) },
      { -INT8_C( 107), -INT8_C(  51),  INT8_C(  79),  INT8_C( 123),  INT8_C( 108),  INT8_C(   5), -INT8_C(  67),  INT8_C(  80),
        -INT8_C(  26), -INT8_C( 114),  INT8_C(  59),  INT8_C(  10), -INT8_C(  24),  INT8_C( 108),  INT8_C(  72), -INT8_C(   9) },
      {      INT8_MIN, -INT8_C(  93),  INT8_C(  32), -INT8_C( 121),  INT8_C( 119), -INT8_C(  42), -INT8_C(  37),  INT8_C(  37),
        -INT8_C(  68), -INT8_C(  86),  INT8_C( 102), -INT8_C(  37), -INT8_C(  68),  INT8_C(  74),  INT8_C(  85), -INT8_C(   2) },
      {  INT8_C( 123), -INT8_C( 104),  INT8_C(  20), -INT8_C( 118),  INT8_C( 121), -INT8_C(  54), -INT8_C(  30),  INT8_C(  27),
        -INT8_C(  78), -INT8_C(  79),  INT8_C( 112), -INT8_C(  49), -INT8_C(  78),  INT8_C(  66),  INT8_C(  88), -INT8_C(   1) },
      {  INT8_C( 122), -INT8_C( 105),  INT8_C(  18), -INT8_C( 117),  INT8_C( 122), -INT8_C(  56), -INT8_C(  28),  INT8_C(  25),
        -INT8_C(  80), -INT8_C(  78),  INT8_C( 114), -INT8_C(  51), -INT8_C(  80),  INT8_C(  64),  INT8_C(  88),  INT8_C(   0) },
      {  INT8_C( 121), -INT8_C( 107),  INT8_C(  16), -INT8_C( 117),  INT8_C( 122), -INT8_C(  58), -INT8_C(  27),  INT8_C(  23),
        -INT8_C(  82), -INT8_C(  77),  INT8_C( 116), -INT8_C(  53), -INT8_C(  82),  INT8_C(  63),  INT8_C(  89),  INT8_C(   0) } },
    { { -INT8_C(  17), -INT8_C(  19),  INT8_C( 120),  INT8_C( 105), -INT8_C(  77),  INT8_C(  93),      INT8_MIN,  INT8_C(  97),
         INT8_C(  16), -INT8_C(  11),  INT8_C(  45), -INT8_C(  66),  INT8_C(  52), -INT8_C( 122), -INT8_C(  65),  INT8_C( 107) },
      { -INT8_C(  11),  INT8_C(  61),  INT8_C(  76), -INT8_C(  39), -INT8_C(  69), -INT8_C(   5),  INT8_C(  75),  INT8_C(  43),
        -INT8_C(  79), -INT8_C(  39), -INT8_C(  86),  INT8_C(  37),  INT8_C(  51), -INT8_C( 121),  INT8_C(  18),  INT8_C(  34) },
      { -INT8_C(  22),  INT8_C(  12), -INT8_C(  98),  INT8_C(  86), -INT8_C( 111),  INT8_C(  91), -INT8_C(  90),  INT8_C( 119),
        -INT8_C(  23), -INT8_C(  30),  INT8_C(   2), -INT8_C(  47),  INT8_C(  78),  INT8_C(  74), -INT8_C(  56),  INT8_C( 124) },
      { -INT8_C(  18), -INT8_C(  11), -INT8_C( 126),  INT8_C( 100), -INT8_C(  86),  INT8_C(  92), -INT8_C( 119),  INT8_C( 102),
         INT8_C(   6), -INT8_C(  16),  INT8_C(  34), -INT8_C(  61),  INT8_C(  58),  INT8_C( 119), -INT8_C(  63),  INT8_C( 111) },
      { -INT8_C(  17), -INT8_C(  17),  INT8_C( 122),  INT8_C( 104), -INT8_C(  79),  INT8_C(  93), -INT8_C( 126),  INT8_C(  98),
         INT8_C(  14), -INT8_C(  12),  INT8_C(  42), -INT8_C(  65),  INT8_C(  54), -INT8_C( 126), -INT8_C(  64),  INT8_C( 108) },
      { -INT8_C(  17), -INT8_C(  18),  INT8_C( 121),  INT8_C( 104), -INT8_C(  78),  INT8_C(  93), -INT8_C( 127),  INT8_C(  98),
         INT8_C(  15), -INT8_C(  12),  INT8_C(  44), -INT8_C(  65),  INT8_C(  53), -INT8_C( 124), -INT8_C(  65),  INT8_C( 108) },
      { -INT8_C(  17), -INT8_C(  19),  INT8_C( 120),  INT8_C( 105), -INT8_C(  77),  INT8_C(  93),      INT8_MIN,  INT8_C(  97),
         INT8_C(  16), -INT8_C(  11),  INT8_C(  45), -INT8_C(  66),  INT8_C(  52), -INT8_C( 122), -INT8_C(  65),  INT8_C( 107) } },
    { {  INT8_C( 116), -INT8_C( 118), -INT8_C( 117),  INT8_C(  39), -INT8_C(  25),  INT8_C(  12), -INT8_C( 119), -INT8_C(   8),
         INT8_C(   1), -INT8_C(  74), -INT8_C(  74),  INT8_C(  53),  INT8_C(  60),  INT8_C( 117), -INT8_C(  96),  INT8_C(  49) },
      { -INT8_C(  77), -INT8_C(  20),  INT8_C(  10),  INT8_C( 110), -INT8_C(  25),  INT8_C(  85), -INT8_C( 103), -INT8_C( 103),
         INT8_C(  46),  INT8_C(  67), -INT8_C(  66),  INT8_C(  97), -INT8_C(  54), -INT8_C(  48), -INT8_C( 125),  INT8_C(  62) },
      {  INT8_C(  78),      INT8_MIN, -INT8_C( 112),  INT8_C(  94), -INT8_C(  37),  INT8_C(  55),  INT8_C(  86), -INT8_C(  59),
         INT8_C(  24), -INT8_C(  40), -INT8_C( 107),  INT8_C( 102),  INT8_C(  33),  INT8_C(  93),  INT8_C(  98),  INT8_C(  80) },
      {  INT8_C( 106), -INT8_C( 120), -INT8_C( 116),  INT8_C(  53), -INT8_C(  28),  INT8_C(  23),  INT8_C( 124), -INT8_C(  21),
         INT8_C(   7), -INT8_C(  66), -INT8_C(  82),  INT8_C(  65),  INT8_C(  53),  INT8_C( 111), -INT8_C( 112),  INT8_C(  57) },
      {  INT8_C( 114), -INT8_C( 119), -INT8_C( 117),  INT8_C(  42), -INT8_C(  26),  INT8_C(  15), -INT8_C( 122), -INT8_C(  11),
         INT8_C(   2), -INT8_C(  72), -INT8_C(  76),  INT8_C(  56),  INT8_C(  58),  INT8_C( 116), -INT8_C( 100),  INT8_C(  51) },
      {  INT8_C( 115), -INT8_C( 118), -INT8_C( 117),  INT8_C(  41), -INT8_C(  25),  INT8_C(  13), -INT8_C( 121), -INT8_C(  10),
         INT8_C(   2), -INT8_C(  73), -INT8_C(  75),  INT8_C(  55),  INT8_C(  59),  INT8_C( 116), -INT8_C(  98),  INT8_C(  50) },
      {  INT8_C( 116), -INT8_C( 118), -INT8_C( 117),  INT8_C(  39), -INT8_C(  25),  INT8_C(  12), -INT8_C( 119), -INT8_C(   8),
         INT8_C(   1), -INT8_C(  74), -INT8_C(  74),  INT8_C(  53),  INT8_C(  60),  INT8_C( 117), -INT8_C(  96),  INT8_C(  49) } },
    { {  INT8_C(  90),  INT8_C(  15),  INT8_C( 102),  INT8_C(  65),  INT8_C(  27), -INT8_C(  17),  INT8_C(  57),  INT8_C(  28),
        -INT8_C(  91), -INT8_C(  16),  INT8_C(  81), -INT8_C(  31),  INT8_C( 101), -INT8_C(  15),  INT8_C(  18),  INT8_C(  24) },
      { -INT8_C(  34),  INT8_C(  28), -INT8_C( 122), -INT8_C(  59),  INT8_C( 113),  INT8_C(  32),  INT8_C(  94), -INT8_C(  97),
         INT8_C(  99),  INT8_C(  28),  INT8_C(   1),  INT8_C(  46), -INT8_C(  20), -INT8_C( 124),  INT8_C( 108),  INT8_C(  70) },
      {  INT8_C(  73),  INT8_C(  29),  INT8_C(  41),  INT8_C(  36),  INT8_C(  84), -INT8_C(   1),  INT8_C( 104), -INT8_C(  20),
        -INT8_C(  41), -INT8_C(   2),  INT8_C(  82), -INT8_C(   8),  INT8_C(  91), -INT8_C(  77),  INT8_C(  72),  INT8_C(  59) },
      {  INT8_C(  86),  INT8_C(  19),  INT8_C(  87),  INT8_C(  58),  INT8_C(  41), -INT8_C(  13),  INT8_C(  69),  INT8_C(  16),
        -INT8_C(  79), -INT8_C(  12),  INT8_C(  81), -INT8_C(  25),  INT8_C(  99), -INT8_C(  30),  INT8_C(  32),  INT8_C(  33) },
      {  INT8_C(  89),  INT8_C(  16),  INT8_C(  98),  INT8_C(  63),  INT8_C(  31), -INT8_C(  16),  INT8_C(  60),  INT8_C(  25),
        -INT8_C(  88), -INT8_C(  15),  INT8_C(  81), -INT8_C(  30),  INT8_C( 100), -INT8_C(  19),  INT8_C(  21),  INT8_C(  26) },
      {  INT8_C(  89),  INT8_C(  15),  INT8_C( 100),  INT8_C(  64),  INT8_C(  29), -INT8_C(  16),  INT8_C(  58),  INT8_C(  26),
        -INT8_C(  89), -INT8_C(  16),  INT8_C(  81), -INT8_C(  30),  INT8_C( 101), -INT8_C(  17),  INT8_C(  20),  INT8_C(  25) },
      {  INT8_C(  90),  INT8_C(  15),  INT8_C( 102),  INT8_C(  65),  INT8_C(  27), -INT8_C(  17),  INT8_C(  57),  INT8_C(  28),
        -INT8_C(  91), -INT8_C(  16),  INT8_C(  81), -INT8_C(  31),  INT8_C( 101), -INT8_C(  15),  INT8_C(  18),  INT8_C(  24) } },
    { { -INT8_C( 109), -INT8_C(  46), -INT8_C( 120), -INT8_C(  82), -INT8_C(  63), -INT8_C(  63), -INT8_C(  54),  INT8_C( 102),
        -INT8_C(  79),  INT8_C(  27),  INT8_C(  71),  INT8_C(  23),  INT8_C(  13),  INT8_C(  89),  INT8_C(  47), -INT8_C(  21) },
      {  INT8_C( 117), -INT8_C(  74), -INT8_C(  80), -INT8_C(  26), -INT8_C(  42),  INT8_C(  15), -INT8_C( 122),  INT8_C(  57),
         INT8_C(  43), -INT8_C( 121),  INT8_C( 103),  INT8_C(  24),  INT8_C(  11), -INT8_C(  44),  INT8_C(  94), -INT8_C(  97) },
      { -INT8_C(  50), -INT8_C(  83),  INT8_C(  96), -INT8_C(  95), -INT8_C(  84), -INT8_C(  55), -INT8_C( 115), -INT8_C( 125),
        -INT8_C(  57), -INT8_C(  33),  INT8_C( 123),  INT8_C(  35),  INT8_C(  19),  INT8_C(  67),  INT8_C(  94), -INT8_C(  69) },
      { -INT8_C(  94), -INT8_C(  55),  INT8_C( 126), -INT8_C(  85), -INT8_C(  68), -INT8_C(  61), -INT8_C(  69),  INT8_C( 109),
        -INT8_C(  74),  INT8_C(  12),  INT8_C(  84),  INT8_C(  26),  INT8_C(  14),  INT8_C(  84),  INT8_C(  59), -INT8_C(  33) },
      { -INT8_C( 105), -INT8_C(  48), -INT8_C( 122), -INT8_C(  83), -INT8_C(  64), -INT8_C(  63), -INT8_C(  58),  INT8_C( 104),
        -INT8_C(  78),  INT8_C(  23),  INT8_C(  74),  INT8_C(  24),  INT8_C(  13),  INT8_C(  88),  INT8_C(  50), -INT8_C(  24) },
      { -INT8_C( 107), -INT8_C(  47), -INT8_C( 121), -INT8_C(  82), -INT8_C(  64), -INT8_C(  63), -INT8_C(  56),  INT8_C( 103),
        -INT8_C(  78),  INT8_C(  25),  INT8_C(  73),  INT8_C(  23),  INT8_C(  13),  INT8_C(  88),  INT8_C(  48), -INT8_C(  23) },
      { -INT8_C( 109), -INT8_C(  46), -INT8_C( 120), -INT8_C(  82), -INT8_C(  63), -INT8_C(  63), -INT8_C(  54),  INT8_C( 102),
        -INT8_C(  79),  INT8_C(  27),  INT8_C(  71),  INT8_C(  23),  INT8_C(  13),  INT8_C(  89),  INT8_C(  47), -INT8_C(  21) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);

    simde_int8x16_t r1 = simde_vrsraq_n_s8(a, b, 1);
    simde_int8x16_t r3 = simde_vrsraq_n_s8(a, b, 3);
    simde_int8x16_t r5 = simde_vrsraq_n_s8(a, b, 5);
    simde_int8x16_t r6 = simde_vrsraq_n_s8(a, b, 6);
    simde_int8x16_t r8 = simde_vrsraq_n_s8(a, b, 8);

    simde_test_arm_neon_assert_equal_i8x16(r1, simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r6, simde_vld1q_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x16(r8, simde_vld1q_s8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vrsraq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { {  INT16_C( 27213), -INT16_C( 15621),  INT16_C(  4695), -INT16_C( 22303), -INT16_C( 26590), -INT16_C(  9749),  INT16_C(  9982), -INT16_C(  6778) },
      {  INT16_C( 19972), -INT16_C( 25942), -INT16_C( 22797),  INT16_C( 18834), -INT16_C(  5405), -INT16_C( 30691), -INT16_C(  3556),  INT16_C( 27120) },
      {  INT16_C( 29710), -INT16_C( 18864),  INT16_C(  1845), -INT16_C( 19949), -INT16_C( 27266), -INT16_C( 13585),  INT16_C(  9538), -INT16_C(  3388) },
      {  INT16_C( 27525), -INT16_C( 16026),  INT16_C(  4339), -INT16_C( 22009), -INT16_C( 26674), -INT16_C( 10229),  INT16_C(  9926), -INT16_C(  6354) },
      {  INT16_C( 27233), -INT16_C( 15646),  INT16_C(  4673), -INT16_C( 22285), -INT16_C( 26595), -INT16_C(  9779),  INT16_C(  9979), -INT16_C(  6752) },
      {  INT16_C( 27215), -INT16_C( 15624),  INT16_C(  4692), -INT16_C( 22301), -INT16_C( 26591), -INT16_C(  9753),  INT16_C(  9982), -INT16_C(  6775) },
      {  INT16_C( 27213), -INT16_C( 15621),  INT16_C(  4695), -INT16_C( 22303), -INT16_C( 26590), -INT16_C(  9749),  INT16_C(  9982), -INT16_C(  6778) } },
    { { -INT16_C(  5284), -INT16_C( 19669),  INT16_C(  3582),  INT16_C(  8283),  INT16_C( 18085), -INT16_C( 23303),  INT16_C( 32620),  INT16_C( 28809) },
      {  INT16_C( 13261), -INT16_C( 16374), -INT16_C( 25382), -INT16_C( 17143),  INT16_C(  9863), -INT16_C( 23738),  INT16_C( 13849),  INT16_C( 29965) },
      { -INT16_C(  3626), -INT16_C( 21716),  INT16_C(   409),  INT16_C(  6140),  INT16_C( 19318), -INT16_C( 26270), -INT16_C( 31185),  INT16_C( 32555) },
      { -INT16_C(  5077), -INT16_C( 19925),  INT16_C(  3185),  INT16_C(  8015),  INT16_C( 18239), -INT16_C( 23674), -INT16_C( 32700),  INT16_C( 29277) },
      { -INT16_C(  5271), -INT16_C( 19685),  INT16_C(  3557),  INT16_C(  8266),  INT16_C( 18095), -INT16_C( 23326),  INT16_C( 32634),  INT16_C( 28838) },
      { -INT16_C(  5282), -INT16_C( 19671),  INT16_C(  3579),  INT16_C(  8281),  INT16_C( 18086), -INT16_C( 23306),  INT16_C( 32622),  INT16_C( 28813) },
      { -INT16_C(  5284), -INT16_C( 19669),  INT16_C(  3582),  INT16_C(  8283),  INT16_C( 18085), -INT16_C( 23303),  INT16_C( 32620),  INT16_C( 28809) } },
    { {  INT16_C( 14370),  INT16_C(  8233), -INT16_C( 31675), -INT16_C(  5312),  INT16_C( 14795),  INT16_C( 14223),  INT16_C(  6328), -INT16_C( 31320) },
      { -INT16_C( 19893),  INT16_C(  9541),  INT16_C( 20303), -INT16_C( 10525),  INT16_C( 10613), -INT16_C( 29063), -INT16_C( 31137), -INT16_C( 32508) },
      {  INT16_C( 11883),  INT16_C(  9426), -INT16_C( 29137), -INT16_C(  6628),  INT16_C( 16122),  INT16_C( 10590),  INT16_C(  2436),  INT16_C( 30153) },
      {  INT16_C( 14059),  INT16_C(  8382), -INT16_C( 31358), -INT16_C(  5476),  INT16_C( 14961),  INT16_C( 13769),  INT16_C(  5841), -INT16_C( 31828) },
      {  INT16_C( 14351),  INT16_C(  8242), -INT16_C( 31655), -INT16_C(  5322),  INT16_C( 14805),  INT16_C( 14195),  INT16_C(  6298), -INT16_C( 31352) },
      {  INT16_C( 14368),  INT16_C(  8234), -INT16_C( 31673), -INT16_C(  5313),  INT16_C( 14796),  INT16_C( 14219),  INT16_C(  6324), -INT16_C( 31324) },
      {  INT16_C( 14370),  INT16_C(  8233), -INT16_C( 31675), -INT16_C(  5312),  INT16_C( 14795),  INT16_C( 14223),  INT16_C(  6328), -INT16_C( 31320) } },
    { {  INT16_C( 11711),  INT16_C(  1185), -INT16_C(  7759),  INT16_C( 31983),  INT16_C( 32282), -INT16_C( 11596),  INT16_C( 23702), -INT16_C(  7593) },
      { -INT16_C( 25330),  INT16_C( 23815), -INT16_C(  5396),  INT16_C( 24883), -INT16_C( 21229),  INT16_C( 29680), -INT16_C(  3021), -INT16_C(  3340) },
      {  INT16_C(  8545),  INT16_C(  4162), -INT16_C(  8433), -INT16_C( 30443),  INT16_C( 29628), -INT16_C(  7886),  INT16_C( 23324), -INT16_C(  8010) },
      {  INT16_C( 11315),  INT16_C(  1557), -INT16_C(  7843),  INT16_C( 32372),  INT16_C( 31950), -INT16_C( 11132),  INT16_C( 23655), -INT16_C(  7645) },
      {  INT16_C( 11686),  INT16_C(  1208), -INT16_C(  7764),  INT16_C( 32007),  INT16_C( 32261), -INT16_C( 11567),  INT16_C( 23699), -INT16_C(  7596) },
      {  INT16_C( 11708),  INT16_C(  1188), -INT16_C(  7760),  INT16_C( 31986),  INT16_C( 32279), -INT16_C( 11592),  INT16_C( 23702), -INT16_C(  7593) },
      {  INT16_C( 11711),  INT16_C(  1185), -INT16_C(  7759),  INT16_C( 31983),  INT16_C( 32282), -INT16_C( 11596),  INT16_C( 23702), -INT16_C(  7593) } },
    { { -INT16_C( 27103), -INT16_C( 11529), -INT16_C(  6537), -INT16_C( 28081),  INT16_C(   869), -INT16_C(  1180), -INT16_C( 17313),  INT16_C( 28125) },
      { -INT16_C(  6823),  INT16_C( 17867), -INT16_C(   305), -INT16_C(  7258), -INT16_C( 26965), -INT16_C(  8362),  INT16_C( 19082), -INT16_C( 21551) },
      { -INT16_C( 27956), -INT16_C(  9296), -INT16_C(  6575), -INT16_C( 28988), -INT16_C(  2502), -INT16_C(  2225), -INT16_C( 14928),  INT16_C( 25431) },
      { -INT16_C( 27210), -INT16_C( 11250), -INT16_C(  6542), -INT16_C( 28194),  INT16_C(   448), -INT16_C(  1311), -INT16_C( 17015),  INT16_C( 27788) },
      { -INT16_C( 27110), -INT16_C( 11512), -INT16_C(  6537), -INT16_C( 28088),  INT16_C(   843), -INT16_C(  1188), -INT16_C( 17294),  INT16_C( 28104) },
      { -INT16_C( 27104), -INT16_C( 11527), -INT16_C(  6537), -INT16_C( 28082),  INT16_C(   866), -INT16_C(  1181), -INT16_C( 17311),  INT16_C( 28122) },
      { -INT16_C( 27103), -INT16_C( 11529), -INT16_C(  6537), -INT16_C( 28081),  INT16_C(   869), -INT16_C(  1180), -INT16_C( 17313),  INT16_C( 28125) } },
    { { -INT16_C( 14112),  INT16_C( 22654), -INT16_C( 12881),  INT16_C(  5354),  INT16_C( 20176),  INT16_C( 12047), -INT16_C(  4854),  INT16_C( 25500) },
      {  INT16_C( 26578), -INT16_C( 24152),  INT16_C( 20326),  INT16_C(  4484), -INT16_C(  9499),  INT16_C( 28912), -INT16_C( 15835),  INT16_C(  1307) },
      { -INT16_C( 10790),  INT16_C( 19635), -INT16_C( 10340),  INT16_C(  5915),  INT16_C( 18989),  INT16_C( 15661), -INT16_C(  6833),  INT16_C( 25663) },
      { -INT16_C( 13697),  INT16_C( 22277), -INT16_C( 12563),  INT16_C(  5424),  INT16_C( 20028),  INT16_C( 12499), -INT16_C(  5101),  INT16_C( 25520) },
      { -INT16_C( 14086),  INT16_C( 22630), -INT16_C( 12861),  INT16_C(  5358),  INT16_C( 20167),  INT16_C( 12075), -INT16_C(  4869),  INT16_C( 25501) },
      { -INT16_C( 14109),  INT16_C( 22651), -INT16_C( 12879),  INT16_C(  5355),  INT16_C( 20175),  INT16_C( 12051), -INT16_C(  4856),  INT16_C( 25500) },
      { -INT16_C( 14112),  INT16_C( 22654), -INT16_C( 12881),  INT16_C(  5354),  INT16_C( 20176),  INT16_C( 12047), -INT16_C(  4854),  INT16_C( 25500) } },
    { { -INT16_C( 26230),  INT16_C( 14685),  INT16_C( 18278),  INT16_C( 13901),  INT16_C( 23958), -INT16_C( 24475),  INT16_C(   586),  INT16_C(  7172) },
      { -INT16_C( 21399), -INT16_C( 12355),  INT16_C( 17147), -INT16_C(  7711), -INT16_C( 12004),  INT16_C( 16721),  INT16_C( 27795),  INT16_C(  7751) },
      { -INT16_C( 28905),  INT16_C( 13141),  INT16_C( 20421),  INT16_C( 12937),  INT16_C( 22458), -INT16_C( 22385),  INT16_C(  4060),  INT16_C(  8141) },
      { -INT16_C( 26564),  INT16_C( 14492),  INT16_C( 18546),  INT16_C( 13781),  INT16_C( 23770), -INT16_C( 24214),  INT16_C(  1020),  INT16_C(  7293) },
      { -INT16_C( 26251),  INT16_C( 14673),  INT16_C( 18295),  INT16_C( 13893),  INT16_C( 23946), -INT16_C( 24459),  INT16_C(   613),  INT16_C(  7180) },
      { -INT16_C( 26233),  INT16_C( 14683),  INT16_C( 18280),  INT16_C( 13900),  INT16_C( 23957), -INT16_C( 24473),  INT16_C(   589),  INT16_C(  7173) },
      { -INT16_C( 26230),  INT16_C( 14685),  INT16_C( 18278),  INT16_C( 13901),  INT16_C( 23958), -INT16_C( 24475),  INT16_C(   586),  INT16_C(  7172) } },
    { { -INT16_C( 23546),  INT16_C( 27735), -INT16_C( 23060), -INT16_C( 32093),  INT16_C(  2050),  INT16_C( 19490),  INT16_C(  9738),  INT16_C( 29800) },
      {  INT16_C(  9683), -INT16_C( 12733),  INT16_C(  9319), -INT16_C( 31569),  INT16_C(   246), -INT16_C( 30267),  INT16_C(  3181),  INT16_C( 29607) },
      { -INT16_C( 22336),  INT16_C( 26143), -INT16_C( 21895),  INT16_C( 29497),  INT16_C(  2081),  INT16_C( 15707),  INT16_C( 10136), -INT16_C( 32035) },
      { -INT16_C( 23395),  INT16_C( 27536), -INT16_C( 22914), -INT16_C( 32586),  INT16_C(  2054),  INT16_C( 19017),  INT16_C(  9788),  INT16_C( 30263) },
      { -INT16_C( 23537),  INT16_C( 27723), -INT16_C( 23051), -INT16_C( 32124),  INT16_C(  2050),  INT16_C( 19460),  INT16_C(  9741),  INT16_C( 29829) },
      { -INT16_C( 23545),  INT16_C( 27733), -INT16_C( 23059), -INT16_C( 32097),  INT16_C(  2050),  INT16_C( 19486),  INT16_C(  9738),  INT16_C( 29804) },
      { -INT16_C( 23546),  INT16_C( 27735), -INT16_C( 23060), -INT16_C( 32093),  INT16_C(  2050),  INT16_C( 19490),  INT16_C(  9738),  INT16_C( 29800) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);

    simde_int16x8_t r3 = simde_vrsraq_n_s16(a, b, 3);
    simde_int16x8_t r6 = simde_vrsraq_n_s16(a, b, 6);
    simde_int16x8_t r10 = simde_vrsraq_n_s16(a, b, 10);
    simde_int16x8_t r13 = simde_vrsraq_n_s16(a, b, 13);
    simde_int16x8_t r16 = simde_vrsraq_n_s16(a, b, 16);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r16, simde_vld1q_s16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vrsraq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r32[4];
  } test_vec[] = {
    { {  INT32_C(  1502172043), -INT32_C(   504641461),  INT32_C(  1553063998),  INT32_C(  1523463707) },
      {  INT32_C(   563728537),  INT32_C(  1127529576),  INT32_C(   252291388),  INT32_C(  1861909731) },
      {  INT32_C(  1510980301), -INT32_C(   487023811),  INT32_C(  1557006051),  INT32_C(  1552556047) },
      {  INT32_C(  1502240858), -INT32_C(   504503823),  INT32_C(  1553094795),  INT32_C(  1523690991) },
      {  INT32_C(  1502173118), -INT32_C(   504639310),  INT32_C(  1553064479),  INT32_C(  1523467258) },
      {  INT32_C(  1502172051), -INT32_C(   504641444),  INT32_C(  1553064002),  INT32_C(  1523463735) },
      {  INT32_C(  1502172043), -INT32_C(   504641461),  INT32_C(  1553063998),  INT32_C(  1523463707) } },
    { {  INT32_C(   449283023), -INT32_C(  1963216308), -INT32_C(  1377399662),  INT32_C(  1544074435) },
      { -INT32_C(   327310972), -INT32_C(  1724927395),  INT32_C(  1051212123), -INT32_C(  2069060939) },
      {  INT32_C(   444168789), -INT32_C(  1990168299), -INT32_C(  1360974473),  INT32_C(  1511745358) },
      {  INT32_C(   449243068), -INT32_C(  1963426870), -INT32_C(  1377271340),  INT32_C(  1543821864) },
      {  INT32_C(   449282399), -INT32_C(  1963219598), -INT32_C(  1377397657),  INT32_C(  1544070489) },
      {  INT32_C(   449283018), -INT32_C(  1963216334), -INT32_C(  1377399646),  INT32_C(  1544074404) },
      {  INT32_C(   449283023), -INT32_C(  1963216308), -INT32_C(  1377399662),  INT32_C(  1544074435) } },
    { {  INT32_C(  1922986790), -INT32_C(  1191405018), -INT32_C(   379133402),  INT32_C(   440823446) },
      {  INT32_C(  1829159695), -INT32_C(   804899211),  INT32_C(   604942191),  INT32_C(  2007546449) },
      {  INT32_C(  1951567410), -INT32_C(  1203981568), -INT32_C(   369681180),  INT32_C(   472191359) },
      {  INT32_C(  1923210076), -INT32_C(  1191503272), -INT32_C(   379059557),  INT32_C(   441068508) },
      {  INT32_C(  1922990279), -INT32_C(  1191406553), -INT32_C(   379132248),  INT32_C(   440827275) },
      {  INT32_C(  1922986817), -INT32_C(  1191405030), -INT32_C(   379133393),  INT32_C(   440823476) },
      {  INT32_C(  1922986790), -INT32_C(  1191405018), -INT32_C(   379133402),  INT32_C(   440823446) } },
    { {  INT32_C(  1424573998),  INT32_C(   118285792),  INT32_C(  1576039111), -INT32_C(   260622624) },
      {  INT32_C(  1868398330),  INT32_C(   591422388),  INT32_C(  1682394642),  INT32_C(   937160457) },
      {  INT32_C(  1453767722),  INT32_C(   127526767),  INT32_C(  1602326527), -INT32_C(   245979492) },
      {  INT32_C(  1424802074),  INT32_C(   118357987),  INT32_C(  1576244481), -INT32_C(   260508225) },
      {  INT32_C(  1424577562),  INT32_C(   118286920),  INT32_C(  1576042320), -INT32_C(   260620837) },
      {  INT32_C(  1424574026),  INT32_C(   118285801),  INT32_C(  1576039136), -INT32_C(   260622610) },
      {  INT32_C(  1424573998),  INT32_C(   118285792),  INT32_C(  1576039111), -INT32_C(   260622624) } },
    { {  INT32_C(   378258741),  INT32_C(  1914541994), -INT32_C(   355529462),  INT32_C(  1054492484) },
      {  INT32_C(  2041395141), -INT32_C(  1382224485),  INT32_C(  1158800188),  INT32_C(   125627858) },
      {  INT32_C(   410155540),  INT32_C(  1892944736), -INT32_C(   337423209),  INT32_C(  1056455419) },
      {  INT32_C(   378507935),  INT32_C(  1914373265), -INT32_C(   355388007),  INT32_C(  1054507819) },
      {  INT32_C(   378262635),  INT32_C(  1914539358), -INT32_C(   355527252),  INT32_C(  1054492724) },
      {  INT32_C(   378258771),  INT32_C(  1914541973), -INT32_C(   355529445),  INT32_C(  1054492486) },
      {  INT32_C(   378258741),  INT32_C(  1914541994), -INT32_C(   355529462),  INT32_C(  1054492484) } },
    { {  INT32_C(  1545406386), -INT32_C(  1462879586), -INT32_C(  1936482744), -INT32_C(  1429574171) },
      {  INT32_C(  1076066213), -INT32_C(  1578254491),  INT32_C(  1961295778), -INT32_C(  1636080916) },
      {  INT32_C(  1562219921), -INT32_C(  1487539812), -INT32_C(  1905837497), -INT32_C(  1455137935) },
      {  INT32_C(  1545537742), -INT32_C(  1463072244), -INT32_C(  1936243328), -INT32_C(  1429773888) },
      {  INT32_C(  1545408438), -INT32_C(  1462882596), -INT32_C(  1936479003), -INT32_C(  1429577292) },
      {  INT32_C(  1545406402), -INT32_C(  1462879610), -INT32_C(  1936482715), -INT32_C(  1429574195) },
      {  INT32_C(  1545406386), -INT32_C(  1462879586), -INT32_C(  1936482744), -INT32_C(  1429574171) } },
    { {  INT32_C(   133863785),  INT32_C(   464570835),  INT32_C(  1286030183),  INT32_C(  1442214320) },
      {  INT32_C(  1318394345),  INT32_C(  2062517208),  INT32_C(  1861145986), -INT32_C(  1609799369) },
      {  INT32_C(   154463697),  INT32_C(   496797666),  INT32_C(  1315110589),  INT32_C(  1417061205) },
      {  INT32_C(   134024722),  INT32_C(   464822607),  INT32_C(  1286257374),  INT32_C(  1442017811) },
      {  INT32_C(   133866300),  INT32_C(   464574769),  INT32_C(  1286033733),  INT32_C(  1442211250) },
      {  INT32_C(   133863805),  INT32_C(   464570866),  INT32_C(  1286030211),  INT32_C(  1442214296) },
      {  INT32_C(   133863785),  INT32_C(   464570835),  INT32_C(  1286030183),  INT32_C(  1442214320) } },
    { { -INT32_C(   693697022),  INT32_C(   921786319),  INT32_C(  1266850202), -INT32_C(   207587318) },
      {  INT32_C(  1765881489),  INT32_C(  1004744889),  INT32_C(  1017762053),  INT32_C(  1037874491) },
      { -INT32_C(   666105124),  INT32_C(   937485458),  INT32_C(  1282752734), -INT32_C(   191370529) },
      { -INT32_C(   693481460),  INT32_C(   921908969),  INT32_C(  1266974441), -INT32_C(   207460624) },
      { -INT32_C(   693693654),  INT32_C(   921788235),  INT32_C(  1266852143), -INT32_C(   207585338) },
      { -INT32_C(   693696996),  INT32_C(   921786334),  INT32_C(  1266850217), -INT32_C(   207587303) },
      { -INT32_C(   693697022),  INT32_C(   921786319),  INT32_C(  1266850202), -INT32_C(   207587318) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);

    simde_int32x4_t r6 = simde_vrsraq_n_s32(a, b, 6);
    simde_int32x4_t r13 = simde_vrsraq_n_s32(a, b, 13);
    simde_int32x4_t r19 = simde_vrsraq_n_s32(a, b, 19);
    simde_int32x4_t r26 = simde_vrsraq_n_s32(a, b, 26);
    simde_int32x4_t r32 = simde_vrsraq_n_s32(a, b, 32);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r32, simde_vld1q_s32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vrsraq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r13[2];
    int64_t r26[2];
    int64_t r39[2];
    int64_t r52[2];
    int64_t r64[2];
  } test_vec[] = {
    { {  INT64_C( 4041353125507396115), -INT64_C( 5314258365561655216) },
      {  INT64_C( 7313830278785867243),  INT64_C( 2743932506438344679) },
      {  INT64_C( 4042245927055099468), -INT64_C( 5313923412863115379) },
      {  INT64_C( 4041353234491960044), -INT64_C( 5314258324673874633) },
      {  INT64_C( 4041353125520699895), -INT64_C( 5314258365556664032) },
      {  INT64_C( 4041353125507397739), -INT64_C( 5314258365561654607) },
      {  INT64_C( 4041353125507396115), -INT64_C( 5314258365561655216) } },
    { { -INT64_C( 1057029105044103974),  INT64_C( 4845984625688142173) },
      { -INT64_C( 6860630707947583614), -INT64_C(  793388787920162364) },
      { -INT64_C( 1057866584378570232),  INT64_C( 4845887776470866763) },
      { -INT64_C( 1057029207275468045),  INT64_C( 4845984613865727955) },
      { -INT64_C( 1057029105056583389),  INT64_C( 4845984625686699007) },
      { -INT64_C( 1057029105044105497),  INT64_C( 4845984625688141997) },
      { -INT64_C( 1057029105044103974),  INT64_C( 4845984625688142173) } },
    { { -INT64_C( 6863375594008046291), -INT64_C( 3647799926837352763) },
      { -INT64_C( 1330253858463349456),  INT64_C( 5025104695941973679) },
      { -INT64_C( 6863537978512253243), -INT64_C( 3647186510736773909) },
      { -INT64_C( 6863375613830373465), -INT64_C( 3647799851957457673) },
      { -INT64_C( 6863375594010466009), -INT64_C( 3647799926828212151) },
      { -INT64_C( 6863375594008046586), -INT64_C( 3647799926837351647) },
      { -INT64_C( 6863375594008046291), -INT64_C( 3647799926837352763) } },
    { { -INT64_C(  704015982714893225), -INT64_C(  156654237620411461) },
      { -INT64_C( 5508061753547291016),  INT64_C( 7895716240167752758) },
      { -INT64_C(  704688353534418041), -INT64_C(  155690405071562858) },
      { -INT64_C(  704016064791409280), -INT64_C(  156654119965071025) },
      { -INT64_C(  704015982724912331), -INT64_C(  156654237606049237) },
      { -INT64_C(  704015982714894448), -INT64_C(  156654237620409708) },
      { -INT64_C(  704015982714893225), -INT64_C(  156654237620411461) } },
    { {  INT64_C( 4047682171115644932),  INT64_C( 3129739728459284389) },
      { -INT64_C(  301919548837374440), -INT64_C( 8704088626041369935) },
      {  INT64_C( 4047645315701968495),  INT64_C( 3128677217640675823) },
      {  INT64_C( 4047682166616693067),  INT64_C( 3129739598758256727) },
      {  INT64_C( 4047682171115095744),  INT64_C( 3129739728443451744) },
      {  INT64_C( 4047682171115644865),  INT64_C( 3129739728459282456) },
      {  INT64_C( 4047682171115644932),  INT64_C( 3129739728459284389) } },
    { {  INT64_C( 2466539369553214597), -INT64_C( 6843777593601918936) },
      { -INT64_C( 2153973854152829862), -INT64_C( 4116046786669746985) },
      {  INT64_C( 2466276433291721332), -INT64_C( 6844280040719432333) },
      {  INT64_C( 2466539337456502989), -INT64_C( 6843777654935795586) },
      {  INT64_C( 2466539369549296541), -INT64_C( 6843777593609405981) },
      {  INT64_C( 2466539369553214119), -INT64_C( 6843777593601919850) },
      {  INT64_C( 2466539369553214597), -INT64_C( 6843777593601918936) } },
    { { -INT64_C( 5928704661656134375), -INT64_C( 6006236945602556294) },
      { -INT64_C( 4145872490280033437),  INT64_C( 1608630576584073035) },
      { -INT64_C( 5929210749606608012), -INT64_C( 6006040579565375621) },
      { -INT64_C( 5928704723434448642), -INT64_C( 6006236921632092771) },
      { -INT64_C( 5928704661663675673), -INT64_C( 6006236945599630212) },
      { -INT64_C( 5928704661656135296), -INT64_C( 6006236945602555937) },
      { -INT64_C( 5928704661656134375), -INT64_C( 6006236945602556294) } },
    { { -INT64_C( 7435330705155089507),  INT64_C( 5454495663009847732) },
      { -INT64_C( 5810957003708727643),  INT64_C( 1839315258154187636) },
      { -INT64_C( 7436040050492456295),  INT64_C( 5454720188798196632) },
      { -INT64_C( 7435330791745096510),  INT64_C( 5454495690417780880) },
      { -INT64_C( 7435330705165659576),  INT64_C( 5454495663013193427) },
      { -INT64_C( 7435330705155090797),  INT64_C( 5454495663009848140) },
      { -INT64_C( 7435330705155089507),  INT64_C( 5454495663009847732) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);

    simde_int64x2_t r13 = simde_vrsraq_n_s64(a, b, 13);
    simde_int64x2_t r26 = simde_vrsraq_n_s64(a, b, 26);
    simde_int64x2_t r39 = simde_vrsraq_n_s64(a, b, 39);
    simde_int64x2_t r52 = simde_vrsraq_n_s64(a, b, 52);
    simde_int64x2_t r64 = simde_vrsraq_n_s64(a, b, 64);

    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r39, simde_vld1q_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x2(r52, simde_vld1q_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x2(r64, simde_vld1q_s64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vrsraq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { { UINT8_C(218), UINT8_C(246), UINT8_C(246), UINT8_C( 23), UINT8_C(127), UINT8_C(186), UINT8_C(117), UINT8_C( 23),
        UINT8_C( 43), UINT8_C( 33), UINT8_C( 60), UINT8_C(103), UINT8_C(131), UINT8_C(168), UINT8_C(165), UINT8_C( 10) },
      { UINT8_C( 62), UINT8_C(159), UINT8_C( 43), UINT8_C( 70), UINT8_C(213), UINT8_C( 69), UINT8_C(138), UINT8_C( 70),
        UINT8_C( 18), UINT8_C(191), UINT8_C( 88), UINT8_C(148), UINT8_C(  8), UINT8_C(195), UINT8_C( 63), UINT8_C(227) },
      { UINT8_C(249), UINT8_C( 70), UINT8_C( 12), UINT8_C( 58), UINT8_C(234), UINT8_C(221), UINT8_C(186), UINT8_C( 58),
        UINT8_C( 52), UINT8_C(129), UINT8_C(104), UINT8_C(177), UINT8_C(135), UINT8_C( 10), UINT8_C(197), UINT8_C(124) },
      { UINT8_C(226), UINT8_C( 10), UINT8_C(251), UINT8_C( 32), UINT8_C(154), UINT8_C(195), UINT8_C(134), UINT8_C( 32),
        UINT8_C( 45), UINT8_C( 57), UINT8_C( 71), UINT8_C(122), UINT8_C(132), UINT8_C(192), UINT8_C(173), UINT8_C( 38) },
      { UINT8_C(220), UINT8_C(251), UINT8_C(247), UINT8_C( 25), UINT8_C(134), UINT8_C(188), UINT8_C(121), UINT8_C( 25),
        UINT8_C( 44), UINT8_C( 39), UINT8_C( 63), UINT8_C(108), UINT8_C(131), UINT8_C(174), UINT8_C(167), UINT8_C( 17) },
      { UINT8_C(219), UINT8_C(248), UINT8_C(247), UINT8_C( 24), UINT8_C(130), UINT8_C(187), UINT8_C(119), UINT8_C( 24),
        UINT8_C( 43), UINT8_C( 36), UINT8_C( 61), UINT8_C(105), UINT8_C(131), UINT8_C(171), UINT8_C(166), UINT8_C( 14) },
      { UINT8_C(218), UINT8_C(247), UINT8_C(246), UINT8_C( 23), UINT8_C(128), UINT8_C(186), UINT8_C(118), UINT8_C( 23),
        UINT8_C( 43), UINT8_C( 34), UINT8_C( 60), UINT8_C(104), UINT8_C(131), UINT8_C(169), UINT8_C(165), UINT8_C( 11) } },
    { { UINT8_C(186), UINT8_C( 53), UINT8_C(250), UINT8_C( 57), UINT8_C(239), UINT8_C(112), UINT8_C( 80), UINT8_C( 27),
        UINT8_C(145), UINT8_C(141), UINT8_C(130), UINT8_C( 20), UINT8_C( 53), UINT8_C( 39), UINT8_C( 30), UINT8_C(115) },
      { UINT8_C(199), UINT8_C( 73), UINT8_C(186), UINT8_C(156), UINT8_C(142), UINT8_C( 68), UINT8_C(226), UINT8_C(161),
        UINT8_C(  3), UINT8_C( 59), UINT8_C( 53), UINT8_C( 12), UINT8_C(254), UINT8_C(116), UINT8_C(239), UINT8_C(184) },
      { UINT8_C( 30), UINT8_C( 90), UINT8_C( 87), UINT8_C(135), UINT8_C( 54), UINT8_C(146), UINT8_C(193), UINT8_C(108),
        UINT8_C(147), UINT8_C(171), UINT8_C(157), UINT8_C( 26), UINT8_C(180), UINT8_C( 97), UINT8_C(150), UINT8_C(207) },
      { UINT8_C(211), UINT8_C( 62), UINT8_C( 17), UINT8_C( 77), UINT8_C(  1), UINT8_C(121), UINT8_C(108), UINT8_C( 47),
        UINT8_C(145), UINT8_C(148), UINT8_C(137), UINT8_C( 22), UINT8_C( 85), UINT8_C( 54), UINT8_C( 60), UINT8_C(138) },
      { UINT8_C(192), UINT8_C( 55), UINT8_C(  0), UINT8_C( 62), UINT8_C(243), UINT8_C(114), UINT8_C( 87), UINT8_C( 32),
        UINT8_C(145), UINT8_C(143), UINT8_C(132), UINT8_C( 20), UINT8_C( 61), UINT8_C( 43), UINT8_C( 37), UINT8_C(121) },
      { UINT8_C(189), UINT8_C( 54), UINT8_C(253), UINT8_C( 59), UINT8_C(241), UINT8_C(113), UINT8_C( 84), UINT8_C( 30),
        UINT8_C(145), UINT8_C(142), UINT8_C(131), UINT8_C( 20), UINT8_C( 57), UINT8_C( 41), UINT8_C( 34), UINT8_C(118) },
      { UINT8_C(187), UINT8_C( 53), UINT8_C(251), UINT8_C( 58), UINT8_C(240), UINT8_C(112), UINT8_C( 81), UINT8_C( 28),
        UINT8_C(145), UINT8_C(141), UINT8_C(130), UINT8_C( 20), UINT8_C( 54), UINT8_C( 39), UINT8_C( 31), UINT8_C(116) } },
    { { UINT8_C(170), UINT8_C(233), UINT8_C(241), UINT8_C(153), UINT8_C( 89), UINT8_C( 66), UINT8_C(180), UINT8_C(234),
        UINT8_C(207), UINT8_C( 54), UINT8_C(254), UINT8_C(  4), UINT8_C( 94), UINT8_C( 29), UINT8_C(120), UINT8_C( 37) },
      { UINT8_C(102), UINT8_C( 50), UINT8_C(193), UINT8_C(245), UINT8_C(118), UINT8_C(163), UINT8_C(150), UINT8_C(122),
        UINT8_C(222), UINT8_C(203), UINT8_C(134), UINT8_C(221), UINT8_C( 64), UINT8_C(117), UINT8_C(149), UINT8_C(234) },
      { UINT8_C(221), UINT8_C(  2), UINT8_C( 82), UINT8_C( 20), UINT8_C(148), UINT8_C(148),    UINT8_MAX, UINT8_C( 39),
        UINT8_C( 62), UINT8_C(156), UINT8_C( 65), UINT8_C(115), UINT8_C(126), UINT8_C( 88), UINT8_C(195), UINT8_C(154) },
      { UINT8_C(183), UINT8_C(239), UINT8_C(  9), UINT8_C(184), UINT8_C(104), UINT8_C( 86), UINT8_C(199), UINT8_C(249),
        UINT8_C(235), UINT8_C( 79), UINT8_C( 15), UINT8_C( 32), UINT8_C(102), UINT8_C( 44), UINT8_C(139), UINT8_C( 66) },
      { UINT8_C(173), UINT8_C(235), UINT8_C(247), UINT8_C(161), UINT8_C( 93), UINT8_C( 71), UINT8_C(185), UINT8_C(238),
        UINT8_C(214), UINT8_C( 60), UINT8_C(  2), UINT8_C( 11), UINT8_C( 96), UINT8_C( 33), UINT8_C(125), UINT8_C( 44) },
      { UINT8_C(172), UINT8_C(234), UINT8_C(244), UINT8_C(157), UINT8_C( 91), UINT8_C( 69), UINT8_C(182), UINT8_C(236),
        UINT8_C(210), UINT8_C( 57), UINT8_C(  0), UINT8_C(  7), UINT8_C( 95), UINT8_C( 31), UINT8_C(122), UINT8_C( 41) },
      { UINT8_C(170), UINT8_C(233), UINT8_C(242), UINT8_C(154), UINT8_C( 89), UINT8_C( 67), UINT8_C(181), UINT8_C(234),
        UINT8_C(208), UINT8_C( 55),    UINT8_MAX, UINT8_C(  5), UINT8_C( 94), UINT8_C( 29), UINT8_C(121), UINT8_C( 38) } },
    { { UINT8_C( 94), UINT8_C(135), UINT8_C(131), UINT8_C(184), UINT8_C(201), UINT8_C( 56), UINT8_C(162), UINT8_C(152),
        UINT8_C(110), UINT8_C(161), UINT8_C(156), UINT8_C(204), UINT8_C(190), UINT8_C( 20), UINT8_C(241), UINT8_C( 36) },
      { UINT8_C( 70), UINT8_C(178), UINT8_C( 25), UINT8_C(189), UINT8_C( 86), UINT8_C(175), UINT8_C( 55), UINT8_C( 52),
        UINT8_C(123), UINT8_C(189), UINT8_C( 17), UINT8_C(187), UINT8_C( 50), UINT8_C(167), UINT8_C(165), UINT8_C(144) },
      { UINT8_C(129), UINT8_C(224), UINT8_C(144), UINT8_C( 23), UINT8_C(244), UINT8_C(144), UINT8_C(190), UINT8_C(178),
        UINT8_C(172), UINT8_C(  0), UINT8_C(165), UINT8_C( 42), UINT8_C(215), UINT8_C(104), UINT8_C( 68), UINT8_C(108) },
      { UINT8_C(103), UINT8_C(157), UINT8_C(134), UINT8_C(208), UINT8_C(212), UINT8_C( 78), UINT8_C(169), UINT8_C(159),
        UINT8_C(125), UINT8_C(185), UINT8_C(158), UINT8_C(227), UINT8_C(196), UINT8_C( 41), UINT8_C(  6), UINT8_C( 54) },
      { UINT8_C( 96), UINT8_C(141), UINT8_C(132), UINT8_C(190), UINT8_C(204), UINT8_C( 61), UINT8_C(164), UINT8_C(154),
        UINT8_C(114), UINT8_C(167), UINT8_C(157), UINT8_C(210), UINT8_C(192), UINT8_C( 25), UINT8_C(246), UINT8_C( 41) },
      { UINT8_C( 95), UINT8_C(138), UINT8_C(131), UINT8_C(187), UINT8_C(202), UINT8_C( 59), UINT8_C(163), UINT8_C(153),
        UINT8_C(112), UINT8_C(164), UINT8_C(156), UINT8_C(207), UINT8_C(191), UINT8_C( 23), UINT8_C(244), UINT8_C( 38) },
      { UINT8_C( 94), UINT8_C(136), UINT8_C(131), UINT8_C(185), UINT8_C(201), UINT8_C( 57), UINT8_C(162), UINT8_C(152),
        UINT8_C(110), UINT8_C(162), UINT8_C(156), UINT8_C(205), UINT8_C(190), UINT8_C( 21), UINT8_C(242), UINT8_C( 37) } },
    { { UINT8_C( 46), UINT8_C( 40), UINT8_C( 72), UINT8_C(247), UINT8_C( 96), UINT8_C(235), UINT8_C(143), UINT8_C(207),
        UINT8_C(140), UINT8_C( 43), UINT8_C(155), UINT8_C( 74), UINT8_C( 64), UINT8_C(141), UINT8_C(110), UINT8_C(134) },
      { UINT8_C( 63), UINT8_C(136), UINT8_C( 67), UINT8_C(149), UINT8_C( 55), UINT8_C(122), UINT8_C(202), UINT8_C(178),
        UINT8_C( 55), UINT8_C(219), UINT8_C(109), UINT8_C(105), UINT8_C(130), UINT8_C( 18), UINT8_C(250), UINT8_C(176) },
      { UINT8_C( 78), UINT8_C(108), UINT8_C(106), UINT8_C( 66), UINT8_C(124), UINT8_C( 40), UINT8_C(244), UINT8_C( 40),
        UINT8_C(168), UINT8_C(153), UINT8_C(210), UINT8_C(127), UINT8_C(129), UINT8_C(150), UINT8_C(235), UINT8_C(222) },
      { UINT8_C( 54), UINT8_C( 57), UINT8_C( 80), UINT8_C( 10), UINT8_C(103), UINT8_C(250), UINT8_C(168), UINT8_C(229),
        UINT8_C(147), UINT8_C( 70), UINT8_C(169), UINT8_C( 87), UINT8_C( 80), UINT8_C(143), UINT8_C(141), UINT8_C(156) },
      { UINT8_C( 48), UINT8_C( 44), UINT8_C( 74), UINT8_C(252), UINT8_C( 98), UINT8_C(239), UINT8_C(149), UINT8_C(213),
        UINT8_C(142), UINT8_C( 50), UINT8_C(158), UINT8_C( 77), UINT8_C( 68), UINT8_C(142), UINT8_C(118), UINT8_C(140) },
      { UINT8_C( 47), UINT8_C( 42), UINT8_C( 73), UINT8_C(249), UINT8_C( 97), UINT8_C(237), UINT8_C(146), UINT8_C(210),
        UINT8_C(141), UINT8_C( 46), UINT8_C(157), UINT8_C( 76), UINT8_C( 66), UINT8_C(141), UINT8_C(114), UINT8_C(137) },
      { UINT8_C( 46), UINT8_C( 41), UINT8_C( 72), UINT8_C(248), UINT8_C( 96), UINT8_C(235), UINT8_C(144), UINT8_C(208),
        UINT8_C(140), UINT8_C( 44), UINT8_C(155), UINT8_C( 74), UINT8_C( 65), UINT8_C(141), UINT8_C(111), UINT8_C(135) } },
    { { UINT8_C( 59), UINT8_C( 66), UINT8_C(167), UINT8_C(155), UINT8_C( 45), UINT8_C( 54), UINT8_C(106), UINT8_C(185),
        UINT8_C( 98), UINT8_C(  6), UINT8_C(  3), UINT8_C(162), UINT8_C(147), UINT8_C(114), UINT8_C( 40), UINT8_C(210) },
      { UINT8_C(250), UINT8_C(108), UINT8_C(104), UINT8_C( 49), UINT8_C(230), UINT8_C( 50), UINT8_C(228), UINT8_C( 30),
        UINT8_C( 13), UINT8_C( 81), UINT8_C(135), UINT8_C(144), UINT8_C(100), UINT8_C(129), UINT8_C( 64), UINT8_C(159) },
      { UINT8_C(184), UINT8_C(120), UINT8_C(219), UINT8_C(180), UINT8_C(160), UINT8_C( 79), UINT8_C(220), UINT8_C(200),
        UINT8_C(105), UINT8_C( 47), UINT8_C( 71), UINT8_C(234), UINT8_C(197), UINT8_C(179), UINT8_C( 72), UINT8_C( 34) },
      { UINT8_C( 90), UINT8_C( 80), UINT8_C(180), UINT8_C(161), UINT8_C( 74), UINT8_C( 60), UINT8_C(135), UINT8_C(189),
        UINT8_C(100), UINT8_C( 16), UINT8_C( 20), UINT8_C(180), UINT8_C(160), UINT8_C(130), UINT8_C( 48), UINT8_C(230) },
      { UINT8_C( 67), UINT8_C( 69), UINT8_C(170), UINT8_C(157), UINT8_C( 52), UINT8_C( 56), UINT8_C(113), UINT8_C(186),
        UINT8_C( 98), UINT8_C(  9), UINT8_C(  7), UINT8_C(167), UINT8_C(150), UINT8_C(118), UINT8_C( 42), UINT8_C(215) },
      { UINT8_C( 63), UINT8_C( 68), UINT8_C(169), UINT8_C(156), UINT8_C( 49), UINT8_C( 55), UINT8_C(110), UINT8_C(185),
        UINT8_C( 98), UINT8_C(  7), UINT8_C(  5), UINT8_C(164), UINT8_C(149), UINT8_C(116), UINT8_C( 41), UINT8_C(212) },
      { UINT8_C( 60), UINT8_C( 66), UINT8_C(167), UINT8_C(155), UINT8_C( 46), UINT8_C( 54), UINT8_C(107), UINT8_C(185),
        UINT8_C( 98), UINT8_C(  6), UINT8_C(  4), UINT8_C(163), UINT8_C(147), UINT8_C(115), UINT8_C( 40), UINT8_C(211) } },
    { { UINT8_C(196), UINT8_C(232), UINT8_C( 58), UINT8_C(241), UINT8_C( 30), UINT8_C(165), UINT8_C(171), UINT8_C(128),
        UINT8_C(171), UINT8_C(174), UINT8_C( 34), UINT8_C( 62), UINT8_C( 32), UINT8_C( 75), UINT8_C( 16), UINT8_C( 26) },
      { UINT8_C(183), UINT8_C(120), UINT8_C( 76), UINT8_C(157), UINT8_C(170), UINT8_C( 48), UINT8_C(187), UINT8_C(184),
        UINT8_C(129), UINT8_C( 67), UINT8_C( 72), UINT8_C(229), UINT8_C(196), UINT8_C(136), UINT8_C(132), UINT8_C(136) },
      { UINT8_C( 32), UINT8_C( 36), UINT8_C( 96), UINT8_C( 64), UINT8_C(115), UINT8_C(189), UINT8_C(  9), UINT8_C(220),
        UINT8_C(236), UINT8_C(208), UINT8_C( 70), UINT8_C(177), UINT8_C(130), UINT8_C(143), UINT8_C( 82), UINT8_C( 94) },
      { UINT8_C(219), UINT8_C(247), UINT8_C( 68), UINT8_C(  5), UINT8_C( 51), UINT8_C(171), UINT8_C(194), UINT8_C(151),
        UINT8_C(187), UINT8_C(182), UINT8_C( 43), UINT8_C( 91), UINT8_C( 57), UINT8_C( 92), UINT8_C( 33), UINT8_C( 43) },
      { UINT8_C(202), UINT8_C(236), UINT8_C( 60), UINT8_C(246), UINT8_C( 35), UINT8_C(167), UINT8_C(177), UINT8_C(134),
        UINT8_C(175), UINT8_C(176), UINT8_C( 36), UINT8_C( 69), UINT8_C( 38), UINT8_C( 79), UINT8_C( 20), UINT8_C( 30) },
      { UINT8_C(199), UINT8_C(234), UINT8_C( 59), UINT8_C(243), UINT8_C( 33), UINT8_C(166), UINT8_C(174), UINT8_C(131),
        UINT8_C(173), UINT8_C(175), UINT8_C( 35), UINT8_C( 66), UINT8_C( 35), UINT8_C( 77), UINT8_C( 18), UINT8_C( 28) },
      { UINT8_C(197), UINT8_C(232), UINT8_C( 58), UINT8_C(242), UINT8_C( 31), UINT8_C(165), UINT8_C(172), UINT8_C(129),
        UINT8_C(172), UINT8_C(174), UINT8_C( 34), UINT8_C( 63), UINT8_C( 33), UINT8_C( 76), UINT8_C( 17), UINT8_C( 27) } },
    { { UINT8_C(112), UINT8_C(191), UINT8_C(122), UINT8_C(143), UINT8_C(100), UINT8_C( 37), UINT8_C( 15), UINT8_C( 15),
        UINT8_C(211), UINT8_C( 50), UINT8_C( 77), UINT8_C(244), UINT8_C(125), UINT8_C( 93), UINT8_C( 14), UINT8_C( 52) },
      { UINT8_C(214), UINT8_C( 90), UINT8_C(209), UINT8_C(128), UINT8_C(138), UINT8_C(141), UINT8_C( 56), UINT8_C( 12),
        UINT8_C(208), UINT8_C(128), UINT8_C(241), UINT8_C(148), UINT8_C(  9), UINT8_C(118), UINT8_C( 29), UINT8_C(121) },
      { UINT8_C(219), UINT8_C(236), UINT8_C(227), UINT8_C(207), UINT8_C(169), UINT8_C(108), UINT8_C( 43), UINT8_C( 21),
        UINT8_C( 59), UINT8_C(114), UINT8_C(198), UINT8_C( 62), UINT8_C(130), UINT8_C(152), UINT8_C( 29), UINT8_C(113) },
      { UINT8_C(139), UINT8_C(202), UINT8_C(148), UINT8_C(159), UINT8_C(117), UINT8_C( 55), UINT8_C( 22), UINT8_C( 17),
        UINT8_C(237), UINT8_C( 66), UINT8_C(107), UINT8_C(  7), UINT8_C(126), UINT8_C(108), UINT8_C( 18), UINT8_C( 67) },
      { UINT8_C(119), UINT8_C(194), UINT8_C(129), UINT8_C(147), UINT8_C(104), UINT8_C( 41), UINT8_C( 17), UINT8_C( 15),
        UINT8_C(218), UINT8_C( 54), UINT8_C( 85), UINT8_C(249), UINT8_C(125), UINT8_C( 97), UINT8_C( 15), UINT8_C( 56) },
      { UINT8_C(115), UINT8_C(192), UINT8_C(125), UINT8_C(145), UINT8_C(102), UINT8_C( 39), UINT8_C( 16), UINT8_C( 15),
        UINT8_C(214), UINT8_C( 52), UINT8_C( 81), UINT8_C(246), UINT8_C(125), UINT8_C( 95), UINT8_C( 14), UINT8_C( 54) },
      { UINT8_C(113), UINT8_C(191), UINT8_C(123), UINT8_C(144), UINT8_C(101), UINT8_C( 38), UINT8_C( 15), UINT8_C( 15),
        UINT8_C(212), UINT8_C( 51), UINT8_C( 78), UINT8_C(245), UINT8_C(125), UINT8_C( 93), UINT8_C( 14), UINT8_C( 52) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);

    simde_uint8x16_t r1 = simde_vrsraq_n_u8(a, b, 1);
    simde_uint8x16_t r3 = simde_vrsraq_n_u8(a, b, 3);
    simde_uint8x16_t r5 = simde_vrsraq_n_u8(a, b, 5);
    simde_uint8x16_t r6 = simde_vrsraq_n_u8(a, b, 6);
    simde_uint8x16_t r8 = simde_vrsraq_n_u8(a, b, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vrsraq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { { UINT16_C(45310), UINT16_C(11477), UINT16_C(43813), UINT16_C( 3311), UINT16_C(63489), UINT16_C(61402), UINT16_C(30085), UINT16_C( 6127) },
      { UINT16_C( 6624), UINT16_C(38234), UINT16_C(30401), UINT16_C(39166), UINT16_C(25325), UINT16_C(32420), UINT16_C(63541), UINT16_C(13097) },
      { UINT16_C(46138), UINT16_C(16256), UINT16_C(47613), UINT16_C( 8207), UINT16_C( 1119), UINT16_C(65455), UINT16_C(38028), UINT16_C( 7764) },
      { UINT16_C(45414), UINT16_C(12074), UINT16_C(44288), UINT16_C( 3923), UINT16_C(63885), UINT16_C(61909), UINT16_C(31078), UINT16_C( 6332) },
      { UINT16_C(45316), UINT16_C(11514), UINT16_C(43843), UINT16_C( 3349), UINT16_C(63514), UINT16_C(61434), UINT16_C(30147), UINT16_C( 6140) },
      { UINT16_C(45311), UINT16_C(11482), UINT16_C(43817), UINT16_C( 3316), UINT16_C(63492), UINT16_C(61406), UINT16_C(30093), UINT16_C( 6129) },
      { UINT16_C(45310), UINT16_C(11478), UINT16_C(43813), UINT16_C( 3312), UINT16_C(63489), UINT16_C(61402), UINT16_C(30086), UINT16_C( 6127) } },
    { { UINT16_C(65192), UINT16_C(52575), UINT16_C(20138), UINT16_C(43993), UINT16_C(45894), UINT16_C(52123), UINT16_C(35369), UINT16_C( 2530) },
      { UINT16_C(15523), UINT16_C(26014), UINT16_C(40115), UINT16_C(41213), UINT16_C(41471), UINT16_C(13342), UINT16_C(18585), UINT16_C(16743) },
      { UINT16_C( 1596), UINT16_C(55827), UINT16_C(25152), UINT16_C(49145), UINT16_C(51078), UINT16_C(53791), UINT16_C(37692), UINT16_C( 4623) },
      { UINT16_C(65435), UINT16_C(52981), UINT16_C(20765), UINT16_C(44637), UINT16_C(46542), UINT16_C(52331), UINT16_C(35659), UINT16_C( 2792) },
      { UINT16_C(65207), UINT16_C(52600), UINT16_C(20177), UINT16_C(44033), UINT16_C(45934), UINT16_C(52136), UINT16_C(35387), UINT16_C( 2546) },
      { UINT16_C(65194), UINT16_C(52578), UINT16_C(20143), UINT16_C(43998), UINT16_C(45899), UINT16_C(52125), UINT16_C(35371), UINT16_C( 2532) },
      { UINT16_C(65192), UINT16_C(52575), UINT16_C(20139), UINT16_C(43994), UINT16_C(45895), UINT16_C(52123), UINT16_C(35369), UINT16_C( 2530) } },
    { { UINT16_C(50758), UINT16_C(61454), UINT16_C(59412), UINT16_C(23196), UINT16_C(14235), UINT16_C(50213), UINT16_C( 2241), UINT16_C(26061) },
      { UINT16_C(27716), UINT16_C(63434), UINT16_C(50952), UINT16_C( 1943), UINT16_C(46697), UINT16_C(  571), UINT16_C(41726), UINT16_C(17476) },
      { UINT16_C(54223), UINT16_C( 3847), UINT16_C(  245), UINT16_C(23439), UINT16_C(20072), UINT16_C(50284), UINT16_C( 7457), UINT16_C(28246) },
      { UINT16_C(51191), UINT16_C(62445), UINT16_C(60208), UINT16_C(23226), UINT16_C(14965), UINT16_C(50222), UINT16_C( 2893), UINT16_C(26334) },
      { UINT16_C(50785), UINT16_C(61516), UINT16_C(59462), UINT16_C(23198), UINT16_C(14281), UINT16_C(50214), UINT16_C( 2282), UINT16_C(26078) },
      { UINT16_C(50761), UINT16_C(61462), UINT16_C(59418), UINT16_C(23196), UINT16_C(14241), UINT16_C(50213), UINT16_C( 2246), UINT16_C(26063) },
      { UINT16_C(50758), UINT16_C(61455), UINT16_C(59413), UINT16_C(23196), UINT16_C(14236), UINT16_C(50213), UINT16_C( 2242), UINT16_C(26061) } },
    { { UINT16_C(21096), UINT16_C(31797), UINT16_C(53562), UINT16_C(54998), UINT16_C(64520), UINT16_C(51610), UINT16_C(26628), UINT16_C(18478) },
      { UINT16_C(63700), UINT16_C(56384), UINT16_C(55232), UINT16_C(10724), UINT16_C( 8077), UINT16_C(35627), UINT16_C(28610), UINT16_C(10960) },
      { UINT16_C(29059), UINT16_C(38845), UINT16_C(60466), UINT16_C(56339), UINT16_C(65530), UINT16_C(56063), UINT16_C(30204), UINT16_C(19848) },
      { UINT16_C(22091), UINT16_C(32678), UINT16_C(54425), UINT16_C(55166), UINT16_C(64646), UINT16_C(52167), UINT16_C(27075), UINT16_C(18649) },
      { UINT16_C(21158), UINT16_C(31852), UINT16_C(53616), UINT16_C(55008), UINT16_C(64528), UINT16_C(51645), UINT16_C(26656), UINT16_C(18489) },
      { UINT16_C(21104), UINT16_C(31804), UINT16_C(53569), UINT16_C(54999), UINT16_C(64521), UINT16_C(51614), UINT16_C(26631), UINT16_C(18479) },
      { UINT16_C(21097), UINT16_C(31798), UINT16_C(53563), UINT16_C(54998), UINT16_C(64520), UINT16_C(51611), UINT16_C(26628), UINT16_C(18478) } },
    { { UINT16_C( 1474), UINT16_C(64679), UINT16_C(32214), UINT16_C(57042), UINT16_C(28025), UINT16_C(32167), UINT16_C(54997), UINT16_C(43462) },
      { UINT16_C( 1742), UINT16_C(36485), UINT16_C(27101), UINT16_C(27575), UINT16_C(58249), UINT16_C(19446), UINT16_C(50770), UINT16_C( 5237) },
      { UINT16_C( 1692), UINT16_C( 3704), UINT16_C(35602), UINT16_C(60489), UINT16_C(35306), UINT16_C(34598), UINT16_C(61343), UINT16_C(44117) },
      { UINT16_C( 1501), UINT16_C(65249), UINT16_C(32637), UINT16_C(57473), UINT16_C(28935), UINT16_C(32471), UINT16_C(55790), UINT16_C(43544) },
      { UINT16_C( 1476), UINT16_C(64715), UINT16_C(32240), UINT16_C(57069), UINT16_C(28082), UINT16_C(32186), UINT16_C(55047), UINT16_C(43467) },
      { UINT16_C( 1474), UINT16_C(64683), UINT16_C(32217), UINT16_C(57045), UINT16_C(28032), UINT16_C(32169), UINT16_C(55003), UINT16_C(43463) },
      { UINT16_C( 1474), UINT16_C(64680), UINT16_C(32214), UINT16_C(57042), UINT16_C(28026), UINT16_C(32167), UINT16_C(54998), UINT16_C(43462) } },
    { { UINT16_C( 7371), UINT16_C(41233), UINT16_C(58266), UINT16_C( 4991), UINT16_C(10064), UINT16_C( 9617), UINT16_C(22525), UINT16_C(52174) },
      { UINT16_C(21597), UINT16_C(14938), UINT16_C( 4541), UINT16_C(18085), UINT16_C(40180), UINT16_C(18321), UINT16_C( 1890), UINT16_C(11867) },
      { UINT16_C(10071), UINT16_C(43100), UINT16_C(58834), UINT16_C( 7252), UINT16_C(15087), UINT16_C(11907), UINT16_C(22761), UINT16_C(53657) },
      { UINT16_C( 7708), UINT16_C(41466), UINT16_C(58337), UINT16_C( 5274), UINT16_C(10692), UINT16_C( 9903), UINT16_C(22555), UINT16_C(52359) },
      { UINT16_C( 7392), UINT16_C(41248), UINT16_C(58270), UINT16_C( 5009), UINT16_C(10103), UINT16_C( 9635), UINT16_C(22527), UINT16_C(52186) },
      { UINT16_C( 7374), UINT16_C(41235), UINT16_C(58267), UINT16_C( 4993), UINT16_C(10069), UINT16_C( 9619), UINT16_C(22525), UINT16_C(52175) },
      { UINT16_C( 7371), UINT16_C(41233), UINT16_C(58266), UINT16_C( 4991), UINT16_C(10065), UINT16_C( 9617), UINT16_C(22525), UINT16_C(52174) } },
    { { UINT16_C(27683), UINT16_C(48591), UINT16_C(20304), UINT16_C(41169), UINT16_C(25206), UINT16_C(29638), UINT16_C(38073), UINT16_C( 5694) },
      { UINT16_C(39144), UINT16_C(42576), UINT16_C(63146), UINT16_C(40684), UINT16_C(32402), UINT16_C(62693), UINT16_C(16773), UINT16_C(43042) },
      { UINT16_C(32576), UINT16_C(53913), UINT16_C(28197), UINT16_C(46255), UINT16_C(29256), UINT16_C(37475), UINT16_C(40170), UINT16_C(11074) },
      { UINT16_C(28295), UINT16_C(49256), UINT16_C(21291), UINT16_C(41805), UINT16_C(25712), UINT16_C(30618), UINT16_C(38335), UINT16_C( 6367) },
      { UINT16_C(27721), UINT16_C(48633), UINT16_C(20366), UINT16_C(41209), UINT16_C(25238), UINT16_C(29699), UINT16_C(38089), UINT16_C( 5736) },
      { UINT16_C(27688), UINT16_C(48596), UINT16_C(20312), UINT16_C(41174), UINT16_C(25210), UINT16_C(29646), UINT16_C(38075), UINT16_C( 5699) },
      { UINT16_C(27684), UINT16_C(48592), UINT16_C(20305), UINT16_C(41170), UINT16_C(25206), UINT16_C(29639), UINT16_C(38073), UINT16_C( 5695) } },
    { { UINT16_C(62125), UINT16_C(64870), UINT16_C(14145), UINT16_C(47006), UINT16_C(25753), UINT16_C(21034), UINT16_C(26872), UINT16_C(57704) },
      { UINT16_C(47105), UINT16_C(43911), UINT16_C(29614), UINT16_C(16457), UINT16_C(12273), UINT16_C(30261), UINT16_C(22384), UINT16_C( 7455) },
      { UINT16_C( 2477), UINT16_C( 4823), UINT16_C(17847), UINT16_C(49063), UINT16_C(27287), UINT16_C(24817), UINT16_C(29670), UINT16_C(58636) },
      { UINT16_C(62861), UINT16_C(   20), UINT16_C(14608), UINT16_C(47263), UINT16_C(25945), UINT16_C(21507), UINT16_C(27222), UINT16_C(57820) },
      { UINT16_C(62171), UINT16_C(64913), UINT16_C(14174), UINT16_C(47022), UINT16_C(25765), UINT16_C(21064), UINT16_C(26894), UINT16_C(57711) },
      { UINT16_C(62131), UINT16_C(64875), UINT16_C(14149), UINT16_C(47008), UINT16_C(25754), UINT16_C(21038), UINT16_C(26875), UINT16_C(57705) },
      { UINT16_C(62126), UINT16_C(64871), UINT16_C(14145), UINT16_C(47006), UINT16_C(25753), UINT16_C(21034), UINT16_C(26872), UINT16_C(57704) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);

    simde_uint16x8_t r3 = simde_vrsraq_n_u16(a, b, 3);
    simde_uint16x8_t r6 = simde_vrsraq_n_u16(a, b, 6);
    simde_uint16x8_t r10 = simde_vrsraq_n_u16(a, b, 10);
    simde_uint16x8_t r13 = simde_vrsraq_n_u16(a, b, 13);
    simde_uint16x8_t r16 = simde_vrsraq_n_u16(a, b, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vrsraq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { { UINT32_C(2454946824), UINT32_C( 868430946), UINT32_C(  94292273), UINT32_C(4194192115) },
      { UINT32_C(3439656751), UINT32_C(2286051294), UINT32_C(3408966289), UINT32_C(3316734140) },
      { UINT32_C(2508691461), UINT32_C( 904150497), UINT32_C( 147557371), UINT32_C(4246016086) },
      { UINT32_C(2455366704), UINT32_C( 868710005), UINT32_C(  94708407), UINT32_C(4194596990) },
      { UINT32_C(2454953385), UINT32_C( 868435306), UINT32_C(  94298775), UINT32_C(4194198441) },
      { UINT32_C(2454946875), UINT32_C( 868430980), UINT32_C(  94292324), UINT32_C(4194192164) },
      { UINT32_C(2454946825), UINT32_C( 868430947), UINT32_C(  94292274), UINT32_C(4194192116) } },
    { { UINT32_C(1062667484), UINT32_C(1769085496), UINT32_C(3597537507), UINT32_C(2312072282) },
      { UINT32_C(1247269739), UINT32_C(3285358898), UINT32_C( 143524683), UINT32_C( 952975451) },
      { UINT32_C(1082156074), UINT32_C(1820419229), UINT32_C(3599780080), UINT32_C(2326962523) },
      { UINT32_C(1062819739), UINT32_C(1769486541), UINT32_C(3597555027), UINT32_C(2312188612) },
      { UINT32_C(1062669863), UINT32_C(1769091762), UINT32_C(3597537781), UINT32_C(2312074100) },
      { UINT32_C(1062667503), UINT32_C(1769085545), UINT32_C(3597537509), UINT32_C(2312072296) },
      { UINT32_C(1062667484), UINT32_C(1769085497), UINT32_C(3597537507), UINT32_C(2312072282) } },
    { { UINT32_C(2104960068), UINT32_C( 568781118), UINT32_C(1425495545), UINT32_C( 769509057) },
      { UINT32_C(3413587097), UINT32_C( 428755405), UINT32_C(2820742220), UINT32_C(2715872860) },
      { UINT32_C(2158297366), UINT32_C( 575480421), UINT32_C(1469569642), UINT32_C( 811944570) },
      { UINT32_C(2105376766), UINT32_C( 568833456), UINT32_C(1425839874), UINT32_C( 769840584) },
      { UINT32_C(2104966579), UINT32_C( 568781936), UINT32_C(1425500925), UINT32_C( 769514237) },
      { UINT32_C(2104960119), UINT32_C( 568781124), UINT32_C(1425495587), UINT32_C( 769509097) },
      { UINT32_C(2104960069), UINT32_C( 568781118), UINT32_C(1425495546), UINT32_C( 769509058) } },
    { { UINT32_C(1344165650), UINT32_C( 963707968), UINT32_C( 462252121), UINT32_C(3343412014) },
      { UINT32_C(1838333855), UINT32_C(1434853384), UINT32_C(2583537468), UINT32_C(2805652885) },
      { UINT32_C(1372889616), UINT32_C( 986127552), UINT32_C( 502619894), UINT32_C(3387250340) },
      { UINT32_C(1344390056), UINT32_C( 963883121), UINT32_C( 462567494), UINT32_C(3343754501) },
      { UINT32_C(1344169156), UINT32_C( 963710705), UINT32_C( 462257049), UINT32_C(3343417365) },
      { UINT32_C(1344165677), UINT32_C( 963707989), UINT32_C( 462252159), UINT32_C(3343412056) },
      { UINT32_C(1344165650), UINT32_C( 963707968), UINT32_C( 462252122), UINT32_C(3343412015) } },
    { { UINT32_C(1962367028), UINT32_C(3064817756), UINT32_C(4275125200), UINT32_C(1170545062) },
      { UINT32_C(3769784280), UINT32_C(3006609527), UINT32_C(1951150815), UINT32_C(1125877263) },
      { UINT32_C(2021269907), UINT32_C(3111796030), UINT32_C(  10644635), UINT32_C(1188136894) },
      { UINT32_C(1962827207), UINT32_C(3065184774), UINT32_C(4275363378), UINT32_C(1170682498) },
      { UINT32_C(1962374218), UINT32_C(3064823491), UINT32_C(4275128922), UINT32_C(1170547209) },
      { UINT32_C(1962367084), UINT32_C(3064817801), UINT32_C(4275125229), UINT32_C(1170545079) },
      { UINT32_C(1962367029), UINT32_C(3064817757), UINT32_C(4275125200), UINT32_C(1170545062) } },
    { { UINT32_C(1001853662), UINT32_C(1257334138), UINT32_C(1179173536), UINT32_C(3012234715) },
      { UINT32_C(3683860068), UINT32_C(1452263798), UINT32_C( 197843963), UINT32_C(1078912610) },
      { UINT32_C(1059413976), UINT32_C(1280025760), UINT32_C(1182264848), UINT32_C(3029092725) },
      { UINT32_C(1002303352), UINT32_C(1257511416), UINT32_C(1179197687), UINT32_C(3012366418) },
      { UINT32_C(1001860688), UINT32_C(1257336908), UINT32_C(1179173913), UINT32_C(3012236773) },
      { UINT32_C(1001853717), UINT32_C(1257334160), UINT32_C(1179173539), UINT32_C(3012234731) },
      { UINT32_C(1001853663), UINT32_C(1257334138), UINT32_C(1179173536), UINT32_C(3012234715) } },
    { { UINT32_C(1937442552), UINT32_C( 196963435), UINT32_C( 156304942), UINT32_C(2025643027) },
      { UINT32_C(2438156314), UINT32_C( 350741017), UINT32_C( 538948030), UINT32_C(2422238871) },
      { UINT32_C(1975538744), UINT32_C( 202443763), UINT32_C( 164726005), UINT32_C(2063490509) },
      { UINT32_C(1937740179), UINT32_C( 197006250), UINT32_C( 156370732), UINT32_C(2025938710) },
      { UINT32_C(1937447202), UINT32_C( 196964104), UINT32_C( 156305970), UINT32_C(2025647647) },
      { UINT32_C(1937442588), UINT32_C( 196963440), UINT32_C( 156304950), UINT32_C(2025643063) },
      { UINT32_C(1937442553), UINT32_C( 196963435), UINT32_C( 156304942), UINT32_C(2025643028) } },
    { { UINT32_C(3741572212), UINT32_C(2011873352), UINT32_C(3665836998), UINT32_C( 844250391) },
      { UINT32_C(2797839757), UINT32_C(1186638472), UINT32_C(4083604059), UINT32_C(3162752584) },
      { UINT32_C(3785288458), UINT32_C(2030414578), UINT32_C(3729643311), UINT32_C( 893668400) },
      { UINT32_C(3741913745), UINT32_C(2012018205), UINT32_C(3666335485), UINT32_C( 844636469) },
      { UINT32_C(3741577548), UINT32_C(2011875615), UINT32_C(3665844787), UINT32_C( 844256423) },
      { UINT32_C(3741572254), UINT32_C(2011873370), UINT32_C(3665837059), UINT32_C( 844250438) },
      { UINT32_C(3741572213), UINT32_C(2011873352), UINT32_C(3665836999), UINT32_C( 844250392) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);

    simde_uint32x4_t r6 = simde_vrsraq_n_u32(a, b, 6);
    simde_uint32x4_t r13 = simde_vrsraq_n_u32(a, b, 13);
    simde_uint32x4_t r19 = simde_vrsraq_n_u32(a, b, 19);
    simde_uint32x4_t r26 = simde_vrsraq_n_u32(a, b, 26);
    simde_uint32x4_t r32 = simde_vrsraq_n_u32(a, b, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vrsraq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r13[2];
    uint64_t r26[2];
    uint64_t r39[2];
    uint64_t r52[2];
    uint64_t r64[2];
  } test_vec[] = {
    { { UINT64_C( 2393586352393986628), UINT64_C( 3643855986487485346) },
      { UINT64_C( 8639460913876601398), UINT64_C(13301034549434564982) },
      { UINT64_C( 2394640974087575080), UINT64_C( 3645479647931508120) },
      { UINT64_C( 2393586481131986334), UINT64_C( 3643856184688345212) },
      { UINT64_C( 2393586352409701716), UINT64_C( 3643855986511679787) },
      { UINT64_C( 2393586352393988546), UINT64_C( 3643855986487488299) },
      { UINT64_C( 2393586352393986628), UINT64_C( 3643855986487485347) } },
    { { UINT64_C(11358642286101086310), UINT64_C(12703782061007496804) },
      { UINT64_C(14399410231188048240), UINT64_C( 4460751483934020284) },
      { UINT64_C(11360400026607823132), UINT64_C(12704326586335125469) },
      { UINT64_C(11358642500669019261), UINT64_C(12703782127477873712) },
      { UINT64_C(11358642286127278685), UINT64_C(12703782061015610864) },
      { UINT64_C(11358642286101089507), UINT64_C(12703782061007497794) },
      { UINT64_C(11358642286101086311), UINT64_C(12703782061007496804) } },
    { { UINT64_C( 1557508458989728006), UINT64_C( 5220372188488593992) },
      { UINT64_C( 4565939203298658373), UINT64_C( 6314141585117187211) },
      { UINT64_C( 1558065824615130674), UINT64_C( 5221142957725058492) },
      { UINT64_C( 1557508527027524076), UINT64_C( 5220372282576635553) },
      { UINT64_C( 1557508458998033401), UINT64_C( 5220372188500079349) },
      { UINT64_C( 1557508458989729020), UINT64_C( 5220372188488595394) },
      { UINT64_C( 1557508458989728006), UINT64_C( 5220372188488593992) } },
    { { UINT64_C(  634714805581143815), UINT64_C(13837094878020566759) },
      { UINT64_C(12792108764284497092), UINT64_C( 5974222042828109119) },
      { UINT64_C(  636276342295534012), UINT64_C(13837824153172279175) },
      { UINT64_C(  634714996198418521), UINT64_C(13837094967043412427) },
      { UINT64_C(  634714805604412525), UINT64_C(13837094878031433806) },
      { UINT64_C(  634714805581146655), UINT64_C(13837094878020568086) },
      { UINT64_C(  634714805581143816), UINT64_C(13837094878020566759) } },
    { { UINT64_C( 2151550972685074450), UINT64_C(12038654939625203414) },
      { UINT64_C( 6442246549575460752), UINT64_C( 4613886341815040618) },
      { UINT64_C( 2152337379734583173), UINT64_C(12039218158172788258) },
      { UINT64_C( 2151551068682028736), UINT64_C(12038655008377467523) },
      { UINT64_C( 2151550972696792828), UINT64_C(12038654939633596024) },
      { UINT64_C( 2151550972685075880), UINT64_C(12038654939625204438) },
      { UINT64_C( 2151550972685074450), UINT64_C(12038654939625203414) } },
    { { UINT64_C(13863469342447046929), UINT64_C(13050906310178062485) },
      { UINT64_C(17076755345611361673), UINT64_C(14536397728258319948) },
      { UINT64_C(13865553907308571753), UINT64_C(13052680772791375268) },
      { UINT64_C(13863469596910531002), UINT64_C(13050906526787268212) },
      { UINT64_C(13863469342478109366), UINT64_C(13050906310204504038) },
      { UINT64_C(13863469342447050721), UINT64_C(13050906310178065713) },
      { UINT64_C(13863469342447046930), UINT64_C(13050906310178062486) } },
    { { UINT64_C( 5936998566614585017), UINT64_C( 2418125793131132340) },
      { UINT64_C( 1685403765198682613), UINT64_C( 7361218993670194343) },
      { UINT64_C( 5937204304378891497), UINT64_C( 2419024379434070596) },
      { UINT64_C( 5936998591729058199), UINT64_C( 2418125902821843148) },
      { UINT64_C( 5936998566617650749), UINT64_C( 2418125793144522319) },
      { UINT64_C( 5936998566614585391), UINT64_C( 2418125793131133975) },
      { UINT64_C( 5936998566614585017), UINT64_C( 2418125793131132340) } },
    { { UINT64_C( 6929753040782702619), UINT64_C(15248282196733720035) },
      { UINT64_C(14601705884549341632), UINT64_C(11368582454750819763) },
      { UINT64_C( 6931535475583062646), UINT64_C(15249669963146653485) },
      { UINT64_C( 6929753258365075710), UINT64_C(15248282366138799739) },
      { UINT64_C( 6929753040809262967), UINT64_C(15248282196754399366) },
      { UINT64_C( 6929753040782705861), UINT64_C(15248282196733722559) },
      { UINT64_C( 6929753040782702620), UINT64_C(15248282196733720036) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);

    simde_uint64x2_t r13 = simde_vrsraq_n_u64(a, b, 13);
    simde_uint64x2_t r26 = simde_vrsraq_n_u64(a, b, 26);
    simde_uint64x2_t r39 = simde_vrsraq_n_u64(a, b, 39);
    simde_uint64x2_t r52 = simde_vrsraq_n_u64(a, b, 52);
    simde_uint64x2_t r64 = simde_vrsraq_n_u64(a, b, 64);

    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r39, simde_vld1q_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x2(r52, simde_vld1q_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x2(r64, simde_vld1q_u64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vrsrad_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      int64_t a;
      int64_t b;
      int64_t r13;
      int64_t r26;
      int64_t r39;
      int64_t r52;
      int64_t r64;
    } test_vec[] = {
      {  INT64_C( 4098891015068167931),
      -INT64_C( 7927350770354321089),
       INT64_C( 4097923320882333663),
       INT64_C( 4098890896941436262),
       INT64_C( 4098891015053748164),
       INT64_C( 4098891015068166171),
       INT64_C( 4098891015068167931) },
    { -INT64_C( 1136285757235627158),
      -INT64_C(  153052006877333996),
      -INT64_C( 1136304440341935426),
      -INT64_C( 1136285759516279784),
      -INT64_C( 1136285757235905558),
      -INT64_C( 1136285757235627192),
      -INT64_C( 1136285757235627158) },
    {  INT64_C( 9065796891963035374),
      -INT64_C( 4989385510332339017),
       INT64_C( 9065187836114606133),
       INT64_C( 9065796817615397626),
       INT64_C( 9065796891953959735),
       INT64_C( 9065796891963034266),
       INT64_C( 9065796891963035374) },
    { -INT64_C( 7804814571373435745),
      -INT64_C( 4021664052055074256),
      -INT64_C( 7805305497161040124),
      -INT64_C( 7804814631300900052),
      -INT64_C( 7804814571380751109),
      -INT64_C( 7804814571373436638),
      -INT64_C( 7804814571373435745) },
    {  INT64_C( 7130659093733211195),
      -INT64_C( 2150656553268339172),
       INT64_C( 7130396562415673556),
       INT64_C( 7130659061685931222),
       INT64_C( 7130659093729299174),
       INT64_C( 7130659093733210717),
       INT64_C( 7130659093733211195) },
    { -INT64_C( 8013222742073432647),
      -INT64_C( 9183416584159160086),
      -INT64_C( 8014343764605678638),
      -INT64_C( 8013222878917003478),
      -INT64_C( 8013222742090137184),
      -INT64_C( 8013222742073434686),
      -INT64_C( 8013222742073432647) },
    {  INT64_C( 4142447566047997296),
       INT64_C( 2175463351208185612),
       INT64_C( 4142713125539111576),
       INT64_C( 4142447598464927364),
       INT64_C( 4142447566051954441),
       INT64_C( 4142447566047997779),
       INT64_C( 4142447566047997296) },
    {  INT64_C(  892031734132429170),
      -INT64_C( 8575031706173496262),
       INT64_C(  890984977332359163),
       INT64_C(  892031606354499474),
       INT64_C(  892031734116831278),
       INT64_C(  892031734132427266),
       INT64_C(  892031734132429170) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      int64_t r13 = simde_vrsrad_n_s64(test_vec[i].a, test_vec[i].b, 13);
      int64_t r26 = simde_vrsrad_n_s64(test_vec[i].a, test_vec[i].b, 26);
      int64_t r39 = simde_vrsrad_n_s64(test_vec[i].a, test_vec[i].b, 39);
      int64_t r52 = simde_vrsrad_n_s64(test_vec[i].a, test_vec[i].b, 52);
      int64_t r64 = simde_vrsrad_n_s64(test_vec[i].a, test_vec[i].b, 64);

      simde_assert_equal_i64(r13, test_vec[i].r13);
      simde_assert_equal_i64(r26, test_vec[i].r26);
      simde_assert_equal_i64(r39, test_vec[i].r39);
      simde_assert_equal_i64(r52, test_vec[i].r52);
      simde_assert_equal_i64(r64, test_vec[i].r64);
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      int64_t a = simde_test_codegen_random_i64();
      int64_t b = simde_test_codegen_random_i64();
      int64_t r13 = simde_vrsrad_n_s64(a, b, 13);
      int64_t r26 = simde_vrsrad_n_s64(a, b, 26);
      int64_t r39 = simde_vrsrad_n_s64(a, b, 39);
      int64_t r52 = simde_vrsrad_n_s64(a, b, 52);
      int64_t r64 = simde_vrsrad_n_s64(a, b, 64);

      simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i64(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i64(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i64(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i64(2, r64, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vrsrad_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      uint64_t a;
      uint64_t b;
      uint64_t r13;
      uint64_t r26;
      uint64_t r39;
      uint64_t r52;
      uint64_t r64;
    } test_vec[] = {
      { UINT64_C( 6050306364889370489),
      UINT64_C( 3001788449799908035),
      UINT64_C( 6050672794143496454),
      UINT64_C( 6050306409619504049),
      UINT64_C( 6050306364894830710),
      UINT64_C( 6050306364889371156),
      UINT64_C( 6050306364889370489) },
    { UINT64_C(14301900477226346473),
      UINT64_C(15192530887374328044),
      UINT64_C(14303755034219434160),
      UINT64_C(14301900703612698168),
      UINT64_C(14301900477253981526),
      UINT64_C(14301900477226349846),
      UINT64_C(14301900477226346474) },
    { UINT64_C( 2282770154352827077),
      UINT64_C( 5083342822959079346),
      UINT64_C( 2283390679599770324),
      UINT64_C( 2282770230100537886),
      UINT64_C( 2282770154362073624),
      UINT64_C( 2282770154352828206),
      UINT64_C( 2282770154352827077) },
    { UINT64_C( 1516681909782748048),
      UINT64_C(11552342016886187047),
      UINT64_C( 1518092107782856225),
      UINT64_C( 1516682081926058608),
      UINT64_C( 1516681909803761636),
      UINT64_C( 1516681909782750613),
      UINT64_C( 1516681909782748049) },
    { UINT64_C( 2089575028612620931),
      UINT64_C( 4191454503502741640),
      UINT64_C( 2090086680773693043),
      UINT64_C( 2089575091070160124),
      UINT64_C( 2089575028620245142),
      UINT64_C( 2089575028612621862),
      UINT64_C( 2089575028612620931) },
    { UINT64_C( 9647426591071864996),
      UINT64_C(16225159241319920816),
      UINT64_C( 9649407201330815182),
      UINT64_C( 9647426832845578247),
      UINT64_C( 9647426591101378389),
      UINT64_C( 9647426591071868599),
      UINT64_C( 9647426591071864997) },
    { UINT64_C( 6287235976204920506),
      UINT64_C( 7756158188935495359),
      UINT64_C( 6288182772858843296),
      UINT64_C( 6287236091780683924),
      UINT64_C( 6287235976219028876),
      UINT64_C( 6287235976204922228),
      UINT64_C( 6287235976204920506) },
    { UINT64_C( 6797087075695338096),
      UINT64_C( 7821930881155160399),
      UINT64_C( 6798041901242354107),
      UINT64_C( 6797087192251191003),
      UINT64_C( 6797087075709566105),
      UINT64_C( 6797087075695339833),
      UINT64_C( 6797087075695338096) }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      uint64_t r13 = simde_vrsrad_n_u64(test_vec[i].a, test_vec[i].b, 13);
      uint64_t r26 = simde_vrsrad_n_u64(test_vec[i].a, test_vec[i].b, 26);
      uint64_t r39 = simde_vrsrad_n_u64(test_vec[i].a, test_vec[i].b, 39);
      uint64_t r52 = simde_vrsrad_n_u64(test_vec[i].a, test_vec[i].b, 52);
      uint64_t r64 = simde_vrsrad_n_u64(test_vec[i].a, test_vec[i].b, 64);

      simde_assert_equal_u64(r13, test_vec[i].r13);
      simde_assert_equal_u64(r26, test_vec[i].r26);
      simde_assert_equal_u64(r39, test_vec[i].r39);
      simde_assert_equal_u64(r52, test_vec[i].r52);
      simde_assert_equal_u64(r64, test_vec[i].r64);
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      uint64_t a = simde_test_codegen_random_u64();
      uint64_t b = simde_test_codegen_random_u64();
      uint64_t r13 = simde_vrsrad_n_u64(a, b, 13);
      uint64_t r26 = simde_vrsrad_n_u64(a, b, 26);
      uint64_t r39 = simde_vrsrad_n_u64(a, b, 39);
      uint64_t r52 = simde_vrsrad_n_u64(a, b, 52);
      uint64_t r64 = simde_vrsrad_n_u64(a, b, 64);

      simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_u64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_u64(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_u64(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_u64(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_u64(2, r64, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrsra_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsra_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsra_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsra_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsra_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsra_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsra_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsra_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrsraq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsraq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsraq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsraq_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsraq_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsraq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsraq_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsraq_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrsrad_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsrad_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
