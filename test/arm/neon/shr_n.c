#define SIMDE_TEST_ARM_NEON_INSN shr_n

#include "test-neon.h"
#include "../../../simde/arm/neon/shr_n.h"

static int
test_simde_vshr_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec[] = {
    { {  INT8_C(  14), -INT8_C(  74), -INT8_C(  83), -INT8_C(  76), -INT8_C(  68),  INT8_C( 105),  INT8_C(  53),  INT8_C(  43) },
      {  INT8_C(   7), -INT8_C(  37), -INT8_C(  42), -INT8_C(  38), -INT8_C(  34),  INT8_C(  52),  INT8_C(  26),  INT8_C(  21) },
      {  INT8_C(   1), -INT8_C(  10), -INT8_C(  11), -INT8_C(  10), -INT8_C(   9),  INT8_C(  13),  INT8_C(   6),  INT8_C(   5) },
      {  INT8_C(   0), -INT8_C(   3), -INT8_C(   3), -INT8_C(   3), -INT8_C(   3),  INT8_C(   3),  INT8_C(   1),  INT8_C(   1) },
      {  INT8_C(   0), -INT8_C(   2), -INT8_C(   2), -INT8_C(   2), -INT8_C(   2),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  57),  INT8_C(  96), -INT8_C(  64), -INT8_C(  76),  INT8_C(  99), -INT8_C(  51), -INT8_C(  25), -INT8_C(  73) },
      {  INT8_C(  28),  INT8_C(  48), -INT8_C(  32), -INT8_C(  38),  INT8_C(  49), -INT8_C(  26), -INT8_C(  13), -INT8_C(  37) },
      {  INT8_C(   7),  INT8_C(  12), -INT8_C(   8), -INT8_C(  10),  INT8_C(  12), -INT8_C(   7), -INT8_C(   4), -INT8_C(  10) },
      {  INT8_C(   1),  INT8_C(   3), -INT8_C(   2), -INT8_C(   3),  INT8_C(   3), -INT8_C(   2), -INT8_C(   1), -INT8_C(   3) },
      {  INT8_C(   0),  INT8_C(   1), -INT8_C(   1), -INT8_C(   2),  INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   2) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C( 107),  INT8_C( 102),  INT8_C(  97), -INT8_C( 115), -INT8_C(  78), -INT8_C(  41), -INT8_C( 109),  INT8_C(  42) },
      {  INT8_C(  53),  INT8_C(  51),  INT8_C(  48), -INT8_C(  58), -INT8_C(  39), -INT8_C(  21), -INT8_C(  55),  INT8_C(  21) },
      {  INT8_C(  13),  INT8_C(  12),  INT8_C(  12), -INT8_C(  15), -INT8_C(  10), -INT8_C(   6), -INT8_C(  14),  INT8_C(   5) },
      {  INT8_C(   3),  INT8_C(   3),  INT8_C(   3), -INT8_C(   4), -INT8_C(   3), -INT8_C(   2), -INT8_C(   4),  INT8_C(   1) },
      {  INT8_C(   1),  INT8_C(   1),  INT8_C(   1), -INT8_C(   2), -INT8_C(   2), -INT8_C(   1), -INT8_C(   2),  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  47), -INT8_C(  23),  INT8_C(   0), -INT8_C(  58),  INT8_C(  15),  INT8_C( 122),  INT8_C(  37),  INT8_C(  30) },
      {  INT8_C(  23), -INT8_C(  12),  INT8_C(   0), -INT8_C(  29),  INT8_C(   7),  INT8_C(  61),  INT8_C(  18),  INT8_C(  15) },
      {  INT8_C(   5), -INT8_C(   3),  INT8_C(   0), -INT8_C(   8),  INT8_C(   1),  INT8_C(  15),  INT8_C(   4),  INT8_C(   3) },
      {  INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   2),  INT8_C(   0),  INT8_C(   3),  INT8_C(   1),  INT8_C(   0) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  48), -INT8_C(  46), -INT8_C(  46), -INT8_C(  20),  INT8_C(  59),  INT8_C(   7),  INT8_C(  23),  INT8_C( 116) },
      {  INT8_C(  24), -INT8_C(  23), -INT8_C(  23), -INT8_C(  10),  INT8_C(  29),  INT8_C(   3),  INT8_C(  11),  INT8_C(  58) },
      {  INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   3),  INT8_C(   7),  INT8_C(   0),  INT8_C(   2),  INT8_C(  14) },
      {  INT8_C(   1), -INT8_C(   2), -INT8_C(   2), -INT8_C(   1),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 104), -INT8_C(  41),  INT8_C(  40), -INT8_C(  53), -INT8_C(  91),  INT8_C(  16), -INT8_C( 126),  INT8_C(  16) },
      {  INT8_C(  52), -INT8_C(  21),  INT8_C(  20), -INT8_C(  27), -INT8_C(  46),  INT8_C(   8), -INT8_C(  63),  INT8_C(   8) },
      {  INT8_C(  13), -INT8_C(   6),  INT8_C(   5), -INT8_C(   7), -INT8_C(  12),  INT8_C(   2), -INT8_C(  16),  INT8_C(   2) },
      {  INT8_C(   3), -INT8_C(   2),  INT8_C(   1), -INT8_C(   2), -INT8_C(   3),  INT8_C(   0), -INT8_C(   4),  INT8_C(   0) },
      {  INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   2),  INT8_C(   0), -INT8_C(   2),  INT8_C(   0) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C( 118), -INT8_C(  29), -INT8_C(  98),  INT8_C(  40), -INT8_C(  69),  INT8_C(  49),  INT8_C(  83), -INT8_C(  22) },
      {  INT8_C(  59), -INT8_C(  15), -INT8_C(  49),  INT8_C(  20), -INT8_C(  35),  INT8_C(  24),  INT8_C(  41), -INT8_C(  11) },
      {  INT8_C(  14), -INT8_C(   4), -INT8_C(  13),  INT8_C(   5), -INT8_C(   9),  INT8_C(   6),  INT8_C(  10), -INT8_C(   3) },
      {  INT8_C(   3), -INT8_C(   1), -INT8_C(   4),  INT8_C(   1), -INT8_C(   3),  INT8_C(   1),  INT8_C(   2), -INT8_C(   1) },
      {  INT8_C(   1), -INT8_C(   1), -INT8_C(   2),  INT8_C(   0), -INT8_C(   2),  INT8_C(   0),  INT8_C(   1), -INT8_C(   1) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C(  26),  INT8_C(  83), -INT8_C(  79),  INT8_C(  42), -INT8_C(  50), -INT8_C(  42),  INT8_C(  72), -INT8_C(   2) },
      {  INT8_C(  13),  INT8_C(  41), -INT8_C(  40),  INT8_C(  21), -INT8_C(  25), -INT8_C(  21),  INT8_C(  36), -INT8_C(   1) },
      {  INT8_C(   3),  INT8_C(  10), -INT8_C(  10),  INT8_C(   5), -INT8_C(   7), -INT8_C(   6),  INT8_C(   9), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   2), -INT8_C(   3),  INT8_C(   1), -INT8_C(   2), -INT8_C(   2),  INT8_C(   2), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   1), -INT8_C(   2),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   1), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);

    simde_int8x8_t r1 = simde_vshr_n_s8(a, 1);
    simde_int8x8_t r3 = simde_vshr_n_s8(a, 3);
    simde_int8x8_t r5 = simde_vshr_n_s8(a, 5);
    simde_int8x8_t r6 = simde_vshr_n_s8(a, 6);
    simde_int8x8_t r8 = simde_vshr_n_s8(a, 8);

    simde_test_arm_neon_assert_equal_i8x8(r1, simde_vld1_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r6, simde_vld1_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x8(r8, simde_vld1_s8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vshr_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { {  INT16_C(  2391), -INT16_C( 30287),  INT16_C( 21648), -INT16_C(  9648) },
      {  INT16_C(   298), -INT16_C(  3786),  INT16_C(  2706), -INT16_C(  1206) },
      {  INT16_C(    37), -INT16_C(   474),  INT16_C(   338), -INT16_C(   151) },
      {  INT16_C(     2), -INT16_C(    30),  INT16_C(    21), -INT16_C(    10) },
      {  INT16_C(     0), -INT16_C(     4),  INT16_C(     2), -INT16_C(     2) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C( 32696), -INT16_C(  7749),  INT16_C(  3517), -INT16_C(  3032) },
      { -INT16_C(  4087), -INT16_C(   969),  INT16_C(   439), -INT16_C(   379) },
      { -INT16_C(   511), -INT16_C(   122),  INT16_C(    54), -INT16_C(    48) },
      { -INT16_C(    32), -INT16_C(     8),  INT16_C(     3), -INT16_C(     3) },
      { -INT16_C(     4), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C( 25896), -INT16_C( 19991), -INT16_C( 18945),  INT16_C( 17860) },
      { -INT16_C(  3237), -INT16_C(  2499), -INT16_C(  2369),  INT16_C(  2232) },
      { -INT16_C(   405), -INT16_C(   313), -INT16_C(   297),  INT16_C(   279) },
      { -INT16_C(    26), -INT16_C(    20), -INT16_C(    19),  INT16_C(    17) },
      { -INT16_C(     4), -INT16_C(     3), -INT16_C(     3),  INT16_C(     2) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
    { { -INT16_C( 15514), -INT16_C(  7567), -INT16_C(  4534), -INT16_C( 24034) },
      { -INT16_C(  1940), -INT16_C(   946), -INT16_C(   567), -INT16_C(  3005) },
      { -INT16_C(   243), -INT16_C(   119), -INT16_C(    71), -INT16_C(   376) },
      { -INT16_C(    16), -INT16_C(     8), -INT16_C(     5), -INT16_C(    24) },
      { -INT16_C(     2), -INT16_C(     1), -INT16_C(     1), -INT16_C(     3) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 12297), -INT16_C( 30933),  INT16_C( 31524),  INT16_C( 27746) },
      { -INT16_C(  1538), -INT16_C(  3867),  INT16_C(  3940),  INT16_C(  3468) },
      { -INT16_C(   193), -INT16_C(   484),  INT16_C(   492),  INT16_C(   433) },
      { -INT16_C(    13), -INT16_C(    31),  INT16_C(    30),  INT16_C(    27) },
      { -INT16_C(     2), -INT16_C(     4),  INT16_C(     3),  INT16_C(     3) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  7675), -INT16_C( 18355),  INT16_C( 30250),  INT16_C(   940) },
      {  INT16_C(   959), -INT16_C(  2295),  INT16_C(  3781),  INT16_C(   117) },
      {  INT16_C(   119), -INT16_C(   287),  INT16_C(   472),  INT16_C(    14) },
      {  INT16_C(     7), -INT16_C(    18),  INT16_C(    29),  INT16_C(     0) },
      {  INT16_C(     0), -INT16_C(     3),  INT16_C(     3),  INT16_C(     0) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 27376),  INT16_C(  4020),  INT16_C( 30795), -INT16_C( 20139) },
      { -INT16_C(  3422),  INT16_C(   502),  INT16_C(  3849), -INT16_C(  2518) },
      { -INT16_C(   428),  INT16_C(    62),  INT16_C(   481), -INT16_C(   315) },
      { -INT16_C(    27),  INT16_C(     3),  INT16_C(    30), -INT16_C(    20) },
      { -INT16_C(     4),  INT16_C(     0),  INT16_C(     3), -INT16_C(     3) },
      { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C( 14789), -INT16_C( 31085), -INT16_C( 20044), -INT16_C( 21720) },
      { -INT16_C(  1849), -INT16_C(  3886), -INT16_C(  2506), -INT16_C(  2715) },
      { -INT16_C(   232), -INT16_C(   486), -INT16_C(   314), -INT16_C(   340) },
      { -INT16_C(    15), -INT16_C(    31), -INT16_C(    20), -INT16_C(    22) },
      { -INT16_C(     2), -INT16_C(     4), -INT16_C(     3), -INT16_C(     3) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);

    simde_int16x4_t r3 = simde_vshr_n_s16(a, 3);
    simde_int16x4_t r6 = simde_vshr_n_s16(a, 6);
    simde_int16x4_t r10 = simde_vshr_n_s16(a, 10);
    simde_int16x4_t r13 = simde_vshr_n_s16(a, 13);
    simde_int16x4_t r16 = simde_vshr_n_s16(a, 16);

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r16, simde_vld1_s16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vshr_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec[] = {
    { {  INT32_C(  1708457718), -INT32_C(  2095866327) },
      {  INT32_C(    26694651), -INT32_C(    32747912) },
      {  INT32_C(      208551), -INT32_C(      255844) },
      {  INT32_C(        3258), -INT32_C(        3998) },
      {  INT32_C(          25), -INT32_C(          32) },
      {  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(   614449246), -INT32_C(  1580529702) },
      { -INT32_C(     9600770), -INT32_C(    24695777) },
      { -INT32_C(       75007), -INT32_C(      192936) },
      { -INT32_C(        1172), -INT32_C(        3015) },
      { -INT32_C(          10), -INT32_C(          24) },
      { -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1039885425), -INT32_C(   887448430) },
      {  INT32_C(    16248209), -INT32_C(    13866382) },
      {  INT32_C(      126939), -INT32_C(      108332) },
      {  INT32_C(        1983), -INT32_C(        1693) },
      {  INT32_C(          15), -INT32_C(          14) },
      {  INT32_C(           0), -INT32_C(           1) } },
    { {  INT32_C(  1148170012),  INT32_C(  1346167130) },
      {  INT32_C(    17940156),  INT32_C(    21033861) },
      {  INT32_C(      140157),  INT32_C(      164327) },
      {  INT32_C(        2189),  INT32_C(        2567) },
      {  INT32_C(          17),  INT32_C(          20) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   162926816),  INT32_C(  1351403950) },
      {  INT32_C(     2545731),  INT32_C(    21115686) },
      {  INT32_C(       19888),  INT32_C(      164966) },
      {  INT32_C(         310),  INT32_C(        2577) },
      {  INT32_C(           2),  INT32_C(          20) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   500438008),  INT32_C(  1686370035) },
      { -INT32_C(     7819344),  INT32_C(    26349531) },
      { -INT32_C(       61089),  INT32_C(      205855) },
      { -INT32_C(         955),  INT32_C(        3216) },
      { -INT32_C(           8),  INT32_C(          25) },
      { -INT32_C(           1),  INT32_C(           0) } },
    { { -INT32_C(   308117925),  INT32_C(   934919195) },
      { -INT32_C(     4814343),  INT32_C(    14608112) },
      { -INT32_C(       37613),  INT32_C(      114125) },
      { -INT32_C(         588),  INT32_C(        1783) },
      { -INT32_C(           5),  INT32_C(          13) },
      { -INT32_C(           1),  INT32_C(           0) } },
    { { -INT32_C(   964941717), -INT32_C(   384387063) },
      { -INT32_C(    15077215), -INT32_C(     6006048) },
      { -INT32_C(      117791), -INT32_C(       46923) },
      { -INT32_C(        1841), -INT32_C(         734) },
      { -INT32_C(          15), -INT32_C(           6) },
      { -INT32_C(           1), -INT32_C(           1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);

    simde_int32x2_t r6 = simde_vshr_n_s32(a, 6);
    simde_int32x2_t r13 = simde_vshr_n_s32(a, 13);
    simde_int32x2_t r19 = simde_vshr_n_s32(a, 19);
    simde_int32x2_t r26 = simde_vshr_n_s32(a, 26);
    simde_int32x2_t r32 = simde_vshr_n_s32(a, 32);

    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r32, simde_vld1_s32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vshr_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    int64_t r13[1];
    int64_t r26[1];
    int64_t r39[1];
    int64_t r52[1];
    int64_t r64[1];
  } test_vec[] = {
    { { -INT64_C( 3995365984096218581) },
      { -INT64_C(     487715574230496) },
      { -INT64_C(         59535592558) },
      { -INT64_C(             7267529) },
      { -INT64_C(                 888) },
      { -INT64_C(                   1) } },
    { {  INT64_C( 1985728392210632478) },
      {  INT64_C(     242398485377274) },
      {  INT64_C(         29589658859) },
      {  INT64_C(             3612018) },
      {  INT64_C(                 440) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 1822468078428861345) },
      {  INT64_C(     222469247855085) },
      {  INT64_C(         27156890607) },
      {  INT64_C(             3315050) },
      {  INT64_C(                 404) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 3171718320008749032) },
      {  INT64_C(     387172646485442) },
      {  INT64_C(         47262285947) },
      {  INT64_C(             5769322) },
      {  INT64_C(                 704) },
      {  INT64_C(                   0) } },
    { {  INT64_C(  206608010581592391) },
      {  INT64_C(      25220704416698) },
      {  INT64_C(          3078699269) },
      {  INT64_C(              375817) },
      {  INT64_C(                  45) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 6405032054101179732) },
      {  INT64_C(     781864264416647) },
      {  INT64_C(         95442415089) },
      {  INT64_C(            11650685) },
      {  INT64_C(                1422) },
      {  INT64_C(                   0) } },
    { { -INT64_C( 4748376384868048655) },
      { -INT64_C(     579635789168463) },
      { -INT64_C(         70756321920) },
      { -INT64_C(             8637247) },
      { -INT64_C(                1055) },
      { -INT64_C(                   1) } },
    { {  INT64_C( 5759454149627204287) },
      {  INT64_C(     703058367874414) },
      {  INT64_C(         85822554672) },
      {  INT64_C(            10476386) },
      {  INT64_C(                1278) },
      {  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);

    simde_int64x1_t r13 = simde_vshr_n_s64(a, 13);
    simde_int64x1_t r26 = simde_vshr_n_s64(a, 26);
    simde_int64x1_t r39 = simde_vshr_n_s64(a, 39);
    simde_int64x1_t r52 = simde_vshr_n_s64(a, 52);
    simde_int64x1_t r64 = simde_vshr_n_s64(a, 64);

    simde_test_arm_neon_assert_equal_i64x1(r13, simde_vld1_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x1(r26, simde_vld1_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x1(r39, simde_vld1_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x1(r52, simde_vld1_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x1(r64, simde_vld1_s64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vshr_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec[] = {
    { { UINT8_C( 81), UINT8_C(224), UINT8_C( 99), UINT8_C(157), UINT8_C(155), UINT8_C( 57), UINT8_C(165), UINT8_C(241) },
      { UINT8_C( 40), UINT8_C(112), UINT8_C( 49), UINT8_C( 78), UINT8_C( 77), UINT8_C( 28), UINT8_C( 82), UINT8_C(120) },
      { UINT8_C( 10), UINT8_C( 28), UINT8_C( 12), UINT8_C( 19), UINT8_C( 19), UINT8_C(  7), UINT8_C( 20), UINT8_C( 30) },
      { UINT8_C(  2), UINT8_C(  7), UINT8_C(  3), UINT8_C(  4), UINT8_C(  4), UINT8_C(  1), UINT8_C(  5), UINT8_C(  7) },
      { UINT8_C(  1), UINT8_C(  3), UINT8_C(  1), UINT8_C(  2), UINT8_C(  2), UINT8_C(  0), UINT8_C(  2), UINT8_C(  3) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(206), UINT8_C( 99), UINT8_C(157), UINT8_C(  5), UINT8_C( 72), UINT8_C(119), UINT8_C(134), UINT8_C( 48) },
      { UINT8_C(103), UINT8_C( 49), UINT8_C( 78), UINT8_C(  2), UINT8_C( 36), UINT8_C( 59), UINT8_C( 67), UINT8_C( 24) },
      { UINT8_C( 25), UINT8_C( 12), UINT8_C( 19), UINT8_C(  0), UINT8_C(  9), UINT8_C( 14), UINT8_C( 16), UINT8_C(  6) },
      { UINT8_C(  6), UINT8_C(  3), UINT8_C(  4), UINT8_C(  0), UINT8_C(  2), UINT8_C(  3), UINT8_C(  4), UINT8_C(  1) },
      { UINT8_C(  3), UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  2), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(191), UINT8_C(148), UINT8_C(238), UINT8_C(173), UINT8_C(114), UINT8_C(252), UINT8_C( 44), UINT8_C( 59) },
      { UINT8_C( 95), UINT8_C( 74), UINT8_C(119), UINT8_C( 86), UINT8_C( 57), UINT8_C(126), UINT8_C( 22), UINT8_C( 29) },
      { UINT8_C( 23), UINT8_C( 18), UINT8_C( 29), UINT8_C( 21), UINT8_C( 14), UINT8_C( 31), UINT8_C(  5), UINT8_C(  7) },
      { UINT8_C(  5), UINT8_C(  4), UINT8_C(  7), UINT8_C(  5), UINT8_C(  3), UINT8_C(  7), UINT8_C(  1), UINT8_C(  1) },
      { UINT8_C(  2), UINT8_C(  2), UINT8_C(  3), UINT8_C(  2), UINT8_C(  1), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 56), UINT8_C(111), UINT8_C(144), UINT8_C(208), UINT8_C( 21), UINT8_C(102), UINT8_C(139), UINT8_C(102) },
      { UINT8_C( 28), UINT8_C( 55), UINT8_C( 72), UINT8_C(104), UINT8_C( 10), UINT8_C( 51), UINT8_C( 69), UINT8_C( 51) },
      { UINT8_C(  7), UINT8_C( 13), UINT8_C( 18), UINT8_C( 26), UINT8_C(  2), UINT8_C( 12), UINT8_C( 17), UINT8_C( 12) },
      { UINT8_C(  1), UINT8_C(  3), UINT8_C(  4), UINT8_C(  6), UINT8_C(  0), UINT8_C(  3), UINT8_C(  4), UINT8_C(  3) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  2), UINT8_C(  3), UINT8_C(  0), UINT8_C(  1), UINT8_C(  2), UINT8_C(  1) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 70), UINT8_C(238), UINT8_C(  3), UINT8_C(225), UINT8_C( 39), UINT8_C(168), UINT8_C(211), UINT8_C(245) },
      { UINT8_C( 35), UINT8_C(119), UINT8_C(  1), UINT8_C(112), UINT8_C( 19), UINT8_C( 84), UINT8_C(105), UINT8_C(122) },
      { UINT8_C(  8), UINT8_C( 29), UINT8_C(  0), UINT8_C( 28), UINT8_C(  4), UINT8_C( 21), UINT8_C( 26), UINT8_C( 30) },
      { UINT8_C(  2), UINT8_C(  7), UINT8_C(  0), UINT8_C(  7), UINT8_C(  1), UINT8_C(  5), UINT8_C(  6), UINT8_C(  7) },
      { UINT8_C(  1), UINT8_C(  3), UINT8_C(  0), UINT8_C(  3), UINT8_C(  0), UINT8_C(  2), UINT8_C(  3), UINT8_C(  3) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 11), UINT8_C(112), UINT8_C(251), UINT8_C( 83), UINT8_C(231), UINT8_C(129), UINT8_C(131), UINT8_C(167) },
      { UINT8_C(  5), UINT8_C( 56), UINT8_C(125), UINT8_C( 41), UINT8_C(115), UINT8_C( 64), UINT8_C( 65), UINT8_C( 83) },
      { UINT8_C(  1), UINT8_C( 14), UINT8_C( 31), UINT8_C( 10), UINT8_C( 28), UINT8_C( 16), UINT8_C( 16), UINT8_C( 20) },
      { UINT8_C(  0), UINT8_C(  3), UINT8_C(  7), UINT8_C(  2), UINT8_C(  7), UINT8_C(  4), UINT8_C(  4), UINT8_C(  5) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  3), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2), UINT8_C(  2), UINT8_C(  2) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 21), UINT8_C(114), UINT8_C( 84), UINT8_C(135), UINT8_C(110), UINT8_C(128), UINT8_C(195), UINT8_C(166) },
      { UINT8_C( 10), UINT8_C( 57), UINT8_C( 42), UINT8_C( 67), UINT8_C( 55), UINT8_C( 64), UINT8_C( 97), UINT8_C( 83) },
      { UINT8_C(  2), UINT8_C( 14), UINT8_C( 10), UINT8_C( 16), UINT8_C( 13), UINT8_C( 16), UINT8_C( 24), UINT8_C( 20) },
      { UINT8_C(  0), UINT8_C(  3), UINT8_C(  2), UINT8_C(  4), UINT8_C(  3), UINT8_C(  4), UINT8_C(  6), UINT8_C(  5) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  2), UINT8_C(  1), UINT8_C(  2), UINT8_C(  3), UINT8_C(  2) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(240), UINT8_C( 83), UINT8_C(119), UINT8_C(  5), UINT8_C(185), UINT8_C(  2), UINT8_C(107),    UINT8_MAX },
      { UINT8_C(120), UINT8_C( 41), UINT8_C( 59), UINT8_C(  2), UINT8_C( 92), UINT8_C(  1), UINT8_C( 53), UINT8_C(127) },
      { UINT8_C( 30), UINT8_C( 10), UINT8_C( 14), UINT8_C(  0), UINT8_C( 23), UINT8_C(  0), UINT8_C( 13), UINT8_C( 31) },
      { UINT8_C(  7), UINT8_C(  2), UINT8_C(  3), UINT8_C(  0), UINT8_C(  5), UINT8_C(  0), UINT8_C(  3), UINT8_C(  7) },
      { UINT8_C(  3), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(  1), UINT8_C(  3) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);

    simde_uint8x8_t r1 = simde_vshr_n_u8(a, 1);
    simde_uint8x8_t r3 = simde_vshr_n_u8(a, 3);
    simde_uint8x8_t r5 = simde_vshr_n_u8(a, 5);
    simde_uint8x8_t r6 = simde_vshr_n_u8(a, 6);
    simde_uint8x8_t r8 = simde_vshr_n_u8(a, 8);

    simde_test_arm_neon_assert_equal_u8x8(r1, simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r6, simde_vld1_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x8(r8, simde_vld1_u8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vshr_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { UINT16_C(18082), UINT16_C(57692), UINT16_C(41793), UINT16_C(56495) },
      { UINT16_C( 2260), UINT16_C( 7211), UINT16_C( 5224), UINT16_C( 7061) },
      { UINT16_C(  282), UINT16_C(  901), UINT16_C(  653), UINT16_C(  882) },
      { UINT16_C(   17), UINT16_C(   56), UINT16_C(   40), UINT16_C(   55) },
      { UINT16_C(    2), UINT16_C(    7), UINT16_C(    5), UINT16_C(    6) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 8780), UINT16_C(52988), UINT16_C(13539), UINT16_C(19184) },
      { UINT16_C( 1097), UINT16_C( 6623), UINT16_C( 1692), UINT16_C( 2398) },
      { UINT16_C(  137), UINT16_C(  827), UINT16_C(  211), UINT16_C(  299) },
      { UINT16_C(    8), UINT16_C(   51), UINT16_C(   13), UINT16_C(   18) },
      { UINT16_C(    1), UINT16_C(    6), UINT16_C(    1), UINT16_C(    2) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(63422), UINT16_C(13365), UINT16_C(41288), UINT16_C(19151) },
      { UINT16_C( 7927), UINT16_C( 1670), UINT16_C( 5161), UINT16_C( 2393) },
      { UINT16_C(  990), UINT16_C(  208), UINT16_C(  645), UINT16_C(  299) },
      { UINT16_C(   61), UINT16_C(   13), UINT16_C(   40), UINT16_C(   18) },
      { UINT16_C(    7), UINT16_C(    1), UINT16_C(    5), UINT16_C(    2) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(52253), UINT16_C( 3308), UINT16_C(26061), UINT16_C(28915) },
      { UINT16_C( 6531), UINT16_C(  413), UINT16_C( 3257), UINT16_C( 3614) },
      { UINT16_C(  816), UINT16_C(   51), UINT16_C(  407), UINT16_C(  451) },
      { UINT16_C(   51), UINT16_C(    3), UINT16_C(   25), UINT16_C(   28) },
      { UINT16_C(    6), UINT16_C(    0), UINT16_C(    3), UINT16_C(    3) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(20395), UINT16_C(60753), UINT16_C(  242), UINT16_C(16329) },
      { UINT16_C( 2549), UINT16_C( 7594), UINT16_C(   30), UINT16_C( 2041) },
      { UINT16_C(  318), UINT16_C(  949), UINT16_C(    3), UINT16_C(  255) },
      { UINT16_C(   19), UINT16_C(   59), UINT16_C(    0), UINT16_C(   15) },
      { UINT16_C(    2), UINT16_C(    7), UINT16_C(    0), UINT16_C(    1) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(50722), UINT16_C( 1293), UINT16_C(65018), UINT16_C(47184) },
      { UINT16_C( 6340), UINT16_C(  161), UINT16_C( 8127), UINT16_C( 5898) },
      { UINT16_C(  792), UINT16_C(   20), UINT16_C( 1015), UINT16_C(  737) },
      { UINT16_C(   49), UINT16_C(    1), UINT16_C(   63), UINT16_C(   46) },
      { UINT16_C(    6), UINT16_C(    0), UINT16_C(    7), UINT16_C(    5) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(34292), UINT16_C(15596), UINT16_C(47910), UINT16_C(17286) },
      { UINT16_C( 4286), UINT16_C( 1949), UINT16_C( 5988), UINT16_C( 2160) },
      { UINT16_C(  535), UINT16_C(  243), UINT16_C(  748), UINT16_C(  270) },
      { UINT16_C(   33), UINT16_C(   15), UINT16_C(   46), UINT16_C(   16) },
      { UINT16_C(    4), UINT16_C(    1), UINT16_C(    5), UINT16_C(    2) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(29575), UINT16_C(21839), UINT16_C(17112), UINT16_C(33989) },
      { UINT16_C( 3696), UINT16_C( 2729), UINT16_C( 2139), UINT16_C( 4248) },
      { UINT16_C(  462), UINT16_C(  341), UINT16_C(  267), UINT16_C(  531) },
      { UINT16_C(   28), UINT16_C(   21), UINT16_C(   16), UINT16_C(   33) },
      { UINT16_C(    3), UINT16_C(    2), UINT16_C(    2), UINT16_C(    4) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);

    simde_uint16x4_t r3 = simde_vshr_n_u16(a, 3);
    simde_uint16x4_t r6 = simde_vshr_n_u16(a, 6);
    simde_uint16x4_t r10 = simde_vshr_n_u16(a, 10);
    simde_uint16x4_t r13 = simde_vshr_n_u16(a, 13);
    simde_uint16x4_t r16 = simde_vshr_n_u16(a, 16);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r16, simde_vld1_u16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vshr_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { UINT32_C( 696026497), UINT32_C(3975571712) },
      { UINT32_C(  10875414), UINT32_C(  62118308) },
      { UINT32_C(     84964), UINT32_C(    485299) },
      { UINT32_C(      1327), UINT32_C(      7582) },
      { UINT32_C(        10), UINT32_C(        59) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2582254795), UINT32_C(3772650691) },
      { UINT32_C(  40347731), UINT32_C(  58947667) },
      { UINT32_C(    315216), UINT32_C(    460528) },
      { UINT32_C(      4925), UINT32_C(      7195) },
      { UINT32_C(        38), UINT32_C(        56) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 283642668), UINT32_C(2746048542) },
      { UINT32_C(   4431916), UINT32_C(  42907008) },
      { UINT32_C(     34624), UINT32_C(    335211) },
      { UINT32_C(       541), UINT32_C(      5237) },
      { UINT32_C(         4), UINT32_C(        40) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 505097202), UINT32_C(2508049172) },
      { UINT32_C(   7892143), UINT32_C(  39188268) },
      { UINT32_C(     61657), UINT32_C(    306158) },
      { UINT32_C(       963), UINT32_C(      4783) },
      { UINT32_C(         7), UINT32_C(        37) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1354692944), UINT32_C( 775795811) },
      { UINT32_C(  21167077), UINT32_C(  12121809) },
      { UINT32_C(    165367), UINT32_C(     94701) },
      { UINT32_C(      2583), UINT32_C(      1479) },
      { UINT32_C(        20), UINT32_C(        11) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2345084872), UINT32_C(1735173691) },
      { UINT32_C(  36641951), UINT32_C(  27112088) },
      { UINT32_C(    286265), UINT32_C(    211813) },
      { UINT32_C(      4472), UINT32_C(      3309) },
      { UINT32_C(        34), UINT32_C(        25) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3497481393), UINT32_C(2809341108) },
      { UINT32_C(  54648146), UINT32_C(  43895954) },
      { UINT32_C(    426938), UINT32_C(    342937) },
      { UINT32_C(      6670), UINT32_C(      5358) },
      { UINT32_C(        52), UINT32_C(        41) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1673891407), UINT32_C(2851619417) },
      { UINT32_C(  26154553), UINT32_C(  44556553) },
      { UINT32_C(    204332), UINT32_C(    348098) },
      { UINT32_C(      3192), UINT32_C(      5439) },
      { UINT32_C(        24), UINT32_C(        42) },
      { UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);

    simde_uint32x2_t r6 = simde_vshr_n_u32(a, 6);
    simde_uint32x2_t r13 = simde_vshr_n_u32(a, 13);
    simde_uint32x2_t r19 = simde_vshr_n_u32(a, 19);
    simde_uint32x2_t r26 = simde_vshr_n_u32(a, 26);
    simde_uint32x2_t r32 = simde_vshr_n_u32(a, 32);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r32, simde_vld1_u32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vshr_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t r13[1];
    uint64_t r26[1];
    uint64_t r39[1];
    uint64_t r52[1];
    uint64_t r64[1];
  } test_vec[] = {
    { { UINT64_C(17160806007911097636) },
      { UINT64_C(    2094824952137585) },
      { UINT64_C(        255715936540) },
      { UINT64_C(            31215324) },
      { UINT64_C(                3810) },
      { UINT64_C(                   0) } },
    { { UINT64_C(13009184620787666765) },
      { UINT64_C(    1588035232029744) },
      { UINT64_C(        193851957034) },
      { UINT64_C(            23663568) },
      { UINT64_C(                2888) },
      { UINT64_C(                   0) } },
    { { UINT64_C(16411739272322698297) },
      { UINT64_C(    2003386141640954) },
      { UINT64_C(        244553972368) },
      { UINT64_C(            29852779) },
      { UINT64_C(                3644) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 3898171221045080521) },
      { UINT64_C(     475850979131479) },
      { UINT64_C(         58087277726) },
      { UINT64_C(             7090732) },
      { UINT64_C(                 865) },
      { UINT64_C(                   0) } },
    { { UINT64_C(14073411793873930043) },
      { UINT64_C(    1717945775619376) },
      { UINT64_C(        209710177687) },
      { UINT64_C(            25599386) },
      { UINT64_C(                3124) },
      { UINT64_C(                   0) } },
    { { UINT64_C(17658043201827558621) },
      { UINT64_C(    2155522851785590) },
      { UINT64_C(        263125348118) },
      { UINT64_C(            32119793) },
      { UINT64_C(                3920) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 3103817293289106500) },
      { UINT64_C(     378883946934705) },
      { UINT64_C(         46250481803) },
      { UINT64_C(             5645810) },
      { UINT64_C(                 689) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 7940616020180540650) },
      { UINT64_C(     969313479025944) },
      { UINT64_C(        118324399295) },
      { UINT64_C(            14443896) },
      { UINT64_C(                1763) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);

    simde_uint64x1_t r13 = simde_vshr_n_u64(a, 13);
    simde_uint64x1_t r26 = simde_vshr_n_u64(a, 26);
    simde_uint64x1_t r39 = simde_vshr_n_u64(a, 39);
    simde_uint64x1_t r52 = simde_vshr_n_u64(a, 52);
    simde_uint64x1_t r64 = simde_vshr_n_u64(a, 64);

    simde_test_arm_neon_assert_equal_u64x1(r13, simde_vld1_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x1(r26, simde_vld1_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x1(r39, simde_vld1_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x1(r52, simde_vld1_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x1(r64, simde_vld1_u64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vshrq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r8[16];
  } test_vec[] = {
    { { -INT8_C(  72), -INT8_C(  70),  INT8_C( 111),  INT8_C(  46), -INT8_C( 126), -INT8_C(  55),  INT8_C(   9), -INT8_C(   8),
        -INT8_C( 118),  INT8_C(  77), -INT8_C(  85),  INT8_C(  57), -INT8_C(  77),  INT8_C(  54), -INT8_C(  40), -INT8_C(  61) },
      { -INT8_C(  36), -INT8_C(  35),  INT8_C(  55),  INT8_C(  23), -INT8_C(  63), -INT8_C(  28),  INT8_C(   4), -INT8_C(   4),
        -INT8_C(  59),  INT8_C(  38), -INT8_C(  43),  INT8_C(  28), -INT8_C(  39),  INT8_C(  27), -INT8_C(  20), -INT8_C(  31) },
      { -INT8_C(   9), -INT8_C(   9),  INT8_C(  13),  INT8_C(   5), -INT8_C(  16), -INT8_C(   7),  INT8_C(   1), -INT8_C(   1),
        -INT8_C(  15),  INT8_C(   9), -INT8_C(  11),  INT8_C(   7), -INT8_C(  10),  INT8_C(   6), -INT8_C(   5), -INT8_C(   8) },
      { -INT8_C(   3), -INT8_C(   3),  INT8_C(   3),  INT8_C(   1), -INT8_C(   4), -INT8_C(   2),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   4),  INT8_C(   2), -INT8_C(   3),  INT8_C(   1), -INT8_C(   3),  INT8_C(   1), -INT8_C(   2), -INT8_C(   2) },
      { -INT8_C(   2), -INT8_C(   2),  INT8_C(   1),  INT8_C(   0), -INT8_C(   2), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   2),  INT8_C(   1), -INT8_C(   2),  INT8_C(   0), -INT8_C(   2),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  31),  INT8_C(  20), -INT8_C(  87),  INT8_C(  65),  INT8_C( 111),  INT8_C(  32),  INT8_C( 124), -INT8_C(  48),
        -INT8_C(  20),  INT8_C(  13),  INT8_C(  53), -INT8_C( 120), -INT8_C(  14),  INT8_C(  11),  INT8_C(   9), -INT8_C(  86) },
      {  INT8_C(  15),  INT8_C(  10), -INT8_C(  44),  INT8_C(  32),  INT8_C(  55),  INT8_C(  16),  INT8_C(  62), -INT8_C(  24),
        -INT8_C(  10),  INT8_C(   6),  INT8_C(  26), -INT8_C(  60), -INT8_C(   7),  INT8_C(   5),  INT8_C(   4), -INT8_C(  43) },
      {  INT8_C(   3),  INT8_C(   2), -INT8_C(  11),  INT8_C(   8),  INT8_C(  13),  INT8_C(   4),  INT8_C(  15), -INT8_C(   6),
        -INT8_C(   3),  INT8_C(   1),  INT8_C(   6), -INT8_C(  15), -INT8_C(   2),  INT8_C(   1),  INT8_C(   1), -INT8_C(  11) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   1),  INT8_C(   3), -INT8_C(   2),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   1), -INT8_C(   4), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   3) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   2),  INT8_C(   1),  INT8_C(   1),  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   2), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   2) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) } },
    { { -INT8_C(  59),  INT8_C( 120), -INT8_C(  40),  INT8_C(  72),  INT8_C(  65), -INT8_C(  30),  INT8_C(  64), -INT8_C(  53),
         INT8_C(  47), -INT8_C(  20),  INT8_C(   4), -INT8_C(  30),  INT8_C(  34), -INT8_C(  36), -INT8_C(  91),  INT8_C(  65) },
      { -INT8_C(  30),  INT8_C(  60), -INT8_C(  20),  INT8_C(  36),  INT8_C(  32), -INT8_C(  15),  INT8_C(  32), -INT8_C(  27),
         INT8_C(  23), -INT8_C(  10),  INT8_C(   2), -INT8_C(  15),  INT8_C(  17), -INT8_C(  18), -INT8_C(  46),  INT8_C(  32) },
      { -INT8_C(   8),  INT8_C(  15), -INT8_C(   5),  INT8_C(   9),  INT8_C(   8), -INT8_C(   4),  INT8_C(   8), -INT8_C(   7),
         INT8_C(   5), -INT8_C(   3),  INT8_C(   0), -INT8_C(   4),  INT8_C(   4), -INT8_C(   5), -INT8_C(  12),  INT8_C(   8) },
      { -INT8_C(   2),  INT8_C(   3), -INT8_C(   2),  INT8_C(   2),  INT8_C(   2), -INT8_C(   1),  INT8_C(   2), -INT8_C(   2),
         INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   1), -INT8_C(   2), -INT8_C(   3),  INT8_C(   2) },
      { -INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   2),  INT8_C(   1) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C(  16),  INT8_C(  78), -INT8_C( 126),  INT8_C(  95),  INT8_C( 111), -INT8_C(   1),  INT8_C(  47),  INT8_C(  91),
         INT8_C(  12),  INT8_C( 100), -INT8_C(  28), -INT8_C(   2),  INT8_C( 112), -INT8_C(  19), -INT8_C(  87),  INT8_C(  53) },
      { -INT8_C(   8),  INT8_C(  39), -INT8_C(  63),  INT8_C(  47),  INT8_C(  55), -INT8_C(   1),  INT8_C(  23),  INT8_C(  45),
         INT8_C(   6),  INT8_C(  50), -INT8_C(  14), -INT8_C(   1),  INT8_C(  56), -INT8_C(  10), -INT8_C(  44),  INT8_C(  26) },
      { -INT8_C(   2),  INT8_C(   9), -INT8_C(  16),  INT8_C(  11),  INT8_C(  13), -INT8_C(   1),  INT8_C(   5),  INT8_C(  11),
         INT8_C(   1),  INT8_C(  12), -INT8_C(   4), -INT8_C(   1),  INT8_C(  14), -INT8_C(   3), -INT8_C(  11),  INT8_C(   6) },
      { -INT8_C(   1),  INT8_C(   2), -INT8_C(   4),  INT8_C(   2),  INT8_C(   3), -INT8_C(   1),  INT8_C(   1),  INT8_C(   2),
         INT8_C(   0),  INT8_C(   3), -INT8_C(   1), -INT8_C(   1),  INT8_C(   3), -INT8_C(   1), -INT8_C(   3),  INT8_C(   1) },
      { -INT8_C(   1),  INT8_C(   1), -INT8_C(   2),  INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   1),
         INT8_C(   0),  INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   1), -INT8_C(   1), -INT8_C(   2),  INT8_C(   0) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C( 101), -INT8_C( 127),  INT8_C( 125), -INT8_C(  90),  INT8_C(  99), -INT8_C(  66),  INT8_C( 113), -INT8_C( 110),
        -INT8_C(  86),  INT8_C( 117),  INT8_C( 116), -INT8_C(  52),  INT8_C(  82),  INT8_C(  25),  INT8_C(  13),  INT8_C(  66) },
      {  INT8_C(  50), -INT8_C(  64),  INT8_C(  62), -INT8_C(  45),  INT8_C(  49), -INT8_C(  33),  INT8_C(  56), -INT8_C(  55),
        -INT8_C(  43),  INT8_C(  58),  INT8_C(  58), -INT8_C(  26),  INT8_C(  41),  INT8_C(  12),  INT8_C(   6),  INT8_C(  33) },
      {  INT8_C(  12), -INT8_C(  16),  INT8_C(  15), -INT8_C(  12),  INT8_C(  12), -INT8_C(   9),  INT8_C(  14), -INT8_C(  14),
        -INT8_C(  11),  INT8_C(  14),  INT8_C(  14), -INT8_C(   7),  INT8_C(  10),  INT8_C(   3),  INT8_C(   1),  INT8_C(   8) },
      {  INT8_C(   3), -INT8_C(   4),  INT8_C(   3), -INT8_C(   3),  INT8_C(   3), -INT8_C(   3),  INT8_C(   3), -INT8_C(   4),
        -INT8_C(   3),  INT8_C(   3),  INT8_C(   3), -INT8_C(   2),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2) },
      {  INT8_C(   1), -INT8_C(   2),  INT8_C(   1), -INT8_C(   2),  INT8_C(   1), -INT8_C(   2),  INT8_C(   1), -INT8_C(   2),
        -INT8_C(   2),  INT8_C(   1),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1) },
      {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 104), -INT8_C( 112), -INT8_C(  94), -INT8_C(  41), -INT8_C( 113), -INT8_C(  47),  INT8_C(  50), -INT8_C( 101),
         INT8_C(  54),  INT8_C(  22), -INT8_C( 103), -INT8_C(  90),  INT8_C(   3),  INT8_C(  66), -INT8_C(  37),  INT8_C( 104) },
      {  INT8_C(  52), -INT8_C(  56), -INT8_C(  47), -INT8_C(  21), -INT8_C(  57), -INT8_C(  24),  INT8_C(  25), -INT8_C(  51),
         INT8_C(  27),  INT8_C(  11), -INT8_C(  52), -INT8_C(  45),  INT8_C(   1),  INT8_C(  33), -INT8_C(  19),  INT8_C(  52) },
      {  INT8_C(  13), -INT8_C(  14), -INT8_C(  12), -INT8_C(   6), -INT8_C(  15), -INT8_C(   6),  INT8_C(   6), -INT8_C(  13),
         INT8_C(   6),  INT8_C(   2), -INT8_C(  13), -INT8_C(  12),  INT8_C(   0),  INT8_C(   8), -INT8_C(   5),  INT8_C(  13) },
      {  INT8_C(   3), -INT8_C(   4), -INT8_C(   3), -INT8_C(   2), -INT8_C(   4), -INT8_C(   2),  INT8_C(   1), -INT8_C(   4),
         INT8_C(   1),  INT8_C(   0), -INT8_C(   4), -INT8_C(   3),  INT8_C(   0),  INT8_C(   2), -INT8_C(   2),  INT8_C(   3) },
      {  INT8_C(   1), -INT8_C(   2), -INT8_C(   2), -INT8_C(   1), -INT8_C(   2), -INT8_C(   1),  INT8_C(   0), -INT8_C(   2),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   2), -INT8_C(   2),  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(   1) },
      {  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { { -INT8_C(  60),  INT8_C(  89),  INT8_C(  14),  INT8_C(  39),  INT8_C(  23),      INT8_MAX, -INT8_C(  70), -INT8_C(  63),
        -INT8_C(  11),  INT8_C(  46), -INT8_C( 115),  INT8_C(  71),  INT8_C(  72), -INT8_C( 102), -INT8_C( 119), -INT8_C(  80) },
      { -INT8_C(  30),  INT8_C(  44),  INT8_C(   7),  INT8_C(  19),  INT8_C(  11),  INT8_C(  63), -INT8_C(  35), -INT8_C(  32),
        -INT8_C(   6),  INT8_C(  23), -INT8_C(  58),  INT8_C(  35),  INT8_C(  36), -INT8_C(  51), -INT8_C(  60), -INT8_C(  40) },
      { -INT8_C(   8),  INT8_C(  11),  INT8_C(   1),  INT8_C(   4),  INT8_C(   2),  INT8_C(  15), -INT8_C(   9), -INT8_C(   8),
        -INT8_C(   2),  INT8_C(   5), -INT8_C(  15),  INT8_C(   8),  INT8_C(   9), -INT8_C(  13), -INT8_C(  15), -INT8_C(  10) },
      { -INT8_C(   2),  INT8_C(   2),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   3), -INT8_C(   3), -INT8_C(   2),
        -INT8_C(   1),  INT8_C(   1), -INT8_C(   4),  INT8_C(   2),  INT8_C(   2), -INT8_C(   4), -INT8_C(   4), -INT8_C(   3) },
      { -INT8_C(   1),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1), -INT8_C(   2), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   2),  INT8_C(   1),  INT8_C(   1), -INT8_C(   2), -INT8_C(   2), -INT8_C(   2) },
      { -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { {  INT8_C(  42),  INT8_C(  43), -INT8_C( 121), -INT8_C(  71), -INT8_C(   3), -INT8_C(  71),  INT8_C(  84),  INT8_C(  51),
        -INT8_C(  48), -INT8_C(  18), -INT8_C(  39), -INT8_C(  45),  INT8_C(  48), -INT8_C(  76),  INT8_C(  60), -INT8_C(  12) },
      {  INT8_C(  21),  INT8_C(  21), -INT8_C(  61), -INT8_C(  36), -INT8_C(   2), -INT8_C(  36),  INT8_C(  42),  INT8_C(  25),
        -INT8_C(  24), -INT8_C(   9), -INT8_C(  20), -INT8_C(  23),  INT8_C(  24), -INT8_C(  38),  INT8_C(  30), -INT8_C(   6) },
      {  INT8_C(   5),  INT8_C(   5), -INT8_C(  16), -INT8_C(   9), -INT8_C(   1), -INT8_C(   9),  INT8_C(  10),  INT8_C(   6),
        -INT8_C(   6), -INT8_C(   3), -INT8_C(   5), -INT8_C(   6),  INT8_C(   6), -INT8_C(  10),  INT8_C(   7), -INT8_C(   2) },
      {  INT8_C(   1),  INT8_C(   1), -INT8_C(   4), -INT8_C(   3), -INT8_C(   1), -INT8_C(   3),  INT8_C(   2),  INT8_C(   1),
        -INT8_C(   2), -INT8_C(   1), -INT8_C(   2), -INT8_C(   2),  INT8_C(   1), -INT8_C(   3),  INT8_C(   1), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   2), -INT8_C(   2), -INT8_C(   1), -INT8_C(   2),  INT8_C(   1),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   2),  INT8_C(   0), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);

    simde_int8x16_t r1 = simde_vshrq_n_s8(a, 1);
    simde_int8x16_t r3 = simde_vshrq_n_s8(a, 3);
    simde_int8x16_t r5 = simde_vshrq_n_s8(a, 5);
    simde_int8x16_t r6 = simde_vshrq_n_s8(a, 6);
    simde_int8x16_t r8 = simde_vshrq_n_s8(a, 8);

    simde_test_arm_neon_assert_equal_i8x16(r1, simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r6, simde_vld1q_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x16(r8, simde_vld1q_s8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vshrq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { { -INT16_C( 14981),  INT16_C( 10413), -INT16_C(  8036), -INT16_C( 13777),  INT16_C(  6499), -INT16_C( 22969),  INT16_C(  4904),  INT16_C(  5266) },
      { -INT16_C(  1873),  INT16_C(  1301), -INT16_C(  1005), -INT16_C(  1723),  INT16_C(   812), -INT16_C(  2872),  INT16_C(   613),  INT16_C(   658) },
      { -INT16_C(   235),  INT16_C(   162), -INT16_C(   126), -INT16_C(   216),  INT16_C(   101), -INT16_C(   359),  INT16_C(    76),  INT16_C(    82) },
      { -INT16_C(    15),  INT16_C(    10), -INT16_C(     8), -INT16_C(    14),  INT16_C(     6), -INT16_C(    23),  INT16_C(     4),  INT16_C(     5) },
      { -INT16_C(     2),  INT16_C(     1), -INT16_C(     1), -INT16_C(     2),  INT16_C(     0), -INT16_C(     3),  INT16_C(     0),  INT16_C(     0) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  9136), -INT16_C(  5468),  INT16_C( 31374), -INT16_C(   435), -INT16_C( 18326),  INT16_C(  7725),  INT16_C( 28282), -INT16_C(  2743) },
      {  INT16_C(  1142), -INT16_C(   684),  INT16_C(  3921), -INT16_C(    55), -INT16_C(  2291),  INT16_C(   965),  INT16_C(  3535), -INT16_C(   343) },
      {  INT16_C(   142), -INT16_C(    86),  INT16_C(   490), -INT16_C(     7), -INT16_C(   287),  INT16_C(   120),  INT16_C(   441), -INT16_C(    43) },
      {  INT16_C(     8), -INT16_C(     6),  INT16_C(    30), -INT16_C(     1), -INT16_C(    18),  INT16_C(     7),  INT16_C(    27), -INT16_C(     3) },
      {  INT16_C(     1), -INT16_C(     1),  INT16_C(     3), -INT16_C(     1), -INT16_C(     3),  INT16_C(     0),  INT16_C(     3), -INT16_C(     1) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C(  2253), -INT16_C( 12258),  INT16_C( 19927),  INT16_C( 15002), -INT16_C(  7833), -INT16_C( 28704),  INT16_C( 29684), -INT16_C( 23389) },
      { -INT16_C(   282), -INT16_C(  1533),  INT16_C(  2490),  INT16_C(  1875), -INT16_C(   980), -INT16_C(  3588),  INT16_C(  3710), -INT16_C(  2924) },
      { -INT16_C(    36), -INT16_C(   192),  INT16_C(   311),  INT16_C(   234), -INT16_C(   123), -INT16_C(   449),  INT16_C(   463), -INT16_C(   366) },
      { -INT16_C(     3), -INT16_C(    12),  INT16_C(    19),  INT16_C(    14), -INT16_C(     8), -INT16_C(    29),  INT16_C(    28), -INT16_C(    23) },
      { -INT16_C(     1), -INT16_C(     2),  INT16_C(     2),  INT16_C(     1), -INT16_C(     1), -INT16_C(     4),  INT16_C(     3), -INT16_C(     3) },
      { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) } },
    { {  INT16_C( 18326),  INT16_C(  9358), -INT16_C(  9278),  INT16_C( 11299),  INT16_C( 20627),  INT16_C(  3658), -INT16_C( 27458), -INT16_C(  3581) },
      {  INT16_C(  2290),  INT16_C(  1169), -INT16_C(  1160),  INT16_C(  1412),  INT16_C(  2578),  INT16_C(   457), -INT16_C(  3433), -INT16_C(   448) },
      {  INT16_C(   286),  INT16_C(   146), -INT16_C(   145),  INT16_C(   176),  INT16_C(   322),  INT16_C(    57), -INT16_C(   430), -INT16_C(    56) },
      {  INT16_C(    17),  INT16_C(     9), -INT16_C(    10),  INT16_C(    11),  INT16_C(    20),  INT16_C(     3), -INT16_C(    27), -INT16_C(     4) },
      {  INT16_C(     2),  INT16_C(     1), -INT16_C(     2),  INT16_C(     1),  INT16_C(     2),  INT16_C(     0), -INT16_C(     4), -INT16_C(     1) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1) } },
    { {  INT16_C(  8587),  INT16_C( 25282),  INT16_C( 23663), -INT16_C( 10595),  INT16_C( 32061),  INT16_C( 12901),  INT16_C(  2288), -INT16_C( 31018) },
      {  INT16_C(  1073),  INT16_C(  3160),  INT16_C(  2957), -INT16_C(  1325),  INT16_C(  4007),  INT16_C(  1612),  INT16_C(   286), -INT16_C(  3878) },
      {  INT16_C(   134),  INT16_C(   395),  INT16_C(   369), -INT16_C(   166),  INT16_C(   500),  INT16_C(   201),  INT16_C(    35), -INT16_C(   485) },
      {  INT16_C(     8),  INT16_C(    24),  INT16_C(    23), -INT16_C(    11),  INT16_C(    31),  INT16_C(    12),  INT16_C(     2), -INT16_C(    31) },
      {  INT16_C(     1),  INT16_C(     3),  INT16_C(     2), -INT16_C(     2),  INT16_C(     3),  INT16_C(     1),  INT16_C(     0), -INT16_C(     4) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) } },
    { {  INT16_C( 25935),  INT16_C(  4523), -INT16_C( 12736), -INT16_C( 11203), -INT16_C( 30690), -INT16_C(  8990), -INT16_C(  6884), -INT16_C( 22578) },
      {  INT16_C(  3241),  INT16_C(   565), -INT16_C(  1592), -INT16_C(  1401), -INT16_C(  3837), -INT16_C(  1124), -INT16_C(   861), -INT16_C(  2823) },
      {  INT16_C(   405),  INT16_C(    70), -INT16_C(   199), -INT16_C(   176), -INT16_C(   480), -INT16_C(   141), -INT16_C(   108), -INT16_C(   353) },
      {  INT16_C(    25),  INT16_C(     4), -INT16_C(    13), -INT16_C(    11), -INT16_C(    30), -INT16_C(     9), -INT16_C(     7), -INT16_C(    23) },
      {  INT16_C(     3),  INT16_C(     0), -INT16_C(     2), -INT16_C(     2), -INT16_C(     4), -INT16_C(     2), -INT16_C(     1), -INT16_C(     3) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) } },
    { { -INT16_C( 28665),  INT16_C( 30217), -INT16_C( 22804),  INT16_C( 10828), -INT16_C( 20188),  INT16_C(  5212),  INT16_C( 12985),  INT16_C(  2203) },
      { -INT16_C(  3584),  INT16_C(  3777), -INT16_C(  2851),  INT16_C(  1353), -INT16_C(  2524),  INT16_C(   651),  INT16_C(  1623),  INT16_C(   275) },
      { -INT16_C(   448),  INT16_C(   472), -INT16_C(   357),  INT16_C(   169), -INT16_C(   316),  INT16_C(    81),  INT16_C(   202),  INT16_C(    34) },
      { -INT16_C(    28),  INT16_C(    29), -INT16_C(    23),  INT16_C(    10), -INT16_C(    20),  INT16_C(     5),  INT16_C(    12),  INT16_C(     2) },
      { -INT16_C(     4),  INT16_C(     3), -INT16_C(     3),  INT16_C(     1), -INT16_C(     3),  INT16_C(     0),  INT16_C(     1),  INT16_C(     0) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 18071), -INT16_C( 10214),  INT16_C( 22292),  INT16_C( 12972), -INT16_C( 28961), -INT16_C(  1266), -INT16_C(  8845),  INT16_C( 31394) },
      {  INT16_C(  2258), -INT16_C(  1277),  INT16_C(  2786),  INT16_C(  1621), -INT16_C(  3621), -INT16_C(   159), -INT16_C(  1106),  INT16_C(  3924) },
      {  INT16_C(   282), -INT16_C(   160),  INT16_C(   348),  INT16_C(   202), -INT16_C(   453), -INT16_C(    20), -INT16_C(   139),  INT16_C(   490) },
      {  INT16_C(    17), -INT16_C(    10),  INT16_C(    21),  INT16_C(    12), -INT16_C(    29), -INT16_C(     2), -INT16_C(     9),  INT16_C(    30) },
      {  INT16_C(     2), -INT16_C(     2),  INT16_C(     2),  INT16_C(     1), -INT16_C(     4), -INT16_C(     1), -INT16_C(     2),  INT16_C(     3) },
      {  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_int16x8_t r3 = simde_vshrq_n_s16(a, 3);
    simde_int16x8_t r6 = simde_vshrq_n_s16(a, 6);
    simde_int16x8_t r10 = simde_vshrq_n_s16(a, 10);
    simde_int16x8_t r13 = simde_vshrq_n_s16(a, 13);
    simde_int16x8_t r16 = simde_vshrq_n_s16(a, 16);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r16, simde_vld1q_s16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vshrq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r32[4];
  } test_vec[] = {
    { {  INT32_C(   125514276),  INT32_C(  1669026353), -INT32_C(  1870822169),  INT32_C(  1046181581) },
      {  INT32_C(     1961160),  INT32_C(    26078536), -INT32_C(    29231597),  INT32_C(    16346587) },
      {  INT32_C(       15321),  INT32_C(      203738), -INT32_C(      228372),  INT32_C(      127707) },
      {  INT32_C(         239),  INT32_C(        3183), -INT32_C(        3569),  INT32_C(        1995) },
      {  INT32_C(           1),  INT32_C(          24), -INT32_C(          28),  INT32_C(          15) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
    { {  INT32_C(   123929250),  INT32_C(  1830231953), -INT32_C(  1397146087),  INT32_C(   193304550) },
      {  INT32_C(     1936394),  INT32_C(    28597374), -INT32_C(    21830408),  INT32_C(     3020383) },
      {  INT32_C(       15128),  INT32_C(      223416), -INT32_C(      170551),  INT32_C(       23596) },
      {  INT32_C(         236),  INT32_C(        3490), -INT32_C(        2665),  INT32_C(         368) },
      {  INT32_C(           1),  INT32_C(          27), -INT32_C(          21),  INT32_C(           2) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
    { { -INT32_C(    82705975),  INT32_C(   979275347), -INT32_C(   540353518), -INT32_C(   182639278) },
      { -INT32_C(     1292281),  INT32_C(    15301177), -INT32_C(     8443024), -INT32_C(     2853739) },
      { -INT32_C(       10096),  INT32_C(      119540), -INT32_C(       65962), -INT32_C(       22295) },
      { -INT32_C(         158),  INT32_C(        1867), -INT32_C(        1031), -INT32_C(         349) },
      { -INT32_C(           2),  INT32_C(          14), -INT32_C(           9), -INT32_C(           3) },
      { -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1) } },
    { { -INT32_C(  1174634200), -INT32_C(  1188621408),  INT32_C(   946200658),  INT32_C(  1078193015) },
      { -INT32_C(    18353660), -INT32_C(    18572210),  INT32_C(    14784385),  INT32_C(    16846765) },
      { -INT32_C(      143388), -INT32_C(      145096),  INT32_C(      115503),  INT32_C(      131615) },
      { -INT32_C(        2241), -INT32_C(        2268),  INT32_C(        1804),  INT32_C(        2056) },
      { -INT32_C(          18), -INT32_C(          18),  INT32_C(          14),  INT32_C(          16) },
      { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1060853484), -INT32_C(   159737116), -INT32_C(   925547402), -INT32_C(  1833045142) },
      {  INT32_C(    16575835), -INT32_C(     2495893), -INT32_C(    14461679), -INT32_C(    28641331) },
      {  INT32_C(      129498), -INT32_C(       19500), -INT32_C(      112982), -INT32_C(      223761) },
      {  INT32_C(        2023), -INT32_C(         305), -INT32_C(        1766), -INT32_C(        3497) },
      {  INT32_C(          15), -INT32_C(           3), -INT32_C(          14), -INT32_C(          28) },
      {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(   340506996),  INT32_C(   533623501), -INT32_C(   917032110),  INT32_C(   168467230) },
      {  INT32_C(     5320421),  INT32_C(     8337867), -INT32_C(    14328627),  INT32_C(     2632300) },
      {  INT32_C(       41565),  INT32_C(       65139), -INT32_C(      111943),  INT32_C(       20564) },
      {  INT32_C(         649),  INT32_C(        1017), -INT32_C(        1750),  INT32_C(         321) },
      {  INT32_C(           5),  INT32_C(           7), -INT32_C(          14),  INT32_C(           2) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
    { { -INT32_C(   716552719),  INT32_C(  1439417567),  INT32_C(  1914609672),  INT32_C(   117758867) },
      { -INT32_C(    11196137),  INT32_C(    22490899),  INT32_C(    29915776),  INT32_C(     1839982) },
      { -INT32_C(       87470),  INT32_C(      175710),  INT32_C(      233717),  INT32_C(       14374) },
      { -INT32_C(        1367),  INT32_C(        2745),  INT32_C(        3651),  INT32_C(         224) },
      { -INT32_C(          11),  INT32_C(          21),  INT32_C(          28),  INT32_C(           1) },
      { -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1646022805),  INT32_C(   360835778),  INT32_C(  1021237277),  INT32_C(  1682368627) },
      {  INT32_C(    25719106),  INT32_C(     5638059),  INT32_C(    15956832),  INT32_C(    26287009) },
      {  INT32_C(      200930),  INT32_C(       44047),  INT32_C(      124662),  INT32_C(      205367) },
      {  INT32_C(        3139),  INT32_C(         688),  INT32_C(        1947),  INT32_C(        3208) },
      {  INT32_C(          24),  INT32_C(           5),  INT32_C(          15),  INT32_C(          25) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_int32x4_t r6 = simde_vshrq_n_s32(a, 6);
    simde_int32x4_t r13 = simde_vshrq_n_s32(a, 13);
    simde_int32x4_t r19 = simde_vshrq_n_s32(a, 19);
    simde_int32x4_t r26 = simde_vshrq_n_s32(a, 26);
    simde_int32x4_t r32 = simde_vshrq_n_s32(a, 32);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r32, simde_vld1q_s32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vshrq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t r13[2];
    int64_t r26[2];
    int64_t r39[2];
    int64_t r52[2];
    int64_t r64[2];
  } test_vec[] = {
    { {  INT64_C( 7258000848010340907),  INT64_C( 6356962164739953033) },
      {  INT64_C(     885986431641887),  INT64_C(     775996358000482) },
      {  INT64_C(        108152640581),  INT64_C(         94726117919) },
      {  INT64_C(            13202226),  INT64_C(            11563246) },
      {  INT64_C(                1611),  INT64_C(                1411) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 4083202087668540142), -INT64_C(  666128355631102955) },
      { -INT64_C(     498437754842352), -INT64_C(      81314496537000) },
      { -INT64_C(         60844452496), -INT64_C(          9926086004) },
      { -INT64_C(             7427302), -INT64_C(             1211681) },
      { -INT64_C(                 907), -INT64_C(                 148) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C(  508841331230762074), -INT64_C( 8802639018395763947) },
      {  INT64_C(      62114420316255), -INT64_C(    1074540895800265) },
      {  INT64_C(          7582326698), -INT64_C(        131169542945) },
      {  INT64_C(              925576), -INT64_C(            16011908) },
      {  INT64_C(                 112), -INT64_C(                1955) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
    { { -INT64_C( 2596152810134882085), -INT64_C( 8259092421874367328) },
      { -INT64_C(     316913184830919), -INT64_C(    1008189992904586) },
      { -INT64_C(         38685691508), -INT64_C(        123070067494) },
      { -INT64_C(             4722375), -INT64_C(            15023202) },
      { -INT64_C(                 577), -INT64_C(                1834) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 5060155032460684468),  INT64_C( 6358126638685011780) },
      {  INT64_C(     617694706110923),  INT64_C(     776138505698853) },
      {  INT64_C(         75402185804),  INT64_C(         94743469933) },
      {  INT64_C(             9204368),  INT64_C(            11565364) },
      {  INT64_C(                1123),  INT64_C(                1411) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 4506834250564533037),  INT64_C(  434471274424336966) },
      { -INT64_C(     550150665352116),  INT64_C(      53036044241252) },
      { -INT64_C(         67157063642),  INT64_C(          6474126494) },
      { -INT64_C(             8197884),  INT64_C(              790298) },
      { -INT64_C(                1001),  INT64_C(                  96) },
      { -INT64_C(                   1),  INT64_C(                   0) } },
    { { -INT64_C( 3715063387966127879), -INT64_C( 6699736868146957008) },
      { -INT64_C(     453498948726334), -INT64_C(     817838973162471) },
      { -INT64_C(         55358758390), -INT64_C(         99833859029) },
      { -INT64_C(             6757661), -INT64_C(            12186751) },
      { -INT64_C(                 825), -INT64_C(                1488) },
      { -INT64_C(                   1), -INT64_C(                   1) } },
    { {  INT64_C( 6279618844180647748), -INT64_C( 2843222864020090574) },
      {  INT64_C(     766555034690020), -INT64_C(     347073103518078) },
      {  INT64_C(         93573612633), -INT64_C(         42367322207) },
      {  INT64_C(            11422560), -INT64_C(             5171793) },
      {  INT64_C(                1394), -INT64_C(                 632) },
      {  INT64_C(                   0), -INT64_C(                   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_int64x2_t r13 = simde_vshrq_n_s64(a, 13);
    simde_int64x2_t r26 = simde_vshrq_n_s64(a, 26);
    simde_int64x2_t r39 = simde_vshrq_n_s64(a, 39);
    simde_int64x2_t r52 = simde_vshrq_n_s64(a, 52);
    simde_int64x2_t r64 = simde_vshrq_n_s64(a, 64);

    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r39, simde_vld1q_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x2(r52, simde_vld1q_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x2(r64, simde_vld1q_s64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vshrq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { { UINT8_C(152), UINT8_C( 87), UINT8_C( 17), UINT8_C(199), UINT8_C(188), UINT8_C(234), UINT8_C( 66), UINT8_C(209),
        UINT8_C(194), UINT8_C(193), UINT8_C(190), UINT8_C( 69), UINT8_C(146), UINT8_C(243), UINT8_C(209), UINT8_C( 73) },
      { UINT8_C( 76), UINT8_C( 43), UINT8_C(  8), UINT8_C( 99), UINT8_C( 94), UINT8_C(117), UINT8_C( 33), UINT8_C(104),
        UINT8_C( 97), UINT8_C( 96), UINT8_C( 95), UINT8_C( 34), UINT8_C( 73), UINT8_C(121), UINT8_C(104), UINT8_C( 36) },
      { UINT8_C( 19), UINT8_C( 10), UINT8_C(  2), UINT8_C( 24), UINT8_C( 23), UINT8_C( 29), UINT8_C(  8), UINT8_C( 26),
        UINT8_C( 24), UINT8_C( 24), UINT8_C( 23), UINT8_C(  8), UINT8_C( 18), UINT8_C( 30), UINT8_C( 26), UINT8_C(  9) },
      { UINT8_C(  4), UINT8_C(  2), UINT8_C(  0), UINT8_C(  6), UINT8_C(  5), UINT8_C(  7), UINT8_C(  2), UINT8_C(  6),
        UINT8_C(  6), UINT8_C(  6), UINT8_C(  5), UINT8_C(  2), UINT8_C(  4), UINT8_C(  7), UINT8_C(  6), UINT8_C(  2) },
      { UINT8_C(  2), UINT8_C(  1), UINT8_C(  0), UINT8_C(  3), UINT8_C(  2), UINT8_C(  3), UINT8_C(  1), UINT8_C(  3),
        UINT8_C(  3), UINT8_C(  3), UINT8_C(  2), UINT8_C(  1), UINT8_C(  2), UINT8_C(  3), UINT8_C(  3), UINT8_C(  1) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(140), UINT8_C( 32), UINT8_C( 70), UINT8_C(100), UINT8_C( 70), UINT8_C(102), UINT8_C(246), UINT8_C(204),
        UINT8_C(207), UINT8_C(243), UINT8_C(234), UINT8_C( 39), UINT8_C(159), UINT8_C( 16), UINT8_C(196), UINT8_C( 55) },
      { UINT8_C( 70), UINT8_C( 16), UINT8_C( 35), UINT8_C( 50), UINT8_C( 35), UINT8_C( 51), UINT8_C(123), UINT8_C(102),
        UINT8_C(103), UINT8_C(121), UINT8_C(117), UINT8_C( 19), UINT8_C( 79), UINT8_C(  8), UINT8_C( 98), UINT8_C( 27) },
      { UINT8_C( 17), UINT8_C(  4), UINT8_C(  8), UINT8_C( 12), UINT8_C(  8), UINT8_C( 12), UINT8_C( 30), UINT8_C( 25),
        UINT8_C( 25), UINT8_C( 30), UINT8_C( 29), UINT8_C(  4), UINT8_C( 19), UINT8_C(  2), UINT8_C( 24), UINT8_C(  6) },
      { UINT8_C(  4), UINT8_C(  1), UINT8_C(  2), UINT8_C(  3), UINT8_C(  2), UINT8_C(  3), UINT8_C(  7), UINT8_C(  6),
        UINT8_C(  6), UINT8_C(  7), UINT8_C(  7), UINT8_C(  1), UINT8_C(  4), UINT8_C(  0), UINT8_C(  6), UINT8_C(  1) },
      { UINT8_C(  2), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  3), UINT8_C(  3),
        UINT8_C(  3), UINT8_C(  3), UINT8_C(  3), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(  3), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(103), UINT8_C(213),    UINT8_MAX, UINT8_C( 36), UINT8_C(191), UINT8_C( 65), UINT8_C(245), UINT8_C(130),
        UINT8_C(  2), UINT8_C(179), UINT8_C(199), UINT8_C(148), UINT8_C(167), UINT8_C(152), UINT8_C(221), UINT8_C( 51) },
      { UINT8_C( 51), UINT8_C(106), UINT8_C(127), UINT8_C( 18), UINT8_C( 95), UINT8_C( 32), UINT8_C(122), UINT8_C( 65),
        UINT8_C(  1), UINT8_C( 89), UINT8_C( 99), UINT8_C( 74), UINT8_C( 83), UINT8_C( 76), UINT8_C(110), UINT8_C( 25) },
      { UINT8_C( 12), UINT8_C( 26), UINT8_C( 31), UINT8_C(  4), UINT8_C( 23), UINT8_C(  8), UINT8_C( 30), UINT8_C( 16),
        UINT8_C(  0), UINT8_C( 22), UINT8_C( 24), UINT8_C( 18), UINT8_C( 20), UINT8_C( 19), UINT8_C( 27), UINT8_C(  6) },
      { UINT8_C(  3), UINT8_C(  6), UINT8_C(  7), UINT8_C(  1), UINT8_C(  5), UINT8_C(  2), UINT8_C(  7), UINT8_C(  4),
        UINT8_C(  0), UINT8_C(  5), UINT8_C(  6), UINT8_C(  4), UINT8_C(  5), UINT8_C(  4), UINT8_C(  6), UINT8_C(  1) },
      { UINT8_C(  1), UINT8_C(  3), UINT8_C(  3), UINT8_C(  0), UINT8_C(  2), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2),
        UINT8_C(  0), UINT8_C(  2), UINT8_C(  3), UINT8_C(  2), UINT8_C(  2), UINT8_C(  2), UINT8_C(  3), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(184), UINT8_C( 36), UINT8_C(151),    UINT8_MAX, UINT8_C(138), UINT8_C(142), UINT8_C(203), UINT8_C( 89),
        UINT8_C(129), UINT8_C(181), UINT8_C(128), UINT8_C( 32), UINT8_C(198), UINT8_C( 69), UINT8_C( 87), UINT8_C( 45) },
      { UINT8_C( 92), UINT8_C( 18), UINT8_C( 75), UINT8_C(127), UINT8_C( 69), UINT8_C( 71), UINT8_C(101), UINT8_C( 44),
        UINT8_C( 64), UINT8_C( 90), UINT8_C( 64), UINT8_C( 16), UINT8_C( 99), UINT8_C( 34), UINT8_C( 43), UINT8_C( 22) },
      { UINT8_C( 23), UINT8_C(  4), UINT8_C( 18), UINT8_C( 31), UINT8_C( 17), UINT8_C( 17), UINT8_C( 25), UINT8_C( 11),
        UINT8_C( 16), UINT8_C( 22), UINT8_C( 16), UINT8_C(  4), UINT8_C( 24), UINT8_C(  8), UINT8_C( 10), UINT8_C(  5) },
      { UINT8_C(  5), UINT8_C(  1), UINT8_C(  4), UINT8_C(  7), UINT8_C(  4), UINT8_C(  4), UINT8_C(  6), UINT8_C(  2),
        UINT8_C(  4), UINT8_C(  5), UINT8_C(  4), UINT8_C(  1), UINT8_C(  6), UINT8_C(  2), UINT8_C(  2), UINT8_C(  1) },
      { UINT8_C(  2), UINT8_C(  0), UINT8_C(  2), UINT8_C(  3), UINT8_C(  2), UINT8_C(  2), UINT8_C(  3), UINT8_C(  1),
        UINT8_C(  2), UINT8_C(  2), UINT8_C(  2), UINT8_C(  0), UINT8_C(  3), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 26), UINT8_C( 86), UINT8_C( 81), UINT8_C(218), UINT8_C(151), UINT8_C( 70), UINT8_C( 92), UINT8_C(153),
        UINT8_C(250), UINT8_C( 35), UINT8_C( 46), UINT8_C(161), UINT8_C(187), UINT8_C( 11), UINT8_C(212), UINT8_C(115) },
      { UINT8_C( 13), UINT8_C( 43), UINT8_C( 40), UINT8_C(109), UINT8_C( 75), UINT8_C( 35), UINT8_C( 46), UINT8_C( 76),
        UINT8_C(125), UINT8_C( 17), UINT8_C( 23), UINT8_C( 80), UINT8_C( 93), UINT8_C(  5), UINT8_C(106), UINT8_C( 57) },
      { UINT8_C(  3), UINT8_C( 10), UINT8_C( 10), UINT8_C( 27), UINT8_C( 18), UINT8_C(  8), UINT8_C( 11), UINT8_C( 19),
        UINT8_C( 31), UINT8_C(  4), UINT8_C(  5), UINT8_C( 20), UINT8_C( 23), UINT8_C(  1), UINT8_C( 26), UINT8_C( 14) },
      { UINT8_C(  0), UINT8_C(  2), UINT8_C(  2), UINT8_C(  6), UINT8_C(  4), UINT8_C(  2), UINT8_C(  2), UINT8_C(  4),
        UINT8_C(  7), UINT8_C(  1), UINT8_C(  1), UINT8_C(  5), UINT8_C(  5), UINT8_C(  0), UINT8_C(  6), UINT8_C(  3) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2), UINT8_C(  1), UINT8_C(  1), UINT8_C(  2),
        UINT8_C(  3), UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C(  2), UINT8_C(  0), UINT8_C(  3), UINT8_C(  1) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 47), UINT8_C(107), UINT8_C(114), UINT8_C(185), UINT8_C(249), UINT8_C( 62), UINT8_C( 18), UINT8_C(122),
        UINT8_C(243), UINT8_C(147), UINT8_C(154), UINT8_C(185), UINT8_C(216), UINT8_C(242), UINT8_C(231), UINT8_C(242) },
      { UINT8_C( 23), UINT8_C( 53), UINT8_C( 57), UINT8_C( 92), UINT8_C(124), UINT8_C( 31), UINT8_C(  9), UINT8_C( 61),
        UINT8_C(121), UINT8_C( 73), UINT8_C( 77), UINT8_C( 92), UINT8_C(108), UINT8_C(121), UINT8_C(115), UINT8_C(121) },
      { UINT8_C(  5), UINT8_C( 13), UINT8_C( 14), UINT8_C( 23), UINT8_C( 31), UINT8_C(  7), UINT8_C(  2), UINT8_C( 15),
        UINT8_C( 30), UINT8_C( 18), UINT8_C( 19), UINT8_C( 23), UINT8_C( 27), UINT8_C( 30), UINT8_C( 28), UINT8_C( 30) },
      { UINT8_C(  1), UINT8_C(  3), UINT8_C(  3), UINT8_C(  5), UINT8_C(  7), UINT8_C(  1), UINT8_C(  0), UINT8_C(  3),
        UINT8_C(  7), UINT8_C(  4), UINT8_C(  4), UINT8_C(  5), UINT8_C(  6), UINT8_C(  7), UINT8_C(  7), UINT8_C(  7) },
      { UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C(  2), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1),
        UINT8_C(  3), UINT8_C(  2), UINT8_C(  2), UINT8_C(  2), UINT8_C(  3), UINT8_C(  3), UINT8_C(  3), UINT8_C(  3) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 72), UINT8_C( 56), UINT8_C(204), UINT8_C(224), UINT8_C(127), UINT8_C( 40), UINT8_C(121), UINT8_C(121),
        UINT8_C( 75), UINT8_C(167), UINT8_C( 26), UINT8_C(  6), UINT8_C(179), UINT8_C(238), UINT8_C(122), UINT8_C(226) },
      { UINT8_C( 36), UINT8_C( 28), UINT8_C(102), UINT8_C(112), UINT8_C( 63), UINT8_C( 20), UINT8_C( 60), UINT8_C( 60),
        UINT8_C( 37), UINT8_C( 83), UINT8_C( 13), UINT8_C(  3), UINT8_C( 89), UINT8_C(119), UINT8_C( 61), UINT8_C(113) },
      { UINT8_C(  9), UINT8_C(  7), UINT8_C( 25), UINT8_C( 28), UINT8_C( 15), UINT8_C(  5), UINT8_C( 15), UINT8_C( 15),
        UINT8_C(  9), UINT8_C( 20), UINT8_C(  3), UINT8_C(  0), UINT8_C( 22), UINT8_C( 29), UINT8_C( 15), UINT8_C( 28) },
      { UINT8_C(  2), UINT8_C(  1), UINT8_C(  6), UINT8_C(  7), UINT8_C(  3), UINT8_C(  1), UINT8_C(  3), UINT8_C(  3),
        UINT8_C(  2), UINT8_C(  5), UINT8_C(  0), UINT8_C(  0), UINT8_C(  5), UINT8_C(  7), UINT8_C(  3), UINT8_C(  7) },
      { UINT8_C(  1), UINT8_C(  0), UINT8_C(  3), UINT8_C(  3), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1),
        UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C(  3), UINT8_C(  1), UINT8_C(  3) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 89), UINT8_C(236), UINT8_C(156), UINT8_C( 83), UINT8_C( 42), UINT8_C(174), UINT8_C(205), UINT8_C( 30),
        UINT8_C( 65), UINT8_C(104), UINT8_C(215), UINT8_C( 25), UINT8_C( 90), UINT8_C(190), UINT8_C( 12), UINT8_C(162) },
      { UINT8_C( 44), UINT8_C(118), UINT8_C( 78), UINT8_C( 41), UINT8_C( 21), UINT8_C( 87), UINT8_C(102), UINT8_C( 15),
        UINT8_C( 32), UINT8_C( 52), UINT8_C(107), UINT8_C( 12), UINT8_C( 45), UINT8_C( 95), UINT8_C(  6), UINT8_C( 81) },
      { UINT8_C( 11), UINT8_C( 29), UINT8_C( 19), UINT8_C( 10), UINT8_C(  5), UINT8_C( 21), UINT8_C( 25), UINT8_C(  3),
        UINT8_C(  8), UINT8_C( 13), UINT8_C( 26), UINT8_C(  3), UINT8_C( 11), UINT8_C( 23), UINT8_C(  1), UINT8_C( 20) },
      { UINT8_C(  2), UINT8_C(  7), UINT8_C(  4), UINT8_C(  2), UINT8_C(  1), UINT8_C(  5), UINT8_C(  6), UINT8_C(  0),
        UINT8_C(  2), UINT8_C(  3), UINT8_C(  6), UINT8_C(  0), UINT8_C(  2), UINT8_C(  5), UINT8_C(  0), UINT8_C(  5) },
      { UINT8_C(  1), UINT8_C(  3), UINT8_C(  2), UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C(  3), UINT8_C(  0),
        UINT8_C(  1), UINT8_C(  1), UINT8_C(  3), UINT8_C(  0), UINT8_C(  1), UINT8_C(  2), UINT8_C(  0), UINT8_C(  2) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);

    simde_uint8x16_t r1 = simde_vshrq_n_u8(a, 1);
    simde_uint8x16_t r3 = simde_vshrq_n_u8(a, 3);
    simde_uint8x16_t r5 = simde_vshrq_n_u8(a, 5);
    simde_uint8x16_t r6 = simde_vshrq_n_u8(a, 6);
    simde_uint8x16_t r8 = simde_vshrq_n_u8(a, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vshrq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { { UINT16_C(24398), UINT16_C(48722), UINT16_C(55176), UINT16_C( 3988), UINT16_C(49143), UINT16_C( 3217), UINT16_C(60719), UINT16_C(38374) },
      { UINT16_C( 3049), UINT16_C( 6090), UINT16_C( 6897), UINT16_C(  498), UINT16_C( 6142), UINT16_C(  402), UINT16_C( 7589), UINT16_C( 4796) },
      { UINT16_C(  381), UINT16_C(  761), UINT16_C(  862), UINT16_C(   62), UINT16_C(  767), UINT16_C(   50), UINT16_C(  948), UINT16_C(  599) },
      { UINT16_C(   23), UINT16_C(   47), UINT16_C(   53), UINT16_C(    3), UINT16_C(   47), UINT16_C(    3), UINT16_C(   59), UINT16_C(   37) },
      { UINT16_C(    2), UINT16_C(    5), UINT16_C(    6), UINT16_C(    0), UINT16_C(    5), UINT16_C(    0), UINT16_C(    7), UINT16_C(    4) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(65497), UINT16_C(64072), UINT16_C( 6860), UINT16_C( 4494), UINT16_C(32051), UINT16_C(16486), UINT16_C(63839), UINT16_C(44397) },
      { UINT16_C( 8187), UINT16_C( 8009), UINT16_C(  857), UINT16_C(  561), UINT16_C( 4006), UINT16_C( 2060), UINT16_C( 7979), UINT16_C( 5549) },
      { UINT16_C( 1023), UINT16_C( 1001), UINT16_C(  107), UINT16_C(   70), UINT16_C(  500), UINT16_C(  257), UINT16_C(  997), UINT16_C(  693) },
      { UINT16_C(   63), UINT16_C(   62), UINT16_C(    6), UINT16_C(    4), UINT16_C(   31), UINT16_C(   16), UINT16_C(   62), UINT16_C(   43) },
      { UINT16_C(    7), UINT16_C(    7), UINT16_C(    0), UINT16_C(    0), UINT16_C(    3), UINT16_C(    2), UINT16_C(    7), UINT16_C(    5) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(48984), UINT16_C(57451), UINT16_C(  151), UINT16_C(36591), UINT16_C(32959), UINT16_C(61338), UINT16_C(32877), UINT16_C(18052) },
      { UINT16_C( 6123), UINT16_C( 7181), UINT16_C(   18), UINT16_C( 4573), UINT16_C( 4119), UINT16_C( 7667), UINT16_C( 4109), UINT16_C( 2256) },
      { UINT16_C(  765), UINT16_C(  897), UINT16_C(    2), UINT16_C(  571), UINT16_C(  514), UINT16_C(  958), UINT16_C(  513), UINT16_C(  282) },
      { UINT16_C(   47), UINT16_C(   56), UINT16_C(    0), UINT16_C(   35), UINT16_C(   32), UINT16_C(   59), UINT16_C(   32), UINT16_C(   17) },
      { UINT16_C(    5), UINT16_C(    7), UINT16_C(    0), UINT16_C(    4), UINT16_C(    4), UINT16_C(    7), UINT16_C(    4), UINT16_C(    2) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(52351), UINT16_C(19264), UINT16_C(52966), UINT16_C( 6493), UINT16_C(49995), UINT16_C(43865), UINT16_C(50876), UINT16_C( 5208) },
      { UINT16_C( 6543), UINT16_C( 2408), UINT16_C( 6620), UINT16_C(  811), UINT16_C( 6249), UINT16_C( 5483), UINT16_C( 6359), UINT16_C(  651) },
      { UINT16_C(  817), UINT16_C(  301), UINT16_C(  827), UINT16_C(  101), UINT16_C(  781), UINT16_C(  685), UINT16_C(  794), UINT16_C(   81) },
      { UINT16_C(   51), UINT16_C(   18), UINT16_C(   51), UINT16_C(    6), UINT16_C(   48), UINT16_C(   42), UINT16_C(   49), UINT16_C(    5) },
      { UINT16_C(    6), UINT16_C(    2), UINT16_C(    6), UINT16_C(    0), UINT16_C(    6), UINT16_C(    5), UINT16_C(    6), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(50310), UINT16_C( 7668), UINT16_C(58308), UINT16_C(33707), UINT16_C(17763), UINT16_C(53362), UINT16_C(63173), UINT16_C(17686) },
      { UINT16_C( 6288), UINT16_C(  958), UINT16_C( 7288), UINT16_C( 4213), UINT16_C( 2220), UINT16_C( 6670), UINT16_C( 7896), UINT16_C( 2210) },
      { UINT16_C(  786), UINT16_C(  119), UINT16_C(  911), UINT16_C(  526), UINT16_C(  277), UINT16_C(  833), UINT16_C(  987), UINT16_C(  276) },
      { UINT16_C(   49), UINT16_C(    7), UINT16_C(   56), UINT16_C(   32), UINT16_C(   17), UINT16_C(   52), UINT16_C(   61), UINT16_C(   17) },
      { UINT16_C(    6), UINT16_C(    0), UINT16_C(    7), UINT16_C(    4), UINT16_C(    2), UINT16_C(    6), UINT16_C(    7), UINT16_C(    2) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(22211), UINT16_C(43408), UINT16_C(60708), UINT16_C(28867), UINT16_C( 7345), UINT16_C(27931), UINT16_C(29667), UINT16_C(27010) },
      { UINT16_C( 2776), UINT16_C( 5426), UINT16_C( 7588), UINT16_C( 3608), UINT16_C(  918), UINT16_C( 3491), UINT16_C( 3708), UINT16_C( 3376) },
      { UINT16_C(  347), UINT16_C(  678), UINT16_C(  948), UINT16_C(  451), UINT16_C(  114), UINT16_C(  436), UINT16_C(  463), UINT16_C(  422) },
      { UINT16_C(   21), UINT16_C(   42), UINT16_C(   59), UINT16_C(   28), UINT16_C(    7), UINT16_C(   27), UINT16_C(   28), UINT16_C(   26) },
      { UINT16_C(    2), UINT16_C(    5), UINT16_C(    7), UINT16_C(    3), UINT16_C(    0), UINT16_C(    3), UINT16_C(    3), UINT16_C(    3) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(30263), UINT16_C(64390), UINT16_C(12634), UINT16_C(48511), UINT16_C(61814), UINT16_C(15246), UINT16_C(42216), UINT16_C(43904) },
      { UINT16_C( 3782), UINT16_C( 8048), UINT16_C( 1579), UINT16_C( 6063), UINT16_C( 7726), UINT16_C( 1905), UINT16_C( 5277), UINT16_C( 5488) },
      { UINT16_C(  472), UINT16_C( 1006), UINT16_C(  197), UINT16_C(  757), UINT16_C(  965), UINT16_C(  238), UINT16_C(  659), UINT16_C(  686) },
      { UINT16_C(   29), UINT16_C(   62), UINT16_C(   12), UINT16_C(   47), UINT16_C(   60), UINT16_C(   14), UINT16_C(   41), UINT16_C(   42) },
      { UINT16_C(    3), UINT16_C(    7), UINT16_C(    1), UINT16_C(    5), UINT16_C(    7), UINT16_C(    1), UINT16_C(    5), UINT16_C(    5) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 4603), UINT16_C( 8020), UINT16_C( 6142), UINT16_C(44943), UINT16_C(43572), UINT16_C( 5917), UINT16_C(40734), UINT16_C(21888) },
      { UINT16_C(  575), UINT16_C( 1002), UINT16_C(  767), UINT16_C( 5617), UINT16_C( 5446), UINT16_C(  739), UINT16_C( 5091), UINT16_C( 2736) },
      { UINT16_C(   71), UINT16_C(  125), UINT16_C(   95), UINT16_C(  702), UINT16_C(  680), UINT16_C(   92), UINT16_C(  636), UINT16_C(  342) },
      { UINT16_C(    4), UINT16_C(    7), UINT16_C(    5), UINT16_C(   43), UINT16_C(   42), UINT16_C(    5), UINT16_C(   39), UINT16_C(   21) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    5), UINT16_C(    5), UINT16_C(    0), UINT16_C(    4), UINT16_C(    2) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);

    simde_uint16x8_t r3 = simde_vshrq_n_u16(a, 3);
    simde_uint16x8_t r6 = simde_vshrq_n_u16(a, 6);
    simde_uint16x8_t r10 = simde_vshrq_n_u16(a, 10);
    simde_uint16x8_t r13 = simde_vshrq_n_u16(a, 13);
    simde_uint16x8_t r16 = simde_vshrq_n_u16(a, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vshrq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { { UINT32_C(1301916297), UINT32_C(2359195108), UINT32_C(3209238876), UINT32_C(3414373642) },
      { UINT32_C(  20342442), UINT32_C(  36862423), UINT32_C(  50144357), UINT32_C(  53349588) },
      { UINT32_C(    158925), UINT32_C(    287987), UINT32_C(    391752), UINT32_C(    416793) },
      { UINT32_C(      2483), UINT32_C(      4499), UINT32_C(      6121), UINT32_C(      6512) },
      { UINT32_C(        19), UINT32_C(        35), UINT32_C(        47), UINT32_C(        50) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 841976147), UINT32_C( 375262057), UINT32_C(4032949437), UINT32_C(2942361382) },
      { UINT32_C(  13155877), UINT32_C(   5863469), UINT32_C(  63014834), UINT32_C(  45974396) },
      { UINT32_C(    102780), UINT32_C(     45808), UINT32_C(    492303), UINT32_C(    359174) },
      { UINT32_C(      1605), UINT32_C(       715), UINT32_C(      7692), UINT32_C(      5612) },
      { UINT32_C(        12), UINT32_C(         5), UINT32_C(        60), UINT32_C(        43) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1862072714), UINT32_C(3405421166), UINT32_C(3196666803), UINT32_C(3414756472) },
      { UINT32_C(  29094886), UINT32_C(  53209705), UINT32_C(  49947918), UINT32_C(  53355569) },
      { UINT32_C(    227303), UINT32_C(    415700), UINT32_C(    390218), UINT32_C(    416840) },
      { UINT32_C(      3551), UINT32_C(      6495), UINT32_C(      6097), UINT32_C(      6513) },
      { UINT32_C(        27), UINT32_C(        50), UINT32_C(        47), UINT32_C(        50) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(4294883734), UINT32_C(2165660868), UINT32_C(1852995144), UINT32_C(3743339093) },
      { UINT32_C(  67107558), UINT32_C(  33838451), UINT32_C(  28953049), UINT32_C(  58489673) },
      { UINT32_C(    524277), UINT32_C(    264362), UINT32_C(    226195), UINT32_C(    456950) },
      { UINT32_C(      8191), UINT32_C(      4130), UINT32_C(      3534), UINT32_C(      7139) },
      { UINT32_C(        63), UINT32_C(        32), UINT32_C(        27), UINT32_C(        55) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 961354443), UINT32_C(1745111221), UINT32_C(  69635467), UINT32_C( 818917530) },
      { UINT32_C(  15021163), UINT32_C(  27267362), UINT32_C(   1088054), UINT32_C(  12795586) },
      { UINT32_C(    117352), UINT32_C(    213026), UINT32_C(      8500), UINT32_C(     99965) },
      { UINT32_C(      1833), UINT32_C(      3328), UINT32_C(       132), UINT32_C(      1561) },
      { UINT32_C(        14), UINT32_C(        26), UINT32_C(         1), UINT32_C(        12) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 758107497), UINT32_C(1924023338), UINT32_C( 266412218), UINT32_C(3186622450) },
      { UINT32_C(  11845429), UINT32_C(  30062864), UINT32_C(   4162690), UINT32_C(  49790975) },
      { UINT32_C(     92542), UINT32_C(    234866), UINT32_C(     32521), UINT32_C(    388991) },
      { UINT32_C(      1445), UINT32_C(      3669), UINT32_C(       508), UINT32_C(      6077) },
      { UINT32_C(        11), UINT32_C(        28), UINT32_C(         3), UINT32_C(        47) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3472309273), UINT32_C( 272104324), UINT32_C( 571760008), UINT32_C(1985143565) },
      { UINT32_C(  54254832), UINT32_C(   4251630), UINT32_C(   8933750), UINT32_C(  31017868) },
      { UINT32_C(    423865), UINT32_C(     33215), UINT32_C(     69794), UINT32_C(    242327) },
      { UINT32_C(      6622), UINT32_C(       518), UINT32_C(      1090), UINT32_C(      3786) },
      { UINT32_C(        51), UINT32_C(         4), UINT32_C(         8), UINT32_C(        29) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3684925873), UINT32_C(2135773893), UINT32_C(1703882354), UINT32_C(1193442861) },
      { UINT32_C(  57576966), UINT32_C(  33371467), UINT32_C(  26623161), UINT32_C(  18647544) },
      { UINT32_C(    449820), UINT32_C(    260714), UINT32_C(    207993), UINT32_C(    145683) },
      { UINT32_C(      7028), UINT32_C(      4073), UINT32_C(      3249), UINT32_C(      2276) },
      { UINT32_C(        54), UINT32_C(        31), UINT32_C(        25), UINT32_C(        17) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);

    simde_uint32x4_t r6 = simde_vshrq_n_u32(a, 6);
    simde_uint32x4_t r13 = simde_vshrq_n_u32(a, 13);
    simde_uint32x4_t r19 = simde_vshrq_n_u32(a, 19);
    simde_uint32x4_t r26 = simde_vshrq_n_u32(a, 26);
    simde_uint32x4_t r32 = simde_vshrq_n_u32(a, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vshrq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t r13[2];
    uint64_t r26[2];
    uint64_t r39[2];
    uint64_t r52[2];
    uint64_t r64[2];
  } test_vec[] = {
    { { UINT64_C( 4114336365591682096), UINT64_C(10892621211583185910) },
      { UINT64_C(     502238325877890), UINT64_C(    1329665675242088) },
      { UINT64_C(         61308389389), UINT64_C(        162312704497) },
      { UINT64_C(             7483934), UINT64_C(            19813562) },
      { UINT64_C(                 913), UINT64_C(                2418) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(   62757455042096864), UINT64_C( 2063308251897106318) },
      { UINT64_C(       7660822148693), UINT64_C(     251868683092908) },
      { UINT64_C(           935158953), UINT64_C(         30745688854) },
      { UINT64_C(              114155), UINT64_C(             3753135) },
      { UINT64_C(                  13), UINT64_C(                 458) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 4039001276083680180), UINT64_C(10902133567454599789) },
      { UINT64_C(     493042147959433), UINT64_C(    1330826851495922) },
      { UINT64_C(         60185809077), UINT64_C(        162454449645) },
      { UINT64_C(             7346900), UINT64_C(            19830865) },
      { UINT64_C(                 896), UINT64_C(                2420) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(11054679070670198487), UINT64_C(16912305462898253740) },
      { UINT64_C(    1349448128743920), UINT64_C(    2064490412951446) },
      { UINT64_C(        164727554778), UINT64_C(        252012989862) },
      { UINT64_C(            20108344), UINT64_C(            30763304) },
      { UINT64_C(                2454), UINT64_C(                3755) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(15943530412416828871), UINT64_C( 4572805538656698406) },
      { UINT64_C(    1946231739796976), UINT64_C(     558203801105554) },
      { UINT64_C(        237577116674), UINT64_C(         68140112439) },
      { UINT64_C(            29001112), UINT64_C(             8317884) },
      { UINT64_C(                3540), UINT64_C(                1015) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 8978229116225041396), UINT64_C(16650872287755799538) },
      { UINT64_C(    1095975233914189), UINT64_C(    2032577183563940) },
      { UINT64_C(        133786039296), UINT64_C(        248117331978) },
      { UINT64_C(            16331303), UINT64_C(            30287760) },
      { UINT64_C(                1993), UINT64_C(                3697) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(14130945006247203277), UINT64_C( 9230997754973695347) },
      { UINT64_C(    1724968872832910), UINT64_C(    1126830780636437) },
      { UINT64_C(        210567489359), UINT64_C(        137552585526) },
      { UINT64_C(            25704039), UINT64_C(            16791087) },
      { UINT64_C(                3137), UINT64_C(                2049) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(14490079839417058507), UINT64_C(13883758671297588133) },
      { UINT64_C(    1768808574147590), UINT64_C(    1694794759679881) },
      { UINT64_C(        215919015398), UINT64_C(        206884125937) },
      { UINT64_C(            26357301), UINT64_C(            25254409) },
      { UINT64_C(                3217), UINT64_C(                3082) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);

    simde_uint64x2_t r13 = simde_vshrq_n_u64(a, 13);
    simde_uint64x2_t r26 = simde_vshrq_n_u64(a, 26);
    simde_uint64x2_t r39 = simde_vshrq_n_u64(a, 39);
    simde_uint64x2_t r52 = simde_vshrq_n_u64(a, 52);
    simde_uint64x2_t r64 = simde_vshrq_n_u64(a, 64);

    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r39, simde_vld1q_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x2(r52, simde_vld1q_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x2(r64, simde_vld1q_u64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vshrd_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t r1;
    int64_t r13;
    int64_t r23;
    int64_t r37;
    int64_t r46;
    int64_t r55;
    int64_t r64;
  } test_vec[] = {
    {  INT64_C( 4961057853738452981),
       INT64_C( 2480528926869226490),
       INT64_C(     605597882536432),
       INT64_C(        591404182164),
       INT64_C(            36096446),
       INT64_C(               70500),
       INT64_C(                 137),
       INT64_C(                   0) },
    { -INT64_C( 6375358491915238124),
      -INT64_C( 3187679245957619062),
      -INT64_C(     778242003407622),
      -INT64_C(        760001956453),
      -INT64_C(            46386839),
      -INT64_C(               90600),
      -INT64_C(                 177),
      -INT64_C(                   1) },
    { -INT64_C( 2997746089104730026),
      -INT64_C( 1498873044552365013),
      -INT64_C(     365935801892668),
      -INT64_C(        357359181536),
      -INT64_C(            21811474),
      -INT64_C(               42601),
      -INT64_C(                  84),
      -INT64_C(                   1) },
    {  INT64_C( 7733683819984906860),
       INT64_C( 3866841909992453430),
       INT64_C(     944053200681751),
       INT64_C(        921926953790),
       INT64_C(            56269955),
       INT64_C(              109902),
       INT64_C(                 214),
       INT64_C(                   0) },
    { -INT64_C( 2544094223490772585),
      -INT64_C( 1272047111745386293),
      -INT64_C(     310558376890964),
      -INT64_C(        303279664933),
      -INT64_C(            18510722),
      -INT64_C(               36154),
      -INT64_C(                  71),
      -INT64_C(                   1) },
    { -INT64_C( 3119533853209177900),
      -INT64_C( 1559766926604588950),
      -INT64_C(     380802472315574),
      -INT64_C(        371877414371),
      -INT64_C(            22697597),
      -INT64_C(               44332),
      -INT64_C(                  87),
      -INT64_C(                   1) },
    {  INT64_C( 1760566243181776584),
       INT64_C(  880283121590888292),
       INT64_C(     214912871482150),
       INT64_C(        209875851056),
       INT64_C(            12809805),
       INT64_C(               25019),
       INT64_C(                  48),
       INT64_C(                   0) },
    { -INT64_C(  535071418804088397),
      -INT64_C(  267535709402044199),
      -INT64_C(      65316335303234),
      -INT64_C(         63785483695),
      -INT64_C(             3893157),
      -INT64_C(                7604),
      -INT64_C(                  15),
      -INT64_C(                   1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r1 = simde_vshrd_n_s64(test_vec[i].a, 1);
    int64_t r13 = simde_vshrd_n_s64(test_vec[i].a, 13);
    int64_t r23 = simde_vshrd_n_s64(test_vec[i].a, 23);
    int64_t r37 = simde_vshrd_n_s64(test_vec[i].a, 37);
    int64_t r46 = simde_vshrd_n_s64(test_vec[i].a, 46);
    int64_t r55 = simde_vshrd_n_s64(test_vec[i].a, 55);
    int64_t r64 = simde_vshrd_n_s64(test_vec[i].a, 64);

    simde_assert_equal_i64(r1, test_vec[i].r1);
    simde_assert_equal_i64(r13, test_vec[i].r13);
    simde_assert_equal_i64(r23, test_vec[i].r23);
    simde_assert_equal_i64(r37, test_vec[i].r37);
    simde_assert_equal_i64(r46, test_vec[i].r46);
    simde_assert_equal_i64(r55, test_vec[i].r55);
    simde_assert_equal_i64(r64, test_vec[i].r64);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t r1 = simde_vshrd_n_s64(a, 1);
    int64_t r13 = simde_vshrd_n_s64(a, 13);
    int64_t r23 = simde_vshrd_n_s64(a, 23);
    int64_t r37 = simde_vshrd_n_s64(a, 37);
    int64_t r46 = simde_vshrd_n_s64(a, 46);
    int64_t r55 = simde_vshrd_n_s64(a, 55);
    int64_t r64 = simde_vshrd_n_s64(a, 64);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r37, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r46, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshrd_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r1;
    uint64_t r13;
    uint64_t r23;
    uint64_t r37;
    uint64_t r46;
    uint64_t r55;
    uint64_t r64;
  } test_vec[] = {
    { UINT64_C( 1476100456139451215),
      UINT64_C(  738050228069725607),
      UINT64_C(     180188043962335),
      UINT64_C(        175964886681),
      UINT64_C(            10740044),
      UINT64_C(               20976),
      UINT64_C(                  40),
      UINT64_C(                   0) },
    { UINT64_C( 5683035981056096632),
      UINT64_C( 2841517990528048316),
      UINT64_C(     693729978156261),
      UINT64_C(        677470681793),
      UINT64_C(            41349528),
      UINT64_C(               80760),
      UINT64_C(                 157),
      UINT64_C(                   0) },
    { UINT64_C(15663110378325728979),
      UINT64_C( 7831555189162864489),
      UINT64_C(    1912000778604214),
      UINT64_C(       1867188260355),
      UINT64_C(           113964127),
      UINT64_C(              222586),
      UINT64_C(                 434),
      UINT64_C(                   0) },
    { UINT64_C( 7686914600397847593),
      UINT64_C( 3843457300198923796),
      UINT64_C(     938344067431377),
      UINT64_C(        916351628350),
      UINT64_C(            55929664),
      UINT64_C(              109237),
      UINT64_C(                 213),
      UINT64_C(                   0) },
    { UINT64_C( 5400997734401878356),
      UINT64_C( 2700498867200939178),
      UINT64_C(     659301481250229),
      UINT64_C(        643849102783),
      UINT64_C(            39297430),
      UINT64_C(               76752),
      UINT64_C(                 149),
      UINT64_C(                   0) },
    { UINT64_C(10832996324931703019),
      UINT64_C( 5416498162465851509),
      UINT64_C(    1322387246695764),
      UINT64_C(       1291393795601),
      UINT64_C(            78820422),
      UINT64_C(              153946),
      UINT64_C(                 300),
      UINT64_C(                   0) },
    { UINT64_C(16224207454078512231),
      UINT64_C( 8112103727039256115),
      UINT64_C(    1980494073984193),
      UINT64_C(       1934076244125),
      UINT64_C(           118046645),
      UINT64_C(              230559),
      UINT64_C(                 450),
      UINT64_C(                   0) },
    { UINT64_C( 6825115119568069170),
      UINT64_C( 3412557559784034585),
      UINT64_C(     833143935494149),
      UINT64_C(        813617124506),
      UINT64_C(            49659248),
      UINT64_C(               96990),
      UINT64_C(                 189),
      UINT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r1 = simde_vshrd_n_u64(test_vec[i].a, 1);
    uint64_t r13 = simde_vshrd_n_u64(test_vec[i].a, 13);
    uint64_t r23 = simde_vshrd_n_u64(test_vec[i].a, 23);
    uint64_t r37 = simde_vshrd_n_u64(test_vec[i].a, 37);
    uint64_t r46 = simde_vshrd_n_u64(test_vec[i].a, 46);
    uint64_t r55 = simde_vshrd_n_u64(test_vec[i].a, 55);
    uint64_t r64 = simde_vshrd_n_u64(test_vec[i].a, 64);

    simde_assert_equal_u64(r1, test_vec[i].r1);
    simde_assert_equal_u64(r13, test_vec[i].r13);
    simde_assert_equal_u64(r23, test_vec[i].r23);
    simde_assert_equal_u64(r37, test_vec[i].r37);
    simde_assert_equal_u64(r46, test_vec[i].r46);
    simde_assert_equal_u64(r55, test_vec[i].r55);
    simde_assert_equal_u64(r64, test_vec[i].r64);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t r1 = simde_vshrd_n_u64(a, 1);
    uint64_t r13 = simde_vshrd_n_u64(a, 13);
    uint64_t r23 = simde_vshrd_n_u64(a, 23);
    uint64_t r37 = simde_vshrd_n_u64(a, 37);
    uint64_t r46 = simde_vshrd_n_u64(a, 46);
    uint64_t r55 = simde_vshrd_n_u64(a, 55);
    uint64_t r64 = simde_vshrd_n_u64(a, 64);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r37, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r46, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vshr_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshr_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshr_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshr_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vshr_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshr_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshr_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshr_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vshrq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrq_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrq_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrq_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrq_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vshrd_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vshrd_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
