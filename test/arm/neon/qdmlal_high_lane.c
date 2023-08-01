#define SIMDE_TEST_ARM_NEON_INSN qdmlal_high_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlal_high_lane.h"

static int
test_simde_vqdmlal_high_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {   INT32_C(   894353), -INT32_C(   114589),  INT32_C(   405183),  INT32_C(   768578) },
       {   INT16_C(     6491),  INT16_C(     3302), -INT16_C(     9424), -INT16_C(     2705),
           INT16_C(     7001),  INT16_C(     6386), -INT16_C(     9415),  INT16_C(     8455) },
       {   INT16_C(     4126),  INT16_C(     7156), -INT16_C(     4825), -INT16_C(     2552) },
           INT8_C(        3),
       {  -INT32_C( 34838751), -INT32_C( 32708733),  INT32_C( 48459343), -INT32_C( 42385742) } },
     { {   INT32_C(   192194),  INT32_C(   944576),  INT32_C(   519442), -INT32_C(   947446) },
       {   INT16_C(     9492),  INT16_C(     1554), -INT16_C(     7751), -INT16_C(     5715),
          -INT16_C(     4537),  INT16_C(      558), -INT16_C(     5640),  INT16_C(     3903) },
       {   INT16_C(     2026),  INT16_C(     2254),  INT16_C(     8886), -INT16_C(     7598) },
           INT8_C(        3),
       {   INT32_C( 69136446), -INT32_C(  7534792),  INT32_C( 86224882), -INT32_C( 60257434) } },
     { {   INT32_C(   470671), -INT32_C(    18986), -INT32_C(   848425),  INT32_C(   579963) },
       {  -INT16_C(     1439),  INT16_C(     6952), -INT16_C(     4417), -INT16_C(     1989),
           INT16_C(     3445),  INT16_C(     8250), -INT16_C(     1870),  INT16_C(     3800) },
       {   INT16_C(     9729), -INT16_C(     7764), -INT16_C(     7560),  INT16_C(      950) },
           INT8_C(        3),
       {   INT32_C(  7016171),  INT32_C( 15656014), -INT32_C(  4401425),  INT32_C(  7799963) } },
     { {   INT32_C(   294955),  INT32_C(   650666),  INT32_C(   881243),  INT32_C(   927961) },
       {  -INT16_C(     8925),  INT16_C(     2701),  INT16_C(     1635), -INT16_C(     9090),
          -INT16_C(     2483), -INT16_C(     5072), -INT16_C(     3082), -INT16_C(     9610) },
       {  -INT16_C(     6687), -INT16_C(     2609),  INT16_C(     8823),  INT16_C(     3170) },
           INT8_C(        0),
       {   INT32_C( 33502597),  INT32_C( 68483594),  INT32_C( 42099911),  INT32_C(129452101) } },
     { {   INT32_C(   335787),  INT32_C(    53789),  INT32_C(   281996),  INT32_C(   164669) },
       {   INT16_C(     9117),  INT16_C(     2965),  INT16_C(     5932), -INT16_C(     3598),
          -INT16_C(     1940),  INT16_C(     8189), -INT16_C(     7301),  INT16_C(     9863) },
       {   INT16_C(     4314),  INT16_C(     1423), -INT16_C(     5807), -INT16_C(     9427) },
           INT8_C(        3),
       {   INT32_C( 36912547), -INT32_C(154341617),  INT32_C(137935050), -INT32_C(185792333) } },
     { {   INT32_C(   858893),  INT32_C(   643324),  INT32_C(   115742), -INT32_C(    44124) },
       {  -INT16_C(     8990),  INT16_C(     9119),  INT16_C(     3798), -INT16_C(     6834),
           INT16_C(     1343), -INT16_C(     1875), -INT16_C(      778),  INT16_C(     7639) },
       {   INT16_C(     5027),  INT16_C(     2079),  INT16_C(     2810),  INT16_C(     1112) },
           INT8_C(        0),
       {   INT32_C( 14361415), -INT32_C( 18207926), -INT32_C(  7706270),  INT32_C( 76758382) } },
     { {  -INT32_C(   191455),  INT32_C(   878296),  INT32_C(   795255), -INT32_C(   663269) },
       {   INT16_C(     4146), -INT16_C(      589), -INT16_C(     7951),  INT16_C(     6759),
           INT16_C(     3630), -INT16_C(     5969), -INT16_C(     2209),  INT16_C(     5306) },
       {  -INT16_C(     3507),  INT16_C(      380),  INT16_C(      119), -INT16_C(     7800) },
           INT8_C(        3),
       {  -INT32_C( 56819455),  INT32_C( 93994696),  INT32_C( 35255655), -INT32_C( 83436869) } },
     { {   INT32_C(   643659), -INT32_C(   678171), -INT32_C(   638593),  INT32_C(   431494) },
       {   INT16_C(     8065), -INT16_C(     1701), -INT16_C(     9074),  INT16_C(     4292),
           INT16_C(     7650),  INT16_C(     2543),  INT16_C(     2984),  INT16_C(     3881) },
       {   INT16_C(     8706),  INT16_C(      241), -INT16_C(     8993), -INT16_C(     4041) },
           INT8_C(        2),
       {  -INT32_C(136949241), -INT32_C( 46416569), -INT32_C( 54308817), -INT32_C( 69372172) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vqdmlal_high_lane_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlal_high_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t v[8];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {   INT32_C(   127447),  INT32_C(   822978), -INT32_C(   697650), -INT32_C(   247883) },
       {  -INT16_C(     2100), -INT16_C(     3430), -INT16_C(     6622),  INT16_C(     1972),
          -INT16_C(      428),  INT16_C(      871), -INT16_C(     3600),  INT16_C(     4013) },
       {   INT16_C(     5528), -INT16_C(      610), -INT16_C(     1150), -INT16_C(     8205),
           INT16_C(     9857), -INT16_C(      697), -INT16_C(     2319),  INT16_C(     6430) },
           INT8_C(        3),
       {   INT32_C(  7150927), -INT32_C( 13470132),  INT32_C( 58378350), -INT32_C( 66101213) } },
     { {   INT32_C(   455747),  INT32_C(   701429), -INT32_C(   904921), -INT32_C(   464534) },
       {  -INT16_C(     7141), -INT16_C(     6045),  INT16_C(     1342),  INT16_C(     6390),
           INT16_C(     4621), -INT16_C(     5579), -INT16_C(     7186),  INT16_C(     9665) },
       {   INT16_C(     1260),  INT16_C(     4914), -INT16_C(     5142),  INT16_C(     4801),
          -INT16_C(     2144), -INT16_C(     1681), -INT16_C(     1211),  INT16_C(     8297) },
           INT8_C(        2),
       {  -INT32_C( 47066617),  INT32_C( 58075865),  INT32_C( 72995903), -INT32_C( 99859394) } },
     { {   INT32_C(   638305), -INT32_C(   186852), -INT32_C(   213973), -INT32_C(   931458) },
       {   INT16_C(     7760),  INT16_C(     4425),  INT16_C(     8019), -INT16_C(     8933),
           INT16_C(     7668),  INT16_C(      839), -INT16_C(     3102),  INT16_C(     9527) },
       {  -INT16_C(     6989),  INT16_C(     9603),  INT16_C(     2293), -INT16_C(     1576),
           INT16_C(       22), -INT16_C(     7541),  INT16_C(      861),  INT16_C(     5508) },
           INT8_C(        2),
       {   INT32_C( 35803753),  INT32_C(  3660802), -INT32_C( 14439745),  INT32_C( 42759364) } },
     { {   INT32_C(   467159),  INT32_C(   476002),  INT32_C(   413763), -INT32_C(   274557) },
       {  -INT16_C(     9758),  INT16_C(     2410), -INT16_C(     1361),  INT16_C(     2827),
          -INT16_C(     1655),  INT16_C(     6770), -INT16_C(       95),  INT16_C(     3127) },
       {   INT16_C(     2109), -INT16_C(     2712), -INT16_C(     7011), -INT16_C(     7930),
          -INT16_C(     5565),  INT16_C(     8254), -INT16_C(     2066),  INT16_C(      217) },
           INT8_C(        1),
       {   INT32_C(  9443879), -INT32_C( 36244478),  INT32_C(   929043), -INT32_C( 17235405) } },
     { {  -INT32_C(   915165), -INT32_C(   571143), -INT32_C(   687588), -INT32_C(   595102) },
       {  -INT16_C(     3396), -INT16_C(      330),  INT16_C(     7337), -INT16_C(     7912),
           INT16_C(     9264), -INT16_C(     6773), -INT16_C(     8665),  INT16_C(     3851) },
       {  -INT16_C(     2715),  INT16_C(     3092), -INT16_C(     4692),  INT16_C(     2741),
           INT16_C(     6259),  INT16_C(     5204),  INT16_C(     7522), -INT16_C(     7232) },
           INT8_C(        3),
       {   INT32_C( 49870083), -INT32_C( 37700729), -INT32_C( 48189118),  INT32_C( 20516080) } },
     { {   INT32_C(   627584), -INT32_C(    43401),  INT32_C(   754581),  INT32_C(   870436) },
       {   INT16_C(     2524),  INT16_C(     7564),  INT16_C(     5391), -INT16_C(     4454),
           INT16_C(     2191),  INT16_C(     4050), -INT16_C(     3970), -INT16_C(     4712) },
       {  -INT16_C(     1285), -INT16_C(     2198), -INT16_C(     3116), -INT16_C(     1852),
           INT16_C(     7505), -INT16_C(     5812), -INT16_C(     2990), -INT16_C(     5934) },
           INT8_C(        3),
       {  -INT32_C(  7487880), -INT32_C( 15044601),  INT32_C( 15459461),  INT32_C( 18323684) } },
     { {  -INT32_C(    54830), -INT32_C(   203132), -INT32_C(   595975), -INT32_C(   337050) },
       {  -INT16_C(     1470),  INT16_C(     7910), -INT16_C(     8333), -INT16_C(     3329),
           INT16_C(     6685), -INT16_C(     7194),  INT16_C(     5248), -INT16_C(     7801) },
       {   INT16_C(     9530),  INT16_C(     4964),  INT16_C(     3207),  INT16_C(     8287),
           INT16_C(      716), -INT16_C(     2058), -INT16_C(     6439), -INT16_C(     5117) },
           INT8_C(        2),
       {   INT32_C( 42822760), -INT32_C( 46345448),  INT32_C( 33064697), -INT32_C( 50372664) } },
     { {   INT32_C(    35118), -INT32_C(   320708), -INT32_C(    51072),  INT32_C(   492529) },
       {   INT16_C(      757),  INT16_C(     6726), -INT16_C(     6022), -INT16_C(     8158),
           INT16_C(     5620),  INT16_C(     1231), -INT16_C(      260), -INT16_C(     8318) },
       {   INT16_C(      156),  INT16_C(     8068), -INT16_C(     7568),  INT16_C(     9602),
          -INT16_C(     6431),  INT16_C(     9768), -INT16_C(     6471),  INT16_C(     2563) },
           INT8_C(        0),
       {   INT32_C(  1788558),  INT32_C(    63364), -INT32_C(   132192), -INT32_C(  2102687) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int32x4_t r;
    SIMDE_CONSTIFY_8_(simde_vqdmlal_high_laneq_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlal_high_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t v[4];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(     13898671), -INT64_C(     28702086) },
       {  -INT32_C(       263510), -INT32_C(       347579),  INT32_C(       942651), -INT32_C(        19214) },
       {  -INT32_C(       985912),  INT32_C(       863503), -INT32_C(       864486), -INT32_C(        67563) },
           INT8_C(            3),
       {  -INT64_C( 127362760355),  INT64_C(   2567608878) } },
     { {  -INT64_C(     49550599),  INT64_C(     12924804) },
       {   INT32_C(       569339),  INT32_C(       916303),  INT32_C(       322651), -INT32_C(       403309) },
       {   INT32_C(        68174), -INT32_C(       513605),  INT32_C(         1763), -INT32_C(       583573) },
           INT8_C(            1),
       {  -INT64_C( 331479884309),  INT64_C( 414295962694) } },
     { {   INT64_C(     33224957), -INT64_C(     60263322) },
       {  -INT32_C(       733914),  INT32_C(       345428), -INT32_C(       188026), -INT32_C(       361972) },
       {  -INT32_C(       436531),  INT32_C(       676538),  INT32_C(        34787), -INT32_C(       755451) },
           INT8_C(            2),
       {  -INT64_C(  13048495967), -INT64_C(  25244103250) } },
     { {  -INT64_C(     52374386), -INT64_C(     63935054) },
       {   INT32_C(       407419), -INT32_C(       463334), -INT32_C(        37967),  INT32_C(       535562) },
       {  -INT32_C(       286385), -INT32_C(       865597),  INT32_C(       573606),  INT32_C(       589682) },
           INT8_C(            0),
       {   INT64_C(  21693984204), -INT64_C( 306817781794) } },
     { {  -INT64_C(      6598636),  INT64_C(     73031330) },
       {   INT32_C(       493558),  INT32_C(       443848), -INT32_C(       419461),  INT32_C(       376534) },
       {  -INT32_C(       860362), -INT32_C(       176951),  INT32_C(       253114),  INT32_C(        41359) },
           INT8_C(            1),
       {   INT64_C( 148441488186), -INT64_C( 133183104338) } },
     { {  -INT64_C(     71693657),  INT64_C(     31801833) },
       {  -INT32_C(       640025),  INT32_C(       582287),  INT32_C(       257565),  INT32_C(       667728) },
       {   INT32_C(       984425),  INT32_C(       972052),  INT32_C(       466460),  INT32_C(       325387) },
           INT8_C(            0),
       {   INT64_C( 507035156593),  INT64_C(1314688074633) } },
     { {   INT64_C(     80798879), -INT64_C(      5132023) },
       {   INT32_C(        40841),  INT32_C(       230578), -INT32_C(        63996),  INT32_C(       386471) },
       {  -INT32_C(       872708), -INT32_C(        69206),  INT32_C(       475254), -INT32_C(       518991) },
           INT8_C(            3),
       {   INT64_C(  66507494951), -INT64_C( 401155073545) } },
     { {  -INT64_C(      7962780),  INT64_C(     26698152) },
       {  -INT32_C(       245699), -INT32_C(       779577),  INT32_C(       614398),  INT32_C(       990465) },
       {  -INT32_C(       682597),  INT32_C(       354148),  INT32_C(       119693), -INT32_C(       196681) },
           INT8_C(            0),
       {  -INT64_C( 838780425992), -INT64_C(1352150177058) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int64x2_t r;
    SIMDE_CONSTIFY_4_(simde_vqdmlal_high_laneq_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlal_high_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t v[2];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {  -INT64_C(     22649710),  INT64_C(     73149530) },
       {  -INT32_C(       674621), -INT32_C(       663040),  INT32_C(       244552),  INT32_C(       207830) },
       {   INT32_C(       291873),  INT32_C(       695008) },
           INT8_C(            1),
       {   INT64_C( 339908543122),  INT64_C( 288960174810) } },
     { {   INT64_C(     74893760),  INT64_C(     21422606) },
       {  -INT32_C(       756129), -INT32_C(       910364), -INT32_C(       884819),  INT32_C(       337637) },
       {  -INT32_C(       926175),  INT32_C(        65143) },
           INT8_C(            1),
       {  -INT64_C( 115204634474),  INT64_C(  44010796788) } },
     { {  -INT64_C(     87847761), -INT64_C(     71055001) },
       {   INT32_C(       532811), -INT32_C(       865841),  INT32_C(       608434),  INT32_C(       302705) },
       {   INT32_C(        67173), -INT32_C(       302540) },
           INT8_C(            0),
       {   INT64_C(  81652826403),  INT64_C(  40596150929) } },
     { {  -INT64_C(     41489469),  INT64_C(     33328384) },
       {   INT32_C(       266498),  INT32_C(       888074), -INT32_C(       970120),  INT32_C(       774275) },
       {   INT32_C(       620043),  INT32_C(       473602) },
           INT8_C(            1),
       {  -INT64_C( 918943033949),  INT64_C( 733429705484) } },
     { {   INT64_C(     96386778),  INT64_C(     11393205) },
       {   INT32_C(       679805),  INT32_C(         6544),  INT32_C(       994812),  INT32_C(       231461) },
       {  -INT32_C(       690699), -INT32_C(       511317) },
           INT8_C(            1),
       {  -INT64_C(1017232188030), -INT64_C( 236688495069) } },
     { {   INT64_C(     40244631), -INT64_C(      1612051) },
       {  -INT32_C(       415899), -INT32_C(       119442), -INT32_C(       220145), -INT32_C(       506440) },
       {   INT32_C(         7233),  INT32_C(       114175) },
           INT8_C(            0),
       {  -INT64_C(   3144372939), -INT64_C(   7327773091) } },
     { {  -INT64_C(     57747523), -INT64_C(     44936371) },
       {   INT32_C(       385308),  INT32_C(       496935), -INT32_C(       919538), -INT32_C(       160369) },
       {   INT32_C(       348290),  INT32_C(       358396) },
           INT8_C(            1),
       {  -INT64_C( 659175229619), -INT64_C( 114996152619) } },
     { {   INT64_C(     80405546), -INT64_C(     36417386) },
       {  -INT32_C(       895739), -INT32_C(       737647), -INT32_C(       168388), -INT32_C(       183564) },
       {  -INT32_C(       562898), -INT32_C(       405129) },
           INT8_C(            0),
       {   INT64_C( 189650942394),  INT64_C( 206619199558) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vqdmlal_high_lane_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_high_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_high_lane_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_high_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_high_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
