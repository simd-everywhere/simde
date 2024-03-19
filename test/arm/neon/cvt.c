#define SIMDE_TEST_ARM_NEON_INSN cvt

#include "test-neon.h"
#include "../../../simde/arm/neon/cvt.h"

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvth_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    int16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         INT16_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT16_MAX)),
                 INT16_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT16_MIN)),
                 INT16_MIN },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT16_MAX+1000)),
                 INT16_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT16_MIN-1000)),
                 INT16_MIN },
    #endif
    {    SIMDE_FLOAT16_VALUE(  -0.604),
         INT16_C(       0) },
    {    SIMDE_FLOAT16_VALUE(  24.671),
         INT16_C(      24) },
    {    SIMDE_FLOAT16_VALUE( -23.744),
        -INT16_C(      23) },
    {    SIMDE_FLOAT16_VALUE(  -7.939),
        -INT16_C(       7) },
    {    SIMDE_FLOAT16_VALUE( -18.393),
        -INT16_C(      18) },
    {    SIMDE_FLOAT16_VALUE(  29.124),
         INT16_C(      29) },
    {    SIMDE_FLOAT16_VALUE(  26.359),
         INT16_C(      26) },
    {    SIMDE_FLOAT16_VALUE(  19.447),
         INT16_C(      19) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int16_t r = simde_vcvth_s16_f16(a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int16_t r = simde_vcvth_s16_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvth_s32_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         INT32_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT32_MAX)),
                 INT32_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT32_MIN)),
                 INT32_MIN },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT32_MAX+1000ll)),
                 INT32_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT32_MIN-1000ll)),
                 INT32_MIN },
    #endif
    {    SIMDE_FLOAT16_VALUE(  20.055),
         INT32_C(      20) },
    {    SIMDE_FLOAT16_VALUE(   9.812),
         INT32_C(       9) },
    {   SIMDE_FLOAT16_VALUE( -  16.334),
        -INT32_C(      16) },
    {    SIMDE_FLOAT16_VALUE(  28.437),
         INT32_C(      28) },
    {    SIMDE_FLOAT16_VALUE(  27.096),
         INT32_C(      27) },
    {   SIMDE_FLOAT16_VALUE( -   3.232),
        -INT32_C(       3) },
    {   SIMDE_FLOAT16_VALUE( -  16.515),
        -INT32_C(      16) },
    {   SIMDE_FLOAT16_VALUE( -  18.901),
        -INT32_C(      18) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int32_t r = simde_vcvth_s32_f16(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int32_t r = simde_vcvth_s32_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_s64_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    int64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         INT32_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT64_MAX)),
                INT64_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT64_MIN)),
                INT64_MIN },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, 0)),
         INT32_C(       0) },
    #endif
    {   SIMDE_FLOAT16_VALUE( -  17.280),
        -INT64_C(      17) },
    {    SIMDE_FLOAT16_VALUE(  20.237),
         INT64_C(      20) },
    {    SIMDE_FLOAT16_VALUE(  27.909),
         INT64_C(      27) },
    {    SIMDE_FLOAT16_VALUE(  28.646),
         INT64_C(      28) },
    {   SIMDE_FLOAT16_VALUE( -  17.404),
        -INT64_C(      17) },
    {    SIMDE_FLOAT16_VALUE(  19.894),
         INT64_C(      19) },
    {   SIMDE_FLOAT16_VALUE( -   3.624),
        -INT64_C(       3) },
    {    SIMDE_FLOAT16_VALUE(  11.438),
         INT64_C(      11) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int64_t r = simde_vcvth_s64_f16(a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int64_t r = simde_vcvth_s64_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         UINT16_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, UINT16_MAX)),
                UINT16_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, 0)),
         UINT16_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, UINT16_MAX+1000)),
                UINT16_MAX },
    {    SIMDE_FLOAT16_VALUE( -25.081),
         UINT16_C(       0) },
    {    SIMDE_FLOAT16_VALUE( -27.803),
         UINT16_C(       0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(  25.639),
         UINT16_C(      25) },
    {    SIMDE_FLOAT16_VALUE(  15.061),
         UINT16_C(      15) },
    {    SIMDE_FLOAT16_VALUE(   3.276),
         UINT16_C(       3) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint16_t r = simde_vcvth_u16_f16(a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint16_t r = simde_vcvth_u16_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_u32_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         UINT32_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, UINT32_MAX)),
                UINT32_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, 0)),
         UINT32_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, UINT32_MAX+1000ll)),
                UINT32_MAX },
    {    SIMDE_FLOAT16_VALUE( -25.081),
         UINT16_C(       0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(  21.502),
         UINT32_C(      21) },
    {    SIMDE_FLOAT16_VALUE(  26.560),
         UINT32_C(      26) },
    {    SIMDE_FLOAT16_VALUE(  28.676),
         UINT32_C(      28) },
    {    SIMDE_FLOAT16_VALUE(   0.122),
         UINT32_C(       0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint32_t r = simde_vcvth_u32_f16(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint32_t r = simde_vcvth_u32_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_u64_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         UINT64_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, UINT64_MAX)),
                UINT64_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, 0)),
         UINT64_C(       0) },
    {   SIMDE_FLOAT16_VALUE( -16.558),
         UINT64_C(       0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(  11.916),
         UINT64_C(      11) },
    {    SIMDE_FLOAT16_VALUE(   2.866),
         UINT64_C(       2) },
    {    SIMDE_FLOAT16_VALUE(  21.522),
         UINT64_C(      21) },
    {    SIMDE_FLOAT16_VALUE(  10.554),
         UINT64_C(      10) },
    {    SIMDE_FLOAT16_VALUE(   4.087),
         UINT64_C(       4) },
    {    SIMDE_FLOAT16_VALUE(  19.017),
         UINT64_C(      19) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint64_t r = simde_vcvth_u64_f16(a);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint64_t r = simde_vcvth_u64_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a;
    simde_float16 r;
  } test_vec[] = {
    {    INT16_C(   12305),
         SIMDE_FLOAT16_VALUE(12305.000) },
    {    INT16_C(   18453),
         SIMDE_FLOAT16_VALUE(18453.000) },
    {    INT16_C(   22436),
         SIMDE_FLOAT16_VALUE(22436.000) },
    {    INT16_C(   32234),
         SIMDE_FLOAT16_VALUE(32234.000) },
    {    INT16_C(   14635),
         SIMDE_FLOAT16_VALUE(14635.000) },
    {    INT16_C(    8656),
         SIMDE_FLOAT16_VALUE(8656.000) },
    {   -INT16_C(   16437),
         SIMDE_FLOAT16_VALUE(-16437.000) },
    {    INT16_C(   22652),
         SIMDE_FLOAT16_VALUE(22652.000) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 r = simde_vcvth_f16_s16(test_vec[i].a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16_t a = simde_test_codegen_random_i16();
    simde_float16_t r = simde_vcvth_f16_s16(a);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_f16_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a;
    simde_float16_t r;
  } test_vec[] = {
    { -INT32_C(  1589103087),
          SIMDE_NINFINITYHF },
    { -INT32_C(  1592118057),
          SIMDE_NINFINITYHF },
    {  INT32_C(   895663592),
           SIMDE_INFINITYHF },
    { -INT32_C(   320293893),
          SIMDE_NINFINITYHF },
    { -INT32_C(  2108080077),
          SIMDE_NINFINITYHF },
    { -INT32_C(  1415311873),
          SIMDE_NINFINITYHF },
    {  INT32_C(  1265253428),
           SIMDE_INFINITYHF },
    {  INT32_C(   587118609),
           SIMDE_INFINITYHF },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t r = simde_vcvth_f16_s32(test_vec[i].a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_float16_t r = simde_vcvth_f16_s32(a);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_f16_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a;
    simde_float16_t r;
  } test_vec[] = {
    {  INT64_C( 7162937251746498287),
           SIMDE_INFINITYHF },
    { -INT64_C( 5728155978464441958),
          SIMDE_NINFINITYHF },
    {  INT64_C( 2047685275721849536),
           SIMDE_INFINITYHF },
    {  INT64_C( 8954675090954900754),
           SIMDE_INFINITYHF },
    {  INT64_C( 9190064415792367788),
           SIMDE_INFINITYHF },
    {  INT64_C( 7034787140702839156),
           SIMDE_INFINITYHF },
    { -INT64_C( 4867111737836383376),
          SIMDE_NINFINITYHF },
    { -INT64_C( 1339216974095328416),
          SIMDE_NINFINITYHF },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t r = simde_vcvth_f16_s64(test_vec[i].a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    simde_float16_t r = simde_vcvth_f16_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a;
    simde_float16 r;
  } test_vec[] = {
    {    UINT16_C(   10525),
         SIMDE_FLOAT16_VALUE(10525.000) },
    {    UINT16_C(   18190),
         SIMDE_FLOAT16_VALUE(18190.000) },
    {    UINT16_C(    6600),
         SIMDE_FLOAT16_VALUE(6600.000) },
    {    UINT16_C(   41046),
         SIMDE_FLOAT16_VALUE(41046.000) },
    {    UINT16_C(   25615),
         SIMDE_FLOAT16_VALUE(25615.000) },
    {    UINT16_C(    5526),
         SIMDE_FLOAT16_VALUE(5526.000) },
    {    UINT16_C(   20800),
         SIMDE_FLOAT16_VALUE(20800.000) },
    {    UINT16_C(   13173),
         SIMDE_FLOAT16_VALUE(13173.000) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 r = simde_vcvth_f16_u32(test_vec[i].a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16_t a = simde_test_codegen_random_u16();
    simde_float16_t r = simde_vcvth_f16_u16(a);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_f16_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a;
    simde_float16_t r;
  } test_vec[] = {
    { UINT32_C( 320056621),
           SIMDE_INFINITYHF },
    { UINT32_C(3415383383),
           SIMDE_INFINITYHF },
    { UINT32_C(1622976446),
           SIMDE_INFINITYHF },
    { UINT32_C(2898353212),
           SIMDE_INFINITYHF },
    { UINT32_C(3640975919),
           SIMDE_INFINITYHF },
    { UINT32_C(3449124973),
           SIMDE_INFINITYHF },
    { UINT32_C(2512024660),
           SIMDE_INFINITYHF },
    { UINT32_C(3347195033),
           SIMDE_INFINITYHF },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t r = simde_vcvth_f16_u32(test_vec[i].a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    simde_float16_t r = simde_vcvth_f16_u32(a);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_f16_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a;
    simde_float16_t r;
  } test_vec[] = {
    { UINT64_C(17434679020164388305),
           SIMDE_INFINITYHF },
    { UINT64_C( 4394407184798167059),
           SIMDE_INFINITYHF },
    { UINT64_C(14784942065000448500),
           SIMDE_INFINITYHF },
    { UINT64_C(16104841540079380767),
           SIMDE_INFINITYHF },
    { UINT64_C(15680967407793887610),
           SIMDE_INFINITYHF },
    { UINT64_C(17723395172423298733),
           SIMDE_INFINITYHF },
    { UINT64_C(15379376796937423911),
           SIMDE_INFINITYHF },
    { UINT64_C( 3412336215793258606),
           SIMDE_INFINITYHF },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t r = simde_vcvth_f16_u64(test_vec[i].a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    simde_float16_t r = simde_vcvth_f16_u64(a);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvts_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                    INT32_MAX },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) - SIMDE_FLOAT32_C(1000.0),
                    INT32_MIN },
    #endif
    { SIMDE_FLOAT32_C(   550.19),
       INT32_C(         550) },
    { SIMDE_FLOAT32_C(   -14.71),
      -INT32_C(          14) },
    { SIMDE_FLOAT32_C(   735.91),
       INT32_C(         735) },
    { SIMDE_FLOAT32_C(   355.60),
       INT32_C(         355) },
    { SIMDE_FLOAT32_C(  -850.41),
      -INT32_C(         850) },
    { SIMDE_FLOAT32_C(  -934.68),
      -INT32_C(         934) },
    { SIMDE_FLOAT32_C(  -125.28),
      -INT32_C(         125) },
    { SIMDE_FLOAT32_C(   784.80),
       INT32_C(         784) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    int32_t r = simde_vcvts_s32_f32(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a = simde_test_codegen_random_f32(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int32_t r = simde_vcvts_s32_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtd_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    int64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {             SIMDE_MATH_NAN,
        INT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0),
                    INT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) - SIMDE_FLOAT64_C(10000.0),
                    INT64_MIN },
    #endif
    { SIMDE_FLOAT64_C(  -881.66),
      -INT64_C(                 881) },
    { SIMDE_FLOAT64_C(  -469.33),
      -INT64_C(                 469) },
    { SIMDE_FLOAT64_C(   808.92),
       INT64_C(                 808) },
    { SIMDE_FLOAT64_C(   567.01),
       INT64_C(                 567) },
    { SIMDE_FLOAT64_C(  -252.92),
      -INT64_C(                 252) },
    { SIMDE_FLOAT64_C(   379.60),
       INT64_C(                 379) },
    { SIMDE_FLOAT64_C(  -471.75),
      -INT64_C(                 471) },
    { SIMDE_FLOAT64_C(   774.04),
       INT64_C(                 774) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    int64_t r = simde_vcvtd_s64_f64(a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int64_t r = simde_vcvtd_s64_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvts_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                  UINT32_MAX },
      { SIMDE_FLOAT32_C(-1000.0),
        UINT32_C(         0) },
    #endif
    { SIMDE_FLOAT32_C(   738.60),
      UINT32_C(       738) },
    { SIMDE_FLOAT32_C(   205.64),
      UINT32_C(       205) },
    { SIMDE_FLOAT32_C(   570.91),
      UINT32_C(       570) },
    { SIMDE_FLOAT32_C(   812.89),
      UINT32_C(       812) },
    { SIMDE_FLOAT32_C(   660.14),
      UINT32_C(       660) },
    { SIMDE_FLOAT32_C(   129.55),
      UINT32_C(       129) },
    { SIMDE_FLOAT32_C(   382.62),
      UINT32_C(       382) },
    { SIMDE_FLOAT32_C(   355.17),
      UINT32_C(       355) }

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    uint32_t r = simde_vcvts_u32_f32(a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32 a = simde_test_codegen_random_f32(SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1000.0));
    uint32_t r = simde_vcvts_u32_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtd_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {             SIMDE_MATH_NAN,
        INT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(10000.0),
                  UINT64_MAX },
      { SIMDE_FLOAT64_C(-1000.0),
        UINT64_C(         0) },
    #endif
    { SIMDE_FLOAT64_C(   428.71),
      UINT64_C(                 428) },
    { SIMDE_FLOAT64_C(   662.47),
      UINT64_C(                 662) },
    { SIMDE_FLOAT64_C(   262.53),
      UINT64_C(                 262) },
    { SIMDE_FLOAT64_C(   313.97),
      UINT64_C(                 313) },
    { SIMDE_FLOAT64_C(   730.17),
      UINT64_C(                 730) },
    { SIMDE_FLOAT64_C(    13.75),
      UINT64_C(                  13) },
    { SIMDE_FLOAT64_C(   587.80),
      UINT64_C(                 587) },
    { SIMDE_FLOAT64_C(   889.77),
      UINT64_C(                 889) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    uint64_t r = simde_vcvtd_u64_f64(a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
    uint64_t r = simde_vcvtd_u64_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvt_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(  -567.00), SIMDE_FLOAT16_VALUE(   429.00), SIMDE_FLOAT16_VALUE(   629.50), SIMDE_FLOAT16_VALUE(  -509.25) },
      { -INT16_C(   567),  INT16_C(   429),  INT16_C(   629), -INT16_C(   509) } },
    { { SIMDE_FLOAT16_VALUE(  -128.50), SIMDE_FLOAT16_VALUE(  -750.00), SIMDE_FLOAT16_VALUE(   953.00), SIMDE_FLOAT16_VALUE(  -576.50) },
      { -INT16_C(   128), -INT16_C(   750),  INT16_C(   953), -INT16_C(   576) } },
    { { SIMDE_FLOAT16_VALUE(   999.00), SIMDE_FLOAT16_VALUE(  -727.50), SIMDE_FLOAT16_VALUE(  -893.00), SIMDE_FLOAT16_VALUE(  -542.50) },
      {  INT16_C(   999), -INT16_C(   727), -INT16_C(   893), -INT16_C(   542) } },
    { { SIMDE_FLOAT16_VALUE(  -866.00), SIMDE_FLOAT16_VALUE(  -895.50), SIMDE_FLOAT16_VALUE(   283.25), SIMDE_FLOAT16_VALUE(   857.50) },
      { -INT16_C(   866), -INT16_C(   895),  INT16_C(   283),  INT16_C(   857) } },
    { { SIMDE_FLOAT16_VALUE(    32.12), SIMDE_FLOAT16_VALUE(   794.00), SIMDE_FLOAT16_VALUE(  -495.75), SIMDE_FLOAT16_VALUE(  -708.50) },
      {  INT16_C(    32),  INT16_C(   794), -INT16_C(   495), -INT16_C(   708) } },
    { { SIMDE_FLOAT16_VALUE(   322.25), SIMDE_FLOAT16_VALUE(   821.50), SIMDE_FLOAT16_VALUE(   844.50), SIMDE_FLOAT16_VALUE(   952.50) },
      {  INT16_C(   322),  INT16_C(   821),  INT16_C(   844),  INT16_C(   952) } },
    { { SIMDE_FLOAT16_VALUE(   502.50), SIMDE_FLOAT16_VALUE(  -996.50), SIMDE_FLOAT16_VALUE(  -817.50), SIMDE_FLOAT16_VALUE(  -562.50) },
      {  INT16_C(   502), -INT16_C(   996), -INT16_C(   817), -INT16_C(   562) } },
    { { SIMDE_FLOAT16_VALUE(  -805.50), SIMDE_FLOAT16_VALUE(   461.50), SIMDE_FLOAT16_VALUE(   550.50), SIMDE_FLOAT16_VALUE(  -372.75) },
      { -INT16_C(   805),  INT16_C(   461),  INT16_C(   550), -INT16_C(   372) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_int16x4_t r = simde_vcvt_s16_f16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
    simde_int16x4_t r = simde_vcvt_s16_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvt_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    int32_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(1000.0),
          HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) - SIMDE_FLOAT32_C(1000.0) },
        {              INT32_MAX,              INT32_MIN } },
      { {        SIMDE_MATH_NANF,   SIMDE_MATH_INFINITYF },
        {  INT32_C(           0),              INT32_MAX } },
    #endif
    { { SIMDE_FLOAT32_C(   396.15), SIMDE_FLOAT32_C(  -246.90) },
      {  INT32_C(         396), -INT32_C(         246) } },
    { { SIMDE_FLOAT32_C(   241.51), SIMDE_FLOAT32_C(   602.56) },
      {  INT32_C(         241),  INT32_C(         602) } },
    { { SIMDE_FLOAT32_C(  -106.85), SIMDE_FLOAT32_C(  -566.67) },
      { -INT32_C(         106), -INT32_C(         566) } },
    { { SIMDE_FLOAT32_C(   463.44), SIMDE_FLOAT32_C(   539.86) },
      {  INT32_C(         463),  INT32_C(         539) } },
    { { SIMDE_FLOAT32_C(  -550.41), SIMDE_FLOAT32_C(   982.91) },
      { -INT32_C(         550),  INT32_C(         982) } },
    { { SIMDE_FLOAT32_C(   499.92), SIMDE_FLOAT32_C(  -727.55) },
      {  INT32_C(         499), -INT32_C(         727) } },
    { { SIMDE_FLOAT32_C(  -713.41), SIMDE_FLOAT32_C(   713.10) },
      { -INT32_C(         713),  INT32_C(         713) } },
    { { SIMDE_FLOAT32_C(  -998.69), SIMDE_FLOAT32_C(  -409.99) },
      { -INT32_C(         998), -INT32_C(         409) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_int32x2_t r = simde_vcvt_s32_f32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int32x2_t r = simde_vcvt_s32_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    int64_t r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0) },
        { INT64_MAX } },
      { { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) - SIMDE_FLOAT64_C(10000.0) },
        { INT64_MIN } },
      { { SIMDE_MATH_NAN },
        {  INT64_C(0) } },
    #endif
    { { SIMDE_FLOAT64_C(  -824.03) },
      { -INT64_C(                 824) } },
    { { SIMDE_FLOAT64_C(  -841.94) },
      { -INT64_C(                 841) } },
    { { SIMDE_FLOAT64_C(  -786.92) },
      { -INT64_C(                 786) } },
    { { SIMDE_FLOAT64_C(     5.30) },
      {  INT64_C(                   5) } },
    { { SIMDE_FLOAT64_C(   -36.80) },
      { -INT64_C(                  36) } },
    { { SIMDE_FLOAT64_C(   375.47) },
      {  INT64_C(                 375) } },
    { { SIMDE_FLOAT64_C(   -12.40) },
      { -INT64_C(                  12) } },
    { { SIMDE_FLOAT64_C(    35.70) },
      {  INT64_C(                  35) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_int64x1_t r = simde_vcvt_s64_f64(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x1_t r = simde_vcvt_s64_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { SIMDE_FLOAT16_VALUE(  -611.50), SIMDE_FLOAT16_VALUE(  -588.50), SIMDE_FLOAT16_VALUE(   839.00), SIMDE_FLOAT16_VALUE(   440.50) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(  839), UINT16_C(  440) } },
      { { SIMDE_FLOAT16_VALUE(   -43.19), SIMDE_FLOAT16_VALUE(  -115.88), SIMDE_FLOAT16_VALUE(   160.50), SIMDE_FLOAT16_VALUE(   744.50) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(  160), UINT16_C(  744) } },
    #endif
    { { SIMDE_FLOAT16_VALUE(   231.75), SIMDE_FLOAT16_VALUE(   971.00), SIMDE_FLOAT16_VALUE(   897.00), SIMDE_FLOAT16_VALUE(   241.25) },
      { UINT16_C(  231), UINT16_C(  971), UINT16_C(  897), UINT16_C(  241) } },
    { { SIMDE_FLOAT16_VALUE(   648.00), SIMDE_FLOAT16_VALUE(   268.25), SIMDE_FLOAT16_VALUE(    91.31), SIMDE_FLOAT16_VALUE(   371.50) },
      { UINT16_C(  648), UINT16_C(  268), UINT16_C(   91), UINT16_C(  371) } },
    { { SIMDE_FLOAT16_VALUE(   526.50), SIMDE_FLOAT16_VALUE(   148.12), SIMDE_FLOAT16_VALUE(   325.00), SIMDE_FLOAT16_VALUE(    28.55) },
      { UINT16_C(  526), UINT16_C(  148), UINT16_C(  325), UINT16_C(   28) } },
    { { SIMDE_FLOAT16_VALUE(   947.50), SIMDE_FLOAT16_VALUE(   371.75), SIMDE_FLOAT16_VALUE(   814.50), SIMDE_FLOAT16_VALUE(   417.00) },
      { UINT16_C(  947), UINT16_C(  371), UINT16_C(  814), UINT16_C(  417) } },
    { { SIMDE_FLOAT16_VALUE(   645.50), SIMDE_FLOAT16_VALUE(   735.50), SIMDE_FLOAT16_VALUE(   809.00), SIMDE_FLOAT16_VALUE(    30.17) },
      { UINT16_C(  645), UINT16_C(  735), UINT16_C(  809), UINT16_C(   30) } },
    { { SIMDE_FLOAT16_VALUE(   688.00), SIMDE_FLOAT16_VALUE(    22.16), SIMDE_FLOAT16_VALUE(   276.50), SIMDE_FLOAT16_VALUE(   148.62) },
      { UINT16_C(  688), UINT16_C(   22), UINT16_C(  276), UINT16_C(  148) } },
    { { SIMDE_FLOAT16_VALUE(   478.50), SIMDE_FLOAT16_VALUE(   456.50), SIMDE_FLOAT16_VALUE(   974.00), SIMDE_FLOAT16_VALUE(   416.50) },
      { UINT16_C(  478), UINT16_C(  456), UINT16_C(  974), UINT16_C(  416) } },
    { { SIMDE_FLOAT16_VALUE(   282.75), SIMDE_FLOAT16_VALUE(   147.88), SIMDE_FLOAT16_VALUE(   541.00), SIMDE_FLOAT16_VALUE(   514.50) },
      { UINT16_C(  282), UINT16_C(  147), UINT16_C(  541), UINT16_C(  514) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcvt_u16_f16(a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(0.0f, 1000.0f);
    simde_uint16x4_t r = simde_vcvt_u16_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(1000.0) },
        { UINT32_MAX } },
      { { -SIMDE_FLOAT32_C(1000.0) },
        { INT32_C(0) } },
      { { SIMDE_MATH_NANF },
        { INT32_C(0) } },
    #endif
    { { SIMDE_FLOAT32_C(   308.77), SIMDE_FLOAT32_C(   269.80) },
      { UINT32_C(       308), UINT32_C(       269) } },
    { { SIMDE_FLOAT32_C(   859.81), SIMDE_FLOAT32_C(    64.54) },
      { UINT32_C(       859), UINT32_C(        64) } },
    { { SIMDE_FLOAT32_C(     2.07), SIMDE_FLOAT32_C(   232.20) },
      { UINT32_C(         2), UINT32_C(       232) } },
    { { SIMDE_FLOAT32_C(   601.91), SIMDE_FLOAT32_C(   749.29) },
      { UINT32_C(       601), UINT32_C(       749) } },
    { { SIMDE_FLOAT32_C(   306.06), SIMDE_FLOAT32_C(   837.28) },
      { UINT32_C(       306), UINT32_C(       837) } },
    { { SIMDE_FLOAT32_C(   751.87), SIMDE_FLOAT32_C(   543.72) },
      { UINT32_C(       751), UINT32_C(       543) } },
    { { SIMDE_FLOAT32_C(   269.87), SIMDE_FLOAT32_C(   829.47) },
      { UINT32_C(       269), UINT32_C(       829) } },
    { { SIMDE_FLOAT32_C(    14.26), SIMDE_FLOAT32_C(   782.29) },
      { UINT32_C(        14), UINT32_C(       782) } }

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcvt_u32_f32(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(0.0, 1000.0);
    simde_uint32x2_t r = simde_vcvt_u32_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(10000.0) },
        { UINT64_MAX } },
      { { -SIMDE_FLOAT64_C(1000.0) },
        { INT64_C(0) } },
      { { SIMDE_MATH_NAN },
        { INT64_C(0) } },
    #endif
    { { SIMDE_FLOAT64_C(   344.30) },
      { UINT64_C(                 344) } },
    { { SIMDE_FLOAT64_C(   669.70) },
      { UINT64_C(                 669) } },
    { { SIMDE_FLOAT64_C(   628.84) },
      { UINT64_C(                 628) } },
    { { SIMDE_FLOAT64_C(   358.76) },
      { UINT64_C(                 358) } },
    { { SIMDE_FLOAT64_C(    85.06) },
      { UINT64_C(                  85) } },
    { { SIMDE_FLOAT64_C(   302.20) },
      { UINT64_C(                 302) } },
    { { SIMDE_FLOAT64_C(   709.75) },
      { UINT64_C(                 709) } },
    { { SIMDE_FLOAT64_C(   502.24) },
      { UINT64_C(                 502) } }

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcvt_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x1_t r = simde_vcvt_u64_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtq_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   309.00), SIMDE_FLOAT16_VALUE(   886.50), SIMDE_FLOAT16_VALUE(  -319.25), SIMDE_FLOAT16_VALUE(   953.50),
        SIMDE_FLOAT16_VALUE(   259.50), SIMDE_FLOAT16_VALUE(  -722.00), SIMDE_FLOAT16_VALUE(   772.50), SIMDE_FLOAT16_VALUE(    99.88) },
      {  INT16_C(   309),  INT16_C(   886), -INT16_C(   319),  INT16_C(   953),  INT16_C(   259), -INT16_C(   722),  INT16_C(   772),  INT16_C(    99) } },
    { { SIMDE_FLOAT16_VALUE(  -622.00), SIMDE_FLOAT16_VALUE(   731.00), SIMDE_FLOAT16_VALUE(  -240.38), SIMDE_FLOAT16_VALUE(  -888.00),
        SIMDE_FLOAT16_VALUE(   144.38), SIMDE_FLOAT16_VALUE(  -188.75), SIMDE_FLOAT16_VALUE(   374.50), SIMDE_FLOAT16_VALUE(    58.06) },
      { -INT16_C(   622),  INT16_C(   731), -INT16_C(   240), -INT16_C(   888),  INT16_C(   144), -INT16_C(   188),  INT16_C(   374),  INT16_C(    58) } },
    { { SIMDE_FLOAT16_VALUE(   631.50), SIMDE_FLOAT16_VALUE(   798.00), SIMDE_FLOAT16_VALUE(  -243.75), SIMDE_FLOAT16_VALUE(   144.88),
        SIMDE_FLOAT16_VALUE(  -847.50), SIMDE_FLOAT16_VALUE(  -395.50), SIMDE_FLOAT16_VALUE(  -145.88), SIMDE_FLOAT16_VALUE(   916.50) },
      {  INT16_C(   631),  INT16_C(   798), -INT16_C(   243),  INT16_C(   144), -INT16_C(   847), -INT16_C(   395), -INT16_C(   145),  INT16_C(   916) } },
    { { SIMDE_FLOAT16_VALUE(   875.00), SIMDE_FLOAT16_VALUE(  -104.69), SIMDE_FLOAT16_VALUE(   135.25), SIMDE_FLOAT16_VALUE(   727.50),
        SIMDE_FLOAT16_VALUE(   698.50), SIMDE_FLOAT16_VALUE(   839.00), SIMDE_FLOAT16_VALUE(   435.75), SIMDE_FLOAT16_VALUE(     7.73) },
      {  INT16_C(   875), -INT16_C(   104),  INT16_C(   135),  INT16_C(   727),  INT16_C(   698),  INT16_C(   839),  INT16_C(   435),  INT16_C(     7) } },
    { { SIMDE_FLOAT16_VALUE(   725.50), SIMDE_FLOAT16_VALUE(  -883.50), SIMDE_FLOAT16_VALUE(   -38.53), SIMDE_FLOAT16_VALUE(   -14.96),
        SIMDE_FLOAT16_VALUE(  -605.50), SIMDE_FLOAT16_VALUE(  -266.00), SIMDE_FLOAT16_VALUE(  -915.00), SIMDE_FLOAT16_VALUE(  -227.38) },
      {  INT16_C(   725), -INT16_C(   883), -INT16_C(    38), -INT16_C(    14), -INT16_C(   605), -INT16_C(   266), -INT16_C(   915), -INT16_C(   227) } },
    { { SIMDE_FLOAT16_VALUE(  -535.00), SIMDE_FLOAT16_VALUE(  -155.38), SIMDE_FLOAT16_VALUE(  -115.19), SIMDE_FLOAT16_VALUE(   609.50),
        SIMDE_FLOAT16_VALUE(   656.00), SIMDE_FLOAT16_VALUE(  -740.50), SIMDE_FLOAT16_VALUE(  -332.50), SIMDE_FLOAT16_VALUE(   287.50) },
      { -INT16_C(   535), -INT16_C(   155), -INT16_C(   115),  INT16_C(   609),  INT16_C(   656), -INT16_C(   740), -INT16_C(   332),  INT16_C(   287) } },
    { { SIMDE_FLOAT16_VALUE(  -943.00), SIMDE_FLOAT16_VALUE(   423.75), SIMDE_FLOAT16_VALUE(  -567.50), SIMDE_FLOAT16_VALUE(  -790.50),
        SIMDE_FLOAT16_VALUE(  -972.00), SIMDE_FLOAT16_VALUE(   286.50), SIMDE_FLOAT16_VALUE(  -874.00), SIMDE_FLOAT16_VALUE(   903.00) },
      { -INT16_C(   943),  INT16_C(   423), -INT16_C(   567), -INT16_C(   790), -INT16_C(   972),  INT16_C(   286), -INT16_C(   874),  INT16_C(   903) } },
    { { SIMDE_FLOAT16_VALUE(  -818.00), SIMDE_FLOAT16_VALUE(   261.25), SIMDE_FLOAT16_VALUE(   630.50), SIMDE_FLOAT16_VALUE(   880.50),
        SIMDE_FLOAT16_VALUE(   100.44), SIMDE_FLOAT16_VALUE(    66.19), SIMDE_FLOAT16_VALUE(  -111.75), SIMDE_FLOAT16_VALUE(  -173.88) },
      { -INT16_C(   818),  INT16_C(   261),  INT16_C(   630),  INT16_C(   880),  INT16_C(   100),  INT16_C(    66), -INT16_C(   111), -INT16_C(   173) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_int16x8_t r = simde_vcvtq_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-1000.0f, 1000.0f);
    simde_int16x8_t r = simde_vcvtq_s16_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtq_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    int32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(10000.0), HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) - SIMDE_FLOAT32_C(10000.0), SIMDE_MATH_NANF, SIMDE_MATH_INFINITYF },
        {              INT32_MAX,              INT32_MIN,  INT32_C(           0),              INT32_MAX } },
    #endif
    { { SIMDE_FLOAT32_C(   553.19), SIMDE_FLOAT32_C(   -89.37), SIMDE_FLOAT32_C(  -751.51), SIMDE_FLOAT32_C(    39.67) },
      {  INT32_C(         553), -INT32_C(          89), -INT32_C(         751),  INT32_C(          39) } },
    { { SIMDE_FLOAT32_C(   324.39), SIMDE_FLOAT32_C(    39.90), SIMDE_FLOAT32_C(   154.38), SIMDE_FLOAT32_C(  -782.06) },
      {  INT32_C(         324),  INT32_C(          39),  INT32_C(         154), -INT32_C(         782) } },
    { { SIMDE_FLOAT32_C(   683.78), SIMDE_FLOAT32_C(   860.43), SIMDE_FLOAT32_C(   258.08), SIMDE_FLOAT32_C(  -431.46) },
      {  INT32_C(         683),  INT32_C(         860),  INT32_C(         258), -INT32_C(         431) } },
    { { SIMDE_FLOAT32_C(     4.94), SIMDE_FLOAT32_C(  -752.53), SIMDE_FLOAT32_C(   343.30), SIMDE_FLOAT32_C(  -618.07) },
      {  INT32_C(           4), -INT32_C(         752),  INT32_C(         343), -INT32_C(         618) } },
    { { SIMDE_FLOAT32_C(  -508.63), SIMDE_FLOAT32_C(   933.29), SIMDE_FLOAT32_C(    48.92), SIMDE_FLOAT32_C(   220.74) },
      { -INT32_C(         508),  INT32_C(         933),  INT32_C(          48),  INT32_C(         220) } },
    { { SIMDE_FLOAT32_C(  -447.64), SIMDE_FLOAT32_C(  -181.80), SIMDE_FLOAT32_C(  -962.01), SIMDE_FLOAT32_C(   914.94) },
      { -INT32_C(         447), -INT32_C(         181), -INT32_C(         962),  INT32_C(         914) } },
    { { SIMDE_FLOAT32_C(  -193.26), SIMDE_FLOAT32_C(    71.12), SIMDE_FLOAT32_C(   342.76), SIMDE_FLOAT32_C(  -390.07) },
      { -INT32_C(         193),  INT32_C(          71),  INT32_C(         342), -INT32_C(         390) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_int32x4_t r = simde_vcvtq_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_int32x4_t r = simde_vcvtq_s32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    int64_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0), HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) - SIMDE_FLOAT64_C(10000.0) },
        {                      INT64_MAX,                      INT64_MIN } },
      { {             SIMDE_MATH_NAN,        SIMDE_MATH_INFINITY },
        { INT64_C(                   0),                       INT64_MAX } },
    #endif
    { { SIMDE_FLOAT64_C(     7.90), SIMDE_FLOAT64_C(  -570.72) },
      {  INT64_C(                   7), -INT64_C(                 570) } },
    { { SIMDE_FLOAT64_C(  -808.38), SIMDE_FLOAT64_C(   530.98) },
      { -INT64_C(                 808),  INT64_C(                 530) } },
    { { SIMDE_FLOAT64_C(   801.81), SIMDE_FLOAT64_C(  -148.95) },
      {  INT64_C(                 801), -INT64_C(                 148) } },
    { { SIMDE_FLOAT64_C(   837.17), SIMDE_FLOAT64_C(   387.04) },
      {  INT64_C(                 837),  INT64_C(                 387) } },
    { { SIMDE_FLOAT64_C(   553.61), SIMDE_FLOAT64_C(     6.86) },
      {  INT64_C(                 553),  INT64_C(                   6) } },
    { { SIMDE_FLOAT64_C(  -828.64), SIMDE_FLOAT64_C(  -734.97) },
      { -INT64_C(                 828), -INT64_C(                 734) } },
    { { SIMDE_FLOAT64_C(   315.20), SIMDE_FLOAT64_C(  -666.72) },
      {  INT64_C(                 315), -INT64_C(                 666) } },
    { { SIMDE_FLOAT64_C(  -735.89), SIMDE_FLOAT64_C(    55.10) },
      { -INT64_C(                 735),  INT64_C(                  55) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_int64x2_t r = simde_vcvtq_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x2_t r = simde_vcvtq_s64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { SIMDE_FLOAT16_VALUE(   -30.81), SIMDE_FLOAT16_VALUE(    29.19), SIMDE_FLOAT16_VALUE(  -867.50), SIMDE_FLOAT16_VALUE(   968.50),
          SIMDE_FLOAT16_VALUE(   624.50), SIMDE_FLOAT16_VALUE(  -223.62), SIMDE_FLOAT16_VALUE(   875.00), SIMDE_FLOAT16_VALUE(  -341.00) },
        { UINT16_C(    0), UINT16_C(   29), UINT16_C(    0), UINT16_C(  968), UINT16_C(  624), UINT16_C(    0), UINT16_C(  875), UINT16_C(    0) } },
      { { SIMDE_FLOAT16_VALUE(   -88.00), SIMDE_FLOAT16_VALUE(   -72.25), SIMDE_FLOAT16_VALUE(   860.00), SIMDE_FLOAT16_VALUE(  -702.00),
          SIMDE_FLOAT16_VALUE(   153.12), SIMDE_FLOAT16_VALUE(  -930.00), SIMDE_FLOAT16_VALUE(  -692.50), SIMDE_FLOAT16_VALUE(   928.50) },
        { UINT16_C(    0), UINT16_C(    0), UINT16_C(  860), UINT16_C(    0), UINT16_C(  153), UINT16_C(    0), UINT16_C(    0), UINT16_C(  928) } },
    #endif
    { { SIMDE_FLOAT16_VALUE(   821.00), SIMDE_FLOAT16_VALUE(   969.00), SIMDE_FLOAT16_VALUE(   726.00), SIMDE_FLOAT16_VALUE(   631.50),
        SIMDE_FLOAT16_VALUE(   153.75), SIMDE_FLOAT16_VALUE(   778.00), SIMDE_FLOAT16_VALUE(    77.06), SIMDE_FLOAT16_VALUE(   815.00) },
      { UINT16_C(  821), UINT16_C(  969), UINT16_C(  726), UINT16_C(  631), UINT16_C(  153), UINT16_C(  778), UINT16_C(   77), UINT16_C(  815) } },
    { { SIMDE_FLOAT16_VALUE(   625.00), SIMDE_FLOAT16_VALUE(   984.00), SIMDE_FLOAT16_VALUE(   298.00), SIMDE_FLOAT16_VALUE(   493.00),
        SIMDE_FLOAT16_VALUE(   926.50), SIMDE_FLOAT16_VALUE(   626.50), SIMDE_FLOAT16_VALUE(   730.50), SIMDE_FLOAT16_VALUE(   913.00) },
      { UINT16_C(  625), UINT16_C(  984), UINT16_C(  298), UINT16_C(  493), UINT16_C(  926), UINT16_C(  626), UINT16_C(  730), UINT16_C(  913) } },
    { { SIMDE_FLOAT16_VALUE(    29.12), SIMDE_FLOAT16_VALUE(   162.00), SIMDE_FLOAT16_VALUE(   816.00), SIMDE_FLOAT16_VALUE(    81.75),
        SIMDE_FLOAT16_VALUE(   954.50), SIMDE_FLOAT16_VALUE(   541.50), SIMDE_FLOAT16_VALUE(   425.50), SIMDE_FLOAT16_VALUE(    54.72) },
      { UINT16_C(   29), UINT16_C(  162), UINT16_C(  816), UINT16_C(   81), UINT16_C(  954), UINT16_C(  541), UINT16_C(  425), UINT16_C(   54) } },
    { { SIMDE_FLOAT16_VALUE(   252.62), SIMDE_FLOAT16_VALUE(   320.75), SIMDE_FLOAT16_VALUE(   262.50), SIMDE_FLOAT16_VALUE(   497.25),
        SIMDE_FLOAT16_VALUE(    23.61), SIMDE_FLOAT16_VALUE(   752.00), SIMDE_FLOAT16_VALUE(   131.12), SIMDE_FLOAT16_VALUE(   844.50) },
      { UINT16_C(  252), UINT16_C(  320), UINT16_C(  262), UINT16_C(  497), UINT16_C(   23), UINT16_C(  752), UINT16_C(  131), UINT16_C(  844) } },
    { { SIMDE_FLOAT16_VALUE(   721.00), SIMDE_FLOAT16_VALUE(   857.00), SIMDE_FLOAT16_VALUE(   476.25), SIMDE_FLOAT16_VALUE(   874.50),
        SIMDE_FLOAT16_VALUE(   635.00), SIMDE_FLOAT16_VALUE(   553.50), SIMDE_FLOAT16_VALUE(   690.00), SIMDE_FLOAT16_VALUE(   260.00) },
      { UINT16_C(  721), UINT16_C(  857), UINT16_C(  476), UINT16_C(  874), UINT16_C(  635), UINT16_C(  553), UINT16_C(  690), UINT16_C(  260) } },
    { { SIMDE_FLOAT16_VALUE(   537.00), SIMDE_FLOAT16_VALUE(   988.00), SIMDE_FLOAT16_VALUE(   753.00), SIMDE_FLOAT16_VALUE(   463.75),
        SIMDE_FLOAT16_VALUE(   614.50), SIMDE_FLOAT16_VALUE(   483.25), SIMDE_FLOAT16_VALUE(   376.50), SIMDE_FLOAT16_VALUE(   643.50) },
      { UINT16_C(  537), UINT16_C(  988), UINT16_C(  753), UINT16_C(  463), UINT16_C(  614), UINT16_C(  483), UINT16_C(  376), UINT16_C(  643) } },
    { { SIMDE_FLOAT16_VALUE(   645.50), SIMDE_FLOAT16_VALUE(   192.38), SIMDE_FLOAT16_VALUE(   725.50), SIMDE_FLOAT16_VALUE(   599.50),
        SIMDE_FLOAT16_VALUE(   734.00), SIMDE_FLOAT16_VALUE(   150.88), SIMDE_FLOAT16_VALUE(   654.50), SIMDE_FLOAT16_VALUE(   987.00) },
      { UINT16_C(  645), UINT16_C(  192), UINT16_C(  725), UINT16_C(  599), UINT16_C(  734), UINT16_C(  150), UINT16_C(  654), UINT16_C(  987) } },
    { { SIMDE_FLOAT16_VALUE(   471.75), SIMDE_FLOAT16_VALUE(   917.00), SIMDE_FLOAT16_VALUE(   484.00), SIMDE_FLOAT16_VALUE(   495.25),
        SIMDE_FLOAT16_VALUE(   669.00), SIMDE_FLOAT16_VALUE(   615.00), SIMDE_FLOAT16_VALUE(   340.00), SIMDE_FLOAT16_VALUE(   389.75) },
      { UINT16_C(  471), UINT16_C(  917), UINT16_C(  484), UINT16_C(  495), UINT16_C(  669), UINT16_C(  615), UINT16_C(  340), UINT16_C(  389) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcvtq_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(0.0f, 1000.0f);
    simde_uint16x8_t r = simde_vcvtq_u16_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(10000.0), SIMDE_MATH_NANF, -SIMDE_MATH_NANF, SIMDE_MATH_INFINITYF },
        {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    #endif
    { { SIMDE_FLOAT32_C(   169.27), SIMDE_FLOAT32_C(   616.25), SIMDE_FLOAT32_C(   454.93), SIMDE_FLOAT32_C(   561.26) },
      { UINT32_C(       169), UINT32_C(       616), UINT32_C(       454), UINT32_C(       561) } },
    { { SIMDE_FLOAT32_C(   148.72), SIMDE_FLOAT32_C(   602.28), SIMDE_FLOAT32_C(   959.49), SIMDE_FLOAT32_C(   218.41) },
      { UINT32_C(       148), UINT32_C(       602), UINT32_C(       959), UINT32_C(       218) } },
    { { SIMDE_FLOAT32_C(   325.37), SIMDE_FLOAT32_C(   686.32), SIMDE_FLOAT32_C(   690.28), SIMDE_FLOAT32_C(    28.98) },
      { UINT32_C(       325), UINT32_C(       686), UINT32_C(       690), UINT32_C(        28) } },
    { { SIMDE_FLOAT32_C(   498.79), SIMDE_FLOAT32_C(   175.99), SIMDE_FLOAT32_C(   426.50), SIMDE_FLOAT32_C(   983.51) },
      { UINT32_C(       498), UINT32_C(       175), UINT32_C(       426), UINT32_C(       983) } },
    { { SIMDE_FLOAT32_C(   813.92), SIMDE_FLOAT32_C(   911.70), SIMDE_FLOAT32_C(   467.12), SIMDE_FLOAT32_C(   500.14) },
      { UINT32_C(       813), UINT32_C(       911), UINT32_C(       467), UINT32_C(       500) } },
    { { SIMDE_FLOAT32_C(   289.14), SIMDE_FLOAT32_C(   483.56), SIMDE_FLOAT32_C(   831.86), SIMDE_FLOAT32_C(   688.26) },
      { UINT32_C(       289), UINT32_C(       483), UINT32_C(       831), UINT32_C(       688) } },
    { { SIMDE_FLOAT32_C(   803.86), SIMDE_FLOAT32_C(   762.17), SIMDE_FLOAT32_C(   408.81), SIMDE_FLOAT32_C(   246.10) },
      { UINT32_C(       803), UINT32_C(       762), UINT32_C(       408), UINT32_C(       246) } },
    { { SIMDE_FLOAT32_C(   985.02), SIMDE_FLOAT32_C(    92.20), SIMDE_FLOAT32_C(   515.77), SIMDE_FLOAT32_C(   154.29) },
      { UINT32_C(       985), UINT32_C(        92), UINT32_C(       515), UINT32_C(       154) } }

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcvtq_u32_f32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT32_C(0.0), SIMDE_FLOAT32_C(1000.0));
    simde_uint32x4_t r = simde_vcvtq_u32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    uint64_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(10000.0) },
        {           UINT64_MAX, UINT64_C(         0) } },
      { {  -SIMDE_MATH_NAN, -SIMDE_FLOAT64_C(10000.0) },
        { UINT64_C(         0), UINT64_C(         0) } },
    #endif
    { { SIMDE_FLOAT64_C(   182.67), SIMDE_FLOAT64_C(   140.69) },
      { UINT64_C(                 182), UINT64_C(                 140) } },
    { { SIMDE_FLOAT64_C(   326.15), SIMDE_FLOAT64_C(   465.87) },
      { UINT64_C(                 326), UINT64_C(                 465) } },
    { { SIMDE_FLOAT64_C(    24.33), SIMDE_FLOAT64_C(   507.60) },
      { UINT64_C(                  24), UINT64_C(                 507) } },
    { { SIMDE_FLOAT64_C(   765.94), SIMDE_FLOAT64_C(   196.40) },
      { UINT64_C(                 765), UINT64_C(                 196) } },
    { { SIMDE_FLOAT64_C(   933.89), SIMDE_FLOAT64_C(   836.65) },
      { UINT64_C(                 933), UINT64_C(                 836) } },
    { { SIMDE_FLOAT64_C(   256.48), SIMDE_FLOAT64_C(   100.64) },
      { UINT64_C(                 256), UINT64_C(                 100) } },
    { { SIMDE_FLOAT64_C(    95.90), SIMDE_FLOAT64_C(   653.31) },
      { UINT64_C(                  95), UINT64_C(                 653) } },
    { { SIMDE_FLOAT64_C(   555.78), SIMDE_FLOAT64_C(   417.32) },
      { UINT64_C(                 555), UINT64_C(                 417) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcvtq_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x2_t r = simde_vcvtq_u64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcvt_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    simde_float16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 31359), -INT16_C(  6060), -INT16_C(  9227),  INT16_C(  4133) },
      { SIMDE_FLOAT16_VALUE(-31360.00), SIMDE_FLOAT16_VALUE( -6060.00), SIMDE_FLOAT16_VALUE( -9224.00), SIMDE_FLOAT16_VALUE(  4132.00) } },
    { { -INT16_C( 17421),  INT16_C( 21634),  INT16_C( 18391), -INT16_C(  9695) },
      { SIMDE_FLOAT16_VALUE(-17424.00), SIMDE_FLOAT16_VALUE( 21632.00), SIMDE_FLOAT16_VALUE( 18384.00), SIMDE_FLOAT16_VALUE( -9696.00) } },
    { { -INT16_C( 18311), -INT16_C( 27399),  INT16_C(   497),  INT16_C( 25119) },
      { SIMDE_FLOAT16_VALUE(-18304.00), SIMDE_FLOAT16_VALUE(-27392.00), SIMDE_FLOAT16_VALUE(   497.00), SIMDE_FLOAT16_VALUE( 25120.00) } },
    { {  INT16_C( 16007), -INT16_C(  5610),  INT16_C( 21305), -INT16_C( 17667) },
      { SIMDE_FLOAT16_VALUE( 16008.00), SIMDE_FLOAT16_VALUE( -5608.00), SIMDE_FLOAT16_VALUE( 21312.00), SIMDE_FLOAT16_VALUE(-17664.00) } },
    { {  INT16_C( 20952), -INT16_C( 12638), -INT16_C( 14292),  INT16_C(  8414) },
      { SIMDE_FLOAT16_VALUE( 20960.00), SIMDE_FLOAT16_VALUE(-12640.00), SIMDE_FLOAT16_VALUE(-14288.00), SIMDE_FLOAT16_VALUE(  8416.00) } },
    { {  INT16_C( 24707),  INT16_C( 23156), -INT16_C( 27225),  INT16_C(  8500) },
      { SIMDE_FLOAT16_VALUE( 24704.00), SIMDE_FLOAT16_VALUE( 23152.00), SIMDE_FLOAT16_VALUE(-27232.00), SIMDE_FLOAT16_VALUE(  8496.00) } },
    { {  INT16_C( 11597),  INT16_C( 16053), -INT16_C( 11218), -INT16_C( 18784) },
      { SIMDE_FLOAT16_VALUE( 11600.00), SIMDE_FLOAT16_VALUE( 16056.00), SIMDE_FLOAT16_VALUE(-11216.00), SIMDE_FLOAT16_VALUE(-18784.00) } },
    { { -INT16_C( 18926),  INT16_C( 19360), -INT16_C( 25335), -INT16_C(  7674) },
      { SIMDE_FLOAT16_VALUE(-18928.00), SIMDE_FLOAT16_VALUE( 19360.00), SIMDE_FLOAT16_VALUE(-25328.00), SIMDE_FLOAT16_VALUE( -7672.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_float16x4_t r = simde_vcvt_f16_s16(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_float16x4_t r = simde_vcvt_f16_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { -INT32_C(  1490815448),  INT32_C(   440787632) },
      { SIMDE_FLOAT32_C(-1490815488.00), SIMDE_FLOAT32_C(440787648.00) } },
    { {  INT32_C(  1033660046),  INT32_C(   730210234) },
      { SIMDE_FLOAT32_C(1033660032.00), SIMDE_FLOAT32_C(730210240.00) } },
    { { -INT32_C(   389361289),  INT32_C(  1176472002) },
      { SIMDE_FLOAT32_C(-389361280.00), SIMDE_FLOAT32_C(1176472064.00) } },
    { { -INT32_C(  1920118894), -INT32_C(   230240567) },
      { SIMDE_FLOAT32_C(-1920118912.00), SIMDE_FLOAT32_C(-230240560.00) } },
    { {  INT32_C(  1956211140), -INT32_C(   644948405) },
      { SIMDE_FLOAT32_C(1956211200.00), SIMDE_FLOAT32_C(-644948416.00) } },
    { { -INT32_C(    32036028), -INT32_C(  1054237366) },
      { SIMDE_FLOAT32_C(-32036028.00), SIMDE_FLOAT32_C(-1054237376.00) } },
    { {  INT32_C(   816444270),  INT32_C(   242665596) },
      { SIMDE_FLOAT32_C(816444288.00), SIMDE_FLOAT32_C(242665600.00) } },
    { { -INT32_C(   509869032), -INT32_C(  1764498734) },
      { SIMDE_FLOAT32_C(-509869024.00), SIMDE_FLOAT32_C(-1764498688.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_float32x2_t r = simde_vcvt_f32_s32(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_float32x2_t r = simde_vcvt_f32_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { -INT64_C( 5637188979182257959) },
      { SIMDE_FLOAT64_C(-5637188979182258176.00) } },
    { { -INT64_C( 1615765083744039100) },
      { SIMDE_FLOAT64_C(-1615765083744039168.00) } },
    { { -INT64_C( 3391338634861752101) },
      { SIMDE_FLOAT64_C(-3391338634861752320.00) } },
    { { -INT64_C( 5913301266420841191) },
      { SIMDE_FLOAT64_C(-5913301266420841472.00) } },
    { { -INT64_C(  494825632698398733) },
      { SIMDE_FLOAT64_C(-494825632698398720.00) } },
    { { -INT64_C( 7406702033022478571) },
      { SIMDE_FLOAT64_C(-7406702033022478336.00) } },
    { { -INT64_C( 2579062017698220053) },
      { SIMDE_FLOAT64_C(-2579062017698220032.00) } },
    { {  INT64_C(  151943772838646681) },
      { SIMDE_FLOAT64_C(151943772838646688.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_float64x1_t r = simde_vcvt_f64_s64(a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_float64x1_t r = simde_vcvt_f64_s64(a);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    simde_float16_t r[4];
  } test_vec[] = {
    { { UINT16_C(62438), UINT16_C(34514), UINT16_C(11502), UINT16_C(61024) },
      { SIMDE_FLOAT16_VALUE( 62432.00), SIMDE_FLOAT16_VALUE( 34528.00), SIMDE_FLOAT16_VALUE( 11504.00), SIMDE_FLOAT16_VALUE( 61024.00) } },
    { { UINT16_C(12845), UINT16_C(46535), UINT16_C(26251), UINT16_C(44421) },
      { SIMDE_FLOAT16_VALUE( 12848.00), SIMDE_FLOAT16_VALUE( 46528.00), SIMDE_FLOAT16_VALUE( 26256.00), SIMDE_FLOAT16_VALUE( 44416.00) } },
    { { UINT16_C(34839), UINT16_C(13721), UINT16_C(21960), UINT16_C(60620) },
      { SIMDE_FLOAT16_VALUE( 34848.00), SIMDE_FLOAT16_VALUE( 13720.00), SIMDE_FLOAT16_VALUE( 21952.00), SIMDE_FLOAT16_VALUE( 60608.00) } },
    { { UINT16_C(12061), UINT16_C(53316), UINT16_C(51121), UINT16_C(38694) },
      { SIMDE_FLOAT16_VALUE( 12064.00), SIMDE_FLOAT16_VALUE( 53312.00), SIMDE_FLOAT16_VALUE( 51136.00), SIMDE_FLOAT16_VALUE( 38688.00) } },
    { { UINT16_C(63674), UINT16_C(43038), UINT16_C(32293), UINT16_C(21142) },
      { SIMDE_FLOAT16_VALUE( 63680.00), SIMDE_FLOAT16_VALUE( 43040.00), SIMDE_FLOAT16_VALUE( 32288.00), SIMDE_FLOAT16_VALUE( 21136.00) } },
    { { UINT16_C(24240), UINT16_C(15111), UINT16_C(36292), UINT16_C(56297) },
      { SIMDE_FLOAT16_VALUE( 24240.00), SIMDE_FLOAT16_VALUE( 15112.00), SIMDE_FLOAT16_VALUE( 36288.00), SIMDE_FLOAT16_VALUE( 56288.00) } },
    { { UINT16_C(33301), UINT16_C(56593), UINT16_C(56792), UINT16_C(62922) },
      { SIMDE_FLOAT16_VALUE( 33312.00), SIMDE_FLOAT16_VALUE( 56608.00), SIMDE_FLOAT16_VALUE( 56800.00), SIMDE_FLOAT16_VALUE( 62912.00) } },
    { { UINT16_C( 3596), UINT16_C(48838), UINT16_C(60629), UINT16_C(36949) },
      { SIMDE_FLOAT16_VALUE(  3596.00), SIMDE_FLOAT16_VALUE( 48832.00), SIMDE_FLOAT16_VALUE( 60640.00), SIMDE_FLOAT16_VALUE( 36960.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_float16x4_t r = simde_vcvt_f16_u16(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_float16x4_t r = simde_vcvt_f16_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcvt_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { UINT32_C(2587932456), UINT32_C( 295281173) },
      { SIMDE_FLOAT32_C(2587932416.00), SIMDE_FLOAT32_C(295281184.00) } },
    { { UINT32_C(3545609472), UINT32_C(2675448399) },
      { SIMDE_FLOAT32_C(3545609472.00), SIMDE_FLOAT32_C(2675448320.00) } },
    { { UINT32_C(2886471787), UINT32_C(3487249558) },
      { SIMDE_FLOAT32_C(2886471680.00), SIMDE_FLOAT32_C(3487249664.00) } },
    { { UINT32_C(4010341369), UINT32_C(2972864136) },
      { SIMDE_FLOAT32_C(4010341376.00), SIMDE_FLOAT32_C(2972864256.00) } },
    { { UINT32_C( 441152005), UINT32_C( 338486292) },
      { SIMDE_FLOAT32_C(441152000.00), SIMDE_FLOAT32_C(338486304.00) } },
    { { UINT32_C(3924328857), UINT32_C( 126378139) },
      { SIMDE_FLOAT32_C(3924328960.00), SIMDE_FLOAT32_C(126378136.00) } },
    { { UINT32_C( 129209456), UINT32_C(3252063944) },
      { SIMDE_FLOAT32_C(129209456.00), SIMDE_FLOAT32_C(3252064000.00) } },
    { { UINT32_C( 179363457), UINT32_C( 851173932) },
      { SIMDE_FLOAT32_C(179363456.00), SIMDE_FLOAT32_C(851173952.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_float32x2_t r = simde_vcvt_f32_u32(a);
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_float32x2_t r = simde_vcvt_f32_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { UINT64_C( 8225907245979072970) },
      { SIMDE_FLOAT64_C(8225907245979072512.00) } },
    { { UINT64_C(16476598577281444883) },
      { SIMDE_FLOAT64_C(16476598577281445888.00) } },
    { { UINT64_C( 4343902165234378246) },
      { SIMDE_FLOAT64_C(4343902165234378240.00) } },
    { { UINT64_C(15500192606257303370) },
      { SIMDE_FLOAT64_C(15500192606257303552.00) } },
    { { UINT64_C( 6717319276498190264) },
      { SIMDE_FLOAT64_C(6717319276498190336.00) } },
    { { UINT64_C( 8350517506981939683) },
      { SIMDE_FLOAT64_C(8350517506981939200.00) } },
    { { UINT64_C(12151509346023160421) },
      { SIMDE_FLOAT64_C(12151509346023159808.00) } },
    { { UINT64_C( 3677480995464854564) },
      { SIMDE_FLOAT64_C(3677480995464854528.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_float64x1_t r = simde_vcvt_f64_u64(a);
    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_float64x1_t r = simde_vcvt_f64_u64(a);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcvtq_f16_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    simde_float16_t r[8];
  } test_vec[] = {
     { {  INT16_C( 30695),  INT16_C(  2044), -INT16_C( 17659), -INT16_C( 13466), -INT16_C(  7782), -INT16_C( 26595),  INT16_C( 28844),  INT16_C(  8813) },
      { SIMDE_FLOAT16_VALUE( 30688.00), SIMDE_FLOAT16_VALUE(  2044.00), SIMDE_FLOAT16_VALUE(-17664.00), SIMDE_FLOAT16_VALUE(-13464.00),
        SIMDE_FLOAT16_VALUE( -7784.00), SIMDE_FLOAT16_VALUE(-26592.00), SIMDE_FLOAT16_VALUE( 28848.00), SIMDE_FLOAT16_VALUE(  8816.00) } },
    { { -INT16_C( 23007),  INT16_C( 14781), -INT16_C( 26182), -INT16_C( 15014),  INT16_C( 16220),  INT16_C( 16254), -INT16_C(  2052), -INT16_C(  7328) },
      { SIMDE_FLOAT16_VALUE(-23008.00), SIMDE_FLOAT16_VALUE( 14784.00), SIMDE_FLOAT16_VALUE(-26176.00), SIMDE_FLOAT16_VALUE(-15016.00),
        SIMDE_FLOAT16_VALUE( 16224.00), SIMDE_FLOAT16_VALUE( 16256.00), SIMDE_FLOAT16_VALUE( -2052.00), SIMDE_FLOAT16_VALUE( -7328.00) } },
    { {  INT16_C( 23919),  INT16_C( 29930),  INT16_C( 20504), -INT16_C( 19904),  INT16_C( 23857), -INT16_C(  8886), -INT16_C( 18483), -INT16_C(  4608) },
      { SIMDE_FLOAT16_VALUE( 23920.00), SIMDE_FLOAT16_VALUE( 29936.00), SIMDE_FLOAT16_VALUE( 20512.00), SIMDE_FLOAT16_VALUE(-19904.00),
        SIMDE_FLOAT16_VALUE( 23856.00), SIMDE_FLOAT16_VALUE( -8888.00), SIMDE_FLOAT16_VALUE(-18480.00), SIMDE_FLOAT16_VALUE( -4608.00) } },
    { { -INT16_C( 17058),  INT16_C(  6184), -INT16_C( 32170), -INT16_C( 19491),  INT16_C( 23745), -INT16_C( 16910),  INT16_C( 21075), -INT16_C( 15712) },
      { SIMDE_FLOAT16_VALUE(-17056.00), SIMDE_FLOAT16_VALUE(  6184.00), SIMDE_FLOAT16_VALUE(-32176.00), SIMDE_FLOAT16_VALUE(-19488.00),
        SIMDE_FLOAT16_VALUE( 23744.00), SIMDE_FLOAT16_VALUE(-16912.00), SIMDE_FLOAT16_VALUE( 21072.00), SIMDE_FLOAT16_VALUE(-15712.00) } },
    { { -INT16_C( 30033), -INT16_C( 14537),  INT16_C( 30683),  INT16_C(  3194), -INT16_C( 15148), -INT16_C( 24086), -INT16_C(  5508), -INT16_C(  9585) },
      { SIMDE_FLOAT16_VALUE(-30032.00), SIMDE_FLOAT16_VALUE(-14536.00), SIMDE_FLOAT16_VALUE( 30688.00), SIMDE_FLOAT16_VALUE(  3194.00),
        SIMDE_FLOAT16_VALUE(-15152.00), SIMDE_FLOAT16_VALUE(-24080.00), SIMDE_FLOAT16_VALUE( -5508.00), SIMDE_FLOAT16_VALUE( -9584.00) } },
    { { -INT16_C( 18521), -INT16_C(   526), -INT16_C( 12231), -INT16_C(  1360), -INT16_C( 24020),  INT16_C( 32695),  INT16_C( 22517), -INT16_C( 23486) },
      { SIMDE_FLOAT16_VALUE(-18528.00), SIMDE_FLOAT16_VALUE(  -526.00), SIMDE_FLOAT16_VALUE(-12232.00), SIMDE_FLOAT16_VALUE( -1360.00),
        SIMDE_FLOAT16_VALUE(-24016.00), SIMDE_FLOAT16_VALUE( 32688.00), SIMDE_FLOAT16_VALUE( 22512.00), SIMDE_FLOAT16_VALUE(-23488.00) } },
    { {  INT16_C( 31202), -INT16_C( 17044), -INT16_C(  6416), -INT16_C( 15159), -INT16_C( 19542),  INT16_C(  9829), -INT16_C(  2915),  INT16_C( 17408) },
      { SIMDE_FLOAT16_VALUE( 31200.00), SIMDE_FLOAT16_VALUE(-17040.00), SIMDE_FLOAT16_VALUE( -6416.00), SIMDE_FLOAT16_VALUE(-15160.00),
        SIMDE_FLOAT16_VALUE(-19536.00), SIMDE_FLOAT16_VALUE(  9832.00), SIMDE_FLOAT16_VALUE( -2916.00), SIMDE_FLOAT16_VALUE( 17408.00) } },
    { { -INT16_C(  3156), -INT16_C(  6846), -INT16_C(  3389), -INT16_C(  4128), -INT16_C( 26731), -INT16_C( 30098), -INT16_C( 20241), -INT16_C( 11986) },
      { SIMDE_FLOAT16_VALUE( -3156.00), SIMDE_FLOAT16_VALUE( -6848.00), SIMDE_FLOAT16_VALUE( -3388.00), SIMDE_FLOAT16_VALUE( -4128.00),
        SIMDE_FLOAT16_VALUE(-26736.00), SIMDE_FLOAT16_VALUE(-30096.00), SIMDE_FLOAT16_VALUE(-20240.00), SIMDE_FLOAT16_VALUE(-11984.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_float16x8_t r = simde_vcvtq_f16_s16(a);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_float16x8_t r = simde_vcvtq_f16_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    simde_float32 r[4];
  } test_vec[] = {
    { {  INT32_C(   582805677),  INT32_C(  1143681869),  INT32_C(  1367472729), -INT32_C(  1370995331) },
      { SIMDE_FLOAT32_C(582805696.00), SIMDE_FLOAT32_C(1143681920.00), SIMDE_FLOAT32_C(1367472768.00), SIMDE_FLOAT32_C(-1370995328.00) } },
    { {  INT32_C(  1359924217), -INT32_C(  1396830435),  INT32_C(   904922231),  INT32_C(   168727901) },
      { SIMDE_FLOAT32_C(1359924224.00), SIMDE_FLOAT32_C(-1396830464.00), SIMDE_FLOAT32_C(904922240.00), SIMDE_FLOAT32_C(168727904.00) } },
    { { -INT32_C(   886257026),  INT32_C(  1443846141), -INT32_C(   811101870), -INT32_C(   797052970) },
      { SIMDE_FLOAT32_C(-886257024.00), SIMDE_FLOAT32_C(1443846144.00), SIMDE_FLOAT32_C(-811101888.00), SIMDE_FLOAT32_C(-797052992.00) } },
    { { -INT32_C(   685667398),  INT32_C(   293920666),  INT32_C(  1078359267), -INT32_C(  2008328950) },
      { SIMDE_FLOAT32_C(-685667392.00), SIMDE_FLOAT32_C(293920672.00), SIMDE_FLOAT32_C(1078359296.00), SIMDE_FLOAT32_C(-2008328960.00) } },
    { {  INT32_C(   492009247),  INT32_C(   561210063), -INT32_C(   890233869), -INT32_C(   979735286) },
      { SIMDE_FLOAT32_C(492009248.00), SIMDE_FLOAT32_C(561210048.00), SIMDE_FLOAT32_C(-890233856.00), SIMDE_FLOAT32_C(-979735296.00) } },
    { { -INT32_C(  1835222024),  INT32_C(  2107908250), -INT32_C(  1614878059),  INT32_C(  1596393791) },
      { SIMDE_FLOAT32_C(-1835222016.00), SIMDE_FLOAT32_C(2107908224.00), SIMDE_FLOAT32_C(-1614878080.00), SIMDE_FLOAT32_C(1596393728.00) } },
    { {  INT32_C(  1333557888), -INT32_C(   797904932),  INT32_C(   362438666), -INT32_C(   975555379) },
      { SIMDE_FLOAT32_C(1333557888.00), SIMDE_FLOAT32_C(-797904960.00), SIMDE_FLOAT32_C(362438656.00), SIMDE_FLOAT32_C(-975555392.00) } },
    { { -INT32_C(  1990691089),  INT32_C(   738655383),  INT32_C(   650888422),  INT32_C(  1317401293) },
      { SIMDE_FLOAT32_C(-1990691072.00), SIMDE_FLOAT32_C(738655360.00), SIMDE_FLOAT32_C(650888448.00), SIMDE_FLOAT32_C(1317401344.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_float32x4_t r = simde_vcvtq_f32_s32(a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_float32x4_t r = simde_vcvtq_f32_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { -INT64_C( 5437369519729810865),  INT64_C( 7901797256341896009) },
      { SIMDE_FLOAT64_C(-5437369519729810432.00), SIMDE_FLOAT64_C(7901797256341896192.00) } },
    { { -INT64_C( 7839088714326884250),  INT64_C(  640569667726039958) },
      { SIMDE_FLOAT64_C(-7839088714326884352.00), SIMDE_FLOAT64_C(640569667726039936.00) } },
    { { -INT64_C( 5074851512610989404),  INT64_C( 3884241220501831100) },
      { SIMDE_FLOAT64_C(-5074851512610989056.00), SIMDE_FLOAT64_C(3884241220501831168.00) } },
    { {  INT64_C( 4054477313972153432),  INT64_C( 6809766693901170880) },
      { SIMDE_FLOAT64_C(4054477313972153344.00), SIMDE_FLOAT64_C(6809766693901170688.00) } },
    { { -INT64_C( 5392550408562575359),  INT64_C(  779428067380435404) },
      { SIMDE_FLOAT64_C(-5392550408562575360.00), SIMDE_FLOAT64_C(779428067380435456.00) } },
    { {  INT64_C( 2926214301938811585),  INT64_C(  436886571722072056) },
      { SIMDE_FLOAT64_C(2926214301938811392.00), SIMDE_FLOAT64_C(436886571722072064.00) } },
    { { -INT64_C( 1636882415660610150),  INT64_C( 5581745048800032442) },
      { SIMDE_FLOAT64_C(-1636882415660610048.00), SIMDE_FLOAT64_C(5581745048800032768.00) } },
    { {  INT64_C( 3091806024566387289),  INT64_C( 4987996807332923692) },
      { SIMDE_FLOAT64_C(3091806024566387200.00), SIMDE_FLOAT64_C(4987996807332923392.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_float64x2_t r = simde_vcvtq_f64_s64(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_float64x2_t r = simde_vcvtq_f64_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    simde_float16_t r[8];
  } test_vec[] = {
    { { UINT16_C(31719), UINT16_C(40615), UINT16_C(25989), UINT16_C(34272), UINT16_C(12352), UINT16_C(55680), UINT16_C(60433), UINT16_C(10783) },
      { SIMDE_FLOAT16_VALUE( 31712.00), SIMDE_FLOAT16_VALUE( 40608.00), SIMDE_FLOAT16_VALUE( 25984.00), SIMDE_FLOAT16_VALUE( 34272.00),
        SIMDE_FLOAT16_VALUE( 12352.00), SIMDE_FLOAT16_VALUE( 55680.00), SIMDE_FLOAT16_VALUE( 60448.00), SIMDE_FLOAT16_VALUE( 10784.00) } },
    { { UINT16_C( 5224), UINT16_C(60599), UINT16_C(11648), UINT16_C(19599), UINT16_C( 3068), UINT16_C(27332), UINT16_C(15393), UINT16_C( 2080) },
      { SIMDE_FLOAT16_VALUE(  5224.00), SIMDE_FLOAT16_VALUE( 60608.00), SIMDE_FLOAT16_VALUE( 11648.00), SIMDE_FLOAT16_VALUE( 19600.00),
        SIMDE_FLOAT16_VALUE(  3068.00), SIMDE_FLOAT16_VALUE( 27328.00), SIMDE_FLOAT16_VALUE( 15392.00), SIMDE_FLOAT16_VALUE(  2080.00) } },
    { { UINT16_C(51383), UINT16_C(15782), UINT16_C(34605), UINT16_C(28354), UINT16_C(17079), UINT16_C(51271), UINT16_C(26158), UINT16_C(38642) },
      { SIMDE_FLOAT16_VALUE( 51392.00), SIMDE_FLOAT16_VALUE( 15784.00), SIMDE_FLOAT16_VALUE( 34592.00), SIMDE_FLOAT16_VALUE( 28352.00),
        SIMDE_FLOAT16_VALUE( 17072.00), SIMDE_FLOAT16_VALUE( 51264.00), SIMDE_FLOAT16_VALUE( 26160.00), SIMDE_FLOAT16_VALUE( 38656.00) } },
    { { UINT16_C(43387), UINT16_C(64386), UINT16_C( 4822), UINT16_C(53831), UINT16_C( 2845), UINT16_C(15932), UINT16_C(23623), UINT16_C(65351) },
      { SIMDE_FLOAT16_VALUE( 43392.00), SIMDE_FLOAT16_VALUE( 64384.00), SIMDE_FLOAT16_VALUE(  4824.00), SIMDE_FLOAT16_VALUE( 53824.00),
        SIMDE_FLOAT16_VALUE(  2844.00), SIMDE_FLOAT16_VALUE( 15936.00), SIMDE_FLOAT16_VALUE( 23616.00), SIMDE_FLOAT16_VALUE( 65344.00) } },
    { { UINT16_C(60708), UINT16_C(21052), UINT16_C(65140), UINT16_C(11200), UINT16_C( 1856), UINT16_C(28659), UINT16_C(58734), UINT16_C(59653) },
      { SIMDE_FLOAT16_VALUE( 60704.00), SIMDE_FLOAT16_VALUE( 21056.00), SIMDE_FLOAT16_VALUE( 65152.00), SIMDE_FLOAT16_VALUE( 11200.00),
        SIMDE_FLOAT16_VALUE(  1856.00), SIMDE_FLOAT16_VALUE( 28656.00), SIMDE_FLOAT16_VALUE( 58720.00), SIMDE_FLOAT16_VALUE( 59648.00) } },
    { { UINT16_C(34958), UINT16_C(25828), UINT16_C(11162), UINT16_C(46902), UINT16_C(29238), UINT16_C(32245), UINT16_C(15567), UINT16_C(62332) },
      { SIMDE_FLOAT16_VALUE( 34944.00), SIMDE_FLOAT16_VALUE( 25824.00), SIMDE_FLOAT16_VALUE( 11160.00), SIMDE_FLOAT16_VALUE( 46912.00),
        SIMDE_FLOAT16_VALUE( 29232.00), SIMDE_FLOAT16_VALUE( 32240.00), SIMDE_FLOAT16_VALUE( 15568.00), SIMDE_FLOAT16_VALUE( 62336.00) } },
    { { UINT16_C(47146), UINT16_C(40517), UINT16_C( 1462), UINT16_C(63434), UINT16_C(48397), UINT16_C(31590), UINT16_C(27555), UINT16_C(12644) },
      { SIMDE_FLOAT16_VALUE( 47136.00), SIMDE_FLOAT16_VALUE( 40512.00), SIMDE_FLOAT16_VALUE(  1462.00), SIMDE_FLOAT16_VALUE( 63424.00),
        SIMDE_FLOAT16_VALUE( 48384.00), SIMDE_FLOAT16_VALUE( 31584.00), SIMDE_FLOAT16_VALUE( 27552.00), SIMDE_FLOAT16_VALUE( 12640.00) } },
    { { UINT16_C(18675), UINT16_C(36246), UINT16_C(52339), UINT16_C(43332), UINT16_C(14911), UINT16_C( 3622), UINT16_C(41846), UINT16_C(40961) },
      { SIMDE_FLOAT16_VALUE( 18672.00), SIMDE_FLOAT16_VALUE( 36256.00), SIMDE_FLOAT16_VALUE( 52352.00), SIMDE_FLOAT16_VALUE( 43328.00),
        SIMDE_FLOAT16_VALUE( 14912.00), SIMDE_FLOAT16_VALUE(  3622.00), SIMDE_FLOAT16_VALUE( 41856.00), SIMDE_FLOAT16_VALUE( 40960.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_float16x8_t r = simde_vcvtq_f16_u16(a);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_float16x8_t r = simde_vcvtq_f16_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { UINT32_C(2742190227), UINT32_C(1279879163), UINT32_C(1560757930), UINT32_C(2555284292) },
      { SIMDE_FLOAT32_C(2742190336.00), SIMDE_FLOAT32_C(1279879168.00), SIMDE_FLOAT32_C(1560757888.00), SIMDE_FLOAT32_C(2555284224.00) } },
    { { UINT32_C( 314328964), UINT32_C(1716492923), UINT32_C(2449736314), UINT32_C(4182169446) },
      { SIMDE_FLOAT32_C(314328960.00), SIMDE_FLOAT32_C(1716492928.00), SIMDE_FLOAT32_C(2449736192.00), SIMDE_FLOAT32_C(4182169344.00) } },
    { { UINT32_C(1386068055), UINT32_C(3382634015), UINT32_C(1881646636), UINT32_C(3037230385) },
      { SIMDE_FLOAT32_C(1386068096.00), SIMDE_FLOAT32_C(3382633984.00), SIMDE_FLOAT32_C(1881646592.00), SIMDE_FLOAT32_C(3037230336.00) } },
    { { UINT32_C( 952681917), UINT32_C(3667793759), UINT32_C(2137826073), UINT32_C(3514348154) },
      { SIMDE_FLOAT32_C(952681920.00), SIMDE_FLOAT32_C(3667793664.00), SIMDE_FLOAT32_C(2137826048.00), SIMDE_FLOAT32_C(3514348032.00) } },
    { { UINT32_C(2317620586), UINT32_C( 676578043), UINT32_C(2593684072), UINT32_C(2907677168) },
      { SIMDE_FLOAT32_C(2317620480.00), SIMDE_FLOAT32_C(676578048.00), SIMDE_FLOAT32_C(2593683968.00), SIMDE_FLOAT32_C(2907677184.00) } },
    { { UINT32_C(3320125286), UINT32_C(1201636142), UINT32_C(2697333798), UINT32_C( 695353278) },
      { SIMDE_FLOAT32_C(3320125184.00), SIMDE_FLOAT32_C(1201636096.00), SIMDE_FLOAT32_C(2697333760.00), SIMDE_FLOAT32_C(695353280.00) } },
    { { UINT32_C(1353946708), UINT32_C(3245868632), UINT32_C(1901793409), UINT32_C( 387885745) },
      { SIMDE_FLOAT32_C(1353946752.00), SIMDE_FLOAT32_C(3245868544.00), SIMDE_FLOAT32_C(1901793408.00), SIMDE_FLOAT32_C(387885760.00) } },
    { { UINT32_C(4041016258), UINT32_C(2906160262), UINT32_C(1196293768), UINT32_C(2456862525) },
      { SIMDE_FLOAT32_C(4041016320.00), SIMDE_FLOAT32_C(2906160384.00), SIMDE_FLOAT32_C(1196293760.00), SIMDE_FLOAT32_C(2456862464.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_float32x4_t r = simde_vcvtq_f32_u32(a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_float32x4_t r = simde_vcvtq_f32_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { UINT64_C(13683682593130234659), UINT64_C(11559544905560819710) },
      { SIMDE_FLOAT64_C(13683682593130233856.00), SIMDE_FLOAT64_C(11559544905560819712.00) } },
    { { UINT64_C( 8936905941469911567), UINT64_C( 3558395723382130100) },
      { SIMDE_FLOAT64_C(8936905941469912064.00), SIMDE_FLOAT64_C(3558395723382130176.00) } },
    { { UINT64_C( 5604675100166593081), UINT64_C(13208615328365603029) },
      { SIMDE_FLOAT64_C(5604675100166593536.00), SIMDE_FLOAT64_C(13208615328365602816.00) } },
    { { UINT64_C(12384439342403662536), UINT64_C( 9485622372482503779) },
      { SIMDE_FLOAT64_C(12384439342403661824.00), SIMDE_FLOAT64_C(9485622372482504704.00) } },
    { { UINT64_C( 3344579514495568845), UINT64_C(11717851499640679486) },
      { SIMDE_FLOAT64_C(3344579514495568896.00), SIMDE_FLOAT64_C(11717851499640680448.00) } },
    { { UINT64_C(13150759761589106141), UINT64_C( 5909789806474809654) },
      { SIMDE_FLOAT64_C(13150759761589106688.00), SIMDE_FLOAT64_C(5909789806474809344.00) } },
    { { UINT64_C( 2728575438831915349), UINT64_C(14033684711101675845) },
      { SIMDE_FLOAT64_C(2728575438831915520.00), SIMDE_FLOAT64_C(14033684711101675520.00) } },
    { { UINT64_C(15972040989054780831), UINT64_C(17275351436999118824) },
      { SIMDE_FLOAT64_C(15972040989054781440.00), SIMDE_FLOAT64_C(17275351436999118848.00) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_float64x2_t r = simde_vcvtq_f64_u64(a);
    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_float64x2_t r = simde_vcvtq_f64_u64(a);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vcvt_f16_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -746.01), SIMDE_FLOAT32_C(    46.71), SIMDE_FLOAT32_C(   209.49), SIMDE_FLOAT32_C(  -407.21) },
      { SIMDE_FLOAT16_VALUE(  -746.00), SIMDE_FLOAT16_VALUE(    46.72), SIMDE_FLOAT16_VALUE(   209.50), SIMDE_FLOAT16_VALUE(  -407.25) } },
    { { SIMDE_FLOAT32_C(  -250.56), SIMDE_FLOAT32_C(  -515.50), SIMDE_FLOAT32_C(  -893.59), SIMDE_FLOAT32_C(  -958.74) },
      { SIMDE_FLOAT16_VALUE(  -250.50), SIMDE_FLOAT16_VALUE(  -515.50), SIMDE_FLOAT16_VALUE(  -893.50), SIMDE_FLOAT16_VALUE(  -958.50) } },
    { { SIMDE_FLOAT32_C(   290.93), SIMDE_FLOAT32_C(  -154.97), SIMDE_FLOAT32_C(  -692.78), SIMDE_FLOAT32_C(   121.78) },
      { SIMDE_FLOAT16_VALUE(   291.00), SIMDE_FLOAT16_VALUE(  -155.00), SIMDE_FLOAT16_VALUE(  -693.00), SIMDE_FLOAT16_VALUE(   121.75) } },
    { { SIMDE_FLOAT32_C(   544.06), SIMDE_FLOAT32_C(  -720.37), SIMDE_FLOAT32_C(   529.59), SIMDE_FLOAT32_C(   595.99) },
      { SIMDE_FLOAT16_VALUE(   544.00), SIMDE_FLOAT16_VALUE(  -720.50), SIMDE_FLOAT16_VALUE(   529.50), SIMDE_FLOAT16_VALUE(   596.00) } },
    { { SIMDE_FLOAT32_C(   724.87), SIMDE_FLOAT32_C(  -105.71), SIMDE_FLOAT32_C(   -64.08), SIMDE_FLOAT32_C(   347.70) },
      { SIMDE_FLOAT16_VALUE(   725.00), SIMDE_FLOAT16_VALUE(  -105.69), SIMDE_FLOAT16_VALUE(   -64.06), SIMDE_FLOAT16_VALUE(   347.75) } },
    { { SIMDE_FLOAT32_C(  -299.90), SIMDE_FLOAT32_C(   477.20), SIMDE_FLOAT32_C(   358.42), SIMDE_FLOAT32_C(  -777.66) },
      { SIMDE_FLOAT16_VALUE(  -300.00), SIMDE_FLOAT16_VALUE(   477.25), SIMDE_FLOAT16_VALUE(   358.50), SIMDE_FLOAT16_VALUE(  -777.50) } },
    { { SIMDE_FLOAT32_C(  -829.48), SIMDE_FLOAT32_C(  -168.37), SIMDE_FLOAT32_C(  -205.50), SIMDE_FLOAT32_C(  -615.00) },
      { SIMDE_FLOAT16_VALUE(  -829.50), SIMDE_FLOAT16_VALUE(  -168.38), SIMDE_FLOAT16_VALUE(  -205.50), SIMDE_FLOAT16_VALUE(  -615.00) } },
    { { SIMDE_FLOAT32_C(  -491.32), SIMDE_FLOAT32_C(   717.47), SIMDE_FLOAT32_C(  -341.53), SIMDE_FLOAT32_C(  -237.33) },
      { SIMDE_FLOAT16_VALUE(  -491.25), SIMDE_FLOAT16_VALUE(   717.50), SIMDE_FLOAT16_VALUE(  -341.50), SIMDE_FLOAT16_VALUE(  -237.38) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float16x4_t r = simde_vcvt_f16_f32(a);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float16x4_t r = simde_vcvt_f16_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f32_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -475.38), SIMDE_FLOAT64_C(   886.87) },
      { SIMDE_FLOAT32_C(  -475.38), SIMDE_FLOAT32_C(   886.87) } },
    { { SIMDE_FLOAT64_C(  -793.59), SIMDE_FLOAT64_C(   367.52) },
      { SIMDE_FLOAT32_C(  -793.59), SIMDE_FLOAT32_C(   367.52) } },
    { { SIMDE_FLOAT64_C(   983.13), SIMDE_FLOAT64_C(   575.97) },
      { SIMDE_FLOAT32_C(   983.13), SIMDE_FLOAT32_C(   575.97) } },
    { { SIMDE_FLOAT64_C(   956.07), SIMDE_FLOAT64_C(   657.42) },
      { SIMDE_FLOAT32_C(   956.07), SIMDE_FLOAT32_C(   657.42) } },
    { { SIMDE_FLOAT64_C(  -938.85), SIMDE_FLOAT64_C(  -480.84) },
      { SIMDE_FLOAT32_C(  -938.85), SIMDE_FLOAT32_C(  -480.84) } },
    { { SIMDE_FLOAT64_C(  -623.90), SIMDE_FLOAT64_C(   584.54) },
      { SIMDE_FLOAT32_C(  -623.90), SIMDE_FLOAT32_C(   584.54) } },
    { { SIMDE_FLOAT64_C(   337.24), SIMDE_FLOAT64_C(   283.98) },
      { SIMDE_FLOAT32_C(   337.24), SIMDE_FLOAT32_C(   283.98) } },
    { { SIMDE_FLOAT64_C(  -235.16), SIMDE_FLOAT64_C(  -429.01) },
      { SIMDE_FLOAT32_C(  -235.16), SIMDE_FLOAT32_C(  -429.01) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float32x2_t r = simde_vcvt_f32_f64(a);
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float32x2_t r = simde_vcvt_f32_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f64_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -80.80), SIMDE_FLOAT32_C(   420.29) },
      { SIMDE_FLOAT64_C(   -80.80), SIMDE_FLOAT64_C(   420.29) } },
    { { SIMDE_FLOAT32_C(  -189.50), SIMDE_FLOAT32_C(   938.42) },
      { SIMDE_FLOAT64_C(  -189.50), SIMDE_FLOAT64_C(   938.42) } },
    { { SIMDE_FLOAT32_C(   592.79), SIMDE_FLOAT32_C(   535.92) },
      { SIMDE_FLOAT64_C(   592.79), SIMDE_FLOAT64_C(   535.92) } },
    { { SIMDE_FLOAT32_C(  -923.38), SIMDE_FLOAT32_C(    26.50) },
      { SIMDE_FLOAT64_C(  -923.38), SIMDE_FLOAT64_C(    26.50) } },
    { { SIMDE_FLOAT32_C(   809.92), SIMDE_FLOAT32_C(   305.32) },
      { SIMDE_FLOAT64_C(   809.92), SIMDE_FLOAT64_C(   305.32) } },
    { { SIMDE_FLOAT32_C(  -969.35), SIMDE_FLOAT32_C(  -734.75) },
      { SIMDE_FLOAT64_C(  -969.35), SIMDE_FLOAT64_C(  -734.75) } },
    { { SIMDE_FLOAT32_C(  -796.75), SIMDE_FLOAT32_C(  -433.35) },
      { SIMDE_FLOAT64_C(  -796.75), SIMDE_FLOAT64_C(  -433.35) } },
    { { SIMDE_FLOAT32_C(  -940.41), SIMDE_FLOAT32_C(  -742.37) },
      { SIMDE_FLOAT64_C(  -940.41), SIMDE_FLOAT64_C(  -742.37) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float64x2_t r = simde_vcvt_f64_f32(a);
    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_float64x2_t r = simde_vcvt_f64_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtah_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    int16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         INT16_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT16_MAX)),
                 INT16_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT16_MIN)),
                 INT16_MIN },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT16_MAX+1000)),
                 INT16_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT16_MIN-1000)),
                 INT16_MIN },
    #endif
    {   SIMDE_FLOAT16_VALUE( -   2.161),
        -INT16_C(       2) },
    {    SIMDE_FLOAT16_VALUE(   6.927),
         INT16_C(       7) },
    {   SIMDE_FLOAT16_VALUE( -  22.166),
        -INT16_C(      22) },
    {    SIMDE_FLOAT16_VALUE(  24.050),
         INT16_C(      24) },
    {    SIMDE_FLOAT16_VALUE(   3.665),
         INT16_C(       4) },
    {   SIMDE_FLOAT16_VALUE( -  16.715),
        -INT16_C(      17) },
    {    SIMDE_FLOAT16_VALUE(   0.250),
         INT16_C(       0) },
    {   SIMDE_FLOAT16_VALUE( -   3.303),
        -INT16_C(       3) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int16_t r = simde_vcvtah_s16_f16(a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int16_t r = simde_vcvtah_s16_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtah_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint16_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         UINT16_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, UINT16_MAX)),
                 UINT16_MAX },
    {    SIMDE_FLOAT16_VALUE(  0.0),
         UINT16_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, UINT16_MAX+1000)),
                 UINT16_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, -1000)),
         UINT16_C(       0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(  19.373),
         UINT16_C(      19) },
    {    SIMDE_FLOAT16_VALUE(   1.450),
         UINT16_C(       1) },
    {    SIMDE_FLOAT16_VALUE(  13.179),
         UINT16_C(      13) },
    {    SIMDE_FLOAT16_VALUE(  11.179),
         UINT16_C(      11) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint16_t r = simde_vcvtah_u16_f16(a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint16_t r = simde_vcvtah_u16_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtah_s32_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         INT32_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT32_MAX)),
                 INT32_MAX },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT32_MAX+1000ll)),
                 INT32_MAX },
    {    SIMDE_FLOAT16_VALUE(  0.0),
         INT32_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT32_MIN)),
                 INT32_MIN },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT32_MIN-1000ll)),
                 INT32_MIN },
    #endif
    {    SIMDE_FLOAT16_VALUE(  18.628),
         INT32_C(      19) },
    {   SIMDE_FLOAT16_VALUE( -  22.354),
        -INT32_C(      22) },
    {   SIMDE_FLOAT16_VALUE( -  24.547),
        -INT32_C(      25) },
    {    SIMDE_FLOAT16_VALUE(   1.754),
         INT32_C(       2) },
    {    SIMDE_FLOAT16_VALUE(  17.010),
         INT32_C(      17) },
    {    SIMDE_FLOAT16_VALUE(  10.181),
         INT32_C(      10) },
    {    SIMDE_FLOAT16_VALUE(   4.337),
         INT32_C(       4) },
    {    SIMDE_FLOAT16_VALUE(  15.753),
         INT32_C(      16) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int32_t r = simde_vcvtah_s32_f16(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int32_t r = simde_vcvtah_s32_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtah_u32_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         UINT32_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, UINT32_MAX)),
                 UINT32_MAX },
    {    SIMDE_FLOAT16_VALUE(  0.0),
         UINT32_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, UINT32_MAX+1000ll)),
                 UINT32_MAX },
    {   SIMDE_FLOAT16_VALUE( -  24.202),
         UINT32_C(       0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(   8.537),
         UINT32_C(       9) },
    {    SIMDE_FLOAT16_VALUE(  25.260),
         UINT32_C(      25) },
    {    SIMDE_FLOAT16_VALUE(  29.793),
         UINT32_C(      30) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint32_t r = simde_vcvtah_u32_f16(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint32_t r = simde_vcvtah_u32_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtah_s64_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    int64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         INT64_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT64_MAX)),
                 INT64_MAX },
    {    SIMDE_FLOAT16_VALUE(  0.0),
         INT64_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, INT64_MIN)),
                 INT64_MIN },
    #endif
    {    SIMDE_FLOAT16_VALUE(  12.535),
         INT64_C(      13) },
    {   SIMDE_FLOAT16_VALUE( -   6.257),
        -INT64_C(       6) },
    {    SIMDE_FLOAT16_VALUE(  10.120),
         INT64_C(      10) },
    {    SIMDE_FLOAT16_VALUE(  10.746),
         INT64_C(      11) },
    {    SIMDE_FLOAT16_VALUE(  25.689),
         INT64_C(      26) },
    {    SIMDE_FLOAT16_VALUE(   7.095),
         INT64_C(       7) },
    {    SIMDE_FLOAT16_VALUE(   9.180),
         INT64_C(       9) },
    {   SIMDE_FLOAT16_VALUE( -  10.937),
        -INT64_C(      11) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    int64_t r = simde_vcvtah_s64_f16(a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_int64_t r = simde_vcvtah_s64_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtah_u64_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    {    SIMDE_NANHF,
         UINT64_C(       0) },
    {    simde_float16_from_float32(HEDLEY_STATIC_CAST(simde_float32_t, UINT64_MAX)),
                 UINT64_MAX },
    {    SIMDE_FLOAT16_VALUE(  0.0),
         UINT64_C(       0) },
    {   SIMDE_FLOAT16_VALUE( -24.202),
         UINT64_C(       0) },
    #endif
    {    SIMDE_FLOAT16_VALUE(       4.300),
         UINT64_C(           4) },
    {    SIMDE_FLOAT16_VALUE(      11.343),
         UINT64_C(          11) },
    {    SIMDE_FLOAT16_VALUE(      26.432),
         UINT64_C(          26) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16_t a = test_vec[i].a;
    uint64_t r = simde_vcvtah_u64_f16(a);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_arm_neon_random_f16(-100.0f, 100.0f);
    simde_uint64_t r = simde_vcvtah_u64_f16(a);

    simde_test_arm_neon_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtas_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    int32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        INT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX),
                    INT32_MAX },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                    INT32_MAX },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MIN),
                    INT32_MIN },
      { HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) - SIMDE_FLOAT32_C(1000.0),
                    INT32_MIN },
    #endif
    { SIMDE_FLOAT32_C(-55.5),
      -INT32_C(56)  },
    { SIMDE_FLOAT32_C(55.5),
       INT32_C(56)  },
    { SIMDE_FLOAT32_C(-755.699707),
      -INT32_C(756)  },
    { SIMDE_FLOAT32_C(-479.408081),
      -INT32_C(479)  },
    { SIMDE_FLOAT32_C(-192.237427),
      -INT32_C(192)  },
    { SIMDE_FLOAT32_C(92.246948),
      INT32_C(92)  },
    { SIMDE_FLOAT32_C(-620.131226),
      -INT32_C(620)  },
    { SIMDE_FLOAT32_C(658.543213),
      INT32_C(659)  },
    { SIMDE_FLOAT32_C(-58.790283),
      -INT32_C(59)  },
    { SIMDE_FLOAT32_C(-777.055359),
      -INT32_C(777)  },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    int32_t r = simde_vcvtas_s32_f32(a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_arm_neon_random_f32(-1000.0f, 1000.0f);
    simde_int32_t r = simde_vcvtas_s32_f32(a);

    simde_test_arm_neon_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtas_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a;
    uint32_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NANF,
        UINT32_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(1000.0),
                    UINT32_MAX },
      { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX),
                    UINT32_MAX },
      {       SIMDE_MATH_INFINITYF,
        UINT32_MAX },
    #endif
    { SIMDE_FLOAT32_C(238.269043),
      UINT32_C(238)  },
    { SIMDE_FLOAT32_C(884.073364),
      UINT32_C(884)  },
    { SIMDE_FLOAT32_C(517.341492),
      UINT32_C(517)  },
    { SIMDE_FLOAT32_C(161.270676),
      UINT32_C(161)  },
    { SIMDE_FLOAT32_C(302.139801),
      UINT32_C(302)  },
    { SIMDE_FLOAT32_C(949.265381),
      UINT32_C(949)  },
    { SIMDE_FLOAT32_C(586.265320),
      UINT32_C(586)  },
    { SIMDE_FLOAT32_C(230.019547),
      UINT32_C(230)  },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 a = test_vec[i].a;
    uint32_t r = simde_vcvtas_u32_f32(a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_arm_neon_random_f32(-1000.0f, 1000.0f);
    simde_uint32_t r = simde_vcvtas_u32_f32(a);

    simde_test_arm_neon_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtad_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    int64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NAN,
        INT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX),
                    INT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(1000.0),
                    INT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN),
                    INT64_MIN },
      { HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) - SIMDE_FLOAT64_C(1000.0),
                    INT64_MIN },
    #endif
    { SIMDE_FLOAT64_C(   -19.13),
      -INT64_C(                  19) },
    { SIMDE_FLOAT64_C(  -897.18),
      -INT64_C(                 897) },
    { SIMDE_FLOAT64_C(  -126.06),
      -INT64_C(                 126) },
    { SIMDE_FLOAT64_C(  -662.96),
      -INT64_C(                 663) },
    { SIMDE_FLOAT64_C(  -999.91),
      -INT64_C(                1000) },
    { SIMDE_FLOAT64_C(  -845.48),
      -INT64_C(                 845) },
    { SIMDE_FLOAT64_C(  -431.61),
      -INT64_C(                 432) },
    { SIMDE_FLOAT64_C(  -165.42),
      -INT64_C(                 165) },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    int64_t r = simde_vcvtad_s64_f64(a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int64_t r = simde_vcvtad_s64_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtad_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    uint64_t r;
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      {            SIMDE_MATH_NAN,
        UINT64_C(           0) },
      { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(1000.0),
                    UINT64_MAX },
      { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX),
                    UINT64_MAX },
      { SIMDE_FLOAT64_C(  -463.65),
        UINT64_C(                   0) },
      { SIMDE_FLOAT64_C(  -607.03),
        UINT64_C(                   0) },
    #endif
    { SIMDE_FLOAT64_C(   522.61),
      UINT64_C(                 523) },
    { SIMDE_FLOAT64_C(   960.37),
      UINT64_C(                 960) },
    { SIMDE_FLOAT64_C(    66.87),
      UINT64_C(                  67) },
    { SIMDE_FLOAT64_C(   176.41),
      UINT64_C(                 176) },
    { SIMDE_FLOAT64_C(     0.33),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   450.07),
      UINT64_C(                 450) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    uint64_t r = simde_vcvtad_u64_f64(a);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64 a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    uint64_t r = simde_vcvtad_u64_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvta_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(   5.484), SIMDE_FLOAT16_VALUE( -   6.295), SIMDE_FLOAT16_VALUE( -   5.132),  SIMDE_FLOAT16_VALUE(  12.566) },
      {  INT16_C(       5), -INT16_C(       6), -INT16_C(       5),  INT16_C(      13) } },
    { { SIMDE_FLOAT16_VALUE( -  25.918),  SIMDE_FLOAT16_VALUE(  12.330), SIMDE_FLOAT16_VALUE( -  10.464),  SIMDE_FLOAT16_VALUE(   9.083) },
      { -INT16_C(      26),  INT16_C(      12), -INT16_C(      10),  INT16_C(       9) } },
    { { SIMDE_FLOAT16_VALUE( -   1.292), SIMDE_FLOAT16_VALUE( -  11.738),  SIMDE_FLOAT16_VALUE(   6.931),  SIMDE_FLOAT16_VALUE(  29.815) },
      { -INT16_C(       1), -INT16_C(      12),  INT16_C(       7),  INT16_C(      30) } },
    { { SIMDE_FLOAT16_VALUE( -   6.023), SIMDE_FLOAT16_VALUE( -  16.490),  SIMDE_FLOAT16_VALUE(  13.782),  SIMDE_FLOAT16_VALUE(   3.109) },
      { -INT16_C(       6), -INT16_C(      16),  INT16_C(      14),  INT16_C(       3) } },
    { {  SIMDE_FLOAT16_VALUE(  21.674), SIMDE_FLOAT16_VALUE( -  27.968), SIMDE_FLOAT16_VALUE( -  13.322), SIMDE_FLOAT16_VALUE( -   0.172) },
      {  INT16_C(      22), -INT16_C(      28), -INT16_C(      13),  INT16_C(       0) } },
    { { SIMDE_FLOAT16_VALUE( -  10.360),  SIMDE_FLOAT16_VALUE(  15.085),  SIMDE_FLOAT16_VALUE(  26.131),  SIMDE_FLOAT16_VALUE(  18.421) },
      { -INT16_C(      10),  INT16_C(      15),  INT16_C(      26),  INT16_C(      18) } },
    { { SIMDE_FLOAT16_VALUE( -  20.906),  SIMDE_FLOAT16_VALUE(  12.372),  SIMDE_FLOAT16_VALUE(  11.952),  SIMDE_FLOAT16_VALUE(  14.232) },
      { -INT16_C(      21),  INT16_C(      12),  INT16_C(      12),  INT16_C(      14) } },
    { {  SIMDE_FLOAT16_VALUE(   4.188),  SIMDE_FLOAT16_VALUE(   3.209), SIMDE_FLOAT16_VALUE( -   3.902), SIMDE_FLOAT16_VALUE( -   4.983) },
      {  INT16_C(       4),  INT16_C(       3), -INT16_C(       4), -INT16_C(       5) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_int16x4_t r = simde_vcvta_s16_f16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_int16x4_t r = simde_vcvta_s16_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvta_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(    91.88), SIMDE_FLOAT16_VALUE(    32.12), SIMDE_FLOAT16_VALUE(    15.08), SIMDE_FLOAT16_VALUE(    33.19) },
      { UINT16_C(   92), UINT16_C(   32), UINT16_C(   15), UINT16_C(   33) } },
    { { SIMDE_FLOAT16_VALUE(    76.44), SIMDE_FLOAT16_VALUE(    43.81), SIMDE_FLOAT16_VALUE(    91.31), SIMDE_FLOAT16_VALUE(    41.16) },
      { UINT16_C(   76), UINT16_C(   44), UINT16_C(   91), UINT16_C(   41) } },
    { { SIMDE_FLOAT16_VALUE(    69.56), SIMDE_FLOAT16_VALUE(    98.00), SIMDE_FLOAT16_VALUE(    93.50), SIMDE_FLOAT16_VALUE(    29.94) },
      { UINT16_C(   70), UINT16_C(   98), UINT16_C(   94), UINT16_C(   30) } },
    { { SIMDE_FLOAT16_VALUE(    47.88), SIMDE_FLOAT16_VALUE(    20.88), SIMDE_FLOAT16_VALUE(    43.38), SIMDE_FLOAT16_VALUE(    30.53) },
      { UINT16_C(   48), UINT16_C(   21), UINT16_C(   43), UINT16_C(   31) } },
    { { SIMDE_FLOAT16_VALUE(    51.06), SIMDE_FLOAT16_VALUE(    29.81), SIMDE_FLOAT16_VALUE(    36.16), SIMDE_FLOAT16_VALUE(    52.94) },
      { UINT16_C(   51), UINT16_C(   30), UINT16_C(   36), UINT16_C(   53) } },
    { { SIMDE_FLOAT16_VALUE(    77.94), SIMDE_FLOAT16_VALUE(    76.12), SIMDE_FLOAT16_VALUE(    36.69), SIMDE_FLOAT16_VALUE(    46.81) },
      { UINT16_C(   78), UINT16_C(   76), UINT16_C(   37), UINT16_C(   47) } },
    { { SIMDE_FLOAT16_VALUE(    94.00), SIMDE_FLOAT16_VALUE(    85.12), SIMDE_FLOAT16_VALUE(    91.81), SIMDE_FLOAT16_VALUE(    98.12) },
      { UINT16_C(   94), UINT16_C(   85), UINT16_C(   92), UINT16_C(   98) } },
    { { SIMDE_FLOAT16_VALUE(    93.12), SIMDE_FLOAT16_VALUE(     2.32), SIMDE_FLOAT16_VALUE(    40.25), SIMDE_FLOAT16_VALUE(    85.00) },
      { UINT16_C(   93), UINT16_C(    2), UINT16_C(   40), UINT16_C(   85) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcvta_u16_f16(a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(0.0f, 100.0f);
    simde_uint16x4_t r = simde_vcvta_u16_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvta_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    int32_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, INT32_MAX) + SIMDE_FLOAT32_C(1000.0),
          HEDLEY_STATIC_CAST(simde_float32, INT32_MIN) - SIMDE_FLOAT32_C(1000.0) },
        {              INT32_MAX,              INT32_MIN } },
      { {        SIMDE_MATH_NANF,   SIMDE_MATH_INFINITYF },
        {  INT32_C(           0),              INT32_MAX } },
    #endif
    { { SIMDE_FLOAT32_C(-137.097046), SIMDE_FLOAT32_C(632.638672) },
      { -INT32_C(137), INT32_C(633)  } },
    { { SIMDE_FLOAT32_C(135.947388), SIMDE_FLOAT32_C(-204.564087) },
      { INT32_C(136), -INT32_C(205)  } },
    { { SIMDE_FLOAT32_C(422.245239), SIMDE_FLOAT32_C(972.902710) },
      { INT32_C(422), INT32_C(973)  } },
    { { SIMDE_FLOAT32_C(-291.536621), SIMDE_FLOAT32_C(-849.554077) },
      { -INT32_C(292), -INT32_C(850)  } },
    { { SIMDE_FLOAT32_C(-9.575623), SIMDE_FLOAT32_C(318.716919) },
      { -INT32_C(10), INT32_C(319)  } },
    { { SIMDE_FLOAT32_C(-734.776367), SIMDE_FLOAT32_C(-510.679810) },
      { -INT32_C(735), -INT32_C(511)  } },
    { { SIMDE_FLOAT32_C(-457.886719), SIMDE_FLOAT32_C(655.444580) },
      { -INT32_C(458), INT32_C(655)  } },
    { { SIMDE_FLOAT32_C(847.546021), SIMDE_FLOAT32_C(849.980591) },
      { INT32_C(848), INT32_C(850)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_int32x2_t r = simde_vcvta_s32_f32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_int32x2_t r = simde_vcvta_s32_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvta_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(1000.0),
          SIMDE_FLOAT32_C(-1000.0) },
        {              UINT32_MAX,              0 } },
      { {        SIMDE_MATH_NANF,   SIMDE_MATH_INFINITYF },
        {  UINT32_C(           0),              UINT32_MAX } },
    #endif
    { { SIMDE_FLOAT32_C(518.760376), SIMDE_FLOAT32_C(796.769409) },
      { UINT32_C(519), UINT32_C(797)  } },
    { { SIMDE_FLOAT32_C(161.204361), SIMDE_FLOAT32_C(381.395020) },
      { UINT32_C(161), UINT32_C(381)  } },
    { { SIMDE_FLOAT32_C(803.856689), SIMDE_FLOAT32_C(971.859131) },
      { UINT32_C(804), UINT32_C(972)  } },
    { { SIMDE_FLOAT32_C(445.868378), SIMDE_FLOAT32_C(558.828979) },
      { UINT32_C(446), UINT32_C(559)  } },
    { { SIMDE_FLOAT32_C(83.968452), SIMDE_FLOAT32_C(140.023712) },
      { UINT32_C(84), UINT32_C(140)  } },
    { { SIMDE_FLOAT32_C(230.921921), SIMDE_FLOAT32_C(235.137802) },
      { UINT32_C(231), UINT32_C(235)  } },
    { { SIMDE_FLOAT32_C(367.292725), SIMDE_FLOAT32_C(815.052429) },
      { UINT32_C(367), UINT32_C(815)  } },
    { { SIMDE_FLOAT32_C(13.168660), SIMDE_FLOAT32_C(406.672668) },
      { UINT32_C(13), UINT32_C(407)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcvta_u32_f32(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_uint32x2_t r = simde_vcvta_u32_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvta_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    int64_t r[1];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C(467711.875) },
      {  INT64_C(  467712) } },
    { { -SIMDE_FLOAT64_C(975485.312) },
      { -INT64_C(  975485) } },
    { {  SIMDE_FLOAT64_C(313635.750) },
      {  INT64_C(  313636) } },
    { {  SIMDE_FLOAT64_C(699213.000) },
      {  INT64_C(  699213) } },
    { { -SIMDE_FLOAT64_C(798464.875) },
      { -INT64_C(  798465) } },
    { {  SIMDE_FLOAT64_C(501944.750) },
      {  INT64_C(  501945) } },
    { { -SIMDE_FLOAT64_C(986927.375) },
      { -INT64_C(  986927) } },
    { { -SIMDE_FLOAT64_C(797904.438) },
      { -INT64_C(  797904) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_int64x1_t r = simde_vcvta_s64_f64(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x1_t r = simde_vcvta_s64_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvta_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
    { { -SIMDE_FLOAT64_C(866879.562) },
      {  UINT64_C(       0) } },
    { { -SIMDE_FLOAT64_C(144314.438) },
      {  UINT64_C(       0) } },
    { { -SIMDE_FLOAT64_C(515307.688) },
      {  UINT64_C(       0) } },
    { { -SIMDE_FLOAT64_C(833382.875) },
      {  UINT64_C(       0) } },
    { { -SIMDE_FLOAT64_C(579680.125) },
      {  UINT64_C(       0) } },
    #endif
    { {  SIMDE_FLOAT64_C(869455.375) },
      {  UINT64_C(  869455) } },
    { {  SIMDE_FLOAT64_C(372019.875) },
      {  UINT64_C(  372020) } },
    { {  SIMDE_FLOAT64_C(487323.250) },
      {  UINT64_C(  487323) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcvta_u64_f64(a);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x1_t r = simde_vcvta_u64_f64(a);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

/* Disabled until we fix the FCVTZS/FCVTMS/FCVTPS/FCVTNS family intrinsics
 * https://github.com/simd-everywhere/simde/issues/1099
static int
test_simde_vcvtaq_s16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  26.678),  SIMDE_FLOAT16_VALUE(  11.961), SIMDE_FLOAT16_VALUE( -   5.477),  SIMDE_FLOAT16_VALUE(   2.192),
        SIMDE_FLOAT16_VALUE( -  23.653),  SIMDE_FLOAT16_VALUE(  24.091),  SIMDE_FLOAT16_VALUE(  16.211),  SIMDE_FLOAT16_VALUE(  13.136) },
      {  INT16_C(      27),  INT16_C(      12), -INT16_C(       5),  INT16_C(       2),
        -INT16_C(      24),  INT16_C(      24),  INT16_C(      16),  INT16_C(      13) } },
    { { SIMDE_FLOAT16_VALUE( -  10.106),  SIMDE_FLOAT16_VALUE(   2.807),  SIMDE_FLOAT16_VALUE(   0.036),  SIMDE_FLOAT16_VALUE(  16.987),
        SIMDE_FLOAT16_VALUE( -   8.282), SIMDE_FLOAT16_VALUE( -   0.626),  SIMDE_FLOAT16_VALUE(   5.032), SIMDE_FLOAT16_VALUE( -   0.023) },
      { -INT16_C(      10),  INT16_C(       3),  INT16_C(       0),  INT16_C(      17),
        -INT16_C(       8), -INT16_C(       1),  INT16_C(       5),  INT16_C(       0) } },
    { {  SIMDE_FLOAT16_VALUE(   0.850),  SIMDE_FLOAT16_VALUE(  28.954), SIMDE_FLOAT16_VALUE( -  11.152), SIMDE_FLOAT16_VALUE( -   1.218),
         SIMDE_FLOAT16_VALUE(   4.105),  SIMDE_FLOAT16_VALUE(  26.947),  SIMDE_FLOAT16_VALUE(  29.786), SIMDE_FLOAT16_VALUE( -  20.433) },
      {  INT16_C(       1),  INT16_C(      29), -INT16_C(      11), -INT16_C(       1),
         INT16_C(       4),  INT16_C(      27),  INT16_C(      30), -INT16_C(      20) } },
    { {  SIMDE_FLOAT16_VALUE(   9.218),  SIMDE_FLOAT16_VALUE(  27.413),  SIMDE_FLOAT16_VALUE(  29.857),  SIMDE_FLOAT16_VALUE(  25.421),
         SIMDE_FLOAT16_VALUE(  20.930),  SIMDE_FLOAT16_VALUE(   4.858),  SIMDE_FLOAT16_VALUE(   1.136), SIMDE_FLOAT16_VALUE( -   9.511) },
      {  INT16_C(       9),  INT16_C(      27),  INT16_C(      30),  INT16_C(      25),
         INT16_C(      21),  INT16_C(       5),  INT16_C(       1), -INT16_C(      10) } },
    { { SIMDE_FLOAT16_VALUE( -   5.330), SIMDE_FLOAT16_VALUE( -  28.994),  SIMDE_FLOAT16_VALUE(   6.794),  SIMDE_FLOAT16_VALUE(  12.383),
        SIMDE_FLOAT16_VALUE( -  27.061), SIMDE_FLOAT16_VALUE( -  14.157),  SIMDE_FLOAT16_VALUE(  19.177),  SIMDE_FLOAT16_VALUE(  24.741) },
      { -INT16_C(       5), -INT16_C(      29),  INT16_C(       7),  INT16_C(      12),
        -INT16_C(      27), -INT16_C(      14),  INT16_C(      19),  INT16_C(      25) } },
    { { SIMDE_FLOAT16_VALUE( -  10.145),  SIMDE_FLOAT16_VALUE(  14.145),  SIMDE_FLOAT16_VALUE(  10.567), SIMDE_FLOAT16_VALUE( -  18.585),
        SIMDE_FLOAT16_VALUE( -  24.925), SIMDE_FLOAT16_VALUE( -  27.646),  SIMDE_FLOAT16_VALUE(  26.222),  SIMDE_FLOAT16_VALUE(   4.194) },
      { -INT16_C(      10),  INT16_C(      14),  INT16_C(      11), -INT16_C(      19),
        -INT16_C(      25), -INT16_C(      28),  INT16_C(      26),  INT16_C(       4) } },
    { {  SIMDE_FLOAT16_VALUE(  10.447), SIMDE_FLOAT16_VALUE( -  19.586), SIMDE_FLOAT16_VALUE( -   6.815), SIMDE_FLOAT16_VALUE( -  16.894),
        SIMDE_FLOAT16_VALUE( -  10.842),  SIMDE_FLOAT16_VALUE(  23.604), SIMDE_FLOAT16_VALUE( -  11.436), SIMDE_FLOAT16_VALUE( -  10.067) },
      {  INT16_C(      10), -INT16_C(      20), -INT16_C(       7), -INT16_C(      17),
        -INT16_C(      11),  INT16_C(      24), -INT16_C(      11), -INT16_C(      10) } },
    { { SIMDE_FLOAT16_VALUE( -  16.757), SIMDE_FLOAT16_VALUE( -  21.348), SIMDE_FLOAT16_VALUE( -  25.380),  SIMDE_FLOAT16_VALUE(  26.218),
        SIMDE_FLOAT16_VALUE( -  10.699),  SIMDE_FLOAT16_VALUE(  27.303),  SIMDE_FLOAT16_VALUE(  23.601),  SIMDE_FLOAT16_VALUE(   9.547) },
      { -INT16_C(      17), -INT16_C(      21), -INT16_C(      25),  INT16_C(      26),
        -INT16_C(      11),  INT16_C(      27),  INT16_C(      24),  INT16_C(      10) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_int16x8_t r = simde_vcvtaq_s16_f16(a);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_int16x8_t r = simde_vcvtaq_s16_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
*/

static int
test_simde_vcvtaq_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(    34.44), SIMDE_FLOAT16_VALUE(    55.34), SIMDE_FLOAT16_VALUE(    18.20), SIMDE_FLOAT16_VALUE(    10.84),
        SIMDE_FLOAT16_VALUE(    99.12), SIMDE_FLOAT16_VALUE(     9.53), SIMDE_FLOAT16_VALUE(    52.00), SIMDE_FLOAT16_VALUE(    68.75) },
      { UINT16_C(   34), UINT16_C(   55), UINT16_C(   18), UINT16_C(   11), UINT16_C(   99), UINT16_C(   10), UINT16_C(   52), UINT16_C(   69) } },
    { { SIMDE_FLOAT16_VALUE(     7.50), SIMDE_FLOAT16_VALUE(    45.50), SIMDE_FLOAT16_VALUE(    98.69), SIMDE_FLOAT16_VALUE(    55.38),
        SIMDE_FLOAT16_VALUE(    66.38), SIMDE_FLOAT16_VALUE(    42.06), SIMDE_FLOAT16_VALUE(    85.94), SIMDE_FLOAT16_VALUE(    17.45) },
      { UINT16_C(    8), UINT16_C(   46), UINT16_C(   99), UINT16_C(   55), UINT16_C(   66), UINT16_C(   42), UINT16_C(   86), UINT16_C(   17) } },
    { { SIMDE_FLOAT16_VALUE(    71.88), SIMDE_FLOAT16_VALUE(    22.06), SIMDE_FLOAT16_VALUE(    70.38), SIMDE_FLOAT16_VALUE(    49.84),
        SIMDE_FLOAT16_VALUE(    98.25), SIMDE_FLOAT16_VALUE(     7.09), SIMDE_FLOAT16_VALUE(    96.62), SIMDE_FLOAT16_VALUE(    92.19) },
      { UINT16_C(   72), UINT16_C(   22), UINT16_C(   70), UINT16_C(   50), UINT16_C(   98), UINT16_C(    7), UINT16_C(   97), UINT16_C(   92) } },
    { { SIMDE_FLOAT16_VALUE(    92.19), SIMDE_FLOAT16_VALUE(    88.44), SIMDE_FLOAT16_VALUE(    90.31), SIMDE_FLOAT16_VALUE(    85.31),
        SIMDE_FLOAT16_VALUE(    90.75), SIMDE_FLOAT16_VALUE(    30.58), SIMDE_FLOAT16_VALUE(    70.38), SIMDE_FLOAT16_VALUE(    25.20) },
      { UINT16_C(   92), UINT16_C(   88), UINT16_C(   90), UINT16_C(   85), UINT16_C(   91), UINT16_C(   31), UINT16_C(   70), UINT16_C(   25) } },
    { { SIMDE_FLOAT16_VALUE(    85.94), SIMDE_FLOAT16_VALUE(    88.56), SIMDE_FLOAT16_VALUE(    36.06), SIMDE_FLOAT16_VALUE(    85.06),
        SIMDE_FLOAT16_VALUE(    98.06), SIMDE_FLOAT16_VALUE(    88.06), SIMDE_FLOAT16_VALUE(    53.81), SIMDE_FLOAT16_VALUE(     5.58) },
      { UINT16_C(   86), UINT16_C(   89), UINT16_C(   36), UINT16_C(   85), UINT16_C(   98), UINT16_C(   88), UINT16_C(   54), UINT16_C(    6) } },
    { { SIMDE_FLOAT16_VALUE(    33.56), SIMDE_FLOAT16_VALUE(    52.50), SIMDE_FLOAT16_VALUE(    60.97), SIMDE_FLOAT16_VALUE(    99.94),
        SIMDE_FLOAT16_VALUE(    94.56), SIMDE_FLOAT16_VALUE(    46.88), SIMDE_FLOAT16_VALUE(    17.39), SIMDE_FLOAT16_VALUE(    66.44) },
      { UINT16_C(   34), UINT16_C(   53), UINT16_C(   61), UINT16_C(  100), UINT16_C(   95), UINT16_C(   47), UINT16_C(   17), UINT16_C(   66) } },
    { { SIMDE_FLOAT16_VALUE(    68.94), SIMDE_FLOAT16_VALUE(    87.75), SIMDE_FLOAT16_VALUE(    16.28), SIMDE_FLOAT16_VALUE(    67.19),
        SIMDE_FLOAT16_VALUE(    94.88), SIMDE_FLOAT16_VALUE(    12.93), SIMDE_FLOAT16_VALUE(    59.38), SIMDE_FLOAT16_VALUE(    87.06) },
      { UINT16_C(   69), UINT16_C(   88), UINT16_C(   16), UINT16_C(   67), UINT16_C(   95), UINT16_C(   13), UINT16_C(   59), UINT16_C(   87) } },
    { { SIMDE_FLOAT16_VALUE(     1.39), SIMDE_FLOAT16_VALUE(    49.69), SIMDE_FLOAT16_VALUE(    72.44), SIMDE_FLOAT16_VALUE(    92.19),
        SIMDE_FLOAT16_VALUE(    80.25), SIMDE_FLOAT16_VALUE(    42.75), SIMDE_FLOAT16_VALUE(    17.38), SIMDE_FLOAT16_VALUE(    66.19) },
      { UINT16_C(    1), UINT16_C(   50), UINT16_C(   72), UINT16_C(   92), UINT16_C(   80), UINT16_C(   43), UINT16_C(   17), UINT16_C(   66) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcvtaq_u16_f16(a);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(0.0f, 100.0f);
    simde_uint16x8_t r = simde_vcvtaq_u16_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtaq_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    int32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -91.12), SIMDE_FLOAT32_C(   276.21), SIMDE_FLOAT32_C(   314.70), SIMDE_FLOAT32_C(  -855.95) },
      { -INT32_C(          91),  INT32_C(         276),  INT32_C(         315), -INT32_C(         856) } },
    { { SIMDE_FLOAT32_C(  -996.84), SIMDE_FLOAT32_C(   540.73), SIMDE_FLOAT32_C(   797.87), SIMDE_FLOAT32_C(    73.20) },
      { -INT32_C(         997),  INT32_C(         541),  INT32_C(         798),  INT32_C(          73) } },
    { { SIMDE_FLOAT32_C(   982.29), SIMDE_FLOAT32_C(   254.11), SIMDE_FLOAT32_C(  -220.70), SIMDE_FLOAT32_C(  -655.84) },
      {  INT32_C(         982),  INT32_C(         254), -INT32_C(         221), -INT32_C(         656) } },
    { { SIMDE_FLOAT32_C(   775.61), SIMDE_FLOAT32_C(   688.80), SIMDE_FLOAT32_C(  -639.40), SIMDE_FLOAT32_C(   666.72) },
      {  INT32_C(         776),  INT32_C(         689), -INT32_C(         639),  INT32_C(         667) } },
    { { SIMDE_FLOAT32_C(   587.36), SIMDE_FLOAT32_C(  -397.45), SIMDE_FLOAT32_C(  -684.16), SIMDE_FLOAT32_C(  -689.59) },
      {  INT32_C(         587), -INT32_C(         397), -INT32_C(         684), -INT32_C(         690) } },
    { { SIMDE_FLOAT32_C(  -723.69), SIMDE_FLOAT32_C(   904.22), SIMDE_FLOAT32_C(    91.42), SIMDE_FLOAT32_C(  -642.96) },
      { -INT32_C(         724),  INT32_C(         904),  INT32_C(          91), -INT32_C(         643) } },
    { { SIMDE_FLOAT32_C(   357.06), SIMDE_FLOAT32_C(  -318.89), SIMDE_FLOAT32_C(  -860.25), SIMDE_FLOAT32_C(  -108.96) },
      {  INT32_C(         357), -INT32_C(         319), -INT32_C(         860), -INT32_C(         109) } },
    { { SIMDE_FLOAT32_C(   333.78), SIMDE_FLOAT32_C(   -14.76), SIMDE_FLOAT32_C(  -212.33), SIMDE_FLOAT32_C(  -757.34) },
      {  INT32_C(         334), -INT32_C(          15), -INT32_C(         212), -INT32_C(         757) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_int32x4_t r = simde_vcvtaq_s32_f32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_int32x4_t r = simde_vcvtaq_s32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtaq_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float32, UINT32_MAX) + SIMDE_FLOAT32_C(10000.0), SIMDE_FLOAT32_C(-10000.0), SIMDE_MATH_NANF, SIMDE_MATH_INFINITYF },
        {              UINT32_MAX,            UINT32_C(           0),  UINT32_C(           0),              UINT32_MAX } },
    #endif
    { { SIMDE_FLOAT32_C(99.796890), SIMDE_FLOAT32_C(640.625061), SIMDE_FLOAT32_C(761.249390), SIMDE_FLOAT32_C(134.496353) },
      { UINT32_C(100), UINT32_C(641), UINT32_C(761), UINT32_C(134)  } },
    { { SIMDE_FLOAT32_C(740.153748), SIMDE_FLOAT32_C(226.072403), SIMDE_FLOAT32_C(458.142426), SIMDE_FLOAT32_C(312.975708) },
      { UINT32_C(740), UINT32_C(226), UINT32_C(458), UINT32_C(313)  } },
    { { SIMDE_FLOAT32_C(881.748596), SIMDE_FLOAT32_C(315.416504), SIMDE_FLOAT32_C(657.340698), SIMDE_FLOAT32_C(492.805298) },
      { UINT32_C(882), UINT32_C(315), UINT32_C(657), UINT32_C(493)  } },
    { { SIMDE_FLOAT32_C(27.446901), SIMDE_FLOAT32_C(904.086670), SIMDE_FLOAT32_C(857.025085), SIMDE_FLOAT32_C(677.571045) },
      { UINT32_C(27), UINT32_C(904), UINT32_C(857), UINT32_C(678)  } },
    { { SIMDE_FLOAT32_C(666.073059), SIMDE_FLOAT32_C(988.718506), SIMDE_FLOAT32_C(51.321510), SIMDE_FLOAT32_C(353.845490) },
      { UINT32_C(666), UINT32_C(989), UINT32_C(51), UINT32_C(354)  } },
    { { SIMDE_FLOAT32_C(307.715729), SIMDE_FLOAT32_C(75.778244), SIMDE_FLOAT32_C(748.057373), SIMDE_FLOAT32_C(533.695679) },
      { UINT32_C(308), UINT32_C(76), UINT32_C(748), UINT32_C(534)  } },
    { { SIMDE_FLOAT32_C(949.232422), SIMDE_FLOAT32_C(163.359085), SIMDE_FLOAT32_C(946.573120), SIMDE_FLOAT32_C(713.519104) },
      { UINT32_C(949), UINT32_C(163), UINT32_C(947), UINT32_C(714)  } },
    { { SIMDE_FLOAT32_C(592.152954), SIMDE_FLOAT32_C(751.258545), SIMDE_FLOAT32_C(645.332520), SIMDE_FLOAT32_C(894.986938) },
      { UINT32_C(592), UINT32_C(751), UINT32_C(645), UINT32_C(895)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcvtaq_u32_f32(a);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_uint32x4_t r = simde_vcvtaq_u32_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtaq_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    int64_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, INT64_MAX) + SIMDE_FLOAT64_C(10000.0), HEDLEY_STATIC_CAST(simde_float64, INT64_MIN) - SIMDE_FLOAT64_C(10000.0) },
        {              INT64_MAX,              INT64_MIN } },
      { { SIMDE_MATH_NAN, SIMDE_MATH_INFINITY },
        { INT64_C(           0),              INT64_MAX } },
    #endif
    { {  SIMDE_FLOAT64_C(649473.000), -SIMDE_FLOAT64_C(977642.625) },
      {  INT64_C(  649473), -INT64_C(  977643) } },
    { { -SIMDE_FLOAT64_C(179199.750),  SIMDE_FLOAT64_C(179289.625) },
      { -INT64_C(  179200),  INT64_C(  179290) } },
    { { -SIMDE_FLOAT64_C(454067.688), -SIMDE_FLOAT64_C(293304.875) },
      { -INT64_C(  454068), -INT64_C(  293305) } },
    { { -SIMDE_FLOAT64_C(158054.938),  SIMDE_FLOAT64_C(237602.250) },
      { -INT64_C(  158055),  INT64_C(  237602) } },
    { {  SIMDE_FLOAT64_C(919757.375),  SIMDE_FLOAT64_C(229895.000) },
      {  INT64_C(  919757),  INT64_C(  229895) } },
    { { -SIMDE_FLOAT64_C(977677.688), -SIMDE_FLOAT64_C(625679.750) },
      { -INT64_C(  977678), -INT64_C(  625680) } },
    { {  SIMDE_FLOAT64_C(589580.875),  SIMDE_FLOAT64_C(107357.750) },
      {  INT64_C(  589581),  INT64_C(  107358) } },
    { { -SIMDE_FLOAT64_C(409446.562), -SIMDE_FLOAT64_C(469972.188) },
      { -INT64_C(  409447), -INT64_C(  469972) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_int64x2_t r = simde_vcvtaq_s64_f64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_int64x2_t r = simde_vcvtaq_s64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtaq_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    uint64_t r[2];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_CONVERSION_RANGE)
      { { HEDLEY_STATIC_CAST(simde_float64, UINT64_MAX) + SIMDE_FLOAT64_C(10000.0), SIMDE_FLOAT64_C(-10000.0) },
        {              UINT64_MAX,            UINT64_C(           0) } },
      { { SIMDE_MATH_NAN, SIMDE_MATH_INFINITY },
        { UINT64_C(           0),              UINT64_MAX } },
    #endif
    { { SIMDE_FLOAT64_C(   633.17), SIMDE_FLOAT64_C(   804.93) },
      { UINT64_C(                 633), UINT64_C(                 805) } },
    { { SIMDE_FLOAT64_C(   703.41), SIMDE_FLOAT64_C(   627.44) },
      { UINT64_C(                 703), UINT64_C(                 627) } },
    { { SIMDE_FLOAT64_C(   462.56), SIMDE_FLOAT64_C(   955.00) },
      { UINT64_C(                 463), UINT64_C(                 955) } },
    { { SIMDE_FLOAT64_C(    21.07), SIMDE_FLOAT64_C(   229.08) },
      { UINT64_C(                  21), UINT64_C(                 229) } },
    { { SIMDE_FLOAT64_C(   979.06), SIMDE_FLOAT64_C(   321.00) },
      { UINT64_C(                 979), UINT64_C(                 321) } },
    { { SIMDE_FLOAT64_C(   153.68), SIMDE_FLOAT64_C(   825.89) },
      { UINT64_C(                 154), UINT64_C(                 826) } },
    { { SIMDE_FLOAT64_C(   206.68), SIMDE_FLOAT64_C(   853.41) },
      { UINT64_C(                 207), UINT64_C(                 853) } },
    { { SIMDE_FLOAT64_C(   159.03), SIMDE_FLOAT64_C(   851.04) },
      { UINT64_C(                 159), UINT64_C(                 851) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcvtaq_u64_f64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(0.0), SIMDE_FLOAT64_C(1000.0));
    simde_uint64x2_t r = simde_vcvtaq_u64_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_high_f16_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t buf[4];
    simde_float32 a[4];
    simde_float16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( -  24.372),  SIMDE_FLOAT16_VALUE(  23.118), SIMDE_FLOAT16_VALUE( -  23.874), SIMDE_FLOAT16_VALUE( -  17.046) },
      { -SIMDE_FLOAT32_C(7209.161), -SIMDE_FLOAT32_C(3427.483),  SIMDE_FLOAT32_C(4040.883), -SIMDE_FLOAT32_C(2098.786) },
      { SIMDE_FLOAT16_VALUE( -  24.372),  SIMDE_FLOAT16_VALUE(  23.118), SIMDE_FLOAT16_VALUE( -  23.874), SIMDE_FLOAT16_VALUE( -  17.046),
        SIMDE_FLOAT16_VALUE( -7209.161), SIMDE_FLOAT16_VALUE( -3427.483),  SIMDE_FLOAT16_VALUE(4040.883), SIMDE_FLOAT16_VALUE( -2098.786) } },
    { { SIMDE_FLOAT16_VALUE( -  12.176),  SIMDE_FLOAT16_VALUE(   8.252),  SIMDE_FLOAT16_VALUE(   8.152), SIMDE_FLOAT16_VALUE( -  27.851) },
      { -SIMDE_FLOAT32_C(6963.870), -SIMDE_FLOAT32_C(5850.501),  SIMDE_FLOAT32_C(3869.630),  SIMDE_FLOAT32_C(3814.924) },
      { SIMDE_FLOAT16_VALUE( -  12.176),  SIMDE_FLOAT16_VALUE(   8.252),  SIMDE_FLOAT16_VALUE(   8.152), SIMDE_FLOAT16_VALUE( -  27.851),
        SIMDE_FLOAT16_VALUE( -6963.870), SIMDE_FLOAT16_VALUE( -5850.501),  SIMDE_FLOAT16_VALUE(3869.630),  SIMDE_FLOAT16_VALUE(3814.924) } },
    { { SIMDE_FLOAT16_VALUE( -  14.831), SIMDE_FLOAT16_VALUE( -   2.611),  SIMDE_FLOAT16_VALUE(  28.160), SIMDE_FLOAT16_VALUE( -   2.806) },
      {  SIMDE_FLOAT32_C(8370.572), -SIMDE_FLOAT32_C(9646.048), -SIMDE_FLOAT32_C( 914.674), -SIMDE_FLOAT32_C(  96.147) },
      { SIMDE_FLOAT16_VALUE( -  14.831), SIMDE_FLOAT16_VALUE( -   2.611),  SIMDE_FLOAT16_VALUE(  28.160), SIMDE_FLOAT16_VALUE( -   2.806),
         SIMDE_FLOAT16_VALUE(8370.572), SIMDE_FLOAT16_VALUE( -9646.048), SIMDE_FLOAT16_VALUE( - 914.674), SIMDE_FLOAT16_VALUE( -  96.147) } },
    { { SIMDE_FLOAT16_VALUE( -  20.091),  SIMDE_FLOAT16_VALUE(  18.641), SIMDE_FLOAT16_VALUE( -   4.159),  SIMDE_FLOAT16_VALUE(  26.287) },
      { -SIMDE_FLOAT32_C(6804.170),  SIMDE_FLOAT32_C(6809.797), -SIMDE_FLOAT32_C(6641.329),  SIMDE_FLOAT32_C(5256.305) },
      { SIMDE_FLOAT16_VALUE( -  20.091),  SIMDE_FLOAT16_VALUE(  18.641), SIMDE_FLOAT16_VALUE( -   4.159),  SIMDE_FLOAT16_VALUE(  26.287),
        SIMDE_FLOAT16_VALUE( -6804.170),  SIMDE_FLOAT16_VALUE(6809.797), SIMDE_FLOAT16_VALUE( -6641.329),  SIMDE_FLOAT16_VALUE(5256.305) } },
    { {  SIMDE_FLOAT16_VALUE(  11.268),  SIMDE_FLOAT16_VALUE(  24.385), SIMDE_FLOAT16_VALUE( -  11.918), SIMDE_FLOAT16_VALUE( -  20.926) },
      { -SIMDE_FLOAT32_C(9859.181),  SIMDE_FLOAT32_C(7990.297), -SIMDE_FLOAT32_C(1745.461), -SIMDE_FLOAT32_C(6267.518) },
      {  SIMDE_FLOAT16_VALUE(  11.268),  SIMDE_FLOAT16_VALUE(  24.385), SIMDE_FLOAT16_VALUE( -  11.918), SIMDE_FLOAT16_VALUE( -  20.926),
        SIMDE_FLOAT16_VALUE( -9859.181),  SIMDE_FLOAT16_VALUE(7990.297), SIMDE_FLOAT16_VALUE( -1745.461), SIMDE_FLOAT16_VALUE( -6267.518) } },
    { { SIMDE_FLOAT16_VALUE( -  13.564), SIMDE_FLOAT16_VALUE( -   1.015),  SIMDE_FLOAT16_VALUE(  28.694), SIMDE_FLOAT16_VALUE( -  22.499) },
      { -SIMDE_FLOAT32_C(6059.556),  SIMDE_FLOAT32_C(6039.471),  SIMDE_FLOAT32_C(9932.301),  SIMDE_FLOAT32_C(7266.508) },
      { SIMDE_FLOAT16_VALUE( -  13.564), SIMDE_FLOAT16_VALUE( -   1.015),  SIMDE_FLOAT16_VALUE(  28.694), SIMDE_FLOAT16_VALUE( -  22.499),
        SIMDE_FLOAT16_VALUE( -6059.556),  SIMDE_FLOAT16_VALUE(6039.471),  SIMDE_FLOAT16_VALUE(9932.301),  SIMDE_FLOAT16_VALUE(7266.508) } },
    { { SIMDE_FLOAT16_VALUE( -  26.110),  SIMDE_FLOAT16_VALUE(  28.117), SIMDE_FLOAT16_VALUE( -  26.928),  SIMDE_FLOAT16_VALUE(   2.198) },
      { -SIMDE_FLOAT32_C(4140.171), -SIMDE_FLOAT32_C(5252.628),  SIMDE_FLOAT32_C(5685.721), -SIMDE_FLOAT32_C(3753.093) },
      { SIMDE_FLOAT16_VALUE( -  26.110),  SIMDE_FLOAT16_VALUE(  28.117), SIMDE_FLOAT16_VALUE( -  26.928),  SIMDE_FLOAT16_VALUE(   2.198),
        SIMDE_FLOAT16_VALUE( -4140.171), SIMDE_FLOAT16_VALUE( -5252.628),  SIMDE_FLOAT16_VALUE(5685.721), SIMDE_FLOAT16_VALUE( -3753.093) } },
    { { SIMDE_FLOAT16_VALUE( -   3.040),  SIMDE_FLOAT16_VALUE(  10.693),  SIMDE_FLOAT16_VALUE(  19.060), SIMDE_FLOAT16_VALUE( -  29.067) },
      {  SIMDE_FLOAT32_C( 553.772),  SIMDE_FLOAT32_C(3391.303),  SIMDE_FLOAT32_C(3482.779), -SIMDE_FLOAT32_C( 673.666) },
      { SIMDE_FLOAT16_VALUE( -   3.040),  SIMDE_FLOAT16_VALUE(  10.693),  SIMDE_FLOAT16_VALUE(  19.060), SIMDE_FLOAT16_VALUE( -  29.067),
         SIMDE_FLOAT16_VALUE( 553.772),  SIMDE_FLOAT16_VALUE(3391.303),  SIMDE_FLOAT16_VALUE(3482.779), SIMDE_FLOAT16_VALUE( - 673.666) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float16x4_t buf = simde_vld1_f16(test_vec[i].buf);
    simde_float16x8_t r = simde_vcvt_high_f16_f32(buf, a);

    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t buf = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float16x8_t r = simde_vcvt_high_f16_f32(buf, a);

    simde_test_arm_neon_write_f16x4(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_high_f32_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 buf[2];
    simde_float64 a[2];
    simde_float32 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(  3151.790),  SIMDE_FLOAT32_C(  1569.615) },
      { -SIMDE_FLOAT64_C(330922.500),  SIMDE_FLOAT64_C( 86650.750) },
      {  SIMDE_FLOAT32_C(  3151.790),  SIMDE_FLOAT32_C(  1569.615), -SIMDE_FLOAT32_C(330922.500),  SIMDE_FLOAT32_C( 86650.750) } },
    { {  SIMDE_FLOAT32_C(  2740.920), -SIMDE_FLOAT32_C(  6163.193) },
      {  SIMDE_FLOAT64_C(258245.250),  SIMDE_FLOAT64_C(192464.250) },
      {  SIMDE_FLOAT32_C(  2740.920), -SIMDE_FLOAT32_C(  6163.193),  SIMDE_FLOAT32_C(258245.250),  SIMDE_FLOAT32_C(192464.250) } },
    { {  SIMDE_FLOAT32_C(  5576.555),  SIMDE_FLOAT32_C(  6417.400) },
      { -SIMDE_FLOAT64_C(145156.250), -SIMDE_FLOAT64_C(412130.250) },
      {  SIMDE_FLOAT32_C(  5576.555),  SIMDE_FLOAT32_C(  6417.400), -SIMDE_FLOAT32_C(145156.250), -SIMDE_FLOAT32_C(412130.250) } },
    { {  SIMDE_FLOAT32_C(  2466.857),  SIMDE_FLOAT32_C(  3059.207) },
      { -SIMDE_FLOAT64_C(930083.625), -SIMDE_FLOAT64_C(235856.375) },
      {  SIMDE_FLOAT32_C(  2466.857),  SIMDE_FLOAT32_C(  3059.207), -SIMDE_FLOAT32_C(930083.625), -SIMDE_FLOAT32_C(235856.375) } },
    { {  SIMDE_FLOAT32_C(  2648.531), -SIMDE_FLOAT32_C(  9455.132) },
      { -SIMDE_FLOAT64_C(646168.250),  SIMDE_FLOAT64_C(652389.375) },
      {  SIMDE_FLOAT32_C(  2648.531), -SIMDE_FLOAT32_C(  9455.132), -SIMDE_FLOAT32_C(646168.250),  SIMDE_FLOAT32_C(652389.375) } },
    { { -SIMDE_FLOAT32_C(  6091.833), -SIMDE_FLOAT32_C(  7970.317) },
      { -SIMDE_FLOAT64_C(928208.875), -SIMDE_FLOAT64_C(391840.250) },
      { -SIMDE_FLOAT32_C(  6091.833), -SIMDE_FLOAT32_C(  7970.317), -SIMDE_FLOAT32_C(928208.875), -SIMDE_FLOAT32_C(391840.250) } },
    { { -SIMDE_FLOAT32_C(  4632.915),  SIMDE_FLOAT32_C(  1000.022) },
      { -SIMDE_FLOAT64_C(783316.375),  SIMDE_FLOAT64_C(  2008.688) },
      { -SIMDE_FLOAT32_C(  4632.915),  SIMDE_FLOAT32_C(  1000.022), -SIMDE_FLOAT32_C(783316.375),  SIMDE_FLOAT32_C(  2008.688) } },
    { { -SIMDE_FLOAT32_C(  4256.610), -SIMDE_FLOAT32_C(  8440.278) },
      {  SIMDE_FLOAT64_C(522630.125), -SIMDE_FLOAT64_C(222893.500) },
      { -SIMDE_FLOAT32_C(  4256.610), -SIMDE_FLOAT32_C(  8440.278),  SIMDE_FLOAT32_C(522630.125), -SIMDE_FLOAT32_C(222893.500) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float32x4_t r = simde_vcvt_high_f32_f64(buf, a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t buf = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float32x4_t r = simde_vcvt_high_f32_f64(buf, a);

    simde_test_arm_neon_write_f32x2(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_high_f32_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE( - 3.844),  SIMDE_FLOAT16_VALUE(22.261),  SIMDE_FLOAT16_VALUE(21.633),  SIMDE_FLOAT16_VALUE(21.815),
        SIMDE_FLOAT16_VALUE( - 8.432), SIMDE_FLOAT16_VALUE( -19.472),  SIMDE_FLOAT16_VALUE(13.622), SIMDE_FLOAT16_VALUE( - 8.106) },
      { -SIMDE_FLOAT32_C( 8.432), -SIMDE_FLOAT32_C(19.472),  SIMDE_FLOAT32_C(13.622), -SIMDE_FLOAT32_C( 8.106) } },
    { {  SIMDE_FLOAT16_VALUE(26.057),  SIMDE_FLOAT16_VALUE( 0.355), SIMDE_FLOAT16_VALUE( -13.476), SIMDE_FLOAT16_VALUE( - 9.150),
        SIMDE_FLOAT16_VALUE( - 3.837), SIMDE_FLOAT16_VALUE( - 8.472), SIMDE_FLOAT16_VALUE( -12.672),  SIMDE_FLOAT16_VALUE(11.071) },
      { -SIMDE_FLOAT32_C( 3.837), -SIMDE_FLOAT32_C( 8.472), -SIMDE_FLOAT32_C(12.672),  SIMDE_FLOAT32_C(11.071) } },
    { { SIMDE_FLOAT16_VALUE( - 6.540), SIMDE_FLOAT16_VALUE( - 1.356),  SIMDE_FLOAT16_VALUE(22.256), SIMDE_FLOAT16_VALUE( -12.208),
         SIMDE_FLOAT16_VALUE(20.480), SIMDE_FLOAT16_VALUE( - 4.999),  SIMDE_FLOAT16_VALUE( 0.486), SIMDE_FLOAT16_VALUE( - 8.171) },
      {  SIMDE_FLOAT32_C(20.480), -SIMDE_FLOAT32_C( 4.999),  SIMDE_FLOAT32_C( 0.486), -SIMDE_FLOAT32_C( 8.171) } },
    { {  SIMDE_FLOAT16_VALUE(12.817),  SIMDE_FLOAT16_VALUE( 7.000), SIMDE_FLOAT16_VALUE( - 6.571),  SIMDE_FLOAT16_VALUE( 9.247),
         SIMDE_FLOAT16_VALUE(12.120), SIMDE_FLOAT16_VALUE( -10.026), SIMDE_FLOAT16_VALUE( - 5.410), SIMDE_FLOAT16_VALUE( - 4.789) },
      {  SIMDE_FLOAT32_C(12.120), -SIMDE_FLOAT32_C(10.026), -SIMDE_FLOAT32_C( 5.410), -SIMDE_FLOAT32_C( 4.789) } },
    { {  SIMDE_FLOAT16_VALUE(25.521), SIMDE_FLOAT16_VALUE( -18.717), SIMDE_FLOAT16_VALUE( -24.798),  SIMDE_FLOAT16_VALUE(20.203),
         SIMDE_FLOAT16_VALUE(20.893),  SIMDE_FLOAT16_VALUE(22.676), SIMDE_FLOAT16_VALUE( -11.232), SIMDE_FLOAT16_VALUE( - 4.399) },
      {  SIMDE_FLOAT32_C(20.893),  SIMDE_FLOAT32_C(22.676), -SIMDE_FLOAT32_C(11.232), -SIMDE_FLOAT32_C( 4.399) } },
    { {  SIMDE_FLOAT16_VALUE( 7.250), SIMDE_FLOAT16_VALUE( -29.188), SIMDE_FLOAT16_VALUE( -15.288),  SIMDE_FLOAT16_VALUE(10.280),
         SIMDE_FLOAT16_VALUE( 1.174),  SIMDE_FLOAT16_VALUE(29.433), SIMDE_FLOAT16_VALUE( - 3.853),  SIMDE_FLOAT16_VALUE( 3.367) },
      {  SIMDE_FLOAT32_C( 1.174),  SIMDE_FLOAT32_C(29.433), -SIMDE_FLOAT32_C( 3.853),  SIMDE_FLOAT32_C( 3.367) } },
    { { SIMDE_FLOAT16_VALUE( -14.536),  SIMDE_FLOAT16_VALUE(24.455), SIMDE_FLOAT16_VALUE( -12.233), SIMDE_FLOAT16_VALUE( - 7.986),
        SIMDE_FLOAT16_VALUE( -11.418),  SIMDE_FLOAT16_VALUE( 4.680),  SIMDE_FLOAT16_VALUE( 9.822),  SIMDE_FLOAT16_VALUE(16.191) },
      { -SIMDE_FLOAT32_C(11.418),  SIMDE_FLOAT32_C( 4.680),  SIMDE_FLOAT32_C( 9.822),  SIMDE_FLOAT32_C(16.191) } },
    { { SIMDE_FLOAT16_VALUE( -11.395),  SIMDE_FLOAT16_VALUE(11.561), SIMDE_FLOAT16_VALUE( - 5.833),  SIMDE_FLOAT16_VALUE(22.281),
        SIMDE_FLOAT16_VALUE( -27.638), SIMDE_FLOAT16_VALUE( -17.180),  SIMDE_FLOAT16_VALUE(14.937), SIMDE_FLOAT16_VALUE( - 3.647) },
      { -SIMDE_FLOAT32_C(27.638), -SIMDE_FLOAT32_C(17.180),  SIMDE_FLOAT32_C(14.937), -SIMDE_FLOAT32_C( 3.647) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float32x4_t r = simde_vcvt_high_f32_f16(a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float32x4_t r = simde_vcvt_high_f32_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_high_f64_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float64 r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(  2801.914), -SIMDE_FLOAT32_C(  1690.910),  SIMDE_FLOAT32_C(   579.511),  SIMDE_FLOAT32_C(   514.098) },
      {  SIMDE_FLOAT64_C(   579.511),  SIMDE_FLOAT64_C(   514.098) } },
    { {  SIMDE_FLOAT32_C(    23.345), -SIMDE_FLOAT32_C(  8818.351),  SIMDE_FLOAT32_C(  3019.613),  SIMDE_FLOAT32_C(  3442.440) },
      {  SIMDE_FLOAT64_C(  3019.613),  SIMDE_FLOAT64_C(  3442.440) } },
    { {  SIMDE_FLOAT32_C(  3413.646), -SIMDE_FLOAT32_C(  1012.018), -SIMDE_FLOAT32_C(  6549.712), -SIMDE_FLOAT32_C(   269.341) },
      { -SIMDE_FLOAT64_C(  6549.712), -SIMDE_FLOAT64_C(   269.341) } },
    { { -SIMDE_FLOAT32_C(  8209.152), -SIMDE_FLOAT32_C(  6540.035),  SIMDE_FLOAT32_C(  5627.302), -SIMDE_FLOAT32_C(  1488.624) },
      {  SIMDE_FLOAT64_C(  5627.302), -SIMDE_FLOAT64_C(  1488.624) } },
    { {  SIMDE_FLOAT32_C(   444.442),  SIMDE_FLOAT32_C(  8308.801),  SIMDE_FLOAT32_C(  3283.538),  SIMDE_FLOAT32_C(  8306.715) },
      {  SIMDE_FLOAT64_C(  3283.538),  SIMDE_FLOAT64_C(  8306.715) } },
    { {  SIMDE_FLOAT32_C(  4692.329),  SIMDE_FLOAT32_C(   692.840), -SIMDE_FLOAT32_C(  3238.872), -SIMDE_FLOAT32_C(  4908.950) },
      { -SIMDE_FLOAT64_C(  3238.872), -SIMDE_FLOAT64_C(  4908.950) } },
    { {  SIMDE_FLOAT32_C(  1319.597), -SIMDE_FLOAT32_C(  4241.800), -SIMDE_FLOAT32_C(  8086.388),  SIMDE_FLOAT32_C(   496.338) },
      { -SIMDE_FLOAT64_C(  8086.388),  SIMDE_FLOAT64_C(   496.338) } },
    { { -SIMDE_FLOAT32_C(  3654.481),  SIMDE_FLOAT32_C(  4723.808),  SIMDE_FLOAT32_C(  8781.266), -SIMDE_FLOAT32_C(  4554.919) },
      {  SIMDE_FLOAT64_C(  8781.266), -SIMDE_FLOAT64_C(  4554.919) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float64x2_t r = simde_vcvt_high_f64_f32(a);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float64x2_t r = simde_vcvt_high_f64_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtxd_f32_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a;
    simde_float32 r;
  } test_vec[] = {
    {   -SIMDE_FLOAT64_C( 97957.500),
        -SIMDE_FLOAT32_C( 97957.500) },
    {    SIMDE_FLOAT64_C( 70879.625),
         SIMDE_FLOAT32_C( 70879.625) },
    {   -SIMDE_FLOAT64_C( 65748.703),
        -SIMDE_FLOAT32_C( 65748.703) },
    {    SIMDE_FLOAT64_C( 31406.359),
         SIMDE_FLOAT32_C( 31406.359) },
    {    SIMDE_FLOAT64_C( 29286.383),
         SIMDE_FLOAT32_C( 29286.383) },
    {    SIMDE_FLOAT64_C( 13994.172),
         SIMDE_FLOAT32_C( 13994.172) },
    {    SIMDE_FLOAT64_C( 97855.250),
         SIMDE_FLOAT32_C( 97855.250) },
    {    SIMDE_FLOAT64_C( 53307.422),
         SIMDE_FLOAT32_C( 53307.422) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 a = test_vec[i].a;
    simde_float32 r = simde_vcvtxd_f32_f64(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_arm_neon_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float32_t r = simde_vcvtxd_f32_f64(a);

    simde_test_arm_neon_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtx_f32_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float32 r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C( 65007.797), -SIMDE_FLOAT64_C( 80727.609) },
      {  SIMDE_FLOAT32_C( 65007.797), -SIMDE_FLOAT32_C( 80727.609) } },
    { {  SIMDE_FLOAT64_C( 16635.250),  SIMDE_FLOAT64_C( 34365.453) },
      {  SIMDE_FLOAT32_C( 16635.250),  SIMDE_FLOAT32_C( 34365.453) } },
    { {  SIMDE_FLOAT64_C( 59608.250), -SIMDE_FLOAT64_C( 82840.891) },
      {  SIMDE_FLOAT32_C( 59608.250), -SIMDE_FLOAT32_C( 82840.891) } },
    { {  SIMDE_FLOAT64_C( 52610.078),  SIMDE_FLOAT64_C(  7763.352) },
      {  SIMDE_FLOAT32_C( 52610.078),  SIMDE_FLOAT32_C(  7763.352) } },
    { { -SIMDE_FLOAT64_C( 32936.711),  SIMDE_FLOAT64_C( 91758.141) },
      { -SIMDE_FLOAT32_C( 32936.711),  SIMDE_FLOAT32_C( 91758.141) } },
    { {  SIMDE_FLOAT64_C( 86913.797), -SIMDE_FLOAT64_C(  4983.180) },
      {  SIMDE_FLOAT32_C( 86913.797), -SIMDE_FLOAT32_C(  4983.180) } },
    { {  SIMDE_FLOAT64_C( 79903.813), -SIMDE_FLOAT64_C( 75940.688) },
      {  SIMDE_FLOAT32_C( 79903.812), -SIMDE_FLOAT32_C( 75940.688) } },
    { {  SIMDE_FLOAT64_C( 75752.375),  SIMDE_FLOAT64_C( 72121.250) },
      {  SIMDE_FLOAT32_C( 75752.375),  SIMDE_FLOAT32_C( 72121.250) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float32x2_t r = simde_vcvtx_f32_f64(a);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float32x2_t r = simde_vcvtx_f32_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtx_high_f32_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 buf[2];
    simde_float64 a[2];
    simde_float32 r[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(    71.413), -SIMDE_FLOAT32_C(   465.368) },
      {  SIMDE_FLOAT64_C(  4100.359),  SIMDE_FLOAT64_C( 33582.953) },
      { -SIMDE_FLOAT32_C(    71.413), -SIMDE_FLOAT32_C(   465.368),  SIMDE_FLOAT32_C(  4100.359),  SIMDE_FLOAT32_C( 33582.953) } },
    { { -SIMDE_FLOAT32_C(   951.379),  SIMDE_FLOAT32_C(    78.455) },
      {  SIMDE_FLOAT64_C( 68132.203),  SIMDE_FLOAT64_C( 48841.672) },
      { -SIMDE_FLOAT32_C(   951.379),  SIMDE_FLOAT32_C(    78.455),  SIMDE_FLOAT32_C( 68132.203),  SIMDE_FLOAT32_C( 48841.672) } },
    { {  SIMDE_FLOAT32_C(   667.952), -SIMDE_FLOAT32_C(   326.162) },
      {  SIMDE_FLOAT64_C( 21689.508),  SIMDE_FLOAT64_C( 74848.328) },
      {  SIMDE_FLOAT32_C(   667.952), -SIMDE_FLOAT32_C(   326.162),  SIMDE_FLOAT32_C( 21689.508),  SIMDE_FLOAT32_C( 74848.328) } },
    { { -SIMDE_FLOAT32_C(   713.122),  SIMDE_FLOAT32_C(   137.994) },
      { -SIMDE_FLOAT64_C( 49391.813), -SIMDE_FLOAT64_C( 75434.734) },
      { -SIMDE_FLOAT32_C(   713.122),  SIMDE_FLOAT32_C(   137.994), -SIMDE_FLOAT32_C( 49391.812), -SIMDE_FLOAT32_C( 75434.734) } },
    { { -SIMDE_FLOAT32_C(   988.176), -SIMDE_FLOAT32_C(   780.086) },
      { -SIMDE_FLOAT64_C( 54026.855), -SIMDE_FLOAT64_C( 50128.336) },
      { -SIMDE_FLOAT32_C(   988.176), -SIMDE_FLOAT32_C(   780.086), -SIMDE_FLOAT32_C( 54026.855), -SIMDE_FLOAT32_C( 50128.336) } },
    { { -SIMDE_FLOAT32_C(   667.715), -SIMDE_FLOAT32_C(   129.354) },
      { -SIMDE_FLOAT64_C( 37504.672), -SIMDE_FLOAT64_C( 21201.570) },
      { -SIMDE_FLOAT32_C(   667.715), -SIMDE_FLOAT32_C(   129.354), -SIMDE_FLOAT32_C( 37504.672), -SIMDE_FLOAT32_C( 21201.570) } },
    { {  SIMDE_FLOAT32_C(   981.659), -SIMDE_FLOAT32_C(   873.152) },
      {  SIMDE_FLOAT64_C( 83367.734), -SIMDE_FLOAT64_C( 98388.281) },
      {  SIMDE_FLOAT32_C(   981.659), -SIMDE_FLOAT32_C(   873.152),  SIMDE_FLOAT32_C( 83367.734), -SIMDE_FLOAT32_C( 98388.281) } },
    { {  SIMDE_FLOAT32_C(   450.735),  SIMDE_FLOAT32_C(   560.921) },
      { -SIMDE_FLOAT64_C(  3083.563),  SIMDE_FLOAT64_C( 98364.953) },
      {  SIMDE_FLOAT32_C(   450.735),  SIMDE_FLOAT32_C(   560.921), -SIMDE_FLOAT32_C(  3083.563),  SIMDE_FLOAT32_C( 98364.953) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float32x4_t r = simde_vcvtx_high_f32_f64(buf, a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t buf = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float32x4_t r = simde_vcvtx_high_f32_f64(buf, a);

    simde_test_arm_neon_write_f32x2(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_bf16_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32_t a[4];
    simde_bfloat16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   797.26), SIMDE_FLOAT32_C(   229.13), SIMDE_FLOAT32_C(   344.37), SIMDE_FLOAT32_C(   315.27) },
      { SIMDE_BFLOAT16_VALUE(   796.00), SIMDE_BFLOAT16_VALUE(   229.00), SIMDE_BFLOAT16_VALUE(   344.00), SIMDE_BFLOAT16_VALUE(   316.00) } },
    { { SIMDE_FLOAT32_C(  -649.66), SIMDE_FLOAT32_C(  -120.10), SIMDE_FLOAT32_C(   452.41), SIMDE_FLOAT32_C(  -963.13) },
      { SIMDE_BFLOAT16_VALUE(  -648.00), SIMDE_BFLOAT16_VALUE(  -120.00), SIMDE_BFLOAT16_VALUE(   452.00), SIMDE_BFLOAT16_VALUE(  -964.00) } },
    { { SIMDE_FLOAT32_C(   860.52), SIMDE_FLOAT32_C(   434.19), SIMDE_FLOAT32_C(  -916.52), SIMDE_FLOAT32_C(   292.15) },
      { SIMDE_BFLOAT16_VALUE(   860.00), SIMDE_BFLOAT16_VALUE(   434.00), SIMDE_BFLOAT16_VALUE(  -916.00), SIMDE_BFLOAT16_VALUE(   292.00) } },
    { { SIMDE_FLOAT32_C(  -616.07), SIMDE_FLOAT32_C(  -682.86), SIMDE_FLOAT32_C(  -929.66), SIMDE_FLOAT32_C(   699.98) },
      { SIMDE_BFLOAT16_VALUE(  -616.00), SIMDE_BFLOAT16_VALUE(  -684.00), SIMDE_BFLOAT16_VALUE(  -928.00), SIMDE_BFLOAT16_VALUE(   700.00) } },
    { { SIMDE_FLOAT32_C(   727.29), SIMDE_FLOAT32_C(  -756.32), SIMDE_FLOAT32_C(   149.91), SIMDE_FLOAT32_C(  -673.19) },
      { SIMDE_BFLOAT16_VALUE(   728.00), SIMDE_BFLOAT16_VALUE(  -756.00), SIMDE_BFLOAT16_VALUE(   150.00), SIMDE_BFLOAT16_VALUE(  -672.00) } },
    { { SIMDE_FLOAT32_C(  -378.54), SIMDE_FLOAT32_C(  -694.93), SIMDE_FLOAT32_C(  -667.13), SIMDE_FLOAT32_C(   808.37) },
      { SIMDE_BFLOAT16_VALUE(  -378.00), SIMDE_BFLOAT16_VALUE(  -696.00), SIMDE_BFLOAT16_VALUE(  -668.00), SIMDE_BFLOAT16_VALUE(   808.00) } },
    { { SIMDE_FLOAT32_C(    68.80), SIMDE_FLOAT32_C(   564.38), SIMDE_FLOAT32_C(  -586.51), SIMDE_FLOAT32_C(    81.23) },
      { SIMDE_BFLOAT16_VALUE(    69.00), SIMDE_BFLOAT16_VALUE(   564.00), SIMDE_BFLOAT16_VALUE(  -588.00), SIMDE_BFLOAT16_VALUE(    81.00) } },
    { { SIMDE_FLOAT32_C(   250.43), SIMDE_FLOAT32_C(  -181.74), SIMDE_FLOAT32_C(   899.88), SIMDE_FLOAT32_C(    47.69) },
      { SIMDE_BFLOAT16_VALUE(   250.00), SIMDE_BFLOAT16_VALUE(  -182.00), SIMDE_BFLOAT16_VALUE(   900.00), SIMDE_BFLOAT16_VALUE(    47.75) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_bfloat16x4_t r = simde_vcvt_bf16_f32(a);

    simde_test_arm_neon_assert_equal_bf16x4(r, simde_vld1_bf16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_bfloat16x4_t r = simde_vcvt_bf16_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_bf16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvt_f32_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16_t a[4];
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(   117.00), SIMDE_BFLOAT16_VALUE(  -636.00), SIMDE_BFLOAT16_VALUE(    12.12), SIMDE_BFLOAT16_VALUE(   -50.25) },
      { SIMDE_FLOAT32_C(   117.00), SIMDE_FLOAT32_C(  -636.00), SIMDE_FLOAT32_C(    12.12), SIMDE_FLOAT32_C(   -50.25) } },
    { { SIMDE_BFLOAT16_VALUE(  -816.00), SIMDE_BFLOAT16_VALUE(   292.00), SIMDE_BFLOAT16_VALUE(  -516.00), SIMDE_BFLOAT16_VALUE(  -656.00) },
      { SIMDE_FLOAT32_C(  -816.00), SIMDE_FLOAT32_C(   292.00), SIMDE_FLOAT32_C(  -516.00), SIMDE_FLOAT32_C(  -656.00) } },
    { { SIMDE_BFLOAT16_VALUE(   133.00), SIMDE_BFLOAT16_VALUE(   776.00), SIMDE_BFLOAT16_VALUE(   334.00), SIMDE_BFLOAT16_VALUE(  -716.00) },
      { SIMDE_FLOAT32_C(   133.00), SIMDE_FLOAT32_C(   776.00), SIMDE_FLOAT32_C(   334.00), SIMDE_FLOAT32_C(  -716.00) } },
    { { SIMDE_BFLOAT16_VALUE(   592.00), SIMDE_BFLOAT16_VALUE(  -728.00), SIMDE_BFLOAT16_VALUE(   294.00), SIMDE_BFLOAT16_VALUE(    63.00) },
      { SIMDE_FLOAT32_C(   592.00), SIMDE_FLOAT32_C(  -728.00), SIMDE_FLOAT32_C(   294.00), SIMDE_FLOAT32_C(    63.00) } },
    { { SIMDE_BFLOAT16_VALUE(   322.00), SIMDE_BFLOAT16_VALUE(  -676.00), SIMDE_BFLOAT16_VALUE(  -234.00), SIMDE_BFLOAT16_VALUE(   820.00) },
      { SIMDE_FLOAT32_C(   322.00), SIMDE_FLOAT32_C(  -676.00), SIMDE_FLOAT32_C(  -234.00), SIMDE_FLOAT32_C(   820.00) } },
    { { SIMDE_BFLOAT16_VALUE(   888.00), SIMDE_BFLOAT16_VALUE(   428.00), SIMDE_BFLOAT16_VALUE(  -608.00), SIMDE_BFLOAT16_VALUE(   308.00) },
      { SIMDE_FLOAT32_C(   888.00), SIMDE_FLOAT32_C(   428.00), SIMDE_FLOAT32_C(  -608.00), SIMDE_FLOAT32_C(   308.00) } },
    { { SIMDE_BFLOAT16_VALUE(  -672.00), SIMDE_BFLOAT16_VALUE(   612.00), SIMDE_BFLOAT16_VALUE(   207.00), SIMDE_BFLOAT16_VALUE(   948.00) },
      { SIMDE_FLOAT32_C(  -672.00), SIMDE_FLOAT32_C(   612.00), SIMDE_FLOAT32_C(   207.00), SIMDE_FLOAT32_C(   948.00) } },
    { { SIMDE_BFLOAT16_VALUE(   330.00), SIMDE_BFLOAT16_VALUE(   952.00), SIMDE_BFLOAT16_VALUE(   632.00), SIMDE_BFLOAT16_VALUE(  -552.00) },
      { SIMDE_FLOAT32_C(   330.00), SIMDE_FLOAT32_C(   952.00), SIMDE_FLOAT32_C(   632.00), SIMDE_FLOAT32_C(  -552.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x4_t a = simde_vld1_bf16(test_vec[i].a);
    simde_float32x4_t r = simde_vcvt_f32_bf16(a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_bfloat16x4_t a = simde_test_arm_neon_random_bf16x4(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_float32x4_t r = simde_vcvt_f32_bf16(a);

    simde_test_arm_neon_write_bf16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtah_f32_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16_t a;
    simde_float32_t r;
  } test_vec[] = {
    { SIMDE_BFLOAT16_VALUE(   111.50),
      SIMDE_FLOAT32_C(   111.50) },
    { SIMDE_BFLOAT16_VALUE(   456.00),
      SIMDE_FLOAT32_C(   456.00) },
    { SIMDE_BFLOAT16_VALUE(   454.00),
      SIMDE_FLOAT32_C(   454.00) },
    { SIMDE_BFLOAT16_VALUE(  -880.00),
      SIMDE_FLOAT32_C(  -880.00) },
    { SIMDE_BFLOAT16_VALUE(  -292.00),
      SIMDE_FLOAT32_C(  -292.00) },
    { SIMDE_BFLOAT16_VALUE(   956.00),
      SIMDE_FLOAT32_C(   956.00) },
    { SIMDE_BFLOAT16_VALUE(  -193.00),
      SIMDE_FLOAT32_C(  -193.00) },
    { SIMDE_BFLOAT16_VALUE(  -692.00),
      SIMDE_FLOAT32_C(  -692.00) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32_t r = simde_vcvtah_f32_bf16(test_vec[i].a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_bfloat16_t a = simde_test_codegen_random_bf16(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_float32_t r = simde_vcvtah_f32_bf16(a);

    simde_test_codegen_write_bf16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvth_bf16_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32_t a;
    simde_bfloat16_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(  -614.15),
      SIMDE_BFLOAT16_VALUE(  -616.00) },
    { SIMDE_FLOAT32_C(   155.05),
      SIMDE_BFLOAT16_VALUE(   155.00) },
    { SIMDE_FLOAT32_C(  -344.88),
      SIMDE_BFLOAT16_VALUE(  -344.00) },
    { SIMDE_FLOAT32_C(  -544.03),
      SIMDE_BFLOAT16_VALUE(  -544.00) },
    { SIMDE_FLOAT32_C(   952.07),
      SIMDE_BFLOAT16_VALUE(   952.00) },
    { SIMDE_FLOAT32_C(   722.53),
      SIMDE_BFLOAT16_VALUE(   724.00) },
    { SIMDE_FLOAT32_C(  -898.84),
      SIMDE_BFLOAT16_VALUE(  -900.00) },
    { SIMDE_FLOAT32_C(  -620.87),
      SIMDE_BFLOAT16_VALUE(  -620.00) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16_t r = simde_vcvth_bf16_f32(test_vec[i].a);

    simde_assert_equal_bf16(r, test_vec[i].r, 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0, 1000.0);
    simde_bfloat16_t r = simde_vcvth_bf16_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_bf16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_low_f32_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16_t a[8];
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(   -30.50), SIMDE_BFLOAT16_VALUE(  -860.00), SIMDE_BFLOAT16_VALUE(   424.00), SIMDE_BFLOAT16_VALUE(  -984.00),
        SIMDE_BFLOAT16_VALUE(  -262.00), SIMDE_BFLOAT16_VALUE(    99.00), SIMDE_BFLOAT16_VALUE(   884.00), SIMDE_BFLOAT16_VALUE(  -628.00) },
      { SIMDE_FLOAT32_C(   -30.50), SIMDE_FLOAT32_C(  -860.00), SIMDE_FLOAT32_C(   424.00), SIMDE_FLOAT32_C(  -984.00) } },
    { { SIMDE_BFLOAT16_VALUE(   608.00), SIMDE_BFLOAT16_VALUE(   268.00), SIMDE_BFLOAT16_VALUE(  -748.00), SIMDE_BFLOAT16_VALUE(   988.00),
        SIMDE_BFLOAT16_VALUE(  -183.00), SIMDE_BFLOAT16_VALUE(   -69.00), SIMDE_BFLOAT16_VALUE(  -198.00), SIMDE_BFLOAT16_VALUE(  -434.00) },
      { SIMDE_FLOAT32_C(   608.00), SIMDE_FLOAT32_C(   268.00), SIMDE_FLOAT32_C(  -748.00), SIMDE_FLOAT32_C(   988.00) } },
    { { SIMDE_BFLOAT16_VALUE(   105.00), SIMDE_BFLOAT16_VALUE(  -772.00), SIMDE_BFLOAT16_VALUE(   432.00), SIMDE_BFLOAT16_VALUE(  -320.00),
        SIMDE_BFLOAT16_VALUE(   268.00), SIMDE_BFLOAT16_VALUE(   492.00), SIMDE_BFLOAT16_VALUE(  -984.00), SIMDE_BFLOAT16_VALUE(   800.00) },
      { SIMDE_FLOAT32_C(   105.00), SIMDE_FLOAT32_C(  -772.00), SIMDE_FLOAT32_C(   432.00), SIMDE_FLOAT32_C(  -320.00) } },
    { { SIMDE_BFLOAT16_VALUE(  -512.00), SIMDE_BFLOAT16_VALUE(   456.00), SIMDE_BFLOAT16_VALUE(   378.00), SIMDE_BFLOAT16_VALUE(   540.00),
        SIMDE_BFLOAT16_VALUE(  -868.00), SIMDE_BFLOAT16_VALUE(  -860.00), SIMDE_BFLOAT16_VALUE(    -2.16), SIMDE_BFLOAT16_VALUE(   103.00) },
      { SIMDE_FLOAT32_C(  -512.00), SIMDE_FLOAT32_C(   456.00), SIMDE_FLOAT32_C(   378.00), SIMDE_FLOAT32_C(   540.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8_t a = simde_vld1q_bf16(test_vec[i].a);
    simde_float32x4_t r = simde_vcvtq_low_f32_bf16(a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_bfloat16x8_t a = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_float32x4_t r = simde_vcvtq_low_f32_bf16(a);

    simde_test_arm_neon_write_bf16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_high_f32_bf16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16_t a[8];
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(   213.00), SIMDE_BFLOAT16_VALUE(   223.00), SIMDE_BFLOAT16_VALUE(   580.00), SIMDE_BFLOAT16_VALUE(  -952.00),
        SIMDE_BFLOAT16_VALUE(  -732.00), SIMDE_BFLOAT16_VALUE(  -900.00), SIMDE_BFLOAT16_VALUE(  -416.00), SIMDE_BFLOAT16_VALUE(  -640.00) },
      { SIMDE_FLOAT32_C(  -732.00), SIMDE_FLOAT32_C(  -900.00), SIMDE_FLOAT32_C(  -416.00), SIMDE_FLOAT32_C(  -640.00) } },
    { { SIMDE_BFLOAT16_VALUE(   708.00), SIMDE_BFLOAT16_VALUE(  -748.00), SIMDE_BFLOAT16_VALUE(  -524.00), SIMDE_BFLOAT16_VALUE(  -316.00),
        SIMDE_BFLOAT16_VALUE(  -180.00), SIMDE_BFLOAT16_VALUE(  -712.00), SIMDE_BFLOAT16_VALUE(   432.00), SIMDE_BFLOAT16_VALUE(   318.00) },
      { SIMDE_FLOAT32_C(  -180.00), SIMDE_FLOAT32_C(  -712.00), SIMDE_FLOAT32_C(   432.00), SIMDE_FLOAT32_C(   318.00) } },
    { { SIMDE_BFLOAT16_VALUE(   824.00), SIMDE_BFLOAT16_VALUE(  -362.00), SIMDE_BFLOAT16_VALUE(   256.00), SIMDE_BFLOAT16_VALUE(   808.00),
        SIMDE_BFLOAT16_VALUE(    92.50), SIMDE_BFLOAT16_VALUE(   380.00), SIMDE_BFLOAT16_VALUE(  -422.00), SIMDE_BFLOAT16_VALUE(  -608.00) },
      { SIMDE_FLOAT32_C(    92.50), SIMDE_FLOAT32_C(   380.00), SIMDE_FLOAT32_C(  -422.00), SIMDE_FLOAT32_C(  -608.00) } },
    { { SIMDE_BFLOAT16_VALUE(   688.00), SIMDE_BFLOAT16_VALUE(  -300.00), SIMDE_BFLOAT16_VALUE(  -812.00), SIMDE_BFLOAT16_VALUE(   720.00),
        SIMDE_BFLOAT16_VALUE(   728.00), SIMDE_BFLOAT16_VALUE(  -274.00), SIMDE_BFLOAT16_VALUE(   -56.50), SIMDE_BFLOAT16_VALUE(   -60.50) },
      { SIMDE_FLOAT32_C(   728.00), SIMDE_FLOAT32_C(  -274.00), SIMDE_FLOAT32_C(   -56.50), SIMDE_FLOAT32_C(   -60.50) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8_t a = simde_vld1q_bf16(test_vec[i].a);
    simde_float32x4_t r = simde_vcvtq_high_f32_bf16(a);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_bfloat16x8_t a = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_float32x4_t r = simde_vcvtq_high_f32_bf16(a);

    simde_test_arm_neon_write_bf16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_low_bf16_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32_t a[4];
    simde_bfloat16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -701.24), SIMDE_FLOAT32_C(  -714.20), SIMDE_FLOAT32_C(  -963.85), SIMDE_FLOAT32_C(   314.60) },
      { SIMDE_BFLOAT16_VALUE(  -700.00), SIMDE_BFLOAT16_VALUE(  -716.00), SIMDE_BFLOAT16_VALUE(  -964.00), SIMDE_BFLOAT16_VALUE(   314.00),
        SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00) } },
    { { SIMDE_FLOAT32_C(  -888.30), SIMDE_FLOAT32_C(  -957.30), SIMDE_FLOAT32_C(   -62.19), SIMDE_FLOAT32_C(   885.41) },
      { SIMDE_BFLOAT16_VALUE(  -888.00), SIMDE_BFLOAT16_VALUE(  -956.00), SIMDE_BFLOAT16_VALUE(   -62.25), SIMDE_BFLOAT16_VALUE(   884.00),
        SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00) } },
    { { SIMDE_FLOAT32_C(  -193.79), SIMDE_FLOAT32_C(   606.35), SIMDE_FLOAT32_C(   848.78), SIMDE_FLOAT32_C(  -888.62) },
      { SIMDE_BFLOAT16_VALUE(  -194.00), SIMDE_BFLOAT16_VALUE(   608.00), SIMDE_BFLOAT16_VALUE(   848.00), SIMDE_BFLOAT16_VALUE(  -888.00),
        SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00) } },
    { { SIMDE_FLOAT32_C(   393.77), SIMDE_FLOAT32_C(   651.13), SIMDE_FLOAT32_C(   692.47), SIMDE_FLOAT32_C(  -491.41) },
      { SIMDE_BFLOAT16_VALUE(   394.00), SIMDE_BFLOAT16_VALUE(   652.00), SIMDE_BFLOAT16_VALUE(   692.00), SIMDE_BFLOAT16_VALUE(  -492.00),
        SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00), SIMDE_BFLOAT16_VALUE(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_bfloat16x8_t r = simde_vcvtq_low_bf16_f32(a);

    simde_test_arm_neon_assert_equal_bf16x8(r, simde_vld1q_bf16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_bfloat16x8_t r = simde_vcvtq_low_bf16_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_bf16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcvtq_high_bf16_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16_t inactive[8];
    simde_float32_t a[4];
    simde_bfloat16_t r[8];
  } test_vec[] = {
    { { SIMDE_BFLOAT16_VALUE(  -114.50), SIMDE_BFLOAT16_VALUE(   158.00), SIMDE_BFLOAT16_VALUE(   536.00), SIMDE_BFLOAT16_VALUE(   119.00),
        SIMDE_BFLOAT16_VALUE(   624.00), SIMDE_BFLOAT16_VALUE(   228.00), SIMDE_BFLOAT16_VALUE(    12.56), SIMDE_BFLOAT16_VALUE(  -852.00) },
      { SIMDE_FLOAT32_C(  -332.48), SIMDE_FLOAT32_C(   318.31), SIMDE_FLOAT32_C(  -852.48), SIMDE_FLOAT32_C(   741.06) },
      { SIMDE_BFLOAT16_VALUE(  -114.50), SIMDE_BFLOAT16_VALUE(   158.00), SIMDE_BFLOAT16_VALUE(   536.00), SIMDE_BFLOAT16_VALUE(   119.00),
        SIMDE_BFLOAT16_VALUE(  -332.00), SIMDE_BFLOAT16_VALUE(   318.00), SIMDE_BFLOAT16_VALUE(  -852.00), SIMDE_BFLOAT16_VALUE(   740.00) } },
    { { SIMDE_BFLOAT16_VALUE(    34.50), SIMDE_BFLOAT16_VALUE(   868.00), SIMDE_BFLOAT16_VALUE(   224.00), SIMDE_BFLOAT16_VALUE(  -812.00),
        SIMDE_BFLOAT16_VALUE(  -732.00), SIMDE_BFLOAT16_VALUE(  -360.00), SIMDE_BFLOAT16_VALUE(   908.00), SIMDE_BFLOAT16_VALUE(  -816.00) },
      { SIMDE_FLOAT32_C(   783.96), SIMDE_FLOAT32_C(   537.75), SIMDE_FLOAT32_C(  -247.99), SIMDE_FLOAT32_C(    99.18) },
      { SIMDE_BFLOAT16_VALUE(    34.50), SIMDE_BFLOAT16_VALUE(   868.00), SIMDE_BFLOAT16_VALUE(   224.00), SIMDE_BFLOAT16_VALUE(  -812.00),
        SIMDE_BFLOAT16_VALUE(   784.00), SIMDE_BFLOAT16_VALUE(   536.00), SIMDE_BFLOAT16_VALUE(  -248.00), SIMDE_BFLOAT16_VALUE(    99.00) } },
    { { SIMDE_BFLOAT16_VALUE(  -892.00), SIMDE_BFLOAT16_VALUE(   -57.75), SIMDE_BFLOAT16_VALUE(   -60.00), SIMDE_BFLOAT16_VALUE(  -872.00),
        SIMDE_BFLOAT16_VALUE(   620.00), SIMDE_BFLOAT16_VALUE(  -280.00), SIMDE_BFLOAT16_VALUE(   154.00), SIMDE_BFLOAT16_VALUE(  -494.00) },
      { SIMDE_FLOAT32_C(   878.16), SIMDE_FLOAT32_C(  -310.72), SIMDE_FLOAT32_C(   626.10), SIMDE_FLOAT32_C(   504.14) },
      { SIMDE_BFLOAT16_VALUE(  -892.00), SIMDE_BFLOAT16_VALUE(   -57.75), SIMDE_BFLOAT16_VALUE(   -60.00), SIMDE_BFLOAT16_VALUE(  -872.00),
        SIMDE_BFLOAT16_VALUE(   880.00), SIMDE_BFLOAT16_VALUE(  -310.00), SIMDE_BFLOAT16_VALUE(   628.00), SIMDE_BFLOAT16_VALUE(   504.00) } },
    { { SIMDE_BFLOAT16_VALUE(   916.00), SIMDE_BFLOAT16_VALUE(  -362.00), SIMDE_BFLOAT16_VALUE(   652.00), SIMDE_BFLOAT16_VALUE(  -414.00),
        SIMDE_BFLOAT16_VALUE(   956.00), SIMDE_BFLOAT16_VALUE(   800.00), SIMDE_BFLOAT16_VALUE(  -672.00), SIMDE_BFLOAT16_VALUE(    -8.56) },
      { SIMDE_FLOAT32_C(   667.89), SIMDE_FLOAT32_C(   550.42), SIMDE_FLOAT32_C(   177.82), SIMDE_FLOAT32_C(   934.96) },
      { SIMDE_BFLOAT16_VALUE(   916.00), SIMDE_BFLOAT16_VALUE(  -362.00), SIMDE_BFLOAT16_VALUE(   652.00), SIMDE_BFLOAT16_VALUE(  -414.00),
        SIMDE_BFLOAT16_VALUE(   668.00), SIMDE_BFLOAT16_VALUE(   552.00), SIMDE_BFLOAT16_VALUE(   178.00), SIMDE_BFLOAT16_VALUE(   936.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_bfloat16x8_t inactive = simde_vld1q_bf16(test_vec[i].inactive);
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_bfloat16x8_t r = simde_vcvtq_high_bf16_f32(inactive, a);

    simde_test_arm_neon_assert_equal_bf16x8(r, simde_vld1q_bf16(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_bfloat16x8_t inactive = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-1000.0), SIMDE_BFLOAT16_VALUE(1000.0));
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0, 1000.0);
    simde_bfloat16x8_t r = simde_vcvtq_high_bf16_f32(inactive, a);

    simde_test_arm_neon_write_bf16x8(2, inactive, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
//SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_s32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_s64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_u32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_u64_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_f16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_f16_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_f16_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_f16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_f16_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_f16_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvts_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtd_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f64_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_f64_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f16_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f64_f32)


//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtah_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtah_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtah_s32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtah_u32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtah_s64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtah_u64_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtas_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtas_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtad_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtad_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvta_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvta_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvta_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvta_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvta_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvta_u64_f64)

//SIMDE_TEST_FUNC_LIST_ENTRY(vcvtaq_s16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtaq_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtaq_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtaq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtaq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtaq_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_high_f16_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_high_f32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_high_f32_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_high_f64_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvtxd_f32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtx_f32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtx_high_f32_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_bf16_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvt_f32_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtah_f32_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvth_bf16_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_low_f32_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_high_f32_bf16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_low_bf16_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcvtq_high_bf16_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
