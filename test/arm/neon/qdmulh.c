#define SIMDE_TEST_ARM_NEON_INSN qdmulh

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmulh.h"

static int
test_simde_vqdmulh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 10007),  INT16_C( 28883), -INT16_C( 16203), -INT16_C( 25505) },
      { -INT16_C( 28965), -INT16_C(   965), -INT16_C( 21451), -INT16_C( 19467) },
      { -INT16_C(  8846), -INT16_C(   851),  INT16_C( 10607),  INT16_C( 15152) } },
    { {  INT16_C(   297), -INT16_C( 28727),  INT16_C( 26792),  INT16_C( 21146) },
      { -INT16_C(  2097),  INT16_C( 13945),  INT16_C(  6034), -INT16_C( 22205) },
      { -INT16_C(    20), -INT16_C( 12226),  INT16_C(  4933), -INT16_C( 14330) } },
    { {  INT16_C(  5694), -INT16_C(  3302),  INT16_C( 31190), -INT16_C( 20080) },
      { -INT16_C( 13560),  INT16_C( 15789), -INT16_C( 23944), -INT16_C( 24080) },
      { -INT16_C(  2357), -INT16_C(  1592), -INT16_C( 22791),  INT16_C( 14756) } },
    { { -INT16_C( 17757),  INT16_C( 19504), -INT16_C( 13790), -INT16_C(  3682) },
      {  INT16_C(  6337),  INT16_C( 21287),  INT16_C( 27183),  INT16_C( 28413) },
      { -INT16_C(  3435),  INT16_C( 12670), -INT16_C( 11440), -INT16_C(  3193) } },
    { {  INT16_C(  6017),  INT16_C( 22369), -INT16_C(  3696), -INT16_C( 26615) },
      { -INT16_C( 18755),  INT16_C( 13781), -INT16_C( 14759), -INT16_C(   810) },
      { -INT16_C(  3444),  INT16_C(  9407),  INT16_C(  1664),  INT16_C(   657) } },
    { {  INT16_C(  1664), -INT16_C( 23992), -INT16_C(  6191), -INT16_C( 28013) },
      { -INT16_C( 17665),  INT16_C( 12006), -INT16_C(  7388), -INT16_C( 23140) },
      { -INT16_C(   898), -INT16_C(  8791),  INT16_C(  1395),  INT16_C( 19782) } },
    { { -INT16_C(   262), -INT16_C( 29955),  INT16_C(  1775), -INT16_C( 21469) },
      { -INT16_C(  1860),  INT16_C(  5601), -INT16_C( 18498),  INT16_C( 15890) },
      {  INT16_C(    14), -INT16_C(  5121), -INT16_C(  1003), -INT16_C( 10411) } },
    { {  INT16_C( 23230), -INT16_C( 28704),  INT16_C( 29505),  INT16_C( 16417) },
      {  INT16_C(  1837),  INT16_C( 21103),  INT16_C(  3050), -INT16_C(  6921) },
      {  INT16_C(  1302), -INT16_C( 18486),  INT16_C(  2746), -INT16_C(  3468) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vqdmulh_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vqdmulh_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulh_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1569407431),  INT32_C(  1412891023) },
      {  INT32_C(   132938559), -INT32_C(   247554225) },
      {  INT32_C(    97153132), -INT32_C(   162873018) } },
    { {  INT32_C(  2121161384),  INT32_C(  1882235674) },
      {  INT32_C(  1466757416),  INT32_C(  1199108991) },
      {  INT32_C(  1448778989),  INT32_C(  1051000188) } },
    { { -INT32_C(   995884235),  INT32_C(  1125767940) },
      { -INT32_C(  1505098410),  INT32_C(  1284999588) },
      {  INT32_C(   697981463),  INT32_C(   673630898) } },
    { { -INT32_C(    37026077), -INT32_C(   781321303) },
      {  INT32_C(  1797839340),  INT32_C(    45261005) },
      { -INT32_C(    30997646), -INT32_C(    16467361) } },
    { { -INT32_C(  1463396444), -INT32_C(  1980965070) },
      { -INT32_C(  1993394460), -INT32_C(  1563048257) },
      {  INT32_C(  1358392818),  INT32_C(  1441847532) } },
    { {  INT32_C(  1973395660), -INT32_C(  2025386853) },
      { -INT32_C(  1275891738), -INT32_C(  1263164144) },
      { -INT32_C(  1172460252),  INT32_C(  1191345998) } },
    { {  INT32_C(   794590204),  INT32_C(  1069041755) },
      {  INT32_C(  1053353855),  INT32_C(  2061606573) },
      {  INT32_C(   389751351),  INT32_C(  1026291171) } },
    { { -INT32_C(   621838274),  INT32_C(  1935750797) },
      { -INT32_C(  1239001946), -INT32_C(   160769030) },
      {  INT32_C(   358772851), -INT32_C(   144917881) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vqdmulh_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vqdmulh_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulhq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 18403),  INT16_C( 14972), -INT16_C( 24285),  INT16_C( 10702), -INT16_C( 30041), -INT16_C(  5908), -INT16_C( 31444),  INT16_C( 30183) },
      { -INT16_C(  6237),  INT16_C(  3774),  INT16_C(  8878), -INT16_C( 15805), -INT16_C( 14743),  INT16_C( 22060),  INT16_C( 15220),  INT16_C( 22311) },
      { -INT16_C(  3503),  INT16_C(  1724), -INT16_C(  6580), -INT16_C(  5162),  INT16_C( 13516), -INT16_C(  3978), -INT16_C( 14606),  INT16_C( 20550) } },
    { { -INT16_C( 23678), -INT16_C( 23150),  INT16_C( 24645), -INT16_C(  4914), -INT16_C( 17686),  INT16_C(  6101), -INT16_C( 17344), -INT16_C(  7284) },
      {  INT16_C( 19107),  INT16_C( 21233),  INT16_C( 13677), -INT16_C( 10732),  INT16_C( 16635),  INT16_C( 28460),  INT16_C( 21627), -INT16_C(   313) },
      { -INT16_C( 13807), -INT16_C( 15001),  INT16_C( 10286),  INT16_C(  1609), -INT16_C(  8979),  INT16_C(  5298), -INT16_C( 11448),  INT16_C(    69) } },
    { {  INT16_C( 23031),  INT16_C( 15523),  INT16_C( 29369), -INT16_C( 23767), -INT16_C(   468),  INT16_C( 27834),  INT16_C( 18106),  INT16_C( 24144) },
      {  INT16_C( 16785), -INT16_C(   336), -INT16_C( 15242),  INT16_C( 29396),  INT16_C(     5), -INT16_C( 32543), -INT16_C( 22444),  INT16_C( 19582) },
      {  INT16_C( 11797), -INT16_C(   160), -INT16_C( 13661), -INT16_C( 21322), -INT16_C(     1), -INT16_C( 27643), -INT16_C( 12402),  INT16_C( 14428) } },
    { {  INT16_C(  8705), -INT16_C( 17784), -INT16_C( 20076), -INT16_C( 16290),  INT16_C(  6319),  INT16_C( 27181),  INT16_C( 32095), -INT16_C(  3896) },
      {  INT16_C( 30910),  INT16_C( 13806), -INT16_C( 15812),  INT16_C( 16807), -INT16_C( 30526),  INT16_C(  6082),  INT16_C( 16433),  INT16_C( 12899) },
      {  INT16_C(  8211), -INT16_C(  7493),  INT16_C(  9687), -INT16_C(  8356), -INT16_C(  5887),  INT16_C(  5045),  INT16_C( 16095), -INT16_C(  1534) } },
    { { -INT16_C(  5278), -INT16_C(  2323),  INT16_C( 19357),  INT16_C( 19639), -INT16_C(  7069), -INT16_C( 15690),  INT16_C( 32353),  INT16_C(  8114) },
      { -INT16_C( 24330),  INT16_C( 13140), -INT16_C(  1182),  INT16_C(  9588),  INT16_C( 13956), -INT16_C( 19140), -INT16_C( 24713), -INT16_C(  9753) },
      {  INT16_C(  3918), -INT16_C(   932), -INT16_C(   699),  INT16_C(  5746), -INT16_C(  3011),  INT16_C(  9164), -INT16_C( 24401), -INT16_C(  2416) } },
    { { -INT16_C( 11126),  INT16_C( 10192), -INT16_C( 30945), -INT16_C( 31884),  INT16_C( 10859), -INT16_C( 13243), -INT16_C(  1879), -INT16_C( 24597) },
      {  INT16_C( 16536), -INT16_C(  1070),  INT16_C( 18235), -INT16_C( 16608),  INT16_C( 23677), -INT16_C(  2956),  INT16_C( 23803), -INT16_C( 31282) },
      { -INT16_C(  5615), -INT16_C(   333), -INT16_C( 17221),  INT16_C( 16159),  INT16_C(  7846),  INT16_C(  1194), -INT16_C(  1365),  INT16_C( 23481) } },
    { { -INT16_C( 25040),  INT16_C( 20653),  INT16_C(  8485), -INT16_C( 28461),  INT16_C(  6219), -INT16_C(  2980),  INT16_C( 18192), -INT16_C( 22124) },
      {  INT16_C( 26247), -INT16_C( 15452), -INT16_C( 15187),  INT16_C( 11138), -INT16_C(  2272),  INT16_C(  6943), -INT16_C(  4781), -INT16_C( 31840) },
      { -INT16_C( 20057), -INT16_C(  9740), -INT16_C(  3933), -INT16_C(  9675), -INT16_C(   432), -INT16_C(   632), -INT16_C(  2655),  INT16_C( 21497) } },
    { {  INT16_C( 19851), -INT16_C( 20269), -INT16_C( 22930), -INT16_C( 17856), -INT16_C( 25409), -INT16_C( 12370),  INT16_C( 17124),  INT16_C( 27512) },
      {  INT16_C(  7337),  INT16_C( 22062), -INT16_C( 20000),  INT16_C(   129), -INT16_C( 24152), -INT16_C(  1253), -INT16_C( 17266),  INT16_C(  6782) },
      {  INT16_C(  4444), -INT16_C( 13647),  INT16_C( 13995), -INT16_C(    71),  INT16_C( 18727),  INT16_C(   473), -INT16_C(  9023),  INT16_C(  5694) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vqdmulhq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vqdmulhq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulhq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   500379413), -INT32_C(    31083559),  INT32_C(  1368591925),  INT32_C(  2052497007) },
      { -INT32_C(   841622730),  INT32_C(  1100873920),  INT32_C(  1914938471),  INT32_C(  1872022618) },
      { -INT32_C(   196104259), -INT32_C(    15934501),  INT32_C(  1220390819),  INT32_C(  1789220059) } },
    { { -INT32_C(   728995845),  INT32_C(  1339273754),  INT32_C(   799041216),  INT32_C(   984217348) },
      { -INT32_C(  1845002542), -INT32_C(   422271618), -INT32_C(  1537673399), -INT32_C(  1089213245) },
      {  INT32_C(   626314052), -INT32_C(   263348825), -INT32_C(   572141457), -INT32_C(   499199411) } },
    { {  INT32_C(  1855168596),  INT32_C(   314467922), -INT32_C(   801022260),  INT32_C(   671803989) },
      { -INT32_C(   424013464),  INT32_C(    13405879),  INT32_C(  1235494278),  INT32_C(  1695070225) },
      { -INT32_C(   366296835),  INT32_C(     1963097), -INT32_C(   460845614),  INT32_C(   530274090) } },
    { { -INT32_C(  1428906920), -INT32_C(   809725438),  INT32_C(  1184890352),  INT32_C(  1332652775) },
      {  INT32_C(  1916086459),  INT32_C(  1030947511),  INT32_C(   948311847),  INT32_C(   664702927) },
      { -INT32_C(  1274938323), -INT32_C(   388726790),  INT32_C(   523238237),  INT32_C(   412491243) } },
    { {  INT32_C(   768700971), -INT32_C(   184775420),  INT32_C(  1899666570),  INT32_C(    29403206) },
      { -INT32_C(  2005600559),  INT32_C(   533063672), -INT32_C(   833139714),  INT32_C(   100005338) },
      { -INT32_C(   717913312), -INT32_C(    45866270), -INT32_C(   736996375),  INT32_C(     1369266) } },
    { {  INT32_C(  1798555495), -INT32_C(   547344556),  INT32_C(   290495179),  INT32_C(   336793923) },
      { -INT32_C(     6519033),  INT32_C(  1813930350), -INT32_C(  2026211924), -INT32_C(   762564501) },
      { -INT32_C(     5459806), -INT32_C(   462329436), -INT32_C(   274090467), -INT32_C(   119594434) } },
    { {  INT32_C(  1262403575), -INT32_C(  1171611921),  INT32_C(  2076998456), -INT32_C(  1819287668) },
      { -INT32_C(   728618138),  INT32_C(   960540812), -INT32_C(  1866433755), -INT32_C(  1570550613) },
      { -INT32_C(   428319975), -INT32_C(   524046396), -INT32_C(  1805173246),  INT32_C(  1330526248) } },
    { { -INT32_C(    68312820),  INT32_C(  2008356927),  INT32_C(   536052115), -INT32_C(   961379744) },
      {  INT32_C(   983188654),  INT32_C(   427023348),  INT32_C(    27931478), -INT32_C(  1935471232) },
      { -INT32_C(    31275857),  INT32_C(   399358244),  INT32_C(     6972219),  INT32_C(   866466591) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vqdmulhq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vqdmulhq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulh_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
