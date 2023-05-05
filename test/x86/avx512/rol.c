#define SIMDE_TEST_X86_AVX512_INSN rol

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/rol.h>

static int
test_simde_mm_rol_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   461711631),  INT32_C(   598395701),  INT32_C(  1437828868), -INT32_C(  1963631365) },
       INT32_C(           7),
      {  INT32_C(  1030453490), -INT32_C(   714761583), -INT32_C(   641498582),  INT32_C(  2058255813) } },
    { { -INT32_C(  1595134797), -INT32_C(  2006734372), -INT32_C(  1290464062),  INT32_C(   546803691) },
       INT32_C(          90),
      { -INT32_C(   830230350),  INT32_C(  1914801831),  INT32_C(   181163091), -INT32_C(  1400742337) } },
    { { -INT32_C(  1011550520),  INT32_C(  1498261842), -INT32_C(  1515942670), -INT32_C(  1790537543) },
       INT32_C(          58),
      {  INT32_C(   588174299),  INT32_C(  1231369893), -INT32_C(   896101837), -INT32_C(   430630334) } },
    { { -INT32_C(  1448070210),  INT32_C(   499730370),  INT32_C(  1367084425),  INT32_C(  1444229123) },
       INT32_C(         217),
      {  INT32_C(  2102616167), -INT32_C(  2076470641),  INT32_C(   312670235),  INT32_C(   111946336) } },
    { { -INT32_C(  1468967953),  INT32_C(   507361252),  INT32_C(   521821025),  INT32_C(  1355336334) },
       INT32_C(          18),
      {  INT32_C(  1337893317), -INT32_C(   544179978),  INT32_C(  1837399145),  INT32_C(   708395811) } },
    { { -INT32_C(  1561532002), -INT32_C(   201850599),  INT32_C(  1405069156), -INT32_C(   537186053) },
       INT32_C(         232),
      { -INT32_C(   320233822), -INT32_C(   134145549), -INT32_C(  1079548845), -INT32_C(    80675873) } },
    { {  INT32_C(   560469907), -INT32_C(   193842974),  INT32_C(  1620041665), -INT32_C(   503153719) },
       INT32_C(         125),
      {  INT32_C(  1680671474),  INT32_C(  1586382364),  INT32_C(   739376120),  INT32_C(  1010847609) } },
    { { -INT32_C(  1674275679), -INT32_C(  1384435771), -INT32_C(    67733401),  INT32_C(  1914461840) },
       INT32_C(         142),
      {  INT32_C(   623404813), -INT32_C(   873370786), -INT32_C(  1642463491),  INT32_C(   396631175) } },
  };

  simde__m128i a, r;

  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  r = simde_mm_rol_epi32(a, INT32_C(           7));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  r = simde_mm_rol_epi32(a, INT32_C(          90));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  r = simde_mm_rol_epi32(a, INT32_C(          58));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  r = simde_mm_rol_epi32(a, INT32_C(         217));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));
  #endif

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  r = simde_mm_rol_epi32(a, INT32_C(          18));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  r = simde_mm_rol_epi32(a, INT32_C(         232));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  r = simde_mm_rol_epi32(a, INT32_C(         125));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  r = simde_mm_rol_epi32(a, INT32_C(         142));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));
  #endif

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_rol_epi32, r, simde_mm_setzero_si128(), imm8, a);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_rol_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   934278510), -INT32_C(   317083280),  INT32_C(  1305407403),  INT32_C(  1223230083) },
      UINT8_C( 49),
      { -INT32_C(   577112731),  INT32_C(  1231918315),  INT32_C(  1071112112),  INT32_C(   984426309) },
       INT32_C(         214),
      {  INT32_C(  1500997245), -INT32_C(   317083280),  INT32_C(  1305407403),  INT32_C(  1223230083) } },
    { { -INT32_C(   332162819),  INT32_C(  1768980583), -INT32_C(   811878294), -INT32_C(  1716767570) },
      UINT8_C(200),
      { -INT32_C(   109518054), -INT32_C(   515917894),  INT32_C(  1220049252), -INT32_C(  1119469532) },
       INT32_C(         115),
      { -INT32_C(   332162819),  INT32_C(  1768980583), -INT32_C(   811878294),  INT32_C(    19262002) } },
    { {  INT32_C(  1532923298),  INT32_C(  1544105256), -INT32_C(   215702823),  INT32_C(  1089314181) },
      UINT8_C( 84),
      { -INT32_C(  1514594004),  INT32_C(   432669145),  INT32_C(  2056095559),  INT32_C(   941392299) },
       INT32_C(         223),
      {  INT32_C(  1532923298),  INT32_C(  1544105256), -INT32_C(  1119435869),  INT32_C(  1089314181) } },
    { {  INT32_C(   602258816),  INT32_C(  2141772258), -INT32_C(   220993338), -INT32_C(   476607478) },
      UINT8_C(142),
      { -INT32_C(   388629151),  INT32_C(   194203530), -INT32_C(   471151508), -INT32_C(   362482131) },
       INT32_C(         219),
      {  INT32_C(   602258816),  INT32_C(  1348246140),  INT32_C(  1730106979),  INT32_C(  1867720625) } },
    { {  INT32_C(   410667823), -INT32_C(  1423807457),  INT32_C(  1698235652), -INT32_C(  1941041406) },
      UINT8_C( 94),
      { -INT32_C(  1379231775),  INT32_C(  2010820225), -INT32_C(  1722563310), -INT32_C(   574093423) },
       INT32_C(         130),
      {  INT32_C(   410667823), -INT32_C(   546653691),  INT32_C(  1699681354),  INT32_C(  1998593607) } },
    { {  INT32_C(   150120194), -INT32_C(   267757343), -INT32_C(  2024892506), -INT32_C(  1338697426) },
      UINT8_C(199),
      { -INT32_C(   723966193), -INT32_C(  2107215238),  INT32_C(   453264186), -INT32_C(   434245057) },
       INT32_C(         229),
      { -INT32_C(  1692081670),  INT32_C(  1288589136),  INT32_C(  1619552067), -INT32_C(  1338697426) } },
    { { -INT32_C(   941377744),  INT32_C(   536177158), -INT32_C(  1343838817),  INT32_C(  1199816653) },
      UINT8_C( 49),
      {  INT32_C(   745261545), -INT32_C(  1066694963), -INT32_C(   911912284), -INT32_C(   772152807) },
       INT32_C(         197),
      { -INT32_C(  1921434331),  INT32_C(   536177158), -INT32_C(  1343838817),  INT32_C(  1199816653) } },
    { {  INT32_C(  1540355766), -INT32_C(  1691844900), -INT32_C(   338923519),  INT32_C(   118961977) },
      UINT8_C(190),
      { -INT32_C(   714946685),  INT32_C(  1324231532), -INT32_C(   451690715), -INT32_C(  1935981930) },
       INT32_C(          17),
      {  INT32_C(  1540355766),  INT32_C(  1457036764),  INT32_C(  2118896167), -INT32_C(  2060641994) } },
   { { -INT32_C(  1440149080), -INT32_C(  1834033526),  INT32_C(  2034518563), -INT32_C(   499314856) },
      UINT8_C( 37),
      { -INT32_C(   444251277), -INT32_C(   343596048), -INT32_C(  1962280208),  INT32_C(   791930398) },
       INT32_C(          15),
      { -INT32_C(  1581649214), -INT32_C(  1834033526), -INT32_C(    42449532), -INT32_C(   499314856) } },
    { { -INT32_C(   720286837), -INT32_C(  1641117041),  INT32_C(  1002705095),  INT32_C(  1142966611) },
      UINT8_C(109),
      { -INT32_C(  1604505690),  INT32_C(   532605241), -INT32_C(    97587684), -INT32_C(   209380441) },
       INT32_C(          12),
      { -INT32_C(   755340795), -INT32_C(  1641117041), -INT32_C(   287191134),  INT32_C(  1371176760) } },
    { { -INT32_C(  1719787127),  INT32_C(   787266021), -INT32_C(  2137313062), -INT32_C(  1725892256) },
      UINT8_C(226),
      { -INT32_C(   855721762),  INT32_C(    24443110), -INT32_C(   651270274),  INT32_C(   174253545) },
       INT32_C(           3),
      { -INT32_C(  1719787127),  INT32_C(   195544880), -INT32_C(  2137313062), -INT32_C(  1725892256) } },
    { {  INT32_C(   418848487), -INT32_C(  1300727879),  INT32_C(  1972638103), -INT32_C(  1354591287) },
      UINT8_C(139),
      {  INT32_C(   487174326), -INT32_C(  1022958882),  INT32_C(  1059524932),  INT32_C(   505889792) },
       INT32_C(          27),
      { -INT32_C(  1326953083), -INT32_C(   166185194),  INT32_C(  1972638103),  INT32_C(    15809056) } },
    { { -INT32_C(   934704457), -INT32_C(  1299071457), -INT32_C(  1237499904), -INT32_C(   808237072) },
      UINT8_C( 41),
      { -INT32_C(   345074982), -INT32_C(    34886215),  INT32_C(   322439892),  INT32_C(  1825237730) },
       INT32_C(          19),
      { -INT32_C(  1764271244), -INT32_C(  1299071457), -INT32_C(  1237499904),  INT32_C(  1460889175) } },
    { {  INT32_C(  1676819747), -INT32_C(  1034638981),  INT32_C(  1458250620),  INT32_C(  1866553781) },
      UINT8_C(  7),
      {  INT32_C(   937126957), -INT32_C(  1894125659),  INT32_C(  1287882169),  INT32_C(  1315943697) },
       INT32_C(           7),
      { -INT32_C(   306833765), -INT32_C(  1929915705),  INT32_C(  1640160422),  INT32_C(  1866553781) } },
    { {  INT32_C(  1254984487), -INT32_C(   788585609), -INT32_C(  1831375259), -INT32_C(  2134264869) },
      UINT8_C(162),
      {  INT32_C(  1734021090), -INT32_C(  2022135854), -INT32_C(   365967593),  INT32_C(   470908816) },
       INT32_C(          12),
      {  INT32_C(  1254984487), -INT32_C(  1971509129), -INT32_C(  1831375259), -INT32_C(  2134264869) } },
  };

  simde__m128i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm_loadu_epi32(test_vec[0].src);
  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[0].k, a, INT32_C(         214));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  src = simde_x_mm_loadu_epi32(test_vec[1].src);
  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[1].k, a, INT32_C(         115));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  src = simde_x_mm_loadu_epi32(test_vec[2].src);
  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[2].k, a, INT32_C(         223));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  src = simde_x_mm_loadu_epi32(test_vec[3].src);
  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[3].k, a, INT32_C(         219));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  src = simde_x_mm_loadu_epi32(test_vec[4].src);
  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[4].k, a, INT32_C(         130));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  src = simde_x_mm_loadu_epi32(test_vec[5].src);
  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[5].k, a, INT32_C(         229));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  src = simde_x_mm_loadu_epi32(test_vec[6].src);
  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[6].k, a, INT32_C(         197));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));
  #endif

  src = simde_x_mm_loadu_epi32(test_vec[7].src);
  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[7].k, a, INT32_C(          17));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  src = simde_x_mm_loadu_epi32(test_vec[8].src);
  a = simde_x_mm_loadu_epi32(test_vec[8].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[8].k, a, INT32_C(          15));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[8].r));

  src = simde_x_mm_loadu_epi32(test_vec[9].src);
  a = simde_x_mm_loadu_epi32(test_vec[9].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[9].k, a, INT32_C(          12));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[9].r));

  src = simde_x_mm_loadu_epi32(test_vec[10].src);
  a = simde_x_mm_loadu_epi32(test_vec[10].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[10].k, a, INT32_C(          3));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[10].r));

  src = simde_x_mm_loadu_epi32(test_vec[11].src);
  a = simde_x_mm_loadu_epi32(test_vec[11].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[11].k, a, INT32_C(          27));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[11].r));

  src = simde_x_mm_loadu_epi32(test_vec[12].src);
  a = simde_x_mm_loadu_epi32(test_vec[12].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[12].k, a, INT32_C(          19));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[12].r));

  src = simde_x_mm_loadu_epi32(test_vec[13].src);
  a = simde_x_mm_loadu_epi32(test_vec[13].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[13].k, a, INT32_C(           7));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[13].r));

  src = simde_x_mm_loadu_epi32(test_vec[14].src);
  a = simde_x_mm_loadu_epi32(test_vec[14].a);
  r = simde_mm_mask_rol_epi32(src, test_vec[14].k, a, INT32_C(          12));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[14].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_rol_epi32, r, simde_mm_setzero_si128(), imm8, src, k, a);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_rol_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t imm8;
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C( 31),
      { -INT32_C(   812674813), -INT32_C(  1828206212), -INT32_C(  1760115248),  INT32_C(  1375988519) },
       INT32_C(         218),
      {  INT32_C(   255737412), -INT32_C(   229892315),  INT32_C(  1113348887), -INT32_C(  1656221780) } },
    { UINT8_C(100),
      { -INT32_C(   123326371),  INT32_C(   636467388), -INT32_C(   668463289),  INT32_C(  1733621918) },
       INT32_C(         255),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   334231645),  INT32_C(           0) } },
    { UINT8_C(254),
      { -INT32_C(   773133362), -INT32_C(  1256012739), -INT32_C(  1928165795), -INT32_C(   448132563) },
       INT32_C(         250),
      {  INT32_C(           0), -INT32_C(   153842928),  INT32_C(  1983138329), -INT32_C(  1214961624) } },
    { UINT8_C(151),
      {  INT32_C(  1502586629),  INT32_C(  1178701327),  INT32_C(  1024802898), -INT32_C(   293870038) },
       INT32_C(           9),
      {  INT32_C(   525208243), -INT32_C(  2095309172),  INT32_C(   713073786),  INT32_C(           0) } },
    { UINT8_C( 66),
      {  INT32_C(   592231641), -INT32_C(   829274463), -INT32_C(   137156273),  INT32_C(  1191587001) },
       INT32_C(         110),
      {  INT32_C(           0), -INT32_C(  1851231324),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 97),
      {  INT32_C(  1380505815),  INT32_C(   293753286), -INT32_C(  1645558560),  INT32_C(  1463684369) },
       INT32_C(         159),
      { -INT32_C(  1457230741),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(223),
      { -INT32_C(  1542684002),  INT32_C(  1676704457),  INT32_C(     3887656), -INT32_C(   339309158) },
       INT32_C(          16),
      { -INT32_C(  2103532532),  INT32_C(  2060018672),  INT32_C(  1378353211), -INT32_C(  1919226938) } },
    { UINT8_C(194),
      { -INT32_C(  1479547544), -INT32_C(   458002627), -INT32_C(  1165847752),  INT32_C(   428025503) },
       INT32_C(          22),
      {  INT32_C(           0), -INT32_C(   814142245),  INT32_C(           0),  INT32_C(           0) } },
  };

  simde__m128i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  r = simde_mm_maskz_rol_epi32(test_vec[0].k, a, INT32_C(         218));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  r = simde_mm_maskz_rol_epi32(test_vec[1].k, a, INT32_C(         255));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  r = simde_mm_maskz_rol_epi32(test_vec[2].k, a, INT32_C(         250));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));
  #endif

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  r = simde_mm_maskz_rol_epi32(test_vec[3].k, a, INT32_C(           9));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  r = simde_mm_maskz_rol_epi32(test_vec[4].k, a, INT32_C(         110));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  r = simde_mm_maskz_rol_epi32(test_vec[5].k, a, INT32_C(         159));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));
  #endif

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  r = simde_mm_maskz_rol_epi32(test_vec[6].k, a, INT32_C(          16));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  r = simde_mm_maskz_rol_epi32(test_vec[7].k, a, INT32_C(          22));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_rol_epi32, r, simde_mm_setzero_si128(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_rol_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t imm8;
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1866714094), -INT32_C(  1993392344),  INT32_C(   445331517),  INT32_C(  1967285379), -INT32_C(   635170106),  INT32_C(   285944226),  INT32_C(   651773711), -INT32_C(   238324989) },
       INT32_C(          62),
      { -INT32_C(  1680805125),  INT32_C(   575393738),  INT32_C(  1185074703), -INT32_C(   581920480), -INT32_C(  1232534351), -INT32_C(  2075997592), -INT32_C(   910798397), -INT32_C(    59581248) } },
    { { -INT32_C(  1947168691),  INT32_C(  1269136328), -INT32_C(  1514018593), -INT32_C(  1669339654),  INT32_C(   514689551), -INT32_C(   716863534),  INT32_C(   969281786),  INT32_C(  1822369566) },
       INT32_C(         183),
      {  INT32_C(   650508360), -INT32_C(   467283267),  INT32_C(  1876091124), -INT32_C(    45203470),  INT32_C(   126834373), -INT32_C(   378887485),  INT32_C(  2099045128), -INT32_C(  1892266093) } },
    { { -INT32_C(   372532214),  INT32_C(  2123336836), -INT32_C(  2128933262),  INT32_C(  1805633689),  INT32_C(  1245766735),  INT32_C(   327354100), -INT32_C(   444653010), -INT32_C(  1134201166) },
       INT32_C(          18),
      {  INT32_C(  1881909038),  INT32_C(   840038974),  INT32_C(   969540716),  INT32_C(   577089151), -INT32_C(  1858262781),  INT32_C(   466636300), -INT32_C(  2000972292), -INT32_C(   624234091) } },
    { {  INT32_C(   789919165), -INT32_C(   592433085),  INT32_C(  1212633337),  INT32_C(   697468724), -INT32_C(  1136913010), -INT32_C(   358499528),  INT32_C(  1134954289), -INT32_C(   170243016) },
       INT32_C(         129),
      {  INT32_C(  1579838330), -INT32_C(  1184866169), -INT32_C(  1869700622),  INT32_C(  1394937448),  INT32_C(  2021141277), -INT32_C(   716999055), -INT32_C(  2025058718), -INT32_C(   340486031) } },
    { {  INT32_C(   430036256),  INT32_C(  1516431653), -INT32_C(    24906640),  INT32_C(  1119534858), -INT32_C(  1423156102), -INT32_C(  1678847389), -INT32_C(  1601124065), -INT32_C(   647645767) },
       INT32_C(         139),
      {  INT32_C(   245956813),  INT32_C(   390671059),  INT32_C(   530810868), -INT32_C(   705146347),  INT32_C(  1659098457),  INT32_C(  1989352671), -INT32_C(  2042036988),  INT32_C(   766365387) } },
    { {  INT32_C(  1611290096),  INT32_C(  1398771017), -INT32_C(   963307188), -INT32_C(   663633547), -INT32_C(  1284284268), -INT32_C(   497875927),  INT32_C(  1153153465), -INT32_C(  1326076224) },
       INT32_C(           3),
      {  INT32_C(     5418883), -INT32_C(  1694733750),  INT32_C(   883477094), -INT32_C(  1014101074), -INT32_C(  1684339547),  INT32_C(   311959887),  INT32_C(   635293130), -INT32_C(  2018675195) } },
    { { -INT32_C(   643797107), -INT32_C(    23054711), -INT32_C(  1948839433), -INT32_C(  1707193743),  INT32_C(   142381646),  INT32_C(   189544523), -INT32_C(   356826650), -INT32_C(   835204287) },
       INT32_C(          59),
      {  INT32_C(  1858929532),  INT32_C(  1341456820), -INT32_C(  1134643057), -INT32_C(  1932397997),  INT32_C(  1883497618),  INT32_C(  1482318274),  INT32_C(   928373263),  INT32_C(   242335322) } },
    { {  INT32_C(    96618253), -INT32_C(   896493223),  INT32_C(   845533156), -INT32_C(  1405427359),  INT32_C(    12027673),  INT32_C(   166359752),  INT32_C(  2027364669),  INT32_C(   104628216) },
       INT32_C(         198),
      {  INT32_C(  1888600897), -INT32_C(  1540991374), -INT32_C(  1720452852),  INT32_C(   246962283),  INT32_C(   769771072),  INT32_C(  2057089538),  INT32_C(   902319966), -INT32_C(  1893728767) } },
  };

  simde__m256i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi32(test_vec[0].a);
  r = simde_mm256_rol_epi32(a, INT32_C(          62));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[0].r));

  a = simde_x_mm256_loadu_epi32(test_vec[1].a);
  r = simde_mm256_rol_epi32(a, INT32_C(         183));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[1].r));
  #endif

  a = simde_x_mm256_loadu_epi32(test_vec[2].a);
  r = simde_mm256_rol_epi32(a, INT32_C(          18));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[2].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi32(test_vec[3].a);
  r = simde_mm256_rol_epi32(a, INT32_C(         129));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[3].r));

  a = simde_x_mm256_loadu_epi32(test_vec[4].a);
  r = simde_mm256_rol_epi32(a, INT32_C(         139));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[4].r));
  #endif

  a = simde_x_mm256_loadu_epi32(test_vec[5].a);
  r = simde_mm256_rol_epi32(a, INT32_C(           3));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[5].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi32(test_vec[6].a);
  r = simde_mm256_rol_epi32(a, INT32_C(          59));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[6].r));

  a = simde_x_mm256_loadu_epi32(test_vec[7].a);
  r = simde_mm256_rol_epi32(a, INT32_C(         198));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[7].r));
  #endif

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_rol_epi32, r, simde_mm256_setzero_si256(), imm8, a);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_rol_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t imm8;
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  2095750040), -INT32_C(   877703318),  INT32_C(  1249372464),  INT32_C(   961162864), -INT32_C(   566086496),  INT32_C(  1297488469),  INT32_C(  1599312793),  INT32_C(   712990354) },
      UINT8_C(250),
      { -INT32_C(  1201363095),  INT32_C(  1072181334), -INT32_C(   693095769), -INT32_C(  1334384260),  INT32_C(  1157977131),  INT32_C(  1054757803),  INT32_C(    97533606),  INT32_C(   654310077) },
       INT32_C(         161),
      {  INT32_C(  2095750040),  INT32_C(  2144362668),  INT32_C(  1249372464),  INT32_C(  1626198777), -INT32_C(  1979013034),  INT32_C(  2109515606),  INT32_C(   195067212),  INT32_C(  1308620154) } },
    { {  INT32_C(   993511059),  INT32_C(  1964107769), -INT32_C(    81360944), -INT32_C(  2025772068),  INT32_C(   633675646),  INT32_C(   438998365),  INT32_C(   826288527),  INT32_C(   539500172) },
      UINT8_C(229),
      {  INT32_C(  1188977503), -INT32_C(   216640660), -INT32_C(  1513155975),  INT32_C(  1914918483), -INT32_C(  1328527333), -INT32_C(  1690244494),  INT32_C(  1227387179), -INT32_C(   114407271) },
       INT32_C(         163),
      {  INT32_C(   921885434),  INT32_C(  1964107769),  INT32_C(   779654093), -INT32_C(  2025772068),  INT32_C(   633675646), -INT32_C(   637054060),  INT32_C(  1229162842), -INT32_C(   915258161) } },
    { { -INT32_C(   654158240), -INT32_C(  1149316504),  INT32_C(  1143841320),  INT32_C(  1576336874),  INT32_C(   335033576),  INT32_C(  1063002277),  INT32_C(   188255080), -INT32_C(   149260393) },
      UINT8_C(205),
      { -INT32_C(   281685731), -INT32_C(   250089393),  INT32_C(   467426078), -INT32_C(  2080163504),  INT32_C(  1378489905), -INT32_C(    21337741),  INT32_C(   412468897), -INT32_C(    35222048) },
       INT32_C(          94),
      {  INT32_C(  2077062215), -INT32_C(  1149316504), -INT32_C(  2030627129),  INT32_C(   553700948),  INT32_C(   335033576),  INT32_C(  1063002277),  INT32_C(  1176859048),  INT32_C(  1064936312) } },
    { {  INT32_C(   715064332), -INT32_C(  1354400929), -INT32_C(   449558092), -INT32_C(   768123297),  INT32_C(  1758524103), -INT32_C(  1736415560),  INT32_C(  1368811251), -INT32_C(  1895923070) },
      UINT8_C(134),
      {  INT32_C(   417773725),  INT32_C(  1187812861),  INT32_C(   665236169), -INT32_C(   605128471), -INT32_C(  1349298615),  INT32_C(  1034038487),  INT32_C(  1153430466), -INT32_C(  1882501647) },
       INT32_C(           5),
      {  INT32_C(   715064332), -INT32_C(   644694104), -INT32_C(   187279068), -INT32_C(   768123297),  INT32_C(  1758524103), -INT32_C(  1736415560),  INT32_C(  1368811251), -INT32_C(   110510543) } },
    { {  INT32_C(   273249350),  INT32_C(   255323942), -INT32_C(  1309989272),  INT32_C(  1398832764),  INT32_C(  1821442730), -INT32_C(   424587019), -INT32_C(  1552581474),  INT32_C(  1940266285) },
      UINT8_C(145),
      { -INT32_C(   541621264), -INT32_C(   515389765),  INT32_C(   811464881),  INT32_C(  1524281688), -INT32_C(  1840298174),  INT32_C(  1949316856), -INT32_C(   928918357),  INT32_C(  1784222842) },
       INT32_C(         152),
      { -INT32_C(   253773949),  INT32_C(   255323942), -INT32_C(  1309989272),  INT32_C(  1398832764),  INT32_C(  1116884807), -INT32_C(   424587019), -INT32_C(  1552581474),  INT32_C(  2053789972) } },
    { { -INT32_C(  2009820713), -INT32_C(   491220598), -INT32_C(  2076339390), -INT32_C(   770208550),  INT32_C(  1850099650), -INT32_C(  1774786789), -INT32_C(  1828679429),  INT32_C(  2011581088) },
      UINT8_C(220),
      { -INT32_C(  1402601446),  INT32_C(  1273907384),  INT32_C(   304444293), -INT32_C(   774572150),  INT32_C(   619528765),  INT32_C(   153125753), -INT32_C(   827739261), -INT32_C(  1263918694) },
       INT32_C(          33),
      { -INT32_C(  2009820713), -INT32_C(   491220598),  INT32_C(   608888586), -INT32_C(  1549144299),  INT32_C(  1239057530), -INT32_C(  1774786789), -INT32_C(  1655478521),  INT32_C(  1767129909) } },
    { { -INT32_C(   567980200),  INT32_C(  1290816194),  INT32_C(  2132657218), -INT32_C(  2136733177),  INT32_C(   294241421),  INT32_C(   299840119),  INT32_C(  1959168339), -INT32_C(   246536551) },
      UINT8_C(117),
      { -INT32_C(  1120415885), -INT32_C(  2063629377), -INT32_C(  1416921183), -INT32_C(   415691997), -INT32_C(   966899052), -INT32_C(  1306890199),  INT32_C(  1548455478),  INT32_C(  1339178204) },
       INT32_C(          12),
      {  INT32_C(  2096577491),  INT32_C(  1290816194), -INT32_C(  1208345928), -INT32_C(  2136733177), -INT32_C(   458666907), -INT32_C(  1493001439), -INT32_C(  1193056828), -INT32_C(   246536551) } },
    { {  INT32_C(   776932493), -INT32_C(  1361454453),  INT32_C(  2039812837), -INT32_C(  2059340708), -INT32_C(  1707648412), -INT32_C(   973700376), -INT32_C(   887830337),  INT32_C(  1603674578) },
      UINT8_C( 46),
      { -INT32_C(  1061581338),  INT32_C(  2040948838), -INT32_C(   237690883), -INT32_C(  1185588385),  INT32_C(   362999698), -INT32_C(  1361811482), -INT32_C(  1652514949),  INT32_C(   466345781) },
       INT32_C(         108),
      {  INT32_C(   776932493),  INT32_C(  1720084378),  INT32_C(  1375723293),  INT32_C(  1437989781), -INT32_C(  1707648412),  INT32_C(  1182690029), -INT32_C(   887830337),  INT32_C(  1603674578) } },
  };

  simde__m256i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm256_loadu_epi32(test_vec[0].src);
  a = simde_x_mm256_loadu_epi32(test_vec[0].a);
  r = simde_mm256_mask_rol_epi32(src, test_vec[0].k, a, INT32_C(         161));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[0].r));

  src = simde_x_mm256_loadu_epi32(test_vec[1].src);
  a = simde_x_mm256_loadu_epi32(test_vec[1].a);
  r = simde_mm256_mask_rol_epi32(src, test_vec[1].k, a, INT32_C(         163));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[1].r));

  src = simde_x_mm256_loadu_epi32(test_vec[2].src);
  a = simde_x_mm256_loadu_epi32(test_vec[2].a);
  r = simde_mm256_mask_rol_epi32(src, test_vec[2].k, a, INT32_C(          94));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[2].r));
  #endif

  src = simde_x_mm256_loadu_epi32(test_vec[3].src);
  a = simde_x_mm256_loadu_epi32(test_vec[3].a);
  r = simde_mm256_mask_rol_epi32(src, test_vec[3].k, a, INT32_C(           5));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[3].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm256_loadu_epi32(test_vec[4].src);
  a = simde_x_mm256_loadu_epi32(test_vec[4].a);
  r = simde_mm256_mask_rol_epi32(src, test_vec[4].k, a, INT32_C(         152));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[4].r));

  src = simde_x_mm256_loadu_epi32(test_vec[5].src);
  a = simde_x_mm256_loadu_epi32(test_vec[5].a);
  r = simde_mm256_mask_rol_epi32(src, test_vec[5].k, a, INT32_C(          33));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[5].r));
  #endif

  src = simde_x_mm256_loadu_epi32(test_vec[6].src);
  a = simde_x_mm256_loadu_epi32(test_vec[6].a);
  r = simde_mm256_mask_rol_epi32(src, test_vec[6].k, a, INT32_C(          12));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[6].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm256_loadu_epi32(test_vec[7].src);
  a = simde_x_mm256_loadu_epi32(test_vec[7].a);
  r = simde_mm256_mask_rol_epi32(src, test_vec[7].k, a, INT32_C(         108));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[7].r));
  #endif

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_rol_epi32, r, simde_mm256_setzero_si256(), imm8, src, k, a);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_rol_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t imm8;
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(236),
      { -INT32_C(  1578480510),  INT32_C(  2080496417),  INT32_C(   537901617), -INT32_C(  1023007652), -INT32_C(  1757432328),  INT32_C(   365747253),  INT32_C(   729933991),  INT32_C(  1175999684) },
       INT32_C(         160),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   537901617), -INT32_C(  1023007652),  INT32_C(           0),  INT32_C(   365747253),  INT32_C(   729933991),  INT32_C(  1175999684) } },
    { UINT8_C(221),
      { -INT32_C(  1559347480),  INT32_C(  1912549197), -INT32_C(   362167499), -INT32_C(   568328190), -INT32_C(  1249561139),  INT32_C(   192524470), -INT32_C(   894713912), -INT32_C(  1884787290) },
       INT32_C(         172),
      { -INT32_C(   470906320),  INT32_C(           0), -INT32_C(  1674355034),  INT32_C(       11746),  INT32_C(  1398594392),  INT32_C(           0), -INT32_C(  1141076822), -INT32_C(  2032506630) } },
    { UINT8_C(229),
      { -INT32_C(   199529679), -INT32_C(   705296940),  INT32_C(  1520620581),  INT32_C(   168908633), -INT32_C(  1882055472),  INT32_C(   892706247), -INT32_C(    69090235),  INT32_C(   685890294) },
       INT32_C(          69),
      { -INT32_C(  2089982402),  INT32_C(           0),  INT32_C(  1415218347),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1498171162),  INT32_C(  2084079807),  INT32_C(   473652933) } },
    { UINT8_C(  1),
      { -INT32_C(   416813293), -INT32_C(   398360175), -INT32_C(  1363653742), -INT32_C(  1166653667),  INT32_C(  1107274620),  INT32_C(  1714944908), -INT32_C(   659791908), -INT32_C(  1881553284) },
       INT32_C(         181),
      { -INT32_C(   495131395),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(130),
      {  INT32_C(    34877111),  INT32_C(   757122022), -INT32_C(   458630599), -INT32_C(   714020134), -INT32_C(  2119051742),  INT32_C(  1224575362),  INT32_C(  1677560930), -INT32_C(  1159380221) },
       INT32_C(         113),
      {  INT32_C(           0), -INT32_C(  2016650687),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2046331446) } },
    { UINT8_C(188),
      { -INT32_C(  1208646435),  INT32_C(   412211502),  INT32_C(   540698185), -INT32_C(  1599947753),  INT32_C(  1174662073),  INT32_C(   743007976),  INT32_C(  1151140683), -INT32_C(  1660815936) },
       INT32_C(         121),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1841269556),  INT32_C(   792806776),  INT32_C(  1921779671), -INT32_C(   799501619),  INT32_C(           0), -INT32_C(  2126904341) } },
    { UINT8_C(208),
      {  INT32_C(  1293533414), -INT32_C(  1234945542), -INT32_C(   948959780),  INT32_C(  1857009160),  INT32_C(    45734911),  INT32_C(  1858338169), -INT32_C(   169385730), -INT32_C(  1664774219) },
       INT32_C(          79),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   302022308),  INT32_C(           0), -INT32_C(  1333822733), -INT32_C(   941961630) } },
    { UINT8_C( 24),
      {  INT32_C(  1391722573),  INT32_C(   643480432),  INT32_C(  1176881258),  INT32_C(  2143233921),  INT32_C(  1266494954), -INT32_C(  1560251884),  INT32_C(   384998455), -INT32_C(   751944571) },
       INT32_C(          60),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   402387576), -INT32_C(  1531456802),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(199),
      {  INT32_C(   367748229), -INT32_C(   268427402), -INT32_C(  1293774043), -INT32_C(   781214915),  INT32_C(  1249291236),  INT32_C(   742553139), -INT32_C(   184967471), -INT32_C(  1162072523) },
       INT32_C(          18),
      { -INT32_C(  1844160595),  INT32_C(  2111553536),  INT32_C(  1284950922),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  2068304870), -INT32_C(  1193874704) } },
    { UINT8_C(198),
      {  INT32_C(  1676409296),  INT32_C(  1990303451), -INT32_C(  1202032115),  INT32_C(  1609278697), -INT32_C(  2060445721),  INT32_C(  1069229329), -INT32_C(  1999538719),  INT32_C(   357554757) },
       INT32_C(          19),
      {  INT32_C(           0), -INT32_C(   153373428), -INT32_C(  1871854893),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1358150005), -INT32_C(   769086850) } },
    { UINT8_C(216),
      { -INT32_C(  1931140071),  INT32_C(   594910591), -INT32_C(  1609902967),  INT32_C(   716279813), -INT32_C(  1072959413), -INT32_C(  1677356094),  INT32_C(   493886178), -INT32_C(  1393221997) },
       INT32_C(           3),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1435271209),  INT32_C(     6259294),  INT32_C(           0), -INT32_C(   343877872),  INT32_C(  1739125917) } },
    { UINT8_C(120),
      { -INT32_C(  2113804883), -INT32_C(  2138594576),  INT32_C(  1154199891),  INT32_C(  1325829052), -INT32_C(  1422744943),  INT32_C(   826167058),  INT32_C(   527756100), -INT32_C(   778553821) },
       INT32_C(          27),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   495438755), -INT32_C(  1923508972), -INT32_C(  1853230472),  INT32_C(   553363290),  INT32_C(           0) } },
    { UINT8_C( 59),
      { -INT32_C(  1953526822), -INT32_C(   498609322),  INT32_C(  2071172825),  INT32_C(   395189960),  INT32_C(  1214037853),  INT32_C(  1768651571), -INT32_C(  1383842797),  INT32_C(  1776849039) },
       INT32_C(          27),
      { -INT32_C(   732136354), -INT32_C(  1223541094),  INT32_C(           0),  INT32_C(  1086091510), -INT32_C(   364714502), -INT32_C(  1689560103),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 74),
      { -INT32_C(   769436613), -INT32_C(   442851385), -INT32_C(   331173331), -INT32_C(  1994421746),  INT32_C(   849185014), -INT32_C(  1664988660), -INT32_C(  1430770894),  INT32_C(  1542728224) },
       INT32_C(          30),
      {  INT32_C(           0), -INT32_C(   110712847),  INT32_C(           0), -INT32_C(  1572347261),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1431434548),  INT32_C(           0) } },
    { UINT8_C(183),
      {  INT32_C(  2061773512), -INT32_C(   142028691),  INT32_C(  2012025327), -INT32_C(   125624146),  INT32_C(   220930274),  INT32_C(    36558296), -INT32_C(   511669815),  INT32_C(  2123941302) },
       INT32_C(          15),
      {  INT32_C(   358890866),  INT32_C(  1748433860), -INT32_C(  1997030410),  INT32_C(           0), -INT32_C(  1871640939), -INT32_C(   353631978),  INT32_C(           0),  INT32_C(  1658535756) } },
    { UINT8_C( 76),
      { -INT32_C(  1841605504),  INT32_C(  1631629889),  INT32_C(  1447246134),  INT32_C(   959336804),  INT32_C(   117583998),  INT32_C(  1975444656), -INT32_C(   110871428), -INT32_C(  1253719755) },
       INT32_C(          21),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   650823783),  INT32_C(   747054538),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1885393785),  INT32_C(           0) } },
  };

  simde__m256i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi32(test_vec[0].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[0].k, a, INT32_C(         160));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[0].r));

  a = simde_x_mm256_loadu_epi32(test_vec[1].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[1].k, a, INT32_C(         172));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[1].r));

  a = simde_x_mm256_loadu_epi32(test_vec[2].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[2].k, a, INT32_C(          69));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[2].r));

  a = simde_x_mm256_loadu_epi32(test_vec[3].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[3].k, a, INT32_C(         181));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[3].r));

  a = simde_x_mm256_loadu_epi32(test_vec[4].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[4].k, a, INT32_C(         113));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[4].r));

  a = simde_x_mm256_loadu_epi32(test_vec[5].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[5].k, a, INT32_C(         121));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[5].r));

  a = simde_x_mm256_loadu_epi32(test_vec[6].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[6].k, a, INT32_C(          79));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[6].r));

  a = simde_x_mm256_loadu_epi32(test_vec[7].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[7].k, a, INT32_C(          60));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[7].r));
  #endif

  a = simde_x_mm256_loadu_epi32(test_vec[8].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[8].k, a, INT32_C(          18));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[8].r));

  a = simde_x_mm256_loadu_epi32(test_vec[9].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[9].k, a, INT32_C(          19));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[9].r));

  a = simde_x_mm256_loadu_epi32(test_vec[10].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[10].k, a, INT32_C(           3));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[10].r));

  a = simde_x_mm256_loadu_epi32(test_vec[11].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[11].k, a, INT32_C(          27));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[11].r));

  a = simde_x_mm256_loadu_epi32(test_vec[12].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[12].k, a, INT32_C(          27));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[12].r));

  a = simde_x_mm256_loadu_epi32(test_vec[13].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[13].k, a, INT32_C(          30));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[13].r));

  a = simde_x_mm256_loadu_epi32(test_vec[14].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[14].k, a, INT32_C(          15));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[14].r));

  a = simde_x_mm256_loadu_epi32(test_vec[15].a);
  r = simde_mm256_maskz_rol_epi32(test_vec[15].k, a, INT32_C(          21));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[15].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_rol_epi32, r, simde_mm256_setzero_si256(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_rol_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t imm8;
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1495604100), -INT32_C(  1086591804), -INT32_C(    72807668), -INT32_C(  1696488045),  INT32_C(   912544579), -INT32_C(   663187698), -INT32_C(   615406977),  INT32_C(   339953048),
        -INT32_C(   306504407),  INT32_C(   380499466), -INT32_C(  1794025982),  INT32_C(  1060107260),  INT32_C(  1416991558), -INT32_C(  1590890974),  INT32_C(   679312784), -INT32_C(   331497277) },
       INT32_C(         222),
      {  INT32_C(   699840799),  INT32_C(   802093873),  INT32_C(  1055539907), -INT32_C(   424122012), -INT32_C(   845605680), -INT32_C(  1239538749), -INT32_C(   153851745),  INT32_C(    84988262),
         INT32_C(  2070857546), -INT32_C(  2052358782), -INT32_C(  1522248320),  INT32_C(   265026815), -INT32_C(  1793235759), -INT32_C(  1471464568),  INT32_C(   169828196), -INT32_C(    82874320) } },
    { { -INT32_C(   251754514), -INT32_C(   645525539),  INT32_C(  1209644290),  INT32_C(  1805487689),  INT32_C(   219007356),  INT32_C(   171280967),  INT32_C(   687239754),  INT32_C(  1494274154),
         INT32_C(   893980247),  INT32_C(   537841438), -INT32_C(   831969403),  INT32_C(   842598070),  INT32_C(   373245647),  INT32_C(   455112144),  INT32_C(  1380128743),  INT32_C(  1068192999) },
       INT32_C(          98),
      { -INT32_C(  1007018053),  INT32_C(  1712865143),  INT32_C(   543609865), -INT32_C(  1367983835),  INT32_C(   876029424),  INT32_C(   685123868), -INT32_C(  1546008280),  INT32_C(  1682129321),
        -INT32_C(   719046308), -INT32_C(  2143601544),  INT32_C(   967089687), -INT32_C(   924575016),  INT32_C(  1492982588),  INT32_C(  1820448576),  INT32_C(  1225547677), -INT32_C(    22195300) } },
    { {  INT32_C(  1235321540),  INT32_C(  1612122794), -INT32_C(   544059376),  INT32_C(  1744229015),  INT32_C(   780277319),  INT32_C(   360760877),  INT32_C(  2085890842), -INT32_C(   453130208),
        -INT32_C(   198336950), -INT32_C(  1202436952),  INT32_C(   731375508),  INT32_C(     9670073), -INT32_C(   785508956), -INT32_C(   169431077), -INT32_C(    93177126),  INT32_C(  1306423042) },
       INT32_C(          13),
      {  INT32_C(   811108660), -INT32_C(   514503678),  INT32_C(  1241652210), -INT32_C(   632099586),  INT32_C(  1120462288),  INT32_C(   415605424), -INT32_C(  2057089142), -INT32_C(  1190912865),
        -INT32_C(  1278648699), -INT32_C(  2003495158), -INT32_C(    51214990),  INT32_C(  1907826706), -INT32_C(  1028351451), -INT32_C(   704938308),  INT32_C(  1197170510), -INT32_C(   840939077) } },
    { { -INT32_C(   462580145),  INT32_C(   906953853),  INT32_C(   909550226), -INT32_C(  1828232008), -INT32_C(   292950509),  INT32_C(   736688936),  INT32_C(  2004404074),  INT32_C(   573356498),
        -INT32_C(   871982769),  INT32_C(   788665757),  INT32_C(  1885681848), -INT32_C(  1341952611), -INT32_C(  2086761381), -INT32_C(   240220281),  INT32_C(   543696462),  INT32_C(   792892640) },
       INT32_C(          45),
      { -INT32_C(  1295385459), -INT32_C(   527456575), -INT32_C(   732805434), -INT32_C(   325643680),  INT32_C(  1036156369),  INT32_C(   526714237),  INT32_C(   418205423), -INT32_C(  1757789115),
        -INT32_C(   752223872),  INT32_C(  1119069664), -INT32_C(  1491661300),  INT32_C(  1840494080), -INT32_C(   779390861), -INT32_C(   789512651),  INT32_C(    80331789),  INT32_C(  1385956840) } },
    { {  INT32_C(   385547870), -INT32_C(   729391049),  INT32_C(   679774669), -INT32_C(  1649728746), -INT32_C(   124822870),  INT32_C(  1612248960), -INT32_C(  1181721716),  INT32_C(    25463971),
        -INT32_C(  1055424630), -INT32_C(  1399480865),  INT32_C(  1037310503), -INT32_C(   405110979),  INT32_C(  1524591065), -INT32_C(   306514079), -INT32_C(   156874158),  INT32_C(  1643588566) },
       INT32_C(         170),
      { -INT32_C(   335972261),  INT32_C(   427876178),  INT32_C(   304559266), -INT32_C(  1400087946),  INT32_C(  1030400994),  INT32_C(  1675493760),  INT32_C(  1097741030),  INT32_C(   305302534),
         INT32_C(  1576938244),  INT32_C(  1450671794),  INT32_C(  1349033207),  INT32_C(  1778186143),  INT32_C(  2108122475), -INT32_C(   337803338), -INT32_C(  1725346854), -INT32_C(   592488057) } },
    { { -INT32_C(   751454036),  INT32_C(   252709330),  INT32_C(  1660349320), -INT32_C(  1245915820),  INT32_C(   530740940), -INT32_C(  1760212543),  INT32_C(   519572596), -INT32_C(   928572645),
        -INT32_C(  1516512045),  INT32_C(  1840557285), -INT32_C(   338711913),  INT32_C(  1268878207), -INT32_C(  1016446206),  INT32_C(     5930892), -INT32_C(  1491184756),  INT32_C(  1097844078) },
       INT32_C(         161),
      { -INT32_C(  1502908071),  INT32_C(   505418660), -INT32_C(   974268656),  INT32_C(  1803135657),  INT32_C(  1061481880),  INT32_C(   774542211),  INT32_C(  1039145192), -INT32_C(  1857145289),
         INT32_C(  1261943207), -INT32_C(   613852726), -INT32_C(   677423825), -INT32_C(  1757210882), -INT32_C(  2032892411),  INT32_C(    11861784),  INT32_C(  1312597785), -INT32_C(  2099279140) } },
    { {  INT32_C(  1324653239), -INT32_C(  1019624636),  INT32_C(  1359927887), -INT32_C(  1441498850), -INT32_C(  2069139720),  INT32_C(   791464385),  INT32_C(   812686223),  INT32_C(  1572296358),
         INT32_C(   883665904), -INT32_C(  1107827346), -INT32_C(   586283329),  INT32_C(  2005410431),  INT32_C(  1392259985), -INT32_C(  1954404100),  INT32_C(  1790767811),  INT32_C(   969372489) },
       INT32_C(          30),
      { -INT32_C(   742578515),  INT32_C(   818835665), -INT32_C(   733759853), -INT32_C(  1434116537),  INT32_C(   556456894),  INT32_C(  1271607920), -INT32_C(   870570269), -INT32_C(  1754409559),
         INT32_C(   220916476), -INT32_C(  1350698661), -INT32_C(   146570833), -INT32_C(   572389217),  INT32_C(  1421806820),  INT32_C(   585140799), -INT32_C(   626049872),  INT32_C(  1316084946) } },
    { {  INT32_C(   390751576), -INT32_C(   353019797),  INT32_C(   207781243), -INT32_C(  1403101520),  INT32_C(  1228464262),  INT32_C(   481555667), -INT32_C(  2057995417),  INT32_C(  1175569390),
        -INT32_C(  1805821143),  INT32_C(   796873396),  INT32_C(  2134630863), -INT32_C(   986932929),  INT32_C(  1292788858), -INT32_C(  1083588008),  INT32_C(   725925437), -INT32_C(  1418635902) },
       INT32_C(         177),
      { -INT32_C(   894423404), -INT32_C(  1328032278), -INT32_C(    84535100), -INT32_C(  1117693764), -INT32_C(  1056140687), -INT32_C(   374982297), -INT32_C(   154203478), -INT32_C(  2015589341),
        -INT32_C(  1236064070), -INT32_C(  1519886594), -INT32_C(  1012990345),  INT32_C(   847219289), -INT32_C(   923493860), -INT32_C(  2068742445),  INT32_C(  2088392329), -INT32_C(  1425713438) } },
  };

  simde__m512i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi32(test_vec[0].a);
  r = simde_mm512_rol_epi32(a, INT32_C(         222));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[0].r));

  a = simde_mm512_loadu_epi32(test_vec[1].a);
  r = simde_mm512_rol_epi32(a, INT32_C(          98));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[1].r));
  #endif

  a = simde_mm512_loadu_epi32(test_vec[2].a);
  r = simde_mm512_rol_epi32(a, INT32_C(          13));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[2].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi32(test_vec[3].a);
  r = simde_mm512_rol_epi32(a, INT32_C(          45));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[3].r));

  a = simde_mm512_loadu_epi32(test_vec[4].a);
  r = simde_mm512_rol_epi32(a, INT32_C(         170));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[4].r));

  a = simde_mm512_loadu_epi32(test_vec[5].a);
  r = simde_mm512_rol_epi32(a, INT32_C(         161));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[5].r));
  #endif

  a = simde_mm512_loadu_epi32(test_vec[6].a);
  r = simde_mm512_rol_epi32(a, INT32_C(          30));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[6].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi32(test_vec[7].a);
  r = simde_mm512_rol_epi32(a, INT32_C(         177));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[7].r));
  #endif

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_rol_epi32, r, simde_mm512_setzero_si512(), imm8, a);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_rol_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t imm8;
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(   258687455), -INT32_C(   563032161), -INT32_C(   492594072),  INT32_C(  1479520768), -INT32_C(  1323853708), -INT32_C(   639870121),  INT32_C(  1636060592),  INT32_C(  1019659035),
         INT32_C(   556620418), -INT32_C(  1845453527),  INT32_C(   963945273), -INT32_C(   913202091), -INT32_C(  1820678084), -INT32_C(  1284745725), -INT32_C(  1089081181),  INT32_C(   922475444) },
      UINT16_C(10294),
      {  INT32_C(  1472552791),  INT32_C(  1727790833), -INT32_C(   938848201), -INT32_C(  1804581350),  INT32_C(  1189835738),  INT32_C(  1010273831),  INT32_C(  1226304333),  INT32_C(  2020691233),
        -INT32_C(  1630521427),  INT32_C(  1829030709),  INT32_C(   892669467),  INT32_C(   801810005),  INT32_C(  1081455897), -INT32_C(  1854100413), -INT32_C(  1193634665), -INT32_C(  1909371935) },
       INT32_C(         130),
      { -INT32_C(   258687455), -INT32_C(  1678771259),  INT32_C(   539574495),  INT32_C(  1479520768),  INT32_C(   464375657), -INT32_C(   253871972),  INT32_C(  1636060592),  INT32_C(  1019659035),
         INT32_C(   556620418), -INT32_C(  1845453527),  INT32_C(   963945273), -INT32_C(  1087727276), -INT32_C(  1820678084),  INT32_C(  1173532942), -INT32_C(  1089081181),  INT32_C(   922475444) } },
    { { -INT32_C(   416992820), -INT32_C(  1793238464),  INT32_C(   449111808), -INT32_C(   547735140),  INT32_C(  2104547302),  INT32_C(  1278626411),  INT32_C(   417032086),  INT32_C(   886048872),
         INT32_C(  2031875385),  INT32_C(  1343109200), -INT32_C(  1150627297), -INT32_C(   224672500),  INT32_C(   124717980), -INT32_C(   330062506),  INT32_C(  1946430988),  INT32_C(  1890112822) },
      UINT16_C(50378),
      { -INT32_C(   117695767), -INT32_C(   708174741),  INT32_C(  1922750167),  INT32_C(   947795656), -INT32_C(  1847733187), -INT32_C(   994055488),  INT32_C(   127530590),  INT32_C(  1338729574),
        -INT32_C(   381171842), -INT32_C(  1145105693), -INT32_C(  1322427928), -INT32_C(   840324208),  INT32_C(  1063175807),  INT32_C(   251928240),  INT32_C(  2048302356), -INT32_C(  2134253311) },
       INT32_C(         168),
      { -INT32_C(   416992820), -INT32_C(   904107051),  INT32_C(   449111808),  INT32_C(  2117519416),  INT32_C(  2104547302),  INT32_C(  1278626411), -INT32_C(  1711907321), -INT32_C(   882612657),
         INT32_C(  2031875385),  INT32_C(  1343109200),  INT32_C(   760866993), -INT32_C(   224672500),  INT32_C(   124717980), -INT32_C(   330062506),  INT32_C(   379393146), -INT32_C(   908000896) } },
    { {  INT32_C(   189212707),  INT32_C(   314340482), -INT32_C(  1612733152),  INT32_C(   484392556),  INT32_C(  1881924444), -INT32_C(  2098577024), -INT32_C(   889015518), -INT32_C(   413701180),
         INT32_C(   385064596),  INT32_C(   841527058), -INT32_C(  1043200171), -INT32_C(  1579306683),  INT32_C(   336660884),  INT32_C(  1838611274),  INT32_C(  1933088943), -INT32_C(  1738830076) },
      UINT16_C(20013),
      { -INT32_C(   688046162),  INT32_C(  1155355250), -INT32_C(   235592941), -INT32_C(   688223804),  INT32_C(   886129821), -INT32_C(   372473679),  INT32_C(  1333317876),  INT32_C(   379430248),
         INT32_C(  1475123941),  INT32_C(    10210029), -INT32_C(  1309568787), -INT32_C(  1232606439), -INT32_C(   504735440), -INT32_C(   842287143), -INT32_C(   266583161), -INT32_C(   838419991) },
       INT32_C(          84),
      { -INT32_C(    85102637),  INT32_C(   314340482),  INT32_C(   826220370), -INT32_C(  1672646744),  INT32_C(  1881924444),  INT32_C(   186555592), -INT32_C(   889015518), -INT32_C(   413701180),
         INT32_C(   385064596), -INT32_C(  1362097732),  INT32_C(   249241369), -INT32_C(  1315215234),  INT32_C(   336660884),  INT32_C(  1838611274),  INT32_C(   947847620), -INT32_C(  1738830076) } },
    { { -INT32_C(  1438531395),  INT32_C(  1767584592),  INT32_C(  1310712606),  INT32_C(   355469884),  INT32_C(  1222900673),  INT32_C(   658046782),  INT32_C(   234176441), -INT32_C(   280094158),
         INT32_C(   714706906), -INT32_C(   510397246),  INT32_C(   321893335),  INT32_C(  2116640701), -INT32_C(  1715073958), -INT32_C(   993984757),  INT32_C(  1892791870), -INT32_C(  1419829296) },
      UINT16_C(63663),
      {  INT32_C(  1777103317), -INT32_C(  2112043950),  INT32_C(    14801367),  INT32_C(   487341143), -INT32_C(  1793320747), -INT32_C(  1370793252),  INT32_C(   701308106), -INT32_C(  1675526969),
         INT32_C(  1074073326), -INT32_C(  1446895150),  INT32_C(  1370137850), -INT32_C(  1250969888), -INT32_C(  1421177906), -INT32_C(  1336305946),  INT32_C(  2044339890), -INT32_C(  1860830301) },
       INT32_C(           9),
      { -INT32_C(   656168237),  INT32_C(   965256452), -INT32_C(  1011634687),  INT32_C(   410562106),  INT32_C(  1222900673), -INT32_C(  1766475428),  INT32_C(   234176441),  INT32_C(  1123651384),
         INT32_C(   714706906), -INT32_C(   510397246),  INT32_C(   321893335), -INT32_C(   546455190), -INT32_C(  1793614506), -INT32_C(  1288843936), -INT32_C(  1269996301),  INT32_C(   737625890) } },
    { {  INT32_C(   931501116),  INT32_C(   411578168), -INT32_C(  1261570075),  INT32_C(  1767839619),  INT32_C(  1595521197), -INT32_C(  2116488226), -INT32_C(   132976913),  INT32_C(  1171579913),
        -INT32_C(  1334027912),  INT32_C(  1841825160),  INT32_C(  2132907516),  INT32_C(  1525186732),  INT32_C(   398000696), -INT32_C(   459762955), -INT32_C(  1981961344),  INT32_C(   130986383) },
      UINT16_C(19210),
      {  INT32_C(  2135986871),  INT32_C(   554978559), -INT32_C(  1264467764), -INT32_C(   726214118), -INT32_C(  1989759759),  INT32_C(  1832183440),  INT32_C(  1025426287), -INT32_C(  2121783094),
        -INT32_C(  1174349638), -INT32_C(   237300699), -INT32_C(   274367275),  INT32_C(  1203985494), -INT32_C(  1731122936),  INT32_C(  2114323727), -INT32_C(  1816386359),  INT32_C(   118834253) },
       INT32_C(          29),
      {  INT32_C(   931501116), -INT32_C(   467498593), -INT32_C(  1261570075),  INT32_C(  1519835971),  INT32_C(  1595521197), -INT32_C(  2116488226), -INT32_C(   132976913),  INT32_C(  1171579913),
         INT32_C(  1463819031), -INT32_C(  1103404412),  INT32_C(  2132907516), -INT32_C(   923243638),  INT32_C(   398000696), -INT32_C(   459762955),  INT32_C(   846693529),  INT32_C(   130986383) } },
    { { -INT32_C(    13394902),  INT32_C(  1877923865),  INT32_C(  1018671668), -INT32_C(   338327333),  INT32_C(  1449778061),  INT32_C(  1290413567), -INT32_C(  2024472726),  INT32_C(  1053365524),
        -INT32_C(   885130062),  INT32_C(   154807508), -INT32_C(  1186598434),  INT32_C(   128195193), -INT32_C(   178450699), -INT32_C(  1656666317),  INT32_C(  1529124166),  INT32_C(  1570368939) },
      UINT16_C(55273),
      {  INT32_C(  1644412456),  INT32_C(   206889415),  INT32_C(  1059573146),  INT32_C(   843914452),  INT32_C(  1400471569),  INT32_C(  1122549790), -INT32_C(  1271885029),  INT32_C(   411769328),
        -INT32_C(  1636069673),  INT32_C(   179031919),  INT32_C(  1900663452),  INT32_C(    10721006),  INT32_C(   877861910), -INT32_C(   143180836), -INT32_C(  1079203889), -INT32_C(  1730660416) },
       INT32_C(         198),
      { -INT32_C(  2131785192),  INT32_C(  1877923865),  INT32_C(  1018671668), -INT32_C(  1824049908),  INT32_C(  1449778061), -INT32_C(  1171257456),  INT32_C(   203736813),  INT32_C(   583433222),
        -INT32_C(  1629243929), -INT32_C(  1426859070),  INT32_C(  1383376668),  INT32_C(   128195193),  INT32_C(   348587405), -INT32_C(  1656666317), -INT32_C(   349572113),  INT32_C(   906883110) } },
    { { -INT32_C(  1103109854), -INT32_C(  1573943117),  INT32_C(   899863070), -INT32_C(   882248209), -INT32_C(     3940304),  INT32_C(  1220505479),  INT32_C(  1826658214),  INT32_C(   211949290),
        -INT32_C(  1412767240), -INT32_C(  2008155542), -INT32_C(  1145180212),  INT32_C(   361179108), -INT32_C(  1894495737),  INT32_C(  1607979961),  INT32_C(  1422702442), -INT32_C(   983535923) },
      UINT16_C(11087),
      { -INT32_C(  1104823951), -INT32_C(     5312190),  INT32_C(   874943149), -INT32_C(  1132581209), -INT32_C(  1802553411),  INT32_C(  1649146518), -INT32_C(  1345316786),  INT32_C(  1339695326),
         INT32_C(   453902297), -INT32_C(  1659126800), -INT32_C(   170835634),  INT32_C(   749817711),  INT32_C(   499138950), -INT32_C(  1988162757),  INT32_C(    37244964),  INT32_C(  1230049904) },
       INT32_C(          17),
      {  INT32_C(  1927511115), -INT32_C(   494534819),  INT32_C(   626681933),  INT32_C(  1565489404), -INT32_C(     3940304),  INT32_C(  1220505479),  INT32_C(   815620000),  INT32_C(   211949290),
        -INT32_C(     5097957),  INT32_C(  2011249207), -INT32_C(  1145180212), -INT32_C(  1629595294), -INT32_C(  1894495737),  INT32_C(   376902398),  INT32_C(  1422702442), -INT32_C(   983535923) } },
    { {  INT32_C(  1755283482),  INT32_C(   828207553),  INT32_C(  1197281216), -INT32_C(  1956372912),  INT32_C(  1293214505), -INT32_C(  1555083981),  INT32_C(  1911398495),  INT32_C(   426988287),
        -INT32_C(  1820257582),  INT32_C(  1153752707),  INT32_C(  1032528621),  INT32_C(  1774776128),  INT32_C(   112713170), -INT32_C(  1985411542), -INT32_C(  1493526873), -INT32_C(  1161859608) },
      UINT16_C(16512),
      {  INT32_C(   303956814), -INT32_C(   768340921),  INT32_C(   314668105), -INT32_C(  1779460898),  INT32_C(  1134238106), -INT32_C(  1646640478), -INT32_C(  1492466968), -INT32_C(   874018179),
        -INT32_C(   706935154),  INT32_C(  1537741330),  INT32_C(  1684892038), -INT32_C(  1745265411),  INT32_C(   417043829), -INT32_C(  1061833257), -INT32_C(   194527369), -INT32_C(   658550966) },
       INT32_C(          85),
      {  INT32_C(  1755283482),  INT32_C(   828207553),  INT32_C(  1197281216), -INT32_C(  1956372912),  INT32_C(  1293214505), -INT32_C(  1555083981),  INT32_C(  1911398495),  INT32_C(  1337556209),
        -INT32_C(  1820257582),  INT32_C(  1153752707),  INT32_C(  1032528621),  INT32_C(  1774776128),  INT32_C(   112713170), -INT32_C(  1985411542), -INT32_C(   285307657), -INT32_C(  1161859608) } },
  };

  simde__m512i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_mm512_loadu_epi32(test_vec[0].src);
  a = simde_mm512_loadu_epi32(test_vec[0].a);
  r = simde_mm512_mask_rol_epi32(src, test_vec[0].k, a, INT32_C(         130));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[0].r));

  src = simde_mm512_loadu_epi32(test_vec[1].src);
  a = simde_mm512_loadu_epi32(test_vec[1].a);
  r = simde_mm512_mask_rol_epi32(src, test_vec[1].k, a, INT32_C(         168));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[1].r));

  src = simde_mm512_loadu_epi32(test_vec[2].src);
  a = simde_mm512_loadu_epi32(test_vec[2].a);
  r = simde_mm512_mask_rol_epi32(src, test_vec[2].k, a, INT32_C(          84));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[2].r));
  #endif

  src = simde_mm512_loadu_epi32(test_vec[3].src);
  a = simde_mm512_loadu_epi32(test_vec[3].a);
  r = simde_mm512_mask_rol_epi32(src, test_vec[3].k, a, INT32_C(           9));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[3].r));

  src = simde_mm512_loadu_epi32(test_vec[4].src);
  a = simde_mm512_loadu_epi32(test_vec[4].a);
  r = simde_mm512_mask_rol_epi32(src, test_vec[4].k, a, INT32_C(          29));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[4].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_mm512_loadu_epi32(test_vec[5].src);
  a = simde_mm512_loadu_epi32(test_vec[5].a);
  r = simde_mm512_mask_rol_epi32(src, test_vec[5].k, a, INT32_C(         198));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[5].r));
  #endif

  src = simde_mm512_loadu_epi32(test_vec[6].src);
  a = simde_mm512_loadu_epi32(test_vec[6].a);
  r = simde_mm512_mask_rol_epi32(src, test_vec[6].k, a, INT32_C(          17));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[6].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_mm512_loadu_epi32(test_vec[7].src);
  a = simde_mm512_loadu_epi32(test_vec[7].a);
  r = simde_mm512_mask_rol_epi32(src, test_vec[7].k, a, INT32_C(          85));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[7].r));
  #endif

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_rol_epi32, r, simde_mm512_setzero_si512(), imm8, src, k, a);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_rol_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t imm8;
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(21935),
      {  INT32_C(   817837506), -INT32_C(  1819493222),  INT32_C(   791151188), -INT32_C(   807141350),  INT32_C(   663641024),  INT32_C(   259446864),  INT32_C(  1588382640), -INT32_C(   172795086),
         INT32_C(   723874449), -INT32_C(  2084654801), -INT32_C(   843913293), -INT32_C(  1482909977),  INT32_C(  1104030705), -INT32_C(  1269742333),  INT32_C(  1125317904), -INT32_C(   365378215) },
       INT32_C(          56),
      { -INT32_C(  1036992715), -INT32_C(  1701606212),  INT32_C(  1412376578),  INT32_C(   449831936),  INT32_C(           0),  INT32_C(  1343190744),  INT32_C(           0),  INT32_C(   854963035),
        -INT32_C(  1859443342),  INT32_C(           0), -INT32_C(  1278364953),  INT32_C(           0), -INT32_C(   247345621),  INT32_C(           0),  INT32_C(   272831229),  INT32_C(           0) } },
    { UINT16_C(54030),
      { -INT32_C(  1665482006),  INT32_C(   741515663),  INT32_C(   391586632), -INT32_C(  1235461531),  INT32_C(   548629518), -INT32_C(   404353873),  INT32_C(   189013750),  INT32_C(  1876906885),
        -INT32_C(  1542743787), -INT32_C(  2083504837), -INT32_C(   979753120), -INT32_C(  1870924158),  INT32_C(   313601891),  INT32_C(   855283515),  INT32_C(   977092277), -INT32_C(  1498866543) },
       INT32_C(         182),
      {  INT32_C(           0),  INT32_C(  1674251432), -INT32_C(   771369528), -INT32_C(  1720871146),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(  1164509926),  INT32_C(  1323365391),  INT32_C(           0),  INT32_C(           0), -INT32_C(   658199477),  INT32_C(           0), -INT32_C(  1387360433),  INT32_C(   610904647) } },
    { UINT16_C( 7153),
      {  INT32_C(   256070004), -INT32_C(  1845115625),  INT32_C(   113338453),  INT32_C(  1973288315),  INT32_C(  1823691311),  INT32_C(   898188684),  INT32_C(   921255915), -INT32_C(  1538074064),
         INT32_C(  1135842604), -INT32_C(  1344947878), -INT32_C(  1665755359), -INT32_C(  1022274668),  INT32_C(   841991590), -INT32_C(   177686518),  INT32_C(   657215991),  INT32_C(  1489796652) },
       INT32_C(          19),
      { -INT32_C(  1952417254),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1854184038),  INT32_C(   744598602), -INT32_C(    10897591), -INT32_C(   779804010),
        -INT32_C(  1453187684), -INT32_C(   891978067),  INT32_C(           0), -INT32_C(  1666836342),  INT32_C(   758223230),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(28728),
      { -INT32_C(   771270116),  INT32_C(   136748022), -INT32_C(  1899115426),  INT32_C(  1715918846), -INT32_C(   122143028),  INT32_C(   829875301), -INT32_C(   676230852),  INT32_C(   323480054),
         INT32_C(   988106563),  INT32_C(  1229065194), -INT32_C(   690548777), -INT32_C(  1304683034), -INT32_C(  1045695397),  INT32_C(   351412696), -INT32_C(  1578392661), -INT32_C(   793496691) },
       INT32_C(         130),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1726259207), -INT32_C(   488572109), -INT32_C(   975466092),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   112185711),  INT32_C(  1405650784), -INT32_C(  2018603346),  INT32_C(           0) } },
    { UINT16_C(19621),
      { -INT32_C(  1940161099), -INT32_C(  1884667565), -INT32_C(  1618737676), -INT32_C(  1178575674),  INT32_C(  1549560689), -INT32_C(  1047533299), -INT32_C(  1000664646),  INT32_C(   856752510),
        -INT32_C(   775918466), -INT32_C(  1570739538),  INT32_C(   910287983), -INT32_C(  1292959423),  INT32_C(  2047757165), -INT32_C(   281305547),  INT32_C(   766744495),  INT32_C(   375506072) },
       INT32_C(          49),
      { -INT32_C(    76867402),  INT32_C(           0),  INT32_C(   199835400),  INT32_C(           0),  INT32_C(           0), -INT32_C(   769948897),  INT32_C(           0),  INT32_C(    50095650),
         INT32_C(           0),  INT32_C(           0), -INT32_C(   924947325),  INT32_C(    42165726),  INT32_C(           0),  INT32_C(           0),  INT32_C(   794712935),  INT32_C(           0) } },
    { UINT16_C(18315),
      { -INT32_C(  1037239679),  INT32_C(   532901168),  INT32_C(   761999391), -INT32_C(   422862678),  INT32_C(  1115519887),  INT32_C(   151459240),  INT32_C(   304756779), -INT32_C(  1738951401),
        -INT32_C(   530938448),  INT32_C(   285220338), -INT32_C(   130061490), -INT32_C(  1696724469),  INT32_C(   786193285), -INT32_C(  1690836112),  INT32_C(   850223643), -INT32_C(   943061225) },
       INT32_C(         140),
      { -INT32_C(   811066334),  INT32_C(   919798268),  INT32_C(           0), -INT32_C(  1173705108),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1689159291),
        -INT32_C(  1470427643),  INT32_C(    31400208), -INT32_C(   155914365),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   702434518),  INT32_C(           0) } },
    { UINT16_C(43074),
      { -INT32_C(   820801392),  INT32_C(  1742347912), -INT32_C(  1799200840), -INT32_C(   981978227),  INT32_C(  2082968526), -INT32_C(  1870446906), -INT32_C(  1363865850),  INT32_C(   525793166),
         INT32_C(   267282823),  INT32_C(  1064749191), -INT32_C(  1244448472),  INT32_C(   981093228), -INT32_C(  1514757665), -INT32_C(   432719392), -INT32_C(   678106551),  INT32_C(  1761012449) },
       INT32_C(          83),
      {  INT32_C(           0), -INT32_C(   196919600),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  2016769448),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1533137874),  INT32_C(           0), -INT32_C(   821612119),  INT32_C(           0),  INT32_C(  1460357047) } },
    { UINT16_C(61101),
      { -INT32_C(   332933863),  INT32_C(    87593867), -INT32_C(  2069424178), -INT32_C(   239171652),  INT32_C(    31197037), -INT32_C(   705970722), -INT32_C(  1631961562),  INT32_C(   831285016),
        -INT32_C(   937577411),  INT32_C(   365778247),  INT32_C(   681210988),  INT32_C(  1746557179),  INT32_C(  1030354527), -INT32_C(   653110093), -INT32_C(  1434989422),  INT32_C(  1910178868) },
       INT32_C(         184),
      {  INT32_C(   434907093),  INT32_C(           0), -INT32_C(   830167273), -INT32_C(  1125007737),  INT32_C(           0), -INT32_C(   556405827),  INT32_C(           0),  INT32_C(   405900391),
         INT32_C(           0),  INT32_C(  1192611157),  INT32_C(  1814600308), -INT32_C(    77063592),  INT32_C(           0), -INT32_C(  1277619628), -INT32_C(  1834321972),  INT32_C(   879876868) } },
    { UINT16_C(34867),
      { -INT32_C(    71210568), -INT32_C(   313776705),  INT32_C(  1612565342), -INT32_C(  1874539054), -INT32_C(  1479687870), -INT32_C(     9960774), -INT32_C(     8356425), -INT32_C(  1954040621),
        -INT32_C(   578336739), -INT32_C(   875900051),  INT32_C(  1898703006), -INT32_C(   134123339), -INT32_C(   341848527), -INT32_C(  1997928496),  INT32_C(  1468492676),  INT32_C(  1021513247) },
       INT32_C(          22),
      {  INT32_C(  1849618522),  INT32_C(  1878741769),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1353315184), -INT32_C(  1363158528),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   763232348),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2016462653) } },
    { UINT16_C(58429),
      { -INT32_C(  1177756530),  INT32_C(  1311342925),  INT32_C(   404576889),  INT32_C(   807398725), -INT32_C(    56908939), -INT32_C(   569722117),  INT32_C(   273178870), -INT32_C(  1309375197),
        -INT32_C(  1368670111), -INT32_C(  1141009343),  INT32_C(   886250223),  INT32_C(  2103767815), -INT32_C(  1854275690), -INT32_C(  1334868807),  INT32_C(   146847716), -INT32_C(  1631996867) },
       INT32_C(          20),
      { -INT32_C(   924082995),  INT32_C(           0), -INT32_C(  1483636267), -INT32_C(   732757506),  INT32_C(   929024442), -INT32_C(  1346510677),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0), -INT32_C(  1359786703),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1268451064),  INT32_C(  2118159371),  INT32_C(  1138355099) } },
    { UINT16_C(19129),
      {  INT32_C(  1147447408),  INT32_C(  1094151132),  INT32_C(  1648414184), -INT32_C(   823723425),  INT32_C(  1787218602), -INT32_C(  1944140846), -INT32_C(  1364159903), -INT32_C(  1191679673),
        -INT32_C(   285451247), -INT32_C(  1339083832),  INT32_C(  1595043584),  INT32_C(   321845353), -INT32_C(  1786923837), -INT32_C(   668886153),  INT32_C(  1971835437),  INT32_C(  1294827323) },
       INT32_C(          28),
      {  INT32_C(    71715463),  INT32_C(           0),  INT32_C(           0), -INT32_C(    51482715), -INT32_C(  1498911574),  INT32_C(   683797565),  INT32_C(           0),  INT32_C(  2073003668),
         INT32_C(           0), -INT32_C(  1962740932),  INT32_C(           0), -INT32_C(  1858932858),  INT32_C(           0),  INT32_C(           0), -INT32_C(   682066654),  INT32_C(           0) } },
    { UINT16_C(27228),
      {  INT32_C(  1742298196), -INT32_C(   362855492), -INT32_C(   727834026), -INT32_C(   647031368),  INT32_C(  1957404141),  INT32_C(  1073014546),  INT32_C(  1869140020), -INT32_C(   925252492),
        -INT32_C(   600853984),  INT32_C(  1288081397),  INT32_C(  1763730609),  INT32_C(  1732480889),  INT32_C(  1054600748),  INT32_C(   159240149),  INT32_C(   326690207), -INT32_C(   891530839) },
       INT32_C(           4),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1239557485), -INT32_C(  1762567283),  INT32_C(  1253695191),  INT32_C(           0), -INT32_C(   158530746),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   865534124),  INT32_C(           0),  INT32_C(  1949890454),  INT32_C(           0), -INT32_C(  1747124912),  INT32_C(   932076017),  INT32_C(           0) } },
    { UINT16_C(28058),
      {  INT32_C(  1708215365), -INT32_C(   118142027), -INT32_C(  1914232398), -INT32_C(   581059488),  INT32_C(  1053031622), -INT32_C(   326079472), -INT32_C(   570977226), -INT32_C(   750087539),
        -INT32_C(  1825039394),  INT32_C(   411839846), -INT32_C(  1348046001), -INT32_C(   175373521),  INT32_C(   255086591), -INT32_C(   218381124), -INT32_C(   439356584),  INT32_C(  1673009541) },
       INT32_C(          21),
      {  INT32_C(           0),  INT32_C(  1992236713),  INT32_C(           0), -INT32_C(  1944343625), -INT32_C(  1731733377),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1371171154),
         INT32_C(  2077386499),  INT32_C(           0),  INT32_C(  1777726670),  INT32_C(  1711190400),  INT32_C(           0), -INT32_C(  1751228552),  INT32_C(  1797044734),  INT32_C(           0) } },
    { UINT16_C(33310),
      {  INT32_C(  1526033844), -INT32_C(  1453513444),  INT32_C(  1324899354),  INT32_C(  1729279084),  INT32_C(  1985637031),  INT32_C(   143712080),  INT32_C(   972670274),  INT32_C(   347805792),
        -INT32_C(  1569803899), -INT32_C(   263468074), -INT32_C(  1807793368), -INT32_C(  1610919432),  INT32_C(   202725052),  INT32_C(  2014618933), -INT32_C(   877588886), -INT32_C(  1411421146) },
       INT32_C(          29),
      {  INT32_C(           0), -INT32_C(  1792301917),  INT32_C(  1239354243), -INT32_C(  1931323763), -INT32_C(   288666284),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   569804422),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   713298556) } },
    { UINT16_C(38937),
      {  INT32_C(   601637348), -INT32_C(   780872491), -INT32_C(  2010697613),  INT32_C(  1361992764), -INT32_C(  2057332524),  INT32_C(  1139967331),  INT32_C(  2123435824), -INT32_C(   417945085),
        -INT32_C(  1056247060),  INT32_C(   965902022), -INT32_C(   339560017), -INT32_C(   365105130), -INT32_C(   328164472),  INT32_C(  1362059808),  INT32_C(  1959772273),  INT32_C(  1448863082) },
       INT32_C(          24),
      { -INT32_C(   467411903),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1011953244), -INT32_C(   729456744),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   384449776), -INT32_C(  1997770597),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1784044517) } },
    { UINT16_C(43748),
      { -INT32_C(  1704684584), -INT32_C(  1148552578), -INT32_C(   732556700),  INT32_C(   758544382), -INT32_C(  1746032440),  INT32_C(  2021414940), -INT32_C(   958573394), -INT32_C(   881737229),
        -INT32_C(   748300972), -INT32_C(  1282478257),  INT32_C(     8971265),  INT32_C(   590200411), -INT32_C(  2084955290),  INT32_C(   570111859),  INT32_C(  2129189003), -INT32_C(   297182822) },
       INT32_C(          14),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  2070334187),  INT32_C(           0),  INT32_C(           0),  INT32_C(   369565215),  INT32_C(  1428926903),  INT32_C(  1887236828),
         INT32_C(           0), -INT32_C(  1143739165),  INT32_C(           0),  INT32_C(  1872152779),  INT32_C(           0), -INT32_C(   841168770),  INT32_C(           0),  INT32_C(  1449573266) } },
  };

  simde__m512i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi32(test_vec[0].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[0].k, a, INT32_C(          56));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[0].r));

  a = simde_mm512_loadu_epi32(test_vec[1].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[1].k, a, INT32_C(         182));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[1].r));

  a = simde_mm512_loadu_epi32(test_vec[2].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[2].k, a, INT32_C(          19));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[2].r));

  a = simde_mm512_loadu_epi32(test_vec[3].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[3].k, a, INT32_C(         130));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[3].r));

  a = simde_mm512_loadu_epi32(test_vec[4].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[4].k, a, INT32_C(          49));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[4].r));

  a = simde_mm512_loadu_epi32(test_vec[5].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[5].k, a, INT32_C(         140));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[5].r));

  a = simde_mm512_loadu_epi32(test_vec[6].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[6].k, a, INT32_C(          83));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[6].r));

  a = simde_mm512_loadu_epi32(test_vec[7].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[7].k, a, INT32_C(         184));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[7].r));
  #endif

  a = simde_mm512_loadu_epi32(test_vec[8].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[8].k, a, INT32_C(          22));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[8].r));

  a = simde_mm512_loadu_epi32(test_vec[9].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[9].k, a, INT32_C(          20));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[9].r));

  a = simde_mm512_loadu_epi32(test_vec[10].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[10].k, a, INT32_C(          28));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[10].r));

  a = simde_mm512_loadu_epi32(test_vec[11].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[11].k, a, INT32_C(           4));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[11].r));

  a = simde_mm512_loadu_epi32(test_vec[12].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[12].k, a, INT32_C(          21));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[12].r));

  a = simde_mm512_loadu_epi32(test_vec[13].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[13].k, a, INT32_C(          29));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[13].r));

  a = simde_mm512_loadu_epi32(test_vec[14].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[14].k, a, INT32_C(          24));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[14].r));

  a = simde_mm512_loadu_epi32(test_vec[15].a);
  r = simde_mm512_maskz_rol_epi32(test_vec[15].k, a, INT32_C(         14));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[15].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_rol_epi32, r, simde_mm512_setzero_si512(), imm8, k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_rol_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int32_t imm8;
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 1791130803098352704), -INT64_C( 3130149139931427843) },
       INT32_C(         202),
      {  INT64_C( 7890279075467559011),  INT64_C( 4460749535679870802) } },
    { {  INT64_C( 7642029261256077949),  INT64_C( 4185784968170325013) },
       INT32_C(          68),
      { -INT64_C( 6854740335869614122), -INT64_C( 6814416804113006253) } },
    { { -INT64_C(  413815291067910532), -INT64_C( 4011918194003577316) },
       INT32_C(         190),
      {  INT64_C( 4508232195660410271),  INT64_C( 3608706469926493575) } },
    { {  INT64_C( 5844897220275021987),  INT64_C( 6204509097271914544) },
       INT32_C(         173),
      {  INT64_C( 2671877180310535269),  INT64_C( 5622193018980586898) } },
    { {  INT64_C( 6359845298883513809), -INT64_C( 6225287928333175788) },
       INT32_C(         148),
      {  INT64_C( 6460314970823689259),  INT64_C( 6470391489767315893) } },
    { {  INT64_C( 1271574633236171816),  INT64_C( 6715217525415343590) },
       INT32_C(         244),
      { -INT64_C( 4431231590306875640),  INT64_C( 6802074894733114815) } },
    { { -INT64_C( 3878624889376022041),  INT64_C( 1696730829915301395) },
       INT32_C(         137),
      {  INT64_C( 6392416600108289940),  INT64_C( 1729213452285388335) } },
    { {  INT64_C( 3910347420833612837),  INT64_C( 1312799135472024268) },
       INT32_C(          90),
      {  INT64_C(  836715225814733153),  INT64_C( 7984037625013526527) } },
    { { -INT64_C( 8097551068840308835),  INT64_C( 6512325903802158199) },
       INT32_C(          36),
      { -INT64_C(  935348112283958455), -INT64_C( 2649023172690125187) } },
    { { -INT64_C( 1460018685074840524),  INT64_C(  136120421134663334) },
       INT32_C(          17),
      { -INT64_C( 1046069466608576647),  INT64_C( 3574319685456102343) } },
    { {  INT64_C( 6237492842103915598),  INT64_C( 3270515412550683745) },
       INT32_C(          44),
      {  INT64_C( 6072230436743615338),  INT64_C( 6973281784222386520) } },
    { {  INT64_C( 7669060727559651486), -INT64_C(  936512040632910212) },
       INT32_C(          29),
      {  INT64_C( 3270440247263870787),  INT64_C( 6432934463065299688) } },
    { {  INT64_C( 3475433127526322077), -INT64_C( 1341761712016894888) },
       INT32_C(          20),
      { -INT64_C( 9205096723480640589), -INT64_C( 5958438000071354863) } },
    { {  INT64_C( 4468234252715788748),  INT64_C( 2276659889876847596) },
       INT32_C(          10),
      {  INT64_C(  679344500998877432),  INT64_C( 7009973946488434814) } },
    { { -INT64_C( 9013610034649083097),  INT64_C( 3162492081253007624) },
       INT32_C(           9),
      { -INT64_C( 3282319312942641403), -INT64_C( 4117532884900638633) } },
    { { -INT64_C( 4365440247706687696),  INT64_C( 8849147816151726763) },
       INT32_C(          55),
      { -INT64_C( 7466487233409343501),  INT64_C( 6178207782071259869) } },
  };

  simde__m128i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi64(test_vec[0].a);
  r = simde_mm_rol_epi64(a, INT32_C(         202));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[0].r));

  a = simde_x_mm_loadu_epi64(test_vec[1].a);
  r = simde_mm_rol_epi64(a, INT32_C(          68));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[1].r));

  a = simde_x_mm_loadu_epi64(test_vec[2].a);
  r = simde_mm_rol_epi64(a, INT32_C(         190));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[2].r));

  a = simde_x_mm_loadu_epi64(test_vec[3].a);
  r = simde_mm_rol_epi64(a, INT32_C(         173));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  a = simde_x_mm_loadu_epi64(test_vec[4].a);
  r = simde_mm_rol_epi64(a, INT32_C(         148));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  a = simde_x_mm_loadu_epi64(test_vec[5].a);
  r = simde_mm_rol_epi64(a, INT32_C(         244));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[5].r));

  a = simde_x_mm_loadu_epi64(test_vec[6].a);
  r = simde_mm_rol_epi64(a, INT32_C(         137));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[6].r));

  a = simde_x_mm_loadu_epi64(test_vec[7].a);
  r = simde_mm_rol_epi64(a, INT32_C(          90));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[7].r));
  #endif

  a = simde_x_mm_loadu_epi64(test_vec[8].a);
  r = simde_mm_rol_epi64(a, INT32_C(          36));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[8].r));

  a = simde_x_mm_loadu_epi64(test_vec[9].a);
  r = simde_mm_rol_epi64(a, INT32_C(          17));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[9].r));

  a = simde_x_mm_loadu_epi64(test_vec[10].a);
  r = simde_mm_rol_epi64(a, INT32_C(          44));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[10].r));

  a = simde_x_mm_loadu_epi64(test_vec[11].a);
  r = simde_mm_rol_epi64(a, INT32_C(          29));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[11].r));

  a = simde_x_mm_loadu_epi64(test_vec[12].a);
  r = simde_mm_rol_epi64(a, INT32_C(          20));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[12].r));

  a = simde_x_mm_loadu_epi64(test_vec[13].a);
  r = simde_mm_rol_epi64(a, INT32_C(          10));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[13].r));

  a = simde_x_mm_loadu_epi64(test_vec[14].a);
  r = simde_mm_rol_epi64(a, INT32_C(           9));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[14].r));

  a = simde_x_mm_loadu_epi64(test_vec[15].a);
  r = simde_mm_rol_epi64(a, INT32_C(         55));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[15].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    int imm8 = simde_test_codegen_random_i32() & 63;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_rol_epi64, r, simde_mm_setzero_si128(), imm8, a);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_rol_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int32_t imm8;
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C(  913047193543677046), -INT64_C( 4291496680946959004) },
      UINT8_C(226),
      {  INT64_C( 4074458287786883765), -INT64_C( 1979894462254244455) },
       INT32_C(         169),
      { -INT64_C(  913047193543677046),  INT64_C( 2682794941612094457) } },
    { {  INT64_C( 3393405855792775704),  INT64_C( 1126674881917868861) },
      UINT8_C( 34),
      { -INT64_C( 2719127599669622995), -INT64_C( 5181002736853637058) },
       INT32_C(         164),
      {  INT64_C( 3393405855792775704),  INT64_C( 1743601053260453728) } },
    { {  INT64_C( 6806803390483238086), -INT64_C( 6397297517171538623) },
      UINT8_C(242),
      {  INT64_C( 7357247936779026812), -INT64_C( 4773681254240693429) },
       INT32_C(          39),
      {  INT64_C( 6806803390483238086),  INT64_C(  390025219407681661) } },
    { {  INT64_C( 8370632846167554520),  INT64_C( 6327442380650107311) },
      UINT8_C(201),
      {  INT64_C( 4750470532474125801), -INT64_C( 4753217331874190641) },
       INT32_C(          54),
      {  INT64_C( 8813680002516059439),  INT64_C( 6327442380650107311) } },
    { {  INT64_C( 7545086084097272721), -INT64_C( 7999441007954293674) },
      UINT8_C( 85),
      {  INT64_C( 7464810088136757737), -INT64_C( 5163857125333641634) },
       INT32_C(         167),
      { -INT64_C( 7896792893532496695), -INT64_C( 7999441007954293674) } },
    { {  INT64_C( 7584839279575364205), -INT64_C( 2577216069689224513) },
      UINT8_C( 56),
      {  INT64_C( 3275907905388758227), -INT64_C( 6136151501202772302) },
       INT32_C(         134),
      {  INT64_C( 7584839279575364205), -INT64_C( 2577216069689224513) } },
    { { -INT64_C( 2879293344213026924),  INT64_C(  930741174569920237) },
      UINT8_C(  4),
      {  INT64_C( 1100883876533123424), -INT64_C(  729900081199320584) },
       INT32_C(         232),
      { -INT64_C( 2879293344213026924),  INT64_C(  930741174569920237) } },
    { {  INT64_C( 8961960760247239502), -INT64_C( 5539367456927093711) },
      UINT8_C( 87),
      {  INT64_C( 3969810201268175463), -INT64_C( 4968955864697336713) },
       INT32_C(          63),
      { -INT64_C( 7238466936220688077), -INT64_C( 2484477932348668357) } },
  };

  simde__m128i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm_loadu_epi64(test_vec[0].src);
  a = simde_x_mm_loadu_epi64(test_vec[0].a);
  r = simde_mm_mask_rol_epi64(src, test_vec[0].k, a, INT32_C(         169));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[0].r));

  src = simde_x_mm_loadu_epi64(test_vec[1].src);
  a = simde_x_mm_loadu_epi64(test_vec[1].a);
  r = simde_mm_mask_rol_epi64(src, test_vec[1].k, a, INT32_C(         164));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[1].r));
  #endif

  src = simde_x_mm_loadu_epi64(test_vec[2].src);
  a = simde_x_mm_loadu_epi64(test_vec[2].a);
  r = simde_mm_mask_rol_epi64(src, test_vec[2].k, a, INT32_C(          39));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[2].r));

  src = simde_x_mm_loadu_epi64(test_vec[3].src);
  a = simde_x_mm_loadu_epi64(test_vec[3].a);
  r = simde_mm_mask_rol_epi64(src, test_vec[3].k, a, INT32_C(          54));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm_loadu_epi64(test_vec[4].src);
  a = simde_x_mm_loadu_epi64(test_vec[4].a);
  r = simde_mm_mask_rol_epi64(src, test_vec[4].k, a, INT32_C(         167));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  src = simde_x_mm_loadu_epi64(test_vec[5].src);
  a = simde_x_mm_loadu_epi64(test_vec[5].a);
  r = simde_mm_mask_rol_epi64(src, test_vec[5].k, a, INT32_C(         134));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[5].r));

  src = simde_x_mm_loadu_epi64(test_vec[6].src);
  a = simde_x_mm_loadu_epi64(test_vec[6].a);
  r = simde_mm_mask_rol_epi64(src, test_vec[6].k, a, INT32_C(         232));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[6].r));
  #endif

  src = simde_x_mm_loadu_epi64(test_vec[7].src);
  a = simde_x_mm_loadu_epi64(test_vec[7].a);
  r = simde_mm_mask_rol_epi64(src, test_vec[7].k, a, INT32_C(          63));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_rol_epi64, r, simde_mm_setzero_si128(), imm8, src, k, a);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_rol_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int32_t imm8;
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(159),
      {  INT64_C( 7621128820074723084),  INT64_C(  251684160778803811) },
       INT32_C(          64),
      {  INT64_C( 7621128820074723084),  INT64_C(  251684160778803811) } },
    { UINT8_C(212),
      { -INT64_C( 8178312626128010186), -INT64_C( 2643288444803342511) },
       INT32_C(         234),
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(138),
      { -INT64_C( 1470439087147881116), -INT64_C( 4358531194856314048) },
       INT32_C(         227),
      {  INT64_C(                   0),  INT64_C( 2381095810283280324) } },
    { UINT8_C(172),
      {  INT64_C( 5055498425640103197),  INT64_C( 6530093454719693761) },
       INT32_C(          37),
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(171),
      {  INT64_C( 7039954478955399198), -INT64_C( 1285516898359943437) },
       INT32_C(          21),
      {  INT64_C( 2996056833703818846), -INT64_C( 6475032995966368483) } },
    { UINT8_C( 26),
      {  INT64_C( 2524211007055146974), -INT64_C( 5678508337029598627) },
       INT32_C(         148),
      {  INT64_C(                   0),  INT64_C( 3174567262918742814) } },
    { UINT8_C( 17),
      { -INT64_C( 4441372681182501691), -INT64_C( 1471519163362019364) },
       INT32_C(          36),
      { -INT64_C( 1161281795252997826),  INT64_C(                   0) } },
    { UINT8_C(248),
      { -INT64_C( 1229079961875605715),  INT64_C( 1484394575827239521) },
       INT32_C(         254),
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  simde__m128i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi64(test_vec[0].a);
  r = simde_mm_maskz_rol_epi64(test_vec[0].k, a, INT32_C(          64));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[0].r));

  a = simde_x_mm_loadu_epi64(test_vec[1].a);
  r = simde_mm_maskz_rol_epi64(test_vec[1].k, a, INT32_C(         234));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[1].r));

  a = simde_x_mm_loadu_epi64(test_vec[2].a);
  r = simde_mm_maskz_rol_epi64(test_vec[2].k, a, INT32_C(         227));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[2].r));
  #endif

  a = simde_x_mm_loadu_epi64(test_vec[3].a);
  r = simde_mm_maskz_rol_epi64(test_vec[3].k, a, INT32_C(          37));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  a = simde_x_mm_loadu_epi64(test_vec[4].a);
  r = simde_mm_maskz_rol_epi64(test_vec[4].k, a, INT32_C(          21));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi64(test_vec[5].a);
  r = simde_mm_maskz_rol_epi64(test_vec[5].k, a, INT32_C(         148));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[5].r));
  #endif

  a = simde_x_mm_loadu_epi64(test_vec[6].a);
  r = simde_mm_maskz_rol_epi64(test_vec[6].k, a, INT32_C(          36));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[6].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi64(test_vec[7].a);
  r = simde_mm_maskz_rol_epi64(test_vec[7].k, a, INT32_C(         254));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[7].r));
  #endif

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_rol_epi64, r, simde_mm_setzero_si128(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_rol_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int32_t imm8;
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 8758829066757705650),  INT64_C( 3870422979563339261), -INT64_C( 6524855710318620263), -INT64_C( 2859699835249407982) },
       INT32_C(         221),
      {  INT64_C( 2922468879658759060),  INT64_C( 3561282701618499622), -INT64_C( 6415111367448174135), -INT64_C( 2992948706014524988) } },
    { { -INT64_C( 7428307809861064095),  INT64_C( 9055212936604000218), -INT64_C( 8329168475672928861), -INT64_C( 2412662225913989081) },
       INT32_C(          42),
      { -INT64_C( 2114010787538952837),  INT64_C( 3926973908230652367), -INT64_C( 8613540893453608236), -INT64_C( 7863109602751941611) } },
    { { -INT64_C(  710452982991739179),  INT64_C( 5900725873626369419), -INT64_C( 9035275264428520336),  INT64_C( 8177865795680870593) },
       INT32_C(         196),
      {  INT64_C( 7079496345841724767),  INT64_C( 2177893609474152629),  INT64_C( 3009548358820087560),  INT64_C( 1718644214927068183) } },
    { { -INT64_C(  263755173623479139), -INT64_C( 8461653990645613941), -INT64_C( 1433994819515175061), -INT64_C( 2641222377532451318) },
       INT32_C(         194),
      { -INT64_C( 1055020694493916553),  INT64_C( 3046872184836647470), -INT64_C( 5735979278060700241),  INT64_C( 7881854563579746347) } },
    { {  INT64_C( 1896893490547153613),  INT64_C( 7269285980335826504), -INT64_C( 3533163448473945570), -INT64_C(  665499028101181652) },
       INT32_C(           6),
      { -INT64_C( 7726025120949030074),  INT64_C( 4065700898754105881), -INT64_C( 4761531817817897037), -INT64_C( 5698449651056522435) } },
    { { -INT64_C( 7084626718950645071),  INT64_C( 1824048598120238858), -INT64_C( 4675984809126312192),  INT64_C( 2584508124966018621) },
       INT32_C(         166),
      { -INT64_C( 5969331745892965826),  INT64_C(   28079904886399562),  INT64_C( 4166322441727256011), -INT64_C( 1335441220939211632) } },
    { { -INT64_C( 2081282761732404245),  INT64_C( 5497739236695961118), -INT64_C( 5191030490390567307),  INT64_C( 5880003907288748997) },
       INT32_C(         195),
      {  INT64_C( 1796481979850317663),  INT64_C( 7088425746148585714), -INT64_C( 4634755775705435219), -INT64_C( 8300200962818662870) } },
    { { -INT64_C( 8615668857891101647),  INT64_C( 7208820578798844387),  INT64_C( 4166945468076261282),  INT64_C(  202611206811970798) },
       INT32_C(          54),
      {  INT64_C(  892306186355064921),  INT64_C( 8707994343926281518), -INT64_C( 1689284177207638273),  INT64_C( 4287624707763364507) } },
  };

  simde__m256i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi64(test_vec[0].a);
  r = simde_mm256_rol_epi64(a, INT32_C(         221));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[0].r));
  #endif

  a = simde_x_mm256_loadu_epi64(test_vec[1].a);
  r = simde_mm256_rol_epi64(a, INT32_C(          42));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[1].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi64(test_vec[2].a);
  r = simde_mm256_rol_epi64(a, INT32_C(         196));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[2].r));

  a = simde_x_mm256_loadu_epi64(test_vec[3].a);
  r = simde_mm256_rol_epi64(a, INT32_C(         194));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[3].r));
  #endif

  a = simde_x_mm256_loadu_epi64(test_vec[4].a);
  r = simde_mm256_rol_epi64(a, INT32_C(           6));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[4].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi64(test_vec[5].a);
  r = simde_mm256_rol_epi64(a, INT32_C(         166));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[5].r));

  a = simde_x_mm256_loadu_epi64(test_vec[6].a);
  r = simde_mm256_rol_epi64(a, INT32_C(         195));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[6].r));
  #endif

  a = simde_x_mm256_loadu_epi64(test_vec[7].a);
  r = simde_mm256_rol_epi64(a, INT32_C(          54));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_rol_epi64, r, simde_mm256_setzero_si256(), imm8, a);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_rol_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int32_t imm8;
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 7491063461111087153), -INT64_C( 1779176849717586875),  INT64_C( 6894354135666139662),  INT64_C( 2142221723349646716) },
      UINT8_C(114),
      { -INT64_C( 1155872754056310709),  INT64_C( 5667193183348710783), -INT64_C( 3733417778055700214), -INT64_C( 1674433487658360163) },
       INT32_C(           7),
      { -INT64_C( 7491063461111087153),  INT64_C( 5977708593962467239),  INT64_C( 6894354135666139662),  INT64_C( 2142221723349646716) } },
    { { -INT64_C( 7617605214999048911), -INT64_C( 2414842476882498114),  INT64_C( 3236896878250077693), -INT64_C( 8221976033506316549) },
      UINT8_C( 58),
      {  INT64_C( 8306954957427588534),  INT64_C( 4169735725673222175),  INT64_C( 1245796578817046666), -INT64_C( 1733610765116683254) },
       INT32_C(          55),
      { -INT64_C( 7617605214999048911),  INT64_C( 1125036722677088520),  INT64_C( 3236896878250077693),  INT64_C(  392930808682985126) } },
    { {  INT64_C( 6255555725300382160), -INT64_C( 8580949221437362926), -INT64_C( 5688602131010342066),  INT64_C( 7274732404807958272) },
      UINT8_C(196),
      { -INT64_C( 3356902306295753947),  INT64_C( 2457135739603125619),  INT64_C( 9160133076358164760),  INT64_C( 8195275119377209325) },
       INT32_C(         202),
      {  INT64_C( 6255555725300382160), -INT64_C( 8580949221437362926),  INT64_C( 9030280746308493820),  INT64_C( 7274732404807958272) } },
    { {  INT64_C( 2696448048124342572),  INT64_C( 8533453737539699764),  INT64_C( 3396568315755596606),  INT64_C( 6068434640365018751) },
      UINT8_C(155),
      { -INT64_C( 2026347846318296074),  INT64_C( 2695491896231931199), -INT64_C( 7652961885686820028),  INT64_C( 4818025096079480024) },
       INT32_C(           4),
      {  INT64_C( 4471922606326366062),  INT64_C( 6234382192291795954),  INT64_C( 3396568315755596606),  INT64_C( 3301425242433473924) } },
    { { -INT64_C( 7634130246836039771), -INT64_C( 4540258402915617171),  INT64_C( 2960291974497028346),  INT64_C( 5082411823373480482) },
      UINT8_C( 41),
      { -INT64_C( 5883184110051710258), -INT64_C( 3371938239975257226),  INT64_C( 1009042835525994445),  INT64_C( 9063200335231592003) },
       INT32_C(          31),
      {  INT64_C( 8508026917133049244), -INT64_C( 4540258402915617171),  INT64_C( 2960291974497028346), -INT64_C( 3542341546246178217) } },
    { { -INT64_C( 2857605641788800089), -INT64_C( 5845293457200280778), -INT64_C( 5255865655600815569),  INT64_C( 7554118503867143519) },
      UINT8_C( 97),
      {  INT64_C( 7480207249641604571), -INT64_C( 7621876502627757390), -INT64_C( 7985631199632642973),  INT64_C( 6668347257870527370) },
       INT32_C(          63),
      { -INT64_C( 5483268412033973523), -INT64_C( 5845293457200280778), -INT64_C( 5255865655600815569),  INT64_C( 7554118503867143519) } },
    { {  INT64_C( 5440204964351952323),  INT64_C( 2330191026492389412), -INT64_C( 5870157141575105578), -INT64_C( 8063694248110058563) },
      UINT8_C(197),
      {  INT64_C( 4412868495207564700), -INT64_C( 6998662974040586871), -INT64_C( 2579863531334909838), -INT64_C( 2068776999963775099) },
       INT32_C(          63),
      {  INT64_C( 2206434247603782350),  INT64_C( 2330191026492389412),  INT64_C( 7933440271187320889), -INT64_C( 8063694248110058563) } },
    { {  INT64_C( 2009347603484981839), -INT64_C( 3869570637362511516), -INT64_C(  789167128478056959),  INT64_C( 5516300404588566154) },
      UINT8_C( 15),
      { -INT64_C( 3993240383729556082),  INT64_C( 3921109941054237667),  INT64_C( 5986929858849271867), -INT64_C(  390232703262204239) },
       INT32_C(         194),
      {  INT64_C( 2473782538791327291), -INT64_C( 2762304309492600948),  INT64_C( 5500975361687535853), -INT64_C( 1560930813048816953) } },
  };

  simde__m256i src, a, r;

  src = simde_x_mm256_loadu_epi64(test_vec[0].src);
  a = simde_x_mm256_loadu_epi64(test_vec[0].a);
  r = simde_mm256_mask_rol_epi64(src, test_vec[0].k, a, INT32_C(           7));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[0].r));

  src = simde_x_mm256_loadu_epi64(test_vec[1].src);
  a = simde_x_mm256_loadu_epi64(test_vec[1].a);
  r = simde_mm256_mask_rol_epi64(src, test_vec[1].k, a, INT32_C(          55));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[1].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm256_loadu_epi64(test_vec[2].src);
  a = simde_x_mm256_loadu_epi64(test_vec[2].a);
  r = simde_mm256_mask_rol_epi64(src, test_vec[2].k, a, INT32_C(         202));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[2].r));
  #endif

  src = simde_x_mm256_loadu_epi64(test_vec[3].src);
  a = simde_x_mm256_loadu_epi64(test_vec[3].a);
  r = simde_mm256_mask_rol_epi64(src, test_vec[3].k, a, INT32_C(           4));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[3].r));

  src = simde_x_mm256_loadu_epi64(test_vec[4].src);
  a = simde_x_mm256_loadu_epi64(test_vec[4].a);
  r = simde_mm256_mask_rol_epi64(src, test_vec[4].k, a, INT32_C(          31));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[4].r));

  src = simde_x_mm256_loadu_epi64(test_vec[5].src);
  a = simde_x_mm256_loadu_epi64(test_vec[5].a);
  r = simde_mm256_mask_rol_epi64(src, test_vec[5].k, a, INT32_C(          63));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[5].r));

  src = simde_x_mm256_loadu_epi64(test_vec[6].src);
  a = simde_x_mm256_loadu_epi64(test_vec[6].a);
  r = simde_mm256_mask_rol_epi64(src, test_vec[6].k, a, INT32_C(          63));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[6].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm256_loadu_epi64(test_vec[7].src);
  a = simde_x_mm256_loadu_epi64(test_vec[7].a);
  r = simde_mm256_mask_rol_epi64(src, test_vec[7].k, a, INT32_C(         194));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[7].r));
  #endif

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_rol_epi64, r, simde_mm256_setzero_si256(), imm8, src, k, a);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_rol_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int32_t imm8;
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(205),
      { -INT64_C( 1088998805511040576), -INT64_C( 3066750146564122237), -INT64_C( 5758683269935217717), -INT64_C(  283098700816707423) },
       INT32_C(         205),
      {  INT64_C( 7145916928978591260),  INT64_C(                   0), -INT64_C( 6808750833980049918),  INT64_C( 5145196196936302466) } },
    { UINT8_C(219),
      { -INT64_C(  494602922737395701), -INT64_C( 8495919209509488831),  INT64_C( 8561185917340797059), -INT64_C(  134988196726191229) },
       INT32_C(         132),
      { -INT64_C( 7913646763798331201), -INT64_C( 6807498836184959976),  INT64_C(                   0), -INT64_C( 2159811147619059649) } },
    { UINT8_C( 79),
      { -INT64_C(  811890904019123899), -INT64_C( 2111894168313313875), -INT64_C( 2911389779781933094), -INT64_C(   29234114593057078) },
       INT32_C(         229),
      { -INT64_C( 5604684937212809017), -INT64_C( 3537377686796014034), -INT64_C( 6006399634961511052),  INT64_C(  824960687884498761) } },
    { UINT8_C(190),
      { -INT64_C( 2184559359446720521), -INT64_C( 6834950246653783661),  INT64_C( 8883830032421354744),  INT64_C( 8949720658575640652) },
       INT32_C(          42),
      {  INT64_C(                   0), -INT64_C( 1277247112961860886), -INT64_C( 5768018289056718275), -INT64_C( 9141970858247580203) } },
    { UINT8_C(129),
      { -INT64_C(   76614386951331224), -INT64_C( 5743911428784942860), -INT64_C( 1108887004109814577),  INT64_C( 4234822714023156132) },
       INT32_C(         254),
      {  INT64_C( 4592532421689555098),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(169),
      {  INT64_C( 1778797138564455203), -INT64_C( 3692390550039207977), -INT64_C( 1691464719225736805),  INT64_C( 1728682917399871866) },
       INT32_C(          30),
      { -INT64_C( 5987704167061527644),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1529517837234692349) } },
    { UINT8_C( 41),
      { -INT64_C( 5893631158742038406),  INT64_C( 2944506927012971102),  INT64_C( 3403023308418106499), -INT64_C( 7585752703007108876) },
       INT32_C(         198),
      { -INT64_C( 8257512685299425621),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 5872827076006626011) } },
    { UINT8_C( 87),
      {  INT64_C( 7645639292658984101), -INT64_C( 2589513824899087712), -INT64_C( 8370115220587135125), -INT64_C( 9067215144210043623) },
       INT32_C(         235),
      { -INT64_C( 6258548480971412163),  INT64_C( 7644023503847893807), -INT64_C( 9080562661728162338),  INT64_C(                   0) } },
  };

  simde__m256i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi64(test_vec[0].a);
  r = simde_mm256_maskz_rol_epi64(test_vec[0].k, a, INT32_C(         205));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[0].r));

  a = simde_x_mm256_loadu_epi64(test_vec[1].a);
  r = simde_mm256_maskz_rol_epi64(test_vec[1].k, a, INT32_C(         132));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[1].r));

  a = simde_x_mm256_loadu_epi64(test_vec[2].a);
  r = simde_mm256_maskz_rol_epi64(test_vec[2].k, a, INT32_C(         229));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[2].r));
  #endif

  a = simde_x_mm256_loadu_epi64(test_vec[3].a);
  r = simde_mm256_maskz_rol_epi64(test_vec[3].k, a, INT32_C(          42));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[3].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi64(test_vec[4].a);
  r = simde_mm256_maskz_rol_epi64(test_vec[4].k, a, INT32_C(         254));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[4].r));
  #endif

  a = simde_x_mm256_loadu_epi64(test_vec[5].a);
  r = simde_mm256_maskz_rol_epi64(test_vec[5].k, a, INT32_C(          30));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[5].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi64(test_vec[6].a);
  r = simde_mm256_maskz_rol_epi64(test_vec[6].k, a, INT32_C(         198));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[6].r));

  a = simde_x_mm256_loadu_epi64(test_vec[7].a);
  r = simde_mm256_maskz_rol_epi64(test_vec[7].k, a, INT32_C(         235));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[7].r));
  #endif

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_rol_epi64, r, simde_mm256_setzero_si256(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_rol_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int32_t imm8;
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 5258584720530566522),  INT64_C(   22799415887777983), -INT64_C( 9035946788803732596),  INT64_C( 2735770384407509149),
         INT64_C( 8795337360416275670), -INT64_C( 5903243698335440352), -INT64_C( 7720738805882152942), -INT64_C( 4831226712852169180) },
       INT32_C(         133),
      {  INT64_C( 2254014393592164169),  INT64_C(  729581308408895456),  INT64_C( 5997607937633382800), -INT64_C( 4689068067507465308),
         INT64_C( 4749634427677547215), -INT64_C( 4436357609638575083), -INT64_C( 7255968830004723118), -INT64_C( 7025302221593000809) } },
    { { -INT64_C( 2824353216358411366), -INT64_C( 1170275129183772584),  INT64_C(  124011833060465860), -INT64_C( 7971017335773483619),
         INT64_C( 6080731394828082133),  INT64_C(  495539178751126008), -INT64_C( 7765709927176248546),  INT64_C( 1070757445769819988) },
       INT32_C(          51),
      { -INT64_C( 7145305578503023156),  INT64_C(  200267327567256631), -INT64_C( 1864475107568169956),  INT64_C( 7848801125929653741),
        -INT64_C( 2401928124420564392),  INT64_C( 5746653615147159039),  INT64_C( 1798240088496918395), -INT64_C( 4998864878685233737) } },
    { {  INT64_C( 2750085174254632000),  INT64_C( 7213670861917391557), -INT64_C( 8690910105950398781), -INT64_C( 6329476777171927097),
        -INT64_C( 5389388253392425686),  INT64_C( 4676624813737402901),  INT64_C( 6260209706398703371), -INT64_C( 3671987704019454470) },
       INT32_C(          39),
      { -INT64_C( 4468098513973939556), -INT64_C( 7636589076257327375), -INT64_C(  239990662003972341),  INT64_C( 5377266980121687037),
        -INT64_C( 1092521643218700281),  INT64_C( 5490181104987717313), -INT64_C( 6021447205399967828),  INT64_C( 2934936723949179313) } },
    { { -INT64_C( 1041064389764181258), -INT64_C( 2125828409384602854),  INT64_C( 8692380304783466309), -INT64_C( 8339784056593536252),
        -INT64_C( 8171178490447065292), -INT64_C( 7220058179190338408), -INT64_C( 7791090399986449006),  INT64_C( 9028029814966986279) },
       INT32_C(          17),
      { -INT64_C( 3825781941212421350),  INT64_C( 1487958524111996159),  INT64_C( 1417084055459656003),  INT64_C( 4984454052626110598),
         INT64_C( 5253819698824944948),  INT64_C( 7398806611381270426), -INT64_C(  495730536776128576),  INT64_C(  185067032508562068) } },
    { { -INT64_C( 2195002841388237050), -INT64_C( 1444152050480032005),  INT64_C( 4879717249193006547), -INT64_C( 1453282907173944514),
        -INT64_C( 6119807296176723803), -INT64_C( 5066216537112080534), -INT64_C( 6250595596723081469), -INT64_C( 8268663993087294865) },
       INT32_C(         181),
      { -INT64_C( 2243864393161653609), -INT64_C( 2342576958601056374), -INT64_C( 5014627310452650022),  INT64_C( 7484272969895245824),
         INT64_C( 1492206889130668381), -INT64_C( 1344546427499919567), -INT64_C( 2272866260825942427),  INT64_C( 5616454901368004352) } },
    { {  INT64_C( 5047772534721860061),  INT64_C( 6375323480576999032), -INT64_C( 6493633495670015202), -INT64_C( 4043122051023494713),
        -INT64_C( 5230901009222535998),  INT64_C( 4044140217101412313), -INT64_C( 2032910021758213785), -INT64_C( 5802250481734452024) },
       INT32_C(          55),
      { -INT64_C( 1251148964931860248),  INT64_C( 4335907445948678111), -INT64_C( 8119162207188123299), -INT64_C( 2025509355817887472),
         INT64_C( 7015398815164335994), -INT64_C( 1397224372378068557), -INT64_C( 5480347674268769648),  INT64_C( 7230455680339619966) } },
    { { -INT64_C( 5096841536353715804), -INT64_C( 6946319170699959539),  INT64_C( 5537424640147874654),  INT64_C( 9210930905449452069),
         INT64_C( 8096979972494459141),  INT64_C( 7333969087395352739),  INT64_C( 5876180655524235745),  INT64_C( 6345715170403059638) },
       INT32_C(         131),
      { -INT64_C( 3881244143410623195), -INT64_C(  230321144471021460),  INT64_C( 7405908973763894002), -INT64_C(   99529051242589909),
        -INT64_C( 9011136514882533333),  INT64_C( 3331520478034167067), -INT64_C( 8330786976934768886), -INT64_C( 4574510857904177742) } },
    { { -INT64_C( 5541613727526790067),  INT64_C( 6114660313881698233),  INT64_C( 4849625762386831366), -INT64_C( 5242021284193542698),
        -INT64_C( 8478941291350616331),  INT64_C( 1520810466444930206), -INT64_C( 1397489078528458391), -INT64_C( 4206776770126006403) },
       INT32_C(          28),
      { -INT64_C( 3529302836809464902), -INT64_C( 8524876507954431438), -INT64_C(  303317323271056050), -INT64_C( 6509471823792174698),
         INT64_C( 1880949313516162045), -INT64_C(  256046803738054640),  INT64_C( 7317553445211845105),  INT64_C( 1041566780278564973) } },
  };

  simde__m512i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi64(test_vec[0].a);
  r = simde_mm512_rol_epi64(a, INT32_C(         133));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[0].r));
  #endif

  a = simde_mm512_loadu_epi64(test_vec[1].a);
  r = simde_mm512_rol_epi64(a, INT32_C(          51));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[1].r));

  a = simde_mm512_loadu_epi64(test_vec[2].a);
  r = simde_mm512_rol_epi64(a, INT32_C(          39));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[2].r));

  a = simde_mm512_loadu_epi64(test_vec[3].a);
  r = simde_mm512_rol_epi64(a, INT32_C(          17));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[3].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi64(test_vec[4].a);
  r = simde_mm512_rol_epi64(a, INT32_C(         181));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[4].r));
  #endif

  a = simde_mm512_loadu_epi64(test_vec[5].a);
  r = simde_mm512_rol_epi64(a, INT32_C(          55));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[5].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi64(test_vec[6].a);
  r = simde_mm512_rol_epi64(a, INT32_C(         131));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[6].r));
  #endif

  a = simde_mm512_loadu_epi64(test_vec[7].a);
  r = simde_mm512_rol_epi64(a, INT32_C(          28));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_rol_epi64, r, simde_mm512_setzero_si512(), imm8, a);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_rol_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t a[8];
    const int32_t imm8;
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 3849061620818426373),  INT64_C( 6728408934682101406),  INT64_C(  189309731881024316), -INT64_C( 8637572568787239401),
        -INT64_C( 3079734036274570777), -INT64_C( 1891163670279582436), -INT64_C( 5517685126934426824),  INT64_C( 5298493079104664700) },
      UINT8_C(160),
      {  INT64_C( 2767370270444836788), -INT64_C( 7422576990322898040),  INT64_C(  652995371164002132),  INT64_C( 5509789758348005326),
        -INT64_C( 9093894674366116597), -INT64_C( 6489894521381938230), -INT64_C( 2771888555453635413), -INT64_C( 5532349259775478955) },
       INT32_C(         114),
      {  INT64_C( 3849061620818426373),  INT64_C( 6728408934682101406),  INT64_C(  189309731881024316), -INT64_C( 8637572568787239401),
        -INT64_C( 3079734036274570777),  INT64_C( 8010381725459111194), -INT64_C( 5517685126934426824), -INT64_C( 3650505165785286977) } },
    { {  INT64_C( 1220250922038076622),  INT64_C( 1054384385487658870), -INT64_C( 4218017847862351565),  INT64_C( 5591730756527894460),
         INT64_C( 3442392479480317429), -INT64_C( 7221819524682581324),  INT64_C(  143440385231072795),  INT64_C( 4257529229080491337) },
      UINT8_C( 77),
      {  INT64_C( 3424202146697375995), -INT64_C( 5651399591923860091),  INT64_C( 4339772154061441622),  INT64_C( 1313852722008752422),
        -INT64_C(  246738696883977810), -INT64_C( 5595435166509880667),  INT64_C( 7841570997426868175), -INT64_C( 4466279913735170596) },
       INT32_C(         215),
      { -INT64_C( 2672741825317977446),  INT64_C( 1054384385487658870), -INT64_C( 2019728758430360325),  INT64_C(  826201077124242911),
         INT64_C( 3442392479480317429), -INT64_C( 7221819524682581324), -INT64_C( 6680156390440933011),  INT64_C( 4257529229080491337) } },
    { {  INT64_C( 4584310257480284496), -INT64_C( 8275483854669482046),  INT64_C( 7150683007894616430),  INT64_C( 8651497522606719466),
        -INT64_C( 2799536821557634556),  INT64_C( 1790341012458706691),  INT64_C( 1242042586452120202), -INT64_C( 5583931730645785888) },
      UINT8_C( 61),
      { -INT64_C( 2882816404596942353), -INT64_C(  886476709434340969),  INT64_C( 3061368887805840637), -INT64_C(  856376596278770435),
         INT64_C( 3871950670851436835), -INT64_C( 3149404997329011401), -INT64_C( 8318169886120450916),  INT64_C( 1471422472945231729) },
       INT32_C(         252),
      { -INT64_C(  180176025287308898), -INT64_C( 8275483854669482046), -INT64_C( 3267428958332675889), -INT64_C( 2359366546481117105),
         INT64_C( 3700761430748755730),  INT64_C( 9026534224521712595),  INT64_C( 1242042586452120202), -INT64_C( 5583931730645785888) } },
    { { -INT64_C( 4046715229209316536),  INT64_C( 1602732295001481789),  INT64_C( 2729198091988291065), -INT64_C( 1283471302245921894),
         INT64_C( 7754148725859942628),  INT64_C( 4397064943292463208),  INT64_C( 5884384709922236240), -INT64_C(  547161978013490477) },
      UINT8_C( 24),
      { -INT64_C( 6808403146666750506),  INT64_C( 2290400881547768566), -INT64_C( 2799506179458970166), -INT64_C( 2504593998884266226),
         INT64_C( 3151530406796952498), -INT64_C( 8104950160273595665), -INT64_C( 8031316153045197892),  INT64_C( 1192595589346785447) },
       INT32_C(         119),
      { -INT64_C( 4046715229209316536),  INT64_C( 1602732295001481789),  INT64_C( 2729198091988291065), -INT64_C( 8687831866724387121),
        -INT64_C( 2804090834653414207),  INT64_C( 4397064943292463208),  INT64_C( 5884384709922236240), -INT64_C(  547161978013490477) } },
    { {  INT64_C( 5717175188174923778), -INT64_C( 4946710266610983445), -INT64_C( 4963246763511388727),  INT64_C( 3681965586537819381),
         INT64_C( 6321501832063807456),  INT64_C( 2543503936065542489), -INT64_C( 8190442874998581188), -INT64_C(  377156567759707809) },
      UINT8_C(  2),
      { -INT64_C( 5062392192481466903),  INT64_C( 3771544356537978819),  INT64_C( 7556578682619163083),  INT64_C( 2047865916313661270),
         INT64_C( 7041729440216373728), -INT64_C( 3575908668052616049), -INT64_C( 2345764592618230589),  INT64_C( 5758612366313452442) },
       INT32_C(         140),
      {  INT64_C( 5717175188174923778),  INT64_C( 8320894684666540869), -INT64_C( 4963246763511388727),  INT64_C( 3681965586537819381),
         INT64_C( 6321501832063807456),  INT64_C( 2543503936065542489), -INT64_C( 8190442874998581188), -INT64_C(  377156567759707809) } },
    { { -INT64_C( 2853867275989350229),  INT64_C( 8765963038980818137),  INT64_C( 8900977690053974047), -INT64_C( 8716406067849170861),
         INT64_C( 8345212556541006882), -INT64_C( 8479233099072243734), -INT64_C( 7037216040081445937),  INT64_C( 6745695400914395194) },
      UINT8_C( 26),
      { -INT64_C( 7246810613082139554),  INT64_C( 5169728425967372344),  INT64_C( 1141435935772350931), -INT64_C( 1706680046731989585),
         INT64_C( 7402750299865875963),  INT64_C( 2739898669403062818),  INT64_C( 8766989819617450412), -INT64_C( 7495679063299722105) },
       INT32_C(           4),
      { -INT64_C( 2853867275989350229),  INT64_C( 8928678520639751044),  INT64_C( 8900977690053974047), -INT64_C( 8860136674002281730),
         INT64_C( 7763540355596705718), -INT64_C( 8479233099072243734), -INT64_C( 7037216040081445937),  INT64_C( 6745695400914395194) } },
    { { -INT64_C( 8709701969614769601), -INT64_C( 8555026473622362369), -INT64_C( 9105518797539512054),  INT64_C( 4604595270978149297),
         INT64_C( 7709529700617453121),  INT64_C( 2607403978779372262), -INT64_C( 7659681903612186035), -INT64_C( 2580227669458498574) },
      UINT8_C(174),
      { -INT64_C(  470481783283428655),  INT64_C( 9169671124249943704), -INT64_C(  921557701209393940),  INT64_C( 2963765858386388802),
         INT64_C( 6125797904687512251),  INT64_C( 4115880274964387410), -INT64_C( 4964460505310920193), -INT64_C( 3721576306338584616) },
       INT32_C(         136),
      { -INT64_C( 8709701969614769601),  INT64_C( 4699310446872533119),  INT64_C( 3888901448619322611),  INT64_C( 2407552724823917097),
         INT64_C( 7709529700617453121),  INT64_C( 2200938189438734905), -INT64_C( 7659681903612186035),  INT64_C( 6507157410219022540) } },
    { {  INT64_C( 4484149204861311561),  INT64_C( 5951494647325415536),  INT64_C( 7615370746164785574),  INT64_C( 7518492525724043657),
         INT64_C( 5194689791958184679),  INT64_C( 3009054926987366294), -INT64_C( 7727518304370634752), -INT64_C( 1376133336561944480) },
      UINT8_C(240),
      {  INT64_C( 7763661345396409834), -INT64_C( 4533127076157444408),  INT64_C( 2987962641752551360), -INT64_C( 4110348453111991033),
        -INT64_C( 7698995038328537632), -INT64_C( 1329191713529653797), -INT64_C( 4571580535557301965), -INT64_C( 5254649806814069647) },
       INT32_C(         120),
      {  INT64_C( 4484149204861311561),  INT64_C( 5951494647325415536),  INT64_C( 7615370746164785574),  INT64_C( 7518492525724043657),
        -INT64_C( 2263859614544236867), -INT64_C( 2599265540496380907),  INT64_C( 3729137153505231961),  INT64_C( 8194039744515917244) } },
    { {  INT64_C( 5039376786280091641),  INT64_C( 8851607641537599835),  INT64_C(  689019942657147410),  INT64_C( 1141240387957120608),
         INT64_C( 4346468283404413583), -INT64_C( 7433860210490848230),  INT64_C( 6261945176048341729),  INT64_C( 8748318049480567363) },
      UINT8_C(174),
      {  INT64_C( 2384316073153299514),  INT64_C( 6418544564174877074),  INT64_C( 4737405103434035606), -INT64_C( 5114782409972574446),
        -INT64_C( 1215747195312696791), -INT64_C( 6999379935171065795), -INT64_C( 2143757605005612250),  INT64_C( 4046268827170269934) },
       INT32_C(          14),
      {  INT64_C( 5039376786280091641), -INT64_C( 3453824776967776700), -INT64_C( 6253847506553827217),  INT64_C( 2963321871833280065),
         INT64_C( 4346468283404413583),  INT64_C( 5567048409540421559),  INT64_C( 6261945176048341729), -INT64_C( 3529736554425905655) } },
    { {  INT64_C( 2840148618417755816),  INT64_C( 4797986661298685809),  INT64_C( 5553602714629625014), -INT64_C( 4714499055491401320),
         INT64_C( 6582027254419991826), -INT64_C( 5545469371868832427),  INT64_C( 2659492727784746844),  INT64_C( 4357264704541519268) },
      UINT8_C(203),
      { -INT64_C( 2125399110114251491), -INT64_C( 9014075241632151293), -INT64_C( 2884500129072643350),  INT64_C( 5234657400438502077),
         INT64_C( 7949403559554144938), -INT64_C( 6047241648839446467),  INT64_C( 1199639014081110371), -INT64_C( 8277738281829161300) },
       INT32_C(          43),
      { -INT64_C( 6095359226324571811), -INT64_C(  412048479778333602),  INT64_C( 5553602714629625014),  INT64_C(  978946076799753936),
         INT64_C( 6582027254419991826), -INT64_C( 5545469371868832427),  INT64_C(  651641531396693608),  INT64_C( 6716384821369052863) } },
    { {  INT64_C( 4635820843124149639), -INT64_C( 2390867650618234464), -INT64_C(   41982529742407961), -INT64_C( 6653074369234040470),
        -INT64_C( 3561013398677786667),  INT64_C( 6237101134546305318), -INT64_C( 4597238065383441128),  INT64_C( 2134073213814423518) },
      UINT8_C( 48),
      { -INT64_C( 8798014948109291516), -INT64_C( 6649482220531312387), -INT64_C( 2276646437695853259),  INT64_C(  270291837773111760),
         INT64_C( 5206069131207777973), -INT64_C( 5544317626426576060), -INT64_C( 7886184741425313651), -INT64_C( 5834444129284410106) },
       INT32_C(           2),
      {  INT64_C( 4635820843124149639), -INT64_C( 2390867650618234464), -INT64_C(   41982529742407961), -INT64_C( 6653074369234040470),
         INT64_C( 2377532451121560277), -INT64_C( 3730526431996752622), -INT64_C( 4597238065383441128),  INT64_C( 2134073213814423518) } },
    { {  INT64_C( 6423959201694132088), -INT64_C(   47206171675904995), -INT64_C( 7567819112608307474),  INT64_C( 4964846733495697560),
         INT64_C( 1479757895183661909), -INT64_C( 3488293132972353957),  INT64_C( 8444456961289955582),  INT64_C( 8633107064393004477) },
      UINT8_C(112),
      { -INT64_C( 4084346833035810866), -INT64_C( 6318137409180997317), -INT64_C( 8019510038416200902), -INT64_C( 2706898620003500791),
        -INT64_C( 8085614635793786927),  INT64_C( 2536146618296726025), -INT64_C( 4915170253440633058),  INT64_C( 8642736052751727628) },
       INT32_C(           1),
      {  INT64_C( 6423959201694132088), -INT64_C(   47206171675904995), -INT64_C( 7567819112608307474),  INT64_C( 4964846733495697560),
         INT64_C( 2275514802121977763),  INT64_C( 5072293236593452050),  INT64_C( 8616403566828285501),  INT64_C( 8633107064393004477) } },
    { { -INT64_C( 6956715935924927263),  INT64_C( 1176527323902682875),  INT64_C( 4525984141007330475),  INT64_C( 7135725468182298800),
        -INT64_C( 5851932166026498956),  INT64_C( 1501699137593707369), -INT64_C( 2878193611750792649),  INT64_C( 7511883184335406171) },
      UINT8_C(125),
      { -INT64_C( 1749121396976348531), -INT64_C(  434206660491247449), -INT64_C( 7195350495636829905), -INT64_C( 3561510301661593212),
         INT64_C( 5318425304633361292), -INT64_C( 5717596246906298793),  INT64_C( 5206898686637558222),  INT64_C( 6462367282346513311) },
       INT32_C(          51),
      { -INT64_C( 7750908474500152956),  INT64_C( 1176527323902682875),  INT64_C( 5295354823104153878),  INT64_C(  875515372848065672),
         INT64_C( 2045283452665149686), -INT64_C(  955461069763153832),  INT64_C( 5652653140099806166),  INT64_C( 7511883184335406171) } },
    { { -INT64_C( 5861248900079415389), -INT64_C( 2512206938635284562),  INT64_C(  429956566366905463),  INT64_C( 1476510461676397940),
         INT64_C( 8325386347054242733),  INT64_C( 4105895006423738373),  INT64_C( 1779562475860992373),  INT64_C( 6661032409745592555) },
      UINT8_C(216),
      { -INT64_C( 6324724308985956482),  INT64_C( 8468633531741460735), -INT64_C(  710668351846140943),  INT64_C( 7928308899623829362),
        -INT64_C( 5358758307947109063), -INT64_C( 7134181559585404363), -INT64_C( 4874030272790390657),  INT64_C( 4383675908740546934) },
       INT32_C(          23),
      { -INT64_C( 5861248900079415389), -INT64_C( 2512206938635284562),  INT64_C(  429956566366905463),  INT64_C( 8653616929903674241),
        -INT64_C( 2667026176805252882),  INT64_C( 4105895006423738373), -INT64_C( 6542909970283876869),  INT64_C(  122570810624731897) } },
    { { -INT64_C( 8424889235701311915),  INT64_C( 8428482487418098195),  INT64_C( 6255529927478629107),  INT64_C( 8282901594833593614),
        -INT64_C( 3528270431314447203),  INT64_C( 2360546106290549027),  INT64_C( 2041354452040544938),  INT64_C( 5516263778481727486) },
      UINT8_C(168),
      {  INT64_C(  269428532338542986), -INT64_C( 4641152045620917356), -INT64_C( 3444433577179245094),  INT64_C( 7280011465728150955),
         INT64_C( 3777039729845824660), -INT64_C( 4227551927746913336), -INT64_C( 5330525781779471796), -INT64_C( 1893731412480785032) },
       INT32_C(           9),
      { -INT64_C( 8424889235701311915),  INT64_C( 8428482487418098195),  INT64_C( 6255529927478629107),  INT64_C( 1123567563483862730),
        -INT64_C( 3528270431314447203), -INT64_C( 6237530382402088566),  INT64_C( 2041354452040544938),  INT64_C( 8086952716444299723) } },
  };

  simde__m512i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_mm512_loadu_epi64(test_vec[0].src);
  a = simde_mm512_loadu_epi64(test_vec[0].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[0].k, a, INT32_C(         114));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[0].r));

  src = simde_mm512_loadu_epi64(test_vec[1].src);
  a = simde_mm512_loadu_epi64(test_vec[1].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[1].k, a, INT32_C(         215));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[1].r));

  src = simde_mm512_loadu_epi64(test_vec[2].src);
  a = simde_mm512_loadu_epi64(test_vec[2].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[2].k, a, INT32_C(         252));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[2].r));

  src = simde_mm512_loadu_epi64(test_vec[3].src);
  a = simde_mm512_loadu_epi64(test_vec[3].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[3].k, a, INT32_C(         119));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[3].r));

  src = simde_mm512_loadu_epi64(test_vec[4].src);
  a = simde_mm512_loadu_epi64(test_vec[4].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[4].k, a, INT32_C(         140));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[4].r));
  #endif

  src = simde_mm512_loadu_epi64(test_vec[5].src);
  a = simde_mm512_loadu_epi64(test_vec[5].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[5].k, a, INT32_C(           4));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[5].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_mm512_loadu_epi64(test_vec[6].src);
  a = simde_mm512_loadu_epi64(test_vec[6].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[6].k, a, INT32_C(         136));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[6].r));

  src = simde_mm512_loadu_epi64(test_vec[7].src);
  a = simde_mm512_loadu_epi64(test_vec[7].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[7].k, a, INT32_C(         120));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[7].r));
  #endif

  src = simde_mm512_loadu_epi64(test_vec[8].src);
  a = simde_mm512_loadu_epi64(test_vec[8].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[8].k, a, INT32_C(         14));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[8].r));

  src = simde_mm512_loadu_epi64(test_vec[9].src);
  a = simde_mm512_loadu_epi64(test_vec[9].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[9].k, a, INT32_C(          43));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[9].r));

  src = simde_mm512_loadu_epi64(test_vec[10].src);
  a = simde_mm512_loadu_epi64(test_vec[10].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[10].k, a, INT32_C(           2));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[10].r));

  src = simde_mm512_loadu_epi64(test_vec[11].src);
  a = simde_mm512_loadu_epi64(test_vec[11].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[11].k, a, INT32_C(           1));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[11].r));

  src = simde_mm512_loadu_epi64(test_vec[12].src);
  a = simde_mm512_loadu_epi64(test_vec[12].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[12].k, a, INT32_C(          51));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[12].r));

  src = simde_mm512_loadu_epi64(test_vec[13].src);
  a = simde_mm512_loadu_epi64(test_vec[13].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[13].k, a, INT32_C(         23));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[13].r));

  src = simde_mm512_loadu_epi64(test_vec[14].src);
  a = simde_mm512_loadu_epi64(test_vec[14].a);
  r = simde_mm512_mask_rol_epi64(src, test_vec[14].k, a, INT32_C(           9));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[14].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    int imm8 = simde_test_codegen_random_i32() & 63;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_rol_epi64, r, simde_mm512_setzero_si512(), imm8, src, k, a);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_rol_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int32_t imm8;
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(173),
      {  INT64_C( 5466618468751694746),  INT64_C( 5473249926341118945),  INT64_C( 3820470279251735665), -INT64_C( 3833984744770651108),
        -INT64_C( 8529157268535880753),  INT64_C( 8448109707897544995),  INT64_C( 2169511276410239340), -INT64_C( 8404272447616202652) },
       INT32_C(          89),
      {  INT64_C( 1252301649944754857),  INT64_C(                   0), -INT64_C(  838943414192305646),  INT64_C( 6934236623187318246),
         INT64_C(                   0),  INT64_C(  713123735223827310),  INT64_C(                   0),  INT64_C( 8730359341390412813) } },
    { UINT8_C( 49),
      {  INT64_C(  335876946516019588),  INT64_C( 7530113965996646020), -INT64_C( 2236493674537247119), -INT64_C( 1744800280710905409),
        -INT64_C( 1795750552306639421),  INT64_C( 5584153317122344277),  INT64_C( 7655413116561738627),  INT64_C( 8307113471087113982) },
       INT32_C(         232),
      {  INT64_C( 6091545126549999013),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
        -INT64_C( 8278245142793133296),  INT64_C( 7315346961063074582),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 12),
      {  INT64_C( 9077136544160101271),  INT64_C( 5326736690612618741),  INT64_C( 2648864631359493788),  INT64_C( 5823815918275081712),
        -INT64_C( 6943876993516817524), -INT64_C( 7007939659202255959), -INT64_C( 7016481030501563102), -INT64_C( 7876454872262595160) },
       INT32_C(         105),
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 8165808660932414940),  INT64_C( 1903862252351746444),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(130),
      {  INT64_C( 6845367611311239770), -INT64_C( 4534284461168026273),  INT64_C( 5354720670446629020), -INT64_C(  928930535110876549),
         INT64_C( 5146190399352686201), -INT64_C( 8890740186310448242),  INT64_C( 5534393777781540463), -INT64_C( 4500221615847144961) },
       INT32_C(          71),
      {  INT64_C(                   0), -INT64_C( 8539344744511262752),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 4179300543438454816) } },
    { UINT8_C(109),
      { -INT64_C( 2303073197119277770),  INT64_C( 8596477074801134964),  INT64_C( 9109110230728743072),  INT64_C( 3352354839756876699),
        -INT64_C( 3644722336108674711),  INT64_C( 3294264982539647717), -INT64_C( 2870559612970521044),  INT64_C( 5479040038885977828) },
       INT32_C(         246),
      {  INT64_C( 5600228841529835229),  INT64_C(                   0),  INT64_C( 2891199376976813478), -INT64_C( 1816180465434480310),
         INT64_C(                   0), -INT64_C( 5094857722536390098), -INT64_C( 8415527384800128053),  INT64_C(                   0) } },
    { UINT8_C(177),
      { -INT64_C(  537943326736311230), -INT64_C( 4757543912096877170),  INT64_C( 4019882414156403192),  INT64_C( 3355600554166130054),
        -INT64_C( 8217746607527286632), -INT64_C( 2293946394663577240), -INT64_C( 3527005390157460715),  INT64_C( 5818157826248162212) },
       INT32_C(         103),
      {  INT64_C( 5444325817145078398),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 1518922842062290942),  INT64_C( 2669707072607745078),  INT64_C(                   0),  INT64_C( 6277404526460787656) } },
    { UINT8_C(155),
      { -INT64_C( 9132614780765080511),  INT64_C( 8695727300426474137),  INT64_C( 7668976143715564666),  INT64_C( 5399596090969472363),
        -INT64_C(  293606569610513876),  INT64_C( 7667675164772958728), -INT64_C( 7052764342023912054),  INT64_C( 6241392230518681929) },
       INT32_C(         211),
      {  INT64_C( 8787314657234520595),  INT64_C( 8017300900719347051),  INT64_C(                   0), -INT64_C( 4590673707321895047),
         INT64_C( 3678127149109731175),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(  671774767640655087) } },
    { UINT8_C( 40),
      { -INT64_C( 7124938087109414995),  INT64_C( 3838153921833437579), -INT64_C( 5469672514265357829), -INT64_C( 2604845100235788945),
        -INT64_C( 5253684069789922581),  INT64_C( 1625811673317654195),  INT64_C( 5724949103897677804), -INT64_C( 6876474682040583545) },
       INT32_C(         228),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1762832689458295531),
         INT64_C(                   0), -INT64_C( 4862784575182425691),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(228),
      { -INT64_C( 7892356482648893564),  INT64_C( 5899253657785541596), -INT64_C(  460271700206115533), -INT64_C( 4612092583882982590),
        -INT64_C( 8588529775877687899), -INT64_C( 7291434009127482484), -INT64_C( 1760063421952042171),  INT64_C( 3888013373157212922) },
       INT32_C(          52),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 5998682332636942538),  INT64_C(                   0),
         INT64_C(                   0), -INT64_C( 5131380110831129584), -INT64_C( 5449785252102175171),  INT64_C( 3432692138071248912) } },
    { UINT8_C( 78),
      { -INT64_C( 8452313212780926654), -INT64_C( 5717205721254245080), -INT64_C( 8030797122189488135),  INT64_C( 8505088804686971604),
         INT64_C( 7260778124802253647), -INT64_C(  926314380945485116), -INT64_C( 8880679898298986592), -INT64_C( 4978370485789244098) },
       INT32_C(          41),
      {  INT64_C(                   0), -INT64_C( 7018207590894051319),  INT64_C( 6133888540993462777),  INT64_C(  686140250082929013),
         INT64_C(                   0),  INT64_C(                   0), -INT64_C( 2333074572846735773),  INT64_C(                   0) } },
    { UINT8_C( 35),
      {  INT64_C( 4846820094550526647), -INT64_C( 6773109110261663870),  INT64_C(  686328090672006614), -INT64_C( 1509664422074564548),
        -INT64_C( 3181660844946295710), -INT64_C( 6379307289015960401), -INT64_C( 1767863328089876310), -INT64_C( 6509429607160042870) },
       INT32_C(          16),
      {  INT64_C( 6715511258545079107),  INT64_C( 1523995564537192961),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 2725193603297027960),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 85),
      {  INT64_C( 4512846626712515602),  INT64_C( 6077139355295041618), -INT64_C( 1605080210521309747), -INT64_C( 6090878149049360827),
        -INT64_C( 6258567142313394738),  INT64_C( 3513556903803424098), -INT64_C( 9016662485223628569),  INT64_C( 4612563919819872191) },
       INT32_C(          27),
      { -INT64_C( 4145519886397536560),  INT64_C(                   0),  INT64_C( 7763908814005193952),  INT64_C(                   0),
        -INT64_C( 4666903567715981102),  INT64_C(                   0), -INT64_C( 1178468626205314295),  INT64_C(                   0) } },
    { UINT8_C(151),
      { -INT64_C( 7440676735919940788), -INT64_C(  718478528357601751),  INT64_C( 5574064562748426577),  INT64_C( 1091519018158299921),
        -INT64_C( 5693913841437958283),  INT64_C( 4585088757702228501),  INT64_C( 8540939689122092811), -INT64_C( 4687920339814682849) },
       INT32_C(           9),
      {  INT64_C( 8849534466867501361),  INT64_C( 1073874955098936300), -INT64_C( 5324275297786092902),  INT64_C(                   0),
        -INT64_C(  698323170125485215),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 2138484402875908227) } },
    { UINT8_C(130),
      {  INT64_C( 8972650381441466397),  INT64_C( 8187194397222749666),  INT64_C( 4755926656987698248), -INT64_C(  198057362776670621),
        -INT64_C(  336896848846071845), -INT64_C( 2000209989088191777), -INT64_C( 6682607102657245720),  INT64_C(  304171268526165339) },
       INT32_C(          57),
      {  INT64_C(                   0), -INT64_C( 4259493186047373429),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 5329885620771306598) } },
    { UINT8_C(230),
      { -INT64_C( 7591781705476370899), -INT64_C( 4477564134275249969), -INT64_C( 8955592707722674239), -INT64_C( 4376778011899544689),
         INT64_C( 7599384127926372125),  INT64_C( 3881507442177537528), -INT64_C( 2322031873686701726),  INT64_C( 7967287006084186679) },
       INT32_C(           4),
      {  INT64_C(                   0),  INT64_C( 2145950146434206972),  INT64_C( 4284469266113625112),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 6763886853711945603), -INT64_C(  259021831568124371), -INT64_C( 1650616418619874442) } },
    { UINT8_C(204),
      {  INT64_C( 8011587686467143621), -INT64_C( 6627024686560484418), -INT64_C( 6922409611079456806),  INT64_C( 8098108384691379514),
        -INT64_C( 4195850689292130615), -INT64_C( 8752600001986914372),  INT64_C( 5056998177205609324),  INT64_C( 6740269697651790446) },
       INT32_C(          38),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 8573154567018662055), -INT64_C( 8568293333715080475),
         INT64_C(                   0),  INT64_C(                   0), -INT64_C( 8585871821180222685), -INT64_C( 5236389392229079802) } },
  };

  simde__m512i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi64(test_vec[0].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[0].k, a, INT32_C(          89));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[0].r));

  a = simde_mm512_loadu_epi64(test_vec[1].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[1].k, a, INT32_C(         232));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[1].r));

  a = simde_mm512_loadu_epi64(test_vec[2].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[2].k, a, INT32_C(         105));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[2].r));

  a = simde_mm512_loadu_epi64(test_vec[3].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[3].k, a, INT32_C(          71));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[3].r));

  a = simde_mm512_loadu_epi64(test_vec[4].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[4].k, a, INT32_C(         246));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[4].r));

  a = simde_mm512_loadu_epi64(test_vec[5].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[5].k, a, INT32_C(         103));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[5].r));

  a = simde_mm512_loadu_epi64(test_vec[6].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[6].k, a, INT32_C(         211));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[6].r));

  a = simde_mm512_loadu_epi64(test_vec[7].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[7].k, a, INT32_C(         228));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[7].r));
  #endif

  a = simde_mm512_loadu_epi64(test_vec[8].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[8].k, a, INT32_C(          52));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[8].r));

  a = simde_mm512_loadu_epi64(test_vec[9].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[9].k, a, INT32_C(          41));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[9].r));

  a = simde_mm512_loadu_epi64(test_vec[10].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[10].k, a, INT32_C(          16));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[10].r));

  a = simde_mm512_loadu_epi64(test_vec[11].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[11].k, a, INT32_C(          27));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[11].r));

  a = simde_mm512_loadu_epi64(test_vec[12].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[12].k, a, INT32_C(           9));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[12].r));

  a = simde_mm512_loadu_epi64(test_vec[13].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[13].k, a, INT32_C(          57));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[13].r));

  a = simde_mm512_loadu_epi64(test_vec[14].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[14].k, a, INT32_C(           4));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[14].r));

  a = simde_mm512_loadu_epi64(test_vec[15].a);
  r = simde_mm512_maskz_rol_epi64(test_vec[15].k, a, INT32_C(          38));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[15].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    int imm8 = simde_test_codegen_random_i32() & 63;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_rol_epi64, r, simde_mm512_setzero_si512(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rol_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_rol_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_rol_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_rol_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_rol_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_rol_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_rol_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_rol_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_rol_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_rol_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_rol_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_rol_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_rol_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_rol_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_rol_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_rol_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_rol_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_rol_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
