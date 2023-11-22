#define SIMDE_TEST_ARM_NEON_INSN sli_n

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/sli_n.h>

static int
test_simde_vsli_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r0[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r7[8];
  } test_vec[] = {
    { { -INT8_C(  101),  INT8_C(   26),  INT8_C(    9),  INT8_C(   26),  INT8_C(   49), -INT8_C(   61),  INT8_C(  126),  INT8_C(   21)  },
      { -INT8_C(   44), -INT8_C(  122),  INT8_C(   93),  INT8_C(   94),  INT8_C(   54), -INT8_C(   71), -INT8_C(   21),  INT8_C(   56)  },
      { -INT8_C(   44), -INT8_C(  122),  INT8_C(   93),  INT8_C(   94),  INT8_C(   54), -INT8_C(   71), -INT8_C(   21),  INT8_C(   56)  },
      { -INT8_C(   93),  INT8_C(   50), -INT8_C(   23), -INT8_C(   14), -INT8_C(   79), -INT8_C(   53),  INT8_C(   94), -INT8_C(   59)  },
      { -INT8_C(  101), -INT8_C(   38), -INT8_C(   87), -INT8_C(   38), -INT8_C(   47),  INT8_C(   35),  INT8_C(  126),  INT8_C(   21)  },
      {  INT8_C(   27),  INT8_C(   26), -INT8_C(  119),  INT8_C(   26),  INT8_C(   49), -INT8_C(   61), -INT8_C(    2),  INT8_C(   21)  } },
    { { -INT8_C(   52), -INT8_C(   65),  INT8_C(    2),  INT8_C(    9),  INT8_C(  115), -INT8_C(  114),  INT8_C(   25),  INT8_C(   51)  },
      {  INT8_C(   36), -INT8_C(   93),  INT8_C(  125), -INT8_C(   57), -INT8_C(   97),  INT8_C(   56),  INT8_C(    7), -INT8_C(   86)  },
      {  INT8_C(   36), -INT8_C(   93),  INT8_C(  125), -INT8_C(   57), -INT8_C(   97),  INT8_C(   56),  INT8_C(    7), -INT8_C(   86)  },
      {  INT8_C(   36),  INT8_C(   31), -INT8_C(   22),  INT8_C(   57), -INT8_C(    5), -INT8_C(   58),  INT8_C(   57),  INT8_C(   83)  },
      { -INT8_C(  116),       INT8_MAX, -INT8_C(   94), -INT8_C(   23), -INT8_C(   13),  INT8_C(   14), -INT8_C(    7),  INT8_C(   83)  },
      {  INT8_C(   76), -INT8_C(   65), -INT8_C(  126), -INT8_C(  119), -INT8_C(   13),  INT8_C(   14), -INT8_C(  103),  INT8_C(   51)  } },
    { {  INT8_C(    6), -INT8_C(   75), -INT8_C(  113), -INT8_C(  102),  INT8_C(   91),  INT8_C(  107), -INT8_C(   19), -INT8_C(   49)  },
      {  INT8_C(  125),  INT8_C(   24), -INT8_C(  117), -INT8_C(   52),  INT8_C(   56), -INT8_C(   96), -INT8_C(   78), -INT8_C(  125)  },
      {  INT8_C(  125),  INT8_C(   24), -INT8_C(  117), -INT8_C(   52),  INT8_C(   56), -INT8_C(   96), -INT8_C(   78), -INT8_C(  125)  },
      { -INT8_C(   18), -INT8_C(   59),  INT8_C(   95),  INT8_C(   98), -INT8_C(   61),  INT8_C(    3), -INT8_C(  107),  INT8_C(   31)  },
      { -INT8_C(   90),  INT8_C(   21),  INT8_C(  111), -INT8_C(  102),  INT8_C(   27),  INT8_C(   11),  INT8_C(   77),  INT8_C(  111)  },
      { -INT8_C(  122),  INT8_C(   53), -INT8_C(  113),  INT8_C(   26),  INT8_C(   91),  INT8_C(  107),  INT8_C(  109), -INT8_C(   49)  } },
    { {  INT8_C(   75), -INT8_C(   25),  INT8_C(   53),  INT8_C(   41), -INT8_C(   91), -INT8_C(   47),  INT8_C(   11),  INT8_C(  120)  },
      {  INT8_C(   26), -INT8_C(  111), -INT8_C(   51), -INT8_C(   50), -INT8_C(  100),  INT8_C(   21), -INT8_C(  106), -INT8_C(   93)  },
      {  INT8_C(   26), -INT8_C(  111), -INT8_C(   51), -INT8_C(   50), -INT8_C(  100),  INT8_C(   21), -INT8_C(  106), -INT8_C(   93)  },
      { -INT8_C(   45), -INT8_C(  113),  INT8_C(  109),  INT8_C(  113), -INT8_C(   27), -INT8_C(   87), -INT8_C(   77),  INT8_C(   24)  },
      {  INT8_C(   75),  INT8_C(   39), -INT8_C(   75), -INT8_C(   55), -INT8_C(  123), -INT8_C(   79), -INT8_C(   53),  INT8_C(  120)  },
      {  INT8_C(   75), -INT8_C(   25), -INT8_C(   75),  INT8_C(   41),  INT8_C(   37), -INT8_C(   47),  INT8_C(   11), -INT8_C(    8)  } },
    { { -INT8_C(   87), -INT8_C(   95), -INT8_C(    8), -INT8_C(   55), -INT8_C(  109), -INT8_C(   83), -INT8_C(   16), -INT8_C(   60)  },
      {  INT8_C(   67), -INT8_C(  113),  INT8_C(   90), -INT8_C(  126), -INT8_C(   75), -INT8_C(   92),  INT8_C(   62),  INT8_C(  117)  },
      {  INT8_C(   67), -INT8_C(  113),  INT8_C(   90), -INT8_C(  126), -INT8_C(   75), -INT8_C(   92),  INT8_C(   62),  INT8_C(  117)  },
      {  INT8_C(   25),  INT8_C(  121), -INT8_C(   48),  INT8_C(   17), -INT8_C(   85),  INT8_C(   37), -INT8_C(   16), -INT8_C(   84)  },
      {  INT8_C(  105), -INT8_C(   31),  INT8_C(   88),  INT8_C(   73), -INT8_C(   77), -INT8_C(  115), -INT8_C(   48), -INT8_C(   92)  },
      { -INT8_C(   87), -INT8_C(   95),  INT8_C(  120),  INT8_C(   73), -INT8_C(  109),  INT8_C(   45),  INT8_C(  112), -INT8_C(   60)  } },
    { {  INT8_C(  123),  INT8_C(   75), -INT8_C(   20), -INT8_C(   51),  INT8_C(  120),  INT8_C(   69),  INT8_C(   48),  INT8_C(   75)  },
      { -INT8_C(   63), -INT8_C(  101), -INT8_C(  127),  INT8_C(   26), -INT8_C(   50), -INT8_C(   85),  INT8_C(   50), -INT8_C(   88)  },
      { -INT8_C(   63), -INT8_C(  101), -INT8_C(  127),  INT8_C(   26), -INT8_C(   50), -INT8_C(   85),  INT8_C(   50), -INT8_C(   88)  },
      {  INT8_C(   11), -INT8_C(   37),  INT8_C(   12), -INT8_C(   43),  INT8_C(  112),  INT8_C(   93), -INT8_C(  112),  INT8_C(   67)  },
      {  INT8_C(   59),  INT8_C(  107),  INT8_C(   44),  INT8_C(   77), -INT8_C(   40),  INT8_C(  101),  INT8_C(   80),  INT8_C(   11)  },
      { -INT8_C(    5), -INT8_C(   53), -INT8_C(   20),  INT8_C(   77),  INT8_C(  120), -INT8_C(   59),  INT8_C(   48),  INT8_C(   75)  } },
    { { -INT8_C(   23), -INT8_C(   99), -INT8_C(  123), -INT8_C(  103),  INT8_C(   63), -INT8_C(   97), -INT8_C(   22),  INT8_C(  117)  },
      { -INT8_C(   75), -INT8_C(  111),  INT8_C(   98), -INT8_C(   17), -INT8_C(    5),  INT8_C(  109),  INT8_C(   78),  INT8_C(   52)  },
      { -INT8_C(   75), -INT8_C(  111),  INT8_C(   98), -INT8_C(   17), -INT8_C(    5),  INT8_C(  109),  INT8_C(   78),  INT8_C(   52)  },
      { -INT8_C(   87), -INT8_C(  115),  INT8_C(   21),  INT8_C(  121), -INT8_C(   33),  INT8_C(  111),  INT8_C(  114), -INT8_C(   91)  },
      { -INT8_C(   87),  INT8_C(   61),  INT8_C(   69), -INT8_C(    7),       INT8_MAX, -INT8_C(   65), -INT8_C(   54), -INT8_C(  107)  },
      { -INT8_C(   23), -INT8_C(   99),  INT8_C(    5), -INT8_C(  103), -INT8_C(   65), -INT8_C(   97),  INT8_C(  106),  INT8_C(  117)  } },
    { {  INT8_C(   98),  INT8_C(   62),  INT8_C(  126), -INT8_C(   74), -INT8_C(   10),  INT8_C(  124),  INT8_C(   96), -INT8_C(   61)  },
      { -INT8_C(  110),  INT8_C(  111),  INT8_C(   80),  INT8_C(  107),  INT8_C(  102),  INT8_C(    8),  INT8_C(   75), -INT8_C(   51)  },
      { -INT8_C(  110),  INT8_C(  111),  INT8_C(   80),  INT8_C(  107),  INT8_C(  102),  INT8_C(    8),  INT8_C(   75), -INT8_C(   51)  },
      { -INT8_C(  110),  INT8_C(  126), -INT8_C(  122),  INT8_C(   94),  INT8_C(   54),  INT8_C(   68),  INT8_C(   88),  INT8_C(  107)  },
      {  INT8_C(   66), -INT8_C(    2),  INT8_C(   30),  INT8_C(  118), -INT8_C(   42),  INT8_C(   28),  INT8_C(   96), -INT8_C(   93)  },
      {  INT8_C(   98), -INT8_C(   66),  INT8_C(  126), -INT8_C(   74),  INT8_C(  118),  INT8_C(  124), -INT8_C(   32), -INT8_C(   61)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);

    simde_int8x8_t r0 = simde_vsli_n_s8(a, b, 0);
    simde_int8x8_t r3 = simde_vsli_n_s8(a, b, 3);
    simde_int8x8_t r5 = simde_vsli_n_s8(a, b, 5);
    simde_int8x8_t r7 = simde_vsli_n_s8(a, b, 7);

    simde_test_arm_neon_assert_equal_i8x8(r0, simde_vld1_s8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r7, simde_vld1_s8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r0 = simde_vsli_n_s8(a, b, 0);
    simde_int8x8_t r3 = simde_vsli_n_s8(a, b, 3);
    simde_int8x8_t r5 = simde_vsli_n_s8(a, b, 5);
    simde_int8x8_t r7 = simde_vsli_n_s8(a, b, 7);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r15[4];
  } test_vec[] = {
    { {  INT16_C(  23715), -INT16_C(   5119), -INT16_C(    948), -INT16_C(  10596)  },
      { -INT16_C(  10350), -INT16_C(   1795), -INT16_C(  14589),  INT16_C(  23500)  },
      { -INT16_C(  17261), -INT16_C(  14359),  INT16_C(  14364), -INT16_C(   8604)  },
      { -INT16_C(   7005),  INT16_C(  16193), -INT16_C(  16180), -INT16_C(   3300)  },
      {  INT16_C(  18595), -INT16_C(   3071),  INT16_C(   3148),  INT16_C(  12956)  },
      {  INT16_C(  23715), -INT16_C(  21503),  INT16_C(  31820), -INT16_C(  26980)  },
      {  INT16_C(  23715), -INT16_C(   5119), -INT16_C(    948),  INT16_C(  22172)  } },
    { { -INT16_C(   7934),  INT16_C(  21731), -INT16_C(  14529),  INT16_C(   7523)  },
      {  INT16_C(  19582),  INT16_C(  30872), -INT16_C(  13482),  INT16_C(  26450)  },
      {  INT16_C(  25586), -INT16_C(  15165),  INT16_C(  23223),  INT16_C(  14995)  },
      {  INT16_C(   8066),  INT16_C(   9763), -INT16_C(  10817), -INT16_C(  11101)  },
      { -INT16_C(   1790),  INT16_C(  24803),  INT16_C(  23359),  INT16_C(  18787)  },
      { -INT16_C(  16126),  INT16_C(   5347), -INT16_C(  14529),  INT16_C(  23907)  },
      {  INT16_C(  24834),  INT16_C(  21731),  INT16_C(  18239),  INT16_C(   7523)  } },
    { { -INT16_C(  24714), -INT16_C(  31480), -INT16_C(  32651),  INT16_C(  11630)  },
      { -INT16_C(  15138),  INT16_C(  24046),  INT16_C(  29437),  INT16_C(  12656)  },
      {  INT16_C(   9974), -INT16_C(   4240), -INT16_C(  26643), -INT16_C(  29818)  },
      {  INT16_C(  14262),  INT16_C(  31624), -INT16_C(  16523),  INT16_C(  23598)  },
      {  INT16_C(  31606), -INT16_C(  18168), -INT16_C(   2955), -INT16_C(  16018)  },
      { -INT16_C(   8330), -INT16_C(  15096), -INT16_C(  24459),  INT16_C(   3438)  },
      {  INT16_C(   8054),  INT16_C(   1288), -INT16_C(  32651),  INT16_C(  11630)  } },
    { {  INT16_C(  16403),  INT16_C(  27409), -INT16_C(  10162),  INT16_C(   4136)  },
      { -INT16_C(  19183),  INT16_C(  17481),  INT16_C(   8984), -INT16_C(   8279)  },
      { -INT16_C(  22389),  INT16_C(   8777),  INT16_C(   6342), -INT16_C(    696)  },
      {  INT16_C(  17491),  INT16_C(   4689), -INT16_C(  14834), -INT16_C(   5528)  },
      {  INT16_C(  17427),  INT16_C(  10001),  INT16_C(  24654), -INT16_C(  23512)  },
      {  INT16_C(   8211),  INT16_C(  11025),  INT16_C(   6222),  INT16_C(  12328)  },
      { -INT16_C(  16365), -INT16_C(   5359),  INT16_C(  22606), -INT16_C(  28632)  } },
    { { -INT16_C(  13838), -INT16_C(  14285), -INT16_C(  31333),  INT16_C(  13782)  },
      { -INT16_C(  27229), -INT16_C(   5507),  INT16_C(    956),  INT16_C(  28420)  },
      { -INT16_C(  21222),  INT16_C(  21483),  INT16_C(   7651),  INT16_C(  30758)  },
      {  INT16_C(  26866), -INT16_C(  24717), -INT16_C(   4325), -INT16_C(  16106)  },
      { -INT16_C(  29198), -INT16_C(   3021), -INT16_C(   3685),  INT16_C(   4566)  },
      {  INT16_C(  27122), -INT16_C(  22477), -INT16_C(  31333), -INT16_C(  27178)  },
      { -INT16_C(  13838), -INT16_C(  14285),  INT16_C(   1435),  INT16_C(  13782)  } },
    { { -INT16_C(  18860),  INT16_C(  10979),  INT16_C(   2287),  INT16_C(  27177)  },
      { -INT16_C(  19616), -INT16_C(  31797), -INT16_C(  22340), -INT16_C(  25390)  },
      { -INT16_C(  25852),  INT16_C(   7771),  INT16_C(  17895), -INT16_C(   6511)  },
      { -INT16_C(  10220), -INT16_C(   3357),  INT16_C(  12079),  INT16_C(  13481)  },
      { -INT16_C(  32172),  INT16_C(  12003), -INT16_C(   3857),  INT16_C(  18985)  },
      {  INT16_C(   5716),  INT16_C(  27363), -INT16_C(  30481),  INT16_C(  18985)  },
      {  INT16_C(  13908), -INT16_C(  21789),  INT16_C(   2287),  INT16_C(  27177)  } },
    { { -INT16_C(   2519), -INT16_C(  16767),  INT16_C(   1614), -INT16_C(   7018)  },
      { -INT16_C(  20639), -INT16_C(  13532),  INT16_C(  11903),  INT16_C(   7823)  },
      {  INT16_C(  31497),  INT16_C(  22817),  INT16_C(  29694), -INT16_C(   2946)  },
      { -INT16_C(  10135), -INT16_C(  14079), -INT16_C(  24626), -INT16_C(  23594)  },
      { -INT16_C(  31191), -INT16_C(  28031), -INT16_C(    434),  INT16_C(  15510)  },
      {  INT16_C(  13865), -INT16_C(  24959), -INT16_C(   6578), -INT16_C(   7018)  },
      { -INT16_C(   2519),  INT16_C(  16001), -INT16_C(  31154), -INT16_C(   7018)  } },
    { {  INT16_C(  23386), -INT16_C(   5076),  INT16_C(   2178), -INT16_C(  19292)  },
      { -INT16_C(  15822),  INT16_C(  11790), -INT16_C(  26587),  INT16_C(  12479)  },
      {  INT16_C(   4498),  INT16_C(  28788), -INT16_C(  16086), -INT16_C(  31236)  },
      { -INT16_C(  29542), -INT16_C(  31828),  INT16_C(   2370),  INT16_C(  12260)  },
      { -INT16_C(  13478),  INT16_C(  14380), -INT16_C(  27518), -INT16_C(    860)  },
      {  INT16_C(  23386), -INT16_C(  13268), -INT16_C(  22398), -INT16_C(   2908)  },
      {  INT16_C(  23386),  INT16_C(  27692), -INT16_C(  30590), -INT16_C(  19292)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);

    simde_int16x4_t r3 = simde_vsli_n_s16(a, b, 3);
    simde_int16x4_t r6 = simde_vsli_n_s16(a, b, 6);
    simde_int16x4_t r10 = simde_vsli_n_s16(a, b, 10);
    simde_int16x4_t r13 = simde_vsli_n_s16(a, b, 13);
    simde_int16x4_t r15 = simde_vsli_n_s16(a, b, 15);

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r15, simde_vld1_s16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r3 = simde_vsli_n_s16(a, b, 3);
    simde_int16x4_t r6 = simde_vsli_n_s16(a, b, 6);
    simde_int16x4_t r10 = simde_vsli_n_s16(a, b, 10);
    simde_int16x4_t r13 = simde_vsli_n_s16(a, b, 13);
    simde_int16x4_t r15 = simde_vsli_n_s16(a, b, 15);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r31[2];
  } test_vec[] = {
    { { -INT32_C(1940115604), -INT32_C( 493831926)  },
      {  INT32_C(1869505583), -INT32_C( 899781217)  },
      { -INT32_C( 610726932), -INT32_C(1751423030)  },
      { -INT32_C( 863637652), -INT32_C( 843843318)  },
      {  INT32_C( 561786732),  INT32_C(1828239626)  },
      { -INT32_C(1134809236),  INT32_C(2123413770)  },
      { -INT32_C(1940115604), -INT32_C( 493831926)  } },
    { { -INT32_C(1955947586),  INT32_C(1978912402)  },
      { -INT32_C(1236739145),  INT32_C(1680908470)  },
      { -INT32_C(1841893890),  INT32_C( 203959698)  },
      {  INT32_C( 460782526),  INT32_C( 337038994)  },
      { -INT32_C( 574972994),  INT32_C(  95669906)  },
      { -INT32_C( 546661442), -INT32_C( 638333294)  },
      { -INT32_C(1955947586),  INT32_C(1978912402)  } },
    { {  INT32_C( 280147815), -INT32_C( 796117516)  },
      {  INT32_C( 183449113), -INT32_C(1555283915)  },
      { -INT32_C(1144158617), -INT32_C( 753922700)  },
      { -INT32_C( 423413913), -INT32_C(2012826124)  },
      { -INT32_C(1328892057),  INT32_C(  28063220)  },
      {  INT32_C(1689433959), -INT32_C( 729008652)  },
      { -INT32_C(1867335833), -INT32_C( 796117516)  } },
    { { -INT32_C( 481956659),  INT32_C(1163086735)  },
      { -INT32_C( 907228244), -INT32_C( 499683881)  },
      {  INT32_C(2066934541), -INT32_C(1914997297)  },
      { -INT32_C(1720349491), -INT32_C( 306517105)  },
      {  INT32_C(1566960845),  INT32_C(1857768335)  },
      { -INT32_C(1287263027),  INT32_C(1565739919)  },
      {  INT32_C(1665526989), -INT32_C( 984396913)  } },
    { {  INT32_C( 866589805), -INT32_C(1170103474)  },
      { -INT32_C( 619576881), -INT32_C(1677689277)  },
      { -INT32_C( 998214675),  INT32_C(   2068686)  },
      {  INT32_C(1077541997),  INT32_C( 264790862)  },
      {  INT32_C( 243211373), -INT32_C( 233200818)  },
      {  INT32_C(1067916397),  INT32_C( 239182670)  },
      { -INT32_C(1280893843), -INT32_C(1170103474)  } },
    { { -INT32_C(1782422731),  INT32_C(1801404031)  },
      { -INT32_C(  75297761), -INT32_C( 202030994)  },
      { -INT32_C( 524089355), -INT32_C(  45081665)  },
      {  INT32_C(1636033333), -INT32_C(1475486081)  },
      {  INT32_C(1627022133),  INT32_C(  58146431)  },
      {  INT32_C(2109891381), -INT32_C(1151385985)  },
      { -INT32_C(1782422731),  INT32_C(1801404031)  } },
    { { -INT32_C(1145515122), -INT32_C(1205350463)  },
      { -INT32_C(2014419578), -INT32_C( 605233209)  },
      { -INT32_C(  73834098), -INT32_C(  80219711)  },
      { -INT32_C( 860826738), -INT32_C(1678184511)  },
      {  INT32_C( 741397390), -INT32_C(  29372479)  },
      {  INT32_C( 465097614),  INT32_C( 472371137)  },
      {  INT32_C(1001968526), -INT32_C(1205350463)  } },
    { {  INT32_C(1262095535), -INT32_C(1722331384)  },
      {  INT32_C(1969407398), -INT32_C(1230587853)  },
      {  INT32_C(1488021935), -INT32_C(1448211256)  },
      {  INT32_C(1488243887), -INT32_C( 687444216)  },
      {  INT32_C( 758254767), -INT32_C(1046524152)  },
      { -INT32_C(1690694481), -INT32_C( 849916152)  },
      {  INT32_C(1262095535), -INT32_C(1722331384)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);

    simde_int32x2_t r6 = simde_vsli_n_s32(a, b, 6);
    simde_int32x2_t r13 = simde_vsli_n_s32(a, b, 13);
    simde_int32x2_t r19 = simde_vsli_n_s32(a, b, 19);
    simde_int32x2_t r26 = simde_vsli_n_s32(a, b, 26);
    simde_int32x2_t r31 = simde_vsli_n_s32(a, b, 31);

    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r31, simde_vld1_s32(test_vec[i].r31));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r6 = simde_vsli_n_s32(a, b, 6);
    simde_int32x2_t r13 = simde_vsli_n_s32(a, b, 13);
    simde_int32x2_t r19 = simde_vsli_n_s32(a, b, 19);
    simde_int32x2_t r26 = simde_vsli_n_s32(a, b, 26);
    simde_int32x2_t r31 = simde_vsli_n_s32(a, b, 31);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r13[1];
    int64_t r26[1];
    int64_t r39[1];
    int64_t r52[1];
    int64_t r63[1];
  } test_vec[] = {
    { {  INT64_C( 6231160190656283089)  },
      { -INT64_C(  460160416367637488)  },
      { -INT64_C( 6498339846937771567)  },
      {  INT64_C( 2903370611581485521)  },
      {  INT64_C( 6558938900547469777)  },
      { -INT64_C( 4536946518386572847)  },
      {  INT64_C( 6231160190656283089)  } },
    { { -INT64_C( 1382763905312428596)  },
      { -INT64_C( 4253508470463334304)  },
      {  INT64_C( 1158165201708387788)  },
      {  INT64_C( 6062878508435041740)  },
      {  INT64_C( 8465694235828350412)  },
      { -INT64_C( 8786681692709524020)  },
      {  INT64_C( 7840608131542347212)  } },
    { { -INT64_C(  188675660009576721)  },
      {  INT64_C( 8862026640770314742)  },
      { -INT64_C( 8662432930376792337)  },
      {  INT64_C( 1973885914004186863)  },
      { -INT64_C( 7721145048391358737)  },
      {  INT64_C( 2261282537279973103)  },
      {  INT64_C( 9034696376845199087)  } },
    { {  INT64_C( 8280825101553980221)  },
      { -INT64_C( 5326939997036914826)  },
      {  INT64_C( 6704022670392873789)  },
      {  INT64_C( 3396608425067762493)  },
      {  INT64_C( 7326154889283982141)  },
      {  INT64_C( 8605084274724655933)  },
      {  INT64_C( 8280825101553980221)  } },
    { { -INT64_C( 4186443145725907458)  },
      {  INT64_C( 8264653391654679543)  },
      {  INT64_C( 4489833921080389118)  },
      { -INT64_C( 2088201486283346434)  },
      { -INT64_C( 6414819513448829442)  },
      {  INT64_C( 4573058129509707262)  },
      { -INT64_C( 4186443145725907458)  } },
    { {  INT64_C(  668356405945180429)  },
      { -INT64_C( 5702155833444664254)  },
      { -INT64_C( 4904592946104876787)  },
      { -INT64_C( 1416821951687024371)  },
      { -INT64_C( 3603406246906420979)  },
      { -INT64_C( 4312624781926588147)  },
      {  INT64_C(  668356405945180429)  } },
    { { -INT64_C( 7452140987469877822)  },
      { -INT64_C( 6307661369476126878)  },
      { -INT64_C( 3031788287977304638)  },
      { -INT64_C( 7092131897022960190)  },
      {  INT64_C( 8499331815746219458)  },
      {  INT64_C( 8513119691558530498)  },
      {  INT64_C( 1771231049384897986)  } },
    { {  INT64_C( 8764810789801773550)  },
      { -INT64_C( 8804733489023547712)  },
      { -INT64_C( 1607413876556035602)  },
      {  INT64_C( 3040791881582987758)  },
      {  INT64_C( 7062594716434778606)  },
      {  INT64_C( 7783026071035005422)  },
      {  INT64_C( 8764810789801773550)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);

    simde_int64x1_t r13 = simde_vsli_n_s64(a, b, 13);
    simde_int64x1_t r26 = simde_vsli_n_s64(a, b, 26);
    simde_int64x1_t r39 = simde_vsli_n_s64(a, b, 39);
    simde_int64x1_t r52 = simde_vsli_n_s64(a, b, 52);
    simde_int64x1_t r63 = simde_vsli_n_s64(a, b, 63);

    simde_test_arm_neon_assert_equal_i64x1(r13, simde_vld1_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x1(r26, simde_vld1_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x1(r39, simde_vld1_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x1(r52, simde_vld1_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x1(r63, simde_vld1_s64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r13 = simde_vsli_n_s64(a, b, 13);
    simde_int64x1_t r26 = simde_vsli_n_s64(a, b, 26);
    simde_int64x1_t r39 = simde_vsli_n_s64(a, b, 39);
    simde_int64x1_t r52 = simde_vsli_n_s64(a, b, 52);
    simde_int64x1_t r63 = simde_vsli_n_s64(a, b, 63);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r0[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r7[8];
  } test_vec[] = {
    { {  UINT8_C(   194),  UINT8_C(   153),  UINT8_C(   182),  UINT8_C(    53),  UINT8_C(    45),  UINT8_C(   214),  UINT8_C(   136),  UINT8_C(   217)  },
      {  UINT8_C(    51),  UINT8_C(     2),  UINT8_C(    97),  UINT8_C(   189),  UINT8_C(   250),  UINT8_C(    77),  UINT8_C(    65),  UINT8_C(    28)  },
      {  UINT8_C(    51),  UINT8_C(     2),  UINT8_C(    97),  UINT8_C(   189),  UINT8_C(   250),  UINT8_C(    77),  UINT8_C(    65),  UINT8_C(    28)  },
      {  UINT8_C(   154),  UINT8_C(    17),  UINT8_C(    14),  UINT8_C(   237),  UINT8_C(   213),  UINT8_C(   110),  UINT8_C(     8),  UINT8_C(   225)  },
      {  UINT8_C(    98),  UINT8_C(    89),  UINT8_C(    54),  UINT8_C(   181),  UINT8_C(    77),  UINT8_C(   182),  UINT8_C(    40),  UINT8_C(   153)  },
      {  UINT8_C(   194),  UINT8_C(    25),  UINT8_C(   182),  UINT8_C(   181),  UINT8_C(    45),  UINT8_C(   214),  UINT8_C(   136),  UINT8_C(    89)  } },
    { {  UINT8_C(   149),  UINT8_C(   148),  UINT8_C(   192),  UINT8_C(    18),  UINT8_C(   191),  UINT8_C(   120),  UINT8_C(   160),  UINT8_C(   251)  },
      {  UINT8_C(   243),  UINT8_C(   246),  UINT8_C(   159),  UINT8_C(   234),  UINT8_C(    49),  UINT8_C(   191),  UINT8_C(   110),  UINT8_C(   189)  },
      {  UINT8_C(   243),  UINT8_C(   246),  UINT8_C(   159),  UINT8_C(   234),  UINT8_C(    49),  UINT8_C(   191),  UINT8_C(   110),  UINT8_C(   189)  },
      {  UINT8_C(   157),  UINT8_C(   180),  UINT8_C(   248),  UINT8_C(    82),  UINT8_C(   143),  UINT8_C(   248),  UINT8_C(   112),  UINT8_C(   235)  },
      {  UINT8_C(   117),  UINT8_C(   212),  UINT8_C(   224),  UINT8_C(    82),  UINT8_C(    63),  UINT8_C(   248),  UINT8_C(   192),  UINT8_C(   187)  },
      {  UINT8_C(   149),  UINT8_C(    20),  UINT8_C(   192),  UINT8_C(    18),  UINT8_C(   191),  UINT8_C(   248),  UINT8_C(    32),  UINT8_C(   251)  } },
    { {  UINT8_C(    16),  UINT8_C(    99),  UINT8_C(     9),  UINT8_C(   145),  UINT8_C(   219),  UINT8_C(    91),  UINT8_C(   218),  UINT8_C(    77)  },
      {  UINT8_C(   145),  UINT8_C(    92),  UINT8_C(     7),  UINT8_C(    26),  UINT8_C(   192),  UINT8_C(    34),  UINT8_C(     2),  UINT8_C(   133)  },
      {  UINT8_C(   145),  UINT8_C(    92),  UINT8_C(     7),  UINT8_C(    26),  UINT8_C(   192),  UINT8_C(    34),  UINT8_C(     2),  UINT8_C(   133)  },
      {  UINT8_C(   136),  UINT8_C(   227),  UINT8_C(    57),  UINT8_C(   209),  UINT8_C(     3),  UINT8_C(    19),  UINT8_C(    18),  UINT8_C(    45)  },
      {  UINT8_C(    48),  UINT8_C(   131),  UINT8_C(   233),  UINT8_C(    81),  UINT8_C(    27),  UINT8_C(    91),  UINT8_C(    90),  UINT8_C(   173)  },
      {  UINT8_C(   144),  UINT8_C(    99),  UINT8_C(   137),  UINT8_C(    17),  UINT8_C(    91),  UINT8_C(    91),  UINT8_C(    90),  UINT8_C(   205)  } },
    { {  UINT8_C(   102),  UINT8_C(   103),  UINT8_C(     7),  UINT8_C(    20),  UINT8_C(   115),  UINT8_C(   205),  UINT8_C(    70),  UINT8_C(   133)  },
      {  UINT8_C(    41),  UINT8_C(    89),  UINT8_C(   182),  UINT8_C(   231),  UINT8_C(   117),  UINT8_C(    92),  UINT8_C(   234),  UINT8_C(   177)  },
      {  UINT8_C(    41),  UINT8_C(    89),  UINT8_C(   182),  UINT8_C(   231),  UINT8_C(   117),  UINT8_C(    92),  UINT8_C(   234),  UINT8_C(   177)  },
      {  UINT8_C(    78),  UINT8_C(   207),  UINT8_C(   183),  UINT8_C(    60),  UINT8_C(   171),  UINT8_C(   229),  UINT8_C(    86),  UINT8_C(   141)  },
      {  UINT8_C(    38),  UINT8_C(    39),  UINT8_C(   199),  UINT8_C(   244),  UINT8_C(   179),  UINT8_C(   141),  UINT8_C(    70),  UINT8_C(    37)  },
      {  UINT8_C(   230),  UINT8_C(   231),  UINT8_C(     7),  UINT8_C(   148),  UINT8_C(   243),  UINT8_C(    77),  UINT8_C(    70),  UINT8_C(   133)  } },
    { {  UINT8_C(    51),  UINT8_C(    28),  UINT8_C(    95),  UINT8_C(    70),  UINT8_C(    30),  UINT8_C(   241),  UINT8_C(     5),  UINT8_C(   134)  },
      {  UINT8_C(    85),  UINT8_C(   174),  UINT8_C(   194),  UINT8_C(   192),  UINT8_C(   222),  UINT8_C(   190),  UINT8_C(   203),  UINT8_C(    97)  },
      {  UINT8_C(    85),  UINT8_C(   174),  UINT8_C(   194),  UINT8_C(   192),  UINT8_C(   222),  UINT8_C(   190),  UINT8_C(   203),  UINT8_C(    97)  },
      {  UINT8_C(   171),  UINT8_C(   116),  UINT8_C(    23),  UINT8_C(     6),  UINT8_C(   246),  UINT8_C(   241),  UINT8_C(    93),  UINT8_C(    14)  },
      {  UINT8_C(   179),  UINT8_C(   220),  UINT8_C(    95),  UINT8_C(     6),  UINT8_C(   222),  UINT8_C(   209),  UINT8_C(   101),  UINT8_C(    38)  },
      {  UINT8_C(   179),  UINT8_C(    28),  UINT8_C(    95),  UINT8_C(    70),  UINT8_C(    30),  UINT8_C(   113),  UINT8_C(   133),  UINT8_C(   134)  } },
    { {  UINT8_C(   167),  UINT8_C(   158),  UINT8_C(   137),  UINT8_C(    37),  UINT8_C(   155),  UINT8_C(   179),  UINT8_C(   172),  UINT8_C(   255)  },
      {  UINT8_C(    33),  UINT8_C(   236),  UINT8_C(   241),  UINT8_C(   226),  UINT8_C(   155),  UINT8_C(   240),  UINT8_C(    33),  UINT8_C(    64)  },
      {  UINT8_C(    33),  UINT8_C(   236),  UINT8_C(   241),  UINT8_C(   226),  UINT8_C(   155),  UINT8_C(   240),  UINT8_C(    33),  UINT8_C(    64)  },
      {  UINT8_C(    15),  UINT8_C(   102),  UINT8_C(   137),  UINT8_C(    21),  UINT8_C(   219),  UINT8_C(   131),  UINT8_C(    12),  UINT8_C(     7)  },
      {  UINT8_C(    39),  UINT8_C(   158),  UINT8_C(    41),  UINT8_C(    69),  UINT8_C(   123),  UINT8_C(    19),  UINT8_C(    44),  UINT8_C(    31)  },
      {  UINT8_C(   167),  UINT8_C(    30),  UINT8_C(   137),  UINT8_C(    37),  UINT8_C(   155),  UINT8_C(    51),  UINT8_C(   172),  UINT8_C(   127)  } },
    { {  UINT8_C(     5),  UINT8_C(    77),  UINT8_C(    86),  UINT8_C(   188),  UINT8_C(    22),  UINT8_C(   139),  UINT8_C(   165),  UINT8_C(    74)  },
      {  UINT8_C(    27),  UINT8_C(   100),  UINT8_C(    63),  UINT8_C(   133),  UINT8_C(   173),  UINT8_C(   182),  UINT8_C(    69),  UINT8_C(   152)  },
      {  UINT8_C(    27),  UINT8_C(   100),  UINT8_C(    63),  UINT8_C(   133),  UINT8_C(   173),  UINT8_C(   182),  UINT8_C(    69),  UINT8_C(   152)  },
      {  UINT8_C(   221),  UINT8_C(    37),  UINT8_C(   254),  UINT8_C(    44),  UINT8_C(   110),  UINT8_C(   179),  UINT8_C(    45),  UINT8_C(   194)  },
      {  UINT8_C(   101),  UINT8_C(   141),  UINT8_C(   246),  UINT8_C(   188),  UINT8_C(   182),  UINT8_C(   203),  UINT8_C(   165),  UINT8_C(    10)  },
      {  UINT8_C(   133),  UINT8_C(    77),  UINT8_C(   214),  UINT8_C(   188),  UINT8_C(   150),  UINT8_C(    11),  UINT8_C(   165),  UINT8_C(    74)  } },
    { {  UINT8_C(   250),  UINT8_C(   205),  UINT8_C(   140),  UINT8_C(   192),  UINT8_C(    13),  UINT8_C(    95),  UINT8_C(    19),  UINT8_C(    34)  },
      {  UINT8_C(   170),  UINT8_C(    18),  UINT8_C(   194),  UINT8_C(   134),  UINT8_C(   116),  UINT8_C(   119),  UINT8_C(   217),  UINT8_C(     7)  },
      {  UINT8_C(   170),  UINT8_C(    18),  UINT8_C(   194),  UINT8_C(   134),  UINT8_C(   116),  UINT8_C(   119),  UINT8_C(   217),  UINT8_C(     7)  },
      {  UINT8_C(    82),  UINT8_C(   149),  UINT8_C(    20),  UINT8_C(    48),  UINT8_C(   165),  UINT8_C(   191),  UINT8_C(   203),  UINT8_C(    58)  },
      {  UINT8_C(    90),  UINT8_C(    77),  UINT8_C(    76),  UINT8_C(   192),  UINT8_C(   141),        UINT8_MAX,  UINT8_C(    51),  UINT8_C(   226)  },
      {  UINT8_C(   122),  UINT8_C(    77),  UINT8_C(    12),  UINT8_C(    64),  UINT8_C(    13),  UINT8_C(   223),  UINT8_C(   147),  UINT8_C(   162)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);

    simde_uint8x8_t r0 = simde_vsli_n_u8(a, b, 0);
    simde_uint8x8_t r3 = simde_vsli_n_u8(a, b, 3);
    simde_uint8x8_t r5 = simde_vsli_n_u8(a, b, 5);
    simde_uint8x8_t r7 = simde_vsli_n_u8(a, b, 7);

    simde_test_arm_neon_assert_equal_u8x8(r0, simde_vld1_u8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r7, simde_vld1_u8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r0 = simde_vsli_n_u8(a, b, 0);
    simde_uint8x8_t r3 = simde_vsli_n_u8(a, b, 3);
    simde_uint8x8_t r5 = simde_vsli_n_u8(a, b, 5);
    simde_uint8x8_t r7 = simde_vsli_n_u8(a, b, 7);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r15[4];
  } test_vec[] = {
    { {  UINT16_C(  15391),  UINT16_C(   8013),  UINT16_C(   1254),  UINT16_C(  45654)  },
      {  UINT16_C(  35066),  UINT16_C(  48548),  UINT16_C(  14346),  UINT16_C(   1393)  },
      {  UINT16_C(  18391),  UINT16_C(  60709),  UINT16_C(  49238),  UINT16_C(  11150)  },
      {  UINT16_C(  16031),  UINT16_C(  26893),  UINT16_C(    678),  UINT16_C(  23638)  },
      {  UINT16_C(  59423),  UINT16_C(  37709),  UINT16_C(  10470),  UINT16_C(  50774)  },
      {  UINT16_C(  23583),  UINT16_C(  40781),  UINT16_C(  17638),  UINT16_C(  12886)  },
      {  UINT16_C(  15391),  UINT16_C(   8013),  UINT16_C(   1254),  UINT16_C(  45654)  } },
    { {  UINT16_C(  23736),  UINT16_C(   7291),  UINT16_C(  61578),  UINT16_C(   8940)  },
      {  UINT16_C(  15242),  UINT16_C(  20311),  UINT16_C(  19232),  UINT16_C(   4411)  },
      {  UINT16_C(  56400),  UINT16_C(  31419),  UINT16_C(  22786),  UINT16_C(  35292)  },
      {  UINT16_C(  58040),  UINT16_C(  54779),  UINT16_C(  51210),  UINT16_C(  20204)  },
      {  UINT16_C(  10424),  UINT16_C(  23675),  UINT16_C(  32906),  UINT16_C(  61164)  },
      {  UINT16_C(  23736),  UINT16_C(  64635),  UINT16_C(   4234),  UINT16_C(  25324)  },
      {  UINT16_C(  23736),  UINT16_C(  40059),  UINT16_C(  28810),  UINT16_C(  41708)  } },
    { {  UINT16_C(  47025),  UINT16_C(  52193),  UINT16_C(  31710),  UINT16_C(  14843)  },
      {  UINT16_C(  54022),  UINT16_C(  30364),  UINT16_C(  65371),  UINT16_C(  28567)  },
      {  UINT16_C(  38961),  UINT16_C(  46305),  UINT16_C(  64222),  UINT16_C(  31931)  },
      {  UINT16_C(  49585),  UINT16_C(  42785),  UINT16_C(  55006),  UINT16_C(  58875)  },
      {  UINT16_C(   7089),  UINT16_C(  29665),  UINT16_C(  28638),  UINT16_C(  24059)  },
      {  UINT16_C(  55217),  UINT16_C(  35809),  UINT16_C(  31710),  UINT16_C(  63995)  },
      {  UINT16_C(  14257),  UINT16_C(  19425),  UINT16_C(  64478),  UINT16_C(  47611)  } },
    { {  UINT16_C(  54568),  UINT16_C(  15862),  UINT16_C(  52509),  UINT16_C(  47425)  },
      {  UINT16_C(   1779),  UINT16_C(  31523),  UINT16_C(  16426),  UINT16_C(  60116)  },
      {  UINT16_C(  14232),  UINT16_C(  55582),  UINT16_C(    341),  UINT16_C(  22177)  },
      {  UINT16_C(  48360),  UINT16_C(  51446),  UINT16_C(   2717),  UINT16_C(  46337)  },
      {  UINT16_C(  52520),  UINT16_C(  36342),  UINT16_C(  43293),  UINT16_C(  20801)  },
      {  UINT16_C(  29992),  UINT16_C(  32246),  UINT16_C(  19741),  UINT16_C(  39233)  },
      {  UINT16_C(  54568),  UINT16_C(  48630),  UINT16_C(  19741),  UINT16_C(  14657)  } },
    { {  UINT16_C(  19021),  UINT16_C(   2955),  UINT16_C(  23434),  UINT16_C(  24652)  },
      {  UINT16_C(  64304),  UINT16_C(  33123),  UINT16_C(  28656),  UINT16_C(   7738)  },
      {  UINT16_C(  55685),  UINT16_C(   2843),  UINT16_C(  32642),  UINT16_C(  61908)  },
      {  UINT16_C(  52237),  UINT16_C(  22731),  UINT16_C(  64522),  UINT16_C(  36492)  },
      {  UINT16_C(  49741),  UINT16_C(  36747),  UINT16_C(  50058),  UINT16_C(  59468)  },
      {  UINT16_C(   2637),  UINT16_C(  27531),  UINT16_C(   7050),  UINT16_C(  16460)  },
      {  UINT16_C(  19021),  UINT16_C(  35723),  UINT16_C(  23434),  UINT16_C(  24652)  } },
    { {  UINT16_C(  35638),  UINT16_C(  64110),  UINT16_C(  55906),  UINT16_C(  20848)  },
      {  UINT16_C(  27670),  UINT16_C(  29508),  UINT16_C(  17746),  UINT16_C(  25076)  },
      {  UINT16_C(  24758),  UINT16_C(  39462),  UINT16_C(  10898),  UINT16_C(   4000)  },
      {  UINT16_C(   1462),  UINT16_C(  53550),  UINT16_C(  21666),  UINT16_C(  32048)  },
      {  UINT16_C(  23350),  UINT16_C(   4718),  UINT16_C(  19042),  UINT16_C(  53616)  },
      {  UINT16_C(  52022),  UINT16_C(  39534),  UINT16_C(  23138),  UINT16_C(  37232)  },
      {  UINT16_C(   2870),  UINT16_C(  31342),  UINT16_C(  23138),  UINT16_C(  20848)  } },
    { {  UINT16_C(  23800),  UINT16_C(  37832),  UINT16_C(  34512),  UINT16_C(  33446)  },
      {  UINT16_C(  19904),  UINT16_C(  51885),  UINT16_C(  10602),  UINT16_C(  42147)  },
      {  UINT16_C(  28160),  UINT16_C(  21864),  UINT16_C(  19280),  UINT16_C(   9502)  },
      {  UINT16_C(  28728),  UINT16_C(  43848),  UINT16_C(  23184),  UINT16_C(  10470)  },
      {  UINT16_C(    248),  UINT16_C(  47048),  UINT16_C(  43728),  UINT16_C(  36518)  },
      {  UINT16_C(   7416),  UINT16_C(  46024),  UINT16_C(  18128),  UINT16_C(  25254)  },
      {  UINT16_C(  23800),  UINT16_C(  37832),  UINT16_C(   1744),  UINT16_C(  33446)  } },
    { {  UINT16_C(  32311),  UINT16_C(  55845),  UINT16_C(  55299),  UINT16_C(  15525)  },
      {  UINT16_C(  16152),  UINT16_C(  36439),  UINT16_C(  64155),  UINT16_C(  41506)  },
      {  UINT16_C(  63687),  UINT16_C(  29373),  UINT16_C(  54491),  UINT16_C(   4373)  },
      {  UINT16_C(  50743),  UINT16_C(  38373),  UINT16_C(  42691),  UINT16_C(  34981)  },
      {  UINT16_C(  25143),  UINT16_C(  24101),  UINT16_C(  27651),  UINT16_C(  34981)  },
      {  UINT16_C(   7735),  UINT16_C(  64037),  UINT16_C(  30723),  UINT16_C(  23717)  },
      {  UINT16_C(  32311),  UINT16_C(  55845),  UINT16_C(  55299),  UINT16_C(  15525)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);

    simde_uint16x4_t r3 = simde_vsli_n_u16(a, b, 3);
    simde_uint16x4_t r6 = simde_vsli_n_u16(a, b, 6);
    simde_uint16x4_t r10 = simde_vsli_n_u16(a, b, 10);
    simde_uint16x4_t r13 = simde_vsli_n_u16(a, b, 13);
    simde_uint16x4_t r15 = simde_vsli_n_u16(a, b, 15);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r15, simde_vld1_u16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r3 = simde_vsli_n_u16(a, b, 3);
    simde_uint16x4_t r6 = simde_vsli_n_u16(a, b, 6);
    simde_uint16x4_t r10 = simde_vsli_n_u16(a, b, 10);
    simde_uint16x4_t r13 = simde_vsli_n_u16(a, b, 13);
    simde_uint16x4_t r15 = simde_vsli_n_u16(a, b, 15);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r31[2];
  } test_vec[] = {
    { {  UINT32_C(3081230558),  UINT32_C(1323792986)  },
      {  UINT32_C(1071965024),  UINT32_C(2237917539)  },
      {  UINT32_C(4181252126),  UINT32_C(1492801754)  },
      {  UINT32_C(2624329950),  UINT32_C(2100066906)  },
      {  UINT32_C( 453499102),  UINT32_C(1260354138)  },
      {  UINT32_C(2208815326),  UINT32_C(2397534810)  },
      {  UINT32_C( 933746910),  UINT32_C(3471276634)  } },
    { {  UINT32_C(1801753472),  UINT32_C(3276321139)  },
      {  UINT32_C(3767665232),  UINT32_C(1682889056)  },
      {  UINT32_C( 612406272),  UINT32_C( 330717235)  },
      {  UINT32_C(1078596480),  UINT32_C(3677098355)  },
      {  UINT32_C( 310678400),  UINT32_C(3405820275)  },
      {  UINT32_C(1130664832),  UINT32_C(2202579315)  },
      {  UINT32_C(1801753472),  UINT32_C(1128837491)  } },
    { {  UINT32_C(1903242450),  UINT32_C( 544175578)  },
      {  UINT32_C(1301025297),  UINT32_C(2094177212)  },
      {  UINT32_C(1661240402),  UINT32_C( 883355418)  },
      {  UINT32_C(2185374930),  UINT32_C(1400346074)  },
      {  UINT32_C(2424909010),  UINT32_C(3722933722)  },
      {  UINT32_C(1165044946),  UINT32_C(4033836506)  },
      {  UINT32_C(4050726098),  UINT32_C( 544175578)  } },
    { {  UINT32_C(2126941907),  UINT32_C( 977695758)  },
      {  UINT32_C(1486134999),  UINT32_C(1742360137)  },
      {  UINT32_C( 623359443),  UINT32_C(4136866382)  },
      {  UINT32_C(2480598739),  UINT32_C(1237922830)  },
      {  UINT32_C(4139683539),  UINT32_C(1917744142)  },
      {  UINT32_C(1590070995),  UINT32_C( 642151438)  },
      {  UINT32_C(4274425555),  UINT32_C(3125179406)  } },
    { {  UINT32_C(2706916007),  UINT32_C(1068692422)  },
      {  UINT32_C( 545324817),  UINT32_C(1867710312)  },
      {  UINT32_C( 541049959),  UINT32_C(3569342982)  },
      {  UINT32_C( 534913703),  UINT32_C(1609372614)  },
      {  UINT32_C(4169679527),  UINT32_C(4215468998)  },
      {  UINT32_C(1163412135),  UINT32_C(2746414022)  },
      {  UINT32_C(2706916007),  UINT32_C(1068692422)  } },
    { {  UINT32_C(4153598072),  UINT32_C(1583301308)  },
      {  UINT32_C(1843033608),  UINT32_C(3432411003)  },
      {  UINT32_C(1990033976),  UINT32_C( 630972156)  },
      {  UINT32_C(1321271416),  UINT32_C(3455017660)  },
      {  UINT32_C(2957172856),  UINT32_C(2078229180)  },
      {  UINT32_C( 596828280),  UINT32_C(3999220412)  },
      {  UINT32_C(2006114424),  UINT32_C(3730784956)  } },
    { {  UINT32_C( 503922803),  UINT32_C( 102391840)  },
      {  UINT32_C(1659267842),  UINT32_C(3517337088)  },
      {  UINT32_C(3113926835),  UINT32_C(1771274272)  },
      {  UINT32_C(3445637235),  UINT32_C(3384803360)  },
      {  UINT32_C(1477525619),  UINT32_C(1879203872)  },
      {  UINT32_C( 168378483),  UINT32_C(  35282976)  },
      {  UINT32_C( 503922803),  UINT32_C( 102391840)  } },
    { {  UINT32_C( 135317347),  UINT32_C(3314568864)  },
      {  UINT32_C( 923437489),  UINT32_C( 213085622)  },
      {  UINT32_C(3265424483),  UINT32_C( 752577952)  },
      {  UINT32_C(1362503523),  UINT32_C(1840696992)  },
      {  UINT32_C(1300809571),  UINT32_C(1840271008)  },
      {  UINT32_C(3289433955),  UINT32_C(3650113184)  },
      {  UINT32_C(2282800995),  UINT32_C(1167085216)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);

    simde_uint32x2_t r6 = simde_vsli_n_u32(a, b, 6);
    simde_uint32x2_t r13 = simde_vsli_n_u32(a, b, 13);
    simde_uint32x2_t r19 = simde_vsli_n_u32(a, b, 19);
    simde_uint32x2_t r26 = simde_vsli_n_u32(a, b, 26);
    simde_uint32x2_t r31 = simde_vsli_n_u32(a, b, 31);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r31, simde_vld1_u32(test_vec[i].r31));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r6 = simde_vsli_n_u32(a, b, 6);
    simde_uint32x2_t r13 = simde_vsli_n_u32(a, b, 13);
    simde_uint32x2_t r19 = simde_vsli_n_u32(a, b, 19);
    simde_uint32x2_t r26 = simde_vsli_n_u32(a, b, 26);
    simde_uint32x2_t r31 = simde_vsli_n_u32(a, b, 31);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r13[1];
    uint64_t r26[1];
    uint64_t r39[1];
    uint64_t r52[1];
    uint64_t r63[1];
  } test_vec[] = {
    { {  UINT64_C( 2367438358383478378)  },
      {  UINT64_C(10151069329549398822)  },
      {  UINT64_C(18084407459726018154)  },
      {  UINT64_C( 1664254114169931370)  },
      {  UINT64_C( 1425832543274714730)  },
      {  UINT64_C( 3632949853674587754)  },
      {  UINT64_C( 2367438358383478378)  } },
    { {  UINT64_C( 4289360236958653475)  },
      {  UINT64_C( 9003445777938185491)  },
      {  UINT64_C( 6145006178828188707)  },
      {  UINT64_C(17172783880833014819)  },
      {  UINT64_C( 4575245904564132899)  },
      {  UINT64_C(15075481344510991395)  },
      {  UINT64_C(13512732273813429283)  } },
    { {  UINT64_C( 4661840731346591672)  },
      {  UINT64_C(16008367045675390461)  },
      {  UINT64_C( 2639218171596226488)  },
      {  UINT64_C(  891207328682762168)  },
      {  UINT64_C(14306527482023272376)  },
      {  UINT64_C( 6904633345777098680)  },
      {  UINT64_C(13885212768201367480)  } },
    { {  UINT64_C(  560855986095228110)  },
      {  UINT64_C(12519105941898633195)  },
      {  UINT64_C(11065570282205701326)  },
      {  UINT64_C( 1851373620381320398)  },
      {  UINT64_C( 3229069440521569486)  },
      {  UINT64_C(18354578113836057806)  },
      {  UINT64_C( 9784228022950003918)  } },
    { {  UINT64_C(15210706800944352878)  },
      {  UINT64_C( 2343987333079752503)  },
      {  UINT64_C(17330395931398827630)  },
      {  UINT64_C( 4461078750471655022)  },
      {  UINT64_C( 2157113990720261742)  },
      {  UINT64_C(17543571407922269806)  },
      {  UINT64_C(15210706800944352878)  } },
    { {  UINT64_C( 3102245097986106578)  },
      {  UINT64_C(11620068368410445742)  },
      {  UINT64_C( 6400653677085181138)  },
      {  UINT64_C( 8508265199309464786)  },
      {  UINT64_C( 7909402293599511762)  },
      {  UINT64_C( 8857845421765600466)  },
      {  UINT64_C( 3102245097986106578)  } },
    { {  UINT64_C(17038098246975051983)  },
      {  UINT64_C(18292780545233057134)  },
      {  UINT64_C(11556115806516271311)  },
      {  UINT64_C(17456844777586120911)  },
      {  UINT64_C( 7312358247877793999)  },
      {  UINT64_C( 6260984338677455055)  },
      {  UINT64_C( 7814726210120276175)  } },
    { {  UINT64_C( 1351949120307680797)  },
      {  UINT64_C(15139404553755458091)  },
      {  UINT64_C( 4541696815397172765)  },
      {  UINT64_C(16944259135176136221)  },
      {  UINT64_C(14068424518630069789)  },
      {  UINT64_C(11723739062141933085)  },
      {  UINT64_C(10575321157162456605)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);

    simde_uint64x1_t r13 = simde_vsli_n_u64(a, b, 13);
    simde_uint64x1_t r26 = simde_vsli_n_u64(a, b, 26);
    simde_uint64x1_t r39 = simde_vsli_n_u64(a, b, 39);
    simde_uint64x1_t r52 = simde_vsli_n_u64(a, b, 52);
    simde_uint64x1_t r63 = simde_vsli_n_u64(a, b, 63);

    simde_test_arm_neon_assert_equal_u64x1(r13, simde_vld1_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x1(r26, simde_vld1_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x1(r39, simde_vld1_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x1(r52, simde_vld1_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x1(r63, simde_vld1_u64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r13 = simde_vsli_n_u64(a, b, 13);
    simde_uint64x1_t r26 = simde_vsli_n_u64(a, b, 26);
    simde_uint64x1_t r39 = simde_vsli_n_u64(a, b, 39);
    simde_uint64x1_t r52 = simde_vsli_n_u64(a, b, 52);
    simde_uint64x1_t r63 = simde_vsli_n_u64(a, b, 63);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r0[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r7[16];
  } test_vec[] = {
    { {  INT8_C( 107),  INT8_C( 125), -INT8_C(  74),  INT8_C(  13), -INT8_C(  11),  INT8_C(  64),  INT8_C( 106), -INT8_C(  95), -INT8_C(   9), -INT8_C(  95),  INT8_C(  80),  INT8_C(  86),  INT8_C(  70),  INT8_C(  72),  INT8_C(  12),  INT8_C(  60)  },
      {  INT8_C(  59), -INT8_C(   7), -INT8_C( 115), -INT8_C(  18), -INT8_C( 104),  INT8_C( 105),  INT8_C(  23), -INT8_C(  72),  INT8_C(  48),  INT8_C(  16), -INT8_C(  56),  INT8_C(  12),  INT8_C( 111),  INT8_C(  13), -INT8_C( 111),  INT8_C(  21)  },
      {  INT8_C(  59), -INT8_C(   7), -INT8_C( 115), -INT8_C(  18), -INT8_C( 104),  INT8_C( 105),  INT8_C(  23), -INT8_C(  72),  INT8_C(  48),  INT8_C(  16), -INT8_C(  56),  INT8_C(  12),  INT8_C( 111),  INT8_C(  13), -INT8_C( 111),  INT8_C(  21)  },
      { -INT8_C(  37), -INT8_C(  51),  INT8_C( 110),  INT8_C( 117), -INT8_C(  59),  INT8_C(  72), -INT8_C(  70), -INT8_C(  63), -INT8_C( 121), -INT8_C( 127),  INT8_C(  64),  INT8_C( 102),  INT8_C( 126),  INT8_C( 104), -INT8_C( 116), -INT8_C(  84)  },
      {  INT8_C( 107),  INT8_C(  61), -INT8_C(  74), -INT8_C(  51),  INT8_C(  21),  INT8_C(  32), -INT8_C(  22),  INT8_C(   1),  INT8_C(  23),  INT8_C(   1),  INT8_C(  16), -INT8_C( 106), -INT8_C(  26), -INT8_C(  88),  INT8_C(  44), -INT8_C(  68)  },
      { -INT8_C(  21), -INT8_C(   3), -INT8_C(  74),  INT8_C(  13),  INT8_C( 117), -INT8_C(  64), -INT8_C(  22),  INT8_C(  33),  INT8_C( 119),  INT8_C(  33),  INT8_C(  80),  INT8_C(  86), -INT8_C(  58), -INT8_C(  56), -INT8_C( 116), -INT8_C(  68)  } },
    { { -INT8_C(  83),  INT8_C(  48), -INT8_C(  92),  INT8_C(  37), -INT8_C(  62), -INT8_C(  48),  INT8_C( 120), -INT8_C(  43), -INT8_C(  96),  INT8_C( 105),  INT8_C( 127),  INT8_C(  63),  INT8_C( 110),  INT8_C( 120),  INT8_C(  10), -INT8_C(  86)  },
      {  INT8_C(  27), -INT8_C(  20), -INT8_C(  50), -INT8_C(  62),  INT8_C(   1),  INT8_C( 119),  INT8_C(  75), -INT8_C(  28),  INT8_C(  42),  INT8_C(  27),  INT8_C( 107),  INT8_C(   0), -INT8_C( 101),  INT8_C(  64),  INT8_C( 104), -INT8_C(  83)  },
      {  INT8_C(  27), -INT8_C(  20), -INT8_C(  50), -INT8_C(  62),  INT8_C(   1),  INT8_C( 119),  INT8_C(  75), -INT8_C(  28),  INT8_C(  42),  INT8_C(  27),  INT8_C( 107),  INT8_C(   0), -INT8_C( 101),  INT8_C(  64),  INT8_C( 104), -INT8_C(  83)  },
      { -INT8_C(  35),  INT8_C(  96),  INT8_C( 116),  INT8_C(  21),  INT8_C(  10), -INT8_C(  72),  INT8_C(  88),  INT8_C(  37),  INT8_C(  80), -INT8_C(  39),  INT8_C(  95),  INT8_C(   7), -INT8_C(  34),  INT8_C(   0),  INT8_C(  66),  INT8_C( 106)  },
      {  INT8_C( 109), -INT8_C( 112), -INT8_C(  60),  INT8_C(  69),  INT8_C(  34), -INT8_C(  16),  INT8_C( 120), -INT8_C( 107),  INT8_C(  64),  INT8_C( 105),       INT8_MAX,  INT8_C(  31),  INT8_C( 110),  INT8_C(  24),  INT8_C(  10), -INT8_C(  86)  },
      { -INT8_C(  83),  INT8_C(  48),  INT8_C(  36),  INT8_C(  37), -INT8_C(  62), -INT8_C(  48), -INT8_C(   8),  INT8_C(  85),  INT8_C(  32), -INT8_C(  23), -INT8_C(   1),  INT8_C(  63), -INT8_C(  18),  INT8_C( 120),  INT8_C(  10), -INT8_C(  86)  } },
    { { -INT8_C(  19), -INT8_C(  90),  INT8_C(  10), -INT8_C( 113), -INT8_C( 120), -INT8_C(  94),  INT8_C(  87),  INT8_C( 114), -INT8_C(  45), -INT8_C(  75),  INT8_C( 120), -INT8_C(  16),  INT8_C(  46),  INT8_C( 102), -INT8_C( 116), -INT8_C(  68)  },
      {  INT8_C(  92), -INT8_C(  76),  INT8_C(  70), -INT8_C(  37),  INT8_C( 123),  INT8_C(  52), -INT8_C(  87),  INT8_C(  95), -INT8_C(  94),  INT8_C(  15),  INT8_C(   0),  INT8_C(   4),  INT8_C( 101),  INT8_C(  63), -INT8_C(  71), -INT8_C(  97)  },
      {  INT8_C(  92), -INT8_C(  76),  INT8_C(  70), -INT8_C(  37),  INT8_C( 123),  INT8_C(  52), -INT8_C(  87),  INT8_C(  95), -INT8_C(  94),  INT8_C(  15),  INT8_C(   0),  INT8_C(   4),  INT8_C( 101),  INT8_C(  63), -INT8_C(  71), -INT8_C(  97)  },
      { -INT8_C(  27), -INT8_C(  90),  INT8_C(  50), -INT8_C(  33), -INT8_C(  40), -INT8_C(  94),  INT8_C(  79), -INT8_C(   6),  INT8_C(  19),  INT8_C( 125),  INT8_C(   0),  INT8_C(  32),  INT8_C(  46), -INT8_C(   2), -INT8_C(  52), -INT8_C(   4)  },
      { -INT8_C( 115), -INT8_C( 122), -INT8_C(  54),  INT8_C( 111),  INT8_C( 104), -INT8_C( 126),  INT8_C(  55), -INT8_C(  14),  INT8_C(  83), -INT8_C(  11),  INT8_C(  24), -INT8_C( 112), -INT8_C(  82), -INT8_C(  26),  INT8_C(  44), -INT8_C(   4)  },
      {  INT8_C( 109),  INT8_C(  38),  INT8_C(  10), -INT8_C( 113), -INT8_C( 120),  INT8_C(  34), -INT8_C(  41), -INT8_C(  14),  INT8_C(  83), -INT8_C(  75),  INT8_C( 120),  INT8_C( 112), -INT8_C(  82), -INT8_C(  26), -INT8_C( 116), -INT8_C(  68)  } },
    { { -INT8_C(  15),  INT8_C(  19),  INT8_C(  64), -INT8_C( 114),  INT8_C(  42), -INT8_C( 125),  INT8_C(  89), -INT8_C(  12), -INT8_C(   7), -INT8_C(  83),  INT8_C(  70), -INT8_C( 105),  INT8_C(  44), -INT8_C(  31),  INT8_C( 103),  INT8_C(  51)  },
      {  INT8_C(  67),  INT8_C(   4), -INT8_C(  27), -INT8_C(  70),  INT8_C(  87),  INT8_C(  38), -INT8_C(  25), -INT8_C(  12),  INT8_C(  35), -INT8_C(  20),  INT8_C( 122),  INT8_C(  53),  INT8_C(  17),  INT8_C(  11), -INT8_C(  80), -INT8_C(  18)  },
      {  INT8_C(  67),  INT8_C(   4), -INT8_C(  27), -INT8_C(  70),  INT8_C(  87),  INT8_C(  38), -INT8_C(  25), -INT8_C(  12),  INT8_C(  35), -INT8_C(  20),  INT8_C( 122),  INT8_C(  53),  INT8_C(  17),  INT8_C(  11), -INT8_C(  80), -INT8_C(  18)  },
      {  INT8_C(  25),  INT8_C(  35),  INT8_C(  40), -INT8_C(  42), -INT8_C(  70),  INT8_C(  51),  INT8_C(  57), -INT8_C(  92),  INT8_C(  25),  INT8_C( 101), -INT8_C(  42), -INT8_C(  81), -INT8_C( 116),  INT8_C(  89), -INT8_C( 121),  INT8_C( 115)  },
      {  INT8_C( 113), -INT8_C( 109), -INT8_C(  96),  INT8_C(  78), -INT8_C(  22), -INT8_C(  61), -INT8_C(   7), -INT8_C( 108),  INT8_C( 121), -INT8_C( 115),  INT8_C(  70), -INT8_C(  73),  INT8_C(  44),  INT8_C(  97),  INT8_C(   7), -INT8_C(  45)  },
      { -INT8_C(  15),  INT8_C(  19), -INT8_C(  64),  INT8_C(  14), -INT8_C(  86),  INT8_C(   3), -INT8_C(  39),  INT8_C( 116), -INT8_C(   7),  INT8_C(  45),  INT8_C(  70), -INT8_C( 105), -INT8_C(  84), -INT8_C(  31),  INT8_C( 103),  INT8_C(  51)  } },
    { { -INT8_C( 117),  INT8_C(  28),  INT8_C(  31),  INT8_C(  18),  INT8_C(  49),  INT8_C(  30),  INT8_C( 101), -INT8_C(  25), -INT8_C(  21),  INT8_C(  14),  INT8_C(   3), -INT8_C(  42), -INT8_C(   6),  INT8_C( 126), -INT8_C(  36), -INT8_C(  27)  },
      {  INT8_C( 105),  INT8_C(   0), -INT8_C(  61), -INT8_C(  49),  INT8_C(  81),  INT8_C(  27), -INT8_C(  36),  INT8_C(  79),  INT8_C(  94),  INT8_C(  43), -INT8_C(  22),  INT8_C(  34),  INT8_C(  55),  INT8_C(  20), -INT8_C(   6),  INT8_C(  19)  },
      {  INT8_C( 105),  INT8_C(   0), -INT8_C(  61), -INT8_C(  49),  INT8_C(  81),  INT8_C(  27), -INT8_C(  36),  INT8_C(  79),  INT8_C(  94),  INT8_C(  43), -INT8_C(  22),  INT8_C(  34),  INT8_C(  55),  INT8_C(  20), -INT8_C(   6),  INT8_C(  19)  },
      {  INT8_C(  75),  INT8_C(   4),  INT8_C(  31),  INT8_C( 122), -INT8_C( 119), -INT8_C(  34), -INT8_C(  27),       INT8_MAX, -INT8_C(  13),  INT8_C(  94),  INT8_C(  83),  INT8_C(  22), -INT8_C(  70), -INT8_C(  90), -INT8_C(  44), -INT8_C(  99)  },
      {  INT8_C(  43),  INT8_C(  28),       INT8_MAX, -INT8_C(  14),  INT8_C(  49),  INT8_C( 126), -INT8_C( 123), -INT8_C(  25), -INT8_C(  53),  INT8_C( 110),  INT8_C(  67),  INT8_C(  86), -INT8_C(   6), -INT8_C(  98),  INT8_C(  92),  INT8_C( 101)  },
      { -INT8_C( 117),  INT8_C(  28), -INT8_C(  97), -INT8_C( 110), -INT8_C(  79), -INT8_C(  98),  INT8_C( 101), -INT8_C(  25),  INT8_C( 107), -INT8_C( 114),  INT8_C(   3),  INT8_C(  86), -INT8_C(   6),  INT8_C( 126),  INT8_C(  92), -INT8_C(  27)  } },
    { {  INT8_C(  32),  INT8_C(   1), -INT8_C(  82),  INT8_C(   9), -INT8_C(  16),  INT8_C( 104),  INT8_C(  15), -INT8_C( 123), -INT8_C( 124), -INT8_C( 120),  INT8_C(  24),  INT8_C(   2),  INT8_C(  70),  INT8_C( 107), -INT8_C(  20), -INT8_C(  87)  },
      { -INT8_C(  91), -INT8_C(   3),  INT8_C(  66), -INT8_C(  82), -INT8_C(  60), -INT8_C(  88),  INT8_C( 118),  INT8_C(  92),  INT8_C(  44), -INT8_C( 110), -INT8_C(  62),  INT8_C(   8),  INT8_C(  15),  INT8_C(  24),  INT8_C(  15),  INT8_C(  22)  },
      { -INT8_C(  91), -INT8_C(   3),  INT8_C(  66), -INT8_C(  82), -INT8_C(  60), -INT8_C(  88),  INT8_C( 118),  INT8_C(  92),  INT8_C(  44), -INT8_C( 110), -INT8_C(  62),  INT8_C(   8),  INT8_C(  15),  INT8_C(  24),  INT8_C(  15),  INT8_C(  22)  },
      {  INT8_C(  40), -INT8_C(  23),  INT8_C(  22),  INT8_C( 113),  INT8_C(  32),  INT8_C(  64), -INT8_C(  73), -INT8_C(  27),  INT8_C( 100), -INT8_C( 112),  INT8_C(  16),  INT8_C(  66),  INT8_C( 126), -INT8_C(  61),  INT8_C( 124), -INT8_C(  79)  },
      { -INT8_C(  96), -INT8_C(  95),  INT8_C(  78), -INT8_C(  55), -INT8_C( 112),  INT8_C(   8), -INT8_C(  49), -INT8_C( 123), -INT8_C( 124),  INT8_C(  72),  INT8_C(  88),  INT8_C(   2), -INT8_C(  26),  INT8_C(  11), -INT8_C(  20), -INT8_C(  55)  },
      { -INT8_C(  96), -INT8_C( 127),  INT8_C(  46),  INT8_C(   9),  INT8_C( 112),  INT8_C( 104),  INT8_C(  15),  INT8_C(   5),  INT8_C(   4),  INT8_C(   8),  INT8_C(  24),  INT8_C(   2), -INT8_C(  58),  INT8_C( 107), -INT8_C(  20),  INT8_C(  41)  } },
    { {  INT8_C( 116),  INT8_C(  19),  INT8_C(  48),  INT8_C(  76), -INT8_C(  11), -INT8_C(  16),  INT8_C(  66),  INT8_C(  14), -INT8_C(  56), -INT8_C(  32),  INT8_C(  85), -INT8_C(  52),  INT8_C(  90),  INT8_C( 115), -INT8_C(  81), -INT8_C( 128)  },
      {  INT8_C(  38), -INT8_C( 126), -INT8_C(  53),  INT8_C( 117),  INT8_C(  74), -INT8_C(  43),  INT8_C(  93),  INT8_C(  63),  INT8_C(  26),  INT8_C(   0),  INT8_C(  22), -INT8_C(   5), -INT8_C(  88), -INT8_C( 126), -INT8_C(  54), -INT8_C(  25)  },
      {  INT8_C(  38), -INT8_C( 126), -INT8_C(  53),  INT8_C( 117),  INT8_C(  74), -INT8_C(  43),  INT8_C(  93),  INT8_C(  63),  INT8_C(  26),  INT8_C(   0),  INT8_C(  22), -INT8_C(   5), -INT8_C(  88), -INT8_C( 126), -INT8_C(  54), -INT8_C(  25)  },
      {  INT8_C(  52),  INT8_C(  19),  INT8_C(  88), -INT8_C(  84),  INT8_C(  85), -INT8_C(  88), -INT8_C(  22), -INT8_C(   2), -INT8_C(  48),  INT8_C(   0), -INT8_C(  75), -INT8_C(  36),  INT8_C(  66),  INT8_C(  19),  INT8_C(  87),  INT8_C(  56)  },
      { -INT8_C(  44),  INT8_C(  83),  INT8_C( 112), -INT8_C(  84),  INT8_C(  85), -INT8_C(  80), -INT8_C(  94), -INT8_C(  18),  INT8_C(  72),  INT8_C(   0), -INT8_C(  43),  INT8_C( 108),  INT8_C(  26),  INT8_C(  83),  INT8_C(  79), -INT8_C(  32)  },
      {  INT8_C( 116),  INT8_C(  19), -INT8_C(  80), -INT8_C(  52),  INT8_C( 117), -INT8_C(  16), -INT8_C(  62), -INT8_C( 114),  INT8_C(  72),  INT8_C(  96),  INT8_C(  85), -INT8_C(  52),  INT8_C(  90),  INT8_C( 115),  INT8_C(  47),       INT8_MIN  } },
    { { -INT8_C(  22), -INT8_C(  17),  INT8_C(  28),  INT8_C(  50), -INT8_C( 115), -INT8_C(  92),  INT8_C( 125), -INT8_C(  70), -INT8_C(  83), -INT8_C(  95),  INT8_C(  82),  INT8_C( 105), -INT8_C( 105),  INT8_C( 108),  INT8_C(  59), -INT8_C( 115)  },
      { -INT8_C(  23), -INT8_C(  45), -INT8_C(  89), -INT8_C( 112), -INT8_C(  31), -INT8_C(  92),  INT8_C(  60),  INT8_C(  70), -INT8_C(   8),  INT8_C( 108),  INT8_C( 110),  INT8_C(  82),  INT8_C(  62), -INT8_C( 116),  INT8_C(  65), -INT8_C(  36)  },
      { -INT8_C(  23), -INT8_C(  45), -INT8_C(  89), -INT8_C( 112), -INT8_C(  31), -INT8_C(  92),  INT8_C(  60),  INT8_C(  70), -INT8_C(   8),  INT8_C( 108),  INT8_C( 110),  INT8_C(  82),  INT8_C(  62), -INT8_C( 116),  INT8_C(  65), -INT8_C(  36)  },
      {  INT8_C(  74), -INT8_C(  97),  INT8_C(  60), -INT8_C( 126),  INT8_C(  13),  INT8_C(  36), -INT8_C(  27),  INT8_C(  50), -INT8_C(  59),  INT8_C(  97),  INT8_C( 114), -INT8_C( 111), -INT8_C(   9),  INT8_C( 100),  INT8_C(  11), -INT8_C(  27)  },
      {  INT8_C(  42),  INT8_C( 111), -INT8_C(   4),  INT8_C(  18),  INT8_C(  45), -INT8_C( 124), -INT8_C(  99), -INT8_C(  38),  INT8_C(  13), -INT8_C( 127), -INT8_C(  46),  INT8_C(  73), -INT8_C(  41), -INT8_C( 116),  INT8_C(  59), -INT8_C( 115)  },
      { -INT8_C(  22), -INT8_C(  17), -INT8_C( 100),  INT8_C(  50), -INT8_C( 115),  INT8_C(  36),  INT8_C( 125),  INT8_C(  58),  INT8_C(  45),  INT8_C(  33),  INT8_C(  82),  INT8_C( 105),  INT8_C(  23),  INT8_C( 108), -INT8_C(  69),  INT8_C(  13)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);

    simde_int8x16_t r0 = simde_vsliq_n_s8(a, b, 0);
    simde_int8x16_t r3 = simde_vsliq_n_s8(a, b, 3);
    simde_int8x16_t r5 = simde_vsliq_n_s8(a, b, 5);
    simde_int8x16_t r7 = simde_vsliq_n_s8(a, b, 7);

    simde_test_arm_neon_assert_equal_i8x16(r0, simde_vld1q_s8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r7, simde_vld1q_s8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r0 = simde_vsliq_n_s8(a, b, 0);
    simde_int8x16_t r3 = simde_vsliq_n_s8(a, b, 3);
    simde_int8x16_t r5 = simde_vsliq_n_s8(a, b, 5);
    simde_int8x16_t r7 = simde_vsliq_n_s8(a, b, 7);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r15[8];
  } test_vec[] = {
    { { -INT16_C(  29857),  INT16_C(   2406), -INT16_C(  11751),  INT16_C(  26063), -INT16_C(  23473), -INT16_C(  31823),  INT16_C(  16138), -INT16_C(  20066)  },
      { -INT16_C(   4911),  INT16_C(  31239), -INT16_C(  17957), -INT16_C(  32668), -INT16_C(  25285), -INT16_C(  17755),  INT16_C(  16852), -INT16_C(  29183)  },
      {  INT16_C(  26255), -INT16_C(  12226), -INT16_C(  12583),  INT16_C(    807), -INT16_C(   5665), -INT16_C(  10967),  INT16_C(   3746),  INT16_C(  28686)  },
      {  INT16_C(  13407), -INT16_C(  32282),  INT16_C(  30425),  INT16_C(   6415),  INT16_C(  20175), -INT16_C(  22159),  INT16_C(  29962), -INT16_C(  32674)  },
      {  INT16_C(  18271),  INT16_C(   7526),  INT16_C(  28185), -INT16_C(  28209), -INT16_C(   5041), -INT16_C(  26703),  INT16_C(  21258),  INT16_C(   1438)  },
      {  INT16_C(  11103), -INT16_C(   5786),  INT16_C(  29209), -INT16_C(  31281),  INT16_C(  25679), -INT16_C(  23631), -INT16_C(  24822),  INT16_C(  12702)  },
      { -INT16_C(  29857), -INT16_C(  30362), -INT16_C(  11751),  INT16_C(  26063), -INT16_C(  23473), -INT16_C(  31823),  INT16_C(  16138), -INT16_C(  20066)  } },
    { {  INT16_C(  22305),  INT16_C(   2996), -INT16_C(   8798),  INT16_C(  21771),  INT16_C(  20048), -INT16_C(  17424), -INT16_C(   7311), -INT16_C(  13384)  },
      {  INT16_C(   3899), -INT16_C(  13236),  INT16_C(  23899),  INT16_C(  10311),  INT16_C(    358), -INT16_C(  22886), -INT16_C(   4505), -INT16_C(  13942)  },
      {  INT16_C(  31193),  INT16_C(  25188), -INT16_C(   5414),  INT16_C(  16955),  INT16_C(   2864),  INT16_C(  13520),  INT16_C(  29497),  INT16_C(  19536)  },
      { -INT16_C(  12575),  INT16_C(   4916),  INT16_C(  22242),  INT16_C(   4555),  INT16_C(  22928), -INT16_C(  22864), -INT16_C(  26127),  INT16_C(  25272)  },
      { -INT16_C(   4319),  INT16_C(  13236),  INT16_C(  28066),  INT16_C(   7435), -INT16_C(  26032),  INT16_C(  27632), -INT16_C(  24719),  INT16_C(  11192)  },
      {  INT16_C(  30497), -INT16_C(  29772),  INT16_C(  32162), -INT16_C(   2805), -INT16_C(  12720),  INT16_C(  23536), -INT16_C(   7311),  INT16_C(  19384)  },
      { -INT16_C(  10463),  INT16_C(   2996), -INT16_C(   8798), -INT16_C(  10997),  INT16_C(  20048),  INT16_C(  15344), -INT16_C(   7311),  INT16_C(  19384)  } },
    { { -INT16_C(   1299), -INT16_C(  23418), -INT16_C(  31396),  INT16_C(  14574),  INT16_C(  20335),  INT16_C(  24078), -INT16_C(  16568), -INT16_C(  30262)  },
      { -INT16_C(   9023), -INT16_C(  23614), -INT16_C(  28517), -INT16_C(  32122),  INT16_C(   6327),  INT16_C(  32095), -INT16_C(   8933),  INT16_C(  26767)  },
      { -INT16_C(   6643),  INT16_C(   7702), -INT16_C(  31524),  INT16_C(   5174), -INT16_C(  14913), -INT16_C(   5378), -INT16_C(   5928),  INT16_C(  17530)  },
      {  INT16_C(  12397), -INT16_C(   3962),  INT16_C(   9948), -INT16_C(  24146),  INT16_C(  11759),  INT16_C(  22478),  INT16_C(  18120),  INT16_C(   9162)  },
      {  INT16_C(   1773),  INT16_C(   2182),  INT16_C(  27996),  INT16_C(   6382), -INT16_C(   8337),  INT16_C(  32270),  INT16_C(  28488),  INT16_C(  15818)  },
      {  INT16_C(  15085),  INT16_C(  17542),  INT16_C(  25948), -INT16_C(  10002), -INT16_C(   4241), -INT16_C(    498),  INT16_C(  32584), -INT16_C(   5686)  },
      { -INT16_C(   1299),  INT16_C(   9350), -INT16_C(  31396),  INT16_C(  14574), -INT16_C(  12433), -INT16_C(   8690), -INT16_C(  16568), -INT16_C(  30262)  } },
    { {  INT16_C(   7035), -INT16_C(  28128), -INT16_C(  27633), -INT16_C(   6964),  INT16_C(   3245),  INT16_C(  16127), -INT16_C(  23649),  INT16_C(  10659)  },
      { -INT16_C(   6328),  INT16_C(  13357), -INT16_C(   9860),  INT16_C(   5121),  INT16_C(   2322), -INT16_C(   9202), -INT16_C(   5031),  INT16_C(   2542)  },
      {  INT16_C(  14915), -INT16_C(  24216), -INT16_C(  13337), -INT16_C(  24564),  INT16_C(  18581), -INT16_C(   8073),  INT16_C(  25295),  INT16_C(  20339)  },
      { -INT16_C(  11717),  INT16_C(   2912),  INT16_C(  24335),  INT16_C(     76),  INT16_C(  17581),  INT16_C(    959),  INT16_C(   5727),  INT16_C(  31651)  },
      {  INT16_C(   9083), -INT16_C(  18912), -INT16_C(   4081),  INT16_C(   1228),  INT16_C(  18605),  INT16_C(  15103),  INT16_C(  26527), -INT16_C(  18013)  },
      {  INT16_C(   7035), -INT16_C(  19936), -INT16_C(  27633),  INT16_C(   9420),  INT16_C(  19629), -INT16_C(   8449),  INT16_C(   9119), -INT16_C(  13917)  },
      {  INT16_C(   7035), -INT16_C(  28128),  INT16_C(   5135), -INT16_C(   6964),  INT16_C(   3245),  INT16_C(  16127), -INT16_C(  23649),  INT16_C(  10659)  } },
    { { -INT16_C(  14045),  INT16_C(   6950),  INT16_C(  25104), -INT16_C(  22985), -INT16_C(    559), -INT16_C(  28091),  INT16_C(   4901),  INT16_C(  28381)  },
      { -INT16_C(  25976), -INT16_C(  15056),  INT16_C(  10123),  INT16_C(   5179),  INT16_C(   9318), -INT16_C(  26683), -INT16_C(  29282),  INT16_C(  29906)  },
      { -INT16_C(  11197),  INT16_C(  10630),  INT16_C(  15448), -INT16_C(  24097),  INT16_C(   9009), -INT16_C(  16851),  INT16_C(  27893), -INT16_C(  22891)  },
      { -INT16_C(  24029),  INT16_C(  19494), -INT16_C(   7472),  INT16_C(   3831),  INT16_C(   6545), -INT16_C(   3771),  INT16_C(  26533),  INT16_C(  13469)  },
      {  INT16_C(   8483), -INT16_C(  15578),  INT16_C(  11792), -INT16_C(   4553), -INT16_C(  26159),  INT16_C(   5701),  INT16_C(  31525),  INT16_C(  19165)  },
      {  INT16_C(   2339),  INT16_C(   6950),  INT16_C(  25104),  INT16_C(  26167), -INT16_C(   8751), -INT16_C(  19899), -INT16_C(  11483),  INT16_C(  20189)  },
      {  INT16_C(  18723),  INT16_C(   6950), -INT16_C(   7664), -INT16_C(  22985),  INT16_C(  32209), -INT16_C(  28091),  INT16_C(   4901),  INT16_C(  28381)  } },
    { { -INT16_C(   7004), -INT16_C(   1843), -INT16_C(  19583),  INT16_C(  21568),  INT16_C(  21139),  INT16_C(   8147),  INT16_C(  22889), -INT16_C(   8842)  },
      { -INT16_C(  14802), -INT16_C(  15206),  INT16_C(  30112),  INT16_C(   8024),  INT16_C(  23550),  INT16_C(  30909), -INT16_C(  13817),  INT16_C(  27018)  },
      {  INT16_C(  12660),  INT16_C(   9429), -INT16_C(  21247), -INT16_C(   1344), -INT16_C(   8205), -INT16_C(  14869),  INT16_C(  20537),  INT16_C(  19542)  },
      { -INT16_C(  29788),  INT16_C(   9869),  INT16_C(  26625), -INT16_C(  10752), -INT16_C(    109),  INT16_C(  12115), -INT16_C(  32279),  INT16_C(  25270)  },
      { -INT16_C(  18268),  INT16_C(  26829), -INT16_C(  31871),  INT16_C(  24640), -INT16_C(   1389), -INT16_C(   2093),  INT16_C(   7529),  INT16_C(  10614)  },
      { -INT16_C(  15196),  INT16_C(  22733),  INT16_C(   4993),  INT16_C(   5184), -INT16_C(  11629), -INT16_C(  16429), -INT16_C(   1687),  INT16_C(  23926)  },
      {  INT16_C(  25764),  INT16_C(  30925),  INT16_C(  13185),  INT16_C(  21568),  INT16_C(  21139), -INT16_C(  24621), -INT16_C(   9879),  INT16_C(  23926)  } },
    { {  INT16_C(  17169),  INT16_C(  24072), -INT16_C(  12994), -INT16_C(   8073), -INT16_C(  12777),  INT16_C(   1825), -INT16_C(   5150), -INT16_C(  31600)  },
      { -INT16_C(   7078),  INT16_C(  21725),  INT16_C(  27331), -INT16_C(   7935), -INT16_C(   9434),  INT16_C(  29126),  INT16_C(  21858), -INT16_C(   2211)  },
      {  INT16_C(   8913), -INT16_C(  22808),  INT16_C(  22046),  INT16_C(   2063), -INT16_C(   9929), -INT16_C(  29135), -INT16_C(  21742), -INT16_C(  17688)  },
      {  INT16_C(   5777),  INT16_C(  14152), -INT16_C(  20226),  INT16_C(  16503), -INT16_C(  13929),  INT16_C(  29089),  INT16_C(  22690), -INT16_C(  10416)  },
      {  INT16_C(  27409),  INT16_C(  30216),  INT16_C(   3390),  INT16_C(   1143), -INT16_C(  26089),  INT16_C(   6945), -INT16_C(  29726),  INT16_C(  29840)  },
      {  INT16_C(  17169), -INT16_C(  16888),  INT16_C(  27966),  INT16_C(   8311), -INT16_C(  12777), -INT16_C(  14559),  INT16_C(  19426), -INT16_C(  23408)  },
      {  INT16_C(  17169), -INT16_C(   8696), -INT16_C(  12994), -INT16_C(   8073),  INT16_C(  19991),  INT16_C(   1825),  INT16_C(  27618), -INT16_C(  31600)  } },
    { { -INT16_C(  23136), -INT16_C(  21049),  INT16_C(   4129), -INT16_C(   8019),  INT16_C(  25623),  INT16_C(   9637),  INT16_C(   8632),  INT16_C(  32502)  },
      { -INT16_C(   1800),  INT16_C(  21742),  INT16_C(  13572), -INT16_C(  19366), -INT16_C(   6353),  INT16_C(  26854),  INT16_C(    902),  INT16_C(  24083)  },
      { -INT16_C(  14400), -INT16_C(  22665), -INT16_C(  22495), -INT16_C(  23851),  INT16_C(  14719),  INT16_C(  18229),  INT16_C(   7216), -INT16_C(   3938)  },
      {  INT16_C(  15904),  INT16_C(  15239),  INT16_C(  16673),  INT16_C(   5805), -INT16_C(  13353),  INT16_C(  14757), -INT16_C(   7752), -INT16_C(  31498)  },
      { -INT16_C(   7776), -INT16_C(  17977),  INT16_C(   4129),  INT16_C(  26797), -INT16_C(  17385), -INT16_C(  26203),  INT16_C(   6584),  INT16_C(  20214)  },
      {  INT16_C(   1440), -INT16_C(  12857), -INT16_C(  28639),  INT16_C(  16557), -INT16_C(   7145), -INT16_C(  14939), -INT16_C(  15944),  INT16_C(  32502)  },
      {  INT16_C(   9632),  INT16_C(  11719),  INT16_C(   4129),  INT16_C(  24749), -INT16_C(   7145),  INT16_C(   9637),  INT16_C(   8632), -INT16_C(    266)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);

    simde_int16x8_t r3 = simde_vsliq_n_s16(a, b, 3);
    simde_int16x8_t r6 = simde_vsliq_n_s16(a, b, 6);
    simde_int16x8_t r10 = simde_vsliq_n_s16(a, b, 10);
    simde_int16x8_t r13 = simde_vsliq_n_s16(a, b, 13);
    simde_int16x8_t r15 = simde_vsliq_n_s16(a, b, 15);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r15, simde_vld1q_s16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r3 = simde_vsliq_n_s16(a, b, 3);
    simde_int16x8_t r6 = simde_vsliq_n_s16(a, b, 6);
    simde_int16x8_t r10 = simde_vsliq_n_s16(a, b, 10);
    simde_int16x8_t r13 = simde_vsliq_n_s16(a, b, 13);
    simde_int16x8_t r15 = simde_vsliq_n_s16(a, b, 15);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r31[4];
  } test_vec[] = {
    { { -INT32_C(  2048672908),  INT32_C(   482466515), -INT32_C(   375121982),  INT32_C(  1919378555)  },
      { -INT32_C(    92957730),  INT32_C(  1419974623),  INT32_C(  1820210245), -INT32_C(   127918576)  },
      { -INT32_C(  1654327372),  INT32_C(   684062675),  INT32_C(   529338690),  INT32_C(   403145787)  },
      { -INT32_C(  1300505740),  INT32_C(  1660680915), -INT32_C(   964118590),  INT32_C(    63046779)  },
      { -INT32_C(  1628193932), -INT32_C(  1090921773), -INT32_C(  1574168638), -INT32_C(   259562373)  },
      {  INT32_C(  2044967796),  INT32_C(  2093079251),  INT32_C(   363075522),  INT32_C(  1114072187)  },
      {  INT32_C(    98810740), -INT32_C(  1665017133), -INT32_C(   375121982),  INT32_C(  1919378555)  } },
    { {  INT32_C(   429638935),  INT32_C(   807280638),  INT32_C(   482365039),  INT32_C(  1712721656)  },
      {  INT32_C(   396810675),  INT32_C(  2144555430), -INT32_C(   705681075),  INT32_C(   287557555)  },
      { -INT32_C(   373920553), -INT32_C(   187405890),  INT32_C(  2081051503),  INT32_C(  1223814392)  },
      { -INT32_C(   617192169),  INT32_C(  1781850110),  INT32_C(    86617711),  INT32_C(  2029416184)  },
      { -INT32_C(   845429481), -INT32_C(  1925832706),  INT32_C(  1248349807),  INT32_C(  1033768696)  },
      { -INT32_C(   845429481), -INT32_C(  1742856194),  INT32_C(   885018223), -INT32_C(   837415176)  },
      { -INT32_C(  1717844713),  INT32_C(   807280638), -INT32_C(  1665118609), -INT32_C(   434761992)  } },
    { { -INT32_C(   517994438),  INT32_C(  1285438865), -INT32_C(   338029974),  INT32_C(    40999571)  },
      {  INT32_C(   291353625), -INT32_C(  1038552292), -INT32_C(  2119572785), -INT32_C(  1620388047)  },
      {  INT32_C(  1466762874), -INT32_C(  2042837231),  INT32_C(  1786295274), -INT32_C(   625619885)  },
      { -INT32_C(  1232918470),  INT32_C(   509844881),  INT32_C(  1012527722),  INT32_C(  1525037715)  },
      { -INT32_C(  1597503430), -INT32_C(  1729741423),  INT32_C(   377098858), -INT32_C(  1182164333)  },
      {  INT32_C(  1696598074),  INT32_C(  1889418641),  INT32_C(  1071256170), -INT32_C(   965633389)  },
      { -INT32_C(   517994438),  INT32_C(  1285438865), -INT32_C(   338029974), -INT32_C(  2106484077)  } },
    { { -INT32_C(    61481464),  INT32_C(   164801062), -INT32_C(  1442367081),  INT32_C(   600232314)  },
      {  INT32_C(   268218714), -INT32_C(    64451073), -INT32_C(   735524508), -INT32_C(  1224314185)  },
      { -INT32_C(    13871480),  INT32_C(   170098662),  INT32_C(   171071767), -INT32_C(  1046696454)  },
      { -INT32_C(  1775542776),  INT32_C(   297789990),  INT32_C(   422353303), -INT32_C(   833162886)  },
      { -INT32_C(  1965695480),  INT32_C(  1878698534),  INT32_C(  1260861847), -INT32_C(  1782656646)  },
      {  INT32_C(  1750457864), -INT32_C(    36525530), -INT32_C(  1845020265), -INT32_C(   540618374)  },
      {  INT32_C(  2086002184), -INT32_C(  1982682586),  INT32_C(   705116567), -INT32_C(  1547251334)  } },
    { { -INT32_C(   126851217), -INT32_C(  1366643457), -INT32_C(  1960710568),  INT32_C(  1373905720)  },
      {  INT32_C(   491803898),  INT32_C(   803598513), -INT32_C(  1851430137), -INT32_C(   750917567)  },
      {  INT32_C(  1410678447), -INT32_C(   109302657),  INT32_C(  1767555544), -INT32_C(   814083976)  },
      {  INT32_C(   178210671), -INT32_C(  1105842945), -INT32_C(  1386156456), -INT32_C(  1123540168)  },
      { -INT32_C(  1479514257), -INT32_C(  2054509313),  INT32_C(  1480191576),  INT32_C(  1108091704)  },
      { -INT32_C(   395286673), -INT32_C(   963990273),  INT32_C(   522317400),  INT32_C(    98837304)  },
      {  INT32_C(  2020632431), -INT32_C(  1366643457), -INT32_C(  1960710568), -INT32_C(   773577928)  } },
    { { -INT32_C(  2137359464), -INT32_C(   615731445),  INT32_C(   708318726),  INT32_C(   944041089)  },
      {  INT32_C(   938801535), -INT32_C(    84228041),  INT32_C(   353656812),  INT32_C(   158358579)  },
      { -INT32_C(    46243880), -INT32_C(  1095627317),  INT32_C(  1159199494),  INT32_C(  1545014465)  },
      { -INT32_C(  1624245352),  INT32_C(  1493626635), -INT32_C(  1946315258),  INT32_C(   193358977)  },
      { -INT32_C(   872776808),  INT32_C(  1102884619), -INT32_C(    10480122), -INT32_C(   509809535)  },
      { -INT32_C(    56984680), -INT32_C(   548622581), -INT32_C(  1304947194), -INT32_C(   867898239)  },
      { -INT32_C(  2137359464), -INT32_C(   615731445),  INT32_C(   708318726), -INT32_C(  1203442559)  } },
    { {  INT32_C(  1569927325),  INT32_C(  1349793024),  INT32_C(  1347867252),  INT32_C(   583373983)  },
      {  INT32_C(   198226018),  INT32_C(  1371438700),  INT32_C(   322817713),  INT32_C(  1605845413)  },
      { -INT32_C(   198436707),  INT32_C(  1872730880), -INT32_C(   814502796), -INT32_C(   305108641)  },
      {  INT32_C(   369905821), -INT32_C(   808610560), -INT32_C(  1177144716), -INT32_C(   399199073)  },
      { -INT32_C(  2095894371), -INT32_C(   211536640),  INT32_C(  1972294260),  INT32_C(   221090975)  },
      { -INT32_C(  1986842467), -INT32_C(  1334561536), -INT32_C(  1000942988), -INT32_C(  1765436257)  },
      {  INT32_C(  1569927325),  INT32_C(  1349793024), -INT32_C(   799616396), -INT32_C(  1564109665)  } },
    { {  INT32_C(  2115085206),  INT32_C(  1904667615), -INT32_C(  1478857215), -INT32_C(  1378658545)  },
      {  INT32_C(   738556760),  INT32_C(   523005912), -INT32_C(   406383756),  INT32_C(  1614439741)  },
      {  INT32_C(    22992406), -INT32_C(   887359969), -INT32_C(   238756607),  INT32_C(   244928335)  },
      { -INT32_C(  1351941226), -INT32_C(  1912927265), -INT32_C(   496071167),  INT32_C(  1286059791)  },
      { -INT32_C(   624843882),  INT32_C(  2126965727), -INT32_C(  1683853823),  INT32_C(   703289103)  },
      {  INT32_C(  1645323158),  INT32_C(  1636232159), -INT32_C(   740659711), -INT32_C(   170698993)  },
      {  INT32_C(  2115085206),  INT32_C(  1904667615),  INT32_C(   668626433), -INT32_C(  1378658545)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);

    simde_int32x4_t r6 = simde_vsliq_n_s32(a, b, 6);
    simde_int32x4_t r13 = simde_vsliq_n_s32(a, b, 13);
    simde_int32x4_t r19 = simde_vsliq_n_s32(a, b, 19);
    simde_int32x4_t r26 = simde_vsliq_n_s32(a, b, 26);
    simde_int32x4_t r31 = simde_vsliq_n_s32(a, b, 31);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r31, simde_vld1q_s32(test_vec[i].r31));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r6 = simde_vsliq_n_s32(a, b, 6);
    simde_int32x4_t r13 = simde_vsliq_n_s32(a, b, 13);
    simde_int32x4_t r19 = simde_vsliq_n_s32(a, b, 19);
    simde_int32x4_t r26 = simde_vsliq_n_s32(a, b, 26);
    simde_int32x4_t r31 = simde_vsliq_n_s32(a, b, 31);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r13[2];
    int64_t r26[2];
    int64_t r39[2];
    int64_t r52[2];
    int64_t r63[2];
  } test_vec[] = {
    { { -INT64_C( 5263643971819047857),  INT64_C(  541502720996737267)  },
      {  INT64_C( 3946797069985802130), -INT64_C(   42445362033043898)  },
      { -INT64_C( 4980763889152928689),  INT64_C( 2775731625785868531)  },
      {  INT64_C( 1780111104754152527), -INT64_C( 6041964446011948813)  },
      { -INT64_C( 8704392437862665137), -INT64_C( 3158391839620661005)  },
      {  INT64_C( 8729040070421083215),  INT64_C( 7233851767269294323)  },
      {  INT64_C( 3959728065035727951),  INT64_C(  541502720996737267)  } },
    { { -INT64_C( 7912615021952819050), -INT64_C( 5293486681595043945)  },
      {  INT64_C( 6940172625691428387),  INT64_C( 9115758130503661579)  },
      {  INT64_C( 1028914491343265942),  INT64_C( 3870594709730721687)  },
      { -INT64_C( 1294528601230335850), -INT64_C( 2041200592708952169)  },
      {  INT64_C( 2099541159110320278), -INT64_C( 8765124277553586281)  },
      {  INT64_C( 7075364537936191638), -INT64_C( 9171085960761041001)  },
      { -INT64_C( 7912615021952819050), -INT64_C( 5293486681595043945)  } },
    { {  INT64_C( 2180577019911891298), -INT64_C( 1541747926973591080)  },
      { -INT64_C( 8065666064468080886), -INT64_C( 6826784933820909701)  },
      {  INT64_C( 2300871905095272802),  INT64_C( 5505853626468233688)  },
      { -INT64_C( 3829796790686029470),  INT64_C( 1663647807938712024)  },
      {  INT64_C( 4216360182134499682), -INT64_C( 3541027852909850152)  },
      {  INT64_C( 8116321328786205026),  INT64_C( 8627380031628988888)  },
      {  INT64_C( 2180577019911891298), -INT64_C( 1541747926973591080)  } },
    { { -INT64_C( 1415110380634122788),  INT64_C( 3816863978450722004)  },
      {  INT64_C( 6818280905982752686),  INT64_C( 9098726142237371117)  },
      { -INT64_C( 1383873381812283940), -INT64_C( 6528244651753882412)  },
      {  INT64_C( 8056861525103990236), -INT64_C( 2269117483815658284)  },
      { -INT64_C(  640682009993816612),  INT64_C( 5707598467225492692)  },
      {  INT64_C( 8857600369397978588), -INT64_C( 5847860821886362412)  },
      {  INT64_C( 7808261656220653020), -INT64_C( 5406508058404053804)  } },
    { { -INT64_C( 1783781172000361495),  INT64_C( 7705716969977077247)  },
      { -INT64_C( 8358257093625578635), -INT64_C( 7084006825256911651)  },
      {  INT64_C( 3471890629115425769),  INT64_C( 1272943385629146623)  },
      { -INT64_C( 3151327946570763287),  INT64_C( 5541813428062969343)  },
      { -INT64_C( 8683578925376113687),  INT64_C( 1098437138345549311)  },
      { -INT64_C( 5233538486566161431), -INT64_C( 3616332493232349697)  },
      { -INT64_C( 1783781172000361495), -INT64_C( 1517655066877698561)  } },
    { { -INT64_C( 4154394067891526097), -INT64_C( 2189220270624961150)  },
      { -INT64_C( 6795139893074132725), -INT64_C(  309058967878318537)  },
      {  INT64_C( 6487610392131495471), -INT64_C( 4607126760976880254)  },
      {  INT64_C( 1434655984018908719),  INT64_C(  455948887150071170)  },
      {  INT64_C( 2125845925662680623),  INT64_C( 8890980614938856834)  },
      {  INT64_C( 1204889488679364143),  INT64_C( 7169259755050929538)  },
      { -INT64_C( 4154394067891526097), -INT64_C( 2189220270624961150)  } },
    { { -INT64_C( 2333047277017444018),  INT64_C( 7658204717489207402)  },
      { -INT64_C( 6281729226854084346),  INT64_C( 6339895830207820242)  },
      {  INT64_C( 6490139260990050638),  INT64_C( 8842073570075629674)  },
      {  INT64_C( 3704405599550624078), -INT64_C( 6097291397849008022)  },
      {  INT64_C( 1596670502572577102),  INT64_C( 4771820118565599338)  },
      {  INT64_C( 1184264031958913358),  INT64_C( 2100762777314015338)  },
      {  INT64_C( 6890324759837331790),  INT64_C( 7658204717489207402)  } },
    { {  INT64_C( 8524677170650393138),  INT64_C( 3185460102790185058)  },
      { -INT64_C( 4517026812874662391),  INT64_C( 3366551090117233348)  },
      {  INT64_C(  684960792126237234),  INT64_C(  904140044595920994)  },
      {  INT64_C( 3388610690435492402), -INT64_C( 8875872301439188894)  },
      { -INT64_C( 2851054848273569230),  INT64_C( 5919245132162203746)  },
      { -INT64_C( 2261443936901944782), -INT64_C( 6033408334437220254)  },
      { -INT64_C(  698694866204382670),  INT64_C( 3185460102790185058)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);

    simde_int64x2_t r13 = simde_vsliq_n_s64(a, b, 13);
    simde_int64x2_t r26 = simde_vsliq_n_s64(a, b, 26);
    simde_int64x2_t r39 = simde_vsliq_n_s64(a, b, 39);
    simde_int64x2_t r52 = simde_vsliq_n_s64(a, b, 52);
    simde_int64x2_t r63 = simde_vsliq_n_s64(a, b, 63);

    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r39, simde_vld1q_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x2(r52, simde_vld1q_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x2(r63, simde_vld1q_s64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r13 = simde_vsliq_n_s64(a, b, 13);
    simde_int64x2_t r26 = simde_vsliq_n_s64(a, b, 26);
    simde_int64x2_t r39 = simde_vsliq_n_s64(a, b, 39);
    simde_int64x2_t r52 = simde_vsliq_n_s64(a, b, 52);
    simde_int64x2_t r63 = simde_vsliq_n_s64(a, b, 63);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r0[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r7[16];
  } test_vec[] = {
    { {  UINT8_C(   244),  UINT8_C(    66),  UINT8_C(   116),  UINT8_C(    69),  UINT8_C(   184),  UINT8_C(   184),  UINT8_C(    36),  UINT8_C(   119),  UINT8_C(   145),  UINT8_C(    73),  UINT8_C(    68),  UINT8_C(   242),  UINT8_C(   252),  UINT8_C(   205),  UINT8_C(   128),  UINT8_C(    96)  },
      {  UINT8_C(   152),  UINT8_C(    85),  UINT8_C(   203),  UINT8_C(   155),  UINT8_C(    94),  UINT8_C(    94),  UINT8_C(   115),  UINT8_C(    52),  UINT8_C(   255),  UINT8_C(    54),  UINT8_C(   182),  UINT8_C(   141),  UINT8_C(    92),  UINT8_C(   173),  UINT8_C(   209),  UINT8_C(   117)  },
      {  UINT8_C(   152),  UINT8_C(    85),  UINT8_C(   203),  UINT8_C(   155),  UINT8_C(    94),  UINT8_C(    94),  UINT8_C(   115),  UINT8_C(    52),        UINT8_MAX,  UINT8_C(    54),  UINT8_C(   182),  UINT8_C(   141),  UINT8_C(    92),  UINT8_C(   173),  UINT8_C(   209),  UINT8_C(   117)  },
      {  UINT8_C(   196),  UINT8_C(   170),  UINT8_C(    92),  UINT8_C(   221),  UINT8_C(   240),  UINT8_C(   240),  UINT8_C(   156),  UINT8_C(   167),  UINT8_C(   249),  UINT8_C(   177),  UINT8_C(   180),  UINT8_C(   106),  UINT8_C(   228),  UINT8_C(   109),  UINT8_C(   136),  UINT8_C(   168)  },
      {  UINT8_C(    20),  UINT8_C(   162),  UINT8_C(   116),  UINT8_C(   101),  UINT8_C(   216),  UINT8_C(   216),  UINT8_C(   100),  UINT8_C(   151),  UINT8_C(   241),  UINT8_C(   201),  UINT8_C(   196),  UINT8_C(   178),  UINT8_C(   156),  UINT8_C(   173),  UINT8_C(    32),  UINT8_C(   160)  },
      {  UINT8_C(   116),  UINT8_C(   194),  UINT8_C(   244),  UINT8_C(   197),  UINT8_C(    56),  UINT8_C(    56),  UINT8_C(   164),  UINT8_C(   119),  UINT8_C(   145),  UINT8_C(    73),  UINT8_C(    68),  UINT8_C(   242),  UINT8_C(   124),  UINT8_C(   205),  UINT8_C(   128),  UINT8_C(   224)  } },
    { {  UINT8_C(   196),  UINT8_C(   145),  UINT8_C(   235),  UINT8_C(   187),  UINT8_C(   234),  UINT8_C(    71),  UINT8_C(   208),  UINT8_C(    39),  UINT8_C(   217),  UINT8_C(   216),  UINT8_C(   187),  UINT8_C(   169),  UINT8_C(    88),  UINT8_C(   246),  UINT8_C(   218),  UINT8_C(   150)  },
      {  UINT8_C(   139),  UINT8_C(   183),  UINT8_C(   107),  UINT8_C(   236),  UINT8_C(   111),  UINT8_C(   223),  UINT8_C(   146),  UINT8_C(   125),  UINT8_C(     1),  UINT8_C(   153),  UINT8_C(   203),  UINT8_C(     5),  UINT8_C(   159),  UINT8_C(    47),  UINT8_C(   104),  UINT8_C(   122)  },
      {  UINT8_C(   139),  UINT8_C(   183),  UINT8_C(   107),  UINT8_C(   236),  UINT8_C(   111),  UINT8_C(   223),  UINT8_C(   146),  UINT8_C(   125),  UINT8_C(     1),  UINT8_C(   153),  UINT8_C(   203),  UINT8_C(     5),  UINT8_C(   159),  UINT8_C(    47),  UINT8_C(   104),  UINT8_C(   122)  },
      {  UINT8_C(    92),  UINT8_C(   185),  UINT8_C(    91),  UINT8_C(    99),  UINT8_C(   122),        UINT8_MAX,  UINT8_C(   144),  UINT8_C(   239),  UINT8_C(     9),  UINT8_C(   200),  UINT8_C(    91),  UINT8_C(    41),  UINT8_C(   248),  UINT8_C(   126),  UINT8_C(    66),  UINT8_C(   214)  },
      {  UINT8_C(   100),  UINT8_C(   241),  UINT8_C(   107),  UINT8_C(   155),  UINT8_C(   234),  UINT8_C(   231),  UINT8_C(    80),  UINT8_C(   167),  UINT8_C(    57),  UINT8_C(    56),  UINT8_C(   123),  UINT8_C(   169),  UINT8_C(   248),  UINT8_C(   246),  UINT8_C(    26),  UINT8_C(    86)  },
      {  UINT8_C(   196),  UINT8_C(   145),  UINT8_C(   235),  UINT8_C(    59),  UINT8_C(   234),  UINT8_C(   199),  UINT8_C(    80),  UINT8_C(   167),  UINT8_C(   217),  UINT8_C(   216),  UINT8_C(   187),  UINT8_C(   169),  UINT8_C(   216),  UINT8_C(   246),  UINT8_C(    90),  UINT8_C(    22)  } },
    { {  UINT8_C(    99),  UINT8_C(   213),  UINT8_C(    98),  UINT8_C(   126),  UINT8_C(   100),  UINT8_C(   135),  UINT8_C(   177),  UINT8_C(   214),  UINT8_C(   144),  UINT8_C(    59),  UINT8_C(   153),  UINT8_C(     4),  UINT8_C(    22),  UINT8_C(    60),  UINT8_C(    89),  UINT8_C(    55)  },
      {  UINT8_C(   110),  UINT8_C(    86),  UINT8_C(   122),  UINT8_C(    11),  UINT8_C(    21),  UINT8_C(   130),  UINT8_C(   209),  UINT8_C(    56),  UINT8_C(   211),  UINT8_C(   181),  UINT8_C(     9),  UINT8_C(   238),  UINT8_C(   204),  UINT8_C(    88),  UINT8_C(   131),  UINT8_C(   141)  },
      {  UINT8_C(   110),  UINT8_C(    86),  UINT8_C(   122),  UINT8_C(    11),  UINT8_C(    21),  UINT8_C(   130),  UINT8_C(   209),  UINT8_C(    56),  UINT8_C(   211),  UINT8_C(   181),  UINT8_C(     9),  UINT8_C(   238),  UINT8_C(   204),  UINT8_C(    88),  UINT8_C(   131),  UINT8_C(   141)  },
      {  UINT8_C(   115),  UINT8_C(   181),  UINT8_C(   210),  UINT8_C(    94),  UINT8_C(   172),  UINT8_C(    23),  UINT8_C(   137),  UINT8_C(   198),  UINT8_C(   152),  UINT8_C(   171),  UINT8_C(    73),  UINT8_C(   116),  UINT8_C(   102),  UINT8_C(   196),  UINT8_C(    25),  UINT8_C(   111)  },
      {  UINT8_C(   195),  UINT8_C(   213),  UINT8_C(    66),  UINT8_C(   126),  UINT8_C(   164),  UINT8_C(    71),  UINT8_C(    49),  UINT8_C(    22),  UINT8_C(   112),  UINT8_C(   187),  UINT8_C(    57),  UINT8_C(   196),  UINT8_C(   150),  UINT8_C(    28),  UINT8_C(   121),  UINT8_C(   183)  },
      {  UINT8_C(    99),  UINT8_C(    85),  UINT8_C(    98),  UINT8_C(   254),  UINT8_C(   228),  UINT8_C(     7),  UINT8_C(   177),  UINT8_C(    86),  UINT8_C(   144),  UINT8_C(   187),  UINT8_C(   153),  UINT8_C(     4),  UINT8_C(    22),  UINT8_C(    60),  UINT8_C(   217),  UINT8_C(   183)  } },
    { {  UINT8_C(   180),  UINT8_C(   141),  UINT8_C(   233),  UINT8_C(   117),  UINT8_C(   209),  UINT8_C(    84),  UINT8_C(    61),  UINT8_C(   212),  UINT8_C(   173),  UINT8_C(    50),  UINT8_C(   112),  UINT8_C(    18),  UINT8_C(   188),  UINT8_C(    32),  UINT8_C(   189),  UINT8_C(   127)  },
      {  UINT8_C(   190),  UINT8_C(   224),  UINT8_C(   111),  UINT8_C(   107),  UINT8_C(    92),  UINT8_C(    61),  UINT8_C(   107),  UINT8_C(   194),  UINT8_C(   193),  UINT8_C(    92),  UINT8_C(   169),  UINT8_C(    27),  UINT8_C(   120),  UINT8_C(   102),  UINT8_C(   237),  UINT8_C(   120)  },
      {  UINT8_C(   190),  UINT8_C(   224),  UINT8_C(   111),  UINT8_C(   107),  UINT8_C(    92),  UINT8_C(    61),  UINT8_C(   107),  UINT8_C(   194),  UINT8_C(   193),  UINT8_C(    92),  UINT8_C(   169),  UINT8_C(    27),  UINT8_C(   120),  UINT8_C(   102),  UINT8_C(   237),  UINT8_C(   120)  },
      {  UINT8_C(   244),  UINT8_C(     5),  UINT8_C(   121),  UINT8_C(    93),  UINT8_C(   225),  UINT8_C(   236),  UINT8_C(    93),  UINT8_C(    20),  UINT8_C(    13),  UINT8_C(   226),  UINT8_C(    72),  UINT8_C(   218),  UINT8_C(   196),  UINT8_C(    48),  UINT8_C(   109),  UINT8_C(   199)  },
      {  UINT8_C(   212),  UINT8_C(    13),  UINT8_C(   233),  UINT8_C(   117),  UINT8_C(   145),  UINT8_C(   180),  UINT8_C(   125),  UINT8_C(    84),  UINT8_C(    45),  UINT8_C(   146),  UINT8_C(    48),  UINT8_C(   114),  UINT8_C(    28),  UINT8_C(   192),  UINT8_C(   189),  UINT8_C(    31)  },
      {  UINT8_C(    52),  UINT8_C(    13),  UINT8_C(   233),  UINT8_C(   245),  UINT8_C(    81),  UINT8_C(   212),  UINT8_C(   189),  UINT8_C(    84),  UINT8_C(   173),  UINT8_C(    50),  UINT8_C(   240),  UINT8_C(   146),  UINT8_C(    60),  UINT8_C(    32),  UINT8_C(   189),  UINT8_C(   127)  } },
    { {  UINT8_C(   183),  UINT8_C(    36),  UINT8_C(   213),  UINT8_C(   190),  UINT8_C(    11),  UINT8_C(   205),  UINT8_C(   129),  UINT8_C(    21),  UINT8_C(     4),  UINT8_C(   108),  UINT8_C(   248),  UINT8_C(   225),  UINT8_C(   169),  UINT8_C(    75),  UINT8_C(   175),  UINT8_C(    43)  },
      {  UINT8_C(   141),  UINT8_C(    83),  UINT8_C(    71),  UINT8_C(    14),  UINT8_C(    37),  UINT8_C(    24),  UINT8_C(   233),  UINT8_C(   220),  UINT8_C(    16),  UINT8_C(    80),  UINT8_C(   162),  UINT8_C(    85),  UINT8_C(    75),  UINT8_C(   254),  UINT8_C(   153),  UINT8_C(    29)  },
      {  UINT8_C(   141),  UINT8_C(    83),  UINT8_C(    71),  UINT8_C(    14),  UINT8_C(    37),  UINT8_C(    24),  UINT8_C(   233),  UINT8_C(   220),  UINT8_C(    16),  UINT8_C(    80),  UINT8_C(   162),  UINT8_C(    85),  UINT8_C(    75),  UINT8_C(   254),  UINT8_C(   153),  UINT8_C(    29)  },
      {  UINT8_C(   111),  UINT8_C(   156),  UINT8_C(    61),  UINT8_C(   118),  UINT8_C(    43),  UINT8_C(   197),  UINT8_C(    73),  UINT8_C(   229),  UINT8_C(   132),  UINT8_C(   132),  UINT8_C(    16),  UINT8_C(   169),  UINT8_C(    89),  UINT8_C(   243),  UINT8_C(   207),  UINT8_C(   235)  },
      {  UINT8_C(   183),  UINT8_C(   100),  UINT8_C(   245),  UINT8_C(   222),  UINT8_C(   171),  UINT8_C(    13),  UINT8_C(    33),  UINT8_C(   149),  UINT8_C(     4),  UINT8_C(    12),  UINT8_C(    88),  UINT8_C(   161),  UINT8_C(   105),  UINT8_C(   203),  UINT8_C(    47),  UINT8_C(   171)  },
      {  UINT8_C(   183),  UINT8_C(   164),  UINT8_C(   213),  UINT8_C(    62),  UINT8_C(   139),  UINT8_C(    77),  UINT8_C(   129),  UINT8_C(    21),  UINT8_C(     4),  UINT8_C(   108),  UINT8_C(   120),  UINT8_C(   225),  UINT8_C(   169),  UINT8_C(    75),  UINT8_C(   175),  UINT8_C(   171)  } },
    { {  UINT8_C(   234),  UINT8_C(   182),  UINT8_C(   103),  UINT8_C(   241),  UINT8_C(    11),  UINT8_C(   127),  UINT8_C(   118),  UINT8_C(    55),  UINT8_C(   177),  UINT8_C(   196),  UINT8_C(   189),  UINT8_C(   131),  UINT8_C(   254),  UINT8_C(   151),  UINT8_C(   156),  UINT8_C(    20)  },
      {  UINT8_C(    38),  UINT8_C(    43),  UINT8_C(   107),  UINT8_C(   172),  UINT8_C(   184),  UINT8_C(    43),  UINT8_C(   121),  UINT8_C(   218),  UINT8_C(    74),  UINT8_C(   188),  UINT8_C(     8),  UINT8_C(   190),  UINT8_C(   231),  UINT8_C(   164),  UINT8_C(   142),  UINT8_C(   233)  },
      {  UINT8_C(    38),  UINT8_C(    43),  UINT8_C(   107),  UINT8_C(   172),  UINT8_C(   184),  UINT8_C(    43),  UINT8_C(   121),  UINT8_C(   218),  UINT8_C(    74),  UINT8_C(   188),  UINT8_C(     8),  UINT8_C(   190),  UINT8_C(   231),  UINT8_C(   164),  UINT8_C(   142),  UINT8_C(   233)  },
      {  UINT8_C(    50),  UINT8_C(    94),  UINT8_C(    95),  UINT8_C(    97),  UINT8_C(   195),  UINT8_C(    95),  UINT8_C(   206),  UINT8_C(   215),  UINT8_C(    81),  UINT8_C(   228),  UINT8_C(    69),  UINT8_C(   243),  UINT8_C(    62),  UINT8_C(    39),  UINT8_C(   116),  UINT8_C(    76)  },
      {  UINT8_C(   202),  UINT8_C(   118),  UINT8_C(   103),  UINT8_C(   145),  UINT8_C(    11),  UINT8_C(   127),  UINT8_C(    54),  UINT8_C(    87),  UINT8_C(    81),  UINT8_C(   132),  UINT8_C(    29),  UINT8_C(   195),  UINT8_C(   254),  UINT8_C(   151),  UINT8_C(   220),  UINT8_C(    52)  },
      {  UINT8_C(   106),  UINT8_C(   182),  UINT8_C(   231),  UINT8_C(   113),  UINT8_C(    11),        UINT8_MAX,  UINT8_C(   246),  UINT8_C(    55),  UINT8_C(    49),  UINT8_C(    68),  UINT8_C(    61),  UINT8_C(     3),  UINT8_C(   254),  UINT8_C(    23),  UINT8_C(    28),  UINT8_C(   148)  } },
    { {  UINT8_C(    46),  UINT8_C(   219),  UINT8_C(    53),  UINT8_C(     4),  UINT8_C(   130),  UINT8_C(   212),  UINT8_C(    30),  UINT8_C(    85),  UINT8_C(   206),  UINT8_C(    67),  UINT8_C(    71),  UINT8_C(    68),  UINT8_C(   104),  UINT8_C(   195),  UINT8_C(    15),  UINT8_C(   107)  },
      {  UINT8_C(   125),  UINT8_C(   115),  UINT8_C(   253),  UINT8_C(   164),  UINT8_C(   131),  UINT8_C(    60),  UINT8_C(    54),  UINT8_C(    18),  UINT8_C(   160),  UINT8_C(    87),  UINT8_C(   144),  UINT8_C(    99),  UINT8_C(   146),  UINT8_C(   139),  UINT8_C(   180),  UINT8_C(    90)  },
      {  UINT8_C(   125),  UINT8_C(   115),  UINT8_C(   253),  UINT8_C(   164),  UINT8_C(   131),  UINT8_C(    60),  UINT8_C(    54),  UINT8_C(    18),  UINT8_C(   160),  UINT8_C(    87),  UINT8_C(   144),  UINT8_C(    99),  UINT8_C(   146),  UINT8_C(   139),  UINT8_C(   180),  UINT8_C(    90)  },
      {  UINT8_C(   238),  UINT8_C(   155),  UINT8_C(   237),  UINT8_C(    36),  UINT8_C(    26),  UINT8_C(   228),  UINT8_C(   182),  UINT8_C(   149),  UINT8_C(     6),  UINT8_C(   187),  UINT8_C(   135),  UINT8_C(    28),  UINT8_C(   144),  UINT8_C(    91),  UINT8_C(   167),  UINT8_C(   211)  },
      {  UINT8_C(   174),  UINT8_C(   123),  UINT8_C(   181),  UINT8_C(   132),  UINT8_C(    98),  UINT8_C(   148),  UINT8_C(   222),  UINT8_C(    85),  UINT8_C(    14),  UINT8_C(   227),  UINT8_C(     7),  UINT8_C(   100),  UINT8_C(    72),  UINT8_C(    99),  UINT8_C(   143),  UINT8_C(    75)  },
      {  UINT8_C(   174),  UINT8_C(   219),  UINT8_C(   181),  UINT8_C(     4),  UINT8_C(   130),  UINT8_C(    84),  UINT8_C(    30),  UINT8_C(    85),  UINT8_C(    78),  UINT8_C(   195),  UINT8_C(    71),  UINT8_C(   196),  UINT8_C(   104),  UINT8_C(   195),  UINT8_C(    15),  UINT8_C(   107)  } },
    { {  UINT8_C(   234),  UINT8_C(    41),  UINT8_C(     8),  UINT8_C(   239),  UINT8_C(   215),  UINT8_C(   216),  UINT8_C(   100),  UINT8_C(   174),  UINT8_C(    83),  UINT8_C(   100),  UINT8_C(   240),  UINT8_C(    31),  UINT8_C(    72),  UINT8_C(    42),  UINT8_C(   180),  UINT8_C(    12)  },
      {  UINT8_C(    87),  UINT8_C(   103),  UINT8_C(   201),  UINT8_C(   233),  UINT8_C(    29),  UINT8_C(   172),  UINT8_C(   138),  UINT8_C(    78),  UINT8_C(   179),  UINT8_C(    66),  UINT8_C(   163),  UINT8_C(   203),  UINT8_C(   132),  UINT8_C(    33),  UINT8_C(   173),  UINT8_C(    89)  },
      {  UINT8_C(    87),  UINT8_C(   103),  UINT8_C(   201),  UINT8_C(   233),  UINT8_C(    29),  UINT8_C(   172),  UINT8_C(   138),  UINT8_C(    78),  UINT8_C(   179),  UINT8_C(    66),  UINT8_C(   163),  UINT8_C(   203),  UINT8_C(   132),  UINT8_C(    33),  UINT8_C(   173),  UINT8_C(    89)  },
      {  UINT8_C(   186),  UINT8_C(    57),  UINT8_C(    72),  UINT8_C(    79),  UINT8_C(   239),  UINT8_C(    96),  UINT8_C(    84),  UINT8_C(   118),  UINT8_C(   155),  UINT8_C(    20),  UINT8_C(    24),  UINT8_C(    95),  UINT8_C(    32),  UINT8_C(    10),  UINT8_C(   108),  UINT8_C(   204)  },
      {  UINT8_C(   234),  UINT8_C(   233),  UINT8_C(    40),  UINT8_C(    47),  UINT8_C(   183),  UINT8_C(   152),  UINT8_C(    68),  UINT8_C(   206),  UINT8_C(   115),  UINT8_C(    68),  UINT8_C(   112),  UINT8_C(   127),  UINT8_C(   136),  UINT8_C(    42),  UINT8_C(   180),  UINT8_C(    44)  },
      {  UINT8_C(   234),  UINT8_C(   169),  UINT8_C(   136),  UINT8_C(   239),  UINT8_C(   215),  UINT8_C(    88),  UINT8_C(   100),  UINT8_C(    46),  UINT8_C(   211),  UINT8_C(   100),  UINT8_C(   240),  UINT8_C(   159),  UINT8_C(    72),  UINT8_C(   170),  UINT8_C(   180),  UINT8_C(   140)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);

    simde_uint8x16_t r0 = simde_vsliq_n_u8(a, b, 0);
    simde_uint8x16_t r3 = simde_vsliq_n_u8(a, b, 3);
    simde_uint8x16_t r5 = simde_vsliq_n_u8(a, b, 5);
    simde_uint8x16_t r7 = simde_vsliq_n_u8(a, b, 7);

    simde_test_arm_neon_assert_equal_u8x16(r0, simde_vld1q_u8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r7, simde_vld1q_u8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r0 = simde_vsliq_n_u8(a, b, 0);
    simde_uint8x16_t r3 = simde_vsliq_n_u8(a, b, 3);
    simde_uint8x16_t r5 = simde_vsliq_n_u8(a, b, 5);
    simde_uint8x16_t r7 = simde_vsliq_n_u8(a, b, 7);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r15[8];
  } test_vec[] = {
    { {  UINT16_C(  54932),  UINT16_C(   2052),  UINT16_C(  30900),  UINT16_C(   7957),  UINT16_C(  53988),  UINT16_C(  54164),  UINT16_C(  41244),  UINT16_C(  57663)  },
      {  UINT16_C(  22926),  UINT16_C(  51202),  UINT16_C(   3783),  UINT16_C(  62722),  UINT16_C(  47770),  UINT16_C(  44849),  UINT16_C(  38117),  UINT16_C(  19359)  },
      {  UINT16_C(  52340),  UINT16_C(  16404),  UINT16_C(  30268),  UINT16_C(  43029),  UINT16_C(  54484),  UINT16_C(  31116),  UINT16_C(  42796),  UINT16_C(  23807)  },
      {  UINT16_C(  25492),  UINT16_C(    132),  UINT16_C(  45556),  UINT16_C(  16533),  UINT16_C(  42660),  UINT16_C(  52308),  UINT16_C(  14684),  UINT16_C(  59391)  },
      {  UINT16_C(  14996),  UINT16_C(   2052),  UINT16_C(   7348),  UINT16_C(   2837),  UINT16_C(  27364),  UINT16_C(  51092),  UINT16_C(  38172),  UINT16_C(  32063)  },
      {  UINT16_C(  54932),  UINT16_C(  18436),  UINT16_C(  63668),  UINT16_C(  24341),  UINT16_C(  21220),  UINT16_C(  13204),  UINT16_C(  41244),  UINT16_C(  57663)  },
      {  UINT16_C(  22164),  UINT16_C(   2052),  UINT16_C(  63668),  UINT16_C(   7957),  UINT16_C(  21220),  UINT16_C(  54164),  UINT16_C(  41244),  UINT16_C(  57663)  } },
    { {  UINT16_C(  55983),  UINT16_C(   3761),  UINT16_C(  17325),  UINT16_C(   1501),  UINT16_C(  20550),  UINT16_C(  44898),  UINT16_C(   2169),  UINT16_C(  48672)  },
      {  UINT16_C(  59886),  UINT16_C(  11886),  UINT16_C(  50059),  UINT16_C(  39013),  UINT16_C(   4828),  UINT16_C(  28010),  UINT16_C(   2847),  UINT16_C(  15306)  },
      {  UINT16_C(  20343),  UINT16_C(  29553),  UINT16_C(   7261),  UINT16_C(  49965),  UINT16_C(  38630),  UINT16_C(  27474),  UINT16_C(  22777),  UINT16_C(  56912)  },
      {  UINT16_C(  31663),  UINT16_C(  39857),  UINT16_C(  58093),  UINT16_C(   6493),  UINT16_C(  46854),  UINT16_C(  23202),  UINT16_C(  51193),  UINT16_C(  62112)  },
      {  UINT16_C(  47791),  UINT16_C(  47793),  UINT16_C(  12205),  UINT16_C(  38365),  UINT16_C(  28742),  UINT16_C(  43874),  UINT16_C(  31865),  UINT16_C(  10784)  },
      {  UINT16_C(  55983),  UINT16_C(  52913),  UINT16_C(  25517),  UINT16_C(  42461),  UINT16_C(  36934),  UINT16_C(  20322),  UINT16_C(  59513),  UINT16_C(  24096)  },
      {  UINT16_C(  23215),  UINT16_C(   3761),  UINT16_C(  50093),  UINT16_C(  34269),  UINT16_C(  20550),  UINT16_C(  12130),  UINT16_C(  34937),  UINT16_C(  15904)  } },
    { {  UINT16_C(  17536),  UINT16_C(  59891),  UINT16_C(  42463),  UINT16_C(   3164),  UINT16_C(  10034),  UINT16_C(  15752),  UINT16_C(  13926),  UINT16_C(  51179)  },
      {  UINT16_C(  16067),  UINT16_C(  15431),  UINT16_C(  15067),  UINT16_C(  39231),  UINT16_C(  52443),  UINT16_C(  53059),  UINT16_C(  35282),  UINT16_C(   4686)  },
      {  UINT16_C(  63000),  UINT16_C(  57915),  UINT16_C(  55007),  UINT16_C(  51708),  UINT16_C(  26330),  UINT16_C(  31256),  UINT16_C(  20118),  UINT16_C(  37491)  },
      {  UINT16_C(  45248),  UINT16_C(   4595),  UINT16_C(  46815),  UINT16_C(  20444),  UINT16_C(  14066),  UINT16_C(  53448),  UINT16_C(  29862),  UINT16_C(  37803)  },
      {  UINT16_C(   3200),  UINT16_C(   7667),  UINT16_C(  28127),  UINT16_C(  64604),  UINT16_C(  28466),  UINT16_C(   3464),  UINT16_C(  19046),  UINT16_C(  15339)  },
      {  UINT16_C(  25728),  UINT16_C(  59891),  UINT16_C(  26079),  UINT16_C(  60508),  UINT16_C(  26418),  UINT16_C(  32136),  UINT16_C(  22118),  UINT16_C(  51179)  },
      {  UINT16_C(  50304),  UINT16_C(  59891),  UINT16_C(  42463),  UINT16_C(  35932),  UINT16_C(  42802),  UINT16_C(  48520),  UINT16_C(  13926),  UINT16_C(  18411)  } },
    { {  UINT16_C(  55903),  UINT16_C(  22857),  UINT16_C(  39133),  UINT16_C(  33408),  UINT16_C(  16011),  UINT16_C(    990),  UINT16_C(  21485),  UINT16_C(  53727)  },
      {  UINT16_C(  10331),  UINT16_C(   5549),  UINT16_C(  17252),  UINT16_C(  48442),  UINT16_C(   3492),  UINT16_C(  61577),  UINT16_C(  18795),  UINT16_C(  38317)  },
      {  UINT16_C(  17119),  UINT16_C(  44393),  UINT16_C(   6949),  UINT16_C(  59856),  UINT16_C(  27939),  UINT16_C(  33870),  UINT16_C(  19293),  UINT16_C(  44399)  },
      {  UINT16_C(   5855),  UINT16_C(  27465),  UINT16_C(  55581),  UINT16_C(  20096),  UINT16_C(  26891),  UINT16_C(   8798),  UINT16_C(  23277),  UINT16_C(  27487)  },
      {  UINT16_C(  28255),  UINT16_C(  46409),  UINT16_C(  37085),  UINT16_C(  60032),  UINT16_C(  37515),  UINT16_C(  10206),  UINT16_C(  45037),  UINT16_C(  46559)  },
      {  UINT16_C(  31327),  UINT16_C(  47433),  UINT16_C(  39133),  UINT16_C(  17024),  UINT16_C(  40587),  UINT16_C(   9182),  UINT16_C(  29677),  UINT16_C(  45535)  },
      {  UINT16_C(  55903),  UINT16_C(  55625),  UINT16_C(   6365),  UINT16_C(    640),  UINT16_C(  16011),  UINT16_C(  33758),  UINT16_C(  54253),  UINT16_C(  53727)  } },
    { {  UINT16_C(  30910),  UINT16_C(  36057),  UINT16_C(  28028),  UINT16_C(  65285),  UINT16_C(  30944),  UINT16_C(  29925),  UINT16_C(  64087),  UINT16_C(  51797)  },
      {  UINT16_C(  21033),  UINT16_C(  43881),  UINT16_C(  63534),  UINT16_C(  35658),  UINT16_C(  41153),  UINT16_C(  27208),  UINT16_C(  27863),  UINT16_C(  40336)  },
      {  UINT16_C(  37198),  UINT16_C(  23369),  UINT16_C(  49524),  UINT16_C(  23125),  UINT16_C(   1544),  UINT16_C(  21061),  UINT16_C(  26303),  UINT16_C(  60549)  },
      {  UINT16_C(  35454),  UINT16_C(  55897),  UINT16_C(   3004),  UINT16_C(  53893),  UINT16_C(  12384),  UINT16_C(  37413),  UINT16_C(  13783),  UINT16_C(  25621)  },
      {  UINT16_C(  42174),  UINT16_C(  42201),  UINT16_C(  47484),  UINT16_C(  11013),  UINT16_C(   1248),  UINT16_C(   8421),  UINT16_C(  24151),  UINT16_C(  16981)  },
      {  UINT16_C(  14526),  UINT16_C(  11481),  UINT16_C(  52604),  UINT16_C(  24325),  UINT16_C(  14560),  UINT16_C(   5349),  UINT16_C(  64087),  UINT16_C(   2645)  },
      {  UINT16_C(  63678),  UINT16_C(  36057),  UINT16_C(  28028),  UINT16_C(  32517),  UINT16_C(  63712),  UINT16_C(  29925),  UINT16_C(  64087),  UINT16_C(  19029)  } },
    { {  UINT16_C(   2698),  UINT16_C(  52795),  UINT16_C(  47428),  UINT16_C(  57027),  UINT16_C(  39964),  UINT16_C(  36120),  UINT16_C(  60475),  UINT16_C(  45338)  },
      {  UINT16_C(  21185),  UINT16_C(   2661),  UINT16_C(  53801),  UINT16_C(  24352),  UINT16_C(  21787),  UINT16_C(  30325),  UINT16_C(  60200),  UINT16_C(  19373)  },
      {  UINT16_C(  38410),  UINT16_C(  21291),  UINT16_C(  37196),  UINT16_C(  63747),  UINT16_C(  43228),  UINT16_C(  45992),  UINT16_C(  22851),  UINT16_C(  23914)  },
      {  UINT16_C(  45130),  UINT16_C(  39291),  UINT16_C(  35396),  UINT16_C(  51203),  UINT16_C(  18140),  UINT16_C(  40280),  UINT16_C(  51771),  UINT16_C(  60250)  },
      {  UINT16_C(   1674),  UINT16_C(  38459),  UINT16_C(  42308),  UINT16_C(  33475),  UINT16_C(  27676),  UINT16_C(  54552),  UINT16_C(  41019),  UINT16_C(  46362)  },
      {  UINT16_C(  10890),  UINT16_C(  44603),  UINT16_C(  14660),  UINT16_C(   7875),  UINT16_C(  31772),  UINT16_C(  44312),  UINT16_C(   3131),  UINT16_C(  45338)  },
      {  UINT16_C(  35466),  UINT16_C(  52795),  UINT16_C(  47428),  UINT16_C(  24259),  UINT16_C(  39964),  UINT16_C(  36120),  UINT16_C(  27707),  UINT16_C(  45338)  } },
    { {  UINT16_C(  20622),  UINT16_C(  35405),  UINT16_C(  42684),  UINT16_C(  64877),  UINT16_C(  29368),  UINT16_C(  10266),  UINT16_C(  24647),  UINT16_C(  64280)  },
      {  UINT16_C(  31576),  UINT16_C(  19446),  UINT16_C(  44288),  UINT16_C(  56822),  UINT16_C(  32174),  UINT16_C(  17103),  UINT16_C(  18667),  UINT16_C(  20678)  },
      {  UINT16_C(  56006),  UINT16_C(  24501),  UINT16_C(  26628),  UINT16_C(  61365),  UINT16_C(  60784),  UINT16_C(   5754),  UINT16_C(  18271),  UINT16_C(  34352)  },
      {  UINT16_C(  54798),  UINT16_C(  64909),  UINT16_C(  16444),  UINT16_C(  32173),  UINT16_C(  27576),  UINT16_C(  46042),  UINT16_C(  15047),  UINT16_C(  12696)  },
      {  UINT16_C(  24718),  UINT16_C(  55885),  UINT16_C(    700),  UINT16_C(  55661),  UINT16_C(  47800),  UINT16_C(  15386),  UINT16_C(  44103),  UINT16_C(   6936)  },
      {  UINT16_C(   4238),  UINT16_C(  51789),  UINT16_C(   1724),  UINT16_C(  56685),  UINT16_C(  53944),  UINT16_C(  59418),  UINT16_C(  24647),  UINT16_C(  56088)  },
      {  UINT16_C(  20622),  UINT16_C(   2637),  UINT16_C(   9916),  UINT16_C(  32109),  UINT16_C(  29368),  UINT16_C(  43034),  UINT16_C(  57415),  UINT16_C(  31512)  } },
    { {  UINT16_C(  47232),  UINT16_C(    355),  UINT16_C(  64050),  UINT16_C(  59843),  UINT16_C(   9532),  UINT16_C(  42900),  UINT16_C(  36704),  UINT16_C(  46935)  },
      {  UINT16_C(  18854),  UINT16_C(  61891),  UINT16_C(  57306),  UINT16_C(  15820),  UINT16_C(  62408),  UINT16_C(  25140),  UINT16_C(   4068),  UINT16_C(  24825)  },
      {  UINT16_C(  19760),  UINT16_C(  36379),  UINT16_C(  65234),  UINT16_C(  61027),  UINT16_C(  40516),  UINT16_C(   4516),  UINT16_C(  32544),  UINT16_C(   1999)  },
      {  UINT16_C(  27008),  UINT16_C(  28899),  UINT16_C(  63154),  UINT16_C(  29443),  UINT16_C(  62012),  UINT16_C(  36116),  UINT16_C(  63776),  UINT16_C(  15959)  },
      {  UINT16_C(  39040),  UINT16_C(   3427),  UINT16_C(  27186),  UINT16_C(  12739),  UINT16_C(   8508),  UINT16_C(  54164),  UINT16_C(  37728),  UINT16_C(  59223)  },
      {  UINT16_C(  55424),  UINT16_C(  24931),  UINT16_C(  23090),  UINT16_C(  35267),  UINT16_C(   1340),  UINT16_C(  34708),  UINT16_C(  36704),  UINT16_C(  14167)  },
      {  UINT16_C(  14464),  UINT16_C(  33123),  UINT16_C(  31282),  UINT16_C(  27075),  UINT16_C(   9532),  UINT16_C(  10132),  UINT16_C(   3936),  UINT16_C(  46935)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);

    simde_uint16x8_t r3 = simde_vsliq_n_u16(a, b, 3);
    simde_uint16x8_t r6 = simde_vsliq_n_u16(a, b, 6);
    simde_uint16x8_t r10 = simde_vsliq_n_u16(a, b, 10);
    simde_uint16x8_t r13 = simde_vsliq_n_u16(a, b, 13);
    simde_uint16x8_t r15 = simde_vsliq_n_u16(a, b, 15);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r15, simde_vld1q_u16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r3 = simde_vsliq_n_u16(a, b, 3);
    simde_uint16x8_t r6 = simde_vsliq_n_u16(a, b, 6);
    simde_uint16x8_t r10 = simde_vsliq_n_u16(a, b, 10);
    simde_uint16x8_t r13 = simde_vsliq_n_u16(a, b, 13);
    simde_uint16x8_t r15 = simde_vsliq_n_u16(a, b, 15);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r31[4];
  } test_vec[] = {
    { {  UINT32_C(3314104844),  UINT32_C( 896066203),  UINT32_C(1274783480),  UINT32_C(1259865211)  },
      {  UINT32_C(2546938802),  UINT32_C(2309454007),  UINT32_C(3677554301),  UINT32_C(1529066540)  },
      {  UINT32_C(4090293388),  UINT32_C(1776168411),  UINT32_C(3435241336),  UINT32_C(3370978107)  },
      {  UINT32_C(3866515980),  UINT32_C(4011254427),  UINT32_C(1624221432),  UINT32_C(1988461691)  },
      {  UINT32_C(2643540492),  UINT32_C(3317228187),  UINT32_C( 871081720),  UINT32_C(2707424379)  },
      {  UINT32_C(3381213708),  UINT32_C(3714638491),  UINT32_C(4160464632),  UINT32_C(3004695675)  },
      {  UINT32_C(1166621196),  UINT32_C(3043549851),  UINT32_C(3422267128),  UINT32_C(1259865211)  } },
    { {  UINT32_C(2519560084),  UINT32_C(4091206232),  UINT32_C(1216423209),  UINT32_C(2044064088)  },
      {  UINT32_C(3403746096),  UINT32_C( 188361982),  UINT32_C(1027264752),  UINT32_C( 342173962)  },
      {  UINT32_C(3091385364),  UINT32_C(3465232280),  UINT32_C(1320434729),  UINT32_C( 424297112)  },
      {  UINT32_C( 560336788),  UINT32_C(1168104024),  UINT32_C(1511916841),  UINT32_C(2770424152)  },
      {  UINT32_C(1501917076),  UINT32_C(1743968856),  UINT32_C(2273387817),  UINT32_C(1213591896)  },
      {  UINT32_C(3257757588),  UINT32_C(4225423960),  UINT32_C(3229689129),  UINT32_C( 701886808)  },
      {  UINT32_C( 372076436),  UINT32_C(1943722584),  UINT32_C(1216423209),  UINT32_C(2044064088)  } },
    { {  UINT32_C( 442898144),  UINT32_C(4213751943),  UINT32_C(3937589646),  UINT32_C(1647003042)  },
      {  UINT32_C(1900144466),  UINT32_C(2941186414),  UINT32_C( 465710967),  UINT32_C(3138196476)  },
      {  UINT32_C(1350161568),  UINT32_C(3552336775),  UINT32_C(4035698126),  UINT32_C(3276078882)  },
      {  UINT32_C(1021990624),  UINT32_C(3727540359),  UINT32_C(1173289358),  UINT32_C(2726266274)  },
      {  UINT32_C( 982914784),  UINT32_C(2339422343),  UINT32_C(2075842958),  UINT32_C(2682471842)  },
      {  UINT32_C(1248204512),  UINT32_C(3140010119),  UINT32_C(3736263054),  UINT32_C(4062922146)  },
      {  UINT32_C( 442898144),  UINT32_C(2066268295),  UINT32_C(3937589646),  UINT32_C(1647003042)  } },
    { {  UINT32_C(2089720617),  UINT32_C(1970686998),  UINT32_C( 778315975),  UINT32_C(2964826108)  },
      {  UINT32_C( 394207440),  UINT32_C(4261643434),  UINT32_C(2206406389),  UINT32_C(3380683517)  },
      {  UINT32_C(3754439721),  UINT32_C(2162240150),  UINT32_C(3771055431),  UINT32_C(1615380348)  },
      {  UINT32_C(3826916137),  UINT32_C(1888832534),  UINT32_C(1658759367),  UINT32_C( 610248700)  },
      {  UINT32_C( 109484841),  UINT32_C( 626412566),  UINT32_C(3081513159),  UINT32_C( 401582076)  },
      {  UINT32_C(1083087657),  UINT32_C(2843102230),  UINT32_C(3596888263),  UINT32_C(4105676796)  },
      {  UINT32_C(2089720617),  UINT32_C(1970686998),  UINT32_C(2925799623),  UINT32_C(2964826108)  } },
    { {  UINT32_C(4032337033),  UINT32_C(2722005257),  UINT32_C(3284061714),  UINT32_C(3943119414)  },
      {  UINT32_C(3606855119),  UINT32_C(4011542875),  UINT32_C(3628735594),  UINT32_C(1545447947)  },
      {  UINT32_C(3205460937),  UINT32_C(3335673545),  UINT32_C( 310844050),  UINT32_C( 124420854)  },
      {  UINT32_C(2277110921),  UINT32_C(1764450569),  UINT32_C(1133334034),  UINT32_C(3040967222)  },
      {  UINT32_C(4000879753),  UINT32_C(1256096009),  UINT32_C(3814116882),  UINT32_C(1348418102)  },
      {  UINT32_C(1012438153),  UINT32_C(1849590025),  UINT32_C(2881408530),  UINT32_C( 789002806)  },
      {  UINT32_C(4032337033),  UINT32_C(2722005257),  UINT32_C(1136578066),  UINT32_C(3943119414)  } },
    { {  UINT32_C(1857063657),  UINT32_C( 398218107),  UINT32_C(3397194281),  UINT32_C(2589095246)  },
      {  UINT32_C(  57471507),  UINT32_C(2562833446),  UINT32_C(3648520257),  UINT32_C(3804890585)  },
      {  UINT32_C(3678176489),  UINT32_C( 812583355),  UINT32_C(1577062505),  UINT32_C(2994828878)  },
      {  UINT32_C(2655152873),  UINT32_C( 931451771),  UINT32_C(    537129),  UINT32_C(1086010702)  },
      {  UINT32_C(2425916137),  UINT32_C(3778302843),  UINT32_C(  34411049),  UINT32_C( 785020238)  },
      {  UINT32_C(1320192745),  UINT32_C(2612810619),  UINT32_C( 108859945),  UINT32_C(1716680014)  },
      {  UINT32_C(4004547305),  UINT32_C( 398218107),  UINT32_C(3397194281),  UINT32_C(2589095246)  } },
    { {  UINT32_C(3089759757),  UINT32_C( 293828492),  UINT32_C(3325553807),  UINT32_C( 877656139)  },
      {  UINT32_C(1892709601),  UINT32_C(3829548036),  UINT32_C( 730099765),  UINT32_C(2664244870)  },
      {  UINT32_C( 874330189),  UINT32_C( 277938444),  UINT32_C(3776712015),  UINT32_C(3007947147)  },
      {  UINT32_C( 245120525),  UINT32_C(1216386956),  UINT32_C(2382802063),  UINT32_C(2765150283)  },
      {  UINT32_C(2802449933),  UINT32_C( 539195276),  UINT32_C(2175790223),  UINT32_C( 876083275)  },
      {  UINT32_C(2217344525),  UINT32_C( 293828492),  UINT32_C(3593989263),  UINT32_C( 407894091)  },
      {  UINT32_C(3089759757),  UINT32_C( 293828492),  UINT32_C(3325553807),  UINT32_C( 877656139)  } },
    { {  UINT32_C(3617356505),  UINT32_C(3366892416),  UINT32_C(2443525970),  UINT32_C(3678188135)  },
      {  UINT32_C(2074072819),  UINT32_C(1284524143),  UINT32_C(2431646596),  UINT32_C(4048530367)  },
      {  UINT32_C(3891641561),  UINT32_C( 605166528),  UINT32_C(1006559506),  UINT32_C(1407905767)  },
      {  UINT32_C(4208884441),  UINT32_C( 151909248),  UINT32_C(4285570898),  UINT32_C(4118278759)  },
      {  UINT32_C(3080485593),  UINT32_C(1132376960),  UINT32_C(3693428562),  UINT32_C(1576841831)  },
      {  UINT32_C(3483138777),  UINT32_C(3165565824),  UINT32_C( 296042322),  UINT32_C(4282167911)  },
      {  UINT32_C(3617356505),  UINT32_C(3366892416),  UINT32_C( 296042322),  UINT32_C(3678188135)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);

    simde_uint32x4_t r6 = simde_vsliq_n_u32(a, b, 6);
    simde_uint32x4_t r13 = simde_vsliq_n_u32(a, b, 13);
    simde_uint32x4_t r19 = simde_vsliq_n_u32(a, b, 19);
    simde_uint32x4_t r26 = simde_vsliq_n_u32(a, b, 26);
    simde_uint32x4_t r31 = simde_vsliq_n_u32(a, b, 31);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r31, simde_vld1q_u32(test_vec[i].r31));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r6 = simde_vsliq_n_u32(a, b, 6);
    simde_uint32x4_t r13 = simde_vsliq_n_u32(a, b, 13);
    simde_uint32x4_t r19 = simde_vsliq_n_u32(a, b, 19);
    simde_uint32x4_t r26 = simde_vsliq_n_u32(a, b, 26);
    simde_uint32x4_t r31 = simde_vsliq_n_u32(a, b, 31);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r13[2];
    uint64_t r26[2];
    uint64_t r39[2];
    uint64_t r52[2];
    uint64_t r63[2];
  } test_vec[] = {
    { {  UINT64_C( 3326354101924670590),  UINT64_C(15812941646549698216)  },
      {  UINT64_C(18151090002998169439),  UINT64_C( 1380667824062628123)  },
      {  UINT64_C(12972070462018022526),  UINT64_C( 2576697537094444712)  },
      {  UINT64_C(13955360284637015166),  UINT64_C( 5231003553959724712)  },
      {  UINT64_C( 7838427115654622334),  UINT64_C(  594630893316032168)  },
      {  UINT64_C(17724362110628146302),  UINT64_C( 1275322049397737128)  },
      {  UINT64_C(12549726138779446398),  UINT64_C(15812941646549698216)  } },
    { {  UINT64_C( 5869328896938516263),  UINT64_C( 2222189733952536719)  },
      {  UINT64_C(12411628851339405478),  UINT64_C(  942836641027284248)  },
      {  UINT64_C(16056959959070727975),  UINT64_C(12978740484919984271)  },
      {  UINT64_C(13330739158301581095),  UINT64_C(13255955676427108495)  },
      {  UINT64_C(  690267940543831847),  UINT64_C(15253283237737447567)  },
      {  UINT64_C( 9972108157473038119),  UINT64_C(15097981068604784783)  },
      {  UINT64_C( 5869328896938516263),  UINT64_C( 2222189733952536719)  } },
    { {  UINT64_C(15272376107936314541),  UINT64_C( 7392787741455680135)  },
      {  UINT64_C( 9420840874243141019),  UINT64_C( 6038106548576691917)  },
      {  UINT64_C(12797981472756823213),  UINT64_C( 8447984324952302215)  },
      {  UINT64_C( 8217653932499203245),  UINT64_C(12150569524748616327)  },
      {  UINT64_C( 6851890001671943341),  UINT64_C(17281269205359133319)  },
      {  UINT64_C(15686707273654400173),  UINT64_C( 7843147704192729735)  },
      {  UINT64_C(15272376107936314541),  UINT64_C(16616159778310455943)  } },
    { {  UINT64_C(17788547161097733072),  UINT64_C(10303315733532817032)  },
      {  UINT64_C( 9530739437947880088),  UINT64_C( 9539080515559423601)  },
      {  UINT64_C( 9196555730211242960),  UINT64_C( 3739687229137499784)  },
      {  UINT64_C( 1681744860744483792),  UINT64_C(13922618736527455880)  },
      {  UINT64_C(15582820183151182800),  UINT64_C(16320825774362506888)  },
      {  UINT64_C( 2994222385185653712),  UINT64_C(16653391208125216392)  },
      {  UINT64_C( 8565175124242957264),  UINT64_C(10303315733532817032)  } },
    { {  UINT64_C(11269734078394947120),  UINT64_C(11079511464515323691)  },
      {  UINT64_C( 4631258017608531081),  UINT64_C( 2950484057785924872)  },
      {  UINT64_C(12759864702248498736),  UINT64_C( 5130664822783936299)  },
      {  UINT64_C( 9559719181400167984),  UINT64_C( 8723228335687976747)  },
      {  UINT64_C( 6790941082614519344),  UINT64_C(16446728547236431659)  },
      {  UINT64_C(14453779014945887792),  UINT64_C(15024664738091878187)  },
      {  UINT64_C(11269734078394947120),  UINT64_C( 1856139427660547883)  } },
    { {  UINT64_C( 7998503011676121860),  UINT64_C(12436442786690204518)  },
      {  UINT64_C(10507257933463575756),  UINT64_C(  890983024616133747)  },
      {  UINT64_C( 2949143004844755716),  UINT64_C(12469028540094767974)  },
      {  UINT64_C(12591503202443651844),  UINT64_C( 6659864326580700006)  },
      {  UINT64_C(13848118176700230404),  UINT64_C(10586337451585012582)  },
      {  UINT64_C(14753902452731865860),  UINT64_C( 5131604191095260006)  },
      {  UINT64_C( 7998503011676121860),  UINT64_C(12436442786690204518)  } },
    { {  UINT64_C(10515578012670966780),  UINT64_C(17680525830101447828)  },
      {  UINT64_C(11288336922296194998),  UINT64_C(16689682725274606802)  },
      {  UINT64_C(  528025944447179772),  UINT64_C(13060555188091901076)  },
      {  UINT64_C( 9050423663222406140),  UINT64_C(  952473333433152660)  },
      {  UINT64_C( 3606217256912632828),  UINT64_C(18135548271896081556)  },
      {  UINT64_C( 8894282146817588220),  UINT64_C(14784711269702218900)  },
      {  UINT64_C( 1292205975816190972),  UINT64_C( 8457153793246672020)  } },
    { {  UINT64_C( 2303077286822012679),  UINT64_C(  138581218363046567)  },
      {  UINT64_C(18411670028825252116),  UINT64_C( 8225054175440624625)  },
      {  UINT64_C( 7821329487171323655),  UINT64_C(12134448022314433191)  },
      {  UINT64_C( 6788990914251187975),  UINT64_C(14341129652734655143)  },
      {  UINT64_C(16926931031184631559),  UINT64_C(13667854094844426919)  },
      {  UINT64_C( 1244731374389946119),  UINT64_C(13770977290413537959)  },
      {  UINT64_C( 2303077286822012679),  UINT64_C( 9361953255217822375)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);

    simde_uint64x2_t r13 = simde_vsliq_n_u64(a, b, 13);
    simde_uint64x2_t r26 = simde_vsliq_n_u64(a, b, 26);
    simde_uint64x2_t r39 = simde_vsliq_n_u64(a, b, 39);
    simde_uint64x2_t r52 = simde_vsliq_n_u64(a, b, 52);
    simde_uint64x2_t r63 = simde_vsliq_n_u64(a, b, 63);

    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r39, simde_vld1q_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x2(r52, simde_vld1q_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x2(r63, simde_vld1q_u64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r13 = simde_vsliq_n_u64(a, b, 13);
    simde_uint64x2_t r26 = simde_vsliq_n_u64(a, b, 26);
    simde_uint64x2_t r39 = simde_vsliq_n_u64(a, b, 39);
    simde_uint64x2_t r52 = simde_vsliq_n_u64(a, b, 52);
    simde_uint64x2_t r63 = simde_vsliq_n_u64(a, b, 63);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vslid_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a;
    int64_t b;
    int64_t r13;
    int64_t r26;
    int64_t r39;
    int64_t r52;
    int64_t r63;
  } test_vec[] = {
    { -INT64_C( 4403672992202505812),
      -INT64_C( 1230496034501682882),
      -INT64_C( 8301250392370986580),
      -INT64_C( 9144558609705090644),
       INT64_C(    3552791725982124),
      -INT64_C( 7790379911985118804),
       INT64_C( 4819699044652269996) },
    { -INT64_C( 3907786404754124187),
       INT64_C( 7915678331130018259),
       INT64_C( 4931469528035652197),
       INT64_C(  228852244148621925),
      -INT64_C( 6810311284617670043),
      -INT64_C( 7118852939069287835),
      -INT64_C( 3907786404754124187) },
    { -INT64_C( 7546561803657959031),
      -INT64_C( 5215796123490493360),
      -INT64_C( 5142568922800060023),
       INT64_C( 4438848774528280969),
       INT64_C( 4516591482021325193),
      -INT64_C( 4249926876422755959),
       INT64_C( 1676810233196816777) },
    {  INT64_C( 3478031672116439332),
      -INT64_C( 8079927811897769318),
      -INT64_C( 3850898596655052508),
      -INT64_C( 2628937754841519836),
      -INT64_C( 8907753509524412124),
       INT64_C( 3000650111615166756),
       INT64_C( 3478031672116439332) },
    {  INT64_C( 7801976851260586890),
       INT64_C( 4148771054844773256),
       INT64_C( 7829897515388443530),
       INT64_C( 3191301773980941194),
       INT64_C( 4107779959898323850),
       INT64_C( 4072996359797816202),
       INT64_C( 7801976851260586890) },
    {  INT64_C( 5698065473092539665),
      -INT64_C( 6783390212694855361),
      -INT64_C( 7939472383085644527),
       INT64_C( 3061841662278456593),
      -INT64_C( 4965042823300033263),
       INT64_C( 1437660225600050449),
      -INT64_C( 3525306563762236143) },
    {  INT64_C( 4286310312536331710),
       INT64_C( 2689930727598008905),
      -INT64_C( 7946647600025225794),
      -INT64_C(  377303285623532098),
       INT64_C( 8184488051327784382),
      -INT64_C( 6585379187936045634),
      -INT64_C( 4937061724318444098) },
    {  INT64_C( 7214605044141401542),
       INT64_C( 5142768677345030141),
      -INT64_C( 2802459542128974394),
       INT64_C( 8447802647868220870),
      -INT64_C( 7784473535874193978),
      -INT64_C(    9168758160874042),
      -INT64_C( 2008766992713374266) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r13 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 13);
    int64_t r26 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 26);
    int64_t r39 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 39);
    int64_t r52 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 52);
    int64_t r63 = simde_vslid_n_s64(test_vec[i].a, test_vec[i].b, 63);

    simde_assert_equal_i64(r13, test_vec[i].r13);
    simde_assert_equal_i64(r26, test_vec[i].r26);
    simde_assert_equal_i64(r39, test_vec[i].r39);
    simde_assert_equal_i64(r52, test_vec[i].r52);
    simde_assert_equal_i64(r63, test_vec[i].r63);
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    int64_t r13 = simde_vslid_n_s64(a, b, 13);
    int64_t r26 = simde_vslid_n_s64(a, b, 26);
    int64_t r39 = simde_vslid_n_s64(a, b, 39);
    int64_t r52 = simde_vslid_n_s64(a, b, 52);
    int64_t r63 = simde_vslid_n_s64(a, b, 63);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vslid_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a;
    uint64_t b;
    uint64_t r13;
    uint64_t r26;
    uint64_t r39;
    uint64_t r52;
    uint64_t r63;
  } test_vec[] = {
    { UINT64_C(16047323941614028429),
      UINT64_C( 5759110669390432380),
      UINT64_C(10310007171098576525),
      UINT64_C(10384376197257004685),
      UINT64_C(10872883682835072653),
      UINT64_C( 9782816859941668493),
      UINT64_C( 6823951904759252621) },
    { UINT64_C( 6252747629803370157),
      UINT64_C( 9603497943463504180),
      UINT64_C(14938422555498157741),
      UINT64_C(18304133725414782637),
      UINT64_C(12327647779556456109),
      UINT64_C(10612232069098010285),
      UINT64_C( 6252747629803370157) },
    { UINT64_C( 9127216911202849255),
      UINT64_C( 5473098671353457008),
      UINT64_C(10036216613309387239),
      UINT64_C(17994903780703801831),
      UINT64_C( 6319878951979127271),
      UINT64_C(10883620765877342695),
      UINT64_C( 9127216911202849255) },
    { UINT64_C(17366484507887084631),
      UINT64_C(13169929079093652159),
      UINT64_C(11499672881740637271),
      UINT64_C(16245006858353321047),
      UINT64_C( 4284435786980336727),
      UINT64_C(12390006919642686551),
      UINT64_C(17366484507887084631) },
    { UINT64_C(11977100683987906951),
      UINT64_C(15640438591829181941),
      UINT64_C(13835352351822492039),
      UINT64_C( 2410877258336039303),
      UINT64_C(11890341519974986119),
      UINT64_C( 6870018706549764487),
      UINT64_C(11977100683987906951) },
    { UINT64_C(16622456104105027770),
      UINT64_C(12751574988462635335),
      UINT64_C(15437360142427416762),
      UINT64_C(10423661486465624250),
      UINT64_C(  656579698565064890),
      UINT64_C(10700222594112825530),
      UINT64_C(16622456104105027770) },
    { UINT64_C( 6364346099977397255),
      UINT64_C( 5145566249440208637),
      UINT64_C( 1668506987863712775),
      UINT64_C(17818630034471756807),
      UINT64_C( 1131387083589133319),
      UINT64_C( 8057699559868703751),
      UINT64_C(15587718136832173063) },
    { UINT64_C(14133761816967247706),
      UINT64_C(14840253816082545319),
      UINT64_C( 7315815602266109786),
      UINT64_C(16136662355303987034),
      UINT64_C( 2169982941962172250),
      UINT64_C(12282782370117973850),
      UINT64_C(14133761816967247706) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r13 = simde_vslid_n_u64(test_vec[i].a, test_vec[i].b, 13);
    uint64_t r26 = simde_vslid_n_u64(test_vec[i].a, test_vec[i].b, 26);
    uint64_t r39 = simde_vslid_n_u64(test_vec[i].a, test_vec[i].b, 39);
    uint64_t r52 = simde_vslid_n_u64(test_vec[i].a, test_vec[i].b, 52);
    uint64_t r63 = simde_vslid_n_u64(test_vec[i].a, test_vec[i].b, 63);

    simde_assert_equal_u64(r13, test_vec[i].r13);
    simde_assert_equal_u64(r26, test_vec[i].r26);
    simde_assert_equal_u64(r39, test_vec[i].r39);
    simde_assert_equal_u64(r52, test_vec[i].r52);
    simde_assert_equal_u64(r63, test_vec[i].r63);
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r13 = simde_vslid_n_u64(a, b, 13);
    uint64_t r26 = simde_vslid_n_u64(a, b, 26);
    uint64_t r39 = simde_vslid_n_u64(a, b, 39);
    uint64_t r52 = simde_vslid_n_u64(a, b, 52);
    uint64_t r63 = simde_vslid_n_u64(a, b, 63);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[8];
    simde_poly8_t b[8];
    simde_poly8_t r0[8];
    simde_poly8_t r3[8];
    simde_poly8_t r5[8];
    simde_poly8_t r7[8];
  } test_vec[] = {
    { {  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(    53),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   214),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(   217)  },
      {  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   250),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    65),  SIMDE_POLY8_C(    28)  },
      {  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   250),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    65),  SIMDE_POLY8_C(    28)  },
      {  SIMDE_POLY8_C(   154),  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(   237),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(   225)  },
      {  SIMDE_POLY8_C(    98),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(    40),  SIMDE_POLY8_C(   153)  },
      {  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(    25),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   214),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(    89)  } },
    { {  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(   160),  SIMDE_POLY8_C(   251)  },
      {  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(   189)  },
      {  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(   189)  },
      {  SIMDE_POLY8_C(   157),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(    82),  SIMDE_POLY8_C(   143),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   112),  SIMDE_POLY8_C(   235)  },
      {  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(    82),  SIMDE_POLY8_C(    63),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   187)  },
      {  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   251)  } },
    { {  SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(     9),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    77)  },
      {  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    34),  SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(   133)  },
      {  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    34),  SIMDE_POLY8_C(     2),  SIMDE_POLY8_C(   133)  },
      {  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(   227),  SIMDE_POLY8_C(    57),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(    19),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(    45)  },
      {  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(    27),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    90),  SIMDE_POLY8_C(   173)  },
      {  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(    17),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    90),  SIMDE_POLY8_C(   205)  } },
    { {  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(   133)  },
      {  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   177)  },
      {  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   177)  },
      {  SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(   207),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   141)  },
      {  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   199),  SIMDE_POLY8_C(   244),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(    37)  },
      {  SIMDE_POLY8_C(   230),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(   133)  } },
    { {  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(   134)  },
      {  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(    97)  },
      {  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(    97)  },
      {  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(    23),  SIMDE_POLY8_C(     6),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(    93),  SIMDE_POLY8_C(    14)  },
      {  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(     6),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(    38)  },
      {  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    70),  SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(   133),  SIMDE_POLY8_C(   134)  } },
    { {  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   255)  },
      {  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(   226),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(    64)  },
      {  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(   226),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(    64)  },
      {  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(    12),  SIMDE_POLY8_C(     7)  },
      {  SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   158),  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   123),  SIMDE_POLY8_C(    19),  SIMDE_POLY8_C(    44),  SIMDE_POLY8_C(    31)  },
      {  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   127)  } },
    { {  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   165),  SIMDE_POLY8_C(    74)  },
      {  SIMDE_POLY8_C(    27),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(    63),  SIMDE_POLY8_C(   133),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   152)  },
      {  SIMDE_POLY8_C(    27),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(    63),  SIMDE_POLY8_C(   133),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   152)  },
      {  SIMDE_POLY8_C(   221),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(    44),  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   194)  },
      {  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   165),  SIMDE_POLY8_C(    10)  },
      {  SIMDE_POLY8_C(   133),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(   214),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(   150),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(   165),  SIMDE_POLY8_C(    74)  } },
    { {  SIMDE_POLY8_C(   250),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(   140),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    19),  SIMDE_POLY8_C(    34)  },
      {  SIMDE_POLY8_C(   170),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   134),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   119),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(     7)  },
      {  SIMDE_POLY8_C(   170),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   134),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   119),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(     7)  },
      {  SIMDE_POLY8_C(    82),  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(   165),  SIMDE_POLY8_C(   191),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(    58)  },
      {  SIMDE_POLY8_C(    90),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    76),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   141),        SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(    51),  SIMDE_POLY8_C(   226)  },
      {  SIMDE_POLY8_C(   122),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(    12),  SIMDE_POLY8_C(    64),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   147),  SIMDE_POLY8_C(   162)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t a = simde_vld1_p8(test_vec[i].a);
    simde_poly8x8_t b = simde_vld1_p8(test_vec[i].b);

    simde_poly8x8_t r0 = simde_vsli_n_p8(a, b, 0);
    simde_poly8x8_t r3 = simde_vsli_n_p8(a, b, 3);
    simde_poly8x8_t r5 = simde_vsli_n_p8(a, b, 5);
    simde_poly8x8_t r7 = simde_vsli_n_p8(a, b, 7);

    simde_test_arm_neon_assert_equal_p8x8(r0, simde_vld1_p8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_p8x8(r3, simde_vld1_p8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_p8x8(r5, simde_vld1_p8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_p8x8(r7, simde_vld1_p8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8_t a = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t b = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t r0 = simde_vsli_n_p8(a, b, 0);
    simde_poly8x8_t r3 = simde_vsli_n_p8(a, b, 3);
    simde_poly8x8_t r5 = simde_vsli_n_p8(a, b, 5);
    simde_poly8x8_t r7 = simde_vsli_n_p8(a, b, 7);

    simde_test_arm_neon_write_p8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[4];
    simde_poly16_t b[4];
    simde_poly16_t r3[4];
    simde_poly16_t r6[4];
    simde_poly16_t r10[4];
    simde_poly16_t r13[4];
    simde_poly16_t r15[4];
  } test_vec[] = {
    { {  SIMDE_POLY16_C(  15391),  SIMDE_POLY16_C(   8013),  SIMDE_POLY16_C(   1254),  SIMDE_POLY16_C(  45654)  },
      {  SIMDE_POLY16_C(  35066),  SIMDE_POLY16_C(  48548),  SIMDE_POLY16_C(  14346),  SIMDE_POLY16_C(   1393)  },
      {  SIMDE_POLY16_C(  18391),  SIMDE_POLY16_C(  60709),  SIMDE_POLY16_C(  49238),  SIMDE_POLY16_C(  11150)  },
      {  SIMDE_POLY16_C(  16031),  SIMDE_POLY16_C(  26893),  SIMDE_POLY16_C(    678),  SIMDE_POLY16_C(  23638)  },
      {  SIMDE_POLY16_C(  59423),  SIMDE_POLY16_C(  37709),  SIMDE_POLY16_C(  10470),  SIMDE_POLY16_C(  50774)  },
      {  SIMDE_POLY16_C(  23583),  SIMDE_POLY16_C(  40781),  SIMDE_POLY16_C(  17638),  SIMDE_POLY16_C(  12886)  },
      {  SIMDE_POLY16_C(  15391),  SIMDE_POLY16_C(   8013),  SIMDE_POLY16_C(   1254),  SIMDE_POLY16_C(  45654)  } },
    { {  SIMDE_POLY16_C(  23736),  SIMDE_POLY16_C(   7291),  SIMDE_POLY16_C(  61578),  SIMDE_POLY16_C(   8940)  },
      {  SIMDE_POLY16_C(  15242),  SIMDE_POLY16_C(  20311),  SIMDE_POLY16_C(  19232),  SIMDE_POLY16_C(   4411)  },
      {  SIMDE_POLY16_C(  56400),  SIMDE_POLY16_C(  31419),  SIMDE_POLY16_C(  22786),  SIMDE_POLY16_C(  35292)  },
      {  SIMDE_POLY16_C(  58040),  SIMDE_POLY16_C(  54779),  SIMDE_POLY16_C(  51210),  SIMDE_POLY16_C(  20204)  },
      {  SIMDE_POLY16_C(  10424),  SIMDE_POLY16_C(  23675),  SIMDE_POLY16_C(  32906),  SIMDE_POLY16_C(  61164)  },
      {  SIMDE_POLY16_C(  23736),  SIMDE_POLY16_C(  64635),  SIMDE_POLY16_C(   4234),  SIMDE_POLY16_C(  25324)  },
      {  SIMDE_POLY16_C(  23736),  SIMDE_POLY16_C(  40059),  SIMDE_POLY16_C(  28810),  SIMDE_POLY16_C(  41708)  } },
    { {  SIMDE_POLY16_C(  47025),  SIMDE_POLY16_C(  52193),  SIMDE_POLY16_C(  31710),  SIMDE_POLY16_C(  14843)  },
      {  SIMDE_POLY16_C(  54022),  SIMDE_POLY16_C(  30364),  SIMDE_POLY16_C(  65371),  SIMDE_POLY16_C(  28567)  },
      {  SIMDE_POLY16_C(  38961),  SIMDE_POLY16_C(  46305),  SIMDE_POLY16_C(  64222),  SIMDE_POLY16_C(  31931)  },
      {  SIMDE_POLY16_C(  49585),  SIMDE_POLY16_C(  42785),  SIMDE_POLY16_C(  55006),  SIMDE_POLY16_C(  58875)  },
      {  SIMDE_POLY16_C(   7089),  SIMDE_POLY16_C(  29665),  SIMDE_POLY16_C(  28638),  SIMDE_POLY16_C(  24059)  },
      {  SIMDE_POLY16_C(  55217),  SIMDE_POLY16_C(  35809),  SIMDE_POLY16_C(  31710),  SIMDE_POLY16_C(  63995)  },
      {  SIMDE_POLY16_C(  14257),  SIMDE_POLY16_C(  19425),  SIMDE_POLY16_C(  64478),  SIMDE_POLY16_C(  47611)  } },
    { {  SIMDE_POLY16_C(  54568),  SIMDE_POLY16_C(  15862),  SIMDE_POLY16_C(  52509),  SIMDE_POLY16_C(  47425)  },
      {  SIMDE_POLY16_C(   1779),  SIMDE_POLY16_C(  31523),  SIMDE_POLY16_C(  16426),  SIMDE_POLY16_C(  60116)  },
      {  SIMDE_POLY16_C(  14232),  SIMDE_POLY16_C(  55582),  SIMDE_POLY16_C(    341),  SIMDE_POLY16_C(  22177)  },
      {  SIMDE_POLY16_C(  48360),  SIMDE_POLY16_C(  51446),  SIMDE_POLY16_C(   2717),  SIMDE_POLY16_C(  46337)  },
      {  SIMDE_POLY16_C(  52520),  SIMDE_POLY16_C(  36342),  SIMDE_POLY16_C(  43293),  SIMDE_POLY16_C(  20801)  },
      {  SIMDE_POLY16_C(  29992),  SIMDE_POLY16_C(  32246),  SIMDE_POLY16_C(  19741),  SIMDE_POLY16_C(  39233)  },
      {  SIMDE_POLY16_C(  54568),  SIMDE_POLY16_C(  48630),  SIMDE_POLY16_C(  19741),  SIMDE_POLY16_C(  14657)  } },
    { {  SIMDE_POLY16_C(  19021),  SIMDE_POLY16_C(   2955),  SIMDE_POLY16_C(  23434),  SIMDE_POLY16_C(  24652)  },
      {  SIMDE_POLY16_C(  64304),  SIMDE_POLY16_C(  33123),  SIMDE_POLY16_C(  28656),  SIMDE_POLY16_C(   7738)  },
      {  SIMDE_POLY16_C(  55685),  SIMDE_POLY16_C(   2843),  SIMDE_POLY16_C(  32642),  SIMDE_POLY16_C(  61908)  },
      {  SIMDE_POLY16_C(  52237),  SIMDE_POLY16_C(  22731),  SIMDE_POLY16_C(  64522),  SIMDE_POLY16_C(  36492)  },
      {  SIMDE_POLY16_C(  49741),  SIMDE_POLY16_C(  36747),  SIMDE_POLY16_C(  50058),  SIMDE_POLY16_C(  59468)  },
      {  SIMDE_POLY16_C(   2637),  SIMDE_POLY16_C(  27531),  SIMDE_POLY16_C(   7050),  SIMDE_POLY16_C(  16460)  },
      {  SIMDE_POLY16_C(  19021),  SIMDE_POLY16_C(  35723),  SIMDE_POLY16_C(  23434),  SIMDE_POLY16_C(  24652)  } },
    { {  SIMDE_POLY16_C(  35638),  SIMDE_POLY16_C(  64110),  SIMDE_POLY16_C(  55906),  SIMDE_POLY16_C(  20848)  },
      {  SIMDE_POLY16_C(  27670),  SIMDE_POLY16_C(  29508),  SIMDE_POLY16_C(  17746),  SIMDE_POLY16_C(  25076)  },
      {  SIMDE_POLY16_C(  24758),  SIMDE_POLY16_C(  39462),  SIMDE_POLY16_C(  10898),  SIMDE_POLY16_C(   4000)  },
      {  SIMDE_POLY16_C(   1462),  SIMDE_POLY16_C(  53550),  SIMDE_POLY16_C(  21666),  SIMDE_POLY16_C(  32048)  },
      {  SIMDE_POLY16_C(  23350),  SIMDE_POLY16_C(   4718),  SIMDE_POLY16_C(  19042),  SIMDE_POLY16_C(  53616)  },
      {  SIMDE_POLY16_C(  52022),  SIMDE_POLY16_C(  39534),  SIMDE_POLY16_C(  23138),  SIMDE_POLY16_C(  37232)  },
      {  SIMDE_POLY16_C(   2870),  SIMDE_POLY16_C(  31342),  SIMDE_POLY16_C(  23138),  SIMDE_POLY16_C(  20848)  } },
    { {  SIMDE_POLY16_C(  23800),  SIMDE_POLY16_C(  37832),  SIMDE_POLY16_C(  34512),  SIMDE_POLY16_C(  33446)  },
      {  SIMDE_POLY16_C(  19904),  SIMDE_POLY16_C(  51885),  SIMDE_POLY16_C(  10602),  SIMDE_POLY16_C(  42147)  },
      {  SIMDE_POLY16_C(  28160),  SIMDE_POLY16_C(  21864),  SIMDE_POLY16_C(  19280),  SIMDE_POLY16_C(   9502)  },
      {  SIMDE_POLY16_C(  28728),  SIMDE_POLY16_C(  43848),  SIMDE_POLY16_C(  23184),  SIMDE_POLY16_C(  10470)  },
      {  SIMDE_POLY16_C(    248),  SIMDE_POLY16_C(  47048),  SIMDE_POLY16_C(  43728),  SIMDE_POLY16_C(  36518)  },
      {  SIMDE_POLY16_C(   7416),  SIMDE_POLY16_C(  46024),  SIMDE_POLY16_C(  18128),  SIMDE_POLY16_C(  25254)  },
      {  SIMDE_POLY16_C(  23800),  SIMDE_POLY16_C(  37832),  SIMDE_POLY16_C(   1744),  SIMDE_POLY16_C(  33446)  } },
    { {  SIMDE_POLY16_C(  32311),  SIMDE_POLY16_C(  55845),  SIMDE_POLY16_C(  55299),  SIMDE_POLY16_C(  15525)  },
      {  SIMDE_POLY16_C(  16152),  SIMDE_POLY16_C(  36439),  SIMDE_POLY16_C(  64155),  SIMDE_POLY16_C(  41506)  },
      {  SIMDE_POLY16_C(  63687),  SIMDE_POLY16_C(  29373),  SIMDE_POLY16_C(  54491),  SIMDE_POLY16_C(   4373)  },
      {  SIMDE_POLY16_C(  50743),  SIMDE_POLY16_C(  38373),  SIMDE_POLY16_C(  42691),  SIMDE_POLY16_C(  34981)  },
      {  SIMDE_POLY16_C(  25143),  SIMDE_POLY16_C(  24101),  SIMDE_POLY16_C(  27651),  SIMDE_POLY16_C(  34981)  },
      {  SIMDE_POLY16_C(   7735),  SIMDE_POLY16_C(  64037),  SIMDE_POLY16_C(  30723),  SIMDE_POLY16_C(  23717)  },
      {  SIMDE_POLY16_C(  32311),  SIMDE_POLY16_C(  55845),  SIMDE_POLY16_C(  55299),  SIMDE_POLY16_C(  15525)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t a = simde_vld1_p16(test_vec[i].a);
    simde_poly16x4_t b = simde_vld1_p16(test_vec[i].b);

    simde_poly16x4_t r3 = simde_vsli_n_p16(a, b, 3);
    simde_poly16x4_t r6 = simde_vsli_n_p16(a, b, 6);
    simde_poly16x4_t r10 = simde_vsli_n_p16(a, b, 10);
    simde_poly16x4_t r13 = simde_vsli_n_p16(a, b, 13);
    simde_poly16x4_t r15 = simde_vsli_n_p16(a, b, 15);

    simde_test_arm_neon_assert_equal_p16x4(r3, simde_vld1_p16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_p16x4(r6, simde_vld1_p16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_p16x4(r10, simde_vld1_p16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_p16x4(r13, simde_vld1_p16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_p16x4(r15, simde_vld1_p16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x4_t a = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t b = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t r3 = simde_vsli_n_p16(a, b, 3);
    simde_poly16x4_t r6 = simde_vsli_n_p16(a, b, 6);
    simde_poly16x4_t r10 = simde_vsli_n_p16(a, b, 10);
    simde_poly16x4_t r13 = simde_vsli_n_p16(a, b, 13);
    simde_poly16x4_t r15 = simde_vsli_n_p16(a, b, 15);

    simde_test_arm_neon_write_p16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsli_n_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly64_t a[1];
    simde_poly64_t b[1];
    simde_poly64_t r13[1];
    simde_poly64_t r26[1];
    simde_poly64_t r39[1];
    simde_poly64_t r52[1];
    simde_poly64_t r63[1];
  } test_vec[] = {
    { {  SIMDE_POLY64_C( 2367438358383478378)  },
      {  SIMDE_POLY64_C(10151069329549398822)  },
      {  SIMDE_POLY64_C(18084407459726018154)  },
      {  SIMDE_POLY64_C( 1664254114169931370)  },
      {  SIMDE_POLY64_C( 1425832543274714730)  },
      {  SIMDE_POLY64_C( 3632949853674587754)  },
      {  SIMDE_POLY64_C( 2367438358383478378)  } },
    { {  SIMDE_POLY64_C( 4289360236958653475)  },
      {  SIMDE_POLY64_C( 9003445777938185491)  },
      {  SIMDE_POLY64_C( 6145006178828188707)  },
      {  SIMDE_POLY64_C(17172783880833014819)  },
      {  SIMDE_POLY64_C( 4575245904564132899)  },
      {  SIMDE_POLY64_C(15075481344510991395)  },
      {  SIMDE_POLY64_C(13512732273813429283)  } },
    { {  SIMDE_POLY64_C( 4661840731346591672)  },
      {  SIMDE_POLY64_C(16008367045675390461)  },
      {  SIMDE_POLY64_C( 2639218171596226488)  },
      {  SIMDE_POLY64_C(  891207328682762168)  },
      {  SIMDE_POLY64_C(14306527482023272376)  },
      {  SIMDE_POLY64_C( 6904633345777098680)  },
      {  SIMDE_POLY64_C(13885212768201367480)  } },
    { {  SIMDE_POLY64_C(  560855986095228110)  },
      {  SIMDE_POLY64_C(12519105941898633195)  },
      {  SIMDE_POLY64_C(11065570282205701326)  },
      {  SIMDE_POLY64_C( 1851373620381320398)  },
      {  SIMDE_POLY64_C( 3229069440521569486)  },
      {  SIMDE_POLY64_C(18354578113836057806)  },
      {  SIMDE_POLY64_C( 9784228022950003918)  } },
    { {  SIMDE_POLY64_C(15210706800944352878)  },
      {  SIMDE_POLY64_C( 2343987333079752503)  },
      {  SIMDE_POLY64_C(17330395931398827630)  },
      {  SIMDE_POLY64_C( 4461078750471655022)  },
      {  SIMDE_POLY64_C( 2157113990720261742)  },
      {  SIMDE_POLY64_C(17543571407922269806)  },
      {  SIMDE_POLY64_C(15210706800944352878)  } },
    { {  SIMDE_POLY64_C( 3102245097986106578)  },
      {  SIMDE_POLY64_C(11620068368410445742)  },
      {  SIMDE_POLY64_C( 6400653677085181138)  },
      {  SIMDE_POLY64_C( 8508265199309464786)  },
      {  SIMDE_POLY64_C( 7909402293599511762)  },
      {  SIMDE_POLY64_C( 8857845421765600466)  },
      {  SIMDE_POLY64_C( 3102245097986106578)  } },
    { {  SIMDE_POLY64_C(17038098246975051983)  },
      {  SIMDE_POLY64_C(18292780545233057134)  },
      {  SIMDE_POLY64_C(11556115806516271311)  },
      {  SIMDE_POLY64_C(17456844777586120911)  },
      {  SIMDE_POLY64_C( 7312358247877793999)  },
      {  SIMDE_POLY64_C( 6260984338677455055)  },
      {  SIMDE_POLY64_C( 7814726210120276175)  } },
    { {  SIMDE_POLY64_C( 1351949120307680797)  },
      {  SIMDE_POLY64_C(15139404553755458091)  },
      {  SIMDE_POLY64_C( 4541696815397172765)  },
      {  SIMDE_POLY64_C(16944259135176136221)  },
      {  SIMDE_POLY64_C(14068424518630069789)  },
      {  SIMDE_POLY64_C(11723739062141933085)  },
      {  SIMDE_POLY64_C(10575321157162456605)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x1_t a = simde_vld1_p64(test_vec[i].a);
    simde_poly64x1_t b = simde_vld1_p64(test_vec[i].b);

    simde_poly64x1_t r13 = simde_vsli_n_p64(a, b, 13);
    simde_poly64x1_t r26 = simde_vsli_n_p64(a, b, 26);
    simde_poly64x1_t r39 = simde_vsli_n_p64(a, b, 39);
    simde_poly64x1_t r52 = simde_vsli_n_p64(a, b, 52);
    simde_poly64x1_t r63 = simde_vsli_n_p64(a, b, 63);

    simde_test_arm_neon_assert_equal_p64x1(r13, simde_vld1_p64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_p64x1(r26, simde_vld1_p64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_p64x1(r39, simde_vld1_p64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_p64x1(r52, simde_vld1_p64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_p64x1(r63, simde_vld1_p64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x1_t a = simde_test_arm_neon_random_p64x1();
    simde_poly64x1_t b = simde_test_arm_neon_random_p64x1();
    simde_poly64x1_t r13 = simde_vsli_n_p64(a, b, 13);
    simde_poly64x1_t r26 = simde_vsli_n_p64(a, b, 26);
    simde_poly64x1_t r39 = simde_vsli_n_p64(a, b, 39);
    simde_poly64x1_t r52 = simde_vsli_n_p64(a, b, 52);
    simde_poly64x1_t r63 = simde_vsli_n_p64(a, b, 63);

    simde_test_arm_neon_write_p64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x1(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[16];
    simde_poly8_t b[16];
    simde_poly8_t r0[16];
    simde_poly8_t r3[16];
    simde_poly8_t r5[16];
    simde_poly8_t r7[16];
  } test_vec[] = {
    { {  SIMDE_POLY8_C(   244),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   119),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    73),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   242),  SIMDE_POLY8_C(   252),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(   128),  SIMDE_POLY8_C(    96)  },
      {  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(    52),  SIMDE_POLY8_C(   255),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(   117)  },
      {  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(    52),        SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(   117)  },
      {  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   170),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   221),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(   249),  SIMDE_POLY8_C(   177),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   106),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(   109),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(   168)  },
      {  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(   162),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   101),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   151),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   178),  SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   160)  },
      {  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   244),  SIMDE_POLY8_C(   197),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   119),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    73),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   242),  SIMDE_POLY8_C(   124),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(   128),  SIMDE_POLY8_C(   224)  } },
    { {  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(   208),  SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   150)  },
      {  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(     1),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(   122)  },
      {  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   223),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(     1),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(   122)  },
      {  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   185),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   122),        SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(     9),  SIMDE_POLY8_C(   200),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   126),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   214)  },
      {  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(    57),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(   123),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(    86)  },
      {  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(   235),  SIMDE_POLY8_C(    59),  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   199),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(    90),  SIMDE_POLY8_C(    22)  } },
    { {  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(    98),  SIMDE_POLY8_C(   126),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   135),  SIMDE_POLY8_C(   177),  SIMDE_POLY8_C(   214),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    59),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(    55)  },
      {  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   122),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(   130),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(   211),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(     9),  SIMDE_POLY8_C(   238),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(   141)  },
      {  SIMDE_POLY8_C(   110),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   122),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(   130),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(    56),  SIMDE_POLY8_C(   211),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(     9),  SIMDE_POLY8_C(   238),  SIMDE_POLY8_C(   204),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(   141)  },
      {  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(   210),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(    23),  SIMDE_POLY8_C(   137),  SIMDE_POLY8_C(   198),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(    73),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(    25),  SIMDE_POLY8_C(   111)  },
      {  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   126),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(   112),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(    57),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   150),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   183)  },
      {  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    98),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(   177),  SIMDE_POLY8_C(    86),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(    22),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(   217),  SIMDE_POLY8_C(   183)  } },
    { {  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   209),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(    50),  SIMDE_POLY8_C(   112),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   127)  },
      {  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    27),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   237),  SIMDE_POLY8_C(   120)  },
      {  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   224),  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   194),  SIMDE_POLY8_C(   193),  SIMDE_POLY8_C(    92),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    27),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(   102),  SIMDE_POLY8_C(   237),  SIMDE_POLY8_C(   120)  },
      {  SIMDE_POLY8_C(   244),  SIMDE_POLY8_C(     5),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(    93),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   236),  SIMDE_POLY8_C(    93),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(   226),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(   109),  SIMDE_POLY8_C(   199)  },
      {  SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(   117),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    45),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    48),  SIMDE_POLY8_C(   114),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(   192),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(    31)  },
      {  SIMDE_POLY8_C(    52),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(   245),  SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(    50),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   127)  } },
    { {  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(   205),  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(   108),  SIMDE_POLY8_C(   248),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   175),  SIMDE_POLY8_C(    43)  },
      {  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(    83),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(    24),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(   162),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(    29)  },
      {  SIMDE_POLY8_C(   141),  SIMDE_POLY8_C(    83),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(    37),  SIMDE_POLY8_C(    24),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(   162),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   153),  SIMDE_POLY8_C(    29)  },
      {  SIMDE_POLY8_C(   111),  SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   197),  SIMDE_POLY8_C(    73),  SIMDE_POLY8_C(   229),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    16),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    89),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(   207),  SIMDE_POLY8_C(   235)  },
      {  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   245),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(    13),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(    12),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   161),  SIMDE_POLY8_C(   105),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   171)  },
      {  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   213),  SIMDE_POLY8_C(    62),  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(    77),  SIMDE_POLY8_C(   129),  SIMDE_POLY8_C(    21),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(   108),  SIMDE_POLY8_C(   120),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(    75),  SIMDE_POLY8_C(   175),  SIMDE_POLY8_C(   171)  } },
    { {  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   241),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(   127),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(    55),  SIMDE_POLY8_C(   177),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   189),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   151),  SIMDE_POLY8_C(   156),  SIMDE_POLY8_C(    20)  },
      {  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    74),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   233)  },
      {  SIMDE_POLY8_C(    38),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   107),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   184),  SIMDE_POLY8_C(    43),  SIMDE_POLY8_C(   121),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(    74),  SIMDE_POLY8_C(   188),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(   190),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   142),  SIMDE_POLY8_C(   233)  },
      {  SIMDE_POLY8_C(    50),  SIMDE_POLY8_C(    94),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(   215),  SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(    69),  SIMDE_POLY8_C(   243),  SIMDE_POLY8_C(    62),  SIMDE_POLY8_C(    39),  SIMDE_POLY8_C(   116),  SIMDE_POLY8_C(    76)  },
      {  SIMDE_POLY8_C(   202),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   145),  SIMDE_POLY8_C(    11),  SIMDE_POLY8_C(   127),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(    81),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    29),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(   151),  SIMDE_POLY8_C(   220),  SIMDE_POLY8_C(    52)  },
      {  SIMDE_POLY8_C(   106),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   231),  SIMDE_POLY8_C(   113),  SIMDE_POLY8_C(    11),        SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(   246),  SIMDE_POLY8_C(    55),  SIMDE_POLY8_C(    49),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(    61),  SIMDE_POLY8_C(     3),  SIMDE_POLY8_C(   254),  SIMDE_POLY8_C(    23),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(   148)  } },
    { {  SIMDE_POLY8_C(    46),  SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(    53),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(   130),  SIMDE_POLY8_C(   212),  SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(    67),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(   107)  },
      {  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(   253),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   160),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(    90)  },
      {  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(   253),  SIMDE_POLY8_C(   164),  SIMDE_POLY8_C(   131),  SIMDE_POLY8_C(    60),  SIMDE_POLY8_C(    54),  SIMDE_POLY8_C(    18),  SIMDE_POLY8_C(   160),  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   146),  SIMDE_POLY8_C(   139),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(    90)  },
      {  SIMDE_POLY8_C(   238),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(   237),  SIMDE_POLY8_C(    36),  SIMDE_POLY8_C(    26),  SIMDE_POLY8_C(   228),  SIMDE_POLY8_C(   182),  SIMDE_POLY8_C(   149),  SIMDE_POLY8_C(     6),  SIMDE_POLY8_C(   187),  SIMDE_POLY8_C(   135),  SIMDE_POLY8_C(    28),  SIMDE_POLY8_C(   144),  SIMDE_POLY8_C(    91),  SIMDE_POLY8_C(   167),  SIMDE_POLY8_C(   211)  },
      {  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   123),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    98),  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   222),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    14),  SIMDE_POLY8_C(   227),  SIMDE_POLY8_C(     7),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    99),  SIMDE_POLY8_C(   143),  SIMDE_POLY8_C(    75)  },
      {  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(   219),  SIMDE_POLY8_C(   181),  SIMDE_POLY8_C(     4),  SIMDE_POLY8_C(   130),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(    30),  SIMDE_POLY8_C(    85),  SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(    71),  SIMDE_POLY8_C(   196),  SIMDE_POLY8_C(   104),  SIMDE_POLY8_C(   195),  SIMDE_POLY8_C(    15),  SIMDE_POLY8_C(   107)  } },
    { {  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(    41),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(   215),  SIMDE_POLY8_C(   216),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   174),  SIMDE_POLY8_C(    83),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(    31),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(    12)  },
      {  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(    29),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   138),  SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   163),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(    89)  },
      {  SIMDE_POLY8_C(    87),  SIMDE_POLY8_C(   103),  SIMDE_POLY8_C(   201),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(    29),  SIMDE_POLY8_C(   172),  SIMDE_POLY8_C(   138),  SIMDE_POLY8_C(    78),  SIMDE_POLY8_C(   179),  SIMDE_POLY8_C(    66),  SIMDE_POLY8_C(   163),  SIMDE_POLY8_C(   203),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(    33),  SIMDE_POLY8_C(   173),  SIMDE_POLY8_C(    89)  },
      {  SIMDE_POLY8_C(   186),  SIMDE_POLY8_C(    57),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(    96),  SIMDE_POLY8_C(    84),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   155),  SIMDE_POLY8_C(    20),  SIMDE_POLY8_C(    24),  SIMDE_POLY8_C(    95),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(    10),  SIMDE_POLY8_C(   108),  SIMDE_POLY8_C(   204)  },
      {  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   233),  SIMDE_POLY8_C(    40),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(   183),  SIMDE_POLY8_C(   152),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   206),  SIMDE_POLY8_C(   115),  SIMDE_POLY8_C(    68),  SIMDE_POLY8_C(   112),  SIMDE_POLY8_C(   127),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(    42),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(    44)  },
      {  SIMDE_POLY8_C(   234),  SIMDE_POLY8_C(   169),  SIMDE_POLY8_C(   136),  SIMDE_POLY8_C(   239),  SIMDE_POLY8_C(   215),  SIMDE_POLY8_C(    88),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(    46),  SIMDE_POLY8_C(   211),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   240),  SIMDE_POLY8_C(   159),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(   170),  SIMDE_POLY8_C(   180),  SIMDE_POLY8_C(   140)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    simde_poly8x16_t b = simde_vld1q_p8(test_vec[i].b);

    simde_poly8x16_t r0 = simde_vsliq_n_p8(a, b, 0);
    simde_poly8x16_t r3 = simde_vsliq_n_p8(a, b, 3);
    simde_poly8x16_t r5 = simde_vsliq_n_p8(a, b, 5);
    simde_poly8x16_t r7 = simde_vsliq_n_p8(a, b, 7);

    simde_test_arm_neon_assert_equal_p8x16(r0, simde_vld1q_p8(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_p8x16(r3, simde_vld1q_p8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_p8x16(r5, simde_vld1q_p8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_p8x16(r7, simde_vld1q_p8(test_vec[i].r7));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x16_t a = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t b = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t r0 = simde_vsliq_n_p8(a, b, 0);
    simde_poly8x16_t r3 = simde_vsliq_n_p8(a, b, 3);
    simde_poly8x16_t r5 = simde_vsliq_n_p8(a, b, 5);
    simde_poly8x16_t r7 = simde_vsliq_n_p8(a, b, 7);

    simde_test_arm_neon_write_p8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[8];
    simde_poly16_t b[8];
    simde_poly16_t r3[8];
    simde_poly16_t r6[8];
    simde_poly16_t r10[8];
    simde_poly16_t r13[8];
    simde_poly16_t r15[8];
  } test_vec[] = {
    { {  SIMDE_POLY16_C(  54932),  SIMDE_POLY16_C(   2052),  SIMDE_POLY16_C(  30900),  SIMDE_POLY16_C(   7957),  SIMDE_POLY16_C(  53988),  SIMDE_POLY16_C(  54164),  SIMDE_POLY16_C(  41244),  SIMDE_POLY16_C(  57663)  },
      {  SIMDE_POLY16_C(  22926),  SIMDE_POLY16_C(  51202),  SIMDE_POLY16_C(   3783),  SIMDE_POLY16_C(  62722),  SIMDE_POLY16_C(  47770),  SIMDE_POLY16_C(  44849),  SIMDE_POLY16_C(  38117),  SIMDE_POLY16_C(  19359)  },
      {  SIMDE_POLY16_C(  52340),  SIMDE_POLY16_C(  16404),  SIMDE_POLY16_C(  30268),  SIMDE_POLY16_C(  43029),  SIMDE_POLY16_C(  54484),  SIMDE_POLY16_C(  31116),  SIMDE_POLY16_C(  42796),  SIMDE_POLY16_C(  23807)  },
      {  SIMDE_POLY16_C(  25492),  SIMDE_POLY16_C(    132),  SIMDE_POLY16_C(  45556),  SIMDE_POLY16_C(  16533),  SIMDE_POLY16_C(  42660),  SIMDE_POLY16_C(  52308),  SIMDE_POLY16_C(  14684),  SIMDE_POLY16_C(  59391)  },
      {  SIMDE_POLY16_C(  14996),  SIMDE_POLY16_C(   2052),  SIMDE_POLY16_C(   7348),  SIMDE_POLY16_C(   2837),  SIMDE_POLY16_C(  27364),  SIMDE_POLY16_C(  51092),  SIMDE_POLY16_C(  38172),  SIMDE_POLY16_C(  32063)  },
      {  SIMDE_POLY16_C(  54932),  SIMDE_POLY16_C(  18436),  SIMDE_POLY16_C(  63668),  SIMDE_POLY16_C(  24341),  SIMDE_POLY16_C(  21220),  SIMDE_POLY16_C(  13204),  SIMDE_POLY16_C(  41244),  SIMDE_POLY16_C(  57663)  },
      {  SIMDE_POLY16_C(  22164),  SIMDE_POLY16_C(   2052),  SIMDE_POLY16_C(  63668),  SIMDE_POLY16_C(   7957),  SIMDE_POLY16_C(  21220),  SIMDE_POLY16_C(  54164),  SIMDE_POLY16_C(  41244),  SIMDE_POLY16_C(  57663)  } },
    { {  SIMDE_POLY16_C(  55983),  SIMDE_POLY16_C(   3761),  SIMDE_POLY16_C(  17325),  SIMDE_POLY16_C(   1501),  SIMDE_POLY16_C(  20550),  SIMDE_POLY16_C(  44898),  SIMDE_POLY16_C(   2169),  SIMDE_POLY16_C(  48672)  },
      {  SIMDE_POLY16_C(  59886),  SIMDE_POLY16_C(  11886),  SIMDE_POLY16_C(  50059),  SIMDE_POLY16_C(  39013),  SIMDE_POLY16_C(   4828),  SIMDE_POLY16_C(  28010),  SIMDE_POLY16_C(   2847),  SIMDE_POLY16_C(  15306)  },
      {  SIMDE_POLY16_C(  20343),  SIMDE_POLY16_C(  29553),  SIMDE_POLY16_C(   7261),  SIMDE_POLY16_C(  49965),  SIMDE_POLY16_C(  38630),  SIMDE_POLY16_C(  27474),  SIMDE_POLY16_C(  22777),  SIMDE_POLY16_C(  56912)  },
      {  SIMDE_POLY16_C(  31663),  SIMDE_POLY16_C(  39857),  SIMDE_POLY16_C(  58093),  SIMDE_POLY16_C(   6493),  SIMDE_POLY16_C(  46854),  SIMDE_POLY16_C(  23202),  SIMDE_POLY16_C(  51193),  SIMDE_POLY16_C(  62112)  },
      {  SIMDE_POLY16_C(  47791),  SIMDE_POLY16_C(  47793),  SIMDE_POLY16_C(  12205),  SIMDE_POLY16_C(  38365),  SIMDE_POLY16_C(  28742),  SIMDE_POLY16_C(  43874),  SIMDE_POLY16_C(  31865),  SIMDE_POLY16_C(  10784)  },
      {  SIMDE_POLY16_C(  55983),  SIMDE_POLY16_C(  52913),  SIMDE_POLY16_C(  25517),  SIMDE_POLY16_C(  42461),  SIMDE_POLY16_C(  36934),  SIMDE_POLY16_C(  20322),  SIMDE_POLY16_C(  59513),  SIMDE_POLY16_C(  24096)  },
      {  SIMDE_POLY16_C(  23215),  SIMDE_POLY16_C(   3761),  SIMDE_POLY16_C(  50093),  SIMDE_POLY16_C(  34269),  SIMDE_POLY16_C(  20550),  SIMDE_POLY16_C(  12130),  SIMDE_POLY16_C(  34937),  SIMDE_POLY16_C(  15904)  } },
    { {  SIMDE_POLY16_C(  17536),  SIMDE_POLY16_C(  59891),  SIMDE_POLY16_C(  42463),  SIMDE_POLY16_C(   3164),  SIMDE_POLY16_C(  10034),  SIMDE_POLY16_C(  15752),  SIMDE_POLY16_C(  13926),  SIMDE_POLY16_C(  51179)  },
      {  SIMDE_POLY16_C(  16067),  SIMDE_POLY16_C(  15431),  SIMDE_POLY16_C(  15067),  SIMDE_POLY16_C(  39231),  SIMDE_POLY16_C(  52443),  SIMDE_POLY16_C(  53059),  SIMDE_POLY16_C(  35282),  SIMDE_POLY16_C(   4686)  },
      {  SIMDE_POLY16_C(  63000),  SIMDE_POLY16_C(  57915),  SIMDE_POLY16_C(  55007),  SIMDE_POLY16_C(  51708),  SIMDE_POLY16_C(  26330),  SIMDE_POLY16_C(  31256),  SIMDE_POLY16_C(  20118),  SIMDE_POLY16_C(  37491)  },
      {  SIMDE_POLY16_C(  45248),  SIMDE_POLY16_C(   4595),  SIMDE_POLY16_C(  46815),  SIMDE_POLY16_C(  20444),  SIMDE_POLY16_C(  14066),  SIMDE_POLY16_C(  53448),  SIMDE_POLY16_C(  29862),  SIMDE_POLY16_C(  37803)  },
      {  SIMDE_POLY16_C(   3200),  SIMDE_POLY16_C(   7667),  SIMDE_POLY16_C(  28127),  SIMDE_POLY16_C(  64604),  SIMDE_POLY16_C(  28466),  SIMDE_POLY16_C(   3464),  SIMDE_POLY16_C(  19046),  SIMDE_POLY16_C(  15339)  },
      {  SIMDE_POLY16_C(  25728),  SIMDE_POLY16_C(  59891),  SIMDE_POLY16_C(  26079),  SIMDE_POLY16_C(  60508),  SIMDE_POLY16_C(  26418),  SIMDE_POLY16_C(  32136),  SIMDE_POLY16_C(  22118),  SIMDE_POLY16_C(  51179)  },
      {  SIMDE_POLY16_C(  50304),  SIMDE_POLY16_C(  59891),  SIMDE_POLY16_C(  42463),  SIMDE_POLY16_C(  35932),  SIMDE_POLY16_C(  42802),  SIMDE_POLY16_C(  48520),  SIMDE_POLY16_C(  13926),  SIMDE_POLY16_C(  18411)  } },
    { {  SIMDE_POLY16_C(  55903),  SIMDE_POLY16_C(  22857),  SIMDE_POLY16_C(  39133),  SIMDE_POLY16_C(  33408),  SIMDE_POLY16_C(  16011),  SIMDE_POLY16_C(    990),  SIMDE_POLY16_C(  21485),  SIMDE_POLY16_C(  53727)  },
      {  SIMDE_POLY16_C(  10331),  SIMDE_POLY16_C(   5549),  SIMDE_POLY16_C(  17252),  SIMDE_POLY16_C(  48442),  SIMDE_POLY16_C(   3492),  SIMDE_POLY16_C(  61577),  SIMDE_POLY16_C(  18795),  SIMDE_POLY16_C(  38317)  },
      {  SIMDE_POLY16_C(  17119),  SIMDE_POLY16_C(  44393),  SIMDE_POLY16_C(   6949),  SIMDE_POLY16_C(  59856),  SIMDE_POLY16_C(  27939),  SIMDE_POLY16_C(  33870),  SIMDE_POLY16_C(  19293),  SIMDE_POLY16_C(  44399)  },
      {  SIMDE_POLY16_C(   5855),  SIMDE_POLY16_C(  27465),  SIMDE_POLY16_C(  55581),  SIMDE_POLY16_C(  20096),  SIMDE_POLY16_C(  26891),  SIMDE_POLY16_C(   8798),  SIMDE_POLY16_C(  23277),  SIMDE_POLY16_C(  27487)  },
      {  SIMDE_POLY16_C(  28255),  SIMDE_POLY16_C(  46409),  SIMDE_POLY16_C(  37085),  SIMDE_POLY16_C(  60032),  SIMDE_POLY16_C(  37515),  SIMDE_POLY16_C(  10206),  SIMDE_POLY16_C(  45037),  SIMDE_POLY16_C(  46559)  },
      {  SIMDE_POLY16_C(  31327),  SIMDE_POLY16_C(  47433),  SIMDE_POLY16_C(  39133),  SIMDE_POLY16_C(  17024),  SIMDE_POLY16_C(  40587),  SIMDE_POLY16_C(   9182),  SIMDE_POLY16_C(  29677),  SIMDE_POLY16_C(  45535)  },
      {  SIMDE_POLY16_C(  55903),  SIMDE_POLY16_C(  55625),  SIMDE_POLY16_C(   6365),  SIMDE_POLY16_C(    640),  SIMDE_POLY16_C(  16011),  SIMDE_POLY16_C(  33758),  SIMDE_POLY16_C(  54253),  SIMDE_POLY16_C(  53727)  } },
    { {  SIMDE_POLY16_C(  30910),  SIMDE_POLY16_C(  36057),  SIMDE_POLY16_C(  28028),  SIMDE_POLY16_C(  65285),  SIMDE_POLY16_C(  30944),  SIMDE_POLY16_C(  29925),  SIMDE_POLY16_C(  64087),  SIMDE_POLY16_C(  51797)  },
      {  SIMDE_POLY16_C(  21033),  SIMDE_POLY16_C(  43881),  SIMDE_POLY16_C(  63534),  SIMDE_POLY16_C(  35658),  SIMDE_POLY16_C(  41153),  SIMDE_POLY16_C(  27208),  SIMDE_POLY16_C(  27863),  SIMDE_POLY16_C(  40336)  },
      {  SIMDE_POLY16_C(  37198),  SIMDE_POLY16_C(  23369),  SIMDE_POLY16_C(  49524),  SIMDE_POLY16_C(  23125),  SIMDE_POLY16_C(   1544),  SIMDE_POLY16_C(  21061),  SIMDE_POLY16_C(  26303),  SIMDE_POLY16_C(  60549)  },
      {  SIMDE_POLY16_C(  35454),  SIMDE_POLY16_C(  55897),  SIMDE_POLY16_C(   3004),  SIMDE_POLY16_C(  53893),  SIMDE_POLY16_C(  12384),  SIMDE_POLY16_C(  37413),  SIMDE_POLY16_C(  13783),  SIMDE_POLY16_C(  25621)  },
      {  SIMDE_POLY16_C(  42174),  SIMDE_POLY16_C(  42201),  SIMDE_POLY16_C(  47484),  SIMDE_POLY16_C(  11013),  SIMDE_POLY16_C(   1248),  SIMDE_POLY16_C(   8421),  SIMDE_POLY16_C(  24151),  SIMDE_POLY16_C(  16981)  },
      {  SIMDE_POLY16_C(  14526),  SIMDE_POLY16_C(  11481),  SIMDE_POLY16_C(  52604),  SIMDE_POLY16_C(  24325),  SIMDE_POLY16_C(  14560),  SIMDE_POLY16_C(   5349),  SIMDE_POLY16_C(  64087),  SIMDE_POLY16_C(   2645)  },
      {  SIMDE_POLY16_C(  63678),  SIMDE_POLY16_C(  36057),  SIMDE_POLY16_C(  28028),  SIMDE_POLY16_C(  32517),  SIMDE_POLY16_C(  63712),  SIMDE_POLY16_C(  29925),  SIMDE_POLY16_C(  64087),  SIMDE_POLY16_C(  19029)  } },
    { {  SIMDE_POLY16_C(   2698),  SIMDE_POLY16_C(  52795),  SIMDE_POLY16_C(  47428),  SIMDE_POLY16_C(  57027),  SIMDE_POLY16_C(  39964),  SIMDE_POLY16_C(  36120),  SIMDE_POLY16_C(  60475),  SIMDE_POLY16_C(  45338)  },
      {  SIMDE_POLY16_C(  21185),  SIMDE_POLY16_C(   2661),  SIMDE_POLY16_C(  53801),  SIMDE_POLY16_C(  24352),  SIMDE_POLY16_C(  21787),  SIMDE_POLY16_C(  30325),  SIMDE_POLY16_C(  60200),  SIMDE_POLY16_C(  19373)  },
      {  SIMDE_POLY16_C(  38410),  SIMDE_POLY16_C(  21291),  SIMDE_POLY16_C(  37196),  SIMDE_POLY16_C(  63747),  SIMDE_POLY16_C(  43228),  SIMDE_POLY16_C(  45992),  SIMDE_POLY16_C(  22851),  SIMDE_POLY16_C(  23914)  },
      {  SIMDE_POLY16_C(  45130),  SIMDE_POLY16_C(  39291),  SIMDE_POLY16_C(  35396),  SIMDE_POLY16_C(  51203),  SIMDE_POLY16_C(  18140),  SIMDE_POLY16_C(  40280),  SIMDE_POLY16_C(  51771),  SIMDE_POLY16_C(  60250)  },
      {  SIMDE_POLY16_C(   1674),  SIMDE_POLY16_C(  38459),  SIMDE_POLY16_C(  42308),  SIMDE_POLY16_C(  33475),  SIMDE_POLY16_C(  27676),  SIMDE_POLY16_C(  54552),  SIMDE_POLY16_C(  41019),  SIMDE_POLY16_C(  46362)  },
      {  SIMDE_POLY16_C(  10890),  SIMDE_POLY16_C(  44603),  SIMDE_POLY16_C(  14660),  SIMDE_POLY16_C(   7875),  SIMDE_POLY16_C(  31772),  SIMDE_POLY16_C(  44312),  SIMDE_POLY16_C(   3131),  SIMDE_POLY16_C(  45338)  },
      {  SIMDE_POLY16_C(  35466),  SIMDE_POLY16_C(  52795),  SIMDE_POLY16_C(  47428),  SIMDE_POLY16_C(  24259),  SIMDE_POLY16_C(  39964),  SIMDE_POLY16_C(  36120),  SIMDE_POLY16_C(  27707),  SIMDE_POLY16_C(  45338)  } },
    { {  SIMDE_POLY16_C(  20622),  SIMDE_POLY16_C(  35405),  SIMDE_POLY16_C(  42684),  SIMDE_POLY16_C(  64877),  SIMDE_POLY16_C(  29368),  SIMDE_POLY16_C(  10266),  SIMDE_POLY16_C(  24647),  SIMDE_POLY16_C(  64280)  },
      {  SIMDE_POLY16_C(  31576),  SIMDE_POLY16_C(  19446),  SIMDE_POLY16_C(  44288),  SIMDE_POLY16_C(  56822),  SIMDE_POLY16_C(  32174),  SIMDE_POLY16_C(  17103),  SIMDE_POLY16_C(  18667),  SIMDE_POLY16_C(  20678)  },
      {  SIMDE_POLY16_C(  56006),  SIMDE_POLY16_C(  24501),  SIMDE_POLY16_C(  26628),  SIMDE_POLY16_C(  61365),  SIMDE_POLY16_C(  60784),  SIMDE_POLY16_C(   5754),  SIMDE_POLY16_C(  18271),  SIMDE_POLY16_C(  34352)  },
      {  SIMDE_POLY16_C(  54798),  SIMDE_POLY16_C(  64909),  SIMDE_POLY16_C(  16444),  SIMDE_POLY16_C(  32173),  SIMDE_POLY16_C(  27576),  SIMDE_POLY16_C(  46042),  SIMDE_POLY16_C(  15047),  SIMDE_POLY16_C(  12696)  },
      {  SIMDE_POLY16_C(  24718),  SIMDE_POLY16_C(  55885),  SIMDE_POLY16_C(    700),  SIMDE_POLY16_C(  55661),  SIMDE_POLY16_C(  47800),  SIMDE_POLY16_C(  15386),  SIMDE_POLY16_C(  44103),  SIMDE_POLY16_C(   6936)  },
      {  SIMDE_POLY16_C(   4238),  SIMDE_POLY16_C(  51789),  SIMDE_POLY16_C(   1724),  SIMDE_POLY16_C(  56685),  SIMDE_POLY16_C(  53944),  SIMDE_POLY16_C(  59418),  SIMDE_POLY16_C(  24647),  SIMDE_POLY16_C(  56088)  },
      {  SIMDE_POLY16_C(  20622),  SIMDE_POLY16_C(   2637),  SIMDE_POLY16_C(   9916),  SIMDE_POLY16_C(  32109),  SIMDE_POLY16_C(  29368),  SIMDE_POLY16_C(  43034),  SIMDE_POLY16_C(  57415),  SIMDE_POLY16_C(  31512)  } },
    { {  SIMDE_POLY16_C(  47232),  SIMDE_POLY16_C(    355),  SIMDE_POLY16_C(  64050),  SIMDE_POLY16_C(  59843),  SIMDE_POLY16_C(   9532),  SIMDE_POLY16_C(  42900),  SIMDE_POLY16_C(  36704),  SIMDE_POLY16_C(  46935)  },
      {  SIMDE_POLY16_C(  18854),  SIMDE_POLY16_C(  61891),  SIMDE_POLY16_C(  57306),  SIMDE_POLY16_C(  15820),  SIMDE_POLY16_C(  62408),  SIMDE_POLY16_C(  25140),  SIMDE_POLY16_C(   4068),  SIMDE_POLY16_C(  24825)  },
      {  SIMDE_POLY16_C(  19760),  SIMDE_POLY16_C(  36379),  SIMDE_POLY16_C(  65234),  SIMDE_POLY16_C(  61027),  SIMDE_POLY16_C(  40516),  SIMDE_POLY16_C(   4516),  SIMDE_POLY16_C(  32544),  SIMDE_POLY16_C(   1999)  },
      {  SIMDE_POLY16_C(  27008),  SIMDE_POLY16_C(  28899),  SIMDE_POLY16_C(  63154),  SIMDE_POLY16_C(  29443),  SIMDE_POLY16_C(  62012),  SIMDE_POLY16_C(  36116),  SIMDE_POLY16_C(  63776),  SIMDE_POLY16_C(  15959)  },
      {  SIMDE_POLY16_C(  39040),  SIMDE_POLY16_C(   3427),  SIMDE_POLY16_C(  27186),  SIMDE_POLY16_C(  12739),  SIMDE_POLY16_C(   8508),  SIMDE_POLY16_C(  54164),  SIMDE_POLY16_C(  37728),  SIMDE_POLY16_C(  59223)  },
      {  SIMDE_POLY16_C(  55424),  SIMDE_POLY16_C(  24931),  SIMDE_POLY16_C(  23090),  SIMDE_POLY16_C(  35267),  SIMDE_POLY16_C(   1340),  SIMDE_POLY16_C(  34708),  SIMDE_POLY16_C(  36704),  SIMDE_POLY16_C(  14167)  },
      {  SIMDE_POLY16_C(  14464),  SIMDE_POLY16_C(  33123),  SIMDE_POLY16_C(  31282),  SIMDE_POLY16_C(  27075),  SIMDE_POLY16_C(   9532),  SIMDE_POLY16_C(  10132),  SIMDE_POLY16_C(   3936),  SIMDE_POLY16_C(  46935)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    simde_poly16x8_t b = simde_vld1q_p16(test_vec[i].b);

    simde_poly16x8_t r3 = simde_vsliq_n_p16(a, b, 3);
    simde_poly16x8_t r6 = simde_vsliq_n_p16(a, b, 6);
    simde_poly16x8_t r10 = simde_vsliq_n_p16(a, b, 10);
    simde_poly16x8_t r13 = simde_vsliq_n_p16(a, b, 13);
    simde_poly16x8_t r15 = simde_vsliq_n_p16(a, b, 15);

    simde_test_arm_neon_assert_equal_p16x8(r3, simde_vld1q_p16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_p16x8(r6, simde_vld1q_p16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_p16x8(r10, simde_vld1q_p16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_p16x8(r13, simde_vld1q_p16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_p16x8(r15, simde_vld1q_p16(test_vec[i].r15));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8_t a = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t b = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t r3 = simde_vsliq_n_p16(a, b, 3);
    simde_poly16x8_t r6 = simde_vsliq_n_p16(a, b, 6);
    simde_poly16x8_t r10 = simde_vsliq_n_p16(a, b, 10);
    simde_poly16x8_t r13 = simde_vsliq_n_p16(a, b, 13);
    simde_poly16x8_t r15 = simde_vsliq_n_p16(a, b, 15);

    simde_test_arm_neon_write_p16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsliq_n_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly64_t a[2];
    simde_poly64_t b[2];
    simde_poly64_t r13[2];
    simde_poly64_t r26[2];
    simde_poly64_t r39[2];
    simde_poly64_t r52[2];
    simde_poly64_t r63[2];
  } test_vec[] = {
    { {  SIMDE_POLY64_C( 3326354101924670590),  SIMDE_POLY64_C(15812941646549698216)  },
      {  SIMDE_POLY64_C(18151090002998169439),  SIMDE_POLY64_C( 1380667824062628123)  },
      {  SIMDE_POLY64_C(12972070462018022526),  SIMDE_POLY64_C( 2576697537094444712)  },
      {  SIMDE_POLY64_C(13955360284637015166),  SIMDE_POLY64_C( 5231003553959724712)  },
      {  SIMDE_POLY64_C( 7838427115654622334),  SIMDE_POLY64_C(  594630893316032168)  },
      {  SIMDE_POLY64_C(17724362110628146302),  SIMDE_POLY64_C( 1275322049397737128)  },
      {  SIMDE_POLY64_C(12549726138779446398),  SIMDE_POLY64_C(15812941646549698216)  } },
    { {  SIMDE_POLY64_C( 5869328896938516263),  SIMDE_POLY64_C( 2222189733952536719)  },
      {  SIMDE_POLY64_C(12411628851339405478),  SIMDE_POLY64_C(  942836641027284248)  },
      {  SIMDE_POLY64_C(16056959959070727975),  SIMDE_POLY64_C(12978740484919984271)  },
      {  SIMDE_POLY64_C(13330739158301581095),  SIMDE_POLY64_C(13255955676427108495)  },
      {  SIMDE_POLY64_C(  690267940543831847),  SIMDE_POLY64_C(15253283237737447567)  },
      {  SIMDE_POLY64_C( 9972108157473038119),  SIMDE_POLY64_C(15097981068604784783)  },
      {  SIMDE_POLY64_C( 5869328896938516263),  SIMDE_POLY64_C( 2222189733952536719)  } },
    { {  SIMDE_POLY64_C(15272376107936314541),  SIMDE_POLY64_C( 7392787741455680135)  },
      {  SIMDE_POLY64_C( 9420840874243141019),  SIMDE_POLY64_C( 6038106548576691917)  },
      {  SIMDE_POLY64_C(12797981472756823213),  SIMDE_POLY64_C( 8447984324952302215)  },
      {  SIMDE_POLY64_C( 8217653932499203245),  SIMDE_POLY64_C(12150569524748616327)  },
      {  SIMDE_POLY64_C( 6851890001671943341),  SIMDE_POLY64_C(17281269205359133319)  },
      {  SIMDE_POLY64_C(15686707273654400173),  SIMDE_POLY64_C( 7843147704192729735)  },
      {  SIMDE_POLY64_C(15272376107936314541),  SIMDE_POLY64_C(16616159778310455943)  } },
    { {  SIMDE_POLY64_C(17788547161097733072),  SIMDE_POLY64_C(10303315733532817032)  },
      {  SIMDE_POLY64_C( 9530739437947880088),  SIMDE_POLY64_C( 9539080515559423601)  },
      {  SIMDE_POLY64_C( 9196555730211242960),  SIMDE_POLY64_C( 3739687229137499784)  },
      {  SIMDE_POLY64_C( 1681744860744483792),  SIMDE_POLY64_C(13922618736527455880)  },
      {  SIMDE_POLY64_C(15582820183151182800),  SIMDE_POLY64_C(16320825774362506888)  },
      {  SIMDE_POLY64_C( 2994222385185653712),  SIMDE_POLY64_C(16653391208125216392)  },
      {  SIMDE_POLY64_C( 8565175124242957264),  SIMDE_POLY64_C(10303315733532817032)  } },
    { {  SIMDE_POLY64_C(11269734078394947120),  SIMDE_POLY64_C(11079511464515323691)  },
      {  SIMDE_POLY64_C( 4631258017608531081),  SIMDE_POLY64_C( 2950484057785924872)  },
      {  SIMDE_POLY64_C(12759864702248498736),  SIMDE_POLY64_C( 5130664822783936299)  },
      {  SIMDE_POLY64_C( 9559719181400167984),  SIMDE_POLY64_C( 8723228335687976747)  },
      {  SIMDE_POLY64_C( 6790941082614519344),  SIMDE_POLY64_C(16446728547236431659)  },
      {  SIMDE_POLY64_C(14453779014945887792),  SIMDE_POLY64_C(15024664738091878187)  },
      {  SIMDE_POLY64_C(11269734078394947120),  SIMDE_POLY64_C( 1856139427660547883)  } },
    { {  SIMDE_POLY64_C( 7998503011676121860),  SIMDE_POLY64_C(12436442786690204518)  },
      {  SIMDE_POLY64_C(10507257933463575756),  SIMDE_POLY64_C(  890983024616133747)  },
      {  SIMDE_POLY64_C( 2949143004844755716),  SIMDE_POLY64_C(12469028540094767974)  },
      {  SIMDE_POLY64_C(12591503202443651844),  SIMDE_POLY64_C( 6659864326580700006)  },
      {  SIMDE_POLY64_C(13848118176700230404),  SIMDE_POLY64_C(10586337451585012582)  },
      {  SIMDE_POLY64_C(14753902452731865860),  SIMDE_POLY64_C( 5131604191095260006)  },
      {  SIMDE_POLY64_C( 7998503011676121860),  SIMDE_POLY64_C(12436442786690204518)  } },
    { {  SIMDE_POLY64_C(10515578012670966780),  SIMDE_POLY64_C(17680525830101447828)  },
      {  SIMDE_POLY64_C(11288336922296194998),  SIMDE_POLY64_C(16689682725274606802)  },
      {  SIMDE_POLY64_C(  528025944447179772),  SIMDE_POLY64_C(13060555188091901076)  },
      {  SIMDE_POLY64_C( 9050423663222406140),  SIMDE_POLY64_C(  952473333433152660)  },
      {  SIMDE_POLY64_C( 3606217256912632828),  SIMDE_POLY64_C(18135548271896081556)  },
      {  SIMDE_POLY64_C( 8894282146817588220),  SIMDE_POLY64_C(14784711269702218900)  },
      {  SIMDE_POLY64_C( 1292205975816190972),  SIMDE_POLY64_C( 8457153793246672020)  } },
    { {  SIMDE_POLY64_C( 2303077286822012679),  SIMDE_POLY64_C(  138581218363046567)  },
      {  SIMDE_POLY64_C(18411670028825252116),  SIMDE_POLY64_C( 8225054175440624625)  },
      {  SIMDE_POLY64_C( 7821329487171323655),  SIMDE_POLY64_C(12134448022314433191)  },
      {  SIMDE_POLY64_C( 6788990914251187975),  SIMDE_POLY64_C(14341129652734655143)  },
      {  SIMDE_POLY64_C(16926931031184631559),  SIMDE_POLY64_C(13667854094844426919)  },
      {  SIMDE_POLY64_C( 1244731374389946119),  SIMDE_POLY64_C(13770977290413537959)  },
      {  SIMDE_POLY64_C( 2303077286822012679),  SIMDE_POLY64_C( 9361953255217822375)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2_t a = simde_vld1q_p64(test_vec[i].a);
    simde_poly64x2_t b = simde_vld1q_p64(test_vec[i].b);

    simde_poly64x2_t r13 = simde_vsliq_n_p64(a, b, 13);
    simde_poly64x2_t r26 = simde_vsliq_n_p64(a, b, 26);
    simde_poly64x2_t r39 = simde_vsliq_n_p64(a, b, 39);
    simde_poly64x2_t r52 = simde_vsliq_n_p64(a, b, 52);
    simde_poly64x2_t r63 = simde_vsliq_n_p64(a, b, 63);

    simde_test_arm_neon_assert_equal_p64x2(r13, simde_vld1q_p64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_p64x2(r26, simde_vld1q_p64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_p64x2(r39, simde_vld1q_p64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_p64x2(r52, simde_vld1q_p64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_p64x2(r63, simde_vld1q_p64(test_vec[i].r63));
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x2_t a = simde_test_arm_neon_random_p64x2();
    simde_poly64x2_t b = simde_test_arm_neon_random_p64x2();
    simde_poly64x2_t r13 = simde_vsliq_n_p64(a, b, 13);
    simde_poly64x2_t r26 = simde_vsliq_n_p64(a, b, 26);
    simde_poly64x2_t r39 = simde_vsliq_n_p64(a, b, 39);
    simde_poly64x2_t r52 = simde_vsliq_n_p64(a, b, 52);
    simde_poly64x2_t r63 = simde_vsliq_n_p64(a, b, 63);

    simde_test_arm_neon_write_p64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vslid_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vslid_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsli_n_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsliq_n_p64)
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
