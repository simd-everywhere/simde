#define SIMDE_TEST_ARM_NEON_INSN cvt_n

#include "test-neon.h"
#include "../../../simde/arm/neon/cvt_n.h"
#include "../../../simde/arm/neon/dup_n.h"

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
