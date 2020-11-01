#define SIMDE_TEST_ARM_NEON_INSN qneg

#include "test-neon.h"
#include "../../../simde/arm/neon/qneg.h"
#include "../../../simde/arm/neon/set_lane.h"

static int
test_simde_vqnegb_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t r;
  } test_vec[] = {
    {      INT8_MIN,
           INT8_MAX },
    { -INT8_C(  59),
       INT8_C(  59) },
    { -INT8_C(  53),
       INT8_C(  53) },
    {  INT8_C(  96),
      -INT8_C(  96) },
    {  INT8_C(  75),
      -INT8_C(  75) },
    { -INT8_C(  55),
       INT8_C(  55) },
    { -INT8_C(  47),
       INT8_C(  47) },
    { -INT8_C(  61),
       INT8_C(  61) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r = simde_vqnegb_s8(test_vec[i].a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a = (i == 0) ? INT8_MIN : simde_test_codegen_random_i8();
    int8_t r = simde_vqnegb_s8(a);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqnegh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t r;
  } test_vec[] = {
    {       INT16_MIN,
            INT16_MAX },
    { -INT16_C( 19482),
       INT16_C( 19482) },
    { -INT16_C(  1948),
       INT16_C(  1948) },
    {  INT16_C( 21429),
      -INT16_C( 21429) },
    {  INT16_C(  2876),
      -INT16_C(  2876) },
    {  INT16_C( 12853),
      -INT16_C( 12853) },
    { -INT16_C( 15738),
       INT16_C( 15738) },
    { -INT16_C( 22893),
       INT16_C( 22893) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r = simde_vqnegh_s16(test_vec[i].a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = (i == 0) ? INT16_MIN : simde_test_codegen_random_i16();
    int16_t r = simde_vqnegh_s16(a);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqnegs_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t r;
  } test_vec[] = {
    {            INT32_MIN,
                 INT32_MAX },
    {  INT32_C(   833874552),
      -INT32_C(   833874552) },
    {  INT32_C(   789306444),
      -INT32_C(   789306444) },
    {  INT32_C(  2046037166),
      -INT32_C(  2046037166) },
    {  INT32_C(  1044529005),
      -INT32_C(  1044529005) },
    {  INT32_C(  1743857923),
      -INT32_C(  1743857923) },
    {  INT32_C(  1572513313),
      -INT32_C(  1572513313) },
    {  INT32_C(   948957106),
      -INT32_C(   948957106) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_vqnegs_s32(test_vec[i].a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = (i == 0) ? INT32_MIN : simde_test_codegen_random_i32();
    int32_t r = simde_vqnegs_s32(a);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqnegd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t r;
  } test_vec[] = {
    {                     INT64_MIN,
                          INT64_MAX },
    {  INT64_C( 6438900673212785330),
      -INT64_C( 6438900673212785330) },
    { -INT64_C( 2263765304330393746),
       INT64_C( 2263765304330393746) },
    {  INT64_C( 2388614247759206332),
      -INT64_C( 2388614247759206332) },
    { -INT64_C( 9033923089242529353),
       INT64_C( 9033923089242529353) },
    { -INT64_C( 9181141915911028687),
       INT64_C( 9181141915911028687) },
    {  INT64_C( 6396010445682777967),
      -INT64_C( 6396010445682777967) },
    { -INT64_C( 6256838048045538807),
       INT64_C( 6256838048045538807) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vqnegd_s64(test_vec[i].a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = (i == 0) ? INT64_MIN : simde_test_codegen_random_i64();
    int64_t r = simde_vqnegd_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqneg_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { {      INT8_MIN,  INT8_C(  92), -INT8_C(  48),  INT8_C(  20),  INT8_C(  55),  INT8_C(   1),  INT8_C(  44),  INT8_C(  90) },
      {      INT8_MAX, -INT8_C(  92),  INT8_C(  48), -INT8_C(  20), -INT8_C(  55), -INT8_C(   1), -INT8_C(  44), -INT8_C(  90) } },
    { { -INT8_C(  56),  INT8_C(  96), -INT8_C(   3),  INT8_C( 125),      INT8_MIN,  INT8_C(  80), -INT8_C(  75), -INT8_C(   2) },
      {  INT8_C(  56), -INT8_C(  96),  INT8_C(   3), -INT8_C( 125),      INT8_MAX, -INT8_C(  80),  INT8_C(  75),  INT8_C(   2) } },
    { {  INT8_C(   2), -INT8_C(  40), -INT8_C( 121),      INT8_MIN, -INT8_C(  72),  INT8_C( 115), -INT8_C(  65),  INT8_C( 108) },
      { -INT8_C(   2),  INT8_C(  40),  INT8_C( 121),      INT8_MAX,  INT8_C(  72), -INT8_C( 115),  INT8_C(  65), -INT8_C( 108) } },
    { {  INT8_C( 112), -INT8_C(  88), -INT8_C(  96),  INT8_C(  16),      INT8_MIN, -INT8_C(   3), -INT8_C(  32), -INT8_C(  95) },
      { -INT8_C( 112),  INT8_C(  88),  INT8_C(  96), -INT8_C(  16),      INT8_MAX,  INT8_C(   3),  INT8_C(  32),  INT8_C(  95) } },
    { { -INT8_C(  31), -INT8_C(  51), -INT8_C( 114),  INT8_C(  25),      INT8_MIN, -INT8_C(  18),  INT8_C(  23),  INT8_C(  19) },
      {  INT8_C(  31),  INT8_C(  51),  INT8_C( 114), -INT8_C(  25),      INT8_MAX,  INT8_C(  18), -INT8_C(  23), -INT8_C(  19) } },
    { {  INT8_C( 103), -INT8_C(  56),      INT8_MIN, -INT8_C( 109), -INT8_C(  54),  INT8_C(  98),  INT8_C(  27), -INT8_C(  47) },
      { -INT8_C( 103),  INT8_C(  56),      INT8_MAX,  INT8_C( 109),  INT8_C(  54), -INT8_C(  98), -INT8_C(  27),  INT8_C(  47) } },
    { { -INT8_C( 114), -INT8_C( 112), -INT8_C( 121), -INT8_C(  30),      INT8_MIN,  INT8_C(  47), -INT8_C( 126),  INT8_C(  16) },
      {  INT8_C( 114),  INT8_C( 112),  INT8_C( 121),  INT8_C(  30),      INT8_MAX, -INT8_C(  47),  INT8_C( 126), -INT8_C(  16) } },
    { {      INT8_MIN, -INT8_C(  16),  INT8_C(  93), -INT8_C(  77), -INT8_C(  47),  INT8_C(  42),  INT8_C(  65), -INT8_C(  21) },
      {      INT8_MAX,  INT8_C(  16), -INT8_C(  93),  INT8_C(  77),  INT8_C(  47), -INT8_C(  42), -INT8_C(  65),  INT8_C(  21) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vqneg_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    a = simde_vset_lane_s8(INT8_MIN, a, simde_test_codegen_random_i8() & 7);
    simde_int8x8_t r = simde_vqneg_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqneg_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { {       INT16_MIN, -INT16_C(  3014), -INT16_C(   596), -INT16_C( 13820) },
      {       INT16_MAX,  INT16_C(  3014),  INT16_C(   596),  INT16_C( 13820) } },
    { {       INT16_MIN, -INT16_C( 27535), -INT16_C( 24057),  INT16_C( 14980) },
      {       INT16_MAX,  INT16_C( 27535),  INT16_C( 24057), -INT16_C( 14980) } },
    { { -INT16_C(  5471),       INT16_MIN,  INT16_C(  7663), -INT16_C( 23038) },
      {  INT16_C(  5471),       INT16_MAX, -INT16_C(  7663),  INT16_C( 23038) } },
    { { -INT16_C(   182), -INT16_C( 30384), -INT16_C( 15455),       INT16_MIN },
      {  INT16_C(   182),  INT16_C( 30384),  INT16_C( 15455),       INT16_MAX } },
    { {       INT16_MIN,  INT16_C( 12345),  INT16_C( 22890), -INT16_C(    95) },
      {       INT16_MAX, -INT16_C( 12345), -INT16_C( 22890),  INT16_C(    95) } },
    { {       INT16_MIN, -INT16_C(  3173), -INT16_C( 31451), -INT16_C( 31794) },
      {       INT16_MAX,  INT16_C(  3173),  INT16_C( 31451),  INT16_C( 31794) } },
    { { -INT16_C( 31253), -INT16_C( 10982),  INT16_C(  6607),       INT16_MIN },
      {  INT16_C( 31253),  INT16_C( 10982), -INT16_C(  6607),       INT16_MAX } },
    { {  INT16_C(  7144),       INT16_MIN, -INT16_C(  5157),  INT16_C(  2960) },
      { -INT16_C(  7144),       INT16_MAX,  INT16_C(  5157), -INT16_C(  2960) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vqneg_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    a = simde_vset_lane_s16(INT16_MIN, a, simde_test_codegen_random_i8() & 3);
    simde_int16x4_t r = simde_vqneg_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqneg_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1247063273),            INT32_MIN },
      { -INT32_C(  1247063273),            INT32_MAX } },
    { {            INT32_MIN,  INT32_C(  1928856989) },
      {            INT32_MAX, -INT32_C(  1928856989) } },
    { {            INT32_MIN, -INT32_C(   669104000) },
      {            INT32_MAX,  INT32_C(   669104000) } },
    { {            INT32_MIN, -INT32_C(  1665934254) },
      {            INT32_MAX,  INT32_C(  1665934254) } },
    { { -INT32_C(  2001763957),            INT32_MIN },
      {  INT32_C(  2001763957),            INT32_MAX } },
    { {            INT32_MIN, -INT32_C(  1609692717) },
      {            INT32_MAX,  INT32_C(  1609692717) } },
    { {            INT32_MIN,  INT32_C(   648727239) },
      {            INT32_MAX, -INT32_C(   648727239) } },
    { {            INT32_MIN, -INT32_C(   335398556) },
      {            INT32_MAX,  INT32_C(   335398556) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t r = simde_vqneg_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    a = simde_vset_lane_s32(INT32_MIN, a, simde_test_codegen_random_i8() & 1);
    simde_int32x2_t r = simde_vqneg_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqneg_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 8191283204820754105) },
      {  INT64_C( 8191283204820754105) } },
    { {  INT64_C( 7088802444648733089) },
      { -INT64_C( 7088802444648733089) } },
    { {                     INT64_MIN },
      {                     INT64_MAX } },
    { { -INT64_C( 1307339272021044458) },
      {  INT64_C( 1307339272021044458) } },
    { {                     INT64_MIN },
      {                     INT64_MAX } },
    { { -INT64_C( 2461253948824801768) },
      {  INT64_C( 2461253948824801768) } },
    { {  INT64_C( 8701714957695160342) },
      { -INT64_C( 8701714957695160342) } },
    { {  INT64_C( 5631676463628112935) },
      { -INT64_C( 5631676463628112935) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t r = simde_vqneg_s64(a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    if ((simde_test_codegen_random_i8() & 3) == 3)
      a = simde_vset_lane_s64(INT64_MIN, a, 0);
    simde_int64x1_t r = simde_vqneg_s64(a);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqnegq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  57), -INT8_C(  22),  INT8_C( 105), -INT8_C(  86),  INT8_C(   3),      INT8_MIN, -INT8_C(  17), -INT8_C(  23),
         INT8_C(  42), -INT8_C(  51), -INT8_C(  63),  INT8_C(   7),      INT8_MAX, -INT8_C(  41), -INT8_C( 105), -INT8_C(  98) },
      {  INT8_C(  57),  INT8_C(  22), -INT8_C( 105),  INT8_C(  86), -INT8_C(   3),      INT8_MAX,  INT8_C(  17),  INT8_C(  23),
        -INT8_C(  42),  INT8_C(  51),  INT8_C(  63), -INT8_C(   7), -INT8_C( 127),  INT8_C(  41),  INT8_C( 105),  INT8_C(  98) } },
    { {  INT8_C(  61),  INT8_C(  81),  INT8_C(  23), -INT8_C(  74), -INT8_C(  33),  INT8_C(  63),  INT8_C(  10),  INT8_C(  91),
         INT8_C(  31), -INT8_C(  15),  INT8_C(  22),      INT8_MIN,  INT8_C(  63), -INT8_C(  78),  INT8_C(  14),  INT8_C(  41) },
      { -INT8_C(  61), -INT8_C(  81), -INT8_C(  23),  INT8_C(  74),  INT8_C(  33), -INT8_C(  63), -INT8_C(  10), -INT8_C(  91),
        -INT8_C(  31),  INT8_C(  15), -INT8_C(  22),      INT8_MAX, -INT8_C(  63),  INT8_C(  78), -INT8_C(  14), -INT8_C(  41) } },
    { { -INT8_C(  71),  INT8_C(  44), -INT8_C(  77), -INT8_C(  88),  INT8_C(  22), -INT8_C(  35),  INT8_C( 118), -INT8_C(  41),
        -INT8_C(  28), -INT8_C(  11), -INT8_C(  82),      INT8_MIN, -INT8_C( 109),  INT8_C(   4), -INT8_C(  71), -INT8_C(  27) },
      {  INT8_C(  71), -INT8_C(  44),  INT8_C(  77),  INT8_C(  88), -INT8_C(  22),  INT8_C(  35), -INT8_C( 118),  INT8_C(  41),
         INT8_C(  28),  INT8_C(  11),  INT8_C(  82),      INT8_MAX,  INT8_C( 109), -INT8_C(   4),  INT8_C(  71),  INT8_C(  27) } },
    { {  INT8_C( 111), -INT8_C(  60),  INT8_C(  90),  INT8_C( 121),  INT8_C(  31),  INT8_C( 122),      INT8_MIN,  INT8_C(  53),
        -INT8_C(  63), -INT8_C(  87), -INT8_C(  25), -INT8_C(  49), -INT8_C(  45),  INT8_C(   3), -INT8_C( 120), -INT8_C(   1) },
      { -INT8_C( 111),  INT8_C(  60), -INT8_C(  90), -INT8_C( 121), -INT8_C(  31), -INT8_C( 122),      INT8_MAX, -INT8_C(  53),
         INT8_C(  63),  INT8_C(  87),  INT8_C(  25),  INT8_C(  49),  INT8_C(  45), -INT8_C(   3),  INT8_C( 120),  INT8_C(   1) } },
    { {  INT8_C(  49),  INT8_C(  21), -INT8_C( 109), -INT8_C(  89), -INT8_C(  20),      INT8_MIN, -INT8_C( 100), -INT8_C( 101),
        -INT8_C(  13),  INT8_C(  47), -INT8_C(  97), -INT8_C(  83),  INT8_C(  20), -INT8_C(  70),  INT8_C(  28), -INT8_C(  39) },
      { -INT8_C(  49), -INT8_C(  21),  INT8_C( 109),  INT8_C(  89),  INT8_C(  20),      INT8_MAX,  INT8_C( 100),  INT8_C( 101),
         INT8_C(  13), -INT8_C(  47),  INT8_C(  97),  INT8_C(  83), -INT8_C(  20),  INT8_C(  70), -INT8_C(  28),  INT8_C(  39) } },
    { { -INT8_C( 106),      INT8_MIN, -INT8_C( 113),  INT8_C(   0),  INT8_C(  46),  INT8_C(  80), -INT8_C(  86),  INT8_C(  21),
         INT8_C(  31),  INT8_C( 125),  INT8_C(  24), -INT8_C(  88),  INT8_C( 124), -INT8_C(  50), -INT8_C(  39), -INT8_C( 110) },
      {  INT8_C( 106),      INT8_MAX,  INT8_C( 113),  INT8_C(   0), -INT8_C(  46), -INT8_C(  80),  INT8_C(  86), -INT8_C(  21),
        -INT8_C(  31), -INT8_C( 125), -INT8_C(  24),  INT8_C(  88), -INT8_C( 124),  INT8_C(  50),  INT8_C(  39),  INT8_C( 110) } },
    { {      INT8_MIN,  INT8_C( 126), -INT8_C(  39),  INT8_C(  28),  INT8_C(  25), -INT8_C(  52),  INT8_C(  75),      INT8_MIN,
         INT8_C( 121),  INT8_C(  96),  INT8_C( 115), -INT8_C( 106),  INT8_C(  57), -INT8_C( 120),  INT8_C(  44),  INT8_C(  49) },
      {      INT8_MAX, -INT8_C( 126),  INT8_C(  39), -INT8_C(  28), -INT8_C(  25),  INT8_C(  52), -INT8_C(  75),      INT8_MAX,
        -INT8_C( 121), -INT8_C(  96), -INT8_C( 115),  INT8_C( 106), -INT8_C(  57),  INT8_C( 120), -INT8_C(  44), -INT8_C(  49) } },
    { {  INT8_C(  44),  INT8_C(  95),  INT8_C( 103), -INT8_C(  42),  INT8_C( 117), -INT8_C( 122),      INT8_MIN, -INT8_C( 115),
         INT8_C(  46), -INT8_C(  48),  INT8_C(  92),  INT8_C(   7),  INT8_C(  98), -INT8_C(  67), -INT8_C( 121), -INT8_C(  32) },
      { -INT8_C(  44), -INT8_C(  95), -INT8_C( 103),  INT8_C(  42), -INT8_C( 117),  INT8_C( 122),      INT8_MAX,  INT8_C( 115),
        -INT8_C(  46),  INT8_C(  48), -INT8_C(  92), -INT8_C(   7), -INT8_C(  98),  INT8_C(  67),  INT8_C( 121),  INT8_C(  32) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t r = simde_vqnegq_s8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    a = simde_vsetq_lane_s8(INT8_MIN, a, simde_test_codegen_random_i8() & 15);
    simde_int8x16_t r = simde_vqnegq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqnegq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  1373), -INT16_C(  4253), -INT16_C(  9038),       INT16_MIN, -INT16_C( 30606), -INT16_C( 24915), -INT16_C( 15175),  INT16_C(  6603) },
      {  INT16_C(  1373),  INT16_C(  4253),  INT16_C(  9038),       INT16_MAX,  INT16_C( 30606),  INT16_C( 24915),  INT16_C( 15175), -INT16_C(  6603) } },
    { { -INT16_C( 29023), -INT16_C(  2638), -INT16_C(  8165),  INT16_C( 30661),  INT16_C( 10216),  INT16_C( 28469),       INT16_MIN,  INT16_C(   275) },
      {  INT16_C( 29023),  INT16_C(  2638),  INT16_C(  8165), -INT16_C( 30661), -INT16_C( 10216), -INT16_C( 28469),       INT16_MAX, -INT16_C(   275) } },
    { { -INT16_C( 19454),       INT16_MIN,  INT16_C( 32217), -INT16_C( 30759), -INT16_C( 28132), -INT16_C(  6325),  INT16_C( 30635),  INT16_C( 14728) },
      {  INT16_C( 19454),       INT16_MAX, -INT16_C( 32217),  INT16_C( 30759),  INT16_C( 28132),  INT16_C(  6325), -INT16_C( 30635), -INT16_C( 14728) } },
    { {  INT16_C( 21885),  INT16_C( 16905), -INT16_C(  3636),  INT16_C(   361),  INT16_C( 29025),  INT16_C( 29901),       INT16_MIN,  INT16_C(  9846) },
      { -INT16_C( 21885), -INT16_C( 16905),  INT16_C(  3636), -INT16_C(   361), -INT16_C( 29025), -INT16_C( 29901),       INT16_MAX, -INT16_C(  9846) } },
    { {  INT16_C(   199), -INT16_C( 24444), -INT16_C( 24441), -INT16_C( 11726),       INT16_MIN,  INT16_C(  3913),  INT16_C( 29207),  INT16_C( 27789) },
      { -INT16_C(   199),  INT16_C( 24444),  INT16_C( 24441),  INT16_C( 11726),       INT16_MAX, -INT16_C(  3913), -INT16_C( 29207), -INT16_C( 27789) } },
    { {  INT16_C( 14799),  INT16_C( 14701), -INT16_C( 12742),  INT16_C(  1962),  INT16_C(  7234),       INT16_MIN,  INT16_C(  2371),  INT16_C( 17279) },
      { -INT16_C( 14799), -INT16_C( 14701),  INT16_C( 12742), -INT16_C(  1962), -INT16_C(  7234),       INT16_MAX, -INT16_C(  2371), -INT16_C( 17279) } },
    { { -INT16_C( 13793),  INT16_C( 21037),       INT16_MIN, -INT16_C(  6608),  INT16_C( 18372),  INT16_C( 20824), -INT16_C( 11084), -INT16_C(  4832) },
      {  INT16_C( 13793), -INT16_C( 21037),       INT16_MAX,  INT16_C(  6608), -INT16_C( 18372), -INT16_C( 20824),  INT16_C( 11084),  INT16_C(  4832) } },
    { {  INT16_C( 10073),  INT16_C(   784),  INT16_C( 21295),  INT16_C( 12832),  INT16_C( 25355), -INT16_C( 29893),       INT16_MIN,  INT16_C( 28842) },
      { -INT16_C( 10073), -INT16_C(   784), -INT16_C( 21295), -INT16_C( 12832), -INT16_C( 25355),  INT16_C( 29893),       INT16_MAX, -INT16_C( 28842) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t r = simde_vqnegq_s16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    a = simde_vsetq_lane_s16(INT16_MIN, a, simde_test_codegen_random_i8() & 7);
    simde_int16x8_t r = simde_vqnegq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqnegq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   749407484),  INT32_C(  1265922034),            INT32_MIN,  INT32_C(  1010458901) },
      { -INT32_C(   749407484), -INT32_C(  1265922034),            INT32_MAX, -INT32_C(  1010458901) } },
    { {  INT32_C(  1573219133), -INT32_C(   641675107),  INT32_C(   111306331),            INT32_MIN },
      { -INT32_C(  1573219133),  INT32_C(   641675107), -INT32_C(   111306331),            INT32_MAX } },
    { {            INT32_MIN,  INT32_C(  1087074848), -INT32_C(  1918771117), -INT32_C(  2000022756) },
      {            INT32_MAX, -INT32_C(  1087074848),  INT32_C(  1918771117),  INT32_C(  2000022756) } },
    { { -INT32_C(   391568088), -INT32_C(  1605434114),  INT32_C(   221848842),            INT32_MIN },
      {  INT32_C(   391568088),  INT32_C(  1605434114), -INT32_C(   221848842),            INT32_MAX } },
    { { -INT32_C(  1432224033),            INT32_MIN,  INT32_C(  1291036289),  INT32_C(  1416940590) },
      {  INT32_C(  1432224033),            INT32_MAX, -INT32_C(  1291036289), -INT32_C(  1416940590) } },
    { { -INT32_C(  1418112420),            INT32_MIN, -INT32_C(   844572271), -INT32_C(  1230186569) },
      {  INT32_C(  1418112420),            INT32_MAX,  INT32_C(   844572271),  INT32_C(  1230186569) } },
    { { -INT32_C(   529664938), -INT32_C(   930680876),            INT32_MIN,  INT32_C(  1527449865) },
      {  INT32_C(   529664938),  INT32_C(   930680876),            INT32_MAX, -INT32_C(  1527449865) } },
    { { -INT32_C(  2012852553),            INT32_MIN,  INT32_C(   284825956), -INT32_C(  1016695857) },
      {  INT32_C(  2012852553),            INT32_MAX, -INT32_C(   284825956),  INT32_C(  1016695857) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t r = simde_vqnegq_s32(a);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    a = simde_vsetq_lane_s32(INT32_MIN, a, simde_test_codegen_random_i8() & 3);
    simde_int32x4_t r = simde_vqnegq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqnegq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C(  828086871084984250),  INT64_C( 3854096010263235514) },
      {  INT64_C(  828086871084984250), -INT64_C( 3854096010263235514) } },
    { { -INT64_C( 3639046133724107004), -INT64_C( 6251241396687057262) },
      {  INT64_C( 3639046133724107004),  INT64_C( 6251241396687057262) } },
    { { -INT64_C(  425107489667938036), -INT64_C( 1946399232152174468) },
      {  INT64_C(  425107489667938036),  INT64_C( 1946399232152174468) } },
    { { -INT64_C( 4309889297074374813), -INT64_C(  830958200115805909) },
      {  INT64_C( 4309889297074374813),  INT64_C(  830958200115805909) } },
    { {                     INT64_MIN, -INT64_C( 1198093595569662721) },
      {                     INT64_MAX,  INT64_C( 1198093595569662721) } },
    { {  INT64_C( 2211971346900284225), -INT64_C( 8905928107539194389) },
      { -INT64_C( 2211971346900284225),  INT64_C( 8905928107539194389) } },
    { {  INT64_C( 4465699288241565830), -INT64_C( 7640949259834936747) },
      { -INT64_C( 4465699288241565830),  INT64_C( 7640949259834936747) } },
    { { -INT64_C( 2254431034773090970),  INT64_C( 4465036234584639496) },
      {  INT64_C( 2254431034773090970), -INT64_C( 4465036234584639496) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t r = simde_vqnegq_s64(a);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    if ((simde_test_codegen_random_i8() & 3) == 3)
      a = simde_vsetq_lane_s64(INT64_MIN, a, 0);
    simde_int64x2_t r = simde_vqnegq_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqnegb_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqnegh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqnegs_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqnegd_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqneg_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqneg_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqneg_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqneg_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqnegq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqnegq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqnegq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqnegq_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
