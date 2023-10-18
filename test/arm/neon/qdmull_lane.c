#define SIMDE_TEST_ARM_NEON_INSN qdmull_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmull_lane.h"

static int
test_simde_vqdmullh_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[1];
    int16_t v[4];
    int32_t r0[1];
    int32_t r1[1];
    int32_t r2[1];
    int32_t r3[1];
  } test_vec[] = {
    { {   INT16_C( 5511) },
      {  -INT16_C( 1872), -INT16_C( 3187),  INT16_C( 9351),  INT16_C( 5112) },
      {  -INT32_C(  20633184),  },
      {  -INT32_C(  35127114),  },
      {   INT32_C( 103066722),  },
      {   INT32_C(  56344464),  } },
    { {   INT16_C( 3072) },
      {   INT16_C( 3954), -INT16_C( 1030), -INT16_C( 9771),  INT16_C( 3670) },
      {   INT32_C(  24293376),  },
      {  -INT32_C(   6328320),  },
      {  -INT32_C(  60033024),  },
      {   INT32_C(  22548480),  } },
    { {  -INT16_C( 4970) },
      {   INT16_C( 4371),  INT16_C(  532),  INT16_C( 4769), -INT16_C( 6774) },
      {  -INT32_C(  43447740),  },
      {  -INT32_C(   5288080),  },
      {  -INT32_C(  47403860),  },
      {   INT32_C(  67333560),  } },
    { {  -INT16_C( 7124) },
      {   INT16_C( 6609), -INT16_C( 8752),  INT16_C(   44),  INT16_C( 1460) },
      {  -INT32_C(  94165032),  },
      {   INT32_C( 124698496),  },
      {  -INT32_C(    626912),  },
      {  -INT32_C(  20802080),  } },
    { {   INT16_C( 6847) },
      {   INT16_C( 1195),  INT16_C( 6886),  INT16_C( 1817),  INT16_C( 2853) },
      {   INT32_C(  16364330),  },
      {   INT32_C(  94296884),  },
      {   INT32_C(  24881998),  },
      {   INT32_C(  39068982),  } },
    { {   INT16_C( 3195) },
      {   INT16_C( 9325),  INT16_C( 6282),  INT16_C(  466),  INT16_C( 7828) },
      {   INT32_C(  59586750),  },
      {   INT32_C(  40141980),  },
      {   INT32_C(   2977740),  },
      {   INT32_C(  50020920),  } },
    { {  -INT16_C( 2439) },
      {  -INT16_C( 9637), -INT16_C( 1244),  INT16_C( 4196),  INT16_C( 1735) },
      {   INT32_C(  47009286),  },
      {   INT32_C(   6068232),  },
      {  -INT32_C(  20468088),  },
      {  -INT32_C(   8463330),  } },
    { {   INT16_C( 8832) },
      {   INT16_C( 8903),  INT16_C( 3035), -INT16_C( 5601), -INT16_C( 3161) },
      {   INT32_C( 157262592),  },
      {   INT32_C(  53610240),  },
      {  -INT32_C(  98936064),  },
      {  -INT32_C(  55835904),  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a[0];
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    int32_t r0 = simde_vqdmullh_lane_s16(a, v, 0);
    int32_t r1 = simde_vqdmullh_lane_s16(a, v, 1);
    int32_t r2 = simde_vqdmullh_lane_s16(a, v, 2);
    int32_t r3 = simde_vqdmullh_lane_s16(a, v, 3);

    simde_assert_equal_i32(r0, test_vec[i].r0[0]);
    simde_assert_equal_i32(r1, test_vec[i].r1[0]);
    simde_assert_equal_i32(r2, test_vec[i].r2[0]);
    simde_assert_equal_i32(r3, test_vec[i].r3[0]);
  }

  return 0;
}

static int
test_simde_vqdmullh_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[1];
    int16_t v[8];
    int32_t r0[1];
    int32_t r1[1];
    int32_t r2[1];
    int32_t r3[1];
    int32_t r4[1];
    int32_t r5[1];
    int32_t r6[1];
    int32_t r7[1];
  } test_vec[] = {
    { {   INT16_C(  376) },
      {  -INT16_C( 9742),  INT16_C( 8640), -INT16_C( 6706),  INT16_C( 6606),
          INT16_C( 2187), -INT16_C( 2059), -INT16_C( 8275), -INT16_C( 4697) },
      {  -INT32_C(   7325984),  },
      {   INT32_C(   6497280),  },
      {  -INT32_C(   5042912),  },
      {   INT32_C(   4967712),  },
      {   INT32_C(   1644624),  },
      {  -INT32_C(   1548368),  },
      {  -INT32_C(   6222800),  },
      {  -INT32_C(   3532144),  } },
    { {   INT16_C( 4604) },
      {   INT16_C( 3066), -INT16_C( 4532),  INT16_C( 6258),  INT16_C( 8484),
          INT16_C( 5421),  INT16_C( 5549),  INT16_C(  698),  INT16_C( 3341) },
      {   INT32_C(  28231728),  },
      {  -INT32_C(  41730656),  },
      {   INT32_C(  57623664),  },
      {   INT32_C(  78120672),  },
      {   INT32_C(  49916568),  },
      {   INT32_C(  51095192),  },
      {   INT32_C(   6427184),  },
      {   INT32_C(  30763928),  } },
    { {  -INT16_C( 3221) },
      {  -INT16_C(  849), -INT16_C( 3336),  INT16_C( 8568),  INT16_C( 9920),
         -INT16_C( 6161),  INT16_C( 3431), -INT16_C( 5355),  INT16_C(  155) },
      {   INT32_C(   5469258),  },
      {   INT32_C(  21490512),  },
      {  -INT32_C(  55195056),  },
      {  -INT32_C(  63904640),  },
      {   INT32_C(  39689162),  },
      {  -INT32_C(  22102502),  },
      {   INT32_C(  34496910),  },
      {  -INT32_C(    998510),  } },
    { {  -INT16_C( 8783) },
      {  -INT16_C( 8915),  INT16_C( 1873), -INT16_C( 2862), -INT16_C( 6808),
          INT16_C( 6765), -INT16_C( 5486),  INT16_C( 4240),  INT16_C( 6859) },
      {   INT32_C( 156600890),  },
      {  -INT32_C(  32901118),  },
      {   INT32_C(  50273892),  },
      {   INT32_C( 119589328),  },
      {  -INT32_C( 118833990),  },
      {   INT32_C(  96367076),  },
      {  -INT32_C(  74479840),  },
      {  -INT32_C( 120485194),  } },
    { {   INT16_C(  891) },
      {   INT16_C( 8790),  INT16_C(  725),  INT16_C( 1233),  INT16_C( 9529),
         -INT16_C( 4616), -INT16_C( 4963),  INT16_C(  449), -INT16_C( 3328) },
      {   INT32_C(  15663780),  },
      {   INT32_C(   1291950),  },
      {   INT32_C(   2197206),  },
      {   INT32_C(  16980678),  },
      {  -INT32_C(   8225712),  },
      {  -INT32_C(   8844066),  },
      {   INT32_C(    800118),  },
      {  -INT32_C(   5930496),  } },
    { {  -INT16_C( 5783) },
      {  -INT16_C( 5468),  INT16_C( 6792),  INT16_C( 7131), -INT16_C( 3247),
          INT16_C( 7838), -INT16_C( 4352),  INT16_C( 7266), -INT16_C( 8449) },
      {   INT32_C(  63242888),  },
      {  -INT32_C(  78556272),  },
      {  -INT32_C(  82477146),  },
      {   INT32_C(  37554802),  },
      {  -INT32_C(  90654308),  },
      {   INT32_C(  50335232),  },
      {  -INT32_C(  84038556),  },
      {   INT32_C(  97721134),  } },
    { {   INT16_C( 5603) },
      {  -INT16_C( 5528), -INT16_C( 1564),  INT16_C( 4479), -INT16_C( 3106),
         -INT16_C( 7568),  INT16_C( 1209), -INT16_C( 4439),  INT16_C( 7278) },
      {  -INT32_C(  61946768),  },
      {  -INT32_C(  17526184),  },
      {   INT32_C(  50191674),  },
      {  -INT32_C(  34805836),  },
      {  -INT32_C(  84807008),  },
      {   INT32_C(  13548054),  },
      {  -INT32_C(  49743434),  },
      {   INT32_C(  81557268),  } },
    { {  -INT16_C( 2020) },
      {  -INT16_C( 1475),  INT16_C( 7978),  INT16_C( 9778), -INT16_C( 9731),
          INT16_C( 5122),  INT16_C(  669), -INT16_C( 1949),  INT16_C( 7057) },
      {   INT32_C(   5959000),  },
      {  -INT32_C(  32231120),  },
      {  -INT32_C(  39503120),  },
      {   INT32_C(  39313240),  },
      {  -INT32_C(  20692880),  },
      {  -INT32_C(   2702760),  },
      {   INT32_C(   7873960),  },
      {  -INT32_C(  28510280),  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a[0];
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    int32_t r0 = simde_vqdmullh_laneq_s16(a, v, 0);
    int32_t r1 = simde_vqdmullh_laneq_s16(a, v, 1);
    int32_t r2 = simde_vqdmullh_laneq_s16(a, v, 2);
    int32_t r3 = simde_vqdmullh_laneq_s16(a, v, 3);
    int32_t r4 = simde_vqdmullh_laneq_s16(a, v, 4);
    int32_t r5 = simde_vqdmullh_laneq_s16(a, v, 5);
    int32_t r6 = simde_vqdmullh_laneq_s16(a, v, 6);
    int32_t r7 = simde_vqdmullh_laneq_s16(a, v, 7);

    simde_assert_equal_i32(r0, test_vec[i].r0[0]);
    simde_assert_equal_i32(r1, test_vec[i].r1[0]);
    simde_assert_equal_i32(r2, test_vec[i].r2[0]);
    simde_assert_equal_i32(r3, test_vec[i].r3[0]);
    simde_assert_equal_i32(r4, test_vec[i].r4[0]);
    simde_assert_equal_i32(r5, test_vec[i].r5[0]);
    simde_assert_equal_i32(r6, test_vec[i].r6[0]);
    simde_assert_equal_i32(r7, test_vec[i].r7[0]);
  }

  return 0;
}

static int
test_simde_vqdmulls_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[1];
    int32_t v[2];
    int64_t r0[1];
    int64_t r1[1];
  } test_vec[] = {
    { {   INT32_C( 634418) },
      {   INT32_C( 173921), -INT32_C(  71264) },
      {   INT64_C(  220677225956),  },
      {  -INT64_C(   90422328704),  } },
    { {  -INT32_C( 320139) },
      {  -INT32_C( 651577),  INT32_C(  56580) },
      {   INT64_C(  417190418406),  },
      {  -INT64_C(   36226929240),  } },
    { {   INT32_C( 847605) },
      {  -INT32_C( 250775),  INT32_C( 839913) },
      {  -INT64_C(  425116287750),  },
      {   INT64_C( 1423828916730),  } },
    { {   INT32_C( 958733) },
      {   INT32_C( 723071), -INT32_C( 872660) },
      {   INT64_C( 1386464058086),  },
      {  -INT64_C( 1673295879560),  } },
    { {  -INT32_C( 965204) },
      {  -INT32_C(  86642), -INT32_C( 329177) },
      {   INT64_C(  167254409936),  },
      {   INT64_C(  635445914216),  } },
    { {  -INT32_C( 946659) },
      {  -INT32_C(  92694),  INT32_C(  47468) },
      {   INT64_C(  175499218692),  },
      {  -INT64_C(   89872018824),  } },
    { {   INT32_C( 127025) },
      {   INT32_C( 290758),  INT32_C( 248889) },
      {   INT64_C(   73867069900),  },
      {   INT64_C(   63230250450),  } },
    { {   INT32_C( 718100) },
      {   INT32_C( 644267),  INT32_C( 216043) },
      {   INT64_C(  925296265400),  },
      {   INT64_C(  310280956600),  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a[0];
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    int64_t r0 = simde_vqdmulls_lane_s32(a, v, 0);
    int64_t r1 = simde_vqdmulls_lane_s32(a, v, 1);

    simde_assert_equal_i64(r0, test_vec[i].r0[0]);
    simde_assert_equal_i64(r1, test_vec[i].r1[0]);
  }

  return 0;
}

static int
test_simde_vqdmulls_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[1];
    int32_t v[4];
    int64_t r0[1];
    int64_t r1[1];
    int64_t r2[1];
    int64_t r3[1];
  } test_vec[] = {
    { {  -INT32_C( 659075) },
      {  -INT32_C( 730909), -INT32_C( 561211),  INT32_C( 160323), -INT32_C( 512210) },
      {   INT64_C(  963447698350),  },
      {   INT64_C(  739760279650),  },
      {  -INT64_C(  211329762450),  },
      {   INT64_C(  675169611500),  } },
    { {   INT32_C( 204549) },
      {   INT32_C( 689474),  INT32_C( 474503),  INT32_C( 297546), -INT32_C( 478235) },
      {   INT64_C(  282062434452),  },
      {   INT64_C(  194118228294),  },
      {   INT64_C(  121725473508),  },
      {  -INT64_C(  195644982030),  } },
    { {   INT32_C( 417996) },
      {  -INT32_C( 767918),  INT32_C( 493932),  INT32_C( 433526), -INT32_C( 400079) },
      {  -INT64_C(  641973304656),  },
      {   INT64_C(  412923200544),  },
      {   INT64_C(  362424267792),  },
      {  -INT64_C(  334462843368),  } },
    { {   INT32_C(  49844) },
      {   INT32_C( 345692),  INT32_C( 362725),  INT32_C( 925044),  INT32_C( 822684) },
      {   INT64_C(   34461344096),  },
      {   INT64_C(   36159329800),  },
      {   INT64_C(   92215786272),  },
      {   INT64_C(   82011722592),  } },
    { {   INT32_C(   9571) },
      {  -INT32_C( 573965), -INT32_C( 304784), -INT32_C( 114966),  INT32_C( 287780) },
      {  -INT64_C(   10986838030),  },
      {  -INT64_C(    5834175328),  },
      {  -INT64_C(    2200679172),  },
      {   INT64_C(    5508684760),  } },
    { {   INT32_C( 569493) },
      {   INT32_C( 879727), -INT32_C( 968515),  INT32_C( 536749), -INT32_C( 476337) },
      {   INT64_C( 1001996736822),  },
      {  -INT64_C( 1103125025790),  },
      {   INT64_C(  611349596514),  },
      {  -INT64_C(  542541174282),  } },
    { {  -INT32_C( 407646) },
      {  -INT32_C( 528658), -INT32_C( 336851), -INT32_C( 658175),  INT32_C( 568552) },
      {   INT64_C(  431010638136),  },
      {   INT64_C(  274631925492),  },
      {   INT64_C(  536604812100),  },
      {  -INT64_C(  463535897184),  } },
    { {  -INT32_C( 639673) },
      {   INT32_C( 742826), -INT32_C( 190632),  INT32_C( 938444),  INT32_C( 921723) },
      {  -INT64_C(  950331471796),  },
      {   INT64_C(  243884286672),  },
      {  -INT64_C( 1200594577624),  },
      {  -INT64_C( 1179202633158),  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a[0];
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    int64_t r0 = simde_vqdmulls_laneq_s32(a, v, 0);
    int64_t r1 = simde_vqdmulls_laneq_s32(a, v, 1);
    int64_t r2 = simde_vqdmulls_laneq_s32(a, v, 2);
    int64_t r3 = simde_vqdmulls_laneq_s32(a, v, 3);

    simde_assert_equal_i64(r0, test_vec[i].r0[0]);
    simde_assert_equal_i64(r1, test_vec[i].r1[0]);
    simde_assert_equal_i64(r2, test_vec[i].r2[0]);
    simde_assert_equal_i64(r3, test_vec[i].r3[0]);
  }

  return 0;
}

static int
test_simde_vqdmull_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    int16_t v[4];
    int32_t r0[4];
    int32_t r1[4];
    int32_t r2[4];
    int32_t r3[4];
  } test_vec[] = {
     { {  -INT16_C(          2243),  INT16_C(           573), -INT16_C(          7559),  INT16_C(          5666) },
       {  -INT16_C(          1598), -INT16_C(          7039),  INT16_C(          3906), -INT16_C(          7938) },
       {   INT32_C(       7168628), -INT32_C(       1831308),  INT32_C(      24158564), -INT32_C(      18108536) },
       {   INT32_C(      31576954), -INT32_C(       8066694),  INT32_C(     106415602), -INT32_C(      79765948) },
       {  -INT32_C(      17522316),  INT32_C(       4476276), -INT32_C(      59050908),  INT32_C(      44262792) },
       {   INT32_C(      35609868), -INT32_C(       9096948),  INT32_C(     120006684), -INT32_C(      89953416) } },
     { {  -INT16_C(           846),  INT16_C(          6064),  INT16_C(          4978), -INT16_C(          3986) },
       {   INT16_C(          1442), -INT16_C(          6294), -INT16_C(          3742), -INT16_C(          9786) },
       {  -INT32_C(       2439864),  INT32_C(      17488576),  INT32_C(      14356552), -INT32_C(      11495624) },
       {   INT32_C(      10649448), -INT32_C(      76333632), -INT32_C(      62663064),  INT32_C(      50175768) },
       {   INT32_C(       6331464), -INT32_C(      45382976), -INT32_C(      37255352),  INT32_C(      29831224) },
       {   INT32_C(      16557912), -INT32_C(     118684608), -INT32_C(      97429416),  INT32_C(      78013992) } },
     { {  -INT16_C(          7513),  INT16_C(          4446), -INT16_C(          6868),  INT16_C(          9130) },
       {   INT16_C(          2731), -INT16_C(          6525), -INT16_C(          9595), -INT16_C(          8643) },
       {  -INT32_C(      41036006),  INT32_C(      24284052), -INT32_C(      37513016),  INT32_C(      49868060) },
       {   INT32_C(      98044650), -INT32_C(      58020300),  INT32_C(      89627400), -INT32_C(     119146500) },
       {   INT32_C(     144174470), -INT32_C(      85318740),  INT32_C(     131796920), -INT32_C(     175204700) },
       {   INT32_C(     129869718), -INT32_C(      76853556),  INT32_C(     118720248), -INT32_C(     157821180) } },
     { {  -INT16_C(          7578),  INT16_C(          6097), -INT16_C(          4022),  INT16_C(          1187) },
       {   INT16_C(          2209),  INT16_C(           801), -INT16_C(          1382),  INT16_C(          2762) },
       {  -INT32_C(      33479604),  INT32_C(      26936546), -INT32_C(      17769196),  INT32_C(       5244166) },
       {  -INT32_C(      12139956),  INT32_C(       9767394), -INT32_C(       6443244),  INT32_C(       1901574) },
       {   INT32_C(      20945592), -INT32_C(      16852108),  INT32_C(      11116808), -INT32_C(       3280868) },
       {  -INT32_C(      41860872),  INT32_C(      33679828), -INT32_C(      22217528),  INT32_C(       6556988) } },
     { {  -INT16_C(          4146),  INT16_C(          5467), -INT16_C(          8224),  INT16_C(          5701) },
       {  -INT16_C(          2048), -INT16_C(          8137),  INT16_C(          6699), -INT16_C(          7780) },
       {   INT32_C(      16982016), -INT32_C(      22392832),  INT32_C(      33685504), -INT32_C(      23351296) },
       {   INT32_C(      67472004), -INT32_C(      88969958),  INT32_C(     133837376), -INT32_C(      92778074) },
       {  -INT32_C(      55548108),  INT32_C(      73246866), -INT32_C(     110185152),  INT32_C(      76381998) },
       {   INT32_C(      64511760), -INT32_C(      85066520),  INT32_C(     127965440), -INT32_C(      88707560) } },
     { {  -INT16_C(          4260), -INT16_C(          4816),  INT16_C(          9532),  INT16_C(          2495) },
       {   INT16_C(          3361),  INT16_C(          5063),  INT16_C(          1754), -INT16_C(          9626) },
       {  -INT32_C(      28635720), -INT32_C(      32373152),  INT32_C(      64074104),  INT32_C(      16771390) },
       {  -INT32_C(      43136760), -INT32_C(      48766816),  INT32_C(      96521032),  INT32_C(      25264370) },
       {  -INT32_C(      14944080), -INT32_C(      16894528),  INT32_C(      33438256),  INT32_C(       8752460) },
       {   INT32_C(      82013520),  INT32_C(      92717632), -INT32_C(     183510064), -INT32_C(      48033740) } },
     { {  -INT16_C(          2019),  INT16_C(          5182), -INT16_C(          8599), -INT16_C(          1275) },
       {  -INT16_C(          3364),  INT16_C(          6609), -INT16_C(          3140), -INT16_C(          6139) },
       {   INT32_C(      13583832), -INT32_C(      34864496),  INT32_C(      57854072),  INT32_C(       8578200) },
       {  -INT32_C(      26687142),  INT32_C(      68495676), -INT32_C(     113661582), -INT32_C(      16852950) },
       {   INT32_C(      12679320), -INT32_C(      32542960),  INT32_C(      54001720),  INT32_C(       8007000) },
       {   INT32_C(      24789282), -INT32_C(      63624596),  INT32_C(     105578522),  INT32_C(      15654450) } },
     { {   INT16_C(          3840),  INT16_C(          1242),  INT16_C(          2755),  INT16_C(          8053) },
       {  -INT16_C(          2358), -INT16_C(          3412), -INT16_C(           545),  INT16_C(          7951) },
       {  -INT32_C(      18109440), -INT32_C(       5857272), -INT32_C(      12992580), -INT32_C(      37977948) },
       {  -INT32_C(      26204160), -INT32_C(       8475408), -INT32_C(      18800120), -INT32_C(      54953672) },
       {  -INT32_C(       4185600), -INT32_C(       1353780), -INT32_C(       3002950), -INT32_C(       8777770) },
       {   INT32_C(      61063680),  INT32_C(      19750284),  INT32_C(      43810010),  INT32_C(     128058806) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int32x4_t r0 = simde_vqdmull_lane_s16(a, v, 0);
    simde_int32x4_t r1 = simde_vqdmull_lane_s16(a, v, 1);
    simde_int32x4_t r2 = simde_vqdmull_lane_s16(a, v, 2);
    simde_int32x4_t r3 = simde_vqdmull_lane_s16(a, v, 3);

    simde_test_arm_neon_assert_equal_i32x4(r0, simde_vld1q_s32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i32x4(r1, simde_vld1q_s32(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i32x4(r2, simde_vld1q_s32(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_i32x4(r3, simde_vld1q_s32(test_vec[i].r3));
  }

  return 0;
}

static int
test_simde_vqdmull_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t v[2];
    int64_t r0[2];
    int64_t r1[2];
  } test_vec[] = {
     { {  -INT32_C(         9551495), -INT32_C(         4244894) },
       {   INT32_C(         9500016), -INT32_C(         4578713) },
       {  -INT64_C( 181478710647840), -INT64_C(  80653121836608) },
       {   INT64_C(  87467108651870),  INT64_C(  38872302682844) } },
     { {   INT32_C(          624903), -INT32_C(         7769809) },
       {   INT32_C(         8772996), -INT32_C(         1316132) },
       {   INT64_C(  10964543038776), -INT64_C( 136329006555528) },
       {  -INT64_C(   1644909670392),  INT64_C(  20452188517576) } },
     { {   INT32_C(         3990539),  INT32_C(         8360746) },
       {   INT32_C(         3739031),  INT32_C(          186790) },
       {   INT64_C(  29841498055418),  INT64_C(  62522176954252) },
       {   INT64_C(   1490785559620),  INT64_C(   3123407490680) } },
     { {   INT32_C(         4527060),  INT32_C(         1305553) },
       {  -INT32_C(         9235343),  INT32_C(         4280947) },
       {  -INT64_C(  83617903763160), -INT64_C(  24114459519358) },
       {   INT64_C(  38760207851640),  INT64_C(  11178006397382) } },
     { {   INT32_C(         2233801),  INT32_C(         2119374) },
       {  -INT32_C(         5830491),  INT32_C(         5886598) },
       {  -INT64_C(  26048313252582), -INT64_C(  24713982065268) },
       {   INT64_C(  26298976997996),  INT64_C(  24951805499304) } },
     { {   INT32_C(         6369766), -INT32_C(         5994389) },
       {  -INT32_C(          581627),  INT32_C(          174889) },
       {  -INT64_C(   7409655778564),  INT64_C(   6972996981806) },
       {   INT64_C(   2228004011948), -INT64_C(   2096705395642) } },
     { {   INT32_C(         4529939),  INT32_C(         8107248) },
       {  -INT32_C(         8279077),  INT32_C(         2553033) },
       {  -INT64_C(  75007427572606), -INT64_C( 134241060900192) },
       {   INT64_C(  23130167509974),  INT64_C(  41396143366368) } },
     { {   INT32_C(         2201602),  INT32_C(         5722167) },
       {  -INT32_C(         4665805),  INT32_C(         4267400) },
       {  -INT64_C(  20544491239220), -INT64_C(  53397030798870) },
       {   INT64_C(  18790232749600),  INT64_C(  48837550911600) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int64x2_t r0 = simde_vqdmull_lane_s32(a, v, 0);
    simde_int64x2_t r1 = simde_vqdmull_lane_s32(a, v, 1);

    simde_test_arm_neon_assert_equal_i64x2(r0, simde_vld1q_s64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i64x2(r1, simde_vld1q_s64(test_vec[i].r1));
  }

  return 0;
}

static int
test_simde_vqdmull_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    int16_t v[8];
    int32_t r0[4];
    int32_t r1[4];
    int32_t r2[4];
    int32_t r3[4];
    int32_t r4[4];
    int32_t r5[4];
    int32_t r6[4];
    int32_t r7[4];
  } test_vec[] = {
     { {  -INT16_C(          2296), -INT16_C(          9611), -INT16_C(          2943), -INT16_C(          2915) },
       {  -INT16_C(           837),  INT16_C(          4146), -INT16_C(          3620), -INT16_C(          7916),
          -INT16_C(          1608), -INT16_C(          1765), -INT16_C(          8137),  INT16_C(          1464) },
       {   INT32_C(       3843504),  INT32_C(      16088814),  INT32_C(       4926582),  INT32_C(       4879710) },
       {  -INT32_C(      19038432), -INT32_C(      79694412), -INT32_C(      24403356), -INT32_C(      24171180) },
       {   INT32_C(      16623040),  INT32_C(      69583640),  INT32_C(      21307320),  INT32_C(      21104600) },
       {   INT32_C(      36350272),  INT32_C(     152161352),  INT32_C(      46593576),  INT32_C(      46150280) },
       {   INT32_C(       7383936),  INT32_C(      30908976),  INT32_C(       9464688),  INT32_C(       9374640) },
       {   INT32_C(       8104880),  INT32_C(      33926830),  INT32_C(      10388790),  INT32_C(      10289950) },
       {   INT32_C(      37365104),  INT32_C(     156409414),  INT32_C(      47894382),  INT32_C(      47438710) },
       {  -INT32_C(       6722688), -INT32_C(      28141008), -INT32_C(       8617104), -INT32_C(       8535120) } },
     { {   INT16_C(          9591), -INT16_C(          4056),  INT16_C(          7820), -INT16_C(          4853) },
       {  -INT16_C(          8747), -INT16_C(           785),  INT16_C(          4014),  INT16_C(          3743),
          -INT16_C(          8890),  INT16_C(          4960), -INT16_C(          3299),  INT16_C(          2926) },
       {  -INT32_C(     167784954),  INT32_C(      70955664), -INT32_C(     136803080),  INT32_C(      84898382) },
       {  -INT32_C(      15057870),  INT32_C(       6367920), -INT32_C(      12277400),  INT32_C(       7619210) },
       {   INT32_C(      76996548), -INT32_C(      32561568),  INT32_C(      62778960), -INT32_C(      38959884) },
       {   INT32_C(      71798226), -INT32_C(      30363216),  INT32_C(      58540520), -INT32_C(      36329558) },
       {  -INT32_C(     170527980),  INT32_C(      72115680), -INT32_C(     139039600),  INT32_C(      86286340) },
       {   INT32_C(      95142720), -INT32_C(      40235520),  INT32_C(      77574400), -INT32_C(      48141760) },
       {  -INT32_C(      63281418),  INT32_C(      26761488), -INT32_C(      51596360),  INT32_C(      32020094) },
       {   INT32_C(      56126532), -INT32_C(      23735712),  INT32_C(      45762640), -INT32_C(      28399756) } },
     { {   INT16_C(          7691),  INT16_C(          6951), -INT16_C(          9747),  INT16_C(          1914) },
       {  -INT16_C(          5178), -INT16_C(          2026),  INT16_C(          9524),  INT16_C(          1021),
           INT16_C(          7259),  INT16_C(          3467),  INT16_C(          3264), -INT16_C(          3978) },
       {  -INT32_C(      79647996), -INT32_C(      71984556),  INT32_C(     100939932), -INT32_C(      19821384) },
       {  -INT32_C(      31163932), -INT32_C(      28165452),  INT32_C(      39494844), -INT32_C(       7755528) },
       {   INT32_C(     146498168),  INT32_C(     132402648), -INT32_C(     185660856),  INT32_C(      36457872) },
       {   INT32_C(      15705022),  INT32_C(      14193942), -INT32_C(      19903374),  INT32_C(       3908388) },
       {   INT32_C(     111657938),  INT32_C(     100914618), -INT32_C(     141506946),  INT32_C(      27787452) },
       {   INT32_C(      53329394),  INT32_C(      48198234), -INT32_C(      67585698),  INT32_C(      13271676) },
       {   INT32_C(      50206848),  INT32_C(      45376128), -INT32_C(      63628416),  INT32_C(      12494592) },
       {  -INT32_C(      61189596), -INT32_C(      55302156),  INT32_C(      77547132), -INT32_C(      15227784) } },
     { {  -INT16_C(          4214), -INT16_C(          4132), -INT16_C(          7654),  INT16_C(          3308) },
       {  -INT16_C(          3137), -INT16_C(          5177),  INT16_C(          8825),  INT16_C(          5213),
           INT16_C(          4021), -INT16_C(          1222), -INT16_C(          2054), -INT16_C(          8636) },
       {   INT32_C(      26438636),  INT32_C(      25924168),  INT32_C(      48021196), -INT32_C(      20754392) },
       {   INT32_C(      43631756),  INT32_C(      42782728),  INT32_C(      79249516), -INT32_C(      34251032) },
       {  -INT32_C(      74377100), -INT32_C(      72929800), -INT32_C(     135093100),  INT32_C(      58386200) },
       {  -INT32_C(      43935164), -INT32_C(      43080232), -INT32_C(      79800604),  INT32_C(      34489208) },
       {  -INT32_C(      33888988), -INT32_C(      33229544), -INT32_C(      61553468),  INT32_C(      26602936) },
       {   INT32_C(      10299016),  INT32_C(      10098608),  INT32_C(      18706376), -INT32_C(       8084752) },
       {   INT32_C(      17311112),  INT32_C(      16974256),  INT32_C(      31442632), -INT32_C(      13589264) },
       {   INT32_C(      72784208),  INT32_C(      71367904),  INT32_C(     132199888), -INT32_C(      57135776) } },
     { {   INT16_C(          8803),  INT16_C(          8617),  INT16_C(          9238), -INT16_C(          7751) },
       {   INT16_C(          8128),  INT16_C(          8019),  INT16_C(          2912), -INT16_C(          8386),
          -INT16_C(          4694),  INT16_C(          8185),  INT16_C(          7703), -INT16_C(          8880) },
       {   INT32_C(     143101568),  INT32_C(     140077952),  INT32_C(     150172928), -INT32_C(     126000256) },
       {   INT32_C(     141182514),  INT32_C(     138199446),  INT32_C(     148159044), -INT32_C(     124310538) },
       {   INT32_C(      51268672),  INT32_C(      50185408),  INT32_C(      53802112), -INT32_C(      45141824) },
       {  -INT32_C(     147643916), -INT32_C(     144524324), -INT32_C(     154939736),  INT32_C(     129999772) },
       {  -INT32_C(      82642564), -INT32_C(      80896396), -INT32_C(      86726344),  INT32_C(      72766388) },
       {   INT32_C(     144105110),  INT32_C(     141060290),  INT32_C(     151226060), -INT32_C(     126883870) },
       {   INT32_C(     135619018),  INT32_C(     132753502),  INT32_C(     142320628), -INT32_C(     119411906) },
       {  -INT32_C(     156341280), -INT32_C(     153037920), -INT32_C(     164066880),  INT32_C(     137657760) } },
     { {   INT16_C(          4812),  INT16_C(          2790),  INT16_C(          8407), -INT16_C(          6588) },
       {  -INT16_C(           227), -INT16_C(          7945),  INT16_C(          7398),  INT16_C(          8350),
           INT16_C(          3728),  INT16_C(           359),  INT16_C(          2109),  INT16_C(          5197) },
       {  -INT32_C(       2184648), -INT32_C(       1266660), -INT32_C(       3816778),  INT32_C(       2990952) },
       {  -INT32_C(      76462680), -INT32_C(      44333100), -INT32_C(     133587230),  INT32_C(     104683320) },
       {   INT32_C(      71198352),  INT32_C(      41280840),  INT32_C(     124389972), -INT32_C(      97476048) },
       {   INT32_C(      80360400),  INT32_C(      46593000),  INT32_C(     140396900), -INT32_C(     110019600) },
       {   INT32_C(      35878272),  INT32_C(      20802240),  INT32_C(      62682592), -INT32_C(      49120128) },
       {   INT32_C(       3455016),  INT32_C(       2003220),  INT32_C(       6036226), -INT32_C(       4730184) },
       {   INT32_C(      20297016),  INT32_C(      11768220),  INT32_C(      35460726), -INT32_C(      27788184) },
       {   INT32_C(      50015928),  INT32_C(      28999260),  INT32_C(      87382358), -INT32_C(      68475672) } },
     { {  -INT16_C(          6029), -INT16_C(          5946), -INT16_C(          2972),  INT16_C(          1267) },
       {  -INT16_C(          3374),  INT16_C(          1580), -INT16_C(          5727), -INT16_C(          2042),
           INT16_C(          5896), -INT16_C(          1717),  INT16_C(          3183),  INT16_C(          9987) },
       {   INT32_C(      40683692),  INT32_C(      40123608),  INT32_C(      20055056), -INT32_C(       8549716) },
       {  -INT32_C(      19051640), -INT32_C(      18789360), -INT32_C(       9391520),  INT32_C(       4003720) },
       {   INT32_C(      69056166),  INT32_C(      68105484),  INT32_C(      34041288), -INT32_C(      14512218) },
       {   INT32_C(      24622436),  INT32_C(      24283464),  INT32_C(      12137648), -INT32_C(       5174428) },
       {  -INT32_C(      71093968), -INT32_C(      70115232), -INT32_C(      35045824),  INT32_C(      14940464) },
       {   INT32_C(      20703586),  INT32_C(      20418564),  INT32_C(      10205848), -INT32_C(       4350878) },
       {  -INT32_C(      38380614), -INT32_C(      37852236), -INT32_C(      18919752),  INT32_C(       8065722) },
       {  -INT32_C(     120423246), -INT32_C(     118765404), -INT32_C(      59362728),  INT32_C(      25307058) } },
     { {   INT16_C(          9052), -INT16_C(          5974),  INT16_C(           257),  INT16_C(          9738) },
       {  -INT16_C(          2364),  INT16_C(           176), -INT16_C(          3646),  INT16_C(          3711),
           INT16_C(          8971), -INT16_C(          7939), -INT16_C(          4436),  INT16_C(          7553) },
       {  -INT32_C(      42797856),  INT32_C(      28245072), -INT32_C(       1215096), -INT32_C(      46041264) },
       {   INT32_C(       3186304), -INT32_C(       2102848),  INT32_C(         90464),  INT32_C(       3427776) },
       {  -INT32_C(      66007184),  INT32_C(      43562408), -INT32_C(       1874044), -INT32_C(      71009496) },
       {   INT32_C(      67183944), -INT32_C(      44339028),  INT32_C(       1907454),  INT32_C(      72275436) },
       {   INT32_C(     162410984), -INT32_C(     107185508),  INT32_C(       4611094),  INT32_C(     174719196) },
       {  -INT32_C(     143727656),  INT32_C(      94855172), -INT32_C(       4080646), -INT32_C(     154619964) },
       {  -INT32_C(      80309344),  INT32_C(      53001328), -INT32_C(       2280104), -INT32_C(      86395536) },
       {   INT32_C(     136739512), -INT32_C(      90243244),  INT32_C(       3882242),  INT32_C(     147102228) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int32x4_t r0 = simde_vqdmull_laneq_s16(a, v, 0);
    simde_int32x4_t r1 = simde_vqdmull_laneq_s16(a, v, 1);
    simde_int32x4_t r2 = simde_vqdmull_laneq_s16(a, v, 2);
    simde_int32x4_t r3 = simde_vqdmull_laneq_s16(a, v, 3);
    simde_int32x4_t r4 = simde_vqdmull_laneq_s16(a, v, 4);
    simde_int32x4_t r5 = simde_vqdmull_laneq_s16(a, v, 5);
    simde_int32x4_t r6 = simde_vqdmull_laneq_s16(a, v, 6);
    simde_int32x4_t r7 = simde_vqdmull_laneq_s16(a, v, 7);

    simde_test_arm_neon_assert_equal_i32x4(r0, simde_vld1q_s32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i32x4(r1, simde_vld1q_s32(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i32x4(r2, simde_vld1q_s32(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_i32x4(r3, simde_vld1q_s32(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i32x4(r4, simde_vld1q_s32(test_vec[i].r4));
    simde_test_arm_neon_assert_equal_i32x4(r5, simde_vld1q_s32(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r7, simde_vld1q_s32(test_vec[i].r7));
  }

  return 0;
}

static int
test_simde_vqdmull_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t v[4];
    int64_t r0[2];
    int64_t r1[2];
    int64_t r2[2];
    int64_t r3[2];
  } test_vec[] = {
     { {  -INT32_C(          740313), -INT32_C(         1309248) },
       {   INT32_C(         3275217), -INT32_C(         5899901), -INT32_C(          746999),  INT32_C(         8043453) },
       {  -INT64_C(   4849371445842), -INT64_C(   8576142613632) },
       {   INT64_C(   8735546818026),  INT64_C(  15448867168896) },
       {   INT64_C(   1106026141374),  INT64_C(   1956013893504) },
       {  -INT64_C(  11909345641578), -INT64_C(  21061749506688) } },
     { {  -INT32_C(         2092703),  INT32_C(         1079828) },
       {   INT32_C(         8757605),  INT32_C(          294912),  INT32_C(         9379338),  INT32_C(         9257219) },
       {  -INT64_C(  36654132512630),  INT64_C(  18913414183880) },
       {  -INT64_C(   1234326454272),  INT64_C(    636908470272) },
       {  -INT64_C(  39256337541228),  INT64_C(  20256143587728) },
       {  -INT64_C(  38745219945914),  INT64_C(  19992408556664) } },
     { {   INT32_C(         3649334),  INT32_C(         4046007) },
       {  -INT32_C(         2938652),  INT32_C(         6787869),  INT32_C(         3565613),  INT32_C(         8520889) },
       {  -INT64_C(  21448245315536), -INT64_C(  23779613125128) },
       {   INT64_C(  49542402258492),  INT64_C(  54927530978166) },
       {   INT64_C(  26024225503484),  INT64_C(  28852990314582) },
       {   INT64_C(  62191139875852),  INT64_C(  68951153080446) } },
     { {  -INT32_C(         5837561), -INT32_C(         5855016) },
       {  -INT32_C(         7240451),  INT32_C(         6234870),  INT32_C(         8338179), -INT32_C(          510704) },
       {   INT64_C(  84533148760022),  INT64_C(  84785912904432) },
       {  -INT64_C(  72792867904140), -INT64_C(  73010527215840) },
       {  -INT64_C(  97349257082838), -INT64_C(  97640342911728) },
       {   INT64_C(   5962531505888),  INT64_C(   5980360182528) } },
     { {  -INT32_C(         8207047),  INT32_C(         2298705) },
       {  -INT32_C(          681158),  INT32_C(         8270752),  INT32_C(         3728012), -INT32_C(         5271108) },
       {   INT64_C(  11180591440852), -INT64_C(   3131562600780) },
       {  -INT64_C( 135756900778688),  INT64_C(  38024037952320) },
       {  -INT64_C(  61191939401128),  INT64_C(  17139199648920) },
       {   INT64_C(  86520462196152), -INT64_C(  24233444630280) } },
     { {  -INT32_C(          339794), -INT32_C(         4389703) },
       {   INT32_C(         5800265), -INT32_C(         2663644),  INT32_C(         5291255),  INT32_C(         3453411) },
       {  -INT64_C(   3941790490820), -INT64_C(  50922881342590) },
       {   INT64_C(   1810180498672),  INT64_C(  23385212115464) },
       {  -INT64_C(   3595873402940), -INT64_C(  46454075894530) },
       {  -INT64_C(   2346896674668), -INT64_C(  30318897253866) } },
     { {  -INT32_C(         9164937), -INT32_C(         3763377) },
       {  -INT32_C(          550606), -INT32_C(         8091428),  INT32_C(         2921370),  INT32_C(         4595120) },
       {   INT64_C(  10092538603644),  INT64_C(   4144275912924) },
       {   INT64_C( 148314855720072),  INT64_C(  60902188064712) },
       {  -INT64_C(  53548344007380), -INT64_C(  21988433332980) },
       {  -INT64_C(  84227970614880), -INT64_C(  34586337840480) } },
     { {  -INT32_C(         6331007),  INT32_C(         2058935) },
       {  -INT32_C(         1419668),  INT32_C(         9806776),  INT32_C(          973805),  INT32_C(          167524) },
       {   INT64_C(  17975856091352), -INT64_C(   5846008267160) },
       {  -INT64_C( 124173535006864),  INT64_C(  40383028687120) },
       {  -INT64_C(  12330332543270),  INT64_C(   4010002395350) },
       {  -INT64_C(   2121191233336),  INT64_C(    689842053880) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int64x2_t r0 = simde_vqdmull_laneq_s32(a, v, 0);
    simde_int64x2_t r1 = simde_vqdmull_laneq_s32(a, v, 1);
    simde_int64x2_t r2 = simde_vqdmull_laneq_s32(a, v, 2);
    simde_int64x2_t r3 = simde_vqdmull_laneq_s32(a, v, 3);

    simde_test_arm_neon_assert_equal_i64x2(r0, simde_vld1q_s64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i64x2(r1, simde_vld1q_s64(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i64x2(r2, simde_vld1q_s64(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_i64x2(r3, simde_vld1q_s64(test_vec[i].r3));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmullh_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulls_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmullh_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulls_laneq_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_lane_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
