#define SIMDE_TEST_ARM_NEON_INSN mull_high_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mull_high_lane.h"

static int
test_simde_vmull_high_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C(   28834), -INT16_C(   23879),  INT16_C(   13571), -INT16_C(   24395),
         INT16_C(   30864), -INT16_C(    1173), -INT16_C(   19890), -INT16_C(    4121) },
      {  INT16_C(   31343),  INT16_C(    3601), -INT16_C(     203), -INT16_C(    3243) },
         INT8_C(       0),
      {  INT32_C(967370352), -INT32_C(36765339), -INT32_C(623412270), -INT32_C(129164503) } },
    { { -INT16_C(   31821), -INT16_C(   12929),  INT16_C(   25513), -INT16_C(   19128),
        -INT16_C(   12849),  INT16_C(    5825), -INT16_C(    6914), -INT16_C(    4956) },
      { -INT16_C(   10533), -INT16_C(   30942),  INT16_C(    8824), -INT16_C(   16885) },
         INT8_C(       2),
      { -INT32_C(113379576),  INT32_C(51399800), -INT32_C(61009136), -INT32_C(43731744) } },
    { { -INT16_C(   20033),  INT16_C(    8244),  INT16_C(    6084),  INT16_C(    7141),
        -INT16_C(   15139), -INT16_C(   27944),  INT16_C(   25509), -INT16_C(   19066) },
      {  INT16_C(   10470), -INT16_C(    7794),  INT16_C(    6229),  INT16_C(   12221) },
         INT8_C(       1),
      {  INT32_C(117993366),  INT32_C(217795536), -INT32_C(198817146),  INT32_C(148600404) } },
    { { -INT16_C(   11424), -INT16_C(    7079),  INT16_C(   30765),  INT16_C(   16527),
         INT16_C(   24568),  INT16_C(   27817),  INT16_C(   16230),  INT16_C(   26379) },
      {  INT16_C(   27994),  INT16_C(    1328),  INT16_C(    6029), -INT16_C(    1349) },
         INT8_C(       1),
      {  INT32_C(32626304),  INT32_C(36940976),  INT32_C(21553440),  INT32_C(35031312) } },
    { { -INT16_C(   22924),  INT16_C(    2851), -INT16_C(    2202),  INT16_C(   24671),
        -INT16_C(   21971), -INT16_C(   24110),  INT16_C(   12935), -INT16_C(   13132) },
      {  INT16_C(   26299), -INT16_C(   22407), -INT16_C(   19349), -INT16_C(   12020) },
         INT8_C(       2),
      {  INT32_C(425116879),  INT32_C(466504390), -INT32_C(250279315),  INT32_C(254091068) } },
    { { -INT16_C(   21205), -INT16_C(   30405),  INT16_C(   10637),  INT16_C(   18824),
         INT16_C(   10805),  INT16_C(   19029),  INT16_C(   30943),  INT16_C(    9868) },
      { -INT16_C(   11839), -INT16_C(   14874),  INT16_C(   31807),  INT16_C(    1860) },
         INT8_C(       0),
      { -INT32_C(127920395), -INT32_C(225284331), -INT32_C(366334177), -INT32_C(116827252) } },
    { { -INT16_C(   16031),  INT16_C(    3152),  INT16_C(   18097),  INT16_C(   10528),
        -INT16_C(   27719), -INT16_C(    5054), -INT16_C(   12777), -INT16_C(   16024) },
      { -INT16_C(   26039),  INT16_C(   14124), -INT16_C(    5914),  INT16_C(    5932) },
         INT8_C(       3),
      { -INT32_C(164429108), -INT32_C(29980328), -INT32_C(75793164), -INT32_C(95054368) } },
    { { -INT16_C(   27056), -INT16_C(   27388),  INT16_C(    2133),  INT16_C(   28480),
         INT16_C(   24970), -INT16_C(   21089),  INT16_C(   29923),  INT16_C(   18599) },
      { -INT16_C(    1278),  INT16_C(   11120),  INT16_C(    7297),  INT16_C(    3393) },
         INT8_C(       3),
      {  INT32_C(84723210), -INT32_C(71554977),  INT32_C(101528739),  INT32_C(63106407) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vmull_high_lane_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmull_high_lane_s16, r, (HEDLEY_UNREACHABLE(), r), lane, a, v);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t v[2];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1366677891),  INT32_C(  1636702415),  INT32_C(  1027751180),  INT32_C(  1562260351) },
      {  INT32_C(   508697225), -INT32_C(   644285791) },
         INT8_C(           1),
      { -INT64_C(662165481957483380), -INT64_C(1006542145991972641) } },
    { { -INT32_C(   451075438), -INT32_C(  1768978097), -INT32_C(  1278659517),  INT32_C(   724877200) },
      { -INT32_C(   253338093), -INT32_C(   945930470) },
         INT8_C(           1),
      {  INT64_C(1209522997885782990), -INT64_C(685683430488284000) } },
    { {  INT32_C(   390303877),  INT32_C(   828828728), -INT32_C(  1386145012), -INT32_C(  1638293720) },
      { -INT32_C(  2058534341), -INT32_C(  1126577553) },
         INT8_C(           0),
      {  INT64_C(2853427108807857092),  INT64_C(3372483883264638520) } },
    { {  INT32_C(  1672288842), -INT32_C(   319918840), -INT32_C(  1324771700),  INT32_C(  1226510883) },
      { -INT32_C(   263815361), -INT32_C(  1588531786) },
         INT8_C(           0),
      {  INT64_C(349495124278083700), -INT64_C(323572411369073763) } },
    { { -INT32_C(  2136523205), -INT32_C(  2086241395), -INT32_C(   248819017),  INT32_C(  2102044178) },
      { -INT32_C(  1305193403),  INT32_C(   453246916) },
         INT8_C(           0),
      {  INT64_C(324756939529344851), -INT64_C(2743574193940157734) } },
    { { -INT32_C(    23216476), -INT32_C(   339971456), -INT32_C(  1651908645),  INT32_C(  2016703473) },
      {  INT32_C(   231388879), -INT32_C(   667090285) },
         INT8_C(           1),
      {  INT64_C(1101972208787013825), -INT64_C(1345323294564059805) } },
    { { -INT32_C(  1466855103), -INT32_C(  1079332104), -INT32_C(  1412345373), -INT32_C(  1820709717) },
      { -INT32_C(  1325049121),  INT32_C(   437802279) },
         INT8_C(           0),
      {  INT64_C(1871426995042067133),  INT64_C(2412529810107008757) } },
    { { -INT32_C(  1649274274),  INT32_C(   365937935), -INT32_C(  1439340536), -INT32_C(  1793642029) },
      { -INT32_C(  1724162243),  INT32_C(   591482351) },
         INT8_C(           0),
      {  INT64_C(2481656606990582248),  INT64_C(3092529863859711047) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int64x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmull_high_lane_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_int64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmull_high_lane_s32, r, (HEDLEY_UNREACHABLE(), r), lane, a, v);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t v[8];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
    { { -INT16_C(   30873),  INT16_C(      28),  INT16_C(   17250),  INT16_C(   17824),
         INT16_C(   11060),  INT16_C(   16510),  INT16_C(    7400), -INT16_C(   30081) },
      {  INT16_C(   16326),  INT16_C(   30669), -INT16_C(    4060), -INT16_C(   23747),
        -INT16_C(   11795), -INT16_C(   25295),  INT16_C(    8333), -INT16_C(   22920) },
         INT8_C(       5),
      { -INT32_C(279762700), -INT32_C(417620450), -INT32_C(187183000),  INT32_C(760898895) } },
    { { -INT16_C(   12503), -INT16_C(   22388),  INT16_C(   14696),  INT16_C(   12097),
         INT16_C(    2551), -INT16_C(     714),  INT16_C(   23788), -INT16_C(   27234) },
      {  INT16_C(    9313), -INT16_C(   27459),  INT16_C(   16913), -INT16_C(   13127),
         INT16_C(   22036), -INT16_C(   16222), -INT16_C(    3567), -INT16_C(     363) },
         INT8_C(       0),
      {  INT32_C(23757463), -INT32_C( 6649482),  INT32_C(221537644), -INT32_C(253630242) } },
    { { -INT16_C(   30409),  INT16_C(   22917), -INT16_C(    2056), -INT16_C(   11046),
        -INT16_C(   16692), -INT16_C(   21466), -INT16_C(   27339), -INT16_C(   20946) },
      {  INT16_C(   17649),  INT16_C(   13533),  INT16_C(   26545), -INT16_C(    6280),
        -INT16_C(   24341),  INT16_C(    7041), -INT16_C(    9148), -INT16_C(   11827) },
         INT8_C(       5),
      { -INT32_C(117528372), -INT32_C(151142106), -INT32_C(192493899), -INT32_C(147480786) } },
    { { -INT16_C(   30731), -INT16_C(   29155),  INT16_C(    1997), -INT16_C(   12118),
         INT16_C(   15739), -INT16_C(   21071), -INT16_C(   14859),  INT16_C(    2571) },
      {  INT16_C(   18277), -INT16_C(   27812),  INT16_C(   23741), -INT16_C(   28316),
        -INT16_C(   13517),  INT16_C(   23637),  INT16_C(    7291), -INT16_C(   25669) },
         INT8_C(       7),
      { -INT32_C(404004391),  INT32_C(540871499),  INT32_C(381415671), -INT32_C(65994999) } },
    { { -INT16_C(    9432),  INT16_C(   20139), -INT16_C(   31812), -INT16_C(   31503),
        -INT16_C(    7360), -INT16_C(   22530), -INT16_C(   15500),  INT16_C(   11137) },
      {  INT16_C(    6438), -INT16_C(   18646), -INT16_C(   16264), -INT16_C(   25012),
        -INT16_C(   11003), -INT16_C(   31192), -INT16_C(   29501),  INT16_C(     665) },
         INT8_C(       6),
      {  INT32_C(217127360),  INT32_C(664657530),  INT32_C(457265500), -INT32_C(328552637) } },
    { {  INT16_C(    1802), -INT16_C(   11418), -INT16_C(   28120),  INT16_C(   16755),
        -INT16_C(    1090), -INT16_C(   24370), -INT16_C(    7266),  INT16_C(   30670) },
      { -INT16_C(   28290),  INT16_C(   25371), -INT16_C(   31877),  INT16_C(   30327),
        -INT16_C(    9974), -INT16_C(   21503), -INT16_C(   23965),  INT16_C(   19092) },
         INT8_C(       4),
      {  INT32_C(10871660),  INT32_C(243066380),  INT32_C(72471084), -INT32_C(305902580) } },
    { {  INT16_C(   19777), -INT16_C(   18625),  INT16_C(   16630), -INT16_C(   14584),
        -INT16_C(    1806), -INT16_C(   27803),  INT16_C(   20786),  INT16_C(   26730) },
      {  INT16_C(    9566), -INT16_C(   12897),  INT16_C(   10996), -INT16_C(     297),
         INT16_C(   19330), -INT16_C(   17187), -INT16_C(   23929),  INT16_C(    2150) },
         INT8_C(       2),
      { -INT32_C(19858776), -INT32_C(305721788),  INT32_C(228562856),  INT32_C(293923080) } },
    { { -INT16_C(     931), -INT16_C(   22676), -INT16_C(   20667),  INT16_C(    1256),
        -INT16_C(     535),  INT16_C(   10800), -INT16_C(   13285), -INT16_C(   11425) },
      {  INT16_C(   18516), -INT16_C(   16525), -INT16_C(     143),  INT16_C(    5598),
         INT16_C(   24321), -INT16_C(    9246), -INT16_C(    6356),  INT16_C(   30195) },
         INT8_C(       4),
      { -INT32_C(13011735),  INT32_C(262666800), -INT32_C(323104485), -INT32_C(277867425) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int32x4_t r;

    SIMDE_CONSTIFY_8_(simde_vmull_high_laneq_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_int32x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmull_high_laneq_s16, r, (HEDLEY_UNREACHABLE(), r), lane, a, v);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t v[4];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(    98820357),  INT32_C(  2129827770), -INT32_C(   929094559), -INT32_C(   562284615) },
      {  INT32_C(   439107182), -INT32_C(  1897563597),  INT32_C(   762499010), -INT32_C(  2051988139) },
         INT8_C(           0),
      { -INT64_C(407972093614022738), -INT64_C(246903212774604930) } },
    { {  INT32_C(  1870303424), -INT32_C(   800873673), -INT32_C(   943231187),  INT32_C(  1537635436) },
      { -INT32_C(   566862428),  INT32_C(   985504305),  INT32_C(   258289481),  INT32_C(  1105946190) },
         INT8_C(           3),
      { -INT64_C(1043162937551827530),  INT64_C(1700542052053188840) } },
    { { -INT32_C(  1147457203), -INT32_C(  2089576355),  INT32_C(  1699368140),  INT32_C(   608884874) },
      {  INT32_C(   885536078),  INT32_C(   637847445),  INT32_C(   543774923), -INT32_C(   892285670) },
         INT8_C(           2),
      {  INT64_C(924073779477153220),  INT64_C(331096325475214702) } },
    { { -INT32_C(  1078600194), -INT32_C(   802193267),  INT32_C(   318790710), -INT32_C(  1279782282) },
      { -INT32_C(   188124572),  INT32_C(   919717709), -INT32_C(   519967400), -INT32_C(  1900583463) },
         INT8_C(           2),
      { -INT64_C(165760776622854000),  INT64_C(665445065737606800) } },
    { { -INT32_C(  1889965166),  INT32_C(   723367299),  INT32_C(    74155097), -INT32_C(   768771725) },
      { -INT32_C(   852480006),  INT32_C(  1174627370),  INT32_C(  1654708726), -INT32_C(   512211321) },
         INT8_C(           0),
      { -INT64_C(63215737535490582),  INT64_C(655362524740630350) } },
    { {  INT32_C(  2138712702),  INT32_C(   867418307),  INT32_C(   227407579),  INT32_C(  1103712889) },
      { -INT32_C(   740197281),  INT32_C(   937466976), -INT32_C(  1283452128), -INT32_C(  1511605444) },
         INT8_C(           1),
      {  INT64_C(213187095404611104),  INT64_C(1034694384423053664) } },
    { { -INT32_C(  2087150657),  INT32_C(  1302905957),  INT32_C(  1978519128),  INT32_C(   206616372) },
      {  INT32_C(   675063099), -INT32_C(  1166978335),  INT32_C(  1209108707), -INT32_C(  1277454095) },
         INT8_C(           3),
      { -INT64_C(2527467362099429160), -INT64_C(263942930505443340) } },
    { { -INT32_C(   127679378),  INT32_C(  1774578044),  INT32_C(  2078637766), -INT32_C(   210937984) },
      { -INT32_C(   292564519), -INT32_C(   241482105),  INT32_C(  1607425342), -INT32_C(  1488972974) },
         INT8_C(           1),
      { -INT64_C(501953823266177430),  INT64_C(50937748400776320) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int64x2_t r;

    SIMDE_CONSTIFY_4_(simde_vmull_high_laneq_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_int64x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmull_high_laneq_s32, r, (HEDLEY_UNREACHABLE(), r), lane, a, v);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, HEDLEY_STATIC_CAST(int8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t v[4];
    int8_t lane;
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT16_C(   62368),  UINT16_C(    7209),  UINT16_C(    5299),  UINT16_C(   51294),
         UINT16_C(   62619),  UINT16_C(   64726),  UINT16_C(   45709),  UINT16_C(   44834) },
      {  UINT16_C(   44712),  UINT16_C(   45849),  UINT16_C(   57939),  UINT16_C(    6480) },
         INT8_C(       0),
      {  UINT32_C(2799820728),  UINT32_C(2894028912),  UINT32_C(2043740808),  UINT32_C(2004617808) } },
    { {  UINT16_C(   37558),  UINT16_C(   48461),  UINT16_C(    7651),  UINT16_C(   60723),
         UINT16_C(    7856),  UINT16_C(   27281),  UINT16_C(   54593),  UINT16_C(   17999) },
      {  UINT16_C(   63168),  UINT16_C(    1458),  UINT16_C(   39166),  UINT16_C(   44100) },
         INT8_C(       1),
      {  UINT32_C(11454048),  UINT32_C(39775698),  UINT32_C(79596594),  UINT32_C(26242542) } },
    { {  UINT16_C(   25703),  UINT16_C(   63388),  UINT16_C(   47827),  UINT16_C(   12935),
         UINT16_C(   48182),  UINT16_C(   25807),  UINT16_C(   22185),  UINT16_C(   63648) },
      {  UINT16_C(   47336),  UINT16_C(   20030),  UINT16_C(   55024),  UINT16_C(   27272) },
         INT8_C(       0),
      {  UINT32_C(2280743152),  UINT32_C(1221600152),  UINT32_C(1050149160),  UINT32_C(3012841728) } },
    { {  UINT16_C(   56223),  UINT16_C(   40985),  UINT16_C(    9543),  UINT16_C(   49172),
         UINT16_C(    4591),  UINT16_C(   64145),  UINT16_C(   25433),  UINT16_C(    1708) },
      {  UINT16_C(   29331),  UINT16_C(    6111),  UINT16_C(   26687),  UINT16_C(   45285) },
         INT8_C(       1),
      {  UINT32_C(28055601),  UINT32_C(391990095),  UINT32_C(155421063),  UINT32_C(10437588) } },
    { {  UINT16_C(   15924),  UINT16_C(   62544),  UINT16_C(   25797),  UINT16_C(   38772),
         UINT16_C(   52846),  UINT16_C(   64591),  UINT16_C(   57259),  UINT16_C(    2966) },
      {  UINT16_C(   20535),  UINT16_C(   28014),  UINT16_C(   64878),  UINT16_C(   59081) },
         INT8_C(       3),
      {  UINT32_C(3122194526),  UINT32_C(3816100871),  UINT32_C(3382918979),  UINT32_C(175234246) } },
    { {  UINT16_C(    8524),  UINT16_C(   18761),  UINT16_C(   29222),  UINT16_C(   36999),
         UINT16_C(   59339),  UINT16_C(   23784),  UINT16_C(    6072),  UINT16_C(   48792) },
      {  UINT16_C(   41874),  UINT16_C(    1374),  UINT16_C(   10083),  UINT16_C(   54459) },
         INT8_C(       1),
      {  UINT32_C(81531786),  UINT32_C(32679216),  UINT32_C( 8342928),  UINT32_C(67040208) } },
    { {  UINT16_C(   14694),  UINT16_C(   11754),  UINT16_C(   31612),  UINT16_C(   32476),
         UINT16_C(   60706),  UINT16_C(    4258),  UINT16_C(   20845),  UINT16_C(   32303) },
      {  UINT16_C(   10449),  UINT16_C(   31083),  UINT16_C(   30997),  UINT16_C(   56870) },
         INT8_C(       2),
      {  UINT32_C(1881703882),  UINT32_C(131985226),  UINT32_C(646132465),  UINT32_C(1001296091) } },
    { {  UINT16_C(   43427),  UINT16_C(   38730),  UINT16_C(   10614),  UINT16_C(   64789),
         UINT16_C(   59992),  UINT16_C(   12843),  UINT16_C(   13239),  UINT16_C(   61213) },
      {  UINT16_C(   46867),  UINT16_C(   52978),  UINT16_C(   42861),  UINT16_C(   19414) },
         INT8_C(       2),
      {  UINT32_C(2571317112),  UINT32_C(550463823),  UINT32_C(567436779),  UINT32_C(2623650393) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x4_t v = simde_vld1_u16(test_vec[i].v);
    simde_uint32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vmull_high_lane_u16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x4_t v = simde_test_arm_neon_random_u16x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmull_high_lane_u16, r, (HEDLEY_UNREACHABLE(), r), lane, a, v);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t v[2];
    int8_t lane;
    uint64_t r[2];
  } test_vec[] = {
    { {  UINT32_C(   736713243),  UINT32_C(  1201284964),  UINT32_C(   324514881),  UINT32_C(  3217911725) },
      {  UINT32_C(  1795670074),  UINT32_C(  3965004337) },
         INT8_C(           1),
      {  UINT64_C(1286702910586038897),  UINT64_C(12759033945708151325) } },
    { {  UINT32_C(   448751350),  UINT32_C(  2234320605),  UINT32_C(  4193532147),  UINT32_C(  1524786414) },
      {  UINT32_C(   411336099),  UINT32_C(   997740130) },
         INT8_C(           1),
      {  UINT64_C(4184055309506959110),  UINT64_C(1521340594926593820) } },
    { {  UINT32_C(   512728071),  UINT32_C(  4104205539),  UINT32_C(  4235801665),  UINT32_C(   442660380) },
      {  UINT32_C(  4140093913),  UINT32_C(  3378520617) },
         INT8_C(           0),
      {  UINT64_C(17536616689941765145),  UINT64_C(1832655544764266940) } },
    { {  UINT32_C(   419562173),  UINT32_C(    27800514),  UINT32_C(  1346972294),  UINT32_C(  4119968007) },
      {  UINT32_C(  1536370310),  UINT32_C(  3155142906) },
         INT8_C(           0),
      {  UINT64_C(2069448240894191140),  UINT64_C(6329796524104672170) } },
    { {  UINT32_C(  3682062501),  UINT32_C(   194651005),  UINT32_C(  1652459702),  UINT32_C(  4135775226) },
      {  UINT32_C(   306502304),  UINT32_C(  2364220906) },
         INT8_C(           1),
      {  UINT64_C(3906779773790930012),  UINT64_C(9777886251826074756) } },
    { {  UINT32_C(  1151490577),  UINT32_C(   688223364),  UINT32_C(  4084892686),  UINT32_C(  4048336621) },
      {  UINT32_C(    26418091),  UINT32_C(  2480353905) },
         INT8_C(           0),
      {  UINT64_C(107915066703982426),  UINT64_C(106949325252210511) } },
    { {  UINT32_C(   272959896),  UINT32_C(  1686631170),  UINT32_C(  2085946887),  UINT32_C(   242049439) },
      {  UINT32_C(  1671973231),  UINT32_C(   290686190) },
         INT8_C(           1),
      {  UINT64_C(606355953124390530),  UINT64_C(70360429214547410) } },
    { {  UINT32_C(  2831893573),  UINT32_C(  1962582580),  UINT32_C(   181318084),  UINT32_C(  1403855141) },
      {  UINT32_C(  1365124568),  UINT32_C(   891655685) },
         INT8_C(           0),
      {  UINT64_C(247521771091087712),  UINT64_C(1916437142892204088) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x2_t v = simde_vld1_u32(test_vec[i].v);
    simde_uint64x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmull_high_lane_u32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x2_t v = simde_test_arm_neon_random_u32x2();
    int lane = simde_test_codegen_random_i8() & 1;

    simde_uint64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmull_high_lane_u32, r, (HEDLEY_UNREACHABLE(), r), lane, a, v);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t v[8];
    int8_t lane;
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT16_C(   48822),  UINT16_C(   19302),  UINT16_C(   46890),  UINT16_C(   44506),
         UINT16_C(    4936),  UINT16_C(   56336),  UINT16_C(   22930),  UINT16_C(   47629) },
      {  UINT16_C(   43601),  UINT16_C(   33770),  UINT16_C(   23597),  UINT16_C(   47126),
         UINT16_C(   55949),  UINT16_C(   39547),  UINT16_C(   54475),  UINT16_C(   52564) },
         INT8_C(       4),
      {  UINT32_C(276164264),  UINT32_C(3151942864),  UINT32_C(1282910570),  UINT32_C(2664794921) } },
    { {  UINT16_C(   28320),  UINT16_C(   19371),  UINT16_C(   45327),  UINT16_C(   57471),
         UINT16_C(     365),  UINT16_C(   20295),  UINT16_C(    2611),  UINT16_C(    7890) },
      {  UINT16_C(   18429),  UINT16_C(   37492),  UINT16_C(   18537),  UINT16_C(    2597),
         UINT16_C(    5944),  UINT16_C(   61246),  UINT16_C(   64860),  UINT16_C(   53996) },
         INT8_C(       7),
      {  UINT32_C(19708540),  UINT32_C(1095848820),  UINT32_C(140983556),  UINT32_C(426028440) } },
    { {  UINT16_C(   43010),  UINT16_C(   29079),  UINT16_C(   11311),  UINT16_C(   39927),
         UINT16_C(   50017),  UINT16_C(   49504),  UINT16_C(   40018),  UINT16_C(   54760) },
      {  UINT16_C(   16262),  UINT16_C(   44264),  UINT16_C(   18833),  UINT16_C(   60160),
         UINT16_C(   32825),  UINT16_C(    8177),  UINT16_C(   10995),  UINT16_C(   50716) },
         INT8_C(       1),
      {  UINT32_C(2213952488),  UINT32_C(2191245056),  UINT32_C(1771356752),  UINT32_C(2423896640) } },
    { {  UINT16_C(    9515),  UINT16_C(    1703),  UINT16_C(   13690),  UINT16_C(    7352),
         UINT16_C(   49238),  UINT16_C(   24611),  UINT16_C(     805),  UINT16_C(   34610) },
      {  UINT16_C(   38978),  UINT16_C(   55382),  UINT16_C(   14821),  UINT16_C(   61117),
         UINT16_C(   53335),  UINT16_C(    3397),  UINT16_C(    4957),  UINT16_C(     101) },
         INT8_C(       6),
      {  UINT32_C(244072766),  UINT32_C(121996727),  UINT32_C( 3990385),  UINT32_C(171561770) } },
    { {  UINT16_C(   36446),  UINT16_C(   23228),  UINT16_C(   11633),  UINT16_C(   50118),
         UINT16_C(   20896),  UINT16_C(   53716),  UINT16_C(   26210),  UINT16_C(   40665) },
      {  UINT16_C(   14972),  UINT16_C(   21249),  UINT16_C(   26700),  UINT16_C(   44946),
         UINT16_C(   18704),  UINT16_C(   57767),  UINT16_C(   24551),  UINT16_C(   34441) },
         INT8_C(       1),
      {  UINT32_C(444019104),  UINT32_C(1141411284),  UINT32_C(556936290),  UINT32_C(864090585) } },
    { {  UINT16_C(   57145),  UINT16_C(   12704),  UINT16_C(   22527),  UINT16_C(    5367),
         UINT16_C(      81),  UINT16_C(   62707),  UINT16_C(   59749),  UINT16_C(   10502) },
      {  UINT16_C(   19889),  UINT16_C(     573),  UINT16_C(   22431),  UINT16_C(   43093),
         UINT16_C(   10088),  UINT16_C(   48189),  UINT16_C(   22982),  UINT16_C(   52188) },
         INT8_C(       3),
      {  UINT32_C( 3490533),  UINT32_C(2702232751),  UINT32_C(2574763657),  UINT32_C(452562686) } },
    { {  UINT16_C(    6048),  UINT16_C(   51151),  UINT16_C(   48184),  UINT16_C(   19713),
         UINT16_C(   25140),  UINT16_C(   16856),  UINT16_C(   64042),  UINT16_C(   40785) },
      {  UINT16_C(   35067),  UINT16_C(   48785),  UINT16_C(   34202),  UINT16_C(   25217),
         UINT16_C(   16998),  UINT16_C(   36048),  UINT16_C(   12443),  UINT16_C(   25238) },
         INT8_C(       6),
      {  UINT32_C(312817020),  UINT32_C(209739208),  UINT32_C(796874606),  UINT32_C(507487755) } },
    { {  UINT16_C(   26384),  UINT16_C(   46093),  UINT16_C(   16615),  UINT16_C(   35939),
         UINT16_C(    1549),  UINT16_C(   27689),  UINT16_C(   56342),  UINT16_C(   56629) },
      {  UINT16_C(   33788),  UINT16_C(   14431),  UINT16_C(   41344),  UINT16_C(   36429),
         UINT16_C(   52568),  UINT16_C(   44528),  UINT16_C(   40896),  UINT16_C(   37332) },
         INT8_C(       0),
      {  UINT32_C(52337612),  UINT32_C(935555932),  UINT32_C(1903683496),  UINT32_C(1913380652) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t v = simde_vld1q_u16(test_vec[i].v);
    simde_uint32x4_t r;

    SIMDE_CONSTIFY_8_(simde_vmull_high_laneq_u16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t v = simde_test_arm_neon_random_u16x8();
    int lane = simde_test_codegen_random_i8() & 7;

    simde_uint32x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmull_high_laneq_u16, r, (HEDLEY_UNREACHABLE(), r), lane, a, v);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t v[4];
    int8_t lane;
    uint64_t r[2];
  } test_vec[] = {
    { {  UINT32_C(  1417538713),  UINT32_C(  1662052652),  UINT32_C(  1717916689),  UINT32_C(  1084646110) },
      {  UINT32_C(  2359562417),  UINT32_C(   391702538),  UINT32_C(  3672311861),  UINT32_C(  2270655770) },
         INT8_C(           1),
      {  UINT64_C(672912327153856682),  UINT64_C(424858634118827180) } },
    { {  UINT32_C(  1592254699),  UINT32_C(  2048462065),  UINT32_C(  3230540917),  UINT32_C(  1475000926) },
      {  UINT32_C(   416768153),  UINT32_C(   433154729),  UINT32_C(  3667516236),  UINT32_C(  3015221358) },
         INT8_C(           0),
      {  UINT64_C(1346386571169016301),  UINT64_C(614733411602309678) } },
    { {  UINT32_C(  3094280729),  UINT32_C(   860311120),  UINT32_C(   570256702),  UINT32_C(  1602970389) },
      {  UINT32_C(   389994768),  UINT32_C(  1530119450),  UINT32_C(  1339252238),  UINT32_C(  2864754083) },
         INT8_C(           1),
      {  UINT64_C(872560871223053900),  UINT64_C(2452736169982966050) } },
    { {  UINT32_C(   941321015),  UINT32_C(    58916583),  UINT32_C(  2573487856),  UINT32_C(  3136710970) },
      {  UINT32_C(  1076679722),  UINT32_C(  2784996759),  UINT32_C(  2523575539),  UINT32_C(   648447174) },
         INT8_C(           1),
      {  UINT64_C(7167155338285858704),  UINT64_C(8735729885369746230) } },
    { {  UINT32_C(  1093123563),  UINT32_C(  4177699859),  UINT32_C(  2905876725),  UINT32_C(  1293103231) },
      {  UINT32_C(  3015090390),  UINT32_C(  3584139392),  UINT32_C(  3621414738),  UINT32_C(  3496608656) },
         INT8_C(           1),
      {  UINT64_C(10415067238368451200),  UINT64_C(4634662228149575552) } },
    { {  UINT32_C(  3890536861),  UINT32_C(  1544989142),  UINT32_C(  2104229795),  UINT32_C(  2267825439) },
      {  UINT32_C(  1041030163),  UINT32_C(  3127515421),  UINT32_C(  3385673836),  UINT32_C(   551975707) },
         INT8_C(           0),
      {  UINT64_C(2190566686478306585),  UINT64_C(2360874686417716557) } },
    { {  UINT32_C(  2279282619),  UINT32_C(   284283076),  UINT32_C(  4117518980),  UINT32_C(  1088796040) },
      {  UINT32_C(   268087303),  UINT32_C(  1357085991),  UINT32_C(  1614578665),  UINT32_C(  3664898721) },
         INT8_C(           1),
      {  UINT64_C(5587827325434609180),  UINT64_C(1477589852940275640) } },
    { {  UINT32_C(  3480333801),  UINT32_C(  2627663825),  UINT32_C(  3301783258),  UINT32_C(  2163233263) },
      {  UINT32_C(  2137125469),  UINT32_C(  1894759449),  UINT32_C(  3620132959),  UINT32_C(  1379867384) },
         INT8_C(           0),
      {  UINT64_C(7056325093789598002),  UINT64_C(4623100901745275347) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t v = simde_vld1q_u32(test_vec[i].v);
    simde_uint64x2_t r;

    SIMDE_CONSTIFY_4_(simde_vmull_high_laneq_u32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t v = simde_test_arm_neon_random_u32x4();
    int lane = simde_test_codegen_random_i8() & 3;

    simde_uint64x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmull_high_laneq_u32, r, (HEDLEY_UNREACHABLE(), r), lane, a, v);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u8(2, HEDLEY_STATIC_CAST(uint8_t, lane), SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_laneq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
