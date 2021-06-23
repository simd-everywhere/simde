#define SIMDE_TEST_ARM_NEON_INSN qshrn_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qshrn_n.h"

static int
test_simde_vqshrn_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec[] = {
    { {  INT16_C( 11473),  INT16_C( 27542),  INT16_C( 24074),  INT16_C(  2993), -INT16_C( 19599),  INT16_C(   550),  INT16_C(  9579), -INT16_C( 30586) },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,  INT8_C(  68),      INT8_MAX,      INT8_MIN },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  93),      INT8_MIN,  INT8_C(  17),      INT8_MAX,      INT8_MIN },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  46),      INT8_MIN,  INT8_C(   8),      INT8_MAX,      INT8_MIN },
      {  INT8_C(  44),  INT8_C( 107),  INT8_C(  94),  INT8_C(  11), -INT8_C(  77),  INT8_C(   2),  INT8_C(  37), -INT8_C( 120) } },
    { {  INT16_C( 17084), -INT16_C(  6524),  INT16_C( 32126),  INT16_C( 25595), -INT16_C( 28938), -INT16_C( 21879),  INT16_C(  9062),  INT16_C( 14325) },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX },
      {      INT8_MAX, -INT8_C( 102),      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX },
      {  INT8_C(  66), -INT8_C(  26),  INT8_C( 125),  INT8_C(  99), -INT8_C( 114), -INT8_C(  86),  INT8_C(  35),  INT8_C(  55) } },
    { { -INT16_C( 29873),  INT16_C( 22946),  INT16_C( 21481),  INT16_C( 23396), -INT16_C( 29946),  INT16_C( 29021), -INT16_C(  6992),  INT16_C( 27898) },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX, -INT8_C( 110),      INT8_MAX },
      { -INT8_C( 117),  INT8_C(  89),  INT8_C(  83),  INT8_C(  91), -INT8_C( 117),  INT8_C( 113), -INT8_C(  28),  INT8_C( 108) } },
    { {  INT16_C( 32294), -INT16_C( 23469),  INT16_C( 20219), -INT16_C(  3832), -INT16_C( 28195),  INT16_C( 17308), -INT16_C( 28236),  INT16_C(   890) },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C( 111) },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX, -INT8_C( 120),      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(  27) },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX, -INT8_C(  60),      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(  13) },
      {  INT8_C( 126), -INT8_C(  92),  INT8_C(  78), -INT8_C(  15), -INT8_C( 111),  INT8_C(  67), -INT8_C( 111),  INT8_C(   3) } },
    { {  INT16_C(  7196),  INT16_C(  1372), -INT16_C( 16017),  INT16_C( 30048), -INT16_C( 16820), -INT16_C(   794), -INT16_C(  8030), -INT16_C( 14232) },
      {      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      {      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN, -INT8_C( 100),      INT8_MIN,      INT8_MIN },
      {      INT8_MAX,  INT8_C(  42),      INT8_MIN,      INT8_MAX,      INT8_MIN, -INT8_C(  25),      INT8_MIN,      INT8_MIN },
      {  INT8_C( 112),  INT8_C(  21),      INT8_MIN,      INT8_MAX,      INT8_MIN, -INT8_C(  13), -INT8_C( 126),      INT8_MIN },
      {  INT8_C(  28),  INT8_C(   5), -INT8_C(  63),  INT8_C( 117), -INT8_C(  66), -INT8_C(   4), -INT8_C(  32), -INT8_C(  56) } },
    { { -INT16_C( 17570),  INT16_C( 22893),  INT16_C( 29962), -INT16_C(  6325), -INT16_C(  6394), -INT16_C( 17622), -INT16_C( 23432), -INT16_C( 27458) },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C(  99), -INT8_C( 100),      INT8_MIN,      INT8_MIN,      INT8_MIN },
      { -INT8_C(  69),  INT8_C(  89),  INT8_C( 117), -INT8_C(  25), -INT8_C(  25), -INT8_C(  69), -INT8_C(  92), -INT8_C( 108) } },
    { {  INT16_C(  7104),  INT16_C( 12185), -INT16_C(  1316),  INT16_C( 10404), -INT16_C( 30024),  INT16_C( 23076), -INT16_C( 29589), -INT16_C( 14046) },
      {      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN },
      {      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN },
      {      INT8_MAX,      INT8_MAX, -INT8_C(  42),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN },
      {  INT8_C( 111),      INT8_MAX, -INT8_C(  21),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN },
      {  INT8_C(  27),  INT8_C(  47), -INT8_C(   6),  INT8_C(  40), -INT8_C( 118),  INT8_C(  90), -INT8_C( 116), -INT8_C(  55) } },
    { { -INT16_C( 28856),  INT16_C( 21027),  INT16_C( 28164),  INT16_C(  2873),  INT16_C( 25429), -INT16_C( 12858), -INT16_C( 31737), -INT16_C( 14495) },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  89),      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  44),      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      { -INT8_C( 113),  INT8_C(  82),  INT8_C( 110),  INT8_C(  11),  INT8_C(  99), -INT8_C(  51), -INT8_C( 124), -INT8_C(  57) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_int8x8_t r1 = simde_vqshrn_n_s16(a, 1);
    simde_int8x8_t r3 = simde_vqshrn_n_s16(a, 3);
    simde_int8x8_t r5 = simde_vqshrn_n_s16(a, 5);
    simde_int8x8_t r6 = simde_vqshrn_n_s16(a, 6);
    simde_int8x8_t r8 = simde_vqshrn_n_s16(a, 8);

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

    simde_int8x8_t r1 = simde_vqshrn_n_s16(a, 1);
    simde_int8x8_t r3 = simde_vqshrn_n_s16(a, 3);
    simde_int8x8_t r5 = simde_vqshrn_n_s16(a, 5);
    simde_int8x8_t r6 = simde_vqshrn_n_s16(a, 6);
    simde_int8x8_t r8 = simde_vqshrn_n_s16(a, 8);

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
test_simde_vqshrn_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { {  INT32_C(  2079783583), -INT32_C(  1398564108), -INT32_C(  1895381212), -INT32_C(  1671878316) },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN },
      {  INT16_C( 31734), -INT16_C( 21341), -INT16_C( 28922), -INT16_C( 25511) } },
    { { -INT32_C(  1108443976),  INT32_C(  1070082026), -INT32_C(  1861448054), -INT32_C(  1302827758) },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      { -INT16_C( 16914),  INT16_C( 16328), -INT16_C( 28404), -INT16_C( 19880) } },
    { {  INT32_C(  1546473063),  INT32_C(   201904616), -INT32_C(   325316712), -INT32_C(   259459784) },
      {        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,  INT16_C( 24646),        INT16_MIN, -INT16_C( 31673) },
      {  INT16_C( 23597),  INT16_C(  3080), -INT16_C(  4964), -INT16_C(  3960) } },
    { {  INT32_C(  1538094705),  INT32_C(   664434077),  INT32_C(   381199875),  INT32_C(  2059931667) },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {  INT16_C( 23469),  INT16_C( 10138),  INT16_C(  5816),  INT16_C( 31432) } },
    { {  INT32_C(  1188492638),  INT32_C(  1599332294),  INT32_C(   642510830),  INT32_C(  1427559652) },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {  INT16_C( 18134),  INT16_C( 24403),  INT16_C(  9803),  INT16_C( 21782) } },
    { { -INT32_C(   391068598),  INT32_C(  1024412217),  INT32_C(    55822576),  INT32_C(   930946008) },
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MIN,        INT16_MAX,  INT16_C(  6814),        INT16_MAX },
      { -INT16_C(  5968),  INT16_C( 15631),  INT16_C(   851),  INT16_C( 14205) } },
    { { -INT32_C(   679652336),  INT32_C(   557240371), -INT32_C(  1555594817), -INT32_C(  1594335915) },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      { -INT16_C( 10371),  INT16_C(  8502), -INT16_C( 23737), -INT16_C( 24328) } },
    { {  INT32_C(  1535682593), -INT32_C(   493316110),  INT32_C(   954592095),  INT32_C(   376398598) },
      {        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MAX },
      {  INT16_C( 23432), -INT16_C(  7528),  INT16_C( 14565),  INT16_C(  5743) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_int16x4_t r3 = simde_vqshrn_n_s32(a, 3);
    simde_int16x4_t r6 = simde_vqshrn_n_s32(a, 6);
    simde_int16x4_t r10 = simde_vqshrn_n_s32(a, 10);
    simde_int16x4_t r13 = simde_vqshrn_n_s32(a, 13);
    simde_int16x4_t r16 = simde_vqshrn_n_s32(a, 16);

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

    simde_int16x4_t r3 = simde_vqshrn_n_s32(a, 3);
    simde_int16x4_t r6 = simde_vqshrn_n_s32(a, 6);
    simde_int16x4_t r10 = simde_vqshrn_n_s32(a, 10);
    simde_int16x4_t r13 = simde_vqshrn_n_s32(a, 13);
    simde_int16x4_t r16 = simde_vqshrn_n_s32(a, 16);

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
test_simde_vqshrn_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec[] = {
    { {  INT64_C(  822281523113512744), -INT64_C( 6964206681257063844) },
      {              INT32_MAX,              INT32_MIN },
      {              INT32_MAX,              INT32_MIN },
      {              INT32_MAX,              INT32_MIN },
      {              INT32_MAX,              INT32_MIN },
      {  INT32_C(   191452336), -INT32_C(  1621480725) } },
    { {  INT64_C( 5395686725668081081),  INT64_C( 7091788677090818078) },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {  INT32_C(  1256281213),  INT32_C(  1651185722) } },
    { { -INT64_C( 6403250832909994136),  INT64_C( 5614545709174122847) },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      { -INT32_C(  1490873013),  INT32_C(  1307238291) } },
    { {  INT64_C( 1816209573105084012), -INT64_C( 2896698089220778448) },
      {              INT32_MAX,              INT32_MIN },
      {              INT32_MAX,              INT32_MIN },
      {              INT32_MAX,              INT32_MIN },
      {              INT32_MAX,              INT32_MIN },
      {  INT32_C(   422869243), -INT32_C(   674440081) } },
    { { -INT64_C( 1313340744501593901), -INT64_C( 7612172809930323332) },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      { -INT32_C(   305785971), -INT32_C(  1772347095) } },
    { { -INT64_C( 7143636529686973496), -INT64_C(  121083535572906485) },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN, -INT32_C(  1804285282) },
      { -INT32_C(  1663257492), -INT32_C(    28191958) } },
    { { -INT64_C( 3474841212717088692), -INT64_C( 1734946750656938451) },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      { -INT32_C(   809049517), -INT32_C(   403948769) } },
    { {  INT64_C( 3186163839803223087),  INT64_C( 6844898669643579093) },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {  INT32_C(   741836577),  INT32_C(  1593702162) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_int32x2_t r6 = simde_vqshrn_n_s64(a, 6);
    simde_int32x2_t r13 = simde_vqshrn_n_s64(a, 13);
    simde_int32x2_t r19 = simde_vqshrn_n_s64(a, 19);
    simde_int32x2_t r26 = simde_vqshrn_n_s64(a, 26);
    simde_int32x2_t r32 = simde_vqshrn_n_s64(a, 32);

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

    simde_int32x2_t r6 = simde_vqshrn_n_s64(a, 6);
    simde_int32x2_t r13 = simde_vqshrn_n_s64(a, 13);
    simde_int32x2_t r19 = simde_vqshrn_n_s64(a, 19);
    simde_int32x2_t r26 = simde_vqshrn_n_s64(a, 26);
    simde_int32x2_t r32 = simde_vqshrn_n_s64(a, 32);

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
test_simde_vqshrn_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec[] = {
    { { UINT16_C( 6711), UINT16_C(35639), UINT16_C(65276), UINT16_C(10586), UINT16_C(14844), UINT16_C( 7040), UINT16_C(27765), UINT16_C(41987) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      { UINT8_C(209),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(220),    UINT8_MAX,    UINT8_MAX },
      { UINT8_C(104),    UINT8_MAX,    UINT8_MAX, UINT8_C(165), UINT8_C(231), UINT8_C(110),    UINT8_MAX,    UINT8_MAX },
      { UINT8_C( 26), UINT8_C(139), UINT8_C(254), UINT8_C( 41), UINT8_C( 57), UINT8_C( 27), UINT8_C(108), UINT8_C(164) } },
    { { UINT16_C(44505), UINT16_C(64063), UINT16_C(30260), UINT16_C( 2342), UINT16_C(52405), UINT16_C(50953), UINT16_C( 1731), UINT16_C(64037) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(216),    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 73),    UINT8_MAX,    UINT8_MAX, UINT8_C( 54),    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 36),    UINT8_MAX,    UINT8_MAX, UINT8_C( 27),    UINT8_MAX },
      { UINT8_C(173), UINT8_C(250), UINT8_C(118), UINT8_C(  9), UINT8_C(204), UINT8_C(199), UINT8_C(  6), UINT8_C(250) } },
    { { UINT16_C(23584), UINT16_C( 7557), UINT16_C(57434), UINT16_C(22086), UINT16_C(50713), UINT16_C(36466), UINT16_C(30003), UINT16_C( 3122) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX, UINT8_C(236),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 97) },
      {    UINT8_MAX, UINT8_C(118),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 48) },
      { UINT8_C( 92), UINT8_C( 29), UINT8_C(224), UINT8_C( 86), UINT8_C(198), UINT8_C(142), UINT8_C(117), UINT8_C( 12) } },
    { { UINT16_C(28962), UINT16_C(22278), UINT16_C(11496), UINT16_C(40288), UINT16_C(27128), UINT16_C(47972), UINT16_C(35184), UINT16_C(37045) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(179),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      { UINT8_C(113), UINT8_C( 87), UINT8_C( 44), UINT8_C(157), UINT8_C(105), UINT8_C(187), UINT8_C(137), UINT8_C(144) } },
    { { UINT16_C(15333), UINT16_C(16557), UINT16_C(62491), UINT16_C(13462), UINT16_C( 2234), UINT16_C(60867), UINT16_C(62845), UINT16_C(41209) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 69),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      { UINT8_C(239),    UINT8_MAX,    UINT8_MAX, UINT8_C(210), UINT8_C( 34),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      { UINT8_C( 59), UINT8_C( 64), UINT8_C(244), UINT8_C( 52), UINT8_C(  8), UINT8_C(237), UINT8_C(245), UINT8_C(160) } },
    { { UINT16_C(65383), UINT16_C(20471), UINT16_C(22315), UINT16_C( 9196), UINT16_C(20673), UINT16_C(12766), UINT16_C(38105), UINT16_C(48833) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(143),    UINT8_MAX, UINT8_C(199),    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX, UINT8_C( 79), UINT8_C( 87), UINT8_C( 35), UINT8_C( 80), UINT8_C( 49), UINT8_C(148), UINT8_C(190) } },
    { { UINT16_C(28623), UINT16_C(60158), UINT16_C(38243), UINT16_C( 7454), UINT16_C(57757), UINT16_C( 6923), UINT16_C( 1239), UINT16_C(16059) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(154),    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(232),    UINT8_MAX, UINT8_C(216), UINT8_C( 38),    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(116),    UINT8_MAX, UINT8_C(108), UINT8_C( 19), UINT8_C(250) },
      { UINT8_C(111), UINT8_C(234), UINT8_C(149), UINT8_C( 29), UINT8_C(225), UINT8_C( 27), UINT8_C(  4), UINT8_C( 62) } },
    { { UINT16_C(45572), UINT16_C(12173), UINT16_C(30985), UINT16_C(51795), UINT16_C(12745), UINT16_C(41723), UINT16_C(48581), UINT16_C(37984) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX, UINT8_C(190),    UINT8_MAX,    UINT8_MAX, UINT8_C(199),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      { UINT8_C(178), UINT8_C( 47), UINT8_C(121), UINT8_C(202), UINT8_C( 49), UINT8_C(162), UINT8_C(189), UINT8_C(148) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);

    simde_uint8x8_t r1 = simde_vqshrn_n_u16(a, 1);
    simde_uint8x8_t r3 = simde_vqshrn_n_u16(a, 3);
    simde_uint8x8_t r5 = simde_vqshrn_n_u16(a, 5);
    simde_uint8x8_t r6 = simde_vqshrn_n_u16(a, 6);
    simde_uint8x8_t r8 = simde_vqshrn_n_u16(a, 8);

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

    simde_uint8x8_t r1 = simde_vqshrn_n_u16(a, 1);
    simde_uint8x8_t r3 = simde_vqshrn_n_u16(a, 3);
    simde_uint8x8_t r5 = simde_vqshrn_n_u16(a, 5);
    simde_uint8x8_t r6 = simde_vqshrn_n_u16(a, 6);
    simde_uint8x8_t r8 = simde_vqshrn_n_u16(a, 8);

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
test_simde_vqshrn_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { UINT32_C(2407423788), UINT32_C(2444008948), UINT32_C(1437382526), UINT32_C(3230885820) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(36734), UINT16_C(37292), UINT16_C(21932), UINT16_C(49299) } },
    { { UINT32_C( 602873881), UINT32_C(1659716249), UINT32_C( 956623220), UINT32_C(3536741798) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C( 9199), UINT16_C(25325), UINT16_C(14596), UINT16_C(53966) } },
    { { UINT32_C(3093384388), UINT32_C(1749618153), UINT32_C(2176710341), UINT32_C(2000769373) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(47201), UINT16_C(26697), UINT16_C(33213), UINT16_C(30529) } },
    { { UINT32_C( 194654321), UINT32_C(3882714995), UINT32_C( 371225200), UINT32_C(2615733975) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(23761),      UINT16_MAX, UINT16_C(45315),      UINT16_MAX },
      { UINT16_C( 2970), UINT16_C(59245), UINT16_C( 5664), UINT16_C(39912) } },
    { { UINT32_C( 609438011), UINT32_C( 478977111), UINT32_C(4036840082), UINT32_C( 208133787) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(58468),      UINT16_MAX, UINT16_C(25406) },
      { UINT16_C( 9299), UINT16_C( 7308), UINT16_C(61597), UINT16_C( 3175) } },
    { { UINT32_C(2165768462), UINT32_C(4184376712), UINT32_C(3457124855), UINT32_C(2993289335) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(33047), UINT16_C(63848), UINT16_C(52751), UINT16_C(45673) } },
    { { UINT32_C(2564275265), UINT32_C(3954467672), UINT32_C(1222332845), UINT32_C(1045774895) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(39127), UINT16_C(60340), UINT16_C(18651), UINT16_C(15957) } },
    { { UINT32_C(3418319939), UINT32_C(3905169649), UINT32_C( 683070641), UINT32_C( 232464332) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(28376) },
      { UINT16_C(52159), UINT16_C(59588), UINT16_C(10422), UINT16_C( 3547) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);

    simde_uint16x4_t r3 = simde_vqshrn_n_u32(a, 3);
    simde_uint16x4_t r6 = simde_vqshrn_n_u32(a, 6);
    simde_uint16x4_t r10 = simde_vqshrn_n_u32(a, 10);
    simde_uint16x4_t r13 = simde_vqshrn_n_u32(a, 13);
    simde_uint16x4_t r16 = simde_vqshrn_n_u32(a, 16);

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

    simde_uint16x4_t r3 = simde_vqshrn_n_u32(a, 3);
    simde_uint16x4_t r6 = simde_vqshrn_n_u32(a, 6);
    simde_uint16x4_t r10 = simde_vqshrn_n_u32(a, 10);
    simde_uint16x4_t r13 = simde_vqshrn_n_u32(a, 13);
    simde_uint16x4_t r16 = simde_vqshrn_n_u32(a, 16);

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
test_simde_vqshrn_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { UINT64_C(13970688600867096890), UINT64_C( 3237223427641551555) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(3252804419), UINT32_C( 753724814) } },
    { { UINT64_C( 6470568526615714798), UINT64_C( 5090802657901606921) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(1506546634), UINT32_C(1185294859) } },
    { { UINT64_C(10194005275548118643), UINT64_C( 8702863827569253643) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(2373476809), UINT32_C(2026293386) } },
    { { UINT64_C(11711083723286087267), UINT64_C(18044189257935904024) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(2726699161), UINT32_C(4201240199) } },
    { { UINT64_C( 6204316836837845444), UINT64_C( 2434396527111763654) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(1444555082), UINT32_C( 566802110) } },
    { { UINT64_C( 6087130828638133309), UINT64_C( 4878490760061102386) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(1417270588), UINT32_C(1135862143) } },
    { { UINT64_C( 6155272311215777226), UINT64_C( 5674938027452226529) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(1433136014), UINT32_C(1321299473) } },
    { { UINT64_C( 1664817721975836810), UINT64_C( 4398191040089067847) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C( 387620581), UINT32_C(1024033650) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);

    simde_uint32x2_t r6 = simde_vqshrn_n_u64(a, 6);
    simde_uint32x2_t r13 = simde_vqshrn_n_u64(a, 13);
    simde_uint32x2_t r19 = simde_vqshrn_n_u64(a, 19);
    simde_uint32x2_t r26 = simde_vqshrn_n_u64(a, 26);
    simde_uint32x2_t r32 = simde_vqshrn_n_u64(a, 32);

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

    simde_uint32x2_t r6 = simde_vqshrn_n_u64(a, 6);
    simde_uint32x2_t r13 = simde_vqshrn_n_u64(a, 13);
    simde_uint32x2_t r19 = simde_vqshrn_n_u64(a, 19);
    simde_uint32x2_t r26 = simde_vqshrn_n_u64(a, 26);
    simde_uint32x2_t r32 = simde_vqshrn_n_u64(a, 32);

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

static int
test_simde_vqshrns_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int16_t r3;
    int16_t r6;
    int16_t r10;
    int16_t r13;
    int16_t r16;
  } test_vec[] = {
    {  INT32_C(  1327417542),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C( 20254) },
    {  INT32_C(   721831677),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C( 11014) },
    { -INT32_C(   636666790),
             INT16_MIN,
             INT16_MIN,
             INT16_MIN,
             INT16_MIN,
      -INT16_C(  9715) },
    {  INT32_C(   635121001),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C(  9691) },
    { -INT32_C(   964326823),
             INT16_MIN,
             INT16_MIN,
             INT16_MIN,
             INT16_MIN,
      -INT16_C( 14715) },
    { -INT32_C(  1663406671),
             INT16_MIN,
             INT16_MIN,
             INT16_MIN,
             INT16_MIN,
      -INT16_C( 25382) },
    {  INT32_C(  1793389712),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C( 27364) },
    {  INT32_C(   957732467),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C( 14613) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r3 = simde_vqshrns_n_s32(test_vec[i].a, 3);
    int16_t r6 = simde_vqshrns_n_s32(test_vec[i].a, 6);
    int16_t r10 = simde_vqshrns_n_s32(test_vec[i].a, 10);
    int16_t r13 = simde_vqshrns_n_s32(test_vec[i].a, 13);
    int16_t r16 = simde_vqshrns_n_s32(test_vec[i].a, 16);

    simde_assert_equal_i16(r3, test_vec[i].r3);
    simde_assert_equal_i16(r6, test_vec[i].r6);
    simde_assert_equal_i16(r10, test_vec[i].r10);
    simde_assert_equal_i16(r13, test_vec[i].r13);
    simde_assert_equal_i16(r16, test_vec[i].r16);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();

    int16_t r3 = simde_vqshrns_n_s32(a, 3);
    int16_t r6 = simde_vqshrns_n_s32(a, 6);
    int16_t r10 = simde_vqshrns_n_s32(a, 10);
    int16_t r13 = simde_vqshrns_n_s32(a, 13);
    int16_t r16 = simde_vqshrns_n_s32(a, 16);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshrns_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint16_t r3;
    uint16_t r6;
    uint16_t r10;
    uint16_t r13;
    uint16_t r16;
  } test_vec[] = {
    { UINT32_C(3346268065),
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
     UINT16_C(51059) },
   { UINT32_C(3407466915),
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
     UINT16_C(51993) },
   { UINT32_C(2812724740),
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
     UINT16_C(42918) },
   { UINT32_C( 158922281),
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
     UINT16_C(19399),
     UINT16_C( 2424) },
   { UINT32_C( 997935970),
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
     UINT16_C(15227) },
   { UINT32_C( 311156833),
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
     UINT16_C(37983),
     UINT16_C( 4747) },
   { UINT32_C(2938775148),
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
     UINT16_C(44842) },
   { UINT32_C( 850621841),
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
          UINT16_MAX,
     UINT16_C(12979) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r3 = simde_vqshrns_n_u32(test_vec[i].a, 3);
    uint16_t r6 = simde_vqshrns_n_u32(test_vec[i].a, 6);
    uint16_t r10 = simde_vqshrns_n_u32(test_vec[i].a, 10);
    uint16_t r13 = simde_vqshrns_n_u32(test_vec[i].a, 13);
    uint16_t r16 = simde_vqshrns_n_u32(test_vec[i].a, 16);

    simde_assert_equal_u16(r3, test_vec[i].r3);
    simde_assert_equal_u16(r6, test_vec[i].r6);
    simde_assert_equal_u16(r10, test_vec[i].r10);
    simde_assert_equal_u16(r13, test_vec[i].r13);
    simde_assert_equal_u16(r16, test_vec[i].r16);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();

    uint16_t r3 = simde_vqshrns_n_u32(a, 3);
    uint16_t r6 = simde_vqshrns_n_u32(a, 6);
    uint16_t r10 = simde_vqshrns_n_u32(a, 10);
    uint16_t r13 = simde_vqshrns_n_u32(a, 13);
    uint16_t r16 = simde_vqshrns_n_u32(a, 16);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshrnd_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int32_t r6;
    int32_t r13;
    int32_t r19;
    int32_t r26;
    int32_t r32;
  } test_vec[] = {
    { -INT64_C( 3079013855138454644),
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN,
      -INT32_C(   716888778) },
    {  INT64_C( 5304162772951430956),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(  1234971632) },
    { -INT64_C( 2018058201453336472),
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN,
      -INT32_C(   469865790) },
    {  INT64_C( 5254087493388831878),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(  1223312572) },
    {  INT64_C( 3725557741269410216),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(   867424006) },
    { -INT64_C( 2015281132619476530),
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN,
      -INT32_C(   469219204) },
    {  INT64_C( 5140553041755920304),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(  1196878273) },
    { -INT64_C( 8756941757369968267),
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN,
      -INT32_C(  2038884386) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r6 = simde_vqshrnd_n_s64(test_vec[i].a, 6);
    int32_t r13 = simde_vqshrnd_n_s64(test_vec[i].a, 13);
    int32_t r19 = simde_vqshrnd_n_s64(test_vec[i].a, 19);
    int32_t r26 = simde_vqshrnd_n_s64(test_vec[i].a, 26);
    int32_t r32 = simde_vqshrnd_n_s64(test_vec[i].a, 32);

    simde_assert_equal_i32(r6, test_vec[i].r6);
    simde_assert_equal_i32(r13, test_vec[i].r13);
    simde_assert_equal_i32(r19, test_vec[i].r19);
    simde_assert_equal_i32(r26, test_vec[i].r26);
    simde_assert_equal_i32(r32, test_vec[i].r32);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();

    int32_t r6 = simde_vqshrnd_n_s64(a, 6);
    int32_t r13 = simde_vqshrnd_n_s64(a, 13);
    int32_t r19 = simde_vqshrnd_n_s64(a, 19);
    int32_t r26 = simde_vqshrnd_n_s64(a, 26);
    int32_t r32 = simde_vqshrnd_n_s64(a, 32);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshrnd_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint32_t r6;
    uint32_t r13;
    uint32_t r19;
    uint32_t r26;
    uint32_t r32;
  } test_vec[] = {
    { UINT64_C(11854185692521990935),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(2760017684) },
    { UINT64_C(11840776316248418264),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(2756895571) },
    { UINT64_C(15920680587859222240),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(3706822308) },
    { UINT64_C( 9694671580042503629),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(2257216623) },
    { UINT64_C( 3722455280849442031),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C( 866701659) },
    { UINT64_C( 4913593647272132664),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(1144035171) },
    { UINT64_C( 7671568177514544885),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(1786176156) },
    { UINT64_C( 5547575324246079495),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(1291645533) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r6 = simde_vqshrnd_n_u64(test_vec[i].a, 6);
    uint32_t r13 = simde_vqshrnd_n_u64(test_vec[i].a, 13);
    uint32_t r19 = simde_vqshrnd_n_u64(test_vec[i].a, 19);
    uint32_t r26 = simde_vqshrnd_n_u64(test_vec[i].a, 26);
    uint32_t r32 = simde_vqshrnd_n_u64(test_vec[i].a, 32);

    simde_assert_equal_u32(r6, test_vec[i].r6);
    simde_assert_equal_u32(r13, test_vec[i].r13);
    simde_assert_equal_u32(r19, test_vec[i].r19);
    simde_assert_equal_u32(r26, test_vec[i].r26);
    simde_assert_equal_u32(r32, test_vec[i].r32);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();

    uint32_t r6 = simde_vqshrnd_n_u64(a, 6);
    uint32_t r13 = simde_vqshrnd_n_u64(a, 13);
    uint32_t r19 = simde_vqshrnd_n_u64(a, 19);
    uint32_t r26 = simde_vqshrnd_n_u64(a, 26);
    uint32_t r32 = simde_vqshrnd_n_u64(a, 32);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrn_n_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrns_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrns_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrnd_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrnd_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
