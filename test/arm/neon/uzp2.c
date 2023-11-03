#define SIMDE_TEST_ARM_NEON_INSN uzp2

#include "test-neon.h"
#include "../../../simde/arm/neon/uzp2.h"

static int
test_simde_vuzp2_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    simde_float16_t b[4];
    simde_float16_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(   -49.28), SIMDE_FLOAT16_VALUE(  -109.00), SIMDE_FLOAT16_VALUE(  -626.50), SIMDE_FLOAT16_VALUE(  -567.00) },
      { SIMDE_FLOAT16_VALUE(  -178.88), SIMDE_FLOAT16_VALUE(    10.22), SIMDE_FLOAT16_VALUE(   976.50), SIMDE_FLOAT16_VALUE(   -31.19) },
      { SIMDE_FLOAT16_VALUE(  -109.00), SIMDE_FLOAT16_VALUE(  -567.00), SIMDE_FLOAT16_VALUE(    10.22), SIMDE_FLOAT16_VALUE(   -31.19) } },
    { { SIMDE_FLOAT16_VALUE(  -226.00), SIMDE_FLOAT16_VALUE(  -520.50), SIMDE_FLOAT16_VALUE(  -252.38), SIMDE_FLOAT16_VALUE(  -407.50) },
      { SIMDE_FLOAT16_VALUE(    89.44), SIMDE_FLOAT16_VALUE(  -200.50), SIMDE_FLOAT16_VALUE(  -439.75), SIMDE_FLOAT16_VALUE(  -450.75) },
      { SIMDE_FLOAT16_VALUE(  -520.50), SIMDE_FLOAT16_VALUE(  -407.50), SIMDE_FLOAT16_VALUE(  -200.50), SIMDE_FLOAT16_VALUE(  -450.75) } },
    { { SIMDE_FLOAT16_VALUE(  -833.00), SIMDE_FLOAT16_VALUE(  -714.00), SIMDE_FLOAT16_VALUE(   428.50), SIMDE_FLOAT16_VALUE(   871.50) },
      { SIMDE_FLOAT16_VALUE(  -157.12), SIMDE_FLOAT16_VALUE(   972.50), SIMDE_FLOAT16_VALUE(   298.75), SIMDE_FLOAT16_VALUE(  -919.50) },
      { SIMDE_FLOAT16_VALUE(  -714.00), SIMDE_FLOAT16_VALUE(   871.50), SIMDE_FLOAT16_VALUE(   972.50), SIMDE_FLOAT16_VALUE(  -919.50) } },
    { { SIMDE_FLOAT16_VALUE(   488.00), SIMDE_FLOAT16_VALUE(   112.56), SIMDE_FLOAT16_VALUE(    58.66), SIMDE_FLOAT16_VALUE(   879.50) },
      { SIMDE_FLOAT16_VALUE(   129.00), SIMDE_FLOAT16_VALUE(  -858.50), SIMDE_FLOAT16_VALUE(  -133.88), SIMDE_FLOAT16_VALUE(  -920.50) },
      { SIMDE_FLOAT16_VALUE(   112.56), SIMDE_FLOAT16_VALUE(   879.50), SIMDE_FLOAT16_VALUE(  -858.50), SIMDE_FLOAT16_VALUE(  -920.50) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a, b, r;

    a = simde_vld1_f16(test_vec[i].a);
    b = simde_vld1_f16(test_vec[i].b);
    r = simde_vuzp2_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vuzp2_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   343.73), SIMDE_FLOAT32_C(  -384.82) },
      { SIMDE_FLOAT32_C(   348.76), SIMDE_FLOAT32_C(   874.35) },
      { SIMDE_FLOAT32_C(  -384.82), SIMDE_FLOAT32_C(   874.35) } },
    { { SIMDE_FLOAT32_C(   328.67), SIMDE_FLOAT32_C(  -556.62) },
      { SIMDE_FLOAT32_C(  -584.13), SIMDE_FLOAT32_C(   886.34) },
      { SIMDE_FLOAT32_C(  -556.62), SIMDE_FLOAT32_C(   886.34) } },
    { { SIMDE_FLOAT32_C(  -727.41), SIMDE_FLOAT32_C(   622.83) },
      { SIMDE_FLOAT32_C(  -328.14), SIMDE_FLOAT32_C(   552.33) },
      { SIMDE_FLOAT32_C(   622.83), SIMDE_FLOAT32_C(   552.33) } },
    { { SIMDE_FLOAT32_C(   169.12), SIMDE_FLOAT32_C(   762.41) },
      { SIMDE_FLOAT32_C(  -165.94), SIMDE_FLOAT32_C(   247.93) },
      { SIMDE_FLOAT32_C(   762.41), SIMDE_FLOAT32_C(   247.93) } },
    { { SIMDE_FLOAT32_C(   975.47), SIMDE_FLOAT32_C(   559.60) },
      { SIMDE_FLOAT32_C(   -75.67), SIMDE_FLOAT32_C(   142.37) },
      { SIMDE_FLOAT32_C(   559.60), SIMDE_FLOAT32_C(   142.37) } },
    { { SIMDE_FLOAT32_C(  -342.52), SIMDE_FLOAT32_C(  -803.88) },
      { SIMDE_FLOAT32_C(  -138.51), SIMDE_FLOAT32_C(  -568.39) },
      { SIMDE_FLOAT32_C(  -803.88), SIMDE_FLOAT32_C(  -568.39) } },
    { { SIMDE_FLOAT32_C(   706.38), SIMDE_FLOAT32_C(  -329.34) },
      { SIMDE_FLOAT32_C(  -697.68), SIMDE_FLOAT32_C(   236.14) },
      { SIMDE_FLOAT32_C(  -329.34), SIMDE_FLOAT32_C(   236.14) } },
    { { SIMDE_FLOAT32_C(   537.08), SIMDE_FLOAT32_C(   467.12) },
      { SIMDE_FLOAT32_C(   923.63), SIMDE_FLOAT32_C(  -119.19) },
      { SIMDE_FLOAT32_C(   467.12), SIMDE_FLOAT32_C(  -119.19) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, b, r;

    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    r = simde_vuzp2_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vuzp2_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  74),  INT8_C(  41), -INT8_C( 101), -INT8_C(  39),  INT8_C(  90), -INT8_C( 112),  INT8_C(  51),  INT8_C(  51) },
      { -INT8_C( 123), -INT8_C( 118), -INT8_C(   2),  INT8_C( 101),  INT8_C(  68), -INT8_C( 103), -INT8_C(  57), -INT8_C(  67) },
      {  INT8_C(  41), -INT8_C(  39), -INT8_C( 112),  INT8_C(  51), -INT8_C( 118),  INT8_C( 101), -INT8_C( 103), -INT8_C(  67) } },
    { {  INT8_C(  20),  INT8_C( 116),  INT8_C(  51),  INT8_C(  68), -INT8_C(  48),  INT8_C(  60),  INT8_C(  39),  INT8_C(  78) },
      { -INT8_C(  64),  INT8_C(  38),  INT8_C(  69), -INT8_C(  38), -INT8_C(  56),  INT8_C(  75), -INT8_C(   7),  INT8_C(  18) },
      {  INT8_C( 116),  INT8_C(  68),  INT8_C(  60),  INT8_C(  78),  INT8_C(  38), -INT8_C(  38),  INT8_C(  75),  INT8_C(  18) } },
    { {  INT8_C( 117), -INT8_C( 108), -INT8_C(  21), -INT8_C(  49),  INT8_C(  37),  INT8_C(  31),  INT8_C(   2), -INT8_C(  86) },
      { -INT8_C(  87),  INT8_C(   0),  INT8_C(  15), -INT8_C(  19), -INT8_C( 103), -INT8_C(  42), -INT8_C(  86), -INT8_C(  82) },
      { -INT8_C( 108), -INT8_C(  49),  INT8_C(  31), -INT8_C(  86),  INT8_C(   0), -INT8_C(  19), -INT8_C(  42), -INT8_C(  82) } },
    { {  INT8_C(  74), -INT8_C(  34), -INT8_C(  14),  INT8_C(  27),  INT8_C(  26),  INT8_C(  25),  INT8_C( 105), -INT8_C(  38) },
      {  INT8_C(  63), -INT8_C(  82), -INT8_C(  75),  INT8_C(   7), -INT8_C(   7), -INT8_C(  82),  INT8_C(  25),  INT8_C( 110) },
      { -INT8_C(  34),  INT8_C(  27),  INT8_C(  25), -INT8_C(  38), -INT8_C(  82),  INT8_C(   7), -INT8_C(  82),  INT8_C( 110) } },
    { {  INT8_C(  66),  INT8_C(   4),  INT8_C(  61),  INT8_C( 103),  INT8_C(  35),  INT8_C(  64),  INT8_C(  17), -INT8_C(  52) },
      {  INT8_C(  64),  INT8_C(  32), -INT8_C(  71), -INT8_C(  38), -INT8_C(   9),  INT8_C( 100), -INT8_C( 120),  INT8_C(  65) },
      {  INT8_C(   4),  INT8_C( 103),  INT8_C(  64), -INT8_C(  52),  INT8_C(  32), -INT8_C(  38),  INT8_C( 100),  INT8_C(  65) } },
    { {  INT8_C(  66),  INT8_C( 122),  INT8_C(  92),  INT8_C(  92), -INT8_C( 109), -INT8_C(  59),  INT8_C(  55), -INT8_C(  46) },
      {  INT8_C( 115), -INT8_C(  20), -INT8_C(  39),  INT8_C( 109), -INT8_C( 102), -INT8_C(  14), -INT8_C(  37), -INT8_C(  36) },
      {  INT8_C( 122),  INT8_C(  92), -INT8_C(  59), -INT8_C(  46), -INT8_C(  20),  INT8_C( 109), -INT8_C(  14), -INT8_C(  36) } },
    { { -INT8_C(  10),  INT8_C(  25),  INT8_C(  68),  INT8_C(  26),  INT8_C(  89),  INT8_C(  85), -INT8_C(  26), -INT8_C( 103) },
      {  INT8_C( 118), -INT8_C(  96),  INT8_C( 115),  INT8_C( 109),  INT8_C(   4), -INT8_C(   5), -INT8_C(  82),  INT8_C(  70) },
      {  INT8_C(  25),  INT8_C(  26),  INT8_C(  85), -INT8_C( 103), -INT8_C(  96),  INT8_C( 109), -INT8_C(   5),  INT8_C(  70) } },
    { {  INT8_C( 117),  INT8_C(  11), -INT8_C(  94),  INT8_C(   8), -INT8_C(  48), -INT8_C(  39), -INT8_C(  38),  INT8_C(  68) },
      { -INT8_C(  59), -INT8_C(  77), -INT8_C(  79),  INT8_C(  95), -INT8_C(  91), -INT8_C( 116),  INT8_C(  60), -INT8_C( 100) },
      {  INT8_C(  11),  INT8_C(   8), -INT8_C(  39),  INT8_C(  68), -INT8_C(  77),  INT8_C(  95), -INT8_C( 116), -INT8_C( 100) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vuzp2_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vuzp2_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(  8469),  INT16_C(  4214),  INT16_C(  6247), -INT16_C( 14565) },
      {  INT16_C( 17510), -INT16_C( 31761), -INT16_C( 26454),  INT16_C(  6595) },
      {  INT16_C(  4214), -INT16_C( 14565), -INT16_C( 31761),  INT16_C(  6595) } },
    { {  INT16_C( 15772), -INT16_C( 26012),  INT16_C( 25267),  INT16_C( 18574) },
      {  INT16_C( 26296),  INT16_C( 18542), -INT16_C( 31381),  INT16_C( 22512) },
      { -INT16_C( 26012),  INT16_C( 18574),  INT16_C( 18542),  INT16_C( 22512) } },
    { {  INT16_C( 26211), -INT16_C( 13465), -INT16_C( 32129), -INT16_C(  6766) },
      { -INT16_C( 32313),  INT16_C( 29032),  INT16_C( 11289), -INT16_C( 19062) },
      { -INT16_C( 13465), -INT16_C(  6766),  INT16_C( 29032), -INT16_C( 19062) } },
    { { -INT16_C(  4503),  INT16_C(  7247), -INT16_C(  8624),  INT16_C(  2405) },
      { -INT16_C( 11452), -INT16_C( 20399),  INT16_C( 16984), -INT16_C( 17401) },
      {  INT16_C(  7247),  INT16_C(  2405), -INT16_C( 20399), -INT16_C( 17401) } },
    { {  INT16_C( 28328),  INT16_C( 10119),  INT16_C(  6640), -INT16_C( 18676) },
      {  INT16_C( 30106), -INT16_C( 19416), -INT16_C( 19551),  INT16_C(  2665) },
      {  INT16_C( 10119), -INT16_C( 18676), -INT16_C( 19416),  INT16_C(  2665) } },
    { { -INT16_C( 18015), -INT16_C(  3546), -INT16_C( 29801), -INT16_C(  9221) },
      {  INT16_C( 19550), -INT16_C( 18549), -INT16_C( 28018),  INT16_C( 14195) },
      { -INT16_C(  3546), -INT16_C(  9221), -INT16_C( 18549),  INT16_C( 14195) } },
    { { -INT16_C(  1536), -INT16_C(  3746),  INT16_C( 27411), -INT16_C( 21080) },
      { -INT16_C( 11808), -INT16_C( 32415), -INT16_C( 13436),  INT16_C(  9611) },
      { -INT16_C(  3746), -INT16_C( 21080), -INT16_C( 32415),  INT16_C(  9611) } },
    { { -INT16_C( 20092),  INT16_C(  6935),  INT16_C(  4669), -INT16_C( 25610) },
      { -INT16_C( 32161), -INT16_C(  4782), -INT16_C( 15084),  INT16_C(  5412) },
      {  INT16_C(  6935), -INT16_C( 25610), -INT16_C(  4782),  INT16_C(  5412) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vuzp2_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vuzp2_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   700519944),  INT32_C(   806752298) },
      { -INT32_C(  1414503859), -INT32_C(  1821262512) },
      {  INT32_C(   806752298), -INT32_C(  1821262512) } },
    { { -INT32_C(  1774050292),  INT32_C(   309171441) },
      { -INT32_C(  1372346662),  INT32_C(  1901278057) },
      {  INT32_C(   309171441),  INT32_C(  1901278057) } },
    { {  INT32_C(  1939477833),  INT32_C(  1923330085) },
      {  INT32_C(  1646088978),  INT32_C(   485854992) },
      {  INT32_C(  1923330085),  INT32_C(   485854992) } },
    { { -INT32_C(  1531824205), -INT32_C(  1498013749) },
      {  INT32_C(   794094022),  INT32_C(  1705027612) },
      { -INT32_C(  1498013749),  INT32_C(  1705027612) } },
    { { -INT32_C(   489145667), -INT32_C(    61506582) },
      { -INT32_C(   564170034), -INT32_C(  1258662911) },
      { -INT32_C(    61506582), -INT32_C(  1258662911) } },
    { {  INT32_C(  1465429388), -INT32_C(  1828909364) },
      {  INT32_C(   331436791), -INT32_C(  1216847366) },
      { -INT32_C(  1828909364), -INT32_C(  1216847366) } },
    { { -INT32_C(  2053549925), -INT32_C(  1719472437) },
      {  INT32_C(  1652023649), -INT32_C(  1055428043) },
      { -INT32_C(  1719472437), -INT32_C(  1055428043) } },
    { { -INT32_C(   350654689),  INT32_C(  1971197566) },
      {  INT32_C(  1653161832),  INT32_C(  1008271777) },
      {  INT32_C(  1971197566),  INT32_C(  1008271777) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vuzp2_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vuzp2_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 32), UINT8_C(115), UINT8_C( 94), UINT8_C(134), UINT8_C(188), UINT8_C(  5), UINT8_C( 28), UINT8_C( 50) },
      { UINT8_C( 84), UINT8_C( 27), UINT8_C(113), UINT8_C(241),    UINT8_MAX, UINT8_C( 18), UINT8_C(122), UINT8_C( 84) },
      { UINT8_C(115), UINT8_C(134), UINT8_C(  5), UINT8_C( 50), UINT8_C( 27), UINT8_C(241), UINT8_C( 18), UINT8_C( 84) } },
    { { UINT8_C( 24), UINT8_C( 59), UINT8_C(106), UINT8_C(201), UINT8_C( 70), UINT8_C(150), UINT8_C( 86), UINT8_C(152) },
      { UINT8_C(111), UINT8_C(245), UINT8_C(121), UINT8_C(191), UINT8_C(114), UINT8_C(111), UINT8_C( 11), UINT8_C(146) },
      { UINT8_C( 59), UINT8_C(201), UINT8_C(150), UINT8_C(152), UINT8_C(245), UINT8_C(191), UINT8_C(111), UINT8_C(146) } },
    { { UINT8_C(226), UINT8_C(105), UINT8_C( 24), UINT8_C(158), UINT8_C(110), UINT8_C( 52), UINT8_C(208), UINT8_C(194) },
      { UINT8_C( 79), UINT8_C( 66), UINT8_C(180), UINT8_C( 78), UINT8_C( 84), UINT8_C( 46), UINT8_C(162), UINT8_C(108) },
      { UINT8_C(105), UINT8_C(158), UINT8_C( 52), UINT8_C(194), UINT8_C( 66), UINT8_C( 78), UINT8_C( 46), UINT8_C(108) } },
    { { UINT8_C(105), UINT8_C( 12), UINT8_C( 53), UINT8_C(176), UINT8_C(162), UINT8_C(139), UINT8_C( 72), UINT8_C( 17) },
      { UINT8_C(128), UINT8_C(193), UINT8_C(209), UINT8_C(242), UINT8_C( 48), UINT8_C(220), UINT8_C(132), UINT8_C( 18) },
      { UINT8_C( 12), UINT8_C(176), UINT8_C(139), UINT8_C( 17), UINT8_C(193), UINT8_C(242), UINT8_C(220), UINT8_C( 18) } },
    { { UINT8_C( 69), UINT8_C(156), UINT8_C(176), UINT8_C(180), UINT8_C(209), UINT8_C(129), UINT8_C(118), UINT8_C( 32) },
      { UINT8_C(195), UINT8_C( 42), UINT8_C(111), UINT8_C( 23), UINT8_C( 89), UINT8_C( 17), UINT8_C(131), UINT8_C(194) },
      { UINT8_C(156), UINT8_C(180), UINT8_C(129), UINT8_C( 32), UINT8_C( 42), UINT8_C( 23), UINT8_C( 17), UINT8_C(194) } },
    { { UINT8_C( 30), UINT8_C(184), UINT8_C(114), UINT8_C(192), UINT8_C( 67), UINT8_C(186), UINT8_C(210), UINT8_C(195) },
      { UINT8_C(124), UINT8_C(163), UINT8_C(182), UINT8_C(172), UINT8_C(127), UINT8_C( 58), UINT8_C(191), UINT8_C(196) },
      { UINT8_C(184), UINT8_C(192), UINT8_C(186), UINT8_C(195), UINT8_C(163), UINT8_C(172), UINT8_C( 58), UINT8_C(196) } },
    { { UINT8_C(215), UINT8_C(111), UINT8_C(120), UINT8_C(168), UINT8_C(240), UINT8_C(239), UINT8_C(200), UINT8_C(179) },
      { UINT8_C( 25), UINT8_C( 55), UINT8_C(202), UINT8_C(114), UINT8_C( 73), UINT8_C( 77), UINT8_C( 53), UINT8_C(103) },
      { UINT8_C(111), UINT8_C(168), UINT8_C(239), UINT8_C(179), UINT8_C( 55), UINT8_C(114), UINT8_C( 77), UINT8_C(103) } },
    { { UINT8_C(  5), UINT8_C(167), UINT8_C( 39), UINT8_C( 72), UINT8_C( 98), UINT8_C(249), UINT8_C( 12), UINT8_C(222) },
      { UINT8_C(156), UINT8_C(194), UINT8_C(138), UINT8_C( 27), UINT8_C(252), UINT8_C( 73), UINT8_C(224), UINT8_C(211) },
      { UINT8_C(167), UINT8_C( 72), UINT8_C(249), UINT8_C(222), UINT8_C(194), UINT8_C( 27), UINT8_C( 73), UINT8_C(211) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vuzp2_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vuzp2_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C( 5562), UINT16_C(29929), UINT16_C(59535), UINT16_C( 4681) },
      { UINT16_C( 4562), UINT16_C(56009), UINT16_C(26174), UINT16_C(13284) },
      { UINT16_C(29929), UINT16_C( 4681), UINT16_C(56009), UINT16_C(13284) } },
    { { UINT16_C( 5231), UINT16_C( 5283), UINT16_C(50924), UINT16_C(52138) },
      { UINT16_C(51348), UINT16_C(34623), UINT16_C(61476), UINT16_C(57252) },
      { UINT16_C( 5283), UINT16_C(52138), UINT16_C(34623), UINT16_C(57252) } },
    { { UINT16_C(36102), UINT16_C(38227), UINT16_C(40053), UINT16_C(18343) },
      { UINT16_C(28845), UINT16_C(60193), UINT16_C( 1494), UINT16_C(17950) },
      { UINT16_C(38227), UINT16_C(18343), UINT16_C(60193), UINT16_C(17950) } },
    { { UINT16_C(49434), UINT16_C( 1626), UINT16_C( 1159), UINT16_C( 7122) },
      { UINT16_C( 4556), UINT16_C(61603), UINT16_C(18177), UINT16_C( 1999) },
      { UINT16_C( 1626), UINT16_C( 7122), UINT16_C(61603), UINT16_C( 1999) } },
    { { UINT16_C( 8916), UINT16_C(18844), UINT16_C(17342), UINT16_C(27536) },
      { UINT16_C(45748), UINT16_C(35414), UINT16_C(29879), UINT16_C(53712) },
      { UINT16_C(18844), UINT16_C(27536), UINT16_C(35414), UINT16_C(53712) } },
    { { UINT16_C(10805), UINT16_C(48344), UINT16_C(43566), UINT16_C(64216) },
      { UINT16_C(31675), UINT16_C(48363), UINT16_C(47810), UINT16_C(38596) },
      { UINT16_C(48344), UINT16_C(64216), UINT16_C(48363), UINT16_C(38596) } },
    { { UINT16_C(24797), UINT16_C(39903), UINT16_C(28580), UINT16_C(22535) },
      { UINT16_C(23841), UINT16_C(55778), UINT16_C(46034), UINT16_C( 1962) },
      { UINT16_C(39903), UINT16_C(22535), UINT16_C(55778), UINT16_C( 1962) } },
    { { UINT16_C(33501), UINT16_C( 3268), UINT16_C(39980), UINT16_C(59142) },
      { UINT16_C(61719), UINT16_C(55716), UINT16_C(26796), UINT16_C(35183) },
      { UINT16_C( 3268), UINT16_C(59142), UINT16_C(55716), UINT16_C(35183) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vuzp2_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vuzp2_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(4094091955), UINT32_C(3041287499) },
      { UINT32_C(2743144671), UINT32_C(3197617136) },
      { UINT32_C(3041287499), UINT32_C(3197617136) } },
    { { UINT32_C(2304641764), UINT32_C(2188309395) },
      { UINT32_C(1096318907), UINT32_C( 611816304) },
      { UINT32_C(2188309395), UINT32_C( 611816304) } },
    { { UINT32_C(3222830453), UINT32_C(3128254171) },
      { UINT32_C(1599993711), UINT32_C(2652828858) },
      { UINT32_C(3128254171), UINT32_C(2652828858) } },
    { { UINT32_C(2435284222), UINT32_C( 722769264) },
      { UINT32_C(2221698068), UINT32_C(1957225727) },
      { UINT32_C( 722769264), UINT32_C(1957225727) } },
    { { UINT32_C(1010090337), UINT32_C(2398530079) },
      { UINT32_C(1542345633), UINT32_C(1173949511) },
      { UINT32_C(2398530079), UINT32_C(1173949511) } },
    { { UINT32_C(4174848136), UINT32_C(3374640053) },
      { UINT32_C(1464701015), UINT32_C(3603691124) },
      { UINT32_C(3374640053), UINT32_C(3603691124) } },
    { { UINT32_C(3591504055), UINT32_C(1264912810) },
      { UINT32_C(2762363740), UINT32_C(3890847583) },
      { UINT32_C(1264912810), UINT32_C(3890847583) } },
    { { UINT32_C(1960886463), UINT32_C(  54330539) },
      { UINT32_C( 156928660), UINT32_C( 937371008) },
      { UINT32_C(  54330539), UINT32_C( 937371008) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vuzp2_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vuzp2_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    simde_float16_t b[8];
    simde_float16_t r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE( 90.452),  SIMDE_FLOAT16_VALUE( 17.701), SIMDE_FLOAT16_VALUE( - 49.009), SIMDE_FLOAT16_VALUE( - 88.786),
        SIMDE_FLOAT16_VALUE( - 29.009), SIMDE_FLOAT16_VALUE( - 37.203), SIMDE_FLOAT16_VALUE( - 58.225),  SIMDE_FLOAT16_VALUE( 98.368) },
      {  SIMDE_FLOAT16_VALUE( 19.440), SIMDE_FLOAT16_VALUE( -  1.659),  SIMDE_FLOAT16_VALUE( 42.542), SIMDE_FLOAT16_VALUE( - 99.688),
        SIMDE_FLOAT16_VALUE( - 88.443),  SIMDE_FLOAT16_VALUE( 34.706), SIMDE_FLOAT16_VALUE( - 85.533), SIMDE_FLOAT16_VALUE( - 56.781) },
      {  SIMDE_FLOAT16_VALUE( 17.701), SIMDE_FLOAT16_VALUE( - 88.786), SIMDE_FLOAT16_VALUE( - 37.203),  SIMDE_FLOAT16_VALUE( 98.368),
        SIMDE_FLOAT16_VALUE( -  1.659), SIMDE_FLOAT16_VALUE( - 99.688),  SIMDE_FLOAT16_VALUE( 34.706), SIMDE_FLOAT16_VALUE( - 56.781) } },
    { {  SIMDE_FLOAT16_VALUE( 33.998),  SIMDE_FLOAT16_VALUE(  9.488), SIMDE_FLOAT16_VALUE( - 57.721), SIMDE_FLOAT16_VALUE( - 25.485),
        SIMDE_FLOAT16_VALUE( - 94.073), SIMDE_FLOAT16_VALUE( - 82.899),  SIMDE_FLOAT16_VALUE( 44.365), SIMDE_FLOAT16_VALUE( - 99.238) },
      {  SIMDE_FLOAT16_VALUE(  9.551),  SIMDE_FLOAT16_VALUE( 89.969), SIMDE_FLOAT16_VALUE( - 86.075), SIMDE_FLOAT16_VALUE( - 77.835),
         SIMDE_FLOAT16_VALUE(  0.704), SIMDE_FLOAT16_VALUE( - 29.406),  SIMDE_FLOAT16_VALUE( 20.191), SIMDE_FLOAT16_VALUE( - 38.311) },
      {  SIMDE_FLOAT16_VALUE(  9.488), SIMDE_FLOAT16_VALUE( - 25.485), SIMDE_FLOAT16_VALUE( - 82.899), SIMDE_FLOAT16_VALUE( - 99.238),
         SIMDE_FLOAT16_VALUE( 89.969), SIMDE_FLOAT16_VALUE( - 77.835), SIMDE_FLOAT16_VALUE( - 29.406), SIMDE_FLOAT16_VALUE( - 38.311) } },
    { {  SIMDE_FLOAT16_VALUE( 77.669),  SIMDE_FLOAT16_VALUE( 71.372),  SIMDE_FLOAT16_VALUE( 54.402),  SIMDE_FLOAT16_VALUE( 77.171),
         SIMDE_FLOAT16_VALUE( 37.815),  SIMDE_FLOAT16_VALUE( 41.042), SIMDE_FLOAT16_VALUE( - 13.386),  SIMDE_FLOAT16_VALUE( 20.748) },
      { SIMDE_FLOAT16_VALUE( - 98.103), SIMDE_FLOAT16_VALUE( - 63.759), SIMDE_FLOAT16_VALUE( - 16.397), SIMDE_FLOAT16_VALUE( - 83.256),
        SIMDE_FLOAT16_VALUE( - 23.909), SIMDE_FLOAT16_VALUE( - 69.358),  SIMDE_FLOAT16_VALUE( 53.308),  SIMDE_FLOAT16_VALUE( 92.091) },
      {  SIMDE_FLOAT16_VALUE( 71.372),  SIMDE_FLOAT16_VALUE( 77.171),  SIMDE_FLOAT16_VALUE( 41.042),  SIMDE_FLOAT16_VALUE( 20.748),
        SIMDE_FLOAT16_VALUE( - 63.759), SIMDE_FLOAT16_VALUE( - 83.256), SIMDE_FLOAT16_VALUE( - 69.358),  SIMDE_FLOAT16_VALUE( 92.091) } },
    { {  SIMDE_FLOAT16_VALUE(  0.764), SIMDE_FLOAT16_VALUE( - 93.449),  SIMDE_FLOAT16_VALUE( 78.083),  SIMDE_FLOAT16_VALUE( 10.810),
         SIMDE_FLOAT16_VALUE( 94.958),  SIMDE_FLOAT16_VALUE( 38.118),  SIMDE_FLOAT16_VALUE( 48.405),  SIMDE_FLOAT16_VALUE( 98.273) },
      { SIMDE_FLOAT16_VALUE( - 11.121), SIMDE_FLOAT16_VALUE( - 18.789), SIMDE_FLOAT16_VALUE( - 60.496), SIMDE_FLOAT16_VALUE( - 49.152),
        SIMDE_FLOAT16_VALUE( - 38.385), SIMDE_FLOAT16_VALUE( - 40.755),  SIMDE_FLOAT16_VALUE( 93.481),  SIMDE_FLOAT16_VALUE( 93.409) },
      { SIMDE_FLOAT16_VALUE( - 93.449),  SIMDE_FLOAT16_VALUE( 10.810),  SIMDE_FLOAT16_VALUE( 38.118),  SIMDE_FLOAT16_VALUE( 98.273),
        SIMDE_FLOAT16_VALUE( - 18.789), SIMDE_FLOAT16_VALUE( - 49.152), SIMDE_FLOAT16_VALUE( - 40.755),  SIMDE_FLOAT16_VALUE( 93.409) } },
    { {  SIMDE_FLOAT16_VALUE( 60.980),  SIMDE_FLOAT16_VALUE( 44.087),  SIMDE_FLOAT16_VALUE(  4.420), SIMDE_FLOAT16_VALUE( - 86.379),
        SIMDE_FLOAT16_VALUE( - 21.956),  SIMDE_FLOAT16_VALUE( 66.211),  SIMDE_FLOAT16_VALUE( 40.919),  SIMDE_FLOAT16_VALUE( 44.341) },
      { SIMDE_FLOAT16_VALUE( -  6.654),  SIMDE_FLOAT16_VALUE( 74.703),  SIMDE_FLOAT16_VALUE( 90.296), SIMDE_FLOAT16_VALUE( - 32.224),
        SIMDE_FLOAT16_VALUE( - 62.184),  SIMDE_FLOAT16_VALUE( 60.075),  SIMDE_FLOAT16_VALUE( 54.181), SIMDE_FLOAT16_VALUE( - 32.279) },
      {  SIMDE_FLOAT16_VALUE( 44.087), SIMDE_FLOAT16_VALUE( - 86.379),  SIMDE_FLOAT16_VALUE( 66.211),  SIMDE_FLOAT16_VALUE( 44.341),
         SIMDE_FLOAT16_VALUE( 74.703), SIMDE_FLOAT16_VALUE( - 32.224),  SIMDE_FLOAT16_VALUE( 60.075), SIMDE_FLOAT16_VALUE( - 32.279) } },
    { { SIMDE_FLOAT16_VALUE( - 18.086), SIMDE_FLOAT16_VALUE( - 93.397),  SIMDE_FLOAT16_VALUE( 80.704), SIMDE_FLOAT16_VALUE( - 25.237),
         SIMDE_FLOAT16_VALUE( 67.082),  SIMDE_FLOAT16_VALUE( 45.500), SIMDE_FLOAT16_VALUE( - 42.821),  SIMDE_FLOAT16_VALUE( 30.047) },
      {  SIMDE_FLOAT16_VALUE( 33.473), SIMDE_FLOAT16_VALUE( - 16.060),  SIMDE_FLOAT16_VALUE( 82.753), SIMDE_FLOAT16_VALUE( - 97.939),
         SIMDE_FLOAT16_VALUE( 55.855),  SIMDE_FLOAT16_VALUE( 32.741),  SIMDE_FLOAT16_VALUE( 82.947), SIMDE_FLOAT16_VALUE( - 16.162) },
      { SIMDE_FLOAT16_VALUE( - 93.397), SIMDE_FLOAT16_VALUE( - 25.237),  SIMDE_FLOAT16_VALUE( 45.500),  SIMDE_FLOAT16_VALUE( 30.047),
        SIMDE_FLOAT16_VALUE( - 16.060), SIMDE_FLOAT16_VALUE( - 97.939),  SIMDE_FLOAT16_VALUE( 32.741), SIMDE_FLOAT16_VALUE( - 16.162) } },
    { {  SIMDE_FLOAT16_VALUE( 39.481), SIMDE_FLOAT16_VALUE( - 43.751),  SIMDE_FLOAT16_VALUE( 46.517),  SIMDE_FLOAT16_VALUE( 73.973),
        SIMDE_FLOAT16_VALUE( - 63.824), SIMDE_FLOAT16_VALUE( - 81.545),  SIMDE_FLOAT16_VALUE( 80.086),  SIMDE_FLOAT16_VALUE(  5.275) },
      {  SIMDE_FLOAT16_VALUE( 47.213),  SIMDE_FLOAT16_VALUE( 95.067), SIMDE_FLOAT16_VALUE( - 53.211),  SIMDE_FLOAT16_VALUE( 47.692),
         SIMDE_FLOAT16_VALUE( 71.401), SIMDE_FLOAT16_VALUE( - 54.682),  SIMDE_FLOAT16_VALUE( 74.308), SIMDE_FLOAT16_VALUE( - 33.162) },
      { SIMDE_FLOAT16_VALUE( - 43.751),  SIMDE_FLOAT16_VALUE( 73.973), SIMDE_FLOAT16_VALUE( - 81.545),  SIMDE_FLOAT16_VALUE(  5.275),
         SIMDE_FLOAT16_VALUE( 95.067),  SIMDE_FLOAT16_VALUE( 47.692), SIMDE_FLOAT16_VALUE( - 54.682), SIMDE_FLOAT16_VALUE( - 33.162) } },
    { {  SIMDE_FLOAT16_VALUE( 93.150), SIMDE_FLOAT16_VALUE( - 92.626),  SIMDE_FLOAT16_VALUE( 71.362), SIMDE_FLOAT16_VALUE( - 72.353),
         SIMDE_FLOAT16_VALUE( 24.600), SIMDE_FLOAT16_VALUE( - 79.615), SIMDE_FLOAT16_VALUE( - 49.427), SIMDE_FLOAT16_VALUE( - 48.559) },
      { SIMDE_FLOAT16_VALUE( - 35.290), SIMDE_FLOAT16_VALUE( - 24.706),  SIMDE_FLOAT16_VALUE( 98.487),  SIMDE_FLOAT16_VALUE( 58.278),
        SIMDE_FLOAT16_VALUE( - 53.949), SIMDE_FLOAT16_VALUE( - 40.152),  SIMDE_FLOAT16_VALUE( 29.818),  SIMDE_FLOAT16_VALUE( 53.465) },
      { SIMDE_FLOAT16_VALUE( - 92.626), SIMDE_FLOAT16_VALUE( - 72.353), SIMDE_FLOAT16_VALUE( - 79.615), SIMDE_FLOAT16_VALUE( - 48.559),
        SIMDE_FLOAT16_VALUE( - 24.706),  SIMDE_FLOAT16_VALUE( 58.278), SIMDE_FLOAT16_VALUE( - 40.152),  SIMDE_FLOAT16_VALUE( 53.465) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vuzp2q_f16(a, b);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vuzp2q_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -781.39), SIMDE_FLOAT32_C(    88.58), SIMDE_FLOAT32_C(   100.41), SIMDE_FLOAT32_C(   266.53) },
      { SIMDE_FLOAT32_C(   803.29), SIMDE_FLOAT32_C(  -418.13), SIMDE_FLOAT32_C(    24.45), SIMDE_FLOAT32_C(   955.27) },
      { SIMDE_FLOAT32_C(    88.58), SIMDE_FLOAT32_C(   266.53), SIMDE_FLOAT32_C(  -418.13), SIMDE_FLOAT32_C(   955.27) } },
    { { SIMDE_FLOAT32_C(   -28.60), SIMDE_FLOAT32_C(  -622.57), SIMDE_FLOAT32_C(   870.72), SIMDE_FLOAT32_C(   957.13) },
      { SIMDE_FLOAT32_C(  -115.95), SIMDE_FLOAT32_C(  -205.52), SIMDE_FLOAT32_C(  -866.47), SIMDE_FLOAT32_C(  -650.57) },
      { SIMDE_FLOAT32_C(  -622.57), SIMDE_FLOAT32_C(   957.13), SIMDE_FLOAT32_C(  -205.52), SIMDE_FLOAT32_C(  -650.57) } },
    { { SIMDE_FLOAT32_C(   110.44), SIMDE_FLOAT32_C(   300.16), SIMDE_FLOAT32_C(  -300.84), SIMDE_FLOAT32_C(   217.46) },
      { SIMDE_FLOAT32_C(  -171.62), SIMDE_FLOAT32_C(   375.64), SIMDE_FLOAT32_C(   342.58), SIMDE_FLOAT32_C(    76.53) },
      { SIMDE_FLOAT32_C(   300.16), SIMDE_FLOAT32_C(   217.46), SIMDE_FLOAT32_C(   375.64), SIMDE_FLOAT32_C(    76.53) } },
    { { SIMDE_FLOAT32_C(  -412.19), SIMDE_FLOAT32_C(  -951.34), SIMDE_FLOAT32_C(   730.36), SIMDE_FLOAT32_C(   100.26) },
      { SIMDE_FLOAT32_C(   107.62), SIMDE_FLOAT32_C(   786.75), SIMDE_FLOAT32_C(   778.67), SIMDE_FLOAT32_C(   326.23) },
      { SIMDE_FLOAT32_C(  -951.34), SIMDE_FLOAT32_C(   100.26), SIMDE_FLOAT32_C(   786.75), SIMDE_FLOAT32_C(   326.23) } },
    { { SIMDE_FLOAT32_C(  -124.68), SIMDE_FLOAT32_C(  -120.92), SIMDE_FLOAT32_C(  -407.25), SIMDE_FLOAT32_C(  -321.39) },
      { SIMDE_FLOAT32_C(   460.95), SIMDE_FLOAT32_C(   617.20), SIMDE_FLOAT32_C(  -366.12), SIMDE_FLOAT32_C(  -567.65) },
      { SIMDE_FLOAT32_C(  -120.92), SIMDE_FLOAT32_C(  -321.39), SIMDE_FLOAT32_C(   617.20), SIMDE_FLOAT32_C(  -567.65) } },
    { { SIMDE_FLOAT32_C(   994.64), SIMDE_FLOAT32_C(  -495.39), SIMDE_FLOAT32_C(  -610.52), SIMDE_FLOAT32_C(  -121.31) },
      { SIMDE_FLOAT32_C(   299.08), SIMDE_FLOAT32_C(  -477.00), SIMDE_FLOAT32_C(   228.11), SIMDE_FLOAT32_C(  -590.48) },
      { SIMDE_FLOAT32_C(  -495.39), SIMDE_FLOAT32_C(  -121.31), SIMDE_FLOAT32_C(  -477.00), SIMDE_FLOAT32_C(  -590.48) } },
    { { SIMDE_FLOAT32_C(   823.17), SIMDE_FLOAT32_C(   927.28), SIMDE_FLOAT32_C(   626.99), SIMDE_FLOAT32_C(  -348.45) },
      { SIMDE_FLOAT32_C(   302.91), SIMDE_FLOAT32_C(   -30.44), SIMDE_FLOAT32_C(   728.08), SIMDE_FLOAT32_C(   890.73) },
      { SIMDE_FLOAT32_C(   927.28), SIMDE_FLOAT32_C(  -348.45), SIMDE_FLOAT32_C(   -30.44), SIMDE_FLOAT32_C(   890.73) } },
    { { SIMDE_FLOAT32_C(    18.22), SIMDE_FLOAT32_C(   458.45), SIMDE_FLOAT32_C(    -9.02), SIMDE_FLOAT32_C(  -874.16) },
      { SIMDE_FLOAT32_C(   245.19), SIMDE_FLOAT32_C(  -230.35), SIMDE_FLOAT32_C(   452.07), SIMDE_FLOAT32_C(  -879.48) },
      { SIMDE_FLOAT32_C(   458.45), SIMDE_FLOAT32_C(  -874.16), SIMDE_FLOAT32_C(  -230.35), SIMDE_FLOAT32_C(  -879.48) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vuzp2q_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vuzp2q_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -339.85), SIMDE_FLOAT64_C(  -574.12) },
      { SIMDE_FLOAT64_C(   477.11), SIMDE_FLOAT64_C(   -17.44) },
      { SIMDE_FLOAT64_C(  -574.12), SIMDE_FLOAT64_C(   -17.44) } },
    { { SIMDE_FLOAT64_C(  -819.58), SIMDE_FLOAT64_C(  -361.32) },
      { SIMDE_FLOAT64_C(  -283.52), SIMDE_FLOAT64_C(   -25.85) },
      { SIMDE_FLOAT64_C(  -361.32), SIMDE_FLOAT64_C(   -25.85) } },
    { { SIMDE_FLOAT64_C(   881.34), SIMDE_FLOAT64_C(   140.92) },
      { SIMDE_FLOAT64_C(  -394.34), SIMDE_FLOAT64_C(   314.91) },
      { SIMDE_FLOAT64_C(   140.92), SIMDE_FLOAT64_C(   314.91) } },
    { { SIMDE_FLOAT64_C(  -960.58), SIMDE_FLOAT64_C(   916.46) },
      { SIMDE_FLOAT64_C(    40.77), SIMDE_FLOAT64_C(   550.34) },
      { SIMDE_FLOAT64_C(   916.46), SIMDE_FLOAT64_C(   550.34) } },
    { { SIMDE_FLOAT64_C(   784.55), SIMDE_FLOAT64_C(  -320.66) },
      { SIMDE_FLOAT64_C(   942.86), SIMDE_FLOAT64_C(   541.82) },
      { SIMDE_FLOAT64_C(  -320.66), SIMDE_FLOAT64_C(   541.82) } },
    { { SIMDE_FLOAT64_C(   991.85), SIMDE_FLOAT64_C(   533.80) },
      { SIMDE_FLOAT64_C(  -388.26), SIMDE_FLOAT64_C(   204.04) },
      { SIMDE_FLOAT64_C(   533.80), SIMDE_FLOAT64_C(   204.04) } },
    { { SIMDE_FLOAT64_C(   -77.27), SIMDE_FLOAT64_C(   884.24) },
      { SIMDE_FLOAT64_C(   202.14), SIMDE_FLOAT64_C(   892.43) },
      { SIMDE_FLOAT64_C(   884.24), SIMDE_FLOAT64_C(   892.43) } },
    { { SIMDE_FLOAT64_C(  -326.62), SIMDE_FLOAT64_C(  -793.35) },
      { SIMDE_FLOAT64_C(  -340.99), SIMDE_FLOAT64_C(   333.54) },
      { SIMDE_FLOAT64_C(  -793.35), SIMDE_FLOAT64_C(   333.54) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vuzp2q_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r = simde_vuzp2q_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  69),  INT8_C(  59), -INT8_C(  19),  INT8_C(  70), -INT8_C(  88), -INT8_C(  12),  INT8_C(  31), -INT8_C(  75),
        -INT8_C(  45), -INT8_C( 113), -INT8_C(  84), -INT8_C( 102),  INT8_C(  44),  INT8_C( 120),  INT8_C(  29),  INT8_C(  35) },
      {  INT8_C(  95), -INT8_C( 119),  INT8_C(  70),  INT8_C(  64), -INT8_C(  30),  INT8_C( 105), -INT8_C(  87),  INT8_C(  30),
        -INT8_C(  21),  INT8_C(  45),  INT8_C(  82),  INT8_C(  18), -INT8_C( 117),  INT8_C( 116),  INT8_C(  26), -INT8_C(  48) },
      {  INT8_C(  59),  INT8_C(  70), -INT8_C(  12), -INT8_C(  75), -INT8_C( 113), -INT8_C( 102),  INT8_C( 120),  INT8_C(  35),
        -INT8_C( 119),  INT8_C(  64),  INT8_C( 105),  INT8_C(  30),  INT8_C(  45),  INT8_C(  18),  INT8_C( 116), -INT8_C(  48) } },
    { { -INT8_C(  81),  INT8_C(   7),  INT8_C(  22),  INT8_C(  87), -INT8_C(   4),  INT8_C(  53),  INT8_C(  12), -INT8_C(  49),
        -INT8_C(  59), -INT8_C(  71),  INT8_C( 105), -INT8_C(  15),  INT8_C(  49), -INT8_C( 121),  INT8_C(  21), -INT8_C( 112) },
      {  INT8_C(  16),  INT8_C(  91), -INT8_C(  48), -INT8_C(  14), -INT8_C(  59),  INT8_C( 121),  INT8_C(  16), -INT8_C(  80),
        -INT8_C(  90),  INT8_C(  99), -INT8_C(  61),  INT8_C(  49), -INT8_C(  41), -INT8_C(  35),  INT8_C(   1), -INT8_C( 121) },
      {  INT8_C(   7),  INT8_C(  87),  INT8_C(  53), -INT8_C(  49), -INT8_C(  71), -INT8_C(  15), -INT8_C( 121), -INT8_C( 112),
         INT8_C(  91), -INT8_C(  14),  INT8_C( 121), -INT8_C(  80),  INT8_C(  99),  INT8_C(  49), -INT8_C(  35), -INT8_C( 121) } },
    { { -INT8_C(  28),  INT8_C(  23), -INT8_C(  34), -INT8_C(  32),  INT8_C(  77), -INT8_C(  21), -INT8_C(  80),  INT8_C(  18),
        -INT8_C(  92),  INT8_C(  25),  INT8_C(   3), -INT8_C(  43), -INT8_C(  96),  INT8_C(  24),  INT8_C( 101), -INT8_C(  79) },
      {  INT8_C( 116),  INT8_C(  53), -INT8_C(  93),  INT8_C(  57), -INT8_C(  82), -INT8_C(  76), -INT8_C(  23),  INT8_C(  84),
         INT8_C(  23), -INT8_C(  84), -INT8_C( 122), -INT8_C(  18), -INT8_C( 119), -INT8_C( 121),  INT8_C( 117),  INT8_C( 110) },
      {  INT8_C(  23), -INT8_C(  32), -INT8_C(  21),  INT8_C(  18),  INT8_C(  25), -INT8_C(  43),  INT8_C(  24), -INT8_C(  79),
         INT8_C(  53),  INT8_C(  57), -INT8_C(  76),  INT8_C(  84), -INT8_C(  84), -INT8_C(  18), -INT8_C( 121),  INT8_C( 110) } },
    { { -INT8_C(  97),  INT8_C(  84),  INT8_C(  78), -INT8_C(  20),  INT8_C(  63), -INT8_C(   2), -INT8_C(   2), -INT8_C(  29),
         INT8_C(  24),  INT8_C(   1), -INT8_C(  72), -INT8_C(  72),  INT8_C(  26),  INT8_C(  29),  INT8_C( 105), -INT8_C( 114) },
      {  INT8_C(  82),  INT8_C(  13), -INT8_C(  57),  INT8_C(   0), -INT8_C(  63), -INT8_C(  80),  INT8_C(  84), -INT8_C(  40),
         INT8_C(  93), -INT8_C(  38), -INT8_C(  58), -INT8_C(  26),  INT8_C(  98),  INT8_C(  60),  INT8_C(  84),  INT8_C(   1) },
      {  INT8_C(  84), -INT8_C(  20), -INT8_C(   2), -INT8_C(  29),  INT8_C(   1), -INT8_C(  72),  INT8_C(  29), -INT8_C( 114),
         INT8_C(  13),  INT8_C(   0), -INT8_C(  80), -INT8_C(  40), -INT8_C(  38), -INT8_C(  26),  INT8_C(  60),  INT8_C(   1) } },
    { { -INT8_C( 112), -INT8_C(  93), -INT8_C(  19), -INT8_C(  49), -INT8_C(  95), -INT8_C(  21), -INT8_C(  78), -INT8_C(  71),
        -INT8_C(  20),  INT8_C( 106),  INT8_C( 114),  INT8_C(   6), -INT8_C( 121), -INT8_C(  37), -INT8_C( 108), -INT8_C(  39) },
      { -INT8_C(  24),  INT8_C(  91), -INT8_C(  39), -INT8_C(  87),  INT8_C(  12),  INT8_C(  45), -INT8_C( 127),  INT8_C( 105),
         INT8_C(   8),  INT8_C(  72),  INT8_C(  79),  INT8_C( 106), -INT8_C( 124), -INT8_C(  92),  INT8_C( 107),  INT8_C(  20) },
      { -INT8_C(  93), -INT8_C(  49), -INT8_C(  21), -INT8_C(  71),  INT8_C( 106),  INT8_C(   6), -INT8_C(  37), -INT8_C(  39),
         INT8_C(  91), -INT8_C(  87),  INT8_C(  45),  INT8_C( 105),  INT8_C(  72),  INT8_C( 106), -INT8_C(  92),  INT8_C(  20) } },
    { {  INT8_C(  71),  INT8_C(  88), -INT8_C(  29), -INT8_C(  24),  INT8_C(  67), -INT8_C( 107), -INT8_C(  94),  INT8_C(  47),
        -INT8_C(   1),  INT8_C(  20),  INT8_C(  54), -INT8_C( 122), -INT8_C(  17), -INT8_C(  54),  INT8_C(  95), -INT8_C(  40) },
      {  INT8_C(  38),  INT8_C(  56), -INT8_C( 127),  INT8_C(  50),  INT8_C( 101),  INT8_C(   3), -INT8_C( 101),  INT8_C( 109),
         INT8_C(  75), -INT8_C(  22), -INT8_C(  41), -INT8_C(  49), -INT8_C( 114),  INT8_C(  66), -INT8_C(  29), -INT8_C(  43) },
      {  INT8_C(  88), -INT8_C(  24), -INT8_C( 107),  INT8_C(  47),  INT8_C(  20), -INT8_C( 122), -INT8_C(  54), -INT8_C(  40),
         INT8_C(  56),  INT8_C(  50),  INT8_C(   3),  INT8_C( 109), -INT8_C(  22), -INT8_C(  49),  INT8_C(  66), -INT8_C(  43) } },
    { { -INT8_C( 102), -INT8_C(  58), -INT8_C(  66), -INT8_C(  35),  INT8_C(  91),  INT8_C(  96),  INT8_C(  13),  INT8_C(  90),
         INT8_C( 116),  INT8_C(  67), -INT8_C(  32),  INT8_C(  99),  INT8_C(  13),  INT8_C(  63),  INT8_C(  59),  INT8_C(  51) },
      {  INT8_C( 119), -INT8_C(  67),  INT8_C( 101), -INT8_C(  36), -INT8_C(  64),  INT8_C(   0),  INT8_C(  74),  INT8_C(  11),
        -INT8_C(  21),  INT8_C(  33), -INT8_C(  38),  INT8_C( 121),  INT8_C( 100), -INT8_C(  67),  INT8_C(  79), -INT8_C(   2) },
      { -INT8_C(  58), -INT8_C(  35),  INT8_C(  96),  INT8_C(  90),  INT8_C(  67),  INT8_C(  99),  INT8_C(  63),  INT8_C(  51),
        -INT8_C(  67), -INT8_C(  36),  INT8_C(   0),  INT8_C(  11),  INT8_C(  33),  INT8_C( 121), -INT8_C(  67), -INT8_C(   2) } },
    { { -INT8_C( 125),  INT8_C(  13), -INT8_C(  36), -INT8_C(  34),  INT8_C( 109), -INT8_C(  23),  INT8_C(  56), -INT8_C(  31),
         INT8_C(  44),  INT8_C(  24),  INT8_C(  68),  INT8_C(  57),  INT8_C(  87),      INT8_MIN,  INT8_C( 109), -INT8_C(  50) },
      {  INT8_C(  61), -INT8_C(  46), -INT8_C(  86), -INT8_C(   3), -INT8_C(  45), -INT8_C(  12),  INT8_C(   8), -INT8_C(  66),
         INT8_C(  22), -INT8_C(  30),  INT8_C(  55),  INT8_C( 122), -INT8_C(  97), -INT8_C( 122),  INT8_C( 120),  INT8_C(  34) },
      {  INT8_C(  13), -INT8_C(  34), -INT8_C(  23), -INT8_C(  31),  INT8_C(  24),  INT8_C(  57),      INT8_MIN, -INT8_C(  50),
        -INT8_C(  46), -INT8_C(   3), -INT8_C(  12), -INT8_C(  66), -INT8_C(  30),  INT8_C( 122), -INT8_C( 122),  INT8_C(  34) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vuzp2q_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vuzp2q_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 22831),  INT16_C( 10979), -INT16_C( 19770), -INT16_C(  5690),  INT16_C(  6784), -INT16_C(   857), -INT16_C( 21684),  INT16_C(  4304) },
      {  INT16_C( 17678), -INT16_C(  9320), -INT16_C( 16347),  INT16_C( 18514),  INT16_C( 28188), -INT16_C( 11922), -INT16_C( 28199), -INT16_C( 21770) },
      {  INT16_C( 10979), -INT16_C(  5690), -INT16_C(   857),  INT16_C(  4304), -INT16_C(  9320),  INT16_C( 18514), -INT16_C( 11922), -INT16_C( 21770) } },
    { { -INT16_C(  9673), -INT16_C(   555), -INT16_C( 25716),  INT16_C(  3303), -INT16_C( 29003),  INT16_C(   520), -INT16_C( 10183),  INT16_C( 18194) },
      { -INT16_C( 21987),  INT16_C( 17186),  INT16_C( 29802), -INT16_C( 31093), -INT16_C(  1566), -INT16_C( 17321),  INT16_C( 19850), -INT16_C( 16026) },
      { -INT16_C(   555),  INT16_C(  3303),  INT16_C(   520),  INT16_C( 18194),  INT16_C( 17186), -INT16_C( 31093), -INT16_C( 17321), -INT16_C( 16026) } },
    { {  INT16_C( 15143), -INT16_C( 19266), -INT16_C( 23082), -INT16_C( 29504), -INT16_C( 14029),  INT16_C( 27790), -INT16_C( 24415), -INT16_C( 16460) },
      { -INT16_C( 10678), -INT16_C( 19454), -INT16_C( 29365),  INT16_C( 11578), -INT16_C( 28282),  INT16_C(  4329),  INT16_C( 20702),  INT16_C(  1745) },
      { -INT16_C( 19266), -INT16_C( 29504),  INT16_C( 27790), -INT16_C( 16460), -INT16_C( 19454),  INT16_C( 11578),  INT16_C(  4329),  INT16_C(  1745) } },
    { { -INT16_C( 28789),  INT16_C( 25274),  INT16_C( 31285),  INT16_C( 26862),  INT16_C( 31811), -INT16_C(  6699), -INT16_C( 30436),  INT16_C( 26276) },
      { -INT16_C( 22945), -INT16_C( 21990),  INT16_C( 21555), -INT16_C( 17960), -INT16_C( 15899), -INT16_C( 15415), -INT16_C( 26095), -INT16_C( 25143) },
      {  INT16_C( 25274),  INT16_C( 26862), -INT16_C(  6699),  INT16_C( 26276), -INT16_C( 21990), -INT16_C( 17960), -INT16_C( 15415), -INT16_C( 25143) } },
    { { -INT16_C( 31959),  INT16_C( 24319), -INT16_C(  4610),  INT16_C( 16839), -INT16_C( 25495), -INT16_C( 31450), -INT16_C( 13787), -INT16_C( 31509) },
      {  INT16_C(  1392), -INT16_C( 23761),  INT16_C(  1881),  INT16_C( 15964),  INT16_C(  9672), -INT16_C(  9727), -INT16_C( 13377), -INT16_C(  5769) },
      {  INT16_C( 24319),  INT16_C( 16839), -INT16_C( 31450), -INT16_C( 31509), -INT16_C( 23761),  INT16_C( 15964), -INT16_C(  9727), -INT16_C(  5769) } },
    { {  INT16_C( 30286),  INT16_C( 19527),  INT16_C(  3683), -INT16_C( 13170), -INT16_C( 19286), -INT16_C( 12463),  INT16_C( 15487), -INT16_C(  4268) },
      { -INT16_C( 31935), -INT16_C( 25965), -INT16_C(  4214),  INT16_C( 21208), -INT16_C(  9963), -INT16_C( 11220), -INT16_C( 23644), -INT16_C(  3139) },
      {  INT16_C( 19527), -INT16_C( 13170), -INT16_C( 12463), -INT16_C(  4268), -INT16_C( 25965),  INT16_C( 21208), -INT16_C( 11220), -INT16_C(  3139) } },
    { {  INT16_C(  1305),  INT16_C( 31807), -INT16_C( 13037), -INT16_C( 16824), -INT16_C( 26238),  INT16_C(   397), -INT16_C(  7723),  INT16_C(  5872) },
      { -INT16_C( 31900), -INT16_C(  4432), -INT16_C( 30605), -INT16_C( 30655),  INT16_C( 28002),  INT16_C(  1628),  INT16_C(  6673),  INT16_C( 11001) },
      {  INT16_C( 31807), -INT16_C( 16824),  INT16_C(   397),  INT16_C(  5872), -INT16_C(  4432), -INT16_C( 30655),  INT16_C(  1628),  INT16_C( 11001) } },
    { {  INT16_C( 14623),  INT16_C( 12967), -INT16_C(  4346), -INT16_C( 30480),  INT16_C( 32393),  INT16_C( 24201),  INT16_C( 31327), -INT16_C( 15243) },
      {  INT16_C(  9725),  INT16_C( 28850), -INT16_C(  3154),  INT16_C(  4344),  INT16_C( 21857),  INT16_C( 29206),  INT16_C(  4207), -INT16_C( 29028) },
      {  INT16_C( 12967), -INT16_C( 30480),  INT16_C( 24201), -INT16_C( 15243),  INT16_C( 28850),  INT16_C(  4344),  INT16_C( 29206), -INT16_C( 29028) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vuzp2q_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vuzp2q_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1680086568),  INT32_C(  1994775530), -INT32_C(   313035908), -INT32_C(  1619858099) },
      {  INT32_C(  1449835667),  INT32_C(  1456501112), -INT32_C(    78577876), -INT32_C(  1017570149) },
      {  INT32_C(  1994775530), -INT32_C(  1619858099),  INT32_C(  1456501112), -INT32_C(  1017570149) } },
    { {  INT32_C(   489127474), -INT32_C(   711783335), -INT32_C(   842864001),  INT32_C(  1802253528) },
      {  INT32_C(  1774311153),  INT32_C(  1941934407),  INT32_C(   745410705),  INT32_C(  1609549868) },
      { -INT32_C(   711783335),  INT32_C(  1802253528),  INT32_C(  1941934407),  INT32_C(  1609549868) } },
    { { -INT32_C(  1619257786), -INT32_C(  1586229470), -INT32_C(   781306119),  INT32_C(  1547491947) },
      { -INT32_C(   138019408),  INT32_C(   543851919), -INT32_C(  1051928171), -INT32_C(   417317983) },
      { -INT32_C(  1586229470),  INT32_C(  1547491947),  INT32_C(   543851919), -INT32_C(   417317983) } },
    { {  INT32_C(  1938201681), -INT32_C(  1525351765), -INT32_C(  1686731984),  INT32_C(   251114333) },
      {  INT32_C(  1057340848), -INT32_C(   681611198), -INT32_C(   359093431),  INT32_C(   936491494) },
      { -INT32_C(  1525351765),  INT32_C(   251114333), -INT32_C(   681611198),  INT32_C(   936491494) } },
    { {  INT32_C(    27940693), -INT32_C(  2119778479), -INT32_C(  1625482174), -INT32_C(  2136140593) },
      {  INT32_C(   331330513),  INT32_C(  1827282723), -INT32_C(  1319730230), -INT32_C(  1847056580) },
      { -INT32_C(  2119778479), -INT32_C(  2136140593),  INT32_C(  1827282723), -INT32_C(  1847056580) } },
    { { -INT32_C(   812477570), -INT32_C(  1806682030),  INT32_C(   607350101),  INT32_C(  1403314562) },
      { -INT32_C(  1217960812),  INT32_C(  1294160259),  INT32_C(   285112788),  INT32_C(   513992608) },
      { -INT32_C(  1806682030),  INT32_C(  1403314562),  INT32_C(  1294160259),  INT32_C(   513992608) } },
    { { -INT32_C(   856869766), -INT32_C(  1033880211),  INT32_C(   770085803),  INT32_C(   142642036) },
      {  INT32_C(  1925179375),  INT32_C(   230679097), -INT32_C(    81871269),  INT32_C(   521781413) },
      { -INT32_C(  1033880211),  INT32_C(   142642036),  INT32_C(   230679097),  INT32_C(   521781413) } },
    { {  INT32_C(  1642792692), -INT32_C(   282899644),  INT32_C(  1394346718), -INT32_C(  2074370923) },
      { -INT32_C(  1107944572),  INT32_C(  1506457085),  INT32_C(   408217715), -INT32_C(  1657311576) },
      { -INT32_C(   282899644), -INT32_C(  2074370923),  INT32_C(  1506457085), -INT32_C(  1657311576) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vuzp2q_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vuzp2q_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 1572565854752738975),  INT64_C( 1665189159162091459) },
      {  INT64_C( 6552428771358605317),  INT64_C( 3695040570659838411) },
      {  INT64_C( 1665189159162091459),  INT64_C( 3695040570659838411) } },
    { { -INT64_C( 5262955398493842340), -INT64_C( 7196877999693453743) },
      { -INT64_C( 5608706773722595186), -INT64_C( 4035965878303981577) },
      { -INT64_C( 7196877999693453743), -INT64_C( 4035965878303981577) } },
    { { -INT64_C( 7720355845962003918),  INT64_C( 7612134344586186096) },
      {  INT64_C( 7590360267460416444), -INT64_C(  175304159150248608) },
      {  INT64_C( 7612134344586186096), -INT64_C(  175304159150248608) } },
    { { -INT64_C( 7056017815032929221),  INT64_C( 2850576714195906379) },
      { -INT64_C( 8667423604670282021),  INT64_C( 6221128166867593869) },
      {  INT64_C( 2850576714195906379),  INT64_C( 6221128166867593869) } },
    { { -INT64_C( 4606082402684143801), -INT64_C( 2582404268411144041) },
      { -INT64_C( 6707583791840758725),  INT64_C( 7295075065064471499) },
      { -INT64_C( 2582404268411144041),  INT64_C( 7295075065064471499) } },
    { { -INT64_C( 7927198485548690745), -INT64_C( 7817196344013692249) },
      {  INT64_C( 6370587472936938929),  INT64_C( 8835355148860482074) },
      { -INT64_C( 7817196344013692249),  INT64_C( 8835355148860482074) } },
    { {  INT64_C( 1016040448205420686),  INT64_C( 2053704565793336725) },
      {  INT64_C( 7983837966002976230),  INT64_C( 1574364892958690221) },
      {  INT64_C( 2053704565793336725),  INT64_C( 1574364892958690221) } },
    { { -INT64_C( 2868311088181702468),  INT64_C(  498568190981695332) },
      { -INT64_C( 4215856231531032901),  INT64_C( 2732838800146637904) },
      {  INT64_C(  498568190981695332),  INT64_C( 2732838800146637904) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vuzp2q_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_vuzp2q_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(222), UINT8_C(236), UINT8_C(203), UINT8_C(186), UINT8_C(216), UINT8_C(218), UINT8_C( 88), UINT8_C(216),
        UINT8_C(199), UINT8_C(141), UINT8_C( 87), UINT8_C(129), UINT8_C( 11), UINT8_C(113), UINT8_C(215), UINT8_C( 37) },
      { UINT8_C(103), UINT8_C( 87), UINT8_C(221), UINT8_C( 35), UINT8_C(248), UINT8_C( 47), UINT8_C(244), UINT8_C(217),
        UINT8_C( 30), UINT8_C( 82), UINT8_C(106), UINT8_C(233), UINT8_C( 90), UINT8_C(182), UINT8_C(233), UINT8_C( 56) },
      { UINT8_C(236), UINT8_C(186), UINT8_C(218), UINT8_C(216), UINT8_C(141), UINT8_C(129), UINT8_C(113), UINT8_C( 37),
        UINT8_C( 87), UINT8_C( 35), UINT8_C( 47), UINT8_C(217), UINT8_C( 82), UINT8_C(233), UINT8_C(182), UINT8_C( 56) } },
    { { UINT8_C(162), UINT8_C(180), UINT8_C(242), UINT8_C(122), UINT8_C(143), UINT8_C( 74), UINT8_C( 83), UINT8_C( 86),
        UINT8_C(215), UINT8_C(170), UINT8_C(215), UINT8_C(226), UINT8_C( 27), UINT8_C(175), UINT8_C(  7), UINT8_C(131) },
      { UINT8_C(  6), UINT8_C(229), UINT8_C(166), UINT8_C(254), UINT8_C( 20), UINT8_C(155), UINT8_C(216), UINT8_C( 50),
        UINT8_C(237), UINT8_C( 66), UINT8_C( 28), UINT8_C( 71), UINT8_C(248), UINT8_C(  5), UINT8_C(127), UINT8_C(154) },
      { UINT8_C(180), UINT8_C(122), UINT8_C( 74), UINT8_C( 86), UINT8_C(170), UINT8_C(226), UINT8_C(175), UINT8_C(131),
        UINT8_C(229), UINT8_C(254), UINT8_C(155), UINT8_C( 50), UINT8_C( 66), UINT8_C( 71), UINT8_C(  5), UINT8_C(154) } },
    { { UINT8_C(185), UINT8_C(113), UINT8_C( 21), UINT8_C( 72), UINT8_C(187), UINT8_C(104), UINT8_C(159), UINT8_C(146),
        UINT8_C( 18), UINT8_C(118), UINT8_C(116), UINT8_C( 45), UINT8_C( 37), UINT8_C(124), UINT8_C(176), UINT8_C( 44) },
      { UINT8_C( 97), UINT8_C( 87), UINT8_C( 42), UINT8_C(117), UINT8_C(242), UINT8_C(  2), UINT8_C(168), UINT8_C(223),
        UINT8_C( 69), UINT8_C(196), UINT8_C( 39), UINT8_C( 61), UINT8_C(201), UINT8_C(166), UINT8_C(216), UINT8_C(130) },
      { UINT8_C(113), UINT8_C( 72), UINT8_C(104), UINT8_C(146), UINT8_C(118), UINT8_C( 45), UINT8_C(124), UINT8_C( 44),
        UINT8_C( 87), UINT8_C(117), UINT8_C(  2), UINT8_C(223), UINT8_C(196), UINT8_C( 61), UINT8_C(166), UINT8_C(130) } },
    { { UINT8_C( 24), UINT8_C(237), UINT8_C(203), UINT8_C(211), UINT8_C( 85), UINT8_C(106), UINT8_C(102), UINT8_C(103),
        UINT8_C(224), UINT8_C(218), UINT8_C(148), UINT8_C(  6), UINT8_C( 86), UINT8_C( 69), UINT8_C( 50), UINT8_C(183) },
      { UINT8_C(156), UINT8_C( 92), UINT8_C( 45), UINT8_C(142), UINT8_C( 95), UINT8_C(213), UINT8_C(109), UINT8_C(164),
        UINT8_C(153), UINT8_C(148), UINT8_C(225), UINT8_C( 98), UINT8_C( 59), UINT8_C(185), UINT8_C(228), UINT8_C( 83) },
      { UINT8_C(237), UINT8_C(211), UINT8_C(106), UINT8_C(103), UINT8_C(218), UINT8_C(  6), UINT8_C( 69), UINT8_C(183),
        UINT8_C( 92), UINT8_C(142), UINT8_C(213), UINT8_C(164), UINT8_C(148), UINT8_C( 98), UINT8_C(185), UINT8_C( 83) } },
    { { UINT8_C(166), UINT8_C(175), UINT8_C( 38), UINT8_C(251), UINT8_C( 25), UINT8_C(140), UINT8_C( 98), UINT8_C(250),
        UINT8_C(103), UINT8_C(247), UINT8_C(  0), UINT8_C(189), UINT8_C( 60), UINT8_C( 50), UINT8_C(117), UINT8_C(216) },
      { UINT8_C(142), UINT8_C(162), UINT8_C(102), UINT8_C(237), UINT8_C(119), UINT8_C(211), UINT8_C(145), UINT8_C( 16),
        UINT8_C(104), UINT8_C(115), UINT8_C(114), UINT8_C(163), UINT8_C( 44), UINT8_C( 86), UINT8_C(246), UINT8_C(211) },
      { UINT8_C(175), UINT8_C(251), UINT8_C(140), UINT8_C(250), UINT8_C(247), UINT8_C(189), UINT8_C( 50), UINT8_C(216),
        UINT8_C(162), UINT8_C(237), UINT8_C(211), UINT8_C( 16), UINT8_C(115), UINT8_C(163), UINT8_C( 86), UINT8_C(211) } },
    { { UINT8_C(  6), UINT8_C( 28), UINT8_C(206), UINT8_C( 31), UINT8_C(169), UINT8_C( 49), UINT8_C( 25), UINT8_C( 16),
        UINT8_C( 40), UINT8_C( 25), UINT8_C(205), UINT8_C(100), UINT8_C( 75), UINT8_C( 66), UINT8_C( 60), UINT8_C(218) },
      { UINT8_C(228), UINT8_C(162), UINT8_C(199), UINT8_C( 91), UINT8_C(117), UINT8_C( 89), UINT8_C(107), UINT8_C(221),
        UINT8_C(204), UINT8_C(221), UINT8_C(128), UINT8_C(248), UINT8_C( 52), UINT8_C(118), UINT8_C(203), UINT8_C( 58) },
      { UINT8_C( 28), UINT8_C( 31), UINT8_C( 49), UINT8_C( 16), UINT8_C( 25), UINT8_C(100), UINT8_C( 66), UINT8_C(218),
        UINT8_C(162), UINT8_C( 91), UINT8_C( 89), UINT8_C(221), UINT8_C(221), UINT8_C(248), UINT8_C(118), UINT8_C( 58) } },
    { { UINT8_C(147), UINT8_C(154), UINT8_C( 89), UINT8_C( 60), UINT8_C(203), UINT8_C(115), UINT8_C( 76), UINT8_C(243),
        UINT8_C(140), UINT8_C( 25), UINT8_C( 87), UINT8_C(216), UINT8_C( 92), UINT8_C(147), UINT8_C(178), UINT8_C( 64) },
      { UINT8_C( 53), UINT8_C(121), UINT8_C(156), UINT8_C(170), UINT8_C(210), UINT8_C(  7), UINT8_C(136), UINT8_C(158),
        UINT8_C(229), UINT8_C(  8), UINT8_C(151), UINT8_C( 25), UINT8_C(127), UINT8_C( 98), UINT8_C( 83), UINT8_C( 18) },
      { UINT8_C(154), UINT8_C( 60), UINT8_C(115), UINT8_C(243), UINT8_C( 25), UINT8_C(216), UINT8_C(147), UINT8_C( 64),
        UINT8_C(121), UINT8_C(170), UINT8_C(  7), UINT8_C(158), UINT8_C(  8), UINT8_C( 25), UINT8_C( 98), UINT8_C( 18) } },
    { { UINT8_C(252), UINT8_C(172), UINT8_C( 78), UINT8_C(199), UINT8_C( 31), UINT8_C(154), UINT8_C(186), UINT8_C(172),
        UINT8_C(179), UINT8_C( 17), UINT8_C(132), UINT8_C( 15), UINT8_C(164), UINT8_C( 54), UINT8_C( 80), UINT8_C(217) },
      { UINT8_C(175), UINT8_C(236), UINT8_C(132), UINT8_C(130), UINT8_C(243), UINT8_C( 12), UINT8_C( 32), UINT8_C(216),
        UINT8_C( 20), UINT8_C(183), UINT8_C(241), UINT8_C(147), UINT8_C( 26), UINT8_C( 68), UINT8_C(165), UINT8_C( 22) },
      { UINT8_C(172), UINT8_C(199), UINT8_C(154), UINT8_C(172), UINT8_C( 17), UINT8_C( 15), UINT8_C( 54), UINT8_C(217),
        UINT8_C(236), UINT8_C(130), UINT8_C( 12), UINT8_C(216), UINT8_C(183), UINT8_C(147), UINT8_C( 68), UINT8_C( 22) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vuzp2q_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vuzp2q_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(37226), UINT16_C(57568), UINT16_C(51742), UINT16_C(48634), UINT16_C(62066), UINT16_C( 8229), UINT16_C(12583), UINT16_C(19540) },
      { UINT16_C(48673), UINT16_C(18245), UINT16_C(29777), UINT16_C(48054), UINT16_C(41040), UINT16_C(22301), UINT16_C(43109), UINT16_C(53223) },
      { UINT16_C(57568), UINT16_C(48634), UINT16_C( 8229), UINT16_C(19540), UINT16_C(18245), UINT16_C(48054), UINT16_C(22301), UINT16_C(53223) } },
    { { UINT16_C(51001), UINT16_C(22448), UINT16_C(43665), UINT16_C( 1044), UINT16_C(14748), UINT16_C(49956), UINT16_C(31082), UINT16_C(35599) },
      { UINT16_C(21559), UINT16_C(35283), UINT16_C(35273), UINT16_C( 6468), UINT16_C(25129), UINT16_C(36465), UINT16_C(22538), UINT16_C(17246) },
      { UINT16_C(22448), UINT16_C( 1044), UINT16_C(49956), UINT16_C(35599), UINT16_C(35283), UINT16_C( 6468), UINT16_C(36465), UINT16_C(17246) } },
    { { UINT16_C( 3615), UINT16_C(45466), UINT16_C(44728), UINT16_C(21941), UINT16_C(55783), UINT16_C(21016), UINT16_C(10322), UINT16_C(35549) },
      { UINT16_C(45180), UINT16_C(17683), UINT16_C(22329), UINT16_C(25183), UINT16_C(53433), UINT16_C(50161), UINT16_C(20264), UINT16_C(18182) },
      { UINT16_C(45466), UINT16_C(21941), UINT16_C(21016), UINT16_C(35549), UINT16_C(17683), UINT16_C(25183), UINT16_C(50161), UINT16_C(18182) } },
    { { UINT16_C(41053), UINT16_C( 5624), UINT16_C(44366), UINT16_C(13930), UINT16_C(33671), UINT16_C(55688), UINT16_C(26027), UINT16_C(10083) },
      { UINT16_C(30230), UINT16_C(20333), UINT16_C(52430), UINT16_C(34738), UINT16_C(41884), UINT16_C(50251), UINT16_C(20978), UINT16_C(20235) },
      { UINT16_C( 5624), UINT16_C(13930), UINT16_C(55688), UINT16_C(10083), UINT16_C(20333), UINT16_C(34738), UINT16_C(50251), UINT16_C(20235) } },
    { { UINT16_C( 1266), UINT16_C(16484), UINT16_C(53169), UINT16_C(14454), UINT16_C(65106), UINT16_C(64786), UINT16_C(30052), UINT16_C(31268) },
      { UINT16_C(37356), UINT16_C(47817), UINT16_C(31581), UINT16_C(63809), UINT16_C(35870), UINT16_C( 4285), UINT16_C(51678), UINT16_C(53343) },
      { UINT16_C(16484), UINT16_C(14454), UINT16_C(64786), UINT16_C(31268), UINT16_C(47817), UINT16_C(63809), UINT16_C( 4285), UINT16_C(53343) } },
    { { UINT16_C(50381), UINT16_C(32272), UINT16_C(34707), UINT16_C(58807), UINT16_C(51589), UINT16_C(59874), UINT16_C( 1598), UINT16_C(10851) },
      { UINT16_C(11672), UINT16_C(62948), UINT16_C( 9896), UINT16_C(51183), UINT16_C(44210), UINT16_C(37079), UINT16_C(14197), UINT16_C(16992) },
      { UINT16_C(32272), UINT16_C(58807), UINT16_C(59874), UINT16_C(10851), UINT16_C(62948), UINT16_C(51183), UINT16_C(37079), UINT16_C(16992) } },
    { { UINT16_C(29179), UINT16_C(36545), UINT16_C(30968), UINT16_C(32115), UINT16_C(21825), UINT16_C(32615), UINT16_C(51803), UINT16_C(62378) },
      { UINT16_C(36599), UINT16_C(41193), UINT16_C(55476), UINT16_C(26471), UINT16_C(16004), UINT16_C(64247), UINT16_C(22645), UINT16_C(28732) },
      { UINT16_C(36545), UINT16_C(32115), UINT16_C(32615), UINT16_C(62378), UINT16_C(41193), UINT16_C(26471), UINT16_C(64247), UINT16_C(28732) } },
    { { UINT16_C(64969), UINT16_C(49662), UINT16_C(29045), UINT16_C(46654), UINT16_C(42438), UINT16_C( 8758), UINT16_C(57456), UINT16_C(26389) },
      { UINT16_C(65134), UINT16_C( 8967), UINT16_C(28374), UINT16_C(23434), UINT16_C(33197), UINT16_C( 8789), UINT16_C(37337), UINT16_C(41619) },
      { UINT16_C(49662), UINT16_C(46654), UINT16_C( 8758), UINT16_C(26389), UINT16_C( 8967), UINT16_C(23434), UINT16_C( 8789), UINT16_C(41619) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vuzp2q_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vuzp2q_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2900651911), UINT32_C(2436311970), UINT32_C(3817606193), UINT32_C(2719667300) },
      { UINT32_C(2172837903), UINT32_C(3994048712), UINT32_C( 856971193), UINT32_C(2581448722) },
      { UINT32_C(2436311970), UINT32_C(2719667300), UINT32_C(3994048712), UINT32_C(2581448722) } },
    { { UINT32_C(3662070072), UINT32_C( 510361069), UINT32_C(3976329353), UINT32_C(3700366284) },
      { UINT32_C(3294433787), UINT32_C( 598895978), UINT32_C(3596011204), UINT32_C(3329241998) },
      { UINT32_C( 510361069), UINT32_C(3700366284), UINT32_C( 598895978), UINT32_C(3329241998) } },
    { { UINT32_C(3802183413), UINT32_C(3170896947), UINT32_C(3500802308), UINT32_C( 413940253) },
      { UINT32_C(3051096651), UINT32_C(1020890743), UINT32_C(3809619796), UINT32_C(1487503971) },
      { UINT32_C(3170896947), UINT32_C( 413940253), UINT32_C(1020890743), UINT32_C(1487503971) } },
    { { UINT32_C(1815759416), UINT32_C(1512651350), UINT32_C(1479201595), UINT32_C(1500632845) },
      { UINT32_C(1477332449), UINT32_C( 815065052), UINT32_C(2048108311), UINT32_C(1657978153) },
      { UINT32_C(1512651350), UINT32_C(1500632845), UINT32_C( 815065052), UINT32_C(1657978153) } },
    { { UINT32_C(1573784583), UINT32_C(2176317254), UINT32_C(3638223306), UINT32_C(2570144696) },
      { UINT32_C(1962033048), UINT32_C(1051035175), UINT32_C(1471723565), UINT32_C(2092534389) },
      { UINT32_C(2176317254), UINT32_C(2570144696), UINT32_C(1051035175), UINT32_C(2092534389) } },
    { { UINT32_C(3705243542), UINT32_C(1214091390), UINT32_C( 706754418), UINT32_C( 465850754) },
      { UINT32_C(3096426129), UINT32_C(1794520124), UINT32_C(1656860397), UINT32_C(3470752312) },
      { UINT32_C(1214091390), UINT32_C( 465850754), UINT32_C(1794520124), UINT32_C(3470752312) } },
    { { UINT32_C(2141894657), UINT32_C(3150382921), UINT32_C(3253069887), UINT32_C(3403458873) },
      { UINT32_C(2625793119), UINT32_C(2366011552), UINT32_C(1592837926), UINT32_C(1110232897) },
      { UINT32_C(3150382921), UINT32_C(3403458873), UINT32_C(2366011552), UINT32_C(1110232897) } },
    { { UINT32_C(3502364295), UINT32_C( 495683806), UINT32_C(2866704752), UINT32_C(2054470426) },
      { UINT32_C(3340171047), UINT32_C(2522160239), UINT32_C( 619988451), UINT32_C(2607161620) },
      { UINT32_C( 495683806), UINT32_C(2054470426), UINT32_C(2522160239), UINT32_C(2607161620) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vuzp2q_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vuzp2q_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(10128971028910510737), UINT64_C(17729527479315999417) },
      { UINT64_C( 3335331942345100554), UINT64_C(11269845798600382417) },
      { UINT64_C(17729527479315999417), UINT64_C(11269845798600382417) } },
    { { UINT64_C(16475121993802503579), UINT64_C(14326970468804119694) },
      { UINT64_C(11373276584639549932), UINT64_C(18139705864536774166) },
      { UINT64_C(14326970468804119694), UINT64_C(18139705864536774166) } },
    { { UINT64_C( 9372473455084277507), UINT64_C( 3532002181234206082) },
      { UINT64_C(14910203097960200578), UINT64_C(16492371921639289732) },
      { UINT64_C( 3532002181234206082), UINT64_C(16492371921639289732) } },
    { { UINT64_C( 3220394418092766011), UINT64_C(14069084986605703112) },
      { UINT64_C( 5381235056558806823), UINT64_C( 9544269215124331695) },
      { UINT64_C(14069084986605703112), UINT64_C( 9544269215124331695) } },
    { { UINT64_C( 8203135926171567617), UINT64_C(15454311783178649971) },
      { UINT64_C( 3883619683466119637), UINT64_C( 2579500605500691200) },
      { UINT64_C(15454311783178649971), UINT64_C( 2579500605500691200) } },
    { { UINT64_C( 6330836097350664128), UINT64_C(17108193226076674790) },
      { UINT64_C( 9640075422859797005), UINT64_C( 9927792619412164225) },
      { UINT64_C(17108193226076674790), UINT64_C( 9927792619412164225) } },
    { { UINT64_C( 2401771254059341082), UINT64_C(17306527302493298728) },
      { UINT64_C(11839765661985519172), UINT64_C(15144777308092964314) },
      { UINT64_C(17306527302493298728), UINT64_C(15144777308092964314) } },
    { { UINT64_C( 1656802321261076643), UINT64_C( 2042527392187463044) },
      { UINT64_C(  144455106247973689), UINT64_C(18076835750634408275) },
      { UINT64_C( 2042527392187463044), UINT64_C(18076835750634408275) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vuzp2q_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_vuzp2q_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[8];
    simde_poly8_t b[8];
    simde_poly8_t r[8];
  } test_vec[] = {
    { { SIMDE_POLY8_C( 32), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(134), SIMDE_POLY8_C(188), SIMDE_POLY8_C(  5), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 50) },
      { SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(113), SIMDE_POLY8_C(241),    SIMDE_POLY8_C(UINT8_MAX), SIMDE_POLY8_C( 18), SIMDE_POLY8_C(122), SIMDE_POLY8_C( 84) },
      { SIMDE_POLY8_C(115), SIMDE_POLY8_C(134), SIMDE_POLY8_C(  5), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(241), SIMDE_POLY8_C( 18), SIMDE_POLY8_C( 84) } },
    { { SIMDE_POLY8_C( 24), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(106), SIMDE_POLY8_C(201), SIMDE_POLY8_C( 70), SIMDE_POLY8_C(150), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(152) },
      { SIMDE_POLY8_C(111), SIMDE_POLY8_C(245), SIMDE_POLY8_C(121), SIMDE_POLY8_C(191), SIMDE_POLY8_C(114), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 11), SIMDE_POLY8_C(146) },
      { SIMDE_POLY8_C( 59), SIMDE_POLY8_C(201), SIMDE_POLY8_C(150), SIMDE_POLY8_C(152), SIMDE_POLY8_C(245), SIMDE_POLY8_C(191), SIMDE_POLY8_C(111), SIMDE_POLY8_C(146) } },
    { { SIMDE_POLY8_C(226), SIMDE_POLY8_C(105), SIMDE_POLY8_C( 24), SIMDE_POLY8_C(158), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(208), SIMDE_POLY8_C(194) },
      { SIMDE_POLY8_C( 79), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(180), SIMDE_POLY8_C( 78), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 46), SIMDE_POLY8_C(162), SIMDE_POLY8_C(108) },
      { SIMDE_POLY8_C(105), SIMDE_POLY8_C(158), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(194), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 78), SIMDE_POLY8_C( 46), SIMDE_POLY8_C(108) } },
    { { SIMDE_POLY8_C(105), SIMDE_POLY8_C( 12), SIMDE_POLY8_C( 53), SIMDE_POLY8_C(176), SIMDE_POLY8_C(162), SIMDE_POLY8_C(139), SIMDE_POLY8_C( 72), SIMDE_POLY8_C( 17) },
      { SIMDE_POLY8_C(128), SIMDE_POLY8_C(193), SIMDE_POLY8_C(209), SIMDE_POLY8_C(242), SIMDE_POLY8_C( 48), SIMDE_POLY8_C(220), SIMDE_POLY8_C(132), SIMDE_POLY8_C( 18) },
      { SIMDE_POLY8_C( 12), SIMDE_POLY8_C(176), SIMDE_POLY8_C(139), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(193), SIMDE_POLY8_C(242), SIMDE_POLY8_C(220), SIMDE_POLY8_C( 18) } },
    { { SIMDE_POLY8_C( 69), SIMDE_POLY8_C(156), SIMDE_POLY8_C(176), SIMDE_POLY8_C(180), SIMDE_POLY8_C(209), SIMDE_POLY8_C(129), SIMDE_POLY8_C(118), SIMDE_POLY8_C( 32) },
      { SIMDE_POLY8_C(195), SIMDE_POLY8_C( 42), SIMDE_POLY8_C(111), SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 89), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(131), SIMDE_POLY8_C(194) },
      { SIMDE_POLY8_C(156), SIMDE_POLY8_C(180), SIMDE_POLY8_C(129), SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 42), SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(194) } },
    { { SIMDE_POLY8_C( 30), SIMDE_POLY8_C(184), SIMDE_POLY8_C(114), SIMDE_POLY8_C(192), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(186), SIMDE_POLY8_C(210), SIMDE_POLY8_C(195) },
      { SIMDE_POLY8_C(124), SIMDE_POLY8_C(163), SIMDE_POLY8_C(182), SIMDE_POLY8_C(172), SIMDE_POLY8_C(127), SIMDE_POLY8_C( 58), SIMDE_POLY8_C(191), SIMDE_POLY8_C(196) },
      { SIMDE_POLY8_C(184), SIMDE_POLY8_C(192), SIMDE_POLY8_C(186), SIMDE_POLY8_C(195), SIMDE_POLY8_C(163), SIMDE_POLY8_C(172), SIMDE_POLY8_C( 58), SIMDE_POLY8_C(196) } },
    { { SIMDE_POLY8_C(215), SIMDE_POLY8_C(111), SIMDE_POLY8_C(120), SIMDE_POLY8_C(168), SIMDE_POLY8_C(240), SIMDE_POLY8_C(239), SIMDE_POLY8_C(200), SIMDE_POLY8_C(179) },
      { SIMDE_POLY8_C( 25), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(202), SIMDE_POLY8_C(114), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 53), SIMDE_POLY8_C(103) },
      { SIMDE_POLY8_C(111), SIMDE_POLY8_C(168), SIMDE_POLY8_C(239), SIMDE_POLY8_C(179), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(114), SIMDE_POLY8_C( 77), SIMDE_POLY8_C(103) } },
    { { SIMDE_POLY8_C(  5), SIMDE_POLY8_C(167), SIMDE_POLY8_C( 39), SIMDE_POLY8_C( 72), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(249), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(222) },
      { SIMDE_POLY8_C(156), SIMDE_POLY8_C(194), SIMDE_POLY8_C(138), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(252), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(224), SIMDE_POLY8_C(211) },
      { SIMDE_POLY8_C(167), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(249), SIMDE_POLY8_C(222), SIMDE_POLY8_C(194), SIMDE_POLY8_C( 27), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(211) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t a = simde_vld1_p8(test_vec[i].a);
    simde_poly8x8_t b = simde_vld1_p8(test_vec[i].b);
    simde_poly8x8_t r = simde_vuzp2_p8(a, b);

    simde_test_arm_neon_assert_equal_p8x8(r, simde_vld1_p8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8_t a = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t b = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t r = simde_vuzp2_p8(a, b);

    simde_test_arm_neon_write_p8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[4];
    simde_poly16_t b[4];
    simde_poly16_t r[4];
  } test_vec[] = {
    { { SIMDE_POLY16_C( 5562), SIMDE_POLY16_C(29929), SIMDE_POLY16_C(59535), SIMDE_POLY16_C( 4681) },
      { SIMDE_POLY16_C( 4562), SIMDE_POLY16_C(56009), SIMDE_POLY16_C(26174), SIMDE_POLY16_C(13284) },
      { SIMDE_POLY16_C(29929), SIMDE_POLY16_C( 4681), SIMDE_POLY16_C(56009), SIMDE_POLY16_C(13284) } },
    { { SIMDE_POLY16_C( 5231), SIMDE_POLY16_C( 5283), SIMDE_POLY16_C(50924), SIMDE_POLY16_C(52138) },
      { SIMDE_POLY16_C(51348), SIMDE_POLY16_C(34623), SIMDE_POLY16_C(61476), SIMDE_POLY16_C(57252) },
      { SIMDE_POLY16_C( 5283), SIMDE_POLY16_C(52138), SIMDE_POLY16_C(34623), SIMDE_POLY16_C(57252) } },
    { { SIMDE_POLY16_C(36102), SIMDE_POLY16_C(38227), SIMDE_POLY16_C(40053), SIMDE_POLY16_C(18343) },
      { SIMDE_POLY16_C(28845), SIMDE_POLY16_C(60193), SIMDE_POLY16_C( 1494), SIMDE_POLY16_C(17950) },
      { SIMDE_POLY16_C(38227), SIMDE_POLY16_C(18343), SIMDE_POLY16_C(60193), SIMDE_POLY16_C(17950) } },
    { { SIMDE_POLY16_C(49434), SIMDE_POLY16_C( 1626), SIMDE_POLY16_C( 1159), SIMDE_POLY16_C( 7122) },
      { SIMDE_POLY16_C( 4556), SIMDE_POLY16_C(61603), SIMDE_POLY16_C(18177), SIMDE_POLY16_C( 1999) },
      { SIMDE_POLY16_C( 1626), SIMDE_POLY16_C( 7122), SIMDE_POLY16_C(61603), SIMDE_POLY16_C( 1999) } },
    { { SIMDE_POLY16_C( 8916), SIMDE_POLY16_C(18844), SIMDE_POLY16_C(17342), SIMDE_POLY16_C(27536) },
      { SIMDE_POLY16_C(45748), SIMDE_POLY16_C(35414), SIMDE_POLY16_C(29879), SIMDE_POLY16_C(53712) },
      { SIMDE_POLY16_C(18844), SIMDE_POLY16_C(27536), SIMDE_POLY16_C(35414), SIMDE_POLY16_C(53712) } },
    { { SIMDE_POLY16_C(10805), SIMDE_POLY16_C(48344), SIMDE_POLY16_C(43566), SIMDE_POLY16_C(64216) },
      { SIMDE_POLY16_C(31675), SIMDE_POLY16_C(48363), SIMDE_POLY16_C(47810), SIMDE_POLY16_C(38596) },
      { SIMDE_POLY16_C(48344), SIMDE_POLY16_C(64216), SIMDE_POLY16_C(48363), SIMDE_POLY16_C(38596) } },
    { { SIMDE_POLY16_C(24797), SIMDE_POLY16_C(39903), SIMDE_POLY16_C(28580), SIMDE_POLY16_C(22535) },
      { SIMDE_POLY16_C(23841), SIMDE_POLY16_C(55778), SIMDE_POLY16_C(46034), SIMDE_POLY16_C( 1962) },
      { SIMDE_POLY16_C(39903), SIMDE_POLY16_C(22535), SIMDE_POLY16_C(55778), SIMDE_POLY16_C( 1962) } },
    { { SIMDE_POLY16_C(33501), SIMDE_POLY16_C( 3268), SIMDE_POLY16_C(39980), SIMDE_POLY16_C(59142) },
      { SIMDE_POLY16_C(61719), SIMDE_POLY16_C(55716), SIMDE_POLY16_C(26796), SIMDE_POLY16_C(35183) },
      { SIMDE_POLY16_C( 3268), SIMDE_POLY16_C(59142), SIMDE_POLY16_C(55716), SIMDE_POLY16_C(35183) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t a = simde_vld1_p16(test_vec[i].a);
    simde_poly16x4_t b = simde_vld1_p16(test_vec[i].b);
    simde_poly16x4_t r = simde_vuzp2_p16(a, b);
    simde_test_arm_neon_assert_equal_p16x4(r, simde_vld1_p16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x4_t a = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t b = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t r = simde_vuzp2_p16(a, b);

    simde_test_arm_neon_write_p16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[16];
    simde_poly8_t b[16];
    simde_poly8_t r[16];
  } test_vec[] = {
    { { SIMDE_POLY8_C(222), SIMDE_POLY8_C(236), SIMDE_POLY8_C(203), SIMDE_POLY8_C(186), SIMDE_POLY8_C(216), SIMDE_POLY8_C(218), SIMDE_POLY8_C( 88), SIMDE_POLY8_C(216),
        SIMDE_POLY8_C(199), SIMDE_POLY8_C(141), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(129), SIMDE_POLY8_C( 11), SIMDE_POLY8_C(113), SIMDE_POLY8_C(215), SIMDE_POLY8_C( 37) },
      { SIMDE_POLY8_C(103), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(221), SIMDE_POLY8_C( 35), SIMDE_POLY8_C(248), SIMDE_POLY8_C( 47), SIMDE_POLY8_C(244), SIMDE_POLY8_C(217),
        SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(106), SIMDE_POLY8_C(233), SIMDE_POLY8_C( 90), SIMDE_POLY8_C(182), SIMDE_POLY8_C(233), SIMDE_POLY8_C( 56) },
      { SIMDE_POLY8_C(236), SIMDE_POLY8_C(186), SIMDE_POLY8_C(218), SIMDE_POLY8_C(216), SIMDE_POLY8_C(141), SIMDE_POLY8_C(129), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 37),
        SIMDE_POLY8_C( 87), SIMDE_POLY8_C( 35), SIMDE_POLY8_C( 47), SIMDE_POLY8_C(217), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(233), SIMDE_POLY8_C(182), SIMDE_POLY8_C( 56) } },
    { { SIMDE_POLY8_C(162), SIMDE_POLY8_C(180), SIMDE_POLY8_C(242), SIMDE_POLY8_C(122), SIMDE_POLY8_C(143), SIMDE_POLY8_C( 74), SIMDE_POLY8_C( 83), SIMDE_POLY8_C( 86),
        SIMDE_POLY8_C(215), SIMDE_POLY8_C(170), SIMDE_POLY8_C(215), SIMDE_POLY8_C(226), SIMDE_POLY8_C( 27), SIMDE_POLY8_C(175), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(131) },
      { SIMDE_POLY8_C(  6), SIMDE_POLY8_C(229), SIMDE_POLY8_C(166), SIMDE_POLY8_C(254), SIMDE_POLY8_C( 20), SIMDE_POLY8_C(155), SIMDE_POLY8_C(216), SIMDE_POLY8_C( 50),
        SIMDE_POLY8_C(237), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 71), SIMDE_POLY8_C(248), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(127), SIMDE_POLY8_C(154) },
      { SIMDE_POLY8_C(180), SIMDE_POLY8_C(122), SIMDE_POLY8_C( 74), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(170), SIMDE_POLY8_C(226), SIMDE_POLY8_C(175), SIMDE_POLY8_C(131),
        SIMDE_POLY8_C(229), SIMDE_POLY8_C(254), SIMDE_POLY8_C(155), SIMDE_POLY8_C( 50), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 71), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(154) } },
    { { SIMDE_POLY8_C(185), SIMDE_POLY8_C(113), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(187), SIMDE_POLY8_C(104), SIMDE_POLY8_C(159), SIMDE_POLY8_C(146),
        SIMDE_POLY8_C( 18), SIMDE_POLY8_C(118), SIMDE_POLY8_C(116), SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(124), SIMDE_POLY8_C(176), SIMDE_POLY8_C( 44) },
      { SIMDE_POLY8_C( 97), SIMDE_POLY8_C( 87), SIMDE_POLY8_C( 42), SIMDE_POLY8_C(117), SIMDE_POLY8_C(242), SIMDE_POLY8_C(  2), SIMDE_POLY8_C(168), SIMDE_POLY8_C(223),
        SIMDE_POLY8_C( 69), SIMDE_POLY8_C(196), SIMDE_POLY8_C( 39), SIMDE_POLY8_C( 61), SIMDE_POLY8_C(201), SIMDE_POLY8_C(166), SIMDE_POLY8_C(216), SIMDE_POLY8_C(130) },
      { SIMDE_POLY8_C(113), SIMDE_POLY8_C( 72), SIMDE_POLY8_C(104), SIMDE_POLY8_C(146), SIMDE_POLY8_C(118), SIMDE_POLY8_C( 45), SIMDE_POLY8_C(124), SIMDE_POLY8_C( 44),
        SIMDE_POLY8_C( 87), SIMDE_POLY8_C(117), SIMDE_POLY8_C(  2), SIMDE_POLY8_C(223), SIMDE_POLY8_C(196), SIMDE_POLY8_C( 61), SIMDE_POLY8_C(166), SIMDE_POLY8_C(130) } },
    { { SIMDE_POLY8_C( 24), SIMDE_POLY8_C(237), SIMDE_POLY8_C(203), SIMDE_POLY8_C(211), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(106), SIMDE_POLY8_C(102), SIMDE_POLY8_C(103),
        SIMDE_POLY8_C(224), SIMDE_POLY8_C(218), SIMDE_POLY8_C(148), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 86), SIMDE_POLY8_C( 69), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(183) },
      { SIMDE_POLY8_C(156), SIMDE_POLY8_C( 92), SIMDE_POLY8_C( 45), SIMDE_POLY8_C(142), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(213), SIMDE_POLY8_C(109), SIMDE_POLY8_C(164),
        SIMDE_POLY8_C(153), SIMDE_POLY8_C(148), SIMDE_POLY8_C(225), SIMDE_POLY8_C( 98), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(185), SIMDE_POLY8_C(228), SIMDE_POLY8_C( 83) },
      { SIMDE_POLY8_C(237), SIMDE_POLY8_C(211), SIMDE_POLY8_C(106), SIMDE_POLY8_C(103), SIMDE_POLY8_C(218), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(183),
        SIMDE_POLY8_C( 92), SIMDE_POLY8_C(142), SIMDE_POLY8_C(213), SIMDE_POLY8_C(164), SIMDE_POLY8_C(148), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(185), SIMDE_POLY8_C( 83) } },
    { { SIMDE_POLY8_C(166), SIMDE_POLY8_C(175), SIMDE_POLY8_C( 38), SIMDE_POLY8_C(251), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(140), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(250),
        SIMDE_POLY8_C(103), SIMDE_POLY8_C(247), SIMDE_POLY8_C(  0), SIMDE_POLY8_C(189), SIMDE_POLY8_C( 60), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(117), SIMDE_POLY8_C(216) },
      { SIMDE_POLY8_C(142), SIMDE_POLY8_C(162), SIMDE_POLY8_C(102), SIMDE_POLY8_C(237), SIMDE_POLY8_C(119), SIMDE_POLY8_C(211), SIMDE_POLY8_C(145), SIMDE_POLY8_C( 16),
        SIMDE_POLY8_C(104), SIMDE_POLY8_C(115), SIMDE_POLY8_C(114), SIMDE_POLY8_C(163), SIMDE_POLY8_C( 44), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(246), SIMDE_POLY8_C(211) },
      { SIMDE_POLY8_C(175), SIMDE_POLY8_C(251), SIMDE_POLY8_C(140), SIMDE_POLY8_C(250), SIMDE_POLY8_C(247), SIMDE_POLY8_C(189), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(216),
        SIMDE_POLY8_C(162), SIMDE_POLY8_C(237), SIMDE_POLY8_C(211), SIMDE_POLY8_C( 16), SIMDE_POLY8_C(115), SIMDE_POLY8_C(163), SIMDE_POLY8_C( 86), SIMDE_POLY8_C(211) } },
    { { SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 28), SIMDE_POLY8_C(206), SIMDE_POLY8_C( 31), SIMDE_POLY8_C(169), SIMDE_POLY8_C( 49), SIMDE_POLY8_C( 25), SIMDE_POLY8_C( 16),
        SIMDE_POLY8_C( 40), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(205), SIMDE_POLY8_C(100), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(218) },
      { SIMDE_POLY8_C(228), SIMDE_POLY8_C(162), SIMDE_POLY8_C(199), SIMDE_POLY8_C( 91), SIMDE_POLY8_C(117), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(107), SIMDE_POLY8_C(221),
        SIMDE_POLY8_C(204), SIMDE_POLY8_C(221), SIMDE_POLY8_C(128), SIMDE_POLY8_C(248), SIMDE_POLY8_C( 52), SIMDE_POLY8_C(118), SIMDE_POLY8_C(203), SIMDE_POLY8_C( 58) },
      { SIMDE_POLY8_C( 28), SIMDE_POLY8_C( 31), SIMDE_POLY8_C( 49), SIMDE_POLY8_C( 16), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(100), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(218),
        SIMDE_POLY8_C(162), SIMDE_POLY8_C( 91), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(221), SIMDE_POLY8_C(221), SIMDE_POLY8_C(248), SIMDE_POLY8_C(118), SIMDE_POLY8_C( 58) } },
    { { SIMDE_POLY8_C(147), SIMDE_POLY8_C(154), SIMDE_POLY8_C( 89), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(203), SIMDE_POLY8_C(115), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(243),
        SIMDE_POLY8_C(140), SIMDE_POLY8_C( 25), SIMDE_POLY8_C( 87), SIMDE_POLY8_C(216), SIMDE_POLY8_C( 92), SIMDE_POLY8_C(147), SIMDE_POLY8_C(178), SIMDE_POLY8_C( 64) },
      { SIMDE_POLY8_C( 53), SIMDE_POLY8_C(121), SIMDE_POLY8_C(156), SIMDE_POLY8_C(170), SIMDE_POLY8_C(210), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(136), SIMDE_POLY8_C(158),
        SIMDE_POLY8_C(229), SIMDE_POLY8_C(  8), SIMDE_POLY8_C(151), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(127), SIMDE_POLY8_C( 98), SIMDE_POLY8_C( 83), SIMDE_POLY8_C( 18) },
      { SIMDE_POLY8_C(154), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(115), SIMDE_POLY8_C(243), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(216), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 64),
        SIMDE_POLY8_C(121), SIMDE_POLY8_C(170), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(158), SIMDE_POLY8_C(  8), SIMDE_POLY8_C( 25), SIMDE_POLY8_C( 98), SIMDE_POLY8_C( 18) } },
    { { SIMDE_POLY8_C(252), SIMDE_POLY8_C(172), SIMDE_POLY8_C( 78), SIMDE_POLY8_C(199), SIMDE_POLY8_C( 31), SIMDE_POLY8_C(154), SIMDE_POLY8_C(186), SIMDE_POLY8_C(172),
        SIMDE_POLY8_C(179), SIMDE_POLY8_C( 17), SIMDE_POLY8_C(132), SIMDE_POLY8_C( 15), SIMDE_POLY8_C(164), SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(217) },
      { SIMDE_POLY8_C(175), SIMDE_POLY8_C(236), SIMDE_POLY8_C(132), SIMDE_POLY8_C(130), SIMDE_POLY8_C(243), SIMDE_POLY8_C( 12), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(216),
        SIMDE_POLY8_C( 20), SIMDE_POLY8_C(183), SIMDE_POLY8_C(241), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 26), SIMDE_POLY8_C( 68), SIMDE_POLY8_C(165), SIMDE_POLY8_C( 22) },
      { SIMDE_POLY8_C(172), SIMDE_POLY8_C(199), SIMDE_POLY8_C(154), SIMDE_POLY8_C(172), SIMDE_POLY8_C( 17), SIMDE_POLY8_C( 15), SIMDE_POLY8_C( 54), SIMDE_POLY8_C(217),
        SIMDE_POLY8_C(236), SIMDE_POLY8_C(130), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(216), SIMDE_POLY8_C(183), SIMDE_POLY8_C(147), SIMDE_POLY8_C( 68), SIMDE_POLY8_C( 22) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    simde_poly8x16_t b = simde_vld1q_p8(test_vec[i].b);
    simde_poly8x16_t r = simde_vuzp2q_p8(a, b);

    simde_test_arm_neon_assert_equal_p8x16(r, simde_vld1q_p8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x16_t a = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t b = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t r = simde_vuzp2q_p8(a, b);

    simde_test_arm_neon_write_p8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[8];
    simde_poly16_t b[8];
    simde_poly16_t r[8];
  } test_vec[] = {
    { { SIMDE_POLY16_C(37226), SIMDE_POLY16_C(57568), SIMDE_POLY16_C(51742), SIMDE_POLY16_C(48634), SIMDE_POLY16_C(62066), SIMDE_POLY16_C( 8229), SIMDE_POLY16_C(12583), SIMDE_POLY16_C(19540) },
      { SIMDE_POLY16_C(48673), SIMDE_POLY16_C(18245), SIMDE_POLY16_C(29777), SIMDE_POLY16_C(48054), SIMDE_POLY16_C(41040), SIMDE_POLY16_C(22301), SIMDE_POLY16_C(43109), SIMDE_POLY16_C(53223) },
      { SIMDE_POLY16_C(57568), SIMDE_POLY16_C(48634), SIMDE_POLY16_C( 8229), SIMDE_POLY16_C(19540), SIMDE_POLY16_C(18245), SIMDE_POLY16_C(48054), SIMDE_POLY16_C(22301), SIMDE_POLY16_C(53223) } },
    { { SIMDE_POLY16_C(51001), SIMDE_POLY16_C(22448), SIMDE_POLY16_C(43665), SIMDE_POLY16_C( 1044), SIMDE_POLY16_C(14748), SIMDE_POLY16_C(49956), SIMDE_POLY16_C(31082), SIMDE_POLY16_C(35599) },
      { SIMDE_POLY16_C(21559), SIMDE_POLY16_C(35283), SIMDE_POLY16_C(35273), SIMDE_POLY16_C( 6468), SIMDE_POLY16_C(25129), SIMDE_POLY16_C(36465), SIMDE_POLY16_C(22538), SIMDE_POLY16_C(17246) },
      { SIMDE_POLY16_C(22448), SIMDE_POLY16_C( 1044), SIMDE_POLY16_C(49956), SIMDE_POLY16_C(35599), SIMDE_POLY16_C(35283), SIMDE_POLY16_C( 6468), SIMDE_POLY16_C(36465), SIMDE_POLY16_C(17246) } },
    { { SIMDE_POLY16_C( 3615), SIMDE_POLY16_C(45466), SIMDE_POLY16_C(44728), SIMDE_POLY16_C(21941), SIMDE_POLY16_C(55783), SIMDE_POLY16_C(21016), SIMDE_POLY16_C(10322), SIMDE_POLY16_C(35549) },
      { SIMDE_POLY16_C(45180), SIMDE_POLY16_C(17683), SIMDE_POLY16_C(22329), SIMDE_POLY16_C(25183), SIMDE_POLY16_C(53433), SIMDE_POLY16_C(50161), SIMDE_POLY16_C(20264), SIMDE_POLY16_C(18182) },
      { SIMDE_POLY16_C(45466), SIMDE_POLY16_C(21941), SIMDE_POLY16_C(21016), SIMDE_POLY16_C(35549), SIMDE_POLY16_C(17683), SIMDE_POLY16_C(25183), SIMDE_POLY16_C(50161), SIMDE_POLY16_C(18182) } },
    { { SIMDE_POLY16_C(41053), SIMDE_POLY16_C( 5624), SIMDE_POLY16_C(44366), SIMDE_POLY16_C(13930), SIMDE_POLY16_C(33671), SIMDE_POLY16_C(55688), SIMDE_POLY16_C(26027), SIMDE_POLY16_C(10083) },
      { SIMDE_POLY16_C(30230), SIMDE_POLY16_C(20333), SIMDE_POLY16_C(52430), SIMDE_POLY16_C(34738), SIMDE_POLY16_C(41884), SIMDE_POLY16_C(50251), SIMDE_POLY16_C(20978), SIMDE_POLY16_C(20235) },
      { SIMDE_POLY16_C( 5624), SIMDE_POLY16_C(13930), SIMDE_POLY16_C(55688), SIMDE_POLY16_C(10083), SIMDE_POLY16_C(20333), SIMDE_POLY16_C(34738), SIMDE_POLY16_C(50251), SIMDE_POLY16_C(20235) } },
    { { SIMDE_POLY16_C( 1266), SIMDE_POLY16_C(16484), SIMDE_POLY16_C(53169), SIMDE_POLY16_C(14454), SIMDE_POLY16_C(65106), SIMDE_POLY16_C(64786), SIMDE_POLY16_C(30052), SIMDE_POLY16_C(31268) },
      { SIMDE_POLY16_C(37356), SIMDE_POLY16_C(47817), SIMDE_POLY16_C(31581), SIMDE_POLY16_C(63809), SIMDE_POLY16_C(35870), SIMDE_POLY16_C( 4285), SIMDE_POLY16_C(51678), SIMDE_POLY16_C(53343) },
      { SIMDE_POLY16_C(16484), SIMDE_POLY16_C(14454), SIMDE_POLY16_C(64786), SIMDE_POLY16_C(31268), SIMDE_POLY16_C(47817), SIMDE_POLY16_C(63809), SIMDE_POLY16_C( 4285), SIMDE_POLY16_C(53343) } },
    { { SIMDE_POLY16_C(50381), SIMDE_POLY16_C(32272), SIMDE_POLY16_C(34707), SIMDE_POLY16_C(58807), SIMDE_POLY16_C(51589), SIMDE_POLY16_C(59874), SIMDE_POLY16_C( 1598), SIMDE_POLY16_C(10851) },
      { SIMDE_POLY16_C(11672), SIMDE_POLY16_C(62948), SIMDE_POLY16_C( 9896), SIMDE_POLY16_C(51183), SIMDE_POLY16_C(44210), SIMDE_POLY16_C(37079), SIMDE_POLY16_C(14197), SIMDE_POLY16_C(16992) },
      { SIMDE_POLY16_C(32272), SIMDE_POLY16_C(58807), SIMDE_POLY16_C(59874), SIMDE_POLY16_C(10851), SIMDE_POLY16_C(62948), SIMDE_POLY16_C(51183), SIMDE_POLY16_C(37079), SIMDE_POLY16_C(16992) } },
    { { SIMDE_POLY16_C(29179), SIMDE_POLY16_C(36545), SIMDE_POLY16_C(30968), SIMDE_POLY16_C(32115), SIMDE_POLY16_C(21825), SIMDE_POLY16_C(32615), SIMDE_POLY16_C(51803), SIMDE_POLY16_C(62378) },
      { SIMDE_POLY16_C(36599), SIMDE_POLY16_C(41193), SIMDE_POLY16_C(55476), SIMDE_POLY16_C(26471), SIMDE_POLY16_C(16004), SIMDE_POLY16_C(64247), SIMDE_POLY16_C(22645), SIMDE_POLY16_C(28732) },
      { SIMDE_POLY16_C(36545), SIMDE_POLY16_C(32115), SIMDE_POLY16_C(32615), SIMDE_POLY16_C(62378), SIMDE_POLY16_C(41193), SIMDE_POLY16_C(26471), SIMDE_POLY16_C(64247), SIMDE_POLY16_C(28732) } },
    { { SIMDE_POLY16_C(64969), SIMDE_POLY16_C(49662), SIMDE_POLY16_C(29045), SIMDE_POLY16_C(46654), SIMDE_POLY16_C(42438), SIMDE_POLY16_C( 8758), SIMDE_POLY16_C(57456), SIMDE_POLY16_C(26389) },
      { SIMDE_POLY16_C(65134), SIMDE_POLY16_C( 8967), SIMDE_POLY16_C(28374), SIMDE_POLY16_C(23434), SIMDE_POLY16_C(33197), SIMDE_POLY16_C( 8789), SIMDE_POLY16_C(37337), SIMDE_POLY16_C(41619) },
      { SIMDE_POLY16_C(49662), SIMDE_POLY16_C(46654), SIMDE_POLY16_C( 8758), SIMDE_POLY16_C(26389), SIMDE_POLY16_C( 8967), SIMDE_POLY16_C(23434), SIMDE_POLY16_C( 8789), SIMDE_POLY16_C(41619) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    simde_poly16x8_t b = simde_vld1q_p16(test_vec[i].b);
    simde_poly16x8_t r = simde_vuzp2q_p16(a, b);
    simde_test_arm_neon_assert_equal_p16x8(r, simde_vld1q_p16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8_t a = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t b = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t r = simde_vuzp2q_p16(a, b);

    simde_test_arm_neon_write_p16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuzp2q_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly64_t a[2];
    simde_poly64_t b[2];
    simde_poly64_t r[2];
  } test_vec[] = {
    { { SIMDE_POLY64_C(10128971028910510737), SIMDE_POLY64_C(17729527479315999417) },
      { SIMDE_POLY64_C( 3335331942345100554), SIMDE_POLY64_C(11269845798600382417) },
      { SIMDE_POLY64_C(17729527479315999417), SIMDE_POLY64_C(11269845798600382417) } },
    { { SIMDE_POLY64_C(16475121993802503579), SIMDE_POLY64_C(14326970468804119694) },
      { SIMDE_POLY64_C(11373276584639549932), SIMDE_POLY64_C(18139705864536774166) },
      { SIMDE_POLY64_C(14326970468804119694), SIMDE_POLY64_C(18139705864536774166) } },
    { { SIMDE_POLY64_C( 9372473455084277507), SIMDE_POLY64_C( 3532002181234206082) },
      { SIMDE_POLY64_C(14910203097960200578), SIMDE_POLY64_C(16492371921639289732) },
      { SIMDE_POLY64_C( 3532002181234206082), SIMDE_POLY64_C(16492371921639289732) } },
    { { SIMDE_POLY64_C( 3220394418092766011), SIMDE_POLY64_C(14069084986605703112) },
      { SIMDE_POLY64_C( 5381235056558806823), SIMDE_POLY64_C( 9544269215124331695) },
      { SIMDE_POLY64_C(14069084986605703112), SIMDE_POLY64_C( 9544269215124331695) } },
    { { SIMDE_POLY64_C( 8203135926171567617), SIMDE_POLY64_C(15454311783178649971) },
      { SIMDE_POLY64_C( 3883619683466119637), SIMDE_POLY64_C( 2579500605500691200) },
      { SIMDE_POLY64_C(15454311783178649971), SIMDE_POLY64_C( 2579500605500691200) } },
    { { SIMDE_POLY64_C( 6330836097350664128), SIMDE_POLY64_C(17108193226076674790) },
      { SIMDE_POLY64_C( 9640075422859797005), SIMDE_POLY64_C( 9927792619412164225) },
      { SIMDE_POLY64_C(17108193226076674790), SIMDE_POLY64_C( 9927792619412164225) } },
    { { SIMDE_POLY64_C( 2401771254059341082), SIMDE_POLY64_C(17306527302493298728) },
      { SIMDE_POLY64_C(11839765661985519172), SIMDE_POLY64_C(15144777308092964314) },
      { SIMDE_POLY64_C(17306527302493298728), SIMDE_POLY64_C(15144777308092964314) } },
    { { SIMDE_POLY64_C( 1656802321261076643), SIMDE_POLY64_C( 2042527392187463044) },
      { SIMDE_POLY64_C(  144455106247973689), SIMDE_POLY64_C(18076835750634408275) },
      { SIMDE_POLY64_C( 2042527392187463044), SIMDE_POLY64_C(18076835750634408275) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2_t a = simde_vld1q_p64(test_vec[i].a);
    simde_poly64x2_t b = simde_vld1q_p64(test_vec[i].b);
    simde_poly64x2_t r = simde_vuzp2q_p64(a, b);
    simde_test_arm_neon_assert_equal_p64x2(r, simde_vld1q_p64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x2_t a = simde_test_arm_neon_random_p64x2();
    simde_poly64x2_t b = simde_test_arm_neon_random_p64x2();
    simde_poly64x2_t r = simde_vuzp2q_p64(a, b);

    simde_test_arm_neon_write_p64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuzp2q_p64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
