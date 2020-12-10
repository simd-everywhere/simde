#define SIMDE_TEST_ARM_NEON_INSN qabs

#include "test-neon.h"

#include "../../../simde/arm/neon/qabs.h"
#include "../../../simde/arm/neon/set_lane.h"

static int
test_simde_vqabsb_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t r;
  } test_vec[] = {
    {      INT8_MIN,
           INT8_MAX },
    {  INT8_C(  23),
       INT8_C(  23) },
    {  INT8_C(  79),
       INT8_C(  79) },
    { -INT8_C(  44),
       INT8_C(  44) },
    {  INT8_C(  56),
       INT8_C(  56) },
    {  INT8_C(   3),
       INT8_C(   3) },
    { -INT8_C(  28),
       INT8_C(  28) },
    {  INT8_C(  10),
       INT8_C(  10) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r = simde_vqabsb_s8(test_vec[i].a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a = (i == 0) ? INT8_MIN : simde_test_codegen_random_i8();
    int8_t r = simde_vqabsb_s8(a);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabsh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t r;
  } test_vec[] = {
    {       INT16_MIN,
            INT16_MAX },
    { -INT16_C( 19836),
       INT16_C( 19836) },
    { -INT16_C( 11176),
       INT16_C( 11176) },
    { -INT16_C(  6823),
       INT16_C(  6823) },
    {  INT16_C(  3362),
       INT16_C(  3362) },
    {  INT16_C( 23735),
       INT16_C( 23735) },
    {  INT16_C( 12384),
       INT16_C( 12384) },
    {  INT16_C( 28164),
       INT16_C( 28164) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r = simde_vqabsh_s16(test_vec[i].a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = (i == 0) ? INT16_MIN : simde_test_codegen_random_i16();
    int16_t r = simde_vqabsh_s16(a);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabss_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t r;
  } test_vec[] = {
    {            INT32_MIN,
                 INT32_MAX },
    { -INT32_C(  1790689467),
       INT32_C(  1790689467) },
    { -INT32_C(  1403327490),
       INT32_C(  1403327490) },
    { -INT32_C(  2050787531),
       INT32_C(  2050787531) },
    {  INT32_C(   814283596),
       INT32_C(   814283596) },
    {  INT32_C(  1591872774),
       INT32_C(  1591872774) },
    {  INT32_C(    54738145),
       INT32_C(    54738145) },
    { -INT32_C(  1453327799),
       INT32_C(  1453327799) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_vqabss_s32(test_vec[i].a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = (i == 0) ? INT32_MIN : simde_test_codegen_random_i32();
    int32_t r = simde_vqabss_s32(a);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabsd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t r;
  } test_vec[] = {
    {                     INT64_MIN,
                          INT64_MAX },
    { -INT64_C( 6843680731007786197),
       INT64_C( 6843680731007786197) },
    {  INT64_C( 2522315783993647175),
       INT64_C( 2522315783993647175) },
    {  INT64_C( 8678496504418437644),
       INT64_C( 8678496504418437644) },
    { -INT64_C( 2853634349142920334),
       INT64_C( 2853634349142920334) },
    {  INT64_C( 2342241078398778685),
       INT64_C( 2342241078398778685) },
    { -INT64_C( 1537241644215185745),
       INT64_C( 1537241644215185745) },
    { -INT64_C( 6397525771841372632),
       INT64_C( 6397525771841372632) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vqabsd_s64(test_vec[i].a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = (i == 0) ? INT64_MIN : simde_test_codegen_random_i64();
    int64_t r = simde_vqabsd_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabs_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { {      INT8_MIN, -INT8_C(  92), -INT8_C(  69), -INT8_C(  75),  INT8_C(  60), -INT8_C( 103),  INT8_C(  78),  INT8_C(  10) },
      {      INT8_MAX,  INT8_C(  92),  INT8_C(  69),  INT8_C(  75),  INT8_C(  60),  INT8_C( 103),  INT8_C(  78),  INT8_C(  10) } },
    { { -INT8_C(  51),  INT8_C(  25),  INT8_C(  31), -INT8_C( 120),  INT8_C( 122),  INT8_C(  11), -INT8_C( 102), -INT8_C(  14) },
      {  INT8_C(  51),  INT8_C(  25),  INT8_C(  31),  INT8_C( 120),  INT8_C( 122),  INT8_C(  11),  INT8_C( 102),  INT8_C(  14) } },
    { { -INT8_C( 110), -INT8_C( 109), -INT8_C( 104),  INT8_C(  52), -INT8_C(  24),  INT8_C( 103), -INT8_C(   7),  INT8_C(  81) },
      {  INT8_C( 110),  INT8_C( 109),  INT8_C( 104),  INT8_C(  52),  INT8_C(  24),  INT8_C( 103),  INT8_C(   7),  INT8_C(  81) } },
    { { -INT8_C(  61), -INT8_C(  63),  INT8_C(  61),  INT8_C(  25),  INT8_C( 125), -INT8_C(   8), -INT8_C(  21), -INT8_C(  58) },
      {  INT8_C(  61),  INT8_C(  63),  INT8_C(  61),  INT8_C(  25),  INT8_C( 125),  INT8_C(   8),  INT8_C(  21),  INT8_C(  58) } },
    { { -INT8_C( 100), -INT8_C(  90),  INT8_C( 123), -INT8_C(  39),  INT8_C(  64), -INT8_C(  55), -INT8_C(  29),  INT8_C(  13) },
      {  INT8_C( 100),  INT8_C(  90),  INT8_C( 123),  INT8_C(  39),  INT8_C(  64),  INT8_C(  55),  INT8_C(  29),  INT8_C(  13) } },
    { { -INT8_C(  29),  INT8_C(   2), -INT8_C( 107),  INT8_C(  93),  INT8_C(  14),  INT8_C(  48),  INT8_C(  80), -INT8_C(  96) },
      {  INT8_C(  29),  INT8_C(   2),  INT8_C( 107),  INT8_C(  93),  INT8_C(  14),  INT8_C(  48),  INT8_C(  80),  INT8_C(  96) } },
    { { -INT8_C(  61), -INT8_C(  24), -INT8_C(  44), -INT8_C(  85),  INT8_C(  79), -INT8_C(  51), -INT8_C(   4),  INT8_C(  19) },
      {  INT8_C(  61),  INT8_C(  24),  INT8_C(  44),  INT8_C(  85),  INT8_C(  79),  INT8_C(  51),  INT8_C(   4),  INT8_C(  19) } },
    { { -INT8_C( 114),  INT8_C(  57),  INT8_C(  44),  INT8_C(  11),  INT8_C(  49),  INT8_C(  24), -INT8_C(  46), -INT8_C(  50) },
      {  INT8_C( 114),  INT8_C(  57),  INT8_C(  44),  INT8_C(  11),  INT8_C(  49),  INT8_C(  24),  INT8_C(  46),  INT8_C(  50) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vqabs_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    if (i == 0)
      a = simde_vset_lane_s8(INT8_MIN, a, 0);
    simde_int8x8_t r = simde_vqabs_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabs_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { {       INT16_MIN, -INT16_C( 24953), -INT16_C(   302),  INT16_C(  7435) },
      {       INT16_MAX,  INT16_C( 24953),  INT16_C(   302),  INT16_C(  7435) } },
    { {  INT16_C(  9719),  INT16_C(  8963), -INT16_C( 16749),  INT16_C(  8624) },
      {  INT16_C(  9719),  INT16_C(  8963),  INT16_C( 16749),  INT16_C(  8624) } },
    { {  INT16_C(  7660), -INT16_C( 17022), -INT16_C( 14157),  INT16_C( 16231) },
      {  INT16_C(  7660),  INT16_C( 17022),  INT16_C( 14157),  INT16_C( 16231) } },
    { {  INT16_C(  2029), -INT16_C( 15106), -INT16_C(  5141), -INT16_C( 16369) },
      {  INT16_C(  2029),  INT16_C( 15106),  INT16_C(  5141),  INT16_C( 16369) } },
    { { -INT16_C( 26992),  INT16_C( 25182),  INT16_C( 27028), -INT16_C( 29825) },
      {  INT16_C( 26992),  INT16_C( 25182),  INT16_C( 27028),  INT16_C( 29825) } },
    { { -INT16_C( 31857),  INT16_C(  8879),  INT16_C( 24385),  INT16_C( 11587) },
      {  INT16_C( 31857),  INT16_C(  8879),  INT16_C( 24385),  INT16_C( 11587) } },
    { { -INT16_C( 14979),  INT16_C( 12522),  INT16_C( 21134),  INT16_C( 31599) },
      {  INT16_C( 14979),  INT16_C( 12522),  INT16_C( 21134),  INT16_C( 31599) } },
    { {  INT16_C( 27993),  INT16_C( 17471),  INT16_C( 20312), -INT16_C(  5884) },
      {  INT16_C( 27993),  INT16_C( 17471),  INT16_C( 20312),  INT16_C(  5884) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vqabs_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    if (i == 0)
      a = simde_vset_lane_s16(INT16_MIN, a, 0);
    simde_int16x4_t r = simde_vqabs_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabs_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { {            INT32_MIN,  INT32_C(  1527106508) },
      {            INT32_MAX,  INT32_C(  1527106508) } },
    { { -INT32_C(  1887587250), -INT32_C(  1849900780) },
      {  INT32_C(  1887587250),  INT32_C(  1849900780) } },
    { {  INT32_C(   348235654),  INT32_C(  1385116153) },
      {  INT32_C(   348235654),  INT32_C(  1385116153) } },
    { { -INT32_C(   141111394),  INT32_C(    65051166) },
      {  INT32_C(   141111394),  INT32_C(    65051166) } },
    { { -INT32_C(   897766403),  INT32_C(  1143309302) },
      {  INT32_C(   897766403),  INT32_C(  1143309302) } },
    { {  INT32_C(  1272161079), -INT32_C(   354643868) },
      {  INT32_C(  1272161079),  INT32_C(   354643868) } },
    { {  INT32_C(   822058551),  INT32_C(  1837272783) },
      {  INT32_C(   822058551),  INT32_C(  1837272783) } },
    { {  INT32_C(  2070157405), -INT32_C(  1333836622) },
      {  INT32_C(  2070157405),  INT32_C(  1333836622) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t r = simde_vqabs_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    if (i == 0)
      a = simde_vset_lane_s32(INT32_MIN, a, 0);
    simde_int32x2_t r = simde_vqabs_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabs_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t r[1];
  } test_vec[] = {
    { {                     INT64_MIN },
      {                     INT64_MAX } },
    { {  INT64_C( 5013033114247790146) },
      {  INT64_C( 5013033114247790146) } },
    { {  INT64_C( 8987486240898388093) },
      {  INT64_C( 8987486240898388093) } },
    { { -INT64_C( 3282431011849822705) },
      {  INT64_C( 3282431011849822705) } },
    { { -INT64_C( 3555059141116826509) },
      {  INT64_C( 3555059141116826509) } },
    { {  INT64_C(  627695294526827618) },
      {  INT64_C(  627695294526827618) } },
    { {  INT64_C( 3688462541816867989) },
      {  INT64_C( 3688462541816867989) } },
    { {  INT64_C( 1252114627109922603) },
      {  INT64_C( 1252114627109922603) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t r = simde_vqabs_s64(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    if (i == 0)
      a = simde_vset_lane_s64(INT64_MIN, a, 0);
    simde_int64x1_t r = simde_vqabs_s64(a);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabsq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r[16];
  } test_vec[] = {
    { {      INT8_MIN, -INT8_C( 103),  INT8_C(   3), -INT8_C(  34),  INT8_C( 125), -INT8_C(  83), -INT8_C(  84), -INT8_C(  32),
         INT8_C(  89),  INT8_C(  33),  INT8_C(  81), -INT8_C(  28),  INT8_C(  38),  INT8_C(   7), -INT8_C(  20), -INT8_C(  68) },
      {      INT8_MAX,  INT8_C( 103),  INT8_C(   3),  INT8_C(  34),  INT8_C( 125),  INT8_C(  83),  INT8_C(  84),  INT8_C(  32),
         INT8_C(  89),  INT8_C(  33),  INT8_C(  81),  INT8_C(  28),  INT8_C(  38),  INT8_C(   7),  INT8_C(  20),  INT8_C(  68) } },
    { {  INT8_C(  51),  INT8_C(  64),  INT8_C( 112),  INT8_C(  87),  INT8_C(  77), -INT8_C(  96), -INT8_C( 118),  INT8_C( 121),
        -INT8_C(  57),      INT8_MAX,  INT8_C(   7),  INT8_C( 101), -INT8_C(  26),  INT8_C( 103),  INT8_C( 118),  INT8_C(  57) },
      {  INT8_C(  51),  INT8_C(  64),  INT8_C( 112),  INT8_C(  87),  INT8_C(  77),  INT8_C(  96),  INT8_C( 118),  INT8_C( 121),
         INT8_C(  57),      INT8_MAX,  INT8_C(   7),  INT8_C( 101),  INT8_C(  26),  INT8_C( 103),  INT8_C( 118),  INT8_C(  57) } },
    { {  INT8_C(   1),  INT8_C( 122),  INT8_C(  23),  INT8_C( 126),  INT8_C(  39), -INT8_C(  60),  INT8_C(  94),      INT8_MIN,
        -INT8_C(  27), -INT8_C(  81),  INT8_C( 100),  INT8_C(  11), -INT8_C(  73),  INT8_C(  80), -INT8_C(  57), -INT8_C(  22) },
      {  INT8_C(   1),  INT8_C( 122),  INT8_C(  23),  INT8_C( 126),  INT8_C(  39),  INT8_C(  60),  INT8_C(  94),      INT8_MAX,
         INT8_C(  27),  INT8_C(  81),  INT8_C( 100),  INT8_C(  11),  INT8_C(  73),  INT8_C(  80),  INT8_C(  57),  INT8_C(  22) } },
    { { -INT8_C( 112),  INT8_C(  55),  INT8_C(  65), -INT8_C(  35), -INT8_C(  41), -INT8_C(  53),  INT8_C(  86), -INT8_C(  97),
         INT8_C(  74),  INT8_C(  93),  INT8_C(   4),  INT8_C(  48), -INT8_C(  59),  INT8_C( 123),  INT8_C( 105), -INT8_C(  58) },
      {  INT8_C( 112),  INT8_C(  55),  INT8_C(  65),  INT8_C(  35),  INT8_C(  41),  INT8_C(  53),  INT8_C(  86),  INT8_C(  97),
         INT8_C(  74),  INT8_C(  93),  INT8_C(   4),  INT8_C(  48),  INT8_C(  59),  INT8_C( 123),  INT8_C( 105),  INT8_C(  58) } },
    { { -INT8_C(  11), -INT8_C( 127),  INT8_C(  68),  INT8_C(  28),  INT8_C(  69), -INT8_C(  93), -INT8_C( 100),  INT8_C(  42),
         INT8_C(  82),  INT8_C(   0),  INT8_C(  53),  INT8_C(   9),  INT8_C(  80), -INT8_C(   3), -INT8_C(  12), -INT8_C(  32) },
      {  INT8_C(  11),      INT8_MAX,  INT8_C(  68),  INT8_C(  28),  INT8_C(  69),  INT8_C(  93),  INT8_C( 100),  INT8_C(  42),
         INT8_C(  82),  INT8_C(   0),  INT8_C(  53),  INT8_C(   9),  INT8_C(  80),  INT8_C(   3),  INT8_C(  12),  INT8_C(  32) } },
    { {  INT8_C(  52),  INT8_C(  53), -INT8_C(  67),  INT8_C(  12),  INT8_C(   1),  INT8_C(  20), -INT8_C(  85),  INT8_C(  75),
         INT8_C( 113), -INT8_C(  81),  INT8_C( 124),  INT8_C(  54),  INT8_C(  42), -INT8_C(  27), -INT8_C(   4),  INT8_C(  31) },
      {  INT8_C(  52),  INT8_C(  53),  INT8_C(  67),  INT8_C(  12),  INT8_C(   1),  INT8_C(  20),  INT8_C(  85),  INT8_C(  75),
         INT8_C( 113),  INT8_C(  81),  INT8_C( 124),  INT8_C(  54),  INT8_C(  42),  INT8_C(  27),  INT8_C(   4),  INT8_C(  31) } },
    { {  INT8_C( 102),  INT8_C(  65),  INT8_C(  59), -INT8_C(  85), -INT8_C(  28), -INT8_C(  41), -INT8_C(  43),  INT8_C(  54),
        -INT8_C(  41),  INT8_C(  11),  INT8_C(  64),  INT8_C(  39),  INT8_C(   8),  INT8_C(  52),  INT8_C(   7),  INT8_C(  60) },
      {  INT8_C( 102),  INT8_C(  65),  INT8_C(  59),  INT8_C(  85),  INT8_C(  28),  INT8_C(  41),  INT8_C(  43),  INT8_C(  54),
         INT8_C(  41),  INT8_C(  11),  INT8_C(  64),  INT8_C(  39),  INT8_C(   8),  INT8_C(  52),  INT8_C(   7),  INT8_C(  60) } },
    { {  INT8_C( 105), -INT8_C(  59),  INT8_C(  72),  INT8_C( 106), -INT8_C(  39), -INT8_C(  13), -INT8_C(  74),  INT8_C(  74),
        -INT8_C(  93),  INT8_C(  50), -INT8_C( 127), -INT8_C(  51),  INT8_C(  23),  INT8_C( 125), -INT8_C(  19),  INT8_C( 126) },
      {  INT8_C( 105),  INT8_C(  59),  INT8_C(  72),  INT8_C( 106),  INT8_C(  39),  INT8_C(  13),  INT8_C(  74),  INT8_C(  74),
         INT8_C(  93),  INT8_C(  50),      INT8_MAX,  INT8_C(  51),  INT8_C(  23),  INT8_C( 125),  INT8_C(  19),  INT8_C( 126) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t r = simde_vqabsq_s8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    if (i == 0)
      a = simde_vsetq_lane_s8(INT8_MIN, a, 0);
    simde_int8x16_t r = simde_vqabsq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabsq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { {       INT16_MIN, -INT16_C( 24023), -INT16_C(   256), -INT16_C( 10279),  INT16_C(  6410),  INT16_C(  4863),  INT16_C(  1613), -INT16_C( 18866) },
      {       INT16_MAX,  INT16_C( 24023),  INT16_C(   256),  INT16_C( 10279),  INT16_C(  6410),  INT16_C(  4863),  INT16_C(  1613),  INT16_C( 18866) } },
    { { -INT16_C( 26677), -INT16_C( 23519), -INT16_C( 10358),  INT16_C( 11759),  INT16_C( 28681),  INT16_C(  8443), -INT16_C(  5907), -INT16_C( 21346) },
      {  INT16_C( 26677),  INT16_C( 23519),  INT16_C( 10358),  INT16_C( 11759),  INT16_C( 28681),  INT16_C(  8443),  INT16_C(  5907),  INT16_C( 21346) } },
    { { -INT16_C( 14320),  INT16_C(  4174),  INT16_C( 10183), -INT16_C( 11800), -INT16_C(  6336), -INT16_C( 29213),  INT16_C( 12781), -INT16_C( 18108) },
      {  INT16_C( 14320),  INT16_C(  4174),  INT16_C( 10183),  INT16_C( 11800),  INT16_C(  6336),  INT16_C( 29213),  INT16_C( 12781),  INT16_C( 18108) } },
    { {  INT16_C( 26056),  INT16_C( 21341),  INT16_C( 19516),  INT16_C( 17792),  INT16_C( 31676), -INT16_C( 21915),  INT16_C(  1123),  INT16_C( 29782) },
      {  INT16_C( 26056),  INT16_C( 21341),  INT16_C( 19516),  INT16_C( 17792),  INT16_C( 31676),  INT16_C( 21915),  INT16_C(  1123),  INT16_C( 29782) } },
    { { -INT16_C( 23348), -INT16_C( 27772),  INT16_C( 27852),  INT16_C(  3172),  INT16_C( 18259),  INT16_C( 16794), -INT16_C(  8584),  INT16_C( 16890) },
      {  INT16_C( 23348),  INT16_C( 27772),  INT16_C( 27852),  INT16_C(  3172),  INT16_C( 18259),  INT16_C( 16794),  INT16_C(  8584),  INT16_C( 16890) } },
    { {  INT16_C( 22339),  INT16_C( 32660),  INT16_C(  5284),  INT16_C( 24772),  INT16_C( 10640), -INT16_C(  3318),  INT16_C( 24621), -INT16_C(  1689) },
      {  INT16_C( 22339),  INT16_C( 32660),  INT16_C(  5284),  INT16_C( 24772),  INT16_C( 10640),  INT16_C(  3318),  INT16_C( 24621),  INT16_C(  1689) } },
    { { -INT16_C(  5115), -INT16_C( 11892), -INT16_C(  4008), -INT16_C( 21283),  INT16_C( 30519), -INT16_C( 20243), -INT16_C(  6315), -INT16_C( 26383) },
      {  INT16_C(  5115),  INT16_C( 11892),  INT16_C(  4008),  INT16_C( 21283),  INT16_C( 30519),  INT16_C( 20243),  INT16_C(  6315),  INT16_C( 26383) } },
    { { -INT16_C( 31426), -INT16_C(  7657), -INT16_C(  9319),  INT16_C( 10563),  INT16_C( 19717),  INT16_C( 12829), -INT16_C( 31570), -INT16_C( 19668) },
      {  INT16_C( 31426),  INT16_C(  7657),  INT16_C(  9319),  INT16_C( 10563),  INT16_C( 19717),  INT16_C( 12829),  INT16_C( 31570),  INT16_C( 19668) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t r = simde_vqabsq_s16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    if (i == 0)
      a = simde_vsetq_lane_s16(INT16_MIN, a, 0);
    simde_int16x8_t r = simde_vqabsq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabsq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { {            INT32_MIN, -INT32_C(   529178199),  INT32_C(   781214425), -INT32_C(  2016968375) },
      {            INT32_MAX,  INT32_C(   529178199),  INT32_C(   781214425),  INT32_C(  2016968375) } },
    { { -INT32_C(  1603609082), -INT32_C(  1077301830), -INT32_C(  1460541702), -INT32_C(   614785685) },
      {  INT32_C(  1603609082),  INT32_C(  1077301830),  INT32_C(  1460541702),  INT32_C(   614785685) } },
    { {  INT32_C(  2141511638),  INT32_C(   442440001), -INT32_C(  1001852805),  INT32_C(  2018250609) },
      {  INT32_C(  2141511638),  INT32_C(   442440001),  INT32_C(  1001852805),  INT32_C(  2018250609) } },
    { { -INT32_C(  1474775314),  INT32_C(  1567088995),  INT32_C(   856053960),  INT32_C(  1276010870) },
      {  INT32_C(  1474775314),  INT32_C(  1567088995),  INT32_C(   856053960),  INT32_C(  1276010870) } },
    { { -INT32_C(  2100579519),  INT32_C(  1218194124), -INT32_C(  1945312230), -INT32_C(   503031564) },
      {  INT32_C(  2100579519),  INT32_C(  1218194124),  INT32_C(  1945312230),  INT32_C(   503031564) } },
    { {  INT32_C(  1904876558), -INT32_C(   976227843), -INT32_C(  1074211511),  INT32_C(  1997211446) },
      {  INT32_C(  1904876558),  INT32_C(   976227843),  INT32_C(  1074211511),  INT32_C(  1997211446) } },
    { { -INT32_C(  2030446918),  INT32_C(   466523393),  INT32_C(  1856494458),  INT32_C(  1112582963) },
      {  INT32_C(  2030446918),  INT32_C(   466523393),  INT32_C(  1856494458),  INT32_C(  1112582963) } },
    { { -INT32_C(   978068793),  INT32_C(   344621771), -INT32_C(  1898675369),  INT32_C(  1141235594) },
      {  INT32_C(   978068793),  INT32_C(   344621771),  INT32_C(  1898675369),  INT32_C(  1141235594) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t r = simde_vqabsq_s32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    if (i == 0)
      a = simde_vsetq_lane_s32(INT32_MIN, a, 0);
    simde_int32x4_t r = simde_vqabsq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqabsq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t r[2];
  } test_vec[] = {
    { {                     INT64_MIN, -INT64_C( 1303286155051238796) },
      {                     INT64_MAX,  INT64_C( 1303286155051238796) } },
    { {  INT64_C( 8612637443141836198), -INT64_C( 1185279885774071105) },
      {  INT64_C( 8612637443141836198),  INT64_C( 1185279885774071105) } },
    { {  INT64_C( 7326364772480735241), -INT64_C( 7204080496378369549) },
      {  INT64_C( 7326364772480735241),  INT64_C( 7204080496378369549) } },
    { { -INT64_C( 5536731587706767469),  INT64_C( 4762145634079551213) },
      {  INT64_C( 5536731587706767469),  INT64_C( 4762145634079551213) } },
    { {  INT64_C( 2970279220873313762), -INT64_C( 3582816656948116042) },
      {  INT64_C( 2970279220873313762),  INT64_C( 3582816656948116042) } },
    { { -INT64_C( 2979506185981372930),  INT64_C( 1176586486946833368) },
      {  INT64_C( 2979506185981372930),  INT64_C( 1176586486946833368) } },
    { {  INT64_C( 8588114629788644560), -INT64_C( 5302308270149242527) },
      {  INT64_C( 8588114629788644560),  INT64_C( 5302308270149242527) } },
    { {  INT64_C( 7889831097103149759),  INT64_C( 6858932265364126706) },
      {  INT64_C( 7889831097103149759),  INT64_C( 6858932265364126706) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t r = simde_vqabsq_s64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    if (i == 0)
      a = simde_vsetq_lane_s64(INT64_MIN, a, 0);
    simde_int64x2_t r = simde_vqabsq_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqabsb_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqabsh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqabss_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqabsd_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqabs_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqabs_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqabs_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqabs_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqabsq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqabsq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqabsq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqabsq_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
