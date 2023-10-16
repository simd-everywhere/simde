#define SIMDE_TEST_ARM_NEON_INSN qdmlal_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlal_high_n.h"

static int
test_simde_vqdmlal_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t c;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(    413046),  INT32_C(    443321),  INT32_C(    536360), -INT32_C(     57359) },
       {  -INT16_C(      5373),  INT16_C(      7648), -INT16_C(      2270), -INT16_C(      9644),
          -INT16_C(       442),  INT16_C(      7552), -INT16_C(      9649), -INT16_C(      8624) },
           INT16_C(      9006),
       {  -INT32_C(   8374350),  INT32_C( 136469945), -INT32_C( 173261428), -INT32_C( 155392847) } },
     { {  -INT32_C(    328100),  INT32_C(    888774), -INT32_C(    586192),  INT32_C(    106665) },
       {  -INT16_C(      8058), -INT16_C(      1793),  INT16_C(      5117),  INT16_C(      3494),
           INT16_C(      3150), -INT16_C(      1621),  INT16_C(      2769), -INT16_C(      6834) },
           INT16_C(      1088),
       {   INT32_C(   6526300), -INT32_C(   2638522),  INT32_C(   5439152), -INT32_C(  14764119) } },
     { {  -INT32_C(    306051),  INT32_C(    407057),  INT32_C(    601575), -INT32_C(    219908) },
       {  -INT16_C(      4202),  INT16_C(      9749), -INT16_C(      3094),  INT16_C(      8199),
          -INT16_C(      9563),  INT16_C(      6040),  INT16_C(      6427),  INT16_C(      9933) },
           INT16_C(      4283),
       {  -INT32_C(  82222709),  INT32_C(  52145697),  INT32_C(  55655257),  INT32_C(  84866170) } },
     { {  -INT32_C(    757353),  INT32_C(    689083), -INT32_C(    350090),  INT32_C(    926036) },
       {  -INT16_C(      4396), -INT16_C(      5546),  INT16_C(        44), -INT16_C(      8707),
           INT16_C(      1167), -INT16_C(      6498),  INT16_C(      9216), -INT16_C(      7953) },
          -INT16_C(      4177),
       {  -INT32_C(  10506471),  INT32_C(  54973375), -INT32_C(  77340554),  INT32_C(  67365398) } },
     { {   INT32_C(    550132), -INT32_C(    561004),  INT32_C(    619629), -INT32_C(    862339) },
       {   INT16_C(      7220),  INT16_C(      4704), -INT16_C(      6936),  INT16_C(      6210),
           INT16_C(      8306), -INT16_C(       274),  INT16_C(      6211), -INT16_C(      9252) },
           INT16_C(      5964),
       {   INT32_C(  99624100), -INT32_C(   3829276),  INT32_C(  74704437), -INT32_C( 111220195) } },
     { {  -INT32_C(    190829),  INT32_C(     83384), -INT32_C(    684177), -INT32_C(    304022) },
       {   INT16_C(      3361), -INT16_C(      8991),  INT16_C(      2958), -INT16_C(      5174),
           INT16_C(      4223),  INT16_C(      1411),  INT16_C(      3399), -INT16_C(      3695) },
          -INT16_C(      9502),
       {  -INT32_C(  80444721), -INT32_C(  26731260), -INT32_C(  65278773),  INT32_C(  69915758) } },
     { {  -INT32_C(    574255),  INT32_C(    987356),  INT32_C(    971545), -INT32_C(      3766) },
       {  -INT16_C(      2909), -INT16_C(      1186),  INT16_C(      4126),  INT16_C(        63),
           INT16_C(      6070),  INT16_C(       284),  INT16_C(      8912), -INT16_C(      4007) },
           INT16_C(      3652),
       {   INT32_C(  43761025),  INT32_C(   3061692),  INT32_C(  66064793), -INT32_C(  29270894) } },
     { {  -INT32_C(     85805), -INT32_C(    567351),  INT32_C(    225206), -INT32_C(    716760) },
       {  -INT16_C(      6426), -INT16_C(      6271), -INT16_C(       104), -INT16_C(      6015),
           INT16_C(       485),  INT16_C(      5900), -INT16_C(      5869), -INT16_C(      1878) },
           INT16_C(      7731),
       {   INT32_C(   7413265),  INT32_C(  90658449), -INT32_C(  90521272), -INT32_C(  29754396) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    int16_t c = test_vec[i].c;
    simde_int32x4_t r = simde_vqdmlal_high_n_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlal_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t c;
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(     52569594),  INT64_C(     46784526) },
       {  -INT32_C(       718351),  INT32_C(       135729), -INT32_C(       794610),  INT32_C(        77651) },
          -INT32_C(       972135),
       {   INT64_C(1544988954294), -INT64_C( 150927725244) } },
     { {   INT64_C(     11830892),  INT64_C(     32236020) },
       {   INT32_C(       429132),  INT32_C(       506878),  INT32_C(       167297), -INT32_C(       960619) },
          -INT32_C(       451038),
       {  -INT64_C( 150902777680),  INT64_C( 866583581064) } },
     { {   INT64_C(     57262611), -INT64_C(     10112385) },
       {   INT32_C(       786561),  INT32_C(        88630),  INT32_C(       867798),  INT32_C(       990063) },
           INT32_C(       318577),
       {   INT64_C( 552978229503),  INT64_C( 630812488317) } },
     { {   INT64_C(     59464933), -INT64_C(     99742040) },
       {  -INT32_C(       544326), -INT32_C(       464399), -INT32_C(       522580),  INT32_C(       887554) },
           INT32_C(       207064),
       {  -INT64_C( 216355545307),  INT64_C( 367461220872) } },
     { {  -INT64_C(     57110833),  INT64_C(     51531791) },
       {   INT32_C(       254945),  INT32_C(       533216), -INT32_C(       261726),  INT32_C(       879663) },
           INT32_C(       268600),
       {  -INT64_C( 140656318033),  INT64_C( 472606495391) } },
     { {  -INT64_C(     97431652), -INT64_C(     32423614) },
       {  -INT32_C(       167998),  INT32_C(       569412), -INT32_C(       552599),  INT32_C(       643674) },
           INT32_C(       101122),
       {  -INT64_C( 111857263808),  INT64_C( 130146780842) } },
     { {  -INT64_C(     19553586), -INT64_C(       346370) },
       {  -INT32_C(       583295), -INT32_C(         5387),  INT32_C(       721742), -INT32_C(       978622) },
           INT32_C(       631850),
       {   INT64_C( 912045811814), -INT64_C(1236684967770) } },
     { {   INT64_C(     32084642), -INT64_C(     49169174) },
       {   INT32_C(       535706),  INT32_C(        97715), -INT32_C(       835258), -INT32_C(       994676) },
          -INT32_C(       559353),
       {   INT64_C( 934440220790),  INT64_C(1112700840082) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    int32_t c = test_vec[i].c;
    simde_int64x2_t r = simde_vqdmlal_high_n_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_high_n_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
