#define SIMDE_TEST_ARM_NEON_INSN shrn_n

#include "test-neon.h"
#include "../../../simde/arm/neon/shrn_n.h"

static int
test_simde_vshrn_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec[] = {
    { {  INT16_C(  6741),  INT16_C( 21476), -INT16_C( 32351),  INT16_C( 11296),  INT16_C(  4310), -INT16_C( 29246), -INT16_C(  6240), -INT16_C( 26445) },
      {  INT8_C(  42), -INT8_C(  14), -INT8_C(  48),  INT8_C(  16),  INT8_C( 107), -INT8_C(  31), -INT8_C(  48),  INT8_C(  89) },
      {  INT8_C(  74),  INT8_C( 124),  INT8_C(  52), -INT8_C( 124),  INT8_C(  26), -INT8_C(  72), -INT8_C(  12),  INT8_C(  22) },
      { -INT8_C(  46), -INT8_C(  97),  INT8_C(  13),  INT8_C(  97), -INT8_C( 122),  INT8_C( 110),  INT8_C(  61), -INT8_C(  59) },
      {  INT8_C( 105),  INT8_C(  79),  INT8_C(   6), -INT8_C(  80),  INT8_C(  67),  INT8_C(  55), -INT8_C(  98),  INT8_C(  98) },
      {  INT8_C(  26),  INT8_C(  83), -INT8_C( 127),  INT8_C(  44),  INT8_C(  16), -INT8_C( 115), -INT8_C(  25), -INT8_C( 104) } },
    { {  INT16_C( 11615), -INT16_C( 11508), -INT16_C(  4296), -INT16_C( 14439), -INT16_C( 15492),  INT16_C( 11205),  INT16_C( 16637),  INT16_C( 21157) },
      { -INT8_C(  81), -INT8_C( 122), -INT8_C( 100), -INT8_C(  52), -INT8_C(  66), -INT8_C(  30),  INT8_C( 126),  INT8_C(  82) },
      { -INT8_C(  85),  INT8_C(  97), -INT8_C(  25), -INT8_C(  13),  INT8_C( 111),  INT8_C( 120),  INT8_C(  31),  INT8_C(  84) },
      {  INT8_C( 106), -INT8_C( 104),  INT8_C( 121),  INT8_C(  60),  INT8_C(  27),  INT8_C(  94),  INT8_C(   7), -INT8_C( 107) },
      { -INT8_C(  75),  INT8_C(  76), -INT8_C(  68),  INT8_C(  30),  INT8_C(  13), -INT8_C(  81),  INT8_C(   3),  INT8_C(  74) },
      {  INT8_C(  45), -INT8_C(  45), -INT8_C(  17), -INT8_C(  57), -INT8_C(  61),  INT8_C(  43),  INT8_C(  64),  INT8_C(  82) } },
    { { -INT16_C( 30374), -INT16_C(   859), -INT16_C( 14838), -INT16_C(  8152), -INT16_C(  5418),  INT16_C( 30317),  INT16_C(  8401),  INT16_C( 12302) },
      { -INT8_C(  83),  INT8_C(  82),  INT8_C(   5),  INT8_C(  20),  INT8_C( 107),  INT8_C(  54),  INT8_C( 104),  INT8_C(   7) },
      {  INT8_C(  43), -INT8_C( 108), -INT8_C(  63),  INT8_C(   5),  INT8_C(  90), -INT8_C(  51),  INT8_C(  26),  INT8_C(   1) },
      {  INT8_C(  74), -INT8_C(  27),  INT8_C(  48),  INT8_C(   1),  INT8_C(  86), -INT8_C(  77),  INT8_C(   6),      INT8_MIN },
      {  INT8_C(  37), -INT8_C(  14),  INT8_C(  24),      INT8_MIN, -INT8_C(  85), -INT8_C(  39), -INT8_C( 125), -INT8_C(  64) },
      { -INT8_C( 119), -INT8_C(   4), -INT8_C(  58), -INT8_C(  32), -INT8_C(  22),  INT8_C( 118),  INT8_C(  32),  INT8_C(  48) } },
    { {  INT16_C(  6989), -INT16_C( 31229), -INT16_C( 25334), -INT16_C( 31155),  INT16_C(  4704),  INT16_C( 23985),  INT16_C( 22099), -INT16_C( 21073) },
      { -INT8_C(  90),  INT8_C(   1), -INT8_C( 123),  INT8_C(  38),  INT8_C(  48), -INT8_C(  40),  INT8_C(  41), -INT8_C(  41) },
      {  INT8_C( 105), -INT8_C(  64), -INT8_C(  95), -INT8_C(  55),  INT8_C(  76), -INT8_C(  74), -INT8_C(  54), -INT8_C(  75) },
      { -INT8_C(  38),  INT8_C(  48), -INT8_C(  24),  INT8_C(  50), -INT8_C( 109), -INT8_C(  19), -INT8_C(  78),  INT8_C( 109) },
      {  INT8_C( 109),  INT8_C(  24),  INT8_C( 116),  INT8_C(  25),  INT8_C(  73),  INT8_C( 118),  INT8_C(  89), -INT8_C(  74) },
      {  INT8_C(  27), -INT8_C( 122), -INT8_C(  99), -INT8_C( 122),  INT8_C(  18),  INT8_C(  93),  INT8_C(  86), -INT8_C(  83) } },
    { {  INT16_C( 21983), -INT16_C(  5719), -INT16_C( 12005), -INT16_C(  3639),  INT16_C( 14011), -INT16_C( 29593),  INT16_C( 30039), -INT16_C( 23364) },
      { -INT8_C(  17), -INT8_C(  44), -INT8_C( 115), -INT8_C(  28),  INT8_C(  93),  INT8_C(  51), -INT8_C(  85),  INT8_C(  94) },
      { -INT8_C(  69),  INT8_C(  53),  INT8_C(  35),  INT8_C(  57), -INT8_C(  41), -INT8_C( 116), -INT8_C(  86), -INT8_C( 105) },
      { -INT8_C(  82),  INT8_C(  77), -INT8_C( 120), -INT8_C( 114), -INT8_C(  75),  INT8_C(  99), -INT8_C(  86),  INT8_C(  37) },
      {  INT8_C(  87), -INT8_C(  90),  INT8_C(  68), -INT8_C(  57), -INT8_C(  38),  INT8_C(  49), -INT8_C(  43), -INT8_C( 110) },
      {  INT8_C(  85), -INT8_C(  23), -INT8_C(  47), -INT8_C(  15),  INT8_C(  54), -INT8_C( 116),  INT8_C( 117), -INT8_C(  92) } },
    { { -INT16_C( 16240), -INT16_C( 25814),  INT16_C( 30813), -INT16_C( 17119), -INT16_C( 11382), -INT16_C(  8933), -INT16_C( 13783),  INT16_C(  2443) },
      {  INT8_C(  72), -INT8_C( 107),  INT8_C(  46), -INT8_C( 112), -INT8_C(  59), -INT8_C( 115),  INT8_C(  20), -INT8_C(  59) },
      {  INT8_C(  18),  INT8_C( 101),  INT8_C(  11), -INT8_C(  92),  INT8_C( 113), -INT8_C(  93),  INT8_C(  69),  INT8_C(  49) },
      {  INT8_C(   4), -INT8_C(  39), -INT8_C(  62), -INT8_C(  23), -INT8_C( 100), -INT8_C(  24),  INT8_C(  81),  INT8_C(  76) },
      {  INT8_C(   2),  INT8_C( 108), -INT8_C(  31), -INT8_C(  12),  INT8_C(  78),  INT8_C( 116),  INT8_C(  40),  INT8_C(  38) },
      { -INT8_C(  64), -INT8_C( 101),  INT8_C( 120), -INT8_C(  67), -INT8_C(  45), -INT8_C(  35), -INT8_C(  54),  INT8_C(   9) } },
    { {  INT16_C( 13343),  INT16_C( 15090), -INT16_C( 17402), -INT16_C( 16085), -INT16_C( 27918),  INT16_C( 18766),  INT16_C(  2568), -INT16_C( 26386) },
      {  INT8_C(  15),  INT8_C( 121),  INT8_C(   3), -INT8_C( 107),  INT8_C( 121), -INT8_C(  89),  INT8_C(   4),  INT8_C( 119) },
      { -INT8_C( 125),  INT8_C(  94),      INT8_MIN,  INT8_C(  37),  INT8_C(  94),  INT8_C(  41),  INT8_C(  65),  INT8_C(  29) },
      { -INT8_C(  96), -INT8_C(  41), -INT8_C(  32),  INT8_C(   9), -INT8_C( 105),  INT8_C(  74),  INT8_C(  80), -INT8_C(  57) },
      { -INT8_C(  48), -INT8_C(  21), -INT8_C(  16),  INT8_C(   4),  INT8_C(  75),  INT8_C(  37),  INT8_C(  40),  INT8_C(  99) },
      {  INT8_C(  52),  INT8_C(  58), -INT8_C(  68), -INT8_C(  63), -INT8_C( 110),  INT8_C(  73),  INT8_C(  10), -INT8_C( 104) } },
    { {  INT16_C(  6346),  INT16_C( 10035),  INT16_C( 21904),  INT16_C(  7141),  INT16_C(    40),  INT16_C( 20984), -INT16_C( 31798), -INT16_C(  5542) },
      {  INT8_C( 101), -INT8_C( 103), -INT8_C(  56), -INT8_C(  14),  INT8_C(  20), -INT8_C(   4), -INT8_C(  27),  INT8_C(  45) },
      {  INT8_C(  25), -INT8_C(  26), -INT8_C(  78),  INT8_C( 124),  INT8_C(   5),  INT8_C(  63),  INT8_C( 121),  INT8_C(  75) },
      { -INT8_C(  58),  INT8_C(  57), -INT8_C(  84), -INT8_C(  33),  INT8_C(   1), -INT8_C( 113),  INT8_C(  30),  INT8_C(  82) },
      {  INT8_C(  99), -INT8_C( 100),  INT8_C(  86),  INT8_C( 111),  INT8_C(   0),  INT8_C(  71),  INT8_C(  15), -INT8_C(  87) },
      {  INT8_C(  24),  INT8_C(  39),  INT8_C(  85),  INT8_C(  27),  INT8_C(   0),  INT8_C(  81), -INT8_C( 125), -INT8_C(  22) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_int8x8_t r1 = simde_vshrn_n_s16(a, 1);
    simde_int8x8_t r3 = simde_vshrn_n_s16(a, 3);
    simde_int8x8_t r5 = simde_vshrn_n_s16(a, 5);
    simde_int8x8_t r6 = simde_vshrn_n_s16(a, 6);
    simde_int8x8_t r8 = simde_vshrn_n_s16(a, 8);

    simde_test_arm_neon_assert_equal_i8x8(r1, simde_vld1_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r6, simde_vld1_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x8(r8, simde_vld1_s8(test_vec[i].r8));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);

    simde_int8x8_t r1 = simde_vshrn_n_s16(a, 1);
    simde_int8x8_t r3 = simde_vshrn_n_s16(a, 3);
    simde_int8x8_t r5 = simde_vshrn_n_s16(a, 5);
    simde_int8x8_t r6 = simde_vshrn_n_s16(a, 6);
    simde_int8x8_t r8 = simde_vshrn_n_s16(a, 8);

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
test_simde_vshrn_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { { -INT32_C(   103108702),  INT32_C(   693033320), -INT32_C(  2062662115), -INT32_C(  1162446484) },
      {  INT16_C( 22004), -INT16_C(  9427), -INT16_C( 14141), -INT16_C( 12499) },
      {  INT16_C( 27326),  INT16_C( 15205),  INT16_C( 14616), -INT16_C(  9755) },
      {  INT16_C( 30379),  INT16_C( 21430),  INT16_C( 17297), -INT16_C( 21090) },
      { -INT16_C( 12587),  INT16_C( 19062),  INT16_C( 10354), -INT16_C( 10829) },
      { -INT16_C(  1574),  INT16_C( 10574), -INT16_C( 31474), -INT16_C( 17738) } },
    { {  INT32_C(    16690099), -INT32_C(  1715623680),  INT32_C(   323000541),  INT32_C(  2013330390) },
      { -INT16_C( 10890), -INT16_C( 19168),  INT16_C(  4891),  INT16_C(  8058) },
      { -INT16_C(  1362), -INT16_C(  2396),  INT16_C(   611),  INT16_C(  1007) },
      {  INT16_C( 16298),  INT16_C( 28522), -INT16_C( 12250),  INT16_C(    62) },
      {  INT16_C(  2037), -INT16_C( 12819), -INT16_C( 26108), -INT16_C( 16377) },
      {  INT16_C(   254), -INT16_C( 26179),  INT16_C(  4928),  INT16_C( 30720) } },
    { {  INT32_C(   309516970), -INT32_C(   801390413),  INT32_C(  1934969350),  INT32_C(  1999441091) },
      {  INT16_C( 23381),  INT16_C( 30742), -INT16_C( 22208), -INT16_C( 24168) },
      { -INT16_C( 13462), -INT16_C(  4350),  INT16_C( 21800), -INT16_C( 19405) },
      { -INT16_C( 25418),  INT16_C(  3824), -INT16_C( 10926), -INT16_C( 13501) },
      { -INT16_C( 27754), -INT16_C( 32290), -INT16_C( 25942), -INT16_C( 18072) },
      {  INT16_C(  4722), -INT16_C( 12229),  INT16_C( 29525),  INT16_C( 30509) } },
    { { -INT32_C(  1200149321), -INT32_C(  1303300907), -INT32_C(  1547267635),  INT32_C(   924632716) },
      { -INT16_C(  6762),  INT16_C(  9882), -INT16_C( 11719), -INT16_C( 26415) },
      { -INT16_C(  9038),  INT16_C( 17619),  INT16_C(  6727),  INT16_C( 29466) },
      {  INT16_C(  7627), -INT16_C( 27571), -INT16_C(  3676), -INT16_C( 14543) },
      { -INT16_C( 15431), -INT16_C( 28023),  INT16_C(  7732), -INT16_C( 18202) },
      { -INT16_C( 18313), -INT16_C( 19887), -INT16_C( 23610),  INT16_C( 14108) } },
    { {  INT32_C(  1397329568),  INT32_C(  1411614030), -INT32_C(  1832420913),  INT32_C(  1007285637) },
      {  INT16_C( 12756),  INT16_C( 28841), -INT16_C(  4295),  INT16_C( 16048) },
      {  INT16_C(  9786), -INT16_C( 29163),  INT16_C(  7655),  INT16_C( 10198) },
      { -INT16_C( 11677),  INT16_C(  2273), -INT16_C( 20002),  INT16_C(   637) },
      { -INT16_C( 26036), -INT16_C( 24292), -INT16_C( 27077), -INT16_C(  8113) },
      {  INT16_C( 21321),  INT16_C( 21539), -INT16_C( 27961),  INT16_C( 15369) } },
    { { -INT32_C(   151748319), -INT32_C(  2102835531),  INT32_C(  1680240599), -INT32_C(   711245259) },
      { -INT16_C( 28636),  INT16_C( 10454), -INT16_C( 12806),  INT16_C( 26694) },
      { -INT16_C( 11772), -INT16_C( 23270), -INT16_C( 26177),  INT16_C( 27912) },
      { -INT16_C( 17120), -INT16_C( 21935),  INT16_C(  2459),  INT16_C( 26320) },
      { -INT16_C( 18524),  INT16_C(  5450),  INT16_C(  8499), -INT16_C( 21286) },
      { -INT16_C(  2316), -INT16_C( 32087),  INT16_C( 25638), -INT16_C( 10853) } },
    { {  INT32_C(   505996496),  INT32_C(   947014505),  INT32_C(  1238055620),  INT32_C(  1351013423) },
      {  INT16_C(  7322),  INT16_C( 18797),  INT16_C( 26456), -INT16_C(  9595) },
      { -INT16_C( 23661), -INT16_C( 14035),  INT16_C( 11499),  INT16_C(  6992) },
      { -INT16_C( 30151),  INT16_C(  7314),  INT16_C( 29390),  INT16_C(  8629) },
      { -INT16_C(  3769), -INT16_C( 15470),  INT16_C( 20057), -INT16_C( 31690) },
      {  INT16_C(  7720),  INT16_C( 14450),  INT16_C( 18891),  INT16_C( 20614) } },
    { {  INT32_C(   189168213), -INT32_C(  1735528512), -INT32_C(  1812155554), -INT32_C(   983001099) },
      { -INT16_C( 12470), -INT16_C( 16904), -INT16_C( 27029),  INT16_C(  4862) },
      {  INT16_C(  6633),  INT16_C( 14271), -INT16_C(  3379), -INT16_C( 23969) },
      { -INT16_C( 11874),  INT16_C(  9083), -INT16_C(   212),  INT16_C( 23077) },
      {  INT16_C( 23091), -INT16_C( 15249), -INT16_C( 24603),  INT16_C( 11076) },
      {  INT16_C(  2886), -INT16_C( 26483), -INT16_C( 27652), -INT16_C( 15000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_int16x4_t r3 = simde_vshrn_n_s32(a, 3);
    simde_int16x4_t r6 = simde_vshrn_n_s32(a, 6);
    simde_int16x4_t r10 = simde_vshrn_n_s32(a, 10);
    simde_int16x4_t r13 = simde_vshrn_n_s32(a, 13);
    simde_int16x4_t r16 = simde_vshrn_n_s32(a, 16);

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r16, simde_vld1_s16(test_vec[i].r16));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);

    simde_int16x4_t r3 = simde_vshrn_n_s32(a, 3);
    simde_int16x4_t r6 = simde_vshrn_n_s32(a, 6);
    simde_int16x4_t r10 = simde_vshrn_n_s32(a, 10);
    simde_int16x4_t r13 = simde_vshrn_n_s32(a, 13);
    simde_int16x4_t r16 = simde_vshrn_n_s32(a, 16);

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
test_simde_vshrn_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec[] = {
    { { -INT64_C( 8775898798952204204),  INT64_C( 2508671492127885583) },
      {  INT32_C(   671003873), -INT32_C(  1192642012) },
      { -INT32_C(   196084375), -INT32_C(  1150168204) },
      { -INT32_C(  1211023371),  INT32_C(   317572941) },
      { -INT32_C(  1922063745), -INT32_C(  1272587378) },
      { -INT32_C(  2043298167),  INT32_C(   584095598) } },
    { { -INT64_C(  994113294087386872),  INT64_C( 4827313367633509697) },
      { -INT32_C(   411191772), -INT32_C(  1174066955) },
      { -INT32_C(  1714488468),  INT32_C(  2138311249) },
      { -INT32_C(  2040054803), -INT32_C(  1040330711) },
      { -INT32_C(  1928540553), -INT32_C(  1081869408) },
      { -INT32_C(   231460039),  INT32_C(  1123946478) } },
    { {  INT64_C( 8671249428897704775),  INT64_C( 7246435133944939776) },
      { -INT32_C(  1488910675),  INT32_C(  1908067092) },
      { -INT32_C(  1152482803),  INT32_C(   316896662) },
      { -INT32_C(   823313912),  INT32_C(   273386966) },
      {  INT32_C(   362666612),  INT32_C(   606115611) },
      {  INT32_C(  2018932585),  INT32_C(  1687192156) } },
    { {  INT64_C( 8230177897525280011), -INT64_C( 2817580384027180619) },
      { -INT32_C(   988737548),  INT32_C(  1183829510) },
      { -INT32_C(  1182129633), -INT32_C(  1936908388) },
      { -INT32_C(   286906232), -INT32_C(  1104006018) },
      { -INT32_C(  1914844079),  INT32_C(   964453480) },
      {  INT32_C(  1916237617), -INT32_C(   656019055) } },
    { { -INT64_C( 7097954912819403108), -INT64_C( 4718474216426688316) },
      {  INT32_C(  1947640986), -INT32_C(   864014141) },
      { -INT32_C(    51892919), -INT32_C(   442957727) },
      { -INT32_C(   537681739), -INT32_C(  1818860543) },
      {  INT32_C(  1606412097), -INT32_C(  1591268152) },
      { -INT32_C(  1652621411), -INT32_C(  1098605389) } },
    { { -INT64_C(  847457109212411750), -INT64_C( 4817307743942135621) },
      { -INT32_C(    13889758), -INT32_C(  2060297022) },
      { -INT32_C(   771860450), -INT32_C(   519412551) },
      { -INT32_C(  1488455328), -INT32_C(  1350293102) },
      {  INT32_C(   256806898),  INT32_C(  1230964819) },
      { -INT32_C(   197313985), -INT32_C(  1121616863) } },
    { { -INT64_C( 7863776649043325277),  INT64_C( 2369517403231152753) },
      {  INT32_C(   889391930),  INT32_C(   412273577) },
      {  INT32_C(   107611670), -INT32_C(  1137629801) },
      { -INT32_C(   937842664),  INT32_C(  1190184086) },
      { -INT32_C(  1215286448),  INT32_C(   948822409) },
      { -INT32_C(  1830928179),  INT32_C(   551696262) } },
    { { -INT64_C( 2651731640926345729), -INT64_C( 1569983550232999336) },
      {  INT32_C(  2096869271),  INT32_C(   501522217) },
      {  INT32_C(  1090123615),  INT32_C(  1648085310) },
      {  INT32_C(  1694754781), -INT32_C(   913772764) },
      { -INT32_C(   859174961), -INT32_C(  1919741474) },
      { -INT32_C(   617404385), -INT32_C(   365540281) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_int32x2_t r6 = simde_vshrn_n_s64(a, 6);
    simde_int32x2_t r13 = simde_vshrn_n_s64(a, 13);
    simde_int32x2_t r19 = simde_vshrn_n_s64(a, 19);
    simde_int32x2_t r26 = simde_vshrn_n_s64(a, 26);
    simde_int32x2_t r32 = simde_vshrn_n_s64(a, 32);

    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r32, simde_vld1_s32(test_vec[i].r32));
  }

  return 0;
#else
  for (int i = 0 ; i < 8; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);

    simde_int32x2_t r6 = simde_vshrn_n_s64(a, 6);
    simde_int32x2_t r13 = simde_vshrn_n_s64(a, 13);
    simde_int32x2_t r19 = simde_vshrn_n_s64(a, 19);
    simde_int32x2_t r26 = simde_vshrn_n_s64(a, 26);
    simde_int32x2_t r32 = simde_vshrn_n_s64(a, 32);

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
test_simde_vshrn_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec[] = {
    { { UINT16_C(40011), UINT16_C(32461), UINT16_C(21043), UINT16_C(45018), UINT16_C(50823), UINT16_C(63535), UINT16_C(53122), UINT16_C(64347) },
      { UINT8_C( 37), UINT8_C(102), UINT8_C( 25), UINT8_C(237), UINT8_C( 67), UINT8_C( 23), UINT8_C(193), UINT8_C(173) },
      { UINT8_C(137), UINT8_C(217), UINT8_C( 70), UINT8_C(251), UINT8_C(208), UINT8_C(  5), UINT8_C(240), UINT8_C(107) },
      { UINT8_C(226), UINT8_C(246), UINT8_C(145), UINT8_C(126), UINT8_C( 52), UINT8_C(193), UINT8_C(124), UINT8_C(218) },
      { UINT8_C(113), UINT8_C(251), UINT8_C( 72), UINT8_C(191), UINT8_C( 26), UINT8_C(224), UINT8_C( 62), UINT8_C(237) },
      { UINT8_C(156), UINT8_C(126), UINT8_C( 82), UINT8_C(175), UINT8_C(198), UINT8_C(248), UINT8_C(207), UINT8_C(251) } },
    { { UINT16_C(36705), UINT16_C(46651), UINT16_C(20159), UINT16_C(63576), UINT16_C(48442), UINT16_C(57377), UINT16_C(20703), UINT16_C(11011) },
      { UINT8_C(176), UINT8_C( 29), UINT8_C( 95), UINT8_C( 44), UINT8_C(157), UINT8_C( 16), UINT8_C(111), UINT8_C(129) },
      { UINT8_C(236), UINT8_C(199), UINT8_C(215), UINT8_C( 11), UINT8_C(167), UINT8_C(  4), UINT8_C( 27), UINT8_C( 96) },
      { UINT8_C(123), UINT8_C(177), UINT8_C(117), UINT8_C(194), UINT8_C(233), UINT8_C(  1), UINT8_C(134), UINT8_C( 88) },
      { UINT8_C( 61), UINT8_C(216), UINT8_C( 58), UINT8_C(225), UINT8_C(244), UINT8_C(128), UINT8_C( 67), UINT8_C(172) },
      { UINT8_C(143), UINT8_C(182), UINT8_C( 78), UINT8_C(248), UINT8_C(189), UINT8_C(224), UINT8_C( 80), UINT8_C( 43) } },
    { { UINT16_C(53740), UINT16_C( 8361), UINT16_C(33571), UINT16_C(43727), UINT16_C(65097), UINT16_C(52386), UINT16_C(64973), UINT16_C(12231) },
      { UINT8_C(246), UINT8_C( 84), UINT8_C(145), UINT8_C(103), UINT8_C( 36), UINT8_C( 81), UINT8_C(230), UINT8_C(227) },
      { UINT8_C( 61), UINT8_C( 21), UINT8_C(100), UINT8_C( 89), UINT8_C(201), UINT8_C(148), UINT8_C(185), UINT8_C(248) },
      { UINT8_C(143), UINT8_C(  5), UINT8_C( 25), UINT8_C( 86), UINT8_C(242), UINT8_C(101), UINT8_C(238), UINT8_C(126) },
      { UINT8_C( 71), UINT8_C(130), UINT8_C( 12), UINT8_C(171), UINT8_C(249), UINT8_C( 50), UINT8_C(247), UINT8_C(191) },
      { UINT8_C(209), UINT8_C( 32), UINT8_C(131), UINT8_C(170), UINT8_C(254), UINT8_C(204), UINT8_C(253), UINT8_C( 47) } },
    { { UINT16_C(  908), UINT16_C(19429), UINT16_C(15697), UINT16_C(35651), UINT16_C(25851), UINT16_C(55915), UINT16_C(28596), UINT16_C(41221) },
      { UINT8_C(198), UINT8_C(242), UINT8_C(168), UINT8_C(161), UINT8_C(125), UINT8_C( 53), UINT8_C(218), UINT8_C(130) },
      { UINT8_C(113), UINT8_C(124), UINT8_C(170), UINT8_C(104), UINT8_C(159), UINT8_C( 77), UINT8_C(246), UINT8_C( 32) },
      { UINT8_C( 28), UINT8_C( 95), UINT8_C(234), UINT8_C( 90), UINT8_C( 39), UINT8_C(211), UINT8_C(125), UINT8_C(  8) },
      { UINT8_C( 14), UINT8_C( 47), UINT8_C(245), UINT8_C( 45), UINT8_C(147), UINT8_C(105), UINT8_C(190), UINT8_C(132) },
      { UINT8_C(  3), UINT8_C( 75), UINT8_C( 61), UINT8_C(139), UINT8_C(100), UINT8_C(218), UINT8_C(111), UINT8_C(161) } },
    { { UINT16_C(44608), UINT16_C(25537), UINT16_C(36914), UINT16_C(31502), UINT16_C(45198), UINT16_C(23623), UINT16_C( 4014), UINT16_C(14987) },
      { UINT8_C( 32), UINT8_C(224), UINT8_C( 25), UINT8_C(135), UINT8_C( 71), UINT8_C( 35), UINT8_C(215), UINT8_C( 69) },
      { UINT8_C(200), UINT8_C(120), UINT8_C(  6), UINT8_C( 97), UINT8_C( 17), UINT8_C(136), UINT8_C(245), UINT8_C( 81) },
      { UINT8_C(114), UINT8_C( 30), UINT8_C(129), UINT8_C(216), UINT8_C(132), UINT8_C(226), UINT8_C(125), UINT8_C(212) },
      { UINT8_C(185), UINT8_C(143), UINT8_C( 64), UINT8_C(236), UINT8_C(194), UINT8_C(113), UINT8_C( 62), UINT8_C(234) },
      { UINT8_C(174), UINT8_C( 99), UINT8_C(144), UINT8_C(123), UINT8_C(176), UINT8_C( 92), UINT8_C( 15), UINT8_C( 58) } },
    { { UINT16_C(28690), UINT16_C(25478), UINT16_C(51630), UINT16_C(43502), UINT16_C(22830), UINT16_C(57987), UINT16_C(35272), UINT16_C( 2179) },
      { UINT8_C(  9), UINT8_C(195), UINT8_C(215), UINT8_C(247), UINT8_C(151), UINT8_C( 65), UINT8_C(228), UINT8_C( 65) },
      { UINT8_C(  2), UINT8_C(112), UINT8_C( 53), UINT8_C( 61), UINT8_C( 37), UINT8_C( 80), UINT8_C( 57), UINT8_C( 16) },
      { UINT8_C(128), UINT8_C( 28), UINT8_C( 77), UINT8_C( 79), UINT8_C(201), UINT8_C( 20), UINT8_C( 78), UINT8_C( 68) },
      { UINT8_C(192), UINT8_C(142), UINT8_C( 38), UINT8_C(167), UINT8_C(100), UINT8_C(138), UINT8_C( 39), UINT8_C( 34) },
      { UINT8_C(112), UINT8_C( 99), UINT8_C(201), UINT8_C(169), UINT8_C( 89), UINT8_C(226), UINT8_C(137), UINT8_C(  8) } },
    { { UINT16_C(17463), UINT16_C(26988), UINT16_C(31444), UINT16_C(25573), UINT16_C(11306), UINT16_C(55487), UINT16_C(19003), UINT16_C(19731) },
      { UINT8_C( 27), UINT8_C(182), UINT8_C(106), UINT8_C(242), UINT8_C( 21), UINT8_C( 95), UINT8_C( 29), UINT8_C(137) },
      { UINT8_C(134), UINT8_C( 45), UINT8_C( 90), UINT8_C(124), UINT8_C(133), UINT8_C( 23), UINT8_C( 71), UINT8_C(162) },
      { UINT8_C( 33), UINT8_C( 75), UINT8_C(214), UINT8_C( 31), UINT8_C( 97), UINT8_C(197), UINT8_C( 81), UINT8_C(104) },
      { UINT8_C( 16), UINT8_C(165), UINT8_C(235), UINT8_C(143), UINT8_C(176), UINT8_C( 98), UINT8_C( 40), UINT8_C( 52) },
      { UINT8_C( 68), UINT8_C(105), UINT8_C(122), UINT8_C( 99), UINT8_C( 44), UINT8_C(216), UINT8_C( 74), UINT8_C( 77) } },
    { { UINT16_C(39354), UINT16_C(26800), UINT16_C(40546), UINT16_C(36881), UINT16_C(38392), UINT16_C(49267), UINT16_C(63006), UINT16_C(21961) },
      { UINT8_C(221), UINT8_C( 88), UINT8_C( 49), UINT8_C(  8), UINT8_C(252), UINT8_C( 57), UINT8_C( 15), UINT8_C(228) },
      { UINT8_C( 55), UINT8_C( 22), UINT8_C(204), UINT8_C(  2), UINT8_C(191), UINT8_C( 14), UINT8_C(195), UINT8_C(185) },
      { UINT8_C(205), UINT8_C( 69), UINT8_C(243), UINT8_C(128), UINT8_C(175), UINT8_C(  3), UINT8_C(176), UINT8_C(174) },
      { UINT8_C(102), UINT8_C(162), UINT8_C(121), UINT8_C( 64), UINT8_C( 87), UINT8_C(  1), UINT8_C(216), UINT8_C( 87) },
      { UINT8_C(153), UINT8_C(104), UINT8_C(158), UINT8_C(144), UINT8_C(149), UINT8_C(192), UINT8_C(246), UINT8_C( 85) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);

    simde_uint8x8_t r1 = simde_vshrn_n_u16(a, 1);
    simde_uint8x8_t r3 = simde_vshrn_n_u16(a, 3);
    simde_uint8x8_t r5 = simde_vshrn_n_u16(a, 5);
    simde_uint8x8_t r6 = simde_vshrn_n_u16(a, 6);
    simde_uint8x8_t r8 = simde_vshrn_n_u16(a, 8);

    simde_test_arm_neon_assert_equal_u8x8(r1, simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r6, simde_vld1_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x8(r8, simde_vld1_u8(test_vec[i].r8));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint8x8_t r1 = simde_vshrn_n_u16(a, 1);
    simde_uint8x8_t r3 = simde_vshrn_n_u16(a, 3);
    simde_uint8x8_t r5 = simde_vshrn_n_u16(a, 5);
    simde_uint8x8_t r6 = simde_vshrn_n_u16(a, 6);
    simde_uint8x8_t r8 = simde_vshrn_n_u16(a, 8);

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
test_simde_vshrn_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { UINT32_C(2020230017), UINT32_C(2991737982), UINT32_C( 927153001), UINT32_C(1266960713) },
      { UINT16_C(18544), UINT16_C(18831), UINT16_C(26477), UINT16_C(35113) },
      { UINT16_C(43278), UINT16_C(18737), UINT16_C( 3309), UINT16_C( 4389) },
      { UINT16_C( 6800), UINT16_C(38035), UINT16_C(53454), UINT16_C(57618) },
      { UINT16_C(50002), UINT16_C(37522), UINT16_C(47641), UINT16_C(23586) },
      { UINT16_C(30826), UINT16_C(45650), UINT16_C(14147), UINT16_C(19332) } },
    { { UINT32_C(3127336953), UINT32_C(2781462628), UINT32_C(1050575021), UINT32_C(   9081471) },
      { UINT16_C(60415), UINT16_C(14348), UINT16_C(53269), UINT16_C(21071) },
      { UINT16_C(40319), UINT16_C( 9985), UINT16_C(31234), UINT16_C(10825) },
      { UINT16_C(39383), UINT16_C(29296), UINT16_C(42912), UINT16_C( 8868) },
      { UINT16_C(54074), UINT16_C(11854), UINT16_C(62708), UINT16_C( 1108) },
      { UINT16_C(47719), UINT16_C(42441), UINT16_C(16030), UINT16_C(  138) } },
    { { UINT32_C(1400435925), UINT32_C(2835728960), UINT32_C(1340098566), UINT32_C(2325374353) },
      { UINT16_C( 7834), UINT16_C(47432), UINT16_C( 2304), UINT16_C(19634) },
      { UINT16_C(58323), UINT16_C( 5929), UINT16_C(33056), UINT16_C(27030) },
      { UINT16_C(56893), UINT16_C(16754), UINT16_C(63506), UINT16_C(42649) },
      { UINT16_C(39879), UINT16_C(18478), UINT16_C(32514), UINT16_C(21715) },
      { UINT16_C(21368), UINT16_C(43269), UINT16_C(20448), UINT16_C(35482) } },
    { { UINT32_C( 675545540), UINT32_C(1875709378), UINT32_C( 229469326), UINT32_C(3540858878) },
      { UINT16_C(32824), UINT16_C(41400), UINT16_C(44433), UINT16_C(42751) },
      { UINT16_C( 4103), UINT16_C(13367), UINT16_C(46514), UINT16_C(13535) },
      { UINT16_C( 4352), UINT16_C(62275), UINT16_C(27483), UINT16_C(49997) },
      { UINT16_C(16928), UINT16_C(32360), UINT16_C(28011), UINT16_C(39017) },
      { UINT16_C(10308), UINT16_C(28621), UINT16_C( 3501), UINT16_C(54029) } },
    { { UINT32_C(1797686571), UINT32_C(1444228176), UINT32_C( 111539572), UINT32_C( 529547098) },
      { UINT16_C(53413), UINT16_C(42378), UINT16_C(48814), UINT16_C( 2027) },
      { UINT16_C(39444), UINT16_C(21681), UINT16_C(38869), UINT16_C(16637) },
      { UINT16_C(51617), UINT16_C(34123), UINT16_C(43389), UINT16_C(58383) },
      { UINT16_C(22836), UINT16_C(45225), UINT16_C(13615), UINT16_C(64641) },
      { UINT16_C(27430), UINT16_C(22037), UINT16_C( 1701), UINT16_C( 8080) } },
    { { UINT32_C(  38262080), UINT32_C(1886459362), UINT32_C(2138906497), UINT32_C(2186447446) },
      { UINT16_C(64168), UINT16_C( 8892), UINT16_C(41968), UINT16_C(20810) },
      { UINT16_C( 8021), UINT16_C(50263), UINT16_C(62590), UINT16_C(18985) },
      { UINT16_C(37365), UINT16_C( 7237), UINT16_C(57159), UINT16_C(38050) },
      { UINT16_C( 4670), UINT16_C(33672), UINT16_C(64488), UINT16_C( 4756) },
      { UINT16_C(  583), UINT16_C(28785), UINT16_C(32637), UINT16_C(33362) } },
    { { UINT32_C(1626175504), UINT32_C( 431358628), UINT32_C(1377786872), UINT32_C(3664883610) },
      { UINT16_C(44802), UINT16_C(49236), UINT16_C(60287), UINT16_C(13811) },
      { UINT16_C(46560), UINT16_C(55306), UINT16_C(32111), UINT16_C(50878) },
      { UINT16_C(15198), UINT16_C(28032), UINT16_C(34774), UINT16_C(40043) },
      { UINT16_C( 1899), UINT16_C(52656), UINT16_C(37114), UINT16_C(54157) },
      { UINT16_C(24813), UINT16_C( 6582), UINT16_C(21023), UINT16_C(55921) } },
    { { UINT32_C(1742584196), UINT32_C(1339510478), UINT32_C(3301856621), UINT32_C(4014350559) },
      { UINT16_C(46896), UINT16_C(59865), UINT16_C(51885), UINT16_C(50203) },
      { UINT16_C(30438), UINT16_C(23867), UINT16_C(14677), UINT16_C( 6275) },
      { UINT16_C(63342), UINT16_C(62931), UINT16_C(13205), UINT16_C(53640) },
      { UINT16_C(16109), UINT16_C(32442), UINT16_C( 9842), UINT16_C(31281) },
      { UINT16_C(26589), UINT16_C(20439), UINT16_C(50382), UINT16_C(61254) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);

    simde_uint16x4_t r3 = simde_vshrn_n_u32(a, 3);
    simde_uint16x4_t r6 = simde_vshrn_n_u32(a, 6);
    simde_uint16x4_t r10 = simde_vshrn_n_u32(a, 10);
    simde_uint16x4_t r13 = simde_vshrn_n_u32(a, 13);
    simde_uint16x4_t r16 = simde_vshrn_n_u32(a, 16);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r16, simde_vld1_u16(test_vec[i].r16));
  }

  return 0;
#else
  for (int i = 0 ; i < 8; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint16x4_t r = simde_vshrn_n_u32(a, 3);
    simde_uint16x4_t r6 = simde_vshrn_n_u32(a, 6);
    simde_uint16x4_t r10 = simde_vshrn_n_u32(a, 10);
    simde_uint16x4_t r13 = simde_vshrn_n_u32(a, 13);
    simde_uint16x4_t r16 = simde_vshrn_n_u32(a, 16);

    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshrn_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { UINT64_C( 6386371456896674993), UINT64_C( 6998908651324563006) },
      { UINT32_C(  61871282), UINT32_C(1487302520) },
      { UINT32_C(2550620201), UINT32_C(4071705822) },
      { UINT32_C( 509615488), UINT32_C( 600491315) },
      { UINT32_C( 675070011), UINT32_C(1212650890) },
      { UINT32_C(1486942976), UINT32_C(1629560406) } },
    { { UINT64_C( 4854841121089230213), UINT64_C( 2606767739742501925) },
      { UINT32_C( 473820758), UINT32_C(3402445552) },
      { UINT32_C(3795352540), UINT32_C(3415579237) },
      { UINT32_C(4220051951), UINT32_C(2737722985) },
      { UINT32_C(3623293379), UINT32_C( 189160620) },
      { UINT32_C(1130355783), UINT32_C( 606935410) } },
    { { UINT64_C( 7250426124232045125), UINT64_C(15944623223288445327) },
      { UINT32_C(2501132489), UINT32_C(1603679462) },
      { UINT32_C(2167023745), UINT32_C(1925131369) },
      { UINT32_C(3590629538), UINT32_C(3586849969) },
      { UINT32_C( 665586001), UINT32_C(1370199545) },
      { UINT32_C(1688121381), UINT32_C(3712396887) } },
    { { UINT64_C(14109297822627840323), UINT64_C( 8763339891409295879) },
      { UINT32_C(1982837509), UINT32_C(3454392424) },
      { UINT32_C(1558994790), UINT32_C( 429640624) },
      { UINT32_C(3379802493), UINT32_C(3026612014) },
      { UINT32_C(4086490978), UINT32_C(1734921438) },
      { UINT32_C(3285076893), UINT32_C(2040374067) } },
    { { UINT64_C(17104209997803204309), UINT64_C(15981614380883372950) },
      { UINT32_C(2078997179), UINT32_C(1807175598) },
      { UINT32_C(3807892981), UINT32_C(3436670623) },
      { UINT32_C(3414941527), UINT32_C(1127439802) },
      { UINT32_C(1469519806), UINT32_C(1921410747) },
      { UINT32_C(3982384222), UINT32_C(3721009562) } },
    { { UINT64_C(  593128255383975643), UINT64_C( 3025890447517200721) },
      { UINT32_C(  98673371), UINT32_C(1377176261) },
      { UINT32_C(3087778629), UINT32_C(4205063189) },
      { UINT32_C(1725968141), UINT32_C(3286929584) },
      { UINT32_C( 248365150), UINT32_C(2139608353) },
      { UINT32_C( 138098433), UINT32_C( 704520020) } },
    { { UINT64_C(12617258875681553613), UINT64_C(16277529703812492398) },
      { UINT32_C(1689293555), UINT32_C( 404911025) },
      { UINT32_C( 281633061), UINT32_C( 942687463) },
      { UINT32_C( 809706884), UINT32_C(2900410643) },
      { UINT32_C(3328214603), UINT32_C(2035925378) },
      { UINT32_C(2937684505), UINT32_C(3789907718) } },
    { { UINT64_C(15431467047197429277), UINT64_C(10863906923554253126) },
      { UINT32_C( 343762232), UINT32_C( 644705957) },
      { UINT32_C(2888366794), UINT32_C(3461143261) },
      { UINT32_C(4071662571), UINT32_C(2335781739) },
      { UINT32_C(2313511239), UINT32_C(2971038310) },
      { UINT32_C(3592918405), UINT32_C(2529450441) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);

    simde_uint32x2_t r6 = simde_vshrn_n_u64(a, 6);
    simde_uint32x2_t r13 = simde_vshrn_n_u64(a, 13);
    simde_uint32x2_t r19 = simde_vshrn_n_u64(a, 19);
    simde_uint32x2_t r26 = simde_vshrn_n_u64(a, 26);
    simde_uint32x2_t r32 = simde_vshrn_n_u64(a, 32);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r32, simde_vld1_u32(test_vec[i].r32));
  }

  return 0;
#else
  for (int i = 0 ; i < 8; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);

    simde_uint32x2_t r6 = simde_vshrn_n_u64(a, 6);
    simde_uint32x2_t r13 = simde_vshrn_n_u64(a, 13);
    simde_uint32x2_t r19 = simde_vshrn_n_u64(a, 19);
    simde_uint32x2_t r26 = simde_vshrn_n_u64(a, 26);
    simde_uint32x2_t r32 = simde_vshrn_n_u64(a, 32);

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
SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_n_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrn_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
