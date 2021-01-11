#define SIMDE_TEST_ARM_NEON_INSN mul_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mul_n.h"

static int
test_simde_vmul_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -322.57), SIMDE_FLOAT32_C(   102.45) },
      SIMDE_FLOAT32_C(   338.06),
      { SIMDE_FLOAT32_C(-109048.02), SIMDE_FLOAT32_C( 34634.25) } },
    { { SIMDE_FLOAT32_C(   826.06), SIMDE_FLOAT32_C(    35.18) },
      SIMDE_FLOAT32_C(   -55.56),
      { SIMDE_FLOAT32_C(-45895.89), SIMDE_FLOAT32_C( -1954.60) } },
    { { SIMDE_FLOAT32_C(   331.09), SIMDE_FLOAT32_C(    34.30) },
      SIMDE_FLOAT32_C(   -93.48),
      { SIMDE_FLOAT32_C(-30950.29), SIMDE_FLOAT32_C( -3206.36) } },
    { { SIMDE_FLOAT32_C(  -539.02), SIMDE_FLOAT32_C(  -424.49) },
      SIMDE_FLOAT32_C(   433.22),
      { SIMDE_FLOAT32_C(-233514.25), SIMDE_FLOAT32_C(-183897.55) } },
    { { SIMDE_FLOAT32_C(  -259.56), SIMDE_FLOAT32_C(  -381.86) },
      SIMDE_FLOAT32_C(  -747.65),
      { SIMDE_FLOAT32_C(194060.03), SIMDE_FLOAT32_C(285497.62) } },
    { { SIMDE_FLOAT32_C(  -602.55), SIMDE_FLOAT32_C(   464.29) },
      SIMDE_FLOAT32_C(   164.24),
      { SIMDE_FLOAT32_C(-98962.81), SIMDE_FLOAT32_C( 76254.99) } },
    { { SIMDE_FLOAT32_C(  -454.97), SIMDE_FLOAT32_C(  -825.36) },
      SIMDE_FLOAT32_C(   -63.46),
      { SIMDE_FLOAT32_C( 28872.40), SIMDE_FLOAT32_C( 52377.34) } },
    { { SIMDE_FLOAT32_C(  -885.16), SIMDE_FLOAT32_C(  -707.21) },
      SIMDE_FLOAT32_C(   474.46),
      { SIMDE_FLOAT32_C(-419973.00), SIMDE_FLOAT32_C(-335542.88) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32 b = test_vec[i].b;
    simde_float32x2_t r = simde_vmul_n_f32(a, b);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32 b = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vmul_n_f32(a, b);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[1];
    simde_float64 b;
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(     8.29) },
      SIMDE_FLOAT64_C(   136.66),
      { SIMDE_FLOAT64_C(  1132.91) } },
    { { SIMDE_FLOAT64_C(   594.35) },
      SIMDE_FLOAT64_C(   690.12),
      { SIMDE_FLOAT64_C(410172.82) } },
    { { SIMDE_FLOAT64_C(   410.65) },
      SIMDE_FLOAT64_C(  -245.50),
      { SIMDE_FLOAT64_C(-100814.57) } },
    { { SIMDE_FLOAT64_C(  -390.11) },
      SIMDE_FLOAT64_C(  -996.89),
      { SIMDE_FLOAT64_C(388896.76) } },
    { { SIMDE_FLOAT64_C(  -725.18) },
      SIMDE_FLOAT64_C(   771.24),
      { SIMDE_FLOAT64_C(-559287.82) } },
    { { SIMDE_FLOAT64_C(  -382.17) },
      SIMDE_FLOAT64_C(    80.74),
      { SIMDE_FLOAT64_C(-30856.41) } },
    { { SIMDE_FLOAT64_C(    57.06) },
      SIMDE_FLOAT64_C(   152.89),
      { SIMDE_FLOAT64_C(  8723.90) } },
    { { SIMDE_FLOAT64_C(  -971.23) },
      SIMDE_FLOAT64_C(   806.94),
      { SIMDE_FLOAT64_C(-783724.34) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64 b = test_vec[i].b;
    simde_float64x1_t r = simde_vmul_n_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64 b = simde_test_codegen_random_f64(-1000.0f, 1000.0f);
    simde_float64x1_t r = simde_vmul_n_f64(a, b);

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b;
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 11569), -INT16_C( 13956),  INT16_C(  1331),  INT16_C(  9314) },
      -INT16_C( 30067),
      { -INT16_C( 19965), -INT16_C( 11956),  INT16_C( 23319), -INT16_C(  8710) } },
    { { -INT16_C( 13683),  INT16_C( 14392), -INT16_C( 22788), -INT16_C(  4789) },
      -INT16_C( 30281),
      {  INT16_C( 16331),  INT16_C( 10248),  INT16_C( 14884), -INT16_C( 15459) } },
    { { -INT16_C( 21076), -INT16_C(  4703), -INT16_C( 32359),  INT16_C( 15317) },
       INT16_C( 29744),
      { -INT16_C( 32704), -INT16_C( 32208), -INT16_C( 24400), -INT16_C( 17424) } },
    { { -INT16_C(   213), -INT16_C( 22714),  INT16_C( 31432),  INT16_C( 10924) },
       INT16_C( 14750),
      {  INT16_C(  3978), -INT16_C( 11468),  INT16_C( 20336), -INT16_C( 24024) } },
    { {  INT16_C( 11444), -INT16_C(  5116),  INT16_C(   100), -INT16_C( 20333) },
       INT16_C( 19181),
      {  INT16_C( 27300), -INT16_C( 22604),  INT16_C( 17556), -INT16_C(  2537) } },
    { { -INT16_C( 26311), -INT16_C(  9481), -INT16_C( 28282),  INT16_C( 23643) },
      -INT16_C( 29748),
      {  INT16_C(  3180), -INT16_C( 26156), -INT16_C( 18232),  INT16_C(   388) } },
    { { -INT16_C(  2096),  INT16_C(  5770),  INT16_C( 21151),  INT16_C( 19344) },
       INT16_C( 12156),
      {  INT16_C( 14528),  INT16_C( 16600),  INT16_C( 13828),  INT16_C(  2496) } },
    { {  INT16_C( 12421), -INT16_C( 30373), -INT16_C( 16611), -INT16_C( 20343) },
       INT16_C( 30575),
      { -INT16_C(  9045), -INT16_C(  9355),  INT16_C( 22675),  INT16_C( 14951) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    int16_t b = test_vec[i].b;
    simde_int16x4_t r = simde_vmul_n_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    int16_t b = simde_test_codegen_random_i16();
    simde_int16x4_t r = simde_vmul_n_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  2046384268), -INT32_C(   937882563) },
      -INT32_C(   653222027),
      {  INT32_C(   776705028),  INT32_C(  2061269729) } },
    { {  INT32_C(  1723824725), -INT32_C(   838833157) },
       INT32_C(    67083436),
      { -INT32_C(  1864565476),  INT32_C(   706379940) } },
    { {  INT32_C(   474729031),  INT32_C(   124028051) },
       INT32_C(  1770875436),
      { -INT32_C(   958191052),  INT32_C(   874686276) } },
    { { -INT32_C(   349067658), -INT32_C(  1681571515) },
      -INT32_C(  1241414469),
      { -INT32_C(   242257870), -INT32_C(   838647449) } },
    { { -INT32_C(  1669004560), -INT32_C(   442530658) },
      -INT32_C(   519968178),
      {  INT32_C(   942032160),  INT32_C(   678482980) } },
    { { -INT32_C(  1679268497),  INT32_C(  1174697680) },
       INT32_C(  1647457564),
      {  INT32_C(  2014909220),  INT32_C(  1773539008) } },
    { {  INT32_C(   838727542),  INT32_C(  1810366075) },
      -INT32_C(  1626903552),
      {  INT32_C(   849332224),  INT32_C(   968418304) } },
    { {  INT32_C(  1065658097),  INT32_C(     2197137) },
      -INT32_C(  1147467285),
      {  INT32_C(   395229243), -INT32_C(  1320378341) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    int32_t b = test_vec[i].b;
    simde_int32x2_t r = simde_vmul_n_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    int32_t b = simde_test_codegen_random_i32();
    simde_int32x2_t r = simde_vmul_n_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b;
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(10900), UINT16_C(51102), UINT16_C(21030), UINT16_C(24060) },
      UINT16_C(48791),
      { UINT16_C(62796), UINT16_C(  562), UINT16_C(43114), UINT16_C(30628) } },
    { { UINT16_C( 8504), UINT16_C(37652), UINT16_C( 4524), UINT16_C(29706) },
      UINT16_C(34360),
      { UINT16_C(37952), UINT16_C(42080), UINT16_C(58784), UINT16_C(40496) } },
    { { UINT16_C(24879), UINT16_C(36045), UINT16_C(40790), UINT16_C(53145) },
      UINT16_C(33486),
      { UINT16_C( 4562), UINT16_C(26358), UINT16_C(58164), UINT16_C(48926) } },
    { { UINT16_C(25144), UINT16_C(54957), UINT16_C(54058), UINT16_C( 9768) },
      UINT16_C(48944),
      { UINT16_C(12928), UINT16_C(21360), UINT16_C(60896), UINT16_C(65408) } },
    { { UINT16_C(26852), UINT16_C(63712), UINT16_C(36091), UINT16_C( 1290) },
      UINT16_C(16897),
      { UINT16_C(12516), UINT16_C(47328), UINT16_C(17147), UINT16_C(39178) } },
    { { UINT16_C(12427), UINT16_C(22691), UINT16_C(63932), UINT16_C(22008) },
      UINT16_C(50889),
      { UINT16_C(40739), UINT16_C(43515), UINT16_C(31900), UINT16_C(20408) } },
    { { UINT16_C(  472), UINT16_C(34089), UINT16_C(21463), UINT16_C(65368) },
      UINT16_C(35193),
      { UINT16_C(30488), UINT16_C(57697), UINT16_C(44959), UINT16_C(51352) } },
    { { UINT16_C(23999), UINT16_C(40945), UINT16_C(60758), UINT16_C(24620) },
      UINT16_C(11762),
      { UINT16_C(12686), UINT16_C(36562), UINT16_C(31052), UINT16_C(42392) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    uint16_t b = test_vec[i].b;
    simde_uint16x4_t r = simde_vmul_n_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    uint16_t b = simde_test_codegen_random_u16();
    simde_uint16x4_t r = simde_vmul_n_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmul_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3164635766), UINT32_C(1397605284) },
      UINT32_C(2149061254),
      { UINT32_C(1077974468), UINT32_C(1775628248) } },
    { { UINT32_C( 229242173), UINT32_C(2073123090) },
      UINT32_C(2781432267),
      { UINT32_C( 714660959), UINT32_C(4157195078) } },
    { { UINT32_C(2999833826), UINT32_C( 621473455) },
      UINT32_C( 367110768),
      { UINT32_C(2383230688), UINT32_C(2585240208) } },
    { { UINT32_C(4100468334), UINT32_C(2121564225) },
      UINT32_C(2290818677),
      { UINT32_C(2395479110), UINT32_C(2643540917) } },
    { { UINT32_C(1124277623), UINT32_C(1239993446) },
      UINT32_C(1341896096),
      { UINT32_C(2993982816), UINT32_C(2886065600) } },
    { { UINT32_C( 343213731), UINT32_C( 506025648) },
      UINT32_C(3323171205),
      { UINT32_C(2041038255), UINT32_C(2762193264) } },
    { { UINT32_C(2252637969), UINT32_C( 487510181) },
      UINT32_C(1398804973),
      { UINT32_C(  63515581), UINT32_C(2675056065) } },
    { { UINT32_C(2124171485), UINT32_C(2714605822) },
      UINT32_C(1320501918),
      { UINT32_C(1233056358), UINT32_C(1844177092) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    uint32_t b = test_vec[i].b;
    simde_uint32x2_t r = simde_vmul_n_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    uint32_t b = simde_test_codegen_random_u32();
    simde_uint32x2_t r = simde_vmul_n_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   715.05), SIMDE_FLOAT32_C(  -716.07), SIMDE_FLOAT32_C(  -502.73), SIMDE_FLOAT32_C(   871.00) },
      SIMDE_FLOAT32_C(   429.18),
      { SIMDE_FLOAT32_C(306885.16), SIMDE_FLOAT32_C(-307322.91), SIMDE_FLOAT32_C(-215761.66), SIMDE_FLOAT32_C(373815.78) } },
    { { SIMDE_FLOAT32_C(  -532.27), SIMDE_FLOAT32_C(  -766.37), SIMDE_FLOAT32_C(  -989.32), SIMDE_FLOAT32_C(   215.47) },
      SIMDE_FLOAT32_C(   230.94),
      { SIMDE_FLOAT32_C(-122922.44), SIMDE_FLOAT32_C(-176985.48), SIMDE_FLOAT32_C(-228473.56), SIMDE_FLOAT32_C( 49760.64) } },
    { { SIMDE_FLOAT32_C(  -948.09), SIMDE_FLOAT32_C(  -787.27), SIMDE_FLOAT32_C(  -800.69), SIMDE_FLOAT32_C(  -447.45) },
      SIMDE_FLOAT32_C(    14.29),
      { SIMDE_FLOAT32_C(-13548.21), SIMDE_FLOAT32_C(-11250.09), SIMDE_FLOAT32_C(-11441.86), SIMDE_FLOAT32_C( -6394.06) } },
    { { SIMDE_FLOAT32_C(  -572.66), SIMDE_FLOAT32_C(   567.13), SIMDE_FLOAT32_C(  -909.19), SIMDE_FLOAT32_C(   166.79) },
      SIMDE_FLOAT32_C(  -610.23),
      { SIMDE_FLOAT32_C(349454.28), SIMDE_FLOAT32_C(-346079.72), SIMDE_FLOAT32_C(554815.00), SIMDE_FLOAT32_C(-101780.26) } },
    { { SIMDE_FLOAT32_C(   231.91), SIMDE_FLOAT32_C(   484.47), SIMDE_FLOAT32_C(   543.89), SIMDE_FLOAT32_C(   817.92) },
      SIMDE_FLOAT32_C(  -700.44),
      { SIMDE_FLOAT32_C(-162439.05), SIMDE_FLOAT32_C(-339342.16), SIMDE_FLOAT32_C(-380962.31), SIMDE_FLOAT32_C(-572903.88) } },
    { { SIMDE_FLOAT32_C(   709.18), SIMDE_FLOAT32_C(    81.85), SIMDE_FLOAT32_C(  -425.91), SIMDE_FLOAT32_C(   317.14) },
      SIMDE_FLOAT32_C(   890.53),
      { SIMDE_FLOAT32_C(631546.06), SIMDE_FLOAT32_C( 72889.88), SIMDE_FLOAT32_C(-379285.66), SIMDE_FLOAT32_C(282422.72) } },
    { { SIMDE_FLOAT32_C(   108.81), SIMDE_FLOAT32_C(    32.18), SIMDE_FLOAT32_C(  -825.54), SIMDE_FLOAT32_C(   606.08) },
      SIMDE_FLOAT32_C(   -96.81),
      { SIMDE_FLOAT32_C(-10533.90), SIMDE_FLOAT32_C( -3115.35), SIMDE_FLOAT32_C( 79920.52), SIMDE_FLOAT32_C(-58674.61) } },
    { { SIMDE_FLOAT32_C(   603.63), SIMDE_FLOAT32_C(  -926.19), SIMDE_FLOAT32_C(   136.81), SIMDE_FLOAT32_C(   614.31) },
      SIMDE_FLOAT32_C(   289.28),
      { SIMDE_FLOAT32_C(174618.09), SIMDE_FLOAT32_C(-267928.25), SIMDE_FLOAT32_C( 39576.39), SIMDE_FLOAT32_C(177707.59) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32 b = test_vec[i].b;
    simde_float32x4_t r = simde_vmulq_n_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32 b = simde_test_codegen_random_f32(-1000.0f, 1000.0);
    simde_float32x4_t r = simde_vmulq_n_f32(a, b);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 a[2];
    simde_float64 b;
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -876.34), SIMDE_FLOAT64_C(  -946.04) },
      SIMDE_FLOAT64_C(  -921.46),
      { SIMDE_FLOAT64_C(807512.26), SIMDE_FLOAT64_C(871738.02) } },
    { { SIMDE_FLOAT64_C(  -297.61), SIMDE_FLOAT64_C(   953.41) },
      SIMDE_FLOAT64_C(  -273.22),
      { SIMDE_FLOAT64_C( 81313.00), SIMDE_FLOAT64_C(-260490.68) } },
    { { SIMDE_FLOAT64_C(  -449.19), SIMDE_FLOAT64_C(   633.81) },
      SIMDE_FLOAT64_C(  -282.52),
      { SIMDE_FLOAT64_C(126905.16), SIMDE_FLOAT64_C(-179064.00) } },
    { { SIMDE_FLOAT64_C(    17.47), SIMDE_FLOAT64_C(   267.43) },
      SIMDE_FLOAT64_C(  -863.41),
      { SIMDE_FLOAT64_C(-15083.77), SIMDE_FLOAT64_C(-230901.74) } },
    { { SIMDE_FLOAT64_C(  -236.05), SIMDE_FLOAT64_C(   920.75) },
      SIMDE_FLOAT64_C(  -470.13),
      { SIMDE_FLOAT64_C(110974.19), SIMDE_FLOAT64_C(-432872.20) } },
    { { SIMDE_FLOAT64_C(  -667.31), SIMDE_FLOAT64_C(   277.78) },
      SIMDE_FLOAT64_C(    38.32),
      { SIMDE_FLOAT64_C(-25571.32), SIMDE_FLOAT64_C( 10644.53) } },
    { { SIMDE_FLOAT64_C(   502.96), SIMDE_FLOAT64_C(  -260.05) },
      SIMDE_FLOAT64_C(   348.52),
      { SIMDE_FLOAT64_C(175291.62), SIMDE_FLOAT64_C(-90632.63) } },
    { { SIMDE_FLOAT64_C(   -87.91), SIMDE_FLOAT64_C(  -360.14) },
      SIMDE_FLOAT64_C(   845.79),
      { SIMDE_FLOAT64_C(-74353.40), SIMDE_FLOAT64_C(-304602.81) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64 b = test_vec[i].b;
    simde_float64x2_t r = simde_vmulq_n_f64(a, b);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64 b = simde_test_codegen_random_f64(-1000.0, 1000.0);
    simde_float64x2_t r = simde_vmulq_n_f64(a, b);

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_f64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b;
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 29355),  INT16_C(  8535),  INT16_C( 30880), -INT16_C(  2113), -INT16_C( 18419),  INT16_C( 15569),  INT16_C(  3061),  INT16_C( 20353) },
       INT16_C( 29090),
      {  INT16_C(  2870), -INT16_C( 32754), -INT16_C(  2752),  INT16_C(  5598),  INT16_C( 13626), -INT16_C( 17086), -INT16_C( 18934),  INT16_C( 16546) } },
    { {  INT16_C( 21959), -INT16_C( 25743),  INT16_C( 25094), -INT16_C( 30043),  INT16_C(  2684),  INT16_C( 14912), -INT16_C(  5362),  INT16_C( 26029) },
       INT16_C( 19724),
      { -INT16_C(  8108),  INT16_C( 17996),  INT16_C( 26184),  INT16_C(  8380), -INT16_C( 13872), -INT16_C(  1280),  INT16_C( 15016), -INT16_C( 13028) } },
    { { -INT16_C( 13091), -INT16_C(  5308),  INT16_C(  5508),  INT16_C( 31015), -INT16_C( 22240), -INT16_C( 15672), -INT16_C( 28646), -INT16_C( 29928) },
       INT16_C(  7723),
      {  INT16_C( 20255),  INT16_C( 31852),  INT16_C(  5420), -INT16_C(  5235),  INT16_C( 10336),  INT16_C( 10136),  INT16_C( 16478),  INT16_C( 11528) } },
    { { -INT16_C( 12050),  INT16_C( 27304), -INT16_C(  5925), -INT16_C(  5724),  INT16_C( 20947), -INT16_C(  8370),  INT16_C( 11422), -INT16_C(  7509) },
       INT16_C( 12055),
      {  INT16_C( 30562),  INT16_C( 27928),  INT16_C(  8365),  INT16_C(  6588),  INT16_C(  5877),  INT16_C( 25090),  INT16_C(  1074), -INT16_C( 15779) } },
    { {  INT16_C( 16119),  INT16_C(  6056),  INT16_C( 29159),  INT16_C(   730), -INT16_C(  3583),  INT16_C( 11405),  INT16_C( 31504), -INT16_C( 18180) },
      -INT16_C( 10267),
      { -INT16_C( 15373),  INT16_C( 16712), -INT16_C(  7005), -INT16_C( 23806),  INT16_C( 20965),  INT16_C( 17697), -INT16_C( 31408),  INT16_C(  7532) } },
    { { -INT16_C( 30048),  INT16_C( 29632),  INT16_C(  4059),  INT16_C( 31314), -INT16_C(   453),  INT16_C( 21084),  INT16_C( 21549), -INT16_C( 10608) },
       INT16_C( 30827),
      { -INT16_C(  3872),  INT16_C( 24896),  INT16_C( 18569), -INT16_C( 28602), -INT16_C(  5463), -INT16_C( 29580),  INT16_C( 18127),  INT16_C( 11824) } },
    { {  INT16_C( 17735),  INT16_C( 18554),  INT16_C(  1847),  INT16_C( 18292),  INT16_C( 28803),  INT16_C( 26879), -INT16_C( 24760),  INT16_C(  2290) },
      -INT16_C( 12782),
      {  INT16_C(   254),  INT16_C( 17556), -INT16_C( 15394),  INT16_C( 24104),  INT16_C( 21302), -INT16_C( 27666),  INT16_C(  8976),  INT16_C( 23812) } },
    { {  INT16_C( 25879),  INT16_C( 21064), -INT16_C( 23453), -INT16_C( 28508),  INT16_C( 13816),  INT16_C( 25702), -INT16_C( 21075),  INT16_C( 10153) },
      -INT16_C(  7691),
      { -INT16_C(  2557),  INT16_C(  1768),  INT16_C( 21951), -INT16_C( 28428), -INT16_C( 25000), -INT16_C( 17506),  INT16_C( 17297),  INT16_C( 32189) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int16_t b = test_vec[i].b;
    simde_int16x8_t r = simde_vmulq_n_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    int16_t b = simde_test_codegen_random_i16();
    simde_int16x8_t r = simde_vmulq_n_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1259590867),  INT32_C(  1715745376), -INT32_C(  2072571461),  INT32_C(  1807423984) },
      -INT32_C(  1921903951),
      {  INT32_C(  1252195299), -INT32_C(   814640032), -INT32_C(   640128949),  INT32_C(  1628425968) } },
    { {  INT32_C(   953218746),  INT32_C(  1297004900), -INT32_C(  1560843569), -INT32_C(  1628566722) },
      -INT32_C(   133942723),
      {  INT32_C(  1692606034), -INT32_C(  1853377324),  INT32_C(  1527570771), -INT32_C(  1713190458) } },
    { {  INT32_C(   880573251),  INT32_C(  1184839828),  INT32_C(    80941386),  INT32_C(  1815978760) },
       INT32_C(   750357341),
      {  INT32_C(  1066477655),  INT32_C(  1854138820), -INT32_C(  1853196830), -INT32_C(    89026072) } },
    { {  INT32_C(   869183989), -INT32_C(   103695172),  INT32_C(   854775278), -INT32_C(   446271919) },
      -INT32_C(   265615962),
      {  INT32_C(   900214238),  INT32_C(   172232168), -INT32_C(   694264236),  INT32_C(   942546310) } },
    { {  INT32_C(   536215319), -INT32_C(     7654750), -INT32_C(  1305786947), -INT32_C(  1293550858) },
      -INT32_C(  1515473226),
      { -INT32_C(   744836006), -INT32_C(   550819028), -INT32_C(   728305058), -INT32_C(   532853020) } },
    { { -INT32_C(   589849205), -INT32_C(  1295893236),  INT32_C(  1503915330), -INT32_C(  1887921940) },
      -INT32_C(  2020735798),
      {  INT32_C(  1353874350),  INT32_C(  1189108600), -INT32_C(  1280688620),  INT32_C(  1584683576) } },
    { {  INT32_C(  1060747849),  INT32_C(  1794186932),  INT32_C(  1594858708),  INT32_C(  1178396218) },
       INT32_C(  1727594019),
      {  INT32_C(  2020664827),  INT32_C(  1372441244), -INT32_C(   501430020),  INT32_C(   720438766) } },
    { { -INT32_C(   658531349), -INT32_C(    43567053), -INT32_C(  2054884036),  INT32_C(  1673837999) },
      -INT32_C(  1345407525),
      {  INT32_C(    21072137), -INT32_C(   669834591), -INT32_C(  1805044140), -INT32_C(  1220739147) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int32_t b = test_vec[i].b;
    simde_int32x4_t r = simde_vmulq_n_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    int32_t b = simde_test_codegen_random_i32();
    simde_int32x4_t r = simde_vmulq_n_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b;
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 5555), UINT16_C(58708), UINT16_C(41599), UINT16_C(46026), UINT16_C(46713), UINT16_C(17683), UINT16_C(45334), UINT16_C(64079) },
      UINT16_C(28197),
      { UINT16_C( 3295), UINT16_C(15652), UINT16_C( 3675), UINT16_C(51250), UINT16_C(23933), UINT16_C( 9663), UINT16_C( 3118), UINT16_C( 8043) } },
    { { UINT16_C(18396), UINT16_C(16510), UINT16_C(15761), UINT16_C(12772), UINT16_C( 2859), UINT16_C(49835), UINT16_C(24432), UINT16_C(50392) },
      UINT16_C(22340),
      { UINT16_C(55920), UINT16_C(62328), UINT16_C(41348), UINT16_C(48272), UINT16_C(37996), UINT16_C(53868), UINT16_C(27072), UINT16_C(45408) } },
    { { UINT16_C( 3686), UINT16_C(57354), UINT16_C( 7621), UINT16_C(56101), UINT16_C(29902), UINT16_C(62677), UINT16_C(45538), UINT16_C(24635) },
      UINT16_C(52466),
      { UINT16_C(58476), UINT16_C(49524), UINT16_C( 8250), UINT16_C(42234), UINT16_C(37564), UINT16_C(11610), UINT16_C(16292), UINT16_C(64454) } },
    { { UINT16_C(54941), UINT16_C(51709), UINT16_C(43489), UINT16_C(20875), UINT16_C(25352), UINT16_C(19477), UINT16_C(31675), UINT16_C(50523) },
      UINT16_C( 8283),
      { UINT16_C(59855), UINT16_C(27887), UINT16_C(33531), UINT16_C(23657), UINT16_C(13272), UINT16_C(43895), UINT16_C(23417), UINT16_C(34649) } },
    { { UINT16_C(32995), UINT16_C(45563), UINT16_C(53493), UINT16_C(55205), UINT16_C(57730), UINT16_C(29752), UINT16_C(54701), UINT16_C(43850) },
      UINT16_C(11166),
      { UINT16_C(44314), UINT16_C(  490), UINT16_C( 7734), UINT16_C(52950), UINT16_C( 1084), UINT16_C( 8848), UINT16_C(61382), UINT16_C( 9644) } },
    { { UINT16_C(10836), UINT16_C(23676), UINT16_C(37261), UINT16_C(18600), UINT16_C(  780), UINT16_C(26638), UINT16_C(61731), UINT16_C( 7912) },
      UINT16_C(56738),
      { UINT16_C(19752), UINT16_C(37496), UINT16_C(54330), UINT16_C(  592), UINT16_C(18840), UINT16_C(61148), UINT16_C(53030), UINT16_C(54992) } },
    { { UINT16_C(18671), UINT16_C(29109), UINT16_C(60713), UINT16_C(55013), UINT16_C(12226), UINT16_C(24961), UINT16_C(54618), UINT16_C(54923) },
      UINT16_C( 6193),
      { UINT16_C(23999), UINT16_C(48037), UINT16_C(15577), UINT16_C(39381), UINT16_C(21538), UINT16_C(49585), UINT16_C(17978), UINT16_C( 6299) } },
    { { UINT16_C(55911), UINT16_C(29537), UINT16_C(28637), UINT16_C(  475), UINT16_C(50272), UINT16_C(  543), UINT16_C( 3745), UINT16_C(22090) },
      UINT16_C(29567),
      { UINT16_C(40473), UINT16_C(53279), UINT16_C(50595), UINT16_C(19621), UINT16_C(35744), UINT16_C(64097), UINT16_C(38111), UINT16_C( 3254) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    uint16_t b = test_vec[i].b;
    simde_uint16x8_t r = simde_vmulq_n_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    uint16_t b = simde_test_codegen_random_u16();
    simde_uint16x8_t r = simde_vmulq_n_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmulq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 593693436), UINT32_C(2539985187), UINT32_C(3612342030), UINT32_C(2996367597) },
      UINT32_C(1522838875),
      { UINT32_C(2207331220), UINT32_C(2948109937), UINT32_C(2786674682), UINT32_C(2661403967) } },
    { { UINT32_C(1145577779), UINT32_C(2632968636), UINT32_C(1447235673), UINT32_C(1048160027) },
      UINT32_C(3470122688),
      { UINT32_C(1817321536), UINT32_C(2181846272), UINT32_C( 310800576), UINT32_C( 496877120) } },
    { { UINT32_C(3282445526), UINT32_C(1869954580), UINT32_C( 516504299), UINT32_C( 392302939) },
      UINT32_C(1421038074),
      { UINT32_C(2609491708), UINT32_C(3911119752), UINT32_C( 175694974), UINT32_C(3689135582) } },
    { { UINT32_C(2108356450), UINT32_C(1589322654), UINT32_C(3626799106), UINT32_C(3382432436) },
      UINT32_C(4231532560),
      { UINT32_C( 529896992), UINT32_C(4034664928), UINT32_C(3292078112), UINT32_C(2655546176) } },
    { { UINT32_C(2786722378), UINT32_C( 247299347), UINT32_C( 811758030), UINT32_C( 112004200) },
      UINT32_C( 828663855),
      { UINT32_C( 513571734), UINT32_C( 772124285), UINT32_C(3267794130), UINT32_C(1198491416) } },
    { { UINT32_C(2903085304), UINT32_C(1937155171), UINT32_C(4285509301), UINT32_C(3299183280) },
      UINT32_C(3587334919),
      { UINT32_C(2982338248), UINT32_C(1107740597), UINT32_C( 370656755), UINT32_C(2575882960) } },
    { { UINT32_C(1007039700), UINT32_C(1866642240), UINT32_C( 346138140), UINT32_C(2579606070) },
      UINT32_C(  67974991),
      { UINT32_C(3657947500), UINT32_C(3294105792), UINT32_C(4160636580), UINT32_C(2333286570) } },
    { { UINT32_C(2516810982), UINT32_C( 224045318), UINT32_C(3772984332), UINT32_C(2686249312) },
      UINT32_C(3088080540),
      { UINT32_C(3495727144), UINT32_C(1303327656), UINT32_C(3579526992), UINT32_C(3310319232) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    uint32_t b = test_vec[i].b;
    simde_uint32x4_t r = simde_vmulq_n_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    uint32_t b = simde_test_codegen_random_u32();
    simde_uint32x4_t r = simde_vmulq_n_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_n_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmul_n_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_n_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmulq_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
