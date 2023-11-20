#define SIMDE_TEST_ARM_NEON_INSN dup_n

#include "test-neon.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vdup_n_f16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      simde_float16_t a;
      simde_float16_t r[4];
    } test_vec[] = {
      { SIMDE_FLOAT16_VALUE(  -930.50),
      { SIMDE_FLOAT16_VALUE(  -930.50), SIMDE_FLOAT16_VALUE(  -930.50), SIMDE_FLOAT16_VALUE(  -930.50), SIMDE_FLOAT16_VALUE(  -930.50) } },
    { SIMDE_FLOAT16_VALUE(   789.00),
      { SIMDE_FLOAT16_VALUE(   789.00), SIMDE_FLOAT16_VALUE(   789.00), SIMDE_FLOAT16_VALUE(   789.00), SIMDE_FLOAT16_VALUE(   789.00) } },
    { SIMDE_FLOAT16_VALUE(  -706.00),
      { SIMDE_FLOAT16_VALUE(  -706.00), SIMDE_FLOAT16_VALUE(  -706.00), SIMDE_FLOAT16_VALUE(  -706.00), SIMDE_FLOAT16_VALUE(  -706.00) } },
    { SIMDE_FLOAT16_VALUE(   626.50),
      { SIMDE_FLOAT16_VALUE(   626.50), SIMDE_FLOAT16_VALUE(   626.50), SIMDE_FLOAT16_VALUE(   626.50), SIMDE_FLOAT16_VALUE(   626.50) } },
    { SIMDE_FLOAT16_VALUE(  -321.75),
      { SIMDE_FLOAT16_VALUE(  -321.75), SIMDE_FLOAT16_VALUE(  -321.75), SIMDE_FLOAT16_VALUE(  -321.75), SIMDE_FLOAT16_VALUE(  -321.75) } },
    { SIMDE_FLOAT16_VALUE(    91.50),
      { SIMDE_FLOAT16_VALUE(    91.50), SIMDE_FLOAT16_VALUE(    91.50), SIMDE_FLOAT16_VALUE(    91.50), SIMDE_FLOAT16_VALUE(    91.50) } },
    { SIMDE_FLOAT16_VALUE(   479.25),
      { SIMDE_FLOAT16_VALUE(   479.25), SIMDE_FLOAT16_VALUE(   479.25), SIMDE_FLOAT16_VALUE(   479.25), SIMDE_FLOAT16_VALUE(   479.25) } },
    { SIMDE_FLOAT16_VALUE(  -428.00),
      { SIMDE_FLOAT16_VALUE(  -428.00), SIMDE_FLOAT16_VALUE(  -428.00), SIMDE_FLOAT16_VALUE(  -428.00), SIMDE_FLOAT16_VALUE(  -428.00) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_float16_t a;
      simde_float16x4_t r;

      a = test_vec[i].a;
      r = simde_vdup_n_f16(a);

      simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float16_t a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
      simde_float16x4_t r = simde_vdup_n_f16(a);

      simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vdup_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a;
    simde_float32 r[2];
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   891.26),
      { SIMDE_FLOAT32_C(   891.26), SIMDE_FLOAT32_C(   891.26) } },
    { SIMDE_FLOAT32_C(  -212.41),
      { SIMDE_FLOAT32_C(  -212.41), SIMDE_FLOAT32_C(  -212.41) } },
    { SIMDE_FLOAT32_C(   467.72),
      { SIMDE_FLOAT32_C(   467.72), SIMDE_FLOAT32_C(   467.72) } },
    { SIMDE_FLOAT32_C(  -459.92),
      { SIMDE_FLOAT32_C(  -459.92), SIMDE_FLOAT32_C(  -459.92) } },
    { SIMDE_FLOAT32_C(   178.65),
      { SIMDE_FLOAT32_C(   178.65), SIMDE_FLOAT32_C(   178.65) } },
    { SIMDE_FLOAT32_C(   923.96),
      { SIMDE_FLOAT32_C(   923.96), SIMDE_FLOAT32_C(   923.96) } },
    { SIMDE_FLOAT32_C(  -720.22),
      { SIMDE_FLOAT32_C(  -720.22), SIMDE_FLOAT32_C(  -720.22) } },
    { SIMDE_FLOAT32_C(  -919.57),
      { SIMDE_FLOAT32_C(  -919.57), SIMDE_FLOAT32_C(  -919.57) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a;
    simde_float32x2_t r;

    a = test_vec[i].a;
    r = simde_vdup_n_f32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vdup_n_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    double a;
    simde_float64 r[1];
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -118.53),
      { SIMDE_FLOAT64_C(  -118.53) } },
    { SIMDE_FLOAT64_C(  -542.12),
      { SIMDE_FLOAT64_C(  -542.12) } },
    { SIMDE_FLOAT64_C(  -633.36),
      { SIMDE_FLOAT64_C(  -633.36) } },
    { SIMDE_FLOAT64_C(  -497.58),
      { SIMDE_FLOAT64_C(  -497.58) } },
    { SIMDE_FLOAT64_C(   313.94),
      { SIMDE_FLOAT64_C(   313.94) } },
    { SIMDE_FLOAT64_C(   244.08),
      { SIMDE_FLOAT64_C(   244.08) } },
    { SIMDE_FLOAT64_C(   138.92),
      { SIMDE_FLOAT64_C(   138.92) } },
    { SIMDE_FLOAT64_C(  -906.24),
      { SIMDE_FLOAT64_C(  -906.24) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    simde_float64x1_t r = simde_vdup_n_f64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t r = simde_vdup_n_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a;
    int8_t r[8];
  } test_vec[] = {
    { -INT8_C( 125),
      { -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125), -INT8_C( 125) } },
    {  INT8_C(  51),
      {  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51),  INT8_C(  51) } },
    { -INT8_C( 121),
      { -INT8_C( 121), -INT8_C( 121), -INT8_C( 121), -INT8_C( 121), -INT8_C( 121), -INT8_C( 121), -INT8_C( 121), -INT8_C( 121) } },
    { -INT8_C(  82),
      { -INT8_C(  82), -INT8_C(  82), -INT8_C(  82), -INT8_C(  82), -INT8_C(  82), -INT8_C(  82), -INT8_C(  82), -INT8_C(  82) } },
    { -INT8_C(  27),
      { -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27), -INT8_C(  27) } },
    { -INT8_C(   6),
      { -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6), -INT8_C(   6) } },
    { -INT8_C(  22),
      { -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22) } },
    {  INT8_C( 103),
      {  INT8_C( 103),  INT8_C( 103),  INT8_C( 103),  INT8_C( 103),  INT8_C( 103),  INT8_C( 103),  INT8_C( 103),  INT8_C( 103) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t a = test_vec[i].a;
    simde_int8x8_t r = simde_vdup_n_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8_t a = simde_test_codegen_random_i8();
    simde_int8x8_t r = simde_vdup_n_s8(a);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a;
    int16_t r[4];
  } test_vec[] = {
    {  INT16_C( 14470),
      {  INT16_C( 14470),  INT16_C( 14470),  INT16_C( 14470),  INT16_C( 14470) } },
    { -INT16_C( 25891),
      { -INT16_C( 25891), -INT16_C( 25891), -INT16_C( 25891), -INT16_C( 25891) } },
    { -INT16_C( 19194),
      { -INT16_C( 19194), -INT16_C( 19194), -INT16_C( 19194), -INT16_C( 19194) } },
    {  INT16_C( 23205),
      {  INT16_C( 23205),  INT16_C( 23205),  INT16_C( 23205),  INT16_C( 23205) } },
    { -INT16_C(  2042),
      { -INT16_C(  2042), -INT16_C(  2042), -INT16_C(  2042), -INT16_C(  2042) } },
    {  INT16_C( 18383),
      {  INT16_C( 18383),  INT16_C( 18383),  INT16_C( 18383),  INT16_C( 18383) } },
    {  INT16_C( 31162),
      {  INT16_C( 31162),  INT16_C( 31162),  INT16_C( 31162),  INT16_C( 31162) } },
    {  INT16_C( 13153),
      {  INT16_C( 13153),  INT16_C( 13153),  INT16_C( 13153),  INT16_C( 13153) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    simde_int16x4_t r = simde_vdup_n_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16_t a = simde_test_codegen_random_i16();
    simde_int16x4_t r = simde_vdup_n_s16(a);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a;
    int32_t r[2];
  } test_vec[] = {
    { -INT32_C(  1024619355),
      { -INT32_C(  1024619355), -INT32_C(  1024619355) } },
    { -INT32_C(  1215280205),
      { -INT32_C(  1215280205), -INT32_C(  1215280205) } },
    {  INT32_C(  1111759973),
      {  INT32_C(  1111759973),  INT32_C(  1111759973) } },
    { -INT32_C(  1199775095),
      { -INT32_C(  1199775095), -INT32_C(  1199775095) } },
    {  INT32_C(   633784935),
      {  INT32_C(   633784935),  INT32_C(   633784935) } },
    { -INT32_C(  1048329552),
      { -INT32_C(  1048329552), -INT32_C(  1048329552) } },
    { -INT32_C(  1215802644),
      { -INT32_C(  1215802644), -INT32_C(  1215802644) } },
    {  INT32_C(   357141359),
      {  INT32_C(   357141359),  INT32_C(   357141359) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    simde_int32x2_t r = simde_vdup_n_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32_t a = simde_test_codegen_random_i32();
    simde_int32x2_t r = simde_vdup_n_s32(a);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a;
    int64_t r[1];
  } test_vec[] = {
    { -INT64_C( 5115005979396968606),
      { -INT64_C( 5115005979396968606) } },
    {  INT64_C( 7983384083745204187),
      {  INT64_C( 7983384083745204187) } },
    { -INT64_C( 1545395142558030869),
      { -INT64_C( 1545395142558030869) } },
    { -INT64_C( 8687466611181760880),
      { -INT64_C( 8687466611181760880) } },
    {  INT64_C( 3332119824696179291),
      {  INT64_C( 3332119824696179291) } },
    { -INT64_C(  365712898301861384),
      { -INT64_C(  365712898301861384) } },
    {  INT64_C( 6545642081325163422),
      {  INT64_C( 6545642081325163422) } },
    { -INT64_C( 8195148122753775720),
      { -INT64_C( 8195148122753775720) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t a = test_vec[i].a;
    simde_int64x1_t r = simde_vdup_n_s64(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64_t a = simde_test_codegen_random_i64();
    simde_int64x1_t r = simde_vdup_n_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a;
    uint8_t r[16];
  } test_vec[] = {
    { UINT8_C( 70),
      { UINT8_C( 70), UINT8_C( 70), UINT8_C( 70), UINT8_C( 70), UINT8_C( 70), UINT8_C( 70), UINT8_C( 70), UINT8_C( 70) } },
    { UINT8_C( 47),
      { UINT8_C( 47), UINT8_C( 47), UINT8_C( 47), UINT8_C( 47), UINT8_C( 47), UINT8_C( 47), UINT8_C( 47), UINT8_C( 47) } },
    { UINT8_C(150),
      { UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150) } },
    { UINT8_C( 51),
      { UINT8_C( 51), UINT8_C( 51), UINT8_C( 51), UINT8_C( 51), UINT8_C( 51), UINT8_C( 51), UINT8_C( 51), UINT8_C( 51) } },
    { UINT8_C(213),
      { UINT8_C(213), UINT8_C(213), UINT8_C(213), UINT8_C(213), UINT8_C(213), UINT8_C(213), UINT8_C(213), UINT8_C(213) } },
    { UINT8_C(253),
      { UINT8_C(253), UINT8_C(253), UINT8_C(253), UINT8_C(253), UINT8_C(253), UINT8_C(253), UINT8_C(253), UINT8_C(253) } },
    { UINT8_C( 68),
      { UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68) } },
    { UINT8_C( 71),
      { UINT8_C( 71), UINT8_C( 71), UINT8_C( 71), UINT8_C( 71), UINT8_C( 71), UINT8_C( 71), UINT8_C( 71), UINT8_C( 71) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t a = test_vec[i].a;
    simde_uint8x8_t r = simde_vdup_n_u8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8_t a = simde_test_codegen_random_u8();
    simde_uint8x16_t r = simde_vdup_n_u8(a);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a;
    uint16_t r[4];
  } test_vec[] = {
    { UINT16_C(51628),
      { UINT16_C(51628), UINT16_C(51628), UINT16_C(51628), UINT16_C(51628) } },
    { UINT16_C(19470),
      { UINT16_C(19470), UINT16_C(19470), UINT16_C(19470), UINT16_C(19470) } },
    { UINT16_C(18389),
      { UINT16_C(18389), UINT16_C(18389), UINT16_C(18389), UINT16_C(18389) } },
    { UINT16_C(  116),
      { UINT16_C(  116), UINT16_C(  116), UINT16_C(  116), UINT16_C(  116) } },
    { UINT16_C(44704),
      { UINT16_C(44704), UINT16_C(44704), UINT16_C(44704), UINT16_C(44704) } },
    { UINT16_C(37574),
      { UINT16_C(37574), UINT16_C(37574), UINT16_C(37574), UINT16_C(37574) } },
    { UINT16_C(18426),
      { UINT16_C(18426), UINT16_C(18426), UINT16_C(18426), UINT16_C(18426) } },
    { UINT16_C(63921),
      { UINT16_C(63921), UINT16_C(63921), UINT16_C(63921), UINT16_C(63921) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t a = test_vec[i].a;
    simde_uint16x4_t r = simde_vdup_n_u16(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16_t a = simde_test_codegen_random_u16();
    simde_uint16x4_t r = simde_vdup_n_u16(a);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a;
    uint32_t r[2];
  } test_vec[] = {
    { UINT32_C(3794667895),
      { UINT32_C(3794667895), UINT32_C(3794667895) } },
    { UINT32_C(1726335693),
      { UINT32_C(1726335693), UINT32_C(1726335693) } },
    { UINT32_C(2983766046),
      { UINT32_C(2983766046), UINT32_C(2983766046) } },
    { UINT32_C(3005127747),
      { UINT32_C(3005127747), UINT32_C(3005127747) } },
    { UINT32_C(2102894648),
      { UINT32_C(2102894648), UINT32_C(2102894648) } },
    { UINT32_C(3216998892),
      { UINT32_C(3216998892), UINT32_C(3216998892) } },
    { UINT32_C( 828608890),
      { UINT32_C( 828608890), UINT32_C( 828608890) } },
    { UINT32_C( 884825021),
      { UINT32_C( 884825021), UINT32_C( 884825021) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    simde_uint32x2_t r = simde_vdup_n_u32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint32x2_t r = simde_vdup_n_u32(a);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a;
    uint64_t r[1];
  } test_vec[] = {
    { UINT64_C(13339791427449258007),
      { UINT64_C(13339791427449258007) } },
    { UINT64_C( 7070510947546969075),
      { UINT64_C( 7070510947546969075) } },
    { UINT64_C( 8999127261392807922),
      { UINT64_C( 8999127261392807922) } },
    { UINT64_C(12929560324791906007),
      { UINT64_C(12929560324791906007) } },
    { UINT64_C(14006218822742530566),
      { UINT64_C(14006218822742530566) } },
    { UINT64_C(16134641465453407304),
      { UINT64_C(16134641465453407304) } },
    { UINT64_C(17146709105050043369),
      { UINT64_C(17146709105050043369) } },
    { UINT64_C( 3988202661257292296),
      { UINT64_C( 3988202661257292296) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t a = test_vec[i].a;
    simde_uint64x1_t r = simde_vdup_n_u64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64_t a = simde_test_codegen_random_u64();
    simde_uint64x1_t r = simde_vdup_n_u64(a);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_f16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      simde_float16_t a;
      simde_float16_t r[8];
    } test_vec[] = {
      { SIMDE_FLOAT16_VALUE(   189.12),
      { SIMDE_FLOAT16_VALUE(   189.12), SIMDE_FLOAT16_VALUE(   189.12), SIMDE_FLOAT16_VALUE(   189.12), SIMDE_FLOAT16_VALUE(   189.12),
        SIMDE_FLOAT16_VALUE(   189.12), SIMDE_FLOAT16_VALUE(   189.12), SIMDE_FLOAT16_VALUE(   189.12), SIMDE_FLOAT16_VALUE(   189.12) } },
    { SIMDE_FLOAT16_VALUE(  -419.50),
      { SIMDE_FLOAT16_VALUE(  -419.50), SIMDE_FLOAT16_VALUE(  -419.50), SIMDE_FLOAT16_VALUE(  -419.50), SIMDE_FLOAT16_VALUE(  -419.50),
        SIMDE_FLOAT16_VALUE(  -419.50), SIMDE_FLOAT16_VALUE(  -419.50), SIMDE_FLOAT16_VALUE(  -419.50), SIMDE_FLOAT16_VALUE(  -419.50) } },
    { SIMDE_FLOAT16_VALUE(   560.50),
      { SIMDE_FLOAT16_VALUE(   560.50), SIMDE_FLOAT16_VALUE(   560.50), SIMDE_FLOAT16_VALUE(   560.50), SIMDE_FLOAT16_VALUE(   560.50),
        SIMDE_FLOAT16_VALUE(   560.50), SIMDE_FLOAT16_VALUE(   560.50), SIMDE_FLOAT16_VALUE(   560.50), SIMDE_FLOAT16_VALUE(   560.50) } },
    { SIMDE_FLOAT16_VALUE(   578.00),
      { SIMDE_FLOAT16_VALUE(   578.00), SIMDE_FLOAT16_VALUE(   578.00), SIMDE_FLOAT16_VALUE(   578.00), SIMDE_FLOAT16_VALUE(   578.00),
        SIMDE_FLOAT16_VALUE(   578.00), SIMDE_FLOAT16_VALUE(   578.00), SIMDE_FLOAT16_VALUE(   578.00), SIMDE_FLOAT16_VALUE(   578.00) } },
    { SIMDE_FLOAT16_VALUE(   722.50),
      { SIMDE_FLOAT16_VALUE(   722.50), SIMDE_FLOAT16_VALUE(   722.50), SIMDE_FLOAT16_VALUE(   722.50), SIMDE_FLOAT16_VALUE(   722.50),
        SIMDE_FLOAT16_VALUE(   722.50), SIMDE_FLOAT16_VALUE(   722.50), SIMDE_FLOAT16_VALUE(   722.50), SIMDE_FLOAT16_VALUE(   722.50) } },
    { SIMDE_FLOAT16_VALUE(   298.00),
      { SIMDE_FLOAT16_VALUE(   298.00), SIMDE_FLOAT16_VALUE(   298.00), SIMDE_FLOAT16_VALUE(   298.00), SIMDE_FLOAT16_VALUE(   298.00),
        SIMDE_FLOAT16_VALUE(   298.00), SIMDE_FLOAT16_VALUE(   298.00), SIMDE_FLOAT16_VALUE(   298.00), SIMDE_FLOAT16_VALUE(   298.00) } },
    { SIMDE_FLOAT16_VALUE(  -351.50),
      { SIMDE_FLOAT16_VALUE(  -351.50), SIMDE_FLOAT16_VALUE(  -351.50), SIMDE_FLOAT16_VALUE(  -351.50), SIMDE_FLOAT16_VALUE(  -351.50),
        SIMDE_FLOAT16_VALUE(  -351.50), SIMDE_FLOAT16_VALUE(  -351.50), SIMDE_FLOAT16_VALUE(  -351.50), SIMDE_FLOAT16_VALUE(  -351.50) } },
    { SIMDE_FLOAT16_VALUE(   245.62),
      { SIMDE_FLOAT16_VALUE(   245.62), SIMDE_FLOAT16_VALUE(   245.62), SIMDE_FLOAT16_VALUE(   245.62), SIMDE_FLOAT16_VALUE(   245.62),
        SIMDE_FLOAT16_VALUE(   245.62), SIMDE_FLOAT16_VALUE(   245.62), SIMDE_FLOAT16_VALUE(   245.62), SIMDE_FLOAT16_VALUE(   245.62) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_float16_t a;
      simde_float16x8_t r;

      a = test_vec[i].a;
      r = simde_vdupq_n_f16(a);

      simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float16_t a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
      simde_float16x8_t r = simde_vdupq_n_f16(a);

      simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vdupq_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a;
    simde_float32 r[4];
  } test_vec[] = {
    { SIMDE_FLOAT32_C(  -253.37),
      { SIMDE_FLOAT32_C(  -253.37), SIMDE_FLOAT32_C(  -253.37), SIMDE_FLOAT32_C(  -253.37), SIMDE_FLOAT32_C(  -253.37) } },
    { SIMDE_FLOAT32_C(   678.81),
      { SIMDE_FLOAT32_C(   678.81), SIMDE_FLOAT32_C(   678.81), SIMDE_FLOAT32_C(   678.81), SIMDE_FLOAT32_C(   678.81) } },
    { SIMDE_FLOAT32_C(   287.86),
      { SIMDE_FLOAT32_C(   287.86), SIMDE_FLOAT32_C(   287.86), SIMDE_FLOAT32_C(   287.86), SIMDE_FLOAT32_C(   287.86) } },
    { SIMDE_FLOAT32_C(   -23.55),
      { SIMDE_FLOAT32_C(   -23.55), SIMDE_FLOAT32_C(   -23.55), SIMDE_FLOAT32_C(   -23.55), SIMDE_FLOAT32_C(   -23.55) } },
    { SIMDE_FLOAT32_C(   255.34),
      { SIMDE_FLOAT32_C(   255.34), SIMDE_FLOAT32_C(   255.34), SIMDE_FLOAT32_C(   255.34), SIMDE_FLOAT32_C(   255.34) } },
    { SIMDE_FLOAT32_C(  -331.64),
      { SIMDE_FLOAT32_C(  -331.64), SIMDE_FLOAT32_C(  -331.64), SIMDE_FLOAT32_C(  -331.64), SIMDE_FLOAT32_C(  -331.64) } },
    { SIMDE_FLOAT32_C(   507.10),
      { SIMDE_FLOAT32_C(   507.10), SIMDE_FLOAT32_C(   507.10), SIMDE_FLOAT32_C(   507.10), SIMDE_FLOAT32_C(   507.10) } },
    { SIMDE_FLOAT32_C(   555.78),
      { SIMDE_FLOAT32_C(   555.78), SIMDE_FLOAT32_C(   555.78), SIMDE_FLOAT32_C(   555.78), SIMDE_FLOAT32_C(   555.78) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    simde_float32x4_t r = simde_vdupq_n_f32(a);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vdupq_n_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a;
    simde_float64 r[2];
  } test_vec[] = {
    { SIMDE_FLOAT64_C(  -118.41),
      { SIMDE_FLOAT64_C(  -118.41), SIMDE_FLOAT64_C(  -118.41) } },
    { SIMDE_FLOAT64_C(  -822.94),
      { SIMDE_FLOAT64_C(  -822.94), SIMDE_FLOAT64_C(  -822.94) } },
    { SIMDE_FLOAT64_C(  -264.09),
      { SIMDE_FLOAT64_C(  -264.09), SIMDE_FLOAT64_C(  -264.09) } },
    { SIMDE_FLOAT64_C(  -893.94),
      { SIMDE_FLOAT64_C(  -893.94), SIMDE_FLOAT64_C(  -893.94) } },
    { SIMDE_FLOAT64_C(   267.56),
      { SIMDE_FLOAT64_C(   267.56), SIMDE_FLOAT64_C(   267.56) } },
    { SIMDE_FLOAT64_C(  -972.95),
      { SIMDE_FLOAT64_C(  -972.95), SIMDE_FLOAT64_C(  -972.95) } },
    { SIMDE_FLOAT64_C(  -132.42),
      { SIMDE_FLOAT64_C(  -132.42), SIMDE_FLOAT64_C(  -132.42) } },
    { SIMDE_FLOAT64_C(   -34.49),
      { SIMDE_FLOAT64_C(   -34.49), SIMDE_FLOAT64_C(   -34.49) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    simde_float64x2_t r = simde_vdupq_n_f64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r = simde_vdupq_n_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a;
    int8_t r[16];
  } test_vec[] = {
    { -INT8_C(  88),
      { -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88),
        -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88), -INT8_C(  88) } },
    {  INT8_C(  76),
      {  INT8_C(  76),  INT8_C(  76),  INT8_C(  76),  INT8_C(  76),  INT8_C(  76),  INT8_C(  76),  INT8_C(  76),  INT8_C(  76),
         INT8_C(  76),  INT8_C(  76),  INT8_C(  76),  INT8_C(  76),  INT8_C(  76),  INT8_C(  76),  INT8_C(  76),  INT8_C(  76) } },
    { -INT8_C(  22),
      { -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22),
        -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22), -INT8_C(  22) } },
    { -INT8_C(  37),
      { -INT8_C(  37), -INT8_C(  37), -INT8_C(  37), -INT8_C(  37), -INT8_C(  37), -INT8_C(  37), -INT8_C(  37), -INT8_C(  37),
        -INT8_C(  37), -INT8_C(  37), -INT8_C(  37), -INT8_C(  37), -INT8_C(  37), -INT8_C(  37), -INT8_C(  37), -INT8_C(  37) } },
    { -INT8_C(  58),
      { -INT8_C(  58), -INT8_C(  58), -INT8_C(  58), -INT8_C(  58), -INT8_C(  58), -INT8_C(  58), -INT8_C(  58), -INT8_C(  58),
        -INT8_C(  58), -INT8_C(  58), -INT8_C(  58), -INT8_C(  58), -INT8_C(  58), -INT8_C(  58), -INT8_C(  58), -INT8_C(  58) } },
    {  INT8_C(   5),
      {  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),
         INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5),  INT8_C(   5) } },
    {  INT8_C(  39),
      {  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),
         INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39),  INT8_C(  39) } },
    { -INT8_C(  90),
      { -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90),
        -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90), -INT8_C(  90) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t a = test_vec[i].a;
    simde_int8x16_t r = simde_vdupq_n_s8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8_t a = simde_test_codegen_random_i8();
    simde_int8x16_t r = simde_vdupq_n_s8(a);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a;
    int16_t r[8];
  } test_vec[] = {
    { -INT16_C( 12855),
      { -INT16_C( 12855), -INT16_C( 12855), -INT16_C( 12855), -INT16_C( 12855), -INT16_C( 12855), -INT16_C( 12855), -INT16_C( 12855), -INT16_C( 12855) } },
    { -INT16_C(  7137),
      { -INT16_C(  7137), -INT16_C(  7137), -INT16_C(  7137), -INT16_C(  7137), -INT16_C(  7137), -INT16_C(  7137), -INT16_C(  7137), -INT16_C(  7137) } },
    { -INT16_C(  1466),
      { -INT16_C(  1466), -INT16_C(  1466), -INT16_C(  1466), -INT16_C(  1466), -INT16_C(  1466), -INT16_C(  1466), -INT16_C(  1466), -INT16_C(  1466) } },
    { -INT16_C( 32577),
      { -INT16_C( 32577), -INT16_C( 32577), -INT16_C( 32577), -INT16_C( 32577), -INT16_C( 32577), -INT16_C( 32577), -INT16_C( 32577), -INT16_C( 32577) } },
    {  INT16_C( 31960),
      {  INT16_C( 31960),  INT16_C( 31960),  INT16_C( 31960),  INT16_C( 31960),  INT16_C( 31960),  INT16_C( 31960),  INT16_C( 31960),  INT16_C( 31960) } },
    { -INT16_C( 27505),
      { -INT16_C( 27505), -INT16_C( 27505), -INT16_C( 27505), -INT16_C( 27505), -INT16_C( 27505), -INT16_C( 27505), -INT16_C( 27505), -INT16_C( 27505) } },
    { -INT16_C( 27913),
      { -INT16_C( 27913), -INT16_C( 27913), -INT16_C( 27913), -INT16_C( 27913), -INT16_C( 27913), -INT16_C( 27913), -INT16_C( 27913), -INT16_C( 27913) } },
    { -INT16_C(  2168),
      { -INT16_C(  2168), -INT16_C(  2168), -INT16_C(  2168), -INT16_C(  2168), -INT16_C(  2168), -INT16_C(  2168), -INT16_C(  2168), -INT16_C(  2168) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    simde_int16x8_t r = simde_vdupq_n_s16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16_t a = simde_test_codegen_random_i16();
    simde_int16x8_t r = simde_vdupq_n_s16(a);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a;
    int32_t r[4];
  } test_vec[] = {
    {  INT32_C(  1498606215),
      {  INT32_C(  1498606215),  INT32_C(  1498606215),  INT32_C(  1498606215),  INT32_C(  1498606215) } },
    {  INT32_C(   859053161),
      {  INT32_C(   859053161),  INT32_C(   859053161),  INT32_C(   859053161),  INT32_C(   859053161) } },
    { -INT32_C(  1117116324),
      { -INT32_C(  1117116324), -INT32_C(  1117116324), -INT32_C(  1117116324), -INT32_C(  1117116324) } },
    {  INT32_C(   637922202),
      {  INT32_C(   637922202),  INT32_C(   637922202),  INT32_C(   637922202),  INT32_C(   637922202) } },
    {  INT32_C(  1777200653),
      {  INT32_C(  1777200653),  INT32_C(  1777200653),  INT32_C(  1777200653),  INT32_C(  1777200653) } },
    {  INT32_C(  1736753390),
      {  INT32_C(  1736753390),  INT32_C(  1736753390),  INT32_C(  1736753390),  INT32_C(  1736753390) } },
    {  INT32_C(  1743553983),
      {  INT32_C(  1743553983),  INT32_C(  1743553983),  INT32_C(  1743553983),  INT32_C(  1743553983) } },
    {  INT32_C(   833012906),
      {  INT32_C(   833012906),  INT32_C(   833012906),  INT32_C(   833012906),  INT32_C(   833012906) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    simde_int32x4_t r = simde_vdupq_n_s32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32_t a = simde_test_codegen_random_i32();
    simde_int32x4_t r = simde_vdupq_n_s32(a);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a;
    int64_t r[2];
  } test_vec[] = {
    {  INT64_C( 3084521629620139883),
      {  INT64_C( 3084521629620139883),  INT64_C( 3084521629620139883) } },
    { -INT64_C( 3698824787540598387),
      { -INT64_C( 3698824787540598387), -INT64_C( 3698824787540598387) } },
    {  INT64_C( 5697069037127965299),
      {  INT64_C( 5697069037127965299),  INT64_C( 5697069037127965299) } },
    {  INT64_C( 8459596326044522619),
      {  INT64_C( 8459596326044522619),  INT64_C( 8459596326044522619) } },
    { -INT64_C( 2000541241550771459),
      { -INT64_C( 2000541241550771459), -INT64_C( 2000541241550771459) } },
    {  INT64_C(  974893640165390152),
      {  INT64_C(  974893640165390152),  INT64_C(  974893640165390152) } },
    { -INT64_C(  826418811364742626),
      { -INT64_C(  826418811364742626), -INT64_C(  826418811364742626) } },
    {  INT64_C( 2364107377413299280),
      {  INT64_C( 2364107377413299280),  INT64_C( 2364107377413299280) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t a = test_vec[i].a;
    simde_int64x2_t r = simde_vdupq_n_s64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64_t a = simde_test_codegen_random_i64();
    simde_int64x2_t r = simde_vdupq_n_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a;
    uint8_t r[16];
  } test_vec[] = {
    { UINT8_C( 88),
      { UINT8_C( 88), UINT8_C( 88), UINT8_C( 88), UINT8_C( 88), UINT8_C( 88), UINT8_C( 88), UINT8_C( 88), UINT8_C( 88),
        UINT8_C( 88), UINT8_C( 88), UINT8_C( 88), UINT8_C( 88), UINT8_C( 88), UINT8_C( 88), UINT8_C( 88), UINT8_C( 88) } },
    { UINT8_C(137),
      { UINT8_C(137), UINT8_C(137), UINT8_C(137), UINT8_C(137), UINT8_C(137), UINT8_C(137), UINT8_C(137), UINT8_C(137),
        UINT8_C(137), UINT8_C(137), UINT8_C(137), UINT8_C(137), UINT8_C(137), UINT8_C(137), UINT8_C(137), UINT8_C(137) } },
    { UINT8_C( 33),
      { UINT8_C( 33), UINT8_C( 33), UINT8_C( 33), UINT8_C( 33), UINT8_C( 33), UINT8_C( 33), UINT8_C( 33), UINT8_C( 33),
        UINT8_C( 33), UINT8_C( 33), UINT8_C( 33), UINT8_C( 33), UINT8_C( 33), UINT8_C( 33), UINT8_C( 33), UINT8_C( 33) } },
    { UINT8_C(179),
      { UINT8_C(179), UINT8_C(179), UINT8_C(179), UINT8_C(179), UINT8_C(179), UINT8_C(179), UINT8_C(179), UINT8_C(179),
        UINT8_C(179), UINT8_C(179), UINT8_C(179), UINT8_C(179), UINT8_C(179), UINT8_C(179), UINT8_C(179), UINT8_C(179) } },
    { UINT8_C( 68),
      { UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68),
        UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68), UINT8_C( 68) } },
    { UINT8_C(153),
      { UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153),
        UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153), UINT8_C(153) } },
    { UINT8_C(195),
      { UINT8_C(195), UINT8_C(195), UINT8_C(195), UINT8_C(195), UINT8_C(195), UINT8_C(195), UINT8_C(195), UINT8_C(195),
        UINT8_C(195), UINT8_C(195), UINT8_C(195), UINT8_C(195), UINT8_C(195), UINT8_C(195), UINT8_C(195), UINT8_C(195) } },
    { UINT8_C(221),
      { UINT8_C(221), UINT8_C(221), UINT8_C(221), UINT8_C(221), UINT8_C(221), UINT8_C(221), UINT8_C(221), UINT8_C(221),
        UINT8_C(221), UINT8_C(221), UINT8_C(221), UINT8_C(221), UINT8_C(221), UINT8_C(221), UINT8_C(221), UINT8_C(221) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t a = test_vec[i].a;
    simde_uint8x16_t r = simde_vdupq_n_u8(a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8_t a = simde_test_codegen_random_u8();
    simde_uint8x16_t r = simde_vdupq_n_u8(a);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a;
    uint16_t r[8];
  } test_vec[] = {
    { UINT16_C(15077),
      { UINT16_C(15077), UINT16_C(15077), UINT16_C(15077), UINT16_C(15077), UINT16_C(15077), UINT16_C(15077), UINT16_C(15077), UINT16_C(15077) } },
    { UINT16_C(23766),
      { UINT16_C(23766), UINT16_C(23766), UINT16_C(23766), UINT16_C(23766), UINT16_C(23766), UINT16_C(23766), UINT16_C(23766), UINT16_C(23766) } },
    { UINT16_C(62373),
      { UINT16_C(62373), UINT16_C(62373), UINT16_C(62373), UINT16_C(62373), UINT16_C(62373), UINT16_C(62373), UINT16_C(62373), UINT16_C(62373) } },
    { UINT16_C( 9434),
      { UINT16_C( 9434), UINT16_C( 9434), UINT16_C( 9434), UINT16_C( 9434), UINT16_C( 9434), UINT16_C( 9434), UINT16_C( 9434), UINT16_C( 9434) } },
    { UINT16_C(13770),
      { UINT16_C(13770), UINT16_C(13770), UINT16_C(13770), UINT16_C(13770), UINT16_C(13770), UINT16_C(13770), UINT16_C(13770), UINT16_C(13770) } },
    { UINT16_C(60300),
      { UINT16_C(60300), UINT16_C(60300), UINT16_C(60300), UINT16_C(60300), UINT16_C(60300), UINT16_C(60300), UINT16_C(60300), UINT16_C(60300) } },
    { UINT16_C( 9690),
      { UINT16_C( 9690), UINT16_C( 9690), UINT16_C( 9690), UINT16_C( 9690), UINT16_C( 9690), UINT16_C( 9690), UINT16_C( 9690), UINT16_C( 9690) } },
    { UINT16_C( 2267),
      { UINT16_C( 2267), UINT16_C( 2267), UINT16_C( 2267), UINT16_C( 2267), UINT16_C( 2267), UINT16_C( 2267), UINT16_C( 2267), UINT16_C( 2267) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t a = test_vec[i].a;
    simde_uint16x8_t r = simde_vdupq_n_u16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16_t a = simde_test_codegen_random_u16();
    simde_uint16x8_t r = simde_vdupq_n_u16(a);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a;
    uint32_t r[4];
  } test_vec[] = {
    { UINT32_C( 871626588),
      { UINT32_C( 871626588), UINT32_C( 871626588), UINT32_C( 871626588), UINT32_C( 871626588) } },
    { UINT32_C(3690858582),
      { UINT32_C(3690858582), UINT32_C(3690858582), UINT32_C(3690858582), UINT32_C(3690858582) } },
    { UINT32_C(2630828423),
      { UINT32_C(2630828423), UINT32_C(2630828423), UINT32_C(2630828423), UINT32_C(2630828423) } },
    { UINT32_C(3967771416),
      { UINT32_C(3967771416), UINT32_C(3967771416), UINT32_C(3967771416), UINT32_C(3967771416) } },
    { UINT32_C(1205362100),
      { UINT32_C(1205362100), UINT32_C(1205362100), UINT32_C(1205362100), UINT32_C(1205362100) } },
    { UINT32_C(1010872729),
      { UINT32_C(1010872729), UINT32_C(1010872729), UINT32_C(1010872729), UINT32_C(1010872729) } },
    { UINT32_C(3921730572),
      { UINT32_C(3921730572), UINT32_C(3921730572), UINT32_C(3921730572), UINT32_C(3921730572) } },
    { UINT32_C(2097348897),
      { UINT32_C(2097348897), UINT32_C(2097348897), UINT32_C(2097348897), UINT32_C(2097348897) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    simde_uint32x4_t r = simde_vdupq_n_u32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint32x4_t r = simde_vdupq_n_u32(a);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a;
    uint64_t r[2];
  } test_vec[] = {
    { UINT64_C( 9197789892391848940),
      { UINT64_C( 9197789892391848940), UINT64_C( 9197789892391848940) } },
    { UINT64_C( 4409839811323935032),
      { UINT64_C( 4409839811323935032), UINT64_C( 4409839811323935032) } },
    { UINT64_C(  685931058055602176),
      { UINT64_C(  685931058055602176), UINT64_C(  685931058055602176) } },
    { UINT64_C(12677749240105368630),
      { UINT64_C(12677749240105368630), UINT64_C(12677749240105368630) } },
    { UINT64_C(17861042748132860468),
      { UINT64_C(17861042748132860468), UINT64_C(17861042748132860468) } },
    { UINT64_C( 1950859198369969636),
      { UINT64_C( 1950859198369969636), UINT64_C( 1950859198369969636) } },
    { UINT64_C(  102279644159074744),
      { UINT64_C(  102279644159074744), UINT64_C(  102279644159074744) } },
    { UINT64_C(18324753029341470939),
      { UINT64_C(18324753029341470939), UINT64_C(18324753029341470939) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t a = test_vec[i].a;
    simde_uint64x2_t r = simde_vdupq_n_u64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64_t a = simde_test_codegen_random_u64();
    simde_uint64x2_t r = simde_vdupq_n_u64(a);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a;
    simde_poly8_t r[8];
  } test_vec[] = {
    {    SIMDE_POLY8_C(   148),
      {  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   148),
         SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   148),  SIMDE_POLY8_C(   148) } },
    {    SIMDE_POLY8_C(    32),
      {  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(    32),
         SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(    32),  SIMDE_POLY8_C(    32) } },
    {    SIMDE_POLY8_C(    97),
      {  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(    97),
         SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(    97),  SIMDE_POLY8_C(    97) } },
    {    SIMDE_POLY8_C(   125),
      {  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   125),
         SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   125),  SIMDE_POLY8_C(   125) } },
    {    SIMDE_POLY8_C(    79),
      {  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(    79),
         SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(    79),  SIMDE_POLY8_C(    79) } },
    {    SIMDE_POLY8_C(   100),
      {  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   100),
         SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   100),  SIMDE_POLY8_C(   100) } },
    {    SIMDE_POLY8_C(    72),
      {  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    72),
         SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    72),  SIMDE_POLY8_C(    72) } },
    {    SIMDE_POLY8_C(    47),
      {  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(    47),
         SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(    47),  SIMDE_POLY8_C(    47) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8_t a = test_vec[i].a;
    simde_poly8x8_t r = simde_vdup_n_p8(a);

    simde_test_arm_neon_assert_equal_p8x8(r, simde_vld1_p8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8_t a = simde_test_codegen_random_p8();
    simde_poly8x8_t r = simde_vdup_n_p8(a);

    simde_test_codegen_write_p8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a;
    simde_poly16_t r[4];
  } test_vec[] = {
    {    SIMDE_POLY16_C(   64166),
      {  SIMDE_POLY16_C(   64166),  SIMDE_POLY16_C(   64166),  SIMDE_POLY16_C(   64166),  SIMDE_POLY16_C(   64166) } },
    {    SIMDE_POLY16_C(   50491),
      {  SIMDE_POLY16_C(   50491),  SIMDE_POLY16_C(   50491),  SIMDE_POLY16_C(   50491),  SIMDE_POLY16_C(   50491) } },
    {    SIMDE_POLY16_C(   17474),
      {  SIMDE_POLY16_C(   17474),  SIMDE_POLY16_C(   17474),  SIMDE_POLY16_C(   17474),  SIMDE_POLY16_C(   17474) } },
    {    SIMDE_POLY16_C(   19200),
      {  SIMDE_POLY16_C(   19200),  SIMDE_POLY16_C(   19200),  SIMDE_POLY16_C(   19200),  SIMDE_POLY16_C(   19200) } },
    {    SIMDE_POLY16_C(   32387),
      {  SIMDE_POLY16_C(   32387),  SIMDE_POLY16_C(   32387),  SIMDE_POLY16_C(   32387),  SIMDE_POLY16_C(   32387) } },
    {    SIMDE_POLY16_C(    6647),
      {  SIMDE_POLY16_C(    6647),  SIMDE_POLY16_C(    6647),  SIMDE_POLY16_C(    6647),  SIMDE_POLY16_C(    6647) } },
    {    SIMDE_POLY16_C(    7232),
      {  SIMDE_POLY16_C(    7232),  SIMDE_POLY16_C(    7232),  SIMDE_POLY16_C(    7232),  SIMDE_POLY16_C(    7232) } },
    {    SIMDE_POLY16_C(   57650),
      {  SIMDE_POLY16_C(   57650),  SIMDE_POLY16_C(   57650),  SIMDE_POLY16_C(   57650),  SIMDE_POLY16_C(   57650) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16_t a = test_vec[i].a;
    simde_poly16x4_t r = simde_vdup_n_p16(a);

    simde_test_arm_neon_assert_equal_p16x4(r, simde_vld1_p16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16_t a = simde_test_codegen_random_p16();
    simde_poly16x4_t r = simde_vdup_n_p16(a);

    simde_test_codegen_write_p16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly64_t a;
    simde_poly64_t r[1];
  } test_vec[] = {
    {    SIMDE_POLY64_C(11166859701331232768),
      {  SIMDE_POLY64_C(11166859701331232768) } },
    {    SIMDE_POLY64_C(10785164930637903872),
      {  SIMDE_POLY64_C(10785164930637903872) } },
    {    SIMDE_POLY64_C(15134172690085824512),
      {  SIMDE_POLY64_C(15134172690085824512) } },
    {    SIMDE_POLY64_C( 9719404229015875584),
      {  SIMDE_POLY64_C( 9719404229015875584) } },
    {    SIMDE_POLY64_C( 6108431914564907008),
      {  SIMDE_POLY64_C( 6108431914564907008) } },
    {    SIMDE_POLY64_C(16126763516062392320),
      {  SIMDE_POLY64_C(16126763516062392320) } },
    {    SIMDE_POLY64_C(10093142159428458496),
      {  SIMDE_POLY64_C(10093142159428458496) } },
    {    SIMDE_POLY64_C(13458542795151548416),
      {  SIMDE_POLY64_C(13458542795151548416) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64_t a = test_vec[i].a;
    simde_poly64x1_t r = simde_vdup_n_p64(a);

    simde_test_arm_neon_assert_equal_p64x1(r, simde_vld1_p64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64_t a = simde_test_codegen_random_p64();
    simde_poly64x1_t r = simde_vdup_n_p64(a);

    simde_test_codegen_write_p64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a;
    simde_poly8_t r[16];
  } test_vec[] = {
    {    SIMDE_POLY8_C(   171),
      {  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),
         SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),
         SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),
         SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171),  SIMDE_POLY8_C(   171) } },
    {    SIMDE_POLY8_C(   132),
      {  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),
         SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),
         SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),
         SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132),  SIMDE_POLY8_C(   132) } },
    {    SIMDE_POLY8_C(     0),
      {  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),
         SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),
         SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),
         SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0),  SIMDE_POLY8_C(     0) } },
    {    SIMDE_POLY8_C(   118),
      {  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),
         SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),
         SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),
         SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118),  SIMDE_POLY8_C(   118) } },
    {    SIMDE_POLY8_C(   225),
      {  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),
         SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),
         SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),
         SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225),  SIMDE_POLY8_C(   225) } },
    {    SIMDE_POLY8_C(     8),
      {  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),
         SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),
         SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),
         SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8),  SIMDE_POLY8_C(     8) } },
    {    SIMDE_POLY8_C(   218),
      {  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),
         SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),
         SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),
         SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218),  SIMDE_POLY8_C(   218) } },
    {    SIMDE_POLY8_C(    80),
      {  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),
         SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),
         SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),
         SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80),  SIMDE_POLY8_C(    80) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8_t a = test_vec[i].a;
    simde_poly8x16_t r = simde_vdupq_n_p8(a);

    simde_test_arm_neon_assert_equal_p8x16(r, simde_vld1q_p8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8_t a = simde_test_codegen_random_p8();
    simde_poly8x16_t r = simde_vdupq_n_p8(a);

    simde_test_codegen_write_p8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a;
    simde_poly16_t r[8];
  } test_vec[] = {
    {    SIMDE_POLY16_C(   23898),
      {  SIMDE_POLY16_C(   23898),  SIMDE_POLY16_C(   23898),  SIMDE_POLY16_C(   23898),  SIMDE_POLY16_C(   23898),
         SIMDE_POLY16_C(   23898),  SIMDE_POLY16_C(   23898),  SIMDE_POLY16_C(   23898),  SIMDE_POLY16_C(   23898) } },
    {    SIMDE_POLY16_C(   20959),
      {  SIMDE_POLY16_C(   20959),  SIMDE_POLY16_C(   20959),  SIMDE_POLY16_C(   20959),  SIMDE_POLY16_C(   20959),
         SIMDE_POLY16_C(   20959),  SIMDE_POLY16_C(   20959),  SIMDE_POLY16_C(   20959),  SIMDE_POLY16_C(   20959) } },
    {    SIMDE_POLY16_C(   60768),
      {  SIMDE_POLY16_C(   60768),  SIMDE_POLY16_C(   60768),  SIMDE_POLY16_C(   60768),  SIMDE_POLY16_C(   60768),
         SIMDE_POLY16_C(   60768),  SIMDE_POLY16_C(   60768),  SIMDE_POLY16_C(   60768),  SIMDE_POLY16_C(   60768) } },
    {    SIMDE_POLY16_C(   46777),
      {  SIMDE_POLY16_C(   46777),  SIMDE_POLY16_C(   46777),  SIMDE_POLY16_C(   46777),  SIMDE_POLY16_C(   46777),
         SIMDE_POLY16_C(   46777),  SIMDE_POLY16_C(   46777),  SIMDE_POLY16_C(   46777),  SIMDE_POLY16_C(   46777) } },
    {    SIMDE_POLY16_C(   37871),
      {  SIMDE_POLY16_C(   37871),  SIMDE_POLY16_C(   37871),  SIMDE_POLY16_C(   37871),  SIMDE_POLY16_C(   37871),
         SIMDE_POLY16_C(   37871),  SIMDE_POLY16_C(   37871),  SIMDE_POLY16_C(   37871),  SIMDE_POLY16_C(   37871) } },
    {    SIMDE_POLY16_C(   36660),
      {  SIMDE_POLY16_C(   36660),  SIMDE_POLY16_C(   36660),  SIMDE_POLY16_C(   36660),  SIMDE_POLY16_C(   36660),
         SIMDE_POLY16_C(   36660),  SIMDE_POLY16_C(   36660),  SIMDE_POLY16_C(   36660),  SIMDE_POLY16_C(   36660) } },
    {    SIMDE_POLY16_C(   11354),
      {  SIMDE_POLY16_C(   11354),  SIMDE_POLY16_C(   11354),  SIMDE_POLY16_C(   11354),  SIMDE_POLY16_C(   11354),
         SIMDE_POLY16_C(   11354),  SIMDE_POLY16_C(   11354),  SIMDE_POLY16_C(   11354),  SIMDE_POLY16_C(   11354) } },
    {    SIMDE_POLY16_C(   23646),
      {  SIMDE_POLY16_C(   23646),  SIMDE_POLY16_C(   23646),  SIMDE_POLY16_C(   23646),  SIMDE_POLY16_C(   23646),
         SIMDE_POLY16_C(   23646),  SIMDE_POLY16_C(   23646),  SIMDE_POLY16_C(   23646),  SIMDE_POLY16_C(   23646) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16_t a = test_vec[i].a;
    simde_poly16x8_t r = simde_vdupq_n_p16(a);

    simde_test_arm_neon_assert_equal_p16x8(r, simde_vld1q_p16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16_t a = simde_test_codegen_random_p16();
    simde_poly16x8_t r = simde_vdupq_n_p16(a);

    simde_test_codegen_write_p16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdupq_n_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly64_t a;
    simde_poly64_t r[2];
  } test_vec[] = {
    {    SIMDE_POLY64_C( 5435207601179970560),
      {  SIMDE_POLY64_C( 5435207601179970560),  SIMDE_POLY64_C( 5435207601179970560) } },
    {    SIMDE_POLY64_C(  972293002970635136),
      {  SIMDE_POLY64_C(  972293002970635136),  SIMDE_POLY64_C(  972293002970635136) } },
    {    SIMDE_POLY64_C( 7729885915794750464),
      {  SIMDE_POLY64_C( 7729885915794750464),  SIMDE_POLY64_C( 7729885915794750464) } },
    {    SIMDE_POLY64_C( 6190860502394286080),
      {  SIMDE_POLY64_C( 6190860502394286080),  SIMDE_POLY64_C( 6190860502394286080) } },
    {    SIMDE_POLY64_C(15193975649710825472),
      {  SIMDE_POLY64_C(15193975649710825472),  SIMDE_POLY64_C(15193975649710825472) } },
    {    SIMDE_POLY64_C(16330932593817991168),
      {  SIMDE_POLY64_C(16330932593817991168),  SIMDE_POLY64_C(16330932593817991168) } },
    {    SIMDE_POLY64_C( 5488729878842632192),
      {  SIMDE_POLY64_C( 5488729878842632192),  SIMDE_POLY64_C( 5488729878842632192) } },
    {    SIMDE_POLY64_C( 3534236993932647936),
      {  SIMDE_POLY64_C( 3534236993932647936),  SIMDE_POLY64_C( 3534236993932647936) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64_t a = test_vec[i].a;
    simde_poly64x2_t r = simde_vdupq_n_p64(a);

    simde_test_arm_neon_assert_equal_p64x2(r, simde_vld1q_p64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64_t a = simde_test_codegen_random_p64();
    simde_poly64x2_t r = simde_vdupq_n_p64(a);

    simde_test_codegen_write_p64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vdup_n_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      SIMDE_ALIGN_TO_16 simde_bfloat16_t a;
      SIMDE_ALIGN_TO_16 simde_bfloat16_t r[4];
    } test_vec[] = {
      { SIMDE_BFLOAT16_VALUE(   688.00),
      { SIMDE_BFLOAT16_VALUE(   688.00), SIMDE_BFLOAT16_VALUE(   688.00), SIMDE_BFLOAT16_VALUE(   688.00), SIMDE_BFLOAT16_VALUE(   688.00) } },
    { SIMDE_BFLOAT16_VALUE(   160.00),
      { SIMDE_BFLOAT16_VALUE(   160.00), SIMDE_BFLOAT16_VALUE(   160.00), SIMDE_BFLOAT16_VALUE(   160.00), SIMDE_BFLOAT16_VALUE(   160.00) } },
    { SIMDE_BFLOAT16_VALUE(    62.75),
      { SIMDE_BFLOAT16_VALUE(    62.75), SIMDE_BFLOAT16_VALUE(    62.75), SIMDE_BFLOAT16_VALUE(    62.75), SIMDE_BFLOAT16_VALUE(    62.75) } },
    { SIMDE_BFLOAT16_VALUE(   182.00),
      { SIMDE_BFLOAT16_VALUE(   182.00), SIMDE_BFLOAT16_VALUE(   182.00), SIMDE_BFLOAT16_VALUE(   182.00), SIMDE_BFLOAT16_VALUE(   182.00) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      SIMDE_ALIGN_TO_16 simde_bfloat16_t a;
      SIMDE_ALIGN_TO_16 simde_bfloat16x4_t r;

      a = test_vec[i].a;
      r = simde_vdup_n_bf16(a);

      simde_test_arm_neon_assert_equal_bf16x4(r, simde_vld1_bf16(test_vec[i].r), 1);
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 4 ; i++) {
      SIMDE_ALIGN_TO_16 simde_bfloat16_t a = simde_test_codegen_random_bf16(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
      SIMDE_ALIGN_TO_16 simde_bfloat16x4_t r = simde_vdup_n_bf16(a);

      simde_test_codegen_write_bf16(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_bf16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vdupq_n_bf16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      SIMDE_ALIGN_TO_16 simde_bfloat16_t a;
      SIMDE_ALIGN_TO_16 simde_bfloat16_t r[8];
    } test_vec[] = {
    { SIMDE_BFLOAT16_VALUE(   246.00),
      { SIMDE_BFLOAT16_VALUE(   246.00), SIMDE_BFLOAT16_VALUE(   246.00), SIMDE_BFLOAT16_VALUE(   246.00), SIMDE_BFLOAT16_VALUE(   246.00),
        SIMDE_BFLOAT16_VALUE(   246.00), SIMDE_BFLOAT16_VALUE(   246.00), SIMDE_BFLOAT16_VALUE(   246.00), SIMDE_BFLOAT16_VALUE(   246.00) } },
    { SIMDE_BFLOAT16_VALUE(  -330.00),
      { SIMDE_BFLOAT16_VALUE(  -330.00), SIMDE_BFLOAT16_VALUE(  -330.00), SIMDE_BFLOAT16_VALUE(  -330.00), SIMDE_BFLOAT16_VALUE(  -330.00),
        SIMDE_BFLOAT16_VALUE(  -330.00), SIMDE_BFLOAT16_VALUE(  -330.00), SIMDE_BFLOAT16_VALUE(  -330.00), SIMDE_BFLOAT16_VALUE(  -330.00) } },
    { SIMDE_BFLOAT16_VALUE(   540.00),
      { SIMDE_BFLOAT16_VALUE(   540.00), SIMDE_BFLOAT16_VALUE(   540.00), SIMDE_BFLOAT16_VALUE(   540.00), SIMDE_BFLOAT16_VALUE(   540.00),
        SIMDE_BFLOAT16_VALUE(   540.00), SIMDE_BFLOAT16_VALUE(   540.00), SIMDE_BFLOAT16_VALUE(   540.00), SIMDE_BFLOAT16_VALUE(   540.00) } },
    { SIMDE_BFLOAT16_VALUE(  -210.00),
      { SIMDE_BFLOAT16_VALUE(  -210.00), SIMDE_BFLOAT16_VALUE(  -210.00), SIMDE_BFLOAT16_VALUE(  -210.00), SIMDE_BFLOAT16_VALUE(  -210.00),
        SIMDE_BFLOAT16_VALUE(  -210.00), SIMDE_BFLOAT16_VALUE(  -210.00), SIMDE_BFLOAT16_VALUE(  -210.00), SIMDE_BFLOAT16_VALUE(  -210.00) } },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      SIMDE_ALIGN_TO_16 simde_bfloat16_t a;
      SIMDE_ALIGN_TO_16 simde_bfloat16x8_t r;

      a = test_vec[i].a;
      r = simde_vdupq_n_bf16(a);

      simde_test_arm_neon_assert_equal_bf16x8(r, simde_vld1q_bf16(test_vec[i].r), 1);
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 4 ; i++) {
      simde_bfloat16_t a = simde_test_codegen_random_bf16(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
      simde_bfloat16x8_t r = simde_vdupq_n_bf16(a);

      simde_test_codegen_write_bf16(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_bf16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_p64)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_p64)

SIMDE_TEST_FUNC_LIST_ENTRY(vdup_n_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vdupq_n_bf16)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
