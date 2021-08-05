#define SIMDE_TEST_MIPS_MSA_INSN madd

#include "test-msa.h"
#include "../../../simde/mips/msa/madd.h"

static int
test_simde_fmadd_w (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 c[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -524.41), SIMDE_FLOAT32_C(  -776.23), SIMDE_FLOAT32_C(  -545.16), SIMDE_FLOAT32_C(  -321.65) },
      { SIMDE_FLOAT32_C(   543.34), SIMDE_FLOAT32_C(  -181.67), SIMDE_FLOAT32_C(   287.64), SIMDE_FLOAT32_C(  -673.71) },
      { SIMDE_FLOAT32_C(   675.91), SIMDE_FLOAT32_C(  -488.56), SIMDE_FLOAT32_C(     4.92), SIMDE_FLOAT32_C(   540.27) },
      { SIMDE_FLOAT32_C(366724.53), SIMDE_FLOAT32_C( 87980.46), SIMDE_FLOAT32_C(   870.03), SIMDE_FLOAT32_C(-364306.97) } },
    { { SIMDE_FLOAT32_C(  -934.54), SIMDE_FLOAT32_C(  -473.44), SIMDE_FLOAT32_C(  -657.44), SIMDE_FLOAT32_C(   588.19) },
      { SIMDE_FLOAT32_C(  -958.10), SIMDE_FLOAT32_C(   689.98), SIMDE_FLOAT32_C(   754.71), SIMDE_FLOAT32_C(   -87.63) },
      { SIMDE_FLOAT32_C(  -855.49), SIMDE_FLOAT32_C(  -863.92), SIMDE_FLOAT32_C(  -336.54), SIMDE_FLOAT32_C(   366.73) },
      { SIMDE_FLOAT32_C(818710.38), SIMDE_FLOAT32_C(-596560.94), SIMDE_FLOAT32_C(-254647.56), SIMDE_FLOAT32_C(-31548.36) } },
    { { SIMDE_FLOAT32_C(  -656.71), SIMDE_FLOAT32_C(   592.19), SIMDE_FLOAT32_C(   956.68), SIMDE_FLOAT32_C(   767.49) },
      { SIMDE_FLOAT32_C(   275.39), SIMDE_FLOAT32_C(  -573.54), SIMDE_FLOAT32_C(   943.26), SIMDE_FLOAT32_C(   750.98) },
      { SIMDE_FLOAT32_C(  -349.78), SIMDE_FLOAT32_C(  -601.91), SIMDE_FLOAT32_C(  -570.67), SIMDE_FLOAT32_C(  -806.44) },
      { SIMDE_FLOAT32_C(-96982.63), SIMDE_FLOAT32_C(345811.62), SIMDE_FLOAT32_C(-537333.50), SIMDE_FLOAT32_C(-604852.81) } },
    { { SIMDE_FLOAT32_C(   216.43), SIMDE_FLOAT32_C(   716.97), SIMDE_FLOAT32_C(  -480.15), SIMDE_FLOAT32_C(  -107.67) },
      { SIMDE_FLOAT32_C(  -771.59), SIMDE_FLOAT32_C(   524.77), SIMDE_FLOAT32_C(  -567.39), SIMDE_FLOAT32_C(  -706.13) },
      { SIMDE_FLOAT32_C(  -948.66), SIMDE_FLOAT32_C(  -224.83), SIMDE_FLOAT32_C(   882.06), SIMDE_FLOAT32_C(  -906.77) },
      { SIMDE_FLOAT32_C(732193.00), SIMDE_FLOAT32_C(-117267.08), SIMDE_FLOAT32_C(-500952.19), SIMDE_FLOAT32_C(640189.88) } },
    { { SIMDE_FLOAT32_C(  -534.85), SIMDE_FLOAT32_C(   636.77), SIMDE_FLOAT32_C(     5.60), SIMDE_FLOAT32_C(  -390.34) },
      { SIMDE_FLOAT32_C(   772.85), SIMDE_FLOAT32_C(   669.06), SIMDE_FLOAT32_C(   976.38), SIMDE_FLOAT32_C(  -883.85) },
      { SIMDE_FLOAT32_C(   261.25), SIMDE_FLOAT32_C(   933.06), SIMDE_FLOAT32_C(   883.64), SIMDE_FLOAT32_C(  -463.36) },
      { SIMDE_FLOAT32_C(201372.20), SIMDE_FLOAT32_C(624909.88), SIMDE_FLOAT32_C(862774.06), SIMDE_FLOAT32_C(409150.38) } },
    { { SIMDE_FLOAT32_C(  -640.48), SIMDE_FLOAT32_C(   826.90), SIMDE_FLOAT32_C(  -712.38), SIMDE_FLOAT32_C(     9.74) },
      { SIMDE_FLOAT32_C(  -775.01), SIMDE_FLOAT32_C(  -283.06), SIMDE_FLOAT32_C(   203.30), SIMDE_FLOAT32_C(   441.41) },
      { SIMDE_FLOAT32_C(  -566.09), SIMDE_FLOAT32_C(   723.15), SIMDE_FLOAT32_C(  -666.25), SIMDE_FLOAT32_C(  -337.68) },
      { SIMDE_FLOAT32_C(438084.97), SIMDE_FLOAT32_C(-203867.94), SIMDE_FLOAT32_C(-136161.00), SIMDE_FLOAT32_C(-149045.59) } },
    { { SIMDE_FLOAT32_C(   247.93), SIMDE_FLOAT32_C(  -233.64), SIMDE_FLOAT32_C(   -43.81), SIMDE_FLOAT32_C(   299.26) },
      { SIMDE_FLOAT32_C(   541.53), SIMDE_FLOAT32_C(  -161.75), SIMDE_FLOAT32_C(   392.50), SIMDE_FLOAT32_C(  -993.33) },
      { SIMDE_FLOAT32_C(  -524.98), SIMDE_FLOAT32_C(  -601.90), SIMDE_FLOAT32_C(  -383.67), SIMDE_FLOAT32_C(  -752.13) },
      { SIMDE_FLOAT32_C(-284044.50), SIMDE_FLOAT32_C( 97123.69), SIMDE_FLOAT32_C(-150634.30), SIMDE_FLOAT32_C(747412.56) } },
    { { SIMDE_FLOAT32_C(  -932.84), SIMDE_FLOAT32_C(  -407.29), SIMDE_FLOAT32_C(  -635.98), SIMDE_FLOAT32_C(   328.41) },
      { SIMDE_FLOAT32_C(  -474.23), SIMDE_FLOAT32_C(  -752.34), SIMDE_FLOAT32_C(   865.05), SIMDE_FLOAT32_C(  -114.71) },
      { SIMDE_FLOAT32_C(  -925.44), SIMDE_FLOAT32_C(  -847.33), SIMDE_FLOAT32_C(   895.04), SIMDE_FLOAT32_C(  -700.46) },
      { SIMDE_FLOAT32_C(437938.59), SIMDE_FLOAT32_C(637073.00), SIMDE_FLOAT32_C(773618.31), SIMDE_FLOAT32_C( 80678.18) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v4f32 a = simde_x_msa_fld_w(test_vec[i].a, 0);
    simde_v4f32 b = simde_x_msa_fld_w(test_vec[i].b, 0);
    simde_v4f32 c = simde_x_msa_fld_w(test_vec[i].c, 0);
    simde_v4f32 r = simde_msa_fmadd_w(a, b, c);

    simde_test_msa_v4f32_assert_equal(r, simde_x_msa_fld_w(test_vec[i].r, 0), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v4f32 a = simde_test_msa_v4f32_random(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_v4f32 b = simde_test_msa_v4f32_random(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_v4f32 c = simde_test_msa_v4f32_random(-SIMDE_FLOAT32_C(1000.0), SIMDE_FLOAT32_C(1000.0));
    simde_v4f32 r = simde_msa_fmadd_w(a, b, c);

    simde_test_msa_v4f32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v4f32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v4f32_write(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v4f32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_fmadd_d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 c[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   697.18), SIMDE_FLOAT64_C(  -624.95) },
      { SIMDE_FLOAT64_C(   306.12), SIMDE_FLOAT64_C(     7.71) },
      { SIMDE_FLOAT64_C(   183.92), SIMDE_FLOAT64_C(  -436.47) },
      { SIMDE_FLOAT64_C( 56998.77), SIMDE_FLOAT64_C( -3990.13) } },
    { { SIMDE_FLOAT64_C(   427.44), SIMDE_FLOAT64_C(   580.62) },
      { SIMDE_FLOAT64_C(   774.98), SIMDE_FLOAT64_C(   959.08) },
      { SIMDE_FLOAT64_C(   292.83), SIMDE_FLOAT64_C(  -399.60) },
      { SIMDE_FLOAT64_C(227364.83), SIMDE_FLOAT64_C(-382667.75) } },
    { { SIMDE_FLOAT64_C(  -469.14), SIMDE_FLOAT64_C(  -911.91) },
      { SIMDE_FLOAT64_C(    47.76), SIMDE_FLOAT64_C(   477.15) },
      { SIMDE_FLOAT64_C(   416.21), SIMDE_FLOAT64_C(   764.44) },
      { SIMDE_FLOAT64_C( 19409.05), SIMDE_FLOAT64_C(363840.64) } },
    { { SIMDE_FLOAT64_C(    47.21), SIMDE_FLOAT64_C(    71.67) },
      { SIMDE_FLOAT64_C(  -599.60), SIMDE_FLOAT64_C(   534.28) },
      { SIMDE_FLOAT64_C(   454.76), SIMDE_FLOAT64_C(   324.14) },
      { SIMDE_FLOAT64_C(-272626.89), SIMDE_FLOAT64_C(173253.19) } },
    { { SIMDE_FLOAT64_C(    17.69), SIMDE_FLOAT64_C(  -977.20) },
      { SIMDE_FLOAT64_C(  -419.66), SIMDE_FLOAT64_C(   953.51) },
      { SIMDE_FLOAT64_C(   -64.97), SIMDE_FLOAT64_C(  -736.13) },
      { SIMDE_FLOAT64_C( 27283.00), SIMDE_FLOAT64_C(-702884.52) } },
    { { SIMDE_FLOAT64_C(   174.53), SIMDE_FLOAT64_C(  -367.79) },
      { SIMDE_FLOAT64_C(  -361.08), SIMDE_FLOAT64_C(  -519.35) },
      { SIMDE_FLOAT64_C(   639.92), SIMDE_FLOAT64_C(   822.85) },
      { SIMDE_FLOAT64_C(-230887.78), SIMDE_FLOAT64_C(-427714.94) } },
    { { SIMDE_FLOAT64_C(    44.18), SIMDE_FLOAT64_C(    67.36) },
      { SIMDE_FLOAT64_C(   403.46), SIMDE_FLOAT64_C(  -180.84) },
      { SIMDE_FLOAT64_C(    26.45), SIMDE_FLOAT64_C(  -303.70) },
      { SIMDE_FLOAT64_C( 10715.70), SIMDE_FLOAT64_C( 54988.47) } },
    { { SIMDE_FLOAT64_C(   419.56), SIMDE_FLOAT64_C(   557.31) },
      { SIMDE_FLOAT64_C(  -215.62), SIMDE_FLOAT64_C(  -532.68) },
      { SIMDE_FLOAT64_C(    34.46), SIMDE_FLOAT64_C(  -799.41) },
      { SIMDE_FLOAT64_C( -7010.71), SIMDE_FLOAT64_C(426387.03) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v2f64 a = simde_x_msa_fld_d(test_vec[i].a, 0);
    simde_v2f64 b = simde_x_msa_fld_d(test_vec[i].b, 0);
    simde_v2f64 c = simde_x_msa_fld_d(test_vec[i].c, 0);
    simde_v2f64 r = simde_msa_fmadd_d(a, b, c);

    simde_test_msa_v2f64_assert_equal(r, simde_x_msa_fld_d(test_vec[i].r, 0), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v2f64 a = simde_test_msa_v2f64_random(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_v2f64 b = simde_test_msa_v2f64_random(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_v2f64 c = simde_test_msa_v2f64_random(-SIMDE_FLOAT64_C(1000.0), SIMDE_FLOAT64_C(1000.0));
    simde_v2f64 r = simde_msa_fmadd_d(a, b, c);

    simde_test_msa_v2f64_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v2f64_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v2f64_write(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v2f64_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(fmadd_w)
SIMDE_TEST_FUNC_LIST_ENTRY(fmadd_d)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
