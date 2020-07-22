#define SIMDE_TEST_ARM_NEON_INSN qmovun

#include "test-neon.h"
#include "../../../simde/arm/neon/qmovun.h"

static int
test_simde_vqmovun_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { { -INT16_C( 18345),  INT16_C(  7399), -INT16_C(  5353), -INT16_C( 25148), -INT16_C( 27188),  INT16_C( 13769),  INT16_C(   990),  INT16_C(  9688) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT16_C( 27133),  INT16_C( 15294), -INT16_C( 22736),  INT16_C( 17779),  INT16_C( 32692),  INT16_C( 10966),  INT16_C( 17328),  INT16_C(  1930) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT16_C( 29179),  INT16_C(  4643), -INT16_C(  6308),  INT16_C( 10671),  INT16_C( 30844),  INT16_C( 23134),  INT16_C( 13948),  INT16_C( 31103) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT16_C( 16031), -INT16_C( 12364),  INT16_C( 10213), -INT16_C( 26091), -INT16_C(  5210),  INT16_C( 22468),  INT16_C( 20014),  INT16_C( 10590) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT16_C( 32064),  INT16_C(  7227), -INT16_C(  5527), -INT16_C(  6587), -INT16_C( 23709), -INT16_C(  8384), -INT16_C( 16167),  INT16_C( 30808) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT16_C(  3326), -INT16_C(  7352),  INT16_C( 23859), -INT16_C(  9859),  INT16_C( 16712),  INT16_C( 30256), -INT16_C( 28784),  INT16_C( 20639) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { -INT16_C(  9711),  INT16_C( 31340), -INT16_C( 19772),  INT16_C( 10080), -INT16_C( 24235),  INT16_C( 12038),  INT16_C( 24161),  INT16_C( 24487) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT16_C(  4246), -INT16_C( 25278), -INT16_C( 16308), -INT16_C( 27529), -INT16_C( 22783), -INT16_C( 28406), -INT16_C( 22218),  INT16_C( 18401) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint8x8_t r = simde_vqmovun_s16(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_uint8x8_t r = simde_vqmovun_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovun_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1811669884), -INT32_C(  1616095694),  INT32_C(  1505503431),  INT32_C(   410694829) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT32_C(   428853893),  INT32_C(  1008142342),  INT32_C(   497592662),  INT32_C(   932503994) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { -INT32_C(   140341307), -INT32_C(  1399435547),  INT32_C(   604394358), -INT32_C(  2109964281) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT32_C(  1133990474),  INT32_C(   200835253), -INT32_C(   483876823),  INT32_C(  1176157313) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT32_C(   826195275), -INT32_C(  2099391477),  INT32_C(   782689063),  INT32_C(   447799908) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT32_C(  1171659151), -INT32_C(  1034891623), -INT32_C(   274368146), -INT32_C(  2127118283) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { -INT32_C(  2001570691),  INT32_C(  1879740232), -INT32_C(   677465997),  INT32_C(   586239891) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT32_C(    23578472),  INT32_C(    63158421),  INT32_C(  1727162417), -INT32_C(  1511577560) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint16x4_t r = simde_vqmovun_s32(a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_uint16x4_t r = simde_vqmovun_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovun_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { -INT64_C( 5425750683829434048), -INT64_C( 7162323672895373370) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { -INT64_C( 5585277752272748202),  INT64_C( 1967427466993443775) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT64_C( 8318933209745641790), -INT64_C( 3732010236125240056) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT64_C(  907126553308030658), -INT64_C( 2749521670418995231) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { -INT64_C( 4634756288245928563), -INT64_C( 3859146670975987666) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT64_C( 5751074110553797031), -INT64_C( 8626675892199145774) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT64_C( 1533037962395377360), -INT64_C( 3163731268945142079) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT64_C( 6204411644969261404), -INT64_C( 2791938161888713282) },
      {           UINT32_MAX, UINT32_C(         0) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint32x2_t r = simde_vqmovun_s64(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_uint32x2_t r = simde_vqmovun_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovun_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovun_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovun_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
