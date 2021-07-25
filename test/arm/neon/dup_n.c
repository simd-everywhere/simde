#define SIMDE_TEST_ARM_NEON_INSN dup_n

#include "test-neon.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vdup_n_f16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      simde_float16 a;
      simde_float16 r[4];
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
      simde_float16 a;
      simde_float16x4_t r;

      a = test_vec[i].a;
      r = simde_vdup_n_f16(a);

      simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float16 a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
      simde_float16x4_t r = simde_vdup_n_f16(a);

      simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vdup_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdup_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdup_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdup_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdup_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdup_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdup_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdup_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdup_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdup_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdupq_n_f16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      simde_float16 a;
      simde_float16 r[8];
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
      simde_float16 a;
      simde_float16x8_t r;

      a = test_vec[i].a;
      r = simde_vdupq_n_f16(a);

      simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_float16 a = simde_test_codegen_random_f16(-1000.0f, 1000.0f);
      simde_float16x8_t r = simde_vdupq_n_f16(a);

      simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vdupq_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdupq_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdupq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdupq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdupq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdupq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdupq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdupq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdupq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
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
}

static int
test_simde_vdupq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
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
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
