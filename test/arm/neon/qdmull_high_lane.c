#define SIMDE_TEST_ARM_NEON_INSN qdmull_high_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmull_high_lane.h"

static int
test_simde_vqdmull_high_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int16_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
    { {  -INT16_C(    6760), -INT16_C(      95),  INT16_C(    9414),  INT16_C(    1581),
          INT16_C(    9531), -INT16_C(    5668), -INT16_C(    1231), -INT16_C(    8041) },
      {  -INT16_C(    2089), -INT16_C(    9207), -INT16_C(    8278), -INT16_C(    2672) },
          INT8_C(       3),
      {  -INT32_C(  50933664),  INT32_C(  30289792),  INT32_C(   6578464),  INT32_C(  42971104) } },
    { {   INT16_C(    3445),  INT16_C(    9881), -INT16_C(    2591), -INT16_C(    8857),
          INT16_C(    2650),  INT16_C(    5967), -INT16_C(    2644), -INT16_C(    4403) },
      {  -INT16_C(    8527), -INT16_C(    1857), -INT16_C(     788),  INT16_C(    8560) },
          INT8_C(       2),
      {  -INT32_C(   4176400), -INT32_C(   9403992),  INT32_C(   4166944),  INT32_C(   6939128) } },
    { {  -INT16_C(    5482),  INT16_C(    7922), -INT16_C(    1220), -INT16_C(    1648),
         -INT16_C(    5991),  INT16_C(    6334), -INT16_C(    3563),  INT16_C(    8545) },
      {  -INT16_C(    5750),  INT16_C(    6074),  INT16_C(    7152), -INT16_C(    6897) },
          INT8_C(       1),
      {  -INT32_C(  72778668),  INT32_C(  76945432), -INT32_C(  43283324),  INT32_C( 103804660) } },
    { {  -INT16_C(     838),  INT16_C(    5238), -INT16_C(    8736),  INT16_C(     296),
          INT16_C(    8407),  INT16_C(    8762), -INT16_C(    6003), -INT16_C(    4085) },
      {   INT16_C(    9212),  INT16_C(    8531),  INT16_C(    6599),  INT16_C(     888) },
          INT8_C(       2),
      {   INT32_C( 110955586),  INT32_C( 115640876), -INT32_C(  79227594), -INT32_C(  53913830) } },
    { {   INT16_C(    3680),  INT16_C(    8622),  INT16_C(    8753),  INT16_C(    5696),
          INT16_C(    5471), -INT16_C(    2264), -INT16_C(    5501), -INT16_C(    6087) },
      {   INT16_C(     290), -INT16_C(    5208), -INT16_C(    7387),  INT16_C(    6990) },
          INT8_C(       3),
      {   INT32_C(  76484580), -INT32_C(  31650720), -INT32_C(  76903980), -INT32_C(  85096260) } },
    { {  -INT16_C(    3611),  INT16_C(    1897), -INT16_C(    2126),  INT16_C(    6986),
          INT16_C(    6474),  INT16_C(    2698),  INT16_C(    7044), -INT16_C(    2562) },
      {  -INT16_C(    1326),  INT16_C(    2049),  INT16_C(    8320), -INT16_C(    3248) },
          INT8_C(       0),
      {  -INT32_C(  17169048), -INT32_C(   7155096), -INT32_C(  18680688),  INT32_C(   6794424) } },
    { {  -INT16_C(    6094), -INT16_C(    9976),  INT16_C(    8334), -INT16_C(    2735),
         -INT16_C(    7194),  INT16_C(    7077), -INT16_C(    9240), -INT16_C(    9787) },
      {   INT16_C(    9801),  INT16_C(    4409),  INT16_C(    4484),  INT16_C(    6660) },
          INT8_C(       2),
      {  -INT32_C(  64515792),  INT32_C(  63466536), -INT32_C(  82864320), -INT32_C(  87769816) } },
    { {  -INT16_C(    5859), -INT16_C(    3555), -INT16_C(    8501),  INT16_C(    5189),
         -INT16_C(    7467), -INT16_C(    4387), -INT16_C(    8681), -INT16_C(    6318) },
      {   INT16_C(    8507), -INT16_C(    3782), -INT16_C(    5846),  INT16_C(    8906) },
          INT8_C(       2),
      {   INT32_C(  87304164),  INT32_C(  51292804),  INT32_C( 101498252),  INT32_C(  73870056) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vqdmull_high_lane_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmull_high_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t v[2];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
    { {  -INT32_C(  990609),  INT32_C(  371504),  INT32_C(  357144),  INT32_C(  420092) },
      {  -INT32_C(  173232),  INT32_C(   32216) },
          INT8_C(       1),
      {   INT64_C(  23011502208),  INT64_C(  27067367744) } },
    { {   INT32_C(  996227), -INT32_C(  523222), -INT32_C(  796632), -INT32_C(  264381) },
      {   INT32_C(  249707), -INT32_C(  944623) },
          INT8_C(       0),
      {  -INT64_C( 397849173648), -INT64_C( 132035572734) } },
    { {  -INT32_C(   45430),  INT32_C(  963547),  INT32_C(  504181),  INT32_C(  576837) },
      {  -INT32_C(   96621),  INT32_C(   13130) },
          INT8_C(       0),
      {  -INT64_C(  97428944802), -INT64_C( 111469135554) } },
    { {  -INT32_C(  708415),  INT32_C(  807399), -INT32_C(  664026), -INT32_C(  253901) },
      {   INT32_C(  649506), -INT32_C(  839324) },
          INT8_C(       0),
      {  -INT64_C( 862577742312), -INT64_C( 329820445812) } },
    { {  -INT32_C(  746644), -INT32_C(  231482), -INT32_C(  966072),  INT32_C(  467746) },
      {   INT32_C(  448186),  INT32_C(  992765) },
          INT8_C(       1),
      {  -INT64_C(1918164938160),  INT64_C( 928723715380) } },
    { {  -INT32_C(  962442),  INT32_C(   79204), -INT32_C(  791215), -INT32_C(  329825) },
      {  -INT32_C(  321988), -INT32_C(  285699) },
          INT8_C(       1),
      {   INT64_C( 452098668570),  INT64_C( 188461345350) } },
    { {   INT32_C(  223619),  INT32_C(  857944),  INT32_C(  770991), -INT32_C(  773107) },
      {   INT32_C(  301470),  INT32_C(  325192) },
          INT8_C(       0),
      {   INT64_C( 464861313540), -INT64_C( 466137134580) } },
    { {   INT32_C(  320762),  INT32_C(  304253),  INT32_C(  101896),  INT32_C(  354218) },
      {   INT32_C(   22025), -INT32_C(   31237) },
          INT8_C(       0),
      {   INT64_C(   4488518800),  INT64_C(  15603302900) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int64x2_t r;

    SIMDE_CONSTIFY_2_(simde_vqdmull_high_lane_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmull_high_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int16_t v[8];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
    { {  -INT16_C(    6151),  INT16_C(    6904), -INT16_C(    9865),  INT16_C(    7767),
          INT16_C(    7866), -INT16_C(    1675), -INT16_C(    6795),  INT16_C(    1504) },
      {  -INT16_C(    9543),  INT16_C(    3083), -INT16_C(    5514),  INT16_C(    5208),
          INT16_C(    4852),  INT16_C(    3875),  INT16_C(    4128),  INT16_C(    4648) },
          INT8_C(       7),
      {   INT32_C(  73122336), -INT32_C(  15570800), -INT32_C(  63166320),  INT32_C(  13981184) } },
    { {  -INT16_C(    9730), -INT16_C(    8790),  INT16_C(    8429),  INT16_C(    4708),
         -INT16_C(    2554), -INT16_C(    4220),  INT16_C(    9275), -INT16_C(    9174) },
      {   INT16_C(    5355), -INT16_C(    8996), -INT16_C(    3289), -INT16_C(    5823),
          INT16_C(    4975), -INT16_C(    9273), -INT16_C(    5946),  INT16_C(    9530) },
          INT8_C(       0),
      {  -INT32_C(  27353340), -INT32_C(  45196200),  INT32_C(  99335250), -INT32_C(  98253540) } },
    { {   INT16_C(    9947),  INT16_C(    2471), -INT16_C(    6285),  INT16_C(    7562),
         -INT16_C(    8090),  INT16_C(    5268),  INT16_C(    4311), -INT16_C(    5662) },
      {  -INT16_C(      38),  INT16_C(     252), -INT16_C(    9990), -INT16_C(    7375),
          INT16_C(      82),  INT16_C(    2766), -INT16_C(    7954), -INT16_C(     600) },
          INT8_C(       7),
      {   INT32_C(   9708000), -INT32_C(   6321600), -INT32_C(   5173200),  INT32_C(   6794400) } },
    { {   INT16_C(    3237),  INT16_C(    5149),  INT16_C(    1031), -INT16_C(    1352),
         -INT16_C(    2243), -INT16_C(     959), -INT16_C(    5508), -INT16_C(    2221) },
      {   INT16_C(    6518),  INT16_C(    3738), -INT16_C(    9586),  INT16_C(    1434),
         -INT16_C(    9713),  INT16_C(    4094), -INT16_C(    4925),  INT16_C(    9658) },
          INT8_C(       4),
      {   INT32_C(  43572518),  INT32_C(  18629534),  INT32_C( 106998408),  INT32_C(  43145146) } },
    { {   INT16_C(    1366), -INT16_C(    2722), -INT16_C(    1519), -INT16_C(    4492),
         -INT16_C(    2385),  INT16_C(    3823), -INT16_C(    4387), -INT16_C(    6834) },
      {  -INT16_C(    3277),  INT16_C(    8569), -INT16_C(    1556),  INT16_C(    2857),
          INT16_C(    1937),  INT16_C(     165), -INT16_C(    6546),  INT16_C(    6797) },
          INT8_C(       4),
      {  -INT32_C(   9239490),  INT32_C(  14810302), -INT32_C(  16995238), -INT32_C(  26474916) } },
    { {  -INT16_C(    4626), -INT16_C(    3341),  INT16_C(     487), -INT16_C(    3740),
          INT16_C(    6564),  INT16_C(    2633),  INT16_C(    8508), -INT16_C(    9233) },
      {  -INT16_C(    3352),  INT16_C(    9743), -INT16_C(     358),  INT16_C(    2662),
         -INT16_C(    8355), -INT16_C(    4002), -INT16_C(     632), -INT16_C(    8932) },
          INT8_C(       0),
      {  -INT32_C(  44005056), -INT32_C(  17651632), -INT32_C(  57037632),  INT32_C(  61898032) } },
    { {   INT16_C(    5502),  INT16_C(    8721), -INT16_C(    1735),  INT16_C(    4916),
          INT16_C(    7794),  INT16_C(    4166),  INT16_C(    5183), -INT16_C(    3690) },
      {  -INT16_C(    6794),  INT16_C(     882),  INT16_C(    4339),  INT16_C(    5349),
         -INT16_C(    2173),  INT16_C(    4714), -INT16_C(    1175), -INT16_C(    2584) },
          INT8_C(       3),
      {   INT32_C(  83380212),  INT32_C(  44567868),  INT32_C(  55447734), -INT32_C(  39475620) } },
    { {   INT16_C(    4845), -INT16_C(    7931),  INT16_C(    6178),  INT16_C(     701),
          INT16_C(     190),  INT16_C(    9654),  INT16_C(    6726), -INT16_C(    2015) },
      {   INT16_C(    6141), -INT16_C(    4604),  INT16_C(     840),  INT16_C(    9044),
          INT16_C(     416),  INT16_C(    8601), -INT16_C(    4851),  INT16_C(    9143) },
          INT8_C(       7),
      {   INT32_C(   3474340),  INT32_C( 176533044),  INT32_C( 122991636), -INT32_C(  36846290) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int32x4_t r;

    SIMDE_CONSTIFY_8_(simde_vqdmull_high_laneq_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmull_high_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t v[4];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(   170394437),  INT32_C(   838440752),  INT32_C(  2000223965),  INT32_C(   224778862) },
      {  INT32_C(  1294207306),  INT32_C(   797463044),  INT32_C(  1281649861),  INT32_C(   125061820) },
         INT8_C(           2),
      {  INT64_C(5127173533422237730),  INT64_C(576175594476076364) } },
    { { -INT32_C(  1594036428),  INT32_C(  1222292849),  INT32_C(  2015861929), -INT32_C(    82090536) },
      {  INT32_C(  2123083315), -INT32_C(   204875652), -INT32_C(   937168206), -INT32_C(   508936045) },
         INT8_C(           0),
      {  INT64_C(8559685653607229270), -INT64_C(348570094602013680) } },
    { {  INT32_C(   692200562), -INT32_C(   254752304),  INT32_C(   676464785),  INT32_C(  1809723204) },
      {  INT32_C(  1804668600),  INT32_C(  1691972474),  INT32_C(  1076408359),  INT32_C(   986035332) },
         INT8_C(           1),
      {  INT64_C(2289119591700656180),  INT64_C(6124003693454173392) } },
    { { -INT32_C(  1310053903),  INT32_C(  1964973717), -INT32_C(   230274986), -INT32_C(   655165622) },
      {  INT32_C(    77849012),  INT32_C(   523183193),  INT32_C(   306349840), -INT32_C(  1459982813) },
         INT8_C(           2),
      { -INT64_C(141089410234204480), -INT64_C(401419766946400960) } },
    { { -INT32_C(   167463656), -INT32_C(  1320629443), -INT32_C(  1195096316),  INT32_C(   285557548) },
      { -INT32_C(   905947543), -INT32_C(   461591499), -INT32_C(  1003092768), -INT32_C(  1992120667) },
         INT8_C(           1),
      {  INT64_C(1103292599903635368), -INT64_C(263621873264168904) } },
    { {  INT32_C(  1117388545),  INT32_C(  1452962560),  INT32_C(  1037242287), -INT32_C(  1218607240) },
      {  INT32_C(  1611559047), -INT32_C(   218371100), -INT32_C(   469758461), -INT32_C(  2134578451) },
         INT8_C(           2),
      { -INT64_C(974506680850480614),  INT64_C(1144902123251715280) } },
    { { -INT32_C(  1462364218), -INT32_C(  1974598648), -INT32_C(  1177302303),  INT32_C(   690147037) },
      {  INT32_C(   349207586), -INT32_C(   978044017),  INT32_C(  1007534029),  INT32_C(  1033057756) },
         INT8_C(           1),
      {  INT64_C(2302906947298942302), -INT64_C(1349988360776255258) } },
    { { -INT32_C(   957553051),  INT32_C(  1058397298),  INT32_C(   297981031), -INT32_C(  1782179923) },
      { -INT32_C(  2100356702),  INT32_C(  1207072133),  INT32_C(   443917590), -INT32_C(   985658139) },
         INT8_C(           3),
      { -INT64_C(587414856945522618),  INT64_C(3513240292534686594) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int64x2_t r;

    SIMDE_CONSTIFY_4_(simde_vqdmull_high_laneq_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, v);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_high_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_high_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_high_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_high_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
