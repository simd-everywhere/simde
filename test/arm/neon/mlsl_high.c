#define SIMDE_TEST_ARM_NEON_INSN mlsl_high

#include "test-neon.h"
#include "../../../simde/arm/neon/mlsl_high.h"

static int
test_simde_vmlsl_high_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t b[16];
    int8_t c[16];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 31077),  INT16_C(  5466),  INT16_C( 17188),  INT16_C( 11098),  INT16_C( 28477), -INT16_C(  8315),  INT16_C(  4954), -INT16_C( 28534) },
      {      INT8_MIN, -INT8_C(  20),  INT8_C(  61),  INT8_C(  84), -INT8_C(  54), -INT8_C(  49),  INT8_C( 102), -INT8_C(  70),
         INT8_C(  61), -INT8_C(  15),  INT8_C(  16),  INT8_C(  22), -INT8_C(   8), -INT8_C(  34),  INT8_C(  21), -INT8_C( 109) },
      {  INT8_C( 101),  INT8_C( 111), -INT8_C(  88), -INT8_C( 119), -INT8_C(  78),  INT8_C(   3), -INT8_C(  76), -INT8_C(  17),
         INT8_C( 114),  INT8_C(  57), -INT8_C(  50), -INT8_C(  52),  INT8_C(  77),  INT8_C(  88),  INT8_C(  92), -INT8_C(  51) },
      {  INT16_C( 27505),  INT16_C(  6321),  INT16_C( 17988),  INT16_C( 12242),  INT16_C( 29093), -INT16_C(  5323),  INT16_C(  3022),  INT16_C( 31443) } },
    { { -INT16_C( 26300),  INT16_C(  3618), -INT16_C( 30615), -INT16_C( 22840), -INT16_C( 10119),  INT16_C( 29372), -INT16_C( 11849),  INT16_C(  7173) },
      {  INT8_C(  64), -INT8_C(  82), -INT8_C(  91), -INT8_C(  13), -INT8_C(  79),  INT8_C(  89), -INT8_C(  30),  INT8_C(  35),
        -INT8_C( 110), -INT8_C(  79), -INT8_C(  17), -INT8_C(  33),  INT8_C(   9),  INT8_C(  75), -INT8_C(  83),  INT8_C(  78) },
      { -INT8_C(  27), -INT8_C(  49),  INT8_C(  92),  INT8_C(  78),  INT8_C(  87),  INT8_C(  37), -INT8_C(  12), -INT8_C(  47),
        -INT8_C(   3), -INT8_C(  80),  INT8_C(  67), -INT8_C(  76), -INT8_C( 126),  INT8_C(  72), -INT8_C(  48), -INT8_C(  62) },
      { -INT16_C( 26630), -INT16_C(  2702), -INT16_C( 29476), -INT16_C( 25348), -INT16_C(  8985),  INT16_C( 23972), -INT16_C( 15833),  INT16_C( 12009) } },
    { {  INT16_C( 30198), -INT16_C( 22603), -INT16_C( 26418),  INT16_C( 25034), -INT16_C( 18103),  INT16_C( 21056), -INT16_C(  4859), -INT16_C(  5472) },
      { -INT8_C(  68), -INT8_C(   3),  INT8_C(  56),  INT8_C(  20),  INT8_C(  34),  INT8_C(  44), -INT8_C(  27),  INT8_C(  31),
        -INT8_C(  36),  INT8_C(  40), -INT8_C(  44),  INT8_C(  94),  INT8_C( 112), -INT8_C(  92),  INT8_C(  33),  INT8_C( 103) },
      {  INT8_C(  26), -INT8_C(  42),  INT8_C(  14), -INT8_C(  24),  INT8_C( 110), -INT8_C(  39),  INT8_C(  73), -INT8_C(  73),
        -INT8_C( 110), -INT8_C( 118),  INT8_C(  10), -INT8_C( 105),  INT8_C( 119), -INT8_C(  86), -INT8_C( 127),  INT8_C(  52) },
      {  INT16_C( 26238), -INT16_C( 17883), -INT16_C( 25978), -INT16_C( 30632), -INT16_C( 31431),  INT16_C( 13144), -INT16_C(   668), -INT16_C( 10828) } },
    { { -INT16_C( 18009), -INT16_C( 14008),  INT16_C( 11749), -INT16_C( 15639), -INT16_C( 17067), -INT16_C( 15072),  INT16_C( 16737),  INT16_C( 31532) },
      {  INT8_C(  24),  INT8_C(  59),  INT8_C( 100), -INT8_C( 122),  INT8_C(  20), -INT8_C(  83),  INT8_C(  62), -INT8_C(  90),
         INT8_C(  55),  INT8_C(  72),  INT8_C(  62), -INT8_C(  81), -INT8_C(  14), -INT8_C(  65), -INT8_C(  29), -INT8_C( 102) },
      {  INT8_C( 121),  INT8_C(  43),  INT8_C(  99),  INT8_C(  94),  INT8_C(  88),  INT8_C(  76),  INT8_C(  32), -INT8_C(  83),
         INT8_C(   9),  INT8_C(  65),  INT8_C( 114),  INT8_C( 107), -INT8_C( 126), -INT8_C(  97), -INT8_C(  26), -INT8_C( 102) },
      { -INT16_C( 18504), -INT16_C( 18688),  INT16_C(  4681), -INT16_C(  6972), -INT16_C( 18831), -INT16_C( 21377),  INT16_C( 15983),  INT16_C( 21128) } },
    { {  INT16_C( 19162), -INT16_C(  4575),  INT16_C( 24568),  INT16_C( 12180), -INT16_C( 11609), -INT16_C( 26146), -INT16_C( 15982),  INT16_C(  2867) },
      { -INT8_C(  20), -INT8_C( 105),  INT8_C( 105),  INT8_C(  68), -INT8_C(  29), -INT8_C( 118), -INT8_C(  15), -INT8_C(  19),
        -INT8_C(  53),  INT8_C( 100),  INT8_C(  88),  INT8_C(  77),  INT8_C(   3),  INT8_C(  62), -INT8_C(  24), -INT8_C(  35) },
      { -INT8_C( 119),  INT8_C(   9), -INT8_C(  53), -INT8_C( 127),  INT8_C( 104),  INT8_C(  95), -INT8_C(  80),  INT8_C(  15),
         INT8_C(  50), -INT8_C( 113), -INT8_C(  88), -INT8_C(  60),  INT8_C(  80), -INT8_C(  36), -INT8_C(  49),  INT8_C(  61) },
      {  INT16_C( 21812),  INT16_C(  6725),  INT16_C( 32312),  INT16_C( 16800), -INT16_C( 11849), -INT16_C( 23914), -INT16_C( 17158),  INT16_C(  5002) } },
    { {  INT16_C( 14451),  INT16_C( 22145),  INT16_C( 29634), -INT16_C( 29373), -INT16_C( 25641), -INT16_C(  9509), -INT16_C( 15398),  INT16_C( 25527) },
      { -INT8_C(  52), -INT8_C( 126), -INT8_C(  28),  INT8_C(  52), -INT8_C(  31), -INT8_C( 108),  INT8_C(  67),  INT8_C(  19),
         INT8_C(  35), -INT8_C(  21), -INT8_C(  41),  INT8_C( 116), -INT8_C(  57), -INT8_C(  90), -INT8_C(  79),  INT8_C(  58) },
      { -INT8_C(  33),  INT8_C(  50), -INT8_C( 111), -INT8_C(  95), -INT8_C(  91), -INT8_C(  44),  INT8_C(  47),  INT8_C( 124),
         INT8_C( 112),  INT8_C(  10),  INT8_C(  86),  INT8_C(  74), -INT8_C(  51),  INT8_C(  13), -INT8_C(  83), -INT8_C( 103) },
      {  INT16_C( 10531),  INT16_C( 22355), -INT16_C( 32376),  INT16_C( 27579), -INT16_C( 28548), -INT16_C(  8339), -INT16_C( 21955),  INT16_C( 31501) } },
    { { -INT16_C( 28273),  INT16_C( 29133),  INT16_C(  4133),  INT16_C( 18820),  INT16_C( 23803), -INT16_C( 15427),  INT16_C( 28162), -INT16_C(  7683) },
      { -INT8_C(  96), -INT8_C( 114), -INT8_C( 125),  INT8_C(  70),  INT8_C(  99), -INT8_C(  78), -INT8_C(  62), -INT8_C(  45),
        -INT8_C(  68),  INT8_C(  25),  INT8_C(  29), -INT8_C( 119),  INT8_C(  38), -INT8_C(  54),  INT8_C(  34), -INT8_C(  74) },
      {  INT8_C(  91), -INT8_C(  17),  INT8_C(  39),      INT8_MIN, -INT8_C(   1), -INT8_C(  85), -INT8_C(  55), -INT8_C(   6),
         INT8_C(   7), -INT8_C( 122), -INT8_C(  67),  INT8_C(  10), -INT8_C(  12), -INT8_C(  69), -INT8_C(  21), -INT8_C( 107) },
      { -INT16_C( 27797),  INT16_C( 32183),  INT16_C(  6076),  INT16_C( 20010),  INT16_C( 24259), -INT16_C( 19153),  INT16_C( 28876), -INT16_C( 15601) } },
    { {  INT16_C( 28233), -INT16_C( 21285), -INT16_C( 25312), -INT16_C(  9089), -INT16_C( 25418), -INT16_C(  8859), -INT16_C( 30874), -INT16_C( 15981) },
      {  INT8_C( 118), -INT8_C(  70),  INT8_C(  66),  INT8_C( 117),  INT8_C( 101),  INT8_C(  11),  INT8_C( 112),  INT8_C( 109),
        -INT8_C( 110),  INT8_C(  45),  INT8_C( 119), -INT8_C( 122), -INT8_C(  24),  INT8_C(  98),  INT8_C(  27),  INT8_C(  50) },
      { -INT8_C(  47), -INT8_C(  10), -INT8_C(  34), -INT8_C(  15), -INT8_C( 108),  INT8_C(  94), -INT8_C(  50),  INT8_C(  74),
        -INT8_C(   6),  INT8_C(  51),  INT8_C(  39),  INT8_C(  97), -INT8_C(  69), -INT8_C(  70),  INT8_C(  34),  INT8_C(  49) },
      {  INT16_C( 27573), -INT16_C( 23580), -INT16_C( 29953),  INT16_C(  2745), -INT16_C( 27074), -INT16_C(  1999), -INT16_C( 31792), -INT16_C( 18431) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t c = simde_vld1q_s8(test_vec[i].c);
    simde_int16x8_t r = simde_vmlsl_high_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t c = simde_test_arm_neon_random_i8x16();
    simde_int16x8_t r = simde_vmlsl_high_s8(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t c[8];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   196837651), -INT32_C(   735099441),  INT32_C(    85273546), -INT32_C(  1503660226) },
      { -INT16_C( 21911), -INT16_C(   532),  INT16_C( 11222), -INT16_C( 28049), -INT16_C( 29213),  INT16_C( 18983),  INT16_C(  6520),  INT16_C( 26206) },
      { -INT16_C( 23913),  INT16_C( 26202), -INT16_C( 30233), -INT16_C( 20165),  INT16_C( 20660), -INT16_C(  3146),  INT16_C(  5447), -INT16_C( 20071) },
      {  INT32_C(   406702929), -INT32_C(   675378923),  INT32_C(    49759106), -INT32_C(   977679600) } },
    { { -INT32_C(  1766947392), -INT32_C(  1809244751),  INT32_C(   601772203),  INT32_C(     8993897) },
      { -INT16_C(  6946), -INT16_C( 15002), -INT16_C( 24211),  INT16_C(  8823),  INT16_C( 11762),  INT16_C( 14613), -INT16_C( 20925),  INT16_C(  1002) },
      { -INT16_C( 26573), -INT16_C(  7015), -INT16_C( 15690),  INT16_C( 24952),  INT16_C( 22034),  INT16_C( 31620),  INT16_C(  3730),  INT16_C( 28795) },
      { -INT32_C(  2026111300),  INT32_C(  2023659485),  INT32_C(   679822453), -INT32_C(    19858693) } },
    { {  INT32_C(  1597432562),  INT32_C(  1971432835),  INT32_C(   498046682),  INT32_C(  2015402308) },
      { -INT16_C( 17870), -INT16_C(  6052), -INT16_C( 10884), -INT16_C( 28855), -INT16_C( 13013), -INT16_C( 16886), -INT16_C( 31013), -INT16_C( 13010) },
      {  INT16_C( 25704), -INT16_C(  5331), -INT16_C( 20975), -INT16_C(  5023),  INT16_C(  4165), -INT16_C( 30455),  INT16_C( 10921), -INT16_C(  9471) },
      {  INT32_C(  1651631707),  INT32_C(  1457169705),  INT32_C(   836739655),  INT32_C(  1892184598) } },
    { {  INT32_C(  1623416548),  INT32_C(  1592724531), -INT32_C(  1256391974), -INT32_C(   394048640) },
      { -INT16_C( 20305), -INT16_C( 15917),  INT16_C( 13406), -INT16_C( 23635), -INT16_C( 18876), -INT16_C(  4563),  INT16_C( 12000), -INT16_C( 15159) },
      { -INT16_C( 29300), -INT16_C( 16603),  INT16_C(  5273),  INT16_C( 29470),  INT16_C( 14862), -INT16_C( 29143), -INT16_C( 21371),  INT16_C( 13686) },
      {  INT32_C(  1903951660),  INT32_C(  1459745022), -INT32_C(   999939974), -INT32_C(   186582566) } },
    { { -INT32_C(  1158264228), -INT32_C(  1017207938),  INT32_C(   984714073),  INT32_C(  1191082681) },
      {  INT16_C(  8967), -INT16_C( 24315),  INT16_C(  9016),  INT16_C( 17940),  INT16_C( 15710), -INT16_C(  7211),  INT16_C( 19433),  INT16_C( 17688) },
      {  INT16_C(  3733),  INT16_C(  5120),  INT16_C( 24241),  INT16_C(  3031), -INT16_C( 30487), -INT16_C( 23995),  INT16_C( 17154),  INT16_C(  2792) },
      { -INT32_C(   679313458), -INT32_C(  1190235883),  INT32_C(   651360391),  INT32_C(  1141697785) } },
    { { -INT32_C(  1616122265),  INT32_C(  1877327633), -INT32_C(   430720259), -INT32_C(  1691587834) },
      {  INT16_C( 11386),  INT16_C( 11183), -INT16_C( 31094),  INT16_C( 29494),  INT16_C( 31502),  INT16_C(  4373), -INT16_C(   321),  INT16_C(  9755) },
      { -INT16_C( 14612), -INT16_C(   571), -INT16_C( 21883), -INT16_C( 32147), -INT16_C( 16283),  INT16_C( 27497), -INT16_C( 27349), -INT16_C( 23290) },
      { -INT32_C(  1103175199),  INT32_C(  1757083252), -INT32_C(   439499288), -INT32_C(  1464393884) } },
    { {  INT32_C(  1272035009),  INT32_C(  1270744892),  INT32_C(  1113379715), -INT32_C(  1117227055) },
      {  INT16_C( 11581), -INT16_C( 15685),  INT16_C( 10455),  INT16_C( 15429), -INT16_C( 20760),  INT16_C(  5031), -INT16_C( 20925),  INT16_C(  1209) },
      { -INT16_C( 30108), -INT16_C( 24497),  INT16_C(  3473),  INT16_C(  5355),  INT16_C( 18400), -INT16_C( 19882), -INT16_C( 16706), -INT16_C(  1169) },
      {  INT32_C(  1654019009),  INT32_C(  1370771234),  INT32_C(   763806665), -INT32_C(  1115813734) } },
    { { -INT32_C(  1010947349),  INT32_C(   989791058), -INT32_C(   196171855), -INT32_C(  1174927531) },
      {  INT16_C( 18321),  INT16_C(  8793),  INT16_C( 17748),  INT16_C( 13367), -INT16_C( 29300),  INT16_C( 19430),  INT16_C( 22092),  INT16_C( 14150) },
      {  INT16_C(  1152), -INT16_C( 11270), -INT16_C(  1529), -INT16_C( 18419),  INT16_C( 23457), -INT16_C(  2388), -INT16_C( 23454), -INT16_C(  3153) },
      { -INT32_C(   323657249),  INT32_C(  1036189898),  INT32_C(   321973913), -INT32_C(  1130312581) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int32x4_t r = simde_vmlsl_high_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t c = simde_test_arm_neon_random_i16x8();
    simde_int32x4_t r = simde_vmlsl_high_s16(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t c[4];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 2705452481976596245),  INT64_C( 3557399159967668954) },
      {  INT32_C(  1996773488), -INT32_C(   214953646), -INT32_C(   806757267),  INT32_C(  1824757889) },
      { -INT32_C(   290661983),  INT32_C(    13115430),  INT32_C(   724036986), -INT32_C(   916683431) },
      { -INT64_C( 2121330381944318983),  INT64_C( 5230124482400506113) } },
    { { -INT64_C( 2439982941661536035),  INT64_C( 5060482088255229261) },
      {  INT32_C(  1882580554), -INT32_C(  2123301626),  INT32_C(  1152161771), -INT32_C(    99809252) },
      { -INT32_C(   651539096),  INT32_C(   196627902),  INT32_C(    14247514),  INT32_C(   558240727) },
      { -INT64_C( 2456398382624123329),  INT64_C( 5116199677653035465) } },
    { {  INT64_C( 7242071295000673274), -INT64_C( 7084244446544908903) },
      { -INT32_C(  1065887486), -INT32_C(  2117390553),  INT32_C(  1820435605), -INT32_C(  1299330888) },
      { -INT32_C(  1129177533), -INT32_C(  1205849057), -INT32_C(  1754347423), -INT32_C(  2144068227) },
      { -INT64_C( 8010996266339682427),  INT64_C( 8576645553844147137) } },
    { {  INT64_C( 8043161590456953847),  INT64_C( 3177967838759166384) },
      { -INT32_C(  1494626938),  INT32_C(  1650329857),  INT32_C(  1341770962), -INT32_C(   506515734) },
      { -INT32_C(  1258352423), -INT32_C(   870080996), -INT32_C(  1472856129), -INT32_C(   288010393) },
      { -INT64_C( 8427346898156671671),  INT64_C( 3032086043149142922) } },
    { { -INT64_C( 7385636451878912484), -INT64_C( 9112267865781077569) },
      { -INT32_C(   466253368), -INT32_C(   407807961), -INT32_C(  1081088425),  INT32_C(  1387095093) },
      { -INT32_C(   361807582), -INT32_C(   226234573),  INT32_C(   278621289), -INT32_C(   309254875) },
      { -INT64_C( 7084422201382432659), -INT64_C( 8683301946182249194) } },
    { {  INT64_C( 8556139039845172910), -INT64_C( 3174788484804817815) },
      {  INT32_C(  1472028707), -INT32_C(  1203158705), -INT32_C(   758520403), -INT32_C(  1178576374) },
      {  INT32_C(  1083150881),  INT32_C(  2125876245),  INT32_C(  1226632344), -INT32_C(   232976946) },
      { -INT64_C( 8960179373960664074), -INT64_C( 3449369609047091619) } },
    { { -INT64_C( 3930074451990160787), -INT64_C( 5099381442482585993) },
      {  INT32_C(    49924845), -INT32_C(  1367298026),  INT32_C(  1794678172),  INT32_C(   391910826) },
      {  INT32_C(   198419951), -INT32_C(  1345042376),  INT32_C(   523333510), -INT32_C(  1193775925) },
      { -INT64_C( 4869289679063304507), -INT64_C( 4631527733656921943) } },
    { {  INT64_C( 2232443471111377462), -INT64_C(  605200850192108584) },
      { -INT32_C(  1040028278),  INT32_C(  1014159029),  INT32_C(   291218246),  INT32_C(  1187590928) },
      { -INT32_C(  2020375547), -INT32_C(  1733980480), -INT32_C(  1994707327), -INT32_C(  1652509677) },
      {  INT64_C( 2813338640163665904),  INT64_C( 1357304650645301672) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int64x2_t r = simde_vmlsl_high_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t c = simde_test_arm_neon_random_i32x4();
    simde_int64x2_t r = simde_vmlsl_high_s32(a, b, c);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_high_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t b[16];
    uint8_t c[16];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(33569), UINT16_C(55136), UINT16_C(53849), UINT16_C(40723), UINT16_C(28277), UINT16_C(34224), UINT16_C(31393), UINT16_C(42956) },
      { UINT8_C(254), UINT8_C( 95), UINT8_C( 46), UINT8_C(190), UINT8_C(237), UINT8_C(212), UINT8_C( 87), UINT8_C(110),
        UINT8_C(  2), UINT8_C(114), UINT8_C(247), UINT8_C( 21), UINT8_C( 38), UINT8_C(119), UINT8_C(178), UINT8_C( 72) },
      { UINT8_C(250), UINT8_C( 18), UINT8_C( 31), UINT8_C( 84), UINT8_C(228), UINT8_C( 50), UINT8_C(243), UINT8_C( 90),
        UINT8_C(160), UINT8_C(164), UINT8_C(223), UINT8_C( 65), UINT8_C( 30), UINT8_C(171), UINT8_C(232), UINT8_C( 28) },
      { UINT16_C(33249), UINT16_C(36440), UINT16_C(64304), UINT16_C(39358), UINT16_C(27137), UINT16_C(13875), UINT16_C(55633), UINT16_C(40940) } },
    { { UINT16_C( 5898), UINT16_C(63451), UINT16_C(13035), UINT16_C(60773), UINT16_C(23716), UINT16_C(51714), UINT16_C(46292), UINT16_C(52754) },
      { UINT8_C(199), UINT8_C( 49), UINT8_C( 34), UINT8_C(171), UINT8_C( 99), UINT8_C( 22), UINT8_C(  5), UINT8_C(  3),
        UINT8_C(186), UINT8_C(229), UINT8_C( 69), UINT8_C(216), UINT8_C(144), UINT8_C( 45), UINT8_C(244), UINT8_C(155) },
      { UINT8_C( 68), UINT8_C(207), UINT8_C(146), UINT8_C( 47), UINT8_C(  1), UINT8_C(248), UINT8_C( 28), UINT8_C(165),
        UINT8_C( 84), UINT8_C( 30), UINT8_C(112), UINT8_C( 40), UINT8_C(211), UINT8_C(130), UINT8_C(247), UINT8_C(154) },
      { UINT16_C(55810), UINT16_C(56581), UINT16_C( 5307), UINT16_C(52133), UINT16_C(58868), UINT16_C(45864), UINT16_C(51560), UINT16_C(28884) } },
    { { UINT16_C( 6580), UINT16_C( 5957), UINT16_C(19247), UINT16_C(59675), UINT16_C(24624), UINT16_C(49345), UINT16_C(46733), UINT16_C(53851) },
      { UINT8_C(133), UINT8_C(238), UINT8_C(  1), UINT8_C(135), UINT8_C(230), UINT8_C( 30), UINT8_C( 44), UINT8_C( 58),
        UINT8_C( 60), UINT8_C(156), UINT8_C( 99), UINT8_C( 15), UINT8_C( 31), UINT8_C( 90), UINT8_C(169), UINT8_C(211) },
      { UINT8_C(115), UINT8_C(239), UINT8_C(234), UINT8_C(163), UINT8_C( 58), UINT8_C(  5), UINT8_C(140), UINT8_C(106),
        UINT8_C(101), UINT8_C( 78), UINT8_C( 42), UINT8_C(243), UINT8_C(  4), UINT8_C(134), UINT8_C(197), UINT8_C(137) },
      { UINT16_C(  520), UINT16_C(59325), UINT16_C(15089), UINT16_C(56030), UINT16_C(24500), UINT16_C(37285), UINT16_C(13440), UINT16_C(24944) } },
    { { UINT16_C(50804), UINT16_C(23056), UINT16_C(15844), UINT16_C( 8596), UINT16_C(63449), UINT16_C(63536), UINT16_C(55889), UINT16_C(50635) },
      { UINT8_C(201), UINT8_C(182), UINT8_C(104), UINT8_C(  3), UINT8_C(187), UINT8_C(244), UINT8_C(109), UINT8_C( 33),
        UINT8_C( 66), UINT8_C(151), UINT8_C( 20), UINT8_C( 70), UINT8_C( 29), UINT8_C(217), UINT8_C(208), UINT8_C(145) },
      { UINT8_C(159), UINT8_C(224), UINT8_C(235), UINT8_C(132), UINT8_C( 29), UINT8_C(128), UINT8_C(165), UINT8_C(247),
        UINT8_C(119), UINT8_C(213), UINT8_C(239), UINT8_C(201), UINT8_C(175), UINT8_C(187), UINT8_C(142), UINT8_C(120) },
      { UINT16_C(42950), UINT16_C(56429), UINT16_C(11064), UINT16_C(60062), UINT16_C(58374), UINT16_C(22957), UINT16_C(26353), UINT16_C(33235) } },
    { { UINT16_C(63089), UINT16_C(11387), UINT16_C(59626), UINT16_C(11597), UINT16_C(24960), UINT16_C(40307), UINT16_C(17210), UINT16_C(55855) },
      { UINT8_C( 36), UINT8_C( 26), UINT8_C( 94), UINT8_C( 65), UINT8_C(154), UINT8_C(  3), UINT8_C( 56), UINT8_C( 18),
        UINT8_C(216), UINT8_C( 40), UINT8_C(219), UINT8_C(136), UINT8_C(227), UINT8_C(105), UINT8_C(  0), UINT8_C( 84) },
      { UINT8_C( 95), UINT8_C(124), UINT8_C(128), UINT8_C( 73), UINT8_C(100), UINT8_C(206), UINT8_C(118), UINT8_C(228),
        UINT8_C( 47), UINT8_C(234), UINT8_C(130), UINT8_C(106), UINT8_C( 45), UINT8_C(177), UINT8_C( 68), UINT8_C( 81) },
      { UINT16_C(52937), UINT16_C( 2027), UINT16_C(31156), UINT16_C(62717), UINT16_C(14745), UINT16_C(21722), UINT16_C(17210), UINT16_C(49051) } },
    { { UINT16_C(41675), UINT16_C(26259), UINT16_C(52133), UINT16_C(32120), UINT16_C(21491), UINT16_C(54789), UINT16_C( 1724), UINT16_C( 6954) },
      { UINT8_C(130), UINT8_C(171), UINT8_C(100), UINT8_C(230), UINT8_C(121), UINT8_C(219), UINT8_C(203), UINT8_C(168),
        UINT8_C(197), UINT8_C( 77), UINT8_C( 18), UINT8_C(242), UINT8_C(254), UINT8_C( 86), UINT8_C( 68), UINT8_C(201) },
      { UINT8_C(248), UINT8_C(215), UINT8_C( 47), UINT8_C(157), UINT8_C(162), UINT8_C(167), UINT8_C( 27), UINT8_C(150),
        UINT8_C(250), UINT8_C( 32), UINT8_C(108), UINT8_C(182), UINT8_C( 38), UINT8_C(151), UINT8_C(209), UINT8_C(168) },
      { UINT16_C(57961), UINT16_C(23795), UINT16_C(50189), UINT16_C(53612), UINT16_C(11839), UINT16_C(41803), UINT16_C(53048), UINT16_C(38722) } },
    { { UINT16_C(13890), UINT16_C(48015), UINT16_C(23057), UINT16_C(54883), UINT16_C(30375), UINT16_C(42440), UINT16_C( 3276), UINT16_C(50542) },
      { UINT8_C(227), UINT8_C(158), UINT8_C( 98), UINT8_C(134), UINT8_C( 69), UINT8_C(125), UINT8_C( 28), UINT8_C( 64),
        UINT8_C(158), UINT8_C(136), UINT8_C(246), UINT8_C(196), UINT8_C( 31), UINT8_C(200), UINT8_C(109), UINT8_C( 97) },
      { UINT8_C(254), UINT8_C(252), UINT8_C( 28), UINT8_C( 15), UINT8_C( 86), UINT8_C(128), UINT8_C(229), UINT8_C(253),
        UINT8_C(246), UINT8_C(173), UINT8_C(162), UINT8_C(194), UINT8_C(186), UINT8_C( 16), UINT8_C(135), UINT8_C(157) },
      { UINT16_C(40558), UINT16_C(24487), UINT16_C(48741), UINT16_C(16859), UINT16_C(24609), UINT16_C(39240), UINT16_C(54097), UINT16_C(35313) } },
    { { UINT16_C(60078), UINT16_C(62499), UINT16_C(16231), UINT16_C( 1332), UINT16_C(10952), UINT16_C(59338), UINT16_C(14322), UINT16_C(61513) },
      { UINT8_C( 51), UINT8_C(101),    UINT8_MAX, UINT8_C(137), UINT8_C(229), UINT8_C(228), UINT8_C(134), UINT8_C(219),
        UINT8_C(146), UINT8_C( 40), UINT8_C(158), UINT8_C( 76), UINT8_C( 56), UINT8_C( 37), UINT8_C(233), UINT8_C(231) },
      { UINT8_C( 15), UINT8_C( 13), UINT8_C(219), UINT8_C(119), UINT8_C( 76), UINT8_C( 15), UINT8_C(124), UINT8_C( 20),
        UINT8_C( 57), UINT8_C( 70), UINT8_C(252), UINT8_C( 44), UINT8_C(125), UINT8_C( 69), UINT8_C( 28), UINT8_C(176) },
      { UINT16_C(51756), UINT16_C(59699), UINT16_C(41951), UINT16_C(63524), UINT16_C( 3952), UINT16_C(56785), UINT16_C( 7798), UINT16_C(20857) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t c = simde_vld1q_u8(test_vec[i].c);
    simde_uint16x8_t r = simde_vmlsl_high_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t c = simde_test_arm_neon_random_u8x16();
    simde_uint16x8_t r = simde_vmlsl_high_u8(a, b, c);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint16_t c[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2419661994), UINT32_C(2456534784), UINT32_C( 551422439), UINT32_C(1040697391) },
      { UINT16_C(58069), UINT16_C( 8629), UINT16_C(13041), UINT16_C(10806), UINT16_C(12920), UINT16_C(63062), UINT16_C(29559), UINT16_C( 8614) },
      { UINT16_C(57487), UINT16_C(36785), UINT16_C( 7583), UINT16_C(34594), UINT16_C(   38), UINT16_C(21927), UINT16_C(44744), UINT16_C(40340) },
      { UINT32_C(2419171034), UINT32_C(1073774310), UINT32_C(3523801839), UINT32_C( 693208631) } },
    { { UINT32_C(2176797072), UINT32_C(4104910203), UINT32_C(2666136103), UINT32_C(  79663221) },
      { UINT16_C(29040), UINT16_C( 4243), UINT16_C(46478), UINT16_C(46231), UINT16_C(16054), UINT16_C(32266), UINT16_C(40684), UINT16_C(31772) },
      { UINT16_C(56295), UINT16_C(25597), UINT16_C(43216), UINT16_C(63319), UINT16_C(16810), UINT16_C( 8085), UINT16_C(21713), UINT16_C(16931) },
      { UINT32_C(1906929332), UINT32_C(3844039593), UINT32_C(1782764411), UINT32_C(3836698785) } },
    { { UINT32_C(1397929925), UINT32_C( 571009388), UINT32_C( 329323047), UINT32_C(2542779824) },
      { UINT16_C(35992), UINT16_C(26874), UINT16_C(20788), UINT16_C(57183), UINT16_C(62610), UINT16_C(25854), UINT16_C( 8776), UINT16_C( 3750) },
      { UINT16_C(63705), UINT16_C(17761), UINT16_C(27105), UINT16_C( 2152), UINT16_C( 2427), UINT16_C(11035), UINT16_C(43718), UINT16_C(24259) },
      { UINT32_C(1245975455), UINT32_C( 285710498), UINT32_C(4240621175), UINT32_C(2451808574) } },
    { { UINT32_C(1791409462), UINT32_C(2705925391), UINT32_C(1627736089), UINT32_C(1131391850) },
      { UINT16_C(53667), UINT16_C(33928), UINT16_C(61498), UINT16_C(46732), UINT16_C(43001), UINT16_C(49121), UINT16_C(42065), UINT16_C(34589) },
      { UINT16_C(58210), UINT16_C(29170), UINT16_C(15112), UINT16_C( 8466), UINT16_C( 6275), UINT16_C(60803), UINT16_C(62147), UINT16_C(26416) },
      { UINT32_C(1521578187), UINT32_C(4014188524), UINT32_C(3308489830), UINT32_C( 217688826) } },
    { { UINT32_C(4276861379), UINT32_C(2746513577), UINT32_C(1902286111), UINT32_C(2633531450) },
      { UINT16_C(60003), UINT16_C(27661), UINT16_C( 7974), UINT16_C(43405), UINT16_C( 4151), UINT16_C(64407), UINT16_C(50947), UINT16_C(50786) },
      { UINT16_C(19840), UINT16_C(10948), UINT16_C(30917), UINT16_C(58829), UINT16_C(12046), UINT16_C(18518), UINT16_C(20143), UINT16_C( 5092) },
      { UINT32_C(4226858433), UINT32_C(1553824751), UINT32_C( 876060690), UINT32_C(2374929138) } },
    { { UINT32_C(1602220345), UINT32_C(1208486928), UINT32_C( 541302557), UINT32_C(3890652519) },
      { UINT16_C(44018), UINT16_C(47121), UINT16_C(56867), UINT16_C(12701), UINT16_C(62222), UINT16_C(48505), UINT16_C(23873), UINT16_C(31440) },
      { UINT16_C(20302), UINT16_C(24537), UINT16_C(57948), UINT16_C(31143), UINT16_C(60033), UINT16_C(59545), UINT16_C(32655), UINT16_C(33232) },
      { UINT32_C(2161814315), UINT32_C(2615223999), UINT32_C(4056697038), UINT32_C(2845838439) } },
    { { UINT32_C(1312416042), UINT32_C(3464484544), UINT32_C( 193722825), UINT32_C(2776980566) },
      { UINT16_C(24491), UINT16_C( 1796), UINT16_C(43841), UINT16_C(49792), UINT16_C( 6549), UINT16_C( 9387), UINT16_C(31641), UINT16_C(50085) },
      { UINT16_C(57180), UINT16_C( 7185), UINT16_C(37301), UINT16_C(32746), UINT16_C(30346), UINT16_C(57482), UINT16_C( 4050), UINT16_C(32133) },
      { UINT32_C(1113680088), UINT32_C(2924901010), UINT32_C(  65576775), UINT32_C(1167599261) } },
    { { UINT32_C(2944764270), UINT32_C(3379692852), UINT32_C(3102547231), UINT32_C(4101739416) },
      { UINT16_C(36210), UINT16_C(10001), UINT16_C(64286), UINT16_C(43174), UINT16_C(12401), UINT16_C(17288), UINT16_C( 3648), UINT16_C(44737) },
      { UINT16_C(18071), UINT16_C(52318), UINT16_C(53323), UINT16_C(27285), UINT16_C(33773), UINT16_C(34082), UINT16_C(40470), UINT16_C(34937) },
      { UINT32_C(2525945297), UINT32_C(2790483236), UINT32_C(2954912671), UINT32_C(2538762847) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t c = simde_vld1q_u16(test_vec[i].c);
    simde_uint32x4_t r = simde_vmlsl_high_u16(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t c = simde_test_arm_neon_random_u16x8();
    simde_uint32x4_t r = simde_vmlsl_high_u16(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint32_t c[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(17866156331517315627), UINT64_C( 2266995647527483782) },
      { UINT32_C(2381042498), UINT32_C(2432204963), UINT32_C( 420813315), UINT32_C(3819015864) },
      { UINT32_C(2670481689), UINT32_C( 764812711), UINT32_C( 519360919), UINT32_C( 255683021) },
      { UINT64_C(17647602341511479142), UINT64_C( 1290538134173038638) } },
    { { UINT64_C(12425314453772118076), UINT64_C( 3119700495649113263) },
      { UINT32_C(1607104696), UINT32_C( 747463061), UINT32_C(   4948274), UINT32_C( 638552298) },
      { UINT32_C(1510321329), UINT32_C(4043732033), UINT32_C( 173657336), UINT32_C(3963003956) },
      { UINT64_C(12424455149691480012), UINT64_C(  589115212562222375) } },
    { { UINT64_C(10727250376069480476), UINT64_C( 7163718143336261978) },
      { UINT32_C(2445111120), UINT32_C(3682780131), UINT32_C(3303398288), UINT32_C(2628787072) },
      { UINT32_C(2102328348), UINT32_C( 789654997), UINT32_C( 141796694), UINT32_C(2573983049) },
      { UINT64_C(10258839419865820604), UINT64_C(  397264780577919450) } },
    { { UINT64_C( 8938147640385349708), UINT64_C( 2856953468810227848) },
      { UINT32_C(3265655789), UINT32_C(2012395040), UINT32_C(2776589660), UINT32_C(2403265347) },
      { UINT32_C(4290734099), UINT32_C(2658912533), UINT32_C(3316038585), UINT32_C(2582399916) },
      { UINT64_C(18177613266822870224), UINT64_C(15097505312301268612) } },
    { { UINT64_C(11877766040469082431), UINT64_C( 6090422788463089331) },
      { UINT32_C(  89408751), UINT32_C(3349401358), UINT32_C( 931940747), UINT32_C(3570432405) },
      { UINT32_C(1379085066), UINT32_C( 754322041), UINT32_C(2703376224), UINT32_C(3069552582) },
      { UINT64_C( 9358379582852483103), UINT64_C(13577536854548421237) } },
    { { UINT64_C(11871873558399109612), UINT64_C(15064729625762156199) },
      { UINT32_C(1327776982), UINT32_C(2927303246), UINT32_C( 542088538), UINT32_C( 836125765) },
      { UINT32_C(2804650382), UINT32_C(2538335471), UINT32_C(  30615098), UINT32_C(2815681745) },
      { UINT64_C(11855277464683562888), UINT64_C(12710465572727496274) } },
    { { UINT64_C( 7720421080555845416), UINT64_C( 5009800175050060560) },
      { UINT32_C(3823940084), UINT32_C(3631888285), UINT32_C( 785993309), UINT32_C(1524018226) },
      { UINT32_C(3050360227), UINT32_C(1327559743), UINT32_C( 514108519), UINT32_C(  56896015) },
      { UINT64_C( 7316335224521946045), UINT64_C( 4923089611203291170) } },
    { { UINT64_C(16524095746587644123), UINT64_C( 8807891709168200367) },
      { UINT32_C(4130278327), UINT32_C(1715884287), UINT32_C( 193260284), UINT32_C(4027508757) },
      { UINT32_C(3244946745), UINT32_C(  94812758), UINT32_C(3169237733), UINT32_C(1530274212) },
      { UINT64_C(15911607962244547951), UINT64_C( 2644698919726925883) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint64x2_t r = simde_vmlsl_high_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint64x2_t r = simde_vmlsl_high_u32(a, b, c);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_high_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
