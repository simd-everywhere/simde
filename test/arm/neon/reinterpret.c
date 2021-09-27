#define SIMDE_TEST_ARM_NEON_INSN reinterpret

#include "test-neon.h"
#include "../../../simde/arm/neon/reinterpret.h"

static int
test_simde_vreinterpret_f32_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
  } test_vec[] = {
    { { -INT8_C(  42),  INT8_C(  92),  INT8_C(  93),  INT8_C(  70),  INT8_C(  89), -INT8_C(  37), -INT8_C( 103), -INT8_C(  92) },
 },
    { {  INT8_C(  40), -INT8_C(  95), -INT8_C(  44),  INT8_C(  67), -INT8_C(  63), -INT8_C(  92), -INT8_C( 108),  INT8_C(  10) },
 },
    { {  INT8_C(  37),  INT8_C( 114), -INT8_C(   8), -INT8_C( 112), -INT8_C(  60), -INT8_C(  12), -INT8_C(  68), -INT8_C(  73) },
 },
    { { -INT8_C(  40), -INT8_C(  11), -INT8_C(  75),  INT8_C(  51), -INT8_C( 124), -INT8_C(  99),  INT8_C( 109),  INT8_C(  90) },
 },
    { { -INT8_C(   7), -INT8_C(  54), -INT8_C(  95),  INT8_C(  82), -INT8_C(  91),  INT8_C(  58), -INT8_C(  10), -INT8_C(  50) },
 },
    { { -INT8_C(  37), -INT8_C(  54),  INT8_C(  17), -INT8_C( 100),  INT8_C( 110), -INT8_C(  91), -INT8_C(  90), -INT8_C( 108) },
 },
    { {  INT8_C(  23), -INT8_C(  97),  INT8_C(  36), -INT8_C(  36), -INT8_C( 109), -INT8_C(  31), -INT8_C( 109),  INT8_C( 107) },
 },
    { { -INT8_C(  42),  INT8_C(  73), -INT8_C(  97),  INT8_C(  91), -INT8_C(  26),  INT8_C(  12), -INT8_C(  75), -INT8_C(  33) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_float32x2_t r = simde_vreinterpret_f32_s8(a);
    simde_float32x2_private r_ = simde_float32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f64_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
  } test_vec[] = {
    { { -INT8_C(   5),  INT8_C( 109), -INT8_C(  72), -INT8_C(  54),  INT8_C(  91), -INT8_C(   8),  INT8_C(  66),  INT8_C( 119) },
 },
    { {  INT8_C( 115),  INT8_C(  82),  INT8_C(  13), -INT8_C(  69),  INT8_C(  12), -INT8_C(  98),  INT8_C(  10),  INT8_C( 113) },
 },
    { { -INT8_C(  12),  INT8_C(  18),  INT8_C(  58),  INT8_C(  77), -INT8_C(  60),  INT8_C(  73),  INT8_C(  48),  INT8_C(  23) },
 },
    { { -INT8_C(  71),      INT8_MAX, -INT8_C( 101),  INT8_C(  99),  INT8_C(  32), -INT8_C(  47),  INT8_C(  84),  INT8_C(  28) },
 },
    { {  INT8_C(  62),  INT8_C(  13), -INT8_C(  26), -INT8_C( 102),  INT8_C(   5),  INT8_C(  41),  INT8_C(  17),  INT8_C( 120) },
 },
    { {  INT8_C( 123),  INT8_C(  30),  INT8_C(  51), -INT8_C( 121), -INT8_C(  68),  INT8_C(  61), -INT8_C(   8), -INT8_C(  80) },
 },
    { {  INT8_C(  79),  INT8_C(  50), -INT8_C(   3),  INT8_C(  19),  INT8_C( 124),  INT8_C(  46),  INT8_C(  42),  INT8_C(  53) },
 },
    { { -INT8_C(  83), -INT8_C(  59), -INT8_C( 104), -INT8_C(  51), -INT8_C( 106), -INT8_C(  19), -INT8_C(  23), -INT8_C(  43) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_float64x1_t r = simde_vreinterpret_f64_s8(a);
    simde_float64x1_private r_ = simde_float64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s16_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
  } test_vec[] = {
    { { -INT8_C( 119),  INT8_C(  49),  INT8_C(  78),  INT8_C( 105), -INT8_C( 127), -INT8_C(  66), -INT8_C(  26), -INT8_C(  61) },
 },
    { {  INT8_C(  30), -INT8_C(  27), -INT8_C(  30),  INT8_C(  39),  INT8_C(  99),  INT8_C(  61), -INT8_C( 126), -INT8_C( 122) },
 },
    { { -INT8_C(  69), -INT8_C(   3),  INT8_C(  53),  INT8_C(  18),  INT8_C(  42), -INT8_C( 110), -INT8_C(  95),  INT8_C(  32) },
 },
    { {  INT8_C(  65),  INT8_C(  49),  INT8_C(  29),  INT8_C( 105),  INT8_C(  80), -INT8_C( 105), -INT8_C(  59), -INT8_C(  38) },
 },
    { { -INT8_C(  55),  INT8_C(  19),  INT8_C(  67),  INT8_C(  74), -INT8_C(  47),  INT8_C(  41),  INT8_C(  13), -INT8_C(  17) },
 },
    { {  INT8_C(  14), -INT8_C(  17),  INT8_C(  22),  INT8_C( 113),  INT8_C(  44), -INT8_C( 103), -INT8_C(   9), -INT8_C(  25) },
 },
    { { -INT8_C( 106),  INT8_C(  44), -INT8_C(   7), -INT8_C(  64), -INT8_C(  66), -INT8_C( 101), -INT8_C(  32),  INT8_C(   0) },
 },
    { { -INT8_C(  52), -INT8_C(   3),  INT8_C( 105),  INT8_C(  28), -INT8_C( 107),  INT8_C(  46), -INT8_C(  10),  INT8_C(  94) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_int16x4_t r = simde_vreinterpret_s16_s8(a);
    simde_int16x4_private r_ = simde_int16x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s32_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
  } test_vec[] = {
    { {  INT8_C(  34),  INT8_C(  75),  INT8_C(  84), -INT8_C(  29), -INT8_C(  85),  INT8_C(  72),  INT8_C(   5), -INT8_C(  60) },
 },
    { {  INT8_C( 105),  INT8_C(   5), -INT8_C(  90), -INT8_C(  42),  INT8_C(  51),  INT8_C(  40), -INT8_C(  85),  INT8_C(  88) },
 },
    { {  INT8_C( 100),  INT8_C( 114), -INT8_C(  58), -INT8_C(  66),  INT8_C( 110),  INT8_C(  62),  INT8_C(  12), -INT8_C(  14) },
 },
    { { -INT8_C(  56), -INT8_C(  14), -INT8_C( 105),  INT8_C( 107),  INT8_C(  56),  INT8_C( 104), -INT8_C(  65),  INT8_C(  90) },
 },
    { { -INT8_C(  77),  INT8_C(  19),  INT8_C(  61),  INT8_C(  94),  INT8_C(  91),  INT8_C(  66),  INT8_C(  34), -INT8_C(  60) },
 },
    { {  INT8_C(  72), -INT8_C(  56), -INT8_C( 102),  INT8_C( 123), -INT8_C(  15),  INT8_C(  69), -INT8_C(  44),  INT8_C(  85) },
 },
    { { -INT8_C(  72), -INT8_C( 102),  INT8_C(  20),  INT8_C(  38), -INT8_C(  40),  INT8_C(  32),  INT8_C(  25), -INT8_C(  96) },
 },
    { {  INT8_C(  18), -INT8_C(  80),  INT8_C(  11),  INT8_C(  74),  INT8_C(  24), -INT8_C(  54), -INT8_C(  92), -INT8_C(  53) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_int32x2_t r = simde_vreinterpret_s32_s8(a);
    simde_int32x2_private r_ = simde_int32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s64_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
  } test_vec[] = {
    { { -INT8_C( 102), -INT8_C(  98),  INT8_C(  81), -INT8_C(  77), -INT8_C(  94), -INT8_C(   9), -INT8_C(  74),  INT8_C(  34) },
 },
    { {  INT8_C( 104), -INT8_C(  72),  INT8_C( 117), -INT8_C(  60),  INT8_C(  71),  INT8_C(  68),  INT8_C(  51),  INT8_C(  73) },
 },
    { {  INT8_C(  17),  INT8_C(  79), -INT8_C(  67),  INT8_C(  89), -INT8_C(  92), -INT8_C(   5), -INT8_C(  54),  INT8_C(  76) },
 },
    { { -INT8_C( 117), -INT8_C(  98), -INT8_C(  82),  INT8_C( 106), -INT8_C(  80),  INT8_C(  15), -INT8_C(  30),  INT8_C(  74) },
 },
    { { -INT8_C(  83),  INT8_C(  51), -INT8_C(   2),  INT8_C(  79),  INT8_C(  43), -INT8_C(  76),  INT8_C( 114), -INT8_C( 109) },
 },
    { {  INT8_C( 109), -INT8_C(  25),  INT8_C(  87), -INT8_C(  76),  INT8_C(  44), -INT8_C( 117), -INT8_C(   3),  INT8_C(  61) },
 },
    { { -INT8_C(  38), -INT8_C(  69), -INT8_C( 105),  INT8_C( 126), -INT8_C(  74),  INT8_C(  97), -INT8_C(  53),  INT8_C(  65) },
 },
    { { -INT8_C(   1),  INT8_C( 121), -INT8_C(  85), -INT8_C(  81), -INT8_C( 120), -INT8_C( 115), -INT8_C(   6),  INT8_C(  53) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_int64x1_t r = simde_vreinterpret_s64_s8(a);
    simde_int64x1_private r_ = simde_int64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u8_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
  } test_vec[] = {
    { {  INT8_C(  73), -INT8_C(  58), -INT8_C(  54),  INT8_C(   0),      INT8_MAX, -INT8_C(  14), -INT8_C(  96),  INT8_C( 124) },
 },
    { {  INT8_C(  61), -INT8_C(  81), -INT8_C(  61),  INT8_C(  43),  INT8_C(  92),  INT8_C(  16), -INT8_C(  94),  INT8_C( 125) },
 },
    { { -INT8_C(  46),  INT8_C(  72), -INT8_C(  42),  INT8_C(  56),  INT8_C(   3),  INT8_C(  67), -INT8_C(  58), -INT8_C(  39) },
 },
    { {  INT8_C(  44), -INT8_C(  82),  INT8_C(  29), -INT8_C(  51),  INT8_C(  70),  INT8_C(  74), -INT8_C(  65), -INT8_C( 113) },
 },
    { {  INT8_C(  17), -INT8_C( 119), -INT8_C( 112), -INT8_C( 112),  INT8_C( 124),  INT8_C(  48),  INT8_C(  12), -INT8_C(  71) },
 },
    { { -INT8_C(  33), -INT8_C(  49), -INT8_C(  28),  INT8_C(  59), -INT8_C(  33), -INT8_C( 122), -INT8_C(  71), -INT8_C(  78) },
 },
    { { -INT8_C(  50), -INT8_C( 113), -INT8_C(  22), -INT8_C(  47), -INT8_C(  46), -INT8_C(  80), -INT8_C(  86), -INT8_C(   1) },
 },
    { {  INT8_C(  94), -INT8_C(  57), -INT8_C(  52), -INT8_C(  92),  INT8_C(  18), -INT8_C( 116),  INT8_C(  52),  INT8_C(  35) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_uint8x8_t r = simde_vreinterpret_u8_s8(a);
    simde_uint8x8_private r_ = simde_uint8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u16_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
  } test_vec[] = {
    { { -INT8_C(  44),  INT8_C(  17), -INT8_C(  26), -INT8_C(  99),  INT8_C(  57), -INT8_C(  92),  INT8_C(   3),  INT8_C(  58) },
 },
    { {  INT8_C(  16), -INT8_C(  90), -INT8_C( 123), -INT8_C( 127), -INT8_C(  28),  INT8_C(  59), -INT8_C(  66),  INT8_C(   8) },
 },
    { { -INT8_C( 117),  INT8_C(  95),  INT8_C( 102), -INT8_C(  39),  INT8_C(   9), -INT8_C( 100),  INT8_C(  76),  INT8_C(  94) },
 },
    { { -INT8_C(  50),  INT8_C(  29), -INT8_C(  46), -INT8_C( 119),  INT8_C(   8), -INT8_C(  74),  INT8_C(  98), -INT8_C(  36) },
 },
    { { -INT8_C(  57),  INT8_C(  72),  INT8_C( 122),  INT8_C(   0), -INT8_C(  19),  INT8_C( 125),  INT8_C(  58), -INT8_C(   3) },
 },
    { {  INT8_C(  35), -INT8_C(  65),  INT8_C( 126),  INT8_C(   8), -INT8_C(   6),  INT8_C(  60),  INT8_C(  16), -INT8_C( 122) },
 },
    { { -INT8_C( 101),  INT8_C( 118),  INT8_C(  95), -INT8_C(  92),  INT8_C(  18), -INT8_C(  85),  INT8_C(   2), -INT8_C(  31) },
 },
    { { -INT8_C(  55), -INT8_C(  43),  INT8_C( 106), -INT8_C(  47), -INT8_C( 117), -INT8_C(  52), -INT8_C(  83),  INT8_C(  82) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_uint16x4_t r = simde_vreinterpret_u16_s8(a);
    simde_uint16x4_private r_ = simde_uint16x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u32_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
  } test_vec[] = {
    { {  INT8_C(  74),  INT8_C(  41), -INT8_C(   7),  INT8_C(  78), -INT8_C(  65),  INT8_C(  66), -INT8_C(  17), -INT8_C(  70) },
 },
    { {  INT8_C(  81), -INT8_C(  71),  INT8_C(  49), -INT8_C( 102),  INT8_C(  15), -INT8_C(  59), -INT8_C(  56),  INT8_C(  99) },
 },
    { { -INT8_C(  40), -INT8_C(  40), -INT8_C(  17), -INT8_C(  13), -INT8_C(  46), -INT8_C(  41),  INT8_C(  71),  INT8_C(  66) },
 },
    { {  INT8_C(  40),  INT8_C(  64), -INT8_C(  25), -INT8_C( 112),  INT8_C(  50),  INT8_C(  85), -INT8_C(  27),  INT8_C( 124) },
 },
    { {  INT8_C( 126), -INT8_C(  34), -INT8_C(  53),  INT8_C(  61),  INT8_C(  32), -INT8_C(  70), -INT8_C(   9),  INT8_C( 113) },
 },
    { {  INT8_C( 116),  INT8_C(  41),  INT8_C(  11), -INT8_C( 125), -INT8_C(  18), -INT8_C(  44), -INT8_C(  25), -INT8_C(  58) },
 },
    { { -INT8_C(  84), -INT8_C(  42), -INT8_C(  70),      INT8_MAX, -INT8_C(  83),  INT8_C(   1), -INT8_C(  63), -INT8_C(  43) },
 },
    { {  INT8_C(  65), -INT8_C(  88),  INT8_C( 102),  INT8_C( 115), -INT8_C(   3),  INT8_C(  75), -INT8_C(  16),  INT8_C( 123) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_uint32x2_t r = simde_vreinterpret_u32_s8(a);
    simde_uint32x2_private r_ = simde_uint32x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u64_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
  } test_vec[] = {
    { {  INT8_C(  40),  INT8_C(  42),  INT8_C(  95),  INT8_C(  87),  INT8_C(  71), -INT8_C(  53), -INT8_C( 100),  INT8_C(  99) },
 },
    { {  INT8_C(  42), -INT8_C(  25),  INT8_C(  55),  INT8_C( 109), -INT8_C( 110), -INT8_C( 120), -INT8_C(  78), -INT8_C(   7) },
 },
    { { -INT8_C(  97), -INT8_C(   1), -INT8_C(  38),  INT8_C(  60),  INT8_C(  58),  INT8_C(  58),  INT8_C(  80),  INT8_C(  75) },
 },
    { {  INT8_C(  18),  INT8_C(  38), -INT8_C(  40),  INT8_C(   0), -INT8_C( 110),  INT8_C(  19),  INT8_C(  60), -INT8_C(  69) },
 },
    { {  INT8_C(  61), -INT8_C( 101),  INT8_C(  18), -INT8_C( 124),  INT8_C( 102), -INT8_C(  82), -INT8_C(  25), -INT8_C( 111) },
 },
    { { -INT8_C( 107),  INT8_C(  31), -INT8_C(   2),  INT8_C(  40), -INT8_C(  89), -INT8_C(  80),  INT8_C(  33),  INT8_C(  70) },
 },
    { { -INT8_C(  80), -INT8_C(   4), -INT8_C( 126), -INT8_C(  22),  INT8_C(  54), -INT8_C(  46),  INT8_C(  54),  INT8_C(  73) },
 },
    { { -INT8_C(   8),  INT8_C(  14),  INT8_C(  73), -INT8_C( 118),  INT8_C(  33), -INT8_C( 123),  INT8_C(  69),  INT8_C(  94) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_private a_ = simde_int8x8_to_private(a);
    simde_uint64x1_t r = simde_vreinterpret_u64_s8(a);
    simde_uint64x1_private r_ = simde_uint64x1_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f32_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
  } test_vec[] = {
    { {  INT8_C( 126), -INT8_C(  42),  INT8_C(  86), -INT8_C( 114), -INT8_C(  16),  INT8_C(  92), -INT8_C(  85),  INT8_C(  13),
        -INT8_C(  40),  INT8_C(   5),  INT8_C(  82),  INT8_C(  85),  INT8_C(  58),      INT8_MIN, -INT8_C( 124), -INT8_C( 105) },
 },
    { {  INT8_C(  11),  INT8_C(  67),  INT8_C(  88),  INT8_C(  58), -INT8_C(   6), -INT8_C(  66), -INT8_C(  54),  INT8_C(  93),
        -INT8_C(  80), -INT8_C(  34), -INT8_C(  77), -INT8_C(   9),  INT8_C( 108),  INT8_C(  83), -INT8_C(  44), -INT8_C(  22) },
 },
    { {  INT8_C(  41),  INT8_C(  42),  INT8_C( 120),  INT8_C(  26), -INT8_C( 122),  INT8_C(  35),  INT8_C(  39),  INT8_C(  95),
         INT8_C(  41),  INT8_C( 121), -INT8_C(  76),  INT8_C(  99), -INT8_C(   7),  INT8_C(  56), -INT8_C(   6),  INT8_C(   4) },
 },
    { {  INT8_C( 124),  INT8_C(  82),  INT8_C(  62),  INT8_C( 118),  INT8_C(  16),  INT8_C(   8), -INT8_C(  45), -INT8_C(  63),
        -INT8_C(  25), -INT8_C( 122), -INT8_C(  72),  INT8_C(  83), -INT8_C(  39), -INT8_C( 116),  INT8_C(  61),  INT8_C(   3) },
 },
    { { -INT8_C(  74), -INT8_C(  75),  INT8_C(  29),  INT8_C(  61), -INT8_C(  40),  INT8_C(  68), -INT8_C( 100),  INT8_C(   1),
        -INT8_C(  67),  INT8_C(  80),  INT8_C( 100), -INT8_C(  74), -INT8_C( 120),  INT8_C(  95), -INT8_C(  69),  INT8_C(   4) },
 },
    { { -INT8_C(  79), -INT8_C(   7),  INT8_C( 122), -INT8_C(  62),  INT8_C(   2),  INT8_C(  77), -INT8_C( 125), -INT8_C(  23),
        -INT8_C(  45),  INT8_C(  59),  INT8_C(  60), -INT8_C(  83), -INT8_C(  57),  INT8_C( 121), -INT8_C(  80),  INT8_C( 125) },
 },
    { {  INT8_C(  46), -INT8_C(  51), -INT8_C(  70),  INT8_C(   6),  INT8_C(  17),  INT8_C(  86),  INT8_C(   8), -INT8_C(  50),
        -INT8_C(  90),  INT8_C( 108), -INT8_C( 124),  INT8_C(  47), -INT8_C(  53),  INT8_C(  63),  INT8_C(  51),  INT8_C( 125) },
 },
    { {  INT8_C(  57), -INT8_C(  82),  INT8_C(  63),  INT8_C(  59), -INT8_C(   5), -INT8_C(  62),  INT8_C(  36), -INT8_C(  49),
        -INT8_C(   3),  INT8_C(  96),  INT8_C( 124), -INT8_C(  60), -INT8_C(  39),  INT8_C(  44),  INT8_C(  65),  INT8_C(   7) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_float32x4_t r = simde_vreinterpretq_f32_s8(a);
    simde_float32x4_private r_ = simde_float32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f64_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
  } test_vec[] = {
    { { -INT8_C(  26),  INT8_C(  77), -INT8_C(  93),  INT8_C(  31), -INT8_C(  92),  INT8_C(  89), -INT8_C( 113),  INT8_C(  91),
        -INT8_C( 124), -INT8_C(   5),  INT8_C(   6),  INT8_C( 118),  INT8_C(  47), -INT8_C(  29),  INT8_C(  24),  INT8_C(  83) },
 },
    { {  INT8_C(  14),  INT8_C(   2), -INT8_C( 123), -INT8_C( 119), -INT8_C(   9),  INT8_C( 101), -INT8_C(  52),  INT8_C(  85),
        -INT8_C( 102), -INT8_C(  80), -INT8_C( 112), -INT8_C(  37),  INT8_C(  68),  INT8_C(  37), -INT8_C(  82),  INT8_C(  42) },
 },
    { {  INT8_C( 114),  INT8_C(  81),  INT8_C(  73),  INT8_C(  22), -INT8_C(  85), -INT8_C(  40),  INT8_C( 114),  INT8_C(  47),
        -INT8_C(  45),  INT8_C( 120), -INT8_C(  91),  INT8_C(   3),  INT8_C(  91), -INT8_C(  66),  INT8_C(  86),  INT8_C( 106) },
 },
    { { -INT8_C(  64), -INT8_C(  37), -INT8_C(  13), -INT8_C(  72),  INT8_C(  64), -INT8_C(  65),  INT8_C(  13), -INT8_C(  37),
         INT8_C( 111), -INT8_C(  99), -INT8_C(  74), -INT8_C(  77), -INT8_C(  62),  INT8_C( 100), -INT8_C(  35),  INT8_C(  53) },
 },
    { { -INT8_C(  74),  INT8_C(  38),  INT8_C(  75),  INT8_C(  97), -INT8_C(   2), -INT8_C(  67), -INT8_C( 112), -INT8_C(  46),
         INT8_C(  53),  INT8_C(  53), -INT8_C(  43), -INT8_C( 111), -INT8_C(  13),  INT8_C(  43), -INT8_C(   5), -INT8_C(  76) },
 },
    { {  INT8_C(   6), -INT8_C(  18),  INT8_C( 108),  INT8_C(  70), -INT8_C(  83),  INT8_C( 121),  INT8_C(  33),  INT8_C(  29),
         INT8_C(  22), -INT8_C(  41), -INT8_C(  48), -INT8_C(  40),  INT8_C(  60), -INT8_C(  82),  INT8_C(  13), -INT8_C(  14) },
 },
    { { -INT8_C(  44),  INT8_C(  89),  INT8_C(  83), -INT8_C(  45),  INT8_C(  22), -INT8_C(  29), -INT8_C(  91),  INT8_C(  76),
         INT8_C(  24),  INT8_C( 122), -INT8_C(  35),  INT8_C(  12), -INT8_C(  91), -INT8_C(  40), -INT8_C(  64), -INT8_C(  85) },
 },
    { { -INT8_C(  58),  INT8_C(  44), -INT8_C(  15),  INT8_C( 115), -INT8_C(  91),  INT8_C(  19), -INT8_C( 112), -INT8_C(  69),
        -INT8_C(  22),  INT8_C(  97), -INT8_C( 109),  INT8_C(  38),  INT8_C(  15), -INT8_C(  95),  INT8_C(  24), -INT8_C(  29) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_float64x2_t r = simde_vreinterpretq_f64_s8(a);
    simde_float64x2_private r_ = simde_float64x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s16_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
  } test_vec[] = {
    { { -INT8_C( 120), -INT8_C(  31), -INT8_C(  33), -INT8_C(  41),  INT8_C(  89),  INT8_C(  93), -INT8_C(  91), -INT8_C(  75),
        -INT8_C( 105),  INT8_C(  73), -INT8_C(   6), -INT8_C( 100), -INT8_C( 115), -INT8_C(  75), -INT8_C( 112),  INT8_C(  36) },
 },
    { { -INT8_C(  81), -INT8_C(  38), -INT8_C(  58),  INT8_C(  33), -INT8_C(  61),  INT8_C(  54),  INT8_C(  89),  INT8_C(  86),
        -INT8_C(   9), -INT8_C(  91), -INT8_C( 108), -INT8_C(  53),  INT8_C(  44), -INT8_C( 109),  INT8_C( 118), -INT8_C(  75) },
 },
    { {  INT8_C( 116),  INT8_C(  85), -INT8_C( 116), -INT8_C(  50), -INT8_C(  77),  INT8_C(  50), -INT8_C( 125),  INT8_C(  74),
         INT8_C( 123),  INT8_C( 126), -INT8_C(  26),  INT8_C(   9),  INT8_C(  51),  INT8_C( 118),  INT8_C(  45), -INT8_C(  30) },
 },
    { {  INT8_C(  81), -INT8_C(  13),  INT8_C(   3),  INT8_C(  20),  INT8_C(  41),  INT8_C(  93),  INT8_C( 106),  INT8_C(  32),
         INT8_C(   2), -INT8_C(   1), -INT8_C(  21),  INT8_C(  46), -INT8_C( 110),  INT8_C(  97), -INT8_C(  29),  INT8_C(   6) },
 },
    { { -INT8_C(  73),  INT8_C( 112), -INT8_C(  44),  INT8_C( 106), -INT8_C(  94),  INT8_C(  88), -INT8_C(  76),  INT8_C(  29),
        -INT8_C(  42), -INT8_C( 101),  INT8_C(  38),  INT8_C(   9),  INT8_C(  17),  INT8_C(  83), -INT8_C(  20),  INT8_C(  98) },
 },
    { {  INT8_C(  71), -INT8_C(  17),  INT8_C( 118),  INT8_C( 112),  INT8_C(  76), -INT8_C(  31), -INT8_C( 111),  INT8_C(  78),
        -INT8_C(  32),  INT8_C( 124),  INT8_C( 125),  INT8_C( 114), -INT8_C(  34),  INT8_C(  96),  INT8_C( 120), -INT8_C( 107) },
 },
    { { -INT8_C(  48),  INT8_C(  77), -INT8_C(   1),  INT8_C( 114), -INT8_C(  91), -INT8_C(  77), -INT8_C( 112),  INT8_C( 123),
         INT8_C(  78), -INT8_C(  74), -INT8_C( 124),  INT8_C(  96),  INT8_C(  10),  INT8_C( 112), -INT8_C(  62),  INT8_C(  81) },
 },
    { {  INT8_C(  96),  INT8_C(  57), -INT8_C(  63), -INT8_C(  84),  INT8_C(  26),  INT8_C(  82), -INT8_C(   5), -INT8_C(   6),
        -INT8_C(  49),  INT8_C( 120),  INT8_C( 108), -INT8_C(  83), -INT8_C(  40), -INT8_C(  28),  INT8_C(  66), -INT8_C(  87) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_int16x8_t r = simde_vreinterpretq_s16_s8(a);
    simde_int16x8_private r_ = simde_int16x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s32_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
  } test_vec[] = {
    { { -INT8_C(  26), -INT8_C(  70),  INT8_C(  65), -INT8_C(  95), -INT8_C( 121), -INT8_C(  30),  INT8_C(  64), -INT8_C(  26),
         INT8_C(  11),  INT8_C(  80),  INT8_C( 104),  INT8_C(  24), -INT8_C(  39),  INT8_C( 118),  INT8_C(  71),  INT8_C(  40) },
 },
    { {  INT8_C(  86),  INT8_C(   6), -INT8_C( 116),  INT8_C(  44),  INT8_C(  39), -INT8_C(   8),  INT8_C(  58),  INT8_C(  70),
        -INT8_C(  67), -INT8_C(  15), -INT8_C(  45),  INT8_C( 124),  INT8_C( 104),  INT8_C(   2),  INT8_C(   7),  INT8_C(  78) },
 },
    { { -INT8_C(  67),  INT8_C(  73), -INT8_C(  17),  INT8_C(  68),  INT8_C(  43),  INT8_C(  48),  INT8_C(  42),  INT8_C(  54),
             INT8_MIN, -INT8_C( 110),  INT8_C(  78),  INT8_C(  90),  INT8_C(   9), -INT8_C( 107), -INT8_C( 126),  INT8_C(  95) },
 },
    { { -INT8_C( 100),  INT8_C(  15), -INT8_C( 117), -INT8_C(  61),  INT8_C(   7), -INT8_C(  59),  INT8_C(   9), -INT8_C(  60),
        -INT8_C(  73), -INT8_C(  35),  INT8_C(  64),  INT8_C(  31), -INT8_C(  33),  INT8_C(  72),  INT8_C( 109), -INT8_C( 100) },
 },
    { { -INT8_C( 111),  INT8_C(  92), -INT8_C(  32), -INT8_C(  68), -INT8_C( 116),  INT8_C(  10), -INT8_C(  13),  INT8_C(  13),
        -INT8_C(  99),  INT8_C(  65),  INT8_C( 103), -INT8_C(  90), -INT8_C(  41), -INT8_C(  23),  INT8_C(   5),  INT8_C( 115) },
 },
    { { -INT8_C(   8), -INT8_C( 112),  INT8_C(  54), -INT8_C(   1),  INT8_C(  85),  INT8_C(  63), -INT8_C(  61),  INT8_C(  12),
         INT8_C(  28),  INT8_C(   4),  INT8_C(  43), -INT8_C(   4),  INT8_C(  76), -INT8_C( 104), -INT8_C( 104), -INT8_C(  35) },
 },
    { { -INT8_C(  11),  INT8_C( 121), -INT8_C( 103), -INT8_C( 127), -INT8_C( 125), -INT8_C( 116), -INT8_C( 114),  INT8_C(  32),
        -INT8_C(  50), -INT8_C(  11), -INT8_C(  58), -INT8_C(  91), -INT8_C(  33), -INT8_C(  53),  INT8_C(  24), -INT8_C(  41) },
 },
    { {  INT8_C(  91),  INT8_C(  78), -INT8_C(  41), -INT8_C(  79), -INT8_C( 115), -INT8_C( 102), -INT8_C(  67), -INT8_C(  86),
        -INT8_C(  98), -INT8_C(  23), -INT8_C(  90), -INT8_C(  22), -INT8_C( 127),  INT8_C(  62), -INT8_C(  57),  INT8_C( 118) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_int32x4_t r = simde_vreinterpretq_s32_s8(a);
    simde_int32x4_private r_ = simde_int32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s64_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
  } test_vec[] = {
    { {  INT8_C(  40), -INT8_C(  64),  INT8_C(  94),  INT8_C( 110), -INT8_C(  13), -INT8_C( 103), -INT8_C( 107),  INT8_C(   8),
        -INT8_C(  65), -INT8_C(  53), -INT8_C(  27), -INT8_C(  10),  INT8_C( 108), -INT8_C(  74),  INT8_C(   4),  INT8_C(  22) },
 },
    { { -INT8_C(  26), -INT8_C(  37),  INT8_C(  97), -INT8_C(  37), -INT8_C( 111),  INT8_C(  80),  INT8_C(  10), -INT8_C(  66),
        -INT8_C( 125), -INT8_C( 101),  INT8_C(  97), -INT8_C(  59), -INT8_C( 114), -INT8_C(  86), -INT8_C(  58), -INT8_C(  73) },
 },
    { {  INT8_C( 106),  INT8_C(  36),  INT8_C(  37),  INT8_C(  93), -INT8_C(  67), -INT8_C(  70),  INT8_C( 102),  INT8_C( 124),
        -INT8_C( 123),  INT8_C(  75),  INT8_C( 114), -INT8_C(  15),  INT8_C(   1),  INT8_C( 119),  INT8_C(   8), -INT8_C(  25) },
 },
    { {  INT8_C(  82),  INT8_C( 105), -INT8_C(  62), -INT8_C(  29), -INT8_C(  70), -INT8_C(  51), -INT8_C(  95),  INT8_C(  61),
         INT8_C( 104),  INT8_C(   3),  INT8_C(   2), -INT8_C(  10), -INT8_C(  83), -INT8_C(  56), -INT8_C(  83),  INT8_C(  23) },
 },
    { { -INT8_C(  20), -INT8_C(  46),  INT8_C( 117), -INT8_C(  86), -INT8_C( 116), -INT8_C(  37),  INT8_C(  38),  INT8_C(  17),
         INT8_C(  38), -INT8_C( 103),  INT8_C(   3),  INT8_C(  39),  INT8_C(  16),  INT8_C(  11),  INT8_C(  15),  INT8_C(  98) },
 },
    { {  INT8_C( 116), -INT8_C(  47),  INT8_C(  69),  INT8_C(  46), -INT8_C(  98), -INT8_C(  25),  INT8_C( 107),  INT8_C(   6),
        -INT8_C(  22),  INT8_C( 109), -INT8_C(   3), -INT8_C( 105),  INT8_C(  53), -INT8_C(  86), -INT8_C(  82),  INT8_C(  34) },
 },
    { {  INT8_C( 125),  INT8_C(  35), -INT8_C(  52),  INT8_C(   9), -INT8_C(   2), -INT8_C(  14),  INT8_C(  27),  INT8_C(  36),
        -INT8_C( 117),  INT8_C(  30),  INT8_C(  76), -INT8_C( 101),  INT8_C(  41),  INT8_C(  91), -INT8_C(   3), -INT8_C(  99) },
 },
    { {  INT8_C(  44),  INT8_C(  67), -INT8_C(  52), -INT8_C(  53),  INT8_C(  42),  INT8_C(  55), -INT8_C(  47),  INT8_C(  20),
        -INT8_C(  91), -INT8_C(  50), -INT8_C(  85), -INT8_C(  38),  INT8_C( 121),  INT8_C(  89), -INT8_C(   4), -INT8_C(  10) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_int64x2_t r = simde_vreinterpretq_s64_s8(a);
    simde_int64x2_private r_ = simde_int64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u8_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
  } test_vec[] = {
    { { -INT8_C(  47), -INT8_C( 102), -INT8_C(  31),  INT8_C(  11),  INT8_C(  32), -INT8_C(  41), -INT8_C(  85), -INT8_C(  54),
         INT8_C(  70), -INT8_C(  47),  INT8_C(  16), -INT8_C(  62),  INT8_C(  57), -INT8_C(  93), -INT8_C(  83),  INT8_C(  62) },
 },
    { { -INT8_C(  12),  INT8_C(  20), -INT8_C(  76),  INT8_C(  35), -INT8_C(   2), -INT8_C( 107), -INT8_C(   1), -INT8_C( 124),
         INT8_C(  58),  INT8_C(  57), -INT8_C(  54), -INT8_C(  62),  INT8_C( 112),  INT8_C(  79),  INT8_C(  71),  INT8_C(  65) },
 },
    { { -INT8_C(  23),  INT8_C(  41),  INT8_C(  76),  INT8_C(   9),  INT8_C(   0), -INT8_C(   9), -INT8_C(  45),  INT8_C(  70),
        -INT8_C(  55), -INT8_C(  29),  INT8_C(   8),  INT8_C(   2), -INT8_C( 121), -INT8_C(  75),  INT8_C(  64),  INT8_C( 123) },
 },
    { { -INT8_C(  55), -INT8_C(  12), -INT8_C(  98), -INT8_C(  57), -INT8_C( 119), -INT8_C(  99),  INT8_C(  76), -INT8_C(  60),
        -INT8_C(  41),  INT8_C(  22), -INT8_C( 122),  INT8_C(  71),  INT8_C( 101), -INT8_C(  50), -INT8_C( 119),  INT8_C(  78) },
 },
    { { -INT8_C(   9), -INT8_C(  43),  INT8_C(  88), -INT8_C(   9), -INT8_C(  51),  INT8_C(  43),  INT8_C(  61), -INT8_C( 106),
         INT8_C(  15),  INT8_C(  69), -INT8_C( 104), -INT8_C( 106), -INT8_C(   6), -INT8_C(  39),  INT8_C(  17), -INT8_C(  61) },
 },
    { { -INT8_C(  51), -INT8_C(  81), -INT8_C( 118),  INT8_C(  87),  INT8_C(  77), -INT8_C(  42),  INT8_C(  27),  INT8_C(  36),
        -INT8_C(  19), -INT8_C(  95),  INT8_C( 107),  INT8_C(  82),  INT8_C( 111), -INT8_C(  12), -INT8_C(  95),  INT8_C( 102) },
 },
    { { -INT8_C(  54), -INT8_C(   7),  INT8_C(  93), -INT8_C( 105),  INT8_C(  36), -INT8_C( 102),  INT8_C(  45),  INT8_C(  51),
        -INT8_C(  33), -INT8_C(  59), -INT8_C(  55), -INT8_C(  39), -INT8_C(  98), -INT8_C(  38), -INT8_C( 100),  INT8_C( 108) },
 },
    { { -INT8_C( 118),  INT8_C(  39), -INT8_C(  61), -INT8_C(  41), -INT8_C(   3), -INT8_C(  34), -INT8_C(   5), -INT8_C(  22),
             INT8_MAX,  INT8_C( 102),  INT8_C(  61), -INT8_C(  17),  INT8_C(  91), -INT8_C(  34),  INT8_C(  85),  INT8_C(  37) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_uint8x16_t r = simde_vreinterpretq_u8_s8(a);
    simde_uint8x16_private r_ = simde_uint8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u16_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
  } test_vec[] = {
    { { -INT8_C(  32),  INT8_C( 116),  INT8_C(  72),  INT8_C(  76),  INT8_C( 122),      INT8_MAX, -INT8_C(  53),  INT8_C( 119),
        -INT8_C(  39),  INT8_C(  60), -INT8_C( 101), -INT8_C(  31),  INT8_C(  40),  INT8_C(  95), -INT8_C(  92), -INT8_C(  22) },
 },
    { {  INT8_C(  41),  INT8_C(   0),  INT8_C(   1),  INT8_C(  27), -INT8_C(  65), -INT8_C(  19), -INT8_C(  52),  INT8_C( 119),
         INT8_C( 114), -INT8_C( 122), -INT8_C( 126),  INT8_C(  22), -INT8_C(  64), -INT8_C(  26),  INT8_C(  34), -INT8_C(  96) },
 },
    { {  INT8_C(  90),  INT8_C( 106), -INT8_C(  19), -INT8_C(  43), -INT8_C(  22), -INT8_C(  72),  INT8_C(  76), -INT8_C(  61),
        -INT8_C(  11), -INT8_C(  25), -INT8_C(  92),  INT8_C(  29),  INT8_C(  70),  INT8_C(  73),  INT8_C(   7),  INT8_C( 111) },
 },
    { {  INT8_C(  73),  INT8_C(   8), -INT8_C( 118),  INT8_C(   8), -INT8_C(  11),  INT8_C(  86),      INT8_MAX,  INT8_C( 104),
        -INT8_C(  36),  INT8_C(   1),  INT8_C( 126), -INT8_C(  99), -INT8_C(  25), -INT8_C(  95),  INT8_C(  61),  INT8_C(  66) },
 },
    { {  INT8_C(  11),  INT8_C(  42),  INT8_C(  23), -INT8_C(  11), -INT8_C(  29),  INT8_C(  99), -INT8_C(  72), -INT8_C(  40),
         INT8_C(  74),  INT8_C(  93), -INT8_C(  11), -INT8_C( 111), -INT8_C(  90), -INT8_C(   4),  INT8_C(   0), -INT8_C(  17) },
 },
    { {  INT8_C(   4), -INT8_C( 117), -INT8_C(   9), -INT8_C(   7), -INT8_C(  31),  INT8_C( 118),  INT8_C(  97), -INT8_C(  66),
         INT8_C( 119), -INT8_C(  32),  INT8_C(  91),  INT8_C(  95), -INT8_C( 127), -INT8_C( 104), -INT8_C(  95), -INT8_C( 116) },
 },
    { { -INT8_C(  61), -INT8_C(  72), -INT8_C( 126), -INT8_C(  90),  INT8_C(  27),  INT8_C(  58),  INT8_C( 126),  INT8_C( 101),
        -INT8_C( 105),  INT8_C( 115), -INT8_C(  10),  INT8_C(  61),  INT8_C( 111), -INT8_C(   9),  INT8_C(  44),  INT8_C( 115) },
 },
    { { -INT8_C( 126),  INT8_C(  35),  INT8_C( 108),  INT8_C(  99), -INT8_C( 103), -INT8_C(  50),  INT8_C(  33),  INT8_C(  17),
        -INT8_C(  82),  INT8_C( 124),  INT8_C( 112),  INT8_C(  47),  INT8_C(  21),  INT8_C(  17), -INT8_C(  69), -INT8_C(  40) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_uint16x8_t r = simde_vreinterpretq_u16_s8(a);
    simde_uint16x8_private r_ = simde_uint16x8_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u32_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
  } test_vec[] = {
    { { -INT8_C(  76), -INT8_C(  67), -INT8_C(  11),  INT8_C(   4),  INT8_C(  27), -INT8_C(  63), -INT8_C(  79), -INT8_C(  10),
        -INT8_C(  12), -INT8_C( 102),  INT8_C( 114), -INT8_C(  58),  INT8_C(   1), -INT8_C(  93), -INT8_C(  72),  INT8_C(  46) },
 },
    { {  INT8_C( 100),  INT8_C( 106),  INT8_C(   0),  INT8_C(  63),  INT8_C(  60), -INT8_C(  12),  INT8_C(   6),  INT8_C(  24),
         INT8_C(  41),  INT8_C( 105), -INT8_C(  29),  INT8_C(  97), -INT8_C(  73),  INT8_C( 105),  INT8_C(  22),  INT8_C( 108) },
 },
    { {  INT8_C(  38),  INT8_C(  11),  INT8_C( 112),  INT8_C(  65), -INT8_C(  52),  INT8_C(  34),  INT8_C(  55), -INT8_C(  64),
        -INT8_C(  68), -INT8_C(  86), -INT8_C( 122), -INT8_C(  66),  INT8_C(  77),  INT8_C(  62), -INT8_C(  20), -INT8_C(  79) },
 },
    { { -INT8_C(  88), -INT8_C(  20), -INT8_C(  16), -INT8_C(  28), -INT8_C(  32), -INT8_C(  10), -INT8_C(   4),  INT8_C(   9),
         INT8_C(  96), -INT8_C(  33),  INT8_C( 106),  INT8_C(  23),  INT8_C(  72),      INT8_MIN, -INT8_C( 125),  INT8_C( 110) },
 },
    { { -INT8_C( 117), -INT8_C(  12), -INT8_C(  80),  INT8_C(  87),  INT8_C(  22), -INT8_C(  25),  INT8_C(  23), -INT8_C(  46),
        -INT8_C( 111), -INT8_C(  99), -INT8_C( 112), -INT8_C(  34), -INT8_C(  37),  INT8_C( 125), -INT8_C( 112), -INT8_C( 125) },
 },
    { {  INT8_C( 105),      INT8_MIN,  INT8_C( 103),  INT8_C(  74),  INT8_C( 119),  INT8_C(  99),  INT8_C(  83), -INT8_C(  41),
         INT8_C(  66), -INT8_C(  66), -INT8_C(  18), -INT8_C( 118),  INT8_C(  62),  INT8_C( 114), -INT8_C(   7), -INT8_C(  54) },
 },
    { {  INT8_C( 102), -INT8_C(  87),  INT8_C(  33),  INT8_C( 124), -INT8_C( 112),  INT8_C(  57),  INT8_C(  78),  INT8_C(  34),
        -INT8_C(  42), -INT8_C(  33),  INT8_C(   0), -INT8_C(  78),  INT8_C(  92), -INT8_C( 112),  INT8_C(  53), -INT8_C(  59) },
 },
    { {  INT8_C(  17), -INT8_C(  99),  INT8_C(  15), -INT8_C( 120),  INT8_C(   0),  INT8_C(  99),  INT8_C(  95),  INT8_C(  67),
         INT8_C(  33),  INT8_C(  77), -INT8_C(  51),  INT8_C(  95), -INT8_C(  65), -INT8_C(  58),  INT8_C(  41),  INT8_C(  37) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_uint32x4_t r = simde_vreinterpretq_u32_s8(a);
    simde_uint32x4_private r_ = simde_uint32x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u64_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
  } test_vec[] = {
    { {  INT8_C(   3),  INT8_C(  10), -INT8_C(  37),  INT8_C(  49),  INT8_C(  25),  INT8_C(  54), -INT8_C(  41), -INT8_C( 110),
        -INT8_C(  34), -INT8_C( 112),  INT8_C(  93),  INT8_C(  12), -INT8_C( 122),  INT8_C(  85), -INT8_C(  15), -INT8_C(  94) },
 },
    { {  INT8_C(  81), -INT8_C(  62),  INT8_C(  63),  INT8_C( 114), -INT8_C(  14),  INT8_C( 116),  INT8_C( 118), -INT8_C(  98),
        -INT8_C( 118),  INT8_C(  40),  INT8_C(  49),  INT8_C( 103), -INT8_C(  67), -INT8_C(  35),  INT8_C(  31), -INT8_C(  64) },
 },
    { { -INT8_C(  25), -INT8_C(   6), -INT8_C(  15),  INT8_C(   0),  INT8_C(  49), -INT8_C(  56), -INT8_C( 109),  INT8_C(  15),
         INT8_C(  88), -INT8_C(  16),  INT8_C(  28), -INT8_C(  34),  INT8_C(  69),  INT8_C(  13), -INT8_C( 127), -INT8_C( 106) },
 },
    { { -INT8_C(  49), -INT8_C(  64),  INT8_C(   8), -INT8_C(  63),  INT8_C(  53),      INT8_MAX,  INT8_C(  96), -INT8_C(  65),
        -INT8_C(  89), -INT8_C( 111),  INT8_C(  38),  INT8_C( 100),  INT8_C( 110),  INT8_C(  69),  INT8_C(  36),  INT8_C(  85) },
 },
    { {  INT8_C(  63),  INT8_C(  21),  INT8_C(  85),  INT8_C( 112), -INT8_C(  35), -INT8_C(  24),      INT8_MIN,  INT8_C(  53),
        -INT8_C(  40), -INT8_C( 100),  INT8_C(  19),  INT8_C(  29), -INT8_C(  87), -INT8_C( 108), -INT8_C(  76),  INT8_C( 120) },
 },
    { {  INT8_C(  85), -INT8_C(  68),  INT8_C(  57), -INT8_C( 118),  INT8_C(  59), -INT8_C( 103),  INT8_C(  73), -INT8_C(  30),
         INT8_C(  42),  INT8_C( 111),  INT8_C(  70), -INT8_C( 104), -INT8_C(  76),  INT8_C( 106), -INT8_C(  19), -INT8_C(  13) },
 },
    { {      INT8_MAX,  INT8_C(  67),  INT8_C( 100),  INT8_C(  92),  INT8_C(  43), -INT8_C(  28), -INT8_C( 111),  INT8_C(   4),
             INT8_MIN, -INT8_C(  91),  INT8_C(  33),  INT8_C(  41),  INT8_C(  57), -INT8_C(  43), -INT8_C(  95), -INT8_C( 114) },
 },
    { { -INT8_C( 110), -INT8_C(  38),  INT8_C(  24), -INT8_C(  51),  INT8_C( 116),  INT8_C(  97), -INT8_C(  80), -INT8_C(  98),
        -INT8_C(  48), -INT8_C(  10),  INT8_C(  55), -INT8_C( 124),  INT8_C(  97),  INT8_C(  36),  INT8_C( 120), -INT8_C(  32) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_private a_ = simde_int8x16_to_private(a);
    simde_uint64x2_t r = simde_vreinterpretq_u64_s8(a);
    simde_uint64x2_private r_ = simde_uint64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f32_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
  } test_vec[] = {
    { { -INT16_C( 27026), -INT16_C(  5702), -INT16_C( 32251), -INT16_C( 22224) },
 },
    { {  INT16_C( 18627), -INT16_C( 18788),  INT16_C( 28877),  INT16_C(   229) },
 },
    { { -INT16_C( 22464),  INT16_C( 10858), -INT16_C(  1223), -INT16_C(  1199) },
 },
    { {  INT16_C( 17727),  INT16_C(  2234),  INT16_C( 24935), -INT16_C( 10779) },
 },
    { { -INT16_C( 24584), -INT16_C(   578), -INT16_C(  4575), -INT16_C(  6746) },
 },
    { {  INT16_C( 16951),  INT16_C(  1179), -INT16_C( 32590), -INT16_C(  3324) },
 },
    { {  INT16_C( 28456),  INT16_C( 24861),  INT16_C( 28522), -INT16_C( 22180) },
 },
    { {  INT16_C(  5812),  INT16_C(  7090), -INT16_C( 26760),  INT16_C( 28912) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_float32x2_t r = simde_vreinterpret_f32_s16(a);
    simde_float32x2_private r_ = simde_float32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f64_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
  } test_vec[] = {
    { { -INT16_C( 19849), -INT16_C( 26238),  INT16_C( 31751),  INT16_C( 20490) },
 },
    { {  INT16_C(  6833),  INT16_C( 28856), -INT16_C( 28586),  INT16_C( 25538) },
 },
    { {  INT16_C( 10997), -INT16_C( 12172),  INT16_C( 29916),  INT16_C(  9088) },
 },
    { { -INT16_C(   332), -INT16_C(   390), -INT16_C( 25049), -INT16_C( 24659) },
 },
    { {  INT16_C( 12368),  INT16_C( 22584),  INT16_C( 17068),  INT16_C( 23976) },
 },
    { {  INT16_C( 24669), -INT16_C( 19506), -INT16_C( 28432), -INT16_C(  6634) },
 },
    { { -INT16_C( 29765), -INT16_C( 26698),  INT16_C( 14079), -INT16_C( 19526) },
 },
    { {  INT16_C( 13364),  INT16_C( 23474),  INT16_C( 24530),  INT16_C(  9210) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_float64x1_t r = simde_vreinterpret_f64_s16(a);
    simde_float64x1_private r_ = simde_float64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s8_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
  } test_vec[] = {
    { {  INT16_C( 12325), -INT16_C( 26211),  INT16_C( 30570), -INT16_C(  5405) },
 },
    { { -INT16_C( 15356), -INT16_C( 17829),  INT16_C(  1543),  INT16_C( 26527) },
 },
    { { -INT16_C( 21602), -INT16_C( 10929), -INT16_C(  5199),  INT16_C(   544) },
 },
    { { -INT16_C( 22429), -INT16_C( 24560),  INT16_C( 11069),  INT16_C( 25227) },
 },
    { {  INT16_C( 10331), -INT16_C( 14852), -INT16_C(  8289), -INT16_C( 23376) },
 },
    { {  INT16_C(  2979), -INT16_C( 21666), -INT16_C(   750), -INT16_C( 20462) },
 },
    { {  INT16_C( 25000),  INT16_C( 22917), -INT16_C( 22964), -INT16_C( 20645) },
 },
    { {  INT16_C( 27470), -INT16_C( 29872), -INT16_C(  9322), -INT16_C(  3602) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_int8x8_t r = simde_vreinterpret_s8_s16(a);
    simde_int8x8_private r_ = simde_int8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s32_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
  } test_vec[] = {
    { { -INT16_C( 12560),  INT16_C( 27946), -INT16_C( 10148),  INT16_C( 28958) },
 },
    { { -INT16_C( 22095),  INT16_C( 22767), -INT16_C( 18596),  INT16_C( 14570) },
 },
    { { -INT16_C( 21018), -INT16_C( 20461), -INT16_C( 11786), -INT16_C( 29585) },
 },
    { { -INT16_C( 11749),  INT16_C(  8247), -INT16_C( 16711), -INT16_C( 21988) },
 },
    { {  INT16_C( 18316), -INT16_C(  6121),  INT16_C( 13599), -INT16_C( 12199) },
 },
    { {  INT16_C( 18654),  INT16_C( 14888),  INT16_C(  4608), -INT16_C(  6541) },
 },
    { { -INT16_C( 31041), -INT16_C( 18793),  INT16_C(  1623),  INT16_C( 29250) },
 },
    { {  INT16_C( 31193), -INT16_C( 28014), -INT16_C( 20681), -INT16_C( 15556) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_int32x2_t r = simde_vreinterpret_s32_s16(a);
    simde_int32x2_private r_ = simde_int32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s64_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
  } test_vec[] = {
    { {  INT16_C( 25283),  INT16_C(  6672), -INT16_C(  6113), -INT16_C( 12546) },
 },
    { { -INT16_C( 14626),  INT16_C(  3187),  INT16_C( 15843),  INT16_C( 15972) },
 },
    { { -INT16_C(  2508),  INT16_C( 29996), -INT16_C( 16259), -INT16_C( 15064) },
 },
    { { -INT16_C(   967),  INT16_C(  5267), -INT16_C(  1862),  INT16_C( 32247) },
 },
    { {  INT16_C(  2138),  INT16_C( 31127), -INT16_C( 27152), -INT16_C( 12473) },
 },
    { { -INT16_C( 17572),  INT16_C( 16347),  INT16_C( 16376),  INT16_C( 11390) },
 },
    { { -INT16_C( 21962), -INT16_C( 19550), -INT16_C( 13718), -INT16_C( 23687) },
 },
    { {  INT16_C(  3271), -INT16_C( 32329), -INT16_C( 20732),  INT16_C( 24318) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_int64x1_t r = simde_vreinterpret_s64_s16(a);
    simde_int64x1_private r_ = simde_int64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u8_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
  } test_vec[] = {
    { { -INT16_C( 32486), -INT16_C(  2660),  INT16_C(  7883), -INT16_C( 15352) },
 },
    { { -INT16_C( 12203), -INT16_C(  9918),  INT16_C( 13929), -INT16_C(  4761) },
 },
    { { -INT16_C( 15816),  INT16_C( 30875),  INT16_C(  6606), -INT16_C( 29294) },
 },
    { {  INT16_C( 23764), -INT16_C(  4001),  INT16_C( 15786), -INT16_C( 15111) },
 },
    { { -INT16_C( 26946), -INT16_C( 30023), -INT16_C( 15948),  INT16_C(  2382) },
 },
    { { -INT16_C( 28527), -INT16_C(  1053),  INT16_C( 19142), -INT16_C(    24) },
 },
    { { -INT16_C( 31988), -INT16_C(  9353),  INT16_C(  2461),  INT16_C( 29032) },
 },
    { { -INT16_C( 14491),  INT16_C(  3937),  INT16_C( 23301), -INT16_C( 15404) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_uint8x8_t r = simde_vreinterpret_u8_s16(a);
    simde_uint8x8_private r_ = simde_uint8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u16_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
  } test_vec[] = {
    { { -INT16_C( 13698), -INT16_C(  2016),  INT16_C(  7173),  INT16_C(  8812) },
 },
    { {  INT16_C( 14693), -INT16_C( 20452), -INT16_C( 11625),  INT16_C(  2112) },
 },
    { {  INT16_C( 12150), -INT16_C( 13614),  INT16_C( 29200), -INT16_C( 12138) },
 },
    { {  INT16_C(  5371),  INT16_C( 14148), -INT16_C( 22854),  INT16_C( 14568) },
 },
    { {  INT16_C(  2160),  INT16_C( 30256), -INT16_C( 25564), -INT16_C( 30312) },
 },
    { { -INT16_C( 18987),  INT16_C( 27961),  INT16_C( 31111), -INT16_C(   395) },
 },
    { {  INT16_C( 18345), -INT16_C( 17976),  INT16_C( 24249), -INT16_C( 19062) },
 },
    { { -INT16_C( 12685),  INT16_C( 11756), -INT16_C( 11148), -INT16_C(  6811) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_uint16x4_t r = simde_vreinterpret_u16_s16(a);
    simde_uint16x4_private r_ = simde_uint16x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u32_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
  } test_vec[] = {
    { { -INT16_C( 27149), -INT16_C( 16278),  INT16_C( 23388),  INT16_C( 23522) },
 },
    { {  INT16_C( 27458), -INT16_C( 32273),  INT16_C(  2040), -INT16_C( 22817) },
 },
    { {  INT16_C( 19568), -INT16_C( 31411), -INT16_C( 28489),  INT16_C( 18863) },
 },
    { {  INT16_C( 32598), -INT16_C( 30228),  INT16_C(  9375), -INT16_C( 28005) },
 },
    { {  INT16_C(  1721),  INT16_C(  5459),  INT16_C( 13665), -INT16_C( 23695) },
 },
    { {  INT16_C( 24737), -INT16_C( 26332),  INT16_C(  1127), -INT16_C( 10433) },
 },
    { { -INT16_C( 29360),  INT16_C(  1885),  INT16_C(  3101),  INT16_C( 29520) },
 },
    { {  INT16_C( 15500),  INT16_C( 11260), -INT16_C( 26528),  INT16_C(  6845) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_uint32x2_t r = simde_vreinterpret_u32_s16(a);
    simde_uint32x2_private r_ = simde_uint32x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u64_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
  } test_vec[] = {
    { { -INT16_C( 19422),  INT16_C(  4112), -INT16_C(  6132), -INT16_C( 22247) },
 },
    { {  INT16_C( 17482),  INT16_C( 22232),  INT16_C(  7090),  INT16_C( 19055) },
 },
    { {  INT16_C(  7162), -INT16_C( 12732),  INT16_C( 25546), -INT16_C( 12846) },
 },
    { {  INT16_C( 32293),  INT16_C( 15899), -INT16_C( 27923),  INT16_C(  4212) },
 },
    { { -INT16_C( 31674),  INT16_C( 21024),  INT16_C( 14700), -INT16_C( 18436) },
 },
    { { -INT16_C( 11139),  INT16_C( 12045),  INT16_C( 31983), -INT16_C(  5767) },
 },
    { { -INT16_C( 16745),  INT16_C( 25016), -INT16_C( 30175),  INT16_C( 17966) },
 },
    { {  INT16_C( 18953), -INT16_C(  2428), -INT16_C(  1828),  INT16_C(  8710) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_private a_ = simde_int16x4_to_private(a);
    simde_uint64x1_t r = simde_vreinterpret_u64_s16(a);
    simde_uint64x1_private r_ = simde_uint64x1_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f32_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
  } test_vec[] = {
    { {  INT16_C( 26800),  INT16_C(  6579),  INT16_C(  6869),  INT16_C(  1599), -INT16_C(  6376), -INT16_C( 21236),  INT16_C( 31152),  INT16_C( 26129) },
 },
    { {  INT16_C(  4862), -INT16_C( 26934), -INT16_C( 17327), -INT16_C(  8418),  INT16_C( 12000), -INT16_C( 10920), -INT16_C( 22979), -INT16_C(  4503) },
 },
    { {  INT16_C(  7438), -INT16_C(  7417),  INT16_C( 17975),  INT16_C( 20713), -INT16_C(  2770), -INT16_C(  8451),  INT16_C(  3694),  INT16_C( 27972) },
 },
    { {  INT16_C(  3616),  INT16_C( 28931),  INT16_C(  8650), -INT16_C( 21936), -INT16_C( 22449), -INT16_C( 29313), -INT16_C(  6066),  INT16_C( 23675) },
 },
    { { -INT16_C( 32251),  INT16_C( 15679),  INT16_C( 10441), -INT16_C(  2163), -INT16_C( 30179), -INT16_C( 29483),  INT16_C(  6552), -INT16_C( 18183) },
 },
    { { -INT16_C(   985), -INT16_C(  3798),  INT16_C( 31261),  INT16_C( 28059),  INT16_C(  6691),  INT16_C( 29178),  INT16_C( 29954),  INT16_C(  2254) },
 },
    { {  INT16_C(  3575), -INT16_C( 16315), -INT16_C( 11722),  INT16_C( 21431), -INT16_C( 29604), -INT16_C(  2849), -INT16_C( 10075), -INT16_C( 13140) },
 },
    { { -INT16_C( 10540), -INT16_C(  3395),  INT16_C( 22609),  INT16_C( 29791),  INT16_C( 22898),  INT16_C( 30181), -INT16_C( 19506), -INT16_C( 14979) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_float32x4_t r = simde_vreinterpretq_f32_s16(a);
    simde_float32x4_private r_ = simde_float32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f64_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
  } test_vec[] = {
    { { -INT16_C( 29595), -INT16_C(  8184),  INT16_C(  4671),  INT16_C(  8346), -INT16_C( 13564),  INT16_C( 18435), -INT16_C(  4990),  INT16_C( 23480) },
 },
    { { -INT16_C( 21848), -INT16_C( 19785), -INT16_C( 22100),  INT16_C( 15114),  INT16_C( 15366), -INT16_C(  9798),  INT16_C( 30430),  INT16_C( 17186) },
 },
    { {  INT16_C( 10754),  INT16_C( 16675), -INT16_C( 16836),  INT16_C( 16482),  INT16_C( 25993),  INT16_C(  3209),  INT16_C( 16721), -INT16_C(  1433) },
 },
    { {  INT16_C(  8171), -INT16_C( 26708), -INT16_C( 18744), -INT16_C( 12589), -INT16_C( 29198), -INT16_C( 12121), -INT16_C( 14077),  INT16_C(  1300) },
 },
    { {  INT16_C( 14323),  INT16_C( 12103), -INT16_C( 22027),  INT16_C( 32624), -INT16_C(  1778),  INT16_C( 24715), -INT16_C(  3526),  INT16_C(  9562) },
 },
    { {  INT16_C(  1553), -INT16_C(  9796), -INT16_C( 28740), -INT16_C( 20569),  INT16_C( 19997),  INT16_C(  8319), -INT16_C( 27881),  INT16_C(  2598) },
 },
    { {  INT16_C( 28107), -INT16_C( 16326), -INT16_C( 21994),  INT16_C(  9279), -INT16_C( 13661), -INT16_C(  8828), -INT16_C(  8515), -INT16_C( 12798) },
 },
    { { -INT16_C( 16668), -INT16_C( 24152),  INT16_C( 20302),  INT16_C( 27472), -INT16_C( 12386), -INT16_C( 19061), -INT16_C( 20125),  INT16_C( 11968) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_float64x2_t r = simde_vreinterpretq_f64_s16(a);
    simde_float64x2_private r_ = simde_float64x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s8_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
  } test_vec[] = {
    { {  INT16_C( 25297),  INT16_C(  2610),  INT16_C( 31420),  INT16_C( 20877), -INT16_C( 22947), -INT16_C(  6853), -INT16_C( 14640),  INT16_C( 23706) },
 },
    { {  INT16_C( 19927),  INT16_C( 10263),  INT16_C(   461),  INT16_C( 18282),  INT16_C( 15045),  INT16_C( 19626), -INT16_C( 25667), -INT16_C( 28937) },
 },
    { {  INT16_C( 11006), -INT16_C( 17768),  INT16_C(  9636),  INT16_C(   268),  INT16_C( 18380), -INT16_C( 25370), -INT16_C( 32755), -INT16_C(  6920) },
 },
    { {  INT16_C(  4045), -INT16_C( 25843),  INT16_C( 30480), -INT16_C( 10526), -INT16_C( 29519),  INT16_C( 28450),  INT16_C(  6439),  INT16_C(  9725) },
 },
    { { -INT16_C( 27069), -INT16_C(  6176), -INT16_C(  4933), -INT16_C( 30744), -INT16_C( 12493),  INT16_C( 16676),  INT16_C(  7247),  INT16_C(  7461) },
 },
    { {  INT16_C( 12844),  INT16_C( 15544), -INT16_C( 25942),  INT16_C( 23314),  INT16_C( 13350),  INT16_C( 19914), -INT16_C( 14258), -INT16_C( 28301) },
 },
    { {  INT16_C( 21342),  INT16_C(  6521),  INT16_C( 24895),  INT16_C( 29345), -INT16_C( 15056), -INT16_C( 32589), -INT16_C(  9759),  INT16_C(  3485) },
 },
    { {  INT16_C( 21771), -INT16_C( 19126),  INT16_C( 23791),  INT16_C(  5393), -INT16_C(  9327), -INT16_C(  8350), -INT16_C( 10845),  INT16_C(   368) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_int8x16_t r = simde_vreinterpretq_s8_s16(a);
    simde_int8x16_private r_ = simde_int8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s32_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
  } test_vec[] = {
    { {  INT16_C(  3755), -INT16_C( 28039),  INT16_C( 32547), -INT16_C( 16414),  INT16_C( 16253),  INT16_C(  9054), -INT16_C(  6945), -INT16_C(  4111) },
 },
    { { -INT16_C( 24673),  INT16_C( 14711),  INT16_C( 11169),  INT16_C( 31468), -INT16_C( 11576), -INT16_C( 26149), -INT16_C( 11247), -INT16_C( 17209) },
 },
    { {  INT16_C( 16610),  INT16_C(  1614),  INT16_C( 12736),  INT16_C( 15813),  INT16_C(  9328),  INT16_C( 20321),  INT16_C( 21000), -INT16_C( 22465) },
 },
    { { -INT16_C( 18703), -INT16_C( 27935), -INT16_C( 12574), -INT16_C( 22004), -INT16_C(  6240), -INT16_C( 20156),  INT16_C(  3003), -INT16_C( 25234) },
 },
    { { -INT16_C( 17332),  INT16_C(  3235),  INT16_C( 27117),  INT16_C( 23881), -INT16_C( 21875), -INT16_C( 27219), -INT16_C(  4868), -INT16_C(  4803) },
 },
    { {  INT16_C(  8098), -INT16_C( 31617), -INT16_C( 29715), -INT16_C( 29393),  INT16_C( 29554),  INT16_C( 11582), -INT16_C( 21378), -INT16_C( 13621) },
 },
    { {  INT16_C( 28265),  INT16_C( 22230),  INT16_C(  8407),  INT16_C( 25780),  INT16_C( 25034), -INT16_C( 14342),  INT16_C( 14157), -INT16_C(  4172) },
 },
    { {  INT16_C( 13398),  INT16_C( 17268), -INT16_C( 23617),  INT16_C( 13008),  INT16_C(  3862), -INT16_C( 27553),  INT16_C( 10939),  INT16_C(  9311) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_int32x4_t r = simde_vreinterpretq_s32_s16(a);
    simde_int32x4_private r_ = simde_int32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s64_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
  } test_vec[] = {
    { {  INT16_C( 20294), -INT16_C( 29983),  INT16_C( 20382),  INT16_C(   509),  INT16_C(  3811),  INT16_C(  8932),  INT16_C( 11235), -INT16_C( 11050) },
 },
    { {  INT16_C( 12292),  INT16_C( 26311),  INT16_C(  3982), -INT16_C( 17091), -INT16_C( 25962),  INT16_C(  3530),  INT16_C( 13008),  INT16_C(  5801) },
 },
    { { -INT16_C( 30079),  INT16_C(  8352), -INT16_C( 25126), -INT16_C( 17119),  INT16_C(  1451), -INT16_C( 28705), -INT16_C( 18896),  INT16_C( 13411) },
 },
    { {  INT16_C( 10982),  INT16_C( 29850), -INT16_C( 10439), -INT16_C( 12494), -INT16_C(   910),  INT16_C( 17117), -INT16_C( 31186), -INT16_C( 20648) },
 },
    { { -INT16_C(  1776), -INT16_C(  5425), -INT16_C(  3690),  INT16_C( 17063), -INT16_C( 30730),  INT16_C( 10193),  INT16_C( 13373),  INT16_C(  9051) },
 },
    { { -INT16_C(  2466), -INT16_C( 26728), -INT16_C( 13619),  INT16_C( 16230),  INT16_C( 17350), -INT16_C(  2943), -INT16_C(  9527), -INT16_C(  9565) },
 },
    { {  INT16_C( 29651),  INT16_C( 27076),  INT16_C( 27748),  INT16_C( 23211),  INT16_C( 31987),  INT16_C( 12417), -INT16_C(  8784),  INT16_C(  3667) },
 },
    { { -INT16_C(  5165), -INT16_C( 24411),  INT16_C(  3253),  INT16_C( 31712),  INT16_C( 24911),  INT16_C(  6511),  INT16_C(  4923),  INT16_C(  3827) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_int64x2_t r = simde_vreinterpretq_s64_s16(a);
    simde_int64x2_private r_ = simde_int64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u8_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
  } test_vec[] = {
    { { -INT16_C( 10869), -INT16_C(  3074), -INT16_C( 14055), -INT16_C( 27820), -INT16_C( 19316),  INT16_C( 10278),  INT16_C( 16875), -INT16_C( 26815) },
 },
    { {  INT16_C( 10309), -INT16_C(   521), -INT16_C( 22342),  INT16_C( 24239), -INT16_C( 29301),  INT16_C( 29629),  INT16_C(  2522),  INT16_C( 25958) },
 },
    { {  INT16_C( 25822), -INT16_C(  1960), -INT16_C( 21203), -INT16_C( 18037), -INT16_C( 19871),  INT16_C( 19682),  INT16_C(  9203),  INT16_C( 14564) },
 },
    { { -INT16_C(  9397),  INT16_C(  1333), -INT16_C(  7037),  INT16_C(  3939),  INT16_C(  8305),  INT16_C( 19330), -INT16_C(  6102),  INT16_C(  2224) },
 },
    { {  INT16_C(  2380),  INT16_C( 30976), -INT16_C( 29514),  INT16_C(  5939),  INT16_C(  5438),  INT16_C( 12644),  INT16_C( 18488), -INT16_C( 31895) },
 },
    { { -INT16_C( 25053), -INT16_C( 22904), -INT16_C(  5246), -INT16_C(  3147),  INT16_C( 14348),  INT16_C( 13887), -INT16_C(  4320),  INT16_C( 27966) },
 },
    { {  INT16_C( 16376), -INT16_C( 20762),  INT16_C(  6603),  INT16_C(  2502),  INT16_C( 10798),  INT16_C( 26170), -INT16_C( 23694), -INT16_C( 27159) },
 },
    { {  INT16_C( 28993), -INT16_C( 15557), -INT16_C(  3747),  INT16_C( 27062), -INT16_C(  2775),  INT16_C( 18847), -INT16_C(  8731), -INT16_C(  8778) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_uint8x16_t r = simde_vreinterpretq_u8_s16(a);
    simde_uint8x16_private r_ = simde_uint8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u16_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
  } test_vec[] = {
    { { -INT16_C(  2701),  INT16_C( 26145), -INT16_C( 32458), -INT16_C(  9044),  INT16_C( 23783), -INT16_C( 21411),  INT16_C(  2922),  INT16_C(  2234) },
 },
    { { -INT16_C(   386),  INT16_C( 27701), -INT16_C( 15086),  INT16_C( 23162), -INT16_C(  2118), -INT16_C(  6704), -INT16_C( 27867), -INT16_C( 26378) },
 },
    { {  INT16_C(  6024), -INT16_C( 16642), -INT16_C( 21863), -INT16_C( 32614), -INT16_C(  2298),  INT16_C( 28717), -INT16_C(  6398), -INT16_C( 32391) },
 },
    { { -INT16_C( 20763), -INT16_C(  2067),  INT16_C( 26740),  INT16_C( 11858),  INT16_C(  8799), -INT16_C( 31724),  INT16_C(  2742),  INT16_C( 15900) },
 },
    { {  INT16_C(  6690), -INT16_C( 17411), -INT16_C( 26684), -INT16_C( 13765),  INT16_C( 26767), -INT16_C( 28358), -INT16_C( 19632),  INT16_C( 13586) },
 },
    { {  INT16_C(    98), -INT16_C( 10707),  INT16_C( 32616), -INT16_C( 14588),  INT16_C(  6305),  INT16_C( 22347),  INT16_C( 26403),  INT16_C( 17814) },
 },
    { { -INT16_C( 27775),  INT16_C( 17664),  INT16_C( 15146), -INT16_C( 18161),  INT16_C( 18852), -INT16_C(  2997),  INT16_C( 24061),  INT16_C( 24361) },
 },
    { {  INT16_C( 22109), -INT16_C( 15051),  INT16_C( 14805),  INT16_C( 30604), -INT16_C( 10414),  INT16_C( 30158),  INT16_C( 25662), -INT16_C( 16454) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_uint16x8_t r = simde_vreinterpretq_u16_s16(a);
    simde_uint16x8_private r_ = simde_uint16x8_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u32_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
  } test_vec[] = {
    { { -INT16_C( 21556), -INT16_C( 15853),  INT16_C( 13986), -INT16_C( 10777), -INT16_C( 13968), -INT16_C( 19349),  INT16_C( 19197),  INT16_C(   747) },
 },
    { {  INT16_C( 22270),  INT16_C( 22312), -INT16_C( 26423),  INT16_C( 13709), -INT16_C(  3407),  INT16_C( 28470), -INT16_C( 11245), -INT16_C(  8339) },
 },
    { { -INT16_C( 32385),  INT16_C(  8865), -INT16_C( 30281),  INT16_C( 10231),  INT16_C( 25170),  INT16_C( 20444), -INT16_C( 14420), -INT16_C( 21935) },
 },
    { {  INT16_C( 31262), -INT16_C(  6399), -INT16_C( 29166), -INT16_C( 15587),  INT16_C( 21376), -INT16_C( 27598), -INT16_C( 24793), -INT16_C( 22669) },
 },
    { {  INT16_C(  5408), -INT16_C( 10295), -INT16_C( 16226), -INT16_C(  3841), -INT16_C(  9438), -INT16_C( 12736), -INT16_C( 28254), -INT16_C( 16264) },
 },
    { {  INT16_C( 30987),  INT16_C(  7592), -INT16_C( 15096), -INT16_C( 30496),  INT16_C(  4632),  INT16_C( 16156), -INT16_C( 28494), -INT16_C( 11546) },
 },
    { { -INT16_C( 20571),  INT16_C( 17322), -INT16_C( 22161), -INT16_C( 28365),  INT16_C( 29572),  INT16_C(  9823), -INT16_C( 10491),  INT16_C(  4327) },
 },
    { { -INT16_C( 28847),  INT16_C( 22830),  INT16_C(  3668),  INT16_C( 27873), -INT16_C(   479), -INT16_C( 11349), -INT16_C( 28018),  INT16_C( 13221) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_uint32x4_t r = simde_vreinterpretq_u32_s16(a);
    simde_uint32x4_private r_ = simde_uint32x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u64_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
  } test_vec[] = {
    { { -INT16_C( 20852), -INT16_C( 25483),  INT16_C( 22713), -INT16_C( 29124), -INT16_C( 29678), -INT16_C( 23696),  INT16_C(  9074), -INT16_C( 27927) },
 },
    { { -INT16_C( 21498), -INT16_C(  8110),  INT16_C(   928), -INT16_C( 30088),  INT16_C(  7327),  INT16_C( 28745),  INT16_C( 15894), -INT16_C( 23830) },
 },
    { {  INT16_C( 24556), -INT16_C( 23234),  INT16_C( 31671), -INT16_C( 13773), -INT16_C( 23801),  INT16_C( 31085),  INT16_C( 22214), -INT16_C( 13300) },
 },
    { {  INT16_C( 24067), -INT16_C( 23636),  INT16_C(  9313),  INT16_C(    46),  INT16_C( 30529),  INT16_C( 22385),  INT16_C( 23477), -INT16_C( 24071) },
 },
    { {  INT16_C( 14523),  INT16_C( 29254),  INT16_C( 31155), -INT16_C( 17860), -INT16_C( 22244), -INT16_C(  7629),  INT16_C( 16128),  INT16_C(   942) },
 },
    { {  INT16_C( 23453), -INT16_C(    90), -INT16_C( 11137), -INT16_C( 16129),  INT16_C( 28748),  INT16_C(   279),  INT16_C(  4556), -INT16_C( 30813) },
 },
    { { -INT16_C(  5815), -INT16_C(   775),  INT16_C( 13923),  INT16_C( 32694), -INT16_C(  5665), -INT16_C(  8350),  INT16_C(  4137), -INT16_C( 14622) },
 },
    { { -INT16_C( 30357), -INT16_C(  5179), -INT16_C( 15011), -INT16_C( 22101), -INT16_C( 15563),  INT16_C(   427),  INT16_C( 20180),  INT16_C(  7560) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_private a_ = simde_int16x8_to_private(a);
    simde_uint64x2_t r = simde_vreinterpretq_u64_s16(a);
    simde_uint64x2_private r_ = simde_uint64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
  } test_vec[] = {
    { {  INT32_C(  1942756607),  INT32_C(  1141729398) },
 },
    { {  INT32_C(  1475419083),  INT32_C(  1695451994) },
 },
    { { -INT32_C(  1030043290), -INT32_C(  1608484645) },
 },
    { {  INT32_C(   563301726),  INT32_C(   833684529) },
 },
    { { -INT32_C(  1767604960), -INT32_C(  1311067675) },
 },
    { {  INT32_C(   638110924), -INT32_C(  1114892713) },
 },
    { { -INT32_C(  1149294881), -INT32_C(    61104226) },
 },
    { {  INT32_C(   505278188),  INT32_C(   323997683) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_float32x2_t r = simde_vreinterpret_f32_s32(a);
    simde_float32x2_private r_ = simde_float32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f64_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
  } test_vec[] = {
    { { -INT32_C(   115647159),  INT32_C(  1543473707) },
 },
    { { -INT32_C(   414762519), -INT32_C(  1092812093) },
 },
    { { -INT32_C(   524899849), -INT32_C(  1091006359) },
 },
    { {  INT32_C(  1246431952), -INT32_C(    91088719) },
 },
    { { -INT32_C(  1577865867),  INT32_C(   570225207) },
 },
    { { -INT32_C(   301448405),  INT32_C(  1017963845) },
 },
    { { -INT32_C(   149134450), -INT32_C(   994765581) },
 },
    { { -INT32_C(   821166050), -INT32_C(  1899388904) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_float64x1_t r = simde_vreinterpret_f64_s32(a);
    simde_float64x1_private r_ = simde_float64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s8_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
  } test_vec[] = {
    { { -INT32_C(  1326109008),  INT32_C(  1640452524) },
 },
    { {  INT32_C(   708537460), -INT32_C(  1325793864) },
 },
    { { -INT32_C(  2091701145),  INT32_C(   605343901) },
 },
    { { -INT32_C(   117296960),  INT32_C(   536353390) },
 },
    { { -INT32_C(   187699640), -INT32_C(  1269459137) },
 },
    { { -INT32_C(  1143041789), -INT32_C(   177416050) },
 },
    { { -INT32_C(  1585922300),  INT32_C(  1338346895) },
 },
    { {  INT32_C(   726255549),  INT32_C(   709509601) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_int8x8_t r = simde_vreinterpret_s8_s32(a);
    simde_int8x8_private r_ = simde_int8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s16_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
  } test_vec[] = {
    { {  INT32_C(   762512963),  INT32_C(  1517888677) },
 },
    { {  INT32_C(  2109169374),  INT32_C(   948011566) },
 },
    { {  INT32_C(   354883301), -INT32_C(   206442941) },
 },
    { {  INT32_C(   151649563), -INT32_C(  1321787282) },
 },
    { { -INT32_C(   874599898), -INT32_C(  1406838578) },
 },
    { { -INT32_C(   467018314),  INT32_C(  1142729311) },
 },
    { {  INT32_C(    72958912),  INT32_C(  1308035890) },
 },
    { {  INT32_C(  1985413128),  INT32_C(  1176997408) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_int16x4_t r = simde_vreinterpret_s16_s32(a);
    simde_int16x4_private r_ = simde_int16x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s64_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
  } test_vec[] = {
    { { -INT32_C(  1772159451), -INT32_C(   273705620) },
 },
    { { -INT32_C(  1746436879), -INT32_C(  1982011284) },
 },
    { { -INT32_C(   777181111), -INT32_C(  1931103660) },
 },
    { { -INT32_C(  1359005937), -INT32_C(   550167878) },
 },
    { { -INT32_C(  2072603624),  INT32_C(   443819305) },
 },
    { {  INT32_C(   246504353), -INT32_C(  1936224957) },
 },
    { {  INT32_C(   157173173),  INT32_C(   110511095) },
 },
    { {  INT32_C(   884315514), -INT32_C(   938153297) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_int64x1_t r = simde_vreinterpret_s64_s32(a);
    simde_int64x1_private r_ = simde_int64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u8_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
  } test_vec[] = {
    { { -INT32_C(   995763866), -INT32_C(   546679899) },
 },
    { {  INT32_C(    53825220), -INT32_C(  1775030743) },
 },
    { {  INT32_C(  1938520045), -INT32_C(  1292661555) },
 },
    { {  INT32_C(   417415971), -INT32_C(  1253875889) },
 },
    { { -INT32_C(   579147720),  INT32_C(    12444732) },
 },
    { {  INT32_C(  1526985266),  INT32_C(   233911840) },
 },
    { {  INT32_C(  2072018350),  INT32_C(   741241609) },
 },
    { {  INT32_C(    88412086), -INT32_C(  1480882065) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_uint8x8_t r = simde_vreinterpret_u8_s32(a);
    simde_uint8x8_private r_ = simde_uint8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u16_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
  } test_vec[] = {
    { { -INT32_C(   149455343), -INT32_C(   818642956) },
 },
    { {  INT32_C(  2049044700), -INT32_C(  1172643403) },
 },
    { { -INT32_C(  1629876328), -INT32_C(  1237868355) },
 },
    { { -INT32_C(  1013774000),  INT32_C(   406067718) },
 },
    { { -INT32_C(  1945154664), -INT32_C(  1487125301) },
 },
    { { -INT32_C(   383681228), -INT32_C(   157074594) },
 },
    { {  INT32_C(   143949130),  INT32_C(  1857997854) },
 },
    { { -INT32_C(   617524779),  INT32_C(    66283115) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_uint16x4_t r = simde_vreinterpret_u16_s32(a);
    simde_uint16x4_private r_ = simde_uint16x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u32_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
  } test_vec[] = {
    { { -INT32_C(   630456070), -INT32_C(   527501120) },
 },
    { {  INT32_C(   283556507),  INT32_C(   426914223) },
 },
    { {  INT32_C(   981302759), -INT32_C(   427316278) },
 },
    { {  INT32_C(  1365974946),  INT32_C(  2124495236) },
 },
    { { -INT32_C(   111669959), -INT32_C(  1596332283) },
 },
    { {  INT32_C(  1353760929), -INT32_C(   664198415) },
 },
    { {  INT32_C(  1779623840),  INT32_C(   894474642) },
 },
    { {  INT32_C(  1015462840),  INT32_C(   767240180) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_uint32x2_t r = simde_vreinterpret_u32_s32(a);
    simde_uint32x2_private r_ = simde_uint32x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u64_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
  } test_vec[] = {
    { { -INT32_C(   895446699),  INT32_C(  1960405026) },
 },
    { {  INT32_C(   439627100), -INT32_C(  1280121677) },
 },
    { { -INT32_C(    41083772),  INT32_C(  1619246791) },
 },
    { { -INT32_C(  1666539493), -INT32_C(   179584609) },
 },
    { {  INT32_C(  1975511890), -INT32_C(  1326868140) },
 },
    { {  INT32_C(  2043289030), -INT32_C(  2043839230) },
 },
    { {  INT32_C(  1636022937), -INT32_C(  1816066440) },
 },
    { {  INT32_C(  1160735654),  INT32_C(  2134538796) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_private a_ = simde_int32x2_to_private(a);
    simde_uint64x1_t r = simde_vreinterpret_u64_s32(a);
    simde_uint64x1_private r_ = simde_uint64x1_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f32_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
  } test_vec[] = {
    { { -INT32_C(   337377293),  INT32_C(  1436377999),  INT32_C(   759437979),  INT32_C(   598356123) },
 },
    { { -INT32_C(  1245575572), -INT32_C(   608506485),  INT32_C(  1163288433), -INT32_C(   702091293) },
 },
    { { -INT32_C(  2034169097),  INT32_C(   165371501),  INT32_C(   339091576), -INT32_C(  1120411568) },
 },
    { {  INT32_C(  1920137702),  INT32_C(  1464675814),  INT32_C(  1872536460), -INT32_C(  1975139437) },
 },
    { {  INT32_C(   990906061), -INT32_C(   582685851),  INT32_C(  1559329291),  INT32_C(  1092167770) },
 },
    { {  INT32_C(   129207073),  INT32_C(  1163788472),  INT32_C(   917830563), -INT32_C(  1950287170) },
 },
    { {  INT32_C(  1707528192), -INT32_C(   951907652), -INT32_C(   551340924),  INT32_C(  2116041821) },
 },
    { { -INT32_C(  2138647608),  INT32_C(  1992680659), -INT32_C(  1649575201),  INT32_C(  1948872052) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_float32x4_t r = simde_vreinterpretq_f32_s32(a);
    simde_float32x4_private r_ = simde_float32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f64_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
  } test_vec[] = {
    { {  INT32_C(   623130355),  INT32_C(  1449239400), -INT32_C(  1128746035), -INT32_C(  1367149809) },
 },
    { { -INT32_C(  2072522775), -INT32_C(  1280826145),  INT32_C(  2128924204), -INT32_C(  1000200240) },
 },
    { { -INT32_C(   957774242), -INT32_C(   149075415),  INT32_C(   229889534), -INT32_C(  1296353591) },
 },
    { { -INT32_C(   449367547), -INT32_C(  2087133353),  INT32_C(  2114026925),  INT32_C(    37905316) },
 },
    { {  INT32_C(   331951082),  INT32_C(  1946871414), -INT32_C(  2071871813), -INT32_C(   113820428) },
 },
    { { -INT32_C(   958501265), -INT32_C(    95848627), -INT32_C(  1736946700), -INT32_C(  1734624594) },
 },
    { {  INT32_C(  1554801894),  INT32_C(    97564234),  INT32_C(  1753895284), -INT32_C(    60636787) },
 },
    { {  INT32_C(  2093105199), -INT32_C(  1418326857),  INT32_C(    88403799), -INT32_C(  1885413463) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_float64x2_t r = simde_vreinterpretq_f64_s32(a);
    simde_float64x2_private r_ = simde_float64x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s8_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
  } test_vec[] = {
    { {  INT32_C(  1739808067), -INT32_C(   119151266),  INT32_C(  1625226765),  INT32_C(   376018564) },
 },
    { {  INT32_C(   977616236), -INT32_C(   549451966),  INT32_C(   391248997), -INT32_C(  1320634002) },
 },
    { {  INT32_C(  1964636950), -INT32_C(   294781215), -INT32_C(  2125509636),  INT32_C(  1301788897) },
 },
    { {  INT32_C(   948493557),  INT32_C(  1209518307),  INT32_C(   845179076),  INT32_C(   954443810) },
 },
    { { -INT32_C(  2052195164), -INT32_C(   143451397),  INT32_C(  1182319205),  INT32_C(  1888751738) },
 },
    { { -INT32_C(   794288916), -INT32_C(  1474773020),  INT32_C(  1239054375), -INT32_C(   981287647) },
 },
    { { -INT32_C(  1253429318), -INT32_C(  1347633846), -INT32_C(    84531840),  INT32_C(   560630325) },
 },
    { { -INT32_C(  1963912538), -INT32_C(   114160943), -INT32_C(  1555952510), -INT32_C(  2090285879) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_int8x16_t r = simde_vreinterpretq_s8_s32(a);
    simde_int8x16_private r_ = simde_int8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s16_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
  } test_vec[] = {
    { { -INT32_C(   305018345), -INT32_C(   408795924),  INT32_C(  1280110211),  INT32_C(  1591486194) },
 },
    { { -INT32_C(   614138690),  INT32_C(   905999471),  INT32_C(  1411049404), -INT32_C(   422389809) },
 },
    { { -INT32_C(  1915509855),  INT32_C(  1802860008),  INT32_C(  1454948708), -INT32_C(  1514892057) },
 },
    { { -INT32_C(     8382320),  INT32_C(  1228243340),  INT32_C(   933056616), -INT32_C(   937595097) },
 },
    { { -INT32_C(    78254061), -INT32_C(   916010395),  INT32_C(  1931484811),  INT32_C(  1125700786) },
 },
    { {  INT32_C(  2034407917), -INT32_C(  2101184486), -INT32_C(   273063736), -INT32_C(   491268401) },
 },
    { {  INT32_C(   735907014),  INT32_C(  1660241111),  INT32_C(   366286178), -INT32_C(   698814743) },
 },
    { { -INT32_C(  1588553081), -INT32_C(   635235822),  INT32_C(  1120525426),  INT32_C(  2015658162) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_int16x8_t r = simde_vreinterpretq_s16_s32(a);
    simde_int16x8_private r_ = simde_int16x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s64_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
  } test_vec[] = {
    { {  INT32_C(   912293310),  INT32_C(   204558552), -INT32_C(  1953009825), -INT32_C(  2006297133) },
 },
    { {  INT32_C(  1220891744),  INT32_C(  2091956675), -INT32_C(   783740282),  INT32_C(  1164829574) },
 },
    { {  INT32_C(   947637600),  INT32_C(  2084875293), -INT32_C(   301474789), -INT32_C(  1854443215) },
 },
    { { -INT32_C(  1982251834),  INT32_C(  2080737782),  INT32_C(   575491740), -INT32_C(  1838695886) },
 },
    { { -INT32_C(  1513364601), -INT32_C(  1423896689),  INT32_C(   496577003),  INT32_C(  1622020250) },
 },
    { {  INT32_C(  1139378253), -INT32_C(  1379930351),  INT32_C(  1875905853),  INT32_C(  1325545415) },
 },
    { { -INT32_C(  1426797286), -INT32_C(   933947940), -INT32_C(   639242690),  INT32_C(  1278841855) },
 },
    { {  INT32_C(   764355355),  INT32_C(  1339706898),  INT32_C(   599763547), -INT32_C(    59588126) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_int64x2_t r = simde_vreinterpretq_s64_s32(a);
    simde_int64x2_private r_ = simde_int64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u8_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
  } test_vec[] = {
    { { -INT32_C(   689895481), -INT32_C(  1859332607), -INT32_C(  1547664472), -INT32_C(  1320526320) },
 },
    { {  INT32_C(   689737540),  INT32_C(  2062555401), -INT32_C(   448572611),  INT32_C(   340183628) },
 },
    { { -INT32_C(   756406063), -INT32_C(  1503389954), -INT32_C(  1438047079), -INT32_C(   950299518) },
 },
    { {  INT32_C(   753956643), -INT32_C(   844701552), -INT32_C(  2135693005), -INT32_C(  2070611533) },
 },
    { {  INT32_C(   525827617),  INT32_C(   784776085),  INT32_C(  1641549791), -INT32_C(   970443613) },
 },
    { {  INT32_C(  1022498987),  INT32_C(   738826489),  INT32_C(   900512898), -INT32_C(   675659594) },
 },
    { {  INT32_C(  1425478079), -INT32_C(  1417495092),  INT32_C(  1879858124),  INT32_C(   976631183) },
 },
    { {  INT32_C(  1182148941),  INT32_C(  1131643073), -INT32_C(   226943172),  INT32_C(   533345120) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_uint8x16_t r = simde_vreinterpretq_u8_s32(a);
    simde_uint8x16_private r_ = simde_uint8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u16_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
  } test_vec[] = {
    { { -INT32_C(  1719971275),  INT32_C(  1718980383),  INT32_C(   225699668),  INT32_C(  2059234434) },
 },
    { {  INT32_C(   356859972), -INT32_C(   729828136), -INT32_C(  1784676808),  INT32_C(  1301308951) },
 },
    { { -INT32_C(   656012359), -INT32_C(   297902950), -INT32_C(   956518077),  INT32_C(  1631631645) },
 },
    { { -INT32_C(   780695815),  INT32_C(  1923479098),  INT32_C(   185091316),  INT32_C(  1683527851) },
 },
    { {  INT32_C(  1044135844), -INT32_C(   567444837),  INT32_C(  1218717995), -INT32_C(   609622558) },
 },
    { { -INT32_C(  1515446165),  INT32_C(   169300502),  INT32_C(  1091968918),  INT32_C(  1554345656) },
 },
    { {  INT32_C(  1218109869), -INT32_C(  2044213413), -INT32_C(   758199312),  INT32_C(   464353456) },
 },
    { { -INT32_C(  1346348392),  INT32_C(  1119475884), -INT32_C(  1350250505), -INT32_C(   351590082) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_uint16x8_t r = simde_vreinterpretq_u16_s32(a);
    simde_uint16x8_private r_ = simde_uint16x8_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u32_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
  } test_vec[] = {
    { { -INT32_C(  1711092359),  INT32_C(  1337709846), -INT32_C(   858119927), -INT32_C(  1460755540) },
 },
    { {  INT32_C(   490966487),  INT32_C(   167270093), -INT32_C(    89510034),  INT32_C(   150734735) },
 },
    { { -INT32_C(   358416684), -INT32_C(   583442989),  INT32_C(   732500863), -INT32_C(  1915512906) },
 },
    { { -INT32_C(   223668444), -INT32_C(   587488403),  INT32_C(  1658234323), -INT32_C(  2140417364) },
 },
    { { -INT32_C(  1536553520), -INT32_C(   360602517),  INT32_C(  1846880951), -INT32_C(   419698238) },
 },
    { {  INT32_C(  1842914816),  INT32_C(   491377482),  INT32_C(   629088377), -INT32_C(  1012471054) },
 },
    { {  INT32_C(  1667698936),  INT32_C(  1817045172), -INT32_C(   723885550),  INT32_C(  1270601035) },
 },
    { { -INT32_C(   960916612), -INT32_C(   521993625),  INT32_C(   352674338),  INT32_C(  1171827533) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_uint32x4_t r = simde_vreinterpretq_u32_s32(a);
    simde_uint32x4_private r_ = simde_uint32x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u64_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
  } test_vec[] = {
    { { -INT32_C(   836308430), -INT32_C(    20823114), -INT32_C(  1341228176), -INT32_C(  1296687314) },
 },
    { { -INT32_C(  1443363026), -INT32_C(  1323579037), -INT32_C(   865858227), -INT32_C(   196110654) },
 },
    { {  INT32_C(  1069774217),  INT32_C(   691897784),  INT32_C(   785992448), -INT32_C(  1730048150) },
 },
    { { -INT32_C(   113124970), -INT32_C(   257270622),  INT32_C(   750521962),  INT32_C(   757140388) },
 },
    { {  INT32_C(   963437697),  INT32_C(  1768073577),  INT32_C(  1586969588),  INT32_C(  1626765514) },
 },
    { { -INT32_C(   195479471), -INT32_C(    18611308), -INT32_C(  1238654959),  INT32_C(   769871020) },
 },
    { { -INT32_C(  1721348048), -INT32_C(   301807111), -INT32_C(   817063676),  INT32_C(  1664041746) },
 },
    { {  INT32_C(   257395067), -INT32_C(  1643234420), -INT32_C(  2007746084), -INT32_C(  1246414971) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_private a_ = simde_int32x4_to_private(a);
    simde_uint64x2_t r = simde_vreinterpretq_u64_s32(a);
    simde_uint64x2_private r_ = simde_uint64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f32_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
  } test_vec[] = {
    { {  INT64_C( 6507368899876856448) },
 },
    { { -INT64_C( 5606110019210035735) },
 },
    { {  INT64_C( 5538191326012830769) },
 },
    { { -INT64_C( 3913861957691473674) },
 },
    { { -INT64_C(   93860817958845234) },
 },
    { {  INT64_C( 3899560943408114888) },
 },
    { { -INT64_C( 3174423257829653766) },
 },
    { { -INT64_C( 3548350518083791698) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_float32x2_t r = simde_vreinterpret_f32_s64(a);
    simde_float32x2_private r_ = simde_float32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
  } test_vec[] = {
    { {  INT64_C( 3937832030626636539) },
 },
    { { -INT64_C( 1574507081372615631) },
 },
    { {  INT64_C( 9162081502117003319) },
 },
    { { -INT64_C( 7690620279898524097) },
 },
    { {  INT64_C( 2009877472910240848) },
 },
    { { -INT64_C( 4012408675839158720) },
 },
    { { -INT64_C( 6006878943899013745) },
 },
    { { -INT64_C( 7193353285132165379) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_float64x1_t r = simde_vreinterpret_f64_s64(a);
    simde_float64x1_private r_ = simde_float64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s8_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
  } test_vec[] = {
    { {  INT64_C( 6328377202146038951) },
 },
    { {  INT64_C( 3619715714540190062) },
 },
    { {  INT64_C( 9155081246081012001) },
 },
    { { -INT64_C( 2351362546501486091) },
 },
    { {  INT64_C( 5583888352263927452) },
 },
    { { -INT64_C( 9177717705129095379) },
 },
    { {  INT64_C( 8675559626524729859) },
 },
    { { -INT64_C( 1740451813690375232) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_int8x8_t r = simde_vreinterpret_s8_s64(a);
    simde_int8x8_private r_ = simde_int8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s16_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
  } test_vec[] = {
    { { -INT64_C( 3168462482490462822) },
 },
    { { -INT64_C( 1219849104769322211) },
 },
    { {  INT64_C( 4676971831165581582) },
 },
    { { -INT64_C(  740107272915334304) },
 },
    { {  INT64_C( 3784936939007031946) },
 },
    { {  INT64_C( 8422026410167249983) },
 },
    { {  INT64_C( 6151963219461210886) },
 },
    { { -INT64_C( 5096855216589139212) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_int16x4_t r = simde_vreinterpret_s16_s64(a);
    simde_int16x4_private r_ = simde_int16x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s32_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
  } test_vec[] = {
    { { -INT64_C( 7114466497633344375) },
 },
    { { -INT64_C(  982042139150972563) },
 },
    { {  INT64_C( 6098053910720327655) },
 },
    { {  INT64_C( 6897172487366335938) },
 },
    { { -INT64_C( 6892269724810748847) },
 },
    { { -INT64_C( 4064317378932651322) },
 },
    { { -INT64_C( 6313913748120124845) },
 },
    { {  INT64_C( 8073265418032673237) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_int32x2_t r = simde_vreinterpret_s32_s64(a);
    simde_int32x2_private r_ = simde_int32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u8_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
  } test_vec[] = {
    { { -INT64_C( 7859406109924154012) },
 },
    { {  INT64_C( 8049504884380889405) },
 },
    { {  INT64_C( 9100164763748731086) },
 },
    { {  INT64_C( 4674145817308398404) },
 },
    { {  INT64_C( 5901648540621360268) },
 },
    { { -INT64_C( 7509089612126145969) },
 },
    { {  INT64_C( 1982760133211688802) },
 },
    { {  INT64_C(  201577274414764208) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_uint8x8_t r = simde_vreinterpret_u8_s64(a);
    simde_uint8x8_private r_ = simde_uint8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u16_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
  } test_vec[] = {
    { { -INT64_C( 9087886216328385184) },
 },
    { { -INT64_C( 5531611665732542435) },
 },
    { {  INT64_C( 1909430669626039079) },
 },
    { {  INT64_C( 3587155385237390099) },
 },
    { { -INT64_C( 3444164426624836849) },
 },
    { { -INT64_C( 5120178736133780034) },
 },
    { { -INT64_C(  540421074411963309) },
 },
    { { -INT64_C( 1778925326933183155) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_uint16x4_t r = simde_vreinterpret_u16_s64(a);
    simde_uint16x4_private r_ = simde_uint16x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u32_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
  } test_vec[] = {
    { { -INT64_C( 1016733158405359620) },
 },
    { { -INT64_C( 2089216970221742623) },
 },
    { { -INT64_C( 5254723309699434506) },
 },
    { {  INT64_C( 1763286918682342951) },
 },
    { {  INT64_C( 1382685565763607467) },
 },
    { { -INT64_C(  397112793860774050) },
 },
    { { -INT64_C( 8982532413052755037) },
 },
    { { -INT64_C( 7111970021676646888) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_uint32x2_t r = simde_vreinterpret_u32_s64(a);
    simde_uint32x2_private r_ = simde_uint32x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u64_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
  } test_vec[] = {
    { { -INT64_C( 5582127008471794557) },
 },
    { {  INT64_C( 7674704104200227240) },
 },
    { { -INT64_C( 3567127553411135658) },
 },
    { {  INT64_C( 1415740588118772255) },
 },
    { { -INT64_C( 8703974978045111948) },
 },
    { { -INT64_C( 6291395285151757427) },
 },
    { {  INT64_C( 4499629426767960896) },
 },
    { { -INT64_C( 8461345510972825873) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_private a_ = simde_int64x1_to_private(a);
    simde_uint64x1_t r = simde_vreinterpret_u64_s64(a);
    simde_uint64x1_private r_ = simde_uint64x1_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f32_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
  } test_vec[] = {
    { { -INT64_C( 7111391188455227457), -INT64_C( 3254191077044569329) },
 },
    { { -INT64_C( 1650031472652397181), -INT64_C(  309481479475721661) },
 },
    { {  INT64_C( 5693002100524252415), -INT64_C( 3378233746908740393) },
 },
    { { -INT64_C( 6847697544965884688), -INT64_C( 4550811824021290590) },
 },
    { { -INT64_C( 7507740545089526719),  INT64_C( 2218023018207253417) },
 },
    { { -INT64_C( 9191243350082271628), -INT64_C( 8581830885716983195) },
 },
    { { -INT64_C( 2760187395494638758),  INT64_C(  664167231916119275) },
 },
    { { -INT64_C( 1243752674535709601), -INT64_C( 6115893445395211696) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_float32x4_t r = simde_vreinterpretq_f32_s64(a);
    simde_float32x4_private r_ = simde_float32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f64_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
  } test_vec[] = {
    { {  INT64_C( 8185646939337236695),  INT64_C( 2688673206683960774) },
 },
    { { -INT64_C( 2164464113465532920), -INT64_C( 4581510018376765077) },
 },
    { {  INT64_C( 7623174301693993172),  INT64_C( 7721143809931890169) },
 },
    { { -INT64_C( 6296687322834995615),  INT64_C( 7549887383541079837) },
 },
    { {  INT64_C( 1153919958250496759),  INT64_C( 1848510735015130585) },
 },
    { {  INT64_C( 2744226032286850352), -INT64_C( 3616685348569136941) },
 },
    { { -INT64_C(  775628366577954795), -INT64_C( 5119791744112570848) },
 },
    { {  INT64_C( 1037017840322201653), -INT64_C( 7341356102690958982) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_float64x2_t r = simde_vreinterpretq_f64_s64(a);
    simde_float64x2_private r_ = simde_float64x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s8_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
  } test_vec[] = {
    { { -INT64_C( 5478452947858036060),  INT64_C( 3027308422447858654) },
 },
    { {  INT64_C( 5308556797850632463), -INT64_C( 8026805502122097337) },
 },
    { {  INT64_C( 6106164720098399992), -INT64_C( 9071691710817547528) },
 },
    { {  INT64_C(  699266036727281954), -INT64_C( 7616685799744106289) },
 },
    { {  INT64_C( 3870946397987588590), -INT64_C( 7450009907100281433) },
 },
    { {  INT64_C( 6125940608990329656), -INT64_C( 8683961970705989561) },
 },
    { {  INT64_C( 2349370996918262823),  INT64_C( 3983389888589053753) },
 },
    { {  INT64_C( 5183137398324808211), -INT64_C( 8803225149115662156) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_int8x16_t r = simde_vreinterpretq_s8_s64(a);
    simde_int8x16_private r_ = simde_int8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s16_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
  } test_vec[] = {
    { {  INT64_C( 7635004779189560581), -INT64_C( 7876646184904941736) },
 },
    { {  INT64_C( 1169612658643635266),  INT64_C( 6731539315348642040) },
 },
    { { -INT64_C( 4616652067830273248),  INT64_C(  509575005423484026) },
 },
    { { -INT64_C( 7493878042357771413),  INT64_C( 5310470915378310909) },
 },
    { { -INT64_C( 1285850860918728448), -INT64_C( 6861936389400897798) },
 },
    { {  INT64_C( 5912259103237926868), -INT64_C( 3679060685047253378) },
 },
    { {  INT64_C( 8706685679711862898), -INT64_C( 7491460063933611470) },
 },
    { { -INT64_C( 6372003961623504661),  INT64_C(  353322092022675790) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_int16x8_t r = simde_vreinterpretq_s16_s64(a);
    simde_int16x8_private r_ = simde_int16x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s32_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
  } test_vec[] = {
    { {  INT64_C( 1900666753600127530), -INT64_C( 3669406538694196815) },
 },
    { {  INT64_C(  274910012553665461),  INT64_C( 4245955537745086196) },
 },
    { { -INT64_C( 2441454381005625427),  INT64_C( 2105070435390701879) },
 },
    { {  INT64_C( 5514684512187493202),  INT64_C( 5073867488594489119) },
 },
    { { -INT64_C( 5930561804499730522),  INT64_C( 6823035952845641003) },
 },
    { {  INT64_C( 3502229382316161526),  INT64_C( 5997326498957077850) },
 },
    { {  INT64_C( 1885559016628126983), -INT64_C( 9108145918797070545) },
 },
    { {  INT64_C( 4798702945091746902), -INT64_C( 4028627368431650792) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_int32x4_t r = simde_vreinterpretq_s32_s64(a);
    simde_int32x4_private r_ = simde_int32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u8_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
  } test_vec[] = {
    { { -INT64_C( 3917874066034605442), -INT64_C( 1949064800907001111) },
 },
    { {  INT64_C(  546159014590848953),  INT64_C(  396535052162892911) },
 },
    { { -INT64_C( 7089481973961799031), -INT64_C( 7610395224178797157) },
 },
    { { -INT64_C( 4984901720799776239),  INT64_C( 5450384428367346454) },
 },
    { { -INT64_C( 3403951431896589199), -INT64_C( 4357881682333843182) },
 },
    { {  INT64_C( 3218210159869166500), -INT64_C( 1627648328125984676) },
 },
    { {  INT64_C( 6309491700457769098),  INT64_C( 3785499309450386962) },
 },
    { { -INT64_C( 3165524243452323889), -INT64_C( 3098938020335461220) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_uint8x16_t r = simde_vreinterpretq_u8_s64(a);
    simde_uint8x16_private r_ = simde_uint8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u16_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
  } test_vec[] = {
    { {  INT64_C( 2688746253838422578),  INT64_C( 6716962639529351604) },
 },
    { { -INT64_C( 7712284921796853919),  INT64_C( 2773637878869444097) },
 },
    { { -INT64_C( 4818748208638480254), -INT64_C( 6250232908632565769) },
 },
    { {  INT64_C( 7747105512504161589), -INT64_C( 8565703520504441083) },
 },
    { { -INT64_C( 9009270136648749774),  INT64_C( 7164569695744980859) },
 },
    { { -INT64_C(  543294039713008481),  INT64_C( 3421630694511770347) },
 },
    { {  INT64_C( 2255567448309366847), -INT64_C(   42415447632333351) },
 },
    { {  INT64_C( 8930496842383866627),  INT64_C( 3613551510055412217) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_uint16x8_t r = simde_vreinterpretq_u16_s64(a);
    simde_uint16x8_private r_ = simde_uint16x8_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u32_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
  } test_vec[] = {
    { { -INT64_C( 1402027193207326413), -INT64_C( 2166409925850784429) },
 },
    { {  INT64_C( 5097930609605478085), -INT64_C( 2295136319892064806) },
 },
    { { -INT64_C( 1648147493708327294),  INT64_C(  846785885976717368) },
 },
    { {  INT64_C( 3932184930325291114), -INT64_C( 2814545987810144925) },
 },
    { { -INT64_C( 3184276263924858800),  INT64_C( 1254095984874570518) },
 },
    { { -INT64_C( 1881399073800678063), -INT64_C( 9193845543012043206) },
 },
    { { -INT64_C( 5092386302282271258), -INT64_C( 3949520022139500936) },
 },
    { { -INT64_C( 5514276790526899183),  INT64_C( 4287616322038361808) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_uint32x4_t r = simde_vreinterpretq_u32_s64(a);
    simde_uint32x4_private r_ = simde_uint32x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u64_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
  } test_vec[] = {
    { { -INT64_C( 7785086221317720197), -INT64_C( 3333025110275361121) },
 },
    { {  INT64_C(  557425576608416606),  INT64_C( 2865286261606638736) },
 },
    { { -INT64_C( 4239772750377888703), -INT64_C( 3177635380408631869) },
 },
    { {  INT64_C( 5524890609138883593),  INT64_C( 6201906476984207934) },
 },
    { {  INT64_C( 8779790245809580525), -INT64_C( 5973333706829537326) },
 },
    { {  INT64_C( 5825966948614322385),  INT64_C( 3887533678598467464) },
 },
    { { -INT64_C( 4186904048721928523), -INT64_C( 5093246922952772609) },
 },
    { {  INT64_C( 3044468128483812318),  INT64_C( 8884400049866898126) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_private a_ = simde_int64x2_to_private(a);
    simde_uint64x2_t r = simde_vreinterpretq_u64_s64(a);
    simde_uint64x2_private r_ = simde_uint64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f32_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
  } test_vec[] = {
    { { UINT8_C(112), UINT8_C(213), UINT8_C(254), UINT8_C(209), UINT8_C( 81), UINT8_C(219), UINT8_C(117), UINT8_C(223) },
 },
    { { UINT8_C(124), UINT8_C(231), UINT8_C(194), UINT8_C(124), UINT8_C(243), UINT8_C( 26), UINT8_C(211), UINT8_C(153) },
 },
    { { UINT8_C(234), UINT8_C( 24), UINT8_C(169), UINT8_C(251), UINT8_C( 31), UINT8_C(217), UINT8_C(225), UINT8_C(202) },
 },
    { { UINT8_C( 55), UINT8_C(239), UINT8_C( 94), UINT8_C(148), UINT8_C(180), UINT8_C(176), UINT8_C( 71), UINT8_C( 36) },
 },
    { { UINT8_C(133), UINT8_C( 70), UINT8_C(245), UINT8_C(214), UINT8_C( 33), UINT8_C(106), UINT8_C(181), UINT8_C(157) },
 },
    { { UINT8_C( 81), UINT8_C(119), UINT8_C( 26), UINT8_C( 68), UINT8_C(145), UINT8_C(237), UINT8_C(222), UINT8_C(123) },
 },
    { { UINT8_C(  6), UINT8_C(135), UINT8_C(118), UINT8_C( 37), UINT8_C( 96), UINT8_C( 87), UINT8_C(240), UINT8_C(151) },
 },
    { { UINT8_C( 70), UINT8_C( 78), UINT8_C( 43), UINT8_C(250), UINT8_C(254), UINT8_C(115), UINT8_C( 30), UINT8_C(131) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_float32x2_t r = simde_vreinterpret_f32_u8(a);
    simde_float32x2_private r_ = simde_float32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f64_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
  } test_vec[] = {
    { { UINT8_C( 51), UINT8_C( 43), UINT8_C(203), UINT8_C(240), UINT8_C(137), UINT8_C( 63), UINT8_C(125), UINT8_C( 11) },
 },
    { { UINT8_C( 45), UINT8_C( 94), UINT8_C( 82), UINT8_C(205), UINT8_C(174), UINT8_C( 96), UINT8_C(128), UINT8_C(  2) },
 },
    { { UINT8_C( 53), UINT8_C(179), UINT8_C(197), UINT8_C( 89), UINT8_C(162), UINT8_C( 51), UINT8_C( 97), UINT8_C(235) },
 },
    { { UINT8_C(108), UINT8_C( 15), UINT8_C(237), UINT8_C(107), UINT8_C( 76), UINT8_C(137), UINT8_C( 47), UINT8_C(128) },
 },
    { { UINT8_C(180), UINT8_C(250), UINT8_C(112), UINT8_C( 61), UINT8_C( 58), UINT8_C(237), UINT8_C( 73), UINT8_C(103) },
 },
    { { UINT8_C( 76), UINT8_C(155), UINT8_C( 52), UINT8_C(250), UINT8_C(251), UINT8_C(180), UINT8_C(252), UINT8_C( 49) },
 },
    { { UINT8_C(104), UINT8_C(194), UINT8_C(138), UINT8_C( 10), UINT8_C(245), UINT8_C(235), UINT8_C(246), UINT8_C( 97) },
 },
    { { UINT8_C(250), UINT8_C(227), UINT8_C(205), UINT8_C( 71), UINT8_C(108), UINT8_C(252), UINT8_C(199), UINT8_C( 32) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_float64x1_t r = simde_vreinterpret_f64_u8(a);
    simde_float64x1_private r_ = simde_float64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s8_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
  } test_vec[] = {
    { { UINT8_C(147), UINT8_C(243), UINT8_C( 65), UINT8_C(112), UINT8_C(131), UINT8_C( 66), UINT8_C(  5), UINT8_C(171) },
 },
    { { UINT8_C( 45), UINT8_C(204), UINT8_C(175), UINT8_C(204), UINT8_C(142), UINT8_C(231), UINT8_C(239), UINT8_C(114) },
 },
    { { UINT8_C(166), UINT8_C(159), UINT8_C(214), UINT8_C( 13), UINT8_C(153), UINT8_C( 94), UINT8_C( 63), UINT8_C(236) },
 },
    { { UINT8_C(218), UINT8_C( 50), UINT8_C( 76), UINT8_C(184), UINT8_C( 58), UINT8_C(231), UINT8_C( 21), UINT8_C(205) },
 },
    { { UINT8_C(218), UINT8_C( 87), UINT8_C( 62), UINT8_C( 93), UINT8_C(153), UINT8_C( 67), UINT8_C(  8), UINT8_C(198) },
 },
    { { UINT8_C( 15), UINT8_C(183), UINT8_C(147), UINT8_C(157), UINT8_C(159), UINT8_C(130), UINT8_C( 15), UINT8_C( 69) },
 },
    { { UINT8_C( 34), UINT8_C(229), UINT8_C( 82), UINT8_C(187), UINT8_C( 67), UINT8_C(146), UINT8_C(168), UINT8_C( 29) },
 },
    { { UINT8_C(196), UINT8_C(244), UINT8_C(214), UINT8_C(254), UINT8_C(219), UINT8_C(235), UINT8_C(204), UINT8_C(182) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_int8x8_t r = simde_vreinterpret_s8_u8(a);
    simde_int8x8_private r_ = simde_int8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s16_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
  } test_vec[] = {
    { { UINT8_C(167), UINT8_C( 27), UINT8_C( 14), UINT8_C(245), UINT8_C(156), UINT8_C(104), UINT8_C(159), UINT8_C(125) },
 },
    { { UINT8_C(167), UINT8_C( 59), UINT8_C(147), UINT8_C(116), UINT8_C(103), UINT8_C( 23), UINT8_C(182), UINT8_C( 28) },
 },
    { { UINT8_C( 55), UINT8_C(112), UINT8_C(154), UINT8_C(182), UINT8_C(106), UINT8_C(171), UINT8_C(127), UINT8_C(159) },
 },
    { { UINT8_C( 56), UINT8_C(206), UINT8_C(241), UINT8_C( 68), UINT8_C(100), UINT8_C( 28), UINT8_C( 38), UINT8_C( 11) },
 },
    { { UINT8_C( 55), UINT8_C( 52), UINT8_C(  0), UINT8_C(211), UINT8_C(157), UINT8_C(159), UINT8_C( 80), UINT8_C( 68) },
 },
    { { UINT8_C(219), UINT8_C(227), UINT8_C(184), UINT8_C( 66), UINT8_C(251), UINT8_C(111), UINT8_C( 94), UINT8_C( 50) },
 },
    { { UINT8_C(223), UINT8_C(248), UINT8_C(232), UINT8_C( 73), UINT8_C(163), UINT8_C(104), UINT8_C(232), UINT8_C(219) },
 },
    { { UINT8_C( 54), UINT8_C(218), UINT8_C( 32), UINT8_C(155), UINT8_C(246), UINT8_C( 70), UINT8_C(166), UINT8_C( 45) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_int16x4_t r = simde_vreinterpret_s16_u8(a);
    simde_int16x4_private r_ = simde_int16x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s32_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
  } test_vec[] = {
    { { UINT8_C(226), UINT8_C(243), UINT8_C( 11), UINT8_C( 58), UINT8_C(188), UINT8_C(180), UINT8_C(226), UINT8_C( 20) },
 },
    { { UINT8_C(127), UINT8_C(241), UINT8_C(231), UINT8_C( 32), UINT8_C(223), UINT8_C(190), UINT8_C( 44), UINT8_C(190) },
 },
    { { UINT8_C( 90), UINT8_C(254), UINT8_C(207), UINT8_C( 71), UINT8_C(211), UINT8_C(206), UINT8_C( 43), UINT8_C(172) },
 },
    { { UINT8_C(184), UINT8_C(201), UINT8_C( 96), UINT8_C(102), UINT8_C(  4), UINT8_C(196), UINT8_C(  2), UINT8_C(231) },
 },
    { { UINT8_C(183), UINT8_C( 14), UINT8_C( 33), UINT8_C(116), UINT8_C(194), UINT8_C(  4), UINT8_C(136), UINT8_C( 65) },
 },
    { { UINT8_C(245), UINT8_C(111), UINT8_C( 97), UINT8_C(212), UINT8_C( 46), UINT8_C(141), UINT8_C(146), UINT8_C(136) },
 },
    { { UINT8_C(139), UINT8_C( 97), UINT8_C(208), UINT8_C( 95), UINT8_C( 47), UINT8_C(251), UINT8_C( 11), UINT8_C(231) },
 },
    { { UINT8_C(197), UINT8_C(108), UINT8_C( 77), UINT8_C(201), UINT8_C( 48), UINT8_C( 79), UINT8_C(176), UINT8_C(231) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_int32x2_t r = simde_vreinterpret_s32_u8(a);
    simde_int32x2_private r_ = simde_int32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s64_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
  } test_vec[] = {
    { { UINT8_C(128), UINT8_C( 94), UINT8_C(134), UINT8_C(227), UINT8_C(176), UINT8_C(188), UINT8_C(228), UINT8_C(209) },
 },
    { { UINT8_C(168), UINT8_C(199), UINT8_C(161), UINT8_C( 80), UINT8_C(249), UINT8_C( 54), UINT8_C( 47), UINT8_C( 39) },
 },
    { { UINT8_C(186), UINT8_C(119), UINT8_C(105), UINT8_C(148), UINT8_C( 32), UINT8_C( 60), UINT8_C( 67), UINT8_C(249) },
 },
    { { UINT8_C(230), UINT8_C( 73), UINT8_C( 95), UINT8_C(201), UINT8_C(179), UINT8_C(210), UINT8_C(243), UINT8_C( 51) },
 },
    { { UINT8_C( 48), UINT8_C(121), UINT8_C( 22), UINT8_C(225), UINT8_C( 53), UINT8_C(250), UINT8_C(178), UINT8_C(222) },
 },
    { { UINT8_C(193), UINT8_C( 83), UINT8_C( 46), UINT8_C(187), UINT8_C(138), UINT8_C( 93), UINT8_C(226), UINT8_C( 68) },
 },
    { { UINT8_C(212), UINT8_C( 75), UINT8_C(216), UINT8_C(244), UINT8_C(135), UINT8_C( 27), UINT8_C(238), UINT8_C(110) },
 },
    { { UINT8_C(101), UINT8_C( 77), UINT8_C( 55), UINT8_C( 24), UINT8_C( 31), UINT8_C( 42), UINT8_C( 75), UINT8_C( 79) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_int64x1_t r = simde_vreinterpret_s64_u8(a);
    simde_int64x1_private r_ = simde_int64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u16_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
  } test_vec[] = {
    { { UINT8_C( 36), UINT8_C(221), UINT8_C( 60), UINT8_C(229), UINT8_C( 49), UINT8_C(244), UINT8_C(111), UINT8_C(188) },
 },
    { { UINT8_C(160), UINT8_C(192), UINT8_C( 80), UINT8_C( 43), UINT8_C(104), UINT8_C(116), UINT8_C(107), UINT8_C( 44) },
 },
    { { UINT8_C(222), UINT8_C(125), UINT8_C( 68), UINT8_C( 25), UINT8_C(191), UINT8_C(146), UINT8_C(106), UINT8_C(110) },
 },
    { { UINT8_C(218), UINT8_C( 61), UINT8_C(146), UINT8_C(203), UINT8_C( 45), UINT8_C( 95), UINT8_C( 11), UINT8_C( 81) },
 },
    { { UINT8_C( 61), UINT8_C( 72), UINT8_C( 55), UINT8_C(110), UINT8_C( 60), UINT8_C(166), UINT8_C( 42), UINT8_C(220) },
 },
    { { UINT8_C(102), UINT8_C(122), UINT8_C(  7), UINT8_C(206), UINT8_C(239), UINT8_C(115), UINT8_C(251), UINT8_C(205) },
 },
    { { UINT8_C(240), UINT8_C( 63), UINT8_C(230), UINT8_C(176), UINT8_C(209), UINT8_C( 80), UINT8_C( 30), UINT8_C(171) },
 },
    { { UINT8_C(141), UINT8_C(177), UINT8_C(118), UINT8_C(186), UINT8_C( 16), UINT8_C(130), UINT8_C( 12), UINT8_C( 77) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_uint16x4_t r = simde_vreinterpret_u16_u8(a);
    simde_uint16x4_private r_ = simde_uint16x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u32_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
  } test_vec[] = {
    { { UINT8_C(186), UINT8_C(  4), UINT8_C( 77), UINT8_C( 72), UINT8_C(170), UINT8_C( 40), UINT8_C(217), UINT8_C(200) },
 },
    { { UINT8_C( 11), UINT8_C(193), UINT8_C( 28), UINT8_C( 12), UINT8_C(113), UINT8_C(159), UINT8_C( 50), UINT8_C(171) },
 },
    { { UINT8_C(  1), UINT8_C(131), UINT8_C(236), UINT8_C(170), UINT8_C(169), UINT8_C(148), UINT8_C(243), UINT8_C(225) },
 },
    { { UINT8_C(201), UINT8_C(223), UINT8_C(238), UINT8_C(192), UINT8_C( 25), UINT8_C( 88), UINT8_C(105), UINT8_C(211) },
 },
    { { UINT8_C( 92), UINT8_C(182), UINT8_C( 27), UINT8_C(  7), UINT8_C(222), UINT8_C(244), UINT8_C(207), UINT8_C(234) },
 },
    { { UINT8_C(181), UINT8_C(236), UINT8_C(246), UINT8_C( 39), UINT8_C(139), UINT8_C( 40), UINT8_C(210), UINT8_C(140) },
 },
    { { UINT8_C(172), UINT8_C(190), UINT8_C( 54), UINT8_C( 85), UINT8_C( 82), UINT8_C( 41), UINT8_C( 54), UINT8_C( 27) },
 },
    { { UINT8_C(  8), UINT8_C( 36), UINT8_C(219), UINT8_C( 33), UINT8_C(125), UINT8_C( 68), UINT8_C(244), UINT8_C(217) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_uint32x2_t r = simde_vreinterpret_u32_u8(a);
    simde_uint32x2_private r_ = simde_uint32x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u64_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
  } test_vec[] = {
    { { UINT8_C(147), UINT8_C( 20), UINT8_C( 14), UINT8_C(234), UINT8_C(152), UINT8_C(134), UINT8_C( 74), UINT8_C(158) },
 },
    { { UINT8_C(207), UINT8_C( 18), UINT8_C( 79), UINT8_C( 23), UINT8_C(206), UINT8_C( 14), UINT8_C(245), UINT8_C(245) },
 },
    { { UINT8_C(157), UINT8_C( 76), UINT8_C(191), UINT8_C(160), UINT8_C(210), UINT8_C(250), UINT8_C(214), UINT8_C( 44) },
 },
    { { UINT8_C(171), UINT8_C( 35), UINT8_C( 36), UINT8_C(253), UINT8_C( 89), UINT8_C( 67), UINT8_C(191), UINT8_C(237) },
 },
    { { UINT8_C( 88), UINT8_C(206), UINT8_C(215), UINT8_C(240), UINT8_C( 84), UINT8_C( 34), UINT8_C(142), UINT8_C( 35) },
 },
    { { UINT8_C( 52), UINT8_C(222), UINT8_C( 59), UINT8_C(  2), UINT8_C(236), UINT8_C( 48), UINT8_C(247), UINT8_C(137) },
 },
    { { UINT8_C(124), UINT8_C(182), UINT8_C( 41), UINT8_C( 78), UINT8_C(176), UINT8_C(  0), UINT8_C(122), UINT8_C( 91) },
 },
    { { UINT8_C( 35), UINT8_C(158), UINT8_C( 88), UINT8_C(124), UINT8_C(226), UINT8_C( 24), UINT8_C(105), UINT8_C( 58) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_private a_ = simde_uint8x8_to_private(a);
    simde_uint64x1_t r = simde_vreinterpret_u64_u8(a);
    simde_uint64x1_private r_ = simde_uint64x1_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f32_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C( 74), UINT8_C( 19), UINT8_C( 69), UINT8_C( 21), UINT8_C( 71), UINT8_C( 59), UINT8_C(199), UINT8_C(127),
        UINT8_C( 82), UINT8_C(179), UINT8_C(169), UINT8_C(199), UINT8_C( 92), UINT8_C( 94), UINT8_C( 56), UINT8_C(138) },
 },
    { { UINT8_C(242), UINT8_C(208), UINT8_C( 27), UINT8_C( 42),    UINT8_MAX, UINT8_C(136), UINT8_C( 16), UINT8_C(131),
        UINT8_C(  2), UINT8_C( 11), UINT8_C( 23), UINT8_C(252), UINT8_C(182), UINT8_C(246), UINT8_C(201), UINT8_C(  0) },
 },
    { { UINT8_C( 10), UINT8_C( 14), UINT8_C( 22), UINT8_C( 81), UINT8_C( 73), UINT8_C(221), UINT8_C(208), UINT8_C(156),
        UINT8_C(144), UINT8_C(121), UINT8_C( 99), UINT8_C(236), UINT8_C(215), UINT8_C(155), UINT8_C(118), UINT8_C(202) },
 },
    { { UINT8_C(108), UINT8_C(145), UINT8_C(244), UINT8_C(107), UINT8_C( 25), UINT8_C(  4), UINT8_C(239), UINT8_C( 28),
        UINT8_C( 15), UINT8_C(  6), UINT8_C( 24), UINT8_C(197), UINT8_C(253), UINT8_C(225), UINT8_C(198), UINT8_C(  7) },
 },
    { { UINT8_C(240), UINT8_C(220), UINT8_C( 88), UINT8_C( 57), UINT8_C(185), UINT8_C( 40), UINT8_C(213), UINT8_C( 73),
        UINT8_C(161), UINT8_C( 56), UINT8_C( 53), UINT8_C(120), UINT8_C(212), UINT8_C(172), UINT8_C( 66), UINT8_C( 64) },
 },
    { { UINT8_C( 61), UINT8_C( 54), UINT8_C(171), UINT8_C( 87), UINT8_C( 58), UINT8_C(154), UINT8_C(115), UINT8_C( 74),
        UINT8_C(161), UINT8_C(139), UINT8_C( 15), UINT8_C(158), UINT8_C(108), UINT8_C(213), UINT8_C(165), UINT8_C( 92) },
 },
    { { UINT8_C(177), UINT8_C(253), UINT8_C(150), UINT8_C(106), UINT8_C( 37), UINT8_C(107), UINT8_C(179), UINT8_C(198),
        UINT8_C(164), UINT8_C(233), UINT8_C( 62), UINT8_C(120), UINT8_C(149), UINT8_C(129), UINT8_C(184), UINT8_C(210) },
 },
    { { UINT8_C(183), UINT8_C( 99), UINT8_C( 41), UINT8_C(242), UINT8_C(254), UINT8_C(156), UINT8_C( 60), UINT8_C(159),
        UINT8_C( 39), UINT8_C( 75), UINT8_C( 61), UINT8_C(148), UINT8_C( 33), UINT8_C(226), UINT8_C(240), UINT8_C(210) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_float32x4_t r = simde_vreinterpretq_f32_u8(a);
    simde_float32x4_private r_ = simde_float32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f64_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C( 87), UINT8_C(122), UINT8_C(239), UINT8_C(208), UINT8_C(235), UINT8_C( 38), UINT8_C(133), UINT8_C(157),
        UINT8_C( 51), UINT8_C(250), UINT8_C( 84), UINT8_C( 64), UINT8_C( 33), UINT8_C(196), UINT8_C(113), UINT8_C(243) },
 },
    { { UINT8_C(192), UINT8_C(103), UINT8_C( 78), UINT8_C(158), UINT8_C( 75), UINT8_C(154), UINT8_C(226), UINT8_C( 23),
        UINT8_C(169), UINT8_C( 97), UINT8_C( 50), UINT8_C( 85), UINT8_C(198), UINT8_C(111), UINT8_C( 46), UINT8_C( 29) },
 },
    { { UINT8_C(233), UINT8_C( 29), UINT8_C(238), UINT8_C(212), UINT8_C( 67), UINT8_C(115), UINT8_C(113), UINT8_C(118),
        UINT8_C(109), UINT8_C(197), UINT8_C(182), UINT8_C(142), UINT8_C(137), UINT8_C( 40), UINT8_C(129), UINT8_C( 73) },
 },
    { { UINT8_C(143), UINT8_C(208), UINT8_C(231), UINT8_C(219), UINT8_C(106), UINT8_C(201), UINT8_C(242), UINT8_C( 20),
        UINT8_C( 43), UINT8_C( 36), UINT8_C(105), UINT8_C(241), UINT8_C(147), UINT8_C(151), UINT8_C( 14), UINT8_C(124) },
 },
    { { UINT8_C(180), UINT8_C(252), UINT8_C( 80), UINT8_C(248), UINT8_C(112), UINT8_C(193), UINT8_C(110), UINT8_C(221),
        UINT8_C(135), UINT8_C( 37), UINT8_C(108), UINT8_C( 16), UINT8_C( 77), UINT8_C(237), UINT8_C( 90), UINT8_C(220) },
 },
    { { UINT8_C(189), UINT8_C( 65), UINT8_C(183), UINT8_C( 40), UINT8_C( 11), UINT8_C(169), UINT8_C( 60), UINT8_C( 54),
        UINT8_C(205), UINT8_C(165), UINT8_C( 39), UINT8_C( 96), UINT8_C( 60), UINT8_C( 53), UINT8_C(220), UINT8_C(240) },
 },
    { { UINT8_C( 50), UINT8_C( 44), UINT8_C(232), UINT8_C(162), UINT8_C(238), UINT8_C( 87), UINT8_C(127), UINT8_C(117),
        UINT8_C(124), UINT8_C(235), UINT8_C(133), UINT8_C(201), UINT8_C(217), UINT8_C(223), UINT8_C(165), UINT8_C(150) },
 },
    { { UINT8_C( 33), UINT8_C( 93), UINT8_C(190), UINT8_C( 44), UINT8_C(  6), UINT8_C(250), UINT8_C( 98), UINT8_C(212),
        UINT8_C(159), UINT8_C(137), UINT8_C( 52), UINT8_C(219), UINT8_C(190), UINT8_C( 17), UINT8_C(204), UINT8_C(240) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_float64x2_t r = simde_vreinterpretq_f64_u8(a);
    simde_float64x2_private r_ = simde_float64x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s8_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C(186), UINT8_C( 15), UINT8_C(251), UINT8_C( 19), UINT8_C(208), UINT8_C( 70), UINT8_C(122), UINT8_C(225),
        UINT8_C( 58), UINT8_C(175), UINT8_C( 82), UINT8_C(136), UINT8_C(204), UINT8_C(209), UINT8_C( 23), UINT8_C(150) },
 },
    { { UINT8_C(222), UINT8_C( 56), UINT8_C(218), UINT8_C( 62), UINT8_C( 18), UINT8_C(198), UINT8_C(207), UINT8_C(180),
        UINT8_C( 84), UINT8_C(208), UINT8_C( 98), UINT8_C(169), UINT8_C(186), UINT8_C(173), UINT8_C( 76), UINT8_C(116) },
 },
    { { UINT8_C(188), UINT8_C( 71), UINT8_C(136), UINT8_C(140), UINT8_C(142), UINT8_C(  2), UINT8_C(110), UINT8_C(200),
        UINT8_C(177), UINT8_C(192), UINT8_C( 80), UINT8_C(125), UINT8_C(145), UINT8_C(103), UINT8_C( 19), UINT8_C(111) },
 },
    { { UINT8_C(160), UINT8_C(238), UINT8_C(173), UINT8_C(178), UINT8_C(180), UINT8_C(124), UINT8_C(102), UINT8_C(  9),
        UINT8_C( 76), UINT8_C(200), UINT8_C(178), UINT8_C(  6), UINT8_C(117), UINT8_C(254), UINT8_C(123), UINT8_C( 49) },
 },
    { { UINT8_C( 70), UINT8_C(  3), UINT8_C(190), UINT8_C(212), UINT8_C(  5), UINT8_C( 44), UINT8_C(156), UINT8_C(182),
        UINT8_C(236), UINT8_C(236), UINT8_C( 51), UINT8_C(125), UINT8_C( 83), UINT8_C( 70), UINT8_C(236), UINT8_C(243) },
 },
    { { UINT8_C( 52), UINT8_C(153), UINT8_C(165), UINT8_C(233), UINT8_C( 22), UINT8_C( 12), UINT8_C(242), UINT8_C( 98),
        UINT8_C(212), UINT8_C(164), UINT8_C(105), UINT8_C( 74), UINT8_C(163), UINT8_C(228), UINT8_C(123), UINT8_C(233) },
 },
    { { UINT8_C(231), UINT8_C( 57), UINT8_C(189), UINT8_C(236), UINT8_C(101), UINT8_C( 89), UINT8_C(162), UINT8_C( 81),
        UINT8_C( 69), UINT8_C(213), UINT8_C(206), UINT8_C(152), UINT8_C( 27), UINT8_C(186), UINT8_C(140), UINT8_C( 80) },
 },
    { { UINT8_C( 84), UINT8_C( 49), UINT8_C( 57), UINT8_C(106), UINT8_C( 61), UINT8_C( 43), UINT8_C(204), UINT8_C( 18),
        UINT8_C(207), UINT8_C( 53), UINT8_C( 92), UINT8_C(114), UINT8_C( 25), UINT8_C(215), UINT8_C( 91), UINT8_C(  0) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_int8x16_t r = simde_vreinterpretq_s8_u8(a);
    simde_int8x16_private r_ = simde_int8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s16_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C(221), UINT8_C( 34), UINT8_C(  9), UINT8_C( 16), UINT8_C( 32), UINT8_C(148), UINT8_C( 20), UINT8_C(161),
        UINT8_C( 71), UINT8_C(215), UINT8_C(169), UINT8_C(199), UINT8_C(183), UINT8_C( 29), UINT8_C(178), UINT8_C( 97) },
 },
    { { UINT8_C(126), UINT8_C(133), UINT8_C(121), UINT8_C( 62), UINT8_C(164), UINT8_C( 32), UINT8_C(194), UINT8_C(193),
        UINT8_C( 79), UINT8_C( 90), UINT8_C(204), UINT8_C( 21), UINT8_C(238), UINT8_C(210), UINT8_C(  9), UINT8_C(203) },
 },
    { { UINT8_C(244), UINT8_C( 19), UINT8_C(220), UINT8_C( 20), UINT8_C(167), UINT8_C(240), UINT8_C(181), UINT8_C(239),
        UINT8_C(199), UINT8_C( 94), UINT8_C(182), UINT8_C(126), UINT8_C(124), UINT8_C(104), UINT8_C(223), UINT8_C(250) },
 },
    { { UINT8_C(237), UINT8_C( 89), UINT8_C( 56), UINT8_C(145), UINT8_C(121), UINT8_C(250), UINT8_C( 83), UINT8_C(200),
        UINT8_C( 84), UINT8_C( 31), UINT8_C(222), UINT8_C( 66), UINT8_C(241), UINT8_C(231), UINT8_C( 14), UINT8_C(229) },
 },
    { { UINT8_C(250), UINT8_C(234), UINT8_C(249), UINT8_C(162), UINT8_C(218), UINT8_C(175), UINT8_C(145), UINT8_C(162),
        UINT8_C( 13), UINT8_C( 71), UINT8_C( 32), UINT8_C(137), UINT8_C(176), UINT8_C(  0), UINT8_C(132), UINT8_C(157) },
 },
    { { UINT8_C( 89), UINT8_C(188), UINT8_C( 47), UINT8_C(210), UINT8_C(183), UINT8_C(130), UINT8_C(155), UINT8_C( 11),
        UINT8_C(161), UINT8_C(121), UINT8_C( 78), UINT8_C(147), UINT8_C( 96), UINT8_C( 92), UINT8_C(120), UINT8_C( 91) },
 },
    { { UINT8_C( 70), UINT8_C(114), UINT8_C(253), UINT8_C( 32), UINT8_C( 33), UINT8_C(142), UINT8_C(194), UINT8_C( 46),
        UINT8_C(213), UINT8_C(227), UINT8_C(184), UINT8_C(133), UINT8_C(227), UINT8_C( 60), UINT8_C( 35), UINT8_C( 60) },
 },
    { { UINT8_C(248), UINT8_C( 82), UINT8_C( 14), UINT8_C(175), UINT8_C(212), UINT8_C(169), UINT8_C(187), UINT8_C(117),
        UINT8_C( 34), UINT8_C(  9), UINT8_C(  8), UINT8_C(131), UINT8_C(101), UINT8_C(129), UINT8_C(222), UINT8_C(171) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_int16x8_t r = simde_vreinterpretq_s16_u8(a);
    simde_int16x8_private r_ = simde_int16x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s32_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C( 91), UINT8_C( 51), UINT8_C( 32), UINT8_C(225), UINT8_C(239), UINT8_C(  3), UINT8_C( 10), UINT8_C(134),
        UINT8_C( 49), UINT8_C(209), UINT8_C(250), UINT8_C(165), UINT8_C( 94), UINT8_C(196), UINT8_C(  3), UINT8_C(217) },
 },
    { { UINT8_C( 35), UINT8_C(151), UINT8_C(185), UINT8_C( 81), UINT8_C(166), UINT8_C( 25), UINT8_C(152), UINT8_C( 24),
        UINT8_C( 26), UINT8_C(151), UINT8_C( 31), UINT8_C(115), UINT8_C(134), UINT8_C(199), UINT8_C(  5), UINT8_C(225) },
 },
    { { UINT8_C(250), UINT8_C( 37), UINT8_C(194), UINT8_C(234), UINT8_C( 40), UINT8_C(205), UINT8_C(112), UINT8_C( 90),
        UINT8_C(158), UINT8_C(106),    UINT8_MAX, UINT8_C(252), UINT8_C( 46), UINT8_C(  2), UINT8_C(213), UINT8_C( 82) },
 },
    { { UINT8_C(154), UINT8_C(142), UINT8_C(163), UINT8_C( 64), UINT8_C(168), UINT8_C( 59), UINT8_C( 88), UINT8_C(194),
        UINT8_C(211), UINT8_C(120), UINT8_C( 53), UINT8_C( 89), UINT8_C( 63), UINT8_C( 58), UINT8_C( 58), UINT8_C( 57) },
 },
    { { UINT8_C( 95), UINT8_C(253), UINT8_C( 35), UINT8_C(135), UINT8_C(202), UINT8_C(147), UINT8_C(225), UINT8_C(104),
        UINT8_C(253), UINT8_C(224), UINT8_C(100), UINT8_C( 44), UINT8_C(227), UINT8_C( 57), UINT8_C(126), UINT8_C(125) },
 },
    { { UINT8_C(200), UINT8_C( 33), UINT8_C(189), UINT8_C(112), UINT8_C( 93), UINT8_C( 22), UINT8_C( 50), UINT8_C( 48),
        UINT8_C(142), UINT8_C(103), UINT8_C(137), UINT8_C(205), UINT8_C(161), UINT8_C(195), UINT8_C(  6), UINT8_C(  0) },
 },
    { { UINT8_C(192), UINT8_C( 42), UINT8_C(135), UINT8_C(138), UINT8_C(189), UINT8_C(105), UINT8_C(242), UINT8_C(187),
        UINT8_C( 73), UINT8_C( 86), UINT8_C(231), UINT8_C( 44), UINT8_C(144), UINT8_C(101), UINT8_C(169), UINT8_C( 88) },
 },
    { { UINT8_C(134), UINT8_C(103), UINT8_C(200), UINT8_C(227), UINT8_C(125), UINT8_C(250), UINT8_C( 19), UINT8_C( 11),
        UINT8_C( 97), UINT8_C(156), UINT8_C(216), UINT8_C(  2), UINT8_C( 96), UINT8_C(222), UINT8_C(  2), UINT8_C( 32) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_int32x4_t r = simde_vreinterpretq_s32_u8(a);
    simde_int32x4_private r_ = simde_int32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s64_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C( 46), UINT8_C(245), UINT8_C(233), UINT8_C(253), UINT8_C( 19), UINT8_C(131), UINT8_C( 29), UINT8_C( 10),
        UINT8_C(144), UINT8_C(167), UINT8_C(104), UINT8_C(229), UINT8_C(128), UINT8_C(142), UINT8_C( 14), UINT8_C( 54) },
 },
    { { UINT8_C(127), UINT8_C(158), UINT8_C(248), UINT8_C(141), UINT8_C( 40), UINT8_C(252), UINT8_C(110), UINT8_C( 25),
        UINT8_C( 81), UINT8_C( 49), UINT8_C( 20), UINT8_C(242), UINT8_C(154), UINT8_C(241), UINT8_C(214), UINT8_C(201) },
 },
    { { UINT8_C(231), UINT8_C(191), UINT8_C(198), UINT8_C(250), UINT8_C( 66), UINT8_C(227), UINT8_C(  4), UINT8_C(210),
        UINT8_C(139), UINT8_C(108), UINT8_C(184), UINT8_C( 11), UINT8_C(250), UINT8_C(198), UINT8_C( 65), UINT8_C(121) },
 },
    { { UINT8_C(100), UINT8_C( 57), UINT8_C(  6), UINT8_C(140), UINT8_C( 54), UINT8_C(117), UINT8_C(165), UINT8_C(135),
        UINT8_C(166), UINT8_C(185), UINT8_C(121), UINT8_C( 64), UINT8_C(170), UINT8_C( 79), UINT8_C(  9), UINT8_C(145) },
 },
    { { UINT8_C( 14), UINT8_C(208), UINT8_C(139), UINT8_C( 80), UINT8_C(179), UINT8_C(144), UINT8_C( 34), UINT8_C( 62),
        UINT8_C(252), UINT8_C(218), UINT8_C( 73), UINT8_C(247), UINT8_C(160), UINT8_C(138), UINT8_C(112), UINT8_C(  4) },
 },
    { { UINT8_C(196), UINT8_C(119), UINT8_C(144), UINT8_C(250), UINT8_C(236), UINT8_C( 53), UINT8_C(129), UINT8_C(146),
        UINT8_C(238), UINT8_C(250), UINT8_C(210), UINT8_C(153), UINT8_C( 73), UINT8_C(220), UINT8_C( 42), UINT8_C( 87) },
 },
    { { UINT8_C(172), UINT8_C(182), UINT8_C(167), UINT8_C( 95), UINT8_C( 70), UINT8_C(201), UINT8_C(158), UINT8_C( 66),
        UINT8_C(164), UINT8_C(231), UINT8_C( 57), UINT8_C( 68), UINT8_C(114), UINT8_C(170), UINT8_C( 73), UINT8_C( 54) },
 },
    { { UINT8_C( 33), UINT8_C(217), UINT8_C( 48), UINT8_C( 13), UINT8_C( 15), UINT8_C(177), UINT8_C(159), UINT8_C(253),
        UINT8_C(171), UINT8_C(113), UINT8_C(150), UINT8_C(244), UINT8_C( 77), UINT8_C(193), UINT8_C( 75), UINT8_C(249) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_int64x2_t r = simde_vreinterpretq_s64_u8(a);
    simde_int64x2_private r_ = simde_int64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u16_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C( 82), UINT8_C(199), UINT8_C(185), UINT8_C(196), UINT8_C(158), UINT8_C( 47), UINT8_C( 61), UINT8_C(140),
        UINT8_C(219), UINT8_C(212), UINT8_C(210), UINT8_C(116), UINT8_C(240), UINT8_C(118), UINT8_C(167), UINT8_C( 68) },
 },
    { { UINT8_C( 44), UINT8_C(199), UINT8_C( 11), UINT8_C(  1), UINT8_C( 43), UINT8_C( 34), UINT8_C(  2), UINT8_C(208),
        UINT8_C( 89), UINT8_C(217), UINT8_C( 35), UINT8_C( 35), UINT8_C(216), UINT8_C(154), UINT8_C(143), UINT8_C( 42) },
 },
    { { UINT8_C( 97), UINT8_C( 72), UINT8_C(239),    UINT8_MAX, UINT8_C(119), UINT8_C( 44), UINT8_C(140), UINT8_C( 82),
        UINT8_C(  1), UINT8_C( 94), UINT8_C(199), UINT8_C(241), UINT8_C(213), UINT8_C(110), UINT8_C( 53), UINT8_C(  1) },
 },
    { { UINT8_C( 53), UINT8_C( 64), UINT8_C(  2), UINT8_C( 96), UINT8_C( 99), UINT8_C(  5), UINT8_C( 48), UINT8_C(188),
        UINT8_C(222), UINT8_C( 83), UINT8_C(223), UINT8_C(183), UINT8_C(237), UINT8_C(110), UINT8_C(225), UINT8_C( 78) },
 },
    { { UINT8_C(182), UINT8_C(208), UINT8_C( 78), UINT8_C( 45), UINT8_C(253), UINT8_C(218), UINT8_C(128), UINT8_C(254),
        UINT8_C( 56), UINT8_C( 71), UINT8_C(239), UINT8_C( 13), UINT8_C(181), UINT8_C( 36), UINT8_C( 15), UINT8_C(234) },
 },
    { { UINT8_C(101), UINT8_C( 17), UINT8_C( 74), UINT8_C(200), UINT8_C( 22), UINT8_C(122), UINT8_C(132), UINT8_C(245),
        UINT8_C(205), UINT8_C( 99), UINT8_C(172), UINT8_C(186), UINT8_C(209), UINT8_C(141), UINT8_C(  8), UINT8_C(135) },
 },
    { { UINT8_C( 94), UINT8_C( 86), UINT8_C(180), UINT8_C( 91), UINT8_C( 48), UINT8_C( 52), UINT8_C( 89), UINT8_C(105),
        UINT8_C(123), UINT8_C( 72), UINT8_C(118), UINT8_C( 48), UINT8_C(108), UINT8_C(133), UINT8_C( 26), UINT8_C(209) },
 },
    { { UINT8_C(151), UINT8_C(100), UINT8_C(153), UINT8_C(173), UINT8_C(222), UINT8_C( 29), UINT8_C(162), UINT8_C(171),
        UINT8_C(128), UINT8_C( 78), UINT8_C(101), UINT8_C( 81), UINT8_C(220), UINT8_C(110), UINT8_C(216), UINT8_C( 58) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_uint16x8_t r = simde_vreinterpretq_u16_u8(a);
    simde_uint16x8_private r_ = simde_uint16x8_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u32_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C( 82), UINT8_C( 69), UINT8_C(228), UINT8_C(116), UINT8_C(114), UINT8_C(137), UINT8_C(229), UINT8_C( 73),
        UINT8_C( 23), UINT8_C(171), UINT8_C(101), UINT8_C(203), UINT8_C(170), UINT8_C(220), UINT8_C(186), UINT8_C(  4) },
 },
    { { UINT8_C( 57), UINT8_C(134), UINT8_C(119), UINT8_C(221), UINT8_C(153), UINT8_C(228), UINT8_C( 75), UINT8_C( 17),
        UINT8_C(120), UINT8_C(139), UINT8_C(153), UINT8_C( 31), UINT8_C( 13), UINT8_C( 56), UINT8_C(176), UINT8_C( 96) },
 },
    { { UINT8_C(125), UINT8_C(149), UINT8_C(212), UINT8_C(240), UINT8_C( 30), UINT8_C(186), UINT8_C( 57), UINT8_C( 54),
        UINT8_C(101), UINT8_C(158), UINT8_C(  1), UINT8_C( 15), UINT8_C(123), UINT8_C(187), UINT8_C( 19), UINT8_C(180) },
 },
    { { UINT8_C( 66), UINT8_C(138), UINT8_C(146), UINT8_C(219), UINT8_C(110), UINT8_C(221), UINT8_C(236), UINT8_C(231),
        UINT8_C(105), UINT8_C(133), UINT8_C(  6), UINT8_C(118), UINT8_C(189), UINT8_C(183), UINT8_C(214), UINT8_C( 59) },
 },
    { { UINT8_C( 76), UINT8_C(171), UINT8_C( 43), UINT8_C(106), UINT8_C(101), UINT8_C(100), UINT8_C(160), UINT8_C(202),
        UINT8_C(  3), UINT8_C(162), UINT8_C(218), UINT8_C(126), UINT8_C( 93), UINT8_C(237), UINT8_C( 50), UINT8_C(159) },
 },
    { { UINT8_C(120), UINT8_C(196), UINT8_C(122), UINT8_C(230), UINT8_C(162), UINT8_C(102), UINT8_C(205), UINT8_C( 11),
        UINT8_C(235), UINT8_C(212), UINT8_C(129), UINT8_C(169), UINT8_C(139), UINT8_C( 88), UINT8_C(228), UINT8_C(215) },
 },
    { { UINT8_C(  3), UINT8_C( 15), UINT8_C( 65), UINT8_C(104), UINT8_C(115), UINT8_C(226), UINT8_C( 50), UINT8_C(118),
        UINT8_C(132), UINT8_C( 12), UINT8_C(244), UINT8_C(225), UINT8_C(250), UINT8_C( 39), UINT8_C(129), UINT8_C(114) },
 },
    { { UINT8_C(235), UINT8_C(251), UINT8_C( 88), UINT8_C(141), UINT8_C( 98), UINT8_C( 38), UINT8_C(152), UINT8_C( 77),
        UINT8_C(250), UINT8_C( 26), UINT8_C(246), UINT8_C(133), UINT8_C(114), UINT8_C(218), UINT8_C( 92), UINT8_C(117) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_uint32x4_t r = simde_vreinterpretq_u32_u8(a);
    simde_uint32x4_private r_ = simde_uint32x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u64_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C(176), UINT8_C( 47), UINT8_C( 11), UINT8_C( 58), UINT8_C( 97), UINT8_C( 66), UINT8_C(184), UINT8_C( 12),
        UINT8_C(238), UINT8_C(198), UINT8_C( 66), UINT8_C(160), UINT8_C( 22), UINT8_C( 35), UINT8_C(163), UINT8_C(194) },
 },
    { { UINT8_C( 84), UINT8_C(146), UINT8_C( 13), UINT8_C( 43), UINT8_C( 21), UINT8_C( 80), UINT8_C(164), UINT8_C(  8),
        UINT8_C(252), UINT8_C( 83), UINT8_C( 68), UINT8_C(251), UINT8_C(  2), UINT8_C(231), UINT8_C( 63), UINT8_C(178) },
 },
    { { UINT8_C( 22), UINT8_C( 74), UINT8_C(237), UINT8_C(119), UINT8_C(141), UINT8_C(165), UINT8_C(131), UINT8_C(123),
        UINT8_C(107), UINT8_C(197), UINT8_C( 27), UINT8_C(130), UINT8_C(232), UINT8_C(190), UINT8_C( 68), UINT8_C( 60) },
 },
    { { UINT8_C( 80), UINT8_C( 82), UINT8_C(104), UINT8_C(102), UINT8_C(162), UINT8_C( 12), UINT8_C(110), UINT8_C(158),
        UINT8_C( 95), UINT8_C(178), UINT8_C(154), UINT8_C( 97), UINT8_C(153), UINT8_C(217), UINT8_C( 19), UINT8_C(175) },
 },
    { { UINT8_C( 35), UINT8_C(  0), UINT8_C( 38), UINT8_C(176), UINT8_C(165), UINT8_C(170), UINT8_C( 44), UINT8_C( 17),
        UINT8_C(111), UINT8_C( 71), UINT8_C(147), UINT8_C( 88), UINT8_C(  6), UINT8_C(215), UINT8_C(148), UINT8_C( 86) },
 },
    { { UINT8_C( 41), UINT8_C(252), UINT8_C(188), UINT8_C(203), UINT8_C(  8), UINT8_C( 43), UINT8_C(106), UINT8_C(103),
        UINT8_C(221), UINT8_C(  4), UINT8_C(200), UINT8_C(119), UINT8_C(221), UINT8_C(220), UINT8_C( 38), UINT8_C(  0) },
 },
    { { UINT8_C(220), UINT8_C( 77), UINT8_C(177), UINT8_C(130), UINT8_C(247), UINT8_C(221), UINT8_C(147), UINT8_C(102),
        UINT8_C( 36), UINT8_C( 38), UINT8_C(190), UINT8_C( 42), UINT8_C(253), UINT8_C( 83), UINT8_C(129), UINT8_C( 39) },
 },
    { { UINT8_C( 79), UINT8_C( 61), UINT8_C(242), UINT8_C( 88), UINT8_C(104), UINT8_C( 92), UINT8_C(191), UINT8_C( 70),
        UINT8_C( 96), UINT8_C(136), UINT8_C(189), UINT8_C( 61), UINT8_C(100), UINT8_C(227), UINT8_C( 62), UINT8_C( 64) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_private a_ = simde_uint8x16_to_private(a);
    simde_uint64x2_t r = simde_vreinterpretq_u64_u8(a);
    simde_uint64x2_private r_ = simde_uint64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f32_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
  } test_vec[] = {
    { { UINT16_C(33507), UINT16_C(59494), UINT16_C(30007), UINT16_C(35832) },
 },
    { { UINT16_C(46775), UINT16_C(12032), UINT16_C( 8902), UINT16_C( 8337) },
 },
    { { UINT16_C(43537), UINT16_C(37876), UINT16_C(10452), UINT16_C(56119) },
 },
    { { UINT16_C( 4464), UINT16_C(52152), UINT16_C( 3403), UINT16_C(11777) },
 },
    { { UINT16_C(26511), UINT16_C(50966), UINT16_C( 3804), UINT16_C(37714) },
 },
    { { UINT16_C(21189), UINT16_C(35779), UINT16_C(21621), UINT16_C(34475) },
 },
    { { UINT16_C(41215), UINT16_C(54041), UINT16_C(20936), UINT16_C(14511) },
 },
    { { UINT16_C(26466), UINT16_C(44291), UINT16_C( 1140), UINT16_C(  987) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_float32x2_t r = simde_vreinterpret_f32_u16(a);
    simde_float32x2_private r_ = simde_float32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f64_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
  } test_vec[] = {
    { { UINT16_C( 9483), UINT16_C(16427), UINT16_C(61280), UINT16_C(61320) },
 },
    { { UINT16_C(61708), UINT16_C(37798), UINT16_C(33678), UINT16_C(42947) },
 },
    { { UINT16_C( 8615), UINT16_C(53267), UINT16_C(40577), UINT16_C(13982) },
 },
    { { UINT16_C( 7345), UINT16_C(32884), UINT16_C(39065), UINT16_C(42079) },
 },
    { { UINT16_C(35518), UINT16_C( 7908), UINT16_C(27769), UINT16_C(34062) },
 },
    { { UINT16_C(46173), UINT16_C(60185), UINT16_C(56375), UINT16_C(56979) },
 },
    { { UINT16_C(42749), UINT16_C(32430), UINT16_C(19524), UINT16_C(62900) },
 },
    { { UINT16_C(10601), UINT16_C(  629), UINT16_C(54465), UINT16_C(32678) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_float64x1_t r = simde_vreinterpret_f64_u16(a);
    simde_float64x1_private r_ = simde_float64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s8_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
  } test_vec[] = {
    { { UINT16_C(37850), UINT16_C(12094), UINT16_C(28613), UINT16_C(54167) },
 },
    { { UINT16_C(14611), UINT16_C(56465), UINT16_C(40885), UINT16_C(23652) },
 },
    { { UINT16_C(18906), UINT16_C( 5146), UINT16_C(32725), UINT16_C(39195) },
 },
    { { UINT16_C( 7126), UINT16_C(50291), UINT16_C(33501), UINT16_C(47348) },
 },
    { { UINT16_C(12821), UINT16_C(56039), UINT16_C(32417), UINT16_C(46510) },
 },
    { { UINT16_C(16312), UINT16_C(28049), UINT16_C(63198), UINT16_C(47305) },
 },
    { { UINT16_C(58175), UINT16_C( 5324), UINT16_C(59491), UINT16_C(14765) },
 },
    { { UINT16_C( 8195), UINT16_C(57853), UINT16_C(62114), UINT16_C(47257) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_int8x8_t r = simde_vreinterpret_s8_u16(a);
    simde_int8x8_private r_ = simde_int8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s16_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
  } test_vec[] = {
    { { UINT16_C(56181), UINT16_C(42985), UINT16_C(47798), UINT16_C( 3233) },
 },
    { { UINT16_C(58242), UINT16_C(62873), UINT16_C(49449), UINT16_C(33758) },
 },
    { { UINT16_C(50296), UINT16_C(42295), UINT16_C(65104), UINT16_C(15723) },
 },
    { { UINT16_C(19339), UINT16_C(59497), UINT16_C(22037), UINT16_C(35422) },
 },
    { { UINT16_C(18225), UINT16_C(59441), UINT16_C(53761), UINT16_C(33780) },
 },
    { { UINT16_C(36277), UINT16_C(57208), UINT16_C(22094), UINT16_C(50786) },
 },
    { { UINT16_C(39195), UINT16_C(27499), UINT16_C(54936), UINT16_C( 9129) },
 },
    { { UINT16_C( 4642), UINT16_C(14091), UINT16_C(26984), UINT16_C(39617) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_int16x4_t r = simde_vreinterpret_s16_u16(a);
    simde_int16x4_private r_ = simde_int16x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s32_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
  } test_vec[] = {
    { { UINT16_C(24639), UINT16_C(32629), UINT16_C(14135), UINT16_C(61730) },
 },
    { { UINT16_C(40550), UINT16_C(48618), UINT16_C(12348), UINT16_C(20638) },
 },
    { { UINT16_C(51024), UINT16_C(16956), UINT16_C(15191), UINT16_C(39519) },
 },
    { { UINT16_C(13932), UINT16_C(62692), UINT16_C(19741), UINT16_C(23705) },
 },
    { { UINT16_C( 3757), UINT16_C(58843), UINT16_C(65093), UINT16_C(44246) },
 },
    { { UINT16_C(49308), UINT16_C(55401), UINT16_C( 2032), UINT16_C(16424) },
 },
    { { UINT16_C(25807), UINT16_C( 9858), UINT16_C(58015), UINT16_C( 3008) },
 },
    { { UINT16_C(42008), UINT16_C(13568), UINT16_C(39410), UINT16_C(40850) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_int32x2_t r = simde_vreinterpret_s32_u16(a);
    simde_int32x2_private r_ = simde_int32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s64_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
  } test_vec[] = {
    { { UINT16_C( 5357), UINT16_C(26804), UINT16_C( 1844), UINT16_C(34757) },
 },
    { { UINT16_C(13646), UINT16_C(39978), UINT16_C(48856), UINT16_C(33659) },
 },
    { { UINT16_C(30572), UINT16_C( 5381), UINT16_C(23799), UINT16_C(32271) },
 },
    { { UINT16_C(12043), UINT16_C(62789), UINT16_C(38605), UINT16_C(47698) },
 },
    { { UINT16_C( 1706), UINT16_C(56866), UINT16_C(59405), UINT16_C(23398) },
 },
    { { UINT16_C(36893), UINT16_C(62967), UINT16_C(29262), UINT16_C(47737) },
 },
    { { UINT16_C(32489), UINT16_C(57551), UINT16_C(57307), UINT16_C(58975) },
 },
    { { UINT16_C(41998), UINT16_C(56283), UINT16_C(11579), UINT16_C(58774) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_int64x1_t r = simde_vreinterpret_s64_u16(a);
    simde_int64x1_private r_ = simde_int64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u8_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
  } test_vec[] = {
    { { UINT16_C(22055), UINT16_C(19585), UINT16_C(41250), UINT16_C( 5379) },
 },
    { { UINT16_C(46099), UINT16_C(50569), UINT16_C(55295), UINT16_C(25373) },
 },
    { { UINT16_C(12707), UINT16_C(64309), UINT16_C(48160), UINT16_C(47304) },
 },
    { { UINT16_C( 8583), UINT16_C(32183), UINT16_C(59924), UINT16_C(15474) },
 },
    { { UINT16_C(62272), UINT16_C(25224), UINT16_C(35988), UINT16_C(43127) },
 },
    { { UINT16_C(   64), UINT16_C(16493), UINT16_C(35799), UINT16_C(31395) },
 },
    { { UINT16_C(55484), UINT16_C(56437), UINT16_C(16020), UINT16_C( 7316) },
 },
    { { UINT16_C(19295), UINT16_C(29593), UINT16_C( 3125), UINT16_C(30383) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_uint8x8_t r = simde_vreinterpret_u8_u16(a);
    simde_uint8x8_private r_ = simde_uint8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u32_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
  } test_vec[] = {
    { { UINT16_C(26673), UINT16_C(47249), UINT16_C(35372), UINT16_C(15460) },
 },
    { { UINT16_C(57841), UINT16_C(41900), UINT16_C(63910), UINT16_C(58747) },
 },
    { { UINT16_C( 6975), UINT16_C(23152), UINT16_C(12482), UINT16_C(40118) },
 },
    { { UINT16_C(35860), UINT16_C(44337), UINT16_C(45683), UINT16_C(42280) },
 },
    { { UINT16_C(47387), UINT16_C(18269), UINT16_C(49731), UINT16_C(13443) },
 },
    { { UINT16_C(12195), UINT16_C(18904), UINT16_C(21289), UINT16_C(26670) },
 },
    { { UINT16_C(40558), UINT16_C(12738), UINT16_C(30926), UINT16_C(58061) },
 },
    { { UINT16_C(65028), UINT16_C(30863), UINT16_C(47025), UINT16_C(52253) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_uint32x2_t r = simde_vreinterpret_u32_u16(a);
    simde_uint32x2_private r_ = simde_uint32x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u64_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
  } test_vec[] = {
    { { UINT16_C(26293), UINT16_C( 7173), UINT16_C(54818), UINT16_C(60544) },
 },
    { { UINT16_C(24048), UINT16_C(55271), UINT16_C(28786), UINT16_C(63191) },
 },
    { { UINT16_C(50441), UINT16_C(40165), UINT16_C(56905), UINT16_C( 1621) },
 },
    { { UINT16_C(60501), UINT16_C(36105), UINT16_C(15052), UINT16_C(33289) },
 },
    { { UINT16_C( 3744), UINT16_C(50078), UINT16_C( 7908), UINT16_C(54703) },
 },
    { { UINT16_C(38523), UINT16_C(61100), UINT16_C(33542), UINT16_C( 4068) },
 },
    { { UINT16_C(51528), UINT16_C(37292), UINT16_C(  424), UINT16_C(64920) },
 },
    { { UINT16_C(41454), UINT16_C(47754), UINT16_C(38108), UINT16_C(31804) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_uint64x1_t r = simde_vreinterpret_u64_u16(a);
    simde_uint64x1_private r_ = simde_uint64x1_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f32_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
  } test_vec[] = {
    { { UINT16_C(14787), UINT16_C(26040), UINT16_C(47560), UINT16_C(54334), UINT16_C(46659), UINT16_C(43287), UINT16_C(28461), UINT16_C(11270) },
 },
    { { UINT16_C(40851), UINT16_C( 3614), UINT16_C(37884), UINT16_C(13423), UINT16_C(40879), UINT16_C(26781), UINT16_C(54165), UINT16_C(22680) },
 },
    { { UINT16_C(20748), UINT16_C(54461), UINT16_C(64522), UINT16_C(19880), UINT16_C(49074), UINT16_C(57334), UINT16_C(64814), UINT16_C(49419) },
 },
    { { UINT16_C(10652), UINT16_C(39375), UINT16_C(16060), UINT16_C(27853), UINT16_C(27614), UINT16_C(29652), UINT16_C(27710), UINT16_C(19147) },
 },
    { { UINT16_C(35261), UINT16_C(50974), UINT16_C(50821), UINT16_C(14100), UINT16_C( 2949), UINT16_C(45846), UINT16_C( 8456), UINT16_C(42100) },
 },
    { { UINT16_C(17226), UINT16_C( 1597), UINT16_C( 2945), UINT16_C(24434), UINT16_C(18038), UINT16_C(46290), UINT16_C(40627), UINT16_C(28926) },
 },
    { { UINT16_C( 7207), UINT16_C(44088), UINT16_C(19682), UINT16_C(26595), UINT16_C(63831), UINT16_C(24346), UINT16_C(36378), UINT16_C(25604) },
 },
    { { UINT16_C(16849), UINT16_C(21098), UINT16_C(56652), UINT16_C(49842), UINT16_C(33827), UINT16_C(54902), UINT16_C(29730), UINT16_C(18759) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_float32x4_t r = simde_vreinterpretq_f32_u16(a);
    simde_float32x4_private r_ = simde_float32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f64_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
  } test_vec[] = {
    { { UINT16_C(27485), UINT16_C(34613), UINT16_C( 7236), UINT16_C(17212), UINT16_C(26790), UINT16_C(14469), UINT16_C(59015), UINT16_C(59527) },
 },
    { { UINT16_C( 6749), UINT16_C(54543), UINT16_C(64291), UINT16_C(27971), UINT16_C(35201), UINT16_C(33391), UINT16_C(41499), UINT16_C(30814) },
 },
    { { UINT16_C(37645), UINT16_C(20736), UINT16_C(15535), UINT16_C(22164), UINT16_C( 6820), UINT16_C(11150), UINT16_C( 5632), UINT16_C(23828) },
 },
    { { UINT16_C( 9008), UINT16_C(21298), UINT16_C(29982), UINT16_C(41153), UINT16_C(12542), UINT16_C( 6434), UINT16_C(33234), UINT16_C(57234) },
 },
    { { UINT16_C(37396), UINT16_C(50224), UINT16_C(50638), UINT16_C(29466), UINT16_C(43231), UINT16_C(57246), UINT16_C(45758), UINT16_C(61244) },
 },
    { { UINT16_C(28373), UINT16_C(62530), UINT16_C(  996), UINT16_C(58004), UINT16_C(46643), UINT16_C( 1532), UINT16_C(36407), UINT16_C(19684) },
 },
    { { UINT16_C( 5408), UINT16_C(60944), UINT16_C(10970), UINT16_C(47457), UINT16_C(  210), UINT16_C(37272), UINT16_C(54450), UINT16_C(34944) },
 },
    { { UINT16_C(49730), UINT16_C( 9852), UINT16_C( 4294), UINT16_C(63753), UINT16_C( 1478), UINT16_C(65279), UINT16_C(58259), UINT16_C(45898) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_float64x2_t r = simde_vreinterpretq_f64_u16(a);
    simde_float64x2_private r_ = simde_float64x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s8_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
  } test_vec[] = {
    { { UINT16_C(30244), UINT16_C(34430), UINT16_C(25246), UINT16_C(16862), UINT16_C(65193), UINT16_C( 4868), UINT16_C(60789), UINT16_C(43837) },
 },
    { { UINT16_C(50205), UINT16_C(31533), UINT16_C(19434), UINT16_C(59923), UINT16_C( 3352), UINT16_C(55771), UINT16_C(  534), UINT16_C(15315) },
 },
    { { UINT16_C(21112), UINT16_C( 6081), UINT16_C(40884), UINT16_C(23896), UINT16_C(23709), UINT16_C( 4976), UINT16_C(44362), UINT16_C(26558) },
 },
    { { UINT16_C(60273), UINT16_C(23522), UINT16_C(63030), UINT16_C(20037), UINT16_C( 8195), UINT16_C( 6695), UINT16_C(64290), UINT16_C(39765) },
 },
    { { UINT16_C( 5709), UINT16_C(  434), UINT16_C( 2741), UINT16_C(21342), UINT16_C(52838), UINT16_C(45158), UINT16_C( 9339), UINT16_C(60440) },
 },
    { { UINT16_C(64015), UINT16_C(17991), UINT16_C(36336), UINT16_C(62612), UINT16_C(48301), UINT16_C(53262), UINT16_C(25527), UINT16_C( 1131) },
 },
    { { UINT16_C( 7545), UINT16_C(11781), UINT16_C(25383), UINT16_C(36225), UINT16_C(59185), UINT16_C(44094), UINT16_C(22027), UINT16_C( 7064) },
 },
    { { UINT16_C(57168), UINT16_C(16737), UINT16_C(62828), UINT16_C( 6709), UINT16_C(17329), UINT16_C(26858), UINT16_C(21926), UINT16_C( 8044) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_int8x16_t r = simde_vreinterpretq_s8_u16(a);
    simde_int8x16_private r_ = simde_int8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s16_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
  } test_vec[] = {
    { { UINT16_C(37371), UINT16_C(  426), UINT16_C( 2791), UINT16_C(64987), UINT16_C(18284), UINT16_C(18051), UINT16_C( 6331), UINT16_C(40537) },
 },
    { { UINT16_C( 8541), UINT16_C(40133), UINT16_C(10784), UINT16_C(43297), UINT16_C(16042), UINT16_C( 6646), UINT16_C(19594), UINT16_C(34381) },
 },
    { { UINT16_C(63454), UINT16_C(50567), UINT16_C(25090), UINT16_C(28355), UINT16_C(18089), UINT16_C(25780), UINT16_C( 3422), UINT16_C(48130) },
 },
    { { UINT16_C(50991), UINT16_C(20312), UINT16_C(31474), UINT16_C(40184), UINT16_C(61368), UINT16_C(17078), UINT16_C(  827), UINT16_C( 6600) },
 },
    { { UINT16_C(20474), UINT16_C(64735), UINT16_C(41649), UINT16_C(23146), UINT16_C( 7912), UINT16_C(18110), UINT16_C(49452), UINT16_C(23298) },
 },
    { { UINT16_C(23432), UINT16_C(31402), UINT16_C(41685), UINT16_C(36119), UINT16_C(52625), UINT16_C(52687), UINT16_C(39120), UINT16_C(51942) },
 },
    { { UINT16_C(50663), UINT16_C(39367), UINT16_C(12647), UINT16_C(20467), UINT16_C(45648), UINT16_C(31894), UINT16_C(39027), UINT16_C(64471) },
 },
    { { UINT16_C(33267), UINT16_C(51318), UINT16_C(36131), UINT16_C(46421), UINT16_C( 9562), UINT16_C(10882), UINT16_C(26813), UINT16_C(42228) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_int16x8_t r = simde_vreinterpretq_s16_u16(a);
    simde_int16x8_private r_ = simde_int16x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s32_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
  } test_vec[] = {
    { { UINT16_C(61872), UINT16_C(58906), UINT16_C(40218), UINT16_C(57729), UINT16_C( 4514), UINT16_C(43884), UINT16_C(60853), UINT16_C(48362) },
 },
    { { UINT16_C(27639), UINT16_C(10283), UINT16_C(29782), UINT16_C( 9365), UINT16_C(13242), UINT16_C(29738), UINT16_C( 2313), UINT16_C(47770) },
 },
    { { UINT16_C(46330), UINT16_C( 5280), UINT16_C( 8785), UINT16_C(62454), UINT16_C(25139), UINT16_C(59550), UINT16_C(35151), UINT16_C(18084) },
 },
    { { UINT16_C(53236), UINT16_C(19054), UINT16_C(  835), UINT16_C(64878), UINT16_C(39222), UINT16_C(16498), UINT16_C( 3234), UINT16_C(40186) },
 },
    { { UINT16_C(39616), UINT16_C( 4528), UINT16_C(42684), UINT16_C(61188), UINT16_C(41480), UINT16_C(22487), UINT16_C(31531), UINT16_C( 8350) },
 },
    { { UINT16_C( 3146), UINT16_C(36202), UINT16_C(55568), UINT16_C(18059), UINT16_C(64882), UINT16_C( 5254), UINT16_C(32777), UINT16_C(51632) },
 },
    { { UINT16_C(24603), UINT16_C(55258), UINT16_C(56839), UINT16_C( 4039), UINT16_C(40576), UINT16_C(44135), UINT16_C( 1306), UINT16_C(25804) },
 },
    { { UINT16_C(13841), UINT16_C( 8690), UINT16_C(32015), UINT16_C(33128), UINT16_C(61050), UINT16_C(33685), UINT16_C(17775), UINT16_C(35404) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_int32x4_t r = simde_vreinterpretq_s32_u16(a);
    simde_int32x4_private r_ = simde_int32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s64_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
  } test_vec[] = {
    { { UINT16_C( 2822), UINT16_C(48884), UINT16_C(29973), UINT16_C( 1714), UINT16_C(13637), UINT16_C(55111), UINT16_C(52574), UINT16_C(  269) },
 },
    { { UINT16_C(20351), UINT16_C(21891), UINT16_C(12725), UINT16_C(62731), UINT16_C(  548), UINT16_C(51419), UINT16_C(42962), UINT16_C(55479) },
 },
    { { UINT16_C(43954), UINT16_C(51350), UINT16_C(18465), UINT16_C(26318), UINT16_C( 5502), UINT16_C(56381), UINT16_C(19171), UINT16_C(25310) },
 },
    { { UINT16_C(24986), UINT16_C(20408), UINT16_C(50066), UINT16_C(46916), UINT16_C( 8389), UINT16_C(38783), UINT16_C(14023), UINT16_C(31087) },
 },
    { { UINT16_C( 1505), UINT16_C(  577), UINT16_C( 3918), UINT16_C(52328), UINT16_C(42277), UINT16_C( 2216), UINT16_C(34544), UINT16_C(35434) },
 },
    { { UINT16_C( 8936), UINT16_C(31449), UINT16_C( 7909), UINT16_C(43569), UINT16_C(45118), UINT16_C( 1345), UINT16_C(45286), UINT16_C(51326) },
 },
    { { UINT16_C(49334), UINT16_C( 1226), UINT16_C(13263), UINT16_C(62672), UINT16_C(30936), UINT16_C(51452), UINT16_C(26623), UINT16_C(59218) },
 },
    { { UINT16_C(11401), UINT16_C(28513), UINT16_C(37706), UINT16_C(34841), UINT16_C(23363), UINT16_C(10893), UINT16_C( 2827), UINT16_C(49650) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_int64x2_t r = simde_vreinterpretq_s64_u16(a);
    simde_int64x2_private r_ = simde_int64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u8_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
  } test_vec[] = {
    { { UINT16_C(31179), UINT16_C(62043), UINT16_C(34234), UINT16_C(60575), UINT16_C(14522), UINT16_C(65218), UINT16_C(28205), UINT16_C( 2962) },
 },
    { { UINT16_C(26700), UINT16_C( 7147), UINT16_C(59748), UINT16_C( 4323), UINT16_C(15518), UINT16_C(23427), UINT16_C(47621), UINT16_C(53345) },
 },
    { { UINT16_C(48179), UINT16_C(60866), UINT16_C(24898), UINT16_C(64729), UINT16_C(40089), UINT16_C(51194), UINT16_C(35850), UINT16_C(22482) },
 },
    { { UINT16_C(48884), UINT16_C(22898), UINT16_C(21927), UINT16_C(17769), UINT16_C(60562), UINT16_C(38816), UINT16_C(  423), UINT16_C(55911) },
 },
    { { UINT16_C(10686), UINT16_C(  200), UINT16_C(41354), UINT16_C( 9468), UINT16_C(63037), UINT16_C(18667), UINT16_C(48515), UINT16_C(30623) },
 },
    { { UINT16_C( 4475), UINT16_C( 8912), UINT16_C(14694), UINT16_C(63591), UINT16_C( 2086), UINT16_C(52623), UINT16_C(62985), UINT16_C(51111) },
 },
    { { UINT16_C(28447), UINT16_C(43719), UINT16_C(49937), UINT16_C(20174), UINT16_C(47546), UINT16_C(15766), UINT16_C(13686), UINT16_C(62132) },
 },
    { { UINT16_C(34118), UINT16_C(44308), UINT16_C(31934), UINT16_C(58533), UINT16_C(13700), UINT16_C(36273), UINT16_C(22827), UINT16_C(19285) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_uint8x16_t r = simde_vreinterpretq_u8_u16(a);
    simde_uint8x16_private r_ = simde_uint8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u32_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
  } test_vec[] = {
    { { UINT16_C(40287), UINT16_C(10453), UINT16_C(  270), UINT16_C(62770), UINT16_C(21454), UINT16_C(20905), UINT16_C(54272), UINT16_C(28818) },
 },
    { { UINT16_C( 1885), UINT16_C(52960), UINT16_C(24818), UINT16_C(27591), UINT16_C(57828), UINT16_C(35098), UINT16_C(11676), UINT16_C(64676) },
 },
    { { UINT16_C(31178), UINT16_C(55588), UINT16_C(22138), UINT16_C(18894), UINT16_C(30634), UINT16_C(43674), UINT16_C(11339), UINT16_C(43290) },
 },
    { { UINT16_C(64052), UINT16_C( 9847), UINT16_C(15963), UINT16_C(16273), UINT16_C(44063), UINT16_C(48329), UINT16_C(28121), UINT16_C(41912) },
 },
    { { UINT16_C(56550), UINT16_C(24956), UINT16_C(18995), UINT16_C(56746), UINT16_C(17602), UINT16_C( 3463), UINT16_C(41329), UINT16_C(42422) },
 },
    { { UINT16_C(11931), UINT16_C(63179), UINT16_C(23660), UINT16_C(35894), UINT16_C(65288), UINT16_C(57672), UINT16_C(  108), UINT16_C(21125) },
 },
    { { UINT16_C(  476), UINT16_C( 4019), UINT16_C(23884), UINT16_C( 3820), UINT16_C(29602), UINT16_C( 4891), UINT16_C(53780), UINT16_C(45240) },
 },
    { { UINT16_C(33536), UINT16_C(27814), UINT16_C(56543), UINT16_C(59640), UINT16_C(16603), UINT16_C(18377), UINT16_C(20032), UINT16_C( 7578) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_uint32x4_t r = simde_vreinterpretq_u32_u16(a);
    simde_uint32x4_private r_ = simde_uint32x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u64_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
  } test_vec[] = {
    { { UINT16_C(37256), UINT16_C( 7287), UINT16_C(13665), UINT16_C(19885), UINT16_C(39602), UINT16_C(36139), UINT16_C(23663), UINT16_C(43651) },
 },
    { { UINT16_C(43283), UINT16_C(33404), UINT16_C(53825), UINT16_C(39703), UINT16_C(31803), UINT16_C( 7036), UINT16_C(31574), UINT16_C(56904) },
 },
    { { UINT16_C(49164), UINT16_C(28154), UINT16_C(43253), UINT16_C(43194), UINT16_C(58690), UINT16_C(45365), UINT16_C(47426), UINT16_C(21851) },
 },
    { { UINT16_C(55394), UINT16_C(41943), UINT16_C(61098), UINT16_C(58687), UINT16_C(47979), UINT16_C(49408), UINT16_C(18742), UINT16_C(17056) },
 },
    { { UINT16_C(39433), UINT16_C(65199), UINT16_C(26946), UINT16_C(33958), UINT16_C(56399), UINT16_C(37174), UINT16_C(37269), UINT16_C(63462) },
 },
    { { UINT16_C(48489), UINT16_C( 5019), UINT16_C(55980), UINT16_C( 6137), UINT16_C(63893), UINT16_C(52440), UINT16_C(30786), UINT16_C(19214) },
 },
    { { UINT16_C(48659), UINT16_C(21834), UINT16_C(61479), UINT16_C(30426), UINT16_C( 4300), UINT16_C(24839), UINT16_C(60833), UINT16_C( 2905) },
 },
    { { UINT16_C(62635), UINT16_C(22302), UINT16_C( 6094), UINT16_C(25454), UINT16_C(17937), UINT16_C(21295), UINT16_C(16063), UINT16_C(53919) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_uint64x2_t r = simde_vreinterpretq_u64_u16(a);
    simde_uint64x2_private r_ = simde_uint64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
  } test_vec[] = {
     { { UINT16_C( 7282), UINT16_C(35752), UINT16_C(40216), UINT16_C(10637) }},
     { { UINT16_C(31845), UINT16_C(38227), UINT16_C( 6865), UINT16_C( 6420) }},
     { { UINT16_C(40987), UINT16_C(34469), UINT16_C(18021), UINT16_C(31566) }},
     { { UINT16_C(39961), UINT16_C(37015), UINT16_C(56150), UINT16_C(51347) }},
     { { UINT16_C(15351), UINT16_C( 3923), UINT16_C(57560), UINT16_C(15929) }},
     { { UINT16_C(35932), UINT16_C(11731), UINT16_C(59302), UINT16_C(49478) }},
     { { UINT16_C(60295), UINT16_C(60743), UINT16_C(38449), UINT16_C(19304) }},
     { { UINT16_C(65330), UINT16_C(35035), UINT16_C(28379), UINT16_C(53840) }},
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_private a_ = simde_uint16x4_to_private(a);
    simde_float16x4_t r = simde_vreinterpret_f16_u16(a);
    simde_float16x4_private r_ = simde_float16x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
  } test_vec[] = {
    { { UINT32_C( 455684687), UINT32_C(1949574478) },
 },
    { { UINT32_C( 629409756), UINT32_C(2117591771) },
 },
    { { UINT32_C( 273504167), UINT32_C( 926363004) },
 },
    { { UINT32_C(3937451016), UINT32_C(3913249434) },
 },
    { { UINT32_C(4060440740), UINT32_C(1785084301) },
 },
    { { UINT32_C( 479193921), UINT32_C(1956300749) },
 },
    { { UINT32_C(2592401182), UINT32_C( 500284181) },
 },
    { { UINT32_C( 285704823), UINT32_C(2583381748) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_float32x2_t r = simde_vreinterpret_f32_u32(a);
    simde_float32x2_private r_ = simde_float32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f64_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
  } test_vec[] = {
    { { UINT32_C(3803574018), UINT32_C( 183881149) },
 },
    { { UINT32_C( 881972491), UINT32_C(2577490452) },
 },
    { { UINT32_C( 231932657), UINT32_C(1707981836) },
 },
    { { UINT32_C(2565105070), UINT32_C(1101186879) },
 },
    { { UINT32_C(1931696054), UINT32_C( 813504548) },
 },
    { { UINT32_C(  40111854), UINT32_C(1654326640) },
 },
    { { UINT32_C( 342846983), UINT32_C(3631824170) },
 },
    { { UINT32_C(3782303138), UINT32_C(3676508964) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_float64x1_t r = simde_vreinterpret_f64_u32(a);
    simde_float64x1_private r_ = simde_float64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s8_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
  } test_vec[] = {
    { { UINT32_C(1082916978), UINT32_C(3918184476) },
 },
    { { UINT32_C(1406603480), UINT32_C( 187667497) },
 },
    { { UINT32_C(2444684576), UINT32_C(2102212792) },
 },
    { { UINT32_C(1162164356), UINT32_C( 839518400) },
 },
    { { UINT32_C( 611489288), UINT32_C( 789445718) },
 },
    { { UINT32_C( 897770764), UINT32_C(2571153785) },
 },
    { { UINT32_C(1445656222), UINT32_C(3017045806) },
 },
    { { UINT32_C(1878530479), UINT32_C( 715194913) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_int8x8_t r = simde_vreinterpret_s8_u32(a);
    simde_int8x8_private r_ = simde_int8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s16_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
  } test_vec[] = {
    { { UINT32_C(1188544432), UINT32_C(1237954591) },
 },
    { { UINT32_C(2327464733), UINT32_C(2915838870) },
 },
    { { UINT32_C( 986850432), UINT32_C(3609662263) },
 },
    { { UINT32_C(2346378695), UINT32_C(1891232960) },
 },
    { { UINT32_C(3400962219), UINT32_C(1578336065) },
 },
    { { UINT32_C(1642646986), UINT32_C(2031006969) },
 },
    { { UINT32_C( 263447000), UINT32_C(3152468724) },
 },
    { { UINT32_C(2152120767), UINT32_C(1508966317) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_int16x4_t r = simde_vreinterpret_s16_u32(a);
    simde_int16x4_private r_ = simde_int16x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s32_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
  } test_vec[] = {
    { { UINT32_C(4190303205), UINT32_C(3421135521) },
 },
    { { UINT32_C(3069286763), UINT32_C(2460414754) },
 },
    { { UINT32_C(1055798285), UINT32_C( 328962366) },
 },
    { { UINT32_C(3891361501), UINT32_C(2664096697) },
 },
    { { UINT32_C(2006420950), UINT32_C(1531150831) },
 },
    { { UINT32_C(1024537626), UINT32_C( 886028071) },
 },
    { { UINT32_C( 712228332), UINT32_C( 725421646) },
 },
    { { UINT32_C(1024667268), UINT32_C(3906788625) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_int32x2_t r = simde_vreinterpret_s32_u32(a);
    simde_int32x2_private r_ = simde_int32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s64_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
  } test_vec[] = {
    { { UINT32_C(1737799811), UINT32_C(4184346154) },
 },
    { { UINT32_C(3557854092), UINT32_C(4004696328) },
 },
    { { UINT32_C( 692391293), UINT32_C(3828726549) },
 },
    { { UINT32_C(1512595862), UINT32_C( 685172645) },
 },
    { { UINT32_C(3381684895), UINT32_C(  96663672) },
 },
    { { UINT32_C(2346308227), UINT32_C( 544836515) },
 },
    { { UINT32_C(2924134040), UINT32_C( 278036345) },
 },
    { { UINT32_C(2238364384), UINT32_C(1085161633) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_int64x1_t r = simde_vreinterpret_s64_u32(a);
    simde_int64x1_private r_ = simde_int64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u8_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
  } test_vec[] = {
    { { UINT32_C(4009940214), UINT32_C(2454320358) },
 },
    { { UINT32_C(2871745685), UINT32_C(2450177441) },
 },
    { { UINT32_C(3471242743), UINT32_C(3298534337) },
 },
    { { UINT32_C(1355394572), UINT32_C( 983668291) },
 },
    { { UINT32_C(1361683306), UINT32_C( 753103511) },
 },
    { { UINT32_C(1893207758), UINT32_C(3254969035) },
 },
    { { UINT32_C(2576410840), UINT32_C(2556243084) },
 },
    { { UINT32_C( 501819098), UINT32_C( 660048572) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_uint8x8_t r = simde_vreinterpret_u8_u32(a);
    simde_uint8x8_private r_ = simde_uint8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u16_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
  } test_vec[] = {
    { { UINT32_C(2334051580), UINT32_C(4009237040) },
 },
    { { UINT32_C(2584288261), UINT32_C(1769017581) },
 },
    { { UINT32_C(2631474304), UINT32_C(1500364826) },
 },
    { { UINT32_C(2537112437), UINT32_C( 134299660) },
 },
    { { UINT32_C(1033117709), UINT32_C(1059818554) },
 },
    { { UINT32_C(2514105768), UINT32_C(3321776965) },
 },
    { { UINT32_C(2170673255), UINT32_C( 232509336) },
 },
    { { UINT32_C( 514069522), UINT32_C(1629922900) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_uint16x4_t r = simde_vreinterpret_u16_u32(a);
    simde_uint16x4_private r_ = simde_uint16x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u64_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
  } test_vec[] = {
    { { UINT32_C( 870101165), UINT32_C(2209815297) },
 },
    { { UINT32_C(2428866423), UINT32_C( 306277594) },
 },
    { { UINT32_C( 381273794), UINT32_C( 528924364) },
 },
    { { UINT32_C(1140512921), UINT32_C(3548919590) },
 },
    { { UINT32_C(3892798695), UINT32_C(4151033472) },
 },
    { { UINT32_C( 679948622), UINT32_C(1597687965) },
 },
    { { UINT32_C(1517679758), UINT32_C(1266351282) },
 },
    { { UINT32_C(4220417236), UINT32_C(2479756972) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_private a_ = simde_uint32x2_to_private(a);
    simde_uint64x1_t r = simde_vreinterpret_u64_u32(a);
    simde_uint64x1_private r_ = simde_uint64x1_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f16_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
  } test_vec[] = {
     { { UINT16_C( 4779), UINT16_C( 1479), UINT16_C(49141), UINT16_C(57936), UINT16_C(57134), UINT16_C( 3057), UINT16_C(61752), UINT16_C(10708) }},
     { { UINT16_C(33733), UINT16_C(35388), UINT16_C( 7219), UINT16_C(61816), UINT16_C(50702), UINT16_C(56093), UINT16_C(28083), UINT16_C(24275) }},
     { { UINT16_C(39551), UINT16_C(29795), UINT16_C(46169), UINT16_C(34647), UINT16_C(18579), UINT16_C(52114), UINT16_C(26426), UINT16_C(65524) }},
     { { UINT16_C(12522), UINT16_C( 7818), UINT16_C(  588), UINT16_C(23311), UINT16_C(11464), UINT16_C(31542), UINT16_C( 2713), UINT16_C( 6361) }},
     { { UINT16_C(15780), UINT16_C(65165), UINT16_C(58609), UINT16_C(33925), UINT16_C( 6188), UINT16_C(26191), UINT16_C(17535), UINT16_C(26982) }},
     { { UINT16_C(61556), UINT16_C(49543), UINT16_C(38642), UINT16_C(47900), UINT16_C(21186), UINT16_C(23350), UINT16_C( 4188), UINT16_C(  372) }},
     { { UINT16_C(  333), UINT16_C(16127), UINT16_C(34021), UINT16_C( 4546), UINT16_C( 4508), UINT16_C( 7032), UINT16_C(56917), UINT16_C(51845) }},
     { { UINT16_C( 3278), UINT16_C(49291), UINT16_C(42915), UINT16_C(25979), UINT16_C(45817), UINT16_C(22209), UINT16_C(13762), UINT16_C( 3927) }},
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_private a_ = simde_uint16x8_to_private(a);
    simde_float16x8_t r = simde_vreinterpretq_f16_u16(a);
    simde_float16x8_private r_ = simde_float16x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f32_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
  } test_vec[] = {
    { { UINT32_C(3279084377), UINT32_C(2161745592), UINT32_C(3654801364), UINT32_C(3056199879) },
 },
    { { UINT32_C(1218747532), UINT32_C( 135127342), UINT32_C(1086738445), UINT32_C(2027280927) },
 },
    { { UINT32_C(1832601525), UINT32_C(3119322341), UINT32_C(2995963115), UINT32_C( 946453676) },
 },
    { { UINT32_C(2273316184), UINT32_C(4220489454), UINT32_C(4248524254), UINT32_C(3832942639) },
 },
    { { UINT32_C(1011986775), UINT32_C(2985705158), UINT32_C(2942601219), UINT32_C(2649279812) },
 },
    { { UINT32_C(3374606554), UINT32_C(3586438134), UINT32_C( 936509448), UINT32_C(1746618384) },
 },
    { { UINT32_C(3232001274), UINT32_C(2909903530), UINT32_C(1734202659), UINT32_C(2097431970) },
 },
    { { UINT32_C(2756061357), UINT32_C(3816360667), UINT32_C( 454707978), UINT32_C(2390963604) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_float32x4_t r = simde_vreinterpretq_f32_u32(a);
    simde_float32x4_private r_ = simde_float32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f64_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
  } test_vec[] = {
    { { UINT32_C( 798628804), UINT32_C(2308740029), UINT32_C(1010183400), UINT32_C( 499135747) },
 },
    { { UINT32_C(3302186879), UINT32_C(1617207352), UINT32_C(1291082784), UINT32_C(3849247008) },
 },
    { { UINT32_C(2970880244), UINT32_C(2201727131), UINT32_C(3753865692), UINT32_C( 654147750) },
 },
    { { UINT32_C( 401264863), UINT32_C(2423803504), UINT32_C(3420220587), UINT32_C( 967854661) },
 },
    { { UINT32_C(4008428627), UINT32_C(1366435444), UINT32_C(1026568599), UINT32_C(2439196081) },
 },
    { { UINT32_C(1839746813), UINT32_C(1207771292), UINT32_C(3524516237), UINT32_C(1997325092) },
 },
    { { UINT32_C(4234540936), UINT32_C(3025000221), UINT32_C(3136388617), UINT32_C(2840286635) },
 },
    { { UINT32_C(1058469027), UINT32_C(2709984276), UINT32_C( 292854509), UINT32_C(3850928221) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_float64x2_t r = simde_vreinterpretq_f64_u32(a);
    simde_float64x2_private r_ = simde_float64x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s8_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
  } test_vec[] = {
    { { UINT32_C( 298228994), UINT32_C( 760894604), UINT32_C(3945189982), UINT32_C(1190286776) },
 },
    { { UINT32_C(1621610492), UINT32_C(1517645912), UINT32_C( 933037971), UINT32_C(2965300397) },
 },
    { { UINT32_C( 247563394), UINT32_C( 909843416), UINT32_C(2787271149), UINT32_C(3018593463) },
 },
    { { UINT32_C(1007916259), UINT32_C(2543224836), UINT32_C(1036989328), UINT32_C(2599259416) },
 },
    { { UINT32_C(3936923154), UINT32_C(3072451786), UINT32_C(4233970501), UINT32_C(1001343575) },
 },
    { { UINT32_C(3799499742), UINT32_C(3682143563), UINT32_C(1478051904), UINT32_C(3908175574) },
 },
    { { UINT32_C(2144508853), UINT32_C(3291935615), UINT32_C(2395051062), UINT32_C(3167318238) },
 },
    { { UINT32_C(2141077555), UINT32_C(2371491661), UINT32_C( 921072480), UINT32_C( 790550650) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_int8x16_t r = simde_vreinterpretq_s8_u32(a);
    simde_int8x16_private r_ = simde_int8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s16_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
  } test_vec[] = {
    { { UINT32_C(2708620229), UINT32_C( 717266002), UINT32_C(1782875301), UINT32_C(1655354358) },
 },
    { { UINT32_C(1944699603), UINT32_C(2523708845), UINT32_C(3280833691), UINT32_C(3291942911) },
 },
    { { UINT32_C(2774903122), UINT32_C(3939444037), UINT32_C(2689864618), UINT32_C(2583887814) },
 },
    { { UINT32_C(1846406081), UINT32_C(1141144232), UINT32_C(  84381958), UINT32_C(4090052257) },
 },
    { { UINT32_C( 764948456), UINT32_C(4263012180), UINT32_C(1100901498), UINT32_C( 752590955) },
 },
    { { UINT32_C( 882567307), UINT32_C(1752735586), UINT32_C(3513614128), UINT32_C(2781165501) },
 },
    { { UINT32_C(3134414182), UINT32_C(1069149125), UINT32_C(3279968087), UINT32_C(2213501944) },
 },
    { { UINT32_C(2797046340), UINT32_C(1494167337), UINT32_C(1814789294), UINT32_C( 420606131) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_int16x8_t r = simde_vreinterpretq_s16_u32(a);
    simde_int16x8_private r_ = simde_int16x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s32_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
  } test_vec[] = {
    { { UINT32_C(1237267332), UINT32_C(4212671649), UINT32_C( 854252956), UINT32_C(3669148588) },
 },
    { { UINT32_C( 180018859), UINT32_C(1066799467), UINT32_C( 265430687), UINT32_C(3192201018) },
 },
    { { UINT32_C(4077323346), UINT32_C(3840811080), UINT32_C(2853624317), UINT32_C(1199884444) },
 },
    { { UINT32_C( 307314343), UINT32_C(3998345295), UINT32_C(1224614670), UINT32_C(2483503938) },
 },
    { { UINT32_C(2408058439), UINT32_C( 745764398), UINT32_C(3956705871), UINT32_C(4180826706) },
 },
    { { UINT32_C(3893068952), UINT32_C(2060868716), UINT32_C(3267548288), UINT32_C(1582811415) },
 },
    { { UINT32_C( 116252632), UINT32_C(2771542357), UINT32_C(1032849643), UINT32_C(4214735714) },
 },
    { { UINT32_C(3018015303), UINT32_C( 523090335), UINT32_C(2783047566), UINT32_C(2432972985) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_int32x4_t r = simde_vreinterpretq_s32_u32(a);
    simde_int32x4_private r_ = simde_int32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s64_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
  } test_vec[] = {
    { { UINT32_C( 904851114), UINT32_C( 357340730), UINT32_C(4279416342), UINT32_C(2212412929) },
 },
    { { UINT32_C( 954152116), UINT32_C(3376279475), UINT32_C( 588881638), UINT32_C(2462761447) },
 },
    { { UINT32_C(3922180527), UINT32_C(1711149903), UINT32_C(3412332746), UINT32_C(2202944206) },
 },
    { { UINT32_C( 716909943), UINT32_C(  49543452), UINT32_C(2116357527), UINT32_C(2098262222) },
 },
    { { UINT32_C(4167554985), UINT32_C(3042797035), UINT32_C(1149288822), UINT32_C(2076691972) },
 },
    { { UINT32_C( 413500411), UINT32_C( 320510332), UINT32_C(1955676326), UINT32_C(3656491568) },
 },
    { { UINT32_C(1691441273), UINT32_C( 874065598), UINT32_C(4084767215), UINT32_C(1668169831) },
 },
    { { UINT32_C(1065030851), UINT32_C(1397921197), UINT32_C(  96986069), UINT32_C(4292786309) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_int64x2_t r = simde_vreinterpretq_s64_u32(a);
    simde_int64x2_private r_ = simde_int64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u8_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
  } test_vec[] = {
    { { UINT32_C(1105538222), UINT32_C(3755743071), UINT32_C(1126146626), UINT32_C(2100132933) },
 },
    { { UINT32_C(2827012237), UINT32_C(1563107933), UINT32_C(1378456288), UINT32_C( 200370268) },
 },
    { { UINT32_C(4081899156), UINT32_C( 802367725), UINT32_C( 275968715), UINT32_C(4237139823) },
 },
    { { UINT32_C(3315863144), UINT32_C( 270716720), UINT32_C(3194178401), UINT32_C(1204376755) },
 },
    { { UINT32_C( 406525227), UINT32_C( 155717182), UINT32_C(1863956992), UINT32_C(3261834842) },
 },
    { { UINT32_C(3850833844), UINT32_C(1089841886), UINT32_C(2852018421), UINT32_C(3639658413) },
 },
    { { UINT32_C( 451947484), UINT32_C( 975386681), UINT32_C(1302936819), UINT32_C(2534348259) },
 },
    { { UINT32_C(  58496548), UINT32_C( 910389824), UINT32_C(2011120074), UINT32_C(3830435592) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_uint8x16_t r = simde_vreinterpretq_u8_u32(a);
    simde_uint8x16_private r_ = simde_uint8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u16_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
  } test_vec[] = {
    { { UINT32_C(2012347191), UINT32_C( 228853529), UINT32_C(3184606882), UINT32_C(2192724089) },
 },
    { { UINT32_C(3249853973), UINT32_C( 441778337), UINT32_C(2784320210), UINT32_C(1495580194) },
 },
    { { UINT32_C(3536852409), UINT32_C(3202315292), UINT32_C( 729526706), UINT32_C( 397225473) },
 },
    { { UINT32_C(2782421252), UINT32_C( 884944482), UINT32_C(2866394504), UINT32_C( 738524531) },
 },
    { { UINT32_C( 805229586), UINT32_C(4226670153), UINT32_C(2418502031), UINT32_C(2611467415) },
 },
    { { UINT32_C(2554429494), UINT32_C( 919339182), UINT32_C( 685811381), UINT32_C(3059016867) },
 },
    { { UINT32_C(  48583609), UINT32_C(3237859889), UINT32_C(3528467515), UINT32_C( 795801849) },
 },
    { { UINT32_C( 650620792), UINT32_C(1700565935), UINT32_C(3717020729), UINT32_C(3667124769) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_uint16x8_t r = simde_vreinterpretq_u16_u32(a);
    simde_uint16x8_private r_ = simde_uint16x8_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u64_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
  } test_vec[] = {
    { { UINT32_C(2570512756), UINT32_C(3830718427), UINT32_C(3229057798), UINT32_C(1611638719) },
 },
    { { UINT32_C(3729645958), UINT32_C(1980229974), UINT32_C(3183866417), UINT32_C(4227508103) },
 },
    { { UINT32_C(1804873872), UINT32_C(1448142928), UINT32_C( 722913131), UINT32_C(4102760046) },
 },
    { { UINT32_C(1574164487), UINT32_C(4074035905), UINT32_C(1420794317), UINT32_C(3494881600) },
 },
    { { UINT32_C( 691790809), UINT32_C( 931105739), UINT32_C(3227686482), UINT32_C(3283479996) },
 },
    { { UINT32_C(2250279109), UINT32_C( 796456034), UINT32_C(3447924621), UINT32_C(2845692624) },
 },
    { { UINT32_C(2178144693), UINT32_C(3082310244), UINT32_C(2759269096), UINT32_C(3429313543) },
 },
    { { UINT32_C( 391284916), UINT32_C( 172411516), UINT32_C(3252144881), UINT32_C(1382708636) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_private a_ = simde_uint32x4_to_private(a);
    simde_uint64x2_t r = simde_vreinterpretq_u64_u32(a);
    simde_uint64x2_private r_ = simde_uint64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f32_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
  } test_vec[] = {
    { { UINT64_C( 8779430749390950521) },
 },
    { { UINT64_C( 5787192216487944357) },
 },
    { { UINT64_C( 1212378576244495394) },
 },
    { { UINT64_C(11587186962892113876) },
 },
    { { UINT64_C(15419974588312544197) },
 },
    { { UINT64_C(  584303456178448674) },
 },
    { { UINT64_C( 9413963231737312176) },
 },
    { { UINT64_C(10928834220922494436) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    simde_float32x2_t r = simde_vreinterpret_f32_u64(a);
    simde_float32x2_private r_ = simde_float32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
  } test_vec[] = {
    { { UINT64_C(16607055731308338601) },
 },
    { { UINT64_C(   50860304274552481) },
 },
    { { UINT64_C( 9862794963658077786) },
 },
    { { UINT64_C(12392464720683648170) },
 },
    { { UINT64_C( 8689486400691157374) },
 },
    { { UINT64_C( 1541513907969526327) },
 },
    { { UINT64_C( 1716032456096988804) },
 },
    { { UINT64_C( 1658292891718957143) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    simde_float64x1_t r = simde_vreinterpret_f64_u64(a);
    simde_float64x1_private r_ = simde_float64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s8_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
  } test_vec[] = {
    { { UINT64_C( 6944854049650135482) },
 },
    { { UINT64_C( 2643384172688610151) },
 },
    { { UINT64_C( 9694401264440423225) },
 },
    { { UINT64_C(15030064565503554144) },
 },
    { { UINT64_C( 7145989937937443285) },
 },
    { { UINT64_C(10467610559678064954) },
 },
    { { UINT64_C( 2610778010878432799) },
 },
    { { UINT64_C(11146599043610132938) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    simde_int8x8_t r = simde_vreinterpret_s8_u64(a);
    simde_int8x8_private r_ = simde_int8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s16_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
  } test_vec[] = {
    { { UINT64_C( 3986353266778962006) },
 },
    { { UINT64_C( 7176681434443920232) },
 },
    { { UINT64_C( 9525955270665666247) },
 },
    { { UINT64_C(13394712871255028064) },
 },
    { { UINT64_C( 4535400624906860172) },
 },
    { { UINT64_C(10650597281808260014) },
 },
    { { UINT64_C( 8458283561633060611) },
 },
    { { UINT64_C(  300254048795550477) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    simde_int16x4_t r = simde_vreinterpret_s16_u64(a);
    simde_int16x4_private r_ = simde_int16x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s32_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
  } test_vec[] = {
    { { UINT64_C(18361485350794555758) },
 },
    { { UINT64_C( 4996426384215785705) },
 },
    { { UINT64_C(11006711228546924526) },
 },
    { { UINT64_C(10812642598701388252) },
 },
    { { UINT64_C(13100146462438765355) },
 },
    { { UINT64_C( 3308471443271409489) },
 },
    { { UINT64_C( 5760322122107306700) },
 },
    { { UINT64_C( 3446722680712776215) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    simde_int32x2_t r = simde_vreinterpret_s32_u64(a);
    simde_int32x2_private r_ = simde_int32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s64_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
  } test_vec[] = {
    { { UINT64_C( 5657919274295558869) },
 },
    { { UINT64_C( 3965159768771266939) },
 },
    { { UINT64_C( 5087912792556967306) },
 },
    { { UINT64_C(  256521758694905530) },
 },
    { { UINT64_C( 4270793162607544667) },
 },
    { { UINT64_C( 3095497553213558000) },
 },
    { { UINT64_C( 1981335759696853887) },
 },
    { { UINT64_C( 6874422688824928820) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    simde_int64x1_t r = simde_vreinterpret_s64_u64(a);
    simde_int64x1_private r_ = simde_int64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u8_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
  } test_vec[] = {
    { { UINT64_C( 8751185780542309541) },
 },
    { { UINT64_C( 1964445804772003291) },
 },
    { { UINT64_C(10563097091345027527) },
 },
    { { UINT64_C(14780275390623131008) },
 },
    { { UINT64_C( 1886520334338935450) },
 },
    { { UINT64_C(  322713523396222801) },
 },
    { { UINT64_C( 4033920933575331731) },
 },
    { { UINT64_C( 3996921152915932802) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    simde_uint8x8_t r = simde_vreinterpret_u8_u64(a);
    simde_uint8x8_private r_ = simde_uint8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u16_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
  } test_vec[] = {
    { { UINT64_C(15807686447648144263) },
 },
    { { UINT64_C(13586087338080146970) },
 },
    { { UINT64_C( 1229395662396261383) },
 },
    { { UINT64_C( 3399258566591543321) },
 },
    { { UINT64_C( 5224131783317520018) },
 },
    { { UINT64_C(12978948260242732014) },
 },
    { { UINT64_C( 8100327936849454977) },
 },
    { { UINT64_C(17831050982460608157) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    simde_uint16x4_t r = simde_vreinterpret_u16_u64(a);
    simde_uint16x4_private r_ = simde_uint16x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u32_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
  } test_vec[] = {
    { { UINT64_C( 9719491169896031772) },
 },
    { { UINT64_C(12281698703164900773) },
 },
    { { UINT64_C( 6074207952736949374) },
 },
    { { UINT64_C(12717252293388281153) },
 },
    { { UINT64_C(16494333851909467816) },
 },
    { { UINT64_C( 5060794498848419243) },
 },
    { { UINT64_C( 2731966319390488994) },
 },
    { { UINT64_C(13928960856351069961) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_private a_ = simde_uint64x1_to_private(a);
    simde_uint32x2_t r = simde_vreinterpret_u32_u64(a);
    simde_uint32x2_private r_ = simde_uint32x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f32_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
  } test_vec[] = {
    { { UINT64_C( 1234218851471792026), UINT64_C( 2677674681134575894) },
 },
    { { UINT64_C(14515460789981832380), UINT64_C( 8215729928409844471) },
 },
    { { UINT64_C(18432155657786037817), UINT64_C(11578942536244388252) },
 },
    { { UINT64_C(16827624080118754063), UINT64_C( 5552162173842289092) },
 },
    { { UINT64_C(16230363121171568980), UINT64_C( 8591211574267264694) },
 },
    { { UINT64_C(  117863513551373256), UINT64_C( 8002802099049782445) },
 },
    { { UINT64_C(11810948322241091523), UINT64_C( 4217752382814901672) },
 },
    { { UINT64_C( 2754116619510988282), UINT64_C( 4755228904491897970) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_float32x4_t r = simde_vreinterpretq_f32_u64(a);
    simde_float32x4_private r_ = simde_float32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f64_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
  } test_vec[] = {
    { { UINT64_C(15792920702104947431), UINT64_C( 4521637955443876984) },
 },
    { { UINT64_C(11707834749182451748), UINT64_C(15274192250269424470) },
 },
    { { UINT64_C(  661533889626495134), UINT64_C(10242121696137139489) },
 },
    { { UINT64_C(  883403401688261107), UINT64_C(  762781161339000790) },
 },
    { { UINT64_C(  388589280762374089), UINT64_C( 4528384042351654880) },
 },
    { { UINT64_C( 3022232369636497454), UINT64_C(11830534945542760887) },
 },
    { { UINT64_C(17731062154276080423), UINT64_C( 3955312798166219611) },
 },
    { { UINT64_C(11127563320735482609), UINT64_C(   32628938752481525) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_float64x2_t r = simde_vreinterpretq_f64_u64(a);
    simde_float64x2_private r_ = simde_float64x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s8_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
  } test_vec[] = {
    { { UINT64_C( 2322636136670922143), UINT64_C( 5598901547067610440) },
 },
    { { UINT64_C(13672952454968309605), UINT64_C(14002346704856045130) },
 },
    { { UINT64_C(  305025124668412889), UINT64_C( 5032682288508933183) },
 },
    { { UINT64_C( 7364161768165345188), UINT64_C( 3313994378587537432) },
 },
    { { UINT64_C( 6161068422823701695), UINT64_C(14644779267273947415) },
 },
    { { UINT64_C( 1819015547946221244), UINT64_C(  428495374170495345) },
 },
    { { UINT64_C(15359808819437779646), UINT64_C( 8749097411148515194) },
 },
    { { UINT64_C(10259639877273561927), UINT64_C(14228074120516711721) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_int8x16_t r = simde_vreinterpretq_s8_u64(a);
    simde_int8x16_private r_ = simde_int8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s16_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
  } test_vec[] = {
    { { UINT64_C( 4207544517074619564), UINT64_C(17983195729350452668) },
 },
    { { UINT64_C(14769595933460037143), UINT64_C( 2242542422084417963) },
 },
    { { UINT64_C(17209837690262716200), UINT64_C( 5997420568642393605) },
 },
    { { UINT64_C(18206080017375701916), UINT64_C(  110807516602613238) },
 },
    { { UINT64_C( 7695087595622811049), UINT64_C( 1303202160156891015) },
 },
    { { UINT64_C(  963653872485538323), UINT64_C( 4409023572102015572) },
 },
    { { UINT64_C(14093140080987851716), UINT64_C( 4306456267775623227) },
 },
    { { UINT64_C(11230286730154127797), UINT64_C( 1421440177691774952) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_int16x8_t r = simde_vreinterpretq_s16_u64(a);
    simde_int16x8_private r_ = simde_int16x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s32_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
  } test_vec[] = {
    { { UINT64_C(15092064537549437282), UINT64_C(10864827923211013704) },
 },
    { { UINT64_C( 5535174154542260813), UINT64_C(10136250544302758728) },
 },
    { { UINT64_C(11761525752944890796), UINT64_C(16296547469103199523) },
 },
    { { UINT64_C(13760420417112478233), UINT64_C( 6568748200859368817) },
 },
    { { UINT64_C( 9543969152595921780), UINT64_C(12855874340911424243) },
 },
    { { UINT64_C(13043640873963515600), UINT64_C(10293671953509136847) },
 },
    { { UINT64_C(10333738717266419332), UINT64_C(10069345882703560306) },
 },
    { { UINT64_C( 4316653424248691182), UINT64_C( 3798949770022238223) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_int32x4_t r = simde_vreinterpretq_s32_u64(a);
    simde_int32x4_private r_ = simde_int32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s64_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
  } test_vec[] = {
    { { UINT64_C( 2573975289093980101), UINT64_C(12987093788008753529) },
 },
    { { UINT64_C(10893662621074775982), UINT64_C( 9071823841222376635) },
 },
    { { UINT64_C(  728885576711600406), UINT64_C( 2945388765883141678) },
 },
    { { UINT64_C(14412968017312414975), UINT64_C(12400870028522094562) },
 },
    { { UINT64_C(10975768628114679222), UINT64_C( 6085387108246304209) },
 },
    { { UINT64_C( 8391551434180684704), UINT64_C(13909410374581439942) },
 },
    { { UINT64_C( 4759841299535277580), UINT64_C( 1528972579837956751) },
 },
    { { UINT64_C( 9759642074302577259), UINT64_C(12992863654388138115) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_int64x2_t r = simde_vreinterpretq_s64_u64(a);
    simde_int64x2_private r_ = simde_int64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u8_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
  } test_vec[] = {
    { { UINT64_C( 9602034079943150237), UINT64_C(15071447892160942436) },
 },
    { { UINT64_C( 7977050267529101445), UINT64_C(15152987898855457686) },
 },
    { { UINT64_C( 3074072634548977156), UINT64_C(14497327183391996253) },
 },
    { { UINT64_C( 8357763767761154458), UINT64_C( 5568845286471110208) },
 },
    { { UINT64_C(18226659911175066113), UINT64_C( 1720527327522890708) },
 },
    { { UINT64_C(16612550484748069179), UINT64_C( 5208029548622103729) },
 },
    { { UINT64_C(12002096110392883190), UINT64_C(12770693919310474149) },
 },
    { { UINT64_C( 3752436936427036807), UINT64_C(  623876170662637081) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_uint8x16_t r = simde_vreinterpretq_u8_u64(a);
    simde_uint8x16_private r_ = simde_uint8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u16_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
  } test_vec[] = {
    { { UINT64_C( 4581232213571832684), UINT64_C( 1476113207327915279) },
 },
    { { UINT64_C( 1473717667153826830), UINT64_C( 3779245527683887938) },
 },
    { { UINT64_C(15405631003950577694), UINT64_C( 1801577341105853896) },
 },
    { { UINT64_C(16199323197070044241), UINT64_C( 1548692872333386625) },
 },
    { { UINT64_C( 5306202986939200775), UINT64_C( 8315111807944860737) },
 },
    { { UINT64_C(10277774060136857378), UINT64_C( 6083332082561989985) },
 },
    { { UINT64_C(13390826188593827083), UINT64_C( 7133537160237746794) },
 },
    { { UINT64_C(10125996505298054890), UINT64_C(13808688142819286529) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_uint16x8_t r = simde_vreinterpretq_u16_u64(a);
    simde_uint16x8_private r_ = simde_uint16x8_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u32_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
  } test_vec[] = {
    { { UINT64_C( 9421253059950992200), UINT64_C(18190508131208484342) },
 },
    { { UINT64_C( 3715591700242667934), UINT64_C( 6523973211315662879) },
 },
    { { UINT64_C(17575881375336364714), UINT64_C(13558360581878608743) },
 },
    { { UINT64_C( 1206238956071125651), UINT64_C(15728700958152614108) },
 },
    { { UINT64_C( 1548441871217433484), UINT64_C(10482243575994123678) },
 },
    { { UINT64_C(11163255515110986731), UINT64_C( 1316123692325467193) },
 },
    { { UINT64_C( 5633185853516514410), UINT64_C(13955954676396092701) },
 },
    { { UINT64_C(15865768773427186133), UINT64_C(17299602177782036092) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_private a_ = simde_uint64x2_to_private(a);
    simde_uint32x4_t r = simde_vreinterpretq_u32_u64(a);
    simde_uint32x4_private r_ = simde_uint32x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f64_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   640.27), SIMDE_FLOAT32_C(  -585.88) },
 },
    { { SIMDE_FLOAT32_C(   495.02), SIMDE_FLOAT32_C(  -454.59) },
 },
    { { SIMDE_FLOAT32_C(  -794.50), SIMDE_FLOAT32_C(  -757.76) },
 },
    { { SIMDE_FLOAT32_C(  -987.01), SIMDE_FLOAT32_C(  -967.63) },
 },
    { { SIMDE_FLOAT32_C(   776.12), SIMDE_FLOAT32_C(  -392.25) },
 },
    { { SIMDE_FLOAT32_C(   488.06), SIMDE_FLOAT32_C(  -965.22) },
 },
    { { SIMDE_FLOAT32_C(  -118.01), SIMDE_FLOAT32_C(    15.16) },
 },
    { { SIMDE_FLOAT32_C(  -392.02), SIMDE_FLOAT32_C(    26.20) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_float64x1_t r = simde_vreinterpret_f64_f32(a);
    simde_float64x1_private r_ = simde_float64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s8_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -587.63), SIMDE_FLOAT32_C(   585.48) },
 },
    { { SIMDE_FLOAT32_C(  -661.12), SIMDE_FLOAT32_C(  -256.06) },
 },
    { { SIMDE_FLOAT32_C(   118.35), SIMDE_FLOAT32_C(   805.41) },
 },
    { { SIMDE_FLOAT32_C(   505.78), SIMDE_FLOAT32_C(  -965.54) },
 },
    { { SIMDE_FLOAT32_C(  -758.58), SIMDE_FLOAT32_C(   899.30) },
 },
    { { SIMDE_FLOAT32_C(  -523.55), SIMDE_FLOAT32_C(   -97.39) },
 },
    { { SIMDE_FLOAT32_C(  -615.32), SIMDE_FLOAT32_C(  -397.40) },
 },
    { { SIMDE_FLOAT32_C(  -120.59), SIMDE_FLOAT32_C(   913.00) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_int8x8_t r = simde_vreinterpret_s8_f32(a);
    simde_int8x8_private r_ = simde_int8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s16_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   965.56), SIMDE_FLOAT32_C(   406.80) },
 },
    { { SIMDE_FLOAT32_C(  -967.05), SIMDE_FLOAT32_C(  -359.28) },
 },
    { { SIMDE_FLOAT32_C(   -12.20), SIMDE_FLOAT32_C(   830.53) },
 },
    { { SIMDE_FLOAT32_C(  -617.07), SIMDE_FLOAT32_C(   419.80) },
 },
    { { SIMDE_FLOAT32_C(  -178.92), SIMDE_FLOAT32_C(   378.69) },
 },
    { { SIMDE_FLOAT32_C(   707.86), SIMDE_FLOAT32_C(   990.09) },
 },
    { { SIMDE_FLOAT32_C(    19.78), SIMDE_FLOAT32_C(  -485.54) },
 },
    { { SIMDE_FLOAT32_C(     4.31), SIMDE_FLOAT32_C(    85.98) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_int16x4_t r = simde_vreinterpret_s16_f32(a);
    simde_int16x4_private r_ = simde_int16x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   795.77), SIMDE_FLOAT32_C(   550.43) },
 },
    { { SIMDE_FLOAT32_C(   -83.89), SIMDE_FLOAT32_C(   973.87) },
 },
    { { SIMDE_FLOAT32_C(   261.17), SIMDE_FLOAT32_C(   160.88) },
 },
    { { SIMDE_FLOAT32_C(  -625.84), SIMDE_FLOAT32_C(   282.41) },
 },
    { { SIMDE_FLOAT32_C(   796.67), SIMDE_FLOAT32_C(  -170.27) },
 },
    { { SIMDE_FLOAT32_C(   520.80), SIMDE_FLOAT32_C(   944.18) },
 },
    { { SIMDE_FLOAT32_C(   -80.46), SIMDE_FLOAT32_C(   719.27) },
 },
    { { SIMDE_FLOAT32_C(   319.33), SIMDE_FLOAT32_C(  -849.20) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_int32x2_t r = simde_vreinterpret_s32_f32(a);
    simde_int32x2_private r_ = simde_int32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s64_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   516.10), SIMDE_FLOAT32_C(  -198.61) },
 },
    { { SIMDE_FLOAT32_C(  -669.75), SIMDE_FLOAT32_C(  -733.34) },
 },
    { { SIMDE_FLOAT32_C(    -1.26), SIMDE_FLOAT32_C(   -21.15) },
 },
    { { SIMDE_FLOAT32_C(   991.35), SIMDE_FLOAT32_C(   -65.88) },
 },
    { { SIMDE_FLOAT32_C(   207.04), SIMDE_FLOAT32_C(  -249.79) },
 },
    { { SIMDE_FLOAT32_C(  -595.20), SIMDE_FLOAT32_C(   987.70) },
 },
    { { SIMDE_FLOAT32_C(  -316.55), SIMDE_FLOAT32_C(   458.49) },
 },
    { { SIMDE_FLOAT32_C(   515.32), SIMDE_FLOAT32_C(  -268.29) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_int64x1_t r = simde_vreinterpret_s64_f32(a);
    simde_int64x1_private r_ = simde_int64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u8_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -703.61), SIMDE_FLOAT32_C(  -199.03) },
 },
    { { SIMDE_FLOAT32_C(  -275.51), SIMDE_FLOAT32_C(  -704.61) },
 },
    { { SIMDE_FLOAT32_C(   166.82), SIMDE_FLOAT32_C(    78.78) },
 },
    { { SIMDE_FLOAT32_C(   393.16), SIMDE_FLOAT32_C(   135.85) },
 },
    { { SIMDE_FLOAT32_C(  -375.89), SIMDE_FLOAT32_C(  -388.41) },
 },
    { { SIMDE_FLOAT32_C(   975.54), SIMDE_FLOAT32_C(    66.77) },
 },
    { { SIMDE_FLOAT32_C(  -130.34), SIMDE_FLOAT32_C(  -425.75) },
 },
    { { SIMDE_FLOAT32_C(    31.57), SIMDE_FLOAT32_C(   530.63) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_uint8x8_t r = simde_vreinterpret_u8_f32(a);
    simde_uint8x8_private r_ = simde_uint8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u16_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   679.90), SIMDE_FLOAT32_C(   888.01) },
 },
    { { SIMDE_FLOAT32_C(   262.65), SIMDE_FLOAT32_C(   704.41) },
 },
    { { SIMDE_FLOAT32_C(  -705.92), SIMDE_FLOAT32_C(  -576.78) },
 },
    { { SIMDE_FLOAT32_C(   514.37), SIMDE_FLOAT32_C(  -767.53) },
 },
    { { SIMDE_FLOAT32_C(   476.11), SIMDE_FLOAT32_C(  -765.14) },
 },
    { { SIMDE_FLOAT32_C(   623.02), SIMDE_FLOAT32_C(  -915.78) },
 },
    { { SIMDE_FLOAT32_C(  -765.19), SIMDE_FLOAT32_C(  -713.01) },
 },
    { { SIMDE_FLOAT32_C(   118.88), SIMDE_FLOAT32_C(   271.57) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_uint16x4_t r = simde_vreinterpret_u16_f32(a);
    simde_uint16x4_private r_ = simde_uint16x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[4];
  } test_vec[] = {
     {{ SIMDE_FLOAT16_VALUE(  -937.50), SIMDE_FLOAT16_VALUE(   311.75), SIMDE_FLOAT16_VALUE(   -23.30), SIMDE_FLOAT16_VALUE(   600.50) }},
     {{ SIMDE_FLOAT16_VALUE(   438.25), SIMDE_FLOAT16_VALUE(   -31.77), SIMDE_FLOAT16_VALUE(  -916.50), SIMDE_FLOAT16_VALUE(   172.62) }},
     {{ SIMDE_FLOAT16_VALUE(  -668.50), SIMDE_FLOAT16_VALUE(   294.75), SIMDE_FLOAT16_VALUE(   -77.69), SIMDE_FLOAT16_VALUE(  -135.62) }},
     {{ SIMDE_FLOAT16_VALUE(  -130.88), SIMDE_FLOAT16_VALUE(   569.00), SIMDE_FLOAT16_VALUE(  -618.50), SIMDE_FLOAT16_VALUE(  -238.50) }},
     {{ SIMDE_FLOAT16_VALUE(  -396.00), SIMDE_FLOAT16_VALUE(  -605.50), SIMDE_FLOAT16_VALUE(  -576.50), SIMDE_FLOAT16_VALUE(     8.46) }},
     {{ SIMDE_FLOAT16_VALUE(   902.00), SIMDE_FLOAT16_VALUE(   283.50), SIMDE_FLOAT16_VALUE(  -336.75), SIMDE_FLOAT16_VALUE(   741.00) }},
     {{ SIMDE_FLOAT16_VALUE(  -499.00), SIMDE_FLOAT16_VALUE(   515.00), SIMDE_FLOAT16_VALUE(  -923.50), SIMDE_FLOAT16_VALUE(   880.00) }},
     {{ SIMDE_FLOAT16_VALUE(   410.75), SIMDE_FLOAT16_VALUE(   970.50), SIMDE_FLOAT16_VALUE(  -704.50), SIMDE_FLOAT16_VALUE(   473.25) }}
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_private a_ = simde_float16x4_to_private(a);
    simde_uint16x4_t r = simde_vreinterpret_u16_f16(a);
    simde_uint16x4_private r_ = simde_uint16x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   661.50), SIMDE_FLOAT32_C(  -338.84) },
 },
    { { SIMDE_FLOAT32_C(   472.10), SIMDE_FLOAT32_C(  -850.16) },
 },
    { { SIMDE_FLOAT32_C(   915.36), SIMDE_FLOAT32_C(  -912.72) },
 },
    { { SIMDE_FLOAT32_C(   252.30), SIMDE_FLOAT32_C(   744.88) },
 },
    { { SIMDE_FLOAT32_C(   220.69), SIMDE_FLOAT32_C(  -108.88) },
 },
    { { SIMDE_FLOAT32_C(  -892.39), SIMDE_FLOAT32_C(   442.34) },
 },
    { { SIMDE_FLOAT32_C(  -537.40), SIMDE_FLOAT32_C(  -490.27) },
 },
    { { SIMDE_FLOAT32_C(  -224.54), SIMDE_FLOAT32_C(   427.88) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_uint32x2_t r = simde_vreinterpret_u32_f32(a);
    simde_uint32x2_private r_ = simde_uint32x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u64_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -519.07), SIMDE_FLOAT32_C(  -844.22) },
 },
    { { SIMDE_FLOAT32_C(  -231.95), SIMDE_FLOAT32_C(  -916.84) },
 },
    { { SIMDE_FLOAT32_C(   514.42), SIMDE_FLOAT32_C(  -429.97) },
 },
    { { SIMDE_FLOAT32_C(   411.33), SIMDE_FLOAT32_C(  -473.13) },
 },
    { { SIMDE_FLOAT32_C(   825.45), SIMDE_FLOAT32_C(  -559.04) },
 },
    { { SIMDE_FLOAT32_C(    33.66), SIMDE_FLOAT32_C(  -851.23) },
 },
    { { SIMDE_FLOAT32_C(  -750.80), SIMDE_FLOAT32_C(   708.79) },
 },
    { { SIMDE_FLOAT32_C(    71.84), SIMDE_FLOAT32_C(   585.91) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_private a_ = simde_float32x2_to_private(a);
    simde_uint64x1_t r = simde_vreinterpret_u64_f32(a);
    simde_uint64x1_private r_ = simde_uint64x1_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f64_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -811.50), SIMDE_FLOAT32_C(   514.96), SIMDE_FLOAT32_C(  -136.00), SIMDE_FLOAT32_C(  -141.79) },
 },
    { { SIMDE_FLOAT32_C(    61.02), SIMDE_FLOAT32_C(   477.62), SIMDE_FLOAT32_C(   148.51), SIMDE_FLOAT32_C(   991.88) },
 },
    { { SIMDE_FLOAT32_C(  -930.50), SIMDE_FLOAT32_C(   415.23), SIMDE_FLOAT32_C(  -261.81), SIMDE_FLOAT32_C(   239.22) },
 },
    { { SIMDE_FLOAT32_C(  -235.74), SIMDE_FLOAT32_C(  -683.57), SIMDE_FLOAT32_C(   -77.80), SIMDE_FLOAT32_C(   884.34) },
 },
    { { SIMDE_FLOAT32_C(  -663.55), SIMDE_FLOAT32_C(   620.01), SIMDE_FLOAT32_C(  -701.35), SIMDE_FLOAT32_C(   534.67) },
 },
    { { SIMDE_FLOAT32_C(   -55.34), SIMDE_FLOAT32_C(   286.47), SIMDE_FLOAT32_C(  -242.86), SIMDE_FLOAT32_C(  -763.34) },
 },
    { { SIMDE_FLOAT32_C(   995.87), SIMDE_FLOAT32_C(   465.38), SIMDE_FLOAT32_C(   128.46), SIMDE_FLOAT32_C(  -623.09) },
 },
    { { SIMDE_FLOAT32_C(   144.58), SIMDE_FLOAT32_C(   923.36), SIMDE_FLOAT32_C(  -420.92), SIMDE_FLOAT32_C(   333.08) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_float64x2_t r = simde_vreinterpretq_f64_f32(a);
    simde_float64x2_private r_ = simde_float64x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s8_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -715.28), SIMDE_FLOAT32_C(    33.48), SIMDE_FLOAT32_C(   229.63), SIMDE_FLOAT32_C(  -742.42) },
 },
    { { SIMDE_FLOAT32_C(   472.64), SIMDE_FLOAT32_C(  -446.37), SIMDE_FLOAT32_C(   664.03), SIMDE_FLOAT32_C(    26.76) },
 },
    { { SIMDE_FLOAT32_C(  -329.58), SIMDE_FLOAT32_C(   330.64), SIMDE_FLOAT32_C(  -243.69), SIMDE_FLOAT32_C(  -277.14) },
 },
    { { SIMDE_FLOAT32_C(   610.24), SIMDE_FLOAT32_C(   639.80), SIMDE_FLOAT32_C(  -784.18), SIMDE_FLOAT32_C(  -365.62) },
 },
    { { SIMDE_FLOAT32_C(   114.54), SIMDE_FLOAT32_C(  -652.97), SIMDE_FLOAT32_C(  -379.89), SIMDE_FLOAT32_C(  -610.92) },
 },
    { { SIMDE_FLOAT32_C(   952.14), SIMDE_FLOAT32_C(  -538.54), SIMDE_FLOAT32_C(  -682.53), SIMDE_FLOAT32_C(   242.56) },
 },
    { { SIMDE_FLOAT32_C(  -333.51), SIMDE_FLOAT32_C(   450.97), SIMDE_FLOAT32_C(  -236.98), SIMDE_FLOAT32_C(    47.06) },
 },
    { { SIMDE_FLOAT32_C(    18.38), SIMDE_FLOAT32_C(   953.45), SIMDE_FLOAT32_C(   221.44), SIMDE_FLOAT32_C(   303.10) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_int8x16_t r = simde_vreinterpretq_s8_f32(a);
    simde_int8x16_private r_ = simde_int8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s16_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -765.62), SIMDE_FLOAT32_C(   361.08), SIMDE_FLOAT32_C(   970.49), SIMDE_FLOAT32_C(   464.20) },
 },
    { { SIMDE_FLOAT32_C(  -945.27), SIMDE_FLOAT32_C(   -68.63), SIMDE_FLOAT32_C(   229.51), SIMDE_FLOAT32_C(  -351.34) },
 },
    { { SIMDE_FLOAT32_C(   542.83), SIMDE_FLOAT32_C(  -123.36), SIMDE_FLOAT32_C(   927.83), SIMDE_FLOAT32_C(  -243.91) },
 },
    { { SIMDE_FLOAT32_C(  -330.95), SIMDE_FLOAT32_C(   461.31), SIMDE_FLOAT32_C(   836.57), SIMDE_FLOAT32_C(    92.21) },
 },
    { { SIMDE_FLOAT32_C(  -186.44), SIMDE_FLOAT32_C(  -562.27), SIMDE_FLOAT32_C(  -320.25), SIMDE_FLOAT32_C(  -379.25) },
 },
    { { SIMDE_FLOAT32_C(   306.79), SIMDE_FLOAT32_C(  -832.12), SIMDE_FLOAT32_C(   438.15), SIMDE_FLOAT32_C(  -467.18) },
 },
    { { SIMDE_FLOAT32_C(  -657.92), SIMDE_FLOAT32_C(  -254.81), SIMDE_FLOAT32_C(   831.78), SIMDE_FLOAT32_C(   236.89) },
 },
    { { SIMDE_FLOAT32_C(   865.09), SIMDE_FLOAT32_C(   532.74), SIMDE_FLOAT32_C(  -968.34), SIMDE_FLOAT32_C(  -900.54) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_int16x8_t r = simde_vreinterpretq_s16_f32(a);
    simde_int16x8_private r_ = simde_int16x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -932.02), SIMDE_FLOAT32_C(  -132.75), SIMDE_FLOAT32_C(  -699.06), SIMDE_FLOAT32_C(  -679.87) },
 },
    { { SIMDE_FLOAT32_C(  -936.24), SIMDE_FLOAT32_C(   610.41), SIMDE_FLOAT32_C(  -391.45), SIMDE_FLOAT32_C(   201.79) },
 },
    { { SIMDE_FLOAT32_C(  -432.76), SIMDE_FLOAT32_C(   405.49), SIMDE_FLOAT32_C(   203.70), SIMDE_FLOAT32_C(  -940.94) },
 },
    { { SIMDE_FLOAT32_C(  -913.18), SIMDE_FLOAT32_C(   765.98), SIMDE_FLOAT32_C(  -413.09), SIMDE_FLOAT32_C(  -839.58) },
 },
    { { SIMDE_FLOAT32_C(   525.54), SIMDE_FLOAT32_C(  -423.97), SIMDE_FLOAT32_C(  -466.96), SIMDE_FLOAT32_C(   911.94) },
 },
    { { SIMDE_FLOAT32_C(   614.98), SIMDE_FLOAT32_C(   805.06), SIMDE_FLOAT32_C(  -958.00), SIMDE_FLOAT32_C(  -950.16) },
 },
    { { SIMDE_FLOAT32_C(  -656.23), SIMDE_FLOAT32_C(    55.72), SIMDE_FLOAT32_C(   110.93), SIMDE_FLOAT32_C(   458.68) },
 },
    { { SIMDE_FLOAT32_C(  -160.98), SIMDE_FLOAT32_C(   817.98), SIMDE_FLOAT32_C(   396.81), SIMDE_FLOAT32_C(   -92.99) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_int32x4_t r = simde_vreinterpretq_s32_f32(a);
    simde_int32x4_private r_ = simde_int32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s64_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   518.36), SIMDE_FLOAT32_C(  -882.32), SIMDE_FLOAT32_C(   -73.64), SIMDE_FLOAT32_C(   749.12) },
 },
    { { SIMDE_FLOAT32_C(  -496.02), SIMDE_FLOAT32_C(  -306.74), SIMDE_FLOAT32_C(  -922.59), SIMDE_FLOAT32_C(   847.19) },
 },
    { { SIMDE_FLOAT32_C(   777.17), SIMDE_FLOAT32_C(   196.12), SIMDE_FLOAT32_C(  -547.27), SIMDE_FLOAT32_C(  -497.25) },
 },
    { { SIMDE_FLOAT32_C(  -324.90), SIMDE_FLOAT32_C(  -358.94), SIMDE_FLOAT32_C(  -741.14), SIMDE_FLOAT32_C(  -164.39) },
 },
    { { SIMDE_FLOAT32_C(  -823.67), SIMDE_FLOAT32_C(  -347.30), SIMDE_FLOAT32_C(   683.23), SIMDE_FLOAT32_C(  -581.31) },
 },
    { { SIMDE_FLOAT32_C(  -908.06), SIMDE_FLOAT32_C(   681.07), SIMDE_FLOAT32_C(  -895.66), SIMDE_FLOAT32_C(   -13.27) },
 },
    { { SIMDE_FLOAT32_C(    38.57), SIMDE_FLOAT32_C(  -801.68), SIMDE_FLOAT32_C(  -141.46), SIMDE_FLOAT32_C(   275.72) },
 },
    { { SIMDE_FLOAT32_C(  -841.66), SIMDE_FLOAT32_C(  -993.81), SIMDE_FLOAT32_C(  -416.02), SIMDE_FLOAT32_C(   676.69) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_int64x2_t r = simde_vreinterpretq_s64_f32(a);
    simde_int64x2_private r_ = simde_int64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u8_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   666.23), SIMDE_FLOAT32_C(  -544.03), SIMDE_FLOAT32_C(   130.05), SIMDE_FLOAT32_C(  -777.18) },
 },
    { { SIMDE_FLOAT32_C(   521.70), SIMDE_FLOAT32_C(    33.98), SIMDE_FLOAT32_C(  -958.60), SIMDE_FLOAT32_C(  -408.56) },
 },
    { { SIMDE_FLOAT32_C(   396.34), SIMDE_FLOAT32_C(  -364.03), SIMDE_FLOAT32_C(   719.77), SIMDE_FLOAT32_C(   483.05) },
 },
    { { SIMDE_FLOAT32_C(   307.42), SIMDE_FLOAT32_C(   916.12), SIMDE_FLOAT32_C(  -506.50), SIMDE_FLOAT32_C(   167.94) },
 },
    { { SIMDE_FLOAT32_C(   796.69), SIMDE_FLOAT32_C(  -227.61), SIMDE_FLOAT32_C(   168.78), SIMDE_FLOAT32_C(   769.87) },
 },
    { { SIMDE_FLOAT32_C(   237.37), SIMDE_FLOAT32_C(  -942.90), SIMDE_FLOAT32_C(   126.56), SIMDE_FLOAT32_C(   -99.19) },
 },
    { { SIMDE_FLOAT32_C(   684.50), SIMDE_FLOAT32_C(   809.18), SIMDE_FLOAT32_C(   523.87), SIMDE_FLOAT32_C(   945.93) },
 },
    { { SIMDE_FLOAT32_C(   492.61), SIMDE_FLOAT32_C(   718.52), SIMDE_FLOAT32_C(  -237.77), SIMDE_FLOAT32_C(   158.83) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_uint8x16_t r = simde_vreinterpretq_u8_f32(a);
    simde_uint8x16_private r_ = simde_uint8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u16_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -555.05), SIMDE_FLOAT32_C(   929.17), SIMDE_FLOAT32_C(  -878.30), SIMDE_FLOAT32_C(   403.08) },
 },
    { { SIMDE_FLOAT32_C(  -814.23), SIMDE_FLOAT32_C(    72.21), SIMDE_FLOAT32_C(  -782.92), SIMDE_FLOAT32_C(  -545.57) },
 },
    { { SIMDE_FLOAT32_C(  -150.39), SIMDE_FLOAT32_C(  -981.73), SIMDE_FLOAT32_C(   393.48), SIMDE_FLOAT32_C(  -162.45) },
 },
    { { SIMDE_FLOAT32_C(  -204.82), SIMDE_FLOAT32_C(  -148.81), SIMDE_FLOAT32_C(   -48.01), SIMDE_FLOAT32_C(  -385.48) },
 },
    { { SIMDE_FLOAT32_C(  -745.95), SIMDE_FLOAT32_C(   651.42), SIMDE_FLOAT32_C(   885.60), SIMDE_FLOAT32_C(   882.69) },
 },
    { { SIMDE_FLOAT32_C(   987.57), SIMDE_FLOAT32_C(  -664.87), SIMDE_FLOAT32_C(  -294.19), SIMDE_FLOAT32_C(   570.81) },
 },
    { { SIMDE_FLOAT32_C(  -549.84), SIMDE_FLOAT32_C(   623.57), SIMDE_FLOAT32_C(  -114.75), SIMDE_FLOAT32_C(  -564.92) },
 },
    { { SIMDE_FLOAT32_C(   165.89), SIMDE_FLOAT32_C(  -376.09), SIMDE_FLOAT32_C(   997.79), SIMDE_FLOAT32_C(   610.84) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_uint16x8_t r = simde_vreinterpretq_u16_f32(a);
    simde_uint16x8_private r_ = simde_uint16x8_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u16_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[8];
  } test_vec[] = {
     { { SIMDE_FLOAT16_VALUE(   615.50), SIMDE_FLOAT16_VALUE(  -978.50), SIMDE_FLOAT16_VALUE(  -561.50), SIMDE_FLOAT16_VALUE(   508.50),
        SIMDE_FLOAT16_VALUE(  -968.00), SIMDE_FLOAT16_VALUE(  -316.25), SIMDE_FLOAT16_VALUE(  -961.50), SIMDE_FLOAT16_VALUE(   786.50) } },
    { { SIMDE_FLOAT16_VALUE(   968.50), SIMDE_FLOAT16_VALUE(  -779.50), SIMDE_FLOAT16_VALUE(    -0.40), SIMDE_FLOAT16_VALUE(   486.00),
        SIMDE_FLOAT16_VALUE(   819.00), SIMDE_FLOAT16_VALUE(   807.00), SIMDE_FLOAT16_VALUE(  -690.00), SIMDE_FLOAT16_VALUE(  -245.50) } },
    { { SIMDE_FLOAT16_VALUE(  -341.50), SIMDE_FLOAT16_VALUE(  -184.50), SIMDE_FLOAT16_VALUE(   865.50), SIMDE_FLOAT16_VALUE(   213.38),
        SIMDE_FLOAT16_VALUE(   627.50), SIMDE_FLOAT16_VALUE(  -115.00), SIMDE_FLOAT16_VALUE(  -649.50), SIMDE_FLOAT16_VALUE(     0.66) } },
    { { SIMDE_FLOAT16_VALUE(  -466.00), SIMDE_FLOAT16_VALUE(   230.25), SIMDE_FLOAT16_VALUE(   358.50), SIMDE_FLOAT16_VALUE(  -979.50),
        SIMDE_FLOAT16_VALUE(   474.25), SIMDE_FLOAT16_VALUE(   796.00), SIMDE_FLOAT16_VALUE(   782.00), SIMDE_FLOAT16_VALUE(    89.62) } },
    { { SIMDE_FLOAT16_VALUE(   817.50), SIMDE_FLOAT16_VALUE(  -779.50), SIMDE_FLOAT16_VALUE(  -402.00), SIMDE_FLOAT16_VALUE(   849.50),
        SIMDE_FLOAT16_VALUE(   -95.62), SIMDE_FLOAT16_VALUE(  -363.50), SIMDE_FLOAT16_VALUE(   636.00), SIMDE_FLOAT16_VALUE(  -127.19) } },
    { { SIMDE_FLOAT16_VALUE(  -142.88), SIMDE_FLOAT16_VALUE(  -364.50), SIMDE_FLOAT16_VALUE(  -641.00), SIMDE_FLOAT16_VALUE(  -324.00),
        SIMDE_FLOAT16_VALUE(  -558.00), SIMDE_FLOAT16_VALUE(  -331.25), SIMDE_FLOAT16_VALUE(   430.50), SIMDE_FLOAT16_VALUE(   100.62) } },
    { { SIMDE_FLOAT16_VALUE(   484.25), SIMDE_FLOAT16_VALUE(   296.00), SIMDE_FLOAT16_VALUE(  -686.00), SIMDE_FLOAT16_VALUE(   111.56),
        SIMDE_FLOAT16_VALUE(  -819.00), SIMDE_FLOAT16_VALUE(  -335.50), SIMDE_FLOAT16_VALUE(  -888.00), SIMDE_FLOAT16_VALUE(  -284.75) } },
    { { SIMDE_FLOAT16_VALUE(   894.50), SIMDE_FLOAT16_VALUE(   470.75), SIMDE_FLOAT16_VALUE(  -264.25), SIMDE_FLOAT16_VALUE(   369.00),
        SIMDE_FLOAT16_VALUE(   266.75), SIMDE_FLOAT16_VALUE(  -482.00), SIMDE_FLOAT16_VALUE(  -541.50), SIMDE_FLOAT16_VALUE(    84.12) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_private a_ = simde_float16x8_to_private(a);
    simde_uint16x8_t r = simde_vreinterpretq_u16_f16(a);
    simde_uint16x8_private r_ = simde_uint16x8_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u32_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -639.27), SIMDE_FLOAT32_C(     2.23), SIMDE_FLOAT32_C(  -265.16), SIMDE_FLOAT32_C(  -362.94) },
 },
    { { SIMDE_FLOAT32_C(  -445.88), SIMDE_FLOAT32_C(   968.53), SIMDE_FLOAT32_C(   312.26), SIMDE_FLOAT32_C(   936.91) },
 },
    { { SIMDE_FLOAT32_C(  -465.40), SIMDE_FLOAT32_C(   -23.17), SIMDE_FLOAT32_C(   673.23), SIMDE_FLOAT32_C(  -603.22) },
 },
    { { SIMDE_FLOAT32_C(  -429.30), SIMDE_FLOAT32_C(   406.19), SIMDE_FLOAT32_C(   726.96), SIMDE_FLOAT32_C(  -436.99) },
 },
    { { SIMDE_FLOAT32_C(    52.93), SIMDE_FLOAT32_C(  -904.72), SIMDE_FLOAT32_C(   225.27), SIMDE_FLOAT32_C(   -62.92) },
 },
    { { SIMDE_FLOAT32_C(  -719.26), SIMDE_FLOAT32_C(    97.89), SIMDE_FLOAT32_C(  -808.00), SIMDE_FLOAT32_C(   701.29) },
 },
    { { SIMDE_FLOAT32_C(   151.65), SIMDE_FLOAT32_C(   842.19), SIMDE_FLOAT32_C(   331.08), SIMDE_FLOAT32_C(   329.68) },
 },
    { { SIMDE_FLOAT32_C(   304.95), SIMDE_FLOAT32_C(   771.15), SIMDE_FLOAT32_C(   630.46), SIMDE_FLOAT32_C(   665.69) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_uint32x4_t r = simde_vreinterpretq_u32_f32(a);
    simde_uint32x4_private r_ = simde_uint32x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u64_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   231.72), SIMDE_FLOAT32_C(   123.26), SIMDE_FLOAT32_C(  -786.91), SIMDE_FLOAT32_C(  -138.95) },
 },
    { { SIMDE_FLOAT32_C(   166.21), SIMDE_FLOAT32_C(   199.26), SIMDE_FLOAT32_C(  -881.03), SIMDE_FLOAT32_C(   363.41) },
 },
    { { SIMDE_FLOAT32_C(  -208.25), SIMDE_FLOAT32_C(  -126.94), SIMDE_FLOAT32_C(  -663.57), SIMDE_FLOAT32_C(  -651.99) },
 },
    { { SIMDE_FLOAT32_C(  -722.64), SIMDE_FLOAT32_C(  -951.85), SIMDE_FLOAT32_C(   -94.46), SIMDE_FLOAT32_C(   924.65) },
 },
    { { SIMDE_FLOAT32_C(   896.69), SIMDE_FLOAT32_C(    -6.54), SIMDE_FLOAT32_C(  -785.89), SIMDE_FLOAT32_C(  -806.08) },
 },
    { { SIMDE_FLOAT32_C(  -595.88), SIMDE_FLOAT32_C(   347.71), SIMDE_FLOAT32_C(   118.81), SIMDE_FLOAT32_C(  -850.69) },
 },
    { { SIMDE_FLOAT32_C(  -873.62), SIMDE_FLOAT32_C(   679.36), SIMDE_FLOAT32_C(   461.45), SIMDE_FLOAT32_C(  -429.35) },
 },
    { { SIMDE_FLOAT32_C(  -437.13), SIMDE_FLOAT32_C(  -811.02), SIMDE_FLOAT32_C(   684.01), SIMDE_FLOAT32_C(   794.59) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_private a_ = simde_float32x4_to_private(a);
    simde_uint64x2_t r = simde_vreinterpretq_u64_f32(a);
    simde_uint64x2_private r_ = simde_uint64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_f32_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    28.67) },
 },
    { { SIMDE_FLOAT64_C(   473.75) },
 },
    { { SIMDE_FLOAT64_C(   415.56) },
 },
    { { SIMDE_FLOAT64_C(   753.78) },
 },
    { { SIMDE_FLOAT64_C(   619.03) },
 },
    { { SIMDE_FLOAT64_C(   870.52) },
 },
    { { SIMDE_FLOAT64_C(  -321.27) },
 },
    { { SIMDE_FLOAT64_C(  -568.79) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_float32x2_t r = simde_vreinterpret_f32_f64(a);
    simde_float32x2_private r_ = simde_float32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s8_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -39.43) },
 },
    { { SIMDE_FLOAT64_C(   241.14) },
 },
    { { SIMDE_FLOAT64_C(   480.99) },
 },
    { { SIMDE_FLOAT64_C(   763.77) },
 },
    { { SIMDE_FLOAT64_C(   486.92) },
 },
    { { SIMDE_FLOAT64_C(   -31.94) },
 },
    { { SIMDE_FLOAT64_C(   873.55) },
 },
    { { SIMDE_FLOAT64_C(   804.51) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_int8x8_t r = simde_vreinterpret_s8_f64(a);
    simde_int8x8_private r_ = simde_int8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s16_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   937.89) },
 },
    { { SIMDE_FLOAT64_C(  -770.55) },
 },
    { { SIMDE_FLOAT64_C(   954.11) },
 },
    { { SIMDE_FLOAT64_C(  -761.79) },
 },
    { { SIMDE_FLOAT64_C(  -483.85) },
 },
    { { SIMDE_FLOAT64_C(  -722.69) },
 },
    { { SIMDE_FLOAT64_C(    63.26) },
 },
    { { SIMDE_FLOAT64_C(   347.83) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_int16x4_t r = simde_vreinterpret_s16_f64(a);
    simde_int16x4_private r_ = simde_int16x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s32_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -321.48) },
 },
    { { SIMDE_FLOAT64_C(   239.70) },
 },
    { { SIMDE_FLOAT64_C(  -593.78) },
 },
    { { SIMDE_FLOAT64_C(  -961.46) },
 },
    { { SIMDE_FLOAT64_C(  -714.06) },
 },
    { { SIMDE_FLOAT64_C(   876.41) },
 },
    { { SIMDE_FLOAT64_C(   192.37) },
 },
    { { SIMDE_FLOAT64_C(   113.12) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_int32x2_t r = simde_vreinterpret_s32_f64(a);
    simde_int32x2_private r_ = simde_int32x2_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -679.32) },
 },
    { { SIMDE_FLOAT64_C(   926.71) },
 },
    { { SIMDE_FLOAT64_C(   780.61) },
 },
    { { SIMDE_FLOAT64_C(   116.09) },
 },
    { { SIMDE_FLOAT64_C(   481.72) },
 },
    { { SIMDE_FLOAT64_C(  -377.58) },
 },
    { { SIMDE_FLOAT64_C(  -976.13) },
 },
    { { SIMDE_FLOAT64_C(  -213.49) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_int64x1_t r = simde_vreinterpret_s64_f64(a);
    simde_int64x1_private r_ = simde_int64x1_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u8_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   642.50) },
 },
    { { SIMDE_FLOAT64_C(   -99.78) },
 },
    { { SIMDE_FLOAT64_C(   942.91) },
 },
    { { SIMDE_FLOAT64_C(  -784.51) },
 },
    { { SIMDE_FLOAT64_C(    20.18) },
 },
    { { SIMDE_FLOAT64_C(   600.51) },
 },
    { { SIMDE_FLOAT64_C(  -214.07) },
 },
    { { SIMDE_FLOAT64_C(  -775.71) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_uint8x8_t r = simde_vreinterpret_u8_f64(a);
    simde_uint8x8_private r_ = simde_uint8x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u16_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -646.34) },
 },
    { { SIMDE_FLOAT64_C(   355.80) },
 },
    { { SIMDE_FLOAT64_C(   -63.18) },
 },
    { { SIMDE_FLOAT64_C(   300.54) },
 },
    { { SIMDE_FLOAT64_C(  -572.37) },
 },
    { { SIMDE_FLOAT64_C(  -193.89) },
 },
    { { SIMDE_FLOAT64_C(  -662.99) },
 },
    { { SIMDE_FLOAT64_C(    16.90) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_uint16x4_t r = simde_vreinterpret_u16_f64(a);
    simde_uint16x4_private r_ = simde_uint16x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u32_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -775.04) },
 },
    { { SIMDE_FLOAT64_C(   -75.64) },
 },
    { { SIMDE_FLOAT64_C(  -833.77) },
 },
    { { SIMDE_FLOAT64_C(   676.43) },
 },
    { { SIMDE_FLOAT64_C(  -944.49) },
 },
    { { SIMDE_FLOAT64_C(  -660.68) },
 },
    { { SIMDE_FLOAT64_C(   634.14) },
 },
    { { SIMDE_FLOAT64_C(   224.28) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_uint32x2_t r = simde_vreinterpret_u32_f64(a);
    simde_uint32x2_private r_ = simde_uint32x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpret_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   417.49) },
 },
    { { SIMDE_FLOAT64_C(  -757.56) },
 },
    { { SIMDE_FLOAT64_C(  -880.56) },
 },
    { { SIMDE_FLOAT64_C(   795.04) },
 },
    { { SIMDE_FLOAT64_C(  -500.89) },
 },
    { { SIMDE_FLOAT64_C(  -877.89) },
 },
    { { SIMDE_FLOAT64_C(   559.74) },
 },
    { { SIMDE_FLOAT64_C(   235.55) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_private a_ = simde_float64x1_to_private(a);
    simde_uint64x1_t r = simde_vreinterpret_u64_f64(a);
    simde_uint64x1_private r_ = simde_uint64x1_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_f32_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -143.25), SIMDE_FLOAT64_C(   834.85) },
 },
    { { SIMDE_FLOAT64_C(  -261.67), SIMDE_FLOAT64_C(  -140.07) },
 },
    { { SIMDE_FLOAT64_C(   513.01), SIMDE_FLOAT64_C(  -658.64) },
 },
    { { SIMDE_FLOAT64_C(  -687.83), SIMDE_FLOAT64_C(   764.02) },
 },
    { { SIMDE_FLOAT64_C(  -465.12), SIMDE_FLOAT64_C(  -765.44) },
 },
    { { SIMDE_FLOAT64_C(   433.84), SIMDE_FLOAT64_C(  -259.91) },
 },
    { { SIMDE_FLOAT64_C(  -578.38), SIMDE_FLOAT64_C(   507.83) },
 },
    { { SIMDE_FLOAT64_C(   973.67), SIMDE_FLOAT64_C(   -82.78) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_float32x4_t r = simde_vreinterpretq_f32_f64(a);
    simde_float32x4_private r_ = simde_float32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s8_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   458.52), SIMDE_FLOAT64_C(   987.27) },
 },
    { { SIMDE_FLOAT64_C(  -744.09), SIMDE_FLOAT64_C(  -287.82) },
 },
    { { SIMDE_FLOAT64_C(  -721.99), SIMDE_FLOAT64_C(   994.43) },
 },
    { { SIMDE_FLOAT64_C(   754.99), SIMDE_FLOAT64_C(  -258.36) },
 },
    { { SIMDE_FLOAT64_C(   866.04), SIMDE_FLOAT64_C(  -587.02) },
 },
    { { SIMDE_FLOAT64_C(  -745.20), SIMDE_FLOAT64_C(   415.92) },
 },
    { { SIMDE_FLOAT64_C(  -203.46), SIMDE_FLOAT64_C(   889.41) },
 },
    { { SIMDE_FLOAT64_C(   665.61), SIMDE_FLOAT64_C(    69.19) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_int8x16_t r = simde_vreinterpretq_s8_f64(a);
    simde_int8x16_private r_ = simde_int8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s16_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    94.42), SIMDE_FLOAT64_C(   818.93) },
 },
    { { SIMDE_FLOAT64_C(  -692.67), SIMDE_FLOAT64_C(   786.34) },
 },
    { { SIMDE_FLOAT64_C(   928.43), SIMDE_FLOAT64_C(  -189.58) },
 },
    { { SIMDE_FLOAT64_C(  -918.60), SIMDE_FLOAT64_C(   199.44) },
 },
    { { SIMDE_FLOAT64_C(   503.38), SIMDE_FLOAT64_C(   887.65) },
 },
    { { SIMDE_FLOAT64_C(  -468.72), SIMDE_FLOAT64_C(  -389.59) },
 },
    { { SIMDE_FLOAT64_C(   846.67), SIMDE_FLOAT64_C(  -751.14) },
 },
    { { SIMDE_FLOAT64_C(  -515.92), SIMDE_FLOAT64_C(   180.13) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_int16x8_t r = simde_vreinterpretq_s16_f64(a);
    simde_int16x8_private r_ = simde_int16x8_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s32_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   528.55), SIMDE_FLOAT64_C(   688.78) },
 },
    { { SIMDE_FLOAT64_C(   610.11), SIMDE_FLOAT64_C(   611.13) },
 },
    { { SIMDE_FLOAT64_C(  -578.07), SIMDE_FLOAT64_C(   982.36) },
 },
    { { SIMDE_FLOAT64_C(   364.66), SIMDE_FLOAT64_C(  -506.04) },
 },
    { { SIMDE_FLOAT64_C(  -873.02), SIMDE_FLOAT64_C(   793.52) },
 },
    { { SIMDE_FLOAT64_C(   431.73), SIMDE_FLOAT64_C(  -420.86) },
 },
    { { SIMDE_FLOAT64_C(  -966.64), SIMDE_FLOAT64_C(   749.49) },
 },
    { { SIMDE_FLOAT64_C(   468.95), SIMDE_FLOAT64_C(   678.54) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_int32x4_t r = simde_vreinterpretq_s32_f64(a);
    simde_int32x4_private r_ = simde_int32x4_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_s64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   499.96), SIMDE_FLOAT64_C(   483.36) },
 },
    { { SIMDE_FLOAT64_C(  -570.97), SIMDE_FLOAT64_C(  -986.77) },
 },
    { { SIMDE_FLOAT64_C(   388.29), SIMDE_FLOAT64_C(  -157.42) },
 },
    { { SIMDE_FLOAT64_C(  -500.62), SIMDE_FLOAT64_C(  -196.54) },
 },
    { { SIMDE_FLOAT64_C(  -186.43), SIMDE_FLOAT64_C(   777.44) },
 },
    { { SIMDE_FLOAT64_C(  -393.24), SIMDE_FLOAT64_C(  -993.29) },
 },
    { { SIMDE_FLOAT64_C(   813.36), SIMDE_FLOAT64_C(   797.87) },
 },
    { { SIMDE_FLOAT64_C(   890.64), SIMDE_FLOAT64_C(   177.04) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_int64x2_t r = simde_vreinterpretq_s64_f64(a);
    simde_int64x2_private r_ = simde_int64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u8_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   774.17), SIMDE_FLOAT64_C(  -982.31) },
 },
    { { SIMDE_FLOAT64_C(   150.95), SIMDE_FLOAT64_C(   568.12) },
 },
    { { SIMDE_FLOAT64_C(  -697.86), SIMDE_FLOAT64_C(  -585.35) },
 },
    { { SIMDE_FLOAT64_C(  -726.09), SIMDE_FLOAT64_C(  -258.24) },
 },
    { { SIMDE_FLOAT64_C(   225.96), SIMDE_FLOAT64_C(   612.94) },
 },
    { { SIMDE_FLOAT64_C(   513.18), SIMDE_FLOAT64_C(   503.15) },
 },
    { { SIMDE_FLOAT64_C(   963.82), SIMDE_FLOAT64_C(   -77.66) },
 },
    { { SIMDE_FLOAT64_C(  -796.08), SIMDE_FLOAT64_C(     2.44) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_uint8x16_t r = simde_vreinterpretq_u8_f64(a);
    simde_uint8x16_private r_ = simde_uint8x16_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u16_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   366.50), SIMDE_FLOAT64_C(  -291.14) },
 },
    { { SIMDE_FLOAT64_C(  -469.92), SIMDE_FLOAT64_C(  -958.99) },
 },
    { { SIMDE_FLOAT64_C(  -979.93), SIMDE_FLOAT64_C(  -904.00) },
 },
    { { SIMDE_FLOAT64_C(  -442.71), SIMDE_FLOAT64_C(  -363.03) },
 },
    { { SIMDE_FLOAT64_C(  -172.73), SIMDE_FLOAT64_C(    76.80) },
 },
    { { SIMDE_FLOAT64_C(   876.29), SIMDE_FLOAT64_C(  -629.97) },
 },
    { { SIMDE_FLOAT64_C(   360.30), SIMDE_FLOAT64_C(   944.37) },
 },
    { { SIMDE_FLOAT64_C(  -412.04), SIMDE_FLOAT64_C(   375.13) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_uint16x8_t r = simde_vreinterpretq_u16_f64(a);
    simde_uint16x8_private r_ = simde_uint16x8_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u32_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -625.30), SIMDE_FLOAT64_C(  -492.95) },
 },
    { { SIMDE_FLOAT64_C(   940.16), SIMDE_FLOAT64_C(   246.25) },
 },
    { { SIMDE_FLOAT64_C(  -129.68), SIMDE_FLOAT64_C(   -65.50) },
 },
    { { SIMDE_FLOAT64_C(  -587.78), SIMDE_FLOAT64_C(  -371.92) },
 },
    { { SIMDE_FLOAT64_C(   254.10), SIMDE_FLOAT64_C(   929.33) },
 },
    { { SIMDE_FLOAT64_C(   369.23), SIMDE_FLOAT64_C(  -348.00) },
 },
    { { SIMDE_FLOAT64_C(   551.76), SIMDE_FLOAT64_C(   388.09) },
 },
    { { SIMDE_FLOAT64_C(  -849.56), SIMDE_FLOAT64_C(   541.39) },
 },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_uint32x4_t r = simde_vreinterpretq_u32_f64(a);
    simde_uint32x4_private r_ = simde_uint32x4_to_private(r);

    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

static int
test_simde_vreinterpretq_u64_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   261.11), SIMDE_FLOAT64_C(   328.35) },
    },
    { { SIMDE_FLOAT64_C(   953.99), SIMDE_FLOAT64_C(   268.54) },
    },
    { { SIMDE_FLOAT64_C(   860.91), SIMDE_FLOAT64_C(   685.66) },
    },
    { { SIMDE_FLOAT64_C(  -379.72), SIMDE_FLOAT64_C(   849.19) },
    },
    { { SIMDE_FLOAT64_C(  -182.32), SIMDE_FLOAT64_C(   565.54) },
    },
    { { SIMDE_FLOAT64_C(   593.89), SIMDE_FLOAT64_C(   988.09) },
    },
    { { SIMDE_FLOAT64_C(   564.35), SIMDE_FLOAT64_C(   771.05) },
    },
    { { SIMDE_FLOAT64_C(  -993.11), SIMDE_FLOAT64_C(  -315.73) },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_private a_ = simde_float64x2_to_private(a);
    simde_uint64x2_t r = simde_vreinterpretq_u64_f64(a);
    simde_uint64x2_private r_ = simde_uint64x2_to_private(r);
    simde_assert_equal_i(0, simde_memcmp(&r_, &a_, sizeof(r_)));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f32_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f64_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s16_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s32_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s64_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u8_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u16_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u32_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u64_s8)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f32_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f64_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s16_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s32_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s64_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u8_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u16_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u32_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u64_s8)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f32_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f64_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s8_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s32_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s64_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u8_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u32_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u64_s16)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f32_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f64_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s8_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s32_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s64_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u8_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u16_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u32_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u64_s16)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f64_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s8_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s16_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s64_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u8_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u16_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u64_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f64_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s8_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s16_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s64_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u8_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u16_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u32_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u64_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f32_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s8_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s16_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s32_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u8_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u16_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u32_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u64_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f32_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f64_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s8_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s16_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s32_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u8_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u16_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u32_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u64_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f32_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f64_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s8_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s16_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s32_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s64_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u16_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u32_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u64_u8)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f32_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f64_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s8_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s16_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s32_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s64_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u16_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u32_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u64_u8)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f32_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f64_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s8_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s32_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s64_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u8_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u32_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u64_u16)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f32_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f64_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s8_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s32_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s64_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u8_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u32_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u64_u16)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f64_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s8_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s16_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s64_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u8_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u16_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u64_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f16_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f64_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s8_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s16_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s32_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s64_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u8_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u16_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u64_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f32_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f64_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s8_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s16_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s32_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s64_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u8_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u16_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u32_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f32_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f64_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s8_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s16_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s32_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s64_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u8_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u16_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u32_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f64_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s8_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s16_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s64_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u8_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u16_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u64_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f64_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s8_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s16_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s64_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u8_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u16_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u16_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u32_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u64_f32)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_f32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s8_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s16_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u8_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u16_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpret_u64_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_f32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s8_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s16_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_s64_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u8_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u16_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u32_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vreinterpretq_u64_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
