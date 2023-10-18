#define SIMDE_TEST_ARM_NEON_INSN mlal_high_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mlal_high_lane.h"

static int
test_simde_vmlal_high_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t v[8];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(   4406058),  INT32_C(   8594762), -INT32_C(   4438344),  INT32_C(   4284051) },
       {  -INT16_C(      7569), -INT16_C(      2636),  INT16_C(      9703), -INT16_C(      6205),
          -INT16_C(      1133), -INT16_C(      6695),  INT16_C(        49), -INT16_C(      3446) },
       {   INT16_C(      8747),  INT16_C(      1548), -INT16_C(      2880), -INT16_C(      4509),
          -INT16_C(      1216),  INT16_C(      5189), -INT16_C(      7113),  INT16_C(      8336) },
           INT8_C(         5),
       {  -INT32_C(  10285195), -INT32_C(  26145593), -INT32_C(   4184083), -INT32_C(  13597243) } },
     { {  -INT32_C(   9830202),  INT32_C(   3121497), -INT32_C(   7759855), -INT32_C(    820350) },
       {  -INT16_C(      6887),  INT16_C(      9051),  INT16_C(      1315),  INT16_C(      6723),
          -INT16_C(      6245),  INT16_C(      2962), -INT16_C(      2156), -INT16_C(      9817) },
       {   INT16_C(      9129),  INT16_C(      5065), -INT16_C(       905), -INT16_C(      1121),
          -INT16_C(         2),  INT16_C(      4827), -INT16_C(      8602), -INT16_C(      5206) },
           INT8_C(         0),
       {  -INT32_C(  66840807),  INT32_C(  30161595), -INT32_C(  27441979), -INT32_C(  90439743) } },
     { {   INT32_C(   8595222), -INT32_C(   8524727),  INT32_C(   4187766), -INT32_C(   9062933) },
       {  -INT16_C(      2343),  INT16_C(      2612), -INT16_C(      6106), -INT16_C(      4572),
           INT16_C(      5179), -INT16_C(      9713),  INT16_C(      9329),  INT16_C(      4591) },
       {   INT16_C(      6566), -INT16_C(      1645), -INT16_C(      3500),  INT16_C(      5115),
           INT16_C(      3191), -INT16_C(      2940),  INT16_C(      7754),  INT16_C(       199) },
           INT8_C(         4),
       {   INT32_C(  25121411), -INT32_C(  39518910),  INT32_C(  33956605),  INT32_C(   5586948) } },
     { {   INT32_C(   8303620), -INT32_C(   2244672), -INT32_C(   7623952),  INT32_C(   4498971) },
       {  -INT16_C(      1679),  INT16_C(      6998), -INT16_C(      7210),  INT16_C(       759),
           INT16_C(       732),  INT16_C(       406),  INT16_C(      6834), -INT16_C(      9679) },
       {  -INT16_C(       172), -INT16_C(      9945),  INT16_C(      9734), -INT16_C(      5552),
           INT16_C(      8167), -INT16_C(      1116), -INT16_C(      9401), -INT16_C(      2755) },
           INT8_C(         5),
       {   INT32_C(   7486708), -INT32_C(   2697768), -INT32_C(  15250696),  INT32_C(  15300735) } },
     { {   INT32_C(   3026258), -INT32_C(   7909011), -INT32_C(   2204046),  INT32_C(    540470) },
       {   INT16_C(      3461), -INT16_C(      8968),  INT16_C(      3685), -INT16_C(      1789),
           INT16_C(      8647), -INT16_C(      3918),  INT16_C(       521),  INT16_C(      9282) },
       {   INT16_C(      2143), -INT16_C(      4425), -INT16_C(      3341),  INT16_C(      3974),
           INT16_C(      5110), -INT16_C(      8757),  INT16_C(      7097), -INT16_C(      7726) },
           INT8_C(         7),
       {  -INT32_C(  63780464),  INT32_C(  22361457), -INT32_C(   6229292), -INT32_C(  71172262) } },
     { {  -INT32_C(   8224939), -INT32_C(   8215918), -INT32_C(   5663906), -INT32_C(   5459868) },
       {  -INT16_C(      8566), -INT16_C(      3359),  INT16_C(      7584), -INT16_C(      8202),
           INT16_C(      3417),  INT16_C(      8358),  INT16_C(      4162), -INT16_C(       545) },
       {  -INT16_C(      3264),  INT16_C(      7765), -INT16_C(      7330), -INT16_C(      9670),
          -INT16_C(      4342),  INT16_C(      3531), -INT16_C(      2217), -INT16_C(      9483) },
           INT8_C(         3),
       {  -INT32_C(  41267329), -INT32_C(  89037778), -INT32_C(  45910446), -INT32_C(    189718) } },
     { {  -INT32_C(   6900876),  INT32_C(   1989038),  INT32_C(   5250510),  INT32_C(   2462603) },
       {   INT16_C(      8455),  INT16_C(       619), -INT16_C(      8256), -INT16_C(      9681),
          -INT16_C(      2879), -INT16_C(      1635), -INT16_C(      7379), -INT16_C(      3183) },
       {   INT16_C(      6548), -INT16_C(      5649), -INT16_C(      1756), -INT16_C(      1987),
          -INT16_C(      9816),  INT16_C(       143),  INT16_C(      5426), -INT16_C(      8359) },
           INT8_C(         6),
       {  -INT32_C(  22522330), -INT32_C(   6882472), -INT32_C(  34787944), -INT32_C(  14808355) } },
     { {  -INT32_C(   2631663), -INT32_C(   5946993),  INT32_C(   9903067),  INT32_C(   1768734) },
       {  -INT16_C(      8581),  INT16_C(      4016),  INT16_C(      6351),  INT16_C(      8737),
          -INT16_C(       114), -INT16_C(      3913),  INT16_C(      3836),  INT16_C(       647) },
       {   INT16_C(      5939),  INT16_C(        68), -INT16_C(      8203),  INT16_C(      4957),
           INT16_C(       113),  INT16_C(        51),  INT16_C(      4941),  INT16_C(      6129) },
           INT8_C(         1),
       {  -INT32_C(   2639415), -INT32_C(   6213077),  INT32_C(  10163915),  INT32_C(   1812730) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int32x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmlal_high_laneq_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlal_high_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(     92491), -INT32_C(   4991423), -INT32_C(   6962261),  INT32_C(    754720) },
       {   INT16_C(      2235), -INT16_C(      4935),  INT16_C(      7385), -INT16_C(      5463),
          -INT16_C(      3474), -INT16_C(      4909), -INT16_C(       640), -INT16_C(       313) },
       {   INT16_C(      5168), -INT16_C(      6389),  INT16_C(      8233),  INT16_C(      6391) },
           INT8_C(         3),
       {  -INT32_C(  22294825), -INT32_C(  36364842), -INT32_C(  11052501), -INT32_C(   1245663) } },
     { {   INT32_C(   9674847), -INT32_C(   1278400), -INT32_C(   5987353),  INT32_C(   7527095) },
       {  -INT16_C(      1296), -INT16_C(      5541),  INT16_C(      6340), -INT16_C(      4916),
          -INT16_C(      1132),  INT16_C(      8128),  INT16_C(      8305),  INT16_C(      9032) },
       {  -INT16_C(      1737),  INT16_C(      3875),  INT16_C(      7202), -INT16_C(      7464) },
           INT8_C(         2),
       {   INT32_C(   1522183),  INT32_C(  57259456),  INT32_C(  53825257),  INT32_C(  72575559) } },
     { {  -INT32_C(   2804130), -INT32_C(   3910477),  INT32_C(   4740399),  INT32_C(   2398754) },
       {   INT16_C(      3552),  INT16_C(      6585), -INT16_C(      1488), -INT16_C(      1378),
          -INT16_C(      6480),  INT16_C(      3723), -INT16_C(       650),  INT16_C(      9068) },
       {  -INT16_C(      2168), -INT16_C(      3240), -INT16_C(      3091),  INT16_C(      4709) },
           INT8_C(         0),
       {   INT32_C(  11244510), -INT32_C(  11981941),  INT32_C(   6149599), -INT32_C(  17260670) } },
     { {  -INT32_C(   9721994),  INT32_C(    480786),  INT32_C(   3633340),  INT32_C(   4812745) },
       {   INT16_C(      6156), -INT16_C(      3750), -INT16_C(      6058), -INT16_C(      5432),
           INT16_C(      6996),  INT16_C(      4382),  INT16_C(      5315), -INT16_C(      8048) },
       {  -INT16_C(      5881), -INT16_C(      4564), -INT16_C(      7120),  INT16_C(      3603) },
           INT8_C(         3),
       {   INT32_C(  15484594),  INT32_C(  16269132),  INT32_C(  22783285), -INT32_C(  24184199) } },
     { {  -INT32_C(   6952809),  INT32_C(   7957212),  INT32_C(   9452683),  INT32_C(   1765422) },
       {   INT16_C(      2811),  INT16_C(      2833), -INT16_C(      3912),  INT16_C(       722),
          -INT16_C(      1822),  INT16_C(       898),  INT16_C(      2517),  INT16_C(       604) },
       {  -INT16_C(      2211),  INT16_C(      7933), -INT16_C(      4330),  INT16_C(      1609) },
           INT8_C(         1),
       {  -INT32_C(  21406735),  INT32_C(  15081046),  INT32_C(  29420044),  INT32_C(   6556954) } },
     { {   INT32_C(   7386160),  INT32_C(   8890562), -INT32_C(   5677039), -INT32_C(   1223802) },
       {   INT16_C(      8986),  INT16_C(      4235), -INT16_C(      8777), -INT16_C(      4965),
           INT16_C(      9251), -INT16_C(      6676),  INT16_C(      2104),  INT16_C(      4790) },
       {  -INT16_C(      9040),  INT16_C(      9813),  INT16_C(      1608),  INT16_C(      4624) },
           INT8_C(         0),
       {  -INT32_C(  76242880),  INT32_C(  69241602), -INT32_C(  24697199), -INT32_C(  44525402) } },
     { {  -INT32_C(   1883198),  INT32_C(   8275243),  INT32_C(   6306150), -INT32_C(   9752993) },
       {   INT16_C(      5221),  INT16_C(      4046),  INT16_C(      1025), -INT16_C(      2123),
          -INT16_C(      9462), -INT16_C(      1979),  INT16_C(       657),  INT16_C(      3911) },
       {   INT16_C(      9269),  INT16_C(      7938),  INT16_C(       210), -INT16_C(      2149) },
           INT8_C(         2),
       {  -INT32_C(   3870218),  INT32_C(   7859653),  INT32_C(   6444120), -INT32_C(   8931683) } },
     { {   INT32_C(    579073),  INT32_C(   1895524), -INT32_C(   7083507), -INT32_C(   6692075) },
       {   INT16_C(      7032), -INT16_C(      3476),  INT16_C(      9049),  INT16_C(      6246),
          -INT16_C(      5463), -INT16_C(      2974), -INT16_C(      5445), -INT16_C(      1393) },
       {  -INT16_C(      1115), -INT16_C(      9184),  INT16_C(       120),  INT16_C(      8630) },
           INT8_C(         0),
       {   INT32_C(   6670318),  INT32_C(   5211534), -INT32_C(   1012332), -INT32_C(   5138880) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmlal_high_lane_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlal_high_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t v[4];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {  -INT64_C(    715265200),  INT64_C(    269714938) },
       {   INT32_C(        88248), -INT32_C(       502078), -INT32_C(       726867), -INT32_C(       591805) },
       {   INT32_C(       779565), -INT32_C(       878186),  INT32_C(       520407),  INT32_C(       469393) },
           INT8_C(            3),
       {  -INT64_C( 341901546931), -INT64_C( 277519409427) } },
     { {  -INT64_C(    142528748), -INT64_C(    845468102) },
       {  -INT32_C(       181994), -INT32_C(       311631),  INT32_C(       834928), -INT32_C(       325945) },
       {   INT32_C(        18645),  INT32_C(         5351),  INT32_C(       653713),  INT32_C(       553944) },
           INT8_C(            3),
       {   INT64_C( 462360827284), -INT64_C( 181400745182) } },
     { {  -INT64_C(     72197620),  INT64_C(    416280002) },
       {   INT32_C(       395131),  INT32_C(       664381),  INT32_C(       976748),  INT32_C(       960679) },
       {  -INT32_C(        80858), -INT32_C(         9524), -INT32_C(       360067),  INT32_C(       828252) },
           INT8_C(            2),
       {  -INT64_C( 351766919736), -INT64_C( 345492525491) } },
     { {   INT64_C(    245795381), -INT64_C(    416427705) },
       {  -INT32_C(       675063), -INT32_C(       982458),  INT32_C(       887762),  INT32_C(       931604) },
       {   INT32_C(       426164), -INT32_C(       870540),  INT32_C(       980771), -INT32_C(       314064) },
           INT8_C(            3),
       {  -INT64_C( 278568289387), -INT64_C( 292999706361) } },
     { {   INT64_C(    914950112), -INT64_C(    152036963) },
       {   INT32_C(       408930), -INT32_C(       713592),  INT32_C(       345846),  INT32_C(       662237) },
       {  -INT32_C(       639618),  INT32_C(       819242),  INT32_C(       926073),  INT32_C(       790077) },
           INT8_C(            1),
       {   INT64_C( 284246518844),  INT64_C( 542380327391) } },
     { {  -INT64_C(    742448719), -INT64_C(    447505816) },
       {  -INT32_C(       101306),  INT32_C(       346447), -INT32_C(       441632), -INT32_C(       308497) },
       {  -INT32_C(       153682), -INT32_C(       464613),  INT32_C(       511092), -INT32_C(        42392) },
           INT8_C(            2),
       {  -INT64_C( 226457030863), -INT64_C( 158117854540) } },
     { {  -INT64_C(    107186426), -INT64_C(    456887033) },
       {   INT32_C(        57885), -INT32_C(       789527),  INT32_C(       518707), -INT32_C(       658479) },
       {   INT32_C(        56961), -INT32_C(       434997),  INT32_C(       466543),  INT32_C(       436941) },
           INT8_C(            3),
       {   INT64_C( 226537168861), -INT64_C( 288173359772) } },
     { {   INT64_C(    545535846), -INT64_C(    812072135) },
       {  -INT32_C(       715200),  INT32_C(        98996), -INT32_C(       913076), -INT32_C(       363614) },
       {  -INT32_C(       869174),  INT32_C(       915053),  INT32_C(        12643), -INT32_C(       261674) },
           INT8_C(            3),
       {   INT64_C( 239473785070),  INT64_C(  94336257701) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int64x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmlal_high_laneq_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlal_high_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t v[2];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(    487680880), -INT64_C(    964134280) },
       {   INT32_C(       185396), -INT32_C(       962680),  INT32_C(       319975), -INT32_C(        63278) },
       {  -INT32_C(       894626), -INT32_C(       380723) },
           INT8_C(            1),
       {  -INT64_C( 121334161045),  INT64_C(  23127255714) } },
     { {   INT64_C(    144727650),  INT64_C(       171539) },
       {   INT32_C(       151644),  INT32_C(       214255),  INT32_C(       651624), -INT32_C(        42872) },
       {   INT32_C(       968940),  INT32_C(       111669) },
           INT8_C(            1),
       {   INT64_C(  72910928106), -INT64_C(   4787301829) } },
     { {   INT64_C(     86946010), -INT64_C(    102415414) },
       {   INT32_C(        31597),  INT32_C(       608905),  INT32_C(       101866), -INT32_C(       868125) },
       {  -INT32_C(       584715), -INT32_C(       814147) },
           INT8_C(            0),
       {  -INT64_C(  59475632180),  INT64_C( 507503293961) } },
     { {   INT64_C(    667044459),  INT64_C(    167323826) },
       {  -INT32_C(       539162),  INT32_C(       570958), -INT32_C(       563508), -INT32_C(       609980) },
       {  -INT32_C(       614493), -INT32_C(       579962) },
           INT8_C(            0),
       {   INT64_C( 346938765903),  INT64_C( 374995763966) } },
     { {   INT64_C(    212290540), -INT64_C(    680785928) },
       {   INT32_C(       559758),  INT32_C(       758651), -INT32_C(       218804),  INT32_C(       283401) },
       {  -INT32_C(       277799),  INT32_C(       325444) },
           INT8_C(            1),
       {  -INT64_C(  70996158436),  INT64_C(  91550369116) } },
     { {   INT64_C(     48632956),  INT64_C(    729181621) },
       {  -INT32_C(       184632),  INT32_C(         5268), -INT32_C(       663102), -INT32_C(       604470) },
       {   INT32_C(       367518),  INT32_C(       919660) },
           INT8_C(            0),
       {  -INT64_C( 243653287880), -INT64_C( 221424423839) } },
     { {   INT64_C(     40792544),  INT64_C(    525694445) },
       {   INT32_C(       330695), -INT32_C(       120051),  INT32_C(       418734),  INT32_C(       809017) },
       {  -INT32_C(       681949),  INT32_C(       797501) },
           INT8_C(            0),
       {  -INT64_C( 285514440022), -INT64_C( 551182639688) } },
     { {  -INT64_C(    108331267), -INT64_C(    157859080) },
       {  -INT32_C(       729463), -INT32_C(       365438), -INT32_C(       115001), -INT32_C(       131517) },
       {   INT32_C(        83846), -INT32_C(       203448) },
           INT8_C(            0),
       {  -INT64_C(   9750705113), -INT64_C(  11185033462) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmlal_high_lane_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlal_high_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint16_t v[8];
    int8_t lane;
    uint32_t r[4];
  } test_vec[] = {
     { {   UINT32_C(   823552),  UINT32_C(  1583715),  UINT32_C(   125243),  UINT32_C(   841409) },
       {   UINT16_C(    11516),  UINT16_C(    16924),  UINT16_C(    12629),  UINT16_C(    12120),
           UINT16_C(     3697),  UINT16_C(    10848),  UINT16_C(    13480),  UINT16_C(     5328) },
       {   UINT16_C(    16203),  UINT16_C(      152),  UINT16_C(     6471),  UINT16_C(     9438),
           UINT16_C(     6558),  UINT16_C(     3885),  UINT16_C(    13828),  UINT16_C(    17373) },
           INT8_C(        2),
       {   UINT32_C( 24746839),  UINT32_C( 71781123),  UINT32_C( 87354323),  UINT32_C( 35318897) } },
     { {   UINT32_C(  1149210),  UINT32_C(   870807),  UINT32_C(   941770),  UINT32_C(   538856) },
       {   UINT16_C(     5305),  UINT16_C(     2956),  UINT16_C(     7122),  UINT16_C(    11350),
           UINT16_C(     9487),  UINT16_C(     3690),  UINT16_C(    17134),  UINT16_C(      220) },
       {   UINT16_C(    17477),  UINT16_C(     8446),  UINT16_C(    18806),  UINT16_C(    12133),
           UINT16_C(     5081),  UINT16_C(     4438),  UINT16_C(    16954),  UINT16_C(     6981) },
           INT8_C(        5),
       {   UINT32_C( 43252516),  UINT32_C( 17247027),  UINT32_C( 76982462),  UINT32_C(  1515216) } },
     { {   UINT32_C(  1516684),  UINT32_C(  1565377),  UINT32_C(  1529870),  UINT32_C(  1550536) },
       {   UINT16_C(    12746),  UINT16_C(     6401),  UINT16_C(    14666),  UINT16_C(     8345),
           UINT16_C(    10790),  UINT16_C(    12599),  UINT16_C(     3610),  UINT16_C(     9232) },
       {   UINT16_C(     3677),  UINT16_C(     1991),  UINT16_C(     3971),  UINT16_C(     8269),
           UINT16_C(    10848),  UINT16_C(    14011),  UINT16_C(     7535),  UINT16_C(     4999) },
           INT8_C(        1),
       {   UINT32_C( 22999574),  UINT32_C( 26649986),  UINT32_C(  8717380),  UINT32_C( 19931448) } },
     { {   UINT32_C(   179695),  UINT32_C(  1633448),  UINT32_C(  1361260),  UINT32_C(   886103) },
       {   UINT16_C(     5504),  UINT16_C(    15015),  UINT16_C(    15563),  UINT16_C(     5303),
           UINT16_C(    16734),  UINT16_C(     4420),  UINT16_C(     4520),  UINT16_C(     4370) },
       {   UINT16_C(    19267),  UINT16_C(     2332),  UINT16_C(    11249),  UINT16_C(    18799),
           UINT16_C(    13891),  UINT16_C(     5895),  UINT16_C(    13534),  UINT16_C(    12884) },
           INT8_C(        4),
       {   UINT32_C(232631689),  UINT32_C( 63031668),  UINT32_C( 64148580),  UINT32_C( 61589773) } },
     { {   UINT32_C(    35822),  UINT32_C(   672887),  UINT32_C(   327136),  UINT32_C(  1985525) },
       {   UINT16_C(    10533),  UINT16_C(     1227),  UINT16_C(    18158),  UINT16_C(     7741),
           UINT16_C(    19212),  UINT16_C(    13701),  UINT16_C(    19168),  UINT16_C(    18807) },
       {   UINT16_C(    17532),  UINT16_C(     7503),  UINT16_C(     7017),  UINT16_C(    18649),
           UINT16_C(     4424),  UINT16_C(     6986),  UINT16_C(    11514),  UINT16_C(     9620) },
           INT8_C(        4),
       {   UINT32_C( 85029710),  UINT32_C( 61286111),  UINT32_C( 85126368),  UINT32_C( 85187693) } },
     { {   UINT32_C(   557761),  UINT32_C(   279493),  UINT32_C(   821030),  UINT32_C(  1682208) },
       {   UINT16_C(    17401),  UINT16_C(     9083),  UINT16_C(    13665),  UINT16_C(    19890),
           UINT16_C(    11596),  UINT16_C(    16520),  UINT16_C(      343),  UINT16_C(      880) },
       {   UINT16_C(     6411),  UINT16_C(     5820),  UINT16_C(     4373),  UINT16_C(     9293),
           UINT16_C(    11919),  UINT16_C(    11552),  UINT16_C(    19614),  UINT16_C(    15450) },
           INT8_C(        7),
       {   UINT32_C(179715961),  UINT32_C(255513493),  UINT32_C(  6120380),  UINT32_C( 15278208) } },
     { {   UINT32_C(   278083),  UINT32_C(   790523),  UINT32_C(  1050079),  UINT32_C(  1535143) },
       {   UINT16_C(    15332),  UINT16_C(    19391),  UINT16_C(     1377),  UINT16_C(    14311),
           UINT16_C(    19662),  UINT16_C(     9467),  UINT16_C(     3839),  UINT16_C(    14765) },
       {   UINT16_C(    16834),  UINT16_C(     5587),  UINT16_C(    13414),  UINT16_C(     4613),
           UINT16_C(     5986),  UINT16_C(     6482),  UINT16_C(     8238),  UINT16_C(     9616) },
           INT8_C(        0),
       {   UINT32_C(331268191),  UINT32_C(160158001),  UINT32_C( 65675805),  UINT32_C(250089153) } },
     { {   UINT32_C(   673192),  UINT32_C(  1057014),  UINT32_C(   587709),  UINT32_C(  1164643) },
       {   UINT16_C(    16534),  UINT16_C(    16353),  UINT16_C(    11217),  UINT16_C(    14975),
           UINT16_C(    19641),  UINT16_C(    12295),  UINT16_C(     3505),  UINT16_C(     5527) },
       {   UINT16_C(    14295),  UINT16_C(    19182),  UINT16_C(     1458),  UINT16_C(     1238),
           UINT16_C(    10902),  UINT16_C(    12367),  UINT16_C(    13167),  UINT16_C(    12804) },
           INT8_C(        7),
       {   UINT32_C(252156556),  UINT32_C(158482194),  UINT32_C( 45465729),  UINT32_C( 71932351) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t v = simde_vld1q_u16(test_vec[i].v);
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmlal_high_laneq_u16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlal_high_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint16_t v[4];
    int8_t lane;
    uint32_t r[4];
  } test_vec[] = {
     { {   UINT32_C(   420634),  UINT32_C(   293005),  UINT32_C(   407798),  UINT32_C(  1465890) },
       {   UINT16_C(     3558),  UINT16_C(     9827),  UINT16_C(     6927),  UINT16_C(      613),
           UINT16_C(    19349),  UINT16_C(    14878),  UINT16_C(    19617),  UINT16_C(     9078) },
       {   UINT16_C(     8390),  UINT16_C(    10747),  UINT16_C(    15158),  UINT16_C(     4748) },
           INT8_C(        3),
       {   UINT32_C( 92289686),  UINT32_C( 70933749),  UINT32_C( 93549314),  UINT32_C( 44568234) } },
     { {   UINT32_C(  1737289),  UINT32_C(   297926),  UINT32_C(   308256),  UINT32_C(   766049) },
       {   UINT16_C(    17935),  UINT16_C(    15073),  UINT16_C(    15854),  UINT16_C(    12815),
           UINT16_C(     4185),  UINT16_C(    12810),  UINT16_C(    12448),  UINT16_C(     3050) },
       {   UINT16_C(      853),  UINT16_C(     8241),  UINT16_C(    14175),  UINT16_C(     3816) },
           INT8_C(        0),
       {   UINT32_C(  5307094),  UINT32_C( 11224856),  UINT32_C( 10926400),  UINT32_C(  3367699) } },
     { {   UINT32_C(    71249),  UINT32_C(  1172186),  UINT32_C(   843078),  UINT32_C(  1431404) },
       {   UINT16_C(    16237),  UINT16_C(     2382),  UINT16_C(     3646),  UINT16_C(    19155),
           UINT16_C(    12263),  UINT16_C(    19738),  UINT16_C(     1221),  UINT16_C(     8080) },
       {   UINT16_C(    13170),  UINT16_C(     8819),  UINT16_C(    18220),  UINT16_C(    11123) },
           INT8_C(        3),
       {   UINT32_C(136472598),  UINT32_C(220717960),  UINT32_C( 14424261),  UINT32_C( 91305244) } },
     { {   UINT32_C(    73397),  UINT32_C(   105926),  UINT32_C(   843999),  UINT32_C(     3264) },
       {   UINT16_C(    12288),  UINT16_C(     5295),  UINT16_C(    18343),  UINT16_C(     3415),
           UINT16_C(    11416),  UINT16_C(    12486),  UINT16_C(    17062),  UINT16_C(     9676) },
       {   UINT16_C(    13059),  UINT16_C(     3087),  UINT16_C(    11677),  UINT16_C(     4325) },
           INT8_C(        0),
       {   UINT32_C(149154941),  UINT32_C(163160600),  UINT32_C(223656657),  UINT32_C(126362148) } },
     { {   UINT32_C(   734791),  UINT32_C(  1657848),  UINT32_C(   424852),  UINT32_C(  1242994) },
       {   UINT16_C(    11986),  UINT16_C(     7890),  UINT16_C(    14401),  UINT16_C(    18381),
           UINT16_C(    17965),  UINT16_C(    16613),  UINT16_C(     2409),  UINT16_C(    18508) },
       {   UINT16_C(    13721),  UINT16_C(    11302),  UINT16_C(     3779),  UINT16_C(    13766) },
           INT8_C(        2),
       {   UINT32_C( 68624526),  UINT32_C( 64438375),  UINT32_C(  9528463),  UINT32_C( 71184726) } },
     { {   UINT32_C(  1456657),  UINT32_C(   713432),  UINT32_C(  1448872),  UINT32_C(   475639) },
       {   UINT16_C(     1136),  UINT16_C(     5844),  UINT16_C(     2586),  UINT16_C(     3257),
           UINT16_C(     5857),  UINT16_C(     5330),  UINT16_C(     5152),  UINT16_C(    14123) },
       {   UINT16_C(     8401),  UINT16_C(    18368),  UINT16_C(     1802),  UINT16_C(     6512) },
           INT8_C(        2),
       {   UINT32_C( 12010971),  UINT32_C( 10318092),  UINT32_C( 10732776),  UINT32_C( 25925285) } },
     { {   UINT32_C(  1924275),  UINT32_C(   868137),  UINT32_C(   856472),  UINT32_C(   331562) },
       {   UINT16_C(     4671),  UINT16_C(      343),  UINT16_C(    17990),  UINT16_C(     5319),
           UINT16_C(    17163),  UINT16_C(     2321),  UINT16_C(     1233),  UINT16_C(    11827) },
       {   UINT16_C(    15272),  UINT16_C(    16570),  UINT16_C(    13202),  UINT16_C(    13685) },
           INT8_C(        2),
       {   UINT32_C(228510201),  UINT32_C( 31509979),  UINT32_C( 17134538),  UINT32_C(156471616) } },
     { {   UINT32_C(  1268606),  UINT32_C(  1863775),  UINT32_C(   284716),  UINT32_C(  1590387) },
       {   UINT16_C(    18463),  UINT16_C(    16489),  UINT16_C(     7049),  UINT16_C(    11593),
           UINT16_C(    18659),  UINT16_C(     5537),  UINT16_C(    16458),  UINT16_C(    16115) },
       {   UINT16_C(    18417),  UINT16_C(     9423),  UINT16_C(     8975),  UINT16_C(     2463) },
           INT8_C(        3),
       {   UINT32_C( 47225723),  UINT32_C( 15501406),  UINT32_C( 40820770),  UINT32_C( 41281632) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x4_t v = simde_vld1_u16(test_vec[i].v);
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmlal_high_lane_u16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlal_high_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint32_t v[4];
    int8_t lane;
    uint64_t r[2];
  } test_vec[] = {
     { {   UINT64_C(    581865556),  UINT64_C(   1961421217) },
       {   UINT32_C(       587948),  UINT32_C(       928289),  UINT32_C(      1193217),  UINT32_C(        66551) },
       {   UINT32_C(      1943855),  UINT32_C(      1254342),  UINT32_C(      1608561),  UINT32_C(       818907) },
           INT8_C(            0),
       {   UINT64_C(2320022697091),  UINT64_C( 131326915322) } },
     { {   UINT64_C(     23584783),  UINT64_C(    646857139) },
       {   UINT32_C(      1821357),  UINT32_C(      1994247),  UINT32_C(      1905983),  UINT32_C(      1972490) },
       {   UINT32_C(       279410),  UINT32_C(       982246),  UINT32_C(       408226),  UINT32_C(       899202) },
           INT8_C(            0),
       {   UINT64_C( 532574294813),  UINT64_C( 551780288039) } },
     { {   UINT64_C(   1695604807),  UINT64_C(   1426639515) },
       {   UINT32_C(          731),  UINT32_C(      1180120),  UINT32_C(       247965),  UINT32_C(      1134152) },
       {   UINT32_C(      1495374),  UINT32_C(      1527916),  UINT32_C(      1647922),  UINT32_C(      1898499) },
           INT8_C(            3),
       {   UINT64_C( 472456909342),  UINT64_C(2154613077363) } },
     { {   UINT64_C(    275591214),  UINT64_C(    291318976) },
       {   UINT32_C(       597721),  UINT32_C(      1044352),  UINT32_C(       385596),  UINT32_C(       373887) },
       {   UINT32_C(      1046650),  UINT32_C(      1848883),  UINT32_C(      1370487),  UINT32_C(      1319755) },
           INT8_C(            0),
       {   UINT64_C( 403859644614),  UINT64_C( 391620147526) } },
     { {   UINT64_C(   1078618217),  UINT64_C(   1418666301) },
       {   UINT32_C(       622684),  UINT32_C(      1794624),  UINT32_C(        40910),  UINT32_C(      1531594) },
       {   UINT32_C(      1362106),  UINT32_C(      1543402),  UINT32_C(       576586),  UINT32_C(       122961) },
           INT8_C(            2),
       {   UINT64_C(  24666751477),  UINT64_C( 884514324385) } },
     { {   UINT64_C(   1059991594),  UINT64_C(   1685059887) },
       {   UINT32_C(      1654297),  UINT32_C(       675528),  UINT32_C(       874539),  UINT32_C(      1639672) },
       {   UINT32_C(       991106),  UINT32_C(       823282),  UINT32_C(      1390309),  UINT32_C(      1057691) },
           INT8_C(            2),
       {   UINT64_C(1216939434145),  UINT64_C(2281335798535) } },
     { {   UINT64_C(      2400707),  UINT64_C(   1301244679) },
       {   UINT32_C(       559021),  UINT32_C(      1672652),  UINT32_C(      1227845),  UINT32_C(      1237646) },
       {   UINT32_C(       412574),  UINT32_C(      1580173),  UINT32_C(      1347008),  UINT32_C(       790812) },
           INT8_C(            2),
       {   UINT64_C(1653919438467),  UINT64_C(1668420307847) } },
     { {   UINT64_C(   1312259781),  UINT64_C(   1662531619) },
       {   UINT32_C(       377502),  UINT32_C(      1774224),  UINT32_C(      1399533),  UINT32_C(      1819326) },
       {   UINT32_C(       968072),  UINT32_C(      1555748),  UINT32_C(      1537622),  UINT32_C(       611277) },
           INT8_C(            0),
       {   UINT64_C(1356160970157),  UINT64_C(1762901091091) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t v = simde_vld1q_u32(test_vec[i].v);
    simde_uint64x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmlal_high_laneq_u32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlal_high_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint32_t v[2];
    int8_t lane;
    uint64_t r[2];
  } test_vec[] = {
     { {   UINT64_C(   1428131384),  UINT64_C(   1941064234) },
       {   UINT32_C(      1491368),  UINT32_C(       680507),  UINT32_C(      1340293),  UINT32_C(      1164242) },
       {   UINT32_C(      1520576),  UINT32_C(       561467) },
           INT8_C(            1),
       {   UINT64_C( 753958421215),  UINT64_C( 655624527248) } },
     { {   UINT64_C(   1434849562),  UINT64_C(    902513617) },
       {   UINT32_C(       742665),  UINT32_C(      1763018),  UINT32_C(      1692445),  UINT32_C(       194431) },
       {   UINT32_C(      1598735),  UINT32_C(      1196324) },
           INT8_C(            1),
       {   UINT64_C(2026147421742),  UINT64_C( 233504985261) } },
     { {   UINT64_C(     55247748),  UINT64_C(   1266733675) },
       {   UINT32_C(       290891),  UINT32_C(      1869978),  UINT32_C(       984496),  UINT32_C(       795253) },
       {   UINT32_C(       416879),  UINT32_C(      1132903) },
           INT8_C(            0),
       {   UINT64_C( 410470955732),  UINT64_C( 332791009062) } },
     { {   UINT64_C(   1195519168),  UINT64_C(   1592682824) },
       {   UINT32_C(        10452),  UINT32_C(       478545),  UINT32_C(      1870027),  UINT32_C(      1825678) },
       {   UINT32_C(      1188188),  UINT32_C(      1700521) },
           INT8_C(            0),
       {   UINT64_C(2223139160244),  UINT64_C(2170841374288) } },
     { {   UINT64_C(    272189059),  UINT64_C(    312207824) },
       {   UINT32_C(      1162028),  UINT32_C(       878095),  UINT32_C(      1078069),  UINT32_C(      1970971) },
       {   UINT32_C(       199568),  UINT32_C(       365021) },
           INT8_C(            0),
       {   UINT64_C( 215420263251),  UINT64_C( 393654948352) } },
     { {   UINT64_C(   1025265761),  UINT64_C(   1590405508) },
       {   UINT32_C(      1314714),  UINT32_C(       569364),  UINT32_C(       579195),  UINT32_C(      1097124) },
       {   UINT32_C(      1944630),  UINT32_C(       579203) },
           INT8_C(            1),
       {   UINT64_C( 336496747346),  UINT64_C( 637047917680) } },
     { {   UINT64_C(    125528816),  UINT64_C(   1105835591) },
       {   UINT32_C(      1547539),  UINT32_C(       534056),  UINT32_C(       671409),  UINT32_C(      1718709) },
       {   UINT32_C(      1330530),  UINT32_C(        24974) },
           INT8_C(            0),
       {   UINT64_C( 893455345586),  UINT64_C(2287899721361) } },
     { {   UINT64_C(   1637747186),  UINT64_C(   1003847865) },
       {   UINT32_C(        18831),  UINT32_C(       781780),  UINT32_C(      1837816),  UINT32_C(      1298414) },
       {   UINT32_C(      1991192),  UINT32_C(        33878) },
           INT8_C(            0),
       {   UINT64_C(3661082263858),  UINT64_C(2586395417353) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x2_t v = simde_vld1_u32(test_vec[i].v);
    simde_uint64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmlal_high_lane_u32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_laneq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
