/* Copyright (c) 2020 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define SIMDE_TESTS_CURRENT_ISAX f16c
#include <simde/x86/f16c.h>
#include <test/x86/test-avx.h>

static int
test_simde_mm_cvtps_ph (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const int16_t r[8];
    //const int16_t r0[8];
    //const int16_t r1[8];
    //const int16_t r2[8];
    //const int16_t r3[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -922.45), SIMDE_FLOAT32_C(  -417.52), SIMDE_FLOAT32_C(   576.56), SIMDE_FLOAT32_C(   -16.40) },
      { -INT16_C(  7371), -INT16_C(  8570),  INT16_C( 24705), -INT16_C( 13286),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(  -847.35), SIMDE_FLOAT32_C(  -868.69), SIMDE_FLOAT32_C(   190.03), SIMDE_FLOAT32_C(  -263.75) },
      { -INT16_C(  7521), -INT16_C(  7479),  INT16_C( 23024), -INT16_C(  9185),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(   550.95), SIMDE_FLOAT32_C(   691.22), SIMDE_FLOAT32_C(   972.58), SIMDE_FLOAT32_C(   645.93) },
      {  INT16_C( 24654),  INT16_C( 24934),  INT16_C( 25497),  INT16_C( 24844),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(  -961.75), SIMDE_FLOAT32_C(   626.33), SIMDE_FLOAT32_C(   597.48), SIMDE_FLOAT32_C(   793.15) },
      { -INT16_C(  7292),  INT16_C( 24805),  INT16_C( 24747),  INT16_C( 25138),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(  -582.37), SIMDE_FLOAT32_C(  -225.09), SIMDE_FLOAT32_C(   -65.32), SIMDE_FLOAT32_C(   452.55) },
      { -INT16_C(  8051), -INT16_C(  9463), -INT16_C( 11243),  INT16_C( 24338),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(   125.78), SIMDE_FLOAT32_C(  -683.39), SIMDE_FLOAT32_C(  -348.27), SIMDE_FLOAT32_C(  -309.07) },
      {  INT16_C( 22492), -INT16_C(  7849), -INT16_C(  8847), -INT16_C(  9004),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(  -141.60), SIMDE_FLOAT32_C(   503.26), SIMDE_FLOAT32_C(  -451.69), SIMDE_FLOAT32_C(  -298.51) },
      { -INT16_C( 10131),  INT16_C( 24541), -INT16_C(  8433), -INT16_C(  9046),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(   899.79), SIMDE_FLOAT32_C(   611.12), SIMDE_FLOAT32_C(  -363.24), SIMDE_FLOAT32_C(   977.33) },
      {  INT16_C( 25352),  INT16_C( 24774), -INT16_C(  8787),  INT16_C( 25507),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },

    #if 0
    // simde_mm_cvtps_ph doesn't handle the rounding paramter at all
    { { SIMDE_FLOAT32_C(  9204.05), SIMDE_FLOAT32_C( 86132.80), SIMDE_FLOAT32_C( 37121.74), SIMDE_FLOAT32_C( 68581.13) },
      {  INT16_C( 28799),  INT16_C( 31744),  INT16_C( 30856),  INT16_C( 31744),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 28798),  INT16_C( 31743),  INT16_C( 30856),  INT16_C( 31743),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 28799),  INT16_C( 31744),  INT16_C( 30857),  INT16_C( 31744),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 28798),  INT16_C( 31743),  INT16_C( 30856),  INT16_C( 31743),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C( 74896.25), SIMDE_FLOAT32_C(-56204.26), SIMDE_FLOAT32_C( -7440.56), SIMDE_FLOAT32_C(-88439.16) },
      {  INT16_C( 31744), -INT16_C(  1316), -INT16_C(  4284), -INT16_C(  1024),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 31743), -INT16_C(  1315), -INT16_C(  4283), -INT16_C(  1024),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 31744), -INT16_C(  1316), -INT16_C(  4284), -INT16_C(  1025),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 31743), -INT16_C(  1316), -INT16_C(  4284), -INT16_C(  1025),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(  1299.55), SIMDE_FLOAT32_C( 86370.34), SIMDE_FLOAT32_C( 59262.21), SIMDE_FLOAT32_C(-12225.60) },
      {  INT16_C( 25876),  INT16_C( 31744),  INT16_C( 31548), -INT16_C(  3592),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 25875),  INT16_C( 31743),  INT16_C( 31547), -INT16_C(  3591),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 25876),  INT16_C( 31744),  INT16_C( 31548), -INT16_C(  3592),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 25875),  INT16_C( 31743),  INT16_C( 31547), -INT16_C(  3592),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C( 34338.03), SIMDE_FLOAT32_C( 79249.55), SIMDE_FLOAT32_C( 55280.25), SIMDE_FLOAT32_C(-62398.29) },
      {  INT16_C( 30769),  INT16_C( 31744),  INT16_C( 31424), -INT16_C(  1122),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 30769),  INT16_C( 31743),  INT16_C( 31423), -INT16_C(  1122),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 30770),  INT16_C( 31744),  INT16_C( 31424), -INT16_C(  1123),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 30769),  INT16_C( 31743),  INT16_C( 31423), -INT16_C(  1123),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C( 46704.88), SIMDE_FLOAT32_C(-69785.79), SIMDE_FLOAT32_C( 60111.00), SIMDE_FLOAT32_C(-19208.83) },
      {  INT16_C( 31156), -INT16_C(  1024),  INT16_C( 31574), -INT16_C(  2895),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 31155), -INT16_C(  1024),  INT16_C( 31574), -INT16_C(  2895),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 31156), -INT16_C(  1025),  INT16_C( 31575), -INT16_C(  2896),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C( 31155), -INT16_C(  1025),  INT16_C( 31574), -INT16_C(  2896),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(-19389.39), SIMDE_FLOAT32_C( -9921.31), SIMDE_FLOAT32_C( 90650.84), SIMDE_FLOAT32_C( 44172.08) },
      { -INT16_C(  2884), -INT16_C(  3880),  INT16_C( 31744),  INT16_C( 31076),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { -INT16_C(  2884), -INT16_C(  3879),  INT16_C( 31743),  INT16_C( 31076),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { -INT16_C(  2885), -INT16_C(  3880),  INT16_C( 31744),  INT16_C( 31077),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { -INT16_C(  2885), -INT16_C(  3880),  INT16_C( 31743),  INT16_C( 31076),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(-99667.48), SIMDE_FLOAT32_C( 75527.14), SIMDE_FLOAT32_C( 97265.97), SIMDE_FLOAT32_C(-87748.09) },
      { -INT16_C(  1024),  INT16_C( 31744),  INT16_C( 31744), -INT16_C(  1024),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { -INT16_C(  1024),  INT16_C( 31743),  INT16_C( 31743), -INT16_C(  1024),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { -INT16_C(  1025),  INT16_C( 31744),  INT16_C( 31744), -INT16_C(  1025),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { -INT16_C(  1025),  INT16_C( 31743),  INT16_C( 31743), -INT16_C(  1025),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { SIMDE_FLOAT32_C(-35448.19), SIMDE_FLOAT32_C( 83651.46), SIMDE_FLOAT32_C( 18631.21), SIMDE_FLOAT32_C( 73755.86) },
      { -INT16_C(  1964),  INT16_C( 31744),  INT16_C( 29836),  INT16_C( 31744),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { -INT16_C(  1964),  INT16_C( 31743),  INT16_C( 29836),  INT16_C( 31743),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { -INT16_C(  1965),  INT16_C( 31744),  INT16_C( 29837),  INT16_C( 31744),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) },
      { -INT16_C(  1965),  INT16_C( 31743),  INT16_C( 29836),  INT16_C( 31743),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    #endif
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128i r = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));

    //Use the below when the rounding is fixed
    //simde__m128i r0 = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    //simde_test_x86_assert_equal_i16x8(r0, simde_x_mm_loadu_epi16(test_vec[i].r0));
    //simde__m128i r1 = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEG_INF);
    //simde_test_x86_assert_equal_i16x8(r1, simde_x_mm_loadu_epi16(test_vec[i].r1));
    //simde__m128i r2 = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_POS_INF);
    //simde_test_x86_assert_equal_i16x8(r2, simde_x_mm_loadu_epi16(test_vec[i].r2));
    //simde__m128i r3 = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_ZERO);
    //simde_test_x86_assert_equal_i16x8(r3, simde_x_mm_loadu_epi16(test_vec[i].r3));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_f32x4(-100000.0000f, 100000.0000f);
    simde__m128i r0 = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde__m128i r1 = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEG_INF);
    simde__m128i r2 = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_POS_INF);
    simde__m128i r3 = simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_ZERO);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_cvtph_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const simde_float32 r[4];
  } test_vec[] = {
    { { UINT16_C(57665), UINT16_C(57418), UINT16_C(25491), UINT16_C(23593), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(  -672.50), SIMDE_FLOAT32_C(  -549.00), SIMDE_FLOAT32_C(   969.50), SIMDE_FLOAT32_C(   266.25) } },
    { { UINT16_C(24529), UINT16_C(25120), UINT16_C(57577), UINT16_C(55544), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(   500.25), SIMDE_FLOAT32_C(   784.00), SIMDE_FLOAT32_C(  -628.50), SIMDE_FLOAT32_C(  -159.00) } },
    { { UINT16_C(56338), UINT16_C(24788), UINT16_C(58146), UINT16_C(25256), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(  -260.50), SIMDE_FLOAT32_C(   618.00), SIMDE_FLOAT32_C(  -913.00), SIMDE_FLOAT32_C(   852.00) } },
    { { UINT16_C(25457), UINT16_C(24637), UINT16_C(23890), UINT16_C(56982), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(   952.50), SIMDE_FLOAT32_C(   542.50), SIMDE_FLOAT32_C(   340.50), SIMDE_FLOAT32_C(  -421.50) } },
    { { UINT16_C(22950), UINT16_C(21640), UINT16_C(54779), UINT16_C(22774), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(   180.75), SIMDE_FLOAT32_C(    72.50), SIMDE_FLOAT32_C(   -95.69), SIMDE_FLOAT32_C(   158.75) } },
    { { UINT16_C(24293), UINT16_C(55275), UINT16_C(56350), UINT16_C(24325), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(   441.25), SIMDE_FLOAT32_C(  -126.69), SIMDE_FLOAT32_C(  -263.50), SIMDE_FLOAT32_C(   449.25) } },
    { { UINT16_C(22402), UINT16_C(24502), UINT16_C(57033), UINT16_C(56678), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(   120.12), SIMDE_FLOAT32_C(   493.50), SIMDE_FLOAT32_C(  -434.25), SIMDE_FLOAT32_C(  -345.50) } },
    { { UINT16_C(57623), UINT16_C(22385), UINT16_C(56989), UINT16_C(56592), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { SIMDE_FLOAT32_C(  -651.50), SIMDE_FLOAT32_C(   119.06), SIMDE_FLOAT32_C(  -423.25), SIMDE_FLOAT32_C(  -324.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128 r = simde_mm_cvtph_ps(a);
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_mm_cvtps_ph(simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0)), SIMDE_MM_FROUND_NO_EXC);
    simde__m128 r = simde_mm_cvtph_ps(a);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_f16c_round_trip (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 r[4];
  } test_vec[] = {
    #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -423.73),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   160.78) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -423.73),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   160.78) } },
    #endif
    { { SIMDE_FLOAT32_C(  -981.67), SIMDE_FLOAT32_C(   318.53), SIMDE_FLOAT32_C(  -890.10), SIMDE_FLOAT32_C(   443.08) },
      { SIMDE_FLOAT32_C(  -981.67), SIMDE_FLOAT32_C(   318.53), SIMDE_FLOAT32_C(  -890.10), SIMDE_FLOAT32_C(   443.08) } },
    { { SIMDE_FLOAT32_C(  -316.07), SIMDE_FLOAT32_C(   436.20), SIMDE_FLOAT32_C(   506.18), SIMDE_FLOAT32_C(   324.31) },
      { SIMDE_FLOAT32_C(  -316.07), SIMDE_FLOAT32_C(   436.20), SIMDE_FLOAT32_C(   506.18), SIMDE_FLOAT32_C(   324.31) } },
    { { SIMDE_FLOAT32_C(  -232.13), SIMDE_FLOAT32_C(   547.61), SIMDE_FLOAT32_C(   521.27), SIMDE_FLOAT32_C(  -153.90) },
      { SIMDE_FLOAT32_C(  -232.13), SIMDE_FLOAT32_C(   547.61), SIMDE_FLOAT32_C(   521.27), SIMDE_FLOAT32_C(  -153.90) } },
    { { SIMDE_FLOAT32_C(   819.91), SIMDE_FLOAT32_C(   215.00), SIMDE_FLOAT32_C(   715.88), SIMDE_FLOAT32_C(   525.54) },
      { SIMDE_FLOAT32_C(   819.91), SIMDE_FLOAT32_C(   215.00), SIMDE_FLOAT32_C(   715.88), SIMDE_FLOAT32_C(   525.54) } },
    { { SIMDE_FLOAT32_C(  -199.45), SIMDE_FLOAT32_C(  -914.59), SIMDE_FLOAT32_C(  -600.24), SIMDE_FLOAT32_C(  -579.28) },
      { SIMDE_FLOAT32_C(  -199.45), SIMDE_FLOAT32_C(  -914.59), SIMDE_FLOAT32_C(  -600.24), SIMDE_FLOAT32_C(  -579.28) } },
    { { SIMDE_FLOAT32_C(   950.34), SIMDE_FLOAT32_C(   142.00), SIMDE_FLOAT32_C(  -931.01), SIMDE_FLOAT32_C(   915.71) },
      { SIMDE_FLOAT32_C(   950.34), SIMDE_FLOAT32_C(   142.00), SIMDE_FLOAT32_C(  -931.01), SIMDE_FLOAT32_C(   915.71) } },
    { { SIMDE_FLOAT32_C(  -390.34), SIMDE_FLOAT32_C(   580.78), SIMDE_FLOAT32_C(  -866.48), SIMDE_FLOAT32_C(  -588.08) },
      { SIMDE_FLOAT32_C(  -390.34), SIMDE_FLOAT32_C(   580.78), SIMDE_FLOAT32_C(  -866.48), SIMDE_FLOAT32_C(  -588.08) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128 a = simde_mm_loadu_ps(test_vec[i].a);
    simde__m128 r = simde_mm_cvtph_ps(simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEAREST_INT));
    simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[i].r), 0);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 r = a; // simde_mm_cvtph_ps(simde_mm_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEAREST_INT));

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cvtps_ph (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const int16_t r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -266.25), SIMDE_FLOAT32_C(  -994.56), SIMDE_FLOAT32_C(  -351.71), SIMDE_FLOAT32_C(   290.36),
        SIMDE_FLOAT32_C(  -637.78), SIMDE_FLOAT32_C(   495.06), SIMDE_FLOAT32_C(  -635.46), SIMDE_FLOAT32_C(  -352.22) },
      { -INT16_C(  9175), -INT16_C(  7227), -INT16_C(  8833),  INT16_C( 23689), -INT16_C(  7940),  INT16_C( 24508), -INT16_C(  7945), -INT16_C(  8831) } },
    { { SIMDE_FLOAT32_C(  -832.50), SIMDE_FLOAT32_C(   748.25), SIMDE_FLOAT32_C(  -953.26), SIMDE_FLOAT32_C(  -335.37),
        SIMDE_FLOAT32_C(   855.42), SIMDE_FLOAT32_C(  -551.65), SIMDE_FLOAT32_C(   369.44), SIMDE_FLOAT32_C(   315.27) },
      { -INT16_C(  7551),  INT16_C( 25048), -INT16_C(  7309), -INT16_C(  8899),  INT16_C( 25263), -INT16_C(  8113),  INT16_C( 24006),  INT16_C( 23789) } },
    { { SIMDE_FLOAT32_C(  -690.18), SIMDE_FLOAT32_C(   370.38), SIMDE_FLOAT32_C(   -92.70), SIMDE_FLOAT32_C(   797.51),
        SIMDE_FLOAT32_C(   286.45), SIMDE_FLOAT32_C(   853.41), SIMDE_FLOAT32_C(  -941.28), SIMDE_FLOAT32_C(   941.87) },
      { -INT16_C(  7836),  INT16_C( 24010), -INT16_C( 10805),  INT16_C( 25147),  INT16_C( 23674),  INT16_C( 25259), -INT16_C(  7333),  INT16_C( 25436) } },
    { { SIMDE_FLOAT32_C(   873.16), SIMDE_FLOAT32_C(   513.64), SIMDE_FLOAT32_C(   399.26), SIMDE_FLOAT32_C(  -985.07),
        SIMDE_FLOAT32_C(   503.49), SIMDE_FLOAT32_C(  -978.18), SIMDE_FLOAT32_C(  -844.37), SIMDE_FLOAT32_C(  -762.76) },
      {  INT16_C( 25298),  INT16_C( 24579),  INT16_C( 24125), -INT16_C(  7246),  INT16_C( 24542), -INT16_C(  7260), -INT16_C(  7527), -INT16_C(  7690) } },
    { { SIMDE_FLOAT32_C(  -972.74), SIMDE_FLOAT32_C(  -196.09), SIMDE_FLOAT32_C(   527.61), SIMDE_FLOAT32_C(  -610.53),
        SIMDE_FLOAT32_C(  -701.03), SIMDE_FLOAT32_C(   892.15), SIMDE_FLOAT32_C(    37.25), SIMDE_FLOAT32_C(  -533.53) },
      { -INT16_C(  7271), -INT16_C(  9695),  INT16_C( 24607), -INT16_C(  7995), -INT16_C(  7814),  INT16_C( 25336),  INT16_C( 20648), -INT16_C(  8149) } },
    { { SIMDE_FLOAT32_C(   640.40), SIMDE_FLOAT32_C(    83.99), SIMDE_FLOAT32_C(   131.10), SIMDE_FLOAT32_C(   495.82),
        SIMDE_FLOAT32_C(   532.34), SIMDE_FLOAT32_C(  -499.46), SIMDE_FLOAT32_C(  -188.91), SIMDE_FLOAT32_C(   842.16) },
      {  INT16_C( 24833),  INT16_C( 21824),  INT16_C( 22553),  INT16_C( 24511),  INT16_C( 24617), -INT16_C(  8242), -INT16_C(  9753),  INT16_C( 25236) } },
    { { SIMDE_FLOAT32_C(   870.92), SIMDE_FLOAT32_C(   718.39), SIMDE_FLOAT32_C(   639.67), SIMDE_FLOAT32_C(   157.37),
        SIMDE_FLOAT32_C(   571.81), SIMDE_FLOAT32_C(   698.39), SIMDE_FLOAT32_C(    99.25), SIMDE_FLOAT32_C(   444.96) },
      {  INT16_C( 25294),  INT16_C( 24989),  INT16_C( 24831),  INT16_C( 22763),  INT16_C( 24696),  INT16_C( 24949),  INT16_C( 22068),  INT16_C( 24308) } },
    { { SIMDE_FLOAT32_C(   212.02), SIMDE_FLOAT32_C(  -501.49), SIMDE_FLOAT32_C(   459.89), SIMDE_FLOAT32_C(  -284.49),
        SIMDE_FLOAT32_C(  -479.67), SIMDE_FLOAT32_C(   615.52), SIMDE_FLOAT32_C(   -47.25), SIMDE_FLOAT32_C(  -452.42) },
      {  INT16_C( 23200), -INT16_C(  8234),  INT16_C( 24368), -INT16_C(  9102), -INT16_C(  8321),  INT16_C( 24783), -INT16_C( 11800), -INT16_C(  8430) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
    simde__m128i r = simde_mm256_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 a = simde_test_x86_random_f32x8(-1000.0f, 1000.0f);
    simde__m128i r = simde_mm256_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEAREST_INT);

    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_cvtph_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const uint16_t a[8];
    const simde_float32 r[8];
  } test_vec[] = {
      { { UINT16_C(57990), UINT16_C(54973), UINT16_C(57953), UINT16_C(57620), UINT16_C(56879), UINT16_C(24954), UINT16_C(22493), UINT16_C(23782) },
        { SIMDE_FLOAT32_C(  -835.00), SIMDE_FLOAT32_C(  -107.81), SIMDE_FLOAT32_C(  -816.50), SIMDE_FLOAT32_C(  -650.00),
          SIMDE_FLOAT32_C(  -395.75), SIMDE_FLOAT32_C(   701.00), SIMDE_FLOAT32_C(   125.81), SIMDE_FLOAT32_C(   313.50) } },
      { { UINT16_C(57584), UINT16_C(55980), UINT16_C(25240), UINT16_C(56663), UINT16_C(22603), UINT16_C(58177), UINT16_C(25022), UINT16_C(25135) },
        { SIMDE_FLOAT32_C(  -632.00), SIMDE_FLOAT32_C(  -213.50), SIMDE_FLOAT32_C(   844.00), SIMDE_FLOAT32_C(  -341.75),
          SIMDE_FLOAT32_C(   137.38), SIMDE_FLOAT32_C(  -928.50), SIMDE_FLOAT32_C(   735.00), SIMDE_FLOAT32_C(   791.50) } },
      { { UINT16_C(23799), UINT16_C(58131), UINT16_C(56002), UINT16_C(56914), UINT16_C(58108), UINT16_C(21095), UINT16_C(57559), UINT16_C(57517) },
        { SIMDE_FLOAT32_C(   317.75), SIMDE_FLOAT32_C(  -905.50), SIMDE_FLOAT32_C(  -216.25), SIMDE_FLOAT32_C(  -404.50),
          SIMDE_FLOAT32_C(  -894.00), SIMDE_FLOAT32_C(    51.22), SIMDE_FLOAT32_C(  -619.50), SIMDE_FLOAT32_C(  -598.50) } },
      { { UINT16_C(23890), UINT16_C(24728), UINT16_C(54649), UINT16_C(57838), UINT16_C(57887), UINT16_C(24135), UINT16_C(57569), UINT16_C(57557) },
        { SIMDE_FLOAT32_C(   340.50), SIMDE_FLOAT32_C(   588.00), SIMDE_FLOAT32_C(   -87.56), SIMDE_FLOAT32_C(  -759.00),
          SIMDE_FLOAT32_C(  -783.50), SIMDE_FLOAT32_C(   401.75), SIMDE_FLOAT32_C(  -624.50), SIMDE_FLOAT32_C(  -618.50) } },
      { { UINT16_C(57732), UINT16_C(57060), UINT16_C(56369), UINT16_C(54878), UINT16_C(57800), UINT16_C(25267), UINT16_C(57897), UINT16_C(56785) },
        { SIMDE_FLOAT32_C(  -706.00), SIMDE_FLOAT32_C(  -441.00), SIMDE_FLOAT32_C(  -268.25), SIMDE_FLOAT32_C(  -101.88),
          SIMDE_FLOAT32_C(  -740.00), SIMDE_FLOAT32_C(   857.50), SIMDE_FLOAT32_C(  -788.50), SIMDE_FLOAT32_C(  -372.25) } },
      { { UINT16_C(56720), UINT16_C(58209), UINT16_C(23672), UINT16_C(25115), UINT16_C(58065), UINT16_C(19770), UINT16_C(24698), UINT16_C(24308) },
        { SIMDE_FLOAT32_C(  -356.00), SIMDE_FLOAT32_C(  -944.50), SIMDE_FLOAT32_C(   286.00), SIMDE_FLOAT32_C(   781.50),
          SIMDE_FLOAT32_C(  -872.50), SIMDE_FLOAT32_C(    20.91), SIMDE_FLOAT32_C(   573.00), SIMDE_FLOAT32_C(   445.00) } },
      { { UINT16_C(22324), UINT16_C(57607), UINT16_C(58239), UINT16_C(23275), UINT16_C(24160), UINT16_C(57478), UINT16_C(24797), UINT16_C(56285) },
        { SIMDE_FLOAT32_C(   115.25), SIMDE_FLOAT32_C(  -643.50), SIMDE_FLOAT32_C(  -959.50), SIMDE_FLOAT32_C(   221.38),
          SIMDE_FLOAT32_C(   408.00), SIMDE_FLOAT32_C(  -579.00), SIMDE_FLOAT32_C(   622.50), SIMDE_FLOAT32_C(  -251.62) } },
      { { UINT16_C(58301), UINT16_C(57156), UINT16_C(51507), UINT16_C(57868), UINT16_C(25426), UINT16_C(23988), UINT16_C(56866), UINT16_C(57859) },
        { SIMDE_FLOAT32_C(  -990.50), SIMDE_FLOAT32_C(  -465.00), SIMDE_FLOAT32_C(   -10.40), SIMDE_FLOAT32_C(  -774.00),
          SIMDE_FLOAT32_C(   937.00), SIMDE_FLOAT32_C(   365.00), SIMDE_FLOAT32_C(  -392.50), SIMDE_FLOAT32_C(  -769.50) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_mm_loadu_epi16(test_vec[i].a);
    simde__m256 r = simde_mm256_cvtph_ps(a);
    simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_mm256_cvtps_ph(simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0)), SIMDE_MM_FROUND_NO_EXC);
    simde__m256 r = simde_mm256_cvtph_ps(a);

    simde_test_x86_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_f16c_round_trip (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    static const struct {
      const simde_float32 a[8];
      const simde_float32 r[8];
    } test_vec[] = {
      #if !defined(SIMDE_FAST_NANS)
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -474.87),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -588.08),
        SIMDE_FLOAT32_C(   450.80), SIMDE_FLOAT32_C(   475.77), SIMDE_FLOAT32_C(   919.35), SIMDE_FLOAT32_C(   544.67) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -474.87),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -588.08),
        SIMDE_FLOAT32_C(   450.80), SIMDE_FLOAT32_C(   475.77), SIMDE_FLOAT32_C(   919.35), SIMDE_FLOAT32_C(   544.67) } },
      #endif
    { { SIMDE_FLOAT32_C(  -372.84), SIMDE_FLOAT32_C(  -960.44), SIMDE_FLOAT32_C(   -69.78), SIMDE_FLOAT32_C(  -757.33),
        SIMDE_FLOAT32_C(   645.16), SIMDE_FLOAT32_C(   893.71), SIMDE_FLOAT32_C(   672.61), SIMDE_FLOAT32_C(  -845.50) },
      { SIMDE_FLOAT32_C(  -372.84), SIMDE_FLOAT32_C(  -960.44), SIMDE_FLOAT32_C(   -69.78), SIMDE_FLOAT32_C(  -757.33),
        SIMDE_FLOAT32_C(   645.16), SIMDE_FLOAT32_C(   893.71), SIMDE_FLOAT32_C(   672.61), SIMDE_FLOAT32_C(  -845.50) } },
    { { SIMDE_FLOAT32_C(  -863.46), SIMDE_FLOAT32_C(    81.15), SIMDE_FLOAT32_C(  -636.08), SIMDE_FLOAT32_C(   587.35),
        SIMDE_FLOAT32_C(  -443.08), SIMDE_FLOAT32_C(  -716.73), SIMDE_FLOAT32_C(   132.01), SIMDE_FLOAT32_C(   728.65) },
      { SIMDE_FLOAT32_C(  -863.46), SIMDE_FLOAT32_C(    81.15), SIMDE_FLOAT32_C(  -636.08), SIMDE_FLOAT32_C(   587.35),
        SIMDE_FLOAT32_C(  -443.08), SIMDE_FLOAT32_C(  -716.73), SIMDE_FLOAT32_C(   132.01), SIMDE_FLOAT32_C(   728.65) } },
    { { SIMDE_FLOAT32_C(   708.45), SIMDE_FLOAT32_C(  -619.18), SIMDE_FLOAT32_C(   477.33), SIMDE_FLOAT32_C(   353.61),
        SIMDE_FLOAT32_C(  -725.48), SIMDE_FLOAT32_C(   149.94), SIMDE_FLOAT32_C(   508.10), SIMDE_FLOAT32_C(   238.34) },
      { SIMDE_FLOAT32_C(   708.45), SIMDE_FLOAT32_C(  -619.18), SIMDE_FLOAT32_C(   477.33), SIMDE_FLOAT32_C(   353.61),
        SIMDE_FLOAT32_C(  -725.48), SIMDE_FLOAT32_C(   149.94), SIMDE_FLOAT32_C(   508.10), SIMDE_FLOAT32_C(   238.34) } },
    { { SIMDE_FLOAT32_C(   491.58), SIMDE_FLOAT32_C(  -199.94), SIMDE_FLOAT32_C(   616.91), SIMDE_FLOAT32_C(  -951.51),
        SIMDE_FLOAT32_C(    83.34), SIMDE_FLOAT32_C(  -251.08), SIMDE_FLOAT32_C(   777.15), SIMDE_FLOAT32_C(  -532.99) },
      { SIMDE_FLOAT32_C(   491.58), SIMDE_FLOAT32_C(  -199.94), SIMDE_FLOAT32_C(   616.91), SIMDE_FLOAT32_C(  -951.51),
        SIMDE_FLOAT32_C(    83.34), SIMDE_FLOAT32_C(  -251.08), SIMDE_FLOAT32_C(   777.15), SIMDE_FLOAT32_C(  -532.99) } },
    { { SIMDE_FLOAT32_C(  -504.03), SIMDE_FLOAT32_C(    48.55), SIMDE_FLOAT32_C(  -511.25), SIMDE_FLOAT32_C(  -229.50),
        SIMDE_FLOAT32_C(  -801.51), SIMDE_FLOAT32_C(   996.85), SIMDE_FLOAT32_C(  -991.16), SIMDE_FLOAT32_C(   -14.58) },
      { SIMDE_FLOAT32_C(  -504.03), SIMDE_FLOAT32_C(    48.55), SIMDE_FLOAT32_C(  -511.25), SIMDE_FLOAT32_C(  -229.50),
        SIMDE_FLOAT32_C(  -801.51), SIMDE_FLOAT32_C(   996.85), SIMDE_FLOAT32_C(  -991.16), SIMDE_FLOAT32_C(   -14.58) } },
    { { SIMDE_FLOAT32_C(  -294.23), SIMDE_FLOAT32_C(   817.94), SIMDE_FLOAT32_C(  -541.68), SIMDE_FLOAT32_C(   789.10),
        SIMDE_FLOAT32_C(  -433.13), SIMDE_FLOAT32_C(  -764.53), SIMDE_FLOAT32_C(  -743.88), SIMDE_FLOAT32_C(  -704.08) },
      { SIMDE_FLOAT32_C(  -294.23), SIMDE_FLOAT32_C(   817.94), SIMDE_FLOAT32_C(  -541.68), SIMDE_FLOAT32_C(   789.10),
        SIMDE_FLOAT32_C(  -433.13), SIMDE_FLOAT32_C(  -764.53), SIMDE_FLOAT32_C(  -743.88), SIMDE_FLOAT32_C(  -704.08) } },
    { { SIMDE_FLOAT32_C(   252.24), SIMDE_FLOAT32_C(    43.86), SIMDE_FLOAT32_C(  -697.71), SIMDE_FLOAT32_C(   450.73),
        SIMDE_FLOAT32_C(    40.71), SIMDE_FLOAT32_C(  -688.87), SIMDE_FLOAT32_C(  -563.85), SIMDE_FLOAT32_C(   319.17) },
      { SIMDE_FLOAT32_C(   252.24), SIMDE_FLOAT32_C(    43.86), SIMDE_FLOAT32_C(  -697.71), SIMDE_FLOAT32_C(   450.73),
        SIMDE_FLOAT32_C(    40.71), SIMDE_FLOAT32_C(  -688.87), SIMDE_FLOAT32_C(  -563.85), SIMDE_FLOAT32_C(   319.17) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde__m256 a = simde_mm256_loadu_ps(test_vec[i].a);
      simde__m256 r = simde_mm256_cvtph_ps(simde_mm256_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEAREST_INT));
      simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[i].r), 0);
    }

    return 0;
  #else
    fputc('\n', stdout);
    simde_float32 values[8 * 2 * sizeof(simde__m256)];
    simde_test_x86_random_f32x8_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

    for (size_t i = 0 ; i < 8 ; i++) {
      simde__m256 a = simde_test_x86_random_extract_f32x8(i, 2, 0, values);
      simde__m256 r = a; // simde_mm256_cvtph_ps(simde_mm256_cvtps_ph(a, SIMDE_MM_FROUND_TO_NEAREST_INT));

      simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtps_ph)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cvtph_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_f16c_round_trip)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cvtps_ph)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_cvtph_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_f16c_round_trip)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
