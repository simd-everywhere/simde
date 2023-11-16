#define SIMDE_TEST_ARM_NEON_INSN mulx

#include "test-neon.h"
#include "../../../simde/arm/neon/mulx.h"

static int
test_simde_vmulxh_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a;
    simde_float16 b;
    simde_float16 r;
  } test_vec[] = {
    {    SIMDE_FLOAT16_VALUE(      12.121),
         SIMDE_FLOAT16_VALUE(     -10.345),
         SIMDE_FLOAT16_VALUE(    -125.392) },
    {    SIMDE_FLOAT16_VALUE(       2.046),
         SIMDE_FLOAT16_VALUE(     -12.841),
         SIMDE_FLOAT16_VALUE(     -26.273) },
    {    SIMDE_FLOAT16_VALUE(     -15.182),
         SIMDE_FLOAT16_VALUE(      13.387),
         SIMDE_FLOAT16_VALUE(    -203.241) },
    {    SIMDE_FLOAT16_VALUE(     -13.502),
         SIMDE_FLOAT16_VALUE(      14.474),
         SIMDE_FLOAT16_VALUE(    -195.428) },
    {    SIMDE_FLOAT16_VALUE(       2.788),
         SIMDE_FLOAT16_VALUE(     -16.350),
         SIMDE_FLOAT16_VALUE(     -45.584) },
    {    SIMDE_FLOAT16_VALUE(       3.122),
         SIMDE_FLOAT16_VALUE(     -28.460),
         SIMDE_FLOAT16_VALUE(     -88.852) },
    {    SIMDE_FLOAT16_VALUE(     -12.098),
         SIMDE_FLOAT16_VALUE(       4.041),
         SIMDE_FLOAT16_VALUE(     -48.888) },
    {    SIMDE_FLOAT16_VALUE(      -6.972),
         SIMDE_FLOAT16_VALUE(      -0.271),
         SIMDE_FLOAT16_VALUE(       1.889) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16 r = simde_vmulxh_f16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16_t a = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t b = simde_test_codegen_random_f16(-100.0f, 100.0f);
    simde_float16_t r = simde_vmulxh_f16(a, b);

    simde_test_codegen_write_f16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxs_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a;
    simde_float32 b;
    simde_float32 r;
  } test_vec[] = {
    {    SIMDE_FLOAT32_C(     517.954),
        -SIMDE_FLOAT32_C(     461.836),
        -SIMDE_FLOAT32_C(  239209.804) },
    {   -SIMDE_FLOAT32_C(     527.208),
         SIMDE_FLOAT32_C(     422.783),
        -SIMDE_FLOAT32_C(  222894.580) },
    {    SIMDE_FLOAT32_C(     394.340),
         SIMDE_FLOAT32_C(     651.680),
         SIMDE_FLOAT32_C(  256983.491) },
    {    SIMDE_FLOAT32_C(     891.669),
         SIMDE_FLOAT32_C(     986.632),
         SIMDE_FLOAT32_C(  879749.169) },
    {    SIMDE_FLOAT32_C(     160.048),
        -SIMDE_FLOAT32_C(      42.337),
        -SIMDE_FLOAT32_C(    6775.952) },
    {   -SIMDE_FLOAT32_C(      20.358),
         SIMDE_FLOAT32_C(     877.549),
        -SIMDE_FLOAT32_C(   17865.143) },
    {   -SIMDE_FLOAT32_C(     667.814),
        -SIMDE_FLOAT32_C(      79.721),
         SIMDE_FLOAT32_C(   53238.800) },
    {    SIMDE_FLOAT32_C(     621.314),
         SIMDE_FLOAT32_C(     214.636),
         SIMDE_FLOAT32_C(  133356.352) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32 r = simde_vmulxs_f32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t b = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vmulxs_f32(a, b);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a;
    simde_float64 b;
    simde_float64 r;
  } test_vec[] = {
    {    SIMDE_FLOAT64_C(      54212.125),
        -SIMDE_FLOAT64_C(      36874.348),
        -SIMDE_FLOAT64_C( 1999036763.069) },
    {    SIMDE_FLOAT64_C(      18475.828),
        -SIMDE_FLOAT64_C(      83495.586),
        -SIMDE_FLOAT64_C( 1542650085.695) },
    {   -SIMDE_FLOAT64_C(      32044.766),
        -SIMDE_FLOAT64_C(      90285.922),
         SIMDE_FLOAT64_C( 2893191243.584) },
    {    SIMDE_FLOAT64_C(      51040.563),
        -SIMDE_FLOAT64_C(      48550.875),
        -SIMDE_FLOAT64_C( 2478063994.143) },
    {    SIMDE_FLOAT64_C(      38281.031),
        -SIMDE_FLOAT64_C(      47330.313),
        -SIMDE_FLOAT64_C( 1811853179.193) },
    {   -SIMDE_FLOAT64_C(      62916.809),
        -SIMDE_FLOAT64_C(      77798.664),
         SIMDE_FLOAT64_C( 4894843683.343) },
    {    SIMDE_FLOAT64_C(      63107.313),
        -SIMDE_FLOAT64_C(      86359.633),
        -SIMDE_FLOAT64_C( 5449924390.296) },
    {    SIMDE_FLOAT64_C(      94473.344),
        -SIMDE_FLOAT64_C(      81516.984),
        -SIMDE_FLOAT64_C( 7701182071.274) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64 r = simde_vmulxd_f64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64_t b = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64_t r = simde_vmulxd_f64(a, b);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulx_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[4];
    simde_float16 b[4];
    simde_float16 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(  11.884),  SIMDE_FLOAT16_VALUE( -12.117),  SIMDE_FLOAT16_VALUE(  -4.469),  SIMDE_FLOAT16_VALUE(  -3.678) },
      {  SIMDE_FLOAT16_VALUE(  -7.801),  SIMDE_FLOAT16_VALUE(  -6.994),  SIMDE_FLOAT16_VALUE(  12.408),  SIMDE_FLOAT16_VALUE( -10.779) },
      {  SIMDE_FLOAT16_VALUE( -92.707),  SIMDE_FLOAT16_VALUE(  84.746),  SIMDE_FLOAT16_VALUE( -55.451),  SIMDE_FLOAT16_VALUE(  39.645) } },
    { {  SIMDE_FLOAT16_VALUE(  -4.989),  SIMDE_FLOAT16_VALUE(   8.946),  SIMDE_FLOAT16_VALUE(  -9.959),  SIMDE_FLOAT16_VALUE(   6.504) },
      {  SIMDE_FLOAT16_VALUE(  14.524),  SIMDE_FLOAT16_VALUE(  10.306),  SIMDE_FLOAT16_VALUE(   3.340),  SIMDE_FLOAT16_VALUE(   6.852) },
      {  SIMDE_FLOAT16_VALUE( -72.460),  SIMDE_FLOAT16_VALUE(  92.197),  SIMDE_FLOAT16_VALUE( -33.263),  SIMDE_FLOAT16_VALUE(  44.565) } },
    { {  SIMDE_FLOAT16_VALUE(  -3.851),  SIMDE_FLOAT16_VALUE(  -4.284),  SIMDE_FLOAT16_VALUE(  -4.962),  SIMDE_FLOAT16_VALUE( -11.512) },
      {  SIMDE_FLOAT16_VALUE( -11.588),  SIMDE_FLOAT16_VALUE(   2.430),  SIMDE_FLOAT16_VALUE( -11.397),  SIMDE_FLOAT16_VALUE( -10.014) },
      {  SIMDE_FLOAT16_VALUE(  44.625),  SIMDE_FLOAT16_VALUE( -10.410),  SIMDE_FLOAT16_VALUE(  56.552),  SIMDE_FLOAT16_VALUE( 115.281) } },
    { {  SIMDE_FLOAT16_VALUE(  12.957),  SIMDE_FLOAT16_VALUE(   1.372),  SIMDE_FLOAT16_VALUE(   0.880),  SIMDE_FLOAT16_VALUE(  11.068) },
      {  SIMDE_FLOAT16_VALUE(  -8.646),  SIMDE_FLOAT16_VALUE(   1.274),  SIMDE_FLOAT16_VALUE(  -4.545),  SIMDE_FLOAT16_VALUE( -14.868) },
      {  SIMDE_FLOAT16_VALUE(-112.026),  SIMDE_FLOAT16_VALUE(   1.748),  SIMDE_FLOAT16_VALUE(  -4.000),  SIMDE_FLOAT16_VALUE(-164.650) } },
    { {  SIMDE_FLOAT16_VALUE( -12.078),  SIMDE_FLOAT16_VALUE(  11.549),  SIMDE_FLOAT16_VALUE(   5.313),  SIMDE_FLOAT16_VALUE(  -8.893) },
      {  SIMDE_FLOAT16_VALUE(  -8.061),  SIMDE_FLOAT16_VALUE(   3.262),  SIMDE_FLOAT16_VALUE(   7.153),  SIMDE_FLOAT16_VALUE(  -2.053) },
      {  SIMDE_FLOAT16_VALUE(  97.361),  SIMDE_FLOAT16_VALUE(  37.673),  SIMDE_FLOAT16_VALUE(  38.004),  SIMDE_FLOAT16_VALUE(  18.257) } },
    { {  SIMDE_FLOAT16_VALUE(   6.445),  SIMDE_FLOAT16_VALUE(  -2.210),  SIMDE_FLOAT16_VALUE(   0.604),  SIMDE_FLOAT16_VALUE(  -5.514) },
      {  SIMDE_FLOAT16_VALUE(   0.727),  SIMDE_FLOAT16_VALUE(  -4.909),  SIMDE_FLOAT16_VALUE(   1.339),  SIMDE_FLOAT16_VALUE(   5.500) },
      {  SIMDE_FLOAT16_VALUE(   4.686),  SIMDE_FLOAT16_VALUE(  10.849),  SIMDE_FLOAT16_VALUE(   0.809),  SIMDE_FLOAT16_VALUE( -30.327) } },
    { {  SIMDE_FLOAT16_VALUE(   9.710),  SIMDE_FLOAT16_VALUE( -13.103),  SIMDE_FLOAT16_VALUE(  14.405),  SIMDE_FLOAT16_VALUE(  -4.243) },
      {  SIMDE_FLOAT16_VALUE(   9.862),  SIMDE_FLOAT16_VALUE(   6.144),  SIMDE_FLOAT16_VALUE(  -4.625),  SIMDE_FLOAT16_VALUE(  13.226) },
      {  SIMDE_FLOAT16_VALUE(  95.760),  SIMDE_FLOAT16_VALUE( -80.505),  SIMDE_FLOAT16_VALUE( -66.623),  SIMDE_FLOAT16_VALUE( -56.118) } },
    { {  SIMDE_FLOAT16_VALUE(  -0.018),  SIMDE_FLOAT16_VALUE(   5.611),  SIMDE_FLOAT16_VALUE(   5.991),  SIMDE_FLOAT16_VALUE(   9.121) },
      {  SIMDE_FLOAT16_VALUE( -10.315),  SIMDE_FLOAT16_VALUE(  -5.140),  SIMDE_FLOAT16_VALUE(   8.418),  SIMDE_FLOAT16_VALUE(  13.944) },
      {  SIMDE_FLOAT16_VALUE(   0.186),  SIMDE_FLOAT16_VALUE( -28.841),  SIMDE_FLOAT16_VALUE(  50.432),  SIMDE_FLOAT16_VALUE( 127.183) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a, b, r;

    a = simde_vld1_f16(test_vec[i].a);
    b = simde_vld1_f16(test_vec[i].b);
    r = simde_vmulx_f16(a, b);

    simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16x4_t r = simde_vmulx_f16(a, b);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulx_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(     313.560), -SIMDE_FLOAT32_C(     634.469) },
      { -SIMDE_FLOAT32_C(     534.696),  SIMDE_FLOAT32_C(     444.618) },
      {  SIMDE_FLOAT32_C(  167659.278), -SIMDE_FLOAT32_C(  282096.338) } },
    { {  SIMDE_FLOAT32_C(     557.635),  SIMDE_FLOAT32_C(     924.146) },
      { -SIMDE_FLOAT32_C(     116.142),  SIMDE_FLOAT32_C(     102.470) },
      { -SIMDE_FLOAT32_C(   64764.844),  SIMDE_FLOAT32_C(   94697.241) } },
    { {  SIMDE_FLOAT32_C(     719.755), -SIMDE_FLOAT32_C(     801.683) },
      { -SIMDE_FLOAT32_C(     686.644),  SIMDE_FLOAT32_C(     262.645) },
      { -SIMDE_FLOAT32_C(  494215.452), -SIMDE_FLOAT32_C(  210558.032) } },
    { {  SIMDE_FLOAT32_C(     720.080), -SIMDE_FLOAT32_C(      18.857) },
      { -SIMDE_FLOAT32_C(     732.646),  SIMDE_FLOAT32_C(      89.380) },
      { -SIMDE_FLOAT32_C(  527563.732), -SIMDE_FLOAT32_C(    1685.439) } },
    { { -SIMDE_FLOAT32_C(     264.925),  SIMDE_FLOAT32_C(     623.848) },
      {  SIMDE_FLOAT32_C(      89.740), -SIMDE_FLOAT32_C(     916.634) },
      { -SIMDE_FLOAT32_C(   23774.370), -SIMDE_FLOAT32_C(  571840.288) } },
    { { -SIMDE_FLOAT32_C(     661.887), -SIMDE_FLOAT32_C(     853.841) },
      {  SIMDE_FLOAT32_C(     944.831),  SIMDE_FLOAT32_C(     605.152) },
      { -SIMDE_FLOAT32_C(  625371.356), -SIMDE_FLOAT32_C(  516703.589) } },
    { {  SIMDE_FLOAT32_C(     243.668),  SIMDE_FLOAT32_C(     356.235) },
      {  SIMDE_FLOAT32_C(     712.957), -SIMDE_FLOAT32_C(     771.234) },
      {  SIMDE_FLOAT32_C(  173724.806), -SIMDE_FLOAT32_C(  274740.544) } },
    { { -SIMDE_FLOAT32_C(      28.547), -SIMDE_FLOAT32_C(     747.611) },
      {  SIMDE_FLOAT32_C(     794.050), -SIMDE_FLOAT32_C(      25.450) },
      { -SIMDE_FLOAT32_C(   22667.745),  SIMDE_FLOAT32_C(   19026.700) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, b, r;

    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    r = simde_vmulx_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vmulx_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulx_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { -SIMDE_FLOAT64_C(      97980.508) },
      { -SIMDE_FLOAT64_C(      80725.578) },
      {  SIMDE_FLOAT64_C( 7909533141.034) } },
    { { -SIMDE_FLOAT64_C(      49760.543) },
      {  SIMDE_FLOAT64_C(      31517.891) },
      { -SIMDE_FLOAT64_C( 1568347370.375) } },
    { {  SIMDE_FLOAT64_C(      66796.547) },
      { -SIMDE_FLOAT64_C(      95560.875) },
      { -SIMDE_FLOAT64_C( 6383136478.299) } },
    { {  SIMDE_FLOAT64_C(      16581.633) },
      {  SIMDE_FLOAT64_C(      63304.609) },
      {  SIMDE_FLOAT64_C( 1049693793.646) } },
    { {  SIMDE_FLOAT64_C(      36030.578) },
      { -SIMDE_FLOAT64_C(       9645.219) },
      { -SIMDE_FLOAT64_C(  347522815.507) } },
    { {  SIMDE_FLOAT64_C(      62685.094) },
      {  SIMDE_FLOAT64_C(      10381.945) },
      {  SIMDE_FLOAT64_C(  650793198.228) } },
    { { -SIMDE_FLOAT64_C(      96693.703) },
      {  SIMDE_FLOAT64_C(      78016.234) },
      { -SIMDE_FLOAT64_C( 7543678559.575) } },
    { {  SIMDE_FLOAT64_C(      53650.094) },
      {  SIMDE_FLOAT64_C(      23647.594) },
      {  SIMDE_FLOAT64_C( 1268695640.974) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t r = simde_vmulx_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x1_t r = simde_vmulx_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16 a[8];
    simde_float16 b[8];
    simde_float16 r[8];
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(   0.818),  SIMDE_FLOAT16_VALUE(  12.583),  SIMDE_FLOAT16_VALUE(   2.255),  SIMDE_FLOAT16_VALUE(   1.948),
         SIMDE_FLOAT16_VALUE(   1.614),  SIMDE_FLOAT16_VALUE(   2.633),  SIMDE_FLOAT16_VALUE(  -5.124),  SIMDE_FLOAT16_VALUE( -13.340) },
      {  SIMDE_FLOAT16_VALUE(  -2.767),  SIMDE_FLOAT16_VALUE( -11.911),  SIMDE_FLOAT16_VALUE(  14.884),  SIMDE_FLOAT16_VALUE(  -4.149),
         SIMDE_FLOAT16_VALUE(  -6.114),  SIMDE_FLOAT16_VALUE(   6.690),  SIMDE_FLOAT16_VALUE(  13.414),  SIMDE_FLOAT16_VALUE(   8.851) },
      {  SIMDE_FLOAT16_VALUE(  -2.263),  SIMDE_FLOAT16_VALUE(-150.000),  SIMDE_FLOAT16_VALUE(  33.563),  SIMDE_FLOAT16_VALUE(  -8.082),
         SIMDE_FLOAT16_VALUE(  -9.868),  SIMDE_FLOAT16_VALUE(  17.615),  SIMDE_FLOAT16_VALUE( -68.733),  SIMDE_FLOAT16_VALUE(-118.072) } },
    { {  SIMDE_FLOAT16_VALUE(   9.919),  SIMDE_FLOAT16_VALUE(   5.810),  SIMDE_FLOAT16_VALUE(   6.655),  SIMDE_FLOAT16_VALUE(  -6.660),
         SIMDE_FLOAT16_VALUE(  -2.737),  SIMDE_FLOAT16_VALUE(   9.028),  SIMDE_FLOAT16_VALUE(  -4.465),  SIMDE_FLOAT16_VALUE(   3.449) },
      {  SIMDE_FLOAT16_VALUE(   2.092),  SIMDE_FLOAT16_VALUE(  10.711),  SIMDE_FLOAT16_VALUE(  12.038),  SIMDE_FLOAT16_VALUE(  -8.015),
         SIMDE_FLOAT16_VALUE(   0.549),  SIMDE_FLOAT16_VALUE(  -0.735),  SIMDE_FLOAT16_VALUE(  -5.604),  SIMDE_FLOAT16_VALUE( -13.525) },
      {  SIMDE_FLOAT16_VALUE(  20.751),  SIMDE_FLOAT16_VALUE(  62.231),  SIMDE_FLOAT16_VALUE(  80.113),  SIMDE_FLOAT16_VALUE(  53.380),
         SIMDE_FLOAT16_VALUE(  -1.503),  SIMDE_FLOAT16_VALUE(  -6.636),  SIMDE_FLOAT16_VALUE(  25.022),  SIMDE_FLOAT16_VALUE( -46.648) } },
    { {  SIMDE_FLOAT16_VALUE(   2.914),  SIMDE_FLOAT16_VALUE( -10.256),  SIMDE_FLOAT16_VALUE(  13.016),  SIMDE_FLOAT16_VALUE(  14.909),
         SIMDE_FLOAT16_VALUE(  -9.884),  SIMDE_FLOAT16_VALUE(  -7.674),  SIMDE_FLOAT16_VALUE(   5.650),  SIMDE_FLOAT16_VALUE(  14.896) },
      {  SIMDE_FLOAT16_VALUE(  13.592),  SIMDE_FLOAT16_VALUE(  -8.769),  SIMDE_FLOAT16_VALUE( -13.596),  SIMDE_FLOAT16_VALUE(  10.636),
         SIMDE_FLOAT16_VALUE(  -4.322),  SIMDE_FLOAT16_VALUE( -14.667),  SIMDE_FLOAT16_VALUE( -11.936),  SIMDE_FLOAT16_VALUE(   6.353) },
      {  SIMDE_FLOAT16_VALUE(  39.607),  SIMDE_FLOAT16_VALUE(  89.935),  SIMDE_FLOAT16_VALUE(-176.875),  SIMDE_FLOAT16_VALUE( 158.500),
         SIMDE_FLOAT16_VALUE(  42.719),  SIMDE_FLOAT16_VALUE( 112.555),  SIMDE_FLOAT16_VALUE( -67.438),  SIMDE_FLOAT16_VALUE(  94.634) } },
    { {  SIMDE_FLOAT16_VALUE( -14.335),  SIMDE_FLOAT16_VALUE(  -0.489),  SIMDE_FLOAT16_VALUE(  14.410),  SIMDE_FLOAT16_VALUE(  12.424),
         SIMDE_FLOAT16_VALUE(  13.209),  SIMDE_FLOAT16_VALUE(  -4.835),  SIMDE_FLOAT16_VALUE( -12.749),  SIMDE_FLOAT16_VALUE(   9.087) },
      {  SIMDE_FLOAT16_VALUE( -14.724),  SIMDE_FLOAT16_VALUE(  12.785),  SIMDE_FLOAT16_VALUE( -13.619),  SIMDE_FLOAT16_VALUE(  -3.702),
         SIMDE_FLOAT16_VALUE(  -5.130),  SIMDE_FLOAT16_VALUE(  -7.200),  SIMDE_FLOAT16_VALUE(  -3.170),  SIMDE_FLOAT16_VALUE( -12.809) },
      {  SIMDE_FLOAT16_VALUE( 211.069),  SIMDE_FLOAT16_VALUE(  -6.252),  SIMDE_FLOAT16_VALUE(-196.125),  SIMDE_FLOAT16_VALUE( -45.994),
         SIMDE_FLOAT16_VALUE( -67.762),  SIMDE_FLOAT16_VALUE(  34.812),  SIMDE_FLOAT16_VALUE(  40.414),  SIMDE_FLOAT16_VALUE(-116.395) } },
    { {  SIMDE_FLOAT16_VALUE(  13.181),  SIMDE_FLOAT16_VALUE(  13.543),  SIMDE_FLOAT16_VALUE(  13.333),  SIMDE_FLOAT16_VALUE(  -6.331),
         SIMDE_FLOAT16_VALUE(   4.540),  SIMDE_FLOAT16_VALUE( -10.557),  SIMDE_FLOAT16_VALUE(  10.807),  SIMDE_FLOAT16_VALUE(   5.947) },
      {  SIMDE_FLOAT16_VALUE( -13.643),  SIMDE_FLOAT16_VALUE(  -2.075),  SIMDE_FLOAT16_VALUE(   7.184),  SIMDE_FLOAT16_VALUE(  -4.202),
         SIMDE_FLOAT16_VALUE(  -0.541),  SIMDE_FLOAT16_VALUE(   0.728),  SIMDE_FLOAT16_VALUE(   4.217),  SIMDE_FLOAT16_VALUE(  10.131) },
      {  SIMDE_FLOAT16_VALUE(-179.750),  SIMDE_FLOAT16_VALUE( -28.102),  SIMDE_FLOAT16_VALUE(  95.784),  SIMDE_FLOAT16_VALUE(  26.603),
         SIMDE_FLOAT16_VALUE(  -2.456),  SIMDE_FLOAT16_VALUE(  -7.685),  SIMDE_FLOAT16_VALUE(  45.573),  SIMDE_FLOAT16_VALUE(  60.249) } },
    { {  SIMDE_FLOAT16_VALUE(  -6.567),  SIMDE_FLOAT16_VALUE(  -9.550),  SIMDE_FLOAT16_VALUE(   0.753),  SIMDE_FLOAT16_VALUE(   6.529),
         SIMDE_FLOAT16_VALUE(  10.369),  SIMDE_FLOAT16_VALUE(   4.970),  SIMDE_FLOAT16_VALUE(  14.205),  SIMDE_FLOAT16_VALUE(  11.933) },
      {  SIMDE_FLOAT16_VALUE( -12.415),  SIMDE_FLOAT16_VALUE(  12.896),  SIMDE_FLOAT16_VALUE(   4.421),  SIMDE_FLOAT16_VALUE(  13.922),
         SIMDE_FLOAT16_VALUE( -12.445),  SIMDE_FLOAT16_VALUE(  -2.663),  SIMDE_FLOAT16_VALUE(   7.585),  SIMDE_FLOAT16_VALUE(   9.726) },
      {  SIMDE_FLOAT16_VALUE(  81.529),  SIMDE_FLOAT16_VALUE(-123.157),  SIMDE_FLOAT16_VALUE(   3.329),  SIMDE_FLOAT16_VALUE(  90.897),
         SIMDE_FLOAT16_VALUE(-129.042),  SIMDE_FLOAT16_VALUE( -13.235),  SIMDE_FLOAT16_VALUE( 107.745),  SIMDE_FLOAT16_VALUE( 116.060) } },
    { {  SIMDE_FLOAT16_VALUE(  -6.489),  SIMDE_FLOAT16_VALUE(  10.432),  SIMDE_FLOAT16_VALUE(   5.392),  SIMDE_FLOAT16_VALUE(  -9.475),
         SIMDE_FLOAT16_VALUE(   5.624),  SIMDE_FLOAT16_VALUE(  13.628),  SIMDE_FLOAT16_VALUE(  -3.195),  SIMDE_FLOAT16_VALUE(   5.403) },
      {  SIMDE_FLOAT16_VALUE(  -5.621),  SIMDE_FLOAT16_VALUE(  -0.470),  SIMDE_FLOAT16_VALUE(   3.713),  SIMDE_FLOAT16_VALUE(  -3.216),
         SIMDE_FLOAT16_VALUE(   7.516),  SIMDE_FLOAT16_VALUE(   3.058),  SIMDE_FLOAT16_VALUE(   5.566),  SIMDE_FLOAT16_VALUE(  -7.336) },
      {  SIMDE_FLOAT16_VALUE(  36.475),  SIMDE_FLOAT16_VALUE(  -4.903),  SIMDE_FLOAT16_VALUE(  20.020),  SIMDE_FLOAT16_VALUE(  30.472),
         SIMDE_FLOAT16_VALUE(  42.270),  SIMDE_FLOAT16_VALUE(  41.674),  SIMDE_FLOAT16_VALUE( -17.783),  SIMDE_FLOAT16_VALUE( -39.636) } },
    { {  SIMDE_FLOAT16_VALUE(  12.245),  SIMDE_FLOAT16_VALUE(  -0.428),  SIMDE_FLOAT16_VALUE( -10.456),  SIMDE_FLOAT16_VALUE(   4.327),
         SIMDE_FLOAT16_VALUE(   5.673),  SIMDE_FLOAT16_VALUE(  -9.628),  SIMDE_FLOAT16_VALUE(   5.260),  SIMDE_FLOAT16_VALUE(  10.089) },
      {  SIMDE_FLOAT16_VALUE(  11.177),  SIMDE_FLOAT16_VALUE(   3.546),  SIMDE_FLOAT16_VALUE(  -3.457),  SIMDE_FLOAT16_VALUE(  10.459),
         SIMDE_FLOAT16_VALUE(   2.200),  SIMDE_FLOAT16_VALUE(  -1.955),  SIMDE_FLOAT16_VALUE(  -3.125),  SIMDE_FLOAT16_VALUE(   9.213) },
      {  SIMDE_FLOAT16_VALUE( 136.862),  SIMDE_FLOAT16_VALUE(  -1.518),  SIMDE_FLOAT16_VALUE(  36.146),  SIMDE_FLOAT16_VALUE(  45.256),
         SIMDE_FLOAT16_VALUE(  12.481),  SIMDE_FLOAT16_VALUE(  18.823),  SIMDE_FLOAT16_VALUE( -16.438),  SIMDE_FLOAT16_VALUE(  92.950) } },
  };


  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t r = simde_vmulxq_f16(a, b);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t b = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16x8_t r = simde_vmulxq_f16(a, b);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {
    { {  SIMDE_FLOAT32_C(     640.584),  SIMDE_FLOAT32_C(     560.701), -SIMDE_FLOAT32_C(     500.199), -SIMDE_FLOAT32_C(     781.918) },
      {  SIMDE_FLOAT32_C(     127.154),  SIMDE_FLOAT32_C(      35.278), -SIMDE_FLOAT32_C(     309.011), -SIMDE_FLOAT32_C(     387.073) },
      {  SIMDE_FLOAT32_C(   81452.818),  SIMDE_FLOAT32_C(   19780.410),  SIMDE_FLOAT32_C(  154566.993),  SIMDE_FLOAT32_C(  302659.346) } },
    { { -SIMDE_FLOAT32_C(     801.865),  SIMDE_FLOAT32_C(     164.911),  SIMDE_FLOAT32_C(     598.834),  SIMDE_FLOAT32_C(     359.108) },
      { -SIMDE_FLOAT32_C(     517.386), -SIMDE_FLOAT32_C(     212.299),  SIMDE_FLOAT32_C(      10.791), -SIMDE_FLOAT32_C(     526.615) },
      {  SIMDE_FLOAT32_C(  414873.725), -SIMDE_FLOAT32_C(   35010.440),  SIMDE_FLOAT32_C(    6462.018), -SIMDE_FLOAT32_C(  189111.659) } },
    { { -SIMDE_FLOAT32_C(     178.763), -SIMDE_FLOAT32_C(     339.896), -SIMDE_FLOAT32_C(     344.376),  SIMDE_FLOAT32_C(     397.251) },
      { -SIMDE_FLOAT32_C(     277.837),  SIMDE_FLOAT32_C(      31.132),  SIMDE_FLOAT32_C(     792.617), -SIMDE_FLOAT32_C(     703.708) },
      {  SIMDE_FLOAT32_C(   49666.976), -SIMDE_FLOAT32_C(   10581.642), -SIMDE_FLOAT32_C(  272958.272), -SIMDE_FLOAT32_C(  279548.707) } },
    { { -SIMDE_FLOAT32_C(     863.683), -SIMDE_FLOAT32_C(     781.666), -SIMDE_FLOAT32_C(       2.318), -SIMDE_FLOAT32_C(       5.219) },
      {  SIMDE_FLOAT32_C(     726.489),  SIMDE_FLOAT32_C(     363.774),  SIMDE_FLOAT32_C(     874.616), -SIMDE_FLOAT32_C(     565.736) },
      { -SIMDE_FLOAT32_C(  627456.199), -SIMDE_FLOAT32_C(  284349.767), -SIMDE_FLOAT32_C(    2027.360),  SIMDE_FLOAT32_C(    2952.576) } },
    { {  SIMDE_FLOAT32_C(     717.781), -SIMDE_FLOAT32_C(     129.105),  SIMDE_FLOAT32_C(     573.568), -SIMDE_FLOAT32_C(      13.425) },
      { -SIMDE_FLOAT32_C(     490.860), -SIMDE_FLOAT32_C(     147.869), -SIMDE_FLOAT32_C(     578.844),  SIMDE_FLOAT32_C(     936.315) },
      { -SIMDE_FLOAT32_C(  352329.982),  SIMDE_FLOAT32_C(   19090.627), -SIMDE_FLOAT32_C(  332006.395), -SIMDE_FLOAT32_C(   12570.029) } },
    { { -SIMDE_FLOAT32_C(     638.144), -SIMDE_FLOAT32_C(     559.662), -SIMDE_FLOAT32_C(     162.387),  SIMDE_FLOAT32_C(     418.837) },
      { -SIMDE_FLOAT32_C(     655.074), -SIMDE_FLOAT32_C(     734.682),  SIMDE_FLOAT32_C(     423.662),  SIMDE_FLOAT32_C(     673.101) },
      {  SIMDE_FLOAT32_C(  418031.543),  SIMDE_FLOAT32_C(  411173.597), -SIMDE_FLOAT32_C(   68797.201),  SIMDE_FLOAT32_C(  281919.604) } },
    { {  SIMDE_FLOAT32_C(     894.456), -SIMDE_FLOAT32_C(      89.202),  SIMDE_FLOAT32_C(     362.573), -SIMDE_FLOAT32_C(     717.742) },
      { -SIMDE_FLOAT32_C(     330.936), -SIMDE_FLOAT32_C(      20.842),  SIMDE_FLOAT32_C(     696.112), -SIMDE_FLOAT32_C(     251.801) },
      { -SIMDE_FLOAT32_C(  296007.691),  SIMDE_FLOAT32_C(    1859.148),  SIMDE_FLOAT32_C(  252391.416),  SIMDE_FLOAT32_C(  180728.153) } },
    { { -SIMDE_FLOAT32_C(     751.290),  SIMDE_FLOAT32_C(     872.761),  SIMDE_FLOAT32_C(      49.838), -SIMDE_FLOAT32_C(     267.276) },
      {  SIMDE_FLOAT32_C(     759.279), -SIMDE_FLOAT32_C(      58.390), -SIMDE_FLOAT32_C(     531.075),  SIMDE_FLOAT32_C(     170.298) },
      { -SIMDE_FLOAT32_C(  570438.720), -SIMDE_FLOAT32_C(   50960.515), -SIMDE_FLOAT32_C(   26467.716), -SIMDE_FLOAT32_C(   45516.568) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t r = simde_vmulxq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vmulxq_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulxq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C(      24199.352),  SIMDE_FLOAT64_C(      82646.438) },
      {  SIMDE_FLOAT64_C(      39528.594), -SIMDE_FLOAT64_C(      62061.172) },
      {  SIMDE_FLOAT64_C(  956566360.271), -SIMDE_FLOAT64_C( 5129134803.905) } },
    { { -SIMDE_FLOAT64_C(      17662.867),  SIMDE_FLOAT64_C(      13579.281) },
      {  SIMDE_FLOAT64_C(      11833.070),  SIMDE_FLOAT64_C(      36063.047) },
      { -SIMDE_FLOAT64_C(  209005941.612),  SIMDE_FLOAT64_C(  489710248.929) } },
    { {  SIMDE_FLOAT64_C(      49157.781), -SIMDE_FLOAT64_C(       8770.289) },
      { -SIMDE_FLOAT64_C(      79110.055), -SIMDE_FLOAT64_C(      15752.375) },
      { -SIMDE_FLOAT64_C( 3888874758.588),  SIMDE_FLOAT64_C(  138152881.186) } },
    { {  SIMDE_FLOAT64_C(      30696.070), -SIMDE_FLOAT64_C(      54786.527) },
      {  SIMDE_FLOAT64_C(      68961.172),  SIMDE_FLOAT64_C(      33200.047) },
      {  SIMDE_FLOAT64_C( 2116836962.994), -SIMDE_FLOAT64_C( 1818915271.367) } },
    { { -SIMDE_FLOAT64_C(      71874.563), -SIMDE_FLOAT64_C(       8494.773) },
      {  SIMDE_FLOAT64_C(      59465.734),  SIMDE_FLOAT64_C(      79792.094) },
      { -SIMDE_FLOAT64_C( 4274073644.724), -SIMDE_FLOAT64_C(  677815725.725) } },
    { {  SIMDE_FLOAT64_C(      37239.688), -SIMDE_FLOAT64_C(      73466.133) },
      { -SIMDE_FLOAT64_C(      10783.789),  SIMDE_FLOAT64_C(       2901.055) },
      { -SIMDE_FLOAT64_C(  401584937.818), -SIMDE_FLOAT64_C(  213129292.470) } },
    { {  SIMDE_FLOAT64_C(      93075.031),  SIMDE_FLOAT64_C(      27926.734) },
      {  SIMDE_FLOAT64_C(      81577.469),  SIMDE_FLOAT64_C(      48119.938) },
      {  SIMDE_FLOAT64_C( 7592825456.077),  SIMDE_FLOAT64_C( 1343832708.622) } },
    { { -SIMDE_FLOAT64_C(      84794.109), -SIMDE_FLOAT64_C(      73424.023) },
      {  SIMDE_FLOAT64_C(      87311.406), -SIMDE_FLOAT64_C(      45982.188) },
      { -SIMDE_FLOAT64_C( 7403492877.307),  SIMDE_FLOAT64_C( 3376197229.302) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t r = simde_vmulxq_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64x2_t r = simde_vmulxq_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxh_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxs_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxd_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulx_f64)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulxq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
