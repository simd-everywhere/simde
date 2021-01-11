#define SIMDE_TEST_ARM_NEON_INSN mlsl

#include "test-neon.h"
#include "../../../simde/arm/neon/mlsl.h"

static int
test_simde_vmlsl_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t b[8];
    int8_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 31745), -INT16_C( 21638), -INT16_C( 25091), -INT16_C( 30065), -INT16_C( 22021), -INT16_C(  2377), -INT16_C( 25004), -INT16_C( 16531) },
      {  INT8_C(  71), -INT8_C( 102), -INT8_C( 119), -INT8_C( 102), -INT8_C( 113), -INT8_C(  72),  INT8_C(  35), -INT8_C(   6) },
      {  INT8_C(  93),  INT8_C(  75), -INT8_C(   4), -INT8_C(  46),  INT8_C(  41),      INT8_MAX, -INT8_C( 107),  INT8_C(  43) },
      {  INT16_C( 25142), -INT16_C( 13988), -INT16_C( 25567),  INT16_C( 30779), -INT16_C( 17388),  INT16_C(  6767), -INT16_C( 21259), -INT16_C( 16273) } },
    { {  INT16_C(  4091), -INT16_C(  1578),  INT16_C( 26028), -INT16_C( 22653),  INT16_C( 14863),  INT16_C( 25502),  INT16_C(  3032),  INT16_C(  8226) },
      { -INT8_C(  91), -INT8_C(  85), -INT8_C(  70),  INT8_C(  52),  INT8_C( 100), -INT8_C(  35),  INT8_C(  46), -INT8_C(  63) },
      {  INT8_C(  41),  INT8_C(  42), -INT8_C( 109),  INT8_C(  82), -INT8_C(  87),  INT8_C(  40),  INT8_C( 125), -INT8_C(  91) },
      {  INT16_C(  7822),  INT16_C(  1992),  INT16_C( 18398), -INT16_C( 26917),  INT16_C( 23563),  INT16_C( 26902), -INT16_C(  2718),  INT16_C(  2493) } },
    { {  INT16_C( 21303), -INT16_C(  7010),  INT16_C(  8633), -INT16_C( 14197),  INT16_C( 10588),  INT16_C( 13355),  INT16_C( 19765), -INT16_C(  9644) },
      { -INT8_C(   7),  INT8_C(  15),  INT8_C(  15),  INT8_C(  93), -INT8_C(  20),  INT8_C(  61),  INT8_C(  30),  INT8_C(  21) },
      {  INT8_C( 104), -INT8_C(  79),  INT8_C( 104),  INT8_C(  17), -INT8_C(  39), -INT8_C(  27), -INT8_C(  74),  INT8_C(  16) },
      {  INT16_C( 22031), -INT16_C(  5825),  INT16_C(  7073), -INT16_C( 15778),  INT16_C(  9808),  INT16_C( 15002),  INT16_C( 21985), -INT16_C(  9980) } },
    { {  INT16_C( 21561), -INT16_C(  3340), -INT16_C( 32650), -INT16_C( 11590), -INT16_C(  6743), -INT16_C(  8698),  INT16_C( 23346),  INT16_C( 11193) },
      {  INT8_C( 106), -INT8_C(  56), -INT8_C( 120),  INT8_C(  86),  INT8_C(   5), -INT8_C(  90),  INT8_C( 108),  INT8_C( 109) },
      {  INT8_C(  87), -INT8_C(  44),      INT8_MAX,  INT8_C(  48), -INT8_C(  71),  INT8_C(  53),  INT8_C(  65), -INT8_C(  14) },
      {  INT16_C( 12339), -INT16_C(  5804), -INT16_C( 17410), -INT16_C( 15718), -INT16_C(  6388), -INT16_C(  3928),  INT16_C( 16326),  INT16_C( 12719) } },
    { {  INT16_C( 13706),  INT16_C(   228), -INT16_C( 24907),  INT16_C( 24530), -INT16_C( 10109), -INT16_C( 18883), -INT16_C(  2509), -INT16_C( 25119) },
      { -INT8_C(  66),  INT8_C( 106), -INT8_C(  12), -INT8_C(  60),  INT8_C(  16),  INT8_C(  96),  INT8_C(  49),  INT8_C( 104) },
      {  INT8_C(  52), -INT8_C(  80), -INT8_C( 104), -INT8_C(  19), -INT8_C(  26), -INT8_C(  39), -INT8_C(  32),  INT8_C( 112) },
      {  INT16_C( 17138),  INT16_C(  8708), -INT16_C( 26155),  INT16_C( 23390), -INT16_C(  9693), -INT16_C( 15139), -INT16_C(   941),  INT16_C( 28769) } },
    { { -INT16_C( 15345), -INT16_C( 15248),  INT16_C( 16995), -INT16_C(  6621),  INT16_C( 24858),  INT16_C( 20124),  INT16_C( 32343),  INT16_C(  5867) },
      { -INT8_C(  24), -INT8_C(  33), -INT8_C(  38), -INT8_C(   8),  INT8_C(  63),  INT8_C(  11),  INT8_C(  96),  INT8_C( 115) },
      { -INT8_C(  68), -INT8_C(   7),  INT8_C(  97), -INT8_C(  94), -INT8_C(  46),  INT8_C(  65),  INT8_C(  18), -INT8_C(  31) },
      { -INT16_C( 16977), -INT16_C( 15479),  INT16_C( 20681), -INT16_C(  7373),  INT16_C( 27756),  INT16_C( 19409),  INT16_C( 30615),  INT16_C(  9432) } },
    { { -INT16_C( 32251),  INT16_C( 26790), -INT16_C( 13884), -INT16_C(  8625), -INT16_C(  5334), -INT16_C( 32212),  INT16_C(  6249),  INT16_C( 20888) },
      { -INT8_C(   9),  INT8_C( 114),  INT8_C(  74),  INT8_C(  55),  INT8_C( 125), -INT8_C(  86), -INT8_C(  86),  INT8_C(  57) },
      { -INT8_C(  93),  INT8_C(  11), -INT8_C(  37),  INT8_C( 118),  INT8_C(  76), -INT8_C(  19),  INT8_C(  87),  INT8_C(  82) },
      {  INT16_C( 32448),  INT16_C( 25536), -INT16_C( 11146), -INT16_C( 15115), -INT16_C( 14834),  INT16_C( 31690),  INT16_C( 13731),  INT16_C( 16214) } },
    { { -INT16_C(   657),  INT16_C( 13242),  INT16_C(  2503), -INT16_C(  3822),  INT16_C( 16117),  INT16_C( 24179),  INT16_C(  2902),  INT16_C( 20144) },
      {  INT8_C( 125), -INT8_C(   6), -INT8_C( 123), -INT8_C(   5), -INT8_C(  92),  INT8_C(  47),  INT8_C(  52),  INT8_C(  72) },
      {  INT8_C(  59),  INT8_C(  16), -INT8_C(  66), -INT8_C( 121), -INT8_C(   3),  INT8_C(  21), -INT8_C(  39),  INT8_C( 109) },
      { -INT16_C(  8032),  INT16_C( 13338), -INT16_C(  5615), -INT16_C(  4427),  INT16_C( 15841),  INT16_C( 23192),  INT16_C(  4930),  INT16_C( 12296) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t c = simde_vld1_s8(test_vec[i].c);
    simde_int16x8_t r = simde_vmlsl_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t c = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t r = simde_vmlsl_s8(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[8];
    int16_t b[8];
    int16_t c[8];
    int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(   389456902), -INT32_C(  1594102070),  INT32_C(   334870077),  INT32_C(   493042589) },
      { -INT16_C( 32086), -INT16_C(  2707),  INT16_C(  7962),  INT16_C( 29609) },
      { -INT16_C( 18041),  INT16_C(  5864), -INT16_C( 29710), -INT16_C(  4982) },
      { -INT32_C(   968320428), -INT32_C(  1578228222),  INT32_C(   571421097),  INT32_C(   640554627) } },
    { { -INT32_C(  1311419162),  INT32_C(  2136068162),  INT32_C(   596854662),  INT32_C(   759232130) },
      { -INT16_C( 20872), -INT16_C( 27870), -INT16_C( 13363),  INT16_C( 21766) },
      { -INT16_C(  4476),  INT16_C( 30315), -INT16_C(  2695),  INT16_C( 24675) },
      { -INT32_C(  1404842234), -INT32_C(  1314020084),  INT32_C(   560841377),  INT32_C(   222156080) } },
    { { -INT32_C(  1945028535), -INT32_C(  1911856632),  INT32_C(   749837993),  INT32_C(   223998356) },
      {  INT16_C( 31647),  INT16_C( 28064), -INT16_C( 22970), -INT16_C( 13374) },
      {  INT16_C( 11668),  INT16_C(  3649), -INT16_C( 23518),  INT16_C( 27758) },
      {  INT32_C(  1980681565), -INT32_C(  2014262168),  INT32_C(   209629533),  INT32_C(   595233848) } },
    { { -INT32_C(   453476388), -INT32_C(  1955462175),  INT32_C(   917971874), -INT32_C(  1270673387) },
      { -INT16_C(  7285), -INT16_C( 11999), -INT16_C(  7287),  INT16_C(  7836) },
      { -INT16_C(  8688),  INT16_C( 13100), -INT16_C( 25982),  INT16_C( 24479) },
      { -INT32_C(   516768468), -INT32_C(  1798275275),  INT32_C(   728641040), -INT32_C(  1462490831) } },
    { { -INT32_C(    96233703),  INT32_C(  1015395994), -INT32_C(   294437671), -INT32_C(   677136820) },
      { -INT16_C( 15206),  INT16_C(  9129),  INT16_C( 17832), -INT16_C( 18367) },
      {  INT16_C( 27939), -INT16_C( 22805), -INT16_C( 30201),  INT16_C(  8197) },
      {  INT32_C(   328606731),  INT32_C(  1223582839),  INT32_C(   244106561), -INT32_C(   526582521) } },
    { { -INT32_C(  1139062751), -INT32_C(   654794498),  INT32_C(   700869597), -INT32_C(  1140758238) },
      { -INT16_C( 21970), -INT16_C( 10529),  INT16_C(  8687),  INT16_C(  5006) },
      {  INT16_C( 31374), -INT16_C( 26951), -INT16_C( 16892),  INT16_C(  9910) },
      { -INT32_C(   449775971), -INT32_C(   938561577),  INT32_C(   847610401), -INT32_C(  1190367698) } },
    { {  INT32_C(    98750726),  INT32_C(  1339939442),  INT32_C(  1752736582),  INT32_C(   992246029) },
      {  INT16_C(   803),  INT16_C(  4881), -INT16_C( 24796), -INT16_C( 19674) },
      { -INT16_C(  8423),  INT16_C(  7753), -INT16_C(    99), -INT16_C( 23740) },
      {  INT32_C(   105514395),  INT32_C(  1302097049),  INT32_C(  1750281778),  INT32_C(   525185269) } },
    { {  INT32_C(  1135093457),  INT32_C(  1184007424),  INT32_C(   917375529), -INT32_C(  1485712764) },
      { -INT16_C( 32042), -INT16_C(  1350), -INT16_C(  8159),  INT16_C( 15277) },
      { -INT16_C(  2369),  INT16_C( 23641), -INT16_C( 25098), -INT16_C( 14592) },
      {  INT32_C(  1059185959),  INT32_C(  1215922774),  INT32_C(   712600947), -INT32_C(  1262790780) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int32x4_t r = simde_vmlsl_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t c = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t r = simde_vmlsl_s16(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[8];
    int32_t b[8];
    int32_t c[8];
    int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 6271997155721521347),  INT64_C( 7048976240456087718) },
      { -INT32_C(  1587835776),  INT32_C(   752617837) },
      { -INT32_C(   175557121), -INT32_C(  1782806062) },
      {  INT64_C( 5993241278266160451),  INT64_C( 8390747882629015612) } },
    { {  INT64_C(  699856066260354609), -INT64_C( 4537652320033094885) },
      { -INT32_C(    10263662),  INT32_C(  1797996396) },
      {  INT32_C(  1197585525),  INT32_C(  1876761917) },
      {  INT64_C(  712147679305047159), -INT64_C( 7912063482949146017) } },
    { { -INT64_C( 5453993730357971228),  INT64_C( 1930745201687233480) },
      {  INT32_C(   823733957), -INT32_C(   476232338) },
      {  INT32_C(   925564665), -INT32_C(     5896421) },
      { -INT64_C( 6216412774317800633),  INT64_C( 1927937135328571182) } },
    { { -INT64_C( 4428280908314414019),  INT64_C( 1061608475383883288) },
      {  INT32_C(   876598726),  INT32_C(   320330778) },
      { -INT32_C(   162905638), -INT32_C(  2030702519) },
      { -INT64_C( 4285478033585396831),  INT64_C( 1712104993181713070) } },
    { { -INT64_C( 1648061477688624283),  INT64_C( 5342472591096081614) },
      {  INT32_C(   897475611),  INT32_C(   457741632) },
      {  INT32_C(   521245654), -INT32_C(   391772541) },
      { -INT64_C( 2115866739493368877),  INT64_C( 5521803193386208526) } },
    { { -INT64_C( 5045043223223401662), -INT64_C( 1719542942759155884) },
      { -INT32_C(  1742888872),  INT32_C(   196306229) },
      {  INT32_C(  2083243256),  INT32_C(   224711115) },
      { -INT64_C( 1414181734671954430), -INT64_C( 1763655134359191219) } },
    { {  INT64_C( 7455740054248401876), -INT64_C( 7829401044269447261) },
      {  INT32_C(   908883201), -INT32_C(   750657573) },
      {  INT32_C(  1867476132),  INT32_C(   293385277) },
      {  INT64_C( 5758422369605143344), -INT64_C( 7609169164282694540) } },
    { {  INT64_C( 6690458678473038943),  INT64_C( 8817807800455141520) },
      {  INT32_C(  1974504346),  INT32_C(   239727210) },
      { -INT32_C(  1669490594), -INT32_C(  1397884596) },
      { -INT64_C( 8459868961777391149),  INT64_C( 9152918774556198680) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int64x2_t r = simde_vmlsl_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t c = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t r = simde_vmlsl_s32(a, b, c);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t b[8];
    uint8_t c[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(32405), UINT16_C(19998), UINT16_C(63686), UINT16_C(22186), UINT16_C(30224), UINT16_C(35362), UINT16_C(33179), UINT16_C(13828) },
      { UINT8_C( 12), UINT8_C(181), UINT8_C(171), UINT8_C(118), UINT8_C(167), UINT8_C(244), UINT8_C(133), UINT8_C(  5) },
      { UINT8_C(141), UINT8_C(  2), UINT8_C(161), UINT8_C(217), UINT8_C(252), UINT8_C( 79), UINT8_C(133), UINT8_C(145) },
      { UINT16_C(30713), UINT16_C(19636), UINT16_C(36155), UINT16_C(62116), UINT16_C(53676), UINT16_C(16086), UINT16_C(15490), UINT16_C(13103) } },
    { { UINT16_C(42189), UINT16_C(37855), UINT16_C(35228), UINT16_C(44266), UINT16_C( 3072), UINT16_C(39734), UINT16_C(15245), UINT16_C(39377) },
      { UINT8_C(240), UINT8_C(125), UINT8_C( 15), UINT8_C(151), UINT8_C(113), UINT8_C(148), UINT8_C(156), UINT8_C(254) },
      { UINT8_C(151), UINT8_C( 62), UINT8_C(216), UINT8_C(147), UINT8_C(141), UINT8_C( 93), UINT8_C( 36), UINT8_C( 90) },
      { UINT16_C( 5949), UINT16_C(30105), UINT16_C(31988), UINT16_C(22069), UINT16_C(52675), UINT16_C(25970), UINT16_C( 9629), UINT16_C(16517) } },
    { { UINT16_C( 1025), UINT16_C(40429), UINT16_C(55181), UINT16_C(36170), UINT16_C(32995), UINT16_C(28713), UINT16_C(64187), UINT16_C(43785) },
      { UINT8_C(119), UINT8_C( 25), UINT8_C( 66), UINT8_C(233), UINT8_C(173), UINT8_C(223), UINT8_C(231), UINT8_C( 68) },
      { UINT8_C( 29), UINT8_C(191), UINT8_C(215), UINT8_C(170), UINT8_C( 29), UINT8_C(252), UINT8_C(  4), UINT8_C( 30) },
      { UINT16_C(63110), UINT16_C(35654), UINT16_C(40991), UINT16_C(62096), UINT16_C(27978), UINT16_C(38053), UINT16_C(63263), UINT16_C(41745) } },
    { { UINT16_C(61696), UINT16_C(36284), UINT16_C( 1737), UINT16_C(44059), UINT16_C(17542), UINT16_C(16925), UINT16_C( 9790), UINT16_C(46829) },
      { UINT8_C( 63), UINT8_C( 48), UINT8_C(159), UINT8_C(237), UINT8_C( 15), UINT8_C(134), UINT8_C( 49), UINT8_C( 44) },
      { UINT8_C( 70), UINT8_C(  9), UINT8_C(214), UINT8_C( 99), UINT8_C(  5), UINT8_C(218), UINT8_C(129), UINT8_C(  5) },
      { UINT16_C(57286), UINT16_C(35852), UINT16_C(33247), UINT16_C(20596), UINT16_C(17467), UINT16_C(53249), UINT16_C( 3469), UINT16_C(46609) } },
    { { UINT16_C(15819), UINT16_C(38034), UINT16_C(44355), UINT16_C(51777), UINT16_C(24305), UINT16_C(12300), UINT16_C(63876), UINT16_C(50406) },
      { UINT8_C( 41), UINT8_C(133), UINT8_C(177), UINT8_C( 56), UINT8_C( 11), UINT8_C(226), UINT8_C(100), UINT8_C( 81) },
      { UINT8_C(235), UINT8_C( 58), UINT8_C(180), UINT8_C(240), UINT8_C( 20), UINT8_C( 54), UINT8_C(245), UINT8_C(224) },
      { UINT16_C( 6184), UINT16_C(30320), UINT16_C(12495), UINT16_C(38337), UINT16_C(24085), UINT16_C(   96), UINT16_C(39376), UINT16_C(32262) } },
    { { UINT16_C(34931), UINT16_C(46964), UINT16_C(46389), UINT16_C(10113), UINT16_C(36115), UINT16_C(38999), UINT16_C(15750), UINT16_C(45148) },
      { UINT8_C(194), UINT8_C( 13), UINT8_C(232), UINT8_C(205), UINT8_C(239), UINT8_C( 77), UINT8_C( 31), UINT8_C(219) },
      { UINT8_C(135), UINT8_C(211), UINT8_C(203), UINT8_C(156), UINT8_C(  9), UINT8_C(193), UINT8_C(124), UINT8_C(125) },
      { UINT16_C( 8741), UINT16_C(44221), UINT16_C(64829), UINT16_C(43669), UINT16_C(33964), UINT16_C(24138), UINT16_C(11906), UINT16_C(17773) } },
    { { UINT16_C(61513), UINT16_C(32308), UINT16_C(46502), UINT16_C(47525), UINT16_C(64578), UINT16_C(51281), UINT16_C(44345), UINT16_C(64376) },
      { UINT8_C(186), UINT8_C( 97), UINT8_C(201), UINT8_C(170), UINT8_C(174), UINT8_C(232), UINT8_C(133), UINT8_C( 53) },
      { UINT8_C(187), UINT8_C( 80), UINT8_C(209), UINT8_C(197), UINT8_C( 17), UINT8_C( 77), UINT8_C( 66), UINT8_C( 90) },
      { UINT16_C(26731), UINT16_C(24548), UINT16_C( 4493), UINT16_C(14035), UINT16_C(61620), UINT16_C(33417), UINT16_C(35567), UINT16_C(59606) } },
    { { UINT16_C(30270), UINT16_C(58585), UINT16_C(32299), UINT16_C(28061), UINT16_C(61307), UINT16_C(46133), UINT16_C(44700), UINT16_C(22448) },
      { UINT8_C( 15), UINT8_C(121), UINT8_C(  1), UINT8_C(189), UINT8_C( 97), UINT8_C(134), UINT8_C(242), UINT8_C( 28) },
      { UINT8_C(214), UINT8_C(196), UINT8_C(225), UINT8_C(232), UINT8_C( 17), UINT8_C( 35), UINT8_C( 66), UINT8_C( 79) },
      { UINT16_C(27060), UINT16_C(34869), UINT16_C(32074), UINT16_C(49749), UINT16_C(59658), UINT16_C(41443), UINT16_C(28728), UINT16_C(20236) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t c = simde_vld1_u8(test_vec[i].c);
    simde_uint16x8_t r = simde_vmlsl_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t c = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t r = simde_vmlsl_u8(a, b, c);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[8];
    uint16_t b[8];
    uint16_t c[8];
    uint32_t r[8];
  } test_vec[] = {
    { { UINT32_C(  46872662), UINT32_C(2110696610), UINT32_C(1606486472), UINT32_C(3331166886) },
      { UINT16_C(23921), UINT16_C( 2489), UINT16_C( 1686), UINT16_C(49008) },
      { UINT16_C(23913), UINT16_C(36921), UINT16_C(32763), UINT16_C(20942) },
      { UINT32_C(3769817085), UINT32_C(2018800241), UINT32_C(1551248054), UINT32_C(2304841350) } },
    { { UINT32_C(1498716855), UINT32_C( 248980038), UINT32_C(3513620523), UINT32_C(2627271467) },
      { UINT16_C(20824), UINT16_C(61349), UINT16_C( 5720), UINT16_C(49582) },
      { UINT16_C(59251), UINT16_C(28241), UINT16_C( 8294), UINT16_C( 7871) },
      { UINT32_C( 264874031), UINT32_C(2811390225), UINT32_C(3466178843), UINT32_C(2237011545) } },
    { { UINT32_C(   7803834), UINT32_C(1611550261), UINT32_C( 305298407), UINT32_C(3484338806) },
      { UINT16_C(21531), UINT16_C(29630), UINT16_C(27754), UINT16_C(56629) },
      { UINT16_C(34387), UINT16_C(47691), UINT16_C( 2726), UINT16_C(24792) },
      { UINT32_C(3562384633), UINT32_C( 198465931), UINT32_C( 229641003), UINT32_C(2080392638) } },
    { { UINT32_C(1398820638), UINT32_C(2243194526), UINT32_C(1620567786), UINT32_C(3408872880) },
      { UINT16_C(60825), UINT16_C(  831), UINT16_C(29785), UINT16_C(44512) },
      { UINT16_C(11258), UINT16_C(41319), UINT16_C(16182), UINT16_C(21505) },
      { UINT32_C( 714052788), UINT32_C(2208858437), UINT32_C(1138586916), UINT32_C(2451642320) } },
    { { UINT32_C( 749167246), UINT32_C(3132185552), UINT32_C(4045097025), UINT32_C( 666716814) },
      { UINT16_C(64568), UINT16_C(37163), UINT16_C( 2928), UINT16_C(27198) },
      { UINT16_C(42295), UINT16_C(27915), UINT16_C( 3556), UINT16_C(29633) },
      { UINT32_C(2313230982), UINT32_C(2094780407), UINT32_C(4034685057), UINT32_C(4155725776) } },
    { { UINT32_C(1067411567), UINT32_C( 100291012), UINT32_C( 670504345), UINT32_C(2538583135) },
      { UINT16_C(31408), UINT16_C( 8233), UINT16_C(26501), UINT16_C(48266) },
      { UINT16_C(38413), UINT16_C(61737), UINT16_C(60067), UINT16_C( 4708) },
      { UINT32_C(4155903359), UINT32_C(3886977587), UINT32_C(3373636074), UINT32_C(2311346807) } },
    { { UINT32_C( 391185491), UINT32_C(3994831701), UINT32_C(3222672224), UINT32_C(2002216391) },
      { UINT16_C(32991), UINT16_C(25751), UINT16_C( 8936), UINT16_C(62753) },
      { UINT16_C(19128), UINT16_C(23526), UINT16_C(19253), UINT16_C(34925) },
      { UINT32_C(4055100939), UINT32_C(3389013675), UINT32_C(3050627416), UINT32_C(4105535162) } },
    { { UINT32_C(2761932367), UINT32_C(1788001034), UINT32_C(2519378127), UINT32_C(3960373773) },
      { UINT16_C(42242), UINT16_C(59985), UINT16_C(29383), UINT16_C(32735) },
      { UINT16_C(50876), UINT16_C(61914), UINT16_C(18193), UINT16_C(24697) },
      { UINT32_C( 612828375), UINT32_C(2369057040), UINT32_C(1984813208), UINT32_C(3151917478) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t c = simde_vld1_u16(test_vec[i].c);
    simde_uint32x4_t r = simde_vmlsl_u16(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t c = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t r = simde_vmlsl_u16(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[8];
    uint32_t b[8];
    uint32_t c[8];
    uint64_t r[8];
  } test_vec[] = {
    { { UINT64_C(11779893612886890502), UINT64_C( 2970483663335695679) },
      { UINT32_C(3021245165), UINT32_C(3090478076) },
      { UINT32_C(3400142521), UINT32_C(1546265430) },
      { UINT64_C( 1507229461004729537), UINT64_C(16638528325953534615) } },
    { { UINT64_C(  338868131041390140), UINT64_C( 2439975957550918795) },
      { UINT32_C( 265678867), UINT32_C(2647132643) },
      { UINT32_C(1852273176), UINT32_C(3519713941) },
      { UINT64_C(18293502365976770164), UINT64_C(11569570364017194348) } },
    { { UINT64_C(12144400720407377600), UINT64_C( 8635149137401797249) },
      { UINT32_C( 176597798), UINT32_C(3450293941) },
      { UINT32_C(1446710976), UINT32_C(1629947296) },
      { UINT64_C(11888914747703346752), UINT64_C( 3011351857863663713) } },
    { { UINT64_C( 2233627761285925179), UINT64_C(13196859246959090250) },
      { UINT32_C( 180464469), UINT32_C(3134679289) },
      { UINT32_C( 386929270), UINT32_C(1383610135) },
      { UINT64_C( 2163800776034817549), UINT64_C( 8859685212724096235) } },
    { { UINT64_C( 1800500657005354560), UINT64_C(14864951327980965891) },
      { UINT32_C(2413300629), UINT32_C(3930697587) },
      { UINT32_C(3623967169), UINT32_C(3509221776) },
      { UINT64_C(11501522482291856875), UINT64_C( 1071261760809911379) } },
    { { UINT64_C( 9277040838585603287), UINT64_C(  343221831556367483) },
      { UINT32_C(3717438569), UINT32_C( 231201867) },
      { UINT32_C(3336947765), UINT32_C( 412553281) },
      { UINT64_C(15318886587945806618), UINT64_C(  247838742752191856) } },
    { { UINT64_C( 7917748095574492900), UINT64_C(13579801287408677889) },
      { UINT32_C( 228133057), UINT32_C( 437936357) },
      { UINT32_C(1776353064), UINT32_C(4085348111) },
      { UINT64_C( 7512503240772856252), UINT64_C(11790678818600506262) } },
    { { UINT64_C(13698883255360831677), UINT64_C( 7293760618596630058) },
      { UINT32_C(2440221100), UINT32_C(1504480305) },
      { UINT32_C(2613218443), UINT32_C(3247326212) },
      { UINT64_C( 7322052471843084377), UINT64_C( 2408222288732375398) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t c = simde_vld1_u32(test_vec[i].c);
    simde_uint64x2_t r = simde_vmlsl_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t c = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t r = simde_vmlsl_u32(a, b, c);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
