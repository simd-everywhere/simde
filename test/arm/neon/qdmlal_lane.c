#define SIMDE_TEST_ARM_NEON_INSN qdmlal_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlal_lane.h"

SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vqdmlalh_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[1];
    int16_t b[1];
    int16_t v[4];
    int8_t lane;
    int32_t r[1];
  } test_vec[] = {
     { {  -INT32_C( 928597325) },
       {   INT16_C(       491) },
       {  -INT16_C(      1892),  INT16_C(      7957),  INT16_C(      5108), -INT16_C(      4917)},
           INT8_C(         1),
       {  -INT32_C( 920783551) } },
     { {   INT32_C( 955503274) },
       {   INT16_C(      5989) },
       {   INT16_C(      2544),  INT16_C(      6322), -INT16_C(      3642),  INT16_C(      6506)},
           INT8_C(         3),
       {   INT32_C(1033432142) } },
     { {  -INT32_C( 114948833) },
       {  -INT16_C(      1212) },
       {  -INT16_C(      2485),  INT16_C(      6915),  INT16_C(      4401), -INT16_C(      4449)},
           INT8_C(         2),
       {  -INT32_C( 125616857) } },
     { {  -INT32_C( 905358336) },
       {  -INT16_C(      3455) },
       {   INT16_C(      4546),  INT16_C(      9051), -INT16_C(      2684), -INT16_C(      1201)},
           INT8_C(         0),
       {  -INT32_C( 936771196) } },
     { {  -INT32_C( 126619894) },
       {  -INT16_C(      5411) },
       {   INT16_C(      2205),  INT16_C(      7625), -INT16_C(      8915), -INT16_C(       429)},
           INT8_C(         1),
       {  -INT32_C( 209137644) } },
     { {   INT32_C( 194201072) },
       {   INT16_C(      1004) },
       {   INT16_C(      9001),  INT16_C(      4983), -INT16_C(      7323),  INT16_C(      5349)},
           INT8_C(         1),
       {   INT32_C( 204206936) } },
     { {   INT32_C( 708756366) },
       {  -INT16_C(      9878) },
       {   INT16_C(      4537),  INT16_C(      4529), -INT16_C(      5439), -INT16_C(      1731)},
           INT8_C(         0),
       {   INT32_C( 619123394) } },
     { {  -INT32_C( 380764463) },
       {  -INT16_C(      1634) },
       {  -INT16_C(      4899),  INT16_C(      1026), -INT16_C(      4249), -INT16_C(      6523)},
           INT8_C(         0),
       {  -INT32_C( 364754531) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    int32_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlalh_lane_s16(test_vec[i].a[0], test_vec[i].b[0], v, 0); break;
      case 1: r = simde_vqdmlalh_lane_s16(test_vec[i].a[0], test_vec[i].b[0], v, 1); break;
      case 2: r = simde_vqdmlalh_lane_s16(test_vec[i].a[0], test_vec[i].b[0], v, 2); break;
      case 3: r = simde_vqdmlalh_lane_s16(test_vec[i].a[0], test_vec[i].b[0], v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = 0; break;
    }

    simde_assert_equal_i32(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlals_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[1];
    int32_t b[1];
    int32_t v[2];
    int8_t lane;
    int64_t r[1];
  } test_vec[] = {
     { {   INT64_C(  44508685950) },
       {  -INT32_C(       979248) },
       {   INT32_C(       943996),  INT32_C(       693027)},
           INT8_C(            1),
       {  -INT64_C(1312781921442) } },
     { {   INT64_C(  76828192571) },
       {  -INT32_C(       730800) },
       {   INT32_C(       448180), -INT32_C(       687279)},
           INT8_C(            1),
       {   INT64_C(1081355178971) } },
     { {   INT64_C(  15972296819) },
       {  -INT32_C(       166598) },
       {   INT32_C(       434007), -INT32_C(       332523)},
           INT8_C(            0),
       {  -INT64_C( 128637099553) } },
     { {  -INT64_C(  29112908142) },
       {  -INT32_C(       890217) },
       {  -INT32_C(       871566),  INT32_C(       183981)},
           INT8_C(            0),
       {   INT64_C(1522652831502) } },
     { {  -INT64_C(  66884081543) },
       {  -INT32_C(       358235) },
       {  -INT32_C(       199183),  INT32_C(       166087)},
           INT8_C(            0),
       {   INT64_C(  75824562467) } },
     { {  -INT64_C(  45375791253) },
       {   INT32_C(       471327) },
       {   INT32_C(       639915),  INT32_C(       825301)},
           INT8_C(            1),
       {   INT64_C( 732597497601) } },
     { {   INT64_C(  93826405589) },
       {  -INT32_C(        99269) },
       {  -INT32_C(       628747), -INT32_C(       507344)},
           INT8_C(            1),
       {   INT64_C( 194553468661) } },
     { {   INT64_C(  17271492226) },
       {  -INT32_C(       717291) },
       {   INT32_C(       310553), -INT32_C(       927821)},
           INT8_C(            0),
       {  -INT64_C( 428242251620) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    int64_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlals_lane_s32(test_vec[i].a[0], test_vec[i].b[0], v, 0); break;
      case 1: r = simde_vqdmlals_lane_s32(test_vec[i].a[0], test_vec[i].b[0], v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = 0; break;
    }

    simde_assert_equal_i64(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlalh_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[1];
    int16_t b[1];
    int16_t v[8];
    int8_t lane;
    int32_t r[1];
  } test_vec[] = {
     { {  -INT32_C( 128876435) },
       {   INT16_C(      8167) },
       {   INT16_C(      4367),  INT16_C(      5524),  INT16_C(      3500),  INT16_C(      7833),
          -INT16_C(      1658),  INT16_C(      5756), -INT16_C(      3725), -INT16_C(      7243)},
           INT8_C(         6),
       {  -INT32_C( 189720585) } },
     { {  -INT32_C( 832887394) },
       {  -INT16_C(      5992) },
       {   INT16_C(       718),  INT16_C(      1503), -INT16_C(      1635), -INT16_C(      9088),
           INT16_C(      2951),  INT16_C(      9114), -INT16_C(      2329),  INT16_C(      5502)},
           INT8_C(         5),
       {  -INT32_C( 942109570) } },
     { {  -INT32_C( 533589683) },
       {   INT16_C(      8157) },
       {  -INT16_C(       170), -INT16_C(      7579), -INT16_C(      5647), -INT16_C(      8798),
           INT16_C(      9007), -INT16_C(      1908),  INT16_C(      3466),  INT16_C(      1187)},
           INT8_C(         2),
       {  -INT32_C( 625714841) } },
     { {  -INT32_C( 312222225) },
       {  -INT16_C(      7476) },
       {  -INT16_C(      8422), -INT16_C(      5973),  INT16_C(      9555), -INT16_C(      2689),
           INT16_C(      9787), -INT16_C(      6417), -INT16_C(      2133),  INT16_C(      6433)},
           INT8_C(         2),
       {  -INT32_C( 455088585) } },
     { {   INT32_C( 317735354) },
       {   INT16_C(      8102) },
       {   INT16_C(      3790), -INT16_C(      8283), -INT16_C(      6754), -INT16_C(      8752),
          -INT16_C(      9863), -INT16_C(      1371),  INT16_C(      6147),  INT16_C(      2844)},
           INT8_C(         4),
       {   INT32_C( 157915302) } },
     { {   INT32_C( 141559338) },
       {   INT16_C(      8282) },
       {   INT16_C(      2436),  INT16_C(      4026),  INT16_C(      7400),  INT16_C(      3893),
          -INT16_C(      3891), -INT16_C(      8306),  INT16_C(      1775),  INT16_C(      6062)},
           INT8_C(         5),
       {   INT32_C(   3978754) } },
     { {  -INT32_C( 417376500) },
       {   INT16_C(      3995) },
       {   INT16_C(      5383),  INT16_C(      9262), -INT16_C(      5678),  INT16_C(      3658),
           INT16_C(      4019), -INT16_C(      9278), -INT16_C(      5962),  INT16_C(      9759)},
           INT8_C(         3),
       {  -INT32_C( 388149080) } },
     { {  -INT32_C( 753942094) },
       {   INT16_C(      6863) },
       {  -INT16_C(      2747), -INT16_C(      2461), -INT16_C(      4631),  INT16_C(      2782),
           INT16_C(      2898), -INT16_C(      6022),  INT16_C(      9230), -INT16_C(      3066)},
           INT8_C(         0),
       {  -INT32_C( 791647416) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    int32_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlalh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 0); break;
      case 1: r = simde_vqdmlalh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 1); break;
      case 2: r = simde_vqdmlalh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 2); break;
      case 3: r = simde_vqdmlalh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 3); break;
      case 4: r = simde_vqdmlalh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 4); break;
      case 5: r = simde_vqdmlalh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 5); break;
      case 6: r = simde_vqdmlalh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 6); break;
      case 7: r = simde_vqdmlalh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = 0; break;
    }

    simde_assert_equal_i32(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlals_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[1];
    int32_t b[1];
    int32_t v[4];
    int8_t lane;
    int64_t r[1];
  } test_vec[] = {
     { {  -INT64_C( 559402566429) },
       {  -INT32_C(       136817) },
       {   INT32_C(       972146),  INT32_C(       645928),  INT32_C(        80253), -INT32_C(        53618)},
           INT8_C(            2),
       {  -INT64_C( 581362515831) } },
     { {   INT64_C( 968324900099) },
       {  -INT32_C(       504386) },
       {   INT32_C(       754043), -INT32_C(       755209), -INT32_C(       264308), -INT32_C(       501739)},
           INT8_C(            3),
       {   INT64_C(1474465154607) } },
     { {  -INT64_C( 912937153168) },
       {   INT32_C(       562877) },
       {  -INT32_C(       738047), -INT32_C(       379351),  INT32_C(       248340), -INT32_C(       343121)},
           INT8_C(            0),
       {  -INT64_C(1743796515606) } },
     { {   INT64_C( 330634123075) },
       {  -INT32_C(       665378) },
       {  -INT32_C(       343916), -INT32_C(        12921), -INT32_C(       389835),  INT32_C(       753717)},
           INT8_C(            1),
       {   INT64_C( 347828821351) } },
     { {   INT64_C(  97780480309) },
       {  -INT32_C(       309734) },
       {   INT32_C(       174702), -INT32_C(       633437), -INT32_C(       801887),  INT32_C(        48250)},
           INT8_C(            3),
       {   INT64_C(  67891149309) } },
     { {  -INT64_C( 960108357320) },
       {  -INT32_C(       552347) },
       {   INT32_C(       199505),  INT32_C(       277114), -INT32_C(       377026), -INT32_C(       578807)},
           INT8_C(            2),
       {  -INT64_C( 543609997276) } },
     { {   INT64_C( 261824341322) },
       {   INT32_C(       531703) },
       {   INT32_C(       902495),  INT32_C(       897319), -INT32_C(       878787), -INT32_C(       407825)},
           INT8_C(            2),
       {  -INT64_C( 672683027200) } },
     { {   INT64_C( 147822779320) },
       {  -INT32_C(       289635) },
       {  -INT32_C(       217936), -INT32_C(       918247), -INT32_C(       237518), -INT32_C(        18738)},
           INT8_C(            0),
       {   INT64_C( 274066566040) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    int64_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlals_laneq_s32(test_vec[i].a[0], test_vec[i].b[0], v, 0); break;
      case 1: r = simde_vqdmlals_laneq_s32(test_vec[i].a[0], test_vec[i].b[0], v, 1); break;
      case 2: r = simde_vqdmlals_laneq_s32(test_vec[i].a[0], test_vec[i].b[0], v, 2); break;
      case 3: r = simde_vqdmlals_laneq_s32(test_vec[i].a[0], test_vec[i].b[0], v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = 0; break;
    }

    simde_assert_equal_i64(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlal_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C( 425772172), -INT32_C( 870450928), -INT32_C( 353638269),  INT32_C( 869320330) },
       {   INT16_C(      5757),  INT16_C(      3583), -INT16_C(      7892),  INT16_C(      5774) },
       {  -INT16_C(      6124), -INT16_C(      2665), -INT16_C(       748), -INT16_C(      4559)},
           INT8_C(         0),
       {  -INT32_C( 496283908), -INT32_C( 914335512), -INT32_C( 256977053),  INT32_C( 798600378) } },
     { {   INT32_C( 264890360), -INT32_C( 132935996), -INT32_C( 765529797), -INT32_C( 209964978) },
       {  -INT16_C(      6125), -INT16_C(      1669), -INT16_C(      9417), -INT16_C(      5662) },
       {  -INT16_C(      4094), -INT16_C(      4945),  INT16_C(      1153), -INT16_C(      1279)},
           INT8_C(         2),
       {   INT32_C( 250766110), -INT32_C( 136784710), -INT32_C( 787245399), -INT32_C( 223021550) } },
     { {  -INT32_C( 687037777),  INT32_C(    350547), -INT32_C( 917055825),  INT32_C( 467930951) },
       {   INT16_C(         8), -INT16_C(      7260), -INT16_C(      7320),  INT16_C(      6398) },
       {   INT16_C(      2317),  INT16_C(      2456),  INT16_C(      3713), -INT16_C(      8705)},
           INT8_C(         3),
       {  -INT32_C( 687177057),  INT32_C( 126747147), -INT32_C( 789614625),  INT32_C( 356541771) } },
     { {   INT32_C( 831645449), -INT32_C( 458276988), -INT32_C( 533944055), -INT32_C( 897913350) },
       {   INT16_C(      2766),  INT16_C(      6819),  INT16_C(       570), -INT16_C(      6948) },
       {   INT16_C(      7445),  INT16_C(      6907),  INT16_C(      2870),  INT16_C(      4578)},
           INT8_C(         2),
       {   INT32_C( 847522289), -INT32_C( 419135928), -INT32_C( 530672255), -INT32_C( 937794870) } },
     { {   INT32_C( 215114780),  INT32_C( 289582821), -INT32_C( 183295087),  INT32_C( 400458546) },
       {  -INT16_C(      4761), -INT16_C(      5175), -INT16_C(      7164), -INT16_C(      9471) },
       {   INT16_C(      2309), -INT16_C(      9504),  INT16_C(      2390), -INT16_C(       501)},
           INT8_C(         3),
       {   INT32_C( 219885302),  INT32_C( 294768171), -INT32_C( 176116759),  INT32_C( 409948488) } },
     { {  -INT32_C( 228273077), -INT32_C( 573738564),  INT32_C( 805346111),  INT32_C( 451542412) },
       {   INT16_C(      5915), -INT16_C(      5948), -INT16_C(      5277), -INT16_C(      1081) },
       {  -INT16_C(      3952), -INT16_C(      8119), -INT16_C(      3455), -INT16_C(      3040)},
           INT8_C(         3),
       {  -INT32_C( 264236277), -INT32_C( 537574724),  INT32_C( 837430271),  INT32_C( 458114892) } },
     { {   INT32_C( 814789159), -INT32_C( 815174192),  INT32_C( 796268231), -INT32_C( 450444009) },
       {  -INT16_C(      7389),  INT16_C(      8929),  INT16_C(      9568),  INT16_C(      9997) },
       {  -INT16_C(      8028),  INT16_C(       586), -INT16_C(      5375), -INT16_C(      1471)},
           INT8_C(         1),
       {   INT32_C( 806129251), -INT32_C( 804709404),  INT32_C( 807481927), -INT32_C( 438727525) } },
     { {  -INT32_C( 765711601),  INT32_C( 489237452), -INT32_C( 297322404), -INT32_C( 918947291) },
       {  -INT16_C(      5434),  INT16_C(       495),  INT16_C(      8036), -INT16_C(      9574) },
       {  -INT16_C(      7119), -INT16_C(      6426),  INT16_C(      5367), -INT16_C(      6430)},
           INT8_C(         3),
       {  -INT32_C( 695830361),  INT32_C( 482871752), -INT32_C( 400665364), -INT32_C( 795825651) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int32x4_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlal_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqdmlal_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqdmlal_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqdmlal_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s32(0); break;
    }

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlal_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t v[2];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {  -INT64_C( 589163751624),  INT64_C( 429706216903) },
       {   INT32_C(          397), -INT32_C(       957326) },
       {  -INT32_C(       883062), -INT32_C(       410472)},
           INT8_C(            0),
       {  -INT64_C( 589864902852),  INT64_C(2120462641327) } },
     { {  -INT64_C( 656392608678), -INT64_C( 503973207746) },
       {  -INT32_C(       848069),  INT32_C(       771551) },
       {  -INT32_C(       629006),  INT32_C(       576960)},
           INT8_C(            1),
       {  -INT64_C(1634996389158),  INT64_C( 386334922174) } },
     { {  -INT64_C(  95263852864),  INT64_C( 665780368583) },
       {   INT32_C(       603158),  INT32_C(       943104) },
       {   INT32_C(       202514),  INT32_C(         9210)},
           INT8_C(            0),
       {   INT64_C( 149032025560),  INT64_C(1047763895495) } },
     { {   INT64_C( 126598555336),  INT64_C( 273800393016) },
       {   INT32_C(       526071), -INT32_C(       456475) },
       {  -INT32_C(        63146), -INT32_C(       989530)},
           INT8_C(            0),
       {   INT64_C(  60159996604),  INT64_C( 331449533716) } },
     { {   INT64_C( 524521550518), -INT64_C( 231467718925) },
       {   INT32_C(       386981),  INT32_C(       504150) },
       {  -INT32_C(       444746),  INT32_C(       421317)},
           INT8_C(            1),
       {   INT64_C( 850604898472),  INT64_C( 193346212175) } },
     { {   INT64_C( 761045675378), -INT64_C( 119396145499) },
       {  -INT32_C(       718853),  INT32_C(       835642) },
       {   INT32_C(       976927),  INT32_C(        57882)},
           INT8_C(            0),
       {  -INT64_C( 643488134084),  INT64_C(1513326318769) } },
     { {  -INT64_C( 342414590564), -INT64_C( 156288463020) },
       {  -INT32_C(       618980), -INT32_C(       442132) },
       {   INT32_C(       799522), -INT32_C(        56231)},
           INT8_C(            0),
       {  -INT64_C(1332190845684), -INT64_C( 863276984828) } },
     { {   INT64_C( 464983707360),  INT64_C( 656959310680) },
       {  -INT32_C(       986179), -INT32_C(       571141) },
       {   INT32_C(       961008), -INT32_C(        49136)},
           INT8_C(            1),
       {   INT64_C( 561897490048),  INT64_C( 713086479032) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int64x2_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlal_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqdmlal_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s64(0); break;
    }

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlal_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t v[8];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {   INT32_C( 568155650),  INT32_C( 543219523),  INT32_C( 939396263), -INT32_C( 713646577) },
       {  -INT16_C(      3287),  INT16_C(      7702), -INT16_C(       304), -INT16_C(      7258) },
       {  -INT16_C(       421),  INT16_C(      9798),  INT16_C(      7292),  INT16_C(      3391),
          -INT16_C(      4377),  INT16_C(      6560),  INT16_C(      6599),  INT16_C(      6832)},
           INT8_C(         1),
       {   INT32_C( 503743598),  INT32_C( 694147915),  INT32_C( 933439079), -INT32_C( 855874345) } },
     { {  -INT32_C( 851965500),  INT32_C( 262689683),  INT32_C( 937835367), -INT32_C( 937323231) },
       {  -INT16_C(      9936),  INT16_C(      9725),  INT16_C(      5485),  INT16_C(      1635) },
       {  -INT16_C(      1806), -INT16_C(      1922), -INT16_C(      2032),  INT16_C(      6913),
          -INT16_C(      1575), -INT16_C(      3999),  INT16_C(      5066),  INT16_C(       755)},
           INT8_C(         2),
       {  -INT32_C( 811585596),  INT32_C( 223167283),  INT32_C( 915544327), -INT32_C( 943967871) } },
     { {  -INT32_C( 476015894),  INT32_C( 407431452), -INT32_C( 336240585), -INT32_C( 353356841) },
       {   INT16_C(      8127), -INT16_C(      1357),  INT16_C(      1858),  INT16_C(       944) },
       {  -INT16_C(      6845),  INT16_C(      9162),  INT16_C(      8682),  INT16_C(      4334),
          -INT16_C(      3185), -INT16_C(      9666),  INT16_C(      8724),  INT16_C(      7844)},
           INT8_C(         4),
       {  -INT32_C( 527784884),  INT32_C( 416075542), -INT32_C( 348076045), -INT32_C( 359370121) } },
     { {  -INT32_C( 485224282),  INT32_C( 706288413),  INT32_C( 346759391), -INT32_C( 394498051) },
       {   INT16_C(      2755), -INT16_C(      2327),  INT16_C(      3952),  INT16_C(      2153) },
       {  -INT16_C(      8066),  INT16_C(       299), -INT16_C(      1666),  INT16_C(      5037),
           INT16_C(       626), -INT16_C(      6025),  INT16_C(      8365),  INT16_C(      6783)},
           INT8_C(         2),
       {  -INT32_C( 494403942),  INT32_C( 714041977),  INT32_C( 333591327), -INT32_C( 401671847) } },
     { {  -INT32_C( 735474031), -INT32_C( 433366471),  INT32_C( 857935216), -INT32_C( 171303334) },
       {  -INT16_C(       656),  INT16_C(      8961),  INT16_C(      7026), -INT16_C(      8637) },
       {  -INT16_C(      3899),  INT16_C(      3332),  INT16_C(      4545),  INT16_C(      6918),
          -INT16_C(      8654),  INT16_C(      2094), -INT16_C(      8807), -INT16_C(      5700)},
           INT8_C(         6),
       {  -INT32_C( 723919247), -INT32_C( 591205525),  INT32_C( 734179252), -INT32_C(  19171216) } },
     { {   INT32_C( 857914823),  INT32_C( 134100517), -INT32_C( 671734036), -INT32_C( 821625611) },
       {   INT16_C(      2826), -INT16_C(      2892), -INT16_C(      3258),  INT16_C(      2609) },
       {  -INT16_C(      8207),  INT16_C(      2510),  INT16_C(      6448), -INT16_C(      4161),
          -INT16_C(      2965), -INT16_C(      4560), -INT16_C(      9611), -INT16_C(      1543)},
           INT8_C(         5),
       {   INT32_C( 832141703),  INT32_C( 160475557), -INT32_C( 642021076), -INT32_C( 845419691) } },
     { {   INT32_C( 180325523),  INT32_C( 618326408), -INT32_C( 602592055), -INT32_C( 884991036) },
       {   INT16_C(       263), -INT16_C(      6743),  INT16_C(      7649), -INT16_C(      9877) },
       {   INT16_C(      4276), -INT16_C(      5506), -INT16_C(      6679),  INT16_C(      7635),
           INT16_C(      6643), -INT16_C(       419),  INT16_C(      6279), -INT16_C(      5078)},
           INT8_C(         5),
       {   INT32_C( 180105129),  INT32_C( 623977042), -INT32_C( 609001917), -INT32_C( 876714110) } },
     { {   INT32_C( 994862348), -INT32_C( 973583462), -INT32_C( 498991883),  INT32_C( 730031301) },
       {   INT16_C(      6654),  INT16_C(      3001),  INT16_C(       265), -INT16_C(      4764) },
       {   INT16_C(      5869), -INT16_C(      4638),  INT16_C(      6797),  INT16_C(      7920),
          -INT16_C(      7423),  INT16_C(      3231), -INT16_C(      6303),  INT16_C(      9659)},
           INT8_C(         6),
       {   INT32_C( 910982024), -INT32_C(1011414068), -INT32_C( 502332473),  INT32_C( 790086285) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int32x4_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlal_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqdmlal_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqdmlal_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqdmlal_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqdmlal_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqdmlal_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqdmlal_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqdmlal_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s32(0); break;
    }

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlal_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t v[4];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(  86143499926),  INT64_C(  10686042104) },
       {   INT32_C(       597840),  INT32_C(       362874) },
       {   INT32_C(        15572), -INT32_C(       288916), -INT32_C(       180511), -INT32_C(       121773)},
           INT8_C(            0),
       {   INT64_C( 104762628886),  INT64_C(  21987389960) } },
     { {   INT64_C(  70923230602),  INT64_C(  22590881023) },
       {   INT32_C(       491373), -INT32_C(       871823) },
       {   INT32_C(        48311),  INT32_C(       196262),  INT32_C(       730961),  INT32_C(       909459)},
           INT8_C(            2),
       {   INT64_C( 789272229508), -INT64_C(1251946342783) } },
     { {   INT64_C(  23973086943), -INT64_C(  44722868031) },
       {  -INT32_C(       898633), -INT32_C(       887236) },
       {   INT32_C(       659525), -INT32_C(        85043), -INT32_C(        38786),  INT32_C(        50165)},
           INT8_C(            1),
       {   INT64_C( 176817979381),  INT64_C( 106183554265) } },
     { {   INT64_C(  18816198374),  INT64_C(   4696687039) },
       {   INT32_C(       338910),  INT32_C(       598815) },
       {  -INT32_C(       787473),  INT32_C(       671299), -INT32_C(       254311),  INT32_C(       797400)},
           INT8_C(            3),
       {   INT64_C( 559309866374),  INT64_C( 959686849039) } },
     { {   INT64_C(  23088482966), -INT64_C(  37015946585) },
       {  -INT32_C(       664356),  INT32_C(       501139) },
       {  -INT32_C(       892684), -INT32_C(       991933),  INT32_C(       599568),  INT32_C(       259352)},
           INT8_C(            2),
       {  -INT64_C( 773564713450),  INT64_C( 563917869319) } },
     { {  -INT64_C(  81827515540),  INT64_C(  77367027948) },
       {  -INT32_C(       160156),  INT32_C(       198091) },
       {   INT32_C(       635010),  INT32_C(       938868),  INT32_C(       465028),  INT32_C(       201136)},
           INT8_C(            2),
       {  -INT64_C( 230781564276),  INT64_C( 261602751044) } },
     { {   INT64_C(  72614402642),  INT64_C(  71956458345) },
       {   INT32_C(       548307),  INT32_C(       359931) },
       {   INT32_C(        77396),  INT32_C(       201469), -INT32_C(       468037),  INT32_C(       993136)},
           INT8_C(            1),
       {   INT64_C( 293548128608),  INT64_C( 216986335623) } },
     { {   INT64_C(  54757095308), -INT64_C(  78647681491) },
       {  -INT32_C(       391360),  INT32_C(       956876) },
       {  -INT32_C(        57677), -INT32_C(       975727),  INT32_C(       913570),  INT32_C(       949988)},
           INT8_C(            0),
       {   INT64_C(  99902036748), -INT64_C( 189027155595) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int64x2_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlal_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqdmlal_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqdmlal_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqdmlal_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s64(0); break;
    }

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlalh_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlals_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlalh_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlals_laneq_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
