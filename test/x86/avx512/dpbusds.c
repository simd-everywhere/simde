#define SIMDE_TEST_X86_AVX512_INSN dpbusds

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/dpbusds.h>

static int
test_simde_mm_dpbusds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  2044021954), -INT32_C(  1109770795), -INT32_C(  1350023434),  INT32_C(   627903573) },
      { -INT32_C(   485870640), -INT32_C(  1717282268), -INT32_C(  1683552729),  INT32_C(  1902247219) },
      { -INT32_C(  2030597200), -INT32_C(  1102851384),  INT32_C(  1835911960), -INT32_C(  1466770728) },
      { -INT32_C(  2044072345), -INT32_C(  1109776061), -INT32_C(  1349987718),  INT32_C(   627871305) } },
    { {  INT32_C(   848010253),  INT32_C(   499855350),  INT32_C(  1756984117),  INT32_C(   551098992) },
      {  INT32_C(  1839648933), -INT32_C(  1171527006), -INT32_C(  1926719307), -INT32_C(  2143962509) },
      {  INT32_C(  1303560279),  INT32_C(   611024623),  INT32_C(  1636574449), -INT32_C(   478059202) },
      {  INT32_C(   848006741),  INT32_C(   499893377),  INT32_C(  1756995911),  INT32_C(   551114465) } },
    { { -INT32_C(   665835466), -INT32_C(   946636014), -INT32_C(  2041201901), -INT32_C(   871921035) },
      {  INT32_C(   974829899),  INT32_C(   677348663), -INT32_C(   410391639), -INT32_C(  2016801967) },
      {  INT32_C(  1163860531), -INT32_C(  1475546475),  INT32_C(   590307757),  INT32_C(   938424044) },
      { -INT32_C(   665820359), -INT32_C(   946646141), -INT32_C(  2041178609), -INT32_C(   871918070) } },
    { {  INT32_C(   661719535),  INT32_C(   927977614),  INT32_C(   220125628),  INT32_C(   395634916) },
      { -INT32_C(  1755516158), -INT32_C(  1824495386), -INT32_C(  1229557814), -INT32_C(  1796364635) },
      {  INT32_C(  1052466863), -INT32_C(   344650961), -INT32_C(   923233052),  INT32_C(  2145356924) },
      {  INT32_C(   661745229),  INT32_C(   927993969),  INT32_C(   220096336),  INT32_C(   395647095) } },
    { {  INT32_C(  1695955839),  INT32_C(  1845057187),  INT32_C(  1780723653),  INT32_C(   100601941) },
      { -INT32_C(  1639728529), -INT32_C(  1450592059), -INT32_C(   915308212), -INT32_C(  1941417971) },
      {  INT32_C(   804413067),  INT32_C(  2057104309), -INT32_C(   253378406),  INT32_C(  1073079504) },
      {  INT32_C(  1695966824),  INT32_C(  1845045466),  INT32_C(  1780701378),  INT32_C(   100607105) } },
    { {  INT32_C(  1692219550),  INT32_C(  1024288496), -INT32_C(   200900633),  INT32_C(  1535200975) },
      {  INT32_C(  1636463532), -INT32_C(   119789986), -INT32_C(  1209482778),  INT32_C(  1140252069) },
      {  INT32_C(   111662101),  INT32_C(   574862650),  INT32_C(    51792180),  INT32_C(  1130272663) },
      {  INT32_C(  1692206402),  INT32_C(  1024314270), -INT32_C(   200868931),  INT32_C(  1535188058) } },
    { {  INT32_C(  1755703306), -INT32_C(   178159345), -INT32_C(   408139454),  INT32_C(  1009427239) },
      { -INT32_C(  1321020809), -INT32_C(  1143765625),  INT32_C(  1707010766), -INT32_C(  1935073919) },
      {  INT32_C(   351555077),  INT32_C(   285889999), -INT32_C(   956778849), -INT32_C(   805166503) },
      {  INT32_C(  1755723029), -INT32_C(   178149366), -INT32_C(   408184130),  INT32_C(  1009433324) } },
    { {  INT32_C(  2072135156), -INT32_C(  1724492342), -INT32_C(  1040255681),  INT32_C(   390965010) },
      { -INT32_C(  1003732491),  INT32_C(   919942807),  INT32_C(  1190972908), -INT32_C(   468254992) },
      {  INT32_C(   241211459),  INT32_C(   765957870), -INT32_C(  1645304437),  INT32_C(  1119173453) },
      {  INT32_C(  2072151779), -INT32_C(  1724517311), -INT32_C(  1040313414),  INT32_C(   391011874) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_dpbusds_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_dpbusds_epi32(src, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_dpbusds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   769839214),  INT32_C(   873508975),  INT32_C(   441899856),  INT32_C(   317863913) },
      UINT8_C(137),
      { -INT32_C(  2026095258), -INT32_C(  1012064778),  INT32_C(   411211231),  INT32_C(  1384575362) },
      { -INT32_C(  2067680044), -INT32_C(  1613433148), -INT32_C(  2088178100),  INT32_C(  1192073953) },
      {  INT32_C(   769809570),  INT32_C(   873508975),  INT32_C(   441899856),  INT32_C(   317842865) } },
    { { -INT32_C(   825341480),  INT32_C(  1183939431), -INT32_C(  1839328496), -INT32_C(   639310587) },
      UINT8_C(153),
      { -INT32_C(  1688379995),  INT32_C(   535297329),  INT32_C(   536898437), -INT32_C(  1040693384) },
      { -INT32_C(  1876376043),  INT32_C(  1805676119), -INT32_C(  1301269811), -INT32_C(  1135916778) },
      { -INT32_C(   825357049),  INT32_C(  1183939431), -INT32_C(  1839328496), -INT32_C(   639297288) } },
    { { -INT32_C(   682121050),  INT32_C(   737558437),  INT32_C(   575403946),  INT32_C(  1424180030) },
      UINT8_C(  9),
      {  INT32_C(  2053170188), -INT32_C(  1220031611), -INT32_C(  2066810565), -INT32_C(   315979196) },
      {  INT32_C(   546439649), -INT32_C(   271925768),  INT32_C(  1261300744), -INT32_C(   598441520) },
      { -INT32_C(   682127850),  INT32_C(   737558437),  INT32_C(   575403946),  INT32_C(  1424154236) } },
    { { -INT32_C(   346639002), -INT32_C(  1130193280), -INT32_C(   599756649), -INT32_C(   590779398) },
      UINT8_C(108),
      {  INT32_C(   426048603), -INT32_C(  1289661497),  INT32_C(    42167681),  INT32_C(  1986551745) },
      {  INT32_C(  1425494966),  INT32_C(  1726723062),  INT32_C(  1583466483), -INT32_C(   322224752) },
      { -INT32_C(   346639002), -INT32_C(  1130193280), -INT32_C(   599751644), -INT32_C(   590803091) } },
    { {  INT32_C(      339769),  INT32_C(    78915203),  INT32_C(  1426470803),  INT32_C(  1305178007) },
      UINT8_C(194),
      {  INT32_C(  1975034306),  INT32_C(  1416175500), -INT32_C(  1109080192), -INT32_C(  1024012142) },
      { -INT32_C(    62523435), -INT32_C(   493925973), -INT32_C(  1099307953),  INT32_C(  1921107632) },
      {  INT32_C(      339769),  INT32_C(    78891181),  INT32_C(  1426470803),  INT32_C(  1305178007) } },
    { { -INT32_C(   186107545), -INT32_C(   666349224), -INT32_C(  1416287208), -INT32_C(   764572419) },
      UINT8_C(131),
      { -INT32_C(    80818510),  INT32_C(  1112150110),  INT32_C(  1358039434), -INT32_C(  1011325558) },
      { -INT32_C(  1642288051),  INT32_C(   548861172),  INT32_C(   371024266), -INT32_C(  2137394994) },
      { -INT32_C(   186134453), -INT32_C(   666353908), -INT32_C(  1416287208), -INT32_C(   764572419) } },
    { {  INT32_C(   477874110),  INT32_C(  1633666775),  INT32_C(  1504858575),  INT32_C(    52193974) },
      UINT8_C( 22),
      {  INT32_C(   755671352), -INT32_C(  1179178408),  INT32_C(   948489544),  INT32_C(   771098726) },
      {  INT32_C(  1241781124), -INT32_C(  1021745550), -INT32_C(  2105904616), -INT32_C(   946307698) },
      {  INT32_C(   477874110),  INT32_C(  1633674381),  INT32_C(  1504893209),  INT32_C(    52193974) } },
    { {  INT32_C(  2012520991),  INT32_C(   338734028), -INT32_C(   565397384),  INT32_C(  1158366145) },
      UINT8_C( 86),
      {  INT32_C(  1976078095),  INT32_C(   445483944), -INT32_C(  2086138107),  INT32_C(  1235382183) },
      {  INT32_C(   236329315),  INT32_C(    42347081), -INT32_C(  1161599881),  INT32_C(  2131757167) },
      {  INT32_C(  2012520991),  INT32_C(   338734980), -INT32_C(   565414707),  INT32_C(  1158366145) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_mask_dpbusds_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_mask_dpbusds_epi32(src, k, a, b);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_dpbusds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t src[4];
    const int32_t a[4];
    const int32_t b[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C(151),
      {  INT32_C(  1665135832), -INT32_C(  1855366782),  INT32_C(  1899621377), -INT32_C(  1479245170) },
      { -INT32_C(  1007623272), -INT32_C(   834997655), -INT32_C(  1120013131), -INT32_C(   598426620) },
      {  INT32_C(   859804593), -INT32_C(   289101588),  INT32_C(   576716180),  INT32_C(   415839104) },
      {  INT32_C(  1665124146), -INT32_C(  1855397366),  INT32_C(  1899613318),  INT32_C(           0) } },
    { UINT8_C( 22),
      { -INT32_C(  1400841286),  INT32_C(   157437461),  INT32_C(  1208819595),  INT32_C(   133818740) },
      { -INT32_C(   772527063), -INT32_C(   295247120),  INT32_C(  1953400897),  INT32_C(   210470482) },
      {  INT32_C(  2008550242), -INT32_C(   461301159), -INT32_C(  1372811718), -INT32_C(  1581963912) },
      {  INT32_C(           0),  INT32_C(   157445079),  INT32_C(  1208803189),  INT32_C(           0) } },
    { UINT8_C( 81),
      { -INT32_C(  1958579543),  INT32_C(  1640771800),  INT32_C(   615727518), -INT32_C(   679034932) },
      { -INT32_C(  1842282889),  INT32_C(   231478399),  INT32_C(  1720023617), -INT32_C(   642243025) },
      {  INT32_C(  1902443161), -INT32_C(   925748950),  INT32_C(  1055688050), -INT32_C(  1139444924) },
      { -INT32_C(  1958572026),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(113),
      {  INT32_C(  1508920901), -INT32_C(  1801781990), -INT32_C(  1446837885), -INT32_C(  1287480135) },
      {  INT32_C(   853390337),  INT32_C(   212116870),  INT32_C(    72409745),  INT32_C(  1014303991) },
      {  INT32_C(  1955947866), -INT32_C(   435670941), -INT32_C(   359674831),  INT32_C(  1771950696) },
      {  INT32_C(  1508921324),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(134),
      {  INT32_C(   520919930),  INT32_C(   565188671),  INT32_C(  1964553577), -INT32_C(  1865395158) },
      {  INT32_C(   452150506),  INT32_C(   424401229),  INT32_C(   981546344),  INT32_C(  1287711698) },
      { -INT32_C(   966013562),  INT32_C(  1323768805), -INT32_C(    71040816),  INT32_C(  1049334868) },
      {  INT32_C(           0),  INT32_C(   565192526),  INT32_C(  1964540555),  INT32_C(           0) } },
    { UINT8_C(216),
      {  INT32_C(  1462065278), -INT32_C(   658555229), -INT32_C(  1414858048), -INT32_C(  2026768710) },
      {  INT32_C(  2104358753), -INT32_C(   548553761),  INT32_C(   322127999),  INT32_C(  1374450387) },
      {  INT32_C(  1856508362),  INT32_C(   273049680),  INT32_C(   482079074),  INT32_C(  1235545319) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2026792064) } },
    { UINT8_C(228),
      { -INT32_C(   859585007),  INT32_C(  1548526099),  INT32_C(  1194287061),  INT32_C(  1561493835) },
      { -INT32_C(  1850900439), -INT32_C(  1208762938),  INT32_C(  1688146040), -INT32_C(   985077580) },
      { -INT32_C(  1047458898), -INT32_C(  2095194707), -INT32_C(  2000007875), -INT32_C(   135930674) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1194275027),  INT32_C(           0) } },
    { UINT8_C( 92),
      {  INT32_C(  1327729042), -INT32_C(  1933059460),  INT32_C(  1631595641), -INT32_C(  2146499212) },
      {  INT32_C(  1949159831),  INT32_C(  1001500910),  INT32_C(  1460222587), -INT32_C(  1296826081) },
      {  INT32_C(   100784010),  INT32_C(   731105713),  INT32_C(  1770836981),  INT32_C(  1894358233) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1631599769), -INT32_C(  2146484725) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_dpbusds_epi32(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_maskz_dpbusds_epi32(k, src, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_dpbusds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(  1438647573), -INT32_C(  1636576514),  INT32_C(  1683811069),  INT32_C(   658252268),  INT32_C(  2100392366), -INT32_C(   700551613),  INT32_C(  1901601422),  INT32_C(  1783711870) },
      {  INT32_C(  1075089730),  INT32_C(  1641973859),  INT32_C(  1589984114),  INT32_C(   193266012), -INT32_C(  1232554126), -INT32_C(  1282619867),  INT32_C(  1730471145),  INT32_C(  1875998252) },
      {  INT32_C(  1789912583), -INT32_C(   523530642),  INT32_C(   624923081),  INT32_C(    87082130), -INT32_C(  1581532805),  INT32_C(  1750353791),  INT32_C(  1490057515), -INT32_C(   154689041) },
      { -INT32_C(  1438645717), -INT32_C(  1636595998),  INT32_C(  1683814139),  INT32_C(   658248527),  INT32_C(  2100366721), -INT32_C(   700502480),  INT32_C(  1901646365),  INT32_C(  1783686889) } },
    { { -INT32_C(   178227577), -INT32_C(   841602044),  INT32_C(  1341330877),  INT32_C(  1431577561),  INT32_C(  1559629788), -INT32_C(  2101065130), -INT32_C(  1294297917), -INT32_C(  1113022154) },
      {  INT32_C(   481495319), -INT32_C(   219576011),  INT32_C(  2000805022), -INT32_C(   590572032), -INT32_C(    63389019), -INT32_C(   796984051), -INT32_C(   947693423),  INT32_C(   277163001) },
      {  INT32_C(  1764505652),  INT32_C(  1599805121), -INT32_C(   220815886), -INT32_C(   657480909),  INT32_C(  1926498149), -INT32_C(  1773972988), -INT32_C(  1554135382),  INT32_C(   649388785) },
      { -INT32_C(   178215061), -INT32_C(   841558176),  INT32_C(  1341302489),  INT32_C(  1431544815),  INT32_C(  1559674075), -INT32_C(  2101057938), -INT32_C(  1294321815), -INT32_C(  1113036679) } },
    { { -INT32_C(   611327974), -INT32_C(   382014474), -INT32_C(  1143271032),  INT32_C(   429107892), -INT32_C(  1232312142),  INT32_C(  1699532730), -INT32_C(  2046252395), -INT32_C(  1481851764) },
      { -INT32_C(  1820181347), -INT32_C(  1350779609), -INT32_C(  2106959666), -INT32_C(  1264845566),  INT32_C(   543893349), -INT32_C(  1954170890), -INT32_C(   300774047), -INT32_C(   409616822) },
      {  INT32_C(   561649658), -INT32_C(  1563363372),  INT32_C(  1361328719), -INT32_C(  1660501960), -INT32_C(   558009881), -INT32_C(  1972813272),  INT32_C(   444103632),  INT32_C(   872484154) },
      { -INT32_C(   611306825), -INT32_C(   382040293), -INT32_C(  1143235308),  INT32_C(   429074922), -INT32_C(  1232318517),  INT32_C(  1699552211), -INT32_C(  2046231360), -INT32_C(  1481832841) } },
    { { -INT32_C(   111772892), -INT32_C(  1046796686), -INT32_C(  1726758815),  INT32_C(  1731598720), -INT32_C(  1304038262),  INT32_C(   104640310),  INT32_C(  1679864874), -INT32_C(   426171967) },
      {  INT32_C(   266334109),  INT32_C(  1993439765), -INT32_C(  1173363654), -INT32_C(  2027796739),  INT32_C(  1882810170),  INT32_C(  1098348054), -INT32_C(   324692182),  INT32_C(  1456619193) },
      {  INT32_C(  1130737965),  INT32_C(  1723414059),  INT32_C(   388024602),  INT32_C(  1235108367), -INT32_C(  1061562198),  INT32_C(  2013343822), -INT32_C(  2124109880),  INT32_C(   332871397) },
      { -INT32_C(   111761180), -INT32_C(  1046791998), -INT32_C(  1726765089),  INT32_C(  1731613658), -INT32_C(  1304058585),  INT32_C(   104655609),  INT32_C(  1679835611), -INT32_C(   426180590) } },
    { {  INT32_C(   324418791), -INT32_C(  1921446029), -INT32_C(   408577576), -INT32_C(  2043657252),  INT32_C(  1766255131), -INT32_C(   488486886), -INT32_C(   731691281),  INT32_C(  1692875389) },
      { -INT32_C(   361284233),  INT32_C(   628617293),  INT32_C(  1712135306),  INT32_C(  2079079776),  INT32_C(  1122316839),  INT32_C(  1764018042), -INT32_C(  1975613427),  INT32_C(   971974082) },
      { -INT32_C(  1339857309), -INT32_C(   506094761),  INT32_C(   390587063),  INT32_C(  1200829216), -INT32_C(   527861659),  INT32_C(  1279897151), -INT32_C(   120092874),  INT32_C(   271763117) },
      {  INT32_C(   324422239), -INT32_C(  1921469834), -INT32_C(   408585221), -INT32_C(  2043668060),  INT32_C(  1766235707), -INT32_C(   488484910), -INT32_C(   731710681),  INT32_C(  1692870003) } },
    { { -INT32_C(  2084547284), -INT32_C(  1469803024), -INT32_C(  1732269192),  INT32_C(  1155486430),  INT32_C(   153381322),  INT32_C(  1297509655), -INT32_C(  1572524555),  INT32_C(   531789811) },
      { -INT32_C(  1113361715),  INT32_C(  2137327367), -INT32_C(  1860753997),  INT32_C(  1121318775),  INT32_C(  2001467744),  INT32_C(  1556390247), -INT32_C(  1040315954),  INT32_C(  1323413633) },
      {  INT32_C(   688620578),  INT32_C(  1051292043),  INT32_C(   231784598),  INT32_C(   391095735),  INT32_C(   110009247),  INT32_C(   190992956), -INT32_C(   573808548),  INT32_C(   841723152) },
      { -INT32_C(  2084544908), -INT32_C(  1469803965), -INT32_C(  1732289753),  INT32_C(  1155473611),  INT32_C(   153339025),  INT32_C(  1297549257), -INT32_C(  1572524702),  INT32_C(   531790842) } },
    { { -INT32_C(  1118095823),  INT32_C(  1039860903),  INT32_C(  2085342149),  INT32_C(   278174321),  INT32_C(  1914053173), -INT32_C(   780306315), -INT32_C(   391231016),  INT32_C(   672848375) },
      { -INT32_C(  1209699057),  INT32_C(  1073013114),  INT32_C(   498810796),  INT32_C(   254627802), -INT32_C(   410958990), -INT32_C(  1816592709),  INT32_C(  1065051720),  INT32_C(  1315411263) },
      { -INT32_C(  2063250165), -INT32_C(   624625106),  INT32_C(   335052601),  INT32_C(  1092822479),  INT32_C(   606643305), -INT32_C(   340205405), -INT32_C(  2060831930), -INT32_C(   724332087) },
      { -INT32_C(  1118108013),  INT32_C(  1039848131),  INT32_C(  2085359009),  INT32_C(   278169112),  INT32_C(  1914072455), -INT32_C(   780348169), -INT32_C(   391223357),  INT32_C(   672820304) } },
    { {  INT32_C(   207215070),  INT32_C(   216473043),  INT32_C(  1797316508),  INT32_C(  1840005892), -INT32_C(  1970088729), -INT32_C(    92976460),  INT32_C(  1182769021),  INT32_C(   253383473) },
      { -INT32_C(    14912724),  INT32_C(   755696528), -INT32_C(   426234910),  INT32_C(  1448363374), -INT32_C(   824121831), -INT32_C(  1379379664),  INT32_C(   653543669), -INT32_C(   952758629) },
      {  INT32_C(   314987138),  INT32_C(   926929237),  INT32_C(  1797118205),  INT32_C(   918647069), -INT32_C(  2029739433), -INT32_C(   315240968), -INT32_C(  1340856043), -INT32_C(  1183364553) },
      {  INT32_C(   207221922),  INT32_C(   216488310),  INT32_C(  1797343128),  INT32_C(  1840016231), -INT32_C(  1970132204), -INT32_C(    92973917),  INT32_C(  1182778958),  INT32_C(   253385331) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_dpbusds_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_dpbusds_epi32(src, a, b);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_dpbusds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(   238273124),  INT32_C(   187173646),  INT32_C(     7816675),  INT32_C(   238500023), -INT32_C(   761906214),  INT32_C(   499174152),  INT32_C(   734909684), -INT32_C(  1159379938) },
      UINT8_C(129),
      { -INT32_C(  1131369551),  INT32_C(   413178835),  INT32_C(  1271898130),  INT32_C(   321248983),  INT32_C(  1058797684), -INT32_C(  1942799944),  INT32_C(  1269456390), -INT32_C(   187931581) },
      { -INT32_C(   491693041),  INT32_C(   184177144), -INT32_C(   917124367),  INT32_C(   484211624),  INT32_C(   727447411),  INT32_C(   934776368),  INT32_C(   813851116), -INT32_C(   735818043) },
      { -INT32_C(   238271753),  INT32_C(   187173646),  INT32_C(     7816675),  INT32_C(   238500023), -INT32_C(   761906214),  INT32_C(   499174152),  INT32_C(   734909684), -INT32_C(  1159379483) } },
    { { -INT32_C(  1548298837),  INT32_C(   414036006),  INT32_C(   585171834), -INT32_C(   247546498), -INT32_C(   451110476),  INT32_C(   337433383), -INT32_C(   112943564), -INT32_C(  1748145940) },
      UINT8_C( 62),
      {  INT32_C(   862206595), -INT32_C(   340886296),  INT32_C(   443142237), -INT32_C(  1462806001),  INT32_C(  1238414454),  INT32_C(  1853744336), -INT32_C(  1873119704), -INT32_C(   959516093) },
      {  INT32_C(   351875884),  INT32_C(   234858415), -INT32_C(  2027460488),  INT32_C(   942667458),  INT32_C(  2055339946),  INT32_C(   199818979), -INT32_C(  1214495884),  INT32_C(  1635609141) },
      { -INT32_C(  1548298837),  INT32_C(   414009059),  INT32_C(   585205575), -INT32_C(   247529191), -INT32_C(   451138314),  INT32_C(   337425105), -INT32_C(   112943564), -INT32_C(  1748145940) } },
    { {  INT32_C(  1299609501), -INT32_C(  1772456674), -INT32_C(  1608678946),  INT32_C(   584666488),  INT32_C(   815618636), -INT32_C(   851737255), -INT32_C(    41560120), -INT32_C(   547421630) },
      UINT8_C(121),
      {  INT32_C(  1251486933),  INT32_C(   136851078), -INT32_C(  1719613108), -INT32_C(    52059486), -INT32_C(   984279745),  INT32_C(   680338257), -INT32_C(  1435858008), -INT32_C(  1088140566) },
      { -INT32_C(    49693578),  INT32_C(   906310378), -INT32_C(  1647344133),  INT32_C(  1738126631),  INT32_C(   455929802), -INT32_C(  1169901294),  INT32_C(   778350148),  INT32_C(  1877838072) },
      {  INT32_C(  1299632789), -INT32_C(  1772456674), -INT32_C(  1608678946),  INT32_C(   584663025),  INT32_C(   815623936), -INT32_C(   851731494), -INT32_C(    41541674), -INT32_C(   547421630) } },
    { {  INT32_C(   795670340),  INT32_C(   610627881),  INT32_C(   499201526), -INT32_C(  1266394390),  INT32_C(  1540403273), -INT32_C(  1374350230), -INT32_C(  1143113022),  INT32_C(  1193986562) },
      UINT8_C(193),
      {  INT32_C(   132806294),  INT32_C(   285019867),  INT32_C(   721033935),  INT32_C(  1332981663), -INT32_C(  1816539265),  INT32_C(  1582655716),  INT32_C(   258019397), -INT32_C(   791566278) },
      { -INT32_C(   103302370), -INT32_C(  1727343414), -INT32_C(  1899821841),  INT32_C(   853358515), -INT32_C(   356149498),  INT32_C(  1145641983),  INT32_C(  1716759083),  INT32_C(  1882596434) },
      {  INT32_C(   795657055),  INT32_C(   610627881),  INT32_C(   499201526), -INT32_C(  1266394390),  INT32_C(  1540403273), -INT32_C(  1374350230), -INT32_C(  1143101850),  INT32_C(  1194031948) } },
    { { -INT32_C(  1435955488), -INT32_C(   784108574),  INT32_C(   727648120),  INT32_C(  1147026750), -INT32_C(   751950892),  INT32_C(  1779922750),  INT32_C(  1943038497),  INT32_C(  1877149327) },
      UINT8_C( 20),
      { -INT32_C(  1057547955),  INT32_C(  1664665692),  INT32_C(  1705075752), -INT32_C(   449190462), -INT32_C(  1960571884), -INT32_C(  1918005725),  INT32_C(  1679564894),  INT32_C(  1366919940) },
      {  INT32_C(    17920164),  INT32_C(  1617185336),  INT32_C(  1891960494), -INT32_C(    11141397),  INT32_C(   764115210),  INT32_C(  1706768391),  INT32_C(  1556797272),  INT32_C(   128795491) },
      { -INT32_C(  1435955488), -INT32_C(   784108574),  INT32_C(   727647253),  INT32_C(  1147026750), -INT32_C(   751947197),  INT32_C(  1779922750),  INT32_C(  1943038497),  INT32_C(  1877149327) } },
    { { -INT32_C(   351748173), -INT32_C(  1219728119),  INT32_C(  1579618675),  INT32_C(   442399760), -INT32_C(    45553162),  INT32_C(  2036532001),  INT32_C(  1037446618),  INT32_C(   591758192) },
      UINT8_C( 66),
      { -INT32_C(  1169486259),  INT32_C(  1814889050), -INT32_C(  1501787095), -INT32_C(   744712470), -INT32_C(   504063522),  INT32_C(   700214780), -INT32_C(   946210493), -INT32_C(  1945519042) },
      {  INT32_C(   625366475), -INT32_C(  2121173929), -INT32_C(   366539520), -INT32_C(  2101492828),  INT32_C(  1499771228),  INT32_C(  1652695070),  INT32_C(  1479089177), -INT32_C(  1545325864) },
      { -INT32_C(   351748173), -INT32_C(  1219738768),  INT32_C(  1579618675),  INT32_C(   442399760), -INT32_C(    45553162),  INT32_C(  2036532001),  INT32_C(  1037479050),  INT32_C(   591758192) } },
    { { -INT32_C(   540464505), -INT32_C(  1637852514),  INT32_C(   210274152), -INT32_C(  1500625590),  INT32_C(   369095414),  INT32_C(   746029586),  INT32_C(  1988403358),  INT32_C(  1511680210) },
      UINT8_C(146),
      {  INT32_C(  1026636259),  INT32_C(   547737497), -INT32_C(  1653952168),  INT32_C(   848564288), -INT32_C(  1840928496), -INT32_C(  1070567136),  INT32_C(  1569892085), -INT32_C(  1544557376) },
      { -INT32_C(  1092542427),  INT32_C(  1222543088),  INT32_C(  2028292152),  INT32_C(  1772779865),  INT32_C(  1123807010),  INT32_C(  1426205536), -INT32_C(  1833789999), -INT32_C(  1489657215) },
      { -INT32_C(   540464505), -INT32_C(  1637883522),  INT32_C(   210274152), -INT32_C(  1500625590),  INT32_C(   369102376),  INT32_C(   746029586),  INT32_C(  1988403358),  INT32_C(  1511631802) } },
    { { -INT32_C(  1301997886), -INT32_C(   705018723), -INT32_C(   447881076),  INT32_C(  2085549913),  INT32_C(  1203653095),  INT32_C(  1184743796), -INT32_C(   673689770), -INT32_C(  1266807311) },
      UINT8_C( 36),
      {  INT32_C(   683763428),  INT32_C(  1102354017), -INT32_C(   627402013),  INT32_C(   851515112), -INT32_C(  1767503403), -INT32_C(   169022298), -INT32_C(   756563004),  INT32_C(   653695810) },
      {  INT32_C(  1649325825),  INT32_C(   815989325), -INT32_C(  2062926180),  INT32_C(   699911252),  INT32_C(  2076138965),  INT32_C(   242264906), -INT32_C(  1310697617), -INT32_C(   187181326) },
      { -INT32_C(  1301997886), -INT32_C(   705018723), -INT32_C(   447919502),  INT32_C(  2085549913),  INT32_C(  1203653095),  INT32_C(  1184765882), -INT32_C(   673689770), -INT32_C(  1266807311) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_dpbusds_epi32(src, k, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_mask_dpbusds_epi32(src, k, a, b);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_dpbusds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t src[8];
    const int32_t a[8];
    const int32_t b[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(141),
      {  INT32_C(   668620325),  INT32_C(   952371962), -INT32_C(   510899947),  INT32_C(  1572255232),  INT32_C(   564605301), -INT32_C(   107956575),  INT32_C(  1844134294),  INT32_C(  1039851288) },
      {  INT32_C(   811914550), -INT32_C(   194500385),  INT32_C(  1909847153),  INT32_C(   550472618),  INT32_C(  1581348540), -INT32_C(  1017654996),  INT32_C(   707805714),  INT32_C(  1483156002) },
      { -INT32_C(   544683009),  INT32_C(  1708388596), -INT32_C(  1881691676), -INT32_C(   240146892),  INT32_C(  1229975580), -INT32_C(   754145599),  INT32_C(   184368360),  INT32_C(  1717724262) },
      {  INT32_C(   668595398),  INT32_C(           0), -INT32_C(   510945841),  INT32_C(  1572234315),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1039878026) } },
    { UINT8_C( 47),
      { -INT32_C(   635222550), -INT32_C(  1044412136),  INT32_C(   116805216), -INT32_C(   316479491), -INT32_C(   592549066), -INT32_C(  1278967433), -INT32_C(   501559426),  INT32_C(   470908977) },
      { -INT32_C(   571066939),  INT32_C(   513783230),  INT32_C(     2397443), -INT32_C(  1293072772),  INT32_C(   697211826), -INT32_C(  1696771556),  INT32_C(  1400698657),  INT32_C(  1013943927) },
      { -INT32_C(  2129041981),  INT32_C(   513783835), -INT32_C(   920665267), -INT32_C(  1149563895), -INT32_C(   991622744),  INT32_C(  2103427676),  INT32_C(   818994105),  INT32_C(   745291625) },
      { -INT32_C(   635251131), -INT32_C(  1044434561),  INT32_C(   116797474), -INT32_C(   316460666),  INT32_C(           0), -INT32_C(  1278929696),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(165),
      {  INT32_C(  1052814725),  INT32_C(   260824652),  INT32_C(   169432573), -INT32_C(   625814320),  INT32_C(  2067166905), -INT32_C(  1321946155), -INT32_C(  1021680508),  INT32_C(  1449674704) },
      {  INT32_C(  1100228852),  INT32_C(    72359687),  INT32_C(  1158572404), -INT32_C(   148914114),  INT32_C(   208885047), -INT32_C(  1933727992), -INT32_C(   598681588),  INT32_C(   322091039) },
      { -INT32_C(   397097247),  INT32_C(  1525458406),  INT32_C(  1285552910), -INT32_C(   230375749),  INT32_C(   486520595),  INT32_C(  1789443166), -INT32_C(  1287128940), -INT32_C(  1832420943) },
      {  INT32_C(  1052815713),  INT32_C(           0),  INT32_C(   169437558),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1321958551),  INT32_C(           0),  INT32_C(  1449689579) } },
    { UINT8_C( 64),
      { -INT32_C(  1071220197),  INT32_C(  1640988774), -INT32_C(   568517856),  INT32_C(   384962399), -INT32_C(   881521138), -INT32_C(  1352671306), -INT32_C(  1604316378), -INT32_C(   169807142) },
      { -INT32_C(   759822740), -INT32_C(  1506507386),  INT32_C(     8737184),  INT32_C(  1863743328),  INT32_C(   993692549), -INT32_C(  1846896277), -INT32_C(  2043589972), -INT32_C(  1468264132) },
      { -INT32_C(  1636093417),  INT32_C(  1464119223),  INT32_C(  1616365824), -INT32_C(   976261568),  INT32_C(  1677789689),  INT32_C(  1341582243),  INT32_C(  1926637366),  INT32_C(  1343967801) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1604290986),  INT32_C(           0) } },
    { UINT8_C(132),
      {  INT32_C(  1161555606), -INT32_C(    62549453),  INT32_C(  1480435178),  INT32_C(  2119238261), -INT32_C(   283003389), -INT32_C(   752520788), -INT32_C(  1727228089),  INT32_C(  1209884082) },
      {  INT32_C(  2123192395), -INT32_C(   730082582), -INT32_C(   315836296), -INT32_C(  1100251462), -INT32_C(   525497036),  INT32_C(  1169412862),  INT32_C(   484360297),  INT32_C(  1751448349) },
      {  INT32_C(  1038611027),  INT32_C(  1007837892), -INT32_C(   735494630), -INT32_C(   258828868),  INT32_C(   550518562),  INT32_C(  2070250513),  INT32_C(  1637303108), -INT32_C(  1849033922) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1480441082),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1209867581) } },
    { UINT8_C(237),
      {  INT32_C(   313708208),  INT32_C(   523038432), -INT32_C(  1378156264), -INT32_C(   741356397),  INT32_C(   551874460), -INT32_C(  1755029676), -INT32_C(   220871178),  INT32_C(  1071605391) },
      {  INT32_C(   357732660), -INT32_C(  1741390208),  INT32_C(   323293055),  INT32_C(  2028344539),  INT32_C(  1469630979),  INT32_C(   552533290),  INT32_C(  1360184258),  INT32_C(  1569845801) },
      {  INT32_C(    57860995), -INT32_C(   509893023), -INT32_C(  1846222666), -INT32_C(   150349068), -INT32_C(   833707356),  INT32_C(  1643068575),  INT32_C(   682820095),  INT32_C(  2005288179) },
      {  INT32_C(   313706914),  INT32_C(           0), -INT32_C(  1378169079), -INT32_C(   741358795),  INT32_C(           0), -INT32_C(  1755019512), -INT32_C(   220869323),  INT32_C(  1071614691) } },
    { UINT8_C( 39),
      { -INT32_C(  1618445576), -INT32_C(   162174698),  INT32_C(   938206813), -INT32_C(  1831017744),  INT32_C(  1831971377), -INT32_C(  1687317863), -INT32_C(  1987144379),  INT32_C(   347079963) },
      { -INT32_C(  1766639232),  INT32_C(     9177250), -INT32_C(   566790162), -INT32_C(  1955589286),  INT32_C(  1475912126),  INT32_C(  2045928756),  INT32_C(   369328635),  INT32_C(   103461766) },
      { -INT32_C(  1885544980), -INT32_C(   728815131), -INT32_C(    88947040), -INT32_C(  1736104998), -INT32_C(   118522172), -INT32_C(   562896157), -INT32_C(   369789597),  INT32_C(   368058152) },
      { -INT32_C(  1618484981), -INT32_C(   162194564),  INT32_C(   938171441),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1687298927),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(253),
      { -INT32_C(  1243437940), -INT32_C(   111757773), -INT32_C(  1932308375),  INT32_C(  1414556630),  INT32_C(  1027033435),  INT32_C(   815797947),  INT32_C(   710445323),  INT32_C(   103247225) },
      {  INT32_C(  1153108497),  INT32_C(   691933632),  INT32_C(   951390562), -INT32_C(   661911939),  INT32_C(   169198415), -INT32_C(   465914407), -INT32_C(  1206939074),  INT32_C(   297678336) },
      {  INT32_C(    22444352), -INT32_C(   315976565),  INT32_C(   572907685),  INT32_C(   905621990),  INT32_C(  1312755572),  INT32_C(    53639620),  INT32_C(   196821259), -INT32_C(  1206027912) },
      { -INT32_C(  1243419492),  INT32_C(           0), -INT32_C(  1932309236),  INT32_C(  1414563514),  INT32_C(  1027047627),  INT32_C(   815810412),  INT32_C(   710456484),  INT32_C(   103258045) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__mmask8 k = test_vec[i].k;
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi32(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_dpbusds_epi32(k, src, a, b);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i b = simde_test_x86_random_i32x8();
    simde__m256i r = simde_mm256_maskz_dpbusds_epi32(k, src, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_dpbusds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(   331655152), -INT32_C(  1720712607), -INT32_C(  1025094387),  INT32_C(  1846287533),  INT32_C(  1602584914),  INT32_C(  1515255776), -INT32_C(  1350904581),  INT32_C(  1276370780),
        -INT32_C(   396372090), -INT32_C(   427700007), -INT32_C(   878156003), -INT32_C(   700861308),  INT32_C(   372620854), -INT32_C(  1318025803), -INT32_C(  1251939495),  INT32_C(  1342337994) },
      {  INT32_C(   607674699),  INT32_C(  1326168625), -INT32_C(  1524976863), -INT32_C(  1636019352), -INT32_C(   944459502), -INT32_C(  1871174345), -INT32_C(   632891120), -INT32_C(  1758836660),
        -INT32_C(   608410711),  INT32_C(  1042990877), -INT32_C(   488356742), -INT32_C(  1451204457),  INT32_C(  1215378705),  INT32_C(  1792665946),  INT32_C(   256122818),  INT32_C(   279342695) },
      { -INT32_C(   286563631), -INT32_C(  1540549335), -INT32_C(   242871975), -INT32_C(  2103834767), -INT32_C(  1765078212), -INT32_C(  1224694539),  INT32_C(   717636803), -INT32_C(  2076545614),
        -INT32_C(   109959473), -INT32_C(  1784832197),  INT32_C(   562439088),  INT32_C(  1722032170),  INT32_C(   570191660), -INT32_C(   690422765), -INT32_C(   218063040), -INT32_C(   612943348) },
      {  INT32_C(   331659309), -INT32_C(  1720713465), -INT32_C(  1025094054),  INT32_C(  1846267310),  INT32_C(  1602557307),  INT32_C(  1515241255), -INT32_C(  1350885705),  INT32_C(  1276356412),
        -INT32_C(   396356710), -INT32_C(   427728391), -INT32_C(   878183741), -INT32_C(   700846432),  INT32_C(   372629409), -INT32_C(  1318038157), -INT32_C(  1251930281),  INT32_C(  1342364772) } },
    { { -INT32_C(  1663768224),  INT32_C(   959541641), -INT32_C(  1084508267),  INT32_C(    52887511), -INT32_C(  2128338322),  INT32_C(  1599601951), -INT32_C(  1470998628), -INT32_C(   226244207),
         INT32_C(  1015961779),  INT32_C(  1584775113),  INT32_C(  1293865078),  INT32_C(  1028736207), -INT32_C(  2051115674),  INT32_C(   249894258), -INT32_C(    21612692), -INT32_C(  1259324927) },
      {  INT32_C(  1542487698), -INT32_C(  1279630019),  INT32_C(    83941430), -INT32_C(  2109517540),  INT32_C(   956826055), -INT32_C(  2092372713),  INT32_C(   629276196), -INT32_C(   891719368),
         INT32_C(   740739567),  INT32_C(  1709170735), -INT32_C(   731193160), -INT32_C(   128537295), -INT32_C(   969777489),  INT32_C(  1883863627), -INT32_C(  1315583112),  INT32_C(   746286908) },
      {  INT32_C(  1733861688),  INT32_C(   969685121),  INT32_C(  1225602840), -INT32_C(  1824365340),  INT32_C(   240743618),  INT32_C(  1719575534), -INT32_C(  1441328274), -INT32_C(  1143565438),
        -INT32_C(  1239273676),  INT32_C(  2146430823),  INT32_C(   180944166),  INT32_C(   597559905),  INT32_C(  1815213950),  INT32_C(   148090778),  INT32_C(  1169418947), -INT32_C(  1308587651) },
      { -INT32_C(  1663741525),  INT32_C(   959540081), -INT32_C(  1084494726),  INT32_C(    52885079), -INT32_C(  2128349034),  INT32_C(  1599601930), -INT32_C(  1470990057), -INT32_C(   226286632),
         INT32_C(  1015981690),  INT32_C(  1584785182),  INT32_C(  1293867582),  INT32_C(  1028742942), -INT32_C(  2051070636),  INT32_C(   249874337), -INT32_C(    21623738), -INT32_C(  1259334068) } },
    { {  INT32_C(   526918584),  INT32_C(   949901074), -INT32_C(  1253939372), -INT32_C(   254156687),  INT32_C(  1918634712),  INT32_C(  2105225146), -INT32_C(  1748881894),  INT32_C(  1883882423),
        -INT32_C(   124800538),  INT32_C(  1563438601),  INT32_C(   101937813),  INT32_C(   737602643), -INT32_C(  1331866634), -INT32_C(  1674766206), -INT32_C(    30085050), -INT32_C(  1720812109) },
      {  INT32_C(   949091631), -INT32_C(  1063927509), -INT32_C(  2033735629), -INT32_C(  1951285868), -INT32_C(  1824829680), -INT32_C(  1372624537),  INT32_C(   212624217),  INT32_C(   279255777),
         INT32_C(  1128805911),  INT32_C(   704896503),  INT32_C(   447859334), -INT32_C(  1733991800),  INT32_C(   422306225), -INT32_C(  1547216054), -INT32_C(  1615891522), -INT32_C(  1532013427) },
      { -INT32_C(  2115504246),  INT32_C(  1537993685),  INT32_C(  1031101621),  INT32_C(  1893079999),  INT32_C(  1183384060),  INT32_C(   468275292),  INT32_C(  1354406083),  INT32_C(  1995795180),
         INT32_C(   922213473),  INT32_C(  2106696391), -INT32_C(  1095104513),  INT32_C(   506368034), -INT32_C(   295389038), -INT32_C(   871805688), -INT32_C(   786643739), -INT32_C(  1891167954) },
      {  INT32_C(   526900024),  INT32_C(   949899979), -INT32_C(  1253896284), -INT32_C(   254153070),  INT32_C(  1918637996),  INT32_C(  2105246639), -INT32_C(  1748908699),  INT32_C(  1883880752),
        -INT32_C(   124797281),  INT32_C(  1563408665),  INT32_C(   101924987),  INT32_C(   737608441), -INT32_C(  1331898454), -INT32_C(  1674765292), -INT32_C(    30099653), -INT32_C(  1720810302) } },
    { { -INT32_C(  1245298962), -INT32_C(   550348832), -INT32_C(  2137133730),  INT32_C(   262065277), -INT32_C(  1929510268),  INT32_C(   878184271), -INT32_C(   117082677),  INT32_C(  1955155078),
         INT32_C(  1797934986),  INT32_C(    88759462), -INT32_C(   947525559),  INT32_C(   953558196),  INT32_C(  1992610854), -INT32_C(  1482023460),  INT32_C(   413249682), -INT32_C(  2020791556) },
      {  INT32_C(   536000377),  INT32_C(  1562655763), -INT32_C(   668685788), -INT32_C(   200213810), -INT32_C(  1419061809), -INT32_C(  2074995214), -INT32_C(  1046678587), -INT32_C(  1773655779),
        -INT32_C(   189383968), -INT32_C(  1689134473),  INT32_C(  1383363972),  INT32_C(  1044874351),  INT32_C(  1273606489), -INT32_C(  1949352762),  INT32_C(  1296919599),  INT32_C(  1994626453) },
      {  INT32_C(  1198168528), -INT32_C(   119358604), -INT32_C(  1622452688),  INT32_C(   887001819),  INT32_C(   176211779),  INT32_C(   865423107),  INT32_C(  1367401147),  INT32_C(  1221026680),
         INT32_C(  1905209853),  INT32_C(   476672492), -INT32_C(  1547979576), -INT32_C(  1965582010),  INT32_C(  1687443297),  INT32_C(  1654073767), -INT32_C(  2068637940),  INT32_C(  2026666619) },
      { -INT32_C(  1245295766), -INT32_C(   550352592), -INT32_C(  2137135634),  INT32_C(   262042299), -INT32_C(  1929520398),  INT32_C(   878184614), -INT32_C(   117107895),  INT32_C(  1955169313),
         INT32_C(  1797944162),  INT32_C(    88794561), -INT32_C(   947557473),  INT32_C(   953542143),  INT32_C(  1992617222), -INT32_C(  1482046735),  INT32_C(   413237253), -INT32_C(  2020752695) } },
    { { -INT32_C(  1746314325), -INT32_C(  1800187188),  INT32_C(  1295478535),  INT32_C(  1775701768),  INT32_C(   231631718), -INT32_C(  1586469483), -INT32_C(   131783811),  INT32_C(  1232138654),
         INT32_C(   417421644), -INT32_C(  1297247061),  INT32_C(   201384963),  INT32_C(  1517672435), -INT32_C(   664321213),  INT32_C(   645519273), -INT32_C(  1726046469), -INT32_C(   605909361) },
      { -INT32_C(  1829518361),  INT32_C(  1531289688),  INT32_C(  2020033925),  INT32_C(  1607654684), -INT32_C(   919127520),  INT32_C(   217034769), -INT32_C(   576385714), -INT32_C(  2101835621),
        -INT32_C(  1558860725), -INT32_C(   771794356), -INT32_C(  1152751969),  INT32_C(  1679498307),  INT32_C(  1747800662),  INT32_C(  1366564099), -INT32_C(   969991638), -INT32_C(   313989214) },
      { -INT32_C(   527344237),  INT32_C(  1454477495),  INT32_C(   974322678),  INT32_C(  1855859992), -INT32_C(  2099852417),  INT32_C(   332680168),  INT32_C(   131662693),  INT32_C(  2129928682),
         INT32_C(   912164223),  INT32_C(   210571029),  INT32_C(   591830795),  INT32_C(  1267852492), -INT32_C(  1731303249),  INT32_C(   413901491), -INT32_C(  1893759835),  INT32_C(   604836773) },
      { -INT32_C(  1746353014), -INT32_C(  1800209157),  INT32_C(  1295485674),  INT32_C(  1775702255),  INT32_C(   231605072), -INT32_C(  1586466979), -INT32_C(   131780782),  INT32_C(  1232153904),
         INT32_C(   417420789), -INT32_C(  1297270932),  INT32_C(   201388543),  INT32_C(  1517672670), -INT32_C(   664332717),  INT32_C(   645508400), -INT32_C(  1726074432), -INT32_C(   605910246) } },
    { { -INT32_C(  1369740391), -INT32_C(  2034571141),  INT32_C(  1403584647), -INT32_C(  1801569564),  INT32_C(  1428974754), -INT32_C(  1284647154),  INT32_C(     4426843),  INT32_C(   958746784),
         INT32_C(   937918652), -INT32_C(   272784792), -INT32_C(  2025691486),  INT32_C(  1125900448),  INT32_C(  1536706381),  INT32_C(  2031027742),  INT32_C(   846811794),  INT32_C(  1584111266) },
      { -INT32_C(  2037034210), -INT32_C(  1753918731),  INT32_C(  1495185336), -INT32_C(   442746472), -INT32_C(  1639959424), -INT32_C(   854110406),  INT32_C(  1157599649),  INT32_C(  1319267119),
        -INT32_C(  1277937474),  INT32_C(  1128942218), -INT32_C(  1717802751),  INT32_C(   595474594), -INT32_C(  1480474772), -INT32_C(  1334519538), -INT32_C(  1712032918), -INT32_C(  1662544162) },
      {  INT32_C(  1498397902),  INT32_C(   127703558), -INT32_C(  1516161021), -INT32_C(   590864528), -INT32_C(   310146338), -INT32_C(   845285533),  INT32_C(  1231458667), -INT32_C(   152678873),
         INT32_C(   273626378), -INT32_C(   770184241), -INT32_C(  1820805085), -INT32_C(  1234222888),  INT32_C(   765719498),  INT32_C(  1442463978), -INT32_C(   106995247), -INT32_C(  1175485009) },
      { -INT32_C(  1369723838), -INT32_C(  2034588678),  INT32_C(  1403584498), -INT32_C(  1801567753),  INT32_C(  1428953264), -INT32_C(  1284654855),  INT32_C(     4458949),  INT32_C(   958751971),
         INT32_C(   937943132), -INT32_C(   272794488), -INT32_C(  2025696968),  INT32_C(  1125908948),  INT32_C(  1536687632),  INT32_C(  2031055586),  INT32_C(   846793228),  INT32_C(  1584059831) } },
    { { -INT32_C(  1966522694),  INT32_C(  1281155113),  INT32_C(  1910494361), -INT32_C(   551072235),  INT32_C(   739101505), -INT32_C(   578746613),  INT32_C(   399908968),  INT32_C(  1624294821),
         INT32_C(   753572099),  INT32_C(   326649466),  INT32_C(   813979419), -INT32_C(   418403419), -INT32_C(  2112676746), -INT32_C(  1939893212),  INT32_C(  1520711093), -INT32_C(    38112006) },
      { -INT32_C(  2010536946),  INT32_C(   110862827), -INT32_C(  1657397256),  INT32_C(  1099187658), -INT32_C(  2034002078), -INT32_C(   518905300),  INT32_C(  1362867799),  INT32_C(   961476139),
        -INT32_C(  2050918502),  INT32_C(   277568536),  INT32_C(  1169015163),  INT32_C(  1770402311), -INT32_C(   168867383), -INT32_C(  1026162325), -INT32_C(   485289288), -INT32_C(  1575198456) },
      { -INT32_C(   265757224), -INT32_C(  1275022535),  INT32_C(  2096737909), -INT32_C(  1444577056),  INT32_C(   899667145), -INT32_C(  1913162283), -INT32_C(  1888482425),  INT32_C(  1160940652),
        -INT32_C(  1573561751), -INT32_C(  2108279283), -INT32_C(   989966108), -INT32_C(  1720851504), -INT32_C(  1915876169),  INT32_C(   152749698),  INT32_C(  1033472977), -INT32_C(  2122134761) },
      { -INT32_C(  1966529530),  INT32_C(  1281155655),  INT32_C(  1910539925), -INT32_C(   551096750),  INT32_C(   739077658), -INT32_C(   578770564),  INT32_C(   399897898),  INT32_C(  1624278762),
         INT32_C(   753596706),  INT32_C(   326664684),  INT32_C(   813986929), -INT32_C(   418401414), -INT32_C(  2112730668), -INT32_C(  1939899442),  INT32_C(  1520712229), -INT32_C(    38141065) } },
    { {  INT32_C(   841201701), -INT32_C(   759858450), -INT32_C(  1701399606),  INT32_C(  1311966103), -INT32_C(  1831140848), -INT32_C(  1717831992), -INT32_C(  1730792319),  INT32_C(   605641215),
        -INT32_C(    11059951), -INT32_C(  2117006153),  INT32_C(  1444636607),  INT32_C(  2057653866),  INT32_C(   403472464), -INT32_C(   139351946), -INT32_C(   594507556), -INT32_C(   234837535) },
      { -INT32_C(  1645127706),  INT32_C(   589218403), -INT32_C(  1820772055), -INT32_C(   670163320),  INT32_C(   368122527), -INT32_C(  1626496318),  INT32_C(   192650538),  INT32_C(   771586886),
         INT32_C(   919269075), -INT32_C(   648418896), -INT32_C(  1435643102), -INT32_C(  1870431247),  INT32_C(  1487303829),  INT32_C(  1106752278), -INT32_C(  1773374896), -INT32_C(  1060943123) },
      { -INT32_C(   369652168), -INT32_C(  1715318665),  INT32_C(   356790051),  INT32_C(  1084606378),  INT32_C(  1368935227),  INT32_C(  1318227966), -INT32_C(   286925055),  INT32_C(  1638901801),
        -INT32_C(  1387616714),  INT32_C(   440864246), -INT32_C(   416314564), -INT32_C(  1926769582),  INT32_C(   517914400),  INT32_C(  1332572494),  INT32_C(  2034061904),  INT32_C(   836431098) },
      {  INT32_C(   841198883), -INT32_C(   759836614), -INT32_C(  1701384177),  INT32_C(  1311965247), -INT32_C(  1831152880), -INT32_C(  1717839714), -INT32_C(  1730800977),  INT32_C(   605617133),
        -INT32_C(    11059511), -INT32_C(  2116992923),  INT32_C(  1444614833),  INT32_C(  2057656765),  INT32_C(   403466688), -INT32_C(   139297945), -INT32_C(   594469022), -INT32_C(   234838439) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_dpbusds_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_dpbusds_epi32(src, a, b);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_dpbusds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1981930094),  INT32_C(  1856185650),  INT32_C(    39178928), -INT32_C(   963674970), -INT32_C(  1981452741),  INT32_C(   802706143), -INT32_C(  1633151324), -INT32_C(  1781562878),
        -INT32_C(   652300633), -INT32_C(  2075606573),  INT32_C(   965123475),  INT32_C(  1426069018),  INT32_C(  1675617668), -INT32_C(   611141833), -INT32_C(   797361459),  INT32_C(  1684359612) },
      UINT16_C(33783),
      { -INT32_C(  2059089347), -INT32_C(   719071410),  INT32_C(   283852048),  INT32_C(  1911910290),  INT32_C(  1680420050), -INT32_C(  2120288761),  INT32_C(   734681798), -INT32_C(    55656002),
        -INT32_C(   629017973), -INT32_C(   626023223),  INT32_C(  1961532129), -INT32_C(   605691895),  INT32_C(   339676684), -INT32_C(   879371003), -INT32_C(   151560393), -INT32_C(  1410161376) },
      {  INT32_C(  1636135832), -INT32_C(   113560552), -INT32_C(   680712498),  INT32_C(   313676550),  INT32_C(  1713828193),  INT32_C(   103988174),  INT32_C(   989604122),  INT32_C(  1726410446),
         INT32_C(  2043177825),  INT32_C(  1853031328),  INT32_C(   793174057), -INT32_C(  1790773197), -INT32_C(  1191483158),  INT32_C(  1052650788),  INT32_C(   628734550),  INT32_C(   176906152) },
      { -INT32_C(  1981908671),  INT32_C(  1856199276),  INT32_C(    39205405), -INT32_C(   963674970), -INT32_C(  1981421273),  INT32_C(   802697493), -INT32_C(  1633140800), -INT32_C(  1781554672),
        -INT32_C(   652242102), -INT32_C(  2075581272),  INT32_C(   965123475),  INT32_C(  1426069018),  INT32_C(  1675617668), -INT32_C(   611141833), -INT32_C(   797361459),  INT32_C(  1684345867) } },
    { {  INT32_C(  1786991562), -INT32_C(  2133199273),  INT32_C(   179314647),  INT32_C(    27259415),  INT32_C(  2126158682),  INT32_C(   532510920), -INT32_C(   616286669),  INT32_C(  1608896405),
         INT32_C(  2060085539),  INT32_C(   922395487), -INT32_C(   650007870), -INT32_C(   136585060),  INT32_C(  1148556667),  INT32_C(  1080242701), -INT32_C(    48453784), -INT32_C(  1721958026) },
      UINT16_C(10090),
      {  INT32_C(   248171027),  INT32_C(  1102613504),  INT32_C(  1075991909), -INT32_C(  1042965172),  INT32_C(  1156899809),  INT32_C(  1072389155), -INT32_C(  1220451750),  INT32_C(   266251259),
         INT32_C(  1981655157), -INT32_C(  1716005580),  INT32_C(  1994053930),  INT32_C(  1480109943), -INT32_C(  1231213422), -INT32_C(   487225208), -INT32_C(   426166550),  INT32_C(  1475704802) },
      {  INT32_C(  1405948447),  INT32_C(   317556199), -INT32_C(   712456354),  INT32_C(   154058870),  INT32_C(  1975503852),  INT32_C(  1045935187), -INT32_C(   853216789), -INT32_C(  2010900120),
         INT32_C(   316404267), -INT32_C(   719009673),  INT32_C(   111914383),  INT32_C(  1510988141), -INT32_C(   137376092),  INT32_C(  1832199810), -INT32_C(  2143659753), -INT32_C(  1660395662) },
      {  INT32_C(  1786991562), -INT32_C(  2133218819),  INT32_C(   179314647),  INT32_C(    27269870),  INT32_C(  2126158682),  INT32_C(   532531184), -INT32_C(   616297022),  INT32_C(  1608896405),
         INT32_C(  2060089269),  INT32_C(   922389756), -INT32_C(   650048449), -INT32_C(   136585060),  INT32_C(  1148556667),  INT32_C(  1080268352), -INT32_C(    48453784), -INT32_C(  1721958026) } },
    { { -INT32_C(   927931567),  INT32_C(  1000199340), -INT32_C(   280934271), -INT32_C(   985051103), -INT32_C(  1581443042),  INT32_C(  1443820094), -INT32_C(  1093252788), -INT32_C(   111354200),
         INT32_C(  1841368257),  INT32_C(  1655267040), -INT32_C(   934155609),  INT32_C(  1502517819), -INT32_C(   252032078), -INT32_C(  1991898819), -INT32_C(    95937454), -INT32_C(  1124883206) },
      UINT16_C(46256),
      { -INT32_C(   770535383),  INT32_C(  1136507378),  INT32_C(   282982530),  INT32_C(  1281068881), -INT32_C(   967468928),  INT32_C(  1793304354), -INT32_C(  1810965087), -INT32_C(  1018642791),
         INT32_C(  1100307022), -INT32_C(  1769713132), -INT32_C(  1666817462),  INT32_C(  1911030257), -INT32_C(  1153942119), -INT32_C(  2061165596), -INT32_C(  1843842056),  INT32_C(  1079337457) },
      { -INT32_C(   813569349), -INT32_C(  2023422659),  INT32_C(  1495468903), -INT32_C(  1496708340),  INT32_C(   744555080),  INT32_C(   380733213), -INT32_C(  1398224198), -INT32_C(   403899093),
         INT32_C(   615935463), -INT32_C(   626254734),  INT32_C(   875810599),  INT32_C(   601554395),  INT32_C(   491797248),  INT32_C(  2100494786), -INT32_C(   148251700), -INT32_C(  1059187240) },
      { -INT32_C(   927931567),  INT32_C(  1000199340), -INT32_C(   280934271), -INT32_C(   985051103), -INT32_C(  1581416565),  INT32_C(  1443785272), -INT32_C(  1093252788), -INT32_C(   111354506),
         INT32_C(  1841368257),  INT32_C(  1655267040), -INT32_C(   934140947),  INT32_C(  1502517819), -INT32_C(   252018576), -INT32_C(  1991894416), -INT32_C(    95937454), -INT32_C(  1124897795) } },
    { { -INT32_C(   186346110), -INT32_C(   657551183),  INT32_C(   990642528), -INT32_C(    10557697), -INT32_C(   467882462),  INT32_C(  2086752432),  INT32_C(    74680875),  INT32_C(   566514335),
        -INT32_C(  1743345433), -INT32_C(  1720654791), -INT32_C(   439058970), -INT32_C(  2048642461), -INT32_C(  1855323935),  INT32_C(  2081278800), -INT32_C(   176127914), -INT32_C(  1189657390) },
      UINT16_C(11756),
      { -INT32_C(  1039063727), -INT32_C(  1841301570), -INT32_C(  1060789540), -INT32_C(  1832802776),  INT32_C(  1146949943),  INT32_C(   230994829), -INT32_C(  1068394583), -INT32_C(  1561510320),
         INT32_C(   577044067), -INT32_C(   759913482),  INT32_C(  1838381381),  INT32_C(  1459573791), -INT32_C(   207987355), -INT32_C(  1191158000),  INT32_C(  1182356214), -INT32_C(   202873200) },
      {  INT32_C(  1528122469),  INT32_C(   892193519),  INT32_C(  1671610435),  INT32_C(  2058986004),  INT32_C(   258823423), -INT32_C(  1446416973),  INT32_C(  1341080255),  INT32_C(   239327401),
         INT32_C(   342448164),  INT32_C(  1716098594),  INT32_C(  1808395095), -INT32_C(  1931115891), -INT32_C(  1986243882),  INT32_C(  2134009280),  INT32_C(  1355752103),  INT32_C(   509481722) },
      { -INT32_C(   186346110), -INT32_C(   657551183),  INT32_C(   990647390), -INT32_C(    10568392), -INT32_C(   467882462),  INT32_C(  2086749175),  INT32_C(    74693647),  INT32_C(   566523042),
        -INT32_C(  1743308337), -INT32_C(  1720654791), -INT32_C(   439051930), -INT32_C(  2048673471), -INT32_C(  1855323935),  INT32_C(  2081310866), -INT32_C(   176127914), -INT32_C(  1189657390) } },
    { { -INT32_C(  1926051990), -INT32_C(  1242334370), -INT32_C(   199181209),  INT32_C(   360777278),  INT32_C(   413015384),  INT32_C(   697880962), -INT32_C(   310745101), -INT32_C(   485762951),
        -INT32_C(    26198368),  INT32_C(   548627385),  INT32_C(  1578488607),  INT32_C(   846436057),  INT32_C(   894046643), -INT32_C(   715201822), -INT32_C(  1027418039),  INT32_C(  1369886385) },
      UINT16_C( 5644),
      {  INT32_C(    41600335), -INT32_C(    69887514),  INT32_C(  1787932663),  INT32_C(   729564385), -INT32_C(   686924167), -INT32_C(   156215500), -INT32_C(  1060871910),  INT32_C(    30855346),
         INT32_C(  2080592022), -INT32_C(   512239382),  INT32_C(  1749813383), -INT32_C(   980105140),  INT32_C(  1520214566),  INT32_C(   324095225),  INT32_C(  1607669165),  INT32_C(  2086709990) },
      { -INT32_C(   453483526), -INT32_C(  1010405572), -INT32_C(  1020521865),  INT32_C(     8962266),  INT32_C(  1532699746),  INT32_C(   510635121), -INT32_C(  1484897599), -INT32_C(   417079572),
         INT32_C(  2127240002),  INT32_C(    21074314),  INT32_C(  2110025123), -INT32_C(  1887548371), -INT32_C(   487859855),  INT32_C(  1174428293), -INT32_C(  1980858724), -INT32_C(  1620045475) },
      { -INT32_C(  1926051990), -INT32_C(  1242334370), -INT32_C(   199148752),  INT32_C(   360749496),  INT32_C(   413015384),  INT32_C(   697880962), -INT32_C(   310745101), -INT32_C(   485762951),
        -INT32_C(    26198368),  INT32_C(   548583757),  INT32_C(  1578485364),  INT32_C(   846436057),  INT32_C(   894038643), -INT32_C(   715201822), -INT32_C(  1027418039),  INT32_C(  1369886385) } },
    { { -INT32_C(  1222821075),  INT32_C(  1891196621), -INT32_C(   101810740),  INT32_C(   998862026), -INT32_C(   904039355),  INT32_C(  1779441102), -INT32_C(   101450084),  INT32_C(  1033397008),
         INT32_C(  1827976607), -INT32_C(   539185901), -INT32_C(   170276309),  INT32_C(  2066768438), -INT32_C(  1538961962),  INT32_C(   101602922),  INT32_C(  1694433876),  INT32_C(    77698917) },
      UINT16_C(38476),
      {  INT32_C(  1296261232),  INT32_C(   404188735), -INT32_C(  1820701085),  INT32_C(   266358985),  INT32_C(    56970228),  INT32_C(  1359329617), -INT32_C(  1075287522), -INT32_C(   548063889),
        -INT32_C(   735274603),  INT32_C(  1810711559),  INT32_C(  1543399314), -INT32_C(  1402282056),  INT32_C(  2075119402), -INT32_C(  1479756663), -INT32_C(  1905871585),  INT32_C(  2137898218) },
      {  INT32_C(  1548982869),  INT32_C(  1892106462),  INT32_C(  1623967400), -INT32_C(   821283163), -INT32_C(  1907704827), -INT32_C(  1892346000), -INT32_C(  1239573300), -INT32_C(  1388999848),
         INT32_C(    50956325),  INT32_C(  1903415753),  INT32_C(  1020346007),  INT32_C(  2047597940),  INT32_C(   168318361),  INT32_C(   949567084),  INT32_C(   854505434),  INT32_C(  1742676802) },
      { -INT32_C(  1222821075),  INT32_C(  1891196621), -INT32_C(   101816330),  INT32_C(   998850008), -INT32_C(   904039355),  INT32_C(  1779441102), -INT32_C(   101469650),  INT32_C(  1033397008),
         INT32_C(  1827976607), -INT32_C(   539150136), -INT32_C(   170291731),  INT32_C(  2066768438), -INT32_C(  1538946063),  INT32_C(   101602922),  INT32_C(  1694433876),  INT32_C(    77730425) } },
    { {  INT32_C(  1969940652),  INT32_C(  1357307321), -INT32_C(  1869826277),  INT32_C(   772446100),  INT32_C(  1496847085),  INT32_C(   714264912), -INT32_C(   899907448),  INT32_C(  1345403812),
        -INT32_C(   574252252), -INT32_C(  1808880776), -INT32_C(   165365150),  INT32_C(  1059335762), -INT32_C(  1852285888), -INT32_C(  1229247954),  INT32_C(  1333860523),  INT32_C(  2006954579) },
      UINT16_C(25678),
      { -INT32_C(  2096118187),  INT32_C(  2117955930), -INT32_C(  1934848153),  INT32_C(  1743318478),  INT32_C(   965809790),  INT32_C(  1313946829),  INT32_C(   704685451),  INT32_C(  1905151516),
         INT32_C(  1878301973),  INT32_C(  1995321870), -INT32_C(  1878877503),  INT32_C(   100133511), -INT32_C(   834697215),  INT32_C(  1344049349),  INT32_C(  1383799861), -INT32_C(  2134701717) },
      { -INT32_C(  1242580825), -INT32_C(  1423188502), -INT32_C(    12898952),  INT32_C(   419770904), -INT32_C(  2132327237),  INT32_C(   181404628), -INT32_C(  1973662945), -INT32_C(    66445483),
        -INT32_C(  1045300521),  INT32_C(  1332600279),  INT32_C(   575645706), -INT32_C(  1774496549),  INT32_C(  1813389976),  INT32_C(  1165420069), -INT32_C(  2016423374), -INT32_C(   914105614) },
      {  INT32_C(  1969940652),  INT32_C(  1357293299), -INT32_C(  1869797474),  INT32_C(   772466629),  INT32_C(  1496847085),  INT32_C(   714264912), -INT32_C(   899895720),  INT32_C(  1345403812),
        -INT32_C(   574252252), -INT32_C(  1808880776), -INT32_C(   165371718),  INT32_C(  1059335762), -INT32_C(  1852285888), -INT32_C(  1229235585),  INT32_C(  1333845936),  INT32_C(  2006954579) } },
    { { -INT32_C(  1416940332),  INT32_C(   486275089),  INT32_C(  2067679904),  INT32_C(   907115166), -INT32_C(  1029560420),  INT32_C(  1074206990), -INT32_C(   574105877), -INT32_C(  2069411152),
        -INT32_C(  1875889538), -INT32_C(   894686422),  INT32_C(   323414645),  INT32_C(    21583716), -INT32_C(  1916540033), -INT32_C(   254948860),  INT32_C(  1372427424),  INT32_C(  1557492958) },
      UINT16_C( 1446),
      { -INT32_C(  1741631252), -INT32_C(   511466085),  INT32_C(    20506552), -INT32_C(  1410484248),  INT32_C(   292942148), -INT32_C(  1348135199),  INT32_C(  1008960359), -INT32_C(   868037920),
         INT32_C(   895840922), -INT32_C(   803805160), -INT32_C(  1194176561),  INT32_C(  1264828166), -INT32_C(  1839408720),  INT32_C(  1447101167),  INT32_C(  1704092805), -INT32_C(   919415762) },
      {  INT32_C(  1610520391),  INT32_C(  1311708543),  INT32_C(  1778778468),  INT32_C(  1907714752),  INT32_C(   839062083), -INT32_C(  1719122924), -INT32_C(   671147352),  INT32_C(   916468207),
         INT32_C(  1200987848),  INT32_C(   395691187), -INT32_C(  2038260538),  INT32_C(  1240938246),  INT32_C(  1568406089), -INT32_C(   403242178),  INT32_C(   213841437), -INT32_C(   280863193) },
      { -INT32_C(  1416940332),  INT32_C(   486321946),  INT32_C(  2067698977),  INT32_C(   907115166), -INT32_C(  1029560420),  INT32_C(  1074175161), -INT32_C(   574105877), -INT32_C(  2069400382),
        -INT32_C(  1875916378), -INT32_C(   894686422),  INT32_C(   323345831),  INT32_C(    21583716), -INT32_C(  1916540033), -INT32_C(   254948860),  INT32_C(  1372427424),  INT32_C(  1557492958) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_dpbusds_epi32(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_mask_dpbusds_epi32(src, k, a, b);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_dpbusds_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t src[16];
    const int32_t a[16];
    const int32_t b[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(55292),
      { -INT32_C(   878923722),  INT32_C(  1231512263), -INT32_C(   528388632),  INT32_C(   836422326),  INT32_C(   523508008), -INT32_C(  1105899008), -INT32_C(  1591985058),  INT32_C(  1635260459),
        -INT32_C(  1876159288),  INT32_C(  1608094838), -INT32_C(  1203807743),  INT32_C(  1307121957),  INT32_C(   845946418), -INT32_C(   823099024), -INT32_C(   395375427), -INT32_C(   313923547) },
      {  INT32_C(  1937602044),  INT32_C(   198334217), -INT32_C(   691859023),  INT32_C(  1562618922),  INT32_C(   982486986), -INT32_C(   855015408), -INT32_C(  1313507188),  INT32_C(  1570766432),
         INT32_C(  2110790772),  INT32_C(   629711475), -INT32_C(   570733645), -INT32_C(  1036378120), -INT32_C(  1073886546), -INT32_C(   695466422), -INT32_C(   544718210), -INT32_C(  1271126208) },
      { -INT32_C(  1221456829),  INT32_C(  1641855662), -INT32_C(    29436154), -INT32_C(  1514112522), -INT32_C(  1922777789),  INT32_C(  1113845955),  INT32_C(  1931602738),  INT32_C(  1445420306),
         INT32_C(   386750825),  INT32_C(   444131604), -INT32_C(  1223117120),  INT32_C(  1918687279),  INT32_C(  1509933206), -INT32_C(   476355664),  INT32_C(  1633074254), -INT32_C(  2101904103) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   528376605),  INT32_C(   836432015),  INT32_C(   523519591), -INT32_C(  1105887611), -INT32_C(  1591954250),  INT32_C(  1635300008),
        -INT32_C(  1876139037),  INT32_C(  1608110694), -INT32_C(  1203834858),  INT32_C(           0),  INT32_C(   845931792),  INT32_C(           0), -INT32_C(   395336760), -INT32_C(   313944132) } },
    { UINT16_C(50391),
      {  INT32_C(   296610713),  INT32_C(   499674373), -INT32_C(  2131364060),  INT32_C(  1765837674), -INT32_C(  2134052379),  INT32_C(   708647892),  INT32_C(   866604668),  INT32_C(  1928822489),
         INT32_C(  1854186601),  INT32_C(   915098641), -INT32_C(  1380548285), -INT32_C(   250087668), -INT32_C(  1133321240),  INT32_C(  2061938686), -INT32_C(   559051515),  INT32_C(  1968284684) },
      {  INT32_C(  1524946248),  INT32_C(  1687187233), -INT32_C(    49133840),  INT32_C(   636365117),  INT32_C(   199319564),  INT32_C(   361088783),  INT32_C(  1643328341),  INT32_C(   550913239),
         INT32_C(   981121561),  INT32_C(   446630442), -INT32_C(  1911049904), -INT32_C(   424474918),  INT32_C(  1995543910), -INT32_C(  1316260004), -INT32_C(  2129494358), -INT32_C(   593368637) },
      { -INT32_C(   854123613),  INT32_C(  1994962469),  INT32_C(  1090846567),  INT32_C(  1814542085), -INT32_C(  1444800180),  INT32_C(   979004816), -INT32_C(  1363448341), -INT32_C(   108307114),
        -INT32_C(  1631083912), -INT32_C(  1089163432), -INT32_C(  1275062098),  INT32_C(   471869391), -INT32_C(   792395200),  INT32_C(  1510612847), -INT32_C(   502675828), -INT32_C(  1680042973) },
      {  INT32_C(   296610422),  INT32_C(   499675724), -INT32_C(  2131322893),  INT32_C(           0), -INT32_C(  2134056774),  INT32_C(           0),  INT32_C(   866583721),  INT32_C(  1928822041),
         INT32_C(           0),  INT32_C(           0), -INT32_C(  1380561389),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   559082251),  INT32_C(  1968238329) } },
    { UINT16_C(41782),
      {  INT32_C(  1297255993),  INT32_C(  1298464845), -INT32_C(   730581580),  INT32_C(   383169873), -INT32_C(  1875556987), -INT32_C(  1453931872), -INT32_C(  2143454812),  INT32_C(  1310946068),
         INT32_C(  1318810881),  INT32_C(   714801526), -INT32_C(  2013327562),  INT32_C(  1251857860), -INT32_C(  1143287269),  INT32_C(   962867348), -INT32_C(  1111907927),  INT32_C(   353099028) },
      { -INT32_C(   932993198), -INT32_C(   554434904), -INT32_C(   765070835), -INT32_C(   501480761),  INT32_C(  1771960020), -INT32_C(   811466458), -INT32_C(  1232315486), -INT32_C(  1949591496),
        -INT32_C(   413979073),  INT32_C(   986007084),  INT32_C(      797240),  INT32_C(    14821420),  INT32_C(  1147764766),  INT32_C(   605227905), -INT32_C(  1613062297),  INT32_C(  1982506551) },
      {  INT32_C(    22904532), -INT32_C(    46456124),  INT32_C(  2029864780), -INT32_C(  1921392785), -INT32_C(   506338721),  INT32_C(  1426449646), -INT32_C(  1141579901),  INT32_C(  1513168773),
         INT32_C(  1633390493), -INT32_C(    27355471),  INT32_C(  1282825181), -INT32_C(  1696993477), -INT32_C(  1065637166),  INT32_C(   286621838), -INT32_C(   439613088), -INT32_C(   985661912) },
      {  INT32_C(           0),  INT32_C(  1298477072), -INT32_C(   730538513),  INT32_C(           0), -INT32_C(  1875554861), -INT32_C(  1453914179),  INT32_C(           0),  INT32_C(           0),
         INT32_C(  1318829406),  INT32_C(   714809032),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   962852245),  INT32_C(           0),  INT32_C(   353096580) } },
    { UINT16_C(39565),
      { -INT32_C(  2060435929), -INT32_C(  1277096644),  INT32_C(   849484889),  INT32_C(   853308598),  INT32_C(  1236429364),  INT32_C(  1213403772),  INT32_C(   927366136),  INT32_C(  1758647105),
         INT32_C(  1324155410),  INT32_C(  1761725968), -INT32_C(  1583569686),  INT32_C(  1305704472),  INT32_C(  1603700195), -INT32_C(  1868043880), -INT32_C(  1496846747), -INT32_C(   754017855) },
      { -INT32_C(  1406993508), -INT32_C(  1273682998), -INT32_C(   531254841),  INT32_C(   221063210),  INT32_C(  1181533102),  INT32_C(   316019629), -INT32_C(  1011311359), -INT32_C(   745093577),
        -INT32_C(  1954563903), -INT32_C(  1556048676),  INT32_C(  1887671622),  INT32_C(  1820176574),  INT32_C(   565373300), -INT32_C(    30177028),  INT32_C(  1556212517),  INT32_C(  1915705265) },
      { -INT32_C(   318853616), -INT32_C(  1987101117), -INT32_C(  1845947437),  INT32_C(   939357891),  INT32_C(  1532538719),  INT32_C(  1566149431),  INT32_C(   666442358), -INT32_C(  2103776910),
        -INT32_C(   630286185), -INT32_C(  1453064746), -INT32_C(   734307312),  INT32_C(   822819026),  INT32_C(   529360104),  INT32_C(  1719461615),  INT32_C(  1938634241), -INT32_C(  1225447649) },
      { -INT32_C(  2060457523),  INT32_C(           0),  INT32_C(   849453838),  INT32_C(   853311336),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1758606935),
         INT32_C(           0),  INT32_C(  1761708439),  INT32_C(           0),  INT32_C(  1305712255),  INT32_C(  1603701264),  INT32_C(           0),  INT32_C(           0), -INT32_C(   754017928) } },
    { UINT16_C(25535),
      { -INT32_C(   194996847),  INT32_C(  2052157759),  INT32_C(  1353851717), -INT32_C(   491480491),  INT32_C(   919119034), -INT32_C(  1754478326),  INT32_C(   834636604), -INT32_C(   745243070),
         INT32_C(  1405613332), -INT32_C(  1412622234), -INT32_C(  1845788868), -INT32_C(   730615782),  INT32_C(  1577728852),  INT32_C(  1106605829),  INT32_C(  1148433410),  INT32_C(  1192691507) },
      {  INT32_C(  1654317052),  INT32_C(   856516599),  INT32_C(    12847590),  INT32_C(   232011705),  INT32_C(  2020335475),  INT32_C(  1488543830),  INT32_C(  1218259989),  INT32_C(   814724148),
        -INT32_C(  1953289837),  INT32_C(  1992204432),  INT32_C(  1651999657),  INT32_C(   762268602), -INT32_C(  2136614358),  INT32_C(  1356422971), -INT32_C(  1080527221), -INT32_C(  1091557590) },
      { -INT32_C(   532053168), -INT32_C(   850000093),  INT32_C(  1160760714),  INT32_C(  1131585305), -INT32_C(  1262217095),  INT32_C(    33856887),  INT32_C(  1036164115),  INT32_C(   335262403),
         INT32_C(  1492337717), -INT32_C(   702199220),  INT32_C(   807097623),  INT32_C(  1836355316),  INT32_C(   488781990), -INT32_C(   400611627), -INT32_C(  2044337725), -INT32_C(   929422957) },
      { -INT32_C(   194996456),  INT32_C(  2052165642),  INT32_C(  1353833330), -INT32_C(   491456162),  INT32_C(   919122761), -INT32_C(  1754476680),  INT32_C(           0), -INT32_C(   745260085),
         INT32_C(  1405634232), -INT32_C(  1412597376),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1106611709),  INT32_C(  1148403595),  INT32_C(           0) } },
    { UINT16_C(36197),
      {  INT32_C(  1188540705), -INT32_C(  1550061688), -INT32_C(  1825468641),  INT32_C(   533452797),  INT32_C(   340107508), -INT32_C(  1359673208),  INT32_C(   701467023),  INT32_C(  1924543569),
         INT32_C(  1857654502), -INT32_C(  1676585859), -INT32_C(   516930588),  INT32_C(   251722522),  INT32_C(   606291356), -INT32_C(   573433778), -INT32_C(   217669215), -INT32_C(  1134183210) },
      { -INT32_C(   953541046),  INT32_C(  1466186611), -INT32_C(  1724345218),  INT32_C(   732444815), -INT32_C(   883897475), -INT32_C(  2052578589), -INT32_C(  1703366972), -INT32_C(  1252598421),
         INT32_C(  1870495996),  INT32_C(   986112443),  INT32_C(    81002101), -INT32_C(  1288668362),  INT32_C(   696221766),  INT32_C(  1722689442),  INT32_C(  1090528982),  INT32_C(    16143876) },
      { -INT32_C(  1838189610), -INT32_C(   909363884),  INT32_C(  1775148851),  INT32_C(  1612512794),  INT32_C(   545889150), -INT32_C(  1719191357),  INT32_C(  1658488670), -INT32_C(  1268592418),
        -INT32_C(  1740189372),  INT32_C(   962728454), -INT32_C(   878563151), -INT32_C(  1406419154),  INT32_C(   499955034),  INT32_C(  1270240237), -INT32_C(  1179741989), -INT32_C(  1519579039) },
      {  INT32_C(  1188523819),  INT32_C(           0), -INT32_C(  1825463306),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1359719178),  INT32_C(   701474925),  INT32_C(           0),
         INT32_C(  1857662828),  INT32_C(           0), -INT32_C(   516947685),  INT32_C(   251704039),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1134154632) } },
    { UINT16_C(46306),
      { -INT32_C(  1614354371), -INT32_C(   993036254),  INT32_C(  1870921027),  INT32_C(  1982127785), -INT32_C(  1295445509),  INT32_C(   172139612), -INT32_C(   887381155), -INT32_C(  2038432440),
         INT32_C(   119883237),  INT32_C(    30209469), -INT32_C(  1670361102),  INT32_C(   689083437),  INT32_C(    31185829), -INT32_C(   586408576),  INT32_C(   162015169),  INT32_C(   160376612) },
      {  INT32_C(   705803629), -INT32_C(  1674846806),  INT32_C(  1513659180), -INT32_C(   729593297), -INT32_C(  1495900634),  INT32_C(  1015276155),  INT32_C(   759573513), -INT32_C(  1070148269),
         INT32_C(   887834506),  INT32_C(  1372657188), -INT32_C(   508884558),  INT32_C(  2058759764),  INT32_C(   119573644),  INT32_C(  2000986990),  INT32_C(   597985999), -INT32_C(   354166177) },
      {  INT32_C(  1176423970), -INT32_C(  1751650331),  INT32_C(  1299727097), -INT32_C(    54055312),  INT32_C(   671410106),  INT32_C(  1520388234),  INT32_C(   830292946),  INT32_C(  1075535902),
         INT32_C(   344341039),  INT32_C(   581639721), -INT32_C(   781245600),  INT32_C(   214775378), -INT32_C(  1472868067), -INT32_C(   352136167),  INT32_C(   907902744),  INT32_C(   242628831) },
      {  INT32_C(           0), -INT32_C(   993065496),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   172134063), -INT32_C(   887367666), -INT32_C(  2038395756),
         INT32_C(           0),  INT32_C(           0), -INT32_C(  1670335293),  INT32_C(           0),  INT32_C(    31184389), -INT32_C(   586415361),  INT32_C(           0),  INT32_C(   160415747) } },
    { UINT16_C(64626),
      { -INT32_C(   853894110),  INT32_C(   787577790),  INT32_C(   426001228), -INT32_C(  2064940465),  INT32_C(   744031274),  INT32_C(   229339632),  INT32_C(   491096743), -INT32_C(  1155942247),
         INT32_C(   310981716), -INT32_C(    79660369),  INT32_C(   202679741),  INT32_C(  1368522535), -INT32_C(   193074684),  INT32_C(    33630299),  INT32_C(  1260340914),  INT32_C(  1376205054) },
      {  INT32_C(   459640940), -INT32_C(   954817270),  INT32_C(  1909664586),  INT32_C(   784491562), -INT32_C(  1457373362),  INT32_C(   447423335),  INT32_C(  1751501418),  INT32_C(  1874553859),
         INT32_C(   109781244),  INT32_C(   281911749), -INT32_C(   142499380),  INT32_C(  1411728389), -INT32_C(   335722365), -INT32_C(   721049237),  INT32_C(  1983801971), -INT32_C(   739837481) },
      { -INT32_C(   556109543), -INT32_C(   538007790),  INT32_C(  1322676296),  INT32_C(   933428148), -INT32_C(  1356685501), -INT32_C(  1132189880),  INT32_C(  1764934290), -INT32_C(   734259013),
        -INT32_C(  1665984887),  INT32_C(   108765630), -INT32_C(   984329967), -INT32_C(  1862404532), -INT32_C(   566288490), -INT32_C(   644168889),  INT32_C(  1094897030),  INT32_C(  1863745253) },
      {  INT32_C(           0),  INT32_C(   787556322),  INT32_C(           0),  INT32_C(           0),  INT32_C(   744017856),  INT32_C(   229325441),  INT32_C(   491088529),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(   202692513),  INT32_C(  1368512716), -INT32_C(   193078389),  INT32_C(    33618770),  INT32_C(  1260333240),  INT32_C(  1376259104) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi32(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_dpbusds_epi32(test_vec[i].k, src, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i b = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_maskz_dpbusds_epi32(k, src, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dpbusds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_dpbusds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_dpbusds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_dpbusds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_dpbusds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_dpbusds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_dpbusds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_dpbusds_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_dpbusds_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
