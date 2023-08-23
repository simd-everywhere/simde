#define SIMDE_TEST_ARM_NEON_INSN cvt_n

#include "test-neon.h"
#include "../../../simde/arm/neon/cvt_n.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vcvth_n_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[1];
    int16_t r3[1];
    int16_t r6[1];
    int16_t r10[1];
    int16_t r13[1];
    int16_t r16[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_C(  24.220) },
      {  INT16_C(     193) },
      {  INT16_C(    1550) },
      {  INT16_C(   24800) },
      {         INT16_MAX },
      {         INT16_MAX } },
    { { -SIMDE_FLOAT16_C(   8.057) },
      { -INT16_C(      64) },
      { -INT16_C(     515) },
      { -INT16_C(    8248) },
      {         INT16_MIN },
      {         INT16_MIN } },
    { { -SIMDE_FLOAT16_C(   1.310) },
      { -INT16_C(      10) },
      { -INT16_C(      83) },
      { -INT16_C(    1341) },
      { -INT16_C(   10728) },
      {         INT16_MIN } },
    { { -SIMDE_FLOAT16_C(  24.017) },
      { -INT16_C(     192) },
      { -INT16_C(    1537) },
      { -INT16_C(   24592) },
      {         INT16_MIN },
      {         INT16_MIN } },
    { {  SIMDE_FLOAT16_C(  23.037) },
      {  INT16_C(     184) },
      {  INT16_C(    1474) },
      {  INT16_C(   23584) },
      {         INT16_MAX },
      {         INT16_MAX } },
    { {  SIMDE_FLOAT16_C(   7.442) },
      {  INT16_C(      59) },
      {  INT16_C(     476) },
      {  INT16_C(    7620) },
      {         INT16_MAX },
      {         INT16_MAX } },
    { { -SIMDE_FLOAT16_C(  18.102) },
      { -INT16_C(     144) },
      { -INT16_C(    1159) },
      { -INT16_C(   18544) },
      {         INT16_MIN },
      {         INT16_MIN } },
    { { -SIMDE_FLOAT16_C(  10.834) },
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
    int16_t r13 = simde_vcvth_n_s16_f16(a, 13);
    int16_t r16 = simde_vcvth_n_s16_f16(a, 16);

    simde_assert_equal_i16(r3, test_vec[i].r3[0]);
    simde_assert_equal_i16(r6, test_vec[i].r6[0]);
    simde_assert_equal_i16(r10, test_vec[i].r10[0]);
    simde_assert_equal_i16(r13, test_vec[i].r13[0]);
    simde_assert_equal_i16(r16, test_vec[i].r16[0]);
  }

  return 0;
}

static int
test_simde_vcvth_n_s32_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[1];
    int32_t r3[1];
    int32_t r6[1];
    int32_t r10[1];
    int32_t r13[1];
    int32_t r16[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_C(    18.262) },
      {  INT32_C(       146) },
      {  INT32_C(      1169) },
      {  INT32_C(     18704) },
      {  INT32_C(    149632) },
      {  INT32_C(   1197056) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a[0];
    int32_t r3 = simde_vcvth_n_s32_f16(a, 3);
    int32_t r6 = simde_vcvth_n_s32_f16(a, 6);
    int32_t r10 = simde_vcvth_n_s32_f16(a, 10);
    int32_t r13 = simde_vcvth_n_s32_f16(a, 13);
    int32_t r16 = simde_vcvth_n_s32_f16(a, 16);

    simde_assert_equal_i32(r3, test_vec[i].r3[0]);
    simde_assert_equal_i32(r6, test_vec[i].r6[0]);
    simde_assert_equal_i32(r10, test_vec[i].r10[0]);
    simde_assert_equal_i32(r13, test_vec[i].r13[0]);
    simde_assert_equal_i32(r16, test_vec[i].r16[0]);
  }

  return 0;
}

static int
test_simde_vcvth_n_s64_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[1];
    int64_t r3[1];
    int64_t r6[1];
    int64_t r10[1];
    int64_t r13[1];
    int64_t r16[1];
  } test_vec[] = {
    { { -SIMDE_FLOAT16_C(    24.064) },
      { -INT64_C(       192) },
      { -INT64_C(      1540) },
      { -INT64_C(     24640) },
      { -INT64_C(    197120) },
      { -INT64_C(   1576960) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a[0];
    int64_t r3 = simde_vcvth_n_s64_f16(a, 3);
    int64_t r6 = simde_vcvth_n_s64_f16(a, 6);
    int64_t r10 = simde_vcvth_n_s64_f16(a, 10);
    int64_t r13 = simde_vcvth_n_s64_f16(a, 13);
    int64_t r16 = simde_vcvth_n_s64_f16(a, 16);

    simde_assert_equal_i64(r3, test_vec[i].r3[0]);
    simde_assert_equal_i64(r6, test_vec[i].r6[0]);
    simde_assert_equal_i64(r10, test_vec[i].r10[0]);
    simde_assert_equal_i64(r13, test_vec[i].r13[0]);
    simde_assert_equal_i64(r16, test_vec[i].r16[0]);
  }

  return 0;
}

static int
test_simde_vcvth_n_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[1];
    uint16_t r3[1];
    uint16_t r6[1];
    uint16_t r10[1];
    uint16_t r13[1];
    uint16_t r16[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_C(      1.01) },
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
    uint16_t r16 = simde_vcvth_n_u16_f16(a, 16);

    simde_assert_equal_u16(r3, test_vec[i].r3[0]);
    simde_assert_equal_u16(r6, test_vec[i].r6[0]);
    simde_assert_equal_u16(r10, test_vec[i].r10[0]);
    simde_assert_equal_u16(r13, test_vec[i].r13[0]);
    simde_assert_equal_u16(r16, test_vec[i].r16[0]);
  }

  return 0;
}

static int
test_simde_vcvth_n_u32_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[1];
    uint32_t r3[1];
    uint32_t r6[1];
    uint32_t r10[1];
    uint32_t r13[1];
    uint32_t r16[1];
  } test_vec[] = {
    { { -SIMDE_FLOAT16_C(     26.30) },
      {  UINT32_C(         0) },
      {  UINT32_C(         0) },
      {  UINT32_C(         0) },
      {  UINT32_C(         0) },
      {  UINT32_C(         0) } },
    { {  SIMDE_FLOAT16_C(     24.79) },
      {  UINT32_C(       198) },
      {  UINT32_C(      1587) },
      {  UINT32_C(     25392) },
      {  UINT32_C(    203136) },
      {  UINT32_C(   1625088) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a[0];
    uint32_t r3 = simde_vcvth_n_u32_f16(a, 3);
    uint32_t r6 = simde_vcvth_n_u32_f16(a, 6);
    uint32_t r10 = simde_vcvth_n_u32_f16(a, 10);
    uint32_t r13 = simde_vcvth_n_u32_f16(a, 13);
    uint32_t r16 = simde_vcvth_n_u32_f16(a, 16);

    simde_assert_equal_u32(r3, test_vec[i].r3[0]);
    simde_assert_equal_u32(r6, test_vec[i].r6[0]);
    simde_assert_equal_u32(r10, test_vec[i].r10[0]);
    simde_assert_equal_u32(r13, test_vec[i].r13[0]);
    simde_assert_equal_u32(r16, test_vec[i].r16[0]);
  }

  return 0;
}

static int
test_simde_vcvth_n_u64_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[1];
    uint64_t r3[1];
    uint64_t r6[1];
    uint64_t r10[1];
    uint64_t r13[1];
    uint64_t r16[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_C(      1.82) },
      {  UINT64_C(        14) },
      {  UINT64_C(       116) },
      {  UINT64_C(      1864) },
      {  UINT64_C(     14912) },
      {  UINT64_C(    119296) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a[0];
    uint64_t r3 = simde_vcvth_n_u64_f16(a, 3);
    uint64_t r6 = simde_vcvth_n_u64_f16(a, 6);
    uint64_t r10 = simde_vcvth_n_u64_f16(a, 10);
    uint64_t r13 = simde_vcvth_n_u64_f16(a, 13);
    uint64_t r16 = simde_vcvth_n_u64_f16(a, 16);

    simde_assert_equal_u64(r3, test_vec[i].r3[0]);
    simde_assert_equal_u64(r6, test_vec[i].r6[0]);
    simde_assert_equal_u64(r10, test_vec[i].r10[0]);
    simde_assert_equal_u64(r13, test_vec[i].r13[0]);
    simde_assert_equal_u64(r16, test_vec[i].r16[0]);
  }

  return 0;
}

static int
test_simde_vcvth_n_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[1];
    simde_float16_t r3[1];
    simde_float16_t r6[1];
    simde_float16_t r10[1];
    simde_float16_t r13[1];
    simde_float16_t r16[1];
  } test_vec[] = {
    { {  INT16_C(      2586) },
      {  SIMDE_FLOAT16_C(   323.250) },
      {  SIMDE_FLOAT16_C(    40.406) },
      {  SIMDE_FLOAT16_C(     2.525) },
      {  SIMDE_FLOAT16_C(     0.316) },
      {  SIMDE_FLOAT16_C(     0.039) } },
    { { -INT16_C(     12099) },
      { -SIMDE_FLOAT16_C(  1512.375) },
      { -SIMDE_FLOAT16_C(   189.047) },
      { -SIMDE_FLOAT16_C(    11.815) },
      { -SIMDE_FLOAT16_C(     1.477) },
      { -SIMDE_FLOAT16_C(     0.185) } },
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
}

static int
test_simde_vcvth_n_f16_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[1];
    simde_float16_t r3[1];
    simde_float16_t r6[1];
    simde_float16_t r10[1];
    simde_float16_t r13[1];
    simde_float16_t r16[1];
  } test_vec[] = {
    { {  INT32_C(   6803529) },
      {  SIMDE_FLOAT16_C(850441.125) },
      {  SIMDE_FLOAT16_C(106305.141) },
      {  SIMDE_FLOAT16_C(  6644.071) },
      {  SIMDE_FLOAT16_C(   830.509) },
      {  SIMDE_FLOAT16_C(   103.814) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a[0];
    simde_float16_t r3 = simde_vcvth_n_f16_s32(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_s32(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_s32(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_s32(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_s32(a, 16);

    simde_assert_equal_f16(r3, test_vec[i].r3[0], 1);
    simde_assert_equal_f16(r6, test_vec[i].r6[0], 1);
    simde_assert_equal_f16(r10, test_vec[i].r10[0], 1);
    simde_assert_equal_f16(r13, test_vec[i].r13[0], 1);
    simde_assert_equal_f16(r16, test_vec[i].r16[0], 1);
  }

  return 0;
}

static int
test_simde_vcvth_n_f16_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    simde_float16_t r3[1];
    simde_float16_t r6[1];
    simde_float16_t r10[1];
    simde_float16_t r13[1];
    simde_float16_t r16[1];
  } test_vec[] = {
    { { -INT64_C(7987073179265747968) },
      { -SIMDE_FLOAT16_C(998384147408218496.000) },
      { -SIMDE_FLOAT16_C(124798018426027312.000) },
      { -SIMDE_FLOAT16_C(7799876151626707.000) },
      { -SIMDE_FLOAT16_C(974984518953338.375) },
      { -SIMDE_FLOAT16_C(121873064869167.297) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t a = test_vec[i].a[0];
    simde_float16_t r3 = simde_vcvth_n_f16_s64(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_s64(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_s64(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_s64(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_s64(a, 16);

    simde_assert_equal_f16(r3, test_vec[i].r3[0], 1);
    simde_assert_equal_f16(r6, test_vec[i].r6[0], 1);
    simde_assert_equal_f16(r10, test_vec[i].r10[0], 1);
    simde_assert_equal_f16(r13, test_vec[i].r13[0], 1);
    simde_assert_equal_f16(r16, test_vec[i].r16[0], 1);
  }

  return 0;
}

static int
test_simde_vcvth_n_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[1];
    simde_float16_t r3[1];
    simde_float16_t r6[1];
    simde_float16_t r10[1];
    simde_float16_t r13[1];
    simde_float16_t r16[1];
  } test_vec[] = {
    { {  UINT16_C(       195) },
      {  SIMDE_FLOAT16_C(    24.375) },
      {  SIMDE_FLOAT16_C(     3.047) },
      {  SIMDE_FLOAT16_C(     0.190) },
      {  SIMDE_FLOAT16_C(     0.024) },
      {  SIMDE_FLOAT16_C(     0.003) } },
    { {  UINT16_C(     47989) },
      {  SIMDE_FLOAT16_C(  5998.625) },
      {  SIMDE_FLOAT16_C(   749.828) },
      {  SIMDE_FLOAT16_C(    46.864) },
      {  SIMDE_FLOAT16_C(     5.858) },
      {  SIMDE_FLOAT16_C(     0.732) } },
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
}

static int
test_simde_vcvth_n_f16_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[1];
    simde_float16_t r3[1];
    simde_float16_t r6[1];
    simde_float16_t r10[1];
    simde_float16_t r13[1];
    simde_float16_t r16[1];
  } test_vec[] = {
    { {  UINT32_C(2341947767) },
      {  SIMDE_FLOAT16_C(292743470.875) },
      {  SIMDE_FLOAT16_C(36592933.859) },
      {  SIMDE_FLOAT16_C(2287058.366) },
      {  SIMDE_FLOAT16_C(285882.296) },
      {  SIMDE_FLOAT16_C( 35735.287) } },
    { {  UINT32_C(2631710417) },
      {  SIMDE_FLOAT16_C(328963802.125) },
      {  SIMDE_FLOAT16_C(41120475.266) },
      {  SIMDE_FLOAT16_C(2570029.704) },
      {  SIMDE_FLOAT16_C(321253.713) },
      {  SIMDE_FLOAT16_C( 40156.714) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a[0];
    simde_float16_t r3 = simde_vcvth_n_f16_u32(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_u32(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_u32(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_u32(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_u32(a, 16);

    simde_assert_equal_f16(r3, test_vec[i].r3[0], 1);
    simde_assert_equal_f16(r6, test_vec[i].r6[0], 1);
    simde_assert_equal_f16(r10, test_vec[i].r10[0], 1);
    simde_assert_equal_f16(r13, test_vec[i].r13[0], 1);
    simde_assert_equal_f16(r16, test_vec[i].r16[0], 1);
  }

  return 0;
}

static int
test_simde_vcvth_n_f16_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    simde_float16_t r3[1];
    simde_float16_t r6[1];
    simde_float16_t r10[1];
    simde_float16_t r13[1];
    simde_float16_t r16[1];
  } test_vec[] = {
    { {  UINT64_C(16900905102085820416) },
      {  SIMDE_FLOAT16_C(2112613137760727552.000) },
      {  SIMDE_FLOAT16_C(264076642220090944.000) },
      {  SIMDE_FLOAT16_C(16504790138755684.000) },
      {  SIMDE_FLOAT16_C(2063098767344460.500) },
      {  SIMDE_FLOAT16_C(257887345918057.562) } },
    { {  UINT64_C(13990626116228507648) },
      {  SIMDE_FLOAT16_C(1748828264528563456.000) },
      {  SIMDE_FLOAT16_C(218603533066070432.000) },
      {  SIMDE_FLOAT16_C(13662720816629402.000) },
      {  SIMDE_FLOAT16_C(1707840102078675.250) },
      {  SIMDE_FLOAT16_C(213480012759834.406) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t a = test_vec[i].a[0];
    simde_float16_t r3 = simde_vcvth_n_f16_u64(a, 3);
    simde_float16_t r6 = simde_vcvth_n_f16_u64(a, 6);
    simde_float16_t r10 = simde_vcvth_n_f16_u64(a, 10);
    simde_float16_t r13 = simde_vcvth_n_f16_u64(a, 13);
    simde_float16_t r16 = simde_vcvth_n_f16_u64(a, 16);

    simde_assert_equal_f16(r3, test_vec[i].r3[0], 1);
    simde_assert_equal_f16(r6, test_vec[i].r6[0], 1);
    simde_assert_equal_f16(r10, test_vec[i].r10[0], 1);
    simde_assert_equal_f16(r13, test_vec[i].r13[0], 1);
    simde_assert_equal_f16(r16, test_vec[i].r16[0], 1);
  }

  return 0;
}

static int
test_simde_vcvts_n_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
    int32_t r23 = simde_vcvts_n_s32_f32(a, 23);
    int32_t r32 = simde_vcvts_n_s32_f32(a, 32);

    simde_assert_equal_i32(r3, test_vec[i].r3[0]);
    simde_assert_equal_i32(r10, test_vec[i].r10[0]);
    simde_assert_equal_i32(r16, test_vec[i].r16[0]);
    simde_assert_equal_i32(r23, test_vec[i].r23[0]);
    simde_assert_equal_i32(r32, test_vec[i].r32[0]);
  }

  return 0;
}

static int
test_simde_vcvts_n_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[1];
    uint32_t r3[1];
    uint32_t r10[1];
    uint32_t r16[1];
    uint32_t r23[1];
    uint32_t r32[1];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C( 490.307) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) } },
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
    { { -SIMDE_FLOAT32_C( 471.929) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) } },
    { { -SIMDE_FLOAT32_C( 605.541) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) } },
    { { -SIMDE_FLOAT32_C( 977.856) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) },
      {  UINT32_C(       0) } },
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
    uint32_t r23 = simde_vcvts_n_u32_f32(a, 23);
    uint32_t r32 = simde_vcvts_n_u32_f32(a, 32);

    simde_assert_equal_u32(r3, test_vec[i].r3[0]);
    simde_assert_equal_u32(r10, test_vec[i].r10[0]);
    simde_assert_equal_u32(r16, test_vec[i].r16[0]);
    simde_assert_equal_u32(r23, test_vec[i].r23[0]);
    simde_assert_equal_u32(r32, test_vec[i].r32[0]);
  }

  return 0;
}

static int
test_simde_vcvts_n_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[1];
    simde_float32_t r3[1];
    simde_float32_t r10[1];
    simde_float32_t r16[1];
    simde_float32_t r23[1];
    simde_float32_t r32[1];
  } test_vec[] = {
    { {  INT32_C(  366157) },
      {  SIMDE_FLOAT32_C(45769.625) },
      {  SIMDE_FLOAT32_C( 357.575) },
      {  SIMDE_FLOAT32_C(   5.587) },
      {  SIMDE_FLOAT32_C(   0.044) },
      {  SIMDE_FLOAT32_C(   0.000) } },
    { { -INT32_C(  731804) },
      { -SIMDE_FLOAT32_C(91475.500) },
      { -SIMDE_FLOAT32_C( 714.652) },
      { -SIMDE_FLOAT32_C(  11.166) },
      { -SIMDE_FLOAT32_C(   0.087) },
      { -SIMDE_FLOAT32_C(   0.000) } },
    { {  INT32_C(  547841) },
      {  SIMDE_FLOAT32_C(68480.125) },
      {  SIMDE_FLOAT32_C( 535.001) },
      {  SIMDE_FLOAT32_C(   8.359) },
      {  SIMDE_FLOAT32_C(   0.065) },
      {  SIMDE_FLOAT32_C(   0.000) } },
    { { -INT32_C(  419755) },
      { -SIMDE_FLOAT32_C(52469.375) },
      { -SIMDE_FLOAT32_C( 409.917) },
      { -SIMDE_FLOAT32_C(   6.405) },
      { -SIMDE_FLOAT32_C(   0.050) },
      { -SIMDE_FLOAT32_C(   0.000) } },
    { { -INT32_C(  288716) },
      { -SIMDE_FLOAT32_C(36089.500) },
      { -SIMDE_FLOAT32_C( 281.949) },
      { -SIMDE_FLOAT32_C(   4.405) },
      { -SIMDE_FLOAT32_C(   0.034) },
      { -SIMDE_FLOAT32_C(   0.000) } },
    { { -INT32_C( 1075167) },
      { -SIMDE_FLOAT32_C(134395.875) },
      { -SIMDE_FLOAT32_C(1049.968) },
      { -SIMDE_FLOAT32_C(  16.406) },
      { -SIMDE_FLOAT32_C(   0.128) },
      { -SIMDE_FLOAT32_C(   0.000) } },
    { {  INT32_C(   18967) },
      {  SIMDE_FLOAT32_C(2370.875) },
      {  SIMDE_FLOAT32_C(  18.522) },
      {  SIMDE_FLOAT32_C(   0.289) },
      {  SIMDE_FLOAT32_C(   0.002) },
      {  SIMDE_FLOAT32_C(   0.000) } },
    { {  INT32_C(  662857) },
      {  SIMDE_FLOAT32_C(82857.125) },
      {  SIMDE_FLOAT32_C( 647.321) },
      {  SIMDE_FLOAT32_C(  10.114) },
      {  SIMDE_FLOAT32_C(   0.079) },
      {  SIMDE_FLOAT32_C(   0.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a[0];
    simde_float32_t r3 = simde_vcvts_n_f32_s32(a, 3);
    simde_float32_t r10 = simde_vcvts_n_f32_s32(a, 10);
    simde_float32_t r16 = simde_vcvts_n_f32_s32(a, 16);
    simde_float32_t r23 = simde_vcvts_n_f32_s32(a, 23);
    simde_float32_t r32 = simde_vcvts_n_f32_s32(a, 32);

    simde_assert_equal_f32(r3, test_vec[i].r3[0], 1);
    simde_assert_equal_f32(r10, test_vec[i].r10[0], 1);
    simde_assert_equal_f32(r16, test_vec[i].r16[0], 1);
    simde_assert_equal_f32(r23, test_vec[i].r23[0], 1);
    simde_assert_equal_f32(r32, test_vec[i].r32[0], 1);
  }

  return 0;
}

static int
test_simde_vcvts_n_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[1];
    simde_float32_t r3[1];
    simde_float32_t r10[1];
    simde_float32_t r16[1];
    simde_float32_t r23[1];
    simde_float32_t r32[1];
  } test_vec[] = {
    { {  UINT32_C( 2622046) },
      {  SIMDE_FLOAT32_C(327755.750) },
      {  SIMDE_FLOAT32_C(2560.592) },
      {  SIMDE_FLOAT32_C(  40.009) },
      {  SIMDE_FLOAT32_C(   0.313) },
      {  SIMDE_FLOAT32_C(   0.001) } },
    { {  UINT32_C( 1200641) },
      {  SIMDE_FLOAT32_C(150080.125) },
      {  SIMDE_FLOAT32_C(1172.501) },
      {  SIMDE_FLOAT32_C(  18.320) },
      {  SIMDE_FLOAT32_C(   0.143) },
      {  SIMDE_FLOAT32_C(   0.000) } },
    { {  UINT32_C(   48082) },
      {  SIMDE_FLOAT32_C(6010.250) },
      {  SIMDE_FLOAT32_C(  46.955) },
      {  SIMDE_FLOAT32_C(   0.734) },
      {  SIMDE_FLOAT32_C(   0.006) },
      {  SIMDE_FLOAT32_C(   0.000) } },
    { {  UINT32_C( 3590267) },
      {  SIMDE_FLOAT32_C(448783.375) },
      {  SIMDE_FLOAT32_C(3506.120) },
      {  SIMDE_FLOAT32_C(  54.783) },
      {  SIMDE_FLOAT32_C(   0.428) },
      {  SIMDE_FLOAT32_C(   0.001) } },
    { {  UINT32_C( 3258478) },
      {  SIMDE_FLOAT32_C(407309.750) },
      {  SIMDE_FLOAT32_C(3182.107) },
      {  SIMDE_FLOAT32_C(  49.720) },
      {  SIMDE_FLOAT32_C(   0.388) },
      {  SIMDE_FLOAT32_C(   0.001) } },
    { {  UINT32_C( 1129370) },
      {  SIMDE_FLOAT32_C(141171.250) },
      {  SIMDE_FLOAT32_C(1102.900) },
      {  SIMDE_FLOAT32_C(  17.233) },
      {  SIMDE_FLOAT32_C(   0.135) },
      {  SIMDE_FLOAT32_C(   0.000) } },
    { {  UINT32_C(  403080) },
      {  SIMDE_FLOAT32_C(50385.000) },
      {  SIMDE_FLOAT32_C( 393.633) },
      {  SIMDE_FLOAT32_C(   6.151) },
      {  SIMDE_FLOAT32_C(   0.048) },
      {  SIMDE_FLOAT32_C(   0.000) } },
    { {  UINT32_C( 2192389) },
      {  SIMDE_FLOAT32_C(274048.625) },
      {  SIMDE_FLOAT32_C(2141.005) },
      {  SIMDE_FLOAT32_C(  33.453) },
      {  SIMDE_FLOAT32_C(   0.261) },
      {  SIMDE_FLOAT32_C(   0.001) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a[0];
    simde_float32_t r3 = simde_vcvts_n_f32_u32(a, 3);
    simde_float32_t r10 = simde_vcvts_n_f32_u32(a, 10);
    simde_float32_t r16 = simde_vcvts_n_f32_u32(a, 16);
    simde_float32_t r23 = simde_vcvts_n_f32_u32(a, 23);
    simde_float32_t r32 = simde_vcvts_n_f32_u32(a, 32);

    simde_assert_equal_f32(r3, test_vec[i].r3[0], 1);
    simde_assert_equal_f32(r10, test_vec[i].r10[0], 1);
    simde_assert_equal_f32(r16, test_vec[i].r16[0], 1);
    simde_assert_equal_f32(r23, test_vec[i].r23[0], 1);
    simde_assert_equal_f32(r32, test_vec[i].r32[0], 1);
  }

  return 0;
}

static int
test_simde_vcvtd_n_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
    int64_t r55 = simde_vcvtd_n_s64_f64(a, 55);
    int64_t r64 = simde_vcvtd_n_s64_f64(a, 64);

    simde_assert_equal_i64(r3, test_vec[i].r3[0]);
    simde_assert_equal_i64(r17, test_vec[i].r17[0]);
    simde_assert_equal_i64(r38, test_vec[i].r38[0]);
    simde_assert_equal_i64(r55, test_vec[i].r55[0]);
    simde_assert_equal_i64(r64, test_vec[i].r64[0]);
  }

  return 0;
}

static int
test_simde_vcvtd_n_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64_t a[1];
    uint64_t r3[1];
    uint64_t r17[1];
    uint64_t r38[1];
    uint64_t r55[1];
    uint64_t r64[1];
  } test_vec[] = {
    { { -SIMDE_FLOAT64_C(           57326.309) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) } },
    { { -SIMDE_FLOAT64_C(           59785.695) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) } },
    { { -SIMDE_FLOAT64_C(           27056.633) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) } },
    { { -SIMDE_FLOAT64_C(           63444.078) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) } },
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
    { { -SIMDE_FLOAT64_C(           56773.816) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) } },
    { { -SIMDE_FLOAT64_C(           65364.516) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) },
      {  UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64_t a = test_vec[i].a[0];
    uint64_t r3 = simde_vcvtd_n_u64_f64(a, 3);
    uint64_t r17 = simde_vcvtd_n_u64_f64(a, 17);
    uint64_t r38 = simde_vcvtd_n_u64_f64(a, 38);
    uint64_t r55 = simde_vcvtd_n_u64_f64(a, 55);
    uint64_t r64 = simde_vcvtd_n_u64_f64(a, 64);

    simde_assert_equal_u64(r3, test_vec[i].r3[0]);
    simde_assert_equal_u64(r17, test_vec[i].r17[0]);
    simde_assert_equal_u64(r38, test_vec[i].r38[0]);
    simde_assert_equal_u64(r55, test_vec[i].r55[0]);
    simde_assert_equal_u64(r64, test_vec[i].r64[0]);
  }
  return 0;
}

static int
test_simde_vcvtd_n_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    simde_float64_t r3[1];
    simde_float64_t r17[1];
    simde_float64_t r38[1];
    simde_float64_t r55[1];
    simde_float64_t r64[1];
  } test_vec[] = {
    { { -INT64_C(     735807757379453) },
      { -SIMDE_FLOAT64_C(  91975969672431.625) },
      { -SIMDE_FLOAT64_C(      5613767680.202) },
      { -SIMDE_FLOAT64_C(            2676.853) },
      { -SIMDE_FLOAT64_C(               0.020) },
      { -SIMDE_FLOAT64_C(               0.000) } },
    { {  INT64_C(    6167495300835119) },
      {  SIMDE_FLOAT64_C( 770936912604389.875) },
      {  SIMDE_FLOAT64_C(     47054254919.702) },
      {  SIMDE_FLOAT64_C(           22437.217) },
      {  SIMDE_FLOAT64_C(               0.171) },
      {  SIMDE_FLOAT64_C(               0.000) } },
    { { -INT64_C(    6055022287639449) },
      { -SIMDE_FLOAT64_C( 756877785954931.125) },
      { -SIMDE_FLOAT64_C(     46196153927.913) },
      { -SIMDE_FLOAT64_C(           22028.043) },
      { -SIMDE_FLOAT64_C(               0.168) },
      { -SIMDE_FLOAT64_C(               0.000) } },
    { { -INT64_C(    2832446886359960) },
      { -SIMDE_FLOAT64_C( 354055860794995.000) },
      { -SIMDE_FLOAT64_C(     21609854784.851) },
      { -SIMDE_FLOAT64_C(           10304.382) },
      { -SIMDE_FLOAT64_C(               0.079) },
      { -SIMDE_FLOAT64_C(               0.000) } },
    { { -INT64_C(    3342277711258023) },
      { -SIMDE_FLOAT64_C( 417784713907252.875) },
      { -SIMDE_FLOAT64_C(     25499555292.191) },
      { -SIMDE_FLOAT64_C(           12159.135) },
      { -SIMDE_FLOAT64_C(               0.093) },
      { -SIMDE_FLOAT64_C(               0.000) } },
    { { -INT64_C(    8372982121429873) },
      { -SIMDE_FLOAT64_C(1046622765178734.125) },
      { -SIMDE_FLOAT64_C(     63880784007.491) },
      { -SIMDE_FLOAT64_C(           30460.732) },
      { -SIMDE_FLOAT64_C(               0.232) },
      { -SIMDE_FLOAT64_C(               0.000) } },
    { {  INT64_C(    8542511432801410) },
      {  SIMDE_FLOAT64_C(1067813929100176.250) },
      {  SIMDE_FLOAT64_C(     65174190008.556) },
      {  SIMDE_FLOAT64_C(           31077.476) },
      {  SIMDE_FLOAT64_C(               0.237) },
      {  SIMDE_FLOAT64_C(               0.000) } },
    { {  INT64_C(    5736898574813231) },
      {  SIMDE_FLOAT64_C( 717112321851653.875) },
      {  SIMDE_FLOAT64_C(     43769062613.016) },
      {  SIMDE_FLOAT64_C(           20870.715) },
      {  SIMDE_FLOAT64_C(               0.159) },
      {  SIMDE_FLOAT64_C(               0.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t a = test_vec[i].a[0];
    simde_float64_t r3 = simde_vcvtd_n_f64_s64(a, 3);
    simde_float64_t r17 = simde_vcvtd_n_f64_s64(a, 17);
    simde_float64_t r38 = simde_vcvtd_n_f64_s64(a, 38);
    simde_float64_t r55 = simde_vcvtd_n_f64_s64(a, 55);
    simde_float64_t r64 = simde_vcvtd_n_f64_s64(a, 64);

    simde_assert_equal_f64(r3, test_vec[i].r3[0], 1);
    simde_assert_equal_f64(r17, test_vec[i].r17[0], 1);
    simde_assert_equal_f64(r38, test_vec[i].r38[0], 1);
    simde_assert_equal_f64(r55, test_vec[i].r55[0], 1);
    simde_assert_equal_f64(r64, test_vec[i].r64[0], 1);
  }

  return 0;
}

static int
test_simde_vcvtd_n_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    simde_float64_t r3[1];
    simde_float64_t r17[1];
    simde_float64_t r38[1];
    simde_float64_t r55[1];
    simde_float64_t r64[1];
  } test_vec[] = {
    { {  UINT64_C(   17627676351447148) },
      {  SIMDE_FLOAT64_C(2203459543930893.500) },
      {  SIMDE_FLOAT64_C(    134488497554.376) },
      {  SIMDE_FLOAT64_C(           64129.113) },
      {  SIMDE_FLOAT64_C(               0.489) },
      {  SIMDE_FLOAT64_C(               0.001) } },
    { {  UINT64_C(   18207548249679672) },
      {  SIMDE_FLOAT64_C(2275943531209959.000) },
      {  SIMDE_FLOAT64_C(    138912569043.577) },
      {  SIMDE_FLOAT64_C(           66238.675) },
      {  SIMDE_FLOAT64_C(               0.505) },
      {  SIMDE_FLOAT64_C(               0.001) } },
    { {  UINT64_C(   12441429466244526) },
      {  SIMDE_FLOAT64_C(1555178683280565.750) },
      {  SIMDE_FLOAT64_C(     94920573930.699) },
      {  SIMDE_FLOAT64_C(           45261.657) },
      {  SIMDE_FLOAT64_C(               0.345) },
      {  SIMDE_FLOAT64_C(               0.001) } },
    { {  UINT64_C(   15941712238835774) },
      {  SIMDE_FLOAT64_C(1992714029854471.750) },
      {  SIMDE_FLOAT64_C(    121625612173.735) },
      {  SIMDE_FLOAT64_C(           57995.611) },
      {  SIMDE_FLOAT64_C(               0.442) },
      {  SIMDE_FLOAT64_C(               0.001) } },
    { {  UINT64_C(    9181954566203002) },
      {  SIMDE_FLOAT64_C(1147744320775375.250) },
      {  SIMDE_FLOAT64_C(     70052753953.575) },
      {  SIMDE_FLOAT64_C(           33403.756) },
      {  SIMDE_FLOAT64_C(               0.255) },
      {  SIMDE_FLOAT64_C(               0.000) } },
    { {  UINT64_C(   12439258589883542) },
      {  SIMDE_FLOAT64_C(1554907323735442.750) },
      {  SIMDE_FLOAT64_C(     94904011458.462) },
      {  SIMDE_FLOAT64_C(           45253.759) },
      {  SIMDE_FLOAT64_C(               0.345) },
      {  SIMDE_FLOAT64_C(               0.001) } },
    { {  UINT64_C(    3487789820586862) },
      {  SIMDE_FLOAT64_C( 435973727573357.750) },
      {  SIMDE_FLOAT64_C(     26609724583.335) },
      {  SIMDE_FLOAT64_C(           12688.505) },
      {  SIMDE_FLOAT64_C(               0.097) },
      {  SIMDE_FLOAT64_C(               0.000) } },
    { {  UINT64_C(    8325385935020280) },
      {  SIMDE_FLOAT64_C(1040673241877535.000) },
      {  SIMDE_FLOAT64_C(     63517653923.189) },
      {  SIMDE_FLOAT64_C(           30287.578) },
      {  SIMDE_FLOAT64_C(               0.231) },
      {  SIMDE_FLOAT64_C(               0.000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t a = test_vec[i].a[0];
    simde_float64_t r3 = simde_vcvtd_n_f64_u64(a, 3);
    simde_float64_t r17 = simde_vcvtd_n_f64_u64(a, 17);
    simde_float64_t r38 = simde_vcvtd_n_f64_u64(a, 38);
    simde_float64_t r55 = simde_vcvtd_n_f64_u64(a, 55);
    simde_float64_t r64 = simde_vcvtd_n_f64_u64(a, 64);

    simde_assert_equal_f64(r3, test_vec[i].r3[0], 1);
    simde_assert_equal_f64(r17, test_vec[i].r17[0], 1);
    simde_assert_equal_f64(r38, test_vec[i].r38[0], 1);
    simde_assert_equal_f64(r55, test_vec[i].r55[0], 1);
    simde_assert_equal_f64(r64, test_vec[i].r64[0], 1);
  }

  return 0;
}

static int
test_simde_vcvt_n_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[4];
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
}

static int
test_simde_vcvt_n_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvt_n_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvt_n_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[4];
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
}

static int
test_simde_vcvt_n_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvt_n_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtq_n_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[8];
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
}

static int
test_simde_vcvtq_n_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtq_n_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtq_n_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[8];
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
}

static int
test_simde_vcvtq_n_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtq_n_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvt_n_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvt_n_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtq_n_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtq_n_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtq_n_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvt_n_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvt_n_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtq_n_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvt_n_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtq_n_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvtq_n_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vcvt_n_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
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
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_s32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_s64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_u32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_u64_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_n_f16_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_n_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_n_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_n_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_n_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_n_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_n_u64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_n_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_n_f64_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_n_s16_f16)
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

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_s64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_n_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
