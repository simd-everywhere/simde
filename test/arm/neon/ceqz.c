#define SIMDE_TEST_ARM_NEON_INSN ceqz

#include "test-neon.h"
#include <simde/arm/neon/ceqz.h>
#include <stdlib.h>

static int
test_simde_vceqz_f16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
  struct {
    simde_float16 a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   288.00), SIMDE_FLOAT16_VALUE(   217.88), SIMDE_FLOAT16_VALUE(   992.00), SIMDE_FLOAT16_VALUE(  -163.88) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   253.88), SIMDE_FLOAT16_VALUE(    43.75), SIMDE_FLOAT16_VALUE(   -87.38), SIMDE_FLOAT16_VALUE(  -653.50) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -944.50), SIMDE_FLOAT16_VALUE(    25.94), SIMDE_FLOAT16_VALUE(   256.75), SIMDE_FLOAT16_VALUE(  -255.75) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   770.50), SIMDE_FLOAT16_VALUE(   141.50), SIMDE_FLOAT16_VALUE(   616.50), SIMDE_FLOAT16_VALUE(  -261.25) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -674.50), SIMDE_FLOAT16_VALUE(  -461.00), SIMDE_FLOAT16_VALUE(  -235.50), SIMDE_FLOAT16_VALUE(  -111.38) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   996.00), SIMDE_FLOAT16_VALUE(  -204.38), SIMDE_FLOAT16_VALUE(  -877.50), SIMDE_FLOAT16_VALUE(   514.50) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -850.50), SIMDE_FLOAT16_VALUE(   569.50), SIMDE_FLOAT16_VALUE(  -261.50), SIMDE_FLOAT16_VALUE(   174.38) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   983.00), SIMDE_FLOAT16_VALUE(   651.00), SIMDE_FLOAT16_VALUE(  -853.00), SIMDE_FLOAT16_VALUE(   270.75) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r = simde_vceqz_f16(a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
      simde_uint16x4_t r = simde_vceqz_f16(a);

      simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vceqz_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -327.33) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -721.62), SIMDE_FLOAT32_C(   916.22) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -765.93), SIMDE_FLOAT32_C(     0.00) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   995.55), SIMDE_FLOAT32_C(   510.58) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -157.84) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vceqz_f32(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqz_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -60.46) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -469.42) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -384.64) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   -89.50) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   584.35) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -326.83) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   994.82) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   158.46) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vceqz_f64(a);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqz_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { {  INT8_C(   0), -INT8_C(  94),  INT8_C(  67),  INT8_C(  58),  INT8_C(   0),  INT8_C(  42),  INT8_C(   0),  INT8_C(  18) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C( 111), -INT8_C(  68),  INT8_C(  92),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  10),  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(  18), -INT8_C(  63),  INT8_C(   0),  INT8_C(   0), -INT8_C(  21),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(   0),  INT8_C(   0),  INT8_C(  74), -INT8_C( 107),  INT8_C( 100),  INT8_C(  65), -INT8_C(  46),  INT8_C(  46) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   7), -INT8_C(  65),  INT8_C(  60), -INT8_C(  81) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(   0), -INT8_C(  27),  INT8_C(   0),  INT8_C(   0),  INT8_C(  38),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(   0),  INT8_C(   0), -INT8_C(  95), -INT8_C(  90),  INT8_C(   0), -INT8_C(  34),  INT8_C(  86),  INT8_C(   0) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 117), -INT8_C(  13),  INT8_C(  95),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 124),  INT8_C( 103) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_uint8x8_t r = simde_vceqz_s8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqz_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 17987) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(     0), -INT16_C( 20705),  INT16_C( 22988),  INT16_C(     0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 31482),  INT16_C(     0),  INT16_C(     0),  INT16_C(  3854) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14307) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(  6294),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C(     0),  INT16_C(     0),  INT16_C( 30481),  INT16_C(     0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_uint16x4_t r = simde_vceqz_s16(a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqz_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  2044598776), -INT32_C(  1438022561) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(           0), -INT32_C(  1360634674) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(           0), -INT32_C(   283258467) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(   159454426),  INT32_C(   232464368) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  2054051767),  INT32_C(   681421949) },
      { UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_uint32x2_t r = simde_vceqz_s32(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqz_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    uint64_t r[1];
  } test_vec[] = {
    { {  INT64_C(                   0) },
      {                    UINT64_MAX } },
    { {  INT64_C( 3454178962668484182) },
      { UINT64_C(                   0) } },
    { {  INT64_C(                   0) },
      {                    UINT64_MAX } },
    { {  INT64_C( 4224425884300989908) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 7039012478961771578) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 6037402715912565499) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 4197757843192524821) },
      { UINT64_C(                   0) } },
    { {  INT64_C(                   0) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_uint64x1_t r = simde_vceqz_s64(a);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqz_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(149), UINT8_C( 43), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 12), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(140), UINT8_C(107), UINT8_C( 23), UINT8_C(216), UINT8_C(  0), UINT8_C(  0), UINT8_C(209), UINT8_C(115) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 63), UINT8_C(114), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(225), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(164), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(187), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(178) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(177), UINT8_C(  0), UINT8_C(134), UINT8_C( 85), UINT8_C(228), UINT8_C(147), UINT8_C( 20), UINT8_C(  0) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(  0), UINT8_C(  0), UINT8_C( 91), UINT8_C(165), UINT8_C(  0), UINT8_C(  0), UINT8_C( 88), UINT8_C(198) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(116), UINT8_C(226), UINT8_C( 91), UINT8_C( 88), UINT8_C(117), UINT8_C(111), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t r = simde_vceqz_u8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqz_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C( 3710), UINT16_C(    0), UINT16_C(34330), UINT16_C(30937) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(    0), UINT16_C(    0), UINT16_C(28771), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(15055), UINT16_C(    0), UINT16_C(    0), UINT16_C(59617) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(29424), UINT16_C(    0), UINT16_C(62941), UINT16_C(    0) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(12449), UINT16_C(  195), UINT16_C(45749), UINT16_C(34158) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(    0), UINT16_C(31294), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(44577), UINT16_C(16684), UINT16_C(34528), UINT16_C(33221) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(61498), UINT16_C(10225), UINT16_C(22388), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t r = simde_vceqz_u16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqz_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 644870060), UINT32_C(1756296162) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 722655423), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(         0), UINT32_C( 171113308) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3870260215), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3524516793), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(         0), UINT32_C(1719902769) },
      {           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t r = simde_vceqz_u32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqz_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(                   0) },
      {                    UINT64_MAX } },
    { { UINT64_C(                   0) },
      {                    UINT64_MAX } },
    { { UINT64_C(10791983333082230527) },
      { UINT64_C(                   0) } },
    { { UINT64_C(                   0) },
      {                    UINT64_MAX } },
    { { UINT64_C(                   0) },
      {                    UINT64_MAX } },
    { { UINT64_C( 7298863471407900586) },
      { UINT64_C(                   0) } },
    { { UINT64_C(13426132532232202525) },
      { UINT64_C(                   0) } },
    { { UINT64_C(                   0) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t r = simde_vceqz_u64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzq_f16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      simde_float16 a[8];
      uint16_t r[8];
    } test_vec[] = {
      { { SIMDE_FLOAT16_VALUE(   732.00), SIMDE_FLOAT16_VALUE(  -455.50), SIMDE_FLOAT16_VALUE(   260.75), SIMDE_FLOAT16_VALUE(   765.00),
        SIMDE_FLOAT16_VALUE(  -305.50), SIMDE_FLOAT16_VALUE(  -960.00), SIMDE_FLOAT16_VALUE(   373.50), SIMDE_FLOAT16_VALUE(   448.00) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -775.00), SIMDE_FLOAT16_VALUE(    50.47), SIMDE_FLOAT16_VALUE(   449.75), SIMDE_FLOAT16_VALUE(  -198.50),
        SIMDE_FLOAT16_VALUE(  -134.62), SIMDE_FLOAT16_VALUE(   689.00), SIMDE_FLOAT16_VALUE(  -391.25), SIMDE_FLOAT16_VALUE(  -461.50) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   302.50), SIMDE_FLOAT16_VALUE(   622.50), SIMDE_FLOAT16_VALUE(  -242.62), SIMDE_FLOAT16_VALUE(  -533.50),
        SIMDE_FLOAT16_VALUE(   145.00), SIMDE_FLOAT16_VALUE(   305.25), SIMDE_FLOAT16_VALUE(  -211.88), SIMDE_FLOAT16_VALUE(  -968.00) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -971.00), SIMDE_FLOAT16_VALUE(  -691.50), SIMDE_FLOAT16_VALUE(   874.50), SIMDE_FLOAT16_VALUE(  -996.50),
        SIMDE_FLOAT16_VALUE(  -325.25), SIMDE_FLOAT16_VALUE(   380.00), SIMDE_FLOAT16_VALUE(   544.00), SIMDE_FLOAT16_VALUE(  -593.50) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(   924.50), SIMDE_FLOAT16_VALUE(  -195.50), SIMDE_FLOAT16_VALUE(  -828.50), SIMDE_FLOAT16_VALUE(  -381.25),
        SIMDE_FLOAT16_VALUE(  -155.62), SIMDE_FLOAT16_VALUE(   545.00), SIMDE_FLOAT16_VALUE(  -933.00), SIMDE_FLOAT16_VALUE(    69.38) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -404.75), SIMDE_FLOAT16_VALUE(   516.50), SIMDE_FLOAT16_VALUE(   871.00), SIMDE_FLOAT16_VALUE(   460.75),
        SIMDE_FLOAT16_VALUE(   205.75), SIMDE_FLOAT16_VALUE(  -520.50), SIMDE_FLOAT16_VALUE(   999.00), SIMDE_FLOAT16_VALUE(  -491.75) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -898.00), SIMDE_FLOAT16_VALUE(  -243.50), SIMDE_FLOAT16_VALUE(   -25.36), SIMDE_FLOAT16_VALUE(   247.25),
        SIMDE_FLOAT16_VALUE(  -938.00), SIMDE_FLOAT16_VALUE(   763.00), SIMDE_FLOAT16_VALUE(   279.25), SIMDE_FLOAT16_VALUE(  -909.00) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { SIMDE_FLOAT16_VALUE(  -928.50), SIMDE_FLOAT16_VALUE(   153.75), SIMDE_FLOAT16_VALUE(  -905.50), SIMDE_FLOAT16_VALUE(  -254.00),
        SIMDE_FLOAT16_VALUE(  -466.25), SIMDE_FLOAT16_VALUE(   638.50), SIMDE_FLOAT16_VALUE(   152.50), SIMDE_FLOAT16_VALUE(  -542.00) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } }      
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
      simde_uint16x8_t r = simde_vceqzq_f16(a);

      simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
      simde_uint16x8_t r = simde_vceqzq_f16(a);

      simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vceqzq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -765.96), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -158.27) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -383.93), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -833.58), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -556.99) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -216.78), SIMDE_FLOAT32_C(  -123.11), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   892.89), SIMDE_FLOAT32_C(     0.00) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -117.11), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -727.26) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -788.65), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vceqzq_f32(a);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   962.42) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    85.69) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   551.75), SIMDE_FLOAT64_C(     0.00) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(    36.19), SIMDE_FLOAT64_C(   -43.32) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -973.94), SIMDE_FLOAT64_C(  -254.74) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   779.02), SIMDE_FLOAT64_C(   185.84) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vceqzq_f64(a);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    uint8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  28),  INT8_C( 118),  INT8_C(   0),  INT8_C(  65),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  51), -INT8_C( 106),  INT8_C(   0), -INT8_C(   3),  INT8_C(   0),  INT8_C(  32),  INT8_C(   0),  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(   0),  INT8_C( 100), -INT8_C(  19),  INT8_C(  99),  INT8_C(   0),  INT8_C(   0),  INT8_C( 104),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  64), -INT8_C(  39),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  46), -INT8_C(  44),  INT8_C(   0), -INT8_C(  31),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  20),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  58), -INT8_C( 122),  INT8_C(   0), -INT8_C(  36), -INT8_C( 114),  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(  62), -INT8_C( 123),  INT8_C(   0),  INT8_C(   0),  INT8_C(  68),  INT8_C(   0),  INT8_C(  68),  INT8_C(   0),
        -INT8_C(  66),  INT8_C(  10),  INT8_C(   0),  INT8_C(   0), -INT8_C(  25),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C(   0),  INT8_C(  43),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  75),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  88),  INT8_C(   0),  INT8_C(  37),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  83) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(   0),  INT8_C(   0),  INT8_C(  92), -INT8_C(  66), -INT8_C(  67),  INT8_C(   0),  INT8_C(   0), -INT8_C(   5),
         INT8_C(   0),  INT8_C(  32),  INT8_C(  32), -INT8_C(  29),  INT8_C(  69),  INT8_C(   0),  INT8_C(  54), -INT8_C(   7) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(   0),  INT8_C(   0), -INT8_C( 109),  INT8_C(   0), -INT8_C( 126), -INT8_C( 109),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  76),  INT8_C(   0),  INT8_C(   0), -INT8_C(   7),      INT8_MAX, -INT8_C(  21),  INT8_C(   0),  INT8_C(   0) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  39),  INT8_C(   0), -INT8_C(  98),  INT8_C(  91),  INT8_C(   0), -INT8_C( 104),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  99),  INT8_C(  50),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  89) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_uint8x16_t r = simde_vceqzq_s8(a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24335), -INT16_C( 21286),  INT16_C(     0),  INT16_C(     0),  INT16_C( 31836) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(     0),  INT16_C( 17565),  INT16_C( 24523),  INT16_C( 14671),  INT16_C(     0), -INT16_C( 17008), -INT16_C( 24709),  INT16_C(     0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 32471), -INT16_C( 10245), -INT16_C(  5524),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8174),  INT16_C(     0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 20265), -INT16_C( 15545),  INT16_C(     0),  INT16_C( 27834),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 17760) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 27239),  INT16_C( 29471),  INT16_C(     0),  INT16_C( 22936),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 11770) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(  9873), -INT16_C(  7958), -INT16_C( 20602),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14702),  INT16_C( 10900),  INT16_C(     0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C(   604),  INT16_C(  6091),  INT16_C( 15454), -INT16_C(  4273),  INT16_C(     0), -INT16_C(  5936),  INT16_C(     0),  INT16_C(     0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C( 31919),  INT16_C( 25758),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint16x8_t r = simde_vceqzq_s16(a);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   741828223), -INT32_C(  1231377400),  INT32_C(  1319317648),  INT32_C(           0) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(   858956050),  INT32_C(           0),  INT32_C(           0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1164997533),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(           0), -INT32_C(   564635233),  INT32_C(           0),  INT32_C(   586009733) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(   183776264),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1036285494),  INT32_C(           0) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1438651394), -INT32_C(  1538764752),  INT32_C(           0),  INT32_C(           0) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint32x4_t r = simde_vceqzq_s32(a);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzq_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    uint64_t r[2];
  } test_vec[] = {
    { {  INT64_C(                   0), -INT64_C( 1979153583605383721) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C( 5377894213596184894),  INT64_C( 3556417410291188140) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { {  INT64_C(                   0),  INT64_C( 3867993108857557819) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C( 8754853928386430442),  INT64_C(                   0) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { {  INT64_C(                   0), -INT64_C( 7029379564668574246) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C( 2748201011641982176),  INT64_C( 1808857410149651866) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { {  INT64_C(                   0), -INT64_C( 4758189311056880975) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C( 4405967909247061718), -INT64_C( 5912680786139810763) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint64x2_t r = simde_vceqzq_s64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(  0), UINT8_C(254), UINT8_C(  0), UINT8_C(  0), UINT8_C(153), UINT8_C(  0), UINT8_C(  0), UINT8_C(123),
        UINT8_C(  0), UINT8_C( 80), UINT8_C(211), UINT8_C(166), UINT8_C(186), UINT8_C(  5), UINT8_C( 21), UINT8_C(  0) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(246), UINT8_C(225), UINT8_C(  8), UINT8_C(144), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 56),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(141), UINT8_C(131) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(  0), UINT8_C(  0), UINT8_C(  6), UINT8_C( 60), UINT8_C( 36), UINT8_C(  0), UINT8_C(116), UINT8_C(231),
        UINT8_C(240), UINT8_C(  0), UINT8_C(  0), UINT8_C(212), UINT8_C( 71), UINT8_C(241), UINT8_C( 87), UINT8_C(  0) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(  0), UINT8_C(  0), UINT8_C( 13), UINT8_C(123), UINT8_C( 65), UINT8_C(130), UINT8_C( 98), UINT8_C(  0),
        UINT8_C(213), UINT8_C(  0), UINT8_C(  0), UINT8_C( 28), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(194) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(  0), UINT8_C( 39), UINT8_C(195), UINT8_C(  0), UINT8_C(169), UINT8_C( 37), UINT8_C(218), UINT8_C(126),
        UINT8_C(235), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 63), UINT8_C( 23), UINT8_C(  0), UINT8_C(  0) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(125), UINT8_C(  0), UINT8_C( 96), UINT8_C(  0), UINT8_C(245), UINT8_C(  0), UINT8_C(  0), UINT8_C(224),
        UINT8_C( 27), UINT8_C( 62), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(193), UINT8_C(229) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(  0), UINT8_C(  0), UINT8_C( 39), UINT8_C(  0), UINT8_C( 97), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C( 10), UINT8_C(  0), UINT8_C(215), UINT8_C(  0), UINT8_C( 48), UINT8_C(152), UINT8_C(  0), UINT8_C(  0) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 61), UINT8_C(  0), UINT8_C( 96), UINT8_C(  0), UINT8_C(  0), UINT8_C( 40), UINT8_C( 26), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(241), UINT8_C(172), UINT8_C(  0), UINT8_C(137), UINT8_C(  0), UINT8_C( 87), UINT8_C(  0) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t r = simde_vceqzq_u8(a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 2628), UINT16_C(    0), UINT16_C(    0), UINT16_C(52529), UINT16_C(42347), UINT16_C(60537), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(40765), UINT16_C(35889), UINT16_C(34127), UINT16_C(32871), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(42025), UINT16_C( 7467), UINT16_C(38458), UINT16_C(    0), UINT16_C( 9850), UINT16_C(54806), UINT16_C(21582), UINT16_C(32629) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(55585), UINT16_C(    0), UINT16_C(    0), UINT16_C(46249), UINT16_C(    0), UINT16_C(    0), UINT16_C(59499), UINT16_C(    0) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(57589), UINT16_C(15068), UINT16_C(63287), UINT16_C(    0), UINT16_C(37584), UINT16_C(23742), UINT16_C(26560), UINT16_C(37648) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(18507), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(10408), UINT16_C(19561), UINT16_C(    0) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(53896), UINT16_C(21130), UINT16_C( 5820), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(40560), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(18507), UINT16_C(    0), UINT16_C(    0), UINT16_C(30421), UINT16_C(    0), UINT16_C(    0), UINT16_C(62069), UINT16_C(    0) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t r = simde_vceqzq_u16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(         0), UINT32_C(         0), UINT32_C(1525584464), UINT32_C(3368923743) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(         0), UINT32_C(2610273753), UINT32_C(1719119292), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2023245336), UINT32_C(         0), UINT32_C( 862246070), UINT32_C(3238986728) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1455608914), UINT32_C(2095263119), UINT32_C(         0), UINT32_C(2051297665) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(         0), UINT32_C( 788705166), UINT32_C(2794151764), UINT32_C(3271314995) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2650470171), UINT32_C(         0), UINT32_C(         0), UINT32_C(1482492874) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(         0), UINT32_C(3702763873), UINT32_C(         0), UINT32_C( 843646441) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(         0), UINT32_C(1673625513), UINT32_C(         0), UINT32_C(3180275292) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t r = simde_vceqzq_u32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzq_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(11054128522423255960), UINT64_C(                   0) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(18174782665337011255), UINT64_C(17375868560037170376) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(                   0), UINT64_C(                   0) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 9091372480335400579), UINT64_C(                   0) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C( 4304431729282197337), UINT64_C(12656370081252662593) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(                   0), UINT64_C(12455881121136436021) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(16621911418554417429), UINT64_C(                   0) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C(                   0), UINT64_C(                   0) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t r = simde_vceqzq_u64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vceqzd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    uint64_t r;
  } test_vec[] = {
    {  INT64_C( 8645306100540383685),
      UINT64_C(                   0) },
    {  INT64_C(                   0),
                         UINT64_MAX },
    { -INT64_C( 2856822253570240356),
      UINT64_C(                   0) },
    {  INT64_C(                   0),
                         UINT64_MAX },
    { -INT64_C( 2783317518353768030),
      UINT64_C(                   0) },
    {  INT64_C(                   0),
                         UINT64_MAX },
    {  INT64_C( 7733225531581326773),
      UINT64_C(                   0) },
    {  INT64_C(                   0),
                         UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vceqzd_s64(test_vec[i].a);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = (i & 1) ? INT64_C(0) : simde_test_codegen_random_i64();
    uint64_t r = simde_vceqzd_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqzd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C( 8403540811691887376),
      UINT64_C(                   0) },
    { UINT64_C(                   0),
                         UINT64_MAX },
    { UINT64_C( 5427879516395086383),
      UINT64_C(                   0) },
    { UINT64_C(                   0),
                         UINT64_MAX },
    { UINT64_C( 1937779726768716180),
      UINT64_C(                   0) },
    { UINT64_C(                   0),
                         UINT64_MAX },
    { UINT64_C(14291738792189740613),
      UINT64_C(                   0) },
    { UINT64_C(                   0),
                         UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vceqzd_u64(test_vec[i].a);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = (i & 1) ? UINT64_C(0) : simde_test_codegen_random_u64();
    uint64_t r = simde_vceqzd_u64(a);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqzd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    uint64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(   696.29),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(     0.00),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(  -651.65),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(     0.00),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(   -50.42),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(     0.00),
                         UINT64_MAX },
    { SIMDE_FLOAT64_C(  -102.47),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(     0.00),
                         UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vceqzd_f64(test_vec[i].a);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = (i & 1) ? SIMDE_FLOAT64_C(0.0) : simde_test_codegen_random_f64(-1000, 1000);
    uint64_t r = simde_vceqzd_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqzh_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint16_t r;
  } test_vec[] = {
    { SIMDE_FLOAT16_VALUE(   484.25),
      UINT16_C(    0) },
    { SIMDE_FLOAT16_VALUE(     0.00),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(   792.50),
      UINT16_C(    0) },
    { SIMDE_FLOAT16_VALUE(     0.00),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(   -25.38),
      UINT16_C(    0) },
    { SIMDE_FLOAT16_VALUE(     0.00),
           UINT16_MAX },
    { SIMDE_FLOAT16_VALUE(   -64.69),
      UINT16_C(    0) },
    { SIMDE_FLOAT16_VALUE(     0.00),
           UINT16_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_vceqzh_f16(test_vec[i].a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = (i & 1) ? SIMDE_FLOAT16_VALUE(0.0) : simde_test_codegen_random_f16(-1000, 1000);
    uint16_t r = simde_vceqzh_f16(a);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vceqzs_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    uint32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(    30.96),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(     0.00),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(    83.44),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(     0.00),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -314.27),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(     0.00),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(  -517.55),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(     0.00),
                UINT32_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vceqzs_f32(test_vec[i].a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = (i & 1) ? SIMDE_FLOAT32_C(0.0) : simde_test_codegen_random_f32(-1000, 1000);
    uint32_t r = simde_vceqzs_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqz_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzq_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzd_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzh_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vceqzs_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
