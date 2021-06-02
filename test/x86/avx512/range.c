#define SIMDE_TEST_X86_AVX512_INSN range

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/set.h>
#include <simde/x86/avx512/setzero.h>
#include <simde/x86/avx512/range.h>

static int
test_simde_mm_range_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   255.95), SIMDE_FLOAT32_C(   262.13), SIMDE_FLOAT32_C(   990.40), SIMDE_FLOAT32_C(  -502.54) },
      { SIMDE_FLOAT32_C(  -837.49), SIMDE_FLOAT32_C(   145.07), SIMDE_FLOAT32_C(   710.99), SIMDE_FLOAT32_C(  -255.92) },
      { SIMDE_FLOAT32_C(   837.49), SIMDE_FLOAT32_C(   262.13), SIMDE_FLOAT32_C(   990.40), SIMDE_FLOAT32_C(   502.54) } },
    { { SIMDE_FLOAT32_C(  -196.03), SIMDE_FLOAT32_C(   640.68), SIMDE_FLOAT32_C(  -138.92), SIMDE_FLOAT32_C(  -782.11) },
      { SIMDE_FLOAT32_C(  -561.08), SIMDE_FLOAT32_C(  -912.21), SIMDE_FLOAT32_C(   957.45), SIMDE_FLOAT32_C(   859.99) },
      { SIMDE_FLOAT32_C(  -561.08), SIMDE_FLOAT32_C(  -912.21), SIMDE_FLOAT32_C(  -138.92), SIMDE_FLOAT32_C(  -782.11) } },
    { { SIMDE_FLOAT32_C(   594.70), SIMDE_FLOAT32_C(   371.33), SIMDE_FLOAT32_C(   362.58), SIMDE_FLOAT32_C(  -743.00) },
      { SIMDE_FLOAT32_C(  -691.49), SIMDE_FLOAT32_C(  -684.68), SIMDE_FLOAT32_C(   514.63), SIMDE_FLOAT32_C(   797.88) },
      { SIMDE_FLOAT32_C(   594.70), SIMDE_FLOAT32_C(   371.33), SIMDE_FLOAT32_C(   514.63), SIMDE_FLOAT32_C(  -797.88) } },
    { { SIMDE_FLOAT32_C(  -878.00), SIMDE_FLOAT32_C(  -241.00), SIMDE_FLOAT32_C(  -713.77), SIMDE_FLOAT32_C(   133.71) },
      { SIMDE_FLOAT32_C(  -955.11), SIMDE_FLOAT32_C(  -342.49), SIMDE_FLOAT32_C(   444.74), SIMDE_FLOAT32_C(   300.84) },
      { SIMDE_FLOAT32_C(  -878.00), SIMDE_FLOAT32_C(  -241.00), SIMDE_FLOAT32_C(  -444.74), SIMDE_FLOAT32_C(   133.71) } },
    { { SIMDE_FLOAT32_C(   919.63), SIMDE_FLOAT32_C(   435.14), SIMDE_FLOAT32_C(   798.30), SIMDE_FLOAT32_C(  -917.86) },
      { SIMDE_FLOAT32_C(  -419.79), SIMDE_FLOAT32_C(   509.28), SIMDE_FLOAT32_C(  -173.78), SIMDE_FLOAT32_C(   384.18) },
      { SIMDE_FLOAT32_C(   919.63), SIMDE_FLOAT32_C(   509.28), SIMDE_FLOAT32_C(   798.30), SIMDE_FLOAT32_C(  -917.86) } },
    { { SIMDE_FLOAT32_C(   149.97), SIMDE_FLOAT32_C(   687.31), SIMDE_FLOAT32_C(   602.07), SIMDE_FLOAT32_C(   588.89) },
      { SIMDE_FLOAT32_C(   775.09), SIMDE_FLOAT32_C(   559.52), SIMDE_FLOAT32_C(   448.88), SIMDE_FLOAT32_C(   369.80) },
      { SIMDE_FLOAT32_C(   775.09), SIMDE_FLOAT32_C(   687.31), SIMDE_FLOAT32_C(   602.07), SIMDE_FLOAT32_C(   588.89) } },
    { { SIMDE_FLOAT32_C(   -69.15), SIMDE_FLOAT32_C(  -188.54), SIMDE_FLOAT32_C(   626.80), SIMDE_FLOAT32_C(   239.36) },
      { SIMDE_FLOAT32_C(   126.78), SIMDE_FLOAT32_C(   141.43), SIMDE_FLOAT32_C(    37.24), SIMDE_FLOAT32_C(   248.78) },
      { SIMDE_FLOAT32_C(   126.78), SIMDE_FLOAT32_C(   141.43), SIMDE_FLOAT32_C(   626.80), SIMDE_FLOAT32_C(   248.78) } },
    { { SIMDE_FLOAT32_C(   900.43), SIMDE_FLOAT32_C(   323.47), SIMDE_FLOAT32_C(  -617.51), SIMDE_FLOAT32_C(   945.32) },
      { SIMDE_FLOAT32_C(   980.98), SIMDE_FLOAT32_C(   827.24), SIMDE_FLOAT32_C(   246.16), SIMDE_FLOAT32_C(   900.61) },
      { SIMDE_FLOAT32_C(   900.43), SIMDE_FLOAT32_C(   323.47), SIMDE_FLOAT32_C(  -617.51), SIMDE_FLOAT32_C(   900.61) } }
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_range_ps(a, b, 11);
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_range_ps(a, b, 4);
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_range_ps(a, b, 1);
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_range_ps(a, b, 2);
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_range_ps(a, b, 3);
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_range_ps(a, b, 9);
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_range_ps(a, b, 5);
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_range_ps(a, b, 0);
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);

  simde__m128 a, b, r;

  a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm_range_ps(a, b, 11);

  simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm_range_ps(a, b, 4);

  simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm_range_ps(a, b, 1);

  simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm_range_ps(a, b, 2);

  simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm_range_ps(a, b, 3);

  simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm_range_ps(a, b, 9);

  simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm_range_ps(a, b, 5);

  simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm_range_ps(a, b, 0);

  simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm_mask_range_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m128 src, a, b, e, r;

  src = simde_mm_set_ps(SIMDE_FLOAT32_C(  -475.13), SIMDE_FLOAT32_C(  -420.22), SIMDE_FLOAT32_C(  -562.17), SIMDE_FLOAT32_C(   187.68));
  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -756.17), SIMDE_FLOAT32_C(  -745.80), SIMDE_FLOAT32_C(  -452.78), SIMDE_FLOAT32_C(   330.45));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -467.50), SIMDE_FLOAT32_C(   434.14), SIMDE_FLOAT32_C(   -54.78), SIMDE_FLOAT32_C(  -810.43));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -475.13), SIMDE_FLOAT32_C(  -420.22), SIMDE_FLOAT32_C(   452.78), SIMDE_FLOAT32_C(   187.68));
  r = simde_mm_mask_range_ps(src, UINT8_C(194), a, b, INT32_C(          11));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  src = simde_mm_set_ps(SIMDE_FLOAT32_C(   437.68), SIMDE_FLOAT32_C(   650.60), SIMDE_FLOAT32_C(  -352.96), SIMDE_FLOAT32_C(   637.19));
  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   684.24), SIMDE_FLOAT32_C(   201.31), SIMDE_FLOAT32_C(  -376.46), SIMDE_FLOAT32_C(   518.68));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   410.87), SIMDE_FLOAT32_C(  -185.65), SIMDE_FLOAT32_C(  -832.96), SIMDE_FLOAT32_C(  -931.61));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   684.24), SIMDE_FLOAT32_C(   201.31), SIMDE_FLOAT32_C(  -352.96), SIMDE_FLOAT32_C(   518.68));
  r = simde_mm_mask_range_ps(src, UINT8_C(205), a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  src = simde_mm_set_ps(SIMDE_FLOAT32_C(  -981.24), SIMDE_FLOAT32_C(   216.99), SIMDE_FLOAT32_C(   393.09), SIMDE_FLOAT32_C(  -168.92));
  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   127.22), SIMDE_FLOAT32_C(   555.16), SIMDE_FLOAT32_C(  -456.37), SIMDE_FLOAT32_C(   796.77));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   280.43), SIMDE_FLOAT32_C(   371.05), SIMDE_FLOAT32_C(   809.37), SIMDE_FLOAT32_C(    90.86));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -280.43), SIMDE_FLOAT32_C(   216.99), SIMDE_FLOAT32_C(   393.09), SIMDE_FLOAT32_C(  -796.77));
  r = simde_mm_mask_range_ps(src, UINT8_C( 41), a, b, INT32_C(          15));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  src = simde_mm_set_ps(SIMDE_FLOAT32_C(  -557.61), SIMDE_FLOAT32_C(  -637.19), SIMDE_FLOAT32_C(   812.93), SIMDE_FLOAT32_C(  -194.80));
  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   532.09), SIMDE_FLOAT32_C(    94.31), SIMDE_FLOAT32_C(   880.08), SIMDE_FLOAT32_C(  -986.59));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -427.99), SIMDE_FLOAT32_C(   216.33), SIMDE_FLOAT32_C(  -704.37), SIMDE_FLOAT32_C(  -496.38));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -557.61), SIMDE_FLOAT32_C(   -94.31), SIMDE_FLOAT32_C(  -704.37), SIMDE_FLOAT32_C(  -986.59));
  r = simde_mm_mask_range_ps(src, UINT8_C(119), a, b, INT32_C(          12));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  src = simde_mm_set_ps(SIMDE_FLOAT32_C(  -138.24), SIMDE_FLOAT32_C(   -30.06), SIMDE_FLOAT32_C(   982.88), SIMDE_FLOAT32_C(  -969.32));
  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   983.71), SIMDE_FLOAT32_C(   206.90), SIMDE_FLOAT32_C(  -119.48), SIMDE_FLOAT32_C(  -813.07));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -484.99), SIMDE_FLOAT32_C(   110.93), SIMDE_FLOAT32_C(  -237.94), SIMDE_FLOAT32_C(   424.15));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -484.99), SIMDE_FLOAT32_C(   -30.06), SIMDE_FLOAT32_C(  -119.48), SIMDE_FLOAT32_C(  -969.32));
  r = simde_mm_mask_range_ps(src, UINT8_C( 58), a, b, INT32_C(           6));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  src = simde_mm_set_ps(SIMDE_FLOAT32_C(   287.18), SIMDE_FLOAT32_C(   326.02), SIMDE_FLOAT32_C(   795.44), SIMDE_FLOAT32_C(  -518.02));
  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   702.24), SIMDE_FLOAT32_C(  -931.66), SIMDE_FLOAT32_C(   729.57), SIMDE_FLOAT32_C(   688.83));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -886.73), SIMDE_FLOAT32_C(   234.33), SIMDE_FLOAT32_C(   162.66), SIMDE_FLOAT32_C(   609.65));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -886.73), SIMDE_FLOAT32_C(   326.02), SIMDE_FLOAT32_C(   795.44), SIMDE_FLOAT32_C(   688.83));
  r = simde_mm_mask_range_ps(src, UINT8_C(153), a, b, INT32_C(           7));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  src = simde_mm_set_ps(SIMDE_FLOAT32_C(  -518.66), SIMDE_FLOAT32_C(   920.95), SIMDE_FLOAT32_C(  -314.72), SIMDE_FLOAT32_C(  -549.34));
  a = simde_mm_set_ps(SIMDE_FLOAT32_C(    77.83), SIMDE_FLOAT32_C(  -955.87), SIMDE_FLOAT32_C(   343.10), SIMDE_FLOAT32_C(  -109.11));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   647.77), SIMDE_FLOAT32_C(    61.53), SIMDE_FLOAT32_C(   251.02), SIMDE_FLOAT32_C(  -776.38));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -518.66), SIMDE_FLOAT32_C(   920.95), SIMDE_FLOAT32_C(   251.02), SIMDE_FLOAT32_C(  -109.11));
  r = simde_mm_mask_range_ps(src, UINT8_C( 99), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  src = simde_mm_set_ps(SIMDE_FLOAT32_C(  -345.55), SIMDE_FLOAT32_C(  -415.49), SIMDE_FLOAT32_C(  -837.22), SIMDE_FLOAT32_C(  -827.54));
  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   599.36), SIMDE_FLOAT32_C(   566.58), SIMDE_FLOAT32_C(   941.63), SIMDE_FLOAT32_C(   910.53));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   280.85), SIMDE_FLOAT32_C(   301.59), SIMDE_FLOAT32_C(   634.93), SIMDE_FLOAT32_C(   671.20));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   280.85), SIMDE_FLOAT32_C(  -415.49), SIMDE_FLOAT32_C(  -837.22), SIMDE_FLOAT32_C(   671.20));
  r = simde_mm_mask_range_ps(src, UINT8_C(153), a, b, INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m128 r;
    SIMDE_CONSTIFY_16_(simde_mm_mask_range_ps, r, simde_mm_setzero_ps(), imm8, src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_range_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m128 a, b, e, r;

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -920.60), SIMDE_FLOAT32_C(   -13.42), SIMDE_FLOAT32_C(  -744.13), SIMDE_FLOAT32_C(   394.12));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(    67.71), SIMDE_FLOAT32_C(  -252.44), SIMDE_FLOAT32_C(   467.92), SIMDE_FLOAT32_C(  -823.18));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -13.42), SIMDE_FLOAT32_C(  -467.92), SIMDE_FLOAT32_C(     0.00));
  r = simde_mm_maskz_range_ps(UINT8_C(134), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   207.07), SIMDE_FLOAT32_C(  -957.29), SIMDE_FLOAT32_C(    34.64), SIMDE_FLOAT32_C(  -854.46));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -154.81), SIMDE_FLOAT32_C(   379.53), SIMDE_FLOAT32_C(  -944.21), SIMDE_FLOAT32_C(  -317.59));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -154.81), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    34.64), SIMDE_FLOAT32_C(     0.00));
  r = simde_mm_maskz_range_ps(UINT8_C(170), a, b, INT32_C(           6));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -630.01), SIMDE_FLOAT32_C(   975.61), SIMDE_FLOAT32_C(  -449.17), SIMDE_FLOAT32_C(  -196.59));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   451.78), SIMDE_FLOAT32_C(  -995.08), SIMDE_FLOAT32_C(   646.81), SIMDE_FLOAT32_C(  -849.81));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -975.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00));
  r = simde_mm_maskz_range_ps(UINT8_C(228), a, b, INT32_C(          13));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   -25.72), SIMDE_FLOAT32_C(    58.38), SIMDE_FLOAT32_C(  -678.22), SIMDE_FLOAT32_C(   987.70));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   148.74), SIMDE_FLOAT32_C(  -557.80), SIMDE_FLOAT32_C(   235.20), SIMDE_FLOAT32_C(  -598.82));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   148.74), SIMDE_FLOAT32_C(   557.80), SIMDE_FLOAT32_C(   678.22), SIMDE_FLOAT32_C(     0.00));
  r = simde_mm_maskz_range_ps(UINT8_C(206), a, b, INT32_C(          11));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   983.13), SIMDE_FLOAT32_C(  -712.14), SIMDE_FLOAT32_C(  -551.55), SIMDE_FLOAT32_C(   940.42));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(    35.05), SIMDE_FLOAT32_C(  -961.08), SIMDE_FLOAT32_C(   -29.73), SIMDE_FLOAT32_C(   655.52));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   -35.05), SIMDE_FLOAT32_C(  -712.14), SIMDE_FLOAT32_C(   -29.73), SIMDE_FLOAT32_C(  -655.52));
  r = simde_mm_maskz_range_ps(UINT8_C(111), a, b, INT32_C(          14));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(    44.64), SIMDE_FLOAT32_C(   230.06), SIMDE_FLOAT32_C(  -381.13), SIMDE_FLOAT32_C(    69.03));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(    -6.22), SIMDE_FLOAT32_C(  -308.55), SIMDE_FLOAT32_C(   380.25), SIMDE_FLOAT32_C(   -11.14));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -381.13), SIMDE_FLOAT32_C(    69.03));
  r = simde_mm_maskz_range_ps(UINT8_C( 51), a, b, INT32_C(           7));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -145.33), SIMDE_FLOAT32_C(   940.89), SIMDE_FLOAT32_C(  -180.26), SIMDE_FLOAT32_C(   796.29));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -763.78), SIMDE_FLOAT32_C(  -910.13), SIMDE_FLOAT32_C(  -657.93), SIMDE_FLOAT32_C(   794.02));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(  -145.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -180.26), SIMDE_FLOAT32_C(   794.02));
  r = simde_mm_maskz_range_ps(UINT8_C( 75), a, b, INT32_C(           6));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   777.30), SIMDE_FLOAT32_C(  -158.78), SIMDE_FLOAT32_C(   431.22), SIMDE_FLOAT32_C(   489.44));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   453.27), SIMDE_FLOAT32_C(  -252.42), SIMDE_FLOAT32_C(  -503.26), SIMDE_FLOAT32_C(   414.35));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(   453.27), SIMDE_FLOAT32_C(   158.78), SIMDE_FLOAT32_C(   431.22), SIMDE_FLOAT32_C(   414.35));
  r = simde_mm_maskz_range_ps(UINT8_C( 47), a, b, INT32_C(          10));
  simde_test_x86_assert_equal_f32x4(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m128 r;
    SIMDE_CONSTIFY_16_(simde_mm_maskz_range_ps, r, simde_mm_setzero_ps(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_range_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const simde_float32 b[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   965.90), SIMDE_FLOAT32_C(   639.20), SIMDE_FLOAT32_C(   459.04), SIMDE_FLOAT32_C(  -520.02),
        SIMDE_FLOAT32_C(  -921.38), SIMDE_FLOAT32_C(  -256.36), SIMDE_FLOAT32_C(  -322.58), SIMDE_FLOAT32_C(  -975.13) },
      { SIMDE_FLOAT32_C(  -835.96), SIMDE_FLOAT32_C(   794.37), SIMDE_FLOAT32_C(   868.62), SIMDE_FLOAT32_C(  -546.74),
        SIMDE_FLOAT32_C(  -578.43), SIMDE_FLOAT32_C(   511.48), SIMDE_FLOAT32_C(  -160.60), SIMDE_FLOAT32_C(   388.19) },
      { SIMDE_FLOAT32_C(   965.90), SIMDE_FLOAT32_C(   794.37), SIMDE_FLOAT32_C(   868.62), SIMDE_FLOAT32_C(   546.74),
        SIMDE_FLOAT32_C(   921.38), SIMDE_FLOAT32_C(   511.48), SIMDE_FLOAT32_C(   322.58), SIMDE_FLOAT32_C(   975.13) } },
    { { SIMDE_FLOAT32_C(   419.06), SIMDE_FLOAT32_C(   212.58), SIMDE_FLOAT32_C(  -437.40), SIMDE_FLOAT32_C(  -767.85),
        SIMDE_FLOAT32_C(   542.50), SIMDE_FLOAT32_C(   326.58), SIMDE_FLOAT32_C(  -844.98), SIMDE_FLOAT32_C(  -122.00) },
      { SIMDE_FLOAT32_C(   668.38), SIMDE_FLOAT32_C(   663.21), SIMDE_FLOAT32_C(   157.32), SIMDE_FLOAT32_C(  -776.07),
        SIMDE_FLOAT32_C(   123.57), SIMDE_FLOAT32_C(   356.87), SIMDE_FLOAT32_C(   896.03), SIMDE_FLOAT32_C(    89.48) },
      { SIMDE_FLOAT32_C(   419.06), SIMDE_FLOAT32_C(   212.58), SIMDE_FLOAT32_C(  -437.40), SIMDE_FLOAT32_C(  -776.07),
        SIMDE_FLOAT32_C(   123.57), SIMDE_FLOAT32_C(   326.58), SIMDE_FLOAT32_C(  -844.98), SIMDE_FLOAT32_C(  -122.00) } },
    { { SIMDE_FLOAT32_C(    -3.93), SIMDE_FLOAT32_C(   355.07), SIMDE_FLOAT32_C(   569.46), SIMDE_FLOAT32_C(    74.69),
        SIMDE_FLOAT32_C(  -901.29), SIMDE_FLOAT32_C(  -753.12), SIMDE_FLOAT32_C(    99.55), SIMDE_FLOAT32_C(  -737.26) },
      { SIMDE_FLOAT32_C(  -958.76), SIMDE_FLOAT32_C(   -31.83), SIMDE_FLOAT32_C(  -284.00), SIMDE_FLOAT32_C(  -537.19),
        SIMDE_FLOAT32_C(  -520.35), SIMDE_FLOAT32_C(   555.40), SIMDE_FLOAT32_C(   851.00), SIMDE_FLOAT32_C(   898.71) },
      { SIMDE_FLOAT32_C(    -3.93), SIMDE_FLOAT32_C(   355.07), SIMDE_FLOAT32_C(   569.46), SIMDE_FLOAT32_C(    74.69),
        SIMDE_FLOAT32_C(  -520.35), SIMDE_FLOAT32_C(  -555.40), SIMDE_FLOAT32_C(   851.00), SIMDE_FLOAT32_C(  -898.71) } },
    { { SIMDE_FLOAT32_C(  -232.02), SIMDE_FLOAT32_C(  -586.40), SIMDE_FLOAT32_C(  -869.13), SIMDE_FLOAT32_C(  -689.52),
        SIMDE_FLOAT32_C(   740.18), SIMDE_FLOAT32_C(  -714.11), SIMDE_FLOAT32_C(   188.48), SIMDE_FLOAT32_C(   408.56) },
      { SIMDE_FLOAT32_C(   949.10), SIMDE_FLOAT32_C(  -654.19), SIMDE_FLOAT32_C(   632.49), SIMDE_FLOAT32_C(    72.67),
        SIMDE_FLOAT32_C(   702.67), SIMDE_FLOAT32_C(   528.51), SIMDE_FLOAT32_C(  -837.85), SIMDE_FLOAT32_C(  -301.26) },
      { SIMDE_FLOAT32_C(  -232.02), SIMDE_FLOAT32_C(  -586.40), SIMDE_FLOAT32_C(  -632.49), SIMDE_FLOAT32_C(   -72.67),
        SIMDE_FLOAT32_C(   702.67), SIMDE_FLOAT32_C(  -528.51), SIMDE_FLOAT32_C(   188.48), SIMDE_FLOAT32_C(   301.26) } },
    { { SIMDE_FLOAT32_C(  -116.42), SIMDE_FLOAT32_C(   731.60), SIMDE_FLOAT32_C(   773.42), SIMDE_FLOAT32_C(   -17.71),
        SIMDE_FLOAT32_C(   978.48), SIMDE_FLOAT32_C(  -127.03), SIMDE_FLOAT32_C(   245.03), SIMDE_FLOAT32_C(  -980.28) },
      { SIMDE_FLOAT32_C(   841.14), SIMDE_FLOAT32_C(   961.03), SIMDE_FLOAT32_C(  -517.47), SIMDE_FLOAT32_C(  -679.21),
        SIMDE_FLOAT32_C(   516.43), SIMDE_FLOAT32_C(  -666.47), SIMDE_FLOAT32_C(  -780.50), SIMDE_FLOAT32_C(  -715.59) },
      { SIMDE_FLOAT32_C(  -841.14), SIMDE_FLOAT32_C(   961.03), SIMDE_FLOAT32_C(   773.42), SIMDE_FLOAT32_C(  -679.21),
        SIMDE_FLOAT32_C(   978.48), SIMDE_FLOAT32_C(  -666.47), SIMDE_FLOAT32_C(   780.50), SIMDE_FLOAT32_C(  -980.28) } },
    { { SIMDE_FLOAT32_C(  -252.87), SIMDE_FLOAT32_C(  -649.63), SIMDE_FLOAT32_C(  -405.12), SIMDE_FLOAT32_C(  -512.69),
        SIMDE_FLOAT32_C(  -363.74), SIMDE_FLOAT32_C(   783.36), SIMDE_FLOAT32_C(   895.86), SIMDE_FLOAT32_C(  -414.64) },
      { SIMDE_FLOAT32_C(  -870.83), SIMDE_FLOAT32_C(   528.35), SIMDE_FLOAT32_C(   658.03), SIMDE_FLOAT32_C(   831.84),
        SIMDE_FLOAT32_C(    56.86), SIMDE_FLOAT32_C(   820.17), SIMDE_FLOAT32_C(  -469.42), SIMDE_FLOAT32_C(   940.44) },
      { SIMDE_FLOAT32_C(   252.87), SIMDE_FLOAT32_C(   528.35), SIMDE_FLOAT32_C(   658.03), SIMDE_FLOAT32_C(   831.84),
        SIMDE_FLOAT32_C(    56.86), SIMDE_FLOAT32_C(   820.17), SIMDE_FLOAT32_C(   895.86), SIMDE_FLOAT32_C(   940.44) } },
    { { SIMDE_FLOAT32_C(   551.78), SIMDE_FLOAT32_C(  -696.00), SIMDE_FLOAT32_C(   -77.27), SIMDE_FLOAT32_C(   530.26),
        SIMDE_FLOAT32_C(   176.97), SIMDE_FLOAT32_C(  -832.24), SIMDE_FLOAT32_C(   549.98), SIMDE_FLOAT32_C(    18.12) },
      { SIMDE_FLOAT32_C(  -871.21), SIMDE_FLOAT32_C(  -967.48), SIMDE_FLOAT32_C(   338.91), SIMDE_FLOAT32_C(   645.21),
        SIMDE_FLOAT32_C(  -633.95), SIMDE_FLOAT32_C(   558.41), SIMDE_FLOAT32_C(   929.62), SIMDE_FLOAT32_C(   113.18) },
      { SIMDE_FLOAT32_C(   551.78), SIMDE_FLOAT32_C(  -696.00), SIMDE_FLOAT32_C(   338.91), SIMDE_FLOAT32_C(   645.21),
        SIMDE_FLOAT32_C(   176.97), SIMDE_FLOAT32_C(   558.41), SIMDE_FLOAT32_C(   929.62), SIMDE_FLOAT32_C(   113.18) } },
    { { SIMDE_FLOAT32_C(   908.78), SIMDE_FLOAT32_C(  -475.50), SIMDE_FLOAT32_C(   600.49), SIMDE_FLOAT32_C(  -454.96),
        SIMDE_FLOAT32_C(  -692.13), SIMDE_FLOAT32_C(   496.35), SIMDE_FLOAT32_C(   130.40), SIMDE_FLOAT32_C(  -562.96) },
      { SIMDE_FLOAT32_C(    24.70), SIMDE_FLOAT32_C(  -211.58), SIMDE_FLOAT32_C(  -731.12), SIMDE_FLOAT32_C(  -918.44),
        SIMDE_FLOAT32_C(  -391.40), SIMDE_FLOAT32_C(  -200.55), SIMDE_FLOAT32_C(  -978.00), SIMDE_FLOAT32_C(  -839.63) },
      { SIMDE_FLOAT32_C(    24.70), SIMDE_FLOAT32_C(  -475.50), SIMDE_FLOAT32_C(   731.12), SIMDE_FLOAT32_C(  -918.44),
        SIMDE_FLOAT32_C(  -692.13), SIMDE_FLOAT32_C(   200.55), SIMDE_FLOAT32_C(   978.00), SIMDE_FLOAT32_C(  -839.63) } }
  };

  simde__m256 a, b, r;

  a = simde_mm256_loadu_ps(test_vec[0].a);
  b = simde_mm256_loadu_ps(test_vec[0].b);
  r = simde_mm256_range_ps(a, b, 11);
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[0].r), 1);

  a = simde_mm256_loadu_ps(test_vec[1].a);
  b = simde_mm256_loadu_ps(test_vec[1].b);
  r = simde_mm256_range_ps(a, b, 4);
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[1].r), 1);

  a = simde_mm256_loadu_ps(test_vec[2].a);
  b = simde_mm256_loadu_ps(test_vec[2].b);
  r = simde_mm256_range_ps(a, b, 1);
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[2].r), 1);

  a = simde_mm256_loadu_ps(test_vec[3].a);
  b = simde_mm256_loadu_ps(test_vec[3].b);
  r = simde_mm256_range_ps(a, b, 2);
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[3].r), 1);

  a = simde_mm256_loadu_ps(test_vec[4].a);
  b = simde_mm256_loadu_ps(test_vec[4].b);
  r = simde_mm256_range_ps(a, b, 3);
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[4].r), 1);

  a = simde_mm256_loadu_ps(test_vec[5].a);
  b = simde_mm256_loadu_ps(test_vec[5].b);
  r = simde_mm256_range_ps(a, b, 9);
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);

  a = simde_mm256_loadu_ps(test_vec[6].a);
  b = simde_mm256_loadu_ps(test_vec[6].b);
  r = simde_mm256_range_ps(a, b, 5);
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  a = simde_mm256_loadu_ps(test_vec[7].a);
  b = simde_mm256_loadu_ps(test_vec[7].b);
  r = simde_mm256_range_ps(a, b, 0);
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);

  simde__m256 a, b, r;

  a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm256_range_ps(a, b, 11);

  simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm256_range_ps(a, b, 4);

  simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm256_range_ps(a, b, 1);

  simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm256_range_ps(a, b, 2);

  simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm256_range_ps(a, b, 3);

  simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm256_range_ps(a, b, 9);

  simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm256_range_ps(a, b, 5);

  simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm256_range_ps(a, b, 0);

  simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm256_mask_range_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m256 src, a, b, e, r;

  src = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -736.24), SIMDE_FLOAT32_C(    60.00), SIMDE_FLOAT32_C(   504.80), SIMDE_FLOAT32_C(   362.18),
                           SIMDE_FLOAT32_C(  -740.22), SIMDE_FLOAT32_C(  -433.62), SIMDE_FLOAT32_C(   351.91), SIMDE_FLOAT32_C(   446.36));
  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -438.91), SIMDE_FLOAT32_C(  -937.86), SIMDE_FLOAT32_C(  -320.64), SIMDE_FLOAT32_C(   183.88),
                         SIMDE_FLOAT32_C(   224.60), SIMDE_FLOAT32_C(   366.59), SIMDE_FLOAT32_C(  -844.51), SIMDE_FLOAT32_C(   232.20));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -351.80), SIMDE_FLOAT32_C(  -734.27), SIMDE_FLOAT32_C(  -415.40), SIMDE_FLOAT32_C(   538.38),
                         SIMDE_FLOAT32_C(   402.58), SIMDE_FLOAT32_C(   590.16), SIMDE_FLOAT32_C(  -748.29), SIMDE_FLOAT32_C(  -569.46));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(   351.80), SIMDE_FLOAT32_C(   734.27), SIMDE_FLOAT32_C(   504.80), SIMDE_FLOAT32_C(   362.18),
                         SIMDE_FLOAT32_C(   224.60), SIMDE_FLOAT32_C(   366.59), SIMDE_FLOAT32_C(   351.91), SIMDE_FLOAT32_C(   446.36));
  r = simde_mm256_mask_range_ps(src, UINT8_C(204), a, b, INT32_C(          10));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  src = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -674.00), SIMDE_FLOAT32_C(   723.44), SIMDE_FLOAT32_C(  -217.15), SIMDE_FLOAT32_C(   759.63),
                           SIMDE_FLOAT32_C(  -628.48), SIMDE_FLOAT32_C(   336.49), SIMDE_FLOAT32_C(  -150.50), SIMDE_FLOAT32_C(   249.24));
  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -846.71), SIMDE_FLOAT32_C(   504.87), SIMDE_FLOAT32_C(   334.83), SIMDE_FLOAT32_C(  -213.29),
                         SIMDE_FLOAT32_C(   349.37), SIMDE_FLOAT32_C(  -897.38), SIMDE_FLOAT32_C(   830.80), SIMDE_FLOAT32_C(    85.61));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -160.01), SIMDE_FLOAT32_C(  -126.73), SIMDE_FLOAT32_C(   263.20), SIMDE_FLOAT32_C(   249.84),
                         SIMDE_FLOAT32_C(  -378.44), SIMDE_FLOAT32_C(  -167.35), SIMDE_FLOAT32_C(  -311.26), SIMDE_FLOAT32_C(  -440.57));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -674.00), SIMDE_FLOAT32_C(   126.73), SIMDE_FLOAT32_C(   263.20), SIMDE_FLOAT32_C(   759.63),
                         SIMDE_FLOAT32_C(   378.44), SIMDE_FLOAT32_C(   897.38), SIMDE_FLOAT32_C(  -150.50), SIMDE_FLOAT32_C(   249.24));
  r = simde_mm256_mask_range_ps(src, UINT8_C(108), a, b, INT32_C(           8));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  src = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -346.67), SIMDE_FLOAT32_C(   909.34), SIMDE_FLOAT32_C(  -819.25), SIMDE_FLOAT32_C(   316.84),
                           SIMDE_FLOAT32_C(    59.85), SIMDE_FLOAT32_C(   -68.49), SIMDE_FLOAT32_C(   424.59), SIMDE_FLOAT32_C(  -588.35));
  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -418.58), SIMDE_FLOAT32_C(   825.78), SIMDE_FLOAT32_C(   361.32), SIMDE_FLOAT32_C(  -521.20),
                         SIMDE_FLOAT32_C(   994.98), SIMDE_FLOAT32_C(  -724.29), SIMDE_FLOAT32_C(   436.17), SIMDE_FLOAT32_C(   668.97));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   598.43), SIMDE_FLOAT32_C(   -95.70), SIMDE_FLOAT32_C(  -524.33), SIMDE_FLOAT32_C(  -234.22),
                         SIMDE_FLOAT32_C(  -784.44), SIMDE_FLOAT32_C(   916.25), SIMDE_FLOAT32_C(  -387.51), SIMDE_FLOAT32_C(  -289.31));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -346.67), SIMDE_FLOAT32_C(   909.34), SIMDE_FLOAT32_C(  -819.25), SIMDE_FLOAT32_C(  -234.22),
                         SIMDE_FLOAT32_C(    59.85), SIMDE_FLOAT32_C(   916.25), SIMDE_FLOAT32_C(   424.59), SIMDE_FLOAT32_C(  -588.35));
  r = simde_mm256_mask_range_ps(src, UINT8_C( 20), a, b, INT32_C(           5));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  src = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -541.09), SIMDE_FLOAT32_C(  -581.28), SIMDE_FLOAT32_C(  -617.85), SIMDE_FLOAT32_C(   527.40),
                           SIMDE_FLOAT32_C(    -5.87), SIMDE_FLOAT32_C(   970.51), SIMDE_FLOAT32_C(  -138.37), SIMDE_FLOAT32_C(  -845.86));
  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   467.64), SIMDE_FLOAT32_C(   825.06), SIMDE_FLOAT32_C(    20.32), SIMDE_FLOAT32_C(   191.93),
                         SIMDE_FLOAT32_C(  -611.11), SIMDE_FLOAT32_C(   351.34), SIMDE_FLOAT32_C(  -360.34), SIMDE_FLOAT32_C(   735.56));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -198.47), SIMDE_FLOAT32_C(   453.56), SIMDE_FLOAT32_C(   539.66), SIMDE_FLOAT32_C(  -114.72),
                         SIMDE_FLOAT32_C(  -158.93), SIMDE_FLOAT32_C(  -171.04), SIMDE_FLOAT32_C(  -696.14), SIMDE_FLOAT32_C(    15.29));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -541.09), SIMDE_FLOAT32_C(  -581.28), SIMDE_FLOAT32_C(  -539.66), SIMDE_FLOAT32_C(   527.40),
                         SIMDE_FLOAT32_C(  -611.11), SIMDE_FLOAT32_C(  -351.34), SIMDE_FLOAT32_C(  -696.14), SIMDE_FLOAT32_C(  -735.56));
  r = simde_mm256_mask_range_ps(src, UINT8_C( 47), a, b, INT32_C(          15));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  src = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -655.05), SIMDE_FLOAT32_C(  -320.60), SIMDE_FLOAT32_C(  -186.34), SIMDE_FLOAT32_C(  -625.56),
                           SIMDE_FLOAT32_C(   817.77), SIMDE_FLOAT32_C(  -340.48), SIMDE_FLOAT32_C(   277.20), SIMDE_FLOAT32_C(  -780.66));
  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   520.44), SIMDE_FLOAT32_C(   305.37), SIMDE_FLOAT32_C(   962.07), SIMDE_FLOAT32_C(  -830.90),
                         SIMDE_FLOAT32_C(  -334.29), SIMDE_FLOAT32_C(  -773.49), SIMDE_FLOAT32_C(  -272.90), SIMDE_FLOAT32_C(  -793.20));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -206.09), SIMDE_FLOAT32_C(  -520.12), SIMDE_FLOAT32_C(   556.05), SIMDE_FLOAT32_C(   964.95),
                         SIMDE_FLOAT32_C(  -823.98), SIMDE_FLOAT32_C(  -459.24), SIMDE_FLOAT32_C(  -502.69), SIMDE_FLOAT32_C(  -649.04));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -655.05), SIMDE_FLOAT32_C(  -320.60), SIMDE_FLOAT32_C(   556.05), SIMDE_FLOAT32_C(  -830.90),
                         SIMDE_FLOAT32_C(   817.77), SIMDE_FLOAT32_C(  -340.48), SIMDE_FLOAT32_C(  -272.90), SIMDE_FLOAT32_C(  -780.66));
  r = simde_mm256_mask_range_ps(src, UINT8_C( 50), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  src = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -251.70), SIMDE_FLOAT32_C(   443.89), SIMDE_FLOAT32_C(  -929.98), SIMDE_FLOAT32_C(  -911.22),
                           SIMDE_FLOAT32_C(  -833.31), SIMDE_FLOAT32_C(   850.68), SIMDE_FLOAT32_C(  -666.44), SIMDE_FLOAT32_C(   365.16));
  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   596.25), SIMDE_FLOAT32_C(  -109.62), SIMDE_FLOAT32_C(  -226.00), SIMDE_FLOAT32_C(   369.74),
                         SIMDE_FLOAT32_C(  -836.72), SIMDE_FLOAT32_C(  -432.80), SIMDE_FLOAT32_C(   561.95), SIMDE_FLOAT32_C(   818.34));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   120.68), SIMDE_FLOAT32_C(   242.40), SIMDE_FLOAT32_C(   909.28), SIMDE_FLOAT32_C(  -420.08),
                         SIMDE_FLOAT32_C(  -254.91), SIMDE_FLOAT32_C(   558.32), SIMDE_FLOAT32_C(    59.48), SIMDE_FLOAT32_C(   439.72));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(   120.68), SIMDE_FLOAT32_C(   443.89), SIMDE_FLOAT32_C(  -226.00), SIMDE_FLOAT32_C(  -911.22),
                         SIMDE_FLOAT32_C(  -833.31), SIMDE_FLOAT32_C(  -432.80), SIMDE_FLOAT32_C(    59.48), SIMDE_FLOAT32_C(   439.72));
  r = simde_mm256_mask_range_ps(src, UINT8_C(167), a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  src = simde_mm256_set_ps(SIMDE_FLOAT32_C(   -75.46), SIMDE_FLOAT32_C(  -665.19), SIMDE_FLOAT32_C(   930.33), SIMDE_FLOAT32_C(    73.85),
                           SIMDE_FLOAT32_C(  -998.75), SIMDE_FLOAT32_C(  -434.83), SIMDE_FLOAT32_C(  -323.27), SIMDE_FLOAT32_C(   207.34));
  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   449.55), SIMDE_FLOAT32_C(  -266.16), SIMDE_FLOAT32_C(   359.25), SIMDE_FLOAT32_C(  -117.65),
                         SIMDE_FLOAT32_C(   171.89), SIMDE_FLOAT32_C(   540.92), SIMDE_FLOAT32_C(    -5.44), SIMDE_FLOAT32_C(  -576.41));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   258.14), SIMDE_FLOAT32_C(   472.40), SIMDE_FLOAT32_C(   663.27), SIMDE_FLOAT32_C(   699.83),
                         SIMDE_FLOAT32_C(  -587.08), SIMDE_FLOAT32_C(  -776.45), SIMDE_FLOAT32_C(  -896.42), SIMDE_FLOAT32_C(   522.54));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(   449.55), SIMDE_FLOAT32_C(  -665.19), SIMDE_FLOAT32_C(   930.33), SIMDE_FLOAT32_C(  -699.83),
                         SIMDE_FLOAT32_C(  -998.75), SIMDE_FLOAT32_C(  -434.83), SIMDE_FLOAT32_C(  -323.27), SIMDE_FLOAT32_C(  -522.54));
  r = simde_mm256_mask_range_ps(src, UINT8_C(145), a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  src = simde_mm256_set_ps(SIMDE_FLOAT32_C(   817.88), SIMDE_FLOAT32_C(   849.74), SIMDE_FLOAT32_C(  -141.90), SIMDE_FLOAT32_C(   252.71),
                           SIMDE_FLOAT32_C(   173.00), SIMDE_FLOAT32_C(   650.75), SIMDE_FLOAT32_C(   167.42), SIMDE_FLOAT32_C(  -947.68));
  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   386.16), SIMDE_FLOAT32_C(  -157.32), SIMDE_FLOAT32_C(   617.76), SIMDE_FLOAT32_C(   845.24),
                         SIMDE_FLOAT32_C(   848.12), SIMDE_FLOAT32_C(   194.16), SIMDE_FLOAT32_C(   748.22), SIMDE_FLOAT32_C(   -76.41));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   398.14), SIMDE_FLOAT32_C(   627.07), SIMDE_FLOAT32_C(  -732.06), SIMDE_FLOAT32_C(   174.59),
                         SIMDE_FLOAT32_C(   523.49), SIMDE_FLOAT32_C(  -254.59), SIMDE_FLOAT32_C(   725.04), SIMDE_FLOAT32_C(  -210.35));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(   817.88), SIMDE_FLOAT32_C(   849.74), SIMDE_FLOAT32_C(  -141.90), SIMDE_FLOAT32_C(   174.59),
                         SIMDE_FLOAT32_C(   523.49), SIMDE_FLOAT32_C(   254.59), SIMDE_FLOAT32_C(   725.04), SIMDE_FLOAT32_C(  -210.35));
  r = simde_mm256_mask_range_ps(src, UINT8_C( 31), a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m256 r;
    SIMDE_CONSTIFY_16_(simde_mm256_mask_range_ps, r, simde_mm256_setzero_ps(), imm8, src, k, a, b);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_range_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m256 a, b, e, r;

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   378.60), SIMDE_FLOAT32_C(   120.52), SIMDE_FLOAT32_C(   752.45), SIMDE_FLOAT32_C(  -794.41),
                         SIMDE_FLOAT32_C(   469.76), SIMDE_FLOAT32_C(  -414.96), SIMDE_FLOAT32_C(  -846.73), SIMDE_FLOAT32_C(    61.40));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -967.88), SIMDE_FLOAT32_C(  -428.74), SIMDE_FLOAT32_C(  -848.08), SIMDE_FLOAT32_C(  -162.04),
                         SIMDE_FLOAT32_C(  -176.95), SIMDE_FLOAT32_C(   228.33), SIMDE_FLOAT32_C(   978.61), SIMDE_FLOAT32_C(     5.16));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   428.74), SIMDE_FLOAT32_C(   848.08), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   469.76), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00));
  r = simde_mm256_maskz_range_ps(UINT8_C(104), a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   742.35), SIMDE_FLOAT32_C(   963.02), SIMDE_FLOAT32_C(  -451.94), SIMDE_FLOAT32_C(  -432.24),
                         SIMDE_FLOAT32_C(  -560.47), SIMDE_FLOAT32_C(   802.66), SIMDE_FLOAT32_C(  -157.27), SIMDE_FLOAT32_C(   649.88));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   502.01), SIMDE_FLOAT32_C(   650.14), SIMDE_FLOAT32_C(  -798.11), SIMDE_FLOAT32_C(   -83.02),
                         SIMDE_FLOAT32_C(   496.87), SIMDE_FLOAT32_C(   140.49), SIMDE_FLOAT32_C(   590.08), SIMDE_FLOAT32_C(  -183.99));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(   742.35), SIMDE_FLOAT32_C(   963.02), SIMDE_FLOAT32_C(  -451.94), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   590.08), SIMDE_FLOAT32_C(     0.00));
  r = simde_mm256_maskz_range_ps(UINT8_C(226), a, b, INT32_C(           5));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   608.75), SIMDE_FLOAT32_C(    82.67), SIMDE_FLOAT32_C(  -537.34), SIMDE_FLOAT32_C(  -229.21),
                         SIMDE_FLOAT32_C(  -740.37), SIMDE_FLOAT32_C(   234.33), SIMDE_FLOAT32_C(  -207.83), SIMDE_FLOAT32_C(   254.46));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   873.09), SIMDE_FLOAT32_C(   457.35), SIMDE_FLOAT32_C(   290.75), SIMDE_FLOAT32_C(  -929.56),
                         SIMDE_FLOAT32_C(  -385.38), SIMDE_FLOAT32_C(   640.87), SIMDE_FLOAT32_C(   653.94), SIMDE_FLOAT32_C(  -385.42));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    82.67), SIMDE_FLOAT32_C(   290.75), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   234.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   254.46));
  r = simde_mm256_maskz_range_ps(UINT8_C(101), a, b, INT32_C(          10));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -799.64), SIMDE_FLOAT32_C(  -265.96), SIMDE_FLOAT32_C(   -92.05), SIMDE_FLOAT32_C(   283.38),
                         SIMDE_FLOAT32_C(   237.17), SIMDE_FLOAT32_C(   767.46), SIMDE_FLOAT32_C(   693.30), SIMDE_FLOAT32_C(  -578.84));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   474.25), SIMDE_FLOAT32_C(   573.67), SIMDE_FLOAT32_C(   -43.17), SIMDE_FLOAT32_C(  -760.08),
                         SIMDE_FLOAT32_C(  -218.50), SIMDE_FLOAT32_C(   702.37), SIMDE_FLOAT32_C(  -615.82), SIMDE_FLOAT32_C(   109.84));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -799.64), SIMDE_FLOAT32_C(  -573.67), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -760.08),
                         SIMDE_FLOAT32_C(  -237.17), SIMDE_FLOAT32_C(  -767.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00));
  r = simde_mm256_maskz_range_ps(UINT8_C(220), a, b, INT32_C(          15));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -976.49), SIMDE_FLOAT32_C(   166.11), SIMDE_FLOAT32_C(   594.07), SIMDE_FLOAT32_C(   953.07),
                         SIMDE_FLOAT32_C(  -448.51), SIMDE_FLOAT32_C(   953.20), SIMDE_FLOAT32_C(  -700.87), SIMDE_FLOAT32_C(   936.91));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -583.96), SIMDE_FLOAT32_C(  -691.59), SIMDE_FLOAT32_C(  -682.24), SIMDE_FLOAT32_C(  -351.42),
                         SIMDE_FLOAT32_C(  -384.89), SIMDE_FLOAT32_C(   896.61), SIMDE_FLOAT32_C(  -376.54), SIMDE_FLOAT32_C(  -115.17));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   953.07),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   953.20), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   936.91));
  r = simde_mm256_maskz_range_ps(UINT8_C( 21), a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   -86.92), SIMDE_FLOAT32_C(   215.33), SIMDE_FLOAT32_C(   494.51), SIMDE_FLOAT32_C(  -326.84),
                         SIMDE_FLOAT32_C(  -566.17), SIMDE_FLOAT32_C(   792.14), SIMDE_FLOAT32_C(  -711.02), SIMDE_FLOAT32_C(   323.99));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(    86.65), SIMDE_FLOAT32_C(   966.93), SIMDE_FLOAT32_C(  -675.77), SIMDE_FLOAT32_C(   133.45),
                         SIMDE_FLOAT32_C(   667.80), SIMDE_FLOAT32_C(  -612.68), SIMDE_FLOAT32_C(  -211.00), SIMDE_FLOAT32_C(  -548.66));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -675.77), SIMDE_FLOAT32_C(  -326.84),
                         SIMDE_FLOAT32_C(  -566.17), SIMDE_FLOAT32_C(  -612.68), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -548.66));
  r = simde_mm256_maskz_range_ps(UINT8_C( 61), a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   313.87), SIMDE_FLOAT32_C(  -819.34), SIMDE_FLOAT32_C(   840.12), SIMDE_FLOAT32_C(  -334.71),
                         SIMDE_FLOAT32_C(   565.55), SIMDE_FLOAT32_C(   943.51), SIMDE_FLOAT32_C(  -958.17), SIMDE_FLOAT32_C(  -319.28));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   872.99), SIMDE_FLOAT32_C(  -998.21), SIMDE_FLOAT32_C(    53.90), SIMDE_FLOAT32_C(  -919.15),
                         SIMDE_FLOAT32_C(   712.82), SIMDE_FLOAT32_C(   729.91), SIMDE_FLOAT32_C(  -510.94), SIMDE_FLOAT32_C(  -842.12));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -872.99), SIMDE_FLOAT32_C(  -819.34), SIMDE_FLOAT32_C(  -840.12), SIMDE_FLOAT32_C(  -334.71),
                         SIMDE_FLOAT32_C(  -712.82), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -319.28));
  r = simde_mm256_maskz_range_ps(UINT8_C(249), a, b, INT32_C(          13));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -374.49), SIMDE_FLOAT32_C(   486.64), SIMDE_FLOAT32_C(   975.36), SIMDE_FLOAT32_C(   492.06),
                         SIMDE_FLOAT32_C(   818.84), SIMDE_FLOAT32_C(   588.03), SIMDE_FLOAT32_C(  -296.94), SIMDE_FLOAT32_C(   367.50));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   317.09), SIMDE_FLOAT32_C(   217.13), SIMDE_FLOAT32_C(  -607.12), SIMDE_FLOAT32_C(   373.58),
                         SIMDE_FLOAT32_C(   175.31), SIMDE_FLOAT32_C(   712.16), SIMDE_FLOAT32_C(   453.57), SIMDE_FLOAT32_C(  -700.41));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -317.09), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   607.12), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   175.31), SIMDE_FLOAT32_C(   588.03), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   367.50));
  r = simde_mm256_maskz_range_ps(UINT8_C(173), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x8(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 b = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m256 r;
    SIMDE_CONSTIFY_16_(simde_mm256_maskz_range_ps, r, simde_mm256_setzero_ps(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_range_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   103.45), SIMDE_FLOAT32_C(   -55.27), SIMDE_FLOAT32_C(   690.63), SIMDE_FLOAT32_C(  -719.57),
        SIMDE_FLOAT32_C(   112.48), SIMDE_FLOAT32_C(   240.61), SIMDE_FLOAT32_C(   298.55), SIMDE_FLOAT32_C(   241.27),
        SIMDE_FLOAT32_C(   273.12), SIMDE_FLOAT32_C(  -362.54), SIMDE_FLOAT32_C(  -113.52), SIMDE_FLOAT32_C(   639.17),
        SIMDE_FLOAT32_C(  -804.13), SIMDE_FLOAT32_C(  -183.90), SIMDE_FLOAT32_C(  -247.65), SIMDE_FLOAT32_C(  -895.35) },
      { SIMDE_FLOAT32_C(   340.61), SIMDE_FLOAT32_C(  -647.16), SIMDE_FLOAT32_C(  -350.31), SIMDE_FLOAT32_C(   648.47),
        SIMDE_FLOAT32_C(   849.19), SIMDE_FLOAT32_C(   780.09), SIMDE_FLOAT32_C(  -914.49), SIMDE_FLOAT32_C(  -126.12),
        SIMDE_FLOAT32_C(  -431.49), SIMDE_FLOAT32_C(  -645.61), SIMDE_FLOAT32_C(   -44.56), SIMDE_FLOAT32_C(   177.10),
        SIMDE_FLOAT32_C(   153.84), SIMDE_FLOAT32_C(   -22.56), SIMDE_FLOAT32_C(   337.47), SIMDE_FLOAT32_C(  -742.70) },
      { SIMDE_FLOAT32_C(   340.61), SIMDE_FLOAT32_C(   647.16), SIMDE_FLOAT32_C(   690.63), SIMDE_FLOAT32_C(   719.57),
        SIMDE_FLOAT32_C(   849.19), SIMDE_FLOAT32_C(   780.09), SIMDE_FLOAT32_C(   914.49), SIMDE_FLOAT32_C(   241.27),
        SIMDE_FLOAT32_C(   431.49), SIMDE_FLOAT32_C(   645.61), SIMDE_FLOAT32_C(   113.52), SIMDE_FLOAT32_C(   639.17),
        SIMDE_FLOAT32_C(   804.13), SIMDE_FLOAT32_C(   183.90), SIMDE_FLOAT32_C(   337.47), SIMDE_FLOAT32_C(   895.35) } },
    { { SIMDE_FLOAT32_C(   922.17), SIMDE_FLOAT32_C(    28.10), SIMDE_FLOAT32_C(  -462.28), SIMDE_FLOAT32_C(    34.65),
        SIMDE_FLOAT32_C(  -731.29), SIMDE_FLOAT32_C(   836.27), SIMDE_FLOAT32_C(  -724.08), SIMDE_FLOAT32_C(   541.84),
        SIMDE_FLOAT32_C(  -526.27), SIMDE_FLOAT32_C(   162.40), SIMDE_FLOAT32_C(   181.01), SIMDE_FLOAT32_C(  -330.41),
        SIMDE_FLOAT32_C(   978.50), SIMDE_FLOAT32_C(   933.36), SIMDE_FLOAT32_C(  -225.75), SIMDE_FLOAT32_C(   319.11) },
      { SIMDE_FLOAT32_C(  -713.80), SIMDE_FLOAT32_C(   423.94), SIMDE_FLOAT32_C(   -32.42), SIMDE_FLOAT32_C(  -864.61),
        SIMDE_FLOAT32_C(   204.02), SIMDE_FLOAT32_C(    53.09), SIMDE_FLOAT32_C(     9.27), SIMDE_FLOAT32_C(   772.53),
        SIMDE_FLOAT32_C(   407.48), SIMDE_FLOAT32_C(   964.71), SIMDE_FLOAT32_C(   -50.37), SIMDE_FLOAT32_C(  -438.68),
        SIMDE_FLOAT32_C(   -57.85), SIMDE_FLOAT32_C(  -712.89), SIMDE_FLOAT32_C(  -181.38), SIMDE_FLOAT32_C(  -135.68) },
      { SIMDE_FLOAT32_C(  -713.80), SIMDE_FLOAT32_C(    28.10), SIMDE_FLOAT32_C(  -462.28), SIMDE_FLOAT32_C(  -864.61),
        SIMDE_FLOAT32_C(  -731.29), SIMDE_FLOAT32_C(    53.09), SIMDE_FLOAT32_C(  -724.08), SIMDE_FLOAT32_C(   541.84),
        SIMDE_FLOAT32_C(  -526.27), SIMDE_FLOAT32_C(   162.40), SIMDE_FLOAT32_C(   -50.37), SIMDE_FLOAT32_C(  -438.68),
        SIMDE_FLOAT32_C(   -57.85), SIMDE_FLOAT32_C(  -712.89), SIMDE_FLOAT32_C(  -225.75), SIMDE_FLOAT32_C(  -135.68) } },
    { { SIMDE_FLOAT32_C(   315.21), SIMDE_FLOAT32_C(   356.35), SIMDE_FLOAT32_C(   898.97), SIMDE_FLOAT32_C(   583.92),
        SIMDE_FLOAT32_C(   192.62), SIMDE_FLOAT32_C(  -825.11), SIMDE_FLOAT32_C(   125.76), SIMDE_FLOAT32_C(   666.34),
        SIMDE_FLOAT32_C(   337.29), SIMDE_FLOAT32_C(  -693.23), SIMDE_FLOAT32_C(  -664.06), SIMDE_FLOAT32_C(   315.79),
        SIMDE_FLOAT32_C(  -759.87), SIMDE_FLOAT32_C(   110.18), SIMDE_FLOAT32_C(  -365.10), SIMDE_FLOAT32_C(  -473.67) },
      { SIMDE_FLOAT32_C(  -465.88), SIMDE_FLOAT32_C(   602.48), SIMDE_FLOAT32_C(  -338.28), SIMDE_FLOAT32_C(   738.14),
        SIMDE_FLOAT32_C(  -344.43), SIMDE_FLOAT32_C(   670.99), SIMDE_FLOAT32_C(   510.67), SIMDE_FLOAT32_C(  -936.95),
        SIMDE_FLOAT32_C(   635.70), SIMDE_FLOAT32_C(  -539.70), SIMDE_FLOAT32_C(  -375.62), SIMDE_FLOAT32_C(  -422.14),
        SIMDE_FLOAT32_C(  -252.59), SIMDE_FLOAT32_C(   443.00), SIMDE_FLOAT32_C(   442.18), SIMDE_FLOAT32_C(  -937.38) },
      { SIMDE_FLOAT32_C(   315.21), SIMDE_FLOAT32_C(   602.48), SIMDE_FLOAT32_C(   898.97), SIMDE_FLOAT32_C(   738.14),
        SIMDE_FLOAT32_C(   192.62), SIMDE_FLOAT32_C(  -670.99), SIMDE_FLOAT32_C(   510.67), SIMDE_FLOAT32_C(   666.34),
        SIMDE_FLOAT32_C(   635.70), SIMDE_FLOAT32_C(  -539.70), SIMDE_FLOAT32_C(  -375.62), SIMDE_FLOAT32_C(   315.79),
        SIMDE_FLOAT32_C(  -252.59), SIMDE_FLOAT32_C(   443.00), SIMDE_FLOAT32_C(  -442.18), SIMDE_FLOAT32_C(  -473.67) } },
    { { SIMDE_FLOAT32_C(  -200.66), SIMDE_FLOAT32_C(   341.14), SIMDE_FLOAT32_C(   646.55), SIMDE_FLOAT32_C(   991.96),
        SIMDE_FLOAT32_C(   516.03), SIMDE_FLOAT32_C(  -227.69), SIMDE_FLOAT32_C(   658.30), SIMDE_FLOAT32_C(  -146.69),
        SIMDE_FLOAT32_C(    79.08), SIMDE_FLOAT32_C(   994.24), SIMDE_FLOAT32_C(  -830.90), SIMDE_FLOAT32_C(   319.21),
        SIMDE_FLOAT32_C(   104.42), SIMDE_FLOAT32_C(  -196.00), SIMDE_FLOAT32_C(   845.55), SIMDE_FLOAT32_C(   638.54) },
      { SIMDE_FLOAT32_C(  -593.52), SIMDE_FLOAT32_C(  -492.73), SIMDE_FLOAT32_C(   376.68), SIMDE_FLOAT32_C(    62.05),
        SIMDE_FLOAT32_C(  -821.74), SIMDE_FLOAT32_C(  -112.65), SIMDE_FLOAT32_C(   125.10), SIMDE_FLOAT32_C(   813.97),
        SIMDE_FLOAT32_C(   347.66), SIMDE_FLOAT32_C(   749.48), SIMDE_FLOAT32_C(  -608.18), SIMDE_FLOAT32_C(  -904.93),
        SIMDE_FLOAT32_C(   192.48), SIMDE_FLOAT32_C(   834.00), SIMDE_FLOAT32_C(  -842.31), SIMDE_FLOAT32_C(   991.82) },
      { SIMDE_FLOAT32_C(  -200.66), SIMDE_FLOAT32_C(   341.14), SIMDE_FLOAT32_C(   376.68), SIMDE_FLOAT32_C(    62.05),
        SIMDE_FLOAT32_C(   516.03), SIMDE_FLOAT32_C(  -112.65), SIMDE_FLOAT32_C(   125.10), SIMDE_FLOAT32_C(  -146.69),
        SIMDE_FLOAT32_C(    79.08), SIMDE_FLOAT32_C(   749.48), SIMDE_FLOAT32_C(  -608.18), SIMDE_FLOAT32_C(   319.21),
        SIMDE_FLOAT32_C(   104.42), SIMDE_FLOAT32_C(  -196.00), SIMDE_FLOAT32_C(   842.31), SIMDE_FLOAT32_C(   638.54) } },
    { { SIMDE_FLOAT32_C(   175.14), SIMDE_FLOAT32_C(   804.24), SIMDE_FLOAT32_C(   983.78), SIMDE_FLOAT32_C(  -308.83),
        SIMDE_FLOAT32_C(  -423.45), SIMDE_FLOAT32_C(   642.08), SIMDE_FLOAT32_C(   544.49), SIMDE_FLOAT32_C(   655.63),
        SIMDE_FLOAT32_C(   636.32), SIMDE_FLOAT32_C(   713.59), SIMDE_FLOAT32_C(   -25.16), SIMDE_FLOAT32_C(  -259.25),
        SIMDE_FLOAT32_C(  -482.41), SIMDE_FLOAT32_C(  -179.61), SIMDE_FLOAT32_C(  -620.71), SIMDE_FLOAT32_C(   -75.93) },
      { SIMDE_FLOAT32_C(   327.66), SIMDE_FLOAT32_C(   755.97), SIMDE_FLOAT32_C(   986.12), SIMDE_FLOAT32_C(   505.92),
        SIMDE_FLOAT32_C(  -356.68), SIMDE_FLOAT32_C(   111.23), SIMDE_FLOAT32_C(   319.89), SIMDE_FLOAT32_C(   990.98),
        SIMDE_FLOAT32_C(  -139.29), SIMDE_FLOAT32_C(   711.72), SIMDE_FLOAT32_C(  -913.95), SIMDE_FLOAT32_C(  -946.81),
        SIMDE_FLOAT32_C(   545.72), SIMDE_FLOAT32_C(  -756.26), SIMDE_FLOAT32_C(  -954.99), SIMDE_FLOAT32_C(  -279.14) },
      { SIMDE_FLOAT32_C(   327.66), SIMDE_FLOAT32_C(   804.24), SIMDE_FLOAT32_C(   986.12), SIMDE_FLOAT32_C(  -505.92),
        SIMDE_FLOAT32_C(  -423.45), SIMDE_FLOAT32_C(   642.08), SIMDE_FLOAT32_C(   544.49), SIMDE_FLOAT32_C(   990.98),
        SIMDE_FLOAT32_C(   636.32), SIMDE_FLOAT32_C(   713.59), SIMDE_FLOAT32_C(  -913.95), SIMDE_FLOAT32_C(  -946.81),
        SIMDE_FLOAT32_C(  -545.72), SIMDE_FLOAT32_C(  -756.26), SIMDE_FLOAT32_C(  -954.99), SIMDE_FLOAT32_C(  -279.14) } },
    { { SIMDE_FLOAT32_C(  -952.02), SIMDE_FLOAT32_C(  -971.20), SIMDE_FLOAT32_C(   412.03), SIMDE_FLOAT32_C(  -375.47),
        SIMDE_FLOAT32_C(   670.88), SIMDE_FLOAT32_C(   -43.48), SIMDE_FLOAT32_C(  -719.85), SIMDE_FLOAT32_C(   307.20),
        SIMDE_FLOAT32_C(  -329.89), SIMDE_FLOAT32_C(   255.00), SIMDE_FLOAT32_C(  -952.05), SIMDE_FLOAT32_C(   187.70),
        SIMDE_FLOAT32_C(  -924.61), SIMDE_FLOAT32_C(  -572.77), SIMDE_FLOAT32_C(  -888.23), SIMDE_FLOAT32_C(   403.05) },
      { SIMDE_FLOAT32_C(  -816.80), SIMDE_FLOAT32_C(  -902.10), SIMDE_FLOAT32_C(   -91.02), SIMDE_FLOAT32_C(  -173.47),
        SIMDE_FLOAT32_C(   209.12), SIMDE_FLOAT32_C(  -771.13), SIMDE_FLOAT32_C(  -182.49), SIMDE_FLOAT32_C(  -930.17),
        SIMDE_FLOAT32_C(   940.59), SIMDE_FLOAT32_C(   -96.45), SIMDE_FLOAT32_C(  -876.98), SIMDE_FLOAT32_C(   486.30),
        SIMDE_FLOAT32_C(   147.29), SIMDE_FLOAT32_C(  -831.96), SIMDE_FLOAT32_C(  -792.84), SIMDE_FLOAT32_C(   195.27) },
      { SIMDE_FLOAT32_C(   816.80), SIMDE_FLOAT32_C(   902.10), SIMDE_FLOAT32_C(   412.03), SIMDE_FLOAT32_C(   173.47),
        SIMDE_FLOAT32_C(   670.88), SIMDE_FLOAT32_C(    43.48), SIMDE_FLOAT32_C(   182.49), SIMDE_FLOAT32_C(   307.20),
        SIMDE_FLOAT32_C(   940.59), SIMDE_FLOAT32_C(   255.00), SIMDE_FLOAT32_C(   876.98), SIMDE_FLOAT32_C(   486.30),
        SIMDE_FLOAT32_C(   147.29), SIMDE_FLOAT32_C(   572.77), SIMDE_FLOAT32_C(   792.84), SIMDE_FLOAT32_C(   403.05) } },
    { { SIMDE_FLOAT32_C(  -803.17), SIMDE_FLOAT32_C(   619.20), SIMDE_FLOAT32_C(   819.80), SIMDE_FLOAT32_C(   867.71),
        SIMDE_FLOAT32_C(  -424.28), SIMDE_FLOAT32_C(  -900.05), SIMDE_FLOAT32_C(   174.91), SIMDE_FLOAT32_C(   245.83),
        SIMDE_FLOAT32_C(   354.95), SIMDE_FLOAT32_C(   222.86), SIMDE_FLOAT32_C(  -566.47), SIMDE_FLOAT32_C(   430.34),
        SIMDE_FLOAT32_C(   650.10), SIMDE_FLOAT32_C(  -454.70), SIMDE_FLOAT32_C(  -166.61), SIMDE_FLOAT32_C(   833.30) },
      { SIMDE_FLOAT32_C(  -356.80), SIMDE_FLOAT32_C(   742.37), SIMDE_FLOAT32_C(  -340.17), SIMDE_FLOAT32_C(   852.32),
        SIMDE_FLOAT32_C(   971.24), SIMDE_FLOAT32_C(   477.33), SIMDE_FLOAT32_C(   922.16), SIMDE_FLOAT32_C(   911.83),
        SIMDE_FLOAT32_C(  -619.11), SIMDE_FLOAT32_C(  -954.82), SIMDE_FLOAT32_C(   398.14), SIMDE_FLOAT32_C(   528.18),
        SIMDE_FLOAT32_C(  -786.79), SIMDE_FLOAT32_C(   605.30), SIMDE_FLOAT32_C(  -276.55), SIMDE_FLOAT32_C(  -589.95) },
      { SIMDE_FLOAT32_C(  -356.80), SIMDE_FLOAT32_C(   742.37), SIMDE_FLOAT32_C(   819.80), SIMDE_FLOAT32_C(   867.71),
        SIMDE_FLOAT32_C(   971.24), SIMDE_FLOAT32_C(   477.33), SIMDE_FLOAT32_C(   922.16), SIMDE_FLOAT32_C(   911.83),
        SIMDE_FLOAT32_C(   354.95), SIMDE_FLOAT32_C(   222.86), SIMDE_FLOAT32_C(   398.14), SIMDE_FLOAT32_C(   528.18),
        SIMDE_FLOAT32_C(   650.10), SIMDE_FLOAT32_C(   605.30), SIMDE_FLOAT32_C(  -166.61), SIMDE_FLOAT32_C(   833.30) } },
    { { SIMDE_FLOAT32_C(   224.50), SIMDE_FLOAT32_C(  -456.75), SIMDE_FLOAT32_C(  -722.24), SIMDE_FLOAT32_C(   800.22),
        SIMDE_FLOAT32_C(  -356.80), SIMDE_FLOAT32_C(   452.67), SIMDE_FLOAT32_C(    46.04), SIMDE_FLOAT32_C(   998.15),
        SIMDE_FLOAT32_C(  -324.47), SIMDE_FLOAT32_C(   479.57), SIMDE_FLOAT32_C(   428.49), SIMDE_FLOAT32_C(  -674.37),
        SIMDE_FLOAT32_C(  -975.12), SIMDE_FLOAT32_C(  -738.12), SIMDE_FLOAT32_C(  -841.07), SIMDE_FLOAT32_C(  -331.93) },
      { SIMDE_FLOAT32_C(  -995.74), SIMDE_FLOAT32_C(  -181.24), SIMDE_FLOAT32_C(  -479.60), SIMDE_FLOAT32_C(   975.50),
        SIMDE_FLOAT32_C(  -703.91), SIMDE_FLOAT32_C(  -557.45), SIMDE_FLOAT32_C(   887.33), SIMDE_FLOAT32_C(  -323.02),
        SIMDE_FLOAT32_C(  -512.27), SIMDE_FLOAT32_C(   285.47), SIMDE_FLOAT32_C(  -794.84), SIMDE_FLOAT32_C(  -299.05),
        SIMDE_FLOAT32_C(  -109.23), SIMDE_FLOAT32_C(   -71.39), SIMDE_FLOAT32_C(   110.99), SIMDE_FLOAT32_C(  -884.73) },
      { SIMDE_FLOAT32_C(   995.74), SIMDE_FLOAT32_C(  -456.75), SIMDE_FLOAT32_C(  -722.24), SIMDE_FLOAT32_C(   800.22),
        SIMDE_FLOAT32_C(  -703.91), SIMDE_FLOAT32_C(   557.45), SIMDE_FLOAT32_C(    46.04), SIMDE_FLOAT32_C(   323.02),
        SIMDE_FLOAT32_C(  -512.27), SIMDE_FLOAT32_C(   285.47), SIMDE_FLOAT32_C(   794.84), SIMDE_FLOAT32_C(  -674.37),
        SIMDE_FLOAT32_C(  -975.12), SIMDE_FLOAT32_C(  -738.12), SIMDE_FLOAT32_C(  -841.07), SIMDE_FLOAT32_C(  -884.73) } }
  };

  simde__m512 a, b, r;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  b = simde_mm512_loadu_ps(test_vec[0].b);
  r = simde_mm512_range_ps(a, b, 11);
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  b = simde_mm512_loadu_ps(test_vec[1].b);
  r = simde_mm512_range_ps(a, b, 4);
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  b = simde_mm512_loadu_ps(test_vec[2].b);
  r = simde_mm512_range_ps(a, b, 1);
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  b = simde_mm512_loadu_ps(test_vec[3].b);
  r = simde_mm512_range_ps(a, b, 2);
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  b = simde_mm512_loadu_ps(test_vec[4].b);
  r = simde_mm512_range_ps(a, b, 3);
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  b = simde_mm512_loadu_ps(test_vec[5].b);
  r = simde_mm512_range_ps(a, b, 9);
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  b = simde_mm512_loadu_ps(test_vec[6].b);
  r = simde_mm512_range_ps(a, b, 5);
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  b = simde_mm512_loadu_ps(test_vec[7].b);
  r = simde_mm512_range_ps(a, b, 0);
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512 a, b, r;

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm512_range_ps(a, b, 11);

  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm512_range_ps(a, b, 4);

  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm512_range_ps(a, b, 1);

  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm512_range_ps(a, b, 2);

  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm512_range_ps(a, b, 3);

  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm512_range_ps(a, b, 9);

  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm512_range_ps(a, b, 5);

  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  r = simde_mm512_range_ps(a, b, 0);

  simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_mask_range_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m512 src, a, b, e, r;

  src = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -829.11), SIMDE_FLOAT32_C(   949.49), SIMDE_FLOAT32_C(   704.66), SIMDE_FLOAT32_C(   467.83),
                           SIMDE_FLOAT32_C(  -418.01), SIMDE_FLOAT32_C(    29.71), SIMDE_FLOAT32_C(   980.09), SIMDE_FLOAT32_C(  -291.00),
                           SIMDE_FLOAT32_C(    27.91), SIMDE_FLOAT32_C(   -73.81), SIMDE_FLOAT32_C(  -371.85), SIMDE_FLOAT32_C(   315.10),
                           SIMDE_FLOAT32_C(   196.29), SIMDE_FLOAT32_C(  -860.91), SIMDE_FLOAT32_C(   157.21), SIMDE_FLOAT32_C(   882.42));
  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -509.00), SIMDE_FLOAT32_C(  -443.58), SIMDE_FLOAT32_C(   842.51), SIMDE_FLOAT32_C(  -648.08),
                         SIMDE_FLOAT32_C(   399.21), SIMDE_FLOAT32_C(   960.09), SIMDE_FLOAT32_C(  -606.51), SIMDE_FLOAT32_C(  -917.89),
                         SIMDE_FLOAT32_C(  -257.05), SIMDE_FLOAT32_C(  -999.39), SIMDE_FLOAT32_C(  -291.46), SIMDE_FLOAT32_C(   567.65),
                         SIMDE_FLOAT32_C(  -711.55), SIMDE_FLOAT32_C(   254.97), SIMDE_FLOAT32_C(   268.06), SIMDE_FLOAT32_C(   662.95));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(   246.74), SIMDE_FLOAT32_C(  -872.05), SIMDE_FLOAT32_C(   -73.51), SIMDE_FLOAT32_C(   583.79),
                         SIMDE_FLOAT32_C(  -640.37), SIMDE_FLOAT32_C(   633.79), SIMDE_FLOAT32_C(   412.91), SIMDE_FLOAT32_C(  -589.86),
                         SIMDE_FLOAT32_C(   929.13), SIMDE_FLOAT32_C(   945.08), SIMDE_FLOAT32_C(   828.15), SIMDE_FLOAT32_C(  -100.58),
                         SIMDE_FLOAT32_C(   964.99), SIMDE_FLOAT32_C(   119.15), SIMDE_FLOAT32_C(   871.51), SIMDE_FLOAT32_C(    38.79));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -509.00), SIMDE_FLOAT32_C(   949.49), SIMDE_FLOAT32_C(   842.51), SIMDE_FLOAT32_C(   467.83),
                         SIMDE_FLOAT32_C(   640.37), SIMDE_FLOAT32_C(   960.09), SIMDE_FLOAT32_C(   980.09), SIMDE_FLOAT32_C(  -917.89),
                         SIMDE_FLOAT32_C(  -929.13), SIMDE_FLOAT32_C(   -73.81), SIMDE_FLOAT32_C(  -371.85), SIMDE_FLOAT32_C(   315.10),
                         SIMDE_FLOAT32_C(  -964.99), SIMDE_FLOAT32_C(   254.97), SIMDE_FLOAT32_C(   871.51), SIMDE_FLOAT32_C(   882.42));
  r = simde_mm512_mask_range_ps(src, UINT16_C(44430), a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  src = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -999.29), SIMDE_FLOAT32_C(   346.54), SIMDE_FLOAT32_C(  -227.79), SIMDE_FLOAT32_C(  -870.81),
                           SIMDE_FLOAT32_C(  -692.26), SIMDE_FLOAT32_C(  -718.79), SIMDE_FLOAT32_C(   572.78), SIMDE_FLOAT32_C(  -534.76),
                           SIMDE_FLOAT32_C(   929.29), SIMDE_FLOAT32_C(  -826.43), SIMDE_FLOAT32_C(  -494.85), SIMDE_FLOAT32_C(   535.80),
                           SIMDE_FLOAT32_C(  -908.54), SIMDE_FLOAT32_C(   762.20), SIMDE_FLOAT32_C(   535.19), SIMDE_FLOAT32_C(   382.92));
  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(   346.30), SIMDE_FLOAT32_C(    35.23), SIMDE_FLOAT32_C(  -999.85), SIMDE_FLOAT32_C(   584.10),
                         SIMDE_FLOAT32_C(   500.04), SIMDE_FLOAT32_C(  -382.77), SIMDE_FLOAT32_C(   389.55), SIMDE_FLOAT32_C(  -746.70),
                         SIMDE_FLOAT32_C(  -510.72), SIMDE_FLOAT32_C(  -536.94), SIMDE_FLOAT32_C(  -330.49), SIMDE_FLOAT32_C(  -870.35),
                         SIMDE_FLOAT32_C(  -170.74), SIMDE_FLOAT32_C(   256.60), SIMDE_FLOAT32_C(   719.51), SIMDE_FLOAT32_C(   -99.87));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -132.01), SIMDE_FLOAT32_C(   282.49), SIMDE_FLOAT32_C(   445.10), SIMDE_FLOAT32_C(   967.86),
                         SIMDE_FLOAT32_C(   970.96), SIMDE_FLOAT32_C(   553.74), SIMDE_FLOAT32_C(   967.15), SIMDE_FLOAT32_C(  -375.57),
                         SIMDE_FLOAT32_C(  -218.47), SIMDE_FLOAT32_C(   837.96), SIMDE_FLOAT32_C(  -683.31), SIMDE_FLOAT32_C(  -499.68),
                         SIMDE_FLOAT32_C(  -734.82), SIMDE_FLOAT32_C(   851.45), SIMDE_FLOAT32_C(  -428.97), SIMDE_FLOAT32_C(  -908.39));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(   132.01), SIMDE_FLOAT32_C(    35.23), SIMDE_FLOAT32_C(  -227.79), SIMDE_FLOAT32_C(  -870.81),
                         SIMDE_FLOAT32_C(  -692.26), SIMDE_FLOAT32_C(  -718.79), SIMDE_FLOAT32_C(   572.78), SIMDE_FLOAT32_C(  -375.57),
                         SIMDE_FLOAT32_C(  -218.47), SIMDE_FLOAT32_C(  -826.43), SIMDE_FLOAT32_C(  -494.85), SIMDE_FLOAT32_C(  -499.68),
                         SIMDE_FLOAT32_C(  -170.74), SIMDE_FLOAT32_C(   256.60), SIMDE_FLOAT32_C(   428.97), SIMDE_FLOAT32_C(   382.92));
  r = simde_mm512_mask_range_ps(src, UINT16_C(49566), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  src = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -431.81), SIMDE_FLOAT32_C(  -507.46), SIMDE_FLOAT32_C(  -519.75), SIMDE_FLOAT32_C(   997.16),
                           SIMDE_FLOAT32_C(  -599.07), SIMDE_FLOAT32_C(   133.95), SIMDE_FLOAT32_C(   -38.07), SIMDE_FLOAT32_C(  -599.22),
                           SIMDE_FLOAT32_C(   549.85), SIMDE_FLOAT32_C(   461.89), SIMDE_FLOAT32_C(   783.55), SIMDE_FLOAT32_C(  -839.70),
                           SIMDE_FLOAT32_C(   208.59), SIMDE_FLOAT32_C(   294.27), SIMDE_FLOAT32_C(   697.25), SIMDE_FLOAT32_C(  -460.91));
  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(   307.78), SIMDE_FLOAT32_C(    95.93), SIMDE_FLOAT32_C(    65.35), SIMDE_FLOAT32_C(  -986.49),
                         SIMDE_FLOAT32_C(   398.68), SIMDE_FLOAT32_C(  -473.73), SIMDE_FLOAT32_C(  -151.11), SIMDE_FLOAT32_C(  -469.31),
                         SIMDE_FLOAT32_C(   243.78), SIMDE_FLOAT32_C(   403.79), SIMDE_FLOAT32_C(  -437.17), SIMDE_FLOAT32_C(   272.82),
                         SIMDE_FLOAT32_C(   850.05), SIMDE_FLOAT32_C(  -404.32), SIMDE_FLOAT32_C(  -351.61), SIMDE_FLOAT32_C(    68.52));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -668.36), SIMDE_FLOAT32_C(   143.30), SIMDE_FLOAT32_C(  -248.01), SIMDE_FLOAT32_C(   263.12),
                         SIMDE_FLOAT32_C(  -614.42), SIMDE_FLOAT32_C(  -579.71), SIMDE_FLOAT32_C(  -305.07), SIMDE_FLOAT32_C(   893.04),
                         SIMDE_FLOAT32_C(   940.04), SIMDE_FLOAT32_C(  -302.23), SIMDE_FLOAT32_C(   492.10), SIMDE_FLOAT32_C(  -193.92),
                         SIMDE_FLOAT32_C(   735.84), SIMDE_FLOAT32_C(    91.32), SIMDE_FLOAT32_C(   256.23), SIMDE_FLOAT32_C(  -726.05));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -431.81), SIMDE_FLOAT32_C(    95.93), SIMDE_FLOAT32_C(    65.35), SIMDE_FLOAT32_C(  -263.12),
                         SIMDE_FLOAT32_C(  -599.07), SIMDE_FLOAT32_C(   133.95), SIMDE_FLOAT32_C(   -38.07), SIMDE_FLOAT32_C(  -599.22),
                         SIMDE_FLOAT32_C(   243.78), SIMDE_FLOAT32_C(   461.89), SIMDE_FLOAT32_C(  -437.17), SIMDE_FLOAT32_C(   193.92),
                         SIMDE_FLOAT32_C(   208.59), SIMDE_FLOAT32_C(   -91.32), SIMDE_FLOAT32_C(   697.25), SIMDE_FLOAT32_C(    68.52));
  r = simde_mm512_mask_range_ps(src, UINT16_C(28853), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  src = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -416.66), SIMDE_FLOAT32_C(   782.54), SIMDE_FLOAT32_C(   755.66), SIMDE_FLOAT32_C(   327.11),
                           SIMDE_FLOAT32_C(   508.59), SIMDE_FLOAT32_C(  -552.12), SIMDE_FLOAT32_C(  -768.81), SIMDE_FLOAT32_C(  -556.76),
                           SIMDE_FLOAT32_C(  -565.63), SIMDE_FLOAT32_C(  -167.49), SIMDE_FLOAT32_C(   916.97), SIMDE_FLOAT32_C(   585.48),
                           SIMDE_FLOAT32_C(  -698.18), SIMDE_FLOAT32_C(  -326.81), SIMDE_FLOAT32_C(  -818.31), SIMDE_FLOAT32_C(   738.99));
  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -424.68), SIMDE_FLOAT32_C(  -312.49), SIMDE_FLOAT32_C(   499.99), SIMDE_FLOAT32_C(   902.12),
                         SIMDE_FLOAT32_C(  -494.18), SIMDE_FLOAT32_C(   761.01), SIMDE_FLOAT32_C(  -498.25), SIMDE_FLOAT32_C(  -825.81),
                         SIMDE_FLOAT32_C(  -382.30), SIMDE_FLOAT32_C(   749.76), SIMDE_FLOAT32_C(   -88.93), SIMDE_FLOAT32_C(  -767.88),
                         SIMDE_FLOAT32_C(   329.47), SIMDE_FLOAT32_C(  -783.86), SIMDE_FLOAT32_C(  -660.92), SIMDE_FLOAT32_C(   389.43));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -834.61), SIMDE_FLOAT32_C(   745.03), SIMDE_FLOAT32_C(   757.87), SIMDE_FLOAT32_C(  -224.03),
                         SIMDE_FLOAT32_C(  -773.34), SIMDE_FLOAT32_C(   -89.11), SIMDE_FLOAT32_C(  -807.38), SIMDE_FLOAT32_C(  -555.88),
                         SIMDE_FLOAT32_C(   155.24), SIMDE_FLOAT32_C(  -134.49), SIMDE_FLOAT32_C(   -64.47), SIMDE_FLOAT32_C(  -292.64),
                         SIMDE_FLOAT32_C(  -365.68), SIMDE_FLOAT32_C(  -507.71), SIMDE_FLOAT32_C(  -727.01), SIMDE_FLOAT32_C(   801.81));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -424.68), SIMDE_FLOAT32_C(  -312.49), SIMDE_FLOAT32_C(   755.66), SIMDE_FLOAT32_C(   224.03),
                         SIMDE_FLOAT32_C(  -494.18), SIMDE_FLOAT32_C(    89.11), SIMDE_FLOAT32_C(  -498.25), SIMDE_FLOAT32_C(  -556.76),
                         SIMDE_FLOAT32_C(  -565.63), SIMDE_FLOAT32_C(   134.49), SIMDE_FLOAT32_C(   -64.47), SIMDE_FLOAT32_C(  -292.64),
                         SIMDE_FLOAT32_C(   329.47), SIMDE_FLOAT32_C(  -326.81), SIMDE_FLOAT32_C(  -818.31), SIMDE_FLOAT32_C(   738.99));
  r = simde_mm512_mask_range_ps(src, UINT16_C(56952), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  src = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -487.26), SIMDE_FLOAT32_C(  -990.41), SIMDE_FLOAT32_C(  -776.19), SIMDE_FLOAT32_C(  -760.25),
                           SIMDE_FLOAT32_C(  -792.22), SIMDE_FLOAT32_C(   648.49), SIMDE_FLOAT32_C(   552.24), SIMDE_FLOAT32_C(  -292.21),
                           SIMDE_FLOAT32_C(   746.37), SIMDE_FLOAT32_C(    46.42), SIMDE_FLOAT32_C(   -53.22), SIMDE_FLOAT32_C(   244.62),
                           SIMDE_FLOAT32_C(  -127.76), SIMDE_FLOAT32_C(  -670.92), SIMDE_FLOAT32_C(   494.86), SIMDE_FLOAT32_C(   961.17));
  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(   470.13), SIMDE_FLOAT32_C(  -861.73), SIMDE_FLOAT32_C(  -971.39), SIMDE_FLOAT32_C(   141.05),
                         SIMDE_FLOAT32_C(  -356.60), SIMDE_FLOAT32_C(  -932.56), SIMDE_FLOAT32_C(    44.10), SIMDE_FLOAT32_C(  -521.99),
                         SIMDE_FLOAT32_C(  -677.60), SIMDE_FLOAT32_C(   286.22), SIMDE_FLOAT32_C(   702.04), SIMDE_FLOAT32_C(  -904.25),
                         SIMDE_FLOAT32_C(  -624.67), SIMDE_FLOAT32_C(   509.42), SIMDE_FLOAT32_C(   651.63), SIMDE_FLOAT32_C(   220.10));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(   472.10), SIMDE_FLOAT32_C(   985.98), SIMDE_FLOAT32_C(   717.65), SIMDE_FLOAT32_C(  -748.00),
                         SIMDE_FLOAT32_C(   342.07), SIMDE_FLOAT32_C(     1.55), SIMDE_FLOAT32_C(   739.26), SIMDE_FLOAT32_C(   332.48),
                         SIMDE_FLOAT32_C(  -222.26), SIMDE_FLOAT32_C(   499.51), SIMDE_FLOAT32_C(   124.70), SIMDE_FLOAT32_C(   129.25),
                         SIMDE_FLOAT32_C(   947.26), SIMDE_FLOAT32_C(  -583.09), SIMDE_FLOAT32_C(   382.88), SIMDE_FLOAT32_C(   -99.16));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -487.26), SIMDE_FLOAT32_C(  -985.98), SIMDE_FLOAT32_C(  -776.19), SIMDE_FLOAT32_C(  -748.00),
                         SIMDE_FLOAT32_C(  -792.22), SIMDE_FLOAT32_C(  -932.56), SIMDE_FLOAT32_C(   552.24), SIMDE_FLOAT32_C(  -521.99),
                         SIMDE_FLOAT32_C(  -677.60), SIMDE_FLOAT32_C(  -499.51), SIMDE_FLOAT32_C(  -702.04), SIMDE_FLOAT32_C(  -904.25),
                         SIMDE_FLOAT32_C(  -127.76), SIMDE_FLOAT32_C(  -583.09), SIMDE_FLOAT32_C(   494.86), SIMDE_FLOAT32_C(  -220.10));
  r = simde_mm512_mask_range_ps(src, UINT16_C(22005), a, b, INT32_C(          15));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  src = simde_mm512_set_ps(SIMDE_FLOAT32_C(   840.01), SIMDE_FLOAT32_C(  -215.69), SIMDE_FLOAT32_C(  -211.07), SIMDE_FLOAT32_C(  -542.88),
                           SIMDE_FLOAT32_C(   883.47), SIMDE_FLOAT32_C(   318.80), SIMDE_FLOAT32_C(  -681.14), SIMDE_FLOAT32_C(   854.86),
                           SIMDE_FLOAT32_C(  -822.25), SIMDE_FLOAT32_C(   675.45), SIMDE_FLOAT32_C(   787.42), SIMDE_FLOAT32_C(   133.66),
                           SIMDE_FLOAT32_C(   197.45), SIMDE_FLOAT32_C(   465.02), SIMDE_FLOAT32_C(   847.43), SIMDE_FLOAT32_C(   495.40));
  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(   300.48), SIMDE_FLOAT32_C(   541.87), SIMDE_FLOAT32_C(  -513.52), SIMDE_FLOAT32_C(   835.47),
                         SIMDE_FLOAT32_C(   694.44), SIMDE_FLOAT32_C(    -8.92), SIMDE_FLOAT32_C(  -533.81), SIMDE_FLOAT32_C(  -777.66),
                         SIMDE_FLOAT32_C(     5.10), SIMDE_FLOAT32_C(  -251.45), SIMDE_FLOAT32_C(   970.34), SIMDE_FLOAT32_C(   663.03),
                         SIMDE_FLOAT32_C(   747.00), SIMDE_FLOAT32_C(  -768.92), SIMDE_FLOAT32_C(  -669.45), SIMDE_FLOAT32_C(   -30.74));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(   -55.37), SIMDE_FLOAT32_C(  -657.89), SIMDE_FLOAT32_C(  -833.14), SIMDE_FLOAT32_C(   975.37),
                         SIMDE_FLOAT32_C(   610.54), SIMDE_FLOAT32_C(   -38.98), SIMDE_FLOAT32_C(  -864.63), SIMDE_FLOAT32_C(  -173.77),
                         SIMDE_FLOAT32_C(  -827.92), SIMDE_FLOAT32_C(   678.24), SIMDE_FLOAT32_C(   -57.23), SIMDE_FLOAT32_C(  -146.72),
                         SIMDE_FLOAT32_C(   359.38), SIMDE_FLOAT32_C(    87.91), SIMDE_FLOAT32_C(  -324.47), SIMDE_FLOAT32_C(   683.93));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(   840.01), SIMDE_FLOAT32_C(   541.87), SIMDE_FLOAT32_C(  -513.52), SIMDE_FLOAT32_C(  -542.88),
                         SIMDE_FLOAT32_C(   694.44), SIMDE_FLOAT32_C(   318.80), SIMDE_FLOAT32_C(  -681.14), SIMDE_FLOAT32_C(   854.86),
                         SIMDE_FLOAT32_C(     5.10), SIMDE_FLOAT32_C(  -678.24), SIMDE_FLOAT32_C(   787.42), SIMDE_FLOAT32_C(   663.03),
                         SIMDE_FLOAT32_C(   197.45), SIMDE_FLOAT32_C(   465.02), SIMDE_FLOAT32_C(  -324.47), SIMDE_FLOAT32_C(  -683.93));
  r = simde_mm512_mask_range_ps(src, UINT16_C(26835), a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  src = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -322.30), SIMDE_FLOAT32_C(  -672.98), SIMDE_FLOAT32_C(    42.32), SIMDE_FLOAT32_C(  -997.83),
                           SIMDE_FLOAT32_C(  -356.91), SIMDE_FLOAT32_C(   741.84), SIMDE_FLOAT32_C(  -539.70), SIMDE_FLOAT32_C(  -843.39),
                           SIMDE_FLOAT32_C(   906.37), SIMDE_FLOAT32_C(  -234.14), SIMDE_FLOAT32_C(   165.53), SIMDE_FLOAT32_C(   440.18),
                           SIMDE_FLOAT32_C(  -456.48), SIMDE_FLOAT32_C(  -839.57), SIMDE_FLOAT32_C(  -308.37), SIMDE_FLOAT32_C(  -426.81));
  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(   488.78), SIMDE_FLOAT32_C(   111.65), SIMDE_FLOAT32_C(  -574.94), SIMDE_FLOAT32_C(   328.35),
                         SIMDE_FLOAT32_C(  -579.98), SIMDE_FLOAT32_C(   851.88), SIMDE_FLOAT32_C(  -169.06), SIMDE_FLOAT32_C(   475.39),
                         SIMDE_FLOAT32_C(   509.77), SIMDE_FLOAT32_C(  -335.92), SIMDE_FLOAT32_C(   500.01), SIMDE_FLOAT32_C(   899.23),
                         SIMDE_FLOAT32_C(   703.06), SIMDE_FLOAT32_C(   364.65), SIMDE_FLOAT32_C(    73.00), SIMDE_FLOAT32_C(   530.98));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -594.39), SIMDE_FLOAT32_C(   467.44), SIMDE_FLOAT32_C(   372.60), SIMDE_FLOAT32_C(  -125.37),
                         SIMDE_FLOAT32_C(   781.03), SIMDE_FLOAT32_C(   242.37), SIMDE_FLOAT32_C(  -803.07), SIMDE_FLOAT32_C(   454.01),
                         SIMDE_FLOAT32_C(  -799.96), SIMDE_FLOAT32_C(  -805.24), SIMDE_FLOAT32_C(  -189.08), SIMDE_FLOAT32_C(  -541.80),
                         SIMDE_FLOAT32_C(   734.45), SIMDE_FLOAT32_C(  -345.69), SIMDE_FLOAT32_C(  -448.17), SIMDE_FLOAT32_C(   -31.41));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -488.78), SIMDE_FLOAT32_C(  -467.44), SIMDE_FLOAT32_C(    42.32), SIMDE_FLOAT32_C(  -328.35),
                         SIMDE_FLOAT32_C(  -356.91), SIMDE_FLOAT32_C(   741.84), SIMDE_FLOAT32_C(  -539.70), SIMDE_FLOAT32_C(  -843.39),
                         SIMDE_FLOAT32_C(   906.37), SIMDE_FLOAT32_C(  -335.92), SIMDE_FLOAT32_C(   165.53), SIMDE_FLOAT32_C(   440.18),
                         SIMDE_FLOAT32_C(  -456.48), SIMDE_FLOAT32_C(  -364.65), SIMDE_FLOAT32_C(  -308.37), SIMDE_FLOAT32_C(  -426.81));
  r = simde_mm512_mask_range_ps(src, UINT16_C(53316), a, b, INT32_C(          13));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  src = simde_mm512_set_ps(SIMDE_FLOAT32_C(   890.99), SIMDE_FLOAT32_C(   100.13), SIMDE_FLOAT32_C(  -579.19), SIMDE_FLOAT32_C(   339.16),
                           SIMDE_FLOAT32_C(  -868.46), SIMDE_FLOAT32_C(   -67.97), SIMDE_FLOAT32_C(  -772.49), SIMDE_FLOAT32_C(   706.48),
                           SIMDE_FLOAT32_C(   603.69), SIMDE_FLOAT32_C(   807.49), SIMDE_FLOAT32_C(   854.60), SIMDE_FLOAT32_C(  -227.25),
                           SIMDE_FLOAT32_C(  -667.89), SIMDE_FLOAT32_C(  -655.17), SIMDE_FLOAT32_C(  -891.33), SIMDE_FLOAT32_C(  -167.91));
  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(   954.63), SIMDE_FLOAT32_C(  -384.81), SIMDE_FLOAT32_C(   420.61), SIMDE_FLOAT32_C(   609.80),
                         SIMDE_FLOAT32_C(  -493.49), SIMDE_FLOAT32_C(  -411.48), SIMDE_FLOAT32_C(   164.20), SIMDE_FLOAT32_C(  -899.10),
                         SIMDE_FLOAT32_C(   121.08), SIMDE_FLOAT32_C(   791.60), SIMDE_FLOAT32_C(   226.27), SIMDE_FLOAT32_C(   340.05),
                         SIMDE_FLOAT32_C(  -450.77), SIMDE_FLOAT32_C(    29.34), SIMDE_FLOAT32_C(   886.04), SIMDE_FLOAT32_C(  -650.81));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(   367.06), SIMDE_FLOAT32_C(   581.97), SIMDE_FLOAT32_C(   419.59), SIMDE_FLOAT32_C(    17.87),
                         SIMDE_FLOAT32_C(  -252.62), SIMDE_FLOAT32_C(  -655.53), SIMDE_FLOAT32_C(   126.88), SIMDE_FLOAT32_C(   647.25),
                         SIMDE_FLOAT32_C(   923.66), SIMDE_FLOAT32_C(   787.72), SIMDE_FLOAT32_C(   515.71), SIMDE_FLOAT32_C(    -8.38),
                         SIMDE_FLOAT32_C(   560.21), SIMDE_FLOAT32_C(   809.23), SIMDE_FLOAT32_C(   387.94), SIMDE_FLOAT32_C(   752.72));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(   890.99), SIMDE_FLOAT32_C(   100.13), SIMDE_FLOAT32_C(  -579.19), SIMDE_FLOAT32_C(    17.87),
                         SIMDE_FLOAT32_C(  -868.46), SIMDE_FLOAT32_C(   -67.97), SIMDE_FLOAT32_C(   126.88), SIMDE_FLOAT32_C(   647.25),
                         SIMDE_FLOAT32_C(   121.08), SIMDE_FLOAT32_C(   787.72), SIMDE_FLOAT32_C(   854.60), SIMDE_FLOAT32_C(  -227.25),
                         SIMDE_FLOAT32_C(  -667.89), SIMDE_FLOAT32_C(    29.34), SIMDE_FLOAT32_C(   387.94), SIMDE_FLOAT32_C(   650.81));
  r = simde_mm512_mask_range_ps(src, UINT16_C( 5063), a, b, INT32_C(          10));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m512 r;
    SIMDE_CONSTIFY_16_(simde_mm512_mask_range_ps, r, simde_mm512_setzero_ps(), imm8, src, k, a, b);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_range_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m512 a, b, e, r;

  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(    88.80), SIMDE_FLOAT32_C(  -754.26), SIMDE_FLOAT32_C(  -551.88), SIMDE_FLOAT32_C(   528.59),
                         SIMDE_FLOAT32_C(  -563.49), SIMDE_FLOAT32_C(    60.18), SIMDE_FLOAT32_C(   775.88), SIMDE_FLOAT32_C(  -518.12),
                         SIMDE_FLOAT32_C(  -555.00), SIMDE_FLOAT32_C(  -644.73), SIMDE_FLOAT32_C(  -127.91), SIMDE_FLOAT32_C(   938.48),
                         SIMDE_FLOAT32_C(   766.75), SIMDE_FLOAT32_C(   707.89), SIMDE_FLOAT32_C(   837.58), SIMDE_FLOAT32_C(  -354.33));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(    78.74), SIMDE_FLOAT32_C(  -695.37), SIMDE_FLOAT32_C(  -650.65), SIMDE_FLOAT32_C(  -566.92),
                         SIMDE_FLOAT32_C(  -611.66), SIMDE_FLOAT32_C(   738.04), SIMDE_FLOAT32_C(   127.45), SIMDE_FLOAT32_C(    21.28),
                         SIMDE_FLOAT32_C(  -843.93), SIMDE_FLOAT32_C(   707.87), SIMDE_FLOAT32_C(  -996.59), SIMDE_FLOAT32_C(   408.69),
                         SIMDE_FLOAT32_C(   363.40), SIMDE_FLOAT32_C(  -123.48), SIMDE_FLOAT32_C(   761.44), SIMDE_FLOAT32_C(   439.74));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -695.37), SIMDE_FLOAT32_C(  -551.88), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -738.04), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -555.00), SIMDE_FLOAT32_C(  -707.87), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -766.75), SIMDE_FLOAT32_C(  -707.89), SIMDE_FLOAT32_C(  -837.58), SIMDE_FLOAT32_C(  -439.74));
  r = simde_mm512_maskz_range_ps(UINT16_C(25807), a, b, INT32_C(          13));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -118.14), SIMDE_FLOAT32_C(  -529.44), SIMDE_FLOAT32_C(   810.18), SIMDE_FLOAT32_C(   518.46),
                         SIMDE_FLOAT32_C(   594.04), SIMDE_FLOAT32_C(  -951.27), SIMDE_FLOAT32_C(  -921.28), SIMDE_FLOAT32_C(  -494.77),
                         SIMDE_FLOAT32_C(   803.00), SIMDE_FLOAT32_C(   630.60), SIMDE_FLOAT32_C(   -23.36), SIMDE_FLOAT32_C(   366.49),
                         SIMDE_FLOAT32_C(  -429.58), SIMDE_FLOAT32_C(   200.76), SIMDE_FLOAT32_C(  -115.40), SIMDE_FLOAT32_C(  -874.58));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(   774.70), SIMDE_FLOAT32_C(  -925.51), SIMDE_FLOAT32_C(  -799.28), SIMDE_FLOAT32_C(   649.28),
                         SIMDE_FLOAT32_C(   229.00), SIMDE_FLOAT32_C(  -811.80), SIMDE_FLOAT32_C(   462.34), SIMDE_FLOAT32_C(  -849.74),
                         SIMDE_FLOAT32_C(   883.58), SIMDE_FLOAT32_C(   112.99), SIMDE_FLOAT32_C(   717.18), SIMDE_FLOAT32_C(   495.24),
                         SIMDE_FLOAT32_C(   374.94), SIMDE_FLOAT32_C(  -410.27), SIMDE_FLOAT32_C(  -526.03), SIMDE_FLOAT32_C(   218.87));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   529.44), SIMDE_FLOAT32_C(   810.18), SIMDE_FLOAT32_C(   649.28),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   630.60), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   495.24),
                         SIMDE_FLOAT32_C(   374.94), SIMDE_FLOAT32_C(   200.76), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00));
  r = simde_mm512_maskz_range_ps(UINT16_C(28764), a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -292.48), SIMDE_FLOAT32_C(    44.49), SIMDE_FLOAT32_C(   295.69), SIMDE_FLOAT32_C(   332.58),
                         SIMDE_FLOAT32_C(  -545.24), SIMDE_FLOAT32_C(  -178.28), SIMDE_FLOAT32_C(  -886.29), SIMDE_FLOAT32_C(   572.90),
                         SIMDE_FLOAT32_C(  -648.84), SIMDE_FLOAT32_C(  -696.46), SIMDE_FLOAT32_C(  -945.56), SIMDE_FLOAT32_C(  -242.87),
                         SIMDE_FLOAT32_C(  -745.19), SIMDE_FLOAT32_C(   975.72), SIMDE_FLOAT32_C(  -748.11), SIMDE_FLOAT32_C(  -548.19));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -399.44), SIMDE_FLOAT32_C(    51.94), SIMDE_FLOAT32_C(   490.68), SIMDE_FLOAT32_C(  -851.25),
                         SIMDE_FLOAT32_C(  -293.18), SIMDE_FLOAT32_C(  -784.57), SIMDE_FLOAT32_C(    63.42), SIMDE_FLOAT32_C(   -67.87),
                         SIMDE_FLOAT32_C(  -859.07), SIMDE_FLOAT32_C(  -137.29), SIMDE_FLOAT32_C(   282.85), SIMDE_FLOAT32_C(   -88.07),
                         SIMDE_FLOAT32_C(  -325.50), SIMDE_FLOAT32_C(   820.51), SIMDE_FLOAT32_C(  -238.33), SIMDE_FLOAT32_C(  -209.07));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    44.49), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -178.28), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -137.29), SIMDE_FLOAT32_C(   282.85), SIMDE_FLOAT32_C(   -88.07),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   820.51), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00));
  r = simde_mm512_maskz_range_ps(UINT16_C(17524), a, b, INT32_C(           6));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -566.29), SIMDE_FLOAT32_C(   133.23), SIMDE_FLOAT32_C(   -84.08), SIMDE_FLOAT32_C(   759.21),
                         SIMDE_FLOAT32_C(   312.72), SIMDE_FLOAT32_C(  -845.75), SIMDE_FLOAT32_C(   -31.72), SIMDE_FLOAT32_C(  -394.80),
                         SIMDE_FLOAT32_C(   109.76), SIMDE_FLOAT32_C(   672.59), SIMDE_FLOAT32_C(   272.61), SIMDE_FLOAT32_C(  -345.01),
                         SIMDE_FLOAT32_C(  -149.13), SIMDE_FLOAT32_C(   158.90), SIMDE_FLOAT32_C(    82.09), SIMDE_FLOAT32_C(  -500.29));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(   917.18), SIMDE_FLOAT32_C(   964.51), SIMDE_FLOAT32_C(  -865.38), SIMDE_FLOAT32_C(   417.47),
                         SIMDE_FLOAT32_C(   109.15), SIMDE_FLOAT32_C(   106.96), SIMDE_FLOAT32_C(   674.90), SIMDE_FLOAT32_C(  -491.41),
                         SIMDE_FLOAT32_C(  -944.97), SIMDE_FLOAT32_C(  -815.79), SIMDE_FLOAT32_C(  -640.16), SIMDE_FLOAT32_C(   348.21),
                         SIMDE_FLOAT32_C(   968.78), SIMDE_FLOAT32_C(   296.42), SIMDE_FLOAT32_C(  -583.92), SIMDE_FLOAT32_C(   827.85));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -566.29), SIMDE_FLOAT32_C(  -133.23), SIMDE_FLOAT32_C(  -865.38), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -109.15), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -640.16), SIMDE_FLOAT32_C(  -345.01),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -500.29));
  r = simde_mm512_maskz_range_ps(UINT16_C(59441), a, b, INT32_C(          12));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(   848.26), SIMDE_FLOAT32_C(  -101.73), SIMDE_FLOAT32_C(   863.25), SIMDE_FLOAT32_C(   879.47),
                         SIMDE_FLOAT32_C(   601.85), SIMDE_FLOAT32_C(   447.17), SIMDE_FLOAT32_C(  -948.38), SIMDE_FLOAT32_C(   168.13),
                         SIMDE_FLOAT32_C(  -686.06), SIMDE_FLOAT32_C(   135.70), SIMDE_FLOAT32_C(   408.92), SIMDE_FLOAT32_C(     1.22),
                         SIMDE_FLOAT32_C(   -18.55), SIMDE_FLOAT32_C(  -559.36), SIMDE_FLOAT32_C(  -603.98), SIMDE_FLOAT32_C(   871.70));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(   596.47), SIMDE_FLOAT32_C(   810.07), SIMDE_FLOAT32_C(   963.76), SIMDE_FLOAT32_C(   724.77),
                         SIMDE_FLOAT32_C(    42.02), SIMDE_FLOAT32_C(  -159.64), SIMDE_FLOAT32_C(  -491.94), SIMDE_FLOAT32_C(   124.84),
                         SIMDE_FLOAT32_C(  -124.15), SIMDE_FLOAT32_C(  -626.55), SIMDE_FLOAT32_C(   707.37), SIMDE_FLOAT32_C(   766.70),
                         SIMDE_FLOAT32_C(   266.48), SIMDE_FLOAT32_C(  -967.53), SIMDE_FLOAT32_C(   258.11), SIMDE_FLOAT32_C(   211.45));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(   596.47), SIMDE_FLOAT32_C(  -101.73), SIMDE_FLOAT32_C(   863.25), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -491.94), SIMDE_FLOAT32_C(   124.84),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   -18.55), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   211.45));
  r = simde_mm512_maskz_range_ps(UINT16_C(58121), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(   463.30), SIMDE_FLOAT32_C(   525.45), SIMDE_FLOAT32_C(  -414.02), SIMDE_FLOAT32_C(  -803.19),
                         SIMDE_FLOAT32_C(   492.98), SIMDE_FLOAT32_C(   327.87), SIMDE_FLOAT32_C(   -14.64), SIMDE_FLOAT32_C(   644.72),
                         SIMDE_FLOAT32_C(  -570.39), SIMDE_FLOAT32_C(   122.11), SIMDE_FLOAT32_C(   765.25), SIMDE_FLOAT32_C(  -172.24),
                         SIMDE_FLOAT32_C(   674.94), SIMDE_FLOAT32_C(   713.63), SIMDE_FLOAT32_C(   659.63), SIMDE_FLOAT32_C(   361.00));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(   753.45), SIMDE_FLOAT32_C(  -756.03), SIMDE_FLOAT32_C(   460.45), SIMDE_FLOAT32_C(  -607.56),
                         SIMDE_FLOAT32_C(   666.05), SIMDE_FLOAT32_C(   209.74), SIMDE_FLOAT32_C(  -967.34), SIMDE_FLOAT32_C(  -930.42),
                         SIMDE_FLOAT32_C(   399.68), SIMDE_FLOAT32_C(  -931.11), SIMDE_FLOAT32_C(  -655.19), SIMDE_FLOAT32_C(  -642.34),
                         SIMDE_FLOAT32_C(   228.53), SIMDE_FLOAT32_C(   836.74), SIMDE_FLOAT32_C(   232.82), SIMDE_FLOAT32_C(  -647.32));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   525.45), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   607.56),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   327.87), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   399.68), SIMDE_FLOAT32_C(   122.11), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   172.24),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   836.74), SIMDE_FLOAT32_C(   659.63), SIMDE_FLOAT32_C(     0.00));
  r = simde_mm512_maskz_range_ps(UINT16_C(21718), a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(   872.53), SIMDE_FLOAT32_C(    32.71), SIMDE_FLOAT32_C(   618.82), SIMDE_FLOAT32_C(  -356.01),
                         SIMDE_FLOAT32_C(   195.97), SIMDE_FLOAT32_C(  -613.99), SIMDE_FLOAT32_C(  -708.69), SIMDE_FLOAT32_C(   732.67),
                         SIMDE_FLOAT32_C(  -139.44), SIMDE_FLOAT32_C(   705.33), SIMDE_FLOAT32_C(   535.86), SIMDE_FLOAT32_C(   367.58),
                         SIMDE_FLOAT32_C(  -622.55), SIMDE_FLOAT32_C(  -449.50), SIMDE_FLOAT32_C(   722.85), SIMDE_FLOAT32_C(   947.85));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(   114.29), SIMDE_FLOAT32_C(   548.35), SIMDE_FLOAT32_C(   314.72), SIMDE_FLOAT32_C(   166.44),
                         SIMDE_FLOAT32_C(  -880.04), SIMDE_FLOAT32_C(   357.12), SIMDE_FLOAT32_C(  -953.64), SIMDE_FLOAT32_C(  -633.48),
                         SIMDE_FLOAT32_C(   113.14), SIMDE_FLOAT32_C(  -414.10), SIMDE_FLOAT32_C(   974.07), SIMDE_FLOAT32_C(   447.09),
                         SIMDE_FLOAT32_C(   376.16), SIMDE_FLOAT32_C(   941.42), SIMDE_FLOAT32_C(   377.52), SIMDE_FLOAT32_C(   976.48));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   548.35), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -166.44),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -357.12), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   732.67),
                         SIMDE_FLOAT32_C(  -113.14), SIMDE_FLOAT32_C(   705.33), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   447.09),
                         SIMDE_FLOAT32_C(  -376.16), SIMDE_FLOAT32_C(  -941.42), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   976.48));
  r = simde_mm512_maskz_range_ps(UINT16_C(21981), a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  a = simde_mm512_set_ps(SIMDE_FLOAT32_C(  -376.83), SIMDE_FLOAT32_C(   946.31), SIMDE_FLOAT32_C(   -26.41), SIMDE_FLOAT32_C(   247.02),
                         SIMDE_FLOAT32_C(  -995.11), SIMDE_FLOAT32_C(   596.07), SIMDE_FLOAT32_C(   270.54), SIMDE_FLOAT32_C(  -867.63),
                         SIMDE_FLOAT32_C(  -436.64), SIMDE_FLOAT32_C(   651.71), SIMDE_FLOAT32_C(   488.37), SIMDE_FLOAT32_C(   367.39),
                         SIMDE_FLOAT32_C(   265.70), SIMDE_FLOAT32_C(   197.07), SIMDE_FLOAT32_C(   634.72), SIMDE_FLOAT32_C(  -594.85));
  b = simde_mm512_set_ps(SIMDE_FLOAT32_C(   648.39), SIMDE_FLOAT32_C(    27.90), SIMDE_FLOAT32_C(  -945.93), SIMDE_FLOAT32_C(   243.24),
                         SIMDE_FLOAT32_C(   536.16), SIMDE_FLOAT32_C(   955.21), SIMDE_FLOAT32_C(  -794.33), SIMDE_FLOAT32_C(  -578.13),
                         SIMDE_FLOAT32_C(  -593.14), SIMDE_FLOAT32_C(  -109.05), SIMDE_FLOAT32_C(   255.43), SIMDE_FLOAT32_C(  -713.10),
                         SIMDE_FLOAT32_C(   533.83), SIMDE_FLOAT32_C(   209.07), SIMDE_FLOAT32_C(   920.38), SIMDE_FLOAT32_C(  -579.31));
  e = simde_mm512_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -26.41), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   270.54), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   109.05), SIMDE_FLOAT32_C(   255.43), SIMDE_FLOAT32_C(   367.39),
                         SIMDE_FLOAT32_C(   265.70), SIMDE_FLOAT32_C(   197.07), SIMDE_FLOAT32_C(   634.72), SIMDE_FLOAT32_C(  -579.31));
  r = simde_mm512_maskz_range_ps(UINT16_C( 8831), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x16(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 b = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m512 r;
    SIMDE_CONSTIFY_16_(simde_mm512_maskz_range_ps, r, simde_mm512_setzero_ps(), imm8, k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_range_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   830.67), SIMDE_FLOAT64_C(   598.43) },
      { SIMDE_FLOAT64_C(  -161.84), SIMDE_FLOAT64_C(  -609.24) },
      { SIMDE_FLOAT64_C(   830.67), SIMDE_FLOAT64_C(   609.24) } },
    { { SIMDE_FLOAT64_C(  -639.95), SIMDE_FLOAT64_C(   257.59) },
      { SIMDE_FLOAT64_C(   -49.35), SIMDE_FLOAT64_C(   500.73) },
      { SIMDE_FLOAT64_C(  -639.95), SIMDE_FLOAT64_C(   257.59) } },
    { { SIMDE_FLOAT64_C(   920.50), SIMDE_FLOAT64_C(  -952.84) },
      { SIMDE_FLOAT64_C(   445.89), SIMDE_FLOAT64_C(  -703.72) },
      { SIMDE_FLOAT64_C(   920.50), SIMDE_FLOAT64_C(  -703.72) } },
    { { SIMDE_FLOAT64_C(   384.42), SIMDE_FLOAT64_C(  -127.63) },
      { SIMDE_FLOAT64_C(   800.45), SIMDE_FLOAT64_C(   678.44) },
      { SIMDE_FLOAT64_C(   384.42), SIMDE_FLOAT64_C(  -127.63) } },
    { { SIMDE_FLOAT64_C(   519.71), SIMDE_FLOAT64_C(   275.20) },
      { SIMDE_FLOAT64_C(  -380.64), SIMDE_FLOAT64_C(  -709.08) },
      { SIMDE_FLOAT64_C(   519.71), SIMDE_FLOAT64_C(   709.08) } },
    { { SIMDE_FLOAT64_C(  -162.04), SIMDE_FLOAT64_C(   472.77) },
      { SIMDE_FLOAT64_C(  -553.19), SIMDE_FLOAT64_C(   126.94) },
      { SIMDE_FLOAT64_C(   162.04), SIMDE_FLOAT64_C(   472.77) } },
    { { SIMDE_FLOAT64_C(  -894.91), SIMDE_FLOAT64_C(  -295.68) },
      { SIMDE_FLOAT64_C(   576.25), SIMDE_FLOAT64_C(   294.47) },
      { SIMDE_FLOAT64_C(   576.25), SIMDE_FLOAT64_C(   294.47) } },
    { { SIMDE_FLOAT64_C(    69.59), SIMDE_FLOAT64_C(  -855.72) },
      { SIMDE_FLOAT64_C(   780.93), SIMDE_FLOAT64_C(   -99.75) },
      { SIMDE_FLOAT64_C(    69.59), SIMDE_FLOAT64_C(  -855.72) } }
  };

  simde__m128d a, b, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_range_pd(a, b, 11);
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_range_pd(a, b, 4);
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_range_pd(a, b, 1);
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_range_pd(a, b, 2);
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_range_pd(a, b, 3);
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_range_pd(a, b, 9);
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_range_pd(a, b, 5);
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_range_pd(a, b, 0);
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);

  simde__m128d a, b, r;

  a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm_range_pd(a, b, 11);

  simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm_range_pd(a, b, 4);

  simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm_range_pd(a, b, 1);

  simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm_range_pd(a, b, 2);

  simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm_range_pd(a, b, 3);

  simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm_range_pd(a, b, 9);

  simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm_range_pd(a, b, 5);

  simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm_range_pd(a, b, 0);

  simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm_mask_range_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m128d src, a, b, e, r;

  src = simde_mm_set_pd(SIMDE_FLOAT64_C(  -139.94), SIMDE_FLOAT64_C(  -886.75));
  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -792.78), SIMDE_FLOAT64_C(  -894.29));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -806.31), SIMDE_FLOAT64_C(   453.92));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  -139.94), SIMDE_FLOAT64_C(  -894.29));
  r = simde_mm_mask_range_pd(src, UINT8_C(141), a, b, INT32_C(          12));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  src = simde_mm_set_pd(SIMDE_FLOAT64_C(  -663.72), SIMDE_FLOAT64_C(   184.82));
  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -194.35), SIMDE_FLOAT64_C(   403.49));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   681.58), SIMDE_FLOAT64_C(   390.93));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  -663.72), SIMDE_FLOAT64_C(   403.49));
  r = simde_mm_mask_range_pd(src, UINT8_C( 93), a, b, INT32_C(          11));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  src = simde_mm_set_pd(SIMDE_FLOAT64_C(  -113.27), SIMDE_FLOAT64_C(  -276.87));
  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   963.08), SIMDE_FLOAT64_C(  -621.87));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   150.21), SIMDE_FLOAT64_C(   955.33));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  -113.27), SIMDE_FLOAT64_C(  -621.87));
  r = simde_mm_mask_range_pd(src, UINT8_C(241), a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  src = simde_mm_set_pd(SIMDE_FLOAT64_C(   985.23), SIMDE_FLOAT64_C(   499.81));
  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -193.24), SIMDE_FLOAT64_C(  -403.55));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   444.77), SIMDE_FLOAT64_C(  -416.56));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  -444.77), SIMDE_FLOAT64_C(  -403.55));
  r = simde_mm_mask_range_pd(src, UINT8_C( 79), a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  src = simde_mm_set_pd(SIMDE_FLOAT64_C(  -695.93), SIMDE_FLOAT64_C(   443.50));
  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   757.98), SIMDE_FLOAT64_C(   650.72));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -329.26), SIMDE_FLOAT64_C(   219.41));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(   757.98), SIMDE_FLOAT64_C(   650.72));
  r = simde_mm_mask_range_pd(src, UINT8_C( 87), a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  src = simde_mm_set_pd(SIMDE_FLOAT64_C(   426.75), SIMDE_FLOAT64_C(   555.69));
  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -182.32), SIMDE_FLOAT64_C(  -638.66));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   952.11), SIMDE_FLOAT64_C(  -972.12));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  -182.32), SIMDE_FLOAT64_C(   555.69));
  r = simde_mm_mask_range_pd(src, UINT8_C(182), a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  src = simde_mm_set_pd(SIMDE_FLOAT64_C(    -2.92), SIMDE_FLOAT64_C(   -85.39));
  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   -47.59), SIMDE_FLOAT64_C(  -122.31));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   877.42), SIMDE_FLOAT64_C(    69.15));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(   -47.59), SIMDE_FLOAT64_C(   -69.15));
  r = simde_mm_mask_range_pd(src, UINT8_C(143), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  src = simde_mm_set_pd(SIMDE_FLOAT64_C(  -613.32), SIMDE_FLOAT64_C(    54.38));
  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   -29.88), SIMDE_FLOAT64_C(   861.14));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -218.85), SIMDE_FLOAT64_C(  -506.57));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  -613.32), SIMDE_FLOAT64_C(   506.57));
  r = simde_mm_mask_range_pd(src, UINT8_C( 49), a, b, INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m128d r;
    SIMDE_CONSTIFY_16_(simde_mm_mask_range_pd, r, simde_mm_setzero_pd(), imm8, src, k, a, b);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_range_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m128d a, b, e, r;

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -935.65), SIMDE_FLOAT64_C(   806.87));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(    26.29), SIMDE_FLOAT64_C(  -444.52));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00));
  r = simde_mm_maskz_range_pd(UINT8_C(108), a, b, INT32_C(          14));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -838.16), SIMDE_FLOAT64_C(  -418.02));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   -56.68), SIMDE_FLOAT64_C(   844.57));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   844.57));
  r = simde_mm_maskz_range_pd(UINT8_C( 37), a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -479.67), SIMDE_FLOAT64_C(  -104.57));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   892.51), SIMDE_FLOAT64_C(  -212.94));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(   892.51), SIMDE_FLOAT64_C(   104.57));
  r = simde_mm_maskz_range_pd(   UINT8_MAX, a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   508.41), SIMDE_FLOAT64_C(  -155.08));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   297.13), SIMDE_FLOAT64_C(   542.17));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(   508.41), SIMDE_FLOAT64_C(   542.17));
  r = simde_mm_maskz_range_pd(UINT8_C(  3), a, b, INT32_C(           7));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -576.07), SIMDE_FLOAT64_C(  -654.20));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -160.77), SIMDE_FLOAT64_C(  -101.02));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  -576.07), SIMDE_FLOAT64_C(  -654.20));
  r = simde_mm_maskz_range_pd(UINT8_C(187), a, b, INT32_C(           7));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(    11.95), SIMDE_FLOAT64_C(   636.72));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -807.80), SIMDE_FLOAT64_C(   376.95));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(   -11.95), SIMDE_FLOAT64_C(  -376.95));
  r = simde_mm_maskz_range_pd(UINT8_C(211), a, b, INT32_C(          14));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -379.78), SIMDE_FLOAT64_C(   690.48));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(   535.05), SIMDE_FLOAT64_C(  -726.12));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(   379.78), SIMDE_FLOAT64_C(   690.48));
  r = simde_mm_maskz_range_pd(UINT8_C(167), a, b, INT32_C(          10));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -541.03), SIMDE_FLOAT64_C(   407.50));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  -805.43), SIMDE_FLOAT64_C(   773.72));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   407.50));
  r = simde_mm_maskz_range_pd(UINT8_C( 53), a, b, INT32_C(           6));
  simde_test_x86_assert_equal_f64x2(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m128d r;
    SIMDE_CONSTIFY_16_(simde_mm_maskz_range_pd, r, simde_mm_setzero_pd(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_range_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[4];
    const simde_float64 b[4];
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   742.72), SIMDE_FLOAT64_C(  -380.91), SIMDE_FLOAT64_C(   291.01), SIMDE_FLOAT64_C(  -897.24) },
      { SIMDE_FLOAT64_C(   876.68), SIMDE_FLOAT64_C(  -758.34), SIMDE_FLOAT64_C(   603.49), SIMDE_FLOAT64_C(   797.18) },
      { SIMDE_FLOAT64_C(   876.68), SIMDE_FLOAT64_C(   758.34), SIMDE_FLOAT64_C(   603.49), SIMDE_FLOAT64_C(   897.24) } },
    { { SIMDE_FLOAT64_C(  -711.18), SIMDE_FLOAT64_C(    49.38), SIMDE_FLOAT64_C(  -906.54), SIMDE_FLOAT64_C(   673.24) },
      { SIMDE_FLOAT64_C(   921.74), SIMDE_FLOAT64_C(   893.90), SIMDE_FLOAT64_C(   351.69), SIMDE_FLOAT64_C(   441.45) },
      { SIMDE_FLOAT64_C(  -711.18), SIMDE_FLOAT64_C(    49.38), SIMDE_FLOAT64_C(  -906.54), SIMDE_FLOAT64_C(   441.45) } },
    { { SIMDE_FLOAT64_C(   169.11), SIMDE_FLOAT64_C(   971.04), SIMDE_FLOAT64_C(   732.37), SIMDE_FLOAT64_C(  -992.93) },
      { SIMDE_FLOAT64_C(   443.81), SIMDE_FLOAT64_C(  -820.82), SIMDE_FLOAT64_C(   134.01), SIMDE_FLOAT64_C(   548.91) },
      { SIMDE_FLOAT64_C(   443.81), SIMDE_FLOAT64_C(   971.04), SIMDE_FLOAT64_C(   732.37), SIMDE_FLOAT64_C(  -548.91) } },
    { { SIMDE_FLOAT64_C(  -116.50), SIMDE_FLOAT64_C(  -289.74), SIMDE_FLOAT64_C(  -156.63), SIMDE_FLOAT64_C(   953.09) },
      { SIMDE_FLOAT64_C(  -145.46), SIMDE_FLOAT64_C(  -375.70), SIMDE_FLOAT64_C(  -146.66), SIMDE_FLOAT64_C(  -402.75) },
      { SIMDE_FLOAT64_C(  -116.50), SIMDE_FLOAT64_C(  -289.74), SIMDE_FLOAT64_C(  -146.66), SIMDE_FLOAT64_C(   402.75) } },
    { { SIMDE_FLOAT64_C(   243.39), SIMDE_FLOAT64_C(  -855.65), SIMDE_FLOAT64_C(  -299.98), SIMDE_FLOAT64_C(   120.07) },
      { SIMDE_FLOAT64_C(  -613.99), SIMDE_FLOAT64_C(  -696.49), SIMDE_FLOAT64_C(   -82.74), SIMDE_FLOAT64_C(  -325.17) },
      { SIMDE_FLOAT64_C(   613.99), SIMDE_FLOAT64_C(  -855.65), SIMDE_FLOAT64_C(  -299.98), SIMDE_FLOAT64_C(   325.17) } },
    { { SIMDE_FLOAT64_C(   352.88), SIMDE_FLOAT64_C(    10.71), SIMDE_FLOAT64_C(  -651.93), SIMDE_FLOAT64_C(   274.62) },
      { SIMDE_FLOAT64_C(   -95.38), SIMDE_FLOAT64_C(   699.76), SIMDE_FLOAT64_C(  -283.92), SIMDE_FLOAT64_C(  -926.28) },
      { SIMDE_FLOAT64_C(   352.88), SIMDE_FLOAT64_C(   699.76), SIMDE_FLOAT64_C(   283.92), SIMDE_FLOAT64_C(   274.62) } },
    { { SIMDE_FLOAT64_C(   670.80), SIMDE_FLOAT64_C(  -551.55), SIMDE_FLOAT64_C(  -919.21), SIMDE_FLOAT64_C(   114.61) },
      { SIMDE_FLOAT64_C(  -372.37), SIMDE_FLOAT64_C(   214.80), SIMDE_FLOAT64_C(  -336.48), SIMDE_FLOAT64_C(   511.13) },
      { SIMDE_FLOAT64_C(   670.80), SIMDE_FLOAT64_C(   214.80), SIMDE_FLOAT64_C(  -336.48), SIMDE_FLOAT64_C(   511.13) } },
    { { SIMDE_FLOAT64_C(   925.05), SIMDE_FLOAT64_C(   506.89), SIMDE_FLOAT64_C(   464.21), SIMDE_FLOAT64_C(  -220.41) },
      { SIMDE_FLOAT64_C(  -868.81), SIMDE_FLOAT64_C(  -682.45), SIMDE_FLOAT64_C(   376.85), SIMDE_FLOAT64_C(   374.58) },
      { SIMDE_FLOAT64_C(   868.81), SIMDE_FLOAT64_C(   682.45), SIMDE_FLOAT64_C(   376.85), SIMDE_FLOAT64_C(  -220.41) } }
  };

  simde__m256d a, b, r;

  a = simde_mm256_loadu_pd(test_vec[0].a);
  b = simde_mm256_loadu_pd(test_vec[0].b);
  r = simde_mm256_range_pd(a, b, 11);
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[0].r), 1);

  a = simde_mm256_loadu_pd(test_vec[1].a);
  b = simde_mm256_loadu_pd(test_vec[1].b);
  r = simde_mm256_range_pd(a, b, 4);
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[1].r), 1);

  a = simde_mm256_loadu_pd(test_vec[2].a);
  b = simde_mm256_loadu_pd(test_vec[2].b);
  r = simde_mm256_range_pd(a, b, 1);
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[2].r), 1);

  a = simde_mm256_loadu_pd(test_vec[3].a);
  b = simde_mm256_loadu_pd(test_vec[3].b);
  r = simde_mm256_range_pd(a, b, 2);
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[3].r), 1);

  a = simde_mm256_loadu_pd(test_vec[4].a);
  b = simde_mm256_loadu_pd(test_vec[4].b);
  r = simde_mm256_range_pd(a, b, 3);
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[4].r), 1);

  a = simde_mm256_loadu_pd(test_vec[5].a);
  b = simde_mm256_loadu_pd(test_vec[5].b);
  r = simde_mm256_range_pd(a, b, 9);
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[5].r), 1);

  a = simde_mm256_loadu_pd(test_vec[6].a);
  b = simde_mm256_loadu_pd(test_vec[6].b);
  r = simde_mm256_range_pd(a, b, 5);
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[6].r), 1);

  a = simde_mm256_loadu_pd(test_vec[7].a);
  b = simde_mm256_loadu_pd(test_vec[7].b);
  r = simde_mm256_range_pd(a, b, 0);
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);

  simde__m256d a, b, r;

  a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm256_range_pd(a, b, 11);

  simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm256_range_pd(a, b, 4);

  simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm256_range_pd(a, b, 1);

  simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm256_range_pd(a, b, 2);

  simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm256_range_pd(a, b, 3);

  simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm256_range_pd(a, b, 9);

  simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm256_range_pd(a, b, 5);

  simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm256_range_pd(a, b, 0);

  simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm256_mask_range_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m256d src, a, b, e, r;

  src = simde_mm256_set_pd(SIMDE_FLOAT64_C(   721.40), SIMDE_FLOAT64_C(   196.40), SIMDE_FLOAT64_C(   859.32), SIMDE_FLOAT64_C(  -787.01));
  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -160.67), SIMDE_FLOAT64_C(   330.35), SIMDE_FLOAT64_C(  -715.81), SIMDE_FLOAT64_C(  -506.47));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   913.20), SIMDE_FLOAT64_C(   678.56), SIMDE_FLOAT64_C(  -770.67), SIMDE_FLOAT64_C(  -291.88));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -913.20), SIMDE_FLOAT64_C(   196.40), SIMDE_FLOAT64_C(   859.32), SIMDE_FLOAT64_C(  -506.47));
  r = simde_mm256_mask_range_pd(src, UINT8_C(249), a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  src = simde_mm256_set_pd(SIMDE_FLOAT64_C(   507.48), SIMDE_FLOAT64_C(   -81.12), SIMDE_FLOAT64_C(   -74.85), SIMDE_FLOAT64_C(   315.28));
  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   304.80), SIMDE_FLOAT64_C(   583.61), SIMDE_FLOAT64_C(   197.96), SIMDE_FLOAT64_C(    30.92));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -859.49), SIMDE_FLOAT64_C(  -441.81), SIMDE_FLOAT64_C(   147.15), SIMDE_FLOAT64_C(  -266.99));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(   507.48), SIMDE_FLOAT64_C(   -81.12), SIMDE_FLOAT64_C(   147.15), SIMDE_FLOAT64_C(   315.28));
  r = simde_mm256_mask_range_pd(src, UINT8_C( 66), a, b, INT32_C(           6));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  src = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -455.10), SIMDE_FLOAT64_C(   957.60), SIMDE_FLOAT64_C(  -664.92), SIMDE_FLOAT64_C(  -668.08));
  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   647.53), SIMDE_FLOAT64_C(   595.89), SIMDE_FLOAT64_C(  -733.70), SIMDE_FLOAT64_C(   154.00));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   258.61), SIMDE_FLOAT64_C(  -513.15), SIMDE_FLOAT64_C(   -73.76), SIMDE_FLOAT64_C(  -449.51));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(   647.53), SIMDE_FLOAT64_C(   957.60), SIMDE_FLOAT64_C(    73.76), SIMDE_FLOAT64_C(   154.00));
  r = simde_mm256_mask_range_pd(src, UINT8_C(219), a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  src = simde_mm256_set_pd(SIMDE_FLOAT64_C(   480.69), SIMDE_FLOAT64_C(  -302.50), SIMDE_FLOAT64_C(   171.81), SIMDE_FLOAT64_C(  -834.59));
  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -352.70), SIMDE_FLOAT64_C(    60.35), SIMDE_FLOAT64_C(   -11.83), SIMDE_FLOAT64_C(   616.38));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   -80.86), SIMDE_FLOAT64_C(   952.10), SIMDE_FLOAT64_C(  -356.05), SIMDE_FLOAT64_C(  -813.87));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(   480.69), SIMDE_FLOAT64_C(  -302.50), SIMDE_FLOAT64_C(  -356.05), SIMDE_FLOAT64_C(   813.87));
  r = simde_mm256_mask_range_pd(src, UINT8_C( 19), a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  src = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -157.79), SIMDE_FLOAT64_C(   397.22), SIMDE_FLOAT64_C(    59.65), SIMDE_FLOAT64_C(  -489.70));
  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -491.19), SIMDE_FLOAT64_C(   589.12), SIMDE_FLOAT64_C(   387.12), SIMDE_FLOAT64_C(   354.82));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -796.08), SIMDE_FLOAT64_C(  -843.66), SIMDE_FLOAT64_C(   185.02), SIMDE_FLOAT64_C(   653.42));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -157.79), SIMDE_FLOAT64_C(   397.22), SIMDE_FLOAT64_C(    59.65), SIMDE_FLOAT64_C(  -489.70));
  r = simde_mm256_mask_range_pd(src, UINT8_C(128), a, b, INT32_C(          10));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  src = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -191.40), SIMDE_FLOAT64_C(   266.82), SIMDE_FLOAT64_C(   462.53), SIMDE_FLOAT64_C(  -356.81));
  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   580.71), SIMDE_FLOAT64_C(  -268.71), SIMDE_FLOAT64_C(  -710.71), SIMDE_FLOAT64_C(   964.32));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   463.58), SIMDE_FLOAT64_C(  -771.99), SIMDE_FLOAT64_C(   791.64), SIMDE_FLOAT64_C(   277.46));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(   580.71), SIMDE_FLOAT64_C(  -268.71), SIMDE_FLOAT64_C(   791.64), SIMDE_FLOAT64_C(  -356.81));
  r = simde_mm256_mask_range_pd(src, UINT8_C(174), a, b, INT32_C(           5));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  src = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -309.59), SIMDE_FLOAT64_C(  -773.31), SIMDE_FLOAT64_C(  -617.28), SIMDE_FLOAT64_C(  -819.89));
  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   -21.28), SIMDE_FLOAT64_C(  -162.91), SIMDE_FLOAT64_C(   532.62), SIMDE_FLOAT64_C(   623.91));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -426.84), SIMDE_FLOAT64_C(   487.53), SIMDE_FLOAT64_C(  -573.78), SIMDE_FLOAT64_C(   -80.27));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -426.84), SIMDE_FLOAT64_C(  -773.31), SIMDE_FLOAT64_C(  -573.78), SIMDE_FLOAT64_C(   623.91));
  r = simde_mm256_mask_range_pd(src, UINT8_C( 75), a, b, INT32_C(           7));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  src = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -712.94), SIMDE_FLOAT64_C(   722.49), SIMDE_FLOAT64_C(  -222.93), SIMDE_FLOAT64_C(   643.87));
  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   -46.36), SIMDE_FLOAT64_C(  -126.07), SIMDE_FLOAT64_C(    95.66), SIMDE_FLOAT64_C(   -10.69));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -337.59), SIMDE_FLOAT64_C(  -465.66), SIMDE_FLOAT64_C(   605.22), SIMDE_FLOAT64_C(   384.95));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -337.59), SIMDE_FLOAT64_C(   722.49), SIMDE_FLOAT64_C(  -222.93), SIMDE_FLOAT64_C(  -384.95));
  r = simde_mm256_mask_range_pd(src, UINT8_C(121), a, b, INT32_C(          15));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d src = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m256d r;
    SIMDE_CONSTIFY_16_(simde_mm256_mask_range_pd, r, simde_mm256_setzero_pd(), imm8, src, k, a, b);

    simde_test_x86_write_f64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_range_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m256d a, b, e, r;

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -491.29), SIMDE_FLOAT64_C(   -57.54), SIMDE_FLOAT64_C(   832.45), SIMDE_FLOAT64_C(  -874.01));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   683.04), SIMDE_FLOAT64_C(   951.08), SIMDE_FLOAT64_C(   632.87), SIMDE_FLOAT64_C(  -940.87));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -951.08), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00));
  r = simde_mm256_maskz_range_pd(UINT8_C(228), a, b, INT32_C(          13));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -850.71), SIMDE_FLOAT64_C(   214.38), SIMDE_FLOAT64_C(  -914.78), SIMDE_FLOAT64_C(  -338.24));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   435.45), SIMDE_FLOAT64_C(   793.16), SIMDE_FLOAT64_C(  -174.39), SIMDE_FLOAT64_C(  -341.62));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(   435.45), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   338.24));
  r = simde_mm256_maskz_range_pd(UINT8_C(137), a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -451.02), SIMDE_FLOAT64_C(   175.88), SIMDE_FLOAT64_C(   537.41), SIMDE_FLOAT64_C(   675.04));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(    25.39), SIMDE_FLOAT64_C(  -845.80), SIMDE_FLOAT64_C(  -439.17), SIMDE_FLOAT64_C(  -508.95));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   175.88), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   508.95));
  r = simde_mm256_maskz_range_pd(UINT8_C( 85), a, b, INT32_C(          10));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -269.79), SIMDE_FLOAT64_C(   383.50), SIMDE_FLOAT64_C(   349.23), SIMDE_FLOAT64_C(   787.74));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   809.02), SIMDE_FLOAT64_C(  -636.93), SIMDE_FLOAT64_C(   442.64), SIMDE_FLOAT64_C(   857.94));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -636.93), SIMDE_FLOAT64_C(  -349.23), SIMDE_FLOAT64_C(  -787.74));
  r = simde_mm256_maskz_range_pd(UINT8_C(119), a, b, INT32_C(          12));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   811.57), SIMDE_FLOAT64_C(   613.78), SIMDE_FLOAT64_C(   787.44), SIMDE_FLOAT64_C(  -402.82));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   729.89), SIMDE_FLOAT64_C(  -362.82), SIMDE_FLOAT64_C(  -727.85), SIMDE_FLOAT64_C(   936.73));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00));
  r = simde_mm256_maskz_range_pd(UINT8_C(192), a, b, INT32_C(           8));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   -14.01), SIMDE_FLOAT64_C(  -277.31), SIMDE_FLOAT64_C(   382.64), SIMDE_FLOAT64_C(   810.11));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -914.18), SIMDE_FLOAT64_C(   546.83), SIMDE_FLOAT64_C(   213.74), SIMDE_FLOAT64_C(   931.62));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00));
  r = simde_mm256_maskz_range_pd(UINT8_C(160), a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(    20.38), SIMDE_FLOAT64_C(  -880.70), SIMDE_FLOAT64_C(  -973.12), SIMDE_FLOAT64_C(   636.88));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   120.15), SIMDE_FLOAT64_C(  -536.98), SIMDE_FLOAT64_C(   977.25), SIMDE_FLOAT64_C(  -242.92));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -880.70), SIMDE_FLOAT64_C(  -973.12), SIMDE_FLOAT64_C(     0.00));
  r = simde_mm256_maskz_range_pd(UINT8_C(102), a, b, INT32_C(          12));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -737.51), SIMDE_FLOAT64_C(   376.14), SIMDE_FLOAT64_C(  -616.55), SIMDE_FLOAT64_C(  -351.29));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -167.81), SIMDE_FLOAT64_C(  -465.36), SIMDE_FLOAT64_C(   312.87), SIMDE_FLOAT64_C(  -804.98));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -737.51), SIMDE_FLOAT64_C(  -465.36), SIMDE_FLOAT64_C(  -616.55), SIMDE_FLOAT64_C(     0.00));
  r = simde_mm256_maskz_range_pd(UINT8_C(190), a, b, INT32_C(          15));
  simde_test_x86_assert_equal_f64x4(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m256d b = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m256d r;
    SIMDE_CONSTIFY_16_(simde_mm256_maskz_range_pd, r, simde_mm256_setzero_pd(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_range_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -538.10), SIMDE_FLOAT64_C(  -923.13), SIMDE_FLOAT64_C(  -505.34), SIMDE_FLOAT64_C(  -152.09),
        SIMDE_FLOAT64_C(  -619.63), SIMDE_FLOAT64_C(   411.91), SIMDE_FLOAT64_C(   522.74), SIMDE_FLOAT64_C(   733.25) },
      { SIMDE_FLOAT64_C(  -577.37), SIMDE_FLOAT64_C(   870.81), SIMDE_FLOAT64_C(     7.88), SIMDE_FLOAT64_C(   327.24),
        SIMDE_FLOAT64_C(   570.57), SIMDE_FLOAT64_C(   723.95), SIMDE_FLOAT64_C(   400.97), SIMDE_FLOAT64_C(   241.38) },
      { SIMDE_FLOAT64_C(   577.37), SIMDE_FLOAT64_C(   923.13), SIMDE_FLOAT64_C(   505.34), SIMDE_FLOAT64_C(   327.24),
        SIMDE_FLOAT64_C(   619.63), SIMDE_FLOAT64_C(   723.95), SIMDE_FLOAT64_C(   522.74), SIMDE_FLOAT64_C(   733.25) } },
    { { SIMDE_FLOAT64_C(  -827.60), SIMDE_FLOAT64_C(   481.76), SIMDE_FLOAT64_C(  -644.01), SIMDE_FLOAT64_C(  -199.97),
        SIMDE_FLOAT64_C(  -303.44), SIMDE_FLOAT64_C(    19.51), SIMDE_FLOAT64_C(  -688.85), SIMDE_FLOAT64_C(  -378.39) },
      { SIMDE_FLOAT64_C(  -473.60), SIMDE_FLOAT64_C(   775.37), SIMDE_FLOAT64_C(   401.21), SIMDE_FLOAT64_C(  -342.40),
        SIMDE_FLOAT64_C(  -907.08), SIMDE_FLOAT64_C(  -221.95), SIMDE_FLOAT64_C(  -967.82), SIMDE_FLOAT64_C(  -445.18) },
      { SIMDE_FLOAT64_C(  -827.60), SIMDE_FLOAT64_C(   481.76), SIMDE_FLOAT64_C(  -644.01), SIMDE_FLOAT64_C(  -342.40),
        SIMDE_FLOAT64_C(  -907.08), SIMDE_FLOAT64_C(  -221.95), SIMDE_FLOAT64_C(  -967.82), SIMDE_FLOAT64_C(  -445.18) } },
    { { SIMDE_FLOAT64_C(  -145.08), SIMDE_FLOAT64_C(  -473.16), SIMDE_FLOAT64_C(   402.73), SIMDE_FLOAT64_C(   235.29),
        SIMDE_FLOAT64_C(   938.75), SIMDE_FLOAT64_C(   -74.53), SIMDE_FLOAT64_C(   -31.46), SIMDE_FLOAT64_C(  -638.62) },
      { SIMDE_FLOAT64_C(  -203.72), SIMDE_FLOAT64_C(   976.42), SIMDE_FLOAT64_C(   688.62), SIMDE_FLOAT64_C(  -633.15),
        SIMDE_FLOAT64_C(   700.37), SIMDE_FLOAT64_C(    89.59), SIMDE_FLOAT64_C(   608.23), SIMDE_FLOAT64_C(   872.77) },
      { SIMDE_FLOAT64_C(  -145.08), SIMDE_FLOAT64_C(  -976.42), SIMDE_FLOAT64_C(   688.62), SIMDE_FLOAT64_C(   235.29),
        SIMDE_FLOAT64_C(   938.75), SIMDE_FLOAT64_C(   -89.59), SIMDE_FLOAT64_C(  -608.23), SIMDE_FLOAT64_C(  -872.77) } },
    { { SIMDE_FLOAT64_C(  -428.65), SIMDE_FLOAT64_C(   964.22), SIMDE_FLOAT64_C(  -327.20), SIMDE_FLOAT64_C(   267.91),
        SIMDE_FLOAT64_C(   -16.27), SIMDE_FLOAT64_C(   -16.05), SIMDE_FLOAT64_C(   889.52), SIMDE_FLOAT64_C(   510.13) },
      { SIMDE_FLOAT64_C(  -240.68), SIMDE_FLOAT64_C(   290.73), SIMDE_FLOAT64_C(  -832.27), SIMDE_FLOAT64_C(  -147.76),
        SIMDE_FLOAT64_C(  -931.22), SIMDE_FLOAT64_C(  -800.09), SIMDE_FLOAT64_C(   407.06), SIMDE_FLOAT64_C(   -76.30) },
      { SIMDE_FLOAT64_C(  -240.68), SIMDE_FLOAT64_C(   290.73), SIMDE_FLOAT64_C(  -327.20), SIMDE_FLOAT64_C(   147.76),
        SIMDE_FLOAT64_C(   -16.27), SIMDE_FLOAT64_C(   -16.05), SIMDE_FLOAT64_C(   407.06), SIMDE_FLOAT64_C(    76.30) } },
    { { SIMDE_FLOAT64_C(  -273.25), SIMDE_FLOAT64_C(  -190.21), SIMDE_FLOAT64_C(  -841.01), SIMDE_FLOAT64_C(  -334.50),
        SIMDE_FLOAT64_C(   735.25), SIMDE_FLOAT64_C(   127.53), SIMDE_FLOAT64_C(    26.88), SIMDE_FLOAT64_C(  -468.47) },
      { SIMDE_FLOAT64_C(   103.95), SIMDE_FLOAT64_C(  -284.49), SIMDE_FLOAT64_C(  -101.62), SIMDE_FLOAT64_C(  -195.68),
        SIMDE_FLOAT64_C(   805.10), SIMDE_FLOAT64_C(  -493.39), SIMDE_FLOAT64_C(  -322.91), SIMDE_FLOAT64_C(  -623.55) },
      { SIMDE_FLOAT64_C(  -273.25), SIMDE_FLOAT64_C(  -284.49), SIMDE_FLOAT64_C(  -841.01), SIMDE_FLOAT64_C(  -334.50),
        SIMDE_FLOAT64_C(   805.10), SIMDE_FLOAT64_C(   493.39), SIMDE_FLOAT64_C(   322.91), SIMDE_FLOAT64_C(  -623.55) } },
    { { SIMDE_FLOAT64_C(  -529.17), SIMDE_FLOAT64_C(   349.89), SIMDE_FLOAT64_C(   644.36), SIMDE_FLOAT64_C(   454.56),
        SIMDE_FLOAT64_C(  -666.16), SIMDE_FLOAT64_C(   533.89), SIMDE_FLOAT64_C(   -35.30), SIMDE_FLOAT64_C(    93.16) },
      { SIMDE_FLOAT64_C(  -175.39), SIMDE_FLOAT64_C(   132.43), SIMDE_FLOAT64_C(   945.40), SIMDE_FLOAT64_C(  -106.61),
        SIMDE_FLOAT64_C(   332.34), SIMDE_FLOAT64_C(   352.46), SIMDE_FLOAT64_C(   817.09), SIMDE_FLOAT64_C(  -940.90) },
      { SIMDE_FLOAT64_C(   175.39), SIMDE_FLOAT64_C(   349.89), SIMDE_FLOAT64_C(   945.40), SIMDE_FLOAT64_C(   454.56),
        SIMDE_FLOAT64_C(   332.34), SIMDE_FLOAT64_C(   533.89), SIMDE_FLOAT64_C(   817.09), SIMDE_FLOAT64_C(    93.16) } },
    { { SIMDE_FLOAT64_C(  -837.75), SIMDE_FLOAT64_C(   976.08), SIMDE_FLOAT64_C(  -275.40), SIMDE_FLOAT64_C(   897.50),
        SIMDE_FLOAT64_C(   103.61), SIMDE_FLOAT64_C(   751.48), SIMDE_FLOAT64_C(  -570.97), SIMDE_FLOAT64_C(  -792.44) },
      { SIMDE_FLOAT64_C(  -533.01), SIMDE_FLOAT64_C(   327.42), SIMDE_FLOAT64_C(    11.88), SIMDE_FLOAT64_C(  -727.91),
        SIMDE_FLOAT64_C(   834.03), SIMDE_FLOAT64_C(   688.97), SIMDE_FLOAT64_C(  -351.45), SIMDE_FLOAT64_C(  -695.14) },
      { SIMDE_FLOAT64_C(  -533.01), SIMDE_FLOAT64_C(   976.08), SIMDE_FLOAT64_C(    11.88), SIMDE_FLOAT64_C(   897.50),
        SIMDE_FLOAT64_C(   834.03), SIMDE_FLOAT64_C(   751.48), SIMDE_FLOAT64_C(  -351.45), SIMDE_FLOAT64_C(  -695.14) } },
    { { SIMDE_FLOAT64_C(    38.86), SIMDE_FLOAT64_C(  -707.09), SIMDE_FLOAT64_C(   759.43), SIMDE_FLOAT64_C(   372.70),
        SIMDE_FLOAT64_C(   826.80), SIMDE_FLOAT64_C(  -275.88), SIMDE_FLOAT64_C(  -534.14), SIMDE_FLOAT64_C(  -348.59) },
      { SIMDE_FLOAT64_C(   856.55), SIMDE_FLOAT64_C(  -588.74), SIMDE_FLOAT64_C(   544.80), SIMDE_FLOAT64_C(   188.90),
        SIMDE_FLOAT64_C(   763.72), SIMDE_FLOAT64_C(   361.89), SIMDE_FLOAT64_C(   247.99), SIMDE_FLOAT64_C(   925.97) },
      { SIMDE_FLOAT64_C(    38.86), SIMDE_FLOAT64_C(  -707.09), SIMDE_FLOAT64_C(   544.80), SIMDE_FLOAT64_C(   188.90),
        SIMDE_FLOAT64_C(   763.72), SIMDE_FLOAT64_C(  -275.88), SIMDE_FLOAT64_C(  -534.14), SIMDE_FLOAT64_C(  -348.59) } }
  };

  simde__m512d a, b, r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  b = simde_mm512_loadu_pd(test_vec[0].b);
  r = simde_mm512_range_pd(a, b, 11);
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  a = simde_mm512_loadu_pd(test_vec[1].a);
  b = simde_mm512_loadu_pd(test_vec[1].b);
  r = simde_mm512_range_pd(a, b, 4);
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  a = simde_mm512_loadu_pd(test_vec[2].a);
  b = simde_mm512_loadu_pd(test_vec[2].b);
  r = simde_mm512_range_pd(a, b, 1);
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  b = simde_mm512_loadu_pd(test_vec[3].b);
  r = simde_mm512_range_pd(a, b, 2);
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  a = simde_mm512_loadu_pd(test_vec[4].a);
  b = simde_mm512_loadu_pd(test_vec[4].b);
  r = simde_mm512_range_pd(a, b, 3);
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  a = simde_mm512_loadu_pd(test_vec[5].a);
  b = simde_mm512_loadu_pd(test_vec[5].b);
  r = simde_mm512_range_pd(a, b, 9);
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  b = simde_mm512_loadu_pd(test_vec[6].b);
  r = simde_mm512_range_pd(a, b, 5);
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  b = simde_mm512_loadu_pd(test_vec[7].b);
  r = simde_mm512_range_pd(a, b, 0);
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);

  simde__m512d a, b, r;

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm512_range_pd(a, b, 11);

  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm512_range_pd(a, b, 4);

  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm512_range_pd(a, b, 1);

  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm512_range_pd(a, b, 2);

  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm512_range_pd(a, b, 3);

  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm512_range_pd(a, b, 9);

  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm512_range_pd(a, b, 5);

  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  r = simde_mm512_range_pd(a, b, 0);

  simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_mm512_mask_range_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m512d src, a, b, e, r;

  src = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -815.01), SIMDE_FLOAT64_C(  -900.08), SIMDE_FLOAT64_C(   232.89), SIMDE_FLOAT64_C(  -900.14),
                           SIMDE_FLOAT64_C(  -826.33), SIMDE_FLOAT64_C(  -909.36), SIMDE_FLOAT64_C(  -362.80), SIMDE_FLOAT64_C(  -326.67));
  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   489.93), SIMDE_FLOAT64_C(    18.24), SIMDE_FLOAT64_C(  -633.02), SIMDE_FLOAT64_C(  -517.17),
                         SIMDE_FLOAT64_C(   -31.50), SIMDE_FLOAT64_C(   855.15), SIMDE_FLOAT64_C(   229.18), SIMDE_FLOAT64_C(   989.52));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(   533.35), SIMDE_FLOAT64_C(   215.69), SIMDE_FLOAT64_C(   614.42), SIMDE_FLOAT64_C(   761.72),
                         SIMDE_FLOAT64_C(  -255.85), SIMDE_FLOAT64_C(  -511.69), SIMDE_FLOAT64_C(  -939.34), SIMDE_FLOAT64_C(  -968.03));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -815.01), SIMDE_FLOAT64_C(   215.69), SIMDE_FLOAT64_C(   614.42), SIMDE_FLOAT64_C(   761.72),
                         SIMDE_FLOAT64_C(    31.50), SIMDE_FLOAT64_C(   855.15), SIMDE_FLOAT64_C(  -362.80), SIMDE_FLOAT64_C(  -326.67));
  r = simde_mm512_mask_range_pd(src, UINT8_C(124), a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  src = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -853.79), SIMDE_FLOAT64_C(  -717.88), SIMDE_FLOAT64_C(    33.69), SIMDE_FLOAT64_C(  -944.44),
                           SIMDE_FLOAT64_C(   644.92), SIMDE_FLOAT64_C(  -639.63), SIMDE_FLOAT64_C(   606.84), SIMDE_FLOAT64_C(  -541.57));
  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(    37.59), SIMDE_FLOAT64_C(   796.15), SIMDE_FLOAT64_C(   296.80), SIMDE_FLOAT64_C(   182.44),
                         SIMDE_FLOAT64_C(  -433.03), SIMDE_FLOAT64_C(   307.27), SIMDE_FLOAT64_C(   379.10), SIMDE_FLOAT64_C(  -618.02));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -742.78), SIMDE_FLOAT64_C(   344.19), SIMDE_FLOAT64_C(   436.55), SIMDE_FLOAT64_C(   768.91),
                         SIMDE_FLOAT64_C(   283.53), SIMDE_FLOAT64_C(   404.57), SIMDE_FLOAT64_C(  -721.02), SIMDE_FLOAT64_C(  -734.71));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -853.79), SIMDE_FLOAT64_C(  -344.19), SIMDE_FLOAT64_C(  -296.80), SIMDE_FLOAT64_C(  -944.44),
                         SIMDE_FLOAT64_C(   644.92), SIMDE_FLOAT64_C(  -307.27), SIMDE_FLOAT64_C(  -379.10), SIMDE_FLOAT64_C(  -618.02));
  r = simde_mm512_mask_range_pd(src, UINT8_C(103), a, b, INT32_C(          14));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  src = simde_mm512_set_pd(SIMDE_FLOAT64_C(   953.25), SIMDE_FLOAT64_C(  -753.90), SIMDE_FLOAT64_C(   854.82), SIMDE_FLOAT64_C(   592.88),
                           SIMDE_FLOAT64_C(  -360.74), SIMDE_FLOAT64_C(   396.39), SIMDE_FLOAT64_C(   871.64), SIMDE_FLOAT64_C(   105.91));
  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   501.57), SIMDE_FLOAT64_C(   826.97), SIMDE_FLOAT64_C(  -836.16), SIMDE_FLOAT64_C(  -805.70),
                         SIMDE_FLOAT64_C(  -552.13), SIMDE_FLOAT64_C(   781.87), SIMDE_FLOAT64_C(   -13.06), SIMDE_FLOAT64_C(  -698.34));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(   451.58), SIMDE_FLOAT64_C(  -194.06), SIMDE_FLOAT64_C(    63.66), SIMDE_FLOAT64_C(  -953.00),
                         SIMDE_FLOAT64_C(  -473.04), SIMDE_FLOAT64_C(  -201.63), SIMDE_FLOAT64_C(     9.41), SIMDE_FLOAT64_C(  -269.19));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -451.58), SIMDE_FLOAT64_C(  -753.90), SIMDE_FLOAT64_C(   854.82), SIMDE_FLOAT64_C(   592.88),
                         SIMDE_FLOAT64_C(  -360.74), SIMDE_FLOAT64_C(   396.39), SIMDE_FLOAT64_C(    -9.41), SIMDE_FLOAT64_C(  -269.19));
  r = simde_mm512_mask_range_pd(src, UINT8_C(131), a, b, INT32_C(          14));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  src = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -534.79), SIMDE_FLOAT64_C(  -296.28), SIMDE_FLOAT64_C(  -202.71), SIMDE_FLOAT64_C(    68.82),
                           SIMDE_FLOAT64_C(  -167.92), SIMDE_FLOAT64_C(   691.38), SIMDE_FLOAT64_C(  -111.88), SIMDE_FLOAT64_C(  -425.15));
  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   601.63), SIMDE_FLOAT64_C(   236.79), SIMDE_FLOAT64_C(   984.30), SIMDE_FLOAT64_C(   819.77),
                         SIMDE_FLOAT64_C(  -750.15), SIMDE_FLOAT64_C(   682.64), SIMDE_FLOAT64_C(  -679.97), SIMDE_FLOAT64_C(  -703.40));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(   731.03), SIMDE_FLOAT64_C(   268.54), SIMDE_FLOAT64_C(  -503.71), SIMDE_FLOAT64_C(   -67.34),
                         SIMDE_FLOAT64_C(  -740.87), SIMDE_FLOAT64_C(   765.48), SIMDE_FLOAT64_C(   431.09), SIMDE_FLOAT64_C(  -567.84));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(   731.03), SIMDE_FLOAT64_C(  -296.28), SIMDE_FLOAT64_C(  -202.71), SIMDE_FLOAT64_C(    68.82),
                         SIMDE_FLOAT64_C(  -167.92), SIMDE_FLOAT64_C(   765.48), SIMDE_FLOAT64_C(  -431.09), SIMDE_FLOAT64_C(  -567.84));
  r = simde_mm512_mask_range_pd(src, UINT8_C(135), a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  src = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -166.74), SIMDE_FLOAT64_C(   655.25), SIMDE_FLOAT64_C(  -595.95), SIMDE_FLOAT64_C(   141.88),
                           SIMDE_FLOAT64_C(  -232.88), SIMDE_FLOAT64_C(   829.19), SIMDE_FLOAT64_C(  -205.31), SIMDE_FLOAT64_C(   315.54));
  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -250.27), SIMDE_FLOAT64_C(   509.30), SIMDE_FLOAT64_C(  -763.56), SIMDE_FLOAT64_C(    67.09),
                         SIMDE_FLOAT64_C(   189.28), SIMDE_FLOAT64_C(   939.84), SIMDE_FLOAT64_C(   630.55), SIMDE_FLOAT64_C(  -275.93));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -303.82), SIMDE_FLOAT64_C(   154.17), SIMDE_FLOAT64_C(   166.19), SIMDE_FLOAT64_C(   -69.30),
                         SIMDE_FLOAT64_C(   723.08), SIMDE_FLOAT64_C(  -265.98), SIMDE_FLOAT64_C(   329.07), SIMDE_FLOAT64_C(  -513.71));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -250.27), SIMDE_FLOAT64_C(  -509.30), SIMDE_FLOAT64_C(  -595.95), SIMDE_FLOAT64_C(   -67.09),
                         SIMDE_FLOAT64_C(  -232.88), SIMDE_FLOAT64_C(  -939.84), SIMDE_FLOAT64_C(  -205.31), SIMDE_FLOAT64_C(  -275.93));
  r = simde_mm512_mask_range_pd(src, UINT8_C(213), a, b, INT32_C(          13));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  src = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -955.09), SIMDE_FLOAT64_C(  -387.44), SIMDE_FLOAT64_C(  -990.59), SIMDE_FLOAT64_C(  -784.28),
                           SIMDE_FLOAT64_C(   817.87), SIMDE_FLOAT64_C(  -306.14), SIMDE_FLOAT64_C(   192.47), SIMDE_FLOAT64_C(  -913.16));
  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   624.92), SIMDE_FLOAT64_C(  -781.74), SIMDE_FLOAT64_C(   155.84), SIMDE_FLOAT64_C(   685.08),
                         SIMDE_FLOAT64_C(  -412.29), SIMDE_FLOAT64_C(  -568.22), SIMDE_FLOAT64_C(  -551.04), SIMDE_FLOAT64_C(   754.45));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -230.90), SIMDE_FLOAT64_C(   183.49), SIMDE_FLOAT64_C(  -652.34), SIMDE_FLOAT64_C(  -964.92),
                         SIMDE_FLOAT64_C(   854.42), SIMDE_FLOAT64_C(   861.36), SIMDE_FLOAT64_C(   285.35), SIMDE_FLOAT64_C(  -654.88));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -955.09), SIMDE_FLOAT64_C(  -387.44), SIMDE_FLOAT64_C(   652.34), SIMDE_FLOAT64_C(  -784.28),
                         SIMDE_FLOAT64_C(   817.87), SIMDE_FLOAT64_C(   861.36), SIMDE_FLOAT64_C(   551.04), SIMDE_FLOAT64_C(  -913.16));
  r = simde_mm512_mask_range_pd(src, UINT8_C( 38), a, b, INT32_C(          11));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  src = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -945.53), SIMDE_FLOAT64_C(  -997.15), SIMDE_FLOAT64_C(   311.75), SIMDE_FLOAT64_C(   360.61),
                           SIMDE_FLOAT64_C(  -189.63), SIMDE_FLOAT64_C(   224.91), SIMDE_FLOAT64_C(   935.29), SIMDE_FLOAT64_C(  -885.81));
  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   272.18), SIMDE_FLOAT64_C(  -287.57), SIMDE_FLOAT64_C(   496.63), SIMDE_FLOAT64_C(  -159.59),
                         SIMDE_FLOAT64_C(  -736.52), SIMDE_FLOAT64_C(   742.18), SIMDE_FLOAT64_C(  -936.12), SIMDE_FLOAT64_C(  -781.43));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(   883.79), SIMDE_FLOAT64_C(   587.96), SIMDE_FLOAT64_C(  -226.86), SIMDE_FLOAT64_C(  -977.57),
                         SIMDE_FLOAT64_C(  -697.39), SIMDE_FLOAT64_C(  -571.98), SIMDE_FLOAT64_C(  -602.49), SIMDE_FLOAT64_C(  -915.66));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(   883.79), SIMDE_FLOAT64_C(  -997.15), SIMDE_FLOAT64_C(   496.63), SIMDE_FLOAT64_C(   360.61),
                         SIMDE_FLOAT64_C(   736.52), SIMDE_FLOAT64_C(   742.18), SIMDE_FLOAT64_C(   935.29), SIMDE_FLOAT64_C(   915.66));
  r = simde_mm512_mask_range_pd(src, UINT8_C(173), a, b, INT32_C(          11));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  src = simde_mm512_set_pd(SIMDE_FLOAT64_C(   527.10), SIMDE_FLOAT64_C(  -672.57), SIMDE_FLOAT64_C(   925.24), SIMDE_FLOAT64_C(  -697.81),
                           SIMDE_FLOAT64_C(  -607.86), SIMDE_FLOAT64_C(   811.05), SIMDE_FLOAT64_C(  -768.55), SIMDE_FLOAT64_C(   623.04));
  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   710.66), SIMDE_FLOAT64_C(   806.39), SIMDE_FLOAT64_C(   -42.97), SIMDE_FLOAT64_C(   968.47),
                         SIMDE_FLOAT64_C(   742.51), SIMDE_FLOAT64_C(  -261.54), SIMDE_FLOAT64_C(  -161.15), SIMDE_FLOAT64_C(   688.04));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -653.00), SIMDE_FLOAT64_C(  -669.56), SIMDE_FLOAT64_C(   291.64), SIMDE_FLOAT64_C(   918.98),
                         SIMDE_FLOAT64_C(   932.93), SIMDE_FLOAT64_C(   207.29), SIMDE_FLOAT64_C(  -353.20), SIMDE_FLOAT64_C(   220.50));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(   710.66), SIMDE_FLOAT64_C(   806.39), SIMDE_FLOAT64_C(   291.64), SIMDE_FLOAT64_C(   968.47),
                         SIMDE_FLOAT64_C(  -607.86), SIMDE_FLOAT64_C(   811.05), SIMDE_FLOAT64_C(   161.15), SIMDE_FLOAT64_C(   623.04));
  r = simde_mm512_mask_range_pd(src, UINT8_C(242), a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d src = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m512d r;
    SIMDE_CONSTIFY_16_(simde_mm512_mask_range_pd, r, simde_mm512_setzero_pd(), imm8, src, k, a, b);

    simde_test_x86_write_f64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_range_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  simde__m512d a, b, e, r;

  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   197.38), SIMDE_FLOAT64_C(   558.75), SIMDE_FLOAT64_C(  -531.88), SIMDE_FLOAT64_C(  -194.76),
                         SIMDE_FLOAT64_C(   747.70), SIMDE_FLOAT64_C(  -763.33), SIMDE_FLOAT64_C(   182.20), SIMDE_FLOAT64_C(   120.14));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(   -41.93), SIMDE_FLOAT64_C(   136.26), SIMDE_FLOAT64_C(   212.85), SIMDE_FLOAT64_C(  -780.39),
                         SIMDE_FLOAT64_C(  -702.59), SIMDE_FLOAT64_C(   524.81), SIMDE_FLOAT64_C(   483.99), SIMDE_FLOAT64_C(  -229.69));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(   -41.93), SIMDE_FLOAT64_C(   136.26), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
                         SIMDE_FLOAT64_C(  -702.59), SIMDE_FLOAT64_C(   524.81), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00));
  r = simde_mm512_maskz_range_pd(UINT8_C(204), a, b, INT32_C(           6));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   327.53), SIMDE_FLOAT64_C(    68.54), SIMDE_FLOAT64_C(  -977.31), SIMDE_FLOAT64_C(   408.55),
                         SIMDE_FLOAT64_C(   135.60), SIMDE_FLOAT64_C(  -184.60), SIMDE_FLOAT64_C(  -238.25), SIMDE_FLOAT64_C(   915.10));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(   988.52), SIMDE_FLOAT64_C(  -909.23), SIMDE_FLOAT64_C(  -205.33), SIMDE_FLOAT64_C(   751.85),
                         SIMDE_FLOAT64_C(   -91.43), SIMDE_FLOAT64_C(   674.53), SIMDE_FLOAT64_C(   398.98), SIMDE_FLOAT64_C(   314.32));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    68.54), SIMDE_FLOAT64_C(  -205.33), SIMDE_FLOAT64_C(   408.55),
                         SIMDE_FLOAT64_C(   -91.43), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -238.25), SIMDE_FLOAT64_C(     0.00));
  r = simde_mm512_maskz_range_pd(UINT8_C(122), a, b, INT32_C(           6));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   804.72), SIMDE_FLOAT64_C(   524.36), SIMDE_FLOAT64_C(   618.20), SIMDE_FLOAT64_C(   585.11),
                         SIMDE_FLOAT64_C(   226.95), SIMDE_FLOAT64_C(  -906.62), SIMDE_FLOAT64_C(  -898.88), SIMDE_FLOAT64_C(  -543.36));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -419.24), SIMDE_FLOAT64_C(  -451.83), SIMDE_FLOAT64_C(  -322.11), SIMDE_FLOAT64_C(   765.36),
                         SIMDE_FLOAT64_C(   786.41), SIMDE_FLOAT64_C(  -237.21), SIMDE_FLOAT64_C(  -339.38), SIMDE_FLOAT64_C(  -168.95));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   322.11), SIMDE_FLOAT64_C(     0.00),
                         SIMDE_FLOAT64_C(   226.95), SIMDE_FLOAT64_C(  -906.62), SIMDE_FLOAT64_C(  -898.88), SIMDE_FLOAT64_C(  -543.36));
  r = simde_mm512_maskz_range_pd(UINT8_C( 47), a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -967.14), SIMDE_FLOAT64_C(  -173.66), SIMDE_FLOAT64_C(   -41.23), SIMDE_FLOAT64_C(  -718.99),
                         SIMDE_FLOAT64_C(   917.77), SIMDE_FLOAT64_C(   284.24), SIMDE_FLOAT64_C(  -117.97), SIMDE_FLOAT64_C(  -396.55));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(   906.49), SIMDE_FLOAT64_C(  -603.07), SIMDE_FLOAT64_C(  -521.98), SIMDE_FLOAT64_C(   813.11),
                         SIMDE_FLOAT64_C(  -704.19), SIMDE_FLOAT64_C(  -978.62), SIMDE_FLOAT64_C(   -82.90), SIMDE_FLOAT64_C(   753.44));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -967.14), SIMDE_FLOAT64_C(  -603.07), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
                         SIMDE_FLOAT64_C(   704.19), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -117.97), SIMDE_FLOAT64_C(  -396.55));
  r = simde_mm512_maskz_range_pd(UINT8_C(203), a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   655.32), SIMDE_FLOAT64_C(  -857.85), SIMDE_FLOAT64_C(  -450.44), SIMDE_FLOAT64_C(   889.95),
                         SIMDE_FLOAT64_C(  -644.26), SIMDE_FLOAT64_C(   786.76), SIMDE_FLOAT64_C(   229.33), SIMDE_FLOAT64_C(   524.69));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(   931.28), SIMDE_FLOAT64_C(   922.98), SIMDE_FLOAT64_C(  -160.48), SIMDE_FLOAT64_C(  -352.96),
                         SIMDE_FLOAT64_C(    40.94), SIMDE_FLOAT64_C(  -763.93), SIMDE_FLOAT64_C(  -309.68), SIMDE_FLOAT64_C(   227.45));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -450.44), SIMDE_FLOAT64_C(     0.00),
                         SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -786.76), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -524.69));
  r = simde_mm512_maskz_range_pd(UINT8_C( 37), a, b, INT32_C(          15));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -686.16), SIMDE_FLOAT64_C(   -60.70), SIMDE_FLOAT64_C(  -741.77), SIMDE_FLOAT64_C(  -499.27),
                         SIMDE_FLOAT64_C(  -356.51), SIMDE_FLOAT64_C(  -763.15), SIMDE_FLOAT64_C(   583.63), SIMDE_FLOAT64_C(  -109.95));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(   105.03), SIMDE_FLOAT64_C(   670.56), SIMDE_FLOAT64_C(   745.02), SIMDE_FLOAT64_C(   318.27),
                         SIMDE_FLOAT64_C(  -558.77), SIMDE_FLOAT64_C(  -779.67), SIMDE_FLOAT64_C(   336.23), SIMDE_FLOAT64_C(  -263.74));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -318.27),
                         SIMDE_FLOAT64_C(  -356.51), SIMDE_FLOAT64_C(  -763.15), SIMDE_FLOAT64_C(   336.23), SIMDE_FLOAT64_C(     0.00));
  r = simde_mm512_maskz_range_pd(UINT8_C( 30), a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(   580.27), SIMDE_FLOAT64_C(   922.98), SIMDE_FLOAT64_C(   451.90), SIMDE_FLOAT64_C(   -66.77),
                         SIMDE_FLOAT64_C(  -117.96), SIMDE_FLOAT64_C(   215.82), SIMDE_FLOAT64_C(  -757.09), SIMDE_FLOAT64_C(   654.59));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -713.21), SIMDE_FLOAT64_C(  -367.66), SIMDE_FLOAT64_C(  -598.39), SIMDE_FLOAT64_C(  -950.06),
                         SIMDE_FLOAT64_C(    48.71), SIMDE_FLOAT64_C(   511.55), SIMDE_FLOAT64_C(   845.96), SIMDE_FLOAT64_C(  -708.58));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(   580.27), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   451.90), SIMDE_FLOAT64_C(     0.00),
                         SIMDE_FLOAT64_C(   -48.71), SIMDE_FLOAT64_C(   511.55), SIMDE_FLOAT64_C(  -845.96), SIMDE_FLOAT64_C(     0.00));
  r = simde_mm512_maskz_range_pd(UINT8_C(174), a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  a = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -361.11), SIMDE_FLOAT64_C(   722.51), SIMDE_FLOAT64_C(   667.26), SIMDE_FLOAT64_C(   320.63),
                         SIMDE_FLOAT64_C(   281.28), SIMDE_FLOAT64_C(   446.92), SIMDE_FLOAT64_C(   984.40), SIMDE_FLOAT64_C(  -454.98));
  b = simde_mm512_set_pd(SIMDE_FLOAT64_C(  -830.60), SIMDE_FLOAT64_C(   755.95), SIMDE_FLOAT64_C(   398.51), SIMDE_FLOAT64_C(   -46.43),
                         SIMDE_FLOAT64_C(   513.04), SIMDE_FLOAT64_C(   743.92), SIMDE_FLOAT64_C(   393.06), SIMDE_FLOAT64_C(   412.28));
  e = simde_mm512_set_pd(SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   320.63),
                         SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   454.98));
  r = simde_mm512_maskz_range_pd(UINT8_C( 17), a, b, INT32_C(          11));
  simde_test_x86_assert_equal_f64x8(r, e, 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m512d r;
    SIMDE_CONSTIFY_16_(simde_mm512_maskz_range_pd, r, simde_mm512_setzero_pd(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_range_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   947.75), SIMDE_FLOAT32_C(   -97.20), SIMDE_FLOAT32_C(  -691.97), SIMDE_FLOAT32_C(   313.76) },
      { SIMDE_FLOAT32_C(   791.74), SIMDE_FLOAT32_C(  -857.28), SIMDE_FLOAT32_C(   290.69), SIMDE_FLOAT32_C(   907.53) },
       INT32_C(           6),
      { SIMDE_FLOAT32_C(   791.74), SIMDE_FLOAT32_C(   -97.20), SIMDE_FLOAT32_C(  -691.97), SIMDE_FLOAT32_C(   313.76) } },
    { { SIMDE_FLOAT32_C(  -548.75), SIMDE_FLOAT32_C(   688.48), SIMDE_FLOAT32_C(   890.89), SIMDE_FLOAT32_C(  -755.30) },
      { SIMDE_FLOAT32_C(   429.14), SIMDE_FLOAT32_C(   889.39), SIMDE_FLOAT32_C(  -136.81), SIMDE_FLOAT32_C(  -718.79) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(  -548.75), SIMDE_FLOAT32_C(   688.48), SIMDE_FLOAT32_C(   890.89), SIMDE_FLOAT32_C(  -755.30) } },
    { { SIMDE_FLOAT32_C(   -45.09), SIMDE_FLOAT32_C(   230.04), SIMDE_FLOAT32_C(   811.99), SIMDE_FLOAT32_C(  -653.58) },
      { SIMDE_FLOAT32_C(  -585.24), SIMDE_FLOAT32_C(  -266.32), SIMDE_FLOAT32_C(  -546.18), SIMDE_FLOAT32_C(   265.52) },
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   585.24), SIMDE_FLOAT32_C(   230.04), SIMDE_FLOAT32_C(   811.99), SIMDE_FLOAT32_C(  -653.58) } },
    { { SIMDE_FLOAT32_C(   324.35), SIMDE_FLOAT32_C(   785.92), SIMDE_FLOAT32_C(   409.14), SIMDE_FLOAT32_C(  -154.92) },
      { SIMDE_FLOAT32_C(   733.67), SIMDE_FLOAT32_C(  -688.06), SIMDE_FLOAT32_C(   153.11), SIMDE_FLOAT32_C(    47.43) },
       INT32_C(          14),
      { SIMDE_FLOAT32_C(  -324.35), SIMDE_FLOAT32_C(   785.92), SIMDE_FLOAT32_C(   409.14), SIMDE_FLOAT32_C(  -154.92) } },
    { { SIMDE_FLOAT32_C(   295.83), SIMDE_FLOAT32_C(  -661.88), SIMDE_FLOAT32_C(  -988.80), SIMDE_FLOAT32_C(  -430.24) },
      { SIMDE_FLOAT32_C(  -210.63), SIMDE_FLOAT32_C(   699.69), SIMDE_FLOAT32_C(  -539.35), SIMDE_FLOAT32_C(    34.06) },
       INT32_C(          14),
      { SIMDE_FLOAT32_C(  -210.63), SIMDE_FLOAT32_C(  -661.88), SIMDE_FLOAT32_C(  -988.80), SIMDE_FLOAT32_C(  -430.24) } },
    { { SIMDE_FLOAT32_C(  -649.97), SIMDE_FLOAT32_C(   897.25), SIMDE_FLOAT32_C(   410.05), SIMDE_FLOAT32_C(  -334.38) },
      { SIMDE_FLOAT32_C(  -147.84), SIMDE_FLOAT32_C(  -359.91), SIMDE_FLOAT32_C(  -522.39), SIMDE_FLOAT32_C(   198.57) },
       INT32_C(           5),
      { SIMDE_FLOAT32_C(  -147.84), SIMDE_FLOAT32_C(   897.25), SIMDE_FLOAT32_C(   410.05), SIMDE_FLOAT32_C(  -334.38) } },
    { { SIMDE_FLOAT32_C(   211.29), SIMDE_FLOAT32_C(   652.40), SIMDE_FLOAT32_C(  -679.63), SIMDE_FLOAT32_C(  -382.50) },
      { SIMDE_FLOAT32_C(   -23.25), SIMDE_FLOAT32_C(  -893.71), SIMDE_FLOAT32_C(  -973.36), SIMDE_FLOAT32_C(   821.82) },
       INT32_C(          12),
      { SIMDE_FLOAT32_C(   -23.25), SIMDE_FLOAT32_C(   652.40), SIMDE_FLOAT32_C(  -679.63), SIMDE_FLOAT32_C(  -382.50) } },
    { { SIMDE_FLOAT32_C(  -661.42), SIMDE_FLOAT32_C(   -25.07), SIMDE_FLOAT32_C(  -112.61), SIMDE_FLOAT32_C(  -557.75) },
      { SIMDE_FLOAT32_C(  -729.24), SIMDE_FLOAT32_C(   225.51), SIMDE_FLOAT32_C(  -546.54), SIMDE_FLOAT32_C(  -159.48) },
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   729.24), SIMDE_FLOAT32_C(   -25.07), SIMDE_FLOAT32_C(  -112.61), SIMDE_FLOAT32_C(  -557.75) } },
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_x_mm_range_ss(a, b, INT32_C(           6));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_x_mm_range_ss(a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_x_mm_range_ss(a, b, INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_x_mm_range_ss(a, b, INT32_C(          14));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_x_mm_range_ss(a, b, INT32_C(          14));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_x_mm_range_ss(a, b, INT32_C(           5));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_x_mm_range_ss(a, b, INT32_C(           12));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_x_mm_range_ss(a, b, INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m128 r;
    SIMDE_CONSTIFY_16_(simde_x_mm_range_ss, r, simde_mm_setzero_ps(), imm8, a, b);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_range_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   -57.69), SIMDE_FLOAT32_C(   161.65), SIMDE_FLOAT32_C(  -852.14), SIMDE_FLOAT32_C(   635.17) },
      UINT8_C( 52),
      { SIMDE_FLOAT32_C(   468.35), SIMDE_FLOAT32_C(   724.81), SIMDE_FLOAT32_C(   577.52), SIMDE_FLOAT32_C(   574.19) },
      { SIMDE_FLOAT32_C(   277.24), SIMDE_FLOAT32_C(   787.90), SIMDE_FLOAT32_C(   160.06), SIMDE_FLOAT32_C(   -11.06) },
       INT32_C(           5),
      { SIMDE_FLOAT32_C(   -57.69), SIMDE_FLOAT32_C(   724.81), SIMDE_FLOAT32_C(   577.52), SIMDE_FLOAT32_C(   574.19) } },
    { { SIMDE_FLOAT32_C(  -380.86), SIMDE_FLOAT32_C(   579.10), SIMDE_FLOAT32_C(   673.02), SIMDE_FLOAT32_C(   346.64) },
      UINT8_C(213),
      { SIMDE_FLOAT32_C(   901.03), SIMDE_FLOAT32_C(   930.89), SIMDE_FLOAT32_C(  -191.46), SIMDE_FLOAT32_C(   441.50) },
      { SIMDE_FLOAT32_C(  -285.40), SIMDE_FLOAT32_C(   166.01), SIMDE_FLOAT32_C(   358.79), SIMDE_FLOAT32_C(   892.65) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(   285.40), SIMDE_FLOAT32_C(   930.89), SIMDE_FLOAT32_C(  -191.46), SIMDE_FLOAT32_C(   441.50) } },
    { { SIMDE_FLOAT32_C(   514.76), SIMDE_FLOAT32_C(  -820.75), SIMDE_FLOAT32_C(   636.79), SIMDE_FLOAT32_C(  -542.93) },
      UINT8_C( 94),
      { SIMDE_FLOAT32_C(   784.64), SIMDE_FLOAT32_C(  -907.77), SIMDE_FLOAT32_C(  -431.78), SIMDE_FLOAT32_C(   252.99) },
      { SIMDE_FLOAT32_C(   817.04), SIMDE_FLOAT32_C(  -854.26), SIMDE_FLOAT32_C(  -172.82), SIMDE_FLOAT32_C(    94.28) },
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   514.76), SIMDE_FLOAT32_C(  -907.77), SIMDE_FLOAT32_C(  -431.78), SIMDE_FLOAT32_C(   252.99) } },
    { { SIMDE_FLOAT32_C(   987.24), SIMDE_FLOAT32_C(  -916.78), SIMDE_FLOAT32_C(  -756.04), SIMDE_FLOAT32_C(  -393.62) },
      UINT8_C( 38),
      { SIMDE_FLOAT32_C(   916.98), SIMDE_FLOAT32_C(   953.02), SIMDE_FLOAT32_C(   305.22), SIMDE_FLOAT32_C(   818.01) },
      { SIMDE_FLOAT32_C(   883.91), SIMDE_FLOAT32_C(  -886.23), SIMDE_FLOAT32_C(   259.51), SIMDE_FLOAT32_C(  -401.49) },
       INT32_C(           9),
      { SIMDE_FLOAT32_C(   987.24), SIMDE_FLOAT32_C(   953.02), SIMDE_FLOAT32_C(   305.22), SIMDE_FLOAT32_C(   818.01) } },
    { { SIMDE_FLOAT32_C(  -381.70), SIMDE_FLOAT32_C(  -508.84), SIMDE_FLOAT32_C(  -780.32), SIMDE_FLOAT32_C(  -866.94) },
      UINT8_C( 11),
      { SIMDE_FLOAT32_C(   856.47), SIMDE_FLOAT32_C(  -409.87), SIMDE_FLOAT32_C(  -988.68), SIMDE_FLOAT32_C(   641.11) },
      { SIMDE_FLOAT32_C(  -317.64), SIMDE_FLOAT32_C(  -420.46), SIMDE_FLOAT32_C(  -105.90), SIMDE_FLOAT32_C(  -500.59) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   317.64), SIMDE_FLOAT32_C(  -409.87), SIMDE_FLOAT32_C(  -988.68), SIMDE_FLOAT32_C(   641.11) } },
    { { SIMDE_FLOAT32_C(   721.27), SIMDE_FLOAT32_C(   593.69), SIMDE_FLOAT32_C(  -341.09), SIMDE_FLOAT32_C(   708.51) },
      UINT8_C(181),
      { SIMDE_FLOAT32_C(   -97.13), SIMDE_FLOAT32_C(  -685.11), SIMDE_FLOAT32_C(   339.23), SIMDE_FLOAT32_C(  -180.15) },
      { SIMDE_FLOAT32_C(  -732.09), SIMDE_FLOAT32_C(  -355.55), SIMDE_FLOAT32_C(  -362.14), SIMDE_FLOAT32_C(  -848.18) },
       INT32_C(           5),
      { SIMDE_FLOAT32_C(   -97.13), SIMDE_FLOAT32_C(  -685.11), SIMDE_FLOAT32_C(   339.23), SIMDE_FLOAT32_C(  -180.15) } },
    { { SIMDE_FLOAT32_C(   897.37), SIMDE_FLOAT32_C(  -249.67), SIMDE_FLOAT32_C(  -962.01), SIMDE_FLOAT32_C(  -484.33) },
         UINT8_MAX,
      { SIMDE_FLOAT32_C(  -742.32), SIMDE_FLOAT32_C(  -351.27), SIMDE_FLOAT32_C(   911.91), SIMDE_FLOAT32_C(  -885.86) },
      { SIMDE_FLOAT32_C(   238.86), SIMDE_FLOAT32_C(   923.22), SIMDE_FLOAT32_C(   755.25), SIMDE_FLOAT32_C(   921.23) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(  -238.86), SIMDE_FLOAT32_C(  -351.27), SIMDE_FLOAT32_C(   911.91), SIMDE_FLOAT32_C(  -885.86) } },
    { { SIMDE_FLOAT32_C(  -350.65), SIMDE_FLOAT32_C(  -579.36), SIMDE_FLOAT32_C(   228.04), SIMDE_FLOAT32_C(  -629.38) },
      UINT8_C( 81),
      { SIMDE_FLOAT32_C(   886.95), SIMDE_FLOAT32_C(  -920.86), SIMDE_FLOAT32_C(   691.24), SIMDE_FLOAT32_C(  -210.18) },
      { SIMDE_FLOAT32_C(  -605.97), SIMDE_FLOAT32_C(    30.47), SIMDE_FLOAT32_C(   609.67), SIMDE_FLOAT32_C(  -338.06) },
       INT32_C(           9),
      { SIMDE_FLOAT32_C(   886.95), SIMDE_FLOAT32_C(  -920.86), SIMDE_FLOAT32_C(   691.24), SIMDE_FLOAT32_C(  -210.18) } },
  };

  simde__m128 src, a, b, r;

  src = simde_mm_loadu_ps(test_vec[0].src);
  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_mask_range_ss(src, test_vec[0].k, a, b, INT32_C(           5));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  src = simde_mm_loadu_ps(test_vec[1].src);
  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_mask_range_ss(src, test_vec[1].k, a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  src = simde_mm_loadu_ps(test_vec[2].src);
  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_mask_range_ss(src, test_vec[2].k, a, b, INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  src = simde_mm_loadu_ps(test_vec[3].src);
  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_mask_range_ss(src, test_vec[3].k, a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  src = simde_mm_loadu_ps(test_vec[4].src);
  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_mask_range_ss(src, test_vec[4].k, a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  src = simde_mm_loadu_ps(test_vec[5].src);
  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_mask_range_ss(src, test_vec[5].k, a, b, INT32_C(           5));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  src = simde_mm_loadu_ps(test_vec[6].src);
  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_mask_range_ss(src, test_vec[6].k, a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  src = simde_mm_loadu_ps(test_vec[7].src);
  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_mask_range_ss(src, test_vec[7].k, a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m128 r;
    SIMDE_CONSTIFY_16_(simde_mm_mask_range_ss, r, simde_mm_setzero_ps(), imm8, src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_range_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C( 87),
      { SIMDE_FLOAT32_C(  -186.23), SIMDE_FLOAT32_C(  -566.86), SIMDE_FLOAT32_C(  -855.11), SIMDE_FLOAT32_C(   564.10) },
      { SIMDE_FLOAT32_C(  -528.86), SIMDE_FLOAT32_C(  -339.43), SIMDE_FLOAT32_C(  -194.41), SIMDE_FLOAT32_C(  -271.19) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(  -528.86), SIMDE_FLOAT32_C(  -566.86), SIMDE_FLOAT32_C(  -855.11), SIMDE_FLOAT32_C(   564.10) } },
    { UINT8_C( 73),
      { SIMDE_FLOAT32_C(  -157.04), SIMDE_FLOAT32_C(  -451.84), SIMDE_FLOAT32_C(  -359.27), SIMDE_FLOAT32_C(  -401.79) },
      { SIMDE_FLOAT32_C(  -530.61), SIMDE_FLOAT32_C(   143.49), SIMDE_FLOAT32_C(   247.56), SIMDE_FLOAT32_C(  -109.97) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(  -157.04), SIMDE_FLOAT32_C(  -451.84), SIMDE_FLOAT32_C(  -359.27), SIMDE_FLOAT32_C(  -401.79) } },
    { UINT8_C( 66),
      { SIMDE_FLOAT32_C(   -95.65), SIMDE_FLOAT32_C(  -741.53), SIMDE_FLOAT32_C(   697.32), SIMDE_FLOAT32_C(  -404.41) },
      { SIMDE_FLOAT32_C(    48.29), SIMDE_FLOAT32_C(  -908.65), SIMDE_FLOAT32_C(   626.06), SIMDE_FLOAT32_C(  -342.04) },
       INT32_C(          12),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -741.53), SIMDE_FLOAT32_C(   697.32), SIMDE_FLOAT32_C(  -404.41) } },
    { UINT8_C( 29),
      { SIMDE_FLOAT32_C(   -94.52), SIMDE_FLOAT32_C(   567.06), SIMDE_FLOAT32_C(   734.13), SIMDE_FLOAT32_C(    50.37) },
      { SIMDE_FLOAT32_C(   131.16), SIMDE_FLOAT32_C(  -794.74), SIMDE_FLOAT32_C(   710.94), SIMDE_FLOAT32_C(   936.75) },
       INT32_C(          12),
      { SIMDE_FLOAT32_C(   -94.52), SIMDE_FLOAT32_C(   567.06), SIMDE_FLOAT32_C(   734.13), SIMDE_FLOAT32_C(    50.37) } },
    { UINT8_C( 54),
      { SIMDE_FLOAT32_C(  -345.75), SIMDE_FLOAT32_C(   777.03), SIMDE_FLOAT32_C(   568.40), SIMDE_FLOAT32_C(   294.98) },
      { SIMDE_FLOAT32_C(  -624.76), SIMDE_FLOAT32_C(  -962.21), SIMDE_FLOAT32_C(  -561.53), SIMDE_FLOAT32_C(   622.80) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   777.03), SIMDE_FLOAT32_C(   568.40), SIMDE_FLOAT32_C(   294.98) } },
    { UINT8_C(178),
      { SIMDE_FLOAT32_C(   240.99), SIMDE_FLOAT32_C(   832.17), SIMDE_FLOAT32_C(    68.47), SIMDE_FLOAT32_C(   -61.69) },
      { SIMDE_FLOAT32_C(  -572.24), SIMDE_FLOAT32_C(  -883.24), SIMDE_FLOAT32_C(    29.66), SIMDE_FLOAT32_C(  -946.18) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   832.17), SIMDE_FLOAT32_C(    68.47), SIMDE_FLOAT32_C(   -61.69) } },
    { UINT8_C(138),
      { SIMDE_FLOAT32_C(   354.81), SIMDE_FLOAT32_C(   680.19), SIMDE_FLOAT32_C(   350.02), SIMDE_FLOAT32_C(    88.93) },
      { SIMDE_FLOAT32_C(  -269.44), SIMDE_FLOAT32_C(  -518.83), SIMDE_FLOAT32_C(   294.20), SIMDE_FLOAT32_C(  -558.50) },
       INT32_C(          13),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   680.19), SIMDE_FLOAT32_C(   350.02), SIMDE_FLOAT32_C(    88.93) } },
    { UINT8_C(129),
      { SIMDE_FLOAT32_C(   461.74), SIMDE_FLOAT32_C(    72.18), SIMDE_FLOAT32_C(  -994.69), SIMDE_FLOAT32_C(    30.14) },
      { SIMDE_FLOAT32_C(  -632.84), SIMDE_FLOAT32_C(  -619.45), SIMDE_FLOAT32_C(    67.93), SIMDE_FLOAT32_C(  -194.38) },
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -632.84), SIMDE_FLOAT32_C(    72.18), SIMDE_FLOAT32_C(  -994.69), SIMDE_FLOAT32_C(    30.14) } },
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_maskz_range_ss(test_vec[0].k, a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_maskz_range_ss(test_vec[1].k, a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_maskz_range_ss(test_vec[2].k, a, b, INT32_C(          12));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_maskz_range_ss(test_vec[3].k, a, b, INT32_C(          12));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_maskz_range_ss(test_vec[4].k, a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_maskz_range_ss(test_vec[5].k, a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_maskz_range_ss(test_vec[6].k, a, b, INT32_C(          13));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_maskz_range_ss(test_vec[7].k, a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m128 r;
    SIMDE_CONSTIFY_16_(simde_mm_maskz_range_ss, r, simde_mm_setzero_ps(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_mm_range_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   303.71), SIMDE_FLOAT64_C(   529.35) },
      { SIMDE_FLOAT64_C(   873.73), SIMDE_FLOAT64_C(    90.41) },
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   303.71), SIMDE_FLOAT64_C(   529.35) } },
    { { SIMDE_FLOAT64_C(   435.31), SIMDE_FLOAT64_C(     7.29) },
      { SIMDE_FLOAT64_C(  -660.60), SIMDE_FLOAT64_C(   738.01) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   660.60), SIMDE_FLOAT64_C(     7.29) } },
    { { SIMDE_FLOAT64_C(  -704.98), SIMDE_FLOAT64_C(  -155.73) },
      { SIMDE_FLOAT64_C(  -431.88), SIMDE_FLOAT64_C(   554.77) },
       INT32_C(           9),
      { SIMDE_FLOAT64_C(   431.88), SIMDE_FLOAT64_C(  -155.73) } },
    { { SIMDE_FLOAT64_C(   586.62), SIMDE_FLOAT64_C(  -121.06) },
      { SIMDE_FLOAT64_C(   520.15), SIMDE_FLOAT64_C(   384.57) },
       INT32_C(           5),
      { SIMDE_FLOAT64_C(   586.62), SIMDE_FLOAT64_C(  -121.06) } },
    { { SIMDE_FLOAT64_C(   -80.52), SIMDE_FLOAT64_C(     0.12) },
      { SIMDE_FLOAT64_C(  -109.85), SIMDE_FLOAT64_C(   256.11) },
       INT32_C(          14),
      { SIMDE_FLOAT64_C(   -80.52), SIMDE_FLOAT64_C(     0.12) } },
    { { SIMDE_FLOAT64_C(  -228.78), SIMDE_FLOAT64_C(  -140.83) },
      { SIMDE_FLOAT64_C(   360.44), SIMDE_FLOAT64_C(  -282.81) },
       INT32_C(           6),
      { SIMDE_FLOAT64_C(  -228.78), SIMDE_FLOAT64_C(  -140.83) } },
    { { SIMDE_FLOAT64_C(  -452.84), SIMDE_FLOAT64_C(  -979.10) },
      { SIMDE_FLOAT64_C(  -447.11), SIMDE_FLOAT64_C(  -579.11) },
       INT32_C(          11),
      { SIMDE_FLOAT64_C(   452.84), SIMDE_FLOAT64_C(  -979.10) } },
    { { SIMDE_FLOAT64_C(   268.05), SIMDE_FLOAT64_C(   856.20) },
      { SIMDE_FLOAT64_C(  -881.39), SIMDE_FLOAT64_C(   607.45) },
       INT32_C(           5),
      { SIMDE_FLOAT64_C(   268.05), SIMDE_FLOAT64_C(   856.20) } },
  };

  simde__m128d a, b, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_x_mm_range_sd(a, b, INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_x_mm_range_sd(a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_x_mm_range_sd(a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_x_mm_range_sd(a, b, INT32_C(           5));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_x_mm_range_sd(a, b, INT32_C(           14));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_x_mm_range_sd(a, b, INT32_C(            6));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_x_mm_range_sd(a, b, INT32_C(           11));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_x_mm_range_sd(a, b, INT32_C(            5));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m128d r;
    SIMDE_CONSTIFY_16_(simde_x_mm_range_sd, r, simde_mm_setzero_pd(), imm8, a, b);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_range_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   233.87), SIMDE_FLOAT64_C(  -459.39) },
      UINT8_C(157),
      { SIMDE_FLOAT64_C(    72.78), SIMDE_FLOAT64_C(   522.02) },
      { SIMDE_FLOAT64_C(  -642.47), SIMDE_FLOAT64_C(   396.59) },
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -642.47), SIMDE_FLOAT64_C(   522.02) } },
    { { SIMDE_FLOAT64_C(  -430.17), SIMDE_FLOAT64_C(   351.20) },
      UINT8_C(216),
      { SIMDE_FLOAT64_C(  -280.98), SIMDE_FLOAT64_C(  -547.40) },
      { SIMDE_FLOAT64_C(  -695.26), SIMDE_FLOAT64_C(  -362.72) },
       INT32_C(           2),
      { SIMDE_FLOAT64_C(  -430.17), SIMDE_FLOAT64_C(  -547.40) } },
    { { SIMDE_FLOAT64_C(  -391.21), SIMDE_FLOAT64_C(  -190.43) },
      UINT8_C(242),
      { SIMDE_FLOAT64_C(   422.87), SIMDE_FLOAT64_C(    12.55) },
      { SIMDE_FLOAT64_C(  -439.83), SIMDE_FLOAT64_C(   770.04) },
       INT32_C(          14),
      { SIMDE_FLOAT64_C(  -391.21), SIMDE_FLOAT64_C(    12.55) } },
    { { SIMDE_FLOAT64_C(   363.45), SIMDE_FLOAT64_C(  -802.30) },
      UINT8_C(140),
      { SIMDE_FLOAT64_C(   744.84), SIMDE_FLOAT64_C(   780.99) },
      { SIMDE_FLOAT64_C(  -987.02), SIMDE_FLOAT64_C(   695.51) },
       INT32_C(          13),
      { SIMDE_FLOAT64_C(   363.45), SIMDE_FLOAT64_C(   780.99) } },
    { { SIMDE_FLOAT64_C(  -446.41), SIMDE_FLOAT64_C(  -577.07) },
      UINT8_C(242),
      { SIMDE_FLOAT64_C(  -924.38), SIMDE_FLOAT64_C(  -219.54) },
      { SIMDE_FLOAT64_C(   484.24), SIMDE_FLOAT64_C(   -87.33) },
       INT32_C(           5),
      { SIMDE_FLOAT64_C(  -446.41), SIMDE_FLOAT64_C(  -219.54) } },
    { { SIMDE_FLOAT64_C(  -164.56), SIMDE_FLOAT64_C(  -940.26) },
      UINT8_C(  0),
      { SIMDE_FLOAT64_C(   288.03), SIMDE_FLOAT64_C(  -635.52) },
      { SIMDE_FLOAT64_C(  -293.41), SIMDE_FLOAT64_C(   491.32) },
       INT32_C(           1),
      { SIMDE_FLOAT64_C(  -164.56), SIMDE_FLOAT64_C(  -635.52) } },
    { { SIMDE_FLOAT64_C(   516.16), SIMDE_FLOAT64_C(   674.11) },
      UINT8_C(205),
      { SIMDE_FLOAT64_C(  -471.29), SIMDE_FLOAT64_C(  -765.72) },
      { SIMDE_FLOAT64_C(  -833.83), SIMDE_FLOAT64_C(  -535.27) },
       INT32_C(          10),
      { SIMDE_FLOAT64_C(   471.29), SIMDE_FLOAT64_C(  -765.72) } },
    { { SIMDE_FLOAT64_C(  -636.12), SIMDE_FLOAT64_C(  -587.71) },
      UINT8_C(118),
      { SIMDE_FLOAT64_C(  -855.13), SIMDE_FLOAT64_C(  -574.73) },
      { SIMDE_FLOAT64_C(    38.07), SIMDE_FLOAT64_C(   159.73) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(  -636.12), SIMDE_FLOAT64_C(  -574.73) } },
  };

  simde__m128d src, a, b, r;

  src = simde_mm_loadu_pd(test_vec[0].src);
  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_mask_range_sd(src, test_vec[0].k, a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  src = simde_mm_loadu_pd(test_vec[1].src);
  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_mask_range_sd(src, test_vec[1].k, a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  src = simde_mm_loadu_pd(test_vec[2].src);
  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_mask_range_sd(src, test_vec[2].k, a, b, INT32_C(          14));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  src = simde_mm_loadu_pd(test_vec[3].src);
  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_mask_range_sd(src, test_vec[3].k, a, b, INT32_C(          13));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  src = simde_mm_loadu_pd(test_vec[4].src);
  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_mask_range_sd(src, test_vec[4].k, a, b, INT32_C(           5));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  src = simde_mm_loadu_pd(test_vec[5].src);
  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_mask_range_sd(src, test_vec[5].k, a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  src = simde_mm_loadu_pd(test_vec[6].src);
  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_mask_range_sd(src, test_vec[6].k, a, b, INT32_C(          10));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  src = simde_mm_loadu_pd(test_vec[7].src);
  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_mask_range_sd(src, test_vec[7].k, a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m128d r;
    SIMDE_CONSTIFY_16_(simde_mm_mask_range_sd, r, simde_mm_setzero_pd(), imm8, src, k, a, b);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_range_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C(210),
      { SIMDE_FLOAT64_C(   247.38), SIMDE_FLOAT64_C(    54.48) },
      { SIMDE_FLOAT64_C(  -758.53), SIMDE_FLOAT64_C(  -268.38) },
       INT32_C(           3),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    54.48) } },
    { UINT8_C(116),
      { SIMDE_FLOAT64_C(   567.05), SIMDE_FLOAT64_C(  -973.11) },
      { SIMDE_FLOAT64_C(   661.06), SIMDE_FLOAT64_C(  -144.91) },
       INT32_C(           9),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -973.11) } },
    { UINT8_C(137),
      { SIMDE_FLOAT64_C(  -653.59), SIMDE_FLOAT64_C(   364.64) },
      { SIMDE_FLOAT64_C(   883.80), SIMDE_FLOAT64_C(  -979.48) },
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   653.59), SIMDE_FLOAT64_C(   364.64) } },
    { UINT8_C( 86),
      { SIMDE_FLOAT64_C(  -745.20), SIMDE_FLOAT64_C(   926.95) },
      { SIMDE_FLOAT64_C(  -122.76), SIMDE_FLOAT64_C(   852.52) },
       INT32_C(           7),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   926.95) } },
    { UINT8_C( 90),
      { SIMDE_FLOAT64_C(   195.09), SIMDE_FLOAT64_C(  -564.30) },
      { SIMDE_FLOAT64_C(   714.79), SIMDE_FLOAT64_C(  -766.84) },
       INT32_C(          11),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -564.30) } },
    { UINT8_C(171),
      { SIMDE_FLOAT64_C(   694.17), SIMDE_FLOAT64_C(  -157.20) },
      { SIMDE_FLOAT64_C(   748.14), SIMDE_FLOAT64_C(   935.63) },
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   694.17), SIMDE_FLOAT64_C(  -157.20) } },
    { UINT8_C( 70),
      { SIMDE_FLOAT64_C(   527.38), SIMDE_FLOAT64_C(   141.48) },
      { SIMDE_FLOAT64_C(   742.18), SIMDE_FLOAT64_C(   188.44) },
       INT32_C(           3),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   141.48) } },
    { UINT8_C(166),
      { SIMDE_FLOAT64_C(   556.09), SIMDE_FLOAT64_C(  -657.03) },
      { SIMDE_FLOAT64_C(   498.20), SIMDE_FLOAT64_C(   439.89) },
       INT32_C(           1),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -657.03) } },
  };

  simde__m128d  a, b, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_maskz_range_sd(test_vec[0].k, a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_maskz_range_sd(test_vec[1].k, a, b, INT32_C(           9));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_maskz_range_sd(test_vec[2].k, a, b, INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_maskz_range_sd(test_vec[3].k, a, b, INT32_C(           7));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_maskz_range_sd(test_vec[4].k, a, b, INT32_C(          11));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_maskz_range_sd(test_vec[5].k, a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_maskz_range_sd(test_vec[6].k, a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_maskz_range_sd(test_vec[7].k, a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    int imm8 = simde_test_codegen_rand() & 15;
    simde__m128d r;
    SIMDE_CONSTIFY_16_(simde_mm_maskz_range_sd, r, simde_mm_setzero_pd(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_range_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_range_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_range_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(x_mm_range_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_range_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_range_sd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
