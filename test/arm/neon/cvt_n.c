#define SIMDE_TEST_ARM_NEON_INSN cvt_n

#include "test-neon.h"
#include "../../../simde/arm/neon/cvt_n.h"
#include "../../../simde/arm/neon/dup_n.h"

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvth_n_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[1];
    int16_t r3[1];
    int16_t r6[1];
    int16_t r10[1];
    int16_t r13[1];
    int16_t r16[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  24.220) },
      {  INT16_C(     193) },
      {  INT16_C(    1550) },
      {  INT16_C(   24800) },
      {         INT16_MAX },
      {         INT16_MAX } },
    { { SIMDE_FLOAT16_VALUE( -   8.057) },
      { -INT16_C(      64) },
      { -INT16_C(     515) },
      { -INT16_C(    8248) },
      {         INT16_MIN },
      {         INT16_MIN } },
    { { SIMDE_FLOAT16_VALUE( -   1.310) },
      { -INT16_C(      10) },
      { -INT16_C(      83) },
      { -INT16_C(    1341) },
      { -INT16_C(   10728) },
      {         INT16_MIN } },
    { { SIMDE_FLOAT16_VALUE( -  24.017) },
      { -INT16_C(     192) },
      { -INT16_C(    1537) },
      { -INT16_C(   24592) },
      {         INT16_MIN },
      {         INT16_MIN } },
    { {  SIMDE_FLOAT16_VALUE(  23.037) },
      {  INT16_C(     184) },
      {  INT16_C(    1474) },
      {  INT16_C(   23584) },
      {         INT16_MAX },
      {         INT16_MAX } },
    { {  SIMDE_FLOAT16_VALUE(   7.442) },
      {  INT16_C(      59) },
      {  INT16_C(     476) },
      {  INT16_C(    7620) },
      {         INT16_MAX },
      {         INT16_MAX } },
    { { SIMDE_FLOAT16_VALUE( -  18.102) },
      { -INT16_C(     144) },
      { -INT16_C(    1159) },
      { -INT16_C(   18544) },
      {         INT16_MIN },
      {         INT16_MIN } },
    { { SIMDE_FLOAT16_VALUE( -  10.834) },
      { -INT16_C(      86) },
      { -INT16_C(     693) },
      { -INT16_C(   11096) },
      {         INT16_MIN },
      {         INT16_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a[0];
    int16_t r3 = simde_vcvth_n_s16_f16(a, 3);
    int16_t r6 = simde_vcvth_n_s16_f16(a, 6);
    int16_t r10 = simde_vcvth_n_s16_f16(a, 10);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    int16_t r13 = simde_vcvth_n_s16_f16(a, 13);
    int16_t r16 = simde_vcvth_n_s16_f16(a, 16);
    #endif

    simde_assert_equal_i16(r3, test_vec[i].r3[0]);
    simde_assert_equal_i16(r6, test_vec[i].r6[0]);
    simde_assert_equal_i16(r10, test_vec[i].r10[0]);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    simde_assert_equal_i16(r13, test_vec[i].r13[0]);
    simde_assert_equal_i16(r16, test_vec[i].r16[0]);
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    int16_t r3 = simde_vcvth_n_s16_f16(a, 3);
    int16_t r6 = simde_vcvth_n_s16_f16(a, 6);
    int16_t r10 = simde_vcvth_n_s16_f16(a, 10);
    int16_t r13 = simde_vcvth_n_s16_f16(a, 13);
    int16_t r16 = simde_vcvth_n_s16_f16(a, 16);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_n_s32_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    int32_t r3;
    int32_t r6;
    int32_t r10;
    int32_t r13;
    int32_t r16;
  } test_vec[] = {
    { SIMDE_FLOAT16_VALUE(   446.75),
       INT32_C(        3574),
       INT32_C(       28592),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX },
    { SIMDE_FLOAT16_VALUE(   -87.31),
      -INT32_C(         698),
      -INT32_C(        5588),
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN },
    { SIMDE_FLOAT16_VALUE(   826.00),
       INT32_C(        6608),
       INT32_C(       52864),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX },
    { SIMDE_FLOAT16_VALUE(  -327.00),
      -INT32_C(        2616),
      -INT32_C(       20928),
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN },
    { SIMDE_FLOAT16_VALUE(   852.00),
       INT32_C(        6816),
       INT32_C(       54528),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX },
    { SIMDE_FLOAT16_VALUE(  -492.00),
      -INT32_C(        3936),
      -INT32_C(       31488),
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN },
    { SIMDE_FLOAT16_VALUE(   332.25),
       INT32_C(        2658),
       INT32_C(       21264),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX },
    { SIMDE_FLOAT16_VALUE(   648.50),
       INT32_C(        5188),
       INT32_C(       41504),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int32_t r3 = simde_vcvth_n_s32_f16(a, 3);
    int32_t r6 = simde_vcvth_n_s32_f16(a, 6);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    int32_t r10 = simde_vcvth_n_s32_f16(a, 10);
    int32_t r13 = simde_vcvth_n_s32_f16(a, 13);
    int32_t r16 = simde_vcvth_n_s32_f16(a, 16);
    #endif

    simde_assert_equal_i32(r3, test_vec[i].r3);
    simde_assert_equal_i32(r6, test_vec[i].r6);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    simde_assert_equal_i32(r10, test_vec[i].r10);
    simde_assert_equal_i32(r13, test_vec[i].r13);
    simde_assert_equal_i32(r16, test_vec[i].r16);
    #endif
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
    int32_t r3 = simde_vcvth_n_s32_f16(a, 3);
    int32_t r6 = simde_vcvth_n_s32_f16(a, 6);
    int32_t r10 = simde_vcvth_n_s32_f16(a, 10);
    int32_t r13 = simde_vcvth_n_s32_f16(a, 13);
    int32_t r16 = simde_vcvth_n_s32_f16(a, 16);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_n_s64_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    int64_t r3;
    int64_t r6;
    int64_t r10;
    int64_t r13;
    int64_t r16;
  } test_vec[] = {
    { SIMDE_FLOAT16_VALUE(    27.27),
       INT64_C(                 218),
       INT64_C(                1745),
       INT64_C(               27920),
                           INT64_MAX,
                           INT64_MAX },
    { SIMDE_FLOAT16_VALUE(   195.12),
       INT64_C(                1561),
       INT64_C(               12488),
                           INT64_MAX,
                           INT64_MAX,
                           INT64_MAX },
    { SIMDE_FLOAT16_VALUE(   323.50),
       INT64_C(                2588),
       INT64_C(               20704),
                           INT64_MAX,
                           INT64_MAX,
                           INT64_MAX },
    { SIMDE_FLOAT16_VALUE(  -532.00),
      -INT64_C(                4256),
      -INT64_C(               34048),
                           INT64_MIN,
                           INT64_MIN,
                           INT64_MIN },
    { SIMDE_FLOAT16_VALUE(   264.50),
       INT64_C(                2116),
       INT64_C(               16928),
                           INT64_MAX,
                           INT64_MAX,
                           INT64_MAX },
    { SIMDE_FLOAT16_VALUE(   741.50),
       INT64_C(                5932),
       INT64_C(               47456),
                           INT64_MAX,
                           INT64_MAX,
                           INT64_MAX },
    { SIMDE_FLOAT16_VALUE(  -545.50),
      -INT64_C(                4364),
      -INT64_C(               34912),
                           INT64_MIN,
                           INT64_MIN,
                           INT64_MIN },
    { SIMDE_FLOAT16_VALUE(  -404.25),
      -INT64_C(                3234),
      -INT64_C(               25872),
                           INT64_MIN,
                           INT64_MIN,
                           INT64_MIN },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int64_t r3 = simde_vcvth_n_s64_f16(a, 3);
    int64_t r6 = simde_vcvth_n_s64_f16(a, 6);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    int64_t r10 = simde_vcvth_n_s64_f16(a, 10);
    int64_t r13 = simde_vcvth_n_s64_f16(a, 13);
    int64_t r16 = simde_vcvth_n_s64_f16(a, 16);
    #endif

    simde_assert_equal_i64(r3, test_vec[i].r3);
    simde_assert_equal_i64(r6, test_vec[i].r6);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    simde_assert_equal_i64(r10, test_vec[i].r10);
    simde_assert_equal_i64(r13, test_vec[i].r13);
    simde_assert_equal_i64(r16, test_vec[i].r16);
    #endif
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
    int64_t r3 = simde_vcvth_n_s64_f16(a, 3);
    int64_t r6 = simde_vcvth_n_s64_f16(a, 6);
    int64_t r10 = simde_vcvth_n_s64_f16(a, 10);
    int64_t r13 = simde_vcvth_n_s64_f16(a, 13);
    int64_t r16 = simde_vcvth_n_s64_f16(a, 16);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvth_n_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[1];
    uint16_t r3[1];
    uint16_t r6[1];
    uint16_t r10[1];
    uint16_t r13[1];
    uint16_t r16[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(      1.01) },
      {  UINT16_C(         8) },
      {  UINT16_C(        64) },
      {  UINT16_C(      1034) },
      {  UINT16_C(      8272) },
      {          UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a[0];
    uint16_t r3 = simde_vcvth_n_u16_f16(a, 3);
    uint16_t r6 = simde_vcvth_n_u16_f16(a, 6);
    uint16_t r10 = simde_vcvth_n_u16_f16(a, 10);
    uint16_t r13 = simde_vcvth_n_u16_f16(a, 13);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    uint16_t r16 = simde_vcvth_n_u16_f16(a, 16);
    #endif

    simde_assert_equal_u16(r3, test_vec[i].r3[0]);
    simde_assert_equal_u16(r6, test_vec[i].r6[0]);
    simde_assert_equal_u16(r10, test_vec[i].r10[0]);
    simde_assert_equal_u16(r13, test_vec[i].r13[0]);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    simde_assert_equal_u16(r16, test_vec[i].r16[0]);
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    uint16_t r3 = simde_vcvth_n_u16_f16(a, 3);
    uint16_t r6 = simde_vcvth_n_u16_f16(a, 6);
    uint16_t r10 = simde_vcvth_n_u16_f16(a, 10);
    uint16_t r13 = simde_vcvth_n_u16_f16(a, 13);
    uint16_t r16 = simde_vcvth_n_u16_f16(a, 16);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvth_n_u32_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint32_t r3;
    uint32_t r6;
    uint32_t r10;
    uint32_t r13;
    uint32_t r16;
  } test_vec[] = {
    { SIMDE_FLOAT16_VALUE(   146.50),
      UINT32_C(      1172),
      UINT32_C(      9376),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    { SIMDE_FLOAT16_VALUE(   305.75),
      UINT32_C(      2446),
      UINT32_C(     19568),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    { SIMDE_FLOAT16_VALUE(   475.75),
      UINT32_C(      3806),
      UINT32_C(     30448),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    { SIMDE_FLOAT16_VALUE(   776.50),
      UINT32_C(      6212),
      UINT32_C(     49696),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    { SIMDE_FLOAT16_VALUE(   714.00),
      UINT32_C(      5712),
      UINT32_C(     45696),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    { SIMDE_FLOAT16_VALUE(   907.00),
      UINT32_C(      7256),
      UINT32_C(     58048),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint32_t r3 = simde_vcvth_n_u32_f16(a, 3);
    uint32_t r6 = simde_vcvth_n_u32_f16(a, 6);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    uint32_t r10 = simde_vcvth_n_u32_f16(a, 10);
    uint32_t r13 = simde_vcvth_n_u32_f16(a, 13);
    uint32_t r16 = simde_vcvth_n_u32_f16(a, 16);
    #endif

    simde_assert_equal_u32(r3, test_vec[i].r3);
    simde_assert_equal_u32(r6, test_vec[i].r6);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    simde_assert_equal_u32(r10, test_vec[i].r10);
    simde_assert_equal_u32(r13, test_vec[i].r13);
    simde_assert_equal_u32(r16, test_vec[i].r16);
    #endif
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
    uint32_t r3 = simde_vcvth_n_u32_f16(a, 3);
    uint32_t r6 = simde_vcvth_n_u32_f16(a, 6);
    uint32_t r10 = simde_vcvth_n_u32_f16(a, 10);
    uint32_t r13 = simde_vcvth_n_u32_f16(a, 13);
    uint32_t r16 = simde_vcvth_n_u32_f16(a, 16);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_n_u64_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint64_t r3;
    uint64_t r6;
    uint64_t r10;
    uint64_t r13;
    uint64_t r16;
  } test_vec[] = {
    { SIMDE_FLOAT16_VALUE(   215.88),
      UINT64_C(                1727),
      UINT64_C(               13816),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    { SIMDE_FLOAT16_VALUE(   420.75),
      UINT64_C(                3366),
      UINT64_C(               26928),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    { SIMDE_FLOAT16_VALUE(   603.50),
      UINT64_C(                4828),
      UINT64_C(               38624),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint64_t r3 = simde_vcvth_n_u64_f16(a, 3);
    uint64_t r6 = simde_vcvth_n_u64_f16(a, 6);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    uint64_t r10 = simde_vcvth_n_u64_f16(a, 10);
    uint64_t r13 = simde_vcvth_n_u64_f16(a, 13);
    uint64_t r16 = simde_vcvth_n_u64_f16(a, 16);
    #endif

    simde_assert_equal_u64(r3, test_vec[i].r3);
    simde_assert_equal_u64(r6, test_vec[i].r6);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    simde_assert_equal_u64(r10, test_vec[i].r10);
    simde_assert_equal_u64(r13, test_vec[i].r13);
    simde_assert_equal_u64(r16, test_vec[i].r16);
    #endif
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
    uint64_t r3 = simde_vcvth_n_u64_f16(a, 3);
    uint64_t r6 = simde_vcvth_n_u64_f16(a, 6);
    uint64_t r10 = simde_vcvth_n_u64_f16(a, 10);
    uint64_t r13 = simde_vcvth_n_u64_f16(a, 13);
    uint64_t r16 = simde_vcvth_n_u64_f16(a, 16);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvth_n_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[1];
    simde_float16_t r3[1];
    simde_float16_t r6[1];
    simde_float16_t r10[1];
    simde_float16_t r13[1];
    simde_float16_t r16[1];
  } test_vec[] = {
    { {  INT16_C(      2586) },
      {  SIMDE_FLOAT16_VALUE(   323.250) },
      {  SIMDE_FLOAT16_VALUE(    40.406) },
      {  SIMDE_FLOAT16_VALUE(     2.525) },
      {  SIMDE_FLOAT16_VALUE(     0.316) },
      {  SIMDE_FLOAT16_VALUE(     0.039) } },
    { { -INT16_C(     12099) },
      { SIMDE_FLOAT16_VALUE( -  1512.375) },
      { SIMDE_FLOAT16_VALUE( -   189.047) },
      { SIMDE_FLOAT16_VALUE( -    11.815) },
      { SIMDE_FLOAT16_VALUE( -     1.477) },
      { SIMDE_FLOAT16_VALUE( -     0.185) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a[0];
    simde_float16_t r3 = simde_vcvth_n_f16_s16(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_s16(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_s16(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_s16(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_s16(a, 16);

    simde_assert_equal_f16(r3, test_vec[i].r3[0], 1);
    simde_assert_equal_f16(r6, test_vec[i].r6[0], 1);
    simde_assert_equal_f16(r10, test_vec[i].r10[0], 1);
    simde_assert_equal_f16(r13, test_vec[i].r13[0], 1);
    simde_assert_equal_f16(r16, test_vec[i].r16[0], 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = simde_test_arm_neon_random_i16();
    simde_float16_t r3 = simde_vcvth_n_f16_s16(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_s16(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_s16(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_s16(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_s16(a, 16);

    simde_test_arm_neon_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvth_n_f16_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a;
    simde_float16_t r3;
    simde_float16_t r6;
    simde_float16_t r10;
    simde_float16_t r13;
    simde_float16_t r16;
  } test_vec[] = {
    {  INT32_C(  1875020380),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 28608.00) },
    {  INT32_C(   700277977),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 10688.00) },
    {  INT32_C(   909565182),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 13880.00) },
    {  INT32_C(   245822870),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 30000.00),
      SIMDE_FLOAT16_VALUE(  3750.00) },
    { -INT32_C(  1253541882),
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
      SIMDE_FLOAT16_VALUE(-19120.00) },
    {  INT32_C(  1238403304),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 18896.00) },
    { -INT32_C(   147081743),
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
      SIMDE_FLOAT16_VALUE(-17952.00),
      SIMDE_FLOAT16_VALUE( -2244.00) },
    { -INT32_C(  1533160889),
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
      SIMDE_FLOAT16_VALUE(-23392.00) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    simde_float16_t r3 = simde_vcvth_n_f16_s32(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_s32(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_s32(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_s32(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_s32(a, 16);

    simde_assert_equal_f16(r3, test_vec[i].r3, 1);
    simde_assert_equal_f16(r6, test_vec[i].r6, 1);
    simde_assert_equal_f16(r10, test_vec[i].r10, 1);
    simde_assert_equal_f16(r13, test_vec[i].r13, 1);
    simde_assert_equal_f16(r16, test_vec[i].r16, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_float16_t r3 = simde_vcvth_n_f16_s32(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_s32(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_s32(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_s32(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_s32(a, 16);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_n_f16_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a;
    simde_float16_t r3;
    simde_float16_t r6;
    simde_float16_t r10;
    simde_float16_t r13;
    simde_float16_t r16;
  } test_vec[] = {
    { -INT64_C( 4440601166441389988),
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF },
    { -INT64_C( 7975419144118430292),
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF },
    {  INT64_C( 1389104449129453846),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    { -INT64_C( 5568797330875120692),
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF,
          SIMDE_NINFINITYHF },
    {  INT64_C( 5156136258357414408),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    {  INT64_C( 4249388297338128092),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    {  INT64_C( 2498231527699660661),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    {  INT64_C( 7425007925136307715),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t a = test_vec[i].a;
    simde_float16_t r3 = simde_vcvth_n_f16_s64(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_s64(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_s64(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_s64(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_s64(a, 16);

    simde_assert_equal_f16(r3, test_vec[i].r3, 1);
    simde_assert_equal_f16(r6, test_vec[i].r6, 1);
    simde_assert_equal_f16(r10, test_vec[i].r10, 1);
    simde_assert_equal_f16(r13, test_vec[i].r13, 1);
    simde_assert_equal_f16(r16, test_vec[i].r16, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    simde_float16_t r3 = simde_vcvth_n_f16_s64(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_s64(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_s64(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_s64(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_s64(a, 16);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvth_n_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[1];
    simde_float16_t r3[1];
    simde_float16_t r6[1];
    simde_float16_t r10[1];
    simde_float16_t r13[1];
    simde_float16_t r16[1];
  } test_vec[] = {
    { {  UINT16_C(       195) },
      {  SIMDE_FLOAT16_VALUE(    24.375) },
      {  SIMDE_FLOAT16_VALUE(     3.047) },
      {  SIMDE_FLOAT16_VALUE(     0.190) },
      {  SIMDE_FLOAT16_VALUE(     0.024) },
      {  SIMDE_FLOAT16_VALUE(     0.003) } },
    { {  UINT16_C(     47989) },
      {  SIMDE_FLOAT16_VALUE(  5998.625) },
      {  SIMDE_FLOAT16_VALUE(   749.828) },
      {  SIMDE_FLOAT16_VALUE(    46.864) },
      {  SIMDE_FLOAT16_VALUE(     5.858) },
      {  SIMDE_FLOAT16_VALUE(     0.732) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t a = test_vec[i].a[0];
    simde_float16_t r3 = simde_vcvth_n_f16_u16(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_u16(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_u16(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_u16(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_u16(a, 16);

    simde_assert_equal_f16(r3, test_vec[i].r3[0], 1);
    simde_assert_equal_f16(r6, test_vec[i].r6[0], 1);
    simde_assert_equal_f16(r10, test_vec[i].r10[0], 1);
    simde_assert_equal_f16(r13, test_vec[i].r13[0], 1);
    simde_assert_equal_f16(r16, test_vec[i].r16[0], 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x1_t a = simde_test_arm_neon_random_u16x1();
    simde_float16_t r3 = simde_vcvth_n_f16_u16(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_u16(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_u16(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_u16(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_u16(a, 16);

    simde_test_arm_neon_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvth_n_f16_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a;
    simde_float16_t r3;
    simde_float16_t r6;
    simde_float16_t r10;
    simde_float16_t r13;
    simde_float16_t r16;
  } test_vec[] = {
    { UINT32_C(1379136183),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 21040.00) },
    { UINT32_C( 345686584),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 42208.00),
      SIMDE_FLOAT16_VALUE(  5276.00) },
    { UINT32_C(1836786760),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 28032.00) },
    { UINT32_C(1990685696),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 30368.00) },
    { UINT32_C( 151904435),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 18544.00),
      SIMDE_FLOAT16_VALUE(  2318.00) },
    { UINT32_C(1663809632),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 25392.00) },
    { UINT32_C(3451609198),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 52672.00) },
    { UINT32_C(  87344717),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
      SIMDE_FLOAT16_VALUE( 10664.00),
      SIMDE_FLOAT16_VALUE(  1333.00) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    simde_float16_t r3 = simde_vcvth_n_f16_u32(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_u32(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_u32(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_u32(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_u32(a, 16);

    simde_assert_equal_f16(r3, test_vec[i].r3, 1);
    simde_assert_equal_f16(r6, test_vec[i].r6, 1);
    simde_assert_equal_f16(r10, test_vec[i].r10, 1);
    simde_assert_equal_f16(r13, test_vec[i].r13, 1);
    simde_assert_equal_f16(r16, test_vec[i].r16, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    simde_float16_t r3 = simde_vcvth_n_f16_u32(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_u32(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_u32(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_u32(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_u32(a, 16);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_n_f16_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a;
    simde_float16_t r3;
    simde_float16_t r6;
    simde_float16_t r10;
    simde_float16_t r13;
    simde_float16_t r16;
  } test_vec[] = {
    { UINT64_C( 8216238257635551160),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    { UINT64_C(12073173083987345430),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    { UINT64_C(13918897271932492390),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    { UINT64_C( 7173885298450818364),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    { UINT64_C(17133198039240140329),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    { UINT64_C(10481442221277357273),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    { UINT64_C( 4413106528267478314),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
    { UINT64_C(13219284874911206502),
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF,
           SIMDE_INFINITYHF },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t a = test_vec[i].a;
    simde_float16_t r3 = simde_vcvth_n_f16_u64(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_u64(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_u64(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_u64(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_u64(a, 16);

    simde_assert_equal_f16(r3, test_vec[i].r3, 1);
    simde_assert_equal_f16(r6, test_vec[i].r6, 1);
    simde_assert_equal_f16(r10, test_vec[i].r10, 1);
    simde_assert_equal_f16(r13, test_vec[i].r13, 1);
    simde_assert_equal_f16(r16, test_vec[i].r16, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    simde_float16_t r3 = simde_vcvth_n_f16_u64(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_u64(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_u64(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_u64(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_u64(a, 16);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvts_n_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[1];
    int32_t r3[1];
    int32_t r10[1];
    int32_t r16[1];
    int32_t r23[1];
    int32_t r32[1];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(-733.4) },
      { -INT32_C(5867) },
      { -INT32_C(751001) },
      { -INT32_C(48064104) },
      { INT32_MIN },
      { INT32_MIN } },
    { {  SIMDE_FLOAT32_C( 883.313) },
      {  INT32_C(    7066) },
      {  INT32_C(  904512) },
      {  INT32_C(57888800) },
      {         INT32_MAX },
      {         INT32_MAX } },
    { {  SIMDE_FLOAT32_C( 750.328) },
      {  INT32_C(    6002) },
      {  INT32_C(  768335) },
      {  INT32_C(49173496) },
      {         INT32_MAX },
      {         INT32_MAX } },
    { { -SIMDE_FLOAT32_C( 171.275) },
      { -INT32_C(    1370) },
      { -INT32_C(  175385) },
      { -INT32_C(11224678) },
      { -INT32_C(1436758784) },
      {         INT32_MIN } },
    { { -SIMDE_FLOAT32_C( 425.134) },
      { -INT32_C(    3401) },
      { -INT32_C(  435337) },
      { -INT32_C(27861582) },
      {         INT32_MIN },
      {         INT32_MIN } },
    { {  SIMDE_FLOAT32_C( 532.107) },
      {  INT32_C(    4256) },
      {  INT32_C(  544877) },
      {  INT32_C(34872164) },
      {         INT32_MAX },
      {         INT32_MAX } },
    { { -SIMDE_FLOAT32_C( 413.820) },
      { -INT32_C(    3310) },
      { -INT32_C(  423751) },
      { -INT32_C(27120108) },
      {         INT32_MIN },
      {         INT32_MIN } },
    { {  SIMDE_FLOAT32_C( 221.030) },
      {  INT32_C(    1768) },
      {  INT32_C(  226334) },
      {  INT32_C(14485422) },
      {  INT32_C(1854134016) },
      {         INT32_MAX } },
    { { -SIMDE_FLOAT32_C( 711.342) },
      { -INT32_C(    5690) },
      { -INT32_C(  728414) },
      { -INT32_C(46618508) },
      {         INT32_MIN },
      {         INT32_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32_t a = test_vec[i].a[0];
    int32_t r3 = simde_vcvts_n_s32_f32(a, 3);
    int32_t r10 = simde_vcvts_n_s32_f32(a, 10);
    int32_t r16 = simde_vcvts_n_s32_f32(a, 16);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    int32_t r23 = simde_vcvts_n_s32_f32(a, 23);
    int32_t r32 = simde_vcvts_n_s32_f32(a, 32);
    #endif

    simde_assert_equal_i32(r3, test_vec[i].r3[0]);
    simde_assert_equal_i32(r10, test_vec[i].r10[0]);
    simde_assert_equal_i32(r16, test_vec[i].r16[0]);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    simde_assert_equal_i32(r23, test_vec[i].r23[0]);
    simde_assert_equal_i32(r32, test_vec[i].r32[0]);
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_arm_neon_random_f32(-1000.0f, 1000.0f);
    int32_t r3 = simde_vcvts_n_s32_f32(a, 3);
    int32_t r10 = simde_vcvts_n_s32_f32(a, 10);
    int32_t r16 = simde_vcvts_n_s32_f32(a, 16);
    int32_t r23 = simde_vcvts_n_s32_f32(a, 23);
    int32_t r32 = simde_vcvts_n_s32_f32(a, 32);

    simde_test_arm_neon_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvts_n_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[1];
    uint32_t r3[1];
    uint32_t r10[1];
    uint32_t r16[1];
    uint32_t r23[1];
    uint32_t r32[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C( 312.384) },
      {  UINT32_C(    2499) },
      {  UINT32_C(  319881) },
      {  UINT32_C(20472398) },
      {  UINT32_C(2620466944) },
      {        UINT32_MAX } },
    { {  SIMDE_FLOAT32_C( 403.436) },
      {  UINT32_C(    3227) },
      {  UINT32_C(  413118) },
      {  UINT32_C(26439582) },
      {  UINT32_C(3384266496) },
      {        UINT32_MAX } },
    { {  SIMDE_FLOAT32_C( 982.191) },
      {  UINT32_C(    7857) },
      {  UINT32_C( 1005763) },
      {  UINT32_C(64368868) },
      {        UINT32_MAX },
      {        UINT32_MAX } },
    { {  SIMDE_FLOAT32_C( 584.450) },
      {  UINT32_C(    4675) },
      {  UINT32_C(  598476) },
      {  UINT32_C(38302516) },
      {        UINT32_MAX },
      {        UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32_t a = test_vec[i].a[0];
    uint32_t r3 = simde_vcvts_n_u32_f32(a, 3);
    uint32_t r10 = simde_vcvts_n_u32_f32(a, 10);
    uint32_t r16 = simde_vcvts_n_u32_f32(a, 16);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    uint32_t r23 = simde_vcvts_n_u32_f32(a, 23);
    uint32_t r32 = simde_vcvts_n_u32_f32(a, 32);
    #endif

    simde_assert_equal_u32(r3, test_vec[i].r3[0]);
    simde_assert_equal_u32(r10, test_vec[i].r10[0]);
    simde_assert_equal_u32(r16, test_vec[i].r16[0]);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    simde_assert_equal_u32(r23, test_vec[i].r23[0]);
    simde_assert_equal_u32(r32, test_vec[i].r32[0]);
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x1_t a = simde_test_arm_neon_random_f32x1(-1000.0f, 1000.0f);
    uint32_t r3 = simde_vcvts_n_u32_f32(a, 3);
    uint32_t r10 = simde_vcvts_n_u32_f32(a, 10);
    uint32_t r16 = simde_vcvts_n_u32_f32(a, 16);
    uint32_t r23 = simde_vcvts_n_u32_f32(a, 23);
    uint32_t r32 = simde_vcvts_n_u32_f32(a, 32);

    simde_test_arm_neon_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvts_n_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a;
    simde_float32_t r3;
    simde_float32_t r10;
    simde_float32_t r16;
    simde_float32_t r23;
    simde_float32_t r32;
  } test_vec[] = {
    {  INT32_C(   382290179),
      SIMDE_FLOAT32_C(47786272.00),
      SIMDE_FLOAT32_C(373330.25),
      SIMDE_FLOAT32_C(  5833.29),
      SIMDE_FLOAT32_C(    45.57),
      SIMDE_FLOAT32_C(     0.09) },
    { -INT32_C(  1375582254),
      SIMDE_FLOAT32_C(-171947776.00),
      SIMDE_FLOAT32_C(-1343342.00),
      SIMDE_FLOAT32_C(-20989.72),
      SIMDE_FLOAT32_C(  -163.98),
      SIMDE_FLOAT32_C(    -0.32) },
    { -INT32_C(   176355251),
      SIMDE_FLOAT32_C(-22044406.00),
      SIMDE_FLOAT32_C(-172221.92),
      SIMDE_FLOAT32_C( -2690.97),
      SIMDE_FLOAT32_C(   -21.02),
      SIMDE_FLOAT32_C(    -0.04) },
    { -INT32_C(  1699124069),
      SIMDE_FLOAT32_C(-212390512.00),
      SIMDE_FLOAT32_C(-1659300.88),
      SIMDE_FLOAT32_C(-25926.58),
      SIMDE_FLOAT32_C(  -202.55),
      SIMDE_FLOAT32_C(    -0.40) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    simde_float32_t r3 = simde_vcvts_n_f32_s32(a, 3);
    simde_float32_t r10 = simde_vcvts_n_f32_s32(a, 10);
    simde_float32_t r16 = simde_vcvts_n_f32_s32(a, 16);
    simde_float32_t r23 = simde_vcvts_n_f32_s32(a, 23);
    simde_float32_t r32 = simde_vcvts_n_f32_s32(a, 32);

    simde_assert_equal_f32(r3, test_vec[i].r3, 1);
    simde_assert_equal_f32(r10, test_vec[i].r10, 1);
    simde_assert_equal_f32(r16, test_vec[i].r16, 1);
    simde_assert_equal_f32(r23, test_vec[i].r23, 1);
    simde_assert_equal_f32(r32, test_vec[i].r32, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_float32_t r3 = simde_vcvts_n_f32_s32(a, 3);
    simde_float32_t r10 = simde_vcvts_n_f32_s32(a, 10);
    simde_float32_t r16 = simde_vcvts_n_f32_s32(a, 16);
    simde_float32_t r23 = simde_vcvts_n_f32_s32(a, 23);
    simde_float32_t r32 = simde_vcvts_n_f32_s32(a, 32);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvts_n_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a;
    simde_float32_t r3;
    simde_float32_t r10;
    simde_float32_t r16;
    simde_float32_t r23;
    simde_float32_t r32;
  } test_vec[] = {
    { UINT32_C(1716442256),
      SIMDE_FLOAT32_C(214555280.00),
      SIMDE_FLOAT32_C(1676213.12),
      SIMDE_FLOAT32_C( 26190.83),
      SIMDE_FLOAT32_C(   204.62),
      SIMDE_FLOAT32_C(     0.40) },
    { UINT32_C(1980926086),
      SIMDE_FLOAT32_C(247615760.00),
      SIMDE_FLOAT32_C(1934498.12),
      SIMDE_FLOAT32_C( 30226.53),
      SIMDE_FLOAT32_C(   236.14),
      SIMDE_FLOAT32_C(     0.46) },
    { UINT32_C( 767096392),
      SIMDE_FLOAT32_C(95887048.00),
      SIMDE_FLOAT32_C(749117.56),
      SIMDE_FLOAT32_C( 11704.96),
      SIMDE_FLOAT32_C(    91.45),
      SIMDE_FLOAT32_C(     0.18) },
    { UINT32_C(2969434285),
      SIMDE_FLOAT32_C(371179296.00),
      SIMDE_FLOAT32_C(2899838.25),
      SIMDE_FLOAT32_C( 45309.97),
      SIMDE_FLOAT32_C(   353.98),
      SIMDE_FLOAT32_C(     0.69) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    simde_float32_t r3 = simde_vcvts_n_f32_u32(a, 3);
    simde_float32_t r10 = simde_vcvts_n_f32_u32(a, 10);
    simde_float32_t r16 = simde_vcvts_n_f32_u32(a, 16);
    simde_float32_t r23 = simde_vcvts_n_f32_u32(a, 23);
    simde_float32_t r32 = simde_vcvts_n_f32_u32(a, 32);

    simde_assert_equal_f32(r3, test_vec[i].r3, 1);
    simde_assert_equal_f32(r10, test_vec[i].r10, 1);
    simde_assert_equal_f32(r16, test_vec[i].r16, 1);
    simde_assert_equal_f32(r23, test_vec[i].r23, 1);
    simde_assert_equal_f32(r32, test_vec[i].r32, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    simde_float32_t r3 = simde_vcvts_n_f32_u32(a, 3);
    simde_float32_t r10 = simde_vcvts_n_f32_u32(a, 10);
    simde_float32_t r16 = simde_vcvts_n_f32_u32(a, 16);
    simde_float32_t r23 = simde_vcvts_n_f32_u32(a, 23);
    simde_float32_t r32 = simde_vcvts_n_f32_u32(a, 32);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtd_n_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64_t a[1];
    int64_t r3[1];
    int64_t r17[1];
    int64_t r38[1];
    int64_t r55[1];
    int64_t r64[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C(           98809.484) },
      {  INT64_C(              790475) },
      {  INT64_C(         12951156686) },
      {  INT64_C(   27160544148136656) },
      {                     INT64_MAX },
      {                     INT64_MAX } },
    { {  SIMDE_FLOAT64_C(            8345.477) },
      {  INT64_C(               66763) },
      {  INT64_C(          1093858361) },
      {  INT64_C(    2293987250209292) },
      {                     INT64_MAX },
      {                     INT64_MAX } },
    { {  SIMDE_FLOAT64_C(           69039.125) },
      {  INT64_C(              552313) },
      {  INT64_C(          9049096192) },
      {  INT64_C(   18977330177245184) },
      {                     INT64_MAX },
      {                     INT64_MAX } },
    { { -SIMDE_FLOAT64_C(           44042.309) },
      { -INT64_C(              352338) },
      { -INT64_C(          5772713525) },
      { -INT64_C(   12106257714900894) },
      {                     INT64_MIN },
      {                     INT64_MIN } },
    { { -SIMDE_FLOAT64_C(           19111.727) },
      { -INT64_C(              152893) },
      { -INT64_C(          2505012281) },
      { -INT64_C(    5253391515845132) },
      {                     INT64_MIN },
      {                     INT64_MIN } },
    { {  SIMDE_FLOAT64_C(           39608.250) },
      {  INT64_C(              316866) },
      {  INT64_C(          5191532544) },
      {  INT64_C(   10887432857714688) },
      {                     INT64_MAX },
      {                     INT64_MAX } },
    { { -SIMDE_FLOAT64_C(           39541.906) },
      { -INT64_C(              316335) },
      { -INT64_C(          5182836703) },
      { -INT64_C(   10869196357856396) },
      {                     INT64_MIN },
      {                     INT64_MIN } },
    { {  SIMDE_FLOAT64_C(           93824.031) },
      {  INT64_C(              750592) },
      {  INT64_C(         12297703391) },
      {  INT64_C(   25790153262328972) },
      {                     INT64_MAX },
      {                     INT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t a = test_vec[i].a[0];
    int64_t r3 = simde_vcvtd_n_s64_f64(a, 3);
    int64_t r17 = simde_vcvtd_n_s64_f64(a, 17);
    int64_t r38 = simde_vcvtd_n_s64_f64(a, 38);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    int64_t r55 = simde_vcvtd_n_s64_f64(a, 55);
    int64_t r64 = simde_vcvtd_n_s64_f64(a, 64);
    #endif

    simde_assert_equal_i64(r3, test_vec[i].r3[0]);
    simde_assert_equal_i64(r17, test_vec[i].r17[0]);
    simde_assert_equal_i64(r38, test_vec[i].r38[0]);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    simde_assert_equal_i64(r55, test_vec[i].r55[0]);
    simde_assert_equal_i64(r64, test_vec[i].r64[0]);
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int64_t r3 = simde_vcvtd_n_s64_f64(a, 3);
    int64_t r17 = simde_vcvtd_n_s64_f64(a, 17);
    int64_t r38 = simde_vcvtd_n_s64_f64(a, 38);
    int64_t r55 = simde_vcvtd_n_s64_f64(a, 55);
    int64_t r64 = simde_vcvtd_n_s64_f64(a, 64);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtd_n_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64_t a[1];
    uint64_t r3[1];
    uint64_t r17[1];
    uint64_t r38[1];
    uint64_t r55[1];
    uint64_t r64[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C(           84182.672) },
      {  UINT64_C(              673461) },
      {  UINT64_C(         11033991184) },
      {  UINT64_C(   23139956680313276) },
      {                    UINT64_MAX },
      {                    UINT64_MAX } },
    { {  SIMDE_FLOAT64_C(           71694.797) },
      {  UINT64_C(              573558) },
      {  UINT64_C(          9397180432) },
      {  UINT64_C(   19707315738134972) },
      {                    UINT64_MAX },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t a = test_vec[i].a[0];
    uint64_t r3 = simde_vcvtd_n_u64_f64(a, 3);
    uint64_t r17 = simde_vcvtd_n_u64_f64(a, 17);
    uint64_t r38 = simde_vcvtd_n_u64_f64(a, 38);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    uint64_t r55 = simde_vcvtd_n_u64_f64(a, 55);
    uint64_t r64 = simde_vcvtd_n_u64_f64(a, 64);
    #endif

    simde_assert_equal_u64(r3, test_vec[i].r3[0]);
    simde_assert_equal_u64(r17, test_vec[i].r17[0]);
    simde_assert_equal_u64(r38, test_vec[i].r38[0]);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    simde_assert_equal_u64(r55, test_vec[i].r55[0]);
    simde_assert_equal_u64(r64, test_vec[i].r64[0]);
    #endif
  }
  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    uint64_t r3 = simde_vcvtd_n_u64_f64(a, 3);
    uint64_t r17 = simde_vcvtd_n_u64_f64(a, 17);
    uint64_t r38 = simde_vcvtd_n_u64_f64(a, 38);
    uint64_t r55 = simde_vcvtd_n_u64_f64(a, 55);
    uint64_t r64 = simde_vcvtd_n_u64_f64(a, 64);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtd_n_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a;
    simde_float64_t r3;
    simde_float64_t r17;
    simde_float64_t r38;
    simde_float64_t r55;
    simde_float64_t r64;
  } test_vec[] = {
    {  INT64_C( 1802271432678331317),
      SIMDE_FLOAT64_C(225283929084791424.00),
      SIMDE_FLOAT64_C(13750239812304.16),
      SIMDE_FLOAT64_C(6556625.28),
      SIMDE_FLOAT64_C(    50.02),
      SIMDE_FLOAT64_C(     0.10) },
    { -INT64_C(  900386704286887549),
      SIMDE_FLOAT64_C(-112548338035860944.00),
      SIMDE_FLOAT64_C(-6869405397696.59),
      SIMDE_FLOAT64_C(-3275587.75),
      SIMDE_FLOAT64_C(   -24.99),
      SIMDE_FLOAT64_C(    -0.05) },
    {  INT64_C( 7487442315758603864),
      SIMDE_FLOAT64_C(935930289469825536.00),
      SIMDE_FLOAT64_C(57124651456898.53),
      SIMDE_FLOAT64_C(27239156.46),
      SIMDE_FLOAT64_C(   207.82),
      SIMDE_FLOAT64_C(     0.41) },
    {  INT64_C( 8649336546515843284),
      SIMDE_FLOAT64_C(1081167068314480384.00),
      SIMDE_FLOAT64_C(65989200946928.73),
      SIMDE_FLOAT64_C(31466103.05),
      SIMDE_FLOAT64_C(   240.07),
      SIMDE_FLOAT64_C(     0.47) },
    {  INT64_C( 2331510679777683696),
      SIMDE_FLOAT64_C(291438834972210432.00),
      SIMDE_FLOAT64_C(17788014829846.83),
      SIMDE_FLOAT64_C(8481986.44),
      SIMDE_FLOAT64_C(    64.71),
      SIMDE_FLOAT64_C(     0.13) },
    {  INT64_C( 6991199644197509633),
      SIMDE_FLOAT64_C(873899955524688768.00),
      SIMDE_FLOAT64_C(53338620332317.43),
      SIMDE_FLOAT64_C(25433836.14),
      SIMDE_FLOAT64_C(   194.04),
      SIMDE_FLOAT64_C(     0.38) },
    { -INT64_C( 7255582914630055223),
      SIMDE_FLOAT64_C(-906947864328756864.00),
      SIMDE_FLOAT64_C(-55355704609909.48),
      SIMDE_FLOAT64_C(-26395656.88),
      SIMDE_FLOAT64_C(  -201.38),
      SIMDE_FLOAT64_C(    -0.39) },
    { -INT64_C( 4777772969744650379),
      SIMDE_FLOAT64_C(-597221621218081280.00),
      SIMDE_FLOAT64_C(-36451514966923.91),
      SIMDE_FLOAT64_C(-17381436.81),
      SIMDE_FLOAT64_C(  -132.61),
      SIMDE_FLOAT64_C(    -0.26) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t a = test_vec[i].a;
    simde_float64_t r3 = simde_vcvtd_n_f64_s64(a, 3);
    simde_float64_t r17 = simde_vcvtd_n_f64_s64(a, 17);
    simde_float64_t r38 = simde_vcvtd_n_f64_s64(a, 38);
    simde_float64_t r55 = simde_vcvtd_n_f64_s64(a, 55);
    simde_float64_t r64 = simde_vcvtd_n_f64_s64(a, 64);

    simde_assert_equal_f64(r3, test_vec[i].r3, 1);
    simde_assert_equal_f64(r17, test_vec[i].r17, 1);
    simde_assert_equal_f64(r38, test_vec[i].r38, 1);
    simde_assert_equal_f64(r55, test_vec[i].r55, 1);
    simde_assert_equal_f64(r64, test_vec[i].r64, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    simde_float64_t r3 = simde_vcvtd_n_f64_s64(a, 3);
    simde_float64_t r17 = simde_vcvtd_n_f64_s64(a, 17);
    simde_float64_t r38 = simde_vcvtd_n_f64_s64(a, 38);
    simde_float64_t r55 = simde_vcvtd_n_f64_s64(a, 55);
    simde_float64_t r64 = simde_vcvtd_n_f64_s64(a, 64);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtd_n_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a;
    simde_float64_t r3;
    simde_float64_t r17;
    simde_float64_t r38;
    simde_float64_t r55;
    simde_float64_t r64;
  } test_vec[] = {
    { UINT64_C( 1176945894709255833),
      SIMDE_FLOAT64_C(147118236838656992.00),
      SIMDE_FLOAT64_C(8979384572671.94),
      SIMDE_FLOAT64_C(4281704.22),
      SIMDE_FLOAT64_C(    32.67),
      SIMDE_FLOAT64_C(     0.06) },
    { UINT64_C( 1485949606174035764),
      SIMDE_FLOAT64_C(185743700771754464.00),
      SIMDE_FLOAT64_C(11336895799057.28),
      SIMDE_FLOAT64_C(5405853.18),
      SIMDE_FLOAT64_C(    41.24),
      SIMDE_FLOAT64_C(     0.08) },
    { UINT64_C( 2779646423753012273),
      SIMDE_FLOAT64_C(347455802969126528.00),
      SIMDE_FLOAT64_C(21207019224189.85),
      SIMDE_FLOAT64_C(10112294.78),
      SIMDE_FLOAT64_C(    77.15),
      SIMDE_FLOAT64_C(     0.15) },
    { UINT64_C(  360868977349458808),
      SIMDE_FLOAT64_C(45108622168682352.00),
      SIMDE_FLOAT64_C(2753211802287.74),
      SIMDE_FLOAT64_C(1312833.69),
      SIMDE_FLOAT64_C(    10.02),
      SIMDE_FLOAT64_C(     0.02) },
    { UINT64_C(10380111440923722222),
      SIMDE_FLOAT64_C(1297513930115465216.00),
      SIMDE_FLOAT64_C(79193965461149.00),
      SIMDE_FLOAT64_C(37762625.44),
      SIMDE_FLOAT64_C(   288.11),
      SIMDE_FLOAT64_C(     0.56) },
    { UINT64_C( 9763642735089037087),
      SIMDE_FLOAT64_C(1220455341886129664.00),
      SIMDE_FLOAT64_C(74490682488167.09),
      SIMDE_FLOAT64_C(35519925.35),
      SIMDE_FLOAT64_C(   271.00),
      SIMDE_FLOAT64_C(     0.53) },
    { UINT64_C( 4393845023024577058),
      SIMDE_FLOAT64_C(549230627878072128.00),
      SIMDE_FLOAT64_C(33522377189823.74),
      SIMDE_FLOAT64_C(15984715.08),
      SIMDE_FLOAT64_C(   121.95),
      SIMDE_FLOAT64_C(     0.24) },
    { UINT64_C( 6340649816565045645),
      SIMDE_FLOAT64_C(792581227070630656.00),
      SIMDE_FLOAT64_C(48375319035072.67),
      SIMDE_FLOAT64_C(23067149.66),
      SIMDE_FLOAT64_C(   175.99),
      SIMDE_FLOAT64_C(     0.34) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t a = test_vec[i].a;
    simde_float64_t r3 = simde_vcvtd_n_f64_u64(a, 3);
    simde_float64_t r17 = simde_vcvtd_n_f64_u64(a, 17);
    simde_float64_t r38 = simde_vcvtd_n_f64_u64(a, 38);
    simde_float64_t r55 = simde_vcvtd_n_f64_u64(a, 55);
    simde_float64_t r64 = simde_vcvtd_n_f64_u64(a, 64);

    simde_assert_equal_f64(r3, test_vec[i].r3, 1);
    simde_assert_equal_f64(r17, test_vec[i].r17, 1);
    simde_assert_equal_f64(r38, test_vec[i].r38, 1);
    simde_assert_equal_f64(r55, test_vec[i].r55, 1);
    simde_assert_equal_f64(r64, test_vec[i].r64, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    simde_float64_t r3 = simde_vcvtd_n_f64_u64(a, 3);
    simde_float64_t r17 = simde_vcvtd_n_f64_u64(a, 17);
    simde_float64_t r38 = simde_vcvtd_n_f64_u64(a, 38);
    simde_float64_t r55 = simde_vcvtd_n_f64_u64(a, 55);
    simde_float64_t r64 = simde_vcvtd_n_f64_u64(a, 64);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvt_n_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(-0.2), SIMDE_FLOAT16_VALUE(-4.8), SIMDE_FLOAT16_VALUE(9.9), SIMDE_FLOAT16_VALUE(1.1),  },
      { -INT16_C(1), -INT16_C(38), INT16_C(79), INT16_C(8),  },
      { -INT16_C(12), -INT16_C(307), INT16_C(633), INT16_C(70),  },
      { -INT16_C(204), -INT16_C(4916), INT16_C(10136), INT16_C(1126),  },
      { -INT16_C(1638), INT16_MIN, INT16_MAX, INT16_C(9008),  },
      { -INT16_C(13104), INT16_MIN, INT16_MAX, INT16_MAX,  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_int16x4_t r3 = simde_vcvt_n_s16_f16(a, 3);
    simde_int16x4_t r6 = simde_vcvt_n_s16_f16(a, 6);
    simde_int16x4_t r10 = simde_vcvt_n_s16_f16(a, 10);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_int16x4_t r13 = simde_vcvt_n_s16_f16(a, 13);
      simde_int16x4_t r16 = simde_vcvt_n_s16_f16(a, 16);
    #endif

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
      simde_test_arm_neon_assert_equal_i16x4(r16, simde_vld1_s16(test_vec[i].r16));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_int16x4_t r3 = simde_vcvt_n_s16_f16(a, 3);
    simde_int16x4_t r6 = simde_vcvt_n_s16_f16(a, 6);
    simde_int16x4_t r10 = simde_vcvt_n_s16_f16(a, 10);
    simde_int16x4_t r13 = simde_vcvt_n_s16_f16(a, 13);
    simde_int16x4_t r16 = simde_vcvt_n_s16_f16(a, 16);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvt_n_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    int32_t r3[2];
    int32_t r10[2];
    int32_t r16[2];
    int32_t r23[2];
    int32_t r32[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(-733.4), SIMDE_FLOAT32_C(-808.5)  },
      { -INT32_C(5867), -INT32_C(6468)  },
      { -INT32_C(751001), -INT32_C(827904)  },
      { -INT32_C(48064104), -INT32_C(52985856)  },
      { INT32_MIN, INT32_MIN  },
      { INT32_MIN, INT32_MIN  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_int32x2_t r3 = simde_vcvt_n_s32_f32(a, 3);
    simde_int32x2_t r10 = simde_vcvt_n_s32_f32(a, 10);
    simde_int32x2_t r16 = simde_vcvt_n_s32_f32(a, 16);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_int32x2_t r23 = simde_vcvt_n_s32_f32(a, 23);
      simde_int32x2_t r32 = simde_vcvt_n_s32_f32(a, 32);
    #endif

    simde_test_arm_neon_assert_equal_i32x2(r3, simde_vld1_s32(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i32x2(r10, simde_vld1_s32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i32x2(r16, simde_vld1_s32(test_vec[i].r16));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_i32x2(r23, simde_vld1_s32(test_vec[i].r23));
      simde_test_arm_neon_assert_equal_i32x2(r32, simde_vld1_s32(test_vec[i].r32));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_int32x2_t r3 = simde_vcvt_n_s32_f32(a, 3);
    simde_int32x2_t r10 = simde_vcvt_n_s32_f32(a, 10);
    simde_int32x2_t r16 = simde_vcvt_n_s32_f32(a, 16);
    simde_int32x2_t r23 = simde_vcvt_n_s32_f32(a, 23);
    simde_int32x2_t r32 = simde_vcvt_n_s32_f32(a, 32);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_n_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    int64_t r3[1];
    int64_t r17[1];
    int64_t r23[1];
    int64_t r38[1];
    int64_t r55[1];
    int64_t r64[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(-9709.6)  },
      { -INT64_C(77676)  },
      { -INT64_C(1272656691)  },
      { -INT64_C(81450028236)  },
      { -INT64_C(2668954525263462)  },
      { INT64_MIN  },
      { INT64_MIN  } },
    { { SIMDE_FLOAT64_C(8973.1)  },
      { INT64_C(71784)  },
      { INT64_C(1176122163)  },
      { INT64_C(75271818444)  },
      { INT64_C(2466506946799206)  },
      { INT64_MAX  },
      { INT64_MAX  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_int64x1_t r3 = simde_vcvt_n_s64_f64(a, 3);
    simde_int64x1_t r17 = simde_vcvt_n_s64_f64(a, 17);
    simde_int64x1_t r23 = simde_vcvt_n_s64_f64(a, 23);
    simde_int64x1_t r38 = simde_vcvt_n_s64_f64(a, 38);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_int64x1_t r55 = simde_vcvt_n_s64_f64(a, 55);
      simde_int64x1_t r64 = simde_vcvt_n_s64_f64(a, 64);
    #endif

    simde_test_arm_neon_assert_equal_i64x1(r3, simde_vld1_s64(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i64x1(r17, simde_vld1_s64(test_vec[i].r17));
    simde_test_arm_neon_assert_equal_i64x1(r23, simde_vld1_s64(test_vec[i].r23));
    simde_test_arm_neon_assert_equal_i64x1(r38, simde_vld1_s64(test_vec[i].r38));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_i64x1(r55, simde_vld1_s64(test_vec[i].r55));
      simde_test_arm_neon_assert_equal_i64x1(r64, simde_vld1_s64(test_vec[i].r64));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x1_t r3 = simde_vcvt_n_s64_f64(a, 3);
    simde_int64x1_t r17 = simde_vcvt_n_s64_f64(a, 17);
    simde_int64x1_t r23 = simde_vcvt_n_s64_f64(a, 23);
    simde_int64x1_t r38 = simde_vcvt_n_s64_f64(a, 38);
    simde_int64x1_t r55 = simde_vcvt_n_s64_f64(a, 55);
    simde_int64x1_t r64 = simde_vcvt_n_s64_f64(a, 64);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_n_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(9.1), SIMDE_FLOAT16_VALUE(5.4), SIMDE_FLOAT16_VALUE(3.2),  },
      { UINT16_C(11), UINT16_C(72), UINT16_C(43), UINT16_C(25),  },
      { UINT16_C(89), UINT16_C(582), UINT16_C(345), UINT16_C(204),  },
      { UINT16_C(1434), UINT16_C(9320), UINT16_C(5528), UINT16_C(3276),  },
      { UINT16_C(11472), UINT16_MAX, UINT16_C(44224), UINT16_C(26208),  },
      { UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX,  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r3 = simde_vcvt_n_u16_f16(a, 3);
    simde_uint16x4_t r6 = simde_vcvt_n_u16_f16(a, 6);
    simde_uint16x4_t r10 = simde_vcvt_n_u16_f16(a, 10);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_uint16x4_t r13 = simde_vcvt_n_u16_f16(a, 13);
      simde_uint16x4_t r16 = simde_vcvt_n_u16_f16(a, 16);
    #endif

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
      simde_test_arm_neon_assert_equal_u16x4(r16, simde_vld1_u16(test_vec[i].r16));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_uint16x4_t r3 = simde_vcvt_n_u16_f16(a, 3);
    simde_uint16x4_t r6 = simde_vcvt_n_u16_f16(a, 6);
    simde_uint16x4_t r10 = simde_vcvt_n_u16_f16(a, 10);
    simde_uint16x4_t r13 = simde_vcvt_n_u16_f16(a, 13);
    simde_uint16x4_t r16 = simde_vcvt_n_u16_f16(a, 16);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vcvt_n_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    uint32_t r3[2];
    uint32_t r10[2];
    uint32_t r16[2];
    uint32_t r23[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(731.2), SIMDE_FLOAT32_C(293.2)  },
      { UINT32_C(5849), UINT32_C(2345)  },
      { UINT32_C(748748), UINT32_C(300236)  },
      { UINT32_C(47919924), UINT32_C(19215156)  },
      { UINT32_MAX, UINT32_C(2459539968)  },
      { UINT32_MAX, UINT32_MAX  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r3 = simde_vcvt_n_u32_f32(a, 3);
    simde_uint32x2_t r10 = simde_vcvt_n_u32_f32(a, 10);
    simde_uint32x2_t r16 = simde_vcvt_n_u32_f32(a, 16);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_uint32x2_t r23 = simde_vcvt_n_u32_f32(a, 23);
      simde_uint32x2_t r32 = simde_vcvt_n_u32_f32(a, 32);
    #endif

    simde_test_arm_neon_assert_equal_u32x2(r3, simde_vld1_u32(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u32x2(r10, simde_vld1_u32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u32x2(r16, simde_vld1_u32(test_vec[i].r16));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_u32x2(r23, simde_vld1_u32(test_vec[i].r23));
      simde_test_arm_neon_assert_equal_u32x2(r32, simde_vld1_u32(test_vec[i].r32));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_uint32x2_t r3 = simde_vcvt_n_u32_f32(a, 3);
    simde_uint32x2_t r10 = simde_vcvt_n_u32_f32(a, 10);
    simde_uint32x2_t r16 = simde_vcvt_n_u32_f32(a, 16);
    simde_uint32x2_t r23 = simde_vcvt_n_u32_f32(a, 23);
    simde_uint32x2_t r32 = simde_vcvt_n_u32_f32(a, 32);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_n_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    uint64_t r3[1];
    uint64_t r17[1];
    uint64_t r23[1];
    uint64_t r38[1];
    uint64_t r55[1];
    uint64_t r64[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(446.9)  },
      { UINT64_C(3575)  },
      { UINT64_C(58576076)  },
      { UINT64_C(3748868915)  },
      { UINT64_C(122842936613273)  },
      { UINT64_C(16101269387774996480)  },
      { UINT64_MAX  } },
    { { SIMDE_FLOAT64_C(3993.6)  },
      { UINT64_C(31948)  },
      { UINT64_C(523449139)  },
      { UINT64_C(33500744908)  },
      { UINT64_C(1097752409171558)  },
      { UINT64_MAX  },
      { UINT64_MAX  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r3 = simde_vcvt_n_u64_f64(a, 3);
    simde_uint64x1_t r17 = simde_vcvt_n_u64_f64(a, 17);
    simde_uint64x1_t r23 = simde_vcvt_n_u64_f64(a, 23);
    simde_uint64x1_t r38 = simde_vcvt_n_u64_f64(a, 38);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_uint64x1_t r55 = simde_vcvt_n_u64_f64(a, 55);
      simde_uint64x1_t r64 = simde_vcvt_n_u64_f64(a, 64);
    #endif

    simde_test_arm_neon_assert_equal_u64x1(r3, simde_vld1_u64(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u64x1(r17, simde_vld1_u64(test_vec[i].r17));
    simde_test_arm_neon_assert_equal_u64x1(r23, simde_vld1_u64(test_vec[i].r23));
    simde_test_arm_neon_assert_equal_u64x1(r38, simde_vld1_u64(test_vec[i].r38));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_u64x1(r55, simde_vld1_u64(test_vec[i].r55));
      simde_test_arm_neon_assert_equal_u64x1(r64, simde_vld1_u64(test_vec[i].r64));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x1_t r3 = simde_vcvt_n_u64_f64(a, 3);
    simde_uint64x1_t r17 = simde_vcvt_n_u64_f64(a, 17);
    simde_uint64x1_t r23 = simde_vcvt_n_u64_f64(a, 23);
    simde_uint64x1_t r38 = simde_vcvt_n_u64_f64(a, 38);
    simde_uint64x1_t r55 = simde_vcvt_n_u64_f64(a, 55);
    simde_uint64x1_t r64 = simde_vcvt_n_u64_f64(a, 64);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtq_n_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(-0.7), SIMDE_FLOAT16_VALUE(-4.5), SIMDE_FLOAT16_VALUE(0.8), SIMDE_FLOAT16_VALUE(-9.3), SIMDE_FLOAT16_VALUE(-4.4), SIMDE_FLOAT16_VALUE(9.3), SIMDE_FLOAT16_VALUE(6.9), SIMDE_FLOAT16_VALUE(-5.9),  },
      { -INT16_C(5), -INT16_C(36), INT16_C(6), -INT16_C(74), -INT16_C(35), INT16_C(74), INT16_C(55), -INT16_C(47),  },
      { -INT16_C(44), -INT16_C(288), INT16_C(51), -INT16_C(595), -INT16_C(281), INT16_C(595), INT16_C(441), -INT16_C(377),  },
      { -INT16_C(717), -INT16_C(4608), INT16_C(819), -INT16_C(9520), -INT16_C(4504), INT16_C(9520), INT16_C(7064), -INT16_C(6040),  },
      { -INT16_C(5736), INT16_MIN, INT16_C(6552), INT16_MIN, INT16_MIN, INT16_MAX, INT16_MAX, INT16_MIN,  },
      { INT16_MIN, INT16_MIN, INT16_MAX, INT16_MIN, INT16_MIN, INT16_MAX, INT16_MAX, INT16_MIN,  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_int16x8_t r3 = simde_vcvtq_n_s16_f16(a, 3);
    simde_int16x8_t r6 = simde_vcvtq_n_s16_f16(a, 6);
    simde_int16x8_t r10 = simde_vcvtq_n_s16_f16(a, 10);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_int16x8_t r13 = simde_vcvtq_n_s16_f16(a, 13);
      simde_int16x8_t r16 = simde_vcvtq_n_s16_f16(a, 16);
    #endif

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
      simde_test_arm_neon_assert_equal_i16x8(r16, simde_vld1q_s16(test_vec[i].r16));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_int16x8_t r3 = simde_vcvtq_n_s16_f16(a, 3);
    simde_int16x8_t r6 = simde_vcvtq_n_s16_f16(a, 6);
    simde_int16x8_t r10 = simde_vcvtq_n_s16_f16(a, 10);
    simde_int16x8_t r13 = simde_vcvtq_n_s16_f16(a, 13);
    simde_int16x8_t r16 = simde_vcvtq_n_s16_f16(a, 16);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtq_n_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    int32_t r3[4];
    int32_t r10[4];
    int32_t r16[4];
    int32_t r23[4];
    int32_t r32[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(422.6), SIMDE_FLOAT32_C(749.1), SIMDE_FLOAT32_C(-101.2), SIMDE_FLOAT32_C(-5.7)  },
      { INT32_C(3380), INT32_C(5992), -INT32_C(809), -INT32_C(45)  },
      { INT32_C(432742), INT32_C(767078), -INT32_C(103628), -INT32_C(5836)  },
      { INT32_C(27695514), INT32_C(49093016), -INT32_C(6632243), -INT32_C(373555)  },
      { INT32_MAX, INT32_MAX, -INT32_C(848927104), -INT32_C(47815064)  },
      { INT32_MAX, INT32_MAX, INT32_MIN, INT32_MIN  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_int32x4_t r3 = simde_vcvtq_n_s32_f32(a, 3);
    simde_int32x4_t r10 = simde_vcvtq_n_s32_f32(a, 10);
    simde_int32x4_t r16 = simde_vcvtq_n_s32_f32(a, 16);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_int32x4_t r23 = simde_vcvtq_n_s32_f32(a, 23);
      simde_int32x4_t r32 = simde_vcvtq_n_s32_f32(a, 32);
    #endif

    simde_test_arm_neon_assert_equal_i32x4(r3, simde_vld1q_s32(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i32x4(r10, simde_vld1q_s32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i32x4(r16, simde_vld1q_s32(test_vec[i].r16));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_i32x4(r23, simde_vld1q_s32(test_vec[i].r23));
      simde_test_arm_neon_assert_equal_i32x4(r32, simde_vld1q_s32(test_vec[i].r32));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_int32x4_t r3 = simde_vcvtq_n_s32_f32(a, 3);
    simde_int32x4_t r10 = simde_vcvtq_n_s32_f32(a, 10);
    simde_int32x4_t r16 = simde_vcvtq_n_s32_f32(a, 16);
    simde_int32x4_t r23 = simde_vcvtq_n_s32_f32(a, 23);
    simde_int32x4_t r32 = simde_vcvtq_n_s32_f32(a, 32);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_n_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    int64_t r3[2];
    int64_t r17[2];
    int64_t r23[2];
    int64_t r38[2];
    int64_t r55[2];
    int64_t r64[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(-9709.6), SIMDE_FLOAT64_C(8973.1)  },
      { -INT64_C(77676), INT64_C(71784)  },
      { -INT64_C(1272656691), INT64_C(1176122163)  },
      { -INT64_C(81450028236), INT64_C(75271818444)  },
      { -INT64_C(2668954525263462), INT64_C(2466506946799206)  },
      { INT64_MIN, INT64_MAX  },
      { INT64_MIN, INT64_MAX  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_int64x2_t r3 = simde_vcvtq_n_s64_f64(a, 3);
    simde_int64x2_t r17 = simde_vcvtq_n_s64_f64(a, 17);
    simde_int64x2_t r23 = simde_vcvtq_n_s64_f64(a, 23);
    simde_int64x2_t r38 = simde_vcvtq_n_s64_f64(a, 38);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_int64x2_t r55 = simde_vcvtq_n_s64_f64(a, 55);
      simde_int64x2_t r64 = simde_vcvtq_n_s64_f64(a, 64);
    #endif

    simde_test_arm_neon_assert_equal_i64x2(r3, simde_vld1q_s64(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i64x2(r17, simde_vld1q_s64(test_vec[i].r17));
    simde_test_arm_neon_assert_equal_i64x2(r23, simde_vld1q_s64(test_vec[i].r23));
    simde_test_arm_neon_assert_equal_i64x2(r38, simde_vld1q_s64(test_vec[i].r38));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_i64x2(r55, simde_vld1q_s64(test_vec[i].r55));
      simde_test_arm_neon_assert_equal_i64x2(r64, simde_vld1q_s64(test_vec[i].r64));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x2_t r3 = simde_vcvtq_n_s64_f64(a, 3);
    simde_int64x2_t r17 = simde_vcvtq_n_s64_f64(a, 17);
    simde_int64x2_t r23 = simde_vcvtq_n_s64_f64(a, 23);
    simde_int64x2_t r38 = simde_vcvtq_n_s64_f64(a, 38);
    simde_int64x2_t r55 = simde_vcvtq_n_s64_f64(a, 55);
    simde_int64x2_t r64 = simde_vcvtq_n_s64_f64(a, 64);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_n_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(4.8), SIMDE_FLOAT16_VALUE(1.4), SIMDE_FLOAT16_VALUE(0.6), SIMDE_FLOAT16_VALUE(2.6), SIMDE_FLOAT16_VALUE(1.8), SIMDE_FLOAT16_VALUE(6.5), SIMDE_FLOAT16_VALUE(9.8), SIMDE_FLOAT16_VALUE(7.5),  },
      { UINT16_C(38), UINT16_C(11), UINT16_C(4), UINT16_C(20), UINT16_C(14), UINT16_C(52), UINT16_C(78), UINT16_C(60),  },
      { UINT16_C(307), UINT16_C(89), UINT16_C(38), UINT16_C(166), UINT16_C(115), UINT16_C(416), UINT16_C(627), UINT16_C(480),  },
      { UINT16_C(4916), UINT16_C(1434), UINT16_C(614), UINT16_C(2662), UINT16_C(1843), UINT16_C(6656), UINT16_C(10032), UINT16_C(7680),  },
      { UINT16_C(39328), UINT16_C(11472), UINT16_C(4916), UINT16_C(21296), UINT16_C(14744), UINT16_C(53248), UINT16_MAX, UINT16_C(61440),  },
      { UINT16_MAX, UINT16_MAX, UINT16_C(39328), UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX, UINT16_MAX,  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_uint16x8_t r3 = simde_vcvtq_n_u16_f16(a, 3);
    simde_uint16x8_t r6 = simde_vcvtq_n_u16_f16(a, 6);
    simde_uint16x8_t r10 = simde_vcvtq_n_u16_f16(a, 10);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_uint16x8_t r13 = simde_vcvtq_n_u16_f16(a, 13);
      simde_uint16x8_t r16 = simde_vcvtq_n_u16_f16(a, 16);
    #endif

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
      simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_uint16x8_t r3 = simde_vcvtq_n_u16_f16(a, 3);
    simde_uint16x8_t r6 = simde_vcvtq_n_u16_f16(a, 6);
    simde_uint16x8_t r10 = simde_vcvtq_n_u16_f16(a, 10);
    simde_uint16x8_t r13 = simde_vcvtq_n_u16_f16(a, 13);
    simde_uint16x8_t r16 = simde_vcvtq_n_u16_f16(a, 16);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
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
test_simde_vcvtq_n_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    uint32_t r3[4];
    uint32_t r10[4];
    uint32_t r16[4];
    uint32_t r23[4];
    uint32_t r32[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(997.5), SIMDE_FLOAT32_C(825.7), SIMDE_FLOAT32_C(684.9), SIMDE_FLOAT32_C(227.4)  },
      { UINT32_C(7980), UINT32_C(6605), UINT32_C(5479), UINT32_C(1819)  },
      { UINT32_C(1021440), UINT32_C(845516), UINT32_C(701337), UINT32_C(232857)  },
      { UINT32_C(65372160), UINT32_C(54113076), UINT32_C(44885608), UINT32_C(14902886)  },
      { UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_C(1907569408)  },
      { UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r3 = simde_vcvtq_n_u32_f32(a, 3);
    simde_uint32x4_t r10 = simde_vcvtq_n_u32_f32(a, 10);
    simde_uint32x4_t r16 = simde_vcvtq_n_u32_f32(a, 16);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_uint32x4_t r23 = simde_vcvtq_n_u32_f32(a, 23);
      simde_uint32x4_t r32 = simde_vcvtq_n_u32_f32(a, 32);
    #endif

    simde_test_arm_neon_assert_equal_u32x4(r3, simde_vld1q_u32(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u32x4(r10, simde_vld1q_u32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u32x4(r16, simde_vld1q_u32(test_vec[i].r16));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_u32x4(r23, simde_vld1q_u32(test_vec[i].r23));
      simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_uint32x4_t r3 = simde_vcvtq_n_u32_f32(a, 3);
    simde_uint32x4_t r10 = simde_vcvtq_n_u32_f32(a, 10);
    simde_uint32x4_t r16 = simde_vcvtq_n_u32_f32(a, 16);
    simde_uint32x4_t r23 = simde_vcvtq_n_u32_f32(a, 23);
    simde_uint32x4_t r32 = simde_vcvtq_n_u32_f32(a, 32);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_n_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    uint64_t r3[2];
    uint64_t r17[2];
    uint64_t r23[2];
    uint64_t r38[2];
    uint64_t r55[2];
    uint64_t r64[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(446.9), SIMDE_FLOAT64_C(3993.6)  },
      { UINT64_C(3575), UINT64_C(31948)  },
      { UINT64_C(58576076), UINT64_C(523449139)  },
      { UINT64_C(3748868915), UINT64_C(33500744908)  },
      { UINT64_C(122842936613273), UINT64_C(1097752409171558)  },
      { UINT64_C(16101269387774996480), UINT64_MAX  },
      { UINT64_MAX, UINT64_MAX  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r3 = simde_vcvtq_n_u64_f64(a, 3);
    simde_uint64x2_t r17 = simde_vcvtq_n_u64_f64(a, 17);
    simde_uint64x2_t r23 = simde_vcvtq_n_u64_f64(a, 23);
    simde_uint64x2_t r38 = simde_vcvtq_n_u64_f64(a, 38);
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_uint64x2_t r55 = simde_vcvtq_n_u64_f64(a, 55);
      simde_uint64x2_t r64 = simde_vcvtq_n_u64_f64(a, 64);
    #endif

    simde_test_arm_neon_assert_equal_u64x2(r3, simde_vld1q_u64(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u64x2(r17, simde_vld1q_u64(test_vec[i].r17));
    simde_test_arm_neon_assert_equal_u64x2(r23, simde_vld1q_u64(test_vec[i].r23));
    simde_test_arm_neon_assert_equal_u64x2(r38, simde_vld1q_u64(test_vec[i].r38));
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      simde_test_arm_neon_assert_equal_u64x2(r55, simde_vld1q_u64(test_vec[i].r55));
      simde_test_arm_neon_assert_equal_u64x2(r64, simde_vld1q_u64(test_vec[i].r64));
    #endif
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x2_t r3 = simde_vcvtq_n_u64_f64(a, 3);
    simde_uint64x2_t r17 = simde_vcvtq_n_u64_f64(a, 17);
    simde_uint64x2_t r23 = simde_vcvtq_n_u64_f64(a, 23);
    simde_uint64x2_t r38 = simde_vcvtq_n_u64_f64(a, 38);
    simde_uint64x2_t r55 = simde_vcvtq_n_u64_f64(a, 55);
    simde_uint64x2_t r64 = simde_vcvtq_n_u64_f64(a, 64);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_n_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    simde_float16_t r3[4];
    simde_float16_t r6[4];
    simde_float16_t r10[4];
    simde_float16_t r13[4];
    simde_float16_t r16[4];
  } test_vec[] = {
    { { UINT16_C(19849), UINT16_C(26147), UINT16_C(40838), UINT16_C(40781)  },
      { SIMDE_FLOAT16_VALUE(2482.0), SIMDE_FLOAT16_VALUE(3268.4), SIMDE_FLOAT16_VALUE(5104.8), SIMDE_FLOAT16_VALUE(5097.6)  },
      { SIMDE_FLOAT16_VALUE(310.2), SIMDE_FLOAT16_VALUE(408.5), SIMDE_FLOAT16_VALUE(638.1), SIMDE_FLOAT16_VALUE(637.2)  },
      { SIMDE_FLOAT16_VALUE(19.4), SIMDE_FLOAT16_VALUE(25.5), SIMDE_FLOAT16_VALUE(39.9), SIMDE_FLOAT16_VALUE(39.8)  },
      { SIMDE_FLOAT16_VALUE(2.4), SIMDE_FLOAT16_VALUE(3.2), SIMDE_FLOAT16_VALUE(5.0), SIMDE_FLOAT16_VALUE(5.0)  },
      { SIMDE_FLOAT16_VALUE(0.3), SIMDE_FLOAT16_VALUE(0.4), SIMDE_FLOAT16_VALUE(0.6), SIMDE_FLOAT16_VALUE(0.6)  } },
    { { UINT16_C(10037), UINT16_C(52658), UINT16_C(27371), UINT16_C(28364)  },
      { SIMDE_FLOAT16_VALUE(1254.6), SIMDE_FLOAT16_VALUE(6582.3), SIMDE_FLOAT16_VALUE(3421.4), SIMDE_FLOAT16_VALUE(3545.5)  },
      { SIMDE_FLOAT16_VALUE(156.875), SIMDE_FLOAT16_VALUE(822.8), SIMDE_FLOAT16_VALUE(427.7), SIMDE_FLOAT16_VALUE(443.2)  },
      { SIMDE_FLOAT16_VALUE(9.8), SIMDE_FLOAT16_VALUE(51.4), SIMDE_FLOAT16_VALUE(26.7), SIMDE_FLOAT16_VALUE(27.7)  },
      { SIMDE_FLOAT16_VALUE(1.2), SIMDE_FLOAT16_VALUE(6.4), SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(3.5)  },
      { SIMDE_FLOAT16_VALUE(0.2), SIMDE_FLOAT16_VALUE(0.8), SIMDE_FLOAT16_VALUE(0.4), SIMDE_FLOAT16_VALUE(0.4)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_float16x4_t r3 = simde_vcvt_n_f16_u16(a, 3);
    simde_float16x4_t r6 = simde_vcvt_n_f16_u16(a, 6);
    simde_float16x4_t r10 = simde_vcvt_n_f16_u16(a, 10);
    simde_float16x4_t r13 = simde_vcvt_n_f16_u16(a, 13);
    simde_float16x4_t r16 = simde_vcvt_n_f16_u16(a, 16);

    simde_test_arm_neon_assert_equal_f16x4(r3, simde_vld1_f16(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f16x4(r6, simde_vld1_f16(test_vec[i].r6), 1);
    simde_test_arm_neon_assert_equal_f16x4(r10, simde_vld1_f16(test_vec[i].r10), 1);
    simde_test_arm_neon_assert_equal_f16x4(r13, simde_vld1_f16(test_vec[i].r13), 1);
    simde_test_arm_neon_assert_equal_f16x4(r16, simde_vld1_f16(test_vec[i].r16), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_float16x4_t r3 = simde_vcvt_n_f16_u16(a, 3);
    simde_float16x4_t r6 = simde_vcvt_n_f16_u16(a, 6);
    simde_float16x4_t r10 = simde_vcvt_n_f16_u16(a, 10);
    simde_float16x4_t r13 = simde_vcvt_n_f16_u16(a, 13);
    simde_float16x4_t r16 = simde_vcvt_n_f16_u16(a, 16);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_n_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    simde_float16_t r3[4];
    simde_float16_t r6[4];
    simde_float16_t r10[4];
    simde_float16_t r13[4];
    simde_float16_t r16[4];
  } test_vec[] = {
    { { INT16_C(-1573), INT16_C(-19221), INT16_C(23775), INT16_C(-21379)  },
      { SIMDE_FLOAT16_VALUE(-196.625), SIMDE_FLOAT16_VALUE(-2402.6), SIMDE_FLOAT16_VALUE(2971.9), SIMDE_FLOAT16_VALUE(-2672.4)  },
      { SIMDE_FLOAT16_VALUE(-24.578125), SIMDE_FLOAT16_VALUE(-300.25), SIMDE_FLOAT16_VALUE(371.5), SIMDE_FLOAT16_VALUE(-334.0)  },
      { SIMDE_FLOAT16_VALUE(-1.536133), SIMDE_FLOAT16_VALUE(-18.765625), SIMDE_FLOAT16_VALUE(23.218750), SIMDE_FLOAT16_VALUE(-20.8750)  },
      { SIMDE_FLOAT16_VALUE(-0.192017), SIMDE_FLOAT16_VALUE(-2.345703), SIMDE_FLOAT16_VALUE(2.902344), SIMDE_FLOAT16_VALUE(-2.609375)  },
      { SIMDE_FLOAT16_VALUE(0.0), SIMDE_FLOAT16_VALUE(-0.293213), SIMDE_FLOAT16_VALUE(0.362793), SIMDE_FLOAT16_VALUE(-0.326172)  } },
    { { INT16_C(-19672), INT16_C(2663), INT16_C(31268), INT16_C(-11631)  },
      { SIMDE_FLOAT16_VALUE(-2460.0), SIMDE_FLOAT16_VALUE(333.0), SIMDE_FLOAT16_VALUE(3908.5), SIMDE_FLOAT16_VALUE(-1454.0)  },
      { SIMDE_FLOAT16_VALUE(-307.5), SIMDE_FLOAT16_VALUE(41.625), SIMDE_FLOAT16_VALUE(488.5), SIMDE_FLOAT16_VALUE(-181.75)  },
      { SIMDE_FLOAT16_VALUE(-19.21875), SIMDE_FLOAT16_VALUE(2.601562), SIMDE_FLOAT16_VALUE(30.531250), SIMDE_FLOAT16_VALUE(-11.359375)  },
      { SIMDE_FLOAT16_VALUE(-2.402344), SIMDE_FLOAT16_VALUE(0.325195), SIMDE_FLOAT16_VALUE(3.816406), SIMDE_FLOAT16_VALUE(-1.419922)  },
      { SIMDE_FLOAT16_VALUE(-0.300293), SIMDE_FLOAT16_VALUE(0.040649), SIMDE_FLOAT16_VALUE(0.477051), SIMDE_FLOAT16_VALUE(-0.177490)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_float16x4_t r3 = simde_vcvt_n_f16_s16(a, 3);
    simde_float16x4_t r6 = simde_vcvt_n_f16_s16(a, 6);
    simde_float16x4_t r10 = simde_vcvt_n_f16_s16(a, 10);
    simde_float16x4_t r13 = simde_vcvt_n_f16_s16(a, 13);
    simde_float16x4_t r16 = simde_vcvt_n_f16_s16(a, 16);

    simde_test_arm_neon_assert_equal_f16x4(r3, simde_vld1_f16(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f16x4(r6, simde_vld1_f16(test_vec[i].r6), 1);
    simde_test_arm_neon_assert_equal_f16x4(r10, simde_vld1_f16(test_vec[i].r10), 1);
    simde_test_arm_neon_assert_equal_f16x4(r13, simde_vld1_f16(test_vec[i].r13), 1);
    simde_test_arm_neon_assert_equal_f16x4(r16, simde_vld1_f16(test_vec[i].r16), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_float16x4_t r3 = simde_vcvt_n_f16_s16(a, 3);
    simde_float16x4_t r6 = simde_vcvt_n_f16_s16(a, 6);
    simde_float16x4_t r10 = simde_vcvt_n_f16_s16(a, 10);
    simde_float16x4_t r13 = simde_vcvt_n_f16_s16(a, 13);
    simde_float16x4_t r16 = simde_vcvt_n_f16_s16(a, 16);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_n_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    simde_float16_t r3[8];
    simde_float16_t r6[8];
    simde_float16_t r10[8];
    simde_float16_t r13[8];
    simde_float16_t r16[8];
  } test_vec[] = {
    { { UINT16_C(19849), UINT16_C(26147), UINT16_C(40838), UINT16_C(40781), UINT16_C(10037), UINT16_C(52658), UINT16_C(27371), UINT16_C(28364)  },
      { SIMDE_FLOAT16_VALUE(2481.1), SIMDE_FLOAT16_VALUE(3268.4), SIMDE_FLOAT16_VALUE(5104.8), SIMDE_FLOAT16_VALUE(5097.6), SIMDE_FLOAT16_VALUE(1254.6), SIMDE_FLOAT16_VALUE(6582.3), SIMDE_FLOAT16_VALUE(3421.4), SIMDE_FLOAT16_VALUE(3545.5)  },
      { SIMDE_FLOAT16_VALUE(310.2), SIMDE_FLOAT16_VALUE(408.5), SIMDE_FLOAT16_VALUE(638.1), SIMDE_FLOAT16_VALUE(637.2), SIMDE_FLOAT16_VALUE(156.875), SIMDE_FLOAT16_VALUE(822.8), SIMDE_FLOAT16_VALUE(427.7), SIMDE_FLOAT16_VALUE(443.2)  },
      { SIMDE_FLOAT16_VALUE(19.4), SIMDE_FLOAT16_VALUE(25.5), SIMDE_FLOAT16_VALUE(39.9), SIMDE_FLOAT16_VALUE(39.8), SIMDE_FLOAT16_VALUE(9.8), SIMDE_FLOAT16_VALUE(51.4), SIMDE_FLOAT16_VALUE(26.7), SIMDE_FLOAT16_VALUE(27.7)  },
      { SIMDE_FLOAT16_VALUE(2.4), SIMDE_FLOAT16_VALUE(3.2), SIMDE_FLOAT16_VALUE(5.0), SIMDE_FLOAT16_VALUE(5.0), SIMDE_FLOAT16_VALUE(1.2), SIMDE_FLOAT16_VALUE(6.4), SIMDE_FLOAT16_VALUE(3.3), SIMDE_FLOAT16_VALUE(3.5)  },
      { SIMDE_FLOAT16_VALUE(0.3), SIMDE_FLOAT16_VALUE(0.4), SIMDE_FLOAT16_VALUE(0.6), SIMDE_FLOAT16_VALUE(0.6), SIMDE_FLOAT16_VALUE(0.2), SIMDE_FLOAT16_VALUE(0.8), SIMDE_FLOAT16_VALUE(0.4), SIMDE_FLOAT16_VALUE(0.4)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_float16x8_t r3 = simde_vcvtq_n_f16_u16(a, 3);
    simde_float16x8_t r6 = simde_vcvtq_n_f16_u16(a, 6);
    simde_float16x8_t r10 = simde_vcvtq_n_f16_u16(a, 10);
    simde_float16x8_t r13 = simde_vcvtq_n_f16_u16(a, 13);
    simde_float16x8_t r16 = simde_vcvtq_n_f16_u16(a, 16);

    simde_test_arm_neon_assert_equal_f16x8(r3, simde_vld1q_f16(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f16x8(r6, simde_vld1q_f16(test_vec[i].r6), 1);
    simde_test_arm_neon_assert_equal_f16x8(r10, simde_vld1q_f16(test_vec[i].r10), 1);
    simde_test_arm_neon_assert_equal_f16x8(r13, simde_vld1q_f16(test_vec[i].r13), 1);
    simde_test_arm_neon_assert_equal_f16x8(r16, simde_vld1q_f16(test_vec[i].r16), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_float16x8_t r3 = simde_vcvtq_n_f16_u16(a, 3);
    simde_float16x8_t r6 = simde_vcvtq_n_f16_u16(a, 6);
    simde_float16x8_t r10 = simde_vcvtq_n_f16_u16(a, 10);
    simde_float16x8_t r13 = simde_vcvtq_n_f16_u16(a, 13);
    simde_float16x8_t r16 = simde_vcvtq_n_f16_u16(a, 16);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_n_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    simde_float16_t r3[8];
    simde_float16_t r6[8];
    simde_float16_t r10[8];
    simde_float16_t r13[8];
    simde_float16_t r16[8];
  } test_vec[] = {
    { { INT16_C(-1573), INT16_C(-19221), INT16_C(23775), INT16_C(-21379), INT16_C(-19672), INT16_C(2663), INT16_C(31268), INT16_C(-11631)  },
      { SIMDE_FLOAT16_VALUE(-196.625), SIMDE_FLOAT16_VALUE(-2402.6), SIMDE_FLOAT16_VALUE(2971.9), SIMDE_FLOAT16_VALUE(-2672.4), SIMDE_FLOAT16_VALUE(-2460.0), SIMDE_FLOAT16_VALUE(333.0), SIMDE_FLOAT16_VALUE(3908.5), SIMDE_FLOAT16_VALUE(-1454.0)  },
      { SIMDE_FLOAT16_VALUE(-24.578125), SIMDE_FLOAT16_VALUE(-300.25), SIMDE_FLOAT16_VALUE(371.5), SIMDE_FLOAT16_VALUE(-334.0), SIMDE_FLOAT16_VALUE(-307.5), SIMDE_FLOAT16_VALUE(41.625), SIMDE_FLOAT16_VALUE(488.5), SIMDE_FLOAT16_VALUE(-181.75)  },
      { SIMDE_FLOAT16_VALUE(-1.536133), SIMDE_FLOAT16_VALUE(-18.765625), SIMDE_FLOAT16_VALUE(23.218750), SIMDE_FLOAT16_VALUE(-20.8750), SIMDE_FLOAT16_VALUE(-19.21875), SIMDE_FLOAT16_VALUE(2.601562), SIMDE_FLOAT16_VALUE(30.531250), SIMDE_FLOAT16_VALUE(-11.359375)  },
      { SIMDE_FLOAT16_VALUE(-0.192017), SIMDE_FLOAT16_VALUE(-2.345703), SIMDE_FLOAT16_VALUE(2.902344), SIMDE_FLOAT16_VALUE(-2.609375), SIMDE_FLOAT16_VALUE(-2.402344), SIMDE_FLOAT16_VALUE(0.325195), SIMDE_FLOAT16_VALUE(3.816406), SIMDE_FLOAT16_VALUE(-1.419922)  },
      { SIMDE_FLOAT16_VALUE(0.0), SIMDE_FLOAT16_VALUE(-0.293213), SIMDE_FLOAT16_VALUE(0.362793), SIMDE_FLOAT16_VALUE(-0.326172), SIMDE_FLOAT16_VALUE(-0.300293), SIMDE_FLOAT16_VALUE(0.040649), SIMDE_FLOAT16_VALUE(0.477051), SIMDE_FLOAT16_VALUE(-0.177490)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_float16x8_t r3 = simde_vcvtq_n_f16_s16(a, 3);
    simde_float16x8_t r6 = simde_vcvtq_n_f16_s16(a, 6);
    simde_float16x8_t r10 = simde_vcvtq_n_f16_s16(a, 10);
    simde_float16x8_t r13 = simde_vcvtq_n_f16_s16(a, 13);
    simde_float16x8_t r16 = simde_vcvtq_n_f16_s16(a, 16);

    simde_test_arm_neon_assert_equal_f16x8(r3, simde_vld1q_f16(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f16x8(r6, simde_vld1q_f16(test_vec[i].r6), 1);
    simde_test_arm_neon_assert_equal_f16x8(r10, simde_vld1q_f16(test_vec[i].r10), 1);
    simde_test_arm_neon_assert_equal_f16x8(r13, simde_vld1q_f16(test_vec[i].r13), 1);
    simde_test_arm_neon_assert_equal_f16x8(r16, simde_vld1q_f16(test_vec[i].r16), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_float16x8_t r3 = simde_vcvtq_n_f16_s16(a, 3);
    simde_float16x8_t r6 = simde_vcvtq_n_f16_s16(a, 6);
    simde_float16x8_t r10 = simde_vcvtq_n_f16_s16(a, 10);
    simde_float16x8_t r13 = simde_vcvtq_n_f16_s16(a, 13);
    simde_float16x8_t r16 = simde_vcvtq_n_f16_s16(a, 16);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_n_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    simde_float32 r3[4];
    simde_float32 r10[4];
    simde_float32 r16[4];
    simde_float32 r23[4];
    simde_float32 r32[4];
  } test_vec[] = {
    { { -INT32_C(1577698352), INT32_C(1627417640), INT32_C(1166530302), -INT32_C(158461010) },
      { SIMDE_FLOAT32_C(-197212288.0), SIMDE_FLOAT32_C(203427200.0), SIMDE_FLOAT32_C(145816288.0), SIMDE_FLOAT32_C(-19807626.0)  },
      { SIMDE_FLOAT32_C(-1540721.0), SIMDE_FLOAT32_C(1589275.0), SIMDE_FLOAT32_C(1139189.75), SIMDE_FLOAT32_C(-154747.07)  },
      { SIMDE_FLOAT32_C(-24073.76), SIMDE_FLOAT32_C(24832.42), SIMDE_FLOAT32_C(17799.83), SIMDE_FLOAT32_C(-2417.92)  },
      { SIMDE_FLOAT32_C(-188.07), SIMDE_FLOAT32_C(194.003), SIMDE_FLOAT32_C(139.06), SIMDE_FLOAT32_C(-18.89)  },
      { SIMDE_FLOAT32_C(-0.37), SIMDE_FLOAT32_C(0.38), SIMDE_FLOAT32_C(0.27), SIMDE_FLOAT32_C(-0.04)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_float32x4_t r3 = simde_vcvtq_n_f32_s32(a, 3);
    simde_float32x4_t r10 = simde_vcvtq_n_f32_s32(a, 10);
    simde_float32x4_t r16 = simde_vcvtq_n_f32_s32(a, 16);
    simde_float32x4_t r23 = simde_vcvtq_n_f32_s32(a, 23);
    simde_float32x4_t r32 = simde_vcvtq_n_f32_s32(a, 32);

    simde_test_arm_neon_assert_equal_f32x4(r3, simde_vld1q_f32(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f32x4(r10, simde_vld1q_f32(test_vec[i].r10), 1);
    simde_test_arm_neon_assert_equal_f32x4(r16, simde_vld1q_f32(test_vec[i].r16), 1);
    simde_test_arm_neon_assert_equal_f32x4(r23, simde_vld1q_f32(test_vec[i].r23), 1);
    simde_test_arm_neon_assert_equal_f32x4(r32, simde_vld1q_f32(test_vec[i].r32), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_float32x4_t r3 = simde_vcvtq_n_f32_s32(a, 3);
    simde_float32x4_t r10 = simde_vcvtq_n_f32_s32(a, 10);
    simde_float32x4_t r16 = simde_vcvtq_n_f32_s32(a, 16);
    simde_float32x4_t r23 = simde_vcvtq_n_f32_s32(a, 23);
    simde_float32x4_t r32 = simde_vcvtq_n_f32_s32(a, 32);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_n_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[2];
    simde_float32 r3[2];
    simde_float32 r10[2];
    simde_float32 r16[2];
    simde_float32 r23[2];
    simde_float32 r32[2];
  } test_vec[] = {
    { { -INT32_C(1577698352), INT32_C(1627417640) },
      { SIMDE_FLOAT32_C(-197212288.0), SIMDE_FLOAT32_C(203427200.0)  },
      { SIMDE_FLOAT32_C(-1540721.0), SIMDE_FLOAT32_C(1589275.0)  },
      { SIMDE_FLOAT32_C(-24073.76), SIMDE_FLOAT32_C(24832.42)  },
      { SIMDE_FLOAT32_C(-188.07), SIMDE_FLOAT32_C(194.003)  },
      { SIMDE_FLOAT32_C(-0.37), SIMDE_FLOAT32_C(0.38)  } },
    { { INT32_C(1166530302), -INT32_C(158461010) },
      { SIMDE_FLOAT32_C(145816288.0), SIMDE_FLOAT32_C(-19807626.0)  },
      { SIMDE_FLOAT32_C(1139189.75), SIMDE_FLOAT32_C(-154747.07)  },
      { SIMDE_FLOAT32_C(17799.83), SIMDE_FLOAT32_C(-2417.92)  },
      { SIMDE_FLOAT32_C(139.06), SIMDE_FLOAT32_C(-18.89)  },
      { SIMDE_FLOAT32_C(0.27), SIMDE_FLOAT32_C(-0.04)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_float32x2_t r3 = simde_vcvt_n_f32_s32(a, 3);
    simde_float32x2_t r10 = simde_vcvt_n_f32_s32(a, 10);
    simde_float32x2_t r16 = simde_vcvt_n_f32_s32(a, 16);
    simde_float32x2_t r23 = simde_vcvt_n_f32_s32(a, 23);
    simde_float32x2_t r32 = simde_vcvt_n_f32_s32(a, 32);

    simde_test_arm_neon_assert_equal_f32x2(r3, simde_vld1_f32(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f32x2(r10, simde_vld1_f32(test_vec[i].r10), 1);
    simde_test_arm_neon_assert_equal_f32x2(r16, simde_vld1_f32(test_vec[i].r16), 1);
    simde_test_arm_neon_assert_equal_f32x2(r23, simde_vld1_f32(test_vec[i].r23), 1);
    simde_test_arm_neon_assert_equal_f32x2(r32, simde_vld1_f32(test_vec[i].r32), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_float32x2_t r3 = simde_vcvt_n_f32_s32(a, 3);
    simde_float32x2_t r10 = simde_vcvt_n_f32_s32(a, 10);
    simde_float32x2_t r16 = simde_vcvt_n_f32_s32(a, 16);
    simde_float32x2_t r23 = simde_vcvt_n_f32_s32(a, 23);
    simde_float32x2_t r32 = simde_vcvt_n_f32_s32(a, 32);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_n_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[1];
    simde_float64 r3[1];
    simde_float64 r17[1];
    simde_float64 r23[1];
    simde_float64 r38[1];
    simde_float64 r55[1];
    simde_float64 r64[1];
  } test_vec[] = {
    { { UINT64_C(1686065688) },
      { SIMDE_FLOAT64_C(210758211.000000)  },
      { SIMDE_FLOAT64_C(12863.660000)  },
      { SIMDE_FLOAT64_C(200.990000)  },
      { SIMDE_FLOAT64_C(0.010000)  },
      { SIMDE_FLOAT64_C(0.000000)  },
      { SIMDE_FLOAT64_C(0.000000)  } },
    { { UINT64_C(763499258) },
      { SIMDE_FLOAT64_C(95437407.250000)  },
      { SIMDE_FLOAT64_C(5825.040000)  },
      { SIMDE_FLOAT64_C(91.020000)  },
      { SIMDE_FLOAT64_C(0.000000)  },
      { SIMDE_FLOAT64_C(0.000000)  },
      { SIMDE_FLOAT64_C(0.000000)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_float64x1_t r3 = simde_vcvt_n_f64_u64(a, 3);
    simde_float64x1_t r17 = simde_vcvt_n_f64_u64(a, 17);
    simde_float64x1_t r23 = simde_vcvt_n_f64_u64(a, 23);
    simde_float64x1_t r38 = simde_vcvt_n_f64_u64(a, 38);
    simde_float64x1_t r55 = simde_vcvt_n_f64_u64(a, 55);
    simde_float64x1_t r64 = simde_vcvt_n_f64_u64(a, 64);

    simde_test_arm_neon_assert_equal_f64x1(r3, simde_vld1_f64(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f64x1(r17, simde_vld1_f64(test_vec[i].r17), 1);
    simde_test_arm_neon_assert_equal_f64x1(r23, simde_vld1_f64(test_vec[i].r23), 1);
    simde_test_arm_neon_assert_equal_f64x1(r38, simde_vld1_f64(test_vec[i].r38), 1);
    simde_test_arm_neon_assert_equal_f64x1(r55, simde_vld1_f64(test_vec[i].r55), 1);
    simde_test_arm_neon_assert_equal_f64x1(r64, simde_vld1_f64(test_vec[i].r64), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_float64x1_t r3 = simde_vcvt_n_f64_u64(a, 3);
    simde_float64x1_t r17 = simde_vcvt_n_f64_u64(a, 17);
    simde_float64x1_t r23 = simde_vcvt_n_f64_u64(a, 23);
    simde_float64x1_t r38 = simde_vcvt_n_f64_u64(a, 38);
    simde_float64x1_t r55 = simde_vcvt_n_f64_u64(a, 55);
    simde_float64x1_t r64 = simde_vcvt_n_f64_u64(a, 64);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_n_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    simde_float64 r3[2];
    simde_float64 r17[2];
    simde_float64 r23[2];
    simde_float64 r38[2];
    simde_float64 r55[2];
    simde_float64 r64[2];
  } test_vec[] = {
    { { UINT64_C(18446744073618801398), UINT64_C(1801750886) },
      { SIMDE_FLOAT64_C(2305843009202350080.000000), SIMDE_FLOAT64_C(225218860.750000)  },
      { SIMDE_FLOAT64_C(140737488354635.625000), SIMDE_FLOAT64_C(13746.270000)  },
      { SIMDE_FLOAT64_C(2199023255541.179932), SIMDE_FLOAT64_C(214.790000)  },
      { SIMDE_FLOAT64_C(67108864.000000), SIMDE_FLOAT64_C(0.010000)  },
      { SIMDE_FLOAT64_C(512.000000), SIMDE_FLOAT64_C(0.000000)  },
      { SIMDE_FLOAT64_C(1.000000), SIMDE_FLOAT64_C(0.000000)  } },
    { { UINT64_C(18446744072095273152), UINT64_C(34887362) },
      { SIMDE_FLOAT64_C(2305843009011909376.000000), SIMDE_FLOAT64_C(4360920.250000)  },
      { SIMDE_FLOAT64_C(140737488343012.046875), SIMDE_FLOAT64_C(266.170000)  },
      { SIMDE_FLOAT64_C(2199023255359.560059), SIMDE_FLOAT64_C(4.160000)  },
      { SIMDE_FLOAT64_C(67108863.990000), SIMDE_FLOAT64_C(0.000000)  },
      { SIMDE_FLOAT64_C(512.000000), SIMDE_FLOAT64_C(0.000000)  },
      { SIMDE_FLOAT64_C(1.000000), SIMDE_FLOAT64_C(0.000000)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_float64x2_t r3 = simde_vcvtq_n_f64_u64(a, 3);
    simde_float64x2_t r17 = simde_vcvtq_n_f64_u64(a, 17);
    simde_float64x2_t r23 = simde_vcvtq_n_f64_u64(a, 23);
    simde_float64x2_t r38 = simde_vcvtq_n_f64_u64(a, 38);
    simde_float64x2_t r55 = simde_vcvtq_n_f64_u64(a, 55);
    simde_float64x2_t r64 = simde_vcvtq_n_f64_u64(a, 64);

    simde_test_arm_neon_assert_equal_f64x2(r3, simde_vld1q_f64(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f64x2(r17, simde_vld1q_f64(test_vec[i].r17), 1);
    simde_test_arm_neon_assert_equal_f64x2(r23, simde_vld1q_f64(test_vec[i].r23), 1);
    simde_test_arm_neon_assert_equal_f64x2(r38, simde_vld1q_f64(test_vec[i].r38), 1);
    simde_test_arm_neon_assert_equal_f64x2(r55, simde_vld1q_f64(test_vec[i].r55), 1);
    simde_test_arm_neon_assert_equal_f64x2(r64, simde_vld1q_f64(test_vec[i].r64), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_float64x2_t r3 = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r17 = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r23 = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r38 = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r55 = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r64 = simde_vcvtq_n_f64_u64(a, r3, r17, r23, r38, r55);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_n_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[1];
    simde_float64 r3[1];
    simde_float64 r17[1];
    simde_float64 r23[1];
    simde_float64 r38[1];
    simde_float64 r55[1];
    simde_float64 r64[1];
  } test_vec[] = {
    { { -INT64_C(430855472) },
      { SIMDE_FLOAT64_C(-53856934.000000)  },
      { SIMDE_FLOAT64_C(-3287.170000)  },
      { SIMDE_FLOAT64_C(-51.360000)  },
      { SIMDE_FLOAT64_C(-0.000000)  },
      { SIMDE_FLOAT64_C(-0.000000)  },
      { SIMDE_FLOAT64_C(-0.000000)  } },
    { { INT64_C(163557546) },
      { SIMDE_FLOAT64_C(20444693.250000)  },
      { SIMDE_FLOAT64_C(1247.850000)  },
      { SIMDE_FLOAT64_C(19.500000)  },
      { SIMDE_FLOAT64_C(0.000000)  },
      { SIMDE_FLOAT64_C(0.000000)  },
      { SIMDE_FLOAT64_C(0.000000)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_float64x1_t r3 = simde_vcvt_n_f64_s64(a, 3);
    simde_float64x1_t r17 = simde_vcvt_n_f64_s64(a, 17);
    simde_float64x1_t r23 = simde_vcvt_n_f64_s64(a, 23);
    simde_float64x1_t r38 = simde_vcvt_n_f64_s64(a, 38);
    simde_float64x1_t r55 = simde_vcvt_n_f64_s64(a, 55);
    simde_float64x1_t r64 = simde_vcvt_n_f64_s64(a, 64);

    simde_test_arm_neon_assert_equal_f64x1(r3, simde_vld1_f64(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f64x1(r17, simde_vld1_f64(test_vec[i].r17), 1);
    simde_test_arm_neon_assert_equal_f64x1(r23, simde_vld1_f64(test_vec[i].r23), 1);
    simde_test_arm_neon_assert_equal_f64x1(r38, simde_vld1_f64(test_vec[i].r38), 1);
    simde_test_arm_neon_assert_equal_f64x1(r55, simde_vld1_f64(test_vec[i].r55), 1);
    simde_test_arm_neon_assert_equal_f64x1(r64, simde_vld1_f64(test_vec[i].r64), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_float64x1_t r3 = simde_vcvt_n_f64_s64(a, 3);
    simde_float64x1_t r17 = simde_vcvt_n_f64_s64(a, 17);
    simde_float64x1_t r23 = simde_vcvt_n_f64_s64(a, 23);
    simde_float64x1_t r38 = simde_vcvt_n_f64_s64(a, 38);
    simde_float64x1_t r55 = simde_vcvt_n_f64_s64(a, 55);
    simde_float64x1_t r64 = simde_vcvt_n_f64_s64(a, 64);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_n_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    simde_float64 r3[2];
    simde_float64 r17[2];
    simde_float64 r23[2];
    simde_float64 r38[2];
    simde_float64 r55[2];
    simde_float64 r64[2];
  } test_vec[] = {
    { { -INT64_C(430855472), INT64_C(163557546) },
      { SIMDE_FLOAT64_C(-53856934.000000), SIMDE_FLOAT64_C(20444693.250000)  },
      { SIMDE_FLOAT64_C(-3287.170000), SIMDE_FLOAT64_C(1247.850000)  },
      { SIMDE_FLOAT64_C(-51.360000), SIMDE_FLOAT64_C(19.500000)  },
      { SIMDE_FLOAT64_C(-0.000000), SIMDE_FLOAT64_C(0.000000)  },
      { SIMDE_FLOAT64_C(-0.000000), SIMDE_FLOAT64_C(0.000000)  },
      { SIMDE_FLOAT64_C(-0.000000), SIMDE_FLOAT64_C(0.000000)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_float64x2_t r3 = simde_vcvtq_n_f64_s64(a, 3);
    simde_float64x2_t r17 = simde_vcvtq_n_f64_s64(a, 17);
    simde_float64x2_t r23 = simde_vcvtq_n_f64_s64(a, 23);
    simde_float64x2_t r38 = simde_vcvtq_n_f64_s64(a, 38);
    simde_float64x2_t r55 = simde_vcvtq_n_f64_s64(a, 55);
    simde_float64x2_t r64 = simde_vcvtq_n_f64_s64(a, 64);

    simde_test_arm_neon_assert_equal_f64x2(r3, simde_vld1q_f64(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f64x2(r17, simde_vld1q_f64(test_vec[i].r17), 1);
    simde_test_arm_neon_assert_equal_f64x2(r23, simde_vld1q_f64(test_vec[i].r23), 1);
    simde_test_arm_neon_assert_equal_f64x2(r38, simde_vld1q_f64(test_vec[i].r38), 1);
    simde_test_arm_neon_assert_equal_f64x2(r55, simde_vld1q_f64(test_vec[i].r55), 1);
    simde_test_arm_neon_assert_equal_f64x2(r64, simde_vld1q_f64(test_vec[i].r64), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_float64x2_t r3 = simde_vcvtq_n_f64_s64(a, 3);
    simde_float64x2_t r17 = simde_vcvtq_n_f64_s64(a, 17);
    simde_float64x2_t r23 = simde_vcvtq_n_f64_s64(a, 23);
    simde_float64x2_t r38 = simde_vcvtq_n_f64_s64(a, 38);
    simde_float64x2_t r55 = simde_vcvtq_n_f64_s64(a, 55);
    simde_float64x2_t r64 = simde_vcvtq_n_f64_s64(a, 64);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r38, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_n_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    simde_float32 r3[4];
    simde_float32 r10[4];
    simde_float32 r16[4];
    simde_float32 r23[4];
    simde_float32 r32[4];
  } test_vec[] = {
    { { UINT32_C(2614615940), UINT32_C(11008892), UINT32_C(1049754994), UINT32_C(357707956) },
      { SIMDE_FLOAT32_C(326826992.500000), SIMDE_FLOAT32_C(1376111.500000), SIMDE_FLOAT32_C(131219374.250000), SIMDE_FLOAT32_C(44713494.500000)  },
      { SIMDE_FLOAT32_C(2553336.0), SIMDE_FLOAT32_C(10750.87), SIMDE_FLOAT32_C(1025151.375), SIMDE_FLOAT32_C(349324.1875)  },
      { SIMDE_FLOAT32_C(39895.87), SIMDE_FLOAT32_C(167.98), SIMDE_FLOAT32_C(16017.99), SIMDE_FLOAT32_C(5458.19)  },
      { SIMDE_FLOAT32_C(311.686), SIMDE_FLOAT32_C(1.312), SIMDE_FLOAT32_C(125.14), SIMDE_FLOAT32_C(42.642)  },
      { SIMDE_FLOAT32_C(0.610000), SIMDE_FLOAT32_C(0.000000), SIMDE_FLOAT32_C(0.240000), SIMDE_FLOAT32_C(0.080000)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_float32x4_t r3 = simde_vcvtq_n_f32_u32(a, 3);
    simde_float32x4_t r10 = simde_vcvtq_n_f32_u32(a, 10);
    simde_float32x4_t r16 = simde_vcvtq_n_f32_u32(a, 16);
    simde_float32x4_t r23 = simde_vcvtq_n_f32_u32(a, 23);
    simde_float32x4_t r32 = simde_vcvtq_n_f32_u32(a, 32);

    simde_test_arm_neon_assert_equal_f32x4(r3, simde_vld1q_f32(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f32x4(r10, simde_vld1q_f32(test_vec[i].r10), 1);
    simde_test_arm_neon_assert_equal_f32x4(r16, simde_vld1q_f32(test_vec[i].r16), 1);
    simde_test_arm_neon_assert_equal_f32x4(r23, simde_vld1q_f32(test_vec[i].r23), 1);
    simde_test_arm_neon_assert_equal_f32x4(r32, simde_vld1q_f32(test_vec[i].r32), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_float32x4_t r3 = simde_vcvtq_n_f32_u32(a, 3);
    simde_float32x4_t r10 = simde_vcvtq_n_f32_u32(a, 10);
    simde_float32x4_t r16 = simde_vcvtq_n_f32_u32(a, 16);
    simde_float32x4_t r23 = simde_vcvtq_n_f32_u32(a, 23);
    simde_float32x4_t r32 = simde_vcvtq_n_f32_u32(a, 32);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_n_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[2];
    simde_float32 r3[2];
    simde_float32 r10[2];
    simde_float32 r16[2];
    simde_float32 r23[2];
    simde_float32 r32[2];
  } test_vec[] = {
    { { UINT32_C(2614615940), UINT32_C(11008892) },
      { SIMDE_FLOAT32_C(326826992.500000), SIMDE_FLOAT32_C(1376111.500000)  },
      { SIMDE_FLOAT32_C(2553336.0), SIMDE_FLOAT32_C(10750.87)  },
      { SIMDE_FLOAT32_C(39895.87), SIMDE_FLOAT32_C(167.98)  },
      { SIMDE_FLOAT32_C(311.686), SIMDE_FLOAT32_C(1.312)  },
      { SIMDE_FLOAT32_C(0.610000), SIMDE_FLOAT32_C(0.000000)  } },
    { { UINT32_C(1049754994), UINT32_C(357707956) },
      { SIMDE_FLOAT32_C(131219374.250000), SIMDE_FLOAT32_C(44713494.500000)  },
      { SIMDE_FLOAT32_C(1025151.375), SIMDE_FLOAT32_C(349324.1875)  },
      { SIMDE_FLOAT32_C(16017.99), SIMDE_FLOAT32_C(5458.19)  },
      { SIMDE_FLOAT32_C(125.14), SIMDE_FLOAT32_C(42.642)  },
      { SIMDE_FLOAT32_C(0.240000), SIMDE_FLOAT32_C(0.080000)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_float32x2_t r3 = simde_vcvt_n_f32_u32(a, 3);
    simde_float32x2_t r10 = simde_vcvt_n_f32_u32(a, 10);
    simde_float32x2_t r16 = simde_vcvt_n_f32_u32(a, 16);
    simde_float32x2_t r23 = simde_vcvt_n_f32_u32(a, 23);
    simde_float32x2_t r32 = simde_vcvt_n_f32_u32(a, 32);

    simde_test_arm_neon_assert_equal_f32x2(r3, simde_vld1_f32(test_vec[i].r3), 1);
    simde_test_arm_neon_assert_equal_f32x2(r10, simde_vld1_f32(test_vec[i].r10), 1);
    simde_test_arm_neon_assert_equal_f32x2(r16, simde_vld1_f32(test_vec[i].r16), 1);
    simde_test_arm_neon_assert_equal_f32x2(r23, simde_vld1_f32(test_vec[i].r23), 1);
    simde_test_arm_neon_assert_equal_f32x2(r32, simde_vld1_f32(test_vec[i].r32), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_float32x2_t r3 = simde_vcvt_n_f32_u32(a, 3);
    simde_float32x2_t r10 = simde_vcvt_n_f32_u32(a, 10);
    simde_float32x2_t r16 = simde_vcvt_n_f32_u32(a, 16);
    simde_float32x2_t r23 = simde_vcvt_n_f32_u32(a, 23);
    simde_float32x2_t r32 = simde_vcvt_n_f32_u32(a, 32);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_s16_f16)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_s32_f16)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_s64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_u16_f16)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_u32_f16)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_u64_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_s16)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_s32)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_u16)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_u32)
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_n_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_n_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_n_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_n_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_n_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_n_u64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_n_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_n_f64_u64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_s64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_f16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_f16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_f64_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_f16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_f16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_f64_u64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_s64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
