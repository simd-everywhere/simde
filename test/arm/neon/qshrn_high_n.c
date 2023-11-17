#define SIMDE_TEST_ARM_NEON_INSN qshrn_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qshrn_high_n.h"

static int
test_simde_vqshrn_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t r[8];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r8[16];
  } test_vec[] = {
    { {  INT16_C(  10216), -INT16_C(  24429), -INT16_C(  14067),  INT16_C(   9392),  INT16_C(  19587), -INT16_C(  32492),  INT16_C(  28881),  INT16_C(  10954) },
      { -INT8_C( 121),  INT8_C(  23), -INT8_C( 125), -INT8_C(  11),  INT8_C(  79), -INT8_C(   3),  INT8_C( 106), -INT8_C( 121)  },
      { -INT8_C( 121),  INT8_C(  23), -INT8_C( 125), -INT8_C(  11),  INT8_C(  79), -INT8_C(   3),  INT8_C( 106), -INT8_C( 121),       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MAX  },
      { -INT8_C( 121),  INT8_C(  23), -INT8_C( 125), -INT8_C(  11),  INT8_C(  79), -INT8_C(   3),  INT8_C( 106), -INT8_C( 121),       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MAX  },
      { -INT8_C( 121),  INT8_C(  23), -INT8_C( 125), -INT8_C(  11),  INT8_C(  79), -INT8_C(   3),  INT8_C( 106), -INT8_C( 121),       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MAX  },
      { -INT8_C( 121),  INT8_C(  23), -INT8_C( 125), -INT8_C(  11),  INT8_C(  79), -INT8_C(   3),  INT8_C( 106), -INT8_C( 121),       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MAX  },
      { -INT8_C( 121),  INT8_C(  23), -INT8_C( 125), -INT8_C(  11),  INT8_C(  79), -INT8_C(   3),  INT8_C( 106), -INT8_C( 121),  INT8_C(  39), -INT8_C(  96), -INT8_C(  55),  INT8_C(  36),  INT8_C(  76), -INT8_C( 127),  INT8_C( 112),  INT8_C(  42)  } },
    { { -INT16_C(  22100), -INT16_C(  27202),  INT16_C(  31275),  INT16_C(  29280), -INT16_C(  27394),  INT16_C(   8677), -INT16_C(   8078), -INT16_C(  13655) },
      { -INT8_C(  22),  INT8_C( 103),  INT8_C( 106),  INT8_C( 121), -INT8_C(  74),  INT8_C(  26), -INT8_C( 122),  INT8_C(  30)  },
      { -INT8_C(  22),  INT8_C( 103),  INT8_C( 106),  INT8_C( 121), -INT8_C(  74),  INT8_C(  26), -INT8_C( 122),  INT8_C(  30),       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN  },
      { -INT8_C(  22),  INT8_C( 103),  INT8_C( 106),  INT8_C( 121), -INT8_C(  74),  INT8_C(  26), -INT8_C( 122),  INT8_C(  30),       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN  },
      { -INT8_C(  22),  INT8_C( 103),  INT8_C( 106),  INT8_C( 121), -INT8_C(  74),  INT8_C(  26), -INT8_C( 122),  INT8_C(  30),       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN  },
      { -INT8_C(  22),  INT8_C( 103),  INT8_C( 106),  INT8_C( 121), -INT8_C(  74),  INT8_C(  26), -INT8_C( 122),  INT8_C(  30),       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX, -INT8_C( 127),       INT8_MIN  },
      { -INT8_C(  22),  INT8_C( 103),  INT8_C( 106),  INT8_C( 121), -INT8_C(  74),  INT8_C(  26), -INT8_C( 122),  INT8_C(  30), -INT8_C(  87), -INT8_C( 107),  INT8_C( 122),  INT8_C( 114), -INT8_C( 108),  INT8_C(  33), -INT8_C(  32), -INT8_C(  54)  } },
    { { -INT16_C(  14844),  INT16_C(  23748),  INT16_C(  15764),  INT16_C(  11881), -INT16_C(  14418),  INT16_C(  14298),  INT16_C(  22528),  INT16_C(  16001) },
      {  INT8_C(   5),  INT8_C(  52), -INT8_C( 101), -INT8_C(  65), -INT8_C(  50),  INT8_C(  52),  INT8_C(  73), -INT8_C(  83)  },
      {  INT8_C(   5),  INT8_C(  52), -INT8_C( 101), -INT8_C(  65), -INT8_C(  50),  INT8_C(  52),  INT8_C(  73), -INT8_C(  83),       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MAX  },
      {  INT8_C(   5),  INT8_C(  52), -INT8_C( 101), -INT8_C(  65), -INT8_C(  50),  INT8_C(  52),  INT8_C(  73), -INT8_C(  83),       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MAX  },
      {  INT8_C(   5),  INT8_C(  52), -INT8_C( 101), -INT8_C(  65), -INT8_C(  50),  INT8_C(  52),  INT8_C(  73), -INT8_C(  83),       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MAX  },
      {  INT8_C(   5),  INT8_C(  52), -INT8_C( 101), -INT8_C(  65), -INT8_C(  50),  INT8_C(  52),  INT8_C(  73), -INT8_C(  83),       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MAX  },
      {  INT8_C(   5),  INT8_C(  52), -INT8_C( 101), -INT8_C(  65), -INT8_C(  50),  INT8_C(  52),  INT8_C(  73), -INT8_C(  83), -INT8_C(  58),  INT8_C(  92),  INT8_C(  61),  INT8_C(  46), -INT8_C(  57),  INT8_C(  55),  INT8_C(  88),  INT8_C(  62)  } },
    { { -INT16_C(  23532), -INT16_C(  12659), -INT16_C(  29861),  INT16_C(  16868), -INT16_C(  22458),  INT16_C(  28700), -INT16_C(  18092), -INT16_C(   7765) },
      {  INT8_C(  56),  INT8_C(  77), -INT8_C(  23), -INT8_C( 108), -INT8_C(  86),  INT8_C(  93),  INT8_C(  52),  INT8_C(  68)  },
      {  INT8_C(  56),  INT8_C(  77), -INT8_C(  23), -INT8_C( 108), -INT8_C(  86),  INT8_C(  93),  INT8_C(  52),  INT8_C(  68),       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN  },
      {  INT8_C(  56),  INT8_C(  77), -INT8_C(  23), -INT8_C( 108), -INT8_C(  86),  INT8_C(  93),  INT8_C(  52),  INT8_C(  68),       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN  },
      {  INT8_C(  56),  INT8_C(  77), -INT8_C(  23), -INT8_C( 108), -INT8_C(  86),  INT8_C(  93),  INT8_C(  52),  INT8_C(  68),       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN  },
      {  INT8_C(  56),  INT8_C(  77), -INT8_C(  23), -INT8_C( 108), -INT8_C(  86),  INT8_C(  93),  INT8_C(  52),  INT8_C(  68),       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN, -INT8_C( 122)  },
      {  INT8_C(  56),  INT8_C(  77), -INT8_C(  23), -INT8_C( 108), -INT8_C(  86),  INT8_C(  93),  INT8_C(  52),  INT8_C(  68), -INT8_C(  92), -INT8_C(  50), -INT8_C( 117),  INT8_C(  65), -INT8_C(  88),  INT8_C( 112), -INT8_C(  71), -INT8_C(  31)  } },
    { {  INT16_C(  20461), -INT16_C(    741), -INT16_C(   4533), -INT16_C(   9203), -INT16_C(  31212), -INT16_C(   3743), -INT16_C(  21233),  INT16_C(  27370) },
      { -INT8_C(  17),  INT8_C(  23), -INT8_C( 109),  INT8_C(  27), -INT8_C(  77),  INT8_C(  99),  INT8_C(  76), -INT8_C(  44)  },
      { -INT8_C(  17),  INT8_C(  23), -INT8_C( 109),  INT8_C(  27), -INT8_C(  77),  INT8_C(  99),  INT8_C(  76), -INT8_C(  44),       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX  },
      { -INT8_C(  17),  INT8_C(  23), -INT8_C( 109),  INT8_C(  27), -INT8_C(  77),  INT8_C(  99),  INT8_C(  76), -INT8_C(  44),       INT8_MAX, -INT8_C(  93),       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX  },
      { -INT8_C(  17),  INT8_C(  23), -INT8_C( 109),  INT8_C(  27), -INT8_C(  77),  INT8_C(  99),  INT8_C(  76), -INT8_C(  44),       INT8_MAX, -INT8_C(  24),       INT8_MIN,       INT8_MIN,       INT8_MIN, -INT8_C( 117),       INT8_MIN,       INT8_MAX  },
      { -INT8_C(  17),  INT8_C(  23), -INT8_C( 109),  INT8_C(  27), -INT8_C(  77),  INT8_C(  99),  INT8_C(  76), -INT8_C(  44),       INT8_MAX, -INT8_C(  12), -INT8_C(  71),       INT8_MIN,       INT8_MIN, -INT8_C(  59),       INT8_MIN,       INT8_MAX  },
      { -INT8_C(  17),  INT8_C(  23), -INT8_C( 109),  INT8_C(  27), -INT8_C(  77),  INT8_C(  99),  INT8_C(  76), -INT8_C(  44),  INT8_C(  79), -INT8_C(   3), -INT8_C(  18), -INT8_C(  36), -INT8_C( 122), -INT8_C(  15), -INT8_C(  83),  INT8_C( 106)  } },
    { {  INT16_C(  19560),  INT16_C(  13455), -INT16_C(  28972),  INT16_C(  26862), -INT16_C(  30243), -INT16_C(  30157), -INT16_C(  12184),  INT16_C(  20625) },
      { -INT8_C(  72), -INT8_C(  18),  INT8_C(  24), -INT8_C(  24), -INT8_C(  59), -INT8_C(  62), -INT8_C( 102),  INT8_C( 109)  },
      { -INT8_C(  72), -INT8_C(  18),  INT8_C(  24), -INT8_C(  24), -INT8_C(  59), -INT8_C(  62), -INT8_C( 102),  INT8_C( 109),       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX  },
      { -INT8_C(  72), -INT8_C(  18),  INT8_C(  24), -INT8_C(  24), -INT8_C(  59), -INT8_C(  62), -INT8_C( 102),  INT8_C( 109),       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX  },
      { -INT8_C(  72), -INT8_C(  18),  INT8_C(  24), -INT8_C(  24), -INT8_C(  59), -INT8_C(  62), -INT8_C( 102),  INT8_C( 109),       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX  },
      { -INT8_C(  72), -INT8_C(  18),  INT8_C(  24), -INT8_C(  24), -INT8_C(  59), -INT8_C(  62), -INT8_C( 102),  INT8_C( 109),       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX  },
      { -INT8_C(  72), -INT8_C(  18),  INT8_C(  24), -INT8_C(  24), -INT8_C(  59), -INT8_C(  62), -INT8_C( 102),  INT8_C( 109),  INT8_C(  76),  INT8_C(  52), -INT8_C( 114),  INT8_C( 104), -INT8_C( 119), -INT8_C( 118), -INT8_C(  48),  INT8_C(  80)  } },
    { {  INT16_C(   1314),  INT16_C(  14771), -INT16_C(  18655),  INT16_C(  21202), -INT16_C(  13604), -INT16_C(   4043), -INT16_C(  28213), -INT16_C(  19543) },
      {  INT8_C( 104), -INT8_C( 117), -INT8_C(  52), -INT8_C( 101), -INT8_C(  25), -INT8_C(  59), -INT8_C(  62),  INT8_C(  70)  },
      {  INT8_C( 104), -INT8_C( 117), -INT8_C(  52), -INT8_C( 101), -INT8_C(  25), -INT8_C(  59), -INT8_C(  62),  INT8_C(  70),       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MIN  },
      {  INT8_C( 104), -INT8_C( 117), -INT8_C(  52), -INT8_C( 101), -INT8_C(  25), -INT8_C(  59), -INT8_C(  62),  INT8_C(  70),       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MIN  },
      {  INT8_C( 104), -INT8_C( 117), -INT8_C(  52), -INT8_C( 101), -INT8_C(  25), -INT8_C(  59), -INT8_C(  62),  INT8_C(  70),  INT8_C(  41),       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN, -INT8_C( 127),       INT8_MIN,       INT8_MIN  },
      {  INT8_C( 104), -INT8_C( 117), -INT8_C(  52), -INT8_C( 101), -INT8_C(  25), -INT8_C(  59), -INT8_C(  62),  INT8_C(  70),  INT8_C(  20),       INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN, -INT8_C(  64),       INT8_MIN,       INT8_MIN  },
      {  INT8_C( 104), -INT8_C( 117), -INT8_C(  52), -INT8_C( 101), -INT8_C(  25), -INT8_C(  59), -INT8_C(  62),  INT8_C(  70),  INT8_C(   5),  INT8_C(  57), -INT8_C(  73),  INT8_C(  82), -INT8_C(  54), -INT8_C(  16), -INT8_C( 111), -INT8_C(  77)  } },
    { {  INT16_C(  21984),  INT16_C(   7535), -INT16_C(  11054), -INT16_C(  15541),  INT16_C(   6702), -INT16_C(  19675), -INT16_C(  10927), -INT16_C(  26787) },
      {  INT8_C( 122), -INT8_C( 123),  INT8_C(  84), -INT8_C( 127),  INT8_C(  82), -INT8_C(  67), -INT8_C(  85),  INT8_C(  43)  },
      {  INT8_C( 122), -INT8_C( 123),  INT8_C(  84), -INT8_C( 127),  INT8_C(  82), -INT8_C(  67), -INT8_C(  85),  INT8_C(  43),       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN  },
      {  INT8_C( 122), -INT8_C( 123),  INT8_C(  84), -INT8_C( 127),  INT8_C(  82), -INT8_C(  67), -INT8_C(  85),  INT8_C(  43),       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN  },
      {  INT8_C( 122), -INT8_C( 123),  INT8_C(  84), -INT8_C( 127),  INT8_C(  82), -INT8_C(  67), -INT8_C(  85),  INT8_C(  43),       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN  },
      {  INT8_C( 122), -INT8_C( 123),  INT8_C(  84), -INT8_C( 127),  INT8_C(  82), -INT8_C(  67), -INT8_C(  85),  INT8_C(  43),       INT8_MAX,  INT8_C( 117),       INT8_MIN,       INT8_MIN,  INT8_C( 104),       INT8_MIN,       INT8_MIN,       INT8_MIN  },
      {  INT8_C( 122), -INT8_C( 123),  INT8_C(  84), -INT8_C( 127),  INT8_C(  82), -INT8_C(  67), -INT8_C(  85),  INT8_C(  43),  INT8_C(  85),  INT8_C(  29), -INT8_C(  44), -INT8_C(  61),  INT8_C(  26), -INT8_C(  77), -INT8_C(  43), -INT8_C( 105)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x8_t r = simde_vld1_s8(test_vec[i].r);

    simde_int8x16_t r1 = simde_vqshrn_high_n_s16(r, a, 1);
    simde_int8x16_t r3 = simde_vqshrn_high_n_s16(r, a, 3);
    simde_int8x16_t r5 = simde_vqshrn_high_n_s16(r, a, 5);
    simde_int8x16_t r6 = simde_vqshrn_high_n_s16(r, a, 6);
    simde_int8x16_t r8 = simde_vqshrn_high_n_s16(r, a, 8);

    simde_test_arm_neon_assert_equal_i8x16(r1, simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r6, simde_vld1q_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x16(r8, simde_vld1q_s8(test_vec[i].r8));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x8_t r = simde_test_arm_neon_random_i8x8();
    simde_int8x16_t r1 = simde_vqshrn_high_n_s16(r, a, 1);
    simde_int8x16_t r3 = simde_vqshrn_high_n_s16(r, a, 3);
    simde_int8x16_t r5 = simde_vqshrn_high_n_s16(r, a, 5);
    simde_int8x16_t r6 = simde_vqshrn_high_n_s16(r, a, 6);
    simde_int8x16_t r8 = simde_vqshrn_high_n_s16(r, a, 8);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshrn_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t r[4];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { {  INT32_C(1129261466), -INT32_C(1639403369),  INT32_C(  71313492), -INT32_C(1496180707) },
      {  INT16_C(   1331), -INT16_C(  29205), -INT16_C(  30587),  INT16_C(  25424)  },
      {  INT16_C(   1331), -INT16_C(  29205), -INT16_C(  30587),  INT16_C(  25424),         INT16_MAX,         INT16_MIN,         INT16_MAX,         INT16_MIN  },
      {  INT16_C(   1331), -INT16_C(  29205), -INT16_C(  30587),  INT16_C(  25424),         INT16_MAX,         INT16_MIN,         INT16_MAX,         INT16_MIN  },
      {  INT16_C(   1331), -INT16_C(  29205), -INT16_C(  30587),  INT16_C(  25424),         INT16_MAX,         INT16_MIN,         INT16_MAX,         INT16_MIN  },
      {  INT16_C(   1331), -INT16_C(  29205), -INT16_C(  30587),  INT16_C(  25424),         INT16_MAX,         INT16_MIN,  INT16_C(   8705),         INT16_MIN  },
      {  INT16_C(   1331), -INT16_C(  29205), -INT16_C(  30587),  INT16_C(  25424),  INT16_C(  17231), -INT16_C(  25016),  INT16_C(   1088), -INT16_C(  22830)  } },
    { { -INT32_C(1459014421), -INT32_C(1515670200),  INT32_C(  82559049), -INT32_C(2077923617) },
      { -INT16_C(  28066), -INT16_C(  29382), -INT16_C(  27745),  INT16_C(  20378)  },
      { -INT16_C(  28066), -INT16_C(  29382), -INT16_C(  27745),  INT16_C(  20378),         INT16_MIN,         INT16_MIN,         INT16_MAX,         INT16_MIN  },
      { -INT16_C(  28066), -INT16_C(  29382), -INT16_C(  27745),  INT16_C(  20378),         INT16_MIN,         INT16_MIN,         INT16_MAX,         INT16_MIN  },
      { -INT16_C(  28066), -INT16_C(  29382), -INT16_C(  27745),  INT16_C(  20378),         INT16_MIN,         INT16_MIN,         INT16_MAX,         INT16_MIN  },
      { -INT16_C(  28066), -INT16_C(  29382), -INT16_C(  27745),  INT16_C(  20378),         INT16_MIN,         INT16_MIN,  INT16_C(  10078),         INT16_MIN  },
      { -INT16_C(  28066), -INT16_C(  29382), -INT16_C(  27745),  INT16_C(  20378), -INT16_C(  22263), -INT16_C(  23128),  INT16_C(   1259), -INT16_C(  31707)  } },
    { { -INT32_C(1669005205), -INT32_C( 361496326),  INT32_C(1142570396), -INT32_C(1170924398) },
      { -INT16_C(  21246), -INT16_C(   7755), -INT16_C(  21005), -INT16_C(   8489)  },
      { -INT16_C(  21246), -INT16_C(   7755), -INT16_C(  21005), -INT16_C(   8489),         INT16_MIN,         INT16_MIN,         INT16_MAX,         INT16_MIN  },
      { -INT16_C(  21246), -INT16_C(   7755), -INT16_C(  21005), -INT16_C(   8489),         INT16_MIN,         INT16_MIN,         INT16_MAX,         INT16_MIN  },
      { -INT16_C(  21246), -INT16_C(   7755), -INT16_C(  21005), -INT16_C(   8489),         INT16_MIN,         INT16_MIN,         INT16_MAX,         INT16_MIN  },
      { -INT16_C(  21246), -INT16_C(   7755), -INT16_C(  21005), -INT16_C(   8489),         INT16_MIN,         INT16_MIN,         INT16_MAX,         INT16_MIN  },
      { -INT16_C(  21246), -INT16_C(   7755), -INT16_C(  21005), -INT16_C(   8489), -INT16_C(  25467), -INT16_C(   5516),  INT16_C(  17434), -INT16_C(  17867)  } },
    { {  INT32_C( 991737227), -INT32_C( 247956976),  INT32_C(1830904832),  INT32_C( 925103331) },
      { -INT16_C(  20572), -INT16_C(  16805), -INT16_C(  11538),  INT16_C(  29449)  },
      { -INT16_C(  20572), -INT16_C(  16805), -INT16_C(  11538),  INT16_C(  29449),         INT16_MAX,         INT16_MIN,         INT16_MAX,         INT16_MAX  },
      { -INT16_C(  20572), -INT16_C(  16805), -INT16_C(  11538),  INT16_C(  29449),         INT16_MAX,         INT16_MIN,         INT16_MAX,         INT16_MAX  },
      { -INT16_C(  20572), -INT16_C(  16805), -INT16_C(  11538),  INT16_C(  29449),         INT16_MAX,         INT16_MIN,         INT16_MAX,         INT16_MAX  },
      { -INT16_C(  20572), -INT16_C(  16805), -INT16_C(  11538),  INT16_C(  29449),         INT16_MAX, -INT16_C(  30269),         INT16_MAX,         INT16_MAX  },
      { -INT16_C(  20572), -INT16_C(  16805), -INT16_C(  11538),  INT16_C(  29449),  INT16_C(  15132), -INT16_C(   3784),  INT16_C(  27937),  INT16_C(  14115)  } },
    { {  INT32_C( 521682632), -INT32_C(1873599869), -INT32_C(1886854197),  INT32_C( 834818051) },
      { -INT16_C(   8241),  INT16_C(  15746), -INT16_C(      2),  INT16_C(   2910)  },
      { -INT16_C(   8241),  INT16_C(  15746), -INT16_C(      2),  INT16_C(   2910),         INT16_MAX,         INT16_MIN,         INT16_MIN,         INT16_MAX  },
      { -INT16_C(   8241),  INT16_C(  15746), -INT16_C(      2),  INT16_C(   2910),         INT16_MAX,         INT16_MIN,         INT16_MIN,         INT16_MAX  },
      { -INT16_C(   8241),  INT16_C(  15746), -INT16_C(      2),  INT16_C(   2910),         INT16_MAX,         INT16_MIN,         INT16_MIN,         INT16_MAX  },
      { -INT16_C(   8241),  INT16_C(  15746), -INT16_C(      2),  INT16_C(   2910),         INT16_MAX,         INT16_MIN,         INT16_MIN,         INT16_MAX  },
      { -INT16_C(   8241),  INT16_C(  15746), -INT16_C(      2),  INT16_C(   2910),  INT16_C(   7960), -INT16_C(  28589), -INT16_C(  28792),  INT16_C(  12738)  } },
    { {  INT32_C( 752569105), -INT32_C(1056108898), -INT32_C(  55610933), -INT32_C(1139322037) },
      { -INT16_C(  30067), -INT16_C(   9119), -INT16_C(   6313), -INT16_C(  28795)  },
      { -INT16_C(  30067), -INT16_C(   9119), -INT16_C(   6313), -INT16_C(  28795),         INT16_MAX,         INT16_MIN,         INT16_MIN,         INT16_MIN  },
      { -INT16_C(  30067), -INT16_C(   9119), -INT16_C(   6313), -INT16_C(  28795),         INT16_MAX,         INT16_MIN,         INT16_MIN,         INT16_MIN  },
      { -INT16_C(  30067), -INT16_C(   9119), -INT16_C(   6313), -INT16_C(  28795),         INT16_MAX,         INT16_MIN,         INT16_MIN,         INT16_MIN  },
      { -INT16_C(  30067), -INT16_C(   9119), -INT16_C(   6313), -INT16_C(  28795),         INT16_MAX,         INT16_MIN, -INT16_C(   6789),         INT16_MIN  },
      { -INT16_C(  30067), -INT16_C(   9119), -INT16_C(   6313), -INT16_C(  28795),  INT16_C(  11483), -INT16_C(  16115), -INT16_C(    849), -INT16_C(  17385)  } },
    { { -INT32_C(  13538846),  INT32_C( 294134544), -INT32_C(  36755682),  INT32_C( 542562851) },
      {  INT16_C(   4346),  INT16_C(   1839), -INT16_C(  32259),  INT16_C(  30305)  },
      {  INT16_C(   4346),  INT16_C(   1839), -INT16_C(  32259),  INT16_C(  30305),         INT16_MIN,         INT16_MAX,         INT16_MIN,         INT16_MAX  },
      {  INT16_C(   4346),  INT16_C(   1839), -INT16_C(  32259),  INT16_C(  30305),         INT16_MIN,         INT16_MAX,         INT16_MIN,         INT16_MAX  },
      {  INT16_C(   4346),  INT16_C(   1839), -INT16_C(  32259),  INT16_C(  30305), -INT16_C(  13222),         INT16_MAX,         INT16_MIN,         INT16_MAX  },
      {  INT16_C(   4346),  INT16_C(   1839), -INT16_C(  32259),  INT16_C(  30305), -INT16_C(   1653),         INT16_MAX, -INT16_C(   4487),         INT16_MAX  },
      {  INT16_C(   4346),  INT16_C(   1839), -INT16_C(  32259),  INT16_C(  30305), -INT16_C(    207),  INT16_C(   4488), -INT16_C(    561),  INT16_C(   8278)  } },
    { {  INT32_C( 173726430), -INT32_C(1101904268), -INT32_C( 100277379),  INT32_C( 952928107) },
      {  INT16_C(   2900), -INT16_C(  20521),  INT16_C(  26827),  INT16_C(   7019)  },
      {  INT16_C(   2900), -INT16_C(  20521),  INT16_C(  26827),  INT16_C(   7019),         INT16_MAX,         INT16_MIN,         INT16_MIN,         INT16_MAX  },
      {  INT16_C(   2900), -INT16_C(  20521),  INT16_C(  26827),  INT16_C(   7019),         INT16_MAX,         INT16_MIN,         INT16_MIN,         INT16_MAX  },
      {  INT16_C(   2900), -INT16_C(  20521),  INT16_C(  26827),  INT16_C(   7019),         INT16_MAX,         INT16_MIN,         INT16_MIN,         INT16_MAX  },
      {  INT16_C(   2900), -INT16_C(  20521),  INT16_C(  26827),  INT16_C(   7019),  INT16_C(  21206),         INT16_MIN, -INT16_C(  12241),         INT16_MAX  },
      {  INT16_C(   2900), -INT16_C(  20521),  INT16_C(  26827),  INT16_C(   7019),  INT16_C(   2650), -INT16_C(  16814), -INT16_C(   1531),  INT16_C(  14540)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t r = simde_vld1_s16(test_vec[i].r);

    simde_int16x8_t r3 = simde_vqshrn_high_n_s32(r, a, 3);
    simde_int16x8_t r6 = simde_vqshrn_high_n_s32(r, a, 6);
    simde_int16x8_t r10 = simde_vqshrn_high_n_s32(r, a, 10);
    simde_int16x8_t r13 = simde_vqshrn_high_n_s32(r, a, 13);
    simde_int16x8_t r16 = simde_vqshrn_high_n_s32(r, a, 16);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r16, simde_vld1q_s16(test_vec[i].r16));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t r = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t r3 = simde_vqshrn_high_n_s32(r, a, 3);
    simde_int16x8_t r6 = simde_vqshrn_high_n_s32(r, a, 6);
    simde_int16x8_t r10 = simde_vqshrn_high_n_s32(r, a, 10);
    simde_int16x8_t r13 = simde_vqshrn_high_n_s32(r, a, 13);
    simde_int16x8_t r16 = simde_vqshrn_high_n_s32(r, a, 16);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshrn_high_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t r[2];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r32[4];
  } test_vec[] = {
    { { -INT64_C(765171249508011034), -INT64_C(4525319093864694895) },
      { -INT32_C(1566369049), -INT32_C(984125454)  },
      { -INT32_C(1566369049), -INT32_C(984125454),         INT32_MIN,         INT32_MIN  },
      { -INT32_C(1566369049), -INT32_C(984125454),         INT32_MIN,         INT32_MIN  },
      { -INT32_C(1566369049), -INT32_C(984125454),         INT32_MIN,         INT32_MIN  },
      { -INT32_C(1566369049), -INT32_C(984125454),         INT32_MIN,         INT32_MIN  },
      { -INT32_C(1566369049), -INT32_C(984125454), -INT32_C(178155315), -INT32_C(1053632958)  } },
    { { -INT64_C(3161110402208284557),  INT64_C(1691993124931351958) },
      { -INT32_C(360166921),  INT32_C(56480042)  },
      { -INT32_C(360166921),  INT32_C(56480042),         INT32_MIN,         INT32_MAX  },
      { -INT32_C(360166921),  INT32_C(56480042),         INT32_MIN,         INT32_MAX  },
      { -INT32_C(360166921),  INT32_C(56480042),         INT32_MIN,         INT32_MAX  },
      { -INT32_C(360166921),  INT32_C(56480042),         INT32_MIN,         INT32_MAX  },
      { -INT32_C(360166921),  INT32_C(56480042), -INT32_C(736003370),  INT32_C(393947848)  } },
    { { -INT64_C(6810743514283196592), -INT64_C(3960885338091995016) },
      {  INT32_C(1536115396), -INT32_C(290743308)  },
      {  INT32_C(1536115396), -INT32_C(290743308),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(1536115396), -INT32_C(290743308),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(1536115396), -INT32_C(290743308),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(1536115396), -INT32_C(290743308),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(1536115396), -INT32_C(290743308), -INT32_C(1585749797), -INT32_C(922215483)  } },
    { {  INT64_C(1012374666276996287),  INT64_C(5445809416200044057) },
      { -INT32_C(1308095952), -INT32_C(784194256)  },
      { -INT32_C(1308095952), -INT32_C(784194256),         INT32_MAX,         INT32_MAX  },
      { -INT32_C(1308095952), -INT32_C(784194256),         INT32_MAX,         INT32_MAX  },
      { -INT32_C(1308095952), -INT32_C(784194256),         INT32_MAX,         INT32_MAX  },
      { -INT32_C(1308095952), -INT32_C(784194256),         INT32_MAX,         INT32_MAX  },
      { -INT32_C(1308095952), -INT32_C(784194256),  INT32_C(235711845),  INT32_C(1267951311)  } },
    { {  INT64_C(378766495890448787), -INT64_C(7944518708464066992) },
      { -INT32_C(366409358),  INT32_C(1396245526)  },
      { -INT32_C(366409358),  INT32_C(1396245526),         INT32_MAX,         INT32_MIN  },
      { -INT32_C(366409358),  INT32_C(1396245526),         INT32_MAX,         INT32_MIN  },
      { -INT32_C(366409358),  INT32_C(1396245526),         INT32_MAX,         INT32_MIN  },
      { -INT32_C(366409358),  INT32_C(1396245526),         INT32_MAX,         INT32_MIN  },
      { -INT32_C(366409358),  INT32_C(1396245526),  INT32_C(88188447), -INT32_C(1849727405)  } },
    { { -INT64_C(8933309892358046918), -INT64_C(1273532278696929068) },
      {  INT32_C(443286716), -INT32_C(1983115849)  },
      {  INT32_C(443286716), -INT32_C(1983115849),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(443286716), -INT32_C(1983115849),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(443286716), -INT32_C(1983115849),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(443286716), -INT32_C(1983115849),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(443286716), -INT32_C(1983115849), -INT32_C(2079948293), -INT32_C(296517341)  } },
    { {  INT64_C(2163653472670588741), -INT64_C(2442964316617231425) },
      { -INT32_C(1546863875),  INT32_C(1785966531)  },
      { -INT32_C(1546863875),  INT32_C(1785966531),         INT32_MAX,         INT32_MIN  },
      { -INT32_C(1546863875),  INT32_C(1785966531),         INT32_MAX,         INT32_MIN  },
      { -INT32_C(1546863875),  INT32_C(1785966531),         INT32_MAX,         INT32_MIN  },
      { -INT32_C(1546863875),  INT32_C(1785966531),         INT32_MAX,         INT32_MIN  },
      { -INT32_C(1546863875),  INT32_C(1785966531),  INT32_C(503764830), -INT32_C(568796955)  } },
    { { -INT64_C(3574845421579539086), -INT64_C(2305885010680092105) },
      {  INT32_C(91844711), -INT32_C(723757095)  },
      {  INT32_C(91844711), -INT32_C(723757095),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(91844711), -INT32_C(723757095),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(91844711), -INT32_C(723757095),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(91844711), -INT32_C(723757095),         INT32_MIN,         INT32_MIN  },
      {  INT32_C(91844711), -INT32_C(723757095), -INT32_C(832333561), -INT32_C(536880692)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t r = simde_vld1_s32(test_vec[i].r);

    simde_int32x4_t r6 = simde_vqshrn_high_n_s64(r, a, 6);
    simde_int32x4_t r13 = simde_vqshrn_high_n_s64(r, a, 13);
    simde_int32x4_t r19 = simde_vqshrn_high_n_s64(r, a, 19);
    simde_int32x4_t r26 = simde_vqshrn_high_n_s64(r, a, 26);
    simde_int32x4_t r32 = simde_vqshrn_high_n_s64(r, a, 32);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r32, simde_vld1q_s32(test_vec[i].r32));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t r = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t r6 = simde_vqshrn_high_n_s64(r, a, 6);
    simde_int32x4_t r13 = simde_vqshrn_high_n_s64(r, a, 13);
    simde_int32x4_t r19 = simde_vqshrn_high_n_s64(r, a, 19);
    simde_int32x4_t r26 = simde_vqshrn_high_n_s64(r, a, 26);
    simde_int32x4_t r32 = simde_vqshrn_high_n_s64(r, a, 32);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshrn_high_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t r[8];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { {  UINT16_C(   1105),  UINT16_C(   6921),  UINT16_C(  48895),  UINT16_C(  26266),  UINT16_C(  24330),  UINT16_C(  16692),  UINT16_C(   7067),  UINT16_C(  37251) },
      {  UINT8_C( 147),  UINT8_C(  72),  UINT8_C(  41),  UINT8_C( 186),  UINT8_C( 224),  UINT8_C(  59),  UINT8_C( 125),  UINT8_C(  92)  },
      {  UINT8_C( 147),  UINT8_C(  72),  UINT8_C(  41),  UINT8_C( 186),  UINT8_C( 224),  UINT8_C(  59),  UINT8_C( 125),  UINT8_C(  92),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 147),  UINT8_C(  72),  UINT8_C(  41),  UINT8_C( 186),  UINT8_C( 224),  UINT8_C(  59),  UINT8_C( 125),  UINT8_C(  92),  UINT8_C( 138),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 147),  UINT8_C(  72),  UINT8_C(  41),  UINT8_C( 186),  UINT8_C( 224),  UINT8_C(  59),  UINT8_C( 125),  UINT8_C(  92),  UINT8_C(  34),  UINT8_C( 216),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C( 220),      UINT8_MAX  },
      {  UINT8_C( 147),  UINT8_C(  72),  UINT8_C(  41),  UINT8_C( 186),  UINT8_C( 224),  UINT8_C(  59),  UINT8_C( 125),  UINT8_C(  92),  UINT8_C(  17),  UINT8_C( 108),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C( 110),      UINT8_MAX  },
      {  UINT8_C( 147),  UINT8_C(  72),  UINT8_C(  41),  UINT8_C( 186),  UINT8_C( 224),  UINT8_C(  59),  UINT8_C( 125),  UINT8_C(  92),  UINT8_C(   4),  UINT8_C(  27),  UINT8_C( 190),  UINT8_C( 102),  UINT8_C(  95),  UINT8_C(  65),  UINT8_C(  27),  UINT8_C( 145)  } },
    { {  UINT16_C(  54415),  UINT16_C(  52396),  UINT16_C(  44348),  UINT16_C(  19843),  UINT16_C(  21304),  UINT16_C(  58585),  UINT16_C(  20228),  UINT16_C(  37437) },
      {  UINT8_C(  83),  UINT8_C( 107),  UINT8_C(   8),  UINT8_C( 150),  UINT8_C(  99),  UINT8_C(  77),  UINT8_C( 232),  UINT8_C(  49)  },
      {  UINT8_C(  83),  UINT8_C( 107),  UINT8_C(   8),  UINT8_C( 150),  UINT8_C(  99),  UINT8_C(  77),  UINT8_C( 232),  UINT8_C(  49),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C( 107),  UINT8_C(   8),  UINT8_C( 150),  UINT8_C(  99),  UINT8_C(  77),  UINT8_C( 232),  UINT8_C(  49),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C( 107),  UINT8_C(   8),  UINT8_C( 150),  UINT8_C(  99),  UINT8_C(  77),  UINT8_C( 232),  UINT8_C(  49),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C( 107),  UINT8_C(   8),  UINT8_C( 150),  UINT8_C(  99),  UINT8_C(  77),  UINT8_C( 232),  UINT8_C(  49),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  83),  UINT8_C( 107),  UINT8_C(   8),  UINT8_C( 150),  UINT8_C(  99),  UINT8_C(  77),  UINT8_C( 232),  UINT8_C(  49),  UINT8_C( 212),  UINT8_C( 204),  UINT8_C( 173),  UINT8_C(  77),  UINT8_C(  83),  UINT8_C( 228),  UINT8_C(  79),  UINT8_C( 146)  } },
    { {  UINT16_C(   2035),  UINT16_C(  27462),  UINT16_C(  56467),  UINT16_C(    311),  UINT16_C(    791),  UINT16_C(  31983),  UINT16_C(  27022),  UINT16_C(  28573) },
      {  UINT8_C(  68),  UINT8_C(  37),  UINT8_C(   8),  UINT8_C(  62),  UINT8_C(  24),  UINT8_C( 133),  UINT8_C( 210),  UINT8_C( 117)  },
      {  UINT8_C(  68),  UINT8_C(  37),  UINT8_C(   8),  UINT8_C(  62),  UINT8_C(  24),  UINT8_C( 133),  UINT8_C( 210),  UINT8_C( 117),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C( 155),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  68),  UINT8_C(  37),  UINT8_C(   8),  UINT8_C(  62),  UINT8_C(  24),  UINT8_C( 133),  UINT8_C( 210),  UINT8_C( 117),  UINT8_C( 254),      UINT8_MAX,      UINT8_MAX,  UINT8_C(  38),  UINT8_C(  98),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  68),  UINT8_C(  37),  UINT8_C(   8),  UINT8_C(  62),  UINT8_C(  24),  UINT8_C( 133),  UINT8_C( 210),  UINT8_C( 117),  UINT8_C(  63),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   9),  UINT8_C(  24),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  68),  UINT8_C(  37),  UINT8_C(   8),  UINT8_C(  62),  UINT8_C(  24),  UINT8_C( 133),  UINT8_C( 210),  UINT8_C( 117),  UINT8_C(  31),      UINT8_MAX,      UINT8_MAX,  UINT8_C(   4),  UINT8_C(  12),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  68),  UINT8_C(  37),  UINT8_C(   8),  UINT8_C(  62),  UINT8_C(  24),  UINT8_C( 133),  UINT8_C( 210),  UINT8_C( 117),  UINT8_C(   7),  UINT8_C( 107),  UINT8_C( 220),  UINT8_C(   1),  UINT8_C(   3),  UINT8_C( 124),  UINT8_C( 105),  UINT8_C( 111)  } },
    { {  UINT16_C(  24051),  UINT16_C(    261),  UINT16_C(  14783),  UINT16_C(  63186),  UINT16_C(   2150),  UINT16_C(  16210),  UINT16_C(  15740),  UINT16_C(  31367) },
      {  UINT8_C(  26),  UINT8_C( 102),  UINT8_C( 106),  UINT8_C( 141),  UINT8_C( 181),  UINT8_C( 117),  UINT8_C(  54),  UINT8_C(  45)  },
      {  UINT8_C(  26),  UINT8_C( 102),  UINT8_C( 106),  UINT8_C( 141),  UINT8_C( 181),  UINT8_C( 117),  UINT8_C(  54),  UINT8_C(  45),      UINT8_MAX,  UINT8_C( 130),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  26),  UINT8_C( 102),  UINT8_C( 106),  UINT8_C( 141),  UINT8_C( 181),  UINT8_C( 117),  UINT8_C(  54),  UINT8_C(  45),      UINT8_MAX,  UINT8_C(  32),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  26),  UINT8_C( 102),  UINT8_C( 106),  UINT8_C( 141),  UINT8_C( 181),  UINT8_C( 117),  UINT8_C(  54),  UINT8_C(  45),      UINT8_MAX,  UINT8_C(   8),      UINT8_MAX,      UINT8_MAX,  UINT8_C(  67),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  26),  UINT8_C( 102),  UINT8_C( 106),  UINT8_C( 141),  UINT8_C( 181),  UINT8_C( 117),  UINT8_C(  54),  UINT8_C(  45),      UINT8_MAX,  UINT8_C(   4),  UINT8_C( 230),      UINT8_MAX,  UINT8_C(  33),  UINT8_C( 253),  UINT8_C( 245),      UINT8_MAX  },
      {  UINT8_C(  26),  UINT8_C( 102),  UINT8_C( 106),  UINT8_C( 141),  UINT8_C( 181),  UINT8_C( 117),  UINT8_C(  54),  UINT8_C(  45),  UINT8_C(  93),  UINT8_C(   1),  UINT8_C(  57),  UINT8_C( 246),  UINT8_C(   8),  UINT8_C(  63),  UINT8_C(  61),  UINT8_C( 122)  } },
    { {  UINT16_C(   8851),  UINT16_C(  30702),  UINT16_C(  11103),  UINT16_C(  45088),  UINT16_C(  21022),  UINT16_C(   2460),  UINT16_C(  17797),  UINT16_C(  18061) },
      {  UINT8_C(  61),  UINT8_C( 231),  UINT8_C(  92),  UINT8_C( 213),  UINT8_C( 101),  UINT8_C( 122),  UINT8_C(  50),  UINT8_C( 195)  },
      {  UINT8_C(  61),  UINT8_C( 231),  UINT8_C(  92),  UINT8_C( 213),  UINT8_C( 101),  UINT8_C( 122),  UINT8_C(  50),  UINT8_C( 195),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  61),  UINT8_C( 231),  UINT8_C(  92),  UINT8_C( 213),  UINT8_C( 101),  UINT8_C( 122),  UINT8_C(  50),  UINT8_C( 195),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  61),  UINT8_C( 231),  UINT8_C(  92),  UINT8_C( 213),  UINT8_C( 101),  UINT8_C( 122),  UINT8_C(  50),  UINT8_C( 195),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(  76),      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  61),  UINT8_C( 231),  UINT8_C(  92),  UINT8_C( 213),  UINT8_C( 101),  UINT8_C( 122),  UINT8_C(  50),  UINT8_C( 195),  UINT8_C( 138),      UINT8_MAX,  UINT8_C( 173),      UINT8_MAX,      UINT8_MAX,  UINT8_C(  38),      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  61),  UINT8_C( 231),  UINT8_C(  92),  UINT8_C( 213),  UINT8_C( 101),  UINT8_C( 122),  UINT8_C(  50),  UINT8_C( 195),  UINT8_C(  34),  UINT8_C( 119),  UINT8_C(  43),  UINT8_C( 176),  UINT8_C(  82),  UINT8_C(   9),  UINT8_C(  69),  UINT8_C(  70)  } },
    { {  UINT16_C(  52972),  UINT16_C(  55056),  UINT16_C(   8297),  UINT16_C(  49512),  UINT16_C(  26081),  UINT16_C(  29542),  UINT16_C(  35273),  UINT16_C(  26373) },
      {  UINT8_C(  16),  UINT8_C( 151),  UINT8_C(  73),  UINT8_C(  22),  UINT8_C( 214),  UINT8_C(  25),  UINT8_C( 123),  UINT8_C(  96)  },
      {  UINT8_C(  16),  UINT8_C( 151),  UINT8_C(  73),  UINT8_C(  22),  UINT8_C( 214),  UINT8_C(  25),  UINT8_C( 123),  UINT8_C(  96),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  16),  UINT8_C( 151),  UINT8_C(  73),  UINT8_C(  22),  UINT8_C( 214),  UINT8_C(  25),  UINT8_C( 123),  UINT8_C(  96),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  16),  UINT8_C( 151),  UINT8_C(  73),  UINT8_C(  22),  UINT8_C( 214),  UINT8_C(  25),  UINT8_C( 123),  UINT8_C(  96),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  16),  UINT8_C( 151),  UINT8_C(  73),  UINT8_C(  22),  UINT8_C( 214),  UINT8_C(  25),  UINT8_C( 123),  UINT8_C(  96),      UINT8_MAX,      UINT8_MAX,  UINT8_C( 129),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  16),  UINT8_C( 151),  UINT8_C(  73),  UINT8_C(  22),  UINT8_C( 214),  UINT8_C(  25),  UINT8_C( 123),  UINT8_C(  96),  UINT8_C( 206),  UINT8_C( 215),  UINT8_C(  32),  UINT8_C( 193),  UINT8_C( 101),  UINT8_C( 115),  UINT8_C( 137),  UINT8_C( 103)  } },
    { {  UINT16_C(  34631),  UINT16_C(  19191),  UINT16_C(  10930),  UINT16_C(  25238),  UINT16_C(   4654),  UINT16_C(  17428),  UINT16_C(  38959),  UINT16_C(  64073) },
      {  UINT8_C(  78),  UINT8_C(  84),  UINT8_C( 151),  UINT8_C(  79),  UINT8_C( 210),  UINT8_C(  96),  UINT8_C( 183),  UINT8_C( 231)  },
      {  UINT8_C(  78),  UINT8_C(  84),  UINT8_C( 151),  UINT8_C(  79),  UINT8_C( 210),  UINT8_C(  96),  UINT8_C( 183),  UINT8_C( 231),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  78),  UINT8_C(  84),  UINT8_C( 151),  UINT8_C(  79),  UINT8_C( 210),  UINT8_C(  96),  UINT8_C( 183),  UINT8_C( 231),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  78),  UINT8_C(  84),  UINT8_C( 151),  UINT8_C(  79),  UINT8_C( 210),  UINT8_C(  96),  UINT8_C( 183),  UINT8_C( 231),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C( 145),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  78),  UINT8_C(  84),  UINT8_C( 151),  UINT8_C(  79),  UINT8_C( 210),  UINT8_C(  96),  UINT8_C( 183),  UINT8_C( 231),      UINT8_MAX,      UINT8_MAX,  UINT8_C( 170),      UINT8_MAX,  UINT8_C(  72),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C(  78),  UINT8_C(  84),  UINT8_C( 151),  UINT8_C(  79),  UINT8_C( 210),  UINT8_C(  96),  UINT8_C( 183),  UINT8_C( 231),  UINT8_C( 135),  UINT8_C(  74),  UINT8_C(  42),  UINT8_C(  98),  UINT8_C(  18),  UINT8_C(  68),  UINT8_C( 152),  UINT8_C( 250)  } },
    { {  UINT16_C(  11068),  UINT16_C(  33326),  UINT16_C(  23470),  UINT16_C(  17170),  UINT16_C(  12419),  UINT16_C(  39286),  UINT16_C(  59545),  UINT16_C(   8118) },
      {  UINT8_C( 199),  UINT8_C(   1),  UINT8_C(  73),  UINT8_C( 132),  UINT8_C( 228),  UINT8_C( 136),  UINT8_C( 135),  UINT8_C( 152)  },
      {  UINT8_C( 199),  UINT8_C(   1),  UINT8_C(  73),  UINT8_C( 132),  UINT8_C( 228),  UINT8_C( 136),  UINT8_C( 135),  UINT8_C( 152),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 199),  UINT8_C(   1),  UINT8_C(  73),  UINT8_C( 132),  UINT8_C( 228),  UINT8_C( 136),  UINT8_C( 135),  UINT8_C( 152),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX  },
      {  UINT8_C( 199),  UINT8_C(   1),  UINT8_C(  73),  UINT8_C( 132),  UINT8_C( 228),  UINT8_C( 136),  UINT8_C( 135),  UINT8_C( 152),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C( 253)  },
      {  UINT8_C( 199),  UINT8_C(   1),  UINT8_C(  73),  UINT8_C( 132),  UINT8_C( 228),  UINT8_C( 136),  UINT8_C( 135),  UINT8_C( 152),  UINT8_C( 172),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C( 194),      UINT8_MAX,      UINT8_MAX,  UINT8_C( 126)  },
      {  UINT8_C( 199),  UINT8_C(   1),  UINT8_C(  73),  UINT8_C( 132),  UINT8_C( 228),  UINT8_C( 136),  UINT8_C( 135),  UINT8_C( 152),  UINT8_C(  43),  UINT8_C( 130),  UINT8_C(  91),  UINT8_C(  67),  UINT8_C(  48),  UINT8_C( 153),  UINT8_C( 232),  UINT8_C(  31)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x8_t r = simde_vld1_u8(test_vec[i].r);

    simde_uint8x16_t r1 = simde_vqshrn_high_n_u16(r, a, 1);
    simde_uint8x16_t r3 = simde_vqshrn_high_n_u16(r, a, 3);
    simde_uint8x16_t r5 = simde_vqshrn_high_n_u16(r, a, 5);
    simde_uint8x16_t r6 = simde_vqshrn_high_n_u16(r, a, 6);
    simde_uint8x16_t r8 = simde_vqshrn_high_n_u16(r, a, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x8_t r = simde_test_arm_neon_random_u8x8();
    simde_uint8x16_t r1 = simde_vqshrn_high_n_u16(r, a, 1);
    simde_uint8x16_t r3 = simde_vqshrn_high_n_u16(r, a, 3);
    simde_uint8x16_t r5 = simde_vqshrn_high_n_u16(r, a, 5);
    simde_uint8x16_t r6 = simde_vqshrn_high_n_u16(r, a, 6);
    simde_uint8x16_t r8 = simde_vqshrn_high_n_u16(r, a, 8);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshrn_high_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t r[4];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { {  UINT32_C(2361451199),  UINT32_C(3928353983),  UINT32_C(2203416184),  UINT32_C(2489499857) },
      {  UINT16_C(26690),  UINT16_C(31011),  UINT16_C( 645),  UINT16_C(43088)  },
      {  UINT16_C(26690),  UINT16_C(31011),  UINT16_C( 645),  UINT16_C(43088),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(26690),  UINT16_C(31011),  UINT16_C( 645),  UINT16_C(43088),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(26690),  UINT16_C(31011),  UINT16_C( 645),  UINT16_C(43088),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(26690),  UINT16_C(31011),  UINT16_C( 645),  UINT16_C(43088),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(26690),  UINT16_C(31011),  UINT16_C( 645),  UINT16_C(43088),  UINT16_C(36032),  UINT16_C(59941),  UINT16_C(33621),  UINT16_C(37986)  } },
    { {  UINT32_C(306270981),  UINT32_C(4245752686),  UINT32_C(1259241961),  UINT32_C(1394342818) },
      {  UINT16_C(53839),  UINT16_C(54788),  UINT16_C(41601),  UINT16_C(52605)  },
      {  UINT16_C(53839),  UINT16_C(54788),  UINT16_C(41601),  UINT16_C(52605),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(53839),  UINT16_C(54788),  UINT16_C(41601),  UINT16_C(52605),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(53839),  UINT16_C(54788),  UINT16_C(41601),  UINT16_C(52605),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(53839),  UINT16_C(54788),  UINT16_C(41601),  UINT16_C(52605),  UINT16_C(37386),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(53839),  UINT16_C(54788),  UINT16_C(41601),  UINT16_C(52605),  UINT16_C(4673),  UINT16_C(64785),  UINT16_C(19214),  UINT16_C(21275)  } },
    { {  UINT32_C(1329624828),  UINT32_C(2258156829),  UINT32_C(2018646584),  UINT32_C(3202299265) },
      {  UINT16_C(53341),  UINT16_C(23984),  UINT16_C(34377),  UINT16_C(1206)  },
      {  UINT16_C(53341),  UINT16_C(23984),  UINT16_C(34377),  UINT16_C(1206),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(53341),  UINT16_C(23984),  UINT16_C(34377),  UINT16_C(1206),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(53341),  UINT16_C(23984),  UINT16_C(34377),  UINT16_C(1206),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(53341),  UINT16_C(23984),  UINT16_C(34377),  UINT16_C(1206),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(53341),  UINT16_C(23984),  UINT16_C(34377),  UINT16_C(1206),  UINT16_C(20288),  UINT16_C(34456),  UINT16_C(30802),  UINT16_C(48863)  } },
    { {  UINT32_C(56824135),  UINT32_C(2334585118),  UINT32_C(2534667093),  UINT32_C(1779495218) },
      {  UINT16_C(48657),  UINT16_C(6925),  UINT16_C(4288),  UINT16_C(28798)  },
      {  UINT16_C(48657),  UINT16_C(6925),  UINT16_C(4288),  UINT16_C(28798),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(48657),  UINT16_C(6925),  UINT16_C(4288),  UINT16_C(28798),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(48657),  UINT16_C(6925),  UINT16_C(4288),  UINT16_C(28798),  UINT16_C(55492),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(48657),  UINT16_C(6925),  UINT16_C(4288),  UINT16_C(28798),  UINT16_C(6936),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(48657),  UINT16_C(6925),  UINT16_C(4288),  UINT16_C(28798),  UINT16_C( 867),  UINT16_C(35622),  UINT16_C(38675),  UINT16_C(27152)  } },
    { {  UINT32_C(2307010385),  UINT32_C(786094078),  UINT32_C(4213990281),  UINT32_C(514701508) },
      {  UINT16_C(50041),  UINT16_C(42001),  UINT16_C(29125),  UINT16_C(15908)  },
      {  UINT16_C(50041),  UINT16_C(42001),  UINT16_C(29125),  UINT16_C(15908),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(50041),  UINT16_C(42001),  UINT16_C(29125),  UINT16_C(15908),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(50041),  UINT16_C(42001),  UINT16_C(29125),  UINT16_C(15908),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(50041),  UINT16_C(42001),  UINT16_C(29125),  UINT16_C(15908),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,  UINT16_C(62829)  },
      {  UINT16_C(50041),  UINT16_C(42001),  UINT16_C(29125),  UINT16_C(15908),  UINT16_C(35202),  UINT16_C(11994),  UINT16_C(64300),  UINT16_C(7853)  } },
    { {  UINT32_C(2928194567),  UINT32_C(711630444),  UINT32_C(1409143013),  UINT32_C(91264893) },
      {  UINT16_C(46467),  UINT16_C(49351),  UINT16_C(47593),  UINT16_C(14136)  },
      {  UINT16_C(46467),  UINT16_C(49351),  UINT16_C(47593),  UINT16_C(14136),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(46467),  UINT16_C(49351),  UINT16_C(47593),  UINT16_C(14136),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(46467),  UINT16_C(49351),  UINT16_C(47593),  UINT16_C(14136),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(46467),  UINT16_C(49351),  UINT16_C(47593),  UINT16_C(14136),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,  UINT16_C(11140)  },
      {  UINT16_C(46467),  UINT16_C(49351),  UINT16_C(47593),  UINT16_C(14136),  UINT16_C(44680),  UINT16_C(10858),  UINT16_C(21501),  UINT16_C(1392)  } },
    { {  UINT32_C(3282209478),  UINT32_C(2025208263),  UINT32_C(1022708302),  UINT32_C(4060576734) },
      {  UINT16_C(40872),  UINT16_C(52756),  UINT16_C(49418),  UINT16_C( 549)  },
      {  UINT16_C(40872),  UINT16_C(52756),  UINT16_C(49418),  UINT16_C( 549),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(40872),  UINT16_C(52756),  UINT16_C(49418),  UINT16_C( 549),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(40872),  UINT16_C(52756),  UINT16_C(49418),  UINT16_C( 549),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(40872),  UINT16_C(52756),  UINT16_C(49418),  UINT16_C( 549),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(40872),  UINT16_C(52756),  UINT16_C(49418),  UINT16_C( 549),  UINT16_C(50082),  UINT16_C(30902),  UINT16_C(15605),  UINT16_C(61959)  } },
    { {  UINT32_C(2112066869),  UINT32_C(2506561151),  UINT32_C(3159742828),  UINT32_C(1886997040) },
      {  UINT16_C(33103),  UINT16_C(44697),  UINT16_C(3298),  UINT16_C(41095)  },
      {  UINT16_C(33103),  UINT16_C(44697),  UINT16_C(3298),  UINT16_C(41095),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(33103),  UINT16_C(44697),  UINT16_C(3298),  UINT16_C(41095),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(33103),  UINT16_C(44697),  UINT16_C(3298),  UINT16_C(41095),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(33103),  UINT16_C(44697),  UINT16_C(3298),  UINT16_C(41095),     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX  },
      {  UINT16_C(33103),  UINT16_C(44697),  UINT16_C(3298),  UINT16_C(41095),  UINT16_C(32227),  UINT16_C(38247),  UINT16_C(48213),  UINT16_C(28793)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t r = simde_vld1_u16(test_vec[i].r);

    simde_uint16x8_t r3 = simde_vqshrn_high_n_u32(r, a, 3);
    simde_uint16x8_t r6 = simde_vqshrn_high_n_u32(r, a, 6);
    simde_uint16x8_t r10 = simde_vqshrn_high_n_u32(r, a, 10);
    simde_uint16x8_t r13 = simde_vqshrn_high_n_u32(r, a, 13);
    simde_uint16x8_t r16 = simde_vqshrn_high_n_u32(r, a, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t r = simde_test_arm_neon_random_u16x4();
    simde_uint16x8_t r3 = simde_vqshrn_high_n_u32(r, a, 3);
    simde_uint16x8_t r6 = simde_vqshrn_high_n_u32(r, a, 6);
    simde_uint16x8_t r10 = simde_vqshrn_high_n_u32(r, a, 10);
    simde_uint16x8_t r13 = simde_vqshrn_high_n_u32(r, a, 13);
    simde_uint16x8_t r16 = simde_vqshrn_high_n_u32(r, a, 16);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshrn_high_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t r[2];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { {  UINT64_C(5153608494813095252),  UINT64_C(15801484430927645942) },
      {  UINT32_C(1149783980),  UINT32_C(778382986)  },
      {  UINT32_C(1149783980),  UINT32_C(778382986),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(1149783980),  UINT32_C(778382986),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(1149783980),  UINT32_C(778382986),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(1149783980),  UINT32_C(778382986),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(1149783980),  UINT32_C(778382986),  UINT32_C(1199917982),  UINT32_C(3679069790)  } },
    { {  UINT64_C(13858666046941017502),  UINT64_C(17181432487780316057) },
      {  UINT32_C(2555790628),  UINT32_C(4208570593)  },
      {  UINT32_C(2555790628),  UINT32_C(4208570593),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(2555790628),  UINT32_C(4208570593),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(2555790628),  UINT32_C(4208570593),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(2555790628),  UINT32_C(4208570593),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(2555790628),  UINT32_C(4208570593),  UINT32_C(3226722135),  UINT32_C(4000363985)  } },
    { {  UINT64_C(7611247938741977904),  UINT64_C(16019258039644149976) },
      {  UINT32_C(813398151),  UINT32_C(3091258712)  },
      {  UINT32_C(813398151),  UINT32_C(3091258712),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(813398151),  UINT32_C(3091258712),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(813398151),  UINT32_C(3091258712),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(813398151),  UINT32_C(3091258712),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(813398151),  UINT32_C(3091258712),  UINT32_C(1772131756),  UINT32_C(3729774160)  } },
    { {  UINT64_C(11739101929472879634),  UINT64_C(15478438981995682412) },
      {  UINT32_C(160744076),  UINT32_C(3176789119)  },
      {  UINT32_C(160744076),  UINT32_C(3176789119),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(160744076),  UINT32_C(3176789119),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(160744076),  UINT32_C(3176789119),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(160744076),  UINT32_C(3176789119),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(160744076),  UINT32_C(3176789119),  UINT32_C(2733222658),  UINT32_C(3603854910)  } },
    { {  UINT64_C(13918965383802178048),  UINT64_C(988305148310810066) },
      {  UINT32_C(1680278688),  UINT32_C(551691632)  },
      {  UINT32_C(1680278688),  UINT32_C(551691632),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(1680278688),  UINT32_C(551691632),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(1680278688),  UINT32_C(551691632),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(1680278688),  UINT32_C(551691632),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(1680278688),  UINT32_C(551691632),  UINT32_C(3240761669),  UINT32_C(230107723)  } },
    { {  UINT64_C(12655452248050541842),  UINT64_C(9682272096452148561) },
      {  UINT32_C(780484345),  UINT32_C(2945636890)  },
      {  UINT32_C(780484345),  UINT32_C(2945636890),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(780484345),  UINT32_C(2945636890),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(780484345),  UINT32_C(2945636890),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(780484345),  UINT32_C(2945636890),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(780484345),  UINT32_C(2945636890),  UINT32_C(2946577092),  UINT32_C(2254329644)  } },
    { {  UINT64_C(4711763874410978498),  UINT64_C(9840987415755556929) },
      {  UINT32_C(275444936),  UINT32_C(1358980049)  },
      {  UINT32_C(275444936),  UINT32_C(1358980049),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(275444936),  UINT32_C(1358980049),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(275444936),  UINT32_C(1358980049),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(275444936),  UINT32_C(1358980049),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(275444936),  UINT32_C(1358980049),  UINT32_C(1097043015),  UINT32_C(2291283434)  } },
    { {  UINT64_C(18279397249888037655),  UINT64_C(4293313567125042273) },
      {  UINT32_C(2733055859),  UINT32_C(2742207168)  },
      {  UINT32_C(2733055859),  UINT32_C(2742207168),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(2733055859),  UINT32_C(2742207168),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(2733055859),  UINT32_C(2742207168),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(2733055859),  UINT32_C(2742207168),        UINT32_MAX,        UINT32_MAX  },
      {  UINT32_C(2733055859),  UINT32_C(2742207168),  UINT32_C(4256003827),  UINT32_C(999614961)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t r = simde_vld1_u32(test_vec[i].r);

    simde_uint32x4_t r6 = simde_vqshrn_high_n_u64(r, a, 6);
    simde_uint32x4_t r13 = simde_vqshrn_high_n_u64(r, a, 13);
    simde_uint32x4_t r19 = simde_vqshrn_high_n_u64(r, a, 19);
    simde_uint32x4_t r26 = simde_vqshrn_high_n_u64(r, a, 26);
    simde_uint32x4_t r32 = simde_vqshrn_high_n_u64(r, a, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t r = simde_test_arm_neon_random_u32x2();
    simde_uint32x4_t r6 = simde_vqshrn_high_n_u64(r, a, 6);
    simde_uint32x4_t r13 = simde_vqshrn_high_n_u64(r, a, 13);
    simde_uint32x4_t r19 = simde_vqshrn_high_n_u64(r, a, 19);
    simde_uint32x4_t r26 = simde_vqshrn_high_n_u64(r, a, 26);
    simde_uint32x4_t r32 = simde_vqshrn_high_n_u64(r, a, 32);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_high_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_high_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_high_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_high_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_high_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
