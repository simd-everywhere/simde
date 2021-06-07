#define SIMDE_TEST_ARM_NEON_INSN tst

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/tst.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

static int
test_simde_vtst_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  42), -INT8_C(  92),  INT8_C(   8),  INT8_C(  20),  INT8_C( 123), -INT8_C( 127), -INT8_C(  20),  INT8_C(  74) },
      { -INT8_C(  48),  INT8_C(  90), -INT8_C(   3),  INT8_C(  68),  INT8_C( 104),  INT8_C( 126), -INT8_C( 103),  INT8_C( 100) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  58),  INT8_C(  21),  INT8_C( 103), -INT8_C(  65), -INT8_C(  93),  INT8_C(  33), -INT8_C( 117), -INT8_C(   9) },
      { -INT8_C(  59), -INT8_C( 108),  INT8_C(  11),  INT8_C(  64),  INT8_C(  92), -INT8_C(   9), -INT8_C( 117),  INT8_C(  44) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  63),  INT8_C( 126), -INT8_C( 127), -INT8_C(   6),  INT8_C(  27), -INT8_C(  11),  INT8_C(  62),  INT8_C( 121) },
      { -INT8_C(  88), -INT8_C( 127),  INT8_C( 126), -INT8_C(  55), -INT8_C(  94),  INT8_C(  10), -INT8_C(  63),  INT8_C( 104) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(  68), -INT8_C(  24), -INT8_C(  49), -INT8_C(  62), -INT8_C(  97), -INT8_C(  18),  INT8_C(  26), -INT8_C(  84) },
      {  INT8_C(  80),  INT8_C(  23), -INT8_C(  40),  INT8_C( 108), -INT8_C(  86), -INT8_C(  14), -INT8_C(  27),  INT8_C(  83) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  61),  INT8_C(  38),  INT8_C(   6), -INT8_C(  98), -INT8_C(  66), -INT8_C(  40), -INT8_C(  65),  INT8_C(  22) },
      { -INT8_C(  62),  INT8_C(  83), -INT8_C(  40),  INT8_C(  97),  INT8_C(  65),  INT8_C(  39),  INT8_C(  64), -INT8_C( 111) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(  58),  INT8_C(  89), -INT8_C( 108),  INT8_C( 108),  INT8_C(  54),  INT8_C(  45),  INT8_C(  86), -INT8_C(  32) },
      {  INT8_C(  57), -INT8_C(  57),  INT8_C(  78), -INT8_C( 109), -INT8_C(  13), -INT8_C(  46), -INT8_C(  87), -INT8_C(  75) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 111), -INT8_C(  11),  INT8_C(  43),  INT8_C(  98), -INT8_C(  40),  INT8_C(  14), -INT8_C( 127),  INT8_C(  31) },
      {  INT8_C( 103), -INT8_C( 115), -INT8_C(  44), -INT8_C(  99), -INT8_C(  97), -INT8_C( 107),  INT8_C( 126), -INT8_C(  40) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C( 106),  INT8_C(  26),  INT8_C(  41),  INT8_C(  17), -INT8_C(   7),  INT8_C(  33),  INT8_C(  39), -INT8_C(  32) },
      {  INT8_C(  22), -INT8_C(   8),  INT8_C(  90), -INT8_C(  18),  INT8_C(   6),  INT8_C(  82),  INT8_C(  13),  INT8_C( 109) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vtst_s8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_private a_ = simde_int8x8_to_private(simde_test_arm_neon_random_i8x8());
    simde_int8x8_private b_ = simde_int8x8_to_private(simde_test_arm_neon_random_i8x8());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_int8x8_t a = simde_int8x8_from_private(a_);
    simde_int8x8_t b = simde_int8x8_from_private(b_);

    simde_uint8x8_t r = simde_vtst_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtst_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { {  INT16_C(  8893), -INT16_C( 30633), -INT16_C(  5180), -INT16_C( 21986) },
      { -INT16_C(  8894), -INT16_C(  8410),  INT16_C(  5179),  INT16_C(   917) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 22356),  INT16_C( 13046), -INT16_C( 21246), -INT16_C( 17745) },
      {  INT16_C( 17277), -INT16_C( 20888), -INT16_C( 16629),  INT16_C(  6966) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C(  5326),  INT16_C( 28390), -INT16_C(  1563), -INT16_C(  6543) },
      { -INT16_C( 15463), -INT16_C(  4592),  INT16_C(  1562),  INT16_C(  7200) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 16147),  INT16_C( 25142),  INT16_C(  5887), -INT16_C( 15559) },
      { -INT16_C(   149), -INT16_C( 25143), -INT16_C( 20502), -INT16_C(  5621) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C( 20131),  INT16_C( 18995),  INT16_C( 21617), -INT16_C( 25737) },
      {  INT16_C( 20130), -INT16_C( 18996), -INT16_C( 21618), -INT16_C( 29229) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C( 19885),  INT16_C( 27720), -INT16_C( 10807), -INT16_C( 31471) },
      { -INT16_C( 19886), -INT16_C( 27721),  INT16_C( 27027),  INT16_C( 31470) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C(  7756),  INT16_C( 17043),  INT16_C( 26253), -INT16_C(   375) },
      {  INT16_C(  8051),  INT16_C( 32635),  INT16_C( 17720),  INT16_C(   374) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 11348), -INT16_C( 25600), -INT16_C(  4586),  INT16_C( 26038) },
      {  INT16_C( 11347),  INT16_C(  1840), -INT16_C( 15603), -INT16_C( 26039) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vtst_s16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_private a_ = simde_int16x4_to_private(simde_test_arm_neon_random_i16x4());
    simde_int16x4_private b_ = simde_int16x4_to_private(simde_test_arm_neon_random_i16x4());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_int16x4_t a = simde_int16x4_from_private(a_);
    simde_int16x4_t b = simde_int16x4_from_private(b_);

    simde_uint16x4_t r = simde_vtst_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtst_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  2123657738),  INT32_C(  1952785266) },
      { -INT32_C(   968828515), -INT32_C(  1864600079) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  1508136360), -INT32_C(   427542109) },
      {  INT32_C(  1508136359),  INT32_C(  1322053306) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { -INT32_C(  1076671081), -INT32_C(   484753708) },
      {  INT32_C(  1076671080),  INT32_C(   484753707) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { {  INT32_C(  1378540991), -INT32_C(  2024385843) },
      { -INT32_C(  1378540992),  INT32_C(   310331232) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1490709835),  INT32_C(   162460638) },
      { -INT32_C(  1490709836), -INT32_C(  2027980263) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   429832559),  INT32_C(  1338460399) },
      { -INT32_C(   429832560),  INT32_C(   923953009) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { -INT32_C(   537296342),  INT32_C(   780541460) },
      {  INT32_C(   280339865),  INT32_C(    81628817) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   585404851),  INT32_C(   650345653) },
      { -INT32_C(  1201809693), -INT32_C(  1069905722) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vtst_s32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_private a_ = simde_int32x2_to_private(simde_test_arm_neon_random_i32x2());
    simde_int32x2_private b_ = simde_int32x2_to_private(simde_test_arm_neon_random_i32x2());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_int32x2_t a = simde_int32x2_from_private(a_);
    simde_int32x2_t b = simde_int32x2_from_private(b_);

    simde_uint32x2_t r = simde_vtst_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtst_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 1837781170212727101) },
      { -INT64_C( 4247103962042125515) },
      {                    UINT64_MAX } },
    { {  INT64_C( 4526798036743003940) },
      { -INT64_C( 4526798036743003941) },
      { UINT64_C(                   0) } },
    { {  INT64_C(  327556247060509157) },
      { -INT64_C(  327556247060509158) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 4814377440359057512) },
      { -INT64_C( 4814377440359057513) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 1890867640475375592) },
      {  INT64_C(  511230107150325363) },
      {                    UINT64_MAX } },
    { {  INT64_C( 1701538502363315684) },
      { -INT64_C( 1701538502363315685) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 5053963978680335937) },
      { -INT64_C( 5053963978680335938) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 2736194239582835245) },
      {  INT64_C( 7939050786364962868) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vtst_s64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_private a_ = simde_int64x1_to_private(simde_test_arm_neon_random_i64x1());
    simde_int64x1_private b_ = simde_int64x1_to_private(simde_test_arm_neon_random_i64x1());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_int64x1_t a = simde_int64x1_from_private(a_);
    simde_int64x1_t b = simde_int64x1_from_private(b_);

    simde_uint64x1_t r = simde_vtst_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtst_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 89), UINT8_C(123), UINT8_C( 24), UINT8_C( 18), UINT8_C( 98), UINT8_C(227), UINT8_C( 29), UINT8_C( 73) },
      { UINT8_C( 57), UINT8_C(132), UINT8_C(155), UINT8_C(237), UINT8_C( 99), UINT8_C(140), UINT8_C( 26), UINT8_C(  6) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 31), UINT8_C(154), UINT8_C(207), UINT8_C(  7), UINT8_C( 69), UINT8_C(110), UINT8_C(116), UINT8_C(225) },
      { UINT8_C(224), UINT8_C(  2), UINT8_C( 48), UINT8_C( 66), UINT8_C(229), UINT8_C( 77), UINT8_C(139), UINT8_C( 30) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(117), UINT8_C(  3), UINT8_C(142), UINT8_C(199), UINT8_C(118), UINT8_C(239), UINT8_C(116), UINT8_C( 67) },
      { UINT8_C(138), UINT8_C( 99), UINT8_C( 74), UINT8_C(207), UINT8_C(210), UINT8_C( 52), UINT8_C(110), UINT8_C(178) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(166), UINT8_C( 70), UINT8_C(242), UINT8_C( 90), UINT8_C(108), UINT8_C( 45), UINT8_C(157), UINT8_C( 72) },
      { UINT8_C( 48), UINT8_C( 43), UINT8_C( 15), UINT8_C(166), UINT8_C( 26), UINT8_C(131), UINT8_C(233), UINT8_C(164) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(128), UINT8_C( 95), UINT8_C( 32), UINT8_C(108), UINT8_C(222), UINT8_C(131), UINT8_C( 42), UINT8_C(133) },
      { UINT8_C( 61), UINT8_C( 28), UINT8_C(223), UINT8_C(169), UINT8_C( 74), UINT8_C(124), UINT8_C(241), UINT8_C(122) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 62), UINT8_C(218), UINT8_C( 36), UINT8_C(166), UINT8_C(188), UINT8_C(143), UINT8_C( 69), UINT8_C(203) },
      { UINT8_C(238), UINT8_C(  0), UINT8_C(169), UINT8_C(204), UINT8_C(247), UINT8_C(211), UINT8_C( 81), UINT8_C( 52) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(206), UINT8_C( 30), UINT8_C( 21), UINT8_C(238), UINT8_C(223), UINT8_C(247), UINT8_C(178), UINT8_C(161) },
      { UINT8_C( 85), UINT8_C(225), UINT8_C(195), UINT8_C( 17), UINT8_C(112), UINT8_C(  8), UINT8_C( 77), UINT8_C( 94) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(173), UINT8_C( 61),    UINT8_MAX, UINT8_C( 89), UINT8_C(194), UINT8_C(166), UINT8_C(135), UINT8_C(173) },
      { UINT8_C(123), UINT8_C(194), UINT8_C(  0), UINT8_C( 91), UINT8_C( 61), UINT8_C(189), UINT8_C(120), UINT8_C(146) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vtst_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_private a_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());
    simde_uint8x8_private b_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_uint8x8_t a = simde_uint8x8_from_private(a_);
    simde_uint8x8_t b = simde_uint8x8_from_private(b_);

    simde_uint8x8_t r = simde_vtst_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtst_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(17167), UINT16_C( 2845), UINT16_C(60553), UINT16_C(39974) },
      { UINT16_C(48368), UINT16_C(51998), UINT16_C( 4982), UINT16_C(25561) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(27310), UINT16_C(11088), UINT16_C(18399), UINT16_C(51232) },
      { UINT16_C(38225), UINT16_C(54447), UINT16_C(52558), UINT16_C(14303) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(55890), UINT16_C(47439), UINT16_C(54509), UINT16_C(48385) },
      { UINT16_C(11404), UINT16_C(18096), UINT16_C(49763), UINT16_C(17150) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(14483), UINT16_C(57647), UINT16_C( 3589), UINT16_C(17689) },
      { UINT16_C(54692), UINT16_C(63350), UINT16_C(29103), UINT16_C(40127) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(47595), UINT16_C(22531), UINT16_C( 5783), UINT16_C(31862) },
      { UINT16_C(17940), UINT16_C(43004), UINT16_C(11134), UINT16_C(33673) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(15991), UINT16_C( 9940), UINT16_C( 7749), UINT16_C(44782) },
      { UINT16_C(59007), UINT16_C(38600), UINT16_C(57786), UINT16_C(20753) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 8481), UINT16_C(37811), UINT16_C(15385), UINT16_C(21014) },
      { UINT16_C(57054), UINT16_C(21808), UINT16_C( 1053), UINT16_C(52603) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(35619), UINT16_C(57006), UINT16_C(49004), UINT16_C(25647) },
      { UINT16_C( 8846), UINT16_C(41840), UINT16_C( 8976), UINT16_C(10806) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vtst_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_private a_ = simde_uint16x4_to_private(simde_test_arm_neon_random_u16x4());
    simde_uint16x4_private b_ = simde_uint16x4_to_private(simde_test_arm_neon_random_u16x4());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_uint16x4_t a = simde_uint16x4_from_private(a_);
    simde_uint16x4_t b = simde_uint16x4_from_private(b_);

    simde_uint16x4_t r = simde_vtst_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtst_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(1186490664), UINT32_C( 158677967) },
      { UINT32_C(3108476631), UINT32_C(3180949110) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2684851262), UINT32_C(2893485814) },
      { UINT32_C(1446231173), UINT32_C( 357496804) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 673588817), UINT32_C(2227163532) },
      { UINT32_C(2901375964), UINT32_C(2067803763) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(1090798578), UINT32_C(3849131521) },
      { UINT32_C(3204168717), UINT32_C(  14961881) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(1094764559), UINT32_C(2952572818) },
      { UINT32_C(3200202736), UINT32_C(1342394477) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1961547111), UINT32_C(1781720465) },
      { UINT32_C(2775193137), UINT32_C(2331695287) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1024399692), UINT32_C(3204173392) },
      { UINT32_C(2249129758), UINT32_C(3982193923) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(  55975122), UINT32_C(3936928051) },
      { UINT32_C(3161760665), UINT32_C(2111225966) },
      {           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vtst_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_private a_ = simde_uint32x2_to_private(simde_test_arm_neon_random_u32x2());
    simde_uint32x2_private b_ = simde_uint32x2_to_private(simde_test_arm_neon_random_u32x2());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_uint32x2_t a = simde_uint32x2_from_private(a_);
    simde_uint32x2_t b = simde_uint32x2_from_private(b_);

    simde_uint32x2_t r = simde_vtst_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtst_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 1909471733032218373) },
      { UINT64_C(16537272340677333242) },
      { UINT64_C(                   0) } },
    { { UINT64_C(15227949905678791626) },
      { UINT64_C( 9252676368976284696) },
      {                    UINT64_MAX } },
    { { UINT64_C(10377830220437337974) },
      { UINT64_C(17301460315111856336) },
      {                    UINT64_MAX } },
    { { UINT64_C( 1759847872496586826) },
      { UINT64_C(16686896201212964789) },
      { UINT64_C(                   0) } },
    { { UINT64_C(13538799517923171882) },
      { UINT64_C( 4907944555786379733) },
      { UINT64_C(                   0) } },
    { { UINT64_C(16778310820077750940) },
      { UINT64_C(17276065934006257829) },
      {                    UINT64_MAX } },
    { { UINT64_C(14488914339200827468) },
      { UINT64_C(12871270039798326502) },
      {                    UINT64_MAX } },
    { { UINT64_C( 1200755092811906376) },
      { UINT64_C(  591546085826762793) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vtst_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_private a_ = simde_uint64x1_to_private(simde_test_arm_neon_random_u64x1());
    simde_uint64x1_private b_ = simde_uint64x1_to_private(simde_test_arm_neon_random_u64x1());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_uint64x1_t a = simde_uint64x1_from_private(a_);
    simde_uint64x1_t b = simde_uint64x1_from_private(b_);

    simde_uint64x1_t r = simde_vtst_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtstq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { -INT8_C(   4),  INT8_C(  75), -INT8_C(  89), -INT8_C(  82), -INT8_C(  39),  INT8_C(  33),  INT8_C(  86), -INT8_C(  81),
         INT8_C(  87), -INT8_C(  64),  INT8_C(  68), -INT8_C(  88),  INT8_C( 116), -INT8_C(  54), -INT8_C( 114),  INT8_C(   9) },
      {      INT8_MIN,  INT8_C( 113),  INT8_C(  88),  INT8_C(  81),  INT8_C( 119), -INT8_C(  34), -INT8_C(  85),  INT8_C(  80),
        -INT8_C(  15),  INT8_C(  56), -INT8_C( 114),  INT8_C(  87), -INT8_C(  11),  INT8_C(  53), -INT8_C( 104), -INT8_C(  14) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  45), -INT8_C(  61), -INT8_C(   5), -INT8_C(  23), -INT8_C(  95),  INT8_C(  11), -INT8_C(  11), -INT8_C( 110),
        -INT8_C(  33), -INT8_C(  15), -INT8_C(  28),  INT8_C(  60), -INT8_C(  72), -INT8_C( 126), -INT8_C( 110),  INT8_C(   7) },
      { -INT8_C(  94), -INT8_C(  99), -INT8_C( 108),  INT8_C(  22), -INT8_C(  53), -INT8_C(  12), -INT8_C(  32), -INT8_C(  71),
        -INT8_C( 103),  INT8_C(  14),  INT8_C(  27), -INT8_C(  61), -INT8_C(  53), -INT8_C( 122),  INT8_C( 109), -INT8_C(   8) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  39), -INT8_C( 101),  INT8_C( 125), -INT8_C(  14),  INT8_C( 122), -INT8_C( 125), -INT8_C(  85),  INT8_C( 101),
        -INT8_C( 111),  INT8_C( 121), -INT8_C(  19),  INT8_C(  92),  INT8_C(  77),  INT8_C(  90),  INT8_C(  32), -INT8_C( 105) },
      { -INT8_C(  61), -INT8_C(  14), -INT8_C( 126), -INT8_C(  45), -INT8_C( 123),  INT8_C(   0), -INT8_C(  62), -INT8_C( 102),
         INT8_C( 104), -INT8_C( 122),  INT8_C( 104),  INT8_C(  82),  INT8_C(  16),  INT8_C( 112), -INT8_C(  33),  INT8_C(  55) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(  31),  INT8_C(   2),  INT8_C(  38), -INT8_C(  65), -INT8_C(  52),  INT8_C( 102),  INT8_C(  89),  INT8_C( 107),
        -INT8_C(  20), -INT8_C(  62), -INT8_C(  66), -INT8_C(   4),  INT8_C(  12), -INT8_C(  99),  INT8_C(  51), -INT8_C(  46) },
      {  INT8_C(  30),  INT8_C(  93), -INT8_C(  39),  INT8_C(  35),  INT8_C(  51), -INT8_C(  98), -INT8_C(  71), -INT8_C(  49),
         INT8_C(  80), -INT8_C(  85), -INT8_C(  72),  INT8_C(  92), -INT8_C(  13),  INT8_C(  56),  INT8_C(  44),  INT8_C(  45) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C( 104),  INT8_C(  73),  INT8_C(  69),  INT8_C(  50), -INT8_C(  18),  INT8_C(  61),  INT8_C(  16),  INT8_C(  62),
        -INT8_C(  42),  INT8_C( 105), -INT8_C(  61), -INT8_C(  99), -INT8_C(  95),  INT8_C(  76), -INT8_C(  54), -INT8_C(  14) },
      { -INT8_C( 105), -INT8_C(  74),  INT8_C(  25), -INT8_C(  51), -INT8_C(   5), -INT8_C(  62), -INT8_C(  17),  INT8_C(   3),
         INT8_C(  41),  INT8_C(  13),  INT8_C(  60),  INT8_C(  45),  INT8_C(  94), -INT8_C(  77),  INT8_C(  79),  INT8_C(  13) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C( 100), -INT8_C(  97), -INT8_C(  63),  INT8_C(  86),  INT8_C(  97), -INT8_C(  28),  INT8_C(  89), -INT8_C( 118),
        -INT8_C(  15), -INT8_C(  72), -INT8_C(  73),  INT8_C(  79),  INT8_C(  20),  INT8_C(   6),  INT8_C(  93), -INT8_C(  71) },
      { -INT8_C( 101),  INT8_C(  76),  INT8_C(  62),  INT8_C(  47), -INT8_C(  19),  INT8_C( 109),  INT8_C( 108), -INT8_C(  10),
         INT8_C(  55),  INT8_C(  71), -INT8_C(  95), -INT8_C(  56), -INT8_C(  21),  INT8_C(  39), -INT8_C(  16),  INT8_C(  70) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C(  77),  INT8_C(  94),  INT8_C(  57), -INT8_C(  96), -INT8_C(  53), -INT8_C(  91), -INT8_C(  38),  INT8_C(   3),
        -INT8_C(  20), -INT8_C(  48), -INT8_C(  53), -INT8_C(  40),  INT8_C(  95), -INT8_C(  68),  INT8_C(  30),  INT8_C(  37) },
      { -INT8_C(  95), -INT8_C(  70),  INT8_C(  76),  INT8_C( 107), -INT8_C(  81), -INT8_C(   3),  INT8_C(  37),  INT8_C(  57),
         INT8_C( 101),  INT8_C(  47),  INT8_C(  13), -INT8_C(  45), -INT8_C( 106),  INT8_C(  45), -INT8_C(  35),  INT8_C(  74) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  88), -INT8_C(  14), -INT8_C(  93),  INT8_C(   7),  INT8_C( 112),  INT8_C(  73), -INT8_C(  24), -INT8_C(  73),
         INT8_C(  66),  INT8_C( 103), -INT8_C(  65),  INT8_C(  67), -INT8_C(  55), -INT8_C( 100),  INT8_C(  35),  INT8_C(   6) },
      { -INT8_C(  77),  INT8_C(  13),  INT8_C(  92),  INT8_C( 111), -INT8_C( 113), -INT8_C(  74),  INT8_C(  23),  INT8_C(  72),
        -INT8_C(  37), -INT8_C( 104),  INT8_C(  97), -INT8_C(  68),  INT8_C(  54), -INT8_C(  98),  INT8_C(  62), -INT8_C( 113) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vtstq_s8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_private a_ = simde_int8x16_to_private(simde_test_arm_neon_random_i8x16());
    simde_int8x16_private b_ = simde_int8x16_to_private(simde_test_arm_neon_random_i8x16());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_int8x16_t a = simde_int8x16_from_private(a_);
    simde_int8x16_t b = simde_int8x16_from_private(b_);

    simde_uint8x16_t r = simde_vtstq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtstq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 15409), -INT16_C(  4795), -INT16_C(  7107), -INT16_C( 17315), -INT16_C( 32198), -INT16_C( 14318),  INT16_C(  2859),  INT16_C( 31103) },
      {  INT16_C( 30163),  INT16_C( 31895), -INT16_C( 30120), -INT16_C(  7879),  INT16_C( 26743),  INT16_C( 14317), -INT16_C( 29989),  INT16_C(  3276) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 23210),  INT16_C(  1163),  INT16_C(  2660),  INT16_C( 14206),  INT16_C(  5503), -INT16_C( 10317), -INT16_C(  4705),  INT16_C(  6072) },
      { -INT16_C( 23211),  INT16_C( 12622),  INT16_C(  6960), -INT16_C(  2499),  INT16_C( 14125),  INT16_C(  9210), -INT16_C( 18035),  INT16_C( 26196) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 25342), -INT16_C( 25279), -INT16_C(  1713),  INT16_C( 29889),  INT16_C( 22109), -INT16_C( 12331),  INT16_C( 20077),  INT16_C( 19397) },
      { -INT16_C( 16566), -INT16_C( 10386), -INT16_C( 15495), -INT16_C( 29890), -INT16_C( 22110), -INT16_C( 29694), -INT16_C( 20078), -INT16_C( 28426) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C(  8987),  INT16_C(   926),  INT16_C( 25839),  INT16_C( 14670), -INT16_C( 18396), -INT16_C(  3153), -INT16_C( 22314),  INT16_C(  8744) },
      {  INT16_C( 10999), -INT16_C( 30290), -INT16_C( 23333), -INT16_C(  4583),  INT16_C( 18395),  INT16_C(  3152),  INT16_C( 22313),  INT16_C(  3803) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C(  2972), -INT16_C( 25698), -INT16_C( 14662), -INT16_C( 20035),  INT16_C( 27632), -INT16_C( 13253),  INT16_C( 21520), -INT16_C( 24109) },
      {  INT16_C(  2971), -INT16_C( 15113), -INT16_C( 11422), -INT16_C( 27182), -INT16_C(  7347),  INT16_C( 11191),  INT16_C(  4674),  INT16_C( 24108) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 16241),  INT16_C( 12621),  INT16_C(  1912),  INT16_C(  5149),  INT16_C(  5138),  INT16_C( 29912), -INT16_C( 21529),  INT16_C(   151) },
      { -INT16_C( 16242), -INT16_C( 11937), -INT16_C( 29486),  INT16_C( 20527),  INT16_C( 10326), -INT16_C(  6265),  INT16_C( 28894), -INT16_C(   152) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C(  1694),  INT16_C( 19011), -INT16_C(  3881),  INT16_C( 13182), -INT16_C( 27077), -INT16_C(  8188),  INT16_C( 13162), -INT16_C(  6737) },
      { -INT16_C( 18597),  INT16_C( 14759),  INT16_C(  3880), -INT16_C( 17352),  INT16_C( 27076), -INT16_C( 32311), -INT16_C(  5449),  INT16_C(  6736) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 16448),  INT16_C(  7960), -INT16_C(   270), -INT16_C( 13051), -INT16_C( 24268), -INT16_C(  8826), -INT16_C( 16478),  INT16_C( 26266) },
      {  INT16_C( 25384), -INT16_C(  7961),  INT16_C( 14158),  INT16_C( 13050),  INT16_C( 24267), -INT16_C( 21574),  INT16_C( 30272),  INT16_C(   409) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vtstq_s16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_private a_ = simde_int16x8_to_private(simde_test_arm_neon_random_i16x8());
    simde_int16x8_private b_ = simde_int16x8_to_private(simde_test_arm_neon_random_i16x8());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_int16x8_t a = simde_int16x8_from_private(a_);
    simde_int16x8_t b = simde_int16x8_from_private(b_);

    simde_uint16x8_t r = simde_vtstq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtstq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1407376814), -INT32_C(  1356235838), -INT32_C(  1757797231),  INT32_C(   256404884) },
      {  INT32_C(   176509125), -INT32_C(  2017860982), -INT32_C(  2045646060),  INT32_C(  2051097384) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1809273049),  INT32_C(   134353524),  INT32_C(  1159154303),  INT32_C(   625974427) },
      { -INT32_C(  1834219394),  INT32_C(   471383540),  INT32_C(  1721129216), -INT32_C(  1852916296) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   141951368), -INT32_C(  2010725056), -INT32_C(  1157002436), -INT32_C(  2008173164) },
      {  INT32_C(  1923376754),  INT32_C(  2010725055),  INT32_C(    67725303),  INT32_C(  1166345677) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   349079122),  INT32_C(   503604971),  INT32_C(  1629615087), -INT32_C(  1055941776) },
      { -INT32_C(   141513473), -INT32_C(   503604972), -INT32_C(  1557692001),  INT32_C(  1055941775) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(  1249627995), -INT32_C(  1688291285),  INT32_C(  1630895713),  INT32_C(  1062782251) },
      { -INT32_C(    31435937),  INT32_C(  1688291284), -INT32_C(  1985834581),  INT32_C(   225168306) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(   445119869),  INT32_C(  1266168829), -INT32_C(   756375949), -INT32_C(  1569528026) },
      { -INT32_C(    30772910), -INT32_C(  1266168830),  INT32_C(   834794135),  INT32_C(  1569528025) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(   642156723),  INT32_C(   543444986),  INT32_C(   499373623),  INT32_C(   999032633) },
      {  INT32_C(  1794053075), -INT32_C(   543444987), -INT32_C(   499373624), -INT32_C(   495092177) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   792920563),  INT32_C(    62726602), -INT32_C(    62961368),  INT32_C(  1121172021) },
      { -INT32_C(  1488977185),  INT32_C(  1519025195),  INT32_C(     3934202), -INT32_C(  1121172022) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vtstq_s32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_private a_ = simde_int32x4_to_private(simde_test_arm_neon_random_i32x4());
    simde_int32x4_private b_ = simde_int32x4_to_private(simde_test_arm_neon_random_i32x4());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_int32x4_t a = simde_int32x4_from_private(a_);
    simde_int32x4_t b = simde_int32x4_from_private(b_);

    simde_uint32x4_t r = simde_vtstq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtstq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 6906564504408707199), -INT64_C( 1146050713782097844) },
      {  INT64_C( 6906564504408707198),  INT64_C( 7871827673557111993) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { -INT64_C( 9072437593107422918),  INT64_C( 8307808349814397871) },
      { -INT64_C( 1128897749981389977), -INT64_C( 8307808349814397872) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { {  INT64_C( 3448291084656666900), -INT64_C( 4475145380862654405) },
      { -INT64_C( 3448291084656666901),  INT64_C( 4475145380862654404) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { {  INT64_C( 7730266204185906066), -INT64_C( 6692627503882292371) },
      {  INT64_C(  278832263600842306), -INT64_C( 5609719181803134700) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 4259197047024433569),  INT64_C( 6126162669054319166) },
      {  INT64_C( 7757174925230701543),  INT64_C( 1960548500776339251) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 1713351143557313590), -INT64_C( 4878520122427607347) },
      { -INT64_C( 1713351143557313591), -INT64_C( 3458717455958101682) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { {  INT64_C( 7016167619831180015), -INT64_C( 6460363201520064191) },
      { -INT64_C( 6591043928234225762),  INT64_C( 1413314601794032747) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { -INT64_C( 3349850824658449413), -INT64_C( 6384525313472305283) },
      {  INT64_C( 5642723914519993458), -INT64_C( 9204180589598903705) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vtstq_s64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_private a_ = simde_int64x2_to_private(simde_test_arm_neon_random_i64x2());
    simde_int64x2_private b_ = simde_int64x2_to_private(simde_test_arm_neon_random_i64x2());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_int64x2_t a = simde_int64x2_from_private(a_);
    simde_int64x2_t b = simde_int64x2_from_private(b_);

    simde_uint64x2_t r = simde_vtstq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtstq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(189), UINT8_C(210), UINT8_C(102), UINT8_C(249), UINT8_C(193), UINT8_C(191), UINT8_C(107), UINT8_C( 96),
        UINT8_C( 75), UINT8_C( 43), UINT8_C( 42), UINT8_C(225), UINT8_C(222), UINT8_C(196), UINT8_C(189), UINT8_C( 32) },
      { UINT8_C( 96), UINT8_C( 45), UINT8_C(153), UINT8_C(254), UINT8_C(  8), UINT8_C( 64), UINT8_C(118), UINT8_C(199),
        UINT8_C(204), UINT8_C(246), UINT8_C(134), UINT8_C(155), UINT8_C( 33), UINT8_C( 24), UINT8_C(140), UINT8_C(223) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 29), UINT8_C(246), UINT8_C( 33), UINT8_C(126), UINT8_C( 54), UINT8_C(225), UINT8_C(133), UINT8_C(158),
        UINT8_C(215), UINT8_C( 11), UINT8_C(223), UINT8_C(175), UINT8_C( 35), UINT8_C(130), UINT8_C(215), UINT8_C( 32) },
      { UINT8_C(226), UINT8_C(175), UINT8_C(222), UINT8_C(129), UINT8_C(243), UINT8_C(252), UINT8_C(107), UINT8_C( 97),
        UINT8_C( 68), UINT8_C( 54), UINT8_C( 32), UINT8_C( 80), UINT8_C(190), UINT8_C(125), UINT8_C(188), UINT8_C(116) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(170), UINT8_C(226), UINT8_C(213), UINT8_C(163), UINT8_C(222), UINT8_C( 64), UINT8_C(196), UINT8_C( 34),
        UINT8_C(158), UINT8_C(211), UINT8_C(114), UINT8_C( 53), UINT8_C( 80), UINT8_C( 46), UINT8_C(169), UINT8_C(196) },
      { UINT8_C( 85), UINT8_C(218), UINT8_C(109), UINT8_C( 92), UINT8_C(145), UINT8_C( 25), UINT8_C( 59), UINT8_C( 82),
        UINT8_C( 97), UINT8_C( 18), UINT8_C( 55), UINT8_C(211), UINT8_C(192), UINT8_C( 59), UINT8_C( 40), UINT8_C( 30) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(109), UINT8_C(119), UINT8_C( 34), UINT8_C(254), UINT8_C(144), UINT8_C(172), UINT8_C( 80), UINT8_C(219),
        UINT8_C(113), UINT8_C(135), UINT8_C(197), UINT8_C(127), UINT8_C(195), UINT8_C(140), UINT8_C(157), UINT8_C(225) },
      { UINT8_C(234), UINT8_C( 13), UINT8_C(221), UINT8_C( 40), UINT8_C( 47), UINT8_C(252), UINT8_C(221), UINT8_C( 36),
        UINT8_C(142), UINT8_C(198), UINT8_C(105), UINT8_C( 78), UINT8_C( 89), UINT8_C(115), UINT8_C( 99), UINT8_C(198) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(210), UINT8_C( 29), UINT8_C(  3), UINT8_C(152), UINT8_C( 26), UINT8_C( 13), UINT8_C( 17), UINT8_C(152),
        UINT8_C(212), UINT8_C( 37), UINT8_C( 57), UINT8_C( 73), UINT8_C(152), UINT8_C( 89), UINT8_C( 65), UINT8_C(142) },
      { UINT8_C( 45), UINT8_C(183), UINT8_C(252), UINT8_C(174), UINT8_C(203), UINT8_C(104), UINT8_C(238), UINT8_C(103),
        UINT8_C(152), UINT8_C(172), UINT8_C(198), UINT8_C(182), UINT8_C(  8), UINT8_C(  6), UINT8_C(190), UINT8_C(113) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(154), UINT8_C(  2), UINT8_C( 17), UINT8_C(158), UINT8_C(106),    UINT8_MAX, UINT8_C(206), UINT8_C( 32),
        UINT8_C(171), UINT8_C(160), UINT8_C(185), UINT8_C(180), UINT8_C(167), UINT8_C(119), UINT8_C( 37), UINT8_C( 58) },
      { UINT8_C(101), UINT8_C( 47), UINT8_C(  9), UINT8_C( 97), UINT8_C(244), UINT8_C(239), UINT8_C( 49), UINT8_C(223),
        UINT8_C(203), UINT8_C( 46), UINT8_C( 99), UINT8_C(  0), UINT8_C( 30), UINT8_C(105), UINT8_C( 98), UINT8_C(197) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 66), UINT8_C(179), UINT8_C(247), UINT8_C(207), UINT8_C(161), UINT8_C( 30), UINT8_C(250), UINT8_C(239),
        UINT8_C(140), UINT8_C(223), UINT8_C(231), UINT8_C( 78), UINT8_C(198), UINT8_C(113), UINT8_C( 21), UINT8_C( 50) },
      { UINT8_C(189), UINT8_C( 76), UINT8_C(  8), UINT8_C( 48), UINT8_C( 94), UINT8_C(225), UINT8_C( 78), UINT8_C( 16),
        UINT8_C(115), UINT8_C( 32), UINT8_C(106), UINT8_C(124), UINT8_C( 23), UINT8_C(142), UINT8_C(234), UINT8_C( 62) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(217), UINT8_C(  4), UINT8_C(105), UINT8_C(248), UINT8_C(176), UINT8_C(169), UINT8_C(  9),    UINT8_MAX,
        UINT8_C( 77), UINT8_C(115), UINT8_C(136), UINT8_C(100), UINT8_C(  1), UINT8_C(108), UINT8_C(162), UINT8_C( 13) },
      { UINT8_C( 38), UINT8_C(251), UINT8_C(150), UINT8_C(226), UINT8_C( 79), UINT8_C( 86), UINT8_C(206), UINT8_C(  0),
        UINT8_C(253), UINT8_C(  9), UINT8_C(119), UINT8_C(239), UINT8_C( 87), UINT8_C( 33), UINT8_C(158), UINT8_C(242) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vtstq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_private a_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());
    simde_uint8x16_private b_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_uint8x16_t a = simde_uint8x16_from_private(a_);
    simde_uint8x16_t b = simde_uint8x16_from_private(b_);

    simde_uint8x16_t r = simde_vtstq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtstq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(11577), UINT16_C(56621), UINT16_C(19835), UINT16_C(50703), UINT16_C(34400), UINT16_C( 4561), UINT16_C(39613), UINT16_C(15587) },
      { UINT16_C(53958), UINT16_C( 4816), UINT16_C(45700), UINT16_C(14816), UINT16_C(31135), UINT16_C(  383), UINT16_C(25922), UINT16_C(59203) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(15330), UINT16_C(19346), UINT16_C(18495), UINT16_C(57955), UINT16_C(40927), UINT16_C(40472), UINT16_C(63692), UINT16_C(27863) },
      { UINT16_C(22130), UINT16_C(46189), UINT16_C(45244), UINT16_C( 7580), UINT16_C(24608), UINT16_C(40129), UINT16_C(11060), UINT16_C( 5872) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(50311), UINT16_C(21589), UINT16_C(11708), UINT16_C(20181), UINT16_C(45343), UINT16_C(16355), UINT16_C(32733), UINT16_C(48330) },
      { UINT16_C( 7903), UINT16_C( 5274), UINT16_C(35402), UINT16_C(45354), UINT16_C(20192), UINT16_C(32087), UINT16_C(  956), UINT16_C(17205) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(46974), UINT16_C(24954), UINT16_C(55060), UINT16_C(62559), UINT16_C(63990), UINT16_C(16392), UINT16_C(12931), UINT16_C(25585) },
      { UINT16_C(18561), UINT16_C(15841), UINT16_C( 5708), UINT16_C( 4992), UINT16_C( 6304), UINT16_C(22679), UINT16_C(19055), UINT16_C(62611) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(61613), UINT16_C(12571), UINT16_C(59498), UINT16_C(41876), UINT16_C(30036), UINT16_C(41184), UINT16_C(24971), UINT16_C(11444) },
      { UINT16_C(19321), UINT16_C(59524), UINT16_C( 6037), UINT16_C(30172), UINT16_C(12836), UINT16_C( 2409), UINT16_C(20966), UINT16_C(38116) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(35911), UINT16_C(23040), UINT16_C(46152), UINT16_C(64204), UINT16_C( 2560), UINT16_C(38314), UINT16_C(34337), UINT16_C(17930) },
      { UINT16_C(29624), UINT16_C(40783), UINT16_C(13508), UINT16_C( 1331), UINT16_C(63539), UINT16_C(16233), UINT16_C(28753), UINT16_C( 8351) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(26091), UINT16_C(11753), UINT16_C(62610), UINT16_C(19059), UINT16_C(65111), UINT16_C( 1021), UINT16_C(40188), UINT16_C(61615) },
      { UINT16_C(39444), UINT16_C(26217), UINT16_C( 2058), UINT16_C(25222), UINT16_C(  424), UINT16_C(64514), UINT16_C(25347), UINT16_C( 3920) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 1195), UINT16_C(43093), UINT16_C( 1440), UINT16_C(12697), UINT16_C(65165), UINT16_C(38860), UINT16_C(58797), UINT16_C(14857) },
      { UINT16_C(64340), UINT16_C(22442), UINT16_C(64095), UINT16_C(52838), UINT16_C(41524), UINT16_C(25039), UINT16_C( 6738), UINT16_C(50678) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vtstq_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_private a_ = simde_uint16x8_to_private(simde_test_arm_neon_random_u16x8());
    simde_uint16x8_private b_ = simde_uint16x8_to_private(simde_test_arm_neon_random_u16x8());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_uint16x8_t a = simde_uint16x8_from_private(a_);
    simde_uint16x8_t b = simde_uint16x8_from_private(b_);

    simde_uint16x8_t r = simde_vtstq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtstq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3039705452), UINT32_C(2634367223), UINT32_C(3690212691), UINT32_C( 322215036) },
      { UINT32_C( 809289908), UINT32_C(1288906048), UINT32_C( 604754604), UINT32_C( 686277563) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3108576102), UINT32_C(2375368264), UINT32_C(3778502956), UINT32_C(1116440472) },
      { UINT32_C(1186391193), UINT32_C(1919599031), UINT32_C(2157597316), UINT32_C(3178526823) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3242058821), UINT32_C( 708879250), UINT32_C(1799599313), UINT32_C( 852380359) },
      { UINT32_C(1052908474), UINT32_C(3586088045), UINT32_C( 798110676), UINT32_C(3442586936) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2257597108), UINT32_C(2146554854), UINT32_C(2278466253), UINT32_C( 734433469) },
      { UINT32_C(3238036973), UINT32_C(4042298040), UINT32_C(1287463239), UINT32_C( 755125624) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(4166130751), UINT32_C(  62567238), UINT32_C( 825131076), UINT32_C(3186765317) },
      { UINT32_C( 128836544), UINT32_C(2102618628), UINT32_C( 933909943), UINT32_C(1302158823) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2034907445), UINT32_C(3198843321), UINT32_C(4138918391), UINT32_C(2221877376) },
      { UINT32_C(1241629587), UINT32_C(   8497944), UINT32_C( 156048904), UINT32_C(3595619488) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3145660948), UINT32_C(3215279200), UINT32_C(3046871842), UINT32_C(1862245718) },
      { UINT32_C(1366196552), UINT32_C(1079688095), UINT32_C(2383850376), UINT32_C(1515021638) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3876403653), UINT32_C(3559910682), UINT32_C(2391841606), UINT32_C(1362257174) },
      { UINT32_C(1123826362), UINT32_C( 735056613), UINT32_C(3615825527), UINT32_C(2932710121) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vtstq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_private a_ = simde_uint32x4_to_private(simde_test_arm_neon_random_u32x4());
    simde_uint32x4_private b_ = simde_uint32x4_to_private(simde_test_arm_neon_random_u32x4());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_uint32x4_t a = simde_uint32x4_from_private(a_);
    simde_uint32x4_t b = simde_uint32x4_from_private(b_);

    simde_uint32x4_t r = simde_vtstq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtstq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(10528700444459983810), UINT64_C( 1761940834975752996) },
      { UINT64_C( 9932437595201082497), UINT64_C(16684803238733798619) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 5091877151210656604), UINT64_C( 1066874122888010824) },
      { UINT64_C(13354866922498895011), UINT64_C(11382078829017005141) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { UINT64_C( 9063377370790874867), UINT64_C( 6050081726145094505) },
      { UINT64_C(14319394822410993894), UINT64_C(12396662347564457110) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(10412951015911017111), UINT64_C( 1106603098493244346) },
      { UINT64_C( 3239137215810657310), UINT64_C(17340140975216307269) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 3135671028341776206), UINT64_C( 2938365675075114183) },
      { UINT64_C(  982391747816647171), UINT64_C( 4155543630013790838) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 8944818937377997577), UINT64_C(10805608432536573718) },
      { UINT64_C( 4412910401907889313), UINT64_C( 7641135641172977897) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(11115115817610934008), UINT64_C( 1547521650231446886) },
      { UINT64_C(  616655974268410409), UINT64_C( 5913741270551752546) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 1961969470644239469), UINT64_C(17422221396708292660) },
      { UINT64_C(17658369120158031761), UINT64_C( 2933273528357185933) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vtstq_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_private a_ = simde_uint64x2_to_private(simde_test_arm_neon_random_u64x2());
    simde_uint64x2_private b_ = simde_uint64x2_to_private(simde_test_arm_neon_random_u64x2());

    /* Make some complements which is unlikely to happen by accident. */
    for (size_t j = 0 ; j < (sizeof(a_.values) / sizeof(a_.values[0])) ; j++) {
      if (rand() < (RAND_MAX / 3)) a_.values[j] = ~b_.values[j];
    }

    simde_uint64x2_t a = simde_uint64x2_from_private(a_);
    simde_uint64x2_t b = simde_uint64x2_from_private(b_);

    simde_uint64x2_t r = simde_vtstq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtstd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    uint64_t r;
  } test_vec[] = {
    {  INT64_C( 4263098949942533054),
       INT64_C( 5479381541330616536),
                          UINT64_MAX },
    {  INT64_C( 3604778241928819734),
      -INT64_C( 2450150474635664399),
                          UINT64_MAX },
    {  INT64_C( 1427782075273423277),
       INT64_C( 7802262423333415296),
                          UINT64_MAX },
    {  INT64_C( 3499787564841730216),
      -INT64_C( 6494717363095492639),
                          UINT64_MAX },
    {  INT64_C( 3897878349593851338),
       INT64_C( 2194793941280309940),
                          UINT64_MAX },
    { -INT64_C( 3573308421618979079),
       INT64_C( 8454290778876709557),
                          UINT64_MAX },
    {  INT64_C( 5606298299515178721),
       INT64_C( 8172006336584154836),
                          UINT64_MAX },
    { -INT64_C( 6146266748402669830),
       INT64_C( 1278366088808661917),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vtstd_s64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    uint64_t r = simde_vtstd_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vtstd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C(11321897497915832121),
      UINT64_C( 4349438488977307251),
                          UINT64_MAX },
    { UINT64_C(13102333714713675061),
      UINT64_C( 1268531679954021466),
                          UINT64_MAX },
    { UINT64_C( 3122968954254082801),
      UINT64_C(14120881109698231929),
                          UINT64_MAX },
    { UINT64_C( 5351615496173984119),
      UINT64_C(17065668390608454125),
                          UINT64_MAX },
    { UINT64_C( 3860708291238082993),
      UINT64_C(10632126926853024059),
                          UINT64_MAX },
    { UINT64_C( 2826966693956450560),
      UINT64_C( 3427452066105855912),
                          UINT64_MAX },
    { UINT64_C( 8100615858010142586),
      UINT64_C( 4792891319741144020),
                          UINT64_MAX },
    { UINT64_C(13087301141508891966),
      UINT64_C(14207705962035907198),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vtstd_u64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r = simde_vtstd_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vtst_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtst_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtst_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtst_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vtst_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtst_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtst_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtst_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vtstq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtstq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtstq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtstq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vtstq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vtstq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vtstq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vtstq_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vtstd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vtstd_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
