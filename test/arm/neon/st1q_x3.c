#define SIMDE_TEST_ARM_NEON_INSN st1q_x3
#include "test/test.h"
#include "test-neon.h"
#include "../../../simde/arm/neon/st1q_x3.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst1q_f16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t val[3][8];
    simde_float16_t r[24];
  } test_vec[] = {
  { { { SIMDE_FLOAT16_VALUE( - 78.006), SIMDE_FLOAT16_VALUE( - 86.214),  SIMDE_FLOAT16_VALUE( 79.768), SIMDE_FLOAT16_VALUE( - 58.640),
         SIMDE_FLOAT16_VALUE( 95.290), SIMDE_FLOAT16_VALUE( - 58.694), SIMDE_FLOAT16_VALUE( - 66.494),  SIMDE_FLOAT16_VALUE( 14.402)  },
      { SIMDE_FLOAT16_VALUE( - 73.147),  SIMDE_FLOAT16_VALUE( 86.011), SIMDE_FLOAT16_VALUE( - 57.821),  SIMDE_FLOAT16_VALUE( 39.575),
        SIMDE_FLOAT16_VALUE( - 71.723), SIMDE_FLOAT16_VALUE( - 56.950), SIMDE_FLOAT16_VALUE( - 64.715),  SIMDE_FLOAT16_VALUE( 57.900)  },
      {  SIMDE_FLOAT16_VALUE( 61.685), SIMDE_FLOAT16_VALUE( - 81.983),  SIMDE_FLOAT16_VALUE( 15.196), SIMDE_FLOAT16_VALUE( - 22.643),
         SIMDE_FLOAT16_VALUE( 73.963),  SIMDE_FLOAT16_VALUE( 69.945), SIMDE_FLOAT16_VALUE( - 18.252),  SIMDE_FLOAT16_VALUE(  6.208)  } },
      { SIMDE_FLOAT16_VALUE( - 78.006), SIMDE_FLOAT16_VALUE( - 86.214),  SIMDE_FLOAT16_VALUE( 79.768), SIMDE_FLOAT16_VALUE( - 58.640),
         SIMDE_FLOAT16_VALUE( 95.290), SIMDE_FLOAT16_VALUE( - 58.694), SIMDE_FLOAT16_VALUE( - 66.494),  SIMDE_FLOAT16_VALUE( 14.402),
        SIMDE_FLOAT16_VALUE( - 73.147),  SIMDE_FLOAT16_VALUE( 86.011), SIMDE_FLOAT16_VALUE( - 57.821),  SIMDE_FLOAT16_VALUE( 39.575),
        SIMDE_FLOAT16_VALUE( - 71.723), SIMDE_FLOAT16_VALUE( - 56.950), SIMDE_FLOAT16_VALUE( - 64.715),  SIMDE_FLOAT16_VALUE( 57.900),
         SIMDE_FLOAT16_VALUE( 61.685), SIMDE_FLOAT16_VALUE( - 81.983),  SIMDE_FLOAT16_VALUE( 15.196), SIMDE_FLOAT16_VALUE( - 22.643),
         SIMDE_FLOAT16_VALUE( 73.963),  SIMDE_FLOAT16_VALUE( 69.945), SIMDE_FLOAT16_VALUE( - 18.252),  SIMDE_FLOAT16_VALUE(  6.208) } },
  { { {  SIMDE_FLOAT16_VALUE( 75.124),  SIMDE_FLOAT16_VALUE( 63.765),  SIMDE_FLOAT16_VALUE( 93.445), SIMDE_FLOAT16_VALUE( -  2.808),
         SIMDE_FLOAT16_VALUE( 21.150), SIMDE_FLOAT16_VALUE( - 27.804),  SIMDE_FLOAT16_VALUE( 96.600),  SIMDE_FLOAT16_VALUE( 49.484)  },
      { SIMDE_FLOAT16_VALUE( - 21.286),  SIMDE_FLOAT16_VALUE(  6.385),  SIMDE_FLOAT16_VALUE( 58.966), SIMDE_FLOAT16_VALUE( - 25.964),
         SIMDE_FLOAT16_VALUE( 81.303),  SIMDE_FLOAT16_VALUE( 55.133),  SIMDE_FLOAT16_VALUE( 59.277),  SIMDE_FLOAT16_VALUE( 90.767)  },
      { SIMDE_FLOAT16_VALUE( -  9.851), SIMDE_FLOAT16_VALUE( - 51.010), SIMDE_FLOAT16_VALUE( - 57.457),  SIMDE_FLOAT16_VALUE( 76.293),
        SIMDE_FLOAT16_VALUE( - 36.636),  SIMDE_FLOAT16_VALUE( 71.898),  SIMDE_FLOAT16_VALUE( 98.888), SIMDE_FLOAT16_VALUE( - 38.156)  } },
      {  SIMDE_FLOAT16_VALUE( 75.124),  SIMDE_FLOAT16_VALUE( 63.765),  SIMDE_FLOAT16_VALUE( 93.445), SIMDE_FLOAT16_VALUE( -  2.808),
         SIMDE_FLOAT16_VALUE( 21.150), SIMDE_FLOAT16_VALUE( - 27.804),  SIMDE_FLOAT16_VALUE( 96.600),  SIMDE_FLOAT16_VALUE( 49.484),
        SIMDE_FLOAT16_VALUE( - 21.286),  SIMDE_FLOAT16_VALUE(  6.385),  SIMDE_FLOAT16_VALUE( 58.966), SIMDE_FLOAT16_VALUE( - 25.964),
         SIMDE_FLOAT16_VALUE( 81.303),  SIMDE_FLOAT16_VALUE( 55.133),  SIMDE_FLOAT16_VALUE( 59.277),  SIMDE_FLOAT16_VALUE( 90.767),
        SIMDE_FLOAT16_VALUE( -  9.851), SIMDE_FLOAT16_VALUE( - 51.010), SIMDE_FLOAT16_VALUE( - 57.457),  SIMDE_FLOAT16_VALUE( 76.293),
        SIMDE_FLOAT16_VALUE( - 36.636),  SIMDE_FLOAT16_VALUE( 71.898),  SIMDE_FLOAT16_VALUE( 98.888), SIMDE_FLOAT16_VALUE( - 38.156) } },
  { { {  SIMDE_FLOAT16_VALUE( 26.535), SIMDE_FLOAT16_VALUE( - 91.027), SIMDE_FLOAT16_VALUE( - 79.934), SIMDE_FLOAT16_VALUE( - 46.283),
        SIMDE_FLOAT16_VALUE( - 50.743), SIMDE_FLOAT16_VALUE( - 31.430), SIMDE_FLOAT16_VALUE( - 40.474),  SIMDE_FLOAT16_VALUE( 52.962)  },
      {  SIMDE_FLOAT16_VALUE( 54.007), SIMDE_FLOAT16_VALUE( - 51.316), SIMDE_FLOAT16_VALUE( - 70.698),  SIMDE_FLOAT16_VALUE( 59.510),
         SIMDE_FLOAT16_VALUE( 60.522), SIMDE_FLOAT16_VALUE( - 83.540),  SIMDE_FLOAT16_VALUE( 72.171), SIMDE_FLOAT16_VALUE( - 94.419)  },
      { SIMDE_FLOAT16_VALUE( - 73.925), SIMDE_FLOAT16_VALUE( - 73.200), SIMDE_FLOAT16_VALUE( - 12.444),  SIMDE_FLOAT16_VALUE( 72.493),
         SIMDE_FLOAT16_VALUE( 27.042),  SIMDE_FLOAT16_VALUE( 81.525), SIMDE_FLOAT16_VALUE( - 92.143), SIMDE_FLOAT16_VALUE( - 50.921)  } },
      {  SIMDE_FLOAT16_VALUE( 26.535), SIMDE_FLOAT16_VALUE( - 91.027), SIMDE_FLOAT16_VALUE( - 79.934), SIMDE_FLOAT16_VALUE( - 46.283),
        SIMDE_FLOAT16_VALUE( - 50.743), SIMDE_FLOAT16_VALUE( - 31.430), SIMDE_FLOAT16_VALUE( - 40.474),  SIMDE_FLOAT16_VALUE( 52.962),
         SIMDE_FLOAT16_VALUE( 54.007), SIMDE_FLOAT16_VALUE( - 51.316), SIMDE_FLOAT16_VALUE( - 70.698),  SIMDE_FLOAT16_VALUE( 59.510),
         SIMDE_FLOAT16_VALUE( 60.522), SIMDE_FLOAT16_VALUE( - 83.540),  SIMDE_FLOAT16_VALUE( 72.171), SIMDE_FLOAT16_VALUE( - 94.419),
        SIMDE_FLOAT16_VALUE( - 73.925), SIMDE_FLOAT16_VALUE( - 73.200), SIMDE_FLOAT16_VALUE( - 12.444),  SIMDE_FLOAT16_VALUE( 72.493),
         SIMDE_FLOAT16_VALUE( 27.042),  SIMDE_FLOAT16_VALUE( 81.525), SIMDE_FLOAT16_VALUE( - 92.143), SIMDE_FLOAT16_VALUE( - 50.921) } },
  { { { SIMDE_FLOAT16_VALUE( - 45.682),  SIMDE_FLOAT16_VALUE( 52.798), SIMDE_FLOAT16_VALUE( - 80.990), SIMDE_FLOAT16_VALUE( - 61.788),
         SIMDE_FLOAT16_VALUE( 54.221),  SIMDE_FLOAT16_VALUE( 99.819), SIMDE_FLOAT16_VALUE( - 53.166),  SIMDE_FLOAT16_VALUE( 62.212)  },
      { SIMDE_FLOAT16_VALUE( - 26.140), SIMDE_FLOAT16_VALUE( - 44.258), SIMDE_FLOAT16_VALUE( - 63.797),  SIMDE_FLOAT16_VALUE( 21.345),
         SIMDE_FLOAT16_VALUE( 43.284),  SIMDE_FLOAT16_VALUE( 49.659),  SIMDE_FLOAT16_VALUE( 83.024), SIMDE_FLOAT16_VALUE( - 93.541)  },
      { SIMDE_FLOAT16_VALUE( - 41.983),  SIMDE_FLOAT16_VALUE( 72.431), SIMDE_FLOAT16_VALUE( - 72.624), SIMDE_FLOAT16_VALUE( - 68.362),
        SIMDE_FLOAT16_VALUE( -  3.439),  SIMDE_FLOAT16_VALUE( 57.763),  SIMDE_FLOAT16_VALUE( 53.732),  SIMDE_FLOAT16_VALUE( 23.477)  } },
      { SIMDE_FLOAT16_VALUE( - 45.682),  SIMDE_FLOAT16_VALUE( 52.798), SIMDE_FLOAT16_VALUE( - 80.990), SIMDE_FLOAT16_VALUE( - 61.788),
         SIMDE_FLOAT16_VALUE( 54.221),  SIMDE_FLOAT16_VALUE( 99.819), SIMDE_FLOAT16_VALUE( - 53.166),  SIMDE_FLOAT16_VALUE( 62.212),
        SIMDE_FLOAT16_VALUE( - 26.140), SIMDE_FLOAT16_VALUE( - 44.258), SIMDE_FLOAT16_VALUE( - 63.797),  SIMDE_FLOAT16_VALUE( 21.345),
         SIMDE_FLOAT16_VALUE( 43.284),  SIMDE_FLOAT16_VALUE( 49.659),  SIMDE_FLOAT16_VALUE( 83.024), SIMDE_FLOAT16_VALUE( - 93.541),
        SIMDE_FLOAT16_VALUE( - 41.983),  SIMDE_FLOAT16_VALUE( 72.431), SIMDE_FLOAT16_VALUE( - 72.624), SIMDE_FLOAT16_VALUE( - 68.362),
        SIMDE_FLOAT16_VALUE( -  3.439),  SIMDE_FLOAT16_VALUE( 57.763),  SIMDE_FLOAT16_VALUE( 53.732),  SIMDE_FLOAT16_VALUE( 23.477) } },
  { { { SIMDE_FLOAT16_VALUE( - 82.965), SIMDE_FLOAT16_VALUE( - 70.111), SIMDE_FLOAT16_VALUE( - 31.957),  SIMDE_FLOAT16_VALUE( 61.018),
        SIMDE_FLOAT16_VALUE( - 27.870),  SIMDE_FLOAT16_VALUE( 71.621), SIMDE_FLOAT16_VALUE( - 77.867), SIMDE_FLOAT16_VALUE( - 30.557)  },
      {  SIMDE_FLOAT16_VALUE( 58.953), SIMDE_FLOAT16_VALUE( - 20.614), SIMDE_FLOAT16_VALUE( - 60.571),  SIMDE_FLOAT16_VALUE( 63.967),
        SIMDE_FLOAT16_VALUE( - 12.960), SIMDE_FLOAT16_VALUE( - 61.378), SIMDE_FLOAT16_VALUE( - 20.681),  SIMDE_FLOAT16_VALUE( 73.740)  },
      {  SIMDE_FLOAT16_VALUE( 77.996),  SIMDE_FLOAT16_VALUE(  4.822), SIMDE_FLOAT16_VALUE( - 39.992),  SIMDE_FLOAT16_VALUE( 50.289),
        SIMDE_FLOAT16_VALUE( - 37.043), SIMDE_FLOAT16_VALUE( - 89.635),  SIMDE_FLOAT16_VALUE( 33.091), SIMDE_FLOAT16_VALUE( - 39.668)  } },
      { SIMDE_FLOAT16_VALUE( - 82.965), SIMDE_FLOAT16_VALUE( - 70.111), SIMDE_FLOAT16_VALUE( - 31.957),  SIMDE_FLOAT16_VALUE( 61.018),
        SIMDE_FLOAT16_VALUE( - 27.870),  SIMDE_FLOAT16_VALUE( 71.621), SIMDE_FLOAT16_VALUE( - 77.867), SIMDE_FLOAT16_VALUE( - 30.557),
         SIMDE_FLOAT16_VALUE( 58.953), SIMDE_FLOAT16_VALUE( - 20.614), SIMDE_FLOAT16_VALUE( - 60.571),  SIMDE_FLOAT16_VALUE( 63.967),
        SIMDE_FLOAT16_VALUE( - 12.960), SIMDE_FLOAT16_VALUE( - 61.378), SIMDE_FLOAT16_VALUE( - 20.681),  SIMDE_FLOAT16_VALUE( 73.740),
         SIMDE_FLOAT16_VALUE( 77.996),  SIMDE_FLOAT16_VALUE(  4.822), SIMDE_FLOAT16_VALUE( - 39.992),  SIMDE_FLOAT16_VALUE( 50.289),
        SIMDE_FLOAT16_VALUE( - 37.043), SIMDE_FLOAT16_VALUE( - 89.635),  SIMDE_FLOAT16_VALUE( 33.091), SIMDE_FLOAT16_VALUE( - 39.668) } },
  { { {  SIMDE_FLOAT16_VALUE(  3.917),  SIMDE_FLOAT16_VALUE( 67.525), SIMDE_FLOAT16_VALUE( - 40.144),  SIMDE_FLOAT16_VALUE( 98.412),
        SIMDE_FLOAT16_VALUE( -  5.628), SIMDE_FLOAT16_VALUE( - 91.834),  SIMDE_FLOAT16_VALUE( 66.132), SIMDE_FLOAT16_VALUE( - 44.698)  },
      {  SIMDE_FLOAT16_VALUE(  3.461), SIMDE_FLOAT16_VALUE( -  1.903), SIMDE_FLOAT16_VALUE( -  7.486), SIMDE_FLOAT16_VALUE( -  5.095),
        SIMDE_FLOAT16_VALUE( -  4.045),  SIMDE_FLOAT16_VALUE( 76.155),  SIMDE_FLOAT16_VALUE( 45.573), SIMDE_FLOAT16_VALUE( - 17.845)  },
      { SIMDE_FLOAT16_VALUE( - 69.007), SIMDE_FLOAT16_VALUE( - 91.001),  SIMDE_FLOAT16_VALUE( 47.281), SIMDE_FLOAT16_VALUE( -  6.930),
        SIMDE_FLOAT16_VALUE( - 31.826), SIMDE_FLOAT16_VALUE( -  9.605), SIMDE_FLOAT16_VALUE( -  8.507), SIMDE_FLOAT16_VALUE( - 69.550)  } },
      {  SIMDE_FLOAT16_VALUE(  3.917),  SIMDE_FLOAT16_VALUE( 67.525), SIMDE_FLOAT16_VALUE( - 40.144),  SIMDE_FLOAT16_VALUE( 98.412),
        SIMDE_FLOAT16_VALUE( -  5.628), SIMDE_FLOAT16_VALUE( - 91.834),  SIMDE_FLOAT16_VALUE( 66.132), SIMDE_FLOAT16_VALUE( - 44.698),
         SIMDE_FLOAT16_VALUE(  3.461), SIMDE_FLOAT16_VALUE( -  1.903), SIMDE_FLOAT16_VALUE( -  7.486), SIMDE_FLOAT16_VALUE( -  5.095),
        SIMDE_FLOAT16_VALUE( -  4.045),  SIMDE_FLOAT16_VALUE( 76.155),  SIMDE_FLOAT16_VALUE( 45.573), SIMDE_FLOAT16_VALUE( - 17.845),
        SIMDE_FLOAT16_VALUE( - 69.007), SIMDE_FLOAT16_VALUE( - 91.001),  SIMDE_FLOAT16_VALUE( 47.281), SIMDE_FLOAT16_VALUE( -  6.930),
        SIMDE_FLOAT16_VALUE( - 31.826), SIMDE_FLOAT16_VALUE( -  9.605), SIMDE_FLOAT16_VALUE( -  8.507), SIMDE_FLOAT16_VALUE( - 69.550) } },
  { { { SIMDE_FLOAT16_VALUE( - 83.740), SIMDE_FLOAT16_VALUE( -  6.331), SIMDE_FLOAT16_VALUE( - 89.045), SIMDE_FLOAT16_VALUE( - 94.435),
        SIMDE_FLOAT16_VALUE( - 65.111), SIMDE_FLOAT16_VALUE( - 70.456),  SIMDE_FLOAT16_VALUE( 11.289),  SIMDE_FLOAT16_VALUE(  7.177)  },
      { SIMDE_FLOAT16_VALUE( - 90.849), SIMDE_FLOAT16_VALUE( - 95.953), SIMDE_FLOAT16_VALUE( - 42.247),  SIMDE_FLOAT16_VALUE( 14.309),
        SIMDE_FLOAT16_VALUE( - 95.825), SIMDE_FLOAT16_VALUE( - 22.270),  SIMDE_FLOAT16_VALUE( 83.373), SIMDE_FLOAT16_VALUE( - 79.802)  },
      { SIMDE_FLOAT16_VALUE( - 22.035), SIMDE_FLOAT16_VALUE( - 92.921),  SIMDE_FLOAT16_VALUE( 43.906),  SIMDE_FLOAT16_VALUE( 26.805),
         SIMDE_FLOAT16_VALUE( 51.738), SIMDE_FLOAT16_VALUE( - 42.852),  SIMDE_FLOAT16_VALUE(  5.828),  SIMDE_FLOAT16_VALUE( 44.079)  } },
      { SIMDE_FLOAT16_VALUE( - 83.740), SIMDE_FLOAT16_VALUE( -  6.331), SIMDE_FLOAT16_VALUE( - 89.045), SIMDE_FLOAT16_VALUE( - 94.435),
        SIMDE_FLOAT16_VALUE( - 65.111), SIMDE_FLOAT16_VALUE( - 70.456),  SIMDE_FLOAT16_VALUE( 11.289),  SIMDE_FLOAT16_VALUE(  7.177),
        SIMDE_FLOAT16_VALUE( - 90.849), SIMDE_FLOAT16_VALUE( - 95.953), SIMDE_FLOAT16_VALUE( - 42.247),  SIMDE_FLOAT16_VALUE( 14.309),
        SIMDE_FLOAT16_VALUE( - 95.825), SIMDE_FLOAT16_VALUE( - 22.270),  SIMDE_FLOAT16_VALUE( 83.373), SIMDE_FLOAT16_VALUE( - 79.802),
        SIMDE_FLOAT16_VALUE( - 22.035), SIMDE_FLOAT16_VALUE( - 92.921),  SIMDE_FLOAT16_VALUE( 43.906),  SIMDE_FLOAT16_VALUE( 26.805),
         SIMDE_FLOAT16_VALUE( 51.738), SIMDE_FLOAT16_VALUE( - 42.852),  SIMDE_FLOAT16_VALUE(  5.828),  SIMDE_FLOAT16_VALUE( 44.079) } },
  { { { SIMDE_FLOAT16_VALUE( - 16.629),  SIMDE_FLOAT16_VALUE( 51.044),  SIMDE_FLOAT16_VALUE( 19.393),  SIMDE_FLOAT16_VALUE( 55.131),
        SIMDE_FLOAT16_VALUE( - 43.901),  SIMDE_FLOAT16_VALUE( 70.204),  SIMDE_FLOAT16_VALUE( 97.396),  SIMDE_FLOAT16_VALUE( 81.774)  },
      { SIMDE_FLOAT16_VALUE( - 65.652),  SIMDE_FLOAT16_VALUE( 84.250), SIMDE_FLOAT16_VALUE( - 73.434),  SIMDE_FLOAT16_VALUE( 83.066),
         SIMDE_FLOAT16_VALUE( 98.140),  SIMDE_FLOAT16_VALUE( 10.456), SIMDE_FLOAT16_VALUE( - 74.473),  SIMDE_FLOAT16_VALUE( 36.574)  },
      { SIMDE_FLOAT16_VALUE( - 30.153),  SIMDE_FLOAT16_VALUE( 52.521), SIMDE_FLOAT16_VALUE( - 21.877),  SIMDE_FLOAT16_VALUE( 99.308),
        SIMDE_FLOAT16_VALUE( - 78.712), SIMDE_FLOAT16_VALUE( - 45.652), SIMDE_FLOAT16_VALUE( - 23.870),  SIMDE_FLOAT16_VALUE( 33.651)  } },
      { SIMDE_FLOAT16_VALUE( - 16.629),  SIMDE_FLOAT16_VALUE( 51.044),  SIMDE_FLOAT16_VALUE( 19.393),  SIMDE_FLOAT16_VALUE( 55.131),
        SIMDE_FLOAT16_VALUE( - 43.901),  SIMDE_FLOAT16_VALUE( 70.204),  SIMDE_FLOAT16_VALUE( 97.396),  SIMDE_FLOAT16_VALUE( 81.774),
        SIMDE_FLOAT16_VALUE( - 65.652),  SIMDE_FLOAT16_VALUE( 84.250), SIMDE_FLOAT16_VALUE( - 73.434),  SIMDE_FLOAT16_VALUE( 83.066),
         SIMDE_FLOAT16_VALUE( 98.140),  SIMDE_FLOAT16_VALUE( 10.456), SIMDE_FLOAT16_VALUE( - 74.473),  SIMDE_FLOAT16_VALUE( 36.574),
        SIMDE_FLOAT16_VALUE( - 30.153),  SIMDE_FLOAT16_VALUE( 52.521), SIMDE_FLOAT16_VALUE( - 21.877),  SIMDE_FLOAT16_VALUE( 99.308),
        SIMDE_FLOAT16_VALUE( - 78.712), SIMDE_FLOAT16_VALUE( - 45.652), SIMDE_FLOAT16_VALUE( - 23.870),  SIMDE_FLOAT16_VALUE( 33.651) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float16x8x3_t val = {{
        simde_vld1q_f16(test_vec[i].val[0]),
        simde_vld1q_f16(test_vec[i].val[1]),
        simde_vld1q_f16(test_vec[i].val[2]),
    }};
    simde_float16_t r_[24];
    simde_vst1q_f16_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x3_t val[3] = simde_test_arm_neon_random_f16x3(-100.0f, 100.0f);
    simde_float16x24_t r = simde_vst1q_f16_x3(val[3]);

    simde_test_arm_neon_write_f16x3(2, val[3], SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x24(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_f32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r[3][4];
    simde_float32 a[12];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(   301.75), SIMDE_FLOAT32_C(   948.57), SIMDE_FLOAT32_C(  -641.77), SIMDE_FLOAT32_C(   911.15) },
          { SIMDE_FLOAT32_C(   292.66), SIMDE_FLOAT32_C(   217.08), SIMDE_FLOAT32_C(  -302.00), SIMDE_FLOAT32_C(   632.24) },
          { SIMDE_FLOAT32_C(   542.22), SIMDE_FLOAT32_C(   -23.30), SIMDE_FLOAT32_C(   887.34), SIMDE_FLOAT32_C(  -873.31) } },
      { SIMDE_FLOAT32_C(   301.75), SIMDE_FLOAT32_C(   948.57), SIMDE_FLOAT32_C(  -641.77), SIMDE_FLOAT32_C(   911.15),
        SIMDE_FLOAT32_C(   292.66), SIMDE_FLOAT32_C(   217.08), SIMDE_FLOAT32_C(  -302.00), SIMDE_FLOAT32_C(   632.24),
        SIMDE_FLOAT32_C(   542.22), SIMDE_FLOAT32_C(   -23.30), SIMDE_FLOAT32_C(   887.34), SIMDE_FLOAT32_C(  -873.31) } },
    {
        { { SIMDE_FLOAT32_C(   654.53), SIMDE_FLOAT32_C(   351.69), SIMDE_FLOAT32_C(   -76.10), SIMDE_FLOAT32_C(  -702.90) },
          { SIMDE_FLOAT32_C(  -365.99), SIMDE_FLOAT32_C(    70.51), SIMDE_FLOAT32_C(  -342.83), SIMDE_FLOAT32_C(  -252.59) },
          { SIMDE_FLOAT32_C(   408.41), SIMDE_FLOAT32_C(   -48.80), SIMDE_FLOAT32_C(  -256.81), SIMDE_FLOAT32_C(  -769.94) } },
      { SIMDE_FLOAT32_C(   654.53), SIMDE_FLOAT32_C(   351.69), SIMDE_FLOAT32_C(   -76.10), SIMDE_FLOAT32_C(  -702.90),
        SIMDE_FLOAT32_C(  -365.99), SIMDE_FLOAT32_C(    70.51), SIMDE_FLOAT32_C(  -342.83), SIMDE_FLOAT32_C(  -252.59),
        SIMDE_FLOAT32_C(   408.41), SIMDE_FLOAT32_C(   -48.80), SIMDE_FLOAT32_C(  -256.81), SIMDE_FLOAT32_C(  -769.94) } },
    {
        { { SIMDE_FLOAT32_C(   179.53), SIMDE_FLOAT32_C(   588.47), SIMDE_FLOAT32_C(   697.20), SIMDE_FLOAT32_C(  -852.44) },
          { SIMDE_FLOAT32_C(  -681.19), SIMDE_FLOAT32_C(  -606.32), SIMDE_FLOAT32_C(   247.13), SIMDE_FLOAT32_C(   620.56) },
          { SIMDE_FLOAT32_C(  -657.75), SIMDE_FLOAT32_C(   605.36), SIMDE_FLOAT32_C(   531.71), SIMDE_FLOAT32_C(   634.91) } },
      { SIMDE_FLOAT32_C(   179.53), SIMDE_FLOAT32_C(   588.47), SIMDE_FLOAT32_C(   697.20), SIMDE_FLOAT32_C(  -852.44),
        SIMDE_FLOAT32_C(  -681.19), SIMDE_FLOAT32_C(  -606.32), SIMDE_FLOAT32_C(   247.13), SIMDE_FLOAT32_C(   620.56),
        SIMDE_FLOAT32_C(  -657.75), SIMDE_FLOAT32_C(   605.36), SIMDE_FLOAT32_C(   531.71), SIMDE_FLOAT32_C(   634.91) } },
    {
        { { SIMDE_FLOAT32_C(  -177.57), SIMDE_FLOAT32_C(  -770.29), SIMDE_FLOAT32_C(   267.15), SIMDE_FLOAT32_C(  -635.35) },
          { SIMDE_FLOAT32_C(   206.41), SIMDE_FLOAT32_C(   154.49), SIMDE_FLOAT32_C(  -508.65), SIMDE_FLOAT32_C(  -139.06) },
          { SIMDE_FLOAT32_C(  -493.82), SIMDE_FLOAT32_C(   415.25), SIMDE_FLOAT32_C(   158.04), SIMDE_FLOAT32_C(   140.20) } },
      { SIMDE_FLOAT32_C(  -177.57), SIMDE_FLOAT32_C(  -770.29), SIMDE_FLOAT32_C(   267.15), SIMDE_FLOAT32_C(  -635.35),
        SIMDE_FLOAT32_C(   206.41), SIMDE_FLOAT32_C(   154.49), SIMDE_FLOAT32_C(  -508.65), SIMDE_FLOAT32_C(  -139.06),
        SIMDE_FLOAT32_C(  -493.82), SIMDE_FLOAT32_C(   415.25), SIMDE_FLOAT32_C(   158.04), SIMDE_FLOAT32_C(   140.20) } },
    {
        { { SIMDE_FLOAT32_C(  -514.24), SIMDE_FLOAT32_C(   815.21), SIMDE_FLOAT32_C(   887.61), SIMDE_FLOAT32_C(   894.16) },
          { SIMDE_FLOAT32_C(  -233.59), SIMDE_FLOAT32_C(  -369.20), SIMDE_FLOAT32_C(  -875.77), SIMDE_FLOAT32_C(   945.95) },
          { SIMDE_FLOAT32_C(  -780.73), SIMDE_FLOAT32_C(   821.42), SIMDE_FLOAT32_C(  -906.49), SIMDE_FLOAT32_C(  -461.92) } },
      { SIMDE_FLOAT32_C(  -514.24), SIMDE_FLOAT32_C(   815.21), SIMDE_FLOAT32_C(   887.61), SIMDE_FLOAT32_C(   894.16),
        SIMDE_FLOAT32_C(  -233.59), SIMDE_FLOAT32_C(  -369.20), SIMDE_FLOAT32_C(  -875.77), SIMDE_FLOAT32_C(   945.95),
        SIMDE_FLOAT32_C(  -780.73), SIMDE_FLOAT32_C(   821.42), SIMDE_FLOAT32_C(  -906.49), SIMDE_FLOAT32_C(  -461.92) } },
    {
        { { SIMDE_FLOAT32_C(  -784.89), SIMDE_FLOAT32_C(   340.64), SIMDE_FLOAT32_C(  -841.36), SIMDE_FLOAT32_C(  -442.64) },
          { SIMDE_FLOAT32_C(   -54.01), SIMDE_FLOAT32_C(   690.35), SIMDE_FLOAT32_C(  -807.73), SIMDE_FLOAT32_C(   768.43) },
          { SIMDE_FLOAT32_C(   920.06), SIMDE_FLOAT32_C(   459.43), SIMDE_FLOAT32_C(  -866.92), SIMDE_FLOAT32_C(   126.47) } },
      { SIMDE_FLOAT32_C(  -784.89), SIMDE_FLOAT32_C(   340.64), SIMDE_FLOAT32_C(  -841.36), SIMDE_FLOAT32_C(  -442.64),
        SIMDE_FLOAT32_C(   -54.01), SIMDE_FLOAT32_C(   690.35), SIMDE_FLOAT32_C(  -807.73), SIMDE_FLOAT32_C(   768.43),
        SIMDE_FLOAT32_C(   920.06), SIMDE_FLOAT32_C(   459.43), SIMDE_FLOAT32_C(  -866.92), SIMDE_FLOAT32_C(   126.47) } },
    {
        { { SIMDE_FLOAT32_C(  -386.08), SIMDE_FLOAT32_C(  -375.57), SIMDE_FLOAT32_C(   987.41), SIMDE_FLOAT32_C(   120.10) },
          { SIMDE_FLOAT32_C(  -960.32), SIMDE_FLOAT32_C(   145.45), SIMDE_FLOAT32_C(  -739.70), SIMDE_FLOAT32_C(  -474.57) },
          { SIMDE_FLOAT32_C(   -39.34), SIMDE_FLOAT32_C(  -852.09), SIMDE_FLOAT32_C(  -580.40), SIMDE_FLOAT32_C(   727.07) } },
      { SIMDE_FLOAT32_C(  -386.08), SIMDE_FLOAT32_C(  -375.57), SIMDE_FLOAT32_C(   987.41), SIMDE_FLOAT32_C(   120.10),
        SIMDE_FLOAT32_C(  -960.32), SIMDE_FLOAT32_C(   145.45), SIMDE_FLOAT32_C(  -739.70), SIMDE_FLOAT32_C(  -474.57),
        SIMDE_FLOAT32_C(   -39.34), SIMDE_FLOAT32_C(  -852.09), SIMDE_FLOAT32_C(  -580.40), SIMDE_FLOAT32_C(   727.07) } },
    {
        { { SIMDE_FLOAT32_C(  -221.29), SIMDE_FLOAT32_C(  -456.17), SIMDE_FLOAT32_C(   673.02), SIMDE_FLOAT32_C(    -2.02) },
          { SIMDE_FLOAT32_C(  -634.75), SIMDE_FLOAT32_C(   766.53), SIMDE_FLOAT32_C(   536.06), SIMDE_FLOAT32_C(  -419.64) },
          { SIMDE_FLOAT32_C(   107.17), SIMDE_FLOAT32_C(   694.69), SIMDE_FLOAT32_C(   137.72), SIMDE_FLOAT32_C(  -946.84) } },
      { SIMDE_FLOAT32_C(  -221.29), SIMDE_FLOAT32_C(  -456.17), SIMDE_FLOAT32_C(   673.02), SIMDE_FLOAT32_C(    -2.02),
        SIMDE_FLOAT32_C(  -634.75), SIMDE_FLOAT32_C(   766.53), SIMDE_FLOAT32_C(   536.06), SIMDE_FLOAT32_C(  -419.64),
        SIMDE_FLOAT32_C(   107.17), SIMDE_FLOAT32_C(   694.69), SIMDE_FLOAT32_C(   137.72), SIMDE_FLOAT32_C(  -946.84) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x3_t r_ = { { simde_vld1q_f32(test_vec[i].r[0]),
                                 simde_vld1q_f32(test_vec[i].r[1]),
                                 simde_vld1q_f32(test_vec[i].r[2]) } };

    SIMDE_ALIGN_TO_16 simde_float32 a_[12];
    simde_vst1q_f32_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t c = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_f32x4x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32 buf[12];
    simde_vst1q_f32_x3(buf, d);

    simde_test_codegen_write_vf32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_f64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r[3][2];
    simde_float64 a[6];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(   385.04), SIMDE_FLOAT64_C(   329.99) },
          { SIMDE_FLOAT64_C(   821.59), SIMDE_FLOAT64_C(   305.10) },
          { SIMDE_FLOAT64_C(  -210.58), SIMDE_FLOAT64_C(   954.67) } },
      { SIMDE_FLOAT64_C(   385.04), SIMDE_FLOAT64_C(   329.99), SIMDE_FLOAT64_C(   821.59), SIMDE_FLOAT64_C(   305.10),
        SIMDE_FLOAT64_C(  -210.58), SIMDE_FLOAT64_C(   954.67) } },
    {
        { { SIMDE_FLOAT64_C(  -568.43), SIMDE_FLOAT64_C(   403.34) },
          { SIMDE_FLOAT64_C(  -420.90), SIMDE_FLOAT64_C(  -581.02) },
          { SIMDE_FLOAT64_C(  -476.56), SIMDE_FLOAT64_C(  -381.22) } },
      { SIMDE_FLOAT64_C(  -568.43), SIMDE_FLOAT64_C(   403.34), SIMDE_FLOAT64_C(  -420.90), SIMDE_FLOAT64_C(  -581.02),
        SIMDE_FLOAT64_C(  -476.56), SIMDE_FLOAT64_C(  -381.22) } },
    {
        { { SIMDE_FLOAT64_C(   564.42), SIMDE_FLOAT64_C(  -216.26) },
          { SIMDE_FLOAT64_C(   144.21), SIMDE_FLOAT64_C(  -474.92) },
          { SIMDE_FLOAT64_C(   -68.35), SIMDE_FLOAT64_C(   563.81) } },
      { SIMDE_FLOAT64_C(   564.42), SIMDE_FLOAT64_C(  -216.26), SIMDE_FLOAT64_C(   144.21), SIMDE_FLOAT64_C(  -474.92),
        SIMDE_FLOAT64_C(   -68.35), SIMDE_FLOAT64_C(   563.81) } },
    {
        { { SIMDE_FLOAT64_C(  -747.84), SIMDE_FLOAT64_C(   710.36) },
          { SIMDE_FLOAT64_C(  -892.36), SIMDE_FLOAT64_C(   925.18) },
          { SIMDE_FLOAT64_C(  -291.66), SIMDE_FLOAT64_C(  -527.11) } },
      { SIMDE_FLOAT64_C(  -747.84), SIMDE_FLOAT64_C(   710.36), SIMDE_FLOAT64_C(  -892.36), SIMDE_FLOAT64_C(   925.18),
        SIMDE_FLOAT64_C(  -291.66), SIMDE_FLOAT64_C(  -527.11) } },
    {
        { { SIMDE_FLOAT64_C(   691.70), SIMDE_FLOAT64_C(  -755.60) },
          { SIMDE_FLOAT64_C(    53.25), SIMDE_FLOAT64_C(  -201.13) },
          { SIMDE_FLOAT64_C(   939.10), SIMDE_FLOAT64_C(  -809.03) } },
      { SIMDE_FLOAT64_C(   691.70), SIMDE_FLOAT64_C(  -755.60), SIMDE_FLOAT64_C(    53.25), SIMDE_FLOAT64_C(  -201.13),
        SIMDE_FLOAT64_C(   939.10), SIMDE_FLOAT64_C(  -809.03) } },
    {
        { { SIMDE_FLOAT64_C(  -147.97), SIMDE_FLOAT64_C(   324.14) },
          { SIMDE_FLOAT64_C(   520.96), SIMDE_FLOAT64_C(  -326.38) },
          { SIMDE_FLOAT64_C(  -370.77), SIMDE_FLOAT64_C(  -689.62) } },
      { SIMDE_FLOAT64_C(  -147.97), SIMDE_FLOAT64_C(   324.14), SIMDE_FLOAT64_C(   520.96), SIMDE_FLOAT64_C(  -326.38),
        SIMDE_FLOAT64_C(  -370.77), SIMDE_FLOAT64_C(  -689.62) } },
    {
        { { SIMDE_FLOAT64_C(  -371.71), SIMDE_FLOAT64_C(    60.80) },
          { SIMDE_FLOAT64_C(   713.72), SIMDE_FLOAT64_C(   207.39) },
          { SIMDE_FLOAT64_C(   479.77), SIMDE_FLOAT64_C(  -762.84) } },
      { SIMDE_FLOAT64_C(  -371.71), SIMDE_FLOAT64_C(    60.80), SIMDE_FLOAT64_C(   713.72), SIMDE_FLOAT64_C(   207.39),
        SIMDE_FLOAT64_C(   479.77), SIMDE_FLOAT64_C(  -762.84) } },
    {
        { { SIMDE_FLOAT64_C(   826.17), SIMDE_FLOAT64_C(    44.20) },
          { SIMDE_FLOAT64_C(    20.90), SIMDE_FLOAT64_C(   -29.62) },
          { SIMDE_FLOAT64_C(   569.28), SIMDE_FLOAT64_C(   952.55) } },
      { SIMDE_FLOAT64_C(   826.17), SIMDE_FLOAT64_C(    44.20), SIMDE_FLOAT64_C(    20.90), SIMDE_FLOAT64_C(   -29.62),
        SIMDE_FLOAT64_C(   569.28), SIMDE_FLOAT64_C(   952.55) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x3_t r_ = { { simde_vld1q_f64(test_vec[i].r[0]),
                                 simde_vld1q_f64(test_vec[i].r[1]),
                                 simde_vld1q_f64(test_vec[i].r[2]) } };

    SIMDE_ALIGN_TO_16 simde_float64 a_[6];
    simde_vst1q_f64_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t c = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_f64x2x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64 buf[6];
    simde_vst1q_f64_x3(buf, d);

    simde_test_codegen_write_vf64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s8_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[3][16];
    int8_t a[48];
  } test_vec[] = {
    {
        { {  INT8_C(  86),  INT8_C(  69), -INT8_C( 105),  INT8_C( 122), -INT8_C( 113),  INT8_C(   2),  INT8_C( 118),  INT8_C(  42),
            -INT8_C(  15),  INT8_C(  99), -INT8_C(  22),  INT8_C(  14), -INT8_C(  58),  INT8_C(  93), -INT8_C(  10), -INT8_C(  84) },
          { -INT8_C(  85), -INT8_C(  57),  INT8_C(   6),  INT8_C(   0),  INT8_C(  52), -INT8_C(  72),  INT8_C( 107), -INT8_C(  71),
            -INT8_C(  92), -INT8_C(   6), -INT8_C(  18), -INT8_C(  72), -INT8_C( 106),  INT8_C(  27),  INT8_C(  57), -INT8_C(  19) },
          {  INT8_C(  96), -INT8_C(  48),  INT8_C( 103), -INT8_C(  16), -INT8_C(  46), -INT8_C(  35),  INT8_C(  26), -INT8_C(  61),
             INT8_C(  65),  INT8_C(   4), -INT8_C(  47),  INT8_C(   7),  INT8_C(  97), -INT8_C(  56), -INT8_C(  76),  INT8_C(  12) } },
      {  INT8_C(  86),  INT8_C(  69), -INT8_C( 105),  INT8_C( 122), -INT8_C( 113),  INT8_C(   2),  INT8_C( 118),  INT8_C(  42),
        -INT8_C(  15),  INT8_C(  99), -INT8_C(  22),  INT8_C(  14), -INT8_C(  58),  INT8_C(  93), -INT8_C(  10), -INT8_C(  84),
        -INT8_C(  85), -INT8_C(  57),  INT8_C(   6),  INT8_C(   0),  INT8_C(  52), -INT8_C(  72),  INT8_C( 107), -INT8_C(  71),
        -INT8_C(  92), -INT8_C(   6), -INT8_C(  18), -INT8_C(  72), -INT8_C( 106),  INT8_C(  27),  INT8_C(  57), -INT8_C(  19),
         INT8_C(  96), -INT8_C(  48),  INT8_C( 103), -INT8_C(  16), -INT8_C(  46), -INT8_C(  35),  INT8_C(  26), -INT8_C(  61),
         INT8_C(  65),  INT8_C(   4), -INT8_C(  47),  INT8_C(   7),  INT8_C(  97), -INT8_C(  56), -INT8_C(  76),  INT8_C(  12) } },
    {
        { { -INT8_C( 113), -INT8_C(  70),  INT8_C(  13), -INT8_C(  61),  INT8_C( 115),  INT8_C( 120),  INT8_C( 124),  INT8_C(  23),
             INT8_C( 115),  INT8_C( 106), -INT8_C(  49),  INT8_C(   9), -INT8_C( 123),  INT8_C(   8), -INT8_C(  10), -INT8_C(  27) },
          { -INT8_C(  40),  INT8_C(  94), -INT8_C(  43), -INT8_C(  86),  INT8_C(  59), -INT8_C(  17),  INT8_C( 109),  INT8_C( 124),
            -INT8_C(  13),  INT8_C(  63), -INT8_C( 124),  INT8_C(  84),  INT8_C(   7),  INT8_C(  56),  INT8_C(  97), -INT8_C( 106) },
          { -INT8_C(  14),  INT8_C( 110),  INT8_C(  89),  INT8_C( 101), -INT8_C(  26), -INT8_C(  43),  INT8_C( 124),  INT8_C(  89),
             INT8_C(  63),  INT8_C(  76),  INT8_C(  99), -INT8_C(  60),  INT8_C(  84),  INT8_C(  89), -INT8_C(  87),  INT8_C(  45) } },
      { -INT8_C( 113), -INT8_C(  70),  INT8_C(  13), -INT8_C(  61),  INT8_C( 115),  INT8_C( 120),  INT8_C( 124),  INT8_C(  23),
         INT8_C( 115),  INT8_C( 106), -INT8_C(  49),  INT8_C(   9), -INT8_C( 123),  INT8_C(   8), -INT8_C(  10), -INT8_C(  27),
        -INT8_C(  40),  INT8_C(  94), -INT8_C(  43), -INT8_C(  86),  INT8_C(  59), -INT8_C(  17),  INT8_C( 109),  INT8_C( 124),
        -INT8_C(  13),  INT8_C(  63), -INT8_C( 124),  INT8_C(  84),  INT8_C(   7),  INT8_C(  56),  INT8_C(  97), -INT8_C( 106),
        -INT8_C(  14),  INT8_C( 110),  INT8_C(  89),  INT8_C( 101), -INT8_C(  26), -INT8_C(  43),  INT8_C( 124),  INT8_C(  89),
         INT8_C(  63),  INT8_C(  76),  INT8_C(  99), -INT8_C(  60),  INT8_C(  84),  INT8_C(  89), -INT8_C(  87),  INT8_C(  45) } },
    {
        { { -INT8_C(  73),      INT8_MAX, -INT8_C(  41), -INT8_C(  13),  INT8_C( 110),  INT8_C(  69),  INT8_C( 111),  INT8_C(  98),
            -INT8_C( 124), -INT8_C(  13), -INT8_C(  74), -INT8_C( 117),  INT8_C(  43),  INT8_C(  23),  INT8_C(  33),  INT8_C(  30) },
          { -INT8_C( 123),  INT8_C( 122), -INT8_C( 125),  INT8_C( 108),  INT8_C(  79),  INT8_C(   0), -INT8_C(  59), -INT8_C( 114),
             INT8_C(  76),  INT8_C(  40),  INT8_C(  82), -INT8_C(  96), -INT8_C( 126), -INT8_C(   5), -INT8_C(  51),  INT8_C(  57) },
          {  INT8_C( 122), -INT8_C(  91),  INT8_C(  44), -INT8_C(  23), -INT8_C(  22), -INT8_C( 100),  INT8_C(  75),  INT8_C( 110),
            -INT8_C( 113),  INT8_C(   1), -INT8_C(   7), -INT8_C(  69),  INT8_C(  25),  INT8_C(  26), -INT8_C(  39), -INT8_C(  98) } },
      { -INT8_C(  73),      INT8_MAX, -INT8_C(  41), -INT8_C(  13),  INT8_C( 110),  INT8_C(  69),  INT8_C( 111),  INT8_C(  98),
        -INT8_C( 124), -INT8_C(  13), -INT8_C(  74), -INT8_C( 117),  INT8_C(  43),  INT8_C(  23),  INT8_C(  33),  INT8_C(  30),
        -INT8_C( 123),  INT8_C( 122), -INT8_C( 125),  INT8_C( 108),  INT8_C(  79),  INT8_C(   0), -INT8_C(  59), -INT8_C( 114),
         INT8_C(  76),  INT8_C(  40),  INT8_C(  82), -INT8_C(  96), -INT8_C( 126), -INT8_C(   5), -INT8_C(  51),  INT8_C(  57),
         INT8_C( 122), -INT8_C(  91),  INT8_C(  44), -INT8_C(  23), -INT8_C(  22), -INT8_C( 100),  INT8_C(  75),  INT8_C( 110),
        -INT8_C( 113),  INT8_C(   1), -INT8_C(   7), -INT8_C(  69),  INT8_C(  25),  INT8_C(  26), -INT8_C(  39), -INT8_C(  98) } },
    {
        { { -INT8_C( 108),  INT8_C(  92),  INT8_C(  10), -INT8_C(  29),  INT8_C(  92), -INT8_C(  48),  INT8_C( 113), -INT8_C(  88),
            -INT8_C(   8), -INT8_C(  61),  INT8_C(  73),  INT8_C( 122), -INT8_C(  66),  INT8_C(  22), -INT8_C(  76),  INT8_C(  57) },
          { -INT8_C(  69), -INT8_C(  32),  INT8_C(  34), -INT8_C(  91),  INT8_C( 124),  INT8_C( 109),  INT8_C(  19),  INT8_C(  12),
             INT8_C( 110),  INT8_C(  12), -INT8_C(  57), -INT8_C( 121),  INT8_C(  38), -INT8_C(  96),  INT8_C(  38), -INT8_C(  70) },
          { -INT8_C(   4),  INT8_C(  48), -INT8_C(  99),  INT8_C(  89),  INT8_C(   0),  INT8_C(  14),  INT8_C(   1), -INT8_C(   7),
            -INT8_C(  47),  INT8_C(  74),  INT8_C( 115), -INT8_C( 112),  INT8_C(  97),  INT8_C(  39), -INT8_C(  55),  INT8_C(  28) } },
      { -INT8_C( 108),  INT8_C(  92),  INT8_C(  10), -INT8_C(  29),  INT8_C(  92), -INT8_C(  48),  INT8_C( 113), -INT8_C(  88),
        -INT8_C(   8), -INT8_C(  61),  INT8_C(  73),  INT8_C( 122), -INT8_C(  66),  INT8_C(  22), -INT8_C(  76),  INT8_C(  57),
        -INT8_C(  69), -INT8_C(  32),  INT8_C(  34), -INT8_C(  91),  INT8_C( 124),  INT8_C( 109),  INT8_C(  19),  INT8_C(  12),
         INT8_C( 110),  INT8_C(  12), -INT8_C(  57), -INT8_C( 121),  INT8_C(  38), -INT8_C(  96),  INT8_C(  38), -INT8_C(  70),
        -INT8_C(   4),  INT8_C(  48), -INT8_C(  99),  INT8_C(  89),  INT8_C(   0),  INT8_C(  14),  INT8_C(   1), -INT8_C(   7),
        -INT8_C(  47),  INT8_C(  74),  INT8_C( 115), -INT8_C( 112),  INT8_C(  97),  INT8_C(  39), -INT8_C(  55),  INT8_C(  28) } },
    {
        { {  INT8_C(   8), -INT8_C(  21), -INT8_C(  62), -INT8_C( 124),  INT8_C(  88), -INT8_C(  43), -INT8_C( 112), -INT8_C(  58),
            -INT8_C(  30),  INT8_C(  87),  INT8_C(  78),  INT8_C(   8), -INT8_C(   9),  INT8_C( 116), -INT8_C(  61), -INT8_C(  12) },
          { -INT8_C(  92),  INT8_C(  96),  INT8_C(  77), -INT8_C(  91),  INT8_C( 111),  INT8_C(  78), -INT8_C(  98),  INT8_C(  64),
            -INT8_C( 103),  INT8_C(  17), -INT8_C(  48), -INT8_C(   6),  INT8_C(  57), -INT8_C( 103),  INT8_C(  22),  INT8_C(  65) },
          { -INT8_C( 124), -INT8_C(  40), -INT8_C(  59), -INT8_C(  36), -INT8_C(  82),  INT8_C(  86), -INT8_C(  93), -INT8_C( 112),
            -INT8_C(  83), -INT8_C(  15), -INT8_C( 104), -INT8_C(  91),  INT8_C( 101),  INT8_C(  91), -INT8_C( 103),  INT8_C(   9) } },
      {  INT8_C(   8), -INT8_C(  21), -INT8_C(  62), -INT8_C( 124),  INT8_C(  88), -INT8_C(  43), -INT8_C( 112), -INT8_C(  58),
        -INT8_C(  30),  INT8_C(  87),  INT8_C(  78),  INT8_C(   8), -INT8_C(   9),  INT8_C( 116), -INT8_C(  61), -INT8_C(  12),
        -INT8_C(  92),  INT8_C(  96),  INT8_C(  77), -INT8_C(  91),  INT8_C( 111),  INT8_C(  78), -INT8_C(  98),  INT8_C(  64),
        -INT8_C( 103),  INT8_C(  17), -INT8_C(  48), -INT8_C(   6),  INT8_C(  57), -INT8_C( 103),  INT8_C(  22),  INT8_C(  65),
        -INT8_C( 124), -INT8_C(  40), -INT8_C(  59), -INT8_C(  36), -INT8_C(  82),  INT8_C(  86), -INT8_C(  93), -INT8_C( 112),
        -INT8_C(  83), -INT8_C(  15), -INT8_C( 104), -INT8_C(  91),  INT8_C( 101),  INT8_C(  91), -INT8_C( 103),  INT8_C(   9) } },
    {
        { { -INT8_C(  68), -INT8_C(  26), -INT8_C(  82),  INT8_C(  43),  INT8_C(  52),  INT8_C(  76),  INT8_C( 107), -INT8_C(  51),
             INT8_C(  94),  INT8_C(  60), -INT8_C(  57), -INT8_C( 105), -INT8_C(  43), -INT8_C(  34), -INT8_C(  40),  INT8_C(  90) },
          { -INT8_C(  74), -INT8_C(  99),  INT8_C(  54),  INT8_C( 100), -INT8_C(  13), -INT8_C(  39), -INT8_C(  12), -INT8_C(  95),
            -INT8_C(  54), -INT8_C( 115),  INT8_C(  70),  INT8_C(  47), -INT8_C(  24), -INT8_C(  33),  INT8_C(  57), -INT8_C(  92) },
          { -INT8_C(  59), -INT8_C(  25), -INT8_C(  49), -INT8_C(   7),  INT8_C(  52),  INT8_C(  59), -INT8_C(  57), -INT8_C( 110),
             INT8_C( 119), -INT8_C( 114),  INT8_C(  41),  INT8_C(  76),  INT8_C( 108),  INT8_C(   1), -INT8_C(  90),  INT8_C(  35) } },
      { -INT8_C(  68), -INT8_C(  26), -INT8_C(  82),  INT8_C(  43),  INT8_C(  52),  INT8_C(  76),  INT8_C( 107), -INT8_C(  51),
         INT8_C(  94),  INT8_C(  60), -INT8_C(  57), -INT8_C( 105), -INT8_C(  43), -INT8_C(  34), -INT8_C(  40),  INT8_C(  90),
        -INT8_C(  74), -INT8_C(  99),  INT8_C(  54),  INT8_C( 100), -INT8_C(  13), -INT8_C(  39), -INT8_C(  12), -INT8_C(  95),
        -INT8_C(  54), -INT8_C( 115),  INT8_C(  70),  INT8_C(  47), -INT8_C(  24), -INT8_C(  33),  INT8_C(  57), -INT8_C(  92),
        -INT8_C(  59), -INT8_C(  25), -INT8_C(  49), -INT8_C(   7),  INT8_C(  52),  INT8_C(  59), -INT8_C(  57), -INT8_C( 110),
         INT8_C( 119), -INT8_C( 114),  INT8_C(  41),  INT8_C(  76),  INT8_C( 108),  INT8_C(   1), -INT8_C(  90),  INT8_C(  35) } },
    {
        { { -INT8_C(  98), -INT8_C(  35), -INT8_C( 121), -INT8_C( 110), -INT8_C(  74),  INT8_C( 124),  INT8_C(  51), -INT8_C( 127),
             INT8_C(   9),  INT8_C( 121), -INT8_C(  80), -INT8_C(  15),  INT8_C(  88), -INT8_C(  23), -INT8_C( 106),  INT8_C(  29) },
          { -INT8_C(  47),  INT8_C( 101),  INT8_C(  22),  INT8_C(   5), -INT8_C(  96), -INT8_C(  35), -INT8_C( 105),  INT8_C(  23),
             INT8_C( 108), -INT8_C(  64),  INT8_C( 100), -INT8_C(  40), -INT8_C(  63),  INT8_C(  10), -INT8_C(   5),  INT8_C(  95) },
          { -INT8_C(  25), -INT8_C( 125), -INT8_C(  15), -INT8_C(  98), -INT8_C(   1),  INT8_C(  36),  INT8_C(  31),  INT8_C(   8),
            -INT8_C(  99), -INT8_C(  49), -INT8_C(   7), -INT8_C(  11), -INT8_C(  71), -INT8_C( 113),  INT8_C(  18), -INT8_C( 118) } },
      { -INT8_C(  98), -INT8_C(  35), -INT8_C( 121), -INT8_C( 110), -INT8_C(  74),  INT8_C( 124),  INT8_C(  51), -INT8_C( 127),
         INT8_C(   9),  INT8_C( 121), -INT8_C(  80), -INT8_C(  15),  INT8_C(  88), -INT8_C(  23), -INT8_C( 106),  INT8_C(  29),
        -INT8_C(  47),  INT8_C( 101),  INT8_C(  22),  INT8_C(   5), -INT8_C(  96), -INT8_C(  35), -INT8_C( 105),  INT8_C(  23),
         INT8_C( 108), -INT8_C(  64),  INT8_C( 100), -INT8_C(  40), -INT8_C(  63),  INT8_C(  10), -INT8_C(   5),  INT8_C(  95),
        -INT8_C(  25), -INT8_C( 125), -INT8_C(  15), -INT8_C(  98), -INT8_C(   1),  INT8_C(  36),  INT8_C(  31),  INT8_C(   8),
        -INT8_C(  99), -INT8_C(  49), -INT8_C(   7), -INT8_C(  11), -INT8_C(  71), -INT8_C( 113),  INT8_C(  18), -INT8_C( 118) } },
    {
        { { -INT8_C(  11),  INT8_C(  41), -INT8_C( 113), -INT8_C( 107),  INT8_C(   6),  INT8_C(  38), -INT8_C(  83),  INT8_C( 114),
            -INT8_C(  26),  INT8_C(  17),  INT8_C(  75), -INT8_C(  89),  INT8_C(  27),  INT8_C(  70),  INT8_C(   6),  INT8_C(   3) },
          { -INT8_C(  55), -INT8_C(   8), -INT8_C(  95), -INT8_C(  56),  INT8_C(  28), -INT8_C(  64), -INT8_C(  48), -INT8_C(  70),
            -INT8_C( 113), -INT8_C(  54), -INT8_C(  81),  INT8_C(  72),  INT8_C(  89), -INT8_C(  62), -INT8_C(  46),  INT8_C(  78) },
          { -INT8_C(  21),  INT8_C(  97), -INT8_C(  28), -INT8_C(  15), -INT8_C( 121), -INT8_C( 111),  INT8_C( 100),  INT8_C( 109),
            -INT8_C(  94), -INT8_C(  81),  INT8_C(  20), -INT8_C(  67), -INT8_C(  11),  INT8_C(  27), -INT8_C(  64), -INT8_C(  65) } },
      { -INT8_C(  11),  INT8_C(  41), -INT8_C( 113), -INT8_C( 107),  INT8_C(   6),  INT8_C(  38), -INT8_C(  83),  INT8_C( 114),
        -INT8_C(  26),  INT8_C(  17),  INT8_C(  75), -INT8_C(  89),  INT8_C(  27),  INT8_C(  70),  INT8_C(   6),  INT8_C(   3),
        -INT8_C(  55), -INT8_C(   8), -INT8_C(  95), -INT8_C(  56),  INT8_C(  28), -INT8_C(  64), -INT8_C(  48), -INT8_C(  70),
        -INT8_C( 113), -INT8_C(  54), -INT8_C(  81),  INT8_C(  72),  INT8_C(  89), -INT8_C(  62), -INT8_C(  46),  INT8_C(  78),
        -INT8_C(  21),  INT8_C(  97), -INT8_C(  28), -INT8_C(  15), -INT8_C( 121), -INT8_C( 111),  INT8_C( 100),  INT8_C( 109),
        -INT8_C(  94), -INT8_C(  81),  INT8_C(  20), -INT8_C(  67), -INT8_C(  11),  INT8_C(  27), -INT8_C(  64), -INT8_C(  65) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x3_t r_ = { { simde_vld1q_s8(test_vec[i].r[0]),
                               simde_vld1q_s8(test_vec[i].r[1]),
                               simde_vld1q_s8(test_vec[i].r[2]) } };

    SIMDE_ALIGN_TO_16 int8_t a_[48];
    simde_vst1q_s8_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t c = simde_test_arm_neon_random_i8x16();
    simde_int8x16x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_i8x16x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    int8_t buf[48];
    simde_vst1q_s8_x3(buf, d);

    simde_test_codegen_write_vi8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[3][8];
    int16_t a[24];
  } test_vec[] = {
    {
        { {  INT16_C( 24851),  INT16_C( 12167),  INT16_C( 22561), -INT16_C( 19991), -INT16_C( 26334),  INT16_C( 31737), -INT16_C( 13221),  INT16_C( 18122) },
          { -INT16_C( 20947), -INT16_C( 19145), -INT16_C( 25793), -INT16_C(  7902),  INT16_C( 14154),  INT16_C( 16542),  INT16_C( 24402),  INT16_C( 26111) },
          { -INT16_C( 31040), -INT16_C(  7532),  INT16_C( 32478),  INT16_C(   147), -INT16_C( 29673),  INT16_C( 29308),  INT16_C( 18008), -INT16_C( 31048) } },
      {  INT16_C( 24851),  INT16_C( 12167),  INT16_C( 22561), -INT16_C( 19991), -INT16_C( 26334),  INT16_C( 31737), -INT16_C( 13221),  INT16_C( 18122),
        -INT16_C( 20947), -INT16_C( 19145), -INT16_C( 25793), -INT16_C(  7902),  INT16_C( 14154),  INT16_C( 16542),  INT16_C( 24402),  INT16_C( 26111),
        -INT16_C( 31040), -INT16_C(  7532),  INT16_C( 32478),  INT16_C(   147), -INT16_C( 29673),  INT16_C( 29308),  INT16_C( 18008), -INT16_C( 31048) } },
    {
        { { -INT16_C(  4108),  INT16_C( 13115),  INT16_C( 23947), -INT16_C( 10988), -INT16_C( 19820), -INT16_C(  6635),  INT16_C(  5137), -INT16_C( 11701) },
          { -INT16_C(  8037),  INT16_C( 31156),  INT16_C( 18270),  INT16_C( 30074), -INT16_C(  2349),  INT16_C( 11495), -INT16_C( 24772),  INT16_C( 12466) },
          { -INT16_C(  4722),  INT16_C(  6499),  INT16_C( 30538), -INT16_C(  8209),  INT16_C(  1065),  INT16_C( 15301),  INT16_C(  4377), -INT16_C( 19443) } },
      { -INT16_C(  4108),  INT16_C( 13115),  INT16_C( 23947), -INT16_C( 10988), -INT16_C( 19820), -INT16_C(  6635),  INT16_C(  5137), -INT16_C( 11701),
        -INT16_C(  8037),  INT16_C( 31156),  INT16_C( 18270),  INT16_C( 30074), -INT16_C(  2349),  INT16_C( 11495), -INT16_C( 24772),  INT16_C( 12466),
        -INT16_C(  4722),  INT16_C(  6499),  INT16_C( 30538), -INT16_C(  8209),  INT16_C(  1065),  INT16_C( 15301),  INT16_C(  4377), -INT16_C( 19443) } },
    {
        { { -INT16_C( 15887),  INT16_C( 20269), -INT16_C( 22776), -INT16_C(  9276), -INT16_C( 21603), -INT16_C(  9977), -INT16_C( 18102), -INT16_C( 10231) },
          {  INT16_C( 27814), -INT16_C(  3598), -INT16_C(  7709),  INT16_C(  3536), -INT16_C( 27163), -INT16_C(   440),  INT16_C( 21926), -INT16_C( 26702) },
          { -INT16_C(  8170),  INT16_C(  7910), -INT16_C( 21881),  INT16_C(  9721),  INT16_C(   341), -INT16_C( 24578),  INT16_C(  2234),  INT16_C( 24952) } },
      { -INT16_C( 15887),  INT16_C( 20269), -INT16_C( 22776), -INT16_C(  9276), -INT16_C( 21603), -INT16_C(  9977), -INT16_C( 18102), -INT16_C( 10231),
         INT16_C( 27814), -INT16_C(  3598), -INT16_C(  7709),  INT16_C(  3536), -INT16_C( 27163), -INT16_C(   440),  INT16_C( 21926), -INT16_C( 26702),
        -INT16_C(  8170),  INT16_C(  7910), -INT16_C( 21881),  INT16_C(  9721),  INT16_C(   341), -INT16_C( 24578),  INT16_C(  2234),  INT16_C( 24952) } },
    {
        { {  INT16_C( 27252),  INT16_C( 22610),  INT16_C(  8779),  INT16_C( 12389), -INT16_C( 21065),  INT16_C( 24111), -INT16_C(  7934),  INT16_C(  6389) },
          { -INT16_C(  9023),  INT16_C( 18742),  INT16_C( 12166), -INT16_C(  9106),  INT16_C( 27696), -INT16_C(  5253), -INT16_C(  3212), -INT16_C(  5812) },
          { -INT16_C( 24995), -INT16_C( 22463), -INT16_C( 22848),  INT16_C( 30681),  INT16_C(  2131),  INT16_C( 21973), -INT16_C( 13335), -INT16_C( 21651) } },
      {  INT16_C( 27252),  INT16_C( 22610),  INT16_C(  8779),  INT16_C( 12389), -INT16_C( 21065),  INT16_C( 24111), -INT16_C(  7934),  INT16_C(  6389),
        -INT16_C(  9023),  INT16_C( 18742),  INT16_C( 12166), -INT16_C(  9106),  INT16_C( 27696), -INT16_C(  5253), -INT16_C(  3212), -INT16_C(  5812),
        -INT16_C( 24995), -INT16_C( 22463), -INT16_C( 22848),  INT16_C( 30681),  INT16_C(  2131),  INT16_C( 21973), -INT16_C( 13335), -INT16_C( 21651) } },
    {
        { { -INT16_C( 23641),  INT16_C( 11764),  INT16_C( 25298),  INT16_C(   777), -INT16_C( 31282),  INT16_C( 17390),  INT16_C( 14968), -INT16_C( 10708) },
          {  INT16_C( 28120), -INT16_C( 26498),  INT16_C( 22291),  INT16_C( 26127), -INT16_C(  6817),  INT16_C( 18875),  INT16_C( 10416),  INT16_C( 22516) },
          { -INT16_C(  5941), -INT16_C( 25212), -INT16_C( 29110),  INT16_C(  6304), -INT16_C( 29165), -INT16_C( 29861), -INT16_C( 30776), -INT16_C( 24479) } },
      { -INT16_C( 23641),  INT16_C( 11764),  INT16_C( 25298),  INT16_C(   777), -INT16_C( 31282),  INT16_C( 17390),  INT16_C( 14968), -INT16_C( 10708),
         INT16_C( 28120), -INT16_C( 26498),  INT16_C( 22291),  INT16_C( 26127), -INT16_C(  6817),  INT16_C( 18875),  INT16_C( 10416),  INT16_C( 22516),
        -INT16_C(  5941), -INT16_C( 25212), -INT16_C( 29110),  INT16_C(  6304), -INT16_C( 29165), -INT16_C( 29861), -INT16_C( 30776), -INT16_C( 24479) } },
    {
        { { -INT16_C(  7948),  INT16_C(  1848),  INT16_C( 18487), -INT16_C( 26771),  INT16_C( 10285), -INT16_C(  8736), -INT16_C( 11184),  INT16_C(  6964) },
          { -INT16_C( 18244),  INT16_C(  1721),  INT16_C( 22854),  INT16_C( 22814),  INT16_C( 31464), -INT16_C( 20251),  INT16_C( 17921), -INT16_C(  2479) },
          { -INT16_C( 30426),  INT16_C( 24317),  INT16_C( 27601), -INT16_C(   267), -INT16_C( 10861), -INT16_C(  6949),  INT16_C(  4009),  INT16_C( 26111) } },
      { -INT16_C(  7948),  INT16_C(  1848),  INT16_C( 18487), -INT16_C( 26771),  INT16_C( 10285), -INT16_C(  8736), -INT16_C( 11184),  INT16_C(  6964),
        -INT16_C( 18244),  INT16_C(  1721),  INT16_C( 22854),  INT16_C( 22814),  INT16_C( 31464), -INT16_C( 20251),  INT16_C( 17921), -INT16_C(  2479),
        -INT16_C( 30426),  INT16_C( 24317),  INT16_C( 27601), -INT16_C(   267), -INT16_C( 10861), -INT16_C(  6949),  INT16_C(  4009),  INT16_C( 26111) } },
    {
        { { -INT16_C( 18232),  INT16_C(  3691), -INT16_C( 30446), -INT16_C(  1432),  INT16_C( 19715),  INT16_C(  1450), -INT16_C(  1133), -INT16_C( 17669) },
          { -INT16_C(  1915),  INT16_C( 22040),  INT16_C(  3427), -INT16_C(  2219),  INT16_C( 12514), -INT16_C( 29733), -INT16_C(  9664),  INT16_C(  2288) },
          {  INT16_C( 23443), -INT16_C( 23274),  INT16_C( 32484), -INT16_C(  5985),  INT16_C( 18891),  INT16_C( 24557), -INT16_C(  6075), -INT16_C( 13799) } },
      { -INT16_C( 18232),  INT16_C(  3691), -INT16_C( 30446), -INT16_C(  1432),  INT16_C( 19715),  INT16_C(  1450), -INT16_C(  1133), -INT16_C( 17669),
        -INT16_C(  1915),  INT16_C( 22040),  INT16_C(  3427), -INT16_C(  2219),  INT16_C( 12514), -INT16_C( 29733), -INT16_C(  9664),  INT16_C(  2288),
         INT16_C( 23443), -INT16_C( 23274),  INT16_C( 32484), -INT16_C(  5985),  INT16_C( 18891),  INT16_C( 24557), -INT16_C(  6075), -INT16_C( 13799) } },
    {
        { {  INT16_C( 12768),  INT16_C( 17440),  INT16_C( 30014),  INT16_C(  8251),  INT16_C(  5798), -INT16_C(  6485), -INT16_C( 25616), -INT16_C( 31762) },
          {  INT16_C(  1270), -INT16_C(  9688), -INT16_C( 14461),  INT16_C( 20162), -INT16_C( 20719),  INT16_C( 22189), -INT16_C( 14697),  INT16_C( 30752) },
          {  INT16_C( 16631),  INT16_C( 13756), -INT16_C(  2122),  INT16_C( 23637),  INT16_C(    13), -INT16_C(   702),  INT16_C( 12443), -INT16_C( 28287) } },
      {  INT16_C( 12768),  INT16_C( 17440),  INT16_C( 30014),  INT16_C(  8251),  INT16_C(  5798), -INT16_C(  6485), -INT16_C( 25616), -INT16_C( 31762),
         INT16_C(  1270), -INT16_C(  9688), -INT16_C( 14461),  INT16_C( 20162), -INT16_C( 20719),  INT16_C( 22189), -INT16_C( 14697),  INT16_C( 30752),
         INT16_C( 16631),  INT16_C( 13756), -INT16_C(  2122),  INT16_C( 23637),  INT16_C(    13), -INT16_C(   702),  INT16_C( 12443), -INT16_C( 28287) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x3_t r_ = { { simde_vld1q_s16(test_vec[i].r[0]),
                               simde_vld1q_s16(test_vec[i].r[1]),
                               simde_vld1q_s16(test_vec[i].r[2]) } };

    SIMDE_ALIGN_TO_16 int16_t a_[24];
    simde_vst1q_s16_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t c = simde_test_arm_neon_random_i16x8();
    simde_int16x8x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_i16x8x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    int16_t buf[24];
    simde_vst1q_s16_x3(buf, d);

    simde_test_codegen_write_vi16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[3][4];
    int32_t a[12];
  } test_vec[] = {
    {
        { { -INT32_C(  1217615564), -INT32_C(  2113524111),  INT32_C(  1977136094),  INT32_C(  1911421050) },
          { -INT32_C(   291002056), -INT32_C(  1387594592), -INT32_C(  1733587715), -INT32_C(   248894276) },
          {  INT32_C(  1185453781), -INT32_C(  1563906364), -INT32_C(   602365854), -INT32_C(   783481448) } },
      { -INT32_C(  1217615564), -INT32_C(  2113524111),  INT32_C(  1977136094),  INT32_C(  1911421050), -INT32_C(   291002056), -INT32_C(  1387594592), -INT32_C(  1733587715), -INT32_C(   248894276),
         INT32_C(  1185453781), -INT32_C(  1563906364), -INT32_C(   602365854), -INT32_C(   783481448) } },
    {
        { {  INT32_C(  1337980079), -INT32_C(   285406479),  INT32_C(  1401333910), -INT32_C(  1455116076) },
          {  INT32_C(   200338502), -INT32_C(    38946661), -INT32_C(   237386407),  INT32_C(  2059544267) },
          {  INT32_C(   214532635),  INT32_C(   586860172),  INT32_C(  1114996846),  INT32_C(  2012002609) } },
      {  INT32_C(  1337980079), -INT32_C(   285406479),  INT32_C(  1401333910), -INT32_C(  1455116076),  INT32_C(   200338502), -INT32_C(    38946661), -INT32_C(   237386407),  INT32_C(  2059544267),
         INT32_C(   214532635),  INT32_C(   586860172),  INT32_C(  1114996846),  INT32_C(  2012002609) } },
    {
        { {  INT32_C(  1099095206), -INT32_C(   314691436), -INT32_C(  1059121163),  INT32_C(  1480237373) },
          { -INT32_C(  1352399837),  INT32_C(   970088138),  INT32_C(   276514783), -INT32_C(  1484298495) },
          { -INT32_C(   655881661),  INT32_C(   801449530),  INT32_C(  2062591037),  INT32_C(  1775446598) } },
      {  INT32_C(  1099095206), -INT32_C(   314691436), -INT32_C(  1059121163),  INT32_C(  1480237373), -INT32_C(  1352399837),  INT32_C(   970088138),  INT32_C(   276514783), -INT32_C(  1484298495),
        -INT32_C(   655881661),  INT32_C(   801449530),  INT32_C(  2062591037),  INT32_C(  1775446598) } },
    {
        { { -INT32_C(   115787986),  INT32_C(  1966271382),  INT32_C(   864398642),  INT32_C(  1490684949) },
          {  INT32_C(  1345372694),  INT32_C(   629208808), -INT32_C(   526356326), -INT32_C(   917867622) },
          {  INT32_C(  1086481322), -INT32_C(  2135559090), -INT32_C(  1229702495),  INT32_C(  1561300551) } },
      { -INT32_C(   115787986),  INT32_C(  1966271382),  INT32_C(   864398642),  INT32_C(  1490684949),  INT32_C(  1345372694),  INT32_C(   629208808), -INT32_C(   526356326), -INT32_C(   917867622),
         INT32_C(  1086481322), -INT32_C(  2135559090), -INT32_C(  1229702495),  INT32_C(  1561300551) } },
    {
        { {  INT32_C(   967720785), -INT32_C(   799068619),  INT32_C(   951123870),  INT32_C(   469891698) },
          { -INT32_C(  1419918499),  INT32_C(  1496060599), -INT32_C(  1810898867), -INT32_C(  1074717074) },
          { -INT32_C(  1812357282),  INT32_C(  1801672909), -INT32_C(   911993769),  INT32_C(  1826989326) } },
      {  INT32_C(   967720785), -INT32_C(   799068619),  INT32_C(   951123870),  INT32_C(   469891698), -INT32_C(  1419918499),  INT32_C(  1496060599), -INT32_C(  1810898867), -INT32_C(  1074717074),
        -INT32_C(  1812357282),  INT32_C(  1801672909), -INT32_C(   911993769),  INT32_C(  1826989326) } },
    {
        { {  INT32_C(   538395241), -INT32_C(  1569111211), -INT32_C(  1841919709),  INT32_C(    89204647) },
          { -INT32_C(  1801893177), -INT32_C(   117375838),  INT32_C(   532849680), -INT32_C(  1299470263) },
          {  INT32_C(  1070834410),  INT32_C(   165760230),  INT32_C(  2107316181),  INT32_C(   109243711) } },
      {  INT32_C(   538395241), -INT32_C(  1569111211), -INT32_C(  1841919709),  INT32_C(    89204647), -INT32_C(  1801893177), -INT32_C(   117375838),  INT32_C(   532849680), -INT32_C(  1299470263),
         INT32_C(  1070834410),  INT32_C(   165760230),  INT32_C(  2107316181),  INT32_C(   109243711) } },
    {
        { { -INT32_C(   627434697),  INT32_C(   684956184), -INT32_C(  2008574402),  INT32_C(   674943550) },
          {  INT32_C(  1533545845),  INT32_C(   795101530), -INT32_C(  1599340447),  INT32_C(   614871021) },
          {  INT32_C(  1660829770),  INT32_C(   428593883), -INT32_C(  1499344280),  INT32_C(   449764517) } },
      { -INT32_C(   627434697),  INT32_C(   684956184), -INT32_C(  2008574402),  INT32_C(   674943550),  INT32_C(  1533545845),  INT32_C(   795101530), -INT32_C(  1599340447),  INT32_C(   614871021),
         INT32_C(  1660829770),  INT32_C(   428593883), -INT32_C(  1499344280),  INT32_C(   449764517) } },
    {
        { {  INT32_C(  1131755241), -INT32_C(   512501376), -INT32_C(   964616231), -INT32_C(  1712642226) },
          {  INT32_C(  1123805543),  INT32_C(   593266363), -INT32_C(    20316839), -INT32_C(  1021798183) },
          {  INT32_C(  1309052366),  INT32_C(  1076853094), -INT32_C(   418991975),  INT32_C(  1065415127) } },
      {  INT32_C(  1131755241), -INT32_C(   512501376), -INT32_C(   964616231), -INT32_C(  1712642226),  INT32_C(  1123805543),  INT32_C(   593266363), -INT32_C(    20316839), -INT32_C(  1021798183),
         INT32_C(  1309052366),  INT32_C(  1076853094), -INT32_C(   418991975),  INT32_C(  1065415127) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x3_t r_ = { { simde_vld1q_s32(test_vec[i].r[0]),
                               simde_vld1q_s32(test_vec[i].r[1]),
                               simde_vld1q_s32(test_vec[i].r[2]) } };

    SIMDE_ALIGN_TO_16 int32_t a_[12];
    simde_vst1q_s32_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t c = simde_test_arm_neon_random_i32x4();
    simde_int32x4x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_i32x4x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    int32_t buf[12];
    simde_vst1q_s32_x3(buf, d);

    simde_test_codegen_write_vi32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r[3][2];
    int64_t a[6];
  } test_vec[] = {
    {
        { {  INT64_C( 6609838406304365787), -INT64_C( 1551647182802025509) },
          { -INT64_C( 8023891749326258434),  INT64_C( 8660413965684747032) },
          {  INT64_C( 7625377633300033652), -INT64_C( 7182795427406861236) } },
      {  INT64_C( 6609838406304365787), -INT64_C( 1551647182802025509), -INT64_C( 8023891749326258434),  INT64_C( 8660413965684747032),
         INT64_C( 7625377633300033652), -INT64_C( 7182795427406861236) } },
    {
        { {  INT64_C(  764388120249600531), -INT64_C( 9194616457999543471) },
          { -INT64_C( 8515804154789661222), -INT64_C( 7624802511224705291) },
          {  INT64_C( 2866889530816934092), -INT64_C( 4045783956378434737) } },
      {  INT64_C(  764388120249600531), -INT64_C( 9194616457999543471), -INT64_C( 8515804154789661222), -INT64_C( 7624802511224705291),
         INT64_C( 2866889530816934092), -INT64_C( 4045783956378434737) } },
    {
        { { -INT64_C( 8018658470021574159), -INT64_C( 5185803795436426770) },
          {  INT64_C( 3783095040767142274),  INT64_C(  339855826956031491) },
          { -INT64_C( 3069506719337683397),  INT64_C( 6861603315756010133) } },
      { -INT64_C( 8018658470021574159), -INT64_C( 5185803795436426770),  INT64_C( 3783095040767142274),  INT64_C(  339855826956031491),
        -INT64_C( 3069506719337683397),  INT64_C( 6861603315756010133) } },
    {
        { { -INT64_C(  859281596229373703),  INT64_C( 5108379452176638669) },
          { -INT64_C( 7548451879049750654), -INT64_C( 3654580023213914867) },
          {  INT64_C(  425518936842043394), -INT64_C( 1534661601957393567) } },
      { -INT64_C(  859281596229373703),  INT64_C( 5108379452176638669), -INT64_C( 7548451879049750654), -INT64_C( 3654580023213914867),
         INT64_C(  425518936842043394), -INT64_C( 1534661601957393567) } },
    {
        { {  INT64_C( 6879971165932343264), -INT64_C( 1749488042864176618) },
          { -INT64_C( 8876945456046119791),  INT64_C( 6691965853399823244) },
          { -INT64_C( 2871686040706469517), -INT64_C( 7992065252285845941) } },
      {  INT64_C( 6879971165932343264), -INT64_C( 1749488042864176618), -INT64_C( 8876945456046119791),  INT64_C( 6691965853399823244),
        -INT64_C( 2871686040706469517), -INT64_C( 7992065252285845941) } },
    {
        { {  INT64_C( 4505051742951108830), -INT64_C( 8308279186545281317) },
          { -INT64_C(  730858942433660607), -INT64_C(  687578390011273755) },
          { -INT64_C( 3306910997839032533), -INT64_C( 7018336252069327373) } },
      {  INT64_C( 4505051742951108830), -INT64_C( 8308279186545281317), -INT64_C(  730858942433660607), -INT64_C(  687578390011273755),
        -INT64_C( 3306910997839032533), -INT64_C( 7018336252069327373) } },
    {
        { {  INT64_C( 5146906711526861774), -INT64_C(  565023854864592615) },
          { -INT64_C( 7981521355724742543),  INT64_C( 1096687264171189309) },
          {  INT64_C( 7984306362547427619),  INT64_C(  813683247830595973) } },
      {  INT64_C( 5146906711526861774), -INT64_C(  565023854864592615), -INT64_C( 7981521355724742543),  INT64_C( 1096687264171189309),
         INT64_C( 7984306362547427619),  INT64_C(  813683247830595973) } },
    {
        { {  INT64_C( 5482762077568507880),  INT64_C( 1108763933648794643) },
          {  INT64_C( 7258221356856437495),  INT64_C(  720576090530536026) },
          {  INT64_C( 3997690289280021535),  INT64_C( 8455208676079919195) } },
      {  INT64_C( 5482762077568507880),  INT64_C( 1108763933648794643),  INT64_C( 7258221356856437495),  INT64_C(  720576090530536026),
         INT64_C( 3997690289280021535),  INT64_C( 8455208676079919195) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x3_t r_ = { { simde_vld1q_s64(test_vec[i].r[0]),
                               simde_vld1q_s64(test_vec[i].r[1]),
                               simde_vld1q_s64(test_vec[i].r[2]) } };

    SIMDE_ALIGN_TO_16 int64_t a_[6];
    simde_vst1q_s64_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t c = simde_test_arm_neon_random_i64x2();
    simde_int64x2x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_i64x2x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    int64_t buf[6];
    simde_vst1q_s64_x3(buf, d);

    simde_test_codegen_write_vi64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u8_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[3][16];
    uint8_t a[48];
  } test_vec[] = {
    {
        { { UINT8_C(217), UINT8_C(234), UINT8_C(193), UINT8_C(184), UINT8_C( 76), UINT8_C(123), UINT8_C( 28), UINT8_C(166),
            UINT8_C(214), UINT8_C(210), UINT8_C(155), UINT8_C(248), UINT8_C(210), UINT8_C(156), UINT8_C(  3), UINT8_C(241) },
          { UINT8_C( 16), UINT8_C(147), UINT8_C( 31), UINT8_C( 52), UINT8_C( 57), UINT8_C(153), UINT8_C(107), UINT8_C(148),
            UINT8_C(249), UINT8_C(246), UINT8_C(219), UINT8_C(119), UINT8_C(229), UINT8_C( 49), UINT8_C(236), UINT8_C(191) },
          { UINT8_C( 28), UINT8_C(173), UINT8_C(119), UINT8_C(104), UINT8_C( 40), UINT8_C(147), UINT8_C( 14), UINT8_C(254),
            UINT8_C(101), UINT8_C(170), UINT8_C(247), UINT8_C( 55), UINT8_C( 70), UINT8_C(250), UINT8_C( 40), UINT8_C( 86) } },
      { UINT8_C(217), UINT8_C(234), UINT8_C(193), UINT8_C(184), UINT8_C( 76), UINT8_C(123), UINT8_C( 28), UINT8_C(166),
        UINT8_C(214), UINT8_C(210), UINT8_C(155), UINT8_C(248), UINT8_C(210), UINT8_C(156), UINT8_C(  3), UINT8_C(241),
        UINT8_C( 16), UINT8_C(147), UINT8_C( 31), UINT8_C( 52), UINT8_C( 57), UINT8_C(153), UINT8_C(107), UINT8_C(148),
        UINT8_C(249), UINT8_C(246), UINT8_C(219), UINT8_C(119), UINT8_C(229), UINT8_C( 49), UINT8_C(236), UINT8_C(191),
        UINT8_C( 28), UINT8_C(173), UINT8_C(119), UINT8_C(104), UINT8_C( 40), UINT8_C(147), UINT8_C( 14), UINT8_C(254),
        UINT8_C(101), UINT8_C(170), UINT8_C(247), UINT8_C( 55), UINT8_C( 70), UINT8_C(250), UINT8_C( 40), UINT8_C( 86) } },
    {
        { { UINT8_C(141), UINT8_C( 71), UINT8_C(138), UINT8_C(198), UINT8_C(224), UINT8_C(245), UINT8_C( 91), UINT8_C(217),
            UINT8_C(236), UINT8_C( 54), UINT8_C( 80), UINT8_C(209), UINT8_C(104), UINT8_C( 60), UINT8_C(144), UINT8_C(132) },
          { UINT8_C(233), UINT8_C(  7), UINT8_C(236), UINT8_C( 17), UINT8_C(154), UINT8_C(250), UINT8_C( 16),    UINT8_MAX,
            UINT8_C(164), UINT8_C(  7), UINT8_C( 54), UINT8_C(234), UINT8_C(  1), UINT8_C( 94), UINT8_C( 65), UINT8_C(142) },
          { UINT8_C(165), UINT8_C(203), UINT8_C( 84), UINT8_C(133), UINT8_C(193), UINT8_C(175), UINT8_C( 94), UINT8_C(173),
            UINT8_C(230), UINT8_C(174), UINT8_C(126), UINT8_C( 78), UINT8_C(234), UINT8_C( 15), UINT8_C(210), UINT8_C(211) } },
      { UINT8_C(141), UINT8_C( 71), UINT8_C(138), UINT8_C(198), UINT8_C(224), UINT8_C(245), UINT8_C( 91), UINT8_C(217),
        UINT8_C(236), UINT8_C( 54), UINT8_C( 80), UINT8_C(209), UINT8_C(104), UINT8_C( 60), UINT8_C(144), UINT8_C(132),
        UINT8_C(233), UINT8_C(  7), UINT8_C(236), UINT8_C( 17), UINT8_C(154), UINT8_C(250), UINT8_C( 16),    UINT8_MAX,
        UINT8_C(164), UINT8_C(  7), UINT8_C( 54), UINT8_C(234), UINT8_C(  1), UINT8_C( 94), UINT8_C( 65), UINT8_C(142),
        UINT8_C(165), UINT8_C(203), UINT8_C( 84), UINT8_C(133), UINT8_C(193), UINT8_C(175), UINT8_C( 94), UINT8_C(173),
        UINT8_C(230), UINT8_C(174), UINT8_C(126), UINT8_C( 78), UINT8_C(234), UINT8_C( 15), UINT8_C(210), UINT8_C(211) } },
    {
        { { UINT8_C( 22), UINT8_C(190), UINT8_C(229), UINT8_C(177), UINT8_C(184), UINT8_C(245), UINT8_C(176), UINT8_C( 93),
            UINT8_C(252), UINT8_C(231), UINT8_C( 71), UINT8_C(253), UINT8_C( 69), UINT8_C(136), UINT8_C(139), UINT8_C(235) },
          { UINT8_C( 84), UINT8_C(223), UINT8_C(112), UINT8_C( 21), UINT8_C(143), UINT8_C(207), UINT8_C(194), UINT8_C(117),
            UINT8_C(125), UINT8_C( 64), UINT8_C(195), UINT8_C(104), UINT8_C( 79), UINT8_C(149), UINT8_C( 59), UINT8_C(102) },
          { UINT8_C( 83), UINT8_C( 32), UINT8_C( 23), UINT8_C( 11), UINT8_C( 21), UINT8_C(199), UINT8_C(104), UINT8_C( 17),
            UINT8_C(174), UINT8_C(176), UINT8_C( 14), UINT8_C(244), UINT8_C( 56), UINT8_C(153), UINT8_C(223), UINT8_C(140) } },
      { UINT8_C( 22), UINT8_C(190), UINT8_C(229), UINT8_C(177), UINT8_C(184), UINT8_C(245), UINT8_C(176), UINT8_C( 93),
        UINT8_C(252), UINT8_C(231), UINT8_C( 71), UINT8_C(253), UINT8_C( 69), UINT8_C(136), UINT8_C(139), UINT8_C(235),
        UINT8_C( 84), UINT8_C(223), UINT8_C(112), UINT8_C( 21), UINT8_C(143), UINT8_C(207), UINT8_C(194), UINT8_C(117),
        UINT8_C(125), UINT8_C( 64), UINT8_C(195), UINT8_C(104), UINT8_C( 79), UINT8_C(149), UINT8_C( 59), UINT8_C(102),
        UINT8_C( 83), UINT8_C( 32), UINT8_C( 23), UINT8_C( 11), UINT8_C( 21), UINT8_C(199), UINT8_C(104), UINT8_C( 17),
        UINT8_C(174), UINT8_C(176), UINT8_C( 14), UINT8_C(244), UINT8_C( 56), UINT8_C(153), UINT8_C(223), UINT8_C(140) } },
    {
        { { UINT8_C(121), UINT8_C( 79), UINT8_C(161), UINT8_C(  8), UINT8_C( 30), UINT8_C( 99), UINT8_C(125), UINT8_C(156),
            UINT8_C(164), UINT8_C( 64), UINT8_C(  4), UINT8_C(243), UINT8_C(213), UINT8_C( 63), UINT8_C( 89), UINT8_C( 40) },
          { UINT8_C( 96), UINT8_C(112), UINT8_C( 51), UINT8_C(117), UINT8_C( 56), UINT8_C(156), UINT8_C(135), UINT8_C(230),
            UINT8_C( 76), UINT8_C(149), UINT8_C(218), UINT8_C(132), UINT8_C( 47), UINT8_C(185), UINT8_C( 17), UINT8_C(168) },
          { UINT8_C(  9), UINT8_C(178), UINT8_C(176), UINT8_C( 39), UINT8_C( 22), UINT8_C( 45), UINT8_C(195), UINT8_C(186),
            UINT8_C(109), UINT8_C(199), UINT8_C(173), UINT8_C( 66), UINT8_C(  7), UINT8_C(  7), UINT8_C(106), UINT8_C(103) } },
      { UINT8_C(121), UINT8_C( 79), UINT8_C(161), UINT8_C(  8), UINT8_C( 30), UINT8_C( 99), UINT8_C(125), UINT8_C(156),
        UINT8_C(164), UINT8_C( 64), UINT8_C(  4), UINT8_C(243), UINT8_C(213), UINT8_C( 63), UINT8_C( 89), UINT8_C( 40),
        UINT8_C( 96), UINT8_C(112), UINT8_C( 51), UINT8_C(117), UINT8_C( 56), UINT8_C(156), UINT8_C(135), UINT8_C(230),
        UINT8_C( 76), UINT8_C(149), UINT8_C(218), UINT8_C(132), UINT8_C( 47), UINT8_C(185), UINT8_C( 17), UINT8_C(168),
        UINT8_C(  9), UINT8_C(178), UINT8_C(176), UINT8_C( 39), UINT8_C( 22), UINT8_C( 45), UINT8_C(195), UINT8_C(186),
        UINT8_C(109), UINT8_C(199), UINT8_C(173), UINT8_C( 66), UINT8_C(  7), UINT8_C(  7), UINT8_C(106), UINT8_C(103) } },
    {
        { { UINT8_C(119), UINT8_C(157), UINT8_C(220), UINT8_C(175), UINT8_C( 57), UINT8_C( 99), UINT8_C(150), UINT8_C(133),
            UINT8_C(249), UINT8_C(112), UINT8_C( 10), UINT8_C( 40), UINT8_C( 42), UINT8_C( 27), UINT8_C(208), UINT8_C( 51) },
          { UINT8_C(205), UINT8_C(128), UINT8_C( 90), UINT8_C(227), UINT8_C(173), UINT8_C( 30), UINT8_C(157), UINT8_C( 26),
            UINT8_C(229), UINT8_C( 75), UINT8_C( 92), UINT8_C(236), UINT8_C( 82), UINT8_C(198), UINT8_C( 83), UINT8_C(201) },
          { UINT8_C( 99), UINT8_C( 48), UINT8_C(121), UINT8_C(157), UINT8_C(147), UINT8_C( 15), UINT8_C( 34), UINT8_C(140),
            UINT8_C(127), UINT8_C( 44), UINT8_C(180), UINT8_C(169), UINT8_C( 71), UINT8_C(132), UINT8_C(220), UINT8_C( 21) } },
      { UINT8_C(119), UINT8_C(157), UINT8_C(220), UINT8_C(175), UINT8_C( 57), UINT8_C( 99), UINT8_C(150), UINT8_C(133),
        UINT8_C(249), UINT8_C(112), UINT8_C( 10), UINT8_C( 40), UINT8_C( 42), UINT8_C( 27), UINT8_C(208), UINT8_C( 51),
        UINT8_C(205), UINT8_C(128), UINT8_C( 90), UINT8_C(227), UINT8_C(173), UINT8_C( 30), UINT8_C(157), UINT8_C( 26),
        UINT8_C(229), UINT8_C( 75), UINT8_C( 92), UINT8_C(236), UINT8_C( 82), UINT8_C(198), UINT8_C( 83), UINT8_C(201),
        UINT8_C( 99), UINT8_C( 48), UINT8_C(121), UINT8_C(157), UINT8_C(147), UINT8_C( 15), UINT8_C( 34), UINT8_C(140),
        UINT8_C(127), UINT8_C( 44), UINT8_C(180), UINT8_C(169), UINT8_C( 71), UINT8_C(132), UINT8_C(220), UINT8_C( 21) } },
    {
        { { UINT8_C(  4), UINT8_C( 55), UINT8_C(248), UINT8_C(177), UINT8_C( 85), UINT8_C(150), UINT8_C(203), UINT8_C( 58),
            UINT8_C(225), UINT8_C( 39), UINT8_C( 39), UINT8_C( 51), UINT8_C(237), UINT8_C(122), UINT8_C(252), UINT8_C( 81) },
          { UINT8_C(170), UINT8_C(117), UINT8_C(238), UINT8_C( 62), UINT8_C(132), UINT8_C( 16), UINT8_C(202), UINT8_C(  4),
            UINT8_C( 61), UINT8_C(127), UINT8_C(173), UINT8_C(132), UINT8_C(  3), UINT8_C(138), UINT8_C(153), UINT8_C(  8) },
          { UINT8_C(193), UINT8_C(146), UINT8_C(185), UINT8_C( 22), UINT8_C( 40), UINT8_C(133), UINT8_C( 80), UINT8_C(  9),
            UINT8_C(172), UINT8_C(119), UINT8_C( 60), UINT8_C(154), UINT8_C(242), UINT8_C( 56), UINT8_C(235), UINT8_C(156) } },
      { UINT8_C(  4), UINT8_C( 55), UINT8_C(248), UINT8_C(177), UINT8_C( 85), UINT8_C(150), UINT8_C(203), UINT8_C( 58),
        UINT8_C(225), UINT8_C( 39), UINT8_C( 39), UINT8_C( 51), UINT8_C(237), UINT8_C(122), UINT8_C(252), UINT8_C( 81),
        UINT8_C(170), UINT8_C(117), UINT8_C(238), UINT8_C( 62), UINT8_C(132), UINT8_C( 16), UINT8_C(202), UINT8_C(  4),
        UINT8_C( 61), UINT8_C(127), UINT8_C(173), UINT8_C(132), UINT8_C(  3), UINT8_C(138), UINT8_C(153), UINT8_C(  8),
        UINT8_C(193), UINT8_C(146), UINT8_C(185), UINT8_C( 22), UINT8_C( 40), UINT8_C(133), UINT8_C( 80), UINT8_C(  9),
        UINT8_C(172), UINT8_C(119), UINT8_C( 60), UINT8_C(154), UINT8_C(242), UINT8_C( 56), UINT8_C(235), UINT8_C(156) } },
    {
        { { UINT8_C(174), UINT8_C(217), UINT8_C(218), UINT8_C( 50), UINT8_C(233), UINT8_C(165), UINT8_C( 54), UINT8_C( 38),
            UINT8_C( 36), UINT8_C(228), UINT8_C(171), UINT8_C( 39), UINT8_C(110), UINT8_C( 68), UINT8_C( 47), UINT8_C( 47) },
          { UINT8_C(214), UINT8_C(233), UINT8_C( 69), UINT8_C(254), UINT8_C(110), UINT8_C(149), UINT8_C(  7), UINT8_C( 26),
            UINT8_C( 13), UINT8_C( 67), UINT8_C(180),    UINT8_MAX, UINT8_C(124), UINT8_C(159), UINT8_C(155), UINT8_C( 42) },
          { UINT8_C(120), UINT8_C(118), UINT8_C( 92), UINT8_C( 98), UINT8_C( 27), UINT8_C(147), UINT8_C(136), UINT8_C( 63),
            UINT8_C(119), UINT8_C( 51), UINT8_C(102), UINT8_C(229), UINT8_C(120), UINT8_C(150), UINT8_C( 20), UINT8_C( 78) } },
      { UINT8_C(174), UINT8_C(217), UINT8_C(218), UINT8_C( 50), UINT8_C(233), UINT8_C(165), UINT8_C( 54), UINT8_C( 38),
        UINT8_C( 36), UINT8_C(228), UINT8_C(171), UINT8_C( 39), UINT8_C(110), UINT8_C( 68), UINT8_C( 47), UINT8_C( 47),
        UINT8_C(214), UINT8_C(233), UINT8_C( 69), UINT8_C(254), UINT8_C(110), UINT8_C(149), UINT8_C(  7), UINT8_C( 26),
        UINT8_C( 13), UINT8_C( 67), UINT8_C(180),    UINT8_MAX, UINT8_C(124), UINT8_C(159), UINT8_C(155), UINT8_C( 42),
        UINT8_C(120), UINT8_C(118), UINT8_C( 92), UINT8_C( 98), UINT8_C( 27), UINT8_C(147), UINT8_C(136), UINT8_C( 63),
        UINT8_C(119), UINT8_C( 51), UINT8_C(102), UINT8_C(229), UINT8_C(120), UINT8_C(150), UINT8_C( 20), UINT8_C( 78) } },
    {
        { { UINT8_C(127), UINT8_C( 89), UINT8_C( 77), UINT8_C(237), UINT8_C(238), UINT8_C( 84), UINT8_C(  7), UINT8_C(251),
            UINT8_C(152), UINT8_C(188), UINT8_C(250), UINT8_C( 20), UINT8_C( 91), UINT8_C(150), UINT8_C( 62), UINT8_C(212) },
          { UINT8_C( 12), UINT8_C(154), UINT8_C( 54), UINT8_C( 39), UINT8_C( 45), UINT8_C(190), UINT8_C(102), UINT8_C(164),
            UINT8_C(242), UINT8_C(204), UINT8_C(137), UINT8_C(106), UINT8_C( 98), UINT8_C(157), UINT8_C(184), UINT8_C(225) },
          { UINT8_C(246), UINT8_C(  5), UINT8_C(206), UINT8_C(229), UINT8_C( 90), UINT8_C(214), UINT8_C(224), UINT8_C(242),
            UINT8_C(146), UINT8_C(219), UINT8_C(  6), UINT8_C(237), UINT8_C(113), UINT8_C( 68), UINT8_C(193), UINT8_C(125) } },
      { UINT8_C(127), UINT8_C( 89), UINT8_C( 77), UINT8_C(237), UINT8_C(238), UINT8_C( 84), UINT8_C(  7), UINT8_C(251),
        UINT8_C(152), UINT8_C(188), UINT8_C(250), UINT8_C( 20), UINT8_C( 91), UINT8_C(150), UINT8_C( 62), UINT8_C(212),
        UINT8_C( 12), UINT8_C(154), UINT8_C( 54), UINT8_C( 39), UINT8_C( 45), UINT8_C(190), UINT8_C(102), UINT8_C(164),
        UINT8_C(242), UINT8_C(204), UINT8_C(137), UINT8_C(106), UINT8_C( 98), UINT8_C(157), UINT8_C(184), UINT8_C(225),
        UINT8_C(246), UINT8_C(  5), UINT8_C(206), UINT8_C(229), UINT8_C( 90), UINT8_C(214), UINT8_C(224), UINT8_C(242),
        UINT8_C(146), UINT8_C(219), UINT8_C(  6), UINT8_C(237), UINT8_C(113), UINT8_C( 68), UINT8_C(193), UINT8_C(125) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x3_t r_ = { { simde_vld1q_u8(test_vec[i].r[0]),
                                simde_vld1q_u8(test_vec[i].r[1]),
                                simde_vld1q_u8(test_vec[i].r[2]) } };

    SIMDE_ALIGN_TO_16 uint8_t a_[48];
    simde_vst1q_u8_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t c = simde_test_arm_neon_random_u8x16();
    simde_uint8x16x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_u8x16x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    uint8_t buf[48];
    simde_vst1q_u8_x3(buf, d);

    simde_test_codegen_write_vu8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[3][8];
    uint16_t a[24];
  } test_vec[] = {
    {
        { { UINT16_C(63454), UINT16_C( 3236), UINT16_C( 2742), UINT16_C(43184), UINT16_C(15062), UINT16_C(14610), UINT16_C(51927), UINT16_C(52762) },
          { UINT16_C(59856), UINT16_C(10931), UINT16_C(37823), UINT16_C(20764), UINT16_C( 8814), UINT16_C(57150), UINT16_C(  102), UINT16_C(17500) },
          { UINT16_C(  247), UINT16_C(44368), UINT16_C(  266), UINT16_C(57685), UINT16_C(26427), UINT16_C( 4634), UINT16_C(13362), UINT16_C(  736) } },
      { UINT16_C(63454), UINT16_C( 3236), UINT16_C( 2742), UINT16_C(43184), UINT16_C(15062), UINT16_C(14610), UINT16_C(51927), UINT16_C(52762),
        UINT16_C(59856), UINT16_C(10931), UINT16_C(37823), UINT16_C(20764), UINT16_C( 8814), UINT16_C(57150), UINT16_C(  102), UINT16_C(17500),
        UINT16_C(  247), UINT16_C(44368), UINT16_C(  266), UINT16_C(57685), UINT16_C(26427), UINT16_C( 4634), UINT16_C(13362), UINT16_C(  736) } },
    {
        { { UINT16_C(37661), UINT16_C(56364), UINT16_C(18471), UINT16_C(38189), UINT16_C(27754), UINT16_C(53365), UINT16_C(53612), UINT16_C(25364) },
          { UINT16_C(26066), UINT16_C(56337), UINT16_C(26214), UINT16_C(41405), UINT16_C(55246), UINT16_C(  179), UINT16_C(37900), UINT16_C(10498) },
          { UINT16_C(11815), UINT16_C(19974), UINT16_C(13174), UINT16_C(57572), UINT16_C(22943), UINT16_C( 2992), UINT16_C(50218), UINT16_C(64623) } },
      { UINT16_C(37661), UINT16_C(56364), UINT16_C(18471), UINT16_C(38189), UINT16_C(27754), UINT16_C(53365), UINT16_C(53612), UINT16_C(25364),
        UINT16_C(26066), UINT16_C(56337), UINT16_C(26214), UINT16_C(41405), UINT16_C(55246), UINT16_C(  179), UINT16_C(37900), UINT16_C(10498),
        UINT16_C(11815), UINT16_C(19974), UINT16_C(13174), UINT16_C(57572), UINT16_C(22943), UINT16_C( 2992), UINT16_C(50218), UINT16_C(64623) } },
    {
        { { UINT16_C(32809), UINT16_C(36825), UINT16_C(38630), UINT16_C(46128), UINT16_C(58478), UINT16_C(31412), UINT16_C(46712), UINT16_C(40867) },
          { UINT16_C(43492), UINT16_C(23278), UINT16_C(53981), UINT16_C(31802), UINT16_C(59947), UINT16_C(21896), UINT16_C(63407), UINT16_C(55378) },
          { UINT16_C(11127), UINT16_C(23912), UINT16_C(39105), UINT16_C(12050), UINT16_C(50812), UINT16_C(62633), UINT16_C(19837), UINT16_C(24980) } },
      { UINT16_C(32809), UINT16_C(36825), UINT16_C(38630), UINT16_C(46128), UINT16_C(58478), UINT16_C(31412), UINT16_C(46712), UINT16_C(40867),
        UINT16_C(43492), UINT16_C(23278), UINT16_C(53981), UINT16_C(31802), UINT16_C(59947), UINT16_C(21896), UINT16_C(63407), UINT16_C(55378),
        UINT16_C(11127), UINT16_C(23912), UINT16_C(39105), UINT16_C(12050), UINT16_C(50812), UINT16_C(62633), UINT16_C(19837), UINT16_C(24980) } },
    {
        { { UINT16_C(33526), UINT16_C(54204), UINT16_C(63060), UINT16_C(32592), UINT16_C(55521), UINT16_C(37076), UINT16_C( 9935), UINT16_C(18024) },
          { UINT16_C(53329), UINT16_C( 5027), UINT16_C(46441), UINT16_C(58690), UINT16_C(60540), UINT16_C(63962), UINT16_C(28217), UINT16_C(12122) },
          { UINT16_C( 5872), UINT16_C(17411), UINT16_C(21261), UINT16_C(61123), UINT16_C(38699), UINT16_C(64126), UINT16_C(59070), UINT16_C( 3904) } },
      { UINT16_C(33526), UINT16_C(54204), UINT16_C(63060), UINT16_C(32592), UINT16_C(55521), UINT16_C(37076), UINT16_C( 9935), UINT16_C(18024),
        UINT16_C(53329), UINT16_C( 5027), UINT16_C(46441), UINT16_C(58690), UINT16_C(60540), UINT16_C(63962), UINT16_C(28217), UINT16_C(12122),
        UINT16_C( 5872), UINT16_C(17411), UINT16_C(21261), UINT16_C(61123), UINT16_C(38699), UINT16_C(64126), UINT16_C(59070), UINT16_C( 3904) } },
    {
        { { UINT16_C(58295), UINT16_C( 8226), UINT16_C(26009), UINT16_C( 5381), UINT16_C(57169), UINT16_C(35342), UINT16_C(26701), UINT16_C(15801) },
          { UINT16_C(48255), UINT16_C(35969), UINT16_C(17423), UINT16_C(14970), UINT16_C(63708), UINT16_C(39476), UINT16_C(29918), UINT16_C(38313) },
          { UINT16_C(52312), UINT16_C(61877), UINT16_C(47921), UINT16_C(33286), UINT16_C( 5274), UINT16_C(59404), UINT16_C(50556), UINT16_C(64293) } },
      { UINT16_C(58295), UINT16_C( 8226), UINT16_C(26009), UINT16_C( 5381), UINT16_C(57169), UINT16_C(35342), UINT16_C(26701), UINT16_C(15801),
        UINT16_C(48255), UINT16_C(35969), UINT16_C(17423), UINT16_C(14970), UINT16_C(63708), UINT16_C(39476), UINT16_C(29918), UINT16_C(38313),
        UINT16_C(52312), UINT16_C(61877), UINT16_C(47921), UINT16_C(33286), UINT16_C( 5274), UINT16_C(59404), UINT16_C(50556), UINT16_C(64293) } },
    {
        { { UINT16_C(42882), UINT16_C(37255), UINT16_C(  491), UINT16_C(51148), UINT16_C(  249), UINT16_C(55393), UINT16_C( 2933), UINT16_C(52589) },
          { UINT16_C( 9175), UINT16_C( 2238), UINT16_C(50398), UINT16_C(30858), UINT16_C(38616), UINT16_C(21600), UINT16_C(34395), UINT16_C(56656) },
          { UINT16_C(55085), UINT16_C( 6255), UINT16_C(15321), UINT16_C(53984), UINT16_C(16699), UINT16_C(45226), UINT16_C( 6220), UINT16_C( 9085) } },
      { UINT16_C(42882), UINT16_C(37255), UINT16_C(  491), UINT16_C(51148), UINT16_C(  249), UINT16_C(55393), UINT16_C( 2933), UINT16_C(52589),
        UINT16_C( 9175), UINT16_C( 2238), UINT16_C(50398), UINT16_C(30858), UINT16_C(38616), UINT16_C(21600), UINT16_C(34395), UINT16_C(56656),
        UINT16_C(55085), UINT16_C( 6255), UINT16_C(15321), UINT16_C(53984), UINT16_C(16699), UINT16_C(45226), UINT16_C( 6220), UINT16_C( 9085) } },
    {
        { { UINT16_C(15163), UINT16_C( 6443), UINT16_C(46591), UINT16_C(55185), UINT16_C(62027), UINT16_C(42796), UINT16_C(31864), UINT16_C(42372) },
          { UINT16_C(62291), UINT16_C(11453), UINT16_C(40238), UINT16_C(27391), UINT16_C(43487), UINT16_C(11034), UINT16_C(39105), UINT16_C(64591) },
          { UINT16_C(31443), UINT16_C(54037), UINT16_C(42800), UINT16_C(31658), UINT16_C(54937), UINT16_C( 4386), UINT16_C(42834), UINT16_C(42678) } },
      { UINT16_C(15163), UINT16_C( 6443), UINT16_C(46591), UINT16_C(55185), UINT16_C(62027), UINT16_C(42796), UINT16_C(31864), UINT16_C(42372),
        UINT16_C(62291), UINT16_C(11453), UINT16_C(40238), UINT16_C(27391), UINT16_C(43487), UINT16_C(11034), UINT16_C(39105), UINT16_C(64591),
        UINT16_C(31443), UINT16_C(54037), UINT16_C(42800), UINT16_C(31658), UINT16_C(54937), UINT16_C( 4386), UINT16_C(42834), UINT16_C(42678) } },
    {
        { { UINT16_C(29594), UINT16_C(51666), UINT16_C(53521), UINT16_C(61491), UINT16_C(19835), UINT16_C(15387), UINT16_C(27365), UINT16_C(47417) },
          { UINT16_C(20197), UINT16_C( 5516), UINT16_C(14069), UINT16_C(36496), UINT16_C(45837), UINT16_C(24479), UINT16_C(21850), UINT16_C(62469) },
          { UINT16_C(55497), UINT16_C(55997), UINT16_C(61609), UINT16_C( 9418), UINT16_C(58686), UINT16_C( 9057), UINT16_C(39504), UINT16_C(13788) } },
      { UINT16_C(29594), UINT16_C(51666), UINT16_C(53521), UINT16_C(61491), UINT16_C(19835), UINT16_C(15387), UINT16_C(27365), UINT16_C(47417),
        UINT16_C(20197), UINT16_C( 5516), UINT16_C(14069), UINT16_C(36496), UINT16_C(45837), UINT16_C(24479), UINT16_C(21850), UINT16_C(62469),
        UINT16_C(55497), UINT16_C(55997), UINT16_C(61609), UINT16_C( 9418), UINT16_C(58686), UINT16_C( 9057), UINT16_C(39504), UINT16_C(13788) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x3_t r_ = { { simde_vld1q_u16(test_vec[i].r[0]),
                                simde_vld1q_u16(test_vec[i].r[1]),
                                simde_vld1q_u16(test_vec[i].r[2]) } };

    SIMDE_ALIGN_TO_16 uint16_t a_[24];
    simde_vst1q_u16_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t c = simde_test_arm_neon_random_u16x8();
    simde_uint16x8x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_u16x8x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    uint16_t buf[24];
    simde_vst1q_u16_x3(buf, d);

    simde_test_codegen_write_vu16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[3][4];
    uint32_t a[12];
  } test_vec[] = {
    {
        { { UINT32_C(3729418472), UINT32_C(2892815007), UINT32_C(3876261005), UINT32_C( 719065441) },
          { UINT32_C(2449775081), UINT32_C(3367489162), UINT32_C(  82516148), UINT32_C(2587478194) },
          { UINT32_C(3480781616), UINT32_C(3950765405), UINT32_C(1389529073), UINT32_C(2172497560) } },
      { UINT32_C(3729418472), UINT32_C(2892815007), UINT32_C(3876261005), UINT32_C( 719065441), UINT32_C(2449775081), UINT32_C(3367489162), UINT32_C(  82516148), UINT32_C(2587478194),
        UINT32_C(3480781616), UINT32_C(3950765405), UINT32_C(1389529073), UINT32_C(2172497560) } },
    {
        { { UINT32_C(3524493640), UINT32_C(  77253200), UINT32_C(2483586530), UINT32_C(2117026125) },
          { UINT32_C( 558737348), UINT32_C(2097990028), UINT32_C(3906002768), UINT32_C(3580448141) },
          { UINT32_C( 514292942), UINT32_C( 690110791), UINT32_C( 348007111), UINT32_C( 798158187) } },
      { UINT32_C(3524493640), UINT32_C(  77253200), UINT32_C(2483586530), UINT32_C(2117026125), UINT32_C( 558737348), UINT32_C(2097990028), UINT32_C(3906002768), UINT32_C(3580448141),
        UINT32_C( 514292942), UINT32_C( 690110791), UINT32_C( 348007111), UINT32_C( 798158187) } },
    {
        { { UINT32_C( 559014036), UINT32_C(4187905449), UINT32_C(3403771452), UINT32_C(2325695163) },
          { UINT32_C( 229132230), UINT32_C(1329056648), UINT32_C(1634006517), UINT32_C(1989211874) },
          { UINT32_C(2140660182), UINT32_C(2071475775), UINT32_C(1615157668), UINT32_C(1793779107) } },
      { UINT32_C( 559014036), UINT32_C(4187905449), UINT32_C(3403771452), UINT32_C(2325695163), UINT32_C( 229132230), UINT32_C(1329056648), UINT32_C(1634006517), UINT32_C(1989211874),
        UINT32_C(2140660182), UINT32_C(2071475775), UINT32_C(1615157668), UINT32_C(1793779107) } },
    {
        { { UINT32_C(3027735084), UINT32_C(1392815709), UINT32_C(2243192995), UINT32_C( 905725022) },
          { UINT32_C(1706332966), UINT32_C(1860185545), UINT32_C( 718153350), UINT32_C( 932493323) },
          { UINT32_C(2833976138), UINT32_C(1576791994), UINT32_C(3068374871), UINT32_C( 434888691) } },
      { UINT32_C(3027735084), UINT32_C(1392815709), UINT32_C(2243192995), UINT32_C( 905725022), UINT32_C(1706332966), UINT32_C(1860185545), UINT32_C( 718153350), UINT32_C( 932493323),
        UINT32_C(2833976138), UINT32_C(1576791994), UINT32_C(3068374871), UINT32_C( 434888691) } },
    {
        { { UINT32_C(1014931314), UINT32_C(1403674572), UINT32_C(2424141957), UINT32_C(2059866416) },
          { UINT32_C(3592598044), UINT32_C(4180942242), UINT32_C(3232700364), UINT32_C(1759091446) },
          { UINT32_C( 111433786), UINT32_C(1012485815), UINT32_C(4140619462), UINT32_C(  74552295) } },
      { UINT32_C(1014931314), UINT32_C(1403674572), UINT32_C(2424141957), UINT32_C(2059866416), UINT32_C(3592598044), UINT32_C(4180942242), UINT32_C(3232700364), UINT32_C(1759091446),
        UINT32_C( 111433786), UINT32_C(1012485815), UINT32_C(4140619462), UINT32_C(  74552295) } },
    {
        { { UINT32_C(3889861445), UINT32_C(2111901361), UINT32_C( 457019429), UINT32_C(1703155499) },
          { UINT32_C( 644556911), UINT32_C(1029883255), UINT32_C(2201235099), UINT32_C( 109553089) },
          { UINT32_C(3924713784), UINT32_C(2506608496), UINT32_C(2326897759), UINT32_C( 720319931) } },
      { UINT32_C(3889861445), UINT32_C(2111901361), UINT32_C( 457019429), UINT32_C(1703155499), UINT32_C( 644556911), UINT32_C(1029883255), UINT32_C(2201235099), UINT32_C( 109553089),
        UINT32_C(3924713784), UINT32_C(2506608496), UINT32_C(2326897759), UINT32_C( 720319931) } },
    {
        { { UINT32_C(3562036061), UINT32_C(3138564640), UINT32_C(2705213152), UINT32_C( 598263275) },
          { UINT32_C(2534250023), UINT32_C(3291247717), UINT32_C(3562003736), UINT32_C(1895710226) },
          { UINT32_C(3108261785), UINT32_C(3799340545), UINT32_C(2273555356), UINT32_C(2695572345) } },
      { UINT32_C(3562036061), UINT32_C(3138564640), UINT32_C(2705213152), UINT32_C( 598263275), UINT32_C(2534250023), UINT32_C(3291247717), UINT32_C(3562003736), UINT32_C(1895710226),
        UINT32_C(3108261785), UINT32_C(3799340545), UINT32_C(2273555356), UINT32_C(2695572345) } },
    {
        { { UINT32_C( 641185985), UINT32_C(1156277036), UINT32_C(1394096705), UINT32_C( 314775416) },
          { UINT32_C(1741359206), UINT32_C(4215881822), UINT32_C(1837288948), UINT32_C(3121425912) },
          { UINT32_C( 299910373), UINT32_C(3898002343), UINT32_C(2117889541), UINT32_C(3952148357) } },
      { UINT32_C( 641185985), UINT32_C(1156277036), UINT32_C(1394096705), UINT32_C( 314775416), UINT32_C(1741359206), UINT32_C(4215881822), UINT32_C(1837288948), UINT32_C(3121425912),
        UINT32_C( 299910373), UINT32_C(3898002343), UINT32_C(2117889541), UINT32_C(3952148357) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x3_t r_ = { { simde_vld1q_u32(test_vec[i].r[0]),
                                simde_vld1q_u32(test_vec[i].r[1]),
                                simde_vld1q_u32(test_vec[i].r[2]) } };

    SIMDE_ALIGN_TO_16 uint32_t a_[12];
    simde_vst1q_u32_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_u32x4x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    uint32_t buf[12];
    simde_vst1q_u32_x3(buf, d);

    simde_test_codegen_write_vu32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r[3][2];
    uint64_t a[6];
  } test_vec[] = {
    {
        { { UINT64_C(10403768809748126471), UINT64_C(17734060502469698409) },
          { UINT64_C(14834398439802469454), UINT64_C( 2395311478632291020) },
          { UINT64_C(10836760411903594551), UINT64_C(13318010972271042763) } },
      { UINT64_C(10403768809748126471), UINT64_C(17734060502469698409), UINT64_C(14834398439802469454), UINT64_C( 2395311478632291020),
        UINT64_C(10836760411903594551), UINT64_C(13318010972271042763) } },
    {
        { { UINT64_C(  407165896905054993), UINT64_C(  351445481845944997) },
          { UINT64_C( 1939145226926384933), UINT64_C(  557543611881218458) },
          { UINT64_C(11232970286156507813), UINT64_C(17675004353776860024) } },
      { UINT64_C(  407165896905054993), UINT64_C(  351445481845944997), UINT64_C( 1939145226926384933), UINT64_C(  557543611881218458),
        UINT64_C(11232970286156507813), UINT64_C(17675004353776860024) } },
    {
        { { UINT64_C(17801094752373318305), UINT64_C( 8074875839067128082) },
          { UINT64_C(17199865409659924258), UINT64_C(16659517911248145517) },
          { UINT64_C(13759871989849750177), UINT64_C(14564595739931373795) } },
      { UINT64_C(17801094752373318305), UINT64_C( 8074875839067128082), UINT64_C(17199865409659924258), UINT64_C(16659517911248145517),
        UINT64_C(13759871989849750177), UINT64_C(14564595739931373795) } },
    {
        { { UINT64_C(  948734087435218629), UINT64_C( 9137377986491342496) },
          { UINT64_C( 7737307891966453495), UINT64_C(14038347846904325984) },
          { UINT64_C(16741331480747095208), UINT64_C( 1360823877911945094) } },
      { UINT64_C(  948734087435218629), UINT64_C( 9137377986491342496), UINT64_C( 7737307891966453495), UINT64_C(14038347846904325984),
        UINT64_C(16741331480747095208), UINT64_C( 1360823877911945094) } },
    {
        { { UINT64_C( 3402212025738550852), UINT64_C( 3817938181475029564) },
          { UINT64_C(12173178261873687230), UINT64_C(11573951273137651312) },
          { UINT64_C(11911075881548534605), UINT64_C( 5599903492297622774) } },
      { UINT64_C( 3402212025738550852), UINT64_C( 3817938181475029564), UINT64_C(12173178261873687230), UINT64_C(11573951273137651312),
        UINT64_C(11911075881548534605), UINT64_C( 5599903492297622774) } },
    {
        { { UINT64_C( 8331450420443689684), UINT64_C(16789028647699655425) },
          { UINT64_C(  359531567795956463), UINT64_C( 9993554327186627540) },
          { UINT64_C( 5180300958306993006), UINT64_C( 8020526654460060619) } },
      { UINT64_C( 8331450420443689684), UINT64_C(16789028647699655425), UINT64_C(  359531567795956463), UINT64_C( 9993554327186627540),
        UINT64_C( 5180300958306993006), UINT64_C( 8020526654460060619) } },
    {
        { { UINT64_C( 8584077094592926221), UINT64_C( 5899868220857951903) },
          { UINT64_C( 5484161147315904910), UINT64_C( 8032451831478271882) },
          { UINT64_C(11776255538936561747), UINT64_C( 6955204696398710865) } },
      { UINT64_C( 8584077094592926221), UINT64_C( 5899868220857951903), UINT64_C( 5484161147315904910), UINT64_C( 8032451831478271882),
        UINT64_C(11776255538936561747), UINT64_C( 6955204696398710865) } },
    {
        { { UINT64_C( 8793084692815693882), UINT64_C( 1000078094486518287) },
          { UINT64_C( 7414456697634384445), UINT64_C(17432343130826006201) },
          { UINT64_C( 9210621483031470184), UINT64_C(10535555963185813357) } },
      { UINT64_C( 8793084692815693882), UINT64_C( 1000078094486518287), UINT64_C( 7414456697634384445), UINT64_C(17432343130826006201),
        UINT64_C( 9210621483031470184), UINT64_C(10535555963185813357) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x3_t r_ = { { simde_vld1q_u64(test_vec[i].r[0]),
                                simde_vld1q_u64(test_vec[i].r[1]),
                                simde_vld1q_u64(test_vec[i].r[2]) } };

    SIMDE_ALIGN_TO_16 uint64_t a_[6];
    simde_vst1q_u64_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t c = simde_test_arm_neon_random_u64x2();
    simde_uint64x2x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_u64x2x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    uint64_t buf[6];
    simde_vst1q_u64_x3(buf, d);

    simde_test_codegen_write_vu64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_p8_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_TO_16 simde_poly8_t val[3][16];
    SIMDE_ALIGN_TO_16 simde_poly8_t r[48];
  } test_vec[] = {
  { { {  SIMDE_POLY8_C(  118),  SIMDE_POLY8_C(  211),  SIMDE_POLY8_C(  123),  SIMDE_POLY8_C(  105),
         SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(  106),  SIMDE_POLY8_C(  199),  SIMDE_POLY8_C(    8),
         SIMDE_POLY8_C(  195),  SIMDE_POLY8_C(  193),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(   10),
         SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(  227),  SIMDE_POLY8_C(  117),  SIMDE_POLY8_C(  194)  },
      {  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(  117),  SIMDE_POLY8_C(   25),
         SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(  253),  SIMDE_POLY8_C(  228),  SIMDE_POLY8_C(  247),
         SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(  234),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(   70),  SIMDE_POLY8_C(   26)  },
      {  SIMDE_POLY8_C(  118),  SIMDE_POLY8_C(   51),  SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(   15),
         SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(   86),  SIMDE_POLY8_C(  138),  SIMDE_POLY8_C(  171),
         SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(  216),  SIMDE_POLY8_C(  238),  SIMDE_POLY8_C(   23),
         SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(  119)  } },
      {  SIMDE_POLY8_C(  118),  SIMDE_POLY8_C(  211),  SIMDE_POLY8_C(  123),  SIMDE_POLY8_C(  105),
         SIMDE_POLY8_C(  240),  SIMDE_POLY8_C(  106),  SIMDE_POLY8_C(  199),  SIMDE_POLY8_C(    8),
         SIMDE_POLY8_C(  195),  SIMDE_POLY8_C(  193),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(   10),
         SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(  227),  SIMDE_POLY8_C(  117),  SIMDE_POLY8_C(  194),
         SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(  117),  SIMDE_POLY8_C(   25),
         SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(  253),  SIMDE_POLY8_C(  228),  SIMDE_POLY8_C(  247),
         SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(  234),  SIMDE_POLY8_C(   45),
         SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(   70),  SIMDE_POLY8_C(   26),
         SIMDE_POLY8_C(  118),  SIMDE_POLY8_C(   51),  SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(   15),
         SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(   86),  SIMDE_POLY8_C(  138),  SIMDE_POLY8_C(  171),
         SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(  216),  SIMDE_POLY8_C(  238),  SIMDE_POLY8_C(   23),
         SIMDE_POLY8_C(   71),  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(  119) } },
  { { {  SIMDE_POLY8_C(   52),  SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(  130),  SIMDE_POLY8_C(  188),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  101),  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(  186),
         SIMDE_POLY8_C(  155),  SIMDE_POLY8_C(  182),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(  185),
         SIMDE_POLY8_C(  106),  SIMDE_POLY8_C(  153),  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(  116)  },
      {  SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(   68),  SIMDE_POLY8_C(   26),  SIMDE_POLY8_C(  137),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(  226),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(  143),
         SIMDE_POLY8_C(   63),  SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(   35),
         SIMDE_POLY8_C(  119),  SIMDE_POLY8_C(  162),  SIMDE_POLY8_C(  235),  SIMDE_POLY8_C(   29)  },
      {  SIMDE_POLY8_C(   62),  SIMDE_POLY8_C(  251),  SIMDE_POLY8_C(  150),  SIMDE_POLY8_C(   30),
         SIMDE_POLY8_C(   14),  SIMDE_POLY8_C(   11),  SIMDE_POLY8_C(  209),  SIMDE_POLY8_C(  198),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  128),  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(  199),
         SIMDE_POLY8_C(  115),  SIMDE_POLY8_C(   26),  SIMDE_POLY8_C(   27),  SIMDE_POLY8_C(  127)  } },
      {  SIMDE_POLY8_C(   52),  SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(  130),  SIMDE_POLY8_C(  188),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  101),  SIMDE_POLY8_C(   66),  SIMDE_POLY8_C(  186),
         SIMDE_POLY8_C(  155),  SIMDE_POLY8_C(  182),  SIMDE_POLY8_C(   43),  SIMDE_POLY8_C(  185),
         SIMDE_POLY8_C(  106),  SIMDE_POLY8_C(  153),  SIMDE_POLY8_C(   60),  SIMDE_POLY8_C(  116),
         SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(   68),  SIMDE_POLY8_C(   26),  SIMDE_POLY8_C(  137),
         SIMDE_POLY8_C(  190),  SIMDE_POLY8_C(  226),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(  143),
         SIMDE_POLY8_C(   63),  SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(   35),
         SIMDE_POLY8_C(  119),  SIMDE_POLY8_C(  162),  SIMDE_POLY8_C(  235),  SIMDE_POLY8_C(   29),
         SIMDE_POLY8_C(   62),  SIMDE_POLY8_C(  251),  SIMDE_POLY8_C(  150),  SIMDE_POLY8_C(   30),
         SIMDE_POLY8_C(   14),  SIMDE_POLY8_C(   11),  SIMDE_POLY8_C(  209),  SIMDE_POLY8_C(  198),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  128),  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(  199),
         SIMDE_POLY8_C(  115),  SIMDE_POLY8_C(   26),  SIMDE_POLY8_C(   27),  SIMDE_POLY8_C(  127) } },
  { { {  SIMDE_POLY8_C(  194),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(  143),
         SIMDE_POLY8_C(  248),  SIMDE_POLY8_C(   39),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(  167),
         SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(   73),  SIMDE_POLY8_C(  248),  SIMDE_POLY8_C(  115),
         SIMDE_POLY8_C(   51),  SIMDE_POLY8_C(  113),  SIMDE_POLY8_C(  225),  SIMDE_POLY8_C(  199)  },
      {  SIMDE_POLY8_C(   10),  SIMDE_POLY8_C(   31),  SIMDE_POLY8_C(  163),  SIMDE_POLY8_C(  126),
         SIMDE_POLY8_C(   67),  SIMDE_POLY8_C(  175),  SIMDE_POLY8_C(  188),  SIMDE_POLY8_C(  115),
         SIMDE_POLY8_C(   27),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(    9),
         SIMDE_POLY8_C(    4),    SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(   77)  },
      {  SIMDE_POLY8_C(   34),  SIMDE_POLY8_C(   72),  SIMDE_POLY8_C(  166),  SIMDE_POLY8_C(  234),
         SIMDE_POLY8_C(  141),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(   64),  SIMDE_POLY8_C(    0),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  159),  SIMDE_POLY8_C(  160),  SIMDE_POLY8_C(  114),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  156),    SIMDE_POLY8_C(UINT8_MAX)  } },
      {  SIMDE_POLY8_C(  194),  SIMDE_POLY8_C(   38),  SIMDE_POLY8_C(  152),  SIMDE_POLY8_C(  143),
         SIMDE_POLY8_C(  248),  SIMDE_POLY8_C(   39),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(  167),
         SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(   73),  SIMDE_POLY8_C(  248),  SIMDE_POLY8_C(  115),
         SIMDE_POLY8_C(   51),  SIMDE_POLY8_C(  113),  SIMDE_POLY8_C(  225),  SIMDE_POLY8_C(  199),
         SIMDE_POLY8_C(   10),  SIMDE_POLY8_C(   31),  SIMDE_POLY8_C(  163),  SIMDE_POLY8_C(  126),
         SIMDE_POLY8_C(   67),  SIMDE_POLY8_C(  175),  SIMDE_POLY8_C(  188),  SIMDE_POLY8_C(  115),
         SIMDE_POLY8_C(   27),  SIMDE_POLY8_C(  242),  SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(    9),
         SIMDE_POLY8_C(    4),    SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(   77),
         SIMDE_POLY8_C(   34),  SIMDE_POLY8_C(   72),  SIMDE_POLY8_C(  166),  SIMDE_POLY8_C(  234),
         SIMDE_POLY8_C(  141),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(   64),  SIMDE_POLY8_C(    0),
         SIMDE_POLY8_C(   56),  SIMDE_POLY8_C(  159),  SIMDE_POLY8_C(  160),  SIMDE_POLY8_C(  114),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  156),    SIMDE_POLY8_C(UINT8_MAX) } },
  { { {  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  128),  SIMDE_POLY8_C(   25),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(   95),  SIMDE_POLY8_C(   74),
         SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(  116),  SIMDE_POLY8_C(   59),
         SIMDE_POLY8_C(  101),  SIMDE_POLY8_C(  187),  SIMDE_POLY8_C(   11),  SIMDE_POLY8_C(   32)  },
      {  SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(   87),  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  161),
         SIMDE_POLY8_C(  182),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(   10),  SIMDE_POLY8_C(  164),
         SIMDE_POLY8_C(  180),  SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  170),
         SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(   46)  },
      {  SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(   84),  SIMDE_POLY8_C(  237),  SIMDE_POLY8_C(   56),
         SIMDE_POLY8_C(  235),  SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(  158),
         SIMDE_POLY8_C(    9),  SIMDE_POLY8_C(  253),  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(   86),
         SIMDE_POLY8_C(   55),  SIMDE_POLY8_C(  150),  SIMDE_POLY8_C(  165),  SIMDE_POLY8_C(   49)  } },
      {  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  128),  SIMDE_POLY8_C(   25),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(   35),  SIMDE_POLY8_C(  143),  SIMDE_POLY8_C(   95),  SIMDE_POLY8_C(   74),
         SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(  116),  SIMDE_POLY8_C(   59),
         SIMDE_POLY8_C(  101),  SIMDE_POLY8_C(  187),  SIMDE_POLY8_C(   11),  SIMDE_POLY8_C(   32),
         SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(   87),  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  161),
         SIMDE_POLY8_C(  182),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(   10),  SIMDE_POLY8_C(  164),
         SIMDE_POLY8_C(  180),  SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  247),  SIMDE_POLY8_C(  170),
         SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(    4),  SIMDE_POLY8_C(   30),  SIMDE_POLY8_C(   46),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(   84),  SIMDE_POLY8_C(  237),  SIMDE_POLY8_C(   56),
         SIMDE_POLY8_C(  235),  SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(  124),  SIMDE_POLY8_C(  158),
         SIMDE_POLY8_C(    9),  SIMDE_POLY8_C(  253),  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(   86),
         SIMDE_POLY8_C(   55),  SIMDE_POLY8_C(  150),  SIMDE_POLY8_C(  165),  SIMDE_POLY8_C(   49) } },
  { { {  SIMDE_POLY8_C(  197),  SIMDE_POLY8_C(  151),  SIMDE_POLY8_C(  249),  SIMDE_POLY8_C(  136),
         SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(  102),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(   81),
         SIMDE_POLY8_C(   79),  SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(  174),  SIMDE_POLY8_C(   39),
         SIMDE_POLY8_C(   51),  SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(   79)  },
      {  SIMDE_POLY8_C(  229),  SIMDE_POLY8_C(  253),  SIMDE_POLY8_C(  223),  SIMDE_POLY8_C(  124),
         SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  116),
         SIMDE_POLY8_C(   27),  SIMDE_POLY8_C(  109),  SIMDE_POLY8_C(  188),  SIMDE_POLY8_C(   24),
         SIMDE_POLY8_C(  213),    SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(   95),  SIMDE_POLY8_C(  218)  },
      {  SIMDE_POLY8_C(  102),  SIMDE_POLY8_C(  116),  SIMDE_POLY8_C(  111),  SIMDE_POLY8_C(  104),
         SIMDE_POLY8_C(  102),  SIMDE_POLY8_C(  216),  SIMDE_POLY8_C(  246),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   94),  SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  244),
         SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   25),  SIMDE_POLY8_C(   40)  } },
      {  SIMDE_POLY8_C(  197),  SIMDE_POLY8_C(  151),  SIMDE_POLY8_C(  249),  SIMDE_POLY8_C(  136),
         SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(  102),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(   81),
         SIMDE_POLY8_C(   79),  SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(  174),  SIMDE_POLY8_C(   39),
         SIMDE_POLY8_C(   51),  SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   99),  SIMDE_POLY8_C(   79),
         SIMDE_POLY8_C(  229),  SIMDE_POLY8_C(  253),  SIMDE_POLY8_C(  223),  SIMDE_POLY8_C(  124),
         SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(   28),  SIMDE_POLY8_C(  103),  SIMDE_POLY8_C(  116),
         SIMDE_POLY8_C(   27),  SIMDE_POLY8_C(  109),  SIMDE_POLY8_C(  188),  SIMDE_POLY8_C(   24),
         SIMDE_POLY8_C(  213),    SIMDE_POLY8_C(UINT8_MAX),  SIMDE_POLY8_C(   95),  SIMDE_POLY8_C(  218),
         SIMDE_POLY8_C(  102),  SIMDE_POLY8_C(  116),  SIMDE_POLY8_C(  111),  SIMDE_POLY8_C(  104),
         SIMDE_POLY8_C(  102),  SIMDE_POLY8_C(  216),  SIMDE_POLY8_C(  246),  SIMDE_POLY8_C(  231),
         SIMDE_POLY8_C(  161),  SIMDE_POLY8_C(   94),  SIMDE_POLY8_C(  100),  SIMDE_POLY8_C(  244),
         SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(  135),  SIMDE_POLY8_C(   25),  SIMDE_POLY8_C(   40) } },
  { { {  SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(  109),  SIMDE_POLY8_C(  147),  SIMDE_POLY8_C(  120),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  106),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   30),
         SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  178),  SIMDE_POLY8_C(  179),
         SIMDE_POLY8_C(  248),  SIMDE_POLY8_C(  158),  SIMDE_POLY8_C(  197),  SIMDE_POLY8_C(  254)  },
      {  SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(   11),  SIMDE_POLY8_C(  234),
         SIMDE_POLY8_C(   77),  SIMDE_POLY8_C(   34),  SIMDE_POLY8_C(  192),  SIMDE_POLY8_C(  243),
         SIMDE_POLY8_C(  183),  SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(    2),  SIMDE_POLY8_C(  127),
         SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(  203)  },
      {  SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(  209),  SIMDE_POLY8_C(   86),    SIMDE_POLY8_C(UINT8_MAX),
         SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(  167),  SIMDE_POLY8_C(  251),  SIMDE_POLY8_C(   19),
         SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(   47),  SIMDE_POLY8_C(   53),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(   47),  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(  241)  } },
      {  SIMDE_POLY8_C(  231),  SIMDE_POLY8_C(  109),  SIMDE_POLY8_C(  147),  SIMDE_POLY8_C(  120),
         SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  106),  SIMDE_POLY8_C(   75),  SIMDE_POLY8_C(   30),
         SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(  178),  SIMDE_POLY8_C(  179),
         SIMDE_POLY8_C(  248),  SIMDE_POLY8_C(  158),  SIMDE_POLY8_C(  197),  SIMDE_POLY8_C(  254),
         SIMDE_POLY8_C(  121),  SIMDE_POLY8_C(   42),  SIMDE_POLY8_C(   11),  SIMDE_POLY8_C(  234),
         SIMDE_POLY8_C(   77),  SIMDE_POLY8_C(   34),  SIMDE_POLY8_C(  192),  SIMDE_POLY8_C(  243),
         SIMDE_POLY8_C(  183),  SIMDE_POLY8_C(  144),  SIMDE_POLY8_C(    2),  SIMDE_POLY8_C(  127),
         SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(   49),  SIMDE_POLY8_C(  207),  SIMDE_POLY8_C(  203),
         SIMDE_POLY8_C(  222),  SIMDE_POLY8_C(  209),  SIMDE_POLY8_C(   86),    SIMDE_POLY8_C(UINT8_MAX),
         SIMDE_POLY8_C(   20),  SIMDE_POLY8_C(  167),  SIMDE_POLY8_C(  251),  SIMDE_POLY8_C(   19),
         SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(   47),  SIMDE_POLY8_C(   53),  SIMDE_POLY8_C(   98),
         SIMDE_POLY8_C(   47),  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(  241) } },
  { { {  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(    2),  SIMDE_POLY8_C(   69),  SIMDE_POLY8_C(  114),
         SIMDE_POLY8_C(  193),  SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(  138),  SIMDE_POLY8_C(  166),
         SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  214),
         SIMDE_POLY8_C(  215),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(  233)  },
      {  SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  238),  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(  209),
         SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(   36),  SIMDE_POLY8_C(  214),
         SIMDE_POLY8_C(  122),  SIMDE_POLY8_C(  148),  SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(  106),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(   94),  SIMDE_POLY8_C(  123)  },
      {  SIMDE_POLY8_C(  174),  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(  120),  SIMDE_POLY8_C(  232),
         SIMDE_POLY8_C(  142),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(  162),  SIMDE_POLY8_C(  251),
         SIMDE_POLY8_C(   67),  SIMDE_POLY8_C(  199),  SIMDE_POLY8_C(  174),  SIMDE_POLY8_C(   17),
         SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(  166),  SIMDE_POLY8_C(   10)  } },
      {  SIMDE_POLY8_C(  254),  SIMDE_POLY8_C(    2),  SIMDE_POLY8_C(   69),  SIMDE_POLY8_C(  114),
         SIMDE_POLY8_C(  193),  SIMDE_POLY8_C(  177),  SIMDE_POLY8_C(  138),  SIMDE_POLY8_C(  166),
         SIMDE_POLY8_C(  133),  SIMDE_POLY8_C(   48),  SIMDE_POLY8_C(  184),  SIMDE_POLY8_C(  214),
         SIMDE_POLY8_C(  215),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(  233),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  238),  SIMDE_POLY8_C(  186),  SIMDE_POLY8_C(  209),
         SIMDE_POLY8_C(    8),  SIMDE_POLY8_C(  168),  SIMDE_POLY8_C(   36),  SIMDE_POLY8_C(  214),
         SIMDE_POLY8_C(  122),  SIMDE_POLY8_C(  148),  SIMDE_POLY8_C(   33),  SIMDE_POLY8_C(  106),
         SIMDE_POLY8_C(  105),  SIMDE_POLY8_C(  205),  SIMDE_POLY8_C(   94),  SIMDE_POLY8_C(  123),
         SIMDE_POLY8_C(  174),  SIMDE_POLY8_C(   21),  SIMDE_POLY8_C(  120),  SIMDE_POLY8_C(  232),
         SIMDE_POLY8_C(  142),  SIMDE_POLY8_C(  224),  SIMDE_POLY8_C(  162),  SIMDE_POLY8_C(  251),
         SIMDE_POLY8_C(   67),  SIMDE_POLY8_C(  199),  SIMDE_POLY8_C(  174),  SIMDE_POLY8_C(   17),
         SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(  179),  SIMDE_POLY8_C(  166),  SIMDE_POLY8_C(   10) } },
  { { {  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  236),  SIMDE_POLY8_C(  176),  SIMDE_POLY8_C(  247),
         SIMDE_POLY8_C(  104),  SIMDE_POLY8_C(   22),  SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  237),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(  159),
         SIMDE_POLY8_C(  125),  SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(   74)  },
      {  SIMDE_POLY8_C(  175),  SIMDE_POLY8_C(   29),  SIMDE_POLY8_C(   44),  SIMDE_POLY8_C(   24),
         SIMDE_POLY8_C(  233),  SIMDE_POLY8_C(  183),  SIMDE_POLY8_C(  141),  SIMDE_POLY8_C(   62),
         SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(  244),  SIMDE_POLY8_C(  125),  SIMDE_POLY8_C(  177),
         SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(  111),  SIMDE_POLY8_C(  160),  SIMDE_POLY8_C(   39)  },
      {  SIMDE_POLY8_C(  226),  SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(   39),  SIMDE_POLY8_C(  185),
         SIMDE_POLY8_C(  252),  SIMDE_POLY8_C(  218),  SIMDE_POLY8_C(   13),  SIMDE_POLY8_C(  243),
         SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(  251),  SIMDE_POLY8_C(  123),  SIMDE_POLY8_C(  198),
         SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(  145),  SIMDE_POLY8_C(  154)  } },
      {  SIMDE_POLY8_C(  134),  SIMDE_POLY8_C(  236),  SIMDE_POLY8_C(  176),  SIMDE_POLY8_C(  247),
         SIMDE_POLY8_C(  104),  SIMDE_POLY8_C(   22),  SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  237),
         SIMDE_POLY8_C(  164),  SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(  181),  SIMDE_POLY8_C(  159),
         SIMDE_POLY8_C(  125),  SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(   41),  SIMDE_POLY8_C(   74),
         SIMDE_POLY8_C(  175),  SIMDE_POLY8_C(   29),  SIMDE_POLY8_C(   44),  SIMDE_POLY8_C(   24),
         SIMDE_POLY8_C(  233),  SIMDE_POLY8_C(  183),  SIMDE_POLY8_C(  141),  SIMDE_POLY8_C(   62),
         SIMDE_POLY8_C(  171),  SIMDE_POLY8_C(  244),  SIMDE_POLY8_C(  125),  SIMDE_POLY8_C(  177),
         SIMDE_POLY8_C(  210),  SIMDE_POLY8_C(  111),  SIMDE_POLY8_C(  160),  SIMDE_POLY8_C(   39),
         SIMDE_POLY8_C(  226),  SIMDE_POLY8_C(  126),  SIMDE_POLY8_C(   39),  SIMDE_POLY8_C(  185),
         SIMDE_POLY8_C(  252),  SIMDE_POLY8_C(  218),  SIMDE_POLY8_C(   13),  SIMDE_POLY8_C(  243),
         SIMDE_POLY8_C(  189),  SIMDE_POLY8_C(  251),  SIMDE_POLY8_C(  123),  SIMDE_POLY8_C(  198),
         SIMDE_POLY8_C(  241),  SIMDE_POLY8_C(    7),  SIMDE_POLY8_C(  145),  SIMDE_POLY8_C(  154) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN_TO_16 simde_poly8x16x3_t val = {{
        simde_vld1q_p8(test_vec[i].val[0]),
        simde_vld1q_p8(test_vec[i].val[1]),
        simde_vld1q_p8(test_vec[i].val[2]),
    }};
    SIMDE_ALIGN_TO_16 simde_poly8_t r_[48];
    simde_vst1q_p8_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly8x3_t val[3] = simde_test_arm_neon_random_p8x3();
    simde_poly8x48_t r = simde_vst1q_p8_x3(val[3]);

    simde_test_arm_neon_write_p8x3(2, val[3], SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p8x48(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_p16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_TO_16 simde_poly16_t val[3][8];
    SIMDE_ALIGN_TO_16 simde_poly16_t r[24];
  } test_vec[] = {
  { { {  SIMDE_POLY16_C(   21107),  SIMDE_POLY16_C(    4607),  SIMDE_POLY16_C(   64052),  SIMDE_POLY16_C(    5779),
         SIMDE_POLY16_C(   43904),  SIMDE_POLY16_C(    7898),  SIMDE_POLY16_C(   55020),  SIMDE_POLY16_C(   28189)  },
      {  SIMDE_POLY16_C(   40116),  SIMDE_POLY16_C(   37209),  SIMDE_POLY16_C(   11361),  SIMDE_POLY16_C(   35424),
         SIMDE_POLY16_C(   40362),  SIMDE_POLY16_C(   49050),  SIMDE_POLY16_C(   51285),  SIMDE_POLY16_C(   48707)  },
      {  SIMDE_POLY16_C(   47101),  SIMDE_POLY16_C(   59817),  SIMDE_POLY16_C(    2153),  SIMDE_POLY16_C(   14167),
         SIMDE_POLY16_C(    4774),  SIMDE_POLY16_C(   42900),  SIMDE_POLY16_C(   45188),  SIMDE_POLY16_C(   40585)  } },
      {  SIMDE_POLY16_C(   21107),  SIMDE_POLY16_C(    4607),  SIMDE_POLY16_C(   64052),  SIMDE_POLY16_C(    5779),
         SIMDE_POLY16_C(   43904),  SIMDE_POLY16_C(    7898),  SIMDE_POLY16_C(   55020),  SIMDE_POLY16_C(   28189),
         SIMDE_POLY16_C(   40116),  SIMDE_POLY16_C(   37209),  SIMDE_POLY16_C(   11361),  SIMDE_POLY16_C(   35424),
         SIMDE_POLY16_C(   40362),  SIMDE_POLY16_C(   49050),  SIMDE_POLY16_C(   51285),  SIMDE_POLY16_C(   48707),
         SIMDE_POLY16_C(   47101),  SIMDE_POLY16_C(   59817),  SIMDE_POLY16_C(    2153),  SIMDE_POLY16_C(   14167),
         SIMDE_POLY16_C(    4774),  SIMDE_POLY16_C(   42900),  SIMDE_POLY16_C(   45188),  SIMDE_POLY16_C(   40585) } },
  { { {  SIMDE_POLY16_C(   14152),  SIMDE_POLY16_C(   34305),  SIMDE_POLY16_C(     305),  SIMDE_POLY16_C(   12831),
         SIMDE_POLY16_C(   40356),  SIMDE_POLY16_C(    9040),  SIMDE_POLY16_C(   10170),  SIMDE_POLY16_C(   37368)  },
      {  SIMDE_POLY16_C(   26140),  SIMDE_POLY16_C(   39804),  SIMDE_POLY16_C(   20162),  SIMDE_POLY16_C(   19251),
         SIMDE_POLY16_C(   27789),  SIMDE_POLY16_C(   20223),  SIMDE_POLY16_C(   10903),  SIMDE_POLY16_C(   22983)  },
      {  SIMDE_POLY16_C(    6418),  SIMDE_POLY16_C(   25641),  SIMDE_POLY16_C(   55893),  SIMDE_POLY16_C(   52768),
         SIMDE_POLY16_C(   17266),  SIMDE_POLY16_C(   41226),  SIMDE_POLY16_C(   32867),  SIMDE_POLY16_C(   53078)  } },
      {  SIMDE_POLY16_C(   14152),  SIMDE_POLY16_C(   34305),  SIMDE_POLY16_C(     305),  SIMDE_POLY16_C(   12831),
         SIMDE_POLY16_C(   40356),  SIMDE_POLY16_C(    9040),  SIMDE_POLY16_C(   10170),  SIMDE_POLY16_C(   37368),
         SIMDE_POLY16_C(   26140),  SIMDE_POLY16_C(   39804),  SIMDE_POLY16_C(   20162),  SIMDE_POLY16_C(   19251),
         SIMDE_POLY16_C(   27789),  SIMDE_POLY16_C(   20223),  SIMDE_POLY16_C(   10903),  SIMDE_POLY16_C(   22983),
         SIMDE_POLY16_C(    6418),  SIMDE_POLY16_C(   25641),  SIMDE_POLY16_C(   55893),  SIMDE_POLY16_C(   52768),
         SIMDE_POLY16_C(   17266),  SIMDE_POLY16_C(   41226),  SIMDE_POLY16_C(   32867),  SIMDE_POLY16_C(   53078) } },
  { { {  SIMDE_POLY16_C(   58524),  SIMDE_POLY16_C(    8858),  SIMDE_POLY16_C(   11112),  SIMDE_POLY16_C(   12712),
         SIMDE_POLY16_C(    2227),  SIMDE_POLY16_C(    9913),  SIMDE_POLY16_C(   48319),  SIMDE_POLY16_C(   14486)  },
      {  SIMDE_POLY16_C(   51875),  SIMDE_POLY16_C(    3020),  SIMDE_POLY16_C(   61098),  SIMDE_POLY16_C(   56639),
         SIMDE_POLY16_C(   23878),  SIMDE_POLY16_C(   13605),  SIMDE_POLY16_C(   65325),  SIMDE_POLY16_C(   42066)  },
      {  SIMDE_POLY16_C(   47837),  SIMDE_POLY16_C(   31228),  SIMDE_POLY16_C(   42856),  SIMDE_POLY16_C(   40395),
         SIMDE_POLY16_C(   12878),  SIMDE_POLY16_C(   26606),  SIMDE_POLY16_C(    8609),  SIMDE_POLY16_C(    9872)  } },
      {  SIMDE_POLY16_C(   58524),  SIMDE_POLY16_C(    8858),  SIMDE_POLY16_C(   11112),  SIMDE_POLY16_C(   12712),
         SIMDE_POLY16_C(    2227),  SIMDE_POLY16_C(    9913),  SIMDE_POLY16_C(   48319),  SIMDE_POLY16_C(   14486),
         SIMDE_POLY16_C(   51875),  SIMDE_POLY16_C(    3020),  SIMDE_POLY16_C(   61098),  SIMDE_POLY16_C(   56639),
         SIMDE_POLY16_C(   23878),  SIMDE_POLY16_C(   13605),  SIMDE_POLY16_C(   65325),  SIMDE_POLY16_C(   42066),
         SIMDE_POLY16_C(   47837),  SIMDE_POLY16_C(   31228),  SIMDE_POLY16_C(   42856),  SIMDE_POLY16_C(   40395),
         SIMDE_POLY16_C(   12878),  SIMDE_POLY16_C(   26606),  SIMDE_POLY16_C(    8609),  SIMDE_POLY16_C(    9872) } },
  { { {  SIMDE_POLY16_C(    7641),  SIMDE_POLY16_C(   54951),  SIMDE_POLY16_C(    6287),  SIMDE_POLY16_C(    8390),
         SIMDE_POLY16_C(   19971),  SIMDE_POLY16_C(   25694),  SIMDE_POLY16_C(   21498),  SIMDE_POLY16_C(   45907)  },
      {  SIMDE_POLY16_C(   62093),  SIMDE_POLY16_C(   38079),  SIMDE_POLY16_C(   42815),  SIMDE_POLY16_C(   63441),
         SIMDE_POLY16_C(   60690),  SIMDE_POLY16_C(   62102),  SIMDE_POLY16_C(   49961),  SIMDE_POLY16_C(   57820)  },
      {  SIMDE_POLY16_C(   29466),  SIMDE_POLY16_C(   30046),  SIMDE_POLY16_C(   42417),  SIMDE_POLY16_C(   19664),
         SIMDE_POLY16_C(    5041),  SIMDE_POLY16_C(    1326),  SIMDE_POLY16_C(   47311),  SIMDE_POLY16_C(   12857)  } },
      {  SIMDE_POLY16_C(    7641),  SIMDE_POLY16_C(   54951),  SIMDE_POLY16_C(    6287),  SIMDE_POLY16_C(    8390),
         SIMDE_POLY16_C(   19971),  SIMDE_POLY16_C(   25694),  SIMDE_POLY16_C(   21498),  SIMDE_POLY16_C(   45907),
         SIMDE_POLY16_C(   62093),  SIMDE_POLY16_C(   38079),  SIMDE_POLY16_C(   42815),  SIMDE_POLY16_C(   63441),
         SIMDE_POLY16_C(   60690),  SIMDE_POLY16_C(   62102),  SIMDE_POLY16_C(   49961),  SIMDE_POLY16_C(   57820),
         SIMDE_POLY16_C(   29466),  SIMDE_POLY16_C(   30046),  SIMDE_POLY16_C(   42417),  SIMDE_POLY16_C(   19664),
         SIMDE_POLY16_C(    5041),  SIMDE_POLY16_C(    1326),  SIMDE_POLY16_C(   47311),  SIMDE_POLY16_C(   12857) } },
  { { {  SIMDE_POLY16_C(    7164),  SIMDE_POLY16_C(   62008),  SIMDE_POLY16_C(   52693),  SIMDE_POLY16_C(   35160),
         SIMDE_POLY16_C(     239),  SIMDE_POLY16_C(   45084),  SIMDE_POLY16_C(   27658),  SIMDE_POLY16_C(   22299)  },
      {  SIMDE_POLY16_C(    2717),  SIMDE_POLY16_C(    4377),  SIMDE_POLY16_C(   13917),  SIMDE_POLY16_C(    8964),
         SIMDE_POLY16_C(   64589),  SIMDE_POLY16_C(    4904),  SIMDE_POLY16_C(   51060),  SIMDE_POLY16_C(   26907)  },
      {  SIMDE_POLY16_C(   58329),  SIMDE_POLY16_C(   12820),  SIMDE_POLY16_C(   58023),  SIMDE_POLY16_C(    4066),
         SIMDE_POLY16_C(   53075),  SIMDE_POLY16_C(   13473),  SIMDE_POLY16_C(   45896),  SIMDE_POLY16_C(   56630)  } },
      {  SIMDE_POLY16_C(    7164),  SIMDE_POLY16_C(   62008),  SIMDE_POLY16_C(   52693),  SIMDE_POLY16_C(   35160),
         SIMDE_POLY16_C(     239),  SIMDE_POLY16_C(   45084),  SIMDE_POLY16_C(   27658),  SIMDE_POLY16_C(   22299),
         SIMDE_POLY16_C(    2717),  SIMDE_POLY16_C(    4377),  SIMDE_POLY16_C(   13917),  SIMDE_POLY16_C(    8964),
         SIMDE_POLY16_C(   64589),  SIMDE_POLY16_C(    4904),  SIMDE_POLY16_C(   51060),  SIMDE_POLY16_C(   26907),
         SIMDE_POLY16_C(   58329),  SIMDE_POLY16_C(   12820),  SIMDE_POLY16_C(   58023),  SIMDE_POLY16_C(    4066),
         SIMDE_POLY16_C(   53075),  SIMDE_POLY16_C(   13473),  SIMDE_POLY16_C(   45896),  SIMDE_POLY16_C(   56630) } },
  { { {  SIMDE_POLY16_C(   20763),  SIMDE_POLY16_C(   62556),  SIMDE_POLY16_C(   17397),  SIMDE_POLY16_C(   56339),
         SIMDE_POLY16_C(   25410),  SIMDE_POLY16_C(   24026),  SIMDE_POLY16_C(   58131),  SIMDE_POLY16_C(    1166)  },
      {  SIMDE_POLY16_C(   51072),  SIMDE_POLY16_C(     993),  SIMDE_POLY16_C(   44396),  SIMDE_POLY16_C(   64074),
         SIMDE_POLY16_C(   27949),  SIMDE_POLY16_C(   18016),  SIMDE_POLY16_C(   53802),  SIMDE_POLY16_C(   54090)  },
      {  SIMDE_POLY16_C(   11063),  SIMDE_POLY16_C(   62388),  SIMDE_POLY16_C(   41751),  SIMDE_POLY16_C(   22926),
         SIMDE_POLY16_C(   60980),  SIMDE_POLY16_C(   11707),  SIMDE_POLY16_C(    9537),  SIMDE_POLY16_C(   48745)  } },
      {  SIMDE_POLY16_C(   20763),  SIMDE_POLY16_C(   62556),  SIMDE_POLY16_C(   17397),  SIMDE_POLY16_C(   56339),
         SIMDE_POLY16_C(   25410),  SIMDE_POLY16_C(   24026),  SIMDE_POLY16_C(   58131),  SIMDE_POLY16_C(    1166),
         SIMDE_POLY16_C(   51072),  SIMDE_POLY16_C(     993),  SIMDE_POLY16_C(   44396),  SIMDE_POLY16_C(   64074),
         SIMDE_POLY16_C(   27949),  SIMDE_POLY16_C(   18016),  SIMDE_POLY16_C(   53802),  SIMDE_POLY16_C(   54090),
         SIMDE_POLY16_C(   11063),  SIMDE_POLY16_C(   62388),  SIMDE_POLY16_C(   41751),  SIMDE_POLY16_C(   22926),
         SIMDE_POLY16_C(   60980),  SIMDE_POLY16_C(   11707),  SIMDE_POLY16_C(    9537),  SIMDE_POLY16_C(   48745) } },
  { { {  SIMDE_POLY16_C(   31570),  SIMDE_POLY16_C(   18320),  SIMDE_POLY16_C(   12801),  SIMDE_POLY16_C(   15868),
         SIMDE_POLY16_C(   16770),  SIMDE_POLY16_C(   12613),  SIMDE_POLY16_C(     677),  SIMDE_POLY16_C(   36235)  },
      {  SIMDE_POLY16_C(    7166),  SIMDE_POLY16_C(   33512),  SIMDE_POLY16_C(   13279),  SIMDE_POLY16_C(   51433),
         SIMDE_POLY16_C(   19681),  SIMDE_POLY16_C(   20820),  SIMDE_POLY16_C(    7451),  SIMDE_POLY16_C(   59438)  },
      {  SIMDE_POLY16_C(   47651),  SIMDE_POLY16_C(   22915),  SIMDE_POLY16_C(   34492),  SIMDE_POLY16_C(   56145),
         SIMDE_POLY16_C(    2682),  SIMDE_POLY16_C(   45847),  SIMDE_POLY16_C(   28516),  SIMDE_POLY16_C(   52181)  } },
      {  SIMDE_POLY16_C(   31570),  SIMDE_POLY16_C(   18320),  SIMDE_POLY16_C(   12801),  SIMDE_POLY16_C(   15868),
         SIMDE_POLY16_C(   16770),  SIMDE_POLY16_C(   12613),  SIMDE_POLY16_C(     677),  SIMDE_POLY16_C(   36235),
         SIMDE_POLY16_C(    7166),  SIMDE_POLY16_C(   33512),  SIMDE_POLY16_C(   13279),  SIMDE_POLY16_C(   51433),
         SIMDE_POLY16_C(   19681),  SIMDE_POLY16_C(   20820),  SIMDE_POLY16_C(    7451),  SIMDE_POLY16_C(   59438),
         SIMDE_POLY16_C(   47651),  SIMDE_POLY16_C(   22915),  SIMDE_POLY16_C(   34492),  SIMDE_POLY16_C(   56145),
         SIMDE_POLY16_C(    2682),  SIMDE_POLY16_C(   45847),  SIMDE_POLY16_C(   28516),  SIMDE_POLY16_C(   52181) } },
  { { {  SIMDE_POLY16_C(   22334),  SIMDE_POLY16_C(   22525),  SIMDE_POLY16_C(   57022),  SIMDE_POLY16_C(   40133),
         SIMDE_POLY16_C(   14932),  SIMDE_POLY16_C(   29297),  SIMDE_POLY16_C(   55306),  SIMDE_POLY16_C(   56717)  },
      {  SIMDE_POLY16_C(   17749),  SIMDE_POLY16_C(     318),  SIMDE_POLY16_C(   11446),  SIMDE_POLY16_C(   15693),
         SIMDE_POLY16_C(   55790),  SIMDE_POLY16_C(   42094),  SIMDE_POLY16_C(   64924),  SIMDE_POLY16_C(     177)  },
      {  SIMDE_POLY16_C(   24308),  SIMDE_POLY16_C(    4839),  SIMDE_POLY16_C(   10364),  SIMDE_POLY16_C(    6946),
         SIMDE_POLY16_C(   22786),  SIMDE_POLY16_C(   23522),  SIMDE_POLY16_C(   39436),  SIMDE_POLY16_C(   60287)  } },
      {  SIMDE_POLY16_C(   22334),  SIMDE_POLY16_C(   22525),  SIMDE_POLY16_C(   57022),  SIMDE_POLY16_C(   40133),
         SIMDE_POLY16_C(   14932),  SIMDE_POLY16_C(   29297),  SIMDE_POLY16_C(   55306),  SIMDE_POLY16_C(   56717),
         SIMDE_POLY16_C(   17749),  SIMDE_POLY16_C(     318),  SIMDE_POLY16_C(   11446),  SIMDE_POLY16_C(   15693),
         SIMDE_POLY16_C(   55790),  SIMDE_POLY16_C(   42094),  SIMDE_POLY16_C(   64924),  SIMDE_POLY16_C(     177),
         SIMDE_POLY16_C(   24308),  SIMDE_POLY16_C(    4839),  SIMDE_POLY16_C(   10364),  SIMDE_POLY16_C(    6946),
         SIMDE_POLY16_C(   22786),  SIMDE_POLY16_C(   23522),  SIMDE_POLY16_C(   39436),  SIMDE_POLY16_C(   60287) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN_TO_16 simde_poly16x8x3_t val = {{
        simde_vld1q_p16(test_vec[i].val[0]),
        simde_vld1q_p16(test_vec[i].val[1]),
        simde_vld1q_p16(test_vec[i].val[2]),
    }};
    SIMDE_ALIGN_TO_16 simde_poly16_t r_[24];
    simde_vst1q_p16_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly16x3_t val[3] = simde_test_arm_neon_random_p16x3();
    simde_poly16x24_t r = simde_vst1q_p16_x3(val[3]);

    simde_test_arm_neon_write_p16x3(2, val[3], SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p16x24(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_p64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_poly64_t val[3][2];
    simde_poly64_t r[6];
  } test_vec[] = {
  { { {  SIMDE_POLY64_C( 7555284625339926989),  SIMDE_POLY64_C(17466467831333283314)  },
      {  SIMDE_POLY64_C( 8772387308643096643),  SIMDE_POLY64_C( 9525210396323671210)  },
      {  SIMDE_POLY64_C( 7164656628800658895),  SIMDE_POLY64_C(14688874909680887590)  } },
      {  SIMDE_POLY64_C( 7555284625339926989),  SIMDE_POLY64_C(17466467831333283314),  SIMDE_POLY64_C( 8772387308643096643),  SIMDE_POLY64_C( 9525210396323671210),  SIMDE_POLY64_C( 7164656628800658895),  SIMDE_POLY64_C(14688874909680887590) } },
  { { {  SIMDE_POLY64_C(  236701857996312676),  SIMDE_POLY64_C( 6831317607123371885)  },
      {  SIMDE_POLY64_C(15742465926030276710),  SIMDE_POLY64_C( 2589803878441594210)  },
      {  SIMDE_POLY64_C(12324403906753597038),  SIMDE_POLY64_C( 4740945125691882212)  } },
      {  SIMDE_POLY64_C(  236701857996312676),  SIMDE_POLY64_C( 6831317607123371885),  SIMDE_POLY64_C(15742465926030276710),  SIMDE_POLY64_C( 2589803878441594210),  SIMDE_POLY64_C(12324403906753597038),  SIMDE_POLY64_C( 4740945125691882212) } },
  { { {  SIMDE_POLY64_C(12512300594124074357),  SIMDE_POLY64_C( 1163586325543898222)  },
      {  SIMDE_POLY64_C(13503335155109545330),  SIMDE_POLY64_C(11808321761518126354)  },
      {  SIMDE_POLY64_C(13434621719993317645),  SIMDE_POLY64_C( 4748496777640087590)  } },
      {  SIMDE_POLY64_C(12512300594124074357),  SIMDE_POLY64_C( 1163586325543898222),  SIMDE_POLY64_C(13503335155109545330),  SIMDE_POLY64_C(11808321761518126354),  SIMDE_POLY64_C(13434621719993317645),  SIMDE_POLY64_C( 4748496777640087590) } },
  { { {  SIMDE_POLY64_C(17980574263139470838),  SIMDE_POLY64_C(15154347382840985671)  },
      {  SIMDE_POLY64_C( 2590733835098455343),  SIMDE_POLY64_C( 5128372592428232532)  },
      {  SIMDE_POLY64_C(15737158191058531464),  SIMDE_POLY64_C(16055173851335738164)  } },
      {  SIMDE_POLY64_C(17980574263139470838),  SIMDE_POLY64_C(15154347382840985671),  SIMDE_POLY64_C( 2590733835098455343),  SIMDE_POLY64_C( 5128372592428232532),  SIMDE_POLY64_C(15737158191058531464),  SIMDE_POLY64_C(16055173851335738164) } },
  { { {  SIMDE_POLY64_C(17326566926258713407),  SIMDE_POLY64_C( 1853337919224088484)  },
      {  SIMDE_POLY64_C(13596419169706848981),  SIMDE_POLY64_C(11786265449580301664)  },
      {  SIMDE_POLY64_C( 6612784333843145481),  SIMDE_POLY64_C( 1104387816993840563)  } },
      {  SIMDE_POLY64_C(17326566926258713407),  SIMDE_POLY64_C( 1853337919224088484),  SIMDE_POLY64_C(13596419169706848981),  SIMDE_POLY64_C(11786265449580301664),  SIMDE_POLY64_C( 6612784333843145481),  SIMDE_POLY64_C( 1104387816993840563) } },
  { { {  SIMDE_POLY64_C(16177403835656312777),  SIMDE_POLY64_C(16855596382578598147)  },
      {  SIMDE_POLY64_C( 7478715589016856295),  SIMDE_POLY64_C( 6407567708612819692)  },
      {  SIMDE_POLY64_C(14300582356565411734),  SIMDE_POLY64_C( 4241344443988637304)  } },
      {  SIMDE_POLY64_C(16177403835656312777),  SIMDE_POLY64_C(16855596382578598147),  SIMDE_POLY64_C( 7478715589016856295),  SIMDE_POLY64_C( 6407567708612819692),  SIMDE_POLY64_C(14300582356565411734),  SIMDE_POLY64_C( 4241344443988637304) } },
  { { {  SIMDE_POLY64_C(17026909229323956592),  SIMDE_POLY64_C( 9876515850322189464)  },
      {  SIMDE_POLY64_C( 8589309808143565937),  SIMDE_POLY64_C(  239316176215501799)  },
      {  SIMDE_POLY64_C( 3935995277380127149),  SIMDE_POLY64_C( 6710599645478040898)  } },
      {  SIMDE_POLY64_C(17026909229323956592),  SIMDE_POLY64_C( 9876515850322189464),  SIMDE_POLY64_C( 8589309808143565937),  SIMDE_POLY64_C(  239316176215501799),  SIMDE_POLY64_C( 3935995277380127149),  SIMDE_POLY64_C( 6710599645478040898) } },
  { { {  SIMDE_POLY64_C(10625963414496883587),  SIMDE_POLY64_C( 6583889364679806254)  },
      {  SIMDE_POLY64_C( 2221780634318079596),  SIMDE_POLY64_C( 2483671931813354711)  },
      {  SIMDE_POLY64_C(12014651139460929299),  SIMDE_POLY64_C(11511641119939002888)  } },
      {  SIMDE_POLY64_C(10625963414496883587),  SIMDE_POLY64_C( 6583889364679806254),  SIMDE_POLY64_C( 2221780634318079596),  SIMDE_POLY64_C( 2483671931813354711),  SIMDE_POLY64_C(12014651139460929299),  SIMDE_POLY64_C(11511641119939002888) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly64x2x3_t val = {{
        simde_vld1q_p64(test_vec[i].val[0]),
        simde_vld1q_p64(test_vec[i].val[1]),
        simde_vld1q_p64(test_vec[i].val[2]),
    }};
    simde_poly64_t r_[6];
    simde_vst1q_p64_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_poly64x3_t val[3] = simde_test_arm_neon_random_p64x3();
    simde_poly64x6_t r = simde_vst1q_p64_x3(val[3]);

    simde_test_arm_neon_write_p64x3(2, val[3], SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_p64x6(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_bf16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_bfloat16 val[3][8];
    simde_bfloat16 r[24];
  } test_vec[] = {
  { { { SIMDE_BFLOAT16_VALUE( - 78.006), SIMDE_BFLOAT16_VALUE( - 86.214),  SIMDE_BFLOAT16_VALUE( 79.768), SIMDE_BFLOAT16_VALUE( - 58.640),
         SIMDE_BFLOAT16_VALUE( 95.290), SIMDE_BFLOAT16_VALUE( - 58.694), SIMDE_BFLOAT16_VALUE( - 66.494),  SIMDE_BFLOAT16_VALUE( 14.402)  },
      { SIMDE_BFLOAT16_VALUE( - 73.147),  SIMDE_BFLOAT16_VALUE( 86.011), SIMDE_BFLOAT16_VALUE( - 57.821),  SIMDE_BFLOAT16_VALUE( 39.575),
        SIMDE_BFLOAT16_VALUE( - 71.723), SIMDE_BFLOAT16_VALUE( - 56.950), SIMDE_BFLOAT16_VALUE( - 64.715),  SIMDE_BFLOAT16_VALUE( 57.900)  },
      {  SIMDE_BFLOAT16_VALUE( 61.685), SIMDE_BFLOAT16_VALUE( - 81.983),  SIMDE_BFLOAT16_VALUE( 15.196), SIMDE_BFLOAT16_VALUE( - 22.643),
         SIMDE_BFLOAT16_VALUE( 73.963),  SIMDE_BFLOAT16_VALUE( 69.945), SIMDE_BFLOAT16_VALUE( - 18.252),  SIMDE_BFLOAT16_VALUE(  6.208)  } },
      { SIMDE_BFLOAT16_VALUE( - 78.006), SIMDE_BFLOAT16_VALUE( - 86.214),  SIMDE_BFLOAT16_VALUE( 79.768), SIMDE_BFLOAT16_VALUE( - 58.640),
         SIMDE_BFLOAT16_VALUE( 95.290), SIMDE_BFLOAT16_VALUE( - 58.694), SIMDE_BFLOAT16_VALUE( - 66.494),  SIMDE_BFLOAT16_VALUE( 14.402),
        SIMDE_BFLOAT16_VALUE( - 73.147),  SIMDE_BFLOAT16_VALUE( 86.011), SIMDE_BFLOAT16_VALUE( - 57.821),  SIMDE_BFLOAT16_VALUE( 39.575),
        SIMDE_BFLOAT16_VALUE( - 71.723), SIMDE_BFLOAT16_VALUE( - 56.950), SIMDE_BFLOAT16_VALUE( - 64.715),  SIMDE_BFLOAT16_VALUE( 57.900),
         SIMDE_BFLOAT16_VALUE( 61.685), SIMDE_BFLOAT16_VALUE( - 81.983),  SIMDE_BFLOAT16_VALUE( 15.196), SIMDE_BFLOAT16_VALUE( - 22.643),
         SIMDE_BFLOAT16_VALUE( 73.963),  SIMDE_BFLOAT16_VALUE( 69.945), SIMDE_BFLOAT16_VALUE( - 18.252),  SIMDE_BFLOAT16_VALUE(  6.208) } },
  { { {  SIMDE_BFLOAT16_VALUE( 75.124),  SIMDE_BFLOAT16_VALUE( 63.765),  SIMDE_BFLOAT16_VALUE( 93.445), SIMDE_BFLOAT16_VALUE( -  2.808),
         SIMDE_BFLOAT16_VALUE( 21.150), SIMDE_BFLOAT16_VALUE( - 27.804),  SIMDE_BFLOAT16_VALUE( 96.600),  SIMDE_BFLOAT16_VALUE( 49.484)  },
      { SIMDE_BFLOAT16_VALUE( - 21.286),  SIMDE_BFLOAT16_VALUE(  6.385),  SIMDE_BFLOAT16_VALUE( 58.966), SIMDE_BFLOAT16_VALUE( - 25.964),
         SIMDE_BFLOAT16_VALUE( 81.303),  SIMDE_BFLOAT16_VALUE( 55.133),  SIMDE_BFLOAT16_VALUE( 59.277),  SIMDE_BFLOAT16_VALUE( 90.767)  },
      { SIMDE_BFLOAT16_VALUE( -  9.851), SIMDE_BFLOAT16_VALUE( - 51.010), SIMDE_BFLOAT16_VALUE( - 57.457),  SIMDE_BFLOAT16_VALUE( 76.293),
        SIMDE_BFLOAT16_VALUE( - 36.636),  SIMDE_BFLOAT16_VALUE( 71.898),  SIMDE_BFLOAT16_VALUE( 98.888), SIMDE_BFLOAT16_VALUE( - 38.156)  } },
      {  SIMDE_BFLOAT16_VALUE( 75.124),  SIMDE_BFLOAT16_VALUE( 63.765),  SIMDE_BFLOAT16_VALUE( 93.445), SIMDE_BFLOAT16_VALUE( -  2.808),
         SIMDE_BFLOAT16_VALUE( 21.150), SIMDE_BFLOAT16_VALUE( - 27.804),  SIMDE_BFLOAT16_VALUE( 96.600),  SIMDE_BFLOAT16_VALUE( 49.484),
        SIMDE_BFLOAT16_VALUE( - 21.286),  SIMDE_BFLOAT16_VALUE(  6.385),  SIMDE_BFLOAT16_VALUE( 58.966), SIMDE_BFLOAT16_VALUE( - 25.964),
         SIMDE_BFLOAT16_VALUE( 81.303),  SIMDE_BFLOAT16_VALUE( 55.133),  SIMDE_BFLOAT16_VALUE( 59.277),  SIMDE_BFLOAT16_VALUE( 90.767),
        SIMDE_BFLOAT16_VALUE( -  9.851), SIMDE_BFLOAT16_VALUE( - 51.010), SIMDE_BFLOAT16_VALUE( - 57.457),  SIMDE_BFLOAT16_VALUE( 76.293),
        SIMDE_BFLOAT16_VALUE( - 36.636),  SIMDE_BFLOAT16_VALUE( 71.898),  SIMDE_BFLOAT16_VALUE( 98.888), SIMDE_BFLOAT16_VALUE( - 38.156) } },
  { { {  SIMDE_BFLOAT16_VALUE( 26.535), SIMDE_BFLOAT16_VALUE( - 91.027), SIMDE_BFLOAT16_VALUE( - 79.934), SIMDE_BFLOAT16_VALUE( - 46.283),
        SIMDE_BFLOAT16_VALUE( - 50.743), SIMDE_BFLOAT16_VALUE( - 31.430), SIMDE_BFLOAT16_VALUE( - 40.474),  SIMDE_BFLOAT16_VALUE( 52.962)  },
      {  SIMDE_BFLOAT16_VALUE( 54.007), SIMDE_BFLOAT16_VALUE( - 51.316), SIMDE_BFLOAT16_VALUE( - 70.698),  SIMDE_BFLOAT16_VALUE( 59.510),
         SIMDE_BFLOAT16_VALUE( 60.522), SIMDE_BFLOAT16_VALUE( - 83.540),  SIMDE_BFLOAT16_VALUE( 72.171), SIMDE_BFLOAT16_VALUE( - 94.419)  },
      { SIMDE_BFLOAT16_VALUE( - 73.925), SIMDE_BFLOAT16_VALUE( - 73.200), SIMDE_BFLOAT16_VALUE( - 12.444),  SIMDE_BFLOAT16_VALUE( 72.493),
         SIMDE_BFLOAT16_VALUE( 27.042),  SIMDE_BFLOAT16_VALUE( 81.525), SIMDE_BFLOAT16_VALUE( - 92.143), SIMDE_BFLOAT16_VALUE( - 50.921)  } },
      {  SIMDE_BFLOAT16_VALUE( 26.535), SIMDE_BFLOAT16_VALUE( - 91.027), SIMDE_BFLOAT16_VALUE( - 79.934), SIMDE_BFLOAT16_VALUE( - 46.283),
        SIMDE_BFLOAT16_VALUE( - 50.743), SIMDE_BFLOAT16_VALUE( - 31.430), SIMDE_BFLOAT16_VALUE( - 40.474),  SIMDE_BFLOAT16_VALUE( 52.962),
         SIMDE_BFLOAT16_VALUE( 54.007), SIMDE_BFLOAT16_VALUE( - 51.316), SIMDE_BFLOAT16_VALUE( - 70.698),  SIMDE_BFLOAT16_VALUE( 59.510),
         SIMDE_BFLOAT16_VALUE( 60.522), SIMDE_BFLOAT16_VALUE( - 83.540),  SIMDE_BFLOAT16_VALUE( 72.171), SIMDE_BFLOAT16_VALUE( - 94.419),
        SIMDE_BFLOAT16_VALUE( - 73.925), SIMDE_BFLOAT16_VALUE( - 73.200), SIMDE_BFLOAT16_VALUE( - 12.444),  SIMDE_BFLOAT16_VALUE( 72.493),
         SIMDE_BFLOAT16_VALUE( 27.042),  SIMDE_BFLOAT16_VALUE( 81.525), SIMDE_BFLOAT16_VALUE( - 92.143), SIMDE_BFLOAT16_VALUE( - 50.921) } },
  { { { SIMDE_BFLOAT16_VALUE( - 45.682),  SIMDE_BFLOAT16_VALUE( 52.798), SIMDE_BFLOAT16_VALUE( - 80.990), SIMDE_BFLOAT16_VALUE( - 61.788),
         SIMDE_BFLOAT16_VALUE( 54.221),  SIMDE_BFLOAT16_VALUE( 99.819), SIMDE_BFLOAT16_VALUE( - 53.166),  SIMDE_BFLOAT16_VALUE( 62.212)  },
      { SIMDE_BFLOAT16_VALUE( - 26.140), SIMDE_BFLOAT16_VALUE( - 44.258), SIMDE_BFLOAT16_VALUE( - 63.797),  SIMDE_BFLOAT16_VALUE( 21.345),
         SIMDE_BFLOAT16_VALUE( 43.284),  SIMDE_BFLOAT16_VALUE( 49.659),  SIMDE_BFLOAT16_VALUE( 83.024), SIMDE_BFLOAT16_VALUE( - 93.541)  },
      { SIMDE_BFLOAT16_VALUE( - 41.983),  SIMDE_BFLOAT16_VALUE( 72.431), SIMDE_BFLOAT16_VALUE( - 72.624), SIMDE_BFLOAT16_VALUE( - 68.362),
        SIMDE_BFLOAT16_VALUE( -  3.439),  SIMDE_BFLOAT16_VALUE( 57.763),  SIMDE_BFLOAT16_VALUE( 53.732),  SIMDE_BFLOAT16_VALUE( 23.477)  } },
      { SIMDE_BFLOAT16_VALUE( - 45.682),  SIMDE_BFLOAT16_VALUE( 52.798), SIMDE_BFLOAT16_VALUE( - 80.990), SIMDE_BFLOAT16_VALUE( - 61.788),
         SIMDE_BFLOAT16_VALUE( 54.221),  SIMDE_BFLOAT16_VALUE( 99.819), SIMDE_BFLOAT16_VALUE( - 53.166),  SIMDE_BFLOAT16_VALUE( 62.212),
        SIMDE_BFLOAT16_VALUE( - 26.140), SIMDE_BFLOAT16_VALUE( - 44.258), SIMDE_BFLOAT16_VALUE( - 63.797),  SIMDE_BFLOAT16_VALUE( 21.345),
         SIMDE_BFLOAT16_VALUE( 43.284),  SIMDE_BFLOAT16_VALUE( 49.659),  SIMDE_BFLOAT16_VALUE( 83.024), SIMDE_BFLOAT16_VALUE( - 93.541),
        SIMDE_BFLOAT16_VALUE( - 41.983),  SIMDE_BFLOAT16_VALUE( 72.431), SIMDE_BFLOAT16_VALUE( - 72.624), SIMDE_BFLOAT16_VALUE( - 68.362),
        SIMDE_BFLOAT16_VALUE( -  3.439),  SIMDE_BFLOAT16_VALUE( 57.763),  SIMDE_BFLOAT16_VALUE( 53.732),  SIMDE_BFLOAT16_VALUE( 23.477) } },
  { { { SIMDE_BFLOAT16_VALUE( - 82.965), SIMDE_BFLOAT16_VALUE( - 70.111), SIMDE_BFLOAT16_VALUE( - 31.957),  SIMDE_BFLOAT16_VALUE( 61.018),
        SIMDE_BFLOAT16_VALUE( - 27.870),  SIMDE_BFLOAT16_VALUE( 71.621), SIMDE_BFLOAT16_VALUE( - 77.867), SIMDE_BFLOAT16_VALUE( - 30.557)  },
      {  SIMDE_BFLOAT16_VALUE( 58.953), SIMDE_BFLOAT16_VALUE( - 20.614), SIMDE_BFLOAT16_VALUE( - 60.571),  SIMDE_BFLOAT16_VALUE( 63.967),
        SIMDE_BFLOAT16_VALUE( - 12.960), SIMDE_BFLOAT16_VALUE( - 61.378), SIMDE_BFLOAT16_VALUE( - 20.681),  SIMDE_BFLOAT16_VALUE( 73.740)  },
      {  SIMDE_BFLOAT16_VALUE( 77.996),  SIMDE_BFLOAT16_VALUE(  4.822), SIMDE_BFLOAT16_VALUE( - 39.992),  SIMDE_BFLOAT16_VALUE( 50.289),
        SIMDE_BFLOAT16_VALUE( - 37.043), SIMDE_BFLOAT16_VALUE( - 89.635),  SIMDE_BFLOAT16_VALUE( 33.091), SIMDE_BFLOAT16_VALUE( - 39.668)  } },
      { SIMDE_BFLOAT16_VALUE( - 82.965), SIMDE_BFLOAT16_VALUE( - 70.111), SIMDE_BFLOAT16_VALUE( - 31.957),  SIMDE_BFLOAT16_VALUE( 61.018),
        SIMDE_BFLOAT16_VALUE( - 27.870),  SIMDE_BFLOAT16_VALUE( 71.621), SIMDE_BFLOAT16_VALUE( - 77.867), SIMDE_BFLOAT16_VALUE( - 30.557),
         SIMDE_BFLOAT16_VALUE( 58.953), SIMDE_BFLOAT16_VALUE( - 20.614), SIMDE_BFLOAT16_VALUE( - 60.571),  SIMDE_BFLOAT16_VALUE( 63.967),
        SIMDE_BFLOAT16_VALUE( - 12.960), SIMDE_BFLOAT16_VALUE( - 61.378), SIMDE_BFLOAT16_VALUE( - 20.681),  SIMDE_BFLOAT16_VALUE( 73.740),
         SIMDE_BFLOAT16_VALUE( 77.996),  SIMDE_BFLOAT16_VALUE(  4.822), SIMDE_BFLOAT16_VALUE( - 39.992),  SIMDE_BFLOAT16_VALUE( 50.289),
        SIMDE_BFLOAT16_VALUE( - 37.043), SIMDE_BFLOAT16_VALUE( - 89.635),  SIMDE_BFLOAT16_VALUE( 33.091), SIMDE_BFLOAT16_VALUE( - 39.668) } },
  { { {  SIMDE_BFLOAT16_VALUE(  3.917),  SIMDE_BFLOAT16_VALUE( 67.525), SIMDE_BFLOAT16_VALUE( - 40.144),  SIMDE_BFLOAT16_VALUE( 98.412),
        SIMDE_BFLOAT16_VALUE( -  5.628), SIMDE_BFLOAT16_VALUE( - 91.834),  SIMDE_BFLOAT16_VALUE( 66.132), SIMDE_BFLOAT16_VALUE( - 44.698)  },
      {  SIMDE_BFLOAT16_VALUE(  3.461), SIMDE_BFLOAT16_VALUE( -  1.903), SIMDE_BFLOAT16_VALUE( -  7.486), SIMDE_BFLOAT16_VALUE( -  5.095),
        SIMDE_BFLOAT16_VALUE( -  4.045),  SIMDE_BFLOAT16_VALUE( 76.155),  SIMDE_BFLOAT16_VALUE( 45.573), SIMDE_BFLOAT16_VALUE( - 17.845)  },
      { SIMDE_BFLOAT16_VALUE( - 69.007), SIMDE_BFLOAT16_VALUE( - 91.001),  SIMDE_BFLOAT16_VALUE( 47.281), SIMDE_BFLOAT16_VALUE( -  6.930),
        SIMDE_BFLOAT16_VALUE( - 31.826), SIMDE_BFLOAT16_VALUE( -  9.605), SIMDE_BFLOAT16_VALUE( -  8.507), SIMDE_BFLOAT16_VALUE( - 69.550)  } },
      {  SIMDE_BFLOAT16_VALUE(  3.917),  SIMDE_BFLOAT16_VALUE( 67.525), SIMDE_BFLOAT16_VALUE( - 40.144),  SIMDE_BFLOAT16_VALUE( 98.412),
        SIMDE_BFLOAT16_VALUE( -  5.628), SIMDE_BFLOAT16_VALUE( - 91.834),  SIMDE_BFLOAT16_VALUE( 66.132), SIMDE_BFLOAT16_VALUE( - 44.698),
         SIMDE_BFLOAT16_VALUE(  3.461), SIMDE_BFLOAT16_VALUE( -  1.903), SIMDE_BFLOAT16_VALUE( -  7.486), SIMDE_BFLOAT16_VALUE( -  5.095),
        SIMDE_BFLOAT16_VALUE( -  4.045),  SIMDE_BFLOAT16_VALUE( 76.155),  SIMDE_BFLOAT16_VALUE( 45.573), SIMDE_BFLOAT16_VALUE( - 17.845),
        SIMDE_BFLOAT16_VALUE( - 69.007), SIMDE_BFLOAT16_VALUE( - 91.001),  SIMDE_BFLOAT16_VALUE( 47.281), SIMDE_BFLOAT16_VALUE( -  6.930),
        SIMDE_BFLOAT16_VALUE( - 31.826), SIMDE_BFLOAT16_VALUE( -  9.605), SIMDE_BFLOAT16_VALUE( -  8.507), SIMDE_BFLOAT16_VALUE( - 69.550) } },
  { { { SIMDE_BFLOAT16_VALUE( - 83.740), SIMDE_BFLOAT16_VALUE( -  6.331), SIMDE_BFLOAT16_VALUE( - 89.045), SIMDE_BFLOAT16_VALUE( - 94.435),
        SIMDE_BFLOAT16_VALUE( - 65.111), SIMDE_BFLOAT16_VALUE( - 70.456),  SIMDE_BFLOAT16_VALUE( 11.289),  SIMDE_BFLOAT16_VALUE(  7.177)  },
      { SIMDE_BFLOAT16_VALUE( - 90.849), SIMDE_BFLOAT16_VALUE( - 95.953), SIMDE_BFLOAT16_VALUE( - 42.247),  SIMDE_BFLOAT16_VALUE( 14.309),
        SIMDE_BFLOAT16_VALUE( - 95.825), SIMDE_BFLOAT16_VALUE( - 22.270),  SIMDE_BFLOAT16_VALUE( 83.373), SIMDE_BFLOAT16_VALUE( - 79.802)  },
      { SIMDE_BFLOAT16_VALUE( - 22.035), SIMDE_BFLOAT16_VALUE( - 92.921),  SIMDE_BFLOAT16_VALUE( 43.906),  SIMDE_BFLOAT16_VALUE( 26.805),
         SIMDE_BFLOAT16_VALUE( 51.738), SIMDE_BFLOAT16_VALUE( - 42.852),  SIMDE_BFLOAT16_VALUE(  5.828),  SIMDE_BFLOAT16_VALUE( 44.079)  } },
      { SIMDE_BFLOAT16_VALUE( - 83.740), SIMDE_BFLOAT16_VALUE( -  6.331), SIMDE_BFLOAT16_VALUE( - 89.045), SIMDE_BFLOAT16_VALUE( - 94.435),
        SIMDE_BFLOAT16_VALUE( - 65.111), SIMDE_BFLOAT16_VALUE( - 70.456),  SIMDE_BFLOAT16_VALUE( 11.289),  SIMDE_BFLOAT16_VALUE(  7.177),
        SIMDE_BFLOAT16_VALUE( - 90.849), SIMDE_BFLOAT16_VALUE( - 95.953), SIMDE_BFLOAT16_VALUE( - 42.247),  SIMDE_BFLOAT16_VALUE( 14.309),
        SIMDE_BFLOAT16_VALUE( - 95.825), SIMDE_BFLOAT16_VALUE( - 22.270),  SIMDE_BFLOAT16_VALUE( 83.373), SIMDE_BFLOAT16_VALUE( - 79.802),
        SIMDE_BFLOAT16_VALUE( - 22.035), SIMDE_BFLOAT16_VALUE( - 92.921),  SIMDE_BFLOAT16_VALUE( 43.906),  SIMDE_BFLOAT16_VALUE( 26.805),
         SIMDE_BFLOAT16_VALUE( 51.738), SIMDE_BFLOAT16_VALUE( - 42.852),  SIMDE_BFLOAT16_VALUE(  5.828),  SIMDE_BFLOAT16_VALUE( 44.079) } },
  { { { SIMDE_BFLOAT16_VALUE( - 16.629),  SIMDE_BFLOAT16_VALUE( 51.044),  SIMDE_BFLOAT16_VALUE( 19.393),  SIMDE_BFLOAT16_VALUE( 55.131),
        SIMDE_BFLOAT16_VALUE( - 43.901),  SIMDE_BFLOAT16_VALUE( 70.204),  SIMDE_BFLOAT16_VALUE( 97.396),  SIMDE_BFLOAT16_VALUE( 81.774)  },
      { SIMDE_BFLOAT16_VALUE( - 65.652),  SIMDE_BFLOAT16_VALUE( 84.250), SIMDE_BFLOAT16_VALUE( - 73.434),  SIMDE_BFLOAT16_VALUE( 83.066),
         SIMDE_BFLOAT16_VALUE( 98.140),  SIMDE_BFLOAT16_VALUE( 10.456), SIMDE_BFLOAT16_VALUE( - 74.473),  SIMDE_BFLOAT16_VALUE( 36.574)  },
      { SIMDE_BFLOAT16_VALUE( - 30.153),  SIMDE_BFLOAT16_VALUE( 52.521), SIMDE_BFLOAT16_VALUE( - 21.877),  SIMDE_BFLOAT16_VALUE( 99.308),
        SIMDE_BFLOAT16_VALUE( - 78.712), SIMDE_BFLOAT16_VALUE( - 45.652), SIMDE_BFLOAT16_VALUE( - 23.870),  SIMDE_BFLOAT16_VALUE( 33.651)  } },
      { SIMDE_BFLOAT16_VALUE( - 16.629),  SIMDE_BFLOAT16_VALUE( 51.044),  SIMDE_BFLOAT16_VALUE( 19.393),  SIMDE_BFLOAT16_VALUE( 55.131),
        SIMDE_BFLOAT16_VALUE( - 43.901),  SIMDE_BFLOAT16_VALUE( 70.204),  SIMDE_BFLOAT16_VALUE( 97.396),  SIMDE_BFLOAT16_VALUE( 81.774),
        SIMDE_BFLOAT16_VALUE( - 65.652),  SIMDE_BFLOAT16_VALUE( 84.250), SIMDE_BFLOAT16_VALUE( - 73.434),  SIMDE_BFLOAT16_VALUE( 83.066),
         SIMDE_BFLOAT16_VALUE( 98.140),  SIMDE_BFLOAT16_VALUE( 10.456), SIMDE_BFLOAT16_VALUE( - 74.473),  SIMDE_BFLOAT16_VALUE( 36.574),
        SIMDE_BFLOAT16_VALUE( - 30.153),  SIMDE_BFLOAT16_VALUE( 52.521), SIMDE_BFLOAT16_VALUE( - 21.877),  SIMDE_BFLOAT16_VALUE( 99.308),
        SIMDE_BFLOAT16_VALUE( - 78.712), SIMDE_BFLOAT16_VALUE( - 45.652), SIMDE_BFLOAT16_VALUE( - 23.870),  SIMDE_BFLOAT16_VALUE( 33.651) } },
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_bfloat16x8x3_t val = {{
        simde_vld1q_bf16(test_vec[i].val[0]),
        simde_vld1q_bf16(test_vec[i].val[1]),
        simde_vld1q_bf16(test_vec[i].val[2]),
    }};
    simde_bfloat16 r_[24];
    simde_vst1q_bf16_x3(r_, val);
    simde_assert_equal_i(0, simde_memcmp(r_, test_vec[i].r, sizeof(test_vec[i].r)));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_bfloat16x3_t val[3] = simde_test_arm_neon_random_bf16x3(-100.0f, 100.0f);
    simde_bfloat16x24_t r = simde_vst1q_bf16_x3(val[3]);

    simde_test_arm_neon_write_bf16x3(2, val[3], SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_bf16x24(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_f16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_f32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_f64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_p8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_p16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_p64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_bf16_x3)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
