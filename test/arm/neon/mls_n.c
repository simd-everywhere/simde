#define SIMDE_TEST_ARM_NEON_INSN mls_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mls_n.h"

static int
test_simde_vmls_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 c;
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -647.13), SIMDE_FLOAT32_C(   366.97) },
      { SIMDE_FLOAT32_C(   527.74), SIMDE_FLOAT32_C(   503.00) },
      SIMDE_FLOAT32_C(   833.05),
      { SIMDE_FLOAT32_C(-440280.91), SIMDE_FLOAT32_C(-418657.19) } },
    { { SIMDE_FLOAT32_C(   812.52), SIMDE_FLOAT32_C(  -705.38) },
      { SIMDE_FLOAT32_C(   240.26), SIMDE_FLOAT32_C(  -162.82) },
      SIMDE_FLOAT32_C(  -435.62),
      { SIMDE_FLOAT32_C(105474.58), SIMDE_FLOAT32_C(-71633.03) } },
    { { SIMDE_FLOAT32_C(   542.21), SIMDE_FLOAT32_C(  -924.21) },
      { SIMDE_FLOAT32_C(   795.16), SIMDE_FLOAT32_C(  -886.10) },
      SIMDE_FLOAT32_C(   343.92),
      { SIMDE_FLOAT32_C(-272929.22), SIMDE_FLOAT32_C(303823.28) } },
    { { SIMDE_FLOAT32_C(    27.23), SIMDE_FLOAT32_C(  -901.56) },
      { SIMDE_FLOAT32_C(  -640.14), SIMDE_FLOAT32_C(  -584.65) },
      SIMDE_FLOAT32_C(   126.02),
      { SIMDE_FLOAT32_C( 80697.67), SIMDE_FLOAT32_C( 72776.03) } },
    { { SIMDE_FLOAT32_C(   958.88), SIMDE_FLOAT32_C(  -573.62) },
      { SIMDE_FLOAT32_C(  -928.01), SIMDE_FLOAT32_C(   687.70) },
      SIMDE_FLOAT32_C(   -84.58),
      { SIMDE_FLOAT32_C(-77532.20), SIMDE_FLOAT32_C( 57592.05) } },
    { { SIMDE_FLOAT32_C(   252.63), SIMDE_FLOAT32_C(  -744.64) },
      { SIMDE_FLOAT32_C(   832.67), SIMDE_FLOAT32_C(  -922.69) },
      SIMDE_FLOAT32_C(  -514.34),
      { SIMDE_FLOAT32_C(428528.12), SIMDE_FLOAT32_C(-475321.03) } },
    { { SIMDE_FLOAT32_C(  -765.80), SIMDE_FLOAT32_C(  -569.82) },
      { SIMDE_FLOAT32_C(   852.63), SIMDE_FLOAT32_C(   761.94) },
      SIMDE_FLOAT32_C(   933.18),
      { SIMDE_FLOAT32_C(-796423.06), SIMDE_FLOAT32_C(-711597.00) } },
    { { SIMDE_FLOAT32_C(   685.68), SIMDE_FLOAT32_C(   574.46) },
      { SIMDE_FLOAT32_C(  -772.20), SIMDE_FLOAT32_C(   -74.06) },
      SIMDE_FLOAT32_C(  -588.35),
      { SIMDE_FLOAT32_C(-453638.16), SIMDE_FLOAT32_C(-42998.74) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32 c = test_vec[i].c;
    simde_float32x2_t r = simde_vmls_n_f32(a, b, c);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32 c = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32x2_t r = simde_vmls_n_f32(a, b, c);

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t c;
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 24582), -INT16_C(   903), -INT16_C( 30731), -INT16_C(  8747) },
      { -INT16_C(  1631),  INT16_C(  8603),  INT16_C(  8206),  INT16_C( 27376) },
       INT16_C(  6307),
      { -INT16_C( 27017),  INT16_C(  3784), -INT16_C( 12533),  INT16_C( 18181) } },
    { { -INT16_C( 15101), -INT16_C(  9275), -INT16_C(  5708), -INT16_C(  5227) },
      {  INT16_C(  3127),  INT16_C( 20723), -INT16_C(  4753), -INT16_C(  5905) },
      -INT16_C(  6934),
      { -INT16_C( 24899),  INT16_C( 29095),  INT16_C(  1598),  INT16_C(  9503) } },
    { { -INT16_C( 16529),  INT16_C(  4289),  INT16_C( 23737), -INT16_C( 14543) },
      {  INT16_C(  8573),  INT16_C(  8241),  INT16_C( 13626), -INT16_C(    27) },
      -INT16_C( 26352),
      { -INT16_C(  3425), -INT16_C( 15183),  INT16_C( 24345), -INT16_C(  5151) } },
    { { -INT16_C( 23064),  INT16_C(  8068),  INT16_C( 30897),  INT16_C(  8303) },
      {  INT16_C( 24165),  INT16_C( 20233),  INT16_C( 30786),  INT16_C(   783) },
      -INT16_C( 14199),
      {  INT16_C( 14811), -INT16_C( 13389), -INT16_C( 29345), -INT16_C( 15000) } },
    { { -INT16_C( 17825), -INT16_C(  9073), -INT16_C( 16164),  INT16_C(  5884) },
      { -INT16_C(  7435),  INT16_C(  1301), -INT16_C(   645),  INT16_C(   170) },
       INT16_C( 23324),
      { -INT16_C( 12141), -INT16_C( 10429),  INT16_C( 20072), -INT16_C( 27036) } },
    { { -INT16_C( 29832), -INT16_C(  8836), -INT16_C( 31255),  INT16_C( 11053) },
      {  INT16_C( 15613), -INT16_C( 31186), -INT16_C( 29436), -INT16_C( 27839) },
       INT16_C(  7530),
      { -INT16_C( 24138),  INT16_C(  6256), -INT16_C( 20927), -INT16_C( 10941) } },
    { {  INT16_C( 26195),  INT16_C( 18739),  INT16_C( 18504), -INT16_C( 15282) },
      { -INT16_C(  1723),  INT16_C( 25028),  INT16_C( 15444), -INT16_C( 12052) },
      -INT16_C( 10983),
      { -INT16_C( 23146), -INT16_C( 22257), -INT16_C( 32748),  INT16_C(   322) } },
    { {  INT16_C( 18005),  INT16_C( 21248),  INT16_C( 11906), -INT16_C( 31015) },
      {  INT16_C(  6843),  INT16_C(  9497),  INT16_C( 27959),  INT16_C( 27276) },
      -INT16_C( 11082),
      {  INT16_C( 26979),  INT16_C( 16186), -INT16_C(   664), -INT16_C( 10415) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int16x4_t r = simde_vmls_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    int16_t c = simde_test_codegen_random_i16();
    simde_int16x4_t r = simde_vmls_n_s16(a, b, c);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t c;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(   141032270),  INT32_C(  1381522685) },
      { -INT32_C(  1306377064),  INT32_C(   435714073) },
      -INT32_C(  1538819125),
      { -INT32_C(   649160662),  INT32_C(    95297066) } },
    { {  INT32_C(   465502977), -INT32_C(  1266092504) },
      {  INT32_C(   327761505),  INT32_C(  1074471234) },
       INT32_C(   378692478),
      { -INT32_C(  2118071229),  INT32_C(  1032720812) } },
    { { -INT32_C(  1043811160), -INT32_C(   136593108) },
      {  INT32_C(  1033642556),  INT32_C(  1314413349) },
      -INT32_C(  1308434351),
      { -INT32_C(  1460314196),  INT32_C(  1843169911) } },
    { {  INT32_C(  1640401694),  INT32_C(   732025261) },
      { -INT32_C(   599706828),  INT32_C(   345901799) },
       INT32_C(   118192587),
      {  INT32_C(  1235442914),  INT32_C(  1446706560) } },
    { { -INT32_C(  1052465253),  INT32_C(  1410309378) },
      { -INT32_C(  1677323907),  INT32_C(  1258146973) },
      -INT32_C(   764043619),
      { -INT32_C(   895498254),  INT32_C(  1683962553) } },
    { { -INT32_C(  1196509487), -INT32_C(  1949545280) },
      {  INT32_C(  1637013701), -INT32_C(  2111645825) },
      -INT32_C(   237620876),
      { -INT32_C(  1124546419),  INT32_C(   899242036) } },
    { { -INT32_C(   544351166),  INT32_C(  1177127593) },
      { -INT32_C(   115827160),  INT32_C(   364037973) },
      -INT32_C(   643727853),
      { -INT32_C(   440766646),  INT32_C(  1112795482) } },
    { { -INT32_C(   700828842),  INT32_C(  2119719946) },
      { -INT32_C(   814731635), -INT32_C(  1280312054) },
      -INT32_C(  1325737848),
      { -INT32_C(  1784119186), -INT32_C(  1886028102) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int32x2_t r = simde_vmls_n_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    int32_t c = simde_test_codegen_random_i32();
    simde_int32x2_t r = simde_vmls_n_s32(a, b, c);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t c;
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C( 4727), UINT16_C(52394), UINT16_C(23769), UINT16_C(60897) },
      { UINT16_C(33498), UINT16_C(12742), UINT16_C(  182), UINT16_C(49159) },
      UINT16_C(24412),
      { UINT16_C( 9759), UINT16_C(28546), UINT16_C(37233), UINT16_C(21085) } },
    { { UINT16_C(59711), UINT16_C(44941), UINT16_C(38840), UINT16_C(26540) },
      { UINT16_C(13387), UINT16_C(17728), UINT16_C(47077), UINT16_C(36695) },
      UINT16_C(12675),
      { UINT16_C(52190), UINT16_C(65485), UINT16_C(43145), UINT16_C(26407) } },
    { { UINT16_C(25835), UINT16_C(50462), UINT16_C(58599), UINT16_C(40438) },
      { UINT16_C(64996), UINT16_C(16477), UINT16_C(40028), UINT16_C(59689) },
      UINT16_C(57675),
      { UINT16_C(40735), UINT16_C(11487), UINT16_C(14835), UINT16_C(17907) } },
    { { UINT16_C(63617), UINT16_C(52297), UINT16_C(35116), UINT16_C( 4369) },
      { UINT16_C(26688), UINT16_C(50080), UINT16_C(35737), UINT16_C(46887) },
      UINT16_C( 3665),
      { UINT16_C(31809), UINT16_C( 9897), UINT16_C(65475), UINT16_C(64442) } },
    { { UINT16_C(18331), UINT16_C(32683), UINT16_C( 2373), UINT16_C(41407) },
      { UINT16_C(59557), UINT16_C(61835), UINT16_C( 3274), UINT16_C( 5097) },
      UINT16_C( 5592),
      { UINT16_C(29539), UINT16_C(19299), UINT16_C(44245), UINT16_C(47143) } },
    { { UINT16_C(59804), UINT16_C(56359), UINT16_C(51025), UINT16_C(60319) },
      { UINT16_C(50771), UINT16_C(42146), UINT16_C(16085), UINT16_C(33003) },
      UINT16_C(12477),
      { UINT16_C(61013), UINT16_C(61581), UINT16_C(29712), UINT16_C(44576) } },
    { { UINT16_C(32137), UINT16_C(12242), UINT16_C(23909), UINT16_C(12064) },
      { UINT16_C( 2409), UINT16_C(16706), UINT16_C(56862), UINT16_C(17706) },
      UINT16_C(31674),
      { UINT16_C(13375), UINT16_C( 4062), UINT16_C(37273), UINT16_C(49308) } },
    { { UINT16_C(22797), UINT16_C(24678), UINT16_C( 2336), UINT16_C(62724) },
      { UINT16_C(61255), UINT16_C( 1141), UINT16_C(65312), UINT16_C(62081) },
      UINT16_C(59182),
      { UINT16_C(18763), UINT16_C(   96), UINT16_C(20832), UINT16_C(64214) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    uint16_t c = test_vec[i].c;
    simde_uint16x4_t r = simde_vmls_n_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    uint16_t c = simde_test_codegen_random_u16();
    simde_uint16x4_t r = simde_vmls_n_u16(a, b, c);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmls_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t c;
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3088469583), UINT32_C(1979275607) },
      { UINT32_C(4072350519), UINT32_C(  88852638) },
      UINT32_C( 739142440),
      { UINT32_C( 840880311), UINT32_C(3567515303) } },
    { { UINT32_C(3592115552), UINT32_C(3688184665) },
      { UINT32_C(2093089581), UINT32_C(2822035537) },
      UINT32_C(1763519793),
      { UINT32_C( 156291267), UINT32_C(2776930008) } },
    { { UINT32_C(4015773776), UINT32_C(3371476640) },
      { UINT32_C(1928593938), UINT32_C(2957512791) },
      UINT32_C(2039160139),
      { UINT32_C(4225577738), UINT32_C(4223730211) } },
    { { UINT32_C(1911901472), UINT32_C(1461266982) },
      { UINT32_C(2831169367), UINT32_C(2962692879) },
      UINT32_C(3564669890),
      { UINT32_C( 896999474), UINT32_C(1574798280) } },
    { { UINT32_C(3829820813), UINT32_C(3365179261) },
      { UINT32_C(3443597484), UINT32_C(2470328173) },
      UINT32_C(3102431329),
      { UINT32_C( 494529633), UINT32_C(1642403632) } },
    { { UINT32_C(2657135503), UINT32_C(2303653831) },
      { UINT32_C( 257804162), UINT32_C(2985534260) },
      UINT32_C(3749283890),
      { UINT32_C(1101046827), UINT32_C(3916527519) } },
    { { UINT32_C( 363641768), UINT32_C(1403644658) },
      { UINT32_C(3507196994), UINT32_C( 108031039) },
      UINT32_C(3868180067),
      { UINT32_C(2303420962), UINT32_C(1420315797) } },
    { { UINT32_C(3119901829), UINT32_C(3261786512) },
      { UINT32_C( 430040177), UINT32_C(2435730847) },
      UINT32_C(2061817656),
      { UINT32_C(3641511117), UINT32_C( 897410504) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    uint32_t c = test_vec[i].c;
    simde_uint32x2_t r = simde_vmls_n_u32(a, b, c);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    uint32_t c = simde_test_codegen_random_u32();
    simde_uint32x2_t r = simde_vmls_n_u32(a, b, c);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 c;
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -610.67), SIMDE_FLOAT32_C(  -418.32), SIMDE_FLOAT32_C(   241.04), SIMDE_FLOAT32_C(  -742.03) },
      { SIMDE_FLOAT32_C(   299.89), SIMDE_FLOAT32_C(   809.28), SIMDE_FLOAT32_C(   909.30), SIMDE_FLOAT32_C(  -915.75) },
      SIMDE_FLOAT32_C(  -135.47),
      { SIMDE_FLOAT32_C( 40015.43), SIMDE_FLOAT32_C(109214.84), SIMDE_FLOAT32_C(123423.91), SIMDE_FLOAT32_C(-124798.69) } },
    { { SIMDE_FLOAT32_C(   356.62), SIMDE_FLOAT32_C(  -395.86), SIMDE_FLOAT32_C(   488.21), SIMDE_FLOAT32_C(   856.70) },
      { SIMDE_FLOAT32_C(   660.83), SIMDE_FLOAT32_C(   136.39), SIMDE_FLOAT32_C(  -671.61), SIMDE_FLOAT32_C(   269.07) },
      SIMDE_FLOAT32_C(  -547.11),
      { SIMDE_FLOAT32_C(361903.31), SIMDE_FLOAT32_C( 74224.47), SIMDE_FLOAT32_C(-366956.31), SIMDE_FLOAT32_C(148067.59) } },
    { { SIMDE_FLOAT32_C(   205.06), SIMDE_FLOAT32_C(   798.89), SIMDE_FLOAT32_C(   952.13), SIMDE_FLOAT32_C(   281.01) },
      { SIMDE_FLOAT32_C(   151.61), SIMDE_FLOAT32_C(   903.69), SIMDE_FLOAT32_C(  -949.31), SIMDE_FLOAT32_C(   576.79) },
      SIMDE_FLOAT32_C(   114.60),
      { SIMDE_FLOAT32_C(-17169.45), SIMDE_FLOAT32_C(-102763.98), SIMDE_FLOAT32_C(109743.05), SIMDE_FLOAT32_C(-65819.12) } },
    { { SIMDE_FLOAT32_C(   529.72), SIMDE_FLOAT32_C(   899.70), SIMDE_FLOAT32_C(  -645.73), SIMDE_FLOAT32_C(  -185.54) },
      { SIMDE_FLOAT32_C(  -710.98), SIMDE_FLOAT32_C(   -64.06), SIMDE_FLOAT32_C(  -944.50), SIMDE_FLOAT32_C(  -453.01) },
      SIMDE_FLOAT32_C(  -764.17),
      { SIMDE_FLOAT32_C(-542779.81), SIMDE_FLOAT32_C(-48053.03), SIMDE_FLOAT32_C(-722404.31), SIMDE_FLOAT32_C(-346362.19) } },
    { { SIMDE_FLOAT32_C(   864.78), SIMDE_FLOAT32_C(  -543.71), SIMDE_FLOAT32_C(  -679.92), SIMDE_FLOAT32_C(  -270.68) },
      { SIMDE_FLOAT32_C(   812.92), SIMDE_FLOAT32_C(   -75.78), SIMDE_FLOAT32_C(  -782.47), SIMDE_FLOAT32_C(   669.62) },
      SIMDE_FLOAT32_C(  -414.96),
      { SIMDE_FLOAT32_C(338194.06), SIMDE_FLOAT32_C(-31989.38), SIMDE_FLOAT32_C(-325373.62), SIMDE_FLOAT32_C(277594.81) } },
    { { SIMDE_FLOAT32_C(   353.92), SIMDE_FLOAT32_C(   998.00), SIMDE_FLOAT32_C(   854.11), SIMDE_FLOAT32_C(   806.81) },
      { SIMDE_FLOAT32_C(   203.06), SIMDE_FLOAT32_C(   653.00), SIMDE_FLOAT32_C(   758.94), SIMDE_FLOAT32_C(  -515.93) },
      SIMDE_FLOAT32_C(  -195.39),
      { SIMDE_FLOAT32_C( 40029.82), SIMDE_FLOAT32_C(128587.67), SIMDE_FLOAT32_C(149143.39), SIMDE_FLOAT32_C(-100000.75) } },
    { { SIMDE_FLOAT32_C(   662.63), SIMDE_FLOAT32_C(  -465.25), SIMDE_FLOAT32_C(  -618.60), SIMDE_FLOAT32_C(  -222.77) },
      { SIMDE_FLOAT32_C(  -935.53), SIMDE_FLOAT32_C(  -718.90), SIMDE_FLOAT32_C(   131.50), SIMDE_FLOAT32_C(  -121.07) },
      SIMDE_FLOAT32_C(  -429.88),
      { SIMDE_FLOAT32_C(-401503.03), SIMDE_FLOAT32_C(-309506.00), SIMDE_FLOAT32_C( 55910.62), SIMDE_FLOAT32_C(-52268.34) } },
    { { SIMDE_FLOAT32_C(  -932.56), SIMDE_FLOAT32_C(   -65.57), SIMDE_FLOAT32_C(   117.12), SIMDE_FLOAT32_C(  -696.73) },
      { SIMDE_FLOAT32_C(  -200.78), SIMDE_FLOAT32_C(   573.41), SIMDE_FLOAT32_C(  -376.65), SIMDE_FLOAT32_C(   528.53) },
      SIMDE_FLOAT32_C(   386.33),
      { SIMDE_FLOAT32_C( 76634.77), SIMDE_FLOAT32_C(-221591.03), SIMDE_FLOAT32_C(145628.31), SIMDE_FLOAT32_C(-204883.73) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32 c = test_vec[i].c;
    simde_float32x4_t r = simde_vmlsq_n_f32(a, b, c);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32 c = simde_test_codegen_random_f32(-1000.0f, 1000.0f);
    simde_float32x4_t r = simde_vmlsq_n_f32(a, b, c);

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_f32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t c;
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 27973), -INT16_C( 27930),  INT16_C(   514),  INT16_C(  6899), -INT16_C(   934), -INT16_C(  8258),  INT16_C( 19722), -INT16_C(  6522) },
      {  INT16_C( 26730), -INT16_C(  4739), -INT16_C(  5488),  INT16_C(  8944),  INT16_C( 28134), -INT16_C( 31589), -INT16_C( 13047), -INT16_C( 15276) },
       INT16_C( 14943),
      { -INT16_C( 12443),  INT16_C(  8067),  INT16_C( 22162), -INT16_C( 15389),  INT16_C(  6144), -INT16_C( 29639),  INT16_C( 11443),  INT16_C(   858) } },
    { {  INT16_C( 25174),  INT16_C( 19004), -INT16_C( 26756),  INT16_C( 14918),  INT16_C( 20598), -INT16_C(   889), -INT16_C(  3530), -INT16_C( 19612) },
      { -INT16_C(  2849), -INT16_C( 12387), -INT16_C( 31722), -INT16_C( 20164),  INT16_C( 17672),  INT16_C( 23679), -INT16_C(  8695),  INT16_C( 24727) },
      -INT16_C( 11456),
      {  INT16_C( 23958), -INT16_C(  1028),  INT16_C( 28668),  INT16_C( 30534),  INT16_C( 30326),  INT16_C( 12231),  INT16_C(  1270),  INT16_C(  6308) } },
    { { -INT16_C( 16982), -INT16_C(  3990), -INT16_C(  7945),  INT16_C( 32577),  INT16_C( 30684),  INT16_C( 16497),  INT16_C( 20523), -INT16_C( 14283) },
      {  INT16_C( 19231),  INT16_C( 23628),  INT16_C( 21757),  INT16_C( 31905), -INT16_C( 21583),  INT16_C( 18522), -INT16_C( 25845), -INT16_C( 19173) },
      -INT16_C( 31144),
      { -INT16_C( 20222),  INT16_C( 28234),  INT16_C( 15359),  INT16_C( 25065), -INT16_C( 13052),  INT16_C( 17793),  INT16_C( 16995),  INT16_C( 25837) } },
    { {  INT16_C( 20389), -INT16_C(  6554),  INT16_C( 17358),  INT16_C( 16222), -INT16_C( 30333), -INT16_C( 18289), -INT16_C( 20655), -INT16_C( 25084) },
      {  INT16_C(   267), -INT16_C( 21262), -INT16_C( 23683), -INT16_C( 10409),  INT16_C( 25323),  INT16_C(  1906), -INT16_C( 13801), -INT16_C( 17011) },
      -INT16_C(  3302),
      { -INT16_C( 15481), -INT16_C( 24622),  INT16_C(   540), -INT16_C( 13432),  INT16_C( 27813), -INT16_C( 16133),  INT16_C( 21499), -INT16_C( 31054) } },
    { { -INT16_C(  5981),  INT16_C(   310), -INT16_C( 17880), -INT16_C( 18550), -INT16_C(  9102),  INT16_C( 30310),  INT16_C( 29050),  INT16_C( 27767) },
      { -INT16_C(  3042),  INT16_C( 29968), -INT16_C(  1076),  INT16_C( 16088), -INT16_C(  4350), -INT16_C( 28919),  INT16_C(  9132),  INT16_C( 20611) },
      -INT16_C( 18165),
      { -INT16_C( 17063),  INT16_C( 27014),  INT16_C( 31844), -INT16_C(  5054),  INT16_C(  9564), -INT16_C( 12285), -INT16_C( 25322),  INT16_C( 19414) } },
    { {  INT16_C( 13137), -INT16_C(  9101), -INT16_C(  6421),  INT16_C( 20920),  INT16_C( 12892), -INT16_C( 11069), -INT16_C(  7778), -INT16_C( 20792) },
      { -INT16_C( 27562),  INT16_C( 11946), -INT16_C( 21293), -INT16_C(  9186), -INT16_C( 13764), -INT16_C( 16385),  INT16_C(  2586),  INT16_C( 27768) },
      -INT16_C(  5058),
      { -INT16_C(   387), -INT16_C( 10425), -INT16_C( 30767),  INT16_C( 23156), -INT16_C(  6188),  INT16_C( 16641),  INT16_C( 30546), -INT16_C( 13896) } },
    { {  INT16_C( 10568),  INT16_C(   210),  INT16_C( 11898),  INT16_C( 15666), -INT16_C( 12286), -INT16_C( 13538),  INT16_C( 30079),  INT16_C( 10591) },
      {  INT16_C( 12963), -INT16_C( 15915),  INT16_C(  4366),  INT16_C(  3468), -INT16_C( 22832),  INT16_C( 18712),  INT16_C( 22034),  INT16_C( 23093) },
       INT16_C(  1919),
      { -INT16_C( 27285),  INT16_C(  1319),  INT16_C( 22152), -INT16_C( 20290),  INT16_C( 24274), -INT16_C(  8138),  INT16_C( 17553), -INT16_C(  2540) } },
    { { -INT16_C(  1702), -INT16_C( 29643),  INT16_C( 14391),  INT16_C( 21853), -INT16_C(  9213),  INT16_C( 25290),  INT16_C( 28165), -INT16_C(  9579) },
      { -INT16_C( 23761), -INT16_C( 17428), -INT16_C( 17231), -INT16_C( 13982),  INT16_C( 29701),  INT16_C( 14879), -INT16_C( 24881),  INT16_C( 10561) },
       INT16_C( 30615),
      { -INT16_C(  8287),  INT16_C(     1), -INT16_C( 23344), -INT16_C(   369),  INT16_C(  6672), -INT16_C( 20095), -INT16_C( 30484),  INT16_C( 20030) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int16x8_t r = simde_vmlsq_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    int16_t c = simde_test_codegen_random_i16();
    simde_int16x8_t r = simde_vmlsq_n_s16(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t c;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   330288822), -INT32_C(   286281180), -INT32_C(  1453525996), -INT32_C(  1169322802) },
      { -INT32_C(  1451753913), -INT32_C(   434209593), -INT32_C(   125506121), -INT32_C(   865133802) },
       INT32_C(   249503466),
      { -INT32_C(  1168371760),  INT32_C(  1897484862), -INT32_C(   677955378),  INT32_C(   191379122) } },
    { { -INT32_C(   436416816), -INT32_C(  1852941886),  INT32_C(   743168997), -INT32_C(  1596538151) },
      { -INT32_C(   158927809), -INT32_C(   135394591),  INT32_C(   281304614),  INT32_C(  1293853564) },
       INT32_C(   875698802),
      { -INT32_C(   389569342),  INT32_C(   679520144), -INT32_C(  1478618375),  INT32_C(   241130913) } },
    { {  INT32_C(  1489354867),  INT32_C(  1971655068),  INT32_C(   303455187),  INT32_C(   805870671) },
      { -INT32_C(   853018713), -INT32_C(   773985451),  INT32_C(    18807695), -INT32_C(  1992994795) },
      -INT32_C(  1377699055),
      {  INT32_C(    75927900), -INT32_C(  1453909513), -INT32_C(   491556268),  INT32_C(   981775338) } },
    { { -INT32_C(   551393780),  INT32_C(   284309697),  INT32_C(  2084633301),  INT32_C(  1179216113) },
      { -INT32_C(   501733805),  INT32_C(   920860193), -INT32_C(  1732306553),  INT32_C(   541434132) },
      -INT32_C(   906008825),
      { -INT32_C(  1587481401),  INT32_C(  1377138394), -INT32_C(    11995356),  INT32_C(   967243109) } },
    { {  INT32_C(  1977217440), -INT32_C(   571401492), -INT32_C(   719046014), -INT32_C(  2118632352) },
      { -INT32_C(   105407630), -INT32_C(   929990732),  INT32_C(   535352856), -INT32_C(   555161538) },
      -INT32_C(   984366375),
      { -INT32_C(  2055943682),  INT32_C(  1250966360),  INT32_C(  1958776874),  INT32_C(   204628946) } },
    { {  INT32_C(  1587758300), -INT32_C(   567031938),  INT32_C(  1969220355),  INT32_C(   997136007) },
      { -INT32_C(  1526464371),  INT32_C(   365292759), -INT32_C(  1359761964),  INT32_C(  1265845871) },
       INT32_C(   145299082),
      {  INT32_C(  1297734362),  INT32_C(   221815192), -INT32_C(   736100677), -INT32_C(  1342794575) } },
    { { -INT32_C(   521740835),  INT32_C(  1331054024), -INT32_C(   376715941), -INT32_C(  1668378683) },
      {  INT32_C(  1353798523),  INT32_C(  1895736321),  INT32_C(  1958506986),  INT32_C(  1702651272) },
       INT32_C(   189162050),
      {  INT32_C(   345522727), -INT32_C(   811492474),  INT32_C(  2036257543),  INT32_C(   946754229) } },
    { {  INT32_C(    56269991),  INT32_C(   653059425), -INT32_C(   255624588), -INT32_C(   817859378) },
      {  INT32_C(    54476313),  INT32_C(   930675631), -INT32_C(  1549929375), -INT32_C(    22092969) },
      -INT32_C(   536802945),
      {  INT32_C(   263384384),  INT32_C(  1163911824),  INT32_C(  1668207957),  INT32_C(  1294507429) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int32x4_t r = simde_vmlsq_n_s32(a, b, c);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    int32_t c = simde_test_codegen_random_i32();
    simde_int32x4_t r = simde_vmlsq_n_s32(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vmlsq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t c;
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(42783), UINT16_C( 6825), UINT16_C(46722), UINT16_C(15064), UINT16_C(33458), UINT16_C(27811), UINT16_C(26954), UINT16_C(34790) },
      { UINT16_C(31524), UINT16_C(31430), UINT16_C(44756), UINT16_C(14837), UINT16_C(58761), UINT16_C(56912), UINT16_C(24086), UINT16_C(13841) },
      UINT16_C(47621),
      { UINT16_C( 5995), UINT16_C(55499), UINT16_C(17502), UINT16_C( 5903), UINT16_C(32005), UINT16_C(62739), UINT16_C(38620), UINT16_C( 8081) } },
    { { UINT16_C(34896), UINT16_C(10352), UINT16_C( 9154), UINT16_C(26026), UINT16_C(62607), UINT16_C(30159), UINT16_C(62332), UINT16_C(17136) },
      { UINT16_C(50285), UINT16_C(25328), UINT16_C(31485), UINT16_C(20039), UINT16_C(24152), UINT16_C(27052), UINT16_C(45716), UINT16_C(58404) },
      UINT16_C(37946),
      { UINT16_C(  926), UINT16_C(65040), UINT16_C(  624), UINT16_C(40340), UINT16_C(46239), UINT16_C( 5335), UINT16_C(60916), UINT16_C(49864) } },
    { { UINT16_C(64524), UINT16_C(47031), UINT16_C(18273), UINT16_C(12459), UINT16_C(10172), UINT16_C(44324), UINT16_C(37225), UINT16_C(23153) },
      { UINT16_C(28660), UINT16_C(15316), UINT16_C(11453), UINT16_C(27033), UINT16_C(11670), UINT16_C(47643), UINT16_C(21777), UINT16_C( 7758) },
      UINT16_C( 1617),
      { UINT16_C(55256), UINT16_C(53667), UINT16_C(45460), UINT16_C(12610), UINT16_C(14150), UINT16_C(10393), UINT16_C(16648), UINT16_C(61379) } },
    { { UINT16_C(46037), UINT16_C(32845), UINT16_C( 2531), UINT16_C( 1960), UINT16_C( 4534), UINT16_C(10393), UINT16_C(36203), UINT16_C(16279) },
      { UINT16_C(21704), UINT16_C(25196), UINT16_C(  701), UINT16_C(55695), UINT16_C(41404), UINT16_C( 2606), UINT16_C(32959), UINT16_C(37904) },
      UINT16_C(23859),
      { UINT16_C(10237), UINT16_C(43209), UINT16_C(54588), UINT16_C(48427), UINT16_C(36162), UINT16_C(27503), UINT16_C(33886), UINT16_C(61543) } },
    { { UINT16_C( 5652), UINT16_C(48231), UINT16_C( 7454), UINT16_C(47054), UINT16_C(14661), UINT16_C(56388), UINT16_C( 3193), UINT16_C(58672) },
      { UINT16_C(61038), UINT16_C(65255), UINT16_C(41927), UINT16_C(62879), UINT16_C(24237), UINT16_C(48757), UINT16_C(43250), UINT16_C( 1563) },
      UINT16_C(33471),
      { UINT16_C(22018), UINT16_C(16398), UINT16_C(56741), UINT16_C(47149), UINT16_C(48178), UINT16_C(22777), UINT16_C( 7147), UINT16_C(41227) } },
    { { UINT16_C(56771), UINT16_C(37280), UINT16_C(58772), UINT16_C(55498), UINT16_C(17346), UINT16_C(62180), UINT16_C(21288), UINT16_C( 4064) },
      { UINT16_C(42833), UINT16_C(61618), UINT16_C(24733), UINT16_C( 4686), UINT16_C(16414), UINT16_C(14779), UINT16_C(31302), UINT16_C( 2492) },
      UINT16_C(23639),
      { UINT16_C(58684), UINT16_C(52514), UINT16_C(42041), UINT16_C(38984), UINT16_C(45456), UINT16_C( 8279), UINT16_C(40286), UINT16_C(12540) } },
    { { UINT16_C(60314), UINT16_C(25921), UINT16_C(  963), UINT16_C(42920), UINT16_C(53750), UINT16_C(55034), UINT16_C(19424), UINT16_C(37758) },
      { UINT16_C( 6971), UINT16_C(35315), UINT16_C( 4397), UINT16_C(59593), UINT16_C( 4170), UINT16_C( 1634), UINT16_C(47385), UINT16_C(46178) },
      UINT16_C(42148),
      { UINT16_C(44494), UINT16_C(22933), UINT16_C(12015), UINT16_C(49892), UINT16_C(64142), UINT16_C(63538), UINT16_C(46044), UINT16_C(15542) } },
    { { UINT16_C(26393), UINT16_C(49575), UINT16_C(40207), UINT16_C( 2450), UINT16_C(29556), UINT16_C(62037), UINT16_C(36870), UINT16_C(63757) },
      { UINT16_C(14874), UINT16_C(58122), UINT16_C(21539), UINT16_C(34291), UINT16_C( 3419), UINT16_C(48447), UINT16_C(58305), UINT16_C(55905) },
      UINT16_C( 2379),
      { UINT16_C(30587), UINT16_C(58297), UINT16_C(48078), UINT16_C(16481), UINT16_C(22219), UINT16_C(18912), UINT16_C( 3451), UINT16_C(38306) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    uint16_t c = test_vec[i].c;
    simde_uint16x8_t r = simde_vmlsq_n_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    uint16_t c = simde_test_codegen_random_u16();
    simde_uint16x8_t r = simde_vmlsq_n_u16(a, b, c);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c;
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 782654107), UINT32_C(3097565795), UINT32_C( 424257292), UINT32_C(2857657248) },
      { UINT32_C( 989755206), UINT32_C( 994531836), UINT32_C(2015299607), UINT32_C(2105633506) },
      UINT32_C( 665528516),
      { UINT32_C(3949861123), UINT32_C(2963068275), UINT32_C(1608965488), UINT32_C(2274705048) } },
    { { UINT32_C(1340099650), UINT32_C(2473077235), UINT32_C(3527261324), UINT32_C( 806108211) },
      { UINT32_C(2892714901), UINT32_C(1025870427), UINT32_C(3099305716), UINT32_C( 299919054) },
      UINT32_C(2791358643),
      { UINT32_C(1279597331), UINT32_C(3326356562), UINT32_C( 374407152), UINT32_C(1103747625) } },
    { { UINT32_C(1966786793), UINT32_C(3091691397), UINT32_C(1239962803), UINT32_C(  66409639) },
      { UINT32_C(3544193758), UINT32_C(2408315841), UINT32_C( 362834786), UINT32_C( 347799595) },
      UINT32_C(1317664201),
      { UINT32_C( 962673307), UINT32_C(2200311804), UINT32_C(1958558401), UINT32_C(2499152868) } },
    { { UINT32_C( 537317741), UINT32_C(3429494565), UINT32_C( 567238467), UINT32_C( 989073529) },
      { UINT32_C(1841987595), UINT32_C( 394423019), UINT32_C( 875249259), UINT32_C(2692920627) },
      UINT32_C(2881587334),
      { UINT32_C( 850850731), UINT32_C(2704154659), UINT32_C(1381555009), UINT32_C( 433266631) } },
    { { UINT32_C(3128371831), UINT32_C(  64767881), UINT32_C(1648218199), UINT32_C(1020266320) },
      { UINT32_C(3713225330), UINT32_C(3289480848), UINT32_C(3110376243), UINT32_C(2472813851) },
      UINT32_C(3645758544),
      { UINT32_C(2269736663), UINT32_C(2488334985), UINT32_C(2197355623), UINT32_C( 293747424) } },
    { { UINT32_C(2061248803), UINT32_C(1255938810), UINT32_C(2475076641), UINT32_C(2406537727) },
      { UINT32_C(2337505624), UINT32_C( 809875476), UINT32_C( 767797725), UINT32_C(2819035269) },
      UINT32_C( 874701626),
      { UINT32_C(3499086643), UINT32_C( 103721586), UINT32_C(1111046415), UINT32_C(  75967709) } },
    { { UINT32_C( 528416765), UINT32_C(2863793579), UINT32_C( 909779934), UINT32_C(3116535204) },
      { UINT32_C( 602474309), UINT32_C( 911256752), UINT32_C(4141766588), UINT32_C( 942276923) },
      UINT32_C(2874648832),
      { UINT32_C(3124720381), UINT32_C( 685888939), UINT32_C( 158009310), UINT32_C( 719690404) } },
    { { UINT32_C(2354449070), UINT32_C(3519254573), UINT32_C(1670022429), UINT32_C(1015444364) },
      { UINT32_C(3698513439), UINT32_C(1775391022), UINT32_C(1386347858), UINT32_C(1425930662) },
      UINT32_C( 820007683),
      { UINT32_C(2423356241), UINT32_C(3149574819), UINT32_C(3737319207), UINT32_C(1415296154) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    uint32_t c = test_vec[i].c;
    simde_uint32x4_t r = simde_vmlsq_n_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    uint32_t c = simde_test_codegen_random_u32();
    simde_uint32x4_t r = simde_vmlsq_n_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmls_n_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsq_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
