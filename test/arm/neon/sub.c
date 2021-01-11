#define SIMDE_TEST_ARM_NEON_INSN sub

#include "test-neon.h"
#include "../../../simde/arm/neon/sub.h"

static int
test_simde_vsub_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   360.99), SIMDE_FLOAT32_C(   722.92) },
      { SIMDE_FLOAT32_C(   682.14), SIMDE_FLOAT32_C(   426.96) },
      { SIMDE_FLOAT32_C(  -321.15), SIMDE_FLOAT32_C(   295.96) } },
    { { SIMDE_FLOAT32_C(   -11.59), SIMDE_FLOAT32_C(   342.55) },
      { SIMDE_FLOAT32_C(   590.06), SIMDE_FLOAT32_C(   965.15) },
      { SIMDE_FLOAT32_C(  -601.65), SIMDE_FLOAT32_C(  -622.60) } },
    { { SIMDE_FLOAT32_C(   547.91), SIMDE_FLOAT32_C(  -219.14) },
      { SIMDE_FLOAT32_C(  -886.88), SIMDE_FLOAT32_C(   282.47) },
      { SIMDE_FLOAT32_C(  1434.79), SIMDE_FLOAT32_C(  -501.61) } },
    { { SIMDE_FLOAT32_C(    13.06), SIMDE_FLOAT32_C(   946.64) },
      { SIMDE_FLOAT32_C(   963.27), SIMDE_FLOAT32_C(   959.34) },
      { SIMDE_FLOAT32_C(  -950.22), SIMDE_FLOAT32_C(   -12.70) } },
    { { SIMDE_FLOAT32_C(   829.13), SIMDE_FLOAT32_C(  -382.80) },
      { SIMDE_FLOAT32_C(  -854.14), SIMDE_FLOAT32_C(   146.76) },
      { SIMDE_FLOAT32_C(  1683.27), SIMDE_FLOAT32_C(  -529.55) } },
    { { SIMDE_FLOAT32_C(    73.22), SIMDE_FLOAT32_C(  -493.34) },
      { SIMDE_FLOAT32_C(   912.86), SIMDE_FLOAT32_C(   976.77) },
      { SIMDE_FLOAT32_C(  -839.64), SIMDE_FLOAT32_C( -1470.11) } },
    { { SIMDE_FLOAT32_C(   314.03), SIMDE_FLOAT32_C(  -507.33) },
      { SIMDE_FLOAT32_C(   923.09), SIMDE_FLOAT32_C(  -827.02) },
      { SIMDE_FLOAT32_C(  -609.06), SIMDE_FLOAT32_C(   319.69) } },
    { { SIMDE_FLOAT32_C(  -988.72), SIMDE_FLOAT32_C(  -917.98) },
      { SIMDE_FLOAT32_C(  -195.14), SIMDE_FLOAT32_C(   372.28) },
      { SIMDE_FLOAT32_C(  -793.58), SIMDE_FLOAT32_C( -1290.26) } }
  };  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, b, r;

    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    r = simde_vsub_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vsub_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -464.36) },
      { SIMDE_FLOAT64_C(   759.96) },
      { SIMDE_FLOAT64_C( -1224.33) } },
    { { SIMDE_FLOAT64_C(   959.10) },
      { SIMDE_FLOAT64_C(   297.97) },
      { SIMDE_FLOAT64_C(   661.13) } },
    { { SIMDE_FLOAT64_C(   736.45) },
      { SIMDE_FLOAT64_C(  -164.58) },
      { SIMDE_FLOAT64_C(   901.03) } },
    { { SIMDE_FLOAT64_C(   849.22) },
      { SIMDE_FLOAT64_C(   985.27) },
      { SIMDE_FLOAT64_C(  -136.05) } },
    { { SIMDE_FLOAT64_C(   917.24) },
      { SIMDE_FLOAT64_C(   640.75) },
      { SIMDE_FLOAT64_C(   276.49) } },
    { { SIMDE_FLOAT64_C(   422.18) },
      { SIMDE_FLOAT64_C(   767.10) },
      { SIMDE_FLOAT64_C(  -344.92) } },
    { { SIMDE_FLOAT64_C(  -365.38) },
      { SIMDE_FLOAT64_C(   691.56) },
      { SIMDE_FLOAT64_C( -1056.93) } },
    { { SIMDE_FLOAT64_C(   655.10) },
      { SIMDE_FLOAT64_C(   559.29) },
      { SIMDE_FLOAT64_C(    95.82) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vsub_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vsub_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  86),  INT8_C(  59), -INT8_C( 116), -INT8_C( 123), -INT8_C(  44), -INT8_C( 120),  INT8_C(  28), -INT8_C( 104) },
      { -INT8_C( 122),  INT8_C( 123), -INT8_C(  26),  INT8_C(  51),  INT8_C(  71), -INT8_C(  64),  INT8_C( 123),  INT8_C(  12) },
      {  INT8_C(  36), -INT8_C(  64), -INT8_C(  90),  INT8_C(  82), -INT8_C( 115), -INT8_C(  56), -INT8_C(  95), -INT8_C( 116) } },
    { { -INT8_C(  23), -INT8_C(   9), -INT8_C(  81), -INT8_C(  94),  INT8_C(  57), -INT8_C(  16), -INT8_C(  81), -INT8_C( 110) },
      { -INT8_C(  28),  INT8_C( 125), -INT8_C(  21), -INT8_C(  64),  INT8_C(  43),  INT8_C(  80),  INT8_C(  73), -INT8_C(  43) },
      {  INT8_C(   5),  INT8_C( 122), -INT8_C(  60), -INT8_C(  30),  INT8_C(  14), -INT8_C(  96),  INT8_C( 102), -INT8_C(  67) } },
    { { -INT8_C( 116), -INT8_C(  43),  INT8_C(  91),  INT8_C(  96),  INT8_C(  94),  INT8_C( 119), -INT8_C(   8), -INT8_C(  28) },
      { -INT8_C(  14), -INT8_C(  34),  INT8_C(  24),  INT8_C(  57), -INT8_C(  98), -INT8_C( 109),  INT8_C(  69), -INT8_C( 121) },
      { -INT8_C( 102), -INT8_C(   9),  INT8_C(  67),  INT8_C(  39), -INT8_C(  64), -INT8_C(  28), -INT8_C(  77),  INT8_C(  93) } },
    { { -INT8_C( 118), -INT8_C(  12),  INT8_C(  42), -INT8_C(  60), -INT8_C(  28), -INT8_C(  39),  INT8_C(  86), -INT8_C(  55) },
      {  INT8_C(  86),  INT8_C(  65), -INT8_C( 119), -INT8_C( 126), -INT8_C( 110), -INT8_C(  46),  INT8_C(  87),  INT8_C(  30) },
      {  INT8_C(  52), -INT8_C(  77), -INT8_C(  95),  INT8_C(  66),  INT8_C(  82),  INT8_C(   7), -INT8_C(   1), -INT8_C(  85) } },
    { { -INT8_C(  89), -INT8_C(  78),  INT8_C( 126),  INT8_C(   5),  INT8_C(  41),  INT8_C( 118), -INT8_C(  22),  INT8_C(  27) },
      {  INT8_C(  84),  INT8_C(   2),  INT8_C(  84), -INT8_C(  13), -INT8_C( 107), -INT8_C( 102),  INT8_C( 122),  INT8_C(  31) },
      {  INT8_C(  83), -INT8_C(  80),  INT8_C(  42),  INT8_C(  18), -INT8_C( 108), -INT8_C(  36),  INT8_C( 112), -INT8_C(   4) } },
    { { -INT8_C( 114), -INT8_C(  92), -INT8_C(  29),  INT8_C( 115),  INT8_C( 126),  INT8_C(  57),  INT8_C(  60), -INT8_C(  44) },
      {  INT8_C( 123), -INT8_C(  59),  INT8_C(  86),  INT8_C(  13), -INT8_C( 105), -INT8_C(  82),  INT8_C(  43),  INT8_C(  62) },
      {  INT8_C(  19), -INT8_C(  33), -INT8_C( 115),  INT8_C( 102), -INT8_C(  25), -INT8_C( 117),  INT8_C(  17), -INT8_C( 106) } },
    { {  INT8_C(  96), -INT8_C(  87),  INT8_C(  68), -INT8_C( 118),  INT8_C(  31),  INT8_C(  46), -INT8_C(  91),  INT8_C( 115) },
      {  INT8_C(  48), -INT8_C(   6),  INT8_C( 102), -INT8_C(  59), -INT8_C( 108), -INT8_C(  31), -INT8_C(  28),  INT8_C(  34) },
      {  INT8_C(  48), -INT8_C(  81), -INT8_C(  34), -INT8_C(  59), -INT8_C( 117),  INT8_C(  77), -INT8_C(  63),  INT8_C(  81) } },
    { { -INT8_C( 123), -INT8_C(  56), -INT8_C( 107),  INT8_C(   3),  INT8_C(   1), -INT8_C(  47), -INT8_C(  40),  INT8_C( 124) },
      { -INT8_C( 106),  INT8_C(  46), -INT8_C( 119),  INT8_C(  45), -INT8_C(  36), -INT8_C(  76),  INT8_C( 108),  INT8_C(  61) },
      { -INT8_C(  17), -INT8_C( 102),  INT8_C(  12), -INT8_C(  42),  INT8_C(  37),  INT8_C(  29),  INT8_C( 108),  INT8_C(  63) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vsub_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsub_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 24371),  INT16_C( 25777), -INT16_C(  6138), -INT16_C( 26958) },
      {  INT16_C( 31782), -INT16_C( 21475), -INT16_C( 30815),  INT16_C( 16870) },
      {  INT16_C(  9383), -INT16_C( 18284),  INT16_C( 24677),  INT16_C( 21708) } },
    { {  INT16_C( 30389),  INT16_C(  1729), -INT16_C( 20391),  INT16_C(  4694) },
      {  INT16_C( 28093), -INT16_C(  9420),  INT16_C( 22129),  INT16_C( 16024) },
      {  INT16_C(  2296),  INT16_C( 11149),  INT16_C( 23016), -INT16_C( 11330) } },
    { {  INT16_C( 19190), -INT16_C(   606),  INT16_C( 21810),  INT16_C( 22675) },
      { -INT16_C( 20271),  INT16_C( 29444), -INT16_C(  5321), -INT16_C(  4684) },
      { -INT16_C( 26075), -INT16_C( 30050),  INT16_C( 27131),  INT16_C( 27359) } },
    { {  INT16_C( 30049), -INT16_C( 17677),  INT16_C( 18982), -INT16_C(  7220) },
      {  INT16_C(   183),  INT16_C( 10686),  INT16_C( 22358),  INT16_C( 19815) },
      {  INT16_C( 29866), -INT16_C( 28363), -INT16_C(  3376), -INT16_C( 27035) } },
    { {  INT16_C(  2721), -INT16_C( 11446), -INT16_C(  8865),  INT16_C( 12331) },
      {  INT16_C( 12429), -INT16_C( 15197),  INT16_C( 22555),  INT16_C( 31921) },
      { -INT16_C(  9708),  INT16_C(  3751), -INT16_C( 31420), -INT16_C( 19590) } },
    { { -INT16_C( 23091), -INT16_C(  3274),  INT16_C(   751), -INT16_C( 22825) },
      { -INT16_C( 27389),  INT16_C( 22991),  INT16_C( 14316), -INT16_C( 29274) },
      {  INT16_C(  4298), -INT16_C( 26265), -INT16_C( 13565),  INT16_C(  6449) } },
    { { -INT16_C(  4031), -INT16_C( 24480), -INT16_C( 29491),  INT16_C( 23248) },
      {  INT16_C( 29884), -INT16_C( 10465), -INT16_C( 12084), -INT16_C( 26285) },
      {  INT16_C( 31621), -INT16_C( 14015), -INT16_C( 17407), -INT16_C( 16003) } },
    { { -INT16_C( 30347),  INT16_C( 25741),  INT16_C( 25739), -INT16_C( 29173) },
      { -INT16_C(  9479), -INT16_C(  6424), -INT16_C( 29167),  INT16_C( 21107) },
      { -INT16_C( 20868),  INT16_C( 32165), -INT16_C( 10630),  INT16_C( 15256) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vsub_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsub_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  2124589663), -INT32_C(   360776502) },
      {  INT32_C(  2043609956), -INT32_C(  1270893877) },
      {  INT32_C(   126767677),  INT32_C(   910117375) } },
    { {  INT32_C(   343997614),  INT32_C(   705859580) },
      {  INT32_C(  1578649653),  INT32_C(   517998717) },
      { -INT32_C(  1234652039),  INT32_C(   187860863) } },
    { {  INT32_C(   664747613), -INT32_C(  1642980038) },
      { -INT32_C(   350756576),  INT32_C(  1100961427) },
      {  INT32_C(  1015504189),  INT32_C(  1551025831) } },
    { {  INT32_C(  1314267218), -INT32_C(   461870929) },
      {  INT32_C(   759337136), -INT32_C(   162847847) },
      {  INT32_C(   554930082), -INT32_C(   299023082) } },
    { { -INT32_C(  1692472479),  INT32_C(   691613704) },
      { -INT32_C(  1525395439), -INT32_C(   102320986) },
      { -INT32_C(   167077040),  INT32_C(   793934690) } },
    { { -INT32_C(  2092483372),  INT32_C(  1432862885) },
      { -INT32_C(   377247152),  INT32_C(   786484941) },
      { -INT32_C(  1715236220),  INT32_C(   646377944) } },
    { { -INT32_C(  1026949447),  INT32_C(  1072366126) },
      { -INT32_C(   119210158), -INT32_C(  2014196813) },
      { -INT32_C(   907739289), -INT32_C(  1208404357) } },
    { { -INT32_C(  1408616185),  INT32_C(  1224897273) },
      { -INT32_C(   382499556),  INT32_C(   219616083) },
      { -INT32_C(  1026116629),  INT32_C(  1005281190) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vsub_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsub_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C(  657685634693326830) },
      { -INT64_C( 8547862028071945079) },
      {  INT64_C( 7890176393378618249) } },
    { {  INT64_C(  410282319565482483) },
      { -INT64_C( 8894323999304500444) },
      { -INT64_C( 9142137754839568689) } },
    { { -INT64_C( 4433867253433316581) },
      {  INT64_C(  561055581874761594) },
      { -INT64_C( 4994922835308078175) } },
    { { -INT64_C( 2464801910170707154) },
      {  INT64_C( 2554893422116537470) },
      { -INT64_C( 5019695332287244624) } },
    { { -INT64_C( 8461106941343280231) },
      { -INT64_C( 1340220289429308853) },
      { -INT64_C( 7120886651913971378) } },
    { { -INT64_C( 4952413417304229456) },
      { -INT64_C( 1464478769234607229) },
      { -INT64_C( 3487934648069622227) } },
    { { -INT64_C( 5112057892408831373) },
      {  INT64_C( 2123587332767078860) },
      { -INT64_C( 7235645225175910233) } },
    { {  INT64_C( 3202283264815803256) },
      { -INT64_C( 5869487482085106866) },
      {  INT64_C( 9071770746900910122) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vsub_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsub_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(226), UINT8_C(152), UINT8_C(175), UINT8_C( 29), UINT8_C(233), UINT8_C( 81), UINT8_C( 65), UINT8_C(  7) },
      { UINT8_C(166), UINT8_C(215), UINT8_C(155), UINT8_C( 54), UINT8_C(226), UINT8_C(113), UINT8_C( 20), UINT8_C(177) },
      { UINT8_C( 60), UINT8_C(193), UINT8_C( 20), UINT8_C(231), UINT8_C(  7), UINT8_C(224), UINT8_C( 45), UINT8_C( 86) } },
    { { UINT8_C( 32), UINT8_C(227), UINT8_C( 13), UINT8_C(184), UINT8_C(211), UINT8_C(108), UINT8_C(142), UINT8_C( 85) },
      { UINT8_C( 75), UINT8_C(149), UINT8_C( 97), UINT8_C( 87), UINT8_C(227), UINT8_C(174), UINT8_C(  4), UINT8_C(197) },
      { UINT8_C(213), UINT8_C( 78), UINT8_C(172), UINT8_C( 97), UINT8_C(240), UINT8_C(190), UINT8_C(138), UINT8_C(144) } },
    { { UINT8_C( 70), UINT8_C(180), UINT8_C(227), UINT8_C( 48), UINT8_C(  5), UINT8_C( 36), UINT8_C( 55), UINT8_C(171) },
      { UINT8_C(251), UINT8_C(210), UINT8_C(226), UINT8_C(222), UINT8_C( 67), UINT8_C(246), UINT8_C(143), UINT8_C(100) },
      { UINT8_C( 75), UINT8_C(226), UINT8_C(  1), UINT8_C( 82), UINT8_C(194), UINT8_C( 46), UINT8_C(168), UINT8_C( 71) } },
    { { UINT8_C(218), UINT8_C(156), UINT8_C( 28), UINT8_C(173), UINT8_C(  9), UINT8_C(171), UINT8_C(  2), UINT8_C( 84) },
      { UINT8_C( 64), UINT8_C( 99), UINT8_C(171), UINT8_C( 36), UINT8_C( 17), UINT8_C(175), UINT8_C(233), UINT8_C( 88) },
      { UINT8_C(154), UINT8_C( 57), UINT8_C(113), UINT8_C(137), UINT8_C(248), UINT8_C(252), UINT8_C( 25), UINT8_C(252) } },
    { { UINT8_C( 99), UINT8_C(204), UINT8_C(136), UINT8_C(105), UINT8_C(240), UINT8_C(191), UINT8_C( 20), UINT8_C(236) },
      { UINT8_C(145), UINT8_C(246), UINT8_C(202), UINT8_C(212), UINT8_C(237), UINT8_C( 89), UINT8_C( 56), UINT8_C(199) },
      { UINT8_C(210), UINT8_C(214), UINT8_C(190), UINT8_C(149), UINT8_C(  3), UINT8_C(102), UINT8_C(220), UINT8_C( 37) } },
    { { UINT8_C(246), UINT8_C( 85), UINT8_C(116), UINT8_C(255), UINT8_C(  0), UINT8_C(118), UINT8_C( 83), UINT8_C( 64) },
      { UINT8_C(218), UINT8_C(254), UINT8_C(100), UINT8_C(235), UINT8_C(173), UINT8_C( 78), UINT8_C( 67), UINT8_C( 17) },
      { UINT8_C( 28), UINT8_C( 87), UINT8_C( 16), UINT8_C( 20), UINT8_C( 83), UINT8_C( 40), UINT8_C( 16), UINT8_C( 47) } },
    { { UINT8_C( 26), UINT8_C(203), UINT8_C(122), UINT8_C( 11), UINT8_C(138), UINT8_C(142), UINT8_C(247), UINT8_C( 27) },
      { UINT8_C(133), UINT8_C(193), UINT8_C(240), UINT8_C(114), UINT8_C( 26), UINT8_C( 40), UINT8_C( 57), UINT8_C( 16) },
      { UINT8_C(149), UINT8_C( 10), UINT8_C(138), UINT8_C(153), UINT8_C(112), UINT8_C(102), UINT8_C(190), UINT8_C( 11) } },
    { { UINT8_C(125), UINT8_C(173), UINT8_C( 15), UINT8_C(125), UINT8_C( 35), UINT8_C( 98), UINT8_C(190), UINT8_C(253) },
      { UINT8_C( 96), UINT8_C( 34), UINT8_C(233), UINT8_C( 14), UINT8_C(112), UINT8_C( 44), UINT8_C( 31), UINT8_C(139) },
      { UINT8_C( 29), UINT8_C(139), UINT8_C( 38), UINT8_C(111), UINT8_C(179), UINT8_C( 54), UINT8_C(159), UINT8_C(114) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vsub_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsub_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(39416), UINT16_C(33430), UINT16_C(36135), UINT16_C(44190) },
      { UINT16_C(36430), UINT16_C(26654), UINT16_C(22454), UINT16_C(13433) },
      { UINT16_C( 2986), UINT16_C( 6776), UINT16_C(13681), UINT16_C(30757) } },
    { { UINT16_C(34820), UINT16_C(10417), UINT16_C(28651), UINT16_C(19237) },
      { UINT16_C( 3730), UINT16_C(  601), UINT16_C(30779), UINT16_C(13197) },
      { UINT16_C(31090), UINT16_C( 9816), UINT16_C(63408), UINT16_C( 6040) } },
    { { UINT16_C( 8977), UINT16_C(14773), UINT16_C(21424), UINT16_C(65253) },
      { UINT16_C( 1249), UINT16_C(39015), UINT16_C(57435), UINT16_C(24780) },
      { UINT16_C( 7728), UINT16_C(41294), UINT16_C(29525), UINT16_C(40473) } },
    { { UINT16_C(32104), UINT16_C(21384), UINT16_C(44525), UINT16_C(32671) },
      { UINT16_C(63676), UINT16_C(63361), UINT16_C( 3953), UINT16_C(33322) },
      { UINT16_C(33964), UINT16_C(23559), UINT16_C(40572), UINT16_C(64885) } },
    { { UINT16_C(57138), UINT16_C(58299), UINT16_C(41267), UINT16_C( 5345) },
      { UINT16_C(18597), UINT16_C(  172), UINT16_C(30760), UINT16_C(37216) },
      { UINT16_C(38541), UINT16_C(58127), UINT16_C(10507), UINT16_C(33665) } },
    { { UINT16_C(59638), UINT16_C(58340), UINT16_C(33686), UINT16_C(21090) },
      { UINT16_C(58236), UINT16_C(60745), UINT16_C(29682), UINT16_C( 9583) },
      { UINT16_C( 1402), UINT16_C(63131), UINT16_C( 4004), UINT16_C(11507) } },
    { { UINT16_C(11090), UINT16_C(34056), UINT16_C(59852), UINT16_C(29082) },
      { UINT16_C(17970), UINT16_C(23153), UINT16_C(53951), UINT16_C(46571) },
      { UINT16_C(58656), UINT16_C(10903), UINT16_C( 5901), UINT16_C(48047) } },
    { { UINT16_C(53434), UINT16_C(20632), UINT16_C(64083), UINT16_C(53154) },
      { UINT16_C(60381), UINT16_C(53436), UINT16_C(11358), UINT16_C(45557) },
      { UINT16_C(58589), UINT16_C(32732), UINT16_C(52725), UINT16_C( 7597) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vsub_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsub_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 590806359), UINT32_C( 412405990) },
      { UINT32_C(3597862167), UINT32_C(2458607319) },
      { UINT32_C(1287911488), UINT32_C(2248765967) } },
    { { UINT32_C(2195858222), UINT32_C(4199646493) },
      { UINT32_C(3486125680), UINT32_C(2441133882) },
      { UINT32_C(3004699838), UINT32_C(1758512611) } },
    { { UINT32_C(2746529468), UINT32_C(2663073927) },
      { UINT32_C( 628371021), UINT32_C(3149397901) },
      { UINT32_C(2118158447), UINT32_C(3808643322) } },
    { { UINT32_C(1061001506), UINT32_C(2402914078) },
      { UINT32_C(3613263005), UINT32_C(2154356419) },
      { UINT32_C(1742705797), UINT32_C( 248557659) } },
    { { UINT32_C( 455285908), UINT32_C(2981748324) },
      { UINT32_C(2597727501), UINT32_C(1314229548) },
      { UINT32_C(2152525703), UINT32_C(1667518776) } },
    { { UINT32_C(1166906151), UINT32_C(3218392866) },
      { UINT32_C(2392208075), UINT32_C(2769223184) },
      { UINT32_C(3069665372), UINT32_C( 449169682) } },
    { { UINT32_C(2126524698), UINT32_C( 489650704) },
      { UINT32_C(3568764583), UINT32_C(3122793619) },
      { UINT32_C(2852727411), UINT32_C(1661824381) } },
    { { UINT32_C(3238047903), UINT32_C(1115739255) },
      { UINT32_C( 399513095), UINT32_C( 784129812) },
      { UINT32_C(2838534808), UINT32_C( 331609443) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vsub_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsub_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(11402512785535171856) },
      { UINT64_C(11542889678448555234) },
      { UINT64_C(18306367180796168238) } },
    { { UINT64_C(  864376688470011973) },
      { UINT64_C(13708077300151734009) },
      { UINT64_C( 5603043462027829580) } },
    { { UINT64_C(12029709184206301276) },
      { UINT64_C( 4517758008823669776) },
      { UINT64_C( 7511951175382631500) } },
    { { UINT64_C(17261445209413784700) },
      { UINT64_C(16947671631759519687) },
      { UINT64_C(  313773577654265013) } },
    { { UINT64_C( 4434972706747584801) },
      { UINT64_C( 8128155052344846485) },
      { UINT64_C(14753561728112289932) } },
    { { UINT64_C( 9798563678062233365) },
      { UINT64_C( 5955216873392699436) },
      { UINT64_C( 3843346804669533929) } },
    { { UINT64_C(12225519354979607615) },
      { UINT64_C( 1067922630293125229) },
      { UINT64_C(11157596724686482386) } },
    { { UINT64_C( 7787591547626374092) },
      { UINT64_C( 8975898620757217037) },
      { UINT64_C(17258437000578708671) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vsub_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsubq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   313.36), SIMDE_FLOAT32_C(   130.95), SIMDE_FLOAT32_C(   558.01), SIMDE_FLOAT32_C(  -224.30) },
      { SIMDE_FLOAT32_C(  -431.17), SIMDE_FLOAT32_C(  -838.29), SIMDE_FLOAT32_C(   973.18), SIMDE_FLOAT32_C(  -249.71) },
      { SIMDE_FLOAT32_C(   744.52), SIMDE_FLOAT32_C(   969.24), SIMDE_FLOAT32_C(  -415.17), SIMDE_FLOAT32_C(    25.41) } },
    { { SIMDE_FLOAT32_C(  -619.93), SIMDE_FLOAT32_C(  -195.67), SIMDE_FLOAT32_C(   784.76), SIMDE_FLOAT32_C(   593.47) },
      { SIMDE_FLOAT32_C(  -109.46), SIMDE_FLOAT32_C(   -51.93), SIMDE_FLOAT32_C(  -685.95), SIMDE_FLOAT32_C(    54.63) },
      { SIMDE_FLOAT32_C(  -510.46), SIMDE_FLOAT32_C(  -143.74), SIMDE_FLOAT32_C(  1470.70), SIMDE_FLOAT32_C(   538.84) } },
    { { SIMDE_FLOAT32_C(   238.71), SIMDE_FLOAT32_C(  -726.25), SIMDE_FLOAT32_C(  -693.46), SIMDE_FLOAT32_C(   265.88) },
      { SIMDE_FLOAT32_C(   740.54), SIMDE_FLOAT32_C(   826.68), SIMDE_FLOAT32_C(  -296.56), SIMDE_FLOAT32_C(   -34.22) },
      { SIMDE_FLOAT32_C(  -501.83), SIMDE_FLOAT32_C( -1552.93), SIMDE_FLOAT32_C(  -396.90), SIMDE_FLOAT32_C(   300.10) } },
    { { SIMDE_FLOAT32_C(   788.21), SIMDE_FLOAT32_C(   906.36), SIMDE_FLOAT32_C(  -290.22), SIMDE_FLOAT32_C(    38.77) },
      { SIMDE_FLOAT32_C(   692.11), SIMDE_FLOAT32_C(   669.99), SIMDE_FLOAT32_C(    83.43), SIMDE_FLOAT32_C(     5.46) },
      { SIMDE_FLOAT32_C(    96.10), SIMDE_FLOAT32_C(   236.38), SIMDE_FLOAT32_C(  -373.65), SIMDE_FLOAT32_C(    33.31) } },
    { { SIMDE_FLOAT32_C(  -199.06), SIMDE_FLOAT32_C(  -358.56), SIMDE_FLOAT32_C(   781.16), SIMDE_FLOAT32_C(   369.77) },
      { SIMDE_FLOAT32_C(  -196.85), SIMDE_FLOAT32_C(   754.34), SIMDE_FLOAT32_C(  -879.94), SIMDE_FLOAT32_C(   183.22) },
      { SIMDE_FLOAT32_C(    -2.21), SIMDE_FLOAT32_C( -1112.90), SIMDE_FLOAT32_C(  1661.10), SIMDE_FLOAT32_C(   186.55) } },
    { { SIMDE_FLOAT32_C(  -441.33), SIMDE_FLOAT32_C(   904.82), SIMDE_FLOAT32_C(  -223.31), SIMDE_FLOAT32_C(   449.20) },
      { SIMDE_FLOAT32_C(  -147.11), SIMDE_FLOAT32_C(    90.74), SIMDE_FLOAT32_C(  -496.16), SIMDE_FLOAT32_C(  -908.40) },
      { SIMDE_FLOAT32_C(  -294.22), SIMDE_FLOAT32_C(   814.08), SIMDE_FLOAT32_C(   272.85), SIMDE_FLOAT32_C(  1357.61) } },
    { { SIMDE_FLOAT32_C(   364.49), SIMDE_FLOAT32_C(  -189.62), SIMDE_FLOAT32_C(   357.48), SIMDE_FLOAT32_C(   105.03) },
      { SIMDE_FLOAT32_C(  -362.94), SIMDE_FLOAT32_C(  -939.08), SIMDE_FLOAT32_C(  -929.19), SIMDE_FLOAT32_C(  -574.73) },
      { SIMDE_FLOAT32_C(   727.43), SIMDE_FLOAT32_C(   749.46), SIMDE_FLOAT32_C(  1286.67), SIMDE_FLOAT32_C(   679.76) } },
    { { SIMDE_FLOAT32_C(   967.28), SIMDE_FLOAT32_C(  -219.41), SIMDE_FLOAT32_C(   464.05), SIMDE_FLOAT32_C(   659.39) },
      { SIMDE_FLOAT32_C(  -549.43), SIMDE_FLOAT32_C(  -452.53), SIMDE_FLOAT32_C(  -335.15), SIMDE_FLOAT32_C(   251.51) },
      { SIMDE_FLOAT32_C(  1516.71), SIMDE_FLOAT32_C(   233.11), SIMDE_FLOAT32_C(   799.20), SIMDE_FLOAT32_C(   407.88) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vsubq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vsubq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   188.91), SIMDE_FLOAT64_C(  -553.99) },
      { SIMDE_FLOAT64_C(  -378.72), SIMDE_FLOAT64_C(   992.06) },
      { SIMDE_FLOAT64_C(   567.63), SIMDE_FLOAT64_C( -1546.05) } },
    { { SIMDE_FLOAT64_C(  -799.65), SIMDE_FLOAT64_C(  -258.66) },
      { SIMDE_FLOAT64_C(   175.28), SIMDE_FLOAT64_C(  -240.98) },
      { SIMDE_FLOAT64_C(  -974.93), SIMDE_FLOAT64_C(   -17.68) } },
    { { SIMDE_FLOAT64_C(  -353.84), SIMDE_FLOAT64_C(   951.96) },
      { SIMDE_FLOAT64_C(  -791.78), SIMDE_FLOAT64_C(   499.05) },
      { SIMDE_FLOAT64_C(   437.94), SIMDE_FLOAT64_C(   452.91) } },
    { { SIMDE_FLOAT64_C(    42.70), SIMDE_FLOAT64_C(  -287.94) },
      { SIMDE_FLOAT64_C(   590.65), SIMDE_FLOAT64_C(  -592.80) },
      { SIMDE_FLOAT64_C(  -547.94), SIMDE_FLOAT64_C(   304.86) } },
    { { SIMDE_FLOAT64_C(   522.44), SIMDE_FLOAT64_C(   -51.88) },
      { SIMDE_FLOAT64_C(   512.22), SIMDE_FLOAT64_C(  -840.50) },
      { SIMDE_FLOAT64_C(    10.21), SIMDE_FLOAT64_C(   788.62) } },
    { { SIMDE_FLOAT64_C(     9.04), SIMDE_FLOAT64_C(   583.04) },
      { SIMDE_FLOAT64_C(  -415.23), SIMDE_FLOAT64_C(   -23.68) },
      { SIMDE_FLOAT64_C(   424.27), SIMDE_FLOAT64_C(   606.72) } },
    { { SIMDE_FLOAT64_C(  -636.38), SIMDE_FLOAT64_C(  -951.18) },
      { SIMDE_FLOAT64_C(  -364.30), SIMDE_FLOAT64_C(  -185.81) },
      { SIMDE_FLOAT64_C(  -272.08), SIMDE_FLOAT64_C(  -765.37) } },
    { { SIMDE_FLOAT64_C(  -403.71), SIMDE_FLOAT64_C(   300.55) },
      { SIMDE_FLOAT64_C(  -934.30), SIMDE_FLOAT64_C(   785.21) },
      { SIMDE_FLOAT64_C(   530.59), SIMDE_FLOAT64_C(  -484.65) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vsubq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vsubq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  49),  INT8_C(  77),  INT8_C(   3), -INT8_C( 119),  INT8_C(  60),  INT8_C(   2), -INT8_C(  57), -INT8_C(  36),
         INT8_C(  62), -INT8_C( 100),  INT8_C(  15),  INT8_C( 100),  INT8_C(  13),  INT8_C(  79), -INT8_C(  52),  INT8_C(  90) },
      { -INT8_C(  83),  INT8_C( 119), -INT8_C(  39),  INT8_C(  82),  INT8_C( 122),  INT8_C( 105), -INT8_C(  39),  INT8_C(  96),
         INT8_C(  58),  INT8_C( 116), -INT8_C(  80), -INT8_C( 127), -INT8_C(  85),  INT8_C(  24), -INT8_C( 118), -INT8_C(  35) },
      { -INT8_C( 124), -INT8_C(  42),  INT8_C(  42),  INT8_C(  55), -INT8_C(  62), -INT8_C( 103), -INT8_C(  18),  INT8_C( 124),
         INT8_C(   4),  INT8_C(  40),  INT8_C(  95), -INT8_C(  29),  INT8_C(  98),  INT8_C(  55),  INT8_C(  66),  INT8_C( 125) } },
    { {  INT8_C( 101), -INT8_C( 115),  INT8_C( 102), -INT8_C(  94), -INT8_C( 113),  INT8_C(  46),  INT8_C( 126), -INT8_C(  50),
        -INT8_C(  54), -INT8_C( 115),  INT8_C(  50), -INT8_C(  40), -INT8_C(  35), -INT8_C(   2),  INT8_C(  50), -INT8_C( 118) },
      {  INT8_C( 117),  INT8_C(  11), -INT8_C(  35), -INT8_C(  17),  INT8_C( 116), -INT8_C(  74),  INT8_C(  79), -INT8_C(  82),
         INT8_C(  42), -INT8_C(   1),  INT8_C(  47), -INT8_C(  42),  INT8_C(  23), -INT8_C(  70), -INT8_C(  77),  INT8_C( 125) },
      { -INT8_C(  16), -INT8_C( 126), -INT8_C( 119), -INT8_C(  77),  INT8_C(  27),  INT8_C( 120),  INT8_C(  47),  INT8_C(  32),
        -INT8_C(  96), -INT8_C( 114),  INT8_C(   3),  INT8_C(   2), -INT8_C(  58),  INT8_C(  68),     INT8_MAX,  INT8_C(  13) } },
    { {  INT8_C(  71),  INT8_C(  25),  INT8_C(  31), -INT8_C(  41),  INT8_C(  71), -INT8_C(  99), -INT8_C(  91),  INT8_C(  18),
         INT8_C(  42), -INT8_C(  41), -INT8_C(  22),  INT8_C(   7), -INT8_C(  43),  INT8_C(  28), -INT8_C( 110),  INT8_C(  74) },
      {  INT8_C(  39),  INT8_C( 111),  INT8_C(  57), -INT8_C( 101),  INT8_C(  37), -INT8_C( 120),  INT8_C(  73),  INT8_C(  80),
        -INT8_C( 120),  INT8_C( 121),  INT8_C(  38), -INT8_C(  97),  INT8_C(  51), -INT8_C(  39),  INT8_C(  28),  INT8_C( 122) },
      {  INT8_C(  32), -INT8_C(  86), -INT8_C(  26),  INT8_C(  60),  INT8_C(  34),  INT8_C(  21),  INT8_C(  92), -INT8_C(  62),
        -INT8_C(  94),  INT8_C(  94), -INT8_C(  60),  INT8_C( 104), -INT8_C(  94),  INT8_C(  67),  INT8_C( 118), -INT8_C(  48) } },
    { { -INT8_C(  14),  INT8_C(  59),  INT8_C(  81),  INT8_C(  58), -INT8_C(  40), -INT8_C(  10),  INT8_C(  76),  INT8_C(   3),
        -INT8_C(  51),  INT8_C(  54),  INT8_C(  10), -INT8_C(  94),  INT8_C(  82), -INT8_C( 100), -INT8_C(  20),  INT8_C( 121) },
      {  INT8_C(  11),  INT8_C(  37),  INT8_C(  20),  INT8_C(  49), -INT8_C(  82),  INT8_C(  93), -INT8_C( 127),  INT8_C(  54),
        -INT8_C(  42), -INT8_C(  89), -INT8_C(  43),  INT8_C(   9),     INT8_MIN, -INT8_C(  14), -INT8_C( 124),  INT8_C( 114) },
      { -INT8_C(  25),  INT8_C(  22),  INT8_C(  61),  INT8_C(   9),  INT8_C(  42), -INT8_C( 103), -INT8_C(  53), -INT8_C(  51),
        -INT8_C(   9), -INT8_C( 113),  INT8_C(  53), -INT8_C( 103), -INT8_C(  46), -INT8_C(  86),  INT8_C( 104),  INT8_C(   7) } },
    { {  INT8_C(  45), -INT8_C(  43), -INT8_C(  84),  INT8_C(   6), -INT8_C(  52), -INT8_C(   8),  INT8_C(   9), -INT8_C( 103),
         INT8_C(  46),  INT8_C(  19),  INT8_C(  60),     INT8_MIN, -INT8_C(  80),  INT8_C(  40), -INT8_C(   7), -INT8_C(  69) },
      {  INT8_C(  78),  INT8_C(  13), -INT8_C(  20), -INT8_C(   4),  INT8_C( 107),  INT8_C( 109),  INT8_C(  50),  INT8_C(  65),
         INT8_C(  20),  INT8_C(   7),  INT8_C(  75), -INT8_C( 108), -INT8_C(   7), -INT8_C(  49),  INT8_C(   7),  INT8_C(  39) },
      { -INT8_C(  33), -INT8_C(  56), -INT8_C(  64),  INT8_C(  10),  INT8_C(  97), -INT8_C( 117), -INT8_C(  41),  INT8_C(  88),
         INT8_C(  26),  INT8_C(  12), -INT8_C(  15), -INT8_C(  20), -INT8_C(  73),  INT8_C(  89), -INT8_C(  14), -INT8_C( 108) } },
    { { -INT8_C(  92), -INT8_C(  77),  INT8_C(  45),  INT8_C( 112), -INT8_C(  84),  INT8_C(  54),  INT8_C(  10), -INT8_C(  38),
         INT8_C(  73),  INT8_C(  70),  INT8_C(  91), -INT8_C(   7),  INT8_C( 110),  INT8_C(  84), -INT8_C(  75), -INT8_C(  68) },
      {  INT8_C(  98), -INT8_C(  95), -INT8_C(  72), -INT8_C(  51),  INT8_C(  15), -INT8_C(  22),  INT8_C(  14),  INT8_C(  35),
        -INT8_C(  14),  INT8_C(  89), -INT8_C(  72), -INT8_C(  21),  INT8_C(  40), -INT8_C(  65),  INT8_C(  18), -INT8_C(  51) },
      {  INT8_C(  66),  INT8_C(  18),  INT8_C( 117), -INT8_C(  93), -INT8_C(  99),  INT8_C(  76), -INT8_C(   4), -INT8_C(  73),
         INT8_C(  87), -INT8_C(  19), -INT8_C(  93),  INT8_C(  14),  INT8_C(  70), -INT8_C( 107), -INT8_C(  93), -INT8_C(  17) } },
    { {  INT8_C( 114),  INT8_C(  63),  INT8_C(  61),  INT8_C(  30),  INT8_C( 117),  INT8_C(  71), -INT8_C(   7), -INT8_C(  65),
        -INT8_C( 115),  INT8_C(  84), -INT8_C(  72), -INT8_C(   4), -INT8_C(  88),  INT8_C( 109), -INT8_C(  72),  INT8_C(  10) },
      {  INT8_C(  15),  INT8_C( 113), -INT8_C(  41),  INT8_C(  30),  INT8_C(  91), -INT8_C(  26),  INT8_C(  65),  INT8_C(  77),
         INT8_C(  63), -INT8_C(   7),  INT8_C(  57),  INT8_C( 104), -INT8_C(  72),  INT8_C(  75),  INT8_C(  53),  INT8_C(  43) },
      {  INT8_C(  99), -INT8_C(  50),  INT8_C( 102),  INT8_C(   0),  INT8_C(  26),  INT8_C(  97), -INT8_C(  72),  INT8_C( 114),
         INT8_C(  78),  INT8_C(  91),     INT8_MAX, -INT8_C( 108), -INT8_C(  16),  INT8_C(  34), -INT8_C( 125), -INT8_C(  33) } },
    { { -INT8_C( 117),  INT8_C( 114),  INT8_C(  73),  INT8_C(   0), -INT8_C(  70),  INT8_C(  66), -INT8_C(  65),  INT8_C(  71),
        -INT8_C( 106),  INT8_C( 120),  INT8_C(  67),  INT8_C(  63), -INT8_C(  27), -INT8_C(   4),  INT8_C(  73), -INT8_C(  12) },
      {  INT8_C( 109),  INT8_C(  33),  INT8_C(  18), -INT8_C(  56),  INT8_C(   7),  INT8_C(  84),  INT8_C(  22),  INT8_C(  70),
         INT8_C(  77),  INT8_C(  79), -INT8_C(  82),  INT8_C(   6), -INT8_C( 102), -INT8_C(  29),  INT8_C(  49),  INT8_C(  37) },
      {  INT8_C(  30),  INT8_C(  81),  INT8_C(  55),  INT8_C(  56), -INT8_C(  77), -INT8_C(  18), -INT8_C(  87),  INT8_C(   1),
         INT8_C(  73),  INT8_C(  41), -INT8_C( 107),  INT8_C(  57),  INT8_C(  75),  INT8_C(  25),  INT8_C(  24), -INT8_C(  49) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vsubq_s8(a, b);
    
    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsubq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 31318),  INT16_C(  4134), -INT16_C(  6723),  INT16_C( 21335), -INT16_C( 25763),  INT16_C( 17298), -INT16_C(  9065),  INT16_C(  1079) },
      {  INT16_C( 19197),  INT16_C(  1228), -INT16_C(  7522), -INT16_C(  5302), -INT16_C(  1743), -INT16_C( 13071),  INT16_C(  8924),  INT16_C( 13041) },
      {  INT16_C( 12121),  INT16_C(  2906),  INT16_C(   799),  INT16_C( 26637), -INT16_C( 24020),  INT16_C( 30369), -INT16_C( 17989), -INT16_C( 11962) } },
    { {  INT16_C(  6045),  INT16_C( 23106), -INT16_C( 25859),  INT16_C( 23213),  INT16_C( 16437), -INT16_C( 13155), -INT16_C( 10980),  INT16_C(  6608) },
      { -INT16_C( 25569), -INT16_C( 17123),  INT16_C( 26495), -INT16_C( 20312), -INT16_C( 26016),  INT16_C( 15740),  INT16_C( 28348),  INT16_C( 22895) },
      {  INT16_C( 31614), -INT16_C( 25307),  INT16_C( 13182), -INT16_C( 22011), -INT16_C( 23083), -INT16_C( 28895),  INT16_C( 26208), -INT16_C( 16287) } },
    { { -INT16_C( 19835), -INT16_C( 32077),  INT16_C( 24908), -INT16_C( 32291),  INT16_C( 31393), -INT16_C( 17075),  INT16_C(  7503),  INT16_C( 28374) },
      { -INT16_C(  3143),  INT16_C( 14379), -INT16_C( 11174), -INT16_C( 17431),  INT16_C( 25966),  INT16_C( 11000),  INT16_C( 26579),  INT16_C( 22916) },
      { -INT16_C( 16692),  INT16_C( 19080), -INT16_C( 29454), -INT16_C( 14860),  INT16_C(  5427), -INT16_C( 28075), -INT16_C( 19076),  INT16_C(  5458) } },
    { {  INT16_C( 14105),  INT16_C( 26075), -INT16_C( 18280),  INT16_C( 14822),  INT16_C( 13107), -INT16_C( 32010), -INT16_C( 13232),  INT16_C(  2801) },
      {  INT16_C(  7359),  INT16_C(  6722),  INT16_C( 11248),  INT16_C( 24277), -INT16_C( 12911),  INT16_C( 25737),  INT16_C(  3380),  INT16_C( 20157) },
      {  INT16_C(  6746),  INT16_C( 19353), -INT16_C( 29528), -INT16_C(  9455),  INT16_C( 26018),  INT16_C(  7789), -INT16_C( 16612), -INT16_C( 17356) } },
    { { -INT16_C( 26300), -INT16_C(  8781), -INT16_C( 26031), -INT16_C( 31722),  INT16_C(  3533),  INT16_C(  7687), -INT16_C(  1831), -INT16_C( 26328) },
      {  INT16_C( 27156),  INT16_C(  1459), -INT16_C( 30570),  INT16_C( 10083), -INT16_C(  5035), -INT16_C( 30325),  INT16_C( 18937),  INT16_C( 16087) },
      {  INT16_C( 12080), -INT16_C( 10240),  INT16_C(  4539),  INT16_C( 23731),  INT16_C(  8568), -INT16_C( 27524), -INT16_C( 20768),  INT16_C( 23121) } },
    { { -INT16_C( 29726),  INT16_C( 13083),  INT16_C( 12581), -INT16_C(  3400), -INT16_C( 16578),  INT16_C(  6160),  INT16_C( 14519), -INT16_C( 13391) },
      {  INT16_C( 25763),  INT16_C( 14800),  INT16_C( 13548),  INT16_C( 16736), -INT16_C(  5344),  INT16_C(  6858), -INT16_C( 24012),  INT16_C(  5720) },
      {  INT16_C( 10047), -INT16_C(  1717), -INT16_C(   967), -INT16_C( 20136), -INT16_C( 11234), -INT16_C(   698), -INT16_C( 27005), -INT16_C( 19111) } },
    { {  INT16_C( 29485),  INT16_C( 21066),  INT16_C(   676), -INT16_C(  7356),  INT16_C( 21953),  INT16_C( 30971), -INT16_C( 21363),  INT16_C( 12355) },
      {  INT16_C(  5136), -INT16_C(   919), -INT16_C( 14008),  INT16_C( 26685),  INT16_C(  1973), -INT16_C(  5758), -INT16_C(  9559), -INT16_C( 10752) },
      {  INT16_C( 24349),  INT16_C( 21985),  INT16_C( 14684),  INT16_C( 31495),  INT16_C( 19980), -INT16_C( 28807), -INT16_C( 11804),  INT16_C( 23107) } },
    { {  INT16_C( 19021), -INT16_C(  3544),  INT16_C( 27980),  INT16_C(  3541), -INT16_C( 12094),  INT16_C( 20357), -INT16_C( 14212), -INT16_C( 29568) },
      { -INT16_C(  5668),  INT16_C(  9352), -INT16_C( 14925),  INT16_C( 26765),  INT16_C(  4044),  INT16_C( 30289),  INT16_C( 20970),  INT16_C( 14156) },
      {  INT16_C( 24689), -INT16_C( 12896), -INT16_C( 22631), -INT16_C( 23224), -INT16_C( 16138), -INT16_C(  9932),  INT16_C( 30354),  INT16_C( 21812) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vsubq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsubq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   416713317), -INT32_C(  1527447838),  INT32_C(  1257470414),  INT32_C(   517370690) },
      {  INT32_C(   272850525), -INT32_C(   260517853), -INT32_C(   916010529), -INT32_C(  1241402853) },
      { -INT32_C(   689563842), -INT32_C(  1266929985), -INT32_C(  2121486353),  INT32_C(  1758773543) } },
    { {  INT32_C(   161360423), -INT32_C(   139619799),  INT32_C(  1312989452),  INT32_C(  1902909460) },
      { -INT32_C(  1702776969),  INT32_C(  1602943359), -INT32_C(   567742269), -INT32_C(   896259677) },
      {  INT32_C(  1864137392), -INT32_C(  1742563158),  INT32_C(  1880731721), -INT32_C(  1495798159) } },
    { {  INT32_C(  2111058516), -INT32_C(   780893755),  INT32_C(   924825122),  INT32_C(  1185450959) },
      { -INT32_C(  1159714245), -INT32_C(   434541789), -INT32_C(    20692389), -INT32_C(  1077323413) },
      { -INT32_C(  1024194535), -INT32_C(   346351966),  INT32_C(   945517511), -INT32_C(  2032192924) } },
    { {  INT32_C(  1346149771),  INT32_C(  1092727070),  INT32_C(   913850471),  INT32_C(   125575372) },
      {  INT32_C(  1858166090),  INT32_C(   592763848), -INT32_C(  2011031267), -INT32_C(    45552782) },
      { -INT32_C(   512016319),  INT32_C(   499963222), -INT32_C(  1370085558),  INT32_C(   171128154) } },
    { { -INT32_C(  1504803704), -INT32_C(  1645777099),  INT32_C(  2094227376), -INT32_C(   897363840) },
      {  INT32_C(  1966621869),  INT32_C(  1016630559),  INT32_C(   415611558),  INT32_C(   756354469) },
      {  INT32_C(   823541723),  INT32_C(  1632559638),  INT32_C(  1678615818), -INT32_C(  1653718309) } },
    { { -INT32_C(   942382191), -INT32_C(  2090550317), -INT32_C(  1677773029),  INT32_C(   879067783) },
      { -INT32_C(   425091386), -INT32_C(   786283989), -INT32_C(  1561729028), -INT32_C(  2033189132) },
      { -INT32_C(   517290805), -INT32_C(  1304266328), -INT32_C(   116044001), -INT32_C(  1382710381) } },
    { {  INT32_C(   894280546),  INT32_C(  2058924383),  INT32_C(  1880471528), -INT32_C(     5998023) },
      {  INT32_C(  1139101208), -INT32_C(  1944844144), -INT32_C(   466682385),  INT32_C(  1584070396) },
      { -INT32_C(   244820662), -INT32_C(   291198769), -INT32_C(  1947813383), -INT32_C(  1590068419) } },
    { {  INT32_C(     9680801),  INT32_C(  1350191976),  INT32_C(  1002475266),  INT32_C(   574252298) },
      {  INT32_C(  1130766515),  INT32_C(   399473192),  INT32_C(  1962671736), -INT32_C(  1647155716) },
      { -INT32_C(  1121085714),  INT32_C(   950718784), -INT32_C(   960196470), -INT32_C(  2073559282) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vsubq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsubq_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 5560511018500725476), -INT64_C( 5921063652388137560) },
      {  INT64_C( 3280802739062323783),  INT64_C(  312846142526292670) },
      { -INT64_C( 8841313757563049259), -INT64_C( 6233909794914430230) } },
    { { -INT64_C( 5315832993644153384), -INT64_C( 7594410036925290509) },
      {  INT64_C(  745781472090492023),  INT64_C( 5042654366893668879) },
      { -INT64_C( 6061614465734645407),  INT64_C( 5809679669890592228) } },
    { { -INT64_C( 2966456111776037871), -INT64_C( 1147749979637138130) },
      { -INT64_C( 5530009519274583829),  INT64_C( 3612351040494110063) },
      {  INT64_C( 2563553407498545958), -INT64_C( 4760101020131248193) } },
    { {  INT64_C( 2585953444973112874), -INT64_C(  950908203764242589) },
      { -INT64_C( 3593191495057151542), -INT64_C( 7078589392559026832) },
      {  INT64_C( 6179144940030264416),  INT64_C( 6127681188794784243) } },
    { { -INT64_C( 7073873831480650565), -INT64_C( 1068119307084729292) },
      {  INT64_C( 3629482117552952880), -INT64_C( 8043279582318360241) },
      {  INT64_C( 7743388124675948171),  INT64_C( 6975160275233630949) } },
    { { -INT64_C( 3714601521476728165),  INT64_C( 7322910394983902601) },
      { -INT64_C( 3279092754793889653),  INT64_C( 7260354318767047259) },
      { -INT64_C(  435508766682838512),  INT64_C(   62556076216855342) } },
    { { -INT64_C( 6889190113625373953),  INT64_C( 3113659290876930971) },
      { -INT64_C( 2934387092794955279), -INT64_C( 3430112546453398728) },
      { -INT64_C( 3954803020830418674),  INT64_C( 6543771837330329699) } },
    { { -INT64_C( 1619946426246651700), -INT64_C( 5331436475357998025) },
      { -INT64_C( 6382884422338053864),  INT64_C(  787019694814557260) },
      {  INT64_C( 4762937996091402164), -INT64_C( 6118456170172555285) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vsubq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsubq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 46), UINT8_C(195), UINT8_C( 10), UINT8_C(219), UINT8_C(166), UINT8_C( 78), UINT8_C(182), UINT8_C(237),
        UINT8_C(213), UINT8_C(145), UINT8_C( 21), UINT8_C(119), UINT8_C(125), UINT8_C(251), UINT8_C( 49), UINT8_C(192) },
      { UINT8_C( 82), UINT8_C(167), UINT8_C( 39), UINT8_C(113), UINT8_C( 53), UINT8_C(  0), UINT8_C(195), UINT8_C( 43),
        UINT8_C( 66), UINT8_C(194), UINT8_C( 13), UINT8_C(182), UINT8_C( 87), UINT8_C( 48), UINT8_C( 39), UINT8_C(134) },
      { UINT8_C(220), UINT8_C( 28), UINT8_C(227), UINT8_C(106), UINT8_C(113), UINT8_C( 78), UINT8_C(243), UINT8_C(194),
        UINT8_C(147), UINT8_C(207), UINT8_C(  8), UINT8_C(193), UINT8_C( 38), UINT8_C(203), UINT8_C( 10), UINT8_C( 58) } },
    { { UINT8_C(243), UINT8_C( 49), UINT8_C( 97), UINT8_C(154), UINT8_C(127), UINT8_C( 23), UINT8_C(135), UINT8_C( 84),
        UINT8_C(169), UINT8_C(156), UINT8_C(203), UINT8_C( 38), UINT8_C(152), UINT8_C(252), UINT8_C(231), UINT8_C(234) },
      { UINT8_C(163), UINT8_C( 14), UINT8_C( 91), UINT8_C(217), UINT8_C( 15), UINT8_C( 30), UINT8_C(  4), UINT8_C( 81),
        UINT8_C(225), UINT8_C( 17), UINT8_C(  7), UINT8_C( 56), UINT8_C( 65), UINT8_C( 46), UINT8_C(190), UINT8_C( 53) },
      { UINT8_C( 80), UINT8_C( 35), UINT8_C(  6), UINT8_C(193), UINT8_C(112), UINT8_C(249), UINT8_C(131), UINT8_C(  3),
        UINT8_C(200), UINT8_C(139), UINT8_C(196), UINT8_C(238), UINT8_C( 87), UINT8_C(206), UINT8_C( 41), UINT8_C(181) } },
    { { UINT8_C( 95), UINT8_C( 32), UINT8_C(207), UINT8_C(223), UINT8_C( 55), UINT8_C( 86), UINT8_C( 51), UINT8_C(224),
        UINT8_C(243),    UINT8_MAX, UINT8_C(  7), UINT8_C(139), UINT8_C(251), UINT8_C(238), UINT8_C(117), UINT8_C(159) },
      { UINT8_C(252), UINT8_C(208), UINT8_C(120), UINT8_C( 11), UINT8_C(238), UINT8_C(124), UINT8_C( 93), UINT8_C(207),
        UINT8_C(141), UINT8_C(100), UINT8_C(  8), UINT8_C(206), UINT8_C(147), UINT8_C(198), UINT8_C(  3), UINT8_C(242) },
      { UINT8_C( 99), UINT8_C( 80), UINT8_C( 87), UINT8_C(212), UINT8_C( 73), UINT8_C(218), UINT8_C(214), UINT8_C( 17),
        UINT8_C(102), UINT8_C(155),    UINT8_MAX, UINT8_C(189), UINT8_C(104), UINT8_C( 40), UINT8_C(114), UINT8_C(173) } },
    { { UINT8_C(230), UINT8_C(210), UINT8_C(209), UINT8_C( 30), UINT8_C( 41), UINT8_C(  5), UINT8_C(254), UINT8_C( 28),
        UINT8_C(  4), UINT8_C(  5), UINT8_C(167),    UINT8_MAX, UINT8_C(243), UINT8_C( 28), UINT8_C(158), UINT8_C(240) },
      { UINT8_C(236), UINT8_C( 22), UINT8_C(251), UINT8_C(218), UINT8_C(146), UINT8_C( 88), UINT8_C(170), UINT8_C( 31),
        UINT8_C(189), UINT8_C(178), UINT8_C(238), UINT8_C( 80), UINT8_C(120), UINT8_C(241), UINT8_C( 66), UINT8_C( 95) },
      { UINT8_C(250), UINT8_C(188), UINT8_C(214), UINT8_C( 68), UINT8_C(151), UINT8_C(173), UINT8_C( 84), UINT8_C(253),
        UINT8_C( 71), UINT8_C( 83), UINT8_C(185), UINT8_C(175), UINT8_C(123), UINT8_C( 43), UINT8_C( 92), UINT8_C(145) } },
    { { UINT8_C(196), UINT8_C( 20), UINT8_C(125), UINT8_C(237), UINT8_C( 25), UINT8_C(123), UINT8_C(  9), UINT8_C( 29),
        UINT8_C(129), UINT8_C(176), UINT8_C( 28), UINT8_C(116), UINT8_C(204), UINT8_C(187), UINT8_C(100), UINT8_C(184) },
      { UINT8_C(209), UINT8_C( 96), UINT8_C(146), UINT8_C(100), UINT8_C(184), UINT8_C( 60), UINT8_C(131), UINT8_C(117),
        UINT8_C(238), UINT8_C(113), UINT8_C(197), UINT8_C(103), UINT8_C( 99), UINT8_C(  8), UINT8_C(198), UINT8_C( 39) },
      { UINT8_C(243), UINT8_C(180), UINT8_C(235), UINT8_C(137), UINT8_C( 97), UINT8_C( 63), UINT8_C(134), UINT8_C(168),
        UINT8_C(147), UINT8_C( 63), UINT8_C( 87), UINT8_C( 13), UINT8_C(105), UINT8_C(179), UINT8_C(158), UINT8_C(145) } },
    { { UINT8_C( 28), UINT8_C( 67), UINT8_C( 20), UINT8_C( 53), UINT8_C(190), UINT8_C( 29), UINT8_C( 82), UINT8_C( 63),
        UINT8_C(205), UINT8_C(110), UINT8_C(180), UINT8_C(153), UINT8_C( 41), UINT8_C( 24), UINT8_C( 81), UINT8_C(251) },
      { UINT8_C(120), UINT8_C(227), UINT8_C( 95), UINT8_C( 49), UINT8_C( 32), UINT8_C(226), UINT8_C(166), UINT8_C( 14),
        UINT8_C( 84), UINT8_C(108), UINT8_C(117), UINT8_C(183), UINT8_C(116), UINT8_C( 59), UINT8_C(222), UINT8_C(144) },
      { UINT8_C(164), UINT8_C( 96), UINT8_C(181), UINT8_C(  4), UINT8_C(158), UINT8_C( 59), UINT8_C(172), UINT8_C( 49),
        UINT8_C(121), UINT8_C(  2), UINT8_C( 63), UINT8_C(226), UINT8_C(181), UINT8_C(221), UINT8_C(115), UINT8_C(107) } },
    { { UINT8_C(126), UINT8_C(242), UINT8_C(197), UINT8_C( 61), UINT8_C( 15), UINT8_C( 23), UINT8_C(124), UINT8_C(220),
        UINT8_C(133), UINT8_C( 48), UINT8_C(117), UINT8_C(175), UINT8_C( 73), UINT8_C(198), UINT8_C(170), UINT8_C(193) },
      { UINT8_C(169), UINT8_C(  9), UINT8_C(242), UINT8_C(201), UINT8_C(235), UINT8_C(153), UINT8_C(216), UINT8_C( 63),
        UINT8_C(  5), UINT8_C( 77), UINT8_C(246), UINT8_C(121), UINT8_C(137), UINT8_C(212), UINT8_C(  9), UINT8_C(  7) },
      { UINT8_C(213), UINT8_C(233), UINT8_C(211), UINT8_C(116), UINT8_C( 36), UINT8_C(126), UINT8_C(164), UINT8_C(157),
        UINT8_C(128), UINT8_C(227), UINT8_C(127), UINT8_C( 54), UINT8_C(192), UINT8_C(242), UINT8_C(161), UINT8_C(186) } },
    { { UINT8_C(198), UINT8_C(206), UINT8_C( 68), UINT8_C(213), UINT8_C(229), UINT8_C(193), UINT8_C(177), UINT8_C(106),
        UINT8_C(241), UINT8_C( 38), UINT8_C( 25), UINT8_C( 58), UINT8_C(236), UINT8_C(195), UINT8_C(252), UINT8_C(150) },
      { UINT8_C(204), UINT8_C(238), UINT8_C( 95), UINT8_C(184), UINT8_C(135), UINT8_C( 55), UINT8_C(247), UINT8_C(140),
        UINT8_C(133), UINT8_C(238), UINT8_C(  5), UINT8_C( 14), UINT8_C(194), UINT8_C( 14), UINT8_C( 21), UINT8_C(137) },
      { UINT8_C(250), UINT8_C(224), UINT8_C(229), UINT8_C( 29), UINT8_C( 94), UINT8_C(138), UINT8_C(186), UINT8_C(222),
        UINT8_C(108), UINT8_C( 56), UINT8_C( 20), UINT8_C( 44), UINT8_C( 42), UINT8_C(181), UINT8_C(231), UINT8_C( 13) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vsubq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsubq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(43750), UINT16_C(51981), UINT16_C(43836), UINT16_C(49690), UINT16_C(27185), UINT16_C(26458), UINT16_C(47312), UINT16_C(58715) },
      { UINT16_C( 9265), UINT16_C(46000), UINT16_C(44438), UINT16_C( 9529), UINT16_C(38462), UINT16_C(62869), UINT16_C(57124), UINT16_C( 2719) },
      { UINT16_C(34485), UINT16_C( 5981), UINT16_C(64934), UINT16_C(40161), UINT16_C(54259), UINT16_C(29125), UINT16_C(55724), UINT16_C(55996) } },
    { { UINT16_C(44170), UINT16_C(50902), UINT16_C(61527), UINT16_C(34952), UINT16_C(57946), UINT16_C(11248), UINT16_C(19354), UINT16_C(52240) },
      { UINT16_C(49519), UINT16_C( 1407), UINT16_C(47214), UINT16_C(44331), UINT16_C(49231), UINT16_C(29602), UINT16_C(16800), UINT16_C(10877) },
      { UINT16_C(60187), UINT16_C(49495), UINT16_C(14313), UINT16_C(56157), UINT16_C( 8715), UINT16_C(47182), UINT16_C( 2554), UINT16_C(41363) } },
    { { UINT16_C(21485), UINT16_C(17648), UINT16_C(30787), UINT16_C(40653), UINT16_C(48474), UINT16_C(62665), UINT16_C(55560), UINT16_C(30656) },
      { UINT16_C(16282), UINT16_C( 2429), UINT16_C(43256), UINT16_C(18358), UINT16_C(22632), UINT16_C( 2234), UINT16_C(14233), UINT16_C(34354) },
      { UINT16_C( 5203), UINT16_C(15219), UINT16_C(53067), UINT16_C(22295), UINT16_C(25842), UINT16_C(60431), UINT16_C(41327), UINT16_C(61838) } },
    { { UINT16_C( 8843), UINT16_C(52938), UINT16_C(38810), UINT16_C(62572), UINT16_C(13652), UINT16_C(23785), UINT16_C(43279), UINT16_C(43476) },
      { UINT16_C(20969), UINT16_C(57778), UINT16_C(26873), UINT16_C(24872), UINT16_C(58048), UINT16_C(22890), UINT16_C(39961), UINT16_C(42207) },
      { UINT16_C(53410), UINT16_C(60696), UINT16_C(11937), UINT16_C(37700), UINT16_C(21140), UINT16_C(  895), UINT16_C( 3318), UINT16_C( 1269) } },
    { { UINT16_C(43711), UINT16_C(22899), UINT16_C(57153), UINT16_C(38478), UINT16_C(14101), UINT16_C( 9458), UINT16_C(50912), UINT16_C(51661) },
      { UINT16_C(32791), UINT16_C( 4266), UINT16_C(53992), UINT16_C(43378), UINT16_C(56500), UINT16_C(52738), UINT16_C(57976), UINT16_C(14194) },
      { UINT16_C(10920), UINT16_C(18633), UINT16_C( 3161), UINT16_C(60636), UINT16_C(23137), UINT16_C(22256), UINT16_C(58472), UINT16_C(37467) } },
    { { UINT16_C(58764), UINT16_C(52625), UINT16_C(57285), UINT16_C(55907), UINT16_C(22038), UINT16_C(63230), UINT16_C(51996), UINT16_C(13504) },
      { UINT16_C(27211), UINT16_C(13380), UINT16_C(46653), UINT16_C(61917), UINT16_C(57234), UINT16_C( 3007), UINT16_C(12993), UINT16_C(19778) },
      { UINT16_C(31553), UINT16_C(39245), UINT16_C(10632), UINT16_C(59526), UINT16_C(30340), UINT16_C(60223), UINT16_C(39003), UINT16_C(59262) } },
    { { UINT16_C(54039), UINT16_C(56347), UINT16_C(32434), UINT16_C(51382), UINT16_C(46292), UINT16_C(61887), UINT16_C(32640), UINT16_C(52005) },
      { UINT16_C(27113), UINT16_C( 9983), UINT16_C(56352), UINT16_C(45592), UINT16_C(55228), UINT16_C(32189), UINT16_C(    9), UINT16_C( 8651) },
      { UINT16_C(26926), UINT16_C(46364), UINT16_C(41618), UINT16_C( 5790), UINT16_C(56600), UINT16_C(29698), UINT16_C(32631), UINT16_C(43354) } },
    { { UINT16_C(59091), UINT16_C(34557), UINT16_C(46180), UINT16_C(14670), UINT16_C( 3432), UINT16_C(59434), UINT16_C(20364), UINT16_C(30388) },
      { UINT16_C(46008), UINT16_C(55452), UINT16_C(46224), UINT16_C(19595), UINT16_C(18572), UINT16_C(38345), UINT16_C(37960), UINT16_C( 7350) },
      { UINT16_C(13083), UINT16_C(44641), UINT16_C(65492), UINT16_C(60611), UINT16_C(50396), UINT16_C(21089), UINT16_C(47940), UINT16_C(23038) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vsubq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsubq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3751982202), UINT32_C(3491295336), UINT32_C(2327397118), UINT32_C(1224764817) },
      { UINT32_C(2955058464), UINT32_C(3724324177), UINT32_C(1047774965), UINT32_C(3579455834) },
      { UINT32_C( 796923738), UINT32_C(4061938455), UINT32_C(1279622153), UINT32_C(1940276279) } },
    { { UINT32_C(1169489117), UINT32_C(3927362796), UINT32_C(2675298062), UINT32_C(1558738236) },
      { UINT32_C(1678576146), UINT32_C(2906720695), UINT32_C( 720090319), UINT32_C(3154068958) },
      { UINT32_C(3785880267), UINT32_C(1020642101), UINT32_C(1955207743), UINT32_C(2699636574) } },
    { { UINT32_C( 755086145), UINT32_C(2367166335), UINT32_C( 573345254), UINT32_C( 360584194) },
      { UINT32_C(3598289695), UINT32_C(1686354581), UINT32_C(1301180015), UINT32_C(4094201267) },
      { UINT32_C(1451763746), UINT32_C( 680811754), UINT32_C(3567132535), UINT32_C( 561350223) } },
    { { UINT32_C(3206678848), UINT32_C( 105658912), UINT32_C(3374872775), UINT32_C(2900273037) },
      { UINT32_C(3347207986), UINT32_C(2167146002), UINT32_C( 684636788), UINT32_C(2283591240) },
      { UINT32_C(4154438158), UINT32_C(2233480206), UINT32_C(2690235987), UINT32_C( 616681797) } },
    { { UINT32_C(   4734688), UINT32_C(1057461368), UINT32_C(2584293133), UINT32_C( 155641814) },
      { UINT32_C(1372637247), UINT32_C(1137900750), UINT32_C(4285243575), UINT32_C(1451722614) },
      { UINT32_C(2927064737), UINT32_C(4214527914), UINT32_C(2594016854), UINT32_C(2998886496) } },
    { { UINT32_C(1045942214), UINT32_C(1904107108), UINT32_C(1678477197), UINT32_C(2909622638) },
      { UINT32_C(3908975897), UINT32_C(4046180410), UINT32_C(3891304048), UINT32_C(3812456221) },
      { UINT32_C(1431933613), UINT32_C(2152893994), UINT32_C(2082140445), UINT32_C(3392133713) } },
    { { UINT32_C(2871170119), UINT32_C(2149359858), UINT32_C(2514757415), UINT32_C(2437108088) },
      { UINT32_C(3363389838), UINT32_C(2193204242), UINT32_C(1483319610), UINT32_C(1748739873) },
      { UINT32_C(3802747577), UINT32_C(4251122912), UINT32_C(1031437805), UINT32_C( 688368215) } },
    { { UINT32_C( 773020987), UINT32_C( 615395325), UINT32_C(3468333654), UINT32_C(1902116323) },
      { UINT32_C(1346033982), UINT32_C(3100898173), UINT32_C(3188735133), UINT32_C( 522603491) },
      { UINT32_C(3721954301), UINT32_C(1809464448), UINT32_C( 279598521), UINT32_C(1379512832) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vsubq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vsubq_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(13748358714363820457), UINT64_C(13898648870508594573) },
      { UINT64_C(12464525672885328836), UINT64_C(18312639204639246880) },
      { UINT64_C( 1283833041478491621), UINT64_C(14032753739578899309) } },
    { { UINT64_C(17937679446536712393), UINT64_C( 3114038371788815349) },
      { UINT64_C( 5557555380804733029), UINT64_C(16412652075366845041) },
      { UINT64_C(12380124065731979364), UINT64_C( 5148130370131521924) } },
    { { UINT64_C(14935910925362031332), UINT64_C( 6705716878113156990) },
      { UINT64_C( 6070836784052403398), UINT64_C(16751385124290662523) },
      { UINT64_C( 8865074141309627934), UINT64_C( 8401075827532046083) } },
    { { UINT64_C( 1005286295086795850), UINT64_C( 8972016764501244205) },
      { UINT64_C(14030593306424989054), UINT64_C(18099070462252798271) },
      { UINT64_C( 5421437062371358412), UINT64_C( 9319690375957997550) } },
    { { UINT64_C( 1150971945603261276), UINT64_C( 7745832836702530379) },
      { UINT64_C(15714891553410182414), UINT64_C(11168727231119650387) },
      { UINT64_C( 3882824465902630478), UINT64_C(15023849679292431608) } },
    { { UINT64_C( 8907979534016847533), UINT64_C(11224091280831009899) },
      { UINT64_C( 7376339916272210152), UINT64_C( 8308414289197825140) },
      { UINT64_C( 1531639617744637381), UINT64_C( 2915676991633184759) } },
    { { UINT64_C(13777815640503210888), UINT64_C(10709519970759848310) },
      { UINT64_C(  784601148808531819), UINT64_C( 4623801230915620594) },
      { UINT64_C(12993214491694679069), UINT64_C( 6085718739844227716) } },
    { { UINT64_C( 5183694642829930205), UINT64_C( 5557700198912427999) },
      { UINT64_C(11536725458092243066), UINT64_C(13832107935466575868) },
      { UINT64_C(12093713258447238755), UINT64_C(10172336337155403747) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vsubq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsub_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vsubq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
