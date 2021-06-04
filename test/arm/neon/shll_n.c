#define SIMDE_TEST_ARM_NEON_INSN shll_n

#include "test-neon.h"
#include "../../../simde/arm/neon/shll_n.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vshll_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int16_t r0[8];
    int16_t r1[8];
    int16_t r3[8];
    int16_t r5[8];
    int16_t r6[8];
    int16_t r7[8];
  } test_vec[] = {
    { {  INT8_C(  91), -INT8_C(  61), -INT8_C(  18), -INT8_C(  52),  INT8_C(  14),  INT8_C(  34), -INT8_C(  19), -INT8_C( 117) },
      {  INT16_C(    91), -INT16_C(    61), -INT16_C(    18), -INT16_C(    52),  INT16_C(    14),  INT16_C(    34), -INT16_C(    19), -INT16_C(   117) },
      {  INT16_C(   182), -INT16_C(   122), -INT16_C(    36), -INT16_C(   104),  INT16_C(    28),  INT16_C(    68), -INT16_C(    38), -INT16_C(   234) },
      {  INT16_C(   728), -INT16_C(   488), -INT16_C(   144), -INT16_C(   416),  INT16_C(   112),  INT16_C(   272), -INT16_C(   152), -INT16_C(   936) },
      {  INT16_C(  2912), -INT16_C(  1952), -INT16_C(   576), -INT16_C(  1664),  INT16_C(   448),  INT16_C(  1088), -INT16_C(   608), -INT16_C(  3744) },
      {  INT16_C(  5824), -INT16_C(  3904), -INT16_C(  1152), -INT16_C(  3328),  INT16_C(   896),  INT16_C(  2176), -INT16_C(  1216), -INT16_C(  7488) },
      {  INT16_C( 11648), -INT16_C(  7808), -INT16_C(  2304), -INT16_C(  6656),  INT16_C(  1792),  INT16_C(  4352), -INT16_C(  2432), -INT16_C( 14976) } },
    { { -INT8_C( 120), -INT8_C(  18), -INT8_C( 101),  INT8_C(   5), -INT8_C(  46), -INT8_C(  83), -INT8_C(   9),  INT8_C(  42) },
      { -INT16_C(   120), -INT16_C(    18), -INT16_C(   101),  INT16_C(     5), -INT16_C(    46), -INT16_C(    83), -INT16_C(     9),  INT16_C(    42) },
      { -INT16_C(   240), -INT16_C(    36), -INT16_C(   202),  INT16_C(    10), -INT16_C(    92), -INT16_C(   166), -INT16_C(    18),  INT16_C(    84) },
      { -INT16_C(   960), -INT16_C(   144), -INT16_C(   808),  INT16_C(    40), -INT16_C(   368), -INT16_C(   664), -INT16_C(    72),  INT16_C(   336) },
      { -INT16_C(  3840), -INT16_C(   576), -INT16_C(  3232),  INT16_C(   160), -INT16_C(  1472), -INT16_C(  2656), -INT16_C(   288),  INT16_C(  1344) },
      { -INT16_C(  7680), -INT16_C(  1152), -INT16_C(  6464),  INT16_C(   320), -INT16_C(  2944), -INT16_C(  5312), -INT16_C(   576),  INT16_C(  2688) },
      { -INT16_C( 15360), -INT16_C(  2304), -INT16_C( 12928),  INT16_C(   640), -INT16_C(  5888), -INT16_C( 10624), -INT16_C(  1152),  INT16_C(  5376) } },
    { {  INT8_C(   9),  INT8_C(   7), -INT8_C(  65), -INT8_C(  16),  INT8_C(   2),  INT8_C(  62),  INT8_C(  37),  INT8_C(  79) },
      {  INT16_C(     9),  INT16_C(     7), -INT16_C(    65), -INT16_C(    16),  INT16_C(     2),  INT16_C(    62),  INT16_C(    37),  INT16_C(    79) },
      {  INT16_C(    18),  INT16_C(    14), -INT16_C(   130), -INT16_C(    32),  INT16_C(     4),  INT16_C(   124),  INT16_C(    74),  INT16_C(   158) },
      {  INT16_C(    72),  INT16_C(    56), -INT16_C(   520), -INT16_C(   128),  INT16_C(    16),  INT16_C(   496),  INT16_C(   296),  INT16_C(   632) },
      {  INT16_C(   288),  INT16_C(   224), -INT16_C(  2080), -INT16_C(   512),  INT16_C(    64),  INT16_C(  1984),  INT16_C(  1184),  INT16_C(  2528) },
      {  INT16_C(   576),  INT16_C(   448), -INT16_C(  4160), -INT16_C(  1024),  INT16_C(   128),  INT16_C(  3968),  INT16_C(  2368),  INT16_C(  5056) },
      {  INT16_C(  1152),  INT16_C(   896), -INT16_C(  8320), -INT16_C(  2048),  INT16_C(   256),  INT16_C(  7936),  INT16_C(  4736),  INT16_C( 10112) } },
    { {  INT8_C(  23), -INT8_C( 120),  INT8_C(   5),  INT8_C(  56),  INT8_C(  58), -INT8_C( 105), -INT8_C(  16), -INT8_C( 107) },
      {  INT16_C(    23), -INT16_C(   120),  INT16_C(     5),  INT16_C(    56),  INT16_C(    58), -INT16_C(   105), -INT16_C(    16), -INT16_C(   107) },
      {  INT16_C(    46), -INT16_C(   240),  INT16_C(    10),  INT16_C(   112),  INT16_C(   116), -INT16_C(   210), -INT16_C(    32), -INT16_C(   214) },
      {  INT16_C(   184), -INT16_C(   960),  INT16_C(    40),  INT16_C(   448),  INT16_C(   464), -INT16_C(   840), -INT16_C(   128), -INT16_C(   856) },
      {  INT16_C(   736), -INT16_C(  3840),  INT16_C(   160),  INT16_C(  1792),  INT16_C(  1856), -INT16_C(  3360), -INT16_C(   512), -INT16_C(  3424) },
      {  INT16_C(  1472), -INT16_C(  7680),  INT16_C(   320),  INT16_C(  3584),  INT16_C(  3712), -INT16_C(  6720), -INT16_C(  1024), -INT16_C(  6848) },
      {  INT16_C(  2944), -INT16_C( 15360),  INT16_C(   640),  INT16_C(  7168),  INT16_C(  7424), -INT16_C( 13440), -INT16_C(  2048), -INT16_C( 13696) } },
    { {  INT8_C(  90), -INT8_C(  34),  INT8_C(  98),  INT8_C( 104),  INT8_C(   0),  INT8_C(  79), -INT8_C(  12), -INT8_C( 120) },
      {  INT16_C(    90), -INT16_C(    34),  INT16_C(    98),  INT16_C(   104),  INT16_C(     0),  INT16_C(    79), -INT16_C(    12), -INT16_C(   120) },
      {  INT16_C(   180), -INT16_C(    68),  INT16_C(   196),  INT16_C(   208),  INT16_C(     0),  INT16_C(   158), -INT16_C(    24), -INT16_C(   240) },
      {  INT16_C(   720), -INT16_C(   272),  INT16_C(   784),  INT16_C(   832),  INT16_C(     0),  INT16_C(   632), -INT16_C(    96), -INT16_C(   960) },
      {  INT16_C(  2880), -INT16_C(  1088),  INT16_C(  3136),  INT16_C(  3328),  INT16_C(     0),  INT16_C(  2528), -INT16_C(   384), -INT16_C(  3840) },
      {  INT16_C(  5760), -INT16_C(  2176),  INT16_C(  6272),  INT16_C(  6656),  INT16_C(     0),  INT16_C(  5056), -INT16_C(   768), -INT16_C(  7680) },
      {  INT16_C( 11520), -INT16_C(  4352),  INT16_C( 12544),  INT16_C( 13312),  INT16_C(     0),  INT16_C( 10112), -INT16_C(  1536), -INT16_C( 15360) } },
    { {  INT8_C(  61), -INT8_C( 113), -INT8_C( 115),  INT8_C(  15),  INT8_C(  60), -INT8_C( 124),  INT8_C(  58),  INT8_C(  70) },
      {  INT16_C(    61), -INT16_C(   113), -INT16_C(   115),  INT16_C(    15),  INT16_C(    60), -INT16_C(   124),  INT16_C(    58),  INT16_C(    70) },
      {  INT16_C(   122), -INT16_C(   226), -INT16_C(   230),  INT16_C(    30),  INT16_C(   120), -INT16_C(   248),  INT16_C(   116),  INT16_C(   140) },
      {  INT16_C(   488), -INT16_C(   904), -INT16_C(   920),  INT16_C(   120),  INT16_C(   480), -INT16_C(   992),  INT16_C(   464),  INT16_C(   560) },
      {  INT16_C(  1952), -INT16_C(  3616), -INT16_C(  3680),  INT16_C(   480),  INT16_C(  1920), -INT16_C(  3968),  INT16_C(  1856),  INT16_C(  2240) },
      {  INT16_C(  3904), -INT16_C(  7232), -INT16_C(  7360),  INT16_C(   960),  INT16_C(  3840), -INT16_C(  7936),  INT16_C(  3712),  INT16_C(  4480) },
      {  INT16_C(  7808), -INT16_C( 14464), -INT16_C( 14720),  INT16_C(  1920),  INT16_C(  7680), -INT16_C( 15872),  INT16_C(  7424),  INT16_C(  8960) } },
    { { -INT8_C( 117), -INT8_C(   7),  INT8_C(  54), -INT8_C( 114),  INT8_C(  55),  INT8_C(  91), -INT8_C(  35),  INT8_C(  79) },
      { -INT16_C(   117), -INT16_C(     7),  INT16_C(    54), -INT16_C(   114),  INT16_C(    55),  INT16_C(    91), -INT16_C(    35),  INT16_C(    79) },
      { -INT16_C(   234), -INT16_C(    14),  INT16_C(   108), -INT16_C(   228),  INT16_C(   110),  INT16_C(   182), -INT16_C(    70),  INT16_C(   158) },
      { -INT16_C(   936), -INT16_C(    56),  INT16_C(   432), -INT16_C(   912),  INT16_C(   440),  INT16_C(   728), -INT16_C(   280),  INT16_C(   632) },
      { -INT16_C(  3744), -INT16_C(   224),  INT16_C(  1728), -INT16_C(  3648),  INT16_C(  1760),  INT16_C(  2912), -INT16_C(  1120),  INT16_C(  2528) },
      { -INT16_C(  7488), -INT16_C(   448),  INT16_C(  3456), -INT16_C(  7296),  INT16_C(  3520),  INT16_C(  5824), -INT16_C(  2240),  INT16_C(  5056) },
      { -INT16_C( 14976), -INT16_C(   896),  INT16_C(  6912), -INT16_C( 14592),  INT16_C(  7040),  INT16_C( 11648), -INT16_C(  4480),  INT16_C( 10112) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int16x8_t r0 = simde_vshll_n_s8(a, 0);
    simde_int16x8_t r1 = simde_vshll_n_s8(a, 1);
    simde_int16x8_t r3 = simde_vshll_n_s8(a, 3);
    simde_int16x8_t r5 = simde_vshll_n_s8(a, 5);
    simde_int16x8_t r6 = simde_vshll_n_s8(a, 6);
    simde_int16x8_t r7 = simde_vshll_n_s8(a, 7);

    simde_test_arm_neon_assert_equal_i16x8(r0, simde_vld1q_s16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i16x8(r1, simde_vld1q_s16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r5, simde_vld1q_s16(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r7, simde_vld1q_s16(test_vec[i].r7));
  }

  return 0;
#else
  for (int i = 1 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t r0 = simde_vshll_n_s8(a, 0);
    simde_int16x8_t r1 = simde_vshll_n_s8(a, 1);
    simde_int16x8_t r3 = simde_vshll_n_s8(a, 3);
    simde_int16x8_t r5 = simde_vshll_n_s8(a, 5);
    simde_int16x8_t r6 = simde_vshll_n_s8(a, 6);
    simde_int16x8_t r7 = simde_vshll_n_s8(a, 7);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int32_t r3[4];
    int32_t r6[4];
    int32_t r10[4];
    int32_t r13[4];
    int32_t r15[4];
  } test_vec[] = {
    { { -INT16_C( 16425), -INT16_C( 17625),  INT16_C( 19833), -INT16_C( 29566) },
      { -INT32_C(      131400), -INT32_C(      141000),  INT32_C(      158664), -INT32_C(      236528) },
      { -INT32_C(     1051200), -INT32_C(     1128000),  INT32_C(     1269312), -INT32_C(     1892224) },
      { -INT32_C(    16819200), -INT32_C(    18048000),  INT32_C(    20308992), -INT32_C(    30275584) },
      { -INT32_C(   134553600), -INT32_C(   144384000),  INT32_C(   162471936), -INT32_C(   242204672) },
      { -INT32_C(   538214400), -INT32_C(   577536000),  INT32_C(   649887744), -INT32_C(   968818688) } },
    { { -INT16_C( 23356),  INT16_C( 16332), -INT16_C( 29218),  INT16_C(  9163) },
      { -INT32_C(      186848),  INT32_C(      130656), -INT32_C(      233744),  INT32_C(       73304) },
      { -INT32_C(     1494784),  INT32_C(     1045248), -INT32_C(     1869952),  INT32_C(      586432) },
      { -INT32_C(    23916544),  INT32_C(    16723968), -INT32_C(    29919232),  INT32_C(     9382912) },
      { -INT32_C(   191332352),  INT32_C(   133791744), -INT32_C(   239353856),  INT32_C(    75063296) },
      { -INT32_C(   765329408),  INT32_C(   535166976), -INT32_C(   957415424),  INT32_C(   300253184) } },
    { {  INT16_C( 10258),  INT16_C(  6440), -INT16_C( 19281),  INT16_C( 26681) },
      {  INT32_C(       82064),  INT32_C(       51520), -INT32_C(      154248),  INT32_C(      213448) },
      {  INT32_C(      656512),  INT32_C(      412160), -INT32_C(     1233984),  INT32_C(     1707584) },
      {  INT32_C(    10504192),  INT32_C(     6594560), -INT32_C(    19743744),  INT32_C(    27321344) },
      {  INT32_C(    84033536),  INT32_C(    52756480), -INT32_C(   157949952),  INT32_C(   218570752) },
      {  INT32_C(   336134144),  INT32_C(   211025920), -INT32_C(   631799808),  INT32_C(   874283008) } },
    { { -INT16_C(  7477), -INT16_C( 22652), -INT16_C( 10993), -INT16_C(  6485) },
      { -INT32_C(       59816), -INT32_C(      181216), -INT32_C(       87944), -INT32_C(       51880) },
      { -INT32_C(      478528), -INT32_C(     1449728), -INT32_C(      703552), -INT32_C(      415040) },
      { -INT32_C(     7656448), -INT32_C(    23195648), -INT32_C(    11256832), -INT32_C(     6640640) },
      { -INT32_C(    61251584), -INT32_C(   185565184), -INT32_C(    90054656), -INT32_C(    53125120) },
      { -INT32_C(   245006336), -INT32_C(   742260736), -INT32_C(   360218624), -INT32_C(   212500480) } },
    { { -INT16_C( 11628),  INT16_C(  3489),  INT16_C(  8991), -INT16_C(  7270) },
      { -INT32_C(       93024),  INT32_C(       27912),  INT32_C(       71928), -INT32_C(       58160) },
      { -INT32_C(      744192),  INT32_C(      223296),  INT32_C(      575424), -INT32_C(      465280) },
      { -INT32_C(    11907072),  INT32_C(     3572736),  INT32_C(     9206784), -INT32_C(     7444480) },
      { -INT32_C(    95256576),  INT32_C(    28581888),  INT32_C(    73654272), -INT32_C(    59555840) },
      { -INT32_C(   381026304),  INT32_C(   114327552),  INT32_C(   294617088), -INT32_C(   238223360) } },
    { {  INT16_C( 26311), -INT16_C( 23006), -INT16_C(  4621),  INT16_C(  1481) },
      {  INT32_C(      210488), -INT32_C(      184048), -INT32_C(       36968),  INT32_C(       11848) },
      {  INT32_C(     1683904), -INT32_C(     1472384), -INT32_C(      295744),  INT32_C(       94784) },
      {  INT32_C(    26942464), -INT32_C(    23558144), -INT32_C(     4731904),  INT32_C(     1516544) },
      {  INT32_C(   215539712), -INT32_C(   188465152), -INT32_C(    37855232),  INT32_C(    12132352) },
      {  INT32_C(   862158848), -INT32_C(   753860608), -INT32_C(   151420928),  INT32_C(    48529408) } },
    { { -INT16_C(  3819), -INT16_C( 15073),  INT16_C( 22694),  INT16_C( 28973) },
      { -INT32_C(       30552), -INT32_C(      120584),  INT32_C(      181552),  INT32_C(      231784) },
      { -INT32_C(      244416), -INT32_C(      964672),  INT32_C(     1452416),  INT32_C(     1854272) },
      { -INT32_C(     3910656), -INT32_C(    15434752),  INT32_C(    23238656),  INT32_C(    29668352) },
      { -INT32_C(    31285248), -INT32_C(   123478016),  INT32_C(   185909248),  INT32_C(   237346816) },
      { -INT32_C(   125140992), -INT32_C(   493912064),  INT32_C(   743636992),  INT32_C(   949387264) } },
  };

  for (size_t i = 1 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int32x4_t r3 = simde_vshll_n_s16(a, 3);
    simde_int32x4_t r6 = simde_vshll_n_s16(a, 6);
    simde_int32x4_t r10 = simde_vshll_n_s16(a, 10);
    simde_int32x4_t r13 = simde_vshll_n_s16(a, 13);
    simde_int32x4_t r15 = simde_vshll_n_s16(a, 15);

    simde_test_arm_neon_assert_equal_i32x4(r3, simde_vld1q_s32(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r10, simde_vld1q_s32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r15, simde_vld1q_s32(test_vec[i].r15));
  }

  return 0;
#else
  for (int i = 1 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t r3 = simde_vshll_n_s16(a, 3);
    simde_int32x4_t r6 = simde_vshll_n_s16(a, 6);
    simde_int32x4_t r10 = simde_vshll_n_s16(a, 10);
    simde_int32x4_t r13 = simde_vshll_n_s16(a, 13);
    simde_int32x4_t r15 = simde_vshll_n_s16(a, 15);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int64_t r6[2];
    int64_t r13[2];
    int64_t r19[2];
    int64_t r26[2];
    int64_t r31[2];
  } test_vec[] = {
    { {  INT32_C(   950429293), -INT32_C(   661372014) },
      {  INT64_C(         60827474752), -INT64_C(         42327808896) },
      {  INT64_C(       7785916768256), -INT64_C(       5417959538688) },
      {  INT64_C(     498298673168384), -INT64_C(     346749410476032) },
      {  INT64_C(   63782230165553152), -INT64_C(   44383924540932096) },
      {  INT64_C( 2041031365297700864), -INT64_C( 1420285585309827072) } },
    { {  INT32_C(  1589323003),  INT32_C(    86315474) },
      {  INT64_C(        101716672192),  INT64_C(          5524190336) },
      {  INT64_C(      13019734040576),  INT64_C(        707096363008) },
      {  INT64_C(     833262978596864),  INT64_C(      45254167232512) },
      {  INT64_C(  106657661260398592),  INT64_C(    5792533405761536) },
      {  INT64_C( 3413045160332754944),  INT64_C(  185361068984369152) } },
    { {  INT32_C(   855451097), -INT32_C(  1981432844) },
      {  INT64_C(         54748870208), -INT64_C(        126811702016) },
      {  INT64_C(       7007855386624), -INT64_C(      16231897858048) },
      {  INT64_C(     448502744743936), -INT64_C(    1038841462915072) },
      {  INT64_C(   57408351327223808), -INT64_C(  132971707253129216) },
      {  INT64_C( 1837067242471161856), -INT64_C( 4255094632100134912) } },
    { {  INT32_C(   478615849),  INT32_C(   217270687) },
      {  INT64_C(         30631414336),  INT64_C(         13905323968) },
      {  INT64_C(       3920821035008),  INT64_C(       1779881467904) },
      {  INT64_C(     250932546240512),  INT64_C(     113912413945856) },
      {  INT64_C(   32119365918785536),  INT64_C(   14580788985069568) },
      {  INT64_C( 1027819709401137152),  INT64_C(  466585247522226176) } },
    { {  INT32_C(  1111857584), -INT32_C(   669263395) },
      {  INT64_C(         71158885376), -INT64_C(         42832857280) },
      {  INT64_C(       9108337328128), -INT64_C(       5482605731840) },
      {  INT64_C(     582933589000192), -INT64_C(     350886766837760) },
      {  INT64_C(   74615499392024576), -INT64_C(   44913506155233280) },
      {  INT64_C( 2387695980544786432), -INT64_C( 1437232196967464960) } },
    { { -INT32_C(   818489603), -INT32_C(  1043047448) },
      { -INT64_C(         52383334592), -INT64_C(         66755036672) },
      { -INT64_C(       6705066827776), -INT64_C(       8544644694016) },
      { -INT64_C(     429124276977664), -INT64_C(     546857260417024) },
      { -INT64_C(   54927907453140992), -INT64_C(   69997729333379072) },
      { -INT64_C( 1757693038500511744), -INT64_C( 2239927338668130304) } },
    { {  INT32_C(  1978913152), -INT32_C(  1224812403) },
      {  INT64_C(        126650441728), -INT64_C(         78387993792) },
      {  INT64_C(      16211256541184), -INT64_C(      10033663205376) },
      {  INT64_C(    1037520418635776), -INT64_C(     642154445144064) },
      {  INT64_C(  132802613585379328), -INT64_C(   82195768978440192) },
      {  INT64_C( 4249683634732138496), -INT64_C( 2630264607310086144) } },
    { { -INT32_C(  1865251343),  INT32_C(  2141046223) },
      { -INT64_C(        119376085952),  INT64_C(        137026958272) },
      { -INT64_C(      15280139001856),  INT64_C(      17539450658816) },
      { -INT64_C(     977928896118784),  INT64_C(    1122524842164224) },
      { -INT64_C(  125174898703204352),  INT64_C(  143683179797020672) },
      { -INT64_C( 4005596758502539264),  INT64_C( 4597861753504661504) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int64x2_t r6 = simde_vshll_n_s32(a, 6);
    simde_int64x2_t r13 = simde_vshll_n_s32(a, 13);
    simde_int64x2_t r19 = simde_vshll_n_s32(a, 19);
    simde_int64x2_t r26 = simde_vshll_n_s32(a, 26);
    simde_int64x2_t r31 = simde_vshll_n_s32(a, 31);

    simde_test_arm_neon_assert_equal_i64x2(r6, simde_vld1q_s64(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r19, simde_vld1q_s64(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r31, simde_vld1q_s64(test_vec[i].r31));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t r6 = simde_vshll_n_s32(a, 6);
    simde_int64x2_t r13 = simde_vshll_n_s32(a, 13);
    simde_int64x2_t r19 = simde_vshll_n_s32(a, 19);
    simde_int64x2_t r26 = simde_vshll_n_s32(a, 26);
    simde_int64x2_t r31 = simde_vshll_n_s32(a, 31);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint16_t r1[8];
    uint16_t r3[8];
    uint16_t r5[8];
    uint16_t r6[8];
    uint16_t r7[8];
  } test_vec[] = {
    { { UINT8_C(246), UINT8_C(145), UINT8_C(126), UINT8_C(115), UINT8_C(134), UINT8_C( 86), UINT8_C(120), UINT8_C(171) },
      { UINT16_C(  492), UINT16_C(  290), UINT16_C(  252), UINT16_C(  230), UINT16_C(  268), UINT16_C(  172), UINT16_C(  240), UINT16_C(  342) },
      { UINT16_C( 1968), UINT16_C( 1160), UINT16_C( 1008), UINT16_C(  920), UINT16_C( 1072), UINT16_C(  688), UINT16_C(  960), UINT16_C( 1368) },
      { UINT16_C( 7872), UINT16_C( 4640), UINT16_C( 4032), UINT16_C( 3680), UINT16_C( 4288), UINT16_C( 2752), UINT16_C( 3840), UINT16_C( 5472) },
      { UINT16_C(15744), UINT16_C( 9280), UINT16_C( 8064), UINT16_C( 7360), UINT16_C( 8576), UINT16_C( 5504), UINT16_C( 7680), UINT16_C(10944) },
      { UINT16_C(31488), UINT16_C(18560), UINT16_C(16128), UINT16_C(14720), UINT16_C(17152), UINT16_C(11008), UINT16_C(15360), UINT16_C(21888) } },
    { { UINT8_C(219), UINT8_C( 52), UINT8_C(252), UINT8_C( 39), UINT8_C(171), UINT8_C(183), UINT8_C( 80), UINT8_C(207) },
      { UINT16_C(  438), UINT16_C(  104), UINT16_C(  504), UINT16_C(   78), UINT16_C(  342), UINT16_C(  366), UINT16_C(  160), UINT16_C(  414) },
      { UINT16_C( 1752), UINT16_C(  416), UINT16_C( 2016), UINT16_C(  312), UINT16_C( 1368), UINT16_C( 1464), UINT16_C(  640), UINT16_C( 1656) },
      { UINT16_C( 7008), UINT16_C( 1664), UINT16_C( 8064), UINT16_C( 1248), UINT16_C( 5472), UINT16_C( 5856), UINT16_C( 2560), UINT16_C( 6624) },
      { UINT16_C(14016), UINT16_C( 3328), UINT16_C(16128), UINT16_C( 2496), UINT16_C(10944), UINT16_C(11712), UINT16_C( 5120), UINT16_C(13248) },
      { UINT16_C(28032), UINT16_C( 6656), UINT16_C(32256), UINT16_C( 4992), UINT16_C(21888), UINT16_C(23424), UINT16_C(10240), UINT16_C(26496) } },
    { { UINT8_C(175), UINT8_C(179), UINT8_C( 48), UINT8_C(  9), UINT8_C(110), UINT8_C(240), UINT8_C(197), UINT8_C(131) },
      { UINT16_C(  350), UINT16_C(  358), UINT16_C(   96), UINT16_C(   18), UINT16_C(  220), UINT16_C(  480), UINT16_C(  394), UINT16_C(  262) },
      { UINT16_C( 1400), UINT16_C( 1432), UINT16_C(  384), UINT16_C(   72), UINT16_C(  880), UINT16_C( 1920), UINT16_C( 1576), UINT16_C( 1048) },
      { UINT16_C( 5600), UINT16_C( 5728), UINT16_C( 1536), UINT16_C(  288), UINT16_C( 3520), UINT16_C( 7680), UINT16_C( 6304), UINT16_C( 4192) },
      { UINT16_C(11200), UINT16_C(11456), UINT16_C( 3072), UINT16_C(  576), UINT16_C( 7040), UINT16_C(15360), UINT16_C(12608), UINT16_C( 8384) },
      { UINT16_C(22400), UINT16_C(22912), UINT16_C( 6144), UINT16_C( 1152), UINT16_C(14080), UINT16_C(30720), UINT16_C(25216), UINT16_C(16768) } },
    { { UINT8_C( 10), UINT8_C(140), UINT8_C(195), UINT8_C( 96), UINT8_C(201), UINT8_C(111), UINT8_C(166), UINT8_C(191) },
      { UINT16_C(   20), UINT16_C(  280), UINT16_C(  390), UINT16_C(  192), UINT16_C(  402), UINT16_C(  222), UINT16_C(  332), UINT16_C(  382) },
      { UINT16_C(   80), UINT16_C( 1120), UINT16_C( 1560), UINT16_C(  768), UINT16_C( 1608), UINT16_C(  888), UINT16_C( 1328), UINT16_C( 1528) },
      { UINT16_C(  320), UINT16_C( 4480), UINT16_C( 6240), UINT16_C( 3072), UINT16_C( 6432), UINT16_C( 3552), UINT16_C( 5312), UINT16_C( 6112) },
      { UINT16_C(  640), UINT16_C( 8960), UINT16_C(12480), UINT16_C( 6144), UINT16_C(12864), UINT16_C( 7104), UINT16_C(10624), UINT16_C(12224) },
      { UINT16_C( 1280), UINT16_C(17920), UINT16_C(24960), UINT16_C(12288), UINT16_C(25728), UINT16_C(14208), UINT16_C(21248), UINT16_C(24448) } },
    { { UINT8_C(  0), UINT8_C( 36), UINT8_C( 51), UINT8_C(134), UINT8_C(123), UINT8_C(171), UINT8_C( 50), UINT8_C( 86) },
      { UINT16_C(    0), UINT16_C(   72), UINT16_C(  102), UINT16_C(  268), UINT16_C(  246), UINT16_C(  342), UINT16_C(  100), UINT16_C(  172) },
      { UINT16_C(    0), UINT16_C(  288), UINT16_C(  408), UINT16_C( 1072), UINT16_C(  984), UINT16_C( 1368), UINT16_C(  400), UINT16_C(  688) },
      { UINT16_C(    0), UINT16_C( 1152), UINT16_C( 1632), UINT16_C( 4288), UINT16_C( 3936), UINT16_C( 5472), UINT16_C( 1600), UINT16_C( 2752) },
      { UINT16_C(    0), UINT16_C( 2304), UINT16_C( 3264), UINT16_C( 8576), UINT16_C( 7872), UINT16_C(10944), UINT16_C( 3200), UINT16_C( 5504) },
      { UINT16_C(    0), UINT16_C( 4608), UINT16_C( 6528), UINT16_C(17152), UINT16_C(15744), UINT16_C(21888), UINT16_C( 6400), UINT16_C(11008) } },
    { { UINT8_C(223), UINT8_C( 46), UINT8_C(125), UINT8_C(139), UINT8_C(229), UINT8_C(205), UINT8_C( 90), UINT8_C(149) },
      { UINT16_C(  446), UINT16_C(   92), UINT16_C(  250), UINT16_C(  278), UINT16_C(  458), UINT16_C(  410), UINT16_C(  180), UINT16_C(  298) },
      { UINT16_C( 1784), UINT16_C(  368), UINT16_C( 1000), UINT16_C( 1112), UINT16_C( 1832), UINT16_C( 1640), UINT16_C(  720), UINT16_C( 1192) },
      { UINT16_C( 7136), UINT16_C( 1472), UINT16_C( 4000), UINT16_C( 4448), UINT16_C( 7328), UINT16_C( 6560), UINT16_C( 2880), UINT16_C( 4768) },
      { UINT16_C(14272), UINT16_C( 2944), UINT16_C( 8000), UINT16_C( 8896), UINT16_C(14656), UINT16_C(13120), UINT16_C( 5760), UINT16_C( 9536) },
      { UINT16_C(28544), UINT16_C( 5888), UINT16_C(16000), UINT16_C(17792), UINT16_C(29312), UINT16_C(26240), UINT16_C(11520), UINT16_C(19072) } },
    { { UINT8_C(128), UINT8_C(138), UINT8_C(158), UINT8_C(239), UINT8_C(122), UINT8_C( 99), UINT8_C(114), UINT8_C(133) },
      { UINT16_C(  256), UINT16_C(  276), UINT16_C(  316), UINT16_C(  478), UINT16_C(  244), UINT16_C(  198), UINT16_C(  228), UINT16_C(  266) },
      { UINT16_C( 1024), UINT16_C( 1104), UINT16_C( 1264), UINT16_C( 1912), UINT16_C(  976), UINT16_C(  792), UINT16_C(  912), UINT16_C( 1064) },
      { UINT16_C( 4096), UINT16_C( 4416), UINT16_C( 5056), UINT16_C( 7648), UINT16_C( 3904), UINT16_C( 3168), UINT16_C( 3648), UINT16_C( 4256) },
      { UINT16_C( 8192), UINT16_C( 8832), UINT16_C(10112), UINT16_C(15296), UINT16_C( 7808), UINT16_C( 6336), UINT16_C( 7296), UINT16_C( 8512) },
      { UINT16_C(16384), UINT16_C(17664), UINT16_C(20224), UINT16_C(30592), UINT16_C(15616), UINT16_C(12672), UINT16_C(14592), UINT16_C(17024) } },
  };

  for (size_t i = 1 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint16x8_t r1 = simde_vshll_n_u8(a, 1);
    simde_uint16x8_t r3 = simde_vshll_n_u8(a, 3);
    simde_uint16x8_t r5 = simde_vshll_n_u8(a, 5);
    simde_uint16x8_t r6 = simde_vshll_n_u8(a, 6);
    simde_uint16x8_t r7 = simde_vshll_n_u8(a, 7);

    simde_test_arm_neon_assert_equal_u16x8(r1, simde_vld1q_u16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r5, simde_vld1q_u16(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r7, simde_vld1q_u16(test_vec[i].r7));
  }

  return 0;
#else
  for (int i = 1 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t r1 = simde_vshll_n_u8(a, 1);
    simde_uint16x8_t r3 = simde_vshll_n_u8(a, 3);
    simde_uint16x8_t r5 = simde_vshll_n_u8(a, 5);
    simde_uint16x8_t r6 = simde_vshll_n_u8(a, 6);
    simde_uint16x8_t r7 = simde_vshll_n_u8(a, 7);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint32_t r3[4];
    uint32_t r6[4];
    uint32_t r10[4];
    uint32_t r13[4];
    uint32_t r15[4];
  } test_vec[] = {
    { { UINT16_C(28903), UINT16_C( 4536), UINT16_C(57309), UINT16_C(47082) },
      { UINT32_C(    231224), UINT32_C(     36288), UINT32_C(    458472), UINT32_C(    376656) },
      { UINT32_C(   1849792), UINT32_C(    290304), UINT32_C(   3667776), UINT32_C(   3013248) },
      { UINT32_C(  29596672), UINT32_C(   4644864), UINT32_C(  58684416), UINT32_C(  48211968) },
      { UINT32_C( 236773376), UINT32_C(  37158912), UINT32_C( 469475328), UINT32_C( 385695744) },
      { UINT32_C( 947093504), UINT32_C( 148635648), UINT32_C(1877901312), UINT32_C(1542782976) } },
    { { UINT16_C(20626), UINT16_C(43076), UINT16_C(52517), UINT16_C(52086) },
      { UINT32_C(    165008), UINT32_C(    344608), UINT32_C(    420136), UINT32_C(    416688) },
      { UINT32_C(   1320064), UINT32_C(   2756864), UINT32_C(   3361088), UINT32_C(   3333504) },
      { UINT32_C(  21121024), UINT32_C(  44109824), UINT32_C(  53777408), UINT32_C(  53336064) },
      { UINT32_C( 168968192), UINT32_C( 352878592), UINT32_C( 430219264), UINT32_C( 426688512) },
      { UINT32_C( 675872768), UINT32_C(1411514368), UINT32_C(1720877056), UINT32_C(1706754048) } },
    { { UINT16_C(31758), UINT16_C(51303), UINT16_C(54820), UINT16_C(59119) },
      { UINT32_C(    254064), UINT32_C(    410424), UINT32_C(    438560), UINT32_C(    472952) },
      { UINT32_C(   2032512), UINT32_C(   3283392), UINT32_C(   3508480), UINT32_C(   3783616) },
      { UINT32_C(  32520192), UINT32_C(  52534272), UINT32_C(  56135680), UINT32_C(  60537856) },
      { UINT32_C( 260161536), UINT32_C( 420274176), UINT32_C( 449085440), UINT32_C( 484302848) },
      { UINT32_C(1040646144), UINT32_C(1681096704), UINT32_C(1796341760), UINT32_C(1937211392) } },
    { { UINT16_C(10599), UINT16_C(45769), UINT16_C(46438), UINT16_C(19779) },
      { UINT32_C(     84792), UINT32_C(    366152), UINT32_C(    371504), UINT32_C(    158232) },
      { UINT32_C(    678336), UINT32_C(   2929216), UINT32_C(   2972032), UINT32_C(   1265856) },
      { UINT32_C(  10853376), UINT32_C(  46867456), UINT32_C(  47552512), UINT32_C(  20253696) },
      { UINT32_C(  86827008), UINT32_C( 374939648), UINT32_C( 380420096), UINT32_C( 162029568) },
      { UINT32_C( 347308032), UINT32_C(1499758592), UINT32_C(1521680384), UINT32_C( 648118272) } },
    { { UINT16_C(64294), UINT16_C(  863), UINT16_C(18906), UINT16_C(28091) },
      { UINT32_C(    514352), UINT32_C(      6904), UINT32_C(    151248), UINT32_C(    224728) },
      { UINT32_C(   4114816), UINT32_C(     55232), UINT32_C(   1209984), UINT32_C(   1797824) },
      { UINT32_C(  65837056), UINT32_C(    883712), UINT32_C(  19359744), UINT32_C(  28765184) },
      { UINT32_C( 526696448), UINT32_C(   7069696), UINT32_C( 154877952), UINT32_C( 230121472) },
      { UINT32_C(2106785792), UINT32_C(  28278784), UINT32_C( 619511808), UINT32_C( 920485888) } },
    { { UINT16_C(65434), UINT16_C(48917), UINT16_C(35788), UINT16_C(55946) },
      { UINT32_C(    523472), UINT32_C(    391336), UINT32_C(    286304), UINT32_C(    447568) },
      { UINT32_C(   4187776), UINT32_C(   3130688), UINT32_C(   2290432), UINT32_C(   3580544) },
      { UINT32_C(  67004416), UINT32_C(  50091008), UINT32_C(  36646912), UINT32_C(  57288704) },
      { UINT32_C( 536035328), UINT32_C( 400728064), UINT32_C( 293175296), UINT32_C( 458309632) },
      { UINT32_C(2144141312), UINT32_C(1602912256), UINT32_C(1172701184), UINT32_C(1833238528) } },
    { { UINT16_C(61703), UINT16_C(11170), UINT16_C(37319), UINT16_C(11793) },
      { UINT32_C(    493624), UINT32_C(     89360), UINT32_C(    298552), UINT32_C(     94344) },
      { UINT32_C(   3948992), UINT32_C(    714880), UINT32_C(   2388416), UINT32_C(    754752) },
      { UINT32_C(  63183872), UINT32_C(  11438080), UINT32_C(  38214656), UINT32_C(  12076032) },
      { UINT32_C( 505470976), UINT32_C(  91504640), UINT32_C( 305717248), UINT32_C(  96608256) },
      { UINT32_C(2021883904), UINT32_C( 366018560), UINT32_C(1222868992), UINT32_C( 386433024) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint32x4_t r3 = simde_vshll_n_u16(a, 3);
    simde_uint32x4_t r6 = simde_vshll_n_u16(a, 6);
    simde_uint32x4_t r10 = simde_vshll_n_u16(a, 10);
    simde_uint32x4_t r13 = simde_vshll_n_u16(a, 13);
    simde_uint32x4_t r15 = simde_vshll_n_u16(a, 15);

    simde_test_arm_neon_assert_equal_u32x4(r3, simde_vld1q_u32(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r10, simde_vld1q_u32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r15, simde_vld1q_u32(test_vec[i].r15));
  }

  return 0;
#else
  for (int i = 1 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t r3 = simde_vshll_n_u16(a, 3);
    simde_uint32x4_t r6 = simde_vshll_n_u16(a, 6);
    simde_uint32x4_t r10 = simde_vshll_n_u16(a, 10);
    simde_uint32x4_t r13 = simde_vshll_n_u16(a, 13);
    simde_uint32x4_t r15 = simde_vshll_n_u16(a, 15);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint64_t r6[2];
    uint64_t r13[2];
    uint64_t r19[2];
    uint64_t r26[2];
    uint64_t r31[2];
  } test_vec[] = {
    { { UINT32_C(1738825912), UINT32_C( 147426508) },
      { UINT64_C(        111284858368), UINT64_C(          9435296512) },
      { UINT64_C(      14244461871104), UINT64_C(       1207717953536) },
      { UINT64_C(     911645559750656), UINT64_C(      77293949026304) },
      { UINT64_C(  116690631648083968), UINT64_C(    9893625475366912) },
      { UINT64_C( 3734100212738686976), UINT64_C(  316596015211741184) } },
    { { UINT32_C(1345319720), UINT32_C(1780924654) },
      { UINT64_C(         86100462080), UINT64_C(        113979177856) },
      { UINT64_C(      11020859146240), UINT64_C(      14589334765568) },
      { UINT64_C(     705334985359360), UINT64_C(     933717424996352) },
      { UINT64_C(   90282878125998080), UINT64_C(  119515830399533056) },
      { UINT64_C( 2889052100031938560), UINT64_C( 3824506572785057792) } },
    { { UINT32_C(2879088480), UINT32_C(1642049332) },
      { UINT64_C(        184261662720), UINT64_C(        105091157248) },
      { UINT64_C(      23585492828160), UINT64_C(      13451668127744) },
      { UINT64_C(    1509471541002240), UINT64_C(     860906760175616) },
      { UINT64_C(  193212357248286720), UINT64_C(  110196065302478848) },
      { UINT64_C( 6182795431945175040), UINT64_C( 3526274089679323136) } },
    { { UINT32_C(3256177424), UINT32_C( 297698137) },
      { UINT64_C(        208395355136), UINT64_C(         19052680768) },
      { UINT64_C(      26674605457408), UINT64_C(       2438743138304) },
      { UINT64_C(    1707174749274112), UINT64_C(     156079560851456) },
      { UINT64_C(  218518367907086336), UINT64_C(   19978183788986368) },
      { UINT64_C( 6992587773026762752), UINT64_C(  639301881247563776) } },
    { { UINT32_C(2960679652), UINT32_C( 398017007) },
      { UINT64_C(        189483497728), UINT64_C(         25473088448) },
      { UINT64_C(      24253887709184), UINT64_C(       3260555321344) },
      { UINT64_C(    1552248813387776), UINT64_C(     208675540566016) },
      { UINT64_C(  198687848113635328), UINT64_C(   26710469192450048) },
      { UINT64_C( 6358011139636330496), UINT64_C(  854735014158401536) } },
    { { UINT32_C( 594077749), UINT32_C( 143494824) },
      { UINT64_C(         38020975936), UINT64_C(          9183668736) },
      { UINT64_C(       4866684919808), UINT64_C(       1175509598208) },
      { UINT64_C(     311467834867712), UINT64_C(      75232614285312) },
      { UINT64_C(   39867882863067136), UINT64_C(    9629774628519936) },
      { UINT64_C( 1275772251618148352), UINT64_C(  308152788112637952) } },
    { { UINT32_C( 699607285), UINT32_C(3884618455) },
      { UINT64_C(         44774866240), UINT64_C(        248615581120) },
      { UINT64_C(       5731182878720), UINT64_C(      31822794383360) },
      { UINT64_C(     366795704238080), UINT64_C(    2036658840535040) },
      { UINT64_C(   46949850142474240), UINT64_C(  260692331588485120) },
      { UINT64_C( 1502395204559175680), UINT64_C( 8342154610831523840) } },
    { { UINT32_C(1051369445), UINT32_C( 122710051) },
      { UINT64_C(         67287644480), UINT64_C(          7853443264) },
      { UINT64_C(       8612818493440), UINT64_C(       1005240737792) },
      { UINT64_C(     551220383580160), UINT64_C(      64335407218688) },
      { UINT64_C(   70556209098260480), UINT64_C(    8234932123992064) },
      { UINT64_C( 2257798691144335360), UINT64_C(  263517827967746048) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint64x2_t r6 = simde_vshll_n_u32(a, 6);
    simde_uint64x2_t r13 = simde_vshll_n_u32(a, 13);
    simde_uint64x2_t r19 = simde_vshll_n_u32(a, 19);
    simde_uint64x2_t r26 = simde_vshll_n_u32(a, 26);
    simde_uint64x2_t r31 = simde_vshll_n_u32(a, 31);

    simde_test_arm_neon_assert_equal_u64x2(r6, simde_vld1q_u64(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r19, simde_vld1q_u64(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r31, simde_vld1q_u64(test_vec[i].r31));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t r6 = simde_vshll_n_u32(a, 6);
    simde_uint64x2_t r13 = simde_vshll_n_u32(a, 13);
    simde_uint64x2_t r19 = simde_vshll_n_u32(a, 19);
    simde_uint64x2_t r26 = simde_vshll_n_u32(a, 26);
    simde_uint64x2_t r31 = simde_vshll_n_u32(a, 31);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
