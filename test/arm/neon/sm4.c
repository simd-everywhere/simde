#define SIMDE_TEST_ARM_NEON_INSN sm4

#include "test-neon.h"
#include "../../../simde/arm/neon/sm4.h"

static int
test_simde_vsm4eq_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(    86366698),  UINT32_C(  1548487039),  UINT32_C(  2482162735),  UINT32_C(  1772303343) },
      {  UINT32_C(  1203461642),  UINT32_C(  2459321482),  UINT32_C(   391167851),  UINT32_C(  1428154879) },
      {  UINT32_C(   509313710),  UINT32_C(  1124462804),  UINT32_C(   656045141),  UINT32_C(  3063762159) } },
    { {  UINT32_C(   857837190),  UINT32_C(  1568809189),  UINT32_C(   842834539),  UINT32_C(  1645287943) },
      {  UINT32_C(   592622053),  UINT32_C(  2359696962),  UINT32_C(   932246979),  UINT32_C(  3998256510) },
      {  UINT32_C(  1346237515),  UINT32_C(   631877507),  UINT32_C(  2000644790),  UINT32_C(   738177290) } },
    { {  UINT32_C(  1380346229),  UINT32_C(  3264665020),  UINT32_C(  1610204751),  UINT32_C(   719937573) },
      {  UINT32_C(    93710264),  UINT32_C(  1622912996),  UINT32_C(   498309356),  UINT32_C(  1345614832) },
      {  UINT32_C(  2001785969),  UINT32_C(  3538453490),  UINT32_C(  2837644742),  UINT32_C(  3501552147) } },
    { {  UINT32_C(   144109503),  UINT32_C(  2341151744),  UINT32_C(  1025270546),  UINT32_C(  1859744721) },
      {  UINT32_C(  3232298688),  UINT32_C(  1966050236),  UINT32_C(  3019530288),  UINT32_C(  3102939798) },
      {  UINT32_C(  2496715619),  UINT32_C(  1732251813),  UINT32_C(  4223591690),  UINT32_C(  1348801512) } },
    { {  UINT32_C(  2888161610),  UINT32_C(   839388553),  UINT32_C(  1549201654),  UINT32_C(  2531992107) },
      {  UINT32_C(  3315742789),  UINT32_C(   216182861),  UINT32_C(   275682140),  UINT32_C(  3576948947) },
      {  UINT32_C(  2399354111),  UINT32_C(  1032384041),  UINT32_C(  2376205840),  UINT32_C(  2255072658) } },
    { {  UINT32_C(  3690752223),  UINT32_C(  1884373718),  UINT32_C(  3910622108),  UINT32_C(  4285914198) },
      {  UINT32_C(  2194870060),  UINT32_C(   120405782),  UINT32_C(  3446079553),  UINT32_C(  2911082933) },
      {  UINT32_C(  1472163040),  UINT32_C(  3112035052),  UINT32_C(  3104943723),  UINT32_C(  3017281411) } },
    { {  UINT32_C(  3460766285),  UINT32_C(  1407696899),  UINT32_C(  4216699804),  UINT32_C(  2262558290) },
      {  UINT32_C(  2030464185),  UINT32_C(  2415450516),  UINT32_C(   455822124),  UINT32_C(  3275848660) },
      {  UINT32_C(   703135597),  UINT32_C(  3343455912),  UINT32_C(  3787618854),  UINT32_C(  2786553034) } },
    { {  UINT32_C(  2532557533),  UINT32_C(  1592830601),  UINT32_C(   687963275),  UINT32_C(  2612931049) },
      {  UINT32_C(  1667039368),  UINT32_C(  4054915640),  UINT32_C(     3371319),  UINT32_C(  2736881717) },
      {  UINT32_C(  2818231646),  UINT32_C(  1865888037),  UINT32_C(   595190562),  UINT32_C(  1246787794) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vsm4eq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsm4eq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsm4ekeyq_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  2603681902),  UINT32_C(  4215431196),  UINT32_C(  3661140891),  UINT32_C(  3848373209) },
      {  UINT32_C(  2821621143),  UINT32_C(  2186281507),  UINT32_C(  1606078044),  UINT32_C(  3502955013) },
      {  UINT32_C(  3978457336),  UINT32_C(  3144098304),  UINT32_C(  3469953573),  UINT32_C(  3845465293) } },
    { {  UINT32_C(  1720169669),  UINT32_C(  2766084569),  UINT32_C(  2184814235),  UINT32_C(  1017084676) },
      {  UINT32_C(  2106807416),  UINT32_C(  3161211580),  UINT32_C(   929426040),  UINT32_C(  2946889179) },
      {  UINT32_C(  3818977348),  UINT32_C(  2586042190),  UINT32_C(   107537213),  UINT32_C(   573394513) } },
    { {  UINT32_C(  2509856753),  UINT32_C(  1326477670),  UINT32_C(  1063528410),  UINT32_C(  1570487153) },
      {  UINT32_C(  2180590565),  UINT32_C(  1599898629),  UINT32_C(  3272342943),  UINT32_C(  2077001921) },
      {  UINT32_C(   379387964),  UINT32_C(  3620072585),  UINT32_C(  2340874914),  UINT32_C(   293016947) } },
    { {  UINT32_C(   478776218),  UINT32_C(  2393468111),  UINT32_C(  1913876004),  UINT32_C(  3710822006) },
      {  UINT32_C(  1952527019),  UINT32_C(  1995231047),  UINT32_C(  1788079730),  UINT32_C(  2270495816) },
      {  UINT32_C(  2403005412),  UINT32_C(   194202083),  UINT32_C(  1808946113),  UINT32_C(  2144516833) } },
    { {  UINT32_C(  2187936179),  UINT32_C(  2619070593),  UINT32_C(  4085280786),  UINT32_C(  2139725127) },
      {  UINT32_C(  4023301414),  UINT32_C(  2794684997),  UINT32_C(   258082378),  UINT32_C(   552407049) },
      {  UINT32_C(  3912916652),  UINT32_C(   245553014),  UINT32_C(   187362248),  UINT32_C(  3682042404) } },
    { {  UINT32_C(   753099971),  UINT32_C(  4041316476),  UINT32_C(   887137810),  UINT32_C(  2803335600) },
      {  UINT32_C(  3007783926),  UINT32_C(  1300461484),  UINT32_C(  1779468549),  UINT32_C(   391650568) },
      {  UINT32_C(  3249259847),  UINT32_C(  1125533449),  UINT32_C(  3717837912),  UINT32_C(  2945893091) } },
    { {  UINT32_C(  2895390672),  UINT32_C(  1774472389),  UINT32_C(  2236727807),  UINT32_C(  3941837209) },
      {  UINT32_C(   603195841),  UINT32_C(  1025253051),  UINT32_C(  1467993293),  UINT32_C(  1571703093) },
      {  UINT32_C(  2103417810),  UINT32_C(   618445370),  UINT32_C(  2176815595),  UINT32_C(  3826315629) } },
    { {  UINT32_C(   251193184),  UINT32_C(   511712506),  UINT32_C(  3532314488),  UINT32_C(  1269273948) },
      {  UINT32_C(  3625452113),  UINT32_C(  3333603222),  UINT32_C(  3365096135),  UINT32_C(  3768228210) },
      {  UINT32_C(  3314241478),  UINT32_C(  2780878907),  UINT32_C(  2697671355),  UINT32_C(  1573116589) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vsm4ekeyq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsm4ekeyq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsm4eq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsm4ekeyq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
