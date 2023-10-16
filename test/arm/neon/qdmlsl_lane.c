#define SIMDE_TEST_ARM_NEON_INSN qdmlsl_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlsl_lane.h"

SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vqdmlslh_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[1];
    int16_t b[1];
    int16_t v[4];
    int8_t lane;
    int32_t r[1];
  } test_vec[] = {
     { {  -INT32_C(  521768223) },
       {  -INT16_C(       1891) },
       {   INT16_C(       4436),  INT16_C(       3105), -INT16_C(       2887),  INT16_C(       1765)},
           INT8_C(          2),
       {  -INT32_C(  532686857) } },
     { {   INT32_C(  958870647) },
       {   INT16_C(       3721) },
       {   INT16_C(       7881), -INT16_C(       4769),  INT16_C(        862), -INT16_C(       5799)},
           INT8_C(          2),
       {   INT32_C(  952455643) } },
     { {   INT32_C(  596132412) },
       {   INT16_C(        845) },
       {  -INT16_C(       6428),  INT16_C(       9822), -INT16_C(       9929),  INT16_C(       7367)},
           INT8_C(          2),
       {   INT32_C(  612912422) } },
     { {  -INT32_C(  230553326) },
       {   INT16_C(       7874) },
       {  -INT16_C(       5546),  INT16_C(       7556), -INT16_C(       3520), -INT16_C(       2713)},
           INT8_C(          0),
       {  -INT32_C(  143214918) } },
     { {   INT32_C(  851397549) },
       {   INT16_C(        333) },
       {   INT16_C(       8762), -INT16_C(       4955),  INT16_C(       3059),  INT16_C(       7156)},
           INT8_C(          3),
       {   INT32_C(  846631653) } },
     { {   INT32_C(  476045229) },
       {   INT16_C(       3731) },
       {  -INT16_C(       6899), -INT16_C(       5316), -INT16_C(       5132),  INT16_C(       2354)},
           INT8_C(          3),
       {   INT32_C(  458479681) } },
     { {  -INT32_C(    8428601) },
       {  -INT16_C(       7758) },
       {  -INT16_C(       3068), -INT16_C(       1053), -INT16_C(       5872),  INT16_C(       5349)},
           INT8_C(          0),
       {  -INT32_C(   56031689) } },
     { {   INT32_C(  391924831) },
       {  -INT16_C(        575) },
       {   INT16_C(       7185), -INT16_C(       7316), -INT16_C(       2257),  INT16_C(       3710)},
           INT8_C(          3),
       {   INT32_C(  396191331) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    int32_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlslh_lane_s16(test_vec[i].a[0], test_vec[i].b[0], v, 0); break;
      case 1: r = simde_vqdmlslh_lane_s16(test_vec[i].a[0], test_vec[i].b[0], v, 1); break;
      case 2: r = simde_vqdmlslh_lane_s16(test_vec[i].a[0], test_vec[i].b[0], v, 2); break;
      case 3: r = simde_vqdmlslh_lane_s16(test_vec[i].a[0], test_vec[i].b[0], v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = 0; break;
    }

    simde_assert_equal_i32(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlsls_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[1];
    int32_t b[1];
    int32_t v[2];
    int8_t lane;
    int64_t r[1];
  } test_vec[] = {
     { {  -INT64_C(   17908307265) },
       {  -INT32_C(        901936) },
       {   INT32_C(        494783), -INT32_C(        387685)},
           INT8_C(             0),
       {   INT64_C(  874616892511) } },
     { {  -INT64_C(  301361331707) },
       {  -INT32_C(        564541) },
       {  -INT32_C(        210620),  INT32_C(        132803)},
           INT8_C(             1),
       {  -INT64_C(  151415854861) } },
     { {  -INT64_C(  970902083330) },
       {  -INT32_C(        541204) },
       {   INT32_C(        568552), -INT32_C(        652520)},
           INT8_C(             0),
       {  -INT64_C(  355496850114) } },
     { {  -INT64_C(  909008067967) },
       {  -INT32_C(        316442) },
       {   INT32_C(        262937), -INT32_C(        816748)},
           INT8_C(             0),
       {  -INT64_C(  742599447659) } },
     { {   INT64_C(  254776768658) },
       {   INT32_C(        405732) },
       {   INT32_C(        689187), -INT32_C(        933829)},
           INT8_C(             0),
       {  -INT64_C(  304473671110) } },
     { {  -INT64_C(  445641548478) },
       {   INT32_C(        520506) },
       {   INT32_C(        918585),  INT32_C(        262103)},
           INT8_C(             0),
       {  -INT64_C( 1401899556498) } },
     { {   INT64_C(  325969795255) },
       {  -INT32_C(        621275) },
       {  -INT32_C(        363058),  INT32_C(        155048)},
           INT8_C(             1),
       {   INT64_C(  518624687655) } },
     { {  -INT64_C(  684284349157) },
       {   INT32_C(        663436) },
       {   INT32_C(        158891), -INT32_C(          5388)},
           INT8_C(             1),
       {  -INT64_C(  677135162821) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    int64_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlsls_lane_s32(test_vec[i].a[0], test_vec[i].b[0], v, 0); break;
      case 1: r = simde_vqdmlsls_lane_s32(test_vec[i].a[0], test_vec[i].b[0], v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = 0; break;
    }

    simde_assert_equal_i64(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlslh_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[1];
    int16_t b[1];
    int16_t v[8];
    int8_t lane;
    int32_t r[1];
  } test_vec[] = {
     { {  -INT32_C(  939501449) },
       {  -INT16_C(       4649) },
       {   INT16_C(       6426),  INT16_C(       6519), -INT16_C(       3709),  INT16_C(       4272),
           INT16_C(       5523), -INT16_C(       3752), -INT16_C(       8267), -INT16_C(       5596)},
           INT8_C(          5),
       {  -INT32_C(  974387545) } },
     { {   INT32_C(   67701807) },
       {  -INT16_C(         95) },
       {   INT16_C(       4742),  INT16_C(        715),  INT16_C(       9336),  INT16_C(       1391),
           INT16_C(       2321), -INT16_C(        362), -INT16_C(       7284), -INT16_C(       5872)},
           INT8_C(          6),
       {   INT32_C(   66317847) } },
     { {  -INT32_C(  459149237) },
       {  -INT16_C(       2172) },
       {   INT16_C(        174), -INT16_C(       5623),  INT16_C(        484),  INT16_C(       1234),
          -INT16_C(       2341), -INT16_C(       5297), -INT16_C(       6531), -INT16_C(       6876)},
           INT8_C(          3),
       {  -INT32_C(  453788741) } },
     { {   INT32_C(  152555937) },
       {  -INT16_C(       9984) },
       {   INT16_C(        501),  INT16_C(       3250), -INT16_C(       5883), -INT16_C(       2978),
          -INT16_C(       4675),  INT16_C(       5875), -INT16_C(       6413), -INT16_C(       6884)},
           INT8_C(          1),
       {   INT32_C(  217451937) } },
     { {   INT32_C(  903005488) },
       {  -INT16_C(       8056) },
       {  -INT16_C(       2229),  INT16_C(       4275),  INT16_C(       6721), -INT16_C(       9742),
           INT16_C(       8103), -INT16_C(       3583), -INT16_C(       2568),  INT16_C(       4540)},
           INT8_C(          4),
       {   INT32_C( 1033561024) } },
     { {  -INT32_C(  788810551) },
       {   INT16_C(       7749) },
       {   INT16_C(       6311), -INT16_C(       3808),  INT16_C(       3622),  INT16_C(        344),
           INT16_C(       1495), -INT16_C(        126), -INT16_C(       1394), -INT16_C(       5015)},
           INT8_C(          5),
       {  -INT32_C(  786857803) } },
     { {  -INT32_C(  941983580) },
       {   INT16_C(       3786) },
       {  -INT16_C(       9783),  INT16_C(       7609),  INT16_C(       7290), -INT16_C(       7255),
           INT16_C(       8817),  INT16_C(       8016), -INT16_C(       8645), -INT16_C(       7114)},
           INT8_C(          2),
       {  -INT32_C(  997183460) } },
     { {  -INT32_C(  768054624) },
       {   INT16_C(       6573) },
       {  -INT16_C(       3944),  INT16_C(       1034), -INT16_C(       8121),  INT16_C(       9965),
           INT16_C(       6007), -INT16_C(        748), -INT16_C(       8042), -INT16_C(       6337)},
           INT8_C(          1),
       {  -INT32_C(  781647588) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    int32_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlslh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 0); break;
      case 1: r = simde_vqdmlslh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 1); break;
      case 2: r = simde_vqdmlslh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 2); break;
      case 3: r = simde_vqdmlslh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 3); break;
      case 4: r = simde_vqdmlslh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 4); break;
      case 5: r = simde_vqdmlslh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 5); break;
      case 6: r = simde_vqdmlslh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 6); break;
      case 7: r = simde_vqdmlslh_laneq_s16(test_vec[i].a[0], test_vec[i].b[0], v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = 0; break;
    }

    simde_assert_equal_i32(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlsls_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[1];
    int32_t b[1];
    int32_t v[4];
    int8_t lane;
    int64_t r[1];
  } test_vec[] = {
     { {  -INT64_C(  500450126315) },
       {   INT32_C(        524413) },
       {  -INT32_C(        742918),  INT32_C(        466620),  INT32_C(        225935), -INT32_C(        166188)},
           INT8_C(             1),
       {  -INT64_C(  989853314435) } },
     { {  -INT64_C(  132211311684) },
       {   INT32_C(        403420) },
       {  -INT32_C(        690715),  INT32_C(        295053),  INT32_C(        615254),  INT32_C(        965539)},
           INT8_C(             0),
       {   INT64_C(  425085178916) } },
     { {   INT64_C(  829159715571) },
       {  -INT32_C(        818481) },
       {   INT32_C(        296998), -INT32_C(        936881),  INT32_C(        516497),  INT32_C(        655216)},
           INT8_C(             3),
       {   INT64_C( 1901723409363) } },
     { {  -INT64_C(  538012455356) },
       {  -INT32_C(        534254) },
       {   INT32_C(        237258),  INT32_C(        190484), -INT32_C(         87731), -INT32_C(        580229)},
           INT8_C(             2),
       {  -INT64_C(  631753730704) } },
     { {  -INT64_C(   86569196546) },
       {   INT32_C(        634638) },
       {   INT32_C(        249039), -INT32_C(        868967), -INT32_C(        513773), -INT32_C(        660315)},
           INT8_C(             3),
       {   INT64_C(  751552785394) } },
     { {  -INT64_C(  421340522093) },
       {  -INT32_C(        625640) },
       {   INT32_C(        950739),  INT32_C(        725055),  INT32_C(        936872), -INT32_C(        330093)},
           INT8_C(             2),
       {   INT64_C(  750948674067) } },
     { {  -INT64_C(  352349278764) },
       {  -INT32_C(        619512) },
       {   INT32_C(        446726),  INT32_C(        703647),  INT32_C(        180352),  INT32_C(        457912)},
           INT8_C(             1),
       {   INT64_C(  519486241764) } },
     { {  -INT64_C(  881661908384) },
       {  -INT32_C(        171477) },
       {  -INT32_C(        467044), -INT32_C(        608804), -INT32_C(        160391), -INT32_C(        839703)},
           INT8_C(             1),
       {  -INT64_C( 1090453675400) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    int64_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlsls_laneq_s32(test_vec[i].a[0], test_vec[i].b[0], v, 0); break;
      case 1: r = simde_vqdmlsls_laneq_s32(test_vec[i].a[0], test_vec[i].b[0], v, 1); break;
      case 2: r = simde_vqdmlsls_laneq_s32(test_vec[i].a[0], test_vec[i].b[0], v, 2); break;
      case 3: r = simde_vqdmlsls_laneq_s32(test_vec[i].a[0], test_vec[i].b[0], v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = 0; break;
    }

    simde_assert_equal_i64(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlsl_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(  621980471), -INT32_C(  848186675), -INT32_C(  509036072),  INT32_C(  748012096) },
       {  -INT16_C(       9060), -INT16_C(       7835),  INT16_C(       5740),  INT16_C(       7999) },
       {  -INT16_C(       3714),  INT16_C(       8214), -INT16_C(       7570), -INT16_C(       6376)},
           INT8_C(          3),
       {  -INT32_C(  737513591), -INT32_C(  948098595), -INT32_C(  435839592),  INT32_C(  850015344) } },
     { {   INT32_C(  701138315),  INT32_C(  599017440),  INT32_C(  406294106),  INT32_C(  912157267) },
       {  -INT16_C(       8720), -INT16_C(       9909), -INT16_C(       3317), -INT16_C(       9314) },
       {   INT16_C(       4644),  INT16_C(       6314),  INT16_C(       8460),  INT16_C(       9616)},
           INT8_C(          2),
       {   INT32_C(  848680715),  INT32_C(  766677720),  INT32_C(  462417746),  INT32_C( 1069750147) } },
     { {   INT32_C(  832658663), -INT32_C(  214972206),  INT32_C(  752911172), -INT32_C(  348332696) },
       {   INT16_C(       7944),  INT16_C(       4659), -INT16_C(       5401),  INT16_C(       6379) },
       {  -INT16_C(       1071), -INT16_C(       9321),  INT16_C(       8232), -INT16_C(       4878)},
           INT8_C(          3),
       {   INT32_C(  910160327), -INT32_C(  169519002),  INT32_C(  700219016), -INT32_C(  286099172) } },
     { {   INT32_C(  635065763),  INT32_C(  340022238), -INT32_C(  340772832), -INT32_C(  659109761) },
       {   INT16_C(       9265),  INT16_C(       9751),  INT16_C(       9161), -INT16_C(       4242) },
       {   INT16_C(       6611), -INT16_C(       4974), -INT16_C(       9605), -INT16_C(       7983)},
           INT8_C(          1),
       {   INT32_C(  727233983),  INT32_C(  437025186), -INT32_C(  249639204), -INT32_C(  701309177) } },
     { {   INT32_C(  489256195), -INT32_C(  915698286),  INT32_C(   19849451),  INT32_C(  925310967) },
       {   INT16_C(       2139),  INT16_C(       1927),  INT16_C(        954),  INT16_C(       4965) },
       {   INT16_C(       5661), -INT16_C(       1116),  INT16_C(       7688), -INT16_C(       3366)},
           INT8_C(          1),
       {   INT32_C(  494030443), -INT32_C(  911397222),  INT32_C(   21978779),  INT32_C(  936392847) } },
     { {   INT32_C(  375425665), -INT32_C(  850941037),  INT32_C(  673625225),  INT32_C(  992218818) },
       {   INT16_C(       8491),  INT16_C(       1184), -INT16_C(       8612), -INT16_C(       5764) },
       {  -INT16_C(       1111),  INT16_C(       9806), -INT16_C(       5898),  INT16_C(       1455)},
           INT8_C(          3),
       {   INT32_C(  350716855), -INT32_C(  854386477),  INT32_C(  698686145),  INT32_C( 1008992058) } },
     { {  -INT32_C(  244188012),  INT32_C(  236430154),  INT32_C(  959399976), -INT32_C(  587410301) },
       {   INT16_C(       1313),  INT16_C(       6408), -INT16_C(       6082),  INT16_C(       3305) },
       {   INT16_C(       5128), -INT16_C(       3587), -INT16_C(       7384), -INT16_C(        299)},
           INT8_C(          2),
       {  -INT32_C(  224797628),  INT32_C(  331063498),  INT32_C(  869581000), -INT32_C(  538602061) } },
     { {  -INT32_C(  439264700),  INT32_C(  924081299),  INT32_C(  127569051),  INT32_C(  914997609) },
       {  -INT16_C(        430),  INT16_C(       3269),  INT16_C(       5140),  INT16_C(       7867) },
       {  -INT16_C(       3308),  INT16_C(       7584),  INT16_C(       3613),  INT16_C(       1332)},
           INT8_C(          2),
       {  -INT32_C(  436157520),  INT32_C(  900459505),  INT32_C(   90427411),  INT32_C(  858150667) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int32x4_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlsl_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqdmlsl_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqdmlsl_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqdmlsl_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s32(0); break;
    }

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlsl_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t v[2];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(  358287139107),  INT64_C(  431713426998) },
       {   INT32_C(        965537),  INT32_C(        901602) },
       {   INT32_C(        553527),  INT32_C(        592565)},
           INT8_C(             1),
       {  -INT64_C(  785999725703), -INT64_C(  636802151262) } },
     { {   INT64_C(  673223528167),  INT64_C(  297497561012) },
       {  -INT32_C(        449165),  INT32_C(        858137) },
       {  -INT32_C(        242074), -INT32_C(        654769)},
           INT8_C(             1),
       {   INT64_C(   85024892397),  INT64_C( 1421260571718) } },
     { {  -INT64_C(  388620023028), -INT64_C(  263834014828) },
       {  -INT32_C(         23441), -INT32_C(        106279) },
       {  -INT32_C(        574815),  INT32_C(        419135)},
           INT8_C(             0),
       {  -INT64_C(  415568499858), -INT64_C(  386015541598) } },
     { {   INT64_C(  951671555991),  INT64_C(  736051930158) },
       {   INT32_C(        807824),  INT32_C(        478972) },
       {   INT32_C(        611136),  INT32_C(        507977)},
           INT8_C(             0),
       {  -INT64_C(   35709100137),  INT64_C(  150617865774) } },
     { {  -INT64_C(  191997325980), -INT64_C(  306244833898) },
       {  -INT32_C(        506328),  INT32_C(        665384) },
       {   INT32_C(        765803), -INT32_C(        873513)},
           INT8_C(             1),
       {  -INT64_C( 1076565506508),  INT64_C(  856198314086) } },
     { {   INT64_C(  750098780084), -INT64_C(  354288298011) },
       {  -INT32_C(        755871), -INT32_C(        477052) },
       {   INT32_C(        218455), -INT32_C(          2723)},
           INT8_C(             1),
       {   INT64_C(  745982306618), -INT64_C(  356886323203) } },
     { {  -INT64_C(  572018600681), -INT64_C(  948099495092) },
       {  -INT32_C(        451512),  INT32_C(        380722) },
       {  -INT32_C(        372983), -INT32_C(        375407)},
           INT8_C(             0),
       {  -INT64_C(  908831201273), -INT64_C(  664093827640) } },
     { {   INT64_C(  801129221619), -INT64_C(  673441488474) },
       {   INT32_C(        868112),  INT32_C(         30583) },
       {  -INT32_C(        495740), -INT32_C(        746578)},
           INT8_C(             0),
       {   INT64_C( 1661844907379), -INT64_C(  643119055634) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int64x2_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlsl_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqdmlsl_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s64(0); break;
    }

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlsl_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t v[8];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {   INT32_C(  576260820),  INT32_C(  326390657), -INT32_C(  621853039), -INT32_C(  884742225) },
       {   INT16_C(       2818),  INT16_C(       6712),  INT16_C(       5722),  INT16_C(       4321) },
       {   INT16_C(       6648),  INT16_C(       8790),  INT16_C(       6169), -INT16_C(       6194),
          -INT16_C(       1520), -INT16_C(       9622), -INT16_C(       3104),  INT16_C(       8027)},
           INT8_C(          2),
       {   INT32_C(  541492336),  INT32_C(  243578001), -INT32_C(  692451075), -INT32_C(  938054723) } },
     { {  -INT32_C(  697467647),  INT32_C(  598941739), -INT32_C(  363565604),  INT32_C(  526836150) },
       {   INT16_C(       6695), -INT16_C(       3263),  INT16_C(       2485),  INT16_C(       2450) },
       {  -INT16_C(       5334), -INT16_C(       2962),  INT16_C(        702),  INT16_C(       3354),
          -INT16_C(       8399),  INT16_C(       4470),  INT16_C(       8232),  INT16_C(       1471)},
           INT8_C(          1),
       {  -INT32_C(  657806467),  INT32_C(  579611727), -INT32_C(  348844464),  INT32_C(  541349950) } },
     { {   INT32_C(   16745378), -INT32_C(  643200730), -INT32_C(  553632268),  INT32_C(  662966256) },
       {  -INT16_C(         68),  INT16_C(       3722),  INT16_C(       2403),  INT16_C(       5102) },
       {  -INT16_C(        302), -INT16_C(       5801),  INT16_C(        591), -INT16_C(       1556),
          -INT16_C(       5794),  INT16_C(       1883), -INT16_C(       1143),  INT16_C(       8514)},
           INT8_C(          3),
       {   INT32_C(   16533762), -INT32_C(  631617866), -INT32_C(  546154132),  INT32_C(  678843680) } },
     { {  -INT32_C(  427278683), -INT32_C(  105903585),  INT32_C(   41252604), -INT32_C(  318817836) },
       {  -INT16_C(       7528), -INT16_C(       2955), -INT16_C(       7668),  INT16_C(       3010) },
       {   INT16_C(       6156),  INT16_C(       9935),  INT16_C(       7913),  INT16_C(       4232),
          -INT16_C(       4512),  INT16_C(       6480), -INT16_C(       5793),  INT16_C(       7771)},
           INT8_C(          3),
       {  -INT32_C(  363561691), -INT32_C(   80892465),  INT32_C(  106154556), -INT32_C(  344294476) } },
     { {   INT32_C(   88945249), -INT32_C(  272013243),  INT32_C(  678093194),  INT32_C(  755403207) },
       {   INT16_C(       6957), -INT16_C(       2125),  INT16_C(       3610), -INT16_C(       4205) },
       {  -INT16_C(       5280), -INT16_C(       6119),  INT16_C(       3261),  INT16_C(       4591),
          -INT16_C(       9342), -INT16_C(       9870),  INT16_C(        939), -INT16_C(       7955)},
           INT8_C(          6),
       {   INT32_C(   75880003), -INT32_C(  268022493),  INT32_C(  671313614),  INT32_C(  763300197) } },
     { {   INT32_C(  693892333), -INT32_C(  781710600),  INT32_C(  285172511),  INT32_C(  809047430) },
       {  -INT16_C(        214),  INT16_C(       7779),  INT16_C(       6711),  INT16_C(       8023) },
       {  -INT16_C(       5595),  INT16_C(       9254),  INT16_C(       5893),  INT16_C(       3207),
           INT16_C(       6157), -INT16_C(       1793), -INT16_C(       3084),  INT16_C(       6516)},
           INT8_C(          5),
       {   INT32_C(  693124929), -INT32_C(  753815106),  INT32_C(  309238157),  INT32_C(  837817908) } },
     { {  -INT32_C(  403691731),  INT32_C(  112238564), -INT32_C(  325269856), -INT32_C(  967736266) },
       {  -INT16_C(       6885), -INT16_C(       7784), -INT16_C(       6629),  INT16_C(       7601) },
       {   INT16_C(       6518),  INT16_C(       1723), -INT16_C(       2663),  INT16_C(       4164),
           INT16_C(       8103), -INT16_C(       4645), -INT16_C(       7864),  INT16_C(       9689)},
           INT8_C(          3),
       {  -INT32_C(  346353451),  INT32_C(  177063716), -INT32_C(  270063544), -INT32_C( 1031037394) } },
     { {  -INT32_C(  570543552),  INT32_C(   27439576), -INT32_C(  819157093),  INT32_C(  278644282) },
       {   INT16_C(       6777), -INT16_C(       9799),  INT16_C(       5995), -INT16_C(       2829) },
       {   INT16_C(       3230), -INT16_C(       5974), -INT16_C(        189),  INT16_C(        253),
           INT16_C(       7940), -INT16_C(       8193),  INT16_C(       2977), -INT16_C(       9125)},
           INT8_C(          6),
       {  -INT32_C(  610893810),  INT32_C(   85782822), -INT32_C(  854851323),  INT32_C(  295488148) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int32x4_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlsl_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqdmlsl_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqdmlsl_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqdmlsl_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqdmlsl_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqdmlsl_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqdmlsl_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqdmlsl_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s32(0); break;
    }

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlsl_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t v[4];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(  692285164033), -INT64_C(  144355368083) },
       {  -INT32_C(        452790),  INT32_C(         12539) },
       {   INT32_C(        796583), -INT32_C(        614228),  INT32_C(        678045), -INT32_C(        459061)},
           INT8_C(             1),
       {   INT64_C(  136052571793), -INT64_C(  128951758299) } },
     { {   INT64_C(  347571409953), -INT64_C(  218176683416) },
       {  -INT32_C(        887657),  INT32_C(        464196) },
       {  -INT32_C(        542531), -INT32_C(        303694), -INT32_C(        136429), -INT32_C(        503898)},
           INT8_C(             2),
       {   INT64_C(  105367096247), -INT64_C(   91517091248) } },
     { {   INT64_C(  961419941818),  INT64_C(  500579550915) },
       {   INT32_C(        538554), -INT32_C(        599232) },
       {   INT32_C(         47934), -INT32_C(        850535), -INT32_C(         71916), -INT32_C(        709554)},
           INT8_C(             3),
       {   INT64_C( 1725686231650), -INT64_C(  349795374141) } },
     { {  -INT64_C(  857911950622),  INT64_C(  346094269849) },
       {   INT32_C(        962763), -INT32_C(        580545) },
       {   INT32_C(        985816),  INT32_C(         46854),  INT32_C(        327618),  INT32_C(        618943)},
           INT8_C(             3),
       {  -INT64_C( 2049702789640),  INT64_C( 1064742797719) } },
     { {   INT64_C(  287577232554), -INT64_C(  128173901668) },
       {   INT32_C(        285174),  INT32_C(         14178) },
       {  -INT32_C(        309901), -INT32_C(        768787), -INT32_C(         22523), -INT32_C(        178443)},
           INT8_C(             0),
       {   INT64_C(  464328648102), -INT64_C(  119386348912) } },
     { {  -INT64_C(  645061444509), -INT64_C(  246985654113) },
       {   INT32_C(        135819), -INT32_C(        966767) },
       {   INT32_C(        295862),  INT32_C(        973630), -INT32_C(        900353), -INT32_C(        748632)},
           INT8_C(             1),
       {  -INT64_C(  909536350449),  INT64_C( 1635561054307) } },
     { {   INT64_C(  335016087460),  INT64_C(  178424854943) },
       {   INT32_C(        131115),  INT32_C(        783497) },
       {   INT32_C(        280843),  INT32_C(        801145), -INT32_C(        720619),  INT32_C(        353365)},
           INT8_C(             1),
       {   INT64_C(  124931834110), -INT64_C( 1076964553187) } },
     { {  -INT64_C(  425709782755),  INT64_C(  249067519718) },
       {   INT32_C(        458791), -INT32_C(        504729) },
       {   INT32_C(        746888), -INT32_C(         42237), -INT32_C(         62401),  INT32_C(        286730)},
           INT8_C(             3),
       {  -INT64_C(  688808069615),  INT64_C(  538509412058) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int64x2_t r;
    switch(test_vec[i].lane) {
      case 0: r = simde_vqdmlsl_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqdmlsl_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqdmlsl_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqdmlsl_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = simde_vdupq_n_s64(0); break;
    }

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlslh_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsls_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlslh_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsls_laneq_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
