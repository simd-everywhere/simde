#define SIMDE_TEST_ARM_NEON_INSN st1_x2
#include "test/test.h"
#include "test-neon.h"
#include "../../../simde/arm/neon/st1_x2.h"
#include "../../../simde/arm/neon/st1_lane.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst1_f16_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 val[2][4];
    simde_float16 r[8];
  } test_vec[] = {
  { { { SIMDE_FLOAT16_VALUE( -49.565), SIMDE_FLOAT16_VALUE( -3.779), SIMDE_FLOAT16_VALUE( -4.526),  SIMDE_FLOAT16_VALUE(  54.137)  },
      {  SIMDE_FLOAT16_VALUE(  93.243),  SIMDE_FLOAT16_VALUE(  77.887),  SIMDE_FLOAT16_VALUE(  67.064), SIMDE_FLOAT16_VALUE( -88.528)  } },
      { SIMDE_FLOAT16_VALUE( -49.565), SIMDE_FLOAT16_VALUE( -3.779), SIMDE_FLOAT16_VALUE( -4.526),  SIMDE_FLOAT16_VALUE(  54.137),  SIMDE_FLOAT16_VALUE(  93.243),  SIMDE_FLOAT16_VALUE(  77.887),  SIMDE_FLOAT16_VALUE(  67.064), SIMDE_FLOAT16_VALUE( -88.528) } },
  { { { SIMDE_FLOAT16_VALUE( -20.795),  SIMDE_FLOAT16_VALUE(  75.008), SIMDE_FLOAT16_VALUE( -10.786),  SIMDE_FLOAT16_VALUE(  61.695)  },
      { SIMDE_FLOAT16_VALUE( -13.619),  SIMDE_FLOAT16_VALUE(  27.128), SIMDE_FLOAT16_VALUE( -26.152),  SIMDE_FLOAT16_VALUE(  86.900)  } },
      { SIMDE_FLOAT16_VALUE( -20.795),  SIMDE_FLOAT16_VALUE(  75.008), SIMDE_FLOAT16_VALUE( -10.786),  SIMDE_FLOAT16_VALUE(  61.695), SIMDE_FLOAT16_VALUE( -13.619),  SIMDE_FLOAT16_VALUE(  27.128), SIMDE_FLOAT16_VALUE( -26.152),  SIMDE_FLOAT16_VALUE(  86.900) } },
  { { {  SIMDE_FLOAT16_VALUE(   2.070),  SIMDE_FLOAT16_VALUE(  76.065), SIMDE_FLOAT16_VALUE( -55.688),  SIMDE_FLOAT16_VALUE(  21.829)  },
      { SIMDE_FLOAT16_VALUE( -92.596),  SIMDE_FLOAT16_VALUE(  28.101), SIMDE_FLOAT16_VALUE( -53.959), SIMDE_FLOAT16_VALUE( -93.775)  } },
      {  SIMDE_FLOAT16_VALUE(   2.070),  SIMDE_FLOAT16_VALUE(  76.065), SIMDE_FLOAT16_VALUE( -55.688),  SIMDE_FLOAT16_VALUE(  21.829), SIMDE_FLOAT16_VALUE( -92.596),  SIMDE_FLOAT16_VALUE(  28.101), SIMDE_FLOAT16_VALUE( -53.959), SIMDE_FLOAT16_VALUE( -93.775) } },
  { { {  SIMDE_FLOAT16_VALUE(  35.951),  SIMDE_FLOAT16_VALUE(  62.015),  SIMDE_FLOAT16_VALUE(  90.532),  SIMDE_FLOAT16_VALUE(  31.925)  },
      { SIMDE_FLOAT16_VALUE( -46.722), SIMDE_FLOAT16_VALUE( -97.917),  SIMDE_FLOAT16_VALUE(  38.448), SIMDE_FLOAT16_VALUE( -24.373)  } },
      {  SIMDE_FLOAT16_VALUE(  35.951),  SIMDE_FLOAT16_VALUE(  62.015),  SIMDE_FLOAT16_VALUE(  90.532),  SIMDE_FLOAT16_VALUE(  31.925), SIMDE_FLOAT16_VALUE( -46.722), SIMDE_FLOAT16_VALUE( -97.917),  SIMDE_FLOAT16_VALUE(  38.448), SIMDE_FLOAT16_VALUE( -24.373) } },
  { { { SIMDE_FLOAT16_VALUE( -51.687),  SIMDE_FLOAT16_VALUE(  48.322),  SIMDE_FLOAT16_VALUE(  69.086), SIMDE_FLOAT16_VALUE( -54.351)  },
      { SIMDE_FLOAT16_VALUE( -64.082), SIMDE_FLOAT16_VALUE( -98.147), SIMDE_FLOAT16_VALUE( -46.114), SIMDE_FLOAT16_VALUE( -18.794)  } },
      { SIMDE_FLOAT16_VALUE( -51.687),  SIMDE_FLOAT16_VALUE(  48.322),  SIMDE_FLOAT16_VALUE(  69.086), SIMDE_FLOAT16_VALUE( -54.351), SIMDE_FLOAT16_VALUE( -64.082), SIMDE_FLOAT16_VALUE( -98.147), SIMDE_FLOAT16_VALUE( -46.114), SIMDE_FLOAT16_VALUE( -18.794) } },
  { { {  SIMDE_FLOAT16_VALUE(  68.290),  SIMDE_FLOAT16_VALUE(  85.741), SIMDE_FLOAT16_VALUE( -41.817), SIMDE_FLOAT16_VALUE( -53.220)  },
      { SIMDE_FLOAT16_VALUE( -75.047),  SIMDE_FLOAT16_VALUE(  76.317), SIMDE_FLOAT16_VALUE( -59.770),  SIMDE_FLOAT16_VALUE(  34.185)  } },
      {  SIMDE_FLOAT16_VALUE(  68.290),  SIMDE_FLOAT16_VALUE(  85.741), SIMDE_FLOAT16_VALUE( -41.817), SIMDE_FLOAT16_VALUE( -53.220), SIMDE_FLOAT16_VALUE( -75.047),  SIMDE_FLOAT16_VALUE(  76.317), SIMDE_FLOAT16_VALUE( -59.770),  SIMDE_FLOAT16_VALUE(  34.185) } },
  { { { SIMDE_FLOAT16_VALUE( -15.653), SIMDE_FLOAT16_VALUE( -73.326), SIMDE_FLOAT16_VALUE( -11.883), SIMDE_FLOAT16_VALUE( -37.580)  },
      { SIMDE_FLOAT16_VALUE( -25.858), SIMDE_FLOAT16_VALUE( -61.674),  SIMDE_FLOAT16_VALUE(  40.814), SIMDE_FLOAT16_VALUE( -12.611)  } },
      { SIMDE_FLOAT16_VALUE( -15.653), SIMDE_FLOAT16_VALUE( -73.326), SIMDE_FLOAT16_VALUE( -11.883), SIMDE_FLOAT16_VALUE( -37.580), SIMDE_FLOAT16_VALUE( -25.858), SIMDE_FLOAT16_VALUE( -61.674),  SIMDE_FLOAT16_VALUE(  40.814), SIMDE_FLOAT16_VALUE( -12.611) } },
  { { { SIMDE_FLOAT16_VALUE( -22.246), SIMDE_FLOAT16_VALUE( -57.414), SIMDE_FLOAT16_VALUE( -85.821),  SIMDE_FLOAT16_VALUE(  94.244)  },
      { SIMDE_FLOAT16_VALUE( -24.985),  SIMDE_FLOAT16_VALUE(  26.320),  SIMDE_FLOAT16_VALUE(  45.671),  SIMDE_FLOAT16_VALUE(  30.999)  } },
      { SIMDE_FLOAT16_VALUE( -22.246), SIMDE_FLOAT16_VALUE( -57.414), SIMDE_FLOAT16_VALUE( -85.821),  SIMDE_FLOAT16_VALUE(  94.244), SIMDE_FLOAT16_VALUE( -24.985),  SIMDE_FLOAT16_VALUE(  26.320),  SIMDE_FLOAT16_VALUE(  45.671),  SIMDE_FLOAT16_VALUE(  30.999) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float16x4x2_t val = {{
        simde_vld1_f16(test_vec[i].val[0]),
        simde_vld1_f16(test_vec[i].val[1]),
    }};
    simde_float16 r_[8];
    simde_vst1_f16_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_f32_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 val[2][2];
    simde_float32 r[4];
  } test_vec[] = {
  { { {  SIMDE_FLOAT32_C(  6843.736),  SIMDE_FLOAT32_C(  9865.703)  },
      { -SIMDE_FLOAT32_C(  6900.860), -SIMDE_FLOAT32_C(  4662.413)  } },
      {  SIMDE_FLOAT32_C(  6843.736),  SIMDE_FLOAT32_C(  9865.703), -SIMDE_FLOAT32_C(  6900.860), -SIMDE_FLOAT32_C(  4662.413) } },
  { { { -SIMDE_FLOAT32_C(  4356.780), -SIMDE_FLOAT32_C(  6410.902)  },
      {  SIMDE_FLOAT32_C(   896.456), -SIMDE_FLOAT32_C(  7733.802)  } },
      { -SIMDE_FLOAT32_C(  4356.780), -SIMDE_FLOAT32_C(  6410.902),  SIMDE_FLOAT32_C(   896.456), -SIMDE_FLOAT32_C(  7733.802) } },
  { { {  SIMDE_FLOAT32_C(  5819.666),  SIMDE_FLOAT32_C(  5409.103)  },
      {  SIMDE_FLOAT32_C(  3023.927), -SIMDE_FLOAT32_C(  5003.722)  } },
      {  SIMDE_FLOAT32_C(  5819.666),  SIMDE_FLOAT32_C(  5409.103),  SIMDE_FLOAT32_C(  3023.927), -SIMDE_FLOAT32_C(  5003.722) } },
  { { {  SIMDE_FLOAT32_C(  6551.521), -SIMDE_FLOAT32_C(   532.100)  },
      {  SIMDE_FLOAT32_C(  9165.000), -SIMDE_FLOAT32_C(   764.496)  } },
      {  SIMDE_FLOAT32_C(  6551.521), -SIMDE_FLOAT32_C(   532.100),  SIMDE_FLOAT32_C(  9165.000), -SIMDE_FLOAT32_C(   764.496) } },
  { { { -SIMDE_FLOAT32_C(  9531.305),  SIMDE_FLOAT32_C(  4615.365)  },
      { -SIMDE_FLOAT32_C(  9355.624),  SIMDE_FLOAT32_C(  2251.278)  } },
      { -SIMDE_FLOAT32_C(  9531.305),  SIMDE_FLOAT32_C(  4615.365), -SIMDE_FLOAT32_C(  9355.624),  SIMDE_FLOAT32_C(  2251.278) } },
  { { { -SIMDE_FLOAT32_C(  5229.114),  SIMDE_FLOAT32_C(  1551.494)  },
      { -SIMDE_FLOAT32_C(  1295.303), -SIMDE_FLOAT32_C(  5479.659)  } },
      { -SIMDE_FLOAT32_C(  5229.114),  SIMDE_FLOAT32_C(  1551.494), -SIMDE_FLOAT32_C(  1295.303), -SIMDE_FLOAT32_C(  5479.659) } },
  { { {  SIMDE_FLOAT32_C(  1820.891), -SIMDE_FLOAT32_C(  7016.534)  },
      { -SIMDE_FLOAT32_C(  1326.924), -SIMDE_FLOAT32_C(  5351.269)  } },
      {  SIMDE_FLOAT32_C(  1820.891), -SIMDE_FLOAT32_C(  7016.534), -SIMDE_FLOAT32_C(  1326.924), -SIMDE_FLOAT32_C(  5351.269) } },
  { { { -SIMDE_FLOAT32_C(  8510.635), -SIMDE_FLOAT32_C(  5107.335)  },
      { -SIMDE_FLOAT32_C(  2854.852), -SIMDE_FLOAT32_C(  8948.875)  } },
      { -SIMDE_FLOAT32_C(  8510.635), -SIMDE_FLOAT32_C(  5107.335), -SIMDE_FLOAT32_C(  2854.852), -SIMDE_FLOAT32_C(  8948.875) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2x2_t val = {{
        simde_vld1_f32(test_vec[i].val[0]),
        simde_vld1_f32(test_vec[i].val[1]),
    }};
    simde_float32 r_[8];
    simde_vst1_f32_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_f64_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 val[2][1];
    simde_float64 r[2];
  } test_vec[] = {
  { { { -SIMDE_FLOAT64_C(   27933.750)  },
      {  SIMDE_FLOAT64_C(  985309.375)  } },
      { -SIMDE_FLOAT64_C(   27933.750),  SIMDE_FLOAT64_C(  985309.375) } },
  { { { -SIMDE_FLOAT64_C(  378689.625)  },
      { -SIMDE_FLOAT64_C(  916079.500)  } },
      { -SIMDE_FLOAT64_C(  378689.625), -SIMDE_FLOAT64_C(  916079.500) } },
  { { {  SIMDE_FLOAT64_C(  734894.750)  },
      { -SIMDE_FLOAT64_C(  642386.125)  } },
      {  SIMDE_FLOAT64_C(  734894.750), -SIMDE_FLOAT64_C(  642386.125) } },
  { { { -SIMDE_FLOAT64_C(   36451.062)  },
      { -SIMDE_FLOAT64_C(  365898.188)  } },
      { -SIMDE_FLOAT64_C(   36451.062), -SIMDE_FLOAT64_C(  365898.188) } },
  { { {  SIMDE_FLOAT64_C(  258655.250)  },
      {  SIMDE_FLOAT64_C(  710758.500)  } },
      {  SIMDE_FLOAT64_C(  258655.250),  SIMDE_FLOAT64_C(  710758.500) } },
  { { { -SIMDE_FLOAT64_C(  657571.250)  },
      {  SIMDE_FLOAT64_C(  650595.250)  } },
      { -SIMDE_FLOAT64_C(  657571.250),  SIMDE_FLOAT64_C(  650595.250) } },
  { { {  SIMDE_FLOAT64_C(  792135.875)  },
      {  SIMDE_FLOAT64_C(  544038.375)  } },
      {  SIMDE_FLOAT64_C(  792135.875),  SIMDE_FLOAT64_C(  544038.375) } },
  { { { -SIMDE_FLOAT64_C(  112184.125)  },
      {  SIMDE_FLOAT64_C(  244829.750)  } },
      { -SIMDE_FLOAT64_C(  112184.125),  SIMDE_FLOAT64_C(  244829.750) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1x2_t val = {{
        simde_vld1_f64(test_vec[i].val[0]),
        simde_vld1_f64(test_vec[i].val[1]),
    }};
    simde_float64 r_[2];
    simde_vst1_f64_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_s8_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t val[2][8];
    int8_t r[16];
  } test_vec[] = {
  { { {  INT8_C(   43), -INT8_C(  106), -INT8_C(   56), -INT8_C(  105), -INT8_C(   65),  INT8_C(   89),  INT8_C(   95),  INT8_C(   90)  },
      { -INT8_C(   85), -INT8_C(   36), -INT8_C(   36),  INT8_C(   68), -INT8_C(    5), -INT8_C(   92), -INT8_C(   48), -INT8_C(  107)  } },
      {  INT8_C(   43), -INT8_C(  106), -INT8_C(   56), -INT8_C(  105), -INT8_C(   65),  INT8_C(   89),  INT8_C(   95),  INT8_C(   90), -INT8_C(   85), -INT8_C(   36), -INT8_C(   36),  INT8_C(   68), -INT8_C(    5), -INT8_C(   92), -INT8_C(   48), -INT8_C(  107) } },
  { { { -INT8_C(   86),  INT8_C(  111),  INT8_C(  122),  INT8_C(  101),  INT8_C(   77), -INT8_C(  120),  INT8_C(   72), -INT8_C(   61)  },
      {  INT8_C(   96),  INT8_C(   35),  INT8_C(   25), -INT8_C(   21),  INT8_C(   44), -INT8_C(   76),  INT8_C(    7), -INT8_C(   94)  } },
      { -INT8_C(   86),  INT8_C(  111),  INT8_C(  122),  INT8_C(  101),  INT8_C(   77), -INT8_C(  120),  INT8_C(   72), -INT8_C(   61),  INT8_C(   96),  INT8_C(   35),  INT8_C(   25), -INT8_C(   21),  INT8_C(   44), -INT8_C(   76),  INT8_C(    7), -INT8_C(   94) } },
  { { { -INT8_C(   51),  INT8_C(   78), -INT8_C(   38), -INT8_C(    3),  INT8_C(   48), -INT8_C(   78), -INT8_C(  112),  INT8_C(   37)  },
      { -INT8_C(   92), -INT8_C(   48), -INT8_C(   62),  INT8_C(   92),  INT8_C(   32), -INT8_C(   69),  INT8_C(   52),  INT8_C(   28)  } },
      { -INT8_C(   51),  INT8_C(   78), -INT8_C(   38), -INT8_C(    3),  INT8_C(   48), -INT8_C(   78), -INT8_C(  112),  INT8_C(   37), -INT8_C(   92), -INT8_C(   48), -INT8_C(   62),  INT8_C(   92),  INT8_C(   32), -INT8_C(   69),  INT8_C(   52),  INT8_C(   28) } },
  { { { -INT8_C(  117),  INT8_C(  120), -INT8_C(   22),  INT8_C(  103),  INT8_C(   81), -INT8_C(   57),  INT8_C(   28), -INT8_C(   79)  },
      {  INT8_C(   61),  INT8_C(   51),  INT8_C(   77), -INT8_C(   91),  INT8_C(   63), -INT8_C(    4),  INT8_C(   72),  INT8_C(    5)  } },
      { -INT8_C(  117),  INT8_C(  120), -INT8_C(   22),  INT8_C(  103),  INT8_C(   81), -INT8_C(   57),  INT8_C(   28), -INT8_C(   79),  INT8_C(   61),  INT8_C(   51),  INT8_C(   77), -INT8_C(   91),  INT8_C(   63), -INT8_C(    4),  INT8_C(   72),  INT8_C(    5) } },
  { { { -INT8_C(   11),  INT8_C(  103), -INT8_C(  124),  INT8_C(    9), -INT8_C(  123),  INT8_C(   71),  INT8_C(    9),  INT8_C(   36)  },
      {  INT8_C(   38), -INT8_C(  103),  INT8_C(   77),  INT8_C(   25), -INT8_C(   45), -INT8_C(   41),  INT8_C(   97),  INT8_C(  110)  } },
      { -INT8_C(   11),  INT8_C(  103), -INT8_C(  124),  INT8_C(    9), -INT8_C(  123),  INT8_C(   71),  INT8_C(    9),  INT8_C(   36),  INT8_C(   38), -INT8_C(  103),  INT8_C(   77),  INT8_C(   25), -INT8_C(   45), -INT8_C(   41),  INT8_C(   97),  INT8_C(  110) } },
  { { {  INT8_C(    9),  INT8_C(   76),  INT8_C(   87),  INT8_C(   72), -INT8_C(    6),  INT8_C(   20), -INT8_C(   51), -INT8_C(   39)  },
      { -INT8_C(   78),  INT8_C(   74), -INT8_C(   85), -INT8_C(   63), -INT8_C(    1),  INT8_C(   77),  INT8_C(   88), -INT8_C(  114)  } },
      {  INT8_C(    9),  INT8_C(   76),  INT8_C(   87),  INT8_C(   72), -INT8_C(    6),  INT8_C(   20), -INT8_C(   51), -INT8_C(   39), -INT8_C(   78),  INT8_C(   74), -INT8_C(   85), -INT8_C(   63), -INT8_C(    1),  INT8_C(   77),  INT8_C(   88), -INT8_C(  114) } },
  { { {  INT8_C(  109), -INT8_C(  120), -INT8_C(   21),  INT8_C(   73), -INT8_C(    7), -INT8_C(   77), -INT8_C(   91), -INT8_C(   42)  },
      {  INT8_C(    1),  INT8_C(   29), -INT8_C(   67), -INT8_C(   76),  INT8_C(  110), -INT8_C(   36),  INT8_C(   55), -INT8_C(   31)  } },
      {  INT8_C(  109), -INT8_C(  120), -INT8_C(   21),  INT8_C(   73), -INT8_C(    7), -INT8_C(   77), -INT8_C(   91), -INT8_C(   42),  INT8_C(    1),  INT8_C(   29), -INT8_C(   67), -INT8_C(   76),  INT8_C(  110), -INT8_C(   36),  INT8_C(   55), -INT8_C(   31) } },
  { { {  INT8_C(   46),  INT8_C(   30), -INT8_C(   27),  INT8_C(   21), -INT8_C(   57), -INT8_C(   29), -INT8_C(   57),  INT8_C(  121)  },
      {  INT8_C(   97),  INT8_C(   10),  INT8_C(   78), -INT8_C(   95), -INT8_C(   60),  INT8_C(   41), -INT8_C(   34),  INT8_C(   92)  } },
      {  INT8_C(   46),  INT8_C(   30), -INT8_C(   27),  INT8_C(   21), -INT8_C(   57), -INT8_C(   29), -INT8_C(   57),  INT8_C(  121),  INT8_C(   97),  INT8_C(   10),  INT8_C(   78), -INT8_C(   95), -INT8_C(   60),  INT8_C(   41), -INT8_C(   34),  INT8_C(   92) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8x2_t val = {{
        simde_vld1_s8(test_vec[i].val[0]),
        simde_vld1_s8(test_vec[i].val[1]),
    }};
    int8_t r_[16];
    simde_vst1_s8_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_s16_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t val[2][4];
    int16_t r[8];
  } test_vec[] = {
  { { { -INT16_C(     430),  INT16_C(    8647),  INT16_C(   15507),  INT16_C(   28746)  },
      {  INT16_C(   16544), -INT16_C(   29370),  INT16_C(   24798), -INT16_C(   25330)  } },
      { -INT16_C(     430),  INT16_C(    8647),  INT16_C(   15507),  INT16_C(   28746),  INT16_C(   16544), -INT16_C(   29370),  INT16_C(   24798), -INT16_C(   25330) } },
  { { { -INT16_C(   19178), -INT16_C(   20620), -INT16_C(    8560), -INT16_C(    5595)  },
      { -INT16_C(    1507),  INT16_C(   29881), -INT16_C(   26940), -INT16_C(   14413)  } },
      { -INT16_C(   19178), -INT16_C(   20620), -INT16_C(    8560), -INT16_C(    5595), -INT16_C(    1507),  INT16_C(   29881), -INT16_C(   26940), -INT16_C(   14413) } },
  { { { -INT16_C(   23315),  INT16_C(   12937), -INT16_C(    1507),  INT16_C(   17021)  },
      { -INT16_C(   14299),  INT16_C(    4233), -INT16_C(   24539),  INT16_C(    1706)  } },
      { -INT16_C(   23315),  INT16_C(   12937), -INT16_C(    1507),  INT16_C(   17021), -INT16_C(   14299),  INT16_C(    4233), -INT16_C(   24539),  INT16_C(    1706) } },
  { { { -INT16_C(   23634),  INT16_C(   15057),  INT16_C(   14812),  INT16_C(   28080)  },
      { -INT16_C(   30208), -INT16_C(   13163), -INT16_C(   10120), -INT16_C(   19846)  } },
      { -INT16_C(   23634),  INT16_C(   15057),  INT16_C(   14812),  INT16_C(   28080), -INT16_C(   30208), -INT16_C(   13163), -INT16_C(   10120), -INT16_C(   19846) } },
  { { { -INT16_C(    3201),  INT16_C(   31196), -INT16_C(    3705), -INT16_C(    8314)  },
      {  INT16_C(   23971), -INT16_C(   30454),  INT16_C(   22943),  INT16_C(   31984)  } },
      { -INT16_C(    3201),  INT16_C(   31196), -INT16_C(    3705), -INT16_C(    8314),  INT16_C(   23971), -INT16_C(   30454),  INT16_C(   22943),  INT16_C(   31984) } },
  { { {  INT16_C(   17792), -INT16_C(   18913), -INT16_C(   11405),  INT16_C(    3997)  },
      { -INT16_C(    2025),  INT16_C(   26877), -INT16_C(   30132), -INT16_C(   14646)  } },
      {  INT16_C(   17792), -INT16_C(   18913), -INT16_C(   11405),  INT16_C(    3997), -INT16_C(    2025),  INT16_C(   26877), -INT16_C(   30132), -INT16_C(   14646) } },
  { { { -INT16_C(    2982),  INT16_C(     472),  INT16_C(   25814),  INT16_C(   24659)  },
      { -INT16_C(   11101),  INT16_C(    6252), -INT16_C(    9261),  INT16_C(   17150)  } },
      { -INT16_C(    2982),  INT16_C(     472),  INT16_C(   25814),  INT16_C(   24659), -INT16_C(   11101),  INT16_C(    6252), -INT16_C(    9261),  INT16_C(   17150) } },
  { { { -INT16_C(   24836),  INT16_C(    6770),  INT16_C(   24259),  INT16_C(   27225)  },
      {  INT16_C(   12050), -INT16_C(    7103), -INT16_C(   24422),  INT16_C(   22634)  } },
      { -INT16_C(   24836),  INT16_C(    6770),  INT16_C(   24259),  INT16_C(   27225),  INT16_C(   12050), -INT16_C(    7103), -INT16_C(   24422),  INT16_C(   22634) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4x2_t val = {{
        simde_vld1_s16(test_vec[i].val[0]),
        simde_vld1_s16(test_vec[i].val[1]),
    }};
    int16_t r_[8];
    simde_vst1_s16_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_s32_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t val[2][2];
    int32_t r[4];
  } test_vec[] = {
  { { { -INT32_C(   869086191), -INT32_C(    31153350)  },
      {  INT32_C(   507976144), -INT32_C(  2123170651)  } },
      { -INT32_C(   869086191), -INT32_C(    31153350),  INT32_C(   507976144), -INT32_C(  2123170651) } },
  { { {  INT32_C(  1375081450), -INT32_C(  2016407852)  },
      { -INT32_C(    47408143), -INT32_C(   134069981)  } },
      {  INT32_C(  1375081450), -INT32_C(  2016407852), -INT32_C(    47408143), -INT32_C(   134069981) } },
  { { {  INT32_C(  2073244503),  INT32_C(   239388107)  },
      {  INT32_C(   331401192), -INT32_C(  1838962674)  } },
      {  INT32_C(  2073244503),  INT32_C(   239388107),  INT32_C(   331401192), -INT32_C(  1838962674) } },
  { { { -INT32_C(  1143883097),  INT32_C(  1675838421)  },
      {  INT32_C(  1407775326),  INT32_C(   949290301)  } },
      { -INT32_C(  1143883097),  INT32_C(  1675838421),  INT32_C(  1407775326),  INT32_C(   949290301) } },
  { { { -INT32_C(   656118503),  INT32_C(   393652553)  },
      {  INT32_C(  1876651307),  INT32_C(   985305231)  } },
      { -INT32_C(   656118503),  INT32_C(   393652553),  INT32_C(  1876651307),  INT32_C(   985305231) } },
  { { { -INT32_C(  1114525722),  INT32_C(  1143578559)  },
      {  INT32_C(  1706882667), -INT32_C(  1262256001)  } },
      { -INT32_C(  1114525722),  INT32_C(  1143578559),  INT32_C(  1706882667), -INT32_C(  1262256001) } },
  { { {  INT32_C(  1689735679),  INT32_C(   693440475)  },
      { -INT32_C(  1360227811),  INT32_C(   758725135)  } },
      {  INT32_C(  1689735679),  INT32_C(   693440475), -INT32_C(  1360227811),  INT32_C(   758725135) } },
  { { { -INT32_C(   387390800), -INT32_C(   804645356)  },
      { -INT32_C(   396579449),  INT32_C(  1662927383)  } },
      { -INT32_C(   387390800), -INT32_C(   804645356), -INT32_C(   396579449),  INT32_C(  1662927383) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2x2_t val = {{
        simde_vld1_s32(test_vec[i].val[0]),
        simde_vld1_s32(test_vec[i].val[1]),
    }};
    int32_t r_[4];
    simde_vst1_s32_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_s64_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t val[2][1];
    int64_t r[2];
  } test_vec[] = {
  { { { -INT64_C( 8901938134320110244)  },
      { -INT64_C( 9128185153657900089)  } },
      { -INT64_C( 8901938134320110244), -INT64_C( 9128185153657900089) } },
  { { {  INT64_C( 4573054188179233432)  },
      {  INT64_C( 4434823271570029887)  } },
      {  INT64_C( 4573054188179233432),  INT64_C( 4434823271570029887) } },
  { { { -INT64_C( 7197985081443610331)  },
      {  INT64_C( 1750222726765704024)  } },
      { -INT64_C( 7197985081443610331),  INT64_C( 1750222726765704024) } },
  { { { -INT64_C( 4059912297401108859)  },
      { -INT64_C(  861296300954477787)  } },
      { -INT64_C( 4059912297401108859), -INT64_C(  861296300954477787) } },
  { { { -INT64_C( 6593327675374075153)  },
      {  INT64_C(  237853562347175554)  } },
      { -INT64_C( 6593327675374075153),  INT64_C(  237853562347175554) } },
  { { { -INT64_C( 4108115544201312954)  },
      {  INT64_C( 7475074140464521471)  } },
      { -INT64_C( 4108115544201312954),  INT64_C( 7475074140464521471) } },
  { { {  INT64_C( 8488675137191090363)  },
      {  INT64_C( 8864108287482807723)  } },
      {  INT64_C( 8488675137191090363),  INT64_C( 8864108287482807723) } },
  { { { -INT64_C(  653810091028888162)  },
      { -INT64_C( 8560851770442398385)  } },
      { -INT64_C(  653810091028888162), -INT64_C( 8560851770442398385) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1x2_t val = {{
        simde_vld1_s64(test_vec[i].val[0]),
        simde_vld1_s64(test_vec[i].val[1]),
    }};
    int64_t r_[2];
    simde_vst1_s64_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_u8_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t val[2][8];
    uint8_t r[16];
  } test_vec[] = {
  { { {  UINT8_C( 105),  UINT8_C( 113),  UINT8_C( 207),  UINT8_C(  31),  UINT8_C(   3),  UINT8_C( 246),  UINT8_C( 226),  UINT8_C(  24)  },
      {  UINT8_C( 209),  UINT8_C( 241),  UINT8_C( 210),  UINT8_C( 130),  UINT8_C( 250),  UINT8_C(  67),  UINT8_C( 182),  UINT8_C( 162)  } },
      {  UINT8_C( 105),  UINT8_C( 113),  UINT8_C( 207),  UINT8_C(  31),  UINT8_C(   3),  UINT8_C( 246),  UINT8_C( 226),  UINT8_C(  24),  UINT8_C( 209),  UINT8_C( 241),  UINT8_C( 210),  UINT8_C( 130),  UINT8_C( 250),  UINT8_C(  67),  UINT8_C( 182),  UINT8_C( 162) } },
  { { {  UINT8_C(  91),  UINT8_C( 104),  UINT8_C( 251),  UINT8_C( 221),  UINT8_C( 115),  UINT8_C(   7),  UINT8_C(  63),  UINT8_C( 170)  },
      {  UINT8_C(   3),  UINT8_C(  57),  UINT8_C(  82),  UINT8_C(   6),  UINT8_C( 238),  UINT8_C( 113),  UINT8_C(  44),  UINT8_C(  82)  } },
      {  UINT8_C(  91),  UINT8_C( 104),  UINT8_C( 251),  UINT8_C( 221),  UINT8_C( 115),  UINT8_C(   7),  UINT8_C(  63),  UINT8_C( 170),  UINT8_C(   3),  UINT8_C(  57),  UINT8_C(  82),  UINT8_C(   6),  UINT8_C( 238),  UINT8_C( 113),  UINT8_C(  44),  UINT8_C(  82) } },
  { { {  UINT8_C( 212),  UINT8_C( 145),  UINT8_C( 138),  UINT8_C( 117),  UINT8_C( 141),  UINT8_C(  47),  UINT8_C( 186),  UINT8_C(  68)  },
      {  UINT8_C(  35),  UINT8_C( 104),  UINT8_C( 216),  UINT8_C(  21),  UINT8_C( 132),  UINT8_C( 202),  UINT8_C(  30),  UINT8_C( 252)  } },
      {  UINT8_C( 212),  UINT8_C( 145),  UINT8_C( 138),  UINT8_C( 117),  UINT8_C( 141),  UINT8_C(  47),  UINT8_C( 186),  UINT8_C(  68),  UINT8_C(  35),  UINT8_C( 104),  UINT8_C( 216),  UINT8_C(  21),  UINT8_C( 132),  UINT8_C( 202),  UINT8_C(  30),  UINT8_C( 252) } },
  { { {  UINT8_C( 122),  UINT8_C(  10),  UINT8_C(  68),  UINT8_C( 149),  UINT8_C(  16),  UINT8_C( 222),  UINT8_C(  64),  UINT8_C( 218)  },
      {  UINT8_C(  75),  UINT8_C(  62),  UINT8_C( 101),  UINT8_C( 187),  UINT8_C( 154),  UINT8_C( 121),  UINT8_C( 211),  UINT8_C( 113)  } },
      {  UINT8_C( 122),  UINT8_C(  10),  UINT8_C(  68),  UINT8_C( 149),  UINT8_C(  16),  UINT8_C( 222),  UINT8_C(  64),  UINT8_C( 218),  UINT8_C(  75),  UINT8_C(  62),  UINT8_C( 101),  UINT8_C( 187),  UINT8_C( 154),  UINT8_C( 121),  UINT8_C( 211),  UINT8_C( 113) } },
  { { {  UINT8_C( 132),  UINT8_C( 159),  UINT8_C(  19),  UINT8_C(  41),  UINT8_C( 227),  UINT8_C( 194),  UINT8_C( 166),  UINT8_C( 204)  },
      {  UINT8_C( 189),  UINT8_C( 170),  UINT8_C(  20),  UINT8_C( 218),  UINT8_C(   6),  UINT8_C( 205),  UINT8_C( 162),  UINT8_C( 221)  } },
      {  UINT8_C( 132),  UINT8_C( 159),  UINT8_C(  19),  UINT8_C(  41),  UINT8_C( 227),  UINT8_C( 194),  UINT8_C( 166),  UINT8_C( 204),  UINT8_C( 189),  UINT8_C( 170),  UINT8_C(  20),  UINT8_C( 218),  UINT8_C(   6),  UINT8_C( 205),  UINT8_C( 162),  UINT8_C( 221) } },
  { { {  UINT8_C( 175),  UINT8_C( 156),  UINT8_C(  16),  UINT8_C( 222),  UINT8_C( 166),  UINT8_C( 249),  UINT8_C(   3),  UINT8_C( 232)  },
      {  UINT8_C( 243),  UINT8_C( 232),  UINT8_C( 101),  UINT8_C( 156),  UINT8_C( 189),  UINT8_C(  34),  UINT8_C( 241),  UINT8_C( 159)  } },
      {  UINT8_C( 175),  UINT8_C( 156),  UINT8_C(  16),  UINT8_C( 222),  UINT8_C( 166),  UINT8_C( 249),  UINT8_C(   3),  UINT8_C( 232),  UINT8_C( 243),  UINT8_C( 232),  UINT8_C( 101),  UINT8_C( 156),  UINT8_C( 189),  UINT8_C(  34),  UINT8_C( 241),  UINT8_C( 159) } },
  { { {  UINT8_C( 177),  UINT8_C( 178),  UINT8_C(  71),  UINT8_C( 217),  UINT8_C(  47),  UINT8_C( 163),  UINT8_C( 208),  UINT8_C( 139)  },
      {  UINT8_C( 219),  UINT8_C(  72),  UINT8_C(  33),  UINT8_C( 180),  UINT8_C(  30),  UINT8_C(  46),  UINT8_C(  48),  UINT8_C(   5)  } },
      {  UINT8_C( 177),  UINT8_C( 178),  UINT8_C(  71),  UINT8_C( 217),  UINT8_C(  47),  UINT8_C( 163),  UINT8_C( 208),  UINT8_C( 139),  UINT8_C( 219),  UINT8_C(  72),  UINT8_C(  33),  UINT8_C( 180),  UINT8_C(  30),  UINT8_C(  46),  UINT8_C(  48),  UINT8_C(   5) } },
  { { {  UINT8_C( 249),  UINT8_C( 112),  UINT8_C(  40),  UINT8_C( 235),  UINT8_C( 243),  UINT8_C( 111),  UINT8_C(   7),  UINT8_C(  39)  },
      {  UINT8_C( 229),  UINT8_C( 170),  UINT8_C( 149),  UINT8_C( 132),  UINT8_C( 183),  UINT8_C( 153),  UINT8_C( 169),  UINT8_C( 205)  } },
      {  UINT8_C( 249),  UINT8_C( 112),  UINT8_C(  40),  UINT8_C( 235),  UINT8_C( 243),  UINT8_C( 111),  UINT8_C(   7),  UINT8_C(  39),  UINT8_C( 229),  UINT8_C( 170),  UINT8_C( 149),  UINT8_C( 132),  UINT8_C( 183),  UINT8_C( 153),  UINT8_C( 169),  UINT8_C( 205) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8x2_t val = {{
        simde_vld1_u8(test_vec[i].val[0]),
        simde_vld1_u8(test_vec[i].val[1]),
    }};
    uint8_t r_[16];
    simde_vst1_u8_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_u16_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t val[2][4];
    uint16_t r[8];
  } test_vec[] = {
  { { {  UINT16_C(   11091),  UINT16_C(    6966),  UINT16_C(   23233),  UINT16_C(   35759)  },
      {  UINT16_C(   56096),  UINT16_C(   58578),  UINT16_C(   22340),  UINT16_C(    4740)  } },
      {  UINT16_C(   11091),  UINT16_C(    6966),  UINT16_C(   23233),  UINT16_C(   35759),  UINT16_C(   56096),  UINT16_C(   58578),  UINT16_C(   22340),  UINT16_C(    4740) } },
  { { {  UINT16_C(   42022),  UINT16_C(   21487),  UINT16_C(   28995),  UINT16_C(    1640)  },
      {  UINT16_C(   33397),  UINT16_C(   50386),  UINT16_C(   36002),  UINT16_C(   47485)  } },
      {  UINT16_C(   42022),  UINT16_C(   21487),  UINT16_C(   28995),  UINT16_C(    1640),  UINT16_C(   33397),  UINT16_C(   50386),  UINT16_C(   36002),  UINT16_C(   47485) } },
  { { {  UINT16_C(   16168),  UINT16_C(   60558),  UINT16_C(   48319),  UINT16_C(   52357)  },
      {  UINT16_C(   31169),  UINT16_C(   24279),  UINT16_C(   55163),  UINT16_C(   24761)  } },
      {  UINT16_C(   16168),  UINT16_C(   60558),  UINT16_C(   48319),  UINT16_C(   52357),  UINT16_C(   31169),  UINT16_C(   24279),  UINT16_C(   55163),  UINT16_C(   24761) } },
  { { {  UINT16_C(   42027),  UINT16_C(   61015),  UINT16_C(   14900),  UINT16_C(   34553)  },
      {  UINT16_C(   41464),  UINT16_C(   20457),  UINT16_C(   60377),  UINT16_C(   63002)  } },
      {  UINT16_C(   42027),  UINT16_C(   61015),  UINT16_C(   14900),  UINT16_C(   34553),  UINT16_C(   41464),  UINT16_C(   20457),  UINT16_C(   60377),  UINT16_C(   63002) } },
  { { {  UINT16_C(   58393),  UINT16_C(   61899),  UINT16_C(   54978),  UINT16_C(   44112)  },
      {  UINT16_C(    1442),  UINT16_C(   54813),  UINT16_C(   25858),  UINT16_C(   12013)  } },
      {  UINT16_C(   58393),  UINT16_C(   61899),  UINT16_C(   54978),  UINT16_C(   44112),  UINT16_C(    1442),  UINT16_C(   54813),  UINT16_C(   25858),  UINT16_C(   12013) } },
  { { {  UINT16_C(   41036),  UINT16_C(   46001),  UINT16_C(    4845),  UINT16_C(    4705)  },
      {  UINT16_C(    7083),  UINT16_C(   50199),  UINT16_C(   42498),  UINT16_C(   50554)  } },
      {  UINT16_C(   41036),  UINT16_C(   46001),  UINT16_C(    4845),  UINT16_C(    4705),  UINT16_C(    7083),  UINT16_C(   50199),  UINT16_C(   42498),  UINT16_C(   50554) } },
  { { {  UINT16_C(   38904),  UINT16_C(    3594),  UINT16_C(   41490),  UINT16_C(   53434)  },
      {  UINT16_C(   31648),  UINT16_C(   34328),  UINT16_C(   29179),  UINT16_C(   12535)  } },
      {  UINT16_C(   38904),  UINT16_C(    3594),  UINT16_C(   41490),  UINT16_C(   53434),  UINT16_C(   31648),  UINT16_C(   34328),  UINT16_C(   29179),  UINT16_C(   12535) } },
  { { {  UINT16_C(   30705),  UINT16_C(   33222),  UINT16_C(   38173),  UINT16_C(   59912)  },
      {  UINT16_C(   34700),  UINT16_C(   34948),  UINT16_C(    9298),  UINT16_C(    3633)  } },
      {  UINT16_C(   30705),  UINT16_C(   33222),  UINT16_C(   38173),  UINT16_C(   59912),  UINT16_C(   34700),  UINT16_C(   34948),  UINT16_C(    9298),  UINT16_C(    3633) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4x2_t val = {{
        simde_vld1_u16(test_vec[i].val[0]),
        simde_vld1_u16(test_vec[i].val[1]),
    }};
    uint16_t r_[8];
    simde_vst1_u16_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_u32_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t val[2][2];
    uint32_t r[4];
  } test_vec[] = {
  { { {  UINT32_C(  2085679445),  UINT32_C(  2112947749)  },
      {  UINT32_C(  3854885995),  UINT32_C(  2692783157)  } },
      {  UINT32_C(  2085679445),  UINT32_C(  2112947749),  UINT32_C(  3854885995),  UINT32_C(  2692783157) } },
  { { {  UINT32_C(  2356425279),  UINT32_C(  3197462223)  },
      {  UINT32_C(  2609428061),  UINT32_C(  2845202698)  } },
      {  UINT32_C(  2356425279),  UINT32_C(  3197462223),  UINT32_C(  2609428061),  UINT32_C(  2845202698) } },
  { { {  UINT32_C(  1324390478),  UINT32_C(  2655138581)  },
      {  UINT32_C(  3707179097),  UINT32_C(  3998829221)  } },
      {  UINT32_C(  1324390478),  UINT32_C(  2655138581),  UINT32_C(  3707179097),  UINT32_C(  3998829221) } },
  { { {  UINT32_C(  2656115959),  UINT32_C(   669837764)  },
      {  UINT32_C(  3111358130),  UINT32_C(  1436646647)  } },
      {  UINT32_C(  2656115959),  UINT32_C(   669837764),  UINT32_C(  3111358130),  UINT32_C(  1436646647) } },
  { { {  UINT32_C(  4171203498),  UINT32_C(  1203375203)  },
      {  UINT32_C(  2308697854),  UINT32_C(   368967400)  } },
      {  UINT32_C(  4171203498),  UINT32_C(  1203375203),  UINT32_C(  2308697854),  UINT32_C(   368967400) } },
  { { {  UINT32_C(    66915534),  UINT32_C(   410843731)  },
      {  UINT32_C(  1744851316),  UINT32_C(   318919445)  } },
      {  UINT32_C(    66915534),  UINT32_C(   410843731),  UINT32_C(  1744851316),  UINT32_C(   318919445) } },
  { { {  UINT32_C(  2537206564),  UINT32_C(  1587518137)  },
      {  UINT32_C(  3071720023),  UINT32_C(  3684510530)  } },
      {  UINT32_C(  2537206564),  UINT32_C(  1587518137),  UINT32_C(  3071720023),  UINT32_C(  3684510530) } },
  { { {  UINT32_C(   863791690),  UINT32_C(  2868195617)  },
      {  UINT32_C(   835785309),  UINT32_C(  4269487653)  } },
      {  UINT32_C(   863791690),  UINT32_C(  2868195617),  UINT32_C(   835785309),  UINT32_C(  4269487653) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2x2_t val = {{
        simde_vld1_u32(test_vec[i].val[0]),
        simde_vld1_u32(test_vec[i].val[1]),
    }};
    uint32_t r_[4];
    simde_vst1_u32_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_u64_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t val[2][1];
    uint64_t r[2];
  } test_vec[] = {
  { { {  UINT64_C( 1231064000629912711)  },
      {  UINT64_C(15345087409264858744)  } },
      {  UINT64_C( 1231064000629912711),  UINT64_C(15345087409264858744) } },
  { { {  UINT64_C( 2681063865924700395)  },
      {  UINT64_C( 4798843605620016536)  } },
      {  UINT64_C( 2681063865924700395),  UINT64_C( 4798843605620016536) } },
  { { {  UINT64_C(14841759704911298485)  },
      {  UINT64_C(16956752176796490843)  } },
      {  UINT64_C(14841759704911298485),  UINT64_C(16956752176796490843) } },
  { { {  UINT64_C( 4013177131545649908)  },
      {  UINT64_C(17735759326592392681)  } },
      {  UINT64_C( 4013177131545649908),  UINT64_C(17735759326592392681) } },
  { { {  UINT64_C(15163077662661381366)  },
      {  UINT64_C( 9633859623966389691)  } },
      {  UINT64_C(15163077662661381366),  UINT64_C( 9633859623966389691) } },
  { { {  UINT64_C( 6692468699591056506)  },
      {  UINT64_C( 1908195998752618604)  } },
      {  UINT64_C( 6692468699591056506),  UINT64_C( 1908195998752618604) } },
  { { {  UINT64_C( 9119257606980163030)  },
      {  UINT64_C(17780128296297603341)  } },
      {  UINT64_C( 9119257606980163030),  UINT64_C(17780128296297603341) } },
  { { {  UINT64_C( 4929736945477117464)  },
      {  UINT64_C(13356827602948403618)  } },
      {  UINT64_C( 4929736945477117464),  UINT64_C(13356827602948403618) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1x2_t val = {{
        simde_vld1_u64(test_vec[i].val[0]),
        simde_vld1_u64(test_vec[i].val[1]),
    }};
    uint64_t r_[2];
    simde_vst1_u64_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_p8_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_poly8_t val[2][8];
    simde_poly8_t r[16];
  } test_vec[] = {
  { { {  UINT8_C( 105),  UINT8_C( 113),  UINT8_C( 207),  UINT8_C(  31),  UINT8_C(   3),  UINT8_C( 246),  UINT8_C( 226),  UINT8_C(  24)  },
      {  UINT8_C( 209),  UINT8_C( 241),  UINT8_C( 210),  UINT8_C( 130),  UINT8_C( 250),  UINT8_C(  67),  UINT8_C( 182),  UINT8_C( 162)  } },
      {  UINT8_C( 105),  UINT8_C( 113),  UINT8_C( 207),  UINT8_C(  31),  UINT8_C(   3),  UINT8_C( 246),  UINT8_C( 226),  UINT8_C(  24),  UINT8_C( 209),  UINT8_C( 241),  UINT8_C( 210),  UINT8_C( 130),  UINT8_C( 250),  UINT8_C(  67),  UINT8_C( 182),  UINT8_C( 162) } },
  { { {  UINT8_C(  91),  UINT8_C( 104),  UINT8_C( 251),  UINT8_C( 221),  UINT8_C( 115),  UINT8_C(   7),  UINT8_C(  63),  UINT8_C( 170)  },
      {  UINT8_C(   3),  UINT8_C(  57),  UINT8_C(  82),  UINT8_C(   6),  UINT8_C( 238),  UINT8_C( 113),  UINT8_C(  44),  UINT8_C(  82)  } },
      {  UINT8_C(  91),  UINT8_C( 104),  UINT8_C( 251),  UINT8_C( 221),  UINT8_C( 115),  UINT8_C(   7),  UINT8_C(  63),  UINT8_C( 170),  UINT8_C(   3),  UINT8_C(  57),  UINT8_C(  82),  UINT8_C(   6),  UINT8_C( 238),  UINT8_C( 113),  UINT8_C(  44),  UINT8_C(  82) } },
  { { {  UINT8_C( 212),  UINT8_C( 145),  UINT8_C( 138),  UINT8_C( 117),  UINT8_C( 141),  UINT8_C(  47),  UINT8_C( 186),  UINT8_C(  68)  },
      {  UINT8_C(  35),  UINT8_C( 104),  UINT8_C( 216),  UINT8_C(  21),  UINT8_C( 132),  UINT8_C( 202),  UINT8_C(  30),  UINT8_C( 252)  } },
      {  UINT8_C( 212),  UINT8_C( 145),  UINT8_C( 138),  UINT8_C( 117),  UINT8_C( 141),  UINT8_C(  47),  UINT8_C( 186),  UINT8_C(  68),  UINT8_C(  35),  UINT8_C( 104),  UINT8_C( 216),  UINT8_C(  21),  UINT8_C( 132),  UINT8_C( 202),  UINT8_C(  30),  UINT8_C( 252) } },
  { { {  UINT8_C( 122),  UINT8_C(  10),  UINT8_C(  68),  UINT8_C( 149),  UINT8_C(  16),  UINT8_C( 222),  UINT8_C(  64),  UINT8_C( 218)  },
      {  UINT8_C(  75),  UINT8_C(  62),  UINT8_C( 101),  UINT8_C( 187),  UINT8_C( 154),  UINT8_C( 121),  UINT8_C( 211),  UINT8_C( 113)  } },
      {  UINT8_C( 122),  UINT8_C(  10),  UINT8_C(  68),  UINT8_C( 149),  UINT8_C(  16),  UINT8_C( 222),  UINT8_C(  64),  UINT8_C( 218),  UINT8_C(  75),  UINT8_C(  62),  UINT8_C( 101),  UINT8_C( 187),  UINT8_C( 154),  UINT8_C( 121),  UINT8_C( 211),  UINT8_C( 113) } },
  { { {  UINT8_C( 132),  UINT8_C( 159),  UINT8_C(  19),  UINT8_C(  41),  UINT8_C( 227),  UINT8_C( 194),  UINT8_C( 166),  UINT8_C( 204)  },
      {  UINT8_C( 189),  UINT8_C( 170),  UINT8_C(  20),  UINT8_C( 218),  UINT8_C(   6),  UINT8_C( 205),  UINT8_C( 162),  UINT8_C( 221)  } },
      {  UINT8_C( 132),  UINT8_C( 159),  UINT8_C(  19),  UINT8_C(  41),  UINT8_C( 227),  UINT8_C( 194),  UINT8_C( 166),  UINT8_C( 204),  UINT8_C( 189),  UINT8_C( 170),  UINT8_C(  20),  UINT8_C( 218),  UINT8_C(   6),  UINT8_C( 205),  UINT8_C( 162),  UINT8_C( 221) } },
  { { {  UINT8_C( 175),  UINT8_C( 156),  UINT8_C(  16),  UINT8_C( 222),  UINT8_C( 166),  UINT8_C( 249),  UINT8_C(   3),  UINT8_C( 232)  },
      {  UINT8_C( 243),  UINT8_C( 232),  UINT8_C( 101),  UINT8_C( 156),  UINT8_C( 189),  UINT8_C(  34),  UINT8_C( 241),  UINT8_C( 159)  } },
      {  UINT8_C( 175),  UINT8_C( 156),  UINT8_C(  16),  UINT8_C( 222),  UINT8_C( 166),  UINT8_C( 249),  UINT8_C(   3),  UINT8_C( 232),  UINT8_C( 243),  UINT8_C( 232),  UINT8_C( 101),  UINT8_C( 156),  UINT8_C( 189),  UINT8_C(  34),  UINT8_C( 241),  UINT8_C( 159) } },
  { { {  UINT8_C( 177),  UINT8_C( 178),  UINT8_C(  71),  UINT8_C( 217),  UINT8_C(  47),  UINT8_C( 163),  UINT8_C( 208),  UINT8_C( 139)  },
      {  UINT8_C( 219),  UINT8_C(  72),  UINT8_C(  33),  UINT8_C( 180),  UINT8_C(  30),  UINT8_C(  46),  UINT8_C(  48),  UINT8_C(   5)  } },
      {  UINT8_C( 177),  UINT8_C( 178),  UINT8_C(  71),  UINT8_C( 217),  UINT8_C(  47),  UINT8_C( 163),  UINT8_C( 208),  UINT8_C( 139),  UINT8_C( 219),  UINT8_C(  72),  UINT8_C(  33),  UINT8_C( 180),  UINT8_C(  30),  UINT8_C(  46),  UINT8_C(  48),  UINT8_C(   5) } },
  { { {  UINT8_C( 249),  UINT8_C( 112),  UINT8_C(  40),  UINT8_C( 235),  UINT8_C( 243),  UINT8_C( 111),  UINT8_C(   7),  UINT8_C(  39)  },
      {  UINT8_C( 229),  UINT8_C( 170),  UINT8_C( 149),  UINT8_C( 132),  UINT8_C( 183),  UINT8_C( 153),  UINT8_C( 169),  UINT8_C( 205)  } },
      {  UINT8_C( 249),  UINT8_C( 112),  UINT8_C(  40),  UINT8_C( 235),  UINT8_C( 243),  UINT8_C( 111),  UINT8_C(   7),  UINT8_C(  39),  UINT8_C( 229),  UINT8_C( 170),  UINT8_C( 149),  UINT8_C( 132),  UINT8_C( 183),  UINT8_C( 153),  UINT8_C( 169),  UINT8_C( 205) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly8x8x2_t val = {{
        simde_vld1_p8(test_vec[i].val[0]),
        simde_vld1_p8(test_vec[i].val[1]),
    }};
    simde_poly8_t r_[16];
    simde_vst1_p8_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_p16_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_poly16_t val[2][4];
    simde_poly16_t r[8];
  } test_vec[] = {
  { { {  UINT16_C(   11091),  UINT16_C(    6966),  UINT16_C(   23233),  UINT16_C(   35759)  },
      {  UINT16_C(   56096),  UINT16_C(   58578),  UINT16_C(   22340),  UINT16_C(    4740)  } },
      {  UINT16_C(   11091),  UINT16_C(    6966),  UINT16_C(   23233),  UINT16_C(   35759),  UINT16_C(   56096),  UINT16_C(   58578),  UINT16_C(   22340),  UINT16_C(    4740) } },
  { { {  UINT16_C(   42022),  UINT16_C(   21487),  UINT16_C(   28995),  UINT16_C(    1640)  },
      {  UINT16_C(   33397),  UINT16_C(   50386),  UINT16_C(   36002),  UINT16_C(   47485)  } },
      {  UINT16_C(   42022),  UINT16_C(   21487),  UINT16_C(   28995),  UINT16_C(    1640),  UINT16_C(   33397),  UINT16_C(   50386),  UINT16_C(   36002),  UINT16_C(   47485) } },
  { { {  UINT16_C(   16168),  UINT16_C(   60558),  UINT16_C(   48319),  UINT16_C(   52357)  },
      {  UINT16_C(   31169),  UINT16_C(   24279),  UINT16_C(   55163),  UINT16_C(   24761)  } },
      {  UINT16_C(   16168),  UINT16_C(   60558),  UINT16_C(   48319),  UINT16_C(   52357),  UINT16_C(   31169),  UINT16_C(   24279),  UINT16_C(   55163),  UINT16_C(   24761) } },
  { { {  UINT16_C(   42027),  UINT16_C(   61015),  UINT16_C(   14900),  UINT16_C(   34553)  },
      {  UINT16_C(   41464),  UINT16_C(   20457),  UINT16_C(   60377),  UINT16_C(   63002)  } },
      {  UINT16_C(   42027),  UINT16_C(   61015),  UINT16_C(   14900),  UINT16_C(   34553),  UINT16_C(   41464),  UINT16_C(   20457),  UINT16_C(   60377),  UINT16_C(   63002) } },
  { { {  UINT16_C(   58393),  UINT16_C(   61899),  UINT16_C(   54978),  UINT16_C(   44112)  },
      {  UINT16_C(    1442),  UINT16_C(   54813),  UINT16_C(   25858),  UINT16_C(   12013)  } },
      {  UINT16_C(   58393),  UINT16_C(   61899),  UINT16_C(   54978),  UINT16_C(   44112),  UINT16_C(    1442),  UINT16_C(   54813),  UINT16_C(   25858),  UINT16_C(   12013) } },
  { { {  UINT16_C(   41036),  UINT16_C(   46001),  UINT16_C(    4845),  UINT16_C(    4705)  },
      {  UINT16_C(    7083),  UINT16_C(   50199),  UINT16_C(   42498),  UINT16_C(   50554)  } },
      {  UINT16_C(   41036),  UINT16_C(   46001),  UINT16_C(    4845),  UINT16_C(    4705),  UINT16_C(    7083),  UINT16_C(   50199),  UINT16_C(   42498),  UINT16_C(   50554) } },
  { { {  UINT16_C(   38904),  UINT16_C(    3594),  UINT16_C(   41490),  UINT16_C(   53434)  },
      {  UINT16_C(   31648),  UINT16_C(   34328),  UINT16_C(   29179),  UINT16_C(   12535)  } },
      {  UINT16_C(   38904),  UINT16_C(    3594),  UINT16_C(   41490),  UINT16_C(   53434),  UINT16_C(   31648),  UINT16_C(   34328),  UINT16_C(   29179),  UINT16_C(   12535) } },
  { { {  UINT16_C(   30705),  UINT16_C(   33222),  UINT16_C(   38173),  UINT16_C(   59912)  },
      {  UINT16_C(   34700),  UINT16_C(   34948),  UINT16_C(    9298),  UINT16_C(    3633)  } },
      {  UINT16_C(   30705),  UINT16_C(   33222),  UINT16_C(   38173),  UINT16_C(   59912),  UINT16_C(   34700),  UINT16_C(   34948),  UINT16_C(    9298),  UINT16_C(    3633) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly16x4x2_t val = {{
        simde_vld1_p16(test_vec[i].val[0]),
        simde_vld1_p16(test_vec[i].val[1]),
    }};
    simde_poly16_t r_[8];
    simde_vst1_p16_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

static int
test_simde_vst1_p64_x2 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_poly64_t val[2][1];
    simde_poly64_t r[2];
  } test_vec[] = {
  { { {  UINT64_C( 1231064000629912711)  },
      {  UINT64_C(15345087409264858744)  } },
      {  UINT64_C( 1231064000629912711),  UINT64_C(15345087409264858744) } },
  { { {  UINT64_C( 2681063865924700395)  },
      {  UINT64_C( 4798843605620016536)  } },
      {  UINT64_C( 2681063865924700395),  UINT64_C( 4798843605620016536) } },
  { { {  UINT64_C(14841759704911298485)  },
      {  UINT64_C(16956752176796490843)  } },
      {  UINT64_C(14841759704911298485),  UINT64_C(16956752176796490843) } },
  { { {  UINT64_C( 4013177131545649908)  },
      {  UINT64_C(17735759326592392681)  } },
      {  UINT64_C( 4013177131545649908),  UINT64_C(17735759326592392681) } },
  { { {  UINT64_C(15163077662661381366)  },
      {  UINT64_C( 9633859623966389691)  } },
      {  UINT64_C(15163077662661381366),  UINT64_C( 9633859623966389691) } },
  { { {  UINT64_C( 6692468699591056506)  },
      {  UINT64_C( 1908195998752618604)  } },
      {  UINT64_C( 6692468699591056506),  UINT64_C( 1908195998752618604) } },
  { { {  UINT64_C( 9119257606980163030)  },
      {  UINT64_C(17780128296297603341)  } },
      {  UINT64_C( 9119257606980163030),  UINT64_C(17780128296297603341) } },
  { { {  UINT64_C( 4929736945477117464)  },
      {  UINT64_C(13356827602948403618)  } },
      {  UINT64_C( 4929736945477117464),  UINT64_C(13356827602948403618) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly64x1x2_t val = {{
        simde_vld1_p64(test_vec[i].val[0]),
        simde_vld1_p64(test_vec[i].val[1]),
    }};
    simde_poly64_t r_[2];
    simde_vst1_p64_x2(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_p8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_p16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_p64_x2)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
