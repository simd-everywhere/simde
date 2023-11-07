#define SIMDE_TEST_ARM_NEON_INSN qrdmlsh_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qrdmlsh_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vqrdmlshh_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t v[4];
    int8_t lane;
    int16_t r;
  } test_vec[] = {
    {   -INT16_C(   26344),
         INT16_C(    6005),
      {  INT16_C(   16409), -INT16_C(    8312), -INT16_C(   19684),  INT16_C(   19114) },
         INT8_C(       1),
        -INT16_C(   24821) },
    {   -INT16_C(   26648),
        -INT16_C(   24267),
      { -INT16_C(   16725),  INT16_C(     302),  INT16_C(   16842),  INT16_C(   24047) },
         INT8_C(       1),
        -INT16_C(   26424) },
    {    INT16_C(    7399),
        -INT16_C(   20363),
      { -INT16_C(   20565),  INT16_C(   31268), -INT16_C(   13849), -INT16_C(   22213) },
         INT8_C(       0),
        -INT16_C(    5381) },
    {   -INT16_C(   14953),
         INT16_C(   23577),
      {  INT16_C(    4902), -INT16_C(   21349), -INT16_C(   27264),  INT16_C(    2006) },
         INT8_C(       2),
         INT16_C(    4664) },
    {   -INT16_C(    3262),
        -INT16_C(   21430),
      { -INT16_C(   24365), -INT16_C(   24013), -INT16_C(   18862),  INT16_C(    2664) },
         INT8_C(       2),
        -INT16_C(   15598) },
    {   -INT16_C(   32055),
         INT16_C(    4565),
      { -INT16_C(    6960), -INT16_C(   21399),  INT16_C(   25367), -INT16_C(    7124) },
         INT8_C(       0),
        -INT16_C(   31085) },
    {   -INT16_C(   15588),
        -INT16_C(   31579),
      { -INT16_C(   10021), -INT16_C(   17119), -INT16_C(   31451), -INT16_C(   14170) },
         INT8_C(       3),
        -INT16_C(   29244) },
    {   -INT16_C(   13118),
         INT16_C(    3612),
      { -INT16_C(   14988),  INT16_C(    1600),  INT16_C(   16075),  INT16_C(    9799) },
         INT8_C(       2),
        -INT16_C(   14890) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    int16_t b = test_vec[i].b;
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    int16_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshh_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshh_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshh_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshh_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16_t a = simde_test_codegen_random_i16();
    simde_int16_t b = simde_test_codegen_random_i16();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    simde_int8_t lane = simde_test_codegen_random_i8();
    int16_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshh_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshh_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshh_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshh_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshs_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t v[2];
    int8_t lane;
    int32_t r;
  } test_vec[] = {
    {    INT32_C(  1440282154),
         INT32_C(   179878846),
      { -INT32_C(  1795075146),  INT32_C(   758464353) },
         INT8_C(           1),
         INT32_C(  1376751196) },
    {    INT32_C(  1392210167),
         INT32_C(  1236014758),
      { -INT32_C(   291356975), -INT32_C(   587249695) },
         INT8_C(           1),
         INT32_C(  1730210082) },
    {    INT32_C(  1544139794),
         INT32_C(  2027361206),
      { -INT32_C(   869387981),  INT32_C(  1509895512) },
         INT8_C(           0),
                     INT32_MAX },
    {    INT32_C(   847603735),
         INT32_C(  1942610330),
      {  INT32_C(   561961123),  INT32_C(  1212189523) },
         INT8_C(           1),
        -INT32_C(   248941001) },
    {    INT32_C(   843683727),
        -INT32_C(  1601937682),
      {  INT32_C(    44876863), -INT32_C(   834778415) },
         INT8_C(           1),
         INT32_C(   220972117) },
    {    INT32_C(   506983856),
        -INT32_C(  1038959908),
      {  INT32_C(  2046390473), -INT32_C(    93076183) },
         INT8_C(           0),
         INT32_C(  1497034541) },
    {   -INT32_C(   387331648),
         INT32_C(    85919846),
      { -INT32_C(   339884354), -INT32_C(  1836810163) },
         INT8_C(           0),
        -INT32_C(   373733029) },
    {    INT32_C(  2107726727),
         INT32_C(  2065642516),
      { -INT32_C(  1834105136),  INT32_C(  1912451176) },
         INT8_C(           0),
                     INT32_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    int32_t b = test_vec[i].b;
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    int32_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshs_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshs_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32_t a = simde_test_codegen_random_i32();
    simde_int32_t b = simde_test_codegen_random_i32();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    simde_int8_t lane = simde_test_codegen_random_i8();
    int32_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshs_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshs_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshh_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t v[8];
    int8_t lane;
    int16_t r;
  } test_vec[] = {
    {   -INT16_C(   27890),
        -INT16_C(   21253),
      { -INT16_C(   25851), -INT16_C(   25190), -INT16_C(    2789), -INT16_C(   16593),
        -INT16_C(    6407), -INT16_C(    7553),  INT16_C(   26968),  INT16_C(   22405) },
         INT8_C(       7),
        -INT16_C(   13358) },
    {   -INT16_C(   31549),
         INT16_C(   31191),
      { -INT16_C(   27711), -INT16_C(    5304),  INT16_C(    5133), -INT16_C(   26434),
         INT16_C(   28213),  INT16_C(   26369),  INT16_C(    6271),  INT16_C(   24242) },
         INT8_C(       5),
                 INT16_MIN },
    {    INT16_C(   15328),
        -INT16_C(   32254),
      {  INT16_C(   32573), -INT16_C(   29125), -INT16_C(   24142), -INT16_C(   17763),
         INT16_C(    2385), -INT16_C(    2422), -INT16_C(   27635),  INT16_C(   19464) },
         INT8_C(       1),
        -INT16_C(   13340) },
    {    INT16_C(    7087),
        -INT16_C(   11165),
      {  INT16_C(   21278),  INT16_C(   28748), -INT16_C(    5476),  INT16_C(   30724),
         INT16_C(    4566),  INT16_C(   25158),  INT16_C(   29807), -INT16_C(   18366) },
         INT8_C(       1),
         INT16_C(   16882) },
    {    INT16_C(   32762),
        -INT16_C(   18055),
      { -INT16_C(    2118),  INT16_C(   25618), -INT16_C(   31133), -INT16_C(   20681),
        -INT16_C(    4934), -INT16_C(    6445),  INT16_C(   12331), -INT16_C(     987) },
         INT8_C(       3),
         INT16_C(   21367) },
    {    INT16_C(    5313),
         INT16_C(   27577),
      {  INT16_C(   12666), -INT16_C(   14849), -INT16_C(   32440), -INT16_C(   26666),
        -INT16_C(    5167),  INT16_C(     264), -INT16_C(   15448), -INT16_C(   28050) },
         INT8_C(       6),
         INT16_C(   18314) },
    {    INT16_C(    7345),
         INT16_C(   21175),
      {  INT16_C(    2347),  INT16_C(    4873),  INT16_C(    7119),  INT16_C(    3728),
         INT16_C(   16715), -INT16_C(   24665), -INT16_C(   13239),  INT16_C(   10183) },
         INT8_C(       7),
         INT16_C(     765) },
    {   -INT16_C(    6194),
         INT16_C(   23085),
      {  INT16_C(   15144),  INT16_C(   31997),  INT16_C(   24214), -INT16_C(    8899),
         INT16_C(   17168),  INT16_C(   17122),  INT16_C(   19534), -INT16_C(   23740) },
         INT8_C(       4),
        -INT16_C(   18289) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    int16_t b = test_vec[i].b;
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    int16_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshh_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshh_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshh_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshh_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlshh_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlshh_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlshh_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlshh_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16_t a = simde_test_codegen_random_i16();
    simde_int16_t b = simde_test_codegen_random_i16();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    simde_int8_t lane = simde_test_codegen_random_i8();
    int16_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshh_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshh_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshh_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshh_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlshh_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlshh_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlshh_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlshh_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshs_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t v[4];
    int8_t lane;
    int32_t r;
  } test_vec[] = {
    {    INT32_C(   504746758),
        -INT32_C(  1080606674),
      { -INT32_C(   546207211), -INT32_C(   418587566), -INT32_C(  1355830581), -INT32_C(  1049309193) },
         INT8_C(           0),
         INT32_C(   229897095) },
    {   -INT32_C(  1685208591),
         INT32_C(  1300764983),
      { -INT32_C(  1048148551), -INT32_C(  1070625441), -INT32_C(   117431862), -INT32_C(   804653908) },
         INT8_C(           3),
        -INT32_C(  1197816928) },
    {   -INT32_C(  1697871017),
        -INT32_C(   602447478),
      {  INT32_C(  2018483014),  INT32_C(   809848622),  INT32_C(  2068351492), -INT32_C(  1882926538) },
         INT8_C(           2),
        -INT32_C(  1117622995) },
    {    INT32_C(   850778288),
        -INT32_C(  1853822977),
      {  INT32_C(  1095149281),  INT32_C(  1590302503),  INT32_C(    63393707), -INT32_C(   889289386) },
         INT8_C(           3),
         INT32_C(    83096030) },
    {   -INT32_C(   386552519),
        -INT32_C(  1491238989),
      {  INT32_C(   827091153),  INT32_C(   321909539),  INT32_C(  1144684896),  INT32_C(   836228398) },
         INT8_C(           0),
         INT32_C(   187789724) },
    {    INT32_C(   607759554),
         INT32_C(   487379101),
      {  INT32_C(     6001681), -INT32_C(  1752440123),  INT32_C(  1126699357),  INT32_C(   554958809) },
         INT8_C(           3),
         INT32_C(   481809666) },
    {   -INT32_C(  1475079280),
         INT32_C(  1050148375),
      { -INT32_C(    88158761),  INT32_C(   893814171),  INT32_C(   354061717), -INT32_C(   715962452) },
         INT8_C(           2),
        -INT32_C(  1648220220) },
    {    INT32_C(   270221831),
        -INT32_C(  1854925664),
      {  INT32_C(   392339543), -INT32_C(    47221790), -INT32_C(   819913159),  INT32_C(  1639376805) },
         INT8_C(           0),
         INT32_C(   609111810) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    int32_t b = test_vec[i].b;
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    int32_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshs_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshs_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshs_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshs_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32_t a = simde_test_codegen_random_i32();
    simde_int32_t b = simde_test_codegen_random_i32();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    simde_int8_t lane = simde_test_codegen_random_i8();
    int32_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshs_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshs_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshs_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshs_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlsh_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t v[4];
    int8_t lane;
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(   24825),  INT16_C(   17422),  INT16_C(    8296), -INT16_C(   27782) },
      {  INT16_C(    8530), -INT16_C(   28451), -INT16_C(   14644),  INT16_C(   32099) },
      { -INT16_C(    5606), -INT16_C(    1060), -INT16_C(   13088), -INT16_C(   13926) },
         INT8_C(       3),
      { -INT16_C(   21200),  INT16_C(    5331),  INT16_C(    2072), -INT16_C(   14140) } },
    { { -INT16_C(   27729),  INT16_C(   30407), -INT16_C(   14631),  INT16_C(   29339) },
      {  INT16_C(    1872), -INT16_C(    7259), -INT16_C(   24606),  INT16_C(   17050) },
      { -INT16_C(   32258), -INT16_C(   30510), -INT16_C(   27100), -INT16_C(   19456) },
         INT8_C(       3),
      { -INT16_C(   26617),  INT16_C(   26097), -INT16_C(   29241),          INT16_MAX } },
    { {  INT16_C(    6424),  INT16_C(   17727),  INT16_C(    6328),  INT16_C(   27881) },
      { -INT16_C(   22514), -INT16_C(   29769), -INT16_C(   24270),  INT16_C(   16864) },
      {  INT16_C(   20941),  INT16_C(   25797), -INT16_C(   32489),  INT16_C(   13450) },
         INT8_C(       1),
      {  INT16_C(   24148),          INT16_MAX,  INT16_C(   25435),  INT16_C(   14605) } },
    { {  INT16_C(   24437),  INT16_C(    3251), -INT16_C(   26038),  INT16_C(   28245) },
      { -INT16_C(   16868), -INT16_C(    4653), -INT16_C(   32176),  INT16_C(   12756) },
      {  INT16_C(    5033), -INT16_C(   24552), -INT16_C(    5130), -INT16_C(     478) },
         INT8_C(       3),
      {  INT16_C(   24191),  INT16_C(    3183), -INT16_C(   26507),  INT16_C(   28431) } },
    { { -INT16_C(   10502), -INT16_C(   30197), -INT16_C(   23267),  INT16_C(    1975) },
      { -INT16_C(    5789),  INT16_C(    7598),  INT16_C(   17622), -INT16_C(   29712) },
      {  INT16_C(   22123), -INT16_C(   15759),  INT16_C(    5390), -INT16_C(   19530) },
         INT8_C(       0),
      { -INT16_C(    6594),          INT16_MIN,          INT16_MIN,  INT16_C(   22035) } },
    { {  INT16_C(   24010), -INT16_C(    2451), -INT16_C(    3909), -INT16_C(   21847) },
      { -INT16_C(   17910), -INT16_C(   21450), -INT16_C(    2851),  INT16_C(   16831) },
      {  INT16_C(    9808), -INT16_C(    7811), -INT16_C(    5098), -INT16_C(   24611) },
         INT8_C(       0),
      {  INT16_C(   29371),  INT16_C(    3969), -INT16_C(    3056), -INT16_C(   26885) } },
    { {  INT16_C(   28931), -INT16_C(   15331),  INT16_C(   26326),  INT16_C(   29855) },
      { -INT16_C(   19343), -INT16_C(   26101),  INT16_C(   12777), -INT16_C(    6073) },
      { -INT16_C(    8669),  INT16_C(   21288),  INT16_C(   21224), -INT16_C(     755) },
         INT8_C(       0),
      {  INT16_C(   23814), -INT16_C(   22236),  INT16_C(   29706),  INT16_C(   28248) } },
    { {  INT16_C(   19522),  INT16_C(   21988), -INT16_C(   28064), -INT16_C(   13541) },
      {  INT16_C(    4288),  INT16_C(   24268), -INT16_C(   18745), -INT16_C(   28122) },
      { -INT16_C(     128),  INT16_C(   25095),  INT16_C(   26539), -INT16_C(    1758) },
         INT8_C(       0),
      {  INT16_C(   19539),  INT16_C(   22083), -INT16_C(   28137), -INT16_C(   13651) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    simde_int16x4_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlsh_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlsh_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlsh_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlsh_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    simde_int8_t lane = simde_test_codegen_random_i8();
    simde_int16x4_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlsh_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlsh_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlsh_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlsh_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlsh_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t v[2];
    int8_t lane;
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1368066907), -INT32_C(   778421776) },
      {  INT32_C(    77354504), -INT32_C(  2039586295) },
      { -INT32_C(   744977174), -INT32_C(   470321147) },
         INT8_C(           1),
      {  INT32_C(  1385008344), -INT32_C(  1225112286) } },
    { { -INT32_C(  1156103845),  INT32_C(   371590958) },
      { -INT32_C(  1432234586), -INT32_C(   539646375) },
      { -INT32_C(   393455328), -INT32_C(   796619478) },
         INT8_C(           0),
      { -INT32_C(  1418513447),  INT32_C(   272718614) } },
    { { -INT32_C(  1367319452), -INT32_C(   639445556) },
      {  INT32_C(  1079720315), -INT32_C(  1894086826) },
      { -INT32_C(   253031167), -INT32_C(   203129830) },
         INT8_C(           0),
      { -INT32_C(  1240099442), -INT32_C(   862619782) } },
    { { -INT32_C(  1748303515),  INT32_C(  1781270267) },
      { -INT32_C(  1596723611),  INT32_C(  1632103272) },
      { -INT32_C(   470118102), -INT32_C(  1730699963) },
         INT8_C(           0),
      { -INT32_C(  2097851543),  INT32_C(  2138563461) } },
    { { -INT32_C(  1024887473), -INT32_C(  1428160082) },
      { -INT32_C(  2014596412),  INT32_C(  1666357593) },
      { -INT32_C(  1495121387), -INT32_C(  2091326632) },
         INT8_C(           1),
      {              INT32_MIN,  INT32_C(   194622013) } },
    { {  INT32_C(  1643030200), -INT32_C(  1715184409) },
      {  INT32_C(   255918472),  INT32_C(  1332739608) },
      { -INT32_C(  1299214037), -INT32_C(   320044664) },
         INT8_C(           1),
      {  INT32_C(  1681170347), -INT32_C(  1516563013) } },
    { {  INT32_C(   525767180), -INT32_C(   117907175) },
      { -INT32_C(   158691706),  INT32_C(   928654788) },
      { -INT32_C(  1457718165), -INT32_C(  1362455089) },
         INT8_C(           0),
      {  INT32_C(   418046787),  INT32_C(   512466404) } },
    { { -INT32_C(   803307939),  INT32_C(  1754636799) },
      {  INT32_C(   660713892), -INT32_C(   940298410) },
      { -INT32_C(  1907260860),  INT32_C(  1096844614) },
         INT8_C(           0),
      { -INT32_C(   216503123),  INT32_C(   919522475) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int32x2_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlsh_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlsh_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    simde_int8_t lane = simde_test_codegen_random_i8();
    simde_int32x2_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlsh_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlsh_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlsh_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t v[8];
    int8_t lane;
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(    2044), -INT16_C(   20480),  INT16_C(   18864),  INT16_C(   17229) },
      { -INT16_C(   21471), -INT16_C(   27014), -INT16_C(   26348), -INT16_C(   29447) },
      { -INT16_C(    9984), -INT16_C(   12746), -INT16_C(    7109),  INT16_C(   19589),
         INT16_C(   19461),  INT16_C(   31094),  INT16_C(    8364),  INT16_C(    4055) },
         INT8_C(       1),
      { -INT16_C(   10396), -INT16_C(   30988),  INT16_C(    8615),  INT16_C(    5775) } },
    { {  INT16_C(   19977), -INT16_C(   21447),  INT16_C(   28318), -INT16_C(    7661) },
      { -INT16_C(   30276),  INT16_C(   29342),  INT16_C(   10561), -INT16_C(   25753) },
      { -INT16_C(   28376),  INT16_C(   11413),  INT16_C(   15384), -INT16_C(   16456),
         INT16_C(    3403),  INT16_C(   18344), -INT16_C(    4362),  INT16_C(   16501) },
         INT8_C(       2),
      {          INT16_MAX,          INT16_MIN,  INT16_C(   23360),  INT16_C(    4430) } },
    { {  INT16_C(   27719),  INT16_C(   19500), -INT16_C(    6773), -INT16_C(   31238) },
      { -INT16_C(   21840), -INT16_C(   10809),  INT16_C(   14482),  INT16_C(   20236) },
      {  INT16_C(   29586),  INT16_C(   19077), -INT16_C(    3935),  INT16_C(    5840),
         INT16_C(   28677), -INT16_C(    3636),  INT16_C(   32763), -INT16_C(   26005) },
         INT8_C(       1),
      {          INT16_MAX,  INT16_C(   25793), -INT16_C(   15204),          INT16_MIN } },
    { {  INT16_C(    8452),  INT16_C(   24730),  INT16_C(   29685), -INT16_C(    8215) },
      {  INT16_C(    7180),  INT16_C(   12635), -INT16_C(    2930), -INT16_C(   20805) },
      { -INT16_C(   17579), -INT16_C(    5063), -INT16_C(   23766), -INT16_C(   29024),
         INT16_C(   23780), -INT16_C(   26689), -INT16_C(   23287), -INT16_C(   24774) },
         INT8_C(       0),
      {  INT16_C(   12304),  INT16_C(   31508),  INT16_C(   28113), -INT16_C(   19376) } },
    { {  INT16_C(    2069),  INT16_C(   28053), -INT16_C(   11343), -INT16_C(   29127) },
      { -INT16_C(   11013),  INT16_C(   21642), -INT16_C(   14283), -INT16_C(   21867) },
      { -INT16_C(   32653), -INT16_C(   12341),  INT16_C(   26834), -INT16_C(   12430),
         INT16_C(   19849),  INT16_C(   32252),  INT16_C(   16763), -INT16_C(   20287) },
         INT8_C(       3),
      { -INT16_C(    2109),          INT16_MAX, -INT16_C(   16761),          INT16_MIN } },
    { {  INT16_C(   23107),  INT16_C(    3737),  INT16_C(    8194),  INT16_C(   17576) },
      {  INT16_C(   16444),  INT16_C(    3215), -INT16_C(      29),  INT16_C(   19754) },
      {  INT16_C(   18922), -INT16_C(   21476),  INT16_C(    6456),  INT16_C(   26363),
         INT16_C(    1721),  INT16_C(   16058), -INT16_C(   24368),  INT16_C(   24110) },
         INT8_C(       7),
      {  INT16_C(   11008),  INT16_C(    1371),  INT16_C(    8215),  INT16_C(    3041) } },
    { {  INT16_C(    5632),  INT16_C(    8126),  INT16_C(    4640),  INT16_C(    6454) },
      { -INT16_C(   24319),  INT16_C(   17286), -INT16_C(   29165),  INT16_C(     639) },
      {  INT16_C(     588), -INT16_C(    6436), -INT16_C(   30072),  INT16_C(   31462),
         INT16_C(   22680), -INT16_C(   21034), -INT16_C(   31125),  INT16_C(    5650) },
         INT8_C(       6),
      { -INT16_C(   17468),  INT16_C(   24545), -INT16_C(   23063),  INT16_C(    7061) } },
    { {  INT16_C(   29384), -INT16_C(   18329), -INT16_C(    6150),  INT16_C(   15677) },
      {  INT16_C(    5170),  INT16_C(    5481),  INT16_C(   13252), -INT16_C(    9595) },
      {  INT16_C(   26176),  INT16_C(   19608),  INT16_C(   15938),  INT16_C(    7103),
        -INT16_C(   14452),  INT16_C(   29728),  INT16_C(    5950), -INT16_C(   29019) },
         INT8_C(       3),
      {  INT16_C(   28263), -INT16_C(   19517), -INT16_C(    9023),  INT16_C(   17757) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    simde_int16x4_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlsh_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlsh_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlsh_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlsh_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlsh_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlsh_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlsh_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlsh_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    simde_int8_t lane = simde_test_codegen_random_i8();
    simde_int16x4_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlsh_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlsh_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlsh_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlsh_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlsh_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlsh_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlsh_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlsh_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlsh_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t v[4];
    int8_t lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1134043349),  INT32_C(   479722391) },
      { -INT32_C(   731696193), -INT32_C(   831895852) },
      { -INT32_C(   268149630), -INT32_C(  1974057416),  INT32_C(  1416279756), -INT32_C(   969319259) },
         INT8_C(           3),
      { -INT32_C(  1464312319),  INT32_C(   104225855) } },
    { { -INT32_C(   740115652), -INT32_C(   137459046) },
      {  INT32_C(  1134061317),  INT32_C(   908131940) },
      {  INT32_C(  1908150628),  INT32_C(   345405071),  INT32_C(  1628632009), -INT32_C(   334116812) },
         INT8_C(           0),
      { -INT32_C(  1747787965), -INT32_C(   944381387) } },
    { { -INT32_C(   621283799),  INT32_C(  1720880866) },
      { -INT32_C(  1538154859), -INT32_C(   770625942) },
      { -INT32_C(  2125582856), -INT32_C(   560360488), -INT32_C(  2005007575),  INT32_C(  1126213689) },
         INT8_C(           2),
      { -INT32_C(  2057388864),  INT32_C(  1001382558) } },
    { {  INT32_C(   291100745),  INT32_C(  2028710659) },
      {  INT32_C(   390013620), -INT32_C(  1298454102) },
      { -INT32_C(    97543411),  INT32_C(   837957280),  INT32_C(  1916729991), -INT32_C(  1481647052) },
         INT8_C(           0),
      {  INT32_C(   308816018),  INT32_C(  1969732030) } },
    { { -INT32_C(  1206168110), -INT32_C(  1205138879) },
      {  INT32_C(   443046425), -INT32_C(  1239572366) },
      {  INT32_C(  2040266484), -INT32_C(  1430378307),  INT32_C(   744371508), -INT32_C(  1467301376) },
         INT8_C(           2),
      { -INT32_C(  1359739075), -INT32_C(   775472114) } },
    { {  INT32_C(  2064159350), -INT32_C(  1133077502) },
      {  INT32_C(  1602782246), -INT32_C(   719632291) },
      { -INT32_C(  1836564197), -INT32_C(   345975195),  INT32_C(  1437811826),  INT32_C(   303996020) },
         INT8_C(           0),
      {              INT32_MAX, -INT32_C(  1748519162) } },
    { {  INT32_C(  1025134391), -INT32_C(  2025786485) },
      {  INT32_C(  1468932104), -INT32_C(    99712722) },
      {  INT32_C(  1826005386),  INT32_C(  2110109194), -INT32_C(   358714790),  INT32_C(  1678702806) },
         INT8_C(           2),
      {  INT32_C(  1270504209), -INT32_C(  2042442457) } },
    { {  INT32_C(  1665551894), -INT32_C(  1718527007) },
      {  INT32_C(   122129770),  INT32_C(   294892482) },
      {  INT32_C(  1672020559),  INT32_C(  1496408206),  INT32_C(   279774042),  INT32_C(     6121624) },
         INT8_C(           2),
      {  INT32_C(  1649640835), -INT32_C(  1756945582) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int32x2_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlsh_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlsh_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlsh_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlsh_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    simde_int8_t lane = simde_test_codegen_random_i8();
    simde_int32x2_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlsh_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlsh_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlsh_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlsh_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t v[4];
    int8_t lane;
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(   26484), -INT16_C(   26333), -INT16_C(   25093), -INT16_C(   15405),
         INT16_C(   24246),  INT16_C(    8304),  INT16_C(    8751),  INT16_C(    1199) },
      {  INT16_C(    2796), -INT16_C(   10398),  INT16_C(   17865), -INT16_C(    1415),
        -INT16_C(    8518),  INT16_C(    4258), -INT16_C(    8330),  INT16_C(   10945) },
      { -INT16_C(   16818),  INT16_C(   14051),  INT16_C(   20283), -INT16_C(   18178) },
         INT8_C(       3),
      { -INT16_C(   24933), -INT16_C(   32101), -INT16_C(   15182), -INT16_C(   16190),
         INT16_C(   19521),  INT16_C(   10666),  INT16_C(    4130),  INT16_C(    7271) } },
    { {  INT16_C(   12974),  INT16_C(   25959),  INT16_C(    3223),  INT16_C(   23676),
         INT16_C(   11612), -INT16_C(    9915), -INT16_C(    6071),  INT16_C(   28052) },
      {  INT16_C(   17492), -INT16_C(   24518), -INT16_C(    2598),  INT16_C(   10787),
         INT16_C(   22626),  INT16_C(   14982), -INT16_C(   24647), -INT16_C(    9169) },
      { -INT16_C(    3623), -INT16_C(   13217), -INT16_C(   18348), -INT16_C(   16166) },
         INT8_C(       1),
      {  INT16_C(   20029),  INT16_C(   16070),  INT16_C(    2175),  INT16_C(   28027),
         INT16_C(   20738), -INT16_C(    3872), -INT16_C(   16012),  INT16_C(   24354) } },
    { { -INT16_C(    4841), -INT16_C(   24500),  INT16_C(    1049),  INT16_C(   21802),
        -INT16_C(   23597), -INT16_C(   20644),  INT16_C(   32423),  INT16_C(   31666) },
      { -INT16_C(    6988), -INT16_C(    1156), -INT16_C(   26444), -INT16_C(   21223),
        -INT16_C(    8917), -INT16_C(   16293), -INT16_C(   27912), -INT16_C(    4945) },
      {  INT16_C(    4353), -INT16_C(   29580), -INT16_C(    8135), -INT16_C(   30709) },
         INT8_C(       2),
      { -INT16_C(    6576), -INT16_C(   24787), -INT16_C(    5516),  INT16_C(   16533),
        -INT16_C(   25811), -INT16_C(   24689),  INT16_C(   25494),  INT16_C(   30438) } },
    { {  INT16_C(   23171),  INT16_C(    6433), -INT16_C(    9619),  INT16_C(    8600),
         INT16_C(   22336),  INT16_C(    1652), -INT16_C(    6139), -INT16_C(    1910) },
      { -INT16_C(   25474),  INT16_C(   28924), -INT16_C(   28974), -INT16_C(    9849),
        -INT16_C(    9327), -INT16_C(     537), -INT16_C(   19969),  INT16_C(    6912) },
      { -INT16_C(   29392),  INT16_C(   15160),  INT16_C(    5965),  INT16_C(    6095) },
         INT8_C(       1),
      {          INT16_MAX, -INT16_C(    6949),  INT16_C(    3786),  INT16_C(   13157),
         INT16_C(   26651),  INT16_C(    1900),  INT16_C(    3100), -INT16_C(    5108) } },
    { {  INT16_C(   23541),  INT16_C(   31573), -INT16_C(   19225),  INT16_C(   11468),
         INT16_C(   15584), -INT16_C(    4940),  INT16_C(   15481),  INT16_C(    6174) },
      {  INT16_C(    5038),  INT16_C(   17357),  INT16_C(    4151),  INT16_C(   26658),
        -INT16_C(    4889), -INT16_C(   11621), -INT16_C(   15710),  INT16_C(   13272) },
      {  INT16_C(   26233), -INT16_C(   22761), -INT16_C(    5177), -INT16_C(   17744) },
         INT8_C(       2),
      {  INT16_C(   24337),          INT16_MAX, -INT16_C(   18569),  INT16_C(   15680),
         INT16_C(   14812), -INT16_C(    6776),  INT16_C(   12999),  INT16_C(    8271) } },
    { {  INT16_C(   22681),  INT16_C(    8532), -INT16_C(    7309),  INT16_C(   18281),
         INT16_C(     867), -INT16_C(   21527),  INT16_C(   18755),  INT16_C(    6844) },
      {  INT16_C(   24057),  INT16_C(   22554), -INT16_C(    1815), -INT16_C(   27444),
         INT16_C(   26589),  INT16_C(    4254), -INT16_C(   22698), -INT16_C(    9237) },
      { -INT16_C(   32472), -INT16_C(   22044), -INT16_C(     480), -INT16_C(    8955) },
         INT8_C(       1),
      {          INT16_MAX,  INT16_C(   23705), -INT16_C(    8530), -INT16_C(     181),
         INT16_C(   18754), -INT16_C(   18665),  INT16_C(    3485),  INT16_C(     630) } },
    { {  INT16_C(   29078), -INT16_C(    6026),  INT16_C(   20894), -INT16_C(   27639),
        -INT16_C(   19193), -INT16_C(   18098),  INT16_C(   25692), -INT16_C(    3010) },
      { -INT16_C(   29475),  INT16_C(   19660), -INT16_C(    5879),  INT16_C(   18423),
        -INT16_C(   29698),  INT16_C(     378), -INT16_C(    5353), -INT16_C(     414) },
      { -INT16_C(   12986),  INT16_C(   25384), -INT16_C(    3590),  INT16_C(   13063) },
         INT8_C(       3),
      {          INT16_MAX, -INT16_C(   13863),  INT16_C(   23238),          INT16_MIN,
        -INT16_C(    7354), -INT16_C(   18249),  INT16_C(   27826), -INT16_C(    2845) } },
    { {  INT16_C(   25537),  INT16_C(    8003), -INT16_C(   31144),  INT16_C(   24493),
         INT16_C(   13747), -INT16_C(   11784), -INT16_C(   14633), -INT16_C(   15439) },
      { -INT16_C(   32048),  INT16_C(     866),  INT16_C(   29951),  INT16_C(    5941),
        -INT16_C(   22513),  INT16_C(   12182),  INT16_C(   14206), -INT16_C(    5167) },
      {  INT16_C(   19144),  INT16_C(   27321), -INT16_C(   25732),  INT16_C(    8004) },
         INT8_C(       3),
      {          INT16_MAX,  INT16_C(    7791),          INT16_MIN,  INT16_C(   23042),
         INT16_C(   19246), -INT16_C(   14760), -INT16_C(   18103), -INT16_C(   14177) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    simde_int16x8_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshq_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshq_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshq_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshq_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    simde_int8_t lane = simde_test_codegen_random_i8();
    simde_int16x8_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshq_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshq_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshq_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshq_lane_s16(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t v[2];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   743934274),  INT32_C(  2125383688), -INT32_C(   275508822), -INT32_C(   282701268) },
      {  INT32_C(  1663611008), -INT32_C(  1533132151), -INT32_C(   225205714),  INT32_C(   814665306) },
      { -INT32_C(  1236160248), -INT32_C(  1957417240) },
         INT8_C(           0),
      {  INT32_C(   213693412),  INT32_C(  1242863804), -INT32_C(   405144431),  INT32_C(   186246129) } },
    { {  INT32_C(  1996500777),  INT32_C(  2089286689), -INT32_C(  2066724373),  INT32_C(   793359619) },
      { -INT32_C(   349124615), -INT32_C(  1426567144), -INT32_C(  2099366709),  INT32_C(  1081389182) },
      {  INT32_C(  1294007911),  INT32_C(   347812860) },
         INT8_C(           1),
      {  INT32_C(  2053046041),              INT32_MAX, -INT32_C(  1726704676),  INT32_C(   618214600) } },
    { {  INT32_C(   826729037),  INT32_C(  2145361086),  INT32_C(  1993720251), -INT32_C(  1375077741) },
      {  INT32_C(  1827843630), -INT32_C(   680572359), -INT32_C(   548333957),  INT32_C(  1186785174) },
      {  INT32_C(  1078745520), -INT32_C(  1476218996) },
         INT8_C(           0),
      { -INT32_C(    91451704),              INT32_MAX,              INT32_MAX, -INT32_C(  1971235570) } },
    { {  INT32_C(   812709868),  INT32_C(   200956803),  INT32_C(   954314568), -INT32_C(  1168303049) },
      {  INT32_C(   842790081),  INT32_C(  1317418411),  INT32_C(  2058830684), -INT32_C(   700637725) },
      {  INT32_C(   535615620), -INT32_C(  2036355744) },
         INT8_C(           1),
      {  INT32_C(  1611887279),  INT32_C(  1450201495),              INT32_MAX, -INT32_C(  1832684199) } },
    { {  INT32_C(  1174764461),  INT32_C(   128839802), -INT32_C(  1032588995),  INT32_C(    23330444) },
      { -INT32_C(  2095797224),  INT32_C(  1264792354), -INT32_C(  1172598507), -INT32_C(  1915907828) },
      {  INT32_C(  1156658665),  INT32_C(    76380915) },
         INT8_C(           0),
      {              INT32_MAX, -INT32_C(   552391479), -INT32_C(   401014350),  INT32_C(  1055259787) } },
    { { -INT32_C(  1906183186),  INT32_C(   156819369), -INT32_C(  1255676111),  INT32_C(  1726112718) },
      { -INT32_C(  1222160783),  INT32_C(   846555968),  INT32_C(  2069082700),  INT32_C(  1770923908) },
      { -INT32_C(  1608601078),  INT32_C(  1742428934) },
         INT8_C(           0),
      {              INT32_MIN,  INT32_C(   790943333),  INT32_C(   294197698),              INT32_MAX } },
    { {  INT32_C(  1889038957),  INT32_C(  1159223156),  INT32_C(  1105819631),  INT32_C(  1507595933) },
      { -INT32_C(   600621550),  INT32_C(   430072584),  INT32_C(  1107136603),  INT32_C(   797822227) },
      { -INT32_C(   341089496), -INT32_C(    92282539) },
         INT8_C(           1),
      {  INT32_C(  1863228804),  INT32_C(  1177704410),  INT32_C(  1153395954),  INT32_C(  1541880274) } },
    { { -INT32_C(  1508205331),  INT32_C(   467797371), -INT32_C(   342402216), -INT32_C(  1294750632) },
      {  INT32_C(   121009236), -INT32_C(   433346041), -INT32_C(  1967788752),  INT32_C(  1388386145) },
      { -INT32_C(  1951131210),  INT32_C(   785837045) },
         INT8_C(           1),
      { -INT32_C(  1552486711),  INT32_C(   626373373),  INT32_C(   377678377), -INT32_C(  1802808175) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int32x4_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlshq_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshq_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    simde_int8_t lane = simde_test_codegen_random_i8();
    simde_int32x4_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlshq_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshq_lane_s32(a, b, v, 1); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshq_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t v[8];
    int8_t lane;
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(    5853), -INT16_C(    1722), -INT16_C(   28728),  INT16_C(   22946),
         INT16_C(   13355), -INT16_C(   10052), -INT16_C(   31158),  INT16_C(    9501) },
      { -INT16_C(   12542),  INT16_C(   20992), -INT16_C(    7065),  INT16_C(   14784),
         INT16_C(   31351), -INT16_C(    2286), -INT16_C(    5719), -INT16_C(   28065) },
      {  INT16_C(   15453),  INT16_C(   31499), -INT16_C(    9417), -INT16_C(   21121),
         INT16_C(   16234),  INT16_C(    4212),  INT16_C(   17766),  INT16_C(   17380) },
         INT8_C(       2),
      { -INT16_C(    9457),  INT16_C(    4311), -INT16_C(   30758),  INT16_C(   27195),
         INT16_C(   22365), -INT16_C(   10709),          INT16_MIN,  INT16_C(    1436) } },
    { {  INT16_C(   22262),  INT16_C(   10602),  INT16_C(   27937),  INT16_C(   21118),
        -INT16_C(    6721),  INT16_C(     508), -INT16_C(    4722), -INT16_C(   31197) },
      {  INT16_C(   16645), -INT16_C(    3468),  INT16_C(    8021),  INT16_C(   31104),
         INT16_C(   11105), -INT16_C(   10110),  INT16_C(   28220),  INT16_C(    8441) },
      { -INT16_C(   26199),  INT16_C(   13875), -INT16_C(     420),  INT16_C(   20472),
         INT16_C(   31669), -INT16_C(   25666),  INT16_C(    2903), -INT16_C(   30050) },
         INT8_C(       1),
      {  INT16_C(   15214),  INT16_C(   12070),  INT16_C(   24541),  INT16_C(    7948),
        -INT16_C(   11423),  INT16_C(    4789), -INT16_C(   16671),          INT16_MIN } },
    { { -INT16_C(    8990),  INT16_C(    7305),  INT16_C(    2323),  INT16_C(    4082),
         INT16_C(   25601),  INT16_C(   15447), -INT16_C(   24032),  INT16_C(   13975) },
      {  INT16_C(   28858), -INT16_C(   26057),  INT16_C(    6900), -INT16_C(   24438),
         INT16_C(    7141), -INT16_C(    4540), -INT16_C(    4259),  INT16_C(    3432) },
      {  INT16_C(   31483),  INT16_C(   18340), -INT16_C(   26960),  INT16_C(     410),
        -INT16_C(   25392), -INT16_C(    2881),  INT16_C(    5775),  INT16_C(   11360) },
         INT8_C(       5),
      { -INT16_C(    6453),  INT16_C(    5014),  INT16_C(    2930),  INT16_C(    1933),
         INT16_C(   26229),  INT16_C(   15048), -INT16_C(   24406),  INT16_C(   14277) } },
    { {  INT16_C(   15606),  INT16_C(    8227), -INT16_C(   13562), -INT16_C(   18908),
         INT16_C(   19463), -INT16_C(   23251),  INT16_C(   26050),  INT16_C(   25969) },
      {  INT16_C(   21409),  INT16_C(   13852),  INT16_C(    4119), -INT16_C(   14739),
         INT16_C(    6246), -INT16_C(   19685), -INT16_C(   21123), -INT16_C(   19388) },
      {  INT16_C(     756),  INT16_C(   25174),  INT16_C(   16028),  INT16_C(   23223),
        -INT16_C(   11777), -INT16_C(   20418), -INT16_C(   31557), -INT16_C(   19368) },
         INT8_C(       5),
      {  INT16_C(   28946),  INT16_C(   16858), -INT16_C(   10995), -INT16_C(   28092),
         INT16_C(   23355),          INT16_MIN,  INT16_C(   12888),  INT16_C(   13888) } },
    { { -INT16_C(   15683), -INT16_C(    2655), -INT16_C(   15160), -INT16_C(   22100),
        -INT16_C(   11284),  INT16_C(   32544), -INT16_C(   30115), -INT16_C(    8247) },
      { -INT16_C(   29439), -INT16_C(   30789), -INT16_C(   28217), -INT16_C(   20215),
         INT16_C(   24703),  INT16_C(    6324),  INT16_C(   30813),  INT16_C(   15911) },
      {  INT16_C(    7001), -INT16_C(    7497),  INT16_C(    1123), -INT16_C(   13835),
         INT16_C(    2408),  INT16_C(     888), -INT16_C(   19257),  INT16_C(   16462) },
         INT8_C(       1),
      { -INT16_C(   22418), -INT16_C(    9699), -INT16_C(   21616), -INT16_C(   26725),
        -INT16_C(    5632),          INT16_MAX, -INT16_C(   23065), -INT16_C(    4607) } },
    { {  INT16_C(   26953),  INT16_C(   24519), -INT16_C(   30688), -INT16_C(   18222),
        -INT16_C(    1201), -INT16_C(   27166),  INT16_C(    1525), -INT16_C(    1685) },
      {  INT16_C(   30092), -INT16_C(   12354),  INT16_C(   30351), -INT16_C(   23119),
        -INT16_C(   22631), -INT16_C(   15046),  INT16_C(   22723), -INT16_C(    9274) },
      { -INT16_C(   15098), -INT16_C(   10750), -INT16_C(   32228),  INT16_C(   11019),
         INT16_C(   28916), -INT16_C(    2907),  INT16_C(    8671),  INT16_C(   27501) },
         INT8_C(       2),
      {          INT16_MAX,  INT16_C(   12369), -INT16_C(     837),          INT16_MIN,
        -INT16_C(   23459),          INT16_MIN,  INT16_C(   23874), -INT16_C(   10806) } },
    { {  INT16_C(   21768),  INT16_C(   31474),  INT16_C(   11357), -INT16_C(   24695),
         INT16_C(   26530), -INT16_C(    6740), -INT16_C(   17021),  INT16_C(    6794) },
      { -INT16_C(    9528),  INT16_C(    1504), -INT16_C(    9627), -INT16_C(   25713),
         INT16_C(   20224), -INT16_C(   20844),  INT16_C(   16558), -INT16_C(   32521) },
      { -INT16_C(   17834), -INT16_C(    2172),  INT16_C(   30763), -INT16_C(   14117),
         INT16_C(    7397), -INT16_C(      72),  INT16_C(   28090),  INT16_C(   25304) },
         INT8_C(       0),
      {  INT16_C(   16582),  INT16_C(   32293),  INT16_C(    6118),          INT16_MIN,
                 INT16_MAX, -INT16_C(   18084), -INT16_C(    8009), -INT16_C(   10906) } },
    { {  INT16_C(    7186),  INT16_C(   14224),  INT16_C(   21284),  INT16_C(    1681),
        -INT16_C(    7941), -INT16_C(   30437), -INT16_C(   15990), -INT16_C(    8953) },
      { -INT16_C(   16063),  INT16_C(    9876),  INT16_C(   27582),  INT16_C(   26113),
        -INT16_C(   22172),  INT16_C(   18054),  INT16_C(   19838),  INT16_C(    5449) },
      {  INT16_C(   21428), -INT16_C(   20468),  INT16_C(   10824),  INT16_C(    5849),
        -INT16_C(    9077), -INT16_C(   22583), -INT16_C(   10344), -INT16_C(   23458) },
         INT8_C(       1),
      { -INT16_C(    2847),  INT16_C(   20393),          INT16_MAX,  INT16_C(   17992),
        -INT16_C(   21790), -INT16_C(   19160), -INT16_C(    3599), -INT16_C(    5549) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    simde_int16x8_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshq_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshq_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshq_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshq_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlshq_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlshq_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlshq_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlshq_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    simde_int8_t lane = simde_test_codegen_random_i8();
    simde_int16x8_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlshq_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshq_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshq_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshq_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlshq_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlshq_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlshq_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlshq_laneq_s16(a, b, v, 7); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   892747490),  INT32_C(  1873091190),  INT32_C(  1032972739), -INT32_C(  2019198668) },
      { -INT32_C(  1563787891),  INT32_C(  1766512312),  INT32_C(  1696857454),  INT32_C(   185795354) },
      {  INT32_C(    38500087), -INT32_C(  1901559194),  INT32_C(  1744827991), -INT32_C(   340805920) },
         INT8_C(           0),
      { -INT32_C(   864711901),  INT32_C(  1841421157),  INT32_C(  1002551478), -INT32_C(  2022529607) } },
    { { -INT32_C(  1118917099), -INT32_C(  1956459679), -INT32_C(   855871108), -INT32_C(  1214153064) },
      {  INT32_C(   259877225), -INT32_C(  1074903167),  INT32_C(  1642481883), -INT32_C(   208036760) },
      { -INT32_C(   886153798),  INT32_C(   899767869),  INT32_C(   358410030),  INT32_C(   964608602) },
         INT8_C(           1),
      { -INT32_C(  1227802295), -INT32_C(  1506089157), -INT32_C(  1544049770), -INT32_C(  1126988353) } },
    { { -INT32_C(   734321086), -INT32_C(  2016442765),  INT32_C(  1232720312), -INT32_C(  1582232435) },
      {  INT32_C(  1893304140), -INT32_C(  1340106484), -INT32_C(  1356568571),  INT32_C(  1865341268) },
      { -INT32_C(  1910997987),  INT32_C(  1507004337),  INT32_C(  1194477583), -INT32_C(  1795632089) },
         INT8_C(           2),
      { -INT32_C(  1787418443), -INT32_C(  1271046098),  INT32_C(  1987273554),              INT32_MIN } },
    { { -INT32_C(  1585438901),  INT32_C(  1662702766), -INT32_C(  1096897314), -INT32_C(  1964294588) },
      {  INT32_C(    95514059),  INT32_C(  1406953409),  INT32_C(  1116720893), -INT32_C(  1864216468) },
      { -INT32_C(  2094496805), -INT32_C(  1544727737),  INT32_C(   944522921), -INT32_C(   540659237) },
         INT8_C(           0),
      { -INT32_C(  1492281548),              INT32_MAX, -INT32_C(     7730305),              INT32_MIN } },
    { { -INT32_C(   231811414), -INT32_C(   520606799), -INT32_C(  1357521497), -INT32_C(   477801244) },
      {  INT32_C(   536450961), -INT32_C(   615018907), -INT32_C(   251946444), -INT32_C(  1852769719) },
      {  INT32_C(  1677178265),  INT32_C(   654223706),  INT32_C(  1827897465),  INT32_C(   564506328) },
         INT8_C(           2),
      { -INT32_C(   688428326),  INT32_C(     2885663), -INT32_C(  1143069449),  INT32_C(  1099241299) } },
    { {  INT32_C(  1612444860), -INT32_C(  1062769858), -INT32_C(  1213691663), -INT32_C(   832966236) },
      { -INT32_C(  1460736552),  INT32_C(  1558297600), -INT32_C(  1943677940),  INT32_C(    70297232) },
      {  INT32_C(  1095559873),  INT32_C(   263749442),  INT32_C(  1961797343), -INT32_C(  1319994179) },
         INT8_C(           3),
      {  INT32_C(   714573648), -INT32_C(   104930778),              INT32_MIN, -INT32_C(   789756623) } },
    { { -INT32_C(    51732972), -INT32_C(  1695418049), -INT32_C(   263811192),  INT32_C(  1146382989) },
      {  INT32_C(  2069857213),  INT32_C(  1926623066), -INT32_C(   905434054), -INT32_C(   632943406) },
      { -INT32_C(  1226413407), -INT32_C(   579634309), -INT32_C(  1308818019), -INT32_C(  1442698090) },
         INT8_C(           1),
      {  INT32_C(   506948933), -INT32_C(  1175396939), -INT32_C(   508199848),  INT32_C(   975543172) } },
    { {  INT32_C(   199308223),  INT32_C(  1448716983), -INT32_C(   772838440),  INT32_C(  2017829117) },
      { -INT32_C(   668958675),  INT32_C(  1906350124),  INT32_C(  2013019190), -INT32_C(   466295953) },
      {  INT32_C(   429198423), -INT32_C(   216837657), -INT32_C(  2138067487), -INT32_C(  1823895486) },
         INT8_C(           2),
      { -INT32_C(   466717241),              INT32_MAX,  INT32_C(  1231354181),  INT32_C(  1553577751) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int32x4_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlshq_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshq_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshq_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshq_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    simde_int8_t lane = simde_test_codegen_random_i8();
    simde_int32x4_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlshq_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlshq_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlshq_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlshq_laneq_s32(a, b, v, 3); break;
      default: HEDLEY_UNREACHABLE(); r = a; break;
    }

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

HEDLEY_DIAGNOSTIC_POP

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshh_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshs_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshh_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshs_laneq_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlsh_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlsh_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlsh_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlsh_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshq_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshq_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
