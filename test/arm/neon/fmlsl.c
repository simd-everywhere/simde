#define SIMDE_TEST_ARM_NEON_INSN fmlsl

#include "test-neon.h"
#include "../../../simde/arm/neon/fmlsl.h"

static int
test_simde_vfmlsl_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[4];
    simde_float32_t r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   862.470), -SIMDE_FLOAT32_C(   738.393) },
      { -SIMDE_FLOAT16_C(     1.495), -SIMDE_FLOAT16_C(     5.685), -SIMDE_FLOAT16_C(    10.289), -SIMDE_FLOAT16_C(    25.096) },
      { -SIMDE_FLOAT16_C(    14.380), -SIMDE_FLOAT16_C(     9.463), -SIMDE_FLOAT16_C(    17.890), -SIMDE_FLOAT16_C(     0.576) },
      {  SIMDE_FLOAT32_C(   840.972), -SIMDE_FLOAT32_C(   792.190) } },
    { { -SIMDE_FLOAT32_C(   964.309),  SIMDE_FLOAT32_C(   909.898) },
      { -SIMDE_FLOAT16_C(    10.834),  SIMDE_FLOAT16_C(     1.817), -SIMDE_FLOAT16_C(    24.774), -SIMDE_FLOAT16_C(    18.213) },
      {  SIMDE_FLOAT16_C(    18.274), -SIMDE_FLOAT16_C(    16.656), -SIMDE_FLOAT16_C(     9.572),  SIMDE_FLOAT16_C(    27.703) },
      { -SIMDE_FLOAT32_C(   766.214),  SIMDE_FLOAT32_C(   940.162) } },
    { { -SIMDE_FLOAT32_C(   404.260), -SIMDE_FLOAT32_C(   555.077) },
      { -SIMDE_FLOAT16_C(     8.693), -SIMDE_FLOAT16_C(    18.662), -SIMDE_FLOAT16_C(    23.289), -SIMDE_FLOAT16_C(     9.533) },
      {  SIMDE_FLOAT16_C(    20.804), -SIMDE_FLOAT16_C(    19.284), -SIMDE_FLOAT16_C(     2.164),  SIMDE_FLOAT16_C(    21.143) },
      { -SIMDE_FLOAT32_C(   223.411), -SIMDE_FLOAT32_C(   914.792) } },
    { { -SIMDE_FLOAT32_C(   200.159),  SIMDE_FLOAT32_C(   157.390) },
      {  SIMDE_FLOAT16_C(    27.155),  SIMDE_FLOAT16_C(    17.688),  SIMDE_FLOAT16_C(    24.070), -SIMDE_FLOAT16_C(    10.002) },
      {  SIMDE_FLOAT16_C(    15.180),  SIMDE_FLOAT16_C(    17.241),  SIMDE_FLOAT16_C(    17.256), -SIMDE_FLOAT16_C(    13.817) },
      { -SIMDE_FLOAT32_C(   612.372), -SIMDE_FLOAT32_C(   147.443) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x2_t r = simde_vfmlsl_low_f16(buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlslq_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[8];
    simde_float32_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   850.862), -SIMDE_FLOAT32_C(   788.246),  SIMDE_FLOAT32_C(   864.626), -SIMDE_FLOAT32_C(   466.541) },
      {  SIMDE_FLOAT16_C(    16.525), -SIMDE_FLOAT16_C(    28.213),  SIMDE_FLOAT16_C(    10.622),  SIMDE_FLOAT16_C(    11.626),
         SIMDE_FLOAT16_C(    20.682),  SIMDE_FLOAT16_C(     6.255),  SIMDE_FLOAT16_C(     1.879),  SIMDE_FLOAT16_C(    16.726) },
      {  SIMDE_FLOAT16_C(    12.734),  SIMDE_FLOAT16_C(     4.316),  SIMDE_FLOAT16_C(    24.394),  SIMDE_FLOAT16_C(    18.307),
        -SIMDE_FLOAT16_C(    26.404), -SIMDE_FLOAT16_C(    17.535), -SIMDE_FLOAT16_C(    23.364),  SIMDE_FLOAT16_C(     9.966) },
      {  SIMDE_FLOAT32_C(   640.433), -SIMDE_FLOAT32_C(   666.479),  SIMDE_FLOAT32_C(   605.513), -SIMDE_FLOAT32_C(   679.378) } },
    { {  SIMDE_FLOAT32_C(   662.627),  SIMDE_FLOAT32_C(   680.116), -SIMDE_FLOAT32_C(   660.018), -SIMDE_FLOAT32_C(   219.447) },
      {  SIMDE_FLOAT16_C(    13.558),  SIMDE_FLOAT16_C(    26.933), -SIMDE_FLOAT16_C(    23.264),  SIMDE_FLOAT16_C(    18.761),
        -SIMDE_FLOAT16_C(    10.374),  SIMDE_FLOAT16_C(    27.155), -SIMDE_FLOAT16_C(    17.363), -SIMDE_FLOAT16_C(     2.179) },
      { -SIMDE_FLOAT16_C(    20.426), -SIMDE_FLOAT16_C(     0.929),  SIMDE_FLOAT16_C(    15.701),  SIMDE_FLOAT16_C(     3.319),
         SIMDE_FLOAT16_C(    18.206),  SIMDE_FLOAT16_C(    27.679),  SIMDE_FLOAT16_C(     3.665), -SIMDE_FLOAT16_C(    24.338) },
      {  SIMDE_FLOAT32_C(   939.439),  SIMDE_FLOAT32_C(   705.137), -SIMDE_FLOAT32_C(   294.750), -SIMDE_FLOAT32_C(   281.715) } },
    { { -SIMDE_FLOAT32_C(   687.558), -SIMDE_FLOAT32_C(   223.718),  SIMDE_FLOAT32_C(   599.035), -SIMDE_FLOAT32_C(   641.397) },
      {  SIMDE_FLOAT16_C(    26.258), -SIMDE_FLOAT16_C(    22.615),  SIMDE_FLOAT16_C(    11.378), -SIMDE_FLOAT16_C(    17.512),
        -SIMDE_FLOAT16_C(    19.390),  SIMDE_FLOAT16_C(    14.793),  SIMDE_FLOAT16_C(    29.321), -SIMDE_FLOAT16_C(    29.472) },
      { -SIMDE_FLOAT16_C(    11.765), -SIMDE_FLOAT16_C(    12.557),  SIMDE_FLOAT16_C(    12.535), -SIMDE_FLOAT16_C(    14.359),
        -SIMDE_FLOAT16_C(    26.602),  SIMDE_FLOAT16_C(     4.759),  SIMDE_FLOAT16_C(    23.836),  SIMDE_FLOAT16_C(     5.183) },
      { -SIMDE_FLOAT32_C(   378.526), -SIMDE_FLOAT32_C(   507.571),  SIMDE_FLOAT32_C(   456.412), -SIMDE_FLOAT32_C(   892.852) } },
    { {  SIMDE_FLOAT32_C(   242.510),  SIMDE_FLOAT32_C(   346.573), -SIMDE_FLOAT32_C(    55.046), -SIMDE_FLOAT32_C(   627.016) },
      { -SIMDE_FLOAT16_C(    25.870),  SIMDE_FLOAT16_C(     7.118), -SIMDE_FLOAT16_C(    17.810),  SIMDE_FLOAT16_C(     6.908),
         SIMDE_FLOAT16_C(    22.615),  SIMDE_FLOAT16_C(    20.780),  SIMDE_FLOAT16_C(     6.999), -SIMDE_FLOAT16_C(    13.540) },
      { -SIMDE_FLOAT16_C(     0.062),  SIMDE_FLOAT16_C(    25.294),  SIMDE_FLOAT16_C(     3.793),  SIMDE_FLOAT16_C(    24.341),
        -SIMDE_FLOAT16_C(    22.556), -SIMDE_FLOAT16_C(    25.966),  SIMDE_FLOAT16_C(    29.396), -SIMDE_FLOAT16_C(     1.016) },
      {  SIMDE_FLOAT32_C(   240.906),  SIMDE_FLOAT32_C(   166.530),  SIMDE_FLOAT32_C(    12.507), -SIMDE_FLOAT32_C(   795.164) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x4_t r = simde_vfmlslq_low_f16(buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlsl_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[4];
    simde_float32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   132.713), -SIMDE_FLOAT32_C(   958.361) },
      { -SIMDE_FLOAT16_C(     7.271), -SIMDE_FLOAT16_C(    28.274), -SIMDE_FLOAT16_C(    24.933),  SIMDE_FLOAT16_C(    28.972) },
      {  SIMDE_FLOAT16_C(     6.376),  SIMDE_FLOAT16_C(    15.313),  SIMDE_FLOAT16_C(     5.324), -SIMDE_FLOAT16_C(     3.177) },
      {  SIMDE_FLOAT32_C(     0.030), -SIMDE_FLOAT32_C(   866.317) } },
    { {  SIMDE_FLOAT32_C(    84.525),  SIMDE_FLOAT32_C(   487.748) },
      {  SIMDE_FLOAT16_C(     1.729), -SIMDE_FLOAT16_C(    11.326),  SIMDE_FLOAT16_C(    16.362), -SIMDE_FLOAT16_C(    21.948) },
      {  SIMDE_FLOAT16_C(     4.556),  SIMDE_FLOAT16_C(    23.947), -SIMDE_FLOAT16_C(     2.075),  SIMDE_FLOAT16_C(    28.710) },
      {  SIMDE_FLOAT32_C(   118.476),  SIMDE_FLOAT32_C(  1117.875) } },
    { {  SIMDE_FLOAT32_C(   139.570), -SIMDE_FLOAT32_C(   787.259) },
      {  SIMDE_FLOAT16_C(    14.681),  SIMDE_FLOAT16_C(     9.803),  SIMDE_FLOAT16_C(    18.308),  SIMDE_FLOAT16_C(    23.199) },
      { -SIMDE_FLOAT16_C(    19.724), -SIMDE_FLOAT16_C(    21.183),  SIMDE_FLOAT16_C(    14.436),  SIMDE_FLOAT16_C(    11.391) },
      { -SIMDE_FLOAT32_C(   124.724), -SIMDE_FLOAT32_C(  1051.519) } },
    { {  SIMDE_FLOAT32_C(   613.455),  SIMDE_FLOAT32_C(   626.408) },
      { -SIMDE_FLOAT16_C(     0.112),  SIMDE_FLOAT16_C(    17.076), -SIMDE_FLOAT16_C(    15.637),  SIMDE_FLOAT16_C(    29.510) },
      { -SIMDE_FLOAT16_C(    29.464),  SIMDE_FLOAT16_C(    12.845),  SIMDE_FLOAT16_C(     7.998),  SIMDE_FLOAT16_C(     6.187) },
      {  SIMDE_FLOAT32_C(   738.520),  SIMDE_FLOAT32_C(   443.830) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x2_t r = simde_vfmlsl_high_f16(buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlslq_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[8];
    simde_float32_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   467.701), -SIMDE_FLOAT32_C(    29.510), -SIMDE_FLOAT32_C(   935.115), -SIMDE_FLOAT32_C(   675.906) },
      {  SIMDE_FLOAT16_C(    15.539),  SIMDE_FLOAT16_C(     0.443),  SIMDE_FLOAT16_C(     2.680),  SIMDE_FLOAT16_C(    21.051),
        -SIMDE_FLOAT16_C(    11.561),  SIMDE_FLOAT16_C(    29.589), -SIMDE_FLOAT16_C(    13.975), -SIMDE_FLOAT16_C(    23.969) },
      {  SIMDE_FLOAT16_C(    24.588), -SIMDE_FLOAT16_C(    11.197),  SIMDE_FLOAT16_C(    23.814), -SIMDE_FLOAT16_C(    27.681),
        -SIMDE_FLOAT16_C(    15.937), -SIMDE_FLOAT16_C(     9.616), -SIMDE_FLOAT16_C(    21.339), -SIMDE_FLOAT16_C(     1.609) },
      {  SIMDE_FLOAT32_C(   283.453),  SIMDE_FLOAT32_C(   255.018), -SIMDE_FLOAT32_C(  1233.328), -SIMDE_FLOAT32_C(   714.472) } },
    { { -SIMDE_FLOAT32_C(   643.252), -SIMDE_FLOAT32_C(   142.305), -SIMDE_FLOAT32_C(   729.511),  SIMDE_FLOAT32_C(   956.812) },
      {  SIMDE_FLOAT16_C(    15.653),  SIMDE_FLOAT16_C(    22.598),  SIMDE_FLOAT16_C(    12.231), -SIMDE_FLOAT16_C(     4.252),
        -SIMDE_FLOAT16_C(    29.462), -SIMDE_FLOAT16_C(     6.017),  SIMDE_FLOAT16_C(    29.109), -SIMDE_FLOAT16_C(    15.710) },
      { -SIMDE_FLOAT16_C(    14.193),  SIMDE_FLOAT16_C(     6.820),  SIMDE_FLOAT16_C(    16.830),  SIMDE_FLOAT16_C(    16.371),
         SIMDE_FLOAT16_C(     3.103), -SIMDE_FLOAT16_C(    11.377), -SIMDE_FLOAT16_C(    11.093),  SIMDE_FLOAT16_C(    12.935) },
      { -SIMDE_FLOAT32_C(   551.831), -SIMDE_FLOAT32_C(   210.760), -SIMDE_FLOAT32_C(   406.605),  SIMDE_FLOAT32_C(  1160.021) } },
    { { -SIMDE_FLOAT32_C(   159.853),  SIMDE_FLOAT32_C(   790.259), -SIMDE_FLOAT32_C(   153.159),  SIMDE_FLOAT32_C(   977.137) },
      {  SIMDE_FLOAT16_C(    22.456),  SIMDE_FLOAT16_C(     3.921),  SIMDE_FLOAT16_C(    20.404), -SIMDE_FLOAT16_C(    22.311),
        -SIMDE_FLOAT16_C(    14.103),  SIMDE_FLOAT16_C(     8.163), -SIMDE_FLOAT16_C(    26.257), -SIMDE_FLOAT16_C(     6.839) },
      {  SIMDE_FLOAT16_C(    23.442), -SIMDE_FLOAT16_C(    10.680), -SIMDE_FLOAT16_C(     3.476),  SIMDE_FLOAT16_C(    14.279),
         SIMDE_FLOAT16_C(    15.311), -SIMDE_FLOAT16_C(     1.259),  SIMDE_FLOAT16_C(    28.349), -SIMDE_FLOAT16_C(     0.262) },
      {  SIMDE_FLOAT32_C(    56.078),  SIMDE_FLOAT32_C(   800.536),  SIMDE_FLOAT32_C(   590.864),  SIMDE_FLOAT32_C(   975.345) } },
    { { -SIMDE_FLOAT32_C(   587.877),  SIMDE_FLOAT32_C(   900.658),  SIMDE_FLOAT32_C(   779.679),  SIMDE_FLOAT32_C(   486.385) },
      {  SIMDE_FLOAT16_C(     4.177),  SIMDE_FLOAT16_C(    15.169), -SIMDE_FLOAT16_C(    17.122), -SIMDE_FLOAT16_C(    24.153),
         SIMDE_FLOAT16_C(    13.249),  SIMDE_FLOAT16_C(    27.075), -SIMDE_FLOAT16_C(    23.418),  SIMDE_FLOAT16_C(    21.330) },
      {  SIMDE_FLOAT16_C(     9.997), -SIMDE_FLOAT16_C(     9.739), -SIMDE_FLOAT16_C(    21.997), -SIMDE_FLOAT16_C(    17.648),
        -SIMDE_FLOAT16_C(    14.801),  SIMDE_FLOAT16_C(    26.899),  SIMDE_FLOAT16_C(    23.345), -SIMDE_FLOAT16_C(    28.473) },
      { -SIMDE_FLOAT32_C(   391.779),  SIMDE_FLOAT32_C(   172.087),  SIMDE_FLOAT32_C(  1326.372),  SIMDE_FLOAT32_C(  1093.570) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x4_t r = simde_vfmlslq_high_f16(buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlsl_lane_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[4];
    int8_t lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   466.298),  SIMDE_FLOAT32_C(   370.861) },
      {  SIMDE_FLOAT16_C(    24.539),  SIMDE_FLOAT16_C(    20.909), -SIMDE_FLOAT16_C(     5.545), -SIMDE_FLOAT16_C(    20.879) },
      { -SIMDE_FLOAT16_C(     1.080),  SIMDE_FLOAT16_C(     1.944),  SIMDE_FLOAT16_C(    16.164),  SIMDE_FLOAT16_C(     6.338) },
         INT8_C(         0),
      {  SIMDE_FLOAT32_C(   492.800),  SIMDE_FLOAT32_C(   393.443) } },
    { {  SIMDE_FLOAT32_C(   361.225), -SIMDE_FLOAT32_C(   280.772) },
      { -SIMDE_FLOAT16_C(    20.985),  SIMDE_FLOAT16_C(     0.472), -SIMDE_FLOAT16_C(     3.127), -SIMDE_FLOAT16_C(     4.801) },
      {  SIMDE_FLOAT16_C(    10.636), -SIMDE_FLOAT16_C(    24.202), -SIMDE_FLOAT16_C(    16.395),  SIMDE_FLOAT16_C(     5.341) },
         INT8_C(         2),
      {  SIMDE_FLOAT32_C(    17.277), -SIMDE_FLOAT32_C(   273.034) } },
    { { -SIMDE_FLOAT32_C(   540.125), -SIMDE_FLOAT32_C(   974.056) },
      { -SIMDE_FLOAT16_C(     1.396),  SIMDE_FLOAT16_C(     6.859), -SIMDE_FLOAT16_C(    22.605),  SIMDE_FLOAT16_C(    22.206) },
      {  SIMDE_FLOAT16_C(    10.272),  SIMDE_FLOAT16_C(    10.417), -SIMDE_FLOAT16_C(    24.248),  SIMDE_FLOAT16_C(    16.909) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   516.520), -SIMDE_FLOAT32_C(  1090.035) } },
    { { -SIMDE_FLOAT32_C(   452.205), -SIMDE_FLOAT32_C(   495.839) },
      {  SIMDE_FLOAT16_C(    27.957),  SIMDE_FLOAT16_C(     6.129), -SIMDE_FLOAT16_C(     0.713), -SIMDE_FLOAT16_C(    12.082) },
      {  SIMDE_FLOAT16_C(    28.256),  SIMDE_FLOAT16_C(    27.435), -SIMDE_FLOAT16_C(     5.818), -SIMDE_FLOAT16_C(    13.070) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(    86.807), -SIMDE_FLOAT32_C(   415.733) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x2_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_4_(simde_vfmlsl_lane_low_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlsl_laneq_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[8];
    int8_t lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   577.514),  SIMDE_FLOAT32_C(   702.013) },
      {  SIMDE_FLOAT16_C(    11.517), -SIMDE_FLOAT16_C(     3.167), -SIMDE_FLOAT16_C(    13.263), -SIMDE_FLOAT16_C(     7.661) },
      { -SIMDE_FLOAT16_C(    11.889),  SIMDE_FLOAT16_C(    13.910), -SIMDE_FLOAT16_C(    27.151),  SIMDE_FLOAT16_C(    19.332),
         SIMDE_FLOAT16_C(    13.683), -SIMDE_FLOAT16_C(     9.459),  SIMDE_FLOAT16_C(    20.733),  SIMDE_FLOAT16_C(     2.332) },
         INT8_C(         7),
      { -SIMDE_FLOAT32_C(   604.372),  SIMDE_FLOAT32_C(   709.398) } },
    { { -SIMDE_FLOAT32_C(   957.923),  SIMDE_FLOAT32_C(   257.656) },
      { -SIMDE_FLOAT16_C(    17.862),  SIMDE_FLOAT16_C(     4.819), -SIMDE_FLOAT16_C(    11.971),  SIMDE_FLOAT16_C(    21.803) },
      {  SIMDE_FLOAT16_C(    12.436),  SIMDE_FLOAT16_C(    28.559),  SIMDE_FLOAT16_C(    13.268), -SIMDE_FLOAT16_C(    22.133),
        -SIMDE_FLOAT16_C(    12.201),  SIMDE_FLOAT16_C(    21.753),  SIMDE_FLOAT16_C(    24.465),  SIMDE_FLOAT16_C(     1.615) },
         INT8_C(         5),
      { -SIMDE_FLOAT32_C(   569.481),  SIMDE_FLOAT32_C(   152.828) } },
    { { -SIMDE_FLOAT32_C(   419.683), -SIMDE_FLOAT32_C(   598.369) },
      {  SIMDE_FLOAT16_C(    10.406),  SIMDE_FLOAT16_C(    11.424),  SIMDE_FLOAT16_C(    25.461), -SIMDE_FLOAT16_C(     1.504) },
      {  SIMDE_FLOAT16_C(    22.751),  SIMDE_FLOAT16_C(    21.087), -SIMDE_FLOAT16_C(    22.525), -SIMDE_FLOAT16_C(    28.914),
         SIMDE_FLOAT16_C(    18.698),  SIMDE_FLOAT16_C(     4.235), -SIMDE_FLOAT16_C(     7.682), -SIMDE_FLOAT16_C(    14.215) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   118.804), -SIMDE_FLOAT32_C(   268.205) } },
    { { -SIMDE_FLOAT32_C(   134.926), -SIMDE_FLOAT32_C(   728.911) },
      { -SIMDE_FLOAT16_C(    15.608), -SIMDE_FLOAT16_C(    14.004), -SIMDE_FLOAT16_C(    25.466),  SIMDE_FLOAT16_C(    23.582) },
      { -SIMDE_FLOAT16_C(     6.352),  SIMDE_FLOAT16_C(    10.215),  SIMDE_FLOAT16_C(     9.798), -SIMDE_FLOAT16_C(    13.754),
        -SIMDE_FLOAT16_C(    25.969), -SIMDE_FLOAT16_C(     4.773), -SIMDE_FLOAT16_C(    13.396),  SIMDE_FLOAT16_C(     0.550) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   234.068), -SIMDE_FLOAT32_C(   817.864) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x2_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_8_(simde_vfmlsl_laneq_low_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlslq_lane_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[4];
    int8_t lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   235.557),  SIMDE_FLOAT32_C(   786.443),  SIMDE_FLOAT32_C(   669.340),  SIMDE_FLOAT32_C(   589.758) },
      { -SIMDE_FLOAT16_C(    14.688), -SIMDE_FLOAT16_C(    16.477), -SIMDE_FLOAT16_C(     3.837), -SIMDE_FLOAT16_C(    19.593),
         SIMDE_FLOAT16_C(    16.931), -SIMDE_FLOAT16_C(    20.669),  SIMDE_FLOAT16_C(    27.323), -SIMDE_FLOAT16_C(    22.574) },
      { -SIMDE_FLOAT16_C(    24.284),  SIMDE_FLOAT16_C(    16.848),  SIMDE_FLOAT16_C(    14.524),  SIMDE_FLOAT16_C(    15.461) },
         INT8_C(         3),
      {  SIMDE_FLOAT32_C(   462.648),  SIMDE_FLOAT32_C(  1041.306),  SIMDE_FLOAT32_C(   728.664),  SIMDE_FLOAT32_C(   892.685) } },
    { { -SIMDE_FLOAT32_C(   245.508), -SIMDE_FLOAT32_C(   133.997), -SIMDE_FLOAT32_C(   893.838), -SIMDE_FLOAT32_C(   813.693) },
      { -SIMDE_FLOAT16_C(     0.797),  SIMDE_FLOAT16_C(    16.498), -SIMDE_FLOAT16_C(    22.509),  SIMDE_FLOAT16_C(    10.222),
        -SIMDE_FLOAT16_C(    27.448), -SIMDE_FLOAT16_C(    17.464), -SIMDE_FLOAT16_C(    24.913),  SIMDE_FLOAT16_C(    27.772) },
      {  SIMDE_FLOAT16_C(    28.760),  SIMDE_FLOAT16_C(     6.637), -SIMDE_FLOAT16_C(     1.842),  SIMDE_FLOAT16_C(    28.381) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   222.888), -SIMDE_FLOAT32_C(   602.227), -SIMDE_FLOAT32_C(   255.010), -SIMDE_FLOAT32_C(  1103.650) } },
    { { -SIMDE_FLOAT32_C(    11.943), -SIMDE_FLOAT32_C(   331.833), -SIMDE_FLOAT32_C(   532.550),  SIMDE_FLOAT32_C(    78.813) },
      {  SIMDE_FLOAT16_C(    25.269),  SIMDE_FLOAT16_C(     3.323),  SIMDE_FLOAT16_C(    11.045),  SIMDE_FLOAT16_C(    13.937),
         SIMDE_FLOAT16_C(     0.795), -SIMDE_FLOAT16_C(    12.524), -SIMDE_FLOAT16_C(     0.176),  SIMDE_FLOAT16_C(    15.856) },
      {  SIMDE_FLOAT16_C(    12.956), -SIMDE_FLOAT16_C(    24.150), -SIMDE_FLOAT16_C(    22.836),  SIMDE_FLOAT16_C(     0.819) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(   598.303), -SIMDE_FLOAT32_C(   251.583), -SIMDE_FLOAT32_C(   265.698),  SIMDE_FLOAT32_C(   415.392) } },
    { {  SIMDE_FLOAT32_C(    59.290), -SIMDE_FLOAT32_C(   595.629),  SIMDE_FLOAT32_C(   237.487), -SIMDE_FLOAT32_C(   690.185) },
      { -SIMDE_FLOAT16_C(    24.047),  SIMDE_FLOAT16_C(     7.120), -SIMDE_FLOAT16_C(     5.066), -SIMDE_FLOAT16_C(    16.770),
         SIMDE_FLOAT16_C(    22.636),  SIMDE_FLOAT16_C(    21.320), -SIMDE_FLOAT16_C(    13.033),  SIMDE_FLOAT16_C(    17.567) },
      { -SIMDE_FLOAT16_C(     9.656), -SIMDE_FLOAT16_C(    26.239), -SIMDE_FLOAT16_C(     7.176), -SIMDE_FLOAT16_C(    10.623) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   196.161), -SIMDE_FLOAT32_C(   519.993),  SIMDE_FLOAT32_C(   183.671), -SIMDE_FLOAT32_C(   868.333) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x4_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_4_(simde_vfmlslq_lane_low_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlslq_laneq_low_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[8];
    int8_t lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   470.656),  SIMDE_FLOAT32_C(    98.721),  SIMDE_FLOAT32_C(   374.717), -SIMDE_FLOAT32_C(    26.079) },
      { -SIMDE_FLOAT16_C(     1.666),  SIMDE_FLOAT16_C(    24.935), -SIMDE_FLOAT16_C(    28.747), -SIMDE_FLOAT16_C(     2.169),
        -SIMDE_FLOAT16_C(    10.055), -SIMDE_FLOAT16_C(    17.768),  SIMDE_FLOAT16_C(    25.798), -SIMDE_FLOAT16_C(     4.663) },
      {  SIMDE_FLOAT16_C(    10.614), -SIMDE_FLOAT16_C(    12.058), -SIMDE_FLOAT16_C(    28.034),  SIMDE_FLOAT16_C(    12.623),
         SIMDE_FLOAT16_C(    26.563),  SIMDE_FLOAT16_C(    27.397), -SIMDE_FLOAT16_C(    11.686),  SIMDE_FLOAT16_C(     6.308) },
         INT8_C(         7),
      {  SIMDE_FLOAT32_C(   481.165), -SIMDE_FLOAT32_C(    58.569),  SIMDE_FLOAT32_C(   556.053), -SIMDE_FLOAT32_C(    12.397) } },
    { { -SIMDE_FLOAT32_C(   800.239), -SIMDE_FLOAT32_C(   298.674), -SIMDE_FLOAT32_C(   171.620), -SIMDE_FLOAT32_C(   740.700) },
      {  SIMDE_FLOAT16_C(    27.746),  SIMDE_FLOAT16_C(    22.266), -SIMDE_FLOAT16_C(    23.804), -SIMDE_FLOAT16_C(    11.896),
        -SIMDE_FLOAT16_C(     7.848),  SIMDE_FLOAT16_C(    27.900),  SIMDE_FLOAT16_C(    24.526), -SIMDE_FLOAT16_C(    21.386) },
      {  SIMDE_FLOAT16_C(     0.768),  SIMDE_FLOAT16_C(    15.768), -SIMDE_FLOAT16_C(     8.788),  SIMDE_FLOAT16_C(    15.314),
         SIMDE_FLOAT16_C(     4.228), -SIMDE_FLOAT16_C(     2.792),  SIMDE_FLOAT16_C(     5.798), -SIMDE_FLOAT16_C(    11.947) },
         INT8_C(         4),
      { -SIMDE_FLOAT32_C(   917.549), -SIMDE_FLOAT32_C(   392.815), -SIMDE_FLOAT32_C(    70.977), -SIMDE_FLOAT32_C(   690.404) } },
    { { -SIMDE_FLOAT32_C(   744.499),  SIMDE_FLOAT32_C(   659.846), -SIMDE_FLOAT32_C(   956.874), -SIMDE_FLOAT32_C(   110.245) },
      {  SIMDE_FLOAT16_C(    28.513),  SIMDE_FLOAT16_C(    16.232),  SIMDE_FLOAT16_C(    14.516),  SIMDE_FLOAT16_C(    20.420),
         SIMDE_FLOAT16_C(    24.393), -SIMDE_FLOAT16_C(    22.925),  SIMDE_FLOAT16_C(    18.291), -SIMDE_FLOAT16_C(     8.466) },
      {  SIMDE_FLOAT16_C(    17.255),  SIMDE_FLOAT16_C(    19.464),  SIMDE_FLOAT16_C(    15.841),  SIMDE_FLOAT16_C(    10.642),
         SIMDE_FLOAT16_C(    19.581),  SIMDE_FLOAT16_C(    17.864), -SIMDE_FLOAT16_C(     4.707), -SIMDE_FLOAT16_C(    19.599) },
         INT8_C(         4),
      { -SIMDE_FLOAT32_C(  1302.812),  SIMDE_FLOAT32_C(   342.007), -SIMDE_FLOAT32_C(  1241.112), -SIMDE_FLOAT32_C(   510.089) } },
    { {  SIMDE_FLOAT32_C(   358.680),  SIMDE_FLOAT32_C(   976.535),  SIMDE_FLOAT32_C(   584.782),  SIMDE_FLOAT32_C(   981.761) },
      { -SIMDE_FLOAT16_C(    28.919), -SIMDE_FLOAT16_C(     3.562),  SIMDE_FLOAT16_C(     6.649),  SIMDE_FLOAT16_C(    14.119),
         SIMDE_FLOAT16_C(     9.733),  SIMDE_FLOAT16_C(    11.743),  SIMDE_FLOAT16_C(    21.405),  SIMDE_FLOAT16_C(     1.923) },
      {  SIMDE_FLOAT16_C(    29.936), -SIMDE_FLOAT16_C(    17.739), -SIMDE_FLOAT16_C(    15.950), -SIMDE_FLOAT16_C(    28.330),
        -SIMDE_FLOAT16_C(    22.796), -SIMDE_FLOAT16_C(     5.568),  SIMDE_FLOAT16_C(    23.796), -SIMDE_FLOAT16_C(    28.992) },
         INT8_C(         4),
      { -SIMDE_FLOAT32_C(   300.558),  SIMDE_FLOAT32_C(   895.336),  SIMDE_FLOAT32_C(   736.353),  SIMDE_FLOAT32_C(  1303.618) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x4_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_8_(simde_vfmlslq_laneq_low_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlsl_lane_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[4];
    int8_t lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   959.403),  SIMDE_FLOAT32_C(   363.161) },
      { -SIMDE_FLOAT16_C(    13.577), -SIMDE_FLOAT16_C(    14.364), -SIMDE_FLOAT16_C(    19.874),  SIMDE_FLOAT16_C(     5.489) },
      {  SIMDE_FLOAT16_C(    14.802),  SIMDE_FLOAT16_C(    23.600), -SIMDE_FLOAT16_C(    23.310), -SIMDE_FLOAT16_C(    25.931) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   665.228),  SIMDE_FLOAT32_C(   281.913) } },
    { {  SIMDE_FLOAT32_C(   797.569),  SIMDE_FLOAT32_C(   150.509) },
      { -SIMDE_FLOAT16_C(    27.143), -SIMDE_FLOAT16_C(    13.192),  SIMDE_FLOAT16_C(    23.609),  SIMDE_FLOAT16_C(     8.341) },
      { -SIMDE_FLOAT16_C(     9.814),  SIMDE_FLOAT16_C(     5.639),  SIMDE_FLOAT16_C(    19.088),  SIMDE_FLOAT16_C(    15.698) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(   664.438),  SIMDE_FLOAT32_C(   103.474) } },
    { {  SIMDE_FLOAT32_C(   675.819),  SIMDE_FLOAT32_C(   806.122) },
      { -SIMDE_FLOAT16_C(     0.649),  SIMDE_FLOAT16_C(    13.432),  SIMDE_FLOAT16_C(     4.591), -SIMDE_FLOAT16_C(    15.450) },
      {  SIMDE_FLOAT16_C(     5.750),  SIMDE_FLOAT16_C(    18.407), -SIMDE_FLOAT16_C(    16.101),  SIMDE_FLOAT16_C(    25.628) },
         INT8_C(         0),
      {  SIMDE_FLOAT32_C(   649.421),  SIMDE_FLOAT32_C(   894.960) } },
    { { -SIMDE_FLOAT32_C(   647.818),  SIMDE_FLOAT32_C(   814.212) },
      {  SIMDE_FLOAT16_C(     9.421),  SIMDE_FLOAT16_C(    13.768),  SIMDE_FLOAT16_C(    29.112), -SIMDE_FLOAT16_C(     6.674) },
      {  SIMDE_FLOAT16_C(     9.095),  SIMDE_FLOAT16_C(     3.822),  SIMDE_FLOAT16_C(    17.625),  SIMDE_FLOAT16_C(    13.060) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   912.592),  SIMDE_FLOAT32_C(   874.912) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x2_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_4_(simde_vfmlsl_lane_high_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlsl_laneq_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[2];
    simde_float16_t a[4];
    simde_float16_t b[8];
    int8_t lane;
    simde_float32_t r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   907.059), -SIMDE_FLOAT32_C(    91.658) },
      {  SIMDE_FLOAT16_C(    23.623), -SIMDE_FLOAT16_C(     3.579), -SIMDE_FLOAT16_C(    22.888),  SIMDE_FLOAT16_C(    19.460) },
      {  SIMDE_FLOAT16_C(     4.549), -SIMDE_FLOAT16_C(    15.595),  SIMDE_FLOAT16_C(     3.113),  SIMDE_FLOAT16_C(     5.928),
        -SIMDE_FLOAT16_C(     8.615),  SIMDE_FLOAT16_C(    13.373), -SIMDE_FLOAT16_C(    26.577), -SIMDE_FLOAT16_C(    10.178) },
         INT8_C(         0),
      { -SIMDE_FLOAT32_C(   802.942), -SIMDE_FLOAT32_C(   180.182) } },
    { {  SIMDE_FLOAT32_C(   144.127),  SIMDE_FLOAT32_C(   542.104) },
      { -SIMDE_FLOAT16_C(    27.375),  SIMDE_FLOAT16_C(    23.023), -SIMDE_FLOAT16_C(    14.482),  SIMDE_FLOAT16_C(     5.276) },
      {  SIMDE_FLOAT16_C(    28.760), -SIMDE_FLOAT16_C(     1.117),  SIMDE_FLOAT16_C(    12.979),  SIMDE_FLOAT16_C(    20.583),
        -SIMDE_FLOAT16_C(     9.482), -SIMDE_FLOAT16_C(    28.655), -SIMDE_FLOAT16_C(    29.880), -SIMDE_FLOAT16_C(    28.545) },
         INT8_C(         6),
      { -SIMDE_FLOAT32_C(   288.595),  SIMDE_FLOAT32_C(   699.751) } },
    { { -SIMDE_FLOAT32_C(   144.280), -SIMDE_FLOAT32_C(   329.618) },
      { -SIMDE_FLOAT16_C(    10.176), -SIMDE_FLOAT16_C(     2.540), -SIMDE_FLOAT16_C(     5.224), -SIMDE_FLOAT16_C(     5.458) },
      {  SIMDE_FLOAT16_C(    12.123), -SIMDE_FLOAT16_C(    14.259),  SIMDE_FLOAT16_C(    13.747),  SIMDE_FLOAT16_C(    22.426),
         SIMDE_FLOAT16_C(     1.580), -SIMDE_FLOAT16_C(    15.808),  SIMDE_FLOAT16_C(    17.325),  SIMDE_FLOAT16_C(    17.181) },
         INT8_C(         5),
      { -SIMDE_FLOAT32_C(   226.861), -SIMDE_FLOAT32_C(   415.898) } },
    { { -SIMDE_FLOAT32_C(   262.655),  SIMDE_FLOAT32_C(   793.971) },
      { -SIMDE_FLOAT16_C(    16.858),  SIMDE_FLOAT16_C(     8.745), -SIMDE_FLOAT16_C(     3.932),  SIMDE_FLOAT16_C(    22.752) },
      { -SIMDE_FLOAT16_C(    28.119),  SIMDE_FLOAT16_C(    10.453),  SIMDE_FLOAT16_C(    17.881),  SIMDE_FLOAT16_C(    14.951),
        -SIMDE_FLOAT16_C(     4.709), -SIMDE_FLOAT16_C(    29.036),  SIMDE_FLOAT16_C(     5.538),  SIMDE_FLOAT16_C(    23.680) },
         INT8_C(         4),
      { -SIMDE_FLOAT32_C(   281.171),  SIMDE_FLOAT32_C(   901.110) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t buf = simde_vld1_f32(test_vec[i].buf);
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x2_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_8_(simde_vfmlsl_laneq_high_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlslq_lane_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[4];
    int8_t lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(   866.865), -SIMDE_FLOAT32_C(   471.987),  SIMDE_FLOAT32_C(    12.503), -SIMDE_FLOAT32_C(   364.707) },
      {  SIMDE_FLOAT16_C(     6.369), -SIMDE_FLOAT16_C(    22.801), -SIMDE_FLOAT16_C(     1.625),  SIMDE_FLOAT16_C(    25.289),
        -SIMDE_FLOAT16_C(    12.938),  SIMDE_FLOAT16_C(    18.278), -SIMDE_FLOAT16_C(    25.899),  SIMDE_FLOAT16_C(     9.801) },
      { -SIMDE_FLOAT16_C(    15.642), -SIMDE_FLOAT16_C(    13.357), -SIMDE_FLOAT16_C(    22.406),  SIMDE_FLOAT16_C(    21.218) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(   694.052), -SIMDE_FLOAT32_C(   227.848), -SIMDE_FLOAT32_C(   333.588), -SIMDE_FLOAT32_C(   233.795) } },
    { { -SIMDE_FLOAT32_C(    92.695),  SIMDE_FLOAT32_C(   706.658), -SIMDE_FLOAT32_C(   869.624), -SIMDE_FLOAT32_C(   138.274) },
      { -SIMDE_FLOAT16_C(    17.690), -SIMDE_FLOAT16_C(    10.999), -SIMDE_FLOAT16_C(     9.695),  SIMDE_FLOAT16_C(     8.812),
         SIMDE_FLOAT16_C(    19.423),  SIMDE_FLOAT16_C(    12.329), -SIMDE_FLOAT16_C(     3.420),  SIMDE_FLOAT16_C(     2.211) },
      { -SIMDE_FLOAT16_C(     4.842), -SIMDE_FLOAT16_C(    18.795), -SIMDE_FLOAT16_C(    20.012),  SIMDE_FLOAT16_C(    23.256) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   544.253),  SIMDE_FLOAT32_C(   419.935), -SIMDE_FLOAT32_C(   790.089), -SIMDE_FLOAT32_C(   189.693) } },
    { {  SIMDE_FLOAT32_C(   524.109),  SIMDE_FLOAT32_C(   424.012), -SIMDE_FLOAT32_C(   460.499), -SIMDE_FLOAT32_C(   226.537) },
      {  SIMDE_FLOAT16_C(    26.158), -SIMDE_FLOAT16_C(    24.828), -SIMDE_FLOAT16_C(     1.435),  SIMDE_FLOAT16_C(    23.361),
         SIMDE_FLOAT16_C(    19.803), -SIMDE_FLOAT16_C(    12.485),  SIMDE_FLOAT16_C(    28.470), -SIMDE_FLOAT16_C(    12.102) },
      { -SIMDE_FLOAT16_C(     6.093), -SIMDE_FLOAT16_C(     5.638),  SIMDE_FLOAT16_C(     6.478),  SIMDE_FLOAT16_C(    26.029) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(   635.758),  SIMDE_FLOAT32_C(   353.622), -SIMDE_FLOAT32_C(   299.985), -SIMDE_FLOAT32_C(   294.768) } },
    { { -SIMDE_FLOAT32_C(   121.897), -SIMDE_FLOAT32_C(   632.267), -SIMDE_FLOAT32_C(   354.689),  SIMDE_FLOAT32_C(   615.061) },
      { -SIMDE_FLOAT16_C(    22.811),  SIMDE_FLOAT16_C(    18.913), -SIMDE_FLOAT16_C(    23.933),  SIMDE_FLOAT16_C(     4.098),
        -SIMDE_FLOAT16_C(    26.679),  SIMDE_FLOAT16_C(    12.345),  SIMDE_FLOAT16_C(     2.940), -SIMDE_FLOAT16_C(    12.072) },
      { -SIMDE_FLOAT16_C(     1.871), -SIMDE_FLOAT16_C(    28.898),  SIMDE_FLOAT16_C(    20.923), -SIMDE_FLOAT16_C(    13.465) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   481.130), -SIMDE_FLOAT32_C(   466.042), -SIMDE_FLOAT32_C(   315.102),  SIMDE_FLOAT32_C(   452.512) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
    simde_float32x4_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_4_(simde_vfmlslq_lane_high_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vfmlslq_laneq_high_f16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32_t buf[4];
    simde_float16_t a[8];
    simde_float16_t b[8];
    int8_t lane;
    simde_float32_t r[4];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   270.422),  SIMDE_FLOAT32_C(   273.685),  SIMDE_FLOAT32_C(   604.366), -SIMDE_FLOAT32_C(   216.222) },
      {  SIMDE_FLOAT16_C(    17.262), -SIMDE_FLOAT16_C(     7.295), -SIMDE_FLOAT16_C(    29.721),  SIMDE_FLOAT16_C(    13.279),
        -SIMDE_FLOAT16_C(    23.684),  SIMDE_FLOAT16_C(    16.574),  SIMDE_FLOAT16_C(    16.180), -SIMDE_FLOAT16_C(    18.536) },
      { -SIMDE_FLOAT16_C(    21.196),  SIMDE_FLOAT16_C(    29.439),  SIMDE_FLOAT16_C(    25.478), -SIMDE_FLOAT16_C(    10.691),
         SIMDE_FLOAT16_C(    20.611),  SIMDE_FLOAT16_C(    27.592),  SIMDE_FLOAT16_C(    20.478), -SIMDE_FLOAT16_C(    23.149) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(   426.811), -SIMDE_FLOAT32_C(   214.237),  SIMDE_FLOAT32_C(   127.846),  SIMDE_FLOAT32_C(   329.291) } },
    { { -SIMDE_FLOAT32_C(   115.549), -SIMDE_FLOAT32_C(   943.670), -SIMDE_FLOAT32_C(   276.746),  SIMDE_FLOAT32_C(   590.228) },
      {  SIMDE_FLOAT16_C(    18.945), -SIMDE_FLOAT16_C(    16.360),  SIMDE_FLOAT16_C(     0.647), -SIMDE_FLOAT16_C(     5.027),
        -SIMDE_FLOAT16_C(    12.857), -SIMDE_FLOAT16_C(    27.973),  SIMDE_FLOAT16_C(    24.786), -SIMDE_FLOAT16_C(     7.098) },
      {  SIMDE_FLOAT16_C(    25.675),  SIMDE_FLOAT16_C(     0.374),  SIMDE_FLOAT16_C(    20.933),  SIMDE_FLOAT16_C(    19.328),
        -SIMDE_FLOAT16_C(    24.124), -SIMDE_FLOAT16_C(     7.863),  SIMDE_FLOAT16_C(    23.346),  SIMDE_FLOAT16_C(    19.162) },
         INT8_C(         6),
      {  SIMDE_FLOAT32_C(   184.611), -SIMDE_FLOAT32_C(   290.774), -SIMDE_FLOAT32_C(   855.233),  SIMDE_FLOAT32_C(   755.938) } },
    { {  SIMDE_FLOAT32_C(    32.257),  SIMDE_FLOAT32_C(   444.171),  SIMDE_FLOAT32_C(   878.202), -SIMDE_FLOAT32_C(   746.626) },
      { -SIMDE_FLOAT16_C(     2.690), -SIMDE_FLOAT16_C(    17.177),  SIMDE_FLOAT16_C(     7.493),  SIMDE_FLOAT16_C(     4.461),
         SIMDE_FLOAT16_C(    28.040),  SIMDE_FLOAT16_C(    25.885), -SIMDE_FLOAT16_C(     9.049), -SIMDE_FLOAT16_C(    23.323) },
      {  SIMDE_FLOAT16_C(    15.158), -SIMDE_FLOAT16_C(    17.498), -SIMDE_FLOAT16_C(    13.383),  SIMDE_FLOAT16_C(    12.508),
         SIMDE_FLOAT16_C(    18.691), -SIMDE_FLOAT16_C(    26.689),  SIMDE_FLOAT16_C(    26.057), -SIMDE_FLOAT16_C(    22.413) },
         INT8_C(         3),
      { -SIMDE_FLOAT32_C(   318.467),  SIMDE_FLOAT32_C(   120.401),  SIMDE_FLOAT32_C(   991.387), -SIMDE_FLOAT32_C(   454.902) } },
    { { -SIMDE_FLOAT32_C(   679.208),  SIMDE_FLOAT32_C(    19.921),  SIMDE_FLOAT32_C(   478.808), -SIMDE_FLOAT32_C(   484.372) },
      {  SIMDE_FLOAT16_C(    27.815), -SIMDE_FLOAT16_C(    20.693), -SIMDE_FLOAT16_C(    13.554),  SIMDE_FLOAT16_C(    14.889),
        -SIMDE_FLOAT16_C(    29.097), -SIMDE_FLOAT16_C(     0.981),  SIMDE_FLOAT16_C(    14.219), -SIMDE_FLOAT16_C(     8.002) },
      { -SIMDE_FLOAT16_C(     8.018),  SIMDE_FLOAT16_C(    25.930),  SIMDE_FLOAT16_C(    10.803),  SIMDE_FLOAT16_C(    24.380),
        -SIMDE_FLOAT16_C(     1.764), -SIMDE_FLOAT16_C(    16.756), -SIMDE_FLOAT16_C(     1.235),  SIMDE_FLOAT16_C(     5.219) },
         INT8_C(         1),
      {  SIMDE_FLOAT32_C(    75.411),  SIMDE_FLOAT32_C(    45.358),  SIMDE_FLOAT32_C(   110.109), -SIMDE_FLOAT32_C(   276.880) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float32x4_t r;
    int lane = test_vec[i].lane;
    SIMDE_CONSTIFY_8_(simde_vfmlslq_laneq_high_f16, r, (HEDLEY_UNREACHABLE(), r), lane, buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlsl_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlsl_high_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmlslq_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlslq_high_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmlsl_lane_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlsl_lane_high_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmlsl_laneq_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlsl_laneq_high_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmlslq_lane_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlslq_lane_high_f16)

SIMDE_TEST_FUNC_LIST_ENTRY(vfmlslq_laneq_low_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vfmlslq_laneq_high_f16)

SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
