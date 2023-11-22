#define SIMDE_TEST_ARM_NEON_INSN trn2

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/trn2.h>

static int
test_simde_vtrn2_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    simde_float16_t b[4];
    simde_float16_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE( 56.300), SIMDE_FLOAT16_VALUE( -  9.279), SIMDE_FLOAT16_VALUE( - 19.078),  SIMDE_FLOAT16_VALUE( 91.073) },
      {  SIMDE_FLOAT16_VALUE( 85.295),  SIMDE_FLOAT16_VALUE(  3.112), SIMDE_FLOAT16_VALUE( - 91.891),  SIMDE_FLOAT16_VALUE(  4.800) },
      { SIMDE_FLOAT16_VALUE( -  9.279),  SIMDE_FLOAT16_VALUE(  3.112),  SIMDE_FLOAT16_VALUE( 91.073),  SIMDE_FLOAT16_VALUE(  4.800) } },
    { {  SIMDE_FLOAT16_VALUE( 74.709), SIMDE_FLOAT16_VALUE( - 26.125), SIMDE_FLOAT16_VALUE( - 27.765), SIMDE_FLOAT16_VALUE( - 99.458) },
      {  SIMDE_FLOAT16_VALUE( 89.694), SIMDE_FLOAT16_VALUE( - 71.014),  SIMDE_FLOAT16_VALUE( 48.493),  SIMDE_FLOAT16_VALUE( 30.421) },
      { SIMDE_FLOAT16_VALUE( - 26.125), SIMDE_FLOAT16_VALUE( - 71.014), SIMDE_FLOAT16_VALUE( - 99.458),  SIMDE_FLOAT16_VALUE( 30.421) } },
    { {  SIMDE_FLOAT16_VALUE( 73.102),  SIMDE_FLOAT16_VALUE( 41.016), SIMDE_FLOAT16_VALUE( - 35.965), SIMDE_FLOAT16_VALUE( - 89.249) },
      {  SIMDE_FLOAT16_VALUE( 85.101),  SIMDE_FLOAT16_VALUE( 59.074),  SIMDE_FLOAT16_VALUE( 55.450), SIMDE_FLOAT16_VALUE( - 85.858) },
      {  SIMDE_FLOAT16_VALUE( 41.016),  SIMDE_FLOAT16_VALUE( 59.074), SIMDE_FLOAT16_VALUE( - 89.249), SIMDE_FLOAT16_VALUE( - 85.858) } },
    { {  SIMDE_FLOAT16_VALUE( 74.180),  SIMDE_FLOAT16_VALUE( 76.843), SIMDE_FLOAT16_VALUE( - 60.751), SIMDE_FLOAT16_VALUE( - 41.114) },
      {  SIMDE_FLOAT16_VALUE( 10.403),  SIMDE_FLOAT16_VALUE( 54.517), SIMDE_FLOAT16_VALUE( - 73.384),  SIMDE_FLOAT16_VALUE( 65.706) },
      {  SIMDE_FLOAT16_VALUE( 76.843),  SIMDE_FLOAT16_VALUE( 54.517), SIMDE_FLOAT16_VALUE( - 41.114),  SIMDE_FLOAT16_VALUE( 65.706) } },
    { { SIMDE_FLOAT16_VALUE( - 73.108), SIMDE_FLOAT16_VALUE( - 71.731), SIMDE_FLOAT16_VALUE( - 42.349), SIMDE_FLOAT16_VALUE( - 33.103) },
      { SIMDE_FLOAT16_VALUE( - 37.091), SIMDE_FLOAT16_VALUE( -  4.379), SIMDE_FLOAT16_VALUE( - 56.871), SIMDE_FLOAT16_VALUE( - 36.204) },
      { SIMDE_FLOAT16_VALUE( - 71.731), SIMDE_FLOAT16_VALUE( -  4.379), SIMDE_FLOAT16_VALUE( - 33.103), SIMDE_FLOAT16_VALUE( - 36.204) } },
    { { SIMDE_FLOAT16_VALUE( - 12.826),  SIMDE_FLOAT16_VALUE( 44.335), SIMDE_FLOAT16_VALUE( -  3.623), SIMDE_FLOAT16_VALUE( - 89.419) },
      { SIMDE_FLOAT16_VALUE( - 91.221), SIMDE_FLOAT16_VALUE( -  5.349), SIMDE_FLOAT16_VALUE( -  8.450),  SIMDE_FLOAT16_VALUE( 34.071) },
      {  SIMDE_FLOAT16_VALUE( 44.335), SIMDE_FLOAT16_VALUE( -  5.349), SIMDE_FLOAT16_VALUE( - 89.419),  SIMDE_FLOAT16_VALUE( 34.071) } },
    { {  SIMDE_FLOAT16_VALUE( 14.291), SIMDE_FLOAT16_VALUE( -  9.864),  SIMDE_FLOAT16_VALUE( 72.841), SIMDE_FLOAT16_VALUE( - 90.631) },
      {  SIMDE_FLOAT16_VALUE( 40.737), SIMDE_FLOAT16_VALUE( - 40.555), SIMDE_FLOAT16_VALUE( - 53.928),  SIMDE_FLOAT16_VALUE( 45.466) },
      { SIMDE_FLOAT16_VALUE( -  9.864), SIMDE_FLOAT16_VALUE( - 40.555), SIMDE_FLOAT16_VALUE( - 90.631),  SIMDE_FLOAT16_VALUE( 45.466) } },
    { {  SIMDE_FLOAT16_VALUE( 77.115),  SIMDE_FLOAT16_VALUE( 37.620),  SIMDE_FLOAT16_VALUE( 28.892), SIMDE_FLOAT16_VALUE( - 64.989) },
      { SIMDE_FLOAT16_VALUE( - 18.627), SIMDE_FLOAT16_VALUE( - 85.234),  SIMDE_FLOAT16_VALUE( 78.130), SIMDE_FLOAT16_VALUE( - 13.349) },
      {  SIMDE_FLOAT16_VALUE( 37.620), SIMDE_FLOAT16_VALUE( - 85.234), SIMDE_FLOAT16_VALUE( - 64.989), SIMDE_FLOAT16_VALUE( - 13.349) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float16x4_t r = simde_vtrn2_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vtrn2_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    83.42), SIMDE_FLOAT32_C(   803.99) },
      { SIMDE_FLOAT32_C(   636.36), SIMDE_FLOAT32_C(   295.59) },
      { SIMDE_FLOAT32_C(   803.99), SIMDE_FLOAT32_C(   295.59) } },
    { { SIMDE_FLOAT32_C(   877.14), SIMDE_FLOAT32_C(  -285.61) },
      { SIMDE_FLOAT32_C(   689.26), SIMDE_FLOAT32_C(   398.34) },
      { SIMDE_FLOAT32_C(  -285.61), SIMDE_FLOAT32_C(   398.34) } },
    { { SIMDE_FLOAT32_C(  -478.64), SIMDE_FLOAT32_C(   -23.77) },
      { SIMDE_FLOAT32_C(   747.86), SIMDE_FLOAT32_C(   759.56) },
      { SIMDE_FLOAT32_C(   -23.77), SIMDE_FLOAT32_C(   759.56) } },
    { { SIMDE_FLOAT32_C(  -573.98), SIMDE_FLOAT32_C(   874.62) },
      { SIMDE_FLOAT32_C(   584.77), SIMDE_FLOAT32_C(   826.51) },
      { SIMDE_FLOAT32_C(   874.62), SIMDE_FLOAT32_C(   826.51) } },
    { { SIMDE_FLOAT32_C(   -73.10), SIMDE_FLOAT32_C(  -203.77) },
      { SIMDE_FLOAT32_C(   333.96), SIMDE_FLOAT32_C(   -54.11) },
      { SIMDE_FLOAT32_C(  -203.77), SIMDE_FLOAT32_C(   -54.11) } },
    { { SIMDE_FLOAT32_C(   552.91), SIMDE_FLOAT32_C(   -34.42) },
      { SIMDE_FLOAT32_C(  -526.96), SIMDE_FLOAT32_C(  -200.73) },
      { SIMDE_FLOAT32_C(   -34.42), SIMDE_FLOAT32_C(  -200.73) } },
    { { SIMDE_FLOAT32_C(   276.54), SIMDE_FLOAT32_C(  -171.29) },
      { SIMDE_FLOAT32_C(  -906.91), SIMDE_FLOAT32_C(  -286.58) },
      { SIMDE_FLOAT32_C(  -171.29), SIMDE_FLOAT32_C(  -286.58) } },
    { { SIMDE_FLOAT32_C(   665.38), SIMDE_FLOAT32_C(   440.56) },
      { SIMDE_FLOAT32_C(   826.61), SIMDE_FLOAT32_C(  -251.20) },
      { SIMDE_FLOAT32_C(   440.56), SIMDE_FLOAT32_C(  -251.20) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t r = simde_vtrn2_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vtrn2_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C( 106),  INT8_C(  93),  INT8_C( 108),  INT8_C(  69),  INT8_C(  23),  INT8_C(  43),  INT8_C(  82), -INT8_C(  47) },
      {  INT8_C(  44),  INT8_C(  36), -INT8_C( 125),  INT8_C(  77),  INT8_C(  46), -INT8_C( 121),  INT8_C(   2),  INT8_C(   4) },
      {  INT8_C(  93),  INT8_C(  36),  INT8_C(  69),  INT8_C(  77),  INT8_C(  43), -INT8_C( 121), -INT8_C(  47),  INT8_C(   4) } },
    { {  INT8_C(  71),  INT8_C(  37), -INT8_C(  29),  INT8_C(  29), -INT8_C(  88),  INT8_C(   1),  INT8_C( 106), -INT8_C(  41) },
      {  INT8_C( 123), -INT8_C(  54), -INT8_C(  57),  INT8_C( 117), -INT8_C(  92),      INT8_MIN, -INT8_C(  68),  INT8_C(  58) },
      {  INT8_C(  37), -INT8_C(  54),  INT8_C(  29),  INT8_C( 117),  INT8_C(   1),      INT8_MIN, -INT8_C(  41),  INT8_C(  58) } },
    { { -INT8_C(  35),  INT8_C(  40),      INT8_MIN, -INT8_C(  11),  INT8_C(  83), -INT8_C(  46), -INT8_C(  58),      INT8_MAX },
      { -INT8_C(   9),  INT8_C(  73), -INT8_C(  52),  INT8_C(  37), -INT8_C(  48), -INT8_C(  49),  INT8_C(  41),  INT8_C(  24) },
      {  INT8_C(  40),  INT8_C(  73), -INT8_C(  11),  INT8_C(  37), -INT8_C(  46), -INT8_C(  49),      INT8_MAX,  INT8_C(  24) } },
    { { -INT8_C(  12),  INT8_C(  13),  INT8_C(  53), -INT8_C( 100),  INT8_C(  14), -INT8_C(  96),  INT8_C( 115), -INT8_C( 118) },
      {  INT8_C( 106),  INT8_C(  59), -INT8_C(   1),  INT8_C(  14), -INT8_C(  69), -INT8_C(  69),  INT8_C(  72), -INT8_C( 104) },
      {  INT8_C(  13),  INT8_C(  59), -INT8_C( 100),  INT8_C(  14), -INT8_C(  96), -INT8_C(  69), -INT8_C( 118), -INT8_C( 104) } },
    { { -INT8_C(  29), -INT8_C(  56), -INT8_C( 115),  INT8_C(  55), -INT8_C( 101),  INT8_C(  84), -INT8_C(  74), -INT8_C( 110) },
      { -INT8_C(  99), -INT8_C( 125), -INT8_C(  73),  INT8_C( 110),  INT8_C(  82), -INT8_C(  31), -INT8_C( 122),  INT8_C(  70) },
      { -INT8_C(  56), -INT8_C( 125),  INT8_C(  55),  INT8_C( 110),  INT8_C(  84), -INT8_C(  31), -INT8_C( 110),  INT8_C(  70) } },
    { { -INT8_C(  18), -INT8_C(  69), -INT8_C(  30), -INT8_C(   4),  INT8_C(  91),  INT8_C(  85), -INT8_C( 122), -INT8_C(  59) },
      { -INT8_C( 112), -INT8_C( 122), -INT8_C(  45),  INT8_C(  75),  INT8_C(  65),  INT8_C(  28), -INT8_C(  28),  INT8_C(  37) },
      { -INT8_C(  69), -INT8_C( 122), -INT8_C(   4),  INT8_C(  75),  INT8_C(  85),  INT8_C(  28), -INT8_C(  59),  INT8_C(  37) } },
    { { -INT8_C(  28),  INT8_C( 113),  INT8_C(  92),      INT8_MAX, -INT8_C(  59),  INT8_C(  18),  INT8_C(  17),  INT8_C(  99) },
      { -INT8_C( 107), -INT8_C(  55), -INT8_C(  47), -INT8_C(  25), -INT8_C(  86),  INT8_C(  87),  INT8_C(  45), -INT8_C( 104) },
      {  INT8_C( 113), -INT8_C(  55),      INT8_MAX, -INT8_C(  25),  INT8_C(  18),  INT8_C(  87),  INT8_C(  99), -INT8_C( 104) } },
    { {  INT8_C(  18),  INT8_C(  15), -INT8_C( 108),  INT8_C( 110),  INT8_C( 101),  INT8_C(  27),  INT8_C(  51), -INT8_C(  11) },
      { -INT8_C(  95),  INT8_C(   7),  INT8_C(  65), -INT8_C(  30),  INT8_C(  35),  INT8_C(  37),  INT8_C(   7),  INT8_C(   7) },
      {  INT8_C(  15),  INT8_C(   7),  INT8_C( 110), -INT8_C(  30),  INT8_C(  27),  INT8_C(  37), -INT8_C(  11),  INT8_C(   7) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vtrn2_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vtrn2_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 21140), -INT16_C(  8901), -INT16_C(  7583), -INT16_C( 12924) },
      {  INT16_C(  7835),  INT16_C(  4605),  INT16_C( 31307),  INT16_C( 32045) },
      { -INT16_C(  8901),  INT16_C(  4605), -INT16_C( 12924),  INT16_C( 32045) } },
    { { -INT16_C( 20882),  INT16_C( 23307), -INT16_C(  2013),  INT16_C( 19039) },
      { -INT16_C( 26641), -INT16_C( 29962),  INT16_C( 15491), -INT16_C(  4182) },
      {  INT16_C( 23307), -INT16_C( 29962),  INT16_C( 19039), -INT16_C(  4182) } },
    { { -INT16_C(  6679),  INT16_C( 19149),  INT16_C( 20935),  INT16_C( 25111) },
      {  INT16_C(  5231), -INT16_C( 17804), -INT16_C( 24178), -INT16_C(   968) },
      {  INT16_C( 19149), -INT16_C( 17804),  INT16_C( 25111), -INT16_C(   968) } },
    { {  INT16_C( 17232),  INT16_C( 29527), -INT16_C( 18884),  INT16_C( 11197) },
      { -INT16_C( 19635), -INT16_C( 12107),  INT16_C( 24559), -INT16_C( 10048) },
      {  INT16_C( 29527), -INT16_C( 12107),  INT16_C( 11197), -INT16_C( 10048) } },
    { { -INT16_C( 29372),  INT16_C(  3106),  INT16_C( 14814),  INT16_C( 19822) },
      { -INT16_C(  7603), -INT16_C(  9465),  INT16_C( 16260), -INT16_C( 11049) },
      {  INT16_C(  3106), -INT16_C(  9465),  INT16_C( 19822), -INT16_C( 11049) } },
    { {  INT16_C( 11907), -INT16_C( 16569),  INT16_C(  1252),  INT16_C( 13034) },
      { -INT16_C( 24649), -INT16_C( 22782), -INT16_C( 15617),  INT16_C( 17279) },
      { -INT16_C( 16569), -INT16_C( 22782),  INT16_C( 13034),  INT16_C( 17279) } },
    { { -INT16_C( 23985),  INT16_C( 11599), -INT16_C( 16677),  INT16_C( 10618) },
      { -INT16_C( 32096),  INT16_C(  9220), -INT16_C(  9023),  INT16_C( 17656) },
      {  INT16_C( 11599),  INT16_C(  9220),  INT16_C( 10618),  INT16_C( 17656) } },
    { {  INT16_C( 16138), -INT16_C(  4349), -INT16_C(  4797), -INT16_C(  1247) },
      {  INT16_C(  9101), -INT16_C( 29534),  INT16_C(  8678),  INT16_C( 13775) },
      { -INT16_C(  4349), -INT16_C( 29534), -INT16_C(  1247),  INT16_C( 13775) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vtrn2_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vtrn2_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(    10645001),  INT32_C(  1062972149) },
      { -INT32_C(  1146901624),  INT32_C(   636172842) },
      {  INT32_C(  1062972149),  INT32_C(   636172842) } },
    { {  INT32_C(  1131938959), -INT32_C(  1546593877) },
      {  INT32_C(  1194148703), -INT32_C(   460102437) },
      { -INT32_C(  1546593877), -INT32_C(   460102437) } },
    { { -INT32_C(   924568109),  INT32_C(  1728528351) },
      {  INT32_C(   337816298),  INT32_C(  1933119204) },
      {  INT32_C(  1728528351),  INT32_C(  1933119204) } },
    { { -INT32_C(  1095323118), -INT32_C(   345930101) },
      { -INT32_C(  1540190263), -INT32_C(   964114957) },
      { -INT32_C(   345930101), -INT32_C(   964114957) } },
    { { -INT32_C(   644977414), -INT32_C(  1790863957) },
      {  INT32_C(   598303551), -INT32_C(  2070486159) },
      { -INT32_C(  1790863957), -INT32_C(  2070486159) } },
    { {  INT32_C(   541215893), -INT32_C(  1676958765) },
      {  INT32_C(   641809714), -INT32_C(    51590910) },
      { -INT32_C(  1676958765), -INT32_C(    51590910) } },
    { { -INT32_C(   506037450),  INT32_C(  1349981968) },
      { -INT32_C(   327999366), -INT32_C(  1737487869) },
      {  INT32_C(  1349981968), -INT32_C(  1737487869) } },
    { {  INT32_C(   700035670), -INT32_C(  2000239531) },
      {  INT32_C(    78513922),  INT32_C(   100768464) },
      { -INT32_C(  2000239531),  INT32_C(   100768464) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vtrn2_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vtrn2_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 15), UINT8_C(216), UINT8_C(  0), UINT8_C( 22), UINT8_C( 58), UINT8_C(248), UINT8_C( 89), UINT8_C(225) },
      { UINT8_C( 12), UINT8_C(184), UINT8_C(182), UINT8_C(163), UINT8_C(  1), UINT8_C(177), UINT8_C( 19), UINT8_C(121) },
      { UINT8_C(216), UINT8_C(184), UINT8_C( 22), UINT8_C(163), UINT8_C(248), UINT8_C(177), UINT8_C(225), UINT8_C(121) } },
    { { UINT8_C( 68), UINT8_C(225), UINT8_C(135), UINT8_C(204), UINT8_C(162), UINT8_C( 76), UINT8_C(186), UINT8_C(237) },
      { UINT8_C( 95), UINT8_C(179), UINT8_C( 10), UINT8_C( 85), UINT8_C(205), UINT8_C( 94), UINT8_C( 62), UINT8_C(220) },
      { UINT8_C(225), UINT8_C(179), UINT8_C(204), UINT8_C( 85), UINT8_C( 76), UINT8_C( 94), UINT8_C(237), UINT8_C(220) } },
    { { UINT8_C( 54), UINT8_C( 62), UINT8_C(243), UINT8_C(112), UINT8_C( 54), UINT8_C( 76), UINT8_C( 81), UINT8_C( 66) },
      { UINT8_C(  5), UINT8_C(  7), UINT8_C(229), UINT8_C(  6), UINT8_C(185), UINT8_C(248), UINT8_C(128), UINT8_C(253) },
      { UINT8_C( 62), UINT8_C(  7), UINT8_C(112), UINT8_C(  6), UINT8_C( 76), UINT8_C(248), UINT8_C( 66), UINT8_C(253) } },
    { { UINT8_C(218), UINT8_C(  7), UINT8_C(201), UINT8_C(124), UINT8_C( 83), UINT8_C(131), UINT8_C(105), UINT8_C(178) },
      { UINT8_C( 55), UINT8_C(116), UINT8_C(  7), UINT8_C(  4), UINT8_C(210), UINT8_C( 70), UINT8_C(224), UINT8_C(  8) },
      { UINT8_C(  7), UINT8_C(116), UINT8_C(124), UINT8_C(  4), UINT8_C(131), UINT8_C( 70), UINT8_C(178), UINT8_C(  8) } },
    { { UINT8_C(132), UINT8_C(211), UINT8_C(120), UINT8_C(187), UINT8_C( 32), UINT8_C(201), UINT8_C(253), UINT8_C( 37) },
      { UINT8_C(208), UINT8_C(227), UINT8_C( 43), UINT8_C(137), UINT8_C(219), UINT8_C(171), UINT8_C(134), UINT8_C(181) },
      { UINT8_C(211), UINT8_C(227), UINT8_C(187), UINT8_C(137), UINT8_C(201), UINT8_C(171), UINT8_C( 37), UINT8_C(181) } },
    { { UINT8_C(179), UINT8_C( 79), UINT8_C( 50), UINT8_C(  6), UINT8_C(211), UINT8_C(155), UINT8_C(185), UINT8_C( 10) },
      { UINT8_C( 15), UINT8_C(192), UINT8_C( 14), UINT8_C(225), UINT8_C(  6), UINT8_C(238), UINT8_C(233), UINT8_C(139) },
      { UINT8_C( 79), UINT8_C(192), UINT8_C(  6), UINT8_C(225), UINT8_C(155), UINT8_C(238), UINT8_C( 10), UINT8_C(139) } },
    { { UINT8_C(194), UINT8_C( 97), UINT8_C( 70), UINT8_C(226), UINT8_C( 42), UINT8_C( 67), UINT8_C(  7), UINT8_C(251) },
      { UINT8_C( 38), UINT8_C( 50), UINT8_C(132), UINT8_C(  2), UINT8_C(222), UINT8_C( 11), UINT8_C(183), UINT8_C(145) },
      { UINT8_C( 97), UINT8_C( 50), UINT8_C(226), UINT8_C(  2), UINT8_C( 67), UINT8_C( 11), UINT8_C(251), UINT8_C(145) } },
    { { UINT8_C( 90), UINT8_C(233), UINT8_C(151), UINT8_C( 45), UINT8_C(133), UINT8_C( 80), UINT8_C( 55), UINT8_C(148) },
      { UINT8_C( 17), UINT8_C( 69), UINT8_C(118), UINT8_C( 23), UINT8_C( 52), UINT8_C( 95), UINT8_C(162), UINT8_C(246) },
      { UINT8_C(233), UINT8_C( 69), UINT8_C( 45), UINT8_C( 23), UINT8_C( 80), UINT8_C( 95), UINT8_C(148), UINT8_C(246) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vtrn2_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vtrn2_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C( 5340), UINT16_C(40669), UINT16_C(17077), UINT16_C(60369) },
      { UINT16_C( 8272), UINT16_C(45663), UINT16_C(  988), UINT16_C(27971) },
      { UINT16_C(40669), UINT16_C(45663), UINT16_C(60369), UINT16_C(27971) } },
    { { UINT16_C(17106), UINT16_C( 4797), UINT16_C( 3841), UINT16_C(52059) },
      { UINT16_C(56359), UINT16_C(46318), UINT16_C(18079), UINT16_C(31782) },
      { UINT16_C( 4797), UINT16_C(46318), UINT16_C(52059), UINT16_C(31782) } },
    { { UINT16_C(  859), UINT16_C( 4122), UINT16_C(60229), UINT16_C(38651) },
      { UINT16_C(23051), UINT16_C(59464), UINT16_C(35678), UINT16_C(12373) },
      { UINT16_C( 4122), UINT16_C(59464), UINT16_C(38651), UINT16_C(12373) } },
    { { UINT16_C( 5069), UINT16_C(53058), UINT16_C(40482), UINT16_C(18842) },
      { UINT16_C(35194), UINT16_C( 6909), UINT16_C( 9167), UINT16_C(10902) },
      { UINT16_C(53058), UINT16_C( 6909), UINT16_C(18842), UINT16_C(10902) } },
    { { UINT16_C(45094), UINT16_C(27450), UINT16_C(13980), UINT16_C(42753) },
      { UINT16_C(18832), UINT16_C(61071), UINT16_C(58836), UINT16_C(41503) },
      { UINT16_C(27450), UINT16_C(61071), UINT16_C(42753), UINT16_C(41503) } },
    { { UINT16_C(25080), UINT16_C( 6769), UINT16_C( 3071), UINT16_C(31331) },
      { UINT16_C(24724), UINT16_C(25748), UINT16_C(10883), UINT16_C(43406) },
      { UINT16_C( 6769), UINT16_C(25748), UINT16_C(31331), UINT16_C(43406) } },
    { { UINT16_C(51674), UINT16_C(30228), UINT16_C( 5887), UINT16_C(36638) },
      { UINT16_C(44383), UINT16_C(13438), UINT16_C(40338), UINT16_C(35542) },
      { UINT16_C(30228), UINT16_C(13438), UINT16_C(36638), UINT16_C(35542) } },
    { { UINT16_C(18430), UINT16_C(65188), UINT16_C( 1874), UINT16_C(59256) },
      { UINT16_C( 3175), UINT16_C(59979), UINT16_C(55606), UINT16_C( 4243) },
      { UINT16_C(65188), UINT16_C(59979), UINT16_C(59256), UINT16_C( 4243) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vtrn2_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vtrn2_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(4196725491), UINT32_C(3634714177) },
      { UINT32_C(1414317671), UINT32_C(1496429915) },
      { UINT32_C(3634714177), UINT32_C(1496429915) } },
    { { UINT32_C(3347760164), UINT32_C(1815798194) },
      { UINT32_C(3174009957), UINT32_C(4006824187) },
      { UINT32_C(1815798194), UINT32_C(4006824187) } },
    { { UINT32_C(2078930746), UINT32_C(3025374797) },
      { UINT32_C(2936578132), UINT32_C(2030582357) },
      { UINT32_C(3025374797), UINT32_C(2030582357) } },
    { { UINT32_C(2957021950), UINT32_C(3642587763) },
      { UINT32_C(  43404295), UINT32_C(3488704916) },
      { UINT32_C(3642587763), UINT32_C(3488704916) } },
    { { UINT32_C(2907363936), UINT32_C(3160514152) },
      { UINT32_C(2473290302), UINT32_C(2718790820) },
      { UINT32_C(3160514152), UINT32_C(2718790820) } },
    { { UINT32_C(2052279558), UINT32_C(3478352072) },
      { UINT32_C(1355934140), UINT32_C(3005203027) },
      { UINT32_C(3478352072), UINT32_C(3005203027) } },
    { { UINT32_C(  73493148), UINT32_C(1187037704) },
      { UINT32_C(3503893548), UINT32_C(2792613536) },
      { UINT32_C(1187037704), UINT32_C(2792613536) } },
    { { UINT32_C(4230006324), UINT32_C(4073419574) },
      { UINT32_C(2957155421), UINT32_C(4217594463) },
      { UINT32_C(4073419574), UINT32_C(4217594463) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vtrn2_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vtrn2_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    simde_float16_t b[8];
    simde_float16_t r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE( 72.335),  SIMDE_FLOAT16_VALUE(  7.554), SIMDE_FLOAT16_VALUE( - 33.008),  SIMDE_FLOAT16_VALUE( 90.304),
        SIMDE_FLOAT16_VALUE( - 99.993), SIMDE_FLOAT16_VALUE( - 50.693), SIMDE_FLOAT16_VALUE( - 79.762),  SIMDE_FLOAT16_VALUE(  7.872) },
      { SIMDE_FLOAT16_VALUE( -  8.557),  SIMDE_FLOAT16_VALUE( 96.325), SIMDE_FLOAT16_VALUE( - 89.713),  SIMDE_FLOAT16_VALUE( 36.819),
         SIMDE_FLOAT16_VALUE(  5.553),  SIMDE_FLOAT16_VALUE( 14.489),  SIMDE_FLOAT16_VALUE(  5.427),  SIMDE_FLOAT16_VALUE( 32.305) },
      {  SIMDE_FLOAT16_VALUE(  7.554),  SIMDE_FLOAT16_VALUE( 96.325),  SIMDE_FLOAT16_VALUE( 90.304),  SIMDE_FLOAT16_VALUE( 36.819),
        SIMDE_FLOAT16_VALUE( - 50.693),  SIMDE_FLOAT16_VALUE( 14.489),  SIMDE_FLOAT16_VALUE(  7.872),  SIMDE_FLOAT16_VALUE( 32.305) } },
    { {  SIMDE_FLOAT16_VALUE( 74.913), SIMDE_FLOAT16_VALUE( - 11.970), SIMDE_FLOAT16_VALUE( - 42.824), SIMDE_FLOAT16_VALUE( - 82.513),
        SIMDE_FLOAT16_VALUE( - 55.926),  SIMDE_FLOAT16_VALUE( 86.502), SIMDE_FLOAT16_VALUE( - 85.855),  SIMDE_FLOAT16_VALUE( 25.208) },
      {  SIMDE_FLOAT16_VALUE(  6.209),  SIMDE_FLOAT16_VALUE( 90.752), SIMDE_FLOAT16_VALUE( - 82.451), SIMDE_FLOAT16_VALUE( - 91.435),
         SIMDE_FLOAT16_VALUE( 66.777), SIMDE_FLOAT16_VALUE( - 74.104), SIMDE_FLOAT16_VALUE( - 66.222), SIMDE_FLOAT16_VALUE( - 49.415) },
      { SIMDE_FLOAT16_VALUE( - 11.970),  SIMDE_FLOAT16_VALUE( 90.752), SIMDE_FLOAT16_VALUE( - 82.513), SIMDE_FLOAT16_VALUE( - 91.435),
         SIMDE_FLOAT16_VALUE( 86.502), SIMDE_FLOAT16_VALUE( - 74.104),  SIMDE_FLOAT16_VALUE( 25.208), SIMDE_FLOAT16_VALUE( - 49.415) } },
    { { SIMDE_FLOAT16_VALUE( - 63.196), SIMDE_FLOAT16_VALUE( - 52.466), SIMDE_FLOAT16_VALUE( - 73.706),  SIMDE_FLOAT16_VALUE( 40.555),
        SIMDE_FLOAT16_VALUE( - 76.544),  SIMDE_FLOAT16_VALUE( 87.237),  SIMDE_FLOAT16_VALUE( 84.511), SIMDE_FLOAT16_VALUE( - 75.225) },
      {  SIMDE_FLOAT16_VALUE( 44.539),  SIMDE_FLOAT16_VALUE( 21.319),  SIMDE_FLOAT16_VALUE( 66.231), SIMDE_FLOAT16_VALUE( - 19.440),
         SIMDE_FLOAT16_VALUE( 72.319), SIMDE_FLOAT16_VALUE( - 77.793),  SIMDE_FLOAT16_VALUE( 71.130),  SIMDE_FLOAT16_VALUE( 32.971) },
      { SIMDE_FLOAT16_VALUE( - 52.466),  SIMDE_FLOAT16_VALUE( 21.319),  SIMDE_FLOAT16_VALUE( 40.555), SIMDE_FLOAT16_VALUE( - 19.440),
         SIMDE_FLOAT16_VALUE( 87.237), SIMDE_FLOAT16_VALUE( - 77.793), SIMDE_FLOAT16_VALUE( - 75.225),  SIMDE_FLOAT16_VALUE( 32.971) } },
    { { SIMDE_FLOAT16_VALUE( - 44.126),  SIMDE_FLOAT16_VALUE( 81.561), SIMDE_FLOAT16_VALUE( - 38.052),  SIMDE_FLOAT16_VALUE( 19.498),
        SIMDE_FLOAT16_VALUE( - 93.987),  SIMDE_FLOAT16_VALUE( 83.750), SIMDE_FLOAT16_VALUE( - 87.122),  SIMDE_FLOAT16_VALUE( 72.370) },
      {  SIMDE_FLOAT16_VALUE( 57.508), SIMDE_FLOAT16_VALUE( - 39.509), SIMDE_FLOAT16_VALUE( - 62.778),  SIMDE_FLOAT16_VALUE( 95.740),
        SIMDE_FLOAT16_VALUE( - 53.685),  SIMDE_FLOAT16_VALUE( 86.996), SIMDE_FLOAT16_VALUE( - 59.984),  SIMDE_FLOAT16_VALUE( 75.447) },
      {  SIMDE_FLOAT16_VALUE( 81.561), SIMDE_FLOAT16_VALUE( - 39.509),  SIMDE_FLOAT16_VALUE( 19.498),  SIMDE_FLOAT16_VALUE( 95.740),
         SIMDE_FLOAT16_VALUE( 83.750),  SIMDE_FLOAT16_VALUE( 86.996),  SIMDE_FLOAT16_VALUE( 72.370),  SIMDE_FLOAT16_VALUE( 75.447) } },
    { {  SIMDE_FLOAT16_VALUE( 84.124),  SIMDE_FLOAT16_VALUE( 57.505), SIMDE_FLOAT16_VALUE( - 95.462),  SIMDE_FLOAT16_VALUE( 81.748),
         SIMDE_FLOAT16_VALUE( 24.643),  SIMDE_FLOAT16_VALUE( 70.285), SIMDE_FLOAT16_VALUE( - 69.576),  SIMDE_FLOAT16_VALUE( 73.340) },
      {  SIMDE_FLOAT16_VALUE( 17.355),  SIMDE_FLOAT16_VALUE(  5.498),  SIMDE_FLOAT16_VALUE( 29.349),  SIMDE_FLOAT16_VALUE( 93.614),
         SIMDE_FLOAT16_VALUE( 78.556), SIMDE_FLOAT16_VALUE( - 70.390),  SIMDE_FLOAT16_VALUE( 53.898),  SIMDE_FLOAT16_VALUE( 55.877) },
      {  SIMDE_FLOAT16_VALUE( 57.505),  SIMDE_FLOAT16_VALUE(  5.498),  SIMDE_FLOAT16_VALUE( 81.748),  SIMDE_FLOAT16_VALUE( 93.614),
         SIMDE_FLOAT16_VALUE( 70.285), SIMDE_FLOAT16_VALUE( - 70.390),  SIMDE_FLOAT16_VALUE( 73.340),  SIMDE_FLOAT16_VALUE( 55.877) } },
    { { SIMDE_FLOAT16_VALUE( -  9.431), SIMDE_FLOAT16_VALUE( - 67.084),  SIMDE_FLOAT16_VALUE(  3.039), SIMDE_FLOAT16_VALUE( - 23.339),
        SIMDE_FLOAT16_VALUE( - 70.932), SIMDE_FLOAT16_VALUE( - 71.857),  SIMDE_FLOAT16_VALUE( 23.002), SIMDE_FLOAT16_VALUE( - 46.362) },
      {  SIMDE_FLOAT16_VALUE( 43.482),  SIMDE_FLOAT16_VALUE( 21.428), SIMDE_FLOAT16_VALUE( -  1.230), SIMDE_FLOAT16_VALUE( - 40.972),
        SIMDE_FLOAT16_VALUE( - 47.974),  SIMDE_FLOAT16_VALUE( 73.628), SIMDE_FLOAT16_VALUE( - 29.720), SIMDE_FLOAT16_VALUE( - 90.383) },
      { SIMDE_FLOAT16_VALUE( - 67.084),  SIMDE_FLOAT16_VALUE( 21.428), SIMDE_FLOAT16_VALUE( - 23.339), SIMDE_FLOAT16_VALUE( - 40.972),
        SIMDE_FLOAT16_VALUE( - 71.857),  SIMDE_FLOAT16_VALUE( 73.628), SIMDE_FLOAT16_VALUE( - 46.362), SIMDE_FLOAT16_VALUE( - 90.383) } },
    { {  SIMDE_FLOAT16_VALUE( 95.642), SIMDE_FLOAT16_VALUE( - 87.854), SIMDE_FLOAT16_VALUE( - 44.833),  SIMDE_FLOAT16_VALUE( 50.993),
        SIMDE_FLOAT16_VALUE( -  1.937),  SIMDE_FLOAT16_VALUE( 79.506),  SIMDE_FLOAT16_VALUE( 71.543),  SIMDE_FLOAT16_VALUE( 92.534) },
      { SIMDE_FLOAT16_VALUE( - 89.081), SIMDE_FLOAT16_VALUE( - 58.662), SIMDE_FLOAT16_VALUE( - 70.366), SIMDE_FLOAT16_VALUE( - 82.181),
        SIMDE_FLOAT16_VALUE( - 14.473),  SIMDE_FLOAT16_VALUE( 16.003), SIMDE_FLOAT16_VALUE( - 24.386),  SIMDE_FLOAT16_VALUE( 17.897) },
      { SIMDE_FLOAT16_VALUE( - 87.854), SIMDE_FLOAT16_VALUE( - 58.662),  SIMDE_FLOAT16_VALUE( 50.993), SIMDE_FLOAT16_VALUE( - 82.181),
         SIMDE_FLOAT16_VALUE( 79.506),  SIMDE_FLOAT16_VALUE( 16.003),  SIMDE_FLOAT16_VALUE( 92.534),  SIMDE_FLOAT16_VALUE( 17.897) } },
    { {  SIMDE_FLOAT16_VALUE(  7.217), SIMDE_FLOAT16_VALUE( -  3.575), SIMDE_FLOAT16_VALUE( - 54.338), SIMDE_FLOAT16_VALUE( - 88.934),
        SIMDE_FLOAT16_VALUE( - 45.428), SIMDE_FLOAT16_VALUE( - 96.685), SIMDE_FLOAT16_VALUE( - 19.259), SIMDE_FLOAT16_VALUE( - 78.009) },
      {  SIMDE_FLOAT16_VALUE( 59.084), SIMDE_FLOAT16_VALUE( - 63.373), SIMDE_FLOAT16_VALUE( - 74.830),  SIMDE_FLOAT16_VALUE( 65.237),
         SIMDE_FLOAT16_VALUE(  6.826),  SIMDE_FLOAT16_VALUE( 80.287), SIMDE_FLOAT16_VALUE( - 55.550), SIMDE_FLOAT16_VALUE( - 99.593) },
      { SIMDE_FLOAT16_VALUE( -  3.575), SIMDE_FLOAT16_VALUE( - 63.373), SIMDE_FLOAT16_VALUE( - 88.934),  SIMDE_FLOAT16_VALUE( 65.237),
        SIMDE_FLOAT16_VALUE( - 96.685),  SIMDE_FLOAT16_VALUE( 80.287), SIMDE_FLOAT16_VALUE( - 78.009), SIMDE_FLOAT16_VALUE( - 99.593) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vtrn2q_f16(a, b);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vtrn2q_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -211.13), SIMDE_FLOAT32_C(  -979.06), SIMDE_FLOAT32_C(   252.18), SIMDE_FLOAT32_C(   585.60) },
      { SIMDE_FLOAT32_C(  -353.90), SIMDE_FLOAT32_C(  -614.27), SIMDE_FLOAT32_C(  -898.32), SIMDE_FLOAT32_C(   395.91) },
      { SIMDE_FLOAT32_C(  -979.06), SIMDE_FLOAT32_C(  -614.27), SIMDE_FLOAT32_C(   585.60), SIMDE_FLOAT32_C(   395.91) } },
    { { SIMDE_FLOAT32_C(   662.54), SIMDE_FLOAT32_C(   470.15), SIMDE_FLOAT32_C(  -417.90), SIMDE_FLOAT32_C(  -256.21) },
      { SIMDE_FLOAT32_C(  -510.87), SIMDE_FLOAT32_C(   875.70), SIMDE_FLOAT32_C(  -440.43), SIMDE_FLOAT32_C(   620.00) },
      { SIMDE_FLOAT32_C(   470.15), SIMDE_FLOAT32_C(   875.70), SIMDE_FLOAT32_C(  -256.21), SIMDE_FLOAT32_C(   620.00) } },
    { { SIMDE_FLOAT32_C(  -175.24), SIMDE_FLOAT32_C(   314.73), SIMDE_FLOAT32_C(  -141.11), SIMDE_FLOAT32_C(  -855.73) },
      { SIMDE_FLOAT32_C(  -301.48), SIMDE_FLOAT32_C(  -992.19), SIMDE_FLOAT32_C(  -362.14), SIMDE_FLOAT32_C(  -921.90) },
      { SIMDE_FLOAT32_C(   314.73), SIMDE_FLOAT32_C(  -992.19), SIMDE_FLOAT32_C(  -855.73), SIMDE_FLOAT32_C(  -921.90) } },
    { { SIMDE_FLOAT32_C(   931.20), SIMDE_FLOAT32_C(  -308.80), SIMDE_FLOAT32_C(   750.81), SIMDE_FLOAT32_C(  -865.99) },
      { SIMDE_FLOAT32_C(  -783.84), SIMDE_FLOAT32_C(  -467.10), SIMDE_FLOAT32_C(  -605.39), SIMDE_FLOAT32_C(     5.03) },
      { SIMDE_FLOAT32_C(  -308.80), SIMDE_FLOAT32_C(  -467.10), SIMDE_FLOAT32_C(  -865.99), SIMDE_FLOAT32_C(     5.03) } },
    { { SIMDE_FLOAT32_C(  -446.16), SIMDE_FLOAT32_C(   646.79), SIMDE_FLOAT32_C(  -409.36), SIMDE_FLOAT32_C(   199.94) },
      { SIMDE_FLOAT32_C(  -967.48), SIMDE_FLOAT32_C(  -307.68), SIMDE_FLOAT32_C(  -404.15), SIMDE_FLOAT32_C(   695.06) },
      { SIMDE_FLOAT32_C(   646.79), SIMDE_FLOAT32_C(  -307.68), SIMDE_FLOAT32_C(   199.94), SIMDE_FLOAT32_C(   695.06) } },
    { { SIMDE_FLOAT32_C(  -837.54), SIMDE_FLOAT32_C(   177.95), SIMDE_FLOAT32_C(  -561.15), SIMDE_FLOAT32_C(  -348.41) },
      { SIMDE_FLOAT32_C(    53.65), SIMDE_FLOAT32_C(    -1.58), SIMDE_FLOAT32_C(  -728.41), SIMDE_FLOAT32_C(   878.40) },
      { SIMDE_FLOAT32_C(   177.95), SIMDE_FLOAT32_C(    -1.58), SIMDE_FLOAT32_C(  -348.41), SIMDE_FLOAT32_C(   878.40) } },
    { { SIMDE_FLOAT32_C(  -686.85), SIMDE_FLOAT32_C(   130.48), SIMDE_FLOAT32_C(  -977.32), SIMDE_FLOAT32_C(    11.67) },
      { SIMDE_FLOAT32_C(   138.29), SIMDE_FLOAT32_C(  -339.46), SIMDE_FLOAT32_C(    89.77), SIMDE_FLOAT32_C(    69.49) },
      { SIMDE_FLOAT32_C(   130.48), SIMDE_FLOAT32_C(  -339.46), SIMDE_FLOAT32_C(    11.67), SIMDE_FLOAT32_C(    69.49) } },
    { { SIMDE_FLOAT32_C(   351.74), SIMDE_FLOAT32_C(  -159.41), SIMDE_FLOAT32_C(   203.49), SIMDE_FLOAT32_C(   567.89) },
      { SIMDE_FLOAT32_C(   373.49), SIMDE_FLOAT32_C(   598.10), SIMDE_FLOAT32_C(  -427.08), SIMDE_FLOAT32_C(   927.33) },
      { SIMDE_FLOAT32_C(  -159.41), SIMDE_FLOAT32_C(   598.10), SIMDE_FLOAT32_C(   567.89), SIMDE_FLOAT32_C(   927.33) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vtrn2q_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vtrn2q_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   808.16), SIMDE_FLOAT64_C(   -66.58) },
      { SIMDE_FLOAT64_C(   640.72), SIMDE_FLOAT64_C(  -179.06) },
      { SIMDE_FLOAT64_C(   -66.58), SIMDE_FLOAT64_C(  -179.06) } },
    { { SIMDE_FLOAT64_C(  -763.23), SIMDE_FLOAT64_C(   245.88) },
      { SIMDE_FLOAT64_C(    64.27), SIMDE_FLOAT64_C(   245.45) },
      { SIMDE_FLOAT64_C(   245.88), SIMDE_FLOAT64_C(   245.45) } },
    { { SIMDE_FLOAT64_C(   533.54), SIMDE_FLOAT64_C(  -357.67) },
      { SIMDE_FLOAT64_C(  -180.56), SIMDE_FLOAT64_C(   -85.73) },
      { SIMDE_FLOAT64_C(  -357.67), SIMDE_FLOAT64_C(   -85.73) } },
    { { SIMDE_FLOAT64_C(   913.02), SIMDE_FLOAT64_C(   -45.29) },
      { SIMDE_FLOAT64_C(  -710.20), SIMDE_FLOAT64_C(   600.50) },
      { SIMDE_FLOAT64_C(   -45.29), SIMDE_FLOAT64_C(   600.50) } },
    { { SIMDE_FLOAT64_C(   103.86), SIMDE_FLOAT64_C(   824.18) },
      { SIMDE_FLOAT64_C(   417.27), SIMDE_FLOAT64_C(   319.73) },
      { SIMDE_FLOAT64_C(   824.18), SIMDE_FLOAT64_C(   319.73) } },
    { { SIMDE_FLOAT64_C(   543.92), SIMDE_FLOAT64_C(   468.66) },
      { SIMDE_FLOAT64_C(  -370.42), SIMDE_FLOAT64_C(  -598.68) },
      { SIMDE_FLOAT64_C(   468.66), SIMDE_FLOAT64_C(  -598.68) } },
    { { SIMDE_FLOAT64_C(  -891.19), SIMDE_FLOAT64_C(   383.96) },
      { SIMDE_FLOAT64_C(    82.38), SIMDE_FLOAT64_C(  -999.44) },
      { SIMDE_FLOAT64_C(   383.96), SIMDE_FLOAT64_C(  -999.44) } },
    { { SIMDE_FLOAT64_C(   899.21), SIMDE_FLOAT64_C(  -263.60) },
      { SIMDE_FLOAT64_C(  -211.00), SIMDE_FLOAT64_C(   707.37) },
      { SIMDE_FLOAT64_C(  -263.60), SIMDE_FLOAT64_C(   707.37) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vtrn2q_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r = simde_vtrn2q_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C( 126), -INT8_C(  47), -INT8_C(  55),  INT8_C(   7), -INT8_C(  42), -INT8_C(  98),  INT8_C(  55), -INT8_C(   9),
         INT8_C( 121),  INT8_C(  61), -INT8_C(  71),  INT8_C(  49), -INT8_C(  54), -INT8_C(  19),  INT8_C(  62),  INT8_C(  54) },
      {  INT8_C( 113),  INT8_C(  96),  INT8_C( 112),  INT8_C(  65),  INT8_C(  76), -INT8_C(  70),  INT8_C(  97), -INT8_C( 119),
         INT8_C(  42),  INT8_C(  57),  INT8_C(  15), -INT8_C( 105),  INT8_C( 114), -INT8_C(  24), -INT8_C(  38), -INT8_C(  15) },
      { -INT8_C(  47),  INT8_C(  96),  INT8_C(   7),  INT8_C(  65), -INT8_C(  98), -INT8_C(  70), -INT8_C(   9), -INT8_C( 119),
         INT8_C(  61),  INT8_C(  57),  INT8_C(  49), -INT8_C( 105), -INT8_C(  19), -INT8_C(  24),  INT8_C(  54), -INT8_C(  15) } },
    { { -INT8_C(  71), -INT8_C(  92), -INT8_C(   8), -INT8_C( 112),  INT8_C(  66),  INT8_C(  48), -INT8_C( 121), -INT8_C(  69),
         INT8_C( 109),  INT8_C(  65), -INT8_C(  20),  INT8_C(  56),  INT8_C(  46),  INT8_C(  42),  INT8_C( 110), -INT8_C(  97) },
      { -INT8_C( 117), -INT8_C(  34), -INT8_C(  32), -INT8_C(  41), -INT8_C( 104),  INT8_C(  66),  INT8_C(  96), -INT8_C(  62),
         INT8_C( 123),  INT8_C( 111),  INT8_C(  90), -INT8_C(  18),  INT8_C(  88),  INT8_C(  52), -INT8_C(  33),  INT8_C(  17) },
      { -INT8_C(  92), -INT8_C(  34), -INT8_C( 112), -INT8_C(  41),  INT8_C(  48),  INT8_C(  66), -INT8_C(  69), -INT8_C(  62),
         INT8_C(  65),  INT8_C( 111),  INT8_C(  56), -INT8_C(  18),  INT8_C(  42),  INT8_C(  52), -INT8_C(  97),  INT8_C(  17) } },
    { { -INT8_C(  40), -INT8_C(  41), -INT8_C(  95),  INT8_C(  26),  INT8_C(   7),  INT8_C(  41), -INT8_C(  42),  INT8_C( 117),
         INT8_C( 106), -INT8_C(  62), -INT8_C(  83), -INT8_C( 104), -INT8_C(  19),  INT8_C(  27),  INT8_C(  55),  INT8_C( 120) },
      { -INT8_C(   7),  INT8_C(  24),  INT8_C(  79), -INT8_C( 110),  INT8_C(  90), -INT8_C(  81),  INT8_C(  84), -INT8_C(  43),
         INT8_C(  31), -INT8_C(  82), -INT8_C(  61),  INT8_C( 119), -INT8_C(  29), -INT8_C(  94), -INT8_C( 120), -INT8_C(  69) },
      { -INT8_C(  41),  INT8_C(  24),  INT8_C(  26), -INT8_C( 110),  INT8_C(  41), -INT8_C(  81),  INT8_C( 117), -INT8_C(  43),
        -INT8_C(  62), -INT8_C(  82), -INT8_C( 104),  INT8_C( 119),  INT8_C(  27), -INT8_C(  94),  INT8_C( 120), -INT8_C(  69) } },
    { {  INT8_C( 122),  INT8_C(  42), -INT8_C(  42), -INT8_C( 127),  INT8_C(  83), -INT8_C(  84), -INT8_C(  10), -INT8_C(  67),
         INT8_C( 110), -INT8_C(  93),  INT8_C(  85),  INT8_C(  91), -INT8_C(  66), -INT8_C( 116), -INT8_C(  45), -INT8_C(  72) },
      { -INT8_C(  92),  INT8_C(  34),  INT8_C(  74), -INT8_C(   2), -INT8_C(  46), -INT8_C(  98), -INT8_C(  44), -INT8_C(  15),
         INT8_C(  77), -INT8_C( 105),  INT8_C( 104),  INT8_C(  48),  INT8_C(  58), -INT8_C(  16), -INT8_C(  21), -INT8_C(  76) },
      {  INT8_C(  42),  INT8_C(  34), -INT8_C( 127), -INT8_C(   2), -INT8_C(  84), -INT8_C(  98), -INT8_C(  67), -INT8_C(  15),
        -INT8_C(  93), -INT8_C( 105),  INT8_C(  91),  INT8_C(  48), -INT8_C( 116), -INT8_C(  16), -INT8_C(  72), -INT8_C(  76) } },
    { {  INT8_C(  26), -INT8_C(  63),  INT8_C(  53),  INT8_C( 109),  INT8_C( 109),  INT8_C(  44),  INT8_C(  42), -INT8_C(  36),
        -INT8_C(  49),      INT8_MAX,  INT8_C(  55), -INT8_C( 114),  INT8_C(  12),  INT8_C(  11),  INT8_C(  70), -INT8_C(  80) },
      {  INT8_C(  45), -INT8_C( 112), -INT8_C(  81), -INT8_C(   1),  INT8_C(  46), -INT8_C( 125), -INT8_C(  16),  INT8_C( 123),
         INT8_C(  26),  INT8_C(  88), -INT8_C(  85),  INT8_C(  84),  INT8_C(  73), -INT8_C( 105),  INT8_C(   8),  INT8_C(  99) },
      { -INT8_C(  63), -INT8_C( 112),  INT8_C( 109), -INT8_C(   1),  INT8_C(  44), -INT8_C( 125), -INT8_C(  36),  INT8_C( 123),
             INT8_MAX,  INT8_C(  88), -INT8_C( 114),  INT8_C(  84),  INT8_C(  11), -INT8_C( 105), -INT8_C(  80),  INT8_C(  99) } },
    { {  INT8_C(  88),  INT8_C(  62), -INT8_C(  47), -INT8_C(  58),  INT8_C( 106), -INT8_C(   5), -INT8_C(  94),  INT8_C(  57),
         INT8_C( 123), -INT8_C(  39), -INT8_C(  57), -INT8_C( 121), -INT8_C(  28),  INT8_C(  13),  INT8_C(  55),  INT8_C(  18) },
      { -INT8_C(  99), -INT8_C(  26),  INT8_C(  17), -INT8_C(  52),  INT8_C( 105),  INT8_C(   2),  INT8_C(  71), -INT8_C( 124),
         INT8_C(  90), -INT8_C(  13), -INT8_C(  40), -INT8_C(  93), -INT8_C( 118), -INT8_C(  31),  INT8_C(   7), -INT8_C(  30) },
      {  INT8_C(  62), -INT8_C(  26), -INT8_C(  58), -INT8_C(  52), -INT8_C(   5),  INT8_C(   2),  INT8_C(  57), -INT8_C( 124),
        -INT8_C(  39), -INT8_C(  13), -INT8_C( 121), -INT8_C(  93),  INT8_C(  13), -INT8_C(  31),  INT8_C(  18), -INT8_C(  30) } },
    { {  INT8_C(  31), -INT8_C(  40), -INT8_C(  88), -INT8_C( 119), -INT8_C(  45),  INT8_C(  74), -INT8_C(  62),  INT8_C(  78),
         INT8_C(  36), -INT8_C( 118), -INT8_C(  43),  INT8_C(   8), -INT8_C( 105),  INT8_C(  13),  INT8_C(  26),  INT8_C(  53) },
      { -INT8_C(  13),  INT8_C(  44),  INT8_C(   1),  INT8_C(  93),  INT8_C(  46),  INT8_C(  72), -INT8_C(  31), -INT8_C( 120),
         INT8_C(  59), -INT8_C(  71),  INT8_C(  44), -INT8_C(  59), -INT8_C( 102),  INT8_C(  51), -INT8_C(  88), -INT8_C(  71) },
      { -INT8_C(  40),  INT8_C(  44), -INT8_C( 119),  INT8_C(  93),  INT8_C(  74),  INT8_C(  72),  INT8_C(  78), -INT8_C( 120),
        -INT8_C( 118), -INT8_C(  71),  INT8_C(   8), -INT8_C(  59),  INT8_C(  13),  INT8_C(  51),  INT8_C(  53), -INT8_C(  71) } },
    { {  INT8_C(  11),  INT8_C(  80),  INT8_C(  66), -INT8_C(  34), -INT8_C( 101),  INT8_C(   5),  INT8_C(  45), -INT8_C(  65),
        -INT8_C( 113),  INT8_C(   2), -INT8_C(  57),  INT8_C(  38),  INT8_C(  15), -INT8_C(  30),  INT8_C(  91),  INT8_C(   3) },
      {  INT8_C(  14),  INT8_C(  92),  INT8_C(  96),  INT8_C(  60), -INT8_C(  91),  INT8_C(  65), -INT8_C(  60), -INT8_C(  32),
        -INT8_C(   6), -INT8_C(  16), -INT8_C(  90), -INT8_C( 107),  INT8_C(  35),  INT8_C(  78),  INT8_C(  78),  INT8_C(  46) },
      {  INT8_C(  80),  INT8_C(  92), -INT8_C(  34),  INT8_C(  60),  INT8_C(   5),  INT8_C(  65), -INT8_C(  65), -INT8_C(  32),
         INT8_C(   2), -INT8_C(  16),  INT8_C(  38), -INT8_C( 107), -INT8_C(  30),  INT8_C(  78),  INT8_C(   3),  INT8_C(  46) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vtrn2q_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vtrn2q_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 25616),  INT16_C( 12174), -INT16_C( 26288),  INT16_C( 19899),  INT16_C( 18017), -INT16_C( 25514), -INT16_C(  3524),  INT16_C( 25184) },
      { -INT16_C(  5010),  INT16_C( 21716),  INT16_C(  8269), -INT16_C(  9581),  INT16_C(  9727), -INT16_C( 17748), -INT16_C( 10274), -INT16_C( 12721) },
      {  INT16_C( 12174),  INT16_C( 21716),  INT16_C( 19899), -INT16_C(  9581), -INT16_C( 25514), -INT16_C( 17748),  INT16_C( 25184), -INT16_C( 12721) } },
    { { -INT16_C(  8846), -INT16_C( 15363), -INT16_C( 18313), -INT16_C( 10224),  INT16_C( 26366),  INT16_C( 14964), -INT16_C( 10919), -INT16_C( 14436) },
      {  INT16_C( 29121),  INT16_C(  3611), -INT16_C( 20847), -INT16_C( 28183), -INT16_C( 27181), -INT16_C( 20149), -INT16_C( 26004), -INT16_C(  8321) },
      { -INT16_C( 15363),  INT16_C(  3611), -INT16_C( 10224), -INT16_C( 28183),  INT16_C( 14964), -INT16_C( 20149), -INT16_C( 14436), -INT16_C(  8321) } },
    { {  INT16_C( 31863), -INT16_C(  4446), -INT16_C( 19916),  INT16_C( 12999),  INT16_C( 15128),  INT16_C( 29036),  INT16_C(  2320), -INT16_C( 11720) },
      {  INT16_C( 21626),  INT16_C(  3040), -INT16_C( 14078), -INT16_C( 10596), -INT16_C(  6305), -INT16_C( 13433),  INT16_C(  1921), -INT16_C(  1622) },
      { -INT16_C(  4446),  INT16_C(  3040),  INT16_C( 12999), -INT16_C( 10596),  INT16_C( 29036), -INT16_C( 13433), -INT16_C( 11720), -INT16_C(  1622) } },
    { {  INT16_C( 19587), -INT16_C( 18201), -INT16_C( 20738),  INT16_C(  6122),  INT16_C( 22506), -INT16_C(  1400), -INT16_C( 16032), -INT16_C(  9524) },
      { -INT16_C( 21227),  INT16_C(  6117), -INT16_C( 32138), -INT16_C( 10771),  INT16_C( 30057), -INT16_C(  5215),  INT16_C( 19324), -INT16_C(    28) },
      { -INT16_C( 18201),  INT16_C(  6117),  INT16_C(  6122), -INT16_C( 10771), -INT16_C(  1400), -INT16_C(  5215), -INT16_C(  9524), -INT16_C(    28) } },
    { { -INT16_C( 13416), -INT16_C( 26953), -INT16_C( 23942),  INT16_C( 25773),  INT16_C( 14073),  INT16_C( 22878),  INT16_C( 11255),  INT16_C(  3123) },
      {  INT16_C(  6360),  INT16_C( 20003),  INT16_C(  4506),  INT16_C(  1060), -INT16_C( 14970),  INT16_C(   751), -INT16_C( 11504), -INT16_C( 22527) },
      { -INT16_C( 26953),  INT16_C( 20003),  INT16_C( 25773),  INT16_C(  1060),  INT16_C( 22878),  INT16_C(   751),  INT16_C(  3123), -INT16_C( 22527) } },
    { { -INT16_C( 18018),  INT16_C(  6207), -INT16_C(  5029),  INT16_C( 21628), -INT16_C(  9438),  INT16_C(  6573), -INT16_C(  8186), -INT16_C(  8667) },
      {  INT16_C( 18936), -INT16_C( 27860),  INT16_C( 20570), -INT16_C(  8041), -INT16_C( 31211),  INT16_C(  9954), -INT16_C(  7335), -INT16_C(  2098) },
      {  INT16_C(  6207), -INT16_C( 27860),  INT16_C( 21628), -INT16_C(  8041),  INT16_C(  6573),  INT16_C(  9954), -INT16_C(  8667), -INT16_C(  2098) } },
    { {  INT16_C(  3484), -INT16_C(  2288), -INT16_C( 29446),  INT16_C(  7243), -INT16_C(  1945),  INT16_C( 27958),  INT16_C( 23512), -INT16_C( 11957) },
      {  INT16_C( 30884), -INT16_C(   412), -INT16_C(  1080), -INT16_C(  8482), -INT16_C( 16255), -INT16_C(  9724), -INT16_C( 11612),  INT16_C( 16593) },
      { -INT16_C(  2288), -INT16_C(   412),  INT16_C(  7243), -INT16_C(  8482),  INT16_C( 27958), -INT16_C(  9724), -INT16_C( 11957),  INT16_C( 16593) } },
    { { -INT16_C(  7712), -INT16_C(  9672), -INT16_C( 31890), -INT16_C( 10762),  INT16_C( 11388),  INT16_C( 21571), -INT16_C( 29048),  INT16_C( 11301) },
      { -INT16_C( 30458), -INT16_C( 12501),  INT16_C(  2436),  INT16_C(  1453), -INT16_C( 20022),  INT16_C( 28383), -INT16_C( 20093),  INT16_C( 25518) },
      { -INT16_C(  9672), -INT16_C( 12501), -INT16_C( 10762),  INT16_C(  1453),  INT16_C( 21571),  INT16_C( 28383),  INT16_C( 11301),  INT16_C( 25518) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vtrn2q_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vtrn2q_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1320359767),  INT32_C(  1637046083),  INT32_C(   635603625), -INT32_C(   170216369) },
      { -INT32_C(  1440222354), -INT32_C(   386047728),  INT32_C(  1218036504), -INT32_C(  1417935102) },
      {  INT32_C(  1637046083), -INT32_C(   386047728), -INT32_C(   170216369), -INT32_C(  1417935102) } },
    { {  INT32_C(   861719023), -INT32_C(   912986080), -INT32_C(   890276230), -INT32_C(  1732261590) },
      { -INT32_C(   851253572),  INT32_C(  1605713735),  INT32_C(    78073346),  INT32_C(  1169106005) },
      { -INT32_C(   912986080),  INT32_C(  1605713735), -INT32_C(  1732261590),  INT32_C(  1169106005) } },
    { {  INT32_C(   225971437),  INT32_C(  1993739516), -INT32_C(  1405041278),  INT32_C(  1262813070) },
      {  INT32_C(   739804901), -INT32_C(   930361915),  INT32_C(  1909207836),  INT32_C(  1152810071) },
      {  INT32_C(  1993739516), -INT32_C(   930361915),  INT32_C(  1262813070),  INT32_C(  1152810071) } },
    { { -INT32_C(  2075054456), -INT32_C(  1124456646),  INT32_C(  2070428653),  INT32_C(   549891130) },
      { -INT32_C(   129180110), -INT32_C(   926885716),  INT32_C(  1647938571), -INT32_C(  1868107768) },
      { -INT32_C(  1124456646), -INT32_C(   926885716),  INT32_C(   549891130), -INT32_C(  1868107768) } },
    { {  INT32_C(  1494546206),  INT32_C(   185929502), -INT32_C(  2071495094),  INT32_C(  1571048746) },
      { -INT32_C(   665456340), -INT32_C(   727706167), -INT32_C(  1439245919), -INT32_C(   398795575) },
      {  INT32_C(   185929502), -INT32_C(   727706167),  INT32_C(  1571048746), -INT32_C(   398795575) } },
    { { -INT32_C(   247377965), -INT32_C(  1459792290), -INT32_C(    13859628), -INT32_C(    44248623) },
      { -INT32_C(  1948929598),  INT32_C(  1734309318),  INT32_C(   403805519),  INT32_C(  1140870257) },
      { -INT32_C(  1459792290),  INT32_C(  1734309318), -INT32_C(    44248623),  INT32_C(  1140870257) } },
    { { -INT32_C(   113950309),  INT32_C(  1822503576), -INT32_C(  2006200906),  INT32_C(  1619380126) },
      {  INT32_C(  1055611768),  INT32_C(   530991824),  INT32_C(  1345894367), -INT32_C(  1634453501) },
      {  INT32_C(  1822503576),  INT32_C(   530991824),  INT32_C(  1619380126), -INT32_C(  1634453501) } },
    { {  INT32_C(   311937658), -INT32_C(  1283573508), -INT32_C(  1539577338),  INT32_C(   705020081) },
      { -INT32_C(   328667109),  INT32_C(   436932155), -INT32_C(   915717178), -INT32_C(   160891012) },
      { -INT32_C(  1283573508),  INT32_C(   436932155),  INT32_C(   705020081), -INT32_C(   160891012) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vtrn2q_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vtrn2q_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C(   45048472413891075),  INT64_C(  152343486260863284) },
      { -INT64_C( 7730196300375534852), -INT64_C( 8005652403684821719) },
      {  INT64_C(  152343486260863284), -INT64_C( 8005652403684821719) } },
    { {  INT64_C( 1006278375945588127), -INT64_C( 7206005011547724955) },
      {  INT64_C( 1148738847977968370), -INT64_C( 2056190901628563624) },
      { -INT64_C( 7206005011547724955), -INT64_C( 2056190901628563624) } },
    { {  INT64_C( 4946309049015261886), -INT64_C( 5085055702267746507) },
      {  INT64_C( 6144890095936133458),  INT64_C(   89703941150560535) },
      { -INT64_C( 5085055702267746507),  INT64_C(   89703941150560535) } },
    { {  INT64_C( 2211054014804007052), -INT64_C( 8906606921584021020) },
      { -INT64_C( 7238688109679051718),  INT64_C(  331072265161983572) },
      { -INT64_C( 8906606921584021020),  INT64_C(  331072265161983572) } },
    { {  INT64_C( 5932400063550533708), -INT64_C( 2250282873078790641) },
      { -INT64_C( 2810630427950743073),  INT64_C( 8423146550228677737) },
      { -INT64_C( 2250282873078790641),  INT64_C( 8423146550228677737) } },
    { { -INT64_C( 9009452761172257736),  INT64_C( 4092514606168405316) },
      { -INT64_C( 1340495419970625015),  INT64_C( 1453734540291790223) },
      {  INT64_C( 4092514606168405316),  INT64_C( 1453734540291790223) } },
    { {  INT64_C( 1800509477191603719),  INT64_C( 5780595826556583847) },
      { -INT64_C(  134753468448648017), -INT64_C( 6122395599108706281) },
      {  INT64_C( 5780595826556583847), -INT64_C( 6122395599108706281) } },
    { {  INT64_C( 1991472244662321847),  INT64_C( 2555603067598513888) },
      { -INT64_C( 5866650351400692696), -INT64_C( 2037973200194614680) },
      {  INT64_C( 2555603067598513888), -INT64_C( 2037973200194614680) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vtrn2q_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_vtrn2q_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 20), UINT8_C(238), UINT8_C(252), UINT8_C(213), UINT8_C( 66), UINT8_C(233), UINT8_C(216), UINT8_C( 19),
        UINT8_C(139), UINT8_C(224), UINT8_C( 95), UINT8_C( 61), UINT8_C(180), UINT8_C(215), UINT8_C(124), UINT8_C(191) },
      { UINT8_C(  7), UINT8_C(  5), UINT8_C(234), UINT8_C(232), UINT8_C(111), UINT8_C(230), UINT8_C(156), UINT8_C( 66),
        UINT8_C( 82), UINT8_C(  3), UINT8_C(221), UINT8_C(221), UINT8_C(135), UINT8_C(  8), UINT8_C( 89), UINT8_C(155) },
      { UINT8_C(238), UINT8_C(  5), UINT8_C(213), UINT8_C(232), UINT8_C(233), UINT8_C(230), UINT8_C( 19), UINT8_C( 66),
        UINT8_C(224), UINT8_C(  3), UINT8_C( 61), UINT8_C(221), UINT8_C(215), UINT8_C(  8), UINT8_C(191), UINT8_C(155) } },
    { { UINT8_C(247), UINT8_C( 85), UINT8_C(112), UINT8_C( 57), UINT8_C( 62), UINT8_C( 73), UINT8_C( 76), UINT8_C(202),
        UINT8_C( 41), UINT8_C(171), UINT8_C(  7), UINT8_C(221), UINT8_C(130), UINT8_C(132), UINT8_C(156), UINT8_C(137) },
      { UINT8_C(137), UINT8_C(135), UINT8_C(113), UINT8_C(249), UINT8_C(109), UINT8_C( 14), UINT8_C( 59), UINT8_C(191),
        UINT8_C( 17), UINT8_C( 25), UINT8_C(157), UINT8_C(152), UINT8_C( 33), UINT8_C(246), UINT8_C( 51), UINT8_C( 24) },
      { UINT8_C( 85), UINT8_C(135), UINT8_C( 57), UINT8_C(249), UINT8_C( 73), UINT8_C( 14), UINT8_C(202), UINT8_C(191),
        UINT8_C(171), UINT8_C( 25), UINT8_C(221), UINT8_C(152), UINT8_C(132), UINT8_C(246), UINT8_C(137), UINT8_C( 24) } },
    { { UINT8_C( 75), UINT8_C(163), UINT8_C( 81), UINT8_C(138), UINT8_C(236), UINT8_C(157), UINT8_C( 84), UINT8_C( 22),
        UINT8_C( 72), UINT8_C( 91), UINT8_C(243), UINT8_C(202), UINT8_C(223), UINT8_C(144), UINT8_C( 84), UINT8_C(105) },
      { UINT8_C( 23), UINT8_C(197), UINT8_C( 98), UINT8_C(132), UINT8_C(211), UINT8_C(157), UINT8_C( 67), UINT8_C(228),
        UINT8_C(182), UINT8_C(224), UINT8_C(124), UINT8_C(216), UINT8_C(214), UINT8_C(175), UINT8_C(240), UINT8_C( 34) },
      { UINT8_C(163), UINT8_C(197), UINT8_C(138), UINT8_C(132), UINT8_C(157), UINT8_C(157), UINT8_C( 22), UINT8_C(228),
        UINT8_C( 91), UINT8_C(224), UINT8_C(202), UINT8_C(216), UINT8_C(144), UINT8_C(175), UINT8_C(105), UINT8_C( 34) } },
    { { UINT8_C( 83), UINT8_C( 66), UINT8_C(172), UINT8_C( 63), UINT8_C(223), UINT8_C(  0), UINT8_C( 85), UINT8_C( 40),
        UINT8_C( 91), UINT8_C( 73), UINT8_C(242), UINT8_C( 59), UINT8_C(217), UINT8_C( 70), UINT8_C(164), UINT8_C(240) },
      { UINT8_C( 12), UINT8_C(  6), UINT8_C(116), UINT8_C(223), UINT8_C(163), UINT8_C(183), UINT8_C(196), UINT8_C( 90),
        UINT8_C(152), UINT8_C( 64), UINT8_C( 50), UINT8_C(110), UINT8_C(240), UINT8_C( 34), UINT8_C(144), UINT8_C( 67) },
      { UINT8_C( 66), UINT8_C(  6), UINT8_C( 63), UINT8_C(223), UINT8_C(  0), UINT8_C(183), UINT8_C( 40), UINT8_C( 90),
        UINT8_C( 73), UINT8_C( 64), UINT8_C( 59), UINT8_C(110), UINT8_C( 70), UINT8_C( 34), UINT8_C(240), UINT8_C( 67) } },
    { { UINT8_C(100), UINT8_C( 60), UINT8_C(130), UINT8_C( 68), UINT8_C( 60), UINT8_C(216), UINT8_C(108), UINT8_C(152),
        UINT8_C( 33), UINT8_C( 94), UINT8_C(211), UINT8_C(250), UINT8_C(165), UINT8_C(119), UINT8_C(234), UINT8_C(177) },
      { UINT8_C(125), UINT8_C( 94), UINT8_C(144), UINT8_C( 32), UINT8_C( 21), UINT8_C( 84), UINT8_C(122), UINT8_C(173),
        UINT8_C(149), UINT8_C(172), UINT8_C( 28), UINT8_C(133), UINT8_C(207), UINT8_C(172), UINT8_C(200), UINT8_C( 51) },
      { UINT8_C( 60), UINT8_C( 94), UINT8_C( 68), UINT8_C( 32), UINT8_C(216), UINT8_C( 84), UINT8_C(152), UINT8_C(173),
        UINT8_C( 94), UINT8_C(172), UINT8_C(250), UINT8_C(133), UINT8_C(119), UINT8_C(172), UINT8_C(177), UINT8_C( 51) } },
    { { UINT8_C(233), UINT8_C( 74), UINT8_C(119), UINT8_C( 37), UINT8_C( 34), UINT8_C(227), UINT8_C(189), UINT8_C( 67),
        UINT8_C( 66), UINT8_C(144), UINT8_C( 61), UINT8_C(231), UINT8_C(  7), UINT8_C( 39), UINT8_C(152), UINT8_C(132) },
      { UINT8_C(133), UINT8_C( 40), UINT8_C(165), UINT8_C(155), UINT8_C(125), UINT8_C( 31), UINT8_C( 72), UINT8_C( 18),
        UINT8_C(204), UINT8_C(100), UINT8_C(151), UINT8_C(155), UINT8_C( 17), UINT8_C( 95), UINT8_C(206), UINT8_C(250) },
      { UINT8_C( 74), UINT8_C( 40), UINT8_C( 37), UINT8_C(155), UINT8_C(227), UINT8_C( 31), UINT8_C( 67), UINT8_C( 18),
        UINT8_C(144), UINT8_C(100), UINT8_C(231), UINT8_C(155), UINT8_C( 39), UINT8_C( 95), UINT8_C(132), UINT8_C(250) } },
    { { UINT8_C(169), UINT8_C( 70), UINT8_C( 31), UINT8_C(204), UINT8_C( 41), UINT8_C(221), UINT8_C( 15), UINT8_C(107),
        UINT8_C(109), UINT8_C( 77), UINT8_C( 82), UINT8_C(117), UINT8_C(116), UINT8_C(234), UINT8_C(249), UINT8_C(250) },
      { UINT8_C( 19), UINT8_C(158), UINT8_C(149), UINT8_C(144), UINT8_C(190), UINT8_C(221), UINT8_C(162), UINT8_C(138),
        UINT8_C( 66), UINT8_C( 57), UINT8_C( 37), UINT8_C( 83), UINT8_C(152), UINT8_C(243), UINT8_C( 77), UINT8_C( 65) },
      { UINT8_C( 70), UINT8_C(158), UINT8_C(204), UINT8_C(144), UINT8_C(221), UINT8_C(221), UINT8_C(107), UINT8_C(138),
        UINT8_C( 77), UINT8_C( 57), UINT8_C(117), UINT8_C( 83), UINT8_C(234), UINT8_C(243), UINT8_C(250), UINT8_C( 65) } },
    { { UINT8_C( 57), UINT8_C(108), UINT8_C( 13), UINT8_C( 99), UINT8_C( 73), UINT8_C( 29), UINT8_C(206), UINT8_C(183),
        UINT8_C(106), UINT8_C( 33), UINT8_C( 44), UINT8_C(222), UINT8_C( 11), UINT8_C( 37), UINT8_C(216), UINT8_C( 30) },
      { UINT8_C(196), UINT8_C(109), UINT8_C(174), UINT8_C(130), UINT8_C( 75), UINT8_C( 80), UINT8_C( 12), UINT8_C(141),
        UINT8_C(137), UINT8_C( 49), UINT8_C(224), UINT8_C( 33), UINT8_C( 36), UINT8_C( 45), UINT8_C( 99), UINT8_C( 94) },
      { UINT8_C(108), UINT8_C(109), UINT8_C( 99), UINT8_C(130), UINT8_C( 29), UINT8_C( 80), UINT8_C(183), UINT8_C(141),
        UINT8_C( 33), UINT8_C( 49), UINT8_C(222), UINT8_C( 33), UINT8_C( 37), UINT8_C( 45), UINT8_C( 30), UINT8_C( 94) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vtrn2q_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vtrn2q_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(  871), UINT16_C(60974), UINT16_C(46339), UINT16_C(41413), UINT16_C(48049), UINT16_C(26805), UINT16_C( 6238), UINT16_C(17076) },
      { UINT16_C(16789), UINT16_C(31129), UINT16_C(27483), UINT16_C(21460), UINT16_C(34444), UINT16_C(40210), UINT16_C(60228), UINT16_C(43796) },
      { UINT16_C(60974), UINT16_C(31129), UINT16_C(41413), UINT16_C(21460), UINT16_C(26805), UINT16_C(40210), UINT16_C(17076), UINT16_C(43796) } },
    { { UINT16_C(17391), UINT16_C(62105), UINT16_C(24568), UINT16_C(43411), UINT16_C(18714), UINT16_C(30993), UINT16_C(50529), UINT16_C(63163) },
      { UINT16_C(21510), UINT16_C(24944), UINT16_C(17600), UINT16_C(19636), UINT16_C(50890), UINT16_C( 3817), UINT16_C(64945), UINT16_C(41145) },
      { UINT16_C(62105), UINT16_C(24944), UINT16_C(43411), UINT16_C(19636), UINT16_C(30993), UINT16_C( 3817), UINT16_C(63163), UINT16_C(41145) } },
    { { UINT16_C(21312), UINT16_C(14483), UINT16_C( 9906), UINT16_C(52449), UINT16_C(62063), UINT16_C(53317), UINT16_C(  439), UINT16_C(48583) },
      { UINT16_C(14165), UINT16_C( 5406), UINT16_C(53883), UINT16_C(17761), UINT16_C(19096), UINT16_C(19028), UINT16_C( 3400), UINT16_C(35050) },
      { UINT16_C(14483), UINT16_C( 5406), UINT16_C(52449), UINT16_C(17761), UINT16_C(53317), UINT16_C(19028), UINT16_C(48583), UINT16_C(35050) } },
    { { UINT16_C(32096), UINT16_C( 4801), UINT16_C(41636), UINT16_C( 5087), UINT16_C( 9365), UINT16_C(19684), UINT16_C(43813), UINT16_C(31498) },
      { UINT16_C(10466), UINT16_C(23952), UINT16_C(62203), UINT16_C(37794), UINT16_C(63036), UINT16_C(34013), UINT16_C(51204), UINT16_C(25613) },
      { UINT16_C( 4801), UINT16_C(23952), UINT16_C( 5087), UINT16_C(37794), UINT16_C(19684), UINT16_C(34013), UINT16_C(31498), UINT16_C(25613) } },
    { { UINT16_C(52805), UINT16_C(59767), UINT16_C(22128), UINT16_C( 1533), UINT16_C(57722), UINT16_C(41042), UINT16_C(23692), UINT16_C(28187) },
      { UINT16_C(43908), UINT16_C(32715), UINT16_C(28061), UINT16_C(55827), UINT16_C(61540), UINT16_C(26718), UINT16_C(27576), UINT16_C(65228) },
      { UINT16_C(59767), UINT16_C(32715), UINT16_C( 1533), UINT16_C(55827), UINT16_C(41042), UINT16_C(26718), UINT16_C(28187), UINT16_C(65228) } },
    { { UINT16_C(17209), UINT16_C(43751), UINT16_C(58521), UINT16_C( 5295), UINT16_C(  453), UINT16_C(20916), UINT16_C(53085), UINT16_C(58047) },
      { UINT16_C(35450), UINT16_C( 6241), UINT16_C(29944), UINT16_C(23794), UINT16_C(20581), UINT16_C( 7620), UINT16_C(37052), UINT16_C(62747) },
      { UINT16_C(43751), UINT16_C( 6241), UINT16_C( 5295), UINT16_C(23794), UINT16_C(20916), UINT16_C( 7620), UINT16_C(58047), UINT16_C(62747) } },
    { { UINT16_C(  980), UINT16_C(28063), UINT16_C(20455), UINT16_C(44417), UINT16_C(13648), UINT16_C(44798), UINT16_C(48644), UINT16_C(32656) },
      { UINT16_C(61768), UINT16_C(16535), UINT16_C(35174), UINT16_C(52124), UINT16_C(24793), UINT16_C(38376), UINT16_C( 1265), UINT16_C(50571) },
      { UINT16_C(28063), UINT16_C(16535), UINT16_C(44417), UINT16_C(52124), UINT16_C(44798), UINT16_C(38376), UINT16_C(32656), UINT16_C(50571) } },
    { { UINT16_C(10759), UINT16_C(60978), UINT16_C(46201), UINT16_C(51867), UINT16_C(39657), UINT16_C(61048), UINT16_C( 2136), UINT16_C(41069) },
      { UINT16_C( 1273), UINT16_C(24545), UINT16_C(32141), UINT16_C(26154), UINT16_C( 5086), UINT16_C(53244), UINT16_C(34583), UINT16_C( 7828) },
      { UINT16_C(60978), UINT16_C(24545), UINT16_C(51867), UINT16_C(26154), UINT16_C(61048), UINT16_C(53244), UINT16_C(41069), UINT16_C( 7828) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vtrn2q_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vtrn2q_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1786091532), UINT32_C(2913397648), UINT32_C(2660777932), UINT32_C(1683023251) },
      { UINT32_C( 419814195), UINT32_C(3980578117), UINT32_C( 636435713), UINT32_C(2575415437) },
      { UINT32_C(2913397648), UINT32_C(3980578117), UINT32_C(1683023251), UINT32_C(2575415437) } },
    { { UINT32_C(3775198801), UINT32_C(2911808225), UINT32_C(2085299945), UINT32_C(1071684619) },
      { UINT32_C(3159942775), UINT32_C(3031014067), UINT32_C(1691982295), UINT32_C(2734512721) },
      { UINT32_C(2911808225), UINT32_C(3031014067), UINT32_C(1071684619), UINT32_C(2734512721) } },
    { { UINT32_C( 847511889), UINT32_C(2514490027), UINT32_C(1141975865), UINT32_C(1065611975) },
      { UINT32_C(2348538840), UINT32_C(1279239541), UINT32_C(2410682430), UINT32_C(3274878578) },
      { UINT32_C(2514490027), UINT32_C(1279239541), UINT32_C(1065611975), UINT32_C(3274878578) } },
    { { UINT32_C(1542895279), UINT32_C(  32560840), UINT32_C(3376808193), UINT32_C(3406350835) },
      { UINT32_C( 441844645), UINT32_C(3865548200), UINT32_C( 544610221), UINT32_C(1977854149) },
      { UINT32_C(  32560840), UINT32_C(3865548200), UINT32_C(3406350835), UINT32_C(1977854149) } },
    { { UINT32_C( 651221342), UINT32_C(2972237999), UINT32_C(3044699841), UINT32_C(3699409463) },
      { UINT32_C( 787994501), UINT32_C( 437542508), UINT32_C( 993692277), UINT32_C(2427460914) },
      { UINT32_C(2972237999), UINT32_C( 437542508), UINT32_C(3699409463), UINT32_C(2427460914) } },
    { { UINT32_C(2797043959), UINT32_C(  22536000), UINT32_C(2226573645), UINT32_C(3647027027) },
      { UINT32_C(2047301646), UINT32_C( 731126710), UINT32_C(3630616230), UINT32_C(3815315180) },
      { UINT32_C(  22536000), UINT32_C( 731126710), UINT32_C(3647027027), UINT32_C(3815315180) } },
    { { UINT32_C(3599310998), UINT32_C(1289282047), UINT32_C( 114331314), UINT32_C(3554619845) },
      { UINT32_C(1062135433), UINT32_C(2808865281), UINT32_C(2642465201), UINT32_C(2122377704) },
      { UINT32_C(1289282047), UINT32_C(2808865281), UINT32_C(3554619845), UINT32_C(2122377704) } },
    { { UINT32_C( 139790601), UINT32_C(2639539690), UINT32_C(2174952635), UINT32_C(3746857558) },
      { UINT32_C(1763680872), UINT32_C( 907119237), UINT32_C(1137938779), UINT32_C(2210550650) },
      { UINT32_C(2639539690), UINT32_C( 907119237), UINT32_C(3746857558), UINT32_C(2210550650) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vtrn2q_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vtrn2q_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 6945319424494524748), UINT64_C(16610643692567852571) },
      { UINT64_C( 6955632144508350698), UINT64_C( 8616304367102141145) },
      { UINT64_C(16610643692567852571), UINT64_C( 8616304367102141145) } },
    { { UINT64_C(  483247366258044957), UINT64_C(10529975198939663308) },
      { UINT64_C( 1036481247570548332), UINT64_C( 9734062660554794868) },
      { UINT64_C(10529975198939663308), UINT64_C( 9734062660554794868) } },
    { { UINT64_C( 3276246002131765894), UINT64_C( 6310820620303658843) },
      { UINT64_C( 2711935197491257183), UINT64_C( 4743376430044571105) },
      { UINT64_C( 6310820620303658843), UINT64_C( 4743376430044571105) } },
    { { UINT64_C(11165594730051579749), UINT64_C( 4925304002160909336) },
      { UINT64_C( 5649618867251098256), UINT64_C( 7843984154933472479) },
      { UINT64_C( 4925304002160909336), UINT64_C( 7843984154933472479) } },
    { { UINT64_C(14913150880268389661), UINT64_C( 6101299713457361539) },
      { UINT64_C(16112188414821303774), UINT64_C(13807286187674121257) },
      { UINT64_C( 6101299713457361539), UINT64_C(13807286187674121257) } },
    { { UINT64_C( 8820038150351737058), UINT64_C( 4808593589038889379) },
      { UINT64_C( 8715071445204291859), UINT64_C(11798381818995567451) },
      { UINT64_C( 4808593589038889379), UINT64_C(11798381818995567451) } },
    { { UINT64_C(10053903435184264981), UINT64_C(  757640439803308252) },
      { UINT64_C(10647933628473741822), UINT64_C(14474090585097530747) },
      { UINT64_C(  757640439803308252), UINT64_C(14474090585097530747) } },
    { { UINT64_C(11139191600147929635), UINT64_C( 3874607743106779588) },
      { UINT64_C( 7870963881294881648), UINT64_C( 4192999787675110324) },
      { UINT64_C( 3874607743106779588), UINT64_C( 4192999787675110324) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vtrn2q_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_vtrn2q_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[8];
    simde_poly8_t b[8];
    simde_poly8_t r[8];
  } test_vec[] = {
    { { SIMDE_POLY8_C( 15), SIMDE_POLY8_C(216), SIMDE_POLY8_C(  0), SIMDE_POLY8_C( 22), SIMDE_POLY8_C( 58), SIMDE_POLY8_C(248), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(225) },
      { SIMDE_POLY8_C( 12), SIMDE_POLY8_C(184), SIMDE_POLY8_C(182), SIMDE_POLY8_C(163), SIMDE_POLY8_C(  1), SIMDE_POLY8_C(177), SIMDE_POLY8_C( 19), SIMDE_POLY8_C(121) },
      { SIMDE_POLY8_C(216), SIMDE_POLY8_C(184), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(163), SIMDE_POLY8_C(248), SIMDE_POLY8_C(177), SIMDE_POLY8_C(225), SIMDE_POLY8_C(121) } },
    { { SIMDE_POLY8_C( 68), SIMDE_POLY8_C(225), SIMDE_POLY8_C(135), SIMDE_POLY8_C(204), SIMDE_POLY8_C(162), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(186), SIMDE_POLY8_C(237) },
      { SIMDE_POLY8_C( 95), SIMDE_POLY8_C(179), SIMDE_POLY8_C( 10), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(205), SIMDE_POLY8_C( 94), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(220) },
      { SIMDE_POLY8_C(225), SIMDE_POLY8_C(179), SIMDE_POLY8_C(204), SIMDE_POLY8_C( 85), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(237), SIMDE_POLY8_C(220) } },
    { { SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 62), SIMDE_POLY8_C(243), SIMDE_POLY8_C(112), SIMDE_POLY8_C( 54), SIMDE_POLY8_C( 76), SIMDE_POLY8_C( 81), SIMDE_POLY8_C( 66) },
      { SIMDE_POLY8_C(  5), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(229), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(185), SIMDE_POLY8_C(248), SIMDE_POLY8_C(128), SIMDE_POLY8_C(253) },
      { SIMDE_POLY8_C( 62), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(112), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(248), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(253) } },
    { { SIMDE_POLY8_C(218), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(201), SIMDE_POLY8_C(124), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(131), SIMDE_POLY8_C(105), SIMDE_POLY8_C(178) },
      { SIMDE_POLY8_C( 55), SIMDE_POLY8_C(116), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(210), SIMDE_POLY8_C( 70), SIMDE_POLY8_C(224), SIMDE_POLY8_C(  8) },
      { SIMDE_POLY8_C(  7), SIMDE_POLY8_C(116), SIMDE_POLY8_C(124), SIMDE_POLY8_C(  4), SIMDE_POLY8_C(131), SIMDE_POLY8_C( 70), SIMDE_POLY8_C(178), SIMDE_POLY8_C(  8) } },
    { { SIMDE_POLY8_C(132), SIMDE_POLY8_C(211), SIMDE_POLY8_C(120), SIMDE_POLY8_C(187), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(201), SIMDE_POLY8_C(253), SIMDE_POLY8_C( 37) },
      { SIMDE_POLY8_C(208), SIMDE_POLY8_C(227), SIMDE_POLY8_C( 43), SIMDE_POLY8_C(137), SIMDE_POLY8_C(219), SIMDE_POLY8_C(171), SIMDE_POLY8_C(134), SIMDE_POLY8_C(181) },
      { SIMDE_POLY8_C(211), SIMDE_POLY8_C(227), SIMDE_POLY8_C(187), SIMDE_POLY8_C(137), SIMDE_POLY8_C(201), SIMDE_POLY8_C(171), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(181) } },
    { { SIMDE_POLY8_C(179), SIMDE_POLY8_C( 79), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(211), SIMDE_POLY8_C(155), SIMDE_POLY8_C(185), SIMDE_POLY8_C( 10) },
      { SIMDE_POLY8_C( 15), SIMDE_POLY8_C(192), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(225), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(238), SIMDE_POLY8_C(233), SIMDE_POLY8_C(139) },
      { SIMDE_POLY8_C( 79), SIMDE_POLY8_C(192), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(225), SIMDE_POLY8_C(155), SIMDE_POLY8_C(238), SIMDE_POLY8_C( 10), SIMDE_POLY8_C(139) } },
    { { SIMDE_POLY8_C(194), SIMDE_POLY8_C( 97), SIMDE_POLY8_C( 70), SIMDE_POLY8_C(226), SIMDE_POLY8_C( 42), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(251) },
      { SIMDE_POLY8_C( 38), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(132), SIMDE_POLY8_C(  2), SIMDE_POLY8_C(222), SIMDE_POLY8_C( 11), SIMDE_POLY8_C(183), SIMDE_POLY8_C(145) },
      { SIMDE_POLY8_C( 97), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(226), SIMDE_POLY8_C(  2), SIMDE_POLY8_C( 67), SIMDE_POLY8_C( 11), SIMDE_POLY8_C(251), SIMDE_POLY8_C(145) } },
    { { SIMDE_POLY8_C( 90), SIMDE_POLY8_C(233), SIMDE_POLY8_C(151), SIMDE_POLY8_C( 45), SIMDE_POLY8_C(133), SIMDE_POLY8_C( 80), SIMDE_POLY8_C( 55), SIMDE_POLY8_C(148) },
      { SIMDE_POLY8_C( 17), SIMDE_POLY8_C( 69), SIMDE_POLY8_C(118), SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 52), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(162), SIMDE_POLY8_C(246) },
      { SIMDE_POLY8_C(233), SIMDE_POLY8_C( 69), SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 23), SIMDE_POLY8_C( 80), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(148), SIMDE_POLY8_C(246) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x8_t a = simde_vld1_p8(test_vec[i].a);
    simde_poly8x8_t b = simde_vld1_p8(test_vec[i].b);
    simde_poly8x8_t r = simde_vtrn2_p8(a, b);

    simde_test_arm_neon_assert_equal_p8x8(r, simde_vld1_p8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x8_t a = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t b = simde_test_arm_neon_random_p8x8();
    simde_poly8x8_t r = simde_vtrn2_p8(a, b);

    simde_test_arm_neon_write_p8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[4];
    simde_poly16_t b[4];
    simde_poly16_t r[4];
  } test_vec[] = {
    { { SIMDE_POLY16_C( 5340), SIMDE_POLY16_C(40669), SIMDE_POLY16_C(17077), SIMDE_POLY16_C(60369) },
      { SIMDE_POLY16_C( 8272), SIMDE_POLY16_C(45663), SIMDE_POLY16_C(  988), SIMDE_POLY16_C(27971) },
      { SIMDE_POLY16_C(40669), SIMDE_POLY16_C(45663), SIMDE_POLY16_C(60369), SIMDE_POLY16_C(27971) } },
    { { SIMDE_POLY16_C(17106), SIMDE_POLY16_C( 4797), SIMDE_POLY16_C( 3841), SIMDE_POLY16_C(52059) },
      { SIMDE_POLY16_C(56359), SIMDE_POLY16_C(46318), SIMDE_POLY16_C(18079), SIMDE_POLY16_C(31782) },
      { SIMDE_POLY16_C( 4797), SIMDE_POLY16_C(46318), SIMDE_POLY16_C(52059), SIMDE_POLY16_C(31782) } },
    { { SIMDE_POLY16_C(  859), SIMDE_POLY16_C( 4122), SIMDE_POLY16_C(60229), SIMDE_POLY16_C(38651) },
      { SIMDE_POLY16_C(23051), SIMDE_POLY16_C(59464), SIMDE_POLY16_C(35678), SIMDE_POLY16_C(12373) },
      { SIMDE_POLY16_C( 4122), SIMDE_POLY16_C(59464), SIMDE_POLY16_C(38651), SIMDE_POLY16_C(12373) } },
    { { SIMDE_POLY16_C( 5069), SIMDE_POLY16_C(53058), SIMDE_POLY16_C(40482), SIMDE_POLY16_C(18842) },
      { SIMDE_POLY16_C(35194), SIMDE_POLY16_C( 6909), SIMDE_POLY16_C( 9167), SIMDE_POLY16_C(10902) },
      { SIMDE_POLY16_C(53058), SIMDE_POLY16_C( 6909), SIMDE_POLY16_C(18842), SIMDE_POLY16_C(10902) } },
    { { SIMDE_POLY16_C(45094), SIMDE_POLY16_C(27450), SIMDE_POLY16_C(13980), SIMDE_POLY16_C(42753) },
      { SIMDE_POLY16_C(18832), SIMDE_POLY16_C(61071), SIMDE_POLY16_C(58836), SIMDE_POLY16_C(41503) },
      { SIMDE_POLY16_C(27450), SIMDE_POLY16_C(61071), SIMDE_POLY16_C(42753), SIMDE_POLY16_C(41503) } },
    { { SIMDE_POLY16_C(25080), SIMDE_POLY16_C( 6769), SIMDE_POLY16_C( 3071), SIMDE_POLY16_C(31331) },
      { SIMDE_POLY16_C(24724), SIMDE_POLY16_C(25748), SIMDE_POLY16_C(10883), SIMDE_POLY16_C(43406) },
      { SIMDE_POLY16_C( 6769), SIMDE_POLY16_C(25748), SIMDE_POLY16_C(31331), SIMDE_POLY16_C(43406) } },
    { { SIMDE_POLY16_C(51674), SIMDE_POLY16_C(30228), SIMDE_POLY16_C( 5887), SIMDE_POLY16_C(36638) },
      { SIMDE_POLY16_C(44383), SIMDE_POLY16_C(13438), SIMDE_POLY16_C(40338), SIMDE_POLY16_C(35542) },
      { SIMDE_POLY16_C(30228), SIMDE_POLY16_C(13438), SIMDE_POLY16_C(36638), SIMDE_POLY16_C(35542) } },
    { { SIMDE_POLY16_C(18430), SIMDE_POLY16_C(65188), SIMDE_POLY16_C( 1874), SIMDE_POLY16_C(59256) },
      { SIMDE_POLY16_C( 3175), SIMDE_POLY16_C(59979), SIMDE_POLY16_C(55606), SIMDE_POLY16_C( 4243) },
      { SIMDE_POLY16_C(65188), SIMDE_POLY16_C(59979), SIMDE_POLY16_C(59256), SIMDE_POLY16_C( 4243) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x4_t a = simde_vld1_p16(test_vec[i].a);
    simde_poly16x4_t b = simde_vld1_p16(test_vec[i].b);
    simde_poly16x4_t r = simde_vtrn2_p16(a, b);
    simde_test_arm_neon_assert_equal_p16x4(r, simde_vld1_p16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x4_t a = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t b = simde_test_arm_neon_random_p16x4();
    simde_poly16x4_t r = simde_vtrn2_p16(a, b);

    simde_test_arm_neon_write_p16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_p8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly8_t a[16];
    simde_poly8_t b[16];
    simde_poly8_t r[16];
  } test_vec[] = {
    { { SIMDE_POLY8_C( 20), SIMDE_POLY8_C(238), SIMDE_POLY8_C(252), SIMDE_POLY8_C(213), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(233), SIMDE_POLY8_C(216), SIMDE_POLY8_C( 19),
        SIMDE_POLY8_C(139), SIMDE_POLY8_C(224), SIMDE_POLY8_C( 95), SIMDE_POLY8_C( 61), SIMDE_POLY8_C(180), SIMDE_POLY8_C(215), SIMDE_POLY8_C(124), SIMDE_POLY8_C(191) },
      { SIMDE_POLY8_C(  7), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(234), SIMDE_POLY8_C(232), SIMDE_POLY8_C(111), SIMDE_POLY8_C(230), SIMDE_POLY8_C(156), SIMDE_POLY8_C( 66),
        SIMDE_POLY8_C( 82), SIMDE_POLY8_C(  3), SIMDE_POLY8_C(221), SIMDE_POLY8_C(221), SIMDE_POLY8_C(135), SIMDE_POLY8_C(  8), SIMDE_POLY8_C( 89), SIMDE_POLY8_C(155) },
      { SIMDE_POLY8_C(238), SIMDE_POLY8_C(  5), SIMDE_POLY8_C(213), SIMDE_POLY8_C(232), SIMDE_POLY8_C(233), SIMDE_POLY8_C(230), SIMDE_POLY8_C( 19), SIMDE_POLY8_C( 66),
        SIMDE_POLY8_C(224), SIMDE_POLY8_C(  3), SIMDE_POLY8_C( 61), SIMDE_POLY8_C(221), SIMDE_POLY8_C(215), SIMDE_POLY8_C(  8), SIMDE_POLY8_C(191), SIMDE_POLY8_C(155) } },
    { { SIMDE_POLY8_C(247), SIMDE_POLY8_C( 85), SIMDE_POLY8_C(112), SIMDE_POLY8_C( 57), SIMDE_POLY8_C( 62), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 76), SIMDE_POLY8_C(202),
        SIMDE_POLY8_C( 41), SIMDE_POLY8_C(171), SIMDE_POLY8_C(  7), SIMDE_POLY8_C(221), SIMDE_POLY8_C(130), SIMDE_POLY8_C(132), SIMDE_POLY8_C(156), SIMDE_POLY8_C(137) },
      { SIMDE_POLY8_C(137), SIMDE_POLY8_C(135), SIMDE_POLY8_C(113), SIMDE_POLY8_C(249), SIMDE_POLY8_C(109), SIMDE_POLY8_C( 14), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(191),
        SIMDE_POLY8_C( 17), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(157), SIMDE_POLY8_C(152), SIMDE_POLY8_C( 33), SIMDE_POLY8_C(246), SIMDE_POLY8_C( 51), SIMDE_POLY8_C( 24) },
      { SIMDE_POLY8_C( 85), SIMDE_POLY8_C(135), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(249), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 14), SIMDE_POLY8_C(202), SIMDE_POLY8_C(191),
        SIMDE_POLY8_C(171), SIMDE_POLY8_C( 25), SIMDE_POLY8_C(221), SIMDE_POLY8_C(152), SIMDE_POLY8_C(132), SIMDE_POLY8_C(246), SIMDE_POLY8_C(137), SIMDE_POLY8_C( 24) } },
    { { SIMDE_POLY8_C( 75), SIMDE_POLY8_C(163), SIMDE_POLY8_C( 81), SIMDE_POLY8_C(138), SIMDE_POLY8_C(236), SIMDE_POLY8_C(157), SIMDE_POLY8_C( 84), SIMDE_POLY8_C( 22),
        SIMDE_POLY8_C( 72), SIMDE_POLY8_C( 91), SIMDE_POLY8_C(243), SIMDE_POLY8_C(202), SIMDE_POLY8_C(223), SIMDE_POLY8_C(144), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(105) },
      { SIMDE_POLY8_C( 23), SIMDE_POLY8_C(197), SIMDE_POLY8_C( 98), SIMDE_POLY8_C(132), SIMDE_POLY8_C(211), SIMDE_POLY8_C(157), SIMDE_POLY8_C( 67), SIMDE_POLY8_C(228),
        SIMDE_POLY8_C(182), SIMDE_POLY8_C(224), SIMDE_POLY8_C(124), SIMDE_POLY8_C(216), SIMDE_POLY8_C(214), SIMDE_POLY8_C(175), SIMDE_POLY8_C(240), SIMDE_POLY8_C( 34) },
      { SIMDE_POLY8_C(163), SIMDE_POLY8_C(197), SIMDE_POLY8_C(138), SIMDE_POLY8_C(132), SIMDE_POLY8_C(157), SIMDE_POLY8_C(157), SIMDE_POLY8_C( 22), SIMDE_POLY8_C(228),
        SIMDE_POLY8_C( 91), SIMDE_POLY8_C(224), SIMDE_POLY8_C(202), SIMDE_POLY8_C(216), SIMDE_POLY8_C(144), SIMDE_POLY8_C(175), SIMDE_POLY8_C(105), SIMDE_POLY8_C( 34) } },
    { { SIMDE_POLY8_C( 83), SIMDE_POLY8_C( 66), SIMDE_POLY8_C(172), SIMDE_POLY8_C( 63), SIMDE_POLY8_C(223), SIMDE_POLY8_C(  0), SIMDE_POLY8_C( 85), SIMDE_POLY8_C( 40),
        SIMDE_POLY8_C( 91), SIMDE_POLY8_C( 73), SIMDE_POLY8_C(242), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(217), SIMDE_POLY8_C( 70), SIMDE_POLY8_C(164), SIMDE_POLY8_C(240) },
      { SIMDE_POLY8_C( 12), SIMDE_POLY8_C(  6), SIMDE_POLY8_C(116), SIMDE_POLY8_C(223), SIMDE_POLY8_C(163), SIMDE_POLY8_C(183), SIMDE_POLY8_C(196), SIMDE_POLY8_C( 90),
        SIMDE_POLY8_C(152), SIMDE_POLY8_C( 64), SIMDE_POLY8_C( 50), SIMDE_POLY8_C(110), SIMDE_POLY8_C(240), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(144), SIMDE_POLY8_C( 67) },
      { SIMDE_POLY8_C( 66), SIMDE_POLY8_C(  6), SIMDE_POLY8_C( 63), SIMDE_POLY8_C(223), SIMDE_POLY8_C(  0), SIMDE_POLY8_C(183), SIMDE_POLY8_C( 40), SIMDE_POLY8_C( 90),
        SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 64), SIMDE_POLY8_C( 59), SIMDE_POLY8_C(110), SIMDE_POLY8_C( 70), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(240), SIMDE_POLY8_C( 67) } },
    { { SIMDE_POLY8_C(100), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(130), SIMDE_POLY8_C( 68), SIMDE_POLY8_C( 60), SIMDE_POLY8_C(216), SIMDE_POLY8_C(108), SIMDE_POLY8_C(152),
        SIMDE_POLY8_C( 33), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(211), SIMDE_POLY8_C(250), SIMDE_POLY8_C(165), SIMDE_POLY8_C(119), SIMDE_POLY8_C(234), SIMDE_POLY8_C(177) },
      { SIMDE_POLY8_C(125), SIMDE_POLY8_C( 94), SIMDE_POLY8_C(144), SIMDE_POLY8_C( 32), SIMDE_POLY8_C( 21), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(122), SIMDE_POLY8_C(173),
        SIMDE_POLY8_C(149), SIMDE_POLY8_C(172), SIMDE_POLY8_C( 28), SIMDE_POLY8_C(133), SIMDE_POLY8_C(207), SIMDE_POLY8_C(172), SIMDE_POLY8_C(200), SIMDE_POLY8_C( 51) },
      { SIMDE_POLY8_C( 60), SIMDE_POLY8_C( 94), SIMDE_POLY8_C( 68), SIMDE_POLY8_C( 32), SIMDE_POLY8_C(216), SIMDE_POLY8_C( 84), SIMDE_POLY8_C(152), SIMDE_POLY8_C(173),
        SIMDE_POLY8_C( 94), SIMDE_POLY8_C(172), SIMDE_POLY8_C(250), SIMDE_POLY8_C(133), SIMDE_POLY8_C(119), SIMDE_POLY8_C(172), SIMDE_POLY8_C(177), SIMDE_POLY8_C( 51) } },
    { { SIMDE_POLY8_C(233), SIMDE_POLY8_C( 74), SIMDE_POLY8_C(119), SIMDE_POLY8_C( 37), SIMDE_POLY8_C( 34), SIMDE_POLY8_C(227), SIMDE_POLY8_C(189), SIMDE_POLY8_C( 67),
        SIMDE_POLY8_C( 66), SIMDE_POLY8_C(144), SIMDE_POLY8_C( 61), SIMDE_POLY8_C(231), SIMDE_POLY8_C(  7), SIMDE_POLY8_C( 39), SIMDE_POLY8_C(152), SIMDE_POLY8_C(132) },
      { SIMDE_POLY8_C(133), SIMDE_POLY8_C( 40), SIMDE_POLY8_C(165), SIMDE_POLY8_C(155), SIMDE_POLY8_C(125), SIMDE_POLY8_C( 31), SIMDE_POLY8_C( 72), SIMDE_POLY8_C( 18),
        SIMDE_POLY8_C(204), SIMDE_POLY8_C(100), SIMDE_POLY8_C(151), SIMDE_POLY8_C(155), SIMDE_POLY8_C( 17), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(206), SIMDE_POLY8_C(250) },
      { SIMDE_POLY8_C( 74), SIMDE_POLY8_C( 40), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(155), SIMDE_POLY8_C(227), SIMDE_POLY8_C( 31), SIMDE_POLY8_C( 67), SIMDE_POLY8_C( 18),
        SIMDE_POLY8_C(144), SIMDE_POLY8_C(100), SIMDE_POLY8_C(231), SIMDE_POLY8_C(155), SIMDE_POLY8_C( 39), SIMDE_POLY8_C( 95), SIMDE_POLY8_C(132), SIMDE_POLY8_C(250) } },
    { { SIMDE_POLY8_C(169), SIMDE_POLY8_C( 70), SIMDE_POLY8_C( 31), SIMDE_POLY8_C(204), SIMDE_POLY8_C( 41), SIMDE_POLY8_C(221), SIMDE_POLY8_C( 15), SIMDE_POLY8_C(107),
        SIMDE_POLY8_C(109), SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 82), SIMDE_POLY8_C(117), SIMDE_POLY8_C(116), SIMDE_POLY8_C(234), SIMDE_POLY8_C(249), SIMDE_POLY8_C(250) },
      { SIMDE_POLY8_C( 19), SIMDE_POLY8_C(158), SIMDE_POLY8_C(149), SIMDE_POLY8_C(144), SIMDE_POLY8_C(190), SIMDE_POLY8_C(221), SIMDE_POLY8_C(162), SIMDE_POLY8_C(138),
        SIMDE_POLY8_C( 66), SIMDE_POLY8_C( 57), SIMDE_POLY8_C( 37), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(152), SIMDE_POLY8_C(243), SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 65) },
      { SIMDE_POLY8_C( 70), SIMDE_POLY8_C(158), SIMDE_POLY8_C(204), SIMDE_POLY8_C(144), SIMDE_POLY8_C(221), SIMDE_POLY8_C(221), SIMDE_POLY8_C(107), SIMDE_POLY8_C(138),
        SIMDE_POLY8_C( 77), SIMDE_POLY8_C( 57), SIMDE_POLY8_C(117), SIMDE_POLY8_C( 83), SIMDE_POLY8_C(234), SIMDE_POLY8_C(243), SIMDE_POLY8_C(250), SIMDE_POLY8_C( 65) } },
    { { SIMDE_POLY8_C( 57), SIMDE_POLY8_C(108), SIMDE_POLY8_C( 13), SIMDE_POLY8_C( 99), SIMDE_POLY8_C( 73), SIMDE_POLY8_C( 29), SIMDE_POLY8_C(206), SIMDE_POLY8_C(183),
        SIMDE_POLY8_C(106), SIMDE_POLY8_C( 33), SIMDE_POLY8_C( 44), SIMDE_POLY8_C(222), SIMDE_POLY8_C( 11), SIMDE_POLY8_C( 37), SIMDE_POLY8_C(216), SIMDE_POLY8_C( 30) },
      { SIMDE_POLY8_C(196), SIMDE_POLY8_C(109), SIMDE_POLY8_C(174), SIMDE_POLY8_C(130), SIMDE_POLY8_C( 75), SIMDE_POLY8_C( 80), SIMDE_POLY8_C( 12), SIMDE_POLY8_C(141),
        SIMDE_POLY8_C(137), SIMDE_POLY8_C( 49), SIMDE_POLY8_C(224), SIMDE_POLY8_C( 33), SIMDE_POLY8_C( 36), SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 99), SIMDE_POLY8_C( 94) },
      { SIMDE_POLY8_C(108), SIMDE_POLY8_C(109), SIMDE_POLY8_C( 99), SIMDE_POLY8_C(130), SIMDE_POLY8_C( 29), SIMDE_POLY8_C( 80), SIMDE_POLY8_C(183), SIMDE_POLY8_C(141),
        SIMDE_POLY8_C( 33), SIMDE_POLY8_C( 49), SIMDE_POLY8_C(222), SIMDE_POLY8_C( 33), SIMDE_POLY8_C( 37), SIMDE_POLY8_C( 45), SIMDE_POLY8_C( 30), SIMDE_POLY8_C( 94) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    simde_poly8x16_t b = simde_vld1q_p8(test_vec[i].b);
    simde_poly8x16_t r = simde_vtrn2q_p8(a, b);

    simde_test_arm_neon_assert_equal_p8x16(r, simde_vld1q_p8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x16_t a = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t b = simde_test_arm_neon_random_p8x16();
    simde_poly8x16_t r = simde_vtrn2q_p8(a, b);

    simde_test_arm_neon_write_p8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_p16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly16_t a[8];
    simde_poly16_t b[8];
    simde_poly16_t r[8];
  } test_vec[] = {
    { { SIMDE_POLY16_C(  871), SIMDE_POLY16_C(60974), SIMDE_POLY16_C(46339), SIMDE_POLY16_C(41413), SIMDE_POLY16_C(48049), SIMDE_POLY16_C(26805), SIMDE_POLY16_C( 6238), SIMDE_POLY16_C(17076) },
      { SIMDE_POLY16_C(16789), SIMDE_POLY16_C(31129), SIMDE_POLY16_C(27483), SIMDE_POLY16_C(21460), SIMDE_POLY16_C(34444), SIMDE_POLY16_C(40210), SIMDE_POLY16_C(60228), SIMDE_POLY16_C(43796) },
      { SIMDE_POLY16_C(60974), SIMDE_POLY16_C(31129), SIMDE_POLY16_C(41413), SIMDE_POLY16_C(21460), SIMDE_POLY16_C(26805), SIMDE_POLY16_C(40210), SIMDE_POLY16_C(17076), SIMDE_POLY16_C(43796) } },
    { { SIMDE_POLY16_C(17391), SIMDE_POLY16_C(62105), SIMDE_POLY16_C(24568), SIMDE_POLY16_C(43411), SIMDE_POLY16_C(18714), SIMDE_POLY16_C(30993), SIMDE_POLY16_C(50529), SIMDE_POLY16_C(63163) },
      { SIMDE_POLY16_C(21510), SIMDE_POLY16_C(24944), SIMDE_POLY16_C(17600), SIMDE_POLY16_C(19636), SIMDE_POLY16_C(50890), SIMDE_POLY16_C( 3817), SIMDE_POLY16_C(64945), SIMDE_POLY16_C(41145) },
      { SIMDE_POLY16_C(62105), SIMDE_POLY16_C(24944), SIMDE_POLY16_C(43411), SIMDE_POLY16_C(19636), SIMDE_POLY16_C(30993), SIMDE_POLY16_C( 3817), SIMDE_POLY16_C(63163), SIMDE_POLY16_C(41145) } },
    { { SIMDE_POLY16_C(21312), SIMDE_POLY16_C(14483), SIMDE_POLY16_C( 9906), SIMDE_POLY16_C(52449), SIMDE_POLY16_C(62063), SIMDE_POLY16_C(53317), SIMDE_POLY16_C(  439), SIMDE_POLY16_C(48583) },
      { SIMDE_POLY16_C(14165), SIMDE_POLY16_C( 5406), SIMDE_POLY16_C(53883), SIMDE_POLY16_C(17761), SIMDE_POLY16_C(19096), SIMDE_POLY16_C(19028), SIMDE_POLY16_C( 3400), SIMDE_POLY16_C(35050) },
      { SIMDE_POLY16_C(14483), SIMDE_POLY16_C( 5406), SIMDE_POLY16_C(52449), SIMDE_POLY16_C(17761), SIMDE_POLY16_C(53317), SIMDE_POLY16_C(19028), SIMDE_POLY16_C(48583), SIMDE_POLY16_C(35050) } },
    { { SIMDE_POLY16_C(32096), SIMDE_POLY16_C( 4801), SIMDE_POLY16_C(41636), SIMDE_POLY16_C( 5087), SIMDE_POLY16_C( 9365), SIMDE_POLY16_C(19684), SIMDE_POLY16_C(43813), SIMDE_POLY16_C(31498) },
      { SIMDE_POLY16_C(10466), SIMDE_POLY16_C(23952), SIMDE_POLY16_C(62203), SIMDE_POLY16_C(37794), SIMDE_POLY16_C(63036), SIMDE_POLY16_C(34013), SIMDE_POLY16_C(51204), SIMDE_POLY16_C(25613) },
      { SIMDE_POLY16_C( 4801), SIMDE_POLY16_C(23952), SIMDE_POLY16_C( 5087), SIMDE_POLY16_C(37794), SIMDE_POLY16_C(19684), SIMDE_POLY16_C(34013), SIMDE_POLY16_C(31498), SIMDE_POLY16_C(25613) } },
    { { SIMDE_POLY16_C(52805), SIMDE_POLY16_C(59767), SIMDE_POLY16_C(22128), SIMDE_POLY16_C( 1533), SIMDE_POLY16_C(57722), SIMDE_POLY16_C(41042), SIMDE_POLY16_C(23692), SIMDE_POLY16_C(28187) },
      { SIMDE_POLY16_C(43908), SIMDE_POLY16_C(32715), SIMDE_POLY16_C(28061), SIMDE_POLY16_C(55827), SIMDE_POLY16_C(61540), SIMDE_POLY16_C(26718), SIMDE_POLY16_C(27576), SIMDE_POLY16_C(65228) },
      { SIMDE_POLY16_C(59767), SIMDE_POLY16_C(32715), SIMDE_POLY16_C( 1533), SIMDE_POLY16_C(55827), SIMDE_POLY16_C(41042), SIMDE_POLY16_C(26718), SIMDE_POLY16_C(28187), SIMDE_POLY16_C(65228) } },
    { { SIMDE_POLY16_C(17209), SIMDE_POLY16_C(43751), SIMDE_POLY16_C(58521), SIMDE_POLY16_C( 5295), SIMDE_POLY16_C(  453), SIMDE_POLY16_C(20916), SIMDE_POLY16_C(53085), SIMDE_POLY16_C(58047) },
      { SIMDE_POLY16_C(35450), SIMDE_POLY16_C( 6241), SIMDE_POLY16_C(29944), SIMDE_POLY16_C(23794), SIMDE_POLY16_C(20581), SIMDE_POLY16_C( 7620), SIMDE_POLY16_C(37052), SIMDE_POLY16_C(62747) },
      { SIMDE_POLY16_C(43751), SIMDE_POLY16_C( 6241), SIMDE_POLY16_C( 5295), SIMDE_POLY16_C(23794), SIMDE_POLY16_C(20916), SIMDE_POLY16_C( 7620), SIMDE_POLY16_C(58047), SIMDE_POLY16_C(62747) } },
    { { SIMDE_POLY16_C(  980), SIMDE_POLY16_C(28063), SIMDE_POLY16_C(20455), SIMDE_POLY16_C(44417), SIMDE_POLY16_C(13648), SIMDE_POLY16_C(44798), SIMDE_POLY16_C(48644), SIMDE_POLY16_C(32656) },
      { SIMDE_POLY16_C(61768), SIMDE_POLY16_C(16535), SIMDE_POLY16_C(35174), SIMDE_POLY16_C(52124), SIMDE_POLY16_C(24793), SIMDE_POLY16_C(38376), SIMDE_POLY16_C( 1265), SIMDE_POLY16_C(50571) },
      { SIMDE_POLY16_C(28063), SIMDE_POLY16_C(16535), SIMDE_POLY16_C(44417), SIMDE_POLY16_C(52124), SIMDE_POLY16_C(44798), SIMDE_POLY16_C(38376), SIMDE_POLY16_C(32656), SIMDE_POLY16_C(50571) } },
    { { SIMDE_POLY16_C(10759), SIMDE_POLY16_C(60978), SIMDE_POLY16_C(46201), SIMDE_POLY16_C(51867), SIMDE_POLY16_C(39657), SIMDE_POLY16_C(61048), SIMDE_POLY16_C( 2136), SIMDE_POLY16_C(41069) },
      { SIMDE_POLY16_C( 1273), SIMDE_POLY16_C(24545), SIMDE_POLY16_C(32141), SIMDE_POLY16_C(26154), SIMDE_POLY16_C( 5086), SIMDE_POLY16_C(53244), SIMDE_POLY16_C(34583), SIMDE_POLY16_C( 7828) },
      { SIMDE_POLY16_C(60978), SIMDE_POLY16_C(24545), SIMDE_POLY16_C(51867), SIMDE_POLY16_C(26154), SIMDE_POLY16_C(61048), SIMDE_POLY16_C(53244), SIMDE_POLY16_C(41069), SIMDE_POLY16_C( 7828) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    simde_poly16x8_t b = simde_vld1q_p16(test_vec[i].b);
    simde_poly16x8_t r = simde_vtrn2q_p16(a, b);
    simde_test_arm_neon_assert_equal_p16x8(r, simde_vld1q_p16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x8_t a = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t b = simde_test_arm_neon_random_p16x8();
    simde_poly16x8_t r = simde_vtrn2q_p16(a, b);

    simde_test_arm_neon_write_p16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtrn2q_p64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_poly64_t a[2];
    simde_poly64_t b[2];
    simde_poly64_t r[2];
  } test_vec[] = {
    { { SIMDE_POLY64_C( 6945319424494524748), SIMDE_POLY64_C(16610643692567852571) },
      { SIMDE_POLY64_C( 6955632144508350698), SIMDE_POLY64_C( 8616304367102141145) },
      { SIMDE_POLY64_C(16610643692567852571), SIMDE_POLY64_C( 8616304367102141145) } },
    { { SIMDE_POLY64_C(  483247366258044957), SIMDE_POLY64_C(10529975198939663308) },
      { SIMDE_POLY64_C( 1036481247570548332), SIMDE_POLY64_C( 9734062660554794868) },
      { SIMDE_POLY64_C(10529975198939663308), SIMDE_POLY64_C( 9734062660554794868) } },
    { { SIMDE_POLY64_C( 3276246002131765894), SIMDE_POLY64_C( 6310820620303658843) },
      { SIMDE_POLY64_C( 2711935197491257183), SIMDE_POLY64_C( 4743376430044571105) },
      { SIMDE_POLY64_C( 6310820620303658843), SIMDE_POLY64_C( 4743376430044571105) } },
    { { SIMDE_POLY64_C(11165594730051579749), SIMDE_POLY64_C( 4925304002160909336) },
      { SIMDE_POLY64_C( 5649618867251098256), SIMDE_POLY64_C( 7843984154933472479) },
      { SIMDE_POLY64_C( 4925304002160909336), SIMDE_POLY64_C( 7843984154933472479) } },
    { { SIMDE_POLY64_C(14913150880268389661), SIMDE_POLY64_C( 6101299713457361539) },
      { SIMDE_POLY64_C(16112188414821303774), SIMDE_POLY64_C(13807286187674121257) },
      { SIMDE_POLY64_C( 6101299713457361539), SIMDE_POLY64_C(13807286187674121257) } },
    { { SIMDE_POLY64_C( 8820038150351737058), SIMDE_POLY64_C( 4808593589038889379) },
      { SIMDE_POLY64_C( 8715071445204291859), SIMDE_POLY64_C(11798381818995567451) },
      { SIMDE_POLY64_C( 4808593589038889379), SIMDE_POLY64_C(11798381818995567451) } },
    { { SIMDE_POLY64_C(10053903435184264981), SIMDE_POLY64_C(  757640439803308252) },
      { SIMDE_POLY64_C(10647933628473741822), SIMDE_POLY64_C(14474090585097530747) },
      { SIMDE_POLY64_C(  757640439803308252), SIMDE_POLY64_C(14474090585097530747) } },
    { { SIMDE_POLY64_C(11139191600147929635), SIMDE_POLY64_C( 3874607743106779588) },
      { SIMDE_POLY64_C( 7870963881294881648), SIMDE_POLY64_C( 4192999787675110324) },
      { SIMDE_POLY64_C( 3874607743106779588), SIMDE_POLY64_C( 4192999787675110324) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly64x2_t a = simde_vld1q_p64(test_vec[i].a);
    simde_poly64x2_t b = simde_vld1q_p64(test_vec[i].b);
    simde_poly64x2_t r = simde_vtrn2q_p64(a, b);
    simde_test_arm_neon_assert_equal_p64x2(r, simde_vld1q_p64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x2_t a = simde_test_arm_neon_random_p64x2();
    simde_poly64x2_t b = simde_test_arm_neon_random_p64x2();
    simde_poly64x2_t r = simde_vtrn2q_p64(a, b);

    simde_test_arm_neon_write_p64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_p64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_p8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_p16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtrn2q_p64)
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
