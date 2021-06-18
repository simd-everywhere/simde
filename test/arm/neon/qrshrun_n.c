
#define SIMDE_TEST_ARM_NEON_INSN qrshrun_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qrshrun_n.h"

static int
test_simde_vqrshrun_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { { -INT16_C( 14576),  INT16_C( 28041),  INT16_C( 23233),  INT16_C(  6762),  INT16_C( 15047), -INT16_C( 26618), -INT16_C(  8367),  INT16_C( 16002) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(211),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(106), UINT8_C(235), UINT8_C(  0), UINT8_C(  0), UINT8_C(250) },
      { UINT8_C(  0), UINT8_C(110), UINT8_C( 91), UINT8_C( 26), UINT8_C( 59), UINT8_C(  0), UINT8_C(  0), UINT8_C( 63) } },
    { {  INT16_C( 14737),  INT16_C( 24598),  INT16_C(  3097), -INT16_C( 24203),  INT16_C( 31538), -INT16_C(  4291),  INT16_C(  2694), -INT16_C( 26841) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C( 97), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C( 84), UINT8_C(  0) },
      { UINT8_C(230),    UINT8_MAX, UINT8_C( 48), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C( 42), UINT8_C(  0) },
      { UINT8_C( 58), UINT8_C( 96), UINT8_C( 12), UINT8_C(  0), UINT8_C(123), UINT8_C(  0), UINT8_C( 11), UINT8_C(  0) } },
    { { -INT16_C( 20270), -INT16_C( 27900),  INT16_C( 28170), -INT16_C( 11603), -INT16_C( 19544), -INT16_C(  1686), -INT16_C(  4718),  INT16_C(  9015) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(141) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(110), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 35) } },
    { {  INT16_C( 19750),  INT16_C( 16515), -INT16_C(  1959), -INT16_C( 29471),  INT16_C(  7795), -INT16_C(  1413), -INT16_C( 24023), -INT16_C(  1135) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(244), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(122), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C( 77), UINT8_C( 65), UINT8_C(  0), UINT8_C(  0), UINT8_C( 30), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { -INT16_C( 27309),  INT16_C( 23950),  INT16_C( 15107), -INT16_C( 21713), -INT16_C( 25874), -INT16_C( 32604), -INT16_C(  9337), -INT16_C( 21085) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(236), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C( 94), UINT8_C( 59), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT16_C( 10024), -INT16_C( 32275), -INT16_C( 12769), -INT16_C( 27891), -INT16_C( 30483),  INT16_C(  5773),  INT16_C(  7723),  INT16_C( 32273) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(180), UINT8_C(241),    UINT8_MAX },
      { UINT8_C(157), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 90), UINT8_C(121),    UINT8_MAX },
      { UINT8_C( 39), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 23), UINT8_C( 30), UINT8_C(126) } },
    { { -INT16_C( 24653), -INT16_C( 18725),  INT16_C(  3034), -INT16_C( 14239),  INT16_C(  1445),  INT16_C( 11336), -INT16_C(  5152),  INT16_C(  2265) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(181),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C( 95), UINT8_C(  0), UINT8_C( 45),    UINT8_MAX, UINT8_C(  0), UINT8_C( 71) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C( 47), UINT8_C(  0), UINT8_C( 23), UINT8_C(177), UINT8_C(  0), UINT8_C( 35) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C( 12), UINT8_C(  0), UINT8_C(  6), UINT8_C( 44), UINT8_C(  0), UINT8_C(  9) } },
    { { -INT16_C( 14574),  INT16_C( 12937), -INT16_C( 26731), -INT16_C( 32059),  INT16_C( 21023),  INT16_C( 19096), -INT16_C( 22160),  INT16_C(  9160) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0), UINT8_C(202), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(143) },
      { UINT8_C(  0), UINT8_C( 51), UINT8_C(  0), UINT8_C(  0), UINT8_C( 82), UINT8_C( 75), UINT8_C(  0), UINT8_C( 36) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_uint8x8_t r1 = simde_vqrshrun_n_s16(a, 1);
    simde_uint8x8_t r3 = simde_vqrshrun_n_s16(a, 3);
    simde_uint8x8_t r5 = simde_vqrshrun_n_s16(a, 5);
    simde_uint8x8_t r6 = simde_vqrshrun_n_s16(a, 6);
    simde_uint8x8_t r8 = simde_vqrshrun_n_s16(a, 8);

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
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();

    simde_uint8x8_t r1 = simde_vqrshrun_n_s16(a, 1);
    simde_uint8x8_t r3 = simde_vqrshrun_n_s16(a, 3);
    simde_uint8x8_t r5 = simde_vqrshrun_n_s16(a, 5);
    simde_uint8x8_t r6 = simde_vqrshrun_n_s16(a, 6);
    simde_uint8x8_t r8 = simde_vqrshrun_n_s16(a, 8);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vqrshrun_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { -INT32_C(   248078666), -INT32_C(    87001047), -INT32_C(   273061285),  INT32_C(  1753432806) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(26755) } },
    { { -INT32_C(   699268474), -INT32_C(  1870965399),  INT32_C(   769809326),  INT32_C(  1616612777) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(11746), UINT16_C(24668) } },
    { {  INT32_C(  1414631723),  INT32_C(  1699619081),  INT32_C(  1918109835), -INT32_C(   790964150) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(21586), UINT16_C(25934), UINT16_C(29268), UINT16_C(    0) } },
    { {  INT32_C(  1134963930),  INT32_C(   819143298),  INT32_C(   660518525),  INT32_C(  1854388547) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(17318), UINT16_C(12499), UINT16_C(10079), UINT16_C(28296) } },
    { {  INT32_C(  1405278282), -INT32_C(  2051534343),  INT32_C(  1677135129), -INT32_C(  1087057435) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(21443), UINT16_C(    0), UINT16_C(25591), UINT16_C(    0) } },
    { { -INT32_C(  2147230978),  INT32_C(  2058409724), -INT32_C(   811528564),  INT32_C(   289220807) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(35305) },
      { UINT16_C(    0), UINT16_C(31409), UINT16_C(    0), UINT16_C( 4413) } },
    { { -INT32_C(   110821376),  INT32_C(   712908049),  INT32_C(   260928810),  INT32_C(  1171243335) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(31852),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(10878), UINT16_C( 3981), UINT16_C(17872) } },
    { { -INT32_C(  1731865956),  INT32_C(   890402216),  INT32_C(  1258599300), -INT32_C(   614645029) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(13586), UINT16_C(19205), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_uint16x4_t r3 = simde_vqrshrun_n_s32(a, 3);
    simde_uint16x4_t r6 = simde_vqrshrun_n_s32(a, 6);
    simde_uint16x4_t r10 = simde_vqrshrun_n_s32(a, 10);
    simde_uint16x4_t r13 = simde_vqrshrun_n_s32(a, 13);
    simde_uint16x4_t r16 = simde_vqrshrun_n_s32(a, 16);

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
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();

    simde_uint16x4_t r3 = simde_vqrshrun_n_s32(a, 3);
    simde_uint16x4_t r6 = simde_vqrshrun_n_s32(a, 6);
    simde_uint16x4_t r10 = simde_vqrshrun_n_s32(a, 10);
    simde_uint16x4_t r13 = simde_vqrshrun_n_s32(a, 13);
    simde_uint16x4_t r16 = simde_vqrshrun_n_s32(a, 16);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vqrshrun_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { -INT64_C( 8209958500099004498), -INT64_C( 5380907253539501925) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT64_C( 3514381741394830213),  INT64_C(  675718455382357951) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C( 818255763), UINT32_C( 157327963) } },
    { {  INT64_C( 4599623981926270473), -INT64_C(  234386780471276883) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      { UINT32_C(1070933412), UINT32_C(         0) } },
    { {  INT64_C(  733988109630354541),  INT64_C( 1711455882546539613) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C( 170894924), UINT32_C( 398479375) } },
    { { -INT64_C( 6306670078853130858),  INT64_C( 2878487060131442814) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C( 670199995) } },
    { { -INT64_C( 3064042620722949596),  INT64_C( 5829995182389291714) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(1357401531) } },
    { { -INT64_C(  376890066992478429),  INT64_C(  889427834486880117) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C( 207086055) } },
    { { -INT64_C( 7709329324771672652), -INT64_C(   42417113769078945) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_uint32x2_t r6 = simde_vqrshrun_n_s64(a, 6);
    simde_uint32x2_t r13 = simde_vqrshrun_n_s64(a, 13);
    simde_uint32x2_t r19 = simde_vqrshrun_n_s64(a, 19);
    simde_uint32x2_t r26 = simde_vqrshrun_n_s64(a, 26);
    simde_uint32x2_t r32 = simde_vqrshrun_n_s64(a, 32);

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
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();

    simde_uint32x2_t r6 = simde_vqrshrun_n_s64(a, 6);
    simde_uint32x2_t r13 = simde_vqrshrun_n_s64(a, 13);
    simde_uint32x2_t r19 = simde_vqrshrun_n_s64(a, 19);
    simde_uint32x2_t r26 = simde_vqrshrun_n_s64(a, 26);
    simde_uint32x2_t r32 = simde_vqrshrun_n_s64(a, 32);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vqrshrund_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    uint32_t r6;
    uint32_t r13;
    uint32_t r19;
    uint32_t r26;
    uint32_t r32;
  } test_vec[] = {
    {  INT64_C( 3938940077467616316),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C( 917105954) },
    {  INT64_C(  710008281531519723),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C( 165311685) },
    { -INT64_C( 9045414067431900482),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    { -INT64_C( 7352525117533445070),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    { -INT64_C( 3408714858422142887),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT64_C( 2967830833194399329),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C( 691001963) },
    {  INT64_C(  336698846563898965),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(  78393809) },
    { -INT64_C( 2068452359814777771),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r6 = HEDLEY_STATIC_CAST(uint32_t, simde_vqrshrund_n_s64(test_vec[i].a, 6));
    uint32_t r13 = HEDLEY_STATIC_CAST(uint32_t, simde_vqrshrund_n_s64(test_vec[i].a, 13));
    uint32_t r19 = HEDLEY_STATIC_CAST(uint32_t, simde_vqrshrund_n_s64(test_vec[i].a, 19));
    uint32_t r26 = HEDLEY_STATIC_CAST(uint32_t, simde_vqrshrund_n_s64(test_vec[i].a, 26));
    uint32_t r32 = HEDLEY_STATIC_CAST(uint32_t, simde_vqrshrund_n_s64(test_vec[i].a, 32));

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
    int64_t a = simde_test_codegen_random_i64();

    uint32_t r6 = HEDLEY_STATIC_CAST(uint32_t, simde_vqrshrund_n_s64(a, 6));
    uint32_t r13 = HEDLEY_STATIC_CAST(uint32_t, simde_vqrshrund_n_s64(a, 13));
    uint32_t r19 = HEDLEY_STATIC_CAST(uint32_t, simde_vqrshrund_n_s64(a, 19));
    uint32_t r26 = HEDLEY_STATIC_CAST(uint32_t, simde_vqrshrund_n_s64(a, 26));
    uint32_t r32 = HEDLEY_STATIC_CAST(uint32_t, simde_vqrshrund_n_s64(a, 32));

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshruns_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    uint16_t r6;
    uint16_t r8;
    uint16_t r10;
    uint16_t r12;
    uint16_t r16;
  } test_vec[] = {
    { -INT32_C(  1583078696),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT32_C(   143985186),
      UINT16_C(21545),
      UINT16_C(38154),
      UINT16_C( 9539),
      UINT16_C(35153),
      UINT16_C( 2197) },
    { -INT32_C(    40662305),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    { -INT32_C(  2139863647),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    { -INT32_C(  1597621020),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    { -INT32_C(   158180481),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT32_C(   933718157),
      UINT16_C(40354),
      UINT16_C(42857),
      UINT16_C(59866),
      UINT16_C(31351),
      UINT16_C(14247) },
    {  INT32_C(  1252938354),
      UINT16_C(47434),
      UINT16_C(44626),
      UINT16_C(43925),
      UINT16_C(43749),
      UINT16_C(19118) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r6 = HEDLEY_STATIC_CAST(uint16_t, simde_vqrshrund_n_s64(test_vec[i].a, 6));
    uint16_t r8 = HEDLEY_STATIC_CAST(uint16_t, simde_vqrshrund_n_s64(test_vec[i].a, 8));
    uint16_t r10 = HEDLEY_STATIC_CAST(uint16_t, simde_vqrshrund_n_s64(test_vec[i].a, 10));
    uint16_t r12 = HEDLEY_STATIC_CAST(uint16_t, simde_vqrshrund_n_s64(test_vec[i].a, 12));
    uint16_t r16 = HEDLEY_STATIC_CAST(uint16_t, simde_vqrshrund_n_s64(test_vec[i].a, 16));

    simde_assert_equal_u16(r6, test_vec[i].r6);
    simde_assert_equal_u16(r8, test_vec[i].r8);
    simde_assert_equal_u16(r10, test_vec[i].r10);
    simde_assert_equal_u16(r12, test_vec[i].r12);
    simde_assert_equal_u16(r16, test_vec[i].r16);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();

    uint16_t r6 = HEDLEY_STATIC_CAST(uint16_t, simde_vqrshrund_n_s64(a, 6));
    uint16_t r8 = HEDLEY_STATIC_CAST(uint16_t, simde_vqrshrund_n_s64(a, 8));
    uint16_t r10 = HEDLEY_STATIC_CAST(uint16_t, simde_vqrshrund_n_s64(a, 10));
    uint16_t r12 = HEDLEY_STATIC_CAST(uint16_t, simde_vqrshrund_n_s64(a, 12));
    uint16_t r16 = HEDLEY_STATIC_CAST(uint16_t, simde_vqrshrund_n_s64(a, 16));

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrun_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrun_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrun_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrund_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshruns_n_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
