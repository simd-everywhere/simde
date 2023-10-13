#define SIMDE_TEST_ARM_NEON_INSN st1_x3
#include "test/test.h"
#include "test-neon.h"
#include "../../../simde/arm/neon/st1_x3.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst1_f16_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 val[3][4];
    simde_float16 r[12];
  } test_vec[] = {
  { { {  SIMDE_FLOAT16_VALUE( 29.597), SIMDE_FLOAT16_VALUE( -97.375), SIMDE_FLOAT16_VALUE( -37.290),  SIMDE_FLOAT16_VALUE( 83.451)  },
      {  SIMDE_FLOAT16_VALUE( 58.071),  SIMDE_FLOAT16_VALUE(  9.615), SIMDE_FLOAT16_VALUE( -92.703), SIMDE_FLOAT16_VALUE( -13.746)  },
      {  SIMDE_FLOAT16_VALUE( 82.251),  SIMDE_FLOAT16_VALUE( 31.216),  SIMDE_FLOAT16_VALUE(  5.814),  SIMDE_FLOAT16_VALUE( 14.340)  } },
      {  SIMDE_FLOAT16_VALUE( 29.597), SIMDE_FLOAT16_VALUE( -97.375), SIMDE_FLOAT16_VALUE( -37.290),  SIMDE_FLOAT16_VALUE( 83.451),
         SIMDE_FLOAT16_VALUE( 58.071),  SIMDE_FLOAT16_VALUE(  9.615), SIMDE_FLOAT16_VALUE( -92.703), SIMDE_FLOAT16_VALUE( -13.746),
         SIMDE_FLOAT16_VALUE( 82.251),  SIMDE_FLOAT16_VALUE( 31.216),  SIMDE_FLOAT16_VALUE(  5.814),  SIMDE_FLOAT16_VALUE( 14.340) } },
  { { { SIMDE_FLOAT16_VALUE( -61.888),  SIMDE_FLOAT16_VALUE( 47.875), SIMDE_FLOAT16_VALUE( -89.222),  SIMDE_FLOAT16_VALUE( 78.391)  },
      {  SIMDE_FLOAT16_VALUE(  7.891), SIMDE_FLOAT16_VALUE( -86.814),  SIMDE_FLOAT16_VALUE(  7.232),  SIMDE_FLOAT16_VALUE( 87.625)  },
      { SIMDE_FLOAT16_VALUE( -59.898),  SIMDE_FLOAT16_VALUE( 99.002),  SIMDE_FLOAT16_VALUE( 38.867), SIMDE_FLOAT16_VALUE( -11.673)  } },
      { SIMDE_FLOAT16_VALUE( -61.888),  SIMDE_FLOAT16_VALUE( 47.875), SIMDE_FLOAT16_VALUE( -89.222),  SIMDE_FLOAT16_VALUE( 78.391),
         SIMDE_FLOAT16_VALUE(  7.891), SIMDE_FLOAT16_VALUE( -86.814),  SIMDE_FLOAT16_VALUE(  7.232),  SIMDE_FLOAT16_VALUE( 87.625),
        SIMDE_FLOAT16_VALUE( -59.898),  SIMDE_FLOAT16_VALUE( 99.002),  SIMDE_FLOAT16_VALUE( 38.867), SIMDE_FLOAT16_VALUE( -11.673) } },
  { { { SIMDE_FLOAT16_VALUE( -30.571), SIMDE_FLOAT16_VALUE( -70.230),  SIMDE_FLOAT16_VALUE( 40.374), SIMDE_FLOAT16_VALUE( -20.532)  },
      { SIMDE_FLOAT16_VALUE( -53.791), SIMDE_FLOAT16_VALUE( -27.304), SIMDE_FLOAT16_VALUE( -92.472),  SIMDE_FLOAT16_VALUE( 61.997)  },
      { SIMDE_FLOAT16_VALUE( -84.356),  SIMDE_FLOAT16_VALUE( 57.986), SIMDE_FLOAT16_VALUE( -40.919),  SIMDE_FLOAT16_VALUE( 59.208)  } },
      { SIMDE_FLOAT16_VALUE( -30.571), SIMDE_FLOAT16_VALUE( -70.230),  SIMDE_FLOAT16_VALUE( 40.374), SIMDE_FLOAT16_VALUE( -20.532),
        SIMDE_FLOAT16_VALUE( -53.791), SIMDE_FLOAT16_VALUE( -27.304), SIMDE_FLOAT16_VALUE( -92.472),  SIMDE_FLOAT16_VALUE( 61.997),
        SIMDE_FLOAT16_VALUE( -84.356),  SIMDE_FLOAT16_VALUE( 57.986), SIMDE_FLOAT16_VALUE( -40.919),  SIMDE_FLOAT16_VALUE( 59.208) } },
  { { {  SIMDE_FLOAT16_VALUE( 44.416), SIMDE_FLOAT16_VALUE( -23.810), SIMDE_FLOAT16_VALUE( -15.844), SIMDE_FLOAT16_VALUE( -72.400)  },
      {  SIMDE_FLOAT16_VALUE( 39.332),  SIMDE_FLOAT16_VALUE( 94.084),  SIMDE_FLOAT16_VALUE( 69.027),  SIMDE_FLOAT16_VALUE( 27.132)  },
      { SIMDE_FLOAT16_VALUE( -53.948), SIMDE_FLOAT16_VALUE( -6.196),  SIMDE_FLOAT16_VALUE( 93.667), SIMDE_FLOAT16_VALUE( -14.595)  } },
      {  SIMDE_FLOAT16_VALUE( 44.416), SIMDE_FLOAT16_VALUE( -23.810), SIMDE_FLOAT16_VALUE( -15.844), SIMDE_FLOAT16_VALUE( -72.400),
         SIMDE_FLOAT16_VALUE( 39.332),  SIMDE_FLOAT16_VALUE( 94.084),  SIMDE_FLOAT16_VALUE( 69.027),  SIMDE_FLOAT16_VALUE( 27.132),
        SIMDE_FLOAT16_VALUE( -53.948), SIMDE_FLOAT16_VALUE( -6.196),  SIMDE_FLOAT16_VALUE( 93.667), SIMDE_FLOAT16_VALUE( -14.595) } },
  { { { SIMDE_FLOAT16_VALUE( -82.639), SIMDE_FLOAT16_VALUE( -31.640),  SIMDE_FLOAT16_VALUE( 38.749), SIMDE_FLOAT16_VALUE( -86.594)  },
      {  SIMDE_FLOAT16_VALUE( 49.953),  SIMDE_FLOAT16_VALUE( 35.426),  SIMDE_FLOAT16_VALUE( 78.108),  SIMDE_FLOAT16_VALUE( 30.009)  },
      {  SIMDE_FLOAT16_VALUE( 15.917), SIMDE_FLOAT16_VALUE( -35.664), SIMDE_FLOAT16_VALUE( -94.160), SIMDE_FLOAT16_VALUE( -24.487)  } },
      { SIMDE_FLOAT16_VALUE( -82.639), SIMDE_FLOAT16_VALUE( -31.640),  SIMDE_FLOAT16_VALUE( 38.749), SIMDE_FLOAT16_VALUE( -86.594),
         SIMDE_FLOAT16_VALUE( 49.953),  SIMDE_FLOAT16_VALUE( 35.426),  SIMDE_FLOAT16_VALUE( 78.108),  SIMDE_FLOAT16_VALUE( 30.009),
         SIMDE_FLOAT16_VALUE( 15.917), SIMDE_FLOAT16_VALUE( -35.664), SIMDE_FLOAT16_VALUE( -94.160), SIMDE_FLOAT16_VALUE( -24.487) } },
  { { { SIMDE_FLOAT16_VALUE( -53.177),  SIMDE_FLOAT16_VALUE( 32.005),  SIMDE_FLOAT16_VALUE( 86.184),  SIMDE_FLOAT16_VALUE( 76.077)  },
      {  SIMDE_FLOAT16_VALUE(  6.572), SIMDE_FLOAT16_VALUE( -52.085),  SIMDE_FLOAT16_VALUE( 48.290),  SIMDE_FLOAT16_VALUE( 75.600)  },
      {  SIMDE_FLOAT16_VALUE( 81.474), SIMDE_FLOAT16_VALUE( -76.981), SIMDE_FLOAT16_VALUE( -76.144),  SIMDE_FLOAT16_VALUE( 91.779)  } },
      { SIMDE_FLOAT16_VALUE( -53.177),  SIMDE_FLOAT16_VALUE( 32.005),  SIMDE_FLOAT16_VALUE( 86.184),  SIMDE_FLOAT16_VALUE( 76.077),
         SIMDE_FLOAT16_VALUE(  6.572), SIMDE_FLOAT16_VALUE( -52.085),  SIMDE_FLOAT16_VALUE( 48.290),  SIMDE_FLOAT16_VALUE( 75.600),
         SIMDE_FLOAT16_VALUE( 81.474), SIMDE_FLOAT16_VALUE( -76.981), SIMDE_FLOAT16_VALUE( -76.144),  SIMDE_FLOAT16_VALUE( 91.779) } },
  { { {  SIMDE_FLOAT16_VALUE( 52.159),  SIMDE_FLOAT16_VALUE( 24.957),  SIMDE_FLOAT16_VALUE( 64.016),  SIMDE_FLOAT16_VALUE( 36.756)  },
      {  SIMDE_FLOAT16_VALUE( 65.380), SIMDE_FLOAT16_VALUE( -22.729),  SIMDE_FLOAT16_VALUE(  0.877),  SIMDE_FLOAT16_VALUE( 71.132)  },
      {  SIMDE_FLOAT16_VALUE( 84.184),  SIMDE_FLOAT16_VALUE(  1.688),  SIMDE_FLOAT16_VALUE( 13.012), SIMDE_FLOAT16_VALUE( -96.029)  } },
      {  SIMDE_FLOAT16_VALUE( 52.159),  SIMDE_FLOAT16_VALUE( 24.957),  SIMDE_FLOAT16_VALUE( 64.016),  SIMDE_FLOAT16_VALUE( 36.756),
         SIMDE_FLOAT16_VALUE( 65.380), SIMDE_FLOAT16_VALUE( -22.729),  SIMDE_FLOAT16_VALUE(  0.877),  SIMDE_FLOAT16_VALUE( 71.132),
         SIMDE_FLOAT16_VALUE( 84.184),  SIMDE_FLOAT16_VALUE(  1.688),  SIMDE_FLOAT16_VALUE( 13.012), SIMDE_FLOAT16_VALUE( -96.029) } },
  { { { SIMDE_FLOAT16_VALUE( -42.841), SIMDE_FLOAT16_VALUE( -57.189),  SIMDE_FLOAT16_VALUE( 82.362), SIMDE_FLOAT16_VALUE( -76.770)  },
      {  SIMDE_FLOAT16_VALUE( 44.180),  SIMDE_FLOAT16_VALUE( 81.552),  SIMDE_FLOAT16_VALUE( 36.064),  SIMDE_FLOAT16_VALUE( 37.831)  },
      { SIMDE_FLOAT16_VALUE( -86.197),  SIMDE_FLOAT16_VALUE(  7.055), SIMDE_FLOAT16_VALUE( -65.114), SIMDE_FLOAT16_VALUE( -27.135)  } },
      { SIMDE_FLOAT16_VALUE( -42.841), SIMDE_FLOAT16_VALUE( -57.189),  SIMDE_FLOAT16_VALUE( 82.362), SIMDE_FLOAT16_VALUE( -76.770),
         SIMDE_FLOAT16_VALUE( 44.180),  SIMDE_FLOAT16_VALUE( 81.552),  SIMDE_FLOAT16_VALUE( 36.064),  SIMDE_FLOAT16_VALUE( 37.831),
        SIMDE_FLOAT16_VALUE( -86.197),  SIMDE_FLOAT16_VALUE(  7.055), SIMDE_FLOAT16_VALUE( -65.114), SIMDE_FLOAT16_VALUE( -27.135) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float16x4x3_t val = {{
        simde_vld1_f16(test_vec[i].val[0]),
        simde_vld1_f16(test_vec[i].val[1]),
        simde_vld1_f16(test_vec[i].val[2]),
    }};
    simde_float16 r_[12];
    simde_vst1_f16_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_f32_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 val[3][2];
    simde_float32 r[6];
  } test_vec[] = {
  { { {  SIMDE_FLOAT32_C( 1465.264), -SIMDE_FLOAT32_C( 9841.196)  },
      {  SIMDE_FLOAT32_C( 3174.656), -SIMDE_FLOAT32_C( 1635.959)  },
      { -SIMDE_FLOAT32_C( 6223.302),  SIMDE_FLOAT32_C( 5201.661)  } },
      {  SIMDE_FLOAT32_C( 1465.264), -SIMDE_FLOAT32_C( 9841.196),  SIMDE_FLOAT32_C( 3174.656), -SIMDE_FLOAT32_C( 1635.959), -SIMDE_FLOAT32_C( 6223.302),  SIMDE_FLOAT32_C( 5201.661) } },
  { { { -SIMDE_FLOAT32_C( 5391.817), -SIMDE_FLOAT32_C( 7835.295)  },
      { -SIMDE_FLOAT32_C( 9908.128), -SIMDE_FLOAT32_C( 3550.051)  },
      { -SIMDE_FLOAT32_C( 5558.961), -SIMDE_FLOAT32_C( 6973.140)  } },
      { -SIMDE_FLOAT32_C( 5391.817), -SIMDE_FLOAT32_C( 7835.295), -SIMDE_FLOAT32_C( 9908.128), -SIMDE_FLOAT32_C( 3550.051), -SIMDE_FLOAT32_C( 5558.961), -SIMDE_FLOAT32_C( 6973.140) } },
  { { { -SIMDE_FLOAT32_C( 5191.328),  SIMDE_FLOAT32_C( 3702.124)  },
      { -SIMDE_FLOAT32_C( 7626.972), -SIMDE_FLOAT32_C( 2744.820)  },
      { -SIMDE_FLOAT32_C( 8285.138),  SIMDE_FLOAT32_C( 3041.577)  } },
      { -SIMDE_FLOAT32_C( 5191.328),  SIMDE_FLOAT32_C( 3702.124), -SIMDE_FLOAT32_C( 7626.972), -SIMDE_FLOAT32_C( 2744.820), -SIMDE_FLOAT32_C( 8285.138),  SIMDE_FLOAT32_C( 3041.577) } },
  { { {  SIMDE_FLOAT32_C( 2442.315), -SIMDE_FLOAT32_C( 1026.613)  },
      {  SIMDE_FLOAT32_C( 8127.418), -SIMDE_FLOAT32_C( 7299.442)  },
      { -SIMDE_FLOAT32_C( 4223.697),  SIMDE_FLOAT32_C( 8289.078)  } },
      {  SIMDE_FLOAT32_C( 2442.315), -SIMDE_FLOAT32_C( 1026.613),  SIMDE_FLOAT32_C( 8127.418), -SIMDE_FLOAT32_C( 7299.442), -SIMDE_FLOAT32_C( 4223.697),  SIMDE_FLOAT32_C( 8289.078) } },
  { { { -SIMDE_FLOAT32_C( 8249.307), -SIMDE_FLOAT32_C( 6352.753)  },
      {  SIMDE_FLOAT32_C( 2886.608),  SIMDE_FLOAT32_C( 2424.469)  },
      { -SIMDE_FLOAT32_C( 7161.071), -SIMDE_FLOAT32_C( 7616.214)  } },
      { -SIMDE_FLOAT32_C( 8249.307), -SIMDE_FLOAT32_C( 6352.753),  SIMDE_FLOAT32_C( 2886.608),  SIMDE_FLOAT32_C( 2424.469), -SIMDE_FLOAT32_C( 7161.071), -SIMDE_FLOAT32_C( 7616.214) } },
  { { { -SIMDE_FLOAT32_C( 6688.370), -SIMDE_FLOAT32_C( 7658.354)  },
      { -SIMDE_FLOAT32_C( 2661.900), -SIMDE_FLOAT32_C( 4192.297)  },
      {  SIMDE_FLOAT32_C(  882.319), -SIMDE_FLOAT32_C( 3682.961)  } },
      { -SIMDE_FLOAT32_C( 6688.370), -SIMDE_FLOAT32_C( 7658.354), -SIMDE_FLOAT32_C( 2661.900), -SIMDE_FLOAT32_C( 4192.297),  SIMDE_FLOAT32_C(  882.319), -SIMDE_FLOAT32_C( 3682.961) } },
  { { {  SIMDE_FLOAT32_C( 6602.301), -SIMDE_FLOAT32_C( 1649.863)  },
      {  SIMDE_FLOAT32_C(  329.104),  SIMDE_FLOAT32_C( 5030.946)  },
      { -SIMDE_FLOAT32_C( 2305.431), -SIMDE_FLOAT32_C( 8942.493)  } },
      {  SIMDE_FLOAT32_C( 6602.301), -SIMDE_FLOAT32_C( 1649.863),  SIMDE_FLOAT32_C(  329.104),  SIMDE_FLOAT32_C( 5030.946), -SIMDE_FLOAT32_C( 2305.431), -SIMDE_FLOAT32_C( 8942.493) } },
  { { {  SIMDE_FLOAT32_C(  246.577), -SIMDE_FLOAT32_C( 9433.146)  },
      {  SIMDE_FLOAT32_C( 3790.517), -SIMDE_FLOAT32_C( 3123.045)  },
      {  SIMDE_FLOAT32_C( 8981.955),  SIMDE_FLOAT32_C( 5795.435)  } },
      {  SIMDE_FLOAT32_C(  246.577), -SIMDE_FLOAT32_C( 9433.146),  SIMDE_FLOAT32_C( 3790.517), -SIMDE_FLOAT32_C( 3123.045),  SIMDE_FLOAT32_C( 8981.955),  SIMDE_FLOAT32_C( 5795.435) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2x3_t val = {{
        simde_vld1_f32(test_vec[i].val[0]),
        simde_vld1_f32(test_vec[i].val[1]),
        simde_vld1_f32(test_vec[i].val[2]),
    }};
    simde_float32 r_[6];
    simde_vst1_f32_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_f64_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 val[3][1];
    simde_float64 r[3];
  } test_vec[] = {
  { { { -SIMDE_FLOAT64_C(  237259.375)  },
      {  SIMDE_FLOAT64_C(  783719.750)  },
      {  SIMDE_FLOAT64_C(  661990.375)  } },
      { -SIMDE_FLOAT64_C(  237259.375),  SIMDE_FLOAT64_C(  783719.750),  SIMDE_FLOAT64_C(  661990.375) } },
  { { { -SIMDE_FLOAT64_C(  423248.688)  },
      { -SIMDE_FLOAT64_C(  556667.062)  },
      { -SIMDE_FLOAT64_C(  323304.188)  } },
      { -SIMDE_FLOAT64_C(  423248.688), -SIMDE_FLOAT64_C(  556667.062), -SIMDE_FLOAT64_C(  323304.188) } },
  { { { -SIMDE_FLOAT64_C(  874894.062)  },
      { -SIMDE_FLOAT64_C(   67084.000)  },
      {  SIMDE_FLOAT64_C(  278980.125)  } },
      { -SIMDE_FLOAT64_C(  874894.062), -SIMDE_FLOAT64_C(   67084.000),  SIMDE_FLOAT64_C(  278980.125) } },
  { { {  SIMDE_FLOAT64_C(  256394.500)  },
      {  SIMDE_FLOAT64_C(  722799.625)  },
      {  SIMDE_FLOAT64_C(  520607.500)  } },
      {  SIMDE_FLOAT64_C(  256394.500),  SIMDE_FLOAT64_C(  722799.625),  SIMDE_FLOAT64_C(  520607.500) } },
  { { { -SIMDE_FLOAT64_C(  905557.688)  },
      { -SIMDE_FLOAT64_C(  112214.250)  },
      {  SIMDE_FLOAT64_C(  283980.625)  } },
      { -SIMDE_FLOAT64_C(  905557.688), -SIMDE_FLOAT64_C(  112214.250),  SIMDE_FLOAT64_C(  283980.625) } },
  { { { -SIMDE_FLOAT64_C(  989063.938)  },
      { -SIMDE_FLOAT64_C(   39020.250)  },
      {  SIMDE_FLOAT64_C(  744667.500)  } },
      { -SIMDE_FLOAT64_C(  989063.938), -SIMDE_FLOAT64_C(   39020.250),  SIMDE_FLOAT64_C(  744667.500) } },
  { { {  SIMDE_FLOAT64_C(  378448.000)  },
      {  SIMDE_FLOAT64_C(  395263.500)  },
      { -SIMDE_FLOAT64_C(  294918.438)  } },
      {  SIMDE_FLOAT64_C(  378448.000),  SIMDE_FLOAT64_C(  395263.500), -SIMDE_FLOAT64_C(  294918.438) } },
  { { { -SIMDE_FLOAT64_C(  185488.062)  },
      {  SIMDE_FLOAT64_C(   28712.125)  },
      { -SIMDE_FLOAT64_C(  342294.000)  } },
      { -SIMDE_FLOAT64_C(  185488.062),  SIMDE_FLOAT64_C(   28712.125), -SIMDE_FLOAT64_C(  342294.000) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1x3_t val = {{
        simde_vld1_f64(test_vec[i].val[0]),
        simde_vld1_f64(test_vec[i].val[1]),
        simde_vld1_f64(test_vec[i].val[2]),
    }};
    simde_float64 r_[3];
    simde_vst1_f64_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_s8_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t val[3][8];
    int8_t r[24];
  } test_vec[] = {
  { { { -INT8_C(  77), -INT8_C(  86),  INT8_C(  76),  INT8_C(  24),
         INT8_C( 119), -INT8_C(  77), -INT8_C(  47), -INT8_C(  51)  },
      {  INT8_C(  87), -INT8_C(  98), -INT8_C(  77),  INT8_C(  96),
         INT8_C(   1), -INT8_C( 111), -INT8_C( 120),  INT8_C( 126)  },
      { -INT8_C( 103),  INT8_C(  87),  INT8_C(  57),  INT8_C(  16),
         INT8_C( 123),  INT8_C( 114),  INT8_C(  84), -INT8_C(  10)  } },
      { -INT8_C(  77), -INT8_C(  86),  INT8_C(  76),  INT8_C(  24),
         INT8_C( 119), -INT8_C(  77), -INT8_C(  47), -INT8_C(  51),
         INT8_C(  87), -INT8_C(  98), -INT8_C(  77),  INT8_C(  96),
         INT8_C(   1), -INT8_C( 111), -INT8_C( 120),  INT8_C( 126),
        -INT8_C( 103),  INT8_C(  87),  INT8_C(  57),  INT8_C(  16),
         INT8_C( 123),  INT8_C( 114),  INT8_C(  84), -INT8_C(  10) } },
  { { { -INT8_C(  49),  INT8_C( 107), -INT8_C( 107),    INT8_MAX,
         INT8_C(   7),  INT8_C(   8),  INT8_C(  11),  INT8_C(  79)  },
      { -INT8_C(  47), -INT8_C( 110), -INT8_C(  89),  INT8_C(   3),
         INT8_C(  35), -INT8_C(  93), -INT8_C(  25), -INT8_C(  54)  },
      { -INT8_C(  32), -INT8_C( 105), -INT8_C(  57),  INT8_C(   6),
         INT8_C(  19),  INT8_C(  30),  INT8_C( 104),  INT8_C(  16)  } },
      { -INT8_C(  49),  INT8_C( 107), -INT8_C( 107),    INT8_MAX,
         INT8_C(   7),  INT8_C(   8),  INT8_C(  11),  INT8_C(  79),
        -INT8_C(  47), -INT8_C( 110), -INT8_C(  89),  INT8_C(   3),
         INT8_C(  35), -INT8_C(  93), -INT8_C(  25), -INT8_C(  54),
        -INT8_C(  32), -INT8_C( 105), -INT8_C(  57),  INT8_C(   6),
         INT8_C(  19),  INT8_C(  30),  INT8_C( 104),  INT8_C(  16) } },
  { { { -INT8_C( 116),  INT8_C(  89),  INT8_C(  59),  INT8_C(  47),
        -INT8_C(  80),  INT8_C( 101),  INT8_C(  89), -INT8_C( 119)  },
      { -INT8_C(  79), -INT8_C(  81),  INT8_C(  38),  INT8_C(  64),
        -INT8_C(  69), -INT8_C(  76),  INT8_C(  40), -INT8_C(  38)  },
      {  INT8_C( 115),  INT8_C(  56),  INT8_C( 108),  INT8_C(  18),
         INT8_C(  35),  INT8_C( 124),  INT8_C( 101), -INT8_C(  70)  } },
      { -INT8_C( 116),  INT8_C(  89),  INT8_C(  59),  INT8_C(  47),
        -INT8_C(  80),  INT8_C( 101),  INT8_C(  89), -INT8_C( 119),
        -INT8_C(  79), -INT8_C(  81),  INT8_C(  38),  INT8_C(  64),
        -INT8_C(  69), -INT8_C(  76),  INT8_C(  40), -INT8_C(  38),
         INT8_C( 115),  INT8_C(  56),  INT8_C( 108),  INT8_C(  18),
         INT8_C(  35),  INT8_C( 124),  INT8_C( 101), -INT8_C(  70) } },
  { { { -INT8_C(  84), -INT8_C(  59), -INT8_C(  65), -INT8_C(  53),
        -INT8_C( 109),  INT8_C(  86), -INT8_C( 101),  INT8_C(  62)  },
      {  INT8_C( 105), -INT8_C(  24), -INT8_C(  85),  INT8_C(  19),
         INT8_C(  70),  INT8_C(  86), -INT8_C(  71),  INT8_C(  40)  },
      { -INT8_C(  46), -INT8_C(  45),  INT8_C(  52), -INT8_C(  43),
         INT8_C(   9), -INT8_C( 105),  INT8_C(  24), -INT8_C( 125)  } },
      { -INT8_C(  84), -INT8_C(  59), -INT8_C(  65), -INT8_C(  53),
        -INT8_C( 109),  INT8_C(  86), -INT8_C( 101),  INT8_C(  62),
         INT8_C( 105), -INT8_C(  24), -INT8_C(  85),  INT8_C(  19),
         INT8_C(  70),  INT8_C(  86), -INT8_C(  71),  INT8_C(  40),
        -INT8_C(  46), -INT8_C(  45),  INT8_C(  52), -INT8_C(  43),
         INT8_C(   9), -INT8_C( 105),  INT8_C(  24), -INT8_C( 125) } },
  { { {  INT8_C(  27), -INT8_C(  81),  INT8_C(   5),  INT8_C( 104),
        -INT8_C(  87), -INT8_C(  90),  INT8_C(  95),  INT8_C( 118)  },
      {  INT8_C(  73),  INT8_C(  82), -INT8_C(  43),  INT8_C(  81),
         INT8_C(  25), -INT8_C(  38), -INT8_C(  90), -INT8_C(  41)  },
      {  INT8_C(  67),  INT8_C(  20),  INT8_C( 115), -INT8_C( 112),
        -INT8_C(  40), -INT8_C(  97), -INT8_C(  60), -INT8_C( 112)  } },
      {  INT8_C(  27), -INT8_C(  81),  INT8_C(   5),  INT8_C( 104),
        -INT8_C(  87), -INT8_C(  90),  INT8_C(  95),  INT8_C( 118),
         INT8_C(  73),  INT8_C(  82), -INT8_C(  43),  INT8_C(  81),
         INT8_C(  25), -INT8_C(  38), -INT8_C(  90), -INT8_C(  41),
         INT8_C(  67),  INT8_C(  20),  INT8_C( 115), -INT8_C( 112),
        -INT8_C(  40), -INT8_C(  97), -INT8_C(  60), -INT8_C( 112) } },
  { { { -INT8_C(  15),  INT8_C(  10), -INT8_C( 104),  INT8_C(  34),
         INT8_C(  75),  INT8_C(  44),  INT8_C(  49), -INT8_C( 101)  },
      { -INT8_C(  56),  INT8_C(  29), -INT8_C(  68), -INT8_C(  43),
         INT8_C( 100),  INT8_C(  41),  INT8_C( 123), -INT8_C(  55)  },
      {  INT8_C(  87), -INT8_C(   8), -INT8_C( 102),  INT8_C(  85),
         INT8_C(  86),  INT8_C( 115),  INT8_C( 110), -INT8_C(  92)  } },
      { -INT8_C(  15),  INT8_C(  10), -INT8_C( 104),  INT8_C(  34),
         INT8_C(  75),  INT8_C(  44),  INT8_C(  49), -INT8_C( 101),
        -INT8_C(  56),  INT8_C(  29), -INT8_C(  68), -INT8_C(  43),
         INT8_C( 100),  INT8_C(  41),  INT8_C( 123), -INT8_C(  55),
         INT8_C(  87), -INT8_C(   8), -INT8_C( 102),  INT8_C(  85),
         INT8_C(  86),  INT8_C( 115),  INT8_C( 110), -INT8_C(  92) } },
  { { {  INT8_C(  35), -INT8_C( 105), -INT8_C( 117),  INT8_C(  97),
         INT8_C(  33), -INT8_C(  17),  INT8_C(  68),  INT8_C( 114)  },
      { -INT8_C(  54), -INT8_C(  40), -INT8_C(  24), -INT8_C( 107),
        -INT8_C(  36), -INT8_C(  33), -INT8_C(  21), -INT8_C(  27)  },
      { -INT8_C(  79), -INT8_C(  16), -INT8_C(  99), -INT8_C(  95),
        -INT8_C(  58),  INT8_C(  35), -INT8_C(  41), -INT8_C(  79)  } },
      {  INT8_C(  35), -INT8_C( 105), -INT8_C( 117),  INT8_C(  97),
         INT8_C(  33), -INT8_C(  17),  INT8_C(  68),  INT8_C( 114),
        -INT8_C(  54), -INT8_C(  40), -INT8_C(  24), -INT8_C( 107),
        -INT8_C(  36), -INT8_C(  33), -INT8_C(  21), -INT8_C(  27),
        -INT8_C(  79), -INT8_C(  16), -INT8_C(  99), -INT8_C(  95),
        -INT8_C(  58),  INT8_C(  35), -INT8_C(  41), -INT8_C(  79) } },
  { { { -INT8_C(  93), -INT8_C( 125), -INT8_C(  39),  INT8_C(  13),
        -INT8_C(  50), -INT8_C(  41), -INT8_C(  84), -INT8_C(  11)  },
      { -INT8_C(  27), -INT8_C(  70),  INT8_C( 122),  INT8_C(  24),
        -INT8_C(  91), -INT8_C(  15),  INT8_C(  63), -INT8_C(   4)  },
      {  INT8_C(  61), -INT8_C(  57), -INT8_C(  42),  INT8_C(  49),
        -INT8_C(  51), -INT8_C( 112),  INT8_C(  16),  INT8_C(  55)  } },
      { -INT8_C(  93), -INT8_C( 125), -INT8_C(  39),  INT8_C(  13),
        -INT8_C(  50), -INT8_C(  41), -INT8_C(  84), -INT8_C(  11),
        -INT8_C(  27), -INT8_C(  70),  INT8_C( 122),  INT8_C(  24),
        -INT8_C(  91), -INT8_C(  15),  INT8_C(  63), -INT8_C(   4),
         INT8_C(  61), -INT8_C(  57), -INT8_C(  42),  INT8_C(  49),
        -INT8_C(  51), -INT8_C( 112),  INT8_C(  16),  INT8_C(  55) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8x3_t val = {{
        simde_vld1_s8(test_vec[i].val[0]),
        simde_vld1_s8(test_vec[i].val[1]),
        simde_vld1_s8(test_vec[i].val[2]),
    }};
    int8_t r_[24];
    simde_vst1_s8_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_s16_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t val[3][4];
    int16_t r[12];
  } test_vec[] = {
  { { { -INT16_C(    9918), -INT16_C(   15170),  INT16_C(   18969),  INT16_C(    5210)  },
      {  INT16_C(   25414),  INT16_C(   25543), -INT16_C(   15396),  INT16_C(    5815)  },
      {  INT16_C(   19057),  INT16_C(   23624),  INT16_C(   28505),  INT16_C(    1832)  } },
      { -INT16_C(    9918), -INT16_C(   15170),  INT16_C(   18969),  INT16_C(    5210),
         INT16_C(   25414),  INT16_C(   25543), -INT16_C(   15396),  INT16_C(    5815),
         INT16_C(   19057),  INT16_C(   23624),  INT16_C(   28505),  INT16_C(    1832) } },
  { { {  INT16_C(   22959),  INT16_C(   25824), -INT16_C(   29354), -INT16_C(    6392)  },
      {  INT16_C(    4171), -INT16_C(   28320), -INT16_C(   31730),  INT16_C(   10127)  },
      {  INT16_C(   16146),  INT16_C(   11645), -INT16_C(   30533),  INT16_C(   11147)  } },
      {  INT16_C(   22959),  INT16_C(   25824), -INT16_C(   29354), -INT16_C(    6392),
         INT16_C(    4171), -INT16_C(   28320), -INT16_C(   31730),  INT16_C(   10127),
         INT16_C(   16146),  INT16_C(   11645), -INT16_C(   30533),  INT16_C(   11147) } },
  { { { -INT16_C(   16058), -INT16_C(   14229), -INT16_C(    1275),  INT16_C(   24392)  },
      { -INT16_C(    6204), -INT16_C(   29782),  INT16_C(    3143),  INT16_C(   15565)  },
      { -INT16_C(   21256), -INT16_C(   12103), -INT16_C(     967), -INT16_C(     656)  } },
      { -INT16_C(   16058), -INT16_C(   14229), -INT16_C(    1275),  INT16_C(   24392),
        -INT16_C(    6204), -INT16_C(   29782),  INT16_C(    3143),  INT16_C(   15565),
        -INT16_C(   21256), -INT16_C(   12103), -INT16_C(     967), -INT16_C(     656) } },
  { { { -INT16_C(   15305), -INT16_C(    6571),  INT16_C(   21425), -INT16_C(   17056)  },
      { -INT16_C(     597), -INT16_C(    1320), -INT16_C(   24904),  INT16_C(   30907)  },
      {  INT16_C(   13068),  INT16_C(   21504),  INT16_C(    1629), -INT16_C(   13532)  } },
      { -INT16_C(   15305), -INT16_C(    6571),  INT16_C(   21425), -INT16_C(   17056),
        -INT16_C(     597), -INT16_C(    1320), -INT16_C(   24904),  INT16_C(   30907),
         INT16_C(   13068),  INT16_C(   21504),  INT16_C(    1629), -INT16_C(   13532) } },
  { { { -INT16_C(     868), -INT16_C(   28723), -INT16_C(    9831),  INT16_C(    9215)  },
      {  INT16_C(   21175), -INT16_C(   20185),  INT16_C(   13934), -INT16_C(    4822)  },
      {  INT16_C(    3267), -INT16_C(   16420),  INT16_C(   19169), -INT16_C(    9588)  } },
      { -INT16_C(     868), -INT16_C(   28723), -INT16_C(    9831),  INT16_C(    9215),
         INT16_C(   21175), -INT16_C(   20185),  INT16_C(   13934), -INT16_C(    4822),
         INT16_C(    3267), -INT16_C(   16420),  INT16_C(   19169), -INT16_C(    9588) } },
  { { {  INT16_C(   32357),  INT16_C(   23428),  INT16_C(   17427),  INT16_C(   18134)  },
      { -INT16_C(   15542),  INT16_C(   29109),  INT16_C(    1277), -INT16_C(   26798)  },
      {  INT16_C(    1486),  INT16_C(   31553),  INT16_C(   23931),  INT16_C(    4130)  } },
      {  INT16_C(   32357),  INT16_C(   23428),  INT16_C(   17427),  INT16_C(   18134),
        -INT16_C(   15542),  INT16_C(   29109),  INT16_C(    1277), -INT16_C(   26798),
         INT16_C(    1486),  INT16_C(   31553),  INT16_C(   23931),  INT16_C(    4130) } },
  { { {  INT16_C(    4210),  INT16_C(   12294),  INT16_C(   29025),  INT16_C(     382)  },
      { -INT16_C(    5398), -INT16_C(    3359),  INT16_C(    5815),  INT16_C(    5014)  },
      { -INT16_C(     141),  INT16_C(   22770), -INT16_C(   29452),  INT16_C(   17951)  } },
      {  INT16_C(    4210),  INT16_C(   12294),  INT16_C(   29025),  INT16_C(     382),
        -INT16_C(    5398), -INT16_C(    3359),  INT16_C(    5815),  INT16_C(    5014),
        -INT16_C(     141),  INT16_C(   22770), -INT16_C(   29452),  INT16_C(   17951) } },
  { { {  INT16_C(    3354),  INT16_C(   31801), -INT16_C(    6470),  INT16_C(   27491)  },
      {  INT16_C(   10035),  INT16_C(    6145),  INT16_C(   31932),  INT16_C(   32038)  },
      { -INT16_C(   20871), -INT16_C(   25838), -INT16_C(   14594), -INT16_C(    6137)  } },
      {  INT16_C(    3354),  INT16_C(   31801), -INT16_C(    6470),  INT16_C(   27491),
         INT16_C(   10035),  INT16_C(    6145),  INT16_C(   31932),  INT16_C(   32038),
        -INT16_C(   20871), -INT16_C(   25838), -INT16_C(   14594), -INT16_C(    6137) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4x3_t val = {{
        simde_vld1_s16(test_vec[i].val[0]),
        simde_vld1_s16(test_vec[i].val[1]),
        simde_vld1_s16(test_vec[i].val[2]),
    }};
    int16_t r_[12];
    simde_vst1_s16_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_s32_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t val[3][2];
    int32_t r[6];
  } test_vec[] = {
  { { {  INT32_C(  1659426468),  INT32_C(  2109199351)  },
      { -INT32_C(   165496116), -INT32_C(   445590715)  },
      {  INT32_C(    32230964), -INT32_C(   159278530)  } },
      {  INT32_C(  1659426468),  INT32_C(  2109199351), -INT32_C(   165496116), -INT32_C(   445590715),  INT32_C(    32230964), -INT32_C(   159278530) } },
  { { {  INT32_C(   549755181), -INT32_C(   451502563)  },
      { -INT32_C(  1007538931),  INT32_C(   457899100)  },
      { -INT32_C(  1540965393), -INT32_C(    65123287)  } },
      {  INT32_C(   549755181), -INT32_C(   451502563), -INT32_C(  1007538931),  INT32_C(   457899100), -INT32_C(  1540965393), -INT32_C(    65123287) } },
  { { {  INT32_C(  1252795707), -INT32_C(   761146891)  },
      {  INT32_C(  1696615264),  INT32_C(  1836889843)  },
      { -INT32_C(   388787289),  INT32_C(  1088748038)  } },
      {  INT32_C(  1252795707), -INT32_C(   761146891),  INT32_C(  1696615264),  INT32_C(  1836889843), -INT32_C(   388787289),  INT32_C(  1088748038) } },
  { { { -INT32_C(  1694510585),  INT32_C(  1447173882)  },
      { -INT32_C(  1127622723), -INT32_C(   651424165)  },
      { -INT32_C(   799113419),  INT32_C(  1398938444)  } },
      { -INT32_C(  1694510585),  INT32_C(  1447173882), -INT32_C(  1127622723), -INT32_C(   651424165), -INT32_C(   799113419),  INT32_C(  1398938444) } },
  { { { -INT32_C(   206043904),  INT32_C(  1418393151)  },
      { -INT32_C(   472873561), -INT32_C(  1047512890)  },
      { -INT32_C(   478651186),  INT32_C(   641761455)  } },
      { -INT32_C(   206043904),  INT32_C(  1418393151), -INT32_C(   472873561), -INT32_C(  1047512890), -INT32_C(   478651186),  INT32_C(   641761455) } },
  { { { -INT32_C(  1206535015),  INT32_C(   678287149)  },
      { -INT32_C(  1989752910),  INT32_C(  1235770691)  },
      { -INT32_C(  1249781211),  INT32_C(   160484990)  } },
      { -INT32_C(  1206535015),  INT32_C(   678287149), -INT32_C(  1989752910),  INT32_C(  1235770691), -INT32_C(  1249781211),  INT32_C(   160484990) } },
  { { { -INT32_C(  2025477041), -INT32_C(  1726525114)  },
      {  INT32_C(  1241070748), -INT32_C(    68765445)  },
      {  INT32_C(  1741337215), -INT32_C(   167242877)  } },
      { -INT32_C(  2025477041), -INT32_C(  1726525114),  INT32_C(  1241070748), -INT32_C(    68765445),  INT32_C(  1741337215), -INT32_C(   167242877) } },
  { { {  INT32_C(  1701669748),  INT32_C(  1572367412)  },
      {  INT32_C(   836199612),  INT32_C(  1585873859)  },
      { -INT32_C(  1523648823), -INT32_C(   234740460)  } },
      {  INT32_C(  1701669748),  INT32_C(  1572367412),  INT32_C(   836199612),  INT32_C(  1585873859), -INT32_C(  1523648823), -INT32_C(   234740460) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2x3_t val = {{
        simde_vld1_s32(test_vec[i].val[0]),
        simde_vld1_s32(test_vec[i].val[1]),
        simde_vld1_s32(test_vec[i].val[2]),
    }};
    int32_t r_[6];
    simde_vst1_s32_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_s64_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t val[3][1];
    int64_t r[3];
  } test_vec[] = {
  { { { -INT64_C(  324688268217214510)  },
      {  INT64_C( 6555013858260086461)  },
      { -INT64_C( 4171892446323234449)  } },
      { -INT64_C(  324688268217214510),  INT64_C( 6555013858260086461), -INT64_C( 4171892446323234449) } },
  { { {  INT64_C( 7558853181241542220)  },
      { -INT64_C( 6927665649455001038)  },
      {  INT64_C( 1941964905678319357)  } },
      {  INT64_C( 7558853181241542220), -INT64_C( 6927665649455001038),  INT64_C( 1941964905678319357) } },
  { { { -INT64_C( 5804851387615542502)  },
      { -INT64_C( 3432221340632395615)  },
      { -INT64_C( 1336222917297342208)  } },
      { -INT64_C( 5804851387615542502), -INT64_C( 3432221340632395615), -INT64_C( 1336222917297342208) } },
  { { { -INT64_C(  741660553674955513)  },
      {  INT64_C( 4870255248549942108)  },
      {  INT64_C( 7950846317780396305)  } },
      { -INT64_C(  741660553674955513),  INT64_C( 4870255248549942108),  INT64_C( 7950846317780396305) } },
  { { { -INT64_C( 6193426369521613302)  },
      { -INT64_C( 9124668995710459338)  },
      { -INT64_C(   69796552541282130)  } },
      { -INT64_C( 6193426369521613302), -INT64_C( 9124668995710459338), -INT64_C(   69796552541282130) } },
  { { {  INT64_C( 3276925377317973865)  },
      { -INT64_C( 2613504986732356350)  },
      { -INT64_C( 1397577237575245352)  } },
      {  INT64_C( 3276925377317973865), -INT64_C( 2613504986732356350), -INT64_C( 1397577237575245352) } },
  { { {  INT64_C( 3384132572195949708)  },
      {  INT64_C( 3757973727131487360)  },
      {  INT64_C( 6668473445192699478)  } },
      {  INT64_C( 3384132572195949708),  INT64_C( 3757973727131487360),  INT64_C( 6668473445192699478) } },
  { { {  INT64_C( 2456344331383543397)  },
      { -INT64_C( 3610302254899778004)  },
      { -INT64_C( 2785958690387801429)  } },
      {  INT64_C( 2456344331383543397), -INT64_C( 3610302254899778004), -INT64_C( 2785958690387801429) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1x3_t val = {{
        simde_vld1_s64(test_vec[i].val[0]),
        simde_vld1_s64(test_vec[i].val[1]),
        simde_vld1_s64(test_vec[i].val[2]),
    }};
    int64_t r_[3];
    simde_vst1_s64_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_u8_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t val[3][8];
    uint8_t r[24];
  } test_vec[] = {
  { { {  UINT8_C( 247),  UINT8_C( 116),  UINT8_C( 236),  UINT8_C( 151),
         UINT8_C( 124),  UINT8_C( 216),  UINT8_C( 191),  UINT8_C( 153)  },
      {  UINT8_C(  89),  UINT8_C( 159),  UINT8_C( 131),  UINT8_C(  96),
         UINT8_C( 244),  UINT8_C(  66),  UINT8_C(   4),  UINT8_C( 245)  },
      {  UINT8_C(  53),  UINT8_C( 226),  UINT8_C( 169),  UINT8_C( 140),
         UINT8_C(   1),  UINT8_C( 224),  UINT8_C(  66),  UINT8_C( 209)  } },
      {  UINT8_C( 247),  UINT8_C( 116),  UINT8_C( 236),  UINT8_C( 151),
         UINT8_C( 124),  UINT8_C( 216),  UINT8_C( 191),  UINT8_C( 153),
         UINT8_C(  89),  UINT8_C( 159),  UINT8_C( 131),  UINT8_C(  96),
         UINT8_C( 244),  UINT8_C(  66),  UINT8_C(   4),  UINT8_C( 245),
         UINT8_C(  53),  UINT8_C( 226),  UINT8_C( 169),  UINT8_C( 140),
         UINT8_C(   1),  UINT8_C( 224),  UINT8_C(  66),  UINT8_C( 209) } },
  { { {  UINT8_C(  17),  UINT8_C( 176),  UINT8_C( 204),  UINT8_C( 206),
         UINT8_C(  69),  UINT8_C( 140),  UINT8_C( 124),  UINT8_C( 184)  },
      {  UINT8_C( 210),  UINT8_C( 248),  UINT8_C( 205),  UINT8_C(  15),
         UINT8_C( 205),  UINT8_C( 127),  UINT8_C(  82),  UINT8_C( 111)  },
      {  UINT8_C( 105),  UINT8_C(  36),  UINT8_C( 232),  UINT8_C(  72),
         UINT8_C( 190),  UINT8_C( 234),  UINT8_C(  10),  UINT8_C( 200)  } },
      {  UINT8_C(  17),  UINT8_C( 176),  UINT8_C( 204),  UINT8_C( 206),
         UINT8_C(  69),  UINT8_C( 140),  UINT8_C( 124),  UINT8_C( 184),
         UINT8_C( 210),  UINT8_C( 248),  UINT8_C( 205),  UINT8_C(  15),
         UINT8_C( 205),  UINT8_C( 127),  UINT8_C(  82),  UINT8_C( 111),
         UINT8_C( 105),  UINT8_C(  36),  UINT8_C( 232),  UINT8_C(  72),
         UINT8_C( 190),  UINT8_C( 234),  UINT8_C(  10),  UINT8_C( 200) } },
  { { {  UINT8_C(  17),  UINT8_C(  96),  UINT8_C(  12),  UINT8_C(  42),
         UINT8_C(  82),  UINT8_C( 186),  UINT8_C( 165),   UINT8_MAX  },
      {  UINT8_C( 179),  UINT8_C( 241),  UINT8_C( 135),  UINT8_C( 201),
         UINT8_C(  98),  UINT8_C(  15),  UINT8_C( 157),  UINT8_C( 229)  },
      {  UINT8_C( 204),  UINT8_C( 154),  UINT8_C(  32),  UINT8_C( 203),
         UINT8_C(  52),  UINT8_C( 239),  UINT8_C(  90),  UINT8_C( 249)  } },
      {  UINT8_C(  17),  UINT8_C(  96),  UINT8_C(  12),  UINT8_C(  42),
         UINT8_C(  82),  UINT8_C( 186),  UINT8_C( 165),   UINT8_MAX,
         UINT8_C( 179),  UINT8_C( 241),  UINT8_C( 135),  UINT8_C( 201),
         UINT8_C(  98),  UINT8_C(  15),  UINT8_C( 157),  UINT8_C( 229),
         UINT8_C( 204),  UINT8_C( 154),  UINT8_C(  32),  UINT8_C( 203),
         UINT8_C(  52),  UINT8_C( 239),  UINT8_C(  90),  UINT8_C( 249) } },
  { { {  UINT8_C(  18),  UINT8_C(  63),  UINT8_C( 193),  UINT8_C(  48),
         UINT8_C( 126),  UINT8_C(  18),  UINT8_C(  76),  UINT8_C( 130)  },
      {  UINT8_C( 214),  UINT8_C(  77),  UINT8_C( 184),  UINT8_C( 249),
         UINT8_C(  55),  UINT8_C( 141),  UINT8_C( 123),  UINT8_C(  58)  },
      {  UINT8_C( 243),  UINT8_C( 153),  UINT8_C( 124),  UINT8_C(  89),
         UINT8_C( 123),  UINT8_C( 152),  UINT8_C(  84),  UINT8_C( 209)  } },
      {  UINT8_C(  18),  UINT8_C(  63),  UINT8_C( 193),  UINT8_C(  48),
         UINT8_C( 126),  UINT8_C(  18),  UINT8_C(  76),  UINT8_C( 130),
         UINT8_C( 214),  UINT8_C(  77),  UINT8_C( 184),  UINT8_C( 249),
         UINT8_C(  55),  UINT8_C( 141),  UINT8_C( 123),  UINT8_C(  58),
         UINT8_C( 243),  UINT8_C( 153),  UINT8_C( 124),  UINT8_C(  89),
         UINT8_C( 123),  UINT8_C( 152),  UINT8_C(  84),  UINT8_C( 209) } },
  { { {  UINT8_C(  74),  UINT8_C( 118),  UINT8_C( 254),  UINT8_C( 240),
         UINT8_C(  73),  UINT8_C( 103),  UINT8_C( 249),  UINT8_C(  88)  },
      {  UINT8_C(  21),  UINT8_C( 142),  UINT8_C( 110),  UINT8_C( 159),
         UINT8_C(  38),  UINT8_C(  75),  UINT8_C( 173),  UINT8_C(   7)  },
      {  UINT8_C(  28),  UINT8_C( 231),  UINT8_C( 147),  UINT8_C(  70),
         UINT8_C(   2),  UINT8_C(  71),  UINT8_C( 141),  UINT8_C( 169)  } },
      {  UINT8_C(  74),  UINT8_C( 118),  UINT8_C( 254),  UINT8_C( 240),
         UINT8_C(  73),  UINT8_C( 103),  UINT8_C( 249),  UINT8_C(  88),
         UINT8_C(  21),  UINT8_C( 142),  UINT8_C( 110),  UINT8_C( 159),
         UINT8_C(  38),  UINT8_C(  75),  UINT8_C( 173),  UINT8_C(   7),
         UINT8_C(  28),  UINT8_C( 231),  UINT8_C( 147),  UINT8_C(  70),
         UINT8_C(   2),  UINT8_C(  71),  UINT8_C( 141),  UINT8_C( 169) } },
  { { {  UINT8_C(  58),  UINT8_C( 207),  UINT8_C(  87),  UINT8_C( 195),
         UINT8_C( 135),  UINT8_C( 180),  UINT8_C(  93),  UINT8_C( 210)  },
      {  UINT8_C( 203),  UINT8_C( 196),  UINT8_C(  31),  UINT8_C(  48),
         UINT8_C( 161),  UINT8_C( 125),  UINT8_C( 129),  UINT8_C( 190)  },
      {  UINT8_C(  26),  UINT8_C(  24),  UINT8_C( 151),  UINT8_C( 108),
         UINT8_C( 172),  UINT8_C(  43),  UINT8_C(   8),  UINT8_C(  51)  } },
      {  UINT8_C(  58),  UINT8_C( 207),  UINT8_C(  87),  UINT8_C( 195),
         UINT8_C( 135),  UINT8_C( 180),  UINT8_C(  93),  UINT8_C( 210),
         UINT8_C( 203),  UINT8_C( 196),  UINT8_C(  31),  UINT8_C(  48),
         UINT8_C( 161),  UINT8_C( 125),  UINT8_C( 129),  UINT8_C( 190),
         UINT8_C(  26),  UINT8_C(  24),  UINT8_C( 151),  UINT8_C( 108),
         UINT8_C( 172),  UINT8_C(  43),  UINT8_C(   8),  UINT8_C(  51) } },
  { { {  UINT8_C( 169),  UINT8_C( 206),  UINT8_C( 244),  UINT8_C(  84),
         UINT8_C( 107),  UINT8_C( 203),  UINT8_C(  23),  UINT8_C( 228)  },
      {  UINT8_C( 148),  UINT8_C( 250),  UINT8_C( 253),  UINT8_C( 208),
         UINT8_C(  98),  UINT8_C( 131),  UINT8_C( 163),  UINT8_C(  19)  },
      {  UINT8_C(  40),  UINT8_C( 234),  UINT8_C( 237),  UINT8_C(  45),
         UINT8_C(  84),  UINT8_C( 143),  UINT8_C( 163),  UINT8_C(  63)  } },
      {  UINT8_C( 169),  UINT8_C( 206),  UINT8_C( 244),  UINT8_C(  84),
         UINT8_C( 107),  UINT8_C( 203),  UINT8_C(  23),  UINT8_C( 228),
         UINT8_C( 148),  UINT8_C( 250),  UINT8_C( 253),  UINT8_C( 208),
         UINT8_C(  98),  UINT8_C( 131),  UINT8_C( 163),  UINT8_C(  19),
         UINT8_C(  40),  UINT8_C( 234),  UINT8_C( 237),  UINT8_C(  45),
         UINT8_C(  84),  UINT8_C( 143),  UINT8_C( 163),  UINT8_C(  63) } },
  { { {  UINT8_C( 178),  UINT8_C( 105),  UINT8_C(  90),  UINT8_C( 139),
         UINT8_C( 211),  UINT8_C(  78),  UINT8_C( 222),  UINT8_C(   8)  },
      {  UINT8_C( 202),  UINT8_C( 164),  UINT8_C( 157),  UINT8_C(  72),
         UINT8_C( 177),  UINT8_C(   5),  UINT8_C(  35),  UINT8_C(  86)  },
      {  UINT8_C( 203),  UINT8_C(   4),  UINT8_C(  27),  UINT8_C( 219),
         UINT8_C( 213),  UINT8_C( 235),  UINT8_C(   8),  UINT8_C(  27)  } },
      {  UINT8_C( 178),  UINT8_C( 105),  UINT8_C(  90),  UINT8_C( 139),
         UINT8_C( 211),  UINT8_C(  78),  UINT8_C( 222),  UINT8_C(   8),
         UINT8_C( 202),  UINT8_C( 164),  UINT8_C( 157),  UINT8_C(  72),
         UINT8_C( 177),  UINT8_C(   5),  UINT8_C(  35),  UINT8_C(  86),
         UINT8_C( 203),  UINT8_C(   4),  UINT8_C(  27),  UINT8_C( 219),
         UINT8_C( 213),  UINT8_C( 235),  UINT8_C(   8),  UINT8_C(  27) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8x3_t val = {{
        simde_vld1_u8(test_vec[i].val[0]),
        simde_vld1_u8(test_vec[i].val[1]),
        simde_vld1_u8(test_vec[i].val[2]),
    }};
    uint8_t r_[24];
    simde_vst1_u8_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_u16_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t val[3][4];
    uint16_t r[12];
  } test_vec[] = {
  { { {  UINT16_C(   14624),  UINT16_C(   25408),  UINT16_C(   12573),  UINT16_C(   13551)  },
      {  UINT16_C(   13018),  UINT16_C(   27018),  UINT16_C(    8624),  UINT16_C(    8654)  },
      {  UINT16_C(   47774),  UINT16_C(   10119),  UINT16_C(   10557),  UINT16_C(   36481)  } },
      {  UINT16_C(   14624),  UINT16_C(   25408),  UINT16_C(   12573),  UINT16_C(   13551),
         UINT16_C(   13018),  UINT16_C(   27018),  UINT16_C(    8624),  UINT16_C(    8654),
         UINT16_C(   47774),  UINT16_C(   10119),  UINT16_C(   10557),  UINT16_C(   36481) } },
  { { {  UINT16_C(   44406),  UINT16_C(   10122),  UINT16_C(   44130),  UINT16_C(   26137)  },
      {  UINT16_C(   16447),  UINT16_C(   47867),  UINT16_C(   45724),  UINT16_C(   35942)  },
      {  UINT16_C(   44228),  UINT16_C(   11718),  UINT16_C(   42621),  UINT16_C(   23301)  } },
      {  UINT16_C(   44406),  UINT16_C(   10122),  UINT16_C(   44130),  UINT16_C(   26137),
         UINT16_C(   16447),  UINT16_C(   47867),  UINT16_C(   45724),  UINT16_C(   35942),
         UINT16_C(   44228),  UINT16_C(   11718),  UINT16_C(   42621),  UINT16_C(   23301) } },
  { { {  UINT16_C(   40097),  UINT16_C(   34036),  UINT16_C(    3415),  UINT16_C(   10148)  },
      {  UINT16_C(   47168),  UINT16_C(   52780),  UINT16_C(   20645),  UINT16_C(     837)  },
      {  UINT16_C(   37373),  UINT16_C(   36262),  UINT16_C(    7284),  UINT16_C(   15220)  } },
      {  UINT16_C(   40097),  UINT16_C(   34036),  UINT16_C(    3415),  UINT16_C(   10148),
         UINT16_C(   47168),  UINT16_C(   52780),  UINT16_C(   20645),  UINT16_C(     837),
         UINT16_C(   37373),  UINT16_C(   36262),  UINT16_C(    7284),  UINT16_C(   15220) } },
  { { {  UINT16_C(   24904),  UINT16_C(   17173),  UINT16_C(   20133),  UINT16_C(   15463)  },
      {  UINT16_C(   15462),  UINT16_C(    9086),  UINT16_C(   39268),  UINT16_C(   53195)  },
      {  UINT16_C(   32800),  UINT16_C(   17824),  UINT16_C(   14829),  UINT16_C(   27783)  } },
      {  UINT16_C(   24904),  UINT16_C(   17173),  UINT16_C(   20133),  UINT16_C(   15463),
         UINT16_C(   15462),  UINT16_C(    9086),  UINT16_C(   39268),  UINT16_C(   53195),
         UINT16_C(   32800),  UINT16_C(   17824),  UINT16_C(   14829),  UINT16_C(   27783) } },
  { { {  UINT16_C(   23019),  UINT16_C(   63913),  UINT16_C(   23784),  UINT16_C(   53228)  },
      {  UINT16_C(   40672),  UINT16_C(   33770),  UINT16_C(    2443),  UINT16_C(    4305)  },
      {  UINT16_C(   40688),  UINT16_C(   25487),  UINT16_C(    6358),  UINT16_C(   30525)  } },
      {  UINT16_C(   23019),  UINT16_C(   63913),  UINT16_C(   23784),  UINT16_C(   53228),
         UINT16_C(   40672),  UINT16_C(   33770),  UINT16_C(    2443),  UINT16_C(    4305),
         UINT16_C(   40688),  UINT16_C(   25487),  UINT16_C(    6358),  UINT16_C(   30525) } },
  { { {  UINT16_C(   52456),  UINT16_C(   16254),  UINT16_C(   31479),  UINT16_C(   11146)  },
      {  UINT16_C(   11337),  UINT16_C(    6351),  UINT16_C(   25325),  UINT16_C(   11006)  },
      {  UINT16_C(   61119),  UINT16_C(    6026),  UINT16_C(   35810),  UINT16_C(   13827)  } },
      {  UINT16_C(   52456),  UINT16_C(   16254),  UINT16_C(   31479),  UINT16_C(   11146),
         UINT16_C(   11337),  UINT16_C(    6351),  UINT16_C(   25325),  UINT16_C(   11006),
         UINT16_C(   61119),  UINT16_C(    6026),  UINT16_C(   35810),  UINT16_C(   13827) } },
  { { {  UINT16_C(    5588),  UINT16_C(   56205),  UINT16_C(   59029),  UINT16_C(   13472)  },
      {  UINT16_C(   20360),  UINT16_C(   39152),  UINT16_C(   16794),  UINT16_C(    1300)  },
      {  UINT16_C(   47480),  UINT16_C(   62460),  UINT16_C(   21894),  UINT16_C(   27291)  } },
      {  UINT16_C(    5588),  UINT16_C(   56205),  UINT16_C(   59029),  UINT16_C(   13472),
         UINT16_C(   20360),  UINT16_C(   39152),  UINT16_C(   16794),  UINT16_C(    1300),
         UINT16_C(   47480),  UINT16_C(   62460),  UINT16_C(   21894),  UINT16_C(   27291) } },
  { { {  UINT16_C(   16101),  UINT16_C(   37984),  UINT16_C(   37135),  UINT16_C(   61198)  },
      {  UINT16_C(   49742),  UINT16_C(   47252),  UINT16_C(   33098),  UINT16_C(    7353)  },
      {  UINT16_C(   61348),  UINT16_C(   64627),  UINT16_C(    6987),  UINT16_C(   34685)  } },
      {  UINT16_C(   16101),  UINT16_C(   37984),  UINT16_C(   37135),  UINT16_C(   61198),
         UINT16_C(   49742),  UINT16_C(   47252),  UINT16_C(   33098),  UINT16_C(    7353),
         UINT16_C(   61348),  UINT16_C(   64627),  UINT16_C(    6987),  UINT16_C(   34685) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4x3_t val = {{
        simde_vld1_u16(test_vec[i].val[0]),
        simde_vld1_u16(test_vec[i].val[1]),
        simde_vld1_u16(test_vec[i].val[2]),
    }};
    uint16_t r_[12];
    simde_vst1_u16_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_u32_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t val[3][2];
    uint32_t r[6];
  } test_vec[] = {
  { { {  UINT32_C(  3151709013),  UINT32_C(  3851505735)  },
      {  UINT32_C(  3883147292),  UINT32_C(  1205304659)  },
      {  UINT32_C(  1898658516),  UINT32_C(  3490283851)  } },
      {  UINT32_C(  3151709013),  UINT32_C(  3851505735),  UINT32_C(  3883147292),  UINT32_C(  1205304659),  UINT32_C(  1898658516),  UINT32_C(  3490283851) } },
  { { {  UINT32_C(  1465046976),  UINT32_C(  1747483342)  },
      {  UINT32_C(  1470062232),  UINT32_C(  3900051048)  },
      {  UINT32_C(   305497471),  UINT32_C(   826784224)  } },
      {  UINT32_C(  1465046976),  UINT32_C(  1747483342),  UINT32_C(  1470062232),  UINT32_C(  3900051048),  UINT32_C(   305497471),  UINT32_C(   826784224) } },
  { { {  UINT32_C(  2788475070),  UINT32_C(  2719759107)  },
      {  UINT32_C(   416706703),  UINT32_C(   692459732)  },
      {  UINT32_C(   622778214),  UINT32_C(   323072924)  } },
      {  UINT32_C(  2788475070),  UINT32_C(  2719759107),  UINT32_C(   416706703),  UINT32_C(   692459732),  UINT32_C(   622778214),  UINT32_C(   323072924) } },
  { { {  UINT32_C(  1222511208),  UINT32_C(  1493224890)  },
      {  UINT32_C(  2803786207),  UINT32_C(  3927290950)  },
      {  UINT32_C(  3691147638),  UINT32_C(  1340365329)  } },
      {  UINT32_C(  1222511208),  UINT32_C(  1493224890),  UINT32_C(  2803786207),  UINT32_C(  3927290950),  UINT32_C(  3691147638),  UINT32_C(  1340365329) } },
  { { {  UINT32_C(  3351375671),  UINT32_C(  3398780649)  },
      {  UINT32_C(   473721831),  UINT32_C(  1971040098)  },
      {  UINT32_C(  1737390388),  UINT32_C(  3665586662)  } },
      {  UINT32_C(  3351375671),  UINT32_C(  3398780649),  UINT32_C(   473721831),  UINT32_C(  1971040098),  UINT32_C(  1737390388),  UINT32_C(  3665586662) } },
  { { {  UINT32_C(   461214655),  UINT32_C(  2812339437)  },
      {  UINT32_C(  2926968085),  UINT32_C(   664051992)  },
      {  UINT32_C(   329299498),  UINT32_C(  1040002180)  } },
      {  UINT32_C(   461214655),  UINT32_C(  2812339437),  UINT32_C(  2926968085),  UINT32_C(   664051992),  UINT32_C(   329299498),  UINT32_C(  1040002180) } },
  { { {  UINT32_C(  2275614879),  UINT32_C(  4038460170)  },
      {  UINT32_C(  1594668307),  UINT32_C(   258291876)  },
      {  UINT32_C(  4216361233),  UINT32_C(  1734898915)  } },
      {  UINT32_C(  2275614879),  UINT32_C(  4038460170),  UINT32_C(  1594668307),  UINT32_C(   258291876),  UINT32_C(  4216361233),  UINT32_C(  1734898915) } },
  { { {  UINT32_C(   895091055),  UINT32_C(  2947398955)  },
      {  UINT32_C(    25819220),  UINT32_C(  2704696261)  },
      {  UINT32_C(     6440487),  UINT32_C(  2572228325)  } },
      {  UINT32_C(   895091055),  UINT32_C(  2947398955),  UINT32_C(    25819220),  UINT32_C(  2704696261),  UINT32_C(     6440487),  UINT32_C(  2572228325) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2x3_t val = {{
        simde_vld1_u32(test_vec[i].val[0]),
        simde_vld1_u32(test_vec[i].val[1]),
        simde_vld1_u32(test_vec[i].val[2]),
    }};
    uint32_t r_[6];
    simde_vst1_u32_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_u64_x3 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t val[3][1];
    uint64_t r[3];
  } test_vec[] = {
  { { {  UINT64_C(13696862663724501296)  },
      {  UINT64_C( 2407586688617891272)  },
      {  UINT64_C(13350810269838252643)  } },
      {  UINT64_C(13696862663724501296),  UINT64_C( 2407586688617891272),  UINT64_C(13350810269838252643) } },
  { { {  UINT64_C( 4855481413974911935)  },
      {  UINT64_C( 9137964526324786639)  },
      {  UINT64_C( 4270906361875675031)  } },
      {  UINT64_C( 4855481413974911935),  UINT64_C( 9137964526324786639),  UINT64_C( 4270906361875675031) } },
  { { {  UINT64_C(14495568871437680584)  },
      {  UINT64_C( 8350672327029912401)  },
      {  UINT64_C(15423650965611425756)  } },
      {  UINT64_C(14495568871437680584),  UINT64_C( 8350672327029912401),  UINT64_C(15423650965611425756) } },
  { { {  UINT64_C( 9362243166401489021)  },
      {  UINT64_C( 7976169275828430295)  },
      {  UINT64_C( 3850427573558057075)  } },
      {  UINT64_C( 9362243166401489021),  UINT64_C( 7976169275828430295),  UINT64_C( 3850427573558057075) } },
  { { {  UINT64_C( 3703872477303341339)  },
      {  UINT64_C(17355382681297876803)  },
      {  UINT64_C( 6632600177163728577)  } },
      {  UINT64_C( 3703872477303341339),  UINT64_C(17355382681297876803),  UINT64_C( 6632600177163728577) } },
  { { {  UINT64_C(15503143563008144409)  },
      {  UINT64_C( 1482447020981325159)  },
      {  UINT64_C(17254609295998275918)  } },
      {  UINT64_C(15503143563008144409),  UINT64_C( 1482447020981325159),  UINT64_C(17254609295998275918) } },
  { { {  UINT64_C(13260140572396091307)  },
      {  UINT64_C( 1183228426541877851)  },
      {  UINT64_C(17419033251060271135)  } },
      {  UINT64_C(13260140572396091307),  UINT64_C( 1183228426541877851),  UINT64_C(17419033251060271135) } },
  { { {  UINT64_C(11400326925112759573)  },
      {  UINT64_C(12966722910322979826)  },
      {  UINT64_C(16439512255501391600)  } },
      {  UINT64_C(11400326925112759573),  UINT64_C(12966722910322979826),  UINT64_C(16439512255501391600) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1x3_t val = {{
        simde_vld1_u64(test_vec[i].val[0]),
        simde_vld1_u64(test_vec[i].val[1]),
        simde_vld1_u64(test_vec[i].val[2]),
    }};
    uint64_t r_[3];
    simde_vst1_u64_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u64_x3)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
