#define SIMDE_TEST_ARM_NEON_INSN qtbl

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/qtbl.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

#if 0
  #define PROBABILITY 80
  #define probability(p) (rand() < ((HEDLEY_STATIC_CAST(int64_t, RAND_MAX) * (p)) / 100))
#endif

static int
test_simde_vqtbl1_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 int8_t t[16];
    SIMDE_ALIGN_TO_16 uint8_t idx[8];
    SIMDE_ALIGN_TO_16 int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  29),  INT8_C( 100),  INT8_C(  31),  INT8_C( 119),  INT8_C(   4),  INT8_C(  25),  INT8_C( 119), -INT8_C(  28),
        -INT8_C(  31), -INT8_C(  76), -INT8_C(  95), -INT8_C(  91),  INT8_C(  81), -INT8_C( 115),  INT8_C(  77), -INT8_C(  75) },
      { UINT8_C(  2), UINT8_C( 10), UINT8_C(  7), UINT8_C(  2), UINT8_C( 14), UINT8_C( 89), UINT8_C( 10), UINT8_C(  1) },
      {  INT8_C(  31), -INT8_C(  95), -INT8_C(  28),  INT8_C(  31),  INT8_C(  77),  INT8_C(   0), -INT8_C(  95),  INT8_C( 100) } },
    { {  INT8_C(  62),  INT8_C(  30), -INT8_C(  17),  INT8_C(  66),  INT8_C(  56),  INT8_C( 102),  INT8_C(  38),  INT8_C(  25),
         INT8_C(  26), -INT8_C(  57), -INT8_C(  66),  INT8_C( 107),  INT8_C(  85),  INT8_C(  11),  INT8_C(  33),  INT8_C(  39) },
      { UINT8_C(  5), UINT8_C(  8), UINT8_C(  9), UINT8_C(  4), UINT8_C(130), UINT8_C(  3), UINT8_C(181), UINT8_C(  7) },
      {  INT8_C( 102),  INT8_C(  26), -INT8_C(  57),  INT8_C(  56),  INT8_C(   0),  INT8_C(  66),  INT8_C(   0),  INT8_C(  25) } },
    { { -INT8_C(  20), -INT8_C(  44), -INT8_C( 102),  INT8_C(  36),  INT8_C(  59), -INT8_C(  64),  INT8_C(  61),  INT8_C(  85),
        -INT8_C( 120), -INT8_C(   4), -INT8_C(  63), -INT8_C(  35),  INT8_C(   7), -INT8_C(  30),  INT8_C(   4), -INT8_C(  83) },
      { UINT8_C( 10), UINT8_C( 13), UINT8_C(  1), UINT8_C( 12), UINT8_C(  0), UINT8_C(  6), UINT8_C(  4), UINT8_C(  8) },
      { -INT8_C(  63), -INT8_C(  30), -INT8_C(  44),  INT8_C(   7), -INT8_C(  20),  INT8_C(  61),  INT8_C(  59), -INT8_C( 120) } },
    { {  INT8_C(  78),  INT8_C(  79), -INT8_C(  48), -INT8_C( 119),  INT8_C(  15),  INT8_C(  13), -INT8_C(  34), -INT8_C( 105),
         INT8_C(   9), -INT8_C(  97),  INT8_C( 116),  INT8_C(  17), -INT8_C( 127),  INT8_C( 120), -INT8_C(  66), -INT8_C( 116) },
      { UINT8_C(  5), UINT8_C( 15), UINT8_C(  8), UINT8_C(  6), UINT8_C( 21), UINT8_C( 12), UINT8_C( 14), UINT8_C(  9) },
      {  INT8_C(  13), -INT8_C( 116),  INT8_C(   9), -INT8_C(  34),  INT8_C(   0), -INT8_C( 127), -INT8_C(  66), -INT8_C(  97) } },
    { { -INT8_C(  69),  INT8_C( 107), -INT8_C( 125), -INT8_C(  54),  INT8_C( 120),  INT8_C(  97),  INT8_C(  98), -INT8_C( 126),
         INT8_C(   1), -INT8_C(  42), -INT8_C( 109), -INT8_C( 126),  INT8_C(  79),  INT8_C(  81),  INT8_C(  14),  INT8_C( 116) },
      { UINT8_C(  0), UINT8_C(  7), UINT8_C( 10), UINT8_C(  5), UINT8_C( 99), UINT8_C(  8), UINT8_C( 14), UINT8_C(  2) },
      { -INT8_C(  69), -INT8_C( 126), -INT8_C( 109),  INT8_C(  97),  INT8_C(   0),  INT8_C(   1),  INT8_C(  14), -INT8_C( 125) } },
    { { -INT8_C( 121), -INT8_C(  28),  INT8_C( 119),  INT8_C(   0),  INT8_C(  69), -INT8_C(  39), -INT8_C( 126),  INT8_C(  70),
        -INT8_C(  81),  INT8_C(  21), -INT8_C(  55), -INT8_C(   2),  INT8_C( 102), -INT8_C(  41),  INT8_C( 115), -INT8_C(  58) },
      { UINT8_C(254), UINT8_C( 13), UINT8_C( 11), UINT8_C( 98), UINT8_C(  6), UINT8_C(  9), UINT8_C(  4), UINT8_C(161) },
      {  INT8_C(   0), -INT8_C(  41), -INT8_C(   2),  INT8_C(   0), -INT8_C( 126),  INT8_C(  21),  INT8_C(  69),  INT8_C(   0) } },
    { {  INT8_C(  77), -INT8_C(  92),  INT8_C(  26), -INT8_C( 110),  INT8_C( 125), -INT8_C( 100), -INT8_C(  39),  INT8_C(  44),
        -INT8_C(  79), -INT8_C(  94),  INT8_C(  43),  INT8_C(  23),  INT8_C( 121), -INT8_C(  98), -INT8_C(  35),  INT8_C( 120) },
      { UINT8_C( 11), UINT8_C(  8), UINT8_C( 10), UINT8_C(  1), UINT8_C(  1), UINT8_C( 14), UINT8_C(130), UINT8_C(176) },
      {  INT8_C(  23), -INT8_C(  79),  INT8_C(  43), -INT8_C(  92), -INT8_C(  92), -INT8_C(  35),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(   2),  INT8_C(  11), -INT8_C(  45),      INT8_MAX, -INT8_C(  89), -INT8_C(  84), -INT8_C(  85),  INT8_C(  88),
         INT8_C(  78), -INT8_C(  42),  INT8_C( 111), -INT8_C(  57),  INT8_C( 116),  INT8_C(  76),  INT8_C(  63),  INT8_C( 112) },
      { UINT8_C(100), UINT8_C(  9), UINT8_C(  1), UINT8_C(  5), UINT8_C(  8), UINT8_C(  4), UINT8_C(  6), UINT8_C( 12) },
      {  INT8_C(   0), -INT8_C(  42),  INT8_C(  11), -INT8_C(  84),  INT8_C(  78), -INT8_C(  89), -INT8_C(  85),  INT8_C( 116) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t t = simde_vld1q_s8(test_vec[i].t);
    simde_uint8x8_t idx = simde_vld1_u8(test_vec[i].idx);
    simde_int8x8_t r = simde_vqtbl1_s8(t, idx);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t t = simde_test_arm_neon_random_i8x16();
    simde_uint8x8_private idx_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 15;
      }
    }

    simde_uint8x8_t idx = simde_uint8x8_from_private(idx_);

    simde_int8x8_t r = simde_vqtbl1_s8(t, idx);
    simde_test_arm_neon_write_i8x16(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl1_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 uint8_t t[16];
    SIMDE_ALIGN_TO_16 uint8_t idx[8];
    SIMDE_ALIGN_TO_16 uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 60), UINT8_C( 20), UINT8_C(  0), UINT8_C(112), UINT8_C(102), UINT8_C( 65), UINT8_C(211), UINT8_C(114),
        UINT8_C(253), UINT8_C(  6), UINT8_C(129), UINT8_C(166), UINT8_C(153), UINT8_C(197), UINT8_C( 72), UINT8_C(200) },
      { UINT8_C(103), UINT8_C(  8), UINT8_C( 65), UINT8_C(  6), UINT8_C(  0), UINT8_C(184), UINT8_C( 12), UINT8_C(  1) },
      { UINT8_C(  0), UINT8_C(253), UINT8_C(  0), UINT8_C(211), UINT8_C( 60), UINT8_C(  0), UINT8_C(153), UINT8_C( 20) } },
    { { UINT8_C(166), UINT8_C(109), UINT8_C(131), UINT8_C( 12), UINT8_C(174), UINT8_C( 86), UINT8_C(126), UINT8_C(172),
        UINT8_C( 92),    UINT8_MAX, UINT8_C( 82), UINT8_C(245), UINT8_C(196), UINT8_C(154), UINT8_C(189), UINT8_C( 43) },
      { UINT8_C(  3), UINT8_C( 15), UINT8_C(  2), UINT8_C(  3), UINT8_C(  7), UINT8_C( 14), UINT8_C(  4), UINT8_C(  2) },
      { UINT8_C( 12), UINT8_C( 43), UINT8_C(131), UINT8_C( 12), UINT8_C(172), UINT8_C(189), UINT8_C(174), UINT8_C(131) } },
    { { UINT8_C(242), UINT8_C( 87), UINT8_C(169), UINT8_C(160), UINT8_C(173), UINT8_C( 40), UINT8_C( 76), UINT8_C(  9),
        UINT8_C( 39), UINT8_C(158), UINT8_C(254), UINT8_C(236), UINT8_C( 57), UINT8_C(187), UINT8_C( 23), UINT8_C(204) },
      { UINT8_C( 10), UINT8_C(  9), UINT8_C( 15), UINT8_C(  1), UINT8_C(  8), UINT8_C(  4), UINT8_C(  3), UINT8_C(  3) },
      { UINT8_C(254), UINT8_C(158), UINT8_C(204), UINT8_C( 87), UINT8_C( 39), UINT8_C(173), UINT8_C(160), UINT8_C(160) } },
    { { UINT8_C(191), UINT8_C(215), UINT8_C(131), UINT8_C(108),    UINT8_MAX, UINT8_C(207), UINT8_C(117), UINT8_C( 38),
        UINT8_C(110), UINT8_C(115), UINT8_C( 18), UINT8_C(167), UINT8_C( 47), UINT8_C( 42), UINT8_C(115), UINT8_C(233) },
      { UINT8_C( 51), UINT8_C(  2), UINT8_C( 11), UINT8_C( 11), UINT8_C(  6), UINT8_C( 14), UINT8_C( 14), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(131), UINT8_C(167), UINT8_C(167), UINT8_C(117), UINT8_C(115), UINT8_C(115), UINT8_C(191) } },
    { { UINT8_C(213), UINT8_C(112), UINT8_C( 23), UINT8_C(212), UINT8_C( 63), UINT8_C(141), UINT8_C(250), UINT8_C(173),
        UINT8_C(  0), UINT8_C( 13), UINT8_C( 84), UINT8_C( 47), UINT8_C( 55), UINT8_C(199), UINT8_C( 25), UINT8_C(106) },
      { UINT8_C( 10), UINT8_C(  4), UINT8_C(  6), UINT8_C(  0), UINT8_C( 34), UINT8_C(116), UINT8_C(  0), UINT8_C( 12) },
      { UINT8_C( 84), UINT8_C( 63), UINT8_C(250), UINT8_C(213), UINT8_C(  0), UINT8_C(  0), UINT8_C(213), UINT8_C( 55) } },
    { { UINT8_C(164), UINT8_C(165), UINT8_C(152), UINT8_C(227), UINT8_C( 50), UINT8_C(146), UINT8_C(145), UINT8_C( 51),
        UINT8_C(159), UINT8_C(229), UINT8_C( 98), UINT8_C(214), UINT8_C(173), UINT8_C(123), UINT8_C( 65), UINT8_C(231) },
      { UINT8_C(239), UINT8_C(  7), UINT8_C(199), UINT8_C(  2), UINT8_C( 11), UINT8_C(  8), UINT8_C( 14), UINT8_C(  3) },
      { UINT8_C(  0), UINT8_C( 51), UINT8_C(  0), UINT8_C(152), UINT8_C(214), UINT8_C(159), UINT8_C( 65), UINT8_C(227) } },
    { { UINT8_C( 73), UINT8_C( 36), UINT8_C( 81), UINT8_C(124), UINT8_C(182), UINT8_C(226), UINT8_C(175), UINT8_C( 86),
        UINT8_C(199), UINT8_C( 17), UINT8_C( 44), UINT8_C(116), UINT8_C(141), UINT8_C(109), UINT8_C( 91), UINT8_C(124) },
      { UINT8_C(  4), UINT8_C(  3), UINT8_C( 14), UINT8_C(  0), UINT8_C( 11), UINT8_C( 13), UINT8_C(  3), UINT8_C(  4) },
      { UINT8_C(182), UINT8_C(124), UINT8_C( 91), UINT8_C( 73), UINT8_C(116), UINT8_C(109), UINT8_C(124), UINT8_C(182) } },
    { { UINT8_C( 92), UINT8_C(250), UINT8_C( 34), UINT8_C( 18), UINT8_C(220), UINT8_C(209), UINT8_C(104), UINT8_C(164),
        UINT8_C(227), UINT8_C(149), UINT8_C( 24), UINT8_C(112), UINT8_C(  2), UINT8_C(116), UINT8_C(236), UINT8_C( 55) },
      { UINT8_C(  7), UINT8_C( 11), UINT8_C(  7), UINT8_C(162), UINT8_C( 88), UINT8_C( 10), UINT8_C(  6), UINT8_C( 10) },
      { UINT8_C(164), UINT8_C(112), UINT8_C(164), UINT8_C(  0), UINT8_C(  0), UINT8_C( 24), UINT8_C(104), UINT8_C( 24) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t t = simde_vld1q_u8(test_vec[i].t);
    simde_uint8x8_t idx = simde_vld1_u8(test_vec[i].idx);
    simde_uint8x8_t r = simde_vqtbl1_u8(t, idx);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t t = simde_test_arm_neon_random_u8x16();
    simde_uint8x8_private idx_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 15;
      }
    }

    simde_uint8x8_t idx = simde_uint8x8_from_private(idx_);

    simde_uint8x8_t r = simde_vqtbl1_u8(t, idx);

    simde_test_arm_neon_write_u8x16(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vqtbl2_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 int8_t t[2][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[8];
    SIMDE_ALIGN_TO_16 int8_t r[8];
  } test_vec[] = {
    {
        { {  INT8_C( 111), -INT8_C(  69),  INT8_C( 111), -INT8_C(  97), -INT8_C(  67),  INT8_C(  21), -INT8_C(   1), -INT8_C(  16),
            -INT8_C(  39),  INT8_C(  28), -INT8_C(  84),  INT8_C(  73),  INT8_C(  88), -INT8_C(  42), -INT8_C(   2),  INT8_C(  72) },
          {  INT8_C( 107),  INT8_C( 104), -INT8_C( 117), -INT8_C(  55), -INT8_C( 106), -INT8_C(   6),  INT8_C(  98),  INT8_C(  77),
             INT8_C( 122),  INT8_C(   7), -INT8_C( 123),  INT8_C(  86), -INT8_C( 108),  INT8_C(  97), -INT8_C(  82),  INT8_C(   3) } },
      { UINT8_C( 28), UINT8_C( 30), UINT8_C(  2), UINT8_C(218), UINT8_C( 19), UINT8_C(  1), UINT8_C( 10), UINT8_C( 12) },
      { -INT8_C( 108), -INT8_C(  82),  INT8_C( 111),  INT8_C(   0), -INT8_C(  55), -INT8_C(  69), -INT8_C(  84),  INT8_C(  88) } },
    {
        { { -INT8_C(  69), -INT8_C(  23),      INT8_MIN,  INT8_C(  82), -INT8_C(  29), -INT8_C(  30), -INT8_C(  97),  INT8_C(  93),
            -INT8_C(  22),  INT8_C(  36), -INT8_C(  77),  INT8_C( 126), -INT8_C( 122),  INT8_C(  97), -INT8_C( 127), -INT8_C(  94) },
          {      INT8_MAX,  INT8_C(  35),  INT8_C( 124), -INT8_C(  78), -INT8_C(  59),  INT8_C(  71), -INT8_C(  66), -INT8_C( 126),
            -INT8_C(  67),  INT8_C(  20), -INT8_C( 104),  INT8_C(  10),  INT8_C( 103), -INT8_C(  10), -INT8_C(  63),  INT8_C(  35) } },
      { UINT8_C( 31), UINT8_C(  2), UINT8_C( 21), UINT8_C(194), UINT8_C(  4), UINT8_C( 20), UINT8_C( 31), UINT8_C( 14) },
      {  INT8_C(  35),      INT8_MIN,  INT8_C(  71),  INT8_C(   0), -INT8_C(  29), -INT8_C(  59),  INT8_C(  35), -INT8_C( 127) } },
    {
        { {  INT8_C(  49), -INT8_C(  34),  INT8_C( 101), -INT8_C(  10),  INT8_C(  37),  INT8_C(  36),  INT8_C( 120), -INT8_C(  30),
             INT8_C(  56),  INT8_C(  16), -INT8_C(  20), -INT8_C(  97),  INT8_C(   6), -INT8_C(  82), -INT8_C(  62), -INT8_C(  27) },
          { -INT8_C(  16),  INT8_C(  55), -INT8_C(  89),  INT8_C(  20),  INT8_C(  76), -INT8_C(  58),  INT8_C(  35), -INT8_C( 123),
            -INT8_C( 104), -INT8_C(  81),  INT8_C(  68), -INT8_C(  52), -INT8_C(  67), -INT8_C(  91),      INT8_MAX, -INT8_C(  18) } },
      { UINT8_C(  3), UINT8_C(228), UINT8_C(  4), UINT8_C(  8), UINT8_C(  8), UINT8_C( 92), UINT8_C( 11), UINT8_C(  0) },
      { -INT8_C(  10),  INT8_C(   0),  INT8_C(  37),  INT8_C(  56),  INT8_C(  56),  INT8_C(   0), -INT8_C(  97),  INT8_C(  49) } },
    {
        { { -INT8_C(  38),  INT8_C(   0),  INT8_C(  42),  INT8_C(  38), -INT8_C(  57),  INT8_C(  77), -INT8_C(  85),  INT8_C(  95),
            -INT8_C(   4), -INT8_C(  17),  INT8_C(  43), -INT8_C(  71), -INT8_C( 108), -INT8_C(  86), -INT8_C(  89),  INT8_C(  24) },
          { -INT8_C( 113), -INT8_C( 117), -INT8_C(  64), -INT8_C( 105), -INT8_C(  24),  INT8_C(  75), -INT8_C(  40),  INT8_C(  85),
            -INT8_C(  61), -INT8_C(  72), -INT8_C(  56), -INT8_C(  24),  INT8_C(  90),  INT8_C(  33), -INT8_C(   2),  INT8_C(  52) } },
      { UINT8_C(  2), UINT8_C( 40), UINT8_C( 26), UINT8_C(  9), UINT8_C(117), UINT8_C(  5), UINT8_C(  8), UINT8_C( 17) },
      {  INT8_C(  42),  INT8_C(   0), -INT8_C(  56), -INT8_C(  17),  INT8_C(   0),  INT8_C(  77), -INT8_C(   4), -INT8_C( 117) } },
    {
        { {  INT8_C(  94),  INT8_C(  97),  INT8_C(  69),  INT8_C(  70), -INT8_C(  83),  INT8_C(  29), -INT8_C( 101),  INT8_C( 112),
            -INT8_C(  43),  INT8_C(  99),  INT8_C(  88),  INT8_C(  47), -INT8_C( 123),  INT8_C(  86),  INT8_C( 100), -INT8_C(  89) },
          {  INT8_C( 126), -INT8_C(  66), -INT8_C( 112), -INT8_C(  13), -INT8_C(  60), -INT8_C(  40),  INT8_C( 101), -INT8_C(  72),
             INT8_C(  76), -INT8_C( 112),  INT8_C(  65),  INT8_C( 107),  INT8_C(  98), -INT8_C(  30),  INT8_C(  24), -INT8_C(  64) } },
      { UINT8_C( 68), UINT8_C( 29), UINT8_C(  6), UINT8_C( 17), UINT8_C( 26), UINT8_C(  1), UINT8_C(  1), UINT8_C( 15) },
      {  INT8_C(   0), -INT8_C(  30), -INT8_C( 101), -INT8_C(  66),  INT8_C(  65),  INT8_C(  97),  INT8_C(  97), -INT8_C(  89) } },
    {
        { { -INT8_C(  95), -INT8_C(  63), -INT8_C( 126),  INT8_C( 101), -INT8_C( 103), -INT8_C(  25),  INT8_C(  30), -INT8_C(  26),
             INT8_C( 119),  INT8_C(  95),  INT8_C(  81), -INT8_C(  39),  INT8_C(  66),  INT8_C( 105), -INT8_C( 102), -INT8_C( 122) },
          { -INT8_C(  57), -INT8_C(  96),  INT8_C( 119),  INT8_C(  65),  INT8_C(  66), -INT8_C(  40), -INT8_C( 111),  INT8_C(  71),
            -INT8_C( 111),  INT8_C(  16), -INT8_C(  47), -INT8_C(  95), -INT8_C(  13),  INT8_C(   2),  INT8_C(  48), -INT8_C( 108) } },
      { UINT8_C(  3), UINT8_C( 18), UINT8_C(250), UINT8_C( 28), UINT8_C( 25), UINT8_C( 24), UINT8_C(  2), UINT8_C( 16) },
      {  INT8_C( 101),  INT8_C( 119),  INT8_C(   0), -INT8_C(  13),  INT8_C(  16), -INT8_C( 111), -INT8_C( 126), -INT8_C(  57) } },
    {
        { {  INT8_C(  36), -INT8_C(  74),  INT8_C(   5),  INT8_C( 102), -INT8_C( 114), -INT8_C( 106), -INT8_C(  83),  INT8_C(  32),
            -INT8_C(  90),  INT8_C( 126), -INT8_C(  63), -INT8_C( 103),      INT8_MIN, -INT8_C(  15),  INT8_C(  46),  INT8_C(  67) },
          { -INT8_C(  93),  INT8_C(  40), -INT8_C(  97),  INT8_C(  60),  INT8_C(  64), -INT8_C(  30),  INT8_C(  76), -INT8_C(  73),
             INT8_C( 117),  INT8_C(  54),  INT8_C( 113),  INT8_C( 114), -INT8_C(  71), -INT8_C(  80),  INT8_C(  54), -INT8_C(  35) } },
      { UINT8_C(  7), UINT8_C( 60), UINT8_C(  3), UINT8_C( 21), UINT8_C( 18), UINT8_C(240), UINT8_C( 21), UINT8_C( 25) },
      {  INT8_C(  32),  INT8_C(   0),  INT8_C( 102), -INT8_C(  30), -INT8_C(  97),  INT8_C(   0), -INT8_C(  30),  INT8_C(  54) } },
    {
        { {  INT8_C( 104), -INT8_C(  47), -INT8_C(  88), -INT8_C(  88), -INT8_C(  77), -INT8_C(  11),  INT8_C(  96),  INT8_C(  40),
             INT8_C(  43), -INT8_C(  47), -INT8_C( 101), -INT8_C(  28), -INT8_C( 127), -INT8_C(  47), -INT8_C(  62), -INT8_C(  24) },
          {  INT8_C(  13),  INT8_C(   5), -INT8_C(  34), -INT8_C(  32), -INT8_C(  10), -INT8_C(  13),  INT8_C(  89),  INT8_C( 100),
            -INT8_C(  54),  INT8_C( 107),  INT8_C(  83), -INT8_C( 109), -INT8_C(  84), -INT8_C( 124), -INT8_C(   1),  INT8_C(  20) } },
      { UINT8_C( 21), UINT8_C(  7), UINT8_C( 29), UINT8_C(  8), UINT8_C( 28), UINT8_C( 29), UINT8_C( 17), UINT8_C(199) },
      { -INT8_C(  13),  INT8_C(  40), -INT8_C( 124),  INT8_C(  43), -INT8_C(  84), -INT8_C( 124),  INT8_C(   5),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x2_t t;
    simde_uint8x8_t idx = simde_vld1_u8(test_vec[i].idx);
    simde_int8x8_t r;
    t.val[0] = simde_vld1q_s8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_s8(test_vec[i].t[1]);
    r = simde_vqtbl2_s8(t, idx);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16x2_t t = simde_test_arm_neon_random_i8x16x2();
    simde_uint8x8_private idx_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 31;
      }
    }

    simde_uint8x8_t idx = simde_uint8x8_from_private(idx_);

    simde_int8x8_t r = simde_vqtbl2_s8(t, idx);
    simde_test_arm_neon_write_i8x16x2(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl2_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 uint8_t t[2][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[8];
    SIMDE_ALIGN_TO_16 uint8_t r[8];
  } test_vec[] = {
    {
        { { UINT8_C(100), UINT8_C( 13), UINT8_C(102), UINT8_C(107), UINT8_C( 43), UINT8_C(137), UINT8_C( 34), UINT8_C( 34),
            UINT8_C(186), UINT8_C(204), UINT8_C( 12), UINT8_C(111), UINT8_C(110), UINT8_C( 43), UINT8_C(121), UINT8_C(110) },
          { UINT8_C(239), UINT8_C( 67), UINT8_C(177), UINT8_C(201), UINT8_C( 68), UINT8_C( 65), UINT8_C(171), UINT8_C( 23),
            UINT8_C(115), UINT8_C(  0), UINT8_C( 85), UINT8_C(146), UINT8_C( 33), UINT8_C( 24), UINT8_C(200), UINT8_C(134) } },
      { UINT8_C(  5), UINT8_C( 14), UINT8_C( 17), UINT8_C( 16), UINT8_C( 23), UINT8_C( 19), UINT8_C( 19), UINT8_C(113) },
      { UINT8_C(137), UINT8_C(121), UINT8_C( 67), UINT8_C(239), UINT8_C( 23), UINT8_C(201), UINT8_C(201), UINT8_C(  0) } },
    {
        { { UINT8_C(157), UINT8_C(108), UINT8_C( 98), UINT8_C(225), UINT8_C(173), UINT8_C( 14), UINT8_C(248), UINT8_C( 32),
            UINT8_C( 14), UINT8_C( 77), UINT8_C(178), UINT8_C( 47), UINT8_C(101), UINT8_C(122), UINT8_C(181), UINT8_C(139) },
          { UINT8_C(169), UINT8_C(166), UINT8_C(219), UINT8_C( 96), UINT8_C(186), UINT8_C( 78), UINT8_C(210), UINT8_C(153),
            UINT8_C(205), UINT8_C(178), UINT8_C(231), UINT8_C(119), UINT8_C( 12), UINT8_C(162), UINT8_C( 16), UINT8_C(169) } },
      { UINT8_C( 15), UINT8_C( 19), UINT8_C( 10), UINT8_C( 28), UINT8_C(  1), UINT8_C(131), UINT8_C( 29), UINT8_C(143) },
      { UINT8_C(139), UINT8_C( 96), UINT8_C(178), UINT8_C( 12), UINT8_C(108), UINT8_C(  0), UINT8_C(162), UINT8_C(  0) } },
    {
        { { UINT8_C( 26), UINT8_C(156), UINT8_C( 19), UINT8_C(212), UINT8_C(235), UINT8_C(229), UINT8_C(110), UINT8_C(184),
            UINT8_C(152), UINT8_C( 85), UINT8_C( 48), UINT8_C(164), UINT8_C(247), UINT8_C( 64), UINT8_C( 77), UINT8_C(  6) },
          { UINT8_C(179), UINT8_C(215), UINT8_C(195), UINT8_C( 52), UINT8_C( 90), UINT8_C(160), UINT8_C(195), UINT8_C( 43),
            UINT8_C( 47), UINT8_C(130), UINT8_C( 97), UINT8_C( 57), UINT8_C(246), UINT8_C( 34), UINT8_C(236), UINT8_C( 16) } },
      { UINT8_C(190), UINT8_C(  0), UINT8_C(  5), UINT8_C(  9), UINT8_C(  5), UINT8_C( 83), UINT8_C(  2), UINT8_C( 29) },
      { UINT8_C(  0), UINT8_C( 26), UINT8_C(229), UINT8_C( 85), UINT8_C(229), UINT8_C(  0), UINT8_C( 19), UINT8_C( 34) } },
    {
        { { UINT8_C( 70), UINT8_C(105), UINT8_C(186), UINT8_C(160), UINT8_C(  9), UINT8_C(126), UINT8_C(203), UINT8_C( 56),
            UINT8_C(  0), UINT8_C( 44), UINT8_C(114), UINT8_C(246), UINT8_C( 78), UINT8_C( 94), UINT8_C(  6), UINT8_C( 13) },
          { UINT8_C( 94), UINT8_C(235), UINT8_C(182), UINT8_C( 68), UINT8_C( 62), UINT8_C( 24), UINT8_C(193), UINT8_C(230),
            UINT8_C(170), UINT8_C(227), UINT8_C(134), UINT8_C(125), UINT8_C( 81), UINT8_C( 44), UINT8_C(  3), UINT8_C(151) } },
      { UINT8_C(149), UINT8_C( 29), UINT8_C( 24), UINT8_C(158), UINT8_C( 27), UINT8_C(  3), UINT8_C( 22), UINT8_C( 27) },
      { UINT8_C(  0), UINT8_C( 44), UINT8_C(170), UINT8_C(  0), UINT8_C(125), UINT8_C(160), UINT8_C(193), UINT8_C(125) } },
    {
        { { UINT8_C( 35), UINT8_C( 66), UINT8_C( 73), UINT8_C( 98), UINT8_C( 90), UINT8_C( 11), UINT8_C( 72), UINT8_C(  5),
            UINT8_C(238), UINT8_C(206), UINT8_C(130), UINT8_C( 63), UINT8_C(250), UINT8_C(133), UINT8_C(215), UINT8_C(143) },
          { UINT8_C( 66), UINT8_C( 15), UINT8_C( 45), UINT8_C(126), UINT8_C( 18), UINT8_C(  4), UINT8_C(185), UINT8_C( 66),
            UINT8_C( 76), UINT8_C(235), UINT8_C(193), UINT8_C(243), UINT8_C( 35), UINT8_C( 76), UINT8_C(249), UINT8_C( 70) } },
      { UINT8_C( 14), UINT8_C(  2), UINT8_C(  8), UINT8_C(  9), UINT8_C( 13), UINT8_C(241), UINT8_C( 14), UINT8_C( 27) },
      { UINT8_C(215), UINT8_C( 73), UINT8_C(238), UINT8_C(206), UINT8_C(133), UINT8_C(  0), UINT8_C(215), UINT8_C(243) } },
    {
        { { UINT8_C( 97), UINT8_C(119), UINT8_C(181), UINT8_C(115), UINT8_C(123), UINT8_C(111), UINT8_C(182), UINT8_C(199),
            UINT8_C( 90), UINT8_C(119), UINT8_C(187), UINT8_C(125), UINT8_C(195), UINT8_C(180), UINT8_C(195), UINT8_C( 82) },
          { UINT8_C(246), UINT8_C(108), UINT8_C( 59), UINT8_C( 68), UINT8_C( 93), UINT8_C( 41), UINT8_C(127), UINT8_C( 28),
            UINT8_C(153), UINT8_C(250), UINT8_C(214), UINT8_C(142), UINT8_C( 76), UINT8_C( 32), UINT8_C(197), UINT8_C(173) } },
      { UINT8_C(151), UINT8_C( 27), UINT8_C(  1), UINT8_C( 18), UINT8_C( 10), UINT8_C( 23), UINT8_C( 25), UINT8_C(  4) },
      { UINT8_C(  0), UINT8_C(142), UINT8_C(119), UINT8_C( 59), UINT8_C(187), UINT8_C( 28), UINT8_C(250), UINT8_C(123) } },
    {
        { { UINT8_C(240), UINT8_C(158), UINT8_C(131), UINT8_C( 77), UINT8_C(199), UINT8_C(  2), UINT8_C(106), UINT8_C( 96),
            UINT8_C(253), UINT8_C( 64), UINT8_C(238), UINT8_C( 73), UINT8_C( 96), UINT8_C(180), UINT8_C(247), UINT8_C(247) },
          { UINT8_C( 47), UINT8_C( 24), UINT8_C(  9), UINT8_C( 25), UINT8_C(239), UINT8_C(227), UINT8_C( 93), UINT8_C( 61),
            UINT8_C(119), UINT8_C( 30), UINT8_C( 78), UINT8_C(192), UINT8_C(162), UINT8_C(178),    UINT8_MAX, UINT8_C(147) } },
      { UINT8_C( 16), UINT8_C(  2), UINT8_C(224), UINT8_C( 24), UINT8_C(  4), UINT8_C( 10), UINT8_C( 24), UINT8_C(  1) },
      { UINT8_C( 47), UINT8_C(131), UINT8_C(  0), UINT8_C(119), UINT8_C(199), UINT8_C(238), UINT8_C(119), UINT8_C(158) } },
    {
        { { UINT8_C(218), UINT8_C(236), UINT8_C( 99), UINT8_C(201), UINT8_C(207), UINT8_C(192), UINT8_C(  6), UINT8_C( 71),
            UINT8_C(222), UINT8_C( 84), UINT8_C(  7), UINT8_C(128), UINT8_C(  6), UINT8_C(  6), UINT8_C( 19), UINT8_C( 87) },
          { UINT8_C(136), UINT8_C(244), UINT8_C(111), UINT8_C( 12), UINT8_C( 62), UINT8_C(231), UINT8_C(142), UINT8_C(201),
            UINT8_C( 78), UINT8_C( 89), UINT8_C(181), UINT8_C(105), UINT8_C( 27), UINT8_C(152), UINT8_C(179), UINT8_C(245) } },
      { UINT8_C(132), UINT8_C( 22), UINT8_C(190), UINT8_C( 20), UINT8_C( 22), UINT8_C(  4), UINT8_C(155), UINT8_C( 20) },
      { UINT8_C(  0), UINT8_C(142), UINT8_C(  0), UINT8_C( 62), UINT8_C(142), UINT8_C(207), UINT8_C(  0), UINT8_C( 62) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x2_t t;
    simde_uint8x8_t idx, r;
    idx = simde_vld1_u8(test_vec[i].idx);
    t.val[0] = simde_vld1q_u8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_u8(test_vec[i].t[1]);
    r = simde_vqtbl2_u8(t, idx);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16x2_t t = simde_test_arm_neon_random_u8x16x2();
    simde_uint8x8_private idx_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 31;
      }
    }

    simde_uint8x8_t idx = simde_uint8x8_from_private(idx_);

    simde_uint8x8_t r = simde_vqtbl2_u8(t, idx);

    simde_test_arm_neon_write_u8x16x2(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl3_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 int8_t t[3][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[8];
    SIMDE_ALIGN_TO_16 int8_t r[8];
  } test_vec[] = {
    {
        { { -INT8_C(  89),  INT8_C(  74), -INT8_C( 122),  INT8_C(   5), -INT8_C(  54), -INT8_C( 125),  INT8_C(  83), -INT8_C(  23),
            -INT8_C(  83), -INT8_C(  23), -INT8_C(  63),  INT8_C(  36), -INT8_C(  31),  INT8_C(  61), -INT8_C(  38), -INT8_C(  49) },
          {  INT8_C(  53),  INT8_C( 108), -INT8_C(  51), -INT8_C(  96),  INT8_C(  38), -INT8_C(  87), -INT8_C( 102), -INT8_C(  70),
            -INT8_C(  15),  INT8_C(  52), -INT8_C(  59),  INT8_C(  64),  INT8_C( 109),  INT8_C(  58), -INT8_C(  48),  INT8_C(  21) },
          { -INT8_C( 124),  INT8_C(  86),  INT8_C(  26),  INT8_C(  78), -INT8_C(  39),  INT8_C( 109),  INT8_C(  56), -INT8_C( 121),
             INT8_C(  86), -INT8_C(   7), -INT8_C(  85),  INT8_C(  55),  INT8_C(  54), -INT8_C( 123),  INT8_C(   7),  INT8_C( 107) } },
      { UINT8_C(  2), UINT8_C( 20), UINT8_C( 11), UINT8_C( 24), UINT8_C(125), UINT8_C( 22), UINT8_C(210), UINT8_C( 14) },
      { -INT8_C( 122),  INT8_C(  38),  INT8_C(  36), -INT8_C(  15),  INT8_C(   0), -INT8_C( 102),  INT8_C(   0), -INT8_C(  38) } },
    {
        { { -INT8_C(  43),  INT8_C( 119), -INT8_C(  93), -INT8_C(  82), -INT8_C(  28), -INT8_C(  37),  INT8_C(  53),  INT8_C(  59),
            -INT8_C(  43), -INT8_C(  32),  INT8_C( 114),  INT8_C(  11),  INT8_C( 102),  INT8_C( 121),  INT8_C( 119),  INT8_C(  88) },
          {  INT8_C(  77), -INT8_C( 126),  INT8_C( 112), -INT8_C(  54),  INT8_C(  40),  INT8_C(  66),  INT8_C(  57),  INT8_C(   3),
            -INT8_C(  39), -INT8_C(  25),  INT8_C(  75), -INT8_C(  86),  INT8_C( 102), -INT8_C(  88), -INT8_C(   1),  INT8_C(  59) },
          {  INT8_C(  31), -INT8_C(  94), -INT8_C(  23),  INT8_C(   3),  INT8_C( 126),  INT8_C(  31),  INT8_C(  62),  INT8_C(  83),
            -INT8_C(   1), -INT8_C(  79),  INT8_C(  94),  INT8_C( 101),  INT8_C(  42), -INT8_C(  43), -INT8_C(  67),  INT8_C( 120) } },
      { UINT8_C( 40), UINT8_C( 45), UINT8_C( 18), UINT8_C( 32), UINT8_C(111), UINT8_C( 27), UINT8_C( 35), UINT8_C( 24) },
      { -INT8_C(   1), -INT8_C(  43),  INT8_C( 112),  INT8_C(  31),  INT8_C(   0), -INT8_C(  86),  INT8_C(   3), -INT8_C(  39) } },
    {
        { { -INT8_C( 108), -INT8_C(  19), -INT8_C( 103),  INT8_C(  18),  INT8_C(  12), -INT8_C(  41),  INT8_C( 101),  INT8_C(  12),
            -INT8_C( 120), -INT8_C(  61),  INT8_C( 113), -INT8_C(  77), -INT8_C( 103),  INT8_C(  47),  INT8_C(  43), -INT8_C(  15) },
          {  INT8_C(  92),  INT8_C( 109),  INT8_C( 113), -INT8_C(  52), -INT8_C(  23), -INT8_C(  11),  INT8_C(  20),  INT8_C(  76),
            -INT8_C(  61),  INT8_C(   7),  INT8_C(  21),  INT8_C(  58), -INT8_C(   8),  INT8_C(  25), -INT8_C(  49), -INT8_C( 116) },
          {  INT8_C(   6),  INT8_C( 104), -INT8_C(  98),  INT8_C(  19),  INT8_C(  64),  INT8_C(   3),  INT8_C(  31), -INT8_C(  56),
            -INT8_C(  57), -INT8_C( 112),  INT8_C( 123),  INT8_C(  96), -INT8_C(  65), -INT8_C(  90),  INT8_C(  81),  INT8_C(  28) } },
      { UINT8_C( 20), UINT8_C(  2), UINT8_C( 40), UINT8_C(253), UINT8_C( 39), UINT8_C( 12), UINT8_C( 25), UINT8_C(123) },
      { -INT8_C(  23), -INT8_C( 103), -INT8_C(  57),  INT8_C(   0), -INT8_C(  56), -INT8_C( 103),  INT8_C(   7),  INT8_C(   0) } },
    {
        { { -INT8_C(  19),  INT8_C(  39), -INT8_C( 112),  INT8_C(  45),  INT8_C(  42), -INT8_C(  81), -INT8_C(  11), -INT8_C(  15),
             INT8_C(  64),  INT8_C( 113),  INT8_C(  81), -INT8_C(   1),  INT8_C(  23), -INT8_C(  94),  INT8_C(  27),  INT8_C(  43) },
          {  INT8_C( 101),  INT8_C(   3),  INT8_C(  40),  INT8_C(  28),  INT8_C(   0),  INT8_C( 113), -INT8_C( 105),  INT8_C(   3),
            -INT8_C(  49),  INT8_C(  76), -INT8_C(   1),  INT8_C(  70), -INT8_C(  47), -INT8_C( 120), -INT8_C(  60), -INT8_C(  66) },
          { -INT8_C(  81),  INT8_C(  84), -INT8_C(  21), -INT8_C(  39),  INT8_C(   4), -INT8_C(  32), -INT8_C(  53),  INT8_C(  68),
             INT8_C(  81),  INT8_C(  28),  INT8_C(  67),  INT8_C( 105), -INT8_C(  65),  INT8_C(  95), -INT8_C( 108),  INT8_C(  36) } },
      { UINT8_C(  2), UINT8_C(189), UINT8_C( 16), UINT8_C(  2), UINT8_C( 46), UINT8_C(216), UINT8_C(102), UINT8_C(254) },
      { -INT8_C( 112),  INT8_C(   0),  INT8_C( 101), -INT8_C( 112), -INT8_C( 108),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    {
        { {  INT8_C(  93), -INT8_C(  98),  INT8_C( 118),  INT8_C(  97),      INT8_MAX,  INT8_C(  65), -INT8_C(  91), -INT8_C(  48),
             INT8_C(  93), -INT8_C(  24),  INT8_C(  57),  INT8_C(  28),  INT8_C(  71), -INT8_C(  50),  INT8_C(  64), -INT8_C(  86) },
          { -INT8_C( 117), -INT8_C( 127),  INT8_C(  12), -INT8_C(  71),  INT8_C(  89),  INT8_C( 114), -INT8_C(  73),  INT8_C( 125),
            -INT8_C(  40), -INT8_C(   4),  INT8_C( 115), -INT8_C(  59),  INT8_C(   4),  INT8_C(  38),  INT8_C(  98),  INT8_C(  97) },
          { -INT8_C(  59), -INT8_C(  40), -INT8_C(  62),  INT8_C(  68),  INT8_C(  25),  INT8_C( 103),  INT8_C(  20),  INT8_C( 118),
             INT8_C(  80),  INT8_C(  78), -INT8_C( 109), -INT8_C( 105),  INT8_C(  28), -INT8_C(  45),  INT8_C(  65), -INT8_C(  89) } },
      { UINT8_C( 36), UINT8_C( 30), UINT8_C(  0), UINT8_C(173), UINT8_C(  0), UINT8_C( 24), UINT8_C( 43), UINT8_C(152) },
      {  INT8_C(  25),  INT8_C(  98),  INT8_C(  93),  INT8_C(   0),  INT8_C(  93), -INT8_C(  40), -INT8_C( 105),  INT8_C(   0) } },
    {
        { { -INT8_C( 104),  INT8_C(  60), -INT8_C(  51), -INT8_C(  79), -INT8_C(  92), -INT8_C(  30),  INT8_C(  39), -INT8_C(  12),
             INT8_C(  48), -INT8_C(  70), -INT8_C( 117),  INT8_C(  76), -INT8_C( 114), -INT8_C(  51), -INT8_C(  13), -INT8_C(  30) },
          {  INT8_C(  27),  INT8_C(  83), -INT8_C( 112), -INT8_C(  37),  INT8_C( 107), -INT8_C(  69),  INT8_C( 116),      INT8_MAX,
             INT8_C(  89), -INT8_C(  46), -INT8_C( 104),  INT8_C(  29), -INT8_C( 110),  INT8_C(  18), -INT8_C(  89),  INT8_C(  42) },
          {  INT8_C(  78),  INT8_C( 116), -INT8_C(  37), -INT8_C(  14),  INT8_C(  86),  INT8_C(   2), -INT8_C(  26), -INT8_C( 122),
            -INT8_C(  67),  INT8_C( 114), -INT8_C(  46),  INT8_C(  75),  INT8_C(  63), -INT8_C(  59),  INT8_C(  45),  INT8_C(  90) } },
      { UINT8_C( 25), UINT8_C( 45), UINT8_C(  5), UINT8_C( 36), UINT8_C( 24), UINT8_C(169), UINT8_C(  4), UINT8_C( 17) },
      { -INT8_C(  46), -INT8_C(  59), -INT8_C(  30),  INT8_C(  86),  INT8_C(  89),  INT8_C(   0), -INT8_C(  92),  INT8_C(  83) } },
    {
        { {  INT8_C(  10),  INT8_C(  18), -INT8_C(  17),  INT8_C(  97),  INT8_C(  21), -INT8_C(  43), -INT8_C(  25), -INT8_C(  46),
             INT8_C(  71), -INT8_C(  70),  INT8_C(  29), -INT8_C( 122),      INT8_MAX,  INT8_C(  74), -INT8_C(  32), -INT8_C( 104) },
          {  INT8_C(   8),  INT8_C(  22),  INT8_C(  29),      INT8_MIN, -INT8_C(  65),  INT8_C(  33),  INT8_C(  82),  INT8_C(  59),
            -INT8_C(  67),  INT8_C(  65),  INT8_C(  72),  INT8_C( 107), -INT8_C(  41),      INT8_MIN,  INT8_C( 103), -INT8_C(  31) },
          { -INT8_C( 110),  INT8_C(  86),  INT8_C(  66), -INT8_C(  89),  INT8_C(  44),  INT8_C(  42),  INT8_C( 121),  INT8_C( 115),
            -INT8_C(  28), -INT8_C( 106), -INT8_C(   6),  INT8_C(  99), -INT8_C(  31), -INT8_C(  38), -INT8_C(   4), -INT8_C(  23) } },
      { UINT8_C(240), UINT8_C( 25), UINT8_C(  9), UINT8_C(176), UINT8_C( 10), UINT8_C( 43), UINT8_C(235), UINT8_C(  7) },
      {  INT8_C(   0),  INT8_C(  65), -INT8_C(  70),  INT8_C(   0),  INT8_C(  29),  INT8_C(  99),  INT8_C(   0), -INT8_C(  46) } },
    {
        { {  INT8_C(  32), -INT8_C(   9), -INT8_C(  19),  INT8_C(  76),  INT8_C(  33),  INT8_C( 103), -INT8_C(  65),  INT8_C(   5),
            -INT8_C(   3), -INT8_C(  71),  INT8_C( 105), -INT8_C(  34), -INT8_C( 108),  INT8_C( 101), -INT8_C(  57), -INT8_C( 124) },
          {  INT8_C( 126),  INT8_C(  49),  INT8_C(  52), -INT8_C(  72), -INT8_C(  20),  INT8_C(  31), -INT8_C(  81), -INT8_C(  23),
             INT8_C(  83),  INT8_C(  17), -INT8_C(  68),  INT8_C(   6), -INT8_C(  38),  INT8_C( 113),  INT8_C(  76), -INT8_C(   6) },
          {  INT8_C( 105),  INT8_C(  58),  INT8_C(  70), -INT8_C( 118), -INT8_C(  95),  INT8_C(   6), -INT8_C( 112), -INT8_C(  98),
            -INT8_C(  65), -INT8_C(   7),  INT8_C( 125),  INT8_C(  83),  INT8_C(  94),  INT8_C(  68), -INT8_C(  40), -INT8_C(  36) } },
      { UINT8_C( 21), UINT8_C( 12), UINT8_C(  4), UINT8_C(  2), UINT8_C( 44), UINT8_C( 19), UINT8_C( 27), UINT8_C( 31) },
      {  INT8_C(  31), -INT8_C( 108),  INT8_C(  33), -INT8_C(  19),  INT8_C(  94), -INT8_C(  72),  INT8_C(   6), -INT8_C(   6) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x3_t t;
    simde_uint8x8_t idx = simde_vld1_u8(test_vec[i].idx);
    simde_int8x8_t r;
    t.val[0] = simde_vld1q_s8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_s8(test_vec[i].t[1]);
    t.val[2] = simde_vld1q_s8(test_vec[i].t[2]);
    r = simde_vqtbl3_s8(t, idx);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16x3_t t = simde_test_arm_neon_random_i8x16x3();
    simde_uint8x8_private idx_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] %= 48;
      }
    }

    simde_uint8x8_t idx = simde_uint8x8_from_private(idx_);

    simde_int8x8_t r = simde_vqtbl3_s8(t, idx);
    simde_test_arm_neon_write_i8x16x3(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl3_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 uint8_t t[3][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[8];
    SIMDE_ALIGN_TO_16 uint8_t r[8];
  } test_vec[] = {
    {
        { { UINT8_C(208), UINT8_C( 97), UINT8_C(114), UINT8_C(178), UINT8_C(120), UINT8_C( 19), UINT8_C(  1), UINT8_C(138),
            UINT8_C(136), UINT8_C( 71), UINT8_C(  4), UINT8_C(251), UINT8_C(  0), UINT8_C(149), UINT8_C(109), UINT8_C( 74) },
          { UINT8_C( 90), UINT8_C(147), UINT8_C(103), UINT8_C( 44), UINT8_C(188), UINT8_C(116), UINT8_C(156), UINT8_C(105),
            UINT8_C(117), UINT8_C(159), UINT8_C( 36), UINT8_C(192), UINT8_C(208), UINT8_C(106), UINT8_C( 53), UINT8_C(160) },
          { UINT8_C(203), UINT8_C(167), UINT8_C( 83), UINT8_C( 67), UINT8_C(187), UINT8_C( 84), UINT8_C(205), UINT8_C( 67),
            UINT8_C(156), UINT8_C(209), UINT8_C( 62), UINT8_C(156), UINT8_C(103), UINT8_C(171), UINT8_C(230), UINT8_C(193) } },
      { UINT8_C( 62), UINT8_C( 30), UINT8_C( 45), UINT8_C( 10), UINT8_C(194), UINT8_C( 41), UINT8_C(  3), UINT8_C(  7) },
      { UINT8_C(  0), UINT8_C( 53), UINT8_C(171), UINT8_C(  4), UINT8_C(  0), UINT8_C(209), UINT8_C(178), UINT8_C(138) } },
    {
        { { UINT8_C(212), UINT8_C(236), UINT8_C(  1), UINT8_C(143), UINT8_C( 64), UINT8_C(206), UINT8_C(210), UINT8_C(220),
            UINT8_C(160), UINT8_C( 16), UINT8_C(121), UINT8_C(  7), UINT8_C(187), UINT8_C( 95), UINT8_C(200), UINT8_C(250) },
          { UINT8_C(173), UINT8_C(182), UINT8_C(244), UINT8_C(111), UINT8_C( 63), UINT8_C( 88), UINT8_C(166), UINT8_C(104),
            UINT8_C(224), UINT8_C(158), UINT8_C( 96), UINT8_C(210), UINT8_C(203), UINT8_C(249), UINT8_C(143), UINT8_C(159) },
          { UINT8_C(229), UINT8_C(144), UINT8_C( 47), UINT8_C( 38), UINT8_C( 95), UINT8_C(  1), UINT8_C(  2),    UINT8_MAX,
            UINT8_C( 18), UINT8_C(123), UINT8_C(  6), UINT8_C(205), UINT8_C(219), UINT8_C(206), UINT8_C(199), UINT8_C(136) } },
      { UINT8_C( 36), UINT8_C( 44), UINT8_C(  8), UINT8_C(  4), UINT8_C( 20), UINT8_C( 14), UINT8_C( 44), UINT8_C(  4) },
      { UINT8_C( 95), UINT8_C(219), UINT8_C(160), UINT8_C( 64), UINT8_C( 63), UINT8_C(200), UINT8_C(219), UINT8_C( 64) } },
    {
        { { UINT8_C(230), UINT8_C(214), UINT8_C(145), UINT8_C( 69), UINT8_C(215), UINT8_C(148), UINT8_C( 68), UINT8_C(233),
            UINT8_C( 15), UINT8_C( 74), UINT8_C(183), UINT8_C(234), UINT8_C( 24), UINT8_C(126), UINT8_C(115), UINT8_C(157) },
          { UINT8_C( 58), UINT8_C(107), UINT8_C( 97), UINT8_C( 78), UINT8_C(  9), UINT8_C(141), UINT8_C( 66), UINT8_C( 70),
            UINT8_C( 25), UINT8_C(  8), UINT8_C( 77), UINT8_C(159), UINT8_C( 94), UINT8_C(244), UINT8_C( 11), UINT8_C( 68) },
          { UINT8_C(202), UINT8_C(156), UINT8_C(137), UINT8_C(162), UINT8_C( 48), UINT8_C(205), UINT8_C(139), UINT8_C( 64),
            UINT8_C( 23), UINT8_C( 66), UINT8_C( 42), UINT8_C( 47), UINT8_C(193), UINT8_C(157), UINT8_C(204), UINT8_C(251) } },
      { UINT8_C(  8), UINT8_C( 45), UINT8_C( 74), UINT8_C( 18), UINT8_C(186), UINT8_C( 44), UINT8_C( 40), UINT8_C( 20) },
      { UINT8_C( 15), UINT8_C(157), UINT8_C(  0), UINT8_C( 97), UINT8_C(  0), UINT8_C(193), UINT8_C( 23), UINT8_C(  9) } },
    {
        { { UINT8_C( 27), UINT8_C(192), UINT8_C(  6), UINT8_C( 75), UINT8_C(141), UINT8_C(146), UINT8_C(139), UINT8_C(164),
            UINT8_C(212), UINT8_C(182), UINT8_C(211), UINT8_C(149), UINT8_C( 83), UINT8_C(160), UINT8_C(145), UINT8_C( 92) },
          { UINT8_C(205), UINT8_C(219), UINT8_C(110), UINT8_C(136), UINT8_C(103), UINT8_C(198), UINT8_C( 92), UINT8_C(252),
            UINT8_C(107), UINT8_C(207), UINT8_C(239), UINT8_C(  5), UINT8_C( 78), UINT8_C( 38), UINT8_C(106), UINT8_C(105) },
          { UINT8_C(230), UINT8_C(112), UINT8_C(180), UINT8_C(115), UINT8_C(  2), UINT8_C( 64), UINT8_C( 23), UINT8_C(215),
            UINT8_C(246), UINT8_C(235), UINT8_C(108), UINT8_C( 73), UINT8_C(139), UINT8_C(253), UINT8_C(165), UINT8_C( 88) } },
      { UINT8_C( 24), UINT8_C( 19), UINT8_C( 32), UINT8_C( 16), UINT8_C( 25), UINT8_C( 12), UINT8_C( 12), UINT8_C( 21) },
      { UINT8_C(107), UINT8_C(136), UINT8_C(230), UINT8_C(205), UINT8_C(207), UINT8_C( 83), UINT8_C( 83), UINT8_C(198) } },
    {
        { { UINT8_C( 37), UINT8_C(119), UINT8_C(172), UINT8_C( 39), UINT8_C(183), UINT8_C(196), UINT8_C(254), UINT8_C(173),
            UINT8_C(175), UINT8_C(107), UINT8_C(247), UINT8_C( 58), UINT8_C(104), UINT8_C(156), UINT8_C(146), UINT8_C( 65) },
          { UINT8_C(176), UINT8_C(115), UINT8_C(129), UINT8_C(137), UINT8_C(175), UINT8_C(189), UINT8_C(206), UINT8_C(187),
            UINT8_C(233), UINT8_C( 25), UINT8_C( 21), UINT8_C( 60), UINT8_C(205), UINT8_C(216), UINT8_C(117), UINT8_C(242) },
          { UINT8_C( 80), UINT8_C( 33), UINT8_C( 26), UINT8_C(  7), UINT8_C(229), UINT8_C( 24), UINT8_C(181), UINT8_C(148),
            UINT8_C(131), UINT8_C(172), UINT8_C(206), UINT8_C(236), UINT8_C( 72), UINT8_C( 97), UINT8_C( 45), UINT8_C(248) } },
      { UINT8_C( 20), UINT8_C( 30), UINT8_C( 34), UINT8_C( 35), UINT8_C( 11), UINT8_C( 32), UINT8_C( 15), UINT8_C( 37) },
      { UINT8_C(175), UINT8_C(117), UINT8_C( 26), UINT8_C(  7), UINT8_C( 58), UINT8_C( 80), UINT8_C( 65), UINT8_C( 24) } },
    {
        { { UINT8_C( 39), UINT8_C( 67), UINT8_C(132), UINT8_C( 13), UINT8_C( 92), UINT8_C( 57), UINT8_C(161), UINT8_C(223),
            UINT8_C(229), UINT8_C(112), UINT8_C(203), UINT8_C( 46), UINT8_C(209), UINT8_C(248), UINT8_C( 38), UINT8_C(165) },
          { UINT8_C(166), UINT8_C(168), UINT8_C( 40), UINT8_C( 18), UINT8_C(249), UINT8_C(103), UINT8_C(103), UINT8_C( 98),
            UINT8_C(188), UINT8_C(248), UINT8_C(153), UINT8_C(233), UINT8_C(254), UINT8_C(195), UINT8_C(102), UINT8_C( 37) },
          { UINT8_C(  6), UINT8_C(234), UINT8_C( 50), UINT8_C( 98), UINT8_C( 36), UINT8_C(212), UINT8_C( 66), UINT8_C(  9),
            UINT8_C( 68), UINT8_C( 13), UINT8_C( 55), UINT8_C( 21), UINT8_C(  6), UINT8_C( 94), UINT8_C(186), UINT8_C(172) } },
      { UINT8_C(  6), UINT8_C( 34), UINT8_C( 46),    UINT8_MAX, UINT8_C( 74), UINT8_C( 37), UINT8_C(  2), UINT8_C(  6) },
      { UINT8_C(161), UINT8_C( 50), UINT8_C(186), UINT8_C(  0), UINT8_C(  0), UINT8_C(212), UINT8_C(132), UINT8_C(161) } },
    {
        { { UINT8_C( 63), UINT8_C(115), UINT8_C( 39), UINT8_C( 99), UINT8_C( 71), UINT8_C(105), UINT8_C(109), UINT8_C(139),
            UINT8_C(119), UINT8_C(164), UINT8_C(160), UINT8_C(125), UINT8_C(  2), UINT8_C( 90), UINT8_C( 41), UINT8_C(  9) },
          { UINT8_C( 61), UINT8_C(232), UINT8_C(  8), UINT8_C(135), UINT8_C( 13), UINT8_C(106), UINT8_C(141), UINT8_C( 43),
            UINT8_C(102), UINT8_C(124), UINT8_C( 70), UINT8_C( 36), UINT8_C(209), UINT8_C(135), UINT8_C(233), UINT8_C( 16) },
          { UINT8_C(251), UINT8_C( 17), UINT8_C(116), UINT8_C( 66), UINT8_C(122), UINT8_C(225), UINT8_C(206), UINT8_C(241),
            UINT8_C(133), UINT8_C(110), UINT8_C(110), UINT8_C(136), UINT8_C(201), UINT8_C(152), UINT8_C(145), UINT8_C(  6) } },
      { UINT8_C( 32), UINT8_C(  9), UINT8_C( 45), UINT8_C( 45), UINT8_C(  4), UINT8_C( 26), UINT8_C( 40), UINT8_C(106) },
      { UINT8_C(251), UINT8_C(164), UINT8_C(152), UINT8_C(152), UINT8_C( 71), UINT8_C( 70), UINT8_C(133), UINT8_C(  0) } },
    {
        { { UINT8_C(137), UINT8_C(235), UINT8_C(196), UINT8_C(  3), UINT8_C(204), UINT8_C(146), UINT8_C(245), UINT8_C( 82),
            UINT8_C(  0), UINT8_C( 99), UINT8_C(218), UINT8_C(201), UINT8_C(251), UINT8_C(107), UINT8_C(207), UINT8_C(123) },
          { UINT8_C(  4), UINT8_C( 92), UINT8_C(  9), UINT8_C(  8), UINT8_C(118), UINT8_C(193), UINT8_C(114), UINT8_C( 12),
            UINT8_C(192), UINT8_C(  1), UINT8_C(115), UINT8_C( 71), UINT8_C(121), UINT8_C(235), UINT8_C(200), UINT8_C(  2) },
          { UINT8_C(214), UINT8_C(140), UINT8_C(  5), UINT8_C(163), UINT8_C( 30), UINT8_C(250), UINT8_C(245), UINT8_C( 31),
            UINT8_C( 94), UINT8_C(207), UINT8_C(232), UINT8_C( 89), UINT8_C( 58), UINT8_C(184), UINT8_C(213), UINT8_C( 62) } },
      { UINT8_C( 20), UINT8_C( 30), UINT8_C( 23), UINT8_C( 43), UINT8_C( 15), UINT8_C( 41), UINT8_C(  7), UINT8_C(  0) },
      { UINT8_C(118), UINT8_C(200), UINT8_C( 12), UINT8_C( 89), UINT8_C(123), UINT8_C(207), UINT8_C( 82), UINT8_C(137) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x3_t t;
    simde_uint8x8_t idx, r;
    idx = simde_vld1_u8(test_vec[i].idx);
    t.val[0] = simde_vld1q_u8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_u8(test_vec[i].t[1]);
    t.val[2] = simde_vld1q_u8(test_vec[i].t[2]);
    r = simde_vqtbl3_u8(t, idx);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16x3_t t = simde_test_arm_neon_random_u8x16x3();
    simde_uint8x8_private idx_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] %= 48;
      }
    }

    simde_uint8x8_t idx = simde_uint8x8_from_private(idx_);

    simde_uint8x8_t r = simde_vqtbl3_u8(t, idx);

    simde_test_arm_neon_write_u8x16x3(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl4_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 int8_t t[4][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[8];
    SIMDE_ALIGN_TO_16 int8_t r[8];
  } test_vec[] = {
    {
        { {  INT8_C(  97),  INT8_C(  11),  INT8_C(  79), -INT8_C( 105), -INT8_C(  26), -INT8_C( 117), -INT8_C(  75),  INT8_C( 124),
            -INT8_C(  52), -INT8_C(  21),  INT8_C(  43), -INT8_C(   1),  INT8_C( 105),  INT8_C(  94), -INT8_C(  42),  INT8_C(  42) },
          { -INT8_C(  12),  INT8_C(   5), -INT8_C(  14),  INT8_C(   1), -INT8_C(   5),  INT8_C(  49), -INT8_C( 102),  INT8_C(  78),
            -INT8_C(  11), -INT8_C(  49),  INT8_C( 119),  INT8_C( 100), -INT8_C(  85),  INT8_C( 113),  INT8_C(  44),  INT8_C(  12) },
          {  INT8_C( 124),  INT8_C( 123), -INT8_C(  93),  INT8_C(  99),  INT8_C(   7),  INT8_C(  88), -INT8_C(  33), -INT8_C(  45),
             INT8_C(  67),  INT8_C(  10), -INT8_C(  46), -INT8_C(  84),  INT8_C( 104), -INT8_C(  87), -INT8_C(  41),  INT8_C(  92) },
          { -INT8_C(  82), -INT8_C(  55),  INT8_C(  94), -INT8_C(  87), -INT8_C(   5), -INT8_C(   8), -INT8_C(   9), -INT8_C(  16),
            -INT8_C(  57),  INT8_C( 110),  INT8_C(  84),  INT8_C( 114), -INT8_C(  33), -INT8_C( 127),      INT8_MAX,  INT8_C(  92) } },
      { UINT8_C( 60), UINT8_C( 34), UINT8_C( 63), UINT8_C(  3), UINT8_C( 59), UINT8_C( 30), UINT8_C( 23), UINT8_C( 62) },
      { -INT8_C(  33), -INT8_C(  93),  INT8_C(  92), -INT8_C( 105),  INT8_C( 114),  INT8_C(  44),  INT8_C(  78),      INT8_MAX } },
    {
        { {  INT8_C(  11), -INT8_C(  53), -INT8_C(  87),  INT8_C(   6), -INT8_C(  61), -INT8_C(  95), -INT8_C(  10), -INT8_C( 117),
             INT8_C(  15),  INT8_C(  75), -INT8_C(   3), -INT8_C(  17), -INT8_C(  52),  INT8_C( 124),  INT8_C(  75), -INT8_C(  56) },
          { -INT8_C(  97),  INT8_C(  10), -INT8_C(  52),  INT8_C(  26), -INT8_C(  88), -INT8_C(  93), -INT8_C(  40),  INT8_C(  80),
             INT8_C(  76),  INT8_C(  67),  INT8_C(  96), -INT8_C(  97), -INT8_C( 123), -INT8_C(  51), -INT8_C(  97), -INT8_C( 111) },
          { -INT8_C( 104),  INT8_C(  73), -INT8_C( 105),  INT8_C(  92), -INT8_C(  22), -INT8_C( 114), -INT8_C(  25), -INT8_C(   7),
            -INT8_C(  39), -INT8_C(  28), -INT8_C(  24), -INT8_C(  91),  INT8_C(  97),  INT8_C(  51),  INT8_C( 109),  INT8_C(   0) },
          {  INT8_C(  61),  INT8_C(  57),  INT8_C(  26), -INT8_C(  27), -INT8_C(  36), -INT8_C(  14),  INT8_C(  53),  INT8_C(  41),
             INT8_C(  54), -INT8_C( 106), -INT8_C(  56), -INT8_C(  69),  INT8_C(  99),  INT8_C( 103),  INT8_C(  76), -INT8_C(   4) } },
      { UINT8_C( 48), UINT8_C( 36), UINT8_C( 24), UINT8_C( 26), UINT8_C(114), UINT8_C( 63), UINT8_C( 20), UINT8_C( 11) },
      {  INT8_C(  61), -INT8_C(  22),  INT8_C(  76),  INT8_C(  96),  INT8_C(   0), -INT8_C(   4), -INT8_C(  88), -INT8_C(  17) } },
    {
        { { -INT8_C( 105), -INT8_C(  98), -INT8_C(  45),  INT8_C( 115), -INT8_C( 111),  INT8_C(   8), -INT8_C( 100), -INT8_C(  57),
            -INT8_C(  98),  INT8_C( 100), -INT8_C( 126),  INT8_C(   2), -INT8_C(  52), -INT8_C(  49), -INT8_C(   2),  INT8_C( 124) },
          { -INT8_C(  77),  INT8_C(  86),  INT8_C(  23),  INT8_C(  37), -INT8_C( 107), -INT8_C(  85),  INT8_C( 112), -INT8_C(  72),
             INT8_C(  39),  INT8_C(  96),  INT8_C(  61), -INT8_C(  41), -INT8_C(  67), -INT8_C(  63), -INT8_C(  59),  INT8_C(  84) },
          {  INT8_C(  96), -INT8_C( 104), -INT8_C(  56), -INT8_C(  15), -INT8_C(  96),  INT8_C( 100), -INT8_C(  72),  INT8_C(  63),
            -INT8_C(  55),  INT8_C(  58),  INT8_C(  65), -INT8_C( 107),  INT8_C(   9),  INT8_C(  63),  INT8_C(  17), -INT8_C(  68) },
          { -INT8_C( 107),  INT8_C(  40), -INT8_C(  31),  INT8_C(  42), -INT8_C(  45),  INT8_C(  81), -INT8_C(  30), -INT8_C(   5),
            -INT8_C(  79),  INT8_C(  31), -INT8_C(  46),  INT8_C( 111), -INT8_C(  31), -INT8_C( 105), -INT8_C(  61),  INT8_C(  65) } },
      { UINT8_C( 47), UINT8_C(139), UINT8_C( 50), UINT8_C( 16), UINT8_C( 48), UINT8_C( 42), UINT8_C( 15), UINT8_C( 57) },
      { -INT8_C(  68),  INT8_C(   0), -INT8_C(  31), -INT8_C(  77), -INT8_C( 107),  INT8_C(  65),  INT8_C( 124),  INT8_C(  31) } },
    {
        { { -INT8_C( 120), -INT8_C(  52),  INT8_C(  78),  INT8_C(  91),  INT8_C(  29),  INT8_C(  48),  INT8_C(  86), -INT8_C(  49),
             INT8_C(  80),  INT8_C(  41),  INT8_C(  62),  INT8_C(  49), -INT8_C(  64),  INT8_C(   1),  INT8_C( 114), -INT8_C(  16) },
          { -INT8_C( 115), -INT8_C(  92), -INT8_C(  64),  INT8_C( 125), -INT8_C( 114), -INT8_C(  49),  INT8_C(  54), -INT8_C(  78),
             INT8_C(  31), -INT8_C( 124), -INT8_C(  32), -INT8_C(  82), -INT8_C(  29), -INT8_C(  53), -INT8_C(  46),  INT8_C( 107) },
          { -INT8_C( 105),  INT8_C(  32), -INT8_C(  57), -INT8_C(  76),  INT8_C(  80),  INT8_C(  29), -INT8_C( 125), -INT8_C(  96),
             INT8_C(  70), -INT8_C(  63), -INT8_C(  47),  INT8_C(   7), -INT8_C(  61),  INT8_C(  67), -INT8_C(   9),  INT8_C(  80) },
          { -INT8_C(  25), -INT8_C(  73), -INT8_C(  51),  INT8_C( 117), -INT8_C( 122),  INT8_C(   3),  INT8_C(  40), -INT8_C(  91),
            -INT8_C( 121),  INT8_C(   8),  INT8_C(  83),  INT8_C( 106), -INT8_C(  45),  INT8_C(  37), -INT8_C(  42),  INT8_C( 106) } },
      { UINT8_C(  5), UINT8_C( 29), UINT8_C( 31), UINT8_C( 21), UINT8_C( 58), UINT8_C( 34), UINT8_C( 54), UINT8_C(  1) },
      {  INT8_C(  48), -INT8_C(  53),  INT8_C( 107), -INT8_C(  49),  INT8_C(  83), -INT8_C(  57),  INT8_C(  40), -INT8_C(  52) } },
    {
        { { -INT8_C(  74),  INT8_C(  68), -INT8_C(  88),  INT8_C(  60),  INT8_C(  71), -INT8_C(  48), -INT8_C(  31), -INT8_C(  50),
            -INT8_C(  40),  INT8_C(  52),  INT8_C(  56), -INT8_C(  84),  INT8_C(  89),  INT8_C(  14),  INT8_C(  22), -INT8_C(  98) },
          { -INT8_C(  85),  INT8_C(  53),  INT8_C(  51),  INT8_C( 102), -INT8_C(  40),  INT8_C( 105),  INT8_C( 103),  INT8_C(  60),
             INT8_C( 113),  INT8_C( 111),  INT8_C(  99), -INT8_C(  68),  INT8_C( 110), -INT8_C(  38), -INT8_C(  18),  INT8_C(  36) },
          {  INT8_C(  30), -INT8_C( 106),  INT8_C(  96),  INT8_C( 101),  INT8_C( 102),  INT8_C(  65),  INT8_C(  51),  INT8_C(  63),
             INT8_C( 117),  INT8_C( 107), -INT8_C(  21), -INT8_C(  50),  INT8_C( 122),  INT8_C(   1),  INT8_C( 108),  INT8_C(  37) },
          {  INT8_C(  55), -INT8_C(  97), -INT8_C( 117),  INT8_C(  15),  INT8_C(   9), -INT8_C(  14),  INT8_C(  75),  INT8_C( 122),
             INT8_C(  97), -INT8_C(  82),  INT8_C(  54), -INT8_C(  49), -INT8_C( 120),  INT8_C(  36), -INT8_C(  13), -INT8_C(  90) } },
      { UINT8_C( 59), UINT8_C( 19), UINT8_C( 11), UINT8_C( 33), UINT8_C( 20), UINT8_C( 62), UINT8_C( 32), UINT8_C(  9) },
      { -INT8_C(  49),  INT8_C( 102), -INT8_C(  84), -INT8_C( 106), -INT8_C(  40), -INT8_C(  13),  INT8_C(  30),  INT8_C(  52) } },
    {
        { { -INT8_C(  29), -INT8_C(  44), -INT8_C( 109), -INT8_C(  20), -INT8_C(  57), -INT8_C(  34),  INT8_C( 102),  INT8_C(  40),
            -INT8_C( 116), -INT8_C( 100), -INT8_C(   8),  INT8_C(  20), -INT8_C(  64), -INT8_C(  21), -INT8_C(  70),  INT8_C( 123) },
          {  INT8_C(  63), -INT8_C(  59), -INT8_C(  99), -INT8_C(  45),  INT8_C(   3), -INT8_C(   3), -INT8_C(  35), -INT8_C(  84),
             INT8_C(  73), -INT8_C(  76), -INT8_C(  48), -INT8_C( 106), -INT8_C(   8),  INT8_C(  25),  INT8_C(  26), -INT8_C(  37) },
          { -INT8_C(  19), -INT8_C(  83), -INT8_C(  57), -INT8_C(  76), -INT8_C( 117),  INT8_C(  45), -INT8_C(  35),  INT8_C(  23),
            -INT8_C(  55), -INT8_C(  43),  INT8_C(  43), -INT8_C( 119), -INT8_C(  64), -INT8_C(  27),  INT8_C(   5), -INT8_C(   1) },
          { -INT8_C(  86), -INT8_C(  94), -INT8_C(  45), -INT8_C(  83), -INT8_C(  97), -INT8_C(  80),  INT8_C(  89), -INT8_C(  24),
             INT8_C( 100),  INT8_C(  41),  INT8_C( 126),  INT8_C(  92),  INT8_C(  66), -INT8_C( 104),  INT8_C(  55),  INT8_C(  48) } },
      { UINT8_C(  5), UINT8_C(254), UINT8_C( 36), UINT8_C( 16), UINT8_C( 43), UINT8_C(  1), UINT8_C( 39), UINT8_C( 52) },
      { -INT8_C(  34),  INT8_C(   0), -INT8_C( 117),  INT8_C(  63), -INT8_C( 119), -INT8_C(  44),  INT8_C(  23), -INT8_C(  97) } },
    {
        { {  INT8_C(  37),  INT8_C(  41),  INT8_C(  78), -INT8_C(  60), -INT8_C(  39), -INT8_C(  88), -INT8_C(  83),  INT8_C(  62),
            -INT8_C(  47),  INT8_C(  43), -INT8_C( 102),  INT8_C(  20), -INT8_C(  60), -INT8_C(  46),  INT8_C(  68),  INT8_C(   9) },
          { -INT8_C(  48),  INT8_C(  40), -INT8_C(  38), -INT8_C(   4), -INT8_C(  22), -INT8_C(  63), -INT8_C(  16),      INT8_MIN,
            -INT8_C(  44),  INT8_C( 110), -INT8_C(  41), -INT8_C(  53), -INT8_C(  15),  INT8_C(  46),  INT8_C( 109),  INT8_C(  22) },
          {  INT8_C(  87), -INT8_C(  69), -INT8_C(  37),  INT8_C(  49),  INT8_C(  99), -INT8_C( 120),  INT8_C( 111),  INT8_C(  53),
            -INT8_C(  77),  INT8_C(   9),  INT8_C(  73),  INT8_C( 119), -INT8_C(  37), -INT8_C( 115), -INT8_C( 127), -INT8_C(  84) },
          { -INT8_C(  75),  INT8_C(  91), -INT8_C(  88), -INT8_C(  97),  INT8_C(  28), -INT8_C( 104),  INT8_C(  32), -INT8_C(  16),
             INT8_C(   7), -INT8_C(   9), -INT8_C(  68), -INT8_C(   8),  INT8_C(  37),  INT8_C(  41),  INT8_C(  15),  INT8_C( 125) } },
      { UINT8_C( 36), UINT8_C( 42), UINT8_C( 46), UINT8_C( 72), UINT8_C( 50), UINT8_C( 29), UINT8_C( 61), UINT8_C( 37) },
      {  INT8_C(  99),  INT8_C(  73), -INT8_C( 127),  INT8_C(   0), -INT8_C(  88),  INT8_C(  46),  INT8_C(  41), -INT8_C( 120) } },
    {
        { {  INT8_C( 121),  INT8_C(  86), -INT8_C(  88), -INT8_C( 107), -INT8_C(  18), -INT8_C(  56), -INT8_C( 122), -INT8_C(  11),
            -INT8_C(  65),  INT8_C(  66), -INT8_C(  18), -INT8_C(  27),  INT8_C( 107), -INT8_C(   3),  INT8_C(  98),  INT8_C(  79) },
          { -INT8_C(  25),  INT8_C(  16), -INT8_C( 105),  INT8_C(  89),  INT8_C(  45),  INT8_C(  20),  INT8_C( 126),  INT8_C(  83),
            -INT8_C(  38),  INT8_C(  27),  INT8_C(  85),  INT8_C(  45),  INT8_C(  57),  INT8_C(   3),  INT8_C(  54), -INT8_C(  78) },
          {  INT8_C(  89), -INT8_C(  34),  INT8_C(  72),  INT8_C(  72), -INT8_C(  90), -INT8_C(  50),  INT8_C(  61),  INT8_C( 101),
             INT8_C(  16),  INT8_C(  43),  INT8_C(  74),  INT8_C( 123),  INT8_C(  40), -INT8_C(  84), -INT8_C(  54),  INT8_C(  15) },
          { -INT8_C(  68),  INT8_C(  98),  INT8_C( 104), -INT8_C(  23),  INT8_C( 118), -INT8_C(  25),  INT8_C(  61),  INT8_C(  81),
             INT8_C(   2), -INT8_C( 110),  INT8_C( 126),  INT8_C(  60), -INT8_C( 106), -INT8_C(  76), -INT8_C(  18), -INT8_C(  17) } },
      { UINT8_C( 18), UINT8_C( 54), UINT8_C( 55), UINT8_C( 56), UINT8_C(  4), UINT8_C( 53), UINT8_C( 30), UINT8_C( 20) },
      { -INT8_C( 105),  INT8_C(  61),  INT8_C(  81),  INT8_C(   2), -INT8_C(  18), -INT8_C(  25),  INT8_C(  54),  INT8_C(  45) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x4_t t;
    simde_uint8x8_t idx = simde_vld1_u8(test_vec[i].idx);
    simde_int8x8_t r;
    t.val[0] = simde_vld1q_s8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_s8(test_vec[i].t[1]);
    t.val[2] = simde_vld1q_s8(test_vec[i].t[2]);
    t.val[3] = simde_vld1q_s8(test_vec[i].t[3]);
    r = simde_vqtbl4_s8(t, idx);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16x4_t t = simde_test_arm_neon_random_i8x16x4();
    simde_uint8x8_private idx_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 63;
      }
    }

    simde_uint8x8_t idx = simde_uint8x8_from_private(idx_);

    simde_int8x8_t r = simde_vqtbl4_s8(t, idx);
    simde_test_arm_neon_write_i8x16x4(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl4_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 uint8_t t[4][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[8];
    SIMDE_ALIGN_TO_16 uint8_t r[8];
  } test_vec[] = {
    {
        { { UINT8_C( 73), UINT8_C(147), UINT8_C( 18), UINT8_C(240), UINT8_C(193), UINT8_C( 95), UINT8_C( 22), UINT8_C(176),
            UINT8_C( 28), UINT8_C( 92), UINT8_C(226), UINT8_C( 93), UINT8_C(217), UINT8_C(166), UINT8_C(186), UINT8_C(146) },
          { UINT8_C( 26), UINT8_C(238), UINT8_C(  0), UINT8_C(185), UINT8_C(120), UINT8_C(178), UINT8_C(101), UINT8_C( 19),
            UINT8_C(  8), UINT8_C( 27), UINT8_C(113), UINT8_C(182), UINT8_C(189), UINT8_C(192), UINT8_C( 36), UINT8_C(  6) },
          { UINT8_C( 84), UINT8_C( 54), UINT8_C(246), UINT8_C( 21), UINT8_C(149), UINT8_C( 12), UINT8_C(197), UINT8_C(177),
            UINT8_C(104), UINT8_C(167), UINT8_C( 14), UINT8_C( 65), UINT8_C( 77), UINT8_C(200), UINT8_C(212), UINT8_C(103) },
          { UINT8_C(182), UINT8_C(212), UINT8_C( 32), UINT8_C( 47), UINT8_C(135), UINT8_C(134), UINT8_C( 66), UINT8_C(143),
            UINT8_C(161), UINT8_C(179), UINT8_C( 70), UINT8_C( 95), UINT8_C(115), UINT8_C(106), UINT8_C(101), UINT8_C(199) } },
      { UINT8_C( 32), UINT8_C( 92), UINT8_C( 28), UINT8_C( 53), UINT8_C( 40), UINT8_C(161), UINT8_C( 38), UINT8_C( 17) },
      { UINT8_C( 84), UINT8_C(  0), UINT8_C(189), UINT8_C(134), UINT8_C(104), UINT8_C(  0), UINT8_C(197), UINT8_C(238) } },
    {
        { { UINT8_C(187), UINT8_C( 30), UINT8_C(162), UINT8_C( 66), UINT8_C(164), UINT8_C(228), UINT8_C(209), UINT8_C( 70),
            UINT8_C(151), UINT8_C( 23), UINT8_C(165), UINT8_C( 10), UINT8_C(129), UINT8_C( 10), UINT8_C(210), UINT8_C( 33) },
          { UINT8_C(102), UINT8_C(174), UINT8_C( 86), UINT8_C(207), UINT8_C( 80), UINT8_C( 60), UINT8_C(160), UINT8_C(153),
            UINT8_C( 48), UINT8_C(178), UINT8_C( 47), UINT8_C(237), UINT8_C(153), UINT8_C( 45), UINT8_C( 96), UINT8_C( 84) },
          { UINT8_C( 76), UINT8_C(  2), UINT8_C(150), UINT8_C(240), UINT8_C(230), UINT8_C(103), UINT8_C( 54), UINT8_C(125),
            UINT8_C(127), UINT8_C(219), UINT8_C(135), UINT8_C(  0), UINT8_C(230), UINT8_C( 89), UINT8_C( 34), UINT8_C( 76) },
          { UINT8_C(  8), UINT8_C(120), UINT8_C( 27), UINT8_C( 88), UINT8_C(181), UINT8_C(187), UINT8_C(241), UINT8_C(229),
            UINT8_C(110), UINT8_C( 32), UINT8_C(210), UINT8_C(  7), UINT8_C( 78), UINT8_C( 50), UINT8_C( 91), UINT8_C(154) } },
      { UINT8_C( 52), UINT8_C( 49), UINT8_C(138), UINT8_C( 26), UINT8_C( 24), UINT8_C(  1), UINT8_C( 23), UINT8_C( 23) },
      { UINT8_C(181), UINT8_C(120), UINT8_C(  0), UINT8_C( 47), UINT8_C( 48), UINT8_C( 30), UINT8_C(153), UINT8_C(153) } },
    {
        { { UINT8_C(114), UINT8_C(234), UINT8_C(216), UINT8_C( 39), UINT8_C(166), UINT8_C(201), UINT8_C( 13), UINT8_C( 20),
            UINT8_C(234), UINT8_C(223), UINT8_C( 27), UINT8_C( 56), UINT8_C( 18), UINT8_C(118), UINT8_C(210), UINT8_C( 70) },
          { UINT8_C(103), UINT8_C( 92), UINT8_C( 97), UINT8_C(191), UINT8_C( 29), UINT8_C(248), UINT8_C(151), UINT8_C(186),
            UINT8_C( 23), UINT8_C(111), UINT8_C( 60), UINT8_C(144), UINT8_C(105), UINT8_C( 11), UINT8_C( 16), UINT8_C(219) },
          { UINT8_C(246), UINT8_C(233), UINT8_C(  3), UINT8_C(156), UINT8_C(178), UINT8_C( 16), UINT8_C(176), UINT8_C(156),
            UINT8_C(239), UINT8_C(203), UINT8_C(212), UINT8_C(  1), UINT8_C( 65), UINT8_C(166), UINT8_C( 72), UINT8_C(168) },
          { UINT8_C(  3), UINT8_C(169), UINT8_C(103), UINT8_C( 32), UINT8_C(161), UINT8_C(254), UINT8_C(218), UINT8_C(185),
            UINT8_C(109), UINT8_C( 23), UINT8_C( 73), UINT8_C(214), UINT8_C( 34), UINT8_C( 89), UINT8_C(178), UINT8_C( 24) } },
      { UINT8_C(  2), UINT8_C( 53), UINT8_C( 52), UINT8_C( 53), UINT8_C(  5), UINT8_C( 36), UINT8_C( 17), UINT8_C( 52) },
      { UINT8_C(216), UINT8_C(254), UINT8_C(161), UINT8_C(254), UINT8_C(201), UINT8_C(178), UINT8_C( 92), UINT8_C(161) } },
    {
        { { UINT8_C(167), UINT8_C(128), UINT8_C( 48), UINT8_C( 72), UINT8_C(126), UINT8_C( 10), UINT8_C(  1), UINT8_C(236),
            UINT8_C( 33), UINT8_C( 74), UINT8_C(194), UINT8_C( 68), UINT8_C(164), UINT8_C(116), UINT8_C( 92), UINT8_C(230) },
          { UINT8_C( 41), UINT8_C( 17), UINT8_C(219), UINT8_C(238), UINT8_C(117), UINT8_C(109), UINT8_C(163), UINT8_C(165),
            UINT8_C(211), UINT8_C( 89), UINT8_C( 21), UINT8_C(223), UINT8_C( 87), UINT8_C( 46), UINT8_C(239), UINT8_C(254) },
          { UINT8_C(174), UINT8_C( 31), UINT8_C( 70), UINT8_C( 44), UINT8_C( 41), UINT8_C( 72), UINT8_C( 24), UINT8_C( 75),
            UINT8_C(146), UINT8_C(219), UINT8_C(143), UINT8_C( 54), UINT8_C( 79), UINT8_C(235), UINT8_C( 29), UINT8_C(121) },
          { UINT8_C(252), UINT8_C(248), UINT8_C(103), UINT8_C(114), UINT8_C(101), UINT8_C( 10), UINT8_C( 23), UINT8_C( 56),
            UINT8_C( 99), UINT8_C( 44), UINT8_C( 24), UINT8_C(186), UINT8_C( 90), UINT8_C(  7), UINT8_C(184), UINT8_C(  8) } },
      { UINT8_C( 38), UINT8_C( 63), UINT8_C( 53), UINT8_C( 79), UINT8_C(  7), UINT8_C( 13), UINT8_C( 26), UINT8_C( 25) },
      { UINT8_C( 24), UINT8_C(  8), UINT8_C( 10), UINT8_C(  0), UINT8_C(236), UINT8_C(116), UINT8_C( 21), UINT8_C( 89) } },
    {
        { { UINT8_C( 37), UINT8_C( 88), UINT8_C(131), UINT8_C(139), UINT8_C( 99), UINT8_C(154), UINT8_C(195), UINT8_C(198),
            UINT8_C(199), UINT8_C(219), UINT8_C(129), UINT8_C( 33), UINT8_C(226), UINT8_C( 57), UINT8_C( 42), UINT8_C(  8) },
          { UINT8_C( 56), UINT8_C( 95), UINT8_C( 88), UINT8_C(127), UINT8_C(172), UINT8_C(242), UINT8_C( 89), UINT8_C(213),
            UINT8_C( 28), UINT8_C(105), UINT8_C( 77), UINT8_C( 49), UINT8_C(150), UINT8_C( 62), UINT8_C( 66), UINT8_C(187) },
          { UINT8_C(150), UINT8_C(198), UINT8_C( 70), UINT8_C(249), UINT8_C( 96), UINT8_C( 10), UINT8_C(192), UINT8_C( 39),
            UINT8_C(229), UINT8_C( 65), UINT8_C( 73), UINT8_C(200), UINT8_C(122), UINT8_C(115), UINT8_C(208), UINT8_C(179) },
          { UINT8_C(210), UINT8_C( 40), UINT8_C( 50), UINT8_C(126), UINT8_C( 27), UINT8_C(139), UINT8_C( 83), UINT8_C( 55),
            UINT8_C(244), UINT8_C(160), UINT8_C(104), UINT8_C(138), UINT8_C(222), UINT8_C(170), UINT8_C( 70), UINT8_C(117) } },
      { UINT8_C( 48), UINT8_C(140), UINT8_C( 46), UINT8_C( 17), UINT8_C( 22), UINT8_C( 46), UINT8_C( 56), UINT8_C( 60) },
      { UINT8_C(210), UINT8_C(  0), UINT8_C(208), UINT8_C( 95), UINT8_C( 89), UINT8_C(208), UINT8_C(244), UINT8_C(222) } },
    {
        { { UINT8_C( 61), UINT8_C(207), UINT8_C(  5), UINT8_C( 88), UINT8_C( 91), UINT8_C( 88), UINT8_C(143), UINT8_C( 79),
            UINT8_C(249), UINT8_C(247), UINT8_C(218), UINT8_C(215), UINT8_C(161), UINT8_C( 32), UINT8_C( 76), UINT8_C( 18) },
          { UINT8_C(172), UINT8_C(187), UINT8_C(227), UINT8_C( 67), UINT8_C(233), UINT8_C(219), UINT8_C(191), UINT8_C( 89),
            UINT8_C( 29), UINT8_C(  3), UINT8_C( 67), UINT8_C(209), UINT8_C( 23), UINT8_C(224), UINT8_C( 88), UINT8_C( 84) },
          { UINT8_C(175), UINT8_C( 93), UINT8_C(172), UINT8_C( 10), UINT8_C(181), UINT8_C( 59), UINT8_C( 90), UINT8_C(174),
            UINT8_C( 50), UINT8_C( 52), UINT8_C(134), UINT8_C(212), UINT8_C( 84), UINT8_C(210), UINT8_C(230), UINT8_C(  0) },
          { UINT8_C(141), UINT8_C(201), UINT8_C( 67), UINT8_C(119), UINT8_C(164), UINT8_C(  2), UINT8_C(208), UINT8_C(193),
            UINT8_C(  5), UINT8_C( 19), UINT8_C(147), UINT8_C( 29), UINT8_C(243), UINT8_C(235), UINT8_C(113), UINT8_C(162) } },
      { UINT8_C(  8), UINT8_C( 30), UINT8_C(173), UINT8_C( 61), UINT8_C( 25), UINT8_C(  7), UINT8_C(172), UINT8_C( 12) },
      { UINT8_C(249), UINT8_C( 88), UINT8_C(  0), UINT8_C(235), UINT8_C(  3), UINT8_C( 79), UINT8_C(  0), UINT8_C(161) } },
    {
        { { UINT8_C( 15), UINT8_C(211), UINT8_C(  9), UINT8_C(179), UINT8_C(213), UINT8_C(217), UINT8_C(117), UINT8_C(219),
            UINT8_C(236), UINT8_C(  8), UINT8_C(248), UINT8_C(223), UINT8_C(243), UINT8_C(105), UINT8_C(129), UINT8_C( 59) },
          { UINT8_C(135), UINT8_C( 46), UINT8_C( 56), UINT8_C(225), UINT8_C( 53), UINT8_C(228), UINT8_C(109), UINT8_C(112),
            UINT8_C( 22), UINT8_C(205),    UINT8_MAX, UINT8_C( 27), UINT8_C( 19), UINT8_C(143), UINT8_C(173), UINT8_C( 34) },
          { UINT8_C( 98), UINT8_C(182), UINT8_C(213), UINT8_C( 55), UINT8_C(143), UINT8_C( 74), UINT8_C( 18), UINT8_C(123),
            UINT8_C( 82), UINT8_C( 10), UINT8_C( 90), UINT8_C( 69), UINT8_C(116), UINT8_C(219), UINT8_C(128), UINT8_C(251) },
          { UINT8_C( 10), UINT8_C(185), UINT8_C(220), UINT8_C( 63), UINT8_C(157), UINT8_C( 73), UINT8_C(176), UINT8_C(180),
            UINT8_C( 22), UINT8_C(175), UINT8_C(207), UINT8_C( 41), UINT8_C( 62), UINT8_C(124), UINT8_C( 75), UINT8_C(160) } },
      { UINT8_C( 50), UINT8_C( 33), UINT8_C( 24), UINT8_C(  1), UINT8_C(107), UINT8_C( 42), UINT8_C( 60), UINT8_C( 62) },
      { UINT8_C(220), UINT8_C(182), UINT8_C( 22), UINT8_C(211), UINT8_C(  0), UINT8_C( 90), UINT8_C( 62), UINT8_C( 75) } },
    {
        { { UINT8_C( 61), UINT8_C( 65), UINT8_C(187), UINT8_C(218), UINT8_C(138), UINT8_C(107), UINT8_C(142), UINT8_C(161),
            UINT8_C( 26), UINT8_C( 93), UINT8_C(202), UINT8_C( 89), UINT8_C(217), UINT8_C( 22), UINT8_C(249), UINT8_C( 11) },
          { UINT8_C( 55), UINT8_C(209), UINT8_C(204), UINT8_C(162), UINT8_C(188), UINT8_C(  8), UINT8_C( 96), UINT8_C(177),
            UINT8_C(158), UINT8_C(100), UINT8_C( 26), UINT8_C( 16), UINT8_C(232), UINT8_C(126), UINT8_C(139), UINT8_C( 37) },
          { UINT8_C(191), UINT8_C( 70),    UINT8_MAX, UINT8_C( 74), UINT8_C(177), UINT8_C(142), UINT8_C(235), UINT8_C(204),
            UINT8_C(235), UINT8_C(181), UINT8_C( 37), UINT8_C(197), UINT8_C(203), UINT8_C( 30), UINT8_C(208), UINT8_C(  2) },
          { UINT8_C(240), UINT8_C(157), UINT8_C(165), UINT8_C(172), UINT8_C(165), UINT8_C(  5), UINT8_C( 93), UINT8_C( 68),
            UINT8_C(105), UINT8_C(119), UINT8_C( 84), UINT8_C( 81), UINT8_C(245), UINT8_C(223), UINT8_C(118), UINT8_C(181) } },
      { UINT8_C( 38), UINT8_C( 54), UINT8_C( 63), UINT8_C(215), UINT8_C(  4), UINT8_C( 42), UINT8_C( 35), UINT8_C(239) },
      { UINT8_C(235), UINT8_C( 93), UINT8_C(181), UINT8_C(  0), UINT8_C(138), UINT8_C( 37), UINT8_C( 74), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x4_t t;
    simde_uint8x8_t idx, r;
    idx = simde_vld1_u8(test_vec[i].idx);
    t.val[0] = simde_vld1q_u8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_u8(test_vec[i].t[1]);
    t.val[2] = simde_vld1q_u8(test_vec[i].t[2]);
    t.val[3] = simde_vld1q_u8(test_vec[i].t[3]);
    r = simde_vqtbl4_u8(t, idx);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16x4_t t = simde_test_arm_neon_random_u8x16x4();
    simde_uint8x8_private idx_ = simde_uint8x8_to_private(simde_test_arm_neon_random_u8x8());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 63;
      }
    }

    simde_uint8x8_t idx = simde_uint8x8_from_private(idx_);

    simde_uint8x8_t r = simde_vqtbl4_u8(t, idx);

    simde_test_arm_neon_write_u8x16x4(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

static int
test_simde_vqtbl1q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 int8_t t[16];
    SIMDE_ALIGN_TO_16 uint8_t idx[16];
    SIMDE_ALIGN_TO_16 int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  37),  INT8_C( 124),  INT8_C(   8), -INT8_C(   5),  INT8_C(  48), -INT8_C(  55), -INT8_C( 105), -INT8_C(   1),
        -INT8_C( 108), -INT8_C( 100), -INT8_C(  70),  INT8_C(  68),  INT8_C(  95),  INT8_C(  72), -INT8_C( 122),  INT8_C(  99) },
      { UINT8_C(  6), UINT8_C(  0), UINT8_C(  9), UINT8_C(  6), UINT8_C(  4), UINT8_C(  2), UINT8_C( 14), UINT8_C( 11),
        UINT8_C(  5), UINT8_C(  2), UINT8_C( 15), UINT8_C( 15), UINT8_C(  0), UINT8_C(171), UINT8_C(  3), UINT8_C(  5) },
      { -INT8_C( 105),  INT8_C(  37), -INT8_C( 100), -INT8_C( 105),  INT8_C(  48),  INT8_C(   8), -INT8_C( 122),  INT8_C(  68),
        -INT8_C(  55),  INT8_C(   8),  INT8_C(  99),  INT8_C(  99),  INT8_C(  37),  INT8_C(   0), -INT8_C(   5), -INT8_C(  55) } },
    { {  INT8_C(  82), -INT8_C( 112), -INT8_C(  57), -INT8_C( 122),  INT8_C(   2),  INT8_C(  54),  INT8_C( 114), -INT8_C( 104),
         INT8_C(   8),  INT8_C(  97),  INT8_C(  39),  INT8_C(  56),  INT8_C(  13), -INT8_C(  86), -INT8_C( 114),  INT8_C(  53) },
      { UINT8_C(  5), UINT8_C( 15), UINT8_C( 13), UINT8_C(137), UINT8_C(  7), UINT8_C(  4), UINT8_C(  1), UINT8_C( 75),
        UINT8_C(  6), UINT8_C( 13), UINT8_C( 14), UINT8_C(  1), UINT8_C( 79), UINT8_C(116), UINT8_C( 50), UINT8_C(  2) },
      {  INT8_C(  54),  INT8_C(  53), -INT8_C(  86),  INT8_C(   0), -INT8_C( 104),  INT8_C(   2), -INT8_C( 112),  INT8_C(   0),
         INT8_C( 114), -INT8_C(  86), -INT8_C( 114), -INT8_C( 112),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  57) } },
    { { -INT8_C(  35), -INT8_C(  53),  INT8_C(  46), -INT8_C(  92), -INT8_C(  81), -INT8_C(  97), -INT8_C(  17), -INT8_C(  90),
         INT8_C(  60),  INT8_C(  29), -INT8_C(   9), -INT8_C( 117), -INT8_C( 111),  INT8_C(  41),  INT8_C(  45), -INT8_C( 106) },
      { UINT8_C(  2), UINT8_C(  6), UINT8_C( 13), UINT8_C(  2), UINT8_C(  0), UINT8_C( 12), UINT8_C(  9), UINT8_C(236),
        UINT8_C(  2), UINT8_C(  9), UINT8_C(  5), UINT8_C(  2), UINT8_C(  7), UINT8_C(  3), UINT8_C(  7), UINT8_C(  4) },
      {  INT8_C(  46), -INT8_C(  17),  INT8_C(  41),  INT8_C(  46), -INT8_C(  35), -INT8_C( 111),  INT8_C(  29),  INT8_C(   0),
         INT8_C(  46),  INT8_C(  29), -INT8_C(  97),  INT8_C(  46), -INT8_C(  90), -INT8_C(  92), -INT8_C(  90), -INT8_C(  81) } },
    { {  INT8_C(  47),  INT8_C(  73), -INT8_C(  24),  INT8_C(  31), -INT8_C( 123),  INT8_C( 114),  INT8_C(  12), -INT8_C( 121),
         INT8_C( 107),  INT8_C(   1), -INT8_C(   7),  INT8_C(  99),  INT8_C(  53),  INT8_C(  16),  INT8_C(  55),  INT8_C(  51) },
      { UINT8_C(  5), UINT8_C(  0), UINT8_C(225), UINT8_C( 57), UINT8_C( 23), UINT8_C(  5), UINT8_C( 89), UINT8_C( 12),
        UINT8_C(  0), UINT8_C(  4), UINT8_C(  2), UINT8_C(  4), UINT8_C( 13), UINT8_C( 14), UINT8_C( 11), UINT8_C( 12) },
      {  INT8_C( 114),  INT8_C(  47),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 114),  INT8_C(   0),  INT8_C(  53),
         INT8_C(  47), -INT8_C( 123), -INT8_C(  24), -INT8_C( 123),  INT8_C(  16),  INT8_C(  55),  INT8_C(  99),  INT8_C(  53) } },
    { { -INT8_C( 101), -INT8_C( 125),  INT8_C(  74), -INT8_C(  77), -INT8_C(  71), -INT8_C(  93),  INT8_C(  79),  INT8_C(  57),
        -INT8_C(  89),  INT8_C(   1),  INT8_C(  46), -INT8_C( 123),  INT8_C(  95), -INT8_C(  71), -INT8_C( 111),  INT8_C(   6) },
      { UINT8_C( 12), UINT8_C( 13), UINT8_C( 50), UINT8_C(  2), UINT8_C(  5), UINT8_C(  5), UINT8_C(  3), UINT8_C( 15),
        UINT8_C(  1), UINT8_C(  7), UINT8_C( 13), UINT8_C( 13), UINT8_C(  2), UINT8_C( 15), UINT8_C( 14), UINT8_C( 14) },
      {  INT8_C(  95), -INT8_C(  71),  INT8_C(   0),  INT8_C(  74), -INT8_C(  93), -INT8_C(  93), -INT8_C(  77),  INT8_C(   6),
        -INT8_C( 125),  INT8_C(  57), -INT8_C(  71), -INT8_C(  71),  INT8_C(  74),  INT8_C(   6), -INT8_C( 111), -INT8_C( 111) } },
    { { -INT8_C(  58),  INT8_C(  56), -INT8_C(  37), -INT8_C(  68),  INT8_C(  29),  INT8_C(  62), -INT8_C(  21), -INT8_C(  82),
         INT8_C(  85), -INT8_C( 120), -INT8_C(   5),  INT8_C(  87), -INT8_C(  56),  INT8_C(  89), -INT8_C(  11), -INT8_C( 117) },
      { UINT8_C(  1), UINT8_C(  6), UINT8_C(  7), UINT8_C( 12), UINT8_C(  6), UINT8_C( 12), UINT8_C( 14), UINT8_C(  7),
        UINT8_C(  0), UINT8_C(  6), UINT8_C(  7), UINT8_C( 12), UINT8_C( 15), UINT8_C( 13), UINT8_C(  5), UINT8_C(  5) },
      {  INT8_C(  56), -INT8_C(  21), -INT8_C(  82), -INT8_C(  56), -INT8_C(  21), -INT8_C(  56), -INT8_C(  11), -INT8_C(  82),
        -INT8_C(  58), -INT8_C(  21), -INT8_C(  82), -INT8_C(  56), -INT8_C( 117),  INT8_C(  89),  INT8_C(  62),  INT8_C(  62) } },
    { {  INT8_C(   7),  INT8_C(  15),  INT8_C(  49), -INT8_C(  19), -INT8_C(  53),  INT8_C( 112),  INT8_C( 117),  INT8_C( 107),
         INT8_C(  38), -INT8_C(   4), -INT8_C(  88), -INT8_C(  27), -INT8_C( 118), -INT8_C(  83),  INT8_C( 106),  INT8_C(  79) },
      { UINT8_C( 14), UINT8_C( 12), UINT8_C(  2), UINT8_C( 12), UINT8_C(  8), UINT8_C(  2), UINT8_C(  0), UINT8_C( 13),
        UINT8_C( 14), UINT8_C( 11), UINT8_C( 10), UINT8_C( 50), UINT8_C( 11), UINT8_C(  2), UINT8_C( 24), UINT8_C(  2) },
      {  INT8_C( 106), -INT8_C( 118),  INT8_C(  49), -INT8_C( 118),  INT8_C(  38),  INT8_C(  49),  INT8_C(   7), -INT8_C(  83),
         INT8_C( 106), -INT8_C(  27), -INT8_C(  88),  INT8_C(   0), -INT8_C(  27),  INT8_C(  49),  INT8_C(   0),  INT8_C(  49) } },
    { { -INT8_C(  37),  INT8_C(  29), -INT8_C(  24), -INT8_C(  77), -INT8_C(  33),  INT8_C(   8),  INT8_C(  65),  INT8_C(  45),
        -INT8_C(  13),  INT8_C(  75),  INT8_C(  96), -INT8_C(  97),  INT8_C(  94),  INT8_C( 120),  INT8_C(  81),      INT8_MAX },
      { UINT8_C(  1), UINT8_C(  1), UINT8_C( 12), UINT8_C( 11), UINT8_C(  6), UINT8_C(  5), UINT8_C( 10), UINT8_C(  8),
        UINT8_C(197), UINT8_C( 15), UINT8_C(  3), UINT8_C(  3), UINT8_C( 14), UINT8_C(158), UINT8_C(175), UINT8_C( 41) },
      {  INT8_C(  29),  INT8_C(  29),  INT8_C(  94), -INT8_C(  97),  INT8_C(  65),  INT8_C(   8),  INT8_C(  96), -INT8_C(  13),
         INT8_C(   0),      INT8_MAX, -INT8_C(  77), -INT8_C(  77),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t t = simde_vld1q_s8(test_vec[i].t);
    simde_uint8x16_t idx = simde_vld1q_u8(test_vec[i].idx);
    simde_int8x16_t r = simde_vqtbl1q_s8(t, idx);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t t = simde_test_arm_neon_random_i8x16();
    simde_uint8x16_private idx_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 15;
      }
    }

    simde_uint8x16_t idx = simde_uint8x16_from_private(idx_);

    simde_int8x16_t r = simde_vqtbl1q_s8(t, idx);
    simde_test_arm_neon_write_i8x16(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl1q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 uint8_t t[16];
    SIMDE_ALIGN_TO_16 uint8_t idx[16];
    SIMDE_ALIGN_TO_16 uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(142), UINT8_C(172), UINT8_C( 12), UINT8_C(116), UINT8_C(168), UINT8_C(225), UINT8_C( 78), UINT8_C( 20),
        UINT8_C( 22), UINT8_C( 25), UINT8_C(166), UINT8_C(198), UINT8_C(  9), UINT8_C(107), UINT8_C(223), UINT8_C(250) },
      { UINT8_C(  6), UINT8_C( 10), UINT8_C(  9), UINT8_C( 11), UINT8_C(204), UINT8_C(  6), UINT8_C(  6), UINT8_C(  0),
        UINT8_C(  2), UINT8_C(  2), UINT8_C(  4), UINT8_C( 12), UINT8_C( 15), UINT8_C( 98), UINT8_C(  8), UINT8_C( 13) },
      { UINT8_C( 78), UINT8_C(166), UINT8_C( 25), UINT8_C(198), UINT8_C(  0), UINT8_C( 78), UINT8_C( 78), UINT8_C(142),
        UINT8_C( 12), UINT8_C( 12), UINT8_C(168), UINT8_C(  9), UINT8_C(250), UINT8_C(  0), UINT8_C( 22), UINT8_C(107) } },
    { { UINT8_C( 76), UINT8_C( 53), UINT8_C( 78), UINT8_C( 24), UINT8_C(155), UINT8_C( 36), UINT8_C(153), UINT8_C( 77),
        UINT8_C(231), UINT8_C(189), UINT8_C(170), UINT8_C(150), UINT8_C( 31), UINT8_C( 34), UINT8_C(211), UINT8_C( 45) },
      { UINT8_C(  6), UINT8_C(  4), UINT8_C(  3), UINT8_C( 12), UINT8_C(  3), UINT8_C( 14), UINT8_C(  8), UINT8_C(155),
        UINT8_C( 15), UINT8_C( 10), UINT8_C( 13), UINT8_C( 12), UINT8_C( 12), UINT8_C(  8), UINT8_C(174), UINT8_C( 56) },
      { UINT8_C(153), UINT8_C(155), UINT8_C( 24), UINT8_C( 31), UINT8_C( 24), UINT8_C(211), UINT8_C(231), UINT8_C(  0),
        UINT8_C( 45), UINT8_C(170), UINT8_C( 34), UINT8_C( 31), UINT8_C( 31), UINT8_C(231), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(245), UINT8_C(214), UINT8_C(117), UINT8_C(120), UINT8_C(132), UINT8_C(254), UINT8_C( 19), UINT8_C(164),
        UINT8_C(200), UINT8_C(208), UINT8_C(160), UINT8_C(180), UINT8_C(169), UINT8_C( 78), UINT8_C(236), UINT8_C(182) },
      { UINT8_C( 11), UINT8_C( 13), UINT8_C( 15), UINT8_C( 12), UINT8_C(  6), UINT8_C( 86), UINT8_C(  4), UINT8_C( 13),
        UINT8_C(  6), UINT8_C(  2), UINT8_C(  2), UINT8_C(  9), UINT8_C(  3), UINT8_C(133), UINT8_C(  2), UINT8_C(  8) },
      { UINT8_C(180), UINT8_C( 78), UINT8_C(182), UINT8_C(169), UINT8_C( 19), UINT8_C(  0), UINT8_C(132), UINT8_C( 78),
        UINT8_C( 19), UINT8_C(117), UINT8_C(117), UINT8_C(208), UINT8_C(120), UINT8_C(  0), UINT8_C(117), UINT8_C(200) } },
    { { UINT8_C( 60), UINT8_C(147), UINT8_C( 41), UINT8_C( 98), UINT8_C(233), UINT8_C(157), UINT8_C( 47), UINT8_C(223),
        UINT8_C(175), UINT8_C(194), UINT8_C(152), UINT8_C( 50), UINT8_C( 71), UINT8_C(186), UINT8_C(170), UINT8_C(162) },
      { UINT8_C( 82), UINT8_C( 10), UINT8_C(  1), UINT8_C(  7), UINT8_C(157), UINT8_C(  5), UINT8_C(  5), UINT8_C(  1),
        UINT8_C(  8), UINT8_C(  8), UINT8_C( 14), UINT8_C( 10), UINT8_C(  7), UINT8_C(  2), UINT8_C( 87), UINT8_C(  3) },
      { UINT8_C(  0), UINT8_C(152), UINT8_C(147), UINT8_C(223), UINT8_C(  0), UINT8_C(157), UINT8_C(157), UINT8_C(147),
        UINT8_C(175), UINT8_C(175), UINT8_C(170), UINT8_C(152), UINT8_C(223), UINT8_C( 41), UINT8_C(  0), UINT8_C( 98) } },
    { { UINT8_C( 66), UINT8_C( 81), UINT8_C( 10), UINT8_C(224), UINT8_C( 86), UINT8_C( 79), UINT8_C( 81), UINT8_C(127),
        UINT8_C(167), UINT8_C( 64), UINT8_C( 25), UINT8_C(254), UINT8_C( 98), UINT8_C(113), UINT8_C(145), UINT8_C( 23) },
      { UINT8_C(241), UINT8_C(135), UINT8_C(  5), UINT8_C( 15), UINT8_C( 12), UINT8_C(  2), UINT8_C( 11), UINT8_C(  3),
        UINT8_C(  8), UINT8_C( 10), UINT8_C(  1), UINT8_C( 25), UINT8_C(130), UINT8_C(  1), UINT8_C( 11), UINT8_C(  5) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C( 79), UINT8_C( 23), UINT8_C( 98), UINT8_C( 10), UINT8_C(254), UINT8_C(224),
        UINT8_C(167), UINT8_C( 25), UINT8_C( 81), UINT8_C(  0), UINT8_C(  0), UINT8_C( 81), UINT8_C(254), UINT8_C( 79) } },
    { { UINT8_C( 83), UINT8_C(100), UINT8_C( 67),    UINT8_MAX, UINT8_C(151), UINT8_C( 30), UINT8_C(146), UINT8_C(223),
        UINT8_C(248), UINT8_C( 83), UINT8_C(248), UINT8_C(123), UINT8_C(228), UINT8_C( 52), UINT8_C( 64), UINT8_C(199) },
      { UINT8_C(  9), UINT8_C(  5), UINT8_C(  0), UINT8_C( 14), UINT8_C( 11), UINT8_C(184), UINT8_C( 11), UINT8_C( 18),
        UINT8_C(  9), UINT8_C(  6), UINT8_C( 10), UINT8_C(204), UINT8_C(  2), UINT8_C( 10), UINT8_C(  0), UINT8_C(  6) },
      { UINT8_C( 83), UINT8_C( 30), UINT8_C( 83), UINT8_C( 64), UINT8_C(123), UINT8_C(  0), UINT8_C(123), UINT8_C(  0),
        UINT8_C( 83), UINT8_C(146), UINT8_C(248), UINT8_C(  0), UINT8_C( 67), UINT8_C(248), UINT8_C( 83), UINT8_C(146) } },
    { { UINT8_C(250), UINT8_C( 55), UINT8_C(233), UINT8_C(213), UINT8_C(239), UINT8_C( 52), UINT8_C(231), UINT8_C(120),
        UINT8_C(186), UINT8_C(146), UINT8_C( 68), UINT8_C( 13), UINT8_C(236), UINT8_C( 68), UINT8_C(179), UINT8_C(170) },
      { UINT8_C(  7), UINT8_C( 88), UINT8_C(  0), UINT8_C(233), UINT8_C(  0), UINT8_C( 53), UINT8_C( 67), UINT8_C( 12),
        UINT8_C(  2), UINT8_C(  8), UINT8_C( 12), UINT8_C(  4), UINT8_C( 45), UINT8_C(  3), UINT8_C( 15), UINT8_C(  7) },
      { UINT8_C(120), UINT8_C(  0), UINT8_C(250), UINT8_C(  0), UINT8_C(250), UINT8_C(  0), UINT8_C(  0), UINT8_C(236),
        UINT8_C(233), UINT8_C(186), UINT8_C(236), UINT8_C(239), UINT8_C(  0), UINT8_C(213), UINT8_C(170), UINT8_C(120) } },
    { { UINT8_C(144), UINT8_C( 12), UINT8_C( 91), UINT8_C( 32), UINT8_C( 65), UINT8_C(158), UINT8_C( 60), UINT8_C(164),
        UINT8_C(182), UINT8_C(200), UINT8_C(104), UINT8_C(227), UINT8_C(139), UINT8_C(  7), UINT8_C( 10), UINT8_C(133) },
      { UINT8_C( 15), UINT8_C(  6), UINT8_C( 14), UINT8_C( 12), UINT8_C( 10), UINT8_C(  0), UINT8_C(  4), UINT8_C(  0),
        UINT8_C(  6), UINT8_C(  8), UINT8_C(  2), UINT8_C(  0), UINT8_C(  0), UINT8_C( 15), UINT8_C(  2), UINT8_C( 16) },
      { UINT8_C(133), UINT8_C( 60), UINT8_C( 10), UINT8_C(139), UINT8_C(104), UINT8_C(144), UINT8_C( 65), UINT8_C(144),
        UINT8_C( 60), UINT8_C(182), UINT8_C( 91), UINT8_C(144), UINT8_C(144), UINT8_C(133), UINT8_C( 91), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t t = simde_vld1q_u8(test_vec[i].t);
    simde_uint8x16_t idx = simde_vld1q_u8(test_vec[i].idx);
    simde_uint8x16_t r = simde_vqtbl1q_u8(t, idx);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t t = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_private idx_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 15;
      }
    }

    simde_uint8x16_t idx = simde_uint8x16_from_private(idx_);

    simde_uint8x16_t r = simde_vqtbl1q_u8(t, idx);

    simde_test_arm_neon_write_u8x16(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vqtbl2q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 int8_t t[2][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[16];
    SIMDE_ALIGN_TO_16 int8_t r[16];
  } test_vec[] = {
    {
        { {  INT8_C(  81),  INT8_C( 103), -INT8_C( 107), -INT8_C( 105),  INT8_C(  49),  INT8_C(  42), -INT8_C(  93), -INT8_C(  31),
             INT8_C(  20), -INT8_C(  36),  INT8_C(  67), -INT8_C(  64),  INT8_C(  40), -INT8_C( 120), -INT8_C( 115),  INT8_C(  32) },
          { -INT8_C(   9),  INT8_C(  92),  INT8_C(  74), -INT8_C(  27),  INT8_C(  94), -INT8_C(   5), -INT8_C(  74),  INT8_C(  49),
             INT8_C( 102), -INT8_C(  67),  INT8_C(   1),  INT8_C( 121),  INT8_C( 125),  INT8_C(   3), -INT8_C( 116), -INT8_C(  50) } },
      { UINT8_C( 11), UINT8_C( 33), UINT8_C(  6), UINT8_C(156), UINT8_C( 12), UINT8_C(  9), UINT8_C(125), UINT8_C( 96),
        UINT8_C(229), UINT8_C(  0), UINT8_C(  0), UINT8_C( 13), UINT8_C(  8), UINT8_C( 13), UINT8_C( 13), UINT8_C(  0) },
      { -INT8_C(  64),  INT8_C(   0), -INT8_C(  93),  INT8_C(   0),  INT8_C(  40), -INT8_C(  36),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  81),  INT8_C(  81), -INT8_C( 120),  INT8_C(  20), -INT8_C( 120), -INT8_C( 120),  INT8_C(  81) } },
    {
        { { -INT8_C(   1),  INT8_C(  74), -INT8_C(  92),  INT8_C(  75),  INT8_C(  83),  INT8_C(  34), -INT8_C(  85),  INT8_C(  56),
            -INT8_C(  30), -INT8_C(  53),  INT8_C(  69),  INT8_C(  43),  INT8_C( 120),  INT8_C( 114),  INT8_C( 107), -INT8_C( 126) },
          { -INT8_C(  23), -INT8_C( 112), -INT8_C(  23),  INT8_C(  92),  INT8_C( 107), -INT8_C( 126),  INT8_C(  53),  INT8_C(   3),
             INT8_C(  28), -INT8_C( 121),  INT8_C(  24), -INT8_C(  71),  INT8_C( 101), -INT8_C(   4), -INT8_C(  62),  INT8_C( 101) } },
      { UINT8_C(  6), UINT8_C(  6), UINT8_C( 16), UINT8_C( 25), UINT8_C(  8), UINT8_C( 28), UINT8_C(209), UINT8_C(107),
        UINT8_C( 39), UINT8_C( 22), UINT8_C( 22), UINT8_C(  0), UINT8_C(136), UINT8_C(  1), UINT8_C( 34), UINT8_C( 18) },
      { -INT8_C(  85), -INT8_C(  85), -INT8_C(  23), -INT8_C( 121), -INT8_C(  30),  INT8_C( 101),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  53),  INT8_C(  53), -INT8_C(   1),  INT8_C(   0),  INT8_C(  74),  INT8_C(   0), -INT8_C(  23) } },
    {
        { { -INT8_C( 117),  INT8_C(   6), -INT8_C(  12),  INT8_C(  20),  INT8_C(  98), -INT8_C(  59),      INT8_MAX, -INT8_C( 118),
            -INT8_C(  36),  INT8_C(  21),  INT8_C(  42),  INT8_C( 100),  INT8_C(  22),  INT8_C(  76), -INT8_C(  42), -INT8_C(  89) },
          {  INT8_C(  87), -INT8_C(  91), -INT8_C(  93), -INT8_C(  27), -INT8_C(  87), -INT8_C(  94), -INT8_C( 114),  INT8_C(  52),
            -INT8_C(  71), -INT8_C(  15),  INT8_C(  37), -INT8_C(  51),  INT8_C(  22),  INT8_C( 123),  INT8_C(  40), -INT8_C(  94) } },
      { UINT8_C(  2), UINT8_C( 28), UINT8_C( 22), UINT8_C(  4), UINT8_C(  1), UINT8_C( 21), UINT8_C(110), UINT8_C( 29),
        UINT8_C( 74), UINT8_C( 24), UINT8_C(  2), UINT8_C( 96), UINT8_C(  4), UINT8_C( 24), UINT8_C(  7), UINT8_C( 28) },
      { -INT8_C(  12),  INT8_C(  22), -INT8_C( 114),  INT8_C(  98),  INT8_C(   6), -INT8_C(  94),  INT8_C(   0),  INT8_C( 123),
         INT8_C(   0), -INT8_C(  71), -INT8_C(  12),  INT8_C(   0),  INT8_C(  98), -INT8_C(  71), -INT8_C( 118),  INT8_C(  22) } },
    {
        { {  INT8_C(  23),  INT8_C(  15), -INT8_C( 126), -INT8_C(   8),  INT8_C(  68), -INT8_C(  15), -INT8_C(  74), -INT8_C( 114),
            -INT8_C( 119), -INT8_C(  40), -INT8_C(  18),  INT8_C( 110), -INT8_C(  48), -INT8_C(  11), -INT8_C(  86),  INT8_C( 110) },
          { -INT8_C(  97), -INT8_C(  53), -INT8_C(  76), -INT8_C(  21),  INT8_C( 122),  INT8_C(  47), -INT8_C(  15),  INT8_C(  27),
            -INT8_C(  48), -INT8_C(  60), -INT8_C(  45), -INT8_C(  20), -INT8_C(  65),  INT8_C(  44), -INT8_C( 118), -INT8_C(  42) } },
      { UINT8_C( 28), UINT8_C( 12), UINT8_C( 14), UINT8_C(  0), UINT8_C( 29), UINT8_C(132), UINT8_C( 15), UINT8_C(  7),
        UINT8_C( 28), UINT8_C(253), UINT8_C( 21), UINT8_C( 13), UINT8_C( 19), UINT8_C(159), UINT8_C( 27), UINT8_C( 18) },
      { -INT8_C(  65), -INT8_C(  48), -INT8_C(  86),  INT8_C(  23),  INT8_C(  44),  INT8_C(   0),  INT8_C( 110), -INT8_C( 114),
        -INT8_C(  65),  INT8_C(   0),  INT8_C(  47), -INT8_C(  11), -INT8_C(  21),  INT8_C(   0), -INT8_C(  20), -INT8_C(  76) } },
    {
        { { -INT8_C(  47), -INT8_C( 106), -INT8_C(  68), -INT8_C(  49),  INT8_C(  27), -INT8_C(  53),  INT8_C(  86),  INT8_C( 119),
            -INT8_C(  56),  INT8_C(  75), -INT8_C(  92), -INT8_C(  69), -INT8_C(  22),  INT8_C(  63),  INT8_C(  78),  INT8_C(  84) },
          { -INT8_C( 113), -INT8_C(  52),  INT8_C(  56),  INT8_C(  14),  INT8_C(  59),  INT8_C(  56),  INT8_C(  93),  INT8_C( 110),
             INT8_C(  11), -INT8_C( 104),  INT8_C(  96),  INT8_C(  11),  INT8_C(  93),  INT8_C(  40),  INT8_C(  70),  INT8_C(  46) } },
      { UINT8_C( 30), UINT8_C(  2), UINT8_C(253), UINT8_C( 25), UINT8_C( 13), UINT8_C( 83), UINT8_C( 17), UINT8_C(150),
        UINT8_C( 30), UINT8_C( 21), UINT8_C( 17), UINT8_C(  8), UINT8_C( 21), UINT8_C(159), UINT8_C( 28), UINT8_C(  4) },
      {  INT8_C(  70), -INT8_C(  68),  INT8_C(   0), -INT8_C( 104),  INT8_C(  63),  INT8_C(   0), -INT8_C(  52),  INT8_C(   0),
         INT8_C(  70),  INT8_C(  56), -INT8_C(  52), -INT8_C(  56),  INT8_C(  56),  INT8_C(   0),  INT8_C(  93),  INT8_C(  27) } },
    {
        { { -INT8_C(  83),  INT8_C(  80),  INT8_C(  52),  INT8_C( 122), -INT8_C(  93), -INT8_C( 123),  INT8_C(  16),  INT8_C(  66),
             INT8_C( 123),  INT8_C(  98), -INT8_C(  54), -INT8_C(  80),  INT8_C(   1), -INT8_C(  89),  INT8_C( 116),  INT8_C( 109) },
          { -INT8_C(  68),  INT8_C(  70),  INT8_C(  19),  INT8_C(   9),  INT8_C( 117),  INT8_C(  40),  INT8_C(  98),  INT8_C(  60),
            -INT8_C( 100), -INT8_C(  58),  INT8_C(  96),  INT8_C(  57),  INT8_C( 113), -INT8_C(  78), -INT8_C( 108),  INT8_C(  30) } },
      { UINT8_C(  2), UINT8_C(  8), UINT8_C(152), UINT8_C(  6), UINT8_C( 14), UINT8_C(  9), UINT8_C(  8), UINT8_C(  9),
        UINT8_C( 11), UINT8_C( 18), UINT8_C( 25), UINT8_C( 12), UINT8_C( 25), UINT8_C( 13), UINT8_C( 25), UINT8_C( 21) },
      {  INT8_C(  52),  INT8_C( 123),  INT8_C(   0),  INT8_C(  16),  INT8_C( 116),  INT8_C(  98),  INT8_C( 123),  INT8_C(  98),
        -INT8_C(  80),  INT8_C(  19), -INT8_C(  58),  INT8_C(   1), -INT8_C(  58), -INT8_C(  89), -INT8_C(  58),  INT8_C(  40) } },
    {
        { { -INT8_C(  25),  INT8_C( 111), -INT8_C(  97),  INT8_C(  53),  INT8_C(  24), -INT8_C( 121), -INT8_C(   2),  INT8_C(  35),
             INT8_C(  57),  INT8_C( 119),  INT8_C(  48), -INT8_C( 109),  INT8_C( 100), -INT8_C(  87), -INT8_C(  88), -INT8_C( 105) },
          {  INT8_C(  54), -INT8_C(  57),  INT8_C(  63), -INT8_C(  21),  INT8_C(  73),  INT8_C(  35),  INT8_C(  61), -INT8_C( 111),
             INT8_C( 103), -INT8_C(  57),  INT8_C(  74),  INT8_C(  93), -INT8_C(  26),  INT8_C(  33),  INT8_C(  86), -INT8_C(  51) } },
      { UINT8_C( 16), UINT8_C( 21), UINT8_C(  2), UINT8_C(169), UINT8_C( 28), UINT8_C(  0), UINT8_C( 12), UINT8_C( 22),
        UINT8_C(119), UINT8_C( 28), UINT8_C(  9), UINT8_C( 27), UINT8_C(  6), UINT8_C(241), UINT8_C( 18), UINT8_C( 28) },
      {  INT8_C(  54),  INT8_C(  35), -INT8_C(  97),  INT8_C(   0), -INT8_C(  26), -INT8_C(  25),  INT8_C( 100),  INT8_C(  61),
         INT8_C(   0), -INT8_C(  26),  INT8_C( 119),  INT8_C(  93), -INT8_C(   2),  INT8_C(   0),  INT8_C(  63), -INT8_C(  26) } },
    {
        { { -INT8_C(  28), -INT8_C( 127),  INT8_C(  55),  INT8_C(  97), -INT8_C( 127),  INT8_C(   4),  INT8_C(  23), -INT8_C(   8),
             INT8_C(   0),  INT8_C(  96), -INT8_C(  45), -INT8_C(  90),  INT8_C(  81),  INT8_C(  69), -INT8_C( 125),  INT8_C(  10) },
          { -INT8_C(  10),  INT8_C(  75),  INT8_C(  12), -INT8_C(  54),  INT8_C(  80), -INT8_C(  97),  INT8_C(   5),  INT8_C(  28),
             INT8_C( 124), -INT8_C(  98), -INT8_C(  49),  INT8_C( 122), -INT8_C( 115),  INT8_C(  78),  INT8_C(   9),  INT8_C( 113) } },
      { UINT8_C( 16), UINT8_C(  0), UINT8_C( 18), UINT8_C( 17), UINT8_C(  4), UINT8_C(  9), UINT8_C( 74), UINT8_C(  5),
        UINT8_C(  9), UINT8_C( 29), UINT8_C( 11), UINT8_C( 27), UINT8_C(  3), UINT8_C( 14), UINT8_C(  5), UINT8_C( 89) },
      { -INT8_C(  10), -INT8_C(  28),  INT8_C(  12),  INT8_C(  75), -INT8_C( 127),  INT8_C(  96),  INT8_C(   0),  INT8_C(   4),
         INT8_C(  96),  INT8_C(  78), -INT8_C(  90),  INT8_C( 122),  INT8_C(  97), -INT8_C( 125),  INT8_C(   4),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x2_t t;
    simde_uint8x16_t idx = simde_vld1q_u8(test_vec[i].idx);
    simde_int8x16_t r;
    t.val[0] = simde_vld1q_s8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_s8(test_vec[i].t[1]);
    r = simde_vqtbl2q_s8(t, idx);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16x2_t t = simde_test_arm_neon_random_i8x16x2();
    simde_uint8x16_private idx_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 31;
      }
    }

    simde_uint8x16_t idx = simde_uint8x16_from_private(idx_);

    simde_int8x16_t r = simde_vqtbl2q_s8(t, idx);
    simde_test_arm_neon_write_i8x16x2(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl2q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 uint8_t t[2][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[16];
    SIMDE_ALIGN_TO_16 uint8_t r[16];
  } test_vec[] = {
    {
        { { UINT8_C(113), UINT8_C(145), UINT8_C(199), UINT8_C( 23), UINT8_C(246), UINT8_C(139), UINT8_C(165), UINT8_C(240),
            UINT8_C( 96), UINT8_C( 24), UINT8_C(242), UINT8_C(168), UINT8_C(193), UINT8_C( 50), UINT8_C( 37), UINT8_C(142) },
          { UINT8_C(247), UINT8_C(182), UINT8_C(243), UINT8_C( 26), UINT8_C(212), UINT8_C(212), UINT8_C(185), UINT8_C( 89),
            UINT8_C( 97), UINT8_C(225), UINT8_C(162), UINT8_C(157), UINT8_C( 32), UINT8_C( 50), UINT8_C(223), UINT8_C(145) } },
      { UINT8_C(  3), UINT8_C(  6), UINT8_C(169), UINT8_C( 25), UINT8_C( 18), UINT8_C( 14), UINT8_C(169), UINT8_C( 18),
        UINT8_C(  6), UINT8_C( 27), UINT8_C( 26), UINT8_C(  8), UINT8_C( 13), UINT8_C(  0), UINT8_C( 22), UINT8_C(196) },
      { UINT8_C( 23), UINT8_C(165), UINT8_C(  0), UINT8_C(225), UINT8_C(243), UINT8_C( 37), UINT8_C(  0), UINT8_C(243),
        UINT8_C(165), UINT8_C(157), UINT8_C(162), UINT8_C( 96), UINT8_C( 50), UINT8_C(113), UINT8_C(185), UINT8_C(  0) } },
    {
        { { UINT8_C(  2), UINT8_C(212), UINT8_C(147), UINT8_C( 52), UINT8_C( 34), UINT8_C( 60), UINT8_C(199), UINT8_C(137),
            UINT8_C(216), UINT8_C(  1), UINT8_C(177), UINT8_C(165), UINT8_C( 97), UINT8_C(103), UINT8_C(106), UINT8_C(120) },
          { UINT8_C( 17), UINT8_C( 72), UINT8_C( 98), UINT8_C(144), UINT8_C(224), UINT8_C(166), UINT8_C(111), UINT8_C( 89),
            UINT8_C(139), UINT8_C(236), UINT8_C(242), UINT8_C(163), UINT8_C( 72), UINT8_C( 29), UINT8_C(125), UINT8_C( 75) } },
      { UINT8_C( 17), UINT8_C( 17), UINT8_C( 31), UINT8_C( 20), UINT8_C( 13), UINT8_C( 70), UINT8_C( 29), UINT8_C(  5),
        UINT8_C(  8), UINT8_C( 14), UINT8_C( 11), UINT8_C(  9), UINT8_C( 21), UINT8_C( 53), UINT8_C(  1), UINT8_C(  7) },
      { UINT8_C( 72), UINT8_C( 72), UINT8_C( 75), UINT8_C(224), UINT8_C(103), UINT8_C(  0), UINT8_C( 29), UINT8_C( 60),
        UINT8_C(216), UINT8_C(106), UINT8_C(165), UINT8_C(  1), UINT8_C(166), UINT8_C(  0), UINT8_C(212), UINT8_C(137) } },
    {
        { { UINT8_C(231), UINT8_C(198), UINT8_C(204), UINT8_C( 52), UINT8_C( 12), UINT8_C(105), UINT8_C( 90), UINT8_C( 84),
            UINT8_C(183), UINT8_C( 37), UINT8_C(254), UINT8_C(108), UINT8_C( 90), UINT8_C( 31), UINT8_C( 51), UINT8_C(215) },
          { UINT8_C(163), UINT8_C(138), UINT8_C( 53), UINT8_C(205), UINT8_C( 81), UINT8_C(235), UINT8_C(131), UINT8_C(  4),
            UINT8_C(148), UINT8_C(219),    UINT8_MAX, UINT8_C( 91), UINT8_C(177), UINT8_C( 70), UINT8_C( 19), UINT8_C(152) } },
      { UINT8_C( 12), UINT8_C( 31), UINT8_C( 13), UINT8_C( 24), UINT8_C(  8), UINT8_C( 39), UINT8_C(109), UINT8_C( 31),
        UINT8_C( 12), UINT8_C(107), UINT8_C( 11), UINT8_C(  6), UINT8_C(138), UINT8_C( 31), UINT8_C( 29), UINT8_C( 14) },
      { UINT8_C( 90), UINT8_C(152), UINT8_C( 31), UINT8_C(148), UINT8_C(183), UINT8_C(  0), UINT8_C(  0), UINT8_C(152),
        UINT8_C( 90), UINT8_C(  0), UINT8_C(108), UINT8_C( 90), UINT8_C(  0), UINT8_C(152), UINT8_C( 70), UINT8_C( 51) } },
    {
        { { UINT8_C(127), UINT8_C(113), UINT8_C(232), UINT8_C(199), UINT8_C(152), UINT8_C( 85), UINT8_C(198), UINT8_C(228),
            UINT8_C(192), UINT8_C( 50), UINT8_C(138), UINT8_C( 75), UINT8_C(209), UINT8_C(  7), UINT8_C(121), UINT8_C(250) },
          { UINT8_C(186), UINT8_C(116), UINT8_C(117), UINT8_C( 88), UINT8_C(243), UINT8_C(243), UINT8_C(138), UINT8_C( 77),
            UINT8_C(113), UINT8_C( 24), UINT8_C( 88), UINT8_C( 53), UINT8_C(184), UINT8_C(252), UINT8_C(  5), UINT8_C( 56) } },
      { UINT8_C(109), UINT8_C( 14), UINT8_C( 31), UINT8_C(  5), UINT8_C( 67), UINT8_C(  6), UINT8_C(  9), UINT8_C(  4),
        UINT8_C( 24), UINT8_C(115), UINT8_C( 15), UINT8_C(  9), UINT8_C( 27), UINT8_C(  8), UINT8_C(  3), UINT8_C( 21) },
      { UINT8_C(  0), UINT8_C(121), UINT8_C( 56), UINT8_C( 85), UINT8_C(  0), UINT8_C(198), UINT8_C( 50), UINT8_C(152),
        UINT8_C(113), UINT8_C(  0), UINT8_C(250), UINT8_C( 50), UINT8_C( 53), UINT8_C(192), UINT8_C(199), UINT8_C(243) } },
    {
        { { UINT8_C(198), UINT8_C( 31), UINT8_C( 68), UINT8_C( 10), UINT8_C(229), UINT8_C( 46), UINT8_C( 14), UINT8_C(221),
            UINT8_C(161), UINT8_C( 93), UINT8_C(166), UINT8_C( 28), UINT8_C( 37), UINT8_C(106), UINT8_C( 81), UINT8_C( 97) },
          { UINT8_C(162), UINT8_C(222), UINT8_C(145), UINT8_C(206), UINT8_C(246), UINT8_C( 13), UINT8_C(108), UINT8_C( 37),
            UINT8_C(226), UINT8_C( 63), UINT8_C( 13), UINT8_C(180), UINT8_C( 23), UINT8_C( 45), UINT8_C(243), UINT8_C(222) } },
      { UINT8_C( 13), UINT8_C( 23), UINT8_C(  8), UINT8_C( 18), UINT8_C(  5), UINT8_C( 22), UINT8_C( 16), UINT8_C(  7),
        UINT8_C( 19), UINT8_C(182), UINT8_C(  3), UINT8_C( 24), UINT8_C(  0), UINT8_C( 21), UINT8_C( 25), UINT8_C(  3) },
      { UINT8_C(106), UINT8_C( 37), UINT8_C(161), UINT8_C(145), UINT8_C( 46), UINT8_C(108), UINT8_C(162), UINT8_C(221),
        UINT8_C(206), UINT8_C(  0), UINT8_C( 10), UINT8_C(226), UINT8_C(198), UINT8_C( 13), UINT8_C( 63), UINT8_C( 10) } },
    {
        { { UINT8_C( 57), UINT8_C( 26), UINT8_C( 41), UINT8_C(158), UINT8_C( 16), UINT8_C( 57), UINT8_C(165), UINT8_C( 99),
            UINT8_C(240), UINT8_C(201), UINT8_C(219), UINT8_C( 16), UINT8_C( 62), UINT8_C(180), UINT8_C(211), UINT8_C(145) },
          { UINT8_C( 31), UINT8_C(101), UINT8_C(219), UINT8_C(151), UINT8_C( 98), UINT8_C( 74), UINT8_C(241), UINT8_C(159),
            UINT8_C(198), UINT8_C(  0), UINT8_C(243), UINT8_C(112), UINT8_C(  1), UINT8_C( 37), UINT8_C(103), UINT8_C( 58) } },
      { UINT8_C( 31), UINT8_C( 17), UINT8_C(217), UINT8_C( 79), UINT8_C(202), UINT8_C( 30), UINT8_C( 18), UINT8_C( 26),
        UINT8_C(  7), UINT8_C( 13), UINT8_C( 11), UINT8_C(  5), UINT8_C(  1), UINT8_C( 30), UINT8_C( 23), UINT8_C(  0) },
      { UINT8_C( 58), UINT8_C(101), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(103), UINT8_C(219), UINT8_C(243),
        UINT8_C( 99), UINT8_C(180), UINT8_C( 16), UINT8_C( 57), UINT8_C( 26), UINT8_C(103), UINT8_C(159), UINT8_C( 57) } },
    {
        { { UINT8_C(107), UINT8_C(254), UINT8_C(171), UINT8_C( 54), UINT8_C(124), UINT8_C( 93), UINT8_C(240), UINT8_C(196),
            UINT8_C(234), UINT8_C(187), UINT8_C( 73), UINT8_C( 43), UINT8_C( 90), UINT8_C( 96), UINT8_C(140), UINT8_C( 93) },
          { UINT8_C( 82), UINT8_C(131), UINT8_C(195), UINT8_C(142), UINT8_C(108), UINT8_C(200), UINT8_C(145), UINT8_C( 85),
            UINT8_C(192), UINT8_C(  4), UINT8_C( 64), UINT8_C(221), UINT8_C(222), UINT8_C(101), UINT8_C( 57), UINT8_C( 74) } },
      { UINT8_C( 99), UINT8_C(  4), UINT8_C(  0), UINT8_C( 31), UINT8_C(  1), UINT8_C( 16), UINT8_C(163), UINT8_C( 43),
        UINT8_C( 12), UINT8_C( 13), UINT8_C( 23), UINT8_C(  6), UINT8_C( 13), UINT8_C(  3), UINT8_C(  3), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(124), UINT8_C(107), UINT8_C( 74), UINT8_C(254), UINT8_C( 82), UINT8_C(  0), UINT8_C(  0),
        UINT8_C( 90), UINT8_C( 96), UINT8_C( 85), UINT8_C(240), UINT8_C( 96), UINT8_C( 54), UINT8_C( 54), UINT8_C(107) } },
    {
        { { UINT8_C( 43), UINT8_C(108), UINT8_C( 16), UINT8_C(109), UINT8_C(220), UINT8_C(179), UINT8_C(152), UINT8_C(  8),
            UINT8_C(160), UINT8_C(239), UINT8_C(142), UINT8_C(238), UINT8_C(210), UINT8_C(114), UINT8_C(142), UINT8_C( 57) },
          { UINT8_C( 25), UINT8_C(188), UINT8_C( 12), UINT8_C(136), UINT8_C(124), UINT8_C( 52), UINT8_C(184), UINT8_C( 63),
            UINT8_C(157), UINT8_C(198), UINT8_C(225), UINT8_C(106), UINT8_C( 13), UINT8_C(205), UINT8_C(155), UINT8_C( 56) } },
      { UINT8_C( 25), UINT8_C( 11), UINT8_C(  5), UINT8_C( 22), UINT8_C( 30), UINT8_C( 62), UINT8_C( 30),    UINT8_MAX,
        UINT8_C( 13), UINT8_C( 13), UINT8_C( 13), UINT8_C(  0), UINT8_C( 31), UINT8_C( 27), UINT8_C( 25), UINT8_C( 24) },
      { UINT8_C(198), UINT8_C(238), UINT8_C(179), UINT8_C(184), UINT8_C(155), UINT8_C(  0), UINT8_C(155), UINT8_C(  0),
        UINT8_C(114), UINT8_C(114), UINT8_C(114), UINT8_C( 43), UINT8_C( 56), UINT8_C(106), UINT8_C(198), UINT8_C(157) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x2_t t;
    simde_uint8x16_t idx, r;
    idx = simde_vld1q_u8(test_vec[i].idx);
    t.val[0] = simde_vld1q_u8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_u8(test_vec[i].t[1]);
    r = simde_vqtbl2q_u8(t, idx);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16x2_t t = simde_test_arm_neon_random_u8x16x2();
    simde_uint8x16_private idx_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 31;
      }
    }

    simde_uint8x16_t idx = simde_uint8x16_from_private(idx_);

    simde_uint8x16_t r = simde_vqtbl2q_u8(t, idx);

    simde_test_arm_neon_write_u8x16x2(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl3q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 int8_t t[3][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[16];
    SIMDE_ALIGN_TO_16 int8_t r[16];
  } test_vec[] = {
    {
        { { -INT8_C( 104), -INT8_C(  29),  INT8_C(  64), -INT8_C( 110), -INT8_C(  17), -INT8_C( 127), -INT8_C(  55), -INT8_C(  27),
             INT8_C(  52), -INT8_C(  16), -INT8_C(   7), -INT8_C(  50),  INT8_C(  73), -INT8_C(  35),  INT8_C(  81),  INT8_C( 116) },
          { -INT8_C( 100), -INT8_C(  87), -INT8_C(  87), -INT8_C( 107), -INT8_C(  88), -INT8_C(  14), -INT8_C( 111), -INT8_C( 109),
             INT8_C(  90), -INT8_C(  62),  INT8_C(  33),  INT8_C( 126),  INT8_C( 114), -INT8_C(  13),  INT8_C( 100),  INT8_C(  10) },
          { -INT8_C(  42), -INT8_C(  92), -INT8_C(  99), -INT8_C(  59),  INT8_C(  37),  INT8_C( 102), -INT8_C(  86),  INT8_C(  90),
             INT8_C(  87), -INT8_C(  92),  INT8_C(  40), -INT8_C(  96), -INT8_C( 127),  INT8_C( 122),  INT8_C(  20),  INT8_C(  29) } },
      { UINT8_C( 35), UINT8_C( 46), UINT8_C( 34), UINT8_C( 11), UINT8_C( 32), UINT8_C( 19), UINT8_C( 94), UINT8_C( 11),
        UINT8_C(  5), UINT8_C( 31), UINT8_C( 41), UINT8_C( 23), UINT8_C( 18), UINT8_C( 45), UINT8_C( 34), UINT8_C( 24) },
      { -INT8_C(  59),  INT8_C(  20), -INT8_C(  99), -INT8_C(  50), -INT8_C(  42), -INT8_C( 107),  INT8_C(   0), -INT8_C(  50),
        -INT8_C( 127),  INT8_C(  10), -INT8_C(  92), -INT8_C( 109), -INT8_C(  87),  INT8_C( 122), -INT8_C(  99),  INT8_C(  90) } },
    {
        { {  INT8_C(  79), -INT8_C(  84), -INT8_C(  93),  INT8_C(   0), -INT8_C(  17),  INT8_C(   1),  INT8_C(  11), -INT8_C(  11),
            -INT8_C( 127), -INT8_C( 108),  INT8_C( 108), -INT8_C(  13), -INT8_C( 127), -INT8_C(  18),  INT8_C(  60),  INT8_C(  19) },
          {  INT8_C(  13),  INT8_C(  74), -INT8_C(  53), -INT8_C( 109),  INT8_C(   2), -INT8_C(  36),  INT8_C( 111),  INT8_C(  95),
             INT8_C(  22), -INT8_C(  20),  INT8_C(  60), -INT8_C(  54),  INT8_C( 126),  INT8_C(  55), -INT8_C(  94), -INT8_C(  51) },
          { -INT8_C(  29),  INT8_C(  69), -INT8_C(  51), -INT8_C(  45),  INT8_C(  70), -INT8_C(  40), -INT8_C(  56), -INT8_C(  57),
             INT8_C( 108),  INT8_C(  52), -INT8_C(  69), -INT8_C(  18),  INT8_C(  35), -INT8_C(   9),  INT8_C(   1),  INT8_C(  48) } },
      { UINT8_C( 17), UINT8_C( 12), UINT8_C(  3), UINT8_C( 19), UINT8_C( 25), UINT8_C(  3), UINT8_C(162), UINT8_C( 47),
        UINT8_C( 31), UINT8_C(223), UINT8_C( 42), UINT8_C( 13), UINT8_C( 22), UINT8_C( 44), UINT8_C( 11), UINT8_C(  9) },
      {  INT8_C(  74), -INT8_C( 127),  INT8_C(   0), -INT8_C( 109), -INT8_C(  20),  INT8_C(   0),  INT8_C(   0),  INT8_C(  48),
        -INT8_C(  51),  INT8_C(   0), -INT8_C(  69), -INT8_C(  18),  INT8_C( 111),  INT8_C(  35), -INT8_C(  13), -INT8_C( 108) } },
    {
        { {  INT8_C(  57), -INT8_C(  32), -INT8_C(  75), -INT8_C(  30),  INT8_C(  19),  INT8_C(  88), -INT8_C(  94),  INT8_C(  50),
             INT8_C(  55),  INT8_C(  44), -INT8_C(  48),  INT8_C(  77),  INT8_C(  88),  INT8_C(  59),  INT8_C(  70), -INT8_C(  55) },
          {  INT8_C( 115),  INT8_C(  19),      INT8_MIN, -INT8_C( 124), -INT8_C(  89), -INT8_C(   1),  INT8_C(   2),  INT8_C( 112),
             INT8_C(  57),  INT8_C( 109),  INT8_C(  92),  INT8_C( 106), -INT8_C(  38),  INT8_C( 121), -INT8_C(  36),  INT8_C(  20) },
          {  INT8_C(  89), -INT8_C( 110), -INT8_C(  10),  INT8_C( 108), -INT8_C(  22), -INT8_C( 104), -INT8_C(  98),  INT8_C(  33),
            -INT8_C(  60),  INT8_C( 110),  INT8_C( 110),  INT8_C(  28), -INT8_C(  87), -INT8_C(  76), -INT8_C(  27),  INT8_C(  29) } },
      { UINT8_C(  7), UINT8_C(  6), UINT8_C(161), UINT8_C( 15), UINT8_C(101), UINT8_C(163), UINT8_C( 31), UINT8_C( 15),
        UINT8_C( 17), UINT8_C( 12), UINT8_C(  9), UINT8_C( 43), UINT8_C( 37), UINT8_C( 38), UINT8_C( 15), UINT8_C( 14) },
      {  INT8_C(  50), -INT8_C(  94),  INT8_C(   0), -INT8_C(  55),  INT8_C(   0),  INT8_C(   0),  INT8_C(  20), -INT8_C(  55),
         INT8_C(  19),  INT8_C(  88),  INT8_C(  44),  INT8_C(  28), -INT8_C( 104), -INT8_C(  98), -INT8_C(  55),  INT8_C(  70) } },
    {
        { { -INT8_C(  69), -INT8_C(  17), -INT8_C(  36),  INT8_C(  32), -INT8_C( 110), -INT8_C(  69), -INT8_C(  65), -INT8_C(  93),
            -INT8_C(   9), -INT8_C(  55), -INT8_C( 113), -INT8_C(  84), -INT8_C(  81), -INT8_C( 114), -INT8_C(  70),  INT8_C(  39) },
          { -INT8_C( 124),  INT8_C(  52), -INT8_C( 119),  INT8_C(  19),  INT8_C(  77),  INT8_C(  12),  INT8_C( 102), -INT8_C(  44),
            -INT8_C(   3), -INT8_C(  43),  INT8_C(   4), -INT8_C(  94),  INT8_C(  42),  INT8_C(  82),  INT8_C(  15), -INT8_C(  27) },
          {  INT8_C(  65), -INT8_C(  21),  INT8_C(   6), -INT8_C(  45), -INT8_C(  89), -INT8_C(  59),  INT8_C( 119), -INT8_C(  98),
            -INT8_C( 114),  INT8_C(   6),  INT8_C(  75),  INT8_C(  61), -INT8_C( 108),  INT8_C(   5),  INT8_C( 100),  INT8_C(  25) } },
      { UINT8_C( 10), UINT8_C(237), UINT8_C( 44), UINT8_C( 39), UINT8_C(  9), UINT8_C(  2), UINT8_C( 43), UINT8_C(246),
        UINT8_C(  7), UINT8_C( 47), UINT8_C(  9), UINT8_C(  2), UINT8_C( 33), UINT8_C( 24), UINT8_C(119), UINT8_C(  2) },
      { -INT8_C( 113),  INT8_C(   0), -INT8_C( 108), -INT8_C(  98), -INT8_C(  55), -INT8_C(  36),  INT8_C(  61),  INT8_C(   0),
        -INT8_C(  93),  INT8_C(  25), -INT8_C(  55), -INT8_C(  36), -INT8_C(  21), -INT8_C(   3),  INT8_C(   0), -INT8_C(  36) } },
    {
        { {  INT8_C(  97),  INT8_C(  28), -INT8_C(  21),  INT8_C(  90), -INT8_C(  82),  INT8_C(  70),  INT8_C(  81),  INT8_C(  22),
            -INT8_C(  91), -INT8_C(  22), -INT8_C(  88),  INT8_C(  87), -INT8_C( 110),  INT8_C(  31),  INT8_C(  73),  INT8_C(  38) },
          { -INT8_C(  99),  INT8_C(  15),  INT8_C(  97), -INT8_C(  32),  INT8_C(  76),  INT8_C(  59), -INT8_C(  79), -INT8_C( 113),
             INT8_C(  95), -INT8_C(  64),  INT8_C( 103), -INT8_C( 119),  INT8_C(  52),  INT8_C(  87), -INT8_C(  19), -INT8_C( 107) },
          {  INT8_C( 116), -INT8_C(  40), -INT8_C(  17),  INT8_C(  34),  INT8_C(  30),  INT8_C(  64),  INT8_C(  56), -INT8_C(  60),
             INT8_C(  42), -INT8_C(  32),  INT8_C(  27), -INT8_C(  67),  INT8_C(   0),  INT8_C( 100), -INT8_C(  29), -INT8_C(  99) } },
      { UINT8_C( 20), UINT8_C( 69), UINT8_C( 29), UINT8_C(  0), UINT8_C( 32), UINT8_C( 46), UINT8_C( 32), UINT8_C( 31),
        UINT8_C( 47), UINT8_C( 39), UINT8_C(105), UINT8_C( 35), UINT8_C( 14), UINT8_C( 38), UINT8_C( 40), UINT8_C( 34) },
      {  INT8_C(  76),  INT8_C(   0),  INT8_C(  87),  INT8_C(  97),  INT8_C( 116), -INT8_C(  29),  INT8_C( 116), -INT8_C( 107),
        -INT8_C(  99), -INT8_C(  60),  INT8_C(   0),  INT8_C(  34),  INT8_C(  73),  INT8_C(  56),  INT8_C(  42), -INT8_C(  17) } },
    {
        { { -INT8_C(   8), -INT8_C(  40), -INT8_C(  59),  INT8_C( 120),  INT8_C(   6),  INT8_C(  21),  INT8_C(  87), -INT8_C(  11),
            -INT8_C(  52), -INT8_C(  64),  INT8_C(  24), -INT8_C(  37),  INT8_C(  23), -INT8_C(  48),  INT8_C(  93),  INT8_C(  70) },
          {  INT8_C( 120),  INT8_C(   2), -INT8_C( 109),  INT8_C(  96), -INT8_C(  32), -INT8_C(  91),  INT8_C( 114), -INT8_C(  98),
            -INT8_C(  47),  INT8_C(  66),  INT8_C(  92),  INT8_C(  98), -INT8_C(  11), -INT8_C(  73),  INT8_C( 103), -INT8_C(  19) },
          { -INT8_C( 113),  INT8_C(  45),  INT8_C( 101), -INT8_C( 107),  INT8_C(  66), -INT8_C(  68), -INT8_C( 117),  INT8_C(  15),
             INT8_C( 125), -INT8_C(  93), -INT8_C(  22), -INT8_C( 108),  INT8_C( 116),  INT8_C(  71), -INT8_C(  38), -INT8_C(  20) } },
      { UINT8_C( 26), UINT8_C( 13), UINT8_C( 28), UINT8_C( 42), UINT8_C( 18), UINT8_C( 46), UINT8_C(  8), UINT8_C(228),
        UINT8_C(  0), UINT8_C( 36), UINT8_C( 22), UINT8_C(  5), UINT8_C(219), UINT8_C( 30), UINT8_C( 34), UINT8_C( 10) },
      {  INT8_C(  92), -INT8_C(  48), -INT8_C(  11), -INT8_C(  22), -INT8_C( 109), -INT8_C(  38), -INT8_C(  52),  INT8_C(   0),
        -INT8_C(   8),  INT8_C(  66),  INT8_C( 114),  INT8_C(  21),  INT8_C(   0),  INT8_C( 103),  INT8_C( 101),  INT8_C(  24) } },
    {
        { {  INT8_C(  92), -INT8_C(  38), -INT8_C(  46),  INT8_C( 111), -INT8_C( 104), -INT8_C( 102),  INT8_C(  83), -INT8_C( 103),
            -INT8_C(  66), -INT8_C( 103), -INT8_C( 114), -INT8_C( 103),  INT8_C(  71),  INT8_C( 113),  INT8_C(   3),  INT8_C(  34) },
          { -INT8_C(  72),  INT8_C(   2),  INT8_C(  64), -INT8_C(  68), -INT8_C( 115),  INT8_C( 108),  INT8_C(  61), -INT8_C(  69),
            -INT8_C( 125),  INT8_C(  82),  INT8_C(  93), -INT8_C(  31),  INT8_C(  65), -INT8_C(  21), -INT8_C( 119), -INT8_C(  98) },
          { -INT8_C(  59),  INT8_C(  91),  INT8_C(  13),  INT8_C(  93), -INT8_C(  11),  INT8_C(  96), -INT8_C(  10), -INT8_C(  77),
            -INT8_C(   7), -INT8_C( 123),  INT8_C(  76),  INT8_C(  65), -INT8_C(  10),  INT8_C(  79),  INT8_C(  99), -INT8_C(  82) } },
      { UINT8_C( 33), UINT8_C( 19), UINT8_C( 11), UINT8_C( 30), UINT8_C( 16), UINT8_C( 24), UINT8_C(153), UINT8_C(  3),
        UINT8_C( 11), UINT8_C(246), UINT8_C( 20), UINT8_C( 12), UINT8_C( 33), UINT8_C( 13), UINT8_C( 26), UINT8_C( 22) },
      {  INT8_C(  91), -INT8_C(  68), -INT8_C( 103), -INT8_C( 119), -INT8_C(  72), -INT8_C( 125),  INT8_C(   0),  INT8_C( 111),
        -INT8_C( 103),  INT8_C(   0), -INT8_C( 115),  INT8_C(  71),  INT8_C(  91),  INT8_C( 113),  INT8_C(  93),  INT8_C(  61) } },
    {
        { { -INT8_C( 119), -INT8_C( 113), -INT8_C(  53), -INT8_C( 103),  INT8_C(  55),  INT8_C( 100),  INT8_C(  44),  INT8_C(  50),
             INT8_C(  91), -INT8_C(  96),  INT8_C( 111),  INT8_C(  60), -INT8_C(  99),  INT8_C(  73), -INT8_C(  29), -INT8_C(  11) },
          {  INT8_C(  49), -INT8_C(  25),  INT8_C(  66),  INT8_C( 120), -INT8_C(  31),  INT8_C(  66), -INT8_C(  71),  INT8_C(  97),
            -INT8_C( 114),  INT8_C(  59), -INT8_C(  42),  INT8_C(  41),  INT8_C(  33), -INT8_C(   6),  INT8_C(  21), -INT8_C(  86) },
          { -INT8_C( 119), -INT8_C(  32),  INT8_C(  67), -INT8_C(  63),  INT8_C(  69),  INT8_C( 111), -INT8_C(  13), -INT8_C(  96),
             INT8_C(  15),  INT8_C(  98), -INT8_C(  36), -INT8_C(  84), -INT8_C(  84), -INT8_C(  65), -INT8_C(  95), -INT8_C(  35) } },
      { UINT8_C( 22), UINT8_C(227), UINT8_C( 85), UINT8_C( 40), UINT8_C( 37), UINT8_C( 15), UINT8_C(233), UINT8_C( 35),
        UINT8_C( 26), UINT8_C( 47), UINT8_C( 28), UINT8_C( 11), UINT8_C( 42), UINT8_C(  1), UINT8_C( 21), UINT8_C( 19) },
      { -INT8_C(  71),  INT8_C(   0),  INT8_C(   0),  INT8_C(  15),  INT8_C( 111), -INT8_C(  11),  INT8_C(   0), -INT8_C(  63),
        -INT8_C(  42), -INT8_C(  35),  INT8_C(  33),  INT8_C(  60), -INT8_C(  36), -INT8_C( 113),  INT8_C(  66),  INT8_C( 120) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x3_t t;
    simde_uint8x16_t idx = simde_vld1q_u8(test_vec[i].idx);
    simde_int8x16_t r;
    t.val[0] = simde_vld1q_s8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_s8(test_vec[i].t[1]);
    t.val[2] = simde_vld1q_s8(test_vec[i].t[2]);
    r = simde_vqtbl3q_s8(t, idx);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16x3_t t = simde_test_arm_neon_random_i8x16x3();
    simde_uint8x16_private idx_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] %= 48;
      }
    }

    simde_uint8x16_t idx = simde_uint8x16_from_private(idx_);

    simde_int8x16_t r = simde_vqtbl3q_s8(t, idx);
    simde_test_arm_neon_write_i8x16x3(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl3q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 uint8_t t[3][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[16];
    SIMDE_ALIGN_TO_16 uint8_t r[16];
  } test_vec[] = {
    {
        { { UINT8_C(183), UINT8_C( 77), UINT8_C(187), UINT8_C(230), UINT8_C( 94), UINT8_C(110), UINT8_C(156), UINT8_C(135),
            UINT8_C(216), UINT8_C(209), UINT8_C(114), UINT8_C(100), UINT8_C( 51), UINT8_C( 27), UINT8_C(104), UINT8_C(194) },
          { UINT8_C( 28), UINT8_C(  9), UINT8_C(138), UINT8_C(222), UINT8_C( 96), UINT8_C(233), UINT8_C(123), UINT8_C( 57),
            UINT8_C(232), UINT8_C(241), UINT8_C( 29), UINT8_C(249), UINT8_C(162), UINT8_C( 81), UINT8_C(115), UINT8_C( 89) },
          { UINT8_C(159), UINT8_C( 46), UINT8_C( 63), UINT8_C(253), UINT8_C(157), UINT8_C(219), UINT8_C(132), UINT8_C(117),
            UINT8_C(172), UINT8_C(247), UINT8_C(218), UINT8_C(223), UINT8_C( 18), UINT8_C( 66), UINT8_C(162), UINT8_C( 46) } },
      { UINT8_C( 27), UINT8_C( 44), UINT8_C( 13), UINT8_C( 27), UINT8_C( 21), UINT8_C( 40), UINT8_C( 37), UINT8_C( 13),
        UINT8_C(121), UINT8_C(  2), UINT8_C(  6), UINT8_C( 27), UINT8_C( 36), UINT8_C( 10), UINT8_C( 20), UINT8_C(243) },
      { UINT8_C(249), UINT8_C( 18), UINT8_C( 27), UINT8_C(249), UINT8_C(233), UINT8_C(172), UINT8_C(219), UINT8_C( 27),
        UINT8_C(  0), UINT8_C(187), UINT8_C(156), UINT8_C(249), UINT8_C(157), UINT8_C(114), UINT8_C( 96), UINT8_C(  0) } },
    {
        { { UINT8_C(232), UINT8_C(186), UINT8_C(189), UINT8_C(254), UINT8_C( 66), UINT8_C(162), UINT8_C(251), UINT8_C(187),
            UINT8_C(165), UINT8_C(242), UINT8_C(215), UINT8_C(249), UINT8_C( 92), UINT8_C( 75), UINT8_C(236), UINT8_C(244) },
          {    UINT8_MAX, UINT8_C(220), UINT8_C( 42), UINT8_C(141), UINT8_C( 81), UINT8_C(213), UINT8_C(200), UINT8_C(189),
            UINT8_C( 90), UINT8_C(226), UINT8_C( 60), UINT8_C( 33), UINT8_C(158), UINT8_C(233), UINT8_C( 51), UINT8_C(134) },
          { UINT8_C(163), UINT8_C(240), UINT8_C(132), UINT8_C(229), UINT8_C(147), UINT8_C(128), UINT8_C(160), UINT8_C( 56),
            UINT8_C(114), UINT8_C(119), UINT8_C( 49), UINT8_C(206), UINT8_C(195), UINT8_C( 29), UINT8_C(194), UINT8_C(194) } },
      { UINT8_C(  9), UINT8_C( 44), UINT8_C( 31), UINT8_C( 27), UINT8_C(  1), UINT8_C( 23), UINT8_C(  8), UINT8_C( 27),
        UINT8_C(  9), UINT8_C( 20), UINT8_C( 12), UINT8_C(  7), UINT8_C( 45), UINT8_C( 15), UINT8_C( 30), UINT8_C(208) },
      { UINT8_C(242), UINT8_C(195), UINT8_C(134), UINT8_C( 33), UINT8_C(186), UINT8_C(189), UINT8_C(165), UINT8_C( 33),
        UINT8_C(242), UINT8_C( 81), UINT8_C( 92), UINT8_C(187), UINT8_C( 29), UINT8_C(244), UINT8_C( 51), UINT8_C(  0) } },
    {
        { { UINT8_C( 17), UINT8_C(162), UINT8_C(189), UINT8_C(211), UINT8_C(185), UINT8_C(198), UINT8_C(238), UINT8_C(179),
            UINT8_C( 10), UINT8_C( 43), UINT8_C( 74), UINT8_C( 56), UINT8_C(154), UINT8_C(104), UINT8_C(  8), UINT8_C(250) },
          { UINT8_C( 11), UINT8_C(190), UINT8_C(237), UINT8_C( 45), UINT8_C( 20), UINT8_C( 24), UINT8_C(194), UINT8_C(225),
            UINT8_C(116), UINT8_C( 36), UINT8_C(114), UINT8_C(237), UINT8_C( 73), UINT8_C(196), UINT8_C( 96), UINT8_C( 91) },
          { UINT8_C(102), UINT8_C( 29), UINT8_C( 46), UINT8_C( 32), UINT8_C(227), UINT8_C( 28), UINT8_C(211), UINT8_C(238),
            UINT8_C( 71), UINT8_C( 29), UINT8_C( 38), UINT8_C(226), UINT8_C(134), UINT8_C( 46), UINT8_C(220), UINT8_C(145) } },
      { UINT8_C( 44), UINT8_C( 10), UINT8_C( 46), UINT8_C(  0), UINT8_C(226), UINT8_C( 32), UINT8_C( 34), UINT8_C( 39),
        UINT8_C(165), UINT8_C( 36), UINT8_C( 20), UINT8_C( 46), UINT8_C( 24), UINT8_C(164), UINT8_C( 25), UINT8_C( 31) },
      { UINT8_C(134), UINT8_C( 74), UINT8_C(220), UINT8_C( 17), UINT8_C(  0), UINT8_C(102), UINT8_C( 46), UINT8_C(238),
        UINT8_C(  0), UINT8_C(227), UINT8_C( 20), UINT8_C(220), UINT8_C(116), UINT8_C(  0), UINT8_C( 36), UINT8_C( 91) } },
    {
        { { UINT8_C(100), UINT8_C(101), UINT8_C(213), UINT8_C( 70), UINT8_C(229), UINT8_C(183), UINT8_C(157), UINT8_C(138),
            UINT8_C( 11), UINT8_C(226), UINT8_C(121), UINT8_C( 35), UINT8_C(134), UINT8_C(194), UINT8_C(162), UINT8_C( 72) },
          { UINT8_C( 58), UINT8_C( 65), UINT8_C(238), UINT8_C(206), UINT8_C(179), UINT8_C(129), UINT8_C(169), UINT8_C( 67),
            UINT8_C( 59), UINT8_C(103), UINT8_C( 88), UINT8_C( 35), UINT8_C(  1),    UINT8_MAX, UINT8_C(247), UINT8_C(101) },
          { UINT8_C(100), UINT8_C(204), UINT8_C(171), UINT8_C( 73), UINT8_C(131), UINT8_C( 73), UINT8_C(212), UINT8_C(142),
            UINT8_C( 43), UINT8_C( 77), UINT8_C(178), UINT8_C(177), UINT8_C( 15), UINT8_C( 84), UINT8_C(250), UINT8_C( 73) } },
      { UINT8_C(  6), UINT8_C( 40), UINT8_C( 23), UINT8_C( 25), UINT8_C(  9), UINT8_C(193), UINT8_C(140), UINT8_C( 20),
        UINT8_C( 40), UINT8_C( 37), UINT8_C(  7), UINT8_C( 41), UINT8_C( 36), UINT8_C( 47), UINT8_C( 46), UINT8_C( 24) },
      { UINT8_C(157), UINT8_C( 43), UINT8_C( 67), UINT8_C(103), UINT8_C(226), UINT8_C(  0), UINT8_C(  0), UINT8_C(179),
        UINT8_C( 43), UINT8_C( 73), UINT8_C(138), UINT8_C( 77), UINT8_C(131), UINT8_C( 73), UINT8_C(250), UINT8_C( 59) } },
    {
        { { UINT8_C( 65), UINT8_C( 35), UINT8_C(131), UINT8_C(170), UINT8_C(228), UINT8_C( 16), UINT8_C( 79), UINT8_C( 12),
            UINT8_C(245), UINT8_C( 22), UINT8_C( 53), UINT8_C(217), UINT8_C(213), UINT8_C(195), UINT8_C( 33), UINT8_C( 97) },
          { UINT8_C(252), UINT8_C(178), UINT8_C(112), UINT8_C(127), UINT8_C( 24), UINT8_C( 13), UINT8_C( 44), UINT8_C(202),
            UINT8_C( 93), UINT8_C(139), UINT8_C(140), UINT8_C(  1), UINT8_C(228), UINT8_C(152), UINT8_C( 59), UINT8_C( 37) },
          { UINT8_C(187), UINT8_C(190), UINT8_C(208), UINT8_C(159), UINT8_C(206), UINT8_C( 31), UINT8_C(171), UINT8_C(195),
            UINT8_C( 53), UINT8_C(224), UINT8_C(156), UINT8_C( 11), UINT8_C(163), UINT8_C(189), UINT8_C(108), UINT8_C(159) } },
      { UINT8_C( 16), UINT8_C( 28), UINT8_C( 30), UINT8_C( 40), UINT8_C( 41), UINT8_C( 27), UINT8_C( 34), UINT8_C( 22),
        UINT8_C( 22), UINT8_C(223), UINT8_C( 23), UINT8_C( 43), UINT8_C(119), UINT8_C( 34), UINT8_C( 32), UINT8_C(  2) },
      { UINT8_C(252), UINT8_C(228), UINT8_C( 59), UINT8_C( 53), UINT8_C(224), UINT8_C(  1), UINT8_C(208), UINT8_C( 44),
        UINT8_C( 44), UINT8_C(  0), UINT8_C(202), UINT8_C( 11), UINT8_C(  0), UINT8_C(208), UINT8_C(187), UINT8_C(131) } },
    {
        { { UINT8_C( 88), UINT8_C(189), UINT8_C( 37), UINT8_C( 65), UINT8_C(  8), UINT8_C(119), UINT8_C(136), UINT8_C(222),
            UINT8_C( 86), UINT8_C(207), UINT8_C(153), UINT8_C(205), UINT8_C( 82), UINT8_C(122),    UINT8_MAX, UINT8_C(147) },
          { UINT8_C( 42), UINT8_C(208), UINT8_C(162), UINT8_C(250), UINT8_C( 76), UINT8_C(117),    UINT8_MAX, UINT8_C(168),
            UINT8_C(229), UINT8_C( 15), UINT8_C(167), UINT8_C( 18), UINT8_C(139), UINT8_C( 70), UINT8_C(175), UINT8_C(227) },
          { UINT8_C(  3), UINT8_C(212), UINT8_C( 36), UINT8_C( 11), UINT8_C( 75), UINT8_C(172), UINT8_C(233), UINT8_C(162),
            UINT8_C(124), UINT8_C(131), UINT8_C(111), UINT8_C(206), UINT8_C(253), UINT8_C(111), UINT8_C( 97), UINT8_C( 39) } },
      { UINT8_C( 63), UINT8_C(  3), UINT8_C( 33), UINT8_C( 44), UINT8_C( 25), UINT8_C( 32), UINT8_C(  4), UINT8_C( 46),
        UINT8_C( 47), UINT8_C( 28), UINT8_C(112), UINT8_C( 42), UINT8_C( 34), UINT8_C( 31), UINT8_C( 13), UINT8_C( 37) },
      { UINT8_C(  0), UINT8_C( 65), UINT8_C(212), UINT8_C(253), UINT8_C( 15), UINT8_C(  3), UINT8_C(  8), UINT8_C( 97),
        UINT8_C( 39), UINT8_C(139), UINT8_C(  0), UINT8_C(111), UINT8_C( 36), UINT8_C(227), UINT8_C(122), UINT8_C(172) } },
    {
        { { UINT8_C( 29), UINT8_C(226), UINT8_C(138), UINT8_C(150), UINT8_C(  3), UINT8_C(191), UINT8_C(244), UINT8_C( 50),
            UINT8_C(155), UINT8_C(100), UINT8_C(237), UINT8_C(189), UINT8_C(131), UINT8_C(138), UINT8_C(226), UINT8_C(118) },
          { UINT8_C( 76), UINT8_C( 18), UINT8_C(180), UINT8_C(187), UINT8_C( 43), UINT8_C(149), UINT8_C(165), UINT8_C(200),
            UINT8_C(229), UINT8_C( 94), UINT8_C( 97), UINT8_C(164), UINT8_C(119), UINT8_C( 34), UINT8_C(162), UINT8_C(148) },
          { UINT8_C(  5), UINT8_C( 45), UINT8_C( 42), UINT8_C(  8), UINT8_C(236), UINT8_C( 30), UINT8_C( 58), UINT8_C(135),
            UINT8_C(130), UINT8_C( 39), UINT8_C( 68), UINT8_C(  5), UINT8_C(178), UINT8_C( 38), UINT8_C(123), UINT8_C(254) } },
      { UINT8_C(  8), UINT8_C(  0), UINT8_C( 41), UINT8_C(  3), UINT8_C(  5), UINT8_C( 47), UINT8_C( 43), UINT8_C( 26),
        UINT8_C( 45), UINT8_C( 45), UINT8_C( 30), UINT8_C(  4), UINT8_C(175), UINT8_C(  0), UINT8_C(  9), UINT8_C(180) },
      { UINT8_C(155), UINT8_C( 29), UINT8_C( 39), UINT8_C(150), UINT8_C(191), UINT8_C(254), UINT8_C(  5), UINT8_C( 97),
        UINT8_C( 38), UINT8_C( 38), UINT8_C(162), UINT8_C(  3), UINT8_C(  0), UINT8_C( 29), UINT8_C(100), UINT8_C(  0) } },
    {
        { { UINT8_C( 69), UINT8_C(136), UINT8_C(150), UINT8_C( 10), UINT8_C(231), UINT8_C(193), UINT8_C(180), UINT8_C(164),
            UINT8_C( 78), UINT8_C(  2), UINT8_C(217), UINT8_C(254), UINT8_C(243), UINT8_C(162), UINT8_C(178), UINT8_C( 16) },
          { UINT8_C(149), UINT8_C(111), UINT8_C( 26), UINT8_C(167), UINT8_C(102), UINT8_C(170), UINT8_C( 60), UINT8_C(132),
            UINT8_C(127), UINT8_C(214), UINT8_C( 85), UINT8_C(121), UINT8_C(235), UINT8_C( 36), UINT8_C(172), UINT8_C( 49) },
          { UINT8_C(172), UINT8_C( 66), UINT8_C( 59), UINT8_C(148), UINT8_C(  3), UINT8_C(240), UINT8_C( 56), UINT8_C( 82),
            UINT8_C(242), UINT8_C( 17), UINT8_C( 80), UINT8_C(229), UINT8_C(179), UINT8_C(  2), UINT8_C(246), UINT8_C( 73) } },
      { UINT8_C( 17), UINT8_C( 16), UINT8_C(  0), UINT8_C( 23), UINT8_C( 42), UINT8_C( 44), UINT8_C( 44), UINT8_C(  9),
        UINT8_C(  2), UINT8_C(177), UINT8_C( 35), UINT8_C(238), UINT8_C( 21), UINT8_C( 47), UINT8_C( 31), UINT8_C( 33) },
      { UINT8_C(111), UINT8_C(149), UINT8_C( 69), UINT8_C(132), UINT8_C( 80), UINT8_C(179), UINT8_C(179), UINT8_C(  2),
        UINT8_C(150), UINT8_C(  0), UINT8_C(148), UINT8_C(  0), UINT8_C(170), UINT8_C( 73), UINT8_C( 49), UINT8_C( 66) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x3_t t;
    simde_uint8x16_t idx, r;
    idx = simde_vld1q_u8(test_vec[i].idx);
    t.val[0] = simde_vld1q_u8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_u8(test_vec[i].t[1]);
    t.val[2] = simde_vld1q_u8(test_vec[i].t[2]);
    r = simde_vqtbl3q_u8(t, idx);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16x3_t t = simde_test_arm_neon_random_u8x16x3();
    simde_uint8x16_private idx_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] %= 48;
      }
    }

    simde_uint8x16_t idx = simde_uint8x16_from_private(idx_);

    simde_uint8x16_t r = simde_vqtbl3q_u8(t, idx);

    simde_test_arm_neon_write_u8x16x3(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl4q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 int8_t t[4][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[16];
    SIMDE_ALIGN_TO_16 int8_t r[16];
  } test_vec[] = {
    {
        { { -INT8_C(  76), -INT8_C( 122),  INT8_C( 105), -INT8_C(  93),  INT8_C(  78),      INT8_MAX, -INT8_C(  98), -INT8_C(  72),
             INT8_C(   8),  INT8_C(  25), -INT8_C(   8), -INT8_C(  74),  INT8_C(  68),  INT8_C(  77),  INT8_C(  64), -INT8_C(  67) },
          {  INT8_C(  25), -INT8_C(  52),  INT8_C(  61), -INT8_C( 107),  INT8_C(  42),  INT8_C(  20), -INT8_C(   6),  INT8_C(  41),
             INT8_C( 112),  INT8_C(  51), -INT8_C( 103), -INT8_C(  34),  INT8_C(  51),  INT8_C(  77),  INT8_C(  28), -INT8_C(  25) },
          { -INT8_C(  44), -INT8_C( 122), -INT8_C( 118),  INT8_C(  34),  INT8_C(   5),  INT8_C(  41), -INT8_C(  37),  INT8_C(  13),
             INT8_C(  66), -INT8_C(  45), -INT8_C(  61), -INT8_C( 122),  INT8_C(  32),  INT8_C(   4),  INT8_C(  68),  INT8_C(  57) },
          { -INT8_C(  48), -INT8_C( 127), -INT8_C(  49), -INT8_C(   6), -INT8_C( 107), -INT8_C(  55),  INT8_C(  36),  INT8_C(   6),
            -INT8_C(   4), -INT8_C(  67), -INT8_C(  28),  INT8_C(  47),  INT8_C(  10),  INT8_C(   1),  INT8_C(  22), -INT8_C(  34) } },
      { UINT8_C(  7), UINT8_C( 33), UINT8_C(  1), UINT8_C( 12), UINT8_C(202), UINT8_C( 28), UINT8_C(153), UINT8_C( 12),
        UINT8_C(175), UINT8_C( 29), UINT8_C( 18), UINT8_C(207), UINT8_C( 33), UINT8_C(214), UINT8_C(  8), UINT8_C( 49) },
      { -INT8_C(  72), -INT8_C( 122), -INT8_C( 122),  INT8_C(  68),  INT8_C(   0),  INT8_C(  51),  INT8_C(   0),  INT8_C(  68),
         INT8_C(   0),  INT8_C(  77),  INT8_C(  61),  INT8_C(   0), -INT8_C( 122),  INT8_C(   0),  INT8_C(   8), -INT8_C( 127) } },
    {
        { { -INT8_C( 124), -INT8_C(  10), -INT8_C(  20),  INT8_C(  78), -INT8_C(  46), -INT8_C( 123),  INT8_C(  90), -INT8_C( 127),
            -INT8_C(  30), -INT8_C(  20),  INT8_C(  80),  INT8_C(  67), -INT8_C(  61),  INT8_C(  89),  INT8_C( 116),  INT8_C(  27) },
          {  INT8_C(  48), -INT8_C(  96),  INT8_C(   8), -INT8_C(  47), -INT8_C(  17), -INT8_C(   4),  INT8_C( 110), -INT8_C(   4),
            -INT8_C(  44),  INT8_C(  58),  INT8_C(  19), -INT8_C(  83),  INT8_C(  29),  INT8_C(   8),  INT8_C(  13), -INT8_C(  95) },
          { -INT8_C(   1), -INT8_C(   7), -INT8_C(  17), -INT8_C(  47),  INT8_C( 126),  INT8_C(  73),  INT8_C(  83),  INT8_C(  97),
             INT8_C(  54), -INT8_C(  93), -INT8_C(  92), -INT8_C(   7), -INT8_C(   4),  INT8_C(  25),  INT8_C(  20),  INT8_C(  45) },
          { -INT8_C(  71),  INT8_C(  28), -INT8_C(   2), -INT8_C(  88),  INT8_C(  24),  INT8_C( 108), -INT8_C(  92), -INT8_C(  20),
            -INT8_C(  90), -INT8_C(  73), -INT8_C( 103), -INT8_C(  60), -INT8_C(  64), -INT8_C(  90),  INT8_C( 101), -INT8_C(  65) } },
      { UINT8_C( 31), UINT8_C( 21), UINT8_C( 16), UINT8_C( 30), UINT8_C( 30), UINT8_C(227), UINT8_C( 63), UINT8_C( 20),
        UINT8_C(  7), UINT8_C( 35), UINT8_C(205), UINT8_C(  3), UINT8_C( 60), UINT8_C( 33), UINT8_C( 48), UINT8_C( 53) },
      { -INT8_C(  95), -INT8_C(   4),  INT8_C(  48),  INT8_C(  13),  INT8_C(  13),  INT8_C(   0), -INT8_C(  65), -INT8_C(  17),
        -INT8_C( 127), -INT8_C(  47),  INT8_C(   0),  INT8_C(  78), -INT8_C(  64), -INT8_C(   7), -INT8_C(  71),  INT8_C( 108) } },
    {
        { {  INT8_C(  63),  INT8_C(   9),  INT8_C(   0), -INT8_C(  34), -INT8_C(  19),      INT8_MAX, -INT8_C(  78),  INT8_C( 116),
            -INT8_C(  93),      INT8_MIN, -INT8_C(   9), -INT8_C(  33),  INT8_C(  97), -INT8_C(  88), -INT8_C(  43),  INT8_C(  95) },
          {  INT8_C(  86),  INT8_C( 115),  INT8_C( 118),  INT8_C( 113), -INT8_C(  75),  INT8_C( 121),  INT8_C(  50), -INT8_C(  81),
             INT8_C(  21), -INT8_C(  73),  INT8_C( 105),  INT8_C(  88), -INT8_C(  95), -INT8_C(  30),  INT8_C(  59), -INT8_C(  31) },
          { -INT8_C(  20),  INT8_C(  59), -INT8_C(  65), -INT8_C(  39), -INT8_C(  69),  INT8_C( 113),  INT8_C(  77),  INT8_C(  94),
            -INT8_C(  15),  INT8_C(  68),  INT8_C(  61),  INT8_C(  83), -INT8_C(  20),  INT8_C(  18), -INT8_C(  78),  INT8_C(  67) },
          { -INT8_C( 123),  INT8_C(  40), -INT8_C(  76),  INT8_C(  59), -INT8_C(  95), -INT8_C(  26), -INT8_C(  22), -INT8_C(  73),
            -INT8_C(  99),  INT8_C(  84),  INT8_C(  15),  INT8_C(  62),  INT8_C(  54),  INT8_C(  74),  INT8_C(  31),  INT8_C(  34) } },
      { UINT8_C(  6), UINT8_C( 30), UINT8_C( 59), UINT8_C( 65), UINT8_C( 80), UINT8_C( 72), UINT8_C( 31), UINT8_C(  1),
        UINT8_C( 13), UINT8_C( 28), UINT8_C( 20), UINT8_C( 57), UINT8_C( 47), UINT8_C(  7), UINT8_C(188), UINT8_C( 52) },
      { -INT8_C(  78),  INT8_C(  59),  INT8_C(  62),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  31),  INT8_C(   9),
        -INT8_C(  88), -INT8_C(  95), -INT8_C(  75),  INT8_C(  84),  INT8_C(  67),  INT8_C( 116),  INT8_C(   0), -INT8_C(  95) } },
    {
        { {  INT8_C(  48),  INT8_C(  66), -INT8_C(  23),      INT8_MIN, -INT8_C( 117), -INT8_C( 120), -INT8_C(  63),  INT8_C(  24),
             INT8_C( 100),  INT8_C(  86), -INT8_C( 111),  INT8_C(  83), -INT8_C(  99),  INT8_C(  78), -INT8_C(  56),  INT8_C(  12) },
          { -INT8_C(  66),  INT8_C( 119),  INT8_C(  29),  INT8_C(  21),  INT8_C(  17), -INT8_C(  27),  INT8_C(   8), -INT8_C(   1),
            -INT8_C(  67),  INT8_C(  58),  INT8_C(  36), -INT8_C(  33), -INT8_C( 116),  INT8_C( 107), -INT8_C( 121), -INT8_C(  68) },
          { -INT8_C(  83),  INT8_C( 112),  INT8_C(  60),  INT8_C(  56), -INT8_C(   8), -INT8_C(   3),  INT8_C(  80),  INT8_C(  92),
             INT8_C(  83), -INT8_C(  30), -INT8_C(  80), -INT8_C(  16),  INT8_C(  48),  INT8_C( 120), -INT8_C(   3), -INT8_C(  18) },
          { -INT8_C(  17),  INT8_C(  26),  INT8_C(   3),  INT8_C(   1),  INT8_C(   0),  INT8_C(  12),  INT8_C(   0), -INT8_C(  67),
             INT8_C(  70),  INT8_C(  36), -INT8_C( 100), -INT8_C(  46), -INT8_C( 113),  INT8_C(  35), -INT8_C( 114),  INT8_C(  61) } },
      { UINT8_C(147), UINT8_C(202), UINT8_C( 53), UINT8_C( 11), UINT8_C(  8), UINT8_C(198), UINT8_C( 39), UINT8_C( 27),
        UINT8_C( 40), UINT8_C( 23), UINT8_C( 12), UINT8_C(216), UINT8_C( 15), UINT8_C(  9), UINT8_C(  6), UINT8_C( 63) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  12),  INT8_C(  83),  INT8_C( 100),  INT8_C(   0),  INT8_C(  92), -INT8_C(  33),
         INT8_C(  83), -INT8_C(   1), -INT8_C(  99),  INT8_C(   0),  INT8_C(  12),  INT8_C(  86), -INT8_C(  63),  INT8_C(  61) } },
    {
        { {  INT8_C(  72),  INT8_C( 103), -INT8_C(  67),  INT8_C(  16),  INT8_C(  45), -INT8_C(  91),  INT8_C(  43), -INT8_C(  43),
             INT8_C(  60),  INT8_C(  55), -INT8_C(  83),  INT8_C(  76),  INT8_C(  64),  INT8_C( 115),  INT8_C(  75),  INT8_C( 100) },
          {  INT8_C(  61),  INT8_C(  75), -INT8_C( 121),  INT8_C(  19),  INT8_C(  75),  INT8_C( 104),  INT8_C(  48),  INT8_C( 112),
            -INT8_C(  28),  INT8_C(  31),  INT8_C(  37), -INT8_C( 124), -INT8_C( 100),  INT8_C(  22), -INT8_C(  74), -INT8_C(  28) },
          {  INT8_C( 125),  INT8_C( 116), -INT8_C(  12), -INT8_C(  86),  INT8_C(  25),  INT8_C(  32),      INT8_MAX,  INT8_C(  85),
             INT8_C(  87),  INT8_C(  44), -INT8_C(  95), -INT8_C( 104), -INT8_C(  96), -INT8_C(  20), -INT8_C(   4), -INT8_C(  35) },
          {  INT8_C(  55), -INT8_C( 125), -INT8_C(  15), -INT8_C( 125), -INT8_C(  21),  INT8_C(  33), -INT8_C(  13), -INT8_C(  48),
             INT8_C(  64),  INT8_C(  24),  INT8_C(  84), -INT8_C(  36),  INT8_C(  47),  INT8_C(  10), -INT8_C(  63), -INT8_C(  84) } },
      { UINT8_C( 62), UINT8_C( 53), UINT8_C( 87), UINT8_C( 23), UINT8_C( 21), UINT8_C( 22), UINT8_C(237), UINT8_C( 45),
        UINT8_C(  3), UINT8_C( 14), UINT8_C(  5), UINT8_C( 35), UINT8_C( 59), UINT8_C(  1), UINT8_C(  0), UINT8_C( 50) },
      { -INT8_C(  63),  INT8_C(  33),  INT8_C(   0),  INT8_C( 112),  INT8_C( 104),  INT8_C(  48),  INT8_C(   0), -INT8_C(  20),
         INT8_C(  16),  INT8_C(  75), -INT8_C(  91), -INT8_C(  86), -INT8_C(  36),  INT8_C( 103),  INT8_C(  72), -INT8_C(  15) } },
    {
        { {  INT8_C(  37),  INT8_C( 116),  INT8_C( 116), -INT8_C(   5),  INT8_C(  74),  INT8_C(  97),  INT8_C(  40),  INT8_C(  77),
            -INT8_C(  16), -INT8_C(  19), -INT8_C(  16),  INT8_C( 107), -INT8_C(  82),  INT8_C( 113),  INT8_C(  29), -INT8_C(  14) },
          { -INT8_C(  30),  INT8_C(  83),  INT8_C(  34),  INT8_C( 117),  INT8_C( 124),  INT8_C(  34),  INT8_C(  71), -INT8_C(  67),
             INT8_C( 118), -INT8_C(  10),  INT8_C(  46), -INT8_C(  43),  INT8_C( 102),  INT8_C(  75), -INT8_C(  78), -INT8_C( 116) },
          { -INT8_C(  65),  INT8_C(  38), -INT8_C( 121),  INT8_C(   9), -INT8_C( 120), -INT8_C(  81),  INT8_C(  87),  INT8_C( 120),
            -INT8_C( 100),  INT8_C(  71), -INT8_C(  29),  INT8_C(  74), -INT8_C(  72),  INT8_C(   0),  INT8_C(  60), -INT8_C( 101) },
          {  INT8_C(  83),  INT8_C(  95),  INT8_C(  16), -INT8_C(  49), -INT8_C( 127),  INT8_C(  87), -INT8_C( 115), -INT8_C(   8),
             INT8_C(  78), -INT8_C(  69), -INT8_C(  51), -INT8_C(  76),  INT8_C(   6),      INT8_MAX,  INT8_C(  64), -INT8_C(  59) } },
      { UINT8_C( 37), UINT8_C(  7), UINT8_C( 14), UINT8_C( 45), UINT8_C( 54), UINT8_C( 37), UINT8_C(165), UINT8_C( 18),
        UINT8_C( 45), UINT8_C(  8), UINT8_C( 92), UINT8_C( 37), UINT8_C(137), UINT8_C(153), UINT8_C(  0), UINT8_C( 28) },
      { -INT8_C(  81),  INT8_C(  77),  INT8_C(  29),  INT8_C(   0), -INT8_C( 115), -INT8_C(  81),  INT8_C(   0),  INT8_C(  34),
         INT8_C(   0), -INT8_C(  16),  INT8_C(   0), -INT8_C(  81),  INT8_C(   0),  INT8_C(   0),  INT8_C(  37),  INT8_C( 102) } },
    {
        { {  INT8_C(  50), -INT8_C( 115), -INT8_C( 112), -INT8_C(  87), -INT8_C(  77),  INT8_C(  54), -INT8_C(  69),  INT8_C(  32),
            -INT8_C(  66),  INT8_C(  24),  INT8_C(  69),  INT8_C(  71), -INT8_C(  79),  INT8_C(   6),  INT8_C(  36), -INT8_C(  87) },
          { -INT8_C(  42), -INT8_C(  48),  INT8_C(  34), -INT8_C(   2),  INT8_C(   9), -INT8_C( 108),  INT8_C( 116), -INT8_C(   3),
            -INT8_C(  46), -INT8_C(  97), -INT8_C(   9), -INT8_C( 112),  INT8_C(  10), -INT8_C(  74), -INT8_C(  13),  INT8_C(  60) },
          {  INT8_C(  67), -INT8_C( 125), -INT8_C(  27), -INT8_C(  10), -INT8_C(  71), -INT8_C(  95),  INT8_C(  22),  INT8_C( 120),
            -INT8_C(  71),  INT8_C(  92), -INT8_C(  65),  INT8_C( 106),  INT8_C(  98), -INT8_C(  29),  INT8_C(  19),  INT8_C(  56) },
          { -INT8_C(  77),  INT8_C(  53),  INT8_C(  55), -INT8_C(  68), -INT8_C(  55), -INT8_C(  85), -INT8_C(  71), -INT8_C( 100),
             INT8_C(  74), -INT8_C(  80),  INT8_C(  44),  INT8_C(  84),  INT8_C( 102),  INT8_C(  31), -INT8_C( 111), -INT8_C(  86) } },
      { UINT8_C( 34), UINT8_C( 54), UINT8_C(160), UINT8_C( 28), UINT8_C( 23), UINT8_C( 55), UINT8_C(212), UINT8_C( 16),
        UINT8_C( 19), UINT8_C( 19), UINT8_C( 58), UINT8_C( 53), UINT8_C( 55), UINT8_C( 13), UINT8_C(173), UINT8_C( 42) },
      { -INT8_C(  27), -INT8_C(  71),  INT8_C(   0),  INT8_C(  10), -INT8_C(   3), -INT8_C( 100),  INT8_C(   0), -INT8_C(  42),
        -INT8_C(   2), -INT8_C(   2),  INT8_C(  44), -INT8_C(  85), -INT8_C( 100),  INT8_C(   6),  INT8_C(   0), -INT8_C(  65) } },
    {
        { {  INT8_C(  54),  INT8_C(   2),  INT8_C(  50),  INT8_C(  78), -INT8_C(  71),  INT8_C(   6),  INT8_C(  30), -INT8_C(  52),
            -INT8_C( 103),  INT8_C(  89),  INT8_C(  65),  INT8_C(  16), -INT8_C(  90), -INT8_C(  18),  INT8_C(  59),  INT8_C(  41) },
          { -INT8_C(  45),  INT8_C(  34),  INT8_C( 118),  INT8_C(  99), -INT8_C(  62),  INT8_C(  94),  INT8_C(  61),  INT8_C(  19),
             INT8_C( 115),  INT8_C( 108), -INT8_C(  53), -INT8_C(  90),  INT8_C(  44),  INT8_C(  44),  INT8_C( 124),  INT8_C(  99) },
          {  INT8_C(  46), -INT8_C(  82), -INT8_C(  79), -INT8_C(  25), -INT8_C(  76), -INT8_C(  49), -INT8_C(  77),  INT8_C(  78),
             INT8_C(  40), -INT8_C(  12),  INT8_C(  94), -INT8_C(  49), -INT8_C(  29), -INT8_C( 103), -INT8_C(   8), -INT8_C(  74) },
          { -INT8_C(  69),  INT8_C( 110),  INT8_C(  25),  INT8_C( 126), -INT8_C(  51),  INT8_C(  86), -INT8_C( 111),  INT8_C(  64),
            -INT8_C(  61),  INT8_C(  92), -INT8_C(  26), -INT8_C(  17), -INT8_C( 119),  INT8_C(  99),  INT8_C(  82), -INT8_C(  73) } },
      { UINT8_C( 17), UINT8_C(  3), UINT8_C( 31), UINT8_C(  6), UINT8_C( 19), UINT8_C( 18), UINT8_C( 20), UINT8_C( 59),
        UINT8_C(  7), UINT8_C( 50), UINT8_C( 10), UINT8_C( 42), UINT8_C( 12), UINT8_C(195), UINT8_C( 32), UINT8_C(199) },
      {  INT8_C(  34),  INT8_C(  78),  INT8_C(  99),  INT8_C(  30),  INT8_C(  99),  INT8_C( 118), -INT8_C(  62), -INT8_C(  17),
        -INT8_C(  52),  INT8_C(  25),  INT8_C(  65),  INT8_C(  94), -INT8_C(  90),  INT8_C(   0),  INT8_C(  46),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x4_t t;
    simde_int8x16_t r;
    simde_uint8x16_t idx = simde_vld1q_u8(test_vec[i].idx);
    t.val[0] = simde_vld1q_s8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_s8(test_vec[i].t[1]);
    t.val[2] = simde_vld1q_s8(test_vec[i].t[2]);
    t.val[3] = simde_vld1q_s8(test_vec[i].t[3]);
    r = simde_vqtbl4q_s8(t, idx);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16x4_t t = simde_test_arm_neon_random_i8x16x4();
    simde_uint8x16_private idx_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 63;
      }
    }

    simde_uint8x16_t idx = simde_uint8x16_from_private(idx_);

    simde_int8x16_t r = simde_vqtbl4q_s8(t, idx);
    simde_test_arm_neon_write_i8x16x4(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqtbl4q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    SIMDE_ALIGN_TO_16 uint8_t t[4][16];
    SIMDE_ALIGN_TO_16 uint8_t idx[16];
    SIMDE_ALIGN_TO_16 uint8_t r[16];
  } test_vec[] = {
    {
        { { UINT8_C( 61), UINT8_C(170), UINT8_C(106), UINT8_C( 58), UINT8_C(205), UINT8_C( 68), UINT8_C( 29), UINT8_C( 29),
            UINT8_C( 37), UINT8_C( 43), UINT8_C(241), UINT8_C(123), UINT8_C(240), UINT8_C(188), UINT8_C( 79), UINT8_C( 68) },
          { UINT8_C(247), UINT8_C(121), UINT8_C(252), UINT8_C(147), UINT8_C(228), UINT8_C(140), UINT8_C(235), UINT8_C( 42),
            UINT8_C( 74), UINT8_C(124), UINT8_C( 84), UINT8_C( 73), UINT8_C( 20), UINT8_C( 61), UINT8_C(118), UINT8_C( 81) },
          { UINT8_C(232), UINT8_C(224), UINT8_C(140), UINT8_C(181), UINT8_C( 36), UINT8_C(169), UINT8_C(210), UINT8_C( 73),
            UINT8_C(213), UINT8_C(195), UINT8_C(196), UINT8_C(197), UINT8_C(127), UINT8_C( 20), UINT8_C(  9), UINT8_C(119) },
          { UINT8_C(141), UINT8_C(  5), UINT8_C( 10), UINT8_C(113), UINT8_C(146), UINT8_C(245), UINT8_C(156), UINT8_C(220),
            UINT8_C(113), UINT8_C(240), UINT8_C( 37), UINT8_C(133), UINT8_C( 46), UINT8_C(155), UINT8_C(215), UINT8_C( 22) } },
      { UINT8_C( 59), UINT8_C( 99), UINT8_C( 11), UINT8_C( 32), UINT8_C( 12), UINT8_C( 29), UINT8_C( 41), UINT8_C( 33),
        UINT8_C( 32), UINT8_C( 46), UINT8_C(167), UINT8_C( 31), UINT8_C(  2), UINT8_C(176), UINT8_C( 22), UINT8_C( 15) },
      { UINT8_C(133), UINT8_C(  0), UINT8_C(123), UINT8_C(232), UINT8_C(240), UINT8_C( 61), UINT8_C(195), UINT8_C(224),
        UINT8_C(232), UINT8_C(  9), UINT8_C(  0), UINT8_C( 81), UINT8_C(106), UINT8_C(  0), UINT8_C(235), UINT8_C( 68) } },
    {
        { { UINT8_C(134), UINT8_C( 92), UINT8_C(  0), UINT8_C(146), UINT8_C(249), UINT8_C(234), UINT8_C(116), UINT8_C( 89),
            UINT8_C(152), UINT8_C( 27), UINT8_C( 56), UINT8_C( 90), UINT8_C(203), UINT8_C(143), UINT8_C(169), UINT8_C(129) },
          { UINT8_C(239), UINT8_C(105), UINT8_C(201), UINT8_C( 69), UINT8_C(198), UINT8_C(237), UINT8_C( 11), UINT8_C( 19),
            UINT8_C( 55), UINT8_C( 87), UINT8_C(142), UINT8_C( 28), UINT8_C(122), UINT8_C( 31), UINT8_C(124), UINT8_C(  0) },
          { UINT8_C(123), UINT8_C(125), UINT8_C(147), UINT8_C(116), UINT8_C(103), UINT8_C(  7), UINT8_C(205),    UINT8_MAX,
            UINT8_C( 34), UINT8_C(  5), UINT8_C( 89), UINT8_C(237), UINT8_C(148), UINT8_C(  2), UINT8_C(111), UINT8_C(132) },
          { UINT8_C(107), UINT8_C( 56), UINT8_C(201), UINT8_C( 49), UINT8_C( 38), UINT8_C(212), UINT8_C( 68), UINT8_C( 93),
            UINT8_C( 44), UINT8_C(210), UINT8_C(121), UINT8_C(166), UINT8_C(241), UINT8_C(245), UINT8_C(167), UINT8_C(108) } },
      { UINT8_C( 50), UINT8_C( 58), UINT8_C(224), UINT8_C( 25), UINT8_C(  1), UINT8_C( 45), UINT8_C(216), UINT8_C( 35),
        UINT8_C( 51), UINT8_C( 49), UINT8_C( 16), UINT8_C(  7), UINT8_C( 51), UINT8_C( 63), UINT8_C(203), UINT8_C( 31) },
      { UINT8_C(201), UINT8_C(121), UINT8_C(  0), UINT8_C( 87), UINT8_C( 92), UINT8_C(  2), UINT8_C(  0), UINT8_C(116),
        UINT8_C( 49), UINT8_C( 56), UINT8_C(239), UINT8_C( 89), UINT8_C( 49), UINT8_C(108), UINT8_C(  0), UINT8_C(  0) } },
    {
        { { UINT8_C( 28), UINT8_C( 38), UINT8_C( 53), UINT8_C( 93), UINT8_C(211), UINT8_C( 14), UINT8_C(192), UINT8_C(134),
            UINT8_C( 63), UINT8_C( 17), UINT8_C(206), UINT8_C(115), UINT8_C(208), UINT8_C(153), UINT8_C( 18), UINT8_C(200) },
          { UINT8_C( 46), UINT8_C(226), UINT8_C(230), UINT8_C(151), UINT8_C(247), UINT8_C( 97), UINT8_C( 44), UINT8_C(223),
            UINT8_C( 85), UINT8_C(103), UINT8_C(184), UINT8_C( 63), UINT8_C( 74), UINT8_C(253), UINT8_C(155), UINT8_C(102) },
          { UINT8_C( 35), UINT8_C(208), UINT8_C(196), UINT8_C(247), UINT8_C(222), UINT8_C(132), UINT8_C(125), UINT8_C( 30),
            UINT8_C(149), UINT8_C( 75), UINT8_C(145), UINT8_C(102), UINT8_C(229), UINT8_C(163), UINT8_C( 46), UINT8_C( 19) },
          { UINT8_C(133), UINT8_C( 21), UINT8_C(170), UINT8_C(125), UINT8_C(118), UINT8_C(214), UINT8_C( 92), UINT8_C(204),
            UINT8_C( 61), UINT8_C( 20), UINT8_C( 11), UINT8_C(135), UINT8_C( 17), UINT8_C(166), UINT8_C(238), UINT8_C( 53) } },
      { UINT8_C( 54), UINT8_C( 50), UINT8_C( 44), UINT8_C( 85), UINT8_C( 54), UINT8_C( 41), UINT8_C(115), UINT8_C( 12),
        UINT8_C( 53), UINT8_C(  4), UINT8_C( 50), UINT8_C( 26), UINT8_C( 39), UINT8_C( 32), UINT8_C( 45), UINT8_C( 44) },
      { UINT8_C( 92), UINT8_C(170), UINT8_C(229), UINT8_C(  0), UINT8_C( 92), UINT8_C( 75), UINT8_C(  0), UINT8_C(208),
        UINT8_C(214), UINT8_C(211), UINT8_C(170), UINT8_C(184), UINT8_C( 30), UINT8_C( 35), UINT8_C(163), UINT8_C(229) } },
    {
        { { UINT8_C(210), UINT8_C(140), UINT8_C( 52), UINT8_C(  8), UINT8_C( 53), UINT8_C(167), UINT8_C(212), UINT8_C( 42),
            UINT8_C(171), UINT8_C(  6), UINT8_C(  4), UINT8_C( 82), UINT8_C(103), UINT8_C(241), UINT8_C(127), UINT8_C(220) },
          { UINT8_C(136), UINT8_C( 40), UINT8_C(200), UINT8_C(245), UINT8_C( 46), UINT8_C(128), UINT8_C(160), UINT8_C( 71),
            UINT8_C( 67), UINT8_C(210), UINT8_C(114), UINT8_C(172), UINT8_C(242), UINT8_C(210), UINT8_C(140), UINT8_C(196) },
          { UINT8_C( 94), UINT8_C(192), UINT8_C(204), UINT8_C(148), UINT8_C(104), UINT8_C(161), UINT8_C(190), UINT8_C( 19),
            UINT8_C(167), UINT8_C(195), UINT8_C(102), UINT8_C( 14), UINT8_C(180), UINT8_C(229), UINT8_C(235), UINT8_C( 61) },
          { UINT8_C( 13), UINT8_C(179), UINT8_C( 50), UINT8_C( 59), UINT8_C( 52), UINT8_C(210), UINT8_C(131), UINT8_C(119),
            UINT8_C(164), UINT8_C(245), UINT8_C( 36), UINT8_C(150), UINT8_C(200), UINT8_C(176), UINT8_C( 90), UINT8_C( 38) } },
      { UINT8_C(112), UINT8_C( 39), UINT8_C( 58), UINT8_C( 24), UINT8_C(  8), UINT8_C( 57), UINT8_C( 44), UINT8_C( 47),
        UINT8_C( 60), UINT8_C( 18), UINT8_C( 62), UINT8_C( 48), UINT8_C( 55), UINT8_C( 41), UINT8_C( 45), UINT8_C(  4) },
      { UINT8_C(  0), UINT8_C( 19), UINT8_C( 36), UINT8_C( 67), UINT8_C(171), UINT8_C(245), UINT8_C(180), UINT8_C( 61),
        UINT8_C(200), UINT8_C(200), UINT8_C( 90), UINT8_C( 13), UINT8_C(119), UINT8_C(195), UINT8_C(229), UINT8_C( 53) } },
    {
        { { UINT8_C(239), UINT8_C(161), UINT8_C(229), UINT8_C(183), UINT8_C( 26), UINT8_C(209), UINT8_C( 38), UINT8_C( 86),
            UINT8_C( 35), UINT8_C(164), UINT8_C( 71), UINT8_C( 90), UINT8_C( 13), UINT8_C(116), UINT8_C(158), UINT8_C( 42) },
          { UINT8_C(212), UINT8_C( 30), UINT8_C(122), UINT8_C(  7), UINT8_C( 33), UINT8_C( 66), UINT8_C(222), UINT8_C( 26),
            UINT8_C( 46), UINT8_C( 75), UINT8_C(218), UINT8_C(202), UINT8_C( 19), UINT8_C(193), UINT8_C(215), UINT8_C(  2) },
          { UINT8_C( 99), UINT8_C(188), UINT8_C(185), UINT8_C(125), UINT8_C(141), UINT8_C(224), UINT8_C(212), UINT8_C(176),
            UINT8_C(132), UINT8_C( 27), UINT8_C( 10), UINT8_C(146), UINT8_C(143), UINT8_C(168), UINT8_C(188), UINT8_C(100) },
          { UINT8_C(199), UINT8_C( 54), UINT8_C(107), UINT8_C(232), UINT8_C(121), UINT8_C( 73), UINT8_C(  2), UINT8_C(167),
            UINT8_C(148), UINT8_C(221), UINT8_C(114), UINT8_C(168), UINT8_C(158), UINT8_C( 73), UINT8_C(170), UINT8_C(  1) } },
      { UINT8_C(  5), UINT8_C( 36), UINT8_C( 63), UINT8_C( 18), UINT8_C(  4), UINT8_C( 19), UINT8_C(  2), UINT8_C(  8),
        UINT8_C( 46), UINT8_C( 12), UINT8_C( 26), UINT8_C( 61), UINT8_C( 52), UINT8_C( 22), UINT8_C( 33), UINT8_C( 59) },
      { UINT8_C(209), UINT8_C(141), UINT8_C(  1), UINT8_C(122), UINT8_C( 26), UINT8_C(  7), UINT8_C(229), UINT8_C( 35),
        UINT8_C(188), UINT8_C( 13), UINT8_C(218), UINT8_C( 73), UINT8_C(121), UINT8_C(222), UINT8_C(188), UINT8_C(168) } },
    {
        { { UINT8_C( 96), UINT8_C(162), UINT8_C(191), UINT8_C(164), UINT8_C(245), UINT8_C(  1), UINT8_C(109), UINT8_C( 99),
            UINT8_C( 77), UINT8_C(199), UINT8_C( 97), UINT8_C( 66), UINT8_C(222), UINT8_C(194), UINT8_C(253), UINT8_C( 43) },
          { UINT8_C(143), UINT8_C(161), UINT8_C(241), UINT8_C(164), UINT8_C( 72), UINT8_C( 94), UINT8_C( 78), UINT8_C(203),
            UINT8_C( 62), UINT8_C(160), UINT8_C(237), UINT8_C(102), UINT8_C(157), UINT8_C( 17), UINT8_C(148), UINT8_C(253) },
          { UINT8_C(179), UINT8_C( 83), UINT8_C(162), UINT8_C(169), UINT8_C( 85), UINT8_C( 15), UINT8_C( 12), UINT8_C(162),
            UINT8_C(214), UINT8_C(109), UINT8_C(228), UINT8_C(180), UINT8_C( 48), UINT8_C(226), UINT8_C(223), UINT8_C(191) },
          { UINT8_C(131), UINT8_C(208), UINT8_C( 99), UINT8_C(203), UINT8_C( 47), UINT8_C(178), UINT8_C(151), UINT8_C(109),
            UINT8_C( 82), UINT8_C(132), UINT8_C(211), UINT8_C(239), UINT8_C(149), UINT8_C(103), UINT8_C(237), UINT8_C( 73) } },
      { UINT8_C( 59), UINT8_C( 15), UINT8_C(242), UINT8_C( 16), UINT8_C( 30), UINT8_C( 62), UINT8_C( 50), UINT8_C( 52),
        UINT8_C( 44), UINT8_C( 23), UINT8_C( 41), UINT8_C(156), UINT8_C( 57), UINT8_C(  8), UINT8_C( 91), UINT8_C( 60) },
      { UINT8_C(239), UINT8_C( 43), UINT8_C(  0), UINT8_C(143), UINT8_C(148), UINT8_C(237), UINT8_C( 99), UINT8_C( 47),
        UINT8_C( 48), UINT8_C(203), UINT8_C(109), UINT8_C(  0), UINT8_C(132), UINT8_C( 77), UINT8_C(  0), UINT8_C(149) } },
    {
        { { UINT8_C( 46), UINT8_C(180), UINT8_C(123), UINT8_C(204), UINT8_C(178), UINT8_C( 45), UINT8_C( 65), UINT8_C( 30),
            UINT8_C(196), UINT8_C(106), UINT8_C(186), UINT8_C( 61), UINT8_C(114), UINT8_C( 21), UINT8_C( 58), UINT8_C( 75) },
          { UINT8_C(212), UINT8_C(  2), UINT8_C( 83), UINT8_C( 68), UINT8_C( 97), UINT8_C(200), UINT8_C(  7), UINT8_C( 68),
            UINT8_C( 17), UINT8_C(186), UINT8_C(189), UINT8_C(193), UINT8_C( 89), UINT8_C(127), UINT8_C( 44), UINT8_C(136) },
          { UINT8_C( 51), UINT8_C(167), UINT8_C( 84), UINT8_C(230), UINT8_C(212), UINT8_C(149), UINT8_C(  4), UINT8_C(153),
               UINT8_MAX, UINT8_C(191), UINT8_C(214), UINT8_C(114), UINT8_C(212), UINT8_C( 16), UINT8_C(189), UINT8_C(168) },
          { UINT8_C( 18), UINT8_C( 17), UINT8_C(237), UINT8_C(115), UINT8_C(217), UINT8_C(244), UINT8_C(184), UINT8_C(234),
            UINT8_C(174), UINT8_C(117), UINT8_C(171), UINT8_C(  8), UINT8_C(245), UINT8_C(215), UINT8_C(144), UINT8_C( 40) } },
      { UINT8_C( 62), UINT8_C( 36), UINT8_C( 14), UINT8_C( 83), UINT8_C( 58), UINT8_C( 19), UINT8_C(236), UINT8_C( 57),
        UINT8_C(210), UINT8_C(194), UINT8_C( 43), UINT8_C( 38), UINT8_C( 19), UINT8_C( 41), UINT8_C( 79), UINT8_C( 37) },
      { UINT8_C(144), UINT8_C(212), UINT8_C( 58), UINT8_C(  0), UINT8_C(171), UINT8_C( 68), UINT8_C(  0), UINT8_C(117),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(114), UINT8_C(  4), UINT8_C( 68), UINT8_C(191), UINT8_C(  0), UINT8_C(149) } },
    {
        { { UINT8_C( 91), UINT8_C(178), UINT8_C(210), UINT8_C(213), UINT8_C(197), UINT8_C(190), UINT8_C( 79), UINT8_C(151),
            UINT8_C(129), UINT8_C( 58), UINT8_C( 62), UINT8_C( 84), UINT8_C(227), UINT8_C(141), UINT8_C( 57), UINT8_C(157) },
          { UINT8_C(201), UINT8_C(146), UINT8_C( 49), UINT8_C(249), UINT8_C(163), UINT8_C(175), UINT8_C(216), UINT8_C( 42),
            UINT8_C(216), UINT8_C(191), UINT8_C(165), UINT8_C(217), UINT8_C( 54), UINT8_C( 73), UINT8_C( 89), UINT8_C(146) },
          { UINT8_C(252), UINT8_C( 43), UINT8_C(103), UINT8_C(193), UINT8_C(234), UINT8_C(182), UINT8_C( 89), UINT8_C(107),
            UINT8_C(241), UINT8_C(151), UINT8_C(191), UINT8_C(212), UINT8_C( 36), UINT8_C(248), UINT8_C(114), UINT8_C(237) },
          { UINT8_C(139), UINT8_C(163), UINT8_C(230), UINT8_C( 46), UINT8_C( 82), UINT8_C(191), UINT8_C( 88), UINT8_C( 42),
            UINT8_C(126), UINT8_C(254), UINT8_C(  4), UINT8_C(181), UINT8_C( 71), UINT8_C( 93), UINT8_C( 71), UINT8_C( 67) } },
      { UINT8_C(  8), UINT8_C(174), UINT8_C(  5), UINT8_C( 50), UINT8_C( 37), UINT8_C( 30), UINT8_C(221), UINT8_C( 22),
        UINT8_C( 53), UINT8_C( 28), UINT8_C( 42), UINT8_C( 25), UINT8_C( 21), UINT8_C(156), UINT8_C(  6), UINT8_C( 32) },
      { UINT8_C(129), UINT8_C(  0), UINT8_C(190), UINT8_C(230), UINT8_C(182), UINT8_C( 89), UINT8_C(  0), UINT8_C(216),
        UINT8_C(191), UINT8_C( 54), UINT8_C(191), UINT8_C(191), UINT8_C(175), UINT8_C(  0), UINT8_C( 79), UINT8_C(252) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x4_t t;
    simde_uint8x16_t idx, r;
    idx = simde_vld1q_u8(test_vec[i].idx);
    t.val[0] = simde_vld1q_u8(test_vec[i].t[0]);
    t.val[1] = simde_vld1q_u8(test_vec[i].t[1]);
    t.val[2] = simde_vld1q_u8(test_vec[i].t[2]);
    t.val[3] = simde_vld1q_u8(test_vec[i].t[3]);
    r = simde_vqtbl4q_u8(t, idx);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);

  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16x4_t t = simde_test_arm_neon_random_u8x16x4();
    simde_uint8x16_private idx_ = simde_uint8x16_to_private(simde_test_arm_neon_random_u8x16());

    for (size_t j = 0 ; j < (sizeof(idx_.values) / sizeof(idx_.values[0])) ; j++) {
      if (probability(PROBABILITY)) {
        idx_.values[j] &= 63;
      }
    }

    simde_uint8x16_t idx = simde_uint8x16_from_private(idx_);

    simde_uint8x16_t r = simde_vqtbl4q_u8(t, idx);

    simde_test_arm_neon_write_u8x16x4(2, t, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, idx, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl1_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl1_u8)
#if !defined(SIMDE_BUG_INTEL_857088)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl2_s8)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl2_u8)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl3_s8)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl3_u8)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl4_s8)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl4_u8)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl1q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl1q_u8)
#if !defined(SIMDE_BUG_INTEL_857088)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl2q_s8)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl2q_u8)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl3q_s8)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl3q_u8)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl4q_s8)
  SIMDE_TEST_FUNC_LIST_ENTRY(vqtbl4q_u8)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
