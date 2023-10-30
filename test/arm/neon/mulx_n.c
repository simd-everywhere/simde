#define SIMDE_TEST_ARM_NEON_INSN mulx_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mulx_n.h"

static int
test_simde_vmulx_n_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b;
    simde_float16 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(     6.147),  SIMDE_FLOAT16_VALUE(     8.026),  SIMDE_FLOAT16_VALUE(     8.205),  SIMDE_FLOAT16_VALUE(    -4.372) },
         SIMDE_FLOAT16_VALUE(    10.677),
      {  SIMDE_FLOAT16_VALUE(    65.632),  SIMDE_FLOAT16_VALUE(    85.694),  SIMDE_FLOAT16_VALUE(    87.605),  SIMDE_FLOAT16_VALUE(   -46.680) } },
    { {  SIMDE_FLOAT16_VALUE(    -8.080),  SIMDE_FLOAT16_VALUE(    -2.013),  SIMDE_FLOAT16_VALUE(    -2.635),  SIMDE_FLOAT16_VALUE(     9.062) },
         SIMDE_FLOAT16_VALUE(    -8.726),
      {  SIMDE_FLOAT16_VALUE(    70.506),  SIMDE_FLOAT16_VALUE(    17.565),  SIMDE_FLOAT16_VALUE(    22.993),  SIMDE_FLOAT16_VALUE(   -79.075) } },
    { {  SIMDE_FLOAT16_VALUE(    -2.635),  SIMDE_FLOAT16_VALUE(    -5.732),  SIMDE_FLOAT16_VALUE(   -12.813),  SIMDE_FLOAT16_VALUE(    14.355) },
         SIMDE_FLOAT16_VALUE(    -7.538),
      {  SIMDE_FLOAT16_VALUE(    19.863),  SIMDE_FLOAT16_VALUE(    43.208),  SIMDE_FLOAT16_VALUE(    96.584),  SIMDE_FLOAT16_VALUE(  -108.208) } },
    { {  SIMDE_FLOAT16_VALUE(     9.770),  SIMDE_FLOAT16_VALUE(     3.322),  SIMDE_FLOAT16_VALUE(    14.353),  SIMDE_FLOAT16_VALUE(   -10.374) },
         SIMDE_FLOAT16_VALUE(    -1.829),
      {  SIMDE_FLOAT16_VALUE(   -17.869),  SIMDE_FLOAT16_VALUE(    -6.076),  SIMDE_FLOAT16_VALUE(   -26.252),  SIMDE_FLOAT16_VALUE(    18.974) } },
    { {  SIMDE_FLOAT16_VALUE(    12.353),  SIMDE_FLOAT16_VALUE(     4.352),  SIMDE_FLOAT16_VALUE(     9.042),  SIMDE_FLOAT16_VALUE(    -8.456) },
         SIMDE_FLOAT16_VALUE(     0.593),
      {  SIMDE_FLOAT16_VALUE(     7.325),  SIMDE_FLOAT16_VALUE(     2.581),  SIMDE_FLOAT16_VALUE(     5.362),  SIMDE_FLOAT16_VALUE(    -5.014) } },
    { {  SIMDE_FLOAT16_VALUE(    10.085),  SIMDE_FLOAT16_VALUE(     5.073),  SIMDE_FLOAT16_VALUE(   -13.995),  SIMDE_FLOAT16_VALUE(    -3.692) },
         SIMDE_FLOAT16_VALUE(    -6.356),
      {  SIMDE_FLOAT16_VALUE(   -64.100),  SIMDE_FLOAT16_VALUE(   -32.244),  SIMDE_FLOAT16_VALUE(    88.952),  SIMDE_FLOAT16_VALUE(    23.466) } },
    { {  SIMDE_FLOAT16_VALUE(     2.616),  SIMDE_FLOAT16_VALUE(    13.510),  SIMDE_FLOAT16_VALUE(   -10.555),  SIMDE_FLOAT16_VALUE(     5.012) },
         SIMDE_FLOAT16_VALUE(     3.524),
      {  SIMDE_FLOAT16_VALUE(     9.219),  SIMDE_FLOAT16_VALUE(    47.609),  SIMDE_FLOAT16_VALUE(   -37.196),  SIMDE_FLOAT16_VALUE(    17.662) } },
    { {  SIMDE_FLOAT16_VALUE(     1.775),  SIMDE_FLOAT16_VALUE(   -14.567),  SIMDE_FLOAT16_VALUE(     0.614),  SIMDE_FLOAT16_VALUE(   -11.430) },
         SIMDE_FLOAT16_VALUE(     7.777),
      {  SIMDE_FLOAT16_VALUE(    13.804),  SIMDE_FLOAT16_VALUE(  -113.288),  SIMDE_FLOAT16_VALUE(     4.775),  SIMDE_FLOAT16_VALUE(   -88.891) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16 b = test_vec[i].b;
    simde_float16x4_t r = simde_vmulx_n_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16_t b = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vmulx_n_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxq_n_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b;
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(    -0.208),  SIMDE_FLOAT16_VALUE(     9.608),  SIMDE_FLOAT16_VALUE(   -10.786),  SIMDE_FLOAT16_VALUE(    -4.477),
         SIMDE_FLOAT16_VALUE(    -5.752),  SIMDE_FLOAT16_VALUE(     0.158),  SIMDE_FLOAT16_VALUE(    -0.915),  SIMDE_FLOAT16_VALUE(    -2.118) },
         SIMDE_FLOAT16_VALUE(    13.403),
      {  SIMDE_FLOAT16_VALUE(    -2.788),  SIMDE_FLOAT16_VALUE(   128.875),  SIMDE_FLOAT16_VALUE(  -144.565),  SIMDE_FLOAT16_VALUE(   -60.005),
         SIMDE_FLOAT16_VALUE(   -77.094),  SIMDE_FLOAT16_VALUE(     2.118),  SIMDE_FLOAT16_VALUE(   -12.264),  SIMDE_FLOAT16_VALUE(   -28.388) } },
    { {  SIMDE_FLOAT16_VALUE(    -1.086),  SIMDE_FLOAT16_VALUE(     9.971),  SIMDE_FLOAT16_VALUE(     4.082),  SIMDE_FLOAT16_VALUE(     1.330),
         SIMDE_FLOAT16_VALUE(    -6.446),  SIMDE_FLOAT16_VALUE(    -9.402),  SIMDE_FLOAT16_VALUE(     1.195),  SIMDE_FLOAT16_VALUE(     9.305) },
         SIMDE_FLOAT16_VALUE(     2.399),
      {  SIMDE_FLOAT16_VALUE(    -2.605),  SIMDE_FLOAT16_VALUE(    23.920),  SIMDE_FLOAT16_VALUE(     9.793),  SIMDE_FLOAT16_VALUE(     3.191),
         SIMDE_FLOAT16_VALUE(   -15.464),  SIMDE_FLOAT16_VALUE(   -22.555),  SIMDE_FLOAT16_VALUE(     2.867),  SIMDE_FLOAT16_VALUE(    22.323) } },
    { {  SIMDE_FLOAT16_VALUE(   -13.930),  SIMDE_FLOAT16_VALUE(    -1.967),  SIMDE_FLOAT16_VALUE(   -10.269),  SIMDE_FLOAT16_VALUE(     7.466),
         SIMDE_FLOAT16_VALUE(     5.053),  SIMDE_FLOAT16_VALUE(    -6.886),  SIMDE_FLOAT16_VALUE(    -3.365),  SIMDE_FLOAT16_VALUE(    -1.955) },
         SIMDE_FLOAT16_VALUE(   -11.395),
      {  SIMDE_FLOAT16_VALUE(   158.732),  SIMDE_FLOAT16_VALUE(    22.414),  SIMDE_FLOAT16_VALUE(   117.015),  SIMDE_FLOAT16_VALUE(   -85.075),
         SIMDE_FLOAT16_VALUE(   -57.579),  SIMDE_FLOAT16_VALUE(    78.466),  SIMDE_FLOAT16_VALUE(    38.344),  SIMDE_FLOAT16_VALUE(    22.277) } },
    { {  SIMDE_FLOAT16_VALUE(     1.599),  SIMDE_FLOAT16_VALUE(    -5.262),  SIMDE_FLOAT16_VALUE(    10.110),  SIMDE_FLOAT16_VALUE(     6.774),
         SIMDE_FLOAT16_VALUE(    11.013),  SIMDE_FLOAT16_VALUE(    -9.229),  SIMDE_FLOAT16_VALUE(    -4.293),  SIMDE_FLOAT16_VALUE(    13.202) },
         SIMDE_FLOAT16_VALUE(    -8.516),
      {  SIMDE_FLOAT16_VALUE(   -13.617),  SIMDE_FLOAT16_VALUE(    44.811),  SIMDE_FLOAT16_VALUE(   -86.097),  SIMDE_FLOAT16_VALUE(   -57.687),
         SIMDE_FLOAT16_VALUE(   -93.787),  SIMDE_FLOAT16_VALUE(    78.594),  SIMDE_FLOAT16_VALUE(    36.559),  SIMDE_FLOAT16_VALUE(  -112.428) } },
    { {  SIMDE_FLOAT16_VALUE(    -4.086),  SIMDE_FLOAT16_VALUE(    -8.122),  SIMDE_FLOAT16_VALUE(    -6.214),  SIMDE_FLOAT16_VALUE(    -0.827),
         SIMDE_FLOAT16_VALUE(    10.931),  SIMDE_FLOAT16_VALUE(    -4.143),  SIMDE_FLOAT16_VALUE(    12.376),  SIMDE_FLOAT16_VALUE(    13.925) },
         SIMDE_FLOAT16_VALUE(    -0.114),
      {  SIMDE_FLOAT16_VALUE(     0.466),  SIMDE_FLOAT16_VALUE(     0.926),  SIMDE_FLOAT16_VALUE(     0.708),  SIMDE_FLOAT16_VALUE(     0.094),
         SIMDE_FLOAT16_VALUE(    -1.246),  SIMDE_FLOAT16_VALUE(     0.472),  SIMDE_FLOAT16_VALUE(    -1.411),  SIMDE_FLOAT16_VALUE(    -1.587) } },
    { {  SIMDE_FLOAT16_VALUE(     1.958),  SIMDE_FLOAT16_VALUE(     2.298),  SIMDE_FLOAT16_VALUE(    -4.675),  SIMDE_FLOAT16_VALUE(   -13.009),
         SIMDE_FLOAT16_VALUE(     7.319),  SIMDE_FLOAT16_VALUE(     0.171),  SIMDE_FLOAT16_VALUE(     2.135),  SIMDE_FLOAT16_VALUE(    -3.966) },
         SIMDE_FLOAT16_VALUE(    -4.928),
      {  SIMDE_FLOAT16_VALUE(    -9.649),  SIMDE_FLOAT16_VALUE(   -11.325),  SIMDE_FLOAT16_VALUE(    23.038),  SIMDE_FLOAT16_VALUE(    64.108),
         SIMDE_FLOAT16_VALUE(   -36.068),  SIMDE_FLOAT16_VALUE(    -0.843),  SIMDE_FLOAT16_VALUE(   -10.521),  SIMDE_FLOAT16_VALUE(    19.544) } },
    { {  SIMDE_FLOAT16_VALUE(    13.718),  SIMDE_FLOAT16_VALUE(   -10.061),  SIMDE_FLOAT16_VALUE(     2.857),  SIMDE_FLOAT16_VALUE(     3.005),
         SIMDE_FLOAT16_VALUE(     6.442),  SIMDE_FLOAT16_VALUE(    -2.565),  SIMDE_FLOAT16_VALUE(   -14.003),  SIMDE_FLOAT16_VALUE(    -4.137) },
         SIMDE_FLOAT16_VALUE(    -0.792),
      {  SIMDE_FLOAT16_VALUE(   -10.865),  SIMDE_FLOAT16_VALUE(     7.968),  SIMDE_FLOAT16_VALUE(    -2.263),  SIMDE_FLOAT16_VALUE(    -2.380),
         SIMDE_FLOAT16_VALUE(    -5.102),  SIMDE_FLOAT16_VALUE(     2.031),  SIMDE_FLOAT16_VALUE(    11.090),  SIMDE_FLOAT16_VALUE(     3.277) } },
    { {  SIMDE_FLOAT16_VALUE(     6.022),  SIMDE_FLOAT16_VALUE(    -5.553),  SIMDE_FLOAT16_VALUE(     0.441),  SIMDE_FLOAT16_VALUE(    -3.958),
         SIMDE_FLOAT16_VALUE(    -4.461),  SIMDE_FLOAT16_VALUE(     3.670),  SIMDE_FLOAT16_VALUE(     5.103),  SIMDE_FLOAT16_VALUE(     5.566) },
         SIMDE_FLOAT16_VALUE(    -7.034),
      {  SIMDE_FLOAT16_VALUE(   -42.359),  SIMDE_FLOAT16_VALUE(    39.060),  SIMDE_FLOAT16_VALUE(    -3.102),  SIMDE_FLOAT16_VALUE(    27.841),
         SIMDE_FLOAT16_VALUE(    31.379),  SIMDE_FLOAT16_VALUE(   -25.815),  SIMDE_FLOAT16_VALUE(   -35.895),  SIMDE_FLOAT16_VALUE(   -39.151) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t r = simde_vmulxq_n_f16(a, test_vec[i].b);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16_t b = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vmulxq_n_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_n_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_n_f16)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
