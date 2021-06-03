#include "simde/simde-constify.h"
#include "test/test.h"
#define SIMDE_TEST_ARM_NEON_INSN qrdmulh_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qrdmulh_lane.h"

static int
test_simde_vqrdmulh_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t  a[4];
    int16_t  v[4];
    int16_t r0[4];
    int16_t r1[4];
    int16_t r2[4];
    int16_t r3[4];
  } test_vec[] = {
    { { -INT16_C( 12561),  INT16_C(  3059),  INT16_C( 32420), -INT16_C( 18371) },
      {  INT16_C( 18618),  INT16_C(  6154),  INT16_C( 15717),  INT16_C( 31555) },
      { -INT16_C(  7137),  INT16_C(  1738),  INT16_C( 18420), -INT16_C( 10438) },
      { -INT16_C(  2359),  INT16_C(   574),  INT16_C(  6089), -INT16_C(  3450) },
      { -INT16_C(  6025),  INT16_C(  1467),  INT16_C( 15550), -INT16_C(  8812) },
      { -INT16_C( 12096),  INT16_C(  2946),  INT16_C( 31220), -INT16_C( 17691) } },
    { { -INT16_C( 10392),  INT16_C( 12208),  INT16_C(  7489), -INT16_C(  8299) },
      { -INT16_C( 29781),  INT16_C( 19791), -INT16_C(  7031),  INT16_C( 30830) },
      {  INT16_C(  9445), -INT16_C( 11095), -INT16_C(  6806),  INT16_C(  7542) },
      { -INT16_C(  6276),  INT16_C(  7373),  INT16_C(  4523), -INT16_C(  5012) },
      {  INT16_C(  2230), -INT16_C(  2619), -INT16_C(  1607),  INT16_C(  1781) },
      { -INT16_C(  9777),  INT16_C( 11486),  INT16_C(  7046), -INT16_C(  7808) } },
    { {  INT16_C( 25266),  INT16_C( 22147), -INT16_C( 15904), -INT16_C( 26097) },
      {  INT16_C(  6409),  INT16_C( 28338), -INT16_C(  2730), -INT16_C( 16662) },
      {  INT16_C(  4942),  INT16_C(  4332), -INT16_C(  3111), -INT16_C(  5104) },
      {  INT16_C( 21850),  INT16_C( 19153), -INT16_C( 13754), -INT16_C( 22569) },
      { -INT16_C(  2105), -INT16_C(  1845),  INT16_C(  1325),  INT16_C(  2174) },
      { -INT16_C( 12847), -INT16_C( 11261),  INT16_C(  8087),  INT16_C( 13270) } },
    { { -INT16_C( 25908),  INT16_C(  3821), -INT16_C( 32073),  INT16_C( 25325) },
      {  INT16_C( 15374), -INT16_C( 26704),  INT16_C(  7713), -INT16_C( 11504) },
      { -INT16_C( 12155),  INT16_C(  1793), -INT16_C( 15048),  INT16_C( 11882) },
      {  INT16_C( 21114), -INT16_C(  3114),  INT16_C( 26138), -INT16_C( 20638) },
      { -INT16_C(  6098),  INT16_C(   899), -INT16_C(  7549),  INT16_C(  5961) },
      {  INT16_C(  9096), -INT16_C(  1341),  INT16_C( 11260), -INT16_C(  8891) } },
    { { -INT16_C( 27776),  INT16_C( 24618),  INT16_C( 14676),  INT16_C( 24059) },
      { -INT16_C( 21166), -INT16_C( 22068), -INT16_C( 18781),  INT16_C( 28519) },
      {  INT16_C( 17941), -INT16_C( 15902), -INT16_C(  9480), -INT16_C( 15541) },
      {  INT16_C( 18706), -INT16_C( 16579), -INT16_C(  9884), -INT16_C( 16203) },
      {  INT16_C( 15920), -INT16_C( 14110), -INT16_C(  8412), -INT16_C( 13789) },
      { -INT16_C( 24174),  INT16_C( 21426),  INT16_C( 12773),  INT16_C( 20939) } },
    { {  INT16_C( 21840),  INT16_C(  1917),  INT16_C( 27351), -INT16_C(  6807) },
      {  INT16_C(  6567), -INT16_C( 14211), -INT16_C( 29384), -INT16_C( 18277) },
      {  INT16_C(  4377),  INT16_C(   384),  INT16_C(  5481), -INT16_C(  1364) },
      { -INT16_C(  9472), -INT16_C(   831), -INT16_C( 11862),  INT16_C(  2952) },
      { -INT16_C( 19585), -INT16_C(  1719), -INT16_C( 24526),  INT16_C(  6104) },
      { -INT16_C( 12182), -INT16_C(  1069), -INT16_C( 15256),  INT16_C(  3797) } },
    { { -INT16_C( 15072),  INT16_C( 29977),  INT16_C(  5374),  INT16_C( 20946) },
      { -INT16_C( 24895),  INT16_C( 25850),  INT16_C( 24916), -INT16_C( 23340) },
      {  INT16_C( 11451), -INT16_C( 22775), -INT16_C(  4083), -INT16_C( 15913) },
      { -INT16_C( 11890),  INT16_C( 23648),  INT16_C(  4239),  INT16_C( 16524) },
      { -INT16_C( 11460),  INT16_C( 22794),  INT16_C(  4086),  INT16_C( 15927) },
      {  INT16_C( 10735), -INT16_C( 21352), -INT16_C(  3828), -INT16_C( 14919) } },
    { {  INT16_C( 20918), -INT16_C( 29013),  INT16_C(  5564),  INT16_C( 25459) },
      { -INT16_C(  4050),  INT16_C( 26155), -INT16_C( 14723), -INT16_C( 25057) },
      { -INT16_C(  2585),  INT16_C(  3586), -INT16_C(   688), -INT16_C(  3147) },
      {  INT16_C( 16696), -INT16_C( 23158),  INT16_C(  4441),  INT16_C( 20321) },
      { -INT16_C(  9399),  INT16_C( 13036), -INT16_C(  2500), -INT16_C( 11439) },
      { -INT16_C( 15996),  INT16_C( 22186), -INT16_C(  4255), -INT16_C( 19468) } }
  };

  simde_int16x4_t a, v, r;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1_s16(test_vec[i].a);
    v = simde_vld1_s16(test_vec[i].v);

    r = simde_vqrdmulh_lane_s16(a, v, 0);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r0));

    r = simde_vqrdmulh_lane_s16(a, v, 1);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r1));

    r = simde_vqrdmulh_lane_s16(a, v, 2);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r2));

    r = simde_vqrdmulh_lane_s16(a, v, 3);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r3));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r;

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 4 ; j++) {
      SIMDE_CONSTIFY_4_(simde_vqrdmulh_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(0)), j, a, v);
      simde_test_arm_neon_write_i16x4(2, r, (j == 3) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulh_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a[2];
    int32_t  v[2];
    int32_t r0[2];
    int32_t r1[2];
  } test_vec[] = {
    { { -INT32_C(   637840845),  INT32_C(   354783389) },
      {  INT32_C(  1259318102),  INT32_C(   828664870) },
      { -INT32_C(   374039878),  INT32_C(   208050545) },
      { -INT32_C(   246128207),  INT32_C(   136902803) } },
    { { -INT32_C(  1643073658), -INT32_C(  1521776327) },
      { -INT32_C(   500203274), -INT32_C(  1146494840) },
      {  INT32_C(   382713426),  INT32_C(   354460208) },
      {  INT32_C(   877201311),  INT32_C(   812443302) } },
    { { -INT32_C(   812342222), -INT32_C(  1947879115) },
      { -INT32_C(  1948847004), -INT32_C(   423871904) },
      {  INT32_C(   737202682),  INT32_C(  1767705370) },
      {  INT32_C(   160340706),  INT32_C(   384473814) } },
    { {  INT32_C(   579128809),  INT32_C(  1288163158) },
      { -INT32_C(   668010928),  INT32_C(   160749783) },
      { -INT32_C(   180147762), -INT32_C(   400704828) },
      {  INT32_C(    43350659),  INT32_C(    96425390) } },
    { { -INT32_C(  1311168388),  INT32_C(  1178386146) },
      {  INT32_C(   332468914),  INT32_C(   905547340) },
      { -INT32_C(   202992340),  INT32_C(   182435271) },
      { -INT32_C(   552891309),  INT32_C(   496899914) } },
    { { -INT32_C(  1319600549), -INT32_C(  1644355763) },
      { -INT32_C(   311022570), -INT32_C(  2131359228) },
      {  INT32_C(   191119292),  INT32_C(   238153970) },
      {  INT32_C(  1309692304),  INT32_C(  1632009088) } },
    { {  INT32_C(   338874162),  INT32_C(  1079733901) },
      { -INT32_C(   850187135),  INT32_C(   352537786) },
      { -INT32_C(   134160022), -INT32_C(   427465826) },
      {  INT32_C(    55630667),  INT32_C(   177252572) } },
    { {  INT32_C(   415652810), -INT32_C(  1867135878) },
      { -INT32_C(   193123344),  INT32_C(  1752462389) },
      { -INT32_C(    37379684),  INT32_C(   167911651) },
      {  INT32_C(   339195093), -INT32_C(  1523683500) } }
  };

  simde_int32x2_t a, v, r;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1_s32(test_vec[i].a);
    v = simde_vld1_s32(test_vec[i].v);

    r = simde_vqrdmulh_lane_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r0));

    r = simde_vqrdmulh_lane_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r1));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r;

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 2 ; j++) {
      SIMDE_CONSTIFY_2_(simde_vqrdmulh_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(0)), j, a, v);
      simde_test_arm_neon_write_i32x2(2, r, (j == 1) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t  a[8];
    int16_t  v[4];
    int16_t r0[8];
    int16_t r1[8];
    int16_t r2[8];
    int16_t r3[8];
  } test_vec[] = {
    { {  INT16_C( 17734),  INT16_C( 32169), -INT16_C( 31975), -INT16_C( 28787),  INT16_C( 16455), -INT16_C( 10887),  INT16_C( 30043),  INT16_C( 24724) },
      { -INT16_C(  3730),  INT16_C( 27154), -INT16_C( 24769), -INT16_C( 20800) },
      { -INT16_C(  2019), -INT16_C(  3662),  INT16_C(  3640),  INT16_C(  3277), -INT16_C(  1873),  INT16_C(  1239), -INT16_C(  3420), -INT16_C(  2814) },
      {  INT16_C( 14696),  INT16_C( 26658), -INT16_C( 26497), -INT16_C( 23855),  INT16_C( 13636), -INT16_C(  9022),  INT16_C( 24896),  INT16_C( 20488) },
      { -INT16_C( 13405), -INT16_C( 24316),  INT16_C( 24170),  INT16_C( 21760), -INT16_C( 12438),  INT16_C(  8229), -INT16_C( 22709), -INT16_C( 18689) },
      { -INT16_C( 11257), -INT16_C( 20420),  INT16_C( 20297),  INT16_C( 18273), -INT16_C( 10445),  INT16_C(  6911), -INT16_C( 19070), -INT16_C( 15694) } },
    { { -INT16_C(  7007), -INT16_C( 23903),  INT16_C( 29110), -INT16_C(  1021), -INT16_C( 21321), -INT16_C( 12167),  INT16_C(  1584),  INT16_C( 30559) },
      { -INT16_C(  9914), -INT16_C( 24244), -INT16_C(  7858), -INT16_C( 17407) },
      {  INT16_C(  2120),  INT16_C(  7232), -INT16_C(  8807),  INT16_C(   309),  INT16_C(  6451),  INT16_C(  3681), -INT16_C(   479), -INT16_C(  9246) },
      {  INT16_C(  5184),  INT16_C( 17685), -INT16_C( 21538),  INT16_C(   755),  INT16_C( 15775),  INT16_C(  9002), -INT16_C(  1172), -INT16_C( 22610) },
      {  INT16_C(  1680),  INT16_C(  5732), -INT16_C(  6981),  INT16_C(   245),  INT16_C(  5113),  INT16_C(  2918), -INT16_C(   380), -INT16_C(  7328) },
      {  INT16_C(  3722),  INT16_C( 12698), -INT16_C( 15464),  INT16_C(   542),  INT16_C( 11326),  INT16_C(  6463), -INT16_C(   841), -INT16_C( 16234) } },
    { {  INT16_C(  5330),  INT16_C(  4390), -INT16_C(  6477),  INT16_C( 21696),  INT16_C( 25035), -INT16_C( 32265), -INT16_C(  1326), -INT16_C( 30338) },
      { -INT16_C(  2137), -INT16_C( 10407), -INT16_C( 17922),  INT16_C( 17486) },
      { -INT16_C(   348), -INT16_C(   286),  INT16_C(   422), -INT16_C(  1415), -INT16_C(  1633),  INT16_C(  2104),  INT16_C(    86),  INT16_C(  1979) },
      { -INT16_C(  1693), -INT16_C(  1394),  INT16_C(  2057), -INT16_C(  6891), -INT16_C(  7951),  INT16_C( 10247),  INT16_C(   421),  INT16_C(  9635) },
      { -INT16_C(  2915), -INT16_C(  2401),  INT16_C(  3543), -INT16_C( 11866), -INT16_C( 13693),  INT16_C( 17647),  INT16_C(   725),  INT16_C( 16593) },
      {  INT16_C(  2844),  INT16_C(  2343), -INT16_C(  3456),  INT16_C( 11578),  INT16_C( 13359), -INT16_C( 17218), -INT16_C(   708), -INT16_C( 16189) } },
    { { -INT16_C( 25966), -INT16_C(  7962), -INT16_C(  6277),  INT16_C( 20124), -INT16_C( 15365), -INT16_C( 20641),  INT16_C(  8105),  INT16_C( 29699) },
      { -INT16_C(  1408),  INT16_C( 21494),  INT16_C( 29941), -INT16_C( 25380) },
      {  INT16_C(  1116),  INT16_C(   342),  INT16_C(   270), -INT16_C(   865),  INT16_C(   660),  INT16_C(   887), -INT16_C(   348), -INT16_C(  1276) },
      { -INT16_C( 17032), -INT16_C(  5223), -INT16_C(  4117),  INT16_C( 13200), -INT16_C( 10079), -INT16_C( 13539),  INT16_C(  5316),  INT16_C( 19481) },
      { -INT16_C( 23726), -INT16_C(  7275), -INT16_C(  5735),  INT16_C( 18388), -INT16_C( 14039), -INT16_C( 18860),  INT16_C(  7406),  INT16_C( 27137) },
      {  INT16_C( 20112),  INT16_C(  6167),  INT16_C(  4862), -INT16_C( 15587),  INT16_C( 11901),  INT16_C( 15987), -INT16_C(  6278), -INT16_C( 23003) } },
    { {  INT16_C( 13931),  INT16_C( 26995), -INT16_C( 15889), -INT16_C( 32338), -INT16_C( 27557), -INT16_C( 10399), -INT16_C(   645),  INT16_C( 30501) },
      { -INT16_C( 31552),  INT16_C( 27174),  INT16_C( 10660),  INT16_C(  9438) },
      { -INT16_C( 13414), -INT16_C( 25993),  INT16_C( 15299),  INT16_C( 31138),  INT16_C( 26534),  INT16_C( 10013),  INT16_C(   621), -INT16_C( 29369) },
      {  INT16_C( 11553),  INT16_C( 22387), -INT16_C( 13177), -INT16_C( 26817), -INT16_C( 22853), -INT16_C(  8624), -INT16_C(   535),  INT16_C( 25294) },
      {  INT16_C(  4532),  INT16_C(  8782), -INT16_C(  5169), -INT16_C( 10520), -INT16_C(  8965), -INT16_C(  3383), -INT16_C(   210),  INT16_C(  9923) },
      {  INT16_C(  4012),  INT16_C(  7775), -INT16_C(  4576), -INT16_C(  9314), -INT16_C(  7937), -INT16_C(  2995), -INT16_C(   186),  INT16_C(  8785) } },
    { { -INT16_C( 11228),  INT16_C(  6519),  INT16_C( 21576), -INT16_C( 19275),  INT16_C( 10378),  INT16_C( 31005), -INT16_C( 13335),  INT16_C( 17658) },
      {  INT16_C( 23391), -INT16_C(  9445),  INT16_C( 16472),  INT16_C(  6482) },
      { -INT16_C(  8015),  INT16_C(  4654),  INT16_C( 15402), -INT16_C( 13759),  INT16_C(  7408),  INT16_C( 22133), -INT16_C(  9519),  INT16_C( 12605) },
      {  INT16_C(  3236), -INT16_C(  1879), -INT16_C(  6219),  INT16_C(  5556), -INT16_C(  2991), -INT16_C(  8937),  INT16_C(  3844), -INT16_C(  5090) },
      { -INT16_C(  5644),  INT16_C(  3277),  INT16_C( 10846), -INT16_C(  9689),  INT16_C(  5217),  INT16_C( 15586), -INT16_C(  6703),  INT16_C(  8876) },
      { -INT16_C(  2221),  INT16_C(  1290),  INT16_C(  4268), -INT16_C(  3813),  INT16_C(  2053),  INT16_C(  6133), -INT16_C(  2638),  INT16_C(  3493) } },
    { {  INT16_C( 30917),  INT16_C( 27011),  INT16_C( 24993), -INT16_C( 14963),  INT16_C(  1334),  INT16_C( 32478), -INT16_C( 27815), -INT16_C(  7374) },
      {  INT16_C( 20667), -INT16_C( 23460),  INT16_C( 22043),  INT16_C( 31721) },
      {  INT16_C( 19500),  INT16_C( 17036),  INT16_C( 15763), -INT16_C(  9437),  INT16_C(   841),  INT16_C( 20484), -INT16_C( 17543), -INT16_C(  4651) },
      { -INT16_C( 22135), -INT16_C( 19338), -INT16_C( 17894),  INT16_C( 10713), -INT16_C(   955), -INT16_C( 23252),  INT16_C( 19914),  INT16_C(  5279) },
      {  INT16_C( 20798),  INT16_C( 18170),  INT16_C( 16813), -INT16_C( 10066),  INT16_C(   897),  INT16_C( 21848), -INT16_C( 18711), -INT16_C(  4960) },
      {  INT16_C( 29929),  INT16_C( 26148),  INT16_C( 24194), -INT16_C( 14485),  INT16_C(  1291),  INT16_C( 31440), -INT16_C( 26926), -INT16_C(  7138) } },
    { {  INT16_C(  1201),  INT16_C(  2390), -INT16_C( 22459),  INT16_C(  2594), -INT16_C( 23264), -INT16_C( 16013),  INT16_C(     7),  INT16_C( 15751) },
      {  INT16_C( 25861),  INT16_C( 24251), -INT16_C(  4359), -INT16_C( 19391) },
      {  INT16_C(   948),  INT16_C(  1886), -INT16_C( 17725),  INT16_C(  2047), -INT16_C( 18360), -INT16_C( 12638),  INT16_C(     6),  INT16_C( 12431) },
      {  INT16_C(   889),  INT16_C(  1769), -INT16_C( 16621),  INT16_C(  1920), -INT16_C( 17217), -INT16_C( 11851),  INT16_C(     5),  INT16_C( 11657) },
      { -INT16_C(   160), -INT16_C(   318),  INT16_C(  2988), -INT16_C(   345),  INT16_C(  3095),  INT16_C(  2130), -INT16_C(     1), -INT16_C(  2095) },
      { -INT16_C(   711), -INT16_C(  1414),  INT16_C( 13290), -INT16_C(  1535),  INT16_C( 13767),  INT16_C(  9476), -INT16_C(     4), -INT16_C(  9321) } }
  };

  simde_int16x8_t a, r;
  simde_int16x4_t v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s16(test_vec[i].a);
    v = simde_vld1_s16(test_vec[i].v);

    r = simde_vqrdmulhq_lane_s16(a, v, 0);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r0));

    r = simde_vqrdmulhq_lane_s16(a, v, 1);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r1));

    r = simde_vqrdmulhq_lane_s16(a, v, 2);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r2));

    r = simde_vqrdmulhq_lane_s16(a, v, 3);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r3));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t r;

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 4 ; j++) {
      SIMDE_CONSTIFY_4_(simde_vqrdmulhq_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(0)), j, a, v);
      simde_test_arm_neon_write_i16x8(2, r, (j == 3) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a[4];
    int32_t  v[2];
    int32_t r0[4];
    int32_t r1[4];
  } test_vec[] = {
    { {  INT32_C(  1499045182), -INT32_C(  1529593101), -INT32_C(  1951520186), -INT32_C(   225062702) },
      {  INT32_C(  2108950646),  INT32_C(   247085833) },
      {  INT32_C(  1472147324), -INT32_C(  1502147111), -INT32_C(  1916503421), -INT32_C(   221024328) },
      {  INT32_C(   172477601), -INT32_C(   175992393), -INT32_C(   224538609), -INT32_C(    25895333) } },
    { { -INT32_C(  1720879712), -INT32_C(  1588679069),  INT32_C(  1073456972),  INT32_C(   803524585) },
      { -INT32_C(   860122374), -INT32_C(   658550686) },
      {  INT32_C(   689256537),  INT32_C(   636306783), -INT32_C(   429947096), -INT32_C(   321832240) },
      {  INT32_C(   527727657),  INT32_C(   487186802), -INT32_C(   329187990), -INT32_C(   246410103) } },
    { {  INT32_C(  1649767257),  INT32_C(  1315966894), -INT32_C(   387392123), -INT32_C(   662030708) },
      { -INT32_C(   971536931),  INT32_C(  1324743508) },
      { -INT32_C(   746366483), -INT32_C(   595352816),  INT32_C(   175258962),  INT32_C(   299507418) },
      {  INT32_C(  1017711341),  INT32_C(   811795983), -INT32_C(   238975137), -INT32_C(   408394673) } },
    { { -INT32_C(   266620787),  INT32_C(  1523112449), -INT32_C(    71557555), -INT32_C(  1303827411) },
      { -INT32_C(  1768214262),  INT32_C(  1148069223) },
      {  INT32_C(   219532604), -INT32_C(  1254113929),  INT32_C(    58919699),  INT32_C(  1073557056) },
      { -INT32_C(   142538510),  INT32_C(   814273267), -INT32_C(    38255484), -INT32_C(   697040988) } },
    { { -INT32_C(    32864854),  INT32_C(   239927425), -INT32_C(  1308727120), -INT32_C(  1895053502) },
      {  INT32_C(   311085029), -INT32_C(    20589580) },
      { -INT32_C(     4760811),  INT32_C(    34755948), -INT32_C(   189582544), -INT32_C(   274517934) },
      {  INT32_C(      315101), -INT32_C(     2300369),  INT32_C(    12547775),  INT32_C(    18169338) } },
    { {  INT32_C(  1821663237),  INT32_C(   800129669),  INT32_C(   137214855),  INT32_C(  1813478075) },
      {  INT32_C(   605885922), -INT32_C(  1045222948) },
      {  INT32_C(   513959727),  INT32_C(   225746679),  INT32_C(    38713472),  INT32_C(   511650385) },
      { -INT32_C(   886639682), -INT32_C(   389439003), -INT32_C(    66785195), -INT32_C(   882655801) } },
    { { -INT32_C(   455852560),  INT32_C(   383949073),  INT32_C(  2122479353),  INT32_C(    11350904) },
      { -INT32_C(  1442260241),  INT32_C(   924196693) },
      {  INT32_C(   306152749), -INT32_C(   257862025), -INT32_C(  1425467237), -INT32_C(     7623321) },
      { -INT32_C(   196181903),  INT32_C(   165237330),  INT32_C(   913435779),  INT32_C(     4885005) } },
    { {  INT32_C(   291255349),  INT32_C(  1305677661),  INT32_C(  1580377933),  INT32_C(   963908672) },
      {  INT32_C(    62387851),  INT32_C(   419652650) },
      {  INT32_C(     8461436),  INT32_C(    37932034),  INT32_C(    45912519),  INT32_C(    28003096) },
      {  INT32_C(    56915953),  INT32_C(   255150297),  INT32_C(   308831123),  INT32_C(   188363171) } }
  };

  simde_int32x4_t a, r;
  simde_int32x2_t v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s32(test_vec[i].a);
    v = simde_vld1_s32(test_vec[i].v);

    r = simde_vqrdmulhq_lane_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r0));

    r = simde_vqrdmulhq_lane_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r1));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t r;

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 2 ; j++) {
      SIMDE_CONSTIFY_2_(simde_vqrdmulhq_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), j, a, v);
      simde_test_arm_neon_write_i32x4(2, r, (j == 1) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulh_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t  a[4];
    int16_t  v[8];
    int16_t r0[4];
    int16_t r1[4];
    int16_t r2[4];
    int16_t r3[4];
    int16_t r4[4];
    int16_t r5[4];
    int16_t r6[4];
    int16_t r7[4];
  } test_vec[] = {
    { {  INT16_C( 27427), -INT16_C(  7217), -INT16_C( 15719), -INT16_C(  7778) },
      { -INT16_C( 15305), -INT16_C( 25277),  INT16_C( 22130),  INT16_C( 27126), -INT16_C( 30572), -INT16_C( 19037), -INT16_C( 22542), -INT16_C( 21501) },
      { -INT16_C( 12810),  INT16_C(  3371),  INT16_C(  7342),  INT16_C(  3633) },
      { -INT16_C( 21157),  INT16_C(  5567),  INT16_C( 12126),  INT16_C(  6000) },
      {  INT16_C( 18523), -INT16_C(  4874), -INT16_C( 10616), -INT16_C(  5253) },
      {  INT16_C( 22705), -INT16_C(  5974), -INT16_C( 13012), -INT16_C(  6439) },
      { -INT16_C( 25589),  INT16_C(  6733),  INT16_C( 14666),  INT16_C(  7257) },
      { -INT16_C( 15934),  INT16_C(  4193),  INT16_C(  9132),  INT16_C(  4519) },
      { -INT16_C( 18868),  INT16_C(  4965),  INT16_C( 10814),  INT16_C(  5351) },
      { -INT16_C( 17996),  INT16_C(  4735),  INT16_C( 10314),  INT16_C(  5104) } },
    { { -INT16_C(  2542), -INT16_C( 15734), -INT16_C( 30695),  INT16_C( 15361) },
      { -INT16_C( 12045), -INT16_C( 29664), -INT16_C( 16750), -INT16_C( 13971), -INT16_C( 20094), -INT16_C(  2714),  INT16_C( 23559), -INT16_C( 25762) },
      {  INT16_C(   934),  INT16_C(  5784),  INT16_C( 11283), -INT16_C(  5646) },
      {  INT16_C(  2301),  INT16_C( 14244),  INT16_C( 27787), -INT16_C( 13906) },
      {  INT16_C(  1299),  INT16_C(  8043),  INT16_C( 15690), -INT16_C(  7852) },
      {  INT16_C(  1084),  INT16_C(  6708),  INT16_C( 13087), -INT16_C(  6549) },
      {  INT16_C(  1559),  INT16_C(  9648),  INT16_C( 18823), -INT16_C(  9420) },
      {  INT16_C(   211),  INT16_C(  1303),  INT16_C(  2542), -INT16_C(  1272) },
      { -INT16_C(  1828), -INT16_C( 11312), -INT16_C( 22069),  INT16_C( 11044) },
      {  INT16_C(  1999),  INT16_C( 12370),  INT16_C( 24132), -INT16_C( 12077) } },
    { {  INT16_C(   484), -INT16_C( 10416),  INT16_C( 21416), -INT16_C( 17789) },
      {  INT16_C(  3657),  INT16_C( 25212),  INT16_C( 32150), -INT16_C( 30306), -INT16_C( 16819), -INT16_C(  8427), -INT16_C( 32132), -INT16_C(    87) },
      {  INT16_C(    54), -INT16_C(  1162),  INT16_C(  2390), -INT16_C(  1985) },
      {  INT16_C(   372), -INT16_C(  8014),  INT16_C( 16478), -INT16_C( 13687) },
      {  INT16_C(   475), -INT16_C( 10220),  INT16_C( 21012), -INT16_C( 17454) },
      { -INT16_C(   448),  INT16_C(  9633), -INT16_C( 19807),  INT16_C( 16452) },
      { -INT16_C(   248),  INT16_C(  5346), -INT16_C( 10992),  INT16_C(  9131) },
      { -INT16_C(   124),  INT16_C(  2679), -INT16_C(  5508),  INT16_C(  4575) },
      { -INT16_C(   475),  INT16_C( 10214), -INT16_C( 21000),  INT16_C( 17444) },
      { -INT16_C(     1),  INT16_C(    28), -INT16_C(    57),  INT16_C(    47) } },
    { {  INT16_C(  3891),  INT16_C( 15092),  INT16_C( 21100),  INT16_C( 20693) },
      {  INT16_C(  9555), -INT16_C(  1241), -INT16_C( 21640), -INT16_C( 15947),  INT16_C( 12729),  INT16_C( 20259), -INT16_C( 15697), -INT16_C(   808) },
      {  INT16_C(  1135),  INT16_C(  4401),  INT16_C(  6153),  INT16_C(  6034) },
      { -INT16_C(   147), -INT16_C(   572), -INT16_C(   799), -INT16_C(   784) },
      { -INT16_C(  2570), -INT16_C(  9967), -INT16_C( 13934), -INT16_C( 13666) },
      { -INT16_C(  1894), -INT16_C(  7345), -INT16_C( 10269), -INT16_C( 10071) },
      {  INT16_C(  1511),  INT16_C(  5863),  INT16_C(  8196),  INT16_C(  8038) },
      {  INT16_C(  2406),  INT16_C(  9331),  INT16_C( 13045),  INT16_C( 12794) },
      { -INT16_C(  1864), -INT16_C(  7230), -INT16_C( 10108), -INT16_C(  9913) },
      { -INT16_C(    96), -INT16_C(   372), -INT16_C(   520), -INT16_C(   510) } },
    { { -INT16_C(  4736), -INT16_C(   548), -INT16_C( 31377), -INT16_C( 23556) },
      { -INT16_C(  3948),  INT16_C(   221), -INT16_C( 19646), -INT16_C( 27311),  INT16_C( 30936),  INT16_C( 20880),  INT16_C( 17699), -INT16_C(  9198) },
      {  INT16_C(   571),  INT16_C(    66),  INT16_C(  3780),  INT16_C(  2838) },
      { -INT16_C(    32), -INT16_C(     4), -INT16_C(   212), -INT16_C(   159) },
      {  INT16_C(  2839),  INT16_C(   329),  INT16_C( 18812),  INT16_C( 14123) },
      {  INT16_C(  3947),  INT16_C(   457),  INT16_C( 26152),  INT16_C( 19633) },
      { -INT16_C(  4471), -INT16_C(   517), -INT16_C( 29623), -INT16_C( 22239) },
      { -INT16_C(  3018), -INT16_C(   349), -INT16_C( 19994), -INT16_C( 15010) },
      { -INT16_C(  2558), -INT16_C(   296), -INT16_C( 16948), -INT16_C( 12723) },
      {  INT16_C(  1329),  INT16_C(   154),  INT16_C(  8808),  INT16_C(  6612) } },
    { {  INT16_C( 13942),  INT16_C(  9515),  INT16_C(  1016),  INT16_C( 30754) },
      { -INT16_C(   272),  INT16_C( 24693),  INT16_C( 29059),  INT16_C(  5891), -INT16_C(  8095), -INT16_C( 23784),  INT16_C( 27027),  INT16_C( 27704) },
      { -INT16_C(   116), -INT16_C(    79), -INT16_C(     8), -INT16_C(   255) },
      {  INT16_C( 10506),  INT16_C(  7170),  INT16_C(   766),  INT16_C( 23175) },
      {  INT16_C( 12364),  INT16_C(  8438),  INT16_C(   901),  INT16_C( 27273) },
      {  INT16_C(  2506),  INT16_C(  1711),  INT16_C(   183),  INT16_C(  5529) },
      { -INT16_C(  3444), -INT16_C(  2351), -INT16_C(   251), -INT16_C(  7597) },
      { -INT16_C( 10120), -INT16_C(  6906), -INT16_C(   737), -INT16_C( 22322) },
      {  INT16_C( 11499),  INT16_C(  7848),  INT16_C(   838),  INT16_C( 25366) },
      {  INT16_C( 11787),  INT16_C(  8045),  INT16_C(   859),  INT16_C( 26001) } },
    { { -INT16_C( 14111),  INT16_C(  1469), -INT16_C( 12531), -INT16_C( 31519) },
      {  INT16_C(  3333), -INT16_C(   599), -INT16_C( 13552),  INT16_C(   374), -INT16_C(  5175),  INT16_C( 19553),  INT16_C( 25693), -INT16_C( 16796) },
      { -INT16_C(  1435),  INT16_C(   149), -INT16_C(  1275), -INT16_C(  3206) },
      {  INT16_C(   258), -INT16_C(    27),  INT16_C(   229),  INT16_C(   576) },
      {  INT16_C(  5836), -INT16_C(   608),  INT16_C(  5182),  INT16_C( 13035) },
      { -INT16_C(   161),  INT16_C(    17), -INT16_C(   143), -INT16_C(   360) },
      {  INT16_C(  2229), -INT16_C(   232),  INT16_C(  1979),  INT16_C(  4978) },
      { -INT16_C(  8420),  INT16_C(   877), -INT16_C(  7477), -INT16_C( 18808) },
      { -INT16_C( 11064),  INT16_C(  1152), -INT16_C(  9825), -INT16_C( 24714) },
      {  INT16_C(  7233), -INT16_C(   753),  INT16_C(  6423),  INT16_C( 16156) } },
    { {  INT16_C( 31812), -INT16_C( 10142), -INT16_C( 25883), -INT16_C( 14780) },
      {  INT16_C(   355),  INT16_C( 28875), -INT16_C( 21040), -INT16_C( 10508), -INT16_C( 24902), -INT16_C( 13613),  INT16_C( 18793),  INT16_C( 13259) },
      {  INT16_C(   345), -INT16_C(   110), -INT16_C(   280), -INT16_C(   160) },
      {  INT16_C( 28033), -INT16_C(  8937), -INT16_C( 22808), -INT16_C( 13024) },
      { -INT16_C( 20426),  INT16_C(  6512),  INT16_C( 16619),  INT16_C(  9490) },
      { -INT16_C( 10201),  INT16_C(  3252),  INT16_C(  8300),  INT16_C(  4740) },
      { -INT16_C( 24175),  INT16_C(  7707),  INT16_C( 19670),  INT16_C( 11232) },
      { -INT16_C( 13216),  INT16_C(  4213),  INT16_C( 10753),  INT16_C(  6140) },
      {  INT16_C( 18245), -INT16_C(  5817), -INT16_C( 14844), -INT16_C(  8477) },
      {  INT16_C( 12872), -INT16_C(  4104), -INT16_C( 10473), -INT16_C(  5980) } }
  };

  simde_int16x4_t a, r;
  simde_int16x8_t v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1_s16(test_vec[i].a);
    v = simde_vld1q_s16(test_vec[i].v);

    r = simde_vqrdmulh_laneq_s16(a, v, 0);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r0));

    r = simde_vqrdmulh_laneq_s16(a, v, 1);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r1));

    r = simde_vqrdmulh_laneq_s16(a, v, 2);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r2));

    r = simde_vqrdmulh_laneq_s16(a, v, 3);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r3));

    r = simde_vqrdmulh_laneq_s16(a, v, 4);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r4));

    r = simde_vqrdmulh_laneq_s16(a, v, 5);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r5));

    r = simde_vqrdmulh_laneq_s16(a, v, 6);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r6));

    r = simde_vqrdmulh_laneq_s16(a, v, 7);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r7));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t r;

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 8 ; j++) {
      SIMDE_CONSTIFY_8_(simde_vqrdmulh_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(0)), j, a, v);
      simde_test_arm_neon_write_i16x4(2, r, (j == 7) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulh_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a[2];
    int32_t  v[4];
    int32_t r0[2];
    int32_t r1[2];
    int32_t r2[2];
    int32_t r3[2];
  } test_vec[] = {
    { { -INT32_C(  1837159371), -INT32_C(   716119152) },
      {  INT32_C(  1152234079), -INT32_C(  1341394611), -INT32_C(  1038035214),  INT32_C(  1033377155) },
      { -INT32_C(   985729339), -INT32_C(   384234307) },
      {  INT32_C(  1147555038),  INT32_C(   447313474) },
      {  INT32_C(   888032895),  INT32_C(   346152530) },
      { -INT32_C(   884047953), -INT32_C(   344599212) } },
    { {  INT32_C(   470314163), -INT32_C(   363867211) },
      { -INT32_C(  1870868736),  INT32_C(   308661682), -INT32_C(   866774401), -INT32_C(   176398077) },
      { -INT32_C(   409733534),  INT32_C(   316997892) },
      {  INT32_C(    67599099), -INT32_C(    52299288) },
      { -INT32_C(   189829747),  INT32_C(   146865278) },
      { -INT32_C(    38632431),  INT32_C(    29888692) } },
    { { -INT32_C(  1145529032),  INT32_C(  1710837938) },
      {  INT32_C(  1921057212), -INT32_C(   732114476),  INT32_C(  1382406560),  INT32_C(   627362470) },
      { -INT32_C(  1024746713),  INT32_C(  1530450564) },
      {  INT32_C(   390530744), -INT32_C(   583254369) },
      { -INT32_C(   737415090),  INT32_C(  1101323212) },
      { -INT32_C(   334653036),  INT32_C(   499801484) } },
    { { -INT32_C(   520963107),  INT32_C(  1423339036) },
      { -INT32_C(  1122988533), -INT32_C(  1692268066), -INT32_C(   569531382),  INT32_C(   364079477) },
      {  INT32_C(   272428428), -INT32_C(   744309936) },
      {  INT32_C(   410531289), -INT32_C(  1121624931) },
      {  INT32_C(   138163957), -INT32_C(   377481919) },
      { -INT32_C(    88322896),  INT32_C(   241309652) } },
    { { -INT32_C(   395896766), -INT32_C(  1089549086) },
      { -INT32_C(  1549795193),  INT32_C(  2063103598), -INT32_C(   499709948),  INT32_C(   461199889) },
      {  INT32_C(   285710629),  INT32_C(   786305375) },
      { -INT32_C(   380340983), -INT32_C(  1046737954) },
      {  INT32_C(    92123427),  INT32_C(   253533254) },
      { -INT32_C(    85023951), -INT32_C(   233994758) } },
    { {  INT32_C(  1945733886),  INT32_C(   914926836) },
      { -INT32_C(  1491079228),  INT32_C(  1113992635), -INT32_C(  1679423955), -INT32_C(  2146050436) },
      { -INT32_C(  1350996727), -INT32_C(   635268353) },
      {  INT32_C(  1009336309),  INT32_C(   474612115) },
      { -INT32_C(  1521647022), -INT32_C(   715511872) },
      { -INT32_C(  1944435320), -INT32_C(   914316222) } },
    { { -INT32_C(   144486938), -INT32_C(  1525489497) },
      {  INT32_C(  1595411307),  INT32_C(  2090180792),  INT32_C(  1260631183),  INT32_C(   244157153) },
      { -INT32_C(   107342421), -INT32_C(  1133318614) },
      { -INT32_C(   140631489), -INT32_C(  1484783760) },
      { -INT32_C(    84817754), -INT32_C(   895503736) },
      { -INT32_C(    16427375), -INT32_C(   173439818) } },
    { {  INT32_C(   229274512),  INT32_C(   932036433) },
      { -INT32_C(  1288769524),  INT32_C(  1012416721),  INT32_C(    77295692), -INT32_C(  1602211824) },
      { -INT32_C(   137594530), -INT32_C(   559343095) },
      {  INT32_C(   108089926),  INT32_C(   439402307) },
      {  INT32_C(     8252418),  INT32_C(    33547357) },
      { -INT32_C(   171058967), -INT32_C(   695381217) } }
  };

  simde_int32x2_t a, r;
  simde_int32x4_t v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1_s32(test_vec[i].a);
    v = simde_vld1q_s32(test_vec[i].v);

    r = simde_vqrdmulh_laneq_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r0));

    r = simde_vqrdmulh_laneq_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r1));

    r = simde_vqrdmulh_laneq_s32(a, v, 2);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r2));

    r = simde_vqrdmulh_laneq_s32(a, v, 3);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r3));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t r;

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 4 ; j++) {
      SIMDE_CONSTIFY_4_(simde_vqrdmulh_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(0)), j, a, v);
      simde_test_arm_neon_write_i32x2(2, r, (j == 3) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t  a[8];
    int16_t  v[8];
    int16_t r0[8];
    int16_t r1[8];
    int16_t r2[8];
    int16_t r3[8];
    int16_t r4[8];
    int16_t r5[8];
    int16_t r6[8];
    int16_t r7[8];
  } test_vec[] = {
    { { -INT16_C( 23323), -INT16_C( 14613),  INT16_C( 30766), -INT16_C( 16683),  INT16_C( 32748),  INT16_C( 15819),  INT16_C( 22846),  INT16_C( 19317) },
      { -INT16_C( 23735),  INT16_C(  6910),  INT16_C( 22500),  INT16_C( 12374), -INT16_C(  3641), -INT16_C( 10188), -INT16_C( 19422),  INT16_C(  1912) },
      {  INT16_C( 16894),  INT16_C( 10585), -INT16_C( 22285),  INT16_C( 12084), -INT16_C( 23721), -INT16_C( 11458), -INT16_C( 16548), -INT16_C( 13992) },
      { -INT16_C(  4918), -INT16_C(  3082),  INT16_C(  6488), -INT16_C(  3518),  INT16_C(  6906),  INT16_C(  3336),  INT16_C(  4818),  INT16_C(  4074) },
      { -INT16_C( 16015), -INT16_C( 10034),  INT16_C( 21125), -INT16_C( 11455),  INT16_C( 22486),  INT16_C( 10862),  INT16_C( 15687),  INT16_C( 13264) },
      { -INT16_C(  8807), -INT16_C(  5518),  INT16_C( 11618), -INT16_C(  6300),  INT16_C( 12366),  INT16_C(  5974),  INT16_C(  8627),  INT16_C(  7295) },
      {  INT16_C(  2592),  INT16_C(  1624), -INT16_C(  3419),  INT16_C(  1854), -INT16_C(  3639), -INT16_C(  1758), -INT16_C(  2539), -INT16_C(  2146) },
      {  INT16_C(  7251),  INT16_C(  4543), -INT16_C(  9566),  INT16_C(  5187), -INT16_C( 10182), -INT16_C(  4918), -INT16_C(  7103), -INT16_C(  6006) },
      {  INT16_C( 13824),  INT16_C(  8661), -INT16_C( 18235),  INT16_C(  9888), -INT16_C( 19410), -INT16_C(  9376), -INT16_C( 13541), -INT16_C( 11449) },
      { -INT16_C(  1361), -INT16_C(   853),  INT16_C(  1795), -INT16_C(   973),  INT16_C(  1911),  INT16_C(   923),  INT16_C(  1333),  INT16_C(  1127) } },
    { {  INT16_C( 25432), -INT16_C( 31027), -INT16_C( 23845), -INT16_C( 14523),  INT16_C(  4129),  INT16_C( 24581),  INT16_C( 31337), -INT16_C( 19541) },
      { -INT16_C( 22243),  INT16_C(   461),  INT16_C(  9216), -INT16_C( 14287),  INT16_C( 25877),  INT16_C( 14240),  INT16_C(  6170),  INT16_C( 29246) },
      { -INT16_C( 17263),  INT16_C( 21061),  INT16_C( 16186),  INT16_C(  9858), -INT16_C(  2803), -INT16_C( 16686), -INT16_C( 21272),  INT16_C( 13264) },
      {  INT16_C(   358), -INT16_C(   437), -INT16_C(   335), -INT16_C(   204),  INT16_C(    58),  INT16_C(   346),  INT16_C(   441), -INT16_C(   275) },
      {  INT16_C(  7153), -INT16_C(  8726), -INT16_C(  6706), -INT16_C(  4085),  INT16_C(  1161),  INT16_C(  6913),  INT16_C(  8814), -INT16_C(  5496) },
      { -INT16_C( 11088),  INT16_C( 13528),  INT16_C( 10397),  INT16_C(  6332), -INT16_C(  1800), -INT16_C( 10717), -INT16_C( 13663),  INT16_C(  8520) },
      {  INT16_C( 20084), -INT16_C( 24502), -INT16_C( 18830), -INT16_C( 11469),  INT16_C(  3261),  INT16_C( 19412),  INT16_C( 24747), -INT16_C( 15432) },
      {  INT16_C( 11052), -INT16_C( 13483), -INT16_C( 10362), -INT16_C(  6311),  INT16_C(  1794),  INT16_C( 10682),  INT16_C( 13618), -INT16_C(  8492) },
      {  INT16_C(  4789), -INT16_C(  5842), -INT16_C(  4490), -INT16_C(  2735),  INT16_C(   777),  INT16_C(  4628),  INT16_C(  5901), -INT16_C(  3679) },
      {  INT16_C( 22698), -INT16_C( 27692), -INT16_C( 21282), -INT16_C( 12962),  INT16_C(  3685),  INT16_C( 21939),  INT16_C( 27969), -INT16_C( 17441) } },
    { {  INT16_C(  3195),  INT16_C( 22265),  INT16_C( 16046), -INT16_C( 12258),  INT16_C(  9038), -INT16_C( 18384), -INT16_C(  9315), -INT16_C( 17813) },
      {  INT16_C( 14468), -INT16_C( 31300), -INT16_C(  4772),  INT16_C( 29261), -INT16_C(  4781),  INT16_C( 28073), -INT16_C(  6139), -INT16_C( 32545) },
      {  INT16_C(  1411),  INT16_C(  9831),  INT16_C(  7085), -INT16_C(  5412),  INT16_C(  3991), -INT16_C(  8117), -INT16_C(  4113), -INT16_C(  7865) },
      { -INT16_C(  3052), -INT16_C( 21268), -INT16_C( 15327),  INT16_C( 11709), -INT16_C(  8633),  INT16_C( 17560),  INT16_C(  8898),  INT16_C( 17015) },
      { -INT16_C(   465), -INT16_C(  3242), -INT16_C(  2337),  INT16_C(  1785), -INT16_C(  1316),  INT16_C(  2677),  INT16_C(  1357),  INT16_C(  2594) },
      {  INT16_C(  2853),  INT16_C( 19882),  INT16_C( 14329), -INT16_C( 10946),  INT16_C(  8071), -INT16_C( 16416), -INT16_C(  8318), -INT16_C( 15907) },
      { -INT16_C(   466), -INT16_C(  3249), -INT16_C(  2341),  INT16_C(  1788), -INT16_C(  1319),  INT16_C(  2682),  INT16_C(  1359),  INT16_C(  2599) },
      {  INT16_C(  2737),  INT16_C( 19075),  INT16_C( 13747), -INT16_C( 10502),  INT16_C(  7743), -INT16_C( 15750), -INT16_C(  7980), -INT16_C( 15261) },
      { -INT16_C(   599), -INT16_C(  4171), -INT16_C(  3006),  INT16_C(  2297), -INT16_C(  1693),  INT16_C(  3444),  INT16_C(  1745),  INT16_C(  3337) },
      { -INT16_C(  3173), -INT16_C( 22113), -INT16_C( 15937),  INT16_C( 12175), -INT16_C(  8976),  INT16_C( 18259),  INT16_C(  9252),  INT16_C( 17692) } },
    { { -INT16_C(  9996), -INT16_C( 23850), -INT16_C(  3050),  INT16_C( 25970), -INT16_C( 24041), -INT16_C( 19427), -INT16_C( 30595),  INT16_C(   623) },
      {  INT16_C( 11200),  INT16_C(  7559), -INT16_C( 11240),  INT16_C( 27535),  INT16_C( 14529), -INT16_C( 14632), -INT16_C( 18400),  INT16_C(  5190) },
      { -INT16_C(  3417), -INT16_C(  8152), -INT16_C(  1042),  INT16_C(  8876), -INT16_C(  8217), -INT16_C(  6640), -INT16_C( 10457),  INT16_C(   213) },
      { -INT16_C(  2306), -INT16_C(  5502), -INT16_C(   704),  INT16_C(  5991), -INT16_C(  5546), -INT16_C(  4481), -INT16_C(  7058),  INT16_C(   144) },
      {  INT16_C(  3429),  INT16_C(  8181),  INT16_C(  1046), -INT16_C(  8908),  INT16_C(  8246),  INT16_C(  6664),  INT16_C( 10495), -INT16_C(   214) },
      { -INT16_C(  8400), -INT16_C( 20041), -INT16_C(  2563),  INT16_C( 21823), -INT16_C( 20202), -INT16_C( 16325), -INT16_C( 25709),  INT16_C(   524) },
      { -INT16_C(  4432), -INT16_C( 10575), -INT16_C(  1352),  INT16_C( 11515), -INT16_C( 10660), -INT16_C(  8614), -INT16_C( 13566),  INT16_C(   276) },
      {  INT16_C(  4464),  INT16_C( 10650),  INT16_C(  1362), -INT16_C( 11596),  INT16_C( 10735),  INT16_C(  8675),  INT16_C( 13662), -INT16_C(   278) },
      {  INT16_C(  5613),  INT16_C( 13392),  INT16_C(  1713), -INT16_C( 14583),  INT16_C( 13500),  INT16_C( 10909),  INT16_C( 17180), -INT16_C(   350) },
      { -INT16_C(  1583), -INT16_C(  3778), -INT16_C(   483),  INT16_C(  4113), -INT16_C(  3808), -INT16_C(  3077), -INT16_C(  4846),  INT16_C(    99) } },
    { {  INT16_C(  7312), -INT16_C( 22601),  INT16_C( 10513),  INT16_C( 10252),  INT16_C( 10700),  INT16_C( 18909),  INT16_C( 19633),  INT16_C( 29003) },
      { -INT16_C( 11657), -INT16_C( 28786),  INT16_C(  7590),  INT16_C( 26619), -INT16_C( 11434),  INT16_C( 30253),  INT16_C( 29579),  INT16_C(  7307) },
      { -INT16_C(  2601),  INT16_C(  8040), -INT16_C(  3740), -INT16_C(  3647), -INT16_C(  3806), -INT16_C(  6727), -INT16_C(  6984), -INT16_C( 10318) },
      { -INT16_C(  6423),  INT16_C( 19855), -INT16_C(  9235), -INT16_C(  9006), -INT16_C(  9400), -INT16_C( 16611), -INT16_C( 17247), -INT16_C( 25479) },
      {  INT16_C(  1694), -INT16_C(  5235),  INT16_C(  2435),  INT16_C(  2375),  INT16_C(  2478),  INT16_C(  4380),  INT16_C(  4548),  INT16_C(  6718) },
      {  INT16_C(  5940), -INT16_C( 18360),  INT16_C(  8540),  INT16_C(  8328),  INT16_C(  8692),  INT16_C( 15361),  INT16_C( 15949),  INT16_C( 23561) },
      { -INT16_C(  2551),  INT16_C(  7886), -INT16_C(  3668), -INT16_C(  3577), -INT16_C(  3734), -INT16_C(  6598), -INT16_C(  6851), -INT16_C( 10120) },
      {  INT16_C(  6751), -INT16_C( 20866),  INT16_C(  9706),  INT16_C(  9465),  INT16_C(  9879),  INT16_C( 17458),  INT16_C( 18126),  INT16_C( 26777) },
      {  INT16_C(  6600), -INT16_C( 20401),  INT16_C(  9490),  INT16_C(  9254),  INT16_C(  9659),  INT16_C( 17069),  INT16_C( 17722),  INT16_C( 26180) },
      {  INT16_C(  1631), -INT16_C(  5040),  INT16_C(  2344),  INT16_C(  2286),  INT16_C(  2386),  INT16_C(  4217),  INT16_C(  4378),  INT16_C(  6467) } },
    { {  INT16_C( 17040), -INT16_C( 24125), -INT16_C( 12437),  INT16_C( 14281), -INT16_C( 22792), -INT16_C( 22143), -INT16_C( 13070),  INT16_C( 26906) },
      { -INT16_C( 22113),  INT16_C( 17913), -INT16_C(  2874),  INT16_C(  7341), -INT16_C(  9529),  INT16_C( 21395),  INT16_C(  7758), -INT16_C(  8593) },
      { -INT16_C( 11499),  INT16_C( 16280),  INT16_C(  8393), -INT16_C(  9637),  INT16_C( 15381),  INT16_C( 14943),  INT16_C(  8820), -INT16_C( 18157) },
      {  INT16_C(  9315), -INT16_C( 13188), -INT16_C(  6799),  INT16_C(  7807), -INT16_C( 12460), -INT16_C( 12105), -INT16_C(  7145),  INT16_C( 14708) },
      { -INT16_C(  1495),  INT16_C(  2116),  INT16_C(  1091), -INT16_C(  1253),  INT16_C(  1999),  INT16_C(  1942),  INT16_C(  1146), -INT16_C(  2360) },
      {  INT16_C(  3817), -INT16_C(  5405), -INT16_C(  2786),  INT16_C(  3199), -INT16_C(  5106), -INT16_C(  4961), -INT16_C(  2928),  INT16_C(  6028) },
      { -INT16_C(  4955),  INT16_C(  7016),  INT16_C(  3617), -INT16_C(  4153),  INT16_C(  6628),  INT16_C(  6439),  INT16_C(  3801), -INT16_C(  7824) },
      {  INT16_C( 11126), -INT16_C( 15752), -INT16_C(  8120),  INT16_C(  9324), -INT16_C( 14881), -INT16_C( 14458), -INT16_C(  8534),  INT16_C( 17568) },
      {  INT16_C(  4034), -INT16_C(  5712), -INT16_C(  2945),  INT16_C(  3381), -INT16_C(  5396), -INT16_C(  5242), -INT16_C(  3094),  INT16_C(  6370) },
      { -INT16_C(  4469),  INT16_C(  6326),  INT16_C(  3261), -INT16_C(  3745),  INT16_C(  5977),  INT16_C(  5807),  INT16_C(  3427), -INT16_C(  7056) } },
    { {  INT16_C( 12896), -INT16_C( 13441),  INT16_C( 18433), -INT16_C(  1789), -INT16_C( 31505), -INT16_C(  7774), -INT16_C( 17328), -INT16_C(  4277) },
      {  INT16_C( 17509),  INT16_C( 11317), -INT16_C(  7624), -INT16_C(   184), -INT16_C(  9284),  INT16_C(  2642), -INT16_C( 15879),  INT16_C( 23016) },
      {  INT16_C(  6891), -INT16_C(  7182),  INT16_C(  9849), -INT16_C(   956), -INT16_C( 16834), -INT16_C(  4154), -INT16_C(  9259), -INT16_C(  2285) },
      {  INT16_C(  4454), -INT16_C(  4642),  INT16_C(  6366), -INT16_C(   618), -INT16_C( 10881), -INT16_C(  2685), -INT16_C(  5985), -INT16_C(  1477) },
      { -INT16_C(  3000),  INT16_C(  3127), -INT16_C(  4289),  INT16_C(   416),  INT16_C(  7330),  INT16_C(  1809),  INT16_C(  4032),  INT16_C(   995) },
      { -INT16_C(    72),  INT16_C(    75), -INT16_C(   104),  INT16_C(    10),  INT16_C(   177),  INT16_C(    44),  INT16_C(    97),  INT16_C(    24) },
      { -INT16_C(  3654),  INT16_C(  3808), -INT16_C(  5223),  INT16_C(   507),  INT16_C(  8926),  INT16_C(  2203),  INT16_C(  4909),  INT16_C(  1212) },
      {  INT16_C(  1040), -INT16_C(  1084),  INT16_C(  1486), -INT16_C(   144), -INT16_C(  2540), -INT16_C(   627), -INT16_C(  1397), -INT16_C(   345) },
      { -INT16_C(  6249),  INT16_C(  6513), -INT16_C(  8932),  INT16_C(   867),  INT16_C( 15267),  INT16_C(  3767),  INT16_C(  8397),  INT16_C(  2073) },
      {  INT16_C(  9058), -INT16_C(  9441),  INT16_C( 12947), -INT16_C(  1257), -INT16_C( 22129), -INT16_C(  5460), -INT16_C( 12171), -INT16_C(  3004) } },
    { {  INT16_C( 26611), -INT16_C(  3035),  INT16_C( 10416), -INT16_C( 24595), -INT16_C( 28756), -INT16_C(   896), -INT16_C( 13492), -INT16_C( 19988) },
      {  INT16_C(  8463),  INT16_C( 18397),  INT16_C(  9731), -INT16_C( 16569), -INT16_C( 26367), -INT16_C(  1078), -INT16_C( 19877),  INT16_C( 20052) },
      {  INT16_C(  6873), -INT16_C(   784),  INT16_C(  2690), -INT16_C(  6352), -INT16_C(  7427), -INT16_C(   231), -INT16_C(  3485), -INT16_C(  5162) },
      {  INT16_C( 14940), -INT16_C(  1704),  INT16_C(  5848), -INT16_C( 13808), -INT16_C( 16145), -INT16_C(   503), -INT16_C(  7575), -INT16_C( 11222) },
      {  INT16_C(  7903), -INT16_C(   901),  INT16_C(  3093), -INT16_C(  7304), -INT16_C(  8540), -INT16_C(   266), -INT16_C(  4007), -INT16_C(  5936) },
      { -INT16_C( 13456),  INT16_C(  1535), -INT16_C(  5267),  INT16_C( 12436),  INT16_C( 14540),  INT16_C(   453),  INT16_C(  6822),  INT16_C( 10107) },
      { -INT16_C( 21413),  INT16_C(  2442), -INT16_C(  8381),  INT16_C( 19791),  INT16_C( 23139),  INT16_C(   721),  INT16_C( 10856),  INT16_C( 16083) },
      { -INT16_C(   875),  INT16_C(   100), -INT16_C(   343),  INT16_C(   809),  INT16_C(   946),  INT16_C(    29),  INT16_C(   444),  INT16_C(   658) },
      { -INT16_C( 16142),  INT16_C(  1841), -INT16_C(  6318),  INT16_C( 14919),  INT16_C( 17443),  INT16_C(   544),  INT16_C(  8184),  INT16_C( 12125) },
      {  INT16_C( 16284), -INT16_C(  1857),  INT16_C(  6374), -INT16_C( 15051), -INT16_C( 17597), -INT16_C(   548), -INT16_C(  8256), -INT16_C( 12231) } }
  };

  simde_int16x8_t a, v, r;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s16(test_vec[i].a);
    v = simde_vld1q_s16(test_vec[i].v);

    r = simde_vqrdmulhq_laneq_s16(a, v, 0);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r0));

    r = simde_vqrdmulhq_laneq_s16(a, v, 1);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r1));

    r = simde_vqrdmulhq_laneq_s16(a, v, 2);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r2));

    r = simde_vqrdmulhq_laneq_s16(a, v, 3);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r3));

    r = simde_vqrdmulhq_laneq_s16(a, v, 4);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r4));

    r = simde_vqrdmulhq_laneq_s16(a, v, 5);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r5));

    r = simde_vqrdmulhq_laneq_s16(a, v, 6);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r6));

    r = simde_vqrdmulhq_laneq_s16(a, v, 7);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r7));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r;

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 8 ; j++) {
      SIMDE_CONSTIFY_8_(simde_vqrdmulhq_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(0)), j, a, v);
      simde_test_arm_neon_write_i16x8(2, r, (j == 7) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a[4];
    int32_t  v[4];
    int32_t r0[4];
    int32_t r1[4];
    int32_t r2[4];
    int32_t r3[4];
  } test_vec[] = {
    { {  INT32_C(   633958153), -INT32_C(  2111375543), -INT32_C(   523839107),  INT32_C(     1089846) },
      {  INT32_C(  1554865778), -INT32_C(  1003238821), -INT32_C(  1500578880), -INT32_C(   742250550) },
      {  INT32_C(   459011568), -INT32_C(  1528722037), -INT32_C(   379280886),  INT32_C(      789093) },
      { -INT32_C(   296165901),  INT32_C(   986370216),  INT32_C(   244721644), -INT32_C(      509143) },
      { -INT32_C(   442985545),  INT32_C(  1475347927),  INT32_C(   366038596), -INT32_C(      761542) },
      { -INT32_C(   219119614),  INT32_C(   729770240),  INT32_C(   181058359), -INT32_C(      376691) } },
    { { -INT32_C(   537293674),  INT32_C(     6430595),  INT32_C(   803219705),  INT32_C(  1009774793) },
      { -INT32_C(  1432822706),  INT32_C(  1735314343), -INT32_C(  1861288762), -INT32_C(  1167798237) },
      {  INT32_C(   358487748), -INT32_C(     4290558), -INT32_C(   535916272), -INT32_C(   673731906) },
      { -INT32_C(   434170206),  INT32_C(     5196363),  INT32_C(   649056712),  INT32_C(   815967415) },
      {  INT32_C(   465688611), -INT32_C(     5573590), -INT32_C(   696174712), -INT32_C(   875202228) },
      {  INT32_C(   292179457), -INT32_C(     3496947), -INT32_C(   436789615), -INT32_C(   549113947) } },
    { { -INT32_C(   543597220),  INT32_C(  1994390397), -INT32_C(   307904733), -INT32_C(    30813008) },
      {  INT32_C(  1470677424),  INT32_C(  1405032333),  INT32_C(   937741587), -INT32_C(    84850275) },
      { -INT32_C(   372275784),  INT32_C(  1365833418), -INT32_C(   210864721), -INT32_C(    21101905) },
      { -INT32_C(   355658899),  INT32_C(  1304868140), -INT32_C(   201452573), -INT32_C(    20160001) },
      { -INT32_C(   237372573),  INT32_C(   870890364), -INT32_C(   134452746), -INT32_C(    13455115) },
      {  INT32_C(    21478335), -INT32_C(    78801333),  INT32_C(    12165774),  INT32_C(     1217468) } },
    { {  INT32_C(   601459366), -INT32_C(  1449543290),  INT32_C(   680935032), -INT32_C(  1020805358) },
      {  INT32_C(   236638081), -INT32_C(    94250522),  INT32_C(  1144080038),  INT32_C(   893264527) },
      {  INT32_C(    66276728), -INT32_C(   159729804),  INT32_C(    75034406), -INT32_C(   112485802) },
      { -INT32_C(    26397341),  INT32_C(    63618744), -INT32_C(    29885435),  INT32_C(    44801942) },
      {  INT32_C(   320429753), -INT32_C(   772249672),  INT32_C(   362770714), -INT32_C(   543837916) },
      {  INT32_C(   250182262), -INT32_C(   602950156),  INT32_C(   283240857), -INT32_C(   424612879) } },
    { {  INT32_C(   844699564),  INT32_C(  1239216848),  INT32_C(  1131508273), -INT32_C(  1291413454) },
      {  INT32_C(  1321279848), -INT32_C(  1589107974), -INT32_C(   135956120),  INT32_C(  1210917787) },
      {  INT32_C(   519717350),  INT32_C(   762451556),  INT32_C(   696181822), -INT32_C(   794566503) },
      { -INT32_C(   625065906), -INT32_C(   917003199), -INT32_C(   837300354),  INT32_C(   955627960) },
      { -INT32_C(    53477509), -INT32_C(    78454201), -INT32_C(    71635225),  INT32_C(    81758742) },
      {  INT32_C(   476307108),  INT32_C(   698766542),  INT32_C(   638032096), -INT32_C(   728199036) } },
    { {  INT32_C(   192579130), -INT32_C(  1454090632), -INT32_C(    68303415), -INT32_C(   961612962) },
      {  INT32_C(   252997396), -INT32_C(    89105007),  INT32_C(  1928435158), -INT32_C(   222683464) },
      {  INT32_C(    22687958), -INT32_C(   171308007), -INT32_C(     8046900), -INT32_C(   113288674) },
      { -INT32_C(     7990638),  INT32_C(    60334222),  INT32_C(     2834097),  INT32_C(    39899968) },
      {  INT32_C(   172935596), -INT32_C(  1305769895), -INT32_C(    61336303), -INT32_C(   863526130) },
      { -INT32_C(    19969506),  INT32_C(   150782028),  INT32_C(     7082727),  INT32_C(    99714522) } },
    { {  INT32_C(   503133348),  INT32_C(  1422283147),  INT32_C(  1968157463), -INT32_C(  1153696345) },
      { -INT32_C(    37073044), -INT32_C(  2080933204), -INT32_C(   940185329), -INT32_C(  1397051641) },
      { -INT32_C(     8685833), -INT32_C(    24553559), -INT32_C(    33977250),  INT32_C(    19916815) },
      { -INT32_C(   487541263), -INT32_C(  1378206641), -INT32_C(  1907164331),  INT32_C(  1117943335) },
      { -INT32_C(   220275760), -INT32_C(   622686813), -INT32_C(   861674907),  INT32_C(   505097386) },
      { -INT32_C(   327314841), -INT32_C(   925270377), -INT32_C(  1280390477),  INT32_C(   750540463) } },
    { {  INT32_C(  1858713571),  INT32_C(   549621513), -INT32_C(   359329469),  INT32_C(  2057687054) },
      { -INT32_C(   864522209), -INT32_C(    95457302),  INT32_C(  1623278680), -INT32_C(   703824909) },
      { -INT32_C(   748270732), -INT32_C(   221263619),  INT32_C(   144656890), -INT32_C(   828372388) },
      { -INT32_C(    82621250), -INT32_C(    24431100),  INT32_C(    15972472), -INT32_C(    91465774) },
      {  INT32_C(  1404997945),  INT32_C(   415457824), -INT32_C(   271616441),  INT32_C(  1555401611) },
      { -INT32_C(   609182245), -INT32_C(   180135160),  INT32_C(   117768082), -INT32_C(   674394613) } }
  };

  simde_int32x4_t a, v, r;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s32(test_vec[i].a);
    v = simde_vld1q_s32(test_vec[i].v);

    r = simde_vqrdmulhq_laneq_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r0));

    r = simde_vqrdmulhq_laneq_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r1));

    r = simde_vqrdmulhq_laneq_s32(a, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r2));

    r = simde_vqrdmulhq_laneq_s32(a, v, 3);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r3));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r;

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 4 ; j++) {
      SIMDE_CONSTIFY_4_(simde_vqrdmulhq_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), j, a, v);
      simde_test_arm_neon_write_i32x4(2, r, (j == 3) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
