#define SIMDE_TEST_ARM_NEON_INSN mlal

#include "test-neon.h"
#include "../../../simde/arm/neon/mlal.h"

static int
test_simde_vmlal_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t b[8];
    int8_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 22815),  INT16_C( 31689), -INT16_C(  3101), -INT16_C( 14571),  INT16_C(  4624), -INT16_C(  7544), -INT16_C( 30491),  INT16_C( 21581) },
      { -INT8_C(  66),  INT8_C(  81),  INT8_C( 115),  INT8_C(  86), -INT8_C(  49), -INT8_C(  27), -INT8_C(  75),  INT8_C(  12) },
      { -INT8_C( 122), -INT8_C(  95), -INT8_C(  63), -INT8_C(  71),  INT8_C(  63), -INT8_C( 125), -INT8_C(  33),  INT8_C(  94) },
      {  INT16_C( 30867),  INT16_C( 23994), -INT16_C( 10346), -INT16_C( 20677),  INT16_C(  1537), -INT16_C(  4169), -INT16_C( 28016),  INT16_C( 22709) } },
    { { -INT16_C( 22307), -INT16_C( 16167), -INT16_C(  4452), -INT16_C( 21369),  INT16_C(  3841), -INT16_C(  6514), -INT16_C(  9320),  INT16_C( 22074) },
      {  INT8_C(  45), -INT8_C(  83), -INT8_C(  84), -INT8_C(   4), -INT8_C( 109),  INT8_C(  97),  INT8_C(   8),  INT8_C(  25) },
      {  INT8_C(   3), -INT8_C(  54), -INT8_C(  45),  INT8_C(  66),  INT8_C(  77), -INT8_C(  78), -INT8_C(  96),  INT8_C(  42) },
      { -INT16_C( 22172), -INT16_C( 11685), -INT16_C(   672), -INT16_C( 21633), -INT16_C(  4552), -INT16_C( 14080), -INT16_C( 10088),  INT16_C( 23124) } },
    { {  INT16_C( 31066), -INT16_C(  2326),  INT16_C( 29287),  INT16_C( 26786),  INT16_C( 12417),  INT16_C(  6479), -INT16_C( 30452),  INT16_C( 14703) },
      {  INT8_C(  55),  INT8_C(  28),  INT8_C(  53), -INT8_C(  54),  INT8_C( 125),  INT8_C(  62), -INT8_C(  29),      INT8_MIN },
      {  INT8_C(   8), -INT8_C(  74), -INT8_C(  62),  INT8_C(  85),  INT8_C( 104),  INT8_C(  98),      INT8_MIN, -INT8_C(  61) },
      {  INT16_C( 31506), -INT16_C(  4398),  INT16_C( 26001),  INT16_C( 22196),  INT16_C( 25417),  INT16_C( 12555), -INT16_C( 26740),  INT16_C( 22511) } },
    { {  INT16_C( 27355),  INT16_C( 17337),  INT16_C( 23772),  INT16_C( 24235), -INT16_C(  1396), -INT16_C( 26505), -INT16_C(  6268), -INT16_C( 17455) },
      {  INT8_C(   3),  INT8_C(   7), -INT8_C( 123),      INT8_MIN,  INT8_C(  69),  INT8_C( 104),  INT8_C(   1),  INT8_C(  77) },
      {  INT8_C(  31), -INT8_C(  61), -INT8_C(  94), -INT8_C( 121),  INT8_C(  38),  INT8_C(  34),  INT8_C(  74),  INT8_C(   1) },
      {  INT16_C( 27448),  INT16_C( 16910), -INT16_C( 30202), -INT16_C( 25813),  INT16_C(  1226), -INT16_C( 22969), -INT16_C(  6194), -INT16_C( 17378) } },
    { {  INT16_C(  1165),  INT16_C( 26948), -INT16_C(  4000), -INT16_C(  4921),  INT16_C( 16362),  INT16_C( 28293),  INT16_C( 22054),  INT16_C( 10537) },
      {  INT8_C(  93), -INT8_C(  82), -INT8_C(  87), -INT8_C(  94),  INT8_C(  23), -INT8_C(  86), -INT8_C(  17),  INT8_C(  54) },
      {  INT8_C( 110), -INT8_C( 110), -INT8_C(  67), -INT8_C( 108), -INT8_C(  76),  INT8_C(   8), -INT8_C( 107),  INT8_C(  65) },
      {  INT16_C( 11395), -INT16_C( 29568),  INT16_C(  1829),  INT16_C(  5231),  INT16_C( 14614),  INT16_C( 27605),  INT16_C( 23873),  INT16_C( 14047) } },
    { { -INT16_C(  9716),  INT16_C( 27819),  INT16_C( 29386), -INT16_C( 19368), -INT16_C(  8783), -INT16_C( 10461),  INT16_C( 19508), -INT16_C( 28416) },
      { -INT8_C(   5), -INT8_C(  86),  INT8_C(  52),  INT8_C(  18),  INT8_C(  84),  INT8_C(  35),  INT8_C(  72), -INT8_C(  62) },
      { -INT8_C(  75),  INT8_C(   5),  INT8_C(  86),  INT8_C( 106),  INT8_C(  13), -INT8_C(  20), -INT8_C(  85),  INT8_C(  25) },
      { -INT16_C(  9341),  INT16_C( 27389), -INT16_C( 31678), -INT16_C( 17460), -INT16_C(  7691), -INT16_C( 11161),  INT16_C( 13388), -INT16_C( 29966) } },
    { {  INT16_C( 22214), -INT16_C( 28539), -INT16_C(  8503),  INT16_C( 31300),  INT16_C( 26555), -INT16_C(  4270),  INT16_C( 21172), -INT16_C( 20607) },
      { -INT8_C(   4), -INT8_C(  75), -INT8_C(  63),  INT8_C(  81), -INT8_C(  40),  INT8_C(   9),  INT8_C(  19), -INT8_C( 114) },
      {  INT8_C(  14),  INT8_C( 106), -INT8_C(   8),  INT8_C(  28),  INT8_C(  86), -INT8_C(  93),  INT8_C(  53),  INT8_C(  28) },
      {  INT16_C( 22158),  INT16_C( 29047), -INT16_C(  7999), -INT16_C( 31968),  INT16_C( 23115), -INT16_C(  5107),  INT16_C( 22179), -INT16_C( 23799) } },
    { { -INT16_C( 17414), -INT16_C( 15444), -INT16_C(  3943),  INT16_C( 21565), -INT16_C( 28840),  INT16_C(  3140), -INT16_C( 14878), -INT16_C(  8517) },
      {  INT8_C( 122),  INT8_C( 124),  INT8_C(  47),  INT8_C(  82), -INT8_C( 123),  INT8_C(  67), -INT8_C(  32), -INT8_C( 109) },
      { -INT8_C(  83), -INT8_C(  40), -INT8_C(  81),  INT8_C(   3),  INT8_C( 124), -INT8_C(  27),  INT8_C(  31),  INT8_C( 118) },
      { -INT16_C( 27540), -INT16_C( 20404), -INT16_C(  7750),  INT16_C( 21811),  INT16_C( 21444),  INT16_C(  1331), -INT16_C( 15870), -INT16_C( 21379) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t c = simde_vld1_s8(test_vec[i].c);
    simde_int16x8_t r = simde_vmlal_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t c = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t r = simde_vmlal_s8(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t c[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1576146538), -INT32_C(   379749091), -INT32_C(  1025404855), -INT32_C(  1031842427) },
      {  INT16_C(  1573), -INT16_C(  2909), -INT16_C( 20161),  INT16_C( 24305) },
      { -INT16_C(  7737),  INT16_C( 12514), -INT16_C( 21357),  INT16_C( 10595) },
      { -INT32_C(  1588316839), -INT32_C(   416152317), -INT32_C(   594826378), -INT32_C(   774330952) } },
    { { -INT32_C(  1295290219),  INT32_C(   932981230),  INT32_C(  1056603577), -INT32_C(   134121005) },
      { -INT16_C( 23425), -INT16_C( 16404), -INT16_C(  8619),  INT16_C(  7197) },
      { -INT16_C(    65),  INT16_C( 21069), -INT16_C( 20308),  INT16_C( 16763) },
      { -INT32_C(  1293767594),  INT32_C(   587365354),  INT32_C(  1231638229), -INT32_C(    13477694) } },
    { {  INT32_C(   250890016),  INT32_C(   692490352), -INT32_C(   530038771),  INT32_C(   970549689) },
      { -INT16_C( 15091),  INT16_C( 25336),  INT16_C(  5539),  INT16_C( 25214) },
      { -INT16_C( 13547), -INT16_C( 15948),  INT16_C( 12411), -INT16_C( 25598) },
      {  INT32_C(   455327793),  INT32_C(   288431824), -INT32_C(   461294242),  INT32_C(   325121717) } },
    { { -INT32_C(   408226185), -INT32_C(  1810829178), -INT32_C(   361465808), -INT32_C(   299676191) },
      {  INT16_C(  6931), -INT16_C( 18864), -INT16_C( 12496),  INT16_C( 17689) },
      { -INT16_C( 12902),  INT16_C(  5638),  INT16_C(  2557),  INT16_C( 29874) },
      { -INT32_C(   497649947), -INT32_C(  1917184410), -INT32_C(   393418080),  INT32_C(   228764995) } },
    { { -INT32_C(  2040832769),  INT32_C(  2098883661), -INT32_C(   966291740), -INT32_C(   273380644) },
      {  INT16_C(  1445), -INT16_C( 10587), -INT16_C( 16684),  INT16_C( 28187) },
      {  INT16_C(  8844), -INT16_C( 30332),  INT16_C( 13867),  INT16_C( 11006) },
      { -INT32_C(  2028053189), -INT32_C(  1874958751), -INT32_C(  1197648768),  INT32_C(    36845478) } },
    { { -INT32_C(   525313645), -INT32_C(  1436693819),  INT32_C(   896583001), -INT32_C(   182180785) },
      { -INT16_C( 14039), -INT16_C(   565), -INT16_C(  6520),  INT16_C(  5228) },
      { -INT16_C(  4088),  INT16_C( 13213), -INT16_C( 25817), -INT16_C( 17826) },
      { -INT32_C(   467922213), -INT32_C(  1444159164),  INT32_C(  1064909841), -INT32_C(   275375113) } },
    { { -INT32_C(  1164308747),  INT32_C(   845477849),  INT32_C(   208131260),  INT32_C(   570526713) },
      { -INT16_C( 13228), -INT16_C(  9184), -INT16_C( 29518), -INT16_C( 17424) },
      { -INT16_C( 29060), -INT16_C( 23570),  INT16_C( 19497),  INT16_C(  7773) },
      { -INT32_C(   779903067),  INT32_C(  1061944729), -INT32_C(   367381186),  INT32_C(   435089961) } },
    { {  INT32_C(   886699867), -INT32_C(  1419362833),  INT32_C(   196594962), -INT32_C(  1406289832) },
      {  INT16_C( 19844),  INT16_C( 14217),  INT16_C( 31193),  INT16_C( 22258) },
      { -INT16_C(  8185),  INT16_C( 12793),  INT16_C( 22317), -INT16_C( 30641) },
      {  INT32_C(   724276727), -INT32_C(  1237484752),  INT32_C(   892729143), -INT32_C(  2088297210) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int32x4_t r = simde_vmlal_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t c = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t r = simde_vmlal_s16(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t c[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 2979872316173994295), -INT64_C( 1240883300939221293) },
      {  INT32_C(  1264523082), -INT32_C(  1345297013) },
      { -INT32_C(   300170767),  INT32_C(   828293992) },
      { -INT64_C( 3359445179587138189), -INT64_C( 2355184734262667189) } },
    { { -INT64_C(  344116179695056007), -INT64_C( 3436780301193115862) },
      { -INT32_C(  1138971087),  INT32_C(    74181651) },
      {  INT32_C(   384993198), -INT32_C(  1018736566) },
      { -INT64_C(  782612300908722233), -INT64_C( 3512351861593066328) } },
    { { -INT64_C( 5386480482346723813), -INT64_C( 2396648732816469401) },
      {  INT32_C(   630905106),  INT32_C(  1948845766) },
      { -INT32_C(   678814835), -INT32_C(  2019896980) },
      { -INT64_C( 5814748227776771323), -INT64_C( 6333116410045656081) } },
    { { -INT64_C( 8708260595498237721), -INT64_C( 5609177671864664931) },
      { -INT32_C(   774389237),  INT32_C(  1430585544) },
      { -INT32_C(  2027106533), -INT32_C(  2029009248) },
      { -INT64_C( 7138491114090652400), -INT64_C( 8511848970695775843) } },
    { { -INT64_C( 8993934859609449849), -INT64_C( 2184819944803425445) },
      { -INT32_C(  2135784265), -INT32_C(  1596589948) },
      {  INT32_C(  1747387079),  INT32_C(  1341077192) },
      {  INT64_C( 5720767385907589832), -INT64_C( 4325970309042691461) } },
    { {  INT64_C( 7167802101881890833), -INT64_C(  900706475257674039) },
      {  INT32_C(   359871121), -INT32_C(   223000534) },
      {  INT32_C(   324721994),  INT32_C(   610421011) },
      {  INT64_C( 7284660169876026107), -INT64_C( 1036830686675493913) } },
    { {  INT64_C( 5304559210268940594), -INT64_C( 7347226928829891365) },
      { -INT32_C(   978355046),  INT32_C(   263677381) },
      {  INT32_C(  1428296002), -INT32_C(  1938127526) },
      {  INT64_C( 3907178609530614502), -INT64_C( 7858267318929580771) } },
    { {  INT64_C(  335346826108900830), -INT64_C( 7997507868240933024) },
      {  INT32_C(  1716958113),  INT32_C(  1517620504) },
      {  INT32_C(  2041550878), -INT32_C(    83547875) },
      {  INT64_C( 3840604169193274044), -INT64_C( 8124301836406562024) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int64x2_t r = simde_vmlal_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t c = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t r = simde_vmlal_s32(a, b, c);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t b[8];
    uint8_t c[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(47449), UINT16_C(30639), UINT16_C(18307), UINT16_C(14469), UINT16_C(51034), UINT16_C(24048), UINT16_C(31662), UINT16_C(48756) },
      { UINT8_C(161), UINT8_C(211), UINT8_C(242), UINT8_C(246), UINT8_C(142), UINT8_C( 12), UINT8_C(  6), UINT8_C( 91) },
      { UINT8_C( 89), UINT8_C(125), UINT8_C(196), UINT8_C(231), UINT8_C(202), UINT8_C(241), UINT8_C(182), UINT8_C( 36) },
      { UINT16_C(61778), UINT16_C(57014), UINT16_C(  203), UINT16_C( 5759), UINT16_C(14182), UINT16_C(26940), UINT16_C(32754), UINT16_C(52032) } },
    { { UINT16_C(26282), UINT16_C(11931), UINT16_C( 8365), UINT16_C( 2150), UINT16_C(22248), UINT16_C(38501), UINT16_C(55761), UINT16_C(29269) },
      { UINT8_C(173), UINT8_C( 71), UINT8_C(105), UINT8_C( 59), UINT8_C( 83), UINT8_C(111), UINT8_C(151), UINT8_C(172) },
      { UINT8_C(236), UINT8_C( 91), UINT8_C(148), UINT8_C(183), UINT8_C( 76), UINT8_C( 74), UINT8_C(219), UINT8_C(246) },
      { UINT16_C( 1574), UINT16_C(18392), UINT16_C(23905), UINT16_C(12947), UINT16_C(28556), UINT16_C(46715), UINT16_C(23294), UINT16_C( 6045) } },
    { { UINT16_C(30384), UINT16_C(24100), UINT16_C(35478), UINT16_C(32358), UINT16_C(52192), UINT16_C(45589), UINT16_C(27300), UINT16_C(20772) },
      { UINT8_C(177), UINT8_C(141), UINT8_C(141), UINT8_C(  4), UINT8_C(253), UINT8_C( 36), UINT8_C(177), UINT8_C(233) },
      { UINT8_C(127), UINT8_C( 69), UINT8_C(160), UINT8_C(203), UINT8_C(143), UINT8_C(123), UINT8_C(193), UINT8_C( 64) },
      { UINT16_C(52863), UINT16_C(33829), UINT16_C(58038), UINT16_C(33170), UINT16_C(22835), UINT16_C(50017), UINT16_C(61461), UINT16_C(35684) } },
    { { UINT16_C(59121), UINT16_C(34974), UINT16_C( 1136), UINT16_C(20742), UINT16_C( 7119), UINT16_C(29443), UINT16_C(10117), UINT16_C(14021) },
      { UINT8_C(181), UINT8_C( 82), UINT8_C( 59), UINT8_C(178), UINT8_C(118), UINT8_C(236), UINT8_C(155), UINT8_C(245) },
      { UINT8_C( 49), UINT8_C( 60), UINT8_C(192), UINT8_C(192), UINT8_C(183), UINT8_C(129), UINT8_C(  0), UINT8_C(169) },
      { UINT16_C( 2454), UINT16_C(39894), UINT16_C(12464), UINT16_C(54918), UINT16_C(28713), UINT16_C(59887), UINT16_C(10117), UINT16_C(55426) } },
    { { UINT16_C(40551), UINT16_C(55345), UINT16_C(14242), UINT16_C(28969), UINT16_C(11347), UINT16_C(55525), UINT16_C(43603), UINT16_C( 2063) },
      { UINT8_C(252), UINT8_C( 74), UINT8_C(186), UINT8_C(114), UINT8_C( 54), UINT8_C( 86), UINT8_C(103), UINT8_C(103) },
      { UINT8_C(146), UINT8_C( 39), UINT8_C( 39), UINT8_C( 73), UINT8_C(168), UINT8_C( 40), UINT8_C(242), UINT8_C( 16) },
      { UINT16_C(11807), UINT16_C(58231), UINT16_C(21496), UINT16_C(37291), UINT16_C(20419), UINT16_C(58965), UINT16_C( 2993), UINT16_C( 3711) } },
    { { UINT16_C( 9158), UINT16_C(27112), UINT16_C( 4443), UINT16_C(44762), UINT16_C(48957), UINT16_C(36998), UINT16_C(38249), UINT16_C(26009) },
      { UINT8_C(223), UINT8_C( 83), UINT8_C(215), UINT8_C( 21), UINT8_C(169), UINT8_C( 62), UINT8_C(124), UINT8_C( 59) },
      { UINT8_C(101), UINT8_C(164), UINT8_C(133), UINT8_C( 14), UINT8_C(204), UINT8_C(119), UINT8_C( 30), UINT8_C(146) },
      { UINT16_C(31681), UINT16_C(40724), UINT16_C(33038), UINT16_C(45056), UINT16_C(17897), UINT16_C(44376), UINT16_C(41969), UINT16_C(34623) } },
    { { UINT16_C( 1691), UINT16_C(63227), UINT16_C(54807), UINT16_C(21668), UINT16_C(10901), UINT16_C(65508), UINT16_C(32192), UINT16_C(40804) },
      { UINT8_C(209), UINT8_C( 60), UINT8_C(181), UINT8_C(122), UINT8_C(122), UINT8_C( 49), UINT8_C(182), UINT8_C(224) },
      { UINT8_C(213), UINT8_C( 59), UINT8_C(238), UINT8_C(161), UINT8_C(178), UINT8_C( 12), UINT8_C( 52), UINT8_C( 77) },
      { UINT16_C(46208), UINT16_C( 1231), UINT16_C(32349), UINT16_C(41310), UINT16_C(32617), UINT16_C(  560), UINT16_C(41656), UINT16_C(58052) } },
    { { UINT16_C(12050), UINT16_C(10563), UINT16_C(59141), UINT16_C(39805), UINT16_C(24850), UINT16_C(53914), UINT16_C(65247), UINT16_C(45169) },
      { UINT8_C( 58), UINT8_C( 38), UINT8_C( 42), UINT8_C(181), UINT8_C( 88), UINT8_C(224), UINT8_C(149), UINT8_C( 45) },
      { UINT8_C( 27), UINT8_C(131), UINT8_C(207), UINT8_C(206), UINT8_C(143), UINT8_C(  3), UINT8_C( 27), UINT8_C(161) },
      { UINT16_C(13616), UINT16_C(15541), UINT16_C( 2299), UINT16_C(11555), UINT16_C(37434), UINT16_C(54586), UINT16_C( 3734), UINT16_C(52414) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t c = simde_vld1_u8(test_vec[i].c);
    simde_uint16x8_t r = simde_vmlal_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t c = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t r = simde_vmlal_u8(a, b, c);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[4];
    uint16_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3154437210), UINT32_C(3449386933), UINT32_C( 981946950), UINT32_C(3734704900) },
      { UINT16_C(23951), UINT16_C(53783), UINT16_C( 4408), UINT16_C(46605) },
      { UINT16_C(  876), UINT16_C(48085), UINT16_C(47956), UINT16_C(44730) },
      { UINT32_C(3175418286), UINT32_C(1740575192), UINT32_C(1193336998), UINT32_C(1524379254) } },
    { { UINT32_C(1416347295), UINT32_C(2082538549), UINT32_C(1521920086), UINT32_C(1245270459) },
      { UINT16_C(20654), UINT16_C(59164), UINT16_C(10850), UINT16_C(52893) },
      { UINT16_C(29229), UINT16_C(33161), UINT16_C(17197), UINT16_C(52527) },
      { UINT32_C(2020043061), UINT32_C(4044475953), UINT32_C(1708507536), UINT32_C(4023581070) } },
    { { UINT32_C( 924948993), UINT32_C(4122166174), UINT32_C(2806999531), UINT32_C(1777436858) },
      { UINT16_C( 3801), UINT16_C(15184), UINT16_C(60728), UINT16_C(25865) },
      { UINT16_C(37727), UINT16_C(36326), UINT16_C( 5590), UINT16_C(55386) },
      { UINT32_C(1068349320), UINT32_C( 378772862), UINT32_C(3146469051), UINT32_C(3209995748) } },
    { { UINT32_C(1309637552), UINT32_C(2856567486), UINT32_C(3847328555), UINT32_C(4098769435) },
      { UINT16_C(40528), UINT16_C(34863), UINT16_C(14731), UINT16_C(60397) },
      { UINT16_C(54220), UINT16_C(41592), UINT16_C(53993), UINT16_C(39290) },
      { UINT32_C(3507065712), UINT32_C(  11622086), UINT32_C( 347732142), UINT32_C(2176800269) } },
    { { UINT32_C( 216500557), UINT32_C(1991650123), UINT32_C(3646687166), UINT32_C(2597235273) },
      { UINT16_C(64841), UINT16_C(54306), UINT16_C( 4150), UINT16_C(  703) },
      { UINT16_C(14307), UINT16_C(52389), UINT16_C( 7945), UINT16_C(22373) },
      { UINT32_C(1144180744), UINT32_C( 541719861), UINT32_C(3679658916), UINT32_C(2612963492) } },
    { { UINT32_C(4100148649), UINT32_C( 912988536), UINT32_C(1762641696), UINT32_C(3120815473) },
      { UINT16_C( 9947), UINT16_C( 4495), UINT16_C(20022), UINT16_C( 6420) },
      { UINT16_C(47494), UINT16_C(36838), UINT16_C(19416), UINT16_C(33254) },
      { UINT32_C( 277604171), UINT32_C(1078575346), UINT32_C(2151388848), UINT32_C(3334306153) } },
    { { UINT32_C( 276187544), UINT32_C(2185683298), UINT32_C( 434919080), UINT32_C( 248835891) },
      { UINT16_C(25365), UINT16_C(19232), UINT16_C(13489), UINT16_C(14181) },
      { UINT16_C(19437), UINT16_C(50631), UINT16_C(44438), UINT16_C(12103) },
      { UINT32_C( 769207049), UINT32_C(3159418690), UINT32_C(1034343262), UINT32_C( 420468534) } },
    { { UINT32_C(1497349623), UINT32_C(1188857502), UINT32_C( 257935580), UINT32_C(3441308599) },
      { UINT16_C(16022), UINT16_C(18456), UINT16_C(32114), UINT16_C(24447) },
      { UINT16_C(18120), UINT16_C(24356), UINT16_C(27636), UINT16_C(60302) },
      { UINT32_C(1787668263), UINT32_C(1638371838), UINT32_C(1145438084), UINT32_C( 620544297) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t c = simde_vld1_u16(test_vec[i].c);
    simde_uint32x4_t r = simde_vmlal_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t c = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t r = simde_vmlal_u16(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[2];
    uint32_t c[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(10190224453633740445), UINT64_C( 8831462168739048581) },
      { UINT32_C(3579245118), UINT32_C(  26948603) },
      { UINT32_C( 186872846), UINT32_C(2037143771) },
      { UINT64_C(10859088175366006273), UINT64_C( 8886360347477650494) } },
    { { UINT64_C( 4294859221972665063), UINT64_C( 9068824954654529363) },
      { UINT32_C(3713151458), UINT32_C(1927212388) },
      { UINT32_C(1031668066), UINT32_C(1085729369) },
      { UINT64_C( 8125599005412605291), UINT64_C(11161256044606752535) } },
    { { UINT64_C( 7970781020315038636), UINT64_C(15005054901360262783) },
      { UINT32_C(1068338906), UINT32_C(3736177532) },
      { UINT32_C(3843764108), UINT32_C(3324432921) },
      { UINT64_C(12077223762377824484), UINT64_C( 8978982413732042139) } },
    { { UINT64_C(15712994622238651269), UINT64_C( 7098188166977871555) },
      { UINT32_C(3751882339), UINT32_C(1170035385) },
      { UINT32_C(2603276418), UINT32_C( 811684010) },
      { UINT64_C( 7033437364758481355), UINT64_C( 8047887180116565405) } },
    { { UINT64_C( 1295311894479931844), UINT64_C(14530656829270299069) },
      { UINT32_C( 715671665), UINT32_C( 477062554) },
      { UINT32_C(3904412221), UINT32_C(2920815082) },
      { UINT64_C( 4089589089529349809), UINT64_C(15924068332050938497) } },
    { { UINT64_C( 9584722998327109795), UINT64_C( 8829149881152750936) },
      { UINT32_C(1420111801), UINT32_C(3513783444) },
      { UINT32_C(2579048622), UINT32_C(3846689090) },
      { UINT64_C(13247260381782098017), UINT64_C( 3898838246100625280) } },
    { { UINT64_C( 3677147157587432890), UINT64_C(18240273672796492447) },
      { UINT32_C( 995215271), UINT32_C(2316157404) },
      { UINT32_C( 740542186), UINT32_C(1376873368) },
      { UINT64_C( 4414146049914355296), UINT64_C( 2982585044750557503) } },
    { { UINT64_C( 6958021572826556288), UINT64_C(11596253343504695469) },
      { UINT32_C(3470540786), UINT32_C(3931695360) },
      { UINT32_C(1192656047), UINT32_C(1738090471) },
      { UINT64_C(11097183027609589230), UINT64_C(18429895583595610029) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t c = simde_vld1_u32(test_vec[i].c);
    simde_uint64x2_t r = simde_vmlal_u32(a, b, c);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t c = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t r = simde_vmlal_u32(a, b, c);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
