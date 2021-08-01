#define SIMDE_TEST_X86_AVX512_INSN dpwssds

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/dpwssds.h>

static int
test_simde_mm_dpwssds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const int16_t a[8];
    const int16_t b[8];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(    44669938), -INT32_C(   186191774),  INT32_C(  2147287265), -INT32_C(  1084410228) },
      { -INT16_C( 15155),  INT16_C( 10470), -INT16_C(  5074), -INT16_C( 16374),  INT16_C( 11150), -INT16_C(  3326),  INT16_C( 26984),  INT16_C( 23251) },
      {  INT16_C( 31748),  INT16_C( 26205),  INT16_C( 17261),  INT16_C( 20058),  INT16_C( 22339), -INT16_C( 12339),  INT16_C( 10894),  INT16_C( 23439) },
      { -INT32_C(   162104652), -INT32_C(   602203780),              INT32_MAX, -INT32_C(   245466343) } },
    { {  INT32_C(   478377454), -INT32_C(   253981342),  INT32_C(   568582073),  INT32_C(  1283241800) },
      { -INT16_C(  9933), -INT16_C( 24398),  INT16_C(  3356),  INT16_C( 24558), -INT16_C( 17564), -INT16_C(  3538), -INT16_C( 16923), -INT16_C( 11443) },
      { -INT16_C( 11981), -INT16_C( 27152), -INT16_C( 13218),  INT16_C(  6021),  INT16_C( 26795), -INT16_C(  3271), -INT16_C( 19169),  INT16_C( 21311) },
      {  INT32_C(  1259839223), -INT32_C(   150477232),  INT32_C(   109527491),  INT32_C(  1363777014) } },
    { { -INT32_C(  1426853234),  INT32_C(  1661592319), -INT32_C(  2091501667),  INT32_C(   676766709) },
      {  INT16_C( 18036), -INT16_C( 11331),  INT16_C( 16915), -INT16_C( 16662),  INT16_C(  9130), -INT16_C( 13646), -INT16_C(  3624),  INT16_C( 26141) },
      {  INT16_C(  4323), -INT16_C(  7664),  INT16_C(  6642), -INT16_C( 28602), -INT16_C( 25519),  INT16_C( 17939),  INT16_C( 26943), -INT16_C( 19346) },
      { -INT32_C(  1262042822),              INT32_MAX,              INT32_MIN,  INT32_C(    73401491) } },
    { { -INT32_C(  1014551632),  INT32_C(   394359149),  INT32_C(  1843475349),  INT32_C(   148176421) },
      { -INT16_C(  7153),  INT16_C(   491),  INT16_C( 12798),  INT16_C( 20369), -INT16_C( 23347),  INT16_C(  3221),  INT16_C(   782), -INT16_C( 16704) },
      {  INT16_C( 18222), -INT16_C( 25727),  INT16_C(   697),  INT16_C( 20146), -INT16_C( 27594),  INT16_C( 23483), -INT16_C( 28782), -INT16_C( 24221) },
      { -INT32_C(  1157525555),  INT32_C(   813633229),              INT32_MAX,  INT32_C(   530256481) } },
    { {  INT32_C(  1923305076),  INT32_C(  1287730303), -INT32_C(   413575463), -INT32_C(  2019223207) },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {              INT32_MAX,              INT32_MAX,  INT32_C(  1733777115),  INT32_C(   128129371) } },
    { {  INT32_C(   438445665),  INT32_C(  1583928360), -INT32_C(    71752856),  INT32_C(   664542643) },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {              INT32_MAX,              INT32_MAX,  INT32_C(  2075599722),              INT32_MAX } },
    { { -INT32_C(   342278293),  INT32_C(  1295473268),  INT32_C(   154439856),  INT32_C(   194042282) },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {              INT32_MIN, -INT32_C(   851944844), -INT32_C(  1992978256), -INT32_C(  1953375830) } },
    { {  INT32_C(   656782079), -INT32_C(   276394618),  INT32_C(  1676296112), -INT32_C(   930445732) },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      { -INT32_C(  1490636033),              INT32_MIN, -INT32_C(   471122000),              INT32_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_dpwssds_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 4 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_dpwssds_epi32(src, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 2 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__m128i a = simde_mm_set1_epi16(INT16_MAX);
    simde__m128i b = simde_mm_set1_epi16(INT16_MAX);
    simde__m128i r = simde_mm_dpwssds_epi32(src, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 2 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__m128i a = simde_mm_set1_epi16(INT16_MIN);
    simde__m128i b = simde_mm_set1_epi16(INT16_MAX);
    simde__m128i r = simde_mm_dpwssds_epi32(src, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_dpwssds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int16_t a[8];
    const int16_t b[8];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1729899697),  INT32_C(  1477593491), -INT32_C(  1300698913), -INT32_C(  1729893459) },
      UINT8_C(232),
      { -INT16_C( 15883), -INT16_C( 32739), -INT16_C( 17008),  INT16_C(  2580), -INT16_C( 26659),  INT16_C( 16059),  INT16_C(  8983), -INT16_C(  5235) },
      {  INT16_C(  9478),  INT16_C( 20606), -INT16_C( 10696),  INT16_C(  8239), -INT16_C(  7858),  INT16_C( 15053),  INT16_C( 26052), -INT16_C( 17886) },
      { -INT32_C(  1729899697),  INT32_C(  1477593491), -INT32_C(  1300698913), -INT32_C(  1402235133) } },
    { { -INT32_C(  1237696730), -INT32_C(   641708292), -INT32_C(    48792347), -INT32_C(  1494702945) },
      UINT8_C(202),
      { -INT16_C(  2458),  INT16_C( 15618),  INT16_C(  8741),  INT16_C(  1675), -INT16_C( 14865),  INT16_C( 21962), -INT16_C( 31512),  INT16_C( 10107) },
      {  INT16_C( 12991),  INT16_C(  3364), -INT16_C(   526),  INT16_C( 28403), -INT16_C(  4075), -INT16_C( 18162), -INT16_C( 19240),  INT16_C( 16003) },
      { -INT32_C(  1237696730), -INT32_C(   598731033), -INT32_C(    48792347), -INT32_C(   726669744) } },
    { { -INT32_C(   813988438), -INT32_C(  1747646553), -INT32_C(  1259561012), -INT32_C(   472094940) },
      UINT8_C(153),
      { -INT16_C(  4096), -INT16_C(   628), -INT16_C(  1309), -INT16_C( 11502), -INT16_C( 13304), -INT16_C( 17237), -INT16_C(  5553), -INT16_C( 10906) },
      {  INT16_C( 13669),  INT16_C( 27772),  INT16_C(  4874), -INT16_C( 21959), -INT16_C(  4609),  INT16_C( 26574), -INT16_C( 20023), -INT16_C( 14080) },
      { -INT32_C(   887417478), -INT32_C(  1747646553), -INT32_C(  1259561012), -INT32_C(   207350741) } },
    { { -INT32_C(  2050519903), -INT32_C(  1890002553), -INT32_C(   179567451),  INT32_C(  1405793006) },
      UINT8_C(232),
      { -INT16_C( 16314),  INT16_C( 23282), -INT16_C( 25351), -INT16_C(  6567), -INT16_C( 16278),  INT16_C(  7088),  INT16_C( 31169),  INT16_C( 19901) },
      {  INT16_C( 16960),  INT16_C(  6868),  INT16_C( 25754), -INT16_C( 24897), -INT16_C( 19280),  INT16_C( 25228), -INT16_C(  8066), -INT16_C( 15030) },
      { -INT32_C(  2050519903), -INT32_C(  1890002553), -INT32_C(   179567451),  INT32_C(   855271822) } },
    { { -INT32_C(  1726005856),  INT32_C(  1149204697), -INT32_C(    94425287), -INT32_C(   381215575) },
      UINT8_C( 94),
      {  INT16_C(   796), -INT16_C( 32519), -INT16_C( 26685),  INT16_C( 30512), -INT16_C( 28124),  INT16_C(  1270), -INT16_C( 17443),  INT16_C(  6820) },
      {  INT16_C( 15834),  INT16_C( 21235),  INT16_C( 14268), -INT16_C(  4981), -INT16_C( 31337), -INT16_C( 19563),  INT16_C( 32461), -INT16_C(  5870) },
      { -INT32_C(  1726005856),  INT32_C(   616482845),  INT32_C(   762051491), -INT32_C(   987466198) } },
    { {  INT32_C(  1164512130), -INT32_C(   960718430),  INT32_C(   147501611),  INT32_C(  1193438829) },
      UINT8_C(171),
      { -INT16_C( 26090),  INT16_C( 19816),  INT16_C( 21541), -INT16_C( 21532), -INT16_C( 26391),  INT16_C( 26488),  INT16_C( 25002), -INT16_C( 18967) },
      {  INT16_C( 11978),  INT16_C( 25431),  INT16_C(  7915), -INT16_C( 25202), -INT16_C( 26648),  INT16_C( 22283),  INT16_C( 21177), -INT16_C( 12542) },
      {  INT32_C(  1355946806), -INT32_C(   247571951),  INT32_C(   147501611),  INT32_C(  1960790297) } },
    { {  INT32_C(   303917804), -INT32_C(  1480785474),  INT32_C(  1125070233),  INT32_C(  1626929302) },
      UINT8_C( 39),
      { -INT16_C( 15536),  INT16_C( 28178), -INT16_C( 20655), -INT16_C(  6058), -INT16_C( 21062),  INT16_C(  3490),  INT16_C( 29104),  INT16_C(  6905) },
      {  INT16_C(  2958), -INT16_C( 28455), -INT16_C( 32568), -INT16_C(   727),  INT16_C( 28047), -INT16_C( 30573), -INT16_C(  3227), -INT16_C( 19025) },
      { -INT32_C(   543842674), -INT32_C(   803689268),  INT32_C(   427644549),  INT32_C(  1626929302) } },
    { {  INT32_C(   136561078),  INT32_C(   737180272), -INT32_C(   684158425), -INT32_C(  1829621500) },
      UINT8_C( 61),
      {  INT16_C(  8907),  INT16_C( 19205),  INT16_C(   844), -INT16_C( 17957),  INT16_C( 25494), -INT16_C( 30178), -INT16_C( 11246), -INT16_C( 11456) },
      {  INT16_C( 18679),  INT16_C( 28995),  INT16_C( 28217), -INT16_C( 13415),  INT16_C( 28838), -INT16_C( 10033),  INT16_C( 25186),  INT16_C( 11541) },
      {  INT32_C(   859783906),  INT32_C(   737180272),  INT32_C(   353813421),              INT32_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_mask_dpwssds_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_mask_dpwssds_epi32(src, k, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_dpwssds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t src[4];
    const int16_t a[8];
    const int16_t b[8];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C(132),
      {  INT32_C(   500201754), -INT32_C(  1212905132),  INT32_C(  2093563560), -INT32_C(   948724610) },
      { -INT16_C(  6689),  INT16_C( 19968), -INT16_C( 13442), -INT16_C(  4364), -INT16_C( 13157), -INT16_C(   687),  INT16_C( 32481), -INT16_C(   895) },
      {  INT16_C( 21239),  INT16_C( 19225), -INT16_C( 12837), -INT16_C( 31998), -INT16_C( 13557), -INT16_C( 29953),  INT16_C( 29543),  INT16_C( 18257) },
      {  INT32_C(           0),  INT32_C(           0),              INT32_MAX,  INT32_C(           0) } },
    { UINT8_C( 88),
      {  INT32_C(   483824977),  INT32_C(  1454883977), -INT32_C(  1808288747), -INT32_C(  2004143306) },
      { -INT16_C( 10419),  INT16_C(  6755), -INT16_C(  6183), -INT16_C( 23258), -INT16_C( 20250),  INT16_C( 22796),  INT16_C( 21249),  INT16_C( 21169) },
      { -INT16_C( 30744),  INT16_C( 29294),  INT16_C(  9804),  INT16_C( 25032), -INT16_C(    38),  INT16_C(  4341), -INT16_C( 32461), -INT16_C( 32616) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),              INT32_MIN } },
    { UINT8_C( 88),
      { -INT32_C(   483288324),  INT32_C(  1892275904),  INT32_C(   913384419),  INT32_C(  1545585620) },
      { -INT16_C( 28366),  INT16_C( 22696),  INT16_C(  2393),  INT16_C( 22578),  INT16_C( 17407), -INT16_C( 32629),  INT16_C(  3035), -INT16_C( 10280) },
      {  INT16_C(  2470),  INT16_C( 26298), -INT16_C( 31520), -INT16_C( 15401),  INT16_C( 18599),  INT16_C( 31737),  INT16_C(  6156),  INT16_C( 16087) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1398894720) } },
    { UINT8_C(169),
      { -INT32_C(  1996319105),  INT32_C(   193485768), -INT32_C(   219739930), -INT32_C(   375865632) },
      { -INT16_C(   391), -INT16_C(   567), -INT16_C( 29483),  INT16_C(  7844),  INT16_C(  8070), -INT16_C( 25046),  INT16_C( 26871),  INT16_C( 30280) },
      {  INT16_C( 19198), -INT16_C( 14593), -INT16_C( 30811), -INT16_C( 29486), -INT16_C( 18033),  INT16_C( 28542),  INT16_C(  5751), -INT16_C(  4007) },
      { -INT32_C(  1995551292),  INT32_C(           0),  INT32_C(           0), -INT32_C(   342662471) } },
    { UINT8_C( 20),
      { -INT32_C(  1343558366), -INT32_C(  1321924463), -INT32_C(  1700211918),  INT32_C(  1721245211) },
      {  INT16_C( 24094), -INT16_C( 23285), -INT16_C( 26832), -INT16_C(  5835), -INT16_C( 23531),  INT16_C( 11105),  INT16_C( 20989),  INT16_C(  8256) },
      {  INT16_C( 10815), -INT16_C( 12081),  INT16_C(  1074),  INT16_C( 25729),  INT16_C( 10711), -INT16_C(  3074), -INT16_C( 27064),  INT16_C( 26201) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1986389229),  INT32_C(           0) } },
    { UINT8_C(244),
      { -INT32_C(    64681116), -INT32_C(   451867072), -INT32_C(  1042137745), -INT32_C(  1493171587) },
      { -INT16_C( 12079), -INT16_C( 10791),  INT16_C( 15698),  INT16_C( 31661), -INT16_C( 24517), -INT16_C( 11837),  INT16_C( 10745),  INT16_C( 24005) },
      { -INT16_C(  5579),  INT16_C( 30041),  INT16_C( 27641),  INT16_C( 26714),  INT16_C( 15784),  INT16_C(  9513),  INT16_C( 10559),  INT16_C(  4556) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1541719454),  INT32_C(           0) } },
    { UINT8_C(250),
      { -INT32_C(   498276699),  INT32_C(   857589651), -INT32_C(  1272123765), -INT32_C(  1628861773) },
      {  INT16_C( 24547),  INT16_C( 20119), -INT16_C(    71), -INT16_C(  2314),  INT16_C(  6953),  INT16_C( 21046),  INT16_C( 18407), -INT16_C( 29620) },
      { -INT16_C( 26579), -INT16_C( 16018), -INT16_C( 29856), -INT16_C(  5132),  INT16_C(  8569),  INT16_C( 11679), -INT16_C( 30293), -INT16_C( 28981) },
      {  INT32_C(           0),  INT32_C(   871584875),  INT32_C(           0), -INT32_C(  1328047804) } },
    { UINT8_C(232),
      {  INT32_C(  1637997922), -INT32_C(   276129581),  INT32_C(   366403022), -INT32_C(  1035836631) },
      {  INT16_C(   977),  INT16_C( 23842),  INT16_C(  3576),  INT16_C(  6614),  INT16_C(   940),  INT16_C( 13764),  INT16_C( 21198),  INT16_C( 12317) },
      { -INT16_C( 16593),  INT16_C(   914),  INT16_C(  7255),  INT16_C(  9714), -INT16_C( 14087),  INT16_C(  9018),  INT16_C( 31787), -INT16_C(   539) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   368654668) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi16(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_dpwssds_epi32(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i b = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_maskz_dpwssds_epi32(k, src, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_dpwssds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const int16_t a[16];
    const int16_t b[16];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  2019166080), -INT32_C(  1064226796),  INT32_C(    49698100), -INT32_C(   684518489),  INT32_C(   702203346), -INT32_C(   615592735), -INT32_C(  1057060716), -INT32_C(  2051153147) },
      {  INT16_C(  6122), -INT16_C(   259), -INT16_C( 29113),  INT16_C( 31678), -INT16_C( 19229), -INT16_C( 30082), -INT16_C( 20024), -INT16_C( 26015),
         INT16_C( 15222),  INT16_C( 22468),  INT16_C(  4615), -INT16_C( 25550),  INT16_C( 12443), -INT16_C( 24484),  INT16_C(  6419), -INT16_C(   731) },
      {  INT16_C(  8752),  INT16_C( 30715), -INT16_C( 17744), -INT16_C( 27661),  INT16_C( 29038),  INT16_C( 13853),  INT16_C( 32546), -INT16_C( 26415),
        -INT16_C( 27206), -INT16_C( 15633),  INT16_C(  8871),  INT16_C( 16990), -INT16_C( 17838),  INT16_C( 26338),  INT16_C(  2003),  INT16_C(   867) },
      {  INT32_C(  2064790639), -INT32_C(  1423890882), -INT32_C(   925399548), -INT32_C(   649033368), -INT32_C(    63168630), -INT32_C(  1008747570), -INT32_C(  1923878542), -INT32_C(  2038929667) } },
    { { -INT32_C(   646291671), -INT32_C(  2022937319),  INT32_C(    12487390), -INT32_C(  1013412087), -INT32_C(   880441308), -INT32_C(    66133078),  INT32_C(  1885532317),  INT32_C(   561235704) },
      { -INT16_C(  4571),  INT16_C( 16123),  INT16_C( 26459),  INT16_C( 15045), -INT16_C( 31759), -INT16_C(  1478), -INT16_C( 11502),  INT16_C( 14014),
         INT16_C( 17243),  INT16_C(  1282),  INT16_C(  4135), -INT16_C( 15359),  INT16_C( 25600), -INT16_C(  1995), -INT16_C( 22486),  INT16_C( 20250) },
      {  INT16_C(  5526), -INT16_C(  3443),  INT16_C( 21116),  INT16_C( 28204),  INT16_C( 26326), -INT16_C(  6040),  INT16_C(  9785), -INT16_C( 27617),
         INT16_C(  8554), -INT16_C( 28263), -INT16_C( 25807),  INT16_C( 12629), -INT16_C( 29953),  INT16_C( 10538),  INT16_C( 17459), -INT16_C( 13960) },
      { -INT32_C(   727062506), -INT32_C(  1039899895), -INT32_C(   814672924), -INT32_C(  1512983795), -INT32_C(   769177852), -INT32_C(   366813834),  INT32_C(  1097712207), -INT32_C(   114037370) } },
    { { -INT32_C(   709163687),  INT32_C(   759424855), -INT32_C(  2028557234),  INT32_C(  1008481746), -INT32_C(  2016561834),  INT32_C(  1337467728), -INT32_C(   528948563),  INT32_C(  2141909030) },
      {  INT16_C( 26101),  INT16_C( 19797), -INT16_C( 26547), -INT16_C( 25734), -INT16_C( 28604),  INT16_C(  5922),  INT16_C( 16069),  INT16_C(  6995),
         INT16_C(  8692),  INT16_C( 17570),  INT16_C( 23364), -INT16_C(  3692),  INT16_C(  3133),  INT16_C( 25810),  INT16_C( 31997), -INT16_C(  3357) },
      {  INT16_C( 14561),  INT16_C( 11839), -INT16_C( 17711),  INT16_C(  5577), -INT16_C(  5046),  INT16_C(  4140), -INT16_C( 32726),  INT16_C(  7723),
        -INT16_C( 12639), -INT16_C(  6813), -INT16_C(  2263),  INT16_C( 26326), -INT16_C( 22525),  INT16_C(   202), -INT16_C( 20956),  INT16_C(  1779) },
      { -INT32_C(    94730343),  INT32_C(  1086080254), -INT32_C(  1859704370),  INT32_C(   536630037),              INT32_MIN,  INT32_C(  1187399404), -INT32_C(   594305768),  INT32_C(  1465407795) } },
    { { -INT32_C(  1221315866),  INT32_C(   936247020),  INT32_C(   340261354),  INT32_C(   439579257),  INT32_C(  1778357824), -INT32_C(  1865361779), -INT32_C(  1550738818),  INT32_C(   799638600) },
      { -INT16_C(  8778), -INT16_C( 23578), -INT16_C( 19493), -INT16_C( 14886),  INT16_C(  8621),  INT16_C(  9946),  INT16_C(  3475), -INT16_C( 11199),
         INT16_C( 16547),  INT16_C( 12349),  INT16_C(  3350), -INT16_C( 27200),  INT16_C( 20904), -INT16_C(  4040), -INT16_C(  7723), -INT16_C( 29665) },
      {  INT16_C(  1726), -INT16_C( 26065),  INT16_C(  2489),  INT16_C( 26207),  INT16_C( 14634), -INT16_C( 17011), -INT16_C( 12730), -INT16_C(  5743),
        -INT16_C( 12530),  INT16_C(  9497), -INT16_C(  9508), -INT16_C( 31558), -INT16_C(  3541),  INT16_C(   373), -INT16_C( 27437), -INT16_C( 28275) },
      { -INT32_C(   621906124),  INT32_C(   497611541),  INT32_C(   297229662),  INT32_C(   459658364),  INT32_C(  1688302367), -INT32_C(  1038835979), -INT32_C(  1626266802),  INT32_C(  1850312426) } },
    { {  INT32_C(  1412152474), -INT32_C(   272987195),  INT32_C(   195839940),  INT32_C(   619986453), -INT32_C(   381088243),  INT32_C(   325977064), -INT32_C(   938155019),  INT32_C(   307863927) },
      { -INT16_C( 31395),  INT16_C(  8806),  INT16_C(  8208), -INT16_C( 11247), -INT16_C( 16792),  INT16_C( 32223), -INT16_C( 11012),  INT16_C(  2465),
        -INT16_C(  5406), -INT16_C( 13582),  INT16_C( 24813), -INT16_C(  7459), -INT16_C(  3517), -INT16_C( 17494),  INT16_C(  1171), -INT16_C(  3635) },
      {  INT16_C( 13193), -INT16_C( 26349),  INT16_C(  9555), -INT16_C( 17555),  INT16_C( 19939), -INT16_C(  8391), -INT16_C(  9695),  INT16_C(  1000),
        -INT16_C(  9531), -INT16_C( 19763), -INT16_C( 21957),  INT16_C( 32405),  INT16_C( 16284),  INT16_C( 12345),  INT16_C(  1603), -INT16_C( 13279) },
      {  INT32_C(   765928945),  INT32_C(     2881330), -INT32_C(   409358941),  INT32_C(   729212793), -INT32_C(    61142591), -INT32_C(   460550872), -INT32_C(  1211389277),  INT32_C(   358010205) } },
    { { -INT32_C(  1922747335),  INT32_C(  1011405657),  INT32_C(  1092321568),  INT32_C(   558105436),  INT32_C(   433263070),  INT32_C(  1486317755), -INT32_C(   343354968),  INT32_C(   297314775) },
      {  INT16_C(  7645),  INT16_C( 14238), -INT16_C(  6416),  INT16_C(  4211), -INT16_C( 28824), -INT16_C( 15279), -INT16_C( 27246),  INT16_C( 28901),
        -INT16_C( 18266),  INT16_C( 25225),  INT16_C(  8481), -INT16_C( 13894),  INT16_C( 17138), -INT16_C( 13900),  INT16_C( 27883), -INT16_C( 14118) },
      {  INT16_C( 30858),  INT16_C( 31487),  INT16_C( 29535), -INT16_C( 14453), -INT16_C(  9214), -INT16_C( 27509),  INT16_C( 28786),  INT16_C(  6149),
        -INT16_C( 29144),  INT16_C( 18810),  INT16_C( 13487), -INT16_C( 24302), -INT16_C( 14474),  INT16_C( 24939),  INT16_C( 17715), -INT16_C( 17110) },
      { -INT32_C(  1238526019),  INT32_C(   761047514),  INT32_C(  1778215915), -INT32_C(    48485671),  INT32_C(  1440089624),  INT32_C(  1938352990), -INT32_C(   938062480),  INT32_C(  1032821100) } },
    { {  INT32_C(   490219966), -INT32_C(  1629174884),  INT32_C(   288583583),  INT32_C(   120207583),  INT32_C(  1985062086),  INT32_C(  1326932953),  INT32_C(  1588691498), -INT32_C(  2044994616) },
      {  INT16_C( 21252), -INT16_C( 24157), -INT16_C( 30954), -INT16_C( 18881),  INT16_C( 29430), -INT16_C( 10809), -INT16_C(  3670),  INT16_C( 29148),
         INT16_C( 11670),  INT16_C( 28647), -INT16_C(   367), -INT16_C( 17474),  INT16_C( 28545),  INT16_C( 18713),  INT16_C( 13642),  INT16_C( 20431) },
      {  INT16_C( 29320), -INT16_C( 24592),  INT16_C( 12281), -INT16_C(  4267),  INT16_C(  7330),  INT16_C( 19652), -INT16_C( 24562), -INT16_C( 23363),
        -INT16_C( 23346),  INT16_C( 24339), -INT16_C( 11869),  INT16_C(  9242),  INT16_C( 13377), -INT16_C( 29843),  INT16_C( 15465), -INT16_C(  3622) },
      {  INT32_C(  1707397550), -INT32_C(  1928755731),  INT32_C(   291887015), -INT32_C(   470634601),              INT32_MAX,  INT32_C(  1169794168),  INT32_C(  1412085904), -INT32_C(  1908022168) } },
    { { -INT32_C(  1483683154), -INT32_C(  1667832326),  INT32_C(   283662850), -INT32_C(   927684870), -INT32_C(   316160182), -INT32_C(   653180264), -INT32_C(   546996618),  INT32_C(  1758478266) },
      {  INT16_C( 24842),  INT16_C(  1039), -INT16_C( 23226),  INT16_C( 18592), -INT16_C( 30465), -INT16_C(  1448),  INT16_C(  3118),  INT16_C( 31170),
        -INT16_C(  5421),  INT16_C( 27750),  INT16_C( 30764), -INT16_C( 23995), -INT16_C( 21770), -INT16_C( 20095),  INT16_C( 20970), -INT16_C(  3047) },
      {  INT16_C( 10674), -INT16_C(  1544), -INT16_C( 26418), -INT16_C( 12735), -INT16_C( 26080),  INT16_C( 20424), -INT16_C( 30042),  INT16_C( 31432),
         INT16_C( 11892), -INT16_C( 24346),  INT16_C( 11174), -INT16_C( 25278), -INT16_C( 15402), -INT16_C( 16306),  INT16_C( 26389), -INT16_C( 14412) },
      { -INT32_C(  1220123862), -INT32_C(  1291016978),  INT32_C(  1048616098), -INT32_C(    41620386), -INT32_C(  1056228214),  INT32_C(   297122282),  INT32_C(   115973992),              INT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_dpwssds_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_dpwssds_epi32(src, a, b);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_dpwssds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int16_t a[16];
    const int16_t b[16];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1606462608),  INT32_C(  1680671300),  INT32_C(  1119090076), -INT32_C(   188974209),  INT32_C(  1351918250), -INT32_C(  1527916594), -INT32_C(  1352385638),  INT32_C(   863443107) },
      UINT8_C(196),
      { -INT16_C( 28105),  INT16_C( 14600),  INT16_C( 27839), -INT16_C( 19243),  INT16_C(  6176), -INT16_C( 25804),  INT16_C( 10452),  INT16_C( 30533),
        -INT16_C( 26948), -INT16_C( 27835), -INT16_C(  5757), -INT16_C( 16594), -INT16_C(  8883),  INT16_C( 25954), -INT16_C( 27308), -INT16_C( 29655) },
      {  INT16_C( 12584), -INT16_C(  6203), -INT16_C( 25699), -INT16_C( 16996), -INT16_C( 12109), -INT16_C( 30887), -INT16_C( 24840), -INT16_C( 19202),
         INT16_C( 17204), -INT16_C( 18360),  INT16_C( 30252),  INT16_C( 31095), -INT16_C(  9901), -INT16_C( 22306),  INT16_C(  1902), -INT16_C( 27084) },
      {  INT32_C(  1606462608),  INT32_C(  1680671300),  INT32_C(  1841313040), -INT32_C(   188974209),  INT32_C(  1351918250), -INT32_C(  1527916594), -INT32_C(  1843364979),  INT32_C(  1614679311) } },
    { { -INT32_C(   696321736),  INT32_C(  1200822932), -INT32_C(   489689878), -INT32_C(  1080636021),  INT32_C(  1031265809), -INT32_C(  1464340908),  INT32_C(   911250887), -INT32_C(   708016995) },
      UINT8_C(125),
      { -INT16_C( 21686),  INT16_C( 25618),  INT16_C( 22847),  INT16_C( 11086),  INT16_C( 12328), -INT16_C(  2378),  INT16_C( 30407), -INT16_C( 23289),
         INT16_C( 17645), -INT16_C(  8966), -INT16_C( 23813), -INT16_C( 28253), -INT16_C(  9742),  INT16_C( 30254),  INT16_C(   934), -INT16_C(  3853) },
      {  INT16_C(  1455), -INT16_C(  4523), -INT16_C( 23713), -INT16_C( 30951), -INT16_C( 12076), -INT16_C( 25731), -INT16_C( 31674),  INT16_C( 13120),
         INT16_C( 15049), -INT16_C( 15345), -INT16_C( 19492), -INT16_C( 12715), -INT16_C( 31860),  INT16_C( 12868),  INT16_C( 14471),  INT16_C( 13859) },
      { -INT32_C(   843745080),  INT32_C(  1200822932), -INT32_C(   577374488),              INT32_MIN,  INT32_C(  1434388684), -INT32_C(   640941017),  INT32_C(  1610939479), -INT32_C(   708016995) } },
    { { -INT32_C(  1675331523), -INT32_C(   282837733),  INT32_C(  1401594125), -INT32_C(   276313306), -INT32_C(   491547131), -INT32_C(   693106359),  INT32_C(   319354252),  INT32_C(  1783180077) },
      UINT8_C(163),
      {  INT16_C(  1901), -INT16_C( 21569), -INT16_C( 20949), -INT16_C( 13128),  INT16_C(  3129),  INT16_C(  1266), -INT16_C(  7789),  INT16_C( 10505),
        -INT16_C(  5227), -INT16_C( 24973),  INT16_C( 18844), -INT16_C( 28374),  INT16_C( 15953),  INT16_C( 32190),  INT16_C( 10375), -INT16_C(  2784) },
      { -INT16_C(  8401),  INT16_C( 23200),  INT16_C( 22670), -INT16_C( 14553),  INT16_C(  6500), -INT16_C(  2101), -INT16_C( 11013), -INT16_C( 28639),
        -INT16_C( 27456),  INT16_C( 23598),  INT16_C( 22749),  INT16_C( 12013), -INT16_C( 21610),  INT16_C(  7851), -INT16_C( 13101),  INT16_C(   787) },
      {              INT32_MIN, -INT32_C(   566699779),  INT32_C(  1401594125), -INT32_C(   276313306), -INT32_C(   491547131), -INT32_C(   605281065),  INT32_C(   319354252),  INT32_C(  1645066194) } },
    { {  INT32_C(   962442155),  INT32_C(  1879081995), -INT32_C(  1721250914),  INT32_C(  1613334688), -INT32_C(   105097444),  INT32_C(  1177069999),  INT32_C(   660919124),  INT32_C(  1261074335) },
      UINT8_C( 42),
      { -INT16_C( 31608),  INT16_C(  3125), -INT16_C( 23163),  INT16_C( 20650),  INT16_C( 17165), -INT16_C( 27152),  INT16_C( 20588), -INT16_C( 15438),
        -INT16_C( 21748), -INT16_C( 19085), -INT16_C( 17965), -INT16_C( 22775),  INT16_C( 12573), -INT16_C( 27578), -INT16_C( 28325), -INT16_C(  7234) },
      { -INT16_C(  3306), -INT16_C( 25616), -INT16_C( 25959), -INT16_C( 22805), -INT16_C(  8994),  INT16_C( 19003), -INT16_C(  4820),  INT16_C( 14606),
        -INT16_C( 32359),  INT16_C( 27886), -INT16_C(  1990),  INT16_C( 22291),  INT16_C( 23081), -INT16_C( 31509), -INT16_C( 22037),  INT16_C(   360) },
      {  INT32_C(   962442155),  INT32_C(  2009447062), -INT32_C(  1721250914),  INT32_C(  1288613100), -INT32_C(   105097444),  INT32_C(   705142824),  INT32_C(   660919124),  INT32_C(  1261074335) } },
    { {  INT32_C(   899438748), -INT32_C(   790918926), -INT32_C(  1877272732), -INT32_C(  1647761148), -INT32_C(   469059414), -INT32_C(   650437200),  INT32_C(  1667049079),  INT32_C(  1801766351) },
      UINT8_C( 29),
      { -INT16_C( 24319), -INT16_C( 30448), -INT16_C(  8068), -INT16_C( 27667),  INT16_C( 32251),  INT16_C(  9368),  INT16_C( 13639), -INT16_C(    50),
        -INT16_C( 19905),  INT16_C( 23983), -INT16_C( 30483),  INT16_C(  5076),  INT16_C( 14309), -INT16_C( 21534),  INT16_C( 20124), -INT16_C( 25144) },
      { -INT16_C( 10001),  INT16_C( 27430),  INT16_C(  5049), -INT16_C( 19201), -INT16_C( 26736), -INT16_C( 10279), -INT16_C( 22580),  INT16_C(  3286),
        -INT16_C( 31398),  INT16_C( 18281),  INT16_C( 15629), -INT16_C(  3237),  INT16_C( 15733),  INT16_C(  4510),  INT16_C( 26251),  INT16_C( 31406) },
      {  INT32_C(   307464427), -INT32_C(   790918926),              INT32_MIN, -INT32_C(  1955894068),  INT32_C(   594350999), -INT32_C(   650437200),  INT32_C(  1667049079),  INT32_C(  1801766351) } },
    { { -INT32_C(   119090113),  INT32_C(  2007819751),  INT32_C(  1213171068), -INT32_C(  2024528595), -INT32_C(  1194410581),  INT32_C(  1890265595), -INT32_C(   226408089), -INT32_C(   278057040) },
      UINT8_C(  3),
      { -INT16_C(  6317),  INT16_C( 14570),  INT16_C( 24979),  INT16_C(  6580), -INT16_C(   848), -INT16_C( 10682), -INT16_C( 12975),  INT16_C(  3713),
         INT16_C( 14747), -INT16_C( 15095),  INT16_C( 31205),  INT16_C( 11820),  INT16_C(  7930),  INT16_C( 10718), -INT16_C( 12917), -INT16_C(  8660) },
      {  INT16_C(  5812),  INT16_C( 18454), -INT16_C( 13704),  INT16_C( 10337), -INT16_C( 22585),  INT16_C(  6398),  INT16_C( 32628),  INT16_C(  3878),
         INT16_C( 12473), -INT16_C( 24876),  INT16_C(   169), -INT16_C( 23348), -INT16_C( 21729), -INT16_C( 21811), -INT16_C(  1416),  INT16_C( 11657) },
      {  INT32_C(   113070263),  INT32_C(  1733524995),  INT32_C(  1213171068), -INT32_C(  2024528595), -INT32_C(  1194410581),  INT32_C(  1890265595), -INT32_C(   226408089), -INT32_C(   278057040) } },
    { { -INT32_C(  2005557488),  INT32_C(   833738346), -INT32_C(   246829187), -INT32_C(   402624721),  INT32_C(  1233573279), -INT32_C(   185773355),  INT32_C(  1990179581), -INT32_C(   979162956) },
      UINT8_C(199),
      {  INT16_C( 19736), -INT16_C(  4559),  INT16_C( 25342), -INT16_C( 20885),  INT16_C( 23723),  INT16_C(  7133), -INT16_C( 15012),  INT16_C( 12730),
         INT16_C(   843), -INT16_C( 25337), -INT16_C(  1040), -INT16_C( 21605),  INT16_C(  4506), -INT16_C( 15777),  INT16_C(  9396), -INT16_C( 13174) },
      { -INT16_C( 17550),  INT16_C( 28858),  INT16_C(  9502), -INT16_C( 14050), -INT16_C(  1151), -INT16_C(  8732), -INT16_C( 24640),  INT16_C(  2831),
         INT16_C(  5794), -INT16_C( 27735),  INT16_C( 17425), -INT16_C( 21442), -INT16_C( 25259),  INT16_C(  2414), -INT16_C(  1854),  INT16_C( 13525) },
      {              INT32_MIN,  INT32_C(  1367972280), -INT32_C(   336419716), -INT32_C(   402624721),  INT32_C(  1233573279), -INT32_C(   185773355),  INT32_C(  1838276849), -INT32_C(  1174761490) } },
    { { -INT32_C(   760967244),  INT32_C(   899400628),  INT32_C(  2131919038), -INT32_C(  1047912161),  INT32_C(  1230254903), -INT32_C(   856321417), -INT32_C(   220896464),  INT32_C(   270969436) },
      UINT8_C( 57),
      { -INT16_C(  7478), -INT16_C( 29203),  INT16_C(  8829), -INT16_C(   692), -INT16_C( 13515),  INT16_C( 22044), -INT16_C(  8619), -INT16_C( 30322),
        -INT16_C( 10446), -INT16_C( 15104), -INT16_C( 12852),  INT16_C( 12277), -INT16_C(  6238),  INT16_C( 19851), -INT16_C( 25843), -INT16_C( 10362) },
      {  INT16_C( 29821), -INT16_C(  1179), -INT16_C( 20074), -INT16_C( 13320),  INT16_C(  5500), -INT16_C( 11998), -INT16_C( 20237),  INT16_C(  9562),
         INT16_C( 23431),  INT16_C( 21482), -INT16_C(  8408), -INT16_C( 13694),  INT16_C(  3782), -INT16_C( 11497), -INT16_C( 24919),  INT16_C( 10155) },
      { -INT32_C(   949538345),  INT32_C(   899400628),  INT32_C(  2131919038), -INT32_C(  1163428422),  INT32_C(   661030549), -INT32_C(   916383039), -INT32_C(   220896464),  INT32_C(   270969436) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_dpwssds_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_mask_dpwssds_epi32(src, k, a, b);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_dpwssds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t src[8];
    const int16_t a[16];
    const int16_t b[16];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C( 18),
      { -INT32_C(  1045945840),  INT32_C(   792556570),  INT32_C(  1176637078), -INT32_C(   993179543),  INT32_C(   317464626), -INT32_C(  1327974750),  INT32_C(  1817881806),  INT32_C(  1736343895) },
      {  INT16_C(  9891), -INT16_C( 17112),  INT16_C( 26010),  INT16_C( 12525),  INT16_C(  3955), -INT16_C(  9098),  INT16_C( 17239), -INT16_C( 30048),
        -INT16_C( 29597),  INT16_C(  1692),  INT16_C( 29763),  INT16_C(  4534),  INT16_C(  4128),  INT16_C( 30589), -INT16_C(  1135),  INT16_C( 13534) },
      {  INT16_C(  1569), -INT16_C( 17166), -INT16_C(  8341), -INT16_C(  8212),  INT16_C( 25582),  INT16_C( 18107),  INT16_C( 23718),  INT16_C(  2768),
         INT16_C( 27880),  INT16_C( 11024), -INT16_C( 14624),  INT16_C(   316), -INT16_C( 17961),  INT16_C( 26744),  INT16_C( 22452), -INT16_C( 10595) },
      {  INT32_C(           0),  INT32_C(   472751860),  INT32_C(           0),  INT32_C(           0), -INT32_C(   489047126),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 93),
      {  INT32_C(  1858704015), -INT32_C(   514021250), -INT32_C(  1081564573), -INT32_C(   559377806),  INT32_C(  1757402018), -INT32_C(   918568944), -INT32_C(  1887524808), -INT32_C(   722643899) },
      { -INT16_C( 18714),  INT16_C( 25666), -INT16_C( 24994), -INT16_C( 16058), -INT16_C( 12735), -INT16_C( 19583),  INT16_C( 10592),  INT16_C(   658),
         INT16_C( 20988),  INT16_C(  3178), -INT16_C( 21999),  INT16_C( 18902),  INT16_C( 21586), -INT16_C( 26663), -INT16_C( 14680), -INT16_C( 29077) },
      { -INT16_C( 21124), -INT16_C(  9486),  INT16_C( 14411), -INT16_C( 29541),  INT16_C(  7174),  INT16_C( 26176), -INT16_C( 11707),  INT16_C( 17000),
        -INT16_C( 11485),  INT16_C( 13390),  INT16_C(  9341), -INT16_C( 12419),  INT16_C( 22136),  INT16_C(  8294), -INT16_C( 12004), -INT16_C( 26450) },
      {  INT32_C(  2010550875),  INT32_C(           0), -INT32_C(  1685530071), -INT32_C(   672192350),  INT32_C(  1558908258),  INT32_C(           0), -INT32_C(  1630840034),  INT32_C(           0) } },
    { UINT8_C(126),
      { -INT32_C(   641109343),  INT32_C(   719345166),  INT32_C(  1752188566), -INT32_C(  2104773969),  INT32_C(   637517568), -INT32_C(  1818374596),  INT32_C(    95403572),  INT32_C(   226707564) },
      {  INT16_C( 19642), -INT16_C( 14105), -INT16_C( 14430),  INT16_C( 14579),  INT16_C( 25357), -INT16_C( 17248),  INT16_C( 11029),  INT16_C(  5438),
         INT16_C( 15850),  INT16_C( 10042), -INT16_C( 10229),  INT16_C( 16314),  INT16_C( 27030),  INT16_C(   580), -INT16_C( 14415),  INT16_C( 27664) },
      { -INT16_C(  2284), -INT16_C( 18892),  INT16_C( 10174), -INT16_C( 13329), -INT16_C( 28790), -INT16_C( 24696), -INT16_C( 14661), -INT16_C( 23115),
        -INT16_C(  4348),  INT16_C(  4044), -INT16_C( 31033),  INT16_C( 23887), -INT16_C( 27664), -INT16_C( 24224),  INT16_C( 28763),  INT16_C( 28429) },
      {  INT32_C(           0),  INT32_C(   378210855),  INT32_C(  1448117144),              INT32_MIN,  INT32_C(   609211616), -INT32_C(  1111245521), -INT32_C(   666404268),  INT32_C(           0) } },
    { UINT8_C(103),
      {  INT32_C(  1764042050), -INT32_C(  1527451628),  INT32_C(  1063228280),  INT32_C(   943916104),  INT32_C(  1476350673),  INT32_C(   893869473),  INT32_C(   764471741),  INT32_C(   949288950) },
      { -INT16_C( 18140),  INT16_C( 14754), -INT16_C( 26967),  INT16_C(  8925),  INT16_C( 15401),  INT16_C( 29281), -INT16_C( 23488),  INT16_C(  4522),
        -INT16_C( 22026), -INT16_C( 26519), -INT16_C( 20474), -INT16_C( 15411),  INT16_C( 23961), -INT16_C( 28432), -INT16_C( 31652), -INT16_C( 32568) },
      {  INT16_C( 27197), -INT16_C(  6215), -INT16_C( 27136),  INT16_C( 10761),  INT16_C( 27346),  INT16_C(  5020),  INT16_C( 17934),  INT16_C(  1060),
        -INT16_C( 29201), -INT16_C(  2404),  INT16_C( 26942), -INT16_C( 10311), -INT16_C( 21818),  INT16_C(  8807),  INT16_C( 12334),  INT16_C( 27811) },
      {  INT32_C(  1178992360), -INT32_C(   699633191),  INT32_C(  1631374646),  INT32_C(           0),  INT32_C(           0),  INT32_C(   501161786), -INT32_C(     8709981),  INT32_C(           0) } },
    { UINT8_C(154),
      { -INT32_C(   207924388), -INT32_C(   960117412), -INT32_C(  1479223199), -INT32_C(  1969825539), -INT32_C(   557282187), -INT32_C(   257580986),  INT32_C(   924763911), -INT32_C(   942503318) },
      {  INT16_C( 28125),  INT16_C( 14778),  INT16_C( 32562), -INT16_C( 27649), -INT16_C( 11432),  INT16_C( 21818), -INT16_C( 12116),  INT16_C(  8671),
        -INT16_C( 22435), -INT16_C( 23553), -INT16_C( 23480),  INT16_C( 20371), -INT16_C( 20116), -INT16_C( 10617),  INT16_C( 22844),  INT16_C(  6557) },
      {  INT16_C( 22470), -INT16_C(  1965),  INT16_C( 21207),  INT16_C( 12171), -INT16_C( 15066), -INT16_C( 11644),  INT16_C( 25493), -INT16_C(  3341),
        -INT16_C(  3573),  INT16_C( 21397),  INT16_C( 10391),  INT16_C(   931),  INT16_C( 10970),  INT16_C(  5849),  INT16_C( 30595),  INT16_C( 18735) },
      {  INT32_C(           0), -INT32_C(   606091057),  INT32_C(           0),              INT32_MIN, -INT32_C(   981085473),  INT32_C(           0),  INT32_C(           0), -INT32_C(   120745743) } },
    { UINT8_C(206),
      { -INT32_C(   710590078), -INT32_C(  1845766964), -INT32_C(  1138307752), -INT32_C(  1295574592), -INT32_C(   683074642), -INT32_C(   391033666), -INT32_C(  1653881050),  INT32_C(  2037101814) },
      {  INT16_C(  4597), -INT16_C( 16050),  INT16_C( 18917),  INT16_C( 15954),  INT16_C( 30742), -INT16_C( 10502), -INT16_C( 15983),  INT16_C( 16520),
        -INT16_C( 11556), -INT16_C( 26089), -INT16_C( 14306),  INT16_C( 17538), -INT16_C(  4721), -INT16_C( 31263),  INT16_C( 19873), -INT16_C( 26882) },
      {  INT16_C( 19550),  INT16_C( 17239), -INT16_C( 22123), -INT16_C( 21631),  INT16_C( 31522), -INT16_C( 19583),  INT16_C(  2621),  INT16_C(  6643),
         INT16_C(  2780), -INT16_C(  1356),  INT16_C( 14034),  INT16_C( 24895),  INT16_C(  8228), -INT16_C( 14873), -INT16_C(  6803), -INT16_C( 13476) },
      {  INT32_C(           0),              INT32_MIN,  INT32_C(    36402238), -INT32_C(  1227723675),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1227750839),              INT32_MAX } },
    { UINT8_C( 50),
      {  INT32_C(  1573326771),  INT32_C(   209679248), -INT32_C(    28757260),  INT32_C(   819618342),  INT32_C(  1292096790),  INT32_C(   879846420),  INT32_C(   832714315),  INT32_C(  1180921234) },
      {  INT16_C( 10876),  INT16_C(  3491),  INT16_C(  8861), -INT16_C( 28135),  INT16_C( 25172),  INT16_C( 31376),  INT16_C( 27588), -INT16_C(  9301),
        -INT16_C( 20928),  INT16_C( 21544), -INT16_C( 26350),  INT16_C( 24200),  INT16_C( 10959),  INT16_C( 25231), -INT16_C(  3432),  INT16_C(  5288) },
      {  INT16_C( 19228), -INT16_C( 17887),  INT16_C( 14957), -INT16_C( 16052), -INT16_C(  9060),  INT16_C( 24892), -INT16_C(  6329), -INT16_C( 30916),
         INT16_C( 25749), -INT16_C( 22565),  INT16_C( 25853), -INT16_C( 13307), -INT16_C( 27506),  INT16_C(  9774), -INT16_C( 10618), -INT16_C( 23749) },
      {  INT32_C(           0),  INT32_C(   793836245),  INT32_C(           0),  INT32_C(           0),  INT32_C(   267081358), -INT32_C(   123409530),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 33),
      { -INT32_C(  1752277668), -INT32_C(  2060234583),  INT32_C(  1942852748),  INT32_C(   872961232), -INT32_C(  1808683216),  INT32_C(  1227030197),  INT32_C(    63981868), -INT32_C(   534482044) },
      { -INT16_C( 19504),  INT16_C( 31095), -INT16_C( 21757), -INT16_C( 28674), -INT16_C( 13505),  INT16_C(  4098),  INT16_C(  2592),  INT16_C( 20548),
         INT16_C( 30393),  INT16_C( 28388),  INT16_C(  1652), -INT16_C( 24392), -INT16_C( 30641), -INT16_C( 11357), -INT16_C( 14085), -INT16_C( 13388) },
      {  INT16_C( 11131),  INT16_C( 32324),  INT16_C( 17110),  INT16_C(  5645),  INT16_C(  3854),  INT16_C( 11814),  INT16_C( 27161), -INT16_C( 11650),
         INT16_C( 25312),  INT16_C( 21569), -INT16_C(  1688), -INT16_C( 18187), -INT16_C( 26495),  INT16_C( 31883),  INT16_C( 16224), -INT16_C(  9401) },
      { -INT32_C(   964261912),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1667858925),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi16(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi16(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_dpwssds_epi32(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i b = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_maskz_dpwssds_epi32(k, src, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_dpwssds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const int16_t a[32];
    const int16_t b[32];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(  1096387435), -INT32_C(   615029043), -INT32_C(  1911980683), -INT32_C(   933132312),  INT32_C(  1377673961),  INT32_C(   470422171),  INT32_C(   194549162),  INT32_C(  1088872405),
         INT32_C(   931217514),  INT32_C(   471062950),  INT32_C(  1051335766), -INT32_C(  1928918108),  INT32_C(  1222583469), -INT32_C(   530257610),  INT32_C(  1424751743),  INT32_C(  1167381211) },
      {  INT16_C(  5394), -INT16_C( 18307), -INT16_C( 28434),  INT16_C( 17876),  INT16_C( 32684),  INT16_C( 20611), -INT16_C( 30070),  INT16_C( 14558),
        -INT16_C( 16978), -INT16_C(  7040), -INT16_C(  6745),  INT16_C(  9925), -INT16_C( 20255), -INT16_C( 17030),  INT16_C(  3714), -INT16_C( 27646),
         INT16_C( 32547),  INT16_C(  4685),  INT16_C(  8463), -INT16_C( 17321), -INT16_C(  9568),  INT16_C( 11020), -INT16_C(  5531),  INT16_C(  4963),
        -INT16_C(  7256),  INT16_C( 20472), -INT16_C( 16952), -INT16_C( 21899), -INT16_C(  4243), -INT16_C(  3993),  INT16_C( 27133),  INT16_C(  8324) },
      { -INT16_C( 11799), -INT16_C(  1998), -INT16_C( 30221), -INT16_C( 27724), -INT16_C( 16028), -INT16_C( 13890),  INT16_C(  8619),  INT16_C( 21468),
        -INT16_C( 11259), -INT16_C( 12894),  INT16_C(  6033), -INT16_C(   137), -INT16_C(  8698),  INT16_C(  1007),  INT16_C( 29512),  INT16_C( 12580),
         INT16_C( 22085),  INT16_C( 14377), -INT16_C(  8480),  INT16_C( 17611), -INT16_C( 30049),  INT16_C( 18957), -INT16_C(  5717), -INT16_C( 20322),
         INT16_C( 16574),  INT16_C( 20350), -INT16_C(  2728),  INT16_C( 24142),  INT16_C( 15828),  INT16_C(  7266), -INT16_C( 31055), -INT16_C(  2483) },
      {  INT32_C(  1069321015), -INT32_C(   251319353),              INT32_MIN, -INT32_C(   879774498),  INT32_C(  1659603023),  INT32_C(   428369861),  INT32_C(   353577942),  INT32_C(   850693293),
         INT32_C(  1717374254),  INT32_C(    94256579),  INT32_C(  1547750738), -INT32_C(  1998155467),  INT32_C(  1518927725), -INT32_C(  1012698212),  INT32_C(  1328580401),  INT32_C(   304097404) } },
    { { -INT32_C(  1137805604), -INT32_C(   218039980),  INT32_C(   792595843), -INT32_C(  1243620105),  INT32_C(  1946443036),  INT32_C(   668160851),  INT32_C(  1094923664), -INT32_C(  1757966149),
         INT32_C(  1532257542), -INT32_C(   498183073),  INT32_C(  1494322274), -INT32_C(  2062618264), -INT32_C(  1577512370), -INT32_C(   154612635), -INT32_C(  1137243391), -INT32_C(  1571524709) },
      { -INT16_C( 22316),  INT16_C( 13309),  INT16_C( 19452),  INT16_C( 24086),  INT16_C( 10200),  INT16_C( 16567), -INT16_C( 15080),  INT16_C( 26565),
        -INT16_C( 16424),  INT16_C( 15624), -INT16_C( 11893), -INT16_C( 29389),  INT16_C( 27612),  INT16_C( 30793), -INT16_C( 25126), -INT16_C( 20966),
         INT16_C(  5957),  INT16_C( 17122), -INT16_C(  1950),  INT16_C( 15008),  INT16_C( 22559),  INT16_C( 14459),  INT16_C( 16413), -INT16_C(  2657),
        -INT16_C( 22529), -INT16_C( 29901),  INT16_C( 26232),  INT16_C( 21784),  INT16_C( 25041), -INT16_C( 21555), -INT16_C(  6145),  INT16_C( 17498) },
      {  INT16_C( 15614),  INT16_C( 24710),  INT16_C( 10036),  INT16_C( 21403),  INT16_C(  5759), -INT16_C( 25461),  INT16_C( 10838),  INT16_C( 22162),
        -INT16_C( 14894),  INT16_C( 19169), -INT16_C(  1749), -INT16_C(   609),  INT16_C( 27738),  INT16_C( 22952),  INT16_C(   595),  INT16_C( 20894),
         INT16_C(  9278),  INT16_C( 29362),  INT16_C( 19787), -INT16_C( 13626),  INT16_C( 20835), -INT16_C( 18073), -INT16_C(  1668),  INT16_C( 19983),
        -INT16_C(  3906), -INT16_C(  5736),  INT16_C( 14569),  INT16_C( 17638), -INT16_C( 28764), -INT16_C(  1891),  INT16_C( 15249), -INT16_C( 12215) },
      { -INT32_C(  1157382238),  INT32_C(   492692950),  INT32_C(   429525256), -INT32_C(   818323615),              INT32_MAX,  INT32_C(   706859609),              INT32_MAX,              INT32_MIN,
         INT32_C(  2090262752), -INT32_C(   741266731),  INT32_C(  1703021532), -INT32_C(  2143089979), -INT32_C(  1318001960),  INT32_C(   611787565), -INT32_C(  1816762210), -INT32_C(  1878967884) } },
    { { -INT32_C(  1421673632), -INT32_C(  1418327992), -INT32_C(   697967270), -INT32_C(  1809550122),  INT32_C(  1316863077), -INT32_C(  1718459148), -INT32_C(  2070859533), -INT32_C(   883631509),
         INT32_C(   511154134), -INT32_C(   104141409), -INT32_C(  1597034550),  INT32_C(   137687971), -INT32_C(  1537756752),  INT32_C(   138275093), -INT32_C(  2054304231),  INT32_C(  2136007081) },
      { -INT16_C( 14472),  INT16_C(  6301),  INT16_C( 26548),  INT16_C( 32273), -INT16_C(  7786),  INT16_C( 14878),  INT16_C( 21204), -INT16_C( 31678),
        -INT16_C( 26364),  INT16_C(  6441),  INT16_C( 26243), -INT16_C( 25566), -INT16_C( 20683), -INT16_C(  8671),  INT16_C( 29328),  INT16_C(  2397),
        -INT16_C(  1479), -INT16_C(  4575),  INT16_C( 12898), -INT16_C(  1940), -INT16_C( 29933), -INT16_C(  6094),  INT16_C( 30173), -INT16_C(  7828),
        -INT16_C( 27378), -INT16_C( 28165),  INT16_C(  7676),  INT16_C( 12590),  INT16_C( 20428),  INT16_C( 23567),  INT16_C( 27841), -INT16_C(  1179) },
      { -INT16_C( 31130), -INT16_C( 14103),  INT16_C( 21945), -INT16_C( 13119), -INT16_C(  3104), -INT16_C( 16716),  INT16_C(  8552),  INT16_C( 30623),
        -INT16_C( 25930), -INT16_C( 19960),  INT16_C( 14007), -INT16_C( 31773), -INT16_C(  3450),  INT16_C( 18400),  INT16_C( 17758), -INT16_C( 15038),
         INT16_C( 11212), -INT16_C( 31347),  INT16_C( 20097),  INT16_C( 24913),  INT16_C(  1602), -INT16_C( 21985), -INT16_C( 16601), -INT16_C(  8927),
         INT16_C( 10841),  INT16_C(  4496),  INT16_C( 29536), -INT16_C(  6508),  INT16_C( 29798), -INT16_C( 15314),  INT16_C( 28858), -INT16_C( 31095) },
      { -INT32_C(  1060023275), -INT32_C(  1259121619), -INT32_C(   922500174),              INT32_MIN,  INT32_C(  1871919237), -INT32_C(   538564929),              INT32_MIN, -INT32_C(   398870971),
         INT32_C(   637984111),  INT32_C(   106738477), -INT32_C(  1511010626), -INT32_C(   293333446), -INT32_C(  1961191490),  INT32_C(   283057709), -INT32_C(  1806495725),              INT32_MAX } },
    { {  INT32_C(   487266204), -INT32_C(  1484891035), -INT32_C(  1991074206), -INT32_C(  1234734243), -INT32_C(    20449379), -INT32_C(   790340502), -INT32_C(  1969941808),  INT32_C(   521150083),
        -INT32_C(  1690559691), -INT32_C(   633161096), -INT32_C(  1251699624), -INT32_C(  1519596792),  INT32_C(   748893122),  INT32_C(  1627228303),  INT32_C(   501912218), -INT32_C(   432211024) },
      {  INT16_C( 30742), -INT16_C( 29055), -INT16_C( 15565), -INT16_C( 29847), -INT16_C( 12968),  INT16_C( 24641), -INT16_C( 21096),  INT16_C( 23045),
        -INT16_C( 22048),  INT16_C( 28806), -INT16_C( 31951), -INT16_C( 13360), -INT16_C( 17899), -INT16_C( 14615),  INT16_C(  9653), -INT16_C( 13140),
         INT16_C( 11678), -INT16_C( 11942), -INT16_C( 15376),  INT16_C( 18524), -INT16_C( 25200),  INT16_C( 10408), -INT16_C( 20918),  INT16_C( 11138),
         INT16_C(  2391), -INT16_C( 30565),  INT16_C( 27532), -INT16_C( 23981),  INT16_C( 15397), -INT16_C(  9368),  INT16_C(  5218),  INT16_C(   167) },
      {  INT16_C(   321),  INT16_C( 12753),  INT16_C( 11717),  INT16_C( 21882),  INT16_C(  8907),  INT16_C(  5502),  INT16_C(   208),  INT16_C( 10048),
        -INT16_C(  9463), -INT16_C( 26961),  INT16_C(   838),  INT16_C( 27704), -INT16_C( 24513), -INT16_C( 24249), -INT16_C(  4428), -INT16_C(  2655),
         INT16_C( 29423), -INT16_C( 19418), -INT16_C( 24416),  INT16_C( 27402), -INT16_C( 30525), -INT16_C( 27776), -INT16_C( 15992), -INT16_C( 27973),
         INT16_C( 27292), -INT16_C(  7384),  INT16_C( 24685), -INT16_C( 21169), -INT16_C( 27136), -INT16_C( 19378), -INT16_C(  3964),  INT16_C( 29609) },
      {  INT32_C(   126595971),              INT32_MIN, -INT32_C(  1971005400), -INT32_C(  1007566051), -INT32_C(   588447721), -INT32_C(  1187240880), -INT32_C(  1176784486),  INT32_C(   513293299),
        -INT32_C(  1115068141),  INT32_C(   249853968), -INT32_C(   771562232), -INT32_C(  1496639410),  INT32_C(  1039840254),              INT32_MAX,  INT32_C(   265632330), -INT32_C(   447950473) } },
    { {  INT32_C(    36228962),  INT32_C(   862794352),  INT32_C(  1120333498),  INT32_C(  1272218031),  INT32_C(  1496251628),  INT32_C(  1543929180), -INT32_C(  1760537325), -INT32_C(  1492403899),
        -INT32_C(   106286199),  INT32_C(   522983269), -INT32_C(  1268649467),  INT32_C(  1610626676), -INT32_C(  1883689422), -INT32_C(  1075068756),  INT32_C(  1515715605),  INT32_C(  1040278197) },
      { -INT16_C( 21611), -INT16_C(  1481),  INT16_C( 25539), -INT16_C( 14311),  INT16_C( 31318), -INT16_C( 13699),  INT16_C( 32176), -INT16_C(  7382),
        -INT16_C(  7253),  INT16_C( 22386),  INT16_C( 23971), -INT16_C( 18409),  INT16_C( 28249),  INT16_C(  3858),  INT16_C(  5328),  INT16_C( 25933),
        -INT16_C( 31297), -INT16_C( 32161),  INT16_C( 30952),  INT16_C( 15947), -INT16_C( 14094), -INT16_C( 23800),  INT16_C( 12869), -INT16_C(  3962),
        -INT16_C(  2026), -INT16_C( 18104),  INT16_C( 24405), -INT16_C( 20622), -INT16_C( 31539), -INT16_C( 25154),  INT16_C(  2968),  INT16_C( 22530) },
      {  INT16_C( 24976),  INT16_C( 31194),  INT16_C(  9689), -INT16_C( 13385), -INT16_C( 16147),  INT16_C( 12910), -INT16_C(  2830),  INT16_C(  2083),
         INT16_C( 27628),  INT16_C( 17090),  INT16_C( 13514), -INT16_C( 26639), -INT16_C( 20552),  INT16_C( 20788),  INT16_C( 14010),  INT16_C( 19369),
        -INT16_C( 31849),  INT16_C( 28868),  INT16_C( 31657), -INT16_C( 27077), -INT16_C( 21957),  INT16_C( 11977), -INT16_C(  4962), -INT16_C( 29898),
        -INT16_C(  1961),  INT16_C(  8653), -INT16_C( 16852), -INT16_C(  6728), -INT16_C(  5011),  INT16_C( 10038), -INT16_C(  8414), -INT16_C( 18062) },
      { -INT32_C(   549725688),  INT32_C(  1301794458),  INT32_C(   437787662),  INT32_C(  1165783245),  INT32_C(  1678442484),              INT32_MAX,              INT32_MIN, -INT32_C(   915462342),
        -INT32_C(    37931794),  INT32_C(  1071033814), -INT32_C(  1244240109),  INT32_C(  1665226574), -INT32_C(  2036370348), -INT32_C(  1347597000),  INT32_C(  1421261682),  INT32_C(   608368585) } },
    { {  INT32_C(   187250274), -INT32_C(   308124494), -INT32_C(  1390712050), -INT32_C(  1372040617),  INT32_C(  2010056010),  INT32_C(   811370435), -INT32_C(  1789422989), -INT32_C(   749811087),
        -INT32_C(  1293977856), -INT32_C(   358579749),  INT32_C(  1134017516),  INT32_C(  1492242189), -INT32_C(  1747992364), -INT32_C(  1161352377),  INT32_C(   776937149), -INT32_C(   385770008) },
      { -INT16_C(  8172), -INT16_C(  4197),  INT16_C( 15201),  INT16_C( 19929),  INT16_C( 28919),  INT16_C(  1168), -INT16_C( 32449),  INT16_C(  4956),
         INT16_C( 11073), -INT16_C( 30550),  INT16_C( 29014),  INT16_C(  4930), -INT16_C( 28272),  INT16_C( 30785),  INT16_C( 17198),  INT16_C( 16993),
        -INT16_C(   733), -INT16_C( 31438),  INT16_C(  2872),  INT16_C( 12242),  INT16_C( 25468), -INT16_C( 17612), -INT16_C( 28444),  INT16_C(  9935),
         INT16_C( 31164),  INT16_C(  4782), -INT16_C(  3605),  INT16_C( 31526),  INT16_C( 26498), -INT16_C( 19981),  INT16_C( 21930), -INT16_C( 12557) },
      {  INT16_C(  9554), -INT16_C( 30125),  INT16_C(  9521), -INT16_C( 21062), -INT16_C(  4472),  INT16_C( 28008),  INT16_C( 14206),  INT16_C( 14995),
         INT16_C( 16817), -INT16_C( 25523),  INT16_C( 29490), -INT16_C( 19177),  INT16_C(  2778), -INT16_C( 31386),  INT16_C( 22879), -INT16_C( 20141),
        -INT16_C( 22913), -INT16_C( 20420), -INT16_C(  2357),  INT16_C( 21597), -INT16_C( 14876),  INT16_C( 25281),  INT16_C( 21757), -INT16_C( 20835),
        -INT16_C(  5483), -INT16_C( 14262),  INT16_C( 24925),  INT16_C( 14205), -INT16_C(  7317), -INT16_C( 13380),  INT16_C(  3900), -INT16_C( 17540) },
      {  INT32_C(   235609611), -INT32_C(   583140371), -INT32_C(  1487324474), -INT32_C(  1758695891),              INT32_MAX,  INT32_C(  1572450685),              INT32_MIN, -INT32_C(   698594058),
        -INT32_C(   635218667), -INT32_C(   100958579),  INT32_C(   309906576),  INT32_C(   666390356), -INT32_C(  1987065460), -INT32_C(   803380172),  INT32_C(   850397063), -INT32_C(    79993228) } },
    { { -INT32_C(  2123646795), -INT32_C(  1831483218), -INT32_C(  1946839410),  INT32_C(  2134479594), -INT32_C(   649624708),  INT32_C(  1326499044), -INT32_C(   468005465), -INT32_C(  1835034660),
        -INT32_C(    32306353),  INT32_C(  1636886739),  INT32_C(  1760331134), -INT32_C(  1813568233), -INT32_C(  1939066968), -INT32_C(  1680048653),  INT32_C(   645920330), -INT32_C(   575136115) },
      { -INT16_C( 13527), -INT16_C(   549),  INT16_C( 27571),  INT16_C( 12638),  INT16_C( 19441),  INT16_C(  2201), -INT16_C( 32400),  INT16_C(  6556),
         INT16_C(  2224), -INT16_C( 23643), -INT16_C( 32379), -INT16_C( 12482), -INT16_C( 17032),  INT16_C(  1526), -INT16_C( 20772),  INT16_C(  1506),
        -INT16_C( 17030),  INT16_C( 11522),  INT16_C( 24873),  INT16_C(  6751), -INT16_C(  1876),  INT16_C(  7202), -INT16_C( 16775),  INT16_C( 10549),
        -INT16_C(  9273),  INT16_C( 19661),  INT16_C(  2908), -INT16_C( 11236),  INT16_C(  4809), -INT16_C( 23078), -INT16_C( 17216),  INT16_C( 15018) },
      { -INT16_C( 21126), -INT16_C( 23704), -INT16_C( 14578), -INT16_C( 17731), -INT16_C(  8257),  INT16_C( 14806),  INT16_C(  3230),  INT16_C( 25954),
         INT16_C( 12263),  INT16_C( 17329), -INT16_C( 12997),  INT16_C(  1048), -INT16_C(  3361), -INT16_C( 24407),  INT16_C( 21422),  INT16_C( 10458),
         INT16_C( 16896),  INT16_C(  3787), -INT16_C( 30711), -INT16_C( 13880), -INT16_C( 24728),  INT16_C(  1538),  INT16_C( 25771), -INT16_C( 28053),
         INT16_C(  7316), -INT16_C( 12331), -INT16_C(  4630), -INT16_C( 13869),  INT16_C( 31967), -INT16_C( 29079),  INT16_C( 17615), -INT16_C( 12106) },
      { -INT32_C(  1824861897),              INT32_MIN, -INT32_C(  2074775741),              INT32_MAX, -INT32_C(  1032061343),  INT32_C(  1734247771), -INT32_C(   448005995),              INT32_MIN,
        -INT32_C(   276411419),  INT32_C(   779308156),  INT32_C(  1817797538),              INT32_MIN,              INT32_MIN, -INT32_C(  1537680609),  INT32_C(  1470734795), -INT32_C(  1060203863) } },
    { { -INT32_C(  1864465786),  INT32_C(  1918478090), -INT32_C(   243770554),  INT32_C(  1401152447), -INT32_C(   366848000),  INT32_C(   632550726),  INT32_C(  1102257521), -INT32_C(   418289055),
        -INT32_C(   159911956), -INT32_C(   597045098), -INT32_C(   338829013), -INT32_C(   985771835), -INT32_C(   273718871), -INT32_C(   938188202), -INT32_C(   536229761),  INT32_C(   516430386) },
      {  INT16_C( 16137), -INT16_C( 24556),  INT16_C( 32016),  INT16_C( 15228),  INT16_C( 19039),  INT16_C(  9254),  INT16_C( 26010),  INT16_C( 17385),
        -INT16_C( 26426),  INT16_C(  7218),  INT16_C( 18426),  INT16_C( 31460), -INT16_C(  4849),  INT16_C( 16730),  INT16_C(  8711),  INT16_C(  4447),
         INT16_C( 29538),  INT16_C( 29361),  INT16_C( 11761),  INT16_C( 20653), -INT16_C( 11145),  INT16_C(  4724),  INT16_C( 23865), -INT16_C(   171),
        -INT16_C( 30475), -INT16_C(  4325),  INT16_C(   207), -INT16_C(  8599), -INT16_C( 15123), -INT16_C(  2785),  INT16_C( 32486),  INT16_C( 18438) },
      { -INT16_C( 18447), -INT16_C(  7494),  INT16_C( 26852),  INT16_C( 23602), -INT16_C( 22980),  INT16_C( 30062), -INT16_C( 15613), -INT16_C(  1932),
        -INT16_C( 28853),  INT16_C(  6888),  INT16_C( 20879),  INT16_C( 32248),  INT16_C(  5909), -INT16_C(   910),  INT16_C( 30869), -INT16_C( 30908),
        -INT16_C(   209),  INT16_C(  4969), -INT16_C( 25497), -INT16_C( 23697), -INT16_C(  8894),  INT16_C( 17944), -INT16_C( 29535), -INT16_C(  5058),
         INT16_C(  9755), -INT16_C( 21753), -INT16_C(   136), -INT16_C( 29400), -INT16_C( 26089), -INT16_C( 21367), -INT16_C( 12782),  INT16_C( 16691) },
      { -INT32_C(  1978122361),              INT32_MAX, -INT32_C(   403093026),  INT32_C(   961470497),  INT32_C(   445338962),  INT32_C(  2031789260),  INT32_C(  1058380480), -INT32_C(   286837072),
        -INT32_C(    20190589), -INT32_C(  1386329456), -INT32_C(   154937927), -INT32_C(  1689759692), -INT32_C(   476920771), -INT32_C(   685405754), -INT32_C(    82178719),  INT32_C(   408942992) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_dpwssds_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i b = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_dpwssds_epi32(src, a, b);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_dpwssds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int16_t a[32];
    const int16_t b[32];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(   877960653),  INT32_C(  2077738041),  INT32_C(  1120006049), -INT32_C(  1775304581), -INT32_C(  1639893466),  INT32_C(  1277978933),  INT32_C(   368686339),  INT32_C(  1347824771),
         INT32_C(    42249161),  INT32_C(   276716399), -INT32_C(   984400054),  INT32_C(  1717338687), -INT32_C(   318464584),  INT32_C(   171585543),  INT32_C(  1763718118),  INT32_C(   700085855) },
      UINT16_C(15905),
      { -INT16_C( 28629), -INT16_C( 22118), -INT16_C(  7007), -INT16_C(  2839),  INT16_C( 10410),  INT16_C(  1654),  INT16_C( 11918), -INT16_C( 27741),
        -INT16_C( 21989),  INT16_C( 21955), -INT16_C( 22091), -INT16_C( 10872), -INT16_C(  6125), -INT16_C( 12981),  INT16_C( 27921),  INT16_C( 15371),
        -INT16_C( 23043), -INT16_C( 24858), -INT16_C( 12406),  INT16_C( 13458),  INT16_C(  2295), -INT16_C( 31174), -INT16_C(  8906),  INT16_C( 21017),
        -INT16_C(  9080),  INT16_C( 15783),  INT16_C( 12422), -INT16_C( 26350),  INT16_C( 23832),  INT16_C( 10598),  INT16_C( 29130), -INT16_C( 14235) },
      {  INT16_C( 19223), -INT16_C( 24218), -INT16_C(  1766),  INT16_C(  4821),  INT16_C(  3841),  INT16_C( 14488), -INT16_C( 19988),  INT16_C( 29834),
         INT16_C( 12685),  INT16_C(  5041), -INT16_C( 15519),  INT16_C( 31148),  INT16_C(  4641), -INT16_C(  5214),  INT16_C(  2180), -INT16_C( 25677),
         INT16_C(  6739),  INT16_C( 28220),  INT16_C(  4371),  INT16_C(  5248),  INT16_C(  6176),  INT16_C(  3148), -INT16_C( 10551),  INT16_C( 22145),
         INT16_C( 12808),  INT16_C( 26986),  INT16_C(  5878),  INT16_C(  6115), -INT16_C( 31447), -INT16_C( 21246), -INT16_C( 18803), -INT16_C(  7864) },
      {  INT32_C(   863279110),  INT32_C(  2077738041),  INT32_C(  1120006049), -INT32_C(  1775304581), -INT32_C(  1639893466),  INT32_C(  1282168106),  INT32_C(   368686339),  INT32_C(  1347824771),
         INT32_C(    42249161),  INT32_C(   293117357), -INT32_C(  1068361886),              INT32_MAX, -INT32_C(     8841186),  INT32_C(    83471809),  INT32_C(  1763718118),  INT32_C(   700085855) } },
    { { -INT32_C(   481327920), -INT32_C(  1242050667), -INT32_C(  1329511193),  INT32_C(   570835482),  INT32_C(  1804365941), -INT32_C(  1333629049), -INT32_C(  2107800332),  INT32_C(   174302522),
        -INT32_C(  1091718615),  INT32_C(  1752425857),  INT32_C(  1125659689), -INT32_C(   328851849),  INT32_C(   374862479),  INT32_C(  1439095137), -INT32_C(  1730731171), -INT32_C(   241026360) },
      UINT16_C(37100),
      {  INT16_C( 28079),  INT16_C(  8821), -INT16_C( 24875), -INT16_C(  4778), -INT16_C( 12831),  INT16_C( 18188), -INT16_C( 25671),  INT16_C(  4153),
        -INT16_C( 25935),  INT16_C( 30697),  INT16_C( 18416), -INT16_C( 14438),  INT16_C( 25311), -INT16_C( 32510), -INT16_C(  4525),  INT16_C(   529),
        -INT16_C( 31140),  INT16_C( 12580),  INT16_C( 31268),  INT16_C(  1567),  INT16_C( 11080),  INT16_C(   333), -INT16_C( 30778),  INT16_C( 30482),
        -INT16_C(  1247),  INT16_C(  4590), -INT16_C( 30654),  INT16_C(  8665), -INT16_C(  9238),  INT16_C( 15779), -INT16_C( 19255),  INT16_C(  9535) },
      {  INT16_C( 25403),  INT16_C( 24407),  INT16_C( 30429),  INT16_C(  9573), -INT16_C( 19551),  INT16_C( 26407),  INT16_C( 14650),  INT16_C( 23518),
        -INT16_C( 13260),  INT16_C( 30573),  INT16_C( 18004),  INT16_C( 16024),  INT16_C( 15137), -INT16_C(  5509), -INT16_C( 17680),  INT16_C( 11024),
         INT16_C( 26397), -INT16_C(  1398), -INT16_C(  3875),  INT16_C( 32288),  INT16_C( 18339), -INT16_C(  8731), -INT16_C( 15488), -INT16_C( 19400),
        -INT16_C( 23153), -INT16_C(  7381), -INT16_C( 15125),  INT16_C(  3105), -INT16_C( 25345), -INT16_C(  4105),  INT16_C(  1878),  INT16_C( 29466) },
      { -INT32_C(   481327920), -INT32_C(  1242050667), -INT32_C(   598361796),  INT32_C(   292425586),  INT32_C(  1804365941), -INT32_C(  1233421897), -INT32_C(  1545570135),  INT32_C(   260136218),
        -INT32_C(  1091718615),  INT32_C(  1752425857),  INT32_C(  1125659689), -INT32_C(   328851849),  INT32_C(   369855480),  INT32_C(  1439095137), -INT32_C(  1730731171),  INT32_C(     3771060) } },
    { {  INT32_C(  1265476974),  INT32_C(   952733077),  INT32_C(  1410707156),  INT32_C(      609649), -INT32_C(   555535117), -INT32_C(   118815496), -INT32_C(   152575328),  INT32_C(  1466499817),
         INT32_C(  1017304743),  INT32_C(   947153764), -INT32_C(  1970435815), -INT32_C(   913664298), -INT32_C(  1012372022),  INT32_C(   297505649),  INT32_C(  1577558645),  INT32_C(  1270182052) },
      UINT16_C(22342),
      { -INT16_C( 21881), -INT16_C(  1086), -INT16_C(  9245),  INT16_C( 28804),  INT16_C( 23397), -INT16_C(  4346), -INT16_C( 12252), -INT16_C( 13220),
        -INT16_C( 12909),  INT16_C( 20063), -INT16_C( 11042), -INT16_C(  6671), -INT16_C( 27342), -INT16_C(  6315), -INT16_C( 25631),  INT16_C( 26686),
         INT16_C(    70),  INT16_C( 10596), -INT16_C(  5925),  INT16_C( 16537), -INT16_C( 24765),  INT16_C( 26671), -INT16_C( 29841),  INT16_C(   820),
        -INT16_C( 27560),  INT16_C( 13905),  INT16_C( 17000), -INT16_C( 25829),  INT16_C( 28888), -INT16_C( 18046), -INT16_C( 16116),  INT16_C( 21025) },
      { -INT16_C( 31295), -INT16_C( 25221),  INT16_C(  5230), -INT16_C( 20003),  INT16_C(  3507),  INT16_C(  8729),  INT16_C( 20120), -INT16_C(  3803),
         INT16_C( 30690),  INT16_C( 18983),  INT16_C( 17337), -INT16_C( 28187),  INT16_C( 26803), -INT16_C( 16566),  INT16_C( 27689), -INT16_C(  5615),
        -INT16_C( 29455),  INT16_C( 24455),  INT16_C( 26016),  INT16_C( 21265),  INT16_C( 10866),  INT16_C(  2678), -INT16_C( 25736),  INT16_C( 23291),
         INT16_C(  8978), -INT16_C( 13147), -INT16_C( 30106),  INT16_C(  6493), -INT16_C( 22286),  INT16_C(  7129), -INT16_C(  5612),  INT16_C(  1286) },
      {  INT32_C(  1265476974),  INT32_C(   328215315),  INT32_C(  1454824201),  INT32_C(      609649), -INT32_C(   555535117), -INT32_C(   118815496), -INT32_C(   780808664),  INT32_C(  1466499817),
         INT32_C(  1274368073),  INT32_C(  1144668269),              INT32_MIN, -INT32_C(   913664298), -INT32_C(  1442614737),  INT32_C(   297505649),  INT32_C(   805110743),  INT32_C(  1270182052) } },
    { {  INT32_C(   392531319),  INT32_C(  1684764402),  INT32_C(   426762656), -INT32_C(  1888261508), -INT32_C(   212133747), -INT32_C(  1794262877),  INT32_C(  1957815904),  INT32_C(  1199224784),
         INT32_C(   929029956), -INT32_C(   174339499),  INT32_C(   655231659),  INT32_C(    45515381),  INT32_C(  1039536538),  INT32_C(   718472138), -INT32_C(  1180728087),  INT32_C(  2130778427) },
      UINT16_C(24824),
      {  INT16_C( 19894),  INT16_C( 21034), -INT16_C( 10942),  INT16_C( 20828), -INT16_C( 11780), -INT16_C( 19501),  INT16_C( 28116), -INT16_C( 13628),
        -INT16_C( 29013),  INT16_C( 32461), -INT16_C( 18759),  INT16_C( 22530),  INT16_C( 15727),  INT16_C( 28785),  INT16_C( 27068),  INT16_C( 29648),
        -INT16_C(  1354), -INT16_C(  1851),  INT16_C(  8655), -INT16_C( 13239),  INT16_C(  7411), -INT16_C( 14465),  INT16_C( 17290),  INT16_C( 13713),
         INT16_C( 24274), -INT16_C( 29773), -INT16_C( 19180), -INT16_C( 31773),  INT16_C( 21746), -INT16_C( 20748), -INT16_C( 15171),  INT16_C( 29473) },
      { -INT16_C(  6465), -INT16_C( 29077), -INT16_C( 19192), -INT16_C(  1190), -INT16_C(  9775),  INT16_C( 23490),  INT16_C( 21277), -INT16_C(  4208),
         INT16_C( 17329), -INT16_C( 14982),  INT16_C( 24056), -INT16_C(  5560),  INT16_C( 15537),  INT16_C( 28313), -INT16_C( 17919), -INT16_C( 16159),
         INT16_C( 19617), -INT16_C( 22194), -INT16_C( 22271), -INT16_C( 11356),  INT16_C( 26242), -INT16_C( 24786), -INT16_C( 16455),  INT16_C( 27278),
         INT16_C(  2050), -INT16_C(  1233),  INT16_C( 30565),  INT16_C(  5861),  INT16_C( 32436), -INT16_C( 19068),  INT16_C( 25913), -INT16_C(  9611) },
      {  INT32_C(   392531319),  INT32_C(  1684764402),  INT32_C(   426762656), -INT32_C(  1232690752), -INT32_C(  1201230726),              INT32_MIN,              INT32_MAX,  INT32_C(   235111260),
         INT32_C(   929029956), -INT32_C(   174339499),  INT32_C(   655231659),  INT32_C(    45515381),  INT32_C(  1039536538), -INT32_C(    53986115), -INT32_C(    79751967),  INT32_C(  2130778427) } },
    { { -INT32_C(  1283210318), -INT32_C(   276420756),  INT32_C(  1183757709),  INT32_C(  1991253364), -INT32_C(  1955471579),  INT32_C(   178345814),  INT32_C(   247408341),  INT32_C(  1038627979),
         INT32_C(  1693543416),  INT32_C(   525563794), -INT32_C(  1603935700),  INT32_C(   605492735),  INT32_C(  1269795060), -INT32_C(  1252699681),  INT32_C(    46339447),  INT32_C(  1094757449) },
      UINT16_C(12567),
      { -INT16_C( 21850), -INT16_C(  1624), -INT16_C( 10807),  INT16_C( 12251), -INT16_C(  9611), -INT16_C( 29628),  INT16_C( 14847), -INT16_C( 20971),
        -INT16_C(  2940), -INT16_C(  9729),  INT16_C( 30377),  INT16_C( 28142),  INT16_C( 14457), -INT16_C( 18151),  INT16_C( 12409),  INT16_C(  8170),
        -INT16_C( 27942), -INT16_C( 23527), -INT16_C(  2969), -INT16_C(  8749),  INT16_C(  6095), -INT16_C( 12695),  INT16_C( 32336), -INT16_C( 11140),
         INT16_C( 31859),  INT16_C(  7342), -INT16_C( 25358),  INT16_C( 27529), -INT16_C( 23852),  INT16_C( 20004),  INT16_C(  3795), -INT16_C( 21139) },
      { -INT16_C( 31071),  INT16_C(  2129),  INT16_C(  9339),  INT16_C( 19173),  INT16_C( 20284), -INT16_C( 29672), -INT16_C( 27443),  INT16_C( 16481),
         INT16_C(  3856),  INT16_C(   861), -INT16_C(  6485), -INT16_C( 32658), -INT16_C( 27767),  INT16_C( 23758),  INT16_C( 15265),  INT16_C( 16905),
         INT16_C( 23490),  INT16_C( 15691),  INT16_C( 12415), -INT16_C( 17529), -INT16_C( 24705),  INT16_C( 19784), -INT16_C( 22221),  INT16_C( 17549),
        -INT16_C(  5448),  INT16_C( 25415), -INT16_C( 18991),  INT16_C( 23267), -INT16_C( 20152), -INT16_C(  5450), -INT16_C( 16403), -INT16_C( 20692) },
      { -INT32_C(   607766464), -INT32_C(   142458906),  INT32_C(  1867930201),  INT32_C(  1991253364), -INT32_C(  1975184888),  INT32_C(   178345814),  INT32_C(   247408341),  INT32_C(  1038627979),
         INT32_C(   668023679),  INT32_C(   525563794), -INT32_C(  1603935700),  INT32_C(   605492735),  INT32_C(  1282824158), -INT32_C(   130608660),  INT32_C(    46339447),  INT32_C(  1094757449) } },
    { { -INT32_C(  1695779046),  INT32_C(   659911592),  INT32_C(  1165270290), -INT32_C(    24575418), -INT32_C(  1117597460), -INT32_C(   837335674), -INT32_C(   457650697), -INT32_C(  1483479667),
         INT32_C(    71401308),  INT32_C(    70031346),  INT32_C(  2068422708), -INT32_C(  1887841374),  INT32_C(   692902819),  INT32_C(   418931745), -INT32_C(  1090736079), -INT32_C(   228159595) },
      UINT16_C(42766),
      {  INT16_C(   246),  INT16_C(  8766),  INT16_C( 29444),  INT16_C( 19907),  INT16_C( 26094),  INT16_C( 26400), -INT16_C( 15116),  INT16_C( 16707),
         INT16_C( 25837), -INT16_C(  6747), -INT16_C( 10628),  INT16_C( 30870),  INT16_C( 11157), -INT16_C(  1273),  INT16_C(  5405),  INT16_C(  5282),
        -INT16_C(  7915),  INT16_C(  6454), -INT16_C(  1708),  INT16_C( 16998), -INT16_C( 30881),  INT16_C( 21417), -INT16_C(  5045),  INT16_C( 14484),
         INT16_C( 14672), -INT16_C( 13282), -INT16_C( 19440), -INT16_C( 23228),  INT16_C( 19423), -INT16_C(   608),  INT16_C( 16992),  INT16_C( 29969) },
      {  INT16_C( 18211),  INT16_C( 30606), -INT16_C(  2751), -INT16_C( 24391),  INT16_C( 25468), -INT16_C( 14349), -INT16_C( 30641), -INT16_C( 24321),
         INT16_C(  7617), -INT16_C( 11924), -INT16_C( 20015), -INT16_C( 20106),  INT16_C(  5884),  INT16_C( 23982), -INT16_C( 16551),  INT16_C( 31954),
         INT16_C( 24838),  INT16_C( 18420), -INT16_C( 21162), -INT16_C( 11545), -INT16_C(  9456),  INT16_C( 24729), -INT16_C( 26525),  INT16_C(  9216),
         INT16_C( 27830), -INT16_C( 30730),  INT16_C( 27677),  INT16_C(  6712), -INT16_C(  6525), -INT16_C(  9097),  INT16_C( 18853), -INT16_C( 21416) },
      { -INT32_C(  1695779046),  INT32_C(    93359511),  INT32_C(  1451018682),  INT32_C(    32262991), -INT32_C(  1117597460), -INT32_C(   837335674), -INT32_C(   457650697), -INT32_C(  1483479667),
        -INT32_C(     6308782), -INT32_C(    90065868),              INT32_MAX, -INT32_C(  1887841374),  INT32_C(   692902819), -INT32_C(   275015471), -INT32_C(  1090736079), -INT32_C(   549625523) } },
    { {  INT32_C(    15944874),  INT32_C(   181591034),  INT32_C(   426404790), -INT32_C(  1170380284), -INT32_C(   197053481),  INT32_C(   588151456),  INT32_C(   117409120),  INT32_C(  2041731023),
        -INT32_C(  1636129372),  INT32_C(   916999296), -INT32_C(  1135668296),  INT32_C(  1417055613),  INT32_C(  1615443904), -INT32_C(  1836886223), -INT32_C(  1399291171),  INT32_C(  2116373210) },
      UINT16_C(40943),
      {  INT16_C( 28700), -INT16_C( 15124), -INT16_C( 23386), -INT16_C(  2345),  INT16_C( 21856), -INT16_C( 10621),  INT16_C( 17321), -INT16_C(  3443),
        -INT16_C( 16476),  INT16_C( 10058),  INT16_C( 10065), -INT16_C(  5718), -INT16_C( 31533), -INT16_C(  1997),  INT16_C(  8706),  INT16_C(  7832),
        -INT16_C( 31598),  INT16_C( 14818), -INT16_C( 17880), -INT16_C( 30673), -INT16_C( 19953), -INT16_C( 18338), -INT16_C(  5131), -INT16_C( 26197),
        -INT16_C(  2646), -INT16_C(  1087),  INT16_C( 27420), -INT16_C(  4124),  INT16_C(  6127), -INT16_C(  3609),  INT16_C( 32570), -INT16_C( 13297) },
      { -INT16_C(  3837),  INT16_C( 11013),  INT16_C( 13483), -INT16_C( 17741),  INT16_C(  4582), -INT16_C(  9101),  INT16_C(  7933), -INT16_C( 22667),
         INT16_C( 13843),  INT16_C( 12195), -INT16_C( 30815), -INT16_C( 28642),  INT16_C(  1439), -INT16_C(  9855), -INT16_C( 28539), -INT16_C( 30555),
        -INT16_C( 21630),  INT16_C( 11700),  INT16_C( 26591), -INT16_C( 14616),  INT16_C( 23417),  INT16_C( 30370),  INT16_C(  6009), -INT16_C( 29667),
        -INT16_C( 16306), -INT16_C(  4165), -INT16_C(  9912), -INT16_C(  6272),  INT16_C(   478),  INT16_C( 25536),  INT16_C( 26002),  INT16_C(  5356) },
      { -INT32_C(   260737638), -INT32_C(    92119759),  INT32_C(   623210703), -INT32_C(   954930310), -INT32_C(   197053481),  INT32_C(   441773437),  INT32_C(    91713568),  INT32_C(  1553963729),
        -INT32_C(   779294032),  INT32_C(   889868784),              INT32_MIN,              INT32_MAX,  INT32_C(  1663116935), -INT32_C(  1836886223), -INT32_C(  1399291171),              INT32_MAX } },
    { { -INT32_C(   264134640), -INT32_C(  2135545593), -INT32_C(    34187132), -INT32_C(  1115089809),  INT32_C(   481117396), -INT32_C(    66900707), -INT32_C(  1067465938),  INT32_C(   970214185),
        -INT32_C(   215410965), -INT32_C(   999039169), -INT32_C(  1480496585),  INT32_C(  1382304638), -INT32_C(  1385229937),  INT32_C(  1839821374),  INT32_C(  1596786742),  INT32_C(  1066926676) },
      UINT16_C(49688),
      {  INT16_C( 22322), -INT16_C( 22879), -INT16_C(  9957), -INT16_C(  8944), -INT16_C( 29056), -INT16_C(  7128), -INT16_C( 18464),  INT16_C( 20470),
         INT16_C( 13412),  INT16_C(  3522), -INT16_C(  1887), -INT16_C( 12522),  INT16_C( 27223), -INT16_C(  4143), -INT16_C(  5719), -INT16_C(  9039),
         INT16_C( 21312),  INT16_C( 23682), -INT16_C( 28116), -INT16_C( 21447),  INT16_C( 24864),  INT16_C(   144), -INT16_C( 31208),  INT16_C( 32080),
         INT16_C(  4795),  INT16_C( 23690), -INT16_C( 24566),  INT16_C( 24875), -INT16_C(  1014), -INT16_C( 19376),  INT16_C(   741),  INT16_C(  9872) },
      {  INT16_C(  4693), -INT16_C( 32382), -INT16_C( 17500), -INT16_C( 15315), -INT16_C( 17124),  INT16_C( 13508),  INT16_C(  5188), -INT16_C(    79),
         INT16_C( 15398),  INT16_C( 12379), -INT16_C( 30756), -INT16_C(  6255), -INT16_C(  7549),  INT16_C( 27035),  INT16_C( 11236),  INT16_C( 14735),
         INT16_C(  4413), -INT16_C(  7750), -INT16_C(  6196), -INT16_C(  5979),  INT16_C( 27044), -INT16_C(  6116), -INT16_C( 12674), -INT16_C( 23321),
         INT16_C( 17162), -INT16_C(  6443),  INT16_C( 26314),  INT16_C( 19917),  INT16_C( 26696),  INT16_C( 11446),  INT16_C( 17811), -INT16_C( 12187) },
      { -INT32_C(   264134640), -INT32_C(  2135545593), -INT32_C(    34187132), -INT32_C(  1212498171),  INT32_C(   731234210), -INT32_C(    66900707), -INT32_C(  1067465938),  INT32_C(   970214185),
        -INT32_C(   215410965), -INT32_C(   696600820), -INT32_C(  1480496585),  INT32_C(  1382304638), -INT32_C(  1385229937),  INT32_C(  1839821374),  INT32_C(  1347939302),  INT32_C(   959814563) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_dpwssds_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i b = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_mask_dpwssds_epi32(src, k, a, b);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_dpwssds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t src[16];
    const int16_t a[32];
    const int16_t b[32];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C( 8022),
      {  INT32_C(  1443242673),  INT32_C(   666938122),  INT32_C(  2079669907), -INT32_C(  1212219422), -INT32_C(  1289844507), -INT32_C(  1944361259), -INT32_C(   120475757),  INT32_C(   823666815),
         INT32_C(  1434918474),  INT32_C(  1568425929),  INT32_C(  1759015301),  INT32_C(  1428133488), -INT32_C(   217563874),  INT32_C(   931079332),  INT32_C(  1378832851), -INT32_C(  1014806663) },
      {  INT16_C(  2918),  INT16_C( 12056), -INT16_C( 27566), -INT16_C( 10100),  INT16_C( 25605),  INT16_C( 30016),  INT16_C( 24570),  INT16_C(  6347),
        -INT16_C( 11363),  INT16_C( 16652), -INT16_C( 29705), -INT16_C( 13704), -INT16_C( 22564),  INT16_C( 21789), -INT16_C( 24337),  INT16_C( 21785),
         INT16_C( 12715), -INT16_C(   380),  INT16_C(  4550), -INT16_C( 13354),  INT16_C(  5749),  INT16_C( 28737),  INT16_C(  3189),  INT16_C(  4744),
        -INT16_C( 27425), -INT16_C( 10413), -INT16_C( 13536), -INT16_C(   863), -INT16_C( 16781),  INT16_C( 25170),  INT16_C( 27487),  INT16_C(  2743) },
      {  INT16_C( 15260),  INT16_C( 25096), -INT16_C(  8628), -INT16_C( 15826),  INT16_C( 28660),  INT16_C( 27186), -INT16_C( 17797),  INT16_C( 23164),
        -INT16_C( 12209),  INT16_C( 28465), -INT16_C( 11365),  INT16_C(  3691), -INT16_C( 17007), -INT16_C(  3984),  INT16_C( 10024), -INT16_C( 14853),
         INT16_C(   867), -INT16_C( 20697),  INT16_C( 21986), -INT16_C( 10639), -INT16_C( 23612),  INT16_C( 16192), -INT16_C( 17058), -INT16_C( 21094),
        -INT16_C( 13427),  INT16_C( 10268), -INT16_C( 30818),  INT16_C( 12343), -INT16_C( 22715),  INT16_C( 27936),  INT16_C(  7119),  INT16_C( 12850) },
      {  INT32_C(           0),  INT32_C(  1064620170),              INT32_MAX,  INT32_C(           0), -INT32_C(   677114460),  INT32_C(           0),  INT32_C(   176462815),  INT32_C(           0),
         INT32_C(  1453807239),  INT32_C(  1810535435),  INT32_C(  2088579417),  INT32_C(  1273665590),  INT32_C(    43750917),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(23071),
      {  INT32_C(  1403978209),  INT32_C(   418804951),  INT32_C(  1305826483),  INT32_C(   488202753), -INT32_C(  1046104182),  INT32_C(   141159143), -INT32_C(  1977403305),  INT32_C(  1273250410),
         INT32_C(   463377219), -INT32_C(  1154247417), -INT32_C(   351794967), -INT32_C(   200793750), -INT32_C(  1061769767), -INT32_C(   272097385), -INT32_C(  1048974249),  INT32_C(  1913412910) },
      { -INT16_C( 21520), -INT16_C(  1907), -INT16_C( 16320),  INT16_C( 10675), -INT16_C( 17464),  INT16_C( 12820),  INT16_C(  7645), -INT16_C( 18906),
        -INT16_C(  9014),  INT16_C( 25206),  INT16_C( 16379),  INT16_C( 21073), -INT16_C( 13781),  INT16_C( 22803),  INT16_C(  8231),  INT16_C(  6091),
         INT16_C( 22731),  INT16_C(  2831), -INT16_C( 15848), -INT16_C(  8140),  INT16_C( 18814),  INT16_C( 23314),  INT16_C( 14694),  INT16_C( 12305),
        -INT16_C( 30955),  INT16_C(  4498), -INT16_C(  7226), -INT16_C(  3741),  INT16_C( 30637), -INT16_C( 11189),  INT16_C(  5783),  INT16_C( 25324) },
      { -INT16_C(  1169), -INT16_C( 30867), -INT16_C( 24130),  INT16_C( 15464),  INT16_C( 31466),  INT16_C( 20631), -INT16_C( 22349), -INT16_C( 13951),
         INT16_C(  4911), -INT16_C(  2342),  INT16_C( 15863), -INT16_C( 23321),  INT16_C( 12980),  INT16_C( 19321),  INT16_C( 25929), -INT16_C( 18259),
         INT16_C(  6752),  INT16_C(  7743), -INT16_C( 22596), -INT16_C( 22950), -INT16_C(  3806), -INT16_C( 10761),  INT16_C( 30873), -INT16_C( 13922),
         INT16_C( 30859), -INT16_C( 32065), -INT16_C( 22858),  INT16_C( 27175), -INT16_C( 24359),  INT16_C(  8886),  INT16_C( 25349),  INT16_C( 26074) },
      {  INT32_C(  1487998458),  INT32_C(   977684751),  INT32_C(  1020793679),  INT32_C(   581102254), -INT32_C(  1149404388),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   609333009),  INT32_C(           0),  INT32_C(    81543902),              INT32_MIN,  INT32_C(           0), -INT32_C(  1894686386),  INT32_C(           0) } },
    { UINT16_C( 6526),
      { -INT32_C(   557761916), -INT32_C(   674176032),  INT32_C(  1464822200), -INT32_C(   238036174), -INT32_C(  2070379171), -INT32_C(  1507560976),  INT32_C(  1829317011),  INT32_C(   327583631),
        -INT32_C(  1561245759), -INT32_C(   478559958),  INT32_C(  1564133675),  INT32_C(    21957028),  INT32_C(  2139547535), -INT32_C(   349853096),  INT32_C(  1666723540),  INT32_C(  2004278966) },
      {  INT16_C( 26406),  INT16_C( 20505), -INT16_C( 27863),  INT16_C( 21555),  INT16_C( 27996),  INT16_C(   177),  INT16_C(   119),  INT16_C(  1537),
        -INT16_C( 30745),  INT16_C( 16261), -INT16_C( 21966),  INT16_C(  1578), -INT16_C( 32040), -INT16_C( 29079), -INT16_C(  8351), -INT16_C( 30970),
         INT16_C(  8006),  INT16_C( 28631),  INT16_C(  2994),  INT16_C(  3779),  INT16_C( 30072), -INT16_C(  4338),  INT16_C(  4213),  INT16_C( 24053),
         INT16_C( 31383), -INT16_C( 13924), -INT16_C( 14556), -INT16_C(   561),  INT16_C( 14409), -INT16_C( 21877), -INT16_C( 28393),  INT16_C( 24113) },
      {  INT16_C(  2481),  INT16_C( 25549), -INT16_C( 28396), -INT16_C( 29582), -INT16_C( 32762),  INT16_C( 31612),  INT16_C( 29072),  INT16_C( 10456),
         INT16_C( 30188),  INT16_C(  4337), -INT16_C( 16068), -INT16_C( 31475), -INT16_C( 26119),  INT16_C(  4400),  INT16_C( 24874), -INT16_C(  9361),
         INT16_C( 15466),  INT16_C( 32319), -INT16_C( 20019), -INT16_C( 11509), -INT16_C( 30927), -INT16_C( 15793),  INT16_C( 10232), -INT16_C(  6934),
        -INT16_C(  9316), -INT16_C(  9995),  INT16_C(   668), -INT16_C( 27042), -INT16_C( 29029), -INT16_C( 14681),  INT16_C(  5871),  INT16_C( 23201) },
      {  INT32_C(           0), -INT32_C(   520618294),  INT32_C(   553212572), -INT32_C(   218505734),              INT32_MIN, -INT32_C(  1204278838),              INT32_MAX,  INT32_C(           0),
        -INT32_C(   512099674),  INT32_C(           0),  INT32_C(           0), -INT32_C(   101719058),  INT32_C(  1986353887),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(57426),
      { -INT32_C(   477028136),  INT32_C(  1114293235),  INT32_C(  1869243269),  INT32_C(  1011484231),  INT32_C(  1027598303),  INT32_C(   617339517),  INT32_C(  1111145120), -INT32_C(   316503020),
        -INT32_C(  1596934996), -INT32_C(    52282505), -INT32_C(   445952866),  INT32_C(   841135443),  INT32_C(   426729884), -INT32_C(   599967173),  INT32_C(   152991732), -INT32_C(  1326039036) },
      { -INT16_C( 14604),  INT16_C( 27472),  INT16_C( 13057), -INT16_C( 24729), -INT16_C( 11649), -INT16_C( 11643), -INT16_C( 22648),  INT16_C(  9220),
         INT16_C( 29448),  INT16_C( 17214),  INT16_C( 31661), -INT16_C( 24033),  INT16_C( 15859), -INT16_C(  2133), -INT16_C( 24194),  INT16_C( 29351),
        -INT16_C(  1945),  INT16_C( 27102),  INT16_C( 17707), -INT16_C( 22008), -INT16_C( 29416), -INT16_C( 24451), -INT16_C( 32460),  INT16_C( 15556),
         INT16_C(   757), -INT16_C( 23936), -INT16_C( 24706),  INT16_C( 28996), -INT16_C(  4131),  INT16_C( 23400),  INT16_C(  3984), -INT16_C(  1843) },
      { -INT16_C( 21753),  INT16_C( 12897),  INT16_C( 27121),  INT16_C(  2525),  INT16_C( 23287),  INT16_C( 11177),  INT16_C( 28123), -INT16_C( 12184),
        -INT16_C(  6032), -INT16_C(  4493), -INT16_C( 18553),  INT16_C( 25695), -INT16_C( 14425),  INT16_C( 14271), -INT16_C( 29226), -INT16_C(  8657),
        -INT16_C( 28616),  INT16_C( 10512), -INT16_C(  4614), -INT16_C(  3790), -INT16_C(  9401),  INT16_C(  8988), -INT16_C( 31671), -INT16_C( 17933),
         INT16_C( 26220), -INT16_C(  2905),  INT16_C(  1566), -INT16_C( 15016),  INT16_C(  6349), -INT16_C( 23556),  INT16_C( 11429), -INT16_C(  8831) },
      {  INT32_C(           0),  INT32_C(  1405971407),  INT32_C(           0),  INT32_C(           0),  INT32_C(   772625465),  INT32_C(           0),  INT32_C(   851939002),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1074060705), -INT32_C(   424446387), -INT32_C(  1264230367) } },
    { UINT16_C(37564),
      {  INT32_C(   964670983), -INT32_C(  1005205593), -INT32_C(   582459670), -INT32_C(  1102793449),  INT32_C(    29647529),  INT32_C(   588878119), -INT32_C(  1236287948), -INT32_C(  1555559268),
         INT32_C(  1792853954),  INT32_C(  2016342414),  INT32_C(  1716942415), -INT32_C(   735798741),  INT32_C(   601286908), -INT32_C(  1371082887),  INT32_C(  1248106158),  INT32_C(  1693297826) },
      { -INT16_C( 13965),  INT16_C(   718), -INT16_C(   837),  INT16_C(  2682), -INT16_C( 12173), -INT16_C( 24975), -INT16_C( 27286),  INT16_C( 26227),
         INT16_C( 18814), -INT16_C(  2167), -INT16_C( 12232), -INT16_C(  6491),  INT16_C(  2406),  INT16_C(  2096),  INT16_C(  7605),  INT16_C( 10604),
         INT16_C( 15335), -INT16_C( 24021), -INT16_C( 23241), -INT16_C( 21844),  INT16_C(  7542), -INT16_C(  8119), -INT16_C( 17229),  INT16_C( 12615),
        -INT16_C( 12283),  INT16_C( 15656), -INT16_C( 12640),  INT16_C(  1572),  INT16_C( 21719), -INT16_C( 29426),  INT16_C( 31602),  INT16_C( 22966) },
      { -INT16_C(  7754), -INT16_C(  4613), -INT16_C( 22650), -INT16_C(   872), -INT16_C(  7739),  INT16_C( 30941),  INT16_C(  9373), -INT16_C( 23895),
        -INT16_C( 11788), -INT16_C( 27169),  INT16_C(   927),  INT16_C( 30619), -INT16_C( 21928), -INT16_C( 13820), -INT16_C( 17883), -INT16_C(  9437),
         INT16_C(  7835),  INT16_C(  8648),  INT16_C( 24773), -INT16_C( 30178), -INT16_C(  1215), -INT16_C(  8702), -INT16_C( 21729),  INT16_C(  4992),
         INT16_C( 24701),  INT16_C(  7336),  INT16_C( 17507), -INT16_C( 17517), -INT16_C( 26642),  INT16_C(  4997), -INT16_C( 22447), -INT16_C(  4882) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1261004298), -INT32_C(  1985239292), -INT32_C(   133256680),  INT32_C(   378791126),  INT32_C(           0), -INT32_C(  1791629431),
         INT32_C(           0),  INT32_C(  2099801353),  INT32_C(           0),  INT32_C(           0),  INT32_C(   412736941),  INT32_C(           0),  INT32_C(           0),  INT32_C(   871807720) } },
    { UINT16_C(46790),
      {  INT32_C(   739740686),  INT32_C(   422008854), -INT32_C(  1211873737),  INT32_C(    35078489), -INT32_C(   247039138), -INT32_C(  1131858890),  INT32_C(   895801927), -INT32_C(   706008121),
        -INT32_C(   855571785), -INT32_C(  1830410149), -INT32_C(   951473298),  INT32_C(  1254711788),  INT32_C(   305926108), -INT32_C(  1966160573),  INT32_C(  1723806623),  INT32_C(   356232030) },
      {  INT16_C( 15533),  INT16_C(  2274), -INT16_C( 13980), -INT16_C( 11622), -INT16_C(  7052),  INT16_C( 24730),  INT16_C( 25413),  INT16_C(  8619),
        -INT16_C(  6285), -INT16_C( 18893),  INT16_C(   684),  INT16_C( 19265),  INT16_C(    53), -INT16_C( 27726), -INT16_C(  4693),  INT16_C( 22952),
        -INT16_C( 30166), -INT16_C( 29087), -INT16_C(   941), -INT16_C( 14495), -INT16_C(  1056),  INT16_C(  9512), -INT16_C( 11426), -INT16_C( 11962),
         INT16_C( 31162),  INT16_C( 26248), -INT16_C( 13957), -INT16_C( 20303),  INT16_C( 25545),  INT16_C( 30019), -INT16_C(  5295),  INT16_C( 31694) },
      {  INT16_C( 12150), -INT16_C( 14071),  INT16_C( 27179),  INT16_C(  2961), -INT16_C( 18075), -INT16_C( 15312),  INT16_C( 30348),  INT16_C( 18069),
         INT16_C(  7664),  INT16_C( 27564),  INT16_C( 24038), -INT16_C( 20452),  INT16_C( 24513),  INT16_C(  4645), -INT16_C(  3253), -INT16_C( 15987),
        -INT16_C( 27102),  INT16_C( 20106),  INT16_C(  6913),  INT16_C( 26201), -INT16_C( 29996),  INT16_C( 24618), -INT16_C( 16384), -INT16_C(  3930),
         INT16_C( 21213), -INT16_C( 15268),  INT16_C( 30896),  INT16_C( 29044), -INT16_C( 26153),  INT16_C(  8835),  INT16_C(  4236), -INT16_C( 20765) },
      {  INT32_C(           0),  INT32_C(     7633692), -INT32_C(  1463074597),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   768313846), -INT32_C(  1057675416),
         INT32_C(           0),              INT32_MIN, -INT32_C(   685631106),  INT32_C(           0),  INT32_C(   566211150),              INT32_MIN,  INT32_C(           0), -INT32_C(   324323500) } },
    { UINT16_C(28326),
      {  INT32_C(  1451862012),  INT32_C(   954228238),  INT32_C(  1710809278),  INT32_C(   767022801),  INT32_C(   245720986),  INT32_C(  1537703128), -INT32_C(  2106903649), -INT32_C(   554691871),
        -INT32_C(   952862023), -INT32_C(  1778379560), -INT32_C(   973342476),  INT32_C(  1760736206), -INT32_C(   210331878), -INT32_C(  1286726380),  INT32_C(   842381904), -INT32_C(  2062539060) },
      {  INT16_C( 17568),  INT16_C( 30797),  INT16_C( 19800),  INT16_C( 19470),  INT16_C(  2629),  INT16_C(  5138),  INT16_C(  1213), -INT16_C( 10372),
        -INT16_C(  3172), -INT16_C( 20278),  INT16_C(  6416),  INT16_C( 24931), -INT16_C( 26413), -INT16_C( 24685), -INT16_C( 23618),  INT16_C( 24100),
         INT16_C( 29159),  INT16_C( 16342), -INT16_C(  6722),  INT16_C(  1163), -INT16_C( 25105), -INT16_C( 21480), -INT16_C( 27486),  INT16_C( 16003),
         INT16_C( 20103), -INT16_C( 26386),  INT16_C( 20839),  INT16_C( 15097), -INT16_C( 29463), -INT16_C( 22311), -INT16_C(   721),  INT16_C(  5638) },
      { -INT16_C(  8849),  INT16_C( 11605), -INT16_C(  7998), -INT16_C( 20175),  INT16_C( 18814),  INT16_C(  8285), -INT16_C(  7970),  INT16_C( 25950),
         INT16_C( 19502), -INT16_C( 27139), -INT16_C(  2403), -INT16_C( 31025), -INT16_C( 22398), -INT16_C( 20178),  INT16_C( 13734),  INT16_C(  5575),
         INT16_C(  7186), -INT16_C( 11198),  INT16_C( 29949),  INT16_C( 31621), -INT16_C(  7491), -INT16_C( 25701), -INT16_C(  1598), -INT16_C(  3839),
        -INT16_C(   443), -INT16_C(  7546),  INT16_C( 22261),  INT16_C( 30568), -INT16_C( 26626), -INT16_C( 23511), -INT16_C(  3892), -INT16_C(  8519) },
      {  INT32_C(           0),  INT32_C(   403060588),  INT32_C(  1802839614),  INT32_C(           0),  INT32_C(           0),  INT32_C(   748801205),  INT32_C(           0), -INT32_C(   744703983),
         INT32_C(           0), -INT32_C(  1942921515), -INT32_C(   233223441),  INT32_C(  1743223317),  INT32_C(           0), -INT32_C(   361344305),              INT32_MAX,  INT32_C(           0) } },
    { UINT16_C(64525),
      {  INT32_C(   930089650),  INT32_C(   538520965), -INT32_C(   904274999),  INT32_C(  1405640396), -INT32_C(  1465270976),  INT32_C(  1581229877),  INT32_C(    89000780), -INT32_C(  1694409751),
        -INT32_C(   355307163),  INT32_C(  1745546143), -INT32_C(  1825430585), -INT32_C(  1041827199), -INT32_C(   311783496), -INT32_C(  2092193481), -INT32_C(  1635214923),  INT32_C(  1513786101) },
      {  INT16_C(  3323), -INT16_C( 26043),  INT16_C( 20472), -INT16_C( 16638),  INT16_C( 13427), -INT16_C(  2990),  INT16_C( 14639), -INT16_C(  6218),
         INT16_C(  8392), -INT16_C(    44),  INT16_C(  8137),  INT16_C( 32386),  INT16_C(  3000), -INT16_C( 21219),  INT16_C( 22421), -INT16_C( 28664),
         INT16_C( 19811),  INT16_C( 23339),  INT16_C( 11676),  INT16_C(  3866),  INT16_C( 28002), -INT16_C( 28412), -INT16_C( 17754),  INT16_C( 28280),
         INT16_C( 19674), -INT16_C( 23698), -INT16_C(  3989),  INT16_C(  8994),  INT16_C( 16379), -INT16_C( 28463), -INT16_C(  9834), -INT16_C(  1759) },
      {  INT16_C( 19494), -INT16_C( 15787),  INT16_C( 28537), -INT16_C(  9262), -INT16_C( 10532), -INT16_C( 32148), -INT16_C(  7024),  INT16_C( 27377),
         INT16_C( 24368), -INT16_C( 25843),  INT16_C( 12111),  INT16_C( 19391), -INT16_C( 28562),  INT16_C(  1243), -INT16_C(   919), -INT16_C( 28674),
         INT16_C( 21320), -INT16_C( 15791),  INT16_C(  9154), -INT16_C( 24675),  INT16_C(  2809), -INT16_C( 30431),  INT16_C(  4846),  INT16_C(  8179),
         INT16_C(   369), -INT16_C( 15942),  INT16_C( 31024), -INT16_C( 24820), -INT16_C(  6391),  INT16_C( 29347), -INT16_C( 24092),  INT16_C( 11265) },
      {  INT32_C(  1406009053),  INT32_C(           0), -INT32_C(   949565643),  INT32_C(  1132585874),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0), -INT32_C(   882167395), -INT32_C(   896560963),  INT32_C(    73269726),              INT32_MIN,              INT32_MIN,  INT32_C(  1730891694) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi16(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi16(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_dpwssds_epi32(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i b = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_maskz_dpwssds_epi32(k, src, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dpwssds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_dpwssds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_dpwssds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_dpwssds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_dpwssds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_dpwssds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_dpwssds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_dpwssds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_dpwssds_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
