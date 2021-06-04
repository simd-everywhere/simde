#define SIMDE_TEST_ARM_NEON_INSN qshlu_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qshlu_n.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vqshlu_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    const int n;
    uint8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  66),  INT8_C(  72), -INT8_C(  92), -INT8_C(  15), -INT8_C(  78), -INT8_C(  96), -INT8_C( 107), -INT8_C(  40) },
      INT32_C(           0),
     { UINT8_C(  0), UINT8_C( 72), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
   { {  INT8_C(  46),  INT8_C( 106), -INT8_C(  64), -INT8_C( 112), -INT8_C(  41),  INT8_C(  94), -INT8_C(  38),      INT8_MIN },
      INT32_C(           1),
     { UINT8_C( 92), UINT8_C(212), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(188), UINT8_C(  0), UINT8_C(  0) } },
   { { -INT8_C(   4),  INT8_C(  61), -INT8_C(   4), -INT8_C(  78),  INT8_C(  55),  INT8_C( 107),  INT8_C(  37),  INT8_C(  59) },
      INT32_C(           2),
     { UINT8_C(  0), UINT8_C(244), UINT8_C(  0), UINT8_C(  0), UINT8_C(220),    UINT8_MAX, UINT8_C(148), UINT8_C(236) } },
   { {  INT8_C(  33),  INT8_C(  38),  INT8_C(  47), -INT8_C(  32), -INT8_C(  11),  INT8_C( 103), -INT8_C( 103), -INT8_C(  77) },
      INT32_C(           3),
     {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
   { { -INT8_C(  80),  INT8_C(  61), -INT8_C(  92),  INT8_C(  98), -INT8_C(  35),  INT8_C(  58),  INT8_C(  59),  INT8_C(  11) },
      INT32_C(           4),
     { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(176) } },
   { { -INT8_C(  92), -INT8_C(   5), -INT8_C( 101),  INT8_C( 124),  INT8_C(  89),  INT8_C( 118), -INT8_C(   4),  INT8_C(  85) },
      INT32_C(           5),
     { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
   { { -INT8_C(  77), -INT8_C(   8),  INT8_C(   8), -INT8_C(  22),  INT8_C(  99),  INT8_C(  45),  INT8_C(  37), -INT8_C( 123) },
      INT32_C(           6),
     { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
   { {  INT8_C(  83),  INT8_C(  84),  INT8_C( 101),  INT8_C(  72), -INT8_C(  68), -INT8_C(   2), -INT8_C(   5),  INT8_C( 108) },
      INT32_C(           7),
     {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_uint8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vqshlu_n_s8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int n[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_uint8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vqshlu_n_s8, r, (HEDLEY_UNREACHABLE(), r), n[i], a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, n[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlu_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    uint16_t r0[4];
    uint16_t r2[4];
    uint16_t r5[4];
    uint16_t r9[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r15[4];
  } test_vec[] = {
    { {  INT16_C( 10390), -INT16_C( 23036), -INT16_C( 23085), -INT16_C( 26112) },
      { UINT16_C(10390), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(41560), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 23503), -INT16_C(    67),  INT16_C( 13233), -INT16_C(  9905) },
      { UINT16_C(23503), UINT16_C(    0), UINT16_C(13233), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(52932), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 15091),  INT16_C(   772), -INT16_C( 16389), -INT16_C(  1073) },
      { UINT16_C(15091), UINT16_C(  772), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(60364), UINT16_C( 3088), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(24704), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 28563), -INT16_C(  9751),  INT16_C( 32169),  INT16_C( 16282) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(32169), UINT16_C(16282) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(65128) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C( 24923),  INT16_C( 31206), -INT16_C(  6589),  INT16_C(  4627) },
      { UINT16_C(    0), UINT16_C(31206), UINT16_C(    0), UINT16_C( 4627) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(18508) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 12223), -INT16_C(  3566),  INT16_C( 24835), -INT16_C(  2357) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(24835), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 12133), -INT16_C( 26630), -INT16_C( 13937), -INT16_C(   878) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 31833),  INT16_C(   981),  INT16_C( 28665), -INT16_C( 24766) },
      { UINT16_C(31833), UINT16_C(  981), UINT16_C(28665), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C( 3924),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(31392),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_uint16x4_t r0 = simde_vqshlu_n_s16(a, 0);
    simde_uint16x4_t r2 = simde_vqshlu_n_s16(a, 2);
    simde_uint16x4_t r5 = simde_vqshlu_n_s16(a, 5);
    simde_uint16x4_t r9 = simde_vqshlu_n_s16(a, 9);
    simde_uint16x4_t r10 = simde_vqshlu_n_s16(a, 10);
    simde_uint16x4_t r13 = simde_vqshlu_n_s16(a, 13);
    simde_uint16x4_t r15 = simde_vqshlu_n_s16(a, 15);

    simde_test_arm_neon_assert_equal_u16x4(r0, simde_vld1_u16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u16x4(r2, simde_vld1_u16(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_u16x4(r5, simde_vld1_u16(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u16x4(r9, simde_vld1_u16(test_vec[i].r9));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r15, simde_vld1_u16(test_vec[i].r15));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_uint16x4_t r0 = simde_vqshlu_n_s16(a, 0);
    simde_uint16x4_t r2 = simde_vqshlu_n_s16(a, 2);
    simde_uint16x4_t r5 = simde_vqshlu_n_s16(a, 5);
    simde_uint16x4_t r9 = simde_vqshlu_n_s16(a, 9);
    simde_uint16x4_t r10 = simde_vqshlu_n_s16(a, 10);
    simde_uint16x4_t r13 = simde_vqshlu_n_s16(a, 13);
    simde_uint16x4_t r15 = simde_vqshlu_n_s16(a, 15);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r9, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlu_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    uint32_t r0[2];
    uint32_t r4[2];
    uint32_t r10[2];
    uint32_t r15[2];
    uint32_t r23[2];
    uint32_t r28[2];
    uint32_t r31[2];
  } test_vec[] = {
    { {  INT32_C(   598227896), -INT32_C(  1134992453) },
      { UINT32_C( 598227896), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(   461190294),  INT32_C(  1207825082) },
      { UINT32_C( 461190294), UINT32_C(1207825082) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(   268503244),  INT32_C(  1953130073) },
      { UINT32_C( 268503244), UINT32_C(1953130073) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1616334634), -INT32_C(  1096563195) },
      { UINT32_C(1616334634), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1126085887),  INT32_C(  1148795822) },
      { UINT32_C(         0), UINT32_C(1148795822) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   694154863), -INT32_C(  1267704600) },
      { UINT32_C( 694154863), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1094421915),  INT32_C(    36843480) },
      { UINT32_C(         0), UINT32_C(  36843480) },
      { UINT32_C(         0), UINT32_C( 589495680) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX } },
    { { -INT32_C(  2073917058),  INT32_C(  1363281487) },
      { UINT32_C(         0), UINT32_C(1363281487) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_uint32x2_t r0 = simde_vqshlu_n_s32(a, 0);
    simde_uint32x2_t r4 = simde_vqshlu_n_s32(a, 4);
    simde_uint32x2_t r10 = simde_vqshlu_n_s32(a, 10);
    simde_uint32x2_t r15 = simde_vqshlu_n_s32(a, 15);
    simde_uint32x2_t r23 = simde_vqshlu_n_s32(a, 23);
    simde_uint32x2_t r28 = simde_vqshlu_n_s32(a, 28);
    simde_uint32x2_t r31 = simde_vqshlu_n_s32(a, 31);

    simde_test_arm_neon_assert_equal_u32x2(r0, simde_vld1_u32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u32x2(r4, simde_vld1_u32(test_vec[i].r4));
    simde_test_arm_neon_assert_equal_u32x2(r10, simde_vld1_u32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u32x2(r15, simde_vld1_u32(test_vec[i].r15));
    simde_test_arm_neon_assert_equal_u32x2(r23, simde_vld1_u32(test_vec[i].r23));
    simde_test_arm_neon_assert_equal_u32x2(r28, simde_vld1_u32(test_vec[i].r28));
    simde_test_arm_neon_assert_equal_u32x2(r31, simde_vld1_u32(test_vec[i].r31));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_uint32x2_t r0 = simde_vqshlu_n_s32(a, 0);
    simde_uint32x2_t r4 = simde_vqshlu_n_s32(a, 4);
    simde_uint32x2_t r10 = simde_vqshlu_n_s32(a, 10);
    simde_uint32x2_t r15 = simde_vqshlu_n_s32(a, 15);
    simde_uint32x2_t r23 = simde_vqshlu_n_s32(a, 23);
    simde_uint32x2_t r28 = simde_vqshlu_n_s32(a, 28);
    simde_uint32x2_t r31 = simde_vqshlu_n_s32(a, 31);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r15, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r28, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlu_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    uint64_t r0[1];
    uint64_t r3[1];
    uint64_t r12[1];
    uint64_t r27[1];
    uint64_t r35[1];
    uint64_t r48[1];
    uint64_t r63[1];
  } test_vec[] = {
    { {  INT64_C( 5072672013399964110) },
      { UINT64_C( 5072672013399964110) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } },
    { {  INT64_C( 6677610278852285409) },
      { UINT64_C( 6677610278852285409) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } },
    { { -INT64_C( 8033029934178609758) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 3529324990751820018) },
      { UINT64_C( 3529324990751820018) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } },
    { {  INT64_C( 7025476331418468327) },
      { UINT64_C( 7025476331418468327) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } },
    { {  INT64_C( 4745482970623441748) },
      { UINT64_C( 4745482970623441748) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } },
    { { -INT64_C( 1003541852673011796) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 5984773099453005181) },
      { UINT64_C( 5984773099453005181) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_uint64x1_t r0 = simde_vqshlu_n_s64(a, 0);
    simde_uint64x1_t r3 = simde_vqshlu_n_s64(a, 3);
    simde_uint64x1_t r12 = simde_vqshlu_n_s64(a, 12);
    simde_uint64x1_t r27 = simde_vqshlu_n_s64(a, 27);
    simde_uint64x1_t r35 = simde_vqshlu_n_s64(a, 35);
    simde_uint64x1_t r48 = simde_vqshlu_n_s64(a, 48);
    simde_uint64x1_t r63 = simde_vqshlu_n_s64(a, 63);

    simde_test_arm_neon_assert_equal_u64x1(r0, simde_vld1_u64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u64x1(r3, simde_vld1_u64(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u64x1(r12, simde_vld1_u64(test_vec[i].r12));
    simde_test_arm_neon_assert_equal_u64x1(r27, simde_vld1_u64(test_vec[i].r27));
    simde_test_arm_neon_assert_equal_u64x1(r35, simde_vld1_u64(test_vec[i].r35));
    simde_test_arm_neon_assert_equal_u64x1(r48, simde_vld1_u64(test_vec[i].r48));
    simde_test_arm_neon_assert_equal_u64x1(r63, simde_vld1_u64(test_vec[i].r63));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_uint64x1_t r0 = simde_vqshlu_n_s64(a, 0);
    simde_uint64x1_t r3 = simde_vqshlu_n_s64(a, 3);
    simde_uint64x1_t r12 = simde_vqshlu_n_s64(a, 12);
    simde_uint64x1_t r27 = simde_vqshlu_n_s64(a, 27);
    simde_uint64x1_t r35 = simde_vqshlu_n_s64(a, 35);
    simde_uint64x1_t r48 = simde_vqshlu_n_s64(a, 48);
    simde_uint64x1_t r63 = simde_vqshlu_n_s64(a, 63);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r27, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r35, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r48, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshluq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    const int n;
    uint8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  13), -INT8_C(  72), -INT8_C(  26), -INT8_C(  14), -INT8_C(   8),  INT8_C(  33),  INT8_C(  14),  INT8_C( 109),
         INT8_C(  34), -INT8_C(  11), -INT8_C(  47), -INT8_C(  30),  INT8_C(   2), -INT8_C(  53),  INT8_C( 104), -INT8_C( 114) },
       INT32_C(           0),
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 33), UINT8_C( 14), UINT8_C(109),
        UINT8_C( 34), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(104), UINT8_C(  0) } },
    { { -INT8_C(  53),  INT8_C(  80), -INT8_C(  57), -INT8_C( 121), -INT8_C(   3), -INT8_C(  82),  INT8_C(   7), -INT8_C( 104),
         INT8_C(  56), -INT8_C(  93),      INT8_MAX, -INT8_C( 124), -INT8_C(  69), -INT8_C(  61),  INT8_C( 124), -INT8_C(  82) },
       INT32_C(           1),
      { UINT8_C(  0), UINT8_C(160), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 14), UINT8_C(  0),
        UINT8_C(112), UINT8_C(  0), UINT8_C(254), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(248), UINT8_C(  0) } },
    { {  INT8_C( 123),  INT8_C(  98), -INT8_C(  96),  INT8_C( 116), -INT8_C( 125), -INT8_C(  81), -INT8_C(  31), -INT8_C(  91),
        -INT8_C(  92), -INT8_C(  78), -INT8_C( 120), -INT8_C(  89),  INT8_C( 125), -INT8_C(  16),  INT8_C(  53),  INT8_C(  73) },
       INT32_C(           2),
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(212),    UINT8_MAX } },
    { {  INT8_C(  64), -INT8_C(   4), -INT8_C(  48),  INT8_C(  61), -INT8_C(  86), -INT8_C(  41), -INT8_C(  43), -INT8_C(  30),
         INT8_C( 123),  INT8_C(  84),  INT8_C( 102),  INT8_C(  54),  INT8_C(  24), -INT8_C(  30), -INT8_C(  27), -INT8_C( 109) },
       INT32_C(           3),
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(192), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  68), -INT8_C( 123),  INT8_C(   7), -INT8_C(  57),  INT8_C(  52), -INT8_C(  23),  INT8_C( 109), -INT8_C(  39),
        -INT8_C( 101), -INT8_C(  11),      INT8_MIN,  INT8_C(  25), -INT8_C(  27), -INT8_C(  75),  INT8_C(  98),  INT8_C(  37) },
       INT32_C(           4),
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(112), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  79),  INT8_C(  50),  INT8_C(  98),  INT8_C(  91),  INT8_C(  10),  INT8_C(  56),  INT8_C(  62), -INT8_C( 123),
        -INT8_C( 116), -INT8_C(  92), -INT8_C(  69), -INT8_C(  92), -INT8_C( 121), -INT8_C(  96),  INT8_C(  56), -INT8_C(  53) },
       INT32_C(           5),
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  38),  INT8_C(  63), -INT8_C( 109),  INT8_C(  90),  INT8_C(  40),  INT8_C(   0),  INT8_C(  51), -INT8_C(  60),
        -INT8_C(  11), -INT8_C(  77), -INT8_C(  35), -INT8_C(  38),  INT8_C( 104),  INT8_C(  63), -INT8_C(   1),  INT8_C(  25) },
       INT32_C(           6),
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 113),  INT8_C(  97),  INT8_C( 117),  INT8_C( 123), -INT8_C( 103), -INT8_C(  77),  INT8_C(   0),  INT8_C(  38),
         INT8_C(  87), -INT8_C(  68), -INT8_C(  54), -INT8_C(  34),  INT8_C(  92),  INT8_C(   2), -INT8_C(  86), -INT8_C( 126) },
       INT32_C(           7),
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_uint8x16_t r;
    SIMDE_CONSTIFY_8_(simde_vqshluq_n_s8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int n[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_uint8x16_t r;
    SIMDE_CONSTIFY_8_(simde_vqshluq_n_s8, r, (HEDLEY_UNREACHABLE(), r), n[i], a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, n[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshluq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    uint16_t r0[8];
    uint16_t r2[8];
    uint16_t r5[8];
    uint16_t r9[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r15[8];
  } test_vec[] = {
    { {  INT16_C(  7690), -INT16_C(  5215),  INT16_C(  8941), -INT16_C(  2856), -INT16_C( 19412), -INT16_C( 31048),  INT16_C(  2621), -INT16_C( 11962) },
      { UINT16_C( 7690), UINT16_C(    0), UINT16_C( 8941), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 2621), UINT16_C(    0) },
      { UINT16_C(30760), UINT16_C(    0), UINT16_C(35764), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(10484), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(   485),  INT16_C( 17765),  INT16_C( 24754), -INT16_C( 19795), -INT16_C( 22943), -INT16_C(  9095),  INT16_C( 22537),  INT16_C(  5055) },
      { UINT16_C(  485), UINT16_C(17765), UINT16_C(24754), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(22537), UINT16_C( 5055) },
      { UINT16_C( 1940),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(20220) },
      { UINT16_C(15520),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 24694),  INT16_C( 25854), -INT16_C( 10622), -INT16_C( 20648),  INT16_C(  4490), -INT16_C( 14539),  INT16_C( 31771),  INT16_C(   409) },
      { UINT16_C(24694), UINT16_C(25854), UINT16_C(    0), UINT16_C(    0), UINT16_C( 4490), UINT16_C(    0), UINT16_C(31771), UINT16_C(  409) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(17960), UINT16_C(    0),      UINT16_MAX, UINT16_C( 1636) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(13088) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C(   387),  INT16_C( 12358), -INT16_C(  2978), -INT16_C( 16414),  INT16_C( 23450), -INT16_C( 23397),  INT16_C( 23219),  INT16_C( 10935) },
      { UINT16_C(    0), UINT16_C(12358), UINT16_C(    0), UINT16_C(    0), UINT16_C(23450), UINT16_C(    0), UINT16_C(23219), UINT16_C(10935) },
      { UINT16_C(    0), UINT16_C(49432), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(43740) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C( 18757),  INT16_C( 15758), -INT16_C(  6516),  INT16_C(  6124),  INT16_C(  8951),  INT16_C(  5086),  INT16_C( 30622),  INT16_C(  6932) },
      { UINT16_C(    0), UINT16_C(15758), UINT16_C(    0), UINT16_C( 6124), UINT16_C( 8951), UINT16_C( 5086), UINT16_C(30622), UINT16_C( 6932) },
      { UINT16_C(    0), UINT16_C(63032), UINT16_C(    0), UINT16_C(24496), UINT16_C(35804), UINT16_C(20344),      UINT16_MAX, UINT16_C(27728) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 23157), -INT16_C( 11445),  INT16_C( 11598), -INT16_C(  5741),  INT16_C( 11913),  INT16_C( 15501),  INT16_C( 17545),  INT16_C( 17510) },
      { UINT16_C(23157), UINT16_C(    0), UINT16_C(11598), UINT16_C(    0), UINT16_C(11913), UINT16_C(15501), UINT16_C(17545), UINT16_C(17510) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(46392), UINT16_C(    0), UINT16_C(47652), UINT16_C(62004),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C(  2822), -INT16_C( 30847),  INT16_C( 28379), -INT16_C( 11618),  INT16_C( 31888),  INT16_C( 12005), -INT16_C(  1548),  INT16_C( 26953) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(28379), UINT16_C(    0), UINT16_C(31888), UINT16_C(12005), UINT16_C(    0), UINT16_C(26953) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(48020), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 27308), -INT16_C( 24003), -INT16_C( 12094),  INT16_C( 19339),  INT16_C(  6398), -INT16_C( 30840), -INT16_C(  4515),  INT16_C( 22475) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(19339), UINT16_C( 6398), UINT16_C(    0), UINT16_C(    0), UINT16_C(22475) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(25592), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint16x8_t r0 = simde_vqshluq_n_s16(a, 0);
    simde_uint16x8_t r2 = simde_vqshluq_n_s16(a, 2);
    simde_uint16x8_t r5 = simde_vqshluq_n_s16(a, 5);
    simde_uint16x8_t r9 = simde_vqshluq_n_s16(a, 9);
    simde_uint16x8_t r10 = simde_vqshluq_n_s16(a, 10);
    simde_uint16x8_t r13 = simde_vqshluq_n_s16(a, 13);
    simde_uint16x8_t r15 = simde_vqshluq_n_s16(a, 15);

    simde_test_arm_neon_assert_equal_u16x8(r0, simde_vld1q_u16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u16x8(r2, simde_vld1q_u16(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_u16x8(r5, simde_vld1q_u16(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u16x8(r9, simde_vld1q_u16(test_vec[i].r9));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r15, simde_vld1q_u16(test_vec[i].r15));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_uint16x8_t r0 = simde_vqshluq_n_s16(a, 0);
    simde_uint16x8_t r2 = simde_vqshluq_n_s16(a, 2);
    simde_uint16x8_t r5 = simde_vqshluq_n_s16(a, 5);
    simde_uint16x8_t r9 = simde_vqshluq_n_s16(a, 9);
    simde_uint16x8_t r10 = simde_vqshluq_n_s16(a, 10);
    simde_uint16x8_t r13 = simde_vqshluq_n_s16(a, 13);
    simde_uint16x8_t r15 = simde_vqshluq_n_s16(a, 15);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r9, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshluq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint32_t r0[4];
    uint32_t r4[4];
    uint32_t r10[4];
    uint32_t r15[4];
    uint32_t r23[4];
    uint32_t r28[4];
    uint32_t r31[4];
  } test_vec[] = {
    { {  INT32_C(   347520906),  INT32_C(  1268454275), -INT32_C(    44010171),  INT32_C(  2018331281) },
      { UINT32_C( 347520906), UINT32_C(1268454275), UINT32_C(         0), UINT32_C(2018331281) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   803026077), -INT32_C(  1721349556),  INT32_C(  1100880288), -INT32_C(   705448886) },
      { UINT32_C( 803026077), UINT32_C(         0), UINT32_C(1100880288), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(   152458893),  INT32_C(    37848253), -INT32_C(  1946180870), -INT32_C(  1996272404) },
      { UINT32_C(         0), UINT32_C(  37848253), UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C( 605572048), UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(   860233600), -INT32_C(   882499797), -INT32_C(  2096364488),  INT32_C(   744030136) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 744030136) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1713521065), -INT32_C(  1066900282), -INT32_C(   229939450),  INT32_C(   863784627) },
      { UINT32_C(1713521065), UINT32_C(         0), UINT32_C(         0), UINT32_C( 863784627) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1493185838), -INT32_C(  1943706028),  INT32_C(   571421034), -INT32_C(   632395983) },
      { UINT32_C(1493185838), UINT32_C(         0), UINT32_C( 571421034), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(  1866494377), -INT32_C(   617633579), -INT32_C(  1026721265), -INT32_C(   151696952) },
      { UINT32_C(1866494377), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(   766446210), -INT32_C(   983599781), -INT32_C(   672633178),  INT32_C(  2142320342) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2142320342) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint32x4_t r0 = simde_vqshluq_n_s32(a, 0);
    simde_uint32x4_t r4 = simde_vqshluq_n_s32(a, 4);
    simde_uint32x4_t r10 = simde_vqshluq_n_s32(a, 10);
    simde_uint32x4_t r15 = simde_vqshluq_n_s32(a, 15);
    simde_uint32x4_t r23 = simde_vqshluq_n_s32(a, 23);
    simde_uint32x4_t r28 = simde_vqshluq_n_s32(a, 28);
    simde_uint32x4_t r31 = simde_vqshluq_n_s32(a, 31);

    simde_test_arm_neon_assert_equal_u32x4(r0, simde_vld1q_u32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u32x4(r4, simde_vld1q_u32(test_vec[i].r4));
    simde_test_arm_neon_assert_equal_u32x4(r10, simde_vld1q_u32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u32x4(r15, simde_vld1q_u32(test_vec[i].r15));
    simde_test_arm_neon_assert_equal_u32x4(r23, simde_vld1q_u32(test_vec[i].r23));
    simde_test_arm_neon_assert_equal_u32x4(r28, simde_vld1q_u32(test_vec[i].r28));
    simde_test_arm_neon_assert_equal_u32x4(r31, simde_vld1q_u32(test_vec[i].r31));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_uint32x4_t r0 = simde_vqshluq_n_s32(a, 0);
    simde_uint32x4_t r4 = simde_vqshluq_n_s32(a, 4);
    simde_uint32x4_t r10 = simde_vqshluq_n_s32(a, 10);
    simde_uint32x4_t r15 = simde_vqshluq_n_s32(a, 15);
    simde_uint32x4_t r23 = simde_vqshluq_n_s32(a, 23);
    simde_uint32x4_t r28 = simde_vqshluq_n_s32(a, 28);
    simde_uint32x4_t r31 = simde_vqshluq_n_s32(a, 31);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r15, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r28, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshluq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    uint64_t r0[2];
    uint64_t r3[2];
    uint64_t r12[2];
    uint64_t r27[2];
    uint64_t r35[2];
    uint64_t r48[2];
    uint64_t r63[2];
  } test_vec[] = {
    { { -INT64_C( 1209751964727193159), -INT64_C( 2341309450467053371) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) } },
        { {  INT64_C(  492815255323390162), -INT64_C( 1365191897190827129) },
          { UINT64_C(  492815255323390162), UINT64_C(                   0) },
          { UINT64_C( 3942522042587121296), UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) } },
        { {  INT64_C(  404628253405423535),  INT64_C( 1534651336357594104) },
          { UINT64_C(  404628253405423535), UINT64_C( 1534651336357594104) },
          { UINT64_C( 3237026027243388280), UINT64_C(12277210690860752832) },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX } },
        { {  INT64_C( 1856051024682204894),  INT64_C(    9011946065458431) },
          { UINT64_C( 1856051024682204894), UINT64_C(    9011946065458431) },
          { UINT64_C(14848408197457639152), UINT64_C(   72095568523667448) },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX } },
        { { -INT64_C( 1121311677372993237),  INT64_C( 2947511719470898575) },
          { UINT64_C(                   0), UINT64_C( 2947511719470898575) },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX } },
        { {  INT64_C( 1735194386958128488),  INT64_C( 4209857465653332762) },
          { UINT64_C( 1735194386958128488), UINT64_C( 4209857465653332762) },
          { UINT64_C(13881555095665027904),                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX } },
        { { -INT64_C(  593043140707476516),  INT64_C( 3865971726786044723) },
          { UINT64_C(                   0), UINT64_C( 3865971726786044723) },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX } },
        { {  INT64_C( 5401578680242637509), -INT64_C( 8459973772018564530) },
          { UINT64_C( 5401578680242637509), UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint64x2_t r0 = simde_vqshluq_n_s64(a, 0);
    simde_uint64x2_t r3 = simde_vqshluq_n_s64(a, 3);
    simde_uint64x2_t r12 = simde_vqshluq_n_s64(a, 12);
    simde_uint64x2_t r27 = simde_vqshluq_n_s64(a, 27);
    simde_uint64x2_t r35 = simde_vqshluq_n_s64(a, 35);
    simde_uint64x2_t r48 = simde_vqshluq_n_s64(a, 48);
    simde_uint64x2_t r63 = simde_vqshluq_n_s64(a, 63);

    simde_test_arm_neon_assert_equal_u64x2(r0, simde_vld1q_u64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u64x2(r3, simde_vld1q_u64(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u64x2(r12, simde_vld1q_u64(test_vec[i].r12));
    simde_test_arm_neon_assert_equal_u64x2(r27, simde_vld1q_u64(test_vec[i].r27));
    simde_test_arm_neon_assert_equal_u64x2(r35, simde_vld1q_u64(test_vec[i].r35));
    simde_test_arm_neon_assert_equal_u64x2(r48, simde_vld1q_u64(test_vec[i].r48));
    simde_test_arm_neon_assert_equal_u64x2(r63, simde_vld1q_u64(test_vec[i].r63));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_uint64x2_t r0 = simde_vqshluq_n_s64(a, 0);
    simde_uint64x2_t r3 = simde_vqshluq_n_s64(a, 3);
    simde_uint64x2_t r12 = simde_vqshluq_n_s64(a, 12);
    simde_uint64x2_t r27 = simde_vqshluq_n_s64(a, 27);
    simde_uint64x2_t r35 = simde_vqshluq_n_s64(a, 35);
    simde_uint64x2_t r48 = simde_vqshluq_n_s64(a, 48);
    simde_uint64x2_t r63 = simde_vqshluq_n_s64(a, 63);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r27, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r35, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r48, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlu_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlu_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlu_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlu_n_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqshluq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshluq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshluq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshluq_n_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
