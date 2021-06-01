#define SIMDE_TEST_ARM_NEON_INSN addhn

#include "test-neon.h"
#include "../../../simde/arm/neon/addhn.h"

static int
test_simde_vaddhn_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT16_C( 10191),  INT16_C(   527), -INT16_C( 15725), -INT16_C( 15434), -INT16_C( 29291), -INT16_C( 21715), -INT16_C( 19795),  INT16_C(    69) },
      { -INT16_C( 17904), -INT16_C( 30996),  INT16_C( 15212), -INT16_C( 23888), -INT16_C( 18775),  INT16_C( 22323), -INT16_C(  6945), -INT16_C( 20945) },
      { -INT8_C(  31), -INT8_C( 120), -INT8_C(   3),  INT8_C( 102),  INT8_C(  68),  INT8_C(   2), -INT8_C( 105), -INT8_C(  82) } },
    { {  INT16_C( 15884), -INT16_C( 24656),  INT16_C( 26369), -INT16_C( 27038), -INT16_C( 28428), -INT16_C( 23998), -INT16_C( 30910),  INT16_C( 21154) },
      { -INT16_C( 29119), -INT16_C( 21032), -INT16_C( 30263),  INT16_C( 29264), -INT16_C( 31937),  INT16_C(  7881), -INT16_C(  1944),  INT16_C( 29901) },
      { -INT8_C(  52),  INT8_C(  77), -INT8_C(  16),  INT8_C(   8),  INT8_C(  20), -INT8_C(  63),      INT8_MAX, -INT8_C(  57) } },
    { {  INT16_C( 32055),  INT16_C( 14355),  INT16_C( 30180), -INT16_C(  9778),  INT16_C(  4101),  INT16_C( 18555),  INT16_C(  7575), -INT16_C( 10086) },
      {  INT16_C( 29611),  INT16_C( 29830), -INT16_C( 10500),  INT16_C( 15335), -INT16_C( 20391), -INT16_C( 16038),  INT16_C( 10153), -INT16_C(  8139) },
      { -INT8_C(  16), -INT8_C(  84),  INT8_C(  76),  INT8_C(  21), -INT8_C(  64),  INT8_C(   9),  INT8_C(  69), -INT8_C(  72) } },
    { {  INT16_C( 18596), -INT16_C( 30440), -INT16_C(  6466), -INT16_C( 15518), -INT16_C(  8713), -INT16_C( 29173), -INT16_C( 22790), -INT16_C( 23193) },
      { -INT16_C(  4839),  INT16_C(  5401),  INT16_C(   195),  INT16_C(  7248), -INT16_C( 21839),  INT16_C( 23262),  INT16_C(  5073),  INT16_C( 30266) },
      {  INT8_C(  53), -INT8_C(  98), -INT8_C(  25), -INT8_C(  33), -INT8_C( 120), -INT8_C(  24), -INT8_C(  70),  INT8_C(  27) } },
    { {  INT16_C( 21084),  INT16_C(  6911),  INT16_C( 24888),  INT16_C( 12253), -INT16_C(  5826),  INT16_C( 14526),  INT16_C(  9615), -INT16_C( 22307) },
      { -INT16_C(  2542), -INT16_C( 10819),  INT16_C(  3575), -INT16_C( 22287), -INT16_C( 12360), -INT16_C( 30462),  INT16_C( 15587),  INT16_C( 16383) },
      {  INT8_C(  72), -INT8_C(  16),  INT8_C( 111), -INT8_C(  40), -INT8_C(  72), -INT8_C(  63),  INT8_C(  98), -INT8_C(  24) } },
    { { -INT16_C(   370), -INT16_C( 14759),  INT16_C( 13919), -INT16_C( 25098), -INT16_C( 19425), -INT16_C( 20779), -INT16_C( 19751), -INT16_C(  5290) },
      {  INT16_C(  5033), -INT16_C( 24384), -INT16_C( 20191), -INT16_C(  9912),  INT16_C( 19073),  INT16_C( 25698),  INT16_C( 25222),  INT16_C(  5283) },
      {  INT8_C(  18),  INT8_C( 103), -INT8_C(  25),  INT8_C( 119), -INT8_C(   2),  INT8_C(  19),  INT8_C(  21), -INT8_C(   1) } },
    { { -INT16_C(   928), -INT16_C( 16166), -INT16_C( 12238),  INT16_C( 21085),  INT16_C( 13188),  INT16_C( 23808),  INT16_C( 22501), -INT16_C( 29112) },
      {  INT16_C(  2154), -INT16_C( 29906),  INT16_C( 30394),  INT16_C( 15204), -INT16_C( 14400),  INT16_C( 18079),  INT16_C( 16937), -INT16_C( 30374) },
      {  INT8_C(   4),  INT8_C(  76),  INT8_C(  70), -INT8_C( 115), -INT8_C(   5), -INT8_C(  93), -INT8_C( 102),  INT8_C(  23) } },
    { {  INT16_C( 13630),  INT16_C( 28745), -INT16_C( 22779), -INT16_C( 30014), -INT16_C( 15398), -INT16_C( 16409),  INT16_C( 12314), -INT16_C( 31666) },
      {  INT16_C( 31800), -INT16_C(  3568),  INT16_C( 29939), -INT16_C( 19667), -INT16_C( 13253),  INT16_C( 25850),  INT16_C( 21518),  INT16_C( 19694) },
      { -INT8_C(  79),  INT8_C(  98),  INT8_C(  27),  INT8_C(  61), -INT8_C( 112),  INT8_C(  36), -INT8_C( 124), -INT8_C(  47) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int8x8_t r = simde_vaddhn_s16(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int8x8_t r = simde_vaddhn_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddhn_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT32_C(   453352412),  INT32_C(  1522407581),  INT32_C(   345566129),  INT32_C(  1003013391) },
      {  INT32_C(   822399788), -INT32_C(  1306766202), -INT32_C(   859539363),  INT32_C(  1389311094) },
      {  INT16_C( 19466),  INT16_C(  3290), -INT16_C(  7843), -INT16_C( 29033) } },
    { {  INT32_C(  1835914448), -INT32_C(  1631114259),  INT32_C(   632446742),  INT32_C(  1365277221) },
      { -INT32_C(   729586610),  INT32_C(   361144248), -INT32_C(  1914615273),  INT32_C(  1340059775) },
      {  INT16_C( 16881), -INT16_C( 19379), -INT16_C( 19565), -INT16_C( 24256) } },
    { {  INT32_C(  1924942981), -INT32_C(  1928297609),  INT32_C(   129155810), -INT32_C(  1957096899) },
      {  INT32_C(   794811510), -INT32_C(  1824201093), -INT32_C(  1356847568),  INT32_C(  1543373014) },
      { -INT16_C( 24036),  INT16_C(  8277), -INT16_C( 18734), -INT16_C(  6313) } },
    { { -INT32_C(   993150388),  INT32_C(   542235965), -INT32_C(   584645472), -INT32_C(  1922531306) },
      { -INT32_C(   658716836), -INT32_C(   563412819), -INT32_C(    41055450), -INT32_C(   665285493) },
      { -INT16_C( 25206), -INT16_C(   324), -INT16_C(  9548),  INT16_C( 26049) } },
    { { -INT32_C(  2070141370), -INT32_C(  1549472509),  INT32_C(   142658545), -INT32_C(  1466570676) },
      {  INT32_C(  1568690608),  INT32_C(  2017192785),  INT32_C(    41273719), -INT32_C(  1680159403) },
      { -INT16_C(  7652),  INT16_C(  7136),  INT16_C(  2806),  INT16_C( 17520) } },
    { { -INT32_C(   148932877),  INT32_C(  1436205924), -INT32_C(   614655089), -INT32_C(  1283198461) },
      { -INT32_C(  1794046909),  INT32_C(  1712147695),  INT32_C(  1785299477),  INT32_C(  1124483919) },
      { -INT16_C( 29648), -INT16_C( 17496),  INT16_C( 17862), -INT16_C(  2422) } },
    { {  INT32_C(   507127226),  INT32_C(  2020857065), -INT32_C(   212610577),  INT32_C(   128374467) },
      { -INT32_C(   895698982),  INT32_C(   422619396),  INT32_C(  2055510315), -INT32_C(  1749185827) },
      { -INT16_C(  5930), -INT16_C( 28252),  INT16_C( 28120), -INT16_C( 24732) } },
    { { -INT32_C(  1732905041), -INT32_C(  1156568884), -INT32_C(  1112644615),  INT32_C(   348411194) },
      {  INT32_C(   283009036),  INT32_C(   875171593), -INT32_C(  2052149592), -INT32_C(   417567688) },
      { -INT16_C( 22124), -INT16_C(  4294),  INT16_C( 17245), -INT16_C(  1056) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int16x4_t r = simde_vaddhn_s32(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t r = simde_vaddhn_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddhn_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT64_C(  870442698752863901), -INT64_C(  341582055392372236) },
      { -INT64_C( 2877460202929839660), -INT64_C( 8141529371499380509) },
      { -INT32_C(   872626645), -INT32_C(  1975128294) } },
    { {  INT64_C(  520634231706059596),  INT64_C( 3687736015850957379) },
      {  INT64_C( 5882020447537608857), -INT64_C( 4135025213325836318) },
      {  INT32_C(  1490734210), -INT32_C(   104142632) } },
    { {  INT64_C( 5336278500654210291),  INT64_C( 6107349192705590063) },
      { -INT64_C( 3052948020655173151),  INT64_C( 8214145149490630334) },
      {  INT32_C(   531629305), -INT32_C(   960484551) } },
    { {  INT64_C( 9164408874222422749),  INT64_C( 3808301818011560649) },
      {  INT64_C( 8388277242748532384), -INT64_C( 6115136444078207949) },
      { -INT32_C(   208164090), -INT32_C(   537101791) } },
    { { -INT64_C( 1691738144072820299),  INT64_C(  139124924536885863) },
      { -INT64_C( 3862402276365405636),  INT64_C( 8269345301273973322) },
      { -INT32_C(  1293174090),  INT32_C(  1957749534) } },
    { {  INT64_C( 8448468189015724343),  INT64_C( 3238403627226737295) },
      { -INT64_C( 3606675752233367920),  INT64_C( 4811153969015778965) },
      {  INT32_C(  1127317649),  INT32_C(  1874183676) } },
    { { -INT64_C( 3927747759568306951),  INT64_C( 6601621514774752385) },
      { -INT64_C( 3277928670890313167),  INT64_C(  518451682475272163) },
      { -INT32_C(  1677702282),  INT32_C(  1657771225) } },
    { {  INT64_C( 2389314222737574437), -INT64_C( 4801347874328485576) },
      {  INT64_C( 4249977849243689450),  INT64_C( 3274497391950634587) },
      {  INT32_C(  1545830646), -INT32_C(   355497581) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int32x2_t r = simde_vaddhn_s64(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t r = simde_vaddhn_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddhn_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT16_C( 1622), UINT16_C( 5422), UINT16_C( 4699), UINT16_C( 7191), UINT16_C(65238), UINT16_C(38974), UINT16_C(15812), UINT16_C( 8958) },
      { UINT16_C(28222), UINT16_C(29951), UINT16_C(48226), UINT16_C(12410), UINT16_C(39258), UINT16_C(53852), UINT16_C( 6427), UINT16_C(29162) },
      { UINT8_C(116), UINT8_C(138), UINT8_C(206), UINT8_C( 76), UINT8_C(152), UINT8_C(106), UINT8_C( 86), UINT8_C(148) } },
    { { UINT16_C( 6175), UINT16_C(31367), UINT16_C(40490), UINT16_C(  150), UINT16_C(54428), UINT16_C(24985), UINT16_C(38673), UINT16_C(20355) },
      { UINT16_C(33542), UINT16_C(26820), UINT16_C(15935), UINT16_C(39321), UINT16_C(62936), UINT16_C(62316), UINT16_C(22030), UINT16_C(11877) },
      { UINT8_C(155), UINT8_C(227), UINT8_C(220), UINT8_C(154), UINT8_C(202), UINT8_C( 85), UINT8_C(237), UINT8_C(125) } },
    { { UINT16_C(60526), UINT16_C(39080), UINT16_C(16266), UINT16_C(10137), UINT16_C(12819), UINT16_C( 9608), UINT16_C( 3017), UINT16_C(53108) },
      { UINT16_C(14478), UINT16_C(52536), UINT16_C(53623), UINT16_C(20327), UINT16_C(54214), UINT16_C(54338), UINT16_C(42793), UINT16_C(38658) },
      { UINT8_C( 36), UINT8_C(101), UINT8_C( 17), UINT8_C(119), UINT8_C(  5), UINT8_C(249), UINT8_C(178), UINT8_C(102) } },
    { { UINT16_C(43923), UINT16_C( 7727), UINT16_C(51434), UINT16_C(64837), UINT16_C(52730), UINT16_C(50210), UINT16_C(38872), UINT16_C(26515) },
      { UINT16_C(52175), UINT16_C(17972), UINT16_C(39836), UINT16_C(25237), UINT16_C(55406), UINT16_C(38711), UINT16_C(14719), UINT16_C( 4910) },
      { UINT8_C(119), UINT8_C(100), UINT8_C(100), UINT8_C( 95), UINT8_C(166), UINT8_C( 91), UINT8_C(209), UINT8_C(122) } },
    { { UINT16_C(24292), UINT16_C(52785), UINT16_C(30246), UINT16_C( 8652), UINT16_C(60995), UINT16_C( 7141), UINT16_C(30853), UINT16_C(21890) },
      { UINT16_C(46916), UINT16_C(57499), UINT16_C(12626), UINT16_C(49475), UINT16_C(31241), UINT16_C(34904), UINT16_C(34739), UINT16_C(39067) },
      { UINT8_C( 22), UINT8_C(174), UINT8_C(167), UINT8_C(227), UINT8_C(104), UINT8_C(164), UINT8_C(  0), UINT8_C(238) } },
    { { UINT16_C(52453), UINT16_C( 2918), UINT16_C(12866), UINT16_C(34092), UINT16_C( 4385), UINT16_C(42657), UINT16_C( 9098), UINT16_C(52987) },
      { UINT16_C(38874), UINT16_C(11694), UINT16_C(61896), UINT16_C(53742), UINT16_C(18027), UINT16_C( 8025), UINT16_C(62925), UINT16_C(45751) },
      { UINT8_C(100), UINT8_C( 57), UINT8_C( 36), UINT8_C( 87), UINT8_C( 87), UINT8_C(197), UINT8_C( 25), UINT8_C(129) } },
    { { UINT16_C( 7617), UINT16_C( 1214), UINT16_C(59984), UINT16_C(29065), UINT16_C(11004), UINT16_C(34327), UINT16_C( 4942), UINT16_C(10324) },
      { UINT16_C(  682), UINT16_C(29269), UINT16_C(17396), UINT16_C(24387), UINT16_C(40074), UINT16_C(22398), UINT16_C(13713), UINT16_C(21258) },
      { UINT8_C( 32), UINT8_C(119), UINT8_C( 46), UINT8_C(208), UINT8_C(199), UINT8_C(221), UINT8_C( 72), UINT8_C(123) } },
    { { UINT16_C(51283), UINT16_C(41815), UINT16_C(57522), UINT16_C(44564), UINT16_C(11019), UINT16_C(22836), UINT16_C(34878), UINT16_C(59521) },
      { UINT16_C(55179), UINT16_C(32602), UINT16_C(40218), UINT16_C(42206), UINT16_C(23866), UINT16_C(52220), UINT16_C( 1682), UINT16_C(58654) },
      { UINT8_C(159), UINT8_C( 34), UINT8_C(125), UINT8_C( 82), UINT8_C(136), UINT8_C( 37), UINT8_C(142), UINT8_C(205) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint8x8_t r = simde_vaddhn_u16(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint8x8_t r = simde_vaddhn_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddhn_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT32_C(2156426702), UINT32_C(1630510166), UINT32_C( 112878536), UINT32_C(2012167148) },
      { UINT32_C( 771115282), UINT32_C( 567399655), UINT32_C(3303853361), UINT32_C(2712210387) },
      { UINT16_C(44670), UINT16_C(33537), UINT16_C(52135), UINT16_C( 6552) } },
    { { UINT32_C(3592565376), UINT32_C(2520207822), UINT32_C(2694705588), UINT32_C(1058507821) },
      { UINT32_C(3161198037), UINT32_C( 333266658), UINT32_C(3755461131), UINT32_C(1434485205) },
      { UINT16_C(37518), UINT16_C(43540), UINT16_C(32885), UINT16_C(38040) } },
    { { UINT32_C(2167186099), UINT32_C(2820170739), UINT32_C(2185803093), UINT32_C( 381771841) },
      { UINT32_C(1339240045), UINT32_C(2003021932), UINT32_C(1331051130), UINT32_C(1856362427) },
      { UINT16_C(53503), UINT16_C( 8060), UINT16_C(53662), UINT16_C(34151) } },
    { { UINT32_C(1844498809), UINT32_C(2299856948), UINT32_C(4262157757), UINT32_C( 722783677) },
      { UINT32_C(1736108027), UINT32_C( 316595608), UINT32_C(3546428696), UINT32_C(2235696908) },
      { UINT16_C(54635), UINT16_C(39923), UINT16_C(53613), UINT16_C(45142) } },
    { { UINT32_C( 217199320), UINT32_C(4153804602), UINT32_C( 586522981), UINT32_C(1766656366) },
      { UINT32_C(2312161521), UINT32_C(3181096869), UINT32_C(4036099556), UINT32_C(3698709252) },
      { UINT16_C(38594), UINT16_C(46385), UINT16_C( 4999), UINT16_C(17858) } },
    { { UINT32_C(1072261125), UINT32_C(3560341359), UINT32_C(2415340320), UINT32_C( 637027380) },
      { UINT32_C(2997799180), UINT32_C(1550797432), UINT32_C(1280049223), UINT32_C(3626549715) },
      { UINT16_C(62104), UINT16_C(12453), UINT16_C(56387), UINT16_C(65057) } },
    { { UINT32_C(2568425769), UINT32_C(2976730512), UINT32_C(2906678392), UINT32_C(3050453161) },
      { UINT32_C(2036826369), UINT32_C( 316004299), UINT32_C(2875072983), UINT32_C( 209946595) },
      { UINT16_C( 4734), UINT16_C(50243), UINT16_C(22686), UINT16_C(49749) } },
    { { UINT32_C( 698719128), UINT32_C(1641681896), UINT32_C( 537795191), UINT32_C(1423368274) },
      { UINT32_C( 751648097), UINT32_C(3963593492), UINT32_C(2811731396), UINT32_C(3182696996) },
      { UINT16_C(22130), UINT16_C(19993), UINT16_C(51109), UINT16_C( 4746) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint16x4_t r = simde_vaddhn_u32(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t r = simde_vaddhn_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddhn_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT64_C(16501119132463684021), UINT64_C( 5728819438195838426) },
      { UINT64_C(13049385465302175256), UINT64_C( 9167378077856935768) },
      { UINT32_C(2585295709), UINT32_C(3468291255) } },
    { { UINT64_C(13383322465373855594), UINT64_C(12855074998387654441) },
      { UINT64_C(17607939420304892340), UINT64_C( 3742679072496466086) },
      { UINT32_C(2920748156), UINT32_C(3864465763) } },
    { { UINT64_C( 6008581639880969673), UINT64_C( 7192759530452306053) },
      { UINT64_C( 5567122754819960754), UINT64_C( 2745134587385328156) },
      { UINT32_C(2695178704), UINT32_C(2313846284) } },
    { { UINT64_C( 7870095225187673019), UINT64_C( 2705640225342530426) },
      { UINT64_C( 1513409558858667277), UINT64_C( 2804075071578750568) },
      { UINT32_C(2184767458), UINT32_C(1282830558) } },
    { { UINT64_C( 7317299271182301494), UINT64_C( 9475602711615248615) },
      { UINT64_C( 1278802021024461744), UINT64_C(  182326293962275317) },
      { UINT32_C(2001435796), UINT32_C(2248661826) } },
    { { UINT64_C(13675652879801750137), UINT64_C( 2503606059249719237) },
      { UINT64_C( 2397474299113633163), UINT64_C( 6058195660711205700) },
      { UINT32_C(3742316546), UINT32_C(1993449805) } },
    { { UINT64_C(11974933838988653723), UINT64_C( 7669244096386582490) },
      { UINT64_C(  640325630753192341), UINT64_C(  517680228686390527) },
      { UINT32_C(2937218982), UINT32_C(1906166860) } },
    { { UINT64_C( 4965122288500992095), UINT64_C(18390728808758036975) },
      { UINT64_C(13476076017089042232), UINT64_C(12068456541436910599) },
      { UINT32_C(4293676071), UINT32_C(2796864434) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint32x2_t r = simde_vaddhn_u64(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t r = simde_vaddhn_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddhn_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
