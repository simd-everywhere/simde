#define SIMDE_TEST_ARM_NEON_INSN qdmlsl

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlsl.h"

static int
test_simde_vqdmlslh_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[1];
    int16_t b[1];
    int16_t c[1];
    int32_t r[1];
  } test_vec[] = {
     { {  -INT32_C(      7304045) },
       {  -INT16_C(         4745) },
       {   INT16_C(         7757)},
       {   INT32_C(     66309885) } },
     { {  -INT32_C(     91150936) },
       {   INT16_C(          275) },
       {  -INT16_C(         1162)},
       {  -INT32_C(     90511836) } },
     { {   INT32_C(      9182566) },
       {  -INT16_C(         3247) },
       {  -INT16_C(         1614)},
       {  -INT32_C(      1298750) } },
     { {   INT32_C(     54973448) },
       {   INT16_C(         9255) },
       {   INT16_C(         5744)},
       {  -INT32_C(     51347992) } },
     { {  -INT32_C(     97477178) },
       {  -INT16_C(         9570) },
       {   INT16_C(         5135)},
       {   INT32_C(       806722) } },
     { {  -INT32_C(     54320777) },
       {   INT16_C(         1869) },
       {  -INT16_C(         3076)},
       {  -INT32_C(     42822689) } },
     { {   INT32_C(     27872303) },
       {  -INT16_C(         8110) },
       {  -INT16_C(         8328)},
       {  -INT32_C(    107207857) } },
     { {   INT32_C(     67057391) },
       {  -INT16_C(         2309) },
       {   INT16_C(         1079)},
       {   INT32_C(     72040213) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_vqdmlslh_s16(test_vec[i].a[0], test_vec[i].b[0], test_vec[i].c[0]);

    simde_assert_equal_i32(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlsls_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[1];
    int32_t b[1];
    int32_t c[1];
    int64_t r[1];
  } test_vec[] = {
     { {   INT64_C(   30598753824) },
       {   INT32_C(        472121) },
       {  -INT32_C(        110072)},
       {   INT64_C(  134533359248) } },
     { {  -INT64_C(  879266448960) },
       {  -INT32_C(        870787) },
       {   INT32_C(        215247)},
       {  -INT64_C(  504397870182) } },
     { {  -INT64_C(  524706562706) },
       {  -INT32_C(        267546) },
       {  -INT32_C(        367178)},
       {  -INT64_C(  721180573082) } },
     { {   INT64_C(  141628624861) },
       {  -INT32_C(        323091) },
       {  -INT32_C(        964426)},
       {  -INT64_C(  481566096671) } },
     { {   INT64_C(  834712643290) },
       {   INT32_C(        246066) },
       {   INT32_C(        479461)},
       {   INT64_C(  598754542438) } },
     { {  -INT64_C(  688696419359) },
       {  -INT32_C(        735157) },
       {  -INT32_C(         39524)},
       {  -INT64_C(  746809109895) } },
     { {   INT64_C(  903973493156) },
       {  -INT32_C(        527450) },
       {  -INT32_C(        900523)},
       {  -INT64_C(   45988219544) } },
     { {   INT64_C(  978260666802) },
       {   INT32_C(        529515) },
       {  -INT32_C(        590095)},
       {   INT64_C( 1603188974652) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vqdmlsls_s32(test_vec[i].a[0], test_vec[i].b[0], test_vec[i].c[0]);

    simde_assert_equal_i64(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlsl_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t c[4];
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(   43220716), -INT32_C(   19739561),  INT32_C(   79041776),  INT32_C(   57556654) },
       {   INT16_C(       8044), -INT16_C(       4160), -INT16_C(       8934),  INT16_C(       9184) },
       {  -INT16_C(       6473),  INT16_C(       5685), -INT16_C(       5752),  INT16_C(       6515)},
       {   INT32_C(   60916908),  INT32_C(   27559639), -INT32_C(   23734960), -INT32_C(   62110866) } },
     { {  -INT32_C(   17039563),  INT32_C(     393668),  INT32_C(   79830887),  INT32_C(   97106023) },
       {  -INT16_C(       2620),  INT16_C(       2519), -INT16_C(       9767),  INT16_C(       2499) },
       {   INT16_C(       1205),  INT16_C(       7592),  INT16_C(       5902),  INT16_C(       5791)},
       {  -INT32_C(   10725363), -INT32_C(   37854828),  INT32_C(  195120555),  INT32_C(   68162605) } },
     { {  -INT32_C(   23439805),  INT32_C(   58026650), -INT32_C(    5180845),  INT32_C(   30866311) },
       {  -INT16_C(       8571), -INT16_C(       8928),  INT16_C(       3895), -INT16_C(       9771) },
       {  -INT16_C(       3876),  INT16_C(       8898), -INT16_C(       9394), -INT16_C(       6781)},
       {  -INT32_C(   89882197),  INT32_C(  216909338),  INT32_C(   67998415), -INT32_C(  101647991) } },
     { {   INT32_C(   36239852), -INT32_C(   51532048), -INT32_C(   71094540), -INT32_C(   44844918) },
       {  -INT16_C(        190),  INT16_C(        446), -INT16_C(        752),  INT16_C(       8001) },
       {  -INT16_C(       6821),  INT16_C(       4981),  INT16_C(       5319),  INT16_C(       9223)},
       {   INT32_C(   33647872), -INT32_C(   55975100), -INT32_C(   63094764), -INT32_C(  192431364) } },
     { {  -INT32_C(    3015366),  INT32_C(   11701950), -INT32_C(   53181128),  INT32_C(   35548712) },
       {  -INT16_C(       2890),  INT16_C(       7657),  INT16_C(       8388),  INT16_C(       4823) },
       {  -INT16_C(       1859),  INT16_C(       7752), -INT16_C(       5345),  INT16_C(       6927)},
       {  -INT32_C(   13760386), -INT32_C(  107012178),  INT32_C(   36486592), -INT32_C(   31269130) } },
     { {   INT32_C(   29565525), -INT32_C(   44405017),  INT32_C(   72557961),  INT32_C(   76709539) },
       {   INT16_C(       6757),  INT16_C(       8764),  INT16_C(       1978), -INT16_C(       4268) },
       {   INT16_C(       2772), -INT16_C(       9818),  INT16_C(       8865),  INT16_C(       5166)},
       {  -INT32_C(    7895283),  INT32_C(  127684887),  INT32_C(   37488021),  INT32_C(  120806515) } },
     { {   INT32_C(   89212585), -INT32_C(   71615372), -INT32_C(   12427788), -INT32_C(   40736248) },
       {  -INT16_C(       1166),  INT16_C(       6690),  INT16_C(       7767), -INT16_C(       5984) },
       {  -INT16_C(       9261), -INT16_C(       1037),  INT16_C(       6708),  INT16_C(       4340)},
       {   INT32_C(   67615933), -INT32_C(   57740312), -INT32_C(  116629860),  INT32_C(   11204872) } },
     { {   INT32_C(    3969110),  INT32_C(    8492563),  INT32_C(   23842348),  INT32_C(   36300877) },
       {   INT16_C(       8057), -INT16_C(       9339),  INT16_C(       1806),  INT16_C(       8600) },
       {  -INT16_C(        751), -INT16_C(       6991),  INT16_C(       1494), -INT16_C(       6795)},
       {   INT32_C(   16070724), -INT32_C(  122085335),  INT32_C(   18446020),  INT32_C(  153174877) } },
     { {  -INT32_C(         16), -INT32_C(         15), -INT32_C(         14), -INT32_C(         13) },
       {              INT16_MIN,             INT16_MIN,             INT16_MIN,             INT16_MIN },
       {              INT16_MIN,             INT16_MIN,             INT16_MIN,             INT16_MIN },
       {              INT32_MIN,             INT32_MIN,             INT32_MIN,             INT32_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int32x4_t r = simde_vqdmlsl_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlsl_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t c[2];
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(  826455899656),  INT64_C(  945976857854) },
       {  -INT32_C(        449214),  INT32_C(        605955) },
       {  -INT32_C(        482717),  INT32_C(        781825)},
       {   INT64_C(  392769430780), -INT64_C(    1524677896) } },
     { {   INT64_C(  835289013120),  INT64_C(  749191377169) },
       {  -INT32_C(        173814),  INT32_C(        482498) },
       {   INT32_C(        251796), -INT32_C(        454500)},
       {   INT64_C(  922820353008),  INT64_C( 1187782059169) } },
     { {  -INT64_C(  659348795652), -INT64_C(  298665949347) },
       {  -INT32_C(        841301),  INT32_C(        216093) },
       {   INT32_C(        285802),  INT32_C(         17051)},
       {  -INT64_C(  178457778848), -INT64_C(  306035152833) } },
     { {   INT64_C(  920729567534),  INT64_C(  341740430374) },
       {   INT32_C(        765549),  INT32_C(        219031) },
       {   INT32_C(        556311), -INT32_C(        538859)},
       {   INT64_C(   68962908056),  INT64_C(  577794081632) } },
     { {   INT64_C(  680261439855), -INT64_C(  555740744485) },
       {  -INT32_C(        735475),  INT32_C(        633819) },
       {  -INT32_C(        775268), -INT32_C(        352496)},
       {  -INT64_C(  460119024745), -INT64_C(  108903420037) } },
     { {  -INT64_C(  730657729147),  INT64_C(  663399100769) },
       {  -INT32_C(        769318),  INT32_C(        827092) },
       {  -INT32_C(        784599),  INT32_C(         40219)},
       {  -INT64_C( 1937869996111),  INT64_C(  596869474473) } },
     { {   INT64_C(  875398356494),  INT64_C(  395367813293) },
       {   INT32_C(        388462),  INT32_C(        192181) },
       {  -INT32_C(        442452),  INT32_C(        110220)},
       {   INT64_C( 1219149934142),  INT64_C(  353003433653) } },
     { {   INT64_C(  138304755295), -INT64_C(  639741888131) },
       {  -INT32_C(        305245), -INT32_C(        548274) },
       {  -INT32_C(        805474),  INT32_C(        431866)},
       {  -INT64_C(  353429066965), -INT64_C(  166180089563) } },
     { {  -INT64_C(            16), -INT64_C(            15) },
       {                 INT32_MIN,                INT32_MIN },
       {                 INT32_MIN,                INT32_MIN },
       {                 INT64_MIN,                INT64_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int64x2_t r = simde_vqdmlsl_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlslh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsls_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
