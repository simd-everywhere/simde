#define SIMDE_TEST_ARM_NEON_INSN mlsl_high_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mlsl_high_lane.h"

static int
test_simde_vmlsl_high_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t v[8];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {   INT32_C(     67712035), -INT32_C(     67864461),  INT32_C(     11349754),  INT32_C(     52169456) },
       {   INT16_C(         6212), -INT16_C(         8322),  INT16_C(         7490), -INT16_C(         4147),
           INT16_C(         7816), -INT16_C(         4356),  INT16_C(         1955), -INT16_C(         6760) },
       {  -INT16_C(         3314), -INT16_C(         1248),  INT16_C(         6796),  INT16_C(         1372),
          -INT16_C(         6756), -INT16_C(         5059),  INT16_C(          108),  INT16_C(         4649)},
           INT8_C(            4),
       {   INT32_C(    120516931), -INT32_C(     97293597),  INT32_C(     24557734),  INT32_C(      6498896) } },
     { {   INT32_C(     75597580), -INT32_C(     60874521), -INT32_C(     67759165),  INT32_C(     80327885) },
       {  -INT16_C(         8993), -INT16_C(          682),  INT16_C(         8817), -INT16_C(         6314),
          -INT16_C(         6394),  INT16_C(         3962), -INT16_C(         6496), -INT16_C(         2545) },
       {  -INT16_C(         7603),  INT16_C(          209), -INT16_C(         7567), -INT16_C(         7069),
          -INT16_C(         1252), -INT16_C(         8141), -INT16_C(         4732), -INT16_C(         7645)},
           INT8_C(            7),
       {   INT32_C(     26715450), -INT32_C(     30585031), -INT32_C(    117421085),  INT32_C(     60871360) } },
     { {   INT32_C(     26187969), -INT32_C(     34665412),  INT32_C(     37889481),  INT32_C(     14150274) },
       {   INT16_C(         3068), -INT16_C(         3713), -INT16_C(         2487), -INT16_C(         9210),
           INT16_C(         1167), -INT16_C(         7653), -INT16_C(         2218),  INT16_C(         4419) },
       {  -INT16_C(         3731),  INT16_C(         6397),  INT16_C(         5705), -INT16_C(         8894),
          -INT16_C(          439), -INT16_C(         8184), -INT16_C(         3147), -INT16_C(         9441)},
           INT8_C(            7),
       {   INT32_C(     37205616), -INT32_C(    106917385),  INT32_C(     16949343),  INT32_C(     55870053) } },
     { {   INT32_C(     59507820), -INT32_C(     33087451),  INT32_C(     24156037),  INT32_C(     39805590) },
       {   INT16_C(         9106), -INT16_C(         7586), -INT16_C(         3923),  INT16_C(         8412),
          -INT16_C(         5902),  INT16_C(         9129),  INT16_C(         5614), -INT16_C(          759) },
       {  -INT16_C(         6242), -INT16_C(         9156),  INT16_C(         6483),  INT16_C(         5463),
          -INT16_C(         5715), -INT16_C(         8533), -INT16_C(         5979),  INT16_C(         8666)},
           INT8_C(            7),
       {   INT32_C(    110654552), -INT32_C(    112199365), -INT32_C(     24494887),  INT32_C(     46383084) } },
     { {   INT32_C(     70178161), -INT32_C(     83399214),  INT32_C(     38246661),  INT32_C(     19106266) },
       {   INT16_C(         2663), -INT16_C(          159),  INT16_C(         9408),  INT16_C(         5538),
           INT16_C(         4546),  INT16_C(         1653), -INT16_C(         4482), -INT16_C(         2814) },
       {  -INT16_C(         7600),  INT16_C(         4001),  INT16_C(         1914),  INT16_C(         4530),
          -INT16_C(         7475),  INT16_C(         9916), -INT16_C(         6657),  INT16_C(          389)},
           INT8_C(            6),
       {   INT32_C(    100440883), -INT32_C(     72395193),  INT32_C(      8409987),  INT32_C(       373468) } },
     { {  -INT32_C(     95033943), -INT32_C(     14366530),  INT32_C(     84221826), -INT32_C(     27784504) },
       {  -INT16_C(          227), -INT16_C(         9636),  INT16_C(         6066), -INT16_C(          588),
          -INT16_C(         8009), -INT16_C(         2439),  INT16_C(         9020), -INT16_C(         6696) },
       {   INT16_C(         6567),  INT16_C(         5099),  INT16_C(         1544), -INT16_C(         2666),
          -INT16_C(         9246),  INT16_C(         6472), -INT16_C(         8268),  INT16_C(         3662)},
           INT8_C(            2),
       {  -INT32_C(     82668047), -INT32_C(     10600714),  INT32_C(     70294946), -INT32_C(     17445880) } },
     { {   INT32_C(     73170314), -INT32_C(     38806359), -INT32_C(      6353119),  INT32_C(     11876393) },
       {  -INT16_C(         2801),  INT16_C(         5967), -INT16_C(         1216), -INT16_C(         2920),
          -INT16_C(         8145),  INT16_C(         1392), -INT16_C(         5137),  INT16_C(         8336) },
       {  -INT16_C(         6380), -INT16_C(          670),  INT16_C(          146),  INT16_C(         5849),
          -INT16_C(         2698),  INT16_C(         6342),  INT16_C(         4486),  INT16_C(         8046)},
           INT8_C(            2),
       {   INT32_C(     74359484), -INT32_C(     39009591), -INT32_C(      5603117),  INT32_C(     10659337) } },
     { {   INT32_C(     74620035),  INT32_C(     19263285),  INT32_C(     44551400), -INT32_C(     57917580) },
       {  -INT16_C(         5033), -INT16_C(         7722),  INT16_C(         3965), -INT16_C(         4620),
          -INT16_C(         9970),  INT16_C(         9675), -INT16_C(         5475),  INT16_C(         6604) },
       {  -INT16_C(         8764),  INT16_C(         2998),  INT16_C(         2265),  INT16_C(         3368),
          -INT16_C(         4897),  INT16_C(         3529),  INT16_C(         2167), -INT16_C(         2180)},
           INT8_C(            5),
       {   INT32_C(    109804165), -INT32_C(     14879790),  INT32_C(     63872675), -INT32_C(     81223096) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int32x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmlsl_high_laneq_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsl_high_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(     16038286), -INT32_C(     28905122), -INT32_C(     41483605),  INT32_C(     30927504) },
       {  -INT16_C(         6766),  INT16_C(         3589),  INT16_C(         4613),  INT16_C(         8569),
          -INT16_C(         4501), -INT16_C(          781),  INT16_C(           55),  INT16_C(         7815) },
       {  -INT16_C(         1002),  INT16_C(         8827), -INT16_C(         2491), -INT16_C(         2507)},
           INT8_C(            1),
       {   INT32_C(     23692041), -INT32_C(     22011235), -INT32_C(     41969090), -INT32_C(     38055501) } },
     { {  -INT32_C(      1465584), -INT32_C(     93487862), -INT32_C(     45926674), -INT32_C(     67678742) },
       {   INT16_C(         2292),  INT16_C(         6442), -INT16_C(         4172),  INT16_C(         7676),
          -INT16_C(         4398),  INT16_C(         9179),  INT16_C(         8183), -INT16_C(         4844) },
       {   INT16_C(         9033), -INT16_C(         6631),  INT16_C(         1491),  INT16_C(         1758)},
           INT8_C(            0),
       {   INT32_C(     38261550), -INT32_C(    176401769), -INT32_C(    119843713), -INT32_C(     23922890) } },
     { {   INT32_C(     63865457),  INT32_C(     78987025), -INT32_C(     62827444), -INT32_C(     20940752) },
       {  -INT16_C(         6639), -INT16_C(         7243),  INT16_C(         4755),  INT16_C(          114),
           INT16_C(         9724), -INT16_C(         2345),  INT16_C(         1685), -INT16_C(         3253) },
       {  -INT16_C(         9839),  INT16_C(         8885),  INT16_C(         9180),  INT16_C(         7911)},
           INT8_C(            3),
       {  -INT32_C(     13061107),  INT32_C(     97538320), -INT32_C(     76157479),  INT32_C(      4793731) } },
     { {   INT32_C(     93331675), -INT32_C(     42492077),  INT32_C(     87569415), -INT32_C(     40528661) },
       {   INT16_C(         6333),  INT16_C(         6967),  INT16_C(         1558),  INT16_C(         1671),
           INT16_C(         2212),  INT16_C(         1053), -INT16_C(         9343), -INT16_C(         4322) },
       {  -INT16_C(          360),  INT16_C(         5517), -INT16_C(          850),  INT16_C(          589)},
           INT8_C(            0),
       {   INT32_C(     94127995), -INT32_C(     42112997),  INT32_C(     84205935), -INT32_C(     42084581) } },
     { {   INT32_C(     67912905),  INT32_C(     80342618),  INT32_C(     19746680), -INT32_C(     45657976) },
       {   INT16_C(         1855), -INT16_C(          312), -INT16_C(          795),  INT16_C(         4535),
          -INT16_C(          875),  INT16_C(         1465), -INT16_C(         8325), -INT16_C(          511) },
       {  -INT16_C(         3560), -INT16_C(         7596), -INT16_C(         6733), -INT16_C(         7743)},
           INT8_C(            3),
       {   INT32_C(     61137780),  INT32_C(     91686113), -INT32_C(     44713795), -INT32_C(     49614649) } },
     { {  -INT32_C(     78117098),  INT32_C(     22969964),  INT32_C(     14298623), -INT32_C(     65823014) },
       {  -INT16_C(         4909),  INT16_C(          793),  INT16_C(         8395),  INT16_C(         1872),
          -INT16_C(         3709), -INT16_C(         6161), -INT16_C(         6335), -INT16_C(         3541) },
       {  -INT16_C(         5046),  INT16_C(         1110), -INT16_C(         3197), -INT16_C(         2235)},
           INT8_C(            2),
       {  -INT32_C(     89974771),  INT32_C(      3273247), -INT32_C(      5954372), -INT32_C(     77143591) } },
     { {  -INT32_C(     10285084), -INT32_C(      6337390),  INT32_C(     33112012),  INT32_C(     22633887) },
       {   INT16_C(         7823),  INT16_C(         5178), -INT16_C(         1524),  INT16_C(         5223),
           INT16_C(         3728),  INT16_C(         1041), -INT16_C(         4068),  INT16_C(         9734) },
       {  -INT16_C(         2560), -INT16_C(         2460),  INT16_C(         1203),  INT16_C(         7274)},
           INT8_C(            1),
       {  -INT32_C(      1114204), -INT32_C(      3776530),  INT32_C(     23104732),  INT32_C(     46579527) } },
     { {  -INT32_C(      7539938),  INT32_C(     29005221),  INT32_C(     87743249), -INT32_C(     60072285) },
       {   INT16_C(           59), -INT16_C(         3792), -INT16_C(         4149),  INT16_C(         2029),
          -INT16_C(         9974), -INT16_C(         1840),  INT16_C(         9068),  INT16_C(         7620) },
       {  -INT16_C(         1100), -INT16_C(         4625),  INT16_C(         4297), -INT16_C(         5953)},
           INT8_C(            0),
       {  -INT32_C(     18511338),  INT32_C(     26981221),  INT32_C(     97718049), -INT32_C(     51690285) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmlsl_high_lane_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsl_high_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t v[4];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {  -INT64_C(    455879767), -INT64_C(    866486967) },
       {   INT32_C(       743175), -INT32_C(       968111),  INT32_C(       116900),  INT32_C(       587450) },
       {   INT32_C(       171585), -INT32_C(       745875),  INT32_C(       868410),  INT32_C(       148291)},
           INT8_C(            0),
       {  -INT64_C(  20514166267), -INT64_C( 101664095217) } },
     { {  -INT64_C(    826317710),  INT64_C(    500734654) },
       {   INT32_C(       171853), -INT32_C(       119370),  INT32_C(       240470),  INT32_C(       141429) },
       {  -INT32_C(       835082), -INT32_C(        66691), -INT32_C(       592739), -INT32_C(       599194)},
           INT8_C(            2),
       {   INT64_C( 141709629620),  INT64_C(  84331218685) } },
     { {  -INT64_C(    112887201),  INT64_C(    931258661) },
       {   INT32_C(       421732), -INT32_C(       791541),  INT32_C(       970308),  INT32_C(       537492) },
       {  -INT32_C(       975259),  INT32_C(       966845), -INT32_C(       107533),  INT32_C(       451460)},
           INT8_C(            3),
       {  -INT64_C( 438168136881), -INT64_C( 241724879659) } },
     { {  -INT64_C(    695291438), -INT64_C(    484847055) },
       {  -INT32_C(       141398), -INT32_C(       191063), -INT32_C(       991962),  INT32_C(         8773) },
       {   INT32_C(       143999),  INT32_C(       928844), -INT32_C(       572636), -INT32_C(       865390)},
           INT8_C(            2),
       {  -INT64_C( 568728443270),  INT64_C(   4538888573) } },
     { {   INT64_C(    824767030),  INT64_C(    935157684) },
       {   INT32_C(       462167),  INT32_C(       230846),  INT32_C(       485541),  INT32_C(       495559) },
       {  -INT32_C(       786156), -INT32_C(       603217),  INT32_C(       818113),  INT32_C(       187995)},
           INT8_C(            2),
       {  -INT64_C( 396402637103), -INT64_C( 404488102483) } },
     { {  -INT64_C(     68123208), -INT64_C(    140265965) },
       {  -INT32_C(       881879), -INT32_C(       409087),  INT32_C(       907326),  INT32_C(       894362) },
       {  -INT32_C(        67813), -INT32_C(       787612), -INT32_C(       785492), -INT32_C(       828160)},
           INT8_C(            0),
       {   INT64_C(  61460374830),  INT64_C(  60509104341) } },
     { {  -INT64_C(    194996680),  INT64_C(    107121797) },
       {   INT32_C(       509167),  INT32_C(       962020),  INT32_C(       931436), -INT32_C(        84232) },
       {   INT32_C(       165195),  INT32_C(       187721), -INT32_C(       976542),  INT32_C(       703973)},
           INT8_C(            2),
       {   INT64_C( 909391377632), -INT64_C(  82148963947) } },
     { {  -INT64_C(    643129462),  INT64_C(    766919626) },
       {  -INT32_C(       487078), -INT32_C(       903804),  INT32_C(       307937), -INT32_C(       572415) },
       {   INT32_C(       433558), -INT32_C(       631566), -INT32_C(       446919),  INT32_C(        22497)},
           INT8_C(            3),
       {  -INT64_C(   7570788151),  INT64_C(  13644539881) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int64x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmlsl_high_laneq_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsl_high_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t v[2];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {  -INT64_C(    779064126),  INT64_C(    926199021) },
       {  -INT32_C(         7543),  INT32_C(       658987), -INT32_C(       306512), -INT32_C(       652839) },
       {   INT32_C(       851028), -INT32_C(        22360)},
           INT8_C(            1),
       {  -INT64_C(   7632672446), -INT64_C(  13671281019) } },
     { {  -INT64_C(    807375181),  INT64_C(    424049830) },
       {  -INT32_C(       435009),  INT32_C(       136227), -INT32_C(       980835),  INT32_C(       681295) },
       {  -INT32_C(       170976), -INT32_C(       898669)},
           INT8_C(            0),
       {  -INT64_C( 168506620141),  INT64_C( 116909143750) } },
     { {   INT64_C(    949966717), -INT64_C(    757291296) },
       {   INT32_C(       221316), -INT32_C(       984565),  INT32_C(       799048), -INT32_C(       415305) },
       {   INT32_C(       138966),  INT32_C(        30515)},
           INT8_C(            0),
       {  -INT64_C( 110090537651),  INT64_C(  56955983334) } },
     { {  -INT64_C(    761919040), -INT64_C(    521168046) },
       {   INT32_C(       975792),  INT32_C(       503464),  INT32_C(       260846), -INT32_C(       135815) },
       {  -INT32_C(        29474), -INT32_C(       357205)},
           INT8_C(            0),
       {   INT64_C(   6926255964), -INT64_C(   4524179356) } },
     { {   INT64_C(     39073934), -INT64_C(    667409585) },
       {   INT32_C(       935425), -INT32_C(       770364), -INT32_C(       376646),  INT32_C(        52533) },
       {  -INT32_C(       805091), -INT32_C(       419069)},
           INT8_C(            0),
       {  -INT64_C( 303195230852),  INT64_C(  41626435918) } },
     { {  -INT64_C(    320427737),  INT64_C(     98736754) },
       {   INT32_C(       725730), -INT32_C(       741638),  INT32_C(       577936),  INT32_C(       581300) },
       {  -INT32_C(       927094), -INT32_C(       751422)},
           INT8_C(            0),
       {   INT64_C( 535480570247),  INT64_C( 539018478954) } },
     { {   INT64_C(     18901554), -INT64_C(    378285155) },
       {  -INT32_C(       874243), -INT32_C(       873519), -INT32_C(       216250),  INT32_C(       875544) },
       {  -INT32_C(       571670),  INT32_C(       755647)},
           INT8_C(            1),
       {   INT64_C( 163427565304), -INT64_C( 661980482123) } },
     { {   INT64_C(     14496407),  INT64_C(    779073912) },
       {   INT32_C(       761041), -INT32_C(       995277), -INT32_C(       164203),  INT32_C(       782472) },
       {  -INT32_C(        63927), -INT32_C(       720738)},
           INT8_C(            0),
       {  -INT64_C(  10482508774),  INT64_C(  50800161456) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmlsl_high_lane_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsl_high_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint16_t v[8];
    int8_t lane;
    uint32_t r[4];
  } test_vec[] = {
     { {   UINT32_C(    187720474),  UINT32_C(    114738506),  UINT32_C(    154477949),  UINT32_C(     37108131) },
       {   UINT16_C(        11178),  UINT16_C(        14095),  UINT16_C(        19757),  UINT16_C(        17210),
           UINT16_C(        11826),  UINT16_C(        15068),  UINT16_C(         8896),  UINT16_C(        11650) },
       {   UINT16_C(         3516),  UINT16_C(        12389),  UINT16_C(        18464),  UINT16_C(        13345),
           UINT16_C(        13597),  UINT16_C(        12234),  UINT16_C(         2634),  UINT16_C(        17835)},
           INT8_C(            4),
       {   UINT32_C(     26922352),  UINT32_C(   4204826206),  UINT32_C(     33519037),  UINT32_C(   4173670377) } },
     { {   UINT32_C(     86470971),  UINT32_C(     31690454),  UINT32_C(     18826166),  UINT32_C(     46891713) },
       {   UINT16_C(        10051),  UINT16_C(        19970),  UINT16_C(        19809),  UINT16_C(         5870),
           UINT16_C(         8884),  UINT16_C(         9361),  UINT16_C(        11925),  UINT16_C(         2241) },
       {   UINT16_C(         3459),  UINT16_C(         9236),  UINT16_C(        14016),  UINT16_C(        19498),
           UINT16_C(         4400),  UINT16_C(          982),  UINT16_C(        13826),  UINT16_C(        19737)},
           INT8_C(            2),
       {   UINT32_C(   4256920123),  UINT32_C(   4195453974),  UINT32_C(   4146652662),  UINT32_C(     15481857) } },
     { {   UINT32_C(    106352497),  UINT32_C(     72349451),  UINT32_C(    129526511),  UINT32_C(     63122726) },
       {   UINT16_C(         9656),  UINT16_C(        18065),  UINT16_C(         6404),  UINT16_C(        10849),
           UINT16_C(         4802),  UINT16_C(         9367),  UINT16_C(         3503),  UINT16_C(         7190) },
       {   UINT16_C(         3112),  UINT16_C(         9509),  UINT16_C(         6718),  UINT16_C(        10772),
           UINT16_C(         6968),  UINT16_C(        11549),  UINT16_C(        18296),  UINT16_C(         5254)},
           INT8_C(            1),
       {   UINT32_C(     60690279),  UINT32_C(   4278245944),  UINT32_C(     96216484),  UINT32_C(   4289720312) } },
     { {   UINT32_C(     75743798),  UINT32_C(    158787442),  UINT32_C(     96830003),  UINT32_C(    140288831) },
       {   UINT16_C(        10998),  UINT16_C(         1303),  UINT16_C(         2067),  UINT16_C(        13241),
           UINT16_C(        12475),  UINT16_C(        18530),  UINT16_C(         8560),  UINT16_C(        19234) },
       {   UINT16_C(        19672),  UINT16_C(        14469),  UINT16_C(        16251),  UINT16_C(         1202),
           UINT16_C(         3808),  UINT16_C(         3251),  UINT16_C(        14644),  UINT16_C(         5374)},
           INT8_C(            2),
       {   UINT32_C(   4167979869),  UINT32_C(   4152623708),  UINT32_C(   4252688739),  UINT32_C(   4122684393) } },
     { {   UINT32_C(     18116890),  UINT32_C(    139746422),  UINT32_C(     18991941),  UINT32_C(     18587699) },
       {   UINT16_C(         7461),  UINT16_C(        15853),  UINT16_C(        11733),  UINT16_C(         3207),
           UINT16_C(          752),  UINT16_C(        19168),  UINT16_C(         6498),  UINT16_C(        19201) },
       {   UINT16_C(        11749),  UINT16_C(        15661),  UINT16_C(         8124),  UINT16_C(        14225),
           UINT16_C(        11175),  UINT16_C(         4834),  UINT16_C(         1326),  UINT16_C(         9295)},
           INT8_C(            3),
       {   UINT32_C(      7419690),  UINT32_C(   4162048918),  UINT32_C(   4221525187),  UINT32_C(   4040420770) } },
     { {   UINT32_C(    177779414),  UINT32_C(     28653639),  UINT32_C(    191452144),  UINT32_C(    122212991) },
       {   UINT16_C(        16872),  UINT16_C(         2341),  UINT16_C(        19547),  UINT16_C(         3013),
           UINT16_C(        10180),  UINT16_C(        18540),  UINT16_C(         3216),  UINT16_C(        18595) },
       {   UINT16_C(        19844),  UINT16_C(        19936),  UINT16_C(         6809),  UINT16_C(         6435),
           UINT16_C(        16250),  UINT16_C(        18972),  UINT16_C(         1879),  UINT16_C(          700)},
           INT8_C(            6),
       {   UINT32_C(    158651194),  UINT32_C(   4288784275),  UINT32_C(    185409280),  UINT32_C(     87272986) } },
     { {   UINT32_C(    191118184),  UINT32_C(    133087100),  UINT32_C(      6939589),  UINT32_C(    179040854) },
       {   UINT16_C(        17789),  UINT16_C(          983),  UINT16_C(         5092),  UINT16_C(        13224),
           UINT16_C(         9772),  UINT16_C(        12128),  UINT16_C(        11539),  UINT16_C(         6813) },
       {   UINT16_C(        16436),  UINT16_C(         4748),  UINT16_C(        10981),  UINT16_C(         6595),
           UINT16_C(        15229),  UINT16_C(         8269),  UINT16_C(        14302),  UINT16_C(        16045)},
           INT8_C(            4),
       {   UINT32_C(     42300396),  UINT32_C(   4243357084),  UINT32_C(   4126179454),  UINT32_C(     75285677) } },
     { {   UINT32_C(    161867121),  UINT32_C(    166534840),  UINT32_C(    152062199),  UINT32_C(    100090646) },
       {   UINT16_C(        18028),  UINT16_C(        14483),  UINT16_C(        12126),  UINT16_C(         5959),
           UINT16_C(        14581),  UINT16_C(        18561),  UINT16_C(          925),  UINT16_C(        19196) },
       {   UINT16_C(         2543),  UINT16_C(        12197),  UINT16_C(        19676),  UINT16_C(        11063),
           UINT16_C(        11990),  UINT16_C(        14163),  UINT16_C(         8178),  UINT16_C(         1054)},
           INT8_C(            6),
       {   UINT32_C(     42623703),  UINT32_C(     14742982),  UINT32_C(    144497549),  UINT32_C(   4238073054) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t v = simde_vld1q_u16(test_vec[i].v);
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_8_(simde_vmlsl_high_laneq_u16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsl_high_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint16_t v[4];
    int8_t lane;
    uint32_t r[4];
  } test_vec[] = {
     { {   UINT32_C(    128129524),  UINT32_C(      3786337),  UINT32_C(     89219593),  UINT32_C(    156381984) },
       {   UINT16_C(        16047),  UINT16_C(         4999),  UINT16_C(        18363),  UINT16_C(        12281),
           UINT16_C(         6887),  UINT16_C(        15950),  UINT16_C(         5386),  UINT16_C(         8860) },
       {   UINT16_C(         1477),  UINT16_C(         9737),  UINT16_C(         8887),  UINT16_C(        18453)},
           INT8_C(            1),
       {   UINT32_C(     61070805),  UINT32_C(   4143448483),  UINT32_C(     36776111),  UINT32_C(     70112164) } },
     { {   UINT32_C(    154613048),  UINT32_C(     62703310),  UINT32_C(     94381071),  UINT32_C(     21069636) },
       {   UINT16_C(         1583),  UINT16_C(        19523),  UINT16_C(         1869),  UINT16_C(        10490),
           UINT16_C(        13433),  UINT16_C(        15062),  UINT16_C(         1731),  UINT16_C(         9759) },
       {   UINT16_C(        19043),  UINT16_C(        13447),  UINT16_C(        13345),  UINT16_C(         8332)},
           INT8_C(            1),
       {   UINT32_C(   4268946793),  UINT32_C(   4155131892),  UINT32_C(     71104314),  UINT32_C(   4184807659) } },
     { {   UINT32_C(     18645400),  UINT32_C(     52106771),  UINT32_C(     91507360),  UINT32_C(      8180764) },
       {   UINT16_C(         6572),  UINT16_C(        16642),  UINT16_C(        11506),  UINT16_C(         7010),
           UINT16_C(        10364),  UINT16_C(        19132),  UINT16_C(         1311),  UINT16_C(         9727) },
       {   UINT16_C(         5894),  UINT16_C(         3908),  UINT16_C(        18924),  UINT16_C(         8301)},
           INT8_C(            3),
       {   UINT32_C(   4227581132),  UINT32_C(   4188259335),  UINT32_C(     80624749),  UINT32_C(   4222404233) } },
     { {   UINT32_C(     81479648),  UINT32_C(     76992396),  UINT32_C(    177872811),  UINT32_C(    169811774) },
       {   UINT16_C(          952),  UINT16_C(         9039),  UINT16_C(        13623),  UINT16_C(         8401),
           UINT16_C(        17428),  UINT16_C(        13099),  UINT16_C(         3553),  UINT16_C(         2542) },
       {   UINT16_C(        15201),  UINT16_C(         7062),  UINT16_C(         2290),  UINT16_C(          747)},
           INT8_C(            2),
       {   UINT32_C(     41569528),  UINT32_C(     46995686),  UINT32_C(    169736441),  UINT32_C(    163990594) } },
     { {   UINT32_C(      1560560),  UINT32_C(     79174338),  UINT32_C(    142942120),  UINT32_C(     22318614) },
       {   UINT16_C(        12362),  UINT16_C(        13981),  UINT16_C(        11678),  UINT16_C(         5815),
           UINT16_C(        17685),  UINT16_C(         9255),  UINT16_C(         2518),  UINT16_C(         4104) },
       {   UINT16_C(          150),  UINT16_C(        12096),  UINT16_C(        10674),  UINT16_C(         9603)},
           INT8_C(            1),
       {   UINT32_C(   4082610096),  UINT32_C(   4262193154),  UINT32_C(    112484392),  UINT32_C(   4267643926) } },
     { {   UINT32_C(    144333765),  UINT32_C(    154887730),  UINT32_C(     39392927),  UINT32_C(    180100438) },
       {   UINT16_C(         5728),  UINT16_C(         2487),  UINT16_C(         7638),  UINT16_C(         6550),
           UINT16_C(          243),  UINT16_C(        12181),  UINT16_C(         3983),  UINT16_C(         4204) },
       {   UINT16_C(         1344),  UINT16_C(        18837),  UINT16_C(        14633),  UINT16_C(        17217)},
           INT8_C(            0),
       {   UINT32_C(    144007173),  UINT32_C(    138516466),  UINT32_C(     34039775),  UINT32_C(    174450262) } },
     { {   UINT32_C(    148671659),  UINT32_C(     92903426),  UINT32_C(    144006204),  UINT32_C(    158401926) },
       {   UINT16_C(        10515),  UINT16_C(         2001),  UINT16_C(        10205),  UINT16_C(        15759),
           UINT16_C(         8453),  UINT16_C(        15176),  UINT16_C(        16053),  UINT16_C(         6945) },
       {   UINT16_C(         7678),  UINT16_C(          896),  UINT16_C(          265),  UINT16_C(         2973)},
           INT8_C(            0),
       {   UINT32_C(     83769525),  UINT32_C(   4271349394),  UINT32_C(     20751270),  UINT32_C(    105078216) } },
     { {   UINT32_C(     23512841),  UINT32_C(    124122782),  UINT32_C(     95375810),  UINT32_C(    162866734) },
       {   UINT16_C(         3173),  UINT16_C(         2773),  UINT16_C(        18470),  UINT16_C(         2835),
           UINT16_C(         8062),  UINT16_C(         3364),  UINT16_C(        11264),  UINT16_C(        12468) },
       {   UINT16_C(         3547),  UINT16_C(        18994),  UINT16_C(         3273),  UINT16_C(         6367)},
           INT8_C(            3),
       {   UINT32_C(   4267149383),  UINT32_C(    102704194),  UINT32_C(     23657922),  UINT32_C(     83482978) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x4_t v = simde_vld1_u16(test_vec[i].v);
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vmlsl_high_lane_u16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsl_high_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint32_t v[4];
    int8_t lane;
    uint64_t r[2];
  } test_vec[] = {
     { {   UINT64_C(   1039934347),  UINT64_C(    275280831) },
       {   UINT32_C(      1037015),  UINT32_C(       235679),  UINT32_C(       382401),  UINT32_C(       303311) },
       {   UINT32_C(      1100818),  UINT32_C(       949066),  UINT32_C(       654879),  UINT32_C(       944978)},
           INT8_C(            0),
       {   UINT64_C(18446743653795581945),  UINT64_C(18446743740094624049) } },
     { {   UINT64_C(   1673630883),  UINT64_C(   1187815648) },
       {   UINT32_C(      1508415),  UINT32_C(       759706),  UINT32_C(      1215861),  UINT32_C(       373592) },
       {   UINT32_C(      1140856),  UINT32_C(        62017),  UINT32_C(      1341655),  UINT32_C(       806406)},
           INT8_C(            2),
       {   UINT64_C(18446742444117192544),  UINT64_C(18446743573665792504) } },
     { {   UINT64_C(   1732619684),  UINT64_C(   1823057864) },
       {   UINT32_C(       916962),  UINT32_C(      1578628),  UINT32_C(      1232510),  UINT32_C(       750619) },
       {   UINT32_C(      1060614),  UINT32_C(      1407908),  UINT32_C(       951551),  UINT32_C(      1115279)},
           INT8_C(            2),
       {   UINT64_C(18446742902646048290),  UINT64_C(18446743361280349411) } },
     { {   UINT64_C(    435430309),  UINT64_C(   1755206050) },
       {   UINT32_C(      1263544),  UINT32_C(      1208264),  UINT32_C(       282088),  UINT32_C(      1576857) },
       {   UINT32_C(       834152),  UINT32_C(      1446343),  UINT32_C(      1167738),  UINT32_C(       844313)},
           INT8_C(            1),
       {   UINT64_C(18446743666148977741),  UINT64_C(18446741794788673715) } },
     { {   UINT64_C(    517870838),  UINT64_C(   1805264897) },
       {   UINT32_C(       392603),  UINT32_C(       693883),  UINT32_C(       564681),  UINT32_C(      1770000) },
       {   UINT32_C(       350732),  UINT32_C(      1777733),  UINT32_C(        98652),  UINT32_C(       262293)},
           INT8_C(            1),
       {   UINT64_C(18446743070375374281),  UINT64_C(18446740928927406513) } },
     { {   UINT64_C(   1224729507),  UINT64_C(   1782158252) },
       {   UINT32_C(       511816),  UINT32_C(      1539770),  UINT32_C(       908365),  UINT32_C(       940596) },
       {   UINT32_C(       122510),  UINT32_C(       293642),  UINT32_C(       927041),  UINT32_C(      1320491)},
           INT8_C(            1),
       {   UINT64_C(18446743808200165793),  UINT64_C(18446743799293219236) } },
     { {   UINT64_C(   1904006206),  UINT64_C(    662780591) },
       {   UINT32_C(      1169760),  UINT32_C(      1600085),  UINT32_C(        87097),  UINT32_C(      1607558) },
       {   UINT32_C(       112360),  UINT32_C(      1461102),  UINT32_C(      1127403),  UINT32_C(      1753289)},
           INT8_C(            2),
       {   UINT64_C(18446743977420138731),  UINT64_C(18446742262006620333) } },
     { {   UINT64_C(   1717748601),  UINT64_C(    884477975) },
       {   UINT32_C(       154487),  UINT32_C(      1186882),  UINT32_C(      1967124),  UINT32_C(       352963) },
       {   UINT32_C(      1412406),  UINT32_C(      1778692),  UINT32_C(      1967061),  UINT32_C(      1813001)},
           INT8_C(            0),
       {   UINT64_C(18446741297049559873),  UINT64_C(18446743576066970613) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t v = simde_vld1q_u32(test_vec[i].v);
    simde_uint64x2_t r;
    SIMDE_CONSTIFY_4_(simde_vmlsl_high_laneq_u32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlsl_high_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint32_t v[2];
    int8_t lane;
    uint64_t r[2];
  } test_vec[] = {
     { {   UINT64_C(    807346442),  UINT64_C(    390336432) },
       {   UINT32_C(      1727904),  UINT32_C(      1212124),  UINT32_C(       729670),  UINT32_C(      1999448) },
       {   UINT32_C(       321407),  UINT32_C(      1749330)},
           INT8_C(            1),
       {   UINT64_C(18446742798083276958),  UINT64_C(18446740576405518208) } },
     { {   UINT64_C(   1130610500),  UINT64_C(   1294274127) },
       {   UINT32_C(      1792777),  UINT32_C(      1677015),  UINT32_C(       570046),  UINT32_C(       333541) },
       {   UINT32_C(       960454),  UINT32_C(      1978051)},
           INT8_C(            1),
       {   UINT64_C(18446742947260101770),  UINT64_C(18446743415242717152) } },
     { {   UINT64_C(   1764044054),  UINT64_C(   1316201253) },
       {   UINT32_C(       590075),  UINT32_C(       998633),  UINT32_C(       465915),  UINT32_C(        50919) },
       {   UINT32_C(      1611355),  UINT32_C(      1506608)},
           INT8_C(            1),
       {   UINT64_C(18446743373522329350),  UINT64_C(18446743998310780117) } },
     { {   UINT64_C(   1691008098),  UINT64_C(    171003782) },
       {   UINT32_C(      1110725),  UINT32_C(        28618),  UINT32_C(        33748),  UINT32_C(        91128) },
       {   UINT32_C(       918135),  UINT32_C(       884987)},
           INT8_C(            0),
       {   UINT64_C(18446744044415339734),  UINT64_C(18446743990212749118) } },
     { {   UINT64_C(   1821092036),  UINT64_C(   1170774552) },
       {   UINT32_C(      1433017),  UINT32_C(       609507),  UINT32_C(       937285),  UINT32_C(       613346) },
       {   UINT32_C(      1688325),  UINT32_C(       219981)},
           INT8_C(            1),
       {   UINT64_C(18446743869345752067),  UINT64_C(18446743939955859742) } },
     { {   UINT64_C(    657842295),  UINT64_C(    149096922) },
       {   UINT32_C(      1406492),  UINT32_C(      1660419),  UINT32_C(      1588085),  UINT32_C(       222194) },
       {   UINT32_C(      1600913),  UINT32_C(       436431)},
           INT8_C(            1),
       {   UINT64_C(18446743381277869276),  UINT64_C(18446743976886298924) } },
     { {   UINT64_C(   1800862766),  UINT64_C(    351385912) },
       {   UINT32_C(      1985028),  UINT32_C(       610354),  UINT32_C(       598858),  UINT32_C(       634547) },
       {   UINT32_C(       161297),  UINT32_C(      1989972)},
           INT8_C(            0),
       {   UINT64_C(18446743978916415556),  UINT64_C(18446743971710410069) } },
     { {   UINT64_C(    660613479),  UINT64_C(   1473821982) },
       {   UINT32_C(      1795900),  UINT32_C(      1528251),  UINT32_C(      1047197),  UINT32_C(      1818799) },
       {   UINT32_C(       725139),  UINT32_C(      1130632)},
           INT8_C(            0),
       {   UINT64_C(18446743315006779712),  UINT64_C(18446742756301285537) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x2_t v = simde_vld1_u32(test_vec[i].v);
    simde_uint64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vmlsl_high_lane_u32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_lane_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_laneq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
