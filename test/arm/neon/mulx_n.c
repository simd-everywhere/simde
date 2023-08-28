#define SIMDE_TEST_ARM_NEON_INSN mulx_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mulx_n.h"

static int
test_simde_vmulx_n_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float16 a[4];
    simde_float16 b;
    simde_float16 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_C(     6.147),  SIMDE_FLOAT16_C(     8.026),  SIMDE_FLOAT16_C(     8.205), -SIMDE_FLOAT16_C(     4.372) },
         SIMDE_FLOAT16_C(    10.677),
      {  SIMDE_FLOAT16_C(    65.632),  SIMDE_FLOAT16_C(    85.694),  SIMDE_FLOAT16_C(    87.605), -SIMDE_FLOAT16_C(    46.680) } },
    { { -SIMDE_FLOAT16_C(     8.080), -SIMDE_FLOAT16_C(     2.013), -SIMDE_FLOAT16_C(     2.635),  SIMDE_FLOAT16_C(     9.062) },
        -SIMDE_FLOAT16_C(     8.726),
      {  SIMDE_FLOAT16_C(    70.506),  SIMDE_FLOAT16_C(    17.565),  SIMDE_FLOAT16_C(    22.993), -SIMDE_FLOAT16_C(    79.075) } },
    { { -SIMDE_FLOAT16_C(     2.635), -SIMDE_FLOAT16_C(     5.732), -SIMDE_FLOAT16_C(    12.813),  SIMDE_FLOAT16_C(    14.355) },
        -SIMDE_FLOAT16_C(     7.538),
      {  SIMDE_FLOAT16_C(    19.863),  SIMDE_FLOAT16_C(    43.208),  SIMDE_FLOAT16_C(    96.584), -SIMDE_FLOAT16_C(   108.208) } },
    { {  SIMDE_FLOAT16_C(     9.770),  SIMDE_FLOAT16_C(     3.322),  SIMDE_FLOAT16_C(    14.353), -SIMDE_FLOAT16_C(    10.374) },
        -SIMDE_FLOAT16_C(     1.829),
      { -SIMDE_FLOAT16_C(    17.869), -SIMDE_FLOAT16_C(     6.076), -SIMDE_FLOAT16_C(    26.252),  SIMDE_FLOAT16_C(    18.974) } },
    { {  SIMDE_FLOAT16_C(    12.353),  SIMDE_FLOAT16_C(     4.352),  SIMDE_FLOAT16_C(     9.042), -SIMDE_FLOAT16_C(     8.456) },
         SIMDE_FLOAT16_C(     0.593),
      {  SIMDE_FLOAT16_C(     7.325),  SIMDE_FLOAT16_C(     2.581),  SIMDE_FLOAT16_C(     5.362), -SIMDE_FLOAT16_C(     5.014) } },
    { {  SIMDE_FLOAT16_C(    10.085),  SIMDE_FLOAT16_C(     5.073), -SIMDE_FLOAT16_C(    13.995), -SIMDE_FLOAT16_C(     3.692) },
        -SIMDE_FLOAT16_C(     6.356),
      { -SIMDE_FLOAT16_C(    64.100), -SIMDE_FLOAT16_C(    32.244),  SIMDE_FLOAT16_C(    88.952),  SIMDE_FLOAT16_C(    23.466) } },
    { {  SIMDE_FLOAT16_C(     2.616),  SIMDE_FLOAT16_C(    13.510), -SIMDE_FLOAT16_C(    10.555),  SIMDE_FLOAT16_C(     5.012) },
         SIMDE_FLOAT16_C(     3.524),
      {  SIMDE_FLOAT16_C(     9.219),  SIMDE_FLOAT16_C(    47.609), -SIMDE_FLOAT16_C(    37.196),  SIMDE_FLOAT16_C(    17.662) } },
    { {  SIMDE_FLOAT16_C(     1.775), -SIMDE_FLOAT16_C(    14.567),  SIMDE_FLOAT16_C(     0.614), -SIMDE_FLOAT16_C(    11.430) },
         SIMDE_FLOAT16_C(     7.777),
      {  SIMDE_FLOAT16_C(    13.804), -SIMDE_FLOAT16_C(   113.288),  SIMDE_FLOAT16_C(     4.775), -SIMDE_FLOAT16_C(    88.891) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16 b = test_vec[i].b;
    simde_float16x4_t r = simde_vmulx_n_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmulxq_n_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float16 a[8];
    simde_float16 b;
    simde_float16 r[8];
  } test_vec[] = {
    { { -SIMDE_FLOAT16_C(     0.208),  SIMDE_FLOAT16_C(     9.608), -SIMDE_FLOAT16_C(    10.786), -SIMDE_FLOAT16_C(     4.477),
        -SIMDE_FLOAT16_C(     5.752),  SIMDE_FLOAT16_C(     0.158), -SIMDE_FLOAT16_C(     0.915), -SIMDE_FLOAT16_C(     2.118) },
         SIMDE_FLOAT16_C(    13.403),
      { -SIMDE_FLOAT16_C(     2.788),  SIMDE_FLOAT16_C(   128.875), -SIMDE_FLOAT16_C(   144.565), -SIMDE_FLOAT16_C(    60.005),
        -SIMDE_FLOAT16_C(    77.094),  SIMDE_FLOAT16_C(     2.118), -SIMDE_FLOAT16_C(    12.264), -SIMDE_FLOAT16_C(    28.388) } },
    { { -SIMDE_FLOAT16_C(     1.086),  SIMDE_FLOAT16_C(     9.971),  SIMDE_FLOAT16_C(     4.082),  SIMDE_FLOAT16_C(     1.330),
        -SIMDE_FLOAT16_C(     6.446), -SIMDE_FLOAT16_C(     9.402),  SIMDE_FLOAT16_C(     1.195),  SIMDE_FLOAT16_C(     9.305) },
         SIMDE_FLOAT16_C(     2.399),
      { -SIMDE_FLOAT16_C(     2.605),  SIMDE_FLOAT16_C(    23.920),  SIMDE_FLOAT16_C(     9.793),  SIMDE_FLOAT16_C(     3.191),
        -SIMDE_FLOAT16_C(    15.464), -SIMDE_FLOAT16_C(    22.555),  SIMDE_FLOAT16_C(     2.867),  SIMDE_FLOAT16_C(    22.323) } },
    { { -SIMDE_FLOAT16_C(    13.930), -SIMDE_FLOAT16_C(     1.967), -SIMDE_FLOAT16_C(    10.269),  SIMDE_FLOAT16_C(     7.466),
         SIMDE_FLOAT16_C(     5.053), -SIMDE_FLOAT16_C(     6.886), -SIMDE_FLOAT16_C(     3.365), -SIMDE_FLOAT16_C(     1.955) },
        -SIMDE_FLOAT16_C(    11.395),
      {  SIMDE_FLOAT16_C(   158.732),  SIMDE_FLOAT16_C(    22.414),  SIMDE_FLOAT16_C(   117.015), -SIMDE_FLOAT16_C(    85.075),
        -SIMDE_FLOAT16_C(    57.579),  SIMDE_FLOAT16_C(    78.466),  SIMDE_FLOAT16_C(    38.344),  SIMDE_FLOAT16_C(    22.277) } },
    { {  SIMDE_FLOAT16_C(     1.599), -SIMDE_FLOAT16_C(     5.262),  SIMDE_FLOAT16_C(    10.110),  SIMDE_FLOAT16_C(     6.774),
         SIMDE_FLOAT16_C(    11.013), -SIMDE_FLOAT16_C(     9.229), -SIMDE_FLOAT16_C(     4.293),  SIMDE_FLOAT16_C(    13.202) },
        -SIMDE_FLOAT16_C(     8.516),
      { -SIMDE_FLOAT16_C(    13.617),  SIMDE_FLOAT16_C(    44.811), -SIMDE_FLOAT16_C(    86.097), -SIMDE_FLOAT16_C(    57.687),
        -SIMDE_FLOAT16_C(    93.787),  SIMDE_FLOAT16_C(    78.594),  SIMDE_FLOAT16_C(    36.559), -SIMDE_FLOAT16_C(   112.428) } },
    { { -SIMDE_FLOAT16_C(     4.086), -SIMDE_FLOAT16_C(     8.122), -SIMDE_FLOAT16_C(     6.214), -SIMDE_FLOAT16_C(     0.827),
         SIMDE_FLOAT16_C(    10.931), -SIMDE_FLOAT16_C(     4.143),  SIMDE_FLOAT16_C(    12.376),  SIMDE_FLOAT16_C(    13.925) },
        -SIMDE_FLOAT16_C(     0.114),
      {  SIMDE_FLOAT16_C(     0.466),  SIMDE_FLOAT16_C(     0.926),  SIMDE_FLOAT16_C(     0.708),  SIMDE_FLOAT16_C(     0.094),
        -SIMDE_FLOAT16_C(     1.246),  SIMDE_FLOAT16_C(     0.472), -SIMDE_FLOAT16_C(     1.411), -SIMDE_FLOAT16_C(     1.587) } },
    { {  SIMDE_FLOAT16_C(     1.958),  SIMDE_FLOAT16_C(     2.298), -SIMDE_FLOAT16_C(     4.675), -SIMDE_FLOAT16_C(    13.009),
         SIMDE_FLOAT16_C(     7.319),  SIMDE_FLOAT16_C(     0.171),  SIMDE_FLOAT16_C(     2.135), -SIMDE_FLOAT16_C(     3.966) },
        -SIMDE_FLOAT16_C(     4.928),
      { -SIMDE_FLOAT16_C(     9.649), -SIMDE_FLOAT16_C(    11.325),  SIMDE_FLOAT16_C(    23.038),  SIMDE_FLOAT16_C(    64.108),
        -SIMDE_FLOAT16_C(    36.068), -SIMDE_FLOAT16_C(     0.843), -SIMDE_FLOAT16_C(    10.521),  SIMDE_FLOAT16_C(    19.544) } },
    { {  SIMDE_FLOAT16_C(    13.718), -SIMDE_FLOAT16_C(    10.061),  SIMDE_FLOAT16_C(     2.857),  SIMDE_FLOAT16_C(     3.005),
         SIMDE_FLOAT16_C(     6.442), -SIMDE_FLOAT16_C(     2.565), -SIMDE_FLOAT16_C(    14.003), -SIMDE_FLOAT16_C(     4.137) },
        -SIMDE_FLOAT16_C(     0.792),
      { -SIMDE_FLOAT16_C(    10.865),  SIMDE_FLOAT16_C(     7.968), -SIMDE_FLOAT16_C(     2.263), -SIMDE_FLOAT16_C(     2.380),
        -SIMDE_FLOAT16_C(     5.102),  SIMDE_FLOAT16_C(     2.031),  SIMDE_FLOAT16_C(    11.090),  SIMDE_FLOAT16_C(     3.277) } },
    { {  SIMDE_FLOAT16_C(     6.022), -SIMDE_FLOAT16_C(     5.553),  SIMDE_FLOAT16_C(     0.441), -SIMDE_FLOAT16_C(     3.958),
        -SIMDE_FLOAT16_C(     4.461),  SIMDE_FLOAT16_C(     3.670),  SIMDE_FLOAT16_C(     5.103),  SIMDE_FLOAT16_C(     5.566) },
        -SIMDE_FLOAT16_C(     7.034),
      { -SIMDE_FLOAT16_C(    42.359),  SIMDE_FLOAT16_C(    39.060), -SIMDE_FLOAT16_C(     3.102),  SIMDE_FLOAT16_C(    27.841),
         SIMDE_FLOAT16_C(    31.379), -SIMDE_FLOAT16_C(    25.815), -SIMDE_FLOAT16_C(    35.895), -SIMDE_FLOAT16_C(    39.151) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t r = simde_vmulxq_n_f16(a, test_vec[i].b);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_n_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_n_f16)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
