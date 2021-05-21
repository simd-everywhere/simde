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

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_range_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_range_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_range_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
