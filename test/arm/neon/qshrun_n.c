#define SIMDE_TEST_ARM_NEON_INSN qshrun_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qshrun_n.h"

static int
test_simde_vqshrun_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec[] = {
    { {  INT16_C( 16778), -INT16_C(  3511),  INT16_C(  3623), -INT16_C( 12553), -INT16_C( 21552),  INT16_C( 14428), -INT16_C(  7152), -INT16_C(   804) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(113), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C( 56), UINT8_C(  0), UINT8_C(  0), UINT8_C(225), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C( 65), UINT8_C(  0), UINT8_C( 14), UINT8_C(  0), UINT8_C(  0), UINT8_C( 56), UINT8_C(  0), UINT8_C(  0) } },
    { { -INT16_C( 24341),  INT16_C( 22691),  INT16_C( 19770), -INT16_C( 13268), -INT16_C( 21048), -INT16_C(  6044),  INT16_C( 26120), -INT16_C( 28048) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C( 88), UINT8_C( 77), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(102), UINT8_C(  0) } },
    { { -INT16_C( 18009), -INT16_C( 12667),  INT16_C( 31944), -INT16_C( 26468), -INT16_C(  2009),  INT16_C( 14544), -INT16_C( 21284), -INT16_C( 14284) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(227), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(124), UINT8_C(  0), UINT8_C(  0), UINT8_C( 56), UINT8_C(  0), UINT8_C(  0) } },
    { { -INT16_C( 10419), -INT16_C( 30944),  INT16_C( 19748), -INT16_C(  5036), -INT16_C( 18182),  INT16_C(   725),  INT16_C( 17694), -INT16_C( 14956) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C( 90),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C( 22),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C( 11),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C( 77), UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C( 69), UINT8_C(  0) } },
    { {  INT16_C(  6655), -INT16_C( 14445),  INT16_C( 12438), -INT16_C( 17057),  INT16_C( 12328),  INT16_C(  1525),  INT16_C( 10716),  INT16_C( 10701) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(190),    UINT8_MAX,    UINT8_MAX },
      { UINT8_C(207), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C( 47),    UINT8_MAX,    UINT8_MAX },
      { UINT8_C(103), UINT8_C(  0), UINT8_C(194), UINT8_C(  0), UINT8_C(192), UINT8_C( 23), UINT8_C(167), UINT8_C(167) },
      { UINT8_C( 25), UINT8_C(  0), UINT8_C( 48), UINT8_C(  0), UINT8_C( 48), UINT8_C(  5), UINT8_C( 41), UINT8_C( 41) } },
    { { -INT16_C(  4864),  INT16_C(  9393),  INT16_C(  1338),  INT16_C( 13329), -INT16_C(  6467), -INT16_C(  9418), -INT16_C( 13525),  INT16_C( 10912) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(167),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C( 41),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX },
      { UINT8_C(  0), UINT8_C(146), UINT8_C( 20), UINT8_C(208), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(170) },
      { UINT8_C(  0), UINT8_C( 36), UINT8_C(  5), UINT8_C( 52), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 42) } },
    { {  INT16_C( 13284),  INT16_C( 31473),  INT16_C( 20835), -INT16_C( 29640),  INT16_C( 11649),  INT16_C( 23953),  INT16_C( 24151),  INT16_C( 22407) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      { UINT8_C(207),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(182),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      { UINT8_C( 51), UINT8_C(122), UINT8_C( 81), UINT8_C(  0), UINT8_C( 45), UINT8_C( 93), UINT8_C( 94), UINT8_C( 87) } },
    { {  INT16_C( 14411), -INT16_C( 31108), -INT16_C( 29379), -INT16_C(  1350), -INT16_C(  3725), -INT16_C( 24875),  INT16_C( 30140), -INT16_C( 24375) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(225), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C( 56), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(117), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_uint8x8_t r1 = simde_vqshrun_n_s16(a, 1);
    simde_uint8x8_t r3 = simde_vqshrun_n_s16(a, 3);
    simde_uint8x8_t r5 = simde_vqshrun_n_s16(a, 5);
    simde_uint8x8_t r6 = simde_vqshrun_n_s16(a, 6);
    simde_uint8x8_t r8 = simde_vqshrun_n_s16(a, 8);

    simde_test_arm_neon_assert_equal_u8x8(r1, simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r6, simde_vld1_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x8(r8, simde_vld1_u8(test_vec[i].r8));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();

    simde_uint8x8_t r1 = simde_vqshrun_n_s16(a, 1);
    simde_uint8x8_t r3 = simde_vqshrun_n_s16(a, 3);
    simde_uint8x8_t r5 = simde_vqshrun_n_s16(a, 5);
    simde_uint8x8_t r6 = simde_vqshrun_n_s16(a, 6);
    simde_uint8x8_t r8 = simde_vqshrun_n_s16(a, 8);

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
test_simde_vqshrun_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { {  INT32_C(   504599800),  INT32_C(  1231001018), -INT32_C(  1027622279), -INT32_C(  2117994500) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(61596),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C( 7699), UINT16_C(18783), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT32_C(   196433223), -INT32_C(  1629348972),  INT32_C(  1413801511),  INT32_C(   815101496) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(23978), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C( 2997), UINT16_C(    0), UINT16_C(21572), UINT16_C(12437) } },
    { { -INT32_C(  1001478134), -INT32_C(  1240617667),  INT32_C(  1668861287),  INT32_C(   199506372) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(24353) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(25464), UINT16_C( 3044) } },
    { {  INT32_C(   588683663), -INT32_C(   591267659),  INT32_C(   389088735), -INT32_C(  2042116484) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(47496), UINT16_C(    0) },
      { UINT16_C( 8982), UINT16_C(    0), UINT16_C( 5937), UINT16_C(    0) } },
    { { -INT32_C(  1404332689), -INT32_C(  1436329918), -INT32_C(   384967899), -INT32_C(  1527451115) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT32_C(  1086786443), -INT32_C(   501380861),  INT32_C(   184110734), -INT32_C(  2087632876) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(22474), UINT16_C(    0) },
      { UINT16_C(16583), UINT16_C(    0), UINT16_C( 2809), UINT16_C(    0) } },
    { {  INT32_C(   405855445),  INT32_C(  1522701108), -INT32_C(  2092707986),  INT32_C(  1294416065) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(49542),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C( 6192), UINT16_C(23234), UINT16_C(    0), UINT16_C(19751) } },
    { {  INT32_C(  1183706947),  INT32_C(   103393912),  INT32_C(   219226872),  INT32_C(   949002851) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(12621), UINT16_C(26761),      UINT16_MAX },
      { UINT16_C(18061), UINT16_C( 1577), UINT16_C( 3345), UINT16_C(14480) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_uint16x4_t r3 = simde_vqshrun_n_s32(a, 3);
    simde_uint16x4_t r6 = simde_vqshrun_n_s32(a, 6);
    simde_uint16x4_t r10 = simde_vqshrun_n_s32(a, 10);
    simde_uint16x4_t r13 = simde_vqshrun_n_s32(a, 13);
    simde_uint16x4_t r16 = simde_vqshrun_n_s32(a, 16);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r16, simde_vld1_u16(test_vec[i].r16));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();

    simde_uint16x4_t r3 = simde_vqshrun_n_s32(a, 3);
    simde_uint16x4_t r6 = simde_vqshrun_n_s32(a, 6);
    simde_uint16x4_t r10 = simde_vqshrun_n_s32(a, 10);
    simde_uint16x4_t r13 = simde_vqshrun_n_s32(a, 13);
    simde_uint16x4_t r16 = simde_vqshrun_n_s32(a, 16);

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
test_simde_vqshrun_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { -INT64_C( 8010161828187854301),  INT64_C( 1168589133413045559) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C( 272083360) } },
    { { -INT64_C( 5854951606406895756),  INT64_C(  616105728906045207) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C( 143448293) } },
    { {  INT64_C( 7842072300341757186),  INT64_C( 7541767909253925881) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(1825874741), UINT32_C(1755954676) } },
    { { -INT64_C( 3775402194840015772), -INT64_C(  204979778989186502) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { -INT64_C( 7968814318827211576),  INT64_C( 1206071537328385888) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C( 280810412) } },
    { {  INT64_C( 6773299641568792703), -INT64_C( 4489345585647962438) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      { UINT32_C(1577031715), UINT32_C(         0) } },
    { {  INT64_C( 7548357366580704152),  INT64_C( 4455037217105832726) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(1757488904), UINT32_C(1037269182) } },
    { {  INT64_C( 2452897641440333961), -INT64_C( 4440116941430487385) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      { UINT32_C( 571109736), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_uint32x2_t r6 = simde_vqshrun_n_s64(a, 6);
    simde_uint32x2_t r13 = simde_vqshrun_n_s64(a, 13);
    simde_uint32x2_t r19 = simde_vqshrun_n_s64(a, 19);
    simde_uint32x2_t r26 = simde_vqshrun_n_s64(a, 26);
    simde_uint32x2_t r32 = simde_vqshrun_n_s64(a, 32);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r32, simde_vld1_u32(test_vec[i].r32));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();

    simde_uint32x2_t r6 = simde_vqshrun_n_s64(a, 6);
    simde_uint32x2_t r13 = simde_vqshrun_n_s64(a, 13);
    simde_uint32x2_t r19 = simde_vqshrun_n_s64(a, 19);
    simde_uint32x2_t r26 = simde_vqshrun_n_s64(a, 26);
    simde_uint32x2_t r32 = simde_vqshrun_n_s64(a, 32);

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
test_simde_vqshruns_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    uint16_t r3;
    uint16_t r6;
    uint16_t r10;
    uint16_t r13;
    uint16_t r16;
  } test_vec[] = {
    { -INT32_C(   184642193),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT32_C(  1107660539),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(16901) },
    {  INT32_C(   833713747),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(12721) },
    { -INT32_C(   478242132),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    { -INT32_C(   768980099),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT32_C(   929882231),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(14188) },
    {  INT32_C(   182181552),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(22238),
      UINT16_C( 2779) },
    {  INT32_C(  2067250188),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(31543) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r3 = simde_vqshruns_n_s32(test_vec[i].a, 3);
    uint16_t r6 = simde_vqshruns_n_s32(test_vec[i].a, 6);
    uint16_t r10 = simde_vqshruns_n_s32(test_vec[i].a, 10);
    uint16_t r13 = simde_vqshruns_n_s32(test_vec[i].a, 13);
    uint16_t r16 = simde_vqshruns_n_s32(test_vec[i].a, 16);

    simde_assert_equal_u16(r3, test_vec[i].r3);
    simde_assert_equal_u16(r6, test_vec[i].r6);
    simde_assert_equal_u16(r10, test_vec[i].r10);
    simde_assert_equal_u16(r13, test_vec[i].r13);
    simde_assert_equal_u16(r16, test_vec[i].r16);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();

    uint16_t r3 = simde_vqshruns_n_s32(a, 3);
    uint16_t r6 = simde_vqshruns_n_s32(a, 6);
    uint16_t r10 = simde_vqshruns_n_s32(a, 10);
    uint16_t r13 = simde_vqshruns_n_s32(a, 13);
    uint16_t r16 = simde_vqshruns_n_s32(a, 16);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vqshrund_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    uint32_t r6;
    uint32_t r13;
    uint32_t r19;
    uint32_t r26;
    uint32_t r32;
  } test_vec[] = {
    { -INT64_C( 3436115406163609968),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT64_C( 2921505763109135262),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C( 680216067) },
    { -INT64_C(  235602611085405263),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    { -INT64_C(  461594321089150934),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT64_C(  800403152976868876),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C( 186358381) },
    {  INT64_C( 8298122835898825725),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(1932057281) },
    {  INT64_C( 7139779055768650093),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(1662359353) },
    {  INT64_C( 6681961207257119064),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(1555765328) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r6 = simde_vqshrund_n_s64(test_vec[i].a, 6);
    uint32_t r13 = simde_vqshrund_n_s64(test_vec[i].a, 13);
    uint32_t r19 = simde_vqshrund_n_s64(test_vec[i].a, 19);
    uint32_t r26 = simde_vqshrund_n_s64(test_vec[i].a, 26);
    uint32_t r32 = simde_vqshrund_n_s64(test_vec[i].a, 32);

    simde_assert_equal_u32(r6, test_vec[i].r6);
    simde_assert_equal_u32(r13, test_vec[i].r13);
    simde_assert_equal_u32(r19, test_vec[i].r19);
    simde_assert_equal_u32(r26, test_vec[i].r26);
    simde_assert_equal_u32(r32, test_vec[i].r32);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();

    uint32_t r6 = simde_vqshrund_n_s64(a, 6);
    uint32_t r13 = simde_vqshrund_n_s64(a, 13);
    uint32_t r19 = simde_vqshrund_n_s64(a, 19);
    uint32_t r26 = simde_vqshrund_n_s64(a, 26);
    uint32_t r32 = simde_vqshrund_n_s64(a, 32);

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

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrun_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrun_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrun_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshruns_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshrund_n_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
