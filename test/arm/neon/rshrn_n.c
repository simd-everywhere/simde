
#define SIMDE_TEST_ARM_NEON_INSN rshrn_n

#include "test-neon.h"
#include "../../../simde/arm/neon/rshrn_n.h"

static int
test_simde_vrshrn_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r8[16];
  } test_vec[] = {
    { {  INT16_C( 10562),  INT16_C(  6844),  INT16_C( 14407), -INT16_C( 31970),  INT16_C(  8622), -INT16_C( 13971),  INT16_C( 17167), -INT16_C( 26709) },
      { -INT8_C(  95),  INT8_C(  94),  INT8_C(  36), -INT8_C( 113), -INT8_C(  41), -INT8_C(  73), -INT8_C( 120), -INT8_C(  42) },
      {  INT8_C(  40),  INT8_C(  88),  INT8_C(   9),  INT8_C( 100),  INT8_C(  54),  INT8_C(  46),  INT8_C(  98), -INT8_C(  11) },
      {  INT8_C(  74), -INT8_C(  42), -INT8_C(  62),  INT8_C(  25),  INT8_C(  13),  INT8_C(  75),  INT8_C(  24), -INT8_C(  67) },
      { -INT8_C(  91),  INT8_C( 107), -INT8_C(  31),  INT8_C(  12), -INT8_C( 121),  INT8_C(  38),  INT8_C(  12),  INT8_C(  95) },
      {  INT8_C(  41),  INT8_C(  27),  INT8_C(  56), -INT8_C( 125),  INT8_C(  34), -INT8_C(  55),  INT8_C(  67), -INT8_C( 104) } },
    { {  INT16_C( 30334), -INT16_C(  3256),  INT16_C(  2880), -INT16_C( 20934),  INT16_C( 21822),  INT16_C( 14204), -INT16_C( 24458), -INT16_C( 18006) },
      {  INT8_C(  63), -INT8_C(  92), -INT8_C(  96),  INT8_C(  29), -INT8_C(  97), -INT8_C(  66),  INT8_C(  59), -INT8_C(  43) },
      { -INT8_C(  48),  INT8_C( 105),  INT8_C( 104), -INT8_C(  57), -INT8_C(  88), -INT8_C(  16),  INT8_C(  15),  INT8_C(  53) },
      { -INT8_C(  76), -INT8_C( 102),  INT8_C(  90),  INT8_C( 114), -INT8_C(  86), -INT8_C(  68),  INT8_C(   4), -INT8_C(  51) },
      { -INT8_C(  38), -INT8_C(  51),  INT8_C(  45), -INT8_C(  71),  INT8_C(  85), -INT8_C(  34), -INT8_C( 126), -INT8_C(  25) },
      {  INT8_C( 118), -INT8_C(  13),  INT8_C(  11), -INT8_C(  82),  INT8_C(  85),  INT8_C(  55), -INT8_C(  96), -INT8_C(  70) } },
    { {  INT16_C( 26314),  INT16_C(  4563), -INT16_C(  3682),  INT16_C( 19604),  INT16_C(   275),  INT16_C(  8726), -INT16_C( 16060), -INT16_C( 15687) },
      {  INT8_C( 101), -INT8_C(  22), -INT8_C(  49),  INT8_C(  74), -INT8_C( 118),  INT8_C(  11), -INT8_C(  94),  INT8_C(  93) },
      { -INT8_C(  39),  INT8_C(  58),  INT8_C(  52), -INT8_C( 109),  INT8_C(  34),  INT8_C(  67),  INT8_C(  41),  INT8_C(  87) },
      {  INT8_C(  54), -INT8_C( 113), -INT8_C( 115),  INT8_C( 101),  INT8_C(   9),  INT8_C(  17),  INT8_C(  10),  INT8_C(  22) },
      { -INT8_C( 101),  INT8_C(  71), -INT8_C(  58),  INT8_C(  50),  INT8_C(   4), -INT8_C( 120),  INT8_C(   5),  INT8_C(  11) },
      {  INT8_C( 103),  INT8_C(  18), -INT8_C(  14),  INT8_C(  77),  INT8_C(   1),  INT8_C(  34), -INT8_C(  63), -INT8_C(  61) } },
    { {  INT16_C(   311),  INT16_C( 30645), -INT16_C(  4339),  INT16_C( 19237), -INT16_C( 24252), -INT16_C( 17533),  INT16_C( 11586),  INT16_C(  3188) },
      { -INT8_C( 100), -INT8_C(  37), -INT8_C( 121), -INT8_C( 109), -INT8_C(  94), -INT8_C(  62), -INT8_C(  95),  INT8_C(  58) },
      {  INT8_C(  39), -INT8_C(   9), -INT8_C(  30),  INT8_C( 101),  INT8_C(  41),  INT8_C( 112), -INT8_C(  88), -INT8_C( 113) },
      {  INT8_C(  10), -INT8_C(  66),  INT8_C( 120),  INT8_C(  89),  INT8_C(  10), -INT8_C(  36),  INT8_C( 106),  INT8_C( 100) },
      {  INT8_C(   5), -INT8_C(  33), -INT8_C(  68),  INT8_C(  45), -INT8_C( 123), -INT8_C(  18), -INT8_C(  75),  INT8_C(  50) },
      {  INT8_C(   1),  INT8_C( 120), -INT8_C(  17),  INT8_C(  75), -INT8_C(  95), -INT8_C(  68),  INT8_C(  45),  INT8_C(  12) } },
    { {  INT16_C( 18324),  INT16_C( 12829), -INT16_C( 20168),  INT16_C( 19327), -INT16_C( 27214), -INT16_C(  2451),  INT16_C( 10070), -INT16_C( 29256) },
      { -INT8_C(  54),  INT8_C(  15), -INT8_C( 100), -INT8_C(  64), -INT8_C(  39),  INT8_C(  55), -INT8_C(  85), -INT8_C(  36) },
      { -INT8_C(  13),  INT8_C(  68),  INT8_C(  39),  INT8_C( 112), -INT8_C(  74), -INT8_C(  50), -INT8_C(  21), -INT8_C(  73) },
      {  INT8_C(  61), -INT8_C( 111), -INT8_C( 118),  INT8_C(  92), -INT8_C(  82), -INT8_C(  77),  INT8_C(  59),  INT8_C( 110) },
      {  INT8_C(  30), -INT8_C(  56), -INT8_C(  59),  INT8_C(  46),  INT8_C(  87), -INT8_C(  38), -INT8_C(  99),  INT8_C(  55) },
      {  INT8_C(  72),  INT8_C(  50), -INT8_C(  79),  INT8_C(  75), -INT8_C( 106), -INT8_C(  10),  INT8_C(  39), -INT8_C( 114) } },
    { {  INT16_C( 27944),  INT16_C( 13572),  INT16_C( 10588), -INT16_C( 24191),  INT16_C(  1227),  INT16_C(  3420), -INT16_C( 12239), -INT16_C( 15079) },
      { -INT8_C( 108), -INT8_C( 126), -INT8_C(  82), -INT8_C(  63),  INT8_C( 102), -INT8_C(  82),  INT8_C(  25), -INT8_C( 115) },
      { -INT8_C(  91), -INT8_C(  95),  INT8_C(  44),  INT8_C(  48), -INT8_C( 103), -INT8_C(  84),  INT8_C(   6), -INT8_C(  93) },
      {  INT8_C( 105), -INT8_C(  88),  INT8_C(  75),  INT8_C(  12),  INT8_C(  38),  INT8_C( 107), -INT8_C( 126),  INT8_C(  41) },
      { -INT8_C(  75), -INT8_C(  44), -INT8_C(  91), -INT8_C( 122),  INT8_C(  19),  INT8_C(  53),  INT8_C(  65),  INT8_C(  20) },
      {  INT8_C( 109),  INT8_C(  53),  INT8_C(  41), -INT8_C(  94),  INT8_C(   5),  INT8_C(  13), -INT8_C(  48), -INT8_C(  59) } },
    { {  INT16_C( 13847),  INT16_C( 20472),  INT16_C( 30695), -INT16_C( 26213),  INT16_C(  2060),  INT16_C( 25231),  INT16_C( 18223),  INT16_C( 22767) },
      {  INT8_C(  12), -INT8_C(   4), -INT8_C(  12), -INT8_C(  50),  INT8_C(   6),  INT8_C(  72), -INT8_C( 104),  INT8_C( 120) },
      { -INT8_C(  61), -INT8_C(   1), -INT8_C(   3),  INT8_C(  51),  INT8_C(   2),  INT8_C(  82), -INT8_C(  26),  INT8_C(  30) },
      { -INT8_C(  79),      INT8_MIN, -INT8_C(  65), -INT8_C(  51),  INT8_C(  64),  INT8_C(  20),  INT8_C(  57), -INT8_C(  57) },
      { -INT8_C(  40),  INT8_C(  64), -INT8_C(  32),  INT8_C( 102),  INT8_C(  32), -INT8_C( 118),  INT8_C(  29),  INT8_C( 100) },
      {  INT8_C(  54),  INT8_C(  80),  INT8_C( 120), -INT8_C( 102),  INT8_C(   8),  INT8_C(  99),  INT8_C(  71),  INT8_C(  89) } },
    { { -INT16_C(  3148),  INT16_C(  4237),  INT16_C(  3612), -INT16_C(  6223),  INT16_C(  3346),  INT16_C( 17652),  INT16_C(  3549), -INT16_C(  3063) },
      { -INT8_C(  38),  INT8_C(  71),  INT8_C(  14), -INT8_C(  39), -INT8_C( 119),  INT8_C( 122), -INT8_C(  17),  INT8_C(   5) },
      {  INT8_C( 119),  INT8_C(  18), -INT8_C(  60), -INT8_C(  10), -INT8_C(  94), -INT8_C(  97), -INT8_C(  68), -INT8_C( 127) },
      { -INT8_C(  98), -INT8_C( 124),  INT8_C( 113),  INT8_C(  62),  INT8_C( 105),  INT8_C(  40),  INT8_C( 111), -INT8_C(  96) },
      { -INT8_C(  49),  INT8_C(  66),  INT8_C(  56), -INT8_C(  97),  INT8_C(  52),  INT8_C(  20),  INT8_C(  55), -INT8_C(  48) },
      { -INT8_C(  12),  INT8_C(  17),  INT8_C(  14), -INT8_C(  24),  INT8_C(  13),  INT8_C(  69),  INT8_C(  14), -INT8_C(  12) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_int8x8_t r1 = simde_vrshrn_n_s16(a, 1);
    simde_int8x8_t r3 = simde_vrshrn_n_s16(a, 3);
    simde_int8x8_t r5 = simde_vrshrn_n_s16(a, 5);
    simde_int8x8_t r6 = simde_vrshrn_n_s16(a, 6);
    simde_int8x8_t r8 = simde_vrshrn_n_s16(a, 8);

    simde_test_arm_neon_assert_equal_i8x8(r1, simde_vld1_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r6, simde_vld1_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x8(r8, simde_vld1_s8(test_vec[i].r8));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();

    simde_int8x8_t r1 = simde_vrshrn_n_s16(a, 1);
    simde_int8x8_t r3 = simde_vrshrn_n_s16(a, 3);
    simde_int8x8_t r5 = simde_vrshrn_n_s16(a, 5);
    simde_int8x8_t r6 = simde_vrshrn_n_s16(a, 6);
    simde_int8x8_t r8 = simde_vrshrn_n_s16(a, 8);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r8, SIMDE_TEST_VEC_POS_LAST);

  }
  return 1;
#endif
}

static int
test_simde_vrshrn_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { {  INT32_C(   709099843), -INT32_C(  2067538056),  INT32_C(   400970471),  INT32_C(  1299174809) },
      { -INT16_C( 32728),  INT16_C( 31727), -INT16_C( 13731), -INT16_C(  1357) },
      {  INT16_C(  4101),  INT16_C(  3966), -INT16_C( 26292), -INT16_C( 16554) },
      { -INT16_C( 28416),  INT16_C( 12536), -INT16_C(  1643),  INT16_C( 23541) },
      {  INT16_C( 21024),  INT16_C(  9759), -INT16_C( 16589),  INT16_C( 27519) },
      {  INT16_C( 10820), -INT16_C( 31548),  INT16_C(  6118),  INT16_C( 19824) } },
    { { -INT32_C(   446759736),  INT32_C(   499912459), -INT32_C(    94256867),  INT32_C(   317680590) },
      { -INT16_C(  8295), -INT16_C( 32287),  INT16_C( 14372), -INT16_C(  4742) },
      {  INT16_C( 31731),  INT16_C( 12348), -INT16_C( 30972), -INT16_C( 16977) },
      {  INT16_C( 22463),  INT16_C( 29444), -INT16_C( 26512), -INT16_C( 17445) },
      {  INT16_C( 11000), -INT16_C(  4512), -INT16_C( 11506), -INT16_C( 26757) },
      { -INT16_C(  6817),  INT16_C(  7628), -INT16_C(  1438),  INT16_C(  4847) } },
    { { -INT32_C(   449039508), -INT32_C(   110559214), -INT32_C(   334475182), -INT32_C(   298221787) },
      { -INT16_C( 31122),  INT16_C(  8194),  INT16_C(  2570),  INT16_C( 12261) },
      { -INT16_C(  3890), -INT16_C( 23552),  INT16_C( 16705), -INT16_C(  6659) },
      {  INT16_C( 20237),  INT16_C( 23104),  INT16_C(  1044), -INT16_C( 29088) },
      {  INT16_C( 10722), -INT16_C( 13496),  INT16_C( 24707),  INT16_C( 29132) },
      { -INT16_C(  6852), -INT16_C(  1687), -INT16_C(  5104), -INT16_C(  4551) } },
    { { -INT32_C(  2016176260), -INT32_C(   995844185),  INT32_C(   800982624), -INT32_C(   582898319) },
      {  INT16_C( 29424), -INT16_C( 27659), -INT16_C( 16180),  INT16_C( 13742) },
      {  INT16_C( 20062), -INT16_C( 28033), -INT16_C(  2022),  INT16_C(  1718) },
      { -INT16_C(  2842),  INT16_C( 10536), -INT16_C(  4222),  INT16_C( 20587) },
      {  INT16_C( 16029),  INT16_C(  9509),  INT16_C( 32240), -INT16_C(  5619) },
      { -INT16_C( 30764), -INT16_C( 15195),  INT16_C( 12222), -INT16_C(  8894) } },
    { { -INT32_C(   222134816), -INT32_C(   789828483), -INT32_C(  1581450116), -INT32_C(   124783236) },
      {  INT16_C( 20412), -INT16_C( 31344), -INT16_C( 24688), -INT16_C(   336) },
      {  INT16_C(  2552), -INT16_C( 20302), -INT16_C(  3086),  INT16_C( 16342) },
      { -INT16_C( 20321),  INT16_C( 15115),  INT16_C( 28479),  INT16_C(  9213) },
      { -INT16_C( 27116), -INT16_C( 30879),  INT16_C(  3560), -INT16_C( 15232) },
      { -INT16_C(  3390), -INT16_C( 12052), -INT16_C( 24131), -INT16_C(  1904) } },
    { {  INT32_C(   880763533),  INT32_C(  1660429058), -INT32_C(  1701726679),  INT32_C(  1148768868) },
      { -INT16_C(  5038),  INT16_C(  1120),  INT16_C( 14021),  INT16_C(  6733) },
      { -INT16_C(   630), -INT16_C(  8052),  INT16_C( 18137), -INT16_C(  7350) },
      {  INT16_C(  8153), -INT16_C( 16887), -INT16_C( 23442),  INT16_C(  7733) },
      { -INT16_C( 23557),  INT16_C(  6081), -INT16_C( 11122),  INT16_C(  9159) },
      {  INT16_C( 13439),  INT16_C( 25336), -INT16_C( 25966),  INT16_C( 17529) } },
    { { -INT32_C(   852018608), -INT32_C(   493018266), -INT32_C(  1685825249), -INT32_C(   594341041) },
      { -INT16_C(  6326), -INT16_C( 23443), -INT16_C( 29916),  INT16_C( 25194) },
      { -INT16_C(  8983),  INT16_C( 29838),  INT16_C(  4452),  INT16_C( 19533) },
      {  INT16_C( 19919), -INT16_C( 22711), -INT16_C(  7914),  INT16_C(  9413) },
      {  INT16_C( 27066),  INT16_C(  5353), -INT16_C(  9181), -INT16_C(  7015) },
      { -INT16_C( 13001), -INT16_C(  7523), -INT16_C( 25724), -INT16_C(  9069) } },
    { {  INT32_C(  2014319222),  INT32_C(  1608124470),  INT32_C(   586837182), -INT32_C(  1905823170) },
      {  INT16_C(   591),  INT16_C( 16647),  INT16_C( 19864), -INT16_C(  4536) },
      {  INT16_C( 16458),  INT16_C( 26657), -INT16_C(  5709), -INT16_C( 25143) },
      {  INT16_C(  1029), -INT16_C(  2430), -INT16_C( 16741), -INT16_C( 26147) },
      { -INT16_C( 16255), -INT16_C(   304),  INT16_C(  6099),  INT16_C( 29500) },
      {  INT16_C( 30736),  INT16_C( 24538),  INT16_C(  8954), -INT16_C( 29081) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_int16x4_t r3 = simde_vrshrn_n_s32(a, 3);
    simde_int16x4_t r6 = simde_vrshrn_n_s32(a, 6);
    simde_int16x4_t r10 = simde_vrshrn_n_s32(a, 10);
    simde_int16x4_t r13 = simde_vrshrn_n_s32(a, 13);
    simde_int16x4_t r16 = simde_vrshrn_n_s32(a, 16);

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r16, simde_vld1_s16(test_vec[i].r16));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();

    simde_int16x4_t r3 = simde_vrshrn_n_s32(a, 3);
    simde_int16x4_t r6 = simde_vrshrn_n_s32(a, 6);
    simde_int16x4_t r10 = simde_vrshrn_n_s32(a, 10);
    simde_int16x4_t r13 = simde_vrshrn_n_s32(a, 13);
    simde_int16x4_t r16 = simde_vrshrn_n_s32(a, 16);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshrn_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec[] = {
    { { -INT64_C( 2236607032270741844),  INT64_C(  251655730170198355) },
      {  INT32_C(    72184443),  INT32_C(   915010021) },
      { -INT32_C(   838296859),  INT32_C(  2087523300) },
      { -INT32_C(  1086840212), -INT32_C(  1041124272) },
      {  INT32_C(  1031696453), -INT32_C(   545004695) },
      { -INT32_C(   520750655),  INT32_C(    58593166) } },
    { {  INT64_C( 6104441924141944354), -INT64_C( 3418550825214561855) },
      {  INT32_C(  1499590201), -INT32_C(  1946034489) },
      { -INT32_C(  1397570596), -INT32_C(   250084418) },
      { -INT32_C(   357381361), -INT32_C(   607887345) },
      {  INT32_C(   768959894),  INT32_C(   599230656) },
      {  INT32_C(  1421301142), -INT32_C(   795943389) } },
    { {  INT64_C( 3971568921213135484), -INT64_C( 3755342752156903086) },
      { -INT32_C(  1862824022), -INT32_C(  1484822939) },
      { -INT32_C(   954077409), -INT32_C(  1118896435) },
      { -INT32_C(  1155758148),  INT32_C(  1257585659) },
      { -INT32_C(   948553457), -INT32_C(   124392840) },
      {  INT32_C(   924702948), -INT32_C(   874358870) } },
    { {  INT64_C( 8417186688683695589), -INT64_C( 6881779349013117300) },
      { -INT32_C(   907244168), -INT32_C(  1833053926) },
      { -INT32_C(   711730917),  INT32_C(   287669154) },
      { -INT32_C(    78229660), -INT32_C(   532376081) },
      {  INT32_C(   871804063),  INT32_C(   532711724) },
      {  INT32_C(  1959778994), -INT32_C(  1602289115) } },
    { { -INT64_C( 8284095280205438227),  INT64_C( 2092008030369276308) },
      { -INT32_C(   280529524), -INT32_C(   520768634) },
      { -INT32_C(   639725845),  INT32_C(  1908534119) },
      {  INT32_C(   526875196),  INT32_C(   164038574) },
      {  INT32_C(  1111412468),  INT32_C(  1108577807) },
      { -INT32_C(  1928791236),  INT32_C(   487083576) } },
    { { -INT64_C( 7867393797001827413),  INT64_C( 3851634624841205166) },
      {  INT32_C(   427188399),  INT32_C(   591987991) },
      {  INT32_C(   942861505),  INT32_C(   172397066) },
      {  INT32_C(   752929715),  INT32_C(  2015959624) },
      { -INT32_C(  1269186153),  INT32_C(  1559253557) },
      { -INT32_C(  1831770362),  INT32_C(   896778569) } },
    { { -INT64_C( 2239680672823881693),  INT64_C( 5783790312218253295) },
      {  INT32_C(   762845505), -INT32_C(  1801685664) },
      {  INT32_C(  1918562355),  INT32_C(   891893995) },
      {  INT32_C(  1640590273), -INT32_C(  2066438940) },
      {  INT32_C(   985895640),  INT32_C(   285845834) },
      { -INT32_C(   521466293),  INT32_C(  1346643621) } },
    { { -INT64_C( 1015140313784722351),  INT64_C( 1099502746014591941) },
      {  INT32_C(   224312177), -INT32_C(  1338568529) },
      { -INT32_C(    98910857), -INT32_C(  1084199391) },
      {  INT32_C(   803760886),  INT32_C(  1191018937) },
      {  INT32_C(  2053099734), -INT32_C(   796001533) },
      { -INT32_C(   236355773),  INT32_C(   255997932) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_int32x2_t r6 = simde_vrshrn_n_s64(a, 6);
    simde_int32x2_t r13 = simde_vrshrn_n_s64(a, 13);
    simde_int32x2_t r19 = simde_vrshrn_n_s64(a, 19);
    simde_int32x2_t r26 = simde_vrshrn_n_s64(a, 26);
    simde_int32x2_t r32 = simde_vrshrn_n_s64(a, 32);

    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r32, simde_vld1_s32(test_vec[i].r32));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();

    simde_int32x2_t r6 = simde_vrshrn_n_s64(a, 6);
    simde_int32x2_t r13 = simde_vrshrn_n_s64(a, 13);
    simde_int32x2_t r19 = simde_vrshrn_n_s64(a, 19);
    simde_int32x2_t r26 = simde_vrshrn_n_s64(a, 26);
    simde_int32x2_t r32 = simde_vrshrn_n_s64(a, 32);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshrn_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { { UINT16_C(32691), UINT16_C(23718), UINT16_C(10503), UINT16_C( 9687), UINT16_C(12350), UINT16_C( 1117), UINT16_C( 2002), UINT16_C(58774) },
      { UINT8_C(218), UINT8_C( 83), UINT8_C(132), UINT8_C(236), UINT8_C( 31), UINT8_C( 47), UINT8_C(233), UINT8_C(203) },
      { UINT8_C(246), UINT8_C(149), UINT8_C( 33), UINT8_C(187), UINT8_C(  8), UINT8_C(140), UINT8_C(250), UINT8_C(179) },
      { UINT8_C(254), UINT8_C(229), UINT8_C( 72), UINT8_C( 47), UINT8_C(130), UINT8_C( 35), UINT8_C( 63), UINT8_C( 45) },
      {    UINT8_MAX, UINT8_C(115), UINT8_C(164), UINT8_C(151), UINT8_C(193), UINT8_C( 17), UINT8_C( 31), UINT8_C(150) },
      { UINT8_C(128), UINT8_C( 93), UINT8_C( 41), UINT8_C( 38), UINT8_C( 48), UINT8_C(  4), UINT8_C(  8), UINT8_C(230) } },
    { { UINT16_C(30207), UINT16_C(16504), UINT16_C( 8470), UINT16_C( 6756), UINT16_C(37766), UINT16_C(16633), UINT16_C(34550), UINT16_C(43500) },
      { UINT8_C(  0), UINT8_C( 60), UINT8_C(139), UINT8_C( 50), UINT8_C(195), UINT8_C(125), UINT8_C(123), UINT8_C(246) },
      { UINT8_C(192), UINT8_C( 15), UINT8_C( 35), UINT8_C( 77), UINT8_C(113), UINT8_C( 31), UINT8_C(223), UINT8_C( 62) },
      { UINT8_C(176), UINT8_C(  4), UINT8_C(  9), UINT8_C(211), UINT8_C(156), UINT8_C(  8), UINT8_C( 56), UINT8_C( 79) },
      { UINT8_C(216), UINT8_C(  2), UINT8_C(132), UINT8_C(106), UINT8_C( 78), UINT8_C(  4), UINT8_C( 28), UINT8_C(168) },
      { UINT8_C(118), UINT8_C( 64), UINT8_C( 33), UINT8_C( 26), UINT8_C(148), UINT8_C( 65), UINT8_C(135), UINT8_C(170) } },
    { { UINT16_C(37381), UINT16_C( 3078), UINT16_C(56764), UINT16_C(64050), UINT16_C(36621), UINT16_C(57342), UINT16_C(38038), UINT16_C(38340) },
      { UINT8_C(  3), UINT8_C(  3), UINT8_C(222), UINT8_C( 25), UINT8_C(135),    UINT8_MAX, UINT8_C( 75), UINT8_C(226) },
      { UINT8_C( 65), UINT8_C(129), UINT8_C(184), UINT8_C( 70), UINT8_C(226), UINT8_C(  0), UINT8_C(147), UINT8_C(185) },
      { UINT8_C(144), UINT8_C( 96), UINT8_C(238), UINT8_C(210), UINT8_C(120), UINT8_C(  0), UINT8_C(165), UINT8_C(174) },
      { UINT8_C( 72), UINT8_C( 48), UINT8_C(119), UINT8_C(233), UINT8_C( 60), UINT8_C(128), UINT8_C( 82), UINT8_C( 87) },
      { UINT8_C(146), UINT8_C( 12), UINT8_C(222), UINT8_C(250), UINT8_C(143), UINT8_C(224), UINT8_C(149), UINT8_C(150) } },
    { { UINT16_C(15625), UINT16_C( 8149), UINT16_C(14942), UINT16_C(58425), UINT16_C(13261), UINT16_C(49957), UINT16_C( 4537), UINT16_C(49005) },
      { UINT8_C(133), UINT8_C(235), UINT8_C( 47), UINT8_C( 29), UINT8_C(231), UINT8_C(147), UINT8_C(221), UINT8_C(183) },
      { UINT8_C(161), UINT8_C(251), UINT8_C( 76), UINT8_C(135), UINT8_C(122), UINT8_C(101), UINT8_C( 55), UINT8_C(238) },
      { UINT8_C(232),    UINT8_MAX, UINT8_C(211), UINT8_C( 34), UINT8_C(158), UINT8_C( 25), UINT8_C(142), UINT8_C(251) },
      { UINT8_C(244), UINT8_C(127), UINT8_C(233), UINT8_C(145), UINT8_C(207), UINT8_C( 13), UINT8_C( 71), UINT8_C(254) },
      { UINT8_C( 61), UINT8_C( 32), UINT8_C( 58), UINT8_C(228), UINT8_C( 52), UINT8_C(195), UINT8_C( 18), UINT8_C(191) } },
    { { UINT16_C(29603), UINT16_C(24523), UINT16_C(64848), UINT16_C(23897), UINT16_C(22413), UINT16_C( 9020), UINT16_C(  491), UINT16_C(62649) },
      { UINT8_C(210), UINT8_C(230), UINT8_C(168), UINT8_C(173), UINT8_C(199), UINT8_C(158), UINT8_C(246), UINT8_C( 93) },
      { UINT8_C(116), UINT8_C(249), UINT8_C(170), UINT8_C(171), UINT8_C(242), UINT8_C(104), UINT8_C( 61), UINT8_C(151) },
      { UINT8_C(157), UINT8_C(254), UINT8_C(235), UINT8_C(235), UINT8_C(188), UINT8_C( 26), UINT8_C( 15), UINT8_C(166) },
      { UINT8_C(207), UINT8_C(127), UINT8_C(245), UINT8_C(117), UINT8_C( 94), UINT8_C(141), UINT8_C(  8), UINT8_C(211) },
      { UINT8_C(116), UINT8_C( 96), UINT8_C(253), UINT8_C( 93), UINT8_C( 88), UINT8_C( 35), UINT8_C(  2), UINT8_C(245) } },
    { { UINT16_C(36414), UINT16_C(39956), UINT16_C(19912), UINT16_C(38272), UINT16_C(42368), UINT16_C(14937), UINT16_C(50870), UINT16_C(23289) },
      { UINT8_C( 31), UINT8_C( 10), UINT8_C(228), UINT8_C(192), UINT8_C(192), UINT8_C( 45), UINT8_C( 91), UINT8_C(125) },
      { UINT8_C(200), UINT8_C(131), UINT8_C(185), UINT8_C(176), UINT8_C(176), UINT8_C( 75), UINT8_C(215), UINT8_C( 95) },
      { UINT8_C(114), UINT8_C(225), UINT8_C(110), UINT8_C(172), UINT8_C( 44), UINT8_C(211), UINT8_C( 54), UINT8_C(216) },
      { UINT8_C( 57), UINT8_C(112), UINT8_C( 55), UINT8_C( 86), UINT8_C(150), UINT8_C(233), UINT8_C( 27), UINT8_C(108) },
      { UINT8_C(142), UINT8_C(156), UINT8_C( 78), UINT8_C(150), UINT8_C(166), UINT8_C( 58), UINT8_C(199), UINT8_C( 91) } },
    { { UINT16_C(50233), UINT16_C(35257), UINT16_C( 5058), UINT16_C(20454), UINT16_C( 8810), UINT16_C(22130), UINT16_C(11043), UINT16_C(24906) },
      { UINT8_C( 29), UINT8_C(221), UINT8_C(225), UINT8_C(243), UINT8_C( 53), UINT8_C( 57), UINT8_C(146), UINT8_C(165) },
      { UINT8_C(135), UINT8_C( 55), UINT8_C(120), UINT8_C(253), UINT8_C( 77), UINT8_C(206), UINT8_C(100), UINT8_C( 41) },
      { UINT8_C( 34), UINT8_C( 78), UINT8_C(158), UINT8_C(127), UINT8_C( 19), UINT8_C(180), UINT8_C( 89), UINT8_C( 10) },
      { UINT8_C( 17), UINT8_C( 39), UINT8_C( 79), UINT8_C( 64), UINT8_C(138), UINT8_C( 90), UINT8_C(173), UINT8_C(133) },
      { UINT8_C(196), UINT8_C(138), UINT8_C( 20), UINT8_C( 80), UINT8_C( 34), UINT8_C( 86), UINT8_C( 43), UINT8_C( 97) } },
    { { UINT16_C(24250), UINT16_C(33533), UINT16_C(32428), UINT16_C(11288), UINT16_C(28963), UINT16_C(55910), UINT16_C(24375), UINT16_C(28724) },
      { UINT8_C( 93), UINT8_C(127), UINT8_C( 86), UINT8_C( 12), UINT8_C(146), UINT8_C( 51), UINT8_C(156), UINT8_C( 26) },
      { UINT8_C(215), UINT8_C( 96), UINT8_C(214), UINT8_C(131), UINT8_C( 36), UINT8_C( 77), UINT8_C(231), UINT8_C(  7) },
      { UINT8_C(246), UINT8_C( 24), UINT8_C(245), UINT8_C( 97), UINT8_C(137), UINT8_C(211), UINT8_C(250), UINT8_C(130) },
      { UINT8_C(123), UINT8_C( 12), UINT8_C(251), UINT8_C(176), UINT8_C(197), UINT8_C(106), UINT8_C(125), UINT8_C(193) },
      { UINT8_C( 95), UINT8_C(131), UINT8_C(127), UINT8_C( 44), UINT8_C(113), UINT8_C(218), UINT8_C( 95), UINT8_C(112) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);

    simde_uint8x8_t r1 = simde_vrshrn_n_u16(a, 1);
    simde_uint8x8_t r3 = simde_vrshrn_n_u16(a, 3);
    simde_uint8x8_t r5 = simde_vrshrn_n_u16(a, 5);
    simde_uint8x8_t r6 = simde_vrshrn_n_u16(a, 6);
    simde_uint8x8_t r8 = simde_vrshrn_n_u16(a, 8);

    simde_test_arm_neon_assert_equal_u8x8(r1, simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r6, simde_vld1_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x8(r8, simde_vld1_u8(test_vec[i].r8));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();

    simde_uint8x8_t r1 = simde_vrshrn_n_u16(a, 1);
    simde_uint8x8_t r3 = simde_vrshrn_n_u16(a, 3);
    simde_uint8x8_t r5 = simde_vrshrn_n_u16(a, 5);
    simde_uint8x8_t r6 = simde_vrshrn_n_u16(a, 6);
    simde_uint8x8_t r8 = simde_vrshrn_n_u16(a, 8);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r8, SIMDE_TEST_VEC_POS_LAST);

  }
  return 1;
#endif
}

static int
test_simde_vrshrn_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { UINT32_C(3217229626), UINT32_C(3167645061), UINT32_C(2068396765), UINT32_C( 400791578) },
      { UINT16_C(24807), UINT16_C(52657), UINT16_C(10076), UINT16_C(29443) },
      { UINT16_C( 3101), UINT16_C(14774), UINT16_C( 9451), UINT16_C(36448) },
      { UINT16_C(61634), UINT16_C(13211), UINT16_C(53839), UINT16_C(63718) },
      { UINT16_C(65048), UINT16_C(58995), UINT16_C(55882), UINT16_C(48925) },
      { UINT16_C(49091), UINT16_C(48334), UINT16_C(31561), UINT16_C( 6116) } },
    { { UINT32_C(2919644847), UINT32_C(3770634696), UINT32_C(2491720955), UINT32_C(1484738846) },
      { UINT16_C(51158), UINT16_C(59961), UINT16_C(38047), UINT16_C(59940) },
      { UINT16_C( 6395), UINT16_C(64839), UINT16_C( 4756), UINT16_C(64836) },
      { UINT16_C(33168), UINT16_C(12244), UINT16_C( 8489), UINT16_C( 8148) },
      { UINT16_C(28722), UINT16_C( 1531), UINT16_C(42021), UINT16_C(50171) },
      { UINT16_C(44550), UINT16_C(57535), UINT16_C(38021), UINT16_C(22655) } },
    { { UINT32_C(3726066265), UINT32_C(2358961583), UINT32_C( 973660960), UINT32_C( 726854523) },
      { UINT16_C(59467), UINT16_C(23734), UINT16_C( 7268), UINT16_C(23919) },
      { UINT16_C(23817), UINT16_C(27543), UINT16_C( 9101), UINT16_C(19374) },
      { UINT16_C(34257), UINT16_C( 9913), UINT16_C(33337), UINT16_C(54459) },
      { UINT16_C(61626), UINT16_C(25815), UINT16_C(53319), UINT16_C(23191) },
      { UINT16_C(56855), UINT16_C(35995), UINT16_C(14857), UINT16_C(11091) } },
    { { UINT32_C(4074330153), UINT32_C(2765265321), UINT32_C(1530419005), UINT32_C(  28555176) },
      { UINT16_C(11013), UINT16_C(21301), UINT16_C( 2792), UINT16_C(30453) },
      { UINT16_C(25953), UINT16_C(19047), UINT16_C(57693), UINT16_C(52959) },
      { UINT16_C(46678), UINT16_C(13478), UINT16_C(52758), UINT16_C(27886) },
      { UINT16_C(38603), UINT16_C( 9877), UINT16_C(55747), UINT16_C( 3486) },
      { UINT16_C(62169), UINT16_C(42195), UINT16_C(23352), UINT16_C(  436) } },
    { { UINT32_C(2850016249), UINT32_C(3493165744), UINT32_C(3641392477), UINT32_C(1376017705) },
      { UINT16_C(63871), UINT16_C(44886), UINT16_C(26540), UINT16_C(35749) },
      { UINT16_C(32560), UINT16_C(54763), UINT16_C(11509), UINT16_C( 4469) },
      { UINT16_C(30707), UINT16_C( 3423), UINT16_C(17103), UINT16_C(33047) },
      { UINT16_C(20222), UINT16_C(33196), UINT16_C(51290), UINT16_C(36899) },
      { UINT16_C(43488), UINT16_C(53301), UINT16_C(55563), UINT16_C(20996) } },
    { { UINT32_C(1581571509), UINT32_C(3003324278), UINT32_C( 370031470), UINT32_C(3961045747) },
      { UINT16_C(39863), UINT16_C(25327), UINT16_C(51054), UINT16_C( 6238) },
      { UINT16_C( 4983), UINT16_C( 3166), UINT16_C(14574), UINT16_C(25356) },
      { UINT16_C(37175), UINT16_C(49350), UINT16_C(33679), UINT16_C( 1585) },
      { UINT16_C(61991), UINT16_C(38937), UINT16_C(45170), UINT16_C(24774) },
      { UINT16_C(24133), UINT16_C(45827), UINT16_C( 5646), UINT16_C(60441) } },
    { { UINT32_C(1033238413), UINT32_C(3473853297), UINT32_C( 833100040), UINT32_C( 730115190) },
      { UINT16_C(48882), UINT16_C(55662), UINT16_C(  801), UINT16_C(38287) },
      { UINT16_C(22494), UINT16_C(15150), UINT16_C(41060), UINT16_C( 4786) },
      { UINT16_C(25982), UINT16_C(50099), UINT16_C(27142), UINT16_C(57643) },
      { UINT16_C(60592), UINT16_C(30838), UINT16_C(36161), UINT16_C(23589) },
      { UINT16_C(15766), UINT16_C(53007), UINT16_C(12712), UINT16_C(11141) } },
    { { UINT32_C(   9029769), UINT32_C(1303612639), UINT32_C(3143942856), UINT32_C( 296189060) },
      { UINT16_C(14609), UINT16_C(29084), UINT16_C(39001), UINT16_C(61329) },
      { UINT16_C(10018), UINT16_C(52787), UINT16_C(37643), UINT16_C(40434) },
      { UINT16_C( 8818), UINT16_C(27875), UINT16_C(55601), UINT16_C(27103) },
      { UINT16_C( 1102), UINT16_C(28060), UINT16_C(56102), UINT16_C(36156) },
      { UINT16_C(  138), UINT16_C(19892), UINT16_C(47973), UINT16_C( 4519) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);

    simde_uint16x4_t r3 = simde_vrshrn_n_u32(a, 3);
    simde_uint16x4_t r6 = simde_vrshrn_n_u32(a, 6);
    simde_uint16x4_t r10 = simde_vrshrn_n_u32(a, 10);
    simde_uint16x4_t r13 = simde_vrshrn_n_u32(a, 13);
    simde_uint16x4_t r16 = simde_vrshrn_n_u32(a, 16);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r16, simde_vld1_u16(test_vec[i].r16));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();

    simde_uint16x4_t r3 = simde_vrshrn_n_u32(a, 3);
    simde_uint16x4_t r6 = simde_vrshrn_n_u32(a, 6);
    simde_uint16x4_t r10 = simde_vrshrn_n_u32(a, 10);
    simde_uint16x4_t r13 = simde_vrshrn_n_u32(a, 13);
    simde_uint16x4_t r16 = simde_vrshrn_n_u32(a, 16);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshrn_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { UINT64_C(  567389591719843308), UINT64_C(   92097544496575753) },
      { UINT32_C(1331616856), UINT32_C(3930168788) },
      { UINT32_C( 782155193), UINT32_C(2446623548) },
      { UINT32_C(4172970743), UINT32_C(3863433741) },
      { UINT32_C(4159796470), UINT32_C(1372360356) },
      { UINT32_C( 132105684), UINT32_C(  21443131) } },
    { { UINT64_C( 2709718163430742634), UINT64_C(17310429608007448409) },
      { UINT32_C(1081268842), UINT32_C( 238731485) },
      { UINT32_C(3531662773), UINT32_C(   1865090) },
      { UINT32_C(1531577239), UINT32_C(1610641878) },
      { UINT32_C(1723241479), UINT32_C( 247464164) },
      { UINT32_C( 630905424), UINT32_C(4030398468) } },
    { { UINT64_C(13902513883530654229), UINT64_C(17534651385504618011) },
      { UINT32_C(3752009672), UINT32_C( 559235416) },
      { UINT32_C( 901727808), UINT32_C(3292703363) },
      { UINT32_C(4107730201), UINT32_C(4077980330) },
      { UINT32_C(1005170170), UINT32_C(3588629013) },
      { UINT32_C(3236931256), UINT32_C(4082604168) } },
    { { UINT64_C( 4731218220354047282), UINT64_C( 7986019416146925792) },
      { UINT32_C(2651601973), UINT32_C(1670593892) },
      { UINT32_C(1329338488), UINT32_C(1388783227) },
      { UINT32_C( 356315234), UINT32_C(2169183386) },
      { UINT32_C(1781168609), UINT32_C(3036845625) },
      { UINT32_C(1101572584), UINT32_C(1859390041) } },
    { { UINT64_C( 6661745521806711804), UINT64_C(10238944039905969052) },
      { UINT32_C( 114121328), UINT32_C(1821821710) },
      { UINT32_C( 839752373), UINT32_C(1255746966) },
      { UINT32_C(1757951595), UINT32_C(  19621046) },
      { UINT32_C( 483496045), UINT32_C(2248300233) },
      { UINT32_C(1551058498), UINT32_C(2383939931) } },
    { { UINT64_C(12772131379807856406), UINT64_C( 1501784554322857489) },
      { UINT32_C(1207452828), UINT32_C(1638290488) },
      { UINT32_C(3465539721), UINT32_C(1220758696) },
      { UINT32_C(4147789762), UINT32_C(3978497331) },
      { UINT32_C(1341027456), UINT32_C( 903497242) },
      { UINT32_C(2973743570), UINT32_C( 349661464) } },
    { { UINT64_C( 1198584721895271940), UINT64_C( 8351729097305838845) },
      { UINT32_C(3507952824), UINT32_C(1969542484) },
      { UINT32_C(3550621241), UINT32_C(1793771947) },
      { UINT32_C(1196329145), UINT32_C(3920341799) },
      { UINT32_C( 680434961), UINT32_C(4191377238) },
      { UINT32_C( 279067252), UINT32_C(1944538461) } },
    { { UINT64_C(14048891838043125877), UINT64_C(18152325606760222142) },
      { UINT32_C(3306801122), UINT32_C(3680022071) },
      { UINT32_C(2240426896), UINT32_C( 532066652) },
      { UINT32_C(4128647374), UINT32_C(1082055365) },
      { UINT32_C(3186371666), UINT32_C(4202757558) },
      { UINT32_C(3271012529), UINT32_C(4226417655) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);

    simde_uint32x2_t r6 = simde_vrshrn_n_u64(a, 6);
    simde_uint32x2_t r13 = simde_vrshrn_n_u64(a, 13);
    simde_uint32x2_t r19 = simde_vrshrn_n_u64(a, 19);
    simde_uint32x2_t r26 = simde_vrshrn_n_u64(a, 26);
    simde_uint32x2_t r32 = simde_vrshrn_n_u64(a, 32);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r32, simde_vld1_u32(test_vec[i].r32));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();

    simde_uint32x2_t r6 = simde_vrshrn_n_u64(a, 6);
    simde_uint32x2_t r13 = simde_vrshrn_n_u64(a, 13);
    simde_uint32x2_t r19 = simde_vrshrn_n_u64(a, 19);
    simde_uint32x2_t r26 = simde_vrshrn_n_u64(a, 26);
    simde_uint32x2_t r32 = simde_vrshrn_n_u64(a, 32);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrn_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
