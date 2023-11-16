#define SIMDE_TEST_ARM_NEON_INSN qrdmlah_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qrdmlah_lane.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vqrdmlahh_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t v[4];
    int8_t lane;
    int16_t r;
  } test_vec[] = {
    {   -INT16_C(   18635),
        -INT16_C(   23746),
      { -INT16_C(   11225),  INT16_C(    1359),  INT16_C(   10762),  INT16_C(    9921) },
         INT8_C(       0),
        -INT16_C(   10501) },
    {    INT16_C(   28703),
        -INT16_C(   29481),
      { -INT16_C(   26699), -INT16_C(   29445),  INT16_C(   11879), -INT16_C(    5455) },
         INT8_C(       0),
                 INT16_MAX },
    {    INT16_C(    3139),
         INT16_C(    8712),
      {  INT16_C(   10351), -INT16_C(     923), -INT16_C(    5234), -INT16_C(   18798) },
         INT8_C(       3),
        -INT16_C(    1859) },
    {   -INT16_C(   27539),
         INT16_C(   22875),
      { -INT16_C(    4882),  INT16_C(   10559), -INT16_C(   21595), -INT16_C(    1318) },
         INT8_C(       3),
        -INT16_C(   28459) },
    {   -INT16_C(   23163),
        -INT16_C(   31234),
      { -INT16_C(   21884),  INT16_C(    6696), -INT16_C(   14287),  INT16_C(   15844) },
         INT8_C(       0),
        -INT16_C(    2303) },
    {    INT16_C(   31008),
         INT16_C(    8606),
      { -INT16_C(   30324),  INT16_C(   11199),  INT16_C(   20412), -INT16_C(   20388) },
         INT8_C(       3),
         INT16_C(   25653) },
    {   -INT16_C(    7736),
         INT16_C(    4268),
      { -INT16_C(   19649), -INT16_C(   21504), -INT16_C(    9860), -INT16_C(   28788) },
         INT8_C(       1),
        -INT16_C(   10537) },
    {   -INT16_C(   17796),
         INT16_C(   13897),
      { -INT16_C(    5482),  INT16_C(   18849),  INT16_C(    7808),  INT16_C(   27265) },
         INT8_C(       1),
        -INT16_C(    9802) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    int16_t b = test_vec[i].b;
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    int16_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlahh_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahh_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahh_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahh_lane_s16(a, b, v, 3); break;
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
    simde_int16_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlahh_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahh_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahh_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahh_lane_s16(a, b, v, 3); break;
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
test_simde_vqrdmlahs_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t v[2];
    int8_t lane;
    int32_t r;
  } test_vec[] = {
    {   -INT32_C(  1834182674),
         INT32_C(  1959038206),
      {  INT32_C(  2084514128),  INT32_C(  1804736416) },
         INT8_C(           0),
         INT32_C(    67411697) },
    {    INT32_C(     9440468),
         INT32_C(  1970010699),
      {  INT32_C(   192164732), -INT32_C(   300579598) },
         INT8_C(           0),
         INT32_C(   185724268) },
    {   -INT32_C(  1731513605),
        -INT32_C(  1890338876),
      {  INT32_C(   177454597),  INT32_C(   126502095) },
         INT8_C(           1),
        -INT32_C(  1842868040) },
    {    INT32_C(   864454633),
         INT32_C(  1326598164),
      { -INT32_C(   677290641), -INT32_C(  1901272247) },
         INT8_C(           1),
        -INT32_C(   310047568) },
    {    INT32_C(  1188937465),
         INT32_C(   660886351),
      { -INT32_C(   505693138), -INT32_C(  1114061780) },
         INT8_C(           0),
         INT32_C(  1033310812) },
    {   -INT32_C(  2046854522),
        -INT32_C(   499103511),
      { -INT32_C(   135144973),  INT32_C(  1913281434) },
         INT8_C(           0),
        -INT32_C(  2015445049) },
    {   -INT32_C(   107811300),
        -INT32_C(   819828206),
      { -INT32_C(    57303243),  INT32_C(   133115137) },
         INT8_C(           0),
        -INT32_C(    85935085) },
    {   -INT32_C(  1457174222),
         INT32_C(   234930209),
      { -INT32_C(  2136876571), -INT32_C(   354412329) },
         INT8_C(           1),
        -INT32_C(  1495946188) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    int32_t b = test_vec[i].b;
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    int32_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlahs_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahs_lane_s32(a, b, v, 1); break;
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
      case 0: r = simde_vqrdmlahs_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahs_lane_s32(a, b, v, 1); break;
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
test_simde_vqrdmlahh_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t v[8];
    int8_t lane;
    int16_t r;
  } test_vec[] = {
    {    INT16_C(    8058),
         INT16_C(   24901),
      { -INT16_C(   23332),  INT16_C(    6758),  INT16_C(   21926), -INT16_C(    6708),
        -INT16_C(    8085), -INT16_C(    4103),  INT16_C(    9464),  INT16_C(    5178) },
         INT8_C(       1),
         INT16_C(   13194) },
    {   -INT16_C(   13872),
         INT16_C(   12575),
      { -INT16_C(   19645), -INT16_C(   29220),  INT16_C(     116),  INT16_C(   16849),
         INT16_C(    8164), -INT16_C(   14977), -INT16_C(   16445),  INT16_C(   17400) },
         INT8_C(       6),
        -INT16_C(   20183) },
    {    INT16_C(    2492),
         INT16_C(    6579),
      {  INT16_C(   27366), -INT16_C(   12257), -INT16_C(   25067),  INT16_C(   18065),
         INT16_C(   26319),  INT16_C(   12126),  INT16_C(   20544), -INT16_C(   11358) },
         INT8_C(       5),
         INT16_C(    4927) },
    {    INT16_C(   18886),
         INT16_C(   28681),
      { -INT16_C(   31130),  INT16_C(   11647), -INT16_C(   29346),  INT16_C(   31361),
        -INT16_C(   21011), -INT16_C(   27925),  INT16_C(    9154), -INT16_C(   15209) },
         INT8_C(       5),
        -INT16_C(    5556) },
    {   -INT16_C(   11903),
         INT16_C(   13177),
      {  INT16_C(   26185),  INT16_C(    8822), -INT16_C(   13829), -INT16_C(    7360),
         INT16_C(   16259),  INT16_C(   30743), -INT16_C(   18775), -INT16_C(    9331) },
         INT8_C(       1),
        -INT16_C(    8355) },
    {    INT16_C(   19084),
        -INT16_C(    3274),
      { -INT16_C(    6761), -INT16_C(   25882), -INT16_C(   32465),  INT16_C(    9584),
        -INT16_C(   15244), -INT16_C(   14861),  INT16_C(    3732),  INT16_C(   29157) },
         INT8_C(       2),
         INT16_C(   22328) },
    {    INT16_C(   11117),
        -INT16_C(   26678),
      { -INT16_C(   27044),  INT16_C(   10309),  INT16_C(    6401), -INT16_C(    4172),
        -INT16_C(   21810),  INT16_C(   31797),  INT16_C(   23161), -INT16_C(   14861) },
         INT8_C(       7),
         INT16_C(   23216) },
    {   -INT16_C(   30926),
         INT16_C(   28984),
      {  INT16_C(   19941),  INT16_C(   21667),  INT16_C(   29438),  INT16_C(   31902),
         INT16_C(   28813),  INT16_C(   30849), -INT16_C(    7970),  INT16_C(   31958) },
         INT8_C(       2),
        -INT16_C(    4887) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    int16_t b = test_vec[i].b;
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    int16_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlahh_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahh_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahh_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahh_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlahh_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlahh_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlahh_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlahh_laneq_s16(a, b, v, 7); break;
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
      case 0: r = simde_vqrdmlahh_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahh_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahh_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahh_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlahh_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlahh_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlahh_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlahh_laneq_s16(a, b, v, 7); break;
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
test_simde_vqrdmlahs_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t v[4];
    int8_t lane;
    int32_t r;
  } test_vec[] = {
    {   -INT32_C(  1158822359),
        -INT32_C(  1687802363),
      { -INT32_C(  1860136634), -INT32_C(   924583387), -INT32_C(   981496673), -INT32_C(  1703096280) },
         INT8_C(           1),
        -INT32_C(   432151389) },
    {    INT32_C(   626051275),
        -INT32_C(  1122609272),
      {  INT32_C(  1302434787), -INT32_C(   276432399),  INT32_C(  1449391304), -INT32_C(  1315312589) },
         INT8_C(           1),
         INT32_C(   770557881) },
    {    INT32_C(   268015796),
        -INT32_C(  1909280315),
      { -INT32_C(   859597843),  INT32_C(  2142877249),  INT32_C(  1821241762),  INT32_C(   392215228) },
         INT8_C(           0),
         INT32_C(  1032265266) },
    {    INT32_C(   518287578),
         INT32_C(  1360447830),
      {  INT32_C(   743067880),  INT32_C(  1941053273), -INT32_C(   217614553),  INT32_C(  1315066161) },
         INT8_C(           1),
         INT32_C(  1747960137) },
    {    INT32_C(   916683949),
         INT32_C(  2142069362),
      {  INT32_C(   983530391), -INT32_C(  1431282559),  INT32_C(   282608673),  INT32_C(   582548986) },
         INT8_C(           3),
         INT32_C(  1497764199) },
    {    INT32_C(  2030599808),
        -INT32_C(   188280036),
      { -INT32_C(  1554865456), -INT32_C(   740636409), -INT32_C(   952688723), -INT32_C(   254069713) },
         INT8_C(           2),
         INT32_C(  2114126529) },
    {    INT32_C(  2035190063),
        -INT32_C(    11524531),
      { -INT32_C(  1741163329),  INT32_C(  1344967338), -INT32_C(  1347835926), -INT32_C(  1078913084) },
         INT8_C(           3),
         INT32_C(  2040980080) },
    {    INT32_C(  1492526129),
        -INT32_C(    54912393),
      {  INT32_C(  1909942613),  INT32_C(   680830403), -INT32_C(   341477797),  INT32_C(  1065201035) },
         INT8_C(           1),
         INT32_C(  1475116904) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    int32_t b = test_vec[i].b;
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    int32_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlahs_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahs_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahs_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahs_laneq_s32(a, b, v, 3); break;
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
      case 0: r = simde_vqrdmlahs_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahs_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahs_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahs_laneq_s32(a, b, v, 3); break;
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
test_simde_vqrdmlah_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t v[4];
    int8_t lane;
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C(   19413),  INT16_C(   16702), -INT16_C(   24337), -INT16_C(    6940) },
      {  INT16_C(    6233),  INT16_C(   13905), -INT16_C(   20223),  INT16_C(   16387) },
      {  INT16_C(   29762),  INT16_C(   12447),  INT16_C(   21256), -INT16_C(   30557) },
         INT8_C(       0),
      { -INT16_C(   13752),  INT16_C(   29331),          INT16_MIN,  INT16_C(    7944) } },
    { { -INT16_C(     974),  INT16_C(   16420),  INT16_C(   11030),  INT16_C(   29378) },
      {  INT16_C(    9993),  INT16_C(   30583),  INT16_C(   21046), -INT16_C(   17738) },
      { -INT16_C(   22492), -INT16_C(    2757), -INT16_C(   29508),  INT16_C(     788) },
         INT8_C(       0),
      { -INT16_C(    7833), -INT16_C(    4572), -INT16_C(    3416),          INT16_MAX } },
    { {  INT16_C(   29533),  INT16_C(    7155),  INT16_C(    4266), -INT16_C(    7536) },
      {  INT16_C(   18579),  INT16_C(    5317),  INT16_C(   15179), -INT16_C(   28489) },
      {  INT16_C(    7833),  INT16_C(   23088), -INT16_C(    2525), -INT16_C(   24362) },
         INT8_C(       2),
      {  INT16_C(   28101),  INT16_C(    6745),  INT16_C(    3096), -INT16_C(    5341) } },
    { { -INT16_C(   27538), -INT16_C(   27745), -INT16_C(   31266), -INT16_C(    3497) },
      {  INT16_C(   24610),  INT16_C(    6484),  INT16_C(   27970), -INT16_C(    5693) },
      { -INT16_C(   24515),  INT16_C(   29424),  INT16_C(   24795),  INT16_C(   28598) },
         INT8_C(       2),
      { -INT16_C(    8916), -INT16_C(   22839), -INT16_C(   10102), -INT16_C(    7805) } },
    { {  INT16_C(   25978), -INT16_C(    9520), -INT16_C(   19287), -INT16_C(    2300) },
      { -INT16_C(   30156), -INT16_C(   29037),  INT16_C(   10594), -INT16_C(   19028) },
      {  INT16_C(    9293),  INT16_C(     809),  INT16_C(   24140),  INT16_C(   11597) },
         INT8_C(       3),
      {  INT16_C(   15305), -INT16_C(   19797), -INT16_C(   15538), -INT16_C(    9034) } },
    { {  INT16_C(   22305), -INT16_C(   27492), -INT16_C(    3317), -INT16_C(   14704) },
      {  INT16_C(   12722),  INT16_C(   26712),  INT16_C(   29427), -INT16_C(   19995) },
      { -INT16_C(   22127), -INT16_C(   28480), -INT16_C(   25626),  INT16_C(    8157) },
         INT8_C(       3),
      {  INT16_C(   25472), -INT16_C(   20843),  INT16_C(    4008), -INT16_C(   19681) } },
    { { -INT16_C(   11527), -INT16_C(    4108), -INT16_C(   28054), -INT16_C(   18978) },
      { -INT16_C(   13442), -INT16_C(   13536),  INT16_C(   22192),  INT16_C(   15265) },
      { -INT16_C(   22810), -INT16_C(   25732), -INT16_C(   26947), -INT16_C(   18423) },
         INT8_C(       2),
      { -INT16_C(     473),  INT16_C(    7023),          INT16_MIN, -INT16_C(   31531) } },
    { { -INT16_C(   12108),  INT16_C(    4590),  INT16_C(   25572),  INT16_C(    5952) },
      {  INT16_C(    1525),  INT16_C(    2609), -INT16_C(    2607),  INT16_C(    8292) },
      { -INT16_C(   17887), -INT16_C(   21921), -INT16_C(   13923), -INT16_C(   17487) },
         INT8_C(       2),
      { -INT16_C(   12756),  INT16_C(    3481),  INT16_C(   26680),  INT16_C(    2429) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    simde_int16x4_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlah_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlah_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlah_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlah_lane_s16(a, b, v, 3); break;
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
      case 0: r = simde_vqrdmlah_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlah_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlah_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlah_lane_s16(a, b, v, 3); break;
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
test_simde_vqrdmlah_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t v[2];
    int8_t lane;
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   373153308), -INT32_C(   466351250) },
      { -INT32_C(  1738377482),  INT32_C(   226443832) },
      {  INT32_C(  1785890588),  INT32_C(   659028517) },
         INT8_C(           1),
      { -INT32_C(   160327045), -INT32_C(   396859246) } },
    { {  INT32_C(  2099557949), -INT32_C(   172823137) },
      {  INT32_C(  1836579133), -INT32_C(   246452932) },
      { -INT32_C(   707068922),  INT32_C(  1627770233) },
         INT8_C(           1),
      {              INT32_MAX, -INT32_C(   359631892) } },
    { { -INT32_C(  1695363157), -INT32_C(  2030590254) },
      {  INT32_C(    49055754),  INT32_C(   659152846) },
      { -INT32_C(  1079771039),  INT32_C(  1546614293) },
         INT8_C(           1),
      { -INT32_C(  1660033281), -INT32_C(  1555869427) } },
    { {  INT32_C(   278696474), -INT32_C(  1983086199) },
      {  INT32_C(    68267295), -INT32_C(   934865975) },
      {  INT32_C(   877224683),  INT32_C(  1311587135) },
         INT8_C(           1),
      {  INT32_C(   320391090),              INT32_MIN } },
    { {  INT32_C(  2084818205), -INT32_C(    36779922) },
      { -INT32_C(    20933434),  INT32_C(  2035570330) },
      { -INT32_C(   872611213),  INT32_C(   231564839) },
         INT8_C(           0),
      {  INT32_C(  2093324323), -INT32_C(   863916136) } },
    { {  INT32_C(  2082547961), -INT32_C(  1458032105) },
      { -INT32_C(  1968502414), -INT32_C(  1947643480) },
      { -INT32_C(  1531382148), -INT32_C(  1006592836) },
         INT8_C(           1),
      {              INT32_MAX, -INT32_C(   545110614) } },
    { {  INT32_C(   713897231),  INT32_C(   612015942) },
      { -INT32_C(   966056960), -INT32_C(  1603011301) },
      { -INT32_C(   982320065), -INT32_C(  1271152606) },
         INT8_C(           1),
      {  INT32_C(  1285732003),  INT32_C(  1560880905) } },
    { {  INT32_C(  2077665841),  INT32_C(   159545138) },
      {  INT32_C(  1252956925),  INT32_C(  1799718582) },
      { -INT32_C(  1999109910), -INT32_C(   936755841) },
         INT8_C(           0),
      {  INT32_C(   911278098), -INT32_C(  1515827457) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int32x2_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlah_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlah_lane_s32(a, b, v, 1); break;
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
      case 0: r = simde_vqrdmlah_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlah_lane_s32(a, b, v, 1); break;
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
test_simde_vqrdmlah_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t v[8];
    int8_t lane;
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(   16615),  INT16_C(   13162), -INT16_C(   22270), -INT16_C(    6134) },
      { -INT16_C(    3273),  INT16_C(    7539),  INT16_C(   17593), -INT16_C(    7364) },
      { -INT16_C(   19792), -INT16_C(   10288), -INT16_C(   28727),  INT16_C(    7955),
        -INT16_C(    4533),  INT16_C(   20612), -INT16_C(    8411), -INT16_C(   25168) },
         INT8_C(       0),
      {  INT16_C(   18592),  INT16_C(    8608),          INT16_MIN, -INT16_C(    1686) } },
    { {  INT16_C(    2551),  INT16_C(   11829), -INT16_C(   27602), -INT16_C(   18508) },
      { -INT16_C(    4939), -INT16_C(   25509), -INT16_C(    6746),  INT16_C(   12803) },
      { -INT16_C(   14917), -INT16_C(   14587), -INT16_C(   24884), -INT16_C(   22495),
        -INT16_C(    4397),  INT16_C(    5511), -INT16_C(    1366), -INT16_C(    9473) },
         INT8_C(       7),
      {  INT16_C(    3979),  INT16_C(   19203), -INT16_C(   25652), -INT16_C(   22209) } },
    { { -INT16_C(   11965),  INT16_C(   21846),  INT16_C(   32490), -INT16_C(   27182) },
      { -INT16_C(    3725), -INT16_C(    9758),  INT16_C(    7465), -INT16_C(   22885) },
      { -INT16_C(   18912),  INT16_C(    8494),  INT16_C(   19788),  INT16_C(     623),
         INT16_C(    5633),  INT16_C(    9791),  INT16_C(    4293), -INT16_C(   19999) },
         INT8_C(       4),
      { -INT16_C(   12605),  INT16_C(   20169),          INT16_MAX, -INT16_C(   31116) } },
    { { -INT16_C(    1355), -INT16_C(   14972),  INT16_C(    2989), -INT16_C(    9642) },
      {  INT16_C(   28770), -INT16_C(   17191),  INT16_C(     600), -INT16_C(   29999) },
      { -INT16_C(   20374),  INT16_C(   13510), -INT16_C(   26853), -INT16_C(   19656),
         INT16_C(   18076), -INT16_C(   26868), -INT16_C(    7219), -INT16_C(    4058) },
         INT8_C(       4),
      {  INT16_C(   14516), -INT16_C(   24455),  INT16_C(    3320), -INT16_C(   26191) } },
    { { -INT16_C(    5081), -INT16_C(    8819),  INT16_C(    7712),  INT16_C(    3612) },
      {  INT16_C(   31729),  INT16_C(   23592),  INT16_C(   30941), -INT16_C(   32093) },
      { -INT16_C(   13987), -INT16_C(   29374), -INT16_C(   31969), -INT16_C(    7728),
         INT16_C(   20669), -INT16_C(   18222),  INT16_C(   28027), -INT16_C(   12861) },
         INT8_C(       1),
      {          INT16_MIN, -INT16_C(   29967), -INT16_C(   20024),  INT16_C(   32381) } },
    { {  INT16_C(   22375), -INT16_C(    1806), -INT16_C(   16969),  INT16_C(    4074) },
      { -INT16_C(   10559), -INT16_C(   26230), -INT16_C(   11211),  INT16_C(   11185) },
      {  INT16_C(   26517),  INT16_C(    1193),  INT16_C(    7907),  INT16_C(    8229),
         INT16_C(   26040),  INT16_C(   25190), -INT16_C(    5461), -INT16_C(   20350) },
         INT8_C(       7),
      {  INT16_C(   28932),  INT16_C(   14484), -INT16_C(   10007), -INT16_C(    2872) } },
    { {  INT16_C(   16279),  INT16_C(    4633), -INT16_C(   25461), -INT16_C(   19845) },
      { -INT16_C(   13025),  INT16_C(   24959),  INT16_C(   26809), -INT16_C(   20945) },
      {  INT16_C(   32453),  INT16_C(   23268), -INT16_C(    1173),  INT16_C(   22327),
        -INT16_C(   30581), -INT16_C(   13553), -INT16_C(    3732), -INT16_C(   23697) },
         INT8_C(       6),
      {  INT16_C(   17762),  INT16_C(    1790), -INT16_C(   28514), -INT16_C(   17460) } },
    { { -INT16_C(    1007), -INT16_C(    5115), -INT16_C(   12893),  INT16_C(   17617) },
      {  INT16_C(   18423), -INT16_C(    1025),  INT16_C(    6697),  INT16_C(   15376) },
      {  INT16_C(   21347),  INT16_C(   12581), -INT16_C(    4584), -INT16_C(   15609),
         INT16_C(   22189),  INT16_C(   16388), -INT16_C(    3512),  INT16_C(   24036) },
         INT8_C(       5),
      {  INT16_C(    8207), -INT16_C(    5628), -INT16_C(    9544),  INT16_C(   25307) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    simde_int16x4_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlah_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlah_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlah_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlah_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlah_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlah_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlah_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlah_laneq_s16(a, b, v, 7); break;
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
      case 0: r = simde_vqrdmlah_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlah_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlah_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlah_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlah_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlah_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlah_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlah_laneq_s16(a, b, v, 7); break;
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
test_simde_vqrdmlah_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t v[4];
    int8_t lane;
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(    33211026),  INT32_C(  2017068965) },
      {  INT32_C(   173341517), -INT32_C(   206112487) },
      {  INT32_C(  2032218520),  INT32_C(  1175490671), -INT32_C(  1945162022),  INT32_C(  1925380991) },
         INT8_C(           0),
      {  INT32_C(   130826470),  INT32_C(  1822019464) } },
    { { -INT32_C(  1685369448),  INT32_C(  1446278680) },
      { -INT32_C(  1993455654), -INT32_C(  1497881765) },
      { -INT32_C(   150635384), -INT32_C(   684206566),  INT32_C(  1961592782), -INT32_C(   732511720) },
         INT8_C(           0),
      { -INT32_C(  1545538368),  INT32_C(  1551347697) } },
    { {  INT32_C(   248329111), -INT32_C(  1487503863) },
      {  INT32_C(  1958781041), -INT32_C(  1043917234) },
      { -INT32_C(   669649210),  INT32_C(  1677441000), -INT32_C(  1117068082), -INT32_C(   736132211) },
         INT8_C(           2),
      { -INT32_C(   770580524), -INT32_C(   944483839) } },
    { {  INT32_C(   708869340),  INT32_C(  1385533085) },
      { -INT32_C(   247862059), -INT32_C(  1325488026) },
      {  INT32_C(   336406366), -INT32_C(  1663802844),  INT32_C(   703717375), -INT32_C(   142889536) },
         INT8_C(           3),
      {  INT32_C(   725361617),  INT32_C(  1473728573) } },
    { { -INT32_C(  1655304717), -INT32_C(  1375709409) },
      { -INT32_C(  1167835738), -INT32_C(   803675889) },
      {  INT32_C(   549289233), -INT32_C(  1839174411), -INT32_C(  1003180527), -INT32_C(  1376256891) },
         INT8_C(           2),
      { -INT32_C(  1109759203), -INT32_C(  1000278377) } },
    { { -INT32_C(  1631645955),  INT32_C(  1416605267) },
      { -INT32_C(  2016232534), -INT32_C(  1634147735) },
      {  INT32_C(  1849717123), -INT32_C(  2036288379),  INT32_C(   254319773), -INT32_C(   652713346) },
         INT8_C(           1),
      {  INT32_C(   280187405),              INT32_MAX } },
    { { -INT32_C(    69331995), -INT32_C(  1893035184) },
      {  INT32_C(   427557586),  INT32_C(  2101034606) },
      { -INT32_C(  1873877286), -INT32_C(  1519446319), -INT32_C(  1587880230),  INT32_C(   361051262) },
         INT8_C(           3),
      {  INT32_C(     2552234), -INT32_C(  1539793288) } },
    { {  INT32_C(  1222779901),  INT32_C(  1555663721) },
      { -INT32_C(   228741304), -INT32_C(   320263411) },
      {  INT32_C(   912870415),  INT32_C(  1560452541),  INT32_C(   592883887),  INT32_C(  2130110077) },
         INT8_C(           0),
      {  INT32_C(  1125544623),  INT32_C(  1419523456) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int32x2_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlah_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlah_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlah_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlah_laneq_s32(a, b, v, 3); break;
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
      case 0: r = simde_vqrdmlah_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlah_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlah_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlah_laneq_s32(a, b, v, 3); break;
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
test_simde_vqrdmlahq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t v[4];
    int8_t lane;
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(   30004), -INT16_C(   19592), -INT16_C(    9280), -INT16_C(   14933),
         INT16_C(   15778),  INT16_C(   13228),  INT16_C(    7400), -INT16_C(   29332) },
      { -INT16_C(   31143),  INT16_C(   20240), -INT16_C(    3920),  INT16_C(     425),
        -INT16_C(   16359), -INT16_C(   27553), -INT16_C(   25285),  INT16_C(    5560) },
      { -INT16_C(   24894),  INT16_C(   21641),  INT16_C(   26140), -INT16_C(   20353) },
         INT8_C(       0),
      {          INT16_MAX,          INT16_MIN, -INT16_C(    6302), -INT16_C(   15256),
         INT16_C(   28206),          INT16_MAX,  INT16_C(   26609),          INT16_MIN } },
    { { -INT16_C(    6692),  INT16_C(   11425),  INT16_C(   18540), -INT16_C(   11639),
         INT16_C(    2888),  INT16_C(   16716), -INT16_C(   20806), -INT16_C(   27866) },
      {  INT16_C(   27360),  INT16_C(    8317),  INT16_C(     498),  INT16_C(    9079),
         INT16_C(    9020),  INT16_C(   29010),  INT16_C(   16794),  INT16_C(   24733) },
      { -INT16_C(    7849),  INT16_C(   26606), -INT16_C(   12942),  INT16_C(    8073) },
         INT8_C(       1),
      {  INT16_C(   15523),  INT16_C(   18178),  INT16_C(   18944), -INT16_C(    4267),
         INT16_C(   10212),          INT16_MAX, -INT16_C(    7170), -INT16_C(    7784) } },
    { {  INT16_C(   24068),  INT16_C(    6197), -INT16_C(   27574), -INT16_C(   10134),
        -INT16_C(   10920), -INT16_C(   22524),  INT16_C(   31684), -INT16_C(    4773) },
      {  INT16_C(   32328), -INT16_C(   28417), -INT16_C(   28195), -INT16_C(    4224),
         INT16_C(   18410),  INT16_C(   28751), -INT16_C(   32447), -INT16_C(   23301) },
      {  INT16_C(   19500), -INT16_C(   24933),  INT16_C(   32570),  INT16_C(   20918) },
         INT8_C(       1),
      { -INT16_C(     530),  INT16_C(   27819), -INT16_C(    6121), -INT16_C(    6920),
        -INT16_C(   24928),          INT16_MIN,          INT16_MAX,  INT16_C(   12957) } },
    { {  INT16_C(   31600), -INT16_C(   23594),  INT16_C(   31579), -INT16_C(   25761),
         INT16_C(   27800), -INT16_C(   30620), -INT16_C(   21915),  INT16_C(   10071) },
      { -INT16_C(   16108), -INT16_C(   24778), -INT16_C(     617), -INT16_C(    1404),
         INT16_C(   30728), -INT16_C(   24775),  INT16_C(   28107),  INT16_C(   21857) },
      { -INT16_C(   26158),  INT16_C(    9763),  INT16_C(   32628),  INT16_C(   31721) },
         INT8_C(       0),
      {          INT16_MAX, -INT16_C(    3814),  INT16_C(   32072), -INT16_C(   24640),
         INT16_C(    3270), -INT16_C(   10843),          INT16_MIN, -INT16_C(    7377) } },
    { { -INT16_C(   14607), -INT16_C(   18525),  INT16_C(    1250), -INT16_C(    8110),
         INT16_C(   22284),  INT16_C(   13943),  INT16_C(    9239), -INT16_C(   31755) },
      { -INT16_C(   12585),  INT16_C(   16037),  INT16_C(   22779),  INT16_C(   25728),
        -INT16_C(    2234),  INT16_C(    4828),  INT16_C(   23837),  INT16_C(   16129) },
      {  INT16_C(   26230), -INT16_C(   25776),  INT16_C(   26151), -INT16_C(   11326) },
         INT8_C(       1),
      { -INT16_C(    4707), -INT16_C(   31140), -INT16_C(   16668), -INT16_C(   28348),
         INT16_C(   24041),  INT16_C(   10145), -INT16_C(    9512),          INT16_MIN } },
    { {  INT16_C(     394), -INT16_C(   26662),  INT16_C(    8312), -INT16_C(   21238),
        -INT16_C(   16354),  INT16_C(   17827), -INT16_C(   10741), -INT16_C(   11298) },
      { -INT16_C(   11805), -INT16_C(    1273), -INT16_C(   15633), -INT16_C(   20517),
        -INT16_C(   12934),  INT16_C(   31174),  INT16_C(   31036), -INT16_C(   14861) },
      {  INT16_C(   21869), -INT16_C(   25272), -INT16_C(   18368),  INT16_C(    4023) },
         INT8_C(       2),
      {  INT16_C(    7011), -INT16_C(   25948),  INT16_C(   17075), -INT16_C(    9737),
        -INT16_C(    9104),  INT16_C(     353), -INT16_C(   28138), -INT16_C(    2968) } },
    { {  INT16_C(   19465), -INT16_C(    6060),  INT16_C(   19992), -INT16_C(   17221),
        -INT16_C(   31627),  INT16_C(   14208),  INT16_C(    1809),  INT16_C(   27237) },
      {  INT16_C(   29684),  INT16_C(   26201), -INT16_C(    8982),  INT16_C(   18504),
         INT16_C(     262),  INT16_C(   28612),  INT16_C(    3981), -INT16_C(    3389) },
      { -INT16_C(   10193),  INT16_C(   21607),  INT16_C(    1687),  INT16_C(   32576) },
         INT8_C(       3),
      {          INT16_MAX,  INT16_C(   19987),  INT16_C(   11063),  INT16_C(    1175),
        -INT16_C(   31367),          INT16_MAX,  INT16_C(    5767),  INT16_C(   23868) } },
    { {  INT16_C(   20885),  INT16_C(   15694), -INT16_C(   24391), -INT16_C(    6578),
         INT16_C(   30471), -INT16_C(   13080), -INT16_C(   24679),  INT16_C(     150) },
      { -INT16_C(    2360), -INT16_C(   23503), -INT16_C(   31000), -INT16_C(   21950),
         INT16_C(   17421),  INT16_C(    8396),  INT16_C(    9298),  INT16_C(   21034) },
      { -INT16_C(   21552), -INT16_C(   29645), -INT16_C(   26101),  INT16_C(   32046) },
         INT8_C(       0),
      {  INT16_C(   22437),  INT16_C(   31152), -INT16_C(    4002),  INT16_C(    7859),
         INT16_C(   19013), -INT16_C(   18602), -INT16_C(   30794), -INT16_C(   13684) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    simde_int16x8_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlahq_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahq_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahq_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahq_lane_s16(a, b, v, 3); break;
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
      case 0: r = simde_vqrdmlahq_lane_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahq_lane_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahq_lane_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahq_lane_s16(a, b, v, 3); break;
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
test_simde_vqrdmlahq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t v[2];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1330702347),  INT32_C(  1012346648), -INT32_C(   809180037),  INT32_C(  2126349934) },
      {  INT32_C(  1222425207),  INT32_C(   272005899), -INT32_C(  1458269316),  INT32_C(   288264288) },
      { -INT32_C(  1130107857), -INT32_C(   644439326) },
         INT8_C(           1),
      {  INT32_C(   963864221),  INT32_C(   930720276), -INT32_C(   371567347),  INT32_C(  2039844575) } },
    { { -INT32_C(  1485613372),  INT32_C(  1249806445),  INT32_C(  1529127517), -INT32_C(   208674682) },
      { -INT32_C(   293990264),  INT32_C(  1307197479),  INT32_C(  1987758109),  INT32_C(   151936289) },
      { -INT32_C(  1660451994), -INT32_C(   919421854) },
         INT8_C(           1),
      { -INT32_C(  1359744626),  INT32_C(   690144009),  INT32_C(   678090422), -INT32_C(   273724558) } },
    { {  INT32_C(   220333390), -INT32_C(   385739763), -INT32_C(  1323971000), -INT32_C(  2122003840) },
      { -INT32_C(  1783519708),  INT32_C(    23523302), -INT32_C(   327267857), -INT32_C(  1085606756) },
      {  INT32_C(   280559167),  INT32_C(   231128114) },
         INT8_C(           1),
      {  INT32_C(    28377774), -INT32_C(   383208011), -INT32_C(  1359193993),              INT32_MIN } },
    { { -INT32_C(   965306868), -INT32_C(   286824126), -INT32_C(   114318544), -INT32_C(   635792352) },
      { -INT32_C(   165371494), -INT32_C(   249976163), -INT32_C(  1717535512), -INT32_C(   241527084) },
      {  INT32_C(   428114194), -INT32_C(   795892383) },
         INT8_C(           0),
      { -INT32_C(   998274702), -INT32_C(   336658426), -INT32_C(   456719909), -INT32_C(   683942275) } },
    { { -INT32_C(  1612079873), -INT32_C(   579807187), -INT32_C(   482036652),  INT32_C(   309214066) },
      { -INT32_C(    91924046),  INT32_C(  2093512930), -INT32_C(  2082666674),  INT32_C(   546821543) },
      { -INT32_C(  1810412052), -INT32_C(  1074100502) },
         INT8_C(           0),
      { -INT32_C(  1534584335),              INT32_MIN,  INT32_C(  1273732176), -INT32_C(   151777715) } },
    { {  INT32_C(  1279138779),  INT32_C(   538183198),  INT32_C(  1913226108), -INT32_C(  1567599663) },
      { -INT32_C(  1538936978), -INT32_C(  1375303085),  INT32_C(  1295365005), -INT32_C(  1420030036) },
      {  INT32_C(  1804772433),  INT32_C(   845293549) },
         INT8_C(           1),
      {  INT32_C(   673381664), -INT32_C(     3164265),              INT32_MAX, -INT32_C(  2126552570) } },
    { {  INT32_C(  1988380241), -INT32_C(   960403009),  INT32_C(    73883945), -INT32_C(  1503093659) },
      {  INT32_C(   986290317),  INT32_C(   241692517), -INT32_C(  1621788307),  INT32_C(  1906001053) },
      { -INT32_C(    14917495),  INT32_C(  1338975677) },
         INT8_C(           1),
      {              INT32_MAX, -INT32_C(   809705516), -INT32_C(   937315883), -INT32_C(   314684587) } },
    { { -INT32_C(   233435695),  INT32_C(  1096797017),  INT32_C(   459751587),  INT32_C(   149608230) },
      { -INT32_C(  2024840009),  INT32_C(  2079291830), -INT32_C(  1120457879),  INT32_C(   443340455) },
      {  INT32_C(   163368684),  INT32_C(   355086783) },
         INT8_C(           0),
      { -INT32_C(   387474329),  INT32_C(  1254978044),  INT32_C(   374513346),  INT32_C(   183335121) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int32x4_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlahq_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahq_lane_s32(a, b, v, 1); break;
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
      case 0: r = simde_vqrdmlahq_lane_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahq_lane_s32(a, b, v, 1); break;
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
test_simde_vqrdmlahq_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t v[8];
    int8_t lane;
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(   11894),  INT16_C(    9141),  INT16_C(    9578),  INT16_C(   17503),
         INT16_C(    5869), -INT16_C(   31294),  INT16_C(   20566),  INT16_C(    3092) },
      { -INT16_C(   24297), -INT16_C(   19082),  INT16_C(     341),  INT16_C(   12985),
         INT16_C(   13365),  INT16_C(   23079), -INT16_C(   30055), -INT16_C(   11315) },
      {  INT16_C(   18488), -INT16_C(   32132), -INT16_C(   11649), -INT16_C(    6192),
        -INT16_C(   27158), -INT16_C(   30995),  INT16_C(   29745),  INT16_C(    6121) },
         INT8_C(       7),
      {  INT16_C(    7355),  INT16_C(    5577),  INT16_C(    9642),  INT16_C(   19929),
         INT16_C(    8366), -INT16_C(   26983),  INT16_C(   14952),  INT16_C(     978) } },
    { { -INT16_C(   11244), -INT16_C(    9008), -INT16_C(   31052), -INT16_C(    6283),
         INT16_C(   14984),  INT16_C(   24401),  INT16_C(   28687), -INT16_C(   17180) },
      { -INT16_C(   26769),  INT16_C(   27651), -INT16_C(   20916), -INT16_C(    2902),
         INT16_C(    5239), -INT16_C(    8289),  INT16_C(   32139), -INT16_C(   10249) },
      {  INT16_C(    2702),  INT16_C(   19710), -INT16_C(   26368), -INT16_C(   19997),
         INT16_C(   13159),  INT16_C(   27813), -INT16_C(   26462), -INT16_C(    1832) },
         INT8_C(       2),
      {  INT16_C(   10297), -INT16_C(   31258), -INT16_C(   14221), -INT16_C(    3948),
         INT16_C(   10768),  INT16_C(   31071),  INT16_C(    2825), -INT16_C(    8933) } },
    { {  INT16_C(   31040),  INT16_C(    8817), -INT16_C(    7267), -INT16_C(    8381),
        -INT16_C(   13533), -INT16_C(   30905), -INT16_C(   23845),  INT16_C(    1920) },
      { -INT16_C(   11893),  INT16_C(   26747),  INT16_C(   10575), -INT16_C(   20246),
        -INT16_C(   20698), -INT16_C(   25025), -INT16_C(   17752),  INT16_C(     560) },
      {  INT16_C(   15952), -INT16_C(   19444),  INT16_C(   16319), -INT16_C(   23516),
        -INT16_C(    6881), -INT16_C(   31568), -INT16_C(   21763), -INT16_C(   26605) },
         INT8_C(       0),
      {  INT16_C(   25250),  INT16_C(   21838), -INT16_C(    2119), -INT16_C(   18237),
        -INT16_C(   23609),          INT16_MIN, -INT16_C(   32487),  INT16_C(    2193) } },
    { {  INT16_C(   22456),  INT16_C(   29452),  INT16_C(   27966), -INT16_C(   27945),
        -INT16_C(   17543), -INT16_C(   20263),  INT16_C(   32158), -INT16_C(    1358) },
      { -INT16_C(     609),  INT16_C(   31572),  INT16_C(    8616),  INT16_C(    3808),
         INT16_C(   24859), -INT16_C(    6049), -INT16_C(    8546), -INT16_C(   29667) },
      { -INT16_C(    1626), -INT16_C(   10818), -INT16_C(    3123),  INT16_C(   23786),
        -INT16_C(   27664), -INT16_C(   12819), -INT16_C(    9281), -INT16_C(    1456) },
         INT8_C(       1),
      {  INT16_C(   22657),  INT16_C(   19029),  INT16_C(   25122), -INT16_C(   29202),
        -INT16_C(   25750), -INT16_C(   18266),          INT16_MAX,  INT16_C(    8436) } },
    { { -INT16_C(     590), -INT16_C(   24687),  INT16_C(   28468),  INT16_C(   14838),
        -INT16_C(   25952),  INT16_C(    8095), -INT16_C(    8314),  INT16_C(    6633) },
      {  INT16_C(   11032),  INT16_C(   21567),  INT16_C(   24889),  INT16_C(   25996),
        -INT16_C(   31601),  INT16_C(    6954),  INT16_C(    5528), -INT16_C(   28513) },
      {  INT16_C(   32543),  INT16_C(    6860), -INT16_C(    3066),  INT16_C(   12285),
         INT16_C(   32017), -INT16_C(   28018),  INT16_C(   22961),  INT16_C(     705) },
         INT8_C(       3),
      {  INT16_C(    3546), -INT16_C(   16601),          INT16_MAX,  INT16_C(   24584),
                 INT16_MIN,  INT16_C(   10702), -INT16_C(    6242), -INT16_C(    4057) } },
    { { -INT16_C(   15147),  INT16_C(   18214),  INT16_C(   22737),  INT16_C(   32748),
         INT16_C(    6165),  INT16_C(   17093),  INT16_C(   11819),  INT16_C(    6152) },
      {  INT16_C(   22603), -INT16_C(   28536),  INT16_C(   13901), -INT16_C(   25308),
         INT16_C(    7321), -INT16_C(   24641),  INT16_C(   13660), -INT16_C(   13061) },
      {  INT16_C(   22231),  INT16_C(   31535), -INT16_C(   25812),  INT16_C(    7082),
        -INT16_C(    4022),  INT16_C(   31162),  INT16_C(    3789), -INT16_C(    2542) },
         INT8_C(       7),
      { -INT16_C(   16900),  INT16_C(   20428),  INT16_C(   21659),          INT16_MAX,
         INT16_C(    5597),  INT16_C(   19005),  INT16_C(   10759),  INT16_C(    7165) } },
    { {  INT16_C(   22340), -INT16_C(   22408), -INT16_C(   26200), -INT16_C(    3961),
        -INT16_C(   13845), -INT16_C(   12261),  INT16_C(    8872), -INT16_C(     494) },
      { -INT16_C(    8274), -INT16_C(   20304), -INT16_C(   30830),  INT16_C(    7819),
        -INT16_C(   13249), -INT16_C(   20018),  INT16_C(    1197), -INT16_C(    1141) },
      {  INT16_C(   22173),  INT16_C(   32441),  INT16_C(   26560),  INT16_C(   29136),
        -INT16_C(     683), -INT16_C(   29937), -INT16_C(   23469), -INT16_C(     444) },
         INT8_C(       2),
      {  INT16_C(   15634),          INT16_MIN,          INT16_MIN,  INT16_C(    2377),
        -INT16_C(   24584), -INT16_C(   28487),  INT16_C(    9842), -INT16_C(    1419) } },
    { { -INT16_C(   19819),  INT16_C(   14061),  INT16_C(   24637), -INT16_C(   18721),
         INT16_C(   17549), -INT16_C(   31751), -INT16_C(    7307), -INT16_C(    9335) },
      { -INT16_C(   32224),  INT16_C(    9848),  INT16_C(    9219), -INT16_C(    4061),
        -INT16_C(   31537), -INT16_C(   15355), -INT16_C(   19659), -INT16_C(   23513) },
      { -INT16_C(   27811), -INT16_C(   29264),  INT16_C(   20933), -INT16_C(   32194),
         INT16_C(   11742),  INT16_C(   27157), -INT16_C(   24496), -INT16_C(   21740) },
         INT8_C(       3),
      {  INT16_C(   11841),  INT16_C(    4386),  INT16_C(   15579), -INT16_C(   14731),
                 INT16_MAX, -INT16_C(   16665),  INT16_C(   12008),  INT16_C(   13766) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    int8_t lane = test_vec[i].lane;
    simde_int16x8_t r;
    switch(lane) {
      case 0: r = simde_vqrdmlahq_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahq_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahq_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahq_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlahq_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlahq_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlahq_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlahq_laneq_s16(a, b, v, 7); break;
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
      case 0: r = simde_vqrdmlahq_laneq_s16(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahq_laneq_s16(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahq_laneq_s16(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahq_laneq_s16(a, b, v, 3); break;
      case 4: r = simde_vqrdmlahq_laneq_s16(a, b, v, 4); break;
      case 5: r = simde_vqrdmlahq_laneq_s16(a, b, v, 5); break;
      case 6: r = simde_vqrdmlahq_laneq_s16(a, b, v, 6); break;
      case 7: r = simde_vqrdmlahq_laneq_s16(a, b, v, 7); break;
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
test_simde_vqrdmlahq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1080451557),  INT32_C(  1254855957), -INT32_C(    84423964), -INT32_C(  1741313274) },
      {  INT32_C(   970928218),  INT32_C(   452403695), -INT32_C(  1781903823),  INT32_C(  1799704182) },
      {  INT32_C(    72950264),  INT32_C(   455554498), -INT32_C(   353069887), -INT32_C(  1198976491) },
         INT8_C(           2),
      {  INT32_C(   920820299),  INT32_C(  1180475823),  INT32_C(   208540586), -INT32_C(  2037204399) } },
    { {  INT32_C(   178100509), -INT32_C(   383444816), -INT32_C(  1224253684), -INT32_C(   312787276) },
      { -INT32_C(   569635627),  INT32_C(   723226070),  INT32_C(   752320948), -INT32_C(   459542052) },
      {  INT32_C(  2025929195),  INT32_C(   222602153), -INT32_C(    46297237),  INT32_C(   414938954) },
         INT8_C(           0),
      { -INT32_C(   359291917),  INT32_C(   298844342), -INT32_C(   514516511), -INT32_C(   746317776) } },
    { { -INT32_C(   329198423), -INT32_C(   346904423),  INT32_C(    12124223),  INT32_C(    56782149) },
      {  INT32_C(  1036944033), -INT32_C(    78540579), -INT32_C(   601343388),  INT32_C(   504248231) },
      {  INT32_C(   484923826), -INT32_C(  1630592567),  INT32_C(  1817137280),  INT32_C(  1338391498) },
         INT8_C(           2),
      {  INT32_C(   548233012), -INT32_C(   413363143), -INT32_C(   496714803),  INT32_C(   483462119) } },
    { {  INT32_C(   306589519),  INT32_C(  2137129678), -INT32_C(  1815118202),  INT32_C(   530426686) },
      {  INT32_C(   986802362),  INT32_C(  1606844476), -INT32_C(   741096035), -INT32_C(  1175145703) },
      {  INT32_C(  1121880009), -INT32_C(  1082386682),  INT32_C(   733845860), -INT32_C(  1370160353) },
         INT8_C(           2),
      {  INT32_C(   643803182),              INT32_MAX, -INT32_C(  2068368213),  INT32_C(   128851657) } },
    { {  INT32_C(   661086431),  INT32_C(  1538399720), -INT32_C(  1725810926), -INT32_C(   893417029) },
      { -INT32_C(  1975083035),  INT32_C(  1792462811),  INT32_C(   547535612),  INT32_C(   306822795) },
      {  INT32_C(   216480384), -INT32_C(  1367039871), -INT32_C(  1676747009), -INT32_C(  1842360088) },
         INT8_C(           3),
      {              INT32_MAX,  INT32_C(      617607),              INT32_MIN, -INT32_C(  1156645144) } },
    { {  INT32_C(  2038394451), -INT32_C(   737749482), -INT32_C(   263230876),  INT32_C(   676648563) },
      { -INT32_C(  2140768071),  INT32_C(   214438211), -INT32_C(  1417649802),  INT32_C(   779730178) },
      {  INT32_C(   992777399), -INT32_C(   641726646), -INT32_C(   864194785),  INT32_C(  1577322281) },
         INT8_C(           1),
      {              INT32_MAX, -INT32_C(   801829464),  INT32_C(   160401524),  INT32_C(   443643933) } },
    { {  INT32_C(  1108739077),  INT32_C(  1400290115), -INT32_C(  1105176588),  INT32_C(   885077020) },
      { -INT32_C(  1850212451),  INT32_C(  1796682301), -INT32_C(  1497364897), -INT32_C(   699663367) },
      { -INT32_C(  1342341913),  INT32_C(   159508270),  INT32_C(    99310147),  INT32_C(  1520047806) },
         INT8_C(           0),
      {              INT32_MAX,  INT32_C(   277225937), -INT32_C(   169208735),  INT32_C(  1322420263) } },
    { {  INT32_C(  1842859813),  INT32_C(   588680360), -INT32_C(  1450654390), -INT32_C(   459596768) },
      {  INT32_C(  1814410868), -INT32_C(  1546818036), -INT32_C(   474987631), -INT32_C(  1333896560) },
      { -INT32_C(  1719254391),  INT32_C(  1977475937), -INT32_C(  1550342396), -INT32_C(  1346010523) },
         INT8_C(           2),
      {  INT32_C(   532974127),  INT32_C(  1705381566), -INT32_C(  1107744463),  INT32_C(   503389093) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int32x4_t r;
    int8_t lane = test_vec[i].lane;
    switch(lane) {
      case 0: r = simde_vqrdmlahq_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahq_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahq_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahq_laneq_s32(a, b, v, 3); break;
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
      case 0: r = simde_vqrdmlahq_laneq_s32(a, b, v, 0); break;
      case 1: r = simde_vqrdmlahq_laneq_s32(a, b, v, 1); break;
      case 2: r = simde_vqrdmlahq_laneq_s32(a, b, v, 2); break;
      case 3: r = simde_vqrdmlahq_laneq_s32(a, b, v, 3); break;
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
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahh_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahs_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahh_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahs_laneq_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlah_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlah_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlah_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlah_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahq_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahq_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
