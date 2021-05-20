#define SIMDE_TEST_X86_AVX512_INSN roundscale

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/roundscale.h>
#include <simde/x86/avx512/setzero.h>

static int
test_simde_mm_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m128 a, e, r;

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   493.92), SIMDE_FLOAT32_C(   556.29), SIMDE_FLOAT32_C(   -46.81), SIMDE_FLOAT32_C(  -201.56));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   494.00), SIMDE_FLOAT32_C(   556.00), SIMDE_FLOAT32_C(   -47.00), SIMDE_FLOAT32_C(  -202.00));
  r = simde_mm_roundscale_ps(a, INT32_C(           0));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   -36.32), SIMDE_FLOAT32_C(   924.74), SIMDE_FLOAT32_C(  -925.84), SIMDE_FLOAT32_C(   602.33));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   -36.50), SIMDE_FLOAT32_C(   924.50), SIMDE_FLOAT32_C(  -926.00), SIMDE_FLOAT32_C(   602.50));
  r = simde_mm_roundscale_ps(a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   740.29), SIMDE_FLOAT32_C(  -398.96), SIMDE_FLOAT32_C(    54.66), SIMDE_FLOAT32_C(  -352.57));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   740.25), SIMDE_FLOAT32_C(  -399.00), SIMDE_FLOAT32_C(    54.75), SIMDE_FLOAT32_C(  -352.50));
  r = simde_mm_roundscale_ps(a, INT32_C(          32));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   756.81), SIMDE_FLOAT32_C(   171.03), SIMDE_FLOAT32_C(  -816.83), SIMDE_FLOAT32_C(   786.20));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   756.75), SIMDE_FLOAT32_C(   171.00), SIMDE_FLOAT32_C(  -816.88), SIMDE_FLOAT32_C(   786.25));
  r = simde_mm_roundscale_ps(a, INT32_C(          48));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -941.14), SIMDE_FLOAT32_C(  -471.01), SIMDE_FLOAT32_C(  -107.21), SIMDE_FLOAT32_C(    26.85));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -941.12), SIMDE_FLOAT32_C(  -471.00), SIMDE_FLOAT32_C(  -107.19), SIMDE_FLOAT32_C(    26.88));
  r = simde_mm_roundscale_ps(a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   -82.74), SIMDE_FLOAT32_C(  -855.02), SIMDE_FLOAT32_C(  -278.64), SIMDE_FLOAT32_C(   920.86));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   -82.75), SIMDE_FLOAT32_C(  -855.03), SIMDE_FLOAT32_C(  -278.62), SIMDE_FLOAT32_C(   920.88));
  r = simde_mm_roundscale_ps(a, INT32_C(          80));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   630.38), SIMDE_FLOAT32_C(    58.19), SIMDE_FLOAT32_C(   116.23), SIMDE_FLOAT32_C(   531.16));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   630.38), SIMDE_FLOAT32_C(    58.19), SIMDE_FLOAT32_C(   116.23), SIMDE_FLOAT32_C(   531.16));
  r = simde_mm_roundscale_ps(a, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -845.36), SIMDE_FLOAT32_C(  -193.30), SIMDE_FLOAT32_C(   382.31), SIMDE_FLOAT32_C(   356.21));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -845.36), SIMDE_FLOAT32_C(  -193.30), SIMDE_FLOAT32_C(   382.31), SIMDE_FLOAT32_C(   356.21));
  r = simde_mm_roundscale_ps(a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   937.83), SIMDE_FLOAT32_C(   648.56), SIMDE_FLOAT32_C(  -637.01), SIMDE_FLOAT32_C(  -664.50));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   937.83), SIMDE_FLOAT32_C(   648.56), SIMDE_FLOAT32_C(  -637.01), SIMDE_FLOAT32_C(  -664.50));
  r = simde_mm_roundscale_ps(a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(    84.58), SIMDE_FLOAT32_C(   -98.49), SIMDE_FLOAT32_C(   573.30), SIMDE_FLOAT32_C(  -562.85));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    84.58), SIMDE_FLOAT32_C(   -98.49), SIMDE_FLOAT32_C(   573.30), SIMDE_FLOAT32_C(  -562.85));
  r = simde_mm_roundscale_ps(a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -585.84), SIMDE_FLOAT32_C(  -175.13), SIMDE_FLOAT32_C(   502.55), SIMDE_FLOAT32_C(  -372.03));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -585.84), SIMDE_FLOAT32_C(  -175.13), SIMDE_FLOAT32_C(   502.55), SIMDE_FLOAT32_C(  -372.03));
  r = simde_mm_roundscale_ps(a, INT32_C(         160));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -287.43), SIMDE_FLOAT32_C(  -829.02), SIMDE_FLOAT32_C(   995.90), SIMDE_FLOAT32_C(   685.72));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -287.43), SIMDE_FLOAT32_C(  -829.02), SIMDE_FLOAT32_C(   995.90), SIMDE_FLOAT32_C(   685.72));
  r = simde_mm_roundscale_ps(a, INT32_C(         176));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -190.45), SIMDE_FLOAT32_C(  -228.57), SIMDE_FLOAT32_C(  -300.03), SIMDE_FLOAT32_C(  -111.31));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -190.45), SIMDE_FLOAT32_C(  -228.57), SIMDE_FLOAT32_C(  -300.03), SIMDE_FLOAT32_C(  -111.31));
  r = simde_mm_roundscale_ps(a, INT32_C(         192));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   -47.52), SIMDE_FLOAT32_C(   726.81), SIMDE_FLOAT32_C(   -83.59), SIMDE_FLOAT32_C(   421.32));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   -47.52), SIMDE_FLOAT32_C(   726.81), SIMDE_FLOAT32_C(   -83.59), SIMDE_FLOAT32_C(   421.32));
  r = simde_mm_roundscale_ps(a, INT32_C(         208));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   388.85), SIMDE_FLOAT32_C(  -417.14), SIMDE_FLOAT32_C(  -215.01), SIMDE_FLOAT32_C(  -967.36));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   388.85), SIMDE_FLOAT32_C(  -417.14), SIMDE_FLOAT32_C(  -215.01), SIMDE_FLOAT32_C(  -967.36));
  r = simde_mm_roundscale_ps(a, INT32_C(         224));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -497.19), SIMDE_FLOAT32_C(   543.50), SIMDE_FLOAT32_C(   389.57), SIMDE_FLOAT32_C(  -832.69));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -497.19), SIMDE_FLOAT32_C(   543.50), SIMDE_FLOAT32_C(   389.57), SIMDE_FLOAT32_C(  -832.69));
  r = simde_mm_roundscale_ps(a, INT32_C(         240));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -810.29), SIMDE_FLOAT32_C(  -559.36), SIMDE_FLOAT32_C(   192.06), SIMDE_FLOAT32_C(   752.56));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -811.00), SIMDE_FLOAT32_C(  -560.00), SIMDE_FLOAT32_C(   192.00), SIMDE_FLOAT32_C(   752.00));
  r = simde_mm_roundscale_ps(a, INT32_C(           1));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   393.33), SIMDE_FLOAT32_C(   274.29), SIMDE_FLOAT32_C(   342.15), SIMDE_FLOAT32_C(  -234.64));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   393.00), SIMDE_FLOAT32_C(   274.00), SIMDE_FLOAT32_C(   342.00), SIMDE_FLOAT32_C(  -235.00));
  r = simde_mm_roundscale_ps(a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -469.57), SIMDE_FLOAT32_C(   807.49), SIMDE_FLOAT32_C(  -900.84), SIMDE_FLOAT32_C(  -155.29));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -469.75), SIMDE_FLOAT32_C(   807.25), SIMDE_FLOAT32_C(  -901.00), SIMDE_FLOAT32_C(  -155.50));
  r = simde_mm_roundscale_ps(a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   -16.25), SIMDE_FLOAT32_C(   243.00), SIMDE_FLOAT32_C(   978.47), SIMDE_FLOAT32_C(  -904.94));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   -16.25), SIMDE_FLOAT32_C(   243.00), SIMDE_FLOAT32_C(   978.38), SIMDE_FLOAT32_C(  -905.00));
  r = simde_mm_roundscale_ps(a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -900.24), SIMDE_FLOAT32_C(   793.30), SIMDE_FLOAT32_C(  -985.57), SIMDE_FLOAT32_C(  -321.56));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -900.25), SIMDE_FLOAT32_C(   793.25), SIMDE_FLOAT32_C(  -985.62), SIMDE_FLOAT32_C(  -321.56));
  r = simde_mm_roundscale_ps(a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   -36.51), SIMDE_FLOAT32_C(    52.24), SIMDE_FLOAT32_C(   520.10), SIMDE_FLOAT32_C(   -69.16));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   -36.53), SIMDE_FLOAT32_C(    52.22), SIMDE_FLOAT32_C(   520.09), SIMDE_FLOAT32_C(   -69.19));
  r = simde_mm_roundscale_ps(a, INT32_C(          81));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -527.59), SIMDE_FLOAT32_C(  -647.66), SIMDE_FLOAT32_C(   635.10), SIMDE_FLOAT32_C(  -694.90));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -527.59), SIMDE_FLOAT32_C(  -647.67), SIMDE_FLOAT32_C(   635.09), SIMDE_FLOAT32_C(  -694.91));
  r = simde_mm_roundscale_ps(a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -222.77), SIMDE_FLOAT32_C(   -24.79), SIMDE_FLOAT32_C(   895.83), SIMDE_FLOAT32_C(    24.67));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -222.77), SIMDE_FLOAT32_C(   -24.80), SIMDE_FLOAT32_C(   895.83), SIMDE_FLOAT32_C(    24.66));
  r = simde_mm_roundscale_ps(a, INT32_C(         113));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   853.25), SIMDE_FLOAT32_C(   -33.06), SIMDE_FLOAT32_C(   415.86), SIMDE_FLOAT32_C(    87.89));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   853.25), SIMDE_FLOAT32_C(   -33.06), SIMDE_FLOAT32_C(   415.86), SIMDE_FLOAT32_C(    87.89));
  r = simde_mm_roundscale_ps(a, INT32_C(         129));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   602.72), SIMDE_FLOAT32_C(   246.58), SIMDE_FLOAT32_C(  -758.76), SIMDE_FLOAT32_C(  -241.99));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   602.72), SIMDE_FLOAT32_C(   246.58), SIMDE_FLOAT32_C(  -758.76), SIMDE_FLOAT32_C(  -241.99));
  r = simde_mm_roundscale_ps(a, INT32_C(         145));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -564.54), SIMDE_FLOAT32_C(  -866.86), SIMDE_FLOAT32_C(    54.07), SIMDE_FLOAT32_C(  -659.60));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -564.54), SIMDE_FLOAT32_C(  -866.86), SIMDE_FLOAT32_C(    54.07), SIMDE_FLOAT32_C(  -659.60));
  r = simde_mm_roundscale_ps(a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   710.98), SIMDE_FLOAT32_C(   419.21), SIMDE_FLOAT32_C(   376.14), SIMDE_FLOAT32_C(    32.54));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   710.98), SIMDE_FLOAT32_C(   419.21), SIMDE_FLOAT32_C(   376.14), SIMDE_FLOAT32_C(    32.54));
  r = simde_mm_roundscale_ps(a, INT32_C(         177));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -678.59), SIMDE_FLOAT32_C(   810.74), SIMDE_FLOAT32_C(   212.50), SIMDE_FLOAT32_C(   390.57));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -678.59), SIMDE_FLOAT32_C(   810.74), SIMDE_FLOAT32_C(   212.50), SIMDE_FLOAT32_C(   390.57));
  r = simde_mm_roundscale_ps(a, INT32_C(         193));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(    37.71), SIMDE_FLOAT32_C(   284.89), SIMDE_FLOAT32_C(  -137.02), SIMDE_FLOAT32_C(  -267.39));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    37.71), SIMDE_FLOAT32_C(   284.89), SIMDE_FLOAT32_C(  -137.02), SIMDE_FLOAT32_C(  -267.39));
  r = simde_mm_roundscale_ps(a, INT32_C(         209));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   522.76), SIMDE_FLOAT32_C(   510.11), SIMDE_FLOAT32_C(   637.23), SIMDE_FLOAT32_C(  -501.92));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   522.76), SIMDE_FLOAT32_C(   510.11), SIMDE_FLOAT32_C(   637.23), SIMDE_FLOAT32_C(  -501.92));
  r = simde_mm_roundscale_ps(a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -379.04), SIMDE_FLOAT32_C(  -700.01), SIMDE_FLOAT32_C(  -514.67), SIMDE_FLOAT32_C(   533.06));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -379.04), SIMDE_FLOAT32_C(  -700.01), SIMDE_FLOAT32_C(  -514.67), SIMDE_FLOAT32_C(   533.06));
  r = simde_mm_roundscale_ps(a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -340.81), SIMDE_FLOAT32_C(  -525.79), SIMDE_FLOAT32_C(   266.93), SIMDE_FLOAT32_C(   901.18));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -340.00), SIMDE_FLOAT32_C(  -525.00), SIMDE_FLOAT32_C(   267.00), SIMDE_FLOAT32_C(   902.00));
  r = simde_mm_roundscale_ps(a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   848.57), SIMDE_FLOAT32_C(  -738.09), SIMDE_FLOAT32_C(   720.79), SIMDE_FLOAT32_C(   508.17));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   849.00), SIMDE_FLOAT32_C(  -738.00), SIMDE_FLOAT32_C(   721.00), SIMDE_FLOAT32_C(   508.50));
  r = simde_mm_roundscale_ps(a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   807.41), SIMDE_FLOAT32_C(  -715.98), SIMDE_FLOAT32_C(  -604.95), SIMDE_FLOAT32_C(  -225.13));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   807.50), SIMDE_FLOAT32_C(  -715.75), SIMDE_FLOAT32_C(  -604.75), SIMDE_FLOAT32_C(  -225.00));
  r = simde_mm_roundscale_ps(a, INT32_C(          34));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   161.75), SIMDE_FLOAT32_C(   518.39), SIMDE_FLOAT32_C(   703.23), SIMDE_FLOAT32_C(   771.19));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   161.75), SIMDE_FLOAT32_C(   518.50), SIMDE_FLOAT32_C(   703.25), SIMDE_FLOAT32_C(   771.25));
  r = simde_mm_roundscale_ps(a, INT32_C(          50));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   648.34), SIMDE_FLOAT32_C(   483.16), SIMDE_FLOAT32_C(   329.13), SIMDE_FLOAT32_C(   -84.26));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   648.38), SIMDE_FLOAT32_C(   483.19), SIMDE_FLOAT32_C(   329.19), SIMDE_FLOAT32_C(   -84.25));
  r = simde_mm_roundscale_ps(a, INT32_C(          66));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -309.81), SIMDE_FLOAT32_C(  -313.95), SIMDE_FLOAT32_C(  -231.95), SIMDE_FLOAT32_C(  -807.89));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -309.78), SIMDE_FLOAT32_C(  -313.94), SIMDE_FLOAT32_C(  -231.94), SIMDE_FLOAT32_C(  -807.88));
  r = simde_mm_roundscale_ps(a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   938.35), SIMDE_FLOAT32_C(  -787.05), SIMDE_FLOAT32_C(  -803.84), SIMDE_FLOAT32_C(  -594.72));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   938.36), SIMDE_FLOAT32_C(  -787.05), SIMDE_FLOAT32_C(  -803.83), SIMDE_FLOAT32_C(  -594.72));
  r = simde_mm_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -417.33), SIMDE_FLOAT32_C(  -440.70), SIMDE_FLOAT32_C(  -487.07), SIMDE_FLOAT32_C(  -318.51));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -417.33), SIMDE_FLOAT32_C(  -440.70), SIMDE_FLOAT32_C(  -487.06), SIMDE_FLOAT32_C(  -318.51));
  r = simde_mm_roundscale_ps(a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   288.04), SIMDE_FLOAT32_C(   241.86), SIMDE_FLOAT32_C(    33.52), SIMDE_FLOAT32_C(   779.87));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   288.04), SIMDE_FLOAT32_C(   241.86), SIMDE_FLOAT32_C(    33.52), SIMDE_FLOAT32_C(   779.87));
  r = simde_mm_roundscale_ps(a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   529.18), SIMDE_FLOAT32_C(   136.60), SIMDE_FLOAT32_C(   503.77), SIMDE_FLOAT32_C(  -245.69));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   529.18), SIMDE_FLOAT32_C(   136.60), SIMDE_FLOAT32_C(   503.77), SIMDE_FLOAT32_C(  -245.69));
  r = simde_mm_roundscale_ps(a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   670.01), SIMDE_FLOAT32_C(   336.58), SIMDE_FLOAT32_C(   420.63), SIMDE_FLOAT32_C(   898.82));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   670.01), SIMDE_FLOAT32_C(   336.58), SIMDE_FLOAT32_C(   420.63), SIMDE_FLOAT32_C(   898.82));
  r = simde_mm_roundscale_ps(a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -960.40), SIMDE_FLOAT32_C(  -168.24), SIMDE_FLOAT32_C(  -145.03), SIMDE_FLOAT32_C(   123.86));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -960.40), SIMDE_FLOAT32_C(  -168.24), SIMDE_FLOAT32_C(  -145.03), SIMDE_FLOAT32_C(   123.86));
  r = simde_mm_roundscale_ps(a, INT32_C(         178));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -623.80), SIMDE_FLOAT32_C(   687.94), SIMDE_FLOAT32_C(  -685.08), SIMDE_FLOAT32_C(  -815.90));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -623.80), SIMDE_FLOAT32_C(   687.94), SIMDE_FLOAT32_C(  -685.08), SIMDE_FLOAT32_C(  -815.90));
  r = simde_mm_roundscale_ps(a, INT32_C(         194));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   488.26), SIMDE_FLOAT32_C(    66.39), SIMDE_FLOAT32_C(  -626.01), SIMDE_FLOAT32_C(    82.98));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   488.26), SIMDE_FLOAT32_C(    66.39), SIMDE_FLOAT32_C(  -626.01), SIMDE_FLOAT32_C(    82.98));
  r = simde_mm_roundscale_ps(a, INT32_C(         210));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   251.64), SIMDE_FLOAT32_C(   426.61), SIMDE_FLOAT32_C(   279.34), SIMDE_FLOAT32_C(  -429.84));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   251.64), SIMDE_FLOAT32_C(   426.61), SIMDE_FLOAT32_C(   279.34), SIMDE_FLOAT32_C(  -429.84));
  r = simde_mm_roundscale_ps(a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   572.14), SIMDE_FLOAT32_C(   834.32), SIMDE_FLOAT32_C(   985.91), SIMDE_FLOAT32_C(   792.27));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   572.14), SIMDE_FLOAT32_C(   834.32), SIMDE_FLOAT32_C(   985.91), SIMDE_FLOAT32_C(   792.27));
  r = simde_mm_roundscale_ps(a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   773.73), SIMDE_FLOAT32_C(  -139.82), SIMDE_FLOAT32_C(    76.18), SIMDE_FLOAT32_C(    19.42));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   773.00), SIMDE_FLOAT32_C(  -139.00), SIMDE_FLOAT32_C(    76.00), SIMDE_FLOAT32_C(    19.00));
  r = simde_mm_roundscale_ps(a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -521.22), SIMDE_FLOAT32_C(   302.91), SIMDE_FLOAT32_C(   996.78), SIMDE_FLOAT32_C(  -420.05));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -521.00), SIMDE_FLOAT32_C(   302.50), SIMDE_FLOAT32_C(   996.50), SIMDE_FLOAT32_C(  -420.00));
  r = simde_mm_roundscale_ps(a, INT32_C(          19));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -458.73), SIMDE_FLOAT32_C(  -851.21), SIMDE_FLOAT32_C(  -360.51), SIMDE_FLOAT32_C(   417.41));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -458.50), SIMDE_FLOAT32_C(  -851.00), SIMDE_FLOAT32_C(  -360.50), SIMDE_FLOAT32_C(   417.25));
  r = simde_mm_roundscale_ps(a, INT32_C(          35));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   678.57), SIMDE_FLOAT32_C(  -419.13), SIMDE_FLOAT32_C(   -19.45), SIMDE_FLOAT32_C(   494.47));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   678.50), SIMDE_FLOAT32_C(  -419.12), SIMDE_FLOAT32_C(   -19.38), SIMDE_FLOAT32_C(   494.38));
  r = simde_mm_roundscale_ps(a, INT32_C(          51));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -621.55), SIMDE_FLOAT32_C(  -945.23), SIMDE_FLOAT32_C(  -731.19), SIMDE_FLOAT32_C(   295.48));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -621.50), SIMDE_FLOAT32_C(  -945.19), SIMDE_FLOAT32_C(  -731.19), SIMDE_FLOAT32_C(   295.44));
  r = simde_mm_roundscale_ps(a, INT32_C(          67));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   212.95), SIMDE_FLOAT32_C(   866.71), SIMDE_FLOAT32_C(   121.16), SIMDE_FLOAT32_C(  -357.20));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   212.94), SIMDE_FLOAT32_C(   866.69), SIMDE_FLOAT32_C(   121.16), SIMDE_FLOAT32_C(  -357.19));
  r = simde_mm_roundscale_ps(a, INT32_C(          83));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -807.23), SIMDE_FLOAT32_C(  -535.40), SIMDE_FLOAT32_C(   293.32), SIMDE_FLOAT32_C(  -599.50));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -807.22), SIMDE_FLOAT32_C(  -535.39), SIMDE_FLOAT32_C(   293.31), SIMDE_FLOAT32_C(  -599.50));
  r = simde_mm_roundscale_ps(a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -701.35), SIMDE_FLOAT32_C(   764.92), SIMDE_FLOAT32_C(  -701.08), SIMDE_FLOAT32_C(   279.23));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -701.34), SIMDE_FLOAT32_C(   764.91), SIMDE_FLOAT32_C(  -701.08), SIMDE_FLOAT32_C(   279.23));
  r = simde_mm_roundscale_ps(a, INT32_C(         115));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   955.05), SIMDE_FLOAT32_C(  -927.62), SIMDE_FLOAT32_C(  -374.91), SIMDE_FLOAT32_C(   375.10));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   955.05), SIMDE_FLOAT32_C(  -927.62), SIMDE_FLOAT32_C(  -374.91), SIMDE_FLOAT32_C(   375.10));
  r = simde_mm_roundscale_ps(a, INT32_C(         131));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -960.72), SIMDE_FLOAT32_C(  -566.17), SIMDE_FLOAT32_C(   375.29), SIMDE_FLOAT32_C(  -378.13));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -960.72), SIMDE_FLOAT32_C(  -566.17), SIMDE_FLOAT32_C(   375.29), SIMDE_FLOAT32_C(  -378.13));
  r = simde_mm_roundscale_ps(a, INT32_C(         147));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   509.25), SIMDE_FLOAT32_C(  -419.45), SIMDE_FLOAT32_C(  -417.39), SIMDE_FLOAT32_C(  -985.21));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   509.25), SIMDE_FLOAT32_C(  -419.45), SIMDE_FLOAT32_C(  -417.39), SIMDE_FLOAT32_C(  -985.21));
  r = simde_mm_roundscale_ps(a, INT32_C(         163));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -141.36), SIMDE_FLOAT32_C(   187.82), SIMDE_FLOAT32_C(   161.42), SIMDE_FLOAT32_C(   563.17));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -141.36), SIMDE_FLOAT32_C(   187.82), SIMDE_FLOAT32_C(   161.42), SIMDE_FLOAT32_C(   563.17));
  r = simde_mm_roundscale_ps(a, INT32_C(         179));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -926.97), SIMDE_FLOAT32_C(   237.10), SIMDE_FLOAT32_C(   242.59), SIMDE_FLOAT32_C(   430.23));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -926.97), SIMDE_FLOAT32_C(   237.10), SIMDE_FLOAT32_C(   242.59), SIMDE_FLOAT32_C(   430.23));
  r = simde_mm_roundscale_ps(a, INT32_C(         195));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -235.75), SIMDE_FLOAT32_C(   285.98), SIMDE_FLOAT32_C(   103.81), SIMDE_FLOAT32_C(  -636.25));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -235.75), SIMDE_FLOAT32_C(   285.98), SIMDE_FLOAT32_C(   103.81), SIMDE_FLOAT32_C(  -636.25));
  r = simde_mm_roundscale_ps(a, INT32_C(         211));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   676.35), SIMDE_FLOAT32_C(   -42.97), SIMDE_FLOAT32_C(   750.58), SIMDE_FLOAT32_C(  -602.88));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   676.35), SIMDE_FLOAT32_C(   -42.97), SIMDE_FLOAT32_C(   750.58), SIMDE_FLOAT32_C(  -602.88));
  r = simde_mm_roundscale_ps(a, INT32_C(         227));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   424.59), SIMDE_FLOAT32_C(   975.00), SIMDE_FLOAT32_C(  -278.06), SIMDE_FLOAT32_C(  -950.50));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   424.59), SIMDE_FLOAT32_C(   975.00), SIMDE_FLOAT32_C(  -278.06), SIMDE_FLOAT32_C(  -950.50));
  r = simde_mm_roundscale_ps(a, INT32_C(         243));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   968.91), SIMDE_FLOAT32_C(   379.64), SIMDE_FLOAT32_C(  -952.62), SIMDE_FLOAT32_C(   347.03));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   969.00), SIMDE_FLOAT32_C(   380.00), SIMDE_FLOAT32_C(  -953.00), SIMDE_FLOAT32_C(   347.00));
  r = simde_mm_roundscale_ps(a, INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   437.46), SIMDE_FLOAT32_C(  -991.81), SIMDE_FLOAT32_C(   813.47), SIMDE_FLOAT32_C(   422.67));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   437.50), SIMDE_FLOAT32_C(  -992.00), SIMDE_FLOAT32_C(   813.50), SIMDE_FLOAT32_C(   422.50));
  r = simde_mm_roundscale_ps(a, INT32_C(          20));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   959.25), SIMDE_FLOAT32_C(   -53.29), SIMDE_FLOAT32_C(  -411.25), SIMDE_FLOAT32_C(  -603.92));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   959.25), SIMDE_FLOAT32_C(   -53.25), SIMDE_FLOAT32_C(  -411.25), SIMDE_FLOAT32_C(  -604.00));
  r = simde_mm_roundscale_ps(a, INT32_C(          36));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   180.40), SIMDE_FLOAT32_C(  -182.11), SIMDE_FLOAT32_C(  -865.47), SIMDE_FLOAT32_C(   750.17));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   180.38), SIMDE_FLOAT32_C(  -182.12), SIMDE_FLOAT32_C(  -865.50), SIMDE_FLOAT32_C(   750.12));
  r = simde_mm_roundscale_ps(a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   740.87), SIMDE_FLOAT32_C(   253.42), SIMDE_FLOAT32_C(  -945.01), SIMDE_FLOAT32_C(   377.12));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   740.88), SIMDE_FLOAT32_C(   253.44), SIMDE_FLOAT32_C(  -945.00), SIMDE_FLOAT32_C(   377.12));
  r = simde_mm_roundscale_ps(a, INT32_C(          68));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   555.92), SIMDE_FLOAT32_C(  -494.88), SIMDE_FLOAT32_C(  -460.60), SIMDE_FLOAT32_C(   158.79));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   555.91), SIMDE_FLOAT32_C(  -494.88), SIMDE_FLOAT32_C(  -460.59), SIMDE_FLOAT32_C(   158.78));
  r = simde_mm_roundscale_ps(a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -660.52), SIMDE_FLOAT32_C(   232.27), SIMDE_FLOAT32_C(   462.15), SIMDE_FLOAT32_C(  -710.01));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -660.52), SIMDE_FLOAT32_C(   232.27), SIMDE_FLOAT32_C(   462.16), SIMDE_FLOAT32_C(  -710.02));
  r = simde_mm_roundscale_ps(a, INT32_C(         100));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   531.12), SIMDE_FLOAT32_C(   764.07), SIMDE_FLOAT32_C(   207.27), SIMDE_FLOAT32_C(  -815.91));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   531.12), SIMDE_FLOAT32_C(   764.07), SIMDE_FLOAT32_C(   207.27), SIMDE_FLOAT32_C(  -815.91));
  r = simde_mm_roundscale_ps(a, INT32_C(         116));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -322.68), SIMDE_FLOAT32_C(   500.03), SIMDE_FLOAT32_C(   143.72), SIMDE_FLOAT32_C(   254.65));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -322.68), SIMDE_FLOAT32_C(   500.03), SIMDE_FLOAT32_C(   143.72), SIMDE_FLOAT32_C(   254.65));
  r = simde_mm_roundscale_ps(a, INT32_C(         132));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   353.27), SIMDE_FLOAT32_C(  -885.22), SIMDE_FLOAT32_C(   508.23), SIMDE_FLOAT32_C(   -42.82));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   353.27), SIMDE_FLOAT32_C(  -885.22), SIMDE_FLOAT32_C(   508.23), SIMDE_FLOAT32_C(   -42.82));
  r = simde_mm_roundscale_ps(a, INT32_C(         148));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   847.14), SIMDE_FLOAT32_C(   312.51), SIMDE_FLOAT32_C(    61.49), SIMDE_FLOAT32_C(  -903.03));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   847.14), SIMDE_FLOAT32_C(   312.51), SIMDE_FLOAT32_C(    61.49), SIMDE_FLOAT32_C(  -903.03));
  r = simde_mm_roundscale_ps(a, INT32_C(         164));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -426.86), SIMDE_FLOAT32_C(    27.54), SIMDE_FLOAT32_C(  -869.59), SIMDE_FLOAT32_C(   196.02));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -426.86), SIMDE_FLOAT32_C(    27.54), SIMDE_FLOAT32_C(  -869.59), SIMDE_FLOAT32_C(   196.02));
  r = simde_mm_roundscale_ps(a, INT32_C(         180));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   344.19), SIMDE_FLOAT32_C(  -686.00), SIMDE_FLOAT32_C(  -719.04), SIMDE_FLOAT32_C(  -814.61));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   344.19), SIMDE_FLOAT32_C(  -686.00), SIMDE_FLOAT32_C(  -719.04), SIMDE_FLOAT32_C(  -814.61));
  r = simde_mm_roundscale_ps(a, INT32_C(         196));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   110.35), SIMDE_FLOAT32_C(   -99.89), SIMDE_FLOAT32_C(  -180.88), SIMDE_FLOAT32_C(  -179.63));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   110.35), SIMDE_FLOAT32_C(   -99.89), SIMDE_FLOAT32_C(  -180.88), SIMDE_FLOAT32_C(  -179.63));
  r = simde_mm_roundscale_ps(a, INT32_C(         212));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -534.65), SIMDE_FLOAT32_C(   449.84), SIMDE_FLOAT32_C(  -867.63), SIMDE_FLOAT32_C(  -718.73));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -534.65), SIMDE_FLOAT32_C(   449.84), SIMDE_FLOAT32_C(  -867.63), SIMDE_FLOAT32_C(  -718.73));
  r = simde_mm_roundscale_ps(a, INT32_C(         228));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -405.71), SIMDE_FLOAT32_C(   996.48), SIMDE_FLOAT32_C(   213.91), SIMDE_FLOAT32_C(   339.64));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -405.71), SIMDE_FLOAT32_C(   996.48), SIMDE_FLOAT32_C(   213.91), SIMDE_FLOAT32_C(   339.64));
  r = simde_mm_roundscale_ps(a, INT32_C(         244));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m128 r;
      SIMDE_CONSTIFY_256_(simde_mm_roundscale_ps, r, simde_mm_setzero_ps(), imm8, a);

      simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_ps)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
