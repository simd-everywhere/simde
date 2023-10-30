#define SIMDE_TEST_ARM_NEON_INSN maxnmv

#include "test-neon.h"
#include "../../../simde/arm/neon/maxnmv.h"

static int
test_simde_vmaxnmv_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[4];
    simde_float16_t r;
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(    -3.738),  SIMDE_FLOAT16_VALUE(     1.455),  SIMDE_FLOAT16_VALUE(    14.120),  SIMDE_FLOAT16_VALUE(    10.392) },
         SIMDE_FLOAT16_VALUE(    14.120) },
    { {  SIMDE_FLOAT16_VALUE(   -28.221),  SIMDE_FLOAT16_VALUE(   -24.836),  SIMDE_FLOAT16_VALUE(     1.975),  SIMDE_FLOAT16_VALUE(    15.527) },
         SIMDE_FLOAT16_VALUE(    15.527) },
    { {  SIMDE_FLOAT16_VALUE(    29.824),  SIMDE_FLOAT16_VALUE(    13.759),  SIMDE_FLOAT16_VALUE(   -15.380),  SIMDE_FLOAT16_VALUE(    21.745) },
         SIMDE_FLOAT16_VALUE(    29.824) },
    { {  SIMDE_FLOAT16_VALUE(    -2.636),  SIMDE_FLOAT16_VALUE(    17.047),  SIMDE_FLOAT16_VALUE(   -17.906),  SIMDE_FLOAT16_VALUE(    -2.426) },
         SIMDE_FLOAT16_VALUE(    17.047) },
    { {  SIMDE_FLOAT16_VALUE(   -23.268),  SIMDE_FLOAT16_VALUE(    -0.613),  SIMDE_FLOAT16_VALUE(    -5.015),  SIMDE_FLOAT16_VALUE(    14.077) },
         SIMDE_FLOAT16_VALUE(    14.077) },
    { {  SIMDE_FLOAT16_VALUE(   -18.977),  SIMDE_FLOAT16_VALUE(    18.537),  SIMDE_FLOAT16_VALUE(    27.393),  SIMDE_FLOAT16_VALUE(   -14.588) },
         SIMDE_FLOAT16_VALUE(    27.393) },
    { {  SIMDE_FLOAT16_VALUE(     8.490),  SIMDE_FLOAT16_VALUE(   -16.011),  SIMDE_FLOAT16_VALUE(    19.419),  SIMDE_FLOAT16_VALUE(     7.979) },
         SIMDE_FLOAT16_VALUE(    19.419) },
    { {  SIMDE_FLOAT16_VALUE(    15.064),  SIMDE_FLOAT16_VALUE(    18.001),  SIMDE_FLOAT16_VALUE(   -17.423),  SIMDE_FLOAT16_VALUE(   -12.709) },
         SIMDE_FLOAT16_VALUE(    18.001) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x4_t a = simde_vld1_f16(test_vec[i].a);
    simde_float16_t r = simde_vmaxnmv_f16(a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x4_t a = simde_test_arm_neon_random_f16x4(-100.0f, 100.0f);
    simde_float16_t r = simde_vmaxnmv_f16(a);

    simde_test_arm_neon_write_f16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnmvq_f16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float16_t a[8];
    simde_float16_t r;
  } test_vec[] = {
    { {  SIMDE_FLOAT16_VALUE(   -27.209),  SIMDE_FLOAT16_VALUE(    27.139),  SIMDE_FLOAT16_VALUE(    -8.487),  SIMDE_FLOAT16_VALUE(    29.647),
         SIMDE_FLOAT16_VALUE(     4.093),  SIMDE_FLOAT16_VALUE(   -12.946),  SIMDE_FLOAT16_VALUE(    19.678),  SIMDE_FLOAT16_VALUE(   -17.130) },
         SIMDE_FLOAT16_VALUE(    29.647) },
    { {  SIMDE_FLOAT16_VALUE(   -10.565),  SIMDE_FLOAT16_VALUE(    24.408),  SIMDE_FLOAT16_VALUE(   -20.684),  SIMDE_FLOAT16_VALUE(   -23.760),
         SIMDE_FLOAT16_VALUE(   -14.685),  SIMDE_FLOAT16_VALUE(    10.925),  SIMDE_FLOAT16_VALUE(   -23.577),  SIMDE_FLOAT16_VALUE(    -2.002) },
         SIMDE_FLOAT16_VALUE(    24.408) },
    { {  SIMDE_FLOAT16_VALUE(    12.637),  SIMDE_FLOAT16_VALUE(     0.627),  SIMDE_FLOAT16_VALUE(    -1.251),  SIMDE_FLOAT16_VALUE(   -18.692),
         SIMDE_FLOAT16_VALUE(    -0.956),  SIMDE_FLOAT16_VALUE(   -28.618),  SIMDE_FLOAT16_VALUE(   -21.850),  SIMDE_FLOAT16_VALUE(   -22.646) },
         SIMDE_FLOAT16_VALUE(    12.637) },
    { {  SIMDE_FLOAT16_VALUE(    28.637),  SIMDE_FLOAT16_VALUE(   -15.186),  SIMDE_FLOAT16_VALUE(    29.860),  SIMDE_FLOAT16_VALUE(    -4.792),
         SIMDE_FLOAT16_VALUE(     7.802),  SIMDE_FLOAT16_VALUE(   -20.342),  SIMDE_FLOAT16_VALUE(    26.549),  SIMDE_FLOAT16_VALUE(   -12.132) },
         SIMDE_FLOAT16_VALUE(    29.860) },
    { {  SIMDE_FLOAT16_VALUE(   -24.535),  SIMDE_FLOAT16_VALUE(    19.959),  SIMDE_FLOAT16_VALUE(    -2.053),  SIMDE_FLOAT16_VALUE(    21.915),
         SIMDE_FLOAT16_VALUE(   -12.173),  SIMDE_FLOAT16_VALUE(    25.143),  SIMDE_FLOAT16_VALUE(   -15.516),  SIMDE_FLOAT16_VALUE(    -1.281) },
         SIMDE_FLOAT16_VALUE(    25.143) },
    { {  SIMDE_FLOAT16_VALUE(     4.415),  SIMDE_FLOAT16_VALUE(     8.990),  SIMDE_FLOAT16_VALUE(    -7.033),  SIMDE_FLOAT16_VALUE(    -1.069),
         SIMDE_FLOAT16_VALUE(     9.131),  SIMDE_FLOAT16_VALUE(   -25.759),  SIMDE_FLOAT16_VALUE(    -2.994),  SIMDE_FLOAT16_VALUE(    11.418) },
         SIMDE_FLOAT16_VALUE(    11.418) },
    { {  SIMDE_FLOAT16_VALUE(    -8.941),  SIMDE_FLOAT16_VALUE(    22.113),  SIMDE_FLOAT16_VALUE(    14.990),  SIMDE_FLOAT16_VALUE(    -1.598),
         SIMDE_FLOAT16_VALUE(     7.272),  SIMDE_FLOAT16_VALUE(     8.508),  SIMDE_FLOAT16_VALUE(   -26.884),  SIMDE_FLOAT16_VALUE(   -27.776) },
         SIMDE_FLOAT16_VALUE(    22.113) },
    { {  SIMDE_FLOAT16_VALUE(   -17.691),  SIMDE_FLOAT16_VALUE(    -7.633),  SIMDE_FLOAT16_VALUE(    -1.437),  SIMDE_FLOAT16_VALUE(     1.893),
         SIMDE_FLOAT16_VALUE(   -26.187),  SIMDE_FLOAT16_VALUE(    26.083),  SIMDE_FLOAT16_VALUE(    -0.446),  SIMDE_FLOAT16_VALUE(    -7.923) },
         SIMDE_FLOAT16_VALUE(    26.083) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float16x8_t a = simde_vld1q_f16(test_vec[i].a);
    simde_float16_t r = simde_vmaxnmvq_f16(a);

    simde_assert_equal_f16(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float16x8_t a = simde_test_arm_neon_random_f16x8(-100.0f, 100.0f);
    simde_float16_t r = simde_vmaxnmvq_f16(a);

    simde_test_arm_neon_write_f16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnmv_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[2];
    simde_float32_t r;
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   498.24), SIMDE_FLOAT32_C(   700.18) },
      SIMDE_FLOAT32_C(   700.18) },
    { { SIMDE_FLOAT32_C(  -550.14), SIMDE_FLOAT32_C(  -372.82) },
      SIMDE_FLOAT32_C(  -372.82) },
    { { SIMDE_FLOAT32_C(  -184.85), SIMDE_FLOAT32_C(   347.23) },
      SIMDE_FLOAT32_C(   347.23) },
    { { SIMDE_FLOAT32_C(  -183.13), SIMDE_FLOAT32_C(   910.25) },
      SIMDE_FLOAT32_C(   910.25) },
    { { SIMDE_FLOAT32_C(   995.08), SIMDE_FLOAT32_C(   458.35) },
      SIMDE_FLOAT32_C(   995.08) },
    { { SIMDE_FLOAT32_C(   954.33), SIMDE_FLOAT32_C(   629.96) },
      SIMDE_FLOAT32_C(   954.33) },
    { { SIMDE_FLOAT32_C(   -93.64), SIMDE_FLOAT32_C(   684.43) },
      SIMDE_FLOAT32_C(   684.43) },
    { { SIMDE_FLOAT32_C(   -76.95), SIMDE_FLOAT32_C(  -360.35) },
      SIMDE_FLOAT32_C(   -76.95) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32_t r = simde_vmaxnmv_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vmaxnmv_f32(a);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnmvq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a[4];
    simde_float32_t r;
  } test_vec[] = {
    { { -SIMDE_FLOAT32_C(   671.249), -SIMDE_FLOAT32_C(   225.504),  SIMDE_FLOAT32_C(   807.316), -SIMDE_FLOAT32_C(   192.920) },
         SIMDE_FLOAT32_C(   807.316) },
    { { -SIMDE_FLOAT32_C(   590.028),  SIMDE_FLOAT32_C(   562.163),  SIMDE_FLOAT32_C(   209.177),  SIMDE_FLOAT32_C(   120.910) },
         SIMDE_FLOAT32_C(   562.163) },
    { { -SIMDE_FLOAT32_C(   700.667), -SIMDE_FLOAT32_C(   320.011), -SIMDE_FLOAT32_C(   104.212),  SIMDE_FLOAT32_C(   592.824) },
         SIMDE_FLOAT32_C(   592.824) },
    { {  SIMDE_FLOAT32_C(   814.094), -SIMDE_FLOAT32_C(   977.740),  SIMDE_FLOAT32_C(   507.701),  SIMDE_FLOAT32_C(   140.620) },
         SIMDE_FLOAT32_C(   814.094) },
    { {  SIMDE_FLOAT32_C(   211.605), -SIMDE_FLOAT32_C(   395.592), -SIMDE_FLOAT32_C(   788.657), -SIMDE_FLOAT32_C(    60.819) },
         SIMDE_FLOAT32_C(   211.605) },
    { {  SIMDE_FLOAT32_C(   348.532), -SIMDE_FLOAT32_C(   821.042), -SIMDE_FLOAT32_C(   787.180),  SIMDE_FLOAT32_C(     3.604) },
         SIMDE_FLOAT32_C(   348.532) },
    { { -SIMDE_FLOAT32_C(   731.969),  SIMDE_FLOAT32_C(   706.485), -SIMDE_FLOAT32_C(   999.465),  SIMDE_FLOAT32_C(   485.885) },
         SIMDE_FLOAT32_C(   706.485) },
    { { -SIMDE_FLOAT32_C(   750.926), -SIMDE_FLOAT32_C(   100.519), -SIMDE_FLOAT32_C(   960.919),  SIMDE_FLOAT32_C(   611.964) },
         SIMDE_FLOAT32_C(   611.964) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32_t r = simde_vmaxnmvq_f32(a);

    simde_assert_equal_f32(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32_t r = simde_vmaxnmvq_f32(a);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmaxnmvq_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a[2];
    simde_float64_t r;
  } test_vec[] = {
    { {  SIMDE_FLOAT64_C( 13634.109), -SIMDE_FLOAT64_C( 47458.680) },
         SIMDE_FLOAT64_C( 13634.109) },
    { {  SIMDE_FLOAT64_C( 53863.078),  SIMDE_FLOAT64_C( 59461.031) },
         SIMDE_FLOAT64_C( 59461.031) },
    { {  SIMDE_FLOAT64_C(   484.547),  SIMDE_FLOAT64_C( 55670.812) },
         SIMDE_FLOAT64_C( 55670.812) },
    { {  SIMDE_FLOAT64_C( 32263.688), -SIMDE_FLOAT64_C( 56743.133) },
         SIMDE_FLOAT64_C( 32263.688) },
    { { -SIMDE_FLOAT64_C( 38206.668),  SIMDE_FLOAT64_C( 69423.594) },
         SIMDE_FLOAT64_C( 69423.594) },
    { {  SIMDE_FLOAT64_C( 45622.297),  SIMDE_FLOAT64_C( 67118.375) },
         SIMDE_FLOAT64_C( 67118.375) },
    { { -SIMDE_FLOAT64_C( 83686.242), -SIMDE_FLOAT64_C( 85150.031) },
        -SIMDE_FLOAT64_C( 83686.242) },
    { {  SIMDE_FLOAT64_C( 88258.734), -SIMDE_FLOAT64_C(  8230.039) },
         SIMDE_FLOAT64_C( 88258.734) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64_t r = simde_vmaxnmvq_f64(a);

    simde_assert_equal_f64(r, test_vec[i].r, 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_float64_t r = simde_vmaxnmvq_f64(a);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmv_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmvq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmv_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmvq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmaxnmvq_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
