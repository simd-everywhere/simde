#include "simde/simde-constify.h"
#define SIMDE_TEST_ARM_NEON_INSN mlsl_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mlsl_lane.h"

static int
test_simde_vmlsl_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t v[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   126516375),  INT32_C(   380504594),  INT32_C(  1727111290),  INT32_C(  1092308080) },
      {  INT16_C( 25602), -INT16_C( 30017),  INT16_C( 22297), -INT16_C( 21788) },
      { -INT16_C(   240),  INT16_C( 29764),  INT16_C( 24559),  INT16_C( 22628) },
       // INT16_C(     2),
      { -INT32_C(   755275893),  INT32_C(  1117692097),  INT32_C(  1179519267),  INT32_C(  1627399572) } },
    { { -INT32_C(   470527527), -INT32_C(  1621226497),  INT32_C(  1225770236),  INT32_C(  1129009631) },
      { -INT16_C( 10992),  INT16_C( 26461),  INT16_C(  1977), -INT16_C( 18057) },
      { -INT16_C(  5044), -INT16_C( 21592),  INT16_C(    80),  INT16_C( 10638) },
       // INT16_C(     1),
      { -INT32_C(   707866791), -INT32_C(  1049880585),  INT32_C(  1268457620),  INT32_C(   739122887) } },
    { { -INT32_C(  1924133502),  INT32_C(   797634667),  INT32_C(  1343149055), -INT32_C(   194948834) },
      { -INT16_C( 14162), -INT16_C( 18771),  INT16_C( 26176),  INT16_C( 11266) },
      { -INT16_C( 21234),  INT16_C(  3964), -INT16_C( 23237), -INT16_C( 16800) },
       // INT16_C(     2),
      {  INT32_C(  2041751400),  INT32_C(   361452940),  INT32_C(  1951400767),  INT32_C(    66839208) } },
    { { -INT32_C(  1591915599), -INT32_C(  1465889579), -INT32_C(  1396182694),  INT32_C(   442153810) },
      {  INT16_C(  4200), -INT16_C( 12454), -INT16_C( 31214), -INT16_C( 16163) },
      { -INT16_C(  5118), -INT16_C( 22277), -INT16_C( 18099), -INT16_C(   422) },
       // INT16_C(     1),
      { -INT32_C(  1498352199), -INT32_C(  1743327337), -INT32_C(  2091536972),  INT32_C(    82090659) } },
    { { -INT32_C(   992305288),  INT32_C(   807371583),  INT32_C(    92457802),  INT32_C(   913153317) },
      {  INT16_C( 15607),  INT16_C( 32328),  INT16_C(  2074),  INT16_C(  1664) },
      {  INT16_C( 10244), -INT16_C( 17069),  INT16_C( 20867), -INT16_C(  1086) },
       // INT16_C(     0),
      { -INT32_C(  1152183396),  INT32_C(   476203551),  INT32_C(    71211746),  INT32_C(   896107301) } },
    { {  INT32_C(   540065693), -INT32_C(  1452646178), -INT32_C(  2133889053),  INT32_C(   427230684) },
      { -INT16_C(  2739),  INT16_C( 22067),  INT16_C( 14710), -INT16_C( 24998) },
      {  INT16_C(  6029), -INT16_C(  8671),  INT16_C(  7386),  INT16_C( 30671) },
       // INT16_C(     0),
      {  INT32_C(   556579124), -INT32_C(  1585688121),  INT32_C(  2072391653),  INT32_C(   577943626) } },
    { {  INT32_C(  1606064127),  INT32_C(  1883399169),  INT32_C(   944554547),  INT32_C(   797271354) },
      { -INT16_C(  9320), -INT16_C( 11611),  INT16_C( 17461),  INT16_C( 19807) },
      {  INT16_C( 15717), -INT16_C( 32217), -INT16_C( 25076),  INT16_C(  2910) },
       // INT16_C(     1),
      {  INT32_C(  1305801687),  INT32_C(  1509327582),  INT32_C(  1507095584),  INT32_C(  1435393473) } },
    { {  INT32_C(  2083941144),  INT32_C(  1890559661),  INT32_C(  1487595506),  INT32_C(  1223743853) },
      { -INT16_C( 15745), -INT16_C( 15490), -INT16_C( 13535),  INT16_C( 24360) },
      { -INT16_C( 21774), -INT16_C( 28565),  INT16_C( 30472),  INT16_C(  8645) },
       // INT16_C(     2),
      { -INT32_C(  1731244512), -INT32_C(  1932396355),  INT32_C(  1900034026),  INT32_C(   481445933) } }
  };

    simde_int32x4_t a, r;
    simde_int16x4_t b, v;

    a = simde_vld1q_s32(test_vec[0].a);
    b = simde_vld1_s16(test_vec[0].b);
    v = simde_vld1_s16(test_vec[0].v);
    r = simde_vmlsl_lane_s16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[0].r));

    a = simde_vld1q_s32(test_vec[1].a);
    b = simde_vld1_s16(test_vec[1].b);
    v = simde_vld1_s16(test_vec[1].v);
    r = simde_vmlsl_lane_s16(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[1].r));

    a = simde_vld1q_s32(test_vec[2].a);
    b = simde_vld1_s16(test_vec[2].b);
    v = simde_vld1_s16(test_vec[2].v);
    r = simde_vmlsl_lane_s16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[2].r));

    a = simde_vld1q_s32(test_vec[3].a);
    b = simde_vld1_s16(test_vec[3].b);
    v = simde_vld1_s16(test_vec[3].v);
    r = simde_vmlsl_lane_s16(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[3].r));

    a = simde_vld1q_s32(test_vec[4].a);
    b = simde_vld1_s16(test_vec[4].b);
    v = simde_vld1_s16(test_vec[4].v);
    r = simde_vmlsl_lane_s16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[4].r));

    a = simde_vld1q_s32(test_vec[5].a);
    b = simde_vld1_s16(test_vec[5].b);
    v = simde_vld1_s16(test_vec[5].v);
    r = simde_vmlsl_lane_s16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[5].r));

    a = simde_vld1q_s32(test_vec[6].a);
    b = simde_vld1_s16(test_vec[6].b);
    v = simde_vld1_s16(test_vec[6].v);
    r = simde_vmlsl_lane_s16(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[6].r));

    a = simde_vld1q_s32(test_vec[7].a);
    b = simde_vld1_s16(test_vec[7].b);
    v = simde_vld1_s16(test_vec[7].v);
    r = simde_vmlsl_lane_s16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    int8_t lane = simde_test_codegen_random_i8() & 3;
    simde_int32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vmlsl_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), lane, a, b, v);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t v[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 3788652420436827643), -INT64_C( 7060823032941384791) },
      {  INT32_C(   868271464), -INT32_C(  1742397459) },
      {  INT32_C(    27309450),  INT32_C(  1977860474) },
       // INT32_C(           1),
      {  INT64_C( 2071332611089113707), -INT64_C( 3614603968787249225) } },
    { { -INT64_C( 7702034244332415373),  INT64_C( 7409564472914845570) },
      { -INT32_C(   296548401), -INT32_C(   512103636) },
      {  INT32_C(  1297840780), -INT32_C(   777203618) },
       // INT32_C(           0),
      { -INT64_C( 7317161636270822593),  INT64_C( 8074193455301921650) } },
    { { -INT64_C(   91439376024779944),  INT64_C(  176772863747893141) },
      {  INT32_C(  1143890777),  INT32_C(  1456476124) },
      {  INT32_C(   984882794),  INT32_C(   589333962) },
       // INT32_C(           1),
      { -INT64_C(  765573059729448418), -INT64_C(  681577980967430147) } },
    { {  INT64_C( 4497168686203296943), -INT64_C( 1863017433594786106) },
      {  INT32_C(  2026006889),  INT32_C(  1491212346) },
      {  INT32_C(  1377967309), -INT32_C(   350534340) },
       // INT32_C(           1),
      {  INT64_C( 5207353673874365203), -INT64_C( 1340296298089824466) } },
    { {  INT64_C( 3977230603706220356), -INT64_C( 8299113618633720529) },
      {  INT32_C(  2076592994),  INT32_C(  1229463085) },
      { -INT32_C(  2038064576), -INT32_C(    98078282) },
       // INT32_C(           0),
      {  INT64_C( 8209461223547400900), -INT64_C( 5793388457595543569) } },
    { { -INT64_C( 7780371229208648224), -INT64_C( 8120480214305836981) },
      {  INT32_C(   649971976), -INT32_C(  1402534383) },
      { -INT32_C(    43848308), -INT32_C(   198353900) },
       // INT32_C(           1),
      { -INT64_C( 7651446752878341824), -INT64_C( 8398678379057980681) } },
    { {  INT64_C( 4711868918448769927),  INT64_C( 7488665527569960866) },
      { -INT32_C(   663153710),  INT32_C(  1734616442) },
      { -INT32_C(   478387833),  INT32_C(   379875471) },
       // INT32_C(           1),
      {  INT64_C( 4963784746380417337),  INT64_C( 6829727289660866684) } },
    { { -INT64_C( 2195136954812846341),  INT64_C( 7978942967962365395) },
      { -INT32_C(  2065132705),  INT32_C(  1493913847) },
      {  INT32_C(  1021898444), -INT32_C(  1904673134) },
       // INT32_C(           0),
      { -INT64_C(   84781056919835321),  INT64_C( 6452314732243011327) } }
  };

    simde_int64x2_t a, r;
    simde_int32x2_t b, v;

    a = simde_vld1q_s64(test_vec[0].a);
    b = simde_vld1_s32(test_vec[0].b);
    v = simde_vld1_s32(test_vec[0].v);
    r = simde_vmlsl_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[0].r));

    a = simde_vld1q_s64(test_vec[1].a);
    b = simde_vld1_s32(test_vec[1].b);
    v = simde_vld1_s32(test_vec[1].v);
    r = simde_vmlsl_lane_s32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[1].r));

    a = simde_vld1q_s64(test_vec[2].a);
    b = simde_vld1_s32(test_vec[2].b);
    v = simde_vld1_s32(test_vec[2].v);
    r = simde_vmlsl_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[2].r));

    a = simde_vld1q_s64(test_vec[3].a);
    b = simde_vld1_s32(test_vec[3].b);
    v = simde_vld1_s32(test_vec[3].v);
    r = simde_vmlsl_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[3].r));

    a = simde_vld1q_s64(test_vec[4].a);
    b = simde_vld1_s32(test_vec[4].b);
    v = simde_vld1_s32(test_vec[4].v);
    r = simde_vmlsl_lane_s32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[4].r));

    a = simde_vld1q_s64(test_vec[5].a);
    b = simde_vld1_s32(test_vec[5].b);
    v = simde_vld1_s32(test_vec[5].v);
    r = simde_vmlsl_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[5].r));

    a = simde_vld1q_s64(test_vec[6].a);
    b = simde_vld1_s32(test_vec[6].b);
    v = simde_vld1_s32(test_vec[6].v);
    r = simde_vmlsl_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[6].r));

    a = simde_vld1q_s64(test_vec[7].a);
    b = simde_vld1_s32(test_vec[7].b);
    v = simde_vld1_s32(test_vec[7].v);
    r = simde_vmlsl_lane_s32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    int8_t lane = simde_test_codegen_random_i8() & 1;
    simde_int64x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmlsl_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s64(0)), lane, a, b, v);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[4];
    uint16_t v[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3535631748), UINT32_C(1806081790), UINT32_C(  80121373), UINT32_C(3697488969) },
      { UINT16_C(59420), UINT16_C(27859), UINT16_C(11507), UINT16_C(57912) },
      { UINT16_C(29972), UINT16_C( 4724), UINT16_C(  749), UINT16_C(28990) },
       // INT32_C(           3),
      { UINT32_C(1813045948), UINT32_C( 998449380), UINT32_C(4041500739), UINT32_C(2018620089) } },
    { { UINT32_C(2591376636), UINT32_C(2025382378), UINT32_C(3686907047), UINT32_C( 133668127) },
      { UINT16_C(25713), UINT16_C(40443), UINT16_C(56732), UINT16_C( 4530) },
      { UINT16_C(50257), UINT16_C(21758), UINT16_C(28675), UINT16_C(65483) },
       // INT32_C(           0),
      { UINT32_C(1299118395), UINT32_C(4287805823), UINT32_C( 835726923), UINT32_C(4200971213) } },
    { { UINT32_C( 580819265), UINT32_C( 231282257), UINT32_C(1965925592), UINT32_C(4293276827) },
      { UINT16_C(33839), UINT16_C( 3228), UINT16_C(44342), UINT16_C(64094) },
      { UINT16_C(45740), UINT16_C( 7421), UINT16_C(64637), UINT16_C(48848) },
       // INT32_C(           2),
      { UINT32_C(2688535118), UINT32_C(  22634021), UINT32_C(3394759034), UINT32_C( 150432949) } },
    { { UINT32_C(2229788782), UINT32_C(1297937833), UINT32_C(1458164258), UINT32_C(1015474360) },
      { UINT16_C(37508), UINT16_C(12914), UINT16_C(28144), UINT16_C(41694) },
      { UINT16_C(64106), UINT16_C(26400), UINT16_C(57034), UINT16_C(14589) },
       // INT32_C(           3),
      { UINT32_C(1682584570), UINT32_C(1109535487), UINT32_C(1047571442), UINT32_C( 407200594) } },
    { { UINT32_C(3647519972), UINT32_C(3959141913), UINT32_C(2275627679), UINT32_C(1779228888) },
      { UINT16_C(15954), UINT16_C(48987), UINT16_C(64796), UINT16_C( 5674) },
      { UINT16_C(37149), UINT16_C(64736), UINT16_C( 6286), UINT16_C(29371) },
       // INT32_C(           0),
      { UINT32_C(3054844826), UINT32_C(2139323850), UINT32_C(4163488371), UINT32_C(1568445462) } },
    { { UINT32_C(3656207395), UINT32_C(2574833735), UINT32_C(1550909564), UINT32_C(1252973580) },
      { UINT16_C(28215), UINT16_C(13414), UINT16_C(31896), UINT16_C(10578) },
      { UINT16_C(20060), UINT16_C(29879), UINT16_C(10505), UINT16_C(11336) },
       // INT32_C(           1),
      { UINT32_C(2813171410), UINT32_C(2174036829), UINT32_C( 597888980), UINT32_C( 936913518) } },
    { { UINT32_C( 247268918), UINT32_C(2122995326), UINT32_C(2760566472), UINT32_C(  64738453) },
      { UINT16_C( 3898), UINT16_C(46747), UINT16_C(50273), UINT16_C(44818) },
      { UINT16_C(34427), UINT16_C(42168), UINT16_C(58831), UINT16_C( 1306) },
       // INT32_C(           3),
      { UINT32_C( 242178130), UINT32_C(2061943744), UINT32_C(2694909934), UINT32_C(   6206145) } },
    { { UINT32_C( 761861079), UINT32_C(2230708382), UINT32_C(1192860018), UINT32_C(2223053940) },
      { UINT16_C(14519), UINT16_C(31717), UINT16_C(38218), UINT16_C(53750) },
      { UINT16_C(39757), UINT16_C(12960), UINT16_C(42421), UINT16_C(35869) },
       // INT32_C(           0),
      { UINT32_C( 184629196), UINT32_C( 969735613), UINT32_C(3968394288), UINT32_C(  86115190) } }
  };

    simde_uint32x4_t a, r;
    simde_uint16x4_t b, v;

    a = simde_vld1q_u32(test_vec[0].a);
    b = simde_vld1_u16(test_vec[0].b);
    v = simde_vld1_u16(test_vec[0].v);
    r = simde_vmlsl_lane_u16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[0].r));

    a = simde_vld1q_u32(test_vec[1].a);
    b = simde_vld1_u16(test_vec[1].b);
    v = simde_vld1_u16(test_vec[1].v);
    r = simde_vmlsl_lane_u16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[1].r));

    a = simde_vld1q_u32(test_vec[2].a);
    b = simde_vld1_u16(test_vec[2].b);
    v = simde_vld1_u16(test_vec[2].v);
    r = simde_vmlsl_lane_u16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[2].r));

    a = simde_vld1q_u32(test_vec[3].a);
    b = simde_vld1_u16(test_vec[3].b);
    v = simde_vld1_u16(test_vec[3].v);
    r = simde_vmlsl_lane_u16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[3].r));

    a = simde_vld1q_u32(test_vec[4].a);
    b = simde_vld1_u16(test_vec[4].b);
    v = simde_vld1_u16(test_vec[4].v);
    r = simde_vmlsl_lane_u16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[4].r));

    a = simde_vld1q_u32(test_vec[5].a);
    b = simde_vld1_u16(test_vec[5].b);
    v = simde_vld1_u16(test_vec[5].v);
    r = simde_vmlsl_lane_u16(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[5].r));

    a = simde_vld1q_u32(test_vec[6].a);
    b = simde_vld1_u16(test_vec[6].b);
    v = simde_vld1_u16(test_vec[6].v);
    r = simde_vmlsl_lane_u16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[6].r));

    a = simde_vld1q_u32(test_vec[7].a);
    b = simde_vld1_u16(test_vec[7].b);
    v = simde_vld1_u16(test_vec[7].v);
    r = simde_vmlsl_lane_u16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t v = simde_test_arm_neon_random_u16x4();
    uint8_t lane = simde_test_codegen_random_u8() & 3;
    simde_uint32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vmlsl_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(0)), lane, a, b, v);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[2];
    uint32_t v[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 5251720187024423303), UINT64_C(16341383446611699956) },
      { UINT32_C(3140240422), UINT32_C(3574201658) },
      { UINT32_C(1116355485), UINT32_C(3774551641) },
       // INT32_C(           0),
      { UINT64_C( 1746095567706008633), UINT64_C(12351303821207305826) } },
    { { UINT64_C( 6422633553325936465), UINT64_C( 4534251790065152644) },
      { UINT32_C( 259630865), UINT32_C(3970715312) },
      { UINT32_C(4014338009), UINT32_C(1002382826) },
       // INT32_C(           0),
      { UINT64_C( 5380387503646888680), UINT64_C( 7041202463894810452) } },
    { { UINT64_C(13513892396842379326), UINT64_C(16426866708246253568) },
      { UINT32_C(3147040365), UINT32_C(2710864050) },
      { UINT32_C(3935012037), UINT32_C(2187249475) },
       // INT32_C(           1),
      { UINT64_C( 6630530010692320951), UINT64_C(10497530738087379818) } },
    { { UINT64_C( 7061770736875636738), UINT64_C(16395779804598560296) },
      { UINT32_C(2526364950), UINT32_C(1566259161) },
      { UINT32_C(2309047746), UINT32_C(2780308387) },
       // INT32_C(           1),
      { UINT64_C(   37697077767801088), UINT64_C(12041096323054676989) } },
    { { UINT64_C(10091476766187955568), UINT64_C(17822516903833839806) },
      { UINT32_C( 416345313), UINT32_C(2363174471) },
      { UINT32_C(4063192271), UINT32_C(2375931165) },
       // INT32_C(           0),
      { UINT64_C( 8399785708339279745), UINT64_C( 8220484658242126165) } },
    { { UINT64_C(11905736744850452826), UINT64_C(13565773159463352597) },
      { UINT32_C(1292131103), UINT32_C(2602340406) },
      { UINT32_C(2511867584), UINT32_C(  84886955) },
       // INT32_C(           0),
      { UINT64_C( 8660074512946587674), UINT64_C( 7029038651098553493) } },
    { { UINT64_C( 3671236038546915376), UINT64_C(17482621456595702576) },
      { UINT32_C(1395190723), UINT32_C( 353616647) },
      { UINT32_C(3250628731), UINT32_C(3900163512) },
       // INT32_C(           1),
      { UINT64_C(16676508162130967816), UINT64_C(16103458712730518312) } },
    { { UINT64_C(  771296096172295339), UINT64_C(13597936080331486003) },
      { UINT32_C(2126711227), UINT32_C(3321550876) },
      { UINT32_C(1585298328), UINT32_C(3718473010) },
       // INT32_C(           1),
      { UINT64_C(11309921872218363685), UINT64_C( 1246838796583629243) } }
  };

    simde_uint64x2_t a, r;
    simde_uint32x2_t b, v;

    a = simde_vld1q_u64(test_vec[0].a);
    b = simde_vld1_u32(test_vec[0].b);
    v = simde_vld1_u32(test_vec[0].v);
    r = simde_vmlsl_lane_u32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[0].r));

    a = simde_vld1q_u64(test_vec[1].a);
    b = simde_vld1_u32(test_vec[1].b);
    v = simde_vld1_u32(test_vec[1].v);
    r = simde_vmlsl_lane_u32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[1].r));

    a = simde_vld1q_u64(test_vec[2].a);
    b = simde_vld1_u32(test_vec[2].b);
    v = simde_vld1_u32(test_vec[2].v);
    r = simde_vmlsl_lane_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[2].r));

    a = simde_vld1q_u64(test_vec[3].a);
    b = simde_vld1_u32(test_vec[3].b);
    v = simde_vld1_u32(test_vec[3].v);
    r = simde_vmlsl_lane_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[3].r));

    a = simde_vld1q_u64(test_vec[4].a);
    b = simde_vld1_u32(test_vec[4].b);
    v = simde_vld1_u32(test_vec[4].v);
    r = simde_vmlsl_lane_u32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[4].r));

    a = simde_vld1q_u64(test_vec[5].a);
    b = simde_vld1_u32(test_vec[5].b);
    v = simde_vld1_u32(test_vec[5].v);
    r = simde_vmlsl_lane_u32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[5].r));

    a = simde_vld1q_u64(test_vec[6].a);
    b = simde_vld1_u32(test_vec[6].b);
    v = simde_vld1_u32(test_vec[6].v);
    r = simde_vmlsl_lane_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[6].r));

    a = simde_vld1q_u64(test_vec[7].a);
    b = simde_vld1_u32(test_vec[7].b);
    v = simde_vld1_u32(test_vec[7].v);
    r = simde_vmlsl_lane_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t v = simde_test_arm_neon_random_u32x2();
    uint8_t lane = simde_test_codegen_random_u8() & 1;
    simde_uint64x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmlsl_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u64(0)), lane, a, b, v);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t v[8];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   740269662),  INT32_C(  1225189910),  INT32_C(   488372618), -INT32_C(  1210525778) },
      {  INT16_C( 22171),  INT16_C( 29652), -INT16_C( 26288),  INT16_C(  2828) },
      {  INT16_C( 27158),  INT16_C( 31550),  INT16_C(  6925), -INT16_C( 20572), -INT16_C( 31619), -INT16_C( 27774), -INT16_C( 30354), -INT16_C(  1572) },
       // INT32_C(           2),
      { -INT32_C(   893803837),  INT32_C(  1019849810),  INT32_C(   670417018), -INT32_C(  1230109678) } },
    { { -INT32_C(   818931977),  INT32_C(  1147857134),  INT32_C(  1435884988),  INT32_C(  1399562473) },
      { -INT16_C(  6434), -INT16_C(  1439),  INT16_C(  4234),  INT16_C(  3959) },
      {  INT16_C(  2707),  INT16_C(  7293),  INT16_C( 30438), -INT16_C(  8546), -INT16_C( 12660),  INT16_C( 31405),  INT16_C(  6070),  INT16_C( 29375) },
       // INT32_C(           4),
      { -INT32_C(   900386417),  INT32_C(  1129639394),  INT32_C(  1489487428),  INT32_C(  1449683413) } },
    { { -INT32_C(   186726572),  INT32_C(   416493874), -INT32_C(  1549546094),  INT32_C(  1312207428) },
      {  INT16_C( 21039), -INT16_C( 22988),  INT16_C(  4848), -INT16_C( 16846) },
      { -INT16_C( 21057), -INT16_C( 10635), -INT16_C(  6292), -INT16_C( 16181), -INT16_C( 22097), -INT16_C(  7756), -INT16_C( 30758),  INT16_C( 28154) },
       // INT32_C(           4),
      {  INT32_C(   278172211), -INT32_C(    91471962), -INT32_C(  1442419838),  INT32_C(   939961366) } },
    { {  INT32_C(  1335365789), -INT32_C(  1736513978),  INT32_C(   763896859),  INT32_C(    82658903) },
      { -INT16_C( 15429), -INT16_C( 23696),  INT16_C( 12430),  INT16_C( 14162) },
      {  INT16_C( 13284),  INT16_C( 27666),  INT16_C( 32557), -INT16_C( 13632),  INT16_C( 22927), -INT16_C( 10983), -INT16_C( 26561),  INT16_C( 23149) },
       // INT32_C(           4),
      {  INT32_C(  1689106472), -INT32_C(  1193235786),  INT32_C(   478914249), -INT32_C(   242033271) } },
    { {  INT32_C(   991135989),  INT32_C(   955717493), -INT32_C(  1211655545),  INT32_C(   530382572) },
      {  INT16_C(  2064), -INT16_C( 28851),  INT16_C(  6088),  INT16_C(  8478) },
      { -INT16_C(  3279), -INT16_C( 13983), -INT16_C( 17568),  INT16_C( 21893), -INT16_C( 26301), -INT16_C( 18287), -INT16_C( 30544),  INT16_C( 14577) },
       // INT32_C(           2),
      {  INT32_C(  1027396341),  INT32_C(   448863125), -INT32_C(  1104701561),  INT32_C(   679324076) } },
    { { -INT32_C(  1240535112), -INT32_C(  1815663221), -INT32_C(  1839442310),  INT32_C(  1757642101) },
      { -INT16_C( 29474), -INT16_C( 25911),  INT16_C(  7697), -INT16_C( 21795) },
      { -INT16_C( 26961),  INT16_C( 14171), -INT16_C( 27769),  INT16_C( 16217),  INT16_C( 26498),  INT16_C(  3829), -INT16_C( 17259),  INT16_C(  4001) },
       // INT32_C(           3),
      { -INT32_C(   762555254), -INT32_C(  1395464534), -INT32_C(  1964264559),  INT32_C(  2111091616) } },
    { {  INT32_C(  2072551933), -INT32_C(   262541212), -INT32_C(   670895175),  INT32_C(  1736944849) },
      { -INT16_C( 16633), -INT16_C( 25874),  INT16_C( 11544), -INT16_C( 32739) },
      {  INT16_C( 11042), -INT16_C(  8427),  INT16_C(  9420), -INT16_C( 13582),  INT16_C( 31430),  INT16_C( 10821), -INT16_C( 24982),  INT16_C(  9243) },
       // INT32_C(           2),
      { -INT32_C(  2065732503), -INT32_C(    18808132), -INT32_C(   779639655),  INT32_C(  2045346229) } },
    { { -INT32_C(   916194275),  INT32_C(  1121045123), -INT32_C(   446993480), -INT32_C(  1291330680) },
      { -INT16_C(  6416),  INT16_C(  5248),  INT16_C( 19160),  INT16_C( 21210) },
      {  INT16_C(  1423),  INT16_C( 11709), -INT16_C(  7904),  INT16_C( 15807),  INT16_C(  8925),  INT16_C( 24582), -INT16_C( 10260), -INT16_C( 23389) },
       // INT32_C(           3),
      { -INT32_C(   814776563),  INT32_C(  1038089987), -INT32_C(   749855600), -INT32_C(  1626597150) } }
  };

    simde_int32x4_t a, r;
    simde_int16x4_t b;
    simde_int16x8_t v;

    a = simde_vld1q_s32(test_vec[0].a);
    b = simde_vld1_s16(test_vec[0].b);
    v = simde_vld1q_s16(test_vec[0].v);
    r = simde_vmlsl_laneq_s16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[0].r));

    a = simde_vld1q_s32(test_vec[1].a);
    b = simde_vld1_s16(test_vec[1].b);
    v = simde_vld1q_s16(test_vec[1].v);
    r = simde_vmlsl_laneq_s16(a, b, v, 4);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[1].r));

    a = simde_vld1q_s32(test_vec[2].a);
    b = simde_vld1_s16(test_vec[2].b);
    v = simde_vld1q_s16(test_vec[2].v);
    r = simde_vmlsl_laneq_s16(a, b, v, 4);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[2].r));

    a = simde_vld1q_s32(test_vec[3].a);
    b = simde_vld1_s16(test_vec[3].b);
    v = simde_vld1q_s16(test_vec[3].v);
    r = simde_vmlsl_laneq_s16(a, b, v, 4);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[3].r));

    a = simde_vld1q_s32(test_vec[4].a);
    b = simde_vld1_s16(test_vec[4].b);
    v = simde_vld1q_s16(test_vec[4].v);
    r = simde_vmlsl_laneq_s16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[4].r));

    a = simde_vld1q_s32(test_vec[5].a);
    b = simde_vld1_s16(test_vec[5].b);
    v = simde_vld1q_s16(test_vec[5].v);
    r = simde_vmlsl_laneq_s16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[5].r));

    a = simde_vld1q_s32(test_vec[6].a);
    b = simde_vld1_s16(test_vec[6].b);
    v = simde_vld1q_s16(test_vec[6].v);
    r = simde_vmlsl_laneq_s16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[6].r));

    a = simde_vld1q_s32(test_vec[7].a);
    b = simde_vld1_s16(test_vec[7].b);
    v = simde_vld1q_s16(test_vec[7].v);
    r = simde_vmlsl_laneq_s16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    int8_t lane = simde_test_codegen_random_i8() & 7;
    simde_int32x4_t r;

    SIMDE_CONSTIFY_8_(simde_vmlsl_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), lane, a, b, v);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t v[4];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8631570425233246718), -INT64_C( 4766881293183951361) },
      {  INT32_C(  1088226655), -INT32_C(   417523003) },
      { -INT32_C(   120291808),  INT32_C(   523991073), -INT32_C(  1812462078), -INT32_C(  2079669883) },
       // INT32_C(           2),
      { -INT64_C( 7842804104020015808), -INT64_C( 5523625902814131595) } },
    { { -INT64_C( 6098978191725638310),  INT64_C( 4047425146673208816) },
      { -INT32_C(  1537662165),  INT32_C(  1688631390) },
      {  INT32_C(   837433712), -INT32_C(  1630507453), -INT32_C(   509925828),  INT32_C(   713881402) },
       // INT32_C(           0),
      { -INT64_C( 4811288057087731830),  INT64_C( 2633308293545789136) } },
    { { -INT64_C( 8971303084897651204),  INT64_C(  201049864470078433) },
      { -INT32_C(  1639515345), -INT32_C(   220535605) },
      {  INT32_C(  1982643071),  INT32_C(  1141593672), -INT32_C(   342336885), -INT32_C(  1032972063) },
       // INT32_C(           3),
      {  INT64_C( 7781867440567093677), -INT64_C(   26757254391724682) } },
    { { -INT64_C( 2178607632816464817), -INT64_C(  526746075522047411) },
      {  INT32_C(   557852619), -INT32_C(  1934785486) },
      {  INT32_C(   896374813),  INT32_C(  1450192903),  INT32_C(   854291788), -INT32_C(   904679299) },
       // INT32_C(           2),
      { -INT64_C( 2655176544142457589),  INT64_C( 1126125276709341557) } },
    { { -INT64_C( 3230690977025884992), -INT64_C( 7986973440323793785) },
      {  INT32_C(   798514687),  INT32_C(  1132195790) },
      { -INT32_C(  1967084070), -INT32_C(  2120381504),  INT32_C(   870378631), -INT32_C(  1173943501) },
       // INT32_C(           3),
      { -INT64_C( 2293279849769185805), -INT64_C( 6657839550793732995) } },
    { {  INT64_C( 5448759539162727692), -INT64_C(  845729743728161670) },
      { -INT32_C(  1464545763),  INT32_C(  1462711659) },
      {  INT32_C(   562717462),  INT32_C(  1987593322), -INT32_C(   149633015),  INT32_C(   591638953) },
       // INT32_C(           1),
      {  INT64_C( 8359680917464922378), -INT64_C( 3753005669168102868) } },
    { { -INT64_C( 7000923889114772388),  INT64_C( 1348934395851538285) },
      {  INT32_C(   779934186),  INT32_C(   423096913) },
      { -INT32_C(  1195167993), -INT32_C(   835262862),  INT32_C(  1133050483),  INT32_C(   551641011) },
       // INT32_C(           2),
      { -INT64_C( 7884628695270284226),  INT64_C(  869544234221079306) } },
    { {  INT64_C( 6067649949855498986), -INT64_C( 4029103627516354021) },
      {  INT32_C(  1765461378), -INT32_C(    19134205) },
      { -INT32_C(   256827503), -INT32_C(   355544832),  INT32_C(   238312595),  INT32_C(   392390907) },
       // INT32_C(           2),
      {  INT64_C( 5646918267492043076), -INT64_C( 4024543705469542046) } }
  };

    simde_int64x2_t a, r;
    simde_int32x2_t b;
    simde_int32x4_t v;

    a = simde_vld1q_s64(test_vec[0].a);
    b = simde_vld1_s32(test_vec[0].b);
    v = simde_vld1q_s32(test_vec[0].v);
    r = simde_vmlsl_laneq_s32(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[0].r));

    a = simde_vld1q_s64(test_vec[1].a);
    b = simde_vld1_s32(test_vec[1].b);
    v = simde_vld1q_s32(test_vec[1].v);
    r = simde_vmlsl_laneq_s32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[1].r));

    a = simde_vld1q_s64(test_vec[2].a);
    b = simde_vld1_s32(test_vec[2].b);
    v = simde_vld1q_s32(test_vec[2].v);
    r = simde_vmlsl_laneq_s32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[2].r));

    a = simde_vld1q_s64(test_vec[3].a);
    b = simde_vld1_s32(test_vec[3].b);
    v = simde_vld1q_s32(test_vec[3].v);
    r = simde_vmlsl_laneq_s32(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[3].r));

    a = simde_vld1q_s64(test_vec[4].a);
    b = simde_vld1_s32(test_vec[4].b);
    v = simde_vld1q_s32(test_vec[4].v);
    r = simde_vmlsl_laneq_s32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[4].r));

    a = simde_vld1q_s64(test_vec[5].a);
    b = simde_vld1_s32(test_vec[5].b);
    v = simde_vld1q_s32(test_vec[5].v);
    r = simde_vmlsl_laneq_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[5].r));

    a = simde_vld1q_s64(test_vec[6].a);
    b = simde_vld1_s32(test_vec[6].b);
    v = simde_vld1q_s32(test_vec[6].v);
    r = simde_vmlsl_laneq_s32(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[6].r));

    a = simde_vld1q_s64(test_vec[7].a);
    b = simde_vld1_s32(test_vec[7].b);
    v = simde_vld1q_s32(test_vec[7].v);
    r = simde_vmlsl_laneq_s32(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    int8_t lane = simde_test_codegen_random_i8() & 3;
    simde_int64x2_t r;

    SIMDE_CONSTIFY_4_(simde_vmlsl_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s64(0)), lane, a, b, v);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[4];
    uint16_t v[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3361940745), UINT32_C( 122367034), UINT32_C(1863038054), UINT32_C(2936015248) },
      { UINT16_C(61626), UINT16_C(35759), UINT16_C(39359), UINT16_C( 6942) },
      { UINT16_C(11725), UINT16_C(13590), UINT16_C(11664), UINT16_C(39423), UINT16_C(25170), UINT16_C(35937), UINT16_C(44174), UINT16_C(62868) },
       // INT32_C(           0),
      { UINT32_C(2639375895), UINT32_C(3998060055), UINT32_C(1401553779), UINT32_C(2854620298) } },
    { { UINT32_C(2834326687), UINT32_C(1432526693), UINT32_C(3876908366), UINT32_C( 951332619) },
      { UINT16_C(59718), UINT16_C(29640), UINT16_C(25064), UINT16_C(19398) },
      { UINT16_C(21187), UINT16_C(28633), UINT16_C(52966), UINT16_C(34256), UINT16_C(49203), UINT16_C(38957), UINT16_C(36704), UINT16_C(44781) },
       // INT32_C(           4),
      { UINT32_C(4190989229), UINT32_C(4269117069), UINT32_C(2643684374), UINT32_C(4291860121) } },
    { { UINT32_C( 831034882), UINT32_C( 880263242), UINT32_C(3927763849), UINT32_C(  61695921) },
      { UINT16_C( 7489), UINT16_C( 4074), UINT16_C(28653), UINT16_C(44354) },
      { UINT16_C(55965), UINT16_C(11277), UINT16_C(48328), UINT16_C(51881), UINT16_C(12626), UINT16_C(40187), UINT16_C(29681), UINT16_C(31440) },
       // INT32_C(           6),
      { UINT32_C( 608753873), UINT32_C( 759342848), UINT32_C(3077314156), UINT32_C(3040192143) } },
    { { UINT32_C(1410295277), UINT32_C( 798298642), UINT32_C(1813816828), UINT32_C(3255421671) },
      { UINT16_C(13783), UINT16_C(37770), UINT16_C(21726), UINT16_C( 4069) },
      { UINT16_C(33359), UINT16_C(49665), UINT16_C(31570), UINT16_C(16160), UINT16_C(12256), UINT16_C(62356), UINT16_C(10562), UINT16_C(15906) },
       // INT32_C(           6),
      { UINT32_C(1264719231), UINT32_C( 399371902), UINT32_C(1584346816), UINT32_C(3212444893) } },
    { { UINT32_C( 162966079), UINT32_C(3923802291), UINT32_C(1455911938), UINT32_C(3685078873) },
      { UINT16_C(26840), UINT16_C(21294), UINT16_C(28040), UINT16_C(47156) },
      { UINT16_C( 9985), UINT16_C(11258), UINT16_C(14409), UINT16_C(35065), UINT16_C(45027), UINT16_C(38545), UINT16_C(29223), UINT16_C(10623) },
       // INT32_C(           6),
      { UINT32_C(3673588055), UINT32_C(3301527729), UINT32_C( 636499018), UINT32_C(2307039085) } },
    { { UINT32_C( 507477831), UINT32_C(2381716261), UINT32_C(3054848329), UINT32_C(2763574653) },
      { UINT16_C(58311), UINT16_C(  238), UINT16_C(30428), UINT16_C(36067) },
      { UINT16_C(30984), UINT16_C(31411), UINT16_C(56825), UINT16_C(16480), UINT16_C(40796), UINT16_C(33118), UINT16_C(21690), UINT16_C(  782) },
       // INT32_C(           5),
      { UINT32_C(2871301429), UINT32_C(2373834177), UINT32_C(2047133825), UINT32_C(1569107747) } },
    { { UINT32_C(4045126180), UINT32_C(1438236530), UINT32_C( 607238573), UINT32_C( 355253660) },
      { UINT16_C(42609), UINT16_C(19982), UINT16_C(19974), UINT16_C(42410) },
      { UINT16_C(11436), UINT16_C(   96), UINT16_C(25402), UINT16_C(24222), UINT16_C(47389), UINT16_C(36688), UINT16_C( 2424), UINT16_C( 9956) },
       // INT32_C(           2),
      { UINT32_C(2962772362), UINT32_C( 930653766), UINT32_C(  99859025), UINT32_C(3572922136) } },
    { { UINT32_C(3546171926), UINT32_C( 474248054), UINT32_C(3491926658), UINT32_C(1769850685) },
      { UINT16_C(32039), UINT16_C(35747), UINT16_C(  539), UINT16_C(54440) },
      { UINT16_C(14418), UINT16_C(23373), UINT16_C(29468), UINT16_C(12829), UINT16_C(31677), UINT16_C(13062), UINT16_C(19182), UINT16_C(28751) },
       // INT32_C(           5),
      { UINT32_C(3127678508), UINT32_C(   7320740), UINT32_C(3484886240), UINT32_C(1058755405) } }
  };

    simde_uint32x4_t a, r;
    simde_uint16x4_t b;
    simde_uint16x8_t v;

    a = simde_vld1q_u32(test_vec[0].a);
    b = simde_vld1_u16(test_vec[0].b);
    v = simde_vld1q_u16(test_vec[0].v);
    r = simde_vmlsl_laneq_u16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[0].r));

    a = simde_vld1q_u32(test_vec[1].a);
    b = simde_vld1_u16(test_vec[1].b);
    v = simde_vld1q_u16(test_vec[1].v);
    r = simde_vmlsl_laneq_u16(a, b, v, 4);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[1].r));

    a = simde_vld1q_u32(test_vec[2].a);
    b = simde_vld1_u16(test_vec[2].b);
    v = simde_vld1q_u16(test_vec[2].v);
    r = simde_vmlsl_laneq_u16(a, b, v, 6);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[2].r));

    a = simde_vld1q_u32(test_vec[3].a);
    b = simde_vld1_u16(test_vec[3].b);
    v = simde_vld1q_u16(test_vec[3].v);
    r = simde_vmlsl_laneq_u16(a, b, v, 6);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[3].r));

    a = simde_vld1q_u32(test_vec[4].a);
    b = simde_vld1_u16(test_vec[4].b);
    v = simde_vld1q_u16(test_vec[4].v);
    r = simde_vmlsl_laneq_u16(a, b, v, 6);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[4].r));

    a = simde_vld1q_u32(test_vec[5].a);
    b = simde_vld1_u16(test_vec[5].b);
    v = simde_vld1q_u16(test_vec[5].v);
    r = simde_vmlsl_laneq_u16(a, b, v, 5);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[5].r));

    a = simde_vld1q_u32(test_vec[6].a);
    b = simde_vld1_u16(test_vec[6].b);
    v = simde_vld1q_u16(test_vec[6].v);
    r = simde_vmlsl_laneq_u16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[6].r));

    a = simde_vld1q_u32(test_vec[7].a);
    b = simde_vld1_u16(test_vec[7].b);
    v = simde_vld1q_u16(test_vec[7].v);
    r = simde_vmlsl_laneq_u16(a, b, v, 5);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x8_t v = simde_test_arm_neon_random_u16x8();
    uint8_t lane = simde_test_codegen_random_u8() & 7;
    simde_uint32x4_t r;

    SIMDE_CONSTIFY_8_(simde_vmlsl_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(0)), lane, a, b, v);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[2];
    uint32_t v[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 4278564499010240881), UINT64_C(14662079447895108390) },
      { UINT32_C(3957904760), UINT32_C(1839733490) },
      { UINT32_C(1801247520), UINT32_C(2605239338), UINT32_C(3419693581), UINT32_C( 185021669) },
       // INT32_C(           3),
      { UINT64_C( 3546266354571996441), UINT64_C(14321688887060113580) } },
    { { UINT64_C( 9512304651059475550), UINT64_C( 8188076932587777382) },
      { UINT32_C( 211553344), UINT32_C(3055171412) },
      { UINT32_C(1067181323), UINT32_C(1247717100), UINT32_C(2312376794), UINT32_C(4111324815) },
       // INT32_C(           3),
      { UINT64_C( 8642540138176044190), UINT64_C(14074018966063140218) } },
    { { UINT64_C( 2497187815483864451), UINT64_C(12946209344763376743) },
      { UINT32_C(1856039367), UINT32_C(1497950792) },
      { UINT32_C(2498286014), UINT32_C(1649991134), UINT32_C(1774825810), UINT32_C(3817566588) },
       // INT32_C(           1),
      { UINT64_C(17881483389288443889), UINT64_C(10474603818795098615) } },
    { { UINT64_C( 1582635027763790338), UINT64_C( 9146730218891600966) },
      { UINT32_C(2069660830), UINT32_C(2379136732) },
      { UINT32_C(4178196360), UINT32_C(3290361282), UINT32_C(2616398191), UINT32_C(4273072567) },
       // INT32_C(           1),
      { UINT64_C(13219447239569357894), UINT64_C( 1318510831334790542) } },
    { { UINT64_C(11701327230892846862), UINT64_C(16436463729668710356) },
      { UINT32_C(  61215510), UINT32_C(1114860337) },
      { UINT32_C(1207570014), UINT32_C(3465869503), UINT32_C(1167297831), UINT32_C(3655923205) },
       // INT32_C(           1),
      { UINT64_C(11489162261673255332), UINT64_C(12572503287556107845) } },
    { { UINT64_C(11063205212268424038), UINT64_C(  996999758403570701) },
      { UINT32_C(4291632391), UINT32_C(1042717617) },
      { UINT32_C( 608398382), UINT32_C(3136953428), UINT32_C( 237862024), UINT32_C(4037522915) },
       // INT32_C(           1),
      { UINT64_C(16047298345314689306), UINT64_C(16172787229028981241) } },
    { { UINT64_C( 6595326209654024306), UINT64_C( 1865698255582299931) },
      { UINT32_C(2859272334), UINT32_C(2133993474) },
      { UINT32_C( 174211157), UINT32_C(1514951400), UINT32_C(4175072442), UINT32_C(4115882714) },
       // INT32_C(           1),
      { UINT64_C( 2263667584279456706), UINT64_C(17079545928264687947) } },
    { { UINT64_C(10968429548556168031), UINT64_C( 6168270214495134237) },
      { UINT32_C(3443369339), UINT32_C(2106038257) },
      { UINT32_C(3562569586), UINT32_C( 834489810), UINT32_C(2296075257), UINT32_C( 555749891) },
       // INT32_C(           0),
      { UINT64_C(17147930741779395993), UINT64_C(17112106446864034251) } }
  };

    simde_uint64x2_t a, r;
    simde_uint32x2_t b;
    simde_uint32x4_t v;

    a = simde_vld1q_u64(test_vec[0].a);
    b = simde_vld1_u32(test_vec[0].b);
    v = simde_vld1q_u32(test_vec[0].v);
    r = simde_vmlsl_laneq_u32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[0].r));

    a = simde_vld1q_u64(test_vec[1].a);
    b = simde_vld1_u32(test_vec[1].b);
    v = simde_vld1q_u32(test_vec[1].v);
    r = simde_vmlsl_laneq_u32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[1].r));

    a = simde_vld1q_u64(test_vec[2].a);
    b = simde_vld1_u32(test_vec[2].b);
    v = simde_vld1q_u32(test_vec[2].v);
    r = simde_vmlsl_laneq_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[2].r));

    a = simde_vld1q_u64(test_vec[3].a);
    b = simde_vld1_u32(test_vec[3].b);
    v = simde_vld1q_u32(test_vec[3].v);
    r = simde_vmlsl_laneq_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[3].r));

    a = simde_vld1q_u64(test_vec[4].a);
    b = simde_vld1_u32(test_vec[4].b);
    v = simde_vld1q_u32(test_vec[4].v);
    r = simde_vmlsl_laneq_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[4].r));

    a = simde_vld1q_u64(test_vec[5].a);
    b = simde_vld1_u32(test_vec[5].b);
    v = simde_vld1q_u32(test_vec[5].v);
    r = simde_vmlsl_laneq_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[5].r));

    a = simde_vld1q_u64(test_vec[6].a);
    b = simde_vld1_u32(test_vec[6].b);
    v = simde_vld1q_u32(test_vec[6].v);
    r = simde_vmlsl_laneq_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[6].r));

    a = simde_vld1q_u64(test_vec[7].a);
    b = simde_vld1_u32(test_vec[7].b);
    v = simde_vld1q_u32(test_vec[7].v);
    r = simde_vmlsl_laneq_u32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x4_t v = simde_test_arm_neon_random_u32x4();
    uint8_t lane = simde_test_codegen_random_u8() & 3;
    simde_uint64x2_t r;

    SIMDE_CONSTIFY_4_(simde_vmlsl_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u64(0)), lane, a, b, v);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_laneq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
