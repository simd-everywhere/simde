#define SIMDE_TEST_ARM_NEON_INSN rshr_n

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/rshr_n.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vrshr_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec[] = {
    { { -INT8_C(  87),  INT8_C(  13),  INT8_C( 107), -INT8_C( 109), -INT8_C(  49), -INT8_C(  33), -INT8_C(  55), -INT8_C(  61) },
      { -INT8_C(  43),  INT8_C(   7),  INT8_C(  54), -INT8_C(  54), -INT8_C(  24), -INT8_C(  16), -INT8_C(  27), -INT8_C(  30) },
      { -INT8_C(  11),  INT8_C(   2),  INT8_C(  13), -INT8_C(  14), -INT8_C(   6), -INT8_C(   4), -INT8_C(   7), -INT8_C(   8) },
      { -INT8_C(   3),  INT8_C(   0),  INT8_C(   3), -INT8_C(   3), -INT8_C(   2), -INT8_C(   1), -INT8_C(   2), -INT8_C(   2) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   2), -INT8_C(   2), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  98), -INT8_C(  18), -INT8_C(  28),  INT8_C(  54), -INT8_C( 125),  INT8_C( 113),  INT8_C(  76), -INT8_C(  98) },
      {  INT8_C(  49), -INT8_C(   9), -INT8_C(  14),  INT8_C(  27), -INT8_C(  62),  INT8_C(  57),  INT8_C(  38), -INT8_C(  49) },
      {  INT8_C(  12), -INT8_C(   2), -INT8_C(   3),  INT8_C(   7), -INT8_C(  16),  INT8_C(  14),  INT8_C(  10), -INT8_C(  12) },
      {  INT8_C(   3), -INT8_C(   1), -INT8_C(   1),  INT8_C(   2), -INT8_C(   4),  INT8_C(   4),  INT8_C(   2), -INT8_C(   3) },
      {  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1), -INT8_C(   2),  INT8_C(   2),  INT8_C(   1), -INT8_C(   2) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  38),  INT8_C(   9), -INT8_C(  38),  INT8_C(  29),  INT8_C(  25), -INT8_C(  16), -INT8_C(  92), -INT8_C(  67) },
      {  INT8_C(  19),  INT8_C(   5), -INT8_C(  19),  INT8_C(  15),  INT8_C(  13), -INT8_C(   8), -INT8_C(  46), -INT8_C(  33) },
      {  INT8_C(   5),  INT8_C(   1), -INT8_C(   5),  INT8_C(   4),  INT8_C(   3), -INT8_C(   2), -INT8_C(  11), -INT8_C(   8) },
      {  INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   1),  INT8_C(   1),  INT8_C(   0), -INT8_C(   3), -INT8_C(   2) },
      {  INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  90), -INT8_C(  49),  INT8_C(  85), -INT8_C(   6), -INT8_C( 126), -INT8_C(  96),  INT8_C( 107),  INT8_C(  44) },
      { -INT8_C(  45), -INT8_C(  24),  INT8_C(  43), -INT8_C(   3), -INT8_C(  63), -INT8_C(  48),  INT8_C(  54),  INT8_C(  22) },
      { -INT8_C(  11), -INT8_C(   6),  INT8_C(  11), -INT8_C(   1), -INT8_C(  16), -INT8_C(  12),  INT8_C(  13),  INT8_C(   6) },
      { -INT8_C(   3), -INT8_C(   2),  INT8_C(   3),  INT8_C(   0), -INT8_C(   4), -INT8_C(   3),  INT8_C(   3),  INT8_C(   1) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   1),  INT8_C(   0), -INT8_C(   2), -INT8_C(   1),  INT8_C(   2),  INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  83), -INT8_C(  41), -INT8_C(  65),  INT8_C( 125), -INT8_C(  74), -INT8_C( 120),  INT8_C(  64),  INT8_C(  24) },
      { -INT8_C(  41), -INT8_C(  20), -INT8_C(  32),  INT8_C(  63), -INT8_C(  37), -INT8_C(  60),  INT8_C(  32),  INT8_C(  12) },
      { -INT8_C(  10), -INT8_C(   5), -INT8_C(   8),  INT8_C(  16), -INT8_C(   9), -INT8_C(  15),  INT8_C(   8),  INT8_C(   3) },
      { -INT8_C(   3), -INT8_C(   1), -INT8_C(   2),  INT8_C(   4), -INT8_C(   2), -INT8_C(   4),  INT8_C(   2),  INT8_C(   1) },
      { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   2), -INT8_C(   1), -INT8_C(   2),  INT8_C(   1),  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 118),  INT8_C(  37),  INT8_C(  78), -INT8_C(   7), -INT8_C( 106), -INT8_C( 101), -INT8_C( 105), -INT8_C(  68) },
      {  INT8_C(  59),  INT8_C(  19),  INT8_C(  39), -INT8_C(   3), -INT8_C(  53), -INT8_C(  50), -INT8_C(  52), -INT8_C(  34) },
      {  INT8_C(  15),  INT8_C(   5),  INT8_C(  10), -INT8_C(   1), -INT8_C(  13), -INT8_C(  13), -INT8_C(  13), -INT8_C(   8) },
      {  INT8_C(   4),  INT8_C(   1),  INT8_C(   2),  INT8_C(   0), -INT8_C(   3), -INT8_C(   3), -INT8_C(   3), -INT8_C(   2) },
      {  INT8_C(   2),  INT8_C(   1),  INT8_C(   1),  INT8_C(   0), -INT8_C(   2), -INT8_C(   2), -INT8_C(   2), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  92),  INT8_C( 113), -INT8_C(  39), -INT8_C(  66),  INT8_C(  97),  INT8_C( 125),  INT8_C( 123),  INT8_C(   7) },
      { -INT8_C(  46),  INT8_C(  57), -INT8_C(  19), -INT8_C(  33),  INT8_C(  49),  INT8_C(  63),  INT8_C(  62),  INT8_C(   4) },
      { -INT8_C(  11),  INT8_C(  14), -INT8_C(   5), -INT8_C(   8),  INT8_C(  12),  INT8_C(  16),  INT8_C(  15),  INT8_C(   1) },
      { -INT8_C(   3),  INT8_C(   4), -INT8_C(   1), -INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   0) },
      { -INT8_C(   1),  INT8_C(   2), -INT8_C(   1), -INT8_C(   1),  INT8_C(   2),  INT8_C(   2),  INT8_C(   2),  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  76), -INT8_C(  48),  INT8_C(   1), -INT8_C(  49),  INT8_C( 112),  INT8_C( 109), -INT8_C(   5),  INT8_C(  30) },
      {  INT8_C(  38), -INT8_C(  24),  INT8_C(   1), -INT8_C(  24),  INT8_C(  56),  INT8_C(  55), -INT8_C(   2),  INT8_C(  15) },
      {  INT8_C(  10), -INT8_C(   6),  INT8_C(   0), -INT8_C(   6),  INT8_C(  14),  INT8_C(  14), -INT8_C(   1),  INT8_C(   4) },
      {  INT8_C(   2), -INT8_C(   1),  INT8_C(   0), -INT8_C(   2),  INT8_C(   4),  INT8_C(   3),  INT8_C(   0),  INT8_C(   1) },
      {  INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   2),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);

    simde_int8x8_t r1 = simde_vrshr_n_s8(a, 1);
    simde_int8x8_t r3 = simde_vrshr_n_s8(a, 3);
    simde_int8x8_t r5 = simde_vrshr_n_s8(a, 5);
    simde_int8x8_t r6 = simde_vrshr_n_s8(a, 6);
    simde_int8x8_t r8 = simde_vrshr_n_s8(a, 8);

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
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();

    simde_int8x8_t r1 = simde_vrshr_n_s8(a, 1);
    simde_int8x8_t r3 = simde_vrshr_n_s8(a, 3);
    simde_int8x8_t r5 = simde_vrshr_n_s8(a, 5);
    simde_int8x8_t r6 = simde_vrshr_n_s8(a, 6);
    simde_int8x8_t r8 = simde_vrshr_n_s8(a, 8);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshr_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { {  INT16_C( 31120), -INT16_C( 21578),  INT16_C( 20732),  INT16_C( 19303) },
      {  INT16_C(  3890), -INT16_C(  2697),  INT16_C(  2592),  INT16_C(  2413) },
      {  INT16_C(   486), -INT16_C(   337),  INT16_C(   324),  INT16_C(   302) },
      {  INT16_C(    30), -INT16_C(    21),  INT16_C(    20),  INT16_C(    19) },
      {  INT16_C(     4), -INT16_C(     3),  INT16_C(     3),  INT16_C(     2) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 31545), -INT16_C(  8212), -INT16_C(   519),  INT16_C( 10785) },
      {  INT16_C(  3943), -INT16_C(  1026), -INT16_C(    65),  INT16_C(  1348) },
      {  INT16_C(   493), -INT16_C(   128), -INT16_C(     8),  INT16_C(   169) },
      {  INT16_C(    31), -INT16_C(     8), -INT16_C(     1),  INT16_C(    11) },
      {  INT16_C(     4), -INT16_C(     1),  INT16_C(     0),  INT16_C(     1) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 26531),  INT16_C( 29321),  INT16_C( 12749),  INT16_C(  5762) },
      {  INT16_C(  3316),  INT16_C(  3665),  INT16_C(  1594),  INT16_C(   720) },
      {  INT16_C(   415),  INT16_C(   458),  INT16_C(   199),  INT16_C(    90) },
      {  INT16_C(    26),  INT16_C(    29),  INT16_C(    12),  INT16_C(     6) },
      {  INT16_C(     3),  INT16_C(     4),  INT16_C(     2),  INT16_C(     1) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 25739),  INT16_C( 24284), -INT16_C( 31873),  INT16_C(  3935) },
      { -INT16_C(  3217),  INT16_C(  3036), -INT16_C(  3984),  INT16_C(   492) },
      { -INT16_C(   402),  INT16_C(   379), -INT16_C(   498),  INT16_C(    61) },
      { -INT16_C(    25),  INT16_C(    24), -INT16_C(    31),  INT16_C(     4) },
      { -INT16_C(     3),  INT16_C(     3), -INT16_C(     4),  INT16_C(     0) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  5629), -INT16_C(  1605),  INT16_C(  8806), -INT16_C( 24764) },
      {  INT16_C(   704), -INT16_C(   201),  INT16_C(  1101), -INT16_C(  3095) },
      {  INT16_C(    88), -INT16_C(    25),  INT16_C(   138), -INT16_C(   387) },
      {  INT16_C(     5), -INT16_C(     2),  INT16_C(     9), -INT16_C(    24) },
      {  INT16_C(     1),  INT16_C(     0),  INT16_C(     1), -INT16_C(     3) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 12701), -INT16_C( 26753), -INT16_C( 24530), -INT16_C( 11839) },
      {  INT16_C(  1588), -INT16_C(  3344), -INT16_C(  3066), -INT16_C(  1480) },
      {  INT16_C(   198), -INT16_C(   418), -INT16_C(   383), -INT16_C(   185) },
      {  INT16_C(    12), -INT16_C(    26), -INT16_C(    24), -INT16_C(    12) },
      {  INT16_C(     2), -INT16_C(     3), -INT16_C(     3), -INT16_C(     1) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 18952), -INT16_C( 10940), -INT16_C( 14725), -INT16_C(  3861) },
      {  INT16_C(  2369), -INT16_C(  1367), -INT16_C(  1841), -INT16_C(   483) },
      {  INT16_C(   296), -INT16_C(   171), -INT16_C(   230), -INT16_C(    60) },
      {  INT16_C(    19), -INT16_C(    11), -INT16_C(    14), -INT16_C(     4) },
      {  INT16_C(     2), -INT16_C(     1), -INT16_C(     2),  INT16_C(     0) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 14495), -INT16_C(  7858), -INT16_C( 20917),  INT16_C( 18672) },
      { -INT16_C(  1812), -INT16_C(   982), -INT16_C(  2615),  INT16_C(  2334) },
      { -INT16_C(   226), -INT16_C(   123), -INT16_C(   327),  INT16_C(   292) },
      { -INT16_C(    14), -INT16_C(     8), -INT16_C(    20),  INT16_C(    18) },
      { -INT16_C(     2), -INT16_C(     1), -INT16_C(     3),  INT16_C(     2) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);

    simde_int16x4_t r3 = simde_vrshr_n_s16(a, 3);
    simde_int16x4_t r6 = simde_vrshr_n_s16(a, 6);
    simde_int16x4_t r10 = simde_vrshr_n_s16(a, 10);
    simde_int16x4_t r13 = simde_vrshr_n_s16(a, 13);
    simde_int16x4_t r16 = simde_vrshr_n_s16(a, 16);

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
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();

    simde_int16x4_t r3 = simde_vrshr_n_s16(a, 3);
    simde_int16x4_t r6 = simde_vrshr_n_s16(a, 6);
    simde_int16x4_t r10 = simde_vrshr_n_s16(a, 10);
    simde_int16x4_t r13 = simde_vrshr_n_s16(a, 13);
    simde_int16x4_t r16 = simde_vrshr_n_s16(a, 16);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshr_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec[] = {
    { { -INT32_C(  1255497128),  INT32_C(  1491892639) },
      { -INT32_C(    19617143),  INT32_C(    23310822) },
      { -INT32_C(      153259),  INT32_C(      182116) },
      { -INT32_C(        2395),  INT32_C(        2846) },
      { -INT32_C(          19),  INT32_C(          22) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   604469756),  INT32_C(  1849346692) },
      { -INT32_C(     9444840),  INT32_C(    28896042) },
      { -INT32_C(       73788),  INT32_C(      225750) },
      { -INT32_C(        1153),  INT32_C(        3527) },
      { -INT32_C(           9),  INT32_C(          28) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   431697936),  INT32_C(   378319482) },
      {  INT32_C(     6745280),  INT32_C(     5911242) },
      {  INT32_C(       52698),  INT32_C(       46182) },
      {  INT32_C(         823),  INT32_C(         722) },
      {  INT32_C(           6),  INT32_C(           6) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  2003865358),  INT32_C(  1929771291) },
      { -INT32_C(    31310396),  INT32_C(    30152676) },
      { -INT32_C(      244612),  INT32_C(      235568) },
      { -INT32_C(        3822),  INT32_C(        3681) },
      { -INT32_C(          30),  INT32_C(          29) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   992489627), -INT32_C(  1382869847) },
      {  INT32_C(    15507650), -INT32_C(    21607341) },
      {  INT32_C(      121154), -INT32_C(      168807) },
      {  INT32_C(        1893), -INT32_C(        2638) },
      {  INT32_C(          15), -INT32_C(          21) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   529042587),  INT32_C(  1720566614) },
      {  INT32_C(     8266290),  INT32_C(    26883853) },
      {  INT32_C(       64580),  INT32_C(      210030) },
      {  INT32_C(        1009),  INT32_C(        3282) },
      {  INT32_C(           8),  INT32_C(          26) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1837058291), -INT32_C(   326956038) },
      {  INT32_C(    28704036), -INT32_C(     5108688) },
      {  INT32_C(      224250), -INT32_C(       39912) },
      {  INT32_C(        3504), -INT32_C(         624) },
      {  INT32_C(          27), -INT32_C(           5) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1753935236), -INT32_C(  1509262837) },
      { -INT32_C(    27405238), -INT32_C(    23582232) },
      { -INT32_C(      214103), -INT32_C(      184236) },
      { -INT32_C(        3345), -INT32_C(        2879) },
      { -INT32_C(          26), -INT32_C(          22) },
      {  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);

    simde_int32x2_t r6 = simde_vrshr_n_s32(a, 6);
    simde_int32x2_t r13 = simde_vrshr_n_s32(a, 13);
    simde_int32x2_t r19 = simde_vrshr_n_s32(a, 19);
    simde_int32x2_t r26 = simde_vrshr_n_s32(a, 26);
    simde_int32x2_t r32 = simde_vrshr_n_s32(a, 32);

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
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();

    simde_int32x2_t r6 = simde_vrshr_n_s32(a, 6);
    simde_int32x2_t r13 = simde_vrshr_n_s32(a, 13);
    simde_int32x2_t r19 = simde_vrshr_n_s32(a, 19);
    simde_int32x2_t r26 = simde_vrshr_n_s32(a, 26);
    simde_int32x2_t r32 = simde_vrshr_n_s32(a, 32);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshr_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t r13[1];
    int64_t r26[1];
    int64_t r39[1];
    int64_t r52[1];
    int64_t r64[1];
  } test_vec[] = {
    { {  INT64_C( 5893811813544875365) },
      {  INT64_C(     719459449895615) },
      {  INT64_C(         87824639880) },
      {  INT64_C(            10720781) },
      {  INT64_C(                1309) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 5612455711902941949) },
      {  INT64_C(     685114222644402) },
      {  INT64_C(         83632107256) },
      {  INT64_C(            10208997) },
      {  INT64_C(                1246) },
      {  INT64_C(                   0) } },
    { {  INT64_C(  301388394613128552) },
      {  INT64_C(      36790575514298) },
      {  INT64_C(          4491037050) },
      {  INT64_C(              548222) },
      {  INT64_C(                  67) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 8719384580950964818) },
      {  INT64_C(    1064378000604366) },
      {  INT64_C(        129928955152) },
      {  INT64_C(            15860468) },
      {  INT64_C(                1936) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 6647140838681368655) },
      {  INT64_C(     811418559409347) },
      {  INT64_C(         99050117115) },
      {  INT64_C(            12091079) },
      {  INT64_C(                1476) },
      {  INT64_C(                   0) } },
    { { -INT64_C( 5787933355660094043) },
      { -INT64_C(     706534833454601) },
      { -INT64_C(         86246927912) },
      { -INT64_C(            10528189) },
      { -INT64_C(                1285) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 1623766213007508575) },
      {  INT64_C(     198213649048768) },
      {  INT64_C(         24196002081) },
      {  INT64_C(             2953614) },
      {  INT64_C(                 361) },
      {  INT64_C(                   0) } },
    { { -INT64_C( 1509172499385605759) },
      { -INT64_C(     184225158616407) },
      { -INT64_C(         22488422683) },
      { -INT64_C(             2745169) },
      { -INT64_C(                 335) },
      {  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);

    simde_int64x1_t r13 = simde_vrshr_n_s64(a, 13);
    simde_int64x1_t r26 = simde_vrshr_n_s64(a, 26);
    simde_int64x1_t r39 = simde_vrshr_n_s64(a, 39);
    simde_int64x1_t r52 = simde_vrshr_n_s64(a, 52);
    simde_int64x1_t r64 = simde_vrshr_n_s64(a, 64);

    simde_test_arm_neon_assert_equal_i64x1(r13, simde_vld1_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x1(r26, simde_vld1_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x1(r39, simde_vld1_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x1(r52, simde_vld1_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x1(r64, simde_vld1_s64(test_vec[i].r64));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();

    simde_int64x1_t r13 = simde_vrshr_n_s64(a, 13);
    simde_int64x1_t r26 = simde_vrshr_n_s64(a, 26);
    simde_int64x1_t r39 = simde_vrshr_n_s64(a, 39);
    simde_int64x1_t r52 = simde_vrshr_n_s64(a, 52);
    simde_int64x1_t r64 = simde_vrshr_n_s64(a, 64);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshr_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec[] = {
    { { UINT8_C(188), UINT8_C(100), UINT8_C(233), UINT8_C(106), UINT8_C( 58), UINT8_C( 89), UINT8_C(  6), UINT8_C(109) },
      { UINT8_C( 94), UINT8_C( 50), UINT8_C(117), UINT8_C( 53), UINT8_C( 29), UINT8_C( 45), UINT8_C(  3), UINT8_C( 55) },
      { UINT8_C( 24), UINT8_C( 13), UINT8_C( 29), UINT8_C( 13), UINT8_C(  7), UINT8_C( 11), UINT8_C(  1), UINT8_C( 14) },
      { UINT8_C(  6), UINT8_C(  3), UINT8_C(  7), UINT8_C(  3), UINT8_C(  2), UINT8_C(  3), UINT8_C(  0), UINT8_C(  3) },
      { UINT8_C(  3), UINT8_C(  2), UINT8_C(  4), UINT8_C(  2), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  2) },
      { UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(186), UINT8_C( 87), UINT8_C(173), UINT8_C(246), UINT8_C( 35), UINT8_C(150), UINT8_C(245), UINT8_C( 42) },
      { UINT8_C( 93), UINT8_C( 44), UINT8_C( 87), UINT8_C(123), UINT8_C( 18), UINT8_C( 75), UINT8_C(123), UINT8_C( 21) },
      { UINT8_C( 23), UINT8_C( 11), UINT8_C( 22), UINT8_C( 31), UINT8_C(  4), UINT8_C( 19), UINT8_C( 31), UINT8_C(  5) },
      { UINT8_C(  6), UINT8_C(  3), UINT8_C(  5), UINT8_C(  8), UINT8_C(  1), UINT8_C(  5), UINT8_C(  8), UINT8_C(  1) },
      { UINT8_C(  3), UINT8_C(  1), UINT8_C(  3), UINT8_C(  4), UINT8_C(  1), UINT8_C(  2), UINT8_C(  4), UINT8_C(  1) },
      { UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0) } },
    { { UINT8_C( 43), UINT8_C( 39), UINT8_C( 42), UINT8_C(113), UINT8_C( 48), UINT8_C(202), UINT8_C( 35), UINT8_C( 65) },
      { UINT8_C( 22), UINT8_C( 20), UINT8_C( 21), UINT8_C( 57), UINT8_C( 24), UINT8_C(101), UINT8_C( 18), UINT8_C( 33) },
      { UINT8_C(  5), UINT8_C(  5), UINT8_C(  5), UINT8_C( 14), UINT8_C(  6), UINT8_C( 25), UINT8_C(  4), UINT8_C(  8) },
      { UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  4), UINT8_C(  2), UINT8_C(  6), UINT8_C(  1), UINT8_C(  2) },
      { UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  2), UINT8_C(  1), UINT8_C(  3), UINT8_C(  1), UINT8_C(  1) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 67), UINT8_C(157), UINT8_C(163), UINT8_C(203), UINT8_C( 79), UINT8_C( 53), UINT8_C(214), UINT8_C( 11) },
      { UINT8_C( 34), UINT8_C( 79), UINT8_C( 82), UINT8_C(102), UINT8_C( 40), UINT8_C( 27), UINT8_C(107), UINT8_C(  6) },
      { UINT8_C(  8), UINT8_C( 20), UINT8_C( 20), UINT8_C( 25), UINT8_C( 10), UINT8_C(  7), UINT8_C( 27), UINT8_C(  1) },
      { UINT8_C(  2), UINT8_C(  5), UINT8_C(  5), UINT8_C(  6), UINT8_C(  2), UINT8_C(  2), UINT8_C(  7), UINT8_C(  0) },
      { UINT8_C(  1), UINT8_C(  2), UINT8_C(  3), UINT8_C(  3), UINT8_C(  1), UINT8_C(  1), UINT8_C(  3), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0) } },
    { { UINT8_C(153), UINT8_C(191), UINT8_C(118), UINT8_C(211), UINT8_C( 24), UINT8_C(124), UINT8_C( 64), UINT8_C(211) },
      { UINT8_C( 77), UINT8_C( 96), UINT8_C( 59), UINT8_C(106), UINT8_C( 12), UINT8_C( 62), UINT8_C( 32), UINT8_C(106) },
      { UINT8_C( 19), UINT8_C( 24), UINT8_C( 15), UINT8_C( 26), UINT8_C(  3), UINT8_C( 16), UINT8_C(  8), UINT8_C( 26) },
      { UINT8_C(  5), UINT8_C(  6), UINT8_C(  4), UINT8_C(  7), UINT8_C(  1), UINT8_C(  4), UINT8_C(  2), UINT8_C(  7) },
      { UINT8_C(  2), UINT8_C(  3), UINT8_C(  2), UINT8_C(  3), UINT8_C(  0), UINT8_C(  2), UINT8_C(  1), UINT8_C(  3) },
      { UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1) } },
    { { UINT8_C(211), UINT8_C(237), UINT8_C(201), UINT8_C(247), UINT8_C(132), UINT8_C(190), UINT8_C( 33), UINT8_C(175) },
      { UINT8_C(106), UINT8_C(119), UINT8_C(101), UINT8_C(124), UINT8_C( 66), UINT8_C( 95), UINT8_C( 17), UINT8_C( 88) },
      { UINT8_C( 26), UINT8_C( 30), UINT8_C( 25), UINT8_C( 31), UINT8_C( 17), UINT8_C( 24), UINT8_C(  4), UINT8_C( 22) },
      { UINT8_C(  7), UINT8_C(  7), UINT8_C(  6), UINT8_C(  8), UINT8_C(  4), UINT8_C(  6), UINT8_C(  1), UINT8_C(  5) },
      { UINT8_C(  3), UINT8_C(  4), UINT8_C(  3), UINT8_C(  4), UINT8_C(  2), UINT8_C(  3), UINT8_C(  1), UINT8_C(  3) },
      { UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1) } },
    { { UINT8_C(229), UINT8_C( 75), UINT8_C( 32), UINT8_C( 21), UINT8_C( 21), UINT8_C( 67), UINT8_C( 87), UINT8_C( 88) },
      { UINT8_C(115), UINT8_C( 38), UINT8_C( 16), UINT8_C( 11), UINT8_C( 11), UINT8_C( 34), UINT8_C( 44), UINT8_C( 44) },
      { UINT8_C( 29), UINT8_C(  9), UINT8_C(  4), UINT8_C(  3), UINT8_C(  3), UINT8_C(  8), UINT8_C( 11), UINT8_C( 11) },
      { UINT8_C(  7), UINT8_C(  2), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  2), UINT8_C(  3), UINT8_C(  3) },
      { UINT8_C(  4), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1) },
      { UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(224), UINT8_C(250), UINT8_C( 36), UINT8_C( 47), UINT8_C( 47), UINT8_C(250), UINT8_C( 58), UINT8_C(201) },
      { UINT8_C(112), UINT8_C(125), UINT8_C( 18), UINT8_C( 24), UINT8_C( 24), UINT8_C(125), UINT8_C( 29), UINT8_C(101) },
      { UINT8_C( 28), UINT8_C( 31), UINT8_C(  5), UINT8_C(  6), UINT8_C(  6), UINT8_C( 31), UINT8_C(  7), UINT8_C( 25) },
      { UINT8_C(  7), UINT8_C(  8), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  8), UINT8_C(  2), UINT8_C(  6) },
      { UINT8_C(  4), UINT8_C(  4), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  4), UINT8_C(  1), UINT8_C(  3) },
      { UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);

    simde_uint8x8_t r1 = simde_vrshr_n_u8(a, 1);
    simde_uint8x8_t r3 = simde_vrshr_n_u8(a, 3);
    simde_uint8x8_t r5 = simde_vrshr_n_u8(a, 5);
    simde_uint8x8_t r6 = simde_vrshr_n_u8(a, 6);
    simde_uint8x8_t r8 = simde_vrshr_n_u8(a, 8);

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
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();

    simde_uint8x8_t r1 = simde_vrshr_n_u8(a, 1);
    simde_uint8x8_t r3 = simde_vrshr_n_u8(a, 3);
    simde_uint8x8_t r5 = simde_vrshr_n_u8(a, 5);
    simde_uint8x8_t r6 = simde_vrshr_n_u8(a, 6);
    simde_uint8x8_t r8 = simde_vrshr_n_u8(a, 8);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshr_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { UINT16_C(26758), UINT16_C( 5620), UINT16_C(28305), UINT16_C( 9341) },
      { UINT16_C( 3345), UINT16_C(  703), UINT16_C( 3538), UINT16_C( 1168) },
      { UINT16_C(  418), UINT16_C(   88), UINT16_C(  442), UINT16_C(  146) },
      { UINT16_C(   26), UINT16_C(    5), UINT16_C(   28), UINT16_C(    9) },
      { UINT16_C(    3), UINT16_C(    1), UINT16_C(    3), UINT16_C(    1) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(42950), UINT16_C( 2237), UINT16_C( 9818), UINT16_C(57208) },
      { UINT16_C( 5369), UINT16_C(  280), UINT16_C( 1227), UINT16_C( 7151) },
      { UINT16_C(  671), UINT16_C(   35), UINT16_C(  153), UINT16_C(  894) },
      { UINT16_C(   42), UINT16_C(    2), UINT16_C(   10), UINT16_C(   56) },
      { UINT16_C(    5), UINT16_C(    0), UINT16_C(    1), UINT16_C(    7) },
      { UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1) } },
    { { UINT16_C(58345), UINT16_C(60578), UINT16_C(30620), UINT16_C(38728) },
      { UINT16_C( 7293), UINT16_C( 7572), UINT16_C( 3828), UINT16_C( 4841) },
      { UINT16_C(  912), UINT16_C(  947), UINT16_C(  478), UINT16_C(  605) },
      { UINT16_C(   57), UINT16_C(   59), UINT16_C(   30), UINT16_C(   38) },
      { UINT16_C(    7), UINT16_C(    7), UINT16_C(    4), UINT16_C(    5) },
      { UINT16_C(    1), UINT16_C(    1), UINT16_C(    0), UINT16_C(    1) } },
    { { UINT16_C( 7914), UINT16_C(30904), UINT16_C(54371), UINT16_C(59789) },
      { UINT16_C(  989), UINT16_C( 3863), UINT16_C( 6796), UINT16_C( 7474) },
      { UINT16_C(  124), UINT16_C(  483), UINT16_C(  850), UINT16_C(  934) },
      { UINT16_C(    8), UINT16_C(   30), UINT16_C(   53), UINT16_C(   58) },
      { UINT16_C(    1), UINT16_C(    4), UINT16_C(    7), UINT16_C(    7) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1) } },
    { { UINT16_C(33341), UINT16_C(52991), UINT16_C(31984), UINT16_C(46834) },
      { UINT16_C( 4168), UINT16_C( 6624), UINT16_C( 3998), UINT16_C( 5854) },
      { UINT16_C(  521), UINT16_C(  828), UINT16_C(  500), UINT16_C(  732) },
      { UINT16_C(   33), UINT16_C(   52), UINT16_C(   31), UINT16_C(   46) },
      { UINT16_C(    4), UINT16_C(    6), UINT16_C(    4), UINT16_C(    6) },
      { UINT16_C(    1), UINT16_C(    1), UINT16_C(    0), UINT16_C(    1) } },
    { { UINT16_C(44835), UINT16_C(32190), UINT16_C(14038), UINT16_C(48988) },
      { UINT16_C( 5604), UINT16_C( 4024), UINT16_C( 1755), UINT16_C( 6124) },
      { UINT16_C(  701), UINT16_C(  503), UINT16_C(  219), UINT16_C(  765) },
      { UINT16_C(   44), UINT16_C(   31), UINT16_C(   14), UINT16_C(   48) },
      { UINT16_C(    5), UINT16_C(    4), UINT16_C(    2), UINT16_C(    6) },
      { UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1) } },
    { { UINT16_C(65305), UINT16_C(46508), UINT16_C(62582), UINT16_C(24652) },
      { UINT16_C( 8163), UINT16_C( 5814), UINT16_C( 7823), UINT16_C( 3082) },
      { UINT16_C( 1020), UINT16_C(  727), UINT16_C(  978), UINT16_C(  385) },
      { UINT16_C(   64), UINT16_C(   45), UINT16_C(   61), UINT16_C(   24) },
      { UINT16_C(    8), UINT16_C(    6), UINT16_C(    8), UINT16_C(    3) },
      { UINT16_C(    1), UINT16_C(    1), UINT16_C(    1), UINT16_C(    0) } },
    { { UINT16_C( 1042), UINT16_C(30424), UINT16_C(26329), UINT16_C( 5727) },
      { UINT16_C(  130), UINT16_C( 3803), UINT16_C( 3291), UINT16_C(  716) },
      { UINT16_C(   16), UINT16_C(  475), UINT16_C(  411), UINT16_C(   89) },
      { UINT16_C(    1), UINT16_C(   30), UINT16_C(   26), UINT16_C(    6) },
      { UINT16_C(    0), UINT16_C(    4), UINT16_C(    3), UINT16_C(    1) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);

    simde_uint16x4_t r3 = simde_vrshr_n_u16(a, 3);
    simde_uint16x4_t r6 = simde_vrshr_n_u16(a, 6);
    simde_uint16x4_t r10 = simde_vrshr_n_u16(a, 10);
    simde_uint16x4_t r13 = simde_vrshr_n_u16(a, 13);
    simde_uint16x4_t r16 = simde_vrshr_n_u16(a, 16);

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
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();

    simde_uint16x4_t r3 = simde_vrshr_n_u16(a, 3);
    simde_uint16x4_t r6 = simde_vrshr_n_u16(a, 6);
    simde_uint16x4_t r10 = simde_vrshr_n_u16(a, 10);
    simde_uint16x4_t r13 = simde_vrshr_n_u16(a, 13);
    simde_uint16x4_t r16 = simde_vrshr_n_u16(a, 16);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshr_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { UINT32_C(1138526429), UINT32_C(1714386701) },
      { UINT32_C(  17789475), UINT32_C(  26787292) },
      { UINT32_C(    138980), UINT32_C(    209276) },
      { UINT32_C(      2172), UINT32_C(      3270) },
      { UINT32_C(        17), UINT32_C(        26) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(4121732862), UINT32_C(4029665682) },
      { UINT32_C(  64402076), UINT32_C(  62963526) },
      { UINT32_C(    503141), UINT32_C(    491903) },
      { UINT32_C(      7862), UINT32_C(      7686) },
      { UINT32_C(        61), UINT32_C(        60) },
      { UINT32_C(         1), UINT32_C(         1) } },
    { { UINT32_C(1123760803), UINT32_C(2793257249) },
      { UINT32_C(  17558763), UINT32_C(  43644645) },
      { UINT32_C(    137178), UINT32_C(    340974) },
      { UINT32_C(      2143), UINT32_C(      5328) },
      { UINT32_C(        17), UINT32_C(        42) },
      { UINT32_C(         0), UINT32_C(         1) } },
    { { UINT32_C(1068092775), UINT32_C(3130298076) },
      { UINT32_C(  16688950), UINT32_C(  48910907) },
      { UINT32_C(    130382), UINT32_C(    382116) },
      { UINT32_C(      2037), UINT32_C(      5971) },
      { UINT32_C(        16), UINT32_C(        47) },
      { UINT32_C(         0), UINT32_C(         1) } },
    { { UINT32_C( 620589078), UINT32_C(3851038183) },
      { UINT32_C(   9696704), UINT32_C(  60172472) },
      { UINT32_C(     75756), UINT32_C(    470097) },
      { UINT32_C(      1184), UINT32_C(      7345) },
      { UINT32_C(         9), UINT32_C(        57) },
      { UINT32_C(         0), UINT32_C(         1) } },
    { { UINT32_C(1708799955), UINT32_C(2874476808) },
      { UINT32_C(  26699999), UINT32_C(  44913700) },
      { UINT32_C(    208594), UINT32_C(    350888) },
      { UINT32_C(      3259), UINT32_C(      5483) },
      { UINT32_C(        25), UINT32_C(        43) },
      { UINT32_C(         0), UINT32_C(         1) } },
    { { UINT32_C(1693274179), UINT32_C(1879796489) },
      { UINT32_C(  26457409), UINT32_C(  29371820) },
      { UINT32_C(    206699), UINT32_C(    229467) },
      { UINT32_C(      3230), UINT32_C(      3585) },
      { UINT32_C(        25), UINT32_C(        28) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 363836472), UINT32_C(1489978178) },
      { UINT32_C(   5684945), UINT32_C(  23280909) },
      { UINT32_C(     44414), UINT32_C(    181882) },
      { UINT32_C(       694), UINT32_C(      2842) },
      { UINT32_C(         5), UINT32_C(        22) },
      { UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);

    simde_uint32x2_t r6 = simde_vrshr_n_u32(a, 6);
    simde_uint32x2_t r13 = simde_vrshr_n_u32(a, 13);
    simde_uint32x2_t r19 = simde_vrshr_n_u32(a, 19);
    simde_uint32x2_t r26 = simde_vrshr_n_u32(a, 26);
    simde_uint32x2_t r32 = simde_vrshr_n_u32(a, 32);

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
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();

    simde_uint32x2_t r6 = simde_vrshr_n_u32(a, 6);
    simde_uint32x2_t r13 = simde_vrshr_n_u32(a, 13);
    simde_uint32x2_t r19 = simde_vrshr_n_u32(a, 19);
    simde_uint32x2_t r26 = simde_vrshr_n_u32(a, 26);
    simde_uint32x2_t r32 = simde_vrshr_n_u32(a, 32);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshr_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t r13[1];
    uint64_t r26[1];
    uint64_t r39[1];
    uint64_t r52[1];
    uint64_t r64[1];
  } test_vec[] = {
    { { UINT64_C(16088398316289318313) },
      { UINT64_C(    1963915810093911) },
      { UINT64_C(        239735816662) },
      { UINT64_C(            29264626) },
      { UINT64_C(                3572) },
      { UINT64_C(                   1) } },
    { { UINT64_C(15970363434992149467) },
      { UINT64_C(    1949507255248065) },
      { UINT64_C(        237976959869) },
      { UINT64_C(            29049922) },
      { UINT64_C(                3546) },
      { UINT64_C(                   1) } },
    { { UINT64_C(17355878290108775677) },
      { UINT64_C(    2118637486585544) },
      { UINT64_C(        258622740062) },
      { UINT64_C(            31570159) },
      { UINT64_C(                3854) },
      { UINT64_C(                   1) } },
    { { UINT64_C( 5593719929260279867) },
      { UINT64_C(     682827139802280) },
      { UINT64_C(         83352922339) },
      { UINT64_C(            10174917) },
      { UINT64_C(                1242) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 6892171561238006463) },
      { UINT64_C(     841329536283936) },
      { UINT64_C(        102701359410) },
      { UINT64_C(            12536787) },
      { UINT64_C(                1530) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 6618027965719723532) },
      { UINT64_C(     807864741909146) },
      { UINT64_C(         98616301503) },
      { UINT64_C(            12038123) },
      { UINT64_C(                1469) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 7006102550303846385) },
      { UINT64_C(     855237127722637) },
      { UINT64_C(        104399063443) },
      { UINT64_C(            12744026) },
      { UINT64_C(                1556) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 8117332270751076278) },
      { UINT64_C(     990885286956918) },
      { UINT64_C(        120957676630) },
      { UINT64_C(            14765341) },
      { UINT64_C(                1802) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);

    simde_uint64x1_t r13 = simde_vrshr_n_u64(a, 13);
    simde_uint64x1_t r26 = simde_vrshr_n_u64(a, 26);
    simde_uint64x1_t r39 = simde_vrshr_n_u64(a, 39);
    simde_uint64x1_t r52 = simde_vrshr_n_u64(a, 52);
    simde_uint64x1_t r64 = simde_vrshr_n_u64(a, 64);

    simde_test_arm_neon_assert_equal_u64x1(r13, simde_vld1_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x1(r26, simde_vld1_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x1(r39, simde_vld1_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x1(r52, simde_vld1_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x1(r64, simde_vld1_u64(test_vec[i].r64));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();

    simde_uint64x1_t r13 = simde_vrshr_n_u64(a, 13);
    simde_uint64x1_t r26 = simde_vrshr_n_u64(a, 26);
    simde_uint64x1_t r39 = simde_vrshr_n_u64(a, 39);
    simde_uint64x1_t r52 = simde_vrshr_n_u64(a, 52);
    simde_uint64x1_t r64 = simde_vrshr_n_u64(a, 64);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshrq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r8[16];
  } test_vec[] = {
    { {  INT8_C(  53),  INT8_C(  82),  INT8_C(  70), -INT8_C(  76),  INT8_C(  93), -INT8_C(  85), -INT8_C( 127), -INT8_C( 105),
        -INT8_C( 120),  INT8_C( 101), -INT8_C(  41), -INT8_C(  69), -INT8_C(   1), -INT8_C( 123),  INT8_C(  97), -INT8_C(  90) },
      {  INT8_C(  27),  INT8_C(  41),  INT8_C(  35), -INT8_C(  38),  INT8_C(  47), -INT8_C(  42), -INT8_C(  63), -INT8_C(  52),
        -INT8_C(  60),  INT8_C(  51), -INT8_C(  20), -INT8_C(  34),  INT8_C(   0), -INT8_C(  61),  INT8_C(  49), -INT8_C(  45) },
      {  INT8_C(   7),  INT8_C(  10),  INT8_C(   9), -INT8_C(   9),  INT8_C(  12), -INT8_C(  11), -INT8_C(  16), -INT8_C(  13),
        -INT8_C(  15),  INT8_C(  13), -INT8_C(   5), -INT8_C(   9),  INT8_C(   0), -INT8_C(  15),  INT8_C(  12), -INT8_C(  11) },
      {  INT8_C(   2),  INT8_C(   3),  INT8_C(   2), -INT8_C(   2),  INT8_C(   3), -INT8_C(   3), -INT8_C(   4), -INT8_C(   3),
        -INT8_C(   4),  INT8_C(   3), -INT8_C(   1), -INT8_C(   2),  INT8_C(   0), -INT8_C(   4),  INT8_C(   3), -INT8_C(   3) },
      {  INT8_C(   1),  INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1), -INT8_C(   1), -INT8_C(   2), -INT8_C(   2),
        -INT8_C(   2),  INT8_C(   2), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   2),  INT8_C(   2), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  78),  INT8_C(  69), -INT8_C(  68),  INT8_C(  16),  INT8_C(  85),  INT8_C( 100), -INT8_C(  51),  INT8_C(  44),
        -INT8_C( 127),  INT8_C( 104),  INT8_C(  35),  INT8_C( 126),  INT8_C(  62), -INT8_C( 114), -INT8_C(  74),  INT8_C( 116) },
      {  INT8_C(  39),  INT8_C(  35), -INT8_C(  34),  INT8_C(   8),  INT8_C(  43),  INT8_C(  50), -INT8_C(  25),  INT8_C(  22),
        -INT8_C(  63),  INT8_C(  52),  INT8_C(  18),  INT8_C(  63),  INT8_C(  31), -INT8_C(  57), -INT8_C(  37),  INT8_C(  58) },
      {  INT8_C(  10),  INT8_C(   9), -INT8_C(   8),  INT8_C(   2),  INT8_C(  11),  INT8_C(  13), -INT8_C(   6),  INT8_C(   6),
        -INT8_C(  16),  INT8_C(  13),  INT8_C(   4),  INT8_C(  16),  INT8_C(   8), -INT8_C(  14), -INT8_C(   9),  INT8_C(  15) },
      {  INT8_C(   2),  INT8_C(   2), -INT8_C(   2),  INT8_C(   1),  INT8_C(   3),  INT8_C(   3), -INT8_C(   2),  INT8_C(   1),
        -INT8_C(   4),  INT8_C(   3),  INT8_C(   1),  INT8_C(   4),  INT8_C(   2), -INT8_C(   4), -INT8_C(   2),  INT8_C(   4) },
      {  INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   1),  INT8_C(   2), -INT8_C(   1),  INT8_C(   1),
        -INT8_C(   2),  INT8_C(   2),  INT8_C(   1),  INT8_C(   2),  INT8_C(   1), -INT8_C(   2), -INT8_C(   1),  INT8_C(   2) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  32), -INT8_C(   4),  INT8_C(  40),  INT8_C(  62), -INT8_C(  89), -INT8_C(  87), -INT8_C(  43),  INT8_C(  48),
         INT8_C(  14), -INT8_C(  84), -INT8_C(  21),  INT8_C(  13),  INT8_C(  49),  INT8_C(  76), -INT8_C(  77),      INT8_MAX },
      { -INT8_C(  16), -INT8_C(   2),  INT8_C(  20),  INT8_C(  31), -INT8_C(  44), -INT8_C(  43), -INT8_C(  21),  INT8_C(  24),
         INT8_C(   7), -INT8_C(  42), -INT8_C(  10),  INT8_C(   7),  INT8_C(  25),  INT8_C(  38), -INT8_C(  38),  INT8_C(  64) },
      { -INT8_C(   4),  INT8_C(   0),  INT8_C(   5),  INT8_C(   8), -INT8_C(  11), -INT8_C(  11), -INT8_C(   5),  INT8_C(   6),
         INT8_C(   2), -INT8_C(  10), -INT8_C(   3),  INT8_C(   2),  INT8_C(   6),  INT8_C(  10), -INT8_C(  10),  INT8_C(  16) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   1),  INT8_C(   2), -INT8_C(   3), -INT8_C(   3), -INT8_C(   1),  INT8_C(   2),
         INT8_C(   0), -INT8_C(   3), -INT8_C(   1),  INT8_C(   0),  INT8_C(   2),  INT8_C(   2), -INT8_C(   2),  INT8_C(   4) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   2) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C( 111),  INT8_C( 112), -INT8_C( 112), -INT8_C(  26), -INT8_C(  44),  INT8_C(  93),  INT8_C(  18),  INT8_C(  85),
        -INT8_C(  59),  INT8_C(  53), -INT8_C(  44),  INT8_C(   4), -INT8_C(  61), -INT8_C( 118),  INT8_C( 120), -INT8_C(  93) },
      { -INT8_C(  55),  INT8_C(  56), -INT8_C(  56), -INT8_C(  13), -INT8_C(  22),  INT8_C(  47),  INT8_C(   9),  INT8_C(  43),
        -INT8_C(  29),  INT8_C(  27), -INT8_C(  22),  INT8_C(   2), -INT8_C(  30), -INT8_C(  59),  INT8_C(  60), -INT8_C(  46) },
      { -INT8_C(  14),  INT8_C(  14), -INT8_C(  14), -INT8_C(   3), -INT8_C(   5),  INT8_C(  12),  INT8_C(   2),  INT8_C(  11),
        -INT8_C(   7),  INT8_C(   7), -INT8_C(   5),  INT8_C(   1), -INT8_C(   8), -INT8_C(  15),  INT8_C(  15), -INT8_C(  12) },
      { -INT8_C(   3),  INT8_C(   4), -INT8_C(   3), -INT8_C(   1), -INT8_C(   1),  INT8_C(   3),  INT8_C(   1),  INT8_C(   3),
        -INT8_C(   2),  INT8_C(   2), -INT8_C(   1),  INT8_C(   0), -INT8_C(   2), -INT8_C(   4),  INT8_C(   4), -INT8_C(   3) },
      { -INT8_C(   2),  INT8_C(   2), -INT8_C(   2),  INT8_C(   0), -INT8_C(   1),  INT8_C(   1),  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   2),  INT8_C(   2), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C( 121), -INT8_C(  96), -INT8_C(  31),  INT8_C(  46),  INT8_C(  74), -INT8_C(  74),  INT8_C(  94),  INT8_C(  88),
         INT8_C(  98),  INT8_C(  73),  INT8_C( 102), -INT8_C( 109), -INT8_C( 107),  INT8_C(  25),  INT8_C(  19),  INT8_C(  38) },
      { -INT8_C(  60), -INT8_C(  48), -INT8_C(  15),  INT8_C(  23),  INT8_C(  37), -INT8_C(  37),  INT8_C(  47),  INT8_C(  44),
         INT8_C(  49),  INT8_C(  37),  INT8_C(  51), -INT8_C(  54), -INT8_C(  53),  INT8_C(  13),  INT8_C(  10),  INT8_C(  19) },
      { -INT8_C(  15), -INT8_C(  12), -INT8_C(   4),  INT8_C(   6),  INT8_C(   9), -INT8_C(   9),  INT8_C(  12),  INT8_C(  11),
         INT8_C(  12),  INT8_C(   9),  INT8_C(  13), -INT8_C(  14), -INT8_C(  13),  INT8_C(   3),  INT8_C(   2),  INT8_C(   5) },
      { -INT8_C(   4), -INT8_C(   3), -INT8_C(   1),  INT8_C(   1),  INT8_C(   2), -INT8_C(   2),  INT8_C(   3),  INT8_C(   3),
         INT8_C(   3),  INT8_C(   2),  INT8_C(   3), -INT8_C(   3), -INT8_C(   3),  INT8_C(   1),  INT8_C(   1),  INT8_C(   1) },
      { -INT8_C(   2), -INT8_C(   1),  INT8_C(   0),  INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),  INT8_C(   1),
         INT8_C(   2),  INT8_C(   1),  INT8_C(   2), -INT8_C(   2), -INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C( 119), -INT8_C(  93),  INT8_C(  12),  INT8_C(  93),  INT8_C(   0),  INT8_C(  30), -INT8_C(  77), -INT8_C(  59),
         INT8_C(  83), -INT8_C( 121), -INT8_C(  55),  INT8_C(  22),  INT8_C(  17),  INT8_C(  65), -INT8_C(  70), -INT8_C( 104) },
      { -INT8_C(  59), -INT8_C(  46),  INT8_C(   6),  INT8_C(  47),  INT8_C(   0),  INT8_C(  15), -INT8_C(  38), -INT8_C(  29),
         INT8_C(  42), -INT8_C(  60), -INT8_C(  27),  INT8_C(  11),  INT8_C(   9),  INT8_C(  33), -INT8_C(  35), -INT8_C(  52) },
      { -INT8_C(  15), -INT8_C(  12),  INT8_C(   2),  INT8_C(  12),  INT8_C(   0),  INT8_C(   4), -INT8_C(  10), -INT8_C(   7),
         INT8_C(  10), -INT8_C(  15), -INT8_C(   7),  INT8_C(   3),  INT8_C(   2),  INT8_C(   8), -INT8_C(   9), -INT8_C(  13) },
      { -INT8_C(   4), -INT8_C(   3),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   1), -INT8_C(   2), -INT8_C(   2),
         INT8_C(   3), -INT8_C(   4), -INT8_C(   2),  INT8_C(   1),  INT8_C(   1),  INT8_C(   2), -INT8_C(   2), -INT8_C(   3) },
      { -INT8_C(   2), -INT8_C(   1),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   1), -INT8_C(   2), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1), -INT8_C(   1), -INT8_C(   2) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  30), -INT8_C( 101), -INT8_C(  57),  INT8_C(  44),  INT8_C(  82),  INT8_C(  37), -INT8_C( 124), -INT8_C(  76),
         INT8_C( 111), -INT8_C(  22),  INT8_C(  72),  INT8_C(   4),  INT8_C(   4),  INT8_C(  91),  INT8_C(  43), -INT8_C( 115) },
      { -INT8_C(  15), -INT8_C(  50), -INT8_C(  28),  INT8_C(  22),  INT8_C(  41),  INT8_C(  19), -INT8_C(  62), -INT8_C(  38),
         INT8_C(  56), -INT8_C(  11),  INT8_C(  36),  INT8_C(   2),  INT8_C(   2),  INT8_C(  46),  INT8_C(  22), -INT8_C(  57) },
      { -INT8_C(   4), -INT8_C(  13), -INT8_C(   7),  INT8_C(   6),  INT8_C(  10),  INT8_C(   5), -INT8_C(  15), -INT8_C(   9),
         INT8_C(  14), -INT8_C(   3),  INT8_C(   9),  INT8_C(   1),  INT8_C(   1),  INT8_C(  11),  INT8_C(   5), -INT8_C(  14) },
      { -INT8_C(   1), -INT8_C(   3), -INT8_C(   2),  INT8_C(   1),  INT8_C(   3),  INT8_C(   1), -INT8_C(   4), -INT8_C(   2),
         INT8_C(   3), -INT8_C(   1),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   1), -INT8_C(   4) },
      {  INT8_C(   0), -INT8_C(   2), -INT8_C(   1),  INT8_C(   1),  INT8_C(   1),  INT8_C(   1), -INT8_C(   2), -INT8_C(   1),
         INT8_C(   2),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   1), -INT8_C(   2) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(   2),  INT8_C(  55), -INT8_C(  21), -INT8_C(   2),  INT8_C(  86), -INT8_C(  98), -INT8_C(  61), -INT8_C(  87),
         INT8_C(  37), -INT8_C( 115), -INT8_C(  64),  INT8_C(  54), -INT8_C(  50),  INT8_C( 122), -INT8_C(  49), -INT8_C(  80) },
      { -INT8_C(   1),  INT8_C(  28), -INT8_C(  10), -INT8_C(   1),  INT8_C(  43), -INT8_C(  49), -INT8_C(  30), -INT8_C(  43),
         INT8_C(  19), -INT8_C(  57), -INT8_C(  32),  INT8_C(  27), -INT8_C(  25),  INT8_C(  61), -INT8_C(  24), -INT8_C(  40) },
      {  INT8_C(   0),  INT8_C(   7), -INT8_C(   3),  INT8_C(   0),  INT8_C(  11), -INT8_C(  12), -INT8_C(   8), -INT8_C(  11),
         INT8_C(   5), -INT8_C(  14), -INT8_C(   8),  INT8_C(   7), -INT8_C(   6),  INT8_C(  15), -INT8_C(   6), -INT8_C(  10) },
      {  INT8_C(   0),  INT8_C(   2), -INT8_C(   1),  INT8_C(   0),  INT8_C(   3), -INT8_C(   3), -INT8_C(   2), -INT8_C(   3),
         INT8_C(   1), -INT8_C(   4), -INT8_C(   2),  INT8_C(   2), -INT8_C(   2),  INT8_C(   4), -INT8_C(   2), -INT8_C(   2) },
      {  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1), -INT8_C(   2), -INT8_C(   1), -INT8_C(   1),
         INT8_C(   1), -INT8_C(   2), -INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   2), -INT8_C(   1), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);

    simde_int8x16_t r1 = simde_vrshrq_n_s8(a, 1);
    simde_int8x16_t r3 = simde_vrshrq_n_s8(a, 3);
    simde_int8x16_t r5 = simde_vrshrq_n_s8(a, 5);
    simde_int8x16_t r6 = simde_vrshrq_n_s8(a, 6);
    simde_int8x16_t r8 = simde_vrshrq_n_s8(a, 8);

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
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();

    simde_int8x16_t r1 = simde_vrshrq_n_s8(a, 1);
    simde_int8x16_t r3 = simde_vrshrq_n_s8(a, 3);
    simde_int8x16_t r5 = simde_vrshrq_n_s8(a, 5);
    simde_int8x16_t r6 = simde_vrshrq_n_s8(a, 6);
    simde_int8x16_t r8 = simde_vrshrq_n_s8(a, 8);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshrq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { { -INT16_C( 16620),  INT16_C(  3863), -INT16_C( 26718),  INT16_C(   477),  INT16_C( 12323), -INT16_C( 31606), -INT16_C( 22951), -INT16_C( 13711) },
      { -INT16_C(  2077),  INT16_C(   483), -INT16_C(  3340),  INT16_C(    60),  INT16_C(  1540), -INT16_C(  3951), -INT16_C(  2869), -INT16_C(  1714) },
      { -INT16_C(   260),  INT16_C(    60), -INT16_C(   417),  INT16_C(     7),  INT16_C(   193), -INT16_C(   494), -INT16_C(   359), -INT16_C(   214) },
      { -INT16_C(    16),  INT16_C(     4), -INT16_C(    26),  INT16_C(     0),  INT16_C(    12), -INT16_C(    31), -INT16_C(    22), -INT16_C(    13) },
      { -INT16_C(     2),  INT16_C(     0), -INT16_C(     3),  INT16_C(     0),  INT16_C(     2), -INT16_C(     4), -INT16_C(     3), -INT16_C(     2) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 31302),  INT16_C(  5069),  INT16_C( 28315), -INT16_C(  5931), -INT16_C( 30492),  INT16_C( 21319), -INT16_C( 13235),  INT16_C( 25012) },
      { -INT16_C(  3913),  INT16_C(   634),  INT16_C(  3539), -INT16_C(   741), -INT16_C(  3811),  INT16_C(  2665), -INT16_C(  1654),  INT16_C(  3127) },
      { -INT16_C(   489),  INT16_C(    79),  INT16_C(   442), -INT16_C(    93), -INT16_C(   476),  INT16_C(   333), -INT16_C(   207),  INT16_C(   391) },
      { -INT16_C(    31),  INT16_C(     5),  INT16_C(    28), -INT16_C(     6), -INT16_C(    30),  INT16_C(    21), -INT16_C(    13),  INT16_C(    24) },
      { -INT16_C(     4),  INT16_C(     1),  INT16_C(     3), -INT16_C(     1), -INT16_C(     4),  INT16_C(     3), -INT16_C(     2),  INT16_C(     3) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 13428),  INT16_C( 11888),  INT16_C( 20066), -INT16_C( 31441), -INT16_C( 17794), -INT16_C( 10487),  INT16_C( 31328),  INT16_C(  6817) },
      { -INT16_C(  1678),  INT16_C(  1486),  INT16_C(  2508), -INT16_C(  3930), -INT16_C(  2224), -INT16_C(  1311),  INT16_C(  3916),  INT16_C(   852) },
      { -INT16_C(   210),  INT16_C(   186),  INT16_C(   314), -INT16_C(   491), -INT16_C(   278), -INT16_C(   164),  INT16_C(   490),  INT16_C(   107) },
      { -INT16_C(    13),  INT16_C(    12),  INT16_C(    20), -INT16_C(    31), -INT16_C(    17), -INT16_C(    10),  INT16_C(    31),  INT16_C(     7) },
      { -INT16_C(     2),  INT16_C(     1),  INT16_C(     2), -INT16_C(     4), -INT16_C(     2), -INT16_C(     1),  INT16_C(     4),  INT16_C(     1) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 28160), -INT16_C( 25811),  INT16_C(   732), -INT16_C( 15997), -INT16_C( 13430), -INT16_C( 10220), -INT16_C( 14185),  INT16_C(  9017) },
      {  INT16_C(  3520), -INT16_C(  3226),  INT16_C(    92), -INT16_C(  2000), -INT16_C(  1679), -INT16_C(  1277), -INT16_C(  1773),  INT16_C(  1127) },
      {  INT16_C(   440), -INT16_C(   403),  INT16_C(    11), -INT16_C(   250), -INT16_C(   210), -INT16_C(   160), -INT16_C(   222),  INT16_C(   141) },
      {  INT16_C(    28), -INT16_C(    25),  INT16_C(     1), -INT16_C(    16), -INT16_C(    13), -INT16_C(    10), -INT16_C(    14),  INT16_C(     9) },
      {  INT16_C(     3), -INT16_C(     3),  INT16_C(     0), -INT16_C(     2), -INT16_C(     2), -INT16_C(     1), -INT16_C(     2),  INT16_C(     1) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 21869), -INT16_C(  2734), -INT16_C( 32264),  INT16_C( 30330), -INT16_C( 31941), -INT16_C( 25523), -INT16_C(  4354), -INT16_C(   330) },
      { -INT16_C(  2734), -INT16_C(   342), -INT16_C(  4033),  INT16_C(  3791), -INT16_C(  3993), -INT16_C(  3190), -INT16_C(   544), -INT16_C(    41) },
      { -INT16_C(   342), -INT16_C(    43), -INT16_C(   504),  INT16_C(   474), -INT16_C(   499), -INT16_C(   399), -INT16_C(    68), -INT16_C(     5) },
      { -INT16_C(    21), -INT16_C(     3), -INT16_C(    32),  INT16_C(    30), -INT16_C(    31), -INT16_C(    25), -INT16_C(     4),  INT16_C(     0) },
      { -INT16_C(     3),  INT16_C(     0), -INT16_C(     4),  INT16_C(     4), -INT16_C(     4), -INT16_C(     3), -INT16_C(     1),  INT16_C(     0) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  7076),  INT16_C( 14745),  INT16_C(  7398),  INT16_C( 29178),  INT16_C(  3815),  INT16_C( 32585), -INT16_C( 32042),  INT16_C( 27042) },
      { -INT16_C(   884),  INT16_C(  1843),  INT16_C(   925),  INT16_C(  3647),  INT16_C(   477),  INT16_C(  4073), -INT16_C(  4005),  INT16_C(  3380) },
      { -INT16_C(   111),  INT16_C(   230),  INT16_C(   116),  INT16_C(   456),  INT16_C(    60),  INT16_C(   509), -INT16_C(   501),  INT16_C(   423) },
      { -INT16_C(     7),  INT16_C(    14),  INT16_C(     7),  INT16_C(    28),  INT16_C(     4),  INT16_C(    32), -INT16_C(    31),  INT16_C(    26) },
      { -INT16_C(     1),  INT16_C(     2),  INT16_C(     1),  INT16_C(     4),  INT16_C(     0),  INT16_C(     4), -INT16_C(     4),  INT16_C(     3) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  3028),  INT16_C(  9310), -INT16_C( 10122), -INT16_C( 20070), -INT16_C(  6309),  INT16_C( 22861),  INT16_C(  1237),  INT16_C( 12887) },
      { -INT16_C(   378),  INT16_C(  1164), -INT16_C(  1265), -INT16_C(  2509), -INT16_C(   789),  INT16_C(  2858),  INT16_C(   155),  INT16_C(  1611) },
      { -INT16_C(    47),  INT16_C(   145), -INT16_C(   158), -INT16_C(   314), -INT16_C(    99),  INT16_C(   357),  INT16_C(    19),  INT16_C(   201) },
      { -INT16_C(     3),  INT16_C(     9), -INT16_C(    10), -INT16_C(    20), -INT16_C(     6),  INT16_C(    22),  INT16_C(     1),  INT16_C(    13) },
      {  INT16_C(     0),  INT16_C(     1), -INT16_C(     1), -INT16_C(     2), -INT16_C(     1),  INT16_C(     3),  INT16_C(     0),  INT16_C(     2) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  3864), -INT16_C( 12693),  INT16_C( 25869), -INT16_C(  3009), -INT16_C( 30605),  INT16_C( 18803),  INT16_C(  5643),  INT16_C( 14258) },
      { -INT16_C(   483), -INT16_C(  1587),  INT16_C(  3234), -INT16_C(   376), -INT16_C(  3826),  INT16_C(  2350),  INT16_C(   705),  INT16_C(  1782) },
      { -INT16_C(    60), -INT16_C(   198),  INT16_C(   404), -INT16_C(    47), -INT16_C(   478),  INT16_C(   294),  INT16_C(    88),  INT16_C(   223) },
      { -INT16_C(     4), -INT16_C(    12),  INT16_C(    25), -INT16_C(     3), -INT16_C(    30),  INT16_C(    18),  INT16_C(     6),  INT16_C(    14) },
      {  INT16_C(     0), -INT16_C(     2),  INT16_C(     3),  INT16_C(     0), -INT16_C(     4),  INT16_C(     2),  INT16_C(     1),  INT16_C(     2) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_int16x8_t r3 = simde_vrshrq_n_s16(a, 3);
    simde_int16x8_t r6 = simde_vrshrq_n_s16(a, 6);
    simde_int16x8_t r10 = simde_vrshrq_n_s16(a, 10);
    simde_int16x8_t r13 = simde_vrshrq_n_s16(a, 13);
    simde_int16x8_t r16 = simde_vrshrq_n_s16(a, 16);

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
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();

    simde_int16x8_t r3 = simde_vrshrq_n_s16(a, 3);
    simde_int16x8_t r6 = simde_vrshrq_n_s16(a, 6);
    simde_int16x8_t r10 = simde_vrshrq_n_s16(a, 10);
    simde_int16x8_t r13 = simde_vrshrq_n_s16(a, 13);
    simde_int16x8_t r16 = simde_vrshrq_n_s16(a, 16);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshrq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r32[4];
  } test_vec[] = {
    { {  INT32_C(  1489106393),  INT32_C(  1731098689),  INT32_C(   131701187),  INT32_C(   116014444) },
      {  INT32_C(    23267287),  INT32_C(    27048417),  INT32_C(     2057831),  INT32_C(     1812726) },
      {  INT32_C(      181776),  INT32_C(      211316),  INT32_C(       16077),  INT32_C(       14162) },
      {  INT32_C(        2840),  INT32_C(        3302),  INT32_C(         251),  INT32_C(         221) },
      {  INT32_C(          22),  INT32_C(          26),  INT32_C(           2),  INT32_C(           2) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1295077241), -INT32_C(  2045704932), -INT32_C(  1346710917), -INT32_C(  1766006852) },
      {  INT32_C(    20235582), -INT32_C(    31964140), -INT32_C(    21042358), -INT32_C(    27593857) },
      {  INT32_C(      158090), -INT32_C(      249720), -INT32_C(      164393), -INT32_C(      215577) },
      {  INT32_C(        2470), -INT32_C(        3902), -INT32_C(        2569), -INT32_C(        3368) },
      {  INT32_C(          19), -INT32_C(          30), -INT32_C(          20), -INT32_C(          26) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   384728788), -INT32_C(  1182982922),  INT32_C(   566318773),  INT32_C(   203926419) },
      {  INT32_C(     6011387), -INT32_C(    18484108),  INT32_C(     8848731),  INT32_C(     3186350) },
      {  INT32_C(       46964), -INT32_C(      144407),  INT32_C(       69131),  INT32_C(       24893) },
      {  INT32_C(         734), -INT32_C(        2256),  INT32_C(        1080),  INT32_C(         389) },
      {  INT32_C(           6), -INT32_C(          18),  INT32_C(           8),  INT32_C(           3) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   375019770), -INT32_C(   660772003), -INT32_C(    91728067),  INT32_C(   194004023) },
      {  INT32_C(     5859684), -INT32_C(    10324563), -INT32_C(     1433251),  INT32_C(     3031313) },
      {  INT32_C(       45779), -INT32_C(       80661), -INT32_C(       11197),  INT32_C(       23682) },
      {  INT32_C(         715), -INT32_C(        1260), -INT32_C(         175),  INT32_C(         370) },
      {  INT32_C(           6), -INT32_C(          10), -INT32_C(           1),  INT32_C(           3) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1188987198),  INT32_C(  1332911770), -INT32_C(  2005912587), -INT32_C(   661284898) },
      { -INT32_C(    18577925),  INT32_C(    20826746), -INT32_C(    31342384), -INT32_C(    10332577) },
      { -INT32_C(      145140),  INT32_C(      162709), -INT32_C(      244862), -INT32_C(       80723) },
      { -INT32_C(        2268),  INT32_C(        2542), -INT32_C(        3826), -INT32_C(        1261) },
      { -INT32_C(          18),  INT32_C(          20), -INT32_C(          30), -INT32_C(          10) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1290792943), -INT32_C(  1759146918),  INT32_C(   445754851), -INT32_C(  1272569359) },
      {  INT32_C(    20168640), -INT32_C(    27486671),  INT32_C(     6964920), -INT32_C(    19883896) },
      {  INT32_C(      157567), -INT32_C(      214740),  INT32_C(       54413), -INT32_C(      155343) },
      {  INT32_C(        2462), -INT32_C(        3355),  INT32_C(         850), -INT32_C(        2427) },
      {  INT32_C(          19), -INT32_C(          26),  INT32_C(           7), -INT32_C(          19) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   963463071), -INT32_C(   611786778), -INT32_C(   245106669),  INT32_C(  2127231119) },
      {  INT32_C(    15054110), -INT32_C(     9559168), -INT32_C(     3829792),  INT32_C(    33237986) },
      {  INT32_C(      117610), -INT32_C(       74681), -INT32_C(       29920),  INT32_C(      259672) },
      {  INT32_C(        1838), -INT32_C(        1167), -INT32_C(         468),  INT32_C(        4057) },
      {  INT32_C(          14), -INT32_C(           9), -INT32_C(           4),  INT32_C(          32) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1103870439),  INT32_C(   685371461), -INT32_C(  1908184419),  INT32_C(   725772684) },
      {  INT32_C(    17247976),  INT32_C(    10708929), -INT32_C(    29815382),  INT32_C(    11340198) },
      {  INT32_C(      134750),  INT32_C(       83664), -INT32_C(      232933),  INT32_C(       88595) },
      {  INT32_C(        2105),  INT32_C(        1307), -INT32_C(        3640),  INT32_C(        1384) },
      {  INT32_C(          16),  INT32_C(          10), -INT32_C(          28),  INT32_C(          11) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_int32x4_t r6 = simde_vrshrq_n_s32(a, 6);
    simde_int32x4_t r13 = simde_vrshrq_n_s32(a, 13);
    simde_int32x4_t r19 = simde_vrshrq_n_s32(a, 19);
    simde_int32x4_t r26 = simde_vrshrq_n_s32(a, 26);
    simde_int32x4_t r32 = simde_vrshrq_n_s32(a, 32);

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
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();

    simde_int32x4_t r6 = simde_vrshrq_n_s32(a, 6);
    simde_int32x4_t r13 = simde_vrshrq_n_s32(a, 13);
    simde_int32x4_t r19 = simde_vrshrq_n_s32(a, 19);
    simde_int32x4_t r26 = simde_vrshrq_n_s32(a, 26);
    simde_int32x4_t r32 = simde_vrshrq_n_s32(a, 32);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshrq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t r13[2];
    int64_t r26[2];
    int64_t r39[2];
    int64_t r52[2];
    int64_t r64[2];
  } test_vec[] = {
    { { -INT64_C(  155505297264585433),  INT64_C( 1918057023215863005) },
      { -INT64_C(      18982580232493),  INT64_C(     234137820216780) },
      { -INT64_C(          2317209501),  INT64_C(         28581276882) },
      { -INT64_C(              282862),  INT64_C(             3488925) },
      { -INT64_C(                  35),  INT64_C(                 426) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C(  137607243321795074),  INT64_C( 8939380644695547651) },
      {  INT64_C(      16797759194555),  INT64_C(    1091232988854437) },
      {  INT64_C(          2050507714),  INT64_C(        133207151960) },
      {  INT64_C(              250306),  INT64_C(            16260639) },
      {  INT64_C(                  31),  INT64_C(                1985) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 5774704828559649380),  INT64_C( 3256442460466306147) },
      {  INT64_C(     704920023017535),  INT64_C(     397514948787391) },
      {  INT64_C(         86049807497),  INT64_C(         48524774022) },
      {  INT64_C(            10504127),  INT64_C(             5923434) },
      {  INT64_C(                1282),  INT64_C(                 723) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 3699674341953902441),  INT64_C( 3498799708177743292) },
      { -INT64_C(     451620403070545),  INT64_C(     427099573752166) },
      { -INT64_C(         55129443734),  INT64_C(         52136178437) },
      { -INT64_C(             6729668),  INT64_C(             6364280) },
      { -INT64_C(                 821),  INT64_C(                 777) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 2816868020946299355),  INT64_C( 5524826802489360213) },
      { -INT64_C(     343855959588171),  INT64_C(     674417334288252) },
      { -INT64_C(         41974604442),  INT64_C(         82326334752) },
      { -INT64_C(             5123853),  INT64_C(            10049601) },
      { -INT64_C(                 625),  INT64_C(                1227) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 4927329423533547256),  INT64_C( 3122501998596704856) },
      { -INT64_C(     601480642521185),  INT64_C(     381164794750574) },
      { -INT64_C(         73422929995),  INT64_C(         46528905609) },
      { -INT64_C(             8962760),  INT64_C(             5679798) },
      { -INT64_C(                1094),  INT64_C(                 693) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 8736889974953323505),  INT64_C( 6281295867776871978) },
      {  INT64_C(    1066514889520669),  INT64_C(     766759749484481) },
      {  INT64_C(        130189805850),  INT64_C(         93598602232) },
      {  INT64_C(            15892310),  INT64_C(            11425611) },
      {  INT64_C(                1940),  INT64_C(                1395) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 1315271790320754310),  INT64_C( 6540505840195341714) },
      {  INT64_C(     160555638466889),  INT64_C(     798401591820720) },
      {  INT64_C(         19599076961),  INT64_C(         97461131814) },
      {  INT64_C(             2392465),  INT64_C(            11897111) },
      {  INT64_C(                 292),  INT64_C(                1452) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_int64x2_t r13 = simde_vrshrq_n_s64(a, 13);
    simde_int64x2_t r26 = simde_vrshrq_n_s64(a, 26);
    simde_int64x2_t r39 = simde_vrshrq_n_s64(a, 39);
    simde_int64x2_t r52 = simde_vrshrq_n_s64(a, 52);
    simde_int64x2_t r64 = simde_vrshrq_n_s64(a, 64);

    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r39, simde_vld1q_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x2(r52, simde_vld1q_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x2(r64, simde_vld1q_s64(test_vec[i].r64));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();

    simde_int64x2_t r13 = simde_vrshrq_n_s64(a, 13);
    simde_int64x2_t r26 = simde_vrshrq_n_s64(a, 26);
    simde_int64x2_t r39 = simde_vrshrq_n_s64(a, 39);
    simde_int64x2_t r52 = simde_vrshrq_n_s64(a, 52);
    simde_int64x2_t r64 = simde_vrshrq_n_s64(a, 64);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshrq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { { UINT8_C(165), UINT8_C(115), UINT8_C(214), UINT8_C(181), UINT8_C( 93), UINT8_C(223), UINT8_C(180), UINT8_C(227),
        UINT8_C( 52), UINT8_C( 30), UINT8_C( 57), UINT8_C(152), UINT8_C(142), UINT8_C(132), UINT8_C(131), UINT8_C( 10) },
      { UINT8_C( 83), UINT8_C( 58), UINT8_C(107), UINT8_C( 91), UINT8_C( 47), UINT8_C(112), UINT8_C( 90), UINT8_C(114),
        UINT8_C( 26), UINT8_C( 15), UINT8_C( 29), UINT8_C( 76), UINT8_C( 71), UINT8_C( 66), UINT8_C( 66), UINT8_C(  5) },
      { UINT8_C( 21), UINT8_C( 14), UINT8_C( 27), UINT8_C( 23), UINT8_C( 12), UINT8_C( 28), UINT8_C( 23), UINT8_C( 28),
        UINT8_C(  7), UINT8_C(  4), UINT8_C(  7), UINT8_C( 19), UINT8_C( 18), UINT8_C( 17), UINT8_C( 16), UINT8_C(  1) },
      { UINT8_C(  5), UINT8_C(  4), UINT8_C(  7), UINT8_C(  6), UINT8_C(  3), UINT8_C(  7), UINT8_C(  6), UINT8_C(  7),
        UINT8_C(  2), UINT8_C(  1), UINT8_C(  2), UINT8_C(  5), UINT8_C(  4), UINT8_C(  4), UINT8_C(  4), UINT8_C(  0) },
      { UINT8_C(  3), UINT8_C(  2), UINT8_C(  3), UINT8_C(  3), UINT8_C(  1), UINT8_C(  3), UINT8_C(  3), UINT8_C(  4),
        UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  2), UINT8_C(  2), UINT8_C(  2), UINT8_C(  2), UINT8_C(  0) },
      { UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0) } },
    { { UINT8_C( 12), UINT8_C(192), UINT8_C(153), UINT8_C(117), UINT8_C(226), UINT8_C(110), UINT8_C( 85), UINT8_C(196),
        UINT8_C(134), UINT8_C( 57), UINT8_C(149), UINT8_C(137), UINT8_C( 23), UINT8_C( 24), UINT8_C( 88), UINT8_C(188) },
      { UINT8_C(  6), UINT8_C( 96), UINT8_C( 77), UINT8_C( 59), UINT8_C(113), UINT8_C( 55), UINT8_C( 43), UINT8_C( 98),
        UINT8_C( 67), UINT8_C( 29), UINT8_C( 75), UINT8_C( 69), UINT8_C( 12), UINT8_C( 12), UINT8_C( 44), UINT8_C( 94) },
      { UINT8_C(  2), UINT8_C( 24), UINT8_C( 19), UINT8_C( 15), UINT8_C( 28), UINT8_C( 14), UINT8_C( 11), UINT8_C( 25),
        UINT8_C( 17), UINT8_C(  7), UINT8_C( 19), UINT8_C( 17), UINT8_C(  3), UINT8_C(  3), UINT8_C( 11), UINT8_C( 24) },
      { UINT8_C(  0), UINT8_C(  6), UINT8_C(  5), UINT8_C(  4), UINT8_C(  7), UINT8_C(  3), UINT8_C(  3), UINT8_C(  6),
        UINT8_C(  4), UINT8_C(  2), UINT8_C(  5), UINT8_C(  4), UINT8_C(  1), UINT8_C(  1), UINT8_C(  3), UINT8_C(  6) },
      { UINT8_C(  0), UINT8_C(  3), UINT8_C(  2), UINT8_C(  2), UINT8_C(  4), UINT8_C(  2), UINT8_C(  1), UINT8_C(  3),
        UINT8_C(  2), UINT8_C(  1), UINT8_C(  2), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  3) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1),
        UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1) } },
    { { UINT8_C(140), UINT8_C( 47), UINT8_C(113), UINT8_C(233), UINT8_C( 14), UINT8_C( 38), UINT8_C(204), UINT8_C( 67),
        UINT8_C( 68), UINT8_C(  5), UINT8_C(219), UINT8_C(210), UINT8_C(137), UINT8_C( 95), UINT8_C(220), UINT8_C(150) },
      { UINT8_C( 70), UINT8_C( 24), UINT8_C( 57), UINT8_C(117), UINT8_C(  7), UINT8_C( 19), UINT8_C(102), UINT8_C( 34),
        UINT8_C( 34), UINT8_C(  3), UINT8_C(110), UINT8_C(105), UINT8_C( 69), UINT8_C( 48), UINT8_C(110), UINT8_C( 75) },
      { UINT8_C( 18), UINT8_C(  6), UINT8_C( 14), UINT8_C( 29), UINT8_C(  2), UINT8_C(  5), UINT8_C( 26), UINT8_C(  8),
        UINT8_C(  9), UINT8_C(  1), UINT8_C( 27), UINT8_C( 26), UINT8_C( 17), UINT8_C( 12), UINT8_C( 28), UINT8_C( 19) },
      { UINT8_C(  4), UINT8_C(  1), UINT8_C(  4), UINT8_C(  7), UINT8_C(  0), UINT8_C(  1), UINT8_C(  6), UINT8_C(  2),
        UINT8_C(  2), UINT8_C(  0), UINT8_C(  7), UINT8_C(  7), UINT8_C(  4), UINT8_C(  3), UINT8_C(  7), UINT8_C(  5) },
      { UINT8_C(  2), UINT8_C(  1), UINT8_C(  2), UINT8_C(  4), UINT8_C(  0), UINT8_C(  1), UINT8_C(  3), UINT8_C(  1),
        UINT8_C(  1), UINT8_C(  0), UINT8_C(  3), UINT8_C(  3), UINT8_C(  2), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2) },
      { UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1) } },
    { { UINT8_C( 31), UINT8_C(117), UINT8_C( 11), UINT8_C(  1), UINT8_C(227), UINT8_C( 96), UINT8_C(197), UINT8_C(106),
        UINT8_C(153), UINT8_C( 90), UINT8_C(243), UINT8_C(176), UINT8_C(115), UINT8_C( 75), UINT8_C(109),    UINT8_MAX },
      { UINT8_C( 16), UINT8_C( 59), UINT8_C(  6), UINT8_C(  1), UINT8_C(114), UINT8_C( 48), UINT8_C( 99), UINT8_C( 53),
        UINT8_C( 77), UINT8_C( 45), UINT8_C(122), UINT8_C( 88), UINT8_C( 58), UINT8_C( 38), UINT8_C( 55), UINT8_C(128) },
      { UINT8_C(  4), UINT8_C( 15), UINT8_C(  1), UINT8_C(  0), UINT8_C( 28), UINT8_C( 12), UINT8_C( 25), UINT8_C( 13),
        UINT8_C( 19), UINT8_C( 11), UINT8_C( 30), UINT8_C( 22), UINT8_C( 14), UINT8_C(  9), UINT8_C( 14), UINT8_C( 32) },
      { UINT8_C(  1), UINT8_C(  4), UINT8_C(  0), UINT8_C(  0), UINT8_C(  7), UINT8_C(  3), UINT8_C(  6), UINT8_C(  3),
        UINT8_C(  5), UINT8_C(  3), UINT8_C(  8), UINT8_C(  6), UINT8_C(  4), UINT8_C(  2), UINT8_C(  3), UINT8_C(  8) },
      { UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C(  4), UINT8_C(  2), UINT8_C(  3), UINT8_C(  2),
        UINT8_C(  2), UINT8_C(  1), UINT8_C(  4), UINT8_C(  3), UINT8_C(  2), UINT8_C(  1), UINT8_C(  2), UINT8_C(  4) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),
        UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1) } },
    { { UINT8_C(122), UINT8_C(222), UINT8_C(232), UINT8_C(137), UINT8_C(  4), UINT8_C(180), UINT8_C(204), UINT8_C( 72),
        UINT8_C(185), UINT8_C(167), UINT8_C( 26), UINT8_C( 66), UINT8_C(  6), UINT8_C(247), UINT8_C(216), UINT8_C( 38) },
      { UINT8_C( 61), UINT8_C(111), UINT8_C(116), UINT8_C( 69), UINT8_C(  2), UINT8_C( 90), UINT8_C(102), UINT8_C( 36),
        UINT8_C( 93), UINT8_C( 84), UINT8_C( 13), UINT8_C( 33), UINT8_C(  3), UINT8_C(124), UINT8_C(108), UINT8_C( 19) },
      { UINT8_C( 15), UINT8_C( 28), UINT8_C( 29), UINT8_C( 17), UINT8_C(  1), UINT8_C( 23), UINT8_C( 26), UINT8_C(  9),
        UINT8_C( 23), UINT8_C( 21), UINT8_C(  3), UINT8_C(  8), UINT8_C(  1), UINT8_C( 31), UINT8_C( 27), UINT8_C(  5) },
      { UINT8_C(  4), UINT8_C(  7), UINT8_C(  7), UINT8_C(  4), UINT8_C(  0), UINT8_C(  6), UINT8_C(  6), UINT8_C(  2),
        UINT8_C(  6), UINT8_C(  5), UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  8), UINT8_C(  7), UINT8_C(  1) },
      { UINT8_C(  2), UINT8_C(  3), UINT8_C(  4), UINT8_C(  2), UINT8_C(  0), UINT8_C(  3), UINT8_C(  3), UINT8_C(  1),
        UINT8_C(  3), UINT8_C(  3), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  4), UINT8_C(  3), UINT8_C(  1) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0),
        UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0) } },
    { { UINT8_C(108), UINT8_C(227), UINT8_C( 39), UINT8_C( 80), UINT8_C( 67), UINT8_C(237), UINT8_C(186), UINT8_C(221),
        UINT8_C( 71), UINT8_C(173), UINT8_C(141), UINT8_C(186), UINT8_C(248), UINT8_C(250), UINT8_C(185), UINT8_C(115) },
      { UINT8_C( 54), UINT8_C(114), UINT8_C( 20), UINT8_C( 40), UINT8_C( 34), UINT8_C(119), UINT8_C( 93), UINT8_C(111),
        UINT8_C( 36), UINT8_C( 87), UINT8_C( 71), UINT8_C( 93), UINT8_C(124), UINT8_C(125), UINT8_C( 93), UINT8_C( 58) },
      { UINT8_C( 14), UINT8_C( 28), UINT8_C(  5), UINT8_C( 10), UINT8_C(  8), UINT8_C( 30), UINT8_C( 23), UINT8_C( 28),
        UINT8_C(  9), UINT8_C( 22), UINT8_C( 18), UINT8_C( 23), UINT8_C( 31), UINT8_C( 31), UINT8_C( 23), UINT8_C( 14) },
      { UINT8_C(  3), UINT8_C(  7), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2), UINT8_C(  7), UINT8_C(  6), UINT8_C(  7),
        UINT8_C(  2), UINT8_C(  5), UINT8_C(  4), UINT8_C(  6), UINT8_C(  8), UINT8_C(  8), UINT8_C(  6), UINT8_C(  4) },
      { UINT8_C(  2), UINT8_C(  4), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  4), UINT8_C(  3), UINT8_C(  3),
        UINT8_C(  1), UINT8_C(  3), UINT8_C(  2), UINT8_C(  3), UINT8_C(  4), UINT8_C(  4), UINT8_C(  3), UINT8_C(  2) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0) } },
    { { UINT8_C(217), UINT8_C(161), UINT8_C(252), UINT8_C(221), UINT8_C( 85), UINT8_C(200), UINT8_C( 38), UINT8_C( 14),
        UINT8_C(111), UINT8_C( 64), UINT8_C( 81), UINT8_C(118), UINT8_C( 55), UINT8_C( 41), UINT8_C(156), UINT8_C(164) },
      { UINT8_C(109), UINT8_C( 81), UINT8_C(126), UINT8_C(111), UINT8_C( 43), UINT8_C(100), UINT8_C( 19), UINT8_C(  7),
        UINT8_C( 56), UINT8_C( 32), UINT8_C( 41), UINT8_C( 59), UINT8_C( 28), UINT8_C( 21), UINT8_C( 78), UINT8_C( 82) },
      { UINT8_C( 27), UINT8_C( 20), UINT8_C( 32), UINT8_C( 28), UINT8_C( 11), UINT8_C( 25), UINT8_C(  5), UINT8_C(  2),
        UINT8_C( 14), UINT8_C(  8), UINT8_C( 10), UINT8_C( 15), UINT8_C(  7), UINT8_C(  5), UINT8_C( 20), UINT8_C( 21) },
      { UINT8_C(  7), UINT8_C(  5), UINT8_C(  8), UINT8_C(  7), UINT8_C(  3), UINT8_C(  6), UINT8_C(  1), UINT8_C(  0),
        UINT8_C(  3), UINT8_C(  2), UINT8_C(  3), UINT8_C(  4), UINT8_C(  2), UINT8_C(  1), UINT8_C(  5), UINT8_C(  5) },
      { UINT8_C(  3), UINT8_C(  3), UINT8_C(  4), UINT8_C(  3), UINT8_C(  1), UINT8_C(  3), UINT8_C(  1), UINT8_C(  0),
        UINT8_C(  2), UINT8_C(  1), UINT8_C(  1), UINT8_C(  2), UINT8_C(  1), UINT8_C(  1), UINT8_C(  2), UINT8_C(  3) },
      { UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1) } },
    { { UINT8_C( 13), UINT8_C(195), UINT8_C(244), UINT8_C( 80), UINT8_C(176), UINT8_C(174), UINT8_C( 45), UINT8_C(248),
        UINT8_C( 91), UINT8_C(187), UINT8_C(178), UINT8_C( 83), UINT8_C(181), UINT8_C(108), UINT8_C(198), UINT8_C(142) },
      { UINT8_C(  7), UINT8_C( 98), UINT8_C(122), UINT8_C( 40), UINT8_C( 88), UINT8_C( 87), UINT8_C( 23), UINT8_C(124),
        UINT8_C( 46), UINT8_C( 94), UINT8_C( 89), UINT8_C( 42), UINT8_C( 91), UINT8_C( 54), UINT8_C( 99), UINT8_C( 71) },
      { UINT8_C(  2), UINT8_C( 24), UINT8_C( 31), UINT8_C( 10), UINT8_C( 22), UINT8_C( 22), UINT8_C(  6), UINT8_C( 31),
        UINT8_C( 11), UINT8_C( 23), UINT8_C( 22), UINT8_C( 10), UINT8_C( 23), UINT8_C( 14), UINT8_C( 25), UINT8_C( 18) },
      { UINT8_C(  0), UINT8_C(  6), UINT8_C(  8), UINT8_C(  3), UINT8_C(  6), UINT8_C(  5), UINT8_C(  1), UINT8_C(  8),
        UINT8_C(  3), UINT8_C(  6), UINT8_C(  6), UINT8_C(  3), UINT8_C(  6), UINT8_C(  3), UINT8_C(  6), UINT8_C(  4) },
      { UINT8_C(  0), UINT8_C(  3), UINT8_C(  4), UINT8_C(  1), UINT8_C(  3), UINT8_C(  3), UINT8_C(  1), UINT8_C(  4),
        UINT8_C(  1), UINT8_C(  3), UINT8_C(  3), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2), UINT8_C(  3), UINT8_C(  2) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);

    simde_uint8x16_t r1 = simde_vrshrq_n_u8(a, 1);
    simde_uint8x16_t r3 = simde_vrshrq_n_u8(a, 3);
    simde_uint8x16_t r5 = simde_vrshrq_n_u8(a, 5);
    simde_uint8x16_t r6 = simde_vrshrq_n_u8(a, 6);
    simde_uint8x16_t r8 = simde_vrshrq_n_u8(a, 8);

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
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();

    simde_uint8x16_t r1 = simde_vrshrq_n_u8(a, 1);
    simde_uint8x16_t r3 = simde_vrshrq_n_u8(a, 3);
    simde_uint8x16_t r5 = simde_vrshrq_n_u8(a, 5);
    simde_uint8x16_t r6 = simde_vrshrq_n_u8(a, 6);
    simde_uint8x16_t r8 = simde_vrshrq_n_u8(a, 8);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshrq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { { UINT16_C( 6904), UINT16_C(18521), UINT16_C(38790), UINT16_C(17479), UINT16_C( 9022), UINT16_C(30369), UINT16_C(47080), UINT16_C(51744) },
      { UINT16_C(  863), UINT16_C( 2315), UINT16_C( 4849), UINT16_C( 2185), UINT16_C( 1128), UINT16_C( 3796), UINT16_C( 5885), UINT16_C( 6468) },
      { UINT16_C(  108), UINT16_C(  289), UINT16_C(  606), UINT16_C(  273), UINT16_C(  141), UINT16_C(  475), UINT16_C(  736), UINT16_C(  809) },
      { UINT16_C(    7), UINT16_C(   18), UINT16_C(   38), UINT16_C(   17), UINT16_C(    9), UINT16_C(   30), UINT16_C(   46), UINT16_C(   51) },
      { UINT16_C(    1), UINT16_C(    2), UINT16_C(    5), UINT16_C(    2), UINT16_C(    1), UINT16_C(    4), UINT16_C(    6), UINT16_C(    6) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1) } },
    { { UINT16_C(38955), UINT16_C(50982), UINT16_C(43727), UINT16_C(47830), UINT16_C(43384), UINT16_C(65088), UINT16_C(30354), UINT16_C(35491) },
      { UINT16_C( 4869), UINT16_C( 6373), UINT16_C( 5466), UINT16_C( 5979), UINT16_C( 5423), UINT16_C( 8136), UINT16_C( 3794), UINT16_C( 4436) },
      { UINT16_C(  609), UINT16_C(  797), UINT16_C(  683), UINT16_C(  747), UINT16_C(  678), UINT16_C( 1017), UINT16_C(  474), UINT16_C(  555) },
      { UINT16_C(   38), UINT16_C(   50), UINT16_C(   43), UINT16_C(   47), UINT16_C(   42), UINT16_C(   64), UINT16_C(   30), UINT16_C(   35) },
      { UINT16_C(    5), UINT16_C(    6), UINT16_C(    5), UINT16_C(    6), UINT16_C(    5), UINT16_C(    8), UINT16_C(    4), UINT16_C(    4) },
      { UINT16_C(    1), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1), UINT16_C(    0), UINT16_C(    1) } },
    { { UINT16_C(64656), UINT16_C( 6098), UINT16_C( 6803), UINT16_C(53595), UINT16_C(64573), UINT16_C( 9799), UINT16_C(26548), UINT16_C(57328) },
      { UINT16_C( 8082), UINT16_C(  762), UINT16_C(  850), UINT16_C( 6699), UINT16_C( 8072), UINT16_C( 1225), UINT16_C( 3319), UINT16_C( 7166) },
      { UINT16_C( 1010), UINT16_C(   95), UINT16_C(  106), UINT16_C(  837), UINT16_C( 1009), UINT16_C(  153), UINT16_C(  415), UINT16_C(  896) },
      { UINT16_C(   63), UINT16_C(    6), UINT16_C(    7), UINT16_C(   52), UINT16_C(   63), UINT16_C(   10), UINT16_C(   26), UINT16_C(   56) },
      { UINT16_C(    8), UINT16_C(    1), UINT16_C(    1), UINT16_C(    7), UINT16_C(    8), UINT16_C(    1), UINT16_C(    3), UINT16_C(    7) },
      { UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1) } },
    { { UINT16_C( 5632), UINT16_C(53159), UINT16_C(32193), UINT16_C(14729), UINT16_C(51494), UINT16_C(47415), UINT16_C(55871), UINT16_C(53315) },
      { UINT16_C(  704), UINT16_C( 6645), UINT16_C( 4024), UINT16_C( 1841), UINT16_C( 6437), UINT16_C( 5927), UINT16_C( 6984), UINT16_C( 6664) },
      { UINT16_C(   88), UINT16_C(  831), UINT16_C(  503), UINT16_C(  230), UINT16_C(  805), UINT16_C(  741), UINT16_C(  873), UINT16_C(  833) },
      { UINT16_C(    6), UINT16_C(   52), UINT16_C(   31), UINT16_C(   14), UINT16_C(   50), UINT16_C(   46), UINT16_C(   55), UINT16_C(   52) },
      { UINT16_C(    1), UINT16_C(    6), UINT16_C(    4), UINT16_C(    2), UINT16_C(    6), UINT16_C(    6), UINT16_C(    7), UINT16_C(    7) },
      { UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1) } },
    { { UINT16_C( 5846), UINT16_C(27111), UINT16_C(16944), UINT16_C(27963), UINT16_C(33342), UINT16_C(62099), UINT16_C(34026), UINT16_C(60114) },
      { UINT16_C(  731), UINT16_C( 3389), UINT16_C( 2118), UINT16_C( 3495), UINT16_C( 4168), UINT16_C( 7762), UINT16_C( 4253), UINT16_C( 7514) },
      { UINT16_C(   91), UINT16_C(  424), UINT16_C(  265), UINT16_C(  437), UINT16_C(  521), UINT16_C(  970), UINT16_C(  532), UINT16_C(  939) },
      { UINT16_C(    6), UINT16_C(   26), UINT16_C(   17), UINT16_C(   27), UINT16_C(   33), UINT16_C(   61), UINT16_C(   33), UINT16_C(   59) },
      { UINT16_C(    1), UINT16_C(    3), UINT16_C(    2), UINT16_C(    3), UINT16_C(    4), UINT16_C(    8), UINT16_C(    4), UINT16_C(    7) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1) } },
    { { UINT16_C(31130), UINT16_C(23481), UINT16_C(17142), UINT16_C( 7573), UINT16_C(52236), UINT16_C(19414), UINT16_C( 6567), UINT16_C(32027) },
      { UINT16_C( 3891), UINT16_C( 2935), UINT16_C( 2143), UINT16_C(  947), UINT16_C( 6530), UINT16_C( 2427), UINT16_C(  821), UINT16_C( 4003) },
      { UINT16_C(  486), UINT16_C(  367), UINT16_C(  268), UINT16_C(  118), UINT16_C(  816), UINT16_C(  303), UINT16_C(  103), UINT16_C(  500) },
      { UINT16_C(   30), UINT16_C(   23), UINT16_C(   17), UINT16_C(    7), UINT16_C(   51), UINT16_C(   19), UINT16_C(    6), UINT16_C(   31) },
      { UINT16_C(    4), UINT16_C(    3), UINT16_C(    2), UINT16_C(    1), UINT16_C(    6), UINT16_C(    2), UINT16_C(    1), UINT16_C(    4) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(  559), UINT16_C(24551), UINT16_C( 8772), UINT16_C(33741), UINT16_C(24740), UINT16_C(36469), UINT16_C(18404), UINT16_C(32632) },
      { UINT16_C(   70), UINT16_C( 3069), UINT16_C( 1097), UINT16_C( 4218), UINT16_C( 3093), UINT16_C( 4559), UINT16_C( 2301), UINT16_C( 4079) },
      { UINT16_C(    9), UINT16_C(  384), UINT16_C(  137), UINT16_C(  527), UINT16_C(  387), UINT16_C(  570), UINT16_C(  288), UINT16_C(  510) },
      { UINT16_C(    1), UINT16_C(   24), UINT16_C(    9), UINT16_C(   33), UINT16_C(   24), UINT16_C(   36), UINT16_C(   18), UINT16_C(   32) },
      { UINT16_C(    0), UINT16_C(    3), UINT16_C(    1), UINT16_C(    4), UINT16_C(    3), UINT16_C(    4), UINT16_C(    2), UINT16_C(    4) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(12736), UINT16_C(47066), UINT16_C(28532), UINT16_C(32980), UINT16_C(43580), UINT16_C(58315), UINT16_C(59331), UINT16_C(62304) },
      { UINT16_C( 1592), UINT16_C( 5883), UINT16_C( 3567), UINT16_C( 4123), UINT16_C( 5448), UINT16_C( 7289), UINT16_C( 7416), UINT16_C( 7788) },
      { UINT16_C(  199), UINT16_C(  735), UINT16_C(  446), UINT16_C(  515), UINT16_C(  681), UINT16_C(  911), UINT16_C(  927), UINT16_C(  974) },
      { UINT16_C(   12), UINT16_C(   46), UINT16_C(   28), UINT16_C(   32), UINT16_C(   43), UINT16_C(   57), UINT16_C(   58), UINT16_C(   61) },
      { UINT16_C(    2), UINT16_C(    6), UINT16_C(    3), UINT16_C(    4), UINT16_C(    5), UINT16_C(    7), UINT16_C(    7), UINT16_C(    8) },
      { UINT16_C(    0), UINT16_C(    1), UINT16_C(    0), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1), UINT16_C(    1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);

    simde_uint16x8_t r3 = simde_vrshrq_n_u16(a, 3);
    simde_uint16x8_t r6 = simde_vrshrq_n_u16(a, 6);
    simde_uint16x8_t r10 = simde_vrshrq_n_u16(a, 10);
    simde_uint16x8_t r13 = simde_vrshrq_n_u16(a, 13);
    simde_uint16x8_t r16 = simde_vrshrq_n_u16(a, 16);

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
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();

    simde_uint16x8_t r3 = simde_vrshrq_n_u16(a, 3);
    simde_uint16x8_t r6 = simde_vrshrq_n_u16(a, 6);
    simde_uint16x8_t r10 = simde_vrshrq_n_u16(a, 10);
    simde_uint16x8_t r13 = simde_vrshrq_n_u16(a, 13);
    simde_uint16x8_t r16 = simde_vrshrq_n_u16(a, 16);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshrq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { { UINT32_C( 434564502), UINT32_C(1326181401), UINT32_C(2107734821), UINT32_C(2106644388) },
      { UINT32_C(   6790070), UINT32_C(  20721584), UINT32_C(  32933357), UINT32_C(  32916319) },
      { UINT32_C(     53047), UINT32_C(    161887), UINT32_C(    257292), UINT32_C(    257159) },
      { UINT32_C(       829), UINT32_C(      2529), UINT32_C(      4020), UINT32_C(      4018) },
      { UINT32_C(         6), UINT32_C(        20), UINT32_C(        31), UINT32_C(        31) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1426567452), UINT32_C( 955711525), UINT32_C(3896099004), UINT32_C(3085639456) },
      { UINT32_C(  22290116), UINT32_C(  14932993), UINT32_C(  60876547), UINT32_C(  48213117) },
      { UINT32_C(    174142), UINT32_C(    116664), UINT32_C(    475598), UINT32_C(    376665) },
      { UINT32_C(      2721), UINT32_C(      1823), UINT32_C(      7431), UINT32_C(      5885) },
      { UINT32_C(        21), UINT32_C(        14), UINT32_C(        58), UINT32_C(        46) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         1), UINT32_C(         1) } },
    { { UINT32_C( 634441996), UINT32_C(3799309245), UINT32_C(4200535382), UINT32_C( 158920685) },
      { UINT32_C(   9913156), UINT32_C(  59364207), UINT32_C(  65633365), UINT32_C(   2483136) },
      { UINT32_C(     77447), UINT32_C(    463783), UINT32_C(    512761), UINT32_C(     19399) },
      { UINT32_C(      1210), UINT32_C(      7247), UINT32_C(      8012), UINT32_C(       303) },
      { UINT32_C(         9), UINT32_C(        57), UINT32_C(        63), UINT32_C(         2) },
      { UINT32_C(         0), UINT32_C(         1), UINT32_C(         1), UINT32_C(         0) } },
    { { UINT32_C(3328081824), UINT32_C(1006523775), UINT32_C( 908277525), UINT32_C(1659702870) },
      { UINT32_C(  52001279), UINT32_C(  15726934), UINT32_C(  14191836), UINT32_C(  25932857) },
      { UINT32_C(    406260), UINT32_C(    122867), UINT32_C(    110874), UINT32_C(    202600) },
      { UINT32_C(      6348), UINT32_C(      1920), UINT32_C(      1732), UINT32_C(      3166) },
      { UINT32_C(        50), UINT32_C(        15), UINT32_C(        14), UINT32_C(        25) },
      { UINT32_C(         1), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2626141663), UINT32_C(4001299608), UINT32_C(4276674065), UINT32_C(1846042829) },
      { UINT32_C(  41033463), UINT32_C(  62520306), UINT32_C(  66823032), UINT32_C(  28844419) },
      { UINT32_C(    320574), UINT32_C(    488440), UINT32_C(    522055), UINT32_C(    225347) },
      { UINT32_C(      5009), UINT32_C(      7632), UINT32_C(      8157), UINT32_C(      3521) },
      { UINT32_C(        39), UINT32_C(        60), UINT32_C(        64), UINT32_C(        28) },
      { UINT32_C(         1), UINT32_C(         1), UINT32_C(         1), UINT32_C(         0) } },
    { { UINT32_C(1580492511), UINT32_C(3516543676), UINT32_C(3221732713), UINT32_C(2871194828) },
      { UINT32_C(  24695195), UINT32_C(  54945995), UINT32_C(  50339574), UINT32_C(  44862419) },
      { UINT32_C(    192931), UINT32_C(    429266), UINT32_C(    393278), UINT32_C(    350488) },
      { UINT32_C(      3015), UINT32_C(      6707), UINT32_C(      6145), UINT32_C(      5476) },
      { UINT32_C(        24), UINT32_C(        52), UINT32_C(        48), UINT32_C(        43) },
      { UINT32_C(         0), UINT32_C(         1), UINT32_C(         1), UINT32_C(         1) } },
    { { UINT32_C(1229499057), UINT32_C(3073885862), UINT32_C(1924538532), UINT32_C(1625341568) },
      { UINT32_C(  19210923), UINT32_C(  48029467), UINT32_C(  30070915), UINT32_C(  25395962) },
      { UINT32_C(    150085), UINT32_C(    375230), UINT32_C(    234929), UINT32_C(    198406) },
      { UINT32_C(      2345), UINT32_C(      5863), UINT32_C(      3671), UINT32_C(      3100) },
      { UINT32_C(        18), UINT32_C(        46), UINT32_C(        29), UINT32_C(        24) },
      { UINT32_C(         0), UINT32_C(         1), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3770553380), UINT32_C(2947700806), UINT32_C(3798972694), UINT32_C(1603113646) },
      { UINT32_C(  58914897), UINT32_C(  46057825), UINT32_C(  59358948), UINT32_C(  25048651) },
      { UINT32_C(    460273), UINT32_C(    359827), UINT32_C(    463742), UINT32_C(    195693) },
      { UINT32_C(      7192), UINT32_C(      5622), UINT32_C(      7246), UINT32_C(      3058) },
      { UINT32_C(        56), UINT32_C(        44), UINT32_C(        57), UINT32_C(        24) },
      { UINT32_C(         1), UINT32_C(         1), UINT32_C(         1), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);

    simde_uint32x4_t r6 = simde_vrshrq_n_u32(a, 6);
    simde_uint32x4_t r13 = simde_vrshrq_n_u32(a, 13);
    simde_uint32x4_t r19 = simde_vrshrq_n_u32(a, 19);
    simde_uint32x4_t r26 = simde_vrshrq_n_u32(a, 26);
    simde_uint32x4_t r32 = simde_vrshrq_n_u32(a, 32);

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
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();

    simde_uint32x4_t r6 = simde_vrshrq_n_u32(a, 6);
    simde_uint32x4_t r13 = simde_vrshrq_n_u32(a, 13);
    simde_uint32x4_t r19 = simde_vrshrq_n_u32(a, 19);
    simde_uint32x4_t r26 = simde_vrshrq_n_u32(a, 26);
    simde_uint32x4_t r32 = simde_vrshrq_n_u32(a, 32);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshrq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t r13[2];
    uint64_t r26[2];
    uint64_t r39[2];
    uint64_t r52[2];
    uint64_t r64[2];
  } test_vec[] = {
    { { UINT64_C(14268038043289444930), UINT64_C(16018600277606132720) },
      { UINT64_C(    1741703862706231), UINT64_C(    1955395541699967) },
      { UINT64_C(        212610334803), UINT64_C(        238695744836) },
      { UINT64_C(            25953410), UINT64_C(            29137664) },
      { UINT64_C(                3168), UINT64_C(                3557) },
      { UINT64_C(                   1), UINT64_C(                   1) } },
    { { UINT64_C( 1004212844393534372), UINT64_C(17706996720702848391) },
      { UINT64_C(     122584575731633), UINT64_C(    2161498623132672) },
      { UINT64_C(         14963937467), UINT64_C(        263854812394) },
      { UINT64_C(             1826653), UINT64_C(            32208839) },
      { UINT64_C(                 223), UINT64_C(                3932) },
      { UINT64_C(                   0), UINT64_C(                   1) } },
    { { UINT64_C(17549758105951322565), UINT64_C( 6999528119195679791) },
      { UINT64_C(    2142304456292886), UINT64_C(     854434584862754) },
      { UINT64_C(        261511774450), UINT64_C(        104301096785) },
      { UINT64_C(            31922824), UINT64_C(            12732067) },
      { UINT64_C(                3897), UINT64_C(                1554) },
      { UINT64_C(                   1), UINT64_C(                   0) } },
    { { UINT64_C( 5743283352518859108), UINT64_C(15916761319608890170) },
      { UINT64_C(     701084393618025), UINT64_C(    1942964028272570) },
      { UINT64_C(         85581591018), UINT64_C(        237178226107) },
      { UINT64_C(            10446972), UINT64_C(            28952420) },
      { UINT64_C(                1275), UINT64_C(                3534) },
      { UINT64_C(                   0), UINT64_C(                   1) } },
    { { UINT64_C(11054701464871183732), UINT64_C( 2633199228186095213) },
      { UINT64_C(    1349450862411033), UINT64_C(     321435452659435) },
      { UINT64_C(        164727888478), UINT64_C(         39237726155) },
      { UINT64_C(            20108385), UINT64_C(             4789761) },
      { UINT64_C(                2455), UINT64_C(                 585) },
      { UINT64_C(                   1), UINT64_C(                   0) } },
    { { UINT64_C( 5706200459837691930), UINT64_C( 5666971830166825139) },
      { UINT64_C(     696557673320031), UINT64_C(     691769022237161) },
      { UINT64_C(         85029012856), UINT64_C(         84444460722) },
      { UINT64_C(            10379518), UINT64_C(            10308162) },
      { UINT64_C(                1267), UINT64_C(                1258) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(16593283551739594821), UINT64_C( 4576109281162569117) },
      { UINT64_C(    2025547308561962), UINT64_C(     558607089985665) },
      { UINT64_C(        247259192940), UINT64_C(         68189342039) },
      { UINT64_C(            30183007), UINT64_C(             8323894) },
      { UINT64_C(                3684), UINT64_C(                1016) },
      { UINT64_C(                   1), UINT64_C(                   0) } },
    { { UINT64_C( 9140145378369293427), UINT64_C( 8836886232157394297) },
      { UINT64_C(    1115740402632970), UINT64_C(    1078721463886401) },
      { UINT64_C(        136198779618), UINT64_C(        131679866197) },
      { UINT64_C(            16625828), UINT64_C(            16074202) },
      { UINT64_C(                2030), UINT64_C(                1962) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);

    simde_uint64x2_t r13 = simde_vrshrq_n_u64(a, 13);
    simde_uint64x2_t r26 = simde_vrshrq_n_u64(a, 26);
    simde_uint64x2_t r39 = simde_vrshrq_n_u64(a, 39);
    simde_uint64x2_t r52 = simde_vrshrq_n_u64(a, 52);
    simde_uint64x2_t r64 = simde_vrshrq_n_u64(a, 64);

    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r39, simde_vld1q_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x2(r52, simde_vld1q_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x2(r64, simde_vld1q_u64(test_vec[i].r64));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();

    simde_uint64x2_t r13 = simde_vrshrq_n_u64(a, 13);
    simde_uint64x2_t r26 = simde_vrshrq_n_u64(a, 26);
    simde_uint64x2_t r39 = simde_vrshrq_n_u64(a, 39);
    simde_uint64x2_t r52 = simde_vrshrq_n_u64(a, 52);
    simde_uint64x2_t r64 = simde_vrshrq_n_u64(a, 64);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrshrd_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t r13;
    int64_t r26;
    int64_t r39;
    int64_t r52;
    int64_t r64;
  } test_vec[] = {
    { -INT64_C( 1790017526102052542),
      -INT64_C(     218507998791754),
      -INT64_C(         26673339696),
      -INT64_C(             3256023),
      -INT64_C(                 397),
       INT64_C(                   0) },
    { -INT64_C( 5765476926449100793),
      -INT64_C(     703793570123181),
      -INT64_C(         85912301040),
      -INT64_C(            10487341),
      -INT64_C(                1280),
       INT64_C(                   0) },
    {  INT64_C( 2313109900104114214),
       INT64_C(     282362048352553),
       INT64_C(         34468023481),
       INT64_C(             4207522),
       INT64_C(                 514),
       INT64_C(                   0) },
    { -INT64_C( 8077137427985548041),
      -INT64_C(     985978689939642),
      -INT64_C(        120358726799),
      -INT64_C(            14692227),
      -INT64_C(                1793),
       INT64_C(                   0) },
    {  INT64_C( 8746823298342313711),
       INT64_C(    1067727453410927),
       INT64_C(        130337823903),
       INT64_C(            15910379),
       INT64_C(                1942),
       INT64_C(                   0) },
    { -INT64_C( 4880297161830978482),
      -INT64_C(     595739399637571),
      -INT64_C(         72722094682),
      -INT64_C(             8877209),
      -INT64_C(                1084),
       INT64_C(                   0) },
    {  INT64_C( 3685554438004435923),
       INT64_C(     449896781982963),
       INT64_C(         54919040769),
       INT64_C(             6703984),
       INT64_C(                 818),
       INT64_C(                   0) },
    {  INT64_C( 4346498437147332212),
       INT64_C(     530578422503336),
       INT64_C(         64767873841),
       INT64_C(             7906235),
       INT64_C(                 965),
       INT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r13 = simde_vrshrd_n_s64(test_vec[i].a, 13);
    int64_t r26 = simde_vrshrd_n_s64(test_vec[i].a, 26);
    int64_t r39 = simde_vrshrd_n_s64(test_vec[i].a, 39);
    int64_t r52 = simde_vrshrd_n_s64(test_vec[i].a, 52);
    int64_t r64 = simde_vrshrd_n_s64(test_vec[i].a, 64);

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

    int64_t r13 = simde_vrshrd_n_s64(a, 13);
    int64_t r26 = simde_vrshrd_n_s64(a, 26);
    int64_t r39 = simde_vrshrd_n_s64(a, 39);
    int64_t r52 = simde_vrshrd_n_s64(a, 52);
    int64_t r64 = simde_vrshrd_n_s64(a, 64);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vrshrd_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r13;
    uint64_t r26;
    uint64_t r39;
    uint64_t r52;
    uint64_t r64;
  } test_vec[] = {
    { UINT64_C( 2475698945987162535),
      UINT64_C(     302209343992574),
      UINT64_C(         36890789062),
      UINT64_C(             4503270),
      UINT64_C(                 550),
      UINT64_C(                   0) },
    { UINT64_C(13513306553497811764),
      UINT64_C(    1649573553893776),
      UINT64_C(        201363959216),
      UINT64_C(            24580561),
      UINT64_C(                3001),
      UINT64_C(                   1) },
    { UINT64_C(  650915928106603812),
      UINT64_C(      79457510755201),
      UINT64_C(          9699403168),
      UINT64_C(             1184009),
      UINT64_C(                 145),
      UINT64_C(                   0) },
    { UINT64_C(11433650955471101923),
      UINT64_C(    1395709345150281),
      UINT64_C(        170374675922),
      UINT64_C(            20797690),
      UINT64_C(                2539),
      UINT64_C(                   1) },
    { UINT64_C(12998251088253815853),
      UINT64_C(    1586700572296608),
      UINT64_C(        193689034704),
      UINT64_C(            23643681),
      UINT64_C(                2886),
      UINT64_C(                   1) },
    { UINT64_C(11564674831902479371),
      UINT64_C(    1411703470691221),
      UINT64_C(        172327083825),
      UINT64_C(            21036021),
      UINT64_C(                2568),
      UINT64_C(                   1) },
    { UINT64_C( 6102141588205595920),
      UINT64_C(     744890330591503),
      UINT64_C(         90928995434),
      UINT64_C(            11099731),
      UINT64_C(                1355),
      UINT64_C(                   0) },
    { UINT64_C(  206400139149597000),
      UINT64_C(      25195329486035),
      UINT64_C(          3075601744),
      UINT64_C(              375440),
      UINT64_C(                  46),
      UINT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r13 = simde_vrshrd_n_u64(test_vec[i].a, 13);
    uint64_t r26 = simde_vrshrd_n_u64(test_vec[i].a, 26);
    uint64_t r39 = simde_vrshrd_n_u64(test_vec[i].a, 39);
    uint64_t r52 = simde_vrshrd_n_u64(test_vec[i].a, 52);
    uint64_t r64 = simde_vrshrd_n_u64(test_vec[i].a, 64);

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

    uint64_t r13 = simde_vrshrd_n_u64(a, 13);
    uint64_t r26 = simde_vrshrd_n_u64(a, 26);
    uint64_t r39 = simde_vrshrd_n_u64(a, 39);
    uint64_t r52 = simde_vrshrd_n_u64(a, 52);
    uint64_t r64 = simde_vrshrd_n_u64(a, 64);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
SIMDE_TEST_FUNC_LIST_ENTRY(vrshr_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshr_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshr_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshr_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshr_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshr_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshr_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshr_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrshrq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrq_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrq_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrq_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrq_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrshrd_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vrshrd_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
