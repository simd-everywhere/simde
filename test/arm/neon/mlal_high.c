#define SIMDE_TEST_ARM_NEON_INSN mlal_high

#include "test-neon.h"
#include "../../../simde/arm/neon/mlal_high.h"

static int
test_simde_vmlal_high_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t b[16];
    int8_t c[16];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  3820),  INT16_C( 12612),  INT16_C( 12948),  INT16_C( 16793),  INT16_C( 15561), -INT16_C( 25824),  INT16_C( 27015),  INT16_C(  5311) },
      {  INT8_C(  40), -INT8_C( 122), -INT8_C(  54), -INT8_C(  97),  INT8_C(   0),  INT8_C( 110), -INT8_C(  59), -INT8_C( 126),
        -INT8_C(  26),  INT8_C(  43), -INT8_C(  37), -INT8_C(  65), -INT8_C(   9),  INT8_C(  46), -INT8_C(  80), -INT8_C(  29) },
      {  INT8_C(  60), -INT8_C(  12),  INT8_C(  20), -INT8_C(  47),  INT8_C(  38), -INT8_C(  82),  INT8_C(  18), -INT8_C(  17),
        -INT8_C(  22),  INT8_C(  51), -INT8_C( 118),  INT8_C( 113), -INT8_C( 100),  INT8_C(  73), -INT8_C( 123), -INT8_C(  60) },
      {  INT16_C(  4392),  INT16_C( 14805),  INT16_C( 17314),  INT16_C(  9448),  INT16_C( 16461), -INT16_C( 22466), -INT16_C( 28681),  INT16_C(  7051) } },
    { {  INT16_C( 20431), -INT16_C( 12444),  INT16_C( 10685), -INT16_C( 23470),  INT16_C( 11604),  INT16_C( 19555),  INT16_C(  4955), -INT16_C( 26577) },
      {  INT8_C(   7),  INT8_C(  68),  INT8_C( 105),  INT8_C(  45), -INT8_C(  14),  INT8_C( 123),  INT8_C(  29), -INT8_C(  36),
        -INT8_C(  82), -INT8_C(  89),  INT8_C(  77),  INT8_C(  74), -INT8_C(  15), -INT8_C(  46),  INT8_C(  15), -INT8_C(  64) },
      {  INT8_C(  34),  INT8_C( 115), -INT8_C( 112), -INT8_C(  33), -INT8_C( 100), -INT8_C(  30), -INT8_C( 125), -INT8_C(  15),
         INT8_C(  15), -INT8_C(  26),  INT8_C(  61),  INT8_C( 107), -INT8_C(   7),  INT8_C( 108),  INT8_C(   3),  INT8_C(   0) },
      {  INT16_C( 19201), -INT16_C( 10130),  INT16_C( 15382), -INT16_C( 15552),  INT16_C( 11709),  INT16_C( 14587),  INT16_C(  5000), -INT16_C( 26577) } },
    { {  INT16_C( 27824), -INT16_C( 24018),  INT16_C( 19431), -INT16_C( 27010), -INT16_C( 13326), -INT16_C(  7200), -INT16_C(  4194), -INT16_C( 16220) },
      {  INT8_C(  98),  INT8_C(  52), -INT8_C(  97), -INT8_C(   1),  INT8_C(  22),  INT8_C(  35), -INT8_C(  16),  INT8_C(  37),
         INT8_C(   9),  INT8_C(  45), -INT8_C( 112),  INT8_C(   3), -INT8_C( 103), -INT8_C( 109),  INT8_C(   3),  INT8_C(  74) },
      { -INT8_C(   1),  INT8_C(  49), -INT8_C(  20), -INT8_C(  25),  INT8_C( 124),  INT8_C( 107),  INT8_C( 125),  INT8_C( 111),
         INT8_C(  54),  INT8_C(  93),  INT8_C(  82), -INT8_C(  44),  INT8_C(  77), -INT8_C(  10), -INT8_C( 108), -INT8_C(  81) },
      {  INT16_C( 28310), -INT16_C( 19833),  INT16_C( 10247), -INT16_C( 27142), -INT16_C( 21257), -INT16_C(  6110), -INT16_C(  4518), -INT16_C( 22214) } },
    { {  INT16_C( 13354),  INT16_C( 16558), -INT16_C( 25001),  INT16_C( 24678), -INT16_C(  2357),  INT16_C( 25955),  INT16_C( 26506), -INT16_C( 30289) },
      { -INT8_C( 104), -INT8_C( 101),  INT8_C( 112),  INT8_C(  21),  INT8_C(   6), -INT8_C(  19), -INT8_C( 124),  INT8_C(  61),
         INT8_C(  75), -INT8_C(  42),  INT8_C(  17), -INT8_C( 104), -INT8_C(  51), -INT8_C(  90),  INT8_C(  71), -INT8_C(   9) },
      { -INT8_C(  38), -INT8_C(  10),  INT8_C(  56),  INT8_C(  49), -INT8_C( 108), -INT8_C(  98), -INT8_C( 111),  INT8_C(  96),
        -INT8_C( 108), -INT8_C(  11), -INT8_C(  59),  INT8_C(  30),  INT8_C(  92),  INT8_C( 116), -INT8_C(  88), -INT8_C(  12) },
      {  INT16_C(  5254),  INT16_C( 17020), -INT16_C( 26004),  INT16_C( 21558), -INT16_C(  7049),  INT16_C( 15515),  INT16_C( 20258), -INT16_C( 30181) } },
    { {  INT16_C(  6159),  INT16_C(  5641), -INT16_C( 29434),  INT16_C( 20819),  INT16_C( 25700),  INT16_C( 12777),  INT16_C( 12298), -INT16_C(  7128) },
      {  INT8_C(  38),  INT8_C(  96),  INT8_C(  21), -INT8_C(  69), -INT8_C(   2), -INT8_C(  89),  INT8_C(  27), -INT8_C( 109),
        -INT8_C( 100), -INT8_C(  32), -INT8_C(  79), -INT8_C(   8),  INT8_C(  84),  INT8_C(  89), -INT8_C(  20),  INT8_C(  99) },
      {  INT8_C( 114), -INT8_C(  10),  INT8_C( 121),  INT8_C( 120), -INT8_C( 125), -INT8_C(  52), -INT8_C(  55), -INT8_C(  25),
         INT8_C(  49), -INT8_C(  78),  INT8_C(  24),  INT8_C(  59), -INT8_C(  30),  INT8_C(  65),  INT8_C(  32),  INT8_C(   9) },
      {  INT16_C(  1259),  INT16_C(  8137), -INT16_C( 31330),  INT16_C( 20347),  INT16_C( 23180),  INT16_C( 18562),  INT16_C( 11658), -INT16_C(  6237) } },
    { {  INT16_C( 13729), -INT16_C( 24380), -INT16_C(  8228),  INT16_C( 30771), -INT16_C(  6977),  INT16_C(  4976),  INT16_C( 23870), -INT16_C( 20362) },
      {  INT8_C(  83), -INT8_C(  16),  INT8_C(  40), -INT8_C(  42), -INT8_C(  68), -INT8_C(  15), -INT8_C(  66), -INT8_C(  19),
        -INT8_C(  93), -INT8_C(  42),  INT8_C(  41), -INT8_C( 123),  INT8_C(  23),  INT8_C(  73), -INT8_C( 114), -INT8_C(  71) },
      {  INT8_C( 126),  INT8_C(  82),  INT8_C(  89),  INT8_C(  91),  INT8_C(  49), -INT8_C( 116), -INT8_C(  45), -INT8_C(  16),
         INT8_C( 112),  INT8_C(  68),  INT8_C(   3), -INT8_C(  82), -INT8_C(  95),  INT8_C( 122),  INT8_C(  94), -INT8_C(  12) },
      {  INT16_C(  3313), -INT16_C( 27236), -INT16_C(  8105), -INT16_C( 24679), -INT16_C(  9162),  INT16_C( 13882),  INT16_C( 13154), -INT16_C( 19510) } },
    { { -INT16_C( 31126),  INT16_C(  9930), -INT16_C( 30601),  INT16_C(  6676),  INT16_C( 15711),  INT16_C( 30368),  INT16_C( 11910),  INT16_C(  1071) },
      { -INT8_C( 127), -INT8_C( 120),  INT8_C(  95), -INT8_C(  78),  INT8_C(  20),  INT8_C(  51), -INT8_C(  93), -INT8_C( 123),
         INT8_C( 119), -INT8_C(  90),  INT8_C(  51),  INT8_C(  24),  INT8_C(  32), -INT8_C( 110),  INT8_C(  12), -INT8_C( 118) },
      {  INT8_C(  24), -INT8_C(  42), -INT8_C(  79), -INT8_C( 112),  INT8_C(  95), -INT8_C(  59), -INT8_C(  86), -INT8_C(  66),
         INT8_C(   2),  INT8_C(  74),  INT8_C(  52), -INT8_C( 120),  INT8_C( 121),  INT8_C( 100), -INT8_C( 116), -INT8_C(   6) },
      { -INT16_C( 30888),  INT16_C(  3270), -INT16_C( 27949),  INT16_C(  3796),  INT16_C( 19583),  INT16_C( 19368),  INT16_C( 10518),  INT16_C(  1779) } },
    { { -INT16_C(  4884),  INT16_C(   428),  INT16_C( 20255), -INT16_C( 27002), -INT16_C( 17930),  INT16_C(  5806), -INT16_C( 17845),  INT16_C( 25761) },
      { -INT8_C( 112),  INT8_C(  82), -INT8_C(  12), -INT8_C(  17),  INT8_C(  23), -INT8_C(  98), -INT8_C(  83),  INT8_C(  25),
        -INT8_C(  23), -INT8_C(  30), -INT8_C(  95),  INT8_C(  98),  INT8_C(  70),  INT8_C(  45),  INT8_C(  92),  INT8_C(  50) },
      {  INT8_C(  25),  INT8_C(   8),  INT8_C(  51),  INT8_C(  56),  INT8_C(  88), -INT8_C(  71), -INT8_C(  50),  INT8_C(  78),
         INT8_C( 115),  INT8_C( 124),  INT8_C( 100), -INT8_C(  66),  INT8_C(  54),  INT8_C(   5),  INT8_C(  34), -INT8_C(  57) },
      { -INT16_C(  7529), -INT16_C(  3292),  INT16_C( 10755),  INT16_C( 32066), -INT16_C( 14150),  INT16_C(  6031), -INT16_C( 14717),  INT16_C( 22911) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t c = simde_vld1q_s8(test_vec[i].c);
    simde_int16x8_t r = simde_vmlal_high_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t c = simde_test_arm_neon_random_i8x16();
    simde_int16x8_t r = simde_vmlal_high_s8(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t c[8];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1115600880), -INT32_C(  1829145922),  INT32_C(   182690733), -INT32_C(  1887574040) },
      {  INT16_C( 27742), -INT16_C( 20465),  INT16_C( 27015),  INT16_C(  8158), -INT16_C( 12479),  INT16_C( 32288), -INT16_C(  7148),  INT16_C(  1054) },
      { -INT16_C( 25189),  INT16_C( 23110),  INT16_C( 16399), -INT16_C( 17172), -INT16_C( 12317), -INT16_C( 13370),  INT16_C( 17335),  INT16_C(  5466) },
      {  INT32_C(  1269304723),  INT32_C(  2034130814),  INT32_C(    58780153), -INT32_C(  1881812876) } },
    { {  INT32_C(   918907567),  INT32_C(   357934291), -INT32_C(  2020379277), -INT32_C(   175394470) },
      { -INT16_C( 11698),  INT16_C( 23887),  INT16_C( 15378), -INT16_C(  2791), -INT16_C(  8437), -INT16_C( 15680),  INT16_C(  6946), -INT16_C( 11561) },
      { -INT16_C( 25211),  INT16_C( 22536),  INT16_C( 24129), -INT16_C( 19347),  INT16_C(   211),  INT16_C( 11579), -INT16_C( 14670),  INT16_C(    35) },
      {  INT32_C(   917127360),  INT32_C(   176375571), -INT32_C(  2122277097), -INT32_C(   175799105) } },
    { { -INT32_C(  1436650856), -INT32_C(  1163954258),  INT32_C(  2038194263),  INT32_C(     4936827) },
      {  INT16_C( 21745),  INT16_C( 12888), -INT16_C( 14670), -INT16_C( 31258),  INT16_C(  8646),  INT16_C( 30899), -INT16_C( 10521), -INT16_C( 32647) },
      { -INT16_C( 10424), -INT16_C(  2262), -INT16_C( 13746), -INT16_C( 23119),  INT16_C( 11562), -INT16_C( 23265),  INT16_C( 27265),  INT16_C( 29349) },
      { -INT32_C(  1336685804), -INT32_C(  1882819493),  INT32_C(  1751339198), -INT32_C(   953219976) } },
    { {  INT32_C(  1889861054), -INT32_C(  1963554109), -INT32_C(  1828542037), -INT32_C(   955024513) },
      {  INT16_C( 15698), -INT16_C( 24130),  INT16_C( 28423),  INT16_C( 12614),  INT16_C( 26013),  INT16_C(  7894),  INT16_C( 31696), -INT16_C( 29039) },
      {  INT16_C( 13689),  INT16_C( 15615), -INT16_C(  2624),  INT16_C( 27590), -INT16_C( 13922),  INT16_C(  7678),  INT16_C(  4420), -INT16_C( 26652) },
      {  INT32_C(  1527708068), -INT32_C(  1902943977), -INT32_C(  1688445717), -INT32_C(   181077085) } },
    { {  INT32_C(  1446552399), -INT32_C(  1350009326), -INT32_C(  1261543708),  INT32_C(  1396858842) },
      {  INT16_C( 16788),  INT16_C( 21647),  INT16_C( 22070), -INT16_C( 11072), -INT16_C( 16865),  INT16_C( 25585), -INT16_C( 10544),  INT16_C(  8186) },
      {  INT16_C( 12921), -INT16_C( 29835), -INT16_C(   591), -INT16_C( 27333),  INT16_C(  2396),  INT16_C( 13897), -INT16_C( 29848), -INT16_C(   887) },
      {  INT32_C(  1406143859), -INT32_C(   994454581), -INT32_C(   946826396),  INT32_C(  1389597860) } },
    { {  INT32_C(    55646413), -INT32_C(  1915219602), -INT32_C(  1611544113),  INT32_C(   415165343) },
      {  INT16_C( 13342), -INT16_C( 12380), -INT16_C(  8399), -INT16_C( 29340), -INT16_C( 21016),  INT16_C( 20675),  INT16_C( 19512),  INT16_C(  1356) },
      { -INT16_C( 25243), -INT16_C( 11511), -INT16_C(  7762),  INT16_C( 32353),  INT16_C( 21162),  INT16_C( 18973), -INT16_C(  9155),  INT16_C( 23394) },
      { -INT32_C(   389094179), -INT32_C(  1522952827), -INT32_C(  1790176473),  INT32_C(   446887607) } },
    { {  INT32_C(  1093273104), -INT32_C(   842035483),  INT32_C(  1948095035),  INT32_C(  1148807903) },
      { -INT16_C( 32249), -INT16_C( 18921),  INT16_C( 30819),  INT16_C(  3636),  INT16_C( 20938),  INT16_C(  2136), -INT16_C( 17875),  INT16_C( 15715) },
      { -INT16_C( 28991), -INT16_C( 22913),  INT16_C( 19996),  INT16_C( 22644), -INT16_C( 28192), -INT16_C( 16436),  INT16_C( 17915),  INT16_C(   771) },
      {  INT32_C(   502989008), -INT32_C(   877142779),  INT32_C(  1627864410),  INT32_C(  1160924168) } },
    { {  INT32_C(   733551560),  INT32_C(  1580854675),  INT32_C(  1818661182),  INT32_C(   229230924) },
      {  INT16_C( 10327),  INT16_C( 29875),  INT16_C( 10102),  INT16_C( 22476), -INT16_C( 26439), -INT16_C( 19434),  INT16_C(  6877), -INT16_C( 23113) },
      {  INT16_C( 28725), -INT16_C( 14127),  INT16_C(  2653), -INT16_C( 25562), -INT16_C( 29540), -INT16_C(  6136), -INT16_C( 20138), -INT16_C( 21003) },
      {  INT32_C(  1514559620),  INT32_C(  1700101699),  INT32_C(  1680172156),  INT32_C(   714673263) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int32x4_t r = simde_vmlal_high_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t c = simde_test_arm_neon_random_i16x8();
    simde_int32x4_t r = simde_vmlal_high_s16(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t c[4];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8645752205991848051),  INT64_C( 1679351349465497540) },
      {  INT32_C(  1094402736), -INT32_C(  1664121706), -INT32_C(  1376308970), -INT32_C(  1591905747) },
      { -INT32_C(   325104102), -INT32_C(   211510737), -INT32_C(  2121246119),  INT32_C(  1268309659) },
      { -INT64_C( 6881501806560316135), -INT64_C(  339678085672212733) } },
    { {  INT64_C( 7877741705012499233), -INT64_C( 2928685844663743859) },
      { -INT32_C(  1262159227), -INT32_C(   291034988),  INT32_C(   493827970),  INT32_C(   929564438) },
      {  INT32_C(   854521306), -INT32_C(   559988143),  INT32_C(  1234745996),  INT32_C(  1998714097) },
      {  INT64_C( 8487493813682807353), -INT64_C( 1070752298363261373) } },
    { { -INT64_C( 8110469398928824850), -INT64_C( 4515117118497431542) },
      {  INT32_C(  1525892617),  INT32_C(   339252104),  INT32_C(  1046401357), -INT32_C(  1279950907) },
      {  INT32_C(  1899422052), -INT32_C(  1107253324),  INT32_C(  1860152455), -INT32_C(   902809920) },
      { -INT64_C( 6164003345789943415), -INT64_C( 3359564742544834102) } },
    { {  INT64_C(  223312692866458492),  INT64_C( 6532180949562717998) },
      { -INT32_C(  1932796456),  INT32_C(   206293892),  INT32_C(   930753143), -INT32_C(   587093408) },
      { -INT32_C(  2065619250), -INT32_C(  1316423037),  INT32_C(  1738852977), -INT32_C(  1698608447) },
      {  INT64_C( 1841755566424115203),  INT64_C( 7529422771569535374) } },
    { { -INT64_C( 3550963684817335257), -INT64_C( 6063806773280230757) },
      { -INT32_C(  1339049427),  INT32_C(   643938229),  INT32_C(  1133380993),  INT32_C(  2010992464) },
      {  INT32_C(   857932764),  INT32_C(   268622709), -INT32_C(   351533042),  INT32_C(  1033299215) },
      { -INT64_C( 3949384553031605963), -INT64_C( 3985849838858114997) } },
    { { -INT64_C(  109406366209292896),  INT64_C( 3826967153714727252) },
      { -INT32_C(  1754775774),  INT32_C(   698837531), -INT32_C(  2112572302),  INT32_C(   968862361) },
      { -INT32_C(   326194065),  INT32_C(  1357581051),  INT32_C(  1827941395),  INT32_C(  1839272011) },
      { -INT64_C( 3971064726965534186),  INT64_C( 5608968576813405223) } },
    { { -INT64_C( 1759593037895038384), -INT64_C( 4525510338717046689) },
      { -INT32_C(   793853484), -INT32_C(   568288821),  INT32_C(   273355973),  INT32_C(  1971186725) },
      {  INT32_C(  1809875446), -INT32_C(  1940753363),  INT32_C(  1854257948), -INT32_C(  1221609245) },
      { -INT64_C( 1252720552326514980), -INT64_C( 6933530265598319314) } },
    { {  INT64_C( 4333209917881572729),  INT64_C( 5789036862707101116) },
      {  INT32_C(  2025535051), -INT32_C(   972747350), -INT32_C(  1422619960), -INT32_C(  1151114430) },
      { -INT32_C(  1207965119),  INT32_C(  1324556946), -INT32_C(   382779249),  INT32_C(  1429898506) },
      {  INT64_C( 4877759317782782769),  INT64_C( 4143060059015059536) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int64x2_t r = simde_vmlal_high_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t c = simde_test_arm_neon_random_i32x4();
    simde_int64x2_t r = simde_vmlal_high_s32(a, b, c);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_high_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t b[16];
    uint8_t c[16];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(20405), UINT16_C(34902), UINT16_C(42627), UINT16_C(24981), UINT16_C(45797), UINT16_C(26511), UINT16_C( 3016), UINT16_C( 7803) },
      { UINT8_C(  1), UINT8_C(119), UINT8_C(178), UINT8_C( 83), UINT8_C(215), UINT8_C(173), UINT8_C(184), UINT8_C(152),
        UINT8_C(178), UINT8_C( 84), UINT8_C( 83), UINT8_C(138), UINT8_C(172), UINT8_C( 49), UINT8_C(  8), UINT8_C( 98) },
      { UINT8_C(129), UINT8_C( 95), UINT8_C(234), UINT8_C(  4), UINT8_C(  5), UINT8_C(127), UINT8_C(101), UINT8_C(234),
        UINT8_C( 49), UINT8_C(245), UINT8_C( 81), UINT8_C(250), UINT8_C(  0), UINT8_C(204), UINT8_C( 24), UINT8_C(  2) },
      { UINT16_C(29127), UINT16_C(55482), UINT16_C(49350), UINT16_C(59481), UINT16_C(45797), UINT16_C(36507), UINT16_C( 3208), UINT16_C( 7999) } },
    { { UINT16_C(51779), UINT16_C( 6741), UINT16_C( 3448), UINT16_C(10930), UINT16_C( 1633), UINT16_C( 3764), UINT16_C(48183), UINT16_C(47216) },
      { UINT8_C( 27), UINT8_C( 90), UINT8_C(188), UINT8_C( 33), UINT8_C(217), UINT8_C( 34), UINT8_C( 11), UINT8_C( 10),
        UINT8_C( 23), UINT8_C( 93), UINT8_C(  4), UINT8_C( 23), UINT8_C( 41), UINT8_C( 28), UINT8_C( 25), UINT8_C(109) },
      { UINT8_C(231), UINT8_C(110), UINT8_C(135), UINT8_C( 95), UINT8_C(123), UINT8_C( 58), UINT8_C(137), UINT8_C(221),
        UINT8_C( 64), UINT8_C( 61), UINT8_C(235), UINT8_C(119), UINT8_C(249), UINT8_C( 91), UINT8_C( 48), UINT8_C( 21) },
      { UINT16_C(53251), UINT16_C(12414), UINT16_C( 4388), UINT16_C(13667), UINT16_C(11842), UINT16_C( 6312), UINT16_C(49383), UINT16_C(49505) } },
    { { UINT16_C(60597), UINT16_C(36406), UINT16_C(16654), UINT16_C( 9624), UINT16_C(40350), UINT16_C(51261), UINT16_C(22201), UINT16_C(41013) },
      { UINT8_C(197), UINT8_C(188),    UINT8_MAX, UINT8_C( 64), UINT8_C(246), UINT8_C(136), UINT8_C( 29), UINT8_C( 54),
        UINT8_C(197), UINT8_C(  8), UINT8_C(174), UINT8_C(191), UINT8_C( 99), UINT8_C(222), UINT8_C(212), UINT8_C( 24) },
      { UINT8_C(202), UINT8_C( 10), UINT8_C(166), UINT8_C(217), UINT8_C( 75), UINT8_C( 63), UINT8_C(254), UINT8_C(234),
        UINT8_C(220), UINT8_C( 59), UINT8_C(178), UINT8_C(149), UINT8_C(146), UINT8_C(231), UINT8_C( 54), UINT8_C( 87) },
      { UINT16_C(38401), UINT16_C(36878), UINT16_C(47626), UINT16_C(38083), UINT16_C(54804), UINT16_C(37007), UINT16_C(33649), UINT16_C(43101) } },
    { { UINT16_C(13731), UINT16_C(39575), UINT16_C(46526), UINT16_C(33744), UINT16_C(32445), UINT16_C( 8514), UINT16_C( 5724), UINT16_C(10041) },
      { UINT8_C( 32), UINT8_C(224), UINT8_C(  0), UINT8_C(108), UINT8_C( 31), UINT8_C(254), UINT8_C( 86), UINT8_C(251),
        UINT8_C( 58), UINT8_C(  8), UINT8_C(144), UINT8_C(204), UINT8_C(239), UINT8_C(198), UINT8_C( 35), UINT8_C(146) },
      { UINT8_C(252), UINT8_C(186), UINT8_C( 44), UINT8_C(186), UINT8_C(111), UINT8_C(253), UINT8_C( 61), UINT8_C( 45),
        UINT8_C(123), UINT8_C(128), UINT8_C( 78), UINT8_C(216), UINT8_C(150), UINT8_C(135),    UINT8_MAX, UINT8_C(183) },
      { UINT16_C(20865), UINT16_C(40599), UINT16_C(57758), UINT16_C(12272), UINT16_C( 2759), UINT16_C(35244), UINT16_C(14649), UINT16_C(36759) } },
    { { UINT16_C(65383), UINT16_C(34339), UINT16_C(31229), UINT16_C(14209), UINT16_C( 4737), UINT16_C(28675), UINT16_C( 9944), UINT16_C(54274) },
      { UINT8_C(225), UINT8_C( 47), UINT8_C(142), UINT8_C( 80), UINT8_C( 44), UINT8_C(204), UINT8_C(125), UINT8_C(167),
        UINT8_C( 76), UINT8_C(203), UINT8_C(127), UINT8_C(226), UINT8_C( 83), UINT8_C(126), UINT8_C(153), UINT8_C(186) },
      { UINT8_C(125), UINT8_C(188), UINT8_C( 65), UINT8_C(123), UINT8_C( 53), UINT8_C(194), UINT8_C(178), UINT8_C(182),
        UINT8_C(212), UINT8_C(182), UINT8_C( 38), UINT8_C(173), UINT8_C(220), UINT8_C( 41), UINT8_C(129), UINT8_C(189) },
      { UINT16_C(15959), UINT16_C( 5749), UINT16_C(36055), UINT16_C(53307), UINT16_C(22997), UINT16_C(33841), UINT16_C(29681), UINT16_C(23892) } },
    { { UINT16_C( 4184), UINT16_C(33806), UINT16_C(35804), UINT16_C(10283), UINT16_C(43863), UINT16_C(43530), UINT16_C(42025), UINT16_C(42852) },
      { UINT8_C( 96), UINT8_C(165), UINT8_C( 34), UINT8_C(150), UINT8_C(104), UINT8_C(212), UINT8_C( 76), UINT8_C( 60),
        UINT8_C(138), UINT8_C(115), UINT8_C(233), UINT8_C(103), UINT8_C(156), UINT8_C(107), UINT8_C( 36), UINT8_C(244) },
      { UINT8_C(123), UINT8_C( 50), UINT8_C(120), UINT8_C( 87), UINT8_C(190), UINT8_C(163), UINT8_C(127), UINT8_C( 21),
        UINT8_C( 78), UINT8_C(137), UINT8_C(191), UINT8_C(120), UINT8_C( 45), UINT8_C( 35), UINT8_C( 31), UINT8_C(142) },
      { UINT16_C(14948), UINT16_C(49561), UINT16_C(14771), UINT16_C(22643), UINT16_C(50883), UINT16_C(47275), UINT16_C(43141), UINT16_C(11964) } },
    { { UINT16_C(16841), UINT16_C(12580), UINT16_C(28693), UINT16_C(41069), UINT16_C(22499), UINT16_C(32519), UINT16_C(11202), UINT16_C(15731) },
      { UINT8_C( 94), UINT8_C(235), UINT8_C(148), UINT8_C( 28), UINT8_C(143), UINT8_C( 19), UINT8_C( 49), UINT8_C(221),
        UINT8_C(156), UINT8_C(240), UINT8_C( 85), UINT8_C(202), UINT8_C( 19), UINT8_C(116), UINT8_C( 88), UINT8_C(220) },
      { UINT8_C(181), UINT8_C(124), UINT8_C( 13), UINT8_C(203), UINT8_C(236), UINT8_C(123), UINT8_C(107), UINT8_C(208),
        UINT8_C(210), UINT8_C(114), UINT8_C( 79), UINT8_C(148), UINT8_C(157), UINT8_C(195), UINT8_C(209), UINT8_C(251) },
      { UINT16_C(49601), UINT16_C(39940), UINT16_C(35408), UINT16_C( 5429), UINT16_C(25482), UINT16_C(55139), UINT16_C(29594), UINT16_C( 5415) } },
    { { UINT16_C(26030), UINT16_C(15639), UINT16_C(18552), UINT16_C( 5147), UINT16_C(28728), UINT16_C(19678), UINT16_C(14053), UINT16_C(39464) },
      { UINT8_C(178), UINT8_C( 54), UINT8_C(101), UINT8_C(159), UINT8_C(177), UINT8_C(208), UINT8_C(111), UINT8_C(131),
        UINT8_C( 66), UINT8_C(190), UINT8_C( 23), UINT8_C(224), UINT8_C(129), UINT8_C(232), UINT8_C(219), UINT8_C( 48) },
      { UINT8_C( 77), UINT8_C(243), UINT8_C(109), UINT8_C(197), UINT8_C( 59), UINT8_C(136), UINT8_C(217), UINT8_C(116),
        UINT8_C(249), UINT8_C(184), UINT8_C(192), UINT8_C(222), UINT8_C(238), UINT8_C(232), UINT8_C(120), UINT8_C(161) },
      { UINT16_C(42464), UINT16_C(50599), UINT16_C(22968), UINT16_C(54875), UINT16_C(59430), UINT16_C( 7966), UINT16_C(40333), UINT16_C(47192) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t c = simde_vld1q_u8(test_vec[i].c);
    simde_uint16x8_t r = simde_vmlal_high_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t c = simde_test_arm_neon_random_u8x16();
    simde_uint16x8_t r = simde_vmlal_high_u8(a, b, c);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint16_t c[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1254400694), UINT32_C(2319989667), UINT32_C( 183778036), UINT32_C( 475007370) },
      { UINT16_C(27950), UINT16_C(64978), UINT16_C(58654), UINT16_C(41408), UINT16_C( 2454), UINT16_C(  686), UINT16_C(47772), UINT16_C(21423) },
      { UINT16_C(29532), UINT16_C(65437), UINT16_C(59055), UINT16_C(41866), UINT16_C(32288), UINT16_C(43693), UINT16_C(65159), UINT16_C(46535) },
      { UINT32_C(1333635446), UINT32_C(2349963065), UINT32_C(3296553784), UINT32_C(1471926675) } },
    { { UINT32_C(2326960491), UINT32_C( 338391934), UINT32_C( 420993404), UINT32_C(4033660564) },
      { UINT16_C( 2362), UINT16_C(59888), UINT16_C(31471), UINT16_C( 4236), UINT16_C(15096), UINT16_C(32698), UINT16_C(33080), UINT16_C(41780) },
      { UINT16_C(59163), UINT16_C(39213), UINT16_C(22618), UINT16_C(54958), UINT16_C(50482), UINT16_C(50927), UINT16_C(23435), UINT16_C(50614) },
      { UINT32_C(3089036763), UINT32_C(2003602980), UINT32_C(1196223204), UINT32_C(1853346188) } },
    { { UINT32_C(1420732005), UINT32_C( 409221920), UINT32_C(2912362357), UINT32_C(3142634656) },
      { UINT16_C(32435), UINT16_C( 3413), UINT16_C(  982), UINT16_C( 2275), UINT16_C(54216), UINT16_C(21454), UINT16_C(34094), UINT16_C(37657) },
      { UINT16_C(50987), UINT16_C(19688), UINT16_C(19458), UINT16_C(30564), UINT16_C(64619), UINT16_C( 3108), UINT16_C(30152), UINT16_C(31687) },
      { UINT32_C( 629148413), UINT32_C( 475900952), UINT32_C(3940364645), UINT32_C(  40904719) } },
    { { UINT32_C(3381140723), UINT32_C(3889326879), UINT32_C(1832624190), UINT32_C(1358976037) },
      { UINT16_C(59419), UINT16_C( 7837), UINT16_C(  309), UINT16_C(41109), UINT16_C(47869), UINT16_C(50604), UINT16_C(29743), UINT16_C( 8768) },
      { UINT16_C(51344), UINT16_C(45291), UINT16_C(48436), UINT16_C(29335), UINT16_C(53854), UINT16_C(33759), UINT16_C(57382), UINT16_C(17108) },
      { UINT32_C(1664110553), UINT32_C(1302700019), UINT32_C(3539337016), UINT32_C(1508978981) } },
    { { UINT32_C(4250956232), UINT32_C(1889465715), UINT32_C(3728100015), UINT32_C(1325430462) },
      { UINT16_C(60479), UINT16_C(29695), UINT16_C(38569), UINT16_C( 2021), UINT16_C(50537), UINT16_C(36747), UINT16_C(24485), UINT16_C(28113) },
      { UINT16_C(12753), UINT16_C(17515), UINT16_C( 2343), UINT16_C(54964), UINT16_C(59987), UINT16_C( 4789), UINT16_C(46433), UINT16_C(41057) },
      { UINT32_C(2987551955), UINT32_C(2065447098), UINT32_C( 570044724), UINT32_C(2479665903) } },
    { { UINT32_C(1259561121), UINT32_C(1599273206), UINT32_C(1659887037), UINT32_C( 248561725) },
      { UINT16_C(15346), UINT16_C( 6482), UINT16_C( 1604), UINT16_C(38895), UINT16_C(42225), UINT16_C(21161), UINT16_C( 2650), UINT16_C(64498) },
      { UINT16_C( 1386), UINT16_C(24902), UINT16_C(39421), UINT16_C(48064), UINT16_C(44918), UINT16_C(45853), UINT16_C(60784), UINT16_C(25281) },
      { UINT32_C(3156223671), UINT32_C(2569568539), UINT32_C(1820964637), UINT32_C(1879135663) } },
    { { UINT32_C(1820005160), UINT32_C( 184838682), UINT32_C(1767746831), UINT32_C( 576999352) },
      { UINT16_C(43860), UINT16_C(20867), UINT16_C(17476), UINT16_C(47628), UINT16_C(10995), UINT16_C(25454), UINT16_C(12055), UINT16_C(16581) },
      { UINT16_C(16451), UINT16_C(23980), UINT16_C(45227), UINT16_C(47720), UINT16_C(50526), UINT16_C( 5667), UINT16_C(34580), UINT16_C(26680) },
      { UINT32_C(2375538530), UINT32_C( 329086500), UINT32_C(2184608731), UINT32_C(1019380432) } },
    { { UINT32_C(1991883826), UINT32_C(4080125440), UINT32_C( 123183088), UINT32_C( 289873102) },
      { UINT16_C(62557), UINT16_C( 2158), UINT16_C(54948), UINT16_C(  706), UINT16_C(58779), UINT16_C(44824), UINT16_C(20844), UINT16_C(40727) },
      { UINT16_C(53517), UINT16_C( 3349), UINT16_C(18071), UINT16_C(34560), UINT16_C(22501), UINT16_C(46222), UINT16_C(54900), UINT16_C(53701) },
      { UINT32_C(3314470105), UINT32_C(1857013072), UINT32_C(1267518688), UINT32_C(2476953729) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t c = simde_vld1q_u16(test_vec[i].c);
    simde_uint32x4_t r = simde_vmlal_high_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t c = simde_test_arm_neon_random_u16x8();
    simde_uint32x4_t r = simde_vmlal_high_u16(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint32_t c[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 8235345744292223378), UINT64_C(12397745504786786594) },
      { UINT32_C( 681719911), UINT32_C(3980442008), UINT32_C(4280365644), UINT32_C(1653442256) },
      { UINT32_C(4072578464), UINT32_C(2472806257), UINT32_C( 173008688), UINT32_C(4055260298) },
      { UINT64_C( 8975886188520938450), UINT64_C(  656140166869587266) } },
    { { UINT64_C( 6708492149745866900), UINT64_C( 7043606458429946508) },
      { UINT32_C(4182998408), UINT32_C(3045898372), UINT32_C( 717216671), UINT32_C(3424351543) },
      { UINT32_C(3757585869), UINT32_C( 456921743), UINT32_C( 226007372), UINT32_C( 208549764) },
      { UINT64_C( 6870588404713165512), UINT64_C( 7757754164575632360) } },
    { { UINT64_C( 1868309374540563124), UINT64_C(17253113295557340268) },
      { UINT32_C( 600729748), UINT32_C(3325954682), UINT32_C( 685029028), UINT32_C(2704556781) },
      { UINT32_C(2128230660), UINT32_C( 915982282), UINT32_C(2514082676), UINT32_C(3464775994) },
      { UINT64_C( 3590528986392482052), UINT64_C( 8177052631066503966) } },
    { { UINT64_C(  139946240152523441), UINT64_C(  897725993230910950) },
      { UINT32_C(1619742614), UINT32_C(2341872407), UINT32_C( 958427134), UINT32_C(1762108856) },
      { UINT32_C(1419049463), UINT32_C( 257263145), UINT32_C(1407417931), UINT32_C(1902139867) },
      { UINT64_C( 1488853774101063195), UINT64_C( 4249503498222273102) } },
    { { UINT64_C(  885633589777132456), UINT64_C(  574575160984955863) },
      { UINT32_C(1868336454), UINT32_C(1602138387), UINT32_C( 196239920), UINT32_C(1669141179) },
      { UINT32_C( 186863357), UINT32_C(2367188406), UINT32_C(3894173144), UINT32_C(4042266026) },
      { UINT64_C( 1649825816021840936), UINT64_C( 7321687841454240517) } },
    { { UINT64_C( 3248747887485471907), UINT64_C(15591100011637229632) },
      { UINT32_C(3135471876), UINT32_C(3343383535), UINT32_C(  61891673), UINT32_C( 485793913) },
      { UINT32_C(3922940908), UINT32_C(1897392177), UINT32_C(2339131568), UINT32_C( 174312198) },
      { UINT64_C( 3393520653596105171), UINT64_C(15675779816387280406) } },
    { { UINT64_C(11169784979419121228), UINT64_C( 4541478163365933936) },
      { UINT32_C( 388553190), UINT32_C(1921597378), UINT32_C(2516448655), UINT32_C( 228614336) },
      { UINT32_C(3913835943), UINT32_C(3800320881), UINT32_C(1372332798), UINT32_C(2609959605) },
      { UINT64_C(14623190003158607918), UINT64_C( 5138152345449831216) } },
    { { UINT64_C( 9862949122136521132), UINT64_C(16572891756800892465) },
      { UINT32_C(2496546594), UINT32_C(2440450706), UINT32_C( 719471221), UINT32_C(3234165524) },
      { UINT32_C( 607024940), UINT32_C(3836481459), UINT32_C( 735431405), UINT32_C(2853295239) },
      { UINT64_C(10392070853053616637), UINT64_C( 7354176774858481085) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint64x2_t r = simde_vmlal_high_u32(a, b, c);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint64x2_t r = simde_vmlal_high_u32(a, b, c);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_high_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
